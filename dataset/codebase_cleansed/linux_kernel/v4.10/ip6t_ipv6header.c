static bool
ipv6header_mt6(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct ip6t_ipv6header_info *info = par->matchinfo;
unsigned int temp;
int len;
u8 nexthdr;
unsigned int ptr;
nexthdr = ipv6_hdr(skb)->nexthdr;
ptr = sizeof(struct ipv6hdr);
len = skb->len - ptr;
temp = 0;
while (ip6t_ext_hdr(nexthdr)) {
const struct ipv6_opt_hdr *hp;
struct ipv6_opt_hdr _hdr;
int hdrlen;
if (nexthdr == NEXTHDR_NONE) {
temp |= MASK_NONE;
break;
}
if (len < (int)sizeof(struct ipv6_opt_hdr))
return false;
if (nexthdr == NEXTHDR_ESP) {
temp |= MASK_ESP;
break;
}
hp = skb_header_pointer(skb, ptr, sizeof(_hdr), &_hdr);
BUG_ON(hp == NULL);
if (nexthdr == NEXTHDR_FRAGMENT)
hdrlen = 8;
else if (nexthdr == NEXTHDR_AUTH)
hdrlen = (hp->hdrlen + 2) << 2;
else
hdrlen = ipv6_optlen(hp);
switch (nexthdr) {
case NEXTHDR_HOP:
temp |= MASK_HOPOPTS;
break;
case NEXTHDR_ROUTING:
temp |= MASK_ROUTING;
break;
case NEXTHDR_FRAGMENT:
temp |= MASK_FRAGMENT;
break;
case NEXTHDR_AUTH:
temp |= MASK_AH;
break;
case NEXTHDR_DEST:
temp |= MASK_DSTOPTS;
break;
default:
return false;
}
nexthdr = hp->nexthdr;
len -= hdrlen;
ptr += hdrlen;
if (ptr > skb->len)
break;
}
if (nexthdr != NEXTHDR_NONE && nexthdr != NEXTHDR_ESP)
temp |= MASK_PROTO;
if (info->modeflag)
return !((temp ^ info->matchflags ^ info->invflags)
& info->matchflags);
else {
if (info->invflags)
return temp != info->matchflags;
else
return temp == info->matchflags;
}
}
static int ipv6header_mt6_check(const struct xt_mtchk_param *par)
{
const struct ip6t_ipv6header_info *info = par->matchinfo;
if ((!info->modeflag) && info->invflags != 0x00 &&
info->invflags != 0xFF)
return -EINVAL;
return 0;
}
static int __init ipv6header_mt6_init(void)
{
return xt_register_match(&ipv6header_mt6_reg);
}
static void __exit ipv6header_mt6_exit(void)
{
xt_unregister_match(&ipv6header_mt6_reg);
}
