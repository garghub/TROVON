static int __init p3060_qds_probe(void)
{
unsigned long root = of_get_flat_dt_root();
#ifdef CONFIG_SMP
extern struct smp_ops_t smp_85xx_ops;
#endif
if (of_flat_dt_is_compatible(root, "fsl,P3060QDS"))
return 1;
if (of_flat_dt_is_compatible(root, "fsl,P3060QDS-hv")) {
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
