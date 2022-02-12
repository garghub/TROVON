static void ERR_load_ATALLA_strings(void)
{
if (ATALLA_lib_error_code == 0)
ATALLA_lib_error_code=ERR_get_next_error_library();
if (ATALLA_error_init)
{
ATALLA_error_init=0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(ATALLA_lib_error_code,ATALLA_str_functs);
ERR_load_strings(ATALLA_lib_error_code,ATALLA_str_reasons);
#endif
#ifdef ATALLA_LIB_NAME
ATALLA_lib_name->error = ERR_PACK(ATALLA_lib_error_code,0,0);
ERR_load_strings(0,ATALLA_lib_name);
#endif
}
}
static void ERR_unload_ATALLA_strings(void)
{
if (ATALLA_error_init == 0)
{
#ifndef OPENSSL_NO_ERR
ERR_unload_strings(ATALLA_lib_error_code,ATALLA_str_functs);
ERR_unload_strings(ATALLA_lib_error_code,ATALLA_str_reasons);
#endif
#ifdef ATALLA_LIB_NAME
ERR_unload_strings(0,ATALLA_lib_name);
#endif
ATALLA_error_init=1;
}
}
static void ERR_ATALLA_error(int function, int reason, char *file, int line)
{
if (ATALLA_lib_error_code == 0)
ATALLA_lib_error_code=ERR_get_next_error_library();
ERR_PUT_error(ATALLA_lib_error_code,function,reason,file,line);
}
