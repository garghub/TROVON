static int __init sead3_net_init(void)
{
if (gic_present)
sead3_net_resources[1].start = MIPS_GIC_IRQ_BASE + GIC_INT_NET;
else
sead3_net_resources[1].start = MIPS_CPU_IRQ_BASE + CPU_INT_NET;
return platform_device_register(&sead3_net_device);
}
