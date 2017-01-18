/***********************************************************************
Generated from ../Resources/Codegen/CallStaticMethod.txt
***********************************************************************/

#include "CallStaticMethod.h"

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses-equality"
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#endif
#define GLOBAL_SYMBOL ::vl_workflow_global::CallStaticMethod::
#define GLOBAL_NAME ::vl_workflow_global::CallStaticMethod::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::CallStaticMethod::Instance()

/***********************************************************************
Global Variables and Functions
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_CallStaticMethod)
	vl_workflow_global::CallStaticMethod instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_CallStaticMethod)

namespace vl_workflow_global
{
	::vl::WString CallStaticMethod::main()
	{
		return ::vl::__vwsn::ToString(::Calculator::Internal::Sum(1, 10));
	}

	CallStaticMethod& CallStaticMethod::Instance()
	{
		return Getvl_workflow_global_CallStaticMethod().instance;
	}
}

/***********************************************************************
Class (::Calculator)
***********************************************************************/

::vl::vint32_t Calculator::Sum2(::vl::vint32_t begin, ::vl::vint32_t end, ::vl::vint32_t sum)
{
	if ((begin > end))
	{
		return sum;
	}
	else
	{
		return ::Calculator::Sum2((begin + 1), end, (sum + begin));
	}
}

Calculator::Calculator()
{
}

/***********************************************************************
Class (::Calculator::Internal)
***********************************************************************/

::vl::vint32_t Calculator::Internal::Sum(::vl::vint32_t begin, ::vl::vint32_t end)
{
	return ::Calculator::Sum2(begin, end, 0);
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
			IMPL_CPP_TYPE_INFO(::Calculator)
			IMPL_CPP_TYPE_INFO(::Calculator::Internal)

#define _ ,
			BEGIN_CLASS_MEMBER(::Calculator)
				CLASS_MEMBER_STATIC_METHOD_OVERLOAD(Sum2, { L"begin" _ L"end" _ L"sum" }, ::vl::vint32_t(::Calculator::*)(::vl::vint32_t, ::vl::vint32_t, ::vl::vint32_t))
			END_CLASS_MEMBER(::Calculator)

			BEGIN_INTERFACE_MEMBER(::Calculator::Internal)
				CLASS_MEMBER_STATIC_METHOD_OVERLOAD(Sum, { L"begin" _ L"end" }, ::vl::vint32_t(::Calculator::Internal::*)(::vl::vint32_t, ::vl::vint32_t))
			END_INTERFACE_MEMBER(::Calculator::Internal)

#undef _
			class CallStaticMethodTypeLoader : public Object, public ITypeLoader
			{
			public:
				void Load(ITypeManager* manager)
				{
					ADD_TYPE_INFO(::Calculator)
					ADD_TYPE_INFO(::Calculator::Internal)
				}

				void Unload(ITypeManager* manager)
				{
				}
			};
#endif

			bool LoadCallStaticMethodTypes()
			{
#ifndef VCZH_DEBUG_NO_REFLECTION
				if (auto manager = GetGlobalTypeManager())
				{
					return manager->AddTypeLoader(MakePtr<CallStaticMethodTypeLoader>());
				}
#endif
				return false;
			}
		}
	}
}
