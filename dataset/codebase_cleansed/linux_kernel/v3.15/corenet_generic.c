void __init corenet_gen_pic_init(void)
{
struct mpic *mpic;
unsigned int flags = MPIC_BIG_ENDIAN | MPIC_SINGLE_DEST_CPU |
MPIC_NO_RESET;
struct device_node *np;
if (ppc_md.get_irq == mpic_get_coreint_irq)
flags |= MPIC_ENABLE_COREINT;
mpic = mpic_alloc(NULL, 0, flags, 0, 512, " OpenPIC ");
BUG_ON(mpic == NULL);
mpic_init(mpic);
np = of_find_compatible_node(NULL, NULL, "fsl,qe-ic");
if (np) {
qe_ic_init(np, 0, qe_ic_cascade_low_mpic,
qe_ic_cascade_high_mpic);
of_node_put(np);
}
}
void __init corenet_gen_setup_arch(void)
{
mpc85xx_smp_init();
swiotlb_detect_4g();
pr_info("%s board from Freescale Semiconductor\n", ppc_md.name);
mpc85xx_qe_init();
}
int __init corenet_gen_publish_devices(void)
{
return of_platform_bus_probe(NULL, of_device_ids, NULL);
}
static int __init corenet_generic_probe(void)
{
unsigned long root = of_get_flat_dt_root();
#ifdef CONFIG_SMP
extern struct smp_ops_t smp_85xx_ops;
#endif
if (of_flat_dt_match(root, boards))
return 1;
if (of_flat_dt_match(root, hv_boards)) {
ppc_md.init_IRQ = ehv_pic_init;
ppc_md.get_irq = ehv_pic_get_irq;
ppc_md.restart = fsl_hv_restart;
ppc_md.power_off = fsl_hv_halt;
ppc_md.halt = fsl_hv_halt;
#ifdef CONFIG_SMP
smp_85xx_ops.give_timebase = NULL;
smp_85xx_ops.take_timebase = NULL;
#endif
return 1;
}
return 0;
}
