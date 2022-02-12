static void mpc85xx_irq_mask(int cpu)
{
}
static void mpc85xx_irq_unmask(int cpu)
{
}
static void mpc85xx_cpu_die(int cpu)
{
u32 tmp;
tmp = (mfspr(SPRN_HID0) & ~(HID0_DOZE|HID0_SLEEP)) | HID0_NAP;
mtspr(SPRN_HID0, tmp);
tmp = mfmsr();
tmp |= MSR_WE;
asm volatile(
"msync\n"
"mtmsr %0\n"
"isync\n"
:
: "r" (tmp));
}
static void mpc85xx_cpu_up_prepare(int cpu)
{
}
static void mpc85xx_freeze_time_base(bool freeze)
{
uint32_t mask;
mask = CCSR_GUTS_DEVDISR_TB0 | CCSR_GUTS_DEVDISR_TB1;
if (freeze)
setbits32(&guts->devdisr, mask);
else
clrbits32(&guts->devdisr, mask);
in_be32(&guts->devdisr);
}
int __init mpc85xx_setup_pmc(void)
{
struct device_node *np;
np = of_find_matching_node(NULL, mpc85xx_smp_guts_ids);
if (np) {
guts = of_iomap(np, 0);
of_node_put(np);
if (!guts) {
pr_err("Could not map guts node address\n");
return -ENOMEM;
}
}
qoriq_pm_ops = &mpc85xx_pm_ops;
return 0;
}
