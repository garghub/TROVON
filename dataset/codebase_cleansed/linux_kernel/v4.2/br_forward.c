static inline int should_deliver(const struct net_bridge_port *p,
const struct sk_buff *skb)
{
return ((p->flags & BR_HAIRPIN_MODE) || skb->dev != p->dev) &&
br_allowed_egress(p->br, nbp_get_vlan_info(p), skb) &&
p->state == BR_STATE_FORWARDING;
}
int br_dev_queue_push_xmit(struct sock *sk, struct sk_buff *skb)
{
if (!is_skb_forwardable(skb->dev, skb))
goto drop;
skb_push(skb, ETH_HLEN);
br_drop_fake_rtable(skb);
skb_sender_cpu_clear(skb);
if (skb->ip_summed == CHECKSUM_PARTIAL &&
(skb->protocol == htons(ETH_P_8021Q) ||
skb->protocol == htons(ETH_P_8021AD))) {
int depth;
if (!__vlan_get_protocol(skb, skb->protocol, &depth))
goto drop;
skb_set_network_header(skb, depth);
}
dev_queue_xmit(skb);
return 0;
drop:
kfree_skb(skb);
return 0;
}
int br_forward_finish(struct sock *sk, struct sk_buff *skb)
{
return NF_HOOK(NFPROTO_BRIDGE, NF_BR_POST_ROUTING, sk, skb,
NULL, skb->dev,
br_dev_queue_push_xmit);
}
static void __br_deliver(const struct net_bridge_port *to, struct sk_buff *skb)
{
skb = br_handle_vlan(to->br, nbp_get_vlan_info(to), skb);
if (!skb)
return;
skb->dev = to->dev;
if (unlikely(netpoll_tx_running(to->br->dev))) {
if (!is_skb_forwardable(skb->dev, skb))
kfree_skb(skb);
else {
skb_push(skb, ETH_HLEN);
br_netpoll_send_skb(to, skb);
}
return;
}
NF_HOOK(NFPROTO_BRIDGE, NF_BR_LOCAL_OUT, NULL, skb,
NULL, skb->dev,
br_forward_finish);
}
static void __br_forward(const struct net_bridge_port *to, struct sk_buff *skb)
{
struct net_device *indev;
if (skb_warn_if_lro(skb)) {
kfree_skb(skb);
return;
}
skb = br_handle_vlan(to->br, nbp_get_vlan_info(to), skb);
if (!skb)
return;
indev = skb->dev;
skb->dev = to->dev;
skb_forward_csum(skb);
NF_HOOK(NFPROTO_BRIDGE, NF_BR_FORWARD, NULL, skb,
indev, skb->dev,
br_forward_finish);
}
void br_deliver(const struct net_bridge_port *to, struct sk_buff *skb)
{
if (to && should_deliver(to, skb)) {
__br_deliver(to, skb);
return;
}
kfree_skb(skb);
}
void br_forward(const struct net_bridge_port *to, struct sk_buff *skb, struct sk_buff *skb0)
{
if (should_deliver(to, skb)) {
if (skb0)
deliver_clone(to, skb, __br_forward);
else
__br_forward(to, skb);
return;
}
if (!skb0)
kfree_skb(skb);
}
static int deliver_clone(const struct net_bridge_port *prev,
struct sk_buff *skb,
void (*__packet_hook)(const struct net_bridge_port *p,
struct sk_buff *skb))
{
struct net_device *dev = BR_INPUT_SKB_CB(skb)->brdev;
skb = skb_clone(skb, GFP_ATOMIC);
if (!skb) {
dev->stats.tx_dropped++;
return -ENOMEM;
}
__packet_hook(prev, skb);
return 0;
}
static struct net_bridge_port *maybe_deliver(
struct net_bridge_port *prev, struct net_bridge_port *p,
struct sk_buff *skb,
void (*__packet_hook)(const struct net_bridge_port *p,
struct sk_buff *skb))
{
int err;
if (!should_deliver(p, skb))
return prev;
if (!prev)
goto out;
err = deliver_clone(prev, skb, __packet_hook);
if (err)
return ERR_PTR(err);
out:
return p;
}
static void br_flood(struct net_bridge *br, struct sk_buff *skb,
struct sk_buff *skb0,
void (*__packet_hook)(const struct net_bridge_port *p,
struct sk_buff *skb),
bool unicast)
{
struct net_bridge_port *p;
struct net_bridge_port *prev;
prev = NULL;
list_for_each_entry_rcu(p, &br->port_list, list) {
if (unicast && !(p->flags & BR_FLOOD))
continue;
if (p->flags & BR_PROXYARP)
continue;
if ((p->flags & BR_PROXYARP_WIFI) &&
BR_INPUT_SKB_CB(skb)->proxyarp_replied)
continue;
prev = maybe_deliver(prev, p, skb, __packet_hook);
if (IS_ERR(prev))
goto out;
}
if (!prev)
goto out;
if (skb0)
deliver_clone(prev, skb, __packet_hook);
else
__packet_hook(prev, skb);
return;
out:
if (!skb0)
kfree_skb(skb);
}
void br_flood_deliver(struct net_bridge *br, struct sk_buff *skb, bool unicast)
{
br_flood(br, skb, NULL, __br_deliver, unicast);
}
void br_flood_forward(struct net_bridge *br, struct sk_buff *skb,
struct sk_buff *skb2, bool unicast)
{
br_flood(br, skb, skb2, __br_forward, unicast);
}
static void br_multicast_flood(struct net_bridge_mdb_entry *mdst,
struct sk_buff *skb, struct sk_buff *skb0,
void (*__packet_hook)(
const struct net_bridge_port *p,
struct sk_buff *skb))
{
struct net_device *dev = BR_INPUT_SKB_CB(skb)->brdev;
struct net_bridge *br = netdev_priv(dev);
struct net_bridge_port *prev = NULL;
struct net_bridge_port_group *p;
struct hlist_node *rp;
rp = rcu_dereference(hlist_first_rcu(&br->router_list));
p = mdst ? rcu_dereference(mdst->ports) : NULL;
while (p || rp) {
struct net_bridge_port *port, *lport, *rport;
lport = p ? p->port : NULL;
rport = rp ? hlist_entry(rp, struct net_bridge_port, rlist) :
NULL;
port = (unsigned long)lport > (unsigned long)rport ?
lport : rport;
prev = maybe_deliver(prev, port, skb, __packet_hook);
if (IS_ERR(prev))
goto out;
if ((unsigned long)lport >= (unsigned long)port)
p = rcu_dereference(p->next);
if ((unsigned long)rport >= (unsigned long)port)
rp = rcu_dereference(hlist_next_rcu(rp));
}
if (!prev)
goto out;
if (skb0)
deliver_clone(prev, skb, __packet_hook);
else
__packet_hook(prev, skb);
return;
out:
if (!skb0)
kfree_skb(skb);
}
void br_multicast_deliver(struct net_bridge_mdb_entry *mdst,
struct sk_buff *skb)
{
br_multicast_flood(mdst, skb, NULL, __br_deliver);
}
void br_multicast_forward(struct net_bridge_mdb_entry *mdst,
struct sk_buff *skb, struct sk_buff *skb2)
{
br_multicast_flood(mdst, skb, skb2, __br_forward);
}
