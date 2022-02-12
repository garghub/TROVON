static void reset_counters(void *arg)
{
write_c0_perfhi1(0);
write_c0_perfhi2(0);
write_c0_perflo1(0xc0000000);
write_c0_perflo2(0x40000000);
}
static void loongson3_reg_setup(struct op_counter_config *ctr)
{
unsigned int control1 = 0;
unsigned int control2 = 0;
reg.reset_counter1 = 0;
reg.reset_counter2 = 0;
if (ctr[0].enabled) {
control1 |= LOONGSON3_PERFCTRL_EVENT(0, ctr[0].event) |
LOONGSON3_PERFCTRL_ENABLE;
if (ctr[0].kernel)
control1 |= LOONGSON3_PERFCTRL_KERNEL;
if (ctr[0].user)
control1 |= LOONGSON3_PERFCTRL_USER;
reg.reset_counter1 = 0x8000000000000000ULL - ctr[0].count;
}
if (ctr[1].enabled) {
control2 |= LOONGSON3_PERFCTRL_EVENT(1, ctr[1].event) |
LOONGSON3_PERFCTRL_ENABLE;
if (ctr[1].kernel)
control2 |= LOONGSON3_PERFCTRL_KERNEL;
if (ctr[1].user)
control2 |= LOONGSON3_PERFCTRL_USER;
reg.reset_counter2 = 0x8000000000000000ULL - ctr[1].count;
}
if (ctr[0].enabled)
control1 |= LOONGSON3_PERFCTRL_EXL;
if (ctr[1].enabled)
control2 |= LOONGSON3_PERFCTRL_EXL;
reg.control1 = control1;
reg.control2 = control2;
reg.ctr1_enable = ctr[0].enabled;
reg.ctr2_enable = ctr[1].enabled;
}
static void loongson3_cpu_setup(void *args)
{
uint64_t perfcount1, perfcount2;
perfcount1 = reg.reset_counter1;
perfcount2 = reg.reset_counter2;
write_c0_perfhi1(perfcount1);
write_c0_perfhi2(perfcount2);
}
static void loongson3_cpu_start(void *args)
{
reg.control1 |= (LOONGSON3_PERFCTRL_W|LOONGSON3_PERFCTRL_M);
reg.control2 |= (LOONGSON3_PERFCTRL_W|LOONGSON3_PERFCTRL_M);
if (reg.ctr1_enable)
write_c0_perflo1(reg.control1);
if (reg.ctr2_enable)
write_c0_perflo2(reg.control2);
}
static void loongson3_cpu_stop(void *args)
{
write_c0_perflo1(0xc0000000);
write_c0_perflo2(0x40000000);
memset(&reg, 0, sizeof(reg));
}
static int loongson3_perfcount_handler(void)
{
unsigned long flags;
uint64_t counter1, counter2;
uint32_t cause, handled = IRQ_NONE;
struct pt_regs *regs = get_irq_regs();
cause = read_c0_cause();
if (!(cause & CAUSEF_PCI))
return handled;
counter1 = read_c0_perfhi1();
counter2 = read_c0_perfhi2();
local_irq_save(flags);
if (counter1 & LOONGSON3_PERFCNT_OVERFLOW) {
if (reg.ctr1_enable)
oprofile_add_sample(regs, 0);
counter1 = reg.reset_counter1;
}
if (counter2 & LOONGSON3_PERFCNT_OVERFLOW) {
if (reg.ctr2_enable)
oprofile_add_sample(regs, 1);
counter2 = reg.reset_counter2;
}
local_irq_restore(flags);
write_c0_perfhi1(counter1);
write_c0_perfhi2(counter2);
if (!(cause & CAUSEF_TI))
handled = IRQ_HANDLED;
return handled;
}
static int loongson3_starting_cpu(unsigned int cpu)
{
write_c0_perflo1(reg.control1);
write_c0_perflo2(reg.control2);
return 0;
}
static int loongson3_dying_cpu(unsigned int cpu)
{
write_c0_perflo1(0xc0000000);
write_c0_perflo2(0x40000000);
return 0;
}
static int __init loongson3_init(void)
{
on_each_cpu(reset_counters, NULL, 1);
cpuhp_setup_state_nocalls(CPUHP_AP_MIPS_OP_LOONGSON3_STARTING,
"mips/oprofile/loongson3:starting",
loongson3_starting_cpu, loongson3_dying_cpu);
save_perf_irq = perf_irq;
perf_irq = loongson3_perfcount_handler;
return 0;
}
static void loongson3_exit(void)
{
on_each_cpu(reset_counters, NULL, 1);
cpuhp_remove_state_nocalls(CPUHP_AP_MIPS_OP_LOONGSON3_STARTING);
perf_irq = save_perf_irq;
}
