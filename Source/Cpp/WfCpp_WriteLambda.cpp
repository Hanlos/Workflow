#include "WfCpp.h"

namespace vl
{
	namespace workflow
	{
		namespace cppcodegen
		{
			using namespace collections;
			using namespace parsing;
			using namespace analyzer;
			using namespace reflection;
			using namespace reflection::description;

/***********************************************************************
WfCppConfig::CollectClosureInfo
***********************************************************************/

			class WfCppCollectClassExprInfoVisitor : public Object, public WfDeclaration::IVisitor
			{
			public:
				WfCppConfig*							config;
				vint									variableCount = 0;
				WfFunctionDeclaration*					firstFunction = nullptr;
				Ptr<analyzer::WfLexicalCapture>			capture;

				WfCppCollectClassExprInfoVisitor(WfCppConfig* _config)
					:config(_config)
				{
				}

				void Visit(WfNamespaceDeclaration* node)override
				{
				}

				void Visit(WfFunctionDeclaration* node)override
				{
					if (!firstFunction)
					{
						firstFunction = node;
						capture = config->manager->lambdaCaptures[node];
					}
				}

				void Visit(WfVariableDeclaration* node)override
				{
					variableCount++;
				}

				void Visit(WfEventDeclaration* node)override
				{
				}

				void Visit(WfPropertyDeclaration* node)override
				{
				}

				void Visit(WfClassDeclaration* node)override
				{
				}

				void Visit(WfConstructorDeclaration* node)override
				{
				}

				void Visit(WfDestructorDeclaration* node)override
				{
				}

				void Visit(WfEnumDeclaration* node)override
				{
				}

				void Visit(WfStructDeclaration* node)override
				{
				}

				void Execute(WfNewInterfaceExpression* node)
				{
					FOREACH(Ptr<WfClassMember>, member, node->members)
					{
						member->declaration->Accept(this);
					}
				}
			};

			Ptr<WfCppConfig::ClosureInfo> WfCppConfig::CollectClosureInfo(Ptr<WfExpression> closure)
			{
				auto info = MakePtr<ClosureInfo>();

				if (auto ordered = closure.Cast<WfOrderedLambdaExpression>())
				{
					info->symbols = manager->lambdaCaptures[ordered.Obj()];
				}
				else if (auto funcExpr = closure.Cast<WfFunctionExpression>())
				{
					info->symbols = manager->lambdaCaptures[funcExpr->function.Obj()];
				}
				else if (auto classExpr = closure.Cast<WfNewInterfaceExpression>())
				{
					WfCppCollectClassExprInfoVisitor visitor(this);
					visitor.Execute(classExpr.Obj());

					info->symbols = MakePtr<WfLexicalCapture>();
					if (visitor.capture)
					{
						CopyFrom(info->symbols->symbols, From(visitor.capture->symbols).Skip(visitor.variableCount));
					}
				}

				return info;
			}

/***********************************************************************
WfCppConfig::WriteCpp
***********************************************************************/

			void WfCppConfig::WriteCpp_ClosureMembers(stream::StreamWriter& writer, Ptr<WfExpression> closure)
			{
				auto info = closureInfos[closure.Obj()];

				FOREACH(Ptr<WfLexicalSymbol>, symbol, info->symbols->symbols)
				{
					writer.WriteString(L"\t\t");
					writer.WriteString(ConvertType(symbol->typeInfo.Obj()));
					writer.WriteString(L" ");
					writer.WriteString(ConvertName(symbol->name));
					writer.WriteLine(L";");
				}

				FOREACH_INDEXER(ITypeDescriptor*, thisType, index, info->thisTypes)
				{
					auto typeInfo = MakePtr<RawPtrTypeInfo>(MakePtr<TypeDescriptorTypeInfo>(thisType, TypeInfoHint::Normal));

					writer.WriteString(L"\t\t");
					writer.WriteString(ConvertType(typeInfo.Obj()));
					writer.WriteString(L" ");
					writer.WriteString(L"__vwsn_this_" + itow(index));
					writer.WriteLine(L";");
				}
			}

			void WfCppConfig::WriteCpp_ClosureCtor(stream::StreamWriter& writer, Ptr<WfExpression> closure, const WString& name)
			{
				auto info = closureInfos[closure.Obj()];

				writer.WriteString(name);
				writer.WriteString(L"(");

				FOREACH_INDEXER(Ptr<WfLexicalSymbol>, symbol, index, info->symbols->symbols)
				{
					if (index > 0)
					{
						writer.WriteString(L", ");
					}
					writer.WriteString(ConvertType(symbol->typeInfo.Obj()));
					writer.WriteString(L" _");
					writer.WriteString(ConvertName(symbol->name));
				}

				FOREACH_INDEXER(ITypeDescriptor*, thisType, index, info->thisTypes)
				{
					auto typeInfo = MakePtr<RawPtrTypeInfo>(MakePtr<TypeDescriptorTypeInfo>(thisType, TypeInfoHint::Normal));

					if (index > 0 || info->symbols->symbols.Count() > 0)
					{
						writer.WriteString(L", ");
					}
					writer.WriteString(ConvertType(typeInfo.Obj()));
					writer.WriteString(L" _");
					writer.WriteString(L"__vwsn_this_" + itow(index));
				}

				writer.WriteString(L")");
			}

			void WfCppConfig::WriteCpp_ClosureCtorInitList(stream::StreamWriter& writer, Ptr<WfExpression> closure)
			{
				auto info = closureInfos[closure.Obj()];

				FOREACH_INDEXER(Ptr<WfLexicalSymbol>, symbol, index, info->symbols->symbols)
				{
					if (index > 0)
					{
						writer.WriteString(L"\t\t, ");
					}
					else
					{
						writer.WriteString(L"\t\t:");
					}
					writer.WriteString(ConvertName(symbol->name));
					writer.WriteString(L"(_");
					writer.WriteString(ConvertName(symbol->name));
					writer.WriteLine(L")");
				}

				FOREACH_INDEXER(ITypeDescriptor*, thisType, index, info->thisTypes)
				{
					if (index > 0 || info->symbols->symbols.Count() > 0)
					{
						writer.WriteString(L"\t\t, ");
					}
					else
					{
						writer.WriteString(L"\t\t:");
					}
					writer.WriteString(L"__vwsn_this_" + itow(index));
					writer.WriteString(L"(_");
					writer.WriteString(L"__vwsn_this_" + itow(index));
					writer.WriteLine(L")");
				}
			}

			void WfCppConfig::WriteCpp_LambdaExprDecl(stream::StreamWriter& writer, Ptr<WfExpression> lambda)
			{
				if (auto ordered = lambda.Cast<WfOrderedLambdaExpression>())
				{
					auto name = lambdaExprs[lambda.Obj()];
					writer.WriteLine(L"\tstruct " + name);
					writer.WriteLine(L"\t{");

					WriteCpp_ClosureMembers(writer, lambda);
					writer.WriteLine(L"");
					writer.WriteString(L"\t\t");
					WriteCpp_ClosureCtor(writer, lambda, name);
					writer.WriteLine(L";");
					writer.WriteLine(L"");

					writer.WriteString(L"\t\t");
					WriteFunctionHeader(writer, ordered, L"operator()", true);
					writer.WriteLine(L" const;");
					writer.WriteLine(L"\t};");
				}
				else if (auto funcExpr = lambda.Cast<WfFunctionExpression>())
				{
					auto name = lambdaExprs[lambda.Obj()];
					writer.WriteLine(L"\tstruct " + name);
					writer.WriteLine(L"\t{");

					WriteCpp_ClosureMembers(writer, lambda);
					writer.WriteLine(L"");
					writer.WriteString(L"\t\t");
					WriteCpp_ClosureCtor(writer, lambda, name);
					writer.WriteLine(L";");
					writer.WriteLine(L"");

					writer.WriteString(L"\t\t");
					WriteFunctionHeader(writer, funcExpr, L"operator()", true);
					writer.WriteLine(L" const;");
					writer.WriteLine(L"\t};");
				}
			}

			void WfCppConfig::WriteCpp_LambdaExprImpl(stream::StreamWriter& writer, Ptr<WfExpression> lambda)
			{
				if (auto ordered = lambda.Cast<WfOrderedLambdaExpression>())
				{
					auto name = lambdaExprs[lambda.Obj()];

					writer.WriteString(L"\t");
					WriteCpp_ClosureCtor(writer, lambda, name + L"::" + name);
					writer.WriteLine(L"");
					WriteCpp_ClosureCtorInitList(writer, lambda);
					writer.WriteLine(L"\t{");
					writer.WriteLine(L"\t}");
					writer.WriteLine(L"");

					writer.WriteString(L"\t");
					WriteFunctionHeader(writer, ordered, name + L"::operator()", true);
					writer.WriteLine(L" const");
					writer.WriteLine(L"\t{");
					WriteFunctionBody(writer, ordered->body, L"\t\t");
					writer.WriteLine(L"\t}");
				}
				else if (auto funcExpr = lambda.Cast<WfFunctionExpression>())
				{
					auto name = lambdaExprs[lambda.Obj()];

					writer.WriteString(L"\t");
					WriteCpp_ClosureCtor(writer, lambda, name + L"::" + name);
					writer.WriteLine(L"");
					WriteCpp_ClosureCtorInitList(writer, lambda);
					writer.WriteLine(L"\t{");
					writer.WriteLine(L"\t}");
					writer.WriteLine(L"");

					writer.WriteString(L"\t");
					WriteFunctionHeader(writer, funcExpr, name + L"::operator()", true);
					writer.WriteLine(L" const");
					writer.WriteLine(L"\t{");
					WriteFunctionBody(writer, funcExpr->function->statement, L"\t\t");
					writer.WriteLine(L"\t}");
				}
			}

			void WfCppConfig::WriteCpp_ClassExprDecl(stream::StreamWriter& writer, Ptr<WfNewInterfaceExpression> lambda)
			{
				auto result = manager->expressionResolvings[lambda.Obj()];
				auto td = result.constructorInfo->GetOwnerTypeDescriptor();
				auto name = classExprs[lambda.Obj()];
				writer.WriteLine(L"\tclass " + name + L" : public ::vl::Object, public virtual " + ConvertFullName(CppGetFullName(td)));
				writer.WriteLine(L"\t{");
				writer.WriteLine(L"\tpublic:");

				WriteCpp_ClosureMembers(writer, lambda);
				writer.WriteLine(L"");
				writer.WriteString(L"\t\t");
				WriteCpp_ClosureCtor(writer, lambda, name);
				writer.WriteLine(L";");
				writer.WriteLine(L"");

				FOREACH(Ptr<WfClassMember>, member, lambda->members)
				{
					GenerateClassMemberDecl(this, writer, name, member, L"\t\t");
				}
				writer.WriteLine(L"\t};");
			}

			void WfCppConfig::WriteCpp_ClassExprImpl(stream::StreamWriter& writer, Ptr<WfNewInterfaceExpression> lambda)
			{
				auto name = classExprs[lambda.Obj()];

				writer.WriteString(L"\t");
				WriteCpp_ClosureCtor(writer, lambda, name + L"::" + name);
				writer.WriteLine(L"");
				WriteCpp_ClosureCtorInitList(writer, lambda);
				writer.WriteLine(L"\t{");
				writer.WriteLine(L"\t}");
				writer.WriteLine(L"");

				FOREACH(Ptr<WfClassMember>, member, lambda->members)
				{
					if (GenerateClassMemberImpl(this, writer, name, name, member, L"\t"))
					{
						writer.WriteLine(L"");
					}
				}
			}
		}
	}
}