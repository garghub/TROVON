static inline bool
xt_addr_cmp(const union nf_inet_addr *a1, const union nf_inet_addr *m,
const union nf_inet_addr *a2, unsigned short family)
{
switch (family) {
case NFPROTO_IPV4:
return ((a1->ip ^ a2->ip) & m->ip) == 0;
case NFPROTO_IPV6:
return ipv6_masked_addr_cmp(&a1->in6, &m->in6, &a2->in6) == 0;
}
return false;
}
static bool
match_xfrm_state(const struct xfrm_state *x, const struct xt_policy_elem *e,
unsigned short family)
{
#define MATCH_ADDR(x,y,z) (!e->match.x || \
(xt_addr_cmp(&e->x, &e->y, (const union nf_inet_addr *)(z), family) \
^ e->invert.x))
#define MATCH(x,y) (!e->match.x || ((e->x == (y)) ^ e->invert.x))
return MATCH_ADDR(saddr, smask, &x->props.saddr) &&
MATCH_ADDR(daddr, dmask, &x->id.daddr) &&
MATCH(proto, x->id.proto) &&
MATCH(mode, x->props.mode) &&
MATCH(spi, x->id.spi) &&
MATCH(reqid, x->props.reqid);
}
static int
match_policy_in(const struct sk_buff *skb, const struct xt_policy_info *info,
unsigned short family)
{
const struct xt_policy_elem *e;
const struct sec_path *sp = skb->sp;
int strict = info->flags & XT_POLICY_MATCH_STRICT;
int i, pos;
if (sp == NULL)
return -1;
if (strict && info->len != sp->len)
return 0;
for (i = sp->len - 1; i >= 0; i--) {
pos = strict ? i - sp->len + 1 : 0;
if (pos >= info->len)
return 0;
e = &info->pol[pos];
if (match_xfrm_state(sp->xvec[i], e, family)) {
if (!strict)
return 1;
} else if (strict)
return 0;
}
return strict ? 1 : 0;
}
static int
match_policy_out(const struct sk_buff *skb, const struct xt_policy_info *info,
unsigned short family)
{
const struct xt_policy_elem *e;
const struct dst_entry *dst = skb_dst(skb);
int strict = info->flags & XT_POLICY_MATCH_STRICT;
int i, pos;
if (dst->xfrm == NULL)
return -1;
for (i = 0; dst && dst->xfrm; dst = dst->child, i++) {
pos = strict ? i : 0;
if (pos >= info->len)
return 0;
e = &info->pol[pos];
if (match_xfrm_state(dst->xfrm, e, family)) {
if (!strict)
return 1;
} else if (strict)
return 0;
}
return strict ? i == info->len : 0;
}
static bool
policy_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_policy_info *info = par->matchinfo;
int ret;
if (info->flags & XT_POLICY_MATCH_IN)
ret = match_policy_in(skb, info, par->family);
else
ret = match_policy_out(skb, info, par->family);
if (ret < 0)
ret = info->flags & XT_POLICY_MATCH_NONE ? true : false;
else if (info->flags & XT_POLICY_MATCH_NONE)
ret = false;
return ret;
}
static int policy_mt_check(const struct xt_mtchk_param *par)
{
const struct xt_policy_info *info = par->matchinfo;
if (!(info->flags & (XT_POLICY_MATCH_IN|XT_POLICY_MATCH_OUT))) {
pr_info("neither incoming nor outgoing policy selected\n");
return -EINVAL;
}
if (par->hook_mask & ((1 << NF_INET_PRE_ROUTING) |
(1 << NF_INET_LOCAL_IN)) && info->flags & XT_POLICY_MATCH_OUT) {
pr_info("output policy not valid in PREROUTING and INPUT\n");
return -EINVAL;
}
if (par->hook_mask & ((1 << NF_INET_POST_ROUTING) |
(1 << NF_INET_LOCAL_OUT)) && info->flags & XT_POLICY_MATCH_IN) {
pr_info("input policy not valid in POSTROUTING and OUTPUT\n");
return -EINVAL;
}
if (info->len > XT_POLICY_MAX_ELEM) {
pr_info("too many policy elements\n");
return -EINVAL;
}
return 0;
}
static int __init policy_mt_init(void)
{
return xt_register_matches(policy_mt_reg, ARRAY_SIZE(policy_mt_reg));
}
static void __exit policy_mt_exit(void)
{
xt_unregister_matches(policy_mt_reg, ARRAY_SIZE(policy_mt_reg));
}
