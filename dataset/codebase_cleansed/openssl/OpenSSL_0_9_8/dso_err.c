void ERR_load_DSO_strings(void)
{
static int init=1;
if (init)
{
init=0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(0,DSO_str_functs);
ERR_load_strings(0,DSO_str_reasons);
#endif
}
}
