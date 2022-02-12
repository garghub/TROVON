static bool
ebt_802_3_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct ebt_802_3_info *info = par->matchinfo;
const struct ebt_802_3_hdr *hdr = ebt_802_3_hdr(skb);
__be16 type = hdr->llc.ui.ctrl & IS_UI ? hdr->llc.ui.type : hdr->llc.ni.type;
if (info->bitmask & EBT_802_3_SAP) {
if (FWINV(info->sap != hdr->llc.ui.ssap, EBT_802_3_SAP))
return false;
if (FWINV(info->sap != hdr->llc.ui.dsap, EBT_802_3_SAP))
return false;
}
if (info->bitmask & EBT_802_3_TYPE) {
if (!(hdr->llc.ui.dsap == CHECK_TYPE && hdr->llc.ui.ssap == CHECK_TYPE))
return false;
if (FWINV(info->type != type, EBT_802_3_TYPE))
return false;
}
return true;
}
static int ebt_802_3_mt_check(const struct xt_mtchk_param *par)
{
const struct ebt_802_3_info *info = par->matchinfo;
if (info->bitmask & ~EBT_802_3_MASK || info->invflags & ~EBT_802_3_MASK)
return -EINVAL;
return 0;
}
static int __init ebt_802_3_init(void)
{
return xt_register_match(&ebt_802_3_mt_reg);
}
static void __exit ebt_802_3_fini(void)
{
xt_unregister_match(&ebt_802_3_mt_reg);
}
