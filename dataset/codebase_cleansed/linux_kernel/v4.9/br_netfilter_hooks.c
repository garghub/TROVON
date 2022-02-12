static inline __be16 vlan_proto(const struct sk_buff *skb)
{
if (skb_vlan_tag_present(skb))
return skb->protocol;
else if (skb->protocol == htons(ETH_P_8021Q))
return vlan_eth_hdr(skb)->h_vlan_encapsulated_proto;
else
return 0;
}
static inline __be16 pppoe_proto(const struct sk_buff *skb)
{
return *((__be16 *)(skb_mac_header(skb) + ETH_HLEN +
sizeof(struct pppoe_hdr)));
}
static void nf_bridge_info_free(struct sk_buff *skb)
{
if (skb->nf_bridge) {
nf_bridge_put(skb->nf_bridge);
skb->nf_bridge = NULL;
}
}
static inline struct net_device *bridge_parent(const struct net_device *dev)
{
struct net_bridge_port *port;
port = br_port_get_rcu(dev);
return port ? port->br->dev : NULL;
}
static inline struct nf_bridge_info *nf_bridge_unshare(struct sk_buff *skb)
{
struct nf_bridge_info *nf_bridge = skb->nf_bridge;
if (atomic_read(&nf_bridge->use) > 1) {
struct nf_bridge_info *tmp = nf_bridge_alloc(skb);
if (tmp) {
memcpy(tmp, nf_bridge, sizeof(struct nf_bridge_info));
atomic_set(&tmp->use, 1);
}
nf_bridge_put(nf_bridge);
nf_bridge = tmp;
}
return nf_bridge;
}
unsigned int nf_bridge_encap_header_len(const struct sk_buff *skb)
{
switch (skb->protocol) {
case __cpu_to_be16(ETH_P_8021Q):
return VLAN_HLEN;
case __cpu_to_be16(ETH_P_PPP_SES):
return PPPOE_SES_HLEN;
default:
return 0;
}
}
static inline void nf_bridge_pull_encap_header(struct sk_buff *skb)
{
unsigned int len = nf_bridge_encap_header_len(skb);
skb_pull(skb, len);
skb->network_header += len;
}
static inline void nf_bridge_pull_encap_header_rcsum(struct sk_buff *skb)
{
unsigned int len = nf_bridge_encap_header_len(skb);
skb_pull_rcsum(skb, len);
skb->network_header += len;
}
static int br_validate_ipv4(struct net *net, struct sk_buff *skb)
{
const struct iphdr *iph;
u32 len;
if (!pskb_may_pull(skb, sizeof(struct iphdr)))
goto inhdr_error;
iph = ip_hdr(skb);
if (iph->ihl < 5 || iph->version != 4)
goto inhdr_error;
if (!pskb_may_pull(skb, iph->ihl*4))
goto inhdr_error;
iph = ip_hdr(skb);
if (unlikely(ip_fast_csum((u8 *)iph, iph->ihl)))
goto inhdr_error;
len = ntohs(iph->tot_len);
if (skb->len < len) {
__IP_INC_STATS(net, IPSTATS_MIB_INTRUNCATEDPKTS);
goto drop;
} else if (len < (iph->ihl*4))
goto inhdr_error;
if (pskb_trim_rcsum(skb, len)) {
__IP_INC_STATS(net, IPSTATS_MIB_INDISCARDS);
goto drop;
}
memset(IPCB(skb), 0, sizeof(struct inet_skb_parm));
return 0;
inhdr_error:
__IP_INC_STATS(net, IPSTATS_MIB_INHDRERRORS);
drop:
return -1;
}
void nf_bridge_update_protocol(struct sk_buff *skb)
{
switch (skb->nf_bridge->orig_proto) {
case BRNF_PROTO_8021Q:
skb->protocol = htons(ETH_P_8021Q);
break;
case BRNF_PROTO_PPPOE:
skb->protocol = htons(ETH_P_PPP_SES);
break;
case BRNF_PROTO_UNCHANGED:
break;
}
}
int br_nf_pre_routing_finish_bridge(struct net *net, struct sock *sk, struct sk_buff *skb)
{
struct neighbour *neigh;
struct dst_entry *dst;
skb->dev = bridge_parent(skb->dev);
if (!skb->dev)
goto free_skb;
dst = skb_dst(skb);
neigh = dst_neigh_lookup_skb(dst, skb);
if (neigh) {
struct nf_bridge_info *nf_bridge = nf_bridge_info_get(skb);
int ret;
if (neigh->hh.hh_len) {
neigh_hh_bridge(&neigh->hh, skb);
skb->dev = nf_bridge->physindev;
ret = br_handle_frame_finish(net, sk, skb);
} else {
skb_copy_from_linear_data_offset(skb,
-(ETH_HLEN-ETH_ALEN),
nf_bridge->neigh_header,
ETH_HLEN-ETH_ALEN);
nf_bridge->bridged_dnat = 1;
ret = neigh->output(neigh, skb);
}
neigh_release(neigh);
return ret;
}
free_skb:
kfree_skb(skb);
return 0;
}
static inline bool
br_nf_ipv4_daddr_was_changed(const struct sk_buff *skb,
const struct nf_bridge_info *nf_bridge)
{
return ip_hdr(skb)->daddr != nf_bridge->ipv4_daddr;
}
static int br_nf_pre_routing_finish(struct net *net, struct sock *sk, struct sk_buff *skb)
{
struct net_device *dev = skb->dev;
struct iphdr *iph = ip_hdr(skb);
struct nf_bridge_info *nf_bridge = nf_bridge_info_get(skb);
struct rtable *rt;
int err;
nf_bridge->frag_max_size = IPCB(skb)->frag_max_size;
if (nf_bridge->pkt_otherhost) {
skb->pkt_type = PACKET_OTHERHOST;
nf_bridge->pkt_otherhost = false;
}
nf_bridge->in_prerouting = 0;
if (br_nf_ipv4_daddr_was_changed(skb, nf_bridge)) {
if ((err = ip_route_input(skb, iph->daddr, iph->saddr, iph->tos, dev))) {
struct in_device *in_dev = __in_dev_get_rcu(dev);
if (err != -EHOSTUNREACH || !in_dev || IN_DEV_FORWARD(in_dev))
goto free_skb;
rt = ip_route_output(net, iph->daddr, 0,
RT_TOS(iph->tos), 0);
if (!IS_ERR(rt)) {
if (rt->dst.dev == dev) {
skb_dst_set(skb, &rt->dst);
goto bridged_dnat;
}
ip_rt_put(rt);
}
free_skb:
kfree_skb(skb);
return 0;
} else {
if (skb_dst(skb)->dev == dev) {
bridged_dnat:
skb->dev = nf_bridge->physindev;
nf_bridge_update_protocol(skb);
nf_bridge_push_encap_header(skb);
br_nf_hook_thresh(NF_BR_PRE_ROUTING,
net, sk, skb, skb->dev,
NULL,
br_nf_pre_routing_finish);
return 0;
}
ether_addr_copy(eth_hdr(skb)->h_dest, dev->dev_addr);
skb->pkt_type = PACKET_HOST;
}
} else {
rt = bridge_parent_rtable(nf_bridge->physindev);
if (!rt) {
kfree_skb(skb);
return 0;
}
skb_dst_set_noref(skb, &rt->dst);
}
skb->dev = nf_bridge->physindev;
nf_bridge_update_protocol(skb);
nf_bridge_push_encap_header(skb);
br_nf_hook_thresh(NF_BR_PRE_ROUTING, net, sk, skb, skb->dev, NULL,
br_handle_frame_finish);
return 0;
}
static struct net_device *brnf_get_logical_dev(struct sk_buff *skb, const struct net_device *dev)
{
struct net_device *vlan, *br;
br = bridge_parent(dev);
if (brnf_pass_vlan_indev == 0 || !skb_vlan_tag_present(skb))
return br;
vlan = __vlan_find_dev_deep_rcu(br, skb->vlan_proto,
skb_vlan_tag_get(skb) & VLAN_VID_MASK);
return vlan ? vlan : br;
}
struct net_device *setup_pre_routing(struct sk_buff *skb)
{
struct nf_bridge_info *nf_bridge = nf_bridge_info_get(skb);
if (skb->pkt_type == PACKET_OTHERHOST) {
skb->pkt_type = PACKET_HOST;
nf_bridge->pkt_otherhost = true;
}
nf_bridge->in_prerouting = 1;
nf_bridge->physindev = skb->dev;
skb->dev = brnf_get_logical_dev(skb, skb->dev);
if (skb->protocol == htons(ETH_P_8021Q))
nf_bridge->orig_proto = BRNF_PROTO_8021Q;
else if (skb->protocol == htons(ETH_P_PPP_SES))
nf_bridge->orig_proto = BRNF_PROTO_PPPOE;
skb_orphan(skb);
return skb->dev;
}
static unsigned int br_nf_pre_routing(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
struct nf_bridge_info *nf_bridge;
struct net_bridge_port *p;
struct net_bridge *br;
__u32 len = nf_bridge_encap_header_len(skb);
if (unlikely(!pskb_may_pull(skb, len)))
return NF_DROP;
p = br_port_get_rcu(state->in);
if (p == NULL)
return NF_DROP;
br = p->br;
if (IS_IPV6(skb) || IS_VLAN_IPV6(skb) || IS_PPPOE_IPV6(skb)) {
if (!brnf_call_ip6tables && !br->nf_call_ip6tables)
return NF_ACCEPT;
nf_bridge_pull_encap_header_rcsum(skb);
return br_nf_pre_routing_ipv6(priv, skb, state);
}
if (!brnf_call_iptables && !br->nf_call_iptables)
return NF_ACCEPT;
if (!IS_IP(skb) && !IS_VLAN_IP(skb) && !IS_PPPOE_IP(skb))
return NF_ACCEPT;
nf_bridge_pull_encap_header_rcsum(skb);
if (br_validate_ipv4(state->net, skb))
return NF_DROP;
nf_bridge_put(skb->nf_bridge);
if (!nf_bridge_alloc(skb))
return NF_DROP;
if (!setup_pre_routing(skb))
return NF_DROP;
nf_bridge = nf_bridge_info_get(skb);
nf_bridge->ipv4_daddr = ip_hdr(skb)->daddr;
skb->protocol = htons(ETH_P_IP);
NF_HOOK(NFPROTO_IPV4, NF_INET_PRE_ROUTING, state->net, state->sk, skb,
skb->dev, NULL,
br_nf_pre_routing_finish);
return NF_STOLEN;
}
static unsigned int br_nf_local_in(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
br_drop_fake_rtable(skb);
return NF_ACCEPT;
}
static int br_nf_forward_finish(struct net *net, struct sock *sk, struct sk_buff *skb)
{
struct nf_bridge_info *nf_bridge = nf_bridge_info_get(skb);
struct net_device *in;
if (!IS_ARP(skb) && !IS_VLAN_ARP(skb)) {
if (skb->protocol == htons(ETH_P_IP))
nf_bridge->frag_max_size = IPCB(skb)->frag_max_size;
if (skb->protocol == htons(ETH_P_IPV6))
nf_bridge->frag_max_size = IP6CB(skb)->frag_max_size;
in = nf_bridge->physindev;
if (nf_bridge->pkt_otherhost) {
skb->pkt_type = PACKET_OTHERHOST;
nf_bridge->pkt_otherhost = false;
}
nf_bridge_update_protocol(skb);
} else {
in = *((struct net_device **)(skb->cb));
}
nf_bridge_push_encap_header(skb);
NF_HOOK_THRESH(NFPROTO_BRIDGE, NF_BR_FORWARD, net, sk, skb,
in, skb->dev, br_forward_finish, 1);
return 0;
}
static unsigned int br_nf_forward_ip(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
struct nf_bridge_info *nf_bridge;
struct net_device *parent;
u_int8_t pf;
if (!skb->nf_bridge)
return NF_ACCEPT;
if (!nf_bridge_unshare(skb))
return NF_DROP;
nf_bridge = nf_bridge_info_get(skb);
if (!nf_bridge)
return NF_DROP;
parent = bridge_parent(state->out);
if (!parent)
return NF_DROP;
if (IS_IP(skb) || IS_VLAN_IP(skb) || IS_PPPOE_IP(skb))
pf = NFPROTO_IPV4;
else if (IS_IPV6(skb) || IS_VLAN_IPV6(skb) || IS_PPPOE_IPV6(skb))
pf = NFPROTO_IPV6;
else
return NF_ACCEPT;
nf_bridge_pull_encap_header(skb);
if (skb->pkt_type == PACKET_OTHERHOST) {
skb->pkt_type = PACKET_HOST;
nf_bridge->pkt_otherhost = true;
}
if (pf == NFPROTO_IPV4) {
if (br_validate_ipv4(state->net, skb))
return NF_DROP;
IPCB(skb)->frag_max_size = nf_bridge->frag_max_size;
}
if (pf == NFPROTO_IPV6) {
if (br_validate_ipv6(state->net, skb))
return NF_DROP;
IP6CB(skb)->frag_max_size = nf_bridge->frag_max_size;
}
nf_bridge->physoutdev = skb->dev;
if (pf == NFPROTO_IPV4)
skb->protocol = htons(ETH_P_IP);
else
skb->protocol = htons(ETH_P_IPV6);
NF_HOOK(pf, NF_INET_FORWARD, state->net, NULL, skb,
brnf_get_logical_dev(skb, state->in),
parent, br_nf_forward_finish);
return NF_STOLEN;
}
static unsigned int br_nf_forward_arp(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
struct net_bridge_port *p;
struct net_bridge *br;
struct net_device **d = (struct net_device **)(skb->cb);
p = br_port_get_rcu(state->out);
if (p == NULL)
return NF_ACCEPT;
br = p->br;
if (!brnf_call_arptables && !br->nf_call_arptables)
return NF_ACCEPT;
if (!IS_ARP(skb)) {
if (!IS_VLAN_ARP(skb))
return NF_ACCEPT;
nf_bridge_pull_encap_header(skb);
}
if (arp_hdr(skb)->ar_pln != 4) {
if (IS_VLAN_ARP(skb))
nf_bridge_push_encap_header(skb);
return NF_ACCEPT;
}
*d = state->in;
NF_HOOK(NFPROTO_ARP, NF_ARP_FORWARD, state->net, state->sk, skb,
state->in, state->out, br_nf_forward_finish);
return NF_STOLEN;
}
static int br_nf_push_frag_xmit(struct net *net, struct sock *sk, struct sk_buff *skb)
{
struct brnf_frag_data *data;
int err;
data = this_cpu_ptr(&brnf_frag_data_storage);
err = skb_cow_head(skb, data->size);
if (err) {
kfree_skb(skb);
return 0;
}
if (data->vlan_tci) {
skb->vlan_tci = data->vlan_tci;
skb->vlan_proto = data->vlan_proto;
}
skb_copy_to_linear_data_offset(skb, -data->size, data->mac, data->size);
__skb_push(skb, data->encap_size);
nf_bridge_info_free(skb);
return br_dev_queue_push_xmit(net, sk, skb);
}
static int
br_nf_ip_fragment(struct net *net, struct sock *sk, struct sk_buff *skb,
int (*output)(struct net *, struct sock *, struct sk_buff *))
{
unsigned int mtu = ip_skb_dst_mtu(sk, skb);
struct iphdr *iph = ip_hdr(skb);
if (unlikely(((iph->frag_off & htons(IP_DF)) && !skb->ignore_df) ||
(IPCB(skb)->frag_max_size &&
IPCB(skb)->frag_max_size > mtu))) {
IP_INC_STATS(net, IPSTATS_MIB_FRAGFAILS);
kfree_skb(skb);
return -EMSGSIZE;
}
return ip_do_fragment(net, sk, skb, output);
}
static unsigned int nf_bridge_mtu_reduction(const struct sk_buff *skb)
{
if (skb->nf_bridge->orig_proto == BRNF_PROTO_PPPOE)
return PPPOE_SES_HLEN;
return 0;
}
static int br_nf_dev_queue_xmit(struct net *net, struct sock *sk, struct sk_buff *skb)
{
struct nf_bridge_info *nf_bridge;
unsigned int mtu_reserved;
mtu_reserved = nf_bridge_mtu_reduction(skb);
if (skb_is_gso(skb) || skb->len + mtu_reserved <= skb->dev->mtu) {
nf_bridge_info_free(skb);
return br_dev_queue_push_xmit(net, sk, skb);
}
nf_bridge = nf_bridge_info_get(skb);
if (IS_ENABLED(CONFIG_NF_DEFRAG_IPV4) &&
skb->protocol == htons(ETH_P_IP)) {
struct brnf_frag_data *data;
if (br_validate_ipv4(net, skb))
goto drop;
IPCB(skb)->frag_max_size = nf_bridge->frag_max_size;
nf_bridge_update_protocol(skb);
data = this_cpu_ptr(&brnf_frag_data_storage);
data->vlan_tci = skb->vlan_tci;
data->vlan_proto = skb->vlan_proto;
data->encap_size = nf_bridge_encap_header_len(skb);
data->size = ETH_HLEN + data->encap_size;
skb_copy_from_linear_data_offset(skb, -data->size, data->mac,
data->size);
return br_nf_ip_fragment(net, sk, skb, br_nf_push_frag_xmit);
}
if (IS_ENABLED(CONFIG_NF_DEFRAG_IPV6) &&
skb->protocol == htons(ETH_P_IPV6)) {
const struct nf_ipv6_ops *v6ops = nf_get_ipv6_ops();
struct brnf_frag_data *data;
if (br_validate_ipv6(net, skb))
goto drop;
IP6CB(skb)->frag_max_size = nf_bridge->frag_max_size;
nf_bridge_update_protocol(skb);
data = this_cpu_ptr(&brnf_frag_data_storage);
data->encap_size = nf_bridge_encap_header_len(skb);
data->size = ETH_HLEN + data->encap_size;
skb_copy_from_linear_data_offset(skb, -data->size, data->mac,
data->size);
if (v6ops)
return v6ops->fragment(net, sk, skb, br_nf_push_frag_xmit);
kfree_skb(skb);
return -EMSGSIZE;
}
nf_bridge_info_free(skb);
return br_dev_queue_push_xmit(net, sk, skb);
drop:
kfree_skb(skb);
return 0;
}
static unsigned int br_nf_post_routing(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
struct nf_bridge_info *nf_bridge = nf_bridge_info_get(skb);
struct net_device *realoutdev = bridge_parent(skb->dev);
u_int8_t pf;
if (!nf_bridge || !nf_bridge->physoutdev)
return NF_ACCEPT;
if (!realoutdev)
return NF_DROP;
if (IS_IP(skb) || IS_VLAN_IP(skb) || IS_PPPOE_IP(skb))
pf = NFPROTO_IPV4;
else if (IS_IPV6(skb) || IS_VLAN_IPV6(skb) || IS_PPPOE_IPV6(skb))
pf = NFPROTO_IPV6;
else
return NF_ACCEPT;
if (skb->pkt_type == PACKET_OTHERHOST) {
skb->pkt_type = PACKET_HOST;
nf_bridge->pkt_otherhost = true;
}
nf_bridge_pull_encap_header(skb);
if (pf == NFPROTO_IPV4)
skb->protocol = htons(ETH_P_IP);
else
skb->protocol = htons(ETH_P_IPV6);
NF_HOOK(pf, NF_INET_POST_ROUTING, state->net, state->sk, skb,
NULL, realoutdev,
br_nf_dev_queue_xmit);
return NF_STOLEN;
}
static unsigned int ip_sabotage_in(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
if (skb->nf_bridge && !skb->nf_bridge->in_prerouting)
return NF_STOP;
return NF_ACCEPT;
}
static void br_nf_pre_routing_finish_bridge_slow(struct sk_buff *skb)
{
struct nf_bridge_info *nf_bridge = nf_bridge_info_get(skb);
skb_pull(skb, ETH_HLEN);
nf_bridge->bridged_dnat = 0;
BUILD_BUG_ON(sizeof(nf_bridge->neigh_header) != (ETH_HLEN - ETH_ALEN));
skb_copy_to_linear_data_offset(skb, -(ETH_HLEN - ETH_ALEN),
nf_bridge->neigh_header,
ETH_HLEN - ETH_ALEN);
skb->dev = nf_bridge->physindev;
nf_bridge->physoutdev = NULL;
br_handle_frame_finish(dev_net(skb->dev), NULL, skb);
}
static int br_nf_dev_xmit(struct sk_buff *skb)
{
if (skb->nf_bridge && skb->nf_bridge->bridged_dnat) {
br_nf_pre_routing_finish_bridge_slow(skb);
return 1;
}
return 0;
}
void br_netfilter_enable(void)
{
}
static int brnf_device_event(struct notifier_block *unused, unsigned long event,
void *ptr)
{
struct net_device *dev = netdev_notifier_info_to_dev(ptr);
struct brnf_net *brnet;
struct net *net;
int ret;
if (event != NETDEV_REGISTER || !(dev->priv_flags & IFF_EBRIDGE))
return NOTIFY_DONE;
ASSERT_RTNL();
net = dev_net(dev);
brnet = net_generic(net, brnf_net_id);
if (brnet->enabled)
return NOTIFY_OK;
ret = nf_register_net_hooks(net, br_nf_ops, ARRAY_SIZE(br_nf_ops));
if (ret)
return NOTIFY_BAD;
brnet->enabled = true;
return NOTIFY_OK;
}
static void __net_exit brnf_exit_net(struct net *net)
{
struct brnf_net *brnet = net_generic(net, brnf_net_id);
if (!brnet->enabled)
return;
nf_unregister_net_hooks(net, br_nf_ops, ARRAY_SIZE(br_nf_ops));
brnet->enabled = false;
}
int br_nf_hook_thresh(unsigned int hook, struct net *net,
struct sock *sk, struct sk_buff *skb,
struct net_device *indev,
struct net_device *outdev,
int (*okfn)(struct net *, struct sock *,
struct sk_buff *))
{
struct nf_hook_entry *elem;
struct nf_hook_state state;
int ret;
elem = rcu_dereference(net->nf.hooks[NFPROTO_BRIDGE][hook]);
while (elem && (elem->ops.priority <= NF_BR_PRI_BRNF))
elem = rcu_dereference(elem->next);
if (!elem)
return okfn(net, sk, skb);
rcu_read_lock();
nf_hook_state_init(&state, elem, hook, NF_BR_PRI_BRNF + 1,
NFPROTO_BRIDGE, indev, outdev, sk, net, okfn);
ret = nf_hook_slow(skb, &state);
rcu_read_unlock();
if (ret == 1)
ret = okfn(net, sk, skb);
return ret;
}
static
int brnf_sysctl_call_tables(struct ctl_table *ctl, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
int ret;
ret = proc_dointvec(ctl, write, buffer, lenp, ppos);
if (write && *(int *)(ctl->data))
*(int *)(ctl->data) = 1;
return ret;
}
static int __init br_netfilter_init(void)
{
int ret;
ret = register_pernet_subsys(&brnf_net_ops);
if (ret < 0)
return ret;
ret = register_netdevice_notifier(&brnf_notifier);
if (ret < 0) {
unregister_pernet_subsys(&brnf_net_ops);
return ret;
}
#ifdef CONFIG_SYSCTL
brnf_sysctl_header = register_net_sysctl(&init_net, "net/bridge", brnf_table);
if (brnf_sysctl_header == NULL) {
printk(KERN_WARNING
"br_netfilter: can't register to sysctl.\n");
unregister_netdevice_notifier(&brnf_notifier);
unregister_pernet_subsys(&brnf_net_ops);
return -ENOMEM;
}
#endif
RCU_INIT_POINTER(nf_br_ops, &br_ops);
printk(KERN_NOTICE "Bridge firewalling registered\n");
return 0;
}
static void __exit br_netfilter_fini(void)
{
RCU_INIT_POINTER(nf_br_ops, NULL);
unregister_netdevice_notifier(&brnf_notifier);
unregister_pernet_subsys(&brnf_net_ops);
#ifdef CONFIG_SYSCTL
unregister_net_sysctl_table(brnf_sysctl_header);
#endif
}
