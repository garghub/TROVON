static void ERR_load_DASYNC_strings(void)
{
if (DASYNC_lib_error_code == 0)
DASYNC_lib_error_code = ERR_get_next_error_library();
if (DASYNC_error_init) {
DASYNC_error_init = 0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(DASYNC_lib_error_code, DASYNC_str_functs);
ERR_load_strings(DASYNC_lib_error_code, DASYNC_str_reasons);
#endif
#ifdef DASYNC_LIB_NAME
DASYNC_lib_name->error = ERR_PACK(DASYNC_lib_error_code, 0, 0);
ERR_load_strings(0, DASYNC_lib_name);
#endif
}
}
static void ERR_unload_DASYNC_strings(void)
{
if (DASYNC_error_init == 0) {
#ifndef OPENSSL_NO_ERR
ERR_unload_strings(DASYNC_lib_error_code, DASYNC_str_functs);
ERR_unload_strings(DASYNC_lib_error_code, DASYNC_str_reasons);
#endif
#ifdef DASYNC_LIB_NAME
ERR_unload_strings(0, DASYNC_lib_name);
#endif
DASYNC_error_init = 1;
}
}
static void ERR_DASYNC_error(int function, int reason, char *file, int line)
{
if (DASYNC_lib_error_code == 0)
DASYNC_lib_error_code = ERR_get_next_error_library();
ERR_PUT_error(DASYNC_lib_error_code, function, reason, file, line);
}
