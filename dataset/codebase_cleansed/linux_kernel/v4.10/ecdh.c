static inline struct ecdh_ctx *ecdh_get_ctx(struct crypto_kpp *tfm)
{
return kpp_tfm_ctx(tfm);
}
static unsigned int ecdh_supported_curve(unsigned int curve_id)
{
switch (curve_id) {
case ECC_CURVE_NIST_P192: return 3;
case ECC_CURVE_NIST_P256: return 4;
default: return 0;
}
}
static int ecdh_set_secret(struct crypto_kpp *tfm, void *buf, unsigned int len)
{
struct ecdh_ctx *ctx = ecdh_get_ctx(tfm);
struct ecdh params;
unsigned int ndigits;
if (crypto_ecdh_decode_key(buf, len, &params) < 0)
return -EINVAL;
ndigits = ecdh_supported_curve(params.curve_id);
if (!ndigits)
return -EINVAL;
ctx->curve_id = params.curve_id;
ctx->ndigits = ndigits;
if (ecc_is_key_valid(ctx->curve_id, ctx->ndigits,
(const u8 *)params.key, params.key_size) < 0)
return -EINVAL;
memcpy(ctx->private_key, params.key, params.key_size);
return 0;
}
static int ecdh_compute_value(struct kpp_request *req)
{
int ret = 0;
struct crypto_kpp *tfm = crypto_kpp_reqtfm(req);
struct ecdh_ctx *ctx = ecdh_get_ctx(tfm);
size_t copied, nbytes;
void *buf;
nbytes = ctx->ndigits << ECC_DIGITS_TO_BYTES_SHIFT;
if (req->src) {
copied = sg_copy_to_buffer(req->src, 1, ctx->public_key,
2 * nbytes);
if (copied != 2 * nbytes)
return -EINVAL;
ret = crypto_ecdh_shared_secret(ctx->curve_id, ctx->ndigits,
(const u8 *)ctx->private_key, nbytes,
(const u8 *)ctx->public_key, 2 * nbytes,
(u8 *)ctx->shared_secret, nbytes);
buf = ctx->shared_secret;
} else {
ret = ecdh_make_pub_key(ctx->curve_id, ctx->ndigits,
(const u8 *)ctx->private_key, nbytes,
(u8 *)ctx->public_key,
sizeof(ctx->public_key));
buf = ctx->public_key;
nbytes *= 2;
}
if (ret < 0)
return ret;
copied = sg_copy_from_buffer(req->dst, 1, buf, nbytes);
if (copied != nbytes)
return -EINVAL;
return ret;
}
static int ecdh_max_size(struct crypto_kpp *tfm)
{
struct ecdh_ctx *ctx = ecdh_get_ctx(tfm);
int nbytes = ctx->ndigits << ECC_DIGITS_TO_BYTES_SHIFT;
return 2 * nbytes;
}
static void no_exit_tfm(struct crypto_kpp *tfm)
{
return;
}
static int ecdh_init(void)
{
return crypto_register_kpp(&ecdh);
}
static void ecdh_exit(void)
{
crypto_unregister_kpp(&ecdh);
}
