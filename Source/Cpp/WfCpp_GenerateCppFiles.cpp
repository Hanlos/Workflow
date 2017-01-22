#include "WfCpp.h"

namespace vl
{
	namespace workflow
	{
		namespace cppcodegen
		{
			using namespace collections;
			using namespace stream;
			using namespace filesystem;

/***********************************************************************
WfCppInput
***********************************************************************/

			WfCppInput::WfCppInput(const WString& _assemblyName)
			{
				headerGuardPrefix = L"VCZH_WORKFLOW_COMPILER_GENERATED_";
				assemblyName = _assemblyName;
				assemblyNamespace = L"vl_workflow_global";
				includeFileName = _assemblyName + L"Includes";
				defaultFileName = _assemblyName;
			}

/***********************************************************************
GenerateCppFiles
***********************************************************************/

			template<typename TCallback>
			WString GenerateToStream(const TCallback& callback)
			{
				MemoryStream stream;
				{
					StreamWriter writer(stream);
					callback(writer);
				}
				stream.SeekFromBegin(0);
				{
					StreamReader reader(stream);
					return reader.ReadToEnd();
				}
			}

			void GenerateCppComment(StreamWriter& writer, const WString& comment)
			{
				writer.WriteLine(L"/***********************************************************************");
				writer.WriteLine(L"!!!!!! DO NOT MODIFY !!!!!!");
				writer.WriteLine(L"");
				writer.WriteLine(comment);
				writer.WriteLine(L"");
				writer.WriteLine(L"This file is generated by Workflow compiler");
				writer.WriteLine(L"https://github.com/vczh-libraries");
				writer.WriteLine(L"***********************************************************************/");
			}

			Ptr<WfCppOutput> GenerateCppFiles(Ptr<WfCppInput> input, analyzer::WfLexicalScopeManager* manager)
			{
				WfCppConfig config(manager, input->assemblyName, input->assemblyNamespace);
				auto output = MakePtr<WfCppOutput>();

				bool multiFile = false;
				switch (input->multiFile)
				{
				case WfCppMultiFile::Enabled:
					multiFile = true;
					break;
				case WfCppMultiFile::Disabled:
					multiFile = false;
					break;
				default:
					multiFile = config.topLevelClassDeclsForFiles.Count() > 1;
				}

				output->cppFiles.Add(input->defaultFileName + L".h", GenerateToStream([&](StreamWriter& writer)
				{
					GenerateCppComment(writer, input->comment);
					writer.WriteLine(L"");
					writer.WriteLine(L"#ifndef " + input->headerGuardPrefix + wupper(input->defaultFileName));
					writer.WriteLine(L"#define " + input->headerGuardPrefix + wupper(input->defaultFileName));
					writer.WriteLine(L"");
					FOREACH(WString, include, input->normalIncludes)
					{
						writer.WriteLine(L"#include \"" + include + L"\"");
					}
					if (input->reflectionIncludes.Count() > 0)
					{
						writer.WriteLine(L"#ifndef VCZH_DEBUG_NO_REFLECTION");
						FOREACH(WString, include, input->reflectionIncludes)
						{
							writer.WriteLine(L"#include \"" + include + L"\"");
						}
						writer.WriteLine(L"#endif");
					}
					writer.WriteLine(L"");
					config.WriteHeader(writer, multiFile);
					writer.WriteLine(L"");
					writer.WriteLine(L"#endif");
				}));

				output->cppFiles.Add(input->defaultFileName + L".cpp", GenerateToStream([&](StreamWriter& writer)
				{
					GenerateCppComment(writer, input->comment);
					writer.WriteLine(L"");
					if (multiFile)
					{
						writer.WriteLine(L"#include \"" + input->includeFileName + L".h\"");
					}
					else
					{
						writer.WriteLine(L"#include \"" + input->defaultFileName + L".h\"");
					}
					writer.WriteLine(L"");
					config.WriteCpp(writer, multiFile);
				}));

				if (multiFile)
				{
					output->cppFiles.Add(input->includeFileName + L".h", GenerateToStream([&](StreamWriter& writer)
					{
						GenerateCppComment(writer, input->comment);
						writer.WriteLine(L"");
						writer.WriteLine(L"#ifndef " + input->headerGuardPrefix + wupper(input->includeFileName));
						writer.WriteLine(L"#define " + input->headerGuardPrefix + wupper(input->includeFileName));
						writer.WriteLine(L"");

						writer.WriteLine(L"#include \"" + input->defaultFileName + L".h\"");
						FOREACH(WString, fileName, config.topLevelClassDeclsForFiles.Keys())
						{
							if (fileName != L"")
							{
								writer.WriteLine(L"#include \"" + fileName + L".h\"");
							}
						}

						if (config.manager->declarationTypes.Count() > 0)
						{
							writer.WriteLine(L"");
							config.WriteHeader_Reflection(writer);
						}

						writer.WriteLine(L"");
						writer.WriteLine(L"#endif");
					}));

					FOREACH(WString, fileName, config.topLevelClassDeclsForFiles.Keys())
					{
						if (fileName != L"")
						{
							output->cppFiles.Add(fileName + L".h", GenerateToStream([&](StreamWriter& writer)
							{
								GenerateCppComment(writer, input->comment);
								writer.WriteLine(L"");
								writer.WriteLine(L"#ifndef " + input->headerGuardPrefix + wupper(fileName));
								writer.WriteLine(L"#define " + input->headerGuardPrefix + wupper(fileName));
								writer.WriteLine(L"");
								writer.WriteLine(L"#include \"" + input->defaultFileName + L".h\"");
								{
									List<Ptr<WfDeclaration>> decls;
									CopyFrom(decls, config.topLevelClassDeclsForFiles[fileName]);
									for (vint i = 0; i < decls.Count(); i++)
									{
										if (auto classDecl = decls[i].Cast<WfClassDeclaration>())
										{
											{
												vint index = config.enumDecls.Keys().IndexOf(classDecl.Obj());
												if (index != -1)
												{
													CopyFrom(decls, config.enumDecls.GetByIndex(index), true);
												}
											}
											{
												vint index = config.structDecls.Keys().IndexOf(classDecl.Obj());
												if (index != -1)
												{
													CopyFrom(decls, config.structDecls.GetByIndex(index), true);
												}
											}
											{
												vint index = config.classDecls.Keys().IndexOf(classDecl.Obj());
												if (index != -1)
												{
													CopyFrom(decls, config.classDecls.GetByIndex(index), true);
												}
											}
										}
									}

									SortedList<WString> fileNames;
									FOREACH(Ptr<WfDeclaration>, decl, decls)
									{
										vint index = config.declDependencies.Keys().IndexOf(decl.Obj());
										if (index != -1)
										{
											FOREACH(Ptr<WfDeclaration>, declDep, config.declDependencies.GetByIndex(index))
											{
												WString fileName = config.declFiles[declDep.Obj()];
												if (fileName != L"" && !fileNames.Contains(fileName))
												{
													fileNames.Add(fileName);
												}
											}
										}
									}

									FOREACH(WString, fileName, fileNames)
									{
										writer.WriteLine(L"#include \"" + fileName + L".h\"");
									}
								}
								writer.WriteLine(L"");
								config.WriteSubHeader(writer, fileName);
								writer.WriteLine(L"");
								writer.WriteLine(L"#endif");
							}));

							output->cppFiles.Add(fileName + L".cpp", GenerateToStream([&](StreamWriter& writer)
							{
								GenerateCppComment(writer, input->comment);
								writer.WriteLine(L"");
								writer.WriteLine(L"#include \"" + input->includeFileName + L".h\"");
								writer.WriteLine(L"");
								config.WriteSubCpp(writer, fileName);
							}));
						}
					}
				}

				return output;
			}

/***********************************************************************
MergeCppFile
***********************************************************************/

			WString RemoveSpacePrefix(const WString& s)
			{
				for (vint i = 0; i < s.Length(); i++)
				{
					if (s[i] != L' '&&s[i] != L'\t')
					{
						return s.Sub(i, s.Length() - i);
					}
				}
				return WString::Empty;
			}

			const vint NORMAL = 0;
			const vint WAIT_HEADER = 1;
			const vint WAIT_OPEN = 2;
			const vint WAIT_CLOSE = 3;
			const vint UNUSED_USER_CONTENT = 4;

			template<typename TCallback>
			void ProcessCppContent(const WString& code, const TCallback& callback)
			{
				vint state = NORMAL;

				StringReader reader(code);
				while (!reader.IsEnd())
				{
					auto line = reader.ReadLine();
					if (reader.IsEnd() && line == L"")
					{
						break;
					}

					if (line == L"// UNUSED_USER_CONTENT:")
					{
						state = UNUSED_USER_CONTENT;
					}

					if (state == UNUSED_USER_CONTENT)
					{
						callback(state, state, line, line);
					}
					else
					{
						auto content = RemoveSpacePrefix(line);
						auto previousState = state;
						switch (state)
						{
						case NORMAL:
							if (content.Length() > 9 && content.Sub(0, 9) == L"USERIMPL(")
							{
								state = WAIT_HEADER;
							}
							break;
						case WAIT_HEADER:
							state = WAIT_OPEN;
							break;
						case WAIT_OPEN:
							if (content == L"{")
							{
								state = WAIT_CLOSE;
							}
							break;
						case WAIT_CLOSE:
							if (content == L"}")
							{
								state = NORMAL;
							}
							break;
						}
						callback(previousState, state, line, content);
					}
				}
			}

			WString MergeCppFileContent(const WString& dst, const WString& src)
			{
				Dictionary<WString, WString> userContents, userContentsFull;
				WString unusedUserContent = GenerateToStream([&](StreamWriter& writer)
				{
					WString name;
					WString userImpl;
					WString userImplFull;
					ProcessCppContent(dst, [&](vint previousState, vint state, const WString& line, const WString& content)
					{
						if (state == UNUSED_USER_CONTENT)
						{
							writer.WriteLine(line);
						}
						else
						{
							if (previousState == NORMAL && state == WAIT_HEADER)
							{
								name = content;
								userImpl = L"";
								userImplFull = L"";
							}
							else if (previousState == WAIT_HEADER)
							{
								name += content;
							}
							else if (previousState == WAIT_CLOSE && state == WAIT_CLOSE)
							{
								userImpl += line + L"\r\n";
							}
							else if (previousState == WAIT_CLOSE && state == NORMAL)
							{
								userImplFull += L"//" + line + L"\r\n";
								userContents.Add(name, userImpl);
								userContentsFull.Add(name, userImplFull);
								name = L"";
							}

							if (name != L"")
							{
								userImplFull += L"//" + line + L"\r\n";
							}
						}
					});
				});
				
				return GenerateToStream([&](StreamWriter& writer)
				{
					WString name;
					WString userImpl;
					ProcessCppContent(src, [&](vint previousState, vint state, const WString& line, const WString& content)
					{
						if (previousState == NORMAL && state == WAIT_HEADER)
						{
							name = content;
							userImpl = L"";
						}
						else if (previousState == WAIT_HEADER)
						{
							name += content;
						}
						else if (previousState == WAIT_CLOSE && state == WAIT_CLOSE)
						{
							userImpl += line + L"\r\n";
							return;
						}
						else if (previousState == WAIT_CLOSE && state == NORMAL)
						{
							vint index = userContents.Keys().IndexOf(name);
							if (index == -1)
							{
								writer.WriteString(userImpl);
							}
							else
							{
								writer.WriteString(userContents.Values()[index]);
								userContentsFull.Remove(name);
							}
						}
						writer.WriteLine(line);
					});

					writer.WriteString(unusedUserContent);
					if (userContentsFull.Count() > 0)
					{
						if (unusedUserContent == L"")
						{
							writer.WriteLine(L"// UNUSED_USER_CONTENT:");
						}
						FOREACH(WString, content, userContentsFull.Values())
						{
							writer.WriteString(content);
						}
					}
				});
			}
		}
	}
}
