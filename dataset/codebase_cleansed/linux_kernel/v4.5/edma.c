static inline unsigned int edma_read(struct edma_cc *ecc, int offset)
{
return (unsigned int)__raw_readl(ecc->base + offset);
}
static inline void edma_write(struct edma_cc *ecc, int offset, int val)
{
__raw_writel(val, ecc->base + offset);
}
static inline void edma_modify(struct edma_cc *ecc, int offset, unsigned and,
unsigned or)
{
unsigned val = edma_read(ecc, offset);
val &= and;
val |= or;
edma_write(ecc, offset, val);
}
static inline void edma_and(struct edma_cc *ecc, int offset, unsigned and)
{
unsigned val = edma_read(ecc, offset);
val &= and;
edma_write(ecc, offset, val);
}
static inline void edma_or(struct edma_cc *ecc, int offset, unsigned or)
{
unsigned val = edma_read(ecc, offset);
val |= or;
edma_write(ecc, offset, val);
}
static inline unsigned int edma_read_array(struct edma_cc *ecc, int offset,
int i)
{
return edma_read(ecc, offset + (i << 2));
}
static inline void edma_write_array(struct edma_cc *ecc, int offset, int i,
unsigned val)
{
edma_write(ecc, offset + (i << 2), val);
}
static inline void edma_modify_array(struct edma_cc *ecc, int offset, int i,
unsigned and, unsigned or)
{
edma_modify(ecc, offset + (i << 2), and, or);
}
static inline void edma_or_array(struct edma_cc *ecc, int offset, int i,
unsigned or)
{
edma_or(ecc, offset + (i << 2), or);
}
static inline void edma_or_array2(struct edma_cc *ecc, int offset, int i, int j,
unsigned or)
{
edma_or(ecc, offset + ((i * 2 + j) << 2), or);
}
static inline void edma_write_array2(struct edma_cc *ecc, int offset, int i,
int j, unsigned val)
{
edma_write(ecc, offset + ((i * 2 + j) << 2), val);
}
static inline unsigned int edma_shadow0_read(struct edma_cc *ecc, int offset)
{
return edma_read(ecc, EDMA_SHADOW0 + offset);
}
static inline unsigned int edma_shadow0_read_array(struct edma_cc *ecc,
int offset, int i)
{
return edma_read(ecc, EDMA_SHADOW0 + offset + (i << 2));
}
static inline void edma_shadow0_write(struct edma_cc *ecc, int offset,
unsigned val)
{
edma_write(ecc, EDMA_SHADOW0 + offset, val);
}
static inline void edma_shadow0_write_array(struct edma_cc *ecc, int offset,
int i, unsigned val)
{
edma_write(ecc, EDMA_SHADOW0 + offset + (i << 2), val);
}
static inline unsigned int edma_param_read(struct edma_cc *ecc, int offset,
int param_no)
{
return edma_read(ecc, EDMA_PARM + offset + (param_no << 5));
}
static inline void edma_param_write(struct edma_cc *ecc, int offset,
int param_no, unsigned val)
{
edma_write(ecc, EDMA_PARM + offset + (param_no << 5), val);
}
static inline void edma_param_modify(struct edma_cc *ecc, int offset,
int param_no, unsigned and, unsigned or)
{
edma_modify(ecc, EDMA_PARM + offset + (param_no << 5), and, or);
}
static inline void edma_param_and(struct edma_cc *ecc, int offset, int param_no,
unsigned and)
{
edma_and(ecc, EDMA_PARM + offset + (param_no << 5), and);
}
static inline void edma_param_or(struct edma_cc *ecc, int offset, int param_no,
unsigned or)
{
edma_or(ecc, EDMA_PARM + offset + (param_no << 5), or);
}
static inline void set_bits(int offset, int len, unsigned long *p)
{
for (; len > 0; len--)
set_bit(offset + (len - 1), p);
}
static inline void clear_bits(int offset, int len, unsigned long *p)
{
for (; len > 0; len--)
clear_bit(offset + (len - 1), p);
}
static void edma_assign_priority_to_queue(struct edma_cc *ecc, int queue_no,
int priority)
{
int bit = queue_no * 4;
edma_modify(ecc, EDMA_QUEPRI, ~(0x7 << bit), ((priority & 0x7) << bit));
}
static void edma_set_chmap(struct edma_chan *echan, int slot)
{
struct edma_cc *ecc = echan->ecc;
int channel = EDMA_CHAN_SLOT(echan->ch_num);
if (ecc->chmap_exist) {
slot = EDMA_CHAN_SLOT(slot);
edma_write_array(ecc, EDMA_DCHMAP, channel, (slot << 5));
}
}
static void edma_setup_interrupt(struct edma_chan *echan, bool enable)
{
struct edma_cc *ecc = echan->ecc;
int channel = EDMA_CHAN_SLOT(echan->ch_num);
if (enable) {
edma_shadow0_write_array(ecc, SH_ICR, channel >> 5,
BIT(channel & 0x1f));
edma_shadow0_write_array(ecc, SH_IESR, channel >> 5,
BIT(channel & 0x1f));
} else {
edma_shadow0_write_array(ecc, SH_IECR, channel >> 5,
BIT(channel & 0x1f));
}
}
static void edma_write_slot(struct edma_cc *ecc, unsigned slot,
const struct edmacc_param *param)
{
slot = EDMA_CHAN_SLOT(slot);
if (slot >= ecc->num_slots)
return;
memcpy_toio(ecc->base + PARM_OFFSET(slot), param, PARM_SIZE);
}
static void edma_read_slot(struct edma_cc *ecc, unsigned slot,
struct edmacc_param *param)
{
slot = EDMA_CHAN_SLOT(slot);
if (slot >= ecc->num_slots)
return;
memcpy_fromio(param, ecc->base + PARM_OFFSET(slot), PARM_SIZE);
}
static int edma_alloc_slot(struct edma_cc *ecc, int slot)
{
if (slot >= 0) {
slot = EDMA_CHAN_SLOT(slot);
if (ecc->chmap_exist && slot < ecc->num_channels)
slot = EDMA_SLOT_ANY;
}
if (slot < 0) {
if (ecc->chmap_exist)
slot = 0;
else
slot = ecc->num_channels;
for (;;) {
slot = find_next_zero_bit(ecc->slot_inuse,
ecc->num_slots,
slot);
if (slot == ecc->num_slots)
return -ENOMEM;
if (!test_and_set_bit(slot, ecc->slot_inuse))
break;
}
} else if (slot >= ecc->num_slots) {
return -EINVAL;
} else if (test_and_set_bit(slot, ecc->slot_inuse)) {
return -EBUSY;
}
edma_write_slot(ecc, slot, &dummy_paramset);
return EDMA_CTLR_CHAN(ecc->id, slot);
}
static void edma_free_slot(struct edma_cc *ecc, unsigned slot)
{
slot = EDMA_CHAN_SLOT(slot);
if (slot >= ecc->num_slots)
return;
edma_write_slot(ecc, slot, &dummy_paramset);
clear_bit(slot, ecc->slot_inuse);
}
static void edma_link(struct edma_cc *ecc, unsigned from, unsigned to)
{
if (unlikely(EDMA_CTLR(from) != EDMA_CTLR(to)))
dev_warn(ecc->dev, "Ignoring eDMA instance for linking\n");
from = EDMA_CHAN_SLOT(from);
to = EDMA_CHAN_SLOT(to);
if (from >= ecc->num_slots || to >= ecc->num_slots)
return;
edma_param_modify(ecc, PARM_LINK_BCNTRLD, from, 0xffff0000,
PARM_OFFSET(to));
}
static dma_addr_t edma_get_position(struct edma_cc *ecc, unsigned slot,
bool dst)
{
u32 offs;
slot = EDMA_CHAN_SLOT(slot);
offs = PARM_OFFSET(slot);
offs += dst ? PARM_DST : PARM_SRC;
return edma_read(ecc, offs);
}
static void edma_start(struct edma_chan *echan)
{
struct edma_cc *ecc = echan->ecc;
int channel = EDMA_CHAN_SLOT(echan->ch_num);
int j = (channel >> 5);
unsigned int mask = BIT(channel & 0x1f);
if (!echan->hw_triggered) {
dev_dbg(ecc->dev, "ESR%d %08x\n", j,
edma_shadow0_read_array(ecc, SH_ESR, j));
edma_shadow0_write_array(ecc, SH_ESR, j, mask);
} else {
dev_dbg(ecc->dev, "ER%d %08x\n", j,
edma_shadow0_read_array(ecc, SH_ER, j));
edma_write_array(ecc, EDMA_ECR, j, mask);
edma_write_array(ecc, EDMA_EMCR, j, mask);
edma_shadow0_write_array(ecc, SH_SECR, j, mask);
edma_shadow0_write_array(ecc, SH_EESR, j, mask);
dev_dbg(ecc->dev, "EER%d %08x\n", j,
edma_shadow0_read_array(ecc, SH_EER, j));
}
}
static void edma_stop(struct edma_chan *echan)
{
struct edma_cc *ecc = echan->ecc;
int channel = EDMA_CHAN_SLOT(echan->ch_num);
int j = (channel >> 5);
unsigned int mask = BIT(channel & 0x1f);
edma_shadow0_write_array(ecc, SH_EECR, j, mask);
edma_shadow0_write_array(ecc, SH_ECR, j, mask);
edma_shadow0_write_array(ecc, SH_SECR, j, mask);
edma_write_array(ecc, EDMA_EMCR, j, mask);
edma_shadow0_write_array(ecc, SH_ICR, j, mask);
dev_dbg(ecc->dev, "EER%d %08x\n", j,
edma_shadow0_read_array(ecc, SH_EER, j));
}
static void edma_pause(struct edma_chan *echan)
{
int channel = EDMA_CHAN_SLOT(echan->ch_num);
unsigned int mask = BIT(channel & 0x1f);
edma_shadow0_write_array(echan->ecc, SH_EECR, channel >> 5, mask);
}
static void edma_resume(struct edma_chan *echan)
{
int channel = EDMA_CHAN_SLOT(echan->ch_num);
unsigned int mask = BIT(channel & 0x1f);
edma_shadow0_write_array(echan->ecc, SH_EESR, channel >> 5, mask);
}
static void edma_trigger_channel(struct edma_chan *echan)
{
struct edma_cc *ecc = echan->ecc;
int channel = EDMA_CHAN_SLOT(echan->ch_num);
unsigned int mask = BIT(channel & 0x1f);
edma_shadow0_write_array(ecc, SH_ESR, (channel >> 5), mask);
dev_dbg(ecc->dev, "ESR%d %08x\n", (channel >> 5),
edma_shadow0_read_array(ecc, SH_ESR, (channel >> 5)));
}
static void edma_clean_channel(struct edma_chan *echan)
{
struct edma_cc *ecc = echan->ecc;
int channel = EDMA_CHAN_SLOT(echan->ch_num);
int j = (channel >> 5);
unsigned int mask = BIT(channel & 0x1f);
dev_dbg(ecc->dev, "EMR%d %08x\n", j, edma_read_array(ecc, EDMA_EMR, j));
edma_shadow0_write_array(ecc, SH_ECR, j, mask);
edma_write_array(ecc, EDMA_EMCR, j, mask);
edma_shadow0_write_array(ecc, SH_SECR, j, mask);
edma_write(ecc, EDMA_CCERRCLR, BIT(16) | BIT(1) | BIT(0));
}
static void edma_assign_channel_eventq(struct edma_chan *echan,
enum dma_event_q eventq_no)
{
struct edma_cc *ecc = echan->ecc;
int channel = EDMA_CHAN_SLOT(echan->ch_num);
int bit = (channel & 0x7) * 4;
if (eventq_no == EVENTQ_DEFAULT)
eventq_no = ecc->default_queue;
if (eventq_no >= ecc->num_tc)
return;
eventq_no &= 7;
edma_modify_array(ecc, EDMA_DMAQNUM, (channel >> 3), ~(0x7 << bit),
eventq_no << bit);
}
static int edma_alloc_channel(struct edma_chan *echan,
enum dma_event_q eventq_no)
{
struct edma_cc *ecc = echan->ecc;
int channel = EDMA_CHAN_SLOT(echan->ch_num);
edma_or_array2(ecc, EDMA_DRAE, 0, channel >> 5, BIT(channel & 0x1f));
edma_stop(echan);
edma_setup_interrupt(echan, true);
edma_assign_channel_eventq(echan, eventq_no);
return 0;
}
static void edma_free_channel(struct edma_chan *echan)
{
edma_stop(echan);
edma_setup_interrupt(echan, false);
}
static inline struct edma_cc *to_edma_cc(struct dma_device *d)
{
return container_of(d, struct edma_cc, dma_slave);
}
static inline struct edma_chan *to_edma_chan(struct dma_chan *c)
{
return container_of(c, struct edma_chan, vchan.chan);
}
static inline struct edma_desc *to_edma_desc(struct dma_async_tx_descriptor *tx)
{
return container_of(tx, struct edma_desc, vdesc.tx);
}
static void edma_desc_free(struct virt_dma_desc *vdesc)
{
kfree(container_of(vdesc, struct edma_desc, vdesc));
}
static void edma_execute(struct edma_chan *echan)
{
struct edma_cc *ecc = echan->ecc;
struct virt_dma_desc *vdesc;
struct edma_desc *edesc;
struct device *dev = echan->vchan.chan.device->dev;
int i, j, left, nslots;
if (!echan->edesc) {
vdesc = vchan_next_desc(&echan->vchan);
if (!vdesc)
return;
list_del(&vdesc->node);
echan->edesc = to_edma_desc(&vdesc->tx);
}
edesc = echan->edesc;
left = edesc->pset_nr - edesc->processed;
nslots = min(MAX_NR_SG, left);
edesc->sg_len = 0;
for (i = 0; i < nslots; i++) {
j = i + edesc->processed;
edma_write_slot(ecc, echan->slot[i], &edesc->pset[j].param);
edesc->sg_len += edesc->pset[j].len;
dev_vdbg(dev,
"\n pset[%d]:\n"
" chnum\t%d\n"
" slot\t%d\n"
" opt\t%08x\n"
" src\t%08x\n"
" dst\t%08x\n"
" abcnt\t%08x\n"
" ccnt\t%08x\n"
" bidx\t%08x\n"
" cidx\t%08x\n"
" lkrld\t%08x\n",
j, echan->ch_num, echan->slot[i],
edesc->pset[j].param.opt,
edesc->pset[j].param.src,
edesc->pset[j].param.dst,
edesc->pset[j].param.a_b_cnt,
edesc->pset[j].param.ccnt,
edesc->pset[j].param.src_dst_bidx,
edesc->pset[j].param.src_dst_cidx,
edesc->pset[j].param.link_bcntrld);
if (i != (nslots - 1))
edma_link(ecc, echan->slot[i], echan->slot[i + 1]);
}
edesc->processed += nslots;
if (edesc->processed == edesc->pset_nr) {
if (edesc->cyclic)
edma_link(ecc, echan->slot[nslots - 1], echan->slot[1]);
else
edma_link(ecc, echan->slot[nslots - 1],
echan->ecc->dummy_slot);
}
if (echan->missed) {
dev_dbg(dev, "missed event on channel %d\n", echan->ch_num);
edma_clean_channel(echan);
edma_stop(echan);
edma_start(echan);
edma_trigger_channel(echan);
echan->missed = 0;
} else if (edesc->processed <= MAX_NR_SG) {
dev_dbg(dev, "first transfer starting on channel %d\n",
echan->ch_num);
edma_start(echan);
} else {
dev_dbg(dev, "chan: %d: completed %d elements, resuming\n",
echan->ch_num, edesc->processed);
edma_resume(echan);
}
}
static int edma_terminate_all(struct dma_chan *chan)
{
struct edma_chan *echan = to_edma_chan(chan);
unsigned long flags;
LIST_HEAD(head);
spin_lock_irqsave(&echan->vchan.lock, flags);
if (echan->edesc) {
edma_stop(echan);
if (!echan->tc && echan->edesc->cyclic)
edma_assign_channel_eventq(echan, EVENTQ_DEFAULT);
edma_desc_free(&echan->edesc->vdesc);
echan->edesc = NULL;
}
vchan_get_all_descriptors(&echan->vchan, &head);
spin_unlock_irqrestore(&echan->vchan.lock, flags);
vchan_dma_desc_free_list(&echan->vchan, &head);
return 0;
}
static int edma_slave_config(struct dma_chan *chan,
struct dma_slave_config *cfg)
{
struct edma_chan *echan = to_edma_chan(chan);
if (cfg->src_addr_width == DMA_SLAVE_BUSWIDTH_8_BYTES ||
cfg->dst_addr_width == DMA_SLAVE_BUSWIDTH_8_BYTES)
return -EINVAL;
memcpy(&echan->cfg, cfg, sizeof(echan->cfg));
return 0;
}
static int edma_dma_pause(struct dma_chan *chan)
{
struct edma_chan *echan = to_edma_chan(chan);
if (!echan->edesc)
return -EINVAL;
edma_pause(echan);
return 0;
}
static int edma_dma_resume(struct dma_chan *chan)
{
struct edma_chan *echan = to_edma_chan(chan);
edma_resume(echan);
return 0;
}
static int edma_config_pset(struct dma_chan *chan, struct edma_pset *epset,
dma_addr_t src_addr, dma_addr_t dst_addr, u32 burst,
unsigned int acnt, unsigned int dma_length,
enum dma_transfer_direction direction)
{
struct edma_chan *echan = to_edma_chan(chan);
struct device *dev = chan->device->dev;
struct edmacc_param *param = &epset->param;
int bcnt, ccnt, cidx;
int src_bidx, dst_bidx, src_cidx, dst_cidx;
int absync;
if (!burst)
burst = 1;
if (burst == 1) {
absync = false;
ccnt = dma_length / acnt / (SZ_64K - 1);
bcnt = dma_length / acnt - ccnt * (SZ_64K - 1);
if (bcnt)
ccnt++;
else
bcnt = SZ_64K - 1;
cidx = acnt;
} else {
absync = true;
bcnt = burst;
ccnt = dma_length / (acnt * bcnt);
if (ccnt > (SZ_64K - 1)) {
dev_err(dev, "Exceeded max SG segment size\n");
return -EINVAL;
}
cidx = acnt * bcnt;
}
epset->len = dma_length;
if (direction == DMA_MEM_TO_DEV) {
src_bidx = acnt;
src_cidx = cidx;
dst_bidx = 0;
dst_cidx = 0;
epset->addr = src_addr;
} else if (direction == DMA_DEV_TO_MEM) {
src_bidx = 0;
src_cidx = 0;
dst_bidx = acnt;
dst_cidx = cidx;
epset->addr = dst_addr;
} else if (direction == DMA_MEM_TO_MEM) {
src_bidx = acnt;
src_cidx = cidx;
dst_bidx = acnt;
dst_cidx = cidx;
} else {
dev_err(dev, "%s: direction not implemented yet\n", __func__);
return -EINVAL;
}
param->opt = EDMA_TCC(EDMA_CHAN_SLOT(echan->ch_num));
if (absync)
param->opt |= SYNCDIM;
param->src = src_addr;
param->dst = dst_addr;
param->src_dst_bidx = (dst_bidx << 16) | src_bidx;
param->src_dst_cidx = (dst_cidx << 16) | src_cidx;
param->a_b_cnt = bcnt << 16 | acnt;
param->ccnt = ccnt;
param->link_bcntrld = 0xffffffff;
return absync;
}
static struct dma_async_tx_descriptor *edma_prep_slave_sg(
struct dma_chan *chan, struct scatterlist *sgl,
unsigned int sg_len, enum dma_transfer_direction direction,
unsigned long tx_flags, void *context)
{
struct edma_chan *echan = to_edma_chan(chan);
struct device *dev = chan->device->dev;
struct edma_desc *edesc;
dma_addr_t src_addr = 0, dst_addr = 0;
enum dma_slave_buswidth dev_width;
u32 burst;
struct scatterlist *sg;
int i, nslots, ret;
if (unlikely(!echan || !sgl || !sg_len))
return NULL;
if (direction == DMA_DEV_TO_MEM) {
src_addr = echan->cfg.src_addr;
dev_width = echan->cfg.src_addr_width;
burst = echan->cfg.src_maxburst;
} else if (direction == DMA_MEM_TO_DEV) {
dst_addr = echan->cfg.dst_addr;
dev_width = echan->cfg.dst_addr_width;
burst = echan->cfg.dst_maxburst;
} else {
dev_err(dev, "%s: bad direction: %d\n", __func__, direction);
return NULL;
}
if (dev_width == DMA_SLAVE_BUSWIDTH_UNDEFINED) {
dev_err(dev, "%s: Undefined slave buswidth\n", __func__);
return NULL;
}
edesc = kzalloc(sizeof(*edesc) + sg_len * sizeof(edesc->pset[0]),
GFP_ATOMIC);
if (!edesc) {
dev_err(dev, "%s: Failed to allocate a descriptor\n", __func__);
return NULL;
}
edesc->pset_nr = sg_len;
edesc->residue = 0;
edesc->direction = direction;
edesc->echan = echan;
nslots = min_t(unsigned, MAX_NR_SG, sg_len);
for (i = 0; i < nslots; i++) {
if (echan->slot[i] < 0) {
echan->slot[i] =
edma_alloc_slot(echan->ecc, EDMA_SLOT_ANY);
if (echan->slot[i] < 0) {
kfree(edesc);
dev_err(dev, "%s: Failed to allocate slot\n",
__func__);
return NULL;
}
}
}
for_each_sg(sgl, sg, sg_len, i) {
if (direction == DMA_DEV_TO_MEM)
dst_addr = sg_dma_address(sg);
else
src_addr = sg_dma_address(sg);
ret = edma_config_pset(chan, &edesc->pset[i], src_addr,
dst_addr, burst, dev_width,
sg_dma_len(sg), direction);
if (ret < 0) {
kfree(edesc);
return NULL;
}
edesc->absync = ret;
edesc->residue += sg_dma_len(sg);
if (!((i+1) % MAX_NR_SG))
edesc->pset[i].param.opt |= TCINTEN;
if (i == sg_len - 1)
edesc->pset[i].param.opt |= TCINTEN;
}
edesc->residue_stat = edesc->residue;
return vchan_tx_prep(&echan->vchan, &edesc->vdesc, tx_flags);
}
static struct dma_async_tx_descriptor *edma_prep_dma_memcpy(
struct dma_chan *chan, dma_addr_t dest, dma_addr_t src,
size_t len, unsigned long tx_flags)
{
int ret, nslots;
struct edma_desc *edesc;
struct device *dev = chan->device->dev;
struct edma_chan *echan = to_edma_chan(chan);
unsigned int width, pset_len;
if (unlikely(!echan || !len))
return NULL;
if (len < SZ_64K) {
width = len;
pset_len = len;
nslots = 1;
} else {
width = SZ_32K - 1;
pset_len = rounddown(len, width);
if (unlikely(pset_len == len))
nslots = 1;
else
nslots = 2;
}
edesc = kzalloc(sizeof(*edesc) + nslots * sizeof(edesc->pset[0]),
GFP_ATOMIC);
if (!edesc) {
dev_dbg(dev, "Failed to allocate a descriptor\n");
return NULL;
}
edesc->pset_nr = nslots;
edesc->residue = edesc->residue_stat = len;
edesc->direction = DMA_MEM_TO_MEM;
edesc->echan = echan;
ret = edma_config_pset(chan, &edesc->pset[0], src, dest, 1,
width, pset_len, DMA_MEM_TO_MEM);
if (ret < 0) {
kfree(edesc);
return NULL;
}
edesc->absync = ret;
edesc->pset[0].param.opt |= ITCCHEN;
if (nslots == 1) {
edesc->pset[0].param.opt |= TCINTEN;
} else {
edesc->pset[0].param.opt |= TCCHEN;
if (echan->slot[1] < 0) {
echan->slot[1] = edma_alloc_slot(echan->ecc,
EDMA_SLOT_ANY);
if (echan->slot[1] < 0) {
kfree(edesc);
dev_err(dev, "%s: Failed to allocate slot\n",
__func__);
return NULL;
}
}
dest += pset_len;
src += pset_len;
pset_len = width = len % (SZ_32K - 1);
ret = edma_config_pset(chan, &edesc->pset[1], src, dest, 1,
width, pset_len, DMA_MEM_TO_MEM);
if (ret < 0) {
kfree(edesc);
return NULL;
}
edesc->pset[1].param.opt |= ITCCHEN;
edesc->pset[1].param.opt |= TCINTEN;
}
return vchan_tx_prep(&echan->vchan, &edesc->vdesc, tx_flags);
}
static struct dma_async_tx_descriptor *edma_prep_dma_cyclic(
struct dma_chan *chan, dma_addr_t buf_addr, size_t buf_len,
size_t period_len, enum dma_transfer_direction direction,
unsigned long tx_flags)
{
struct edma_chan *echan = to_edma_chan(chan);
struct device *dev = chan->device->dev;
struct edma_desc *edesc;
dma_addr_t src_addr, dst_addr;
enum dma_slave_buswidth dev_width;
u32 burst;
int i, ret, nslots;
if (unlikely(!echan || !buf_len || !period_len))
return NULL;
if (direction == DMA_DEV_TO_MEM) {
src_addr = echan->cfg.src_addr;
dst_addr = buf_addr;
dev_width = echan->cfg.src_addr_width;
burst = echan->cfg.src_maxburst;
} else if (direction == DMA_MEM_TO_DEV) {
src_addr = buf_addr;
dst_addr = echan->cfg.dst_addr;
dev_width = echan->cfg.dst_addr_width;
burst = echan->cfg.dst_maxburst;
} else {
dev_err(dev, "%s: bad direction: %d\n", __func__, direction);
return NULL;
}
if (dev_width == DMA_SLAVE_BUSWIDTH_UNDEFINED) {
dev_err(dev, "%s: Undefined slave buswidth\n", __func__);
return NULL;
}
if (unlikely(buf_len % period_len)) {
dev_err(dev, "Period should be multiple of Buffer length\n");
return NULL;
}
nslots = (buf_len / period_len) + 1;
if (nslots > MAX_NR_SG)
return NULL;
edesc = kzalloc(sizeof(*edesc) + nslots * sizeof(edesc->pset[0]),
GFP_ATOMIC);
if (!edesc) {
dev_err(dev, "%s: Failed to allocate a descriptor\n", __func__);
return NULL;
}
edesc->cyclic = 1;
edesc->pset_nr = nslots;
edesc->residue = edesc->residue_stat = buf_len;
edesc->direction = direction;
edesc->echan = echan;
dev_dbg(dev, "%s: channel=%d nslots=%d period_len=%zu buf_len=%zu\n",
__func__, echan->ch_num, nslots, period_len, buf_len);
for (i = 0; i < nslots; i++) {
if (echan->slot[i] < 0) {
echan->slot[i] =
edma_alloc_slot(echan->ecc, EDMA_SLOT_ANY);
if (echan->slot[i] < 0) {
kfree(edesc);
dev_err(dev, "%s: Failed to allocate slot\n",
__func__);
return NULL;
}
}
if (i == nslots - 1) {
memcpy(&edesc->pset[i], &edesc->pset[0],
sizeof(edesc->pset[0]));
break;
}
ret = edma_config_pset(chan, &edesc->pset[i], src_addr,
dst_addr, burst, dev_width, period_len,
direction);
if (ret < 0) {
kfree(edesc);
return NULL;
}
if (direction == DMA_DEV_TO_MEM)
dst_addr += period_len;
else
src_addr += period_len;
dev_vdbg(dev, "%s: Configure period %d of buf:\n", __func__, i);
dev_vdbg(dev,
"\n pset[%d]:\n"
" chnum\t%d\n"
" slot\t%d\n"
" opt\t%08x\n"
" src\t%08x\n"
" dst\t%08x\n"
" abcnt\t%08x\n"
" ccnt\t%08x\n"
" bidx\t%08x\n"
" cidx\t%08x\n"
" lkrld\t%08x\n",
i, echan->ch_num, echan->slot[i],
edesc->pset[i].param.opt,
edesc->pset[i].param.src,
edesc->pset[i].param.dst,
edesc->pset[i].param.a_b_cnt,
edesc->pset[i].param.ccnt,
edesc->pset[i].param.src_dst_bidx,
edesc->pset[i].param.src_dst_cidx,
edesc->pset[i].param.link_bcntrld);
edesc->absync = ret;
if (tx_flags & DMA_PREP_INTERRUPT)
edesc->pset[i].param.opt |= TCINTEN;
}
if (!echan->tc)
edma_assign_channel_eventq(echan, EVENTQ_0);
return vchan_tx_prep(&echan->vchan, &edesc->vdesc, tx_flags);
}
static void edma_completion_handler(struct edma_chan *echan)
{
struct device *dev = echan->vchan.chan.device->dev;
struct edma_desc *edesc = echan->edesc;
if (!edesc)
return;
spin_lock(&echan->vchan.lock);
if (edesc->cyclic) {
vchan_cyclic_callback(&edesc->vdesc);
spin_unlock(&echan->vchan.lock);
return;
} else if (edesc->processed == edesc->pset_nr) {
edesc->residue = 0;
edma_stop(echan);
vchan_cookie_complete(&edesc->vdesc);
echan->edesc = NULL;
dev_dbg(dev, "Transfer completed on channel %d\n",
echan->ch_num);
} else {
dev_dbg(dev, "Sub transfer completed on channel %d\n",
echan->ch_num);
edma_pause(echan);
edesc->residue -= edesc->sg_len;
edesc->residue_stat = edesc->residue;
edesc->processed_stat = edesc->processed;
}
edma_execute(echan);
spin_unlock(&echan->vchan.lock);
}
static irqreturn_t dma_irq_handler(int irq, void *data)
{
struct edma_cc *ecc = data;
int ctlr;
u32 sh_ier;
u32 sh_ipr;
u32 bank;
ctlr = ecc->id;
if (ctlr < 0)
return IRQ_NONE;
dev_vdbg(ecc->dev, "dma_irq_handler\n");
sh_ipr = edma_shadow0_read_array(ecc, SH_IPR, 0);
if (!sh_ipr) {
sh_ipr = edma_shadow0_read_array(ecc, SH_IPR, 1);
if (!sh_ipr)
return IRQ_NONE;
sh_ier = edma_shadow0_read_array(ecc, SH_IER, 1);
bank = 1;
} else {
sh_ier = edma_shadow0_read_array(ecc, SH_IER, 0);
bank = 0;
}
do {
u32 slot;
u32 channel;
slot = __ffs(sh_ipr);
sh_ipr &= ~(BIT(slot));
if (sh_ier & BIT(slot)) {
channel = (bank << 5) | slot;
edma_shadow0_write_array(ecc, SH_ICR, bank, BIT(slot));
edma_completion_handler(&ecc->slave_chans[channel]);
}
} while (sh_ipr);
edma_shadow0_write(ecc, SH_IEVAL, 1);
return IRQ_HANDLED;
}
static void edma_error_handler(struct edma_chan *echan)
{
struct edma_cc *ecc = echan->ecc;
struct device *dev = echan->vchan.chan.device->dev;
struct edmacc_param p;
if (!echan->edesc)
return;
spin_lock(&echan->vchan.lock);
edma_read_slot(ecc, echan->slot[0], &p);
if (p.a_b_cnt == 0 && p.ccnt == 0) {
dev_dbg(dev, "Error on null slot, setting miss\n");
echan->missed = 1;
} else {
dev_dbg(dev, "Missed event, TRIGGERING\n");
edma_clean_channel(echan);
edma_stop(echan);
edma_start(echan);
edma_trigger_channel(echan);
}
spin_unlock(&echan->vchan.lock);
}
static inline bool edma_error_pending(struct edma_cc *ecc)
{
if (edma_read_array(ecc, EDMA_EMR, 0) ||
edma_read_array(ecc, EDMA_EMR, 1) ||
edma_read(ecc, EDMA_QEMR) || edma_read(ecc, EDMA_CCERR))
return true;
return false;
}
static irqreturn_t dma_ccerr_handler(int irq, void *data)
{
struct edma_cc *ecc = data;
int i, j;
int ctlr;
unsigned int cnt = 0;
unsigned int val;
ctlr = ecc->id;
if (ctlr < 0)
return IRQ_NONE;
dev_vdbg(ecc->dev, "dma_ccerr_handler\n");
if (!edma_error_pending(ecc))
return IRQ_NONE;
while (1) {
for (j = 0; j < 2; j++) {
unsigned long emr;
val = edma_read_array(ecc, EDMA_EMR, j);
if (!val)
continue;
dev_dbg(ecc->dev, "EMR%d 0x%08x\n", j, val);
emr = val;
for (i = find_next_bit(&emr, 32, 0); i < 32;
i = find_next_bit(&emr, 32, i + 1)) {
int k = (j << 5) + i;
edma_write_array(ecc, EDMA_EMCR, j, BIT(i));
edma_shadow0_write_array(ecc, SH_SECR, j,
BIT(i));
edma_error_handler(&ecc->slave_chans[k]);
}
}
val = edma_read(ecc, EDMA_QEMR);
if (val) {
dev_dbg(ecc->dev, "QEMR 0x%02x\n", val);
edma_write(ecc, EDMA_QEMCR, val);
edma_shadow0_write(ecc, SH_QSECR, val);
}
val = edma_read(ecc, EDMA_CCERR);
if (val) {
dev_warn(ecc->dev, "CCERR 0x%08x\n", val);
edma_write(ecc, EDMA_CCERRCLR, val);
}
if (!edma_error_pending(ecc))
break;
cnt++;
if (cnt > 10)
break;
}
edma_write(ecc, EDMA_EEVAL, 1);
return IRQ_HANDLED;
}
static void edma_tc_set_pm_state(struct edma_tc *tc, bool enable)
{
struct platform_device *tc_pdev;
int ret;
if (!IS_ENABLED(CONFIG_OF) || !tc)
return;
tc_pdev = of_find_device_by_node(tc->node);
if (!tc_pdev) {
pr_err("%s: TPTC device is not found\n", __func__);
return;
}
if (!pm_runtime_enabled(&tc_pdev->dev))
pm_runtime_enable(&tc_pdev->dev);
if (enable)
ret = pm_runtime_get_sync(&tc_pdev->dev);
else
ret = pm_runtime_put_sync(&tc_pdev->dev);
if (ret < 0)
pr_err("%s: pm_runtime_%s_sync() failed for %s\n", __func__,
enable ? "get" : "put", dev_name(&tc_pdev->dev));
}
static int edma_alloc_chan_resources(struct dma_chan *chan)
{
struct edma_chan *echan = to_edma_chan(chan);
struct edma_cc *ecc = echan->ecc;
struct device *dev = ecc->dev;
enum dma_event_q eventq_no = EVENTQ_DEFAULT;
int ret;
if (echan->tc) {
eventq_no = echan->tc->id;
} else if (ecc->tc_list) {
echan->tc = &ecc->tc_list[ecc->info->default_queue];
eventq_no = echan->tc->id;
}
ret = edma_alloc_channel(echan, eventq_no);
if (ret)
return ret;
echan->slot[0] = edma_alloc_slot(ecc, echan->ch_num);
if (echan->slot[0] < 0) {
dev_err(dev, "Entry slot allocation failed for channel %u\n",
EDMA_CHAN_SLOT(echan->ch_num));
goto err_slot;
}
edma_set_chmap(echan, echan->slot[0]);
echan->alloced = true;
dev_dbg(dev, "Got eDMA channel %d for virt channel %d (%s trigger)\n",
EDMA_CHAN_SLOT(echan->ch_num), chan->chan_id,
echan->hw_triggered ? "HW" : "SW");
edma_tc_set_pm_state(echan->tc, true);
return 0;
err_slot:
edma_free_channel(echan);
return ret;
}
static void edma_free_chan_resources(struct dma_chan *chan)
{
struct edma_chan *echan = to_edma_chan(chan);
struct device *dev = echan->ecc->dev;
int i;
edma_stop(echan);
vchan_free_chan_resources(&echan->vchan);
for (i = 0; i < EDMA_MAX_SLOTS; i++) {
if (echan->slot[i] >= 0) {
edma_free_slot(echan->ecc, echan->slot[i]);
echan->slot[i] = -1;
}
}
edma_set_chmap(echan, echan->ecc->dummy_slot);
if (echan->alloced) {
edma_free_channel(echan);
echan->alloced = false;
}
edma_tc_set_pm_state(echan->tc, false);
echan->tc = NULL;
echan->hw_triggered = false;
dev_dbg(dev, "Free eDMA channel %d for virt channel %d\n",
EDMA_CHAN_SLOT(echan->ch_num), chan->chan_id);
}
static void edma_issue_pending(struct dma_chan *chan)
{
struct edma_chan *echan = to_edma_chan(chan);
unsigned long flags;
spin_lock_irqsave(&echan->vchan.lock, flags);
if (vchan_issue_pending(&echan->vchan) && !echan->edesc)
edma_execute(echan);
spin_unlock_irqrestore(&echan->vchan.lock, flags);
}
static u32 edma_residue(struct edma_desc *edesc)
{
bool dst = edesc->direction == DMA_DEV_TO_MEM;
int loop_count = EDMA_MAX_TR_WAIT_LOOPS;
struct edma_chan *echan = edesc->echan;
struct edma_pset *pset = edesc->pset;
dma_addr_t done, pos;
int i;
pos = edma_get_position(echan->ecc, echan->slot[0], dst);
while (edma_read(echan->ecc, EDMA_CCSTAT) & EDMA_CCSTAT_ACTV) {
if (edma_get_position(echan->ecc,
echan->slot[0], dst) != pos) {
break;
}
if (!--loop_count) {
dev_dbg_ratelimited(echan->vchan.chan.device->dev,
"%s: timeout waiting for PaRAM update\n",
__func__);
break;
}
cpu_relax();
}
if (edesc->cyclic) {
done = pos - pset->addr;
edesc->residue_stat = edesc->residue - done;
return edesc->residue_stat;
}
pset += edesc->processed_stat;
for (i = edesc->processed_stat; i < edesc->processed; i++, pset++) {
if (pos >= pset->addr && pos < pset->addr + pset->len)
return edesc->residue_stat - (pos - pset->addr);
edesc->processed_stat++;
edesc->residue_stat -= pset->len;
}
return edesc->residue_stat;
}
static enum dma_status edma_tx_status(struct dma_chan *chan,
dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
struct edma_chan *echan = to_edma_chan(chan);
struct virt_dma_desc *vdesc;
enum dma_status ret;
unsigned long flags;
ret = dma_cookie_status(chan, cookie, txstate);
if (ret == DMA_COMPLETE || !txstate)
return ret;
spin_lock_irqsave(&echan->vchan.lock, flags);
if (echan->edesc && echan->edesc->vdesc.tx.cookie == cookie)
txstate->residue = edma_residue(echan->edesc);
else if ((vdesc = vchan_find_desc(&echan->vchan, cookie)))
txstate->residue = to_edma_desc(&vdesc->tx)->residue;
spin_unlock_irqrestore(&echan->vchan.lock, flags);
return ret;
}
static bool edma_is_memcpy_channel(int ch_num, s32 *memcpy_channels)
{
if (!memcpy_channels)
return false;
while (*memcpy_channels != -1) {
if (*memcpy_channels == ch_num)
return true;
memcpy_channels++;
}
return false;
}
static void edma_dma_init(struct edma_cc *ecc, bool legacy_mode)
{
struct dma_device *s_ddev = &ecc->dma_slave;
struct dma_device *m_ddev = NULL;
s32 *memcpy_channels = ecc->info->memcpy_channels;
int i, j;
dma_cap_zero(s_ddev->cap_mask);
dma_cap_set(DMA_SLAVE, s_ddev->cap_mask);
dma_cap_set(DMA_CYCLIC, s_ddev->cap_mask);
if (ecc->legacy_mode && !memcpy_channels) {
dev_warn(ecc->dev,
"Legacy memcpy is enabled, things might not work\n");
dma_cap_set(DMA_MEMCPY, s_ddev->cap_mask);
s_ddev->device_prep_dma_memcpy = edma_prep_dma_memcpy;
s_ddev->directions = BIT(DMA_MEM_TO_MEM);
}
s_ddev->device_prep_slave_sg = edma_prep_slave_sg;
s_ddev->device_prep_dma_cyclic = edma_prep_dma_cyclic;
s_ddev->device_alloc_chan_resources = edma_alloc_chan_resources;
s_ddev->device_free_chan_resources = edma_free_chan_resources;
s_ddev->device_issue_pending = edma_issue_pending;
s_ddev->device_tx_status = edma_tx_status;
s_ddev->device_config = edma_slave_config;
s_ddev->device_pause = edma_dma_pause;
s_ddev->device_resume = edma_dma_resume;
s_ddev->device_terminate_all = edma_terminate_all;
s_ddev->src_addr_widths = EDMA_DMA_BUSWIDTHS;
s_ddev->dst_addr_widths = EDMA_DMA_BUSWIDTHS;
s_ddev->directions |= (BIT(DMA_DEV_TO_MEM) | BIT(DMA_MEM_TO_DEV));
s_ddev->residue_granularity = DMA_RESIDUE_GRANULARITY_BURST;
s_ddev->dev = ecc->dev;
INIT_LIST_HEAD(&s_ddev->channels);
if (memcpy_channels) {
m_ddev = devm_kzalloc(ecc->dev, sizeof(*m_ddev), GFP_KERNEL);
ecc->dma_memcpy = m_ddev;
dma_cap_zero(m_ddev->cap_mask);
dma_cap_set(DMA_MEMCPY, m_ddev->cap_mask);
m_ddev->device_prep_dma_memcpy = edma_prep_dma_memcpy;
m_ddev->device_alloc_chan_resources = edma_alloc_chan_resources;
m_ddev->device_free_chan_resources = edma_free_chan_resources;
m_ddev->device_issue_pending = edma_issue_pending;
m_ddev->device_tx_status = edma_tx_status;
m_ddev->device_config = edma_slave_config;
m_ddev->device_pause = edma_dma_pause;
m_ddev->device_resume = edma_dma_resume;
m_ddev->device_terminate_all = edma_terminate_all;
m_ddev->src_addr_widths = EDMA_DMA_BUSWIDTHS;
m_ddev->dst_addr_widths = EDMA_DMA_BUSWIDTHS;
m_ddev->directions = BIT(DMA_MEM_TO_MEM);
m_ddev->residue_granularity = DMA_RESIDUE_GRANULARITY_BURST;
m_ddev->dev = ecc->dev;
INIT_LIST_HEAD(&m_ddev->channels);
} else if (!ecc->legacy_mode) {
dev_info(ecc->dev, "memcpy is disabled\n");
}
for (i = 0; i < ecc->num_channels; i++) {
struct edma_chan *echan = &ecc->slave_chans[i];
echan->ch_num = EDMA_CTLR_CHAN(ecc->id, i);
echan->ecc = ecc;
echan->vchan.desc_free = edma_desc_free;
if (m_ddev && edma_is_memcpy_channel(i, memcpy_channels))
vchan_init(&echan->vchan, m_ddev);
else
vchan_init(&echan->vchan, s_ddev);
INIT_LIST_HEAD(&echan->node);
for (j = 0; j < EDMA_MAX_SLOTS; j++)
echan->slot[j] = -1;
}
}
static int edma_setup_from_hw(struct device *dev, struct edma_soc_info *pdata,
struct edma_cc *ecc)
{
int i;
u32 value, cccfg;
s8 (*queue_priority_map)[2];
cccfg = edma_read(ecc, EDMA_CCCFG);
value = GET_NUM_REGN(cccfg);
ecc->num_region = BIT(value);
value = GET_NUM_DMACH(cccfg);
ecc->num_channels = BIT(value + 1);
value = GET_NUM_QDMACH(cccfg);
ecc->num_qchannels = value * 2;
value = GET_NUM_PAENTRY(cccfg);
ecc->num_slots = BIT(value + 4);
value = GET_NUM_EVQUE(cccfg);
ecc->num_tc = value + 1;
ecc->chmap_exist = (cccfg & CHMAP_EXIST) ? true : false;
dev_dbg(dev, "eDMA3 CC HW configuration (cccfg: 0x%08x):\n", cccfg);
dev_dbg(dev, "num_region: %u\n", ecc->num_region);
dev_dbg(dev, "num_channels: %u\n", ecc->num_channels);
dev_dbg(dev, "num_qchannels: %u\n", ecc->num_qchannels);
dev_dbg(dev, "num_slots: %u\n", ecc->num_slots);
dev_dbg(dev, "num_tc: %u\n", ecc->num_tc);
dev_dbg(dev, "chmap_exist: %s\n", ecc->chmap_exist ? "yes" : "no");
if (pdata->queue_priority_mapping)
return 0;
queue_priority_map = devm_kcalloc(dev, ecc->num_tc + 1, sizeof(s8),
GFP_KERNEL);
if (!queue_priority_map)
return -ENOMEM;
for (i = 0; i < ecc->num_tc; i++) {
queue_priority_map[i][0] = i;
queue_priority_map[i][1] = i;
}
queue_priority_map[i][0] = -1;
queue_priority_map[i][1] = -1;
pdata->queue_priority_mapping = queue_priority_map;
pdata->default_queue = i - 1;
return 0;
}
static int edma_xbar_event_map(struct device *dev, struct edma_soc_info *pdata,
size_t sz)
{
const char pname[] = "ti,edma-xbar-event-map";
struct resource res;
void __iomem *xbar;
s16 (*xbar_chans)[2];
size_t nelm = sz / sizeof(s16);
u32 shift, offset, mux;
int ret, i;
xbar_chans = devm_kcalloc(dev, nelm + 2, sizeof(s16), GFP_KERNEL);
if (!xbar_chans)
return -ENOMEM;
ret = of_address_to_resource(dev->of_node, 1, &res);
if (ret)
return -ENOMEM;
xbar = devm_ioremap(dev, res.start, resource_size(&res));
if (!xbar)
return -ENOMEM;
ret = of_property_read_u16_array(dev->of_node, pname, (u16 *)xbar_chans,
nelm);
if (ret)
return -EIO;
nelm >>= 1;
xbar_chans[nelm][0] = -1;
xbar_chans[nelm][1] = -1;
for (i = 0; i < nelm; i++) {
shift = (xbar_chans[i][1] & 0x03) << 3;
offset = xbar_chans[i][1] & 0xfffffffc;
mux = readl(xbar + offset);
mux &= ~(0xff << shift);
mux |= xbar_chans[i][0] << shift;
writel(mux, (xbar + offset));
}
pdata->xbar_chans = (const s16 (*)[2]) xbar_chans;
return 0;
}
static struct edma_soc_info *edma_setup_info_from_dt(struct device *dev,
bool legacy_mode)
{
struct edma_soc_info *info;
struct property *prop;
size_t sz;
int ret;
info = devm_kzalloc(dev, sizeof(struct edma_soc_info), GFP_KERNEL);
if (!info)
return ERR_PTR(-ENOMEM);
if (legacy_mode) {
prop = of_find_property(dev->of_node, "ti,edma-xbar-event-map",
&sz);
if (prop) {
ret = edma_xbar_event_map(dev, info, sz);
if (ret)
return ERR_PTR(ret);
}
return info;
}
prop = of_find_property(dev->of_node, "ti,edma-memcpy-channels", &sz);
if (prop) {
const char pname[] = "ti,edma-memcpy-channels";
size_t nelm = sz / sizeof(s32);
s32 *memcpy_ch;
memcpy_ch = devm_kcalloc(dev, nelm + 1, sizeof(s32),
GFP_KERNEL);
if (!memcpy_ch)
return ERR_PTR(-ENOMEM);
ret = of_property_read_u32_array(dev->of_node, pname,
(u32 *)memcpy_ch, nelm);
if (ret)
return ERR_PTR(ret);
memcpy_ch[nelm] = -1;
info->memcpy_channels = memcpy_ch;
}
prop = of_find_property(dev->of_node, "ti,edma-reserved-slot-ranges",
&sz);
if (prop) {
const char pname[] = "ti,edma-reserved-slot-ranges";
u32 (*tmp)[2];
s16 (*rsv_slots)[2];
size_t nelm = sz / sizeof(*tmp);
struct edma_rsv_info *rsv_info;
int i;
if (!nelm)
return info;
tmp = kcalloc(nelm, sizeof(*tmp), GFP_KERNEL);
if (!tmp)
return ERR_PTR(-ENOMEM);
rsv_info = devm_kzalloc(dev, sizeof(*rsv_info), GFP_KERNEL);
if (!rsv_info) {
kfree(tmp);
return ERR_PTR(-ENOMEM);
}
rsv_slots = devm_kcalloc(dev, nelm + 1, sizeof(*rsv_slots),
GFP_KERNEL);
if (!rsv_slots) {
kfree(tmp);
return ERR_PTR(-ENOMEM);
}
ret = of_property_read_u32_array(dev->of_node, pname,
(u32 *)tmp, nelm * 2);
if (ret) {
kfree(tmp);
return ERR_PTR(ret);
}
for (i = 0; i < nelm; i++) {
rsv_slots[i][0] = tmp[i][0];
rsv_slots[i][1] = tmp[i][1];
}
rsv_slots[nelm][0] = -1;
rsv_slots[nelm][1] = -1;
info->rsv = rsv_info;
info->rsv->rsv_slots = (const s16 (*)[2])rsv_slots;
kfree(tmp);
}
return info;
}
static struct dma_chan *of_edma_xlate(struct of_phandle_args *dma_spec,
struct of_dma *ofdma)
{
struct edma_cc *ecc = ofdma->of_dma_data;
struct dma_chan *chan = NULL;
struct edma_chan *echan;
int i;
if (!ecc || dma_spec->args_count < 1)
return NULL;
for (i = 0; i < ecc->num_channels; i++) {
echan = &ecc->slave_chans[i];
if (echan->ch_num == dma_spec->args[0]) {
chan = &echan->vchan.chan;
break;
}
}
if (!chan)
return NULL;
if (echan->ecc->legacy_mode && dma_spec->args_count == 1)
goto out;
if (!echan->ecc->legacy_mode && dma_spec->args_count == 2 &&
dma_spec->args[1] < echan->ecc->num_tc) {
echan->tc = &echan->ecc->tc_list[dma_spec->args[1]];
goto out;
}
return NULL;
out:
echan->hw_triggered = true;
return dma_get_slave_channel(chan);
}
static struct edma_soc_info *edma_setup_info_from_dt(struct device *dev,
bool legacy_mode)
{
return ERR_PTR(-EINVAL);
}
static struct dma_chan *of_edma_xlate(struct of_phandle_args *dma_spec,
struct of_dma *ofdma)
{
return NULL;
}
static int edma_probe(struct platform_device *pdev)
{
struct edma_soc_info *info = pdev->dev.platform_data;
s8 (*queue_priority_mapping)[2];
int i, off, ln;
const s16 (*rsv_slots)[2];
const s16 (*xbar_chans)[2];
int irq;
char *irq_name;
struct resource *mem;
struct device_node *node = pdev->dev.of_node;
struct device *dev = &pdev->dev;
struct edma_cc *ecc;
bool legacy_mode = true;
int ret;
if (node) {
const struct of_device_id *match;
match = of_match_node(edma_of_ids, node);
if (match && (u32)match->data == EDMA_BINDING_TPCC)
legacy_mode = false;
info = edma_setup_info_from_dt(dev, legacy_mode);
if (IS_ERR(info)) {
dev_err(dev, "failed to get DT data\n");
return PTR_ERR(info);
}
}
if (!info)
return -ENODEV;
pm_runtime_enable(dev);
ret = pm_runtime_get_sync(dev);
if (ret < 0) {
dev_err(dev, "pm_runtime_get_sync() failed\n");
return ret;
}
ret = dma_set_mask_and_coherent(dev, DMA_BIT_MASK(32));
if (ret)
return ret;
ecc = devm_kzalloc(dev, sizeof(*ecc), GFP_KERNEL);
if (!ecc) {
dev_err(dev, "Can't allocate controller\n");
return -ENOMEM;
}
ecc->dev = dev;
ecc->id = pdev->id;
ecc->legacy_mode = legacy_mode;
if (ecc->id < 0)
ecc->id = 0;
mem = platform_get_resource_byname(pdev, IORESOURCE_MEM, "edma3_cc");
if (!mem) {
dev_dbg(dev, "mem resource not found, using index 0\n");
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(dev, "no mem resource?\n");
return -ENODEV;
}
}
ecc->base = devm_ioremap_resource(dev, mem);
if (IS_ERR(ecc->base))
return PTR_ERR(ecc->base);
platform_set_drvdata(pdev, ecc);
ret = edma_setup_from_hw(dev, info, ecc);
if (ret)
return ret;
ecc->slave_chans = devm_kcalloc(dev, ecc->num_channels,
sizeof(*ecc->slave_chans), GFP_KERNEL);
if (!ecc->slave_chans)
return -ENOMEM;
ecc->slot_inuse = devm_kcalloc(dev, BITS_TO_LONGS(ecc->num_slots),
sizeof(unsigned long), GFP_KERNEL);
if (!ecc->slot_inuse)
return -ENOMEM;
ecc->default_queue = info->default_queue;
for (i = 0; i < ecc->num_slots; i++)
edma_write_slot(ecc, i, &dummy_paramset);
if (info->rsv) {
rsv_slots = info->rsv->rsv_slots;
if (rsv_slots) {
for (i = 0; rsv_slots[i][0] != -1; i++) {
off = rsv_slots[i][0];
ln = rsv_slots[i][1];
set_bits(off, ln, ecc->slot_inuse);
}
}
}
xbar_chans = info->xbar_chans;
if (xbar_chans) {
for (i = 0; xbar_chans[i][1] != -1; i++) {
off = xbar_chans[i][1];
}
}
irq = platform_get_irq_byname(pdev, "edma3_ccint");
if (irq < 0 && node)
irq = irq_of_parse_and_map(node, 0);
if (irq >= 0) {
irq_name = devm_kasprintf(dev, GFP_KERNEL, "%s_ccint",
dev_name(dev));
ret = devm_request_irq(dev, irq, dma_irq_handler, 0, irq_name,
ecc);
if (ret) {
dev_err(dev, "CCINT (%d) failed --> %d\n", irq, ret);
return ret;
}
}
irq = platform_get_irq_byname(pdev, "edma3_ccerrint");
if (irq < 0 && node)
irq = irq_of_parse_and_map(node, 2);
if (irq >= 0) {
irq_name = devm_kasprintf(dev, GFP_KERNEL, "%s_ccerrint",
dev_name(dev));
ret = devm_request_irq(dev, irq, dma_ccerr_handler, 0, irq_name,
ecc);
if (ret) {
dev_err(dev, "CCERRINT (%d) failed --> %d\n", irq, ret);
return ret;
}
}
ecc->dummy_slot = edma_alloc_slot(ecc, EDMA_SLOT_ANY);
if (ecc->dummy_slot < 0) {
dev_err(dev, "Can't allocate PaRAM dummy slot\n");
return ecc->dummy_slot;
}
queue_priority_mapping = info->queue_priority_mapping;
if (!ecc->legacy_mode) {
int lowest_priority = 0;
struct of_phandle_args tc_args;
ecc->tc_list = devm_kcalloc(dev, ecc->num_tc,
sizeof(*ecc->tc_list), GFP_KERNEL);
if (!ecc->tc_list)
return -ENOMEM;
for (i = 0;; i++) {
ret = of_parse_phandle_with_fixed_args(node, "ti,tptcs",
1, i, &tc_args);
if (ret || i == ecc->num_tc)
break;
ecc->tc_list[i].node = tc_args.np;
ecc->tc_list[i].id = i;
queue_priority_mapping[i][1] = tc_args.args[0];
if (queue_priority_mapping[i][1] > lowest_priority) {
lowest_priority = queue_priority_mapping[i][1];
info->default_queue = i;
}
}
}
for (i = 0; queue_priority_mapping[i][0] != -1; i++)
edma_assign_priority_to_queue(ecc, queue_priority_mapping[i][0],
queue_priority_mapping[i][1]);
for (i = 0; i < ecc->num_region; i++) {
edma_write_array2(ecc, EDMA_DRAE, i, 0, 0x0);
edma_write_array2(ecc, EDMA_DRAE, i, 1, 0x0);
edma_write_array(ecc, EDMA_QRAE, i, 0x0);
}
ecc->info = info;
edma_dma_init(ecc, legacy_mode);
for (i = 0; i < ecc->num_channels; i++) {
edma_assign_channel_eventq(&ecc->slave_chans[i],
info->default_queue);
edma_set_chmap(&ecc->slave_chans[i], ecc->dummy_slot);
}
ecc->dma_slave.filter.map = info->slave_map;
ecc->dma_slave.filter.mapcnt = info->slavecnt;
ecc->dma_slave.filter.fn = edma_filter_fn;
ret = dma_async_device_register(&ecc->dma_slave);
if (ret) {
dev_err(dev, "slave ddev registration failed (%d)\n", ret);
goto err_reg1;
}
if (ecc->dma_memcpy) {
ret = dma_async_device_register(ecc->dma_memcpy);
if (ret) {
dev_err(dev, "memcpy ddev registration failed (%d)\n",
ret);
dma_async_device_unregister(&ecc->dma_slave);
goto err_reg1;
}
}
if (node)
of_dma_controller_register(node, of_edma_xlate, ecc);
dev_info(dev, "TI EDMA DMA engine driver\n");
return 0;
err_reg1:
edma_free_slot(ecc, ecc->dummy_slot);
return ret;
}
static int edma_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct edma_cc *ecc = dev_get_drvdata(dev);
if (dev->of_node)
of_dma_controller_free(dev->of_node);
dma_async_device_unregister(&ecc->dma_slave);
if (ecc->dma_memcpy)
dma_async_device_unregister(ecc->dma_memcpy);
edma_free_slot(ecc, ecc->dummy_slot);
return 0;
}
static int edma_pm_suspend(struct device *dev)
{
struct edma_cc *ecc = dev_get_drvdata(dev);
struct edma_chan *echan = ecc->slave_chans;
int i;
for (i = 0; i < ecc->num_channels; i++) {
if (echan[i].alloced) {
edma_setup_interrupt(&echan[i], false);
edma_tc_set_pm_state(echan[i].tc, false);
}
}
return 0;
}
static int edma_pm_resume(struct device *dev)
{
struct edma_cc *ecc = dev_get_drvdata(dev);
struct edma_chan *echan = ecc->slave_chans;
int i;
s8 (*queue_priority_mapping)[2];
queue_priority_mapping = ecc->info->queue_priority_mapping;
for (i = 0; queue_priority_mapping[i][0] != -1; i++)
edma_assign_priority_to_queue(ecc, queue_priority_mapping[i][0],
queue_priority_mapping[i][1]);
for (i = 0; i < ecc->num_channels; i++) {
if (echan[i].alloced) {
edma_or_array2(ecc, EDMA_DRAE, 0, i >> 5,
BIT(i & 0x1f));
edma_setup_interrupt(&echan[i], true);
edma_set_chmap(&echan[i], echan[i].slot[0]);
edma_tc_set_pm_state(echan[i].tc, true);
}
}
return 0;
}
static int edma_tptc_probe(struct platform_device *pdev)
{
return 0;
}
bool edma_filter_fn(struct dma_chan *chan, void *param)
{
bool match = false;
if (chan->device->dev->driver == &edma_driver.driver) {
struct edma_chan *echan = to_edma_chan(chan);
unsigned ch_req = *(unsigned *)param;
if (ch_req == echan->ch_num) {
echan->hw_triggered = true;
match = true;
}
}
return match;
}
static int edma_init(void)
{
int ret;
ret = platform_driver_register(&edma_tptc_driver);
if (ret)
return ret;
return platform_driver_register(&edma_driver);
}
static void __exit edma_exit(void)
{
platform_driver_unregister(&edma_driver);
platform_driver_unregister(&edma_tptc_driver);
}
