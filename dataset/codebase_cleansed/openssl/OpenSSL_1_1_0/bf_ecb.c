const char *BF_options(void)
{
return ("blowfish(ptr)");
}
void BF_ecb_encrypt(const unsigned char *in, unsigned char *out,
const BF_KEY *key, int encrypt)
{
BF_LONG l, d[2];
n2l(in, l);
d[0] = l;
n2l(in, l);
d[1] = l;
if (encrypt)
BF_encrypt(d, key);
else
BF_decrypt(d, key);
l = d[0];
l2n(l, out);
l = d[1];
l2n(l, out);
l = d[0] = d[1] = 0;
}
