/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/ListProcessing.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "ListProcessing.h"

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

#define GLOBAL_SYMBOL ::vl_workflow_global::ListProcessing::
#define GLOBAL_NAME ::vl_workflow_global::ListProcessing::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::ListProcessing::Instance()
#define USERIMPL(...)

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_ListProcessing)
	vl_workflow_global::ListProcessing instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_ListProcessing)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	::vl::WString ListProcessing::main()
	{
		auto xs = (::vl::__vwsn::CreateList().Add(1).Add(2).Add(3).Add(4).Add(5)).list;
		auto s1 = ((((::vl::__vwsn::ToString(::vl::__vwsn::This(xs.Obj())->GetCount()) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString(::vl::__vwsn::Unbox<::vl::vint32_t>(::vl::__vwsn::This(xs.Obj())->Get(0)))) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString(::vl::__vwsn::Unbox<::vl::vint32_t>(::vl::__vwsn::This(xs.Obj())->Get(4))));
		::vl::__vwsn::This(xs.Obj())->Set(4, ::vl::__vwsn::Box(6));
		::vl::__vwsn::This(xs.Obj())->Add(::vl::__vwsn::Box(7));
		auto s2 = ((((::vl::__vwsn::ToString(::vl::__vwsn::This(xs.Obj())->GetCount()) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString(::vl::__vwsn::Unbox<::vl::vint32_t>(::vl::__vwsn::This(xs.Obj())->Get(0)))) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString(::vl::__vwsn::Unbox<::vl::vint32_t>(::vl::__vwsn::This(xs.Obj())->Get(4))));
		return ((s1 + ::vl::WString(L", ", false)) + s2);
	}

	ListProcessing& ListProcessing::Instance()
	{
		return Getvl_workflow_global_ListProcessing().instance;
	}
}

#undef GLOBAL_SYMBOL
#undef GLOBAL_NAME
#undef GLOBAL_OBJ
#undef USERIMPL

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif
