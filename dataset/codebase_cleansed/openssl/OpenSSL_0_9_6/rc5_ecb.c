void RC5_32_ecb_encrypt(const unsigned char *in, unsigned char *out,
RC5_32_KEY *ks, int encrypt)
{
unsigned long l,d[2];
c2l(in,l); d[0]=l;
c2l(in,l); d[1]=l;
if (encrypt)
RC5_32_encrypt(d,ks);
else
RC5_32_decrypt(d,ks);
l=d[0]; l2c(l,out);
l=d[1]; l2c(l,out);
l=d[0]=d[1]=0;
}
