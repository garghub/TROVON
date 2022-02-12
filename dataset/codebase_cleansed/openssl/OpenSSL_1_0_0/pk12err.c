void ERR_load_PKCS12_strings(void)
{
#ifndef OPENSSL_NO_ERR
if (ERR_func_error_string(PKCS12_str_functs[0].error) == NULL)
{
ERR_load_strings(0,PKCS12_str_functs);
ERR_load_strings(0,PKCS12_str_reasons);
}
#endif
}
