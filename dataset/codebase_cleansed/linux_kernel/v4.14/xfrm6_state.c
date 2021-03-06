static void
__xfrm6_init_tempsel(struct xfrm_selector *sel, const struct flowi *fl)
{
const struct flowi6 *fl6 = &fl->u.ip6;
*(struct in6_addr *)&sel->daddr = fl6->daddr;
*(struct in6_addr *)&sel->saddr = fl6->saddr;
sel->dport = xfrm_flowi_dport(fl, &fl6->uli);
sel->dport_mask = htons(0xffff);
sel->sport = xfrm_flowi_sport(fl, &fl6->uli);
sel->sport_mask = htons(0xffff);
sel->family = AF_INET6;
sel->prefixlen_d = 128;
sel->prefixlen_s = 128;
sel->proto = fl6->flowi6_proto;
sel->ifindex = fl6->flowi6_oif;
}
static void
xfrm6_init_temprop(struct xfrm_state *x, const struct xfrm_tmpl *tmpl,
const xfrm_address_t *daddr, const xfrm_address_t *saddr)
{
x->id = tmpl->id;
if (ipv6_addr_any((struct in6_addr *)&x->id.daddr))
memcpy(&x->id.daddr, daddr, sizeof(x->sel.daddr));
memcpy(&x->props.saddr, &tmpl->saddr, sizeof(x->props.saddr));
if (ipv6_addr_any((struct in6_addr *)&x->props.saddr))
memcpy(&x->props.saddr, saddr, sizeof(x->props.saddr));
x->props.mode = tmpl->mode;
x->props.reqid = tmpl->reqid;
x->props.family = AF_INET6;
}
static int
__xfrm6_sort(void **dst, void **src, int n, int (*cmp)(void *p), int maxclass)
{
int i;
int class[XFRM_MAX_DEPTH];
int count[maxclass];
memset(count, 0, sizeof(count));
for (i = 0; i < n; i++) {
int c;
class[i] = c = cmp(src[i]);
count[c]++;
}
for (i = 2; i < maxclass; i++)
count[i] += count[i - 1];
for (i = 0; i < n; i++) {
dst[count[class[i] - 1]++] = src[i];
src[i] = NULL;
}
return 0;
}
static int __xfrm6_state_sort_cmp(void *p)
{
struct xfrm_state *v = p;
switch (v->props.mode) {
case XFRM_MODE_TRANSPORT:
if (v->id.proto != IPPROTO_AH)
return 1;
else
return 3;
#if IS_ENABLED(CONFIG_IPV6_MIP6)
case XFRM_MODE_ROUTEOPTIMIZATION:
case XFRM_MODE_IN_TRIGGER:
return 2;
#endif
case XFRM_MODE_TUNNEL:
case XFRM_MODE_BEET:
return 4;
}
return 5;
}
static int
__xfrm6_state_sort(struct xfrm_state **dst, struct xfrm_state **src, int n)
{
return __xfrm6_sort((void **)dst, (void **)src, n,
__xfrm6_state_sort_cmp, 6);
}
static int __xfrm6_tmpl_sort_cmp(void *p)
{
struct xfrm_tmpl *v = p;
switch (v->mode) {
case XFRM_MODE_TRANSPORT:
return 1;
#if IS_ENABLED(CONFIG_IPV6_MIP6)
case XFRM_MODE_ROUTEOPTIMIZATION:
case XFRM_MODE_IN_TRIGGER:
return 2;
#endif
case XFRM_MODE_TUNNEL:
case XFRM_MODE_BEET:
return 3;
}
return 4;
}
static int
__xfrm6_tmpl_sort(struct xfrm_tmpl **dst, struct xfrm_tmpl **src, int n)
{
return __xfrm6_sort((void **)dst, (void **)src, n,
__xfrm6_tmpl_sort_cmp, 5);
}
int xfrm6_extract_header(struct sk_buff *skb)
{
struct ipv6hdr *iph = ipv6_hdr(skb);
XFRM_MODE_SKB_CB(skb)->ihl = sizeof(*iph);
XFRM_MODE_SKB_CB(skb)->id = 0;
XFRM_MODE_SKB_CB(skb)->frag_off = htons(IP_DF);
XFRM_MODE_SKB_CB(skb)->tos = ipv6_get_dsfield(iph);
XFRM_MODE_SKB_CB(skb)->ttl = iph->hop_limit;
XFRM_MODE_SKB_CB(skb)->optlen = 0;
memcpy(XFRM_MODE_SKB_CB(skb)->flow_lbl, iph->flow_lbl,
sizeof(XFRM_MODE_SKB_CB(skb)->flow_lbl));
return 0;
}
int __init xfrm6_state_init(void)
{
return xfrm_state_register_afinfo(&xfrm6_state_afinfo);
}
void xfrm6_state_fini(void)
{
xfrm_state_unregister_afinfo(&xfrm6_state_afinfo);
}
