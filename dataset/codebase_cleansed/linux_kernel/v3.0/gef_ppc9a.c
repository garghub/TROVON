static void __init gef_ppc9a_init_irq(void)
{
struct device_node *cascade_node = NULL;
mpc86xx_init_irq();
cascade_node = of_find_compatible_node(NULL, NULL, "gef,fpga-pic-1.00");
if (!cascade_node) {
printk(KERN_WARNING "PPC9A: No FPGA PIC\n");
return;
}
gef_pic_init(cascade_node);
of_node_put(cascade_node);
}
static void __init gef_ppc9a_setup_arch(void)
{
struct device_node *regs;
#ifdef CONFIG_PCI
struct device_node *np;
for_each_compatible_node(np, "pci", "fsl,mpc8641-pcie") {
fsl_add_bridge(np, 1);
}
#endif
printk(KERN_INFO "GE Intelligent Platforms PPC9A 6U VME SBC\n");
#ifdef CONFIG_SMP
mpc86xx_smp_init();
#endif
regs = of_find_compatible_node(NULL, NULL, "gef,ppc9a-fpga-regs");
if (regs) {
ppc9a_regs = of_iomap(regs, 0);
if (ppc9a_regs == NULL)
printk(KERN_WARNING "Unable to map board registers\n");
of_node_put(regs);
}
#if defined(CONFIG_MMIO_NVRAM)
mmio_nvram_init();
#endif
}
static unsigned int gef_ppc9a_get_pcb_rev(void)
{
unsigned int reg;
reg = ioread32be(ppc9a_regs);
return (reg >> 16) & 0xff;
}
static unsigned int gef_ppc9a_get_board_rev(void)
{
unsigned int reg;
reg = ioread32be(ppc9a_regs);
return (reg >> 8) & 0xff;
}
static unsigned int gef_ppc9a_get_fpga_rev(void)
{
unsigned int reg;
reg = ioread32be(ppc9a_regs);
return reg & 0xf;
}
static unsigned int gef_ppc9a_get_vme_geo_addr(void)
{
unsigned int reg;
reg = ioread32be(ppc9a_regs + 0x4);
return reg & 0x1f;
}
static unsigned int gef_ppc9a_get_vme_is_syscon(void)
{
unsigned int reg;
reg = ioread32be(ppc9a_regs + 0x4);
return (reg >> 9) & 0x1;
}
static void gef_ppc9a_show_cpuinfo(struct seq_file *m)
{
uint svid = mfspr(SPRN_SVR);
seq_printf(m, "Vendor\t\t: GE Intelligent Platforms\n");
seq_printf(m, "Revision\t: %u%c\n", gef_ppc9a_get_pcb_rev(),
('A' + gef_ppc9a_get_board_rev()));
seq_printf(m, "FPGA Revision\t: %u\n", gef_ppc9a_get_fpga_rev());
seq_printf(m, "SVR\t\t: 0x%x\n", svid);
seq_printf(m, "VME geo. addr\t: %u\n", gef_ppc9a_get_vme_geo_addr());
seq_printf(m, "VME syscon\t: %s\n",
gef_ppc9a_get_vme_is_syscon() ? "yes" : "no");
}
static void __init gef_ppc9a_nec_fixup(struct pci_dev *pdev)
{
unsigned int val;
if (!machine_is(gef_ppc9a))
return;
printk(KERN_INFO "Running NEC uPD720101 Fixup\n");
pci_read_config_dword(pdev, 0xe0, &val);
pci_write_config_dword(pdev, 0xe0, (val & ~7) | 0x5);
pci_write_config_dword(pdev, 0xe4, 1 << 5);
}
static int __init gef_ppc9a_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "gef,ppc9a"))
return 1;
return 0;
}
static long __init mpc86xx_time_init(void)
{
unsigned int temp;
mtspr(SPRN_TBWL, 0);
mtspr(SPRN_TBWU, 0);
temp = mfspr(SPRN_HID0);
temp |= HID0_TBEN;
mtspr(SPRN_HID0, temp);
asm volatile("isync");
return 0;
}
static int __init declare_of_platform_devices(void)
{
printk(KERN_DEBUG "Probe platform devices\n");
of_platform_bus_probe(NULL, of_bus_ids, NULL);
return 0;
}
