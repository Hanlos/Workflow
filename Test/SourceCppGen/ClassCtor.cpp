/***********************************************************************
Generated from ../Resources/Codegen/ClassCtor.txt
***********************************************************************/

#include "ClassCtor.h"

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses-equality"
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#endif
#define GLOBAL_SYMBOL ::vl_workflow_global::ClassCtor::
#define GLOBAL_NAME ::vl_workflow_global::ClassCtor::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::ClassCtor::Instance()

/***********************************************************************
Global Variables and Functions
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_ClassCtor)
	vl_workflow_global::ClassCtor instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS

		instance.s = ::vl::WString(L"", false);
	FINALIZE_GLOBAL_STORAGE_CLASS

		instance.s = ::vl::WString::Empty;
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_ClassCtor)

namespace vl_workflow_global
{
	::vl::WString ClassCtor::main()
	{
		{
			auto a = ::vl::Ptr<::Ctor>(new ::Ctor());
			(GLOBAL_NAME s = (GLOBAL_NAME s + ((((::vl::WString(L"[", false) + ::vl::__vwsn::ToString(::vl::__vwsn::This(a.Obj())->GetX())) + ::vl::WString(L"][", false)) + ::vl::__vwsn::ToString(::vl::__vwsn::This(a.Obj())->GetValue())) + ::vl::WString(L"]", false))));
		}
		{
			auto a = ::vl::Ptr<::Ctor>(new ::Ctor(1, true));
			(GLOBAL_NAME s = (GLOBAL_NAME s + ((((::vl::WString(L"[", false) + ::vl::__vwsn::ToString(::vl::__vwsn::This(a.Obj())->GetX())) + ::vl::WString(L"][", false)) + ::vl::__vwsn::ToString(::vl::__vwsn::This(a.Obj())->GetValue())) + ::vl::WString(L"]", false))));
		}
		{
			auto a = ::vl::Ptr<::Ctor>(new ::Ctor(true, 2));
			(GLOBAL_NAME s = (GLOBAL_NAME s + ((((::vl::WString(L"[", false) + ::vl::__vwsn::ToString(::vl::__vwsn::This(a.Obj())->GetX())) + ::vl::WString(L"][", false)) + ::vl::__vwsn::ToString(::vl::__vwsn::This(a.Obj())->GetValue())) + ::vl::WString(L"]", false))));
		}
		{
			auto a = ::vl::Ptr<::Ctor>(new ::Ctor(1, 2));
			(GLOBAL_NAME s = (GLOBAL_NAME s + ((((::vl::WString(L"[", false) + ::vl::__vwsn::ToString(::vl::__vwsn::This(a.Obj())->GetX())) + ::vl::WString(L"][", false)) + ::vl::__vwsn::ToString(::vl::__vwsn::This(a.Obj())->GetValue())) + ::vl::WString(L"]", false))));
		}
		return GLOBAL_NAME s;
	}

	ClassCtor& ClassCtor::Instance()
	{
		return Getvl_workflow_global_ClassCtor().instance;
	}
}

/***********************************************************************
Class (::Base)
***********************************************************************/

Base::Base()
{
}

Base::Base(::vl::vint32_t _x)
{
	(::vl::__vwsn::This(this)->x = _x);
	if ((::vl::__vwsn::This(this)->x != ::vl::__vwsn::This(this)->x))
	{
		throw ::vl::Exception(::vl::WString(L"The \"this\" expression is not correctly implemented.", false));
	}
}

::vl::vint32_t Base::GetX()
{
	if ((::vl::__vwsn::This(this)->x != ::vl::__vwsn::This(this)->x))
	{
		throw ::vl::Exception(::vl::WString(L"The \"this\" expression is not correctly implemented.", false));
	}
	return ::vl::__vwsn::This(this)->x;
}

void Base::SetX(::vl::vint32_t _x)
{
	if ((::vl::__vwsn::This(this)->x != _x))
	{
		(::vl::__vwsn::This(this)->x = _x);
		::vl::__vwsn::EventInvoke(::vl::__vwsn::This(this)->XChanged)();
	}
}

/***********************************************************************
Class (::Ctor)
***********************************************************************/

Ctor::Ctor()
{
}

Ctor::Ctor(::vl::vint32_t y, bool b)
	: ::Base(y)
{
}

Ctor::Ctor(bool b, ::vl::vint32_t value)
	: ::test::ObservableValue(value, ::vl::Nullable<bool>(b))
{
}

Ctor::Ctor(::vl::vint32_t y, ::vl::vint32_t value)
	: ::Base(y)
	, ::test::ObservableValue(value)
{
}

#undef GLOBAL_SYMBOL
#undef GLOBAL_NAME
#undef GLOBAL_OBJ

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif

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
			IMPL_CPP_TYPE_INFO(::Base)
			IMPL_CPP_TYPE_INFO(::Ctor)

#define _ ,
			BEGIN_CLASS_MEMBER(::Base)
				CLASS_MEMBER_METHOD_OVERLOAD(GetX, NO_PARAMETER, ::vl::vint32_t(::Base::*)())
				CLASS_MEMBER_METHOD_OVERLOAD(SetX, { L"_x" }, void(::Base::*)(::vl::vint32_t))
				CLASS_MEMBER_EVENT(XChanged)
				CLASS_MEMBER_PROPERTY_EVENT(X, GetX, SetX, XChanged)
				CLASS_MEMBER_FIELD(x)
			END_CLASS_MEMBER(::Base)

			BEGIN_CLASS_MEMBER(::Ctor)
			END_CLASS_MEMBER(::Ctor)

#undef _
			class ClassCtorTypeLoader : public Object, public ITypeLoader
			{
			public:
				void Load(ITypeManager* manager)
				{
					ADD_TYPE_INFO(::Base)
					ADD_TYPE_INFO(::Ctor)
				}

				void Unload(ITypeManager* manager)
				{
				}
			};
#endif

			bool LoadClassCtorTypes()
			{
#ifndef VCZH_DEBUG_NO_REFLECTION
				if (auto manager = GetGlobalTypeManager())
				{
					return manager->AddTypeLoader(MakePtr<ClassCtorTypeLoader>());
				}
#endif
				return false;
			}
		}
	}
}
