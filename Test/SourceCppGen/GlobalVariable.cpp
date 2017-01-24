/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/GlobalVariable.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "GlobalVariable.h"

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

#define GLOBAL_SYMBOL ::vl_workflow_global::GlobalVariable::
#define GLOBAL_NAME ::vl_workflow_global::GlobalVariable::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::GlobalVariable::Instance()
#define USERIMPL(...)

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_GlobalVariable)
	vl_workflow_global::GlobalVariable instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS

		instance.x = 0;
	FINALIZE_GLOBAL_STORAGE_CLASS

END_GLOBAL_STORAGE_CLASS(vl_workflow_global_GlobalVariable)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	::vl::vint32_t GlobalVariable::Add(::vl::vint32_t y)
	{
		auto z = GLOBAL_NAME x;
		(GLOBAL_NAME x = (GLOBAL_NAME x + y));
		return z;
	}

	::vl::WString GlobalVariable::main()
	{
		(GLOBAL_NAME x = 10);
		auto y = GLOBAL_NAME Add(20);
		return ((::vl::__vwsn::ToString(GLOBAL_NAME x) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString(y));
	}

	GlobalVariable& GlobalVariable::Instance()
	{
		return Getvl_workflow_global_GlobalVariable().instance;
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
