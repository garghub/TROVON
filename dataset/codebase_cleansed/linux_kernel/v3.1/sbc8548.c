static void __init sbc8548_pic_init(void)
{
struct mpic *mpic;
struct resource r;
struct device_node *np = NULL;
np = of_find_node_by_type(np, "open-pic");
if (np == NULL) {
printk(KERN_ERR "Could not find open-pic node\n");
return;
}
if (of_address_to_resource(np, 0, &r)) {
printk(KERN_ERR "Failed to map mpic register space\n");
of_node_put(np);
return;
}
mpic = mpic_alloc(np, r.start,
MPIC_PRIMARY | MPIC_WANTS_RESET | MPIC_BIG_ENDIAN,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
of_node_put(np);
mpic_init(mpic);
}
static int __init sbc8548_hw_rev(void)
{
struct device_node *np;
struct resource res;
unsigned int *rev;
int board_rev = 0;
np = of_find_compatible_node(NULL, NULL, "hw-rev");
if (np == NULL) {
printk("No HW-REV found in DTB.\n");
return -ENODEV;
}
of_address_to_resource(np, 0, &res);
of_node_put(np);
rev = ioremap(res.start,sizeof(unsigned int));
board_rev = (*rev) >> 28;
iounmap(rev);
return board_rev;
}
static void __init sbc8548_setup_arch(void)
{
#ifdef CONFIG_PCI
struct device_node *np;
#endif
if (ppc_md.progress)
ppc_md.progress("sbc8548_setup_arch()", 0);
#ifdef CONFIG_PCI
for_each_node_by_type(np, "pci") {
if (of_device_is_compatible(np, "fsl,mpc8540-pci") ||
of_device_is_compatible(np, "fsl,mpc8548-pcie")) {
struct resource rsrc;
of_address_to_resource(np, 0, &rsrc);
if ((rsrc.start & 0xfffff) == 0x8000)
fsl_add_bridge(np, 1);
else
fsl_add_bridge(np, 0);
}
}
#endif
sbc_rev = sbc8548_hw_rev();
}
static void sbc8548_show_cpuinfo(struct seq_file *m)
{
uint pvid, svid, phid1;
pvid = mfspr(SPRN_PVR);
svid = mfspr(SPRN_SVR);
seq_printf(m, "Vendor\t\t: Wind River\n");
seq_printf(m, "Machine\t\t: SBC8548 v%d\n", sbc_rev);
seq_printf(m, "PVR\t\t: 0x%x\n", pvid);
seq_printf(m, "SVR\t\t: 0x%x\n", svid);
phid1 = mfspr(SPRN_HID1);
seq_printf(m, "PLL setting\t: 0x%x\n", ((phid1 >> 24) & 0x3f));
}
static int __init declare_of_platform_devices(void)
{
of_platform_bus_probe(NULL, of_bus_ids, NULL);
return 0;
}
static int __init sbc8548_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "SBC8548");
}
