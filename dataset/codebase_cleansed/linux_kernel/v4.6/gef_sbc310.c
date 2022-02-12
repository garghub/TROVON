static void __init gef_sbc310_init_irq(void)
{
struct device_node *cascade_node = NULL;
mpc86xx_init_irq();
cascade_node = of_find_compatible_node(NULL, NULL, "gef,fpga-pic");
if (!cascade_node) {
printk(KERN_WARNING "SBC310: No FPGA PIC\n");
return;
}
gef_pic_init(cascade_node);
of_node_put(cascade_node);
}
static void __init gef_sbc310_setup_arch(void)
{
struct device_node *regs;
printk(KERN_INFO "GE Intelligent Platforms SBC310 6U VPX SBC\n");
#ifdef CONFIG_SMP
mpc86xx_smp_init();
#endif
fsl_pci_assign_primary();
regs = of_find_compatible_node(NULL, NULL, "gef,fpga-regs");
if (regs) {
sbc310_regs = of_iomap(regs, 0);
if (sbc310_regs == NULL)
printk(KERN_WARNING "Unable to map board registers\n");
of_node_put(regs);
}
#if defined(CONFIG_MMIO_NVRAM)
mmio_nvram_init();
#endif
}
static unsigned int gef_sbc310_get_board_id(void)
{
unsigned int reg;
reg = ioread32(sbc310_regs);
return reg & 0xff;
}
static unsigned int gef_sbc310_get_pcb_rev(void)
{
unsigned int reg;
reg = ioread32(sbc310_regs);
return (reg >> 8) & 0xff;
}
static unsigned int gef_sbc310_get_board_rev(void)
{
unsigned int reg;
reg = ioread32(sbc310_regs);
return (reg >> 16) & 0xff;
}
static unsigned int gef_sbc310_get_fpga_rev(void)
{
unsigned int reg;
reg = ioread32(sbc310_regs);
return (reg >> 24) & 0xf;
}
static void gef_sbc310_show_cpuinfo(struct seq_file *m)
{
uint svid = mfspr(SPRN_SVR);
seq_printf(m, "Vendor\t\t: GE Intelligent Platforms\n");
seq_printf(m, "Board ID\t: 0x%2.2x\n", gef_sbc310_get_board_id());
seq_printf(m, "Revision\t: %u%c\n", gef_sbc310_get_pcb_rev(),
('A' + gef_sbc310_get_board_rev() - 1));
seq_printf(m, "FPGA Revision\t: %u\n", gef_sbc310_get_fpga_rev());
seq_printf(m, "SVR\t\t: 0x%x\n", svid);
}
static void gef_sbc310_nec_fixup(struct pci_dev *pdev)
{
unsigned int val;
if (!machine_is(gef_sbc310))
return;
printk(KERN_INFO "Running NEC uPD720101 Fixup\n");
pci_read_config_dword(pdev, 0xe0, &val);
pci_write_config_dword(pdev, 0xe0, (val & ~7) | 0x2);
pci_write_config_dword(pdev, 0xe4, 1 << 5);
}
static int __init gef_sbc310_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "gef,sbc310"))
return 1;
return 0;
}
