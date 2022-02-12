static inline struct samsung_aes_variant *find_s5p_sss_version
(struct platform_device *pdev)
{
if (IS_ENABLED(CONFIG_OF) && (pdev->dev.of_node)) {
const struct of_device_id *match;
match = of_match_node(s5p_sss_dt_match,
pdev->dev.of_node);
return (struct samsung_aes_variant *)match->data;
}
return (struct samsung_aes_variant *)
platform_get_device_id(pdev)->driver_data;
}
static void s5p_set_dma_indata(struct s5p_aes_dev *dev, struct scatterlist *sg)
{
SSS_WRITE(dev, FCBRDMAS, sg_dma_address(sg));
SSS_WRITE(dev, FCBRDMAL, sg_dma_len(sg));
}
static void s5p_set_dma_outdata(struct s5p_aes_dev *dev, struct scatterlist *sg)
{
SSS_WRITE(dev, FCBTDMAS, sg_dma_address(sg));
SSS_WRITE(dev, FCBTDMAL, sg_dma_len(sg));
}
static void s5p_free_sg_cpy(struct s5p_aes_dev *dev, struct scatterlist **sg)
{
int len;
if (!*sg)
return;
len = ALIGN(dev->req->nbytes, AES_BLOCK_SIZE);
free_pages((unsigned long)sg_virt(*sg), get_order(len));
kfree(*sg);
*sg = NULL;
}
static void s5p_sg_copy_buf(void *buf, struct scatterlist *sg,
unsigned int nbytes, int out)
{
struct scatter_walk walk;
if (!nbytes)
return;
scatterwalk_start(&walk, sg);
scatterwalk_copychunks(buf, &walk, nbytes, out);
scatterwalk_done(&walk, out, 0);
}
static void s5p_aes_complete(struct s5p_aes_dev *dev, int err)
{
if (dev->sg_dst_cpy) {
dev_dbg(dev->dev,
"Copying %d bytes of output data back to original place\n",
dev->req->nbytes);
s5p_sg_copy_buf(sg_virt(dev->sg_dst_cpy), dev->req->dst,
dev->req->nbytes, 1);
}
s5p_free_sg_cpy(dev, &dev->sg_src_cpy);
s5p_free_sg_cpy(dev, &dev->sg_dst_cpy);
dev->req->base.complete(&dev->req->base, err);
dev->busy = false;
}
static void s5p_unset_outdata(struct s5p_aes_dev *dev)
{
dma_unmap_sg(dev->dev, dev->sg_dst, 1, DMA_FROM_DEVICE);
}
static void s5p_unset_indata(struct s5p_aes_dev *dev)
{
dma_unmap_sg(dev->dev, dev->sg_src, 1, DMA_TO_DEVICE);
}
static int s5p_make_sg_cpy(struct s5p_aes_dev *dev, struct scatterlist *src,
struct scatterlist **dst)
{
void *pages;
int len;
*dst = kmalloc(sizeof(**dst), GFP_ATOMIC);
if (!*dst)
return -ENOMEM;
len = ALIGN(dev->req->nbytes, AES_BLOCK_SIZE);
pages = (void *)__get_free_pages(GFP_ATOMIC, get_order(len));
if (!pages) {
kfree(*dst);
*dst = NULL;
return -ENOMEM;
}
s5p_sg_copy_buf(pages, src, dev->req->nbytes, 0);
sg_init_table(*dst, 1);
sg_set_buf(*dst, pages, len);
return 0;
}
static int s5p_set_outdata(struct s5p_aes_dev *dev, struct scatterlist *sg)
{
int err;
if (!sg->length) {
err = -EINVAL;
goto exit;
}
err = dma_map_sg(dev->dev, sg, 1, DMA_FROM_DEVICE);
if (!err) {
err = -ENOMEM;
goto exit;
}
dev->sg_dst = sg;
err = 0;
exit:
return err;
}
static int s5p_set_indata(struct s5p_aes_dev *dev, struct scatterlist *sg)
{
int err;
if (!sg->length) {
err = -EINVAL;
goto exit;
}
err = dma_map_sg(dev->dev, sg, 1, DMA_TO_DEVICE);
if (!err) {
err = -ENOMEM;
goto exit;
}
dev->sg_src = sg;
err = 0;
exit:
return err;
}
static bool s5p_aes_tx(struct s5p_aes_dev *dev)
{
int err = 0;
bool ret = false;
s5p_unset_outdata(dev);
if (!sg_is_last(dev->sg_dst)) {
err = s5p_set_outdata(dev, sg_next(dev->sg_dst));
if (err)
s5p_aes_complete(dev, err);
else
ret = true;
} else {
s5p_aes_complete(dev, err);
dev->busy = true;
tasklet_schedule(&dev->tasklet);
}
return ret;
}
static bool s5p_aes_rx(struct s5p_aes_dev *dev)
{
int err;
bool ret = false;
s5p_unset_indata(dev);
if (!sg_is_last(dev->sg_src)) {
err = s5p_set_indata(dev, sg_next(dev->sg_src));
if (err)
s5p_aes_complete(dev, err);
else
ret = true;
}
return ret;
}
static irqreturn_t s5p_aes_interrupt(int irq, void *dev_id)
{
struct platform_device *pdev = dev_id;
struct s5p_aes_dev *dev = platform_get_drvdata(pdev);
uint32_t status;
unsigned long flags;
bool set_dma_tx = false;
bool set_dma_rx = false;
spin_lock_irqsave(&dev->lock, flags);
status = SSS_READ(dev, FCINTSTAT);
if (status & SSS_FCINTSTAT_BRDMAINT)
set_dma_rx = s5p_aes_rx(dev);
if (status & SSS_FCINTSTAT_BTDMAINT)
set_dma_tx = s5p_aes_tx(dev);
SSS_WRITE(dev, FCINTPEND, status);
if (set_dma_tx)
s5p_set_dma_outdata(dev, dev->sg_dst);
if (set_dma_rx)
s5p_set_dma_indata(dev, dev->sg_src);
spin_unlock_irqrestore(&dev->lock, flags);
return IRQ_HANDLED;
}
static void s5p_set_aes(struct s5p_aes_dev *dev,
uint8_t *key, uint8_t *iv, unsigned int keylen)
{
void __iomem *keystart;
if (iv)
memcpy_toio(dev->aes_ioaddr + SSS_REG_AES_IV_DATA(0), iv, 0x10);
if (keylen == AES_KEYSIZE_256)
keystart = dev->aes_ioaddr + SSS_REG_AES_KEY_DATA(0);
else if (keylen == AES_KEYSIZE_192)
keystart = dev->aes_ioaddr + SSS_REG_AES_KEY_DATA(2);
else
keystart = dev->aes_ioaddr + SSS_REG_AES_KEY_DATA(4);
memcpy_toio(keystart, key, keylen);
}
static bool s5p_is_sg_aligned(struct scatterlist *sg)
{
while (sg) {
if (!IS_ALIGNED(sg->length, AES_BLOCK_SIZE))
return false;
sg = sg_next(sg);
}
return true;
}
static int s5p_set_indata_start(struct s5p_aes_dev *dev,
struct ablkcipher_request *req)
{
struct scatterlist *sg;
int err;
dev->sg_src_cpy = NULL;
sg = req->src;
if (!s5p_is_sg_aligned(sg)) {
dev_dbg(dev->dev,
"At least one unaligned source scatter list, making a copy\n");
err = s5p_make_sg_cpy(dev, sg, &dev->sg_src_cpy);
if (err)
return err;
sg = dev->sg_src_cpy;
}
err = s5p_set_indata(dev, sg);
if (err) {
s5p_free_sg_cpy(dev, &dev->sg_src_cpy);
return err;
}
return 0;
}
static int s5p_set_outdata_start(struct s5p_aes_dev *dev,
struct ablkcipher_request *req)
{
struct scatterlist *sg;
int err;
dev->sg_dst_cpy = NULL;
sg = req->dst;
if (!s5p_is_sg_aligned(sg)) {
dev_dbg(dev->dev,
"At least one unaligned dest scatter list, making a copy\n");
err = s5p_make_sg_cpy(dev, sg, &dev->sg_dst_cpy);
if (err)
return err;
sg = dev->sg_dst_cpy;
}
err = s5p_set_outdata(dev, sg);
if (err) {
s5p_free_sg_cpy(dev, &dev->sg_dst_cpy);
return err;
}
return 0;
}
static void s5p_aes_crypt_start(struct s5p_aes_dev *dev, unsigned long mode)
{
struct ablkcipher_request *req = dev->req;
uint32_t aes_control;
int err;
unsigned long flags;
aes_control = SSS_AES_KEY_CHANGE_MODE;
if (mode & FLAGS_AES_DECRYPT)
aes_control |= SSS_AES_MODE_DECRYPT;
if ((mode & FLAGS_AES_MODE_MASK) == FLAGS_AES_CBC)
aes_control |= SSS_AES_CHAIN_MODE_CBC;
else if ((mode & FLAGS_AES_MODE_MASK) == FLAGS_AES_CTR)
aes_control |= SSS_AES_CHAIN_MODE_CTR;
if (dev->ctx->keylen == AES_KEYSIZE_192)
aes_control |= SSS_AES_KEY_SIZE_192;
else if (dev->ctx->keylen == AES_KEYSIZE_256)
aes_control |= SSS_AES_KEY_SIZE_256;
aes_control |= SSS_AES_FIFO_MODE;
aes_control |= SSS_AES_BYTESWAP_DI
| SSS_AES_BYTESWAP_DO
| SSS_AES_BYTESWAP_IV
| SSS_AES_BYTESWAP_KEY
| SSS_AES_BYTESWAP_CNT;
spin_lock_irqsave(&dev->lock, flags);
SSS_WRITE(dev, FCINTENCLR,
SSS_FCINTENCLR_BTDMAINTENCLR | SSS_FCINTENCLR_BRDMAINTENCLR);
SSS_WRITE(dev, FCFIFOCTRL, 0x00);
err = s5p_set_indata_start(dev, req);
if (err)
goto indata_error;
err = s5p_set_outdata_start(dev, req);
if (err)
goto outdata_error;
SSS_AES_WRITE(dev, AES_CONTROL, aes_control);
s5p_set_aes(dev, dev->ctx->aes_key, req->info, dev->ctx->keylen);
s5p_set_dma_indata(dev, dev->sg_src);
s5p_set_dma_outdata(dev, dev->sg_dst);
SSS_WRITE(dev, FCINTENSET,
SSS_FCINTENSET_BTDMAINTENSET | SSS_FCINTENSET_BRDMAINTENSET);
spin_unlock_irqrestore(&dev->lock, flags);
return;
outdata_error:
s5p_unset_indata(dev);
indata_error:
s5p_aes_complete(dev, err);
spin_unlock_irqrestore(&dev->lock, flags);
}
static void s5p_tasklet_cb(unsigned long data)
{
struct s5p_aes_dev *dev = (struct s5p_aes_dev *)data;
struct crypto_async_request *async_req, *backlog;
struct s5p_aes_reqctx *reqctx;
unsigned long flags;
spin_lock_irqsave(&dev->lock, flags);
backlog = crypto_get_backlog(&dev->queue);
async_req = crypto_dequeue_request(&dev->queue);
if (!async_req) {
dev->busy = false;
spin_unlock_irqrestore(&dev->lock, flags);
return;
}
spin_unlock_irqrestore(&dev->lock, flags);
if (backlog)
backlog->complete(backlog, -EINPROGRESS);
dev->req = ablkcipher_request_cast(async_req);
dev->ctx = crypto_tfm_ctx(dev->req->base.tfm);
reqctx = ablkcipher_request_ctx(dev->req);
s5p_aes_crypt_start(dev, reqctx->mode);
}
static int s5p_aes_handle_req(struct s5p_aes_dev *dev,
struct ablkcipher_request *req)
{
unsigned long flags;
int err;
spin_lock_irqsave(&dev->lock, flags);
err = ablkcipher_enqueue_request(&dev->queue, req);
if (dev->busy) {
spin_unlock_irqrestore(&dev->lock, flags);
goto exit;
}
dev->busy = true;
spin_unlock_irqrestore(&dev->lock, flags);
tasklet_schedule(&dev->tasklet);
exit:
return err;
}
static int s5p_aes_crypt(struct ablkcipher_request *req, unsigned long mode)
{
struct crypto_ablkcipher *tfm = crypto_ablkcipher_reqtfm(req);
struct s5p_aes_ctx *ctx = crypto_ablkcipher_ctx(tfm);
struct s5p_aes_reqctx *reqctx = ablkcipher_request_ctx(req);
struct s5p_aes_dev *dev = ctx->dev;
if (!IS_ALIGNED(req->nbytes, AES_BLOCK_SIZE)) {
dev_err(dev->dev, "request size is not exact amount of AES blocks\n");
return -EINVAL;
}
reqctx->mode = mode;
return s5p_aes_handle_req(dev, req);
}
static int s5p_aes_setkey(struct crypto_ablkcipher *cipher,
const uint8_t *key, unsigned int keylen)
{
struct crypto_tfm *tfm = crypto_ablkcipher_tfm(cipher);
struct s5p_aes_ctx *ctx = crypto_tfm_ctx(tfm);
if (keylen != AES_KEYSIZE_128 &&
keylen != AES_KEYSIZE_192 &&
keylen != AES_KEYSIZE_256)
return -EINVAL;
memcpy(ctx->aes_key, key, keylen);
ctx->keylen = keylen;
return 0;
}
static int s5p_aes_ecb_encrypt(struct ablkcipher_request *req)
{
return s5p_aes_crypt(req, 0);
}
static int s5p_aes_ecb_decrypt(struct ablkcipher_request *req)
{
return s5p_aes_crypt(req, FLAGS_AES_DECRYPT);
}
static int s5p_aes_cbc_encrypt(struct ablkcipher_request *req)
{
return s5p_aes_crypt(req, FLAGS_AES_CBC);
}
static int s5p_aes_cbc_decrypt(struct ablkcipher_request *req)
{
return s5p_aes_crypt(req, FLAGS_AES_DECRYPT | FLAGS_AES_CBC);
}
static int s5p_aes_cra_init(struct crypto_tfm *tfm)
{
struct s5p_aes_ctx *ctx = crypto_tfm_ctx(tfm);
ctx->dev = s5p_dev;
tfm->crt_ablkcipher.reqsize = sizeof(struct s5p_aes_reqctx);
return 0;
}
static int s5p_aes_probe(struct platform_device *pdev)
{
int i, j, err = -ENODEV;
struct s5p_aes_dev *pdata;
struct device *dev = &pdev->dev;
struct resource *res;
struct samsung_aes_variant *variant;
if (s5p_dev)
return -EEXIST;
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pdata->ioaddr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pdata->ioaddr))
return PTR_ERR(pdata->ioaddr);
variant = find_s5p_sss_version(pdev);
pdata->clk = devm_clk_get(dev, "secss");
if (IS_ERR(pdata->clk)) {
dev_err(dev, "failed to find secss clock source\n");
return -ENOENT;
}
err = clk_prepare_enable(pdata->clk);
if (err < 0) {
dev_err(dev, "Enabling SSS clk failed, err %d\n", err);
return err;
}
spin_lock_init(&pdata->lock);
pdata->aes_ioaddr = pdata->ioaddr + variant->aes_offset;
pdata->irq_fc = platform_get_irq(pdev, 0);
if (pdata->irq_fc < 0) {
err = pdata->irq_fc;
dev_warn(dev, "feed control interrupt is not available.\n");
goto err_irq;
}
err = devm_request_irq(dev, pdata->irq_fc, s5p_aes_interrupt,
IRQF_SHARED, pdev->name, pdev);
if (err < 0) {
dev_warn(dev, "feed control interrupt is not available.\n");
goto err_irq;
}
pdata->busy = false;
pdata->variant = variant;
pdata->dev = dev;
platform_set_drvdata(pdev, pdata);
s5p_dev = pdata;
tasklet_init(&pdata->tasklet, s5p_tasklet_cb, (unsigned long)pdata);
crypto_init_queue(&pdata->queue, CRYPTO_QUEUE_LEN);
for (i = 0; i < ARRAY_SIZE(algs); i++) {
err = crypto_register_alg(&algs[i]);
if (err)
goto err_algs;
}
dev_info(dev, "s5p-sss driver registered\n");
return 0;
err_algs:
dev_err(dev, "can't register '%s': %d\n", algs[i].cra_name, err);
for (j = 0; j < i; j++)
crypto_unregister_alg(&algs[j]);
tasklet_kill(&pdata->tasklet);
err_irq:
clk_disable_unprepare(pdata->clk);
s5p_dev = NULL;
return err;
}
static int s5p_aes_remove(struct platform_device *pdev)
{
struct s5p_aes_dev *pdata = platform_get_drvdata(pdev);
int i;
if (!pdata)
return -ENODEV;
for (i = 0; i < ARRAY_SIZE(algs); i++)
crypto_unregister_alg(&algs[i]);
tasklet_kill(&pdata->tasklet);
clk_disable_unprepare(pdata->clk);
s5p_dev = NULL;
return 0;
}
