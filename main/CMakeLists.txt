idf_component_register(SRCS "hello_world_main.c" "oleddrive.c"
                    INCLUDE_DIRS "")

# target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format")
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-error=missing-braces)
# -Wno-error=missing-braces