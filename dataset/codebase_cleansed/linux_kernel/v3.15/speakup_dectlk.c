static inline int synth_full(void)
{
return xoff;
}
static int is_indnum(u_char *ch)
{
if ((*ch >= '0') && (*ch <= '9')) {
*ch = *ch - '0';
return 1;
}
return 0;
}
static unsigned char get_index(void)
{
u_char rv;
rv = lastind;
lastind = 0;
return rv;
}
static void read_buff_add(u_char c)
{
static int ind = -1;
if (c == 0x01) {
unsigned long flags;
spin_lock_irqsave(&flush_lock, flags);
is_flushing = 0;
wake_up_interruptible(&flush);
spin_unlock_irqrestore(&flush_lock, flags);
} else if (c == 0x13) {
xoff = 1;
} else if (c == 0x11) {
xoff = 0;
} else if (is_indnum(&c)) {
if (ind == -1)
ind = c;
else
ind = ind * 10 + c;
} else if ((c > 31) && (c < 127)) {
if (ind != -1)
lastind = (u_char)ind;
ind = -1;
}
}
static void do_catch_up(struct spk_synth *synth)
{
int synth_full_val = 0;
static u_char ch;
static u_char last = '\0';
unsigned long flags;
unsigned long jiff_max;
unsigned long timeout = msecs_to_jiffies(4000);
DEFINE_WAIT(wait);
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
spin_lock_irqsave(&flush_lock, flags);
while (is_flushing && timeout) {
prepare_to_wait(&flush, &wait, TASK_INTERRUPTIBLE);
spin_unlock_irqrestore(&flush_lock, flags);
timeout = schedule_timeout(timeout);
spin_lock_irqsave(&flush_lock, flags);
}
finish_wait(&flush, &wait);
is_flushing = 0;
spin_unlock_irqrestore(&flush_lock, flags);
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
ch = synth_buffer_peek();
set_current_state(TASK_INTERRUPTIBLE);
delay_time_val = delay_time->u.n.value;
synth_full_val = synth_full();
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
if (ch == '\n')
ch = 0x0D;
if (synth_full_val || !spk_serial_out(ch)) {
schedule_timeout(msecs_to_jiffies(delay_time_val));
continue;
}
set_current_state(TASK_RUNNING);
spin_lock_irqsave(&speakup_info.spinlock, flags);
synth_buffer_getc();
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
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
spk_serial_out(PROCSPEECH);
}
static void synth_flush(struct spk_synth *synth)
{
if (in_escape) {
spk_serial_out(']');
}
in_escape = 0;
is_flushing = 1;
spk_serial_out(SYNTH_CLEAR);
}
static int __init dectlk_init(void)
{
return synth_add(&synth_dectlk);
}
static void __exit dectlk_exit(void)
{
synth_remove(&synth_dectlk);
}
