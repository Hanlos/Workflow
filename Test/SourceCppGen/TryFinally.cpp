/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/TryFinally.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "TryFinally.h"

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

#define GLOBAL_SYMBOL ::vl_workflow_global::TryFinally::
#define GLOBAL_NAME ::vl_workflow_global::TryFinally::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::TryFinally::Instance()
#define USERIMPL(...)

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_TryFinally)
	vl_workflow_global::TryFinally instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS

		instance.sum = 0;
	FINALIZE_GLOBAL_STORAGE_CLASS

END_GLOBAL_STORAGE_CLASS(vl_workflow_global_TryFinally)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	void TryFinally::test1()
	{
		using __vwsnt_0 = ::vl::vint32_t;
		FOREACH(__vwsnt_0, x, ::vl::__vwsn::Range(1, 5 + 1))
		{
			{
				auto __vwsnb_0 = [&]()
				{
					(GLOBAL_NAME sum = (GLOBAL_NAME sum + 1));
				}
				;
				::vl::__vwsn::RunOnExit<::vl::RemoveCVR<decltype(__vwsnb_0)>::Type> __vwsnb_0_dtor(&__vwsnb_0);
				try
				{
					{
						continue;
					}
				}
				catch(const ::vl::Exception&)
				{
				}
				catch(const ::vl::Error&)
				{
				}
			}
		}
	}

	void TryFinally::test2()
	{
		using __vwsnt_0 = ::vl::vint32_t;
		FOREACH(__vwsnt_0, x, ::vl::__vwsn::Range(1, 5 + 1))
		{
			{
				auto __vwsnb_0 = [&]()
				{
					(GLOBAL_NAME sum = (GLOBAL_NAME sum + 10));
				}
				;
				::vl::__vwsn::RunOnExit<::vl::RemoveCVR<decltype(__vwsnb_0)>::Type> __vwsnb_0_dtor(&__vwsnb_0);
				try
				{
					{
						break;
					}
				}
				catch(const ::vl::Exception&)
				{
				}
				catch(const ::vl::Error&)
				{
				}
			}
		}
	}

	void TryFinally::test3()
	{
		{
			auto __vwsnb_0 = [&]()
			{
				(GLOBAL_NAME sum = (GLOBAL_NAME sum + 100));
			}
			;
			::vl::__vwsn::RunOnExit<::vl::RemoveCVR<decltype(__vwsnb_0)>::Type> __vwsnb_0_dtor(&__vwsnb_0);
			try
			{
				{
					return;
				}
			}
			catch(const ::vl::Exception&)
			{
			}
			catch(const ::vl::Error&)
			{
			}
		}
	}

	void TryFinally::test4()
	{
		{
			auto __vwsnb_0 = [&]()
			{
				(GLOBAL_NAME sum = (GLOBAL_NAME sum + 1000));
			}
			;
			::vl::__vwsn::RunOnExit<::vl::RemoveCVR<decltype(__vwsnb_0)>::Type> __vwsnb_0_dtor(&__vwsnb_0);
			try
			{
				{
					{
						auto __vwsnb_1 = [&]()
						{
							(GLOBAL_NAME sum = (GLOBAL_NAME sum + 1000));
						}
						;
						::vl::__vwsn::RunOnExit<::vl::RemoveCVR<decltype(__vwsnb_1)>::Type> __vwsnb_1_dtor(&__vwsnb_1);
						try
						{
							{
								{
									auto __vwsnb_2 = [&]()
									{
										(GLOBAL_NAME sum = (GLOBAL_NAME sum + 1000));
									}
									;
									::vl::__vwsn::RunOnExit<::vl::RemoveCVR<decltype(__vwsnb_2)>::Type> __vwsnb_2_dtor(&__vwsnb_2);
									try
									{
										{
											return;
										}
									}
									catch(const ::vl::Exception&)
									{
									}
									catch(const ::vl::Error&)
									{
									}
								}
							}
						}
						catch(const ::vl::Exception&)
						{
						}
						catch(const ::vl::Error&)
						{
						}
					}
				}
			}
			catch(const ::vl::Exception&)
			{
			}
			catch(const ::vl::Error&)
			{
			}
		}
	}

	::vl::WString TryFinally::main()
	{
		GLOBAL_NAME test1();
		GLOBAL_NAME test2();
		GLOBAL_NAME test3();
		GLOBAL_NAME test4();
		return ::vl::__vwsn::ToString(GLOBAL_NAME sum);
	}

	TryFinally& TryFinally::Instance()
	{
		return Getvl_workflow_global_TryFinally().instance;
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
