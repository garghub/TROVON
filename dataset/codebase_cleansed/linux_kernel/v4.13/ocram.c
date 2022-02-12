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
static inline void ecc_set_bits(u32 bit_mask, void __iomem *ioaddr)
{
u32 value = readl(ioaddr);
value |= bit_mask;
writel(value, ioaddr);
}
static inline void ecc_clear_bits(u32 bit_mask, void __iomem *ioaddr)
{
u32 value = readl(ioaddr);
value &= ~bit_mask;
writel(value, ioaddr);
}
static inline int ecc_test_bits(u32 bit_mask, void __iomem *ioaddr)
{
u32 value = readl(ioaddr);
return (value & bit_mask) ? 1 : 0;
}
static int altr_init_memory_port(void __iomem *ioaddr)
{
int limit = ALTR_A10_ECC_INIT_WATCHDOG_10US;
ecc_set_bits(ALTR_A10_ECC_INITA, (ioaddr + ALTR_A10_ECC_CTRL_OFST));
while (limit--) {
if (ecc_test_bits(ALTR_A10_ECC_INITCOMPLETEA,
(ioaddr + ALTR_A10_ECC_INITSTAT_OFST)))
break;
udelay(1);
}
if (limit < 0)
return -EBUSY;
writel(ALTR_A10_ECC_ERRPENA_MASK,
(ioaddr + ALTR_A10_ECC_INTSTAT_OFST));
return 0;
}
void socfpga_init_arria10_ocram_ecc(void)
{
struct device_node *np;
int ret = 0;
void __iomem *ecc_block_base;
if (!sys_manager_base_addr) {
pr_err("SOCFPGA: sys-mgr is not initialized\n");
return;
}
np = of_find_compatible_node(NULL, NULL, "altr,socfpga-a10-ocram-ecc");
if (!np) {
pr_err("Unable to find socfpga-a10-ocram-ecc\n");
return;
}
ecc_block_base = of_iomap(np, 0);
of_node_put(np);
if (!ecc_block_base) {
pr_err("Unable to map OCRAM ECC block\n");
return;
}
writel(ALTR_A10_OCRAM_ECC_EN_CTL,
sys_manager_base_addr + A10_SYSMGR_ECC_INTMASK_SET_OFST);
ecc_clear_bits(ALTR_A10_ECC_SERRINTEN,
(ecc_block_base + ALTR_A10_ECC_ERRINTEN_OFST));
ecc_clear_bits(ALTR_A10_OCRAM_ECC_EN_CTL,
(ecc_block_base + ALTR_A10_ECC_CTRL_OFST));
wmb();
ret = altr_init_memory_port(ecc_block_base);
if (ret) {
pr_err("ECC: cannot init OCRAM PORTA memory\n");
goto exit;
}
ecc_set_bits(ALTR_A10_OCRAM_ECC_EN_CTL,
(ecc_block_base + ALTR_A10_ECC_CTRL_OFST));
ecc_set_bits(ALTR_A10_ECC_SERRINTEN,
(ecc_block_base + ALTR_A10_ECC_ERRINTEN_OFST));
writel(ALTR_A10_OCRAM_ECC_EN_CTL,
sys_manager_base_addr + A10_SYSMGR_ECC_INTMASK_CLR_OFST);
wmb();
exit:
iounmap(ecc_block_base);
}
