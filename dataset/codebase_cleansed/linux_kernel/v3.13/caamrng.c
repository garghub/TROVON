static inline void rng_unmap_buf(struct device *jrdev, struct buf_data *bd)
{
if (bd->addr)
dma_unmap_single(jrdev, bd->addr, RN_BUF_SIZE,
DMA_FROM_DEVICE);
}
static inline void rng_unmap_ctx(struct caam_rng_ctx *ctx)
{
struct device *jrdev = ctx->jrdev;
if (ctx->sh_desc_dma)
dma_unmap_single(jrdev, ctx->sh_desc_dma, DESC_RNG_LEN,
DMA_TO_DEVICE);
rng_unmap_buf(jrdev, &ctx->bufs[0]);
rng_unmap_buf(jrdev, &ctx->bufs[1]);
}
static void rng_done(struct device *jrdev, u32 *desc, u32 err, void *context)
{
struct buf_data *bd;
bd = (struct buf_data *)((char *)desc -
offsetof(struct buf_data, hw_desc));
if (err) {
char tmp[CAAM_ERROR_STR_MAX];
dev_err(jrdev, "%08x: %s\n", err, caam_jr_strstatus(tmp, err));
}
atomic_set(&bd->empty, BUF_NOT_EMPTY);
complete(&bd->filled);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "rng refreshed buf@: ",
DUMP_PREFIX_ADDRESS, 16, 4, bd->buf, RN_BUF_SIZE, 1);
#endif
}
static inline int submit_job(struct caam_rng_ctx *ctx, int to_current)
{
struct buf_data *bd = &ctx->bufs[!(to_current ^ ctx->current_buf)];
struct device *jrdev = ctx->jrdev;
u32 *desc = bd->hw_desc;
int err;
dev_dbg(jrdev, "submitting job %d\n", !(to_current ^ ctx->current_buf));
init_completion(&bd->filled);
err = caam_jr_enqueue(jrdev, desc, rng_done, ctx);
if (err)
complete(&bd->filled);
else
atomic_inc(&bd->empty);
return err;
}
static int caam_read(struct hwrng *rng, void *data, size_t max, bool wait)
{
struct caam_rng_ctx *ctx = &rng_ctx;
struct buf_data *bd = &ctx->bufs[ctx->current_buf];
int next_buf_idx, copied_idx;
int err;
if (atomic_read(&bd->empty)) {
if (atomic_read(&bd->empty) == BUF_EMPTY) {
err = submit_job(ctx, 1);
if (err)
return 0;
}
if (!wait)
return 0;
if (atomic_read(&bd->empty))
wait_for_completion(&bd->filled);
}
next_buf_idx = ctx->cur_buf_idx + max;
dev_dbg(ctx->jrdev, "%s: start reading at buffer %d, idx %d\n",
__func__, ctx->current_buf, ctx->cur_buf_idx);
if (next_buf_idx < RN_BUF_SIZE) {
memcpy(data, bd->buf + ctx->cur_buf_idx, max);
ctx->cur_buf_idx = next_buf_idx;
return max;
}
copied_idx = RN_BUF_SIZE - ctx->cur_buf_idx;
memcpy(data, bd->buf + ctx->cur_buf_idx, copied_idx);
ctx->cur_buf_idx = 0;
atomic_set(&bd->empty, BUF_EMPTY);
submit_job(ctx, 1);
ctx->current_buf = !ctx->current_buf;
dev_dbg(ctx->jrdev, "switched to buffer %d\n", ctx->current_buf);
return copied_idx + caam_read(rng, data + copied_idx,
max - copied_idx, false);
}
static inline void rng_create_sh_desc(struct caam_rng_ctx *ctx)
{
struct device *jrdev = ctx->jrdev;
u32 *desc = ctx->sh_desc;
init_sh_desc(desc, HDR_SHARE_SERIAL);
append_cmd(desc, SET_OK_NO_PROP_ERRORS | CMD_LOAD);
append_operation(desc, OP_ALG_ALGSEL_RNG | OP_TYPE_CLASS1_ALG);
append_seq_fifo_store(desc, RN_BUF_SIZE, FIFOST_TYPE_RNGSTORE);
ctx->sh_desc_dma = dma_map_single(jrdev, desc, desc_bytes(desc),
DMA_TO_DEVICE);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "rng shdesc@: ", DUMP_PREFIX_ADDRESS, 16, 4,
desc, desc_bytes(desc), 1);
#endif
}
static inline void rng_create_job_desc(struct caam_rng_ctx *ctx, int buf_id)
{
struct device *jrdev = ctx->jrdev;
struct buf_data *bd = &ctx->bufs[buf_id];
u32 *desc = bd->hw_desc;
int sh_len = desc_len(ctx->sh_desc);
init_job_desc_shared(desc, ctx->sh_desc_dma, sh_len, HDR_SHARE_DEFER |
HDR_REVERSE);
bd->addr = dma_map_single(jrdev, bd->buf, RN_BUF_SIZE, DMA_FROM_DEVICE);
append_seq_out_ptr_intlen(desc, bd->addr, RN_BUF_SIZE, 0);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "rng job desc@: ", DUMP_PREFIX_ADDRESS, 16, 4,
desc, desc_bytes(desc), 1);
#endif
}
static void caam_cleanup(struct hwrng *rng)
{
int i;
struct buf_data *bd;
for (i = 0; i < 2; i++) {
bd = &rng_ctx.bufs[i];
if (atomic_read(&bd->empty) == BUF_PENDING)
wait_for_completion(&bd->filled);
}
rng_unmap_ctx(&rng_ctx);
}
static void caam_init_buf(struct caam_rng_ctx *ctx, int buf_id)
{
struct buf_data *bd = &ctx->bufs[buf_id];
rng_create_job_desc(ctx, buf_id);
atomic_set(&bd->empty, BUF_EMPTY);
submit_job(ctx, buf_id == ctx->current_buf);
wait_for_completion(&bd->filled);
}
static void caam_init_rng(struct caam_rng_ctx *ctx, struct device *jrdev)
{
ctx->jrdev = jrdev;
rng_create_sh_desc(ctx);
ctx->current_buf = 0;
ctx->cur_buf_idx = 0;
caam_init_buf(ctx, 0);
caam_init_buf(ctx, 1);
}
static void __exit caam_rng_exit(void)
{
caam_jr_free(rng_ctx.jrdev);
hwrng_unregister(&caam_rng);
}
static int __init caam_rng_init(void)
{
struct device *dev;
dev = caam_jr_alloc();
if (IS_ERR(dev)) {
pr_err("Job Ring Device allocation for transform failed\n");
return PTR_ERR(dev);
}
caam_init_rng(&rng_ctx, dev);
dev_info(dev, "registering rng-caam\n");
return hwrng_register(&caam_rng);
}
