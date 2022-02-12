void ERR_load_PKCS12_strings(void)
{
static int init=1;
if (init)
{
init=0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(ERR_LIB_PKCS12,PKCS12_str_functs);
ERR_load_strings(ERR_LIB_PKCS12,PKCS12_str_reasons);
#endif
}
}
