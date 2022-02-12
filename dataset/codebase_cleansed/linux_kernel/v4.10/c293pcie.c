void __init c293_pcie_pic_init(void)
{
struct mpic *mpic = mpic_alloc(NULL, 0, MPIC_BIG_ENDIAN |
MPIC_SINGLE_DEST_CPU, 0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
mpic_init(mpic);
}
static void __init c293_pcie_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("c293_pcie_setup_arch()", 0);
fsl_pci_assign_primary();
printk(KERN_INFO "C293 PCIE board from Freescale Semiconductor\n");
}
static int __init c293_pcie_probe(void)
{
if (of_machine_is_compatible("fsl,C293PCIE"))
return 1;
return 0;
}
