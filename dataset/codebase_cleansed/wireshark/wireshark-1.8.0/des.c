static void permute(char *out, const char *in, const uchar *p, int n)
{
int i;
for (i=0;i<n;i++)
out[i] = in[p[i]-1];
}
static void lshift(char *d, int count, int n)
{
char out[64];
int i;
for (i=0;i<n;i++)
out[i] = d[(i+count)%n];
for (i=0;i<n;i++)
d[i] = out[i];
}
static void concat(char *out, char *in1, char *in2, int l1, int l2)
{
while (l1--)
*out++ = *in1++;
while (l2--)
*out++ = *in2++;
}
static void xor(char *out, char *in1, char *in2, int n)
{
int i;
for (i=0;i<n;i++)
out[i] = in1[i] ^ in2[i];
}
static void dohash(char *out, char *in, char *key, int forw)
{
int i, j, k;
char pk1[56];
char c[28];
char d[28];
char cd[56];
char ki[16][48];
char pd1[64];
char l[32], r[32];
char rl[64];
permute(pk1, key, perm1, 56);
for (i=0;i<28;i++)
c[i] = pk1[i];
for (i=0;i<28;i++)
d[i] = pk1[i+28];
for (i=0;i<16;i++) {
lshift(c, sc[i], 28);
lshift(d, sc[i], 28);
concat(cd, c, d, 28, 28);
permute(ki[i], cd, perm2, 48);
}
permute(pd1, in, perm3, 64);
for (j=0;j<32;j++) {
l[j] = pd1[j];
r[j] = pd1[j+32];
}
for (i=0;i<16;i++) {
char er[48];
char erk[48];
char b[8][6];
char cb[32];
char pcb[32];
char r2[32];
permute(er, r, perm4, 48);
xor(erk, er, ki[forw ? i : 15 - i], 48);
for (j=0;j<8;j++)
for (k=0;k<6;k++)
b[j][k] = erk[j*6 + k];
for (j=0;j<8;j++) {
int m, n;
m = (b[j][0]<<1) | b[j][5];
n = (b[j][1]<<3) | (b[j][2]<<2) | (b[j][3]<<1) | b[j][4];
for (k=0;k<4;k++)
b[j][k] = (sbox[j][m][n] & (1<<(3-k)))?1:0;
}
for (j=0;j<8;j++)
for (k=0;k<4;k++)
cb[j*4+k] = b[j][k];
permute(pcb, cb, perm5, 32);
xor(r2, l, pcb, 32);
for (j=0;j<32;j++)
l[j] = r[j];
for (j=0;j<32;j++)
r[j] = r2[j];
}
concat(rl, r, l, 32, 32);
permute(out, rl, perm6, 64);
}
static void str_to_key(const unsigned char *str,unsigned char *key)
{
int i;
key[0] = str[0]>>1;
key[1] = ((str[0]&0x01)<<6) | (str[1]>>2);
key[2] = ((str[1]&0x03)<<5) | (str[2]>>3);
key[3] = ((str[2]&0x07)<<4) | (str[3]>>4);
key[4] = ((str[3]&0x0F)<<3) | (str[4]>>5);
key[5] = ((str[4]&0x1F)<<2) | (str[5]>>6);
key[6] = ((str[5]&0x3F)<<1) | (str[6]>>7);
key[7] = str[6]&0x7F;
for (i=0;i<8;i++) {
key[i] = (key[i]<<1);
}
}
void crypt_des_ecb(unsigned char *out, const unsigned char *in, const unsigned char *key, int forw)
{
int i;
char outb[64];
char inb[64];
char keyb[64];
unsigned char key2[8];
str_to_key(key, key2);
for (i=0;i<64;i++) {
inb[i] = (in[i/8] & (1<<(7-(i%8)))) ? 1 : 0;
keyb[i] = (key2[i/8] & (1<<(7-(i%8)))) ? 1 : 0;
outb[i] = 0;
}
dohash(outb, inb, keyb, forw);
for (i=0;i<8;i++) {
out[i] = 0;
}
for (i=0;i<64;i++) {
if (outb[i])
out[i/8] |= (1<<(7-(i%8)));
}
}
