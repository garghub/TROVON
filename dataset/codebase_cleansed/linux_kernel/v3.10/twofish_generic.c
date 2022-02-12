static void twofish_encrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
struct twofish_ctx *ctx = crypto_tfm_ctx(tfm);
const __le32 *src = (const __le32 *)in;
__le32 *dst = (__le32 *)out;
u32 a, b, c, d;
u32 x, y;
INPACK (0, a, 0);
INPACK (1, b, 1);
INPACK (2, c, 2);
INPACK (3, d, 3);
ENCCYCLE (0);
ENCCYCLE (1);
ENCCYCLE (2);
ENCCYCLE (3);
ENCCYCLE (4);
ENCCYCLE (5);
ENCCYCLE (6);
ENCCYCLE (7);
OUTUNPACK (0, c, 4);
OUTUNPACK (1, d, 5);
OUTUNPACK (2, a, 6);
OUTUNPACK (3, b, 7);
}
static void twofish_decrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
struct twofish_ctx *ctx = crypto_tfm_ctx(tfm);
const __le32 *src = (const __le32 *)in;
__le32 *dst = (__le32 *)out;
u32 a, b, c, d;
u32 x, y;
INPACK (0, c, 4);
INPACK (1, d, 5);
INPACK (2, a, 6);
INPACK (3, b, 7);
DECCYCLE (7);
DECCYCLE (6);
DECCYCLE (5);
DECCYCLE (4);
DECCYCLE (3);
DECCYCLE (2);
DECCYCLE (1);
DECCYCLE (0);
OUTUNPACK (0, a, 0);
OUTUNPACK (1, b, 1);
OUTUNPACK (2, c, 2);
OUTUNPACK (3, d, 3);
}
static int __init twofish_mod_init(void)
{
return crypto_register_alg(&alg);
}
static void __exit twofish_mod_fini(void)
{
crypto_unregister_alg(&alg);
}
