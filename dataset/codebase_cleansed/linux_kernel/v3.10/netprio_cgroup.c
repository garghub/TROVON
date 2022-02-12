static inline struct cgroup_netprio_state *cgrp_netprio_state(struct cgroup *cgrp)
{
return container_of(cgroup_subsys_state(cgrp, net_prio_subsys_id),
struct cgroup_netprio_state, css);
}
static int extend_netdev_table(struct net_device *dev, u32 target_idx)
{
struct netprio_map *old, *new;
size_t new_sz, new_len;
old = rtnl_dereference(dev->priomap);
if (old && old->priomap_len > target_idx)
return 0;
new_sz = PRIOMAP_MIN_SZ;
while (true) {
new_len = (new_sz - offsetof(struct netprio_map, priomap)) /
sizeof(new->priomap[0]);
if (new_len > target_idx)
break;
new_sz *= 2;
if (WARN_ON(new_sz < PRIOMAP_MIN_SZ))
return -ENOSPC;
}
new = kzalloc(new_sz, GFP_KERNEL);
if (!new)
return -ENOMEM;
if (old)
memcpy(new->priomap, old->priomap,
old->priomap_len * sizeof(old->priomap[0]));
new->priomap_len = new_len;
rcu_assign_pointer(dev->priomap, new);
if (old)
kfree_rcu(old, rcu);
return 0;
}
static u32 netprio_prio(struct cgroup *cgrp, struct net_device *dev)
{
struct netprio_map *map = rcu_dereference_rtnl(dev->priomap);
if (map && cgrp->id < map->priomap_len)
return map->priomap[cgrp->id];
return 0;
}
static int netprio_set_prio(struct cgroup *cgrp, struct net_device *dev,
u32 prio)
{
struct netprio_map *map;
int ret;
map = rtnl_dereference(dev->priomap);
if (!prio && (!map || map->priomap_len <= cgrp->id))
return 0;
ret = extend_netdev_table(dev, cgrp->id);
if (ret)
return ret;
map = rtnl_dereference(dev->priomap);
map->priomap[cgrp->id] = prio;
return 0;
}
static struct cgroup_subsys_state *cgrp_css_alloc(struct cgroup *cgrp)
{
struct cgroup_netprio_state *cs;
cs = kzalloc(sizeof(*cs), GFP_KERNEL);
if (!cs)
return ERR_PTR(-ENOMEM);
return &cs->css;
}
static int cgrp_css_online(struct cgroup *cgrp)
{
struct cgroup *parent = cgrp->parent;
struct net_device *dev;
int ret = 0;
if (!parent)
return 0;
rtnl_lock();
for_each_netdev(&init_net, dev) {
u32 prio = netprio_prio(parent, dev);
ret = netprio_set_prio(cgrp, dev, prio);
if (ret)
break;
}
rtnl_unlock();
return ret;
}
static void cgrp_css_free(struct cgroup *cgrp)
{
kfree(cgrp_netprio_state(cgrp));
}
static u64 read_prioidx(struct cgroup *cgrp, struct cftype *cft)
{
return cgrp->id;
}
static int read_priomap(struct cgroup *cont, struct cftype *cft,
struct cgroup_map_cb *cb)
{
struct net_device *dev;
rcu_read_lock();
for_each_netdev_rcu(&init_net, dev)
cb->fill(cb, dev->name, netprio_prio(cont, dev));
rcu_read_unlock();
return 0;
}
static int write_priomap(struct cgroup *cgrp, struct cftype *cft,
const char *buffer)
{
char devname[IFNAMSIZ + 1];
struct net_device *dev;
u32 prio;
int ret;
if (sscanf(buffer, "%"__stringify(IFNAMSIZ)"s %u", devname, &prio) != 2)
return -EINVAL;
dev = dev_get_by_name(&init_net, devname);
if (!dev)
return -ENODEV;
rtnl_lock();
ret = netprio_set_prio(cgrp, dev, prio);
rtnl_unlock();
dev_put(dev);
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
static void net_prio_attach(struct cgroup *cgrp, struct cgroup_taskset *tset)
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
