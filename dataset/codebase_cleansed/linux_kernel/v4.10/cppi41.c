static struct cppi41_channel *to_cpp41_chan(struct dma_chan *c)
{
return container_of(c, struct cppi41_channel, chan);
}
static struct cppi41_channel *desc_to_chan(struct cppi41_dd *cdd, u32 desc)
{
struct cppi41_channel *c;
u32 descs_size;
u32 desc_num;
descs_size = sizeof(struct cppi41_desc) * ALLOC_DECS_NUM;
if (!((desc >= cdd->descs_phys) &&
(desc < (cdd->descs_phys + descs_size)))) {
return NULL;
}
desc_num = (desc - cdd->descs_phys) / sizeof(struct cppi41_desc);
BUG_ON(desc_num >= ALLOC_DECS_NUM);
c = cdd->chan_busy[desc_num];
cdd->chan_busy[desc_num] = NULL;
pm_runtime_put(cdd->ddev.dev);
return c;
}
static void cppi_writel(u32 val, void *__iomem *mem)
{
__raw_writel(val, mem);
}
static u32 cppi_readl(void *__iomem *mem)
{
return __raw_readl(mem);
}
static u32 pd_trans_len(u32 val)
{
return val & ((1 << (DESC_LENGTH_BITS_NUM + 1)) - 1);
}
static u32 cppi41_pop_desc(struct cppi41_dd *cdd, unsigned queue_num)
{
u32 desc;
desc = cppi_readl(cdd->qmgr_mem + QMGR_QUEUE_D(queue_num));
desc &= ~0x1f;
return desc;
}
static irqreturn_t cppi41_irq(int irq, void *data)
{
struct cppi41_dd *cdd = data;
struct cppi41_channel *c;
u32 status;
int i;
status = cppi_readl(cdd->usbss_mem + USBSS_IRQ_STATUS);
if (!(status & USBSS_IRQ_PD_COMP))
return IRQ_NONE;
cppi_writel(status, cdd->usbss_mem + USBSS_IRQ_STATUS);
for (i = QMGR_PENDING_SLOT_Q(FIST_COMPLETION_QUEUE); i < QMGR_NUM_PEND;
i++) {
u32 val;
u32 q_num;
val = cppi_readl(cdd->qmgr_mem + QMGR_PEND(i));
if (i == QMGR_PENDING_SLOT_Q(FIST_COMPLETION_QUEUE) && val) {
u32 mask;
mask = 1 << QMGR_PENDING_BIT_Q(FIST_COMPLETION_QUEUE);
mask--;
val &= ~mask;
}
if (val)
__iormb();
while (val) {
u32 desc, len;
WARN_ON(cdd->is_suspended);
q_num = __fls(val);
val &= ~(1 << q_num);
q_num += 32 * i;
desc = cppi41_pop_desc(cdd, q_num);
c = desc_to_chan(cdd, desc);
if (WARN_ON(!c)) {
pr_err("%s() q %d desc %08x\n", __func__,
q_num, desc);
continue;
}
if (c->desc->pd2 & PD2_ZERO_LENGTH)
len = 0;
else
len = pd_trans_len(c->desc->pd0);
c->residue = pd_trans_len(c->desc->pd6) - len;
dma_cookie_complete(&c->txd);
dmaengine_desc_get_callback_invoke(&c->txd, NULL);
}
}
return IRQ_HANDLED;
}
static dma_cookie_t cppi41_tx_submit(struct dma_async_tx_descriptor *tx)
{
dma_cookie_t cookie;
cookie = dma_cookie_assign(tx);
return cookie;
}
static int cppi41_dma_alloc_chan_resources(struct dma_chan *chan)
{
struct cppi41_channel *c = to_cpp41_chan(chan);
struct cppi41_dd *cdd = c->cdd;
int error;
error = pm_runtime_get_sync(cdd->ddev.dev);
if (error < 0) {
dev_err(cdd->ddev.dev, "%s pm runtime get: %i\n",
__func__, error);
pm_runtime_put_noidle(cdd->ddev.dev);
return error;
}
dma_cookie_init(chan);
dma_async_tx_descriptor_init(&c->txd, chan);
c->txd.tx_submit = cppi41_tx_submit;
if (!c->is_tx)
cppi_writel(c->q_num, c->gcr_reg + RXHPCRA0);
pm_runtime_mark_last_busy(cdd->ddev.dev);
pm_runtime_put_autosuspend(cdd->ddev.dev);
return 0;
}
static void cppi41_dma_free_chan_resources(struct dma_chan *chan)
{
struct cppi41_channel *c = to_cpp41_chan(chan);
struct cppi41_dd *cdd = c->cdd;
int error;
error = pm_runtime_get_sync(cdd->ddev.dev);
if (error < 0) {
pm_runtime_put_noidle(cdd->ddev.dev);
return;
}
WARN_ON(!list_empty(&cdd->pending));
pm_runtime_mark_last_busy(cdd->ddev.dev);
pm_runtime_put_autosuspend(cdd->ddev.dev);
}
static enum dma_status cppi41_dma_tx_status(struct dma_chan *chan,
dma_cookie_t cookie, struct dma_tx_state *txstate)
{
struct cppi41_channel *c = to_cpp41_chan(chan);
enum dma_status ret;
ret = dma_cookie_status(chan, cookie, txstate);
if (txstate && ret == DMA_COMPLETE)
txstate->residue = c->residue;
return ret;
}
static void push_desc_queue(struct cppi41_channel *c)
{
struct cppi41_dd *cdd = c->cdd;
u32 desc_num;
u32 desc_phys;
u32 reg;
c->residue = 0;
reg = GCR_CHAN_ENABLE;
if (!c->is_tx) {
reg |= GCR_STARV_RETRY;
reg |= GCR_DESC_TYPE_HOST;
reg |= c->q_comp_num;
}
cppi_writel(reg, c->gcr_reg);
__iowmb();
pm_runtime_get(cdd->ddev.dev);
desc_phys = lower_32_bits(c->desc_phys);
desc_num = (desc_phys - cdd->descs_phys) / sizeof(struct cppi41_desc);
WARN_ON(cdd->chan_busy[desc_num]);
cdd->chan_busy[desc_num] = c;
reg = (sizeof(struct cppi41_desc) - 24) / 4;
reg |= desc_phys;
cppi_writel(reg, cdd->qmgr_mem + QMGR_QUEUE_D(c->q_num));
}
static void cppi41_run_queue(struct cppi41_dd *cdd)
{
struct cppi41_channel *c, *_c;
list_for_each_entry_safe(c, _c, &cdd->pending, node) {
push_desc_queue(c);
list_del(&c->node);
}
}
static void cppi41_dma_issue_pending(struct dma_chan *chan)
{
struct cppi41_channel *c = to_cpp41_chan(chan);
struct cppi41_dd *cdd = c->cdd;
unsigned long flags;
int error;
error = pm_runtime_get(cdd->ddev.dev);
if ((error != -EINPROGRESS) && error < 0) {
pm_runtime_put_noidle(cdd->ddev.dev);
dev_err(cdd->ddev.dev, "Failed to pm_runtime_get: %i\n",
error);
return;
}
spin_lock_irqsave(&cdd->lock, flags);
list_add_tail(&c->node, &cdd->pending);
if (!cdd->is_suspended)
cppi41_run_queue(cdd);
spin_unlock_irqrestore(&cdd->lock, flags);
pm_runtime_mark_last_busy(cdd->ddev.dev);
pm_runtime_put_autosuspend(cdd->ddev.dev);
}
static u32 get_host_pd0(u32 length)
{
u32 reg;
reg = DESC_TYPE_HOST << DESC_TYPE;
reg |= length;
return reg;
}
static u32 get_host_pd1(struct cppi41_channel *c)
{
u32 reg;
reg = 0;
return reg;
}
static u32 get_host_pd2(struct cppi41_channel *c)
{
u32 reg;
reg = DESC_TYPE_USB;
reg |= c->q_comp_num;
return reg;
}
static u32 get_host_pd3(u32 length)
{
u32 reg;
reg = length;
return reg;
}
static u32 get_host_pd6(u32 length)
{
u32 reg;
reg = DESC_PD_COMPLETE;
reg |= length;
return reg;
}
static u32 get_host_pd4_or_7(u32 addr)
{
u32 reg;
reg = addr;
return reg;
}
static u32 get_host_pd5(void)
{
u32 reg;
reg = 0;
return reg;
}
static struct dma_async_tx_descriptor *cppi41_dma_prep_slave_sg(
struct dma_chan *chan, struct scatterlist *sgl, unsigned sg_len,
enum dma_transfer_direction dir, unsigned long tx_flags, void *context)
{
struct cppi41_channel *c = to_cpp41_chan(chan);
struct cppi41_desc *d;
struct scatterlist *sg;
unsigned int i;
d = c->desc;
for_each_sg(sgl, sg, sg_len, i) {
u32 addr;
u32 len;
addr = lower_32_bits(sg_dma_address(sg));
len = sg_dma_len(sg);
d->pd0 = get_host_pd0(len);
d->pd1 = get_host_pd1(c);
d->pd2 = get_host_pd2(c);
d->pd3 = get_host_pd3(len);
d->pd4 = get_host_pd4_or_7(addr);
d->pd5 = get_host_pd5();
d->pd6 = get_host_pd6(len);
d->pd7 = get_host_pd4_or_7(addr);
d++;
}
return &c->txd;
}
static void cppi41_compute_td_desc(struct cppi41_desc *d)
{
d->pd0 = DESC_TYPE_TEARD << DESC_TYPE;
}
static int cppi41_tear_down_chan(struct cppi41_channel *c)
{
struct cppi41_dd *cdd = c->cdd;
struct cppi41_desc *td;
u32 reg;
u32 desc_phys;
u32 td_desc_phys;
td = cdd->cd;
td += cdd->first_td_desc;
td_desc_phys = cdd->descs_phys;
td_desc_phys += cdd->first_td_desc * sizeof(struct cppi41_desc);
if (!c->td_queued) {
cppi41_compute_td_desc(td);
__iowmb();
reg = (sizeof(struct cppi41_desc) - 24) / 4;
reg |= td_desc_phys;
cppi_writel(reg, cdd->qmgr_mem +
QMGR_QUEUE_D(cdd->td_queue.submit));
reg = GCR_CHAN_ENABLE;
if (!c->is_tx) {
reg |= GCR_STARV_RETRY;
reg |= GCR_DESC_TYPE_HOST;
reg |= c->q_comp_num;
}
reg |= GCR_TEARDOWN;
cppi_writel(reg, c->gcr_reg);
c->td_queued = 1;
c->td_retry = 500;
}
if (!c->td_seen || !c->td_desc_seen) {
desc_phys = cppi41_pop_desc(cdd, cdd->td_queue.complete);
if (!desc_phys)
desc_phys = cppi41_pop_desc(cdd, c->q_comp_num);
if (desc_phys == c->desc_phys) {
c->td_desc_seen = 1;
} else if (desc_phys == td_desc_phys) {
u32 pd0;
__iormb();
pd0 = td->pd0;
WARN_ON((pd0 >> DESC_TYPE) != DESC_TYPE_TEARD);
WARN_ON(!c->is_tx && !(pd0 & TD_DESC_IS_RX));
WARN_ON((pd0 & 0x1f) != c->port_num);
c->td_seen = 1;
} else if (desc_phys) {
WARN_ON_ONCE(1);
}
}
c->td_retry--;
if (!c->td_seen && c->td_retry) {
udelay(1);
return -EAGAIN;
}
WARN_ON(!c->td_retry);
if (!c->td_desc_seen) {
desc_phys = cppi41_pop_desc(cdd, c->q_num);
if (!desc_phys)
desc_phys = cppi41_pop_desc(cdd, c->q_comp_num);
WARN_ON(!desc_phys);
}
c->td_queued = 0;
c->td_seen = 0;
c->td_desc_seen = 0;
cppi_writel(0, c->gcr_reg);
return 0;
}
static int cppi41_stop_chan(struct dma_chan *chan)
{
struct cppi41_channel *c = to_cpp41_chan(chan);
struct cppi41_dd *cdd = c->cdd;
u32 desc_num;
u32 desc_phys;
int ret;
desc_phys = lower_32_bits(c->desc_phys);
desc_num = (desc_phys - cdd->descs_phys) / sizeof(struct cppi41_desc);
if (!cdd->chan_busy[desc_num])
return 0;
ret = cppi41_tear_down_chan(c);
if (ret)
return ret;
WARN_ON(!cdd->chan_busy[desc_num]);
cdd->chan_busy[desc_num] = NULL;
pm_runtime_put(cdd->ddev.dev);
return 0;
}
static void cleanup_chans(struct cppi41_dd *cdd)
{
while (!list_empty(&cdd->ddev.channels)) {
struct cppi41_channel *cchan;
cchan = list_first_entry(&cdd->ddev.channels,
struct cppi41_channel, chan.device_node);
list_del(&cchan->chan.device_node);
kfree(cchan);
}
}
static int cppi41_add_chans(struct device *dev, struct cppi41_dd *cdd)
{
struct cppi41_channel *cchan;
int i;
int ret;
u32 n_chans;
ret = of_property_read_u32(dev->of_node, "#dma-channels",
&n_chans);
if (ret)
return ret;
n_chans *= 2;
for (i = 0; i < n_chans; i++) {
cchan = kzalloc(sizeof(*cchan), GFP_KERNEL);
if (!cchan)
goto err;
cchan->cdd = cdd;
if (i & 1) {
cchan->gcr_reg = cdd->ctrl_mem + DMA_TXGCR(i >> 1);
cchan->is_tx = 1;
} else {
cchan->gcr_reg = cdd->ctrl_mem + DMA_RXGCR(i >> 1);
cchan->is_tx = 0;
}
cchan->port_num = i >> 1;
cchan->desc = &cdd->cd[i];
cchan->desc_phys = cdd->descs_phys;
cchan->desc_phys += i * sizeof(struct cppi41_desc);
cchan->chan.device = &cdd->ddev;
list_add_tail(&cchan->chan.device_node, &cdd->ddev.channels);
}
cdd->first_td_desc = n_chans;
return 0;
err:
cleanup_chans(cdd);
return -ENOMEM;
}
static void purge_descs(struct device *dev, struct cppi41_dd *cdd)
{
unsigned int mem_decs;
int i;
mem_decs = ALLOC_DECS_NUM * sizeof(struct cppi41_desc);
for (i = 0; i < DESCS_AREAS; i++) {
cppi_writel(0, cdd->qmgr_mem + QMGR_MEMBASE(i));
cppi_writel(0, cdd->qmgr_mem + QMGR_MEMCTRL(i));
dma_free_coherent(dev, mem_decs, cdd->cd,
cdd->descs_phys);
}
}
static void disable_sched(struct cppi41_dd *cdd)
{
cppi_writel(0, cdd->sched_mem + DMA_SCHED_CTRL);
}
static void deinit_cppi41(struct device *dev, struct cppi41_dd *cdd)
{
disable_sched(cdd);
purge_descs(dev, cdd);
cppi_writel(0, cdd->qmgr_mem + QMGR_LRAM0_BASE);
cppi_writel(0, cdd->qmgr_mem + QMGR_LRAM0_BASE);
dma_free_coherent(dev, QMGR_SCRATCH_SIZE, cdd->qmgr_scratch,
cdd->scratch_phys);
}
static int init_descs(struct device *dev, struct cppi41_dd *cdd)
{
unsigned int desc_size;
unsigned int mem_decs;
int i;
u32 reg;
u32 idx;
BUILD_BUG_ON(sizeof(struct cppi41_desc) &
(sizeof(struct cppi41_desc) - 1));
BUILD_BUG_ON(sizeof(struct cppi41_desc) < 32);
BUILD_BUG_ON(ALLOC_DECS_NUM < 32);
desc_size = sizeof(struct cppi41_desc);
mem_decs = ALLOC_DECS_NUM * desc_size;
idx = 0;
for (i = 0; i < DESCS_AREAS; i++) {
reg = idx << QMGR_MEMCTRL_IDX_SH;
reg |= (ilog2(desc_size) - 5) << QMGR_MEMCTRL_DESC_SH;
reg |= ilog2(ALLOC_DECS_NUM) - 5;
BUILD_BUG_ON(DESCS_AREAS != 1);
cdd->cd = dma_alloc_coherent(dev, mem_decs,
&cdd->descs_phys, GFP_KERNEL);
if (!cdd->cd)
return -ENOMEM;
cppi_writel(cdd->descs_phys, cdd->qmgr_mem + QMGR_MEMBASE(i));
cppi_writel(reg, cdd->qmgr_mem + QMGR_MEMCTRL(i));
idx += ALLOC_DECS_NUM;
}
return 0;
}
static void init_sched(struct cppi41_dd *cdd)
{
unsigned ch;
unsigned word;
u32 reg;
word = 0;
cppi_writel(0, cdd->sched_mem + DMA_SCHED_CTRL);
for (ch = 0; ch < 15 * 2; ch += 2) {
reg = SCHED_ENTRY0_CHAN(ch);
reg |= SCHED_ENTRY1_CHAN(ch) | SCHED_ENTRY1_IS_RX;
reg |= SCHED_ENTRY2_CHAN(ch + 1);
reg |= SCHED_ENTRY3_CHAN(ch + 1) | SCHED_ENTRY3_IS_RX;
cppi_writel(reg, cdd->sched_mem + DMA_SCHED_WORD(word));
word++;
}
reg = 15 * 2 * 2 - 1;
reg |= DMA_SCHED_CTRL_EN;
cppi_writel(reg, cdd->sched_mem + DMA_SCHED_CTRL);
}
static int init_cppi41(struct device *dev, struct cppi41_dd *cdd)
{
int ret;
BUILD_BUG_ON(QMGR_SCRATCH_SIZE > ((1 << 14) - 1));
cdd->qmgr_scratch = dma_alloc_coherent(dev, QMGR_SCRATCH_SIZE,
&cdd->scratch_phys, GFP_KERNEL);
if (!cdd->qmgr_scratch)
return -ENOMEM;
cppi_writel(cdd->scratch_phys, cdd->qmgr_mem + QMGR_LRAM0_BASE);
cppi_writel(QMGR_SCRATCH_SIZE, cdd->qmgr_mem + QMGR_LRAM_SIZE);
cppi_writel(0, cdd->qmgr_mem + QMGR_LRAM1_BASE);
ret = init_descs(dev, cdd);
if (ret)
goto err_td;
cppi_writel(cdd->td_queue.submit, cdd->ctrl_mem + DMA_TDFDQ);
init_sched(cdd);
return 0;
err_td:
deinit_cppi41(dev, cdd);
return ret;
}
static bool cpp41_dma_filter_fn(struct dma_chan *chan, void *param)
{
struct cppi41_channel *cchan;
struct cppi41_dd *cdd;
const struct chan_queues *queues;
u32 *num = param;
if (chan->device->dev->driver != &cpp41_dma_driver.driver)
return false;
cchan = to_cpp41_chan(chan);
if (cchan->port_num != num[INFO_PORT])
return false;
if (cchan->is_tx && !num[INFO_IS_TX])
return false;
cdd = cchan->cdd;
if (cchan->is_tx)
queues = cdd->queues_tx;
else
queues = cdd->queues_rx;
BUILD_BUG_ON(ARRAY_SIZE(usb_queues_rx) != ARRAY_SIZE(usb_queues_tx));
if (WARN_ON(cchan->port_num > ARRAY_SIZE(usb_queues_rx)))
return false;
cchan->q_num = queues[cchan->port_num].submit;
cchan->q_comp_num = queues[cchan->port_num].complete;
return true;
}
static struct dma_chan *cppi41_dma_xlate(struct of_phandle_args *dma_spec,
struct of_dma *ofdma)
{
int count = dma_spec->args_count;
struct of_dma_filter_info *info = ofdma->of_dma_data;
if (!info || !info->filter_fn)
return NULL;
if (count != 2)
return NULL;
return dma_request_channel(info->dma_cap, info->filter_fn,
&dma_spec->args[0]);
}
static const struct cppi_glue_infos *get_glue_info(struct device *dev)
{
const struct of_device_id *of_id;
of_id = of_match_node(cppi41_dma_ids, dev->of_node);
if (!of_id)
return NULL;
return of_id->data;
}
static int cppi41_dma_probe(struct platform_device *pdev)
{
struct cppi41_dd *cdd;
struct device *dev = &pdev->dev;
const struct cppi_glue_infos *glue_info;
int irq;
int ret;
glue_info = get_glue_info(dev);
if (!glue_info)
return -EINVAL;
cdd = devm_kzalloc(&pdev->dev, sizeof(*cdd), GFP_KERNEL);
if (!cdd)
return -ENOMEM;
dma_cap_set(DMA_SLAVE, cdd->ddev.cap_mask);
cdd->ddev.device_alloc_chan_resources = cppi41_dma_alloc_chan_resources;
cdd->ddev.device_free_chan_resources = cppi41_dma_free_chan_resources;
cdd->ddev.device_tx_status = cppi41_dma_tx_status;
cdd->ddev.device_issue_pending = cppi41_dma_issue_pending;
cdd->ddev.device_prep_slave_sg = cppi41_dma_prep_slave_sg;
cdd->ddev.device_terminate_all = cppi41_stop_chan;
cdd->ddev.directions = BIT(DMA_DEV_TO_MEM) | BIT(DMA_MEM_TO_DEV);
cdd->ddev.src_addr_widths = CPPI41_DMA_BUSWIDTHS;
cdd->ddev.dst_addr_widths = CPPI41_DMA_BUSWIDTHS;
cdd->ddev.residue_granularity = DMA_RESIDUE_GRANULARITY_BURST;
cdd->ddev.dev = dev;
INIT_LIST_HEAD(&cdd->ddev.channels);
cpp41_dma_info.dma_cap = cdd->ddev.cap_mask;
cdd->usbss_mem = of_iomap(dev->of_node, 0);
cdd->ctrl_mem = of_iomap(dev->of_node, 1);
cdd->sched_mem = of_iomap(dev->of_node, 2);
cdd->qmgr_mem = of_iomap(dev->of_node, 3);
spin_lock_init(&cdd->lock);
INIT_LIST_HEAD(&cdd->pending);
platform_set_drvdata(pdev, cdd);
if (!cdd->usbss_mem || !cdd->ctrl_mem || !cdd->sched_mem ||
!cdd->qmgr_mem)
return -ENXIO;
pm_runtime_enable(dev);
pm_runtime_set_autosuspend_delay(dev, 100);
pm_runtime_use_autosuspend(dev);
ret = pm_runtime_get_sync(dev);
if (ret < 0)
goto err_get_sync;
cdd->queues_rx = glue_info->queues_rx;
cdd->queues_tx = glue_info->queues_tx;
cdd->td_queue = glue_info->td_queue;
ret = init_cppi41(dev, cdd);
if (ret)
goto err_init_cppi;
ret = cppi41_add_chans(dev, cdd);
if (ret)
goto err_chans;
irq = irq_of_parse_and_map(dev->of_node, 0);
if (!irq) {
ret = -EINVAL;
goto err_irq;
}
cppi_writel(USBSS_IRQ_PD_COMP, cdd->usbss_mem + USBSS_IRQ_ENABLER);
ret = devm_request_irq(&pdev->dev, irq, glue_info->isr, IRQF_SHARED,
dev_name(dev), cdd);
if (ret)
goto err_irq;
cdd->irq = irq;
ret = dma_async_device_register(&cdd->ddev);
if (ret)
goto err_dma_reg;
ret = of_dma_controller_register(dev->of_node,
cppi41_dma_xlate, &cpp41_dma_info);
if (ret)
goto err_of;
pm_runtime_mark_last_busy(dev);
pm_runtime_put_autosuspend(dev);
return 0;
err_of:
dma_async_device_unregister(&cdd->ddev);
err_dma_reg:
err_irq:
cppi_writel(0, cdd->usbss_mem + USBSS_IRQ_CLEARR);
cleanup_chans(cdd);
err_chans:
deinit_cppi41(dev, cdd);
err_init_cppi:
pm_runtime_dont_use_autosuspend(dev);
err_get_sync:
pm_runtime_put_sync(dev);
pm_runtime_disable(dev);
iounmap(cdd->usbss_mem);
iounmap(cdd->ctrl_mem);
iounmap(cdd->sched_mem);
iounmap(cdd->qmgr_mem);
return ret;
}
static int cppi41_dma_remove(struct platform_device *pdev)
{
struct cppi41_dd *cdd = platform_get_drvdata(pdev);
int error;
error = pm_runtime_get_sync(&pdev->dev);
if (error < 0)
dev_err(&pdev->dev, "%s could not pm_runtime_get: %i\n",
__func__, error);
of_dma_controller_free(pdev->dev.of_node);
dma_async_device_unregister(&cdd->ddev);
cppi_writel(0, cdd->usbss_mem + USBSS_IRQ_CLEARR);
devm_free_irq(&pdev->dev, cdd->irq, cdd);
cleanup_chans(cdd);
deinit_cppi41(&pdev->dev, cdd);
iounmap(cdd->usbss_mem);
iounmap(cdd->ctrl_mem);
iounmap(cdd->sched_mem);
iounmap(cdd->qmgr_mem);
pm_runtime_dont_use_autosuspend(&pdev->dev);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int __maybe_unused cppi41_suspend(struct device *dev)
{
struct cppi41_dd *cdd = dev_get_drvdata(dev);
cdd->dma_tdfdq = cppi_readl(cdd->ctrl_mem + DMA_TDFDQ);
cppi_writel(0, cdd->usbss_mem + USBSS_IRQ_CLEARR);
disable_sched(cdd);
return 0;
}
static int __maybe_unused cppi41_resume(struct device *dev)
{
struct cppi41_dd *cdd = dev_get_drvdata(dev);
struct cppi41_channel *c;
int i;
for (i = 0; i < DESCS_AREAS; i++)
cppi_writel(cdd->descs_phys, cdd->qmgr_mem + QMGR_MEMBASE(i));
list_for_each_entry(c, &cdd->ddev.channels, chan.device_node)
if (!c->is_tx)
cppi_writel(c->q_num, c->gcr_reg + RXHPCRA0);
init_sched(cdd);
cppi_writel(cdd->dma_tdfdq, cdd->ctrl_mem + DMA_TDFDQ);
cppi_writel(cdd->scratch_phys, cdd->qmgr_mem + QMGR_LRAM0_BASE);
cppi_writel(QMGR_SCRATCH_SIZE, cdd->qmgr_mem + QMGR_LRAM_SIZE);
cppi_writel(0, cdd->qmgr_mem + QMGR_LRAM1_BASE);
cppi_writel(USBSS_IRQ_PD_COMP, cdd->usbss_mem + USBSS_IRQ_ENABLER);
return 0;
}
static int __maybe_unused cppi41_runtime_suspend(struct device *dev)
{
struct cppi41_dd *cdd = dev_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&cdd->lock, flags);
cdd->is_suspended = true;
WARN_ON(!list_empty(&cdd->pending));
spin_unlock_irqrestore(&cdd->lock, flags);
return 0;
}
static int __maybe_unused cppi41_runtime_resume(struct device *dev)
{
struct cppi41_dd *cdd = dev_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&cdd->lock, flags);
cdd->is_suspended = false;
cppi41_run_queue(cdd);
spin_unlock_irqrestore(&cdd->lock, flags);
return 0;
}
