static ssize_t store_bridge_parm(struct device *d,
const char *buf, size_t len,
int (*set)(struct net_bridge *, unsigned long))
{
struct net_bridge *br = to_bridge(d);
char *endp;
unsigned long val;
int err;
if (!ns_capable(dev_net(br->dev)->user_ns, CAP_NET_ADMIN))
return -EPERM;
val = simple_strtoul(buf, &endp, 0);
if (endp == buf)
return -EINVAL;
err = (*set)(br, val);
return err ? err : len;
}
static ssize_t show_forward_delay(struct device *d,
struct device_attribute *attr, char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%lu\n", jiffies_to_clock_t(br->forward_delay));
}
static ssize_t store_forward_delay(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, br_set_forward_delay);
}
static ssize_t show_hello_time(struct device *d, struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%lu\n",
jiffies_to_clock_t(to_bridge(d)->hello_time));
}
static ssize_t store_hello_time(struct device *d,
struct device_attribute *attr, const char *buf,
size_t len)
{
return store_bridge_parm(d, buf, len, br_set_hello_time);
}
static ssize_t show_max_age(struct device *d, struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%lu\n",
jiffies_to_clock_t(to_bridge(d)->max_age));
}
static ssize_t store_max_age(struct device *d, struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, br_set_max_age);
}
static ssize_t show_ageing_time(struct device *d,
struct device_attribute *attr, char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%lu\n", jiffies_to_clock_t(br->ageing_time));
}
static int set_ageing_time(struct net_bridge *br, unsigned long val)
{
br->ageing_time = clock_t_to_jiffies(val);
return 0;
}
static ssize_t store_ageing_time(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, set_ageing_time);
}
static ssize_t show_stp_state(struct device *d,
struct device_attribute *attr, char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%d\n", br->stp_enabled);
}
static ssize_t store_stp_state(struct device *d,
struct device_attribute *attr, const char *buf,
size_t len)
{
struct net_bridge *br = to_bridge(d);
char *endp;
unsigned long val;
if (!ns_capable(dev_net(br->dev)->user_ns, CAP_NET_ADMIN))
return -EPERM;
val = simple_strtoul(buf, &endp, 0);
if (endp == buf)
return -EINVAL;
if (!rtnl_trylock())
return restart_syscall();
br_stp_set_enabled(br, val);
rtnl_unlock();
return len;
}
static ssize_t show_group_fwd_mask(struct device *d,
struct device_attribute *attr, char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%#x\n", br->group_fwd_mask);
}
static ssize_t store_group_fwd_mask(struct device *d,
struct device_attribute *attr, const char *buf,
size_t len)
{
struct net_bridge *br = to_bridge(d);
char *endp;
unsigned long val;
if (!ns_capable(dev_net(br->dev)->user_ns, CAP_NET_ADMIN))
return -EPERM;
val = simple_strtoul(buf, &endp, 0);
if (endp == buf)
return -EINVAL;
if (val & BR_GROUPFWD_RESTRICTED)
return -EINVAL;
br->group_fwd_mask = val;
return len;
}
static ssize_t show_priority(struct device *d, struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%d\n",
(br->bridge_id.prio[0] << 8) | br->bridge_id.prio[1]);
}
static int set_priority(struct net_bridge *br, unsigned long val)
{
br_stp_set_bridge_priority(br, (u16) val);
return 0;
}
static ssize_t store_priority(struct device *d, struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, set_priority);
}
static ssize_t show_root_id(struct device *d, struct device_attribute *attr,
char *buf)
{
return br_show_bridge_id(buf, &to_bridge(d)->designated_root);
}
static ssize_t show_bridge_id(struct device *d, struct device_attribute *attr,
char *buf)
{
return br_show_bridge_id(buf, &to_bridge(d)->bridge_id);
}
static ssize_t show_root_port(struct device *d, struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%d\n", to_bridge(d)->root_port);
}
static ssize_t show_root_path_cost(struct device *d,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", to_bridge(d)->root_path_cost);
}
static ssize_t show_topology_change(struct device *d,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", to_bridge(d)->topology_change);
}
static ssize_t show_topology_change_detected(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%d\n", br->topology_change_detected);
}
static ssize_t show_hello_timer(struct device *d,
struct device_attribute *attr, char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%ld\n", br_timer_value(&br->hello_timer));
}
static ssize_t show_tcn_timer(struct device *d, struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%ld\n", br_timer_value(&br->tcn_timer));
}
static ssize_t show_topology_change_timer(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%ld\n", br_timer_value(&br->topology_change_timer));
}
static ssize_t show_gc_timer(struct device *d, struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%ld\n", br_timer_value(&br->gc_timer));
}
static ssize_t show_group_addr(struct device *d,
struct device_attribute *attr, char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%x:%x:%x:%x:%x:%x\n",
br->group_addr[0], br->group_addr[1],
br->group_addr[2], br->group_addr[3],
br->group_addr[4], br->group_addr[5]);
}
static ssize_t store_group_addr(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct net_bridge *br = to_bridge(d);
u8 new_addr[6];
int i;
if (!ns_capable(dev_net(br->dev)->user_ns, CAP_NET_ADMIN))
return -EPERM;
if (sscanf(buf, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx",
&new_addr[0], &new_addr[1], &new_addr[2],
&new_addr[3], &new_addr[4], &new_addr[5]) != 6)
return -EINVAL;
if (!is_link_local_ether_addr(new_addr))
return -EINVAL;
if (new_addr[5] == 1 ||
new_addr[5] == 2 ||
new_addr[5] == 3)
return -EINVAL;
spin_lock_bh(&br->lock);
for (i = 0; i < 6; i++)
br->group_addr[i] = new_addr[i];
spin_unlock_bh(&br->lock);
return len;
}
static ssize_t store_flush(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct net_bridge *br = to_bridge(d);
if (!ns_capable(dev_net(br->dev)->user_ns, CAP_NET_ADMIN))
return -EPERM;
br_fdb_flush(br);
return len;
}
static ssize_t show_multicast_router(struct device *d,
struct device_attribute *attr, char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%d\n", br->multicast_router);
}
static ssize_t store_multicast_router(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, br_multicast_set_router);
}
static ssize_t show_multicast_snooping(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%d\n", !br->multicast_disabled);
}
static ssize_t store_multicast_snooping(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, br_multicast_toggle);
}
static ssize_t show_multicast_query_use_ifaddr(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%d\n", br->multicast_query_use_ifaddr);
}
static int set_query_use_ifaddr(struct net_bridge *br, unsigned long val)
{
br->multicast_query_use_ifaddr = !!val;
return 0;
}
static ssize_t
store_multicast_query_use_ifaddr(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, set_query_use_ifaddr);
}
static ssize_t show_multicast_querier(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%d\n", br->multicast_querier);
}
static ssize_t store_multicast_querier(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, br_multicast_set_querier);
}
static ssize_t show_hash_elasticity(struct device *d,
struct device_attribute *attr, char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%u\n", br->hash_elasticity);
}
static int set_elasticity(struct net_bridge *br, unsigned long val)
{
br->hash_elasticity = val;
return 0;
}
static ssize_t store_hash_elasticity(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, set_elasticity);
}
static ssize_t show_hash_max(struct device *d, struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%u\n", br->hash_max);
}
static ssize_t store_hash_max(struct device *d, struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, br_multicast_set_hash_max);
}
static ssize_t show_multicast_last_member_count(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%u\n", br->multicast_last_member_count);
}
static int set_last_member_count(struct net_bridge *br, unsigned long val)
{
br->multicast_last_member_count = val;
return 0;
}
static ssize_t store_multicast_last_member_count(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, set_last_member_count);
}
static ssize_t show_multicast_startup_query_count(
struct device *d, struct device_attribute *attr, char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%u\n", br->multicast_startup_query_count);
}
static int set_startup_query_count(struct net_bridge *br, unsigned long val)
{
br->multicast_startup_query_count = val;
return 0;
}
static ssize_t store_multicast_startup_query_count(
struct device *d, struct device_attribute *attr, const char *buf,
size_t len)
{
return store_bridge_parm(d, buf, len, set_startup_query_count);
}
static ssize_t show_multicast_last_member_interval(
struct device *d, struct device_attribute *attr, char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%lu\n",
jiffies_to_clock_t(br->multicast_last_member_interval));
}
static int set_last_member_interval(struct net_bridge *br, unsigned long val)
{
br->multicast_last_member_interval = clock_t_to_jiffies(val);
return 0;
}
static ssize_t store_multicast_last_member_interval(
struct device *d, struct device_attribute *attr, const char *buf,
size_t len)
{
return store_bridge_parm(d, buf, len, set_last_member_interval);
}
static ssize_t show_multicast_membership_interval(
struct device *d, struct device_attribute *attr, char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%lu\n",
jiffies_to_clock_t(br->multicast_membership_interval));
}
static int set_membership_interval(struct net_bridge *br, unsigned long val)
{
br->multicast_membership_interval = clock_t_to_jiffies(val);
return 0;
}
static ssize_t store_multicast_membership_interval(
struct device *d, struct device_attribute *attr, const char *buf,
size_t len)
{
return store_bridge_parm(d, buf, len, set_membership_interval);
}
static ssize_t show_multicast_querier_interval(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%lu\n",
jiffies_to_clock_t(br->multicast_querier_interval));
}
static int set_querier_interval(struct net_bridge *br, unsigned long val)
{
br->multicast_querier_interval = clock_t_to_jiffies(val);
return 0;
}
static ssize_t store_multicast_querier_interval(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, set_querier_interval);
}
static ssize_t show_multicast_query_interval(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%lu\n",
jiffies_to_clock_t(br->multicast_query_interval));
}
static int set_query_interval(struct net_bridge *br, unsigned long val)
{
br->multicast_query_interval = clock_t_to_jiffies(val);
return 0;
}
static ssize_t store_multicast_query_interval(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, set_query_interval);
}
static ssize_t show_multicast_query_response_interval(
struct device *d, struct device_attribute *attr, char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(
buf, "%lu\n",
jiffies_to_clock_t(br->multicast_query_response_interval));
}
static int set_query_response_interval(struct net_bridge *br, unsigned long val)
{
br->multicast_query_response_interval = clock_t_to_jiffies(val);
return 0;
}
static ssize_t store_multicast_query_response_interval(
struct device *d, struct device_attribute *attr, const char *buf,
size_t len)
{
return store_bridge_parm(d, buf, len, set_query_response_interval);
}
static ssize_t show_multicast_startup_query_interval(
struct device *d, struct device_attribute *attr, char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(
buf, "%lu\n",
jiffies_to_clock_t(br->multicast_startup_query_interval));
}
static int set_startup_query_interval(struct net_bridge *br, unsigned long val)
{
br->multicast_startup_query_interval = clock_t_to_jiffies(val);
return 0;
}
static ssize_t store_multicast_startup_query_interval(
struct device *d, struct device_attribute *attr, const char *buf,
size_t len)
{
return store_bridge_parm(d, buf, len, set_startup_query_interval);
}
static ssize_t show_nf_call_iptables(
struct device *d, struct device_attribute *attr, char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%u\n", br->nf_call_iptables);
}
static int set_nf_call_iptables(struct net_bridge *br, unsigned long val)
{
br->nf_call_iptables = val ? true : false;
return 0;
}
static ssize_t store_nf_call_iptables(
struct device *d, struct device_attribute *attr, const char *buf,
size_t len)
{
return store_bridge_parm(d, buf, len, set_nf_call_iptables);
}
static ssize_t show_nf_call_ip6tables(
struct device *d, struct device_attribute *attr, char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%u\n", br->nf_call_ip6tables);
}
static int set_nf_call_ip6tables(struct net_bridge *br, unsigned long val)
{
br->nf_call_ip6tables = val ? true : false;
return 0;
}
static ssize_t store_nf_call_ip6tables(
struct device *d, struct device_attribute *attr, const char *buf,
size_t len)
{
return store_bridge_parm(d, buf, len, set_nf_call_ip6tables);
}
static ssize_t show_nf_call_arptables(
struct device *d, struct device_attribute *attr, char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%u\n", br->nf_call_arptables);
}
static int set_nf_call_arptables(struct net_bridge *br, unsigned long val)
{
br->nf_call_arptables = val ? true : false;
return 0;
}
static ssize_t store_nf_call_arptables(
struct device *d, struct device_attribute *attr, const char *buf,
size_t len)
{
return store_bridge_parm(d, buf, len, set_nf_call_arptables);
}
static ssize_t show_vlan_filtering(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%d\n", br->vlan_enabled);
}
static ssize_t store_vlan_filtering(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, br_vlan_filter_toggle);
}
static ssize_t brforward_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct device *dev = to_dev(kobj);
struct net_bridge *br = to_bridge(dev);
int n;
if (off % sizeof(struct __fdb_entry) != 0)
return -EINVAL;
n = br_fdb_fillbuf(br, buf,
count / sizeof(struct __fdb_entry),
off / sizeof(struct __fdb_entry));
if (n > 0)
n *= sizeof(struct __fdb_entry);
return n;
}
int br_sysfs_addbr(struct net_device *dev)
{
struct kobject *brobj = &dev->dev.kobj;
struct net_bridge *br = netdev_priv(dev);
int err;
err = sysfs_create_group(brobj, &bridge_group);
if (err) {
pr_info("%s: can't create group %s/%s\n",
__func__, dev->name, bridge_group.name);
goto out1;
}
err = sysfs_create_bin_file(brobj, &bridge_forward);
if (err) {
pr_info("%s: can't create attribute file %s/%s\n",
__func__, dev->name, bridge_forward.attr.name);
goto out2;
}
br->ifobj = kobject_create_and_add(SYSFS_BRIDGE_PORT_SUBDIR, brobj);
if (!br->ifobj) {
pr_info("%s: can't add kobject (directory) %s/%s\n",
__func__, dev->name, SYSFS_BRIDGE_PORT_SUBDIR);
goto out3;
}
return 0;
out3:
sysfs_remove_bin_file(&dev->dev.kobj, &bridge_forward);
out2:
sysfs_remove_group(&dev->dev.kobj, &bridge_group);
out1:
return err;
}
void br_sysfs_delbr(struct net_device *dev)
{
struct kobject *kobj = &dev->dev.kobj;
struct net_bridge *br = netdev_priv(dev);
kobject_put(br->ifobj);
sysfs_remove_bin_file(kobj, &bridge_forward);
sysfs_remove_group(kobj, &bridge_group);
}
