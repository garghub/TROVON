void DES_ecb3_encrypt(const_DES_cblock *input, DES_cblock *output,
DES_key_schedule *ks1, DES_key_schedule *ks2,
DES_key_schedule *ks3, int enc)
{
register DES_LONG l0, l1;
DES_LONG ll[2];
const unsigned char *in = &(*input)[0];
unsigned char *out = &(*output)[0];
c2l(in, l0);
c2l(in, l1);
ll[0] = l0;
ll[1] = l1;
if (enc)
DES_encrypt3(ll, ks1, ks2, ks3);
else
DES_decrypt3(ll, ks1, ks2, ks3);
l0 = ll[0];
l1 = ll[1];
l2c(l0, out);
l2c(l1, out);
}
