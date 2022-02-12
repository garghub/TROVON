static bool
ebt_vlan_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct ebt_vlan_info *info = par->matchinfo;
unsigned short TCI;
unsigned short id;
unsigned char prio;
__be16 encap;
if (vlan_tx_tag_present(skb)) {
TCI = vlan_tx_tag_get(skb);
encap = skb->protocol;
} else {
const struct vlan_hdr *fp;
struct vlan_hdr _frame;
fp = skb_header_pointer(skb, 0, sizeof(_frame), &_frame);
if (fp == NULL)
return false;
TCI = ntohs(fp->h_vlan_TCI);
encap = fp->h_vlan_encapsulated_proto;
}
id = TCI & VLAN_VID_MASK;
prio = (TCI >> 13) & 0x7;
if (GET_BITMASK(EBT_VLAN_ID))
EXIT_ON_MISMATCH(id, EBT_VLAN_ID);
if (GET_BITMASK(EBT_VLAN_PRIO))
EXIT_ON_MISMATCH(prio, EBT_VLAN_PRIO);
if (GET_BITMASK(EBT_VLAN_ENCAP))
EXIT_ON_MISMATCH(encap, EBT_VLAN_ENCAP);
return true;
}
static int ebt_vlan_mt_check(const struct xt_mtchk_param *par)
{
struct ebt_vlan_info *info = par->matchinfo;
const struct ebt_entry *e = par->entryinfo;
if (e->ethproto != htons(ETH_P_8021Q)) {
pr_debug("passed entry proto %2.4X is not 802.1Q (8100)\n",
ntohs(e->ethproto));
return -EINVAL;
}
if (info->bitmask & ~EBT_VLAN_MASK) {
pr_debug("bitmask %2X is out of mask (%2X)\n",
info->bitmask, EBT_VLAN_MASK);
return -EINVAL;
}
if (info->invflags & ~EBT_VLAN_MASK) {
pr_debug("inversion flags %2X is out of mask (%2X)\n",
info->invflags, EBT_VLAN_MASK);
return -EINVAL;
}
if (GET_BITMASK(EBT_VLAN_ID)) {
if (!!info->id) {
if (info->id > VLAN_N_VID) {
pr_debug("id %d is out of range (1-4096)\n",
info->id);
return -EINVAL;
}
info->bitmask &= ~EBT_VLAN_PRIO;
}
}
if (GET_BITMASK(EBT_VLAN_PRIO)) {
if ((unsigned char) info->prio > 7) {
pr_debug("prio %d is out of range (0-7)\n",
info->prio);
return -EINVAL;
}
}
if (GET_BITMASK(EBT_VLAN_ENCAP)) {
if ((unsigned short) ntohs(info->encap) < ETH_ZLEN) {
pr_debug("encap frame length %d is less than "
"minimal\n", ntohs(info->encap));
return -EINVAL;
}
}
return 0;
}
static int __init ebt_vlan_init(void)
{
pr_debug("ebtables 802.1Q extension module v" MODULE_VERS "\n");
return xt_register_match(&ebt_vlan_mt_reg);
}
static void __exit ebt_vlan_fini(void)
{
xt_unregister_match(&ebt_vlan_mt_reg);
}
