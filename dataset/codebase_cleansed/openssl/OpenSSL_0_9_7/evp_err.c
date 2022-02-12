void ERR_load_EVP_strings(void)
{
static int init=1;
if (init)
{
init=0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(ERR_LIB_EVP,EVP_str_functs);
ERR_load_strings(ERR_LIB_EVP,EVP_str_reasons);
#endif
}
}
