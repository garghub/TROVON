static int __init sirfsoc_of_l2x_init(void)
{
struct device_node *np;
void __iomem *sirfsoc_l2x_base;
np = of_find_matching_node(NULL, l2x_ids);
if (!np)
panic("unable to find compatible l2x node in dtb\n");
sirfsoc_l2x_base = of_iomap(np, 0);
if (!sirfsoc_l2x_base)
panic("unable to map l2x cpu registers\n");
of_node_put(np);
if (!(readl_relaxed(sirfsoc_l2x_base + L2X0_CTRL) & 1)) {
writel_relaxed(PLAT_PHYS_OFFSET + 1024 * 1024 * 1024,
sirfsoc_l2x_base + L2X0_ADDR_FILTERING_END);
writel_relaxed(PLAT_PHYS_OFFSET | 0x1,
sirfsoc_l2x_base + L2X0_ADDR_FILTERING_START);
writel_relaxed(0,
sirfsoc_l2x_base + L2X0_TAG_LATENCY_CTRL);
writel_relaxed(0,
sirfsoc_l2x_base + L2X0_DATA_LATENCY_CTRL);
}
l2x0_init((void __iomem *)sirfsoc_l2x_base, 0x00040000,
0x00000000);
return 0;
}
