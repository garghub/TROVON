void socfpga_init_l2_ecc(void)
{
struct device_node *np;
void __iomem *mapped_l2_edac_addr;
np = of_find_compatible_node(NULL, NULL, "altr,socfpga-l2-ecc");
if (!np) {
pr_err("Unable to find socfpga-l2-ecc in dtb\n");
return;
}
mapped_l2_edac_addr = of_iomap(np, 0);
of_node_put(np);
if (!mapped_l2_edac_addr) {
pr_err("Unable to find L2 ECC mapping in dtb\n");
return;
}
writel(0x01, mapped_l2_edac_addr);
iounmap(mapped_l2_edac_addr);
}
