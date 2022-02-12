struct bond_opt_value *bond_opt_get_val(unsigned int option, u64 val)
{
struct bond_option *opt;
int i;
opt = bond_opt_get(option);
if (WARN_ON(!opt))
return NULL;
for (i = 0; opt->values && opt->values[i].string; i++)
if (opt->values[i].value == val)
return &opt->values[i];
return NULL;
}
static struct bond_opt_value *bond_opt_get_flags(const struct bond_option *opt,
u32 flagmask)
{
int i;
for (i = 0; opt->values && opt->values[i].string; i++)
if (opt->values[i].flags & flagmask)
return &opt->values[i];
return NULL;
}
static bool bond_opt_check_range(const struct bond_option *opt, u64 val)
{
struct bond_opt_value *minval, *maxval;
minval = bond_opt_get_flags(opt, BOND_VALFLAG_MIN);
maxval = bond_opt_get_flags(opt, BOND_VALFLAG_MAX);
if (!maxval || (minval && val < minval->value) || val > maxval->value)
return false;
return true;
}
struct bond_opt_value *bond_opt_parse(const struct bond_option *opt,
struct bond_opt_value *val)
{
char *p, valstr[BOND_OPT_MAX_NAMELEN + 1] = { 0, };
struct bond_opt_value *tbl, *ret = NULL;
bool checkval;
int i, rv;
if (opt->flags & BOND_OPTFLAG_RAWVAL)
return val;
tbl = opt->values;
if (!tbl)
goto out;
checkval = val->value != ULLONG_MAX;
if (!checkval) {
if (!val->string)
goto out;
p = strchr(val->string, '\n');
if (p)
*p = '\0';
for (p = val->string; *p; p++)
if (!(isdigit(*p) || isspace(*p)))
break;
if (*p) {
rv = sscanf(val->string, "%32s", valstr);
} else {
rv = sscanf(val->string, "%llu", &val->value);
checkval = true;
}
if (!rv)
goto out;
}
for (i = 0; tbl[i].string; i++) {
if (checkval) {
if (val->value == tbl[i].value)
ret = &tbl[i];
} else {
if (!strcmp(valstr, "default") &&
(tbl[i].flags & BOND_VALFLAG_DEFAULT))
ret = &tbl[i];
if (!strcmp(valstr, tbl[i].string))
ret = &tbl[i];
}
if (ret)
goto out;
}
if (checkval && bond_opt_check_range(opt, val->value))
ret = val;
out:
return ret;
}
static int bond_opt_check_deps(struct bonding *bond,
const struct bond_option *opt)
{
struct bond_params *params = &bond->params;
if (test_bit(params->mode, &opt->unsuppmodes))
return -EACCES;
if ((opt->flags & BOND_OPTFLAG_NOSLAVES) && bond_has_slaves(bond))
return -ENOTEMPTY;
if ((opt->flags & BOND_OPTFLAG_IFDOWN) && (bond->dev->flags & IFF_UP))
return -EBUSY;
return 0;
}
static void bond_opt_dep_print(struct bonding *bond,
const struct bond_option *opt)
{
struct bond_opt_value *modeval;
struct bond_params *params;
params = &bond->params;
modeval = bond_opt_get_val(BOND_OPT_MODE, params->mode);
if (test_bit(params->mode, &opt->unsuppmodes))
pr_err("%s: option %s: mode dependency failed, not supported in mode %s(%llu)\n",
bond->dev->name, opt->name,
modeval->string, modeval->value);
}
static void bond_opt_error_interpret(struct bonding *bond,
const struct bond_option *opt,
int error, struct bond_opt_value *val)
{
struct bond_opt_value *minval, *maxval;
char *p;
switch (error) {
case -EINVAL:
if (val) {
if (val->string) {
p = strchr(val->string, '\n');
if (p)
*p = '\0';
pr_err("%s: option %s: invalid value (%s).\n",
bond->dev->name, opt->name, val->string);
} else {
pr_err("%s: option %s: invalid value (%llu).\n",
bond->dev->name, opt->name, val->value);
}
}
minval = bond_opt_get_flags(opt, BOND_VALFLAG_MIN);
maxval = bond_opt_get_flags(opt, BOND_VALFLAG_MAX);
if (!maxval)
break;
pr_err("%s: option %s: allowed values %llu - %llu.\n",
bond->dev->name, opt->name, minval ? minval->value : 0,
maxval->value);
break;
case -EACCES:
bond_opt_dep_print(bond, opt);
break;
case -ENOTEMPTY:
pr_err("%s: option %s: unable to set because the bond device has slaves.\n",
bond->dev->name, opt->name);
break;
case -EBUSY:
pr_err("%s: option %s: unable to set because the bond device is up.\n",
bond->dev->name, opt->name);
break;
default:
break;
}
}
int __bond_opt_set(struct bonding *bond,
unsigned int option, struct bond_opt_value *val)
{
struct bond_opt_value *retval = NULL;
const struct bond_option *opt;
int ret = -ENOENT;
ASSERT_RTNL();
opt = bond_opt_get(option);
if (WARN_ON(!val) || WARN_ON(!opt))
goto out;
ret = bond_opt_check_deps(bond, opt);
if (ret)
goto out;
retval = bond_opt_parse(opt, val);
if (!retval) {
ret = -EINVAL;
goto out;
}
ret = opt->set(bond, retval);
out:
if (ret)
bond_opt_error_interpret(bond, opt, ret, val);
return ret;
}
int bond_opt_tryset_rtnl(struct bonding *bond, unsigned int option, char *buf)
{
struct bond_opt_value optval;
int ret;
if (!rtnl_trylock())
return restart_syscall();
bond_opt_initstr(&optval, buf);
ret = __bond_opt_set(bond, option, &optval);
rtnl_unlock();
return ret;
}
struct bond_option *bond_opt_get(unsigned int option)
{
if (!BOND_OPT_VALID(option))
return NULL;
return &bond_opts[option];
}
int bond_option_mode_set(struct bonding *bond, struct bond_opt_value *newval)
{
if (BOND_NO_USES_ARP(newval->value) && bond->params.arp_interval) {
pr_info("%s: %s mode is incompatible with arp monitoring, start mii monitoring\n",
bond->dev->name, newval->string);
bond->params.arp_interval = 0;
bond->params.miimon = BOND_DEFAULT_MIIMON;
pr_info("%s: Setting MII monitoring interval to %d.\n",
bond->dev->name, bond->params.miimon);
}
bond->params.arp_validate = BOND_ARP_VALIDATE_NONE;
bond->params.mode = newval->value;
return 0;
}
static struct net_device *__bond_option_active_slave_get(struct bonding *bond,
struct slave *slave)
{
return USES_PRIMARY(bond->params.mode) && slave ? slave->dev : NULL;
}
struct net_device *bond_option_active_slave_get_rcu(struct bonding *bond)
{
struct slave *slave = rcu_dereference(bond->curr_active_slave);
return __bond_option_active_slave_get(bond, slave);
}
struct net_device *bond_option_active_slave_get(struct bonding *bond)
{
return __bond_option_active_slave_get(bond, bond->curr_active_slave);
}
int bond_option_active_slave_set(struct bonding *bond,
struct bond_opt_value *newval)
{
char ifname[IFNAMSIZ] = { 0, };
struct net_device *slave_dev;
int ret = 0;
sscanf(newval->string, "%15s", ifname);
if (!strlen(ifname) || newval->string[0] == '\n') {
slave_dev = NULL;
} else {
slave_dev = __dev_get_by_name(dev_net(bond->dev), ifname);
if (!slave_dev)
return -ENODEV;
}
if (slave_dev) {
if (!netif_is_bond_slave(slave_dev)) {
pr_err("Device %s is not bonding slave.\n",
slave_dev->name);
return -EINVAL;
}
if (bond->dev != netdev_master_upper_dev_get(slave_dev)) {
pr_err("%s: Device %s is not our slave.\n",
bond->dev->name, slave_dev->name);
return -EINVAL;
}
}
block_netpoll_tx();
write_lock_bh(&bond->curr_slave_lock);
if (!slave_dev) {
pr_info("%s: Clearing current active slave.\n",
bond->dev->name);
rcu_assign_pointer(bond->curr_active_slave, NULL);
bond_select_active_slave(bond);
} else {
struct slave *old_active = bond->curr_active_slave;
struct slave *new_active = bond_slave_get_rtnl(slave_dev);
BUG_ON(!new_active);
if (new_active == old_active) {
pr_info("%s: %s is already the current active slave.\n",
bond->dev->name, new_active->dev->name);
} else {
if (old_active && (new_active->link == BOND_LINK_UP) &&
IS_UP(new_active->dev)) {
pr_info("%s: Setting %s as active slave.\n",
bond->dev->name, new_active->dev->name);
bond_change_active_slave(bond, new_active);
} else {
pr_err("%s: Could not set %s as active slave; either %s is down or the link is down.\n",
bond->dev->name, new_active->dev->name,
new_active->dev->name);
ret = -EINVAL;
}
}
}
write_unlock_bh(&bond->curr_slave_lock);
unblock_netpoll_tx();
return ret;
}
int bond_option_miimon_set(struct bonding *bond, struct bond_opt_value *newval)
{
pr_info("%s: Setting MII monitoring interval to %llu.\n",
bond->dev->name, newval->value);
bond->params.miimon = newval->value;
if (bond->params.updelay)
pr_info("%s: Note: Updating updelay (to %d) since it is a multiple of the miimon value.\n",
bond->dev->name,
bond->params.updelay * bond->params.miimon);
if (bond->params.downdelay)
pr_info("%s: Note: Updating downdelay (to %d) since it is a multiple of the miimon value.\n",
bond->dev->name,
bond->params.downdelay * bond->params.miimon);
if (newval->value && bond->params.arp_interval) {
pr_info("%s: MII monitoring cannot be used with ARP monitoring. Disabling ARP monitoring...\n",
bond->dev->name);
bond->params.arp_interval = 0;
if (bond->params.arp_validate)
bond->params.arp_validate = BOND_ARP_VALIDATE_NONE;
}
if (bond->dev->flags & IFF_UP) {
if (!newval->value) {
cancel_delayed_work_sync(&bond->mii_work);
} else {
cancel_delayed_work_sync(&bond->arp_work);
queue_delayed_work(bond->wq, &bond->mii_work, 0);
}
}
return 0;
}
int bond_option_updelay_set(struct bonding *bond, struct bond_opt_value *newval)
{
int value = newval->value;
if (!bond->params.miimon) {
pr_err("%s: Unable to set up delay as MII monitoring is disabled\n",
bond->dev->name);
return -EPERM;
}
if ((value % bond->params.miimon) != 0) {
pr_warn("%s: Warning: up delay (%d) is not a multiple of miimon (%d), updelay rounded to %d ms\n",
bond->dev->name, value,
bond->params.miimon,
(value / bond->params.miimon) *
bond->params.miimon);
}
bond->params.updelay = value / bond->params.miimon;
pr_info("%s: Setting up delay to %d.\n",
bond->dev->name,
bond->params.updelay * bond->params.miimon);
return 0;
}
int bond_option_downdelay_set(struct bonding *bond,
struct bond_opt_value *newval)
{
int value = newval->value;
if (!bond->params.miimon) {
pr_err("%s: Unable to set down delay as MII monitoring is disabled\n",
bond->dev->name);
return -EPERM;
}
if ((value % bond->params.miimon) != 0) {
pr_warn("%s: Warning: down delay (%d) is not a multiple of miimon (%d), delay rounded to %d ms\n",
bond->dev->name, value,
bond->params.miimon,
(value / bond->params.miimon) *
bond->params.miimon);
}
bond->params.downdelay = value / bond->params.miimon;
pr_info("%s: Setting down delay to %d.\n",
bond->dev->name,
bond->params.downdelay * bond->params.miimon);
return 0;
}
int bond_option_use_carrier_set(struct bonding *bond,
struct bond_opt_value *newval)
{
pr_info("%s: Setting use_carrier to %llu.\n",
bond->dev->name, newval->value);
bond->params.use_carrier = newval->value;
return 0;
}
int bond_option_arp_interval_set(struct bonding *bond,
struct bond_opt_value *newval)
{
pr_info("%s: Setting ARP monitoring interval to %llu.\n",
bond->dev->name, newval->value);
bond->params.arp_interval = newval->value;
if (newval->value) {
if (bond->params.miimon) {
pr_info("%s: ARP monitoring cannot be used with MII monitoring. %s Disabling MII monitoring.\n",
bond->dev->name, bond->dev->name);
bond->params.miimon = 0;
}
if (!bond->params.arp_targets[0])
pr_info("%s: ARP monitoring has been set up, but no ARP targets have been specified.\n",
bond->dev->name);
}
if (bond->dev->flags & IFF_UP) {
if (!newval->value) {
if (bond->params.arp_validate)
bond->recv_probe = NULL;
cancel_delayed_work_sync(&bond->arp_work);
} else {
if (bond->params.arp_validate)
bond->recv_probe = bond_arp_rcv;
cancel_delayed_work_sync(&bond->mii_work);
queue_delayed_work(bond->wq, &bond->arp_work, 0);
}
}
return 0;
}
static void _bond_options_arp_ip_target_set(struct bonding *bond, int slot,
__be32 target,
unsigned long last_rx)
{
__be32 *targets = bond->params.arp_targets;
struct list_head *iter;
struct slave *slave;
if (slot >= 0 && slot < BOND_MAX_ARP_TARGETS) {
bond_for_each_slave(bond, slave, iter)
slave->target_last_arp_rx[slot] = last_rx;
targets[slot] = target;
}
}
static int _bond_option_arp_ip_target_add(struct bonding *bond, __be32 target)
{
__be32 *targets = bond->params.arp_targets;
int ind;
if (IS_IP_TARGET_UNUSABLE_ADDRESS(target)) {
pr_err("%s: invalid ARP target %pI4 specified for addition\n",
bond->dev->name, &target);
return -EINVAL;
}
if (bond_get_targets_ip(targets, target) != -1) {
pr_err("%s: ARP target %pI4 is already present\n",
bond->dev->name, &target);
return -EINVAL;
}
ind = bond_get_targets_ip(targets, 0);
if (ind == -1) {
pr_err("%s: ARP target table is full!\n",
bond->dev->name);
return -EINVAL;
}
pr_info("%s: adding ARP target %pI4.\n", bond->dev->name, &target);
_bond_options_arp_ip_target_set(bond, ind, target, jiffies);
return 0;
}
int bond_option_arp_ip_target_add(struct bonding *bond, __be32 target)
{
int ret;
write_lock_bh(&bond->lock);
ret = _bond_option_arp_ip_target_add(bond, target);
write_unlock_bh(&bond->lock);
return ret;
}
int bond_option_arp_ip_target_rem(struct bonding *bond, __be32 target)
{
__be32 *targets = bond->params.arp_targets;
struct list_head *iter;
struct slave *slave;
unsigned long *targets_rx;
int ind, i;
if (IS_IP_TARGET_UNUSABLE_ADDRESS(target)) {
pr_err("%s: invalid ARP target %pI4 specified for removal\n",
bond->dev->name, &target);
return -EINVAL;
}
ind = bond_get_targets_ip(targets, target);
if (ind == -1) {
pr_err("%s: unable to remove nonexistent ARP target %pI4.\n",
bond->dev->name, &target);
return -EINVAL;
}
if (ind == 0 && !targets[1] && bond->params.arp_interval)
pr_warn("%s: removing last arp target with arp_interval on\n",
bond->dev->name);
pr_info("%s: removing ARP target %pI4.\n", bond->dev->name,
&target);
write_lock_bh(&bond->lock);
bond_for_each_slave(bond, slave, iter) {
targets_rx = slave->target_last_arp_rx;
for (i = ind; (i < BOND_MAX_ARP_TARGETS-1) && targets[i+1]; i++)
targets_rx[i] = targets_rx[i+1];
targets_rx[i] = 0;
}
for (i = ind; (i < BOND_MAX_ARP_TARGETS-1) && targets[i+1]; i++)
targets[i] = targets[i+1];
targets[i] = 0;
write_unlock_bh(&bond->lock);
return 0;
}
void bond_option_arp_ip_targets_clear(struct bonding *bond)
{
int i;
write_lock_bh(&bond->lock);
for (i = 0; i < BOND_MAX_ARP_TARGETS; i++)
_bond_options_arp_ip_target_set(bond, i, 0, 0);
write_unlock_bh(&bond->lock);
}
int bond_option_arp_ip_targets_set(struct bonding *bond,
struct bond_opt_value *newval)
{
int ret = -EPERM;
__be32 target;
if (newval->string) {
if (!in4_pton(newval->string+1, -1, (u8 *)&target, -1, NULL)) {
pr_err("%s: invalid ARP target %pI4 specified\n",
bond->dev->name, &target);
return ret;
}
if (newval->string[0] == '+')
ret = bond_option_arp_ip_target_add(bond, target);
else if (newval->string[0] == '-')
ret = bond_option_arp_ip_target_rem(bond, target);
else
pr_err("no command found in arp_ip_targets file for bond %s. Use +<addr> or -<addr>.\n",
bond->dev->name);
} else {
target = newval->value;
ret = bond_option_arp_ip_target_add(bond, target);
}
return ret;
}
int bond_option_arp_validate_set(struct bonding *bond,
struct bond_opt_value *newval)
{
pr_info("%s: setting arp_validate to %s (%llu).\n",
bond->dev->name, newval->string, newval->value);
if (bond->dev->flags & IFF_UP) {
if (!newval->value)
bond->recv_probe = NULL;
else if (bond->params.arp_interval)
bond->recv_probe = bond_arp_rcv;
}
bond->params.arp_validate = newval->value;
return 0;
}
int bond_option_arp_all_targets_set(struct bonding *bond,
struct bond_opt_value *newval)
{
pr_info("%s: setting arp_all_targets to %s (%llu).\n",
bond->dev->name, newval->string, newval->value);
bond->params.arp_all_targets = newval->value;
return 0;
}
int bond_option_primary_set(struct bonding *bond, struct bond_opt_value *newval)
{
char *p, *primary = newval->string;
struct list_head *iter;
struct slave *slave;
block_netpoll_tx();
read_lock(&bond->lock);
write_lock_bh(&bond->curr_slave_lock);
p = strchr(primary, '\n');
if (p)
*p = '\0';
if (!strlen(primary)) {
pr_info("%s: Setting primary slave to None.\n",
bond->dev->name);
bond->primary_slave = NULL;
memset(bond->params.primary, 0, sizeof(bond->params.primary));
bond_select_active_slave(bond);
goto out;
}
bond_for_each_slave(bond, slave, iter) {
if (strncmp(slave->dev->name, primary, IFNAMSIZ) == 0) {
pr_info("%s: Setting %s as primary slave.\n",
bond->dev->name, slave->dev->name);
bond->primary_slave = slave;
strcpy(bond->params.primary, slave->dev->name);
bond_select_active_slave(bond);
goto out;
}
}
if (bond->primary_slave) {
pr_info("%s: Setting primary slave to None.\n",
bond->dev->name);
bond->primary_slave = NULL;
bond_select_active_slave(bond);
}
strncpy(bond->params.primary, primary, IFNAMSIZ);
bond->params.primary[IFNAMSIZ - 1] = 0;
pr_info("%s: Recording %s as primary, but it has not been enslaved to %s yet.\n",
bond->dev->name, primary, bond->dev->name);
out:
write_unlock_bh(&bond->curr_slave_lock);
read_unlock(&bond->lock);
unblock_netpoll_tx();
return 0;
}
int bond_option_primary_reselect_set(struct bonding *bond,
struct bond_opt_value *newval)
{
pr_info("%s: setting primary_reselect to %s (%llu).\n",
bond->dev->name, newval->string, newval->value);
bond->params.primary_reselect = newval->value;
block_netpoll_tx();
write_lock_bh(&bond->curr_slave_lock);
bond_select_active_slave(bond);
write_unlock_bh(&bond->curr_slave_lock);
unblock_netpoll_tx();
return 0;
}
int bond_option_fail_over_mac_set(struct bonding *bond,
struct bond_opt_value *newval)
{
pr_info("%s: Setting fail_over_mac to %s (%llu).\n",
bond->dev->name, newval->string, newval->value);
bond->params.fail_over_mac = newval->value;
return 0;
}
int bond_option_xmit_hash_policy_set(struct bonding *bond,
struct bond_opt_value *newval)
{
pr_info("%s: setting xmit hash policy to %s (%llu).\n",
bond->dev->name, newval->string, newval->value);
bond->params.xmit_policy = newval->value;
return 0;
}
int bond_option_resend_igmp_set(struct bonding *bond,
struct bond_opt_value *newval)
{
pr_info("%s: Setting resend_igmp to %llu.\n",
bond->dev->name, newval->value);
bond->params.resend_igmp = newval->value;
return 0;
}
int bond_option_num_peer_notif_set(struct bonding *bond,
struct bond_opt_value *newval)
{
bond->params.num_peer_notif = newval->value;
return 0;
}
int bond_option_all_slaves_active_set(struct bonding *bond,
struct bond_opt_value *newval)
{
struct list_head *iter;
struct slave *slave;
if (newval->value == bond->params.all_slaves_active)
return 0;
bond->params.all_slaves_active = newval->value;
bond_for_each_slave(bond, slave, iter) {
if (!bond_is_active_slave(slave)) {
if (newval->value)
slave->inactive = 0;
else
slave->inactive = 1;
}
}
return 0;
}
int bond_option_min_links_set(struct bonding *bond,
struct bond_opt_value *newval)
{
pr_info("%s: Setting min links value to %llu\n",
bond->dev->name, newval->value);
bond->params.min_links = newval->value;
return 0;
}
int bond_option_lp_interval_set(struct bonding *bond,
struct bond_opt_value *newval)
{
bond->params.lp_interval = newval->value;
return 0;
}
int bond_option_pps_set(struct bonding *bond, struct bond_opt_value *newval)
{
bond->params.packets_per_slave = newval->value;
if (newval->value > 0) {
bond->params.reciprocal_packets_per_slave =
reciprocal_value(newval->value);
} else {
bond->params.reciprocal_packets_per_slave =
(struct reciprocal_value) { 0 };
}
return 0;
}
int bond_option_lacp_rate_set(struct bonding *bond,
struct bond_opt_value *newval)
{
pr_info("%s: Setting LACP rate to %s (%llu).\n",
bond->dev->name, newval->string, newval->value);
bond->params.lacp_fast = newval->value;
bond_3ad_update_lacp_rate(bond);
return 0;
}
int bond_option_ad_select_set(struct bonding *bond,
struct bond_opt_value *newval)
{
pr_info("%s: Setting ad_select to %s (%llu).\n",
bond->dev->name, newval->string, newval->value);
bond->params.ad_select = newval->value;
return 0;
}
int bond_option_queue_id_set(struct bonding *bond,
struct bond_opt_value *newval)
{
struct slave *slave, *update_slave;
struct net_device *sdev;
struct list_head *iter;
char *delim;
int ret = 0;
u16 qid;
delim = strchr(newval->string, ':');
if (!delim)
goto err_no_cmd;
*delim = '\0';
if (sscanf(++delim, "%hd\n", &qid) != 1)
goto err_no_cmd;
if (strlen(newval->string) > IFNAMSIZ ||
!dev_valid_name(newval->string) ||
qid > bond->dev->real_num_tx_queues)
goto err_no_cmd;
sdev = __dev_get_by_name(dev_net(bond->dev), newval->string);
if (!sdev)
goto err_no_cmd;
update_slave = NULL;
bond_for_each_slave(bond, slave, iter) {
if (sdev == slave->dev)
update_slave = slave;
else if (qid && qid == slave->queue_id) {
goto err_no_cmd;
}
}
if (!update_slave)
goto err_no_cmd;
update_slave->queue_id = qid;
out:
return ret;
err_no_cmd:
pr_info("invalid input for queue_id set for %s.\n",
bond->dev->name);
ret = -EPERM;
goto out;
}
int bond_option_slaves_set(struct bonding *bond, struct bond_opt_value *newval)
{
char command[IFNAMSIZ + 1] = { 0, };
struct net_device *dev;
char *ifname;
int ret;
sscanf(newval->string, "%16s", command);
ifname = command + 1;
if ((strlen(command) <= 1) ||
!dev_valid_name(ifname))
goto err_no_cmd;
dev = __dev_get_by_name(dev_net(bond->dev), ifname);
if (!dev) {
pr_info("%s: Interface %s does not exist!\n",
bond->dev->name, ifname);
ret = -ENODEV;
goto out;
}
switch (command[0]) {
case '+':
pr_info("%s: Adding slave %s.\n", bond->dev->name, dev->name);
ret = bond_enslave(bond->dev, dev);
break;
case '-':
pr_info("%s: Removing slave %s.\n", bond->dev->name, dev->name);
ret = bond_release(bond->dev, dev);
break;
default:
goto err_no_cmd;
}
out:
return ret;
err_no_cmd:
pr_err("no command found in slaves file for bond %s. Use +ifname or -ifname.\n",
bond->dev->name);
ret = -EPERM;
goto out;
}
