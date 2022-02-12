static void rm9000_reg_setup(struct op_counter_config *ctr)
{
unsigned int control = 0;
if (ctr[0].enabled)
control |= RM9K_COUNTER1_EVENT(ctr[0].event) |
RM9K_COUNTER1_KERNEL |
RM9K_COUNTER1_USER |
RM9K_COUNTER1_ENABLE;
if (ctr[1].enabled)
control |= RM9K_COUNTER2_EVENT(ctr[1].event) |
RM9K_COUNTER2_KERNEL |
RM9K_COUNTER2_USER |
RM9K_COUNTER2_ENABLE;
reg.control = control;
reg.reset_counter1 = 0x80000000 - ctr[0].count;
reg.reset_counter2 = 0x80000000 - ctr[1].count;
}
static void rm9000_cpu_setup(void *args)
{
uint64_t perfcount;
perfcount = ((uint64_t) reg.reset_counter2 << 32) | reg.reset_counter1;
write_c0_perfcount(perfcount);
}
static void rm9000_cpu_start(void *args)
{
write_c0_perfcontrol(reg.control);
}
static void rm9000_cpu_stop(void *args)
{
write_c0_perfcontrol(0);
}
static irqreturn_t rm9000_perfcount_handler(int irq, void *dev_id)
{
unsigned int control = read_c0_perfcontrol();
struct pt_regs *regs = get_irq_regs();
uint32_t counter1, counter2;
uint64_t counters;
write_c0_perfcontrol(0);
counters = read_c0_perfcount();
counter1 = counters;
counter2 = counters >> 32;
if (control & RM9K_COUNTER1_OVERFLOW) {
oprofile_add_sample(regs, 0);
counter1 = reg.reset_counter1;
}
if (control & RM9K_COUNTER2_OVERFLOW) {
oprofile_add_sample(regs, 1);
counter2 = reg.reset_counter2;
}
counters = ((uint64_t)counter2 << 32) | counter1;
write_c0_perfcount(counters);
write_c0_perfcontrol(reg.control);
return IRQ_HANDLED;
}
static int __init rm9000_init(void)
{
return request_irq(rm9000_perfcount_irq, rm9000_perfcount_handler,
0, "Perfcounter", NULL);
}
static void rm9000_exit(void)
{
free_irq(rm9000_perfcount_irq, NULL);
}
