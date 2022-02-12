int gre_add_protocol(const struct gre_protocol *proto, u8 version)
{
if (version >= GREPROTO_MAX)
return -EINVAL;
return (cmpxchg((const struct gre_protocol **)&gre_proto[version], NULL, proto) == NULL) ?
0 : -EBUSY;
}
int gre_del_protocol(const struct gre_protocol *proto, u8 version)
{
int ret;
if (version >= GREPROTO_MAX)
return -EINVAL;
ret = (cmpxchg((const struct gre_protocol **)&gre_proto[version], proto, NULL) == proto) ?
0 : -EBUSY;
if (ret)
return ret;
synchronize_rcu();
return 0;
}
void gre_build_header(struct sk_buff *skb, const struct tnl_ptk_info *tpi,
int hdr_len)
{
struct gre_base_hdr *greh;
skb_push(skb, hdr_len);
skb_reset_transport_header(skb);
greh = (struct gre_base_hdr *)skb->data;
greh->flags = tnl_flags_to_gre_flags(tpi->flags);
greh->protocol = tpi->proto;
if (tpi->flags&(TUNNEL_KEY|TUNNEL_CSUM|TUNNEL_SEQ)) {
__be32 *ptr = (__be32 *)(((u8 *)greh) + hdr_len - 4);
if (tpi->flags&TUNNEL_SEQ) {
*ptr = tpi->seq;
ptr--;
}
if (tpi->flags&TUNNEL_KEY) {
*ptr = tpi->key;
ptr--;
}
if (tpi->flags&TUNNEL_CSUM &&
!(skb_shinfo(skb)->gso_type &
(SKB_GSO_GRE|SKB_GSO_GRE_CSUM))) {
*ptr = 0;
*(__sum16 *)ptr = csum_fold(skb_checksum(skb, 0,
skb->len, 0));
}
}
}
static int parse_gre_header(struct sk_buff *skb, struct tnl_ptk_info *tpi,
bool *csum_err)
{
const struct gre_base_hdr *greh;
__be32 *options;
int hdr_len;
if (unlikely(!pskb_may_pull(skb, sizeof(struct gre_base_hdr))))
return -EINVAL;
greh = (struct gre_base_hdr *)skb_transport_header(skb);
if (unlikely(greh->flags & (GRE_VERSION | GRE_ROUTING)))
return -EINVAL;
tpi->flags = gre_flags_to_tnl_flags(greh->flags);
hdr_len = ip_gre_calc_hlen(tpi->flags);
if (!pskb_may_pull(skb, hdr_len))
return -EINVAL;
greh = (struct gre_base_hdr *)skb_transport_header(skb);
tpi->proto = greh->protocol;
options = (__be32 *)(greh + 1);
if (greh->flags & GRE_CSUM) {
if (skb_checksum_simple_validate(skb)) {
*csum_err = true;
return -EINVAL;
}
skb_checksum_try_convert(skb, IPPROTO_GRE, 0,
null_compute_pseudo);
options++;
}
if (greh->flags & GRE_KEY) {
tpi->key = *options;
options++;
} else
tpi->key = 0;
if (unlikely(greh->flags & GRE_SEQ)) {
tpi->seq = *options;
options++;
} else
tpi->seq = 0;
if (greh->flags == 0 && tpi->proto == htons(ETH_P_WCCP)) {
tpi->proto = htons(ETH_P_IP);
if ((*(u8 *)options & 0xF0) != 0x40) {
hdr_len += 4;
if (!pskb_may_pull(skb, hdr_len))
return -EINVAL;
}
}
return iptunnel_pull_header(skb, hdr_len, tpi->proto);
}
static int gre_cisco_rcv(struct sk_buff *skb)
{
struct tnl_ptk_info tpi;
int i;
bool csum_err = false;
#ifdef CONFIG_NET_IPGRE_BROADCAST
if (ipv4_is_multicast(ip_hdr(skb)->daddr)) {
if (rt_is_output_route(skb_rtable(skb)))
goto drop;
}
#endif
if (parse_gre_header(skb, &tpi, &csum_err) < 0)
goto drop;
rcu_read_lock();
for (i = 0; i < GRE_IP_PROTO_MAX; i++) {
struct gre_cisco_protocol *proto;
int ret;
proto = rcu_dereference(gre_cisco_proto_list[i]);
if (!proto)
continue;
ret = proto->handler(skb, &tpi);
if (ret == PACKET_RCVD) {
rcu_read_unlock();
return 0;
}
}
rcu_read_unlock();
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_PORT_UNREACH, 0);
drop:
kfree_skb(skb);
return 0;
}
static void gre_cisco_err(struct sk_buff *skb, u32 info)
{
const int type = icmp_hdr(skb)->type;
const int code = icmp_hdr(skb)->code;
struct tnl_ptk_info tpi;
bool csum_err = false;
int i;
if (parse_gre_header(skb, &tpi, &csum_err)) {
if (!csum_err)
return;
}
if (type == ICMP_DEST_UNREACH && code == ICMP_FRAG_NEEDED) {
ipv4_update_pmtu(skb, dev_net(skb->dev), info,
skb->dev->ifindex, 0, IPPROTO_GRE, 0);
return;
}
if (type == ICMP_REDIRECT) {
ipv4_redirect(skb, dev_net(skb->dev), skb->dev->ifindex, 0,
IPPROTO_GRE, 0);
return;
}
rcu_read_lock();
for (i = 0; i < GRE_IP_PROTO_MAX; i++) {
struct gre_cisco_protocol *proto;
proto = rcu_dereference(gre_cisco_proto_list[i]);
if (!proto)
continue;
if (proto->err_handler(skb, info, &tpi) == PACKET_RCVD)
goto out;
}
out:
rcu_read_unlock();
}
static int gre_rcv(struct sk_buff *skb)
{
const struct gre_protocol *proto;
u8 ver;
int ret;
if (!pskb_may_pull(skb, 12))
goto drop;
ver = skb->data[1]&0x7f;
if (ver >= GREPROTO_MAX)
goto drop;
rcu_read_lock();
proto = rcu_dereference(gre_proto[ver]);
if (!proto || !proto->handler)
goto drop_unlock;
ret = proto->handler(skb);
rcu_read_unlock();
return ret;
drop_unlock:
rcu_read_unlock();
drop:
kfree_skb(skb);
return NET_RX_DROP;
}
static void gre_err(struct sk_buff *skb, u32 info)
{
const struct gre_protocol *proto;
const struct iphdr *iph = (const struct iphdr *)skb->data;
u8 ver = skb->data[(iph->ihl<<2) + 1]&0x7f;
if (ver >= GREPROTO_MAX)
return;
rcu_read_lock();
proto = rcu_dereference(gre_proto[ver]);
if (proto && proto->err_handler)
proto->err_handler(skb, info);
rcu_read_unlock();
}
int gre_cisco_register(struct gre_cisco_protocol *newp)
{
struct gre_cisco_protocol **proto = (struct gre_cisco_protocol **)
&gre_cisco_proto_list[newp->priority];
return (cmpxchg(proto, NULL, newp) == NULL) ? 0 : -EBUSY;
}
int gre_cisco_unregister(struct gre_cisco_protocol *del_proto)
{
struct gre_cisco_protocol **proto = (struct gre_cisco_protocol **)
&gre_cisco_proto_list[del_proto->priority];
int ret;
ret = (cmpxchg(proto, del_proto, NULL) == del_proto) ? 0 : -EINVAL;
if (ret)
return ret;
synchronize_net();
return 0;
}
static int __init gre_init(void)
{
pr_info("GRE over IPv4 demultiplexor driver\n");
if (inet_add_protocol(&net_gre_protocol, IPPROTO_GRE) < 0) {
pr_err("can't add protocol\n");
goto err;
}
if (gre_add_protocol(&ipgre_protocol, GREPROTO_CISCO) < 0) {
pr_info("%s: can't add ipgre handler\n", __func__);
goto err_gre;
}
return 0;
err_gre:
inet_del_protocol(&net_gre_protocol, IPPROTO_GRE);
err:
return -EAGAIN;
}
static void __exit gre_exit(void)
{
gre_del_protocol(&ipgre_protocol, GREPROTO_CISCO);
inet_del_protocol(&net_gre_protocol, IPPROTO_GRE);
}
