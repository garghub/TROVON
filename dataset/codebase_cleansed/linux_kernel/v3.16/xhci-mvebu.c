static void xhci_mvebu_mbus_config(void __iomem *base,
const struct mbus_dram_target_info *dram)
{
int win;
for (win = 0; win < USB3_MAX_WINDOWS; win++) {
writel(0, base + USB3_WIN_CTRL(win));
writel(0, base + USB3_WIN_BASE(win));
}
for (win = 0; win < dram->num_cs; win++) {
const struct mbus_dram_window *cs = dram->cs + win;
writel(((cs->size - 1) & 0xffff0000) | (cs->mbus_attr << 8) |
(dram->mbus_dram_target_id << 4) | 1,
base + USB3_WIN_CTRL(win));
writel((cs->base & 0xffff0000), base + USB3_WIN_BASE(win));
}
}
int xhci_mvebu_mbus_init_quirk(struct platform_device *pdev)
{
struct resource *res;
void __iomem *base;
const struct mbus_dram_target_info *dram;
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!res)
return -ENODEV;
base = ioremap(res->start, resource_size(res));
if (!base)
return -ENODEV;
dram = mv_mbus_dram_info();
xhci_mvebu_mbus_config(base, dram);
iounmap(base);
return 0;
}
