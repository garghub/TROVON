static void dump_ipv6_packet(struct nf_log_buf *m,
const struct nf_loginfo *info,
const struct sk_buff *skb, unsigned int ip6hoff,
int recurse)
{
u_int8_t currenthdr;
int fragment;
struct ipv6hdr _ip6h;
const struct ipv6hdr *ih;
unsigned int ptr;
unsigned int hdrlen = 0;
unsigned int logflags;
if (info->type == NF_LOG_TYPE_LOG)
logflags = info->u.log.logflags;
else
logflags = NF_LOG_MASK;
ih = skb_header_pointer(skb, ip6hoff, sizeof(_ip6h), &_ip6h);
if (ih == NULL) {
nf_log_buf_add(m, "TRUNCATED");
return;
}
nf_log_buf_add(m, "SRC=%pI6 DST=%pI6 ", &ih->saddr, &ih->daddr);
nf_log_buf_add(m, "LEN=%Zu TC=%u HOPLIMIT=%u FLOWLBL=%u ",
ntohs(ih->payload_len) + sizeof(struct ipv6hdr),
(ntohl(*(__be32 *)ih) & 0x0ff00000) >> 20,
ih->hop_limit,
(ntohl(*(__be32 *)ih) & 0x000fffff));
fragment = 0;
ptr = ip6hoff + sizeof(struct ipv6hdr);
currenthdr = ih->nexthdr;
while (currenthdr != NEXTHDR_NONE && ip6t_ext_hdr(currenthdr)) {
struct ipv6_opt_hdr _hdr;
const struct ipv6_opt_hdr *hp;
hp = skb_header_pointer(skb, ptr, sizeof(_hdr), &_hdr);
if (hp == NULL) {
nf_log_buf_add(m, "TRUNCATED");
return;
}
if (logflags & XT_LOG_IPOPT)
nf_log_buf_add(m, "OPT ( ");
switch (currenthdr) {
case IPPROTO_FRAGMENT: {
struct frag_hdr _fhdr;
const struct frag_hdr *fh;
nf_log_buf_add(m, "FRAG:");
fh = skb_header_pointer(skb, ptr, sizeof(_fhdr),
&_fhdr);
if (fh == NULL) {
nf_log_buf_add(m, "TRUNCATED ");
return;
}
nf_log_buf_add(m, "%u ", ntohs(fh->frag_off) & 0xFFF8);
if (fh->frag_off & htons(0x0001))
nf_log_buf_add(m, "INCOMPLETE ");
nf_log_buf_add(m, "ID:%08x ",
ntohl(fh->identification));
if (ntohs(fh->frag_off) & 0xFFF8)
fragment = 1;
hdrlen = 8;
break;
}
case IPPROTO_DSTOPTS:
case IPPROTO_ROUTING:
case IPPROTO_HOPOPTS:
if (fragment) {
if (logflags & XT_LOG_IPOPT)
nf_log_buf_add(m, ")");
return;
}
hdrlen = ipv6_optlen(hp);
break;
case IPPROTO_AH:
if (logflags & XT_LOG_IPOPT) {
struct ip_auth_hdr _ahdr;
const struct ip_auth_hdr *ah;
nf_log_buf_add(m, "AH ");
if (fragment) {
nf_log_buf_add(m, ")");
return;
}
ah = skb_header_pointer(skb, ptr, sizeof(_ahdr),
&_ahdr);
if (ah == NULL) {
nf_log_buf_add(m, "INCOMPLETE [%u bytes] )",
skb->len - ptr);
return;
}
nf_log_buf_add(m, "SPI=0x%x ", ntohl(ah->spi));
}
hdrlen = (hp->hdrlen+2)<<2;
break;
case IPPROTO_ESP:
if (logflags & XT_LOG_IPOPT) {
struct ip_esp_hdr _esph;
const struct ip_esp_hdr *eh;
nf_log_buf_add(m, "ESP ");
if (fragment) {
nf_log_buf_add(m, ")");
return;
}
eh = skb_header_pointer(skb, ptr, sizeof(_esph),
&_esph);
if (eh == NULL) {
nf_log_buf_add(m, "INCOMPLETE [%u bytes] )",
skb->len - ptr);
return;
}
nf_log_buf_add(m, "SPI=0x%x )",
ntohl(eh->spi));
}
return;
default:
nf_log_buf_add(m, "Unknown Ext Hdr %u", currenthdr);
return;
}
if (logflags & XT_LOG_IPOPT)
nf_log_buf_add(m, ") ");
currenthdr = hp->nexthdr;
ptr += hdrlen;
}
switch (currenthdr) {
case IPPROTO_TCP:
if (nf_log_dump_tcp_header(m, skb, currenthdr, fragment,
ptr, logflags))
return;
break;
case IPPROTO_UDP:
case IPPROTO_UDPLITE:
if (nf_log_dump_udp_header(m, skb, currenthdr, fragment, ptr))
return;
break;
case IPPROTO_ICMPV6: {
struct icmp6hdr _icmp6h;
const struct icmp6hdr *ic;
nf_log_buf_add(m, "PROTO=ICMPv6 ");
if (fragment)
break;
ic = skb_header_pointer(skb, ptr, sizeof(_icmp6h), &_icmp6h);
if (ic == NULL) {
nf_log_buf_add(m, "INCOMPLETE [%u bytes] ",
skb->len - ptr);
return;
}
nf_log_buf_add(m, "TYPE=%u CODE=%u ",
ic->icmp6_type, ic->icmp6_code);
switch (ic->icmp6_type) {
case ICMPV6_ECHO_REQUEST:
case ICMPV6_ECHO_REPLY:
nf_log_buf_add(m, "ID=%u SEQ=%u ",
ntohs(ic->icmp6_identifier),
ntohs(ic->icmp6_sequence));
break;
case ICMPV6_MGM_QUERY:
case ICMPV6_MGM_REPORT:
case ICMPV6_MGM_REDUCTION:
break;
case ICMPV6_PARAMPROB:
nf_log_buf_add(m, "POINTER=%08x ",
ntohl(ic->icmp6_pointer));
case ICMPV6_DEST_UNREACH:
case ICMPV6_PKT_TOOBIG:
case ICMPV6_TIME_EXCEED:
if (recurse) {
nf_log_buf_add(m, "[");
dump_ipv6_packet(m, info, skb,
ptr + sizeof(_icmp6h), 0);
nf_log_buf_add(m, "] ");
}
if (ic->icmp6_type == ICMPV6_PKT_TOOBIG) {
nf_log_buf_add(m, "MTU=%u ",
ntohl(ic->icmp6_mtu));
}
}
break;
}
default:
nf_log_buf_add(m, "PROTO=%u ", currenthdr);
}
if ((logflags & XT_LOG_UID) && recurse)
nf_log_dump_sk_uid_gid(m, skb->sk);
if (recurse && skb->mark)
nf_log_buf_add(m, "MARK=0x%x ", skb->mark);
}
static void dump_ipv6_mac_header(struct nf_log_buf *m,
const struct nf_loginfo *info,
const struct sk_buff *skb)
{
struct net_device *dev = skb->dev;
unsigned int logflags = 0;
if (info->type == NF_LOG_TYPE_LOG)
logflags = info->u.log.logflags;
if (!(logflags & XT_LOG_MACDECODE))
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
unsigned int len = dev->hard_header_len;
unsigned int i;
if (dev->type == ARPHRD_SIT) {
p -= ETH_HLEN;
if (p < skb->head)
p = NULL;
}
if (p != NULL) {
nf_log_buf_add(m, "%02x", *p++);
for (i = 1; i < len; i++)
nf_log_buf_add(m, ":%02x", *p++);
}
nf_log_buf_add(m, " ");
if (dev->type == ARPHRD_SIT) {
const struct iphdr *iph =
(struct iphdr *)skb_mac_header(skb);
nf_log_buf_add(m, "TUNNEL=%pI4->%pI4 ", &iph->saddr,
&iph->daddr);
}
} else {
nf_log_buf_add(m, " ");
}
}
static void nf_log_ip6_packet(struct net *net, u_int8_t pf,
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
nf_log_dump_packet_common(m, pf, hooknum, skb, in, out,
loginfo, prefix);
if (in != NULL)
dump_ipv6_mac_header(m, loginfo, skb);
dump_ipv6_packet(m, loginfo, skb, skb_network_offset(skb), 1);
nf_log_buf_close(m);
}
static int __net_init nf_log_ipv6_net_init(struct net *net)
{
nf_log_set(net, NFPROTO_IPV6, &nf_ip6_logger);
return 0;
}
static void __net_exit nf_log_ipv6_net_exit(struct net *net)
{
nf_log_unset(net, &nf_ip6_logger);
}
static int __init nf_log_ipv6_init(void)
{
int ret;
ret = register_pernet_subsys(&nf_log_ipv6_net_ops);
if (ret < 0)
return ret;
nf_log_register(NFPROTO_IPV6, &nf_ip6_logger);
return 0;
}
static void __exit nf_log_ipv6_exit(void)
{
unregister_pernet_subsys(&nf_log_ipv6_net_ops);
nf_log_unregister(&nf_ip6_logger);
}
