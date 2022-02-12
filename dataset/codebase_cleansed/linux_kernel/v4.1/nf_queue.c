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
void nf_queue_entry_release_refs(struct nf_queue_entry *entry)
{
struct nf_hook_state *state = &entry->state;
if (state->in)
dev_put(state->in);
if (state->out)
dev_put(state->out);
if (state->sk)
sock_put(state->sk);
#if IS_ENABLED(CONFIG_BRIDGE_NETFILTER)
if (entry->skb->nf_bridge) {
struct net_device *physdev;
physdev = nf_bridge_get_physindev(entry->skb);
if (physdev)
dev_put(physdev);
physdev = nf_bridge_get_physoutdev(entry->skb);
if (physdev)
dev_put(physdev);
}
#endif
module_put(entry->elem->owner);
}
bool nf_queue_entry_get_refs(struct nf_queue_entry *entry)
{
struct nf_hook_state *state = &entry->state;
if (!try_module_get(entry->elem->owner))
return false;
if (state->in)
dev_hold(state->in);
if (state->out)
dev_hold(state->out);
if (state->sk)
sock_hold(state->sk);
#if IS_ENABLED(CONFIG_BRIDGE_NETFILTER)
if (entry->skb->nf_bridge) {
struct net_device *physdev;
physdev = nf_bridge_get_physindev(entry->skb);
if (physdev)
dev_hold(physdev);
physdev = nf_bridge_get_physoutdev(entry->skb);
if (physdev)
dev_hold(physdev);
}
#endif
return true;
}
int nf_queue(struct sk_buff *skb,
struct nf_hook_ops *elem,
struct nf_hook_state *state,
unsigned int queuenum)
{
int status = -ENOENT;
struct nf_queue_entry *entry = NULL;
const struct nf_afinfo *afinfo;
const struct nf_queue_handler *qh;
rcu_read_lock();
qh = rcu_dereference(queue_handler);
if (!qh) {
status = -ESRCH;
goto err_unlock;
}
afinfo = nf_get_afinfo(state->pf);
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
.state = *state,
.size = sizeof(*entry) + afinfo->route_key_size,
};
if (!nf_queue_entry_get_refs(entry)) {
status = -ECANCELED;
goto err_unlock;
}
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
afinfo = nf_get_afinfo(entry->state.pf);
if (!afinfo || afinfo->reroute(skb, entry) < 0)
verdict = NF_DROP;
}
entry->state.thresh = INT_MIN;
if (verdict == NF_ACCEPT) {
next_hook:
verdict = nf_iterate(&nf_hooks[entry->state.pf][entry->state.hook],
skb, &entry->state, &elem);
}
switch (verdict & NF_VERDICT_MASK) {
case NF_ACCEPT:
case NF_STOP:
local_bh_disable();
entry->state.okfn(entry->state.sk, skb);
local_bh_enable();
break;
case NF_QUEUE:
err = nf_queue(skb, elem, &entry->state,
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
