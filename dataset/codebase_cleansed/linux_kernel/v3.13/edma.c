static inline unsigned int edma_read(unsigned ctlr, int offset)
{
return (unsigned int)__raw_readl(edmacc_regs_base[ctlr] + offset);
}
static inline void edma_write(unsigned ctlr, int offset, int val)
{
__raw_writel(val, edmacc_regs_base[ctlr] + offset);
}
static inline void edma_modify(unsigned ctlr, int offset, unsigned and,
unsigned or)
{
unsigned val = edma_read(ctlr, offset);
val &= and;
val |= or;
edma_write(ctlr, offset, val);
}
static inline void edma_and(unsigned ctlr, int offset, unsigned and)
{
unsigned val = edma_read(ctlr, offset);
val &= and;
edma_write(ctlr, offset, val);
}
static inline void edma_or(unsigned ctlr, int offset, unsigned or)
{
unsigned val = edma_read(ctlr, offset);
val |= or;
edma_write(ctlr, offset, val);
}
static inline unsigned int edma_read_array(unsigned ctlr, int offset, int i)
{
return edma_read(ctlr, offset + (i << 2));
}
static inline void edma_write_array(unsigned ctlr, int offset, int i,
unsigned val)
{
edma_write(ctlr, offset + (i << 2), val);
}
static inline void edma_modify_array(unsigned ctlr, int offset, int i,
unsigned and, unsigned or)
{
edma_modify(ctlr, offset + (i << 2), and, or);
}
static inline void edma_or_array(unsigned ctlr, int offset, int i, unsigned or)
{
edma_or(ctlr, offset + (i << 2), or);
}
static inline void edma_or_array2(unsigned ctlr, int offset, int i, int j,
unsigned or)
{
edma_or(ctlr, offset + ((i*2 + j) << 2), or);
}
static inline void edma_write_array2(unsigned ctlr, int offset, int i, int j,
unsigned val)
{
edma_write(ctlr, offset + ((i*2 + j) << 2), val);
}
static inline unsigned int edma_shadow0_read(unsigned ctlr, int offset)
{
return edma_read(ctlr, EDMA_SHADOW0 + offset);
}
static inline unsigned int edma_shadow0_read_array(unsigned ctlr, int offset,
int i)
{
return edma_read(ctlr, EDMA_SHADOW0 + offset + (i << 2));
}
static inline void edma_shadow0_write(unsigned ctlr, int offset, unsigned val)
{
edma_write(ctlr, EDMA_SHADOW0 + offset, val);
}
static inline void edma_shadow0_write_array(unsigned ctlr, int offset, int i,
unsigned val)
{
edma_write(ctlr, EDMA_SHADOW0 + offset + (i << 2), val);
}
static inline unsigned int edma_parm_read(unsigned ctlr, int offset,
int param_no)
{
return edma_read(ctlr, EDMA_PARM + offset + (param_no << 5));
}
static inline void edma_parm_write(unsigned ctlr, int offset, int param_no,
unsigned val)
{
edma_write(ctlr, EDMA_PARM + offset + (param_no << 5), val);
}
static inline void edma_parm_modify(unsigned ctlr, int offset, int param_no,
unsigned and, unsigned or)
{
edma_modify(ctlr, EDMA_PARM + offset + (param_no << 5), and, or);
}
static inline void edma_parm_and(unsigned ctlr, int offset, int param_no,
unsigned and)
{
edma_and(ctlr, EDMA_PARM + offset + (param_no << 5), and);
}
static inline void edma_parm_or(unsigned ctlr, int offset, int param_no,
unsigned or)
{
edma_or(ctlr, EDMA_PARM + offset + (param_no << 5), or);
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
static void map_dmach_queue(unsigned ctlr, unsigned ch_no,
enum dma_event_q queue_no)
{
int bit = (ch_no & 0x7) * 4;
if (queue_no == EVENTQ_DEFAULT)
queue_no = edma_cc[ctlr]->default_queue;
queue_no &= 7;
edma_modify_array(ctlr, EDMA_DMAQNUM, (ch_no >> 3),
~(0x7 << bit), queue_no << bit);
}
static void __init map_queue_tc(unsigned ctlr, int queue_no, int tc_no)
{
int bit = queue_no * 4;
edma_modify(ctlr, EDMA_QUETCMAP, ~(0x7 << bit), ((tc_no & 0x7) << bit));
}
static void __init assign_priority_to_queue(unsigned ctlr, int queue_no,
int priority)
{
int bit = queue_no * 4;
edma_modify(ctlr, EDMA_QUEPRI, ~(0x7 << bit),
((priority & 0x7) << bit));
}
static void __init map_dmach_param(unsigned ctlr)
{
int i;
for (i = 0; i < EDMA_MAX_DMACH; i++)
edma_write_array(ctlr, EDMA_DCHMAP , i , (i << 5));
}
static inline void
setup_dma_interrupt(unsigned lch,
void (*callback)(unsigned channel, u16 ch_status, void *data),
void *data)
{
unsigned ctlr;
ctlr = EDMA_CTLR(lch);
lch = EDMA_CHAN_SLOT(lch);
if (!callback)
edma_shadow0_write_array(ctlr, SH_IECR, lch >> 5,
BIT(lch & 0x1f));
edma_cc[ctlr]->intr_data[lch].callback = callback;
edma_cc[ctlr]->intr_data[lch].data = data;
if (callback) {
edma_shadow0_write_array(ctlr, SH_ICR, lch >> 5,
BIT(lch & 0x1f));
edma_shadow0_write_array(ctlr, SH_IESR, lch >> 5,
BIT(lch & 0x1f));
}
}
static int irq2ctlr(int irq)
{
if (irq >= edma_cc[0]->irq_res_start && irq <= edma_cc[0]->irq_res_end)
return 0;
else if (irq >= edma_cc[1]->irq_res_start &&
irq <= edma_cc[1]->irq_res_end)
return 1;
return -1;
}
static irqreturn_t dma_irq_handler(int irq, void *data)
{
int ctlr;
u32 sh_ier;
u32 sh_ipr;
u32 bank;
ctlr = irq2ctlr(irq);
if (ctlr < 0)
return IRQ_NONE;
dev_dbg(data, "dma_irq_handler\n");
sh_ipr = edma_shadow0_read_array(ctlr, SH_IPR, 0);
if (!sh_ipr) {
sh_ipr = edma_shadow0_read_array(ctlr, SH_IPR, 1);
if (!sh_ipr)
return IRQ_NONE;
sh_ier = edma_shadow0_read_array(ctlr, SH_IER, 1);
bank = 1;
} else {
sh_ier = edma_shadow0_read_array(ctlr, SH_IER, 0);
bank = 0;
}
do {
u32 slot;
u32 channel;
dev_dbg(data, "IPR%d %08x\n", bank, sh_ipr);
slot = __ffs(sh_ipr);
sh_ipr &= ~(BIT(slot));
if (sh_ier & BIT(slot)) {
channel = (bank << 5) | slot;
edma_shadow0_write_array(ctlr, SH_ICR, bank,
BIT(slot));
if (edma_cc[ctlr]->intr_data[channel].callback)
edma_cc[ctlr]->intr_data[channel].callback(
channel, EDMA_DMA_COMPLETE,
edma_cc[ctlr]->intr_data[channel].data);
}
} while (sh_ipr);
edma_shadow0_write(ctlr, SH_IEVAL, 1);
return IRQ_HANDLED;
}
static irqreturn_t dma_ccerr_handler(int irq, void *data)
{
int i;
int ctlr;
unsigned int cnt = 0;
ctlr = irq2ctlr(irq);
if (ctlr < 0)
return IRQ_NONE;
dev_dbg(data, "dma_ccerr_handler\n");
if ((edma_read_array(ctlr, EDMA_EMR, 0) == 0) &&
(edma_read_array(ctlr, EDMA_EMR, 1) == 0) &&
(edma_read(ctlr, EDMA_QEMR) == 0) &&
(edma_read(ctlr, EDMA_CCERR) == 0))
return IRQ_NONE;
while (1) {
int j = -1;
if (edma_read_array(ctlr, EDMA_EMR, 0))
j = 0;
else if (edma_read_array(ctlr, EDMA_EMR, 1))
j = 1;
if (j >= 0) {
dev_dbg(data, "EMR%d %08x\n", j,
edma_read_array(ctlr, EDMA_EMR, j));
for (i = 0; i < 32; i++) {
int k = (j << 5) + i;
if (edma_read_array(ctlr, EDMA_EMR, j) &
BIT(i)) {
edma_write_array(ctlr, EDMA_EMCR, j,
BIT(i));
edma_shadow0_write_array(ctlr, SH_SECR,
j, BIT(i));
if (edma_cc[ctlr]->intr_data[k].
callback) {
edma_cc[ctlr]->intr_data[k].
callback(k,
EDMA_DMA_CC_ERROR,
edma_cc[ctlr]->intr_data
[k].data);
}
}
}
} else if (edma_read(ctlr, EDMA_QEMR)) {
dev_dbg(data, "QEMR %02x\n",
edma_read(ctlr, EDMA_QEMR));
for (i = 0; i < 8; i++) {
if (edma_read(ctlr, EDMA_QEMR) & BIT(i)) {
edma_write(ctlr, EDMA_QEMCR, BIT(i));
edma_shadow0_write(ctlr, SH_QSECR,
BIT(i));
}
}
} else if (edma_read(ctlr, EDMA_CCERR)) {
dev_dbg(data, "CCERR %08x\n",
edma_read(ctlr, EDMA_CCERR));
for (i = 0; i < 8; i++) {
if (edma_read(ctlr, EDMA_CCERR) & BIT(i)) {
edma_write(ctlr, EDMA_CCERRCLR, BIT(i));
}
}
}
if ((edma_read_array(ctlr, EDMA_EMR, 0) == 0) &&
(edma_read_array(ctlr, EDMA_EMR, 1) == 0) &&
(edma_read(ctlr, EDMA_QEMR) == 0) &&
(edma_read(ctlr, EDMA_CCERR) == 0))
break;
cnt++;
if (cnt > 10)
break;
}
edma_write(ctlr, EDMA_EEVAL, 1);
return IRQ_HANDLED;
}
static int reserve_contiguous_slots(int ctlr, unsigned int id,
unsigned int num_slots,
unsigned int start_slot)
{
int i, j;
unsigned int count = num_slots;
int stop_slot = start_slot;
DECLARE_BITMAP(tmp_inuse, EDMA_MAX_PARAMENTRY);
for (i = start_slot; i < edma_cc[ctlr]->num_slots; ++i) {
j = EDMA_CHAN_SLOT(i);
if (!test_and_set_bit(j, edma_cc[ctlr]->edma_inuse)) {
if (count == num_slots)
stop_slot = i;
count--;
set_bit(j, tmp_inuse);
if (count == 0)
break;
} else {
clear_bit(j, tmp_inuse);
if (id == EDMA_CONT_PARAMS_FIXED_EXACT) {
stop_slot = i;
break;
} else {
count = num_slots;
}
}
}
if (i == edma_cc[ctlr]->num_slots)
stop_slot = i;
j = start_slot;
for_each_set_bit_from(j, tmp_inuse, stop_slot)
clear_bit(j, edma_cc[ctlr]->edma_inuse);
if (count)
return -EBUSY;
for (j = i - num_slots + 1; j <= i; ++j)
memcpy_toio(edmacc_regs_base[ctlr] + PARM_OFFSET(j),
&dummy_paramset, PARM_SIZE);
return EDMA_CTLR_CHAN(ctlr, i - num_slots + 1);
}
static int prepare_unused_channel_list(struct device *dev, void *data)
{
struct platform_device *pdev = to_platform_device(dev);
int i, count, ctlr;
struct of_phandle_args dma_spec;
if (dev->of_node) {
count = of_property_count_strings(dev->of_node, "dma-names");
if (count < 0)
return 0;
for (i = 0; i < count; i++) {
if (of_parse_phandle_with_args(dev->of_node, "dmas",
"#dma-cells", i,
&dma_spec))
continue;
if (!of_match_node(edma_of_ids, dma_spec.np)) {
of_node_put(dma_spec.np);
continue;
}
clear_bit(EDMA_CHAN_SLOT(dma_spec.args[0]),
edma_cc[0]->edma_unused);
of_node_put(dma_spec.np);
}
return 0;
}
for (i = 0; i < pdev->num_resources; i++) {
if ((pdev->resource[i].flags & IORESOURCE_DMA) &&
(int)pdev->resource[i].start >= 0) {
ctlr = EDMA_CTLR(pdev->resource[i].start);
clear_bit(EDMA_CHAN_SLOT(pdev->resource[i].start),
edma_cc[ctlr]->edma_unused);
}
}
return 0;
}
int edma_alloc_channel(int channel,
void (*callback)(unsigned channel, u16 ch_status, void *data),
void *data,
enum dma_event_q eventq_no)
{
unsigned i, done = 0, ctlr = 0;
int ret = 0;
if (!unused_chan_list_done) {
ret = bus_for_each_dev(&platform_bus_type, NULL, NULL,
prepare_unused_channel_list);
if (ret < 0)
return ret;
unused_chan_list_done = true;
}
if (channel >= 0) {
ctlr = EDMA_CTLR(channel);
channel = EDMA_CHAN_SLOT(channel);
}
if (channel < 0) {
for (i = 0; i < arch_num_cc; i++) {
channel = 0;
for (;;) {
channel = find_next_bit(edma_cc[i]->edma_unused,
edma_cc[i]->num_channels,
channel);
if (channel == edma_cc[i]->num_channels)
break;
if (!test_and_set_bit(channel,
edma_cc[i]->edma_inuse)) {
done = 1;
ctlr = i;
break;
}
channel++;
}
if (done)
break;
}
if (!done)
return -ENOMEM;
} else if (channel >= edma_cc[ctlr]->num_channels) {
return -EINVAL;
} else if (test_and_set_bit(channel, edma_cc[ctlr]->edma_inuse)) {
return -EBUSY;
}
edma_or_array2(ctlr, EDMA_DRAE, 0, channel >> 5, BIT(channel & 0x1f));
edma_stop(EDMA_CTLR_CHAN(ctlr, channel));
memcpy_toio(edmacc_regs_base[ctlr] + PARM_OFFSET(channel),
&dummy_paramset, PARM_SIZE);
if (callback)
setup_dma_interrupt(EDMA_CTLR_CHAN(ctlr, channel),
callback, data);
map_dmach_queue(ctlr, channel, eventq_no);
return EDMA_CTLR_CHAN(ctlr, channel);
}
void edma_free_channel(unsigned channel)
{
unsigned ctlr;
ctlr = EDMA_CTLR(channel);
channel = EDMA_CHAN_SLOT(channel);
if (channel >= edma_cc[ctlr]->num_channels)
return;
setup_dma_interrupt(channel, NULL, NULL);
memcpy_toio(edmacc_regs_base[ctlr] + PARM_OFFSET(channel),
&dummy_paramset, PARM_SIZE);
clear_bit(channel, edma_cc[ctlr]->edma_inuse);
}
int edma_alloc_slot(unsigned ctlr, int slot)
{
if (!edma_cc[ctlr])
return -EINVAL;
if (slot >= 0)
slot = EDMA_CHAN_SLOT(slot);
if (slot < 0) {
slot = edma_cc[ctlr]->num_channels;
for (;;) {
slot = find_next_zero_bit(edma_cc[ctlr]->edma_inuse,
edma_cc[ctlr]->num_slots, slot);
if (slot == edma_cc[ctlr]->num_slots)
return -ENOMEM;
if (!test_and_set_bit(slot, edma_cc[ctlr]->edma_inuse))
break;
}
} else if (slot < edma_cc[ctlr]->num_channels ||
slot >= edma_cc[ctlr]->num_slots) {
return -EINVAL;
} else if (test_and_set_bit(slot, edma_cc[ctlr]->edma_inuse)) {
return -EBUSY;
}
memcpy_toio(edmacc_regs_base[ctlr] + PARM_OFFSET(slot),
&dummy_paramset, PARM_SIZE);
return EDMA_CTLR_CHAN(ctlr, slot);
}
void edma_free_slot(unsigned slot)
{
unsigned ctlr;
ctlr = EDMA_CTLR(slot);
slot = EDMA_CHAN_SLOT(slot);
if (slot < edma_cc[ctlr]->num_channels ||
slot >= edma_cc[ctlr]->num_slots)
return;
memcpy_toio(edmacc_regs_base[ctlr] + PARM_OFFSET(slot),
&dummy_paramset, PARM_SIZE);
clear_bit(slot, edma_cc[ctlr]->edma_inuse);
}
int edma_alloc_cont_slots(unsigned ctlr, unsigned int id, int slot, int count)
{
if ((id != EDMA_CONT_PARAMS_ANY) &&
(slot < edma_cc[ctlr]->num_channels ||
slot >= edma_cc[ctlr]->num_slots))
return -EINVAL;
if (count < 1 || count >
(edma_cc[ctlr]->num_slots - edma_cc[ctlr]->num_channels))
return -EINVAL;
switch (id) {
case EDMA_CONT_PARAMS_ANY:
return reserve_contiguous_slots(ctlr, id, count,
edma_cc[ctlr]->num_channels);
case EDMA_CONT_PARAMS_FIXED_EXACT:
case EDMA_CONT_PARAMS_FIXED_NOT_EXACT:
return reserve_contiguous_slots(ctlr, id, count, slot);
default:
return -EINVAL;
}
}
int edma_free_cont_slots(unsigned slot, int count)
{
unsigned ctlr, slot_to_free;
int i;
ctlr = EDMA_CTLR(slot);
slot = EDMA_CHAN_SLOT(slot);
if (slot < edma_cc[ctlr]->num_channels ||
slot >= edma_cc[ctlr]->num_slots ||
count < 1)
return -EINVAL;
for (i = slot; i < slot + count; ++i) {
ctlr = EDMA_CTLR(i);
slot_to_free = EDMA_CHAN_SLOT(i);
memcpy_toio(edmacc_regs_base[ctlr] + PARM_OFFSET(slot_to_free),
&dummy_paramset, PARM_SIZE);
clear_bit(slot_to_free, edma_cc[ctlr]->edma_inuse);
}
return 0;
}
void edma_set_src(unsigned slot, dma_addr_t src_port,
enum address_mode mode, enum fifo_width width)
{
unsigned ctlr;
ctlr = EDMA_CTLR(slot);
slot = EDMA_CHAN_SLOT(slot);
if (slot < edma_cc[ctlr]->num_slots) {
unsigned int i = edma_parm_read(ctlr, PARM_OPT, slot);
if (mode) {
i = (i & ~(EDMA_FWID)) | (SAM | ((width & 0x7) << 8));
} else {
i &= ~SAM;
}
edma_parm_write(ctlr, PARM_OPT, slot, i);
edma_parm_write(ctlr, PARM_SRC, slot, src_port);
}
}
void edma_set_dest(unsigned slot, dma_addr_t dest_port,
enum address_mode mode, enum fifo_width width)
{
unsigned ctlr;
ctlr = EDMA_CTLR(slot);
slot = EDMA_CHAN_SLOT(slot);
if (slot < edma_cc[ctlr]->num_slots) {
unsigned int i = edma_parm_read(ctlr, PARM_OPT, slot);
if (mode) {
i = (i & ~(EDMA_FWID)) | (DAM | ((width & 0x7) << 8));
} else {
i &= ~DAM;
}
edma_parm_write(ctlr, PARM_OPT, slot, i);
edma_parm_write(ctlr, PARM_DST, slot, dest_port);
}
}
void edma_get_position(unsigned slot, dma_addr_t *src, dma_addr_t *dst)
{
struct edmacc_param temp;
unsigned ctlr;
ctlr = EDMA_CTLR(slot);
slot = EDMA_CHAN_SLOT(slot);
edma_read_slot(EDMA_CTLR_CHAN(ctlr, slot), &temp);
if (src != NULL)
*src = temp.src;
if (dst != NULL)
*dst = temp.dst;
}
void edma_set_src_index(unsigned slot, s16 src_bidx, s16 src_cidx)
{
unsigned ctlr;
ctlr = EDMA_CTLR(slot);
slot = EDMA_CHAN_SLOT(slot);
if (slot < edma_cc[ctlr]->num_slots) {
edma_parm_modify(ctlr, PARM_SRC_DST_BIDX, slot,
0xffff0000, src_bidx);
edma_parm_modify(ctlr, PARM_SRC_DST_CIDX, slot,
0xffff0000, src_cidx);
}
}
void edma_set_dest_index(unsigned slot, s16 dest_bidx, s16 dest_cidx)
{
unsigned ctlr;
ctlr = EDMA_CTLR(slot);
slot = EDMA_CHAN_SLOT(slot);
if (slot < edma_cc[ctlr]->num_slots) {
edma_parm_modify(ctlr, PARM_SRC_DST_BIDX, slot,
0x0000ffff, dest_bidx << 16);
edma_parm_modify(ctlr, PARM_SRC_DST_CIDX, slot,
0x0000ffff, dest_cidx << 16);
}
}
void edma_set_transfer_params(unsigned slot,
u16 acnt, u16 bcnt, u16 ccnt,
u16 bcnt_rld, enum sync_dimension sync_mode)
{
unsigned ctlr;
ctlr = EDMA_CTLR(slot);
slot = EDMA_CHAN_SLOT(slot);
if (slot < edma_cc[ctlr]->num_slots) {
edma_parm_modify(ctlr, PARM_LINK_BCNTRLD, slot,
0x0000ffff, bcnt_rld << 16);
if (sync_mode == ASYNC)
edma_parm_and(ctlr, PARM_OPT, slot, ~SYNCDIM);
else
edma_parm_or(ctlr, PARM_OPT, slot, SYNCDIM);
edma_parm_write(ctlr, PARM_A_B_CNT, slot, (bcnt << 16) | acnt);
edma_parm_write(ctlr, PARM_CCNT, slot, ccnt);
}
}
void edma_link(unsigned from, unsigned to)
{
unsigned ctlr_from, ctlr_to;
ctlr_from = EDMA_CTLR(from);
from = EDMA_CHAN_SLOT(from);
ctlr_to = EDMA_CTLR(to);
to = EDMA_CHAN_SLOT(to);
if (from >= edma_cc[ctlr_from]->num_slots)
return;
if (to >= edma_cc[ctlr_to]->num_slots)
return;
edma_parm_modify(ctlr_from, PARM_LINK_BCNTRLD, from, 0xffff0000,
PARM_OFFSET(to));
}
void edma_unlink(unsigned from)
{
unsigned ctlr;
ctlr = EDMA_CTLR(from);
from = EDMA_CHAN_SLOT(from);
if (from >= edma_cc[ctlr]->num_slots)
return;
edma_parm_or(ctlr, PARM_LINK_BCNTRLD, from, 0xffff);
}
void edma_write_slot(unsigned slot, const struct edmacc_param *param)
{
unsigned ctlr;
ctlr = EDMA_CTLR(slot);
slot = EDMA_CHAN_SLOT(slot);
if (slot >= edma_cc[ctlr]->num_slots)
return;
memcpy_toio(edmacc_regs_base[ctlr] + PARM_OFFSET(slot), param,
PARM_SIZE);
}
void edma_read_slot(unsigned slot, struct edmacc_param *param)
{
unsigned ctlr;
ctlr = EDMA_CTLR(slot);
slot = EDMA_CHAN_SLOT(slot);
if (slot >= edma_cc[ctlr]->num_slots)
return;
memcpy_fromio(param, edmacc_regs_base[ctlr] + PARM_OFFSET(slot),
PARM_SIZE);
}
void edma_pause(unsigned channel)
{
unsigned ctlr;
ctlr = EDMA_CTLR(channel);
channel = EDMA_CHAN_SLOT(channel);
if (channel < edma_cc[ctlr]->num_channels) {
unsigned int mask = BIT(channel & 0x1f);
edma_shadow0_write_array(ctlr, SH_EECR, channel >> 5, mask);
}
}
void edma_resume(unsigned channel)
{
unsigned ctlr;
ctlr = EDMA_CTLR(channel);
channel = EDMA_CHAN_SLOT(channel);
if (channel < edma_cc[ctlr]->num_channels) {
unsigned int mask = BIT(channel & 0x1f);
edma_shadow0_write_array(ctlr, SH_EESR, channel >> 5, mask);
}
}
int edma_trigger_channel(unsigned channel)
{
unsigned ctlr;
unsigned int mask;
ctlr = EDMA_CTLR(channel);
channel = EDMA_CHAN_SLOT(channel);
mask = BIT(channel & 0x1f);
edma_shadow0_write_array(ctlr, SH_ESR, (channel >> 5), mask);
pr_debug("EDMA: ESR%d %08x\n", (channel >> 5),
edma_shadow0_read_array(ctlr, SH_ESR, (channel >> 5)));
return 0;
}
int edma_start(unsigned channel)
{
unsigned ctlr;
ctlr = EDMA_CTLR(channel);
channel = EDMA_CHAN_SLOT(channel);
if (channel < edma_cc[ctlr]->num_channels) {
int j = channel >> 5;
unsigned int mask = BIT(channel & 0x1f);
if (test_bit(channel, edma_cc[ctlr]->edma_unused)) {
pr_debug("EDMA: ESR%d %08x\n", j,
edma_shadow0_read_array(ctlr, SH_ESR, j));
edma_shadow0_write_array(ctlr, SH_ESR, j, mask);
return 0;
}
pr_debug("EDMA: ER%d %08x\n", j,
edma_shadow0_read_array(ctlr, SH_ER, j));
edma_write_array(ctlr, EDMA_ECR, j, mask);
edma_write_array(ctlr, EDMA_EMCR, j, mask);
edma_shadow0_write_array(ctlr, SH_SECR, j, mask);
edma_shadow0_write_array(ctlr, SH_EESR, j, mask);
pr_debug("EDMA: EER%d %08x\n", j,
edma_shadow0_read_array(ctlr, SH_EER, j));
return 0;
}
return -EINVAL;
}
void edma_stop(unsigned channel)
{
unsigned ctlr;
ctlr = EDMA_CTLR(channel);
channel = EDMA_CHAN_SLOT(channel);
if (channel < edma_cc[ctlr]->num_channels) {
int j = channel >> 5;
unsigned int mask = BIT(channel & 0x1f);
edma_shadow0_write_array(ctlr, SH_EECR, j, mask);
edma_shadow0_write_array(ctlr, SH_ECR, j, mask);
edma_shadow0_write_array(ctlr, SH_SECR, j, mask);
edma_write_array(ctlr, EDMA_EMCR, j, mask);
pr_debug("EDMA: EER%d %08x\n", j,
edma_shadow0_read_array(ctlr, SH_EER, j));
}
}
void edma_clean_channel(unsigned channel)
{
unsigned ctlr;
ctlr = EDMA_CTLR(channel);
channel = EDMA_CHAN_SLOT(channel);
if (channel < edma_cc[ctlr]->num_channels) {
int j = (channel >> 5);
unsigned int mask = BIT(channel & 0x1f);
pr_debug("EDMA: EMR%d %08x\n", j,
edma_read_array(ctlr, EDMA_EMR, j));
edma_shadow0_write_array(ctlr, SH_ECR, j, mask);
edma_write_array(ctlr, EDMA_EMCR, j, mask);
edma_shadow0_write_array(ctlr, SH_SECR, j, mask);
edma_write(ctlr, EDMA_CCERRCLR, BIT(16) | BIT(1) | BIT(0));
}
}
void edma_clear_event(unsigned channel)
{
unsigned ctlr;
ctlr = EDMA_CTLR(channel);
channel = EDMA_CHAN_SLOT(channel);
if (channel >= edma_cc[ctlr]->num_channels)
return;
if (channel < 32)
edma_write(ctlr, EDMA_ECR, BIT(channel));
else
edma_write(ctlr, EDMA_ECRH, BIT(channel - 32));
}
static int edma_of_read_u32_to_s16_array(const struct device_node *np,
const char *propname, s16 *out_values,
size_t sz)
{
int ret;
ret = of_property_read_u16_array(np, propname, out_values, sz);
if (ret)
return ret;
*out_values++ = -1;
*out_values++ = -1;
return 0;
}
static int edma_xbar_event_map(struct device *dev,
struct device_node *node,
struct edma_soc_info *pdata, int len)
{
int ret, i;
struct resource res;
void __iomem *xbar;
const s16 (*xbar_chans)[2];
u32 shift, offset, mux;
xbar_chans = devm_kzalloc(dev,
len/sizeof(s16) + 2*sizeof(s16),
GFP_KERNEL);
if (!xbar_chans)
return -ENOMEM;
ret = of_address_to_resource(node, 1, &res);
if (ret)
return -EIO;
xbar = devm_ioremap(dev, res.start, resource_size(&res));
if (!xbar)
return -ENOMEM;
ret = edma_of_read_u32_to_s16_array(node,
"ti,edma-xbar-event-map",
(s16 *)xbar_chans,
len/sizeof(u32));
if (ret)
return -EIO;
for (i = 0; xbar_chans[i][0] != -1; i++) {
shift = (xbar_chans[i][1] & 0x03) << 3;
offset = xbar_chans[i][1] & 0xfffffffc;
mux = readl(xbar + offset);
mux &= ~(0xff << shift);
mux |= xbar_chans[i][0] << shift;
writel(mux, (xbar + offset));
}
pdata->xbar_chans = xbar_chans;
return 0;
}
static int edma_of_parse_dt(struct device *dev,
struct device_node *node,
struct edma_soc_info *pdata)
{
int ret = 0, i;
u32 value;
struct property *prop;
size_t sz;
struct edma_rsv_info *rsv_info;
s8 (*queue_tc_map)[2], (*queue_priority_map)[2];
memset(pdata, 0, sizeof(struct edma_soc_info));
ret = of_property_read_u32(node, "dma-channels", &value);
if (ret < 0)
return ret;
pdata->n_channel = value;
ret = of_property_read_u32(node, "ti,edma-regions", &value);
if (ret < 0)
return ret;
pdata->n_region = value;
ret = of_property_read_u32(node, "ti,edma-slots", &value);
if (ret < 0)
return ret;
pdata->n_slot = value;
pdata->n_cc = 1;
rsv_info = devm_kzalloc(dev, sizeof(struct edma_rsv_info), GFP_KERNEL);
if (!rsv_info)
return -ENOMEM;
pdata->rsv = rsv_info;
queue_tc_map = devm_kzalloc(dev, 8*sizeof(s8), GFP_KERNEL);
if (!queue_tc_map)
return -ENOMEM;
for (i = 0; i < 3; i++) {
queue_tc_map[i][0] = i;
queue_tc_map[i][1] = i;
}
queue_tc_map[i][0] = -1;
queue_tc_map[i][1] = -1;
pdata->queue_tc_mapping = queue_tc_map;
queue_priority_map = devm_kzalloc(dev, 8*sizeof(s8), GFP_KERNEL);
if (!queue_priority_map)
return -ENOMEM;
for (i = 0; i < 3; i++) {
queue_priority_map[i][0] = i;
queue_priority_map[i][1] = i;
}
queue_priority_map[i][0] = -1;
queue_priority_map[i][1] = -1;
pdata->queue_priority_mapping = queue_priority_map;
pdata->default_queue = 0;
prop = of_find_property(node, "ti,edma-xbar-event-map", &sz);
if (prop)
ret = edma_xbar_event_map(dev, node, pdata, sz);
return ret;
}
static struct edma_soc_info *edma_setup_info_from_dt(struct device *dev,
struct device_node *node)
{
struct edma_soc_info *info;
int ret;
info = devm_kzalloc(dev, sizeof(struct edma_soc_info), GFP_KERNEL);
if (!info)
return ERR_PTR(-ENOMEM);
ret = edma_of_parse_dt(dev, node, info);
if (ret)
return ERR_PTR(ret);
dma_cap_set(DMA_SLAVE, edma_filter_info.dma_cap);
of_dma_controller_register(dev->of_node, of_dma_simple_xlate,
&edma_filter_info);
return info;
}
static struct edma_soc_info *edma_setup_info_from_dt(struct device *dev,
struct device_node *node)
{
return ERR_PTR(-ENOSYS);
}
static int edma_probe(struct platform_device *pdev)
{
struct edma_soc_info **info = pdev->dev.platform_data;
struct edma_soc_info *ninfo[EDMA_MAX_CC] = {NULL};
s8 (*queue_priority_mapping)[2];
s8 (*queue_tc_mapping)[2];
int i, j, off, ln, found = 0;
int status = -1;
const s16 (*rsv_chans)[2];
const s16 (*rsv_slots)[2];
const s16 (*xbar_chans)[2];
int irq[EDMA_MAX_CC] = {0, 0};
int err_irq[EDMA_MAX_CC] = {0, 0};
struct resource *r[EDMA_MAX_CC] = {NULL};
struct resource res[EDMA_MAX_CC];
char res_name[10];
char irq_name[10];
struct device_node *node = pdev->dev.of_node;
struct device *dev = &pdev->dev;
int ret;
if (node) {
if (arch_num_cc) {
dev_err(dev, "only one EDMA instance is supported via DT\n");
return -ENODEV;
}
ninfo[0] = edma_setup_info_from_dt(dev, node);
if (IS_ERR(ninfo[0])) {
dev_err(dev, "failed to get DT data\n");
return PTR_ERR(ninfo[0]);
}
info = ninfo;
}
if (!info)
return -ENODEV;
pm_runtime_enable(dev);
ret = pm_runtime_get_sync(dev);
if (ret < 0) {
dev_err(dev, "pm_runtime_get_sync() failed\n");
return ret;
}
for (j = 0; j < EDMA_MAX_CC; j++) {
if (!info[j]) {
if (!found)
return -ENODEV;
break;
}
if (node) {
ret = of_address_to_resource(node, j, &res[j]);
if (!ret)
r[j] = &res[j];
} else {
sprintf(res_name, "edma_cc%d", j);
r[j] = platform_get_resource_byname(pdev,
IORESOURCE_MEM,
res_name);
}
if (!r[j]) {
if (found)
break;
else
return -ENODEV;
} else {
found = 1;
}
edmacc_regs_base[j] = devm_ioremap_resource(&pdev->dev, r[j]);
if (IS_ERR(edmacc_regs_base[j]))
return PTR_ERR(edmacc_regs_base[j]);
edma_cc[j] = devm_kzalloc(&pdev->dev, sizeof(struct edma),
GFP_KERNEL);
if (!edma_cc[j])
return -ENOMEM;
edma_cc[j]->num_channels = min_t(unsigned, info[j]->n_channel,
EDMA_MAX_DMACH);
edma_cc[j]->num_slots = min_t(unsigned, info[j]->n_slot,
EDMA_MAX_PARAMENTRY);
edma_cc[j]->num_cc = min_t(unsigned, info[j]->n_cc,
EDMA_MAX_CC);
edma_cc[j]->default_queue = info[j]->default_queue;
dev_dbg(&pdev->dev, "DMA REG BASE ADDR=%p\n",
edmacc_regs_base[j]);
for (i = 0; i < edma_cc[j]->num_slots; i++)
memcpy_toio(edmacc_regs_base[j] + PARM_OFFSET(i),
&dummy_paramset, PARM_SIZE);
memset(edma_cc[j]->edma_unused, 0xff,
sizeof(edma_cc[j]->edma_unused));
if (info[j]->rsv) {
rsv_chans = info[j]->rsv->rsv_chans;
if (rsv_chans) {
for (i = 0; rsv_chans[i][0] != -1; i++) {
off = rsv_chans[i][0];
ln = rsv_chans[i][1];
clear_bits(off, ln,
edma_cc[j]->edma_unused);
}
}
rsv_slots = info[j]->rsv->rsv_slots;
if (rsv_slots) {
for (i = 0; rsv_slots[i][0] != -1; i++) {
off = rsv_slots[i][0];
ln = rsv_slots[i][1];
set_bits(off, ln,
edma_cc[j]->edma_inuse);
}
}
}
xbar_chans = info[j]->xbar_chans;
if (xbar_chans) {
for (i = 0; xbar_chans[i][1] != -1; i++) {
off = xbar_chans[i][1];
clear_bits(off, 1,
edma_cc[j]->edma_unused);
}
}
if (node) {
irq[j] = irq_of_parse_and_map(node, 0);
} else {
sprintf(irq_name, "edma%d", j);
irq[j] = platform_get_irq_byname(pdev, irq_name);
}
edma_cc[j]->irq_res_start = irq[j];
status = devm_request_irq(&pdev->dev, irq[j],
dma_irq_handler, 0, "edma",
&pdev->dev);
if (status < 0) {
dev_dbg(&pdev->dev,
"devm_request_irq %d failed --> %d\n",
irq[j], status);
return status;
}
if (node) {
err_irq[j] = irq_of_parse_and_map(node, 2);
} else {
sprintf(irq_name, "edma%d_err", j);
err_irq[j] = platform_get_irq_byname(pdev, irq_name);
}
edma_cc[j]->irq_res_end = err_irq[j];
status = devm_request_irq(&pdev->dev, err_irq[j],
dma_ccerr_handler, 0,
"edma_error", &pdev->dev);
if (status < 0) {
dev_dbg(&pdev->dev,
"devm_request_irq %d failed --> %d\n",
err_irq[j], status);
return status;
}
for (i = 0; i < edma_cc[j]->num_channels; i++)
map_dmach_queue(j, i, info[j]->default_queue);
queue_tc_mapping = info[j]->queue_tc_mapping;
queue_priority_mapping = info[j]->queue_priority_mapping;
for (i = 0; queue_tc_mapping[i][0] != -1; i++)
map_queue_tc(j, queue_tc_mapping[i][0],
queue_tc_mapping[i][1]);
for (i = 0; queue_priority_mapping[i][0] != -1; i++)
assign_priority_to_queue(j,
queue_priority_mapping[i][0],
queue_priority_mapping[i][1]);
if (edma_read(j, EDMA_CCCFG) & CHMAP_EXIST)
map_dmach_param(j);
for (i = 0; i < info[j]->n_region; i++) {
edma_write_array2(j, EDMA_DRAE, i, 0, 0x0);
edma_write_array2(j, EDMA_DRAE, i, 1, 0x0);
edma_write_array(j, EDMA_QRAE, i, 0x0);
}
arch_num_cc++;
}
return 0;
}
static int __init edma_init(void)
{
return platform_driver_probe(&edma_driver, edma_probe);
}
