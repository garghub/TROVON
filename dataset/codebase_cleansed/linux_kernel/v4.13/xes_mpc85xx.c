void __init xes_mpc85xx_pic_init(void)
{
struct mpic *mpic = mpic_alloc(NULL, 0, MPIC_BIG_ENDIAN,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
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
struct device_node *root;
const char *model = "Unknown";
root = of_find_node_by_path("/");
if (root == NULL)
return;
model = of_get_property(root, "model", NULL);
printk(KERN_INFO "X-ES MPC85xx-based single-board computer: %s\n",
model + strlen("xes,"));
xes_mpc85xx_fixups();
mpc85xx_smp_init();
fsl_pci_assign_primary();
}
static int __init xes_mpc8572_probe(void)
{
return of_machine_is_compatible("xes,MPC8572");
}
static int __init xes_mpc8548_probe(void)
{
return of_machine_is_compatible("xes,MPC8548");
}
static int __init xes_mpc8540_probe(void)
{
return of_machine_is_compatible("xes,MPC8540");
}
