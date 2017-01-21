/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/BindCustomInterface2.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#ifndef VCZH_WORKFLOW_COMPILER_GENERATED_BINDCUSTOMINTERFACE2
#define VCZH_WORKFLOW_COMPILER_GENERATED_BINDCUSTOMINTERFACE2

#include "../Source/CppTypes.h"

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses-equality"
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#endif

#pragma warning(push)
#pragma warning(disable:4250)
class ISummer2;
class IAdder2;

class ISummer2 : public virtual ::vl::reflection::IDescriptable, public ::vl::reflection::Description<ISummer2>
{
public:

	virtual ::vl::vint32_t GetSum() = 0;
	::vl::Event<void()> SumChanged;
};

class IAdder2 : public virtual ::ISummer2, public ::vl::reflection::Description<IAdder2>
{
public:

	virtual void Add(::vl::vint32_t value) = 0;
};
#pragma warning(pop)

/***********************************************************************
Global Variables and Functions
***********************************************************************/

namespace vl_workflow_global
{
	class BindCustomInterface2
	{
	public:

		::vl::WString s;

		::vl::Ptr<::vl::reflection::description::IValueSubscription> Bind(::vl::Ptr<::ISummer2> summer);
		void Execute(::vl::Ptr<::IAdder2> adder);
		::vl::WString main();

		static BindCustomInterface2& Instance();
	};
}

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
			DECL_TYPE_INFO(::IAdder2)
			DECL_TYPE_INFO(::ISummer2)
#pragma warning(push)
#pragma warning(disable:4250)

			BEGIN_INTERFACE_PROXY_NOPARENT_SHAREDPTR(::ISummer2)
				::vl::vint32_t GetSum() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetSum);
				}
			END_INTERFACE_PROXY(::ISummer2)

			BEGIN_INTERFACE_PROXY_SHAREDPTR(::IAdder2, ::ISummer2)
				void Add(::vl::vint32_t value) override
				{
					INVOKE_INTERFACE_PROXY(Add, value);
				}
			END_INTERFACE_PROXY(::IAdder2)
#pragma warning(pop)
#endif

			extern bool LoadBindCustomInterface2Types();
		}
	}
}

#endif
