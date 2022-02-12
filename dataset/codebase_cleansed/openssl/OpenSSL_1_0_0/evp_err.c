void ERR_load_EVP_strings(void)
{
#ifndef OPENSSL_NO_ERR
if (ERR_func_error_string(EVP_str_functs[0].error) == NULL)
{
ERR_load_strings(0,EVP_str_functs);
ERR_load_strings(0,EVP_str_reasons);
}
#endif
}
