static __be32 be64_get_low32(__be64 x)
{
#ifdef __BIG_ENDIAN
return (__force __be32)x;
#else
return (__force __be32)((__force u64)x >> 32);
#endif
}
static __be16 filter_tnl_flags(__be16 flags)
{
return flags & (TUNNEL_CSUM | TUNNEL_KEY);
}
static struct sk_buff *__build_header(struct sk_buff *skb,
int tunnel_hlen)
{
struct tnl_ptk_info tpi;
const struct ovs_key_ipv4_tunnel *tun_key;
tun_key = &OVS_CB(skb)->egress_tun_info->tunnel;
skb = gre_handle_offloads(skb, !!(tun_key->tun_flags & TUNNEL_CSUM));
if (IS_ERR(skb))
return NULL;
tpi.flags = filter_tnl_flags(tun_key->tun_flags);
tpi.proto = htons(ETH_P_TEB);
tpi.key = be64_get_low32(tun_key->tun_id);
tpi.seq = 0;
gre_build_header(skb, &tpi, tunnel_hlen);
return skb;
}
static __be64 key_to_tunnel_id(__be32 key, __be32 seq)
{
#ifdef __BIG_ENDIAN
return (__force __be64)((__force u64)seq << 32 | (__force u32)key);
#else
return (__force __be64)((__force u64)key << 32 | (__force u32)seq);
#endif
}
static int gre_rcv(struct sk_buff *skb,
const struct tnl_ptk_info *tpi)
{
struct ovs_tunnel_info tun_info;
struct ovs_net *ovs_net;
struct vport *vport;
__be64 key;
ovs_net = net_generic(dev_net(skb->dev), ovs_net_id);
vport = rcu_dereference(ovs_net->vport_net.gre_vport);
if (unlikely(!vport))
return PACKET_REJECT;
key = key_to_tunnel_id(tpi->key, tpi->seq);
ovs_flow_tun_info_init(&tun_info, ip_hdr(skb), key,
filter_tnl_flags(tpi->flags), NULL, 0);
ovs_vport_receive(vport, skb, &tun_info);
return PACKET_RCVD;
}
static int gre_err(struct sk_buff *skb, u32 info,
const struct tnl_ptk_info *tpi)
{
struct ovs_net *ovs_net;
struct vport *vport;
ovs_net = net_generic(dev_net(skb->dev), ovs_net_id);
vport = rcu_dereference(ovs_net->vport_net.gre_vport);
if (unlikely(!vport))
return PACKET_REJECT;
else
return PACKET_RCVD;
}
static int gre_tnl_send(struct vport *vport, struct sk_buff *skb)
{
struct net *net = ovs_dp_get_net(vport->dp);
struct ovs_key_ipv4_tunnel *tun_key;
struct flowi4 fl;
struct rtable *rt;
int min_headroom;
int tunnel_hlen;
__be16 df;
int err;
if (unlikely(!OVS_CB(skb)->egress_tun_info)) {
err = -EINVAL;
goto error;
}
tun_key = &OVS_CB(skb)->egress_tun_info->tunnel;
memset(&fl, 0, sizeof(fl));
fl.daddr = tun_key->ipv4_dst;
fl.saddr = tun_key->ipv4_src;
fl.flowi4_tos = RT_TOS(tun_key->ipv4_tos);
fl.flowi4_mark = skb->mark;
fl.flowi4_proto = IPPROTO_GRE;
rt = ip_route_output_key(net, &fl);
if (IS_ERR(rt))
return PTR_ERR(rt);
tunnel_hlen = ip_gre_calc_hlen(tun_key->tun_flags);
min_headroom = LL_RESERVED_SPACE(rt->dst.dev) + rt->dst.header_len
+ tunnel_hlen + sizeof(struct iphdr)
+ (vlan_tx_tag_present(skb) ? VLAN_HLEN : 0);
if (skb_headroom(skb) < min_headroom || skb_header_cloned(skb)) {
int head_delta = SKB_DATA_ALIGN(min_headroom -
skb_headroom(skb) +
16);
err = pskb_expand_head(skb, max_t(int, head_delta, 0),
0, GFP_ATOMIC);
if (unlikely(err))
goto err_free_rt;
}
if (vlan_tx_tag_present(skb)) {
if (unlikely(!__vlan_put_tag(skb,
skb->vlan_proto,
vlan_tx_tag_get(skb)))) {
err = -ENOMEM;
goto err_free_rt;
}
skb->vlan_tci = 0;
}
skb = __build_header(skb, tunnel_hlen);
if (unlikely(!skb)) {
err = 0;
goto err_free_rt;
}
df = tun_key->tun_flags & TUNNEL_DONT_FRAGMENT ?
htons(IP_DF) : 0;
skb->ignore_df = 1;
return iptunnel_xmit(skb->sk, rt, skb, fl.saddr,
tun_key->ipv4_dst, IPPROTO_GRE,
tun_key->ipv4_tos, tun_key->ipv4_ttl, df, false);
err_free_rt:
ip_rt_put(rt);
error:
return err;
}
static int gre_init(void)
{
int err;
gre_ports++;
if (gre_ports > 1)
return 0;
err = gre_cisco_register(&gre_protocol);
if (err)
pr_warn("cannot register gre protocol handler\n");
return err;
}
static void gre_exit(void)
{
gre_ports--;
if (gre_ports > 0)
return;
gre_cisco_unregister(&gre_protocol);
}
static const char *gre_get_name(const struct vport *vport)
{
return vport_priv(vport);
}
static struct vport *gre_create(const struct vport_parms *parms)
{
struct net *net = ovs_dp_get_net(parms->dp);
struct ovs_net *ovs_net;
struct vport *vport;
int err;
err = gre_init();
if (err)
return ERR_PTR(err);
ovs_net = net_generic(net, ovs_net_id);
if (ovsl_dereference(ovs_net->vport_net.gre_vport)) {
vport = ERR_PTR(-EEXIST);
goto error;
}
vport = ovs_vport_alloc(IFNAMSIZ, &ovs_gre_vport_ops, parms);
if (IS_ERR(vport))
goto error;
strncpy(vport_priv(vport), parms->name, IFNAMSIZ);
rcu_assign_pointer(ovs_net->vport_net.gre_vport, vport);
return vport;
error:
gre_exit();
return vport;
}
static void gre_tnl_destroy(struct vport *vport)
{
struct net *net = ovs_dp_get_net(vport->dp);
struct ovs_net *ovs_net;
ovs_net = net_generic(net, ovs_net_id);
RCU_INIT_POINTER(ovs_net->vport_net.gre_vport, NULL);
ovs_vport_deferred_free(vport);
gre_exit();
}
