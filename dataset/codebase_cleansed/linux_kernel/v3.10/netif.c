static inline u32 sel_netif_hashfn(int ifindex)
{
return (ifindex & (SEL_NETIF_HASH_SIZE - 1));
}
static inline struct sel_netif *sel_netif_find(int ifindex)
{
int idx = sel_netif_hashfn(ifindex);
struct sel_netif *netif;
list_for_each_entry_rcu(netif, &sel_netif_hash[idx], list)
if (likely(netif->nsec.ifindex == ifindex))
return netif;
return NULL;
}
static int sel_netif_insert(struct sel_netif *netif)
{
int idx;
if (sel_netif_total >= SEL_NETIF_HASH_MAX)
return -ENOSPC;
idx = sel_netif_hashfn(netif->nsec.ifindex);
list_add_rcu(&netif->list, &sel_netif_hash[idx]);
sel_netif_total++;
return 0;
}
static void sel_netif_destroy(struct sel_netif *netif)
{
list_del_rcu(&netif->list);
sel_netif_total--;
kfree_rcu(netif, rcu_head);
}
static int sel_netif_sid_slow(int ifindex, u32 *sid)
{
int ret;
struct sel_netif *netif;
struct sel_netif *new = NULL;
struct net_device *dev;
dev = dev_get_by_index(&init_net, ifindex);
if (unlikely(dev == NULL)) {
printk(KERN_WARNING
"SELinux: failure in sel_netif_sid_slow(),"
" invalid network interface (%d)\n", ifindex);
return -ENOENT;
}
spin_lock_bh(&sel_netif_lock);
netif = sel_netif_find(ifindex);
if (netif != NULL) {
*sid = netif->nsec.sid;
ret = 0;
goto out;
}
new = kzalloc(sizeof(*new), GFP_ATOMIC);
if (new == NULL) {
ret = -ENOMEM;
goto out;
}
ret = security_netif_sid(dev->name, &new->nsec.sid);
if (ret != 0)
goto out;
new->nsec.ifindex = ifindex;
ret = sel_netif_insert(new);
if (ret != 0)
goto out;
*sid = new->nsec.sid;
out:
spin_unlock_bh(&sel_netif_lock);
dev_put(dev);
if (unlikely(ret)) {
printk(KERN_WARNING
"SELinux: failure in sel_netif_sid_slow(),"
" unable to determine network interface label (%d)\n",
ifindex);
kfree(new);
}
return ret;
}
int sel_netif_sid(int ifindex, u32 *sid)
{
struct sel_netif *netif;
rcu_read_lock();
netif = sel_netif_find(ifindex);
if (likely(netif != NULL)) {
*sid = netif->nsec.sid;
rcu_read_unlock();
return 0;
}
rcu_read_unlock();
return sel_netif_sid_slow(ifindex, sid);
}
static void sel_netif_kill(int ifindex)
{
struct sel_netif *netif;
rcu_read_lock();
spin_lock_bh(&sel_netif_lock);
netif = sel_netif_find(ifindex);
if (netif)
sel_netif_destroy(netif);
spin_unlock_bh(&sel_netif_lock);
rcu_read_unlock();
}
static void sel_netif_flush(void)
{
int idx;
struct sel_netif *netif;
spin_lock_bh(&sel_netif_lock);
for (idx = 0; idx < SEL_NETIF_HASH_SIZE; idx++)
list_for_each_entry(netif, &sel_netif_hash[idx], list)
sel_netif_destroy(netif);
spin_unlock_bh(&sel_netif_lock);
}
static int sel_netif_avc_callback(u32 event)
{
if (event == AVC_CALLBACK_RESET) {
sel_netif_flush();
synchronize_net();
}
return 0;
}
static int sel_netif_netdev_notifier_handler(struct notifier_block *this,
unsigned long event, void *ptr)
{
struct net_device *dev = ptr;
if (dev_net(dev) != &init_net)
return NOTIFY_DONE;
if (event == NETDEV_DOWN)
sel_netif_kill(dev->ifindex);
return NOTIFY_DONE;
}
static __init int sel_netif_init(void)
{
int i, err;
if (!selinux_enabled)
return 0;
for (i = 0; i < SEL_NETIF_HASH_SIZE; i++)
INIT_LIST_HEAD(&sel_netif_hash[i]);
register_netdevice_notifier(&sel_netif_netdev_notifier);
err = avc_add_callback(sel_netif_avc_callback, AVC_CALLBACK_RESET);
if (err)
panic("avc_add_callback() failed, error %d\n", err);
return err;
}
