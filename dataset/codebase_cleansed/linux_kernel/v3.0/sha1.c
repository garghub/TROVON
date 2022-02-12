void sha_transform(__u32 *digest, const char *in, __u32 *W)
{
__u32 a, b, c, d, e, t, i;
for (i = 0; i < 16; i++)
W[i] = be32_to_cpu(((const __be32 *)in)[i]);
for (i = 0; i < 64; i++)
W[i+16] = rol32(W[i+13] ^ W[i+8] ^ W[i+2] ^ W[i], 1);
a = digest[0];
b = digest[1];
c = digest[2];
d = digest[3];
e = digest[4];
for (i = 0; i < 20; i++) {
t = f1(b, c, d) + K1 + rol32(a, 5) + e + W[i];
e = d; d = c; c = rol32(b, 30); b = a; a = t;
}
for (; i < 40; i ++) {
t = f2(b, c, d) + K2 + rol32(a, 5) + e + W[i];
e = d; d = c; c = rol32(b, 30); b = a; a = t;
}
for (; i < 60; i ++) {
t = f3(b, c, d) + K3 + rol32(a, 5) + e + W[i];
e = d; d = c; c = rol32(b, 30); b = a; a = t;
}
for (; i < 80; i ++) {
t = f2(b, c, d) + K4 + rol32(a, 5) + e + W[i];
e = d; d = c; c = rol32(b, 30); b = a; a = t;
}
digest[0] += a;
digest[1] += b;
digest[2] += c;
digest[3] += d;
digest[4] += e;
}
void sha_init(__u32 *buf)
{
buf[0] = 0x67452301;
buf[1] = 0xefcdab89;
buf[2] = 0x98badcfe;
buf[3] = 0x10325476;
buf[4] = 0xc3d2e1f0;
}
