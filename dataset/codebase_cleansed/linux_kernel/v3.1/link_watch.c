static unsigned char default_operstate(const struct net_device *dev)
{
if (!netif_carrier_ok(dev))
return (dev->ifindex != dev->iflink ?
IF_OPER_LOWERLAYERDOWN : IF_OPER_DOWN);
if (netif_dormant(dev))
return IF_OPER_DORMANT;
return IF_OPER_UP;
}
static void rfc2863_policy(struct net_device *dev)
{
unsigned char operstate = default_operstate(dev);
if (operstate == dev->operstate)
return;
write_lock_bh(&dev_base_lock);
switch(dev->link_mode) {
case IF_LINK_MODE_DORMANT:
if (operstate == IF_OPER_UP)
operstate = IF_OPER_DORMANT;
break;
case IF_LINK_MODE_DEFAULT:
default:
break;
}
dev->operstate = operstate;
write_unlock_bh(&dev_base_lock);
}
static bool linkwatch_urgent_event(struct net_device *dev)
{
return netif_running(dev) && netif_carrier_ok(dev) &&
qdisc_tx_changing(dev);
}
static void linkwatch_add_event(struct net_device *dev)
{
unsigned long flags;
spin_lock_irqsave(&lweventlist_lock, flags);
if (list_empty(&dev->link_watch_list)) {
list_add_tail(&dev->link_watch_list, &lweventlist);
dev_hold(dev);
}
spin_unlock_irqrestore(&lweventlist_lock, flags);
}
static void linkwatch_schedule_work(int urgent)
{
unsigned long delay = linkwatch_nextevent - jiffies;
if (test_bit(LW_URGENT, &linkwatch_flags))
return;
if (urgent) {
if (test_and_set_bit(LW_URGENT, &linkwatch_flags))
return;
delay = 0;
}
if (delay > HZ)
delay = 0;
if (schedule_delayed_work(&linkwatch_work, delay) == !delay)
return;
if (!test_bit(LW_URGENT, &linkwatch_flags))
return;
if (!__cancel_delayed_work(&linkwatch_work))
return;
schedule_delayed_work(&linkwatch_work, 0);
}
static void linkwatch_do_dev(struct net_device *dev)
{
smp_mb__before_clear_bit();
clear_bit(__LINK_STATE_LINKWATCH_PENDING, &dev->state);
rfc2863_policy(dev);
if (dev->flags & IFF_UP) {
if (netif_carrier_ok(dev))
dev_activate(dev);
else
dev_deactivate(dev);
netdev_state_change(dev);
}
dev_put(dev);
}
static void __linkwatch_run_queue(int urgent_only)
{
struct net_device *dev;
LIST_HEAD(wrk);
if (!urgent_only)
linkwatch_nextevent = jiffies + HZ;
else if (time_after(linkwatch_nextevent, jiffies + HZ))
linkwatch_nextevent = jiffies;
clear_bit(LW_URGENT, &linkwatch_flags);
spin_lock_irq(&lweventlist_lock);
list_splice_init(&lweventlist, &wrk);
while (!list_empty(&wrk)) {
dev = list_first_entry(&wrk, struct net_device, link_watch_list);
list_del_init(&dev->link_watch_list);
if (urgent_only && !linkwatch_urgent_event(dev)) {
list_add_tail(&dev->link_watch_list, &lweventlist);
continue;
}
spin_unlock_irq(&lweventlist_lock);
linkwatch_do_dev(dev);
spin_lock_irq(&lweventlist_lock);
}
if (!list_empty(&lweventlist))
linkwatch_schedule_work(0);
spin_unlock_irq(&lweventlist_lock);
}
void linkwatch_forget_dev(struct net_device *dev)
{
unsigned long flags;
int clean = 0;
spin_lock_irqsave(&lweventlist_lock, flags);
if (!list_empty(&dev->link_watch_list)) {
list_del_init(&dev->link_watch_list);
clean = 1;
}
spin_unlock_irqrestore(&lweventlist_lock, flags);
if (clean)
linkwatch_do_dev(dev);
}
void linkwatch_run_queue(void)
{
__linkwatch_run_queue(0);
}
static void linkwatch_event(struct work_struct *dummy)
{
rtnl_lock();
__linkwatch_run_queue(time_after(linkwatch_nextevent, jiffies));
rtnl_unlock();
}
void linkwatch_fire_event(struct net_device *dev)
{
bool urgent = linkwatch_urgent_event(dev);
if (!test_and_set_bit(__LINK_STATE_LINKWATCH_PENDING, &dev->state)) {
linkwatch_add_event(dev);
} else if (!urgent)
return;
linkwatch_schedule_work(urgent);
}
