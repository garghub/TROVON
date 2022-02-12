void des_encrypt(DES_LONG *data, des_key_schedule ks, int enc)
{
register DES_LONG l,r,t,u;
#ifdef DES_PTR
register const unsigned char *des_SP=(const unsigned char *)des_SPtrans;
#endif
#ifndef DES_UNROLL
register int i;
#endif
register DES_LONG *s;
r=data[0];
l=data[1];
IP(r,l);
r=ROTATE(r,29)&0xffffffffL;
l=ROTATE(l,29)&0xffffffffL;
s=ks->ks.deslong;
if (enc)
{
#ifdef DES_UNROLL
D_ENCRYPT(l,r, 0);
D_ENCRYPT(r,l, 2);
D_ENCRYPT(l,r, 4);
D_ENCRYPT(r,l, 6);
D_ENCRYPT(l,r, 8);
D_ENCRYPT(r,l,10);
D_ENCRYPT(l,r,12);
D_ENCRYPT(r,l,14);
D_ENCRYPT(l,r,16);
D_ENCRYPT(r,l,18);
D_ENCRYPT(l,r,20);
D_ENCRYPT(r,l,22);
D_ENCRYPT(l,r,24);
D_ENCRYPT(r,l,26);
D_ENCRYPT(l,r,28);
D_ENCRYPT(r,l,30);
#else
for (i=0; i<32; i+=8)
{
D_ENCRYPT(l,r,i+0);
D_ENCRYPT(r,l,i+2);
D_ENCRYPT(l,r,i+4);
D_ENCRYPT(r,l,i+6);
}
#endif
}
else
{
#ifdef DES_UNROLL
D_ENCRYPT(l,r,30);
D_ENCRYPT(r,l,28);
D_ENCRYPT(l,r,26);
D_ENCRYPT(r,l,24);
D_ENCRYPT(l,r,22);
D_ENCRYPT(r,l,20);
D_ENCRYPT(l,r,18);
D_ENCRYPT(r,l,16);
D_ENCRYPT(l,r,14);
D_ENCRYPT(r,l,12);
D_ENCRYPT(l,r,10);
D_ENCRYPT(r,l, 8);
D_ENCRYPT(l,r, 6);
D_ENCRYPT(r,l, 4);
D_ENCRYPT(l,r, 2);
D_ENCRYPT(r,l, 0);
#else
for (i=30; i>0; i-=8)
{
D_ENCRYPT(l,r,i-0);
D_ENCRYPT(r,l,i-2);
D_ENCRYPT(l,r,i-4);
D_ENCRYPT(r,l,i-6);
}
#endif
}
l=ROTATE(l,3)&0xffffffffL;
r=ROTATE(r,3)&0xffffffffL;
FP(r,l);
data[0]=l;
data[1]=r;
l=r=t=u=0;
}
void des_encrypt2(DES_LONG *data, des_key_schedule ks, int enc)
{
register DES_LONG l,r,t,u;
#ifdef DES_PTR
register const unsigned char *des_SP=(const unsigned char *)des_SPtrans;
#endif
#ifndef DES_UNROLL
register int i;
#endif
register DES_LONG *s;
r=data[0];
l=data[1];
r=ROTATE(r,29)&0xffffffffL;
l=ROTATE(l,29)&0xffffffffL;
s=ks->ks.deslong;
if (enc)
{
#ifdef DES_UNROLL
D_ENCRYPT(l,r, 0);
D_ENCRYPT(r,l, 2);
D_ENCRYPT(l,r, 4);
D_ENCRYPT(r,l, 6);
D_ENCRYPT(l,r, 8);
D_ENCRYPT(r,l,10);
D_ENCRYPT(l,r,12);
D_ENCRYPT(r,l,14);
D_ENCRYPT(l,r,16);
D_ENCRYPT(r,l,18);
D_ENCRYPT(l,r,20);
D_ENCRYPT(r,l,22);
D_ENCRYPT(l,r,24);
D_ENCRYPT(r,l,26);
D_ENCRYPT(l,r,28);
D_ENCRYPT(r,l,30);
#else
for (i=0; i<32; i+=8)
{
D_ENCRYPT(l,r,i+0);
D_ENCRYPT(r,l,i+2);
D_ENCRYPT(l,r,i+4);
D_ENCRYPT(r,l,i+6);
}
#endif
}
else
{
#ifdef DES_UNROLL
D_ENCRYPT(l,r,30);
D_ENCRYPT(r,l,28);
D_ENCRYPT(l,r,26);
D_ENCRYPT(r,l,24);
D_ENCRYPT(l,r,22);
D_ENCRYPT(r,l,20);
D_ENCRYPT(l,r,18);
D_ENCRYPT(r,l,16);
D_ENCRYPT(l,r,14);
D_ENCRYPT(r,l,12);
D_ENCRYPT(l,r,10);
D_ENCRYPT(r,l, 8);
D_ENCRYPT(l,r, 6);
D_ENCRYPT(r,l, 4);
D_ENCRYPT(l,r, 2);
D_ENCRYPT(r,l, 0);
#else
for (i=30; i>0; i-=8)
{
D_ENCRYPT(l,r,i-0);
D_ENCRYPT(r,l,i-2);
D_ENCRYPT(l,r,i-4);
D_ENCRYPT(r,l,i-6);
}
#endif
}
data[0]=ROTATE(l,3)&0xffffffffL;
data[1]=ROTATE(r,3)&0xffffffffL;
l=r=t=u=0;
}
void des_encrypt3(DES_LONG *data, des_key_schedule ks1, des_key_schedule ks2,
des_key_schedule ks3)
{
register DES_LONG l,r;
l=data[0];
r=data[1];
IP(l,r);
data[0]=l;
data[1]=r;
des_encrypt2((DES_LONG *)data,ks1,DES_ENCRYPT);
des_encrypt2((DES_LONG *)data,ks2,DES_DECRYPT);
des_encrypt2((DES_LONG *)data,ks3,DES_ENCRYPT);
l=data[0];
r=data[1];
FP(r,l);
data[0]=l;
data[1]=r;
}
void des_decrypt3(DES_LONG *data, des_key_schedule ks1, des_key_schedule ks2,
des_key_schedule ks3)
{
register DES_LONG l,r;
l=data[0];
r=data[1];
IP(l,r);
data[0]=l;
data[1]=r;
des_encrypt2((DES_LONG *)data,ks3,DES_DECRYPT);
des_encrypt2((DES_LONG *)data,ks2,DES_ENCRYPT);
des_encrypt2((DES_LONG *)data,ks1,DES_DECRYPT);
l=data[0];
r=data[1];
FP(r,l);
data[0]=l;
data[1]=r;
}
void des_ede3_cbc_encrypt(const unsigned char *input, unsigned char *output,
long length, des_key_schedule ks1, des_key_schedule ks2,
des_key_schedule ks3, des_cblock *ivec, int enc)
{
register DES_LONG tin0,tin1;
register DES_LONG tout0,tout1,xor0,xor1;
register const unsigned char *in;
unsigned char *out;
register long l=length;
DES_LONG tin[2];
unsigned char *iv;
in=input;
out=output;
iv = &(*ivec)[0];
if (enc)
{
c2l(iv,tout0);
c2l(iv,tout1);
for (l-=8; l>=0; l-=8)
{
c2l(in,tin0);
c2l(in,tin1);
tin0^=tout0;
tin1^=tout1;
tin[0]=tin0;
tin[1]=tin1;
des_encrypt3((DES_LONG *)tin,ks1,ks2,ks3);
tout0=tin[0];
tout1=tin[1];
l2c(tout0,out);
l2c(tout1,out);
}
if (l != -8)
{
c2ln(in,tin0,tin1,l+8);
tin0^=tout0;
tin1^=tout1;
tin[0]=tin0;
tin[1]=tin1;
des_encrypt3((DES_LONG *)tin,ks1,ks2,ks3);
tout0=tin[0];
tout1=tin[1];
l2c(tout0,out);
l2c(tout1,out);
}
iv = &(*ivec)[0];
l2c(tout0,iv);
l2c(tout1,iv);
}
else
{
register DES_LONG t0,t1;
c2l(iv,xor0);
c2l(iv,xor1);
for (l-=8; l>=0; l-=8)
{
c2l(in,tin0);
c2l(in,tin1);
t0=tin0;
t1=tin1;
tin[0]=tin0;
tin[1]=tin1;
des_decrypt3((DES_LONG *)tin,ks1,ks2,ks3);
tout0=tin[0];
tout1=tin[1];
tout0^=xor0;
tout1^=xor1;
l2c(tout0,out);
l2c(tout1,out);
xor0=t0;
xor1=t1;
}
if (l != -8)
{
c2l(in,tin0);
c2l(in,tin1);
t0=tin0;
t1=tin1;
tin[0]=tin0;
tin[1]=tin1;
des_decrypt3((DES_LONG *)tin,ks1,ks2,ks3);
tout0=tin[0];
tout1=tin[1];
tout0^=xor0;
tout1^=xor1;
l2cn(tout0,tout1,out,l+8);
xor0=t0;
xor1=t1;
}
iv = &(*ivec)[0];
l2c(xor0,iv);
l2c(xor1,iv);
}
tin0=tin1=tout0=tout1=xor0=xor1=0;
tin[0]=tin[1]=0;
}
