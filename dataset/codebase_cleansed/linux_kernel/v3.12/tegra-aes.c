static inline u32 aes_readl(struct tegra_aes_dev *dd, u32 offset)
{
return readl(dd->io_base + offset);
}
static inline void aes_writel(struct tegra_aes_dev *dd, u32 val, u32 offset)
{
writel(val, dd->io_base + offset);
}
static int aes_start_crypt(struct tegra_aes_dev *dd, u32 in_addr, u32 out_addr,
int nblocks, int mode, bool upd_iv)
{
u32 cmdq[AES_HW_MAX_ICQ_LENGTH];
int i, eng_busy, icq_empty, ret;
u32 value;
aes_writel(dd, 0xFFFFFFFF, TEGRA_AES_INTR_STATUS);
aes_writel(dd, 0x33, TEGRA_AES_INT_ENB);
cmdq[0] = CMD_DMASETUP << CMDQ_OPCODE_SHIFT;
cmdq[1] = in_addr;
cmdq[2] = CMD_BLKSTARTENGINE << CMDQ_OPCODE_SHIFT | (nblocks-1);
cmdq[3] = CMD_DMACOMPLETE << CMDQ_OPCODE_SHIFT;
value = aes_readl(dd, TEGRA_AES_CMDQUE_CONTROL);
value &= ~TEGRA_AES_CMDQ_CTRL_SRC_STM_SEL_FIELD;
value &= ~TEGRA_AES_CMDQ_CTRL_DST_STM_SEL_FIELD;
value |= TEGRA_AES_CMDQ_CTRL_SRC_STM_SEL_FIELD |
TEGRA_AES_CMDQ_CTRL_DST_STM_SEL_FIELD |
TEGRA_AES_CMDQ_CTRL_ICMDQEN_FIELD;
aes_writel(dd, value, TEGRA_AES_CMDQUE_CONTROL);
dev_dbg(dd->dev, "cmd_q_ctrl=0x%x", value);
value = (0x1 << TEGRA_AES_SECURE_INPUT_ALG_SEL_SHIFT) |
((dd->ctx->keylen * 8) <<
TEGRA_AES_SECURE_INPUT_KEY_LEN_SHIFT) |
((u32)upd_iv << TEGRA_AES_SECURE_IV_SELECT_SHIFT);
if (mode & FLAGS_CBC) {
value |= ((((mode & FLAGS_ENCRYPT) ? 2 : 3)
<< TEGRA_AES_SECURE_XOR_POS_SHIFT) |
(((mode & FLAGS_ENCRYPT) ? 2 : 3)
<< TEGRA_AES_SECURE_VCTRAM_SEL_SHIFT) |
((mode & FLAGS_ENCRYPT) ? 1 : 0)
<< TEGRA_AES_SECURE_CORE_SEL_SHIFT);
} else if (mode & FLAGS_OFB) {
value |= ((TEGRA_AES_SECURE_XOR_POS_FIELD) |
(2 << TEGRA_AES_SECURE_INPUT_SEL_SHIFT) |
(TEGRA_AES_SECURE_CORE_SEL_FIELD));
} else if (mode & FLAGS_RNG) {
value |= (((mode & FLAGS_ENCRYPT) ? 1 : 0)
<< TEGRA_AES_SECURE_CORE_SEL_SHIFT |
TEGRA_AES_SECURE_RNG_ENB_FIELD);
} else {
value |= (((mode & FLAGS_ENCRYPT) ? 1 : 0)
<< TEGRA_AES_SECURE_CORE_SEL_SHIFT);
}
dev_dbg(dd->dev, "secure_in_sel=0x%x", value);
aes_writel(dd, value, TEGRA_AES_SECURE_INPUT_SELECT);
aes_writel(dd, out_addr, TEGRA_AES_SECURE_DEST_ADDR);
INIT_COMPLETION(dd->op_complete);
for (i = 0; i < AES_HW_MAX_ICQ_LENGTH - 1; i++) {
do {
value = aes_readl(dd, TEGRA_AES_INTR_STATUS);
eng_busy = value & TEGRA_AES_ENGINE_BUSY_FIELD;
icq_empty = value & TEGRA_AES_ICQ_EMPTY_FIELD;
} while (eng_busy && !icq_empty);
aes_writel(dd, cmdq[i], TEGRA_AES_ICMDQUE_WR);
}
ret = wait_for_completion_timeout(&dd->op_complete,
msecs_to_jiffies(150));
if (ret == 0) {
dev_err(dd->dev, "timed out (0x%x)\n",
aes_readl(dd, TEGRA_AES_INTR_STATUS));
return -ETIMEDOUT;
}
aes_writel(dd, cmdq[AES_HW_MAX_ICQ_LENGTH - 1], TEGRA_AES_ICMDQUE_WR);
return 0;
}
static void aes_release_key_slot(struct tegra_aes_slot *slot)
{
if (slot->slot_num == SSK_SLOT_NUM)
return;
spin_lock(&list_lock);
list_add_tail(&slot->node, &dev_list);
slot = NULL;
spin_unlock(&list_lock);
}
static struct tegra_aes_slot *aes_find_key_slot(void)
{
struct tegra_aes_slot *slot = NULL;
struct list_head *new_head;
int empty;
spin_lock(&list_lock);
empty = list_empty(&dev_list);
if (!empty) {
slot = list_entry(&dev_list, struct tegra_aes_slot, node);
new_head = dev_list.next;
list_del(&dev_list);
dev_list.next = new_head->next;
dev_list.prev = NULL;
}
spin_unlock(&list_lock);
return slot;
}
static int aes_set_key(struct tegra_aes_dev *dd)
{
u32 value, cmdq[2];
struct tegra_aes_ctx *ctx = dd->ctx;
int eng_busy, icq_empty, dma_busy;
bool use_ssk = false;
if (!dd->ctx->slot) {
dev_dbg(dd->dev, "using ssk");
dd->ctx->slot = &ssk;
use_ssk = true;
}
value = aes_readl(dd, TEGRA_AES_SECURE_CONFIG_EXT);
value &= ~TEGRA_AES_SECURE_KEY_SCH_DIS_FIELD;
aes_writel(dd, value, TEGRA_AES_SECURE_CONFIG_EXT);
value = aes_readl(dd, TEGRA_AES_SECURE_CONFIG);
value &= ~TEGRA_AES_SECURE_KEY_INDEX_FIELD;
value |= (ctx->slot->slot_num << TEGRA_AES_SECURE_KEY_INDEX_SHIFT);
aes_writel(dd, value, TEGRA_AES_SECURE_CONFIG);
if (use_ssk)
return 0;
cmdq[0] = CMD_MEMDMAVD << CMDQ_OPCODE_SHIFT |
MEMDMA_DIR_DTOVRAM << MEMDMA_DIR_SHIFT |
AES_HW_KEY_TABLE_LENGTH_BYTES / sizeof(u32) <<
MEMDMA_NUM_WORDS_SHIFT;
cmdq[1] = (u32)dd->ivkey_phys_base;
aes_writel(dd, cmdq[0], TEGRA_AES_ICMDQUE_WR);
aes_writel(dd, cmdq[1], TEGRA_AES_ICMDQUE_WR);
do {
value = aes_readl(dd, TEGRA_AES_INTR_STATUS);
eng_busy = value & TEGRA_AES_ENGINE_BUSY_FIELD;
icq_empty = value & TEGRA_AES_ICQ_EMPTY_FIELD;
dma_busy = value & TEGRA_AES_DMA_BUSY_FIELD;
} while (eng_busy && !icq_empty && dma_busy);
value = CMD_SETTABLE << CMDQ_OPCODE_SHIFT |
SUBCMD_CRYPTO_TABLE_SEL << CMDQ_TABLESEL_SHIFT |
SUBCMD_VRAM_SEL << CMDQ_VRAMSEL_SHIFT |
(SUBCMD_KEY_TABLE_SEL | ctx->slot->slot_num) <<
CMDQ_KEYTABLEID_SHIFT;
aes_writel(dd, value, TEGRA_AES_ICMDQUE_WR);
do {
value = aes_readl(dd, TEGRA_AES_INTR_STATUS);
eng_busy = value & TEGRA_AES_ENGINE_BUSY_FIELD;
icq_empty = value & TEGRA_AES_ICQ_EMPTY_FIELD;
} while (eng_busy && !icq_empty);
return 0;
}
static int tegra_aes_handle_req(struct tegra_aes_dev *dd)
{
struct crypto_async_request *async_req, *backlog;
struct crypto_ablkcipher *tfm;
struct tegra_aes_ctx *ctx;
struct tegra_aes_reqctx *rctx;
struct ablkcipher_request *req;
unsigned long flags;
int dma_max = AES_HW_DMA_BUFFER_SIZE_BYTES;
int ret = 0, nblocks, total;
int count = 0;
dma_addr_t addr_in, addr_out;
struct scatterlist *in_sg, *out_sg;
if (!dd)
return -EINVAL;
spin_lock_irqsave(&dd->lock, flags);
backlog = crypto_get_backlog(&dd->queue);
async_req = crypto_dequeue_request(&dd->queue);
if (!async_req)
clear_bit(FLAGS_BUSY, &dd->flags);
spin_unlock_irqrestore(&dd->lock, flags);
if (!async_req)
return -ENODATA;
if (backlog)
backlog->complete(backlog, -EINPROGRESS);
req = ablkcipher_request_cast(async_req);
dev_dbg(dd->dev, "%s: get new req\n", __func__);
if (!req->src || !req->dst)
return -EINVAL;
mutex_lock(&aes_lock);
dd->req = req;
dd->total = req->nbytes;
dd->in_offset = 0;
dd->in_sg = req->src;
dd->out_offset = 0;
dd->out_sg = req->dst;
in_sg = dd->in_sg;
out_sg = dd->out_sg;
total = dd->total;
tfm = crypto_ablkcipher_reqtfm(req);
rctx = ablkcipher_request_ctx(req);
ctx = crypto_ablkcipher_ctx(tfm);
rctx->mode &= FLAGS_MODE_MASK;
dd->flags = (dd->flags & ~FLAGS_MODE_MASK) | rctx->mode;
dd->iv = (u8 *)req->info;
dd->ivlen = crypto_ablkcipher_ivsize(tfm);
ctx->dd = dd;
dd->ctx = ctx;
if (ctx->flags & FLAGS_NEW_KEY) {
memcpy(dd->ivkey_base, ctx->key, ctx->keylen);
memset(dd->ivkey_base + ctx->keylen, 0, AES_HW_KEY_TABLE_LENGTH_BYTES - ctx->keylen);
aes_set_key(dd);
ctx->flags &= ~FLAGS_NEW_KEY;
}
if (((dd->flags & FLAGS_CBC) || (dd->flags & FLAGS_OFB)) && dd->iv) {
memcpy(dd->buf_in, dd->iv, dd->ivlen);
ret = aes_start_crypt(dd, (u32)dd->dma_buf_in,
dd->dma_buf_out, 1, FLAGS_CBC, false);
if (ret < 0) {
dev_err(dd->dev, "aes_start_crypt fail(%d)\n", ret);
goto out;
}
}
while (total) {
dev_dbg(dd->dev, "remain: %d\n", total);
ret = dma_map_sg(dd->dev, in_sg, 1, DMA_TO_DEVICE);
if (!ret) {
dev_err(dd->dev, "dma_map_sg() error\n");
goto out;
}
ret = dma_map_sg(dd->dev, out_sg, 1, DMA_FROM_DEVICE);
if (!ret) {
dev_err(dd->dev, "dma_map_sg() error\n");
dma_unmap_sg(dd->dev, dd->in_sg,
1, DMA_TO_DEVICE);
goto out;
}
addr_in = sg_dma_address(in_sg);
addr_out = sg_dma_address(out_sg);
dd->flags |= FLAGS_FAST;
count = min_t(int, sg_dma_len(in_sg), dma_max);
WARN_ON(sg_dma_len(in_sg) != sg_dma_len(out_sg));
nblocks = DIV_ROUND_UP(count, AES_BLOCK_SIZE);
ret = aes_start_crypt(dd, addr_in, addr_out, nblocks,
dd->flags, true);
dma_unmap_sg(dd->dev, out_sg, 1, DMA_FROM_DEVICE);
dma_unmap_sg(dd->dev, in_sg, 1, DMA_TO_DEVICE);
if (ret < 0) {
dev_err(dd->dev, "aes_start_crypt fail(%d)\n", ret);
goto out;
}
dd->flags &= ~FLAGS_FAST;
dev_dbg(dd->dev, "out: copied %d\n", count);
total -= count;
in_sg = sg_next(in_sg);
out_sg = sg_next(out_sg);
WARN_ON(((total != 0) && (!in_sg || !out_sg)));
}
out:
mutex_unlock(&aes_lock);
dd->total = total;
if (dd->req->base.complete)
dd->req->base.complete(&dd->req->base, ret);
dev_dbg(dd->dev, "%s: exit\n", __func__);
return ret;
}
static int tegra_aes_setkey(struct crypto_ablkcipher *tfm, const u8 *key,
unsigned int keylen)
{
struct tegra_aes_ctx *ctx = crypto_ablkcipher_ctx(tfm);
struct tegra_aes_dev *dd = aes_dev;
struct tegra_aes_slot *key_slot;
if ((keylen != AES_KEYSIZE_128) && (keylen != AES_KEYSIZE_192) &&
(keylen != AES_KEYSIZE_256)) {
dev_err(dd->dev, "unsupported key size\n");
crypto_ablkcipher_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
dev_dbg(dd->dev, "keylen: %d\n", keylen);
ctx->dd = dd;
if (key) {
if (!ctx->slot) {
key_slot = aes_find_key_slot();
if (!key_slot) {
dev_err(dd->dev, "no empty slot\n");
return -ENOMEM;
}
ctx->slot = key_slot;
}
memcpy(ctx->key, key, keylen);
ctx->keylen = keylen;
}
ctx->flags |= FLAGS_NEW_KEY;
dev_dbg(dd->dev, "done\n");
return 0;
}
static void aes_workqueue_handler(struct work_struct *work)
{
struct tegra_aes_dev *dd = aes_dev;
int ret;
ret = clk_prepare_enable(dd->aes_clk);
if (ret)
BUG_ON("clock enable failed");
do {
ret = tegra_aes_handle_req(dd);
} while (!ret);
clk_disable_unprepare(dd->aes_clk);
}
static irqreturn_t aes_irq(int irq, void *dev_id)
{
struct tegra_aes_dev *dd = (struct tegra_aes_dev *)dev_id;
u32 value = aes_readl(dd, TEGRA_AES_INTR_STATUS);
int busy = test_bit(FLAGS_BUSY, &dd->flags);
if (!busy) {
dev_dbg(dd->dev, "spurious interrupt\n");
return IRQ_NONE;
}
dev_dbg(dd->dev, "irq_stat: 0x%x\n", value);
if (value & TEGRA_AES_INT_ERROR_MASK)
aes_writel(dd, TEGRA_AES_INT_ERROR_MASK, TEGRA_AES_INTR_STATUS);
if (!(value & TEGRA_AES_ENGINE_BUSY_FIELD))
complete(&dd->op_complete);
else
return IRQ_NONE;
return IRQ_HANDLED;
}
static int tegra_aes_crypt(struct ablkcipher_request *req, unsigned long mode)
{
struct tegra_aes_reqctx *rctx = ablkcipher_request_ctx(req);
struct tegra_aes_dev *dd = aes_dev;
unsigned long flags;
int err = 0;
int busy;
dev_dbg(dd->dev, "nbytes: %d, enc: %d, cbc: %d, ofb: %d\n",
req->nbytes, !!(mode & FLAGS_ENCRYPT),
!!(mode & FLAGS_CBC), !!(mode & FLAGS_OFB));
rctx->mode = mode;
spin_lock_irqsave(&dd->lock, flags);
err = ablkcipher_enqueue_request(&dd->queue, req);
busy = test_and_set_bit(FLAGS_BUSY, &dd->flags);
spin_unlock_irqrestore(&dd->lock, flags);
if (!busy)
queue_work(aes_wq, &aes_work);
return err;
}
static int tegra_aes_ecb_encrypt(struct ablkcipher_request *req)
{
return tegra_aes_crypt(req, FLAGS_ENCRYPT);
}
static int tegra_aes_ecb_decrypt(struct ablkcipher_request *req)
{
return tegra_aes_crypt(req, 0);
}
static int tegra_aes_cbc_encrypt(struct ablkcipher_request *req)
{
return tegra_aes_crypt(req, FLAGS_ENCRYPT | FLAGS_CBC);
}
static int tegra_aes_cbc_decrypt(struct ablkcipher_request *req)
{
return tegra_aes_crypt(req, FLAGS_CBC);
}
static int tegra_aes_ofb_encrypt(struct ablkcipher_request *req)
{
return tegra_aes_crypt(req, FLAGS_ENCRYPT | FLAGS_OFB);
}
static int tegra_aes_ofb_decrypt(struct ablkcipher_request *req)
{
return tegra_aes_crypt(req, FLAGS_OFB);
}
static int tegra_aes_get_random(struct crypto_rng *tfm, u8 *rdata,
unsigned int dlen)
{
struct tegra_aes_dev *dd = aes_dev;
struct tegra_aes_ctx *ctx = &rng_ctx;
int ret, i;
u8 *dest = rdata, *dt = dd->dt;
mutex_lock(&aes_lock);
ret = clk_prepare_enable(dd->aes_clk);
if (ret) {
mutex_unlock(&aes_lock);
return ret;
}
ctx->dd = dd;
dd->ctx = ctx;
dd->flags = FLAGS_ENCRYPT | FLAGS_RNG;
memcpy(dd->buf_in, dt, DEFAULT_RNG_BLK_SZ);
ret = aes_start_crypt(dd, (u32)dd->dma_buf_in,
(u32)dd->dma_buf_out, 1, dd->flags, true);
if (ret < 0) {
dev_err(dd->dev, "aes_start_crypt fail(%d)\n", ret);
dlen = ret;
goto out;
}
memcpy(dest, dd->buf_out, dlen);
for (i = DEFAULT_RNG_BLK_SZ - 1; i >= 0; i--) {
dt[i] += 1;
if (dt[i] != 0)
break;
}
out:
clk_disable_unprepare(dd->aes_clk);
mutex_unlock(&aes_lock);
dev_dbg(dd->dev, "%s: done\n", __func__);
return dlen;
}
static int tegra_aes_rng_reset(struct crypto_rng *tfm, u8 *seed,
unsigned int slen)
{
struct tegra_aes_dev *dd = aes_dev;
struct tegra_aes_ctx *ctx = &rng_ctx;
struct tegra_aes_slot *key_slot;
struct timespec ts;
int ret = 0;
u64 nsec, tmp[2];
u8 *dt;
if (!ctx || !dd) {
dev_err(dd->dev, "ctx=0x%x, dd=0x%x\n",
(unsigned int)ctx, (unsigned int)dd);
return -EINVAL;
}
if (slen < (DEFAULT_RNG_BLK_SZ + AES_KEYSIZE_128)) {
dev_err(dd->dev, "seed size invalid");
return -ENOMEM;
}
mutex_lock(&aes_lock);
if (!ctx->slot) {
key_slot = aes_find_key_slot();
if (!key_slot) {
dev_err(dd->dev, "no empty slot\n");
mutex_unlock(&aes_lock);
return -ENOMEM;
}
ctx->slot = key_slot;
}
ctx->dd = dd;
dd->ctx = ctx;
dd->ctr = 0;
ctx->keylen = AES_KEYSIZE_128;
ctx->flags |= FLAGS_NEW_KEY;
memcpy(dd->ivkey_base, seed + DEFAULT_RNG_BLK_SZ, AES_KEYSIZE_128);
memset(dd->ivkey_base + AES_KEYSIZE_128, 0, AES_HW_KEY_TABLE_LENGTH_BYTES - AES_KEYSIZE_128);
dd->iv = seed;
dd->ivlen = slen;
dd->flags = FLAGS_ENCRYPT | FLAGS_RNG;
ret = clk_prepare_enable(dd->aes_clk);
if (ret) {
mutex_unlock(&aes_lock);
return ret;
}
aes_set_key(dd);
memcpy(dd->buf_in, dd->iv, DEFAULT_RNG_BLK_SZ);
ret = aes_start_crypt(dd, (u32)dd->dma_buf_in,
dd->dma_buf_out, 1, FLAGS_CBC, false);
if (ret < 0) {
dev_err(dd->dev, "aes_start_crypt fail(%d)\n", ret);
goto out;
}
if (dd->ivlen >= (2 * DEFAULT_RNG_BLK_SZ + AES_KEYSIZE_128)) {
dt = dd->iv + DEFAULT_RNG_BLK_SZ + AES_KEYSIZE_128;
} else {
getnstimeofday(&ts);
nsec = timespec_to_ns(&ts);
do_div(nsec, 1000);
nsec ^= dd->ctr << 56;
dd->ctr++;
tmp[0] = nsec;
tmp[1] = tegra_chip_uid();
dt = (u8 *)tmp;
}
memcpy(dd->dt, dt, DEFAULT_RNG_BLK_SZ);
out:
clk_disable_unprepare(dd->aes_clk);
mutex_unlock(&aes_lock);
dev_dbg(dd->dev, "%s: done\n", __func__);
return ret;
}
static int tegra_aes_cra_init(struct crypto_tfm *tfm)
{
tfm->crt_ablkcipher.reqsize = sizeof(struct tegra_aes_reqctx);
return 0;
}
void tegra_aes_cra_exit(struct crypto_tfm *tfm)
{
struct tegra_aes_ctx *ctx =
crypto_ablkcipher_ctx((struct crypto_ablkcipher *)tfm);
if (ctx && ctx->slot)
aes_release_key_slot(ctx->slot);
}
static int tegra_aes_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct tegra_aes_dev *dd;
struct resource *res;
int err = -ENOMEM, i = 0, j;
dd = devm_kzalloc(dev, sizeof(struct tegra_aes_dev), GFP_KERNEL);
if (dd == NULL) {
dev_err(dev, "unable to alloc data struct.\n");
return err;
}
dd->dev = dev;
platform_set_drvdata(pdev, dd);
dd->slots = devm_kzalloc(dev, sizeof(struct tegra_aes_slot) *
AES_NR_KEYSLOTS, GFP_KERNEL);
if (dd->slots == NULL) {
dev_err(dev, "unable to alloc slot struct.\n");
goto out;
}
spin_lock_init(&dd->lock);
crypto_init_queue(&dd->queue, TEGRA_AES_QUEUE_LENGTH);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "invalid resource type: base\n");
err = -ENODEV;
goto out;
}
if (!devm_request_mem_region(&pdev->dev, res->start,
resource_size(res),
dev_name(&pdev->dev))) {
dev_err(&pdev->dev, "Couldn't request MEM resource\n");
return -ENODEV;
}
dd->io_base = devm_ioremap(dev, res->start, resource_size(res));
if (!dd->io_base) {
dev_err(dev, "can't ioremap register space\n");
err = -ENOMEM;
goto out;
}
dd->aes_clk = clk_get(dev, "vde");
if (IS_ERR(dd->aes_clk)) {
dev_err(dev, "iclock intialization failed.\n");
err = -ENODEV;
goto out;
}
err = clk_set_rate(dd->aes_clk, ULONG_MAX);
if (err) {
dev_err(dd->dev, "iclk set_rate fail(%d)\n", err);
goto out;
}
dd->ivkey_base = dma_alloc_coherent(dev, AES_HW_KEY_TABLE_LENGTH_BYTES,
&dd->ivkey_phys_base,
GFP_KERNEL);
if (!dd->ivkey_base) {
dev_err(dev, "can not allocate iv/key buffer\n");
err = -ENOMEM;
goto out;
}
dd->buf_in = dma_alloc_coherent(dev, AES_HW_DMA_BUFFER_SIZE_BYTES,
&dd->dma_buf_in, GFP_KERNEL);
if (!dd->buf_in) {
dev_err(dev, "can not allocate dma-in buffer\n");
err = -ENOMEM;
goto out;
}
dd->buf_out = dma_alloc_coherent(dev, AES_HW_DMA_BUFFER_SIZE_BYTES,
&dd->dma_buf_out, GFP_KERNEL);
if (!dd->buf_out) {
dev_err(dev, "can not allocate dma-out buffer\n");
err = -ENOMEM;
goto out;
}
init_completion(&dd->op_complete);
aes_wq = alloc_workqueue("tegra_aes_wq", WQ_HIGHPRI | WQ_UNBOUND, 1);
if (!aes_wq) {
dev_err(dev, "alloc_workqueue failed\n");
err = -ENOMEM;
goto out;
}
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res) {
dev_err(dev, "invalid resource type: base\n");
err = -ENODEV;
goto out;
}
dd->irq = res->start;
err = devm_request_irq(dev, dd->irq, aes_irq, IRQF_TRIGGER_HIGH |
IRQF_SHARED, "tegra-aes", dd);
if (err) {
dev_err(dev, "request_irq failed\n");
goto out;
}
mutex_init(&aes_lock);
INIT_LIST_HEAD(&dev_list);
spin_lock_init(&list_lock);
spin_lock(&list_lock);
for (i = 0; i < AES_NR_KEYSLOTS; i++) {
if (i == SSK_SLOT_NUM)
continue;
dd->slots[i].slot_num = i;
INIT_LIST_HEAD(&dd->slots[i].node);
list_add_tail(&dd->slots[i].node, &dev_list);
}
spin_unlock(&list_lock);
aes_dev = dd;
for (i = 0; i < ARRAY_SIZE(algs); i++) {
algs[i].cra_priority = 300;
algs[i].cra_ctxsize = sizeof(struct tegra_aes_ctx);
algs[i].cra_module = THIS_MODULE;
algs[i].cra_init = tegra_aes_cra_init;
algs[i].cra_exit = tegra_aes_cra_exit;
err = crypto_register_alg(&algs[i]);
if (err)
goto out;
}
dev_info(dev, "registered");
return 0;
out:
for (j = 0; j < i; j++)
crypto_unregister_alg(&algs[j]);
if (dd->ivkey_base)
dma_free_coherent(dev, AES_HW_KEY_TABLE_LENGTH_BYTES,
dd->ivkey_base, dd->ivkey_phys_base);
if (dd->buf_in)
dma_free_coherent(dev, AES_HW_DMA_BUFFER_SIZE_BYTES,
dd->buf_in, dd->dma_buf_in);
if (dd->buf_out)
dma_free_coherent(dev, AES_HW_DMA_BUFFER_SIZE_BYTES,
dd->buf_out, dd->dma_buf_out);
if (!IS_ERR(dd->aes_clk))
clk_put(dd->aes_clk);
if (aes_wq)
destroy_workqueue(aes_wq);
spin_lock(&list_lock);
list_del(&dev_list);
spin_unlock(&list_lock);
aes_dev = NULL;
dev_err(dev, "%s: initialization failed.\n", __func__);
return err;
}
static int tegra_aes_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct tegra_aes_dev *dd = platform_get_drvdata(pdev);
int i;
for (i = 0; i < ARRAY_SIZE(algs); i++)
crypto_unregister_alg(&algs[i]);
cancel_work_sync(&aes_work);
destroy_workqueue(aes_wq);
spin_lock(&list_lock);
list_del(&dev_list);
spin_unlock(&list_lock);
dma_free_coherent(dev, AES_HW_KEY_TABLE_LENGTH_BYTES,
dd->ivkey_base, dd->ivkey_phys_base);
dma_free_coherent(dev, AES_HW_DMA_BUFFER_SIZE_BYTES,
dd->buf_in, dd->dma_buf_in);
dma_free_coherent(dev, AES_HW_DMA_BUFFER_SIZE_BYTES,
dd->buf_out, dd->dma_buf_out);
clk_put(dd->aes_clk);
aes_dev = NULL;
return 0;
}
