/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/IfNotNull.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "IfNotNull.h"

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses-equality"
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#endif
#define GLOBAL_SYMBOL ::vl_workflow_global::IfNotNull::
#define GLOBAL_NAME ::vl_workflow_global::IfNotNull::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::IfNotNull::Instance()

/***********************************************************************
Global Variables and Functions
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_IfNotNull)
	vl_workflow_global::IfNotNull instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_IfNotNull)

namespace vl_workflow_global
{
	::vl::WString IfNotNull::main()
	{
		auto x = ::vl::__vwsn::Box((::vl::__vwsn::CreateList().Add(1)).list);
		auto y = ::vl::__vwsn::Box((::vl::__vwsn::CreateDictionary().Add(1, 2)).dictionary);
		auto s = ::vl::WString(L"", false);
		if (auto z = ::vl::__vwsn::UnboxWeak<::vl::Ptr<::vl::reflection::description::IValueList>>(x))
		{
			(s = (s + ::vl::WString(L"{1} is a list", false)));
		}
		else
		{
			(s = (s + ::vl::WString(L"{1} is not a list", false)));
		}
		(s = (s + ::vl::WString(L", ", false)));
		if (auto z = ::vl::__vwsn::UnboxWeak<::vl::Ptr<::vl::reflection::description::IValueList>>(y))
		{
			(s = (s + ::vl::WString(L"{1:2} is a list", false)));
		}
		else
		{
			(s = (s + ::vl::WString(L"{1:2} is not a list", false)));
		}
		return s;
	}

	IfNotNull& IfNotNull::Instance()
	{
		return Getvl_workflow_global_IfNotNull().instance;
	}
}

#undef GLOBAL_SYMBOL
#undef GLOBAL_NAME
#undef GLOBAL_OBJ

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif
