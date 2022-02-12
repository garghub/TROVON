static inline bool
type_match(u_int8_t min, u_int8_t max, u_int8_t type, bool invert)
{
return (type >= min && type <= max) ^ invert;
}
static bool mh_mt6(const struct sk_buff *skb, struct xt_action_param *par)
{
struct ip6_mh _mh;
const struct ip6_mh *mh;
const struct ip6t_mh *mhinfo = par->matchinfo;
if (par->fragoff != 0)
return false;
mh = skb_header_pointer(skb, par->thoff, sizeof(_mh), &_mh);
if (mh == NULL) {
pr_debug("Dropping evil MH tinygram.\n");
par->hotdrop = true;
return false;
}
if (mh->ip6mh_proto != IPPROTO_NONE) {
pr_debug("Dropping invalid MH Payload Proto: %u\n",
mh->ip6mh_proto);
par->hotdrop = true;
return false;
}
return type_match(mhinfo->types[0], mhinfo->types[1], mh->ip6mh_type,
!!(mhinfo->invflags & IP6T_MH_INV_TYPE));
}
static int mh_mt6_check(const struct xt_mtchk_param *par)
{
const struct ip6t_mh *mhinfo = par->matchinfo;
return (mhinfo->invflags & ~IP6T_MH_INV_MASK) ? -EINVAL : 0;
}
static int __init mh_mt6_init(void)
{
return xt_register_match(&mh_mt6_reg);
}
static void __exit mh_mt6_exit(void)
{
xt_unregister_match(&mh_mt6_reg);
}
