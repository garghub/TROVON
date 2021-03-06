static void to_talitos_ptr(struct talitos_ptr *talitos_ptr, dma_addr_t dma_addr)
{
talitos_ptr->ptr = cpu_to_be32(lower_32_bits(dma_addr));
talitos_ptr->eptr = upper_32_bits(dma_addr);
}
static void map_single_talitos_ptr(struct device *dev,
struct talitos_ptr *talitos_ptr,
unsigned short len, void *data,
unsigned char extent,
enum dma_data_direction dir)
{
dma_addr_t dma_addr = dma_map_single(dev, data, len, dir);
talitos_ptr->len = cpu_to_be16(len);
to_talitos_ptr(talitos_ptr, dma_addr);
talitos_ptr->j_extent = extent;
}
static void unmap_single_talitos_ptr(struct device *dev,
struct talitos_ptr *talitos_ptr,
enum dma_data_direction dir)
{
dma_unmap_single(dev, be32_to_cpu(talitos_ptr->ptr),
be16_to_cpu(talitos_ptr->len), dir);
}
static int reset_channel(struct device *dev, int ch)
{
struct talitos_private *priv = dev_get_drvdata(dev);
unsigned int timeout = TALITOS_TIMEOUT;
setbits32(priv->chan[ch].reg + TALITOS_CCCR, TALITOS_CCCR_RESET);
while ((in_be32(priv->chan[ch].reg + TALITOS_CCCR) & TALITOS_CCCR_RESET)
&& --timeout)
cpu_relax();
if (timeout == 0) {
dev_err(dev, "failed to reset channel %d\n", ch);
return -EIO;
}
setbits32(priv->chan[ch].reg + TALITOS_CCCR_LO, TALITOS_CCCR_LO_EAE |
TALITOS_CCCR_LO_CDWE | TALITOS_CCCR_LO_CDIE);
if (priv->features & TALITOS_FTR_HW_AUTH_CHECK)
setbits32(priv->chan[ch].reg + TALITOS_CCCR_LO,
TALITOS_CCCR_LO_IWSE);
return 0;
}
static int reset_device(struct device *dev)
{
struct talitos_private *priv = dev_get_drvdata(dev);
unsigned int timeout = TALITOS_TIMEOUT;
u32 mcr = TALITOS_MCR_SWR;
setbits32(priv->reg + TALITOS_MCR, mcr);
while ((in_be32(priv->reg + TALITOS_MCR) & TALITOS_MCR_SWR)
&& --timeout)
cpu_relax();
if (priv->irq[1]) {
mcr = TALITOS_MCR_RCA1 | TALITOS_MCR_RCA3;
setbits32(priv->reg + TALITOS_MCR, mcr);
}
if (timeout == 0) {
dev_err(dev, "failed to reset device\n");
return -EIO;
}
return 0;
}
static int init_device(struct device *dev)
{
struct talitos_private *priv = dev_get_drvdata(dev);
int ch, err;
err = reset_device(dev);
if (err)
return err;
err = reset_device(dev);
if (err)
return err;
for (ch = 0; ch < priv->num_channels; ch++) {
err = reset_channel(dev, ch);
if (err)
return err;
}
setbits32(priv->reg + TALITOS_IMR, TALITOS_IMR_INIT);
setbits32(priv->reg + TALITOS_IMR_LO, TALITOS_IMR_LO_INIT);
if (priv->features & TALITOS_FTR_HW_AUTH_CHECK)
setbits32(priv->reg + TALITOS_MDEUICR_LO,
TALITOS_MDEUICR_LO_ICE);
return 0;
}
int talitos_submit(struct device *dev, int ch, struct talitos_desc *desc,
void (*callback)(struct device *dev,
struct talitos_desc *desc,
void *context, int error),
void *context)
{
struct talitos_private *priv = dev_get_drvdata(dev);
struct talitos_request *request;
unsigned long flags;
int head;
spin_lock_irqsave(&priv->chan[ch].head_lock, flags);
if (!atomic_inc_not_zero(&priv->chan[ch].submit_count)) {
spin_unlock_irqrestore(&priv->chan[ch].head_lock, flags);
return -EAGAIN;
}
head = priv->chan[ch].head;
request = &priv->chan[ch].fifo[head];
request->dma_desc = dma_map_single(dev, desc, sizeof(*desc),
DMA_BIDIRECTIONAL);
request->callback = callback;
request->context = context;
priv->chan[ch].head = (priv->chan[ch].head + 1) & (priv->fifo_len - 1);
smp_wmb();
request->desc = desc;
wmb();
out_be32(priv->chan[ch].reg + TALITOS_FF,
upper_32_bits(request->dma_desc));
out_be32(priv->chan[ch].reg + TALITOS_FF_LO,
lower_32_bits(request->dma_desc));
spin_unlock_irqrestore(&priv->chan[ch].head_lock, flags);
return -EINPROGRESS;
}
static void flush_channel(struct device *dev, int ch, int error, int reset_ch)
{
struct talitos_private *priv = dev_get_drvdata(dev);
struct talitos_request *request, saved_req;
unsigned long flags;
int tail, status;
spin_lock_irqsave(&priv->chan[ch].tail_lock, flags);
tail = priv->chan[ch].tail;
while (priv->chan[ch].fifo[tail].desc) {
request = &priv->chan[ch].fifo[tail];
rmb();
if ((request->desc->hdr & DESC_HDR_DONE) == DESC_HDR_DONE)
status = 0;
else
if (!error)
break;
else
status = error;
dma_unmap_single(dev, request->dma_desc,
sizeof(struct talitos_desc),
DMA_BIDIRECTIONAL);
saved_req.desc = request->desc;
saved_req.callback = request->callback;
saved_req.context = request->context;
smp_wmb();
request->desc = NULL;
priv->chan[ch].tail = (tail + 1) & (priv->fifo_len - 1);
spin_unlock_irqrestore(&priv->chan[ch].tail_lock, flags);
atomic_dec(&priv->chan[ch].submit_count);
saved_req.callback(dev, saved_req.desc, saved_req.context,
status);
if (error && !reset_ch && status == error)
return;
spin_lock_irqsave(&priv->chan[ch].tail_lock, flags);
tail = priv->chan[ch].tail;
}
spin_unlock_irqrestore(&priv->chan[ch].tail_lock, flags);
}
static u32 current_desc_hdr(struct device *dev, int ch)
{
struct talitos_private *priv = dev_get_drvdata(dev);
int tail = priv->chan[ch].tail;
dma_addr_t cur_desc;
cur_desc = in_be32(priv->chan[ch].reg + TALITOS_CDPR_LO);
while (priv->chan[ch].fifo[tail].dma_desc != cur_desc) {
tail = (tail + 1) & (priv->fifo_len - 1);
if (tail == priv->chan[ch].tail) {
dev_err(dev, "couldn't locate current descriptor\n");
return 0;
}
}
return priv->chan[ch].fifo[tail].desc->hdr;
}
static void report_eu_error(struct device *dev, int ch, u32 desc_hdr)
{
struct talitos_private *priv = dev_get_drvdata(dev);
int i;
if (!desc_hdr)
desc_hdr = in_be32(priv->chan[ch].reg + TALITOS_DESCBUF);
switch (desc_hdr & DESC_HDR_SEL0_MASK) {
case DESC_HDR_SEL0_AFEU:
dev_err(dev, "AFEUISR 0x%08x_%08x\n",
in_be32(priv->reg + TALITOS_AFEUISR),
in_be32(priv->reg + TALITOS_AFEUISR_LO));
break;
case DESC_HDR_SEL0_DEU:
dev_err(dev, "DEUISR 0x%08x_%08x\n",
in_be32(priv->reg + TALITOS_DEUISR),
in_be32(priv->reg + TALITOS_DEUISR_LO));
break;
case DESC_HDR_SEL0_MDEUA:
case DESC_HDR_SEL0_MDEUB:
dev_err(dev, "MDEUISR 0x%08x_%08x\n",
in_be32(priv->reg + TALITOS_MDEUISR),
in_be32(priv->reg + TALITOS_MDEUISR_LO));
break;
case DESC_HDR_SEL0_RNG:
dev_err(dev, "RNGUISR 0x%08x_%08x\n",
in_be32(priv->reg + TALITOS_RNGUISR),
in_be32(priv->reg + TALITOS_RNGUISR_LO));
break;
case DESC_HDR_SEL0_PKEU:
dev_err(dev, "PKEUISR 0x%08x_%08x\n",
in_be32(priv->reg + TALITOS_PKEUISR),
in_be32(priv->reg + TALITOS_PKEUISR_LO));
break;
case DESC_HDR_SEL0_AESU:
dev_err(dev, "AESUISR 0x%08x_%08x\n",
in_be32(priv->reg + TALITOS_AESUISR),
in_be32(priv->reg + TALITOS_AESUISR_LO));
break;
case DESC_HDR_SEL0_CRCU:
dev_err(dev, "CRCUISR 0x%08x_%08x\n",
in_be32(priv->reg + TALITOS_CRCUISR),
in_be32(priv->reg + TALITOS_CRCUISR_LO));
break;
case DESC_HDR_SEL0_KEU:
dev_err(dev, "KEUISR 0x%08x_%08x\n",
in_be32(priv->reg + TALITOS_KEUISR),
in_be32(priv->reg + TALITOS_KEUISR_LO));
break;
}
switch (desc_hdr & DESC_HDR_SEL1_MASK) {
case DESC_HDR_SEL1_MDEUA:
case DESC_HDR_SEL1_MDEUB:
dev_err(dev, "MDEUISR 0x%08x_%08x\n",
in_be32(priv->reg + TALITOS_MDEUISR),
in_be32(priv->reg + TALITOS_MDEUISR_LO));
break;
case DESC_HDR_SEL1_CRCU:
dev_err(dev, "CRCUISR 0x%08x_%08x\n",
in_be32(priv->reg + TALITOS_CRCUISR),
in_be32(priv->reg + TALITOS_CRCUISR_LO));
break;
}
for (i = 0; i < 8; i++)
dev_err(dev, "DESCBUF 0x%08x_%08x\n",
in_be32(priv->chan[ch].reg + TALITOS_DESCBUF + 8*i),
in_be32(priv->chan[ch].reg + TALITOS_DESCBUF_LO + 8*i));
}
static void talitos_error(struct device *dev, u32 isr, u32 isr_lo)
{
struct talitos_private *priv = dev_get_drvdata(dev);
unsigned int timeout = TALITOS_TIMEOUT;
int ch, error, reset_dev = 0, reset_ch = 0;
u32 v, v_lo;
for (ch = 0; ch < priv->num_channels; ch++) {
if (!(isr & (1 << (ch * 2 + 1))))
continue;
error = -EINVAL;
v = in_be32(priv->chan[ch].reg + TALITOS_CCPSR);
v_lo = in_be32(priv->chan[ch].reg + TALITOS_CCPSR_LO);
if (v_lo & TALITOS_CCPSR_LO_DOF) {
dev_err(dev, "double fetch fifo overflow error\n");
error = -EAGAIN;
reset_ch = 1;
}
if (v_lo & TALITOS_CCPSR_LO_SOF) {
dev_err(dev, "single fetch fifo overflow error\n");
error = -EAGAIN;
}
if (v_lo & TALITOS_CCPSR_LO_MDTE)
dev_err(dev, "master data transfer error\n");
if (v_lo & TALITOS_CCPSR_LO_SGDLZ)
dev_err(dev, "s/g data length zero error\n");
if (v_lo & TALITOS_CCPSR_LO_FPZ)
dev_err(dev, "fetch pointer zero error\n");
if (v_lo & TALITOS_CCPSR_LO_IDH)
dev_err(dev, "illegal descriptor header error\n");
if (v_lo & TALITOS_CCPSR_LO_IEU)
dev_err(dev, "invalid execution unit error\n");
if (v_lo & TALITOS_CCPSR_LO_EU)
report_eu_error(dev, ch, current_desc_hdr(dev, ch));
if (v_lo & TALITOS_CCPSR_LO_GB)
dev_err(dev, "gather boundary error\n");
if (v_lo & TALITOS_CCPSR_LO_GRL)
dev_err(dev, "gather return/length error\n");
if (v_lo & TALITOS_CCPSR_LO_SB)
dev_err(dev, "scatter boundary error\n");
if (v_lo & TALITOS_CCPSR_LO_SRL)
dev_err(dev, "scatter return/length error\n");
flush_channel(dev, ch, error, reset_ch);
if (reset_ch) {
reset_channel(dev, ch);
} else {
setbits32(priv->chan[ch].reg + TALITOS_CCCR,
TALITOS_CCCR_CONT);
setbits32(priv->chan[ch].reg + TALITOS_CCCR_LO, 0);
while ((in_be32(priv->chan[ch].reg + TALITOS_CCCR) &
TALITOS_CCCR_CONT) && --timeout)
cpu_relax();
if (timeout == 0) {
dev_err(dev, "failed to restart channel %d\n",
ch);
reset_dev = 1;
}
}
}
if (reset_dev || isr & ~TALITOS_ISR_4CHERR || isr_lo) {
dev_err(dev, "done overflow, internal time out, or rngu error: "
"ISR 0x%08x_%08x\n", isr, isr_lo);
for (ch = 0; ch < priv->num_channels; ch++)
flush_channel(dev, ch, -EIO, 1);
init_device(dev);
}
}
static int talitos_rng_data_present(struct hwrng *rng, int wait)
{
struct device *dev = (struct device *)rng->priv;
struct talitos_private *priv = dev_get_drvdata(dev);
u32 ofl;
int i;
for (i = 0; i < 20; i++) {
ofl = in_be32(priv->reg + TALITOS_RNGUSR_LO) &
TALITOS_RNGUSR_LO_OFL;
if (ofl || !wait)
break;
udelay(10);
}
return !!ofl;
}
static int talitos_rng_data_read(struct hwrng *rng, u32 *data)
{
struct device *dev = (struct device *)rng->priv;
struct talitos_private *priv = dev_get_drvdata(dev);
*data = in_be32(priv->reg + TALITOS_RNGU_FIFO);
*data = in_be32(priv->reg + TALITOS_RNGU_FIFO_LO);
return sizeof(u32);
}
static int talitos_rng_init(struct hwrng *rng)
{
struct device *dev = (struct device *)rng->priv;
struct talitos_private *priv = dev_get_drvdata(dev);
unsigned int timeout = TALITOS_TIMEOUT;
setbits32(priv->reg + TALITOS_RNGURCR_LO, TALITOS_RNGURCR_LO_SR);
while (!(in_be32(priv->reg + TALITOS_RNGUSR_LO) & TALITOS_RNGUSR_LO_RD)
&& --timeout)
cpu_relax();
if (timeout == 0) {
dev_err(dev, "failed to reset rng hw\n");
return -ENODEV;
}
setbits32(priv->reg + TALITOS_RNGUDSR_LO, 0);
return 0;
}
static int talitos_register_rng(struct device *dev)
{
struct talitos_private *priv = dev_get_drvdata(dev);
priv->rng.name = dev_driver_string(dev),
priv->rng.init = talitos_rng_init,
priv->rng.data_present = talitos_rng_data_present,
priv->rng.data_read = talitos_rng_data_read,
priv->rng.priv = (unsigned long)dev;
return hwrng_register(&priv->rng);
}
static void talitos_unregister_rng(struct device *dev)
{
struct talitos_private *priv = dev_get_drvdata(dev);
hwrng_unregister(&priv->rng);
}
static int aead_setauthsize(struct crypto_aead *authenc,
unsigned int authsize)
{
struct talitos_ctx *ctx = crypto_aead_ctx(authenc);
ctx->authsize = authsize;
return 0;
}
static int aead_setkey(struct crypto_aead *authenc,
const u8 *key, unsigned int keylen)
{
struct talitos_ctx *ctx = crypto_aead_ctx(authenc);
struct rtattr *rta = (void *)key;
struct crypto_authenc_key_param *param;
unsigned int authkeylen;
unsigned int enckeylen;
if (!RTA_OK(rta, keylen))
goto badkey;
if (rta->rta_type != CRYPTO_AUTHENC_KEYA_PARAM)
goto badkey;
if (RTA_PAYLOAD(rta) < sizeof(*param))
goto badkey;
param = RTA_DATA(rta);
enckeylen = be32_to_cpu(param->enckeylen);
key += RTA_ALIGN(rta->rta_len);
keylen -= RTA_ALIGN(rta->rta_len);
if (keylen < enckeylen)
goto badkey;
authkeylen = keylen - enckeylen;
if (keylen > TALITOS_MAX_KEY_SIZE)
goto badkey;
memcpy(&ctx->key, key, keylen);
ctx->keylen = keylen;
ctx->enckeylen = enckeylen;
ctx->authkeylen = authkeylen;
return 0;
badkey:
crypto_aead_set_flags(authenc, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
static int talitos_map_sg(struct device *dev, struct scatterlist *sg,
unsigned int nents, enum dma_data_direction dir,
int chained)
{
if (unlikely(chained))
while (sg) {
dma_map_sg(dev, sg, 1, dir);
sg = scatterwalk_sg_next(sg);
}
else
dma_map_sg(dev, sg, nents, dir);
return nents;
}
static void talitos_unmap_sg_chain(struct device *dev, struct scatterlist *sg,
enum dma_data_direction dir)
{
while (sg) {
dma_unmap_sg(dev, sg, 1, dir);
sg = scatterwalk_sg_next(sg);
}
}
static void talitos_sg_unmap(struct device *dev,
struct talitos_edesc *edesc,
struct scatterlist *src,
struct scatterlist *dst)
{
unsigned int src_nents = edesc->src_nents ? : 1;
unsigned int dst_nents = edesc->dst_nents ? : 1;
if (src != dst) {
if (edesc->src_is_chained)
talitos_unmap_sg_chain(dev, src, DMA_TO_DEVICE);
else
dma_unmap_sg(dev, src, src_nents, DMA_TO_DEVICE);
if (dst) {
if (edesc->dst_is_chained)
talitos_unmap_sg_chain(dev, dst,
DMA_FROM_DEVICE);
else
dma_unmap_sg(dev, dst, dst_nents,
DMA_FROM_DEVICE);
}
} else
if (edesc->src_is_chained)
talitos_unmap_sg_chain(dev, src, DMA_BIDIRECTIONAL);
else
dma_unmap_sg(dev, src, src_nents, DMA_BIDIRECTIONAL);
}
static void ipsec_esp_unmap(struct device *dev,
struct talitos_edesc *edesc,
struct aead_request *areq)
{
unmap_single_talitos_ptr(dev, &edesc->desc.ptr[6], DMA_FROM_DEVICE);
unmap_single_talitos_ptr(dev, &edesc->desc.ptr[3], DMA_TO_DEVICE);
unmap_single_talitos_ptr(dev, &edesc->desc.ptr[2], DMA_TO_DEVICE);
unmap_single_talitos_ptr(dev, &edesc->desc.ptr[0], DMA_TO_DEVICE);
dma_unmap_sg(dev, areq->assoc, 1, DMA_TO_DEVICE);
talitos_sg_unmap(dev, edesc, areq->src, areq->dst);
if (edesc->dma_len)
dma_unmap_single(dev, edesc->dma_link_tbl, edesc->dma_len,
DMA_BIDIRECTIONAL);
}
static void ipsec_esp_encrypt_done(struct device *dev,
struct talitos_desc *desc, void *context,
int err)
{
struct aead_request *areq = context;
struct crypto_aead *authenc = crypto_aead_reqtfm(areq);
struct talitos_ctx *ctx = crypto_aead_ctx(authenc);
struct talitos_edesc *edesc;
struct scatterlist *sg;
void *icvdata;
edesc = container_of(desc, struct talitos_edesc, desc);
ipsec_esp_unmap(dev, edesc, areq);
if (edesc->dma_len) {
icvdata = &edesc->link_tbl[edesc->src_nents +
edesc->dst_nents + 2];
sg = sg_last(areq->dst, edesc->dst_nents);
memcpy((char *)sg_virt(sg) + sg->length - ctx->authsize,
icvdata, ctx->authsize);
}
kfree(edesc);
aead_request_complete(areq, err);
}
static void ipsec_esp_decrypt_swauth_done(struct device *dev,
struct talitos_desc *desc,
void *context, int err)
{
struct aead_request *req = context;
struct crypto_aead *authenc = crypto_aead_reqtfm(req);
struct talitos_ctx *ctx = crypto_aead_ctx(authenc);
struct talitos_edesc *edesc;
struct scatterlist *sg;
void *icvdata;
edesc = container_of(desc, struct talitos_edesc, desc);
ipsec_esp_unmap(dev, edesc, req);
if (!err) {
if (edesc->dma_len)
icvdata = &edesc->link_tbl[edesc->src_nents +
edesc->dst_nents + 2];
else
icvdata = &edesc->link_tbl[0];
sg = sg_last(req->dst, edesc->dst_nents ? : 1);
err = memcmp(icvdata, (char *)sg_virt(sg) + sg->length -
ctx->authsize, ctx->authsize) ? -EBADMSG : 0;
}
kfree(edesc);
aead_request_complete(req, err);
}
static void ipsec_esp_decrypt_hwauth_done(struct device *dev,
struct talitos_desc *desc,
void *context, int err)
{
struct aead_request *req = context;
struct talitos_edesc *edesc;
edesc = container_of(desc, struct talitos_edesc, desc);
ipsec_esp_unmap(dev, edesc, req);
if (!err && ((desc->hdr_lo & DESC_HDR_LO_ICCR1_MASK) !=
DESC_HDR_LO_ICCR1_PASS))
err = -EBADMSG;
kfree(edesc);
aead_request_complete(req, err);
}
static int sg_to_link_tbl(struct scatterlist *sg, int sg_count,
int cryptlen, struct talitos_ptr *link_tbl_ptr)
{
int n_sg = sg_count;
while (n_sg--) {
to_talitos_ptr(link_tbl_ptr, sg_dma_address(sg));
link_tbl_ptr->len = cpu_to_be16(sg_dma_len(sg));
link_tbl_ptr->j_extent = 0;
link_tbl_ptr++;
cryptlen -= sg_dma_len(sg);
sg = scatterwalk_sg_next(sg);
}
link_tbl_ptr--;
while (be16_to_cpu(link_tbl_ptr->len) <= (-cryptlen)) {
cryptlen += be16_to_cpu(link_tbl_ptr->len);
link_tbl_ptr->len = 0;
sg_count--;
link_tbl_ptr--;
}
link_tbl_ptr->len = cpu_to_be16(be16_to_cpu(link_tbl_ptr->len)
+ cryptlen);
link_tbl_ptr->j_extent = DESC_PTR_LNKTBL_RETURN;
return sg_count;
}
static int ipsec_esp(struct talitos_edesc *edesc, struct aead_request *areq,
u8 *giv, u64 seq,
void (*callback) (struct device *dev,
struct talitos_desc *desc,
void *context, int error))
{
struct crypto_aead *aead = crypto_aead_reqtfm(areq);
struct talitos_ctx *ctx = crypto_aead_ctx(aead);
struct device *dev = ctx->dev;
struct talitos_desc *desc = &edesc->desc;
unsigned int cryptlen = areq->cryptlen;
unsigned int authsize = ctx->authsize;
unsigned int ivsize = crypto_aead_ivsize(aead);
int sg_count, ret;
int sg_link_tbl_len;
map_single_talitos_ptr(dev, &desc->ptr[0], ctx->authkeylen, &ctx->key,
0, DMA_TO_DEVICE);
map_single_talitos_ptr(dev, &desc->ptr[1], areq->assoclen + ivsize,
sg_virt(areq->assoc), 0, DMA_TO_DEVICE);
map_single_talitos_ptr(dev, &desc->ptr[2], ivsize, giv ?: areq->iv, 0,
DMA_TO_DEVICE);
map_single_talitos_ptr(dev, &desc->ptr[3], ctx->enckeylen,
(char *)&ctx->key + ctx->authkeylen, 0,
DMA_TO_DEVICE);
desc->ptr[4].len = cpu_to_be16(cryptlen);
desc->ptr[4].j_extent = authsize;
sg_count = talitos_map_sg(dev, areq->src, edesc->src_nents ? : 1,
(areq->src == areq->dst) ? DMA_BIDIRECTIONAL
: DMA_TO_DEVICE,
edesc->src_is_chained);
if (sg_count == 1) {
to_talitos_ptr(&desc->ptr[4], sg_dma_address(areq->src));
} else {
sg_link_tbl_len = cryptlen;
if (edesc->desc.hdr & DESC_HDR_MODE1_MDEU_CICV)
sg_link_tbl_len = cryptlen + authsize;
sg_count = sg_to_link_tbl(areq->src, sg_count, sg_link_tbl_len,
&edesc->link_tbl[0]);
if (sg_count > 1) {
desc->ptr[4].j_extent |= DESC_PTR_LNKTBL_JUMP;
to_talitos_ptr(&desc->ptr[4], edesc->dma_link_tbl);
dma_sync_single_for_device(dev, edesc->dma_link_tbl,
edesc->dma_len,
DMA_BIDIRECTIONAL);
} else {
to_talitos_ptr(&desc->ptr[4],
sg_dma_address(areq->src));
}
}
desc->ptr[5].len = cpu_to_be16(cryptlen);
desc->ptr[5].j_extent = authsize;
if (areq->src != areq->dst)
sg_count = talitos_map_sg(dev, areq->dst,
edesc->dst_nents ? : 1,
DMA_FROM_DEVICE,
edesc->dst_is_chained);
if (sg_count == 1) {
to_talitos_ptr(&desc->ptr[5], sg_dma_address(areq->dst));
} else {
struct talitos_ptr *link_tbl_ptr =
&edesc->link_tbl[edesc->src_nents + 1];
to_talitos_ptr(&desc->ptr[5], edesc->dma_link_tbl +
(edesc->src_nents + 1) *
sizeof(struct talitos_ptr));
sg_count = sg_to_link_tbl(areq->dst, sg_count, cryptlen,
link_tbl_ptr);
link_tbl_ptr += sg_count - 1;
link_tbl_ptr->j_extent = 0;
sg_count++;
link_tbl_ptr++;
link_tbl_ptr->j_extent = DESC_PTR_LNKTBL_RETURN;
link_tbl_ptr->len = cpu_to_be16(authsize);
to_talitos_ptr(link_tbl_ptr, edesc->dma_link_tbl +
(edesc->src_nents + edesc->dst_nents + 2) *
sizeof(struct talitos_ptr));
desc->ptr[5].j_extent |= DESC_PTR_LNKTBL_JUMP;
dma_sync_single_for_device(ctx->dev, edesc->dma_link_tbl,
edesc->dma_len, DMA_BIDIRECTIONAL);
}
map_single_talitos_ptr(dev, &desc->ptr[6], ivsize, ctx->iv, 0,
DMA_FROM_DEVICE);
ret = talitos_submit(dev, ctx->ch, desc, callback, areq);
if (ret != -EINPROGRESS) {
ipsec_esp_unmap(dev, edesc, areq);
kfree(edesc);
}
return ret;
}
static int sg_count(struct scatterlist *sg_list, int nbytes, int *chained)
{
struct scatterlist *sg = sg_list;
int sg_nents = 0;
*chained = 0;
while (nbytes > 0) {
sg_nents++;
nbytes -= sg->length;
if (!sg_is_last(sg) && (sg + 1)->length == 0)
*chained = 1;
sg = scatterwalk_sg_next(sg);
}
return sg_nents;
}
static size_t sg_copy_end_to_buffer(struct scatterlist *sgl, unsigned int nents,
void *buf, size_t buflen, unsigned int skip)
{
unsigned int offset = 0;
unsigned int boffset = 0;
struct sg_mapping_iter miter;
unsigned long flags;
unsigned int sg_flags = SG_MITER_ATOMIC;
size_t total_buffer = buflen + skip;
sg_flags |= SG_MITER_FROM_SG;
sg_miter_start(&miter, sgl, nents, sg_flags);
local_irq_save(flags);
while (sg_miter_next(&miter) && offset < total_buffer) {
unsigned int len;
unsigned int ignore;
if ((offset + miter.length) > skip) {
if (offset < skip) {
ignore = skip - offset;
len = miter.length - ignore;
if (boffset + len > buflen)
len = buflen - boffset;
memcpy(buf + boffset, miter.addr + ignore, len);
} else {
len = miter.length;
if (boffset + len > buflen)
len = buflen - boffset;
memcpy(buf + boffset, miter.addr, len);
}
boffset += len;
}
offset += miter.length;
}
sg_miter_stop(&miter);
local_irq_restore(flags);
return boffset;
}
static struct talitos_edesc *talitos_edesc_alloc(struct device *dev,
struct scatterlist *src,
struct scatterlist *dst,
int hash_result,
unsigned int cryptlen,
unsigned int authsize,
int icv_stashing,
u32 cryptoflags)
{
struct talitos_edesc *edesc;
int src_nents, dst_nents, alloc_len, dma_len;
int src_chained, dst_chained = 0;
gfp_t flags = cryptoflags & CRYPTO_TFM_REQ_MAY_SLEEP ? GFP_KERNEL :
GFP_ATOMIC;
if (cryptlen + authsize > TALITOS_MAX_DATA_LEN) {
dev_err(dev, "length exceeds h/w max limit\n");
return ERR_PTR(-EINVAL);
}
src_nents = sg_count(src, cryptlen + authsize, &src_chained);
src_nents = (src_nents == 1) ? 0 : src_nents;
if (hash_result) {
dst_nents = 0;
} else {
if (dst == src) {
dst_nents = src_nents;
} else {
dst_nents = sg_count(dst, cryptlen + authsize,
&dst_chained);
dst_nents = (dst_nents == 1) ? 0 : dst_nents;
}
}
alloc_len = sizeof(struct talitos_edesc);
if (src_nents || dst_nents) {
dma_len = (src_nents + dst_nents + 2) *
sizeof(struct talitos_ptr) + authsize;
alloc_len += dma_len;
} else {
dma_len = 0;
alloc_len += icv_stashing ? authsize : 0;
}
edesc = kmalloc(alloc_len, GFP_DMA | flags);
if (!edesc) {
dev_err(dev, "could not allocate edescriptor\n");
return ERR_PTR(-ENOMEM);
}
edesc->src_nents = src_nents;
edesc->dst_nents = dst_nents;
edesc->src_is_chained = src_chained;
edesc->dst_is_chained = dst_chained;
edesc->dma_len = dma_len;
if (dma_len)
edesc->dma_link_tbl = dma_map_single(dev, &edesc->link_tbl[0],
edesc->dma_len,
DMA_BIDIRECTIONAL);
return edesc;
}
static struct talitos_edesc *aead_edesc_alloc(struct aead_request *areq,
int icv_stashing)
{
struct crypto_aead *authenc = crypto_aead_reqtfm(areq);
struct talitos_ctx *ctx = crypto_aead_ctx(authenc);
return talitos_edesc_alloc(ctx->dev, areq->src, areq->dst, 0,
areq->cryptlen, ctx->authsize, icv_stashing,
areq->base.flags);
}
static int aead_encrypt(struct aead_request *req)
{
struct crypto_aead *authenc = crypto_aead_reqtfm(req);
struct talitos_ctx *ctx = crypto_aead_ctx(authenc);
struct talitos_edesc *edesc;
edesc = aead_edesc_alloc(req, 0);
if (IS_ERR(edesc))
return PTR_ERR(edesc);
edesc->desc.hdr = ctx->desc_hdr_template | DESC_HDR_MODE0_ENCRYPT;
return ipsec_esp(edesc, req, NULL, 0, ipsec_esp_encrypt_done);
}
static int aead_decrypt(struct aead_request *req)
{
struct crypto_aead *authenc = crypto_aead_reqtfm(req);
struct talitos_ctx *ctx = crypto_aead_ctx(authenc);
unsigned int authsize = ctx->authsize;
struct talitos_private *priv = dev_get_drvdata(ctx->dev);
struct talitos_edesc *edesc;
struct scatterlist *sg;
void *icvdata;
req->cryptlen -= authsize;
edesc = aead_edesc_alloc(req, 1);
if (IS_ERR(edesc))
return PTR_ERR(edesc);
if ((priv->features & TALITOS_FTR_HW_AUTH_CHECK) &&
((!edesc->src_nents && !edesc->dst_nents) ||
priv->features & TALITOS_FTR_SRC_LINK_TBL_LEN_INCLUDES_EXTENT)) {
edesc->desc.hdr = ctx->desc_hdr_template |
DESC_HDR_DIR_INBOUND |
DESC_HDR_MODE1_MDEU_CICV;
edesc->desc.hdr_lo = 0;
return ipsec_esp(edesc, req, NULL, 0,
ipsec_esp_decrypt_hwauth_done);
}
edesc->desc.hdr = ctx->desc_hdr_template | DESC_HDR_DIR_INBOUND;
if (edesc->dma_len)
icvdata = &edesc->link_tbl[edesc->src_nents +
edesc->dst_nents + 2];
else
icvdata = &edesc->link_tbl[0];
sg = sg_last(req->src, edesc->src_nents ? : 1);
memcpy(icvdata, (char *)sg_virt(sg) + sg->length - ctx->authsize,
ctx->authsize);
return ipsec_esp(edesc, req, NULL, 0, ipsec_esp_decrypt_swauth_done);
}
static int aead_givencrypt(struct aead_givcrypt_request *req)
{
struct aead_request *areq = &req->areq;
struct crypto_aead *authenc = crypto_aead_reqtfm(areq);
struct talitos_ctx *ctx = crypto_aead_ctx(authenc);
struct talitos_edesc *edesc;
edesc = aead_edesc_alloc(areq, 0);
if (IS_ERR(edesc))
return PTR_ERR(edesc);
edesc->desc.hdr = ctx->desc_hdr_template | DESC_HDR_MODE0_ENCRYPT;
memcpy(req->giv, ctx->iv, crypto_aead_ivsize(authenc));
*(__be64 *)req->giv ^= cpu_to_be64(req->seq);
return ipsec_esp(edesc, areq, req->giv, req->seq,
ipsec_esp_encrypt_done);
}
static int ablkcipher_setkey(struct crypto_ablkcipher *cipher,
const u8 *key, unsigned int keylen)
{
struct talitos_ctx *ctx = crypto_ablkcipher_ctx(cipher);
memcpy(&ctx->key, key, keylen);
ctx->keylen = keylen;
return 0;
}
static void common_nonsnoop_unmap(struct device *dev,
struct talitos_edesc *edesc,
struct ablkcipher_request *areq)
{
unmap_single_talitos_ptr(dev, &edesc->desc.ptr[5], DMA_FROM_DEVICE);
unmap_single_talitos_ptr(dev, &edesc->desc.ptr[2], DMA_TO_DEVICE);
unmap_single_talitos_ptr(dev, &edesc->desc.ptr[1], DMA_TO_DEVICE);
talitos_sg_unmap(dev, edesc, areq->src, areq->dst);
if (edesc->dma_len)
dma_unmap_single(dev, edesc->dma_link_tbl, edesc->dma_len,
DMA_BIDIRECTIONAL);
}
static void ablkcipher_done(struct device *dev,
struct talitos_desc *desc, void *context,
int err)
{
struct ablkcipher_request *areq = context;
struct talitos_edesc *edesc;
edesc = container_of(desc, struct talitos_edesc, desc);
common_nonsnoop_unmap(dev, edesc, areq);
kfree(edesc);
areq->base.complete(&areq->base, err);
}
static int common_nonsnoop(struct talitos_edesc *edesc,
struct ablkcipher_request *areq,
void (*callback) (struct device *dev,
struct talitos_desc *desc,
void *context, int error))
{
struct crypto_ablkcipher *cipher = crypto_ablkcipher_reqtfm(areq);
struct talitos_ctx *ctx = crypto_ablkcipher_ctx(cipher);
struct device *dev = ctx->dev;
struct talitos_desc *desc = &edesc->desc;
unsigned int cryptlen = areq->nbytes;
unsigned int ivsize;
int sg_count, ret;
desc->ptr[0].len = 0;
to_talitos_ptr(&desc->ptr[0], 0);
desc->ptr[0].j_extent = 0;
ivsize = crypto_ablkcipher_ivsize(cipher);
map_single_talitos_ptr(dev, &desc->ptr[1], ivsize, areq->info, 0,
DMA_TO_DEVICE);
map_single_talitos_ptr(dev, &desc->ptr[2], ctx->keylen,
(char *)&ctx->key, 0, DMA_TO_DEVICE);
desc->ptr[3].len = cpu_to_be16(cryptlen);
desc->ptr[3].j_extent = 0;
sg_count = talitos_map_sg(dev, areq->src, edesc->src_nents ? : 1,
(areq->src == areq->dst) ? DMA_BIDIRECTIONAL
: DMA_TO_DEVICE,
edesc->src_is_chained);
if (sg_count == 1) {
to_talitos_ptr(&desc->ptr[3], sg_dma_address(areq->src));
} else {
sg_count = sg_to_link_tbl(areq->src, sg_count, cryptlen,
&edesc->link_tbl[0]);
if (sg_count > 1) {
to_talitos_ptr(&desc->ptr[3], edesc->dma_link_tbl);
desc->ptr[3].j_extent |= DESC_PTR_LNKTBL_JUMP;
dma_sync_single_for_device(dev, edesc->dma_link_tbl,
edesc->dma_len,
DMA_BIDIRECTIONAL);
} else {
to_talitos_ptr(&desc->ptr[3],
sg_dma_address(areq->src));
}
}
desc->ptr[4].len = cpu_to_be16(cryptlen);
desc->ptr[4].j_extent = 0;
if (areq->src != areq->dst)
sg_count = talitos_map_sg(dev, areq->dst,
edesc->dst_nents ? : 1,
DMA_FROM_DEVICE,
edesc->dst_is_chained);
if (sg_count == 1) {
to_talitos_ptr(&desc->ptr[4], sg_dma_address(areq->dst));
} else {
struct talitos_ptr *link_tbl_ptr =
&edesc->link_tbl[edesc->src_nents + 1];
to_talitos_ptr(&desc->ptr[4], edesc->dma_link_tbl +
(edesc->src_nents + 1) *
sizeof(struct talitos_ptr));
desc->ptr[4].j_extent |= DESC_PTR_LNKTBL_JUMP;
sg_count = sg_to_link_tbl(areq->dst, sg_count, cryptlen,
link_tbl_ptr);
dma_sync_single_for_device(ctx->dev, edesc->dma_link_tbl,
edesc->dma_len, DMA_BIDIRECTIONAL);
}
map_single_talitos_ptr(dev, &desc->ptr[5], ivsize, ctx->iv, 0,
DMA_FROM_DEVICE);
desc->ptr[6].len = 0;
to_talitos_ptr(&desc->ptr[6], 0);
desc->ptr[6].j_extent = 0;
ret = talitos_submit(dev, ctx->ch, desc, callback, areq);
if (ret != -EINPROGRESS) {
common_nonsnoop_unmap(dev, edesc, areq);
kfree(edesc);
}
return ret;
}
static struct talitos_edesc *ablkcipher_edesc_alloc(struct ablkcipher_request *
areq)
{
struct crypto_ablkcipher *cipher = crypto_ablkcipher_reqtfm(areq);
struct talitos_ctx *ctx = crypto_ablkcipher_ctx(cipher);
return talitos_edesc_alloc(ctx->dev, areq->src, areq->dst, 0,
areq->nbytes, 0, 0, areq->base.flags);
}
static int ablkcipher_encrypt(struct ablkcipher_request *areq)
{
struct crypto_ablkcipher *cipher = crypto_ablkcipher_reqtfm(areq);
struct talitos_ctx *ctx = crypto_ablkcipher_ctx(cipher);
struct talitos_edesc *edesc;
edesc = ablkcipher_edesc_alloc(areq);
if (IS_ERR(edesc))
return PTR_ERR(edesc);
edesc->desc.hdr = ctx->desc_hdr_template | DESC_HDR_MODE0_ENCRYPT;
return common_nonsnoop(edesc, areq, ablkcipher_done);
}
static int ablkcipher_decrypt(struct ablkcipher_request *areq)
{
struct crypto_ablkcipher *cipher = crypto_ablkcipher_reqtfm(areq);
struct talitos_ctx *ctx = crypto_ablkcipher_ctx(cipher);
struct talitos_edesc *edesc;
edesc = ablkcipher_edesc_alloc(areq);
if (IS_ERR(edesc))
return PTR_ERR(edesc);
edesc->desc.hdr = ctx->desc_hdr_template | DESC_HDR_DIR_INBOUND;
return common_nonsnoop(edesc, areq, ablkcipher_done);
}
static void common_nonsnoop_hash_unmap(struct device *dev,
struct talitos_edesc *edesc,
struct ahash_request *areq)
{
struct talitos_ahash_req_ctx *req_ctx = ahash_request_ctx(areq);
unmap_single_talitos_ptr(dev, &edesc->desc.ptr[5], DMA_FROM_DEVICE);
if (edesc->desc.ptr[1].len)
unmap_single_talitos_ptr(dev, &edesc->desc.ptr[1],
DMA_TO_DEVICE);
if (edesc->desc.ptr[2].len)
unmap_single_talitos_ptr(dev, &edesc->desc.ptr[2],
DMA_TO_DEVICE);
talitos_sg_unmap(dev, edesc, req_ctx->psrc, NULL);
if (edesc->dma_len)
dma_unmap_single(dev, edesc->dma_link_tbl, edesc->dma_len,
DMA_BIDIRECTIONAL);
}
static void ahash_done(struct device *dev,
struct talitos_desc *desc, void *context,
int err)
{
struct ahash_request *areq = context;
struct talitos_edesc *edesc =
container_of(desc, struct talitos_edesc, desc);
struct talitos_ahash_req_ctx *req_ctx = ahash_request_ctx(areq);
if (!req_ctx->last && req_ctx->to_hash_later) {
memcpy(req_ctx->buf, req_ctx->bufnext, req_ctx->to_hash_later);
req_ctx->nbuf = req_ctx->to_hash_later;
}
common_nonsnoop_hash_unmap(dev, edesc, areq);
kfree(edesc);
areq->base.complete(&areq->base, err);
}
static int common_nonsnoop_hash(struct talitos_edesc *edesc,
struct ahash_request *areq, unsigned int length,
void (*callback) (struct device *dev,
struct talitos_desc *desc,
void *context, int error))
{
struct crypto_ahash *tfm = crypto_ahash_reqtfm(areq);
struct talitos_ctx *ctx = crypto_ahash_ctx(tfm);
struct talitos_ahash_req_ctx *req_ctx = ahash_request_ctx(areq);
struct device *dev = ctx->dev;
struct talitos_desc *desc = &edesc->desc;
int sg_count, ret;
desc->ptr[0] = zero_entry;
if (!req_ctx->first || req_ctx->swinit) {
map_single_talitos_ptr(dev, &desc->ptr[1],
req_ctx->hw_context_size,
(char *)req_ctx->hw_context, 0,
DMA_TO_DEVICE);
req_ctx->swinit = 0;
} else {
desc->ptr[1] = zero_entry;
req_ctx->first = 0;
}
if (ctx->keylen)
map_single_talitos_ptr(dev, &desc->ptr[2], ctx->keylen,
(char *)&ctx->key, 0, DMA_TO_DEVICE);
else
desc->ptr[2] = zero_entry;
desc->ptr[3].len = cpu_to_be16(length);
desc->ptr[3].j_extent = 0;
sg_count = talitos_map_sg(dev, req_ctx->psrc,
edesc->src_nents ? : 1,
DMA_TO_DEVICE,
edesc->src_is_chained);
if (sg_count == 1) {
to_talitos_ptr(&desc->ptr[3], sg_dma_address(req_ctx->psrc));
} else {
sg_count = sg_to_link_tbl(req_ctx->psrc, sg_count, length,
&edesc->link_tbl[0]);
if (sg_count > 1) {
desc->ptr[3].j_extent |= DESC_PTR_LNKTBL_JUMP;
to_talitos_ptr(&desc->ptr[3], edesc->dma_link_tbl);
dma_sync_single_for_device(ctx->dev,
edesc->dma_link_tbl,
edesc->dma_len,
DMA_BIDIRECTIONAL);
} else {
to_talitos_ptr(&desc->ptr[3],
sg_dma_address(req_ctx->psrc));
}
}
desc->ptr[4] = zero_entry;
if (req_ctx->last)
map_single_talitos_ptr(dev, &desc->ptr[5],
crypto_ahash_digestsize(tfm),
areq->result, 0, DMA_FROM_DEVICE);
else
map_single_talitos_ptr(dev, &desc->ptr[5],
req_ctx->hw_context_size,
req_ctx->hw_context, 0, DMA_FROM_DEVICE);
desc->ptr[6] = zero_entry;
ret = talitos_submit(dev, ctx->ch, desc, callback, areq);
if (ret != -EINPROGRESS) {
common_nonsnoop_hash_unmap(dev, edesc, areq);
kfree(edesc);
}
return ret;
}
static struct talitos_edesc *ahash_edesc_alloc(struct ahash_request *areq,
unsigned int nbytes)
{
struct crypto_ahash *tfm = crypto_ahash_reqtfm(areq);
struct talitos_ctx *ctx = crypto_ahash_ctx(tfm);
struct talitos_ahash_req_ctx *req_ctx = ahash_request_ctx(areq);
return talitos_edesc_alloc(ctx->dev, req_ctx->psrc, NULL, 1,
nbytes, 0, 0, areq->base.flags);
}
static int ahash_init(struct ahash_request *areq)
{
struct crypto_ahash *tfm = crypto_ahash_reqtfm(areq);
struct talitos_ahash_req_ctx *req_ctx = ahash_request_ctx(areq);
req_ctx->nbuf = 0;
req_ctx->first = 1;
req_ctx->swinit = 0;
req_ctx->hw_context_size =
(crypto_ahash_digestsize(tfm) <= SHA256_DIGEST_SIZE)
? TALITOS_MDEU_CONTEXT_SIZE_MD5_SHA1_SHA256
: TALITOS_MDEU_CONTEXT_SIZE_SHA384_SHA512;
return 0;
}
static int ahash_init_sha224_swinit(struct ahash_request *areq)
{
struct talitos_ahash_req_ctx *req_ctx = ahash_request_ctx(areq);
ahash_init(areq);
req_ctx->swinit = 1;
req_ctx->hw_context[0] = SHA224_H0;
req_ctx->hw_context[1] = SHA224_H1;
req_ctx->hw_context[2] = SHA224_H2;
req_ctx->hw_context[3] = SHA224_H3;
req_ctx->hw_context[4] = SHA224_H4;
req_ctx->hw_context[5] = SHA224_H5;
req_ctx->hw_context[6] = SHA224_H6;
req_ctx->hw_context[7] = SHA224_H7;
req_ctx->hw_context[8] = 0;
req_ctx->hw_context[9] = 0;
return 0;
}
static int ahash_process_req(struct ahash_request *areq, unsigned int nbytes)
{
struct crypto_ahash *tfm = crypto_ahash_reqtfm(areq);
struct talitos_ctx *ctx = crypto_ahash_ctx(tfm);
struct talitos_ahash_req_ctx *req_ctx = ahash_request_ctx(areq);
struct talitos_edesc *edesc;
unsigned int blocksize =
crypto_tfm_alg_blocksize(crypto_ahash_tfm(tfm));
unsigned int nbytes_to_hash;
unsigned int to_hash_later;
unsigned int nsg;
int chained;
if (!req_ctx->last && (nbytes + req_ctx->nbuf <= blocksize)) {
sg_copy_to_buffer(areq->src,
sg_count(areq->src, nbytes, &chained),
req_ctx->buf + req_ctx->nbuf, nbytes);
req_ctx->nbuf += nbytes;
return 0;
}
nbytes_to_hash = nbytes + req_ctx->nbuf;
to_hash_later = nbytes_to_hash & (blocksize - 1);
if (req_ctx->last)
to_hash_later = 0;
else if (to_hash_later)
nbytes_to_hash -= to_hash_later;
else {
nbytes_to_hash -= blocksize;
to_hash_later = blocksize;
}
if (req_ctx->nbuf) {
nsg = (req_ctx->nbuf < nbytes_to_hash) ? 2 : 1;
sg_init_table(req_ctx->bufsl, nsg);
sg_set_buf(req_ctx->bufsl, req_ctx->buf, req_ctx->nbuf);
if (nsg > 1)
scatterwalk_sg_chain(req_ctx->bufsl, 2, areq->src);
req_ctx->psrc = req_ctx->bufsl;
} else
req_ctx->psrc = areq->src;
if (to_hash_later) {
int nents = sg_count(areq->src, nbytes, &chained);
sg_copy_end_to_buffer(areq->src, nents,
req_ctx->bufnext,
to_hash_later,
nbytes - to_hash_later);
}
req_ctx->to_hash_later = to_hash_later;
edesc = ahash_edesc_alloc(areq, nbytes_to_hash);
if (IS_ERR(edesc))
return PTR_ERR(edesc);
edesc->desc.hdr = ctx->desc_hdr_template;
if (req_ctx->last)
edesc->desc.hdr |= DESC_HDR_MODE0_MDEU_PAD;
else
edesc->desc.hdr |= DESC_HDR_MODE0_MDEU_CONT;
if (req_ctx->first && !req_ctx->swinit)
edesc->desc.hdr |= DESC_HDR_MODE0_MDEU_INIT;
if (ctx->keylen && (req_ctx->first || req_ctx->last))
edesc->desc.hdr |= DESC_HDR_MODE0_MDEU_HMAC;
return common_nonsnoop_hash(edesc, areq, nbytes_to_hash,
ahash_done);
}
static int ahash_update(struct ahash_request *areq)
{
struct talitos_ahash_req_ctx *req_ctx = ahash_request_ctx(areq);
req_ctx->last = 0;
return ahash_process_req(areq, areq->nbytes);
}
static int ahash_final(struct ahash_request *areq)
{
struct talitos_ahash_req_ctx *req_ctx = ahash_request_ctx(areq);
req_ctx->last = 1;
return ahash_process_req(areq, 0);
}
static int ahash_finup(struct ahash_request *areq)
{
struct talitos_ahash_req_ctx *req_ctx = ahash_request_ctx(areq);
req_ctx->last = 1;
return ahash_process_req(areq, areq->nbytes);
}
static int ahash_digest(struct ahash_request *areq)
{
struct talitos_ahash_req_ctx *req_ctx = ahash_request_ctx(areq);
struct crypto_ahash *ahash = crypto_ahash_reqtfm(areq);
ahash->init(areq);
req_ctx->last = 1;
return ahash_process_req(areq, areq->nbytes);
}
static void keyhash_complete(struct crypto_async_request *req, int err)
{
struct keyhash_result *res = req->data;
if (err == -EINPROGRESS)
return;
res->err = err;
complete(&res->completion);
}
static int keyhash(struct crypto_ahash *tfm, const u8 *key, unsigned int keylen,
u8 *hash)
{
struct talitos_ctx *ctx = crypto_tfm_ctx(crypto_ahash_tfm(tfm));
struct scatterlist sg[1];
struct ahash_request *req;
struct keyhash_result hresult;
int ret;
init_completion(&hresult.completion);
req = ahash_request_alloc(tfm, GFP_KERNEL);
if (!req)
return -ENOMEM;
ctx->keylen = 0;
ahash_request_set_callback(req, CRYPTO_TFM_REQ_MAY_BACKLOG,
keyhash_complete, &hresult);
sg_init_one(&sg[0], key, keylen);
ahash_request_set_crypt(req, sg, hash, keylen);
ret = crypto_ahash_digest(req);
switch (ret) {
case 0:
break;
case -EINPROGRESS:
case -EBUSY:
ret = wait_for_completion_interruptible(
&hresult.completion);
if (!ret)
ret = hresult.err;
break;
default:
break;
}
ahash_request_free(req);
return ret;
}
static int ahash_setkey(struct crypto_ahash *tfm, const u8 *key,
unsigned int keylen)
{
struct talitos_ctx *ctx = crypto_tfm_ctx(crypto_ahash_tfm(tfm));
unsigned int blocksize =
crypto_tfm_alg_blocksize(crypto_ahash_tfm(tfm));
unsigned int digestsize = crypto_ahash_digestsize(tfm);
unsigned int keysize = keylen;
u8 hash[SHA512_DIGEST_SIZE];
int ret;
if (keylen <= blocksize)
memcpy(ctx->key, key, keysize);
else {
ret = keyhash(tfm, key, keylen, hash);
if (ret) {
crypto_ahash_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
keysize = digestsize;
memcpy(ctx->key, hash, digestsize);
}
ctx->keylen = keysize;
return 0;
}
static int talitos_cra_init(struct crypto_tfm *tfm)
{
struct crypto_alg *alg = tfm->__crt_alg;
struct talitos_crypto_alg *talitos_alg;
struct talitos_ctx *ctx = crypto_tfm_ctx(tfm);
struct talitos_private *priv;
if ((alg->cra_flags & CRYPTO_ALG_TYPE_MASK) == CRYPTO_ALG_TYPE_AHASH)
talitos_alg = container_of(__crypto_ahash_alg(alg),
struct talitos_crypto_alg,
algt.alg.hash);
else
talitos_alg = container_of(alg, struct talitos_crypto_alg,
algt.alg.crypto);
ctx->dev = talitos_alg->dev;
priv = dev_get_drvdata(ctx->dev);
ctx->ch = atomic_inc_return(&priv->last_chan) &
(priv->num_channels - 1);
ctx->desc_hdr_template = talitos_alg->algt.desc_hdr_template;
ctx->desc_hdr_template |= DESC_HDR_DONE_NOTIFY;
return 0;
}
static int talitos_cra_init_aead(struct crypto_tfm *tfm)
{
struct talitos_ctx *ctx = crypto_tfm_ctx(tfm);
talitos_cra_init(tfm);
get_random_bytes(ctx->iv, TALITOS_MAX_IV_LENGTH);
return 0;
}
static int talitos_cra_init_ahash(struct crypto_tfm *tfm)
{
struct talitos_ctx *ctx = crypto_tfm_ctx(tfm);
talitos_cra_init(tfm);
ctx->keylen = 0;
crypto_ahash_set_reqsize(__crypto_ahash_cast(tfm),
sizeof(struct talitos_ahash_req_ctx));
return 0;
}
static int hw_supports(struct device *dev, __be32 desc_hdr_template)
{
struct talitos_private *priv = dev_get_drvdata(dev);
int ret;
ret = (1 << DESC_TYPE(desc_hdr_template) & priv->desc_types) &&
(1 << PRIMARY_EU(desc_hdr_template) & priv->exec_units);
if (SECONDARY_EU(desc_hdr_template))
ret = ret && (1 << SECONDARY_EU(desc_hdr_template)
& priv->exec_units);
return ret;
}
static int talitos_remove(struct platform_device *ofdev)
{
struct device *dev = &ofdev->dev;
struct talitos_private *priv = dev_get_drvdata(dev);
struct talitos_crypto_alg *t_alg, *n;
int i;
list_for_each_entry_safe(t_alg, n, &priv->alg_list, entry) {
switch (t_alg->algt.type) {
case CRYPTO_ALG_TYPE_ABLKCIPHER:
case CRYPTO_ALG_TYPE_AEAD:
crypto_unregister_alg(&t_alg->algt.alg.crypto);
break;
case CRYPTO_ALG_TYPE_AHASH:
crypto_unregister_ahash(&t_alg->algt.alg.hash);
break;
}
list_del(&t_alg->entry);
kfree(t_alg);
}
if (hw_supports(dev, DESC_HDR_SEL0_RNG))
talitos_unregister_rng(dev);
for (i = 0; i < priv->num_channels; i++)
kfree(priv->chan[i].fifo);
kfree(priv->chan);
for (i = 0; i < 2; i++)
if (priv->irq[i]) {
free_irq(priv->irq[i], dev);
irq_dispose_mapping(priv->irq[i]);
}
tasklet_kill(&priv->done_task[0]);
if (priv->irq[1])
tasklet_kill(&priv->done_task[1]);
iounmap(priv->reg);
dev_set_drvdata(dev, NULL);
kfree(priv);
return 0;
}
static struct talitos_crypto_alg *talitos_alg_alloc(struct device *dev,
struct talitos_alg_template
*template)
{
struct talitos_private *priv = dev_get_drvdata(dev);
struct talitos_crypto_alg *t_alg;
struct crypto_alg *alg;
t_alg = kzalloc(sizeof(struct talitos_crypto_alg), GFP_KERNEL);
if (!t_alg)
return ERR_PTR(-ENOMEM);
t_alg->algt = *template;
switch (t_alg->algt.type) {
case CRYPTO_ALG_TYPE_ABLKCIPHER:
alg = &t_alg->algt.alg.crypto;
alg->cra_init = talitos_cra_init;
break;
case CRYPTO_ALG_TYPE_AEAD:
alg = &t_alg->algt.alg.crypto;
alg->cra_init = talitos_cra_init_aead;
break;
case CRYPTO_ALG_TYPE_AHASH:
alg = &t_alg->algt.alg.hash.halg.base;
alg->cra_init = talitos_cra_init_ahash;
if (!(priv->features & TALITOS_FTR_HMAC_OK) &&
!strncmp(alg->cra_name, "hmac", 4)) {
kfree(t_alg);
return ERR_PTR(-ENOTSUPP);
}
if (!(priv->features & TALITOS_FTR_SHA224_HWINIT) &&
(!strcmp(alg->cra_name, "sha224") ||
!strcmp(alg->cra_name, "hmac(sha224)"))) {
t_alg->algt.alg.hash.init = ahash_init_sha224_swinit;
t_alg->algt.desc_hdr_template =
DESC_HDR_TYPE_COMMON_NONSNOOP_NO_AFEU |
DESC_HDR_SEL0_MDEUA |
DESC_HDR_MODE0_MDEU_SHA256;
}
break;
default:
dev_err(dev, "unknown algorithm type %d\n", t_alg->algt.type);
return ERR_PTR(-EINVAL);
}
alg->cra_module = THIS_MODULE;
alg->cra_priority = TALITOS_CRA_PRIORITY;
alg->cra_alignmask = 0;
alg->cra_ctxsize = sizeof(struct talitos_ctx);
alg->cra_flags |= CRYPTO_ALG_KERN_DRIVER_ONLY;
t_alg->dev = dev;
return t_alg;
}
static int talitos_probe_irq(struct platform_device *ofdev)
{
struct device *dev = &ofdev->dev;
struct device_node *np = ofdev->dev.of_node;
struct talitos_private *priv = dev_get_drvdata(dev);
int err;
priv->irq[0] = irq_of_parse_and_map(np, 0);
if (!priv->irq[0]) {
dev_err(dev, "failed to map irq\n");
return -EINVAL;
}
priv->irq[1] = irq_of_parse_and_map(np, 1);
if (!priv->irq[1]) {
err = request_irq(priv->irq[0], talitos_interrupt_4ch, 0,
dev_driver_string(dev), dev);
goto primary_out;
}
err = request_irq(priv->irq[0], talitos_interrupt_ch0_2, 0,
dev_driver_string(dev), dev);
if (err)
goto primary_out;
err = request_irq(priv->irq[1], talitos_interrupt_ch1_3, 0,
dev_driver_string(dev), dev);
if (err) {
dev_err(dev, "failed to request secondary irq\n");
irq_dispose_mapping(priv->irq[1]);
priv->irq[1] = 0;
}
return err;
primary_out:
if (err) {
dev_err(dev, "failed to request primary irq\n");
irq_dispose_mapping(priv->irq[0]);
priv->irq[0] = 0;
}
return err;
}
static int talitos_probe(struct platform_device *ofdev)
{
struct device *dev = &ofdev->dev;
struct device_node *np = ofdev->dev.of_node;
struct talitos_private *priv;
const unsigned int *prop;
int i, err;
priv = kzalloc(sizeof(struct talitos_private), GFP_KERNEL);
if (!priv)
return -ENOMEM;
dev_set_drvdata(dev, priv);
priv->ofdev = ofdev;
spin_lock_init(&priv->reg_lock);
err = talitos_probe_irq(ofdev);
if (err)
goto err_out;
if (!priv->irq[1]) {
tasklet_init(&priv->done_task[0], talitos_done_4ch,
(unsigned long)dev);
} else {
tasklet_init(&priv->done_task[0], talitos_done_ch0_2,
(unsigned long)dev);
tasklet_init(&priv->done_task[1], talitos_done_ch1_3,
(unsigned long)dev);
}
INIT_LIST_HEAD(&priv->alg_list);
priv->reg = of_iomap(np, 0);
if (!priv->reg) {
dev_err(dev, "failed to of_iomap\n");
err = -ENOMEM;
goto err_out;
}
prop = of_get_property(np, "fsl,num-channels", NULL);
if (prop)
priv->num_channels = *prop;
prop = of_get_property(np, "fsl,channel-fifo-len", NULL);
if (prop)
priv->chfifo_len = *prop;
prop = of_get_property(np, "fsl,exec-units-mask", NULL);
if (prop)
priv->exec_units = *prop;
prop = of_get_property(np, "fsl,descriptor-types-mask", NULL);
if (prop)
priv->desc_types = *prop;
if (!is_power_of_2(priv->num_channels) || !priv->chfifo_len ||
!priv->exec_units || !priv->desc_types) {
dev_err(dev, "invalid property data in device tree node\n");
err = -EINVAL;
goto err_out;
}
if (of_device_is_compatible(np, "fsl,sec3.0"))
priv->features |= TALITOS_FTR_SRC_LINK_TBL_LEN_INCLUDES_EXTENT;
if (of_device_is_compatible(np, "fsl,sec2.1"))
priv->features |= TALITOS_FTR_HW_AUTH_CHECK |
TALITOS_FTR_SHA224_HWINIT |
TALITOS_FTR_HMAC_OK;
priv->chan = kzalloc(sizeof(struct talitos_channel) *
priv->num_channels, GFP_KERNEL);
if (!priv->chan) {
dev_err(dev, "failed to allocate channel management space\n");
err = -ENOMEM;
goto err_out;
}
for (i = 0; i < priv->num_channels; i++) {
priv->chan[i].reg = priv->reg + TALITOS_CH_STRIDE * (i + 1);
if (!priv->irq[1] || !(i & 1))
priv->chan[i].reg += TALITOS_CH_BASE_OFFSET;
}
for (i = 0; i < priv->num_channels; i++) {
spin_lock_init(&priv->chan[i].head_lock);
spin_lock_init(&priv->chan[i].tail_lock);
}
priv->fifo_len = roundup_pow_of_two(priv->chfifo_len);
for (i = 0; i < priv->num_channels; i++) {
priv->chan[i].fifo = kzalloc(sizeof(struct talitos_request) *
priv->fifo_len, GFP_KERNEL);
if (!priv->chan[i].fifo) {
dev_err(dev, "failed to allocate request fifo %d\n", i);
err = -ENOMEM;
goto err_out;
}
}
for (i = 0; i < priv->num_channels; i++)
atomic_set(&priv->chan[i].submit_count,
-(priv->chfifo_len - 1));
dma_set_mask(dev, DMA_BIT_MASK(36));
err = init_device(dev);
if (err) {
dev_err(dev, "failed to initialize device\n");
goto err_out;
}
if (hw_supports(dev, DESC_HDR_SEL0_RNG)) {
err = talitos_register_rng(dev);
if (err) {
dev_err(dev, "failed to register hwrng: %d\n", err);
goto err_out;
} else
dev_info(dev, "hwrng\n");
}
for (i = 0; i < ARRAY_SIZE(driver_algs); i++) {
if (hw_supports(dev, driver_algs[i].desc_hdr_template)) {
struct talitos_crypto_alg *t_alg;
char *name = NULL;
t_alg = talitos_alg_alloc(dev, &driver_algs[i]);
if (IS_ERR(t_alg)) {
err = PTR_ERR(t_alg);
if (err == -ENOTSUPP)
continue;
goto err_out;
}
switch (t_alg->algt.type) {
case CRYPTO_ALG_TYPE_ABLKCIPHER:
case CRYPTO_ALG_TYPE_AEAD:
err = crypto_register_alg(
&t_alg->algt.alg.crypto);
name = t_alg->algt.alg.crypto.cra_driver_name;
break;
case CRYPTO_ALG_TYPE_AHASH:
err = crypto_register_ahash(
&t_alg->algt.alg.hash);
name =
t_alg->algt.alg.hash.halg.base.cra_driver_name;
break;
}
if (err) {
dev_err(dev, "%s alg registration failed\n",
name);
kfree(t_alg);
} else
list_add_tail(&t_alg->entry, &priv->alg_list);
}
}
if (!list_empty(&priv->alg_list))
dev_info(dev, "%s algorithms registered in /proc/crypto\n",
(char *)of_get_property(np, "compatible", NULL));
return 0;
err_out:
talitos_remove(ofdev);
return err;
}
