void ERR_load_ECDSA_strings(void)
{
static int init=1;
if (init)
{
init=0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(0,ECDSA_str_functs);
ERR_load_strings(0,ECDSA_str_reasons);
#endif
}
}
