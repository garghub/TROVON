void __init ge_imp3a_pic_init(void)
{
struct mpic *mpic;
struct device_node *np;
struct device_node *cascade_node = NULL;
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "fsl,MPC8572DS-CAMP")) {
mpic = mpic_alloc(NULL, 0,
MPIC_NO_RESET |
MPIC_BIG_ENDIAN |
MPIC_SINGLE_DEST_CPU,
0, 256, " OpenPIC ");
} else {
mpic = mpic_alloc(NULL, 0,
MPIC_BIG_ENDIAN |
MPIC_SINGLE_DEST_CPU,
0, 256, " OpenPIC ");
}
BUG_ON(mpic == NULL);
mpic_init(mpic);
for_each_node_by_type(np, "interrupt-controller")
if (of_device_is_compatible(np, "gef,fpga-pic-1.00")) {
cascade_node = np;
break;
}
if (cascade_node == NULL) {
printk(KERN_WARNING "IMP3A: No FPGA PIC\n");
return;
}
gef_pic_init(cascade_node);
of_node_put(cascade_node);
}
static void __init ge_imp3a_setup_arch(void)
{
struct device_node *regs;
#ifdef CONFIG_PCI
struct device_node *np;
struct pci_controller *hose;
#endif
dma_addr_t max = 0xffffffff;
if (ppc_md.progress)
ppc_md.progress("ge_imp3a_setup_arch()", 0);
#ifdef CONFIG_PCI
for_each_node_by_type(np, "pci") {
if (of_device_is_compatible(np, "fsl,mpc8540-pci") ||
of_device_is_compatible(np, "fsl,mpc8548-pcie") ||
of_device_is_compatible(np, "fsl,p2020-pcie")) {
struct resource rsrc;
of_address_to_resource(np, 0, &rsrc);
if ((rsrc.start & 0xfffff) == primary_phb_addr)
fsl_add_bridge(np, 1);
else
fsl_add_bridge(np, 0);
hose = pci_find_hose_for_OF_device(np);
max = min(max, hose->dma_window_base_cur +
hose->dma_window_size);
}
}
#endif
mpc85xx_smp_init();
#ifdef CONFIG_SWIOTLB
if ((memblock_end_of_DRAM() - 1) > max) {
ppc_swiotlb_enable = 1;
set_pci_dma_ops(&swiotlb_dma_ops);
ppc_md.pci_dma_dev_setup = pci_dma_dev_setup_swiotlb;
}
#endif
regs = of_find_compatible_node(NULL, NULL, "ge,imp3a-fpga-regs");
if (regs) {
imp3a_regs = of_iomap(regs, 0);
if (imp3a_regs == NULL)
printk(KERN_WARNING "Unable to map board registers\n");
of_node_put(regs);
}
#if defined(CONFIG_MMIO_NVRAM)
mmio_nvram_init();
#endif
printk(KERN_INFO "GE Intelligent Platforms IMP3A 3U cPCI SBC\n");
}
static unsigned int ge_imp3a_get_pcb_rev(void)
{
unsigned int reg;
reg = ioread16(imp3a_regs);
return (reg >> 8) & 0xff;
}
static unsigned int ge_imp3a_get_board_rev(void)
{
unsigned int reg;
reg = ioread16(imp3a_regs + 0x2);
return reg & 0xff;
}
static unsigned int ge_imp3a_get_fpga_rev(void)
{
unsigned int reg;
reg = ioread16(imp3a_regs + 0x2);
return (reg >> 8) & 0xff;
}
static unsigned int ge_imp3a_get_cpci_geo_addr(void)
{
unsigned int reg;
reg = ioread16(imp3a_regs + 0x6);
return (reg & 0x0f00) >> 8;
}
static unsigned int ge_imp3a_get_cpci_is_syscon(void)
{
unsigned int reg;
reg = ioread16(imp3a_regs + 0x6);
return reg & (1 << 12);
}
static void ge_imp3a_show_cpuinfo(struct seq_file *m)
{
seq_printf(m, "Vendor\t\t: GE Intelligent Platforms\n");
seq_printf(m, "Revision\t: %u%c\n", ge_imp3a_get_pcb_rev(),
('A' + ge_imp3a_get_board_rev() - 1));
seq_printf(m, "FPGA Revision\t: %u\n", ge_imp3a_get_fpga_rev());
seq_printf(m, "cPCI geo. addr\t: %u\n", ge_imp3a_get_cpci_geo_addr());
seq_printf(m, "cPCI syscon\t: %s\n",
ge_imp3a_get_cpci_is_syscon() ? "yes" : "no");
}
static int __init ge_imp3a_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "ge,IMP3A")) {
#ifdef CONFIG_PCI
primary_phb_addr = 0x9000;
#endif
return 1;
}
return 0;
}
