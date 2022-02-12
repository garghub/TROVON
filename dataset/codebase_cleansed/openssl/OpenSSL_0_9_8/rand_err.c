void ERR_load_RAND_strings(void)
{
static int init=1;
if (init)
{
init=0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(0,RAND_str_functs);
ERR_load_strings(0,RAND_str_reasons);
#endif
}
}
