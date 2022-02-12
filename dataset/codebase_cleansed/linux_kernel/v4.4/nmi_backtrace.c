static void print_seq_line(struct nmi_seq_buf *s, int start, int end)
{
const char *buf = s->buffer + start;
printk("%.*s", (end - start) + 1, buf);
}
void nmi_trigger_all_cpu_backtrace(bool include_self,
void (*raise)(cpumask_t *mask))
{
struct nmi_seq_buf *s;
int i, cpu, this_cpu = get_cpu();
if (test_and_set_bit(0, &backtrace_flag)) {
put_cpu();
return;
}
cpumask_copy(to_cpumask(backtrace_mask), cpu_online_mask);
if (!include_self)
cpumask_clear_cpu(this_cpu, to_cpumask(backtrace_mask));
cpumask_copy(&printtrace_mask, to_cpumask(backtrace_mask));
for_each_cpu(cpu, to_cpumask(backtrace_mask)) {
s = &per_cpu(nmi_print_seq, cpu);
seq_buf_init(&s->seq, s->buffer, NMI_BUF_SIZE);
}
if (!cpumask_empty(to_cpumask(backtrace_mask))) {
pr_info("Sending NMI to %s CPUs:\n",
(include_self ? "all" : "other"));
raise(to_cpumask(backtrace_mask));
}
for (i = 0; i < 10 * 1000; i++) {
if (cpumask_empty(to_cpumask(backtrace_mask)))
break;
mdelay(1);
touch_softlockup_watchdog();
}
for_each_cpu(cpu, &printtrace_mask) {
int len, last_i = 0;
s = &per_cpu(nmi_print_seq, cpu);
len = seq_buf_used(&s->seq);
if (!len)
continue;
for (i = 0; i < len; i++) {
if (s->buffer[i] == '\n') {
print_seq_line(s, last_i, i);
last_i = i + 1;
}
}
if (last_i < len) {
print_seq_line(s, last_i, len - 1);
pr_cont("\n");
}
}
clear_bit(0, &backtrace_flag);
smp_mb__after_atomic();
put_cpu();
}
static int nmi_vprintk(const char *fmt, va_list args)
{
struct nmi_seq_buf *s = this_cpu_ptr(&nmi_print_seq);
unsigned int len = seq_buf_used(&s->seq);
seq_buf_vprintf(&s->seq, fmt, args);
return seq_buf_used(&s->seq) - len;
}
bool nmi_cpu_backtrace(struct pt_regs *regs)
{
int cpu = smp_processor_id();
if (cpumask_test_cpu(cpu, to_cpumask(backtrace_mask))) {
printk_func_t printk_func_save = this_cpu_read(printk_func);
this_cpu_write(printk_func, nmi_vprintk);
pr_warn("NMI backtrace for cpu %d\n", cpu);
if (regs)
show_regs(regs);
else
dump_stack();
this_cpu_write(printk_func, printk_func_save);
cpumask_clear_cpu(cpu, to_cpumask(backtrace_mask));
return true;
}
return false;
}
