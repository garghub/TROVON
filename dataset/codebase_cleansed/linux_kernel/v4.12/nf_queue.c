void nf_register_queue_handler(struct net *net, const struct nf_queue_handler *qh)
{
WARN_ON(rcu_access_pointer(net->nf.queue_handler));
rcu_assign_pointer(net->nf.queue_handler, qh);
}
void nf_unregister_queue_handler(struct net *net)
{
RCU_INIT_POINTER(net->nf.queue_handler, NULL);
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
}
void nf_queue_entry_get_refs(struct nf_queue_entry *entry)
{
struct nf_hook_state *state = &entry->state;
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
}
unsigned int nf_queue_nf_hook_drop(struct net *net)
{
const struct nf_queue_handler *qh;
unsigned int count = 0;
rcu_read_lock();
qh = rcu_dereference(net->nf.queue_handler);
if (qh)
count = qh->nf_hook_drop(net);
rcu_read_unlock();
return count;
}
static int __nf_queue(struct sk_buff *skb, const struct nf_hook_state *state,
struct nf_hook_entry *hook_entry, unsigned int queuenum)
{
int status = -ENOENT;
struct nf_queue_entry *entry = NULL;
const struct nf_afinfo *afinfo;
const struct nf_queue_handler *qh;
struct net *net = state->net;
qh = rcu_dereference(net->nf.queue_handler);
if (!qh) {
status = -ESRCH;
goto err;
}
afinfo = nf_get_afinfo(state->pf);
if (!afinfo)
goto err;
entry = kmalloc(sizeof(*entry) + afinfo->route_key_size, GFP_ATOMIC);
if (!entry) {
status = -ENOMEM;
goto err;
}
*entry = (struct nf_queue_entry) {
.skb = skb,
.state = *state,
.hook = hook_entry,
.size = sizeof(*entry) + afinfo->route_key_size,
};
nf_queue_entry_get_refs(entry);
skb_dst_force(skb);
afinfo->saveroute(skb, entry);
status = qh->outfn(entry, queuenum);
if (status < 0) {
nf_queue_entry_release_refs(entry);
goto err;
}
return 0;
err:
kfree(entry);
return status;
}
int nf_queue(struct sk_buff *skb, struct nf_hook_state *state,
struct nf_hook_entry **entryp, unsigned int verdict)
{
struct nf_hook_entry *entry = *entryp;
int ret;
ret = __nf_queue(skb, state, entry, verdict >> NF_VERDICT_QBITS);
if (ret < 0) {
if (ret == -ESRCH &&
(verdict & NF_VERDICT_FLAG_QUEUE_BYPASS)) {
*entryp = rcu_dereference(entry->next);
return 1;
}
kfree_skb(skb);
}
return 0;
}
static unsigned int nf_iterate(struct sk_buff *skb,
struct nf_hook_state *state,
struct nf_hook_entry **entryp)
{
unsigned int verdict;
do {
repeat:
verdict = nf_hook_entry_hookfn((*entryp), skb, state);
if (verdict != NF_ACCEPT) {
if (verdict != NF_REPEAT)
return verdict;
goto repeat;
}
*entryp = rcu_dereference((*entryp)->next);
} while (*entryp);
return NF_ACCEPT;
}
void nf_reinject(struct nf_queue_entry *entry, unsigned int verdict)
{
struct nf_hook_entry *hook_entry = entry->hook;
struct sk_buff *skb = entry->skb;
const struct nf_afinfo *afinfo;
int err;
nf_queue_entry_release_refs(entry);
if (verdict == NF_REPEAT)
verdict = nf_hook_entry_hookfn(hook_entry, skb, &entry->state);
if (verdict == NF_ACCEPT) {
afinfo = nf_get_afinfo(entry->state.pf);
if (!afinfo || afinfo->reroute(entry->state.net, skb, entry) < 0)
verdict = NF_DROP;
}
if (verdict == NF_ACCEPT) {
hook_entry = rcu_dereference(hook_entry->next);
if (hook_entry)
next_hook:
verdict = nf_iterate(skb, &entry->state, &hook_entry);
}
switch (verdict & NF_VERDICT_MASK) {
case NF_ACCEPT:
case NF_STOP:
okfn:
local_bh_disable();
entry->state.okfn(entry->state.net, entry->state.sk, skb);
local_bh_enable();
break;
case NF_QUEUE:
err = nf_queue(skb, &entry->state, &hook_entry, verdict);
if (err == 1) {
if (hook_entry)
goto next_hook;
goto okfn;
}
break;
case NF_STOLEN:
break;
default:
kfree_skb(skb);
}
kfree(entry);
}
