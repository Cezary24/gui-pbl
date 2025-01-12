# Add set(CONFIG_USE_middleware_freertos-kernel true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if(CONFIG_USE_middleware_freertos-kernel_template AND CONFIG_USE_middleware_freertos-kernel_extension)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
${CMAKE_CURRENT_LIST_DIR}/croutine.c
${CMAKE_CURRENT_LIST_DIR}/event_groups.c
${CMAKE_CURRENT_LIST_DIR}/list.c
${CMAKE_CURRENT_LIST_DIR}/queue.c
${CMAKE_CURRENT_LIST_DIR}/stream_buffer.c
${CMAKE_CURRENT_LIST_DIR}/tasks.c
${CMAKE_CURRENT_LIST_DIR}/timers.c
)

if((CONFIG_COMPILER STREQUAL armclang OR CONFIG_COMPILER STREQUAL gcc) AND CONFIG_CORE STREQUAL cm0p AND (CONFIG_TOOLCHAIN STREQUAL armgcc OR CONFIG_TOOLCHAIN STREQUAL mcux OR CONFIG_TOOLCHAIN STREQUAL mdk))
target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
#      ${CMAKE_CURRENT_LIST_DIR}/portable/GCC/ARM_CM0/port.c
)
endif()

if((CONFIG_COMPILER STREQUAL armclang OR CONFIG_COMPILER STREQUAL gcc) AND (CONFIG_CORE STREQUAL cm4f OR CONFIG_CORE STREQUAL cm7f) AND (CONFIG_TOOLCHAIN STREQUAL armgcc OR CONFIG_TOOLCHAIN STREQUAL mcux OR CONFIG_TOOLCHAIN STREQUAL mdk))
target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
#      ${CMAKE_CURRENT_LIST_DIR}/portable/GCC/ARM_CM4F/port.c
)
endif()

if(CONFIG_CORE STREQUAL cm0p AND CONFIG_TOOLCHAIN STREQUAL iar)
target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
#      ${CMAKE_CURRENT_LIST_DIR}/portable/IAR/ARM_CM0/port.c
#      ${CMAKE_CURRENT_LIST_DIR}/portable/IAR/ARM_CM0/portasm.s
)
endif()

if((CONFIG_CORE STREQUAL cm4f OR CONFIG_CORE STREQUAL cm7f) AND CONFIG_TOOLCHAIN STREQUAL iar)
target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
#      ${CMAKE_CURRENT_LIST_DIR}/portable/IAR/ARM_CM4F/port.c
#      ${CMAKE_CURRENT_LIST_DIR}/portable/IAR/ARM_CM4F/portasm.s
)
endif()

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
${CMAKE_CURRENT_LIST_DIR}/include
)

if((CONFIG_COMPILER STREQUAL armclang OR CONFIG_COMPILER STREQUAL gcc) AND CONFIG_CORE STREQUAL cm0p AND (CONFIG_TOOLCHAIN STREQUAL armgcc OR CONFIG_TOOLCHAIN STREQUAL mcux OR CONFIG_TOOLCHAIN STREQUAL mdk))
target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
${CMAKE_CURRENT_LIST_DIR}/include
)
endif()

if((CONFIG_COMPILER STREQUAL armclang OR CONFIG_COMPILER STREQUAL gcc) AND (CONFIG_CORE STREQUAL cm4f OR CONFIG_CORE STREQUAL cm7f) AND (CONFIG_TOOLCHAIN STREQUAL armgcc OR CONFIG_TOOLCHAIN STREQUAL mcux OR CONFIG_TOOLCHAIN STREQUAL mdk))
target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
${CMAKE_CURRENT_LIST_DIR}/include
)
endif()

if(CONFIG_CORE STREQUAL cm0p AND CONFIG_TOOLCHAIN STREQUAL iar)
target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
${CMAKE_CURRENT_LIST_DIR}/include
)
endif()

if((CONFIG_CORE STREQUAL cm4f OR CONFIG_CORE STREQUAL cm7f) AND CONFIG_TOOLCHAIN STREQUAL iar)
target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
${CMAKE_CURRENT_LIST_DIR}/include
)
endif()

if(CONFIG_USE_COMPONENT_CONFIGURATION)
message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
-DSDK_OS_FREE_RTOS
)

endif()

else()

message(SEND_ERROR "middleware_freertos-kernel dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()
