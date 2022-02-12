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
void socfpga_init_arria10_l2_ecc(void)
{
struct device_node *np;
void __iomem *mapped_l2_edac_addr;
np = of_find_compatible_node(NULL, NULL, "altr,socfpga-a10-l2-ecc");
if (!np) {
pr_err("Unable to find socfpga-a10-l2-ecc in dtb\n");
return;
}
mapped_l2_edac_addr = of_iomap(np, 0);
of_node_put(np);
if (!mapped_l2_edac_addr) {
pr_err("Unable to find L2 ECC mapping in dtb\n");
return;
}
if (!sys_manager_base_addr) {
pr_err("System Mananger not mapped for L2 ECC\n");
goto exit;
}
writel(A10_SYSMGR_MPU_CLEAR_L2_ECC, (sys_manager_base_addr +
A10_SYSMGR_MPU_CLEAR_L2_ECC_OFST));
writel(A10_SYSMGR_ECC_INTMASK_CLR_L2, sys_manager_base_addr +
A10_SYSMGR_ECC_INTMASK_CLR_OFST);
writel(A10_MPU_CTRL_L2_ECC_EN, mapped_l2_edac_addr +
A10_MPU_CTRL_L2_ECC_OFST);
exit:
iounmap(mapped_l2_edac_addr);
}
