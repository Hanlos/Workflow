/***********************************************************************
Generated from ../Resources/Codegen/BindFormat.txt
***********************************************************************/

#include "BindFormat.h"

/***********************************************************************
Global Variables and Functions
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_BindFormat)
	vl_workflow_global::BindFormat instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS

		instance.s = L"";
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_BindFormat)

namespace vl_workflow_global
{
	void BindFormat::Callback(::vl::reflection::description::Value value)
	{
		throw 0;
	}

	::vl::WString BindFormat::main()
	{
		throw 0;
	}

	BindFormat& BindFormat::Instance()
	{
		return Getvl_workflow_global_BindFormat().instance;
	}

	class __vwsnc1_BindFormat_main__vl_reflection_description_IValueSubscription : public ::vl::Object, public virtual ::vl::reflection::description::IValueSubscription
	{
	public:
		::vl::Ptr<::test::ObservableValue> x;

		__vwsnc1_BindFormat_main__vl_reflection_description_IValueSubscription(::vl::Ptr<::test::ObservableValue> __vwsnctor_x);

		::vl::Ptr<::test::ObservableValue> __vwsn_bind_cache_1;
		::vl::Ptr<::vl::reflection::description::IEventHandler> __vwsn_bind_handler_1_0;
		bool __vwsn_bind_opened_ = false;
		bool __vwsn_bind_closed_ = false;
		::vl::Ptr<::vl::reflection::description::IValueDictionary> __vwsn_bind_listeners_;
		void __vwsn_bind_activator_();
		void __vwsn_bind_callback_1_0(::vl::vint32_t __vwsn_bind_callback_argument_0, ::vl::vint32_t __vwsn_bind_callback_argument_1);
		void __vwsn_bind_initialize_();
		::vl::Ptr<::vl::reflection::description::IValueListener> Subscribe(const ::vl::Func<void(::vl::reflection::description::Value)>& callback) override;
		bool Update() override;
		bool Close() override;
	};

	class __vwsnc2_BindFormat_main_Subscribe__vl_reflection_description_IValueListener : public ::vl::Object, public virtual ::vl::reflection::description::IValueListener
	{
	public:
		::vl::Ptr<::vl::reflection::description::IValueDictionary> __vwsn_bind_listeners_;
		::vl::reflection::description::IValueSubscription* __vwsn_subscription_;
		::vl::reflection::description::IValueSubscription* __vwsnthis_0;

		__vwsnc2_BindFormat_main_Subscribe__vl_reflection_description_IValueListener(::vl::Ptr<::vl::reflection::description::IValueDictionary> __vwsnctor___vwsn_bind_listeners_, ::vl::reflection::description::IValueSubscription* __vwsnctor___vwsn_subscription_, ::vl::reflection::description::IValueSubscription* __vwsnctorthis_0);

		::vl::reflection::description::IValueSubscription* GetSubscription() override;
		bool GetStopped() override;
		bool StopListening() override;
	};

	__vwsnc1_BindFormat_main__vl_reflection_description_IValueSubscription::__vwsnc1_BindFormat_main__vl_reflection_description_IValueSubscription(::vl::Ptr<::test::ObservableValue> __vwsnctor_x)
		:x(__vwsnctor_x)
	{
	}

	void __vwsnc1_BindFormat_main__vl_reflection_description_IValueSubscription::__vwsn_bind_activator_()
	{
		throw 0;
	}

	void __vwsnc1_BindFormat_main__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_1_0(::vl::vint32_t __vwsn_bind_callback_argument_0, ::vl::vint32_t __vwsn_bind_callback_argument_1)
	{
		throw 0;
	}

	void __vwsnc1_BindFormat_main__vl_reflection_description_IValueSubscription::__vwsn_bind_initialize_()
	{
		throw 0;
	}

	::vl::Ptr<::vl::reflection::description::IValueListener> __vwsnc1_BindFormat_main__vl_reflection_description_IValueSubscription::Subscribe(const ::vl::Func<void(::vl::reflection::description::Value)>& callback)
	{
		throw 0;
	}

	bool __vwsnc1_BindFormat_main__vl_reflection_description_IValueSubscription::Update()
	{
		throw 0;
	}

	bool __vwsnc1_BindFormat_main__vl_reflection_description_IValueSubscription::Close()
	{
		throw 0;
	}

	__vwsnc2_BindFormat_main_Subscribe__vl_reflection_description_IValueListener::__vwsnc2_BindFormat_main_Subscribe__vl_reflection_description_IValueListener(::vl::Ptr<::vl::reflection::description::IValueDictionary> __vwsnctor___vwsn_bind_listeners_, ::vl::reflection::description::IValueSubscription* __vwsnctor___vwsn_subscription_, ::vl::reflection::description::IValueSubscription* __vwsnctorthis_0)
		:__vwsn_bind_listeners_(__vwsnctor___vwsn_bind_listeners_)
		, __vwsn_subscription_(__vwsnctor___vwsn_subscription_)
		, __vwsnthis_0(__vwsnctorthis_0)
	{
	}

	::vl::reflection::description::IValueSubscription* __vwsnc2_BindFormat_main_Subscribe__vl_reflection_description_IValueListener::GetSubscription()
	{
		throw 0;
	}

	bool __vwsnc2_BindFormat_main_Subscribe__vl_reflection_description_IValueListener::GetStopped()
	{
		throw 0;
	}

	bool __vwsnc2_BindFormat_main_Subscribe__vl_reflection_description_IValueListener::StopListening()
	{
		throw 0;
	}

}

