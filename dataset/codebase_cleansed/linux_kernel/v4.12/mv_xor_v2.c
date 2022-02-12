static void mv_xor_v2_set_data_buffers(struct mv_xor_v2_device *xor_dev,
struct mv_xor_v2_descriptor *desc,
dma_addr_t src, int index)
{
int arr_index = ((index >> 1) * 3);
if ((index & 0x1) == 0) {
desc->data_buff_addr[arr_index] = lower_32_bits(src);
desc->data_buff_addr[arr_index + 2] &= ~0xFFFF;
desc->data_buff_addr[arr_index + 2] |=
upper_32_bits(src) & 0xFFFF;
} else {
desc->data_buff_addr[arr_index + 1] =
lower_32_bits(src);
desc->data_buff_addr[arr_index + 2] &= ~0xFFFF0000;
desc->data_buff_addr[arr_index + 2] |=
(upper_32_bits(src) & 0xFFFF) << 16;
}
}
static void mv_xor_v2_add_desc_to_desq(struct mv_xor_v2_device *xor_dev,
int num_of_desc)
{
writel(num_of_desc, xor_dev->dma_base + MV_XOR_V2_DMA_DESQ_ADD_OFF);
}
static void mv_xor_v2_free_desc_from_desq(struct mv_xor_v2_device *xor_dev,
int num_of_desc)
{
writel(num_of_desc, xor_dev->dma_base + MV_XOR_V2_DMA_DESQ_DEALLOC_OFF);
}
static int mv_xor_v2_set_desc_size(struct mv_xor_v2_device *xor_dev)
{
writel(MV_XOR_V2_DMA_DESQ_CTRL_128B,
xor_dev->dma_base + MV_XOR_V2_DMA_DESQ_CTRL_OFF);
return MV_XOR_V2_EXT_DESC_SIZE;
}
static irqreturn_t mv_xor_v2_interrupt_handler(int irq, void *data)
{
struct mv_xor_v2_device *xor_dev = data;
unsigned int ndescs;
u32 reg;
reg = readl(xor_dev->dma_base + MV_XOR_V2_DMA_DESQ_DONE_OFF);
ndescs = ((reg >> MV_XOR_V2_DMA_DESQ_DONE_PENDING_SHIFT) &
MV_XOR_V2_DMA_DESQ_DONE_PENDING_MASK);
if (!ndescs)
return IRQ_NONE;
tasklet_schedule(&xor_dev->irq_tasklet);
return IRQ_HANDLED;
}
static dma_cookie_t
mv_xor_v2_tx_submit(struct dma_async_tx_descriptor *tx)
{
void *dest_hw_desc;
dma_cookie_t cookie;
struct mv_xor_v2_sw_desc *sw_desc =
container_of(tx, struct mv_xor_v2_sw_desc, async_tx);
struct mv_xor_v2_device *xor_dev =
container_of(tx->chan, struct mv_xor_v2_device, dmachan);
dev_dbg(xor_dev->dmadev.dev,
"%s sw_desc %p: async_tx %p\n",
__func__, sw_desc, &sw_desc->async_tx);
spin_lock_bh(&xor_dev->lock);
cookie = dma_cookie_assign(tx);
dest_hw_desc = xor_dev->hw_desq_virt + xor_dev->hw_queue_idx;
memcpy(dest_hw_desc, &sw_desc->hw_desc, xor_dev->desc_size);
xor_dev->npendings++;
xor_dev->hw_queue_idx++;
if (xor_dev->hw_queue_idx >= MV_XOR_V2_DESC_NUM)
xor_dev->hw_queue_idx = 0;
spin_unlock_bh(&xor_dev->lock);
return cookie;
}
static struct mv_xor_v2_sw_desc *
mv_xor_v2_prep_sw_desc(struct mv_xor_v2_device *xor_dev)
{
struct mv_xor_v2_sw_desc *sw_desc;
bool found = false;
spin_lock_bh(&xor_dev->lock);
if (list_empty(&xor_dev->free_sw_desc)) {
spin_unlock_bh(&xor_dev->lock);
tasklet_schedule(&xor_dev->irq_tasklet);
return NULL;
}
list_for_each_entry(sw_desc, &xor_dev->free_sw_desc, free_list) {
if (async_tx_test_ack(&sw_desc->async_tx)) {
found = true;
break;
}
}
if (!found) {
spin_unlock_bh(&xor_dev->lock);
return NULL;
}
list_del(&sw_desc->free_list);
spin_unlock_bh(&xor_dev->lock);
return sw_desc;
}
static struct dma_async_tx_descriptor *
mv_xor_v2_prep_dma_memcpy(struct dma_chan *chan, dma_addr_t dest,
dma_addr_t src, size_t len, unsigned long flags)
{
struct mv_xor_v2_sw_desc *sw_desc;
struct mv_xor_v2_descriptor *hw_descriptor;
struct mv_xor_v2_device *xor_dev;
xor_dev = container_of(chan, struct mv_xor_v2_device, dmachan);
dev_dbg(xor_dev->dmadev.dev,
"%s len: %zu src %pad dest %pad flags: %ld\n",
__func__, len, &src, &dest, flags);
sw_desc = mv_xor_v2_prep_sw_desc(xor_dev);
if (!sw_desc)
return NULL;
sw_desc->async_tx.flags = flags;
hw_descriptor = &sw_desc->hw_desc;
hw_descriptor->desc_id = sw_desc->idx;
hw_descriptor->desc_ctrl =
DESC_OP_MODE_MEMCPY << DESC_OP_MODE_SHIFT;
if (flags & DMA_PREP_INTERRUPT)
hw_descriptor->desc_ctrl |= DESC_IOD;
hw_descriptor->fill_pattern_src_addr[0] = lower_32_bits(src);
hw_descriptor->fill_pattern_src_addr[1] =
upper_32_bits(src) & 0xFFFF;
hw_descriptor->fill_pattern_src_addr[2] = lower_32_bits(dest);
hw_descriptor->fill_pattern_src_addr[3] =
upper_32_bits(dest) & 0xFFFF;
hw_descriptor->buff_size = len;
return &sw_desc->async_tx;
}
static struct dma_async_tx_descriptor *
mv_xor_v2_prep_dma_xor(struct dma_chan *chan, dma_addr_t dest, dma_addr_t *src,
unsigned int src_cnt, size_t len, unsigned long flags)
{
struct mv_xor_v2_sw_desc *sw_desc;
struct mv_xor_v2_descriptor *hw_descriptor;
struct mv_xor_v2_device *xor_dev =
container_of(chan, struct mv_xor_v2_device, dmachan);
int i;
if (src_cnt > MV_XOR_V2_CMD_LINE_NUM_MAX_D_BUF || src_cnt < 1)
return NULL;
dev_dbg(xor_dev->dmadev.dev,
"%s src_cnt: %d len: %zu dest %pad flags: %ld\n",
__func__, src_cnt, len, &dest, flags);
sw_desc = mv_xor_v2_prep_sw_desc(xor_dev);
if (!sw_desc)
return NULL;
sw_desc->async_tx.flags = flags;
hw_descriptor = &sw_desc->hw_desc;
hw_descriptor->desc_id = sw_desc->idx;
hw_descriptor->desc_ctrl =
DESC_OP_MODE_XOR << DESC_OP_MODE_SHIFT;
hw_descriptor->desc_ctrl |= DESC_P_BUFFER_ENABLE;
if (flags & DMA_PREP_INTERRUPT)
hw_descriptor->desc_ctrl |= DESC_IOD;
for (i = 0; i < src_cnt; i++)
mv_xor_v2_set_data_buffers(xor_dev, hw_descriptor, src[i], i);
hw_descriptor->desc_ctrl |=
src_cnt << DESC_NUM_ACTIVE_D_BUF_SHIFT;
hw_descriptor->fill_pattern_src_addr[2] = lower_32_bits(dest);
hw_descriptor->fill_pattern_src_addr[3] =
upper_32_bits(dest) & 0xFFFF;
hw_descriptor->buff_size = len;
return &sw_desc->async_tx;
}
static struct dma_async_tx_descriptor *
mv_xor_v2_prep_dma_interrupt(struct dma_chan *chan, unsigned long flags)
{
struct mv_xor_v2_sw_desc *sw_desc;
struct mv_xor_v2_descriptor *hw_descriptor;
struct mv_xor_v2_device *xor_dev =
container_of(chan, struct mv_xor_v2_device, dmachan);
sw_desc = mv_xor_v2_prep_sw_desc(xor_dev);
if (!sw_desc)
return NULL;
hw_descriptor = &sw_desc->hw_desc;
hw_descriptor->desc_id = sw_desc->idx;
hw_descriptor->desc_ctrl =
DESC_OP_MODE_NOP << DESC_OP_MODE_SHIFT;
hw_descriptor->desc_ctrl |= DESC_IOD;
return &sw_desc->async_tx;
}
static void mv_xor_v2_issue_pending(struct dma_chan *chan)
{
struct mv_xor_v2_device *xor_dev =
container_of(chan, struct mv_xor_v2_device, dmachan);
spin_lock_bh(&xor_dev->lock);
mv_xor_v2_add_desc_to_desq(xor_dev, xor_dev->npendings);
xor_dev->npendings = 0;
writel(0, xor_dev->dma_base + MV_XOR_V2_DMA_DESQ_STOP_OFF);
spin_unlock_bh(&xor_dev->lock);
}
static inline
int mv_xor_v2_get_pending_params(struct mv_xor_v2_device *xor_dev,
int *pending_ptr)
{
u32 reg;
reg = readl(xor_dev->dma_base + MV_XOR_V2_DMA_DESQ_DONE_OFF);
*pending_ptr = ((reg >> MV_XOR_V2_DMA_DESQ_DONE_READ_PTR_SHIFT) &
MV_XOR_V2_DMA_DESQ_DONE_READ_PTR_MASK);
return ((reg >> MV_XOR_V2_DMA_DESQ_DONE_PENDING_SHIFT) &
MV_XOR_V2_DMA_DESQ_DONE_PENDING_MASK);
}
static void mv_xor_v2_tasklet(unsigned long data)
{
struct mv_xor_v2_device *xor_dev = (struct mv_xor_v2_device *) data;
int pending_ptr, num_of_pending, i;
struct mv_xor_v2_sw_desc *next_pending_sw_desc = NULL;
dev_dbg(xor_dev->dmadev.dev, "%s %d\n", __func__, __LINE__);
num_of_pending = mv_xor_v2_get_pending_params(xor_dev, &pending_ptr);
for (i = 0; i < num_of_pending; i++) {
struct mv_xor_v2_descriptor *next_pending_hw_desc =
xor_dev->hw_desq_virt + pending_ptr;
next_pending_sw_desc =
&xor_dev->sw_desq[next_pending_hw_desc->desc_id];
if (next_pending_sw_desc->async_tx.cookie > 0) {
dma_cookie_complete(&next_pending_sw_desc->async_tx);
if (next_pending_sw_desc->async_tx.callback)
next_pending_sw_desc->async_tx.callback(
next_pending_sw_desc->async_tx.callback_param);
dma_descriptor_unmap(&next_pending_sw_desc->async_tx);
}
dma_run_dependencies(&next_pending_sw_desc->async_tx);
spin_lock_bh(&xor_dev->lock);
list_add(&next_pending_sw_desc->free_list,
&xor_dev->free_sw_desc);
spin_unlock_bh(&xor_dev->lock);
pending_ptr++;
if (pending_ptr >= MV_XOR_V2_DESC_NUM)
pending_ptr = 0;
}
if (num_of_pending != 0) {
mv_xor_v2_free_desc_from_desq(xor_dev, num_of_pending);
}
}
static void mv_xor_v2_set_msi_msg(struct msi_desc *desc, struct msi_msg *msg)
{
struct mv_xor_v2_device *xor_dev = dev_get_drvdata(desc->dev);
writel(msg->address_lo,
xor_dev->dma_base + MV_XOR_V2_DMA_IMSG_BALR_OFF);
writel(msg->address_hi & 0xFFFF,
xor_dev->dma_base + MV_XOR_V2_DMA_IMSG_BAHR_OFF);
writel(msg->data,
xor_dev->dma_base + MV_XOR_V2_DMA_IMSG_CDAT_OFF);
}
static int mv_xor_v2_descq_init(struct mv_xor_v2_device *xor_dev)
{
u32 reg;
writel(MV_XOR_V2_DESC_NUM,
xor_dev->dma_base + MV_XOR_V2_DMA_DESQ_SIZE_OFF);
writel(xor_dev->hw_desq & 0xFFFFFFFF,
xor_dev->dma_base + MV_XOR_V2_DMA_DESQ_BALR_OFF);
writel((xor_dev->hw_desq & 0xFFFF00000000) >> 32,
xor_dev->dma_base + MV_XOR_V2_DMA_DESQ_BAHR_OFF);
reg = readl(xor_dev->dma_base + MV_XOR_V2_DMA_DESQ_ARATTR_OFF);
reg &= ~MV_XOR_V2_DMA_DESQ_ATTR_CACHE_MASK;
reg |= MV_XOR_V2_DMA_DESQ_ATTR_OUTER_SHAREABLE |
MV_XOR_V2_DMA_DESQ_ATTR_CACHEABLE;
writel(reg, xor_dev->dma_base + MV_XOR_V2_DMA_DESQ_ARATTR_OFF);
reg = readl(xor_dev->dma_base + MV_XOR_V2_DMA_DESQ_AWATTR_OFF);
reg &= ~MV_XOR_V2_DMA_DESQ_ATTR_CACHE_MASK;
reg |= MV_XOR_V2_DMA_DESQ_ATTR_OUTER_SHAREABLE |
MV_XOR_V2_DMA_DESQ_ATTR_CACHEABLE;
writel(reg, xor_dev->dma_base + MV_XOR_V2_DMA_DESQ_AWATTR_OFF);
reg = ((MV_XOR_V2_GLOB_BW_CTRL_NUM_OSTD_RD_VAL <<
MV_XOR_V2_GLOB_BW_CTRL_NUM_OSTD_RD_SHIFT) |
(MV_XOR_V2_GLOB_BW_CTRL_NUM_OSTD_WR_VAL <<
MV_XOR_V2_GLOB_BW_CTRL_NUM_OSTD_WR_SHIFT) |
(MV_XOR_V2_GLOB_BW_CTRL_RD_BURST_LEN_VAL <<
MV_XOR_V2_GLOB_BW_CTRL_RD_BURST_LEN_SHIFT) |
(MV_XOR_V2_GLOB_BW_CTRL_WR_BURST_LEN_VAL <<
MV_XOR_V2_GLOB_BW_CTRL_WR_BURST_LEN_SHIFT));
writel(reg, xor_dev->glob_base + MV_XOR_V2_GLOB_BW_CTRL);
reg = readl(xor_dev->glob_base + MV_XOR_V2_GLOB_PAUSE);
reg |= MV_XOR_V2_GLOB_PAUSE_AXI_TIME_DIS_VAL;
writel(reg, xor_dev->glob_base + MV_XOR_V2_GLOB_PAUSE);
writel(0, xor_dev->dma_base + MV_XOR_V2_DMA_DESQ_STOP_OFF);
return 0;
}
static int mv_xor_v2_probe(struct platform_device *pdev)
{
struct mv_xor_v2_device *xor_dev;
struct resource *res;
int i, ret = 0;
struct dma_device *dma_dev;
struct mv_xor_v2_sw_desc *sw_desc;
struct msi_desc *msi_desc;
BUILD_BUG_ON(sizeof(struct mv_xor_v2_descriptor) !=
MV_XOR_V2_EXT_DESC_SIZE);
xor_dev = devm_kzalloc(&pdev->dev, sizeof(*xor_dev), GFP_KERNEL);
if (!xor_dev)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
xor_dev->dma_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(xor_dev->dma_base))
return PTR_ERR(xor_dev->dma_base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
xor_dev->glob_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(xor_dev->glob_base))
return PTR_ERR(xor_dev->glob_base);
platform_set_drvdata(pdev, xor_dev);
ret = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(40));
if (ret)
return ret;
xor_dev->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(xor_dev->clk) && PTR_ERR(xor_dev->clk) == -EPROBE_DEFER)
return -EPROBE_DEFER;
if (!IS_ERR(xor_dev->clk)) {
ret = clk_prepare_enable(xor_dev->clk);
if (ret)
return ret;
}
ret = platform_msi_domain_alloc_irqs(&pdev->dev, 1,
mv_xor_v2_set_msi_msg);
if (ret)
goto disable_clk;
msi_desc = first_msi_entry(&pdev->dev);
if (!msi_desc)
goto free_msi_irqs;
ret = devm_request_irq(&pdev->dev, msi_desc->irq,
mv_xor_v2_interrupt_handler, 0,
dev_name(&pdev->dev), xor_dev);
if (ret)
goto free_msi_irqs;
tasklet_init(&xor_dev->irq_tasklet, mv_xor_v2_tasklet,
(unsigned long) xor_dev);
xor_dev->desc_size = mv_xor_v2_set_desc_size(xor_dev);
dma_cookie_init(&xor_dev->dmachan);
xor_dev->hw_desq_virt =
dma_alloc_coherent(&pdev->dev,
xor_dev->desc_size * MV_XOR_V2_DESC_NUM,
&xor_dev->hw_desq, GFP_KERNEL);
if (!xor_dev->hw_desq_virt) {
ret = -ENOMEM;
goto free_msi_irqs;
}
xor_dev->sw_desq = devm_kzalloc(&pdev->dev, sizeof(*sw_desc) *
MV_XOR_V2_DESC_NUM, GFP_KERNEL);
if (!xor_dev->sw_desq) {
ret = -ENOMEM;
goto free_hw_desq;
}
spin_lock_init(&xor_dev->lock);
INIT_LIST_HEAD(&xor_dev->free_sw_desc);
for (i = 0; i < MV_XOR_V2_DESC_NUM; i++) {
struct mv_xor_v2_sw_desc *sw_desc =
xor_dev->sw_desq + i;
sw_desc->idx = i;
dma_async_tx_descriptor_init(&sw_desc->async_tx,
&xor_dev->dmachan);
sw_desc->async_tx.tx_submit = mv_xor_v2_tx_submit;
async_tx_ack(&sw_desc->async_tx);
list_add(&sw_desc->free_list,
&xor_dev->free_sw_desc);
}
dma_dev = &xor_dev->dmadev;
dma_cap_zero(dma_dev->cap_mask);
dma_cap_set(DMA_MEMCPY, dma_dev->cap_mask);
dma_cap_set(DMA_XOR, dma_dev->cap_mask);
dma_cap_set(DMA_INTERRUPT, dma_dev->cap_mask);
INIT_LIST_HEAD(&dma_dev->channels);
dma_dev->device_tx_status = dma_cookie_status;
dma_dev->device_issue_pending = mv_xor_v2_issue_pending;
dma_dev->dev = &pdev->dev;
dma_dev->device_prep_dma_memcpy = mv_xor_v2_prep_dma_memcpy;
dma_dev->device_prep_dma_interrupt = mv_xor_v2_prep_dma_interrupt;
dma_dev->max_xor = 8;
dma_dev->device_prep_dma_xor = mv_xor_v2_prep_dma_xor;
xor_dev->dmachan.device = dma_dev;
list_add_tail(&xor_dev->dmachan.device_node,
&dma_dev->channels);
mv_xor_v2_descq_init(xor_dev);
ret = dma_async_device_register(dma_dev);
if (ret)
goto free_hw_desq;
dev_notice(&pdev->dev, "Marvell Version 2 XOR driver\n");
return 0;
free_hw_desq:
dma_free_coherent(&pdev->dev,
xor_dev->desc_size * MV_XOR_V2_DESC_NUM,
xor_dev->hw_desq_virt, xor_dev->hw_desq);
free_msi_irqs:
platform_msi_domain_free_irqs(&pdev->dev);
disable_clk:
if (!IS_ERR(xor_dev->clk))
clk_disable_unprepare(xor_dev->clk);
return ret;
}
static int mv_xor_v2_remove(struct platform_device *pdev)
{
struct mv_xor_v2_device *xor_dev = platform_get_drvdata(pdev);
dma_async_device_unregister(&xor_dev->dmadev);
dma_free_coherent(&pdev->dev,
xor_dev->desc_size * MV_XOR_V2_DESC_NUM,
xor_dev->hw_desq_virt, xor_dev->hw_desq);
platform_msi_domain_free_irqs(&pdev->dev);
clk_disable_unprepare(xor_dev->clk);
return 0;
}
