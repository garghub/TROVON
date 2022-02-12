void RC2_ecb_encrypt(unsigned char *in, unsigned char *out, RC2_KEY *ks,
int encrypt)
{
unsigned long l,d[2];
c2l(in,l); d[0]=l;
c2l(in,l); d[1]=l;
if (encrypt)
RC2_encrypt(d,ks);
else
RC2_decrypt(d,ks);
l=d[0]; l2c(l,out);
l=d[1]; l2c(l,out);
l=d[0]=d[1]=0;
}
