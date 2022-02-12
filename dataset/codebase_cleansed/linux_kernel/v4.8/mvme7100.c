static void __init mvme7100_setup_arch(void)
{
struct device_node *bcsr_node;
void __iomem *mvme7100_regs = NULL;
u8 reg;
if (ppc_md.progress)
ppc_md.progress("mvme7100_setup_arch()", 0);
#ifdef CONFIG_SMP
mpc86xx_smp_init();
#endif
fsl_pci_assign_primary();
bcsr_node = of_find_compatible_node(NULL, NULL,
"artesyn,mvme7100-bcsr");
if (bcsr_node) {
mvme7100_regs = of_iomap(bcsr_node, 0);
of_node_put(bcsr_node);
}
if (mvme7100_regs) {
reg = readb(mvme7100_regs + MVME7100_INTERRUPT_REG_2_OFFSET);
reg |= MVME7100_DS1375_MASK | MVME7100_MAX6649_MASK
| MVME7100_ABORT_MASK;
writeb(reg, mvme7100_regs + MVME7100_INTERRUPT_REG_2_OFFSET);
} else
pr_warn("Unable to map board registers\n");
pr_info("MVME7100 board from Artesyn\n");
}
static int __init mvme7100_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "artesyn,MVME7100");
}
static void mvme7100_usb_host_fixup(struct pci_dev *pdev)
{
unsigned int val;
if (!machine_is(mvme7100))
return;
pci_read_config_dword(pdev, 0xe0, &val);
pci_write_config_dword(pdev, 0xe0, (val & ~7) | 0x2);
pci_write_config_dword(pdev, 0xe4, 1 << 5);
}
