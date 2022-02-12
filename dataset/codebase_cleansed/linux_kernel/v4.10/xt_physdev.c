static bool
physdev_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_physdev_info *info = par->matchinfo;
const struct net_device *physdev;
unsigned long ret;
const char *indev, *outdev;
if (!skb->nf_bridge) {
if ((info->bitmask & XT_PHYSDEV_OP_BRIDGED) &&
!(info->invert & XT_PHYSDEV_OP_BRIDGED))
return false;
if ((info->bitmask & XT_PHYSDEV_OP_ISIN) &&
!(info->invert & XT_PHYSDEV_OP_ISIN))
return false;
if ((info->bitmask & XT_PHYSDEV_OP_ISOUT) &&
!(info->invert & XT_PHYSDEV_OP_ISOUT))
return false;
if ((info->bitmask & XT_PHYSDEV_OP_IN) &&
!(info->invert & XT_PHYSDEV_OP_IN))
return false;
if ((info->bitmask & XT_PHYSDEV_OP_OUT) &&
!(info->invert & XT_PHYSDEV_OP_OUT))
return false;
return true;
}
physdev = nf_bridge_get_physoutdev(skb);
outdev = physdev ? physdev->name : NULL;
if ((info->bitmask & XT_PHYSDEV_OP_BRIDGED) &&
(!!outdev ^ !(info->invert & XT_PHYSDEV_OP_BRIDGED)))
return false;
physdev = nf_bridge_get_physindev(skb);
indev = physdev ? physdev->name : NULL;
if ((info->bitmask & XT_PHYSDEV_OP_ISIN &&
(!indev ^ !!(info->invert & XT_PHYSDEV_OP_ISIN))) ||
(info->bitmask & XT_PHYSDEV_OP_ISOUT &&
(!outdev ^ !!(info->invert & XT_PHYSDEV_OP_ISOUT))))
return false;
if (!(info->bitmask & XT_PHYSDEV_OP_IN))
goto match_outdev;
if (indev) {
ret = ifname_compare_aligned(indev, info->physindev,
info->in_mask);
if (!ret ^ !(info->invert & XT_PHYSDEV_OP_IN))
return false;
}
match_outdev:
if (!(info->bitmask & XT_PHYSDEV_OP_OUT))
return true;
if (!outdev)
return false;
ret = ifname_compare_aligned(outdev, info->physoutdev, info->out_mask);
return (!!ret ^ !(info->invert & XT_PHYSDEV_OP_OUT));
}
static int physdev_mt_check(const struct xt_mtchk_param *par)
{
const struct xt_physdev_info *info = par->matchinfo;
br_netfilter_enable();
if (!(info->bitmask & XT_PHYSDEV_OP_MASK) ||
info->bitmask & ~XT_PHYSDEV_OP_MASK)
return -EINVAL;
if (info->bitmask & (XT_PHYSDEV_OP_OUT | XT_PHYSDEV_OP_ISOUT) &&
(!(info->bitmask & XT_PHYSDEV_OP_BRIDGED) ||
info->invert & XT_PHYSDEV_OP_BRIDGED) &&
par->hook_mask & ((1 << NF_INET_LOCAL_OUT) |
(1 << NF_INET_FORWARD) | (1 << NF_INET_POST_ROUTING))) {
pr_info("using --physdev-out and --physdev-is-out are only "
"supported in the FORWARD and POSTROUTING chains with "
"bridged traffic.\n");
if (par->hook_mask & (1 << NF_INET_LOCAL_OUT))
return -EINVAL;
}
return 0;
}
static int __init physdev_mt_init(void)
{
return xt_register_match(&physdev_mt_reg);
}
static void __exit physdev_mt_exit(void)
{
xt_unregister_match(&physdev_mt_reg);
}
