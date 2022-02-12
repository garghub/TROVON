static int rockchip_efuse_write(void *context, const void *data, size_t count)
{
return 0;
}
static int rockchip_efuse_read(void *context,
const void *reg, size_t reg_size,
void *val, size_t val_size)
{
unsigned int offset = *(u32 *)reg;
struct rockchip_efuse_context *_context = context;
void __iomem *base = _context->base;
struct clk *clk = _context->efuse_clk;
u8 *buf = val;
int ret;
ret = clk_prepare_enable(clk);
if (ret < 0) {
dev_err(_context->dev, "failed to prepare/enable efuse clk\n");
return ret;
}
writel(EFUSE_LOAD | EFUSE_PGENB, base + REG_EFUSE_CTRL);
udelay(1);
while (val_size) {
writel(readl(base + REG_EFUSE_CTRL) &
(~(EFUSE_A_MASK << EFUSE_A_SHIFT)),
base + REG_EFUSE_CTRL);
writel(readl(base + REG_EFUSE_CTRL) |
((offset & EFUSE_A_MASK) << EFUSE_A_SHIFT),
base + REG_EFUSE_CTRL);
udelay(1);
writel(readl(base + REG_EFUSE_CTRL) |
EFUSE_STROBE, base + REG_EFUSE_CTRL);
udelay(1);
*buf++ = readb(base + REG_EFUSE_DOUT);
writel(readl(base + REG_EFUSE_CTRL) &
(~EFUSE_STROBE), base + REG_EFUSE_CTRL);
udelay(1);
val_size -= 1;
offset += 1;
}
writel(EFUSE_PGENB | EFUSE_CSB, base + REG_EFUSE_CTRL);
clk_disable_unprepare(clk);
return 0;
}
static int rockchip_efuse_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct nvmem_device *nvmem;
struct regmap *regmap;
void __iomem *base;
struct clk *clk;
struct rockchip_efuse_context *context;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
context = devm_kzalloc(dev, sizeof(struct rockchip_efuse_context),
GFP_KERNEL);
if (IS_ERR(context))
return PTR_ERR(context);
clk = devm_clk_get(dev, "pclk_efuse");
if (IS_ERR(clk))
return PTR_ERR(clk);
context->dev = dev;
context->base = base;
context->efuse_clk = clk;
rockchip_efuse_regmap_config.max_register = resource_size(res) - 1;
regmap = devm_regmap_init(dev, &rockchip_efuse_bus,
context, &rockchip_efuse_regmap_config);
if (IS_ERR(regmap)) {
dev_err(dev, "regmap init failed\n");
return PTR_ERR(regmap);
}
econfig.dev = dev;
nvmem = nvmem_register(&econfig);
if (IS_ERR(nvmem))
return PTR_ERR(nvmem);
platform_set_drvdata(pdev, nvmem);
return 0;
}
static int rockchip_efuse_remove(struct platform_device *pdev)
{
struct nvmem_device *nvmem = platform_get_drvdata(pdev);
return nvmem_unregister(nvmem);
}
