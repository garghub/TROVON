static inline bool synth_readable(void)
{
synth_status = inb_p(speakup_info.port_tts + UART_RX);
return (synth_status & TTS_READABLE) != 0;
}
static inline bool synth_writable(void)
{
synth_status = inb_p(speakup_info.port_tts + UART_RX);
return (synth_status & TTS_WRITABLE) != 0;
}
static inline bool synth_full(void)
{
synth_status = inb_p(speakup_info.port_tts + UART_RX);
return (synth_status & TTS_ALMOST_FULL) != 0;
}
static void spk_out(const char ch)
{
int timeout = SPK_XMITR_TIMEOUT;
while (!synth_writable()) {
if (!--timeout)
break;
udelay(1);
}
outb_p(ch, speakup_info.port_tts);
timeout = SPK_XMITR_TIMEOUT;
while (synth_writable()) {
if (!--timeout)
break;
udelay(1);
}
}
static void do_catch_up(struct spk_synth *synth)
{
u_char ch;
unsigned long flags;
unsigned long jiff_max;
struct var_t *jiffy_delta;
struct var_t *delay_time;
int jiffy_delta_val;
int delay_time_val;
jiffy_delta = spk_get_var(JIFFY);
delay_time = spk_get_var(DELAY);
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
delay_time_val = delay_time->u.n.value;
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
if (synth_full()) {
schedule_timeout(msecs_to_jiffies(delay_time_val));
continue;
}
set_current_state(TASK_RUNNING);
spin_lock_irqsave(&speakup_info.spinlock, flags);
ch = synth_buffer_getc();
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
if (ch == '\n')
ch = PROCSPEECH;
spk_out(ch);
if (time_after_eq(jiffies, jiff_max) && (ch == SPACE)) {
spk_out(PROCSPEECH);
spin_lock_irqsave(&speakup_info.spinlock, flags);
delay_time_val = delay_time->u.n.value;
jiffy_delta_val = jiffy_delta->u.n.value;
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
schedule_timeout(msecs_to_jiffies(delay_time_val));
jiff_max = jiffies + jiffy_delta_val;
}
}
spk_out(PROCSPEECH);
}
static const char *synth_immediate(struct spk_synth *synth, const char *buf)
{
u_char ch;
while ((ch = (u_char)*buf)) {
if (synth_full())
return buf;
if (ch == '\n')
ch = PROCSPEECH;
spk_out(ch);
buf++;
}
return NULL;
}
static void synth_flush(struct spk_synth *synth)
{
outb_p(SYNTH_CLEAR, speakup_info.port_tts);
while (synth_writable())
cpu_relax();
}
static char synth_read_tts(void)
{
u_char ch;
while (!synth_readable())
cpu_relax();
ch = synth_status & 0x7f;
outb_p(ch, speakup_info.port_tts);
while (synth_readable())
cpu_relax();
return (char) ch;
}
static struct synth_settings *synth_interrogate(struct spk_synth *synth)
{
u_char *t;
static char buf[sizeof(struct synth_settings) + 1];
int total, i;
static struct synth_settings status;
synth_immediate(synth, "\x18\x01?");
for (total = 0, i = 0; i < 50; i++) {
buf[total] = synth_read_tts();
if (total > 2 && buf[total] == 0x7f)
break;
if (total < sizeof(struct synth_settings))
total++;
}
t = buf;
status.serial_number = t[0] + t[1]*256;
t += 2;
for (i = 0; *t != '\r'; t++) {
status.rom_version[i] = *t;
if (i < sizeof(status.rom_version)-1)
i++;
}
status.rom_version[i] = 0;
t++;
status.mode = *t++;
status.punc_level = *t++;
status.formant_freq = *t++;
status.pitch = *t++;
status.speed = *t++;
status.volume = *t++;
status.tone = *t++;
status.expression = *t++;
status.ext_dict_loaded = *t++;
status.ext_dict_status = *t++;
status.free_ram = *t++;
status.articulation = *t++;
status.reverb = *t++;
status.eob = *t++;
return &status;
}
static int synth_probe(struct spk_synth *synth)
{
unsigned int port_val = 0;
int i = 0;
struct synth_settings *sp;
pr_info("Probing for DoubleTalk.\n");
if (port_forced) {
speakup_info.port_tts = port_forced;
pr_info("probe forced to %x by kernel command line\n",
speakup_info.port_tts);
if ((port_forced & 0xf) != 0xf)
pr_info("warning: port base should probably end with f\n");
if (synth_request_region(speakup_info.port_tts-1,
SYNTH_IO_EXTENT)) {
pr_warn("sorry, port already reserved\n");
return -EBUSY;
}
port_val = inw(speakup_info.port_tts-1);
synth_lpc = speakup_info.port_tts-1;
} else {
for (i = 0; synth_portlist[i]; i++) {
if (synth_request_region(synth_portlist[i],
SYNTH_IO_EXTENT))
continue;
port_val = inw(synth_portlist[i]) & 0xfbff;
if (port_val == 0x107f) {
synth_lpc = synth_portlist[i];
speakup_info.port_tts = synth_lpc+1;
break;
}
synth_release_region(synth_portlist[i],
SYNTH_IO_EXTENT);
}
}
port_val &= 0xfbff;
if (port_val != 0x107f) {
pr_info("DoubleTalk PC: not found\n");
if (synth_lpc)
synth_release_region(synth_lpc, SYNTH_IO_EXTENT);
return -ENODEV;
}
while (inw_p(synth_lpc) != 0x147f)
cpu_relax();
sp = synth_interrogate(synth);
pr_info("%s: %03x-%03x, ROM ver %s, s/n %u, driver: %s\n",
synth->long_name, synth_lpc, synth_lpc+SYNTH_IO_EXTENT - 1,
sp->rom_version, sp->serial_number, synth->version);
synth->alive = 1;
return 0;
}
static void dtlk_release(void)
{
if (speakup_info.port_tts)
synth_release_region(speakup_info.port_tts-1, SYNTH_IO_EXTENT);
speakup_info.port_tts = 0;
}
static int __init dtlk_init(void)
{
return synth_add(&synth_dtlk);
}
static void __exit dtlk_exit(void)
{
synth_remove(&synth_dtlk);
}
