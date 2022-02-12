static int stm32_crc32_cra_init(struct crypto_tfm *tfm)
{
struct stm32_crc_ctx *mctx = crypto_tfm_ctx(tfm);
mctx->key = CRC_INIT_DEFAULT;
mctx->poly = POLY_CRC32;
return 0;
}
static int stm32_crc32c_cra_init(struct crypto_tfm *tfm)
{
struct stm32_crc_ctx *mctx = crypto_tfm_ctx(tfm);
mctx->key = CRC_INIT_DEFAULT;
mctx->poly = POLY_CRC32C;
return 0;
}
static int stm32_crc_setkey(struct crypto_shash *tfm, const u8 *key,
unsigned int keylen)
{
struct stm32_crc_ctx *mctx = crypto_shash_ctx(tfm);
if (keylen != sizeof(u32)) {
crypto_shash_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
mctx->key = get_unaligned_le32(key);
return 0;
}
static int stm32_crc_init(struct shash_desc *desc)
{
struct stm32_crc_desc_ctx *ctx = shash_desc_ctx(desc);
struct stm32_crc_ctx *mctx = crypto_shash_ctx(desc->tfm);
struct stm32_crc *crc;
spin_lock_bh(&crc_list.lock);
list_for_each_entry(crc, &crc_list.dev_list, list) {
ctx->crc = crc;
break;
}
spin_unlock_bh(&crc_list.lock);
writel_relaxed(bitrev32(mctx->key), ctx->crc->regs + CRC_INIT);
writel_relaxed(bitrev32(mctx->poly), ctx->crc->regs + CRC_POL);
writel_relaxed(CRC_CR_RESET | CRC_CR_REVERSE, ctx->crc->regs + CRC_CR);
ctx->partial = readl_relaxed(ctx->crc->regs + CRC_DR);
ctx->crc->nb_pending_bytes = 0;
return 0;
}
static int stm32_crc_update(struct shash_desc *desc, const u8 *d8,
unsigned int length)
{
struct stm32_crc_desc_ctx *ctx = shash_desc_ctx(desc);
struct stm32_crc *crc = ctx->crc;
u32 *d32;
unsigned int i;
if (unlikely(crc->nb_pending_bytes)) {
while (crc->nb_pending_bytes != sizeof(u32) && length) {
crc->pending_data[crc->nb_pending_bytes++] = *(d8++);
length--;
}
if (crc->nb_pending_bytes == sizeof(u32)) {
writel_relaxed(*(u32 *)crc->pending_data,
crc->regs + CRC_DR);
crc->nb_pending_bytes = 0;
}
}
d32 = (u32 *)d8;
for (i = 0; i < length >> 2; i++)
writel_relaxed(*(d32++), crc->regs + CRC_DR);
ctx->partial = readl_relaxed(crc->regs + CRC_DR);
length &= 3;
if (likely(!length))
return 0;
if ((crc->nb_pending_bytes + length) >= sizeof(u32)) {
dev_err(crc->dev, "Pending data overflow\n");
return -EINVAL;
}
d8 = (const u8 *)d32;
for (i = 0; i < length; i++)
crc->pending_data[crc->nb_pending_bytes++] = *(d8++);
return 0;
}
static int stm32_crc_final(struct shash_desc *desc, u8 *out)
{
struct stm32_crc_desc_ctx *ctx = shash_desc_ctx(desc);
struct stm32_crc_ctx *mctx = crypto_shash_ctx(desc->tfm);
put_unaligned_le32(mctx->poly == POLY_CRC32C ?
~ctx->partial : ctx->partial, out);
return 0;
}
static int stm32_crc_finup(struct shash_desc *desc, const u8 *data,
unsigned int length, u8 *out)
{
return stm32_crc_update(desc, data, length) ?:
stm32_crc_final(desc, out);
}
static int stm32_crc_digest(struct shash_desc *desc, const u8 *data,
unsigned int length, u8 *out)
{
return stm32_crc_init(desc) ?: stm32_crc_finup(desc, data, length, out);
}
static int stm32_crc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct stm32_crc *crc;
struct resource *res;
int ret;
crc = devm_kzalloc(dev, sizeof(*crc), GFP_KERNEL);
if (!crc)
return -ENOMEM;
crc->dev = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
crc->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(crc->regs)) {
dev_err(dev, "Cannot map CRC IO\n");
return PTR_ERR(crc->regs);
}
crc->clk = devm_clk_get(dev, NULL);
if (IS_ERR(crc->clk)) {
dev_err(dev, "Could not get clock\n");
return PTR_ERR(crc->clk);
}
ret = clk_prepare_enable(crc->clk);
if (ret) {
dev_err(crc->dev, "Failed to enable clock\n");
return ret;
}
platform_set_drvdata(pdev, crc);
spin_lock(&crc_list.lock);
list_add(&crc->list, &crc_list.dev_list);
spin_unlock(&crc_list.lock);
ret = crypto_register_shashes(algs, ARRAY_SIZE(algs));
if (ret) {
dev_err(dev, "Failed to register\n");
clk_disable_unprepare(crc->clk);
return ret;
}
dev_info(dev, "Initialized\n");
return 0;
}
static int stm32_crc_remove(struct platform_device *pdev)
{
struct stm32_crc *crc = platform_get_drvdata(pdev);
spin_lock(&crc_list.lock);
list_del(&crc->list);
spin_unlock(&crc_list.lock);
crypto_unregister_shashes(algs, ARRAY_SIZE(algs));
clk_disable_unprepare(crc->clk);
return 0;
}
