/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/HelloWorld.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "HelloWorld.h"

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses-equality"
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#endif
#define GLOBAL_SYMBOL ::vl_workflow_global::HelloWorld::
#define GLOBAL_NAME ::vl_workflow_global::HelloWorld::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::HelloWorld::Instance()

/***********************************************************************
Global Variables and Functions
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_HelloWorld)
	vl_workflow_global::HelloWorld instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_HelloWorld)

namespace vl_workflow_global
{
	::vl::WString HelloWorld::main()
	{
		return ::vl::WString(L"Hello, world!", false);
	}

	HelloWorld& HelloWorld::Instance()
	{
		return Getvl_workflow_global_HelloWorld().instance;
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
