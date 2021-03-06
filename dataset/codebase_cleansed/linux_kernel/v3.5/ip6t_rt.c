static inline bool
segsleft_match(u_int32_t min, u_int32_t max, u_int32_t id, bool invert)
{
bool r;
pr_debug("segsleft_match:%c 0x%x <= 0x%x <= 0x%x\n",
invert ? '!' : ' ', min, id, max);
r = (id >= min && id <= max) ^ invert;
pr_debug(" result %s\n", r ? "PASS" : "FAILED");
return r;
}
static bool rt_mt6(const struct sk_buff *skb, struct xt_action_param *par)
{
struct ipv6_rt_hdr _route;
const struct ipv6_rt_hdr *rh;
const struct ip6t_rt *rtinfo = par->matchinfo;
unsigned int temp;
unsigned int ptr = 0;
unsigned int hdrlen = 0;
bool ret = false;
struct in6_addr _addr;
const struct in6_addr *ap;
int err;
err = ipv6_find_hdr(skb, &ptr, NEXTHDR_ROUTING, NULL, NULL);
if (err < 0) {
if (err != -ENOENT)
par->hotdrop = true;
return false;
}
rh = skb_header_pointer(skb, ptr, sizeof(_route), &_route);
if (rh == NULL) {
par->hotdrop = true;
return false;
}
hdrlen = ipv6_optlen(rh);
if (skb->len - ptr < hdrlen) {
return false;
}
pr_debug("IPv6 RT LEN %u %u ", hdrlen, rh->hdrlen);
pr_debug("TYPE %04X ", rh->type);
pr_debug("SGS_LEFT %u %02X\n", rh->segments_left, rh->segments_left);
pr_debug("IPv6 RT segsleft %02X ",
segsleft_match(rtinfo->segsleft[0], rtinfo->segsleft[1],
rh->segments_left,
!!(rtinfo->invflags & IP6T_RT_INV_SGS)));
pr_debug("type %02X %02X %02X ",
rtinfo->rt_type, rh->type,
(!(rtinfo->flags & IP6T_RT_TYP) ||
((rtinfo->rt_type == rh->type) ^
!!(rtinfo->invflags & IP6T_RT_INV_TYP))));
pr_debug("len %02X %04X %02X ",
rtinfo->hdrlen, hdrlen,
!(rtinfo->flags & IP6T_RT_LEN) ||
((rtinfo->hdrlen == hdrlen) ^
!!(rtinfo->invflags & IP6T_RT_INV_LEN)));
pr_debug("res %02X %02X %02X ",
rtinfo->flags & IP6T_RT_RES,
((const struct rt0_hdr *)rh)->reserved,
!((rtinfo->flags & IP6T_RT_RES) &&
(((const struct rt0_hdr *)rh)->reserved)));
ret = (rh != NULL) &&
(segsleft_match(rtinfo->segsleft[0], rtinfo->segsleft[1],
rh->segments_left,
!!(rtinfo->invflags & IP6T_RT_INV_SGS))) &&
(!(rtinfo->flags & IP6T_RT_LEN) ||
((rtinfo->hdrlen == hdrlen) ^
!!(rtinfo->invflags & IP6T_RT_INV_LEN))) &&
(!(rtinfo->flags & IP6T_RT_TYP) ||
((rtinfo->rt_type == rh->type) ^
!!(rtinfo->invflags & IP6T_RT_INV_TYP)));
if (ret && (rtinfo->flags & IP6T_RT_RES)) {
const u_int32_t *rp;
u_int32_t _reserved;
rp = skb_header_pointer(skb,
ptr + offsetof(struct rt0_hdr,
reserved),
sizeof(_reserved),
&_reserved);
ret = (*rp == 0);
}
pr_debug("#%d ", rtinfo->addrnr);
if (!(rtinfo->flags & IP6T_RT_FST)) {
return ret;
} else if (rtinfo->flags & IP6T_RT_FST_NSTRICT) {
pr_debug("Not strict ");
if (rtinfo->addrnr > (unsigned int)((hdrlen - 8) / 16)) {
pr_debug("There isn't enough space\n");
return false;
} else {
unsigned int i = 0;
pr_debug("#%d ", rtinfo->addrnr);
for (temp = 0;
temp < (unsigned int)((hdrlen - 8) / 16);
temp++) {
ap = skb_header_pointer(skb,
ptr
+ sizeof(struct rt0_hdr)
+ temp * sizeof(_addr),
sizeof(_addr),
&_addr);
BUG_ON(ap == NULL);
if (ipv6_addr_equal(ap, &rtinfo->addrs[i])) {
pr_debug("i=%d temp=%d;\n", i, temp);
i++;
}
if (i == rtinfo->addrnr)
break;
}
pr_debug("i=%d #%d\n", i, rtinfo->addrnr);
if (i == rtinfo->addrnr)
return ret;
else
return false;
}
} else {
pr_debug("Strict ");
if (rtinfo->addrnr > (unsigned int)((hdrlen - 8) / 16)) {
pr_debug("There isn't enough space\n");
return false;
} else {
pr_debug("#%d ", rtinfo->addrnr);
for (temp = 0; temp < rtinfo->addrnr; temp++) {
ap = skb_header_pointer(skb,
ptr
+ sizeof(struct rt0_hdr)
+ temp * sizeof(_addr),
sizeof(_addr),
&_addr);
BUG_ON(ap == NULL);
if (!ipv6_addr_equal(ap, &rtinfo->addrs[temp]))
break;
}
pr_debug("temp=%d #%d\n", temp, rtinfo->addrnr);
if (temp == rtinfo->addrnr &&
temp == (unsigned int)((hdrlen - 8) / 16))
return ret;
else
return false;
}
}
return false;
}
static int rt_mt6_check(const struct xt_mtchk_param *par)
{
const struct ip6t_rt *rtinfo = par->matchinfo;
if (rtinfo->invflags & ~IP6T_RT_INV_MASK) {
pr_debug("unknown flags %X\n", rtinfo->invflags);
return -EINVAL;
}
if ((rtinfo->flags & (IP6T_RT_RES | IP6T_RT_FST_MASK)) &&
(!(rtinfo->flags & IP6T_RT_TYP) ||
(rtinfo->rt_type != 0) ||
(rtinfo->invflags & IP6T_RT_INV_TYP))) {
pr_debug("`--rt-type 0' required before `--rt-0-*'");
return -EINVAL;
}
return 0;
}
static int __init rt_mt6_init(void)
{
return xt_register_match(&rt_mt6_reg);
}
static void __exit rt_mt6_exit(void)
{
xt_unregister_match(&rt_mt6_reg);
}
