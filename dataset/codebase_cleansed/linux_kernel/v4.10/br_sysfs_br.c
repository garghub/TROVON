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
if (!rtnl_trylock())
return restart_syscall();
err = (*set)(br, val);
if (!err)
netdev_state_change(br->dev);
rtnl_unlock();
return err ? err : len;
}
static ssize_t forward_delay_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%lu\n", jiffies_to_clock_t(br->forward_delay));
}
static ssize_t forward_delay_store(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, br_set_forward_delay);
}
static ssize_t hello_time_show(struct device *d, struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%lu\n",
jiffies_to_clock_t(to_bridge(d)->hello_time));
}
static ssize_t hello_time_store(struct device *d,
struct device_attribute *attr, const char *buf,
size_t len)
{
return store_bridge_parm(d, buf, len, br_set_hello_time);
}
static ssize_t max_age_show(struct device *d, struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%lu\n",
jiffies_to_clock_t(to_bridge(d)->max_age));
}
static ssize_t max_age_store(struct device *d, struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, br_set_max_age);
}
static ssize_t ageing_time_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%lu\n", jiffies_to_clock_t(br->ageing_time));
}
static int set_ageing_time(struct net_bridge *br, unsigned long val)
{
return br_set_ageing_time(br, val);
}
static ssize_t ageing_time_store(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, set_ageing_time);
}
static ssize_t stp_state_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%d\n", br->stp_enabled);
}
static int set_stp_state(struct net_bridge *br, unsigned long val)
{
br_stp_set_enabled(br, val);
return 0;
}
static ssize_t stp_state_store(struct device *d,
struct device_attribute *attr, const char *buf,
size_t len)
{
return store_bridge_parm(d, buf, len, set_stp_state);
}
static ssize_t group_fwd_mask_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%#x\n", br->group_fwd_mask);
}
static int set_group_fwd_mask(struct net_bridge *br, unsigned long val)
{
if (val & BR_GROUPFWD_RESTRICTED)
return -EINVAL;
br->group_fwd_mask = val;
return 0;
}
static ssize_t group_fwd_mask_store(struct device *d,
struct device_attribute *attr,
const char *buf,
size_t len)
{
return store_bridge_parm(d, buf, len, set_group_fwd_mask);
}
static ssize_t priority_show(struct device *d, struct device_attribute *attr,
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
static ssize_t priority_store(struct device *d, struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, set_priority);
}
static ssize_t root_id_show(struct device *d, struct device_attribute *attr,
char *buf)
{
return br_show_bridge_id(buf, &to_bridge(d)->designated_root);
}
static ssize_t bridge_id_show(struct device *d, struct device_attribute *attr,
char *buf)
{
return br_show_bridge_id(buf, &to_bridge(d)->bridge_id);
}
static ssize_t root_port_show(struct device *d, struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%d\n", to_bridge(d)->root_port);
}
static ssize_t root_path_cost_show(struct device *d,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", to_bridge(d)->root_path_cost);
}
static ssize_t topology_change_show(struct device *d,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", to_bridge(d)->topology_change);
}
static ssize_t topology_change_detected_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%d\n", br->topology_change_detected);
}
static ssize_t hello_timer_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%ld\n", br_timer_value(&br->hello_timer));
}
static ssize_t tcn_timer_show(struct device *d, struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%ld\n", br_timer_value(&br->tcn_timer));
}
static ssize_t topology_change_timer_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%ld\n", br_timer_value(&br->topology_change_timer));
}
static ssize_t gc_timer_show(struct device *d, struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%ld\n", br_timer_value(&br->gc_timer));
}
static ssize_t group_addr_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%x:%x:%x:%x:%x:%x\n",
br->group_addr[0], br->group_addr[1],
br->group_addr[2], br->group_addr[3],
br->group_addr[4], br->group_addr[5]);
}
static ssize_t group_addr_store(struct device *d,
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
if (!rtnl_trylock())
return restart_syscall();
spin_lock_bh(&br->lock);
for (i = 0; i < 6; i++)
br->group_addr[i] = new_addr[i];
spin_unlock_bh(&br->lock);
br->group_addr_set = true;
br_recalculate_fwd_mask(br);
netdev_state_change(br->dev);
rtnl_unlock();
return len;
}
static int set_flush(struct net_bridge *br, unsigned long val)
{
br_fdb_flush(br);
return 0;
}
static ssize_t flush_store(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, set_flush);
}
static ssize_t multicast_router_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%d\n", br->multicast_router);
}
static ssize_t multicast_router_store(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, br_multicast_set_router);
}
static ssize_t multicast_snooping_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%d\n", !br->multicast_disabled);
}
static ssize_t multicast_snooping_store(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, br_multicast_toggle);
}
static ssize_t multicast_query_use_ifaddr_show(struct device *d,
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
multicast_query_use_ifaddr_store(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, set_query_use_ifaddr);
}
static ssize_t multicast_querier_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%d\n", br->multicast_querier);
}
static ssize_t multicast_querier_store(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, br_multicast_set_querier);
}
static ssize_t hash_elasticity_show(struct device *d,
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
static ssize_t hash_elasticity_store(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, set_elasticity);
}
static ssize_t hash_max_show(struct device *d, struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%u\n", br->hash_max);
}
static ssize_t hash_max_store(struct device *d, struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, br_multicast_set_hash_max);
}
static ssize_t multicast_igmp_version_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%u\n", br->multicast_igmp_version);
}
static ssize_t multicast_igmp_version_store(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, br_multicast_set_igmp_version);
}
static ssize_t multicast_last_member_count_show(struct device *d,
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
static ssize_t multicast_last_member_count_store(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, set_last_member_count);
}
static ssize_t multicast_startup_query_count_show(
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
static ssize_t multicast_startup_query_count_store(
struct device *d, struct device_attribute *attr, const char *buf,
size_t len)
{
return store_bridge_parm(d, buf, len, set_startup_query_count);
}
static ssize_t multicast_last_member_interval_show(
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
static ssize_t multicast_last_member_interval_store(
struct device *d, struct device_attribute *attr, const char *buf,
size_t len)
{
return store_bridge_parm(d, buf, len, set_last_member_interval);
}
static ssize_t multicast_membership_interval_show(
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
static ssize_t multicast_membership_interval_store(
struct device *d, struct device_attribute *attr, const char *buf,
size_t len)
{
return store_bridge_parm(d, buf, len, set_membership_interval);
}
static ssize_t multicast_querier_interval_show(struct device *d,
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
static ssize_t multicast_querier_interval_store(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, set_querier_interval);
}
static ssize_t multicast_query_interval_show(struct device *d,
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
static ssize_t multicast_query_interval_store(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, set_query_interval);
}
static ssize_t multicast_query_response_interval_show(
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
static ssize_t multicast_query_response_interval_store(
struct device *d, struct device_attribute *attr, const char *buf,
size_t len)
{
return store_bridge_parm(d, buf, len, set_query_response_interval);
}
static ssize_t multicast_startup_query_interval_show(
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
static ssize_t multicast_startup_query_interval_store(
struct device *d, struct device_attribute *attr, const char *buf,
size_t len)
{
return store_bridge_parm(d, buf, len, set_startup_query_interval);
}
static ssize_t multicast_stats_enabled_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%u\n", br->multicast_stats_enabled);
}
static int set_stats_enabled(struct net_bridge *br, unsigned long val)
{
br->multicast_stats_enabled = !!val;
return 0;
}
static ssize_t multicast_stats_enabled_store(struct device *d,
struct device_attribute *attr,
const char *buf,
size_t len)
{
return store_bridge_parm(d, buf, len, set_stats_enabled);
}
static ssize_t multicast_mld_version_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%u\n", br->multicast_mld_version);
}
static ssize_t multicast_mld_version_store(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, br_multicast_set_mld_version);
}
static ssize_t nf_call_iptables_show(
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
static ssize_t nf_call_iptables_store(
struct device *d, struct device_attribute *attr, const char *buf,
size_t len)
{
return store_bridge_parm(d, buf, len, set_nf_call_iptables);
}
static ssize_t nf_call_ip6tables_show(
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
static ssize_t nf_call_ip6tables_store(
struct device *d, struct device_attribute *attr, const char *buf,
size_t len)
{
return store_bridge_parm(d, buf, len, set_nf_call_ip6tables);
}
static ssize_t nf_call_arptables_show(
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
static ssize_t nf_call_arptables_store(
struct device *d, struct device_attribute *attr, const char *buf,
size_t len)
{
return store_bridge_parm(d, buf, len, set_nf_call_arptables);
}
static ssize_t vlan_filtering_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%d\n", br->vlan_enabled);
}
static ssize_t vlan_filtering_store(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, br_vlan_filter_toggle);
}
static ssize_t vlan_protocol_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%#06x\n", ntohs(br->vlan_proto));
}
static ssize_t vlan_protocol_store(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, br_vlan_set_proto);
}
static ssize_t default_pvid_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%d\n", br->default_pvid);
}
static ssize_t default_pvid_store(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, br_vlan_set_default_pvid);
}
static ssize_t vlan_stats_enabled_show(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct net_bridge *br = to_bridge(d);
return sprintf(buf, "%u\n", br->vlan_stats_enabled);
}
static ssize_t vlan_stats_enabled_store(struct device *d,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_bridge_parm(d, buf, len, br_vlan_set_stats);
}
static ssize_t brforward_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct device *dev = kobj_to_dev(kobj);
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
err = -ENOMEM;
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
