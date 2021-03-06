void nf_register_queue_handler(const struct nf_queue_handler *qh)
{
WARN_ON(rcu_access_pointer(queue_handler));
rcu_assign_pointer(queue_handler, qh);
}
void nf_unregister_queue_handler(void)
{
RCU_INIT_POINTER(queue_handler, NULL);
synchronize_rcu();
}
static void nf_queue_entry_release_refs(struct nf_queue_entry *entry)
{
if (entry->indev)
dev_put(entry->indev);
if (entry->outdev)
dev_put(entry->outdev);
#ifdef CONFIG_BRIDGE_NETFILTER
if (entry->skb->nf_bridge) {
struct nf_bridge_info *nf_bridge = entry->skb->nf_bridge;
if (nf_bridge->physindev)
dev_put(nf_bridge->physindev);
if (nf_bridge->physoutdev)
dev_put(nf_bridge->physoutdev);
}
#endif
module_put(entry->elem->owner);
}
static int __nf_queue(struct sk_buff *skb,
struct nf_hook_ops *elem,
u_int8_t pf, unsigned int hook,
struct net_device *indev,
struct net_device *outdev,
int (*okfn)(struct sk_buff *),
unsigned int queuenum)
{
int status = -ENOENT;
struct nf_queue_entry *entry = NULL;
#ifdef CONFIG_BRIDGE_NETFILTER
struct net_device *physindev;
struct net_device *physoutdev;
#endif
const struct nf_afinfo *afinfo;
const struct nf_queue_handler *qh;
rcu_read_lock();
qh = rcu_dereference(queue_handler);
if (!qh) {
status = -ESRCH;
goto err_unlock;
}
afinfo = nf_get_afinfo(pf);
if (!afinfo)
goto err_unlock;
entry = kmalloc(sizeof(*entry) + afinfo->route_key_size, GFP_ATOMIC);
if (!entry) {
status = -ENOMEM;
goto err_unlock;
}
*entry = (struct nf_queue_entry) {
.skb = skb,
.elem = elem,
.pf = pf,
.hook = hook,
.indev = indev,
.outdev = outdev,
.okfn = okfn,
};
if (!try_module_get(entry->elem->owner)) {
status = -ECANCELED;
goto err_unlock;
}
if (indev)
dev_hold(indev);
if (outdev)
dev_hold(outdev);
#ifdef CONFIG_BRIDGE_NETFILTER
if (skb->nf_bridge) {
physindev = skb->nf_bridge->physindev;
if (physindev)
dev_hold(physindev);
physoutdev = skb->nf_bridge->physoutdev;
if (physoutdev)
dev_hold(physoutdev);
}
#endif
skb_dst_force(skb);
afinfo->saveroute(skb, entry);
status = qh->outfn(entry, queuenum);
rcu_read_unlock();
if (status < 0) {
nf_queue_entry_release_refs(entry);
goto err;
}
return 0;
err_unlock:
rcu_read_unlock();
err:
kfree(entry);
return status;
}
static void nf_bridge_adjust_skb_data(struct sk_buff *skb)
{
if (skb->nf_bridge)
__skb_push(skb, skb->network_header - skb->mac_header);
}
static void nf_bridge_adjust_segmented_data(struct sk_buff *skb)
{
if (skb->nf_bridge)
__skb_pull(skb, skb->network_header - skb->mac_header);
}
int nf_queue(struct sk_buff *skb,
struct nf_hook_ops *elem,
u_int8_t pf, unsigned int hook,
struct net_device *indev,
struct net_device *outdev,
int (*okfn)(struct sk_buff *),
unsigned int queuenum)
{
struct sk_buff *segs;
int err = -EINVAL;
unsigned int queued;
if (!skb_is_gso(skb))
return __nf_queue(skb, elem, pf, hook, indev, outdev, okfn,
queuenum);
switch (pf) {
case NFPROTO_IPV4:
skb->protocol = htons(ETH_P_IP);
break;
case NFPROTO_IPV6:
skb->protocol = htons(ETH_P_IPV6);
break;
}
nf_bridge_adjust_skb_data(skb);
segs = skb_gso_segment(skb, 0);
if (IS_ERR(segs))
goto out_err;
queued = 0;
err = 0;
do {
struct sk_buff *nskb = segs->next;
segs->next = NULL;
if (err == 0) {
nf_bridge_adjust_segmented_data(segs);
err = __nf_queue(segs, elem, pf, hook, indev,
outdev, okfn, queuenum);
}
if (err == 0)
queued++;
else
kfree_skb(segs);
segs = nskb;
} while (segs);
if (queued) {
kfree_skb(skb);
return 0;
}
out_err:
nf_bridge_adjust_segmented_data(skb);
return err;
}
void nf_reinject(struct nf_queue_entry *entry, unsigned int verdict)
{
struct sk_buff *skb = entry->skb;
struct nf_hook_ops *elem = entry->elem;
const struct nf_afinfo *afinfo;
int err;
rcu_read_lock();
nf_queue_entry_release_refs(entry);
if (verdict == NF_REPEAT) {
elem = list_entry(elem->list.prev, struct nf_hook_ops, list);
verdict = NF_ACCEPT;
}
if (verdict == NF_ACCEPT) {
afinfo = nf_get_afinfo(entry->pf);
if (!afinfo || afinfo->reroute(skb, entry) < 0)
verdict = NF_DROP;
}
if (verdict == NF_ACCEPT) {
next_hook:
verdict = nf_iterate(&nf_hooks[entry->pf][entry->hook],
skb, entry->hook,
entry->indev, entry->outdev, &elem,
entry->okfn, INT_MIN);
}
switch (verdict & NF_VERDICT_MASK) {
case NF_ACCEPT:
case NF_STOP:
local_bh_disable();
entry->okfn(skb);
local_bh_enable();
break;
case NF_QUEUE:
err = __nf_queue(skb, elem, entry->pf, entry->hook,
entry->indev, entry->outdev, entry->okfn,
verdict >> NF_VERDICT_QBITS);
if (err < 0) {
if (err == -ECANCELED)
goto next_hook;
if (err == -ESRCH &&
(verdict & NF_VERDICT_FLAG_QUEUE_BYPASS))
goto next_hook;
kfree_skb(skb);
}
break;
case NF_STOLEN:
break;
default:
kfree_skb(skb);
}
rcu_read_unlock();
kfree(entry);
}
