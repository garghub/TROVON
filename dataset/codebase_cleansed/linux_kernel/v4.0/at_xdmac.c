static inline void __iomem *at_xdmac_chan_reg_base(struct at_xdmac *atxdmac, unsigned int chan_nb)
{
return atxdmac->regs + (AT_XDMAC_CHAN_REG_BASE + chan_nb * 0x40);
}
static inline struct at_xdmac_chan *to_at_xdmac_chan(struct dma_chan *dchan)
{
return container_of(dchan, struct at_xdmac_chan, chan);
}
static struct device *chan2dev(struct dma_chan *chan)
{
return &chan->dev->device;
}
static inline struct at_xdmac *to_at_xdmac(struct dma_device *ddev)
{
return container_of(ddev, struct at_xdmac, dma);
}
static inline struct at_xdmac_desc *txd_to_at_desc(struct dma_async_tx_descriptor *txd)
{
return container_of(txd, struct at_xdmac_desc, tx_dma_desc);
}
static inline int at_xdmac_chan_is_cyclic(struct at_xdmac_chan *atchan)
{
return test_bit(AT_XDMAC_CHAN_IS_CYCLIC, &atchan->status);
}
static inline int at_xdmac_chan_is_paused(struct at_xdmac_chan *atchan)
{
return test_bit(AT_XDMAC_CHAN_IS_PAUSED, &atchan->status);
}
static inline int at_xdmac_csize(u32 maxburst)
{
int csize;
csize = ffs(maxburst) - 1;
if (csize > 4)
csize = -EINVAL;
return csize;
}
static inline u8 at_xdmac_get_dwidth(u32 cfg)
{
return (cfg & AT_XDMAC_CC_DWIDTH_MASK) >> AT_XDMAC_CC_DWIDTH_OFFSET;
}
static bool at_xdmac_chan_is_enabled(struct at_xdmac_chan *atchan)
{
return at_xdmac_chan_read(atchan, AT_XDMAC_GS) & atchan->mask;
}
static void at_xdmac_off(struct at_xdmac *atxdmac)
{
at_xdmac_write(atxdmac, AT_XDMAC_GD, -1L);
while (at_xdmac_read(atxdmac, AT_XDMAC_GS))
cpu_relax();
at_xdmac_write(atxdmac, AT_XDMAC_GID, -1L);
}
static void at_xdmac_start_xfer(struct at_xdmac_chan *atchan,
struct at_xdmac_desc *first)
{
struct at_xdmac *atxdmac = to_at_xdmac(atchan->chan.device);
u32 reg;
dev_vdbg(chan2dev(&atchan->chan), "%s: desc 0x%p\n", __func__, first);
if (at_xdmac_chan_is_enabled(atchan))
return;
first->active_xfer = true;
reg = AT_XDMAC_CNDA_NDA(first->tx_dma_desc.phys)
| AT_XDMAC_CNDA_NDAIF(atchan->memif);
at_xdmac_chan_write(atchan, AT_XDMAC_CNDA, reg);
if (at_xdmac_chan_is_cyclic(atchan)) {
reg = AT_XDMAC_CNDC_NDVIEW_NDV1;
at_xdmac_chan_write(atchan, AT_XDMAC_CC, first->lld.mbr_cfg);
} else {
reg = AT_XDMAC_CNDC_NDVIEW_NDV2;
}
reg |= AT_XDMAC_CNDC_NDDUP
| AT_XDMAC_CNDC_NDSUP
| AT_XDMAC_CNDC_NDE;
at_xdmac_chan_write(atchan, AT_XDMAC_CNDC, reg);
dev_vdbg(chan2dev(&atchan->chan),
"%s: CC=0x%08x CNDA=0x%08x, CNDC=0x%08x, CSA=0x%08x, CDA=0x%08x, CUBC=0x%08x\n",
__func__, at_xdmac_chan_read(atchan, AT_XDMAC_CC),
at_xdmac_chan_read(atchan, AT_XDMAC_CNDA),
at_xdmac_chan_read(atchan, AT_XDMAC_CNDC),
at_xdmac_chan_read(atchan, AT_XDMAC_CSA),
at_xdmac_chan_read(atchan, AT_XDMAC_CDA),
at_xdmac_chan_read(atchan, AT_XDMAC_CUBC));
at_xdmac_chan_write(atchan, AT_XDMAC_CID, 0xffffffff);
reg = AT_XDMAC_CIE_RBEIE | AT_XDMAC_CIE_WBEIE | AT_XDMAC_CIE_ROIE;
if (at_xdmac_chan_is_cyclic(atchan))
at_xdmac_chan_write(atchan, AT_XDMAC_CIE,
reg | AT_XDMAC_CIE_BIE);
else
at_xdmac_chan_write(atchan, AT_XDMAC_CIE,
reg | AT_XDMAC_CIE_LIE);
at_xdmac_write(atxdmac, AT_XDMAC_GIE, atchan->mask);
dev_vdbg(chan2dev(&atchan->chan),
"%s: enable channel (0x%08x)\n", __func__, atchan->mask);
wmb();
at_xdmac_write(atxdmac, AT_XDMAC_GE, atchan->mask);
dev_vdbg(chan2dev(&atchan->chan),
"%s: CC=0x%08x CNDA=0x%08x, CNDC=0x%08x, CSA=0x%08x, CDA=0x%08x, CUBC=0x%08x\n",
__func__, at_xdmac_chan_read(atchan, AT_XDMAC_CC),
at_xdmac_chan_read(atchan, AT_XDMAC_CNDA),
at_xdmac_chan_read(atchan, AT_XDMAC_CNDC),
at_xdmac_chan_read(atchan, AT_XDMAC_CSA),
at_xdmac_chan_read(atchan, AT_XDMAC_CDA),
at_xdmac_chan_read(atchan, AT_XDMAC_CUBC));
}
static dma_cookie_t at_xdmac_tx_submit(struct dma_async_tx_descriptor *tx)
{
struct at_xdmac_desc *desc = txd_to_at_desc(tx);
struct at_xdmac_chan *atchan = to_at_xdmac_chan(tx->chan);
dma_cookie_t cookie;
spin_lock_bh(&atchan->lock);
cookie = dma_cookie_assign(tx);
dev_vdbg(chan2dev(tx->chan), "%s: atchan 0x%p, add desc 0x%p to xfers_list\n",
__func__, atchan, desc);
list_add_tail(&desc->xfer_node, &atchan->xfers_list);
if (list_is_singular(&atchan->xfers_list))
at_xdmac_start_xfer(atchan, desc);
spin_unlock_bh(&atchan->lock);
return cookie;
}
static struct at_xdmac_desc *at_xdmac_alloc_desc(struct dma_chan *chan,
gfp_t gfp_flags)
{
struct at_xdmac_desc *desc;
struct at_xdmac *atxdmac = to_at_xdmac(chan->device);
dma_addr_t phys;
desc = dma_pool_alloc(atxdmac->at_xdmac_desc_pool, gfp_flags, &phys);
if (desc) {
memset(desc, 0, sizeof(*desc));
INIT_LIST_HEAD(&desc->descs_list);
dma_async_tx_descriptor_init(&desc->tx_dma_desc, chan);
desc->tx_dma_desc.tx_submit = at_xdmac_tx_submit;
desc->tx_dma_desc.phys = phys;
}
return desc;
}
static struct at_xdmac_desc *at_xdmac_get_desc(struct at_xdmac_chan *atchan)
{
struct at_xdmac_desc *desc;
if (list_empty(&atchan->free_descs_list)) {
desc = at_xdmac_alloc_desc(&atchan->chan, GFP_NOWAIT);
} else {
desc = list_first_entry(&atchan->free_descs_list,
struct at_xdmac_desc, desc_node);
list_del(&desc->desc_node);
desc->active_xfer = false;
}
return desc;
}
static struct dma_chan *at_xdmac_xlate(struct of_phandle_args *dma_spec,
struct of_dma *of_dma)
{
struct at_xdmac *atxdmac = of_dma->of_dma_data;
struct at_xdmac_chan *atchan;
struct dma_chan *chan;
struct device *dev = atxdmac->dma.dev;
if (dma_spec->args_count != 1) {
dev_err(dev, "dma phandler args: bad number of args\n");
return NULL;
}
chan = dma_get_any_slave_channel(&atxdmac->dma);
if (!chan) {
dev_err(dev, "can't get a dma channel\n");
return NULL;
}
atchan = to_at_xdmac_chan(chan);
atchan->memif = AT91_XDMAC_DT_GET_MEM_IF(dma_spec->args[0]);
atchan->perif = AT91_XDMAC_DT_GET_PER_IF(dma_spec->args[0]);
atchan->perid = AT91_XDMAC_DT_GET_PERID(dma_spec->args[0]);
dev_dbg(dev, "chan dt cfg: memif=%u perif=%u perid=%u\n",
atchan->memif, atchan->perif, atchan->perid);
return chan;
}
static int at_xdmac_set_slave_config(struct dma_chan *chan,
struct dma_slave_config *sconfig)
{
struct at_xdmac_chan *atchan = to_at_xdmac_chan(chan);
u8 dwidth;
int csize;
atchan->cfg[AT_XDMAC_DEV_TO_MEM_CFG] =
AT91_XDMAC_DT_PERID(atchan->perid)
| AT_XDMAC_CC_DAM_INCREMENTED_AM
| AT_XDMAC_CC_SAM_FIXED_AM
| AT_XDMAC_CC_DIF(atchan->memif)
| AT_XDMAC_CC_SIF(atchan->perif)
| AT_XDMAC_CC_SWREQ_HWR_CONNECTED
| AT_XDMAC_CC_DSYNC_PER2MEM
| AT_XDMAC_CC_MBSIZE_SIXTEEN
| AT_XDMAC_CC_TYPE_PER_TRAN;
csize = at_xdmac_csize(sconfig->src_maxburst);
if (csize < 0) {
dev_err(chan2dev(chan), "invalid src maxburst value\n");
return -EINVAL;
}
atchan->cfg[AT_XDMAC_DEV_TO_MEM_CFG] |= AT_XDMAC_CC_CSIZE(csize);
dwidth = ffs(sconfig->src_addr_width) - 1;
atchan->cfg[AT_XDMAC_DEV_TO_MEM_CFG] |= AT_XDMAC_CC_DWIDTH(dwidth);
atchan->cfg[AT_XDMAC_MEM_TO_DEV_CFG] =
AT91_XDMAC_DT_PERID(atchan->perid)
| AT_XDMAC_CC_DAM_FIXED_AM
| AT_XDMAC_CC_SAM_INCREMENTED_AM
| AT_XDMAC_CC_DIF(atchan->perif)
| AT_XDMAC_CC_SIF(atchan->memif)
| AT_XDMAC_CC_SWREQ_HWR_CONNECTED
| AT_XDMAC_CC_DSYNC_MEM2PER
| AT_XDMAC_CC_MBSIZE_SIXTEEN
| AT_XDMAC_CC_TYPE_PER_TRAN;
csize = at_xdmac_csize(sconfig->dst_maxburst);
if (csize < 0) {
dev_err(chan2dev(chan), "invalid src maxburst value\n");
return -EINVAL;
}
atchan->cfg[AT_XDMAC_MEM_TO_DEV_CFG] |= AT_XDMAC_CC_CSIZE(csize);
dwidth = ffs(sconfig->dst_addr_width) - 1;
atchan->cfg[AT_XDMAC_MEM_TO_DEV_CFG] |= AT_XDMAC_CC_DWIDTH(dwidth);
atchan->per_src_addr = sconfig->src_addr;
atchan->per_dst_addr = sconfig->dst_addr;
dev_dbg(chan2dev(chan),
"%s: cfg[dev2mem]=0x%08x, cfg[mem2dev]=0x%08x, per_src_addr=0x%08x, per_dst_addr=0x%08x\n",
__func__, atchan->cfg[AT_XDMAC_DEV_TO_MEM_CFG],
atchan->cfg[AT_XDMAC_MEM_TO_DEV_CFG],
atchan->per_src_addr, atchan->per_dst_addr);
return 0;
}
static struct dma_async_tx_descriptor *
at_xdmac_prep_slave_sg(struct dma_chan *chan, struct scatterlist *sgl,
unsigned int sg_len, enum dma_transfer_direction direction,
unsigned long flags, void *context)
{
struct at_xdmac_chan *atchan = to_at_xdmac_chan(chan);
struct at_xdmac_desc *first = NULL, *prev = NULL;
struct scatterlist *sg;
int i;
unsigned int xfer_size = 0;
if (!sgl)
return NULL;
if (!is_slave_direction(direction)) {
dev_err(chan2dev(chan), "invalid DMA direction\n");
return NULL;
}
dev_dbg(chan2dev(chan), "%s: sg_len=%d, dir=%s, flags=0x%lx\n",
__func__, sg_len,
direction == DMA_MEM_TO_DEV ? "to device" : "from device",
flags);
spin_lock_bh(&atchan->lock);
for_each_sg(sgl, sg, sg_len, i) {
struct at_xdmac_desc *desc = NULL;
u32 len, mem, dwidth, fixed_dwidth;
len = sg_dma_len(sg);
mem = sg_dma_address(sg);
if (unlikely(!len)) {
dev_err(chan2dev(chan), "sg data length is zero\n");
spin_unlock_bh(&atchan->lock);
return NULL;
}
dev_dbg(chan2dev(chan), "%s: * sg%d len=%u, mem=0x%08x\n",
__func__, i, len, mem);
desc = at_xdmac_get_desc(atchan);
if (!desc) {
dev_err(chan2dev(chan), "can't get descriptor\n");
if (first)
list_splice_init(&first->descs_list, &atchan->free_descs_list);
spin_unlock_bh(&atchan->lock);
return NULL;
}
if (direction == DMA_DEV_TO_MEM) {
desc->lld.mbr_sa = atchan->per_src_addr;
desc->lld.mbr_da = mem;
desc->lld.mbr_cfg = atchan->cfg[AT_XDMAC_DEV_TO_MEM_CFG];
} else {
desc->lld.mbr_sa = mem;
desc->lld.mbr_da = atchan->per_dst_addr;
desc->lld.mbr_cfg = atchan->cfg[AT_XDMAC_MEM_TO_DEV_CFG];
}
dwidth = at_xdmac_get_dwidth(desc->lld.mbr_cfg);
fixed_dwidth = IS_ALIGNED(len, 1 << dwidth)
? at_xdmac_get_dwidth(desc->lld.mbr_cfg)
: AT_XDMAC_CC_DWIDTH_BYTE;
desc->lld.mbr_ubc = AT_XDMAC_MBR_UBC_NDV2
| AT_XDMAC_MBR_UBC_NDEN
| AT_XDMAC_MBR_UBC_NSEN
| (i == sg_len - 1 ? 0 : AT_XDMAC_MBR_UBC_NDE)
| (len >> fixed_dwidth);
dev_dbg(chan2dev(chan),
"%s: lld: mbr_sa=%pad, mbr_da=%pad, mbr_ubc=0x%08x\n",
__func__, &desc->lld.mbr_sa, &desc->lld.mbr_da, desc->lld.mbr_ubc);
if (prev) {
prev->lld.mbr_nda = desc->tx_dma_desc.phys;
dev_dbg(chan2dev(chan),
"%s: chain lld: prev=0x%p, mbr_nda=%pad\n",
__func__, prev, &prev->lld.mbr_nda);
}
prev = desc;
if (!first)
first = desc;
dev_dbg(chan2dev(chan), "%s: add desc 0x%p to descs_list 0x%p\n",
__func__, desc, first);
list_add_tail(&desc->desc_node, &first->descs_list);
xfer_size += len;
}
spin_unlock_bh(&atchan->lock);
first->tx_dma_desc.flags = flags;
first->xfer_size = xfer_size;
first->direction = direction;
return &first->tx_dma_desc;
}
static struct dma_async_tx_descriptor *
at_xdmac_prep_dma_cyclic(struct dma_chan *chan, dma_addr_t buf_addr,
size_t buf_len, size_t period_len,
enum dma_transfer_direction direction,
unsigned long flags)
{
struct at_xdmac_chan *atchan = to_at_xdmac_chan(chan);
struct at_xdmac_desc *first = NULL, *prev = NULL;
unsigned int periods = buf_len / period_len;
int i;
dev_dbg(chan2dev(chan), "%s: buf_addr=%pad, buf_len=%zd, period_len=%zd, dir=%s, flags=0x%lx\n",
__func__, &buf_addr, buf_len, period_len,
direction == DMA_MEM_TO_DEV ? "mem2per" : "per2mem", flags);
if (!is_slave_direction(direction)) {
dev_err(chan2dev(chan), "invalid DMA direction\n");
return NULL;
}
if (test_and_set_bit(AT_XDMAC_CHAN_IS_CYCLIC, &atchan->status)) {
dev_err(chan2dev(chan), "channel currently used\n");
return NULL;
}
for (i = 0; i < periods; i++) {
struct at_xdmac_desc *desc = NULL;
spin_lock_bh(&atchan->lock);
desc = at_xdmac_get_desc(atchan);
if (!desc) {
dev_err(chan2dev(chan), "can't get descriptor\n");
if (first)
list_splice_init(&first->descs_list, &atchan->free_descs_list);
spin_unlock_bh(&atchan->lock);
return NULL;
}
spin_unlock_bh(&atchan->lock);
dev_dbg(chan2dev(chan),
"%s: desc=0x%p, tx_dma_desc.phys=%pad\n",
__func__, desc, &desc->tx_dma_desc.phys);
if (direction == DMA_DEV_TO_MEM) {
desc->lld.mbr_sa = atchan->per_src_addr;
desc->lld.mbr_da = buf_addr + i * period_len;
desc->lld.mbr_cfg = atchan->cfg[AT_XDMAC_DEV_TO_MEM_CFG];
} else {
desc->lld.mbr_sa = buf_addr + i * period_len;
desc->lld.mbr_da = atchan->per_dst_addr;
desc->lld.mbr_cfg = atchan->cfg[AT_XDMAC_MEM_TO_DEV_CFG];
}
desc->lld.mbr_ubc = AT_XDMAC_MBR_UBC_NDV1
| AT_XDMAC_MBR_UBC_NDEN
| AT_XDMAC_MBR_UBC_NSEN
| AT_XDMAC_MBR_UBC_NDE
| period_len >> at_xdmac_get_dwidth(desc->lld.mbr_cfg);
dev_dbg(chan2dev(chan),
"%s: lld: mbr_sa=%pad, mbr_da=%pad, mbr_ubc=0x%08x\n",
__func__, &desc->lld.mbr_sa, &desc->lld.mbr_da, desc->lld.mbr_ubc);
if (prev) {
prev->lld.mbr_nda = desc->tx_dma_desc.phys;
dev_dbg(chan2dev(chan),
"%s: chain lld: prev=0x%p, mbr_nda=%pad\n",
__func__, prev, &prev->lld.mbr_nda);
}
prev = desc;
if (!first)
first = desc;
dev_dbg(chan2dev(chan), "%s: add desc 0x%p to descs_list 0x%p\n",
__func__, desc, first);
list_add_tail(&desc->desc_node, &first->descs_list);
}
prev->lld.mbr_nda = first->tx_dma_desc.phys;
dev_dbg(chan2dev(chan),
"%s: chain lld: prev=0x%p, mbr_nda=%pad\n",
__func__, prev, &prev->lld.mbr_nda);
first->tx_dma_desc.flags = flags;
first->xfer_size = buf_len;
first->direction = direction;
return &first->tx_dma_desc;
}
static struct dma_async_tx_descriptor *
at_xdmac_prep_dma_memcpy(struct dma_chan *chan, dma_addr_t dest, dma_addr_t src,
size_t len, unsigned long flags)
{
struct at_xdmac_chan *atchan = to_at_xdmac_chan(chan);
struct at_xdmac_desc *first = NULL, *prev = NULL;
size_t remaining_size = len, xfer_size = 0, ublen;
dma_addr_t src_addr = src, dst_addr = dest;
u32 dwidth;
u32 chan_cc = AT_XDMAC_CC_DAM_INCREMENTED_AM
| AT_XDMAC_CC_SAM_INCREMENTED_AM
| AT_XDMAC_CC_DIF(0)
| AT_XDMAC_CC_SIF(0)
| AT_XDMAC_CC_MBSIZE_SIXTEEN
| AT_XDMAC_CC_TYPE_MEM_TRAN;
dev_dbg(chan2dev(chan), "%s: src=%pad, dest=%pad, len=%zd, flags=0x%lx\n",
__func__, &src, &dest, len, flags);
if (unlikely(!len))
return NULL;
if (!((src_addr | dst_addr) & 7)) {
dwidth = AT_XDMAC_CC_DWIDTH_DWORD;
dev_dbg(chan2dev(chan), "%s: dwidth: double word\n", __func__);
} else if (!((src_addr | dst_addr) & 3)) {
dwidth = AT_XDMAC_CC_DWIDTH_WORD;
dev_dbg(chan2dev(chan), "%s: dwidth: word\n", __func__);
} else if (!((src_addr | dst_addr) & 1)) {
dwidth = AT_XDMAC_CC_DWIDTH_HALFWORD;
dev_dbg(chan2dev(chan), "%s: dwidth: half word\n", __func__);
} else {
dwidth = AT_XDMAC_CC_DWIDTH_BYTE;
dev_dbg(chan2dev(chan), "%s: dwidth: byte\n", __func__);
}
while (remaining_size) {
struct at_xdmac_desc *desc = NULL;
dev_dbg(chan2dev(chan), "%s: remaining_size=%zu\n", __func__, remaining_size);
spin_lock_bh(&atchan->lock);
desc = at_xdmac_get_desc(atchan);
spin_unlock_bh(&atchan->lock);
if (!desc) {
dev_err(chan2dev(chan), "can't get descriptor\n");
if (first)
list_splice_init(&first->descs_list, &atchan->free_descs_list);
return NULL;
}
src_addr += xfer_size;
dst_addr += xfer_size;
if (remaining_size >= AT_XDMAC_MBR_UBC_UBLEN_MAX << dwidth)
xfer_size = AT_XDMAC_MBR_UBC_UBLEN_MAX << dwidth;
else
xfer_size = remaining_size;
dev_dbg(chan2dev(chan), "%s: xfer_size=%zu\n", __func__, xfer_size);
if (!((src_addr | dst_addr | xfer_size) & 7)) {
dwidth = AT_XDMAC_CC_DWIDTH_DWORD;
dev_dbg(chan2dev(chan), "%s: dwidth: double word\n", __func__);
} else if (!((src_addr | dst_addr | xfer_size) & 3)) {
dwidth = AT_XDMAC_CC_DWIDTH_WORD;
dev_dbg(chan2dev(chan), "%s: dwidth: word\n", __func__);
} else if (!((src_addr | dst_addr | xfer_size) & 1)) {
dwidth = AT_XDMAC_CC_DWIDTH_HALFWORD;
dev_dbg(chan2dev(chan), "%s: dwidth: half word\n", __func__);
} else if ((src_addr | dst_addr | xfer_size) & 1) {
dwidth = AT_XDMAC_CC_DWIDTH_BYTE;
dev_dbg(chan2dev(chan), "%s: dwidth: byte\n", __func__);
}
chan_cc |= AT_XDMAC_CC_DWIDTH(dwidth);
ublen = xfer_size >> dwidth;
remaining_size -= xfer_size;
desc->lld.mbr_sa = src_addr;
desc->lld.mbr_da = dst_addr;
desc->lld.mbr_ubc = AT_XDMAC_MBR_UBC_NDV2
| AT_XDMAC_MBR_UBC_NDEN
| AT_XDMAC_MBR_UBC_NSEN
| (remaining_size ? AT_XDMAC_MBR_UBC_NDE : 0)
| ublen;
desc->lld.mbr_cfg = chan_cc;
dev_dbg(chan2dev(chan),
"%s: lld: mbr_sa=%pad, mbr_da=%pad, mbr_ubc=0x%08x, mbr_cfg=0x%08x\n",
__func__, &desc->lld.mbr_sa, &desc->lld.mbr_da, desc->lld.mbr_ubc, desc->lld.mbr_cfg);
if (prev) {
prev->lld.mbr_nda = desc->tx_dma_desc.phys;
dev_dbg(chan2dev(chan),
"%s: chain lld: prev=0x%p, mbr_nda=0x%08x\n",
__func__, prev, prev->lld.mbr_nda);
}
prev = desc;
if (!first)
first = desc;
dev_dbg(chan2dev(chan), "%s: add desc 0x%p to descs_list 0x%p\n",
__func__, desc, first);
list_add_tail(&desc->desc_node, &first->descs_list);
}
first->tx_dma_desc.flags = flags;
first->xfer_size = len;
return &first->tx_dma_desc;
}
static enum dma_status
at_xdmac_tx_status(struct dma_chan *chan, dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
struct at_xdmac_chan *atchan = to_at_xdmac_chan(chan);
struct at_xdmac *atxdmac = to_at_xdmac(atchan->chan.device);
struct at_xdmac_desc *desc, *_desc;
struct list_head *descs_list;
enum dma_status ret;
int residue;
u32 cur_nda, mask, value;
u8 dwidth = 0;
ret = dma_cookie_status(chan, cookie, txstate);
if (ret == DMA_COMPLETE)
return ret;
if (!txstate)
return ret;
spin_lock_bh(&atchan->lock);
desc = list_first_entry(&atchan->xfers_list, struct at_xdmac_desc, xfer_node);
if (!desc->active_xfer) {
dma_set_residue(txstate, desc->xfer_size);
spin_unlock_bh(&atchan->lock);
return ret;
}
residue = desc->xfer_size;
mask = AT_XDMAC_CC_TYPE | AT_XDMAC_CC_DSYNC;
value = AT_XDMAC_CC_TYPE_PER_TRAN | AT_XDMAC_CC_DSYNC_PER2MEM;
if ((desc->lld.mbr_cfg & mask) == value) {
at_xdmac_write(atxdmac, AT_XDMAC_GSWF, atchan->mask);
while (!(at_xdmac_chan_read(atchan, AT_XDMAC_CIS) & AT_XDMAC_CIS_FIS))
cpu_relax();
}
cur_nda = at_xdmac_chan_read(atchan, AT_XDMAC_CNDA) & 0xfffffffc;
descs_list = &desc->descs_list;
list_for_each_entry_safe(desc, _desc, descs_list, desc_node) {
dwidth = at_xdmac_get_dwidth(desc->lld.mbr_cfg);
residue -= (desc->lld.mbr_ubc & 0xffffff) << dwidth;
if ((desc->lld.mbr_nda & 0xfffffffc) == cur_nda)
break;
}
residue += at_xdmac_chan_read(atchan, AT_XDMAC_CUBC) << dwidth;
spin_unlock_bh(&atchan->lock);
dma_set_residue(txstate, residue);
dev_dbg(chan2dev(chan),
"%s: desc=0x%p, tx_dma_desc.phys=%pad, tx_status=%d, cookie=%d, residue=%d\n",
__func__, desc, &desc->tx_dma_desc.phys, ret, cookie, residue);
return ret;
}
static void at_xdmac_remove_xfer(struct at_xdmac_chan *atchan,
struct at_xdmac_desc *desc)
{
dev_dbg(chan2dev(&atchan->chan), "%s: desc 0x%p\n", __func__, desc);
list_del(&desc->xfer_node);
list_splice_init(&desc->descs_list, &atchan->free_descs_list);
}
static void at_xdmac_advance_work(struct at_xdmac_chan *atchan)
{
struct at_xdmac_desc *desc;
spin_lock_bh(&atchan->lock);
if (!at_xdmac_chan_is_enabled(atchan) && !list_empty(&atchan->xfers_list)) {
desc = list_first_entry(&atchan->xfers_list,
struct at_xdmac_desc,
xfer_node);
dev_vdbg(chan2dev(&atchan->chan), "%s: desc 0x%p\n", __func__, desc);
if (!desc->active_xfer)
at_xdmac_start_xfer(atchan, desc);
}
spin_unlock_bh(&atchan->lock);
}
static void at_xdmac_handle_cyclic(struct at_xdmac_chan *atchan)
{
struct at_xdmac_desc *desc;
struct dma_async_tx_descriptor *txd;
desc = list_first_entry(&atchan->xfers_list, struct at_xdmac_desc, xfer_node);
txd = &desc->tx_dma_desc;
if (txd->callback && (txd->flags & DMA_PREP_INTERRUPT))
txd->callback(txd->callback_param);
}
static void at_xdmac_tasklet(unsigned long data)
{
struct at_xdmac_chan *atchan = (struct at_xdmac_chan *)data;
struct at_xdmac_desc *desc;
u32 error_mask;
dev_dbg(chan2dev(&atchan->chan), "%s: status=0x%08lx\n",
__func__, atchan->status);
error_mask = AT_XDMAC_CIS_RBEIS
| AT_XDMAC_CIS_WBEIS
| AT_XDMAC_CIS_ROIS;
if (at_xdmac_chan_is_cyclic(atchan)) {
at_xdmac_handle_cyclic(atchan);
} else if ((atchan->status & AT_XDMAC_CIS_LIS)
|| (atchan->status & error_mask)) {
struct dma_async_tx_descriptor *txd;
if (atchan->status & AT_XDMAC_CIS_RBEIS)
dev_err(chan2dev(&atchan->chan), "read bus error!!!");
if (atchan->status & AT_XDMAC_CIS_WBEIS)
dev_err(chan2dev(&atchan->chan), "write bus error!!!");
if (atchan->status & AT_XDMAC_CIS_ROIS)
dev_err(chan2dev(&atchan->chan), "request overflow error!!!");
spin_lock_bh(&atchan->lock);
desc = list_first_entry(&atchan->xfers_list,
struct at_xdmac_desc,
xfer_node);
dev_vdbg(chan2dev(&atchan->chan), "%s: desc 0x%p\n", __func__, desc);
BUG_ON(!desc->active_xfer);
txd = &desc->tx_dma_desc;
at_xdmac_remove_xfer(atchan, desc);
spin_unlock_bh(&atchan->lock);
if (!at_xdmac_chan_is_cyclic(atchan)) {
dma_cookie_complete(txd);
if (txd->callback && (txd->flags & DMA_PREP_INTERRUPT))
txd->callback(txd->callback_param);
}
dma_run_dependencies(txd);
at_xdmac_advance_work(atchan);
}
}
static irqreturn_t at_xdmac_interrupt(int irq, void *dev_id)
{
struct at_xdmac *atxdmac = (struct at_xdmac *)dev_id;
struct at_xdmac_chan *atchan;
u32 imr, status, pending;
u32 chan_imr, chan_status;
int i, ret = IRQ_NONE;
do {
imr = at_xdmac_read(atxdmac, AT_XDMAC_GIM);
status = at_xdmac_read(atxdmac, AT_XDMAC_GIS);
pending = status & imr;
dev_vdbg(atxdmac->dma.dev,
"%s: status=0x%08x, imr=0x%08x, pending=0x%08x\n",
__func__, status, imr, pending);
if (!pending)
break;
for (i = 0; i < atxdmac->dma.chancnt; i++) {
if (!((1 << i) & pending))
continue;
atchan = &atxdmac->chan[i];
chan_imr = at_xdmac_chan_read(atchan, AT_XDMAC_CIM);
chan_status = at_xdmac_chan_read(atchan, AT_XDMAC_CIS);
atchan->status = chan_status & chan_imr;
dev_vdbg(atxdmac->dma.dev,
"%s: chan%d: imr=0x%x, status=0x%x\n",
__func__, i, chan_imr, chan_status);
dev_vdbg(chan2dev(&atchan->chan),
"%s: CC=0x%08x CNDA=0x%08x, CNDC=0x%08x, CSA=0x%08x, CDA=0x%08x, CUBC=0x%08x\n",
__func__,
at_xdmac_chan_read(atchan, AT_XDMAC_CC),
at_xdmac_chan_read(atchan, AT_XDMAC_CNDA),
at_xdmac_chan_read(atchan, AT_XDMAC_CNDC),
at_xdmac_chan_read(atchan, AT_XDMAC_CSA),
at_xdmac_chan_read(atchan, AT_XDMAC_CDA),
at_xdmac_chan_read(atchan, AT_XDMAC_CUBC));
if (atchan->status & (AT_XDMAC_CIS_RBEIS | AT_XDMAC_CIS_WBEIS))
at_xdmac_write(atxdmac, AT_XDMAC_GD, atchan->mask);
tasklet_schedule(&atchan->tasklet);
ret = IRQ_HANDLED;
}
} while (pending);
return ret;
}
static void at_xdmac_issue_pending(struct dma_chan *chan)
{
struct at_xdmac_chan *atchan = to_at_xdmac_chan(chan);
dev_dbg(chan2dev(&atchan->chan), "%s\n", __func__);
if (!at_xdmac_chan_is_cyclic(atchan))
at_xdmac_advance_work(atchan);
return;
}
static int at_xdmac_device_config(struct dma_chan *chan,
struct dma_slave_config *config)
{
struct at_xdmac_chan *atchan = to_at_xdmac_chan(chan);
int ret;
dev_dbg(chan2dev(chan), "%s\n", __func__);
spin_lock_bh(&atchan->lock);
ret = at_xdmac_set_slave_config(chan, config);
spin_unlock_bh(&atchan->lock);
return ret;
}
static int at_xdmac_device_pause(struct dma_chan *chan)
{
struct at_xdmac_chan *atchan = to_at_xdmac_chan(chan);
struct at_xdmac *atxdmac = to_at_xdmac(atchan->chan.device);
dev_dbg(chan2dev(chan), "%s\n", __func__);
if (test_and_set_bit(AT_XDMAC_CHAN_IS_PAUSED, &atchan->status))
return 0;
spin_lock_bh(&atchan->lock);
at_xdmac_write(atxdmac, AT_XDMAC_GRWS, atchan->mask);
while (at_xdmac_chan_read(atchan, AT_XDMAC_CC)
& (AT_XDMAC_CC_WRIP | AT_XDMAC_CC_RDIP))
cpu_relax();
spin_unlock_bh(&atchan->lock);
return 0;
}
static int at_xdmac_device_resume(struct dma_chan *chan)
{
struct at_xdmac_chan *atchan = to_at_xdmac_chan(chan);
struct at_xdmac *atxdmac = to_at_xdmac(atchan->chan.device);
dev_dbg(chan2dev(chan), "%s\n", __func__);
spin_lock_bh(&atchan->lock);
if (!at_xdmac_chan_is_paused(atchan))
return 0;
at_xdmac_write(atxdmac, AT_XDMAC_GRWR, atchan->mask);
clear_bit(AT_XDMAC_CHAN_IS_PAUSED, &atchan->status);
spin_unlock_bh(&atchan->lock);
return 0;
}
static int at_xdmac_device_terminate_all(struct dma_chan *chan)
{
struct at_xdmac_desc *desc, *_desc;
struct at_xdmac_chan *atchan = to_at_xdmac_chan(chan);
struct at_xdmac *atxdmac = to_at_xdmac(atchan->chan.device);
dev_dbg(chan2dev(chan), "%s\n", __func__);
spin_lock_bh(&atchan->lock);
at_xdmac_write(atxdmac, AT_XDMAC_GD, atchan->mask);
while (at_xdmac_read(atxdmac, AT_XDMAC_GS) & atchan->mask)
cpu_relax();
list_for_each_entry_safe(desc, _desc, &atchan->xfers_list, xfer_node)
at_xdmac_remove_xfer(atchan, desc);
clear_bit(AT_XDMAC_CHAN_IS_CYCLIC, &atchan->status);
spin_unlock_bh(&atchan->lock);
return 0;
}
static int at_xdmac_alloc_chan_resources(struct dma_chan *chan)
{
struct at_xdmac_chan *atchan = to_at_xdmac_chan(chan);
struct at_xdmac_desc *desc;
int i;
spin_lock_bh(&atchan->lock);
if (at_xdmac_chan_is_enabled(atchan)) {
dev_err(chan2dev(chan),
"can't allocate channel resources (channel enabled)\n");
i = -EIO;
goto spin_unlock;
}
if (!list_empty(&atchan->free_descs_list)) {
dev_err(chan2dev(chan),
"can't allocate channel resources (channel not free from a previous use)\n");
i = -EIO;
goto spin_unlock;
}
for (i = 0; i < init_nr_desc_per_channel; i++) {
desc = at_xdmac_alloc_desc(chan, GFP_ATOMIC);
if (!desc) {
dev_warn(chan2dev(chan),
"only %d descriptors have been allocated\n", i);
break;
}
list_add_tail(&desc->desc_node, &atchan->free_descs_list);
}
dma_cookie_init(chan);
dev_dbg(chan2dev(chan), "%s: allocated %d descriptors\n", __func__, i);
spin_unlock:
spin_unlock_bh(&atchan->lock);
return i;
}
static void at_xdmac_free_chan_resources(struct dma_chan *chan)
{
struct at_xdmac_chan *atchan = to_at_xdmac_chan(chan);
struct at_xdmac *atxdmac = to_at_xdmac(chan->device);
struct at_xdmac_desc *desc, *_desc;
list_for_each_entry_safe(desc, _desc, &atchan->free_descs_list, desc_node) {
dev_dbg(chan2dev(chan), "%s: freeing descriptor %p\n", __func__, desc);
list_del(&desc->desc_node);
dma_pool_free(atxdmac->at_xdmac_desc_pool, desc, desc->tx_dma_desc.phys);
}
return;
}
static int atmel_xdmac_prepare(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct at_xdmac *atxdmac = platform_get_drvdata(pdev);
struct dma_chan *chan, *_chan;
list_for_each_entry_safe(chan, _chan, &atxdmac->dma.channels, device_node) {
struct at_xdmac_chan *atchan = to_at_xdmac_chan(chan);
if (at_xdmac_chan_is_enabled(atchan) && !at_xdmac_chan_is_cyclic(atchan))
return -EAGAIN;
}
return 0;
}
static int atmel_xdmac_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct at_xdmac *atxdmac = platform_get_drvdata(pdev);
struct dma_chan *chan, *_chan;
list_for_each_entry_safe(chan, _chan, &atxdmac->dma.channels, device_node) {
struct at_xdmac_chan *atchan = to_at_xdmac_chan(chan);
atchan->save_cc = at_xdmac_chan_read(atchan, AT_XDMAC_CC);
if (at_xdmac_chan_is_cyclic(atchan)) {
if (!at_xdmac_chan_is_paused(atchan))
at_xdmac_device_pause(chan);
atchan->save_cim = at_xdmac_chan_read(atchan, AT_XDMAC_CIM);
atchan->save_cnda = at_xdmac_chan_read(atchan, AT_XDMAC_CNDA);
atchan->save_cndc = at_xdmac_chan_read(atchan, AT_XDMAC_CNDC);
}
}
atxdmac->save_gim = at_xdmac_read(atxdmac, AT_XDMAC_GIM);
at_xdmac_off(atxdmac);
clk_disable_unprepare(atxdmac->clk);
return 0;
}
static int atmel_xdmac_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct at_xdmac *atxdmac = platform_get_drvdata(pdev);
struct at_xdmac_chan *atchan;
struct dma_chan *chan, *_chan;
int i;
clk_prepare_enable(atxdmac->clk);
for (i = 0; i < atxdmac->dma.chancnt; i++) {
atchan = &atxdmac->chan[i];
while (at_xdmac_chan_read(atchan, AT_XDMAC_CIS))
cpu_relax();
}
at_xdmac_write(atxdmac, AT_XDMAC_GIE, atxdmac->save_gim);
at_xdmac_write(atxdmac, AT_XDMAC_GE, atxdmac->save_gs);
list_for_each_entry_safe(chan, _chan, &atxdmac->dma.channels, device_node) {
atchan = to_at_xdmac_chan(chan);
at_xdmac_chan_write(atchan, AT_XDMAC_CC, atchan->save_cc);
if (at_xdmac_chan_is_cyclic(atchan)) {
at_xdmac_chan_write(atchan, AT_XDMAC_CNDA, atchan->save_cnda);
at_xdmac_chan_write(atchan, AT_XDMAC_CNDC, atchan->save_cndc);
at_xdmac_chan_write(atchan, AT_XDMAC_CIE, atchan->save_cim);
wmb();
at_xdmac_write(atxdmac, AT_XDMAC_GE, atchan->mask);
}
}
return 0;
}
static int at_xdmac_probe(struct platform_device *pdev)
{
struct resource *res;
struct at_xdmac *atxdmac;
int irq, size, nr_channels, i, ret;
void __iomem *base;
u32 reg;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -EINVAL;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
reg = readl_relaxed(base + AT_XDMAC_GTYPE);
nr_channels = AT_XDMAC_NB_CH(reg);
if (nr_channels > AT_XDMAC_MAX_CHAN) {
dev_err(&pdev->dev, "invalid number of channels (%u)\n",
nr_channels);
return -EINVAL;
}
size = sizeof(*atxdmac);
size += nr_channels * sizeof(struct at_xdmac_chan);
atxdmac = devm_kzalloc(&pdev->dev, size, GFP_KERNEL);
if (!atxdmac) {
dev_err(&pdev->dev, "can't allocate at_xdmac structure\n");
return -ENOMEM;
}
atxdmac->regs = base;
atxdmac->irq = irq;
atxdmac->clk = devm_clk_get(&pdev->dev, "dma_clk");
if (IS_ERR(atxdmac->clk)) {
dev_err(&pdev->dev, "can't get dma_clk\n");
return PTR_ERR(atxdmac->clk);
}
ret = request_irq(atxdmac->irq, at_xdmac_interrupt, 0, "at_xdmac", atxdmac);
if (ret) {
dev_err(&pdev->dev, "can't request irq\n");
return ret;
}
ret = clk_prepare_enable(atxdmac->clk);
if (ret) {
dev_err(&pdev->dev, "can't prepare or enable clock\n");
goto err_free_irq;
}
atxdmac->at_xdmac_desc_pool =
dmam_pool_create(dev_name(&pdev->dev), &pdev->dev,
sizeof(struct at_xdmac_desc), 4, 0);
if (!atxdmac->at_xdmac_desc_pool) {
dev_err(&pdev->dev, "no memory for descriptors dma pool\n");
ret = -ENOMEM;
goto err_clk_disable;
}
dma_cap_set(DMA_CYCLIC, atxdmac->dma.cap_mask);
dma_cap_set(DMA_MEMCPY, atxdmac->dma.cap_mask);
dma_cap_set(DMA_SLAVE, atxdmac->dma.cap_mask);
dma_cap_set(DMA_PRIVATE, atxdmac->dma.cap_mask);
atxdmac->dma.dev = &pdev->dev;
atxdmac->dma.device_alloc_chan_resources = at_xdmac_alloc_chan_resources;
atxdmac->dma.device_free_chan_resources = at_xdmac_free_chan_resources;
atxdmac->dma.device_tx_status = at_xdmac_tx_status;
atxdmac->dma.device_issue_pending = at_xdmac_issue_pending;
atxdmac->dma.device_prep_dma_cyclic = at_xdmac_prep_dma_cyclic;
atxdmac->dma.device_prep_dma_memcpy = at_xdmac_prep_dma_memcpy;
atxdmac->dma.device_prep_slave_sg = at_xdmac_prep_slave_sg;
atxdmac->dma.device_config = at_xdmac_device_config;
atxdmac->dma.device_pause = at_xdmac_device_pause;
atxdmac->dma.device_resume = at_xdmac_device_resume;
atxdmac->dma.device_terminate_all = at_xdmac_device_terminate_all;
atxdmac->dma.src_addr_widths = AT_XDMAC_DMA_BUSWIDTHS;
atxdmac->dma.dst_addr_widths = AT_XDMAC_DMA_BUSWIDTHS;
atxdmac->dma.directions = BIT(DMA_DEV_TO_MEM) | BIT(DMA_MEM_TO_DEV);
atxdmac->dma.residue_granularity = DMA_RESIDUE_GRANULARITY_BURST;
at_xdmac_off(atxdmac);
INIT_LIST_HEAD(&atxdmac->dma.channels);
for (i = 0; i < nr_channels; i++) {
struct at_xdmac_chan *atchan = &atxdmac->chan[i];
atchan->chan.device = &atxdmac->dma;
list_add_tail(&atchan->chan.device_node,
&atxdmac->dma.channels);
atchan->ch_regs = at_xdmac_chan_reg_base(atxdmac, i);
atchan->mask = 1 << i;
spin_lock_init(&atchan->lock);
INIT_LIST_HEAD(&atchan->xfers_list);
INIT_LIST_HEAD(&atchan->free_descs_list);
tasklet_init(&atchan->tasklet, at_xdmac_tasklet,
(unsigned long)atchan);
while (at_xdmac_chan_read(atchan, AT_XDMAC_CIS))
cpu_relax();
}
platform_set_drvdata(pdev, atxdmac);
ret = dma_async_device_register(&atxdmac->dma);
if (ret) {
dev_err(&pdev->dev, "fail to register DMA engine device\n");
goto err_clk_disable;
}
ret = of_dma_controller_register(pdev->dev.of_node,
at_xdmac_xlate, atxdmac);
if (ret) {
dev_err(&pdev->dev, "could not register of dma controller\n");
goto err_dma_unregister;
}
dev_info(&pdev->dev, "%d channels, mapped at 0x%p\n",
nr_channels, atxdmac->regs);
return 0;
err_dma_unregister:
dma_async_device_unregister(&atxdmac->dma);
err_clk_disable:
clk_disable_unprepare(atxdmac->clk);
err_free_irq:
free_irq(atxdmac->irq, atxdmac->dma.dev);
return ret;
}
static int at_xdmac_remove(struct platform_device *pdev)
{
struct at_xdmac *atxdmac = (struct at_xdmac *)platform_get_drvdata(pdev);
int i;
at_xdmac_off(atxdmac);
of_dma_controller_free(pdev->dev.of_node);
dma_async_device_unregister(&atxdmac->dma);
clk_disable_unprepare(atxdmac->clk);
synchronize_irq(atxdmac->irq);
free_irq(atxdmac->irq, atxdmac->dma.dev);
for (i = 0; i < atxdmac->dma.chancnt; i++) {
struct at_xdmac_chan *atchan = &atxdmac->chan[i];
tasklet_kill(&atchan->tasklet);
at_xdmac_free_chan_resources(&atchan->chan);
}
return 0;
}
static int __init at_xdmac_init(void)
{
return platform_driver_probe(&at_xdmac_driver, at_xdmac_probe);
}
