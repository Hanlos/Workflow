/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/StructCtor2.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#ifndef VCZH_WORKFLOW_COMPILER_GENERATED_STRUCTCTOR2
#define VCZH_WORKFLOW_COMPILER_GENERATED_STRUCTCTOR2

#include "../Source/CppTypes.h"

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

struct Point
{
	::vl::vint32_t x = 0;
	::vl::vint32_t y = 0;
	::vl::Nullable<::Point> z;
};
inline bool operator== (const Point& a, const Point& b)
{
	if (a.x != b.x) return false;
	if (a.y != b.y) return false;
	if (a.z != b.z) return false;
	return true;
}
inline bool operator!= (const Point& a, const Point& b)
{
	if (a.x != b.x) return true;
	if (a.y != b.y) return true;
	if (a.z != b.z) return true;
	return false;
}

/***********************************************************************
Global Variables and Functions
***********************************************************************/

namespace vl_workflow_global
{
	class StructCtor2
	{
	public:

		::vl::vint32_t Do(::Point p);
		::vl::WString main();

		static StructCtor2& Instance();
	};
}

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
			DECL_TYPE_INFO(::Point)
#endif

			extern bool LoadStructCtor2Types();
		}
	}
}

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif
