static void ERR_load_CCA4758_strings(void)
{
if (CCA4758_lib_error_code == 0)
CCA4758_lib_error_code = ERR_get_next_error_library();
if (CCA4758_error_init) {
CCA4758_error_init = 0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(CCA4758_lib_error_code, CCA4758_str_functs);
ERR_load_strings(CCA4758_lib_error_code, CCA4758_str_reasons);
#endif
#ifdef CCA4758_LIB_NAME
CCA4758_lib_name->error = ERR_PACK(CCA4758_lib_error_code, 0, 0);
ERR_load_strings(0, CCA4758_lib_name);
#endif
}
}
static void ERR_unload_CCA4758_strings(void)
{
if (CCA4758_error_init == 0) {
#ifndef OPENSSL_NO_ERR
ERR_unload_strings(CCA4758_lib_error_code, CCA4758_str_functs);
ERR_unload_strings(CCA4758_lib_error_code, CCA4758_str_reasons);
#endif
#ifdef CCA4758_LIB_NAME
ERR_unload_strings(0, CCA4758_lib_name);
#endif
CCA4758_error_init = 1;
}
}
static void ERR_CCA4758_error(int function, int reason, char *file, int line)
{
if (CCA4758_lib_error_code == 0)
CCA4758_lib_error_code = ERR_get_next_error_library();
ERR_PUT_error(CCA4758_lib_error_code, function, reason, file, line);
}
