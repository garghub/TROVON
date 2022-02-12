static inline
u32 generic_rotr32 (const u32 x, const unsigned bits)
{
const unsigned n = bits % 32;
return (x >> n) | (x << (32 - n));
}
static inline
u32 generic_rotl32 (const u32 x, const unsigned bits)
{
const unsigned n = bits % 32;
return (x << n) | (x >> (32 - n));
}
inline static u8
byte(const u32 x, const unsigned n)
{
return x >> (n << 3);
}
static inline u8 __init
f_mult (u8 a, u8 b)
{
u8 aa = log_tab[a], cc = aa + log_tab[b];
return pow_tab[cc + (cc < aa ? 1 : 0)];
}
static void __init
gen_tabs (void)
{
u32 i, t;
u8 p, q;
for (i = 0, p = 1; i < 256; ++i) {
pow_tab[i] = (u8) p;
log_tab[p] = (u8) i;
p ^= (p << 1) ^ (p & 0x80 ? 0x01b : 0);
}
log_tab[1] = 0;
for (i = 0, p = 1; i < 10; ++i) {
rco_tab[i] = p;
p = (p << 1) ^ (p & 0x80 ? 0x01b : 0);
}
for (i = 0; i < 256; ++i) {
p = (i ? pow_tab[255 - log_tab[i]] : 0);
q = ((p >> 7) | (p << 1)) ^ ((p >> 6) | (p << 2));
p ^= 0x63 ^ q ^ ((q >> 6) | (q << 2));
sbx_tab[i] = p;
isb_tab[p] = (u8) i;
}
for (i = 0; i < 256; ++i) {
p = sbx_tab[i];
t = p;
fl_tab[0][i] = t;
fl_tab[1][i] = rotl (t, 8);
fl_tab[2][i] = rotl (t, 16);
fl_tab[3][i] = rotl (t, 24);
t = ((u32) ff_mult (2, p)) |
((u32) p << 8) |
((u32) p << 16) | ((u32) ff_mult (3, p) << 24);
ft_tab[0][i] = t;
ft_tab[1][i] = rotl (t, 8);
ft_tab[2][i] = rotl (t, 16);
ft_tab[3][i] = rotl (t, 24);
p = isb_tab[i];
t = p;
il_tab[0][i] = t;
il_tab[1][i] = rotl (t, 8);
il_tab[2][i] = rotl (t, 16);
il_tab[3][i] = rotl (t, 24);
t = ((u32) ff_mult (14, p)) |
((u32) ff_mult (9, p) << 8) |
((u32) ff_mult (13, p) << 16) |
((u32) ff_mult (11, p) << 24);
it_tab[0][i] = t;
it_tab[1][i] = rotl (t, 8);
it_tab[2][i] = rotl (t, 16);
it_tab[3][i] = rotl (t, 24);
}
}
static int
aes_set_key(void *ctx_arg, const u8 *in_key, unsigned int key_len, u32 *flags)
{
struct aes_ctx *ctx = ctx_arg;
u32 i, t, u, v, w;
if (key_len != 16 && key_len != 24 && key_len != 32) {
*flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
ctx->key_length = key_len;
E_KEY[0] = u32_in (in_key);
E_KEY[1] = u32_in (in_key + 4);
E_KEY[2] = u32_in (in_key + 8);
E_KEY[3] = u32_in (in_key + 12);
switch (key_len) {
case 16:
t = E_KEY[3];
for (i = 0; i < 10; ++i)
loop4 (i);
break;
case 24:
E_KEY[4] = u32_in (in_key + 16);
t = E_KEY[5] = u32_in (in_key + 20);
for (i = 0; i < 8; ++i)
loop6 (i);
break;
case 32:
E_KEY[4] = u32_in (in_key + 16);
E_KEY[5] = u32_in (in_key + 20);
E_KEY[6] = u32_in (in_key + 24);
t = E_KEY[7] = u32_in (in_key + 28);
for (i = 0; i < 7; ++i)
loop8 (i);
break;
}
D_KEY[0] = E_KEY[0];
D_KEY[1] = E_KEY[1];
D_KEY[2] = E_KEY[2];
D_KEY[3] = E_KEY[3];
for (i = 4; i < key_len + 24; ++i) {
imix_col (D_KEY[i], E_KEY[i]);
}
return 0;
}
static void aes_encrypt(void *ctx_arg, u8 *out, const u8 *in)
{
const struct aes_ctx *ctx = ctx_arg;
u32 b0[4], b1[4];
const u32 *kp = E_KEY + 4;
b0[0] = u32_in (in) ^ E_KEY[0];
b0[1] = u32_in (in + 4) ^ E_KEY[1];
b0[2] = u32_in (in + 8) ^ E_KEY[2];
b0[3] = u32_in (in + 12) ^ E_KEY[3];
if (ctx->key_length > 24) {
f_nround (b1, b0, kp);
f_nround (b0, b1, kp);
}
if (ctx->key_length > 16) {
f_nround (b1, b0, kp);
f_nround (b0, b1, kp);
}
f_nround (b1, b0, kp);
f_nround (b0, b1, kp);
f_nround (b1, b0, kp);
f_nround (b0, b1, kp);
f_nround (b1, b0, kp);
f_nround (b0, b1, kp);
f_nround (b1, b0, kp);
f_nround (b0, b1, kp);
f_nround (b1, b0, kp);
f_lround (b0, b1, kp);
u32_out (out, b0[0]);
u32_out (out + 4, b0[1]);
u32_out (out + 8, b0[2]);
u32_out (out + 12, b0[3]);
}
static void aes_decrypt(void *ctx_arg, u8 *out, const u8 *in)
{
const struct aes_ctx *ctx = ctx_arg;
u32 b0[4], b1[4];
const int key_len = ctx->key_length;
const u32 *kp = D_KEY + key_len + 20;
b0[0] = u32_in (in) ^ E_KEY[key_len + 24];
b0[1] = u32_in (in + 4) ^ E_KEY[key_len + 25];
b0[2] = u32_in (in + 8) ^ E_KEY[key_len + 26];
b0[3] = u32_in (in + 12) ^ E_KEY[key_len + 27];
if (key_len > 24) {
i_nround (b1, b0, kp);
i_nround (b0, b1, kp);
}
if (key_len > 16) {
i_nround (b1, b0, kp);
i_nround (b0, b1, kp);
}
i_nround (b1, b0, kp);
i_nround (b0, b1, kp);
i_nround (b1, b0, kp);
i_nround (b0, b1, kp);
i_nround (b1, b0, kp);
i_nround (b0, b1, kp);
i_nround (b1, b0, kp);
i_nround (b0, b1, kp);
i_nround (b1, b0, kp);
i_lround (b0, b1, kp);
u32_out (out, b0[0]);
u32_out (out + 4, b0[1]);
u32_out (out + 8, b0[2]);
u32_out (out + 12, b0[3]);
}
static int __init aes_init(void)
{
gen_tabs();
return crypto_register_alg(&aes_alg);
}
static void __exit aes_fini(void)
{
crypto_unregister_alg(&aes_alg);
}
