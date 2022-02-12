void ERR_load_X509V3_strings(void)
{
#ifndef OPENSSL_NO_ERR
if (ERR_func_error_string(X509V3_str_functs[0].error) == NULL)
{
ERR_load_strings(0,X509V3_str_functs);
ERR_load_strings(0,X509V3_str_reasons);
}
#endif
}
