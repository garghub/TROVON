int holly_exclude_device(struct pci_controller *hose, u_char bus, u_char devfn)
{
if (bus == 0 && PCI_SLOT(devfn) == 0)
return PCIBIOS_DEVICE_NOT_FOUND;
else
return PCIBIOS_SUCCESSFUL;
}
static void holly_remap_bridge(void)
{
u32 lut_val, lut_addr;
int i;
printk(KERN_INFO "Remapping PCI bridge\n");
lut_addr = 0x900;
for (i = 0; i < 31; i++) {
tsi108_write_reg(TSI108_PB_OFFSET + lut_addr, 0x00000201);
lut_addr += 4;
tsi108_write_reg(TSI108_PB_OFFSET + lut_addr, 0x0);
lut_addr += 4;
}
tsi108_write_reg(TSI108_PB_OFFSET + lut_addr, 0x00000241);
lut_addr += 4;
tsi108_write_reg(TSI108_PB_OFFSET + lut_addr, 0x0);
tsi108_write_reg(TSI108_PCI_PFAB_IO_UPPER, 0x0);
tsi108_write_reg(TSI108_PCI_PFAB_IO, 0x1);
tsi108_write_reg(TSI108_PCI_PFAB_BAR0_UPPER, 0x0);
tsi108_write_reg(TSI108_PCI_PFAB_BAR0, 0x7c000000 | 0x01);
tsi108_write_reg(TSI108_PCI_PFAB_MEM32, 0x0);
tsi108_write_reg(TSI108_PCI_PFAB_PFM3, 0x0);
tsi108_write_reg(TSI108_PCI_PFAB_PFM4, 0x0);
tsi108_write_reg(TSI108_PCI_P2O_BAR0_UPPER, 0x0);
tsi108_write_reg(TSI108_PCI_P2O_BAR0, 0xc0000000);
lut_addr = 0x500;
lut_val = 0x00000002;
for (i = 0; i < 32; i++) {
tsi108_write_reg(TSI108_PCI_OFFSET + lut_addr, lut_val);
lut_addr += 4;
tsi108_write_reg(TSI108_PCI_OFFSET + lut_addr, 0x40000000);
lut_addr += 4;
lut_val += 0x02000000;
}
tsi108_write_reg(TSI108_PCI_P2O_PAGE_SIZES, 0x00007900);
tsi108_write_reg(TSI108_PCI_P2O_BAR2_UPPER, 0x0);
tsi108_write_reg(TSI108_PCI_P2O_BAR2, 0x0);
}
static void __init holly_setup_arch(void)
{
struct device_node *np;
if (ppc_md.progress)
ppc_md.progress("holly_setup_arch():set_bridge", 0);
tsi108_csr_vir_base = get_vir_csrbase();
holly_remap_bridge();
np = of_find_node_by_type(NULL, "pci");
if (np)
tsi108_setup_pci(np, HOLLY_PCI_CFG_PHYS, 1);
ppc_md.pci_exclude_device = holly_exclude_device;
if (ppc_md.progress)
ppc_md.progress("tsi108: resources set", 0x100);
printk(KERN_INFO "PPC750GX/CL Platform\n");
}
static void __init holly_init_IRQ(void)
{
struct mpic *mpic;
#ifdef CONFIG_PCI
unsigned int cascade_pci_irq;
struct device_node *tsi_pci;
struct device_node *cascade_node = NULL;
#endif
mpic = mpic_alloc(NULL, 0,
MPIC_BIG_ENDIAN | MPIC_WANTS_RESET |
MPIC_SPV_EOI | MPIC_NO_PTHROU_DIS | MPIC_REGSET_TSI108,
24,
NR_IRQS-4,
"Tsi108_PIC");
BUG_ON(mpic == NULL);
mpic_assign_isu(mpic, 0, mpic->paddr + 0x100);
mpic_init(mpic);
#ifdef CONFIG_PCI
tsi_pci = of_find_node_by_type(NULL, "pci");
if (tsi_pci == NULL) {
printk(KERN_ERR "%s: No tsi108 pci node found !\n", __func__);
return;
}
cascade_node = of_find_node_by_type(NULL, "pic-router");
if (cascade_node == NULL) {
printk(KERN_ERR "%s: No tsi108 pci cascade node found !\n", __func__);
return;
}
cascade_pci_irq = irq_of_parse_and_map(tsi_pci, 0);
pr_debug("%s: tsi108 cascade_pci_irq = 0x%x\n", __func__, (u32) cascade_pci_irq);
tsi108_pci_int_init(cascade_node);
irq_set_handler_data(cascade_pci_irq, mpic);
irq_set_chained_handler(cascade_pci_irq, tsi108_irq_cascade);
#endif
tsi108_write_reg(TSI108_MPIC_OFFSET + 0x30c, 0);
}
void holly_show_cpuinfo(struct seq_file *m)
{
seq_printf(m, "vendor\t\t: IBM\n");
seq_printf(m, "machine\t\t: PPC750 GX/CL\n");
}
void holly_restart(char *cmd)
{
__be32 __iomem *ocn_bar1 = NULL;
unsigned long bar;
struct device_node *bridge = NULL;
const void *prop;
int size;
phys_addr_t addr = 0xc0000000;
local_irq_disable();
bridge = of_find_node_by_type(NULL, "tsi-bridge");
if (bridge) {
prop = of_get_property(bridge, "reg", &size);
addr = of_translate_address(bridge, prop);
}
addr += (TSI108_PB_OFFSET + 0x414);
ocn_bar1 = ioremap(addr, 0x4);
bar = ioread32be(ocn_bar1);
bar |= 2;
iowrite32be(bar, ocn_bar1);
iosync();
mtspr(SPRN_SRR0, 0xfff00100);
mtspr(SPRN_SRR1, MSR_IP);
__asm__ __volatile__("rfi" : : : "memory");
for (;;) ;
}
void holly_power_off(void)
{
local_irq_disable();
for (;;) ;
}
void holly_halt(void)
{
holly_power_off();
}
static int __init holly_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (!of_flat_dt_is_compatible(root, "ibm,holly"))
return 0;
return 1;
}
static int ppc750_machine_check_exception(struct pt_regs *regs)
{
const struct exception_table_entry *entry;
if ((entry = search_exception_tables(regs->nip)) != NULL) {
tsi108_clear_pci_cfg_error();
regs->msr |= MSR_RI;
regs->nip = entry->fixup;
return 1;
}
return 0;
}
