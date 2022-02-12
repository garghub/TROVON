static int imx_iim_read(void *context, unsigned int offset,
void *buf, size_t bytes)
{
struct iim_priv *iim = context;
int i, ret;
u8 *buf8 = buf;
ret = clk_prepare_enable(iim->clk);
if (ret)
return ret;
for (i = offset; i < offset + bytes; i++) {
int bank = i >> 5;
int reg = i & 0x1f;
*buf8++ = readl(iim->base + IIM_BANK_BASE(bank) + reg * 4);
}
clk_disable_unprepare(iim->clk);
return 0;
}
static int imx_iim_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id;
struct device *dev = &pdev->dev;
struct resource *res;
struct iim_priv *iim;
struct nvmem_device *nvmem;
struct nvmem_config *cfg;
const struct imx_iim_drvdata *drvdata = NULL;
iim = devm_kzalloc(dev, sizeof(*iim), GFP_KERNEL);
if (!iim)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
iim->base = devm_ioremap_resource(dev, res);
if (IS_ERR(iim->base))
return PTR_ERR(iim->base);
of_id = of_match_device(imx_iim_dt_ids, dev);
if (!of_id)
return -ENODEV;
drvdata = of_id->data;
iim->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(iim->clk))
return PTR_ERR(iim->clk);
cfg = &iim->nvmem;
cfg->name = "imx-iim",
cfg->read_only = true,
cfg->word_size = 1,
cfg->stride = 1,
cfg->owner = THIS_MODULE,
cfg->reg_read = imx_iim_read,
cfg->dev = dev;
cfg->size = drvdata->nregs;
cfg->priv = iim;
nvmem = nvmem_register(cfg);
if (IS_ERR(nvmem))
return PTR_ERR(nvmem);
platform_set_drvdata(pdev, nvmem);
return 0;
}
static int imx_iim_remove(struct platform_device *pdev)
{
struct nvmem_device *nvmem = platform_get_drvdata(pdev);
return nvmem_unregister(nvmem);
}
