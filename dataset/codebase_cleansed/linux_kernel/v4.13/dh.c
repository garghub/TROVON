static inline void dh_clear_params(struct dh_ctx *ctx)
{
mpi_free(ctx->p);
mpi_free(ctx->g);
ctx->p = NULL;
ctx->g = NULL;
}
static void dh_free_ctx(struct dh_ctx *ctx)
{
dh_clear_params(ctx);
mpi_free(ctx->xa);
ctx->xa = NULL;
}
static int _compute_val(const struct dh_ctx *ctx, MPI base, MPI val)
{
return mpi_powm(val, base, ctx->xa, ctx->p);
}
static inline struct dh_ctx *dh_get_ctx(struct crypto_kpp *tfm)
{
return kpp_tfm_ctx(tfm);
}
static int dh_check_params_length(unsigned int p_len)
{
return (p_len < 1536) ? -EINVAL : 0;
}
static int dh_set_params(struct dh_ctx *ctx, struct dh *params)
{
if (unlikely(!params->p || !params->g))
return -EINVAL;
if (dh_check_params_length(params->p_size << 3))
return -EINVAL;
ctx->p = mpi_read_raw_data(params->p, params->p_size);
if (!ctx->p)
return -EINVAL;
ctx->g = mpi_read_raw_data(params->g, params->g_size);
if (!ctx->g) {
mpi_free(ctx->p);
return -EINVAL;
}
return 0;
}
static int dh_set_secret(struct crypto_kpp *tfm, const void *buf,
unsigned int len)
{
struct dh_ctx *ctx = dh_get_ctx(tfm);
struct dh params;
dh_free_ctx(ctx);
if (crypto_dh_decode_key(buf, len, &params) < 0)
return -EINVAL;
if (dh_set_params(ctx, &params) < 0)
return -EINVAL;
ctx->xa = mpi_read_raw_data(params.key, params.key_size);
if (!ctx->xa) {
dh_clear_params(ctx);
return -EINVAL;
}
return 0;
}
static int dh_compute_value(struct kpp_request *req)
{
struct crypto_kpp *tfm = crypto_kpp_reqtfm(req);
struct dh_ctx *ctx = dh_get_ctx(tfm);
MPI base, val = mpi_alloc(0);
int ret = 0;
int sign;
if (!val)
return -ENOMEM;
if (unlikely(!ctx->xa)) {
ret = -EINVAL;
goto err_free_val;
}
if (req->src) {
base = mpi_read_raw_from_sgl(req->src, req->src_len);
if (!base) {
ret = -EINVAL;
goto err_free_val;
}
} else {
base = ctx->g;
}
ret = _compute_val(ctx, base, val);
if (ret)
goto err_free_base;
ret = mpi_write_to_sgl(val, req->dst, req->dst_len, &sign);
if (ret)
goto err_free_base;
if (sign < 0)
ret = -EBADMSG;
err_free_base:
if (req->src)
mpi_free(base);
err_free_val:
mpi_free(val);
return ret;
}
static unsigned int dh_max_size(struct crypto_kpp *tfm)
{
struct dh_ctx *ctx = dh_get_ctx(tfm);
return mpi_get_size(ctx->p);
}
static void dh_exit_tfm(struct crypto_kpp *tfm)
{
struct dh_ctx *ctx = dh_get_ctx(tfm);
dh_free_ctx(ctx);
}
static int dh_init(void)
{
return crypto_register_kpp(&dh);
}
static void dh_exit(void)
{
crypto_unregister_kpp(&dh);
}
