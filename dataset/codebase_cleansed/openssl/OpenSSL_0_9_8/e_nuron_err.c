static void ERR_load_NURON_strings(void)
{
if (NURON_lib_error_code == 0)
NURON_lib_error_code=ERR_get_next_error_library();
if (NURON_error_init)
{
NURON_error_init=0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(NURON_lib_error_code,NURON_str_functs);
ERR_load_strings(NURON_lib_error_code,NURON_str_reasons);
#endif
#ifdef NURON_LIB_NAME
NURON_lib_name->error = ERR_PACK(NURON_lib_error_code,0,0);
ERR_load_strings(0,NURON_lib_name);
#endif
}
}
static void ERR_unload_NURON_strings(void)
{
if (NURON_error_init == 0)
{
#ifndef OPENSSL_NO_ERR
ERR_unload_strings(NURON_lib_error_code,NURON_str_functs);
ERR_unload_strings(NURON_lib_error_code,NURON_str_reasons);
#endif
#ifdef NURON_LIB_NAME
ERR_unload_strings(0,NURON_lib_name);
#endif
NURON_error_init=1;
}
}
static void ERR_NURON_error(int function, int reason, char *file, int line)
{
if (NURON_lib_error_code == 0)
NURON_lib_error_code=ERR_get_next_error_library();
ERR_PUT_error(NURON_lib_error_code,function,reason,file,line);
}
