static void zip_static_init_zip_ops(struct zip_operation *zip_ops,
int lzs_flag)
{
zip_ops->flush = ZIP_FLUSH_FINISH;
zip_ops->speed = 1;
if (!lzs_flag) {
zip_ops->ccode = 0;
zip_ops->lzs_flag = 0;
zip_ops->format = ZLIB_FORMAT;
} else {
zip_ops->ccode = 3;
zip_ops->lzs_flag = 1;
zip_ops->format = LZS_FORMAT;
}
zip_ops->begin_file = 1;
zip_ops->history_len = 0;
zip_ops->end_file = 1;
zip_ops->compcode = 0;
zip_ops->csum = 1;
}
int zip_ctx_init(struct zip_kernel_ctx *zip_ctx, int lzs_flag)
{
struct zip_operation *comp_ctx = &zip_ctx->zip_comp;
struct zip_operation *decomp_ctx = &zip_ctx->zip_decomp;
zip_static_init_zip_ops(comp_ctx, lzs_flag);
zip_static_init_zip_ops(decomp_ctx, lzs_flag);
comp_ctx->input = zip_data_buf_alloc(MAX_INPUT_BUFFER_SIZE);
if (!comp_ctx->input)
return -ENOMEM;
comp_ctx->output = zip_data_buf_alloc(MAX_OUTPUT_BUFFER_SIZE);
if (!comp_ctx->output)
goto err_comp_input;
decomp_ctx->input = zip_data_buf_alloc(MAX_INPUT_BUFFER_SIZE);
if (!decomp_ctx->input)
goto err_comp_output;
decomp_ctx->output = zip_data_buf_alloc(MAX_OUTPUT_BUFFER_SIZE);
if (!decomp_ctx->output)
goto err_decomp_input;
return 0;
err_decomp_input:
zip_data_buf_free(decomp_ctx->input, MAX_INPUT_BUFFER_SIZE);
err_comp_output:
zip_data_buf_free(comp_ctx->output, MAX_OUTPUT_BUFFER_SIZE);
err_comp_input:
zip_data_buf_free(comp_ctx->input, MAX_INPUT_BUFFER_SIZE);
return -ENOMEM;
}
void zip_ctx_exit(struct zip_kernel_ctx *zip_ctx)
{
struct zip_operation *comp_ctx = &zip_ctx->zip_comp;
struct zip_operation *dec_ctx = &zip_ctx->zip_decomp;
zip_data_buf_free(comp_ctx->input, MAX_INPUT_BUFFER_SIZE);
zip_data_buf_free(comp_ctx->output, MAX_OUTPUT_BUFFER_SIZE);
zip_data_buf_free(dec_ctx->input, MAX_INPUT_BUFFER_SIZE);
zip_data_buf_free(dec_ctx->output, MAX_OUTPUT_BUFFER_SIZE);
}
int zip_compress(const u8 *src, unsigned int slen,
u8 *dst, unsigned int *dlen,
struct zip_kernel_ctx *zip_ctx)
{
struct zip_operation *zip_ops = NULL;
struct zip_state zip_state;
struct zip_device *zip = NULL;
int ret;
if (!zip_ctx || !src || !dst || !dlen)
return -ENOMEM;
zip = zip_get_device(zip_get_node_id());
if (!zip)
return -ENODEV;
memset(&zip_state, 0, sizeof(struct zip_state));
zip_ops = &zip_ctx->zip_comp;
zip_ops->input_len = slen;
zip_ops->output_len = *dlen;
memcpy(zip_ops->input, src, slen);
ret = zip_deflate(zip_ops, &zip_state, zip);
if (!ret) {
*dlen = zip_ops->output_len;
memcpy(dst, zip_ops->output, *dlen);
}
return ret;
}
int zip_decompress(const u8 *src, unsigned int slen,
u8 *dst, unsigned int *dlen,
struct zip_kernel_ctx *zip_ctx)
{
struct zip_operation *zip_ops = NULL;
struct zip_state zip_state;
struct zip_device *zip = NULL;
int ret;
if (!zip_ctx || !src || !dst || !dlen)
return -ENOMEM;
zip = zip_get_device(zip_get_node_id());
if (!zip)
return -ENODEV;
memset(&zip_state, 0, sizeof(struct zip_state));
zip_ops = &zip_ctx->zip_decomp;
memcpy(zip_ops->input, src, slen);
if (zip_ops->ccode != 3)
zip_ops->input[slen++] = 0;
zip_ops->input_len = slen;
zip_ops->output_len = *dlen;
ret = zip_inflate(zip_ops, &zip_state, zip);
if (!ret) {
*dlen = zip_ops->output_len;
memcpy(dst, zip_ops->output, *dlen);
}
return ret;
}
int zip_alloc_comp_ctx_deflate(struct crypto_tfm *tfm)
{
int ret;
struct zip_kernel_ctx *zip_ctx = crypto_tfm_ctx(tfm);
ret = zip_ctx_init(zip_ctx, 0);
return ret;
}
int zip_alloc_comp_ctx_lzs(struct crypto_tfm *tfm)
{
int ret;
struct zip_kernel_ctx *zip_ctx = crypto_tfm_ctx(tfm);
ret = zip_ctx_init(zip_ctx, 1);
return ret;
}
void zip_free_comp_ctx(struct crypto_tfm *tfm)
{
struct zip_kernel_ctx *zip_ctx = crypto_tfm_ctx(tfm);
zip_ctx_exit(zip_ctx);
}
int zip_comp_compress(struct crypto_tfm *tfm,
const u8 *src, unsigned int slen,
u8 *dst, unsigned int *dlen)
{
int ret;
struct zip_kernel_ctx *zip_ctx = crypto_tfm_ctx(tfm);
ret = zip_compress(src, slen, dst, dlen, zip_ctx);
return ret;
}
int zip_comp_decompress(struct crypto_tfm *tfm,
const u8 *src, unsigned int slen,
u8 *dst, unsigned int *dlen)
{
int ret;
struct zip_kernel_ctx *zip_ctx = crypto_tfm_ctx(tfm);
ret = zip_decompress(src, slen, dst, dlen, zip_ctx);
return ret;
}
void *zip_alloc_scomp_ctx_deflate(struct crypto_scomp *tfm)
{
int ret;
struct zip_kernel_ctx *zip_ctx;
zip_ctx = kzalloc(sizeof(*zip_ctx), GFP_KERNEL);
if (!zip_ctx)
return ERR_PTR(-ENOMEM);
ret = zip_ctx_init(zip_ctx, 0);
if (ret) {
kzfree(zip_ctx);
return ERR_PTR(ret);
}
return zip_ctx;
}
void *zip_alloc_scomp_ctx_lzs(struct crypto_scomp *tfm)
{
int ret;
struct zip_kernel_ctx *zip_ctx;
zip_ctx = kzalloc(sizeof(*zip_ctx), GFP_KERNEL);
if (!zip_ctx)
return ERR_PTR(-ENOMEM);
ret = zip_ctx_init(zip_ctx, 1);
if (ret) {
kzfree(zip_ctx);
return ERR_PTR(ret);
}
return zip_ctx;
}
void zip_free_scomp_ctx(struct crypto_scomp *tfm, void *ctx)
{
struct zip_kernel_ctx *zip_ctx = ctx;
zip_ctx_exit(zip_ctx);
kzfree(zip_ctx);
}
int zip_scomp_compress(struct crypto_scomp *tfm,
const u8 *src, unsigned int slen,
u8 *dst, unsigned int *dlen, void *ctx)
{
int ret;
struct zip_kernel_ctx *zip_ctx = ctx;
ret = zip_compress(src, slen, dst, dlen, zip_ctx);
return ret;
}
int zip_scomp_decompress(struct crypto_scomp *tfm,
const u8 *src, unsigned int slen,
u8 *dst, unsigned int *dlen, void *ctx)
{
int ret;
struct zip_kernel_ctx *zip_ctx = ctx;
ret = zip_decompress(src, slen, dst, dlen, zip_ctx);
return ret;
}
