static int x25_add_route(struct x25_address *address, unsigned int sigdigits,
struct net_device *dev)
{
struct x25_route *rt;
struct list_head *entry;
int rc = -EINVAL;
write_lock_bh(&x25_route_list_lock);
list_for_each(entry, &x25_route_list) {
rt = list_entry(entry, struct x25_route, node);
if (!memcmp(&rt->address, address, sigdigits) &&
rt->sigdigits == sigdigits)
goto out;
}
rt = kmalloc(sizeof(*rt), GFP_ATOMIC);
rc = -ENOMEM;
if (!rt)
goto out;
strcpy(rt->address.x25_addr, "000000000000000");
memcpy(rt->address.x25_addr, address->x25_addr, sigdigits);
rt->sigdigits = sigdigits;
rt->dev = dev;
refcount_set(&rt->refcnt, 1);
list_add(&rt->node, &x25_route_list);
rc = 0;
out:
write_unlock_bh(&x25_route_list_lock);
return rc;
}
static void __x25_remove_route(struct x25_route *rt)
{
if (rt->node.next) {
list_del(&rt->node);
x25_route_put(rt);
}
}
static int x25_del_route(struct x25_address *address, unsigned int sigdigits,
struct net_device *dev)
{
struct x25_route *rt;
struct list_head *entry;
int rc = -EINVAL;
write_lock_bh(&x25_route_list_lock);
list_for_each(entry, &x25_route_list) {
rt = list_entry(entry, struct x25_route, node);
if (!memcmp(&rt->address, address, sigdigits) &&
rt->sigdigits == sigdigits && rt->dev == dev) {
__x25_remove_route(rt);
rc = 0;
break;
}
}
write_unlock_bh(&x25_route_list_lock);
return rc;
}
void x25_route_device_down(struct net_device *dev)
{
struct x25_route *rt;
struct list_head *entry, *tmp;
write_lock_bh(&x25_route_list_lock);
list_for_each_safe(entry, tmp, &x25_route_list) {
rt = list_entry(entry, struct x25_route, node);
if (rt->dev == dev)
__x25_remove_route(rt);
}
write_unlock_bh(&x25_route_list_lock);
x25_clear_forward_by_dev(dev);
}
struct net_device *x25_dev_get(char *devname)
{
struct net_device *dev = dev_get_by_name(&init_net, devname);
if (dev &&
(!(dev->flags & IFF_UP) || (dev->type != ARPHRD_X25
#if IS_ENABLED(CONFIG_LLC)
&& dev->type != ARPHRD_ETHER
#endif
))){
dev_put(dev);
dev = NULL;
}
return dev;
}
struct x25_route *x25_get_route(struct x25_address *addr)
{
struct x25_route *rt, *use = NULL;
struct list_head *entry;
read_lock_bh(&x25_route_list_lock);
list_for_each(entry, &x25_route_list) {
rt = list_entry(entry, struct x25_route, node);
if (!memcmp(&rt->address, addr, rt->sigdigits)) {
if (!use)
use = rt;
else if (rt->sigdigits > use->sigdigits)
use = rt;
}
}
if (use)
x25_route_hold(use);
read_unlock_bh(&x25_route_list_lock);
return use;
}
int x25_route_ioctl(unsigned int cmd, void __user *arg)
{
struct x25_route_struct rt;
struct net_device *dev;
int rc = -EINVAL;
if (cmd != SIOCADDRT && cmd != SIOCDELRT)
goto out;
rc = -EFAULT;
if (copy_from_user(&rt, arg, sizeof(rt)))
goto out;
rc = -EINVAL;
if (rt.sigdigits > 15)
goto out;
dev = x25_dev_get(rt.device);
if (!dev)
goto out;
if (cmd == SIOCADDRT)
rc = x25_add_route(&rt.address, rt.sigdigits, dev);
else
rc = x25_del_route(&rt.address, rt.sigdigits, dev);
dev_put(dev);
out:
return rc;
}
void __exit x25_route_free(void)
{
struct x25_route *rt;
struct list_head *entry, *tmp;
write_lock_bh(&x25_route_list_lock);
list_for_each_safe(entry, tmp, &x25_route_list) {
rt = list_entry(entry, struct x25_route, node);
__x25_remove_route(rt);
}
write_unlock_bh(&x25_route_list_lock);
}
