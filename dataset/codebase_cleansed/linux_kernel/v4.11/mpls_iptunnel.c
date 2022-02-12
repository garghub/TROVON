static unsigned int mpls_encap_size(struct mpls_iptunnel_encap *en)
{
return en->labels * sizeof(struct mpls_shim_hdr);
}
static int mpls_xmit(struct sk_buff *skb)
{
struct mpls_iptunnel_encap *tun_encap_info;
struct mpls_shim_hdr *hdr;
struct net_device *out_dev;
unsigned int hh_len;
unsigned int new_header_size;
unsigned int mtu;
struct dst_entry *dst = skb_dst(skb);
struct rtable *rt = NULL;
struct rt6_info *rt6 = NULL;
struct mpls_dev *out_mdev;
int err = 0;
bool bos;
int i;
unsigned int ttl;
out_dev = dst->dev;
if (dst->ops->family == AF_INET) {
ttl = ip_hdr(skb)->ttl;
rt = (struct rtable *)dst;
} else if (dst->ops->family == AF_INET6) {
ttl = ipv6_hdr(skb)->hop_limit;
rt6 = (struct rt6_info *)dst;
} else {
goto drop;
}
skb_orphan(skb);
if (!mpls_output_possible(out_dev) ||
!dst->lwtstate || skb_warn_if_lro(skb))
goto drop;
skb_forward_csum(skb);
tun_encap_info = mpls_lwtunnel_encap(dst->lwtstate);
new_header_size = mpls_encap_size(tun_encap_info);
mtu = mpls_dev_mtu(out_dev);
if (mpls_pkt_too_big(skb, mtu - new_header_size))
goto drop;
hh_len = LL_RESERVED_SPACE(out_dev);
if (!out_dev->header_ops)
hh_len = 0;
if (skb_cow(skb, hh_len + new_header_size))
goto drop;
skb_set_inner_protocol(skb, skb->protocol);
skb_reset_inner_network_header(skb);
skb_push(skb, new_header_size);
skb_reset_network_header(skb);
skb->dev = out_dev;
skb->protocol = htons(ETH_P_MPLS_UC);
hdr = mpls_hdr(skb);
bos = true;
for (i = tun_encap_info->labels - 1; i >= 0; i--) {
hdr[i] = mpls_entry_encode(tun_encap_info->label[i],
ttl, 0, bos);
bos = false;
}
mpls_stats_inc_outucastpkts(out_dev, skb);
if (rt)
err = neigh_xmit(NEIGH_ARP_TABLE, out_dev, &rt->rt_gateway,
skb);
else if (rt6)
err = neigh_xmit(NEIGH_ND_TABLE, out_dev, &rt6->rt6i_gateway,
skb);
if (err)
net_dbg_ratelimited("%s: packet transmission failed: %d\n",
__func__, err);
return LWTUNNEL_XMIT_DONE;
drop:
out_mdev = out_dev ? mpls_dev_get(out_dev) : NULL;
if (out_mdev)
MPLS_INC_STATS(out_mdev, tx_errors);
kfree_skb(skb);
return -EINVAL;
}
static int mpls_build_state(struct nlattr *nla,
unsigned int family, const void *cfg,
struct lwtunnel_state **ts)
{
struct mpls_iptunnel_encap *tun_encap_info;
struct nlattr *tb[MPLS_IPTUNNEL_MAX + 1];
struct lwtunnel_state *newts;
int ret;
ret = nla_parse_nested(tb, MPLS_IPTUNNEL_MAX, nla,
mpls_iptunnel_policy);
if (ret < 0)
return ret;
if (!tb[MPLS_IPTUNNEL_DST])
return -EINVAL;
newts = lwtunnel_state_alloc(sizeof(*tun_encap_info));
if (!newts)
return -ENOMEM;
tun_encap_info = mpls_lwtunnel_encap(newts);
ret = nla_get_labels(tb[MPLS_IPTUNNEL_DST], MAX_NEW_LABELS,
&tun_encap_info->labels, tun_encap_info->label);
if (ret)
goto errout;
newts->type = LWTUNNEL_ENCAP_MPLS;
newts->flags |= LWTUNNEL_STATE_XMIT_REDIRECT;
newts->headroom = mpls_encap_size(tun_encap_info);
*ts = newts;
return 0;
errout:
kfree(newts);
*ts = NULL;
return ret;
}
static int mpls_fill_encap_info(struct sk_buff *skb,
struct lwtunnel_state *lwtstate)
{
struct mpls_iptunnel_encap *tun_encap_info;
tun_encap_info = mpls_lwtunnel_encap(lwtstate);
if (nla_put_labels(skb, MPLS_IPTUNNEL_DST, tun_encap_info->labels,
tun_encap_info->label))
goto nla_put_failure;
return 0;
nla_put_failure:
return -EMSGSIZE;
}
static int mpls_encap_nlsize(struct lwtunnel_state *lwtstate)
{
struct mpls_iptunnel_encap *tun_encap_info;
tun_encap_info = mpls_lwtunnel_encap(lwtstate);
return nla_total_size(tun_encap_info->labels * 4);
}
static int mpls_encap_cmp(struct lwtunnel_state *a, struct lwtunnel_state *b)
{
struct mpls_iptunnel_encap *a_hdr = mpls_lwtunnel_encap(a);
struct mpls_iptunnel_encap *b_hdr = mpls_lwtunnel_encap(b);
int l;
if (a_hdr->labels != b_hdr->labels)
return 1;
for (l = 0; l < MAX_NEW_LABELS; l++)
if (a_hdr->label[l] != b_hdr->label[l])
return 1;
return 0;
}
static int __init mpls_iptunnel_init(void)
{
return lwtunnel_encap_add_ops(&mpls_iptun_ops, LWTUNNEL_ENCAP_MPLS);
}
static void __exit mpls_iptunnel_exit(void)
{
lwtunnel_encap_del_ops(&mpls_iptun_ops, LWTUNNEL_ENCAP_MPLS);
}
