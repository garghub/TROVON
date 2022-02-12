static void __init socrates_pic_init(void)
{
struct device_node *np;
struct mpic *mpic = mpic_alloc(NULL, 0, MPIC_BIG_ENDIAN,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
mpic_init(mpic);
np = of_find_compatible_node(NULL, NULL, "abb,socrates-fpga-pic");
if (!np) {
printk(KERN_ERR "Could not find socrates-fpga-pic node\n");
return;
}
socrates_fpga_pic_init(np);
of_node_put(np);
}
static void __init socrates_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("socrates_setup_arch()", 0);
fsl_pci_assign_primary();
}
static int __init socrates_probe(void)
{
if (of_machine_is_compatible("abb,socrates"))
return 1;
return 0;
}
