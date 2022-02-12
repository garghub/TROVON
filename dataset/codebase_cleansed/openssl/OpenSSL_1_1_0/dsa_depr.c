NON_EMPTY_TRANSLATION_UNIT
#else
# include <stdio.h>
# include <time.h>
# include "internal/cryptlib.h"
# include <openssl/evp.h>
# include <openssl/bn.h>
# include <openssl/dsa.h>
# include <openssl/sha.h>
DSA *DSA_generate_parameters(int bits,
unsigned char *seed_in, int seed_len,
int *counter_ret, unsigned long *h_ret,
void (*callback) (int, int, void *),
void *cb_arg)
{
BN_GENCB *cb;
DSA *ret;
if ((ret = DSA_new()) == NULL)
return NULL;
cb = BN_GENCB_new();
if (cb == NULL)
goto err;
BN_GENCB_set_old(cb, callback, cb_arg);
if (DSA_generate_parameters_ex(ret, bits, seed_in, seed_len,
counter_ret, h_ret, cb)) {
BN_GENCB_free(cb);
return ret;
}
BN_GENCB_free(cb);
err:
DSA_free(ret);
return NULL;
}
