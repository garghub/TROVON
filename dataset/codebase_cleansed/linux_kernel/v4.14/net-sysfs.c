static inline int dev_isalive(const struct net_device *dev)
{
return dev->reg_state <= NETREG_REGISTERED;
}
static ssize_t netdev_show(const struct device *dev,
struct device_attribute *attr, char *buf,
ssize_t (*format)(const struct net_device *, char *))
{
struct net_device *ndev = to_net_dev(dev);
ssize_t ret = -EINVAL;
read_lock(&dev_base_lock);
if (dev_isalive(ndev))
ret = (*format)(ndev, buf);
read_unlock(&dev_base_lock);
return ret;
}
static ssize_t netdev_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t len,
int (*set)(struct net_device *, unsigned long))
{
struct net_device *netdev = to_net_dev(dev);
struct net *net = dev_net(netdev);
unsigned long new;
int ret = -EINVAL;
if (!ns_capable(net->user_ns, CAP_NET_ADMIN))
return -EPERM;
ret = kstrtoul(buf, 0, &new);
if (ret)
goto err;
if (!rtnl_trylock())
return restart_syscall();
if (dev_isalive(netdev)) {
ret = (*set)(netdev, new);
if (ret == 0)
ret = len;
}
rtnl_unlock();
err:
return ret;
}
static ssize_t iflink_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct net_device *ndev = to_net_dev(dev);
return sprintf(buf, fmt_dec, dev_get_iflink(ndev));
}
static ssize_t format_name_assign_type(const struct net_device *dev, char *buf)
{
return sprintf(buf, fmt_dec, dev->name_assign_type);
}
static ssize_t name_assign_type_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct net_device *ndev = to_net_dev(dev);
ssize_t ret = -EINVAL;
if (ndev->name_assign_type != NET_NAME_UNKNOWN)
ret = netdev_show(dev, attr, buf, format_name_assign_type);
return ret;
}
static ssize_t address_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct net_device *ndev = to_net_dev(dev);
ssize_t ret = -EINVAL;
read_lock(&dev_base_lock);
if (dev_isalive(ndev))
ret = sysfs_format_mac(buf, ndev->dev_addr, ndev->addr_len);
read_unlock(&dev_base_lock);
return ret;
}
static ssize_t broadcast_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct net_device *ndev = to_net_dev(dev);
if (dev_isalive(ndev))
return sysfs_format_mac(buf, ndev->broadcast, ndev->addr_len);
return -EINVAL;
}
static int change_carrier(struct net_device *dev, unsigned long new_carrier)
{
if (!netif_running(dev))
return -EINVAL;
return dev_change_carrier(dev, (bool)new_carrier);
}
static ssize_t carrier_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t len)
{
return netdev_store(dev, attr, buf, len, change_carrier);
}
static ssize_t carrier_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct net_device *netdev = to_net_dev(dev);
if (netif_running(netdev))
return sprintf(buf, fmt_dec, !!netif_carrier_ok(netdev));
return -EINVAL;
}
static ssize_t speed_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct net_device *netdev = to_net_dev(dev);
int ret = -EINVAL;
if (!rtnl_trylock())
return restart_syscall();
if (netif_running(netdev)) {
struct ethtool_link_ksettings cmd;
if (!__ethtool_get_link_ksettings(netdev, &cmd))
ret = sprintf(buf, fmt_dec, cmd.base.speed);
}
rtnl_unlock();
return ret;
}
static ssize_t duplex_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct net_device *netdev = to_net_dev(dev);
int ret = -EINVAL;
if (!rtnl_trylock())
return restart_syscall();
if (netif_running(netdev)) {
struct ethtool_link_ksettings cmd;
if (!__ethtool_get_link_ksettings(netdev, &cmd)) {
const char *duplex;
switch (cmd.base.duplex) {
case DUPLEX_HALF:
duplex = "half";
break;
case DUPLEX_FULL:
duplex = "full";
break;
default:
duplex = "unknown";
break;
}
ret = sprintf(buf, "%s\n", duplex);
}
}
rtnl_unlock();
return ret;
}
static ssize_t dormant_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct net_device *netdev = to_net_dev(dev);
if (netif_running(netdev))
return sprintf(buf, fmt_dec, !!netif_dormant(netdev));
return -EINVAL;
}
static ssize_t operstate_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
const struct net_device *netdev = to_net_dev(dev);
unsigned char operstate;
read_lock(&dev_base_lock);
operstate = netdev->operstate;
if (!netif_running(netdev))
operstate = IF_OPER_DOWN;
read_unlock(&dev_base_lock);
if (operstate >= ARRAY_SIZE(operstates))
return -EINVAL;
return sprintf(buf, "%s\n", operstates[operstate]);
}
static ssize_t carrier_changes_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct net_device *netdev = to_net_dev(dev);
return sprintf(buf, fmt_dec,
atomic_read(&netdev->carrier_changes));
}
static int change_mtu(struct net_device *dev, unsigned long new_mtu)
{
return dev_set_mtu(dev, (int)new_mtu);
}
static ssize_t mtu_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t len)
{
return netdev_store(dev, attr, buf, len, change_mtu);
}
static int change_flags(struct net_device *dev, unsigned long new_flags)
{
return dev_change_flags(dev, (unsigned int)new_flags);
}
static ssize_t flags_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t len)
{
return netdev_store(dev, attr, buf, len, change_flags);
}
static int change_tx_queue_len(struct net_device *dev, unsigned long new_len)
{
unsigned int orig_len = dev->tx_queue_len;
int res;
if (new_len != (unsigned int)new_len)
return -ERANGE;
if (new_len != orig_len) {
dev->tx_queue_len = new_len;
res = call_netdevice_notifiers(NETDEV_CHANGE_TX_QUEUE_LEN, dev);
res = notifier_to_errno(res);
if (res) {
netdev_err(dev,
"refused to change device tx_queue_len\n");
dev->tx_queue_len = orig_len;
return -EFAULT;
}
}
return 0;
}
static ssize_t tx_queue_len_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
if (!capable(CAP_NET_ADMIN))
return -EPERM;
return netdev_store(dev, attr, buf, len, change_tx_queue_len);
}
static int change_gro_flush_timeout(struct net_device *dev, unsigned long val)
{
dev->gro_flush_timeout = val;
return 0;
}
static ssize_t gro_flush_timeout_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
if (!capable(CAP_NET_ADMIN))
return -EPERM;
return netdev_store(dev, attr, buf, len, change_gro_flush_timeout);
}
static ssize_t ifalias_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t len)
{
struct net_device *netdev = to_net_dev(dev);
struct net *net = dev_net(netdev);
size_t count = len;
ssize_t ret;
if (!ns_capable(net->user_ns, CAP_NET_ADMIN))
return -EPERM;
if (len > 0 && buf[len - 1] == '\n')
--count;
if (!rtnl_trylock())
return restart_syscall();
ret = dev_set_alias(netdev, buf, count);
rtnl_unlock();
return ret < 0 ? ret : len;
}
static ssize_t ifalias_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
const struct net_device *netdev = to_net_dev(dev);
ssize_t ret = 0;
if (!rtnl_trylock())
return restart_syscall();
if (netdev->ifalias)
ret = sprintf(buf, "%s\n", netdev->ifalias);
rtnl_unlock();
return ret;
}
static int change_group(struct net_device *dev, unsigned long new_group)
{
dev_set_group(dev, (int)new_group);
return 0;
}
static ssize_t group_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t len)
{
return netdev_store(dev, attr, buf, len, change_group);
}
static int change_proto_down(struct net_device *dev, unsigned long proto_down)
{
return dev_change_proto_down(dev, (bool)proto_down);
}
static ssize_t proto_down_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
return netdev_store(dev, attr, buf, len, change_proto_down);
}
static ssize_t phys_port_id_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct net_device *netdev = to_net_dev(dev);
ssize_t ret = -EINVAL;
if (!rtnl_trylock())
return restart_syscall();
if (dev_isalive(netdev)) {
struct netdev_phys_item_id ppid;
ret = dev_get_phys_port_id(netdev, &ppid);
if (!ret)
ret = sprintf(buf, "%*phN\n", ppid.id_len, ppid.id);
}
rtnl_unlock();
return ret;
}
static ssize_t phys_port_name_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct net_device *netdev = to_net_dev(dev);
ssize_t ret = -EINVAL;
if (!rtnl_trylock())
return restart_syscall();
if (dev_isalive(netdev)) {
char name[IFNAMSIZ];
ret = dev_get_phys_port_name(netdev, name, sizeof(name));
if (!ret)
ret = sprintf(buf, "%s\n", name);
}
rtnl_unlock();
return ret;
}
static ssize_t phys_switch_id_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct net_device *netdev = to_net_dev(dev);
ssize_t ret = -EINVAL;
if (!rtnl_trylock())
return restart_syscall();
if (dev_isalive(netdev)) {
struct switchdev_attr attr = {
.orig_dev = netdev,
.id = SWITCHDEV_ATTR_ID_PORT_PARENT_ID,
.flags = SWITCHDEV_F_NO_RECURSE,
};
ret = switchdev_port_attr_get(netdev, &attr);
if (!ret)
ret = sprintf(buf, "%*phN\n", attr.u.ppid.id_len,
attr.u.ppid.id);
}
rtnl_unlock();
return ret;
}
static ssize_t netstat_show(const struct device *d,
struct device_attribute *attr, char *buf,
unsigned long offset)
{
struct net_device *dev = to_net_dev(d);
ssize_t ret = -EINVAL;
WARN_ON(offset > sizeof(struct rtnl_link_stats64) ||
offset % sizeof(u64) != 0);
read_lock(&dev_base_lock);
if (dev_isalive(dev)) {
struct rtnl_link_stats64 temp;
const struct rtnl_link_stats64 *stats = dev_get_stats(dev, &temp);
ret = sprintf(buf, fmt_u64, *(u64 *)(((u8 *)stats) + offset));
}
read_unlock(&dev_base_lock);
return ret;
}
static ssize_t rx_queue_attr_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
const struct rx_queue_attribute *attribute = to_rx_queue_attr(attr);
struct netdev_rx_queue *queue = to_rx_queue(kobj);
if (!attribute->show)
return -EIO;
return attribute->show(queue, buf);
}
static ssize_t rx_queue_attr_store(struct kobject *kobj, struct attribute *attr,
const char *buf, size_t count)
{
const struct rx_queue_attribute *attribute = to_rx_queue_attr(attr);
struct netdev_rx_queue *queue = to_rx_queue(kobj);
if (!attribute->store)
return -EIO;
return attribute->store(queue, buf, count);
}
static ssize_t show_rps_map(struct netdev_rx_queue *queue, char *buf)
{
struct rps_map *map;
cpumask_var_t mask;
int i, len;
if (!zalloc_cpumask_var(&mask, GFP_KERNEL))
return -ENOMEM;
rcu_read_lock();
map = rcu_dereference(queue->rps_map);
if (map)
for (i = 0; i < map->len; i++)
cpumask_set_cpu(map->cpus[i], mask);
len = snprintf(buf, PAGE_SIZE, "%*pb\n", cpumask_pr_args(mask));
rcu_read_unlock();
free_cpumask_var(mask);
return len < PAGE_SIZE ? len : -EINVAL;
}
static ssize_t store_rps_map(struct netdev_rx_queue *queue,
const char *buf, size_t len)
{
struct rps_map *old_map, *map;
cpumask_var_t mask;
int err, cpu, i;
static DEFINE_MUTEX(rps_map_mutex);
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (!alloc_cpumask_var(&mask, GFP_KERNEL))
return -ENOMEM;
err = bitmap_parse(buf, len, cpumask_bits(mask), nr_cpumask_bits);
if (err) {
free_cpumask_var(mask);
return err;
}
map = kzalloc(max_t(unsigned int,
RPS_MAP_SIZE(cpumask_weight(mask)), L1_CACHE_BYTES),
GFP_KERNEL);
if (!map) {
free_cpumask_var(mask);
return -ENOMEM;
}
i = 0;
for_each_cpu_and(cpu, mask, cpu_online_mask)
map->cpus[i++] = cpu;
if (i) {
map->len = i;
} else {
kfree(map);
map = NULL;
}
mutex_lock(&rps_map_mutex);
old_map = rcu_dereference_protected(queue->rps_map,
mutex_is_locked(&rps_map_mutex));
rcu_assign_pointer(queue->rps_map, map);
if (map)
static_key_slow_inc(&rps_needed);
if (old_map)
static_key_slow_dec(&rps_needed);
mutex_unlock(&rps_map_mutex);
if (old_map)
kfree_rcu(old_map, rcu);
free_cpumask_var(mask);
return len;
}
static ssize_t show_rps_dev_flow_table_cnt(struct netdev_rx_queue *queue,
char *buf)
{
struct rps_dev_flow_table *flow_table;
unsigned long val = 0;
rcu_read_lock();
flow_table = rcu_dereference(queue->rps_flow_table);
if (flow_table)
val = (unsigned long)flow_table->mask + 1;
rcu_read_unlock();
return sprintf(buf, "%lu\n", val);
}
static void rps_dev_flow_table_release(struct rcu_head *rcu)
{
struct rps_dev_flow_table *table = container_of(rcu,
struct rps_dev_flow_table, rcu);
vfree(table);
}
static ssize_t store_rps_dev_flow_table_cnt(struct netdev_rx_queue *queue,
const char *buf, size_t len)
{
unsigned long mask, count;
struct rps_dev_flow_table *table, *old_table;
static DEFINE_SPINLOCK(rps_dev_flow_lock);
int rc;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
rc = kstrtoul(buf, 0, &count);
if (rc < 0)
return rc;
if (count) {
mask = count - 1;
while ((mask | (mask >> 1)) != mask)
mask |= (mask >> 1);
#if BITS_PER_LONG > 32
if (mask > (unsigned long)(u32)mask)
return -EINVAL;
#else
if (mask > (ULONG_MAX - RPS_DEV_FLOW_TABLE_SIZE(1))
/ sizeof(struct rps_dev_flow)) {
return -EINVAL;
}
#endif
table = vmalloc(RPS_DEV_FLOW_TABLE_SIZE(mask + 1));
if (!table)
return -ENOMEM;
table->mask = mask;
for (count = 0; count <= mask; count++)
table->flows[count].cpu = RPS_NO_CPU;
} else {
table = NULL;
}
spin_lock(&rps_dev_flow_lock);
old_table = rcu_dereference_protected(queue->rps_flow_table,
lockdep_is_held(&rps_dev_flow_lock));
rcu_assign_pointer(queue->rps_flow_table, table);
spin_unlock(&rps_dev_flow_lock);
if (old_table)
call_rcu(&old_table->rcu, rps_dev_flow_table_release);
return len;
}
static void rx_queue_release(struct kobject *kobj)
{
struct netdev_rx_queue *queue = to_rx_queue(kobj);
#ifdef CONFIG_RPS
struct rps_map *map;
struct rps_dev_flow_table *flow_table;
map = rcu_dereference_protected(queue->rps_map, 1);
if (map) {
RCU_INIT_POINTER(queue->rps_map, NULL);
kfree_rcu(map, rcu);
}
flow_table = rcu_dereference_protected(queue->rps_flow_table, 1);
if (flow_table) {
RCU_INIT_POINTER(queue->rps_flow_table, NULL);
call_rcu(&flow_table->rcu, rps_dev_flow_table_release);
}
#endif
memset(kobj, 0, sizeof(*kobj));
dev_put(queue->dev);
}
static const void *rx_queue_namespace(struct kobject *kobj)
{
struct netdev_rx_queue *queue = to_rx_queue(kobj);
struct device *dev = &queue->dev->dev;
const void *ns = NULL;
if (dev->class && dev->class->ns_type)
ns = dev->class->namespace(dev);
return ns;
}
static int rx_queue_add_kobject(struct net_device *dev, int index)
{
struct netdev_rx_queue *queue = dev->_rx + index;
struct kobject *kobj = &queue->kobj;
int error = 0;
kobj->kset = dev->queues_kset;
error = kobject_init_and_add(kobj, &rx_queue_ktype, NULL,
"rx-%u", index);
if (error)
return error;
if (dev->sysfs_rx_queue_group) {
error = sysfs_create_group(kobj, dev->sysfs_rx_queue_group);
if (error) {
kobject_put(kobj);
return error;
}
}
kobject_uevent(kobj, KOBJ_ADD);
dev_hold(queue->dev);
return error;
}
int
net_rx_queue_update_kobjects(struct net_device *dev, int old_num, int new_num)
{
#ifdef CONFIG_SYSFS
int i;
int error = 0;
#ifndef CONFIG_RPS
if (!dev->sysfs_rx_queue_group)
return 0;
#endif
for (i = old_num; i < new_num; i++) {
error = rx_queue_add_kobject(dev, i);
if (error) {
new_num = old_num;
break;
}
}
while (--i >= new_num) {
struct kobject *kobj = &dev->_rx[i].kobj;
if (!atomic_read(&dev_net(dev)->count))
kobj->uevent_suppress = 1;
if (dev->sysfs_rx_queue_group)
sysfs_remove_group(kobj, dev->sysfs_rx_queue_group);
kobject_put(kobj);
}
return error;
#else
return 0;
#endif
}
static ssize_t netdev_queue_attr_show(struct kobject *kobj,
struct attribute *attr, char *buf)
{
const struct netdev_queue_attribute *attribute
= to_netdev_queue_attr(attr);
struct netdev_queue *queue = to_netdev_queue(kobj);
if (!attribute->show)
return -EIO;
return attribute->show(queue, buf);
}
static ssize_t netdev_queue_attr_store(struct kobject *kobj,
struct attribute *attr,
const char *buf, size_t count)
{
const struct netdev_queue_attribute *attribute
= to_netdev_queue_attr(attr);
struct netdev_queue *queue = to_netdev_queue(kobj);
if (!attribute->store)
return -EIO;
return attribute->store(queue, buf, count);
}
static ssize_t tx_timeout_show(struct netdev_queue *queue, char *buf)
{
unsigned long trans_timeout;
spin_lock_irq(&queue->_xmit_lock);
trans_timeout = queue->trans_timeout;
spin_unlock_irq(&queue->_xmit_lock);
return sprintf(buf, "%lu", trans_timeout);
}
static unsigned int get_netdev_queue_index(struct netdev_queue *queue)
{
struct net_device *dev = queue->dev;
unsigned int i;
i = queue - dev->_tx;
BUG_ON(i >= dev->num_tx_queues);
return i;
}
static ssize_t traffic_class_show(struct netdev_queue *queue,
char *buf)
{
struct net_device *dev = queue->dev;
int index = get_netdev_queue_index(queue);
int tc = netdev_txq_to_tc(dev, index);
if (tc < 0)
return -EINVAL;
return sprintf(buf, "%u\n", tc);
}
static ssize_t tx_maxrate_show(struct netdev_queue *queue,
char *buf)
{
return sprintf(buf, "%lu\n", queue->tx_maxrate);
}
static ssize_t tx_maxrate_store(struct netdev_queue *queue,
const char *buf, size_t len)
{
struct net_device *dev = queue->dev;
int err, index = get_netdev_queue_index(queue);
u32 rate = 0;
err = kstrtou32(buf, 10, &rate);
if (err < 0)
return err;
if (!rtnl_trylock())
return restart_syscall();
err = -EOPNOTSUPP;
if (dev->netdev_ops->ndo_set_tx_maxrate)
err = dev->netdev_ops->ndo_set_tx_maxrate(dev, index, rate);
rtnl_unlock();
if (!err) {
queue->tx_maxrate = rate;
return len;
}
return err;
}
static ssize_t bql_show(char *buf, unsigned int value)
{
return sprintf(buf, "%u\n", value);
}
static ssize_t bql_set(const char *buf, const size_t count,
unsigned int *pvalue)
{
unsigned int value;
int err;
if (!strcmp(buf, "max") || !strcmp(buf, "max\n")) {
value = DQL_MAX_LIMIT;
} else {
err = kstrtouint(buf, 10, &value);
if (err < 0)
return err;
if (value > DQL_MAX_LIMIT)
return -EINVAL;
}
*pvalue = value;
return count;
}
static ssize_t bql_show_hold_time(struct netdev_queue *queue,
char *buf)
{
struct dql *dql = &queue->dql;
return sprintf(buf, "%u\n", jiffies_to_msecs(dql->slack_hold_time));
}
static ssize_t bql_set_hold_time(struct netdev_queue *queue,
const char *buf, size_t len)
{
struct dql *dql = &queue->dql;
unsigned int value;
int err;
err = kstrtouint(buf, 10, &value);
if (err < 0)
return err;
dql->slack_hold_time = msecs_to_jiffies(value);
return len;
}
static ssize_t bql_show_inflight(struct netdev_queue *queue,
char *buf)
{
struct dql *dql = &queue->dql;
return sprintf(buf, "%u\n", dql->num_queued - dql->num_completed);
}
static ssize_t xps_cpus_show(struct netdev_queue *queue,
char *buf)
{
struct net_device *dev = queue->dev;
int cpu, len, num_tc = 1, tc = 0;
struct xps_dev_maps *dev_maps;
cpumask_var_t mask;
unsigned long index;
if (!zalloc_cpumask_var(&mask, GFP_KERNEL))
return -ENOMEM;
index = get_netdev_queue_index(queue);
if (dev->num_tc) {
num_tc = dev->num_tc;
tc = netdev_txq_to_tc(dev, index);
if (tc < 0)
return -EINVAL;
}
rcu_read_lock();
dev_maps = rcu_dereference(dev->xps_maps);
if (dev_maps) {
for_each_possible_cpu(cpu) {
int i, tci = cpu * num_tc + tc;
struct xps_map *map;
map = rcu_dereference(dev_maps->cpu_map[tci]);
if (!map)
continue;
for (i = map->len; i--;) {
if (map->queues[i] == index) {
cpumask_set_cpu(cpu, mask);
break;
}
}
}
}
rcu_read_unlock();
len = snprintf(buf, PAGE_SIZE, "%*pb\n", cpumask_pr_args(mask));
free_cpumask_var(mask);
return len < PAGE_SIZE ? len : -EINVAL;
}
static ssize_t xps_cpus_store(struct netdev_queue *queue,
const char *buf, size_t len)
{
struct net_device *dev = queue->dev;
unsigned long index;
cpumask_var_t mask;
int err;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (!alloc_cpumask_var(&mask, GFP_KERNEL))
return -ENOMEM;
index = get_netdev_queue_index(queue);
err = bitmap_parse(buf, len, cpumask_bits(mask), nr_cpumask_bits);
if (err) {
free_cpumask_var(mask);
return err;
}
err = netif_set_xps_queue(dev, mask, index);
free_cpumask_var(mask);
return err ? : len;
}
static void netdev_queue_release(struct kobject *kobj)
{
struct netdev_queue *queue = to_netdev_queue(kobj);
memset(kobj, 0, sizeof(*kobj));
dev_put(queue->dev);
}
static const void *netdev_queue_namespace(struct kobject *kobj)
{
struct netdev_queue *queue = to_netdev_queue(kobj);
struct device *dev = &queue->dev->dev;
const void *ns = NULL;
if (dev->class && dev->class->ns_type)
ns = dev->class->namespace(dev);
return ns;
}
static int netdev_queue_add_kobject(struct net_device *dev, int index)
{
struct netdev_queue *queue = dev->_tx + index;
struct kobject *kobj = &queue->kobj;
int error = 0;
kobj->kset = dev->queues_kset;
error = kobject_init_and_add(kobj, &netdev_queue_ktype, NULL,
"tx-%u", index);
if (error)
return error;
#ifdef CONFIG_BQL
error = sysfs_create_group(kobj, &dql_group);
if (error) {
kobject_put(kobj);
return error;
}
#endif
kobject_uevent(kobj, KOBJ_ADD);
dev_hold(queue->dev);
return 0;
}
int
netdev_queue_update_kobjects(struct net_device *dev, int old_num, int new_num)
{
#ifdef CONFIG_SYSFS
int i;
int error = 0;
for (i = old_num; i < new_num; i++) {
error = netdev_queue_add_kobject(dev, i);
if (error) {
new_num = old_num;
break;
}
}
while (--i >= new_num) {
struct netdev_queue *queue = dev->_tx + i;
if (!atomic_read(&dev_net(dev)->count))
queue->kobj.uevent_suppress = 1;
#ifdef CONFIG_BQL
sysfs_remove_group(&queue->kobj, &dql_group);
#endif
kobject_put(&queue->kobj);
}
return error;
#else
return 0;
#endif
}
static int register_queue_kobjects(struct net_device *dev)
{
int error = 0, txq = 0, rxq = 0, real_rx = 0, real_tx = 0;
#ifdef CONFIG_SYSFS
dev->queues_kset = kset_create_and_add("queues",
NULL, &dev->dev.kobj);
if (!dev->queues_kset)
return -ENOMEM;
real_rx = dev->real_num_rx_queues;
#endif
real_tx = dev->real_num_tx_queues;
error = net_rx_queue_update_kobjects(dev, 0, real_rx);
if (error)
goto error;
rxq = real_rx;
error = netdev_queue_update_kobjects(dev, 0, real_tx);
if (error)
goto error;
txq = real_tx;
return 0;
error:
netdev_queue_update_kobjects(dev, txq, 0);
net_rx_queue_update_kobjects(dev, rxq, 0);
return error;
}
static void remove_queue_kobjects(struct net_device *dev)
{
int real_rx = 0, real_tx = 0;
#ifdef CONFIG_SYSFS
real_rx = dev->real_num_rx_queues;
#endif
real_tx = dev->real_num_tx_queues;
net_rx_queue_update_kobjects(dev, real_rx, 0);
netdev_queue_update_kobjects(dev, real_tx, 0);
#ifdef CONFIG_SYSFS
kset_unregister(dev->queues_kset);
#endif
}
static bool net_current_may_mount(void)
{
struct net *net = current->nsproxy->net_ns;
return ns_capable(net->user_ns, CAP_SYS_ADMIN);
}
static void *net_grab_current_ns(void)
{
struct net *ns = current->nsproxy->net_ns;
#ifdef CONFIG_NET_NS
if (ns)
refcount_inc(&ns->passive);
#endif
return ns;
}
static const void *net_initial_ns(void)
{
return &init_net;
}
static const void *net_netlink_ns(struct sock *sk)
{
return sock_net(sk);
}
static int netdev_uevent(struct device *d, struct kobj_uevent_env *env)
{
struct net_device *dev = to_net_dev(d);
int retval;
retval = add_uevent_var(env, "INTERFACE=%s", dev->name);
if (retval)
goto exit;
retval = add_uevent_var(env, "IFINDEX=%d", dev->ifindex);
exit:
return retval;
}
static void netdev_release(struct device *d)
{
struct net_device *dev = to_net_dev(d);
BUG_ON(dev->reg_state != NETREG_RELEASED);
kfree(dev->ifalias);
netdev_freemem(dev);
}
static const void *net_namespace(struct device *d)
{
struct net_device *dev = to_net_dev(d);
return dev_net(dev);
}
static int of_dev_node_match(struct device *dev, const void *data)
{
int ret = 0;
if (dev->parent)
ret = dev->parent->of_node == data;
return ret == 0 ? dev->of_node == data : ret;
}
struct net_device *of_find_net_device_by_node(struct device_node *np)
{
struct device *dev;
dev = class_find_device(&net_class, NULL, np, of_dev_node_match);
if (!dev)
return NULL;
return to_net_dev(dev);
}
void netdev_unregister_kobject(struct net_device *ndev)
{
struct device *dev = &ndev->dev;
if (!atomic_read(&dev_net(ndev)->count))
dev_set_uevent_suppress(dev, 1);
kobject_get(&dev->kobj);
remove_queue_kobjects(ndev);
pm_runtime_set_memalloc_noio(dev, false);
device_del(dev);
}
int netdev_register_kobject(struct net_device *ndev)
{
struct device *dev = &ndev->dev;
const struct attribute_group **groups = ndev->sysfs_groups;
int error = 0;
device_initialize(dev);
dev->class = &net_class;
dev->platform_data = ndev;
dev->groups = groups;
dev_set_name(dev, "%s", ndev->name);
#ifdef CONFIG_SYSFS
if (*groups)
groups++;
*groups++ = &netstat_group;
#if IS_ENABLED(CONFIG_WIRELESS_EXT) || IS_ENABLED(CONFIG_CFG80211)
if (ndev->ieee80211_ptr)
*groups++ = &wireless_group;
#if IS_ENABLED(CONFIG_WIRELESS_EXT)
else if (ndev->wireless_handlers)
*groups++ = &wireless_group;
#endif
#endif
#endif
error = device_add(dev);
if (error)
return error;
error = register_queue_kobjects(ndev);
if (error) {
device_del(dev);
return error;
}
pm_runtime_set_memalloc_noio(dev, true);
return error;
}
int netdev_class_create_file_ns(const struct class_attribute *class_attr,
const void *ns)
{
return class_create_file_ns(&net_class, class_attr, ns);
}
void netdev_class_remove_file_ns(const struct class_attribute *class_attr,
const void *ns)
{
class_remove_file_ns(&net_class, class_attr, ns);
}
int __init netdev_kobject_init(void)
{
kobj_ns_type_register(&net_ns_type_operations);
return class_register(&net_class);
}
