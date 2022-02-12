static int qfprom_reg_read(void *context,
unsigned int reg, void *_val, size_t bytes)
{
void __iomem *base = context;
u8 *val = _val;
int i = 0, words = bytes;
while (words--)
*val++ = readb(base + reg + i++);
return 0;
}
static int qfprom_reg_write(void *context,
unsigned int reg, void *_val, size_t bytes)
{
void __iomem *base = context;
u8 *val = _val;
int i = 0, words = bytes;
while (words--)
writeb(*val++, base + reg + i++);
return 0;
}
static int qfprom_remove(struct platform_device *pdev)
{
struct nvmem_device *nvmem = platform_get_drvdata(pdev);
return nvmem_unregister(nvmem);
}
static int qfprom_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct nvmem_device *nvmem;
void __iomem *base;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
econfig.size = resource_size(res);
econfig.dev = dev;
econfig.priv = base;
nvmem = nvmem_register(&econfig);
if (IS_ERR(nvmem))
return PTR_ERR(nvmem);
platform_set_drvdata(pdev, nvmem);
return 0;
}
