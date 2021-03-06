int mpc7448_hpc2_exclude_device(struct pci_controller *hose,
u_char bus, u_char devfn)
{
if (bus == 0 && PCI_SLOT(devfn) == 0)
return PCIBIOS_DEVICE_NOT_FOUND;
else
return PCIBIOS_SUCCESSFUL;
}
static void __init mpc7448_hpc2_setup_arch(void)
{
struct device_node *np;
if (ppc_md.progress)
ppc_md.progress("mpc7448_hpc2_setup_arch():set_bridge", 0);
tsi108_csr_vir_base = get_vir_csrbase();
#ifdef CONFIG_PCI
for_each_compatible_node(np, "pci", "tsi108-pci")
tsi108_setup_pci(np, MPC7448HPC2_PCI_CFG_PHYS, 0);
ppc_md.pci_exclude_device = mpc7448_hpc2_exclude_device;
if (ppc_md.progress)
ppc_md.progress("tsi108: resources set", 0x100);
#endif
printk(KERN_INFO "MPC7448HPC2 (TAIGA) Platform\n");
printk(KERN_INFO
"Jointly ported by Freescale and Tundra Semiconductor\n");
printk(KERN_INFO
"Enabling L2 cache then enabling the HID0 prefetch engine.\n");
}
static void __init mpc7448_hpc2_init_IRQ(void)
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
printk("%s: No tsi108 pci node found !\n", __func__);
return;
}
cascade_node = of_find_node_by_type(NULL, "pic-router");
if (cascade_node == NULL) {
printk("%s: No tsi108 pci cascade node found !\n", __func__);
return;
}
cascade_pci_irq = irq_of_parse_and_map(tsi_pci, 0);
DBG("%s: tsi108 cascade_pci_irq = 0x%x\n", __func__,
(u32) cascade_pci_irq);
tsi108_pci_int_init(cascade_node);
irq_set_handler_data(cascade_pci_irq, mpic);
irq_set_chained_handler(cascade_pci_irq, tsi108_irq_cascade);
#endif
tsi108_write_reg(TSI108_MPIC_OFFSET + 0x30c, 0);
}
void mpc7448_hpc2_show_cpuinfo(struct seq_file *m)
{
seq_printf(m, "vendor\t\t: Freescale Semiconductor\n");
}
void mpc7448_hpc2_restart(char *cmd)
{
local_irq_disable();
_nmask_and_or_msr(0, MSR_IP);
for (;;) ;
}
void mpc7448_hpc2_power_off(void)
{
local_irq_disable();
for (;;) ;
}
void mpc7448_hpc2_halt(void)
{
mpc7448_hpc2_power_off();
}
static int __init mpc7448_hpc2_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (!of_flat_dt_is_compatible(root, "mpc74xx"))
return 0;
return 1;
}
static int mpc7448_machine_check_exception(struct pt_regs *regs)
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
