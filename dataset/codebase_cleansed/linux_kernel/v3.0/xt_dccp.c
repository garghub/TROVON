static inline bool
dccp_find_option(u_int8_t option,
const struct sk_buff *skb,
unsigned int protoff,
const struct dccp_hdr *dh,
bool *hotdrop)
{
const unsigned char *op;
unsigned int optoff = __dccp_hdr_len(dh);
unsigned int optlen = dh->dccph_doff*4 - __dccp_hdr_len(dh);
unsigned int i;
if (dh->dccph_doff * 4 < __dccp_hdr_len(dh))
goto invalid;
if (!optlen)
return false;
spin_lock_bh(&dccp_buflock);
op = skb_header_pointer(skb, protoff + optoff, optlen, dccp_optbuf);
if (op == NULL) {
goto partial;
}
for (i = 0; i < optlen; ) {
if (op[i] == option) {
spin_unlock_bh(&dccp_buflock);
return true;
}
if (op[i] < 2)
i++;
else
i += op[i+1]?:1;
}
spin_unlock_bh(&dccp_buflock);
return false;
partial:
spin_unlock_bh(&dccp_buflock);
invalid:
*hotdrop = true;
return false;
}
static inline bool
match_types(const struct dccp_hdr *dh, u_int16_t typemask)
{
return typemask & (1 << dh->dccph_type);
}
static inline bool
match_option(u_int8_t option, const struct sk_buff *skb, unsigned int protoff,
const struct dccp_hdr *dh, bool *hotdrop)
{
return dccp_find_option(option, skb, protoff, dh, hotdrop);
}
static bool
dccp_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_dccp_info *info = par->matchinfo;
const struct dccp_hdr *dh;
struct dccp_hdr _dh;
if (par->fragoff != 0)
return false;
dh = skb_header_pointer(skb, par->thoff, sizeof(_dh), &_dh);
if (dh == NULL) {
par->hotdrop = true;
return false;
}
return DCCHECK(ntohs(dh->dccph_sport) >= info->spts[0]
&& ntohs(dh->dccph_sport) <= info->spts[1],
XT_DCCP_SRC_PORTS, info->flags, info->invflags)
&& DCCHECK(ntohs(dh->dccph_dport) >= info->dpts[0]
&& ntohs(dh->dccph_dport) <= info->dpts[1],
XT_DCCP_DEST_PORTS, info->flags, info->invflags)
&& DCCHECK(match_types(dh, info->typemask),
XT_DCCP_TYPE, info->flags, info->invflags)
&& DCCHECK(match_option(info->option, skb, par->thoff, dh,
&par->hotdrop),
XT_DCCP_OPTION, info->flags, info->invflags);
}
static int dccp_mt_check(const struct xt_mtchk_param *par)
{
const struct xt_dccp_info *info = par->matchinfo;
if (info->flags & ~XT_DCCP_VALID_FLAGS)
return -EINVAL;
if (info->invflags & ~XT_DCCP_VALID_FLAGS)
return -EINVAL;
if (info->invflags & ~info->flags)
return -EINVAL;
return 0;
}
static int __init dccp_mt_init(void)
{
int ret;
dccp_optbuf = kmalloc(256 * 4, GFP_KERNEL);
if (!dccp_optbuf)
return -ENOMEM;
ret = xt_register_matches(dccp_mt_reg, ARRAY_SIZE(dccp_mt_reg));
if (ret)
goto out_kfree;
return ret;
out_kfree:
kfree(dccp_optbuf);
return ret;
}
static void __exit dccp_mt_exit(void)
{
xt_unregister_matches(dccp_mt_reg, ARRAY_SIZE(dccp_mt_reg));
kfree(dccp_optbuf);
}
