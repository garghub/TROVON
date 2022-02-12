void __init xes_mpc85xx_pic_init(void)
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
mpic = mpic_alloc(np, r.start,
MPIC_PRIMARY | MPIC_WANTS_RESET |
MPIC_BIG_ENDIAN | MPIC_BROKEN_FRR_NIRQS,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
of_node_put(np);
mpic_init(mpic);
}
static void xes_mpc85xx_configure_l2(void __iomem *l2_base)
{
volatile uint32_t ctl, tmp;
asm volatile("msync; isync");
tmp = in_be32(l2_base);
printk(KERN_INFO "xes_mpc85xx: Enabling L2 as cache\n");
ctl = MPC85xx_L2CTL_L2E | MPC85xx_L2CTL_L2I;
if (of_machine_is_compatible("MPC8540") ||
of_machine_is_compatible("MPC8560"))
ctl |= (tmp & MPC85xx_L2CTL_L2SIZ_MASK) >> 2;
asm volatile("msync; isync");
out_be32(l2_base, ctl);
asm volatile("msync; isync");
}
static void xes_mpc85xx_fixups(void)
{
struct device_node *np;
int err;
for_each_node_by_name(np, "l2-cache-controller") {
struct resource r[2];
void __iomem *l2_base;
if (!of_device_is_compatible(np,
"fsl,mpc8548-l2-cache-controller") &&
!of_device_is_compatible(np,
"fsl,mpc8540-l2-cache-controller") &&
!of_device_is_compatible(np,
"fsl,mpc8560-l2-cache-controller"))
continue;
err = of_address_to_resource(np, 0, &r[0]);
if (err) {
printk(KERN_WARNING "xes_mpc85xx: Could not get "
"resource for device tree node '%s'",
np->full_name);
continue;
}
l2_base = ioremap(r[0].start, resource_size(&r[0]));
xes_mpc85xx_configure_l2(l2_base);
}
}
static void __init xes_mpc85xx_setup_arch(void)
{
#ifdef CONFIG_PCI
struct device_node *np;
#endif
struct device_node *root;
const char *model = "Unknown";
root = of_find_node_by_path("/");
if (root == NULL)
return;
model = of_get_property(root, "model", NULL);
printk(KERN_INFO "X-ES MPC85xx-based single-board computer: %s\n",
model + strlen("xes,"));
xes_mpc85xx_fixups();
#ifdef CONFIG_PCI
for_each_node_by_type(np, "pci") {
if (of_device_is_compatible(np, "fsl,mpc8540-pci") ||
of_device_is_compatible(np, "fsl,mpc8548-pcie")) {
struct resource rsrc;
of_address_to_resource(np, 0, &rsrc);
if ((rsrc.start & 0xfffff) == primary_phb_addr)
fsl_add_bridge(np, 1);
else
fsl_add_bridge(np, 0);
}
}
#endif
#ifdef CONFIG_SMP
mpc85xx_smp_init();
#endif
}
static int __init xes_mpc85xx_publish_devices(void)
{
return of_platform_bus_probe(NULL, xes_mpc85xx_ids, NULL);
}
static int __init xes_mpc8572_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "xes,MPC8572")) {
#ifdef CONFIG_PCI
primary_phb_addr = 0x8000;
#endif
return 1;
} else {
return 0;
}
}
static int __init xes_mpc8548_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "xes,MPC8548")) {
#ifdef CONFIG_PCI
primary_phb_addr = 0xb000;
#endif
return 1;
} else {
return 0;
}
}
static int __init xes_mpc8540_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "xes,MPC8540")) {
#ifdef CONFIG_PCI
primary_phb_addr = 0xb000;
#endif
return 1;
} else {
return 0;
}
}
