static int dt_getstatus(void)
{
dt_stat = inb_p(speakup_info.port_tts) |
(inb_p(speakup_info.port_tts + 1) << 8);
return dt_stat;
}
static void dt_sendcmd(u_int cmd)
{
outb_p(cmd & 0xFF, speakup_info.port_tts);
outb_p((cmd >> 8) & 0xFF, speakup_info.port_tts+1);
}
static int dt_waitbit(int bit)
{
int timeout = 100;
while (--timeout > 0) {
if ((dt_getstatus() & bit) == bit)
return 1;
udelay(50);
}
return 0;
}
static int dt_wait_dma(void)
{
int timeout = 100, state = dma_state;
if (!dt_waitbit(STAT_dma_ready))
return 0;
while (--timeout > 0) {
if ((dt_getstatus()&STAT_dma_state) == state)
return 1;
udelay(50);
}
dma_state = dt_getstatus() & STAT_dma_state;
return 1;
}
static int dt_ctrl(u_int cmd)
{
int timeout = 10;
if (!dt_waitbit(STAT_cmd_ready))
return -1;
outb_p(0, speakup_info.port_tts+2);
outb_p(0, speakup_info.port_tts+3);
dt_getstatus();
dt_sendcmd(CMD_control|cmd);
outb_p(0, speakup_info.port_tts+6);
while (dt_getstatus() & STAT_cmd_ready) {
udelay(20);
if (--timeout == 0)
break;
}
dt_sendcmd(CMD_null);
return 0;
}
static void synth_flush(struct spk_synth *synth)
{
int timeout = 10;
if (is_flushing)
return;
is_flushing = 4;
in_escape = 0;
while (dt_ctrl(CTRL_flush)) {
if (--timeout == 0)
break;
udelay(50);
}
for (timeout = 0; timeout < 10; timeout++) {
if (dt_waitbit(STAT_dma_ready))
break;
udelay(50);
}
outb_p(DMA_sync, speakup_info.port_tts+4);
outb_p(0, speakup_info.port_tts+4);
udelay(100);
for (timeout = 0; timeout < 10; timeout++) {
if (!(dt_getstatus() & STAT_flushing))
break;
udelay(50);
}
dma_state = dt_getstatus() & STAT_dma_state;
dma_state ^= STAT_dma_state;
is_flushing = 0;
}
static int dt_sendchar(char ch)
{
if (!dt_wait_dma())
return -1;
if (!(dt_stat & STAT_rr_char))
return -2;
outb_p(DMA_single_in, speakup_info.port_tts+4);
outb_p(ch, speakup_info.port_tts+4);
dma_state ^= STAT_dma_state;
return 0;
}
static int testkernel(void)
{
int status = 0;
if (dt_getstatus() == 0xffff) {
status = -1;
goto oops;
}
dt_sendcmd(CMD_sync);
if (!dt_waitbit(STAT_cmd_ready))
status = -2;
else if (dt_stat&0x8000)
return 0;
else if (dt_stat == 0x0dec)
pr_warn("dec_pc at 0x%x, software not loaded\n",
speakup_info.port_tts);
status = -3;
oops: synth_release_region(speakup_info.port_tts, SYNTH_IO_EXTENT);
speakup_info.port_tts = 0;
return status;
}
static void do_catch_up(struct spk_synth *synth)
{
u_char ch;
static u_char last;
unsigned long flags;
unsigned long jiff_max;
struct var_t *jiffy_delta;
struct var_t *delay_time;
int jiffy_delta_val;
int delay_time_val;
jiffy_delta = get_var(JIFFY);
delay_time = get_var(DELAY);
spk_lock(flags);
jiffy_delta_val = jiffy_delta->u.n.value;
spk_unlock(flags);
jiff_max = jiffies + jiffy_delta_val;
while (!kthread_should_stop()) {
spk_lock(flags);
if (speakup_info.flushing) {
speakup_info.flushing = 0;
spk_unlock(flags);
synth->flush(synth);
continue;
}
if (synth_buffer_empty()) {
spk_unlock(flags);
break;
}
ch = synth_buffer_peek();
set_current_state(TASK_INTERRUPTIBLE);
delay_time_val = delay_time->u.n.value;
spk_unlock(flags);
if (ch == '\n')
ch = 0x0D;
if (dt_sendchar(ch)) {
schedule_timeout(msecs_to_jiffies(delay_time_val));
continue;
}
set_current_state(TASK_RUNNING);
spk_lock(flags);
synth_buffer_getc();
spk_unlock(flags);
if (ch == '[')
in_escape = 1;
else if (ch == ']')
in_escape = 0;
else if (ch <= SPACE) {
if (!in_escape && strchr(",.!?;:", last))
dt_sendchar(PROCSPEECH);
if (jiffies >= jiff_max) {
if (!in_escape)
dt_sendchar(PROCSPEECH);
spk_lock(flags);
jiffy_delta_val = jiffy_delta->u.n.value;
delay_time_val = delay_time->u.n.value;
spk_unlock(flags);
schedule_timeout(msecs_to_jiffies
(delay_time_val));
jiff_max = jiffies + jiffy_delta_val;
}
}
last = ch;
ch = 0;
}
if (!in_escape)
dt_sendchar(PROCSPEECH);
}
static const char *synth_immediate(struct spk_synth *synth, const char *buf)
{
u_char ch;
while ((ch = *buf)) {
if (ch == '\n')
ch = PROCSPEECH;
if (dt_sendchar(ch))
return buf;
buf++;
}
return 0;
}
static int synth_probe(struct spk_synth *synth)
{
int i = 0, failed = 0;
pr_info("Probing for %s.\n", synth->long_name);
for (i = 0; synth_portlist[i]; i++) {
if (synth_request_region(synth_portlist[i], SYNTH_IO_EXTENT)) {
pr_warn("request_region: failed with 0x%x, %d\n",
synth_portlist[i], SYNTH_IO_EXTENT);
continue;
}
speakup_info.port_tts = synth_portlist[i];
failed = testkernel();
if (failed == 0)
break;
}
if (failed) {
pr_info("%s: not found\n", synth->long_name);
return -ENODEV;
}
pr_info("%s: %03x-%03x, Driver Version %s,\n", synth->long_name,
speakup_info.port_tts, speakup_info.port_tts + 7,
synth->version);
synth->alive = 1;
return 0;
}
static void dtpc_release(void)
{
if (speakup_info.port_tts)
synth_release_region(speakup_info.port_tts, SYNTH_IO_EXTENT);
speakup_info.port_tts = 0;
}
static int __init decpc_init(void)
{
return synth_add(&synth_dec_pc);
}
static void __exit decpc_exit(void)
{
synth_remove(&synth_dec_pc);
}
