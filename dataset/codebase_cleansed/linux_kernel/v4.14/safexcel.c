static void eip197_trc_cache_init(struct safexcel_crypto_priv *priv)
{
u32 val, htable_offset;
int i;
val = readl(priv->base + EIP197_CS_RAM_CTRL);
val &= ~EIP197_TRC_ENABLE_MASK;
val |= EIP197_TRC_ENABLE_0;
writel(val, priv->base + EIP197_CS_RAM_CTRL);
writel(0, priv->base + EIP197_TRC_ECCCTRL);
val = readl(priv->base + EIP197_TRC_PARAMS);
val |= EIP197_TRC_PARAMS_SW_RESET;
val &= ~EIP197_TRC_PARAMS_DATA_ACCESS;
writel(val, priv->base + EIP197_TRC_PARAMS);
for (i = 0; i < EIP197_CS_RC_MAX; i++) {
u32 val, offset = EIP197_CLASSIFICATION_RAMS + i * EIP197_CS_RC_SIZE;
writel(EIP197_CS_RC_NEXT(EIP197_RC_NULL) |
EIP197_CS_RC_PREV(EIP197_RC_NULL),
priv->base + offset);
val = EIP197_CS_RC_NEXT(i+1) | EIP197_CS_RC_PREV(i-1);
if (i == 0)
val |= EIP197_CS_RC_PREV(EIP197_RC_NULL);
else if (i == EIP197_CS_RC_MAX - 1)
val |= EIP197_CS_RC_NEXT(EIP197_RC_NULL);
writel(val, priv->base + offset + sizeof(u32));
}
htable_offset = EIP197_CS_RC_MAX * EIP197_CS_RC_SIZE;
for (i = 0; i < 64; i++)
writel(GENMASK(29, 0),
priv->base + EIP197_CLASSIFICATION_RAMS + htable_offset + i * sizeof(u32));
val = readl(priv->base + EIP197_CS_RAM_CTRL);
val &= ~EIP197_TRC_ENABLE_MASK;
writel(val, priv->base + EIP197_CS_RAM_CTRL);
val = EIP197_TRC_FREECHAIN_HEAD_PTR(0) |
EIP197_TRC_FREECHAIN_TAIL_PTR(EIP197_CS_RC_MAX - 1);
writel(val, priv->base + EIP197_TRC_FREECHAIN);
val = EIP197_TRC_PARAMS2_RC_SZ_SMALL(EIP197_CS_TRC_REC_WC) |
EIP197_TRC_PARAMS2_HTABLE_PTR(EIP197_CS_RC_MAX);
writel(val, priv->base + EIP197_TRC_PARAMS2);
val = EIP197_TRC_PARAMS_RC_SZ_LARGE(EIP197_CS_TRC_LG_REC_WC) |
EIP197_TRC_PARAMS_BLK_TIMER_SPEED(1) |
EIP197_TRC_PARAMS_HTABLE_SZ(2);
writel(val, priv->base + EIP197_TRC_PARAMS);
}
static void eip197_write_firmware(struct safexcel_crypto_priv *priv,
const struct firmware *fw, u32 ctrl,
u32 prog_en)
{
const u32 *data = (const u32 *)fw->data;
u32 val;
int i;
writel(EIP197_PE_ICE_x_CTRL_SW_RESET |
EIP197_PE_ICE_x_CTRL_CLR_ECC_CORR |
EIP197_PE_ICE_x_CTRL_CLR_ECC_NON_CORR,
priv->base + ctrl);
writel(prog_en, priv->base + EIP197_PE_ICE_RAM_CTRL);
for (i = 0; i < fw->size / sizeof(u32); i++)
writel(be32_to_cpu(data[i]),
priv->base + EIP197_CLASSIFICATION_RAMS + i * sizeof(u32));
writel(0, priv->base + EIP197_PE_ICE_RAM_CTRL);
val = readl(priv->base + ctrl);
val &= ~EIP197_PE_ICE_x_CTRL_SW_RESET;
writel(val, priv->base + ctrl);
}
static int eip197_load_firmwares(struct safexcel_crypto_priv *priv)
{
const char *fw_name[] = {"ifpp.bin", "ipue.bin"};
const struct firmware *fw[FW_NB];
int i, j, ret = 0;
u32 val;
for (i = 0; i < FW_NB; i++) {
ret = request_firmware(&fw[i], fw_name[i], priv->dev);
if (ret) {
dev_err(priv->dev,
"Failed to request firmware %s (%d)\n",
fw_name[i], ret);
goto release_fw;
}
}
val = readl(priv->base + EIP197_PE_ICE_SCRATCH_CTRL);
val |= EIP197_PE_ICE_SCRATCH_CTRL_CHANGE_TIMER |
EIP197_PE_ICE_SCRATCH_CTRL_TIMER_EN |
EIP197_PE_ICE_SCRATCH_CTRL_SCRATCH_ACCESS |
EIP197_PE_ICE_SCRATCH_CTRL_CHANGE_ACCESS;
writel(val, priv->base + EIP197_PE_ICE_SCRATCH_CTRL);
memset(priv->base + EIP197_PE_ICE_SCRATCH_RAM, 0,
EIP197_NUM_OF_SCRATCH_BLOCKS * sizeof(u32));
eip197_write_firmware(priv, fw[FW_IFPP], EIP197_PE_ICE_FPP_CTRL,
EIP197_PE_ICE_RAM_CTRL_FPP_PROG_EN);
eip197_write_firmware(priv, fw[FW_IPUE], EIP197_PE_ICE_PUE_CTRL,
EIP197_PE_ICE_RAM_CTRL_PUE_PROG_EN);
release_fw:
for (j = 0; j < i; j++)
release_firmware(fw[j]);
return ret;
}
static int safexcel_hw_setup_cdesc_rings(struct safexcel_crypto_priv *priv)
{
u32 hdw, cd_size_rnd, val;
int i;
hdw = readl(priv->base + EIP197_HIA_OPTIONS);
hdw &= GENMASK(27, 25);
hdw >>= 25;
cd_size_rnd = (priv->config.cd_size + (BIT(hdw) - 1)) >> hdw;
for (i = 0; i < priv->config.rings; i++) {
writel(lower_32_bits(priv->ring[i].cdr.base_dma),
priv->base + EIP197_HIA_CDR(i) + EIP197_HIA_xDR_RING_BASE_ADDR_LO);
writel(upper_32_bits(priv->ring[i].cdr.base_dma),
priv->base + EIP197_HIA_CDR(i) + EIP197_HIA_xDR_RING_BASE_ADDR_HI);
writel(EIP197_xDR_DESC_MODE_64BIT | (priv->config.cd_offset << 16) |
priv->config.cd_size,
priv->base + EIP197_HIA_CDR(i) + EIP197_HIA_xDR_DESC_SIZE);
writel(((EIP197_FETCH_COUNT * (cd_size_rnd << hdw)) << 16) |
(EIP197_FETCH_COUNT * priv->config.cd_offset),
priv->base + EIP197_HIA_CDR(i) + EIP197_HIA_xDR_CFG);
val = EIP197_HIA_xDR_CFG_WR_CACHE(WR_CACHE_3BITS);
val |= EIP197_HIA_xDR_CFG_RD_CACHE(RD_CACHE_3BITS);
writel(val,
priv->base + EIP197_HIA_CDR(i) + EIP197_HIA_xDR_DMA_CFG);
writel(GENMASK(5, 0),
priv->base + EIP197_HIA_CDR(i) + EIP197_HIA_xDR_STAT);
}
return 0;
}
static int safexcel_hw_setup_rdesc_rings(struct safexcel_crypto_priv *priv)
{
u32 hdw, rd_size_rnd, val;
int i;
hdw = readl(priv->base + EIP197_HIA_OPTIONS);
hdw &= GENMASK(27, 25);
hdw >>= 25;
rd_size_rnd = (priv->config.rd_size + (BIT(hdw) - 1)) >> hdw;
for (i = 0; i < priv->config.rings; i++) {
writel(lower_32_bits(priv->ring[i].rdr.base_dma),
priv->base + EIP197_HIA_RDR(i) + EIP197_HIA_xDR_RING_BASE_ADDR_LO);
writel(upper_32_bits(priv->ring[i].rdr.base_dma),
priv->base + EIP197_HIA_RDR(i) + EIP197_HIA_xDR_RING_BASE_ADDR_HI);
writel(EIP197_xDR_DESC_MODE_64BIT | (priv->config.rd_offset << 16) |
priv->config.rd_size,
priv->base + EIP197_HIA_RDR(i) + EIP197_HIA_xDR_DESC_SIZE);
writel(((EIP197_FETCH_COUNT * (rd_size_rnd << hdw)) << 16) |
(EIP197_FETCH_COUNT * priv->config.rd_offset),
priv->base + EIP197_HIA_RDR(i) + EIP197_HIA_xDR_CFG);
val = EIP197_HIA_xDR_CFG_WR_CACHE(WR_CACHE_3BITS);
val |= EIP197_HIA_xDR_CFG_RD_CACHE(RD_CACHE_3BITS);
val |= EIP197_HIA_xDR_WR_RES_BUF | EIP197_HIA_xDR_WR_CTRL_BUG;
writel(val,
priv->base + EIP197_HIA_RDR(i) + EIP197_HIA_xDR_DMA_CFG);
writel(GENMASK(7, 0),
priv->base + EIP197_HIA_RDR(i) + EIP197_HIA_xDR_STAT);
val = readl(priv->base + EIP197_HIA_AIC_R_ENABLE_CTRL(i));
val |= EIP197_RDR_IRQ(i);
writel(val, priv->base + EIP197_HIA_AIC_R_ENABLE_CTRL(i));
}
return 0;
}
static int safexcel_hw_init(struct safexcel_crypto_priv *priv)
{
u32 version, val;
int i, ret;
version = readl(priv->base + EIP197_HIA_VERSION);
val = readl(priv->base + EIP197_HIA_MST_CTRL);
if ((version & 0xffff) == EIP197_HIA_VERSION_BE)
val |= EIP197_MST_CTRL_BYTE_SWAP;
else if (((version >> 16) & 0xffff) == EIP197_HIA_VERSION_LE)
val |= (EIP197_MST_CTRL_NO_BYTE_SWAP >> 24);
writel(val, priv->base + EIP197_HIA_MST_CTRL);
writel(EIP197_MST_CTRL_RD_CACHE(RD_CACHE_4BITS) |
EIP197_MST_CTRL_WD_CACHE(WR_CACHE_4BITS),
priv->base + EIP197_MST_CTRL);
writel(0, priv->base + EIP197_HIA_AIC_G_ENABLE_CTRL);
writel(GENMASK(31, 0), priv->base + EIP197_HIA_AIC_G_ACK);
writel(EIP197_DxE_THR_CTRL_RESET_PE,
priv->base + EIP197_HIA_DFE_THR_CTRL);
writel(EIP197_HIA_RA_PE_CTRL_RESET,
priv->base + EIP197_HIA_RA_PE_CTRL);
val = EIP197_HIA_DFE_CFG_DIS_DEBUG;
val |= EIP197_HIA_DxE_CFG_MIN_DATA_SIZE(5) | EIP197_HIA_DxE_CFG_MAX_DATA_SIZE(9);
val |= EIP197_HIA_DxE_CFG_MIN_CTRL_SIZE(5) | EIP197_HIA_DxE_CFG_MAX_CTRL_SIZE(7);
val |= EIP197_HIA_DxE_CFG_DATA_CACHE_CTRL(RD_CACHE_3BITS);
val |= EIP197_HIA_DxE_CFG_CTRL_CACHE_CTRL(RD_CACHE_3BITS);
writel(val, priv->base + EIP197_HIA_DFE_CFG);
writel(0, priv->base + EIP197_HIA_DFE_THR_CTRL);
writel(EIP197_PE_IN_xBUF_THRES_MIN(5) | EIP197_PE_IN_xBUF_THRES_MAX(9),
priv->base + EIP197_PE_IN_DBUF_THRES);
writel(EIP197_PE_IN_xBUF_THRES_MIN(5) | EIP197_PE_IN_xBUF_THRES_MAX(7),
priv->base + EIP197_PE_IN_TBUF_THRES);
writel(EIP197_HIA_RA_PE_CTRL_EN | GENMASK(priv->config.rings - 1, 0),
priv->base + EIP197_HIA_RA_PE_CTRL);
writel(EIP197_DxE_THR_CTRL_RESET_PE,
priv->base + EIP197_HIA_DSE_THR_CTRL);
while ((readl(priv->base + EIP197_HIA_DSE_THR_STAT) &
GENMASK(15, 12)) != GENMASK(15, 12))
;
val = EIP197_HIA_DSE_CFG_DIS_DEBUG;
val |= EIP197_HIA_DxE_CFG_MIN_DATA_SIZE(7) | EIP197_HIA_DxE_CFG_MAX_DATA_SIZE(8);
val |= EIP197_HIA_DxE_CFG_DATA_CACHE_CTRL(WR_CACHE_3BITS);
val |= EIP197_HIA_DSE_CFG_ALLWAYS_BUFFERABLE;
val |= EIP197_HIA_DSE_CFG_EN_SINGLE_WR;
writel(val, priv->base + EIP197_HIA_DSE_CFG);
writel(0, priv->base + EIP197_HIA_DSE_THR_CTRL);
writel(EIP197_PE_OUT_DBUF_THRES_MIN(7) | EIP197_PE_OUT_DBUF_THRES_MAX(8),
priv->base + EIP197_PE_OUT_DBUF_THRES);
val = EIP197_FUNCTION_RSVD;
val |= EIP197_PROTOCOL_ENCRYPT_ONLY | EIP197_PROTOCOL_HASH_ONLY;
val |= EIP197_ALG_AES_ECB | EIP197_ALG_AES_CBC;
val |= EIP197_ALG_SHA1 | EIP197_ALG_HMAC_SHA1;
val |= EIP197_ALG_SHA2;
writel(val, priv->base + EIP197_PE_EIP96_FUNCTION_EN);
for (i = 0; i < priv->config.rings; i++) {
writel(GENMASK(31, 0),
priv->base + EIP197_HIA_AIC_R_ENABLE_CLR(i));
writel(0, priv->base + EIP197_HIA_CDR(i) + EIP197_HIA_xDR_CFG);
writel(EIP197_xDR_PREP_CLR_COUNT,
priv->base + EIP197_HIA_CDR(i) + EIP197_HIA_xDR_PREP_COUNT);
writel(EIP197_xDR_PROC_CLR_COUNT,
priv->base + EIP197_HIA_CDR(i) + EIP197_HIA_xDR_PROC_COUNT);
writel(0,
priv->base + EIP197_HIA_CDR(i) + EIP197_HIA_xDR_PREP_PNTR);
writel(0,
priv->base + EIP197_HIA_CDR(i) + EIP197_HIA_xDR_PROC_PNTR);
writel((EIP197_DEFAULT_RING_SIZE * priv->config.cd_offset) << 2,
priv->base + EIP197_HIA_CDR(i) + EIP197_HIA_xDR_RING_SIZE);
}
for (i = 0; i < priv->config.rings; i++) {
writel(0, priv->base + EIP197_HIA_RDR(i) + EIP197_HIA_xDR_CFG);
writel(EIP197_xDR_PREP_CLR_COUNT,
priv->base + EIP197_HIA_RDR(i) + EIP197_HIA_xDR_PREP_COUNT);
writel(EIP197_xDR_PROC_CLR_COUNT,
priv->base + EIP197_HIA_RDR(i) + EIP197_HIA_xDR_PROC_COUNT);
writel(0,
priv->base + EIP197_HIA_RDR(i) + EIP197_HIA_xDR_PREP_PNTR);
writel(0,
priv->base + EIP197_HIA_RDR(i) + EIP197_HIA_xDR_PROC_PNTR);
writel((EIP197_DEFAULT_RING_SIZE * priv->config.rd_offset) << 2,
priv->base + EIP197_HIA_RDR(i) + EIP197_HIA_xDR_RING_SIZE);
}
writel(EIP197_DxE_THR_CTRL_EN | GENMASK(priv->config.rings - 1, 0),
priv->base + EIP197_HIA_DFE_THR_CTRL);
writel(EIP197_DxE_THR_CTRL_EN | GENMASK(priv->config.rings - 1, 0),
priv->base + EIP197_HIA_DSE_THR_CTRL);
writel(GENMASK(30, 20), priv->base + EIP197_HIA_AIC_G_ACK);
eip197_trc_cache_init(priv);
ret = eip197_load_firmwares(priv);
if (ret)
return ret;
safexcel_hw_setup_cdesc_rings(priv);
safexcel_hw_setup_rdesc_rings(priv);
return 0;
}
void safexcel_dequeue(struct safexcel_crypto_priv *priv, int ring)
{
struct crypto_async_request *req, *backlog;
struct safexcel_context *ctx;
struct safexcel_request *request;
int ret, nreq = 0, cdesc = 0, rdesc = 0, commands, results;
priv->ring[ring].need_dequeue = false;
do {
spin_lock_bh(&priv->ring[ring].queue_lock);
backlog = crypto_get_backlog(&priv->ring[ring].queue);
req = crypto_dequeue_request(&priv->ring[ring].queue);
spin_unlock_bh(&priv->ring[ring].queue_lock);
if (!req)
goto finalize;
request = kzalloc(sizeof(*request), EIP197_GFP_FLAGS(*req));
if (!request) {
spin_lock_bh(&priv->ring[ring].queue_lock);
crypto_enqueue_request(&priv->ring[ring].queue, req);
spin_unlock_bh(&priv->ring[ring].queue_lock);
priv->ring[ring].need_dequeue = true;
goto finalize;
}
ctx = crypto_tfm_ctx(req->tfm);
ret = ctx->send(req, ring, request, &commands, &results);
if (ret) {
kfree(request);
req->complete(req, ret);
priv->ring[ring].need_dequeue = true;
goto finalize;
}
if (backlog)
backlog->complete(backlog, -EINPROGRESS);
spin_lock_bh(&priv->ring[ring].egress_lock);
list_add_tail(&request->list, &priv->ring[ring].list);
spin_unlock_bh(&priv->ring[ring].egress_lock);
cdesc += commands;
rdesc += results;
} while (nreq++ < EIP197_MAX_BATCH_SZ);
finalize:
if (nreq == EIP197_MAX_BATCH_SZ)
priv->ring[ring].need_dequeue = true;
else if (!nreq)
return;
spin_lock_bh(&priv->ring[ring].lock);
writel(EIP197_HIA_RDR_THRESH_PKT_MODE |
EIP197_HIA_RDR_THRESH_PROC_PKT(nreq),
priv->base + EIP197_HIA_RDR(ring) + EIP197_HIA_xDR_THRESH);
writel((rdesc * priv->config.rd_offset) << 2,
priv->base + EIP197_HIA_RDR(ring) + EIP197_HIA_xDR_PREP_COUNT);
writel((cdesc * priv->config.cd_offset) << 2,
priv->base + EIP197_HIA_CDR(ring) + EIP197_HIA_xDR_PREP_COUNT);
spin_unlock_bh(&priv->ring[ring].lock);
}
void safexcel_free_context(struct safexcel_crypto_priv *priv,
struct crypto_async_request *req,
int result_sz)
{
struct safexcel_context *ctx = crypto_tfm_ctx(req->tfm);
if (ctx->result_dma)
dma_unmap_single(priv->dev, ctx->result_dma, result_sz,
DMA_FROM_DEVICE);
if (ctx->cache) {
dma_unmap_single(priv->dev, ctx->cache_dma, ctx->cache_sz,
DMA_TO_DEVICE);
kfree(ctx->cache);
ctx->cache = NULL;
ctx->cache_sz = 0;
}
}
void safexcel_complete(struct safexcel_crypto_priv *priv, int ring)
{
struct safexcel_command_desc *cdesc;
do {
cdesc = safexcel_ring_next_rptr(priv, &priv->ring[ring].cdr);
if (IS_ERR(cdesc)) {
dev_err(priv->dev,
"Could not retrieve the command descriptor\n");
return;
}
} while (!cdesc->last_seg);
}
void safexcel_inv_complete(struct crypto_async_request *req, int error)
{
struct safexcel_inv_result *result = req->data;
if (error == -EINPROGRESS)
return;
result->error = error;
complete(&result->completion);
}
int safexcel_invalidate_cache(struct crypto_async_request *async,
struct safexcel_context *ctx,
struct safexcel_crypto_priv *priv,
dma_addr_t ctxr_dma, int ring,
struct safexcel_request *request)
{
struct safexcel_command_desc *cdesc;
struct safexcel_result_desc *rdesc;
int ret = 0;
spin_lock_bh(&priv->ring[ring].egress_lock);
cdesc = safexcel_add_cdesc(priv, ring, true, true, 0, 0, 0, ctxr_dma);
if (IS_ERR(cdesc)) {
ret = PTR_ERR(cdesc);
goto unlock;
}
cdesc->control_data.type = EIP197_TYPE_EXTENDED;
cdesc->control_data.options = 0;
cdesc->control_data.refresh = 0;
cdesc->control_data.control0 = CONTEXT_CONTROL_INV_TR;
rdesc = safexcel_add_rdesc(priv, ring, true, true, 0, 0);
if (IS_ERR(rdesc)) {
ret = PTR_ERR(rdesc);
goto cdesc_rollback;
}
request->req = async;
goto unlock;
cdesc_rollback:
safexcel_ring_rollback_wptr(priv, &priv->ring[ring].cdr);
unlock:
spin_unlock_bh(&priv->ring[ring].egress_lock);
return ret;
}
static inline void safexcel_handle_result_descriptor(struct safexcel_crypto_priv *priv,
int ring)
{
struct safexcel_request *sreq;
struct safexcel_context *ctx;
int ret, i, nreq, ndesc = 0;
bool should_complete;
nreq = readl(priv->base + EIP197_HIA_RDR(ring) + EIP197_HIA_xDR_PROC_COUNT);
nreq >>= 24;
nreq &= GENMASK(6, 0);
if (!nreq)
return;
for (i = 0; i < nreq; i++) {
spin_lock_bh(&priv->ring[ring].egress_lock);
sreq = list_first_entry(&priv->ring[ring].list,
struct safexcel_request, list);
list_del(&sreq->list);
spin_unlock_bh(&priv->ring[ring].egress_lock);
ctx = crypto_tfm_ctx(sreq->req->tfm);
ndesc = ctx->handle_result(priv, ring, sreq->req,
&should_complete, &ret);
if (ndesc < 0) {
dev_err(priv->dev, "failed to handle result (%d)", ndesc);
return;
}
writel(EIP197_xDR_PROC_xD_PKT(1) |
EIP197_xDR_PROC_xD_COUNT(ndesc * priv->config.rd_offset),
priv->base + EIP197_HIA_RDR(ring) + EIP197_HIA_xDR_PROC_COUNT);
if (should_complete) {
local_bh_disable();
sreq->req->complete(sreq->req, ret);
local_bh_enable();
}
kfree(sreq);
}
}
static void safexcel_handle_result_work(struct work_struct *work)
{
struct safexcel_work_data *data =
container_of(work, struct safexcel_work_data, work);
struct safexcel_crypto_priv *priv = data->priv;
safexcel_handle_result_descriptor(priv, data->ring);
if (priv->ring[data->ring].need_dequeue)
safexcel_dequeue(data->priv, data->ring);
}
static irqreturn_t safexcel_irq_ring(int irq, void *data)
{
struct safexcel_ring_irq_data *irq_data = data;
struct safexcel_crypto_priv *priv = irq_data->priv;
int ring = irq_data->ring;
u32 status, stat;
status = readl(priv->base + EIP197_HIA_AIC_R_ENABLED_STAT(ring));
if (!status)
return IRQ_NONE;
if (status & EIP197_RDR_IRQ(ring)) {
stat = readl(priv->base + EIP197_HIA_RDR(ring) + EIP197_HIA_xDR_STAT);
if (unlikely(stat & EIP197_xDR_ERR)) {
dev_err(priv->dev, "RDR: fatal error.");
} else if (likely(stat & EIP197_xDR_THRESH)) {
queue_work(priv->ring[ring].workqueue, &priv->ring[ring].work_data.work);
}
writel(stat & 0xff,
priv->base + EIP197_HIA_RDR(ring) + EIP197_HIA_xDR_STAT);
}
writel(status, priv->base + EIP197_HIA_AIC_R_ACK(ring));
return IRQ_HANDLED;
}
static int safexcel_request_ring_irq(struct platform_device *pdev, const char *name,
irq_handler_t handler,
struct safexcel_ring_irq_data *ring_irq_priv)
{
int ret, irq = platform_get_irq_byname(pdev, name);
if (irq < 0) {
dev_err(&pdev->dev, "unable to get IRQ '%s'\n", name);
return irq;
}
ret = devm_request_irq(&pdev->dev, irq, handler, 0,
dev_name(&pdev->dev), ring_irq_priv);
if (ret) {
dev_err(&pdev->dev, "unable to request IRQ %d\n", irq);
return ret;
}
return irq;
}
static int safexcel_register_algorithms(struct safexcel_crypto_priv *priv)
{
int i, j, ret = 0;
for (i = 0; i < ARRAY_SIZE(safexcel_algs); i++) {
safexcel_algs[i]->priv = priv;
if (safexcel_algs[i]->type == SAFEXCEL_ALG_TYPE_SKCIPHER)
ret = crypto_register_skcipher(&safexcel_algs[i]->alg.skcipher);
else
ret = crypto_register_ahash(&safexcel_algs[i]->alg.ahash);
if (ret)
goto fail;
}
return 0;
fail:
for (j = 0; j < i; j++) {
if (safexcel_algs[j]->type == SAFEXCEL_ALG_TYPE_SKCIPHER)
crypto_unregister_skcipher(&safexcel_algs[j]->alg.skcipher);
else
crypto_unregister_ahash(&safexcel_algs[j]->alg.ahash);
}
return ret;
}
static void safexcel_unregister_algorithms(struct safexcel_crypto_priv *priv)
{
int i;
for (i = 0; i < ARRAY_SIZE(safexcel_algs); i++) {
if (safexcel_algs[i]->type == SAFEXCEL_ALG_TYPE_SKCIPHER)
crypto_unregister_skcipher(&safexcel_algs[i]->alg.skcipher);
else
crypto_unregister_ahash(&safexcel_algs[i]->alg.ahash);
}
}
static void safexcel_configure(struct safexcel_crypto_priv *priv)
{
u32 val, mask;
val = readl(priv->base + EIP197_HIA_OPTIONS);
val = (val & GENMASK(27, 25)) >> 25;
mask = BIT(val) - 1;
val = readl(priv->base + EIP197_HIA_OPTIONS);
priv->config.rings = min_t(u32, val & GENMASK(3, 0), max_rings);
priv->config.cd_size = (sizeof(struct safexcel_command_desc) / sizeof(u32));
priv->config.cd_offset = (priv->config.cd_size + mask) & ~mask;
priv->config.rd_size = (sizeof(struct safexcel_result_desc) / sizeof(u32));
priv->config.rd_offset = (priv->config.rd_size + mask) & ~mask;
}
static int safexcel_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct safexcel_crypto_priv *priv;
int i, ret;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->dev = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap_resource(dev, res);
if (IS_ERR(priv->base)) {
dev_err(dev, "failed to get resource\n");
return PTR_ERR(priv->base);
}
priv->clk = of_clk_get(dev->of_node, 0);
if (!IS_ERR(priv->clk)) {
ret = clk_prepare_enable(priv->clk);
if (ret) {
dev_err(dev, "unable to enable clk (%d)\n", ret);
return ret;
}
} else {
if (PTR_ERR(priv->clk) == -EPROBE_DEFER)
return -EPROBE_DEFER;
}
ret = dma_set_mask_and_coherent(dev, DMA_BIT_MASK(64));
if (ret)
goto err_clk;
priv->context_pool = dmam_pool_create("safexcel-context", dev,
sizeof(struct safexcel_context_record),
1, 0);
if (!priv->context_pool) {
ret = -ENOMEM;
goto err_clk;
}
safexcel_configure(priv);
for (i = 0; i < priv->config.rings; i++) {
char irq_name[6] = {0};
char wq_name[9] = {0};
int irq;
struct safexcel_ring_irq_data *ring_irq;
ret = safexcel_init_ring_descriptors(priv,
&priv->ring[i].cdr,
&priv->ring[i].rdr);
if (ret)
goto err_clk;
ring_irq = devm_kzalloc(dev, sizeof(*ring_irq), GFP_KERNEL);
if (!ring_irq) {
ret = -ENOMEM;
goto err_clk;
}
ring_irq->priv = priv;
ring_irq->ring = i;
snprintf(irq_name, 6, "ring%d", i);
irq = safexcel_request_ring_irq(pdev, irq_name, safexcel_irq_ring,
ring_irq);
if (irq < 0) {
ret = irq;
goto err_clk;
}
priv->ring[i].work_data.priv = priv;
priv->ring[i].work_data.ring = i;
INIT_WORK(&priv->ring[i].work_data.work, safexcel_handle_result_work);
snprintf(wq_name, 9, "wq_ring%d", i);
priv->ring[i].workqueue = create_singlethread_workqueue(wq_name);
if (!priv->ring[i].workqueue) {
ret = -ENOMEM;
goto err_clk;
}
crypto_init_queue(&priv->ring[i].queue,
EIP197_DEFAULT_RING_SIZE);
INIT_LIST_HEAD(&priv->ring[i].list);
spin_lock_init(&priv->ring[i].lock);
spin_lock_init(&priv->ring[i].egress_lock);
spin_lock_init(&priv->ring[i].queue_lock);
}
platform_set_drvdata(pdev, priv);
atomic_set(&priv->ring_used, 0);
ret = safexcel_hw_init(priv);
if (ret) {
dev_err(dev, "EIP h/w init failed (%d)\n", ret);
goto err_clk;
}
ret = safexcel_register_algorithms(priv);
if (ret) {
dev_err(dev, "Failed to register algorithms (%d)\n", ret);
goto err_clk;
}
return 0;
err_clk:
clk_disable_unprepare(priv->clk);
return ret;
}
static int safexcel_remove(struct platform_device *pdev)
{
struct safexcel_crypto_priv *priv = platform_get_drvdata(pdev);
int i;
safexcel_unregister_algorithms(priv);
clk_disable_unprepare(priv->clk);
for (i = 0; i < priv->config.rings; i++)
destroy_workqueue(priv->ring[i].workqueue);
return 0;
}
