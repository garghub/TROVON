static void ERR_load_HWCRHK_strings(void)
{
if (HWCRHK_lib_error_code == 0)
HWCRHK_lib_error_code=ERR_get_next_error_library();
if (HWCRHK_error_init)
{
HWCRHK_error_init=0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(HWCRHK_lib_error_code,HWCRHK_str_functs);
ERR_load_strings(HWCRHK_lib_error_code,HWCRHK_str_reasons);
#endif
#ifdef HWCRHK_LIB_NAME
HWCRHK_lib_name->error = ERR_PACK(HWCRHK_lib_error_code,0,0);
ERR_load_strings(0,HWCRHK_lib_name);
#endif
}
}
static void ERR_unload_HWCRHK_strings(void)
{
if (HWCRHK_error_init == 0)
{
#ifndef OPENSSL_NO_ERR
ERR_unload_strings(HWCRHK_lib_error_code,HWCRHK_str_functs);
ERR_unload_strings(HWCRHK_lib_error_code,HWCRHK_str_reasons);
#endif
#ifdef HWCRHK_LIB_NAME
ERR_unload_strings(0,HWCRHK_lib_name);
#endif
HWCRHK_error_init=1;
}
}
static void ERR_HWCRHK_error(int function, int reason, char *file, int line)
{
if (HWCRHK_lib_error_code == 0)
HWCRHK_lib_error_code=ERR_get_next_error_library();
ERR_PUT_error(HWCRHK_lib_error_code,function,reason,file,line);
}
