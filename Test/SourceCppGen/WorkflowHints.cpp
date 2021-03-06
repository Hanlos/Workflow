/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/WorkflowHints.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "WorkflowHints.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses-equality"
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#endif

#define GLOBAL_SYMBOL ::vl_workflow_global::WorkflowHints::
#define GLOBAL_NAME ::vl_workflow_global::WorkflowHints::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::WorkflowHints::Instance()
#define USERIMPL(...)

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_WorkflowHints)
	vl_workflow_global::WorkflowHints instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_WorkflowHints)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	void WorkflowHints::Ensure(bool condition)
	{
		if ((! condition))
		{
			throw ::vl::Exception(::vl::WString(L"Wrong!", false));
		}
	}

	void WorkflowHints::ExtraTests()
	{
		GLOBAL_NAME Ensure((::vl::__vwsn::ToString(123) == ::vl::WString(L"123", false)));
		GLOBAL_NAME Ensure((::vl::__vwsn::Parse<::vl::vint32_t>(::vl::WString(L"123", false)) == 123));
		auto sBase = ::vl::Ptr<::workflow::hints::Base>(new ::workflow::hints::Base());
		auto rBase = new ::workflow::hints::Base(0);
		auto sDerived = ::vl::Ptr<::workflow::hints::Derived>(new ::workflow::hints::Derived());
		auto rDerived = new ::workflow::hints::Derived(0);
		auto srBase = ::vl::__vwsn::Ensure(::vl::Ptr<::workflow::hints::Base>(rBase));
		auto srDerived = ::vl::__vwsn::Ensure(::vl::Ptr<::workflow::hints::Derived>(rDerived));
		GLOBAL_NAME Ensure((::vl::__vwsn::Ensure(static_cast<::workflow::hints::Base*>(sDerived.Obj())) != nullptr));
		GLOBAL_NAME Ensure(static_cast<bool>(::vl::__vwsn::Ensure(::vl::Ptr<::workflow::hints::Base>(sDerived))));
		GLOBAL_NAME Ensure((::vl::__vwsn::Ensure(static_cast<::workflow::hints::Base*>(rDerived)) != nullptr));
		GLOBAL_NAME Ensure(static_cast<bool>(::vl::__vwsn::Ensure(::vl::Ptr<::workflow::hints::Base>(rDerived))));
		GLOBAL_NAME Ensure((::vl::__vwsn::RawPtrCast<::workflow::hints::Derived>(sBase.Obj()) == nullptr));
		GLOBAL_NAME Ensure((! static_cast<bool>(::vl::__vwsn::SharedPtrCast<::workflow::hints::Derived>(sBase.Obj()))));
		GLOBAL_NAME Ensure((::vl::__vwsn::RawPtrCast<::workflow::hints::Derived>(rBase) == nullptr));
		GLOBAL_NAME Ensure((! static_cast<bool>(::vl::__vwsn::SharedPtrCast<::workflow::hints::Derived>(rBase))));
		GLOBAL_NAME Ensure(true);
		GLOBAL_NAME Ensure((::vl::__vwsn::RawPtrCast<::workflow::hints::Base>(sBase.Obj()) != nullptr));
		GLOBAL_NAME Ensure(true);
		GLOBAL_NAME Ensure((::vl::__vwsn::RawPtrCast<::workflow::hints::Derived>(sBase.Obj()) == nullptr));
		GLOBAL_NAME Ensure((::vl::__vwsn::RawPtrCast<::workflow::hints::Base>(rBase) != nullptr));
		GLOBAL_NAME Ensure(true);
		GLOBAL_NAME Ensure((::vl::__vwsn::RawPtrCast<::workflow::hints::Derived>(rBase) == nullptr));
		GLOBAL_NAME Ensure(true);
		GLOBAL_NAME Ensure(true);
		GLOBAL_NAME Ensure((::vl::__vwsn::RawPtrCast<::workflow::hints::Base>(sDerived.Obj()) != nullptr));
		GLOBAL_NAME Ensure(true);
		GLOBAL_NAME Ensure((! (::vl::__vwsn::RawPtrCast<::workflow::hints::Derived>(sDerived.Obj()) == nullptr)));
		GLOBAL_NAME Ensure((::vl::__vwsn::RawPtrCast<::workflow::hints::Base>(rDerived) != nullptr));
		GLOBAL_NAME Ensure(true);
		GLOBAL_NAME Ensure((! (::vl::__vwsn::RawPtrCast<::workflow::hints::Derived>(rDerived) == nullptr)));
		GLOBAL_NAME Ensure(true);
		auto iNull = ::vl::Nullable<::vl::vint32_t>();
		auto iValue = ::vl::Nullable<::vl::vint32_t>(1);
		auto sNull = ::vl::Nullable<::vl::WString>();
		auto sValue = ::vl::Nullable<::vl::WString>(::vl::WString(L"2", false));
		GLOBAL_NAME Ensure((! static_cast<bool>(iNull)));
		GLOBAL_NAME Ensure(static_cast<bool>(iValue));
		GLOBAL_NAME Ensure((! static_cast<bool>(sNull)));
		GLOBAL_NAME Ensure(static_cast<bool>(sValue));
		GLOBAL_NAME Ensure((! static_cast<bool>(::vl::__vwsn::NullableCast<::vl::WString>(iNull))));
		GLOBAL_NAME Ensure((::vl::__vwsn::NullableCast<::vl::WString>(iValue) == ::vl::Nullable<::vl::WString>(::vl::WString(L"1", false))));
		GLOBAL_NAME Ensure((::vl::__vwsn::ToString(iValue.Value()) == ::vl::WString(L"1", false)));
		GLOBAL_NAME Ensure((! static_cast<bool>(::vl::__vwsn::NullableCast<::vl::vint32_t>(sNull))));
		GLOBAL_NAME Ensure((::vl::__vwsn::NullableCast<::vl::vint32_t>(sValue) == ::vl::Nullable<::vl::vint32_t>(2)));
		GLOBAL_NAME Ensure((::vl::__vwsn::Parse<::vl::vint32_t>(sValue.Value()) == 2));
		GLOBAL_NAME Ensure((! static_cast<bool>(iNull)));
		GLOBAL_NAME Ensure(static_cast<bool>(iValue));
		GLOBAL_NAME Ensure((! static_cast<bool>(sNull)));
		GLOBAL_NAME Ensure(static_cast<bool>(sValue));
		auto x = ::vl::reflection::description::Value();
		auto y = ::vl::__vwsn::Box(2);
		GLOBAL_NAME Ensure(x.IsNull());
		GLOBAL_NAME Ensure((! y.IsNull()));
		GLOBAL_NAME Ensure((dynamic_cast<::vl::reflection::description::IValueType::TypedBox<::vl::vint32_t>*>(x.GetBoxedValue().Obj()) == nullptr));
		GLOBAL_NAME Ensure((dynamic_cast<::vl::reflection::description::IValueType::TypedBox<::vl::vint32_t>*>(y.GetBoxedValue().Obj()) != nullptr));
		auto z = ::vl::__vwsn::Box(rBase);
		GLOBAL_NAME Ensure((! z.IsNull()));
		GLOBAL_NAME Ensure([&](){ auto __vwsn_temp__ = z; return !__vwsn_temp__.GetSharedPtr() && ::vl::__vwsn::RawPtrCast<::workflow::hints::Base>(__vwsn_temp__.GetRawPtr()) != nullptr; }());
		GLOBAL_NAME Ensure([&](){ auto __vwsn_temp__ = z; return !__vwsn_temp__.GetSharedPtr() || ::vl::__vwsn::RawPtrCast<::workflow::hints::Base>(__vwsn_temp__.GetRawPtr()) == nullptr; }());
		GLOBAL_NAME Ensure([&](){ auto __vwsn_temp__ = z; return __vwsn_temp__.GetSharedPtr() || ::vl::__vwsn::RawPtrCast<::workflow::hints::Derived>(__vwsn_temp__.GetRawPtr()) == nullptr; }());
		GLOBAL_NAME Ensure([&](){ auto __vwsn_temp__ = z; return !__vwsn_temp__.GetSharedPtr() || ::vl::__vwsn::RawPtrCast<::workflow::hints::Derived>(__vwsn_temp__.GetRawPtr()) == nullptr; }());
	}

	::vl::WString WorkflowHints::main()
	{
		GLOBAL_NAME ExtraTests();
		auto hinters = ::vl::Ptr<::test::Hinters>(::test::CreateHinter());
		{
			auto hinters2 = ::test::CreateHinter(0);
			::vl::__vwsn::This(hinters2)->Dispose(true);
		}
		auto a = [&]()->decltype(auto){ auto __vwsn_temp_x0 = ::vl::__vwsn::Box((::vl::__vwsn::CreateList().Add(1).Add(2).Add(3)).list); ::vl::collections::List<::vl::vint32_t> __vwsn_temp_0; ::vl::reflection::description::UnboxParameter(__vwsn_temp_x0, __vwsn_temp_0); auto __vwsn_temp_1 = 4; return ::vl::__vwsn::This(hinters.Obj())->GetList(__vwsn_temp_0, __vwsn_temp_1); }()[0];
		auto b = [&]()->decltype(auto){ auto __vwsn_temp_x0 = ::vl::__vwsn::Box(::vl::Ptr<::vl::reflection::description::IValueReadonlyList>((::vl::__vwsn::CreateList().Add(10).Add(20).Add(30)).list)); ::vl::collections::List<::vl::vint32_t> __vwsn_temp_0; ::vl::reflection::description::UnboxParameter(__vwsn_temp_x0, __vwsn_temp_0); return ::vl::__vwsn::This(hinters.Obj())->GetReadonlyList(__vwsn_temp_0); }()[0];
		auto c = ::vl::__vwsn::Unbox<::vl::vint32_t>(::vl::__vwsn::This([&]()->decltype(auto){ auto __vwsn_temp_x0 = ::vl::__vwsn::Box(::vl::Ptr<::vl::reflection::description::IValueReadonlyList>((::vl::__vwsn::CreateList().Add(100).Add(200).Add(300)).list)); ::vl::collections::Array<::vl::vint32_t> __vwsn_temp_0; ::vl::reflection::description::UnboxParameter(__vwsn_temp_x0, __vwsn_temp_0); return ::vl::__vwsn::UnboxCollection<::vl::reflection::description::IValueReadonlyList>(::vl::__vwsn::This(hinters.Obj())->GetReadonlyArray(__vwsn_temp_0)); }().Obj())->Get(0));
		auto d = ::vl::__vwsn::Unbox<::vl::vint32_t>(::vl::__vwsn::This([&]()->decltype(auto){ auto __vwsn_temp_x0 = ::vl::__vwsn::Box(::vl::Ptr<::vl::reflection::description::IValueReadonlyList>((::vl::__vwsn::CreateList().Add(1000).Add(2000).Add(3000)).list)); ::vl::collections::SortedList<::vl::vint32_t> __vwsn_temp_0; ::vl::reflection::description::UnboxParameter(__vwsn_temp_x0, __vwsn_temp_0); return ::vl::__vwsn::UnboxCollection<::vl::reflection::description::IValueReadonlyList>(::vl::__vwsn::This(hinters.Obj())->GetReadonlySL(__vwsn_temp_0)); }().Obj())->Get(0));
		auto e = [&]()->decltype(auto){ auto __vwsn_temp_x0 = ::vl::__vwsn::Box((::vl::__vwsn::CreateDictionary().Add(1, 2).Add(3, 4)).dictionary); ::vl::collections::Dictionary<::vl::vint32_t, ::vl::vint32_t> __vwsn_temp_0; ::vl::reflection::description::UnboxParameter(__vwsn_temp_x0, __vwsn_temp_0); return ::test::GetDictionaryFromHinter(::vl::__vwsn::This(hinters.Obj()), __vwsn_temp_0); }()[1];
		auto f = [&]()->decltype(auto){ auto __vwsn_temp_x0 = ::vl::__vwsn::Box(::vl::Ptr<::vl::reflection::description::IValueReadonlyDictionary>((::vl::__vwsn::CreateDictionary().Add(10, 20).Add(30, 40)).dictionary)); ::vl::collections::Dictionary<::vl::vint32_t, ::vl::vint32_t> __vwsn_temp_0; ::vl::reflection::description::UnboxParameter(__vwsn_temp_x0, __vwsn_temp_0); return ::test::GetReadonlyDictionaryFromHinter(::vl::__vwsn::This(hinters.Obj()), __vwsn_temp_0); }()[10];
		[&]()->decltype(auto){ auto __vwsn_temp_x0 = ::vl::__vwsn::Box((::vl::__vwsn::CreateList().Add(1).Add(2).Add(3).Add(4).Add(5)).list); ::vl::collections::List<::vl::vint32_t> __vwsn_temp_0; ::vl::reflection::description::UnboxParameter(__vwsn_temp_x0, __vwsn_temp_0); return ::vl::__vwsn::This(hinters.Obj())->SetStorage(__vwsn_temp_0); }();
		auto g1 = ::vl::__vwsn::Unbox<::vl::vint32_t>(::vl::__vwsn::This(::vl::__vwsn::UnboxCollection<::vl::reflection::description::IValueList>(::vl::__vwsn::This(hinters.Obj())->GetStorage()).Obj())->Get(0));
		auto xs = (::vl::__vwsn::CreateList().Add(1).Add(2).Add(3).Add(4).Add(5)).list;
		[&]()->decltype(auto){ auto __vwsn_temp_x0 = ::vl::__vwsn::Box(xs); ::vl::collections::List<::vl::vint32_t> __vwsn_temp_0; ::vl::reflection::description::UnboxParameter(__vwsn_temp_x0, __vwsn_temp_0); return ::vl::__vwsn::This(hinters.Obj())->SetStorage(__vwsn_temp_0); }();
		::vl::__vwsn::This(hinters.Obj())->GetStorage().Set(4, 100);
		auto g2 = ::vl::__vwsn::This(hinters.Obj())->GetStorage()[4];
		using __vwsnt_0 = ::vl::vint32_t;
		FOREACH(__vwsnt_0, x, ::vl::__vwsn::Range(1, 5 + 1))
		{
			::vl::__vwsn::This(::vl::__vwsn::UnboxCollection<::vl::reflection::description::IValueList>(::vl::__vwsn::This(hinters.Obj())->GetMyList()).Obj())->Add(::vl::__vwsn::Box(x));
		}
		return ((((((((((((((((((::vl::WString(L"[", false) + ::vl::__vwsn::ToString(a)) + ::vl::WString(L"][", false)) + ::vl::__vwsn::ToString(b)) + ::vl::WString(L"][", false)) + ::vl::__vwsn::ToString(c)) + ::vl::WString(L"][", false)) + ::vl::__vwsn::ToString(d)) + ::vl::WString(L"][", false)) + ::vl::__vwsn::ToString(e)) + ::vl::WString(L"][", false)) + ::vl::__vwsn::ToString(f)) + ::vl::WString(L"][", false)) + ::vl::__vwsn::ToString(g1)) + ::vl::WString(L"][", false)) + ::vl::__vwsn::ToString(g2)) + ::vl::WString(L"][", false)) + ::vl::__vwsn::ToString(::vl::__vwsn::Unbox<::vl::vint32_t>(::vl::__vwsn::This(::vl::__vwsn::UnboxCollection<::vl::reflection::description::IValueList>(::vl::__vwsn::This(hinters.Obj())->GetMyList()).Obj())->Get(2)))) + ::vl::WString(L"]", false));
	}

	WorkflowHints& WorkflowHints::Instance()
	{
		return Getvl_workflow_global_WorkflowHints().instance;
	}
}

/***********************************************************************
Class (::workflow::hints::Base)
***********************************************************************/

namespace workflow
{
	namespace hints
	{
		Base::Base()
		{
		}

		Base::Base(::vl::vint32_t x)
		{
		}

/***********************************************************************
Class (::workflow::hints::Derived)
***********************************************************************/

		Derived::Derived()
		{
		}

		Derived::Derived(::vl::vint32_t x)
		{
		}

	}
}
#undef GLOBAL_SYMBOL
#undef GLOBAL_NAME
#undef GLOBAL_OBJ
#undef USERIMPL

/***********************************************************************
Reflection
***********************************************************************/

namespace vl
{
	namespace reflection
	{
		namespace description
		{
#ifndef VCZH_DEBUG_NO_REFLECTION
			IMPL_CPP_TYPE_INFO(workflow::hints::Base)
			IMPL_CPP_TYPE_INFO(workflow::hints::Derived)

#define _ ,
			BEGIN_CLASS_MEMBER(::workflow::hints::Base)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::workflow::hints::Base>(), NO_PARAMETER)
				CLASS_MEMBER_CONSTRUCTOR(::workflow::hints::Base*(::vl::vint32_t), { L"x" })
			END_CLASS_MEMBER(::workflow::hints::Base)

			BEGIN_CLASS_MEMBER(::workflow::hints::Derived)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::workflow::hints::Derived>(), NO_PARAMETER)
				CLASS_MEMBER_CONSTRUCTOR(::workflow::hints::Derived*(::vl::vint32_t), { L"x" })
			END_CLASS_MEMBER(::workflow::hints::Derived)

#undef _
			class WorkflowHintsTypeLoader : public Object, public ITypeLoader
			{
			public:
				void Load(ITypeManager* manager)
				{
					ADD_TYPE_INFO(::workflow::hints::Base)
					ADD_TYPE_INFO(::workflow::hints::Derived)
				}

				void Unload(ITypeManager* manager)
				{
				}
			};
#endif

			bool LoadWorkflowHintsTypes()
			{
#ifndef VCZH_DEBUG_NO_REFLECTION
				if (auto manager = GetGlobalTypeManager())
				{
					return manager->AddTypeLoader(MakePtr<WorkflowHintsTypeLoader>());
				}
#endif
				return false;
			}
		}
	}
}

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif
