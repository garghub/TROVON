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
struct omap_desc *d = to_omap_dma_desc(&vd->tx);
if (d->using_ll) {
struct omap_dmadev *od = to_omap_dma_dev(vd->tx.chan->device);
int i;
for (i = 0; i < d->sglen; i++) {
if (d->sg[i].t2_desc)
dma_pool_free(od->desc_pool, d->sg[i].t2_desc,
d->sg[i].t2_desc_paddr);
}
}
kfree(d);
}
static void omap_dma_fill_type2_desc(struct omap_desc *d, int idx,
enum dma_transfer_direction dir, bool last)
{
struct omap_sg *sg = &d->sg[idx];
struct omap_type2_desc *t2_desc = sg->t2_desc;
if (idx)
d->sg[idx - 1].t2_desc->next_desc = sg->t2_desc_paddr;
if (last)
t2_desc->next_desc = 0xfffffffc;
t2_desc->en = sg->en;
t2_desc->addr = sg->addr;
t2_desc->fn = sg->fn & 0xffff;
t2_desc->cicr = d->cicr;
if (!last)
t2_desc->cicr &= ~CICR_BLOCK_IE;
switch (dir) {
case DMA_DEV_TO_MEM:
t2_desc->cdei = sg->ei;
t2_desc->csei = d->ei;
t2_desc->cdfi = sg->fi;
t2_desc->csfi = d->fi;
t2_desc->en |= DESC_NXT_DV_REFRESH;
t2_desc->en |= DESC_NXT_SV_REUSE;
break;
case DMA_MEM_TO_DEV:
t2_desc->cdei = d->ei;
t2_desc->csei = sg->ei;
t2_desc->cdfi = d->fi;
t2_desc->csfi = sg->fi;
t2_desc->en |= DESC_NXT_SV_REFRESH;
t2_desc->en |= DESC_NXT_DV_REUSE;
break;
default:
return;
}
t2_desc->en |= DESC_NTYPE_TYPE2;
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
uint16_t cicr = d->cicr;
if (__dma_omap15xx(od->plat->dma_attr))
omap_dma_chan_write(c, CPC, 0);
else
omap_dma_chan_write(c, CDAC, 0);
omap_dma_clear_csr(c);
if (d->using_ll) {
uint32_t cdp = CDP_TMODE_LLIST | CDP_NTYPE_TYPE2 | CDP_FAST;
if (d->dir == DMA_DEV_TO_MEM)
cdp |= (CDP_DST_VALID_RELOAD | CDP_SRC_VALID_REUSE);
else
cdp |= (CDP_DST_VALID_REUSE | CDP_SRC_VALID_RELOAD);
omap_dma_chan_write(c, CDP, cdp);
omap_dma_chan_write(c, CNDP, d->sg[0].t2_desc_paddr);
omap_dma_chan_write(c, CCDN, 0);
omap_dma_chan_write(c, CCFN, 0xffff);
omap_dma_chan_write(c, CCEN, 0xffffff);
cicr &= ~CICR_BLOCK_IE;
} else if (od->ll123_supported) {
omap_dma_chan_write(c, CDP, 0);
}
omap_dma_chan_write(c, CICR, cicr);
omap_dma_chan_write(c, CCR, d->ccr | CCR_ENABLE);
c->running = true;
}
static void omap_dma_drain_chan(struct omap_chan *c)
{
int i;
u32 val;
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
}
static int omap_dma_stop(struct omap_chan *c)
{
struct omap_dmadev *od = to_omap_dma_dev(c->vc.chan.device);
uint32_t val;
omap_dma_chan_write(c, CICR, 0);
omap_dma_clear_csr(c);
val = omap_dma_chan_read(c, CCR);
if (od->plat->errata & DMA_ERRATA_i541 && val & CCR_TRIGGER_SRC) {
uint32_t sysconfig;
sysconfig = omap_dma_glbl_read(od, OCP_SYSCONFIG);
val = sysconfig & ~DMA_SYSCONFIG_MIDLEMODE_MASK;
val |= DMA_SYSCONFIG_MIDLEMODE(DMA_IDLEMODE_NO_IDLE);
omap_dma_glbl_write(od, OCP_SYSCONFIG, val);
val = omap_dma_chan_read(c, CCR);
val &= ~CCR_ENABLE;
omap_dma_chan_write(c, CCR, val);
if (!(c->ccr & CCR_BUFFERING_DISABLE))
omap_dma_drain_chan(c);
omap_dma_glbl_write(od, OCP_SYSCONFIG, sysconfig);
} else {
if (!(val & CCR_ENABLE))
return -EINVAL;
val &= ~CCR_ENABLE;
omap_dma_chan_write(c, CCR, val);
if (!(c->ccr & CCR_BUFFERING_DISABLE))
omap_dma_drain_chan(c);
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
c->running = false;
return 0;
}
static void omap_dma_start_sg(struct omap_chan *c, struct omap_desc *d)
{
struct omap_sg *sg = d->sg + c->sgidx;
unsigned cxsa, cxei, cxfi;
if (d->dir == DMA_DEV_TO_MEM || d->dir == DMA_MEM_TO_MEM) {
cxsa = CDSA;
cxei = CDEI;
cxfi = CDFI;
} else {
cxsa = CSSA;
cxei = CSEI;
cxfi = CSFI;
}
omap_dma_chan_write(c, cxsa, sg->addr);
omap_dma_chan_write(c, cxei, sg->ei);
omap_dma_chan_write(c, cxfi, sg->fi);
omap_dma_chan_write(c, CEN, sg->en);
omap_dma_chan_write(c, CFN, sg->fn);
omap_dma_start(c, d);
c->sgidx++;
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
if (d->dir == DMA_DEV_TO_MEM || d->dir == DMA_MEM_TO_MEM) {
cxsa = CSSA;
cxei = CSEI;
cxfi = CSFI;
} else {
cxsa = CDSA;
cxei = CDEI;
cxfi = CDFI;
}
omap_dma_chan_write(c, cxsa, d->dev_addr);
omap_dma_chan_write(c, cxei, d->ei);
omap_dma_chan_write(c, cxfi, d->fi);
omap_dma_chan_write(c, CSDP, d->csdp);
omap_dma_chan_write(c, CLNK_CTRL, d->clnk_ctrl);
omap_dma_start_sg(c, d);
}
static void omap_dma_callback(int ch, u16 status, void *data)
{
struct omap_chan *c = data;
struct omap_desc *d;
unsigned long flags;
spin_lock_irqsave(&c->vc.lock, flags);
d = c->desc;
if (d) {
if (c->cyclic) {
vchan_cyclic_callback(&d->vd);
} else if (d->using_ll || c->sgidx == d->sglen) {
omap_dma_start_desc(c);
vchan_cookie_complete(&d->vd);
} else {
omap_dma_start_sg(c, d);
}
}
spin_unlock_irqrestore(&c->vc.lock, flags);
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
struct device *dev = od->ddev.dev;
int ret;
if (od->legacy) {
ret = omap_request_dma(c->dma_sig, "DMA engine",
omap_dma_callback, c, &c->dma_ch);
} else {
ret = omap_request_dma(c->dma_sig, "DMA engine", NULL, NULL,
&c->dma_ch);
}
dev_dbg(dev, "allocating channel %u for %u\n", c->dma_ch, c->dma_sig);
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
dev_dbg(od->ddev.dev, "freeing channel %u used for %u\n", c->dma_ch,
c->dma_sig);
c->dma_sig = 0;
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
if (!c->paused && c->running) {
uint32_t ccr = omap_dma_chan_read(c, CCR);
if (!(ccr & CCR_ENABLE))
ret = DMA_COMPLETE;
}
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
else if (d->dir == DMA_DEV_TO_MEM || d->dir == DMA_MEM_TO_MEM)
pos = omap_dma_get_dst_pos(c);
else
pos = 0;
txstate->residue = omap_dma_desc_size_pos(d, pos);
} else {
txstate->residue = 0;
}
if (ret == DMA_IN_PROGRESS && c->paused)
ret = DMA_PAUSED;
spin_unlock_irqrestore(&c->vc.lock, flags);
return ret;
}
static void omap_dma_issue_pending(struct dma_chan *chan)
{
struct omap_chan *c = to_omap_dma_chan(chan);
unsigned long flags;
spin_lock_irqsave(&c->vc.lock, flags);
if (vchan_issue_pending(&c->vc) && !c->desc)
omap_dma_start_desc(c);
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
unsigned i, es, en, frame_bytes;
bool ll_failed = false;
u32 burst;
u32 port_window, port_window_bytes;
if (dir == DMA_DEV_TO_MEM) {
dev_addr = c->cfg.src_addr;
dev_width = c->cfg.src_addr_width;
burst = c->cfg.src_maxburst;
port_window = c->cfg.src_port_window_size;
} else if (dir == DMA_MEM_TO_DEV) {
dev_addr = c->cfg.dst_addr;
dev_width = c->cfg.dst_addr_width;
burst = c->cfg.dst_maxburst;
port_window = c->cfg.dst_port_window_size;
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
if (port_window) {
burst = port_window;
port_window_bytes = port_window * es_bytes[es];
}
d = kzalloc(sizeof(*d) + sglen * sizeof(d->sg[0]), GFP_ATOMIC);
if (!d)
return NULL;
d->dir = dir;
d->dev_addr = dev_addr;
d->es = es;
d->ccr = c->ccr | CCR_SYNC_FRAME;
if (dir == DMA_DEV_TO_MEM) {
d->csdp = CSDP_DST_BURST_64 | CSDP_DST_PACKED;
d->ccr |= CCR_DST_AMODE_POSTINC;
if (port_window) {
d->ccr |= CCR_SRC_AMODE_DBLIDX;
if (port_window_bytes >= 64)
d->csdp |= CSDP_SRC_BURST_64;
else if (port_window_bytes >= 32)
d->csdp |= CSDP_SRC_BURST_32;
else if (port_window_bytes >= 16)
d->csdp |= CSDP_SRC_BURST_16;
} else {
d->ccr |= CCR_SRC_AMODE_CONSTANT;
}
} else {
d->csdp = CSDP_SRC_BURST_64 | CSDP_SRC_PACKED;
d->ccr |= CCR_SRC_AMODE_POSTINC;
if (port_window) {
d->ccr |= CCR_DST_AMODE_DBLIDX;
d->ei = 1;
d->fi = -(port_window_bytes - 1);
if (port_window_bytes >= 64)
d->csdp |= CSDP_DST_BURST_64;
else if (port_window_bytes >= 32)
d->csdp |= CSDP_DST_BURST_32;
else if (port_window_bytes >= 16)
d->csdp |= CSDP_DST_BURST_16;
} else {
d->ccr |= CCR_DST_AMODE_CONSTANT;
}
}
d->cicr = CICR_DROP_IE | CICR_BLOCK_IE;
d->csdp |= es;
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
if (port_window)
d->csdp |= CSDP_WRITE_LAST_NON_POSTED;
}
if (od->plat->errata & DMA_ERRATA_PARALLEL_CHANNELS)
d->clnk_ctrl = c->dma_ch;
en = burst;
frame_bytes = es_bytes[es] * en;
if (sglen >= 2)
d->using_ll = od->ll123_supported;
for_each_sg(sgl, sgent, sglen, i) {
struct omap_sg *osg = &d->sg[i];
osg->addr = sg_dma_address(sgent);
osg->en = en;
osg->fn = sg_dma_len(sgent) / frame_bytes;
if (port_window && dir == DMA_DEV_TO_MEM) {
osg->ei = 1;
osg->fi = -(port_window_bytes - 1);
}
if (d->using_ll) {
osg->t2_desc = dma_pool_alloc(od->desc_pool, GFP_ATOMIC,
&osg->t2_desc_paddr);
if (!osg->t2_desc) {
dev_err(chan->device->dev,
"t2_desc[%d] allocation failed\n", i);
ll_failed = true;
d->using_ll = false;
continue;
}
omap_dma_fill_type2_desc(d, i, dir, (i == sglen - 1));
}
}
d->sglen = sglen;
if (ll_failed) {
for (i = 0; i < d->sglen; i++) {
struct omap_sg *osg = &d->sg[i];
if (osg->t2_desc) {
dma_pool_free(od->desc_pool, osg->t2_desc,
osg->t2_desc_paddr);
osg->t2_desc = NULL;
}
}
}
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
if (dir == DMA_DEV_TO_MEM) {
d->ccr |= CCR_TRIGGER_SRC;
d->csdp |= CSDP_DST_PACKED;
} else {
d->csdp |= CSDP_SRC_PACKED;
}
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
static struct dma_async_tx_descriptor *omap_dma_prep_dma_memcpy(
struct dma_chan *chan, dma_addr_t dest, dma_addr_t src,
size_t len, unsigned long tx_flags)
{
struct omap_chan *c = to_omap_dma_chan(chan);
struct omap_desc *d;
uint8_t data_type;
d = kzalloc(sizeof(*d) + sizeof(d->sg[0]), GFP_ATOMIC);
if (!d)
return NULL;
data_type = __ffs((src | dest | len));
if (data_type > CSDP_DATA_TYPE_32)
data_type = CSDP_DATA_TYPE_32;
d->dir = DMA_MEM_TO_MEM;
d->dev_addr = src;
d->fi = 0;
d->es = data_type;
d->sg[0].en = len / BIT(data_type);
d->sg[0].fn = 1;
d->sg[0].addr = dest;
d->sglen = 1;
d->ccr = c->ccr;
d->ccr |= CCR_DST_AMODE_POSTINC | CCR_SRC_AMODE_POSTINC;
d->cicr = CICR_DROP_IE | CICR_FRAME_IE;
d->csdp = data_type;
if (dma_omap1()) {
d->cicr |= CICR_TOUT_IE;
d->csdp |= CSDP_DST_PORT_EMIFF | CSDP_SRC_PORT_EMIFF;
} else {
d->csdp |= CSDP_DST_PACKED | CSDP_SRC_PACKED;
d->cicr |= CICR_MISALIGNED_ERR_IE | CICR_TRANS_ERR_IE;
d->csdp |= CSDP_DST_BURST_64 | CSDP_SRC_BURST_64;
}
return vchan_tx_prep(&c->vc, &d->vd, tx_flags);
}
static struct dma_async_tx_descriptor *omap_dma_prep_dma_interleaved(
struct dma_chan *chan, struct dma_interleaved_template *xt,
unsigned long flags)
{
struct omap_chan *c = to_omap_dma_chan(chan);
struct omap_desc *d;
struct omap_sg *sg;
uint8_t data_type;
size_t src_icg, dst_icg;
if (is_slave_direction(xt->dir))
return NULL;
if (xt->frame_size != 1 || xt->numf == 0)
return NULL;
d = kzalloc(sizeof(*d) + sizeof(d->sg[0]), GFP_ATOMIC);
if (!d)
return NULL;
data_type = __ffs((xt->src_start | xt->dst_start | xt->sgl[0].size));
if (data_type > CSDP_DATA_TYPE_32)
data_type = CSDP_DATA_TYPE_32;
sg = &d->sg[0];
d->dir = DMA_MEM_TO_MEM;
d->dev_addr = xt->src_start;
d->es = data_type;
sg->en = xt->sgl[0].size / BIT(data_type);
sg->fn = xt->numf;
sg->addr = xt->dst_start;
d->sglen = 1;
d->ccr = c->ccr;
src_icg = dmaengine_get_src_icg(xt, &xt->sgl[0]);
dst_icg = dmaengine_get_dst_icg(xt, &xt->sgl[0]);
if (src_icg) {
d->ccr |= CCR_SRC_AMODE_DBLIDX;
d->ei = 1;
d->fi = src_icg;
} else if (xt->src_inc) {
d->ccr |= CCR_SRC_AMODE_POSTINC;
d->fi = 0;
} else {
dev_err(chan->device->dev,
"%s: SRC constant addressing is not supported\n",
__func__);
kfree(d);
return NULL;
}
if (dst_icg) {
d->ccr |= CCR_DST_AMODE_DBLIDX;
sg->ei = 1;
sg->fi = dst_icg;
} else if (xt->dst_inc) {
d->ccr |= CCR_DST_AMODE_POSTINC;
sg->fi = 0;
} else {
dev_err(chan->device->dev,
"%s: DST constant addressing is not supported\n",
__func__);
kfree(d);
return NULL;
}
d->cicr = CICR_DROP_IE | CICR_FRAME_IE;
d->csdp = data_type;
if (dma_omap1()) {
d->cicr |= CICR_TOUT_IE;
d->csdp |= CSDP_DST_PORT_EMIFF | CSDP_SRC_PORT_EMIFF;
} else {
d->csdp |= CSDP_DST_PACKED | CSDP_SRC_PACKED;
d->cicr |= CICR_MISALIGNED_ERR_IE | CICR_TRANS_ERR_IE;
d->csdp |= CSDP_DST_BURST_64 | CSDP_SRC_BURST_64;
}
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
unsigned long flags;
LIST_HEAD(head);
spin_lock_irqsave(&c->vc.lock, flags);
if (c->desc) {
omap_dma_desc_free(&c->desc->vd);
c->desc = NULL;
if (!c->paused)
omap_dma_stop(c);
}
c->cyclic = false;
c->paused = false;
vchan_get_all_descriptors(&c->vc, &head);
spin_unlock_irqrestore(&c->vc.lock, flags);
vchan_dma_desc_free_list(&c->vc, &head);
return 0;
}
static void omap_dma_synchronize(struct dma_chan *chan)
{
struct omap_chan *c = to_omap_dma_chan(chan);
vchan_synchronize(&c->vc);
}
static int omap_dma_pause(struct dma_chan *chan)
{
struct omap_chan *c = to_omap_dma_chan(chan);
struct omap_dmadev *od = to_omap_dma_dev(chan->device);
unsigned long flags;
int ret = -EINVAL;
bool can_pause = false;
spin_lock_irqsave(&od->irq_lock, flags);
if (!c->desc)
goto out;
if (c->cyclic)
can_pause = true;
else if (c->desc->dir == DMA_DEV_TO_MEM)
can_pause = true;
if (can_pause && !c->paused) {
ret = omap_dma_stop(c);
if (!ret)
c->paused = true;
}
out:
spin_unlock_irqrestore(&od->irq_lock, flags);
return ret;
}
static int omap_dma_resume(struct dma_chan *chan)
{
struct omap_chan *c = to_omap_dma_chan(chan);
struct omap_dmadev *od = to_omap_dma_dev(chan->device);
unsigned long flags;
int ret = -EINVAL;
spin_lock_irqsave(&od->irq_lock, flags);
if (c->paused && c->desc) {
mb();
omap_dma_chan_write(c, CLNK_CTRL, c->desc->clnk_ctrl);
omap_dma_start(c, c->desc);
c->paused = false;
ret = 0;
}
spin_unlock_irqrestore(&od->irq_lock, flags);
return ret;
}
static int omap_dma_chan_init(struct omap_dmadev *od)
{
struct omap_chan *c;
c = kzalloc(sizeof(*c), GFP_KERNEL);
if (!c)
return -ENOMEM;
c->reg_map = od->reg_map;
c->vc.desc_free = omap_dma_desc_free;
vchan_init(&c->vc, &od->ddev);
return 0;
}
static void omap_dma_free(struct omap_dmadev *od)
{
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
u32 lch_count;
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
dma_cap_set(DMA_MEMCPY, od->ddev.cap_mask);
dma_cap_set(DMA_INTERLEAVE, od->ddev.cap_mask);
od->ddev.device_alloc_chan_resources = omap_dma_alloc_chan_resources;
od->ddev.device_free_chan_resources = omap_dma_free_chan_resources;
od->ddev.device_tx_status = omap_dma_tx_status;
od->ddev.device_issue_pending = omap_dma_issue_pending;
od->ddev.device_prep_slave_sg = omap_dma_prep_slave_sg;
od->ddev.device_prep_dma_cyclic = omap_dma_prep_dma_cyclic;
od->ddev.device_prep_dma_memcpy = omap_dma_prep_dma_memcpy;
od->ddev.device_prep_interleaved_dma = omap_dma_prep_dma_interleaved;
od->ddev.device_config = omap_dma_slave_config;
od->ddev.device_pause = omap_dma_pause;
od->ddev.device_resume = omap_dma_resume;
od->ddev.device_terminate_all = omap_dma_terminate_all;
od->ddev.device_synchronize = omap_dma_synchronize;
od->ddev.src_addr_widths = OMAP_DMA_BUSWIDTHS;
od->ddev.dst_addr_widths = OMAP_DMA_BUSWIDTHS;
od->ddev.directions = BIT(DMA_DEV_TO_MEM) | BIT(DMA_MEM_TO_DEV);
od->ddev.residue_granularity = DMA_RESIDUE_GRANULARITY_BURST;
od->ddev.dev = &pdev->dev;
INIT_LIST_HEAD(&od->ddev.channels);
spin_lock_init(&od->lock);
spin_lock_init(&od->irq_lock);
od->dma_requests = OMAP_SDMA_REQUESTS;
if (pdev->dev.of_node && of_property_read_u32(pdev->dev.of_node,
"dma-requests",
&od->dma_requests)) {
dev_info(&pdev->dev,
"Missing dma-requests property, using %u.\n",
OMAP_SDMA_REQUESTS);
}
if (!pdev->dev.of_node) {
lch_count = od->plat->dma_attr->lch_count;
if (unlikely(!lch_count))
lch_count = OMAP_SDMA_CHANNELS;
} else if (of_property_read_u32(pdev->dev.of_node, "dma-channels",
&lch_count)) {
dev_info(&pdev->dev,
"Missing dma-channels property, using %u.\n",
OMAP_SDMA_CHANNELS);
lch_count = OMAP_SDMA_CHANNELS;
}
od->lch_map = devm_kcalloc(&pdev->dev, lch_count, sizeof(*od->lch_map),
GFP_KERNEL);
if (!od->lch_map)
return -ENOMEM;
for (i = 0; i < od->dma_requests; i++) {
rc = omap_dma_chan_init(od);
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
if (omap_dma_glbl_read(od, CAPS_0) & CAPS_0_SUPPORT_LL123)
od->ll123_supported = true;
od->ddev.filter.map = od->plat->slave_map;
od->ddev.filter.mapcnt = od->plat->slavecnt;
od->ddev.filter.fn = omap_dma_filter_fn;
if (od->ll123_supported) {
od->desc_pool = dma_pool_create(dev_name(&pdev->dev),
&pdev->dev,
sizeof(struct omap_type2_desc),
4, 0);
if (!od->desc_pool) {
dev_err(&pdev->dev,
"unable to allocate descriptor pool\n");
od->ll123_supported = false;
}
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
dev_info(&pdev->dev, "OMAP DMA engine driver%s\n",
od->ll123_supported ? " (LinkedList1/2/3 supported)" : "");
return rc;
}
static int omap_dma_remove(struct platform_device *pdev)
{
struct omap_dmadev *od = platform_get_drvdata(pdev);
int irq;
if (pdev->dev.of_node)
of_dma_controller_free(pdev->dev.of_node);
irq = platform_get_irq(pdev, 1);
devm_free_irq(&pdev->dev, irq, od);
dma_async_device_unregister(&od->ddev);
if (!od->legacy) {
omap_dma_glbl_write(od, IRQENABLE_L0, 0);
}
if (od->ll123_supported)
dma_pool_destroy(od->desc_pool);
omap_dma_free(od);
return 0;
}
bool omap_dma_filter_fn(struct dma_chan *chan, void *param)
{
if (chan->device->dev->driver == &omap_dma_driver.driver) {
struct omap_dmadev *od = to_omap_dma_dev(chan->device);
struct omap_chan *c = to_omap_dma_chan(chan);
unsigned req = *(unsigned *)param;
if (req <= od->dma_requests) {
c->dma_sig = req;
return true;
}
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
