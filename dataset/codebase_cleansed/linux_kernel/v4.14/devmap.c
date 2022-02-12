static u64 dev_map_bitmap_size(const union bpf_attr *attr)
{
return BITS_TO_LONGS((u64) attr->max_entries) * sizeof(unsigned long);
}
static struct bpf_map *dev_map_alloc(union bpf_attr *attr)
{
struct bpf_dtab *dtab;
int err = -EINVAL;
u64 cost;
if (!capable(CAP_NET_ADMIN))
return ERR_PTR(-EPERM);
if (attr->max_entries == 0 || attr->key_size != 4 ||
attr->value_size != 4 || attr->map_flags & ~BPF_F_NUMA_NODE)
return ERR_PTR(-EINVAL);
dtab = kzalloc(sizeof(*dtab), GFP_USER);
if (!dtab)
return ERR_PTR(-ENOMEM);
dtab->map.map_type = attr->map_type;
dtab->map.key_size = attr->key_size;
dtab->map.value_size = attr->value_size;
dtab->map.max_entries = attr->max_entries;
dtab->map.map_flags = attr->map_flags;
dtab->map.numa_node = bpf_map_attr_numa_node(attr);
cost = (u64) dtab->map.max_entries * sizeof(struct bpf_dtab_netdev *);
cost += dev_map_bitmap_size(attr) * num_possible_cpus();
if (cost >= U32_MAX - PAGE_SIZE)
goto free_dtab;
dtab->map.pages = round_up(cost, PAGE_SIZE) >> PAGE_SHIFT;
err = bpf_map_precharge_memlock(dtab->map.pages);
if (err)
goto free_dtab;
err = -ENOMEM;
dtab->flush_needed = __alloc_percpu_gfp(dev_map_bitmap_size(attr),
__alignof__(unsigned long),
GFP_KERNEL | __GFP_NOWARN);
if (!dtab->flush_needed)
goto free_dtab;
dtab->netdev_map = bpf_map_area_alloc(dtab->map.max_entries *
sizeof(struct bpf_dtab_netdev *),
dtab->map.numa_node);
if (!dtab->netdev_map)
goto free_dtab;
spin_lock(&dev_map_lock);
list_add_tail_rcu(&dtab->list, &dev_map_list);
spin_unlock(&dev_map_lock);
return &dtab->map;
free_dtab:
free_percpu(dtab->flush_needed);
kfree(dtab);
return ERR_PTR(err);
}
static void dev_map_free(struct bpf_map *map)
{
struct bpf_dtab *dtab = container_of(map, struct bpf_dtab, map);
int i, cpu;
spin_lock(&dev_map_lock);
list_del_rcu(&dtab->list);
spin_unlock(&dev_map_lock);
synchronize_rcu();
for_each_online_cpu(cpu) {
unsigned long *bitmap = per_cpu_ptr(dtab->flush_needed, cpu);
while (!bitmap_empty(bitmap, dtab->map.max_entries))
cond_resched();
}
for (i = 0; i < dtab->map.max_entries; i++) {
struct bpf_dtab_netdev *dev;
dev = dtab->netdev_map[i];
if (!dev)
continue;
dev_put(dev->dev);
kfree(dev);
}
free_percpu(dtab->flush_needed);
bpf_map_area_free(dtab->netdev_map);
kfree(dtab);
}
static int dev_map_get_next_key(struct bpf_map *map, void *key, void *next_key)
{
struct bpf_dtab *dtab = container_of(map, struct bpf_dtab, map);
u32 index = key ? *(u32 *)key : U32_MAX;
u32 *next = next_key;
if (index >= dtab->map.max_entries) {
*next = 0;
return 0;
}
if (index == dtab->map.max_entries - 1)
return -ENOENT;
*next = index + 1;
return 0;
}
void __dev_map_insert_ctx(struct bpf_map *map, u32 bit)
{
struct bpf_dtab *dtab = container_of(map, struct bpf_dtab, map);
unsigned long *bitmap = this_cpu_ptr(dtab->flush_needed);
__set_bit(bit, bitmap);
}
void __dev_map_flush(struct bpf_map *map)
{
struct bpf_dtab *dtab = container_of(map, struct bpf_dtab, map);
unsigned long *bitmap = this_cpu_ptr(dtab->flush_needed);
u32 bit;
for_each_set_bit(bit, bitmap, map->max_entries) {
struct bpf_dtab_netdev *dev = READ_ONCE(dtab->netdev_map[bit]);
struct net_device *netdev;
if (unlikely(!dev))
continue;
__clear_bit(bit, bitmap);
netdev = dev->dev;
if (likely(netdev->netdev_ops->ndo_xdp_flush))
netdev->netdev_ops->ndo_xdp_flush(netdev);
}
}
struct net_device *__dev_map_lookup_elem(struct bpf_map *map, u32 key)
{
struct bpf_dtab *dtab = container_of(map, struct bpf_dtab, map);
struct bpf_dtab_netdev *dev;
if (key >= map->max_entries)
return NULL;
dev = READ_ONCE(dtab->netdev_map[key]);
return dev ? dev->dev : NULL;
}
static void *dev_map_lookup_elem(struct bpf_map *map, void *key)
{
struct net_device *dev = __dev_map_lookup_elem(map, *(u32 *)key);
return dev ? &dev->ifindex : NULL;
}
static void dev_map_flush_old(struct bpf_dtab_netdev *dev)
{
if (dev->dev->netdev_ops->ndo_xdp_flush) {
struct net_device *fl = dev->dev;
unsigned long *bitmap;
int cpu;
for_each_online_cpu(cpu) {
bitmap = per_cpu_ptr(dev->dtab->flush_needed, cpu);
__clear_bit(dev->bit, bitmap);
fl->netdev_ops->ndo_xdp_flush(dev->dev);
}
}
}
static void __dev_map_entry_free(struct rcu_head *rcu)
{
struct bpf_dtab_netdev *dev;
dev = container_of(rcu, struct bpf_dtab_netdev, rcu);
dev_map_flush_old(dev);
dev_put(dev->dev);
kfree(dev);
}
static int dev_map_delete_elem(struct bpf_map *map, void *key)
{
struct bpf_dtab *dtab = container_of(map, struct bpf_dtab, map);
struct bpf_dtab_netdev *old_dev;
int k = *(u32 *)key;
if (k >= map->max_entries)
return -EINVAL;
old_dev = xchg(&dtab->netdev_map[k], NULL);
if (old_dev)
call_rcu(&old_dev->rcu, __dev_map_entry_free);
return 0;
}
static int dev_map_update_elem(struct bpf_map *map, void *key, void *value,
u64 map_flags)
{
struct bpf_dtab *dtab = container_of(map, struct bpf_dtab, map);
struct net *net = current->nsproxy->net_ns;
struct bpf_dtab_netdev *dev, *old_dev;
u32 i = *(u32 *)key;
u32 ifindex = *(u32 *)value;
if (unlikely(map_flags > BPF_EXIST))
return -EINVAL;
if (unlikely(i >= dtab->map.max_entries))
return -E2BIG;
if (unlikely(map_flags == BPF_NOEXIST))
return -EEXIST;
if (!ifindex) {
dev = NULL;
} else {
dev = kmalloc_node(sizeof(*dev), GFP_ATOMIC | __GFP_NOWARN,
map->numa_node);
if (!dev)
return -ENOMEM;
dev->dev = dev_get_by_index(net, ifindex);
if (!dev->dev) {
kfree(dev);
return -EINVAL;
}
dev->bit = i;
dev->dtab = dtab;
}
old_dev = xchg(&dtab->netdev_map[i], dev);
if (old_dev)
call_rcu(&old_dev->rcu, __dev_map_entry_free);
return 0;
}
static int dev_map_notification(struct notifier_block *notifier,
ulong event, void *ptr)
{
struct net_device *netdev = netdev_notifier_info_to_dev(ptr);
struct bpf_dtab *dtab;
int i;
switch (event) {
case NETDEV_UNREGISTER:
rcu_read_lock();
list_for_each_entry_rcu(dtab, &dev_map_list, list) {
for (i = 0; i < dtab->map.max_entries; i++) {
struct bpf_dtab_netdev *dev, *odev;
dev = READ_ONCE(dtab->netdev_map[i]);
if (!dev ||
dev->dev->ifindex != netdev->ifindex)
continue;
odev = cmpxchg(&dtab->netdev_map[i], dev, NULL);
if (dev == odev)
call_rcu(&dev->rcu,
__dev_map_entry_free);
}
}
rcu_read_unlock();
break;
default:
break;
}
return NOTIFY_OK;
}
static int __init dev_map_init(void)
{
register_netdevice_notifier(&dev_map_notifier);
return 0;
}
