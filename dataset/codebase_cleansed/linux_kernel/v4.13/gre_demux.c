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
int gre_parse_header(struct sk_buff *skb, struct tnl_ptk_info *tpi,
bool *csum_err, __be16 proto, int nhs)
{
const struct gre_base_hdr *greh;
__be32 *options;
int hdr_len;
if (unlikely(!pskb_may_pull(skb, nhs + sizeof(struct gre_base_hdr))))
return -EINVAL;
greh = (struct gre_base_hdr *)(skb->data + nhs);
if (unlikely(greh->flags & (GRE_VERSION | GRE_ROUTING)))
return -EINVAL;
tpi->flags = gre_flags_to_tnl_flags(greh->flags);
hdr_len = gre_calc_hlen(tpi->flags);
if (!pskb_may_pull(skb, nhs + hdr_len))
return -EINVAL;
greh = (struct gre_base_hdr *)(skb->data + nhs);
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
} else {
tpi->key = 0;
}
if (unlikely(greh->flags & GRE_SEQ)) {
tpi->seq = *options;
options++;
} else {
tpi->seq = 0;
}
if (greh->flags == 0 && tpi->proto == htons(ETH_P_WCCP)) {
tpi->proto = proto;
if ((*(u8 *)options & 0xF0) != 0x40)
hdr_len += 4;
}
tpi->hdr_len = hdr_len;
return hdr_len;
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
static int __init gre_init(void)
{
pr_info("GRE over IPv4 demultiplexor driver\n");
if (inet_add_protocol(&net_gre_protocol, IPPROTO_GRE) < 0) {
pr_err("can't add protocol\n");
return -EAGAIN;
}
return 0;
}
static void __exit gre_exit(void)
{
inet_del_protocol(&net_gre_protocol, IPPROTO_GRE);
}
