static ssize_t bonding_show_bonds(struct class *cls,
struct class_attribute *attr,
char *buf)
{
struct bond_net *bn =
container_of(attr, struct bond_net, class_attr_bonding_masters);
int res = 0;
struct bonding *bond;
rtnl_lock();
list_for_each_entry(bond, &bn->dev_list, bond_list) {
if (res > (PAGE_SIZE - IFNAMSIZ)) {
if ((PAGE_SIZE - res) > 10)
res = PAGE_SIZE - 10;
res += sprintf(buf + res, "++more++ ");
break;
}
res += sprintf(buf + res, "%s ", bond->dev->name);
}
if (res)
buf[res-1] = '\n';
rtnl_unlock();
return res;
}
static struct net_device *bond_get_by_name(struct bond_net *bn, const char *ifname)
{
struct bonding *bond;
list_for_each_entry(bond, &bn->dev_list, bond_list) {
if (strncmp(bond->dev->name, ifname, IFNAMSIZ) == 0)
return bond->dev;
}
return NULL;
}
static ssize_t bonding_store_bonds(struct class *cls,
struct class_attribute *attr,
const char *buffer, size_t count)
{
struct bond_net *bn =
container_of(attr, struct bond_net, class_attr_bonding_masters);
char command[IFNAMSIZ + 1] = {0, };
char *ifname;
int rv, res = count;
sscanf(buffer, "%16s", command);
ifname = command + 1;
if ((strlen(command) <= 1) ||
!dev_valid_name(ifname))
goto err_no_cmd;
if (command[0] == '+') {
pr_info("%s is being created...\n", ifname);
rv = bond_create(bn->net, ifname);
if (rv) {
if (rv == -EEXIST)
pr_info("%s already exists\n", ifname);
else
pr_info("%s creation failed\n", ifname);
res = rv;
}
} else if (command[0] == '-') {
struct net_device *bond_dev;
rtnl_lock();
bond_dev = bond_get_by_name(bn, ifname);
if (bond_dev) {
pr_info("%s is being deleted...\n", ifname);
unregister_netdevice(bond_dev);
} else {
pr_err("unable to delete non-existent %s\n", ifname);
res = -ENODEV;
}
rtnl_unlock();
} else
goto err_no_cmd;
return res;
err_no_cmd:
pr_err("no command found in bonding_masters - use +ifname or -ifname\n");
return -EPERM;
}
static ssize_t bonding_sysfs_store_option(struct device *d,
struct device_attribute *attr,
const char *buffer, size_t count)
{
struct bonding *bond = to_bond(d);
const struct bond_option *opt;
int ret;
opt = bond_opt_get_by_name(attr->attr.name);
if (WARN_ON(!opt))
return -ENOENT;
ret = bond_opt_tryset_rtnl(bond, opt->id, (char *)buffer);
if (!ret)
ret = count;
return ret;
}
static ssize_t bonding_show_slaves(struct device *d,
struct device_attribute *attr, char *buf)
{
struct bonding *bond = to_bond(d);
struct list_head *iter;
struct slave *slave;
int res = 0;
if (!rtnl_trylock())
return restart_syscall();
bond_for_each_slave(bond, slave, iter) {
if (res > (PAGE_SIZE - IFNAMSIZ)) {
if ((PAGE_SIZE - res) > 10)
res = PAGE_SIZE - 10;
res += sprintf(buf + res, "++more++ ");
break;
}
res += sprintf(buf + res, "%s ", slave->dev->name);
}
rtnl_unlock();
if (res)
buf[res-1] = '\n';
return res;
}
static ssize_t bonding_show_mode(struct device *d,
struct device_attribute *attr, char *buf)
{
struct bonding *bond = to_bond(d);
const struct bond_opt_value *val;
val = bond_opt_get_val(BOND_OPT_MODE, BOND_MODE(bond));
return sprintf(buf, "%s %d\n", val->string, BOND_MODE(bond));
}
static ssize_t bonding_show_xmit_hash(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
const struct bond_opt_value *val;
val = bond_opt_get_val(BOND_OPT_XMIT_HASH, bond->params.xmit_policy);
return sprintf(buf, "%s %d\n", val->string, bond->params.xmit_policy);
}
static ssize_t bonding_show_arp_validate(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
const struct bond_opt_value *val;
val = bond_opt_get_val(BOND_OPT_ARP_VALIDATE,
bond->params.arp_validate);
return sprintf(buf, "%s %d\n", val->string, bond->params.arp_validate);
}
static ssize_t bonding_show_arp_all_targets(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
const struct bond_opt_value *val;
val = bond_opt_get_val(BOND_OPT_ARP_ALL_TARGETS,
bond->params.arp_all_targets);
return sprintf(buf, "%s %d\n",
val->string, bond->params.arp_all_targets);
}
static ssize_t bonding_show_fail_over_mac(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
const struct bond_opt_value *val;
val = bond_opt_get_val(BOND_OPT_FAIL_OVER_MAC,
bond->params.fail_over_mac);
return sprintf(buf, "%s %d\n", val->string, bond->params.fail_over_mac);
}
static ssize_t bonding_show_arp_interval(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
return sprintf(buf, "%d\n", bond->params.arp_interval);
}
static ssize_t bonding_show_arp_targets(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
int i, res = 0;
for (i = 0; i < BOND_MAX_ARP_TARGETS; i++) {
if (bond->params.arp_targets[i])
res += sprintf(buf + res, "%pI4 ",
&bond->params.arp_targets[i]);
}
if (res)
buf[res-1] = '\n';
return res;
}
static ssize_t bonding_show_downdelay(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
return sprintf(buf, "%d\n", bond->params.downdelay * bond->params.miimon);
}
static ssize_t bonding_show_updelay(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
return sprintf(buf, "%d\n", bond->params.updelay * bond->params.miimon);
}
static ssize_t bonding_show_lacp(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
const struct bond_opt_value *val;
val = bond_opt_get_val(BOND_OPT_LACP_RATE, bond->params.lacp_fast);
return sprintf(buf, "%s %d\n", val->string, bond->params.lacp_fast);
}
static ssize_t bonding_show_min_links(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
return sprintf(buf, "%u\n", bond->params.min_links);
}
static ssize_t bonding_show_ad_select(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
const struct bond_opt_value *val;
val = bond_opt_get_val(BOND_OPT_AD_SELECT, bond->params.ad_select);
return sprintf(buf, "%s %d\n", val->string, bond->params.ad_select);
}
static ssize_t bonding_show_num_peer_notif(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
return sprintf(buf, "%d\n", bond->params.num_peer_notif);
}
static ssize_t bonding_store_num_peer_notif(struct device *d,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct bonding *bond = to_bond(d);
int ret;
ret = bond_opt_tryset_rtnl(bond, BOND_OPT_NUM_PEER_NOTIF, (char *)buf);
if (!ret)
ret = count;
return ret;
}
static ssize_t bonding_show_miimon(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
return sprintf(buf, "%d\n", bond->params.miimon);
}
static ssize_t bonding_show_primary(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
struct slave *primary;
int count = 0;
rcu_read_lock();
primary = rcu_dereference(bond->primary_slave);
if (primary)
count = sprintf(buf, "%s\n", primary->dev->name);
rcu_read_unlock();
return count;
}
static ssize_t bonding_show_primary_reselect(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
const struct bond_opt_value *val;
val = bond_opt_get_val(BOND_OPT_PRIMARY_RESELECT,
bond->params.primary_reselect);
return sprintf(buf, "%s %d\n",
val->string, bond->params.primary_reselect);
}
static ssize_t bonding_show_carrier(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
return sprintf(buf, "%d\n", bond->params.use_carrier);
}
static ssize_t bonding_show_active_slave(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
struct net_device *slave_dev;
int count = 0;
rcu_read_lock();
slave_dev = bond_option_active_slave_get_rcu(bond);
if (slave_dev)
count = sprintf(buf, "%s\n", slave_dev->name);
rcu_read_unlock();
return count;
}
static ssize_t bonding_show_mii_status(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
bool active = !!rcu_access_pointer(bond->curr_active_slave);
return sprintf(buf, "%s\n", active ? "up" : "down");
}
static ssize_t bonding_show_ad_aggregator(struct device *d,
struct device_attribute *attr,
char *buf)
{
int count = 0;
struct bonding *bond = to_bond(d);
if (BOND_MODE(bond) == BOND_MODE_8023AD) {
struct ad_info ad_info;
count = sprintf(buf, "%d\n",
bond_3ad_get_active_agg_info(bond, &ad_info)
? 0 : ad_info.aggregator_id);
}
return count;
}
static ssize_t bonding_show_ad_num_ports(struct device *d,
struct device_attribute *attr,
char *buf)
{
int count = 0;
struct bonding *bond = to_bond(d);
if (BOND_MODE(bond) == BOND_MODE_8023AD) {
struct ad_info ad_info;
count = sprintf(buf, "%d\n",
bond_3ad_get_active_agg_info(bond, &ad_info)
? 0 : ad_info.ports);
}
return count;
}
static ssize_t bonding_show_ad_actor_key(struct device *d,
struct device_attribute *attr,
char *buf)
{
int count = 0;
struct bonding *bond = to_bond(d);
if (BOND_MODE(bond) == BOND_MODE_8023AD) {
struct ad_info ad_info;
count = sprintf(buf, "%d\n",
bond_3ad_get_active_agg_info(bond, &ad_info)
? 0 : ad_info.actor_key);
}
return count;
}
static ssize_t bonding_show_ad_partner_key(struct device *d,
struct device_attribute *attr,
char *buf)
{
int count = 0;
struct bonding *bond = to_bond(d);
if (BOND_MODE(bond) == BOND_MODE_8023AD) {
struct ad_info ad_info;
count = sprintf(buf, "%d\n",
bond_3ad_get_active_agg_info(bond, &ad_info)
? 0 : ad_info.partner_key);
}
return count;
}
static ssize_t bonding_show_ad_partner_mac(struct device *d,
struct device_attribute *attr,
char *buf)
{
int count = 0;
struct bonding *bond = to_bond(d);
if (BOND_MODE(bond) == BOND_MODE_8023AD) {
struct ad_info ad_info;
if (!bond_3ad_get_active_agg_info(bond, &ad_info))
count = sprintf(buf, "%pM\n", ad_info.partner_system);
}
return count;
}
static ssize_t bonding_show_queue_id(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
struct list_head *iter;
struct slave *slave;
int res = 0;
if (!rtnl_trylock())
return restart_syscall();
bond_for_each_slave(bond, slave, iter) {
if (res > (PAGE_SIZE - IFNAMSIZ - 6)) {
if ((PAGE_SIZE - res) > 10)
res = PAGE_SIZE - 10;
res += sprintf(buf + res, "++more++ ");
break;
}
res += sprintf(buf + res, "%s:%d ",
slave->dev->name, slave->queue_id);
}
if (res)
buf[res-1] = '\n';
rtnl_unlock();
return res;
}
static ssize_t bonding_show_slaves_active(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
return sprintf(buf, "%d\n", bond->params.all_slaves_active);
}
static ssize_t bonding_show_resend_igmp(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
return sprintf(buf, "%d\n", bond->params.resend_igmp);
}
static ssize_t bonding_show_lp_interval(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
return sprintf(buf, "%d\n", bond->params.lp_interval);
}
static ssize_t bonding_show_tlb_dynamic_lb(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
return sprintf(buf, "%d\n", bond->params.tlb_dynamic_lb);
}
static ssize_t bonding_show_packets_per_slave(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct bonding *bond = to_bond(d);
unsigned int packets_per_slave = bond->params.packets_per_slave;
return sprintf(buf, "%u\n", packets_per_slave);
}
int bond_create_sysfs(struct bond_net *bn)
{
int ret;
bn->class_attr_bonding_masters = class_attr_bonding_masters;
sysfs_attr_init(&bn->class_attr_bonding_masters.attr);
ret = netdev_class_create_file_ns(&bn->class_attr_bonding_masters,
bn->net);
if (ret == -EEXIST) {
if (__dev_get_by_name(bn->net,
class_attr_bonding_masters.attr.name))
pr_err("network device named %s already exists in sysfs\n",
class_attr_bonding_masters.attr.name);
ret = 0;
}
return ret;
}
void bond_destroy_sysfs(struct bond_net *bn)
{
netdev_class_remove_file_ns(&bn->class_attr_bonding_masters, bn->net);
}
void bond_prepare_sysfs_group(struct bonding *bond)
{
bond->dev->sysfs_groups[0] = &bonding_group;
}
