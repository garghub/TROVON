static void __init mpc85xx_rds_setup_arch(void)
{
struct device_node *np;
if (ppc_md.progress)
ppc_md.progress("p1023_rds_setup_arch()", 0);
np = of_find_node_by_name(NULL, "bcsr");
if (np != NULL) {
static u8 __iomem *bcsr_regs;
bcsr_regs = of_iomap(np, 0);
of_node_put(np);
if (!bcsr_regs) {
printk(KERN_ERR
"BCSR: Failed to map bcsr register space\n");
return;
} else {
#define BCSR15_I2C_BUS0_SEG_CLR 0x07
#define BCSR15_I2C_BUS0_SEG2 0x02
#ifdef CONFIG_RTC_CLASS
clrbits8(&bcsr_regs[15], BCSR15_I2C_BUS0_SEG_CLR);
setbits8(&bcsr_regs[15], BCSR15_I2C_BUS0_SEG2);
#endif
iounmap(bcsr_regs);
}
}
#ifdef CONFIG_PCI
for_each_compatible_node(np, "pci", "fsl,p1023-pcie")
fsl_add_bridge(np, 0);
#endif
#ifdef CONFIG_SMP
mpc85xx_smp_init();
#endif
}
static int __init p1023_publish_devices(void)
{
of_platform_bus_probe(NULL, p1023_ids, NULL);
return 0;
}
static void __init mpc85xx_rds_pic_init(void)
{
struct mpic *mpic;
struct resource r;
struct device_node *np = NULL;
np = of_find_node_by_type(NULL, "open-pic");
if (!np) {
printk(KERN_ERR "Could not find open-pic node\n");
return;
}
if (of_address_to_resource(np, 0, &r)) {
printk(KERN_ERR "Failed to map mpic register space\n");
of_node_put(np);
return;
}
mpic = mpic_alloc(np, r.start,
MPIC_PRIMARY | MPIC_WANTS_RESET | MPIC_BIG_ENDIAN |
MPIC_BROKEN_FRR_NIRQS | MPIC_SINGLE_DEST_CPU,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
of_node_put(np);
mpic_init(mpic);
}
static int __init p1023_rds_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "fsl,P1023RDS");
}
