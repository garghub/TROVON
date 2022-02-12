static void to_talitos_ptr(struct talitos_ptr *ptr, dma_addr_t dma_addr,
bool is_sec1)
{
ptr->ptr = cpu_to_be32(lower_32_bits(dma_addr));
if (!is_sec1)
ptr->eptr = upper_32_bits(dma_addr);
}
static void to_talitos_ptr_len(struct talitos_ptr *ptr, unsigned int len,
bool is_sec1)
{
if (is_sec1) {
ptr->res = 0;
ptr->len1 = cpu_to_be16(len);
} else {
ptr->len = cpu_to_be16(len);
}
}
static unsigned short from_talitos_ptr_len(struct talitos_ptr *ptr,
bool is_sec1)
{
if (is_sec1)
return be16_to_cpu(ptr->len1);
else
return be16_to_cpu(ptr->len);
}
static void to_talitos_ptr_extent_clear(struct talitos_ptr *ptr, bool is_sec1)
{
if (!is_sec1)
ptr->j_extent = 0;
}
static void map_single_talitos_ptr(struct device *dev,
struct talitos_ptr *ptr,
unsigned int len, void *data,
enum dma_data_direction dir)
{
dma_addr_t dma_addr = dma_map_single(dev, data, len, dir);
struct talitos_private *priv = dev_get_drvdata(dev);
bool is_sec1 = has_ftr_sec1(priv);
to_talitos_ptr_len(ptr, len, is_sec1);
to_talitos_ptr(ptr, dma_addr, is_sec1);
to_talitos_ptr_extent_clear(ptr, is_sec1);
}
static void unmap_single_talitos_ptr(struct device *dev,
struct talitos_ptr *ptr,
enum dma_data_direction dir)
{
struct talitos_private *priv = dev_get_drvdata(dev);
bool is_sec1 = has_ftr_sec1(priv);
dma_unmap_single(dev, be32_to_cpu(ptr->ptr),
from_talitos_ptr_len(ptr, is_sec1), dir);
}
static int reset_channel(struct device *dev, int ch)
{
struct talitos_private *priv = dev_get_drvdata(dev);
unsigned int timeout = TALITOS_TIMEOUT;
bool is_sec1 = has_ftr_sec1(priv);
if (is_sec1) {
setbits32(priv->chan[ch].reg + TALITOS_CCCR_LO,
TALITOS1_CCCR_LO_RESET);
while ((in_be32(priv->chan[ch].reg + TALITOS_CCCR_LO) &
TALITOS1_CCCR_LO_RESET) && --timeout)
cpu_relax();
} else {
setbits32(priv->chan[ch].reg + TALITOS_CCCR,
TALITOS2_CCCR_RESET);
while ((in_be32(priv->chan[ch].reg + TALITOS_CCCR) &
TALITOS2_CCCR_RESET) && --timeout)
cpu_relax();
}
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
bool is_sec1 = has_ftr_sec1(priv);
u32 mcr = is_sec1 ? TALITOS1_MCR_SWR : TALITOS2_MCR_SWR;
setbits32(priv->reg + TALITOS_MCR, mcr);
while ((in_be32(priv->reg + TALITOS_MCR) & mcr)
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
bool is_sec1 = has_ftr_sec1(priv);
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
if (is_sec1) {
clrbits32(priv->reg + TALITOS_IMR, TALITOS1_IMR_INIT);
clrbits32(priv->reg + TALITOS_IMR_LO, TALITOS1_IMR_LO_INIT);
setbits32(priv->reg_deu + TALITOS_EUICR, TALITOS1_DEUICR_KPE);
} else {
setbits32(priv->reg + TALITOS_IMR, TALITOS2_IMR_INIT);
setbits32(priv->reg + TALITOS_IMR_LO, TALITOS2_IMR_LO_INIT);
}
if (priv->features & TALITOS_FTR_HW_AUTH_CHECK)
setbits32(priv->reg_mdeu + TALITOS_EUICR_LO,
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
bool is_sec1 = has_ftr_sec1(priv);
spin_lock_irqsave(&priv->chan[ch].head_lock, flags);
if (!atomic_inc_not_zero(&priv->chan[ch].submit_count)) {
spin_unlock_irqrestore(&priv->chan[ch].head_lock, flags);
return -EAGAIN;
}
head = priv->chan[ch].head;
request = &priv->chan[ch].fifo[head];
if (is_sec1) {
desc->hdr1 = desc->hdr;
desc->next_desc = 0;
request->dma_desc = dma_map_single(dev, &desc->hdr1,
TALITOS_DESC_SIZE,
DMA_BIDIRECTIONAL);
} else {
request->dma_desc = dma_map_single(dev, desc,
TALITOS_DESC_SIZE,
DMA_BIDIRECTIONAL);
}
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
bool is_sec1 = has_ftr_sec1(priv);
spin_lock_irqsave(&priv->chan[ch].tail_lock, flags);
tail = priv->chan[ch].tail;
while (priv->chan[ch].fifo[tail].desc) {
__be32 hdr;
request = &priv->chan[ch].fifo[tail];
rmb();
hdr = is_sec1 ? request->desc->hdr1 : request->desc->hdr;
if ((hdr & DESC_HDR_DONE) == DESC_HDR_DONE)
status = 0;
else
if (!error)
break;
else
status = error;
dma_unmap_single(dev, request->dma_desc,
TALITOS_DESC_SIZE,
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
int tail, iter;
dma_addr_t cur_desc;
cur_desc = ((u64)in_be32(priv->chan[ch].reg + TALITOS_CDPR)) << 32;
cur_desc |= in_be32(priv->chan[ch].reg + TALITOS_CDPR_LO);
if (!cur_desc) {
dev_err(dev, "CDPR is NULL, giving up search for offending descriptor\n");
return 0;
}
tail = priv->chan[ch].tail;
iter = tail;
while (priv->chan[ch].fifo[iter].dma_desc != cur_desc) {
iter = (iter + 1) & (priv->fifo_len - 1);
if (iter == tail) {
dev_err(dev, "couldn't locate current descriptor\n");
return 0;
}
}
return priv->chan[ch].fifo[iter].desc->hdr;
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
in_be32(priv->reg_afeu + TALITOS_EUISR),
in_be32(priv->reg_afeu + TALITOS_EUISR_LO));
break;
case DESC_HDR_SEL0_DEU:
dev_err(dev, "DEUISR 0x%08x_%08x\n",
in_be32(priv->reg_deu + TALITOS_EUISR),
in_be32(priv->reg_deu + TALITOS_EUISR_LO));
break;
case DESC_HDR_SEL0_MDEUA:
case DESC_HDR_SEL0_MDEUB:
dev_err(dev, "MDEUISR 0x%08x_%08x\n",
in_be32(priv->reg_mdeu + TALITOS_EUISR),
in_be32(priv->reg_mdeu + TALITOS_EUISR_LO));
break;
case DESC_HDR_SEL0_RNG:
dev_err(dev, "RNGUISR 0x%08x_%08x\n",
in_be32(priv->reg_rngu + TALITOS_ISR),
in_be32(priv->reg_rngu + TALITOS_ISR_LO));
break;
case DESC_HDR_SEL0_PKEU:
dev_err(dev, "PKEUISR 0x%08x_%08x\n",
in_be32(priv->reg_pkeu + TALITOS_EUISR),
in_be32(priv->reg_pkeu + TALITOS_EUISR_LO));
break;
case DESC_HDR_SEL0_AESU:
dev_err(dev, "AESUISR 0x%08x_%08x\n",
in_be32(priv->reg_aesu + TALITOS_EUISR),
in_be32(priv->reg_aesu + TALITOS_EUISR_LO));
break;
case DESC_HDR_SEL0_CRCU:
dev_err(dev, "CRCUISR 0x%08x_%08x\n",
in_be32(priv->reg_crcu + TALITOS_EUISR),
in_be32(priv->reg_crcu + TALITOS_EUISR_LO));
break;
case DESC_HDR_SEL0_KEU:
dev_err(dev, "KEUISR 0x%08x_%08x\n",
in_be32(priv->reg_pkeu + TALITOS_EUISR),
in_be32(priv->reg_pkeu + TALITOS_EUISR_LO));
break;
}
switch (desc_hdr & DESC_HDR_SEL1_MASK) {
case DESC_HDR_SEL1_MDEUA:
case DESC_HDR_SEL1_MDEUB:
dev_err(dev, "MDEUISR 0x%08x_%08x\n",
in_be32(priv->reg_mdeu + TALITOS_EUISR),
in_be32(priv->reg_mdeu + TALITOS_EUISR_LO));
break;
case DESC_HDR_SEL1_CRCU:
dev_err(dev, "CRCUISR 0x%08x_%08x\n",
in_be32(priv->reg_crcu + TALITOS_EUISR),
in_be32(priv->reg_crcu + TALITOS_EUISR_LO));
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
int ch, error, reset_dev = 0;
u32 v_lo;
bool is_sec1 = has_ftr_sec1(priv);
int reset_ch = is_sec1 ? 1 : 0;
for (ch = 0; ch < priv->num_channels; ch++) {
if (is_sec1) {
if (!(isr & (1 << (29 + (ch & 1) * 2 - (ch & 2) * 6))))
continue;
} else {
if (!(isr & (1 << (ch * 2 + 1))))
continue;
}
error = -EINVAL;
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
dev_err(dev, is_sec1 ? "pointeur not complete error\n"
: "s/g data length zero error\n");
if (v_lo & TALITOS_CCPSR_LO_FPZ)
dev_err(dev, is_sec1 ? "parity error\n"
: "fetch pointer zero error\n");
if (v_lo & TALITOS_CCPSR_LO_IDH)
dev_err(dev, "illegal descriptor header error\n");
if (v_lo & TALITOS_CCPSR_LO_IEU)
dev_err(dev, is_sec1 ? "static assignment error\n"
: "invalid exec unit error\n");
if (v_lo & TALITOS_CCPSR_LO_EU)
report_eu_error(dev, ch, current_desc_hdr(dev, ch));
if (!is_sec1) {
if (v_lo & TALITOS_CCPSR_LO_GB)
dev_err(dev, "gather boundary error\n");
if (v_lo & TALITOS_CCPSR_LO_GRL)
dev_err(dev, "gather return/length error\n");
if (v_lo & TALITOS_CCPSR_LO_SB)
dev_err(dev, "scatter boundary error\n");
if (v_lo & TALITOS_CCPSR_LO_SRL)
dev_err(dev, "scatter return/length error\n");
}
flush_channel(dev, ch, error, reset_ch);
if (reset_ch) {
reset_channel(dev, ch);
} else {
setbits32(priv->chan[ch].reg + TALITOS_CCCR,
TALITOS2_CCCR_CONT);
setbits32(priv->chan[ch].reg + TALITOS_CCCR_LO, 0);
while ((in_be32(priv->chan[ch].reg + TALITOS_CCCR) &
TALITOS2_CCCR_CONT) && --timeout)
cpu_relax();
if (timeout == 0) {
dev_err(dev, "failed to restart channel %d\n",
ch);
reset_dev = 1;
}
}
}
if (reset_dev || (is_sec1 && isr & ~TALITOS1_ISR_4CHERR) ||
(!is_sec1 && isr & ~TALITOS2_ISR_4CHERR) || isr_lo) {
if (is_sec1 && (isr_lo & TALITOS1_ISR_TEA_ERR))
dev_err(dev, "TEA error: ISR 0x%08x_%08x\n",
isr, isr_lo);
else
dev_err(dev, "done overflow, internal time out, or "
"rngu error: ISR 0x%08x_%08x\n", isr, isr_lo);
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
ofl = in_be32(priv->reg_rngu + TALITOS_EUSR_LO) &
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
*data = in_be32(priv->reg_rngu + TALITOS_EU_FIFO);
*data = in_be32(priv->reg_rngu + TALITOS_EU_FIFO_LO);
return sizeof(u32);
}
static int talitos_rng_init(struct hwrng *rng)
{
struct device *dev = (struct device *)rng->priv;
struct talitos_private *priv = dev_get_drvdata(dev);
unsigned int timeout = TALITOS_TIMEOUT;
setbits32(priv->reg_rngu + TALITOS_EURCR_LO, TALITOS_RNGURCR_LO_SR);
while (!(in_be32(priv->reg_rngu + TALITOS_EUSR_LO)
& TALITOS_RNGUSR_LO_RD)
&& --timeout)
cpu_relax();
if (timeout == 0) {
dev_err(dev, "failed to reset rng hw\n");
return -ENODEV;
}
setbits32(priv->reg_rngu + TALITOS_EUDSR_LO, 0);
return 0;
}
static int talitos_register_rng(struct device *dev)
{
struct talitos_private *priv = dev_get_drvdata(dev);
int err;
priv->rng.name = dev_driver_string(dev),
priv->rng.init = talitos_rng_init,
priv->rng.data_present = talitos_rng_data_present,
priv->rng.data_read = talitos_rng_data_read,
priv->rng.priv = (unsigned long)dev;
err = hwrng_register(&priv->rng);
if (!err)
priv->rng_registered = true;
return err;
}
static void talitos_unregister_rng(struct device *dev)
{
struct talitos_private *priv = dev_get_drvdata(dev);
if (!priv->rng_registered)
return;
hwrng_unregister(&priv->rng);
priv->rng_registered = false;
}
static int aead_setkey(struct crypto_aead *authenc,
const u8 *key, unsigned int keylen)
{
struct talitos_ctx *ctx = crypto_aead_ctx(authenc);
struct crypto_authenc_keys keys;
if (crypto_authenc_extractkeys(&keys, key, keylen) != 0)
goto badkey;
if (keys.authkeylen + keys.enckeylen > TALITOS_MAX_KEY_SIZE)
goto badkey;
memcpy(ctx->key, keys.authkey, keys.authkeylen);
memcpy(&ctx->key[keys.authkeylen], keys.enckey, keys.enckeylen);
ctx->keylen = keys.authkeylen + keys.enckeylen;
ctx->enckeylen = keys.enckeylen;
ctx->authkeylen = keys.authkeylen;
return 0;
badkey:
crypto_aead_set_flags(authenc, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
static int talitos_map_sg(struct device *dev, struct scatterlist *sg,
unsigned int nents, enum dma_data_direction dir,
bool chained)
{
if (unlikely(chained))
while (sg) {
dma_map_sg(dev, sg, 1, dir);
sg = sg_next(sg);
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
sg = sg_next(sg);
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
if (edesc->src_chained)
talitos_unmap_sg_chain(dev, src, DMA_TO_DEVICE);
else
dma_unmap_sg(dev, src, src_nents, DMA_TO_DEVICE);
if (dst) {
if (edesc->dst_chained)
talitos_unmap_sg_chain(dev, dst,
DMA_FROM_DEVICE);
else
dma_unmap_sg(dev, dst, dst_nents,
DMA_FROM_DEVICE);
}
} else
if (edesc->src_chained)
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
unsigned int authsize = crypto_aead_authsize(authenc);
struct talitos_edesc *edesc;
struct scatterlist *sg;
void *icvdata;
edesc = container_of(desc, struct talitos_edesc, desc);
ipsec_esp_unmap(dev, edesc, areq);
if (edesc->icv_ool) {
icvdata = &edesc->link_tbl[edesc->src_nents +
edesc->dst_nents + 2];
sg = sg_last(areq->dst, edesc->dst_nents);
memcpy((char *)sg_virt(sg) + sg->length - authsize,
icvdata, authsize);
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
unsigned int authsize = crypto_aead_authsize(authenc);
struct talitos_edesc *edesc;
struct scatterlist *sg;
char *oicv, *icv;
edesc = container_of(desc, struct talitos_edesc, desc);
ipsec_esp_unmap(dev, edesc, req);
if (!err) {
sg = sg_last(req->dst, edesc->dst_nents ? : 1);
icv = (char *)sg_virt(sg) + sg->length - authsize;
if (edesc->dma_len) {
oicv = (char *)&edesc->link_tbl[edesc->src_nents +
edesc->dst_nents + 2];
if (edesc->icv_ool)
icv = oicv + authsize;
} else
oicv = (char *)&edesc->link_tbl[0];
err = memcmp(oicv, icv, authsize) ? -EBADMSG : 0;
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
static int sg_to_link_tbl_offset(struct scatterlist *sg, int sg_count,
unsigned int offset, int cryptlen,
struct talitos_ptr *link_tbl_ptr)
{
int n_sg = sg_count;
int count = 0;
while (cryptlen && sg && n_sg--) {
unsigned int len = sg_dma_len(sg);
if (offset >= len) {
offset -= len;
goto next;
}
len -= offset;
if (len > cryptlen)
len = cryptlen;
to_talitos_ptr(link_tbl_ptr + count,
sg_dma_address(sg) + offset, 0);
link_tbl_ptr[count].len = cpu_to_be16(len);
link_tbl_ptr[count].j_extent = 0;
count++;
cryptlen -= len;
offset = 0;
next:
sg = sg_next(sg);
}
if (count > 0)
link_tbl_ptr[count - 1].j_extent = DESC_PTR_LNKTBL_RETURN;
return count;
}
static inline int sg_to_link_tbl(struct scatterlist *sg, int sg_count,
int cryptlen,
struct talitos_ptr *link_tbl_ptr)
{
return sg_to_link_tbl_offset(sg, sg_count, 0, cryptlen,
link_tbl_ptr);
}
static int ipsec_esp(struct talitos_edesc *edesc, struct aead_request *areq,
void (*callback)(struct device *dev,
struct talitos_desc *desc,
void *context, int error))
{
struct crypto_aead *aead = crypto_aead_reqtfm(areq);
unsigned int authsize = crypto_aead_authsize(aead);
struct talitos_ctx *ctx = crypto_aead_ctx(aead);
struct device *dev = ctx->dev;
struct talitos_desc *desc = &edesc->desc;
unsigned int cryptlen = areq->cryptlen;
unsigned int ivsize = crypto_aead_ivsize(aead);
int tbl_off = 0;
int sg_count, ret;
int sg_link_tbl_len;
map_single_talitos_ptr(dev, &desc->ptr[0], ctx->authkeylen, &ctx->key,
DMA_TO_DEVICE);
sg_count = talitos_map_sg(dev, areq->src, edesc->src_nents ?: 1,
(areq->src == areq->dst) ? DMA_BIDIRECTIONAL
: DMA_TO_DEVICE,
edesc->src_chained);
desc->ptr[1].len = cpu_to_be16(areq->assoclen);
if (sg_count > 1 &&
(ret = sg_to_link_tbl_offset(areq->src, sg_count, 0,
areq->assoclen,
&edesc->link_tbl[tbl_off])) > 1) {
tbl_off += ret;
to_talitos_ptr(&desc->ptr[1], edesc->dma_link_tbl + tbl_off *
sizeof(struct talitos_ptr), 0);
desc->ptr[1].j_extent = DESC_PTR_LNKTBL_JUMP;
dma_sync_single_for_device(dev, edesc->dma_link_tbl,
edesc->dma_len, DMA_BIDIRECTIONAL);
} else {
to_talitos_ptr(&desc->ptr[1], sg_dma_address(areq->src), 0);
desc->ptr[1].j_extent = 0;
}
to_talitos_ptr(&desc->ptr[2], edesc->iv_dma, 0);
desc->ptr[2].len = cpu_to_be16(ivsize);
desc->ptr[2].j_extent = 0;
map_single_talitos_ptr(dev, &desc->ptr[3], ctx->enckeylen,
(char *)&ctx->key + ctx->authkeylen,
DMA_TO_DEVICE);
desc->ptr[4].len = cpu_to_be16(cryptlen);
desc->ptr[4].j_extent = authsize;
sg_link_tbl_len = cryptlen;
if (edesc->desc.hdr & DESC_HDR_MODE1_MDEU_CICV)
sg_link_tbl_len += authsize;
if (sg_count > 1 &&
(ret = sg_to_link_tbl_offset(areq->src, sg_count, areq->assoclen,
sg_link_tbl_len,
&edesc->link_tbl[tbl_off])) > 1) {
tbl_off += ret;
desc->ptr[4].j_extent |= DESC_PTR_LNKTBL_JUMP;
to_talitos_ptr(&desc->ptr[4], edesc->dma_link_tbl +
tbl_off *
sizeof(struct talitos_ptr), 0);
dma_sync_single_for_device(dev, edesc->dma_link_tbl,
edesc->dma_len,
DMA_BIDIRECTIONAL);
} else
to_talitos_ptr(&desc->ptr[4], sg_dma_address(areq->src), 0);
desc->ptr[5].len = cpu_to_be16(cryptlen);
desc->ptr[5].j_extent = authsize;
if (areq->src != areq->dst)
sg_count = talitos_map_sg(dev, areq->dst,
edesc->dst_nents ? : 1,
DMA_FROM_DEVICE, edesc->dst_chained);
edesc->icv_ool = false;
if (sg_count > 1 &&
(sg_count = sg_to_link_tbl_offset(areq->dst, sg_count,
areq->assoclen, cryptlen,
&edesc->link_tbl[tbl_off])) >
1) {
struct talitos_ptr *tbl_ptr = &edesc->link_tbl[tbl_off];
to_talitos_ptr(&desc->ptr[5], edesc->dma_link_tbl +
tbl_off * sizeof(struct talitos_ptr), 0);
tbl_ptr += sg_count - 1;
tbl_ptr->j_extent = 0;
tbl_ptr++;
tbl_ptr->j_extent = DESC_PTR_LNKTBL_RETURN;
tbl_ptr->len = cpu_to_be16(authsize);
to_talitos_ptr(tbl_ptr, edesc->dma_link_tbl +
(edesc->src_nents + edesc->dst_nents +
2) * sizeof(struct talitos_ptr) +
authsize, 0);
desc->ptr[5].j_extent |= DESC_PTR_LNKTBL_JUMP;
dma_sync_single_for_device(ctx->dev, edesc->dma_link_tbl,
edesc->dma_len, DMA_BIDIRECTIONAL);
edesc->icv_ool = true;
} else
to_talitos_ptr(&desc->ptr[5], sg_dma_address(areq->dst), 0);
map_single_talitos_ptr(dev, &desc->ptr[6], ivsize, ctx->iv,
DMA_FROM_DEVICE);
ret = talitos_submit(dev, ctx->ch, desc, callback, areq);
if (ret != -EINPROGRESS) {
ipsec_esp_unmap(dev, edesc, areq);
kfree(edesc);
}
return ret;
}
static int sg_count(struct scatterlist *sg_list, int nbytes, bool *chained)
{
struct scatterlist *sg = sg_list;
int sg_nents = 0;
*chained = false;
while (nbytes > 0 && sg) {
sg_nents++;
nbytes -= sg->length;
if (!sg_is_last(sg) && (sg + 1)->length == 0)
*chained = true;
sg = sg_next(sg);
}
return sg_nents;
}
static struct talitos_edesc *talitos_edesc_alloc(struct device *dev,
struct scatterlist *src,
struct scatterlist *dst,
u8 *iv,
unsigned int assoclen,
unsigned int cryptlen,
unsigned int authsize,
unsigned int ivsize,
int icv_stashing,
u32 cryptoflags,
bool encrypt)
{
struct talitos_edesc *edesc;
int src_nents, dst_nents, alloc_len, dma_len;
bool src_chained = false, dst_chained = false;
dma_addr_t iv_dma = 0;
gfp_t flags = cryptoflags & CRYPTO_TFM_REQ_MAY_SLEEP ? GFP_KERNEL :
GFP_ATOMIC;
struct talitos_private *priv = dev_get_drvdata(dev);
bool is_sec1 = has_ftr_sec1(priv);
int max_len = is_sec1 ? TALITOS1_MAX_DATA_LEN : TALITOS2_MAX_DATA_LEN;
if (cryptlen + authsize > max_len) {
dev_err(dev, "length exceeds h/w max limit\n");
return ERR_PTR(-EINVAL);
}
if (ivsize)
iv_dma = dma_map_single(dev, iv, ivsize, DMA_TO_DEVICE);
if (!dst || dst == src) {
src_nents = sg_count(src, assoclen + cryptlen + authsize,
&src_chained);
src_nents = (src_nents == 1) ? 0 : src_nents;
dst_nents = dst ? src_nents : 0;
} else {
src_nents = sg_count(src, assoclen + cryptlen +
(encrypt ? 0 : authsize),
&src_chained);
src_nents = (src_nents == 1) ? 0 : src_nents;
dst_nents = sg_count(dst, assoclen + cryptlen +
(encrypt ? authsize : 0),
&dst_chained);
dst_nents = (dst_nents == 1) ? 0 : dst_nents;
}
alloc_len = sizeof(struct talitos_edesc);
if (src_nents || dst_nents) {
if (is_sec1)
dma_len = (src_nents ? cryptlen : 0) +
(dst_nents ? cryptlen : 0);
else
dma_len = (src_nents + dst_nents + 2) *
sizeof(struct talitos_ptr) + authsize * 2;
alloc_len += dma_len;
} else {
dma_len = 0;
alloc_len += icv_stashing ? authsize : 0;
}
edesc = kmalloc(alloc_len, GFP_DMA | flags);
if (!edesc) {
if (iv_dma)
dma_unmap_single(dev, iv_dma, ivsize, DMA_TO_DEVICE);
dev_err(dev, "could not allocate edescriptor\n");
return ERR_PTR(-ENOMEM);
}
edesc->src_nents = src_nents;
edesc->dst_nents = dst_nents;
edesc->src_chained = src_chained;
edesc->dst_chained = dst_chained;
edesc->iv_dma = iv_dma;
edesc->dma_len = dma_len;
if (dma_len)
edesc->dma_link_tbl = dma_map_single(dev, &edesc->link_tbl[0],
edesc->dma_len,
DMA_BIDIRECTIONAL);
return edesc;
}
static struct talitos_edesc *aead_edesc_alloc(struct aead_request *areq, u8 *iv,
int icv_stashing, bool encrypt)
{
struct crypto_aead *authenc = crypto_aead_reqtfm(areq);
unsigned int authsize = crypto_aead_authsize(authenc);
struct talitos_ctx *ctx = crypto_aead_ctx(authenc);
unsigned int ivsize = crypto_aead_ivsize(authenc);
return talitos_edesc_alloc(ctx->dev, areq->src, areq->dst,
iv, areq->assoclen, areq->cryptlen,
authsize, ivsize, icv_stashing,
areq->base.flags, encrypt);
}
static int aead_encrypt(struct aead_request *req)
{
struct crypto_aead *authenc = crypto_aead_reqtfm(req);
struct talitos_ctx *ctx = crypto_aead_ctx(authenc);
struct talitos_edesc *edesc;
edesc = aead_edesc_alloc(req, req->iv, 0, true);
if (IS_ERR(edesc))
return PTR_ERR(edesc);
edesc->desc.hdr = ctx->desc_hdr_template | DESC_HDR_MODE0_ENCRYPT;
return ipsec_esp(edesc, req, ipsec_esp_encrypt_done);
}
static int aead_decrypt(struct aead_request *req)
{
struct crypto_aead *authenc = crypto_aead_reqtfm(req);
unsigned int authsize = crypto_aead_authsize(authenc);
struct talitos_ctx *ctx = crypto_aead_ctx(authenc);
struct talitos_private *priv = dev_get_drvdata(ctx->dev);
struct talitos_edesc *edesc;
struct scatterlist *sg;
void *icvdata;
req->cryptlen -= authsize;
edesc = aead_edesc_alloc(req, req->iv, 1, false);
if (IS_ERR(edesc))
return PTR_ERR(edesc);
if ((priv->features & TALITOS_FTR_HW_AUTH_CHECK) &&
((!edesc->src_nents && !edesc->dst_nents) ||
priv->features & TALITOS_FTR_SRC_LINK_TBL_LEN_INCLUDES_EXTENT)) {
edesc->desc.hdr = ctx->desc_hdr_template |
DESC_HDR_DIR_INBOUND |
DESC_HDR_MODE1_MDEU_CICV;
edesc->desc.hdr_lo = 0;
return ipsec_esp(edesc, req, ipsec_esp_decrypt_hwauth_done);
}
edesc->desc.hdr = ctx->desc_hdr_template | DESC_HDR_DIR_INBOUND;
if (edesc->dma_len)
icvdata = (char *)&edesc->link_tbl[edesc->src_nents +
edesc->dst_nents + 2];
else
icvdata = &edesc->link_tbl[0];
sg = sg_last(req->src, edesc->src_nents ? : 1);
memcpy(icvdata, (char *)sg_virt(sg) + sg->length - authsize, authsize);
return ipsec_esp(edesc, req, ipsec_esp_decrypt_swauth_done);
}
static int ablkcipher_setkey(struct crypto_ablkcipher *cipher,
const u8 *key, unsigned int keylen)
{
struct talitos_ctx *ctx = crypto_ablkcipher_ctx(cipher);
memcpy(&ctx->key, key, keylen);
ctx->keylen = keylen;
return 0;
}
static void unmap_sg_talitos_ptr(struct device *dev, struct scatterlist *src,
struct scatterlist *dst, unsigned int len,
struct talitos_edesc *edesc)
{
struct talitos_private *priv = dev_get_drvdata(dev);
bool is_sec1 = has_ftr_sec1(priv);
if (is_sec1) {
if (!edesc->src_nents) {
dma_unmap_sg(dev, src, 1,
dst != src ? DMA_TO_DEVICE
: DMA_BIDIRECTIONAL);
}
if (dst && edesc->dst_nents) {
dma_sync_single_for_device(dev,
edesc->dma_link_tbl + len,
len, DMA_FROM_DEVICE);
sg_copy_from_buffer(dst, edesc->dst_nents ? : 1,
edesc->buf + len, len);
} else if (dst && dst != src) {
dma_unmap_sg(dev, dst, 1, DMA_FROM_DEVICE);
}
} else {
talitos_sg_unmap(dev, edesc, src, dst);
}
}
static void common_nonsnoop_unmap(struct device *dev,
struct talitos_edesc *edesc,
struct ablkcipher_request *areq)
{
unmap_single_talitos_ptr(dev, &edesc->desc.ptr[5], DMA_FROM_DEVICE);
unmap_sg_talitos_ptr(dev, areq->src, areq->dst, areq->nbytes, edesc);
unmap_single_talitos_ptr(dev, &edesc->desc.ptr[2], DMA_TO_DEVICE);
unmap_single_talitos_ptr(dev, &edesc->desc.ptr[1], DMA_TO_DEVICE);
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
int map_sg_in_talitos_ptr(struct device *dev, struct scatterlist *src,
unsigned int len, struct talitos_edesc *edesc,
enum dma_data_direction dir, struct talitos_ptr *ptr)
{
int sg_count;
struct talitos_private *priv = dev_get_drvdata(dev);
bool is_sec1 = has_ftr_sec1(priv);
to_talitos_ptr_len(ptr, len, is_sec1);
if (is_sec1) {
sg_count = edesc->src_nents ? : 1;
if (sg_count == 1) {
dma_map_sg(dev, src, 1, dir);
to_talitos_ptr(ptr, sg_dma_address(src), is_sec1);
} else {
sg_copy_to_buffer(src, sg_count, edesc->buf, len);
to_talitos_ptr(ptr, edesc->dma_link_tbl, is_sec1);
dma_sync_single_for_device(dev, edesc->dma_link_tbl,
len, DMA_TO_DEVICE);
}
} else {
to_talitos_ptr_extent_clear(ptr, is_sec1);
sg_count = talitos_map_sg(dev, src, edesc->src_nents ? : 1, dir,
edesc->src_chained);
if (sg_count == 1) {
to_talitos_ptr(ptr, sg_dma_address(src), is_sec1);
} else {
sg_count = sg_to_link_tbl(src, sg_count, len,
&edesc->link_tbl[0]);
if (sg_count > 1) {
to_talitos_ptr(ptr, edesc->dma_link_tbl, 0);
ptr->j_extent |= DESC_PTR_LNKTBL_JUMP;
dma_sync_single_for_device(dev,
edesc->dma_link_tbl,
edesc->dma_len,
DMA_BIDIRECTIONAL);
} else {
to_talitos_ptr(ptr, sg_dma_address(src),
is_sec1);
}
}
}
return sg_count;
}
void map_sg_out_talitos_ptr(struct device *dev, struct scatterlist *dst,
unsigned int len, struct talitos_edesc *edesc,
enum dma_data_direction dir,
struct talitos_ptr *ptr, int sg_count)
{
struct talitos_private *priv = dev_get_drvdata(dev);
bool is_sec1 = has_ftr_sec1(priv);
if (dir != DMA_NONE)
sg_count = talitos_map_sg(dev, dst, edesc->dst_nents ? : 1,
dir, edesc->dst_chained);
to_talitos_ptr_len(ptr, len, is_sec1);
if (is_sec1) {
if (sg_count == 1) {
if (dir != DMA_NONE)
dma_map_sg(dev, dst, 1, dir);
to_talitos_ptr(ptr, sg_dma_address(dst), is_sec1);
} else {
to_talitos_ptr(ptr, edesc->dma_link_tbl + len, is_sec1);
dma_sync_single_for_device(dev,
edesc->dma_link_tbl + len,
len, DMA_FROM_DEVICE);
}
} else {
to_talitos_ptr_extent_clear(ptr, is_sec1);
if (sg_count == 1) {
to_talitos_ptr(ptr, sg_dma_address(dst), is_sec1);
} else {
struct talitos_ptr *link_tbl_ptr =
&edesc->link_tbl[edesc->src_nents + 1];
to_talitos_ptr(ptr, edesc->dma_link_tbl +
(edesc->src_nents + 1) *
sizeof(struct talitos_ptr), 0);
ptr->j_extent |= DESC_PTR_LNKTBL_JUMP;
sg_to_link_tbl(dst, sg_count, len, link_tbl_ptr);
dma_sync_single_for_device(dev, edesc->dma_link_tbl,
edesc->dma_len,
DMA_BIDIRECTIONAL);
}
}
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
unsigned int ivsize = crypto_ablkcipher_ivsize(cipher);
int sg_count, ret;
struct talitos_private *priv = dev_get_drvdata(dev);
bool is_sec1 = has_ftr_sec1(priv);
desc->ptr[0] = zero_entry;
to_talitos_ptr(&desc->ptr[1], edesc->iv_dma, is_sec1);
to_talitos_ptr_len(&desc->ptr[1], ivsize, is_sec1);
to_talitos_ptr_extent_clear(&desc->ptr[1], is_sec1);
map_single_talitos_ptr(dev, &desc->ptr[2], ctx->keylen,
(char *)&ctx->key, DMA_TO_DEVICE);
sg_count = map_sg_in_talitos_ptr(dev, areq->src, cryptlen, edesc,
(areq->src == areq->dst) ?
DMA_BIDIRECTIONAL : DMA_TO_DEVICE,
&desc->ptr[3]);
map_sg_out_talitos_ptr(dev, areq->dst, cryptlen, edesc,
(areq->src == areq->dst) ? DMA_NONE
: DMA_FROM_DEVICE,
&desc->ptr[4], sg_count);
map_single_talitos_ptr(dev, &desc->ptr[5], ivsize, ctx->iv,
DMA_FROM_DEVICE);
desc->ptr[6] = zero_entry;
ret = talitos_submit(dev, ctx->ch, desc, callback, areq);
if (ret != -EINPROGRESS) {
common_nonsnoop_unmap(dev, edesc, areq);
kfree(edesc);
}
return ret;
}
static struct talitos_edesc *ablkcipher_edesc_alloc(struct ablkcipher_request *
areq, bool encrypt)
{
struct crypto_ablkcipher *cipher = crypto_ablkcipher_reqtfm(areq);
struct talitos_ctx *ctx = crypto_ablkcipher_ctx(cipher);
unsigned int ivsize = crypto_ablkcipher_ivsize(cipher);
return talitos_edesc_alloc(ctx->dev, areq->src, areq->dst,
areq->info, 0, areq->nbytes, 0, ivsize, 0,
areq->base.flags, encrypt);
}
static int ablkcipher_encrypt(struct ablkcipher_request *areq)
{
struct crypto_ablkcipher *cipher = crypto_ablkcipher_reqtfm(areq);
struct talitos_ctx *ctx = crypto_ablkcipher_ctx(cipher);
struct talitos_edesc *edesc;
edesc = ablkcipher_edesc_alloc(areq, true);
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
edesc = ablkcipher_edesc_alloc(areq, false);
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
struct talitos_private *priv = dev_get_drvdata(dev);
bool is_sec1 = has_ftr_sec1(priv);
unmap_single_talitos_ptr(dev, &edesc->desc.ptr[5], DMA_FROM_DEVICE);
unmap_sg_talitos_ptr(dev, req_ctx->psrc, NULL, 0, edesc);
if (from_talitos_ptr_len(&edesc->desc.ptr[1], is_sec1))
unmap_single_talitos_ptr(dev, &edesc->desc.ptr[1],
DMA_TO_DEVICE);
if (from_talitos_ptr_len(&edesc->desc.ptr[2], is_sec1))
unmap_single_talitos_ptr(dev, &edesc->desc.ptr[2],
DMA_TO_DEVICE);
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
void talitos_handle_buggy_hash(struct talitos_ctx *ctx,
struct talitos_edesc *edesc,
struct talitos_ptr *ptr)
{
static u8 padded_hash[64] = {
0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
pr_err_once("Bug in SEC1, padding ourself\n");
edesc->desc.hdr &= ~DESC_HDR_MODE0_MDEU_PAD;
map_single_talitos_ptr(ctx->dev, ptr, sizeof(padded_hash),
(char *)padded_hash, DMA_TO_DEVICE);
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
int ret;
struct talitos_private *priv = dev_get_drvdata(dev);
bool is_sec1 = has_ftr_sec1(priv);
desc->ptr[0] = zero_entry;
if (!req_ctx->first || req_ctx->swinit) {
map_single_talitos_ptr(dev, &desc->ptr[1],
req_ctx->hw_context_size,
(char *)req_ctx->hw_context,
DMA_TO_DEVICE);
req_ctx->swinit = 0;
} else {
desc->ptr[1] = zero_entry;
req_ctx->first = 0;
}
if (ctx->keylen)
map_single_talitos_ptr(dev, &desc->ptr[2], ctx->keylen,
(char *)&ctx->key, DMA_TO_DEVICE);
else
desc->ptr[2] = zero_entry;
map_sg_in_talitos_ptr(dev, req_ctx->psrc, length, edesc,
DMA_TO_DEVICE, &desc->ptr[3]);
desc->ptr[4] = zero_entry;
if (req_ctx->last)
map_single_talitos_ptr(dev, &desc->ptr[5],
crypto_ahash_digestsize(tfm),
areq->result, DMA_FROM_DEVICE);
else
map_single_talitos_ptr(dev, &desc->ptr[5],
req_ctx->hw_context_size,
req_ctx->hw_context, DMA_FROM_DEVICE);
desc->ptr[6] = zero_entry;
if (is_sec1 && from_talitos_ptr_len(&desc->ptr[3], true) == 0)
talitos_handle_buggy_hash(ctx, edesc, &desc->ptr[3]);
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
return talitos_edesc_alloc(ctx->dev, req_ctx->psrc, NULL, NULL, 0,
nbytes, 0, 0, 0, areq->base.flags, false);
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
bool chained;
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
sg_chain(req_ctx->bufsl, 2, areq->src);
req_ctx->psrc = req_ctx->bufsl;
} else
req_ctx->psrc = areq->src;
if (to_hash_later) {
int nents = sg_count(areq->src, nbytes, &chained);
sg_pcopy_to_buffer(areq->src, nents,
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
static int talitos_cra_init_aead(struct crypto_aead *tfm)
{
talitos_cra_init(crypto_aead_tfm(tfm));
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
break;
case CRYPTO_ALG_TYPE_AEAD:
crypto_unregister_aead(&t_alg->algt.alg.aead);
case CRYPTO_ALG_TYPE_AHASH:
crypto_unregister_ahash(&t_alg->algt.alg.hash);
break;
}
list_del(&t_alg->entry);
kfree(t_alg);
}
if (hw_supports(dev, DESC_HDR_SEL0_RNG))
talitos_unregister_rng(dev);
for (i = 0; priv->chan && i < priv->num_channels; i++)
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
alg->cra_type = &crypto_ablkcipher_type;
alg->cra_ablkcipher.setkey = ablkcipher_setkey;
alg->cra_ablkcipher.encrypt = ablkcipher_encrypt;
alg->cra_ablkcipher.decrypt = ablkcipher_decrypt;
alg->cra_ablkcipher.geniv = "eseqiv";
break;
case CRYPTO_ALG_TYPE_AEAD:
alg = &t_alg->algt.alg.aead.base;
t_alg->algt.alg.aead.init = talitos_cra_init_aead;
t_alg->algt.alg.aead.setkey = aead_setkey;
t_alg->algt.alg.aead.encrypt = aead_encrypt;
t_alg->algt.alg.aead.decrypt = aead_decrypt;
break;
case CRYPTO_ALG_TYPE_AHASH:
alg = &t_alg->algt.alg.hash.halg.base;
alg->cra_init = talitos_cra_init_ahash;
alg->cra_type = &crypto_ahash_type;
t_alg->algt.alg.hash.init = ahash_init;
t_alg->algt.alg.hash.update = ahash_update;
t_alg->algt.alg.hash.final = ahash_final;
t_alg->algt.alg.hash.finup = ahash_finup;
t_alg->algt.alg.hash.digest = ahash_digest;
t_alg->algt.alg.hash.setkey = ahash_setkey;
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
kfree(t_alg);
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
bool is_sec1 = has_ftr_sec1(priv);
priv->irq[0] = irq_of_parse_and_map(np, 0);
if (!priv->irq[0]) {
dev_err(dev, "failed to map irq\n");
return -EINVAL;
}
if (is_sec1) {
err = request_irq(priv->irq[0], talitos1_interrupt_4ch, 0,
dev_driver_string(dev), dev);
goto primary_out;
}
priv->irq[1] = irq_of_parse_and_map(np, 1);
if (!priv->irq[1]) {
err = request_irq(priv->irq[0], talitos2_interrupt_4ch, 0,
dev_driver_string(dev), dev);
goto primary_out;
}
err = request_irq(priv->irq[0], talitos2_interrupt_ch0_2, 0,
dev_driver_string(dev), dev);
if (err)
goto primary_out;
err = request_irq(priv->irq[1], talitos2_interrupt_ch1_3, 0,
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
int stride;
priv = kzalloc(sizeof(struct talitos_private), GFP_KERNEL);
if (!priv)
return -ENOMEM;
INIT_LIST_HEAD(&priv->alg_list);
dev_set_drvdata(dev, priv);
priv->ofdev = ofdev;
spin_lock_init(&priv->reg_lock);
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
if (of_device_is_compatible(np, "fsl,sec1.0"))
priv->features |= TALITOS_FTR_SEC1;
if (of_device_is_compatible(np, "fsl,sec1.2")) {
priv->reg_deu = priv->reg + TALITOS12_DEU;
priv->reg_aesu = priv->reg + TALITOS12_AESU;
priv->reg_mdeu = priv->reg + TALITOS12_MDEU;
stride = TALITOS1_CH_STRIDE;
} else if (of_device_is_compatible(np, "fsl,sec1.0")) {
priv->reg_deu = priv->reg + TALITOS10_DEU;
priv->reg_aesu = priv->reg + TALITOS10_AESU;
priv->reg_mdeu = priv->reg + TALITOS10_MDEU;
priv->reg_afeu = priv->reg + TALITOS10_AFEU;
priv->reg_rngu = priv->reg + TALITOS10_RNGU;
priv->reg_pkeu = priv->reg + TALITOS10_PKEU;
stride = TALITOS1_CH_STRIDE;
} else {
priv->reg_deu = priv->reg + TALITOS2_DEU;
priv->reg_aesu = priv->reg + TALITOS2_AESU;
priv->reg_mdeu = priv->reg + TALITOS2_MDEU;
priv->reg_afeu = priv->reg + TALITOS2_AFEU;
priv->reg_rngu = priv->reg + TALITOS2_RNGU;
priv->reg_pkeu = priv->reg + TALITOS2_PKEU;
priv->reg_keu = priv->reg + TALITOS2_KEU;
priv->reg_crcu = priv->reg + TALITOS2_CRCU;
stride = TALITOS2_CH_STRIDE;
}
err = talitos_probe_irq(ofdev);
if (err)
goto err_out;
if (of_device_is_compatible(np, "fsl,sec1.0")) {
tasklet_init(&priv->done_task[0], talitos1_done_4ch,
(unsigned long)dev);
} else {
if (!priv->irq[1]) {
tasklet_init(&priv->done_task[0], talitos2_done_4ch,
(unsigned long)dev);
} else {
tasklet_init(&priv->done_task[0], talitos2_done_ch0_2,
(unsigned long)dev);
tasklet_init(&priv->done_task[1], talitos2_done_ch1_3,
(unsigned long)dev);
}
}
priv->chan = kzalloc(sizeof(struct talitos_channel) *
priv->num_channels, GFP_KERNEL);
if (!priv->chan) {
dev_err(dev, "failed to allocate channel management space\n");
err = -ENOMEM;
goto err_out;
}
priv->fifo_len = roundup_pow_of_two(priv->chfifo_len);
for (i = 0; i < priv->num_channels; i++) {
priv->chan[i].reg = priv->reg + stride * (i + 1);
if (!priv->irq[1] || !(i & 1))
priv->chan[i].reg += TALITOS_CH_BASE_OFFSET;
spin_lock_init(&priv->chan[i].head_lock);
spin_lock_init(&priv->chan[i].tail_lock);
priv->chan[i].fifo = kzalloc(sizeof(struct talitos_request) *
priv->fifo_len, GFP_KERNEL);
if (!priv->chan[i].fifo) {
dev_err(dev, "failed to allocate request fifo %d\n", i);
err = -ENOMEM;
goto err_out;
}
atomic_set(&priv->chan[i].submit_count,
-(priv->chfifo_len - 1));
}
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
struct crypto_alg *alg = NULL;
t_alg = talitos_alg_alloc(dev, &driver_algs[i]);
if (IS_ERR(t_alg)) {
err = PTR_ERR(t_alg);
if (err == -ENOTSUPP)
continue;
goto err_out;
}
switch (t_alg->algt.type) {
case CRYPTO_ALG_TYPE_ABLKCIPHER:
err = crypto_register_alg(
&t_alg->algt.alg.crypto);
alg = &t_alg->algt.alg.crypto;
break;
case CRYPTO_ALG_TYPE_AEAD:
err = crypto_register_aead(
&t_alg->algt.alg.aead);
alg = &t_alg->algt.alg.aead.base;
break;
case CRYPTO_ALG_TYPE_AHASH:
err = crypto_register_ahash(
&t_alg->algt.alg.hash);
alg = &t_alg->algt.alg.hash.halg.base;
break;
}
if (err) {
dev_err(dev, "%s alg registration failed\n",
alg->cra_driver_name);
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
