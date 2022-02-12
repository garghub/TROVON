static void __init socrates_pic_init(void)
{
struct device_node *np;
struct mpic *mpic = mpic_alloc(NULL, 0,
MPIC_WANTS_RESET | MPIC_BIG_ENDIAN,
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
#ifdef CONFIG_PCI
struct device_node *np;
#endif
if (ppc_md.progress)
ppc_md.progress("socrates_setup_arch()", 0);
#ifdef CONFIG_PCI
for_each_compatible_node(np, "pci", "fsl,mpc8540-pci")
fsl_add_bridge(np, 1);
#endif
}
static int __init socrates_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "abb,socrates"))
return 1;
return 0;
}
