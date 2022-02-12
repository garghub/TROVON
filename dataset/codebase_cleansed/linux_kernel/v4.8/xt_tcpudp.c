static inline bool
port_match(u_int16_t min, u_int16_t max, u_int16_t port, bool invert)
{
return (port >= min && port <= max) ^ invert;
}
static bool
tcp_find_option(u_int8_t option,
const struct sk_buff *skb,
unsigned int protoff,
unsigned int optlen,
bool invert,
bool *hotdrop)
{
const u_int8_t *op;
u_int8_t _opt[60 - sizeof(struct tcphdr)];
unsigned int i;
pr_debug("finding option\n");
if (!optlen)
return invert;
op = skb_header_pointer(skb, protoff + sizeof(struct tcphdr),
optlen, _opt);
if (op == NULL) {
*hotdrop = true;
return false;
}
for (i = 0; i < optlen; ) {
if (op[i] == option) return !invert;
if (op[i] < 2) i++;
else i += op[i+1]?:1;
}
return invert;
}
static bool tcp_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct tcphdr *th;
struct tcphdr _tcph;
const struct xt_tcp *tcpinfo = par->matchinfo;
if (par->fragoff != 0) {
if (par->fragoff == 1) {
pr_debug("Dropping evil TCP offset=1 frag.\n");
par->hotdrop = true;
}
return false;
}
th = skb_header_pointer(skb, par->thoff, sizeof(_tcph), &_tcph);
if (th == NULL) {
pr_debug("Dropping evil TCP offset=0 tinygram.\n");
par->hotdrop = true;
return false;
}
if (!port_match(tcpinfo->spts[0], tcpinfo->spts[1],
ntohs(th->source),
!!(tcpinfo->invflags & XT_TCP_INV_SRCPT)))
return false;
if (!port_match(tcpinfo->dpts[0], tcpinfo->dpts[1],
ntohs(th->dest),
!!(tcpinfo->invflags & XT_TCP_INV_DSTPT)))
return false;
if (!NF_INVF(tcpinfo, XT_TCP_INV_FLAGS,
(((unsigned char *)th)[13] & tcpinfo->flg_mask) == tcpinfo->flg_cmp))
return false;
if (tcpinfo->option) {
if (th->doff * 4 < sizeof(_tcph)) {
par->hotdrop = true;
return false;
}
if (!tcp_find_option(tcpinfo->option, skb, par->thoff,
th->doff*4 - sizeof(_tcph),
tcpinfo->invflags & XT_TCP_INV_OPTION,
&par->hotdrop))
return false;
}
return true;
}
static int tcp_mt_check(const struct xt_mtchk_param *par)
{
const struct xt_tcp *tcpinfo = par->matchinfo;
return (tcpinfo->invflags & ~XT_TCP_INV_MASK) ? -EINVAL : 0;
}
static bool udp_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct udphdr *uh;
struct udphdr _udph;
const struct xt_udp *udpinfo = par->matchinfo;
if (par->fragoff != 0)
return false;
uh = skb_header_pointer(skb, par->thoff, sizeof(_udph), &_udph);
if (uh == NULL) {
pr_debug("Dropping evil UDP tinygram.\n");
par->hotdrop = true;
return false;
}
return port_match(udpinfo->spts[0], udpinfo->spts[1],
ntohs(uh->source),
!!(udpinfo->invflags & XT_UDP_INV_SRCPT))
&& port_match(udpinfo->dpts[0], udpinfo->dpts[1],
ntohs(uh->dest),
!!(udpinfo->invflags & XT_UDP_INV_DSTPT));
}
static int udp_mt_check(const struct xt_mtchk_param *par)
{
const struct xt_udp *udpinfo = par->matchinfo;
return (udpinfo->invflags & ~XT_UDP_INV_MASK) ? -EINVAL : 0;
}
static int __init tcpudp_mt_init(void)
{
return xt_register_matches(tcpudp_mt_reg, ARRAY_SIZE(tcpudp_mt_reg));
}
static void __exit tcpudp_mt_exit(void)
{
xt_unregister_matches(tcpudp_mt_reg, ARRAY_SIZE(tcpudp_mt_reg));
}
