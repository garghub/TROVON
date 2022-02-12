static int imx_sata_init(struct device *dev, void __iomem *addr)
{
u32 tmpdata;
int ret = 0;
struct clk *clk;
sata_clk = clk_get(dev, "ahci");
if (IS_ERR(sata_clk)) {
dev_err(dev, "no sata clock.\n");
return PTR_ERR(sata_clk);
}
ret = clk_enable(sata_clk);
if (ret) {
dev_err(dev, "can't enable sata clock.\n");
goto put_sata_clk;
}
sata_ref_clk = clk_get(dev, "ahci_phy");
if (IS_ERR(sata_ref_clk)) {
dev_err(dev, "no sata ref clock.\n");
ret = PTR_ERR(sata_ref_clk);
goto release_sata_clk;
}
ret = clk_enable(sata_ref_clk);
if (ret) {
dev_err(dev, "can't enable sata ref clock.\n");
goto put_sata_ref_clk;
}
clk = clk_get(dev, "ahci_dma");
if (IS_ERR(clk)) {
dev_err(dev, "no dma clock.\n");
ret = PTR_ERR(clk);
goto release_sata_ref_clk;
}
tmpdata = clk_get_rate(clk) / 1000;
clk_put(clk);
writel(tmpdata, addr + HOST_TIMER1MS);
tmpdata = readl(addr + HOST_CAP);
if (!(tmpdata & HOST_CAP_SSS)) {
tmpdata |= HOST_CAP_SSS;
writel(tmpdata, addr + HOST_CAP);
}
if (!(readl(addr + HOST_PORTS_IMPL) & 0x1))
writel((readl(addr + HOST_PORTS_IMPL) | 0x1),
addr + HOST_PORTS_IMPL);
return 0;
release_sata_ref_clk:
clk_disable(sata_ref_clk);
put_sata_ref_clk:
clk_put(sata_ref_clk);
release_sata_clk:
clk_disable(sata_clk);
put_sata_clk:
clk_put(sata_clk);
return ret;
}
static void imx_sata_exit(struct device *dev)
{
clk_disable(sata_ref_clk);
clk_put(sata_ref_clk);
clk_disable(sata_clk);
clk_put(sata_clk);
}
struct platform_device *__init imx_add_ahci_imx(
const struct imx_ahci_imx_data *data,
const struct ahci_platform_data *pdata)
{
struct resource res[] = {
{
.start = data->iobase,
.end = data->iobase + SZ_4K - 1,
.flags = IORESOURCE_MEM,
}, {
.start = data->irq,
.end = data->irq,
.flags = IORESOURCE_IRQ,
},
};
return imx_add_platform_device_dmamask(data->devid, 0,
res, ARRAY_SIZE(res),
pdata, sizeof(*pdata), DMA_BIT_MASK(32));
}
struct platform_device *__init imx53_add_ahci_imx(void)
{
struct ahci_platform_data pdata = {
.init = imx_sata_init,
.exit = imx_sata_exit,
};
return imx_add_ahci_imx(&imx53_ahci_imx_data, &pdata);
}
