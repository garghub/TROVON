static const struct softing_platform_data
*softingcs_find_platform_data(unsigned int manf, unsigned int prod)
{
const struct softing_platform_data *lp;
for (lp = softingcs_platform_data; lp->manf; ++lp) {
if ((lp->manf == manf) && (lp->prod == prod))
return lp;
}
return NULL;
}
static int softingcs_reset(struct platform_device *pdev, int v)
{
struct pcmcia_device *pcmcia = to_pcmcia_dev(pdev->dev.parent);
dev_dbg(&pdev->dev, "pcmcia config [2] %02x\n", v ? 0 : 0x20);
return pcmcia_write_config_byte(pcmcia, 2, v ? 0 : 0x20);
}
static int softingcs_enable_irq(struct platform_device *pdev, int v)
{
struct pcmcia_device *pcmcia = to_pcmcia_dev(pdev->dev.parent);
dev_dbg(&pdev->dev, "pcmcia config [0] %02x\n", v ? 0x60 : 0);
return pcmcia_write_config_byte(pcmcia, 0, v ? 0x60 : 0);
}
static int softingcs_probe_config(struct pcmcia_device *pcmcia, void *priv_data)
{
struct softing_platform_data *pdat = priv_data;
struct resource *pres;
int memspeed = 0;
WARN_ON(!pdat);
pres = pcmcia->resource[PCMCIA_IOMEM_0];
if (resource_size(pres) < 0x1000)
return -ERANGE;
pres->flags |= WIN_MEMORY_TYPE_CM | WIN_ENABLE;
if (pdat->generation < 2) {
pres->flags |= WIN_USE_WAIT | WIN_DATA_WIDTH_8;
memspeed = 3;
} else {
pres->flags |= WIN_DATA_WIDTH_16;
}
return pcmcia_request_window(pcmcia, pres, memspeed);
}
static void softingcs_remove(struct pcmcia_device *pcmcia)
{
struct platform_device *pdev = pcmcia->priv;
platform_device_unregister(pdev);
pcmcia_disable_device(pcmcia);
}
static void softingcs_pdev_release(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
kfree(pdev);
}
static int softingcs_probe(struct pcmcia_device *pcmcia)
{
int ret;
struct platform_device *pdev;
const struct softing_platform_data *pdat;
struct resource *pres;
struct dev {
struct platform_device pdev;
struct resource res[2];
} *dev;
pdat = softingcs_find_platform_data(pcmcia->manf_id, pcmcia->card_id);
if (!pdat)
return -ENOTTY;
pcmcia->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_IOMEM |
CONF_AUTO_SET_VPP | CONF_AUTO_CHECK_VCC;
ret = pcmcia_loop_config(pcmcia, softingcs_probe_config, (void *)pdat);
if (ret)
goto pcmcia_failed;
ret = pcmcia_enable_device(pcmcia);
if (ret < 0)
goto pcmcia_failed;
pres = pcmcia->resource[PCMCIA_IOMEM_0];
if (!pres) {
ret = -EBADF;
goto pcmcia_bad;
}
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev) {
ret = -ENOMEM;
goto mem_failed;
}
dev->pdev.resource = dev->res;
dev->pdev.num_resources = ARRAY_SIZE(dev->res);
dev->pdev.dev.release = softingcs_pdev_release;
pdev = &dev->pdev;
pdev->dev.platform_data = (void *)pdat;
pdev->dev.parent = &pcmcia->dev;
pcmcia->priv = pdev;
pdev->resource[0].flags = IORESOURCE_MEM;
pdev->resource[0].start = pres->start;
pdev->resource[0].end = pres->end;
pdev->resource[1].flags = IORESOURCE_IRQ;
pdev->resource[1].start = pcmcia->irq;
pdev->resource[1].end = pdev->resource[1].start;
spin_lock(&softingcs_index_lock);
pdev->id = softingcs_index++;
spin_unlock(&softingcs_index_lock);
pdev->name = "softing";
dev_set_name(&pdev->dev, "softingcs.%i", pdev->id);
ret = platform_device_register(pdev);
if (ret < 0)
goto platform_failed;
dev_info(&pcmcia->dev, "created %s\n", dev_name(&pdev->dev));
return 0;
platform_failed:
kfree(dev);
mem_failed:
pcmcia_bad:
pcmcia_failed:
pcmcia_disable_device(pcmcia);
pcmcia->priv = NULL;
return ret ?: -ENODEV;
}
