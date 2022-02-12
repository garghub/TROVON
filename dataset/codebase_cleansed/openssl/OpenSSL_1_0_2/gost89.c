static void kboxinit(gost_ctx * c, const gost_subst_block * b)
{
int i;
for (i = 0; i < 256; i++) {
c->k87[i] = (word32) (b->k8[i >> 4] << 4 | b->k7[i & 15]) << 24;
c->k65[i] = (b->k6[i >> 4] << 4 | b->k5[i & 15]) << 16;
c->k43[i] = (b->k4[i >> 4] << 4 | b->k3[i & 15]) << 8;
c->k21[i] = b->k2[i >> 4] << 4 | b->k1[i & 15];
}
}
static word32 f(gost_ctx * c, word32 x)
{
x = c->k87[x >> 24 & 255] | c->k65[x >> 16 & 255] |
c->k43[x >> 8 & 255] | c->k21[x & 255];
return x << 11 | x >> (32 - 11);
}
void gostcrypt(gost_ctx * c, const byte * in, byte * out)
{
register word32 n1, n2;
n1 = in[0] | (in[1] << 8) | (in[2] << 16) | ((word32) in[3] << 24);
n2 = in[4] | (in[5] << 8) | (in[6] << 16) | ((word32) in[7] << 24);
n2 ^= f(c, n1 + c->k[0]);
n1 ^= f(c, n2 + c->k[1]);
n2 ^= f(c, n1 + c->k[2]);
n1 ^= f(c, n2 + c->k[3]);
n2 ^= f(c, n1 + c->k[4]);
n1 ^= f(c, n2 + c->k[5]);
n2 ^= f(c, n1 + c->k[6]);
n1 ^= f(c, n2 + c->k[7]);
n2 ^= f(c, n1 + c->k[0]);
n1 ^= f(c, n2 + c->k[1]);
n2 ^= f(c, n1 + c->k[2]);
n1 ^= f(c, n2 + c->k[3]);
n2 ^= f(c, n1 + c->k[4]);
n1 ^= f(c, n2 + c->k[5]);
n2 ^= f(c, n1 + c->k[6]);
n1 ^= f(c, n2 + c->k[7]);
n2 ^= f(c, n1 + c->k[0]);
n1 ^= f(c, n2 + c->k[1]);
n2 ^= f(c, n1 + c->k[2]);
n1 ^= f(c, n2 + c->k[3]);
n2 ^= f(c, n1 + c->k[4]);
n1 ^= f(c, n2 + c->k[5]);
n2 ^= f(c, n1 + c->k[6]);
n1 ^= f(c, n2 + c->k[7]);
n2 ^= f(c, n1 + c->k[7]);
n1 ^= f(c, n2 + c->k[6]);
n2 ^= f(c, n1 + c->k[5]);
n1 ^= f(c, n2 + c->k[4]);
n2 ^= f(c, n1 + c->k[3]);
n1 ^= f(c, n2 + c->k[2]);
n2 ^= f(c, n1 + c->k[1]);
n1 ^= f(c, n2 + c->k[0]);
out[0] = (byte) (n2 & 0xff);
out[1] = (byte) ((n2 >> 8) & 0xff);
out[2] = (byte) ((n2 >> 16) & 0xff);
out[3] = (byte) (n2 >> 24);
out[4] = (byte) (n1 & 0xff);
out[5] = (byte) ((n1 >> 8) & 0xff);
out[6] = (byte) ((n1 >> 16) & 0xff);
out[7] = (byte) (n1 >> 24);
}
void gostdecrypt(gost_ctx * c, const byte * in, byte * out)
{
register word32 n1, n2;
n1 = in[0] | (in[1] << 8) | (in[2] << 16) | ((word32) in[3] << 24);
n2 = in[4] | (in[5] << 8) | (in[6] << 16) | ((word32) in[7] << 24);
n2 ^= f(c, n1 + c->k[0]);
n1 ^= f(c, n2 + c->k[1]);
n2 ^= f(c, n1 + c->k[2]);
n1 ^= f(c, n2 + c->k[3]);
n2 ^= f(c, n1 + c->k[4]);
n1 ^= f(c, n2 + c->k[5]);
n2 ^= f(c, n1 + c->k[6]);
n1 ^= f(c, n2 + c->k[7]);
n2 ^= f(c, n1 + c->k[7]);
n1 ^= f(c, n2 + c->k[6]);
n2 ^= f(c, n1 + c->k[5]);
n1 ^= f(c, n2 + c->k[4]);
n2 ^= f(c, n1 + c->k[3]);
n1 ^= f(c, n2 + c->k[2]);
n2 ^= f(c, n1 + c->k[1]);
n1 ^= f(c, n2 + c->k[0]);
n2 ^= f(c, n1 + c->k[7]);
n1 ^= f(c, n2 + c->k[6]);
n2 ^= f(c, n1 + c->k[5]);
n1 ^= f(c, n2 + c->k[4]);
n2 ^= f(c, n1 + c->k[3]);
n1 ^= f(c, n2 + c->k[2]);
n2 ^= f(c, n1 + c->k[1]);
n1 ^= f(c, n2 + c->k[0]);
n2 ^= f(c, n1 + c->k[7]);
n1 ^= f(c, n2 + c->k[6]);
n2 ^= f(c, n1 + c->k[5]);
n1 ^= f(c, n2 + c->k[4]);
n2 ^= f(c, n1 + c->k[3]);
n1 ^= f(c, n2 + c->k[2]);
n2 ^= f(c, n1 + c->k[1]);
n1 ^= f(c, n2 + c->k[0]);
out[0] = (byte) (n2 & 0xff);
out[1] = (byte) ((n2 >> 8) & 0xff);
out[2] = (byte) ((n2 >> 16) & 0xff);
out[3] = (byte) (n2 >> 24);
out[4] = (byte) (n1 & 0xff);
out[5] = (byte) ((n1 >> 8) & 0xff);
out[6] = (byte) ((n1 >> 16) & 0xff);
out[7] = (byte) (n1 >> 24);
}
void gost_enc(gost_ctx * c, const byte * clear, byte * cipher, int blocks)
{
int i;
for (i = 0; i < blocks; i++) {
gostcrypt(c, clear, cipher);
clear += 8;
cipher += 8;
}
}
void gost_dec(gost_ctx * c, const byte * cipher, byte * clear, int blocks)
{
int i;
for (i = 0; i < blocks; i++) {
gostdecrypt(c, cipher, clear);
clear += 8;
cipher += 8;
}
}
void gost_enc_cfb(gost_ctx * ctx, const byte * iv, const byte * clear,
byte * cipher, int blocks)
{
byte cur_iv[8];
byte gamma[8];
int i, j;
const byte *in;
byte *out;
memcpy(cur_iv, iv, 8);
for (i = 0, in = clear, out = cipher; i < blocks; i++, in += 8, out += 8) {
gostcrypt(ctx, cur_iv, gamma);
for (j = 0; j < 8; j++) {
cur_iv[j] = out[j] = in[j] ^ gamma[j];
}
}
}
void gost_dec_cfb(gost_ctx * ctx, const byte * iv, const byte * cipher,
byte * clear, int blocks)
{
byte cur_iv[8];
byte gamma[8];
int i, j;
const byte *in;
byte *out;
memcpy(cur_iv, iv, 8);
for (i = 0, in = cipher, out = clear; i < blocks; i++, in += 8, out += 8) {
gostcrypt(ctx, cur_iv, gamma);
for (j = 0; j < 8; j++) {
out[j] = (cur_iv[j] = in[j]) ^ gamma[j];
}
}
}
void gost_enc_with_key(gost_ctx * c, byte * key, byte * inblock,
byte * outblock)
{
gost_key(c, key);
gostcrypt(c, inblock, outblock);
}
void gost_key(gost_ctx * c, const byte * k)
{
int i, j;
for (i = 0, j = 0; i < 8; i++, j += 4) {
c->k[i] =
k[j] | (k[j + 1] << 8) | (k[j + 2] << 16) | ((word32) k[j + 3] <<
24);
}
}
void gost_get_key(gost_ctx * c, byte * k)
{
int i, j;
for (i = 0, j = 0; i < 8; i++, j += 4) {
k[j] = (byte) (c->k[i] & 0xFF);
k[j + 1] = (byte) ((c->k[i] >> 8) & 0xFF);
k[j + 2] = (byte) ((c->k[i] >> 16) & 0xFF);
k[j + 3] = (byte) ((c->k[i] >> 24) & 0xFF);
}
}
void gost_init(gost_ctx * c, const gost_subst_block * b)
{
if (!b) {
b = &GostR3411_94_TestParamSet;
}
kboxinit(c, b);
}
void gost_destroy(gost_ctx * c)
{
int i;
for (i = 0; i < 8; i++)
c->k[i] = 0;
}
void mac_block(gost_ctx * c, byte * buffer, const byte * block)
{
register word32 n1, n2;
int i;
for (i = 0; i < 8; i++) {
buffer[i] ^= block[i];
}
n1 = buffer[0] | (buffer[1] << 8) | (buffer[2] << 16) | ((word32)
buffer[3] << 24);
n2 = buffer[4] | (buffer[5] << 8) | (buffer[6] << 16) | ((word32)
buffer[7] << 24);
n2 ^= f(c, n1 + c->k[0]);
n1 ^= f(c, n2 + c->k[1]);
n2 ^= f(c, n1 + c->k[2]);
n1 ^= f(c, n2 + c->k[3]);
n2 ^= f(c, n1 + c->k[4]);
n1 ^= f(c, n2 + c->k[5]);
n2 ^= f(c, n1 + c->k[6]);
n1 ^= f(c, n2 + c->k[7]);
n2 ^= f(c, n1 + c->k[0]);
n1 ^= f(c, n2 + c->k[1]);
n2 ^= f(c, n1 + c->k[2]);
n1 ^= f(c, n2 + c->k[3]);
n2 ^= f(c, n1 + c->k[4]);
n1 ^= f(c, n2 + c->k[5]);
n2 ^= f(c, n1 + c->k[6]);
n1 ^= f(c, n2 + c->k[7]);
buffer[0] = (byte) (n1 & 0xff);
buffer[1] = (byte) ((n1 >> 8) & 0xff);
buffer[2] = (byte) ((n1 >> 16) & 0xff);
buffer[3] = (byte) (n1 >> 24);
buffer[4] = (byte) (n2 & 0xff);
buffer[5] = (byte) ((n2 >> 8) & 0xff);
buffer[6] = (byte) ((n2 >> 16) & 0xff);
buffer[7] = (byte) (n2 >> 24);
}
void get_mac(byte * buffer, int nbits, byte * out)
{
int nbytes = nbits >> 3;
int rembits = nbits & 7;
int mask = rembits ? ((1 < rembits) - 1) : 0;
int i;
for (i = 0; i < nbytes; i++)
out[i] = buffer[i];
if (rembits)
out[i] = buffer[i] & mask;
}
int gost_mac(gost_ctx * ctx, int mac_len, const unsigned char *data,
unsigned int data_len, unsigned char *mac)
{
byte buffer[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
byte buf2[8];
unsigned int i;
for (i = 0; i + 8 <= data_len; i += 8)
mac_block(ctx, buffer, data + i);
if (i < data_len) {
memset(buf2, 0, 8);
memcpy(buf2, data + i, data_len - i);
mac_block(ctx, buffer, buf2);
i += 8;
}
if (i == 8) {
memset(buf2, 0, 8);
mac_block(ctx, buffer, buf2);
}
get_mac(buffer, mac_len, mac);
return 1;
}
int gost_mac_iv(gost_ctx * ctx, int mac_len, const unsigned char *iv,
const unsigned char *data, unsigned int data_len,
unsigned char *mac)
{
byte buffer[8];
byte buf2[8];
unsigned int i;
memcpy(buffer, iv, 8);
for (i = 0; i + 8 <= data_len; i += 8)
mac_block(ctx, buffer, data + i);
if (i < data_len) {
memset(buf2, 0, 8);
memcpy(buf2, data + i, data_len - i);
mac_block(ctx, buffer, buf2);
i += 8;
}
if (i == 8) {
memset(buf2, 0, 8);
mac_block(ctx, buffer, buf2);
}
get_mac(buffer, mac_len, mac);
return 1;
}
void cryptopro_key_meshing(gost_ctx * ctx, unsigned char *iv)
{
unsigned char newkey[32], newiv[8];
gost_dec(ctx, CryptoProKeyMeshingKey, newkey, 4);
gost_key(ctx, newkey);
gostcrypt(ctx, iv, newiv);
memcpy(iv, newiv, 8);
}
