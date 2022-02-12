static int arc4_set_key(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
struct arc4_ctx *ctx = crypto_tfm_ctx(tfm);
int i, j = 0, k = 0;
ctx->x = 1;
ctx->y = 0;
for(i = 0; i < 256; i++)
ctx->S[i] = i;
for(i = 0; i < 256; i++)
{
u8 a = ctx->S[i];
j = (j + in_key[k] + a) & 0xff;
ctx->S[i] = ctx->S[j];
ctx->S[j] = a;
if(++k >= key_len)
k = 0;
}
return 0;
}
static void arc4_crypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
struct arc4_ctx *ctx = crypto_tfm_ctx(tfm);
u8 *const S = ctx->S;
u8 x = ctx->x;
u8 y = ctx->y;
u8 a, b;
a = S[x];
y = (y + a) & 0xff;
b = S[y];
S[x] = b;
S[y] = a;
x = (x + 1) & 0xff;
*out++ = *in ^ S[(a + b) & 0xff];
ctx->x = x;
ctx->y = y;
}
static int __init arc4_init(void)
{
return crypto_register_alg(&arc4_alg);
}
static void __exit arc4_exit(void)
{
crypto_unregister_alg(&arc4_alg);
}
