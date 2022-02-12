int vsock_add_tap(struct vsock_tap *vt)
{
if (unlikely(vt->dev->type != ARPHRD_VSOCKMON))
return -EINVAL;
__module_get(vt->module);
spin_lock(&vsock_tap_lock);
list_add_rcu(&vt->list, &vsock_tap_all);
spin_unlock(&vsock_tap_lock);
return 0;
}
int vsock_remove_tap(struct vsock_tap *vt)
{
struct vsock_tap *tmp;
bool found = false;
spin_lock(&vsock_tap_lock);
list_for_each_entry(tmp, &vsock_tap_all, list) {
if (vt == tmp) {
list_del_rcu(&vt->list);
found = true;
goto out;
}
}
pr_warn("vsock_remove_tap: %p not found\n", vt);
out:
spin_unlock(&vsock_tap_lock);
synchronize_net();
if (found)
module_put(vt->module);
return found ? 0 : -ENODEV;
}
static int __vsock_deliver_tap_skb(struct sk_buff *skb,
struct net_device *dev)
{
int ret = 0;
struct sk_buff *nskb = skb_clone(skb, GFP_ATOMIC);
if (nskb) {
dev_hold(dev);
nskb->dev = dev;
ret = dev_queue_xmit(nskb);
if (unlikely(ret > 0))
ret = net_xmit_errno(ret);
dev_put(dev);
}
return ret;
}
static void __vsock_deliver_tap(struct sk_buff *skb)
{
int ret;
struct vsock_tap *tmp;
list_for_each_entry_rcu(tmp, &vsock_tap_all, list) {
ret = __vsock_deliver_tap_skb(skb, tmp->dev);
if (unlikely(ret))
break;
}
}
