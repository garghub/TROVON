void ERR_load_RSA_strings(void)
{
static int init=1;
if (init)
{
init=0;
#ifndef NO_ERR
ERR_load_strings(ERR_LIB_RSA,RSA_str_functs);
ERR_load_strings(ERR_LIB_RSA,RSA_str_reasons);
#endif
}
}
