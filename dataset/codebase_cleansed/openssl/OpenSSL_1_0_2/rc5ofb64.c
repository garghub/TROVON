void RC5_32_ofb64_encrypt(const unsigned char *in, unsigned char *out,
long length, RC5_32_KEY *schedule,
unsigned char *ivec, int *num)
{
register unsigned long v0, v1, t;
register int n = *num;
register long l = length;
unsigned char d[8];
register char *dp;
unsigned long ti[2];
unsigned char *iv;
int save = 0;
iv = (unsigned char *)ivec;
c2l(iv, v0);
c2l(iv, v1);
ti[0] = v0;
ti[1] = v1;
dp = (char *)d;
l2c(v0, dp);
l2c(v1, dp);
while (l--) {
if (n == 0) {
RC5_32_encrypt((unsigned long *)ti, schedule);
dp = (char *)d;
t = ti[0];
l2c(t, dp);
t = ti[1];
l2c(t, dp);
save++;
}
*(out++) = *(in++) ^ d[n];
n = (n + 1) & 0x07;
}
if (save) {
v0 = ti[0];
v1 = ti[1];
iv = (unsigned char *)ivec;
l2c(v0, iv);
l2c(v1, iv);
}
t = v0 = v1 = ti[0] = ti[1] = 0;
*num = n;
}
