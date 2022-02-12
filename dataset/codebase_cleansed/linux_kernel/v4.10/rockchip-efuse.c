static int rockchip_rk3288_efuse_read(void *context, unsigned int offset,
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
writel(RK3288_LOAD | RK3288_PGENB, efuse->base + REG_EFUSE_CTRL);
udelay(1);
while (bytes--) {
writel(readl(efuse->base + REG_EFUSE_CTRL) &
(~(RK3288_A_MASK << RK3288_A_SHIFT)),
efuse->base + REG_EFUSE_CTRL);
writel(readl(efuse->base + REG_EFUSE_CTRL) |
((offset++ & RK3288_A_MASK) << RK3288_A_SHIFT),
efuse->base + REG_EFUSE_CTRL);
udelay(1);
writel(readl(efuse->base + REG_EFUSE_CTRL) |
RK3288_STROBE, efuse->base + REG_EFUSE_CTRL);
udelay(1);
*buf++ = readb(efuse->base + REG_EFUSE_DOUT);
writel(readl(efuse->base + REG_EFUSE_CTRL) &
(~RK3288_STROBE), efuse->base + REG_EFUSE_CTRL);
udelay(1);
}
writel(RK3288_PGENB | RK3288_CSB, efuse->base + REG_EFUSE_CTRL);
clk_disable_unprepare(efuse->clk);
return 0;
}
static int rockchip_rk3399_efuse_read(void *context, unsigned int offset,
void *val, size_t bytes)
{
struct rockchip_efuse_chip *efuse = context;
unsigned int addr_start, addr_end, addr_offset, addr_len;
u32 out_value;
u8 *buf;
int ret, i = 0;
ret = clk_prepare_enable(efuse->clk);
if (ret < 0) {
dev_err(efuse->dev, "failed to prepare/enable efuse clk\n");
return ret;
}
addr_start = rounddown(offset, RK3399_NBYTES) / RK3399_NBYTES;
addr_end = roundup(offset + bytes, RK3399_NBYTES) / RK3399_NBYTES;
addr_offset = offset % RK3399_NBYTES;
addr_len = addr_end - addr_start;
buf = kzalloc(sizeof(*buf) * addr_len * RK3399_NBYTES, GFP_KERNEL);
if (!buf) {
clk_disable_unprepare(efuse->clk);
return -ENOMEM;
}
writel(RK3399_LOAD | RK3399_PGENB | RK3399_STROBSFTSEL | RK3399_RSB,
efuse->base + REG_EFUSE_CTRL);
udelay(1);
while (addr_len--) {
writel(readl(efuse->base + REG_EFUSE_CTRL) | RK3399_STROBE |
((addr_start++ & RK3399_A_MASK) << RK3399_A_SHIFT),
efuse->base + REG_EFUSE_CTRL);
udelay(1);
out_value = readl(efuse->base + REG_EFUSE_DOUT);
writel(readl(efuse->base + REG_EFUSE_CTRL) & (~RK3399_STROBE),
efuse->base + REG_EFUSE_CTRL);
udelay(1);
memcpy(&buf[i], &out_value, RK3399_NBYTES);
i += RK3399_NBYTES;
}
writel(RK3399_PD | RK3399_CSB, efuse->base + REG_EFUSE_CTRL);
memcpy(val, buf + addr_offset, bytes);
kfree(buf);
clk_disable_unprepare(efuse->clk);
return 0;
}
static int rockchip_efuse_probe(struct platform_device *pdev)
{
struct resource *res;
struct nvmem_device *nvmem;
struct rockchip_efuse_chip *efuse;
const struct of_device_id *match;
struct device *dev = &pdev->dev;
match = of_match_device(dev->driver->of_match_table, dev);
if (!match || !match->data) {
dev_err(dev, "failed to get match data\n");
return -EINVAL;
}
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
econfig.reg_read = match->data;
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
