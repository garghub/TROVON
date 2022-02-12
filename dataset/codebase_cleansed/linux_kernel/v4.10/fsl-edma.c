static u32 edma_readl(struct fsl_edma_engine *edma, void __iomem *addr)
{
if (edma->big_endian)
return ioread32be(addr);
else
return ioread32(addr);
}
static void edma_writeb(struct fsl_edma_engine *edma, u8 val, void __iomem *addr)
{
if (edma->big_endian)
iowrite8(val, (void __iomem *)((unsigned long)addr ^ 0x3));
else
iowrite8(val, addr);
}
static void edma_writew(struct fsl_edma_engine *edma, u16 val, void __iomem *addr)
{
if (edma->big_endian)
iowrite16be(val, (void __iomem *)((unsigned long)addr ^ 0x2));
else
iowrite16(val, addr);
}
static void edma_writel(struct fsl_edma_engine *edma, u32 val, void __iomem *addr)
{
if (edma->big_endian)
iowrite32be(val, addr);
else
iowrite32(val, addr);
}
static struct fsl_edma_chan *to_fsl_edma_chan(struct dma_chan *chan)
{
return container_of(chan, struct fsl_edma_chan, vchan.chan);
}
static struct fsl_edma_desc *to_fsl_edma_desc(struct virt_dma_desc *vd)
{
return container_of(vd, struct fsl_edma_desc, vdesc);
}
static void fsl_edma_enable_request(struct fsl_edma_chan *fsl_chan)
{
void __iomem *addr = fsl_chan->edma->membase;
u32 ch = fsl_chan->vchan.chan.chan_id;
edma_writeb(fsl_chan->edma, EDMA_SEEI_SEEI(ch), addr + EDMA_SEEI);
edma_writeb(fsl_chan->edma, ch, addr + EDMA_SERQ);
}
static void fsl_edma_disable_request(struct fsl_edma_chan *fsl_chan)
{
void __iomem *addr = fsl_chan->edma->membase;
u32 ch = fsl_chan->vchan.chan.chan_id;
edma_writeb(fsl_chan->edma, ch, addr + EDMA_CERQ);
edma_writeb(fsl_chan->edma, EDMA_CEEI_CEEI(ch), addr + EDMA_CEEI);
}
static void fsl_edma_chan_mux(struct fsl_edma_chan *fsl_chan,
unsigned int slot, bool enable)
{
u32 ch = fsl_chan->vchan.chan.chan_id;
void __iomem *muxaddr;
unsigned chans_per_mux, ch_off;
chans_per_mux = fsl_chan->edma->n_chans / DMAMUX_NR;
ch_off = fsl_chan->vchan.chan.chan_id % chans_per_mux;
muxaddr = fsl_chan->edma->muxbase[ch / chans_per_mux];
slot = EDMAMUX_CHCFG_SOURCE(slot);
if (enable)
iowrite8(EDMAMUX_CHCFG_ENBL | slot, muxaddr + ch_off);
else
iowrite8(EDMAMUX_CHCFG_DIS, muxaddr + ch_off);
}
static unsigned int fsl_edma_get_tcd_attr(enum dma_slave_buswidth addr_width)
{
switch (addr_width) {
case 1:
return EDMA_TCD_ATTR_SSIZE_8BIT | EDMA_TCD_ATTR_DSIZE_8BIT;
case 2:
return EDMA_TCD_ATTR_SSIZE_16BIT | EDMA_TCD_ATTR_DSIZE_16BIT;
case 4:
return EDMA_TCD_ATTR_SSIZE_32BIT | EDMA_TCD_ATTR_DSIZE_32BIT;
case 8:
return EDMA_TCD_ATTR_SSIZE_64BIT | EDMA_TCD_ATTR_DSIZE_64BIT;
default:
return EDMA_TCD_ATTR_SSIZE_32BIT | EDMA_TCD_ATTR_DSIZE_32BIT;
}
}
static void fsl_edma_free_desc(struct virt_dma_desc *vdesc)
{
struct fsl_edma_desc *fsl_desc;
int i;
fsl_desc = to_fsl_edma_desc(vdesc);
for (i = 0; i < fsl_desc->n_tcds; i++)
dma_pool_free(fsl_desc->echan->tcd_pool, fsl_desc->tcd[i].vtcd,
fsl_desc->tcd[i].ptcd);
kfree(fsl_desc);
}
static int fsl_edma_terminate_all(struct dma_chan *chan)
{
struct fsl_edma_chan *fsl_chan = to_fsl_edma_chan(chan);
unsigned long flags;
LIST_HEAD(head);
spin_lock_irqsave(&fsl_chan->vchan.lock, flags);
fsl_edma_disable_request(fsl_chan);
fsl_chan->edesc = NULL;
fsl_chan->idle = true;
vchan_get_all_descriptors(&fsl_chan->vchan, &head);
spin_unlock_irqrestore(&fsl_chan->vchan.lock, flags);
vchan_dma_desc_free_list(&fsl_chan->vchan, &head);
return 0;
}
static int fsl_edma_pause(struct dma_chan *chan)
{
struct fsl_edma_chan *fsl_chan = to_fsl_edma_chan(chan);
unsigned long flags;
spin_lock_irqsave(&fsl_chan->vchan.lock, flags);
if (fsl_chan->edesc) {
fsl_edma_disable_request(fsl_chan);
fsl_chan->status = DMA_PAUSED;
fsl_chan->idle = true;
}
spin_unlock_irqrestore(&fsl_chan->vchan.lock, flags);
return 0;
}
static int fsl_edma_resume(struct dma_chan *chan)
{
struct fsl_edma_chan *fsl_chan = to_fsl_edma_chan(chan);
unsigned long flags;
spin_lock_irqsave(&fsl_chan->vchan.lock, flags);
if (fsl_chan->edesc) {
fsl_edma_enable_request(fsl_chan);
fsl_chan->status = DMA_IN_PROGRESS;
fsl_chan->idle = false;
}
spin_unlock_irqrestore(&fsl_chan->vchan.lock, flags);
return 0;
}
static int fsl_edma_slave_config(struct dma_chan *chan,
struct dma_slave_config *cfg)
{
struct fsl_edma_chan *fsl_chan = to_fsl_edma_chan(chan);
fsl_chan->fsc.dir = cfg->direction;
if (cfg->direction == DMA_DEV_TO_MEM) {
fsl_chan->fsc.dev_addr = cfg->src_addr;
fsl_chan->fsc.addr_width = cfg->src_addr_width;
fsl_chan->fsc.burst = cfg->src_maxburst;
fsl_chan->fsc.attr = fsl_edma_get_tcd_attr(cfg->src_addr_width);
} else if (cfg->direction == DMA_MEM_TO_DEV) {
fsl_chan->fsc.dev_addr = cfg->dst_addr;
fsl_chan->fsc.addr_width = cfg->dst_addr_width;
fsl_chan->fsc.burst = cfg->dst_maxburst;
fsl_chan->fsc.attr = fsl_edma_get_tcd_attr(cfg->dst_addr_width);
} else {
return -EINVAL;
}
return 0;
}
static size_t fsl_edma_desc_residue(struct fsl_edma_chan *fsl_chan,
struct virt_dma_desc *vdesc, bool in_progress)
{
struct fsl_edma_desc *edesc = fsl_chan->edesc;
void __iomem *addr = fsl_chan->edma->membase;
u32 ch = fsl_chan->vchan.chan.chan_id;
enum dma_transfer_direction dir = fsl_chan->fsc.dir;
dma_addr_t cur_addr, dma_addr;
size_t len, size;
int i;
for (len = i = 0; i < fsl_chan->edesc->n_tcds; i++)
len += le32_to_cpu(edesc->tcd[i].vtcd->nbytes)
* le16_to_cpu(edesc->tcd[i].vtcd->biter);
if (!in_progress)
return len;
if (dir == DMA_MEM_TO_DEV)
cur_addr = edma_readl(fsl_chan->edma, addr + EDMA_TCD_SADDR(ch));
else
cur_addr = edma_readl(fsl_chan->edma, addr + EDMA_TCD_DADDR(ch));
for (i = 0; i < fsl_chan->edesc->n_tcds; i++) {
size = le32_to_cpu(edesc->tcd[i].vtcd->nbytes)
* le16_to_cpu(edesc->tcd[i].vtcd->biter);
if (dir == DMA_MEM_TO_DEV)
dma_addr = le32_to_cpu(edesc->tcd[i].vtcd->saddr);
else
dma_addr = le32_to_cpu(edesc->tcd[i].vtcd->daddr);
len -= size;
if (cur_addr >= dma_addr && cur_addr < dma_addr + size) {
len += dma_addr + size - cur_addr;
break;
}
}
return len;
}
static enum dma_status fsl_edma_tx_status(struct dma_chan *chan,
dma_cookie_t cookie, struct dma_tx_state *txstate)
{
struct fsl_edma_chan *fsl_chan = to_fsl_edma_chan(chan);
struct virt_dma_desc *vdesc;
enum dma_status status;
unsigned long flags;
status = dma_cookie_status(chan, cookie, txstate);
if (status == DMA_COMPLETE)
return status;
if (!txstate)
return fsl_chan->status;
spin_lock_irqsave(&fsl_chan->vchan.lock, flags);
vdesc = vchan_find_desc(&fsl_chan->vchan, cookie);
if (fsl_chan->edesc && cookie == fsl_chan->edesc->vdesc.tx.cookie)
txstate->residue = fsl_edma_desc_residue(fsl_chan, vdesc, true);
else if (vdesc)
txstate->residue = fsl_edma_desc_residue(fsl_chan, vdesc, false);
else
txstate->residue = 0;
spin_unlock_irqrestore(&fsl_chan->vchan.lock, flags);
return fsl_chan->status;
}
static void fsl_edma_set_tcd_regs(struct fsl_edma_chan *fsl_chan,
struct fsl_edma_hw_tcd *tcd)
{
struct fsl_edma_engine *edma = fsl_chan->edma;
void __iomem *addr = fsl_chan->edma->membase;
u32 ch = fsl_chan->vchan.chan.chan_id;
edma_writew(edma, 0, addr + EDMA_TCD_CSR(ch));
edma_writel(edma, le32_to_cpu(tcd->saddr), addr + EDMA_TCD_SADDR(ch));
edma_writel(edma, le32_to_cpu(tcd->daddr), addr + EDMA_TCD_DADDR(ch));
edma_writew(edma, le16_to_cpu(tcd->attr), addr + EDMA_TCD_ATTR(ch));
edma_writew(edma, le16_to_cpu(tcd->soff), addr + EDMA_TCD_SOFF(ch));
edma_writel(edma, le32_to_cpu(tcd->nbytes), addr + EDMA_TCD_NBYTES(ch));
edma_writel(edma, le32_to_cpu(tcd->slast), addr + EDMA_TCD_SLAST(ch));
edma_writew(edma, le16_to_cpu(tcd->citer), addr + EDMA_TCD_CITER(ch));
edma_writew(edma, le16_to_cpu(tcd->biter), addr + EDMA_TCD_BITER(ch));
edma_writew(edma, le16_to_cpu(tcd->doff), addr + EDMA_TCD_DOFF(ch));
edma_writel(edma, le32_to_cpu(tcd->dlast_sga), addr + EDMA_TCD_DLAST_SGA(ch));
edma_writew(edma, le16_to_cpu(tcd->csr), addr + EDMA_TCD_CSR(ch));
}
static inline
void fsl_edma_fill_tcd(struct fsl_edma_hw_tcd *tcd, u32 src, u32 dst,
u16 attr, u16 soff, u32 nbytes, u32 slast, u16 citer,
u16 biter, u16 doff, u32 dlast_sga, bool major_int,
bool disable_req, bool enable_sg)
{
u16 csr = 0;
tcd->saddr = cpu_to_le32(src);
tcd->daddr = cpu_to_le32(dst);
tcd->attr = cpu_to_le16(attr);
tcd->soff = cpu_to_le16(EDMA_TCD_SOFF_SOFF(soff));
tcd->nbytes = cpu_to_le32(EDMA_TCD_NBYTES_NBYTES(nbytes));
tcd->slast = cpu_to_le32(EDMA_TCD_SLAST_SLAST(slast));
tcd->citer = cpu_to_le16(EDMA_TCD_CITER_CITER(citer));
tcd->doff = cpu_to_le16(EDMA_TCD_DOFF_DOFF(doff));
tcd->dlast_sga = cpu_to_le32(EDMA_TCD_DLAST_SGA_DLAST_SGA(dlast_sga));
tcd->biter = cpu_to_le16(EDMA_TCD_BITER_BITER(biter));
if (major_int)
csr |= EDMA_TCD_CSR_INT_MAJOR;
if (disable_req)
csr |= EDMA_TCD_CSR_D_REQ;
if (enable_sg)
csr |= EDMA_TCD_CSR_E_SG;
tcd->csr = cpu_to_le16(csr);
}
static struct fsl_edma_desc *fsl_edma_alloc_desc(struct fsl_edma_chan *fsl_chan,
int sg_len)
{
struct fsl_edma_desc *fsl_desc;
int i;
fsl_desc = kzalloc(sizeof(*fsl_desc) + sizeof(struct fsl_edma_sw_tcd) * sg_len,
GFP_NOWAIT);
if (!fsl_desc)
return NULL;
fsl_desc->echan = fsl_chan;
fsl_desc->n_tcds = sg_len;
for (i = 0; i < sg_len; i++) {
fsl_desc->tcd[i].vtcd = dma_pool_alloc(fsl_chan->tcd_pool,
GFP_NOWAIT, &fsl_desc->tcd[i].ptcd);
if (!fsl_desc->tcd[i].vtcd)
goto err;
}
return fsl_desc;
err:
while (--i >= 0)
dma_pool_free(fsl_chan->tcd_pool, fsl_desc->tcd[i].vtcd,
fsl_desc->tcd[i].ptcd);
kfree(fsl_desc);
return NULL;
}
static struct dma_async_tx_descriptor *fsl_edma_prep_dma_cyclic(
struct dma_chan *chan, dma_addr_t dma_addr, size_t buf_len,
size_t period_len, enum dma_transfer_direction direction,
unsigned long flags)
{
struct fsl_edma_chan *fsl_chan = to_fsl_edma_chan(chan);
struct fsl_edma_desc *fsl_desc;
dma_addr_t dma_buf_next;
int sg_len, i;
u32 src_addr, dst_addr, last_sg, nbytes;
u16 soff, doff, iter;
if (!is_slave_direction(fsl_chan->fsc.dir))
return NULL;
sg_len = buf_len / period_len;
fsl_desc = fsl_edma_alloc_desc(fsl_chan, sg_len);
if (!fsl_desc)
return NULL;
fsl_desc->iscyclic = true;
dma_buf_next = dma_addr;
nbytes = fsl_chan->fsc.addr_width * fsl_chan->fsc.burst;
iter = period_len / nbytes;
for (i = 0; i < sg_len; i++) {
if (dma_buf_next >= dma_addr + buf_len)
dma_buf_next = dma_addr;
last_sg = fsl_desc->tcd[(i + 1) % sg_len].ptcd;
if (fsl_chan->fsc.dir == DMA_MEM_TO_DEV) {
src_addr = dma_buf_next;
dst_addr = fsl_chan->fsc.dev_addr;
soff = fsl_chan->fsc.addr_width;
doff = 0;
} else {
src_addr = fsl_chan->fsc.dev_addr;
dst_addr = dma_buf_next;
soff = 0;
doff = fsl_chan->fsc.addr_width;
}
fsl_edma_fill_tcd(fsl_desc->tcd[i].vtcd, src_addr, dst_addr,
fsl_chan->fsc.attr, soff, nbytes, 0, iter,
iter, doff, last_sg, true, false, true);
dma_buf_next += period_len;
}
return vchan_tx_prep(&fsl_chan->vchan, &fsl_desc->vdesc, flags);
}
static struct dma_async_tx_descriptor *fsl_edma_prep_slave_sg(
struct dma_chan *chan, struct scatterlist *sgl,
unsigned int sg_len, enum dma_transfer_direction direction,
unsigned long flags, void *context)
{
struct fsl_edma_chan *fsl_chan = to_fsl_edma_chan(chan);
struct fsl_edma_desc *fsl_desc;
struct scatterlist *sg;
u32 src_addr, dst_addr, last_sg, nbytes;
u16 soff, doff, iter;
int i;
if (!is_slave_direction(fsl_chan->fsc.dir))
return NULL;
fsl_desc = fsl_edma_alloc_desc(fsl_chan, sg_len);
if (!fsl_desc)
return NULL;
fsl_desc->iscyclic = false;
nbytes = fsl_chan->fsc.addr_width * fsl_chan->fsc.burst;
for_each_sg(sgl, sg, sg_len, i) {
last_sg = fsl_desc->tcd[(i + 1) % sg_len].ptcd;
if (fsl_chan->fsc.dir == DMA_MEM_TO_DEV) {
src_addr = sg_dma_address(sg);
dst_addr = fsl_chan->fsc.dev_addr;
soff = fsl_chan->fsc.addr_width;
doff = 0;
} else {
src_addr = fsl_chan->fsc.dev_addr;
dst_addr = sg_dma_address(sg);
soff = 0;
doff = fsl_chan->fsc.addr_width;
}
iter = sg_dma_len(sg) / nbytes;
if (i < sg_len - 1) {
last_sg = fsl_desc->tcd[(i + 1)].ptcd;
fsl_edma_fill_tcd(fsl_desc->tcd[i].vtcd, src_addr,
dst_addr, fsl_chan->fsc.attr, soff,
nbytes, 0, iter, iter, doff, last_sg,
false, false, true);
} else {
last_sg = 0;
fsl_edma_fill_tcd(fsl_desc->tcd[i].vtcd, src_addr,
dst_addr, fsl_chan->fsc.attr, soff,
nbytes, 0, iter, iter, doff, last_sg,
true, true, false);
}
}
return vchan_tx_prep(&fsl_chan->vchan, &fsl_desc->vdesc, flags);
}
static void fsl_edma_xfer_desc(struct fsl_edma_chan *fsl_chan)
{
struct virt_dma_desc *vdesc;
vdesc = vchan_next_desc(&fsl_chan->vchan);
if (!vdesc)
return;
fsl_chan->edesc = to_fsl_edma_desc(vdesc);
fsl_edma_set_tcd_regs(fsl_chan, fsl_chan->edesc->tcd[0].vtcd);
fsl_edma_enable_request(fsl_chan);
fsl_chan->status = DMA_IN_PROGRESS;
fsl_chan->idle = false;
}
static irqreturn_t fsl_edma_tx_handler(int irq, void *dev_id)
{
struct fsl_edma_engine *fsl_edma = dev_id;
unsigned int intr, ch;
void __iomem *base_addr;
struct fsl_edma_chan *fsl_chan;
base_addr = fsl_edma->membase;
intr = edma_readl(fsl_edma, base_addr + EDMA_INTR);
if (!intr)
return IRQ_NONE;
for (ch = 0; ch < fsl_edma->n_chans; ch++) {
if (intr & (0x1 << ch)) {
edma_writeb(fsl_edma, EDMA_CINT_CINT(ch),
base_addr + EDMA_CINT);
fsl_chan = &fsl_edma->chans[ch];
spin_lock(&fsl_chan->vchan.lock);
if (!fsl_chan->edesc->iscyclic) {
list_del(&fsl_chan->edesc->vdesc.node);
vchan_cookie_complete(&fsl_chan->edesc->vdesc);
fsl_chan->edesc = NULL;
fsl_chan->status = DMA_COMPLETE;
fsl_chan->idle = true;
} else {
vchan_cyclic_callback(&fsl_chan->edesc->vdesc);
}
if (!fsl_chan->edesc)
fsl_edma_xfer_desc(fsl_chan);
spin_unlock(&fsl_chan->vchan.lock);
}
}
return IRQ_HANDLED;
}
static irqreturn_t fsl_edma_err_handler(int irq, void *dev_id)
{
struct fsl_edma_engine *fsl_edma = dev_id;
unsigned int err, ch;
err = edma_readl(fsl_edma, fsl_edma->membase + EDMA_ERR);
if (!err)
return IRQ_NONE;
for (ch = 0; ch < fsl_edma->n_chans; ch++) {
if (err & (0x1 << ch)) {
fsl_edma_disable_request(&fsl_edma->chans[ch]);
edma_writeb(fsl_edma, EDMA_CERR_CERR(ch),
fsl_edma->membase + EDMA_CERR);
fsl_edma->chans[ch].status = DMA_ERROR;
fsl_edma->chans[ch].idle = true;
}
}
return IRQ_HANDLED;
}
static irqreturn_t fsl_edma_irq_handler(int irq, void *dev_id)
{
if (fsl_edma_tx_handler(irq, dev_id) == IRQ_HANDLED)
return IRQ_HANDLED;
return fsl_edma_err_handler(irq, dev_id);
}
static void fsl_edma_issue_pending(struct dma_chan *chan)
{
struct fsl_edma_chan *fsl_chan = to_fsl_edma_chan(chan);
unsigned long flags;
spin_lock_irqsave(&fsl_chan->vchan.lock, flags);
if (unlikely(fsl_chan->pm_state != RUNNING)) {
spin_unlock_irqrestore(&fsl_chan->vchan.lock, flags);
return;
}
if (vchan_issue_pending(&fsl_chan->vchan) && !fsl_chan->edesc)
fsl_edma_xfer_desc(fsl_chan);
spin_unlock_irqrestore(&fsl_chan->vchan.lock, flags);
}
static struct dma_chan *fsl_edma_xlate(struct of_phandle_args *dma_spec,
struct of_dma *ofdma)
{
struct fsl_edma_engine *fsl_edma = ofdma->of_dma_data;
struct dma_chan *chan, *_chan;
struct fsl_edma_chan *fsl_chan;
unsigned long chans_per_mux = fsl_edma->n_chans / DMAMUX_NR;
if (dma_spec->args_count != 2)
return NULL;
mutex_lock(&fsl_edma->fsl_edma_mutex);
list_for_each_entry_safe(chan, _chan, &fsl_edma->dma_dev.channels, device_node) {
if (chan->client_count)
continue;
if ((chan->chan_id / chans_per_mux) == dma_spec->args[0]) {
chan = dma_get_slave_channel(chan);
if (chan) {
chan->device->privatecnt++;
fsl_chan = to_fsl_edma_chan(chan);
fsl_chan->slave_id = dma_spec->args[1];
fsl_edma_chan_mux(fsl_chan, fsl_chan->slave_id,
true);
mutex_unlock(&fsl_edma->fsl_edma_mutex);
return chan;
}
}
}
mutex_unlock(&fsl_edma->fsl_edma_mutex);
return NULL;
}
static int fsl_edma_alloc_chan_resources(struct dma_chan *chan)
{
struct fsl_edma_chan *fsl_chan = to_fsl_edma_chan(chan);
fsl_chan->tcd_pool = dma_pool_create("tcd_pool", chan->device->dev,
sizeof(struct fsl_edma_hw_tcd),
32, 0);
return 0;
}
static void fsl_edma_free_chan_resources(struct dma_chan *chan)
{
struct fsl_edma_chan *fsl_chan = to_fsl_edma_chan(chan);
unsigned long flags;
LIST_HEAD(head);
spin_lock_irqsave(&fsl_chan->vchan.lock, flags);
fsl_edma_disable_request(fsl_chan);
fsl_edma_chan_mux(fsl_chan, 0, false);
fsl_chan->edesc = NULL;
vchan_get_all_descriptors(&fsl_chan->vchan, &head);
spin_unlock_irqrestore(&fsl_chan->vchan.lock, flags);
vchan_dma_desc_free_list(&fsl_chan->vchan, &head);
dma_pool_destroy(fsl_chan->tcd_pool);
fsl_chan->tcd_pool = NULL;
}
static int
fsl_edma_irq_init(struct platform_device *pdev, struct fsl_edma_engine *fsl_edma)
{
int ret;
fsl_edma->txirq = platform_get_irq_byname(pdev, "edma-tx");
if (fsl_edma->txirq < 0) {
dev_err(&pdev->dev, "Can't get edma-tx irq.\n");
return fsl_edma->txirq;
}
fsl_edma->errirq = platform_get_irq_byname(pdev, "edma-err");
if (fsl_edma->errirq < 0) {
dev_err(&pdev->dev, "Can't get edma-err irq.\n");
return fsl_edma->errirq;
}
if (fsl_edma->txirq == fsl_edma->errirq) {
ret = devm_request_irq(&pdev->dev, fsl_edma->txirq,
fsl_edma_irq_handler, 0, "eDMA", fsl_edma);
if (ret) {
dev_err(&pdev->dev, "Can't register eDMA IRQ.\n");
return ret;
}
} else {
ret = devm_request_irq(&pdev->dev, fsl_edma->txirq,
fsl_edma_tx_handler, 0, "eDMA tx", fsl_edma);
if (ret) {
dev_err(&pdev->dev, "Can't register eDMA tx IRQ.\n");
return ret;
}
ret = devm_request_irq(&pdev->dev, fsl_edma->errirq,
fsl_edma_err_handler, 0, "eDMA err", fsl_edma);
if (ret) {
dev_err(&pdev->dev, "Can't register eDMA err IRQ.\n");
return ret;
}
}
return 0;
}
static void fsl_edma_irq_exit(
struct platform_device *pdev, struct fsl_edma_engine *fsl_edma)
{
if (fsl_edma->txirq == fsl_edma->errirq) {
devm_free_irq(&pdev->dev, fsl_edma->txirq, fsl_edma);
} else {
devm_free_irq(&pdev->dev, fsl_edma->txirq, fsl_edma);
devm_free_irq(&pdev->dev, fsl_edma->errirq, fsl_edma);
}
}
static void fsl_disable_clocks(struct fsl_edma_engine *fsl_edma)
{
int i;
for (i = 0; i < DMAMUX_NR; i++)
clk_disable_unprepare(fsl_edma->muxclk[i]);
}
static int fsl_edma_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct fsl_edma_engine *fsl_edma;
struct fsl_edma_chan *fsl_chan;
struct resource *res;
int len, chans;
int ret, i;
ret = of_property_read_u32(np, "dma-channels", &chans);
if (ret) {
dev_err(&pdev->dev, "Can't get dma-channels.\n");
return ret;
}
len = sizeof(*fsl_edma) + sizeof(*fsl_chan) * chans;
fsl_edma = devm_kzalloc(&pdev->dev, len, GFP_KERNEL);
if (!fsl_edma)
return -ENOMEM;
fsl_edma->n_chans = chans;
mutex_init(&fsl_edma->fsl_edma_mutex);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
fsl_edma->membase = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(fsl_edma->membase))
return PTR_ERR(fsl_edma->membase);
for (i = 0; i < DMAMUX_NR; i++) {
char clkname[32];
res = platform_get_resource(pdev, IORESOURCE_MEM, 1 + i);
fsl_edma->muxbase[i] = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(fsl_edma->muxbase[i]))
return PTR_ERR(fsl_edma->muxbase[i]);
sprintf(clkname, "dmamux%d", i);
fsl_edma->muxclk[i] = devm_clk_get(&pdev->dev, clkname);
if (IS_ERR(fsl_edma->muxclk[i])) {
dev_err(&pdev->dev, "Missing DMAMUX block clock.\n");
return PTR_ERR(fsl_edma->muxclk[i]);
}
ret = clk_prepare_enable(fsl_edma->muxclk[i]);
if (ret) {
for (; i >= 0; i--)
clk_disable_unprepare(fsl_edma->muxclk[i]);
dev_err(&pdev->dev, "DMAMUX clk block failed.\n");
return ret;
}
}
fsl_edma->big_endian = of_property_read_bool(np, "big-endian");
INIT_LIST_HEAD(&fsl_edma->dma_dev.channels);
for (i = 0; i < fsl_edma->n_chans; i++) {
struct fsl_edma_chan *fsl_chan = &fsl_edma->chans[i];
fsl_chan->edma = fsl_edma;
fsl_chan->pm_state = RUNNING;
fsl_chan->slave_id = 0;
fsl_chan->idle = true;
fsl_chan->vchan.desc_free = fsl_edma_free_desc;
vchan_init(&fsl_chan->vchan, &fsl_edma->dma_dev);
edma_writew(fsl_edma, 0x0, fsl_edma->membase + EDMA_TCD_CSR(i));
fsl_edma_chan_mux(fsl_chan, 0, false);
}
edma_writel(fsl_edma, ~0, fsl_edma->membase + EDMA_INTR);
ret = fsl_edma_irq_init(pdev, fsl_edma);
if (ret)
return ret;
dma_cap_set(DMA_PRIVATE, fsl_edma->dma_dev.cap_mask);
dma_cap_set(DMA_SLAVE, fsl_edma->dma_dev.cap_mask);
dma_cap_set(DMA_CYCLIC, fsl_edma->dma_dev.cap_mask);
fsl_edma->dma_dev.dev = &pdev->dev;
fsl_edma->dma_dev.device_alloc_chan_resources
= fsl_edma_alloc_chan_resources;
fsl_edma->dma_dev.device_free_chan_resources
= fsl_edma_free_chan_resources;
fsl_edma->dma_dev.device_tx_status = fsl_edma_tx_status;
fsl_edma->dma_dev.device_prep_slave_sg = fsl_edma_prep_slave_sg;
fsl_edma->dma_dev.device_prep_dma_cyclic = fsl_edma_prep_dma_cyclic;
fsl_edma->dma_dev.device_config = fsl_edma_slave_config;
fsl_edma->dma_dev.device_pause = fsl_edma_pause;
fsl_edma->dma_dev.device_resume = fsl_edma_resume;
fsl_edma->dma_dev.device_terminate_all = fsl_edma_terminate_all;
fsl_edma->dma_dev.device_issue_pending = fsl_edma_issue_pending;
fsl_edma->dma_dev.src_addr_widths = FSL_EDMA_BUSWIDTHS;
fsl_edma->dma_dev.dst_addr_widths = FSL_EDMA_BUSWIDTHS;
fsl_edma->dma_dev.directions = BIT(DMA_DEV_TO_MEM) | BIT(DMA_MEM_TO_DEV);
platform_set_drvdata(pdev, fsl_edma);
ret = dma_async_device_register(&fsl_edma->dma_dev);
if (ret) {
dev_err(&pdev->dev,
"Can't register Freescale eDMA engine. (%d)\n", ret);
fsl_disable_clocks(fsl_edma);
return ret;
}
ret = of_dma_controller_register(np, fsl_edma_xlate, fsl_edma);
if (ret) {
dev_err(&pdev->dev,
"Can't register Freescale eDMA of_dma. (%d)\n", ret);
dma_async_device_unregister(&fsl_edma->dma_dev);
fsl_disable_clocks(fsl_edma);
return ret;
}
edma_writel(fsl_edma, EDMA_CR_ERGA | EDMA_CR_ERCA, fsl_edma->membase + EDMA_CR);
return 0;
}
static void fsl_edma_cleanup_vchan(struct dma_device *dmadev)
{
struct fsl_edma_chan *chan, *_chan;
list_for_each_entry_safe(chan, _chan,
&dmadev->channels, vchan.chan.device_node) {
list_del(&chan->vchan.chan.device_node);
tasklet_kill(&chan->vchan.task);
}
}
static int fsl_edma_remove(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct fsl_edma_engine *fsl_edma = platform_get_drvdata(pdev);
fsl_edma_irq_exit(pdev, fsl_edma);
fsl_edma_cleanup_vchan(&fsl_edma->dma_dev);
of_dma_controller_free(np);
dma_async_device_unregister(&fsl_edma->dma_dev);
fsl_disable_clocks(fsl_edma);
return 0;
}
static int fsl_edma_suspend_late(struct device *dev)
{
struct fsl_edma_engine *fsl_edma = dev_get_drvdata(dev);
struct fsl_edma_chan *fsl_chan;
unsigned long flags;
int i;
for (i = 0; i < fsl_edma->n_chans; i++) {
fsl_chan = &fsl_edma->chans[i];
spin_lock_irqsave(&fsl_chan->vchan.lock, flags);
if (unlikely(!fsl_chan->idle)) {
dev_warn(dev, "WARN: There is non-idle channel.");
fsl_edma_disable_request(fsl_chan);
fsl_edma_chan_mux(fsl_chan, 0, false);
}
fsl_chan->pm_state = SUSPENDED;
spin_unlock_irqrestore(&fsl_chan->vchan.lock, flags);
}
return 0;
}
static int fsl_edma_resume_early(struct device *dev)
{
struct fsl_edma_engine *fsl_edma = dev_get_drvdata(dev);
struct fsl_edma_chan *fsl_chan;
int i;
for (i = 0; i < fsl_edma->n_chans; i++) {
fsl_chan = &fsl_edma->chans[i];
fsl_chan->pm_state = RUNNING;
edma_writew(fsl_edma, 0x0, fsl_edma->membase + EDMA_TCD_CSR(i));
if (fsl_chan->slave_id != 0)
fsl_edma_chan_mux(fsl_chan, fsl_chan->slave_id, true);
}
edma_writel(fsl_edma, EDMA_CR_ERGA | EDMA_CR_ERCA,
fsl_edma->membase + EDMA_CR);
return 0;
}
static int __init fsl_edma_init(void)
{
return platform_driver_register(&fsl_edma_driver);
}
static void __exit fsl_edma_exit(void)
{
platform_driver_unregister(&fsl_edma_driver);
}
