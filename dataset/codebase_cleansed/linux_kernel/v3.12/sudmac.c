static void sudmac_writel(struct sudmac_chan *sc, u32 data, u32 reg)
{
iowrite32(data, sc->base + reg);
}
static u32 sudmac_readl(struct sudmac_chan *sc, u32 reg)
{
return ioread32(sc->base + reg);
}
static bool sudmac_is_busy(struct sudmac_chan *sc)
{
u32 den = sudmac_readl(sc, SUDMAC_CH0DEN + sc->offset);
if (den)
return true;
return false;
}
static void sudmac_set_reg(struct sudmac_chan *sc, struct sudmac_regs *hw,
struct shdma_desc *sdesc)
{
sudmac_writel(sc, sc->cfg, SUDMAC_CH0CFG + sc->offset);
sudmac_writel(sc, hw->base_addr, SUDMAC_CH0BA + sc->offset);
sudmac_writel(sc, hw->base_byte_count, SUDMAC_CH0BBC + sc->offset);
}
static void sudmac_start(struct sudmac_chan *sc)
{
u32 dintctrl = sudmac_readl(sc, SUDMAC_DINTCTRL);
sudmac_writel(sc, dintctrl | sc->dint_end_bit, SUDMAC_DINTCTRL);
sudmac_writel(sc, 1, SUDMAC_CH0DEN + sc->offset);
}
static void sudmac_start_xfer(struct shdma_chan *schan,
struct shdma_desc *sdesc)
{
struct sudmac_chan *sc = to_chan(schan);
struct sudmac_desc *sd = to_desc(sdesc);
sudmac_set_reg(sc, &sd->hw, sdesc);
sudmac_start(sc);
}
static bool sudmac_channel_busy(struct shdma_chan *schan)
{
struct sudmac_chan *sc = to_chan(schan);
return sudmac_is_busy(sc);
}
static void sudmac_setup_xfer(struct shdma_chan *schan, int slave_id)
{
}
static const struct sudmac_slave_config *sudmac_find_slave(
struct sudmac_chan *sc, int slave_id)
{
struct sudmac_device *sdev = to_sdev(sc);
struct sudmac_pdata *pdata = sdev->pdata;
const struct sudmac_slave_config *cfg;
int i;
for (i = 0, cfg = pdata->slave; i < pdata->slave_num; i++, cfg++)
if (cfg->slave_id == slave_id)
return cfg;
return NULL;
}
static int sudmac_set_slave(struct shdma_chan *schan, int slave_id,
dma_addr_t slave_addr, bool try)
{
struct sudmac_chan *sc = to_chan(schan);
const struct sudmac_slave_config *cfg = sudmac_find_slave(sc, slave_id);
if (!cfg)
return -ENODEV;
return 0;
}
static inline void sudmac_dma_halt(struct sudmac_chan *sc)
{
u32 dintctrl = sudmac_readl(sc, SUDMAC_DINTCTRL);
sudmac_writel(sc, 0, SUDMAC_CH0DEN + sc->offset);
sudmac_writel(sc, dintctrl & ~sc->dint_end_bit, SUDMAC_DINTCTRL);
sudmac_writel(sc, sc->dint_end_bit, SUDMAC_DINTSTSCLR);
}
static int sudmac_desc_setup(struct shdma_chan *schan,
struct shdma_desc *sdesc,
dma_addr_t src, dma_addr_t dst, size_t *len)
{
struct sudmac_chan *sc = to_chan(schan);
struct sudmac_desc *sd = to_desc(sdesc);
dev_dbg(sc->shdma_chan.dev, "%s: src=%x, dst=%x, len=%d\n",
__func__, src, dst, *len);
if (*len > schan->max_xfer_len)
*len = schan->max_xfer_len;
if (dst)
sd->hw.base_addr = dst;
else if (src)
sd->hw.base_addr = src;
sd->hw.base_byte_count = *len;
return 0;
}
static void sudmac_halt(struct shdma_chan *schan)
{
struct sudmac_chan *sc = to_chan(schan);
sudmac_dma_halt(sc);
}
static bool sudmac_chan_irq(struct shdma_chan *schan, int irq)
{
struct sudmac_chan *sc = to_chan(schan);
u32 dintsts = sudmac_readl(sc, SUDMAC_DINTSTS);
if (!(dintsts & sc->dint_end_bit))
return false;
sudmac_dma_halt(sc);
return true;
}
static size_t sudmac_get_partial(struct shdma_chan *schan,
struct shdma_desc *sdesc)
{
struct sudmac_chan *sc = to_chan(schan);
struct sudmac_desc *sd = to_desc(sdesc);
u32 current_byte_count = sudmac_readl(sc, SUDMAC_CH0CBC + sc->offset);
return sd->hw.base_byte_count - current_byte_count;
}
static bool sudmac_desc_completed(struct shdma_chan *schan,
struct shdma_desc *sdesc)
{
struct sudmac_chan *sc = to_chan(schan);
struct sudmac_desc *sd = to_desc(sdesc);
u32 current_addr = sudmac_readl(sc, SUDMAC_CH0CA + sc->offset);
return sd->hw.base_addr + sd->hw.base_byte_count == current_addr;
}
static int sudmac_chan_probe(struct sudmac_device *su_dev, int id, int irq,
unsigned long flags)
{
struct shdma_dev *sdev = &su_dev->shdma_dev;
struct platform_device *pdev = to_platform_device(sdev->dma_dev.dev);
struct sudmac_chan *sc;
struct shdma_chan *schan;
int err;
sc = devm_kzalloc(&pdev->dev, sizeof(struct sudmac_chan), GFP_KERNEL);
if (!sc) {
dev_err(sdev->dma_dev.dev,
"No free memory for allocating dma channels!\n");
return -ENOMEM;
}
schan = &sc->shdma_chan;
schan->max_xfer_len = 64 * 1024 * 1024 - 1;
shdma_chan_probe(sdev, schan, id);
sc->base = su_dev->chan_reg;
sc->offset = su_dev->pdata->channel->offset;
if (su_dev->pdata->channel->config & SUDMAC_TX_BUFFER_MODE)
sc->cfg |= SUDMAC_SENDBUFM;
if (su_dev->pdata->channel->config & SUDMAC_RX_END_MODE)
sc->cfg |= SUDMAC_RCVENDM;
sc->cfg |= (su_dev->pdata->channel->wait << 4) & SUDMAC_LBA_WAIT;
if (su_dev->pdata->channel->dint_end_bit & SUDMAC_DMA_BIT_CH0)
sc->dint_end_bit |= SUDMAC_CH0ENDE;
if (su_dev->pdata->channel->dint_end_bit & SUDMAC_DMA_BIT_CH1)
sc->dint_end_bit |= SUDMAC_CH1ENDE;
if (pdev->id >= 0)
snprintf(sc->dev_id, sizeof(sc->dev_id), "sudmac%d.%d",
pdev->id, id);
else
snprintf(sc->dev_id, sizeof(sc->dev_id), "sudmac%d", id);
err = shdma_request_irq(schan, irq, flags, sc->dev_id);
if (err) {
dev_err(sdev->dma_dev.dev,
"DMA channel %d request_irq failed %d\n", id, err);
goto err_no_irq;
}
return 0;
err_no_irq:
shdma_chan_remove(schan);
return err;
}
static void sudmac_chan_remove(struct sudmac_device *su_dev)
{
struct dma_device *dma_dev = &su_dev->shdma_dev.dma_dev;
struct shdma_chan *schan;
int i;
shdma_for_each_chan(schan, &su_dev->shdma_dev, i) {
BUG_ON(!schan);
shdma_chan_remove(schan);
}
dma_dev->chancnt = 0;
}
static dma_addr_t sudmac_slave_addr(struct shdma_chan *schan)
{
return 0;
}
static struct shdma_desc *sudmac_embedded_desc(void *buf, int i)
{
return &((struct sudmac_desc *)buf)[i].shdma_desc;
}
static int sudmac_probe(struct platform_device *pdev)
{
struct sudmac_pdata *pdata = dev_get_platdata(&pdev->dev);
int err, i;
struct sudmac_device *su_dev;
struct dma_device *dma_dev;
struct resource *chan, *irq_res;
if (!pdata)
return -ENODEV;
irq_res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!irq_res)
return -ENODEV;
err = -ENOMEM;
su_dev = devm_kzalloc(&pdev->dev, sizeof(struct sudmac_device),
GFP_KERNEL);
if (!su_dev) {
dev_err(&pdev->dev, "Not enough memory\n");
return err;
}
dma_dev = &su_dev->shdma_dev.dma_dev;
chan = platform_get_resource(pdev, IORESOURCE_MEM, 0);
su_dev->chan_reg = devm_ioremap_resource(&pdev->dev, chan);
if (IS_ERR(su_dev->chan_reg))
return PTR_ERR(su_dev->chan_reg);
dma_cap_set(DMA_SLAVE, dma_dev->cap_mask);
su_dev->shdma_dev.ops = &sudmac_shdma_ops;
su_dev->shdma_dev.desc_size = sizeof(struct sudmac_desc);
err = shdma_init(&pdev->dev, &su_dev->shdma_dev, pdata->channel_num);
if (err < 0)
return err;
su_dev->pdata = dev_get_platdata(&pdev->dev);
platform_set_drvdata(pdev, su_dev);
for (i = 0; i < pdata->channel_num; i++) {
err = sudmac_chan_probe(su_dev, i, irq_res->start, IRQF_SHARED);
if (err)
goto chan_probe_err;
}
err = dma_async_device_register(&su_dev->shdma_dev.dma_dev);
if (err < 0)
goto chan_probe_err;
return err;
chan_probe_err:
sudmac_chan_remove(su_dev);
shdma_cleanup(&su_dev->shdma_dev);
return err;
}
static int sudmac_remove(struct platform_device *pdev)
{
struct sudmac_device *su_dev = platform_get_drvdata(pdev);
struct dma_device *dma_dev = &su_dev->shdma_dev.dma_dev;
dma_async_device_unregister(dma_dev);
sudmac_chan_remove(su_dev);
shdma_cleanup(&su_dev->shdma_dev);
return 0;
}
