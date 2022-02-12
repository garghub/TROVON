static void ERR_load_SUREWARE_strings(void)
{
if (SUREWARE_lib_error_code == 0)
SUREWARE_lib_error_code=ERR_get_next_error_library();
if (SUREWARE_error_init)
{
SUREWARE_error_init=0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(SUREWARE_lib_error_code,SUREWARE_str_functs);
ERR_load_strings(SUREWARE_lib_error_code,SUREWARE_str_reasons);
#endif
#ifdef SUREWARE_LIB_NAME
SUREWARE_lib_name->error = ERR_PACK(SUREWARE_lib_error_code,0,0);
ERR_load_strings(0,SUREWARE_lib_name);
#endif
}
}
static void ERR_unload_SUREWARE_strings(void)
{
if (SUREWARE_error_init == 0)
{
#ifndef OPENSSL_NO_ERR
ERR_unload_strings(SUREWARE_lib_error_code,SUREWARE_str_functs);
ERR_unload_strings(SUREWARE_lib_error_code,SUREWARE_str_reasons);
#endif
#ifdef SUREWARE_LIB_NAME
ERR_unload_strings(0,SUREWARE_lib_name);
#endif
SUREWARE_error_init=1;
}
}
static void ERR_SUREWARE_error(int function, int reason, char *file, int line)
{
if (SUREWARE_lib_error_code == 0)
SUREWARE_lib_error_code=ERR_get_next_error_library();
ERR_PUT_error(SUREWARE_lib_error_code,function,reason,file,line);
}
