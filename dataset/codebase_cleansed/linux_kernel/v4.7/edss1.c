char *strisdnevent(ushort ev)
{
struct isdn_event_desc *entry;
for (entry = isdn_event_table; entry->ev; entry++)
if (entry->ev == ev)
break;
return entry->desc;
}
static void pcbit_fsm_timer(unsigned long data)
{
struct pcbit_dev *dev;
struct pcbit_chan *chan;
chan = (struct pcbit_chan *) data;
del_timer(&chan->fsm_timer);
chan->fsm_timer.function = NULL;
dev = chan2dev(chan);
if (!dev) {
printk(KERN_WARNING "pcbit: timer for unknown device\n");
return;
}
pcbit_fsm_event(dev, chan, EV_TIMER, NULL);
}
void pcbit_fsm_event(struct pcbit_dev *dev, struct pcbit_chan *chan,
unsigned short event, struct callb_data *data)
{
struct fsm_entry *action;
struct fsm_timer_entry *tentry;
unsigned long flags;
spin_lock_irqsave(&dev->lock, flags);
for (action = fsm_table; action->init != 0xff; action++)
if (action->init == chan->fsm_state && action->event == event)
break;
if (action->init == 0xff) {
spin_unlock_irqrestore(&dev->lock, flags);
printk(KERN_DEBUG "fsm error: event %x on state %x\n",
event, chan->fsm_state);
return;
}
if (chan->fsm_timer.function) {
del_timer(&chan->fsm_timer);
chan->fsm_timer.function = NULL;
}
chan->fsm_state = action->final;
pcbit_state_change(dev, chan, action->init, event, action->final);
for (tentry = fsm_timers; tentry->init != 0xff; tentry++)
if (tentry->init == chan->fsm_state)
break;
if (tentry->init != 0xff) {
init_timer(&chan->fsm_timer);
chan->fsm_timer.function = &pcbit_fsm_timer;
chan->fsm_timer.data = (ulong) chan;
chan->fsm_timer.expires = jiffies + tentry->timeout * HZ;
add_timer(&chan->fsm_timer);
}
spin_unlock_irqrestore(&dev->lock, flags);
if (action->callb)
action->callb(dev, chan, data);
}
