/***********************************************************************
Generated from ../Resources/Codegen/AnonymousLambda.txt
***********************************************************************/

#include "AnonymousLambda.h"

/***********************************************************************
Global Variables and Functions
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_AnonymousLambda)
	vl_workflow_global::AnonymousLambda instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_AnonymousLambda)

namespace vl_workflow_global
{
	::vl::Func<::vl::Func<::vl::vint32_t()>(::vl::vint32_t)> AnonymousLambda::Adder(::vl::vint32_t x)
	{
		throw 0;
	}

	::vl::WString AnonymousLambda::main()
	{
		throw 0;
	}

	AnonymousLambda& AnonymousLambda::Instance()
	{
		return Getvl_workflow_global_AnonymousLambda().instance;
	}

	struct __vwsnf1_AnonymousLambda_Adder_
	{
		::vl::vint32_t x;

		__vwsnf1_AnonymousLambda_Adder_(::vl::vint32_t _x);

		::vl::Func<::vl::vint32_t()> operator()(::vl::vint32_t y) const;
	};

	struct __vwsnf2_AnonymousLambda_Adder__
	{
		::vl::vint32_t x;
		::vl::vint32_t y;

		__vwsnf2_AnonymousLambda_Adder__(::vl::vint32_t _x, ::vl::vint32_t _y);

		::vl::vint32_t operator()() const;
	};

	__vwsnf1_AnonymousLambda_Adder_::__vwsnf1_AnonymousLambda_Adder_(::vl::vint32_t _x)
		:x(_x)
	{
	}

	::vl::Func<::vl::vint32_t()> __vwsnf1_AnonymousLambda_Adder_::operator()(::vl::vint32_t y) const
	{
		throw 0;
	}

	__vwsnf2_AnonymousLambda_Adder__::__vwsnf2_AnonymousLambda_Adder__(::vl::vint32_t _x, ::vl::vint32_t _y)
		:x(_x)
		, y(_y)
	{
	}

	::vl::vint32_t __vwsnf2_AnonymousLambda_Adder__::operator()() const
	{
		throw 0;
	}
}

