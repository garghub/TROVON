DH *DH_generate_parameters(int prime_len, int generator,
void (*callback) (int, int, void *), void *cb_arg)
{
BN_GENCB cb;
DH *ret = NULL;
if ((ret = DH_new()) == NULL)
return NULL;
BN_GENCB_set_old(&cb, callback, cb_arg);
if (DH_generate_parameters_ex(ret, prime_len, generator, &cb))
return ret;
DH_free(ret);
return NULL;
}
