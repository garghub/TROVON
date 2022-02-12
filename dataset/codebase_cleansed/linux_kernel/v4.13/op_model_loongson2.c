static void reset_counters(void *arg)
{
write_c0_perfctrl(0);
write_c0_perfcnt(0);
}
static void loongson2_reg_setup(struct op_counter_config *cfg)
{
unsigned int ctrl = 0;
reg.reset_counter1 = 0;
reg.reset_counter2 = 0;
if (cfg[0].enabled) {
ctrl |= LOONGSON2_PERFCTRL_EVENT(0, cfg[0].event);
reg.reset_counter1 = 0x80000000ULL - cfg[0].count;
}
if (cfg[1].enabled) {
ctrl |= LOONGSON2_PERFCTRL_EVENT(1, cfg[1].event);
reg.reset_counter2 = 0x80000000ULL - cfg[1].count;
}
if (cfg[0].enabled || cfg[1].enabled) {
ctrl |= LOONGSON2_PERFCTRL_EXL | LOONGSON2_PERFCTRL_ENABLE;
if (cfg[0].kernel || cfg[1].kernel)
ctrl |= LOONGSON2_PERFCTRL_KERNEL;
if (cfg[0].user || cfg[1].user)
ctrl |= LOONGSON2_PERFCTRL_USER;
}
reg.ctrl = ctrl;
reg.cnt1_enabled = cfg[0].enabled;
reg.cnt2_enabled = cfg[1].enabled;
}
static void loongson2_cpu_setup(void *args)
{
write_c0_perfcnt((reg.reset_counter2 << 32) | reg.reset_counter1);
}
static void loongson2_cpu_start(void *args)
{
if (reg.cnt1_enabled || reg.cnt2_enabled)
write_c0_perfctrl(reg.ctrl);
}
static void loongson2_cpu_stop(void *args)
{
write_c0_perfctrl(0);
memset(&reg, 0, sizeof(reg));
}
static irqreturn_t loongson2_perfcount_handler(int irq, void *dev_id)
{
uint64_t counter, counter1, counter2;
struct pt_regs *regs = get_irq_regs();
int enabled;
enabled = read_c0_perfctrl() & LOONGSON2_PERFCTRL_ENABLE;
if (!enabled)
return IRQ_NONE;
enabled = reg.cnt1_enabled | reg.cnt2_enabled;
if (!enabled)
return IRQ_NONE;
counter = read_c0_perfcnt();
counter1 = counter & 0xffffffff;
counter2 = counter >> 32;
if (counter1 & LOONGSON2_PERFCNT_OVERFLOW) {
if (reg.cnt1_enabled)
oprofile_add_sample(regs, 0);
counter1 = reg.reset_counter1;
}
if (counter2 & LOONGSON2_PERFCNT_OVERFLOW) {
if (reg.cnt2_enabled)
oprofile_add_sample(regs, 1);
counter2 = reg.reset_counter2;
}
write_c0_perfcnt((counter2 << 32) | counter1);
return IRQ_HANDLED;
}
static int __init loongson2_init(void)
{
return request_irq(LOONGSON2_PERFCNT_IRQ, loongson2_perfcount_handler,
IRQF_SHARED, "Perfcounter", oprofid);
}
static void loongson2_exit(void)
{
reset_counters(NULL);
free_irq(LOONGSON2_PERFCNT_IRQ, oprofid);
}
