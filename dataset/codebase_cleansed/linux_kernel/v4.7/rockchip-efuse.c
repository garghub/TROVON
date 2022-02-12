static int rockchip_efuse_read(void *context, unsigned int offset,
void *val, size_t bytes)
{
struct rockchip_efuse_chip *efuse = context;
u8 *buf = val;
int ret;
ret = clk_prepare_enable(efuse->clk);
if (ret < 0) {
dev_err(efuse->dev, "failed to prepare/enable efuse clk\n");
return ret;
}
writel(EFUSE_LOAD | EFUSE_PGENB, efuse->base + REG_EFUSE_CTRL);
udelay(1);
while (bytes--) {
writel(readl(efuse->base + REG_EFUSE_CTRL) &
(~(EFUSE_A_MASK << EFUSE_A_SHIFT)),
efuse->base + REG_EFUSE_CTRL);
writel(readl(efuse->base + REG_EFUSE_CTRL) |
((offset++ & EFUSE_A_MASK) << EFUSE_A_SHIFT),
efuse->base + REG_EFUSE_CTRL);
udelay(1);
writel(readl(efuse->base + REG_EFUSE_CTRL) |
EFUSE_STROBE, efuse->base + REG_EFUSE_CTRL);
udelay(1);
*buf++ = readb(efuse->base + REG_EFUSE_DOUT);
writel(readl(efuse->base + REG_EFUSE_CTRL) &
(~EFUSE_STROBE), efuse->base + REG_EFUSE_CTRL);
udelay(1);
}
writel(EFUSE_PGENB | EFUSE_CSB, efuse->base + REG_EFUSE_CTRL);
clk_disable_unprepare(efuse->clk);
return 0;
}
static int rockchip_efuse_probe(struct platform_device *pdev)
{
struct resource *res;
struct nvmem_device *nvmem;
struct rockchip_efuse_chip *efuse;
efuse = devm_kzalloc(&pdev->dev, sizeof(struct rockchip_efuse_chip),
GFP_KERNEL);
if (!efuse)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
efuse->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(efuse->base))
return PTR_ERR(efuse->base);
efuse->clk = devm_clk_get(&pdev->dev, "pclk_efuse");
if (IS_ERR(efuse->clk))
return PTR_ERR(efuse->clk);
efuse->dev = &pdev->dev;
econfig.size = resource_size(res);
econfig.reg_read = rockchip_efuse_read;
econfig.priv = efuse;
econfig.dev = efuse->dev;
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
