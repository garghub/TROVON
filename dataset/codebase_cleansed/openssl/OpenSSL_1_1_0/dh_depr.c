NON_EMPTY_TRANSLATION_UNIT
#else
# include <stdio.h>
# include "internal/cryptlib.h"
# include <openssl/bn.h>
# include <openssl/dh.h>
DH *DH_generate_parameters(int prime_len, int generator,
void (*callback) (int, int, void *), void *cb_arg)
{
BN_GENCB *cb;
DH *ret = NULL;
if ((ret = DH_new()) == NULL)
return NULL;
cb = BN_GENCB_new();
if (cb == NULL) {
DH_free(ret);
return NULL;
}
BN_GENCB_set_old(cb, callback, cb_arg);
if (DH_generate_parameters_ex(ret, prime_len, generator, cb)) {
BN_GENCB_free(cb);
return ret;
}
BN_GENCB_free(cb);
DH_free(ret);
return NULL;
}
