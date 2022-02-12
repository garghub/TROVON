void ERR_load_ECDH_strings(void)
{
#ifndef OPENSSL_NO_ERR
if (ERR_func_error_string(ECDH_str_functs[0].error) == NULL)
{
ERR_load_strings(0,ECDH_str_functs);
ERR_load_strings(0,ECDH_str_reasons);
}
#endif
}
