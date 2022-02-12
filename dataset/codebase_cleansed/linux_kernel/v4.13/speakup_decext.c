static void read_buff_add(u_char ch)
{
last_char = ch;
}
static inline bool synth_full(void)
{
return last_char == 0x13;
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
synth_buffer_skip_nonlatin1();
if (synth_buffer_empty()) {
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
break;
}
ch = synth_buffer_peek();
set_current_state(TASK_INTERRUPTIBLE);
delay_time_val = delay_time->u.n.value;
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
if (ch == '\n')
ch = 0x0D;
if (synth_full() || !synth->io_ops->synth_out(synth, ch)) {
schedule_timeout(msecs_to_jiffies(delay_time_val));
continue;
}
set_current_state(TASK_RUNNING);
spin_lock_irqsave(&speakup_info.spinlock, flags);
synth_buffer_getc();
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
if (ch == '[') {
in_escape = 1;
} else if (ch == ']') {
in_escape = 0;
} else if (ch <= SPACE) {
if (!in_escape && strchr(",.!?;:", last))
synth->io_ops->synth_out(synth, PROCSPEECH);
if (time_after_eq(jiffies, jiff_max)) {
if (!in_escape)
synth->io_ops->synth_out(synth, PROCSPEECH);
spin_lock_irqsave(&speakup_info.spinlock,
flags);
jiffy_delta_val = jiffy_delta->u.n.value;
delay_time_val = delay_time->u.n.value;
spin_unlock_irqrestore(&speakup_info.spinlock,
flags);
schedule_timeout(msecs_to_jiffies
(delay_time_val));
jiff_max = jiffies + jiffy_delta_val;
}
}
last = ch;
}
if (!in_escape)
synth->io_ops->synth_out(synth, PROCSPEECH);
}
static void synth_flush(struct spk_synth *synth)
{
in_escape = 0;
synth->io_ops->flush_buffer();
synth->synth_immediate(synth, "\033P;10z\033\\");
}
