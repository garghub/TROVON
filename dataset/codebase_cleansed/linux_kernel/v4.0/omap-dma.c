static inline struct omap_dmadev *to_omap_dma_dev(struct dma_device *d)
{
return container_of(d, struct omap_dmadev, ddev);
}
static inline struct omap_chan *to_omap_dma_chan(struct dma_chan *c)
{
return container_of(c, struct omap_chan, vc.chan);
}
static inline struct omap_desc *to_omap_dma_desc(struct dma_async_tx_descriptor *t)
{
return container_of(t, struct omap_desc, vd.tx);
}
static void omap_dma_desc_free(struct virt_dma_desc *vd)
{
kfree(container_of(vd, struct omap_desc, vd));
}
static void omap_dma_write(uint32_t val, unsigned type, void __iomem *addr)
{
switch (type) {
case OMAP_DMA_REG_16BIT:
writew_relaxed(val, addr);
break;
case OMAP_DMA_REG_2X16BIT:
writew_relaxed(val, addr);
writew_relaxed(val >> 16, addr + 2);
break;
case OMAP_DMA_REG_32BIT:
writel_relaxed(val, addr);
break;
default:
WARN_ON(1);
}
}
static unsigned omap_dma_read(unsigned type, void __iomem *addr)
{
unsigned val;
switch (type) {
case OMAP_DMA_REG_16BIT:
val = readw_relaxed(addr);
break;
case OMAP_DMA_REG_2X16BIT:
val = readw_relaxed(addr);
val |= readw_relaxed(addr + 2) << 16;
break;
case OMAP_DMA_REG_32BIT:
val = readl_relaxed(addr);
break;
default:
WARN_ON(1);
val = 0;
}
return val;
}
static void omap_dma_glbl_write(struct omap_dmadev *od, unsigned reg, unsigned val)
{
const struct omap_dma_reg *r = od->reg_map + reg;
WARN_ON(r->stride);
omap_dma_write(val, r->type, od->base + r->offset);
}
static unsigned omap_dma_glbl_read(struct omap_dmadev *od, unsigned reg)
{
const struct omap_dma_reg *r = od->reg_map + reg;
WARN_ON(r->stride);
return omap_dma_read(r->type, od->base + r->offset);
}
static void omap_dma_chan_write(struct omap_chan *c, unsigned reg, unsigned val)
{
const struct omap_dma_reg *r = c->reg_map + reg;
omap_dma_write(val, r->type, c->channel_base + r->offset);
}
static unsigned omap_dma_chan_read(struct omap_chan *c, unsigned reg)
{
const struct omap_dma_reg *r = c->reg_map + reg;
return omap_dma_read(r->type, c->channel_base + r->offset);
}
static void omap_dma_clear_csr(struct omap_chan *c)
{
if (dma_omap1())
omap_dma_chan_read(c, CSR);
else
omap_dma_chan_write(c, CSR, ~0);
}
static unsigned omap_dma_get_csr(struct omap_chan *c)
{
unsigned val = omap_dma_chan_read(c, CSR);
if (!dma_omap1())
omap_dma_chan_write(c, CSR, val);
return val;
}
static void omap_dma_assign(struct omap_dmadev *od, struct omap_chan *c,
unsigned lch)
{
c->channel_base = od->base + od->plat->channel_stride * lch;
od->lch_map[lch] = c;
}
static void omap_dma_start(struct omap_chan *c, struct omap_desc *d)
{
struct omap_dmadev *od = to_omap_dma_dev(c->vc.chan.device);
if (__dma_omap15xx(od->plat->dma_attr))
omap_dma_chan_write(c, CPC, 0);
else
omap_dma_chan_write(c, CDAC, 0);
omap_dma_clear_csr(c);
omap_dma_chan_write(c, CICR, d->cicr);
omap_dma_chan_write(c, CCR, d->ccr | CCR_ENABLE);
}
static void omap_dma_stop(struct omap_chan *c)
{
struct omap_dmadev *od = to_omap_dma_dev(c->vc.chan.device);
uint32_t val;
omap_dma_chan_write(c, CICR, 0);
omap_dma_clear_csr(c);
val = omap_dma_chan_read(c, CCR);
if (od->plat->errata & DMA_ERRATA_i541 && val & CCR_TRIGGER_SRC) {
uint32_t sysconfig;
unsigned i;
sysconfig = omap_dma_glbl_read(od, OCP_SYSCONFIG);
val = sysconfig & ~DMA_SYSCONFIG_MIDLEMODE_MASK;
val |= DMA_SYSCONFIG_MIDLEMODE(DMA_IDLEMODE_NO_IDLE);
omap_dma_glbl_write(od, OCP_SYSCONFIG, val);
val = omap_dma_chan_read(c, CCR);
val &= ~CCR_ENABLE;
omap_dma_chan_write(c, CCR, val);
for (i = 0; ; i++) {
val = omap_dma_chan_read(c, CCR);
if (!(val & (CCR_RD_ACTIVE | CCR_WR_ACTIVE)))
break;
if (i > 100)
break;
udelay(5);
}
if (val & (CCR_RD_ACTIVE | CCR_WR_ACTIVE))
dev_err(c->vc.chan.device->dev,
"DMA drain did not complete on lch %d\n",
c->dma_ch);
omap_dma_glbl_write(od, OCP_SYSCONFIG, sysconfig);
} else {
val &= ~CCR_ENABLE;
omap_dma_chan_write(c, CCR, val);
}
mb();
if (!__dma_omap15xx(od->plat->dma_attr) && c->cyclic) {
val = omap_dma_chan_read(c, CLNK_CTRL);
if (dma_omap1())
val |= 1 << 14;
else
val &= ~CLNK_CTRL_ENABLE_LNK;
omap_dma_chan_write(c, CLNK_CTRL, val);
}
}
static void omap_dma_start_sg(struct omap_chan *c, struct omap_desc *d,
unsigned idx)
{
struct omap_sg *sg = d->sg + idx;
unsigned cxsa, cxei, cxfi;
if (d->dir == DMA_DEV_TO_MEM) {
cxsa = CDSA;
cxei = CDEI;
cxfi = CDFI;
} else {
cxsa = CSSA;
cxei = CSEI;
cxfi = CSFI;
}
omap_dma_chan_write(c, cxsa, sg->addr);
omap_dma_chan_write(c, cxei, 0);
omap_dma_chan_write(c, cxfi, 0);
omap_dma_chan_write(c, CEN, sg->en);
omap_dma_chan_write(c, CFN, sg->fn);
omap_dma_start(c, d);
}
static void omap_dma_start_desc(struct omap_chan *c)
{
struct virt_dma_desc *vd = vchan_next_desc(&c->vc);
struct omap_desc *d;
unsigned cxsa, cxei, cxfi;
if (!vd) {
c->desc = NULL;
return;
}
list_del(&vd->node);
c->desc = d = to_omap_dma_desc(&vd->tx);
c->sgidx = 0;
mb();
omap_dma_chan_write(c, CCR, d->ccr);
if (dma_omap1())
omap_dma_chan_write(c, CCR2, d->ccr >> 16);
if (d->dir == DMA_DEV_TO_MEM) {
cxsa = CSSA;
cxei = CSEI;
cxfi = CSFI;
} else {
cxsa = CDSA;
cxei = CDEI;
cxfi = CDFI;
}
omap_dma_chan_write(c, cxsa, d->dev_addr);
omap_dma_chan_write(c, cxei, 0);
omap_dma_chan_write(c, cxfi, d->fi);
omap_dma_chan_write(c, CSDP, d->csdp);
omap_dma_chan_write(c, CLNK_CTRL, d->clnk_ctrl);
omap_dma_start_sg(c, d, 0);
}
static void omap_dma_callback(int ch, u16 status, void *data)
{
struct omap_chan *c = data;
struct omap_desc *d;
unsigned long flags;
spin_lock_irqsave(&c->vc.lock, flags);
d = c->desc;
if (d) {
if (!c->cyclic) {
if (++c->sgidx < d->sglen) {
omap_dma_start_sg(c, d, c->sgidx);
} else {
omap_dma_start_desc(c);
vchan_cookie_complete(&d->vd);
}
} else {
vchan_cyclic_callback(&d->vd);
}
}
spin_unlock_irqrestore(&c->vc.lock, flags);
}
static void omap_dma_sched(unsigned long data)
{
struct omap_dmadev *d = (struct omap_dmadev *)data;
LIST_HEAD(head);
spin_lock_irq(&d->lock);
list_splice_tail_init(&d->pending, &head);
spin_unlock_irq(&d->lock);
while (!list_empty(&head)) {
struct omap_chan *c = list_first_entry(&head,
struct omap_chan, node);
spin_lock_irq(&c->vc.lock);
list_del_init(&c->node);
omap_dma_start_desc(c);
spin_unlock_irq(&c->vc.lock);
}
}
static irqreturn_t omap_dma_irq(int irq, void *devid)
{
struct omap_dmadev *od = devid;
unsigned status, channel;
spin_lock(&od->irq_lock);
status = omap_dma_glbl_read(od, IRQSTATUS_L1);
status &= od->irq_enable_mask;
if (status == 0) {
spin_unlock(&od->irq_lock);
return IRQ_NONE;
}
while ((channel = ffs(status)) != 0) {
unsigned mask, csr;
struct omap_chan *c;
channel -= 1;
mask = BIT(channel);
status &= ~mask;
c = od->lch_map[channel];
if (c == NULL) {
dev_err(od->ddev.dev, "invalid channel %u\n", channel);
continue;
}
csr = omap_dma_get_csr(c);
omap_dma_glbl_write(od, IRQSTATUS_L1, mask);
omap_dma_callback(channel, csr, c);
}
spin_unlock(&od->irq_lock);
return IRQ_HANDLED;
}
static int omap_dma_alloc_chan_resources(struct dma_chan *chan)
{
struct omap_dmadev *od = to_omap_dma_dev(chan->device);
struct omap_chan *c = to_omap_dma_chan(chan);
int ret;
if (od->legacy) {
ret = omap_request_dma(c->dma_sig, "DMA engine",
omap_dma_callback, c, &c->dma_ch);
} else {
ret = omap_request_dma(c->dma_sig, "DMA engine", NULL, NULL,
&c->dma_ch);
}
dev_dbg(od->ddev.dev, "allocating channel %u for %u\n",
c->dma_ch, c->dma_sig);
if (ret >= 0) {
omap_dma_assign(od, c, c->dma_ch);
if (!od->legacy) {
unsigned val;
spin_lock_irq(&od->irq_lock);
val = BIT(c->dma_ch);
omap_dma_glbl_write(od, IRQSTATUS_L1, val);
od->irq_enable_mask |= val;
omap_dma_glbl_write(od, IRQENABLE_L1, od->irq_enable_mask);
val = omap_dma_glbl_read(od, IRQENABLE_L0);
val &= ~BIT(c->dma_ch);
omap_dma_glbl_write(od, IRQENABLE_L0, val);
spin_unlock_irq(&od->irq_lock);
}
}
if (dma_omap1()) {
if (__dma_omap16xx(od->plat->dma_attr)) {
c->ccr = CCR_OMAP31_DISABLE;
c->ccr |= c->dma_ch + 1;
} else {
c->ccr = c->dma_sig & 0x1f;
}
} else {
c->ccr = c->dma_sig & 0x1f;
c->ccr |= (c->dma_sig & ~0x1f) << 14;
}
if (od->plat->errata & DMA_ERRATA_IFRAME_BUFFERING)
c->ccr |= CCR_BUFFERING_DISABLE;
return ret;
}
static void omap_dma_free_chan_resources(struct dma_chan *chan)
{
struct omap_dmadev *od = to_omap_dma_dev(chan->device);
struct omap_chan *c = to_omap_dma_chan(chan);
if (!od->legacy) {
spin_lock_irq(&od->irq_lock);
od->irq_enable_mask &= ~BIT(c->dma_ch);
omap_dma_glbl_write(od, IRQENABLE_L1, od->irq_enable_mask);
spin_unlock_irq(&od->irq_lock);
}
c->channel_base = NULL;
od->lch_map[c->dma_ch] = NULL;
vchan_free_chan_resources(&c->vc);
omap_free_dma(c->dma_ch);
dev_dbg(od->ddev.dev, "freeing channel for %u\n", c->dma_sig);
}
static size_t omap_dma_sg_size(struct omap_sg *sg)
{
return sg->en * sg->fn;
}
static size_t omap_dma_desc_size(struct omap_desc *d)
{
unsigned i;
size_t size;
for (size = i = 0; i < d->sglen; i++)
size += omap_dma_sg_size(&d->sg[i]);
return size * es_bytes[d->es];
}
static size_t omap_dma_desc_size_pos(struct omap_desc *d, dma_addr_t addr)
{
unsigned i;
size_t size, es_size = es_bytes[d->es];
for (size = i = 0; i < d->sglen; i++) {
size_t this_size = omap_dma_sg_size(&d->sg[i]) * es_size;
if (size)
size += this_size;
else if (addr >= d->sg[i].addr &&
addr < d->sg[i].addr + this_size)
size += d->sg[i].addr + this_size - addr;
}
return size;
}
static uint32_t omap_dma_chan_read_3_3(struct omap_chan *c, unsigned reg)
{
struct omap_dmadev *od = to_omap_dma_dev(c->vc.chan.device);
uint32_t val;
val = omap_dma_chan_read(c, reg);
if (val == 0 && od->plat->errata & DMA_ERRATA_3_3)
val = omap_dma_chan_read(c, reg);
return val;
}
static dma_addr_t omap_dma_get_src_pos(struct omap_chan *c)
{
struct omap_dmadev *od = to_omap_dma_dev(c->vc.chan.device);
dma_addr_t addr, cdac;
if (__dma_omap15xx(od->plat->dma_attr)) {
addr = omap_dma_chan_read(c, CPC);
} else {
addr = omap_dma_chan_read_3_3(c, CSAC);
cdac = omap_dma_chan_read_3_3(c, CDAC);
if (cdac == 0)
addr = omap_dma_chan_read(c, CSSA);
}
if (dma_omap1())
addr |= omap_dma_chan_read(c, CSSA) & 0xffff0000;
return addr;
}
static dma_addr_t omap_dma_get_dst_pos(struct omap_chan *c)
{
struct omap_dmadev *od = to_omap_dma_dev(c->vc.chan.device);
dma_addr_t addr;
if (__dma_omap15xx(od->plat->dma_attr)) {
addr = omap_dma_chan_read(c, CPC);
} else {
addr = omap_dma_chan_read_3_3(c, CDAC);
if (addr == 0)
addr = omap_dma_chan_read(c, CDSA);
}
if (dma_omap1())
addr |= omap_dma_chan_read(c, CDSA) & 0xffff0000;
return addr;
}
static enum dma_status omap_dma_tx_status(struct dma_chan *chan,
dma_cookie_t cookie, struct dma_tx_state *txstate)
{
struct omap_chan *c = to_omap_dma_chan(chan);
struct virt_dma_desc *vd;
enum dma_status ret;
unsigned long flags;
ret = dma_cookie_status(chan, cookie, txstate);
if (ret == DMA_COMPLETE || !txstate)
return ret;
spin_lock_irqsave(&c->vc.lock, flags);
vd = vchan_find_desc(&c->vc, cookie);
if (vd) {
txstate->residue = omap_dma_desc_size(to_omap_dma_desc(&vd->tx));
} else if (c->desc && c->desc->vd.tx.cookie == cookie) {
struct omap_desc *d = c->desc;
dma_addr_t pos;
if (d->dir == DMA_MEM_TO_DEV)
pos = omap_dma_get_src_pos(c);
else if (d->dir == DMA_DEV_TO_MEM)
pos = omap_dma_get_dst_pos(c);
else
pos = 0;
txstate->residue = omap_dma_desc_size_pos(d, pos);
} else {
txstate->residue = 0;
}
spin_unlock_irqrestore(&c->vc.lock, flags);
return ret;
}
static void omap_dma_issue_pending(struct dma_chan *chan)
{
struct omap_chan *c = to_omap_dma_chan(chan);
unsigned long flags;
spin_lock_irqsave(&c->vc.lock, flags);
if (vchan_issue_pending(&c->vc) && !c->desc) {
if (!c->cyclic) {
struct omap_dmadev *d = to_omap_dma_dev(chan->device);
spin_lock(&d->lock);
if (list_empty(&c->node))
list_add_tail(&c->node, &d->pending);
spin_unlock(&d->lock);
tasklet_schedule(&d->task);
} else {
omap_dma_start_desc(c);
}
}
spin_unlock_irqrestore(&c->vc.lock, flags);
}
static struct dma_async_tx_descriptor *omap_dma_prep_slave_sg(
struct dma_chan *chan, struct scatterlist *sgl, unsigned sglen,
enum dma_transfer_direction dir, unsigned long tx_flags, void *context)
{
struct omap_dmadev *od = to_omap_dma_dev(chan->device);
struct omap_chan *c = to_omap_dma_chan(chan);
enum dma_slave_buswidth dev_width;
struct scatterlist *sgent;
struct omap_desc *d;
dma_addr_t dev_addr;
unsigned i, j = 0, es, en, frame_bytes;
u32 burst;
if (dir == DMA_DEV_TO_MEM) {
dev_addr = c->cfg.src_addr;
dev_width = c->cfg.src_addr_width;
burst = c->cfg.src_maxburst;
} else if (dir == DMA_MEM_TO_DEV) {
dev_addr = c->cfg.dst_addr;
dev_width = c->cfg.dst_addr_width;
burst = c->cfg.dst_maxburst;
} else {
dev_err(chan->device->dev, "%s: bad direction?\n", __func__);
return NULL;
}
switch (dev_width) {
case DMA_SLAVE_BUSWIDTH_1_BYTE:
es = CSDP_DATA_TYPE_8;
break;
case DMA_SLAVE_BUSWIDTH_2_BYTES:
es = CSDP_DATA_TYPE_16;
break;
case DMA_SLAVE_BUSWIDTH_4_BYTES:
es = CSDP_DATA_TYPE_32;
break;
default:
return NULL;
}
d = kzalloc(sizeof(*d) + sglen * sizeof(d->sg[0]), GFP_ATOMIC);
if (!d)
return NULL;
d->dir = dir;
d->dev_addr = dev_addr;
d->es = es;
d->ccr = c->ccr | CCR_SYNC_FRAME;
if (dir == DMA_DEV_TO_MEM)
d->ccr |= CCR_DST_AMODE_POSTINC | CCR_SRC_AMODE_CONSTANT;
else
d->ccr |= CCR_DST_AMODE_CONSTANT | CCR_SRC_AMODE_POSTINC;
d->cicr = CICR_DROP_IE | CICR_BLOCK_IE;
d->csdp = es;
if (dma_omap1()) {
d->cicr |= CICR_TOUT_IE;
if (dir == DMA_DEV_TO_MEM)
d->csdp |= CSDP_DST_PORT_EMIFF | CSDP_SRC_PORT_TIPB;
else
d->csdp |= CSDP_DST_PORT_TIPB | CSDP_SRC_PORT_EMIFF;
} else {
if (dir == DMA_DEV_TO_MEM)
d->ccr |= CCR_TRIGGER_SRC;
d->cicr |= CICR_MISALIGNED_ERR_IE | CICR_TRANS_ERR_IE;
}
if (od->plat->errata & DMA_ERRATA_PARALLEL_CHANNELS)
d->clnk_ctrl = c->dma_ch;
en = burst;
frame_bytes = es_bytes[es] * en;
for_each_sg(sgl, sgent, sglen, i) {
d->sg[j].addr = sg_dma_address(sgent);
d->sg[j].en = en;
d->sg[j].fn = sg_dma_len(sgent) / frame_bytes;
j++;
}
d->sglen = j;
return vchan_tx_prep(&c->vc, &d->vd, tx_flags);
}
static struct dma_async_tx_descriptor *omap_dma_prep_dma_cyclic(
struct dma_chan *chan, dma_addr_t buf_addr, size_t buf_len,
size_t period_len, enum dma_transfer_direction dir, unsigned long flags)
{
struct omap_dmadev *od = to_omap_dma_dev(chan->device);
struct omap_chan *c = to_omap_dma_chan(chan);
enum dma_slave_buswidth dev_width;
struct omap_desc *d;
dma_addr_t dev_addr;
unsigned es;
u32 burst;
if (dir == DMA_DEV_TO_MEM) {
dev_addr = c->cfg.src_addr;
dev_width = c->cfg.src_addr_width;
burst = c->cfg.src_maxburst;
} else if (dir == DMA_MEM_TO_DEV) {
dev_addr = c->cfg.dst_addr;
dev_width = c->cfg.dst_addr_width;
burst = c->cfg.dst_maxburst;
} else {
dev_err(chan->device->dev, "%s: bad direction?\n", __func__);
return NULL;
}
switch (dev_width) {
case DMA_SLAVE_BUSWIDTH_1_BYTE:
es = CSDP_DATA_TYPE_8;
break;
case DMA_SLAVE_BUSWIDTH_2_BYTES:
es = CSDP_DATA_TYPE_16;
break;
case DMA_SLAVE_BUSWIDTH_4_BYTES:
es = CSDP_DATA_TYPE_32;
break;
default:
return NULL;
}
d = kzalloc(sizeof(*d) + sizeof(d->sg[0]), GFP_ATOMIC);
if (!d)
return NULL;
d->dir = dir;
d->dev_addr = dev_addr;
d->fi = burst;
d->es = es;
d->sg[0].addr = buf_addr;
d->sg[0].en = period_len / es_bytes[es];
d->sg[0].fn = buf_len / period_len;
d->sglen = 1;
d->ccr = c->ccr;
if (dir == DMA_DEV_TO_MEM)
d->ccr |= CCR_DST_AMODE_POSTINC | CCR_SRC_AMODE_CONSTANT;
else
d->ccr |= CCR_DST_AMODE_CONSTANT | CCR_SRC_AMODE_POSTINC;
d->cicr = CICR_DROP_IE;
if (flags & DMA_PREP_INTERRUPT)
d->cicr |= CICR_FRAME_IE;
d->csdp = es;
if (dma_omap1()) {
d->cicr |= CICR_TOUT_IE;
if (dir == DMA_DEV_TO_MEM)
d->csdp |= CSDP_DST_PORT_EMIFF | CSDP_SRC_PORT_MPUI;
else
d->csdp |= CSDP_DST_PORT_MPUI | CSDP_SRC_PORT_EMIFF;
} else {
if (burst)
d->ccr |= CCR_SYNC_PACKET;
else
d->ccr |= CCR_SYNC_ELEMENT;
if (dir == DMA_DEV_TO_MEM)
d->ccr |= CCR_TRIGGER_SRC;
d->cicr |= CICR_MISALIGNED_ERR_IE | CICR_TRANS_ERR_IE;
d->csdp |= CSDP_DST_BURST_64 | CSDP_SRC_BURST_64;
}
if (__dma_omap15xx(od->plat->dma_attr))
d->ccr |= CCR_AUTO_INIT | CCR_REPEAT;
else
d->clnk_ctrl = c->dma_ch | CLNK_CTRL_ENABLE_LNK;
c->cyclic = true;
return vchan_tx_prep(&c->vc, &d->vd, flags);
}
static int omap_dma_slave_config(struct dma_chan *chan, struct dma_slave_config *cfg)
{
struct omap_chan *c = to_omap_dma_chan(chan);
if (cfg->src_addr_width == DMA_SLAVE_BUSWIDTH_8_BYTES ||
cfg->dst_addr_width == DMA_SLAVE_BUSWIDTH_8_BYTES)
return -EINVAL;
memcpy(&c->cfg, cfg, sizeof(c->cfg));
return 0;
}
static int omap_dma_terminate_all(struct dma_chan *chan)
{
struct omap_chan *c = to_omap_dma_chan(chan);
struct omap_dmadev *d = to_omap_dma_dev(c->vc.chan.device);
unsigned long flags;
LIST_HEAD(head);
spin_lock_irqsave(&c->vc.lock, flags);
spin_lock(&d->lock);
list_del_init(&c->node);
spin_unlock(&d->lock);
if (c->desc) {
omap_dma_desc_free(&c->desc->vd);
c->desc = NULL;
if (!c->paused)
omap_dma_stop(c);
}
if (c->cyclic) {
c->cyclic = false;
c->paused = false;
}
vchan_get_all_descriptors(&c->vc, &head);
spin_unlock_irqrestore(&c->vc.lock, flags);
vchan_dma_desc_free_list(&c->vc, &head);
return 0;
}
static int omap_dma_pause(struct dma_chan *chan)
{
struct omap_chan *c = to_omap_dma_chan(chan);
if (!c->cyclic)
return -EINVAL;
if (!c->paused) {
omap_dma_stop(c);
c->paused = true;
}
return 0;
}
static int omap_dma_resume(struct dma_chan *chan)
{
struct omap_chan *c = to_omap_dma_chan(chan);
if (!c->cyclic)
return -EINVAL;
if (c->paused) {
mb();
omap_dma_chan_write(c, CLNK_CTRL, c->desc->clnk_ctrl);
omap_dma_start(c, c->desc);
c->paused = false;
}
return 0;
}
static int omap_dma_chan_init(struct omap_dmadev *od, int dma_sig)
{
struct omap_chan *c;
c = kzalloc(sizeof(*c), GFP_KERNEL);
if (!c)
return -ENOMEM;
c->reg_map = od->reg_map;
c->dma_sig = dma_sig;
c->vc.desc_free = omap_dma_desc_free;
vchan_init(&c->vc, &od->ddev);
INIT_LIST_HEAD(&c->node);
return 0;
}
static void omap_dma_free(struct omap_dmadev *od)
{
tasklet_kill(&od->task);
while (!list_empty(&od->ddev.channels)) {
struct omap_chan *c = list_first_entry(&od->ddev.channels,
struct omap_chan, vc.chan.device_node);
list_del(&c->vc.chan.device_node);
tasklet_kill(&c->vc.task);
kfree(c);
}
}
static int omap_dma_probe(struct platform_device *pdev)
{
struct omap_dmadev *od;
struct resource *res;
int rc, i, irq;
od = devm_kzalloc(&pdev->dev, sizeof(*od), GFP_KERNEL);
if (!od)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
od->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(od->base))
return PTR_ERR(od->base);
od->plat = omap_get_plat_info();
if (!od->plat)
return -EPROBE_DEFER;
od->reg_map = od->plat->reg_map;
dma_cap_set(DMA_SLAVE, od->ddev.cap_mask);
dma_cap_set(DMA_CYCLIC, od->ddev.cap_mask);
od->ddev.device_alloc_chan_resources = omap_dma_alloc_chan_resources;
od->ddev.device_free_chan_resources = omap_dma_free_chan_resources;
od->ddev.device_tx_status = omap_dma_tx_status;
od->ddev.device_issue_pending = omap_dma_issue_pending;
od->ddev.device_prep_slave_sg = omap_dma_prep_slave_sg;
od->ddev.device_prep_dma_cyclic = omap_dma_prep_dma_cyclic;
od->ddev.device_config = omap_dma_slave_config;
od->ddev.device_pause = omap_dma_pause;
od->ddev.device_resume = omap_dma_resume;
od->ddev.device_terminate_all = omap_dma_terminate_all;
od->ddev.src_addr_widths = OMAP_DMA_BUSWIDTHS;
od->ddev.dst_addr_widths = OMAP_DMA_BUSWIDTHS;
od->ddev.directions = BIT(DMA_DEV_TO_MEM) | BIT(DMA_MEM_TO_DEV);
od->ddev.residue_granularity = DMA_RESIDUE_GRANULARITY_BURST;
od->ddev.dev = &pdev->dev;
INIT_LIST_HEAD(&od->ddev.channels);
INIT_LIST_HEAD(&od->pending);
spin_lock_init(&od->lock);
spin_lock_init(&od->irq_lock);
tasklet_init(&od->task, omap_dma_sched, (unsigned long)od);
for (i = 0; i < 127; i++) {
rc = omap_dma_chan_init(od, i);
if (rc) {
omap_dma_free(od);
return rc;
}
}
irq = platform_get_irq(pdev, 1);
if (irq <= 0) {
dev_info(&pdev->dev, "failed to get L1 IRQ: %d\n", irq);
od->legacy = true;
} else {
od->irq_enable_mask = 0;
omap_dma_glbl_write(od, IRQENABLE_L1, 0);
rc = devm_request_irq(&pdev->dev, irq, omap_dma_irq,
IRQF_SHARED, "omap-dma-engine", od);
if (rc)
return rc;
}
rc = dma_async_device_register(&od->ddev);
if (rc) {
pr_warn("OMAP-DMA: failed to register slave DMA engine device: %d\n",
rc);
omap_dma_free(od);
return rc;
}
platform_set_drvdata(pdev, od);
if (pdev->dev.of_node) {
omap_dma_info.dma_cap = od->ddev.cap_mask;
rc = of_dma_controller_register(pdev->dev.of_node,
of_dma_simple_xlate, &omap_dma_info);
if (rc) {
pr_warn("OMAP-DMA: failed to register DMA controller\n");
dma_async_device_unregister(&od->ddev);
omap_dma_free(od);
}
}
dev_info(&pdev->dev, "OMAP DMA engine driver\n");
return rc;
}
static int omap_dma_remove(struct platform_device *pdev)
{
struct omap_dmadev *od = platform_get_drvdata(pdev);
if (pdev->dev.of_node)
of_dma_controller_free(pdev->dev.of_node);
dma_async_device_unregister(&od->ddev);
if (!od->legacy) {
omap_dma_glbl_write(od, IRQENABLE_L0, 0);
}
omap_dma_free(od);
return 0;
}
bool omap_dma_filter_fn(struct dma_chan *chan, void *param)
{
if (chan->device->dev->driver == &omap_dma_driver.driver) {
struct omap_chan *c = to_omap_dma_chan(chan);
unsigned req = *(unsigned *)param;
return req == c->dma_sig;
}
return false;
}
static int omap_dma_init(void)
{
return platform_driver_register(&omap_dma_driver);
}
static void __exit omap_dma_exit(void)
{
platform_driver_unregister(&omap_dma_driver);
}
