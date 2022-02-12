static inline unsigned int optlen(const u_int8_t *opt, unsigned int offset)
{
if (opt[offset] <= TCPOPT_NOP || opt[offset+1] == 0)
return 1;
else
return opt[offset+1];
}
static unsigned int
tcpoptstrip_mangle_packet(struct sk_buff *skb,
const struct xt_action_param *par,
unsigned int tcphoff, unsigned int minlen)
{
const struct xt_tcpoptstrip_target_info *info = par->targinfo;
unsigned int optl, i, j;
struct tcphdr *tcph;
u_int16_t n, o;
u_int8_t *opt;
int len, tcp_hdrlen;
if (par->fragoff != 0)
return XT_CONTINUE;
if (!skb_make_writable(skb, skb->len))
return NF_DROP;
len = skb->len - tcphoff;
if (len < (int)sizeof(struct tcphdr))
return NF_DROP;
tcph = (struct tcphdr *)(skb_network_header(skb) + tcphoff);
tcp_hdrlen = tcph->doff * 4;
if (len < tcp_hdrlen)
return NF_DROP;
opt = (u_int8_t *)tcph;
for (i = sizeof(struct tcphdr); i < tcp_hdrlen - 1; i += optl) {
optl = optlen(opt, i);
if (i + optl > tcp_hdrlen)
break;
if (!tcpoptstrip_test_bit(info->strip_bmap, opt[i]))
continue;
for (j = 0; j < optl; ++j) {
o = opt[i+j];
n = TCPOPT_NOP;
if ((i + j) % 2 == 0) {
o <<= 8;
n <<= 8;
}
inet_proto_csum_replace2(&tcph->check, skb, htons(o),
htons(n), 0);
}
memset(opt + i, TCPOPT_NOP, optl);
}
return XT_CONTINUE;
}
static unsigned int
tcpoptstrip_tg4(struct sk_buff *skb, const struct xt_action_param *par)
{
return tcpoptstrip_mangle_packet(skb, par, ip_hdrlen(skb),
sizeof(struct iphdr) + sizeof(struct tcphdr));
}
static unsigned int
tcpoptstrip_tg6(struct sk_buff *skb, const struct xt_action_param *par)
{
struct ipv6hdr *ipv6h = ipv6_hdr(skb);
int tcphoff;
u_int8_t nexthdr;
__be16 frag_off;
nexthdr = ipv6h->nexthdr;
tcphoff = ipv6_skip_exthdr(skb, sizeof(*ipv6h), &nexthdr, &frag_off);
if (tcphoff < 0)
return NF_DROP;
return tcpoptstrip_mangle_packet(skb, par, tcphoff,
sizeof(*ipv6h) + sizeof(struct tcphdr));
}
static int __init tcpoptstrip_tg_init(void)
{
return xt_register_targets(tcpoptstrip_tg_reg,
ARRAY_SIZE(tcpoptstrip_tg_reg));
}
static void __exit tcpoptstrip_tg_exit(void)
{
xt_unregister_targets(tcpoptstrip_tg_reg,
ARRAY_SIZE(tcpoptstrip_tg_reg));
}
