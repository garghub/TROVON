void CAST_ecb_encrypt(const unsigned char *in, unsigned char *out,
const CAST_KEY *ks, int enc)
{
CAST_LONG l,d[2];
n2l(in,l); d[0]=l;
n2l(in,l); d[1]=l;
if (enc)
CAST_encrypt(d,ks);
else
CAST_decrypt(d,ks);
l=d[0]; l2n(l,out);
l=d[1]; l2n(l,out);
l=d[0]=d[1]=0;
}
