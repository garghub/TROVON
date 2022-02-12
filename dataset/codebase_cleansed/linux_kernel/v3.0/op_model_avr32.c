static void avr32_perf_counter_reset(void)
{
sysreg_write(PCCR, (SYSREG_BIT(PCCR_R)
| SYSREG_BIT(PCCR_C)
| SYSREG_BIT(FC)
| SYSREG_BIT(F0)
| SYSREG_BIT(F1)));
}
static irqreturn_t avr32_perf_counter_interrupt(int irq, void *dev_id)
{
struct avr32_perf_counter *ctr = dev_id;
struct pt_regs *regs;
u32 pccr;
if (likely(!(intc_get_pending(AVR32_PERFCTR_IRQ_GROUP)
& (1 << AVR32_PERFCTR_IRQ_LINE))))
return IRQ_NONE;
regs = get_irq_regs();
pccr = sysreg_read(PCCR);
sysreg_write(PCCR, pccr);
if (ctr->enabled && (pccr & ctr->flag_mask)) {
sysreg_write(PCCNT, -ctr->count);
oprofile_add_sample(regs, PCCNT);
}
ctr++;
if (ctr->enabled && (pccr & ctr->flag_mask)) {
sysreg_write(PCNT0, -ctr->count);
oprofile_add_sample(regs, PCNT0);
}
ctr++;
if (ctr->enabled && (pccr & ctr->flag_mask)) {
sysreg_write(PCNT1, -ctr->count);
oprofile_add_sample(regs, PCNT1);
}
return IRQ_HANDLED;
}
static int avr32_perf_counter_create_files(struct super_block *sb,
struct dentry *root)
{
struct dentry *dir;
unsigned int i;
char filename[4];
for (i = 0; i < NR_counter; i++) {
snprintf(filename, sizeof(filename), "%u", i);
dir = oprofilefs_mkdir(sb, root, filename);
oprofilefs_create_ulong(sb, dir, "enabled",
&counter[i].enabled);
oprofilefs_create_ulong(sb, dir, "event",
&counter[i].event);
oprofilefs_create_ulong(sb, dir, "count",
&counter[i].count);
oprofilefs_create_ulong(sb, dir, "kernel",
&counter[i].kernel);
oprofilefs_create_ulong(sb, dir, "user",
&counter[i].user);
oprofilefs_create_ulong(sb, dir, "unit_mask",
&counter[i].unit_mask);
}
return 0;
}
static int avr32_perf_counter_setup(void)
{
struct avr32_perf_counter *ctr;
u32 pccr;
int ret;
int i;
pr_debug("avr32_perf_counter_setup\n");
if (sysreg_read(PCCR) & SYSREG_BIT(PCCR_E)) {
printk(KERN_ERR
"oprofile: setup: perf counter already enabled\n");
return -EBUSY;
}
ret = request_irq(AVR32_PERFCTR_IRQ_GROUP,
avr32_perf_counter_interrupt, IRQF_SHARED,
"oprofile", counter);
if (ret)
return ret;
avr32_perf_counter_reset();
pccr = 0;
for (i = PCCNT; i < NR_counter; i++) {
ctr = &counter[i];
if (!ctr->enabled)
continue;
pr_debug("enabling counter %d...\n", i);
pccr |= ctr->ie_mask;
switch (i) {
case PCCNT:
sysreg_write(PCCNT, -ctr->count);
break;
case PCNT0:
pccr |= SYSREG_BF(CONF0, ctr->event);
sysreg_write(PCNT0, -ctr->count);
break;
case PCNT1:
pccr |= SYSREG_BF(CONF1, ctr->event);
sysreg_write(PCNT1, -ctr->count);
break;
}
}
pr_debug("oprofile: writing 0x%x to PCCR...\n", pccr);
sysreg_write(PCCR, pccr);
return 0;
}
static void avr32_perf_counter_shutdown(void)
{
pr_debug("avr32_perf_counter_shutdown\n");
avr32_perf_counter_reset();
free_irq(AVR32_PERFCTR_IRQ_GROUP, counter);
}
static int avr32_perf_counter_start(void)
{
pr_debug("avr32_perf_counter_start\n");
sysreg_write(PCCR, sysreg_read(PCCR) | SYSREG_BIT(PCCR_E));
return 0;
}
static void avr32_perf_counter_stop(void)
{
pr_debug("avr32_perf_counter_stop\n");
sysreg_write(PCCR, sysreg_read(PCCR) & ~SYSREG_BIT(PCCR_E));
}
int __init oprofile_arch_init(struct oprofile_operations *ops)
{
if (!(current_cpu_data.features & AVR32_FEATURE_PCTR))
return -ENODEV;
memcpy(ops, &avr32_perf_counter_ops,
sizeof(struct oprofile_operations));
ops->backtrace = avr32_backtrace;
printk(KERN_INFO "oprofile: using AVR32 performance monitoring.\n");
return 0;
}
void oprofile_arch_exit(void)
{
}
