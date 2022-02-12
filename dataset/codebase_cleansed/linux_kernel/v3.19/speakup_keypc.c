static inline bool synth_writable(void)
{
return (inb_p(synth_port + UART_RX) & 0x10) != 0;
}
static inline bool synth_full(void)
{
return (inb_p(synth_port + UART_RX) & 0x80) == 0;
}
static char *oops(void)
{
int s1, s2, s3, s4;
s1 = inb_p(synth_port);
s2 = inb_p(synth_port+1);
s3 = inb_p(synth_port+2);
s4 = inb_p(synth_port+3);
pr_warn("synth timeout %d %d %d %d\n", s1, s2, s3, s4);
return NULL;
}
static const char *synth_immediate(struct spk_synth *synth, const char *buf)
{
u_char ch;
int timeout;
while ((ch = *buf)) {
if (ch == '\n')
ch = PROCSPEECH;
if (synth_full())
return buf;
timeout = 1000;
while (synth_writable())
if (--timeout <= 0)
return oops();
outb_p(ch, synth_port);
udelay(70);
buf++;
}
return NULL;
}
static void do_catch_up(struct spk_synth *synth)
{
u_char ch;
int timeout;
unsigned long flags;
unsigned long jiff_max;
struct var_t *jiffy_delta;
struct var_t *delay_time;
struct var_t *full_time;
int delay_time_val;
int full_time_val;
int jiffy_delta_val;
jiffy_delta = spk_get_var(JIFFY);
delay_time = spk_get_var(DELAY);
full_time = spk_get_var(FULL);
spin_lock_irqsave(&speakup_info.spinlock, flags);
jiffy_delta_val = jiffy_delta->u.n.value;
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
jiff_max = jiffies + jiffy_delta_val;
while (!kthread_should_stop()) {
spin_lock_irqsave(&speakup_info.spinlock, flags);
if (speakup_info.flushing) {
speakup_info.flushing = 0;
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
synth->flush(synth);
continue;
}
if (synth_buffer_empty()) {
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
break;
}
set_current_state(TASK_INTERRUPTIBLE);
full_time_val = full_time->u.n.value;
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
if (synth_full()) {
schedule_timeout(msecs_to_jiffies(full_time_val));
continue;
}
set_current_state(TASK_RUNNING);
timeout = 1000;
while (synth_writable())
if (--timeout <= 0)
break;
if (timeout <= 0) {
oops();
break;
}
spin_lock_irqsave(&speakup_info.spinlock, flags);
ch = synth_buffer_getc();
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
if (ch == '\n')
ch = PROCSPEECH;
outb_p(ch, synth_port);
SWAIT;
if (time_after_eq(jiffies, jiff_max) && (ch == SPACE)) {
timeout = 1000;
while (synth_writable())
if (--timeout <= 0)
break;
if (timeout <= 0) {
oops();
break;
}
outb_p(PROCSPEECH, synth_port);
spin_lock_irqsave(&speakup_info.spinlock, flags);
jiffy_delta_val = jiffy_delta->u.n.value;
delay_time_val = delay_time->u.n.value;
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
schedule_timeout(msecs_to_jiffies(delay_time_val));
jiff_max = jiffies+jiffy_delta_val;
}
}
timeout = 1000;
while (synth_writable())
if (--timeout <= 0)
break;
if (timeout <= 0)
oops();
else
outb_p(PROCSPEECH, synth_port);
}
static void synth_flush(struct spk_synth *synth)
{
outb_p(SYNTH_CLEAR, synth_port);
}
static int synth_probe(struct spk_synth *synth)
{
unsigned int port_val = 0;
int i = 0;
pr_info("Probing for %s.\n", synth->long_name);
if (port_forced) {
synth_port = port_forced;
pr_info("probe forced to %x by kernel command line\n",
synth_port);
if (synth_request_region(synth_port-1, SYNTH_IO_EXTENT)) {
pr_warn("sorry, port already reserved\n");
return -EBUSY;
}
port_val = inb(synth_port);
} else {
for (i = 0; synth_portlist[i]; i++) {
if (synth_request_region(synth_portlist[i],
SYNTH_IO_EXTENT)) {
pr_warn
("request_region: failed with 0x%x, %d\n",
synth_portlist[i], SYNTH_IO_EXTENT);
continue;
}
port_val = inb(synth_portlist[i]);
if (port_val == 0x80) {
synth_port = synth_portlist[i];
break;
}
}
}
if (port_val != 0x80) {
pr_info("%s: not found\n", synth->long_name);
synth_release_region(synth_port, SYNTH_IO_EXTENT);
synth_port = 0;
return -ENODEV;
}
pr_info("%s: %03x-%03x, driver version %s,\n", synth->long_name,
synth_port, synth_port+SYNTH_IO_EXTENT-1,
synth->version);
synth->alive = 1;
return 0;
}
static void keynote_release(void)
{
if (synth_port)
synth_release_region(synth_port, SYNTH_IO_EXTENT);
synth_port = 0;
}
static int __init keypc_init(void)
{
return synth_add(&synth_keypc);
}
static void __exit keypc_exit(void)
{
synth_remove(&synth_keypc);
}
