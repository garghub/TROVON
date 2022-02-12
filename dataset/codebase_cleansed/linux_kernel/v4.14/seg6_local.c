static struct seg6_local_lwt *seg6_local_lwtunnel(struct lwtunnel_state *lwt)
{
return (struct seg6_local_lwt *)lwt->data;
}
static struct ipv6_sr_hdr *get_srh(struct sk_buff *skb)
{
struct ipv6_sr_hdr *srh;
int len, srhoff = 0;
if (ipv6_find_hdr(skb, &srhoff, IPPROTO_ROUTING, NULL, NULL) < 0)
return NULL;
if (!pskb_may_pull(skb, srhoff + sizeof(*srh)))
return NULL;
srh = (struct ipv6_sr_hdr *)(skb->data + srhoff);
len = (srh->hdrlen + 1) << 3;
if (!pskb_may_pull(skb, srhoff + len))
return NULL;
if (!seg6_validate_srh(srh, len))
return NULL;
return srh;
}
static struct ipv6_sr_hdr *get_and_validate_srh(struct sk_buff *skb)
{
struct ipv6_sr_hdr *srh;
srh = get_srh(skb);
if (!srh)
return NULL;
if (srh->segments_left == 0)
return NULL;
#ifdef CONFIG_IPV6_SEG6_HMAC
if (!seg6_hmac_validate_skb(skb))
return NULL;
#endif
return srh;
}
static bool decap_and_validate(struct sk_buff *skb, int proto)
{
struct ipv6_sr_hdr *srh;
unsigned int off = 0;
srh = get_srh(skb);
if (srh && srh->segments_left > 0)
return false;
#ifdef CONFIG_IPV6_SEG6_HMAC
if (srh && !seg6_hmac_validate_skb(skb))
return false;
#endif
if (ipv6_find_hdr(skb, &off, proto, NULL, NULL) < 0)
return false;
if (!pskb_pull(skb, off))
return false;
skb_postpull_rcsum(skb, skb_network_header(skb), off);
skb_reset_network_header(skb);
skb_reset_transport_header(skb);
skb->encapsulation = 0;
return true;
}
static void advance_nextseg(struct ipv6_sr_hdr *srh, struct in6_addr *daddr)
{
struct in6_addr *addr;
srh->segments_left--;
addr = srh->segments + srh->segments_left;
*daddr = *addr;
}
static void lookup_nexthop(struct sk_buff *skb, struct in6_addr *nhaddr,
u32 tbl_id)
{
struct net *net = dev_net(skb->dev);
struct ipv6hdr *hdr = ipv6_hdr(skb);
int flags = RT6_LOOKUP_F_HAS_SADDR;
struct dst_entry *dst = NULL;
struct rt6_info *rt;
struct flowi6 fl6;
fl6.flowi6_iif = skb->dev->ifindex;
fl6.daddr = nhaddr ? *nhaddr : hdr->daddr;
fl6.saddr = hdr->saddr;
fl6.flowlabel = ip6_flowinfo(hdr);
fl6.flowi6_mark = skb->mark;
fl6.flowi6_proto = hdr->nexthdr;
if (nhaddr)
fl6.flowi6_flags = FLOWI_FLAG_KNOWN_NH;
if (!tbl_id) {
dst = ip6_route_input_lookup(net, skb->dev, &fl6, flags);
} else {
struct fib6_table *table;
table = fib6_get_table(net, tbl_id);
if (!table)
goto out;
rt = ip6_pol_route(net, table, 0, &fl6, flags);
dst = &rt->dst;
}
if (dst && dst->dev->flags & IFF_LOOPBACK && !dst->error) {
dst_release(dst);
dst = NULL;
}
out:
if (!dst) {
rt = net->ipv6.ip6_blk_hole_entry;
dst = &rt->dst;
dst_hold(dst);
}
skb_dst_drop(skb);
skb_dst_set(skb, dst);
}
static int input_action_end(struct sk_buff *skb, struct seg6_local_lwt *slwt)
{
struct ipv6_sr_hdr *srh;
srh = get_and_validate_srh(skb);
if (!srh)
goto drop;
advance_nextseg(srh, &ipv6_hdr(skb)->daddr);
lookup_nexthop(skb, NULL, 0);
return dst_input(skb);
drop:
kfree_skb(skb);
return -EINVAL;
}
static int input_action_end_x(struct sk_buff *skb, struct seg6_local_lwt *slwt)
{
struct ipv6_sr_hdr *srh;
srh = get_and_validate_srh(skb);
if (!srh)
goto drop;
advance_nextseg(srh, &ipv6_hdr(skb)->daddr);
lookup_nexthop(skb, &slwt->nh6, 0);
return dst_input(skb);
drop:
kfree_skb(skb);
return -EINVAL;
}
static int input_action_end_t(struct sk_buff *skb, struct seg6_local_lwt *slwt)
{
struct ipv6_sr_hdr *srh;
srh = get_and_validate_srh(skb);
if (!srh)
goto drop;
advance_nextseg(srh, &ipv6_hdr(skb)->daddr);
lookup_nexthop(skb, NULL, slwt->table);
return dst_input(skb);
drop:
kfree_skb(skb);
return -EINVAL;
}
static int input_action_end_dx2(struct sk_buff *skb,
struct seg6_local_lwt *slwt)
{
struct net *net = dev_net(skb->dev);
struct net_device *odev;
struct ethhdr *eth;
if (!decap_and_validate(skb, NEXTHDR_NONE))
goto drop;
if (!pskb_may_pull(skb, ETH_HLEN))
goto drop;
skb_reset_mac_header(skb);
eth = (struct ethhdr *)skb->data;
if (!eth_proto_is_802_3(eth->h_proto))
goto drop;
odev = dev_get_by_index_rcu(net, slwt->oif);
if (!odev)
goto drop;
if (odev->type != ARPHRD_ETHER)
goto drop;
if (!(odev->flags & IFF_UP) || !netif_carrier_ok(odev))
goto drop;
skb_orphan(skb);
if (skb_warn_if_lro(skb))
goto drop;
skb_forward_csum(skb);
if (skb->len - ETH_HLEN > odev->mtu)
goto drop;
skb->dev = odev;
skb->protocol = eth->h_proto;
return dev_queue_xmit(skb);
drop:
kfree_skb(skb);
return -EINVAL;
}
static int input_action_end_dx6(struct sk_buff *skb,
struct seg6_local_lwt *slwt)
{
struct in6_addr *nhaddr = NULL;
if (!decap_and_validate(skb, IPPROTO_IPV6))
goto drop;
if (!pskb_may_pull(skb, sizeof(struct ipv6hdr)))
goto drop;
if (!ipv6_addr_any(&slwt->nh6))
nhaddr = &slwt->nh6;
lookup_nexthop(skb, nhaddr, 0);
return dst_input(skb);
drop:
kfree_skb(skb);
return -EINVAL;
}
static int input_action_end_dx4(struct sk_buff *skb,
struct seg6_local_lwt *slwt)
{
struct iphdr *iph;
__be32 nhaddr;
int err;
if (!decap_and_validate(skb, IPPROTO_IPIP))
goto drop;
if (!pskb_may_pull(skb, sizeof(struct iphdr)))
goto drop;
skb->protocol = htons(ETH_P_IP);
iph = ip_hdr(skb);
nhaddr = slwt->nh4.s_addr ?: iph->daddr;
skb_dst_drop(skb);
err = ip_route_input(skb, nhaddr, iph->saddr, 0, skb->dev);
if (err)
goto drop;
return dst_input(skb);
drop:
kfree_skb(skb);
return -EINVAL;
}
static int input_action_end_dt6(struct sk_buff *skb,
struct seg6_local_lwt *slwt)
{
if (!decap_and_validate(skb, IPPROTO_IPV6))
goto drop;
if (!pskb_may_pull(skb, sizeof(struct ipv6hdr)))
goto drop;
lookup_nexthop(skb, NULL, slwt->table);
return dst_input(skb);
drop:
kfree_skb(skb);
return -EINVAL;
}
static int input_action_end_b6(struct sk_buff *skb, struct seg6_local_lwt *slwt)
{
struct ipv6_sr_hdr *srh;
int err = -EINVAL;
srh = get_and_validate_srh(skb);
if (!srh)
goto drop;
err = seg6_do_srh_inline(skb, slwt->srh);
if (err)
goto drop;
ipv6_hdr(skb)->payload_len = htons(skb->len - sizeof(struct ipv6hdr));
skb_set_transport_header(skb, sizeof(struct ipv6hdr));
lookup_nexthop(skb, NULL, 0);
return dst_input(skb);
drop:
kfree_skb(skb);
return err;
}
static int input_action_end_b6_encap(struct sk_buff *skb,
struct seg6_local_lwt *slwt)
{
struct ipv6_sr_hdr *srh;
int err = -EINVAL;
srh = get_and_validate_srh(skb);
if (!srh)
goto drop;
advance_nextseg(srh, &ipv6_hdr(skb)->daddr);
skb_reset_inner_headers(skb);
skb->encapsulation = 1;
err = seg6_do_srh_encap(skb, slwt->srh, IPPROTO_IPV6);
if (err)
goto drop;
ipv6_hdr(skb)->payload_len = htons(skb->len - sizeof(struct ipv6hdr));
skb_set_transport_header(skb, sizeof(struct ipv6hdr));
lookup_nexthop(skb, NULL, 0);
return dst_input(skb);
drop:
kfree_skb(skb);
return err;
}
static struct seg6_action_desc *__get_action_desc(int action)
{
struct seg6_action_desc *desc;
int i, count;
count = sizeof(seg6_action_table) / sizeof(struct seg6_action_desc);
for (i = 0; i < count; i++) {
desc = &seg6_action_table[i];
if (desc->action == action)
return desc;
}
return NULL;
}
static int seg6_local_input(struct sk_buff *skb)
{
struct dst_entry *orig_dst = skb_dst(skb);
struct seg6_action_desc *desc;
struct seg6_local_lwt *slwt;
if (skb->protocol != htons(ETH_P_IPV6)) {
kfree_skb(skb);
return -EINVAL;
}
slwt = seg6_local_lwtunnel(orig_dst->lwtstate);
desc = slwt->desc;
return desc->input(skb, slwt);
}
static int parse_nla_srh(struct nlattr **attrs, struct seg6_local_lwt *slwt)
{
struct ipv6_sr_hdr *srh;
int len;
srh = nla_data(attrs[SEG6_LOCAL_SRH]);
len = nla_len(attrs[SEG6_LOCAL_SRH]);
if (len < sizeof(*srh) + sizeof(struct in6_addr))
return -EINVAL;
if (!seg6_validate_srh(srh, len))
return -EINVAL;
slwt->srh = kmalloc(len, GFP_KERNEL);
if (!slwt->srh)
return -ENOMEM;
memcpy(slwt->srh, srh, len);
slwt->headroom += len;
return 0;
}
static int put_nla_srh(struct sk_buff *skb, struct seg6_local_lwt *slwt)
{
struct ipv6_sr_hdr *srh;
struct nlattr *nla;
int len;
srh = slwt->srh;
len = (srh->hdrlen + 1) << 3;
nla = nla_reserve(skb, SEG6_LOCAL_SRH, len);
if (!nla)
return -EMSGSIZE;
memcpy(nla_data(nla), srh, len);
return 0;
}
static int cmp_nla_srh(struct seg6_local_lwt *a, struct seg6_local_lwt *b)
{
int len = (a->srh->hdrlen + 1) << 3;
if (len != ((b->srh->hdrlen + 1) << 3))
return 1;
return memcmp(a->srh, b->srh, len);
}
static int parse_nla_table(struct nlattr **attrs, struct seg6_local_lwt *slwt)
{
slwt->table = nla_get_u32(attrs[SEG6_LOCAL_TABLE]);
return 0;
}
static int put_nla_table(struct sk_buff *skb, struct seg6_local_lwt *slwt)
{
if (nla_put_u32(skb, SEG6_LOCAL_TABLE, slwt->table))
return -EMSGSIZE;
return 0;
}
static int cmp_nla_table(struct seg6_local_lwt *a, struct seg6_local_lwt *b)
{
if (a->table != b->table)
return 1;
return 0;
}
static int parse_nla_nh4(struct nlattr **attrs, struct seg6_local_lwt *slwt)
{
memcpy(&slwt->nh4, nla_data(attrs[SEG6_LOCAL_NH4]),
sizeof(struct in_addr));
return 0;
}
static int put_nla_nh4(struct sk_buff *skb, struct seg6_local_lwt *slwt)
{
struct nlattr *nla;
nla = nla_reserve(skb, SEG6_LOCAL_NH4, sizeof(struct in_addr));
if (!nla)
return -EMSGSIZE;
memcpy(nla_data(nla), &slwt->nh4, sizeof(struct in_addr));
return 0;
}
static int cmp_nla_nh4(struct seg6_local_lwt *a, struct seg6_local_lwt *b)
{
return memcmp(&a->nh4, &b->nh4, sizeof(struct in_addr));
}
static int parse_nla_nh6(struct nlattr **attrs, struct seg6_local_lwt *slwt)
{
memcpy(&slwt->nh6, nla_data(attrs[SEG6_LOCAL_NH6]),
sizeof(struct in6_addr));
return 0;
}
static int put_nla_nh6(struct sk_buff *skb, struct seg6_local_lwt *slwt)
{
struct nlattr *nla;
nla = nla_reserve(skb, SEG6_LOCAL_NH6, sizeof(struct in6_addr));
if (!nla)
return -EMSGSIZE;
memcpy(nla_data(nla), &slwt->nh6, sizeof(struct in6_addr));
return 0;
}
static int cmp_nla_nh6(struct seg6_local_lwt *a, struct seg6_local_lwt *b)
{
return memcmp(&a->nh6, &b->nh6, sizeof(struct in6_addr));
}
static int parse_nla_iif(struct nlattr **attrs, struct seg6_local_lwt *slwt)
{
slwt->iif = nla_get_u32(attrs[SEG6_LOCAL_IIF]);
return 0;
}
static int put_nla_iif(struct sk_buff *skb, struct seg6_local_lwt *slwt)
{
if (nla_put_u32(skb, SEG6_LOCAL_IIF, slwt->iif))
return -EMSGSIZE;
return 0;
}
static int cmp_nla_iif(struct seg6_local_lwt *a, struct seg6_local_lwt *b)
{
if (a->iif != b->iif)
return 1;
return 0;
}
static int parse_nla_oif(struct nlattr **attrs, struct seg6_local_lwt *slwt)
{
slwt->oif = nla_get_u32(attrs[SEG6_LOCAL_OIF]);
return 0;
}
static int put_nla_oif(struct sk_buff *skb, struct seg6_local_lwt *slwt)
{
if (nla_put_u32(skb, SEG6_LOCAL_OIF, slwt->oif))
return -EMSGSIZE;
return 0;
}
static int cmp_nla_oif(struct seg6_local_lwt *a, struct seg6_local_lwt *b)
{
if (a->oif != b->oif)
return 1;
return 0;
}
static int parse_nla_action(struct nlattr **attrs, struct seg6_local_lwt *slwt)
{
struct seg6_action_param *param;
struct seg6_action_desc *desc;
int i, err;
desc = __get_action_desc(slwt->action);
if (!desc)
return -EINVAL;
if (!desc->input)
return -EOPNOTSUPP;
slwt->desc = desc;
slwt->headroom += desc->static_headroom;
for (i = 0; i < SEG6_LOCAL_MAX + 1; i++) {
if (desc->attrs & (1 << i)) {
if (!attrs[i])
return -EINVAL;
param = &seg6_action_params[i];
err = param->parse(attrs, slwt);
if (err < 0)
return err;
}
}
return 0;
}
static int seg6_local_build_state(struct nlattr *nla, unsigned int family,
const void *cfg, struct lwtunnel_state **ts,
struct netlink_ext_ack *extack)
{
struct nlattr *tb[SEG6_LOCAL_MAX + 1];
struct lwtunnel_state *newts;
struct seg6_local_lwt *slwt;
int err;
if (family != AF_INET6)
return -EINVAL;
err = nla_parse_nested(tb, SEG6_LOCAL_MAX, nla, seg6_local_policy,
extack);
if (err < 0)
return err;
if (!tb[SEG6_LOCAL_ACTION])
return -EINVAL;
newts = lwtunnel_state_alloc(sizeof(*slwt));
if (!newts)
return -ENOMEM;
slwt = seg6_local_lwtunnel(newts);
slwt->action = nla_get_u32(tb[SEG6_LOCAL_ACTION]);
err = parse_nla_action(tb, slwt);
if (err < 0)
goto out_free;
newts->type = LWTUNNEL_ENCAP_SEG6_LOCAL;
newts->flags = LWTUNNEL_STATE_INPUT_REDIRECT;
newts->headroom = slwt->headroom;
*ts = newts;
return 0;
out_free:
kfree(slwt->srh);
kfree(newts);
return err;
}
static void seg6_local_destroy_state(struct lwtunnel_state *lwt)
{
struct seg6_local_lwt *slwt = seg6_local_lwtunnel(lwt);
kfree(slwt->srh);
}
static int seg6_local_fill_encap(struct sk_buff *skb,
struct lwtunnel_state *lwt)
{
struct seg6_local_lwt *slwt = seg6_local_lwtunnel(lwt);
struct seg6_action_param *param;
int i, err;
if (nla_put_u32(skb, SEG6_LOCAL_ACTION, slwt->action))
return -EMSGSIZE;
for (i = 0; i < SEG6_LOCAL_MAX + 1; i++) {
if (slwt->desc->attrs & (1 << i)) {
param = &seg6_action_params[i];
err = param->put(skb, slwt);
if (err < 0)
return err;
}
}
return 0;
}
static int seg6_local_get_encap_size(struct lwtunnel_state *lwt)
{
struct seg6_local_lwt *slwt = seg6_local_lwtunnel(lwt);
unsigned long attrs;
int nlsize;
nlsize = nla_total_size(4);
attrs = slwt->desc->attrs;
if (attrs & (1 << SEG6_LOCAL_SRH))
nlsize += nla_total_size((slwt->srh->hdrlen + 1) << 3);
if (attrs & (1 << SEG6_LOCAL_TABLE))
nlsize += nla_total_size(4);
if (attrs & (1 << SEG6_LOCAL_NH4))
nlsize += nla_total_size(4);
if (attrs & (1 << SEG6_LOCAL_NH6))
nlsize += nla_total_size(16);
if (attrs & (1 << SEG6_LOCAL_IIF))
nlsize += nla_total_size(4);
if (attrs & (1 << SEG6_LOCAL_OIF))
nlsize += nla_total_size(4);
return nlsize;
}
static int seg6_local_cmp_encap(struct lwtunnel_state *a,
struct lwtunnel_state *b)
{
struct seg6_local_lwt *slwt_a, *slwt_b;
struct seg6_action_param *param;
int i;
slwt_a = seg6_local_lwtunnel(a);
slwt_b = seg6_local_lwtunnel(b);
if (slwt_a->action != slwt_b->action)
return 1;
if (slwt_a->desc->attrs != slwt_b->desc->attrs)
return 1;
for (i = 0; i < SEG6_LOCAL_MAX + 1; i++) {
if (slwt_a->desc->attrs & (1 << i)) {
param = &seg6_action_params[i];
if (param->cmp(slwt_a, slwt_b))
return 1;
}
}
return 0;
}
int __init seg6_local_init(void)
{
return lwtunnel_encap_add_ops(&seg6_local_ops,
LWTUNNEL_ENCAP_SEG6_LOCAL);
}
void seg6_local_exit(void)
{
lwtunnel_encap_del_ops(&seg6_local_ops, LWTUNNEL_ENCAP_SEG6_LOCAL);
}
