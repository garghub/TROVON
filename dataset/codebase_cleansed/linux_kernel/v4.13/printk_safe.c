static void queue_flush_work(struct printk_safe_seq_buf *s)
{
if (printk_safe_irq_ready) {
smp_rmb();
irq_work_queue(&s->work);
}
}
inline void printk_safe_flush_line(const char *text, int len)
{
printk_deferred("%.*s", len, text);
}
static int printk_safe_flush_buffer(const char *start, size_t len)
{
const char *c, *end;
bool header;
c = start;
end = start + len;
header = true;
while (c < end) {
if (*c == '\n') {
printk_safe_flush_line(start, c - start + 1);
start = ++c;
header = true;
continue;
}
if ((c + 1 < end) && printk_get_level(c)) {
if (header) {
c = printk_skip_level(c);
continue;
}
printk_safe_flush_line(start, c - start);
start = c++;
header = true;
continue;
}
header = false;
c++;
}
if (start < end && !header) {
static const char newline[] = KERN_CONT "\n";
printk_safe_flush_line(start, end - start);
printk_safe_flush_line(newline, strlen(newline));
}
return len;
}
static void report_message_lost(struct printk_safe_seq_buf *s)
{
int lost = atomic_xchg(&s->message_lost, 0);
if (lost)
printk_deferred("Lost %d message(s)!\n", lost);
}
static void __printk_safe_flush(struct irq_work *work)
{
static raw_spinlock_t read_lock =
__RAW_SPIN_LOCK_INITIALIZER(read_lock);
struct printk_safe_seq_buf *s =
container_of(work, struct printk_safe_seq_buf, work);
unsigned long flags;
size_t len;
int i;
raw_spin_lock_irqsave(&read_lock, flags);
i = 0;
more:
len = atomic_read(&s->len);
if ((i && i >= len) || len > sizeof(s->buffer)) {
const char *msg = "printk_safe_flush: internal error\n";
printk_safe_flush_line(msg, strlen(msg));
len = 0;
}
if (!len)
goto out;
smp_rmb();
i += printk_safe_flush_buffer(s->buffer + i, len - i);
if (atomic_cmpxchg(&s->len, len, 0) != len)
goto more;
out:
report_message_lost(s);
raw_spin_unlock_irqrestore(&read_lock, flags);
}
void printk_safe_flush(void)
{
int cpu;
for_each_possible_cpu(cpu) {
#ifdef CONFIG_PRINTK_NMI
__printk_safe_flush(&per_cpu(nmi_print_seq, cpu).work);
#endif
__printk_safe_flush(&per_cpu(safe_print_seq, cpu).work);
}
}
void printk_safe_flush_on_panic(void)
{
if (in_nmi() && raw_spin_is_locked(&logbuf_lock)) {
if (num_online_cpus() > 1)
return;
debug_locks_off();
raw_spin_lock_init(&logbuf_lock);
}
printk_safe_flush();
}
void printk_nmi_enter(void)
{
if ((this_cpu_read(printk_context) & PRINTK_SAFE_CONTEXT_MASK) &&
raw_spin_is_locked(&logbuf_lock)) {
this_cpu_or(printk_context, PRINTK_NMI_CONTEXT_MASK);
} else {
this_cpu_or(printk_context, PRINTK_NMI_DEFERRED_CONTEXT_MASK);
}
}
void printk_nmi_exit(void)
{
this_cpu_and(printk_context,
~(PRINTK_NMI_CONTEXT_MASK |
PRINTK_NMI_DEFERRED_CONTEXT_MASK));
}
void __printk_safe_enter(void)
{
this_cpu_inc(printk_context);
}
void __printk_safe_exit(void)
{
this_cpu_dec(printk_context);
}
int vprintk_func(const char *fmt, va_list args)
{
if (this_cpu_read(printk_context) & PRINTK_NMI_CONTEXT_MASK)
return vprintk_nmi(fmt, args);
if (this_cpu_read(printk_context) & PRINTK_SAFE_CONTEXT_MASK)
return vprintk_safe(fmt, args);
if (this_cpu_read(printk_context) & PRINTK_NMI_DEFERRED_CONTEXT_MASK)
return vprintk_deferred(fmt, args);
return vprintk_default(fmt, args);
}
void __init printk_safe_init(void)
{
int cpu;
for_each_possible_cpu(cpu) {
struct printk_safe_seq_buf *s;
s = &per_cpu(safe_print_seq, cpu);
init_irq_work(&s->work, __printk_safe_flush);
#ifdef CONFIG_PRINTK_NMI
s = &per_cpu(nmi_print_seq, cpu);
init_irq_work(&s->work, __printk_safe_flush);
#endif
}
smp_wmb();
printk_safe_irq_ready = 1;
printk_safe_flush();
}
