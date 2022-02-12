static void __init socrates_pic_init(void)
{
struct mpic *mpic;
struct resource r;
struct device_node *np;
np = of_find_node_by_type(NULL, "open-pic");
if (!np) {
printk(KERN_ERR "Could not find open-pic node\n");
return;
}
if (of_address_to_resource(np, 0, &r)) {
printk(KERN_ERR "Could not map mpic register space\n");
of_node_put(np);
return;
}
mpic = mpic_alloc(np, r.start,
MPIC_PRIMARY | MPIC_WANTS_RESET | MPIC_BIG_ENDIAN,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
of_node_put(np);
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
static int __init socrates_publish_devices(void)
{
return of_platform_bus_probe(NULL, socrates_of_bus_ids, NULL);
}
static int __init socrates_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "abb,socrates"))
return 1;
return 0;
}
