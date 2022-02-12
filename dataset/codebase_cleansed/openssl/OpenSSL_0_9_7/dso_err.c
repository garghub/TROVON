void ERR_load_DSO_strings(void)
{
static int init=1;
if (init)
{
init=0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(ERR_LIB_DSO,DSO_str_functs);
ERR_load_strings(ERR_LIB_DSO,DSO_str_reasons);
#endif
}
}
