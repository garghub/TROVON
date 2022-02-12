void CAST_cfb64_encrypt(const unsigned char *in, unsigned char *out,
long length, const CAST_KEY *schedule,
unsigned char *ivec, int *num, int enc)
{
register CAST_LONG v0, v1, t;
register int n = *num;
register long l = length;
CAST_LONG ti[2];
unsigned char *iv, c, cc;
iv = ivec;
if (enc) {
while (l--) {
if (n == 0) {
n2l(iv, v0);
ti[0] = v0;
n2l(iv, v1);
ti[1] = v1;
CAST_encrypt((CAST_LONG *)ti, schedule);
iv = ivec;
t = ti[0];
l2n(t, iv);
t = ti[1];
l2n(t, iv);
iv = ivec;
}
c = *(in++) ^ iv[n];
*(out++) = c;
iv[n] = c;
n = (n + 1) & 0x07;
}
} else {
while (l--) {
if (n == 0) {
n2l(iv, v0);
ti[0] = v0;
n2l(iv, v1);
ti[1] = v1;
CAST_encrypt((CAST_LONG *)ti, schedule);
iv = ivec;
t = ti[0];
l2n(t, iv);
t = ti[1];
l2n(t, iv);
iv = ivec;
}
cc = *(in++);
c = iv[n];
iv[n] = cc;
*(out++) = c ^ cc;
n = (n + 1) & 0x07;
}
}
v0 = v1 = ti[0] = ti[1] = t = c = cc = 0;
*num = n;
}
