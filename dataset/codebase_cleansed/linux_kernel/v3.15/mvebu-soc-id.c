int mvebu_get_soc_id(u32 *dev, u32 *rev)
{
if (is_id_valid) {
*dev = soc_dev_id;
*rev = soc_rev;
return 0;
} else
return -1;
}
static int __init mvebu_soc_id_init(void)
{
struct device_node *np;
int ret = 0;
void __iomem *pci_base;
struct clk *clk;
struct device_node *child;
np = of_find_matching_node(NULL, mvebu_pcie_of_match_table);
if (!np)
return ret;
child = of_get_next_child(np, NULL);
if (child == NULL) {
pr_err("cannot get pci node\n");
ret = -ENOMEM;
goto clk_err;
}
clk = of_clk_get_by_name(child, NULL);
if (IS_ERR(clk)) {
pr_err("cannot get clock\n");
ret = -ENOMEM;
goto clk_err;
}
ret = clk_prepare_enable(clk);
if (ret) {
pr_err("cannot enable clock\n");
goto clk_err;
}
pci_base = of_iomap(child, 0);
if (pci_base == NULL) {
pr_err("cannot map registers\n");
ret = -ENOMEM;
goto res_ioremap;
}
soc_dev_id = readl(pci_base + PCIE_DEV_ID_OFF) >> 16;
soc_rev = readl(pci_base + PCIE_DEV_REV_OFF) & SOC_REV_MASK;
is_id_valid = true;
pr_info("MVEBU SoC ID=0x%X, Rev=0x%X\n", soc_dev_id, soc_rev);
iounmap(pci_base);
res_ioremap:
if (!of_device_is_available(child) || !IS_ENABLED(CONFIG_PCI_MVEBU)) {
clk_disable_unprepare(clk);
clk_put(clk);
}
clk_err:
of_node_put(child);
of_node_put(np);
return ret;
}
