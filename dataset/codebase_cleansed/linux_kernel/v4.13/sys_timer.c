static unsigned long
tmr2ticks(int tmr_value)
{
unsigned long tmp;
unsigned long scale;
tmp = tmr_value * (1000000 / HZ);
scale = (60 * 1000000) / (curr_tempo * curr_timebase);
return (tmp + scale / 2) / scale;
}
static void
poll_def_tmr(unsigned long dummy)
{
if (!opened)
return;
def_tmr.expires = (1) + jiffies;
add_timer(&def_tmr);
if (!tmr_running)
return;
spin_lock(&lock);
tmr_ctr++;
curr_ticks = ticks_offs + tmr2ticks(tmr_ctr);
if (curr_ticks >= next_event_time) {
next_event_time = (unsigned long) -1;
sequencer_timer(0);
}
spin_unlock(&lock);
}
static void
tmr_reset(void)
{
unsigned long flags;
spin_lock_irqsave(&lock,flags);
tmr_offs = 0;
ticks_offs = 0;
tmr_ctr = 0;
next_event_time = (unsigned long) -1;
prev_event_time = 0;
curr_ticks = 0;
spin_unlock_irqrestore(&lock,flags);
}
static int
def_tmr_open(int dev, int mode)
{
if (opened)
return -EBUSY;
tmr_reset();
curr_tempo = 60;
curr_timebase = 100;
opened = 1;
{
def_tmr.expires = (1) + jiffies;
add_timer(&def_tmr);
}
return 0;
}
static void
def_tmr_close(int dev)
{
opened = tmr_running = 0;
del_timer(&def_tmr);
}
static int
def_tmr_event(int dev, unsigned char *event)
{
unsigned char cmd = event[1];
unsigned long parm = *(int *) &event[4];
switch (cmd)
{
case TMR_WAIT_REL:
parm += prev_event_time;
case TMR_WAIT_ABS:
if (parm > 0)
{
long time;
if (parm <= curr_ticks)
return TIMER_NOT_ARMED;
time = parm;
next_event_time = prev_event_time = time;
return TIMER_ARMED;
}
break;
case TMR_START:
tmr_reset();
tmr_running = 1;
break;
case TMR_STOP:
tmr_running = 0;
break;
case TMR_CONTINUE:
tmr_running = 1;
break;
case TMR_TEMPO:
if (parm)
{
if (parm < 8)
parm = 8;
if (parm > 360)
parm = 360;
tmr_offs = tmr_ctr;
ticks_offs += tmr2ticks(tmr_ctr);
tmr_ctr = 0;
curr_tempo = parm;
}
break;
case TMR_ECHO:
seq_copy_to_input(event, 8);
break;
default:;
}
return TIMER_NOT_ARMED;
}
static unsigned long
def_tmr_get_time(int dev)
{
if (!opened)
return 0;
return curr_ticks;
}
static int def_tmr_ioctl(int dev, unsigned int cmd, void __user *arg)
{
int __user *p = arg;
int val;
switch (cmd) {
case SNDCTL_TMR_SOURCE:
return __put_user(TMR_INTERNAL, p);
case SNDCTL_TMR_START:
tmr_reset();
tmr_running = 1;
return 0;
case SNDCTL_TMR_STOP:
tmr_running = 0;
return 0;
case SNDCTL_TMR_CONTINUE:
tmr_running = 1;
return 0;
case SNDCTL_TMR_TIMEBASE:
if (__get_user(val, p))
return -EFAULT;
if (val) {
if (val < 1)
val = 1;
if (val > 1000)
val = 1000;
curr_timebase = val;
}
return __put_user(curr_timebase, p);
case SNDCTL_TMR_TEMPO:
if (__get_user(val, p))
return -EFAULT;
if (val) {
if (val < 8)
val = 8;
if (val > 250)
val = 250;
tmr_offs = tmr_ctr;
ticks_offs += tmr2ticks(tmr_ctr);
tmr_ctr = 0;
curr_tempo = val;
reprogram_timer();
}
return __put_user(curr_tempo, p);
case SNDCTL_SEQ_CTRLRATE:
if (__get_user(val, p))
return -EFAULT;
if (val != 0)
return -EINVAL;
val = ((curr_tempo * curr_timebase) + 30) / 60;
return __put_user(val, p);
case SNDCTL_SEQ_GETTIME:
return __put_user(curr_ticks, p);
case SNDCTL_TMR_METRONOME:
break;
default:;
}
return -EINVAL;
}
static void
def_tmr_arm(int dev, long time)
{
if (time < 0)
time = curr_ticks + 1;
else if (time <= curr_ticks)
return;
next_event_time = prev_event_time = time;
return;
}
