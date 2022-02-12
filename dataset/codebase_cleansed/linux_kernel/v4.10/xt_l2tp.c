static bool l2tp_match(const struct xt_l2tp_info *info, struct l2tp_data *data)
{
if ((info->flags & XT_L2TP_TYPE) && (info->type != data->type))
return false;
if ((info->flags & XT_L2TP_VERSION) && (info->version != data->version))
return false;
if ((info->flags & XT_L2TP_TID) &&
((data->type == XT_L2TP_TYPE_CONTROL) || (data->version == 2)) &&
(info->tid != data->tid))
return false;
if ((info->flags & XT_L2TP_SID) && (data->type == XT_L2TP_TYPE_DATA) &&
(info->sid != data->sid))
return false;
return true;
}
static bool l2tp_udp_mt(const struct sk_buff *skb, struct xt_action_param *par, u16 thoff)
{
const struct xt_l2tp_info *info = par->matchinfo;
int uhlen = sizeof(struct udphdr);
int offs = thoff + uhlen;
union l2tp_val *lh;
union l2tp_val lhbuf;
u16 flags;
struct l2tp_data data = { 0, };
if (par->fragoff != 0)
return false;
lh = skb_header_pointer(skb, offs, 2, &lhbuf);
if (lh == NULL)
return false;
flags = ntohs(lh->val16[0]);
if (flags & L2TP_HDR_T_BIT)
data.type = XT_L2TP_TYPE_CONTROL;
else
data.type = XT_L2TP_TYPE_DATA;
data.version = (u8) flags & L2TP_HDR_VER;
if (data.version == 3) {
lh = skb_header_pointer(skb, offs + 4, 4, &lhbuf);
if (lh == NULL)
return false;
if (data.type == XT_L2TP_TYPE_CONTROL)
data.tid = ntohl(lh->val32);
else
data.sid = ntohl(lh->val32);
} else if (data.version == 2) {
if (flags & L2TP_HDR_L_BIT)
offs += 2;
lh = skb_header_pointer(skb, offs + 2, 4, &lhbuf);
if (lh == NULL)
return false;
data.tid = (u32) ntohs(lh->val16[0]);
data.sid = (u32) ntohs(lh->val16[1]);
} else
return false;
return l2tp_match(info, &data);
}
static bool l2tp_ip_mt(const struct sk_buff *skb, struct xt_action_param *par, u16 thoff)
{
const struct xt_l2tp_info *info = par->matchinfo;
union l2tp_val *lh;
union l2tp_val lhbuf;
struct l2tp_data data = { 0, };
lh = skb_header_pointer(skb, thoff, sizeof(lhbuf), &lhbuf);
if (lh == NULL)
return false;
if (lh->val32 == 0) {
data.type = XT_L2TP_TYPE_CONTROL;
lh = skb_header_pointer(skb, thoff + 8, sizeof(lhbuf),
&lhbuf);
if (lh == NULL)
return false;
data.tid = ntohl(lh->val32);
} else {
data.sid = ntohl(lh->val32);
data.type = XT_L2TP_TYPE_DATA;
}
data.version = 3;
return l2tp_match(info, &data);
}
static bool l2tp_mt4(const struct sk_buff *skb, struct xt_action_param *par)
{
struct iphdr *iph = ip_hdr(skb);
u8 ipproto = iph->protocol;
switch (ipproto) {
case IPPROTO_UDP:
return l2tp_udp_mt(skb, par, par->thoff);
case IPPROTO_L2TP:
return l2tp_ip_mt(skb, par, par->thoff);
}
return false;
}
static bool l2tp_mt6(const struct sk_buff *skb, struct xt_action_param *par)
{
unsigned int thoff = 0;
unsigned short fragoff = 0;
int ipproto;
ipproto = ipv6_find_hdr(skb, &thoff, -1, &fragoff, NULL);
if (fragoff != 0)
return false;
switch (ipproto) {
case IPPROTO_UDP:
return l2tp_udp_mt(skb, par, thoff);
case IPPROTO_L2TP:
return l2tp_ip_mt(skb, par, thoff);
}
return false;
}
static int l2tp_mt_check(const struct xt_mtchk_param *par)
{
const struct xt_l2tp_info *info = par->matchinfo;
if (info->flags & ~(XT_L2TP_TID | XT_L2TP_SID | XT_L2TP_VERSION |
XT_L2TP_TYPE)) {
pr_info("unknown flags: %x\n", info->flags);
return -EINVAL;
}
if ((!(info->flags & XT_L2TP_TID)) &&
(!(info->flags & XT_L2TP_SID)) &&
((!(info->flags & XT_L2TP_TYPE)) ||
(info->type != XT_L2TP_TYPE_CONTROL))) {
pr_info("invalid flags combination: %x\n", info->flags);
return -EINVAL;
}
if (info->flags & XT_L2TP_VERSION) {
if ((info->version < 2) || (info->version > 3)) {
pr_info("wrong L2TP version: %u\n", info->version);
return -EINVAL;
}
if (info->version == 2) {
if ((info->flags & XT_L2TP_TID) &&
(info->tid > 0xffff)) {
pr_info("v2 tid > 0xffff: %u\n", info->tid);
return -EINVAL;
}
if ((info->flags & XT_L2TP_SID) &&
(info->sid > 0xffff)) {
pr_info("v2 sid > 0xffff: %u\n", info->sid);
return -EINVAL;
}
}
}
return 0;
}
static int l2tp_mt_check4(const struct xt_mtchk_param *par)
{
const struct xt_l2tp_info *info = par->matchinfo;
const struct ipt_entry *e = par->entryinfo;
const struct ipt_ip *ip = &e->ip;
int ret;
ret = l2tp_mt_check(par);
if (ret != 0)
return ret;
if ((ip->proto != IPPROTO_UDP) &&
(ip->proto != IPPROTO_L2TP)) {
pr_info("missing protocol rule (udp|l2tpip)\n");
return -EINVAL;
}
if ((ip->proto == IPPROTO_L2TP) &&
(info->version == 2)) {
pr_info("v2 doesn't support IP mode\n");
return -EINVAL;
}
return 0;
}
static int l2tp_mt_check6(const struct xt_mtchk_param *par)
{
const struct xt_l2tp_info *info = par->matchinfo;
const struct ip6t_entry *e = par->entryinfo;
const struct ip6t_ip6 *ip = &e->ipv6;
int ret;
ret = l2tp_mt_check(par);
if (ret != 0)
return ret;
if ((ip->proto != IPPROTO_UDP) &&
(ip->proto != IPPROTO_L2TP)) {
pr_info("missing protocol rule (udp|l2tpip)\n");
return -EINVAL;
}
if ((ip->proto == IPPROTO_L2TP) &&
(info->version == 2)) {
pr_info("v2 doesn't support IP mode\n");
return -EINVAL;
}
return 0;
}
static int __init l2tp_mt_init(void)
{
return xt_register_matches(&l2tp_mt_reg[0], ARRAY_SIZE(l2tp_mt_reg));
}
static void __exit l2tp_mt_exit(void)
{
xt_unregister_matches(&l2tp_mt_reg[0], ARRAY_SIZE(l2tp_mt_reg));
}
