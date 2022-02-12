static inline u_char get_last_char(void)
{
u_char avail = inb_p(speakup_info.port_tts + UART_LSR) & UART_LSR_DR;
if (avail)
last_char = inb_p(speakup_info.port_tts + UART_RX);
return last_char;
}
static inline bool synth_full(void)
{
return get_last_char() == 0x13;
}
static void do_catch_up(struct spk_synth *synth)
{
u_char ch;
static u_char last = '\0';
unsigned long flags;
unsigned long jiff_max;
struct var_t *jiffy_delta;
struct var_t *delay_time;
int jiffy_delta_val = 0;
int delay_time_val = 0;
jiffy_delta = spk_get_var(JIFFY);
delay_time = spk_get_var(DELAY);
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
if (synth_full() || !spk_serial_out(ch)) {
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
spk_serial_out(PROCSPEECH);
if (jiffies >= jiff_max) {
if (!in_escape)
spk_serial_out(PROCSPEECH);
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
}
if (!in_escape)
spk_serial_out(PROCSPEECH);
}
static void synth_flush(struct spk_synth *synth)
{
in_escape = 0;
spk_synth_immediate(synth, "\033P;10z\033\\");
}
static int __init decext_init(void)
{
return synth_add(&synth_decext);
}
static void __exit decext_exit(void)
{
synth_remove(&synth_decext);
}
