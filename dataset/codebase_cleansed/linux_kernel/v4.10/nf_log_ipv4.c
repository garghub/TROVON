static void dump_ipv4_packet(struct nf_log_buf *m,
const struct nf_loginfo *info,
const struct sk_buff *skb, unsigned int iphoff)
{
struct iphdr _iph;
const struct iphdr *ih;
unsigned int logflags;
if (info->type == NF_LOG_TYPE_LOG)
logflags = info->u.log.logflags;
else
logflags = NF_LOG_DEFAULT_MASK;
ih = skb_header_pointer(skb, iphoff, sizeof(_iph), &_iph);
if (ih == NULL) {
nf_log_buf_add(m, "TRUNCATED");
return;
}
nf_log_buf_add(m, "SRC=%pI4 DST=%pI4 ", &ih->saddr, &ih->daddr);
nf_log_buf_add(m, "LEN=%u TOS=0x%02X PREC=0x%02X TTL=%u ID=%u ",
ntohs(ih->tot_len), ih->tos & IPTOS_TOS_MASK,
ih->tos & IPTOS_PREC_MASK, ih->ttl, ntohs(ih->id));
if (ntohs(ih->frag_off) & IP_CE)
nf_log_buf_add(m, "CE ");
if (ntohs(ih->frag_off) & IP_DF)
nf_log_buf_add(m, "DF ");
if (ntohs(ih->frag_off) & IP_MF)
nf_log_buf_add(m, "MF ");
if (ntohs(ih->frag_off) & IP_OFFSET)
nf_log_buf_add(m, "FRAG:%u ", ntohs(ih->frag_off) & IP_OFFSET);
if ((logflags & NF_LOG_IPOPT) &&
ih->ihl * 4 > sizeof(struct iphdr)) {
const unsigned char *op;
unsigned char _opt[4 * 15 - sizeof(struct iphdr)];
unsigned int i, optsize;
optsize = ih->ihl * 4 - sizeof(struct iphdr);
op = skb_header_pointer(skb, iphoff+sizeof(_iph),
optsize, _opt);
if (op == NULL) {
nf_log_buf_add(m, "TRUNCATED");
return;
}
nf_log_buf_add(m, "OPT (");
for (i = 0; i < optsize; i++)
nf_log_buf_add(m, "%02X", op[i]);
nf_log_buf_add(m, ") ");
}
switch (ih->protocol) {
case IPPROTO_TCP:
if (nf_log_dump_tcp_header(m, skb, ih->protocol,
ntohs(ih->frag_off) & IP_OFFSET,
iphoff+ih->ihl*4, logflags))
return;
break;
case IPPROTO_UDP:
case IPPROTO_UDPLITE:
if (nf_log_dump_udp_header(m, skb, ih->protocol,
ntohs(ih->frag_off) & IP_OFFSET,
iphoff+ih->ihl*4))
return;
break;
case IPPROTO_ICMP: {
struct icmphdr _icmph;
const struct icmphdr *ich;
static const size_t required_len[NR_ICMP_TYPES+1]
= { [ICMP_ECHOREPLY] = 4,
[ICMP_DEST_UNREACH]
= 8 + sizeof(struct iphdr),
[ICMP_SOURCE_QUENCH]
= 8 + sizeof(struct iphdr),
[ICMP_REDIRECT]
= 8 + sizeof(struct iphdr),
[ICMP_ECHO] = 4,
[ICMP_TIME_EXCEEDED]
= 8 + sizeof(struct iphdr),
[ICMP_PARAMETERPROB]
= 8 + sizeof(struct iphdr),
[ICMP_TIMESTAMP] = 20,
[ICMP_TIMESTAMPREPLY] = 20,
[ICMP_ADDRESS] = 12,
[ICMP_ADDRESSREPLY] = 12 };
nf_log_buf_add(m, "PROTO=ICMP ");
if (ntohs(ih->frag_off) & IP_OFFSET)
break;
ich = skb_header_pointer(skb, iphoff + ih->ihl * 4,
sizeof(_icmph), &_icmph);
if (ich == NULL) {
nf_log_buf_add(m, "INCOMPLETE [%u bytes] ",
skb->len - iphoff - ih->ihl*4);
break;
}
nf_log_buf_add(m, "TYPE=%u CODE=%u ", ich->type, ich->code);
if (ich->type <= NR_ICMP_TYPES &&
required_len[ich->type] &&
skb->len-iphoff-ih->ihl*4 < required_len[ich->type]) {
nf_log_buf_add(m, "INCOMPLETE [%u bytes] ",
skb->len - iphoff - ih->ihl*4);
break;
}
switch (ich->type) {
case ICMP_ECHOREPLY:
case ICMP_ECHO:
nf_log_buf_add(m, "ID=%u SEQ=%u ",
ntohs(ich->un.echo.id),
ntohs(ich->un.echo.sequence));
break;
case ICMP_PARAMETERPROB:
nf_log_buf_add(m, "PARAMETER=%u ",
ntohl(ich->un.gateway) >> 24);
break;
case ICMP_REDIRECT:
nf_log_buf_add(m, "GATEWAY=%pI4 ", &ich->un.gateway);
case ICMP_DEST_UNREACH:
case ICMP_SOURCE_QUENCH:
case ICMP_TIME_EXCEEDED:
if (!iphoff) {
nf_log_buf_add(m, "[");
dump_ipv4_packet(m, info, skb,
iphoff + ih->ihl*4+sizeof(_icmph));
nf_log_buf_add(m, "] ");
}
if (ich->type == ICMP_DEST_UNREACH &&
ich->code == ICMP_FRAG_NEEDED) {
nf_log_buf_add(m, "MTU=%u ",
ntohs(ich->un.frag.mtu));
}
}
break;
}
case IPPROTO_AH: {
struct ip_auth_hdr _ahdr;
const struct ip_auth_hdr *ah;
if (ntohs(ih->frag_off) & IP_OFFSET)
break;
nf_log_buf_add(m, "PROTO=AH ");
ah = skb_header_pointer(skb, iphoff+ih->ihl*4,
sizeof(_ahdr), &_ahdr);
if (ah == NULL) {
nf_log_buf_add(m, "INCOMPLETE [%u bytes] ",
skb->len - iphoff - ih->ihl*4);
break;
}
nf_log_buf_add(m, "SPI=0x%x ", ntohl(ah->spi));
break;
}
case IPPROTO_ESP: {
struct ip_esp_hdr _esph;
const struct ip_esp_hdr *eh;
nf_log_buf_add(m, "PROTO=ESP ");
if (ntohs(ih->frag_off) & IP_OFFSET)
break;
eh = skb_header_pointer(skb, iphoff+ih->ihl*4,
sizeof(_esph), &_esph);
if (eh == NULL) {
nf_log_buf_add(m, "INCOMPLETE [%u bytes] ",
skb->len - iphoff - ih->ihl*4);
break;
}
nf_log_buf_add(m, "SPI=0x%x ", ntohl(eh->spi));
break;
}
default:
nf_log_buf_add(m, "PROTO=%u ", ih->protocol);
}
if ((logflags & NF_LOG_UID) && !iphoff)
nf_log_dump_sk_uid_gid(m, skb->sk);
if (!iphoff && skb->mark)
nf_log_buf_add(m, "MARK=0x%x ", skb->mark);
}
static void dump_ipv4_mac_header(struct nf_log_buf *m,
const struct nf_loginfo *info,
const struct sk_buff *skb)
{
struct net_device *dev = skb->dev;
unsigned int logflags = 0;
if (info->type == NF_LOG_TYPE_LOG)
logflags = info->u.log.logflags;
if (!(logflags & NF_LOG_MACDECODE))
goto fallback;
switch (dev->type) {
case ARPHRD_ETHER:
nf_log_buf_add(m, "MACSRC=%pM MACDST=%pM MACPROTO=%04x ",
eth_hdr(skb)->h_source, eth_hdr(skb)->h_dest,
ntohs(eth_hdr(skb)->h_proto));
return;
default:
break;
}
fallback:
nf_log_buf_add(m, "MAC=");
if (dev->hard_header_len &&
skb->mac_header != skb->network_header) {
const unsigned char *p = skb_mac_header(skb);
unsigned int i;
nf_log_buf_add(m, "%02x", *p++);
for (i = 1; i < dev->hard_header_len; i++, p++)
nf_log_buf_add(m, ":%02x", *p);
}
nf_log_buf_add(m, " ");
}
static void nf_log_ip_packet(struct net *net, u_int8_t pf,
unsigned int hooknum, const struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
const struct nf_loginfo *loginfo,
const char *prefix)
{
struct nf_log_buf *m;
if (!net_eq(net, &init_net))
return;
m = nf_log_buf_open();
if (!loginfo)
loginfo = &default_loginfo;
nf_log_dump_packet_common(m, pf, hooknum, skb, in,
out, loginfo, prefix);
if (in != NULL)
dump_ipv4_mac_header(m, loginfo, skb);
dump_ipv4_packet(m, loginfo, skb, 0);
nf_log_buf_close(m);
}
static int __net_init nf_log_ipv4_net_init(struct net *net)
{
return nf_log_set(net, NFPROTO_IPV4, &nf_ip_logger);
}
static void __net_exit nf_log_ipv4_net_exit(struct net *net)
{
nf_log_unset(net, &nf_ip_logger);
}
static int __init nf_log_ipv4_init(void)
{
int ret;
ret = register_pernet_subsys(&nf_log_ipv4_net_ops);
if (ret < 0)
return ret;
ret = nf_log_register(NFPROTO_IPV4, &nf_ip_logger);
if (ret < 0) {
pr_err("failed to register logger\n");
goto err1;
}
return 0;
err1:
unregister_pernet_subsys(&nf_log_ipv4_net_ops);
return ret;
}
static void __exit nf_log_ipv4_exit(void)
{
unregister_pernet_subsys(&nf_log_ipv4_net_ops);
nf_log_unregister(&nf_ip_logger);
}
