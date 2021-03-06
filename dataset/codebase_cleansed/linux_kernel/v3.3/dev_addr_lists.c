static int __hw_addr_add_ex(struct netdev_hw_addr_list *list,
unsigned char *addr, int addr_len,
unsigned char addr_type, bool global)
{
struct netdev_hw_addr *ha;
int alloc_size;
if (addr_len > MAX_ADDR_LEN)
return -EINVAL;
list_for_each_entry(ha, &list->list, list) {
if (!memcmp(ha->addr, addr, addr_len) &&
ha->type == addr_type) {
if (global) {
if (ha->global_use)
return 0;
else
ha->global_use = true;
}
ha->refcount++;
return 0;
}
}
alloc_size = sizeof(*ha);
if (alloc_size < L1_CACHE_BYTES)
alloc_size = L1_CACHE_BYTES;
ha = kmalloc(alloc_size, GFP_ATOMIC);
if (!ha)
return -ENOMEM;
memcpy(ha->addr, addr, addr_len);
ha->type = addr_type;
ha->refcount = 1;
ha->global_use = global;
ha->synced = false;
list_add_tail_rcu(&ha->list, &list->list);
list->count++;
return 0;
}
static int __hw_addr_add(struct netdev_hw_addr_list *list, unsigned char *addr,
int addr_len, unsigned char addr_type)
{
return __hw_addr_add_ex(list, addr, addr_len, addr_type, false);
}
static int __hw_addr_del_ex(struct netdev_hw_addr_list *list,
unsigned char *addr, int addr_len,
unsigned char addr_type, bool global)
{
struct netdev_hw_addr *ha;
list_for_each_entry(ha, &list->list, list) {
if (!memcmp(ha->addr, addr, addr_len) &&
(ha->type == addr_type || !addr_type)) {
if (global) {
if (!ha->global_use)
break;
else
ha->global_use = false;
}
if (--ha->refcount)
return 0;
list_del_rcu(&ha->list);
kfree_rcu(ha, rcu_head);
list->count--;
return 0;
}
}
return -ENOENT;
}
static int __hw_addr_del(struct netdev_hw_addr_list *list, unsigned char *addr,
int addr_len, unsigned char addr_type)
{
return __hw_addr_del_ex(list, addr, addr_len, addr_type, false);
}
int __hw_addr_add_multiple(struct netdev_hw_addr_list *to_list,
struct netdev_hw_addr_list *from_list,
int addr_len, unsigned char addr_type)
{
int err;
struct netdev_hw_addr *ha, *ha2;
unsigned char type;
list_for_each_entry(ha, &from_list->list, list) {
type = addr_type ? addr_type : ha->type;
err = __hw_addr_add(to_list, ha->addr, addr_len, type);
if (err)
goto unroll;
}
return 0;
unroll:
list_for_each_entry(ha2, &from_list->list, list) {
if (ha2 == ha)
break;
type = addr_type ? addr_type : ha2->type;
__hw_addr_del(to_list, ha2->addr, addr_len, type);
}
return err;
}
void __hw_addr_del_multiple(struct netdev_hw_addr_list *to_list,
struct netdev_hw_addr_list *from_list,
int addr_len, unsigned char addr_type)
{
struct netdev_hw_addr *ha;
unsigned char type;
list_for_each_entry(ha, &from_list->list, list) {
type = addr_type ? addr_type : ha->type;
__hw_addr_del(to_list, ha->addr, addr_len, type);
}
}
int __hw_addr_sync(struct netdev_hw_addr_list *to_list,
struct netdev_hw_addr_list *from_list,
int addr_len)
{
int err = 0;
struct netdev_hw_addr *ha, *tmp;
list_for_each_entry_safe(ha, tmp, &from_list->list, list) {
if (!ha->synced) {
err = __hw_addr_add(to_list, ha->addr,
addr_len, ha->type);
if (err)
break;
ha->synced = true;
ha->refcount++;
} else if (ha->refcount == 1) {
__hw_addr_del(to_list, ha->addr, addr_len, ha->type);
__hw_addr_del(from_list, ha->addr, addr_len, ha->type);
}
}
return err;
}
void __hw_addr_unsync(struct netdev_hw_addr_list *to_list,
struct netdev_hw_addr_list *from_list,
int addr_len)
{
struct netdev_hw_addr *ha, *tmp;
list_for_each_entry_safe(ha, tmp, &from_list->list, list) {
if (ha->synced) {
__hw_addr_del(to_list, ha->addr,
addr_len, ha->type);
ha->synced = false;
__hw_addr_del(from_list, ha->addr,
addr_len, ha->type);
}
}
}
void __hw_addr_flush(struct netdev_hw_addr_list *list)
{
struct netdev_hw_addr *ha, *tmp;
list_for_each_entry_safe(ha, tmp, &list->list, list) {
list_del_rcu(&ha->list);
kfree_rcu(ha, rcu_head);
}
list->count = 0;
}
void __hw_addr_init(struct netdev_hw_addr_list *list)
{
INIT_LIST_HEAD(&list->list);
list->count = 0;
}
void dev_addr_flush(struct net_device *dev)
{
__hw_addr_flush(&dev->dev_addrs);
dev->dev_addr = NULL;
}
int dev_addr_init(struct net_device *dev)
{
unsigned char addr[MAX_ADDR_LEN];
struct netdev_hw_addr *ha;
int err;
__hw_addr_init(&dev->dev_addrs);
memset(addr, 0, sizeof(addr));
err = __hw_addr_add(&dev->dev_addrs, addr, sizeof(addr),
NETDEV_HW_ADDR_T_LAN);
if (!err) {
ha = list_first_entry(&dev->dev_addrs.list,
struct netdev_hw_addr, list);
dev->dev_addr = ha->addr;
}
return err;
}
int dev_addr_add(struct net_device *dev, unsigned char *addr,
unsigned char addr_type)
{
int err;
ASSERT_RTNL();
err = __hw_addr_add(&dev->dev_addrs, addr, dev->addr_len, addr_type);
if (!err)
call_netdevice_notifiers(NETDEV_CHANGEADDR, dev);
return err;
}
int dev_addr_del(struct net_device *dev, unsigned char *addr,
unsigned char addr_type)
{
int err;
struct netdev_hw_addr *ha;
ASSERT_RTNL();
ha = list_first_entry(&dev->dev_addrs.list,
struct netdev_hw_addr, list);
if (ha->addr == dev->dev_addr && ha->refcount == 1)
return -ENOENT;
err = __hw_addr_del(&dev->dev_addrs, addr, dev->addr_len,
addr_type);
if (!err)
call_netdevice_notifiers(NETDEV_CHANGEADDR, dev);
return err;
}
int dev_addr_add_multiple(struct net_device *to_dev,
struct net_device *from_dev,
unsigned char addr_type)
{
int err;
ASSERT_RTNL();
if (from_dev->addr_len != to_dev->addr_len)
return -EINVAL;
err = __hw_addr_add_multiple(&to_dev->dev_addrs, &from_dev->dev_addrs,
to_dev->addr_len, addr_type);
if (!err)
call_netdevice_notifiers(NETDEV_CHANGEADDR, to_dev);
return err;
}
int dev_addr_del_multiple(struct net_device *to_dev,
struct net_device *from_dev,
unsigned char addr_type)
{
ASSERT_RTNL();
if (from_dev->addr_len != to_dev->addr_len)
return -EINVAL;
__hw_addr_del_multiple(&to_dev->dev_addrs, &from_dev->dev_addrs,
to_dev->addr_len, addr_type);
call_netdevice_notifiers(NETDEV_CHANGEADDR, to_dev);
return 0;
}
int dev_uc_add(struct net_device *dev, unsigned char *addr)
{
int err;
netif_addr_lock_bh(dev);
err = __hw_addr_add(&dev->uc, addr, dev->addr_len,
NETDEV_HW_ADDR_T_UNICAST);
if (!err)
__dev_set_rx_mode(dev);
netif_addr_unlock_bh(dev);
return err;
}
int dev_uc_del(struct net_device *dev, unsigned char *addr)
{
int err;
netif_addr_lock_bh(dev);
err = __hw_addr_del(&dev->uc, addr, dev->addr_len,
NETDEV_HW_ADDR_T_UNICAST);
if (!err)
__dev_set_rx_mode(dev);
netif_addr_unlock_bh(dev);
return err;
}
int dev_uc_sync(struct net_device *to, struct net_device *from)
{
int err = 0;
if (to->addr_len != from->addr_len)
return -EINVAL;
netif_addr_lock_nested(to);
err = __hw_addr_sync(&to->uc, &from->uc, to->addr_len);
if (!err)
__dev_set_rx_mode(to);
netif_addr_unlock(to);
return err;
}
void dev_uc_unsync(struct net_device *to, struct net_device *from)
{
if (to->addr_len != from->addr_len)
return;
netif_addr_lock_bh(from);
netif_addr_lock_nested(to);
__hw_addr_unsync(&to->uc, &from->uc, to->addr_len);
__dev_set_rx_mode(to);
netif_addr_unlock(to);
netif_addr_unlock_bh(from);
}
void dev_uc_flush(struct net_device *dev)
{
netif_addr_lock_bh(dev);
__hw_addr_flush(&dev->uc);
netif_addr_unlock_bh(dev);
}
void dev_uc_init(struct net_device *dev)
{
__hw_addr_init(&dev->uc);
}
static int __dev_mc_add(struct net_device *dev, unsigned char *addr,
bool global)
{
int err;
netif_addr_lock_bh(dev);
err = __hw_addr_add_ex(&dev->mc, addr, dev->addr_len,
NETDEV_HW_ADDR_T_MULTICAST, global);
if (!err)
__dev_set_rx_mode(dev);
netif_addr_unlock_bh(dev);
return err;
}
int dev_mc_add(struct net_device *dev, unsigned char *addr)
{
return __dev_mc_add(dev, addr, false);
}
int dev_mc_add_global(struct net_device *dev, unsigned char *addr)
{
return __dev_mc_add(dev, addr, true);
}
static int __dev_mc_del(struct net_device *dev, unsigned char *addr,
bool global)
{
int err;
netif_addr_lock_bh(dev);
err = __hw_addr_del_ex(&dev->mc, addr, dev->addr_len,
NETDEV_HW_ADDR_T_MULTICAST, global);
if (!err)
__dev_set_rx_mode(dev);
netif_addr_unlock_bh(dev);
return err;
}
int dev_mc_del(struct net_device *dev, unsigned char *addr)
{
return __dev_mc_del(dev, addr, false);
}
int dev_mc_del_global(struct net_device *dev, unsigned char *addr)
{
return __dev_mc_del(dev, addr, true);
}
int dev_mc_sync(struct net_device *to, struct net_device *from)
{
int err = 0;
if (to->addr_len != from->addr_len)
return -EINVAL;
netif_addr_lock_nested(to);
err = __hw_addr_sync(&to->mc, &from->mc, to->addr_len);
if (!err)
__dev_set_rx_mode(to);
netif_addr_unlock(to);
return err;
}
void dev_mc_unsync(struct net_device *to, struct net_device *from)
{
if (to->addr_len != from->addr_len)
return;
netif_addr_lock_bh(from);
netif_addr_lock_nested(to);
__hw_addr_unsync(&to->mc, &from->mc, to->addr_len);
__dev_set_rx_mode(to);
netif_addr_unlock(to);
netif_addr_unlock_bh(from);
}
void dev_mc_flush(struct net_device *dev)
{
netif_addr_lock_bh(dev);
__hw_addr_flush(&dev->mc);
netif_addr_unlock_bh(dev);
}
void dev_mc_init(struct net_device *dev)
{
__hw_addr_init(&dev->mc);
}
static int dev_mc_seq_show(struct seq_file *seq, void *v)
{
struct netdev_hw_addr *ha;
struct net_device *dev = v;
if (v == SEQ_START_TOKEN)
return 0;
netif_addr_lock_bh(dev);
netdev_for_each_mc_addr(ha, dev) {
int i;
seq_printf(seq, "%-4d %-15s %-5d %-5d ", dev->ifindex,
dev->name, ha->refcount, ha->global_use);
for (i = 0; i < dev->addr_len; i++)
seq_printf(seq, "%02x", ha->addr[i]);
seq_putc(seq, '\n');
}
netif_addr_unlock_bh(dev);
return 0;
}
static int dev_mc_seq_open(struct inode *inode, struct file *file)
{
return dev_seq_open_ops(inode, file, &dev_mc_seq_ops);
}
static int __net_init dev_mc_net_init(struct net *net)
{
if (!proc_net_fops_create(net, "dev_mcast", 0, &dev_mc_seq_fops))
return -ENOMEM;
return 0;
}
static void __net_exit dev_mc_net_exit(struct net *net)
{
proc_net_remove(net, "dev_mcast");
}
void __init dev_mcast_init(void)
{
register_pernet_subsys(&dev_mc_net_ops);
}
