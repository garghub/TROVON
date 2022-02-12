static int mxc_scc_get_data(struct mxc_scc_ctx *ctx,
struct crypto_async_request *req)
{
struct ablkcipher_request *ablkreq = ablkcipher_request_cast(req);
struct mxc_scc *scc = ctx->scc;
size_t len;
void __iomem *from;
if (ctx->ctrl & SCC_SCM_CTRL_DECRYPT_MODE)
from = scc->red_memory;
else
from = scc->black_memory;
dev_dbg(scc->dev, "pcopy: from 0x%p %d bytes\n", from,
ctx->dst_nents * 8);
len = sg_pcopy_from_buffer(ablkreq->dst, ctx->dst_nents,
from, ctx->size, ctx->offset);
if (!len) {
dev_err(scc->dev, "pcopy err from 0x%p (len=%d)\n", from, len);
return -EINVAL;
}
#ifdef DEBUG
print_hex_dump(KERN_ERR,
"red memory@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4,
scc->red_memory, ctx->size, 1);
print_hex_dump(KERN_ERR,
"black memory@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4,
scc->black_memory, ctx->size, 1);
#endif
ctx->offset += len;
if (ctx->offset < ablkreq->nbytes)
return -EINPROGRESS;
return 0;
}
static int mxc_scc_ablkcipher_req_init(struct ablkcipher_request *req,
struct mxc_scc_ctx *ctx)
{
struct mxc_scc *scc = ctx->scc;
int nents;
nents = sg_nents_for_len(req->src, req->nbytes);
if (nents < 0) {
dev_err(scc->dev, "Invalid number of src SC");
return nents;
}
ctx->src_nents = nents;
nents = sg_nents_for_len(req->dst, req->nbytes);
if (nents < 0) {
dev_err(scc->dev, "Invalid number of dst SC");
return nents;
}
ctx->dst_nents = nents;
ctx->size = 0;
ctx->offset = 0;
return 0;
}
static int mxc_scc_ablkcipher_req_complete(struct crypto_async_request *req,
struct mxc_scc_ctx *ctx,
int result)
{
struct ablkcipher_request *ablkreq = ablkcipher_request_cast(req);
struct mxc_scc *scc = ctx->scc;
scc->req = NULL;
scc->bytes_remaining = scc->memory_size_bytes;
if (ctx->ctrl & SCC_SCM_CTRL_CBC_MODE)
memcpy(ablkreq->info, scc->base + SCC_SCM_INIT_VECTOR_0,
scc->block_size_bytes);
req->complete(req, result);
scc->hw_busy = false;
return 0;
}
static int mxc_scc_put_data(struct mxc_scc_ctx *ctx,
struct ablkcipher_request *req)
{
u8 padding_buffer[sizeof(u16) + sizeof(scc_block_padding)];
size_t len = min_t(size_t, req->nbytes - ctx->offset,
ctx->scc->bytes_remaining);
unsigned int padding_byte_count = 0;
struct mxc_scc *scc = ctx->scc;
void __iomem *to;
if (ctx->ctrl & SCC_SCM_CTRL_DECRYPT_MODE)
to = scc->black_memory;
else
to = scc->red_memory;
if (ctx->ctrl & SCC_SCM_CTRL_CBC_MODE && req->info)
memcpy(scc->base + SCC_SCM_INIT_VECTOR_0, req->info,
scc->block_size_bytes);
len = sg_pcopy_to_buffer(req->src, ctx->src_nents,
to, len, ctx->offset);
if (!len) {
dev_err(scc->dev, "pcopy err to 0x%p (len=%d)\n", to, len);
return -EINVAL;
}
ctx->size = len;
#ifdef DEBUG
dev_dbg(scc->dev, "copied %d bytes to 0x%p\n", len, to);
print_hex_dump(KERN_ERR,
"init vector0@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4,
scc->base + SCC_SCM_INIT_VECTOR_0, scc->block_size_bytes,
1);
print_hex_dump(KERN_ERR,
"red memory@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4,
scc->red_memory, ctx->size, 1);
print_hex_dump(KERN_ERR,
"black memory@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4,
scc->black_memory, ctx->size, 1);
#endif
scc->bytes_remaining -= len;
padding_byte_count = len % scc->block_size_bytes;
if (padding_byte_count) {
memcpy(padding_buffer, scc_block_padding, padding_byte_count);
memcpy(to + len, padding_buffer, padding_byte_count);
ctx->size += padding_byte_count;
}
#ifdef DEBUG
print_hex_dump(KERN_ERR,
"data to encrypt@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4,
to, ctx->size, 1);
#endif
return 0;
}
static void mxc_scc_ablkcipher_next(struct mxc_scc_ctx *ctx,
struct crypto_async_request *req)
{
struct ablkcipher_request *ablkreq = ablkcipher_request_cast(req);
struct mxc_scc *scc = ctx->scc;
int err;
dev_dbg(scc->dev, "dispatch request (nbytes=%d, src=%p, dst=%p)\n",
ablkreq->nbytes, ablkreq->src, ablkreq->dst);
writel(0, scc->base + SCC_SCM_ERROR_STATUS);
err = mxc_scc_put_data(ctx, ablkreq);
if (err) {
mxc_scc_ablkcipher_req_complete(req, ctx, err);
return;
}
dev_dbg(scc->dev, "Start encryption (0x%p/0x%p)\n",
(void *)readl(scc->base + SCC_SCM_RED_START),
(void *)readl(scc->base + SCC_SCM_BLACK_START));
writel(SCC_SCM_INTR_CTRL_CLR_INTR,
scc->base + SCC_SCM_INTR_CTRL);
writel((ctx->size / ctx->scc->block_size_bytes) - 1,
scc->base + SCC_SCM_LENGTH);
dev_dbg(scc->dev, "Process %d block(s) in 0x%p\n",
ctx->size / ctx->scc->block_size_bytes,
(ctx->ctrl & SCC_SCM_CTRL_DECRYPT_MODE) ? scc->black_memory :
scc->red_memory);
writel(ctx->ctrl, scc->base + SCC_SCM_CTRL);
}
static irqreturn_t mxc_scc_int(int irq, void *priv)
{
struct crypto_async_request *req;
struct mxc_scc_ctx *ctx;
struct mxc_scc *scc = priv;
int status;
int ret;
status = readl(scc->base + SCC_SCM_STATUS);
writel(SCC_SCM_INTR_CTRL_CLR_INTR, scc->base + SCC_SCM_INTR_CTRL);
if (status & SCC_SCM_STATUS_BUSY)
return IRQ_NONE;
req = scc->req;
if (req) {
ctx = crypto_tfm_ctx(req->tfm);
ret = mxc_scc_get_data(ctx, req);
if (ret != -EINPROGRESS)
mxc_scc_ablkcipher_req_complete(req, ctx, ret);
else
mxc_scc_ablkcipher_next(ctx, req);
}
return IRQ_HANDLED;
}
static int mxc_scc_cra_init(struct crypto_tfm *tfm)
{
struct mxc_scc_ctx *ctx = crypto_tfm_ctx(tfm);
struct crypto_alg *alg = tfm->__crt_alg;
struct mxc_scc_crypto_tmpl *algt;
algt = container_of(alg, struct mxc_scc_crypto_tmpl, alg);
ctx->scc = algt->scc;
return 0;
}
static void mxc_scc_dequeue_req_unlocked(struct mxc_scc_ctx *ctx)
{
struct crypto_async_request *req, *backlog;
if (ctx->scc->hw_busy)
return;
spin_lock_bh(&ctx->scc->lock);
backlog = crypto_get_backlog(&ctx->scc->queue);
req = crypto_dequeue_request(&ctx->scc->queue);
ctx->scc->req = req;
ctx->scc->hw_busy = true;
spin_unlock_bh(&ctx->scc->lock);
if (!req)
return;
if (backlog)
backlog->complete(backlog, -EINPROGRESS);
mxc_scc_ablkcipher_next(ctx, req);
}
static int mxc_scc_queue_req(struct mxc_scc_ctx *ctx,
struct crypto_async_request *req)
{
int ret;
spin_lock_bh(&ctx->scc->lock);
ret = crypto_enqueue_request(&ctx->scc->queue, req);
spin_unlock_bh(&ctx->scc->lock);
if (ret != -EINPROGRESS)
return ret;
mxc_scc_dequeue_req_unlocked(ctx);
return -EINPROGRESS;
}
static int mxc_scc_des3_op(struct mxc_scc_ctx *ctx,
struct ablkcipher_request *req)
{
int err;
err = mxc_scc_ablkcipher_req_init(req, ctx);
if (err)
return err;
return mxc_scc_queue_req(ctx, &req->base);
}
static int mxc_scc_ecb_des_encrypt(struct ablkcipher_request *req)
{
struct crypto_ablkcipher *cipher = crypto_ablkcipher_reqtfm(req);
struct mxc_scc_ctx *ctx = crypto_ablkcipher_ctx(cipher);
ctx->ctrl = SCC_SCM_CTRL_START_CIPHER;
return mxc_scc_des3_op(ctx, req);
}
static int mxc_scc_ecb_des_decrypt(struct ablkcipher_request *req)
{
struct crypto_ablkcipher *cipher = crypto_ablkcipher_reqtfm(req);
struct mxc_scc_ctx *ctx = crypto_ablkcipher_ctx(cipher);
ctx->ctrl = SCC_SCM_CTRL_START_CIPHER;
ctx->ctrl |= SCC_SCM_CTRL_DECRYPT_MODE;
return mxc_scc_des3_op(ctx, req);
}
static int mxc_scc_cbc_des_encrypt(struct ablkcipher_request *req)
{
struct crypto_ablkcipher *cipher = crypto_ablkcipher_reqtfm(req);
struct mxc_scc_ctx *ctx = crypto_ablkcipher_ctx(cipher);
ctx->ctrl = SCC_SCM_CTRL_START_CIPHER;
ctx->ctrl |= SCC_SCM_CTRL_CBC_MODE;
return mxc_scc_des3_op(ctx, req);
}
static int mxc_scc_cbc_des_decrypt(struct ablkcipher_request *req)
{
struct crypto_ablkcipher *cipher = crypto_ablkcipher_reqtfm(req);
struct mxc_scc_ctx *ctx = crypto_ablkcipher_ctx(cipher);
ctx->ctrl = SCC_SCM_CTRL_START_CIPHER;
ctx->ctrl |= SCC_SCM_CTRL_CBC_MODE;
ctx->ctrl |= SCC_SCM_CTRL_DECRYPT_MODE;
return mxc_scc_des3_op(ctx, req);
}
static void mxc_scc_hw_init(struct mxc_scc *scc)
{
int offset;
offset = SCC_NON_RESERVED_OFFSET / scc->block_size_bytes;
writel(offset, scc->base + SCC_SCM_RED_START);
writel(offset, scc->base + SCC_SCM_BLACK_START);
scc->red_memory = scc->base + SCC_SCM_RED_MEMORY +
SCC_NON_RESERVED_OFFSET;
scc->black_memory = scc->base + SCC_SCM_BLACK_MEMORY +
SCC_NON_RESERVED_OFFSET;
scc->bytes_remaining = scc->memory_size_bytes;
}
static int mxc_scc_get_config(struct mxc_scc *scc)
{
int config;
config = readl(scc->base + SCC_SCM_CFG);
scc->block_size_bytes = config & SCC_SCM_CFG_BLOCK_SIZE_MASK;
scc->black_ram_size_blocks = config & SCC_SCM_CFG_BLACK_SIZE_MASK;
scc->memory_size_bytes = (scc->block_size_bytes *
scc->black_ram_size_blocks) -
SCC_NON_RESERVED_OFFSET;
return 0;
}
static enum mxc_scc_state mxc_scc_get_state(struct mxc_scc *scc)
{
enum mxc_scc_state state;
int status;
status = readl(scc->base + SCC_SMN_STATUS) &
SCC_SMN_STATUS_STATE_MASK;
if (status & SCC_SMN_STATE_HEALTH_CHECK) {
writel(0xaaaa, scc->base + SCC_SMN_SEQ_START);
writel(0x5555, scc->base + SCC_SMN_SEQ_END);
writel(0x5555, scc->base + SCC_SMN_SEQ_CHECK);
status = readl(scc->base + SCC_SMN_STATUS) &
SCC_SMN_STATUS_STATE_MASK;
}
switch (status) {
case SCC_SMN_STATE_NON_SECURE:
case SCC_SMN_STATE_SECURE:
state = SCC_STATE_OK;
break;
case SCC_SMN_STATE_FAIL:
state = SCC_STATE_FAILED;
break;
default:
state = SCC_STATE_UNIMPLEMENTED;
break;
}
return state;
}
static int mxc_scc_crypto_register(struct mxc_scc *scc)
{
int i;
int err = 0;
for (i = 0; i < ARRAY_SIZE(scc_crypto_algs); i++) {
scc_crypto_algs[i]->scc = scc;
err = crypto_register_alg(&scc_crypto_algs[i]->alg);
if (err)
goto err_out;
}
return 0;
err_out:
while (--i >= 0)
crypto_unregister_alg(&scc_crypto_algs[i]->alg);
return err;
}
static void mxc_scc_crypto_unregister(void)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(scc_crypto_algs); i++)
crypto_unregister_alg(&scc_crypto_algs[i]->alg);
}
static int mxc_scc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct mxc_scc *scc;
enum mxc_scc_state state;
int irq;
int ret;
int i;
scc = devm_kzalloc(dev, sizeof(*scc), GFP_KERNEL);
if (!scc)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
scc->base = devm_ioremap_resource(dev, res);
if (IS_ERR(scc->base))
return PTR_ERR(scc->base);
scc->clk = devm_clk_get(&pdev->dev, "ipg");
if (IS_ERR(scc->clk)) {
dev_err(dev, "Could not get ipg clock\n");
return PTR_ERR(scc->clk);
}
ret = clk_prepare_enable(scc->clk);
if (ret)
return ret;
writel(0x0, scc->base + SCC_SCM_ERROR_STATUS);
writel(SCC_SCM_INTR_CTRL_CLR_INTR |
SCC_SCM_INTR_CTRL_MASK_INTR,
scc->base + SCC_SCM_INTR_CTRL);
writel(SCC_SMN_COMMAND_CLR_INTR |
SCC_SMN_COMMAND_EN_INTR,
scc->base + SCC_SMN_COMMAND);
scc->dev = dev;
platform_set_drvdata(pdev, scc);
ret = mxc_scc_get_config(scc);
if (ret)
goto err_out;
state = mxc_scc_get_state(scc);
if (state != SCC_STATE_OK) {
dev_err(dev, "SCC in unusable state %d\n", state);
ret = -EINVAL;
goto err_out;
}
mxc_scc_hw_init(scc);
spin_lock_init(&scc->lock);
crypto_init_queue(&scc->queue, 50);
for (i = 0; i < 2; i++) {
irq = platform_get_irq(pdev, i);
if (irq < 0) {
dev_err(dev, "failed to get irq resource\n");
ret = -EINVAL;
goto err_out;
}
ret = devm_request_threaded_irq(dev, irq, NULL, mxc_scc_int,
IRQF_ONESHOT, dev_name(dev), scc);
if (ret)
goto err_out;
}
ret = mxc_scc_crypto_register(scc);
if (ret) {
dev_err(dev, "could not register algorithms");
goto err_out;
}
dev_info(dev, "registered successfully.\n");
return 0;
err_out:
clk_disable_unprepare(scc->clk);
return ret;
}
static int mxc_scc_remove(struct platform_device *pdev)
{
struct mxc_scc *scc = platform_get_drvdata(pdev);
mxc_scc_crypto_unregister();
clk_disable_unprepare(scc->clk);
return 0;
}
