void __init p1010_rdb_pic_init(void)
{
struct mpic *mpic;
struct resource r;
struct device_node *np;
np = of_find_node_by_type(NULL, "open-pic");
if (np == NULL) {
printk(KERN_ERR "Could not find open-pic node\n");
return;
}
if (of_address_to_resource(np, 0, &r)) {
printk(KERN_ERR "Failed to map mpic register space\n");
of_node_put(np);
return;
}
mpic = mpic_alloc(np, r.start, MPIC_PRIMARY | MPIC_WANTS_RESET |
MPIC_BIG_ENDIAN | MPIC_BROKEN_FRR_NIRQS | MPIC_SINGLE_DEST_CPU,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
of_node_put(np);
mpic_init(mpic);
}
static void __init p1010_rdb_setup_arch(void)
{
#ifdef CONFIG_PCI
struct device_node *np;
#endif
if (ppc_md.progress)
ppc_md.progress("p1010_rdb_setup_arch()", 0);
#ifdef CONFIG_PCI
for_each_node_by_type(np, "pci") {
if (of_device_is_compatible(np, "fsl,p1010-pcie"))
fsl_add_bridge(np, 0);
}
#endif
printk(KERN_INFO "P1010 RDB board from Freescale Semiconductor\n");
}
static int __init p1010rdb_publish_devices(void)
{
return of_platform_bus_probe(NULL, p1010rdb_ids, NULL);
}
static int __init p1010_rdb_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "fsl,P1010RDB"))
return 1;
return 0;
}
