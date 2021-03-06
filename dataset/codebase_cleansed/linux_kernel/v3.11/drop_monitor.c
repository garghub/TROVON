static struct sk_buff *reset_per_cpu_data(struct per_cpu_dm_data *data)
{
size_t al;
struct net_dm_alert_msg *msg;
struct nlattr *nla;
struct sk_buff *skb;
unsigned long flags;
al = sizeof(struct net_dm_alert_msg);
al += dm_hit_limit * sizeof(struct net_dm_drop_point);
al += sizeof(struct nlattr);
skb = genlmsg_new(al, GFP_KERNEL);
if (skb) {
genlmsg_put(skb, 0, 0, &net_drop_monitor_family,
0, NET_DM_CMD_ALERT);
nla = nla_reserve(skb, NLA_UNSPEC,
sizeof(struct net_dm_alert_msg));
msg = nla_data(nla);
memset(msg, 0, al);
} else {
mod_timer(&data->send_timer, jiffies + HZ / 10);
}
spin_lock_irqsave(&data->lock, flags);
swap(data->skb, skb);
spin_unlock_irqrestore(&data->lock, flags);
return skb;
}
static void send_dm_alert(struct work_struct *work)
{
struct sk_buff *skb;
struct per_cpu_dm_data *data;
data = container_of(work, struct per_cpu_dm_data, dm_alert_work);
skb = reset_per_cpu_data(data);
if (skb)
genlmsg_multicast(skb, 0, NET_DM_GRP_ALERT, GFP_KERNEL);
}
static void sched_send_work(unsigned long _data)
{
struct per_cpu_dm_data *data = (struct per_cpu_dm_data *)_data;
schedule_work(&data->dm_alert_work);
}
static void trace_drop_common(struct sk_buff *skb, void *location)
{
struct net_dm_alert_msg *msg;
struct nlmsghdr *nlh;
struct nlattr *nla;
int i;
struct sk_buff *dskb;
struct per_cpu_dm_data *data;
unsigned long flags;
local_irq_save(flags);
data = &__get_cpu_var(dm_cpu_data);
spin_lock(&data->lock);
dskb = data->skb;
if (!dskb)
goto out;
nlh = (struct nlmsghdr *)dskb->data;
nla = genlmsg_data(nlmsg_data(nlh));
msg = nla_data(nla);
for (i = 0; i < msg->entries; i++) {
if (!memcmp(&location, msg->points[i].pc, sizeof(void *))) {
msg->points[i].count++;
goto out;
}
}
if (msg->entries == dm_hit_limit)
goto out;
__nla_reserve_nohdr(dskb, sizeof(struct net_dm_drop_point));
nla->nla_len += NLA_ALIGN(sizeof(struct net_dm_drop_point));
memcpy(msg->points[msg->entries].pc, &location, sizeof(void *));
msg->points[msg->entries].count = 1;
msg->entries++;
if (!timer_pending(&data->send_timer)) {
data->send_timer.expires = jiffies + dm_delay * HZ;
add_timer(&data->send_timer);
}
out:
spin_unlock_irqrestore(&data->lock, flags);
}
static void trace_kfree_skb_hit(void *ignore, struct sk_buff *skb, void *location)
{
trace_drop_common(skb, location);
}
static void trace_napi_poll_hit(void *ignore, struct napi_struct *napi)
{
struct dm_hw_stat_delta *new_stat;
if (!napi->dev)
return;
rcu_read_lock();
list_for_each_entry_rcu(new_stat, &hw_stats_list, list) {
if ((new_stat->dev == napi->dev) &&
(time_after(jiffies, new_stat->last_rx + dm_hw_check_delta)) &&
(napi->dev->stats.rx_dropped != new_stat->last_drop_val)) {
trace_drop_common(NULL, NULL);
new_stat->last_drop_val = napi->dev->stats.rx_dropped;
new_stat->last_rx = jiffies;
break;
}
}
rcu_read_unlock();
}
static int set_all_monitor_traces(int state)
{
int rc = 0;
struct dm_hw_stat_delta *new_stat = NULL;
struct dm_hw_stat_delta *temp;
mutex_lock(&trace_state_mutex);
if (state == trace_state) {
rc = -EAGAIN;
goto out_unlock;
}
switch (state) {
case TRACE_ON:
if (!try_module_get(THIS_MODULE)) {
rc = -ENODEV;
break;
}
rc |= register_trace_kfree_skb(trace_kfree_skb_hit, NULL);
rc |= register_trace_napi_poll(trace_napi_poll_hit, NULL);
break;
case TRACE_OFF:
rc |= unregister_trace_kfree_skb(trace_kfree_skb_hit, NULL);
rc |= unregister_trace_napi_poll(trace_napi_poll_hit, NULL);
tracepoint_synchronize_unregister();
list_for_each_entry_safe(new_stat, temp, &hw_stats_list, list) {
if (new_stat->dev == NULL) {
list_del_rcu(&new_stat->list);
kfree_rcu(new_stat, rcu);
}
}
module_put(THIS_MODULE);
break;
default:
rc = 1;
break;
}
if (!rc)
trace_state = state;
else
rc = -EINPROGRESS;
out_unlock:
mutex_unlock(&trace_state_mutex);
return rc;
}
static int net_dm_cmd_config(struct sk_buff *skb,
struct genl_info *info)
{
return -ENOTSUPP;
}
static int net_dm_cmd_trace(struct sk_buff *skb,
struct genl_info *info)
{
switch (info->genlhdr->cmd) {
case NET_DM_CMD_START:
return set_all_monitor_traces(TRACE_ON);
break;
case NET_DM_CMD_STOP:
return set_all_monitor_traces(TRACE_OFF);
break;
}
return -ENOTSUPP;
}
static int dropmon_net_event(struct notifier_block *ev_block,
unsigned long event, void *ptr)
{
struct net_device *dev = netdev_notifier_info_to_dev(ptr);
struct dm_hw_stat_delta *new_stat = NULL;
struct dm_hw_stat_delta *tmp;
switch (event) {
case NETDEV_REGISTER:
new_stat = kzalloc(sizeof(struct dm_hw_stat_delta), GFP_KERNEL);
if (!new_stat)
goto out;
new_stat->dev = dev;
new_stat->last_rx = jiffies;
mutex_lock(&trace_state_mutex);
list_add_rcu(&new_stat->list, &hw_stats_list);
mutex_unlock(&trace_state_mutex);
break;
case NETDEV_UNREGISTER:
mutex_lock(&trace_state_mutex);
list_for_each_entry_safe(new_stat, tmp, &hw_stats_list, list) {
if (new_stat->dev == dev) {
new_stat->dev = NULL;
if (trace_state == TRACE_OFF) {
list_del_rcu(&new_stat->list);
kfree_rcu(new_stat, rcu);
break;
}
}
}
mutex_unlock(&trace_state_mutex);
break;
}
out:
return NOTIFY_DONE;
}
static int __init init_net_drop_monitor(void)
{
struct per_cpu_dm_data *data;
int cpu, rc;
pr_info("Initializing network drop monitor service\n");
if (sizeof(void *) > 8) {
pr_err("Unable to store program counters on this arch, Drop monitor failed\n");
return -ENOSPC;
}
rc = genl_register_family_with_ops(&net_drop_monitor_family,
dropmon_ops,
ARRAY_SIZE(dropmon_ops));
if (rc) {
pr_err("Could not create drop monitor netlink family\n");
return rc;
}
rc = register_netdevice_notifier(&dropmon_net_notifier);
if (rc < 0) {
pr_crit("Failed to register netdevice notifier\n");
goto out_unreg;
}
rc = 0;
for_each_possible_cpu(cpu) {
data = &per_cpu(dm_cpu_data, cpu);
INIT_WORK(&data->dm_alert_work, send_dm_alert);
init_timer(&data->send_timer);
data->send_timer.data = (unsigned long)data;
data->send_timer.function = sched_send_work;
spin_lock_init(&data->lock);
reset_per_cpu_data(data);
}
goto out;
out_unreg:
genl_unregister_family(&net_drop_monitor_family);
out:
return rc;
}
static void exit_net_drop_monitor(void)
{
struct per_cpu_dm_data *data;
int cpu;
BUG_ON(unregister_netdevice_notifier(&dropmon_net_notifier));
for_each_possible_cpu(cpu) {
data = &per_cpu(dm_cpu_data, cpu);
del_timer_sync(&data->send_timer);
cancel_work_sync(&data->dm_alert_work);
kfree_skb(data->skb);
}
BUG_ON(genl_unregister_family(&net_drop_monitor_family));
}
