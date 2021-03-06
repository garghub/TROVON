static unsigned long tmr2ticks(int tmr_value)
{
unsigned long tmp;
unsigned long scale;
tmp = tmr_value * usecs_per_tmr;
scale = (60 * 1000000) / (curr_tempo * curr_timebase);
return (tmp + (scale / 2)) / scale;
}
void reprogram_timer(void)
{
unsigned long usecs_per_tick;
if(!tmr)
return;
usecs_per_tick = (60 * 1000000) / (curr_tempo * curr_timebase);
if (usecs_per_tick < 2000)
usecs_per_tick = 2000;
usecs_per_tmr = tmr->tmr_start(tmr->dev, usecs_per_tick);
}
void sound_timer_syncinterval(unsigned int new_usecs)
{
tmr_offs = tmr_ctr;
ticks_offs += tmr2ticks(tmr_ctr);
tmr_ctr = 0;
usecs_per_tmr = new_usecs;
}
static void tmr_reset(void)
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
static int timer_open(int dev, int mode)
{
if (opened)
return -EBUSY;
tmr_reset();
curr_tempo = 60;
curr_timebase = 100;
opened = 1;
reprogram_timer();
return 0;
}
static void timer_close(int dev)
{
opened = tmr_running = 0;
tmr->tmr_disable(tmr->dev);
}
static int timer_event(int dev, unsigned char *event)
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
reprogram_timer();
break;
case TMR_STOP:
tmr_running = 0;
break;
case TMR_CONTINUE:
tmr_running = 1;
reprogram_timer();
break;
case TMR_TEMPO:
if (parm)
{
if (parm < 8)
parm = 8;
if (parm > 250)
parm = 250;
tmr_offs = tmr_ctr;
ticks_offs += tmr2ticks(tmr_ctr);
tmr_ctr = 0;
curr_tempo = parm;
reprogram_timer();
}
break;
case TMR_ECHO:
seq_copy_to_input(event, 8);
break;
default:;
}
return TIMER_NOT_ARMED;
}
static unsigned long timer_get_time(int dev)
{
if (!opened)
return 0;
return curr_ticks;
}
static int timer_ioctl(int dev, unsigned int cmd, void __user *arg)
{
int __user *p = arg;
int val;
switch (cmd)
{
case SNDCTL_TMR_SOURCE:
val = TMR_INTERNAL;
break;
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
if (get_user(val, p))
return -EFAULT;
if (val)
{
if (val < 1)
val = 1;
if (val > 1000)
val = 1000;
curr_timebase = val;
}
val = curr_timebase;
break;
case SNDCTL_TMR_TEMPO:
if (get_user(val, p))
return -EFAULT;
if (val)
{
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
val = curr_tempo;
break;
case SNDCTL_SEQ_CTRLRATE:
if (get_user(val, p))
return -EFAULT;
if (val != 0)
return -EINVAL;
val = ((curr_tempo * curr_timebase) + 30) / 60;
break;
case SNDCTL_SEQ_GETTIME:
val = curr_ticks;
break;
case SNDCTL_TMR_METRONOME:
default:
return -EINVAL;
}
return put_user(val, p);
}
static void timer_arm(int dev, long time)
{
if (time < 0)
time = curr_ticks + 1;
else if (time <= curr_ticks)
return;
next_event_time = prev_event_time = time;
return;
}
void sound_timer_interrupt(void)
{
unsigned long flags;
if (!opened)
return;
tmr->tmr_restart(tmr->dev);
if (!tmr_running)
return;
spin_lock_irqsave(&lock,flags);
tmr_ctr++;
curr_ticks = ticks_offs + tmr2ticks(tmr_ctr);
if (curr_ticks >= next_event_time)
{
next_event_time = (unsigned long) -1;
sequencer_timer(0);
}
spin_unlock_irqrestore(&lock,flags);
}
void sound_timer_init(struct sound_lowlev_timer *t, char *name)
{
int n;
if (initialized)
{
if (t->priority <= tmr->priority)
return;
tmr = t;
return;
}
initialized = 1;
tmr = t;
n = sound_alloc_timerdev();
if (n == -1)
n = 0;
strlcpy(sound_timer.info.name, name, sizeof(sound_timer.info.name));
sound_timer_devs[n] = &sound_timer;
}
