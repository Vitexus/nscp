IF(NOT WIN32)
	SET (BUILD_MODULE 1)
ELSE()
	SET(BUILD_MODULE_SKIP_REASON "Not supported on Windows")
ENDIF()
