static inline bool synth_writable(void)
{
return inb_p(synth_port_control) & SYNTH_WRITABLE;
}
static inline bool synth_full(void)
{
return inb_p(speakup_info.port_tts + UART_RX) == 'F';
}
static const char *synth_immediate(struct spk_synth *synth, const char *buf)
{
u_char ch;
while ((ch = *buf)) {
int timeout = SPK_XMITR_TIMEOUT;
if (ch == '\n')
ch = PROCSPEECH;
if (synth_full())
return buf;
while (synth_writable()) {
if (!--timeout)
return buf;
udelay(1);
}
outb_p(ch, speakup_info.port_tts);
buf++;
}
return NULL;
}
static void do_catch_up(struct spk_synth *synth)
{
u_char ch;
unsigned long flags;
unsigned long jiff_max;
int timeout;
int delay_time_val;
int jiffy_delta_val;
int full_time_val;
struct var_t *delay_time;
struct var_t *full_time;
struct var_t *jiffy_delta;
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
timeout = SPK_XMITR_TIMEOUT;
while (synth_writable()) {
if (!--timeout)
break;
udelay(1);
}
spin_lock_irqsave(&speakup_info.spinlock, flags);
ch = synth_buffer_getc();
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
if (ch == '\n')
ch = PROCSPEECH;
outb_p(ch, speakup_info.port_tts);
if (time_after_eq(jiffies, jiff_max) && ch == SPACE) {
timeout = SPK_XMITR_TIMEOUT;
while (synth_writable()) {
if (!--timeout)
break;
udelay(1);
}
outb_p(PROCSPEECH, speakup_info.port_tts);
spin_lock_irqsave(&speakup_info.spinlock, flags);
jiffy_delta_val = jiffy_delta->u.n.value;
delay_time_val = delay_time->u.n.value;
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
schedule_timeout(msecs_to_jiffies(delay_time_val));
jiff_max = jiffies+jiffy_delta_val;
}
}
timeout = SPK_XMITR_TIMEOUT;
while (synth_writable()) {
if (!--timeout)
break;
udelay(1);
}
outb_p(PROCSPEECH, speakup_info.port_tts);
}
static void synth_flush(struct spk_synth *synth)
{
outb_p(SYNTH_CLEAR, speakup_info.port_tts);
}
static int synth_probe(struct spk_synth *synth)
{
unsigned int port_val = 0;
int i = 0;
pr_info("Probing for %s.\n", synth->long_name);
if (port_forced) {
speakup_info.port_tts = port_forced;
pr_info("probe forced to %x by kernel command line\n",
speakup_info.port_tts);
if (synth_request_region(speakup_info.port_tts-1,
SYNTH_IO_EXTENT)) {
pr_warn("sorry, port already reserved\n");
return -EBUSY;
}
port_val = inw(speakup_info.port_tts-1);
synth_port_control = speakup_info.port_tts-1;
} else {
for (i = 0; synth_portlist[i]; i++) {
if (synth_request_region(synth_portlist[i],
SYNTH_IO_EXTENT)) {
pr_warn
("request_region: failed with 0x%x, %d\n",
synth_portlist[i], SYNTH_IO_EXTENT);
continue;
}
port_val = inw(synth_portlist[i]) & 0xfffc;
if (port_val == 0x53fc) {
synth_port_control = synth_portlist[i];
speakup_info.port_tts = synth_port_control+1;
break;
}
}
}
port_val &= 0xfffc;
if (port_val != 0x53fc) {
pr_info("%s: not found\n", synth->long_name);
synth_release_region(synth_port_control, SYNTH_IO_EXTENT);
synth_port_control = 0;
return -ENODEV;
}
pr_info("%s: %03x-%03x, driver version %s,\n", synth->long_name,
synth_port_control, synth_port_control+SYNTH_IO_EXTENT-1,
synth->version);
synth->alive = 1;
return 0;
}
static void accent_release(void)
{
if (speakup_info.port_tts)
synth_release_region(speakup_info.port_tts-1, SYNTH_IO_EXTENT);
speakup_info.port_tts = 0;
}
static int __init acntpc_init(void)
{
return synth_add(&synth_acntpc);
}
static void __exit acntpc_exit(void)
{
synth_remove(&synth_acntpc);
}
