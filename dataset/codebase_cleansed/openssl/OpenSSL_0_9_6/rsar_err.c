void ERR_load_RSAREF_strings(void)
{
static int init=1;
if (init)
{
init=0;
#ifndef NO_ERR
ERR_load_strings(ERR_LIB_RSAREF,RSAREF_str_functs);
ERR_load_strings(ERR_LIB_RSAREF,RSAREF_str_reasons);
#endif
}
}
