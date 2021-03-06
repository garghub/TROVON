static int get_ch_index(int *status, unsigned int base)
{
int i;
for (i = 0; i < MAX_CHAN; i++) {
if (*status & (1 << (i + base))) {
*status = *status & ~(1 << (i + base));
pr_debug("MDMA: index %d New status %x\n", i, *status);
return i;
}
}
return -1;
}
static int get_block_ts(int len, int tx_width, int block_size)
{
int byte_width = 0, block_ts = 0;
switch (tx_width) {
case DMA_SLAVE_BUSWIDTH_1_BYTE:
byte_width = 1;
break;
case DMA_SLAVE_BUSWIDTH_2_BYTES:
byte_width = 2;
break;
case DMA_SLAVE_BUSWIDTH_4_BYTES:
default:
byte_width = 4;
break;
}
block_ts = len/byte_width;
if (block_ts > block_size)
block_ts = 0xFFFF;
return block_ts;
}
static void dmac1_mask_periphral_intr(struct middma_device *mid)
{
u32 pimr;
if (mid->pimr_mask) {
pimr = readl(mid->mask_reg + LNW_PERIPHRAL_MASK);
pimr |= mid->pimr_mask;
writel(pimr, mid->mask_reg + LNW_PERIPHRAL_MASK);
}
return;
}
static void dmac1_unmask_periphral_intr(struct intel_mid_dma_chan *midc)
{
u32 pimr;
struct middma_device *mid = to_middma_device(midc->chan.device);
if (mid->pimr_mask) {
pimr = readl(mid->mask_reg + LNW_PERIPHRAL_MASK);
pimr &= ~mid->pimr_mask;
writel(pimr, mid->mask_reg + LNW_PERIPHRAL_MASK);
}
return;
}
static void enable_dma_interrupt(struct intel_mid_dma_chan *midc)
{
dmac1_unmask_periphral_intr(midc);
iowrite32(UNMASK_INTR_REG(midc->ch_id), midc->dma_base + MASK_TFR);
iowrite32(UNMASK_INTR_REG(midc->ch_id), midc->dma_base + MASK_ERR);
return;
}
static void disable_dma_interrupt(struct intel_mid_dma_chan *midc)
{
iowrite32(MASK_INTR_REG(midc->ch_id), midc->dma_base + MASK_BLOCK);
iowrite32(MASK_INTR_REG(midc->ch_id), midc->dma_base + MASK_TFR);
iowrite32(MASK_INTR_REG(midc->ch_id), midc->dma_base + MASK_ERR);
return;
}
static struct intel_mid_dma_desc *midc_desc_get(struct intel_mid_dma_chan *midc)
{
struct intel_mid_dma_desc *desc, *_desc;
struct intel_mid_dma_desc *ret = NULL;
spin_lock_bh(&midc->lock);
list_for_each_entry_safe(desc, _desc, &midc->free_list, desc_node) {
if (async_tx_test_ack(&desc->txd)) {
list_del(&desc->desc_node);
ret = desc;
break;
}
}
spin_unlock_bh(&midc->lock);
return ret;
}
static void midc_desc_put(struct intel_mid_dma_chan *midc,
struct intel_mid_dma_desc *desc)
{
if (desc) {
spin_lock_bh(&midc->lock);
list_add_tail(&desc->desc_node, &midc->free_list);
spin_unlock_bh(&midc->lock);
}
}
static void midc_dostart(struct intel_mid_dma_chan *midc,
struct intel_mid_dma_desc *first)
{
struct middma_device *mid = to_middma_device(midc->chan.device);
if (midc->busy && test_ch_en(midc->dma_base, midc->ch_id)) {
pr_err("ERR_MDMA: channel is busy in start\n");
return;
}
midc->busy = true;
iowrite32(first->sar, midc->ch_regs + SAR);
iowrite32(first->dar, midc->ch_regs + DAR);
iowrite32(first->lli_phys, midc->ch_regs + LLP);
iowrite32(first->cfg_hi, midc->ch_regs + CFG_HIGH);
iowrite32(first->cfg_lo, midc->ch_regs + CFG_LOW);
iowrite32(first->ctl_lo, midc->ch_regs + CTL_LOW);
iowrite32(first->ctl_hi, midc->ch_regs + CTL_HIGH);
pr_debug("MDMA:TX SAR %x,DAR %x,CFGL %x,CFGH %x,CTLH %x, CTLL %x\n",
(int)first->sar, (int)first->dar, first->cfg_hi,
first->cfg_lo, first->ctl_hi, first->ctl_lo);
first->status = DMA_IN_PROGRESS;
iowrite32(ENABLE_CHANNEL(midc->ch_id), mid->dma_base + DMA_CHAN_EN);
}
static void midc_descriptor_complete(struct intel_mid_dma_chan *midc,
struct intel_mid_dma_desc *desc)
__releases(&midc->lock
static void midc_scan_descriptors(struct middma_device *mid,
struct intel_mid_dma_chan *midc)
{
struct intel_mid_dma_desc *desc = NULL, *_desc = NULL;
list_for_each_entry_safe(desc, _desc, &midc->active_list, desc_node) {
if (desc->status == DMA_IN_PROGRESS)
midc_descriptor_complete(midc, desc);
}
return;
}
static int midc_lli_fill_sg(struct intel_mid_dma_chan *midc,
struct intel_mid_dma_desc *desc,
struct scatterlist *sglist,
unsigned int sglen,
unsigned int flags)
{
struct intel_mid_dma_slave *mids;
struct scatterlist *sg;
dma_addr_t lli_next, sg_phy_addr;
struct intel_mid_dma_lli *lli_bloc_desc;
union intel_mid_dma_ctl_lo ctl_lo;
union intel_mid_dma_ctl_hi ctl_hi;
int i;
pr_debug("MDMA: Entered midc_lli_fill_sg\n");
mids = midc->mid_slave;
lli_bloc_desc = desc->lli;
lli_next = desc->lli_phys;
ctl_lo.ctl_lo = desc->ctl_lo;
ctl_hi.ctl_hi = desc->ctl_hi;
for_each_sg(sglist, sg, sglen, i) {
if (i != sglen - 1) {
lli_next = lli_next +
sizeof(struct intel_mid_dma_lli);
} else {
if (flags & DMA_PREP_CIRCULAR_LIST) {
pr_debug("MDMA: LLI is configured in circular mode\n");
lli_next = desc->lli_phys;
} else {
lli_next = 0;
ctl_lo.ctlx.llp_dst_en = 0;
ctl_lo.ctlx.llp_src_en = 0;
}
}
ctl_hi.ctlx.block_ts = get_block_ts(sg_dma_len(sg),
desc->width,
midc->dma->block_size);
sg_phy_addr = sg_dma_address(sg);
if (desc->dirn == DMA_MEM_TO_DEV) {
lli_bloc_desc->sar = sg_phy_addr;
lli_bloc_desc->dar = mids->dma_slave.dst_addr;
} else if (desc->dirn == DMA_DEV_TO_MEM) {
lli_bloc_desc->sar = mids->dma_slave.src_addr;
lli_bloc_desc->dar = sg_phy_addr;
}
lli_bloc_desc->llp = lli_next;
lli_bloc_desc->ctl_lo = ctl_lo.ctl_lo;
lli_bloc_desc->ctl_hi = ctl_hi.ctl_hi;
lli_bloc_desc++;
}
desc->ctl_lo = desc->lli->ctl_lo;
desc->ctl_hi = desc->lli->ctl_hi;
desc->sar = desc->lli->sar;
desc->dar = desc->lli->dar;
return 0;
}
static dma_cookie_t intel_mid_dma_tx_submit(struct dma_async_tx_descriptor *tx)
{
struct intel_mid_dma_desc *desc = to_intel_mid_dma_desc(tx);
struct intel_mid_dma_chan *midc = to_intel_mid_dma_chan(tx->chan);
dma_cookie_t cookie;
spin_lock_bh(&midc->lock);
cookie = dma_cookie_assign(tx);
if (list_empty(&midc->active_list))
list_add_tail(&desc->desc_node, &midc->active_list);
else
list_add_tail(&desc->desc_node, &midc->queue);
midc_dostart(midc, desc);
spin_unlock_bh(&midc->lock);
return cookie;
}
static void intel_mid_dma_issue_pending(struct dma_chan *chan)
{
struct intel_mid_dma_chan *midc = to_intel_mid_dma_chan(chan);
spin_lock_bh(&midc->lock);
if (!list_empty(&midc->queue))
midc_scan_descriptors(to_middma_device(chan->device), midc);
spin_unlock_bh(&midc->lock);
}
static enum dma_status intel_mid_dma_tx_status(struct dma_chan *chan,
dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
struct intel_mid_dma_chan *midc = to_intel_mid_dma_chan(chan);
enum dma_status ret;
ret = dma_cookie_status(chan, cookie, txstate);
if (ret != DMA_SUCCESS) {
spin_lock_bh(&midc->lock);
midc_scan_descriptors(to_middma_device(chan->device), midc);
spin_unlock_bh(&midc->lock);
ret = dma_cookie_status(chan, cookie, txstate);
}
return ret;
}
static int dma_slave_control(struct dma_chan *chan, unsigned long arg)
{
struct intel_mid_dma_chan *midc = to_intel_mid_dma_chan(chan);
struct dma_slave_config *slave = (struct dma_slave_config *)arg;
struct intel_mid_dma_slave *mid_slave;
BUG_ON(!midc);
BUG_ON(!slave);
pr_debug("MDMA: slave control called\n");
mid_slave = to_intel_mid_dma_slave(slave);
BUG_ON(!mid_slave);
midc->mid_slave = mid_slave;
return 0;
}
static int intel_mid_dma_device_control(struct dma_chan *chan,
enum dma_ctrl_cmd cmd, unsigned long arg)
{
struct intel_mid_dma_chan *midc = to_intel_mid_dma_chan(chan);
struct middma_device *mid = to_middma_device(chan->device);
struct intel_mid_dma_desc *desc, *_desc;
union intel_mid_dma_cfg_lo cfg_lo;
if (cmd == DMA_SLAVE_CONFIG)
return dma_slave_control(chan, arg);
if (cmd != DMA_TERMINATE_ALL)
return -ENXIO;
spin_lock_bh(&midc->lock);
if (midc->busy == false) {
spin_unlock_bh(&midc->lock);
return 0;
}
cfg_lo.cfg_lo = ioread32(midc->ch_regs + CFG_LOW);
cfg_lo.cfgx.ch_susp = 1;
iowrite32(cfg_lo.cfg_lo, midc->ch_regs + CFG_LOW);
iowrite32(DISABLE_CHANNEL(midc->ch_id), mid->dma_base + DMA_CHAN_EN);
midc->busy = false;
disable_dma_interrupt(midc);
midc->descs_allocated = 0;
spin_unlock_bh(&midc->lock);
list_for_each_entry_safe(desc, _desc, &midc->active_list, desc_node) {
if (desc->lli != NULL) {
pci_pool_free(desc->lli_pool, desc->lli,
desc->lli_phys);
pci_pool_destroy(desc->lli_pool);
desc->lli = NULL;
}
list_move(&desc->desc_node, &midc->free_list);
}
return 0;
}
static struct dma_async_tx_descriptor *intel_mid_dma_prep_memcpy(
struct dma_chan *chan, dma_addr_t dest,
dma_addr_t src, size_t len, unsigned long flags)
{
struct intel_mid_dma_chan *midc;
struct intel_mid_dma_desc *desc = NULL;
struct intel_mid_dma_slave *mids;
union intel_mid_dma_ctl_lo ctl_lo;
union intel_mid_dma_ctl_hi ctl_hi;
union intel_mid_dma_cfg_lo cfg_lo;
union intel_mid_dma_cfg_hi cfg_hi;
enum dma_slave_buswidth width;
pr_debug("MDMA: Prep for memcpy\n");
BUG_ON(!chan);
if (!len)
return NULL;
midc = to_intel_mid_dma_chan(chan);
BUG_ON(!midc);
mids = midc->mid_slave;
BUG_ON(!mids);
pr_debug("MDMA:called for DMA %x CH %d Length %zu\n",
midc->dma->pci_id, midc->ch_id, len);
pr_debug("MDMA:Cfg passed Mode %x, Dirn %x, HS %x, Width %x\n",
mids->cfg_mode, mids->dma_slave.direction,
mids->hs_mode, mids->dma_slave.src_addr_width);
if (mids->hs_mode == LNW_DMA_SW_HS) {
cfg_lo.cfg_lo = 0;
cfg_lo.cfgx.hs_sel_dst = 1;
cfg_lo.cfgx.hs_sel_src = 1;
} else if (mids->hs_mode == LNW_DMA_HW_HS)
cfg_lo.cfg_lo = 0x00000;
if (mids->cfg_mode == LNW_DMA_MEM_TO_MEM) {
cfg_hi.cfg_hi = 0;
} else {
cfg_hi.cfg_hi = 0;
if (midc->dma->pimr_mask) {
cfg_hi.cfgx.protctl = 0x0;
cfg_hi.cfgx.fifo_mode = 1;
if (mids->dma_slave.direction == DMA_MEM_TO_DEV) {
cfg_hi.cfgx.src_per = 0;
if (mids->device_instance == 0)
cfg_hi.cfgx.dst_per = 3;
if (mids->device_instance == 1)
cfg_hi.cfgx.dst_per = 1;
} else if (mids->dma_slave.direction == DMA_DEV_TO_MEM) {
if (mids->device_instance == 0)
cfg_hi.cfgx.src_per = 2;
if (mids->device_instance == 1)
cfg_hi.cfgx.src_per = 0;
cfg_hi.cfgx.dst_per = 0;
}
} else {
cfg_hi.cfgx.protctl = 0x1;
cfg_hi.cfgx.src_per = cfg_hi.cfgx.dst_per =
midc->ch_id - midc->dma->chan_base;
}
}
ctl_hi.ctlx.reser = 0;
ctl_hi.ctlx.done = 0;
width = mids->dma_slave.src_addr_width;
ctl_hi.ctlx.block_ts = get_block_ts(len, width, midc->dma->block_size);
pr_debug("MDMA:calc len %d for block size %d\n",
ctl_hi.ctlx.block_ts, midc->dma->block_size);
ctl_lo.ctl_lo = 0;
ctl_lo.ctlx.int_en = 1;
ctl_lo.ctlx.dst_msize = mids->dma_slave.src_maxburst;
ctl_lo.ctlx.src_msize = mids->dma_slave.dst_maxburst;
ctl_lo.ctlx.dst_tr_width = mids->dma_slave.dst_addr_width / 2;
ctl_lo.ctlx.src_tr_width = mids->dma_slave.src_addr_width / 2;
if (mids->cfg_mode == LNW_DMA_MEM_TO_MEM) {
ctl_lo.ctlx.tt_fc = 0;
ctl_lo.ctlx.sinc = 0;
ctl_lo.ctlx.dinc = 0;
} else {
if (mids->dma_slave.direction == DMA_MEM_TO_DEV) {
ctl_lo.ctlx.sinc = 0;
ctl_lo.ctlx.dinc = 2;
ctl_lo.ctlx.tt_fc = 1;
} else if (mids->dma_slave.direction == DMA_DEV_TO_MEM) {
ctl_lo.ctlx.sinc = 2;
ctl_lo.ctlx.dinc = 0;
ctl_lo.ctlx.tt_fc = 2;
}
}
pr_debug("MDMA:Calc CTL LO %x, CTL HI %x, CFG LO %x, CFG HI %x\n",
ctl_lo.ctl_lo, ctl_hi.ctl_hi, cfg_lo.cfg_lo, cfg_hi.cfg_hi);
enable_dma_interrupt(midc);
desc = midc_desc_get(midc);
if (desc == NULL)
goto err_desc_get;
desc->sar = src;
desc->dar = dest ;
desc->len = len;
desc->cfg_hi = cfg_hi.cfg_hi;
desc->cfg_lo = cfg_lo.cfg_lo;
desc->ctl_lo = ctl_lo.ctl_lo;
desc->ctl_hi = ctl_hi.ctl_hi;
desc->width = width;
desc->dirn = mids->dma_slave.direction;
desc->lli_phys = 0;
desc->lli = NULL;
desc->lli_pool = NULL;
return &desc->txd;
err_desc_get:
pr_err("ERR_MDMA: Failed to get desc\n");
midc_desc_put(midc, desc);
return NULL;
}
static struct dma_async_tx_descriptor *intel_mid_dma_prep_slave_sg(
struct dma_chan *chan, struct scatterlist *sgl,
unsigned int sg_len, enum dma_transfer_direction direction,
unsigned long flags, void *context)
{
struct intel_mid_dma_chan *midc = NULL;
struct intel_mid_dma_slave *mids = NULL;
struct intel_mid_dma_desc *desc = NULL;
struct dma_async_tx_descriptor *txd = NULL;
union intel_mid_dma_ctl_lo ctl_lo;
pr_debug("MDMA: Prep for slave SG\n");
if (!sg_len) {
pr_err("MDMA: Invalid SG length\n");
return NULL;
}
midc = to_intel_mid_dma_chan(chan);
BUG_ON(!midc);
mids = midc->mid_slave;
BUG_ON(!mids);
if (!midc->dma->pimr_mask) {
if (sg_len == 1) {
txd = intel_mid_dma_prep_memcpy(chan,
mids->dma_slave.dst_addr,
mids->dma_slave.src_addr,
sg_dma_len(sgl),
flags);
return txd;
} else {
pr_warn("MDMA: SG list is not supported by this controller\n");
return NULL;
}
}
pr_debug("MDMA: SG Length = %d, direction = %d, Flags = %#lx\n",
sg_len, direction, flags);
txd = intel_mid_dma_prep_memcpy(chan, 0, 0, sg_dma_len(sgl), flags);
if (NULL == txd) {
pr_err("MDMA: Prep memcpy failed\n");
return NULL;
}
desc = to_intel_mid_dma_desc(txd);
desc->dirn = direction;
ctl_lo.ctl_lo = desc->ctl_lo;
ctl_lo.ctlx.llp_dst_en = 1;
ctl_lo.ctlx.llp_src_en = 1;
desc->ctl_lo = ctl_lo.ctl_lo;
desc->lli_length = sg_len;
desc->current_lli = 0;
desc->lli_pool = pci_pool_create("intel_mid_dma_lli_pool",
midc->dma->pdev,
(sizeof(struct intel_mid_dma_lli)*sg_len),
32, 0);
if (NULL == desc->lli_pool) {
pr_err("MID_DMA:LLI pool create failed\n");
return NULL;
}
desc->lli = pci_pool_alloc(desc->lli_pool, GFP_KERNEL, &desc->lli_phys);
if (!desc->lli) {
pr_err("MID_DMA: LLI alloc failed\n");
pci_pool_destroy(desc->lli_pool);
return NULL;
}
midc_lli_fill_sg(midc, desc, sgl, sg_len, flags);
if (flags & DMA_PREP_INTERRUPT) {
iowrite32(UNMASK_INTR_REG(midc->ch_id),
midc->dma_base + MASK_BLOCK);
pr_debug("MDMA:Enabled Block interrupt\n");
}
return &desc->txd;
}
static void intel_mid_dma_free_chan_resources(struct dma_chan *chan)
{
struct intel_mid_dma_chan *midc = to_intel_mid_dma_chan(chan);
struct middma_device *mid = to_middma_device(chan->device);
struct intel_mid_dma_desc *desc, *_desc;
if (true == midc->busy) {
pr_err("ERR_MDMA: trying to free ch in use\n");
}
spin_lock_bh(&midc->lock);
midc->descs_allocated = 0;
list_for_each_entry_safe(desc, _desc, &midc->active_list, desc_node) {
list_del(&desc->desc_node);
pci_pool_free(mid->dma_pool, desc, desc->txd.phys);
}
list_for_each_entry_safe(desc, _desc, &midc->free_list, desc_node) {
list_del(&desc->desc_node);
pci_pool_free(mid->dma_pool, desc, desc->txd.phys);
}
list_for_each_entry_safe(desc, _desc, &midc->queue, desc_node) {
list_del(&desc->desc_node);
pci_pool_free(mid->dma_pool, desc, desc->txd.phys);
}
spin_unlock_bh(&midc->lock);
midc->in_use = false;
midc->busy = false;
iowrite32(MASK_INTR_REG(midc->ch_id), mid->dma_base + MASK_BLOCK);
iowrite32(MASK_INTR_REG(midc->ch_id), mid->dma_base + MASK_ERR);
pm_runtime_put(&mid->pdev->dev);
}
static int intel_mid_dma_alloc_chan_resources(struct dma_chan *chan)
{
struct intel_mid_dma_chan *midc = to_intel_mid_dma_chan(chan);
struct middma_device *mid = to_middma_device(chan->device);
struct intel_mid_dma_desc *desc;
dma_addr_t phys;
int i = 0;
pm_runtime_get_sync(&mid->pdev->dev);
if (mid->state == SUSPENDED) {
if (dma_resume(&mid->pdev->dev)) {
pr_err("ERR_MDMA: resume failed");
return -EFAULT;
}
}
if (test_ch_en(mid->dma_base, midc->ch_id)) {
pr_err("ERR_MDMA: ch not idle\n");
pm_runtime_put(&mid->pdev->dev);
return -EIO;
}
dma_cookie_init(chan);
spin_lock_bh(&midc->lock);
while (midc->descs_allocated < DESCS_PER_CHANNEL) {
spin_unlock_bh(&midc->lock);
desc = pci_pool_alloc(mid->dma_pool, GFP_KERNEL, &phys);
if (!desc) {
pr_err("ERR_MDMA: desc failed\n");
pm_runtime_put(&mid->pdev->dev);
return -ENOMEM;
}
dma_async_tx_descriptor_init(&desc->txd, chan);
desc->txd.tx_submit = intel_mid_dma_tx_submit;
desc->txd.flags = DMA_CTRL_ACK;
desc->txd.phys = phys;
spin_lock_bh(&midc->lock);
i = ++midc->descs_allocated;
list_add_tail(&desc->desc_node, &midc->free_list);
}
spin_unlock_bh(&midc->lock);
midc->in_use = true;
midc->busy = false;
pr_debug("MID_DMA: Desc alloc done ret: %d desc\n", i);
return i;
}
static void midc_handle_error(struct middma_device *mid,
struct intel_mid_dma_chan *midc)
{
midc_scan_descriptors(mid, midc);
}
static void dma_tasklet(unsigned long data)
{
struct middma_device *mid = NULL;
struct intel_mid_dma_chan *midc = NULL;
u32 status, raw_tfr, raw_block;
int i;
mid = (struct middma_device *)data;
if (mid == NULL) {
pr_err("ERR_MDMA: tasklet Null param\n");
return;
}
pr_debug("MDMA: in tasklet for device %x\n", mid->pci_id);
raw_tfr = ioread32(mid->dma_base + RAW_TFR);
raw_block = ioread32(mid->dma_base + RAW_BLOCK);
status = raw_tfr | raw_block;
status &= mid->intr_mask;
while (status) {
i = get_ch_index(&status, mid->chan_base);
if (i < 0) {
pr_err("ERR_MDMA:Invalid ch index %x\n", i);
return;
}
midc = &mid->ch[i];
if (midc == NULL) {
pr_err("ERR_MDMA:Null param midc\n");
return;
}
pr_debug("MDMA:Tx complete interrupt %x, Ch No %d Index %d\n",
status, midc->ch_id, i);
midc->raw_tfr = raw_tfr;
midc->raw_block = raw_block;
spin_lock_bh(&midc->lock);
iowrite32((1 << midc->ch_id), mid->dma_base + CLEAR_TFR);
if (raw_block) {
iowrite32((1 << midc->ch_id),
mid->dma_base + CLEAR_BLOCK);
}
midc_scan_descriptors(mid, midc);
pr_debug("MDMA:Scan of desc... complete, unmasking\n");
iowrite32(UNMASK_INTR_REG(midc->ch_id),
mid->dma_base + MASK_TFR);
if (raw_block) {
iowrite32(UNMASK_INTR_REG(midc->ch_id),
mid->dma_base + MASK_BLOCK);
}
spin_unlock_bh(&midc->lock);
}
status = ioread32(mid->dma_base + RAW_ERR);
status &= mid->intr_mask;
while (status) {
i = get_ch_index(&status, mid->chan_base);
if (i < 0) {
pr_err("ERR_MDMA:Invalid ch index %x\n", i);
return;
}
midc = &mid->ch[i];
if (midc == NULL) {
pr_err("ERR_MDMA:Null param midc\n");
return;
}
pr_debug("MDMA:Tx complete interrupt %x, Ch No %d Index %d\n",
status, midc->ch_id, i);
iowrite32((1 << midc->ch_id), mid->dma_base + CLEAR_ERR);
spin_lock_bh(&midc->lock);
midc_handle_error(mid, midc);
iowrite32(UNMASK_INTR_REG(midc->ch_id),
mid->dma_base + MASK_ERR);
spin_unlock_bh(&midc->lock);
}
pr_debug("MDMA:Exiting takslet...\n");
return;
}
static void dma_tasklet1(unsigned long data)
{
pr_debug("MDMA:in takslet1...\n");
return dma_tasklet(data);
}
static void dma_tasklet2(unsigned long data)
{
pr_debug("MDMA:in takslet2...\n");
return dma_tasklet(data);
}
static irqreturn_t intel_mid_dma_interrupt(int irq, void *data)
{
struct middma_device *mid = data;
u32 tfr_status, err_status;
int call_tasklet = 0;
tfr_status = ioread32(mid->dma_base + RAW_TFR);
err_status = ioread32(mid->dma_base + RAW_ERR);
if (!tfr_status && !err_status)
return IRQ_NONE;
pr_debug("MDMA:Got an interrupt on irq %d\n", irq);
pr_debug("MDMA: Status %x, Mask %x\n", tfr_status, mid->intr_mask);
tfr_status &= mid->intr_mask;
if (tfr_status) {
iowrite32((tfr_status << INT_MASK_WE), mid->dma_base + MASK_TFR);
iowrite32((tfr_status << INT_MASK_WE), mid->dma_base + MASK_BLOCK);
pr_debug("MDMA: Calling tasklet %x\n", tfr_status);
call_tasklet = 1;
}
err_status &= mid->intr_mask;
if (err_status) {
iowrite32((err_status << INT_MASK_WE),
mid->dma_base + MASK_ERR);
call_tasklet = 1;
}
if (call_tasklet)
tasklet_schedule(&mid->tasklet);
return IRQ_HANDLED;
}
static irqreturn_t intel_mid_dma_interrupt1(int irq, void *data)
{
return intel_mid_dma_interrupt(irq, data);
}
static irqreturn_t intel_mid_dma_interrupt2(int irq, void *data)
{
return intel_mid_dma_interrupt(irq, data);
}
static int mid_setup_dma(struct pci_dev *pdev)
{
struct middma_device *dma = pci_get_drvdata(pdev);
int err, i;
dma->dma_pool = pci_pool_create("intel_mid_dma_desc_pool", pdev,
sizeof(struct intel_mid_dma_desc),
32, 0);
if (NULL == dma->dma_pool) {
pr_err("ERR_MDMA:pci_pool_create failed\n");
err = -ENOMEM;
goto err_dma_pool;
}
INIT_LIST_HEAD(&dma->common.channels);
dma->pci_id = pdev->device;
if (dma->pimr_mask) {
dma->mask_reg = ioremap(LNW_PERIPHRAL_MASK_BASE,
LNW_PERIPHRAL_MASK_SIZE);
if (dma->mask_reg == NULL) {
pr_err("ERR_MDMA:Can't map periphral intr space !!\n");
err = -ENOMEM;
goto err_ioremap;
}
} else
dma->mask_reg = NULL;
pr_debug("MDMA:Adding %d channel for this controller\n", dma->max_chan);
dma->intr_mask = 0;
dma->state = RUNNING;
for (i = 0; i < dma->max_chan; i++) {
struct intel_mid_dma_chan *midch = &dma->ch[i];
midch->chan.device = &dma->common;
dma_cookie_init(&midch->chan);
midch->ch_id = dma->chan_base + i;
pr_debug("MDMA:Init CH %d, ID %d\n", i, midch->ch_id);
midch->dma_base = dma->dma_base;
midch->ch_regs = dma->dma_base + DMA_CH_SIZE * midch->ch_id;
midch->dma = dma;
dma->intr_mask |= 1 << (dma->chan_base + i);
spin_lock_init(&midch->lock);
INIT_LIST_HEAD(&midch->active_list);
INIT_LIST_HEAD(&midch->queue);
INIT_LIST_HEAD(&midch->free_list);
iowrite32(MASK_INTR_REG(midch->ch_id),
dma->dma_base + MASK_BLOCK);
iowrite32(MASK_INTR_REG(midch->ch_id),
dma->dma_base + MASK_SRC_TRAN);
iowrite32(MASK_INTR_REG(midch->ch_id),
dma->dma_base + MASK_DST_TRAN);
iowrite32(MASK_INTR_REG(midch->ch_id),
dma->dma_base + MASK_ERR);
iowrite32(MASK_INTR_REG(midch->ch_id),
dma->dma_base + MASK_TFR);
disable_dma_interrupt(midch);
list_add_tail(&midch->chan.device_node, &dma->common.channels);
}
pr_debug("MDMA: Calc Mask as %x for this controller\n", dma->intr_mask);
dma_cap_zero(dma->common.cap_mask);
dma_cap_set(DMA_MEMCPY, dma->common.cap_mask);
dma_cap_set(DMA_SLAVE, dma->common.cap_mask);
dma_cap_set(DMA_PRIVATE, dma->common.cap_mask);
dma->common.dev = &pdev->dev;
dma->common.device_alloc_chan_resources =
intel_mid_dma_alloc_chan_resources;
dma->common.device_free_chan_resources =
intel_mid_dma_free_chan_resources;
dma->common.device_tx_status = intel_mid_dma_tx_status;
dma->common.device_prep_dma_memcpy = intel_mid_dma_prep_memcpy;
dma->common.device_issue_pending = intel_mid_dma_issue_pending;
dma->common.device_prep_slave_sg = intel_mid_dma_prep_slave_sg;
dma->common.device_control = intel_mid_dma_device_control;
iowrite32(REG_BIT0, dma->dma_base + DMA_CFG);
if (dma->pimr_mask) {
pr_debug("MDMA:Requesting irq shared for DMAC1\n");
err = request_irq(pdev->irq, intel_mid_dma_interrupt1,
IRQF_SHARED, "INTEL_MID_DMAC1", dma);
if (0 != err)
goto err_irq;
} else {
dma->intr_mask = 0x03;
pr_debug("MDMA:Requesting irq for DMAC2\n");
err = request_irq(pdev->irq, intel_mid_dma_interrupt2,
IRQF_SHARED, "INTEL_MID_DMAC2", dma);
if (0 != err)
goto err_irq;
}
err = dma_async_device_register(&dma->common);
if (0 != err) {
pr_err("ERR_MDMA:device_register failed: %d\n", err);
goto err_engine;
}
if (dma->pimr_mask) {
pr_debug("setting up tasklet1 for DMAC1\n");
tasklet_init(&dma->tasklet, dma_tasklet1, (unsigned long)dma);
} else {
pr_debug("setting up tasklet2 for DMAC2\n");
tasklet_init(&dma->tasklet, dma_tasklet2, (unsigned long)dma);
}
return 0;
err_engine:
free_irq(pdev->irq, dma);
err_irq:
if (dma->mask_reg)
iounmap(dma->mask_reg);
err_ioremap:
pci_pool_destroy(dma->dma_pool);
err_dma_pool:
pr_err("ERR_MDMA:setup_dma failed: %d\n", err);
return err;
}
static void middma_shutdown(struct pci_dev *pdev)
{
struct middma_device *device = pci_get_drvdata(pdev);
dma_async_device_unregister(&device->common);
pci_pool_destroy(device->dma_pool);
if (device->mask_reg)
iounmap(device->mask_reg);
if (device->dma_base)
iounmap(device->dma_base);
free_irq(pdev->irq, device);
return;
}
static int __devinit intel_mid_dma_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct middma_device *device;
u32 base_addr, bar_size;
struct intel_mid_dma_probe_info *info;
int err;
pr_debug("MDMA: probe for %x\n", pdev->device);
info = (void *)id->driver_data;
pr_debug("MDMA: CH %d, base %d, block len %d, Periphral mask %x\n",
info->max_chan, info->ch_base,
info->block_size, info->pimr_mask);
err = pci_enable_device(pdev);
if (err)
goto err_enable_device;
err = pci_request_regions(pdev, "intel_mid_dmac");
if (err)
goto err_request_regions;
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (err)
goto err_set_dma_mask;
err = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32));
if (err)
goto err_set_dma_mask;
device = kzalloc(sizeof(*device), GFP_KERNEL);
if (!device) {
pr_err("ERR_MDMA:kzalloc failed probe\n");
err = -ENOMEM;
goto err_kzalloc;
}
device->pdev = pci_dev_get(pdev);
base_addr = pci_resource_start(pdev, 0);
bar_size = pci_resource_len(pdev, 0);
device->dma_base = ioremap_nocache(base_addr, DMA_REG_SIZE);
if (!device->dma_base) {
pr_err("ERR_MDMA:ioremap failed\n");
err = -ENOMEM;
goto err_ioremap;
}
pci_set_drvdata(pdev, device);
pci_set_master(pdev);
device->max_chan = info->max_chan;
device->chan_base = info->ch_base;
device->block_size = info->block_size;
device->pimr_mask = info->pimr_mask;
err = mid_setup_dma(pdev);
if (err)
goto err_dma;
pm_runtime_put_noidle(&pdev->dev);
pm_runtime_allow(&pdev->dev);
return 0;
err_dma:
iounmap(device->dma_base);
err_ioremap:
pci_dev_put(pdev);
kfree(device);
err_kzalloc:
err_set_dma_mask:
pci_release_regions(pdev);
pci_disable_device(pdev);
err_request_regions:
err_enable_device:
pr_err("ERR_MDMA:Probe failed %d\n", err);
return err;
}
static void __devexit intel_mid_dma_remove(struct pci_dev *pdev)
{
struct middma_device *device = pci_get_drvdata(pdev);
pm_runtime_get_noresume(&pdev->dev);
pm_runtime_forbid(&pdev->dev);
middma_shutdown(pdev);
pci_dev_put(pdev);
kfree(device);
pci_release_regions(pdev);
pci_disable_device(pdev);
}
static int dma_suspend(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
int i;
struct middma_device *device = pci_get_drvdata(pci);
pr_debug("MDMA: dma_suspend called\n");
for (i = 0; i < device->max_chan; i++) {
if (device->ch[i].in_use)
return -EAGAIN;
}
dmac1_mask_periphral_intr(device);
device->state = SUSPENDED;
pci_save_state(pci);
pci_disable_device(pci);
pci_set_power_state(pci, PCI_D3hot);
return 0;
}
int dma_resume(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
int ret;
struct middma_device *device = pci_get_drvdata(pci);
pr_debug("MDMA: dma_resume called\n");
pci_set_power_state(pci, PCI_D0);
pci_restore_state(pci);
ret = pci_enable_device(pci);
if (ret) {
pr_err("MDMA: device can't be enabled for %x\n", pci->device);
return ret;
}
device->state = RUNNING;
iowrite32(REG_BIT0, device->dma_base + DMA_CFG);
return 0;
}
static int dma_runtime_suspend(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct middma_device *device = pci_get_drvdata(pci_dev);
device->state = SUSPENDED;
return 0;
}
static int dma_runtime_resume(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct middma_device *device = pci_get_drvdata(pci_dev);
device->state = RUNNING;
iowrite32(REG_BIT0, device->dma_base + DMA_CFG);
return 0;
}
static int dma_runtime_idle(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct middma_device *device = pci_get_drvdata(pdev);
int i;
for (i = 0; i < device->max_chan; i++) {
if (device->ch[i].in_use)
return -EAGAIN;
}
return pm_schedule_suspend(dev, 0);
}
static int __init intel_mid_dma_init(void)
{
pr_debug("INFO_MDMA: LNW DMA Driver Version %s\n",
INTEL_MID_DMA_DRIVER_VERSION);
return pci_register_driver(&intel_mid_dma_pci_driver);
}
static void __exit intel_mid_dma_exit(void)
{
pci_unregister_driver(&intel_mid_dma_pci_driver);
}
