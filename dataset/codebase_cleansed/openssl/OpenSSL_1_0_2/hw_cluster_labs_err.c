static void ERR_load_CL_strings(void)
{
if (CL_lib_error_code == 0)
CL_lib_error_code = ERR_get_next_error_library();
if (CL_error_init) {
CL_error_init = 0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(CL_lib_error_code, CL_str_functs);
ERR_load_strings(CL_lib_error_code, CL_str_reasons);
#endif
#ifdef CL_LIB_NAME
CL_lib_name->error = ERR_PACK(CL_lib_error_code, 0, 0);
ERR_load_strings(0, CL_lib_name);
#endif
}
}
static void ERR_unload_CL_strings(void)
{
if (CL_error_init == 0) {
#ifndef OPENSSL_NO_ERR
ERR_unload_strings(CL_lib_error_code, CL_str_functs);
ERR_unload_strings(CL_lib_error_code, CL_str_reasons);
#endif
#ifdef CL_LIB_NAME
ERR_unload_strings(0, CL_lib_name);
#endif
CL_error_init = 1;
}
}
static void ERR_CL_error(int function, int reason, char *file, int line)
{
if (CL_lib_error_code == 0)
CL_lib_error_code = ERR_get_next_error_library();
ERR_PUT_error(CL_lib_error_code, function, reason, file, line);
}
