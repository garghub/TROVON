static void audmapp_write(struct audmapp_chan *auchan, u32 data, u32 reg)
{
struct audmapp_device *audev = to_dev(auchan);
struct device *dev = audev->dev;
dev_dbg(dev, "w %p : %08x\n", auchan->base + reg, data);
iowrite32(data, auchan->base + reg);
}
static u32 audmapp_read(struct audmapp_chan *auchan, u32 reg)
{
return ioread32(auchan->base + reg);
}
static void audmapp_halt(struct shdma_chan *schan)
{
struct audmapp_chan *auchan = to_chan(schan);
int i;
audmapp_write(auchan, 0, PDMACHCR);
for (i = 0; i < 1024; i++) {
if (0 == audmapp_read(auchan, PDMACHCR))
return;
udelay(1);
}
}
static void audmapp_start_xfer(struct shdma_chan *schan,
struct shdma_desc *sdecs)
{
struct audmapp_chan *auchan = to_chan(schan);
struct audmapp_device *audev = to_dev(auchan);
struct audmapp_slave_config *cfg = auchan->config;
struct device *dev = audev->dev;
u32 chcr = cfg->chcr | PDMACHCR_DE;
dev_dbg(dev, "src/dst/chcr = %pad/%pad/%x\n",
&cfg->src, &cfg->dst, cfg->chcr);
audmapp_write(auchan, cfg->src, PDMASAR);
audmapp_write(auchan, cfg->dst, PDMADAR);
audmapp_write(auchan, chcr, PDMACHCR);
}
static struct audmapp_slave_config *
audmapp_find_slave(struct audmapp_chan *auchan, int slave_id)
{
struct audmapp_device *audev = to_dev(auchan);
struct audmapp_pdata *pdata = audev->pdata;
struct audmapp_slave_config *cfg;
int i;
if (slave_id >= AUDMAPP_SLAVE_NUMBER)
return NULL;
for (i = 0, cfg = pdata->slave; i < pdata->slave_num; i++, cfg++)
if (cfg->slave_id == slave_id)
return cfg;
return NULL;
}
static int audmapp_set_slave(struct shdma_chan *schan, int slave_id,
dma_addr_t slave_addr, bool try)
{
struct audmapp_chan *auchan = to_chan(schan);
struct audmapp_slave_config *cfg =
audmapp_find_slave(auchan, slave_id);
if (!cfg)
return -ENODEV;
if (try)
return 0;
auchan->config = cfg;
return 0;
}
static int audmapp_desc_setup(struct shdma_chan *schan,
struct shdma_desc *sdecs,
dma_addr_t src, dma_addr_t dst, size_t *len)
{
struct audmapp_chan *auchan = to_chan(schan);
struct audmapp_slave_config *cfg = auchan->config;
if (!cfg)
return -ENODEV;
if (*len > (size_t)AUDMAPP_LEN_MAX)
*len = (size_t)AUDMAPP_LEN_MAX;
return 0;
}
static void audmapp_setup_xfer(struct shdma_chan *schan,
int slave_id)
{
}
static dma_addr_t audmapp_slave_addr(struct shdma_chan *schan)
{
return 0;
}
static bool audmapp_channel_busy(struct shdma_chan *schan)
{
struct audmapp_chan *auchan = to_chan(schan);
u32 chcr = audmapp_read(auchan, PDMACHCR);
return chcr & ~PDMACHCR_DE;
}
static bool audmapp_desc_completed(struct shdma_chan *schan,
struct shdma_desc *sdesc)
{
return true;
}
static struct shdma_desc *audmapp_embedded_desc(void *buf, int i)
{
return &((struct shdma_desc *)buf)[i];
}
static int audmapp_chan_probe(struct platform_device *pdev,
struct audmapp_device *audev, int id)
{
struct shdma_dev *sdev = &audev->shdma_dev;
struct audmapp_chan *auchan;
struct shdma_chan *schan;
struct device *dev = audev->dev;
auchan = devm_kzalloc(dev, sizeof(*auchan), GFP_KERNEL);
if (!auchan)
return -ENOMEM;
schan = &auchan->shdma_chan;
schan->max_xfer_len = AUDMAPP_LEN_MAX;
shdma_chan_probe(sdev, schan, id);
auchan->base = audev->chan_reg + 0x20 + (0x10 * id);
dev_dbg(dev, "%02d : %p / %p", id, auchan->base, audev->chan_reg);
return 0;
}
static void audmapp_chan_remove(struct audmapp_device *audev)
{
struct dma_device *dma_dev = &audev->shdma_dev.dma_dev;
struct shdma_chan *schan;
int i;
shdma_for_each_chan(schan, &audev->shdma_dev, i) {
BUG_ON(!schan);
shdma_chan_remove(schan);
}
dma_dev->chancnt = 0;
}
static int audmapp_probe(struct platform_device *pdev)
{
struct audmapp_pdata *pdata = pdev->dev.platform_data;
struct audmapp_device *audev;
struct shdma_dev *sdev;
struct dma_device *dma_dev;
struct resource *res;
int err, i;
if (!pdata)
return -ENODEV;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
audev = devm_kzalloc(&pdev->dev, sizeof(*audev), GFP_KERNEL);
if (!audev)
return -ENOMEM;
audev->dev = &pdev->dev;
audev->pdata = pdata;
audev->chan_reg = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(audev->chan_reg))
return PTR_ERR(audev->chan_reg);
sdev = &audev->shdma_dev;
sdev->ops = &audmapp_shdma_ops;
sdev->desc_size = sizeof(struct shdma_desc);
dma_dev = &sdev->dma_dev;
dma_dev->copy_align = LOG2_DEFAULT_XFER_SIZE;
dma_cap_set(DMA_SLAVE, dma_dev->cap_mask);
err = shdma_init(&pdev->dev, sdev, AUDMAPP_MAX_CHANNELS);
if (err < 0)
return err;
platform_set_drvdata(pdev, audev);
for (i = 0; i < AUDMAPP_MAX_CHANNELS; i++) {
err = audmapp_chan_probe(pdev, audev, i);
if (err)
goto chan_probe_err;
}
err = dma_async_device_register(dma_dev);
if (err < 0)
goto chan_probe_err;
return err;
chan_probe_err:
audmapp_chan_remove(audev);
shdma_cleanup(sdev);
return err;
}
static int audmapp_remove(struct platform_device *pdev)
{
struct audmapp_device *audev = platform_get_drvdata(pdev);
struct dma_device *dma_dev = &audev->shdma_dev.dma_dev;
dma_async_device_unregister(dma_dev);
audmapp_chan_remove(audev);
shdma_cleanup(&audev->shdma_dev);
return 0;
}
