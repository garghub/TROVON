static inline struct cgroup_netprio_state *cgrp_netprio_state(struct cgroup *cgrp)
{
return container_of(cgroup_subsys_state(cgrp, net_prio_subsys_id),
struct cgroup_netprio_state, css);
}
static int get_prioidx(u32 *prio)
{
unsigned long flags;
u32 prioidx;
spin_lock_irqsave(&prioidx_map_lock, flags);
prioidx = find_first_zero_bit(prioidx_map, sizeof(unsigned long) * PRIOIDX_SZ);
if (prioidx == sizeof(unsigned long) * PRIOIDX_SZ) {
spin_unlock_irqrestore(&prioidx_map_lock, flags);
return -ENOSPC;
}
set_bit(prioidx, prioidx_map);
if (atomic_read(&max_prioidx) < prioidx)
atomic_set(&max_prioidx, prioidx);
spin_unlock_irqrestore(&prioidx_map_lock, flags);
*prio = prioidx;
return 0;
}
static void put_prioidx(u32 idx)
{
unsigned long flags;
spin_lock_irqsave(&prioidx_map_lock, flags);
clear_bit(idx, prioidx_map);
spin_unlock_irqrestore(&prioidx_map_lock, flags);
}
static int extend_netdev_table(struct net_device *dev, u32 new_len)
{
size_t new_size = sizeof(struct netprio_map) +
((sizeof(u32) * new_len));
struct netprio_map *new_priomap = kzalloc(new_size, GFP_KERNEL);
struct netprio_map *old_priomap;
old_priomap = rtnl_dereference(dev->priomap);
if (!new_priomap) {
pr_warn("Unable to alloc new priomap!\n");
return -ENOMEM;
}
if (old_priomap)
memcpy(new_priomap->priomap, old_priomap->priomap,
old_priomap->priomap_len *
sizeof(old_priomap->priomap[0]));
new_priomap->priomap_len = new_len;
rcu_assign_pointer(dev->priomap, new_priomap);
if (old_priomap)
kfree_rcu(old_priomap, rcu);
return 0;
}
static int write_update_netdev_table(struct net_device *dev)
{
int ret = 0;
u32 max_len;
struct netprio_map *map;
max_len = atomic_read(&max_prioidx) + 1;
map = rtnl_dereference(dev->priomap);
if (!map || map->priomap_len < max_len)
ret = extend_netdev_table(dev, max_len);
return ret;
}
static struct cgroup_subsys_state *cgrp_create(struct cgroup *cgrp)
{
struct cgroup_netprio_state *cs;
int ret = -EINVAL;
cs = kzalloc(sizeof(*cs), GFP_KERNEL);
if (!cs)
return ERR_PTR(-ENOMEM);
if (cgrp->parent && cgrp_netprio_state(cgrp->parent)->prioidx)
goto out;
ret = get_prioidx(&cs->prioidx);
if (ret < 0) {
pr_warn("No space in priority index array\n");
goto out;
}
return &cs->css;
out:
kfree(cs);
return ERR_PTR(ret);
}
static void cgrp_destroy(struct cgroup *cgrp)
{
struct cgroup_netprio_state *cs;
struct net_device *dev;
struct netprio_map *map;
cs = cgrp_netprio_state(cgrp);
rtnl_lock();
for_each_netdev(&init_net, dev) {
map = rtnl_dereference(dev->priomap);
if (map && cs->prioidx < map->priomap_len)
map->priomap[cs->prioidx] = 0;
}
rtnl_unlock();
put_prioidx(cs->prioidx);
kfree(cs);
}
static u64 read_prioidx(struct cgroup *cgrp, struct cftype *cft)
{
return (u64)cgrp_netprio_state(cgrp)->prioidx;
}
static int read_priomap(struct cgroup *cont, struct cftype *cft,
struct cgroup_map_cb *cb)
{
struct net_device *dev;
u32 prioidx = cgrp_netprio_state(cont)->prioidx;
u32 priority;
struct netprio_map *map;
rcu_read_lock();
for_each_netdev_rcu(&init_net, dev) {
map = rcu_dereference(dev->priomap);
priority = (map && prioidx < map->priomap_len) ? map->priomap[prioidx] : 0;
cb->fill(cb, dev->name, priority);
}
rcu_read_unlock();
return 0;
}
static int write_priomap(struct cgroup *cgrp, struct cftype *cft,
const char *buffer)
{
char *devname = kstrdup(buffer, GFP_KERNEL);
int ret = -EINVAL;
u32 prioidx = cgrp_netprio_state(cgrp)->prioidx;
unsigned long priority;
char *priostr;
struct net_device *dev;
struct netprio_map *map;
if (!devname)
return -ENOMEM;
if (strlen(devname) < 3)
goto out_free_devname;
priostr = strstr(devname, " ");
if (!priostr)
goto out_free_devname;
*priostr = '\0';
priostr++;
if (*priostr == '\0')
goto out_free_devname;
ret = kstrtoul(priostr, 10, &priority);
if (ret < 0)
goto out_free_devname;
ret = -ENODEV;
dev = dev_get_by_name(&init_net, devname);
if (!dev)
goto out_free_devname;
rtnl_lock();
ret = write_update_netdev_table(dev);
if (ret < 0)
goto out_put_dev;
map = rtnl_dereference(dev->priomap);
if (map)
map->priomap[prioidx] = priority;
out_put_dev:
rtnl_unlock();
dev_put(dev);
out_free_devname:
kfree(devname);
return ret;
}
static int update_netprio(const void *v, struct file *file, unsigned n)
{
int err;
struct socket *sock = sock_from_file(file, &err);
if (sock)
sock->sk->sk_cgrp_prioidx = (u32)(unsigned long)v;
return 0;
}
void net_prio_attach(struct cgroup *cgrp, struct cgroup_taskset *tset)
{
struct task_struct *p;
void *v;
cgroup_taskset_for_each(p, cgrp, tset) {
task_lock(p);
v = (void *)(unsigned long)task_netprioidx(p);
iterate_fd(p->files, 0, update_netprio, v);
task_unlock(p);
}
}
static int netprio_device_event(struct notifier_block *unused,
unsigned long event, void *ptr)
{
struct net_device *dev = ptr;
struct netprio_map *old;
switch (event) {
case NETDEV_UNREGISTER:
old = rtnl_dereference(dev->priomap);
RCU_INIT_POINTER(dev->priomap, NULL);
if (old)
kfree_rcu(old, rcu);
break;
}
return NOTIFY_DONE;
}
static int __init init_cgroup_netprio(void)
{
int ret;
ret = cgroup_load_subsys(&net_prio_subsys);
if (ret)
goto out;
register_netdevice_notifier(&netprio_device_notifier);
out:
return ret;
}
static void __exit exit_cgroup_netprio(void)
{
struct netprio_map *old;
struct net_device *dev;
unregister_netdevice_notifier(&netprio_device_notifier);
cgroup_unload_subsys(&net_prio_subsys);
rtnl_lock();
for_each_netdev(&init_net, dev) {
old = rtnl_dereference(dev->priomap);
RCU_INIT_POINTER(dev->priomap, NULL);
if (old)
kfree_rcu(old, rcu);
}
rtnl_unlock();
}
