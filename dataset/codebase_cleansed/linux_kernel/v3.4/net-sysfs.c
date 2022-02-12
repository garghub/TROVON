static inline int dev_isalive(const struct net_device *dev)
{
return dev->reg_state <= NETREG_REGISTERED;
}
static ssize_t netdev_show(const struct device *dev,
struct device_attribute *attr, char *buf,
ssize_t (*format)(const struct net_device *, char *))
{
struct net_device *net = to_net_dev(dev);
ssize_t ret = -EINVAL;
read_lock(&dev_base_lock);
if (dev_isalive(net))
ret = (*format)(net, buf);
read_unlock(&dev_base_lock);
return ret;
}
static ssize_t netdev_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t len,
int (*set)(struct net_device *, unsigned long))
{
struct net_device *net = to_net_dev(dev);
char *endp;
unsigned long new;
int ret = -EINVAL;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
new = simple_strtoul(buf, &endp, 0);
if (endp == buf)
goto err;
if (!rtnl_trylock())
return restart_syscall();
if (dev_isalive(net)) {
if ((ret = (*set)(net, new)) == 0)
ret = len;
}
rtnl_unlock();
err:
return ret;
}
static ssize_t show_address(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct net_device *net = to_net_dev(dev);
ssize_t ret = -EINVAL;
read_lock(&dev_base_lock);
if (dev_isalive(net))
ret = sysfs_format_mac(buf, net->dev_addr, net->addr_len);
read_unlock(&dev_base_lock);
return ret;
}
static ssize_t show_broadcast(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct net_device *net = to_net_dev(dev);
if (dev_isalive(net))
return sysfs_format_mac(buf, net->broadcast, net->addr_len);
return -EINVAL;
}
static ssize_t show_carrier(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct net_device *netdev = to_net_dev(dev);
if (netif_running(netdev)) {
return sprintf(buf, fmt_dec, !!netif_carrier_ok(netdev));
}
return -EINVAL;
}
static ssize_t show_speed(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct net_device *netdev = to_net_dev(dev);
int ret = -EINVAL;
if (!rtnl_trylock())
return restart_syscall();
if (netif_running(netdev)) {
struct ethtool_cmd cmd;
if (!__ethtool_get_settings(netdev, &cmd))
ret = sprintf(buf, fmt_udec, ethtool_cmd_speed(&cmd));
}
rtnl_unlock();
return ret;
}
static ssize_t show_duplex(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct net_device *netdev = to_net_dev(dev);
int ret = -EINVAL;
if (!rtnl_trylock())
return restart_syscall();
if (netif_running(netdev)) {
struct ethtool_cmd cmd;
if (!__ethtool_get_settings(netdev, &cmd))
ret = sprintf(buf, "%s\n",
cmd.duplex ? "full" : "half");
}
rtnl_unlock();
return ret;
}
static ssize_t show_dormant(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct net_device *netdev = to_net_dev(dev);
if (netif_running(netdev))
return sprintf(buf, fmt_dec, !!netif_dormant(netdev));
return -EINVAL;
}
static ssize_t show_operstate(struct device *dev,
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
static int change_mtu(struct net_device *net, unsigned long new_mtu)
{
return dev_set_mtu(net, (int) new_mtu);
}
static ssize_t store_mtu(struct device *dev, struct device_attribute *attr,
const char *buf, size_t len)
{
return netdev_store(dev, attr, buf, len, change_mtu);
}
static int change_flags(struct net_device *net, unsigned long new_flags)
{
return dev_change_flags(net, (unsigned) new_flags);
}
static ssize_t store_flags(struct device *dev, struct device_attribute *attr,
const char *buf, size_t len)
{
return netdev_store(dev, attr, buf, len, change_flags);
}
static int change_tx_queue_len(struct net_device *net, unsigned long new_len)
{
net->tx_queue_len = new_len;
return 0;
}
static ssize_t store_tx_queue_len(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
return netdev_store(dev, attr, buf, len, change_tx_queue_len);
}
static ssize_t store_ifalias(struct device *dev, struct device_attribute *attr,
const char *buf, size_t len)
{
struct net_device *netdev = to_net_dev(dev);
size_t count = len;
ssize_t ret;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (len > 0 && buf[len - 1] == '\n')
--count;
if (!rtnl_trylock())
return restart_syscall();
ret = dev_set_alias(netdev, buf, count);
rtnl_unlock();
return ret < 0 ? ret : len;
}
static ssize_t show_ifalias(struct device *dev,
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
static int change_group(struct net_device *net, unsigned long new_group)
{
dev_set_group(net, (int) new_group);
return 0;
}
static ssize_t store_group(struct device *dev, struct device_attribute *attr,
const char *buf, size_t len)
{
return netdev_store(dev, attr, buf, len, change_group);
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
ret = sprintf(buf, fmt_u64, *(u64 *)(((u8 *) stats) + offset));
}
read_unlock(&dev_base_lock);
return ret;
}
static ssize_t wireless_show(struct device *d, char *buf,
ssize_t (*format)(const struct iw_statistics *,
char *))
{
struct net_device *dev = to_net_dev(d);
const struct iw_statistics *iw;
ssize_t ret = -EINVAL;
if (!rtnl_trylock())
return restart_syscall();
if (dev_isalive(dev)) {
iw = get_wireless_stats(dev);
if (iw)
ret = (*format)(iw, buf);
}
rtnl_unlock();
return ret;
}
static ssize_t rx_queue_attr_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct rx_queue_attribute *attribute = to_rx_queue_attr(attr);
struct netdev_rx_queue *queue = to_rx_queue(kobj);
if (!attribute->show)
return -EIO;
return attribute->show(queue, attribute, buf);
}
static ssize_t rx_queue_attr_store(struct kobject *kobj, struct attribute *attr,
const char *buf, size_t count)
{
struct rx_queue_attribute *attribute = to_rx_queue_attr(attr);
struct netdev_rx_queue *queue = to_rx_queue(kobj);
if (!attribute->store)
return -EIO;
return attribute->store(queue, attribute, buf, count);
}
static ssize_t show_rps_map(struct netdev_rx_queue *queue,
struct rx_queue_attribute *attribute, char *buf)
{
struct rps_map *map;
cpumask_var_t mask;
size_t len = 0;
int i;
if (!zalloc_cpumask_var(&mask, GFP_KERNEL))
return -ENOMEM;
rcu_read_lock();
map = rcu_dereference(queue->rps_map);
if (map)
for (i = 0; i < map->len; i++)
cpumask_set_cpu(map->cpus[i], mask);
len += cpumask_scnprintf(buf + len, PAGE_SIZE, mask);
if (PAGE_SIZE - len < 3) {
rcu_read_unlock();
free_cpumask_var(mask);
return -EINVAL;
}
rcu_read_unlock();
free_cpumask_var(mask);
len += sprintf(buf + len, "\n");
return len;
}
static ssize_t store_rps_map(struct netdev_rx_queue *queue,
struct rx_queue_attribute *attribute,
const char *buf, size_t len)
{
struct rps_map *old_map, *map;
cpumask_var_t mask;
int err, cpu, i;
static DEFINE_SPINLOCK(rps_map_lock);
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (!alloc_cpumask_var(&mask, GFP_KERNEL))
return -ENOMEM;
err = bitmap_parse(buf, len, cpumask_bits(mask), nr_cpumask_bits);
if (err) {
free_cpumask_var(mask);
return err;
}
map = kzalloc(max_t(unsigned,
RPS_MAP_SIZE(cpumask_weight(mask)), L1_CACHE_BYTES),
GFP_KERNEL);
if (!map) {
free_cpumask_var(mask);
return -ENOMEM;
}
i = 0;
for_each_cpu_and(cpu, mask, cpu_online_mask)
map->cpus[i++] = cpu;
if (i)
map->len = i;
else {
kfree(map);
map = NULL;
}
spin_lock(&rps_map_lock);
old_map = rcu_dereference_protected(queue->rps_map,
lockdep_is_held(&rps_map_lock));
rcu_assign_pointer(queue->rps_map, map);
spin_unlock(&rps_map_lock);
if (map)
static_key_slow_inc(&rps_needed);
if (old_map) {
kfree_rcu(old_map, rcu);
static_key_slow_dec(&rps_needed);
}
free_cpumask_var(mask);
return len;
}
static ssize_t show_rps_dev_flow_table_cnt(struct netdev_rx_queue *queue,
struct rx_queue_attribute *attr,
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
static void rps_dev_flow_table_release_work(struct work_struct *work)
{
struct rps_dev_flow_table *table = container_of(work,
struct rps_dev_flow_table, free_work);
vfree(table);
}
static void rps_dev_flow_table_release(struct rcu_head *rcu)
{
struct rps_dev_flow_table *table = container_of(rcu,
struct rps_dev_flow_table, rcu);
INIT_WORK(&table->free_work, rps_dev_flow_table_release_work);
schedule_work(&table->free_work);
}
static ssize_t store_rps_dev_flow_table_cnt(struct netdev_rx_queue *queue,
struct rx_queue_attribute *attr,
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
} else
table = NULL;
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
memset(kobj, 0, sizeof(*kobj));
dev_put(queue->dev);
}
static int rx_queue_add_kobject(struct net_device *net, int index)
{
struct netdev_rx_queue *queue = net->_rx + index;
struct kobject *kobj = &queue->kobj;
int error = 0;
kobj->kset = net->queues_kset;
error = kobject_init_and_add(kobj, &rx_queue_ktype, NULL,
"rx-%u", index);
if (error) {
kobject_put(kobj);
return error;
}
kobject_uevent(kobj, KOBJ_ADD);
dev_hold(queue->dev);
return error;
}
int
net_rx_queue_update_kobjects(struct net_device *net, int old_num, int new_num)
{
#ifdef CONFIG_RPS
int i;
int error = 0;
for (i = old_num; i < new_num; i++) {
error = rx_queue_add_kobject(net, i);
if (error) {
new_num = old_num;
break;
}
}
while (--i >= new_num)
kobject_put(&net->_rx[i].kobj);
return error;
#else
return 0;
#endif
}
static ssize_t netdev_queue_attr_show(struct kobject *kobj,
struct attribute *attr, char *buf)
{
struct netdev_queue_attribute *attribute = to_netdev_queue_attr(attr);
struct netdev_queue *queue = to_netdev_queue(kobj);
if (!attribute->show)
return -EIO;
return attribute->show(queue, attribute, buf);
}
static ssize_t netdev_queue_attr_store(struct kobject *kobj,
struct attribute *attr,
const char *buf, size_t count)
{
struct netdev_queue_attribute *attribute = to_netdev_queue_attr(attr);
struct netdev_queue *queue = to_netdev_queue(kobj);
if (!attribute->store)
return -EIO;
return attribute->store(queue, attribute, buf, count);
}
static ssize_t show_trans_timeout(struct netdev_queue *queue,
struct netdev_queue_attribute *attribute,
char *buf)
{
unsigned long trans_timeout;
spin_lock_irq(&queue->_xmit_lock);
trans_timeout = queue->trans_timeout;
spin_unlock_irq(&queue->_xmit_lock);
return sprintf(buf, "%lu", trans_timeout);
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
if (!strcmp(buf, "max") || !strcmp(buf, "max\n"))
value = DQL_MAX_LIMIT;
else {
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
struct netdev_queue_attribute *attr,
char *buf)
{
struct dql *dql = &queue->dql;
return sprintf(buf, "%u\n", jiffies_to_msecs(dql->slack_hold_time));
}
static ssize_t bql_set_hold_time(struct netdev_queue *queue,
struct netdev_queue_attribute *attribute,
const char *buf, size_t len)
{
struct dql *dql = &queue->dql;
unsigned value;
int err;
err = kstrtouint(buf, 10, &value);
if (err < 0)
return err;
dql->slack_hold_time = msecs_to_jiffies(value);
return len;
}
static ssize_t bql_show_inflight(struct netdev_queue *queue,
struct netdev_queue_attribute *attr,
char *buf)
{
struct dql *dql = &queue->dql;
return sprintf(buf, "%u\n", dql->num_queued - dql->num_completed);
}
static inline unsigned int get_netdev_queue_index(struct netdev_queue *queue)
{
struct net_device *dev = queue->dev;
int i;
for (i = 0; i < dev->num_tx_queues; i++)
if (queue == &dev->_tx[i])
break;
BUG_ON(i >= dev->num_tx_queues);
return i;
}
static ssize_t show_xps_map(struct netdev_queue *queue,
struct netdev_queue_attribute *attribute, char *buf)
{
struct net_device *dev = queue->dev;
struct xps_dev_maps *dev_maps;
cpumask_var_t mask;
unsigned long index;
size_t len = 0;
int i;
if (!zalloc_cpumask_var(&mask, GFP_KERNEL))
return -ENOMEM;
index = get_netdev_queue_index(queue);
rcu_read_lock();
dev_maps = rcu_dereference(dev->xps_maps);
if (dev_maps) {
for_each_possible_cpu(i) {
struct xps_map *map =
rcu_dereference(dev_maps->cpu_map[i]);
if (map) {
int j;
for (j = 0; j < map->len; j++) {
if (map->queues[j] == index) {
cpumask_set_cpu(i, mask);
break;
}
}
}
}
}
rcu_read_unlock();
len += cpumask_scnprintf(buf + len, PAGE_SIZE, mask);
if (PAGE_SIZE - len < 3) {
free_cpumask_var(mask);
return -EINVAL;
}
free_cpumask_var(mask);
len += sprintf(buf + len, "\n");
return len;
}
static void xps_queue_release(struct netdev_queue *queue)
{
struct net_device *dev = queue->dev;
struct xps_dev_maps *dev_maps;
struct xps_map *map;
unsigned long index;
int i, pos, nonempty = 0;
index = get_netdev_queue_index(queue);
mutex_lock(&xps_map_mutex);
dev_maps = xmap_dereference(dev->xps_maps);
if (dev_maps) {
for_each_possible_cpu(i) {
map = xmap_dereference(dev_maps->cpu_map[i]);
if (!map)
continue;
for (pos = 0; pos < map->len; pos++)
if (map->queues[pos] == index)
break;
if (pos < map->len) {
if (map->len > 1)
map->queues[pos] =
map->queues[--map->len];
else {
RCU_INIT_POINTER(dev_maps->cpu_map[i],
NULL);
kfree_rcu(map, rcu);
map = NULL;
}
}
if (map)
nonempty = 1;
}
if (!nonempty) {
RCU_INIT_POINTER(dev->xps_maps, NULL);
kfree_rcu(dev_maps, rcu);
}
}
mutex_unlock(&xps_map_mutex);
}
static ssize_t store_xps_map(struct netdev_queue *queue,
struct netdev_queue_attribute *attribute,
const char *buf, size_t len)
{
struct net_device *dev = queue->dev;
cpumask_var_t mask;
int err, i, cpu, pos, map_len, alloc_len, need_set;
unsigned long index;
struct xps_map *map, *new_map;
struct xps_dev_maps *dev_maps, *new_dev_maps;
int nonempty = 0;
int numa_node_id = -2;
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
new_dev_maps = kzalloc(max_t(unsigned,
XPS_DEV_MAPS_SIZE, L1_CACHE_BYTES), GFP_KERNEL);
if (!new_dev_maps) {
free_cpumask_var(mask);
return -ENOMEM;
}
mutex_lock(&xps_map_mutex);
dev_maps = xmap_dereference(dev->xps_maps);
for_each_possible_cpu(cpu) {
map = dev_maps ?
xmap_dereference(dev_maps->cpu_map[cpu]) : NULL;
new_map = map;
if (map) {
for (pos = 0; pos < map->len; pos++)
if (map->queues[pos] == index)
break;
map_len = map->len;
alloc_len = map->alloc_len;
} else
pos = map_len = alloc_len = 0;
need_set = cpumask_test_cpu(cpu, mask) && cpu_online(cpu);
#ifdef CONFIG_NUMA
if (need_set) {
if (numa_node_id == -2)
numa_node_id = cpu_to_node(cpu);
else if (numa_node_id != cpu_to_node(cpu))
numa_node_id = -1;
}
#endif
if (need_set && pos >= map_len) {
if (map_len >= alloc_len) {
alloc_len = alloc_len ?
2 * alloc_len : XPS_MIN_MAP_ALLOC;
new_map = kzalloc_node(XPS_MAP_SIZE(alloc_len),
GFP_KERNEL,
cpu_to_node(cpu));
if (!new_map)
goto error;
new_map->alloc_len = alloc_len;
for (i = 0; i < map_len; i++)
new_map->queues[i] = map->queues[i];
new_map->len = map_len;
}
new_map->queues[new_map->len++] = index;
} else if (!need_set && pos < map_len) {
if (map_len > 1)
new_map->queues[pos] =
new_map->queues[--new_map->len];
else
new_map = NULL;
}
RCU_INIT_POINTER(new_dev_maps->cpu_map[cpu], new_map);
}
for_each_possible_cpu(cpu) {
map = dev_maps ?
xmap_dereference(dev_maps->cpu_map[cpu]) : NULL;
if (map && xmap_dereference(new_dev_maps->cpu_map[cpu]) != map)
kfree_rcu(map, rcu);
if (new_dev_maps->cpu_map[cpu])
nonempty = 1;
}
if (nonempty) {
rcu_assign_pointer(dev->xps_maps, new_dev_maps);
} else {
kfree(new_dev_maps);
RCU_INIT_POINTER(dev->xps_maps, NULL);
}
if (dev_maps)
kfree_rcu(dev_maps, rcu);
netdev_queue_numa_node_write(queue, (numa_node_id >= 0) ? numa_node_id :
NUMA_NO_NODE);
mutex_unlock(&xps_map_mutex);
free_cpumask_var(mask);
return len;
error:
mutex_unlock(&xps_map_mutex);
if (new_dev_maps)
for_each_possible_cpu(i)
kfree(rcu_dereference_protected(
new_dev_maps->cpu_map[i],
1));
kfree(new_dev_maps);
free_cpumask_var(mask);
return -ENOMEM;
}
static void netdev_queue_release(struct kobject *kobj)
{
struct netdev_queue *queue = to_netdev_queue(kobj);
#ifdef CONFIG_XPS
xps_queue_release(queue);
#endif
memset(kobj, 0, sizeof(*kobj));
dev_put(queue->dev);
}
static int netdev_queue_add_kobject(struct net_device *net, int index)
{
struct netdev_queue *queue = net->_tx + index;
struct kobject *kobj = &queue->kobj;
int error = 0;
kobj->kset = net->queues_kset;
error = kobject_init_and_add(kobj, &netdev_queue_ktype, NULL,
"tx-%u", index);
if (error)
goto exit;
#ifdef CONFIG_BQL
error = sysfs_create_group(kobj, &dql_group);
if (error)
goto exit;
#endif
kobject_uevent(kobj, KOBJ_ADD);
dev_hold(queue->dev);
return 0;
exit:
kobject_put(kobj);
return error;
}
int
netdev_queue_update_kobjects(struct net_device *net, int old_num, int new_num)
{
#ifdef CONFIG_SYSFS
int i;
int error = 0;
for (i = old_num; i < new_num; i++) {
error = netdev_queue_add_kobject(net, i);
if (error) {
new_num = old_num;
break;
}
}
while (--i >= new_num) {
struct netdev_queue *queue = net->_tx + i;
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
static int register_queue_kobjects(struct net_device *net)
{
int error = 0, txq = 0, rxq = 0, real_rx = 0, real_tx = 0;
#ifdef CONFIG_SYSFS
net->queues_kset = kset_create_and_add("queues",
NULL, &net->dev.kobj);
if (!net->queues_kset)
return -ENOMEM;
#endif
#ifdef CONFIG_RPS
real_rx = net->real_num_rx_queues;
#endif
real_tx = net->real_num_tx_queues;
error = net_rx_queue_update_kobjects(net, 0, real_rx);
if (error)
goto error;
rxq = real_rx;
error = netdev_queue_update_kobjects(net, 0, real_tx);
if (error)
goto error;
txq = real_tx;
return 0;
error:
netdev_queue_update_kobjects(net, txq, 0);
net_rx_queue_update_kobjects(net, rxq, 0);
return error;
}
static void remove_queue_kobjects(struct net_device *net)
{
int real_rx = 0, real_tx = 0;
#ifdef CONFIG_RPS
real_rx = net->real_num_rx_queues;
#endif
real_tx = net->real_num_tx_queues;
net_rx_queue_update_kobjects(net, real_rx, 0);
netdev_queue_update_kobjects(net, real_tx, 0);
#ifdef CONFIG_SYSFS
kset_unregister(net->queues_kset);
#endif
}
static void *net_grab_current_ns(void)
{
struct net *ns = current->nsproxy->net_ns;
#ifdef CONFIG_NET_NS
if (ns)
atomic_inc(&ns->passive);
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
kfree((char *)dev - dev->padded);
}
static const void *net_namespace(struct device *d)
{
struct net_device *dev;
dev = container_of(d, struct net_device, dev);
return dev_net(dev);
}
void netdev_unregister_kobject(struct net_device * net)
{
struct device *dev = &(net->dev);
kobject_get(&dev->kobj);
remove_queue_kobjects(net);
device_del(dev);
}
int netdev_register_kobject(struct net_device *net)
{
struct device *dev = &(net->dev);
const struct attribute_group **groups = net->sysfs_groups;
int error = 0;
device_initialize(dev);
dev->class = &net_class;
dev->platform_data = net;
dev->groups = groups;
dev_set_name(dev, "%s", net->name);
#ifdef CONFIG_SYSFS
if (*groups)
groups++;
*groups++ = &netstat_group;
#ifdef CONFIG_WIRELESS_EXT_SYSFS
if (net->ieee80211_ptr)
*groups++ = &wireless_group;
#ifdef CONFIG_WIRELESS_EXT
else if (net->wireless_handlers)
*groups++ = &wireless_group;
#endif
#endif
#endif
error = device_add(dev);
if (error)
return error;
error = register_queue_kobjects(net);
if (error) {
device_del(dev);
return error;
}
return error;
}
int netdev_class_create_file(struct class_attribute *class_attr)
{
return class_create_file(&net_class, class_attr);
}
void netdev_class_remove_file(struct class_attribute *class_attr)
{
class_remove_file(&net_class, class_attr);
}
int netdev_kobject_init(void)
{
kobj_ns_type_register(&net_ns_type_operations);
return class_register(&net_class);
}
