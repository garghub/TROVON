NON_EMPTY_TRANSLATION_UNIT
#else
# include <stdio.h>
# include <time.h>
# include "internal/cryptlib.h"
# include <openssl/bn.h>
# include <openssl/rsa.h>
RSA *RSA_generate_key(int bits, unsigned long e_value,
void (*callback) (int, int, void *), void *cb_arg)
{
int i;
BN_GENCB *cb = BN_GENCB_new();
RSA *rsa = RSA_new();
BIGNUM *e = BN_new();
if (cb == NULL || rsa == NULL || e == NULL)
goto err;
for (i = 0; i < (int)sizeof(unsigned long) * 8; i++) {
if (e_value & (1UL << i))
if (BN_set_bit(e, i) == 0)
goto err;
}
BN_GENCB_set_old(cb, callback, cb_arg);
if (RSA_generate_key_ex(rsa, bits, e, cb)) {
BN_free(e);
BN_GENCB_free(cb);
return rsa;
}
err:
BN_free(e);
RSA_free(rsa);
BN_GENCB_free(cb);
return 0;
}
