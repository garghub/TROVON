void socfpga_init_ocram_ecc(void)
{
struct device_node *np;
void __iomem *mapped_ocr_edac_addr;
np = of_find_compatible_node(NULL, NULL, "altr,socfpga-ocram-ecc");
if (!np) {
pr_err("Unable to find socfpga-ocram-ecc\n");
return;
}
mapped_ocr_edac_addr = of_iomap(np, 0);
of_node_put(np);
if (!mapped_ocr_edac_addr) {
pr_err("Unable to map OCRAM ecc regs.\n");
return;
}
writel(ALTR_OCRAM_CLEAR_ECC, mapped_ocr_edac_addr);
writel(ALTR_OCRAM_ECC_EN, mapped_ocr_edac_addr);
iounmap(mapped_ocr_edac_addr);
}
