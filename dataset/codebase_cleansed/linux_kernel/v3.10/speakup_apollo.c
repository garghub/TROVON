static void do_catch_up(struct spk_synth *synth)
{
u_char ch;
unsigned long flags;
unsigned long jiff_max;
struct var_t *jiffy_delta;
struct var_t *delay_time;
struct var_t *full_time;
int full_time_val = 0;
int delay_time_val = 0;
int jiffy_delta_val = 0;
jiffy_delta = spk_get_var(JIFFY);
delay_time = spk_get_var(DELAY);
full_time = spk_get_var(FULL);
spk_lock(flags);
jiffy_delta_val = jiffy_delta->u.n.value;
spk_unlock(flags);
jiff_max = jiffies + jiffy_delta_val;
while (!kthread_should_stop()) {
spk_lock(flags);
jiffy_delta_val = jiffy_delta->u.n.value;
full_time_val = full_time->u.n.value;
delay_time_val = delay_time->u.n.value;
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
full_time_val = full_time->u.n.value;
spk_unlock(flags);
if (!spk_serial_out(ch)) {
outb(UART_MCR_DTR, speakup_info.port_tts + UART_MCR);
outb(UART_MCR_DTR | UART_MCR_RTS,
speakup_info.port_tts + UART_MCR);
schedule_timeout(msecs_to_jiffies(full_time_val));
continue;
}
if ((jiffies >= jiff_max) && (ch == SPACE)) {
spk_lock(flags);
jiffy_delta_val = jiffy_delta->u.n.value;
full_time_val = full_time->u.n.value;
delay_time_val = delay_time->u.n.value;
spk_unlock(flags);
if (spk_serial_out(synth->procspeech))
schedule_timeout(msecs_to_jiffies
(delay_time_val));
else
schedule_timeout(msecs_to_jiffies
(full_time_val));
jiff_max = jiffies + jiffy_delta_val;
}
set_current_state(TASK_RUNNING);
spk_lock(flags);
synth_buffer_getc();
spk_unlock(flags);
}
spk_serial_out(PROCSPEECH);
}
static int __init apollo_init(void)
{
return synth_add(&synth_apollo);
}
static void __exit apollo_exit(void)
{
synth_remove(&synth_apollo);
}
