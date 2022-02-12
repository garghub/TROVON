int mvebu_get_soc_id(u32 *dev, u32 *rev)
{
if (is_id_valid) {
*dev = soc_dev_id;
*rev = soc_rev;
return 0;
} else
return -ENODEV;
}
static int __init get_soc_id_by_pci(void)
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
static int __init mvebu_soc_id_init(void)
{
if (!mvebu_system_controller_get_soc_id(&soc_dev_id, &soc_rev)) {
is_id_valid = true;
pr_info("MVEBU SoC ID=0x%X, Rev=0x%X\n", soc_dev_id, soc_rev);
return 0;
}
return get_soc_id_by_pci();
}
static int __init mvebu_soc_device(void)
{
struct soc_device_attribute *soc_dev_attr;
struct soc_device *soc_dev;
if (!is_id_valid)
return 0;
soc_dev_attr = kzalloc(sizeof(*soc_dev_attr), GFP_KERNEL);
if (!soc_dev_attr)
return -ENOMEM;
soc_dev_attr->family = kasprintf(GFP_KERNEL, "Marvell");
soc_dev_attr->revision = kasprintf(GFP_KERNEL, "%X", soc_rev);
soc_dev_attr->soc_id = kasprintf(GFP_KERNEL, "%X", soc_dev_id);
soc_dev = soc_device_register(soc_dev_attr);
if (IS_ERR(soc_dev)) {
kfree(soc_dev_attr->family);
kfree(soc_dev_attr->revision);
kfree(soc_dev_attr->soc_id);
kfree(soc_dev_attr);
}
return 0;
}
