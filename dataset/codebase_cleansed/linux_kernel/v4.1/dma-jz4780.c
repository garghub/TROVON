static inline struct jz4780_dma_chan *to_jz4780_dma_chan(struct dma_chan *chan)
{
return container_of(chan, struct jz4780_dma_chan, vchan.chan);
}
static inline struct jz4780_dma_desc *to_jz4780_dma_desc(
struct virt_dma_desc *vdesc)
{
return container_of(vdesc, struct jz4780_dma_desc, vdesc);
}
static inline struct jz4780_dma_dev *jz4780_dma_chan_parent(
struct jz4780_dma_chan *jzchan)
{
return container_of(jzchan->vchan.chan.device, struct jz4780_dma_dev,
dma_device);
}
static inline uint32_t jz4780_dma_readl(struct jz4780_dma_dev *jzdma,
unsigned int reg)
{
return readl(jzdma->base + reg);
}
static inline void jz4780_dma_writel(struct jz4780_dma_dev *jzdma,
unsigned int reg, uint32_t val)
{
writel(val, jzdma->base + reg);
}
static struct jz4780_dma_desc *jz4780_dma_desc_alloc(
struct jz4780_dma_chan *jzchan, unsigned int count,
enum dma_transaction_type type)
{
struct jz4780_dma_desc *desc;
if (count > JZ_DMA_MAX_DESC)
return NULL;
desc = kzalloc(sizeof(*desc), GFP_NOWAIT);
if (!desc)
return NULL;
desc->desc = dma_pool_alloc(jzchan->desc_pool, GFP_NOWAIT,
&desc->desc_phys);
if (!desc->desc) {
kfree(desc);
return NULL;
}
desc->count = count;
desc->type = type;
return desc;
}
static void jz4780_dma_desc_free(struct virt_dma_desc *vdesc)
{
struct jz4780_dma_desc *desc = to_jz4780_dma_desc(vdesc);
struct jz4780_dma_chan *jzchan = to_jz4780_dma_chan(vdesc->tx.chan);
dma_pool_free(jzchan->desc_pool, desc->desc, desc->desc_phys);
kfree(desc);
}
static uint32_t jz4780_dma_transfer_size(unsigned long val, int *ord)
{
*ord = ffs(val) - 1;
switch (*ord) {
case 0:
return JZ_DMA_SIZE_1_BYTE;
case 1:
return JZ_DMA_SIZE_2_BYTE;
case 2:
return JZ_DMA_SIZE_4_BYTE;
case 4:
return JZ_DMA_SIZE_16_BYTE;
case 5:
return JZ_DMA_SIZE_32_BYTE;
case 6:
return JZ_DMA_SIZE_64_BYTE;
case 7:
return JZ_DMA_SIZE_128_BYTE;
default:
return -EINVAL;
}
}
static uint32_t jz4780_dma_setup_hwdesc(struct jz4780_dma_chan *jzchan,
struct jz4780_dma_hwdesc *desc, dma_addr_t addr, size_t len,
enum dma_transfer_direction direction)
{
struct dma_slave_config *config = &jzchan->config;
uint32_t width, maxburst, tsz;
int ord;
if (direction == DMA_MEM_TO_DEV) {
desc->dcm = JZ_DMA_DCM_SAI;
desc->dsa = addr;
desc->dta = config->dst_addr;
desc->drt = jzchan->transfer_type;
width = config->dst_addr_width;
maxburst = config->dst_maxburst;
} else {
desc->dcm = JZ_DMA_DCM_DAI;
desc->dsa = config->src_addr;
desc->dta = addr;
desc->drt = jzchan->transfer_type;
width = config->src_addr_width;
maxburst = config->src_maxburst;
}
tsz = jz4780_dma_transfer_size(addr | len | (width * maxburst), &ord);
jzchan->transfer_shift = ord;
switch (width) {
case DMA_SLAVE_BUSWIDTH_1_BYTE:
case DMA_SLAVE_BUSWIDTH_2_BYTES:
break;
case DMA_SLAVE_BUSWIDTH_4_BYTES:
width = JZ_DMA_WIDTH_32_BIT;
break;
default:
return -EINVAL;
}
desc->dcm |= tsz << JZ_DMA_DCM_TSZ_SHIFT;
desc->dcm |= width << JZ_DMA_DCM_SP_SHIFT;
desc->dcm |= width << JZ_DMA_DCM_DP_SHIFT;
desc->dtc = len >> ord;
}
static struct dma_async_tx_descriptor *jz4780_dma_prep_slave_sg(
struct dma_chan *chan, struct scatterlist *sgl, unsigned int sg_len,
enum dma_transfer_direction direction, unsigned long flags)
{
struct jz4780_dma_chan *jzchan = to_jz4780_dma_chan(chan);
struct jz4780_dma_desc *desc;
unsigned int i;
int err;
desc = jz4780_dma_desc_alloc(jzchan, sg_len, DMA_SLAVE);
if (!desc)
return NULL;
for (i = 0; i < sg_len; i++) {
err = jz4780_dma_setup_hwdesc(jzchan, &desc->desc[i],
sg_dma_address(&sgl[i]),
sg_dma_len(&sgl[i]),
direction);
if (err < 0)
return ERR_PTR(err);
desc->desc[i].dcm |= JZ_DMA_DCM_TIE;
if (i != (sg_len - 1)) {
desc->desc[i].dcm |= JZ_DMA_DCM_LINK;
desc->desc[i].dtc |=
(((i + 1) * sizeof(*desc->desc)) >> 4) << 24;
}
}
return vchan_tx_prep(&jzchan->vchan, &desc->vdesc, flags);
}
static struct dma_async_tx_descriptor *jz4780_dma_prep_dma_cyclic(
struct dma_chan *chan, dma_addr_t buf_addr, size_t buf_len,
size_t period_len, enum dma_transfer_direction direction,
unsigned long flags)
{
struct jz4780_dma_chan *jzchan = to_jz4780_dma_chan(chan);
struct jz4780_dma_desc *desc;
unsigned int periods, i;
int err;
if (buf_len % period_len)
return NULL;
periods = buf_len / period_len;
desc = jz4780_dma_desc_alloc(jzchan, periods, DMA_CYCLIC);
if (!desc)
return NULL;
for (i = 0; i < periods; i++) {
err = jz4780_dma_setup_hwdesc(jzchan, &desc->desc[i], buf_addr,
period_len, direction);
if (err < 0)
return ERR_PTR(err);
buf_addr += period_len;
desc->desc[i].dcm |= JZ_DMA_DCM_TIE | JZ_DMA_DCM_LINK;
if (i != (periods - 1)) {
desc->desc[i].dtc |=
(((i + 1) * sizeof(*desc->desc)) >> 4) << 24;
}
}
return vchan_tx_prep(&jzchan->vchan, &desc->vdesc, flags);
}
struct dma_async_tx_descriptor *jz4780_dma_prep_dma_memcpy(
struct dma_chan *chan, dma_addr_t dest, dma_addr_t src,
size_t len, unsigned long flags)
{
struct jz4780_dma_chan *jzchan = to_jz4780_dma_chan(chan);
struct jz4780_dma_desc *desc;
uint32_t tsz;
int ord;
desc = jz4780_dma_desc_alloc(jzchan, 1, DMA_MEMCPY);
if (!desc)
return NULL;
tsz = jz4780_dma_transfer_size(dest | src | len, &ord);
if (tsz < 0)
return ERR_PTR(tsz);
desc->desc[0].dsa = src;
desc->desc[0].dta = dest;
desc->desc[0].drt = JZ_DMA_DRT_AUTO;
desc->desc[0].dcm = JZ_DMA_DCM_TIE | JZ_DMA_DCM_SAI | JZ_DMA_DCM_DAI |
tsz << JZ_DMA_DCM_TSZ_SHIFT |
JZ_DMA_WIDTH_32_BIT << JZ_DMA_DCM_SP_SHIFT |
JZ_DMA_WIDTH_32_BIT << JZ_DMA_DCM_DP_SHIFT;
desc->desc[0].dtc = len >> ord;
return vchan_tx_prep(&jzchan->vchan, &desc->vdesc, flags);
}
static void jz4780_dma_begin(struct jz4780_dma_chan *jzchan)
{
struct jz4780_dma_dev *jzdma = jz4780_dma_chan_parent(jzchan);
struct virt_dma_desc *vdesc;
unsigned int i;
dma_addr_t desc_phys;
if (!jzchan->desc) {
vdesc = vchan_next_desc(&jzchan->vchan);
if (!vdesc)
return;
list_del(&vdesc->node);
jzchan->desc = to_jz4780_dma_desc(vdesc);
jzchan->curr_hwdesc = 0;
if (jzchan->desc->type == DMA_CYCLIC && vdesc->tx.callback) {
for (i = 0; i < jzchan->desc->count; i++)
jzchan->desc->desc[i].dcm &= ~JZ_DMA_DCM_LINK;
}
} else {
jzchan->curr_hwdesc =
(jzchan->curr_hwdesc + 1) % jzchan->desc->count;
}
jz4780_dma_writel(jzdma, JZ_DMA_REG_DCS(jzchan->id), JZ_DMA_DCS_DES8);
desc_phys = jzchan->desc->desc_phys +
(jzchan->curr_hwdesc * sizeof(*jzchan->desc->desc));
jz4780_dma_writel(jzdma, JZ_DMA_REG_DDA(jzchan->id), desc_phys);
jz4780_dma_writel(jzdma, JZ_DMA_REG_DDRS, BIT(jzchan->id));
jz4780_dma_writel(jzdma, JZ_DMA_REG_DCS(jzchan->id),
JZ_DMA_DCS_DES8 | JZ_DMA_DCS_CTE);
}
static void jz4780_dma_issue_pending(struct dma_chan *chan)
{
struct jz4780_dma_chan *jzchan = to_jz4780_dma_chan(chan);
unsigned long flags;
spin_lock_irqsave(&jzchan->vchan.lock, flags);
if (vchan_issue_pending(&jzchan->vchan) && !jzchan->desc)
jz4780_dma_begin(jzchan);
spin_unlock_irqrestore(&jzchan->vchan.lock, flags);
}
static int jz4780_dma_terminate_all(struct jz4780_dma_chan *jzchan)
{
struct jz4780_dma_dev *jzdma = jz4780_dma_chan_parent(jzchan);
unsigned long flags;
LIST_HEAD(head);
spin_lock_irqsave(&jzchan->vchan.lock, flags);
jz4780_dma_writel(jzdma, JZ_DMA_REG_DCS(jzchan->id), 0);
if (jzchan->desc) {
jz4780_dma_desc_free(&jzchan->desc->vdesc);
jzchan->desc = NULL;
}
vchan_get_all_descriptors(&jzchan->vchan, &head);
spin_unlock_irqrestore(&jzchan->vchan.lock, flags);
vchan_dma_desc_free_list(&jzchan->vchan, &head);
return 0;
}
static int jz4780_dma_slave_config(struct jz4780_dma_chan *jzchan,
const struct dma_slave_config *config)
{
if ((config->src_addr_width == DMA_SLAVE_BUSWIDTH_8_BYTES)
|| (config->dst_addr_width == DMA_SLAVE_BUSWIDTH_8_BYTES))
return -EINVAL;
memcpy(&jzchan->config, config, sizeof(jzchan->config));
return 0;
}
static size_t jz4780_dma_desc_residue(struct jz4780_dma_chan *jzchan,
struct jz4780_dma_desc *desc, unsigned int next_sg)
{
struct jz4780_dma_dev *jzdma = jz4780_dma_chan_parent(jzchan);
unsigned int residue, count;
unsigned int i;
residue = 0;
for (i = next_sg; i < desc->count; i++)
residue += desc->desc[i].dtc << jzchan->transfer_shift;
if (next_sg != 0) {
count = jz4780_dma_readl(jzdma,
JZ_DMA_REG_DTC(jzchan->id));
residue += count << jzchan->transfer_shift;
}
return residue;
}
static enum dma_status jz4780_dma_tx_status(struct dma_chan *chan,
dma_cookie_t cookie, struct dma_tx_state *txstate)
{
struct jz4780_dma_chan *jzchan = to_jz4780_dma_chan(chan);
struct virt_dma_desc *vdesc;
enum dma_status status;
unsigned long flags;
status = dma_cookie_status(chan, cookie, txstate);
if ((status == DMA_COMPLETE) || (txstate == NULL))
return status;
spin_lock_irqsave(&jzchan->vchan.lock, flags);
vdesc = vchan_find_desc(&jzchan->vchan, cookie);
if (vdesc) {
txstate->residue = jz4780_dma_desc_residue(jzchan,
to_jz4780_dma_desc(vdesc), 0);
} else if (cookie == jzchan->desc->vdesc.tx.cookie) {
txstate->residue = jz4780_dma_desc_residue(jzchan, jzchan->desc,
(jzchan->curr_hwdesc + 1) % jzchan->desc->count);
} else
txstate->residue = 0;
if (vdesc && jzchan->desc && vdesc == &jzchan->desc->vdesc
&& jzchan->desc->status & (JZ_DMA_DCS_AR | JZ_DMA_DCS_HLT))
status = DMA_ERROR;
spin_unlock_irqrestore(&jzchan->vchan.lock, flags);
return status;
}
static void jz4780_dma_chan_irq(struct jz4780_dma_dev *jzdma,
struct jz4780_dma_chan *jzchan)
{
uint32_t dcs;
spin_lock(&jzchan->vchan.lock);
dcs = jz4780_dma_readl(jzdma, JZ_DMA_REG_DCS(jzchan->id));
jz4780_dma_writel(jzdma, JZ_DMA_REG_DCS(jzchan->id), 0);
if (dcs & JZ_DMA_DCS_AR) {
dev_warn(&jzchan->vchan.chan.dev->device,
"address error (DCS=0x%x)\n", dcs);
}
if (dcs & JZ_DMA_DCS_HLT) {
dev_warn(&jzchan->vchan.chan.dev->device,
"channel halt (DCS=0x%x)\n", dcs);
}
if (jzchan->desc) {
jzchan->desc->status = dcs;
if ((dcs & (JZ_DMA_DCS_AR | JZ_DMA_DCS_HLT)) == 0) {
if (jzchan->desc->type == DMA_CYCLIC) {
vchan_cyclic_callback(&jzchan->desc->vdesc);
} else {
vchan_cookie_complete(&jzchan->desc->vdesc);
jzchan->desc = NULL;
}
jz4780_dma_begin(jzchan);
}
} else {
dev_err(&jzchan->vchan.chan.dev->device,
"channel IRQ with no active transfer\n");
}
spin_unlock(&jzchan->vchan.lock);
}
static irqreturn_t jz4780_dma_irq_handler(int irq, void *data)
{
struct jz4780_dma_dev *jzdma = data;
uint32_t pending, dmac;
int i;
pending = jz4780_dma_readl(jzdma, JZ_DMA_REG_DIRQP);
for (i = 0; i < JZ_DMA_NR_CHANNELS; i++) {
if (!(pending & (1<<i)))
continue;
jz4780_dma_chan_irq(jzdma, &jzdma->chan[i]);
}
dmac = jz4780_dma_readl(jzdma, JZ_DMA_REG_DMAC);
dmac &= ~(JZ_DMA_DMAC_HLT | JZ_DMA_DMAC_AR);
jz4780_dma_writel(jzdma, JZ_DMA_REG_DMAC, dmac);
jz4780_dma_writel(jzdma, JZ_DMA_REG_DIRQP, 0);
return IRQ_HANDLED;
}
static int jz4780_dma_alloc_chan_resources(struct dma_chan *chan)
{
struct jz4780_dma_chan *jzchan = to_jz4780_dma_chan(chan);
jzchan->desc_pool = dma_pool_create(dev_name(&chan->dev->device),
chan->device->dev,
JZ_DMA_DESC_BLOCK_SIZE,
PAGE_SIZE, 0);
if (!jzchan->desc_pool) {
dev_err(&chan->dev->device,
"failed to allocate descriptor pool\n");
return -ENOMEM;
}
return 0;
}
static void jz4780_dma_free_chan_resources(struct dma_chan *chan)
{
struct jz4780_dma_chan *jzchan = to_jz4780_dma_chan(chan);
vchan_free_chan_resources(&jzchan->vchan);
dma_pool_destroy(jzchan->desc_pool);
jzchan->desc_pool = NULL;
}
static bool jz4780_dma_filter_fn(struct dma_chan *chan, void *param)
{
struct jz4780_dma_chan *jzchan = to_jz4780_dma_chan(chan);
struct jz4780_dma_dev *jzdma = jz4780_dma_chan_parent(jzchan);
struct jz4780_dma_data *data = param;
if (data->channel > -1) {
if (data->channel != jzchan->id)
return false;
} else if (jzdma->chan_reserved & BIT(jzchan->id)) {
return false;
}
jzchan->transfer_type = data->transfer_type;
return true;
}
static struct dma_chan *jz4780_of_dma_xlate(struct of_phandle_args *dma_spec,
struct of_dma *ofdma)
{
struct jz4780_dma_dev *jzdma = ofdma->of_dma_data;
dma_cap_mask_t mask = jzdma->dma_device.cap_mask;
struct jz4780_dma_data data;
if (dma_spec->args_count != 2)
return NULL;
data.transfer_type = dma_spec->args[0];
data.channel = dma_spec->args[1];
if (data.channel > -1) {
if (data.channel >= JZ_DMA_NR_CHANNELS) {
dev_err(jzdma->dma_device.dev,
"device requested non-existent channel %u\n",
data.channel);
return NULL;
}
if (!(jzdma->chan_reserved & BIT(data.channel))) {
dev_err(jzdma->dma_device.dev,
"device requested unreserved channel %u\n",
data.channel);
return NULL;
}
}
return dma_request_channel(mask, jz4780_dma_filter_fn, &data);
}
static int jz4780_dma_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct jz4780_dma_dev *jzdma;
struct jz4780_dma_chan *jzchan;
struct dma_device *dd;
struct resource *res;
int i, ret;
jzdma = devm_kzalloc(dev, sizeof(*jzdma), GFP_KERNEL);
if (!jzdma)
return -ENOMEM;
platform_set_drvdata(pdev, jzdma);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "failed to get I/O memory\n");
return -EINVAL;
}
jzdma->base = devm_ioremap_resource(dev, res);
if (IS_ERR(jzdma->base))
return PTR_ERR(jzdma->base);
jzdma->irq = platform_get_irq(pdev, 0);
if (jzdma->irq < 0) {
dev_err(dev, "failed to get IRQ: %d\n", ret);
return jzdma->irq;
}
ret = devm_request_irq(dev, jzdma->irq, jz4780_dma_irq_handler, 0,
dev_name(dev), jzdma);
if (ret) {
dev_err(dev, "failed to request IRQ %u!\n", jzdma->irq);
return -EINVAL;
}
jzdma->clk = devm_clk_get(dev, NULL);
if (IS_ERR(jzdma->clk)) {
dev_err(dev, "failed to get clock\n");
return PTR_ERR(jzdma->clk);
}
clk_prepare_enable(jzdma->clk);
of_property_read_u32_index(dev->of_node, "ingenic,reserved-channels",
0, &jzdma->chan_reserved);
dd = &jzdma->dma_device;
dma_cap_set(DMA_MEMCPY, dd->cap_mask);
dma_cap_set(DMA_SLAVE, dd->cap_mask);
dma_cap_set(DMA_CYCLIC, dd->cap_mask);
dd->dev = dev;
dd->copy_align = 2;
dd->device_alloc_chan_resources = jz4780_dma_alloc_chan_resources;
dd->device_free_chan_resources = jz4780_dma_free_chan_resources;
dd->device_prep_slave_sg = jz4780_dma_prep_slave_sg;
dd->device_prep_dma_cyclic = jz4780_dma_prep_dma_cyclic;
dd->device_prep_dma_memcpy = jz4780_dma_prep_dma_memcpy;
dd->device_config = jz4780_dma_slave_config;
dd->device_terminate_all = jz4780_dma_terminate_all;
dd->device_tx_status = jz4780_dma_tx_status;
dd->device_issue_pending = jz4780_dma_issue_pending;
dd->src_addr_widths = JZ_DMA_BUSWIDTHS;
dd->dst_addr_widths = JZ_DMA_BUSWIDTHS;
dd->directions = BIT(DMA_DEV_TO_MEM) | BIT(DMA_MEM_TO_DEV);
dd->residue_granularity = DMA_RESIDUE_GRANULARITY_BURST;
jz4780_dma_writel(jzdma, JZ_DMA_REG_DMAC,
JZ_DMA_DMAC_DMAE | JZ_DMA_DMAC_FMSC);
jz4780_dma_writel(jzdma, JZ_DMA_REG_DMACP, 0);
INIT_LIST_HEAD(&dd->channels);
for (i = 0; i < JZ_DMA_NR_CHANNELS; i++) {
jzchan = &jzdma->chan[i];
jzchan->id = i;
vchan_init(&jzchan->vchan, dd);
jzchan->vchan.desc_free = jz4780_dma_desc_free;
}
ret = dma_async_device_register(dd);
if (ret) {
dev_err(dev, "failed to register device\n");
goto err_disable_clk;
}
ret = of_dma_controller_register(dev->of_node, jz4780_of_dma_xlate,
jzdma);
if (ret) {
dev_err(dev, "failed to register OF DMA controller\n");
goto err_unregister_dev;
}
dev_info(dev, "JZ4780 DMA controller initialised\n");
return 0;
err_unregister_dev:
dma_async_device_unregister(dd);
err_disable_clk:
clk_disable_unprepare(jzdma->clk);
return ret;
}
static int jz4780_dma_remove(struct platform_device *pdev)
{
struct jz4780_dma_dev *jzdma = platform_get_drvdata(pdev);
of_dma_controller_free(pdev->dev.of_node);
devm_free_irq(&pdev->dev, jzdma->irq, jzdma);
dma_async_device_unregister(&jzdma->dma_device);
return 0;
}
static int __init jz4780_dma_init(void)
{
return platform_driver_register(&jz4780_dma_driver);
}
static void __exit jz4780_dma_exit(void)
{
platform_driver_unregister(&jz4780_dma_driver);
}
