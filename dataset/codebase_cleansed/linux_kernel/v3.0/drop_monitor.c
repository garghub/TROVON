static void reset_per_cpu_data(struct per_cpu_dm_data *data)
{
size_t al;
struct net_dm_alert_msg *msg;
struct nlattr *nla;
al = sizeof(struct net_dm_alert_msg);
al += dm_hit_limit * sizeof(struct net_dm_drop_point);
al += sizeof(struct nlattr);
data->skb = genlmsg_new(al, GFP_KERNEL);
genlmsg_put(data->skb, 0, 0, &net_drop_monitor_family,
0, NET_DM_CMD_ALERT);
nla = nla_reserve(data->skb, NLA_UNSPEC, sizeof(struct net_dm_alert_msg));
msg = nla_data(nla);
memset(msg, 0, al);
atomic_set(&data->dm_hit_count, dm_hit_limit);
}
static void send_dm_alert(struct work_struct *unused)
{
struct sk_buff *skb;
struct per_cpu_dm_data *data = &__get_cpu_var(dm_cpu_data);
skb = data->skb;
reset_per_cpu_data(data);
genlmsg_multicast(skb, 0, NET_DM_GRP_ALERT, GFP_KERNEL);
}
static void sched_send_work(unsigned long unused)
{
struct per_cpu_dm_data *data = &__get_cpu_var(dm_cpu_data);
schedule_work(&data->dm_alert_work);
}
static void trace_drop_common(struct sk_buff *skb, void *location)
{
struct net_dm_alert_msg *msg;
struct nlmsghdr *nlh;
struct nlattr *nla;
int i;
struct per_cpu_dm_data *data = &__get_cpu_var(dm_cpu_data);
if (!atomic_add_unless(&data->dm_hit_count, -1, 0)) {
goto out;
}
nlh = (struct nlmsghdr *)data->skb->data;
nla = genlmsg_data(nlmsg_data(nlh));
msg = nla_data(nla);
for (i = 0; i < msg->entries; i++) {
if (!memcmp(&location, msg->points[i].pc, sizeof(void *))) {
msg->points[i].count++;
goto out;
}
}
__nla_reserve_nohdr(data->skb, sizeof(struct net_dm_drop_point));
nla->nla_len += NLA_ALIGN(sizeof(struct net_dm_drop_point));
memcpy(msg->points[msg->entries].pc, &location, sizeof(void *));
msg->points[msg->entries].count = 1;
msg->entries++;
if (!timer_pending(&data->send_timer)) {
data->send_timer.expires = jiffies + dm_delay * HZ;
add_timer_on(&data->send_timer, smp_processor_id());
}
out:
return;
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
spin_lock(&trace_state_lock);
if (state == trace_state) {
rc = -EAGAIN;
goto out_unlock;
}
switch (state) {
case TRACE_ON:
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
spin_unlock(&trace_state_lock);
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
struct net_device *dev = ptr;
struct dm_hw_stat_delta *new_stat = NULL;
struct dm_hw_stat_delta *tmp;
switch (event) {
case NETDEV_REGISTER:
new_stat = kzalloc(sizeof(struct dm_hw_stat_delta), GFP_KERNEL);
if (!new_stat)
goto out;
new_stat->dev = dev;
new_stat->last_rx = jiffies;
spin_lock(&trace_state_lock);
list_add_rcu(&new_stat->list, &hw_stats_list);
spin_unlock(&trace_state_lock);
break;
case NETDEV_UNREGISTER:
spin_lock(&trace_state_lock);
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
spin_unlock(&trace_state_lock);
break;
}
out:
return NOTIFY_DONE;
}
static int __init init_net_drop_monitor(void)
{
struct per_cpu_dm_data *data;
int cpu, rc;
printk(KERN_INFO "Initializing network drop monitor service\n");
if (sizeof(void *) > 8) {
printk(KERN_ERR "Unable to store program counters on this arch, Drop monitor failed\n");
return -ENOSPC;
}
rc = genl_register_family_with_ops(&net_drop_monitor_family,
dropmon_ops,
ARRAY_SIZE(dropmon_ops));
if (rc) {
printk(KERN_ERR "Could not create drop monitor netlink family\n");
return rc;
}
rc = register_netdevice_notifier(&dropmon_net_notifier);
if (rc < 0) {
printk(KERN_CRIT "Failed to register netdevice notifier\n");
goto out_unreg;
}
rc = 0;
for_each_present_cpu(cpu) {
data = &per_cpu(dm_cpu_data, cpu);
reset_per_cpu_data(data);
INIT_WORK(&data->dm_alert_work, send_dm_alert);
init_timer(&data->send_timer);
data->send_timer.data = cpu;
data->send_timer.function = sched_send_work;
}
goto out;
out_unreg:
genl_unregister_family(&net_drop_monitor_family);
out:
return rc;
}
