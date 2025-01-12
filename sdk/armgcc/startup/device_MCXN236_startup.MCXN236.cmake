# Add set(CONFIG_USE_device_MCXN236_startup true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if(CONFIG_USE_device_MCXN236_system)

if(CONFIG_TOOLCHAIN STREQUAL iar)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/iar/startup_MCXN236.s "" device_MCXN236_startup.MCXN236)
endif()

if(CONFIG_TOOLCHAIN STREQUAL armgcc)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/startup_MCXN236.S "" device_MCXN236_startup.MCXN236)
endif()

if(CONFIG_TOOLCHAIN STREQUAL mdk)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/arm/startup_MCXN236.S "" device_MCXN236_startup.MCXN236)
endif()

if(CONFIG_TOOLCHAIN STREQUAL mcux)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/mcuxpresso/startup_mcxn236.c "" device_MCXN236_startup.MCXN236)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/mcuxpresso/startup_mcxn236.cpp "" device_MCXN236_startup.MCXN236)
endif()

else()

message(SEND_ERROR "device_MCXN236_startup.MCXN236 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()
