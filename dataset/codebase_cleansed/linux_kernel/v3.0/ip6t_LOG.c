static void dump_packet(struct sbuff *m,
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
sb_add(m, "TRUNCATED");
return;
}
sb_add(m, "SRC=%pI6 DST=%pI6 ", &ih->saddr, &ih->daddr);
sb_add(m, "LEN=%Zu TC=%u HOPLIMIT=%u FLOWLBL=%u ",
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
sb_add(m, "TRUNCATED");
return;
}
if (logflags & IP6T_LOG_IPOPT)
sb_add(m, "OPT ( ");
switch (currenthdr) {
case IPPROTO_FRAGMENT: {
struct frag_hdr _fhdr;
const struct frag_hdr *fh;
sb_add(m, "FRAG:");
fh = skb_header_pointer(skb, ptr, sizeof(_fhdr),
&_fhdr);
if (fh == NULL) {
sb_add(m, "TRUNCATED ");
return;
}
sb_add(m, "%u ", ntohs(fh->frag_off) & 0xFFF8);
if (fh->frag_off & htons(0x0001))
sb_add(m, "INCOMPLETE ");
sb_add(m, "ID:%08x ", ntohl(fh->identification));
if (ntohs(fh->frag_off) & 0xFFF8)
fragment = 1;
hdrlen = 8;
break;
}
case IPPROTO_DSTOPTS:
case IPPROTO_ROUTING:
case IPPROTO_HOPOPTS:
if (fragment) {
if (logflags & IP6T_LOG_IPOPT)
sb_add(m, ")");
return;
}
hdrlen = ipv6_optlen(hp);
break;
case IPPROTO_AH:
if (logflags & IP6T_LOG_IPOPT) {
struct ip_auth_hdr _ahdr;
const struct ip_auth_hdr *ah;
sb_add(m, "AH ");
if (fragment) {
sb_add(m, ")");
return;
}
ah = skb_header_pointer(skb, ptr, sizeof(_ahdr),
&_ahdr);
if (ah == NULL) {
sb_add(m, "INCOMPLETE [%u bytes] )",
skb->len - ptr);
return;
}
sb_add(m, "SPI=0x%x ", ntohl(ah->spi));
}
hdrlen = (hp->hdrlen+2)<<2;
break;
case IPPROTO_ESP:
if (logflags & IP6T_LOG_IPOPT) {
struct ip_esp_hdr _esph;
const struct ip_esp_hdr *eh;
sb_add(m, "ESP ");
if (fragment) {
sb_add(m, ")");
return;
}
eh = skb_header_pointer(skb, ptr, sizeof(_esph),
&_esph);
if (eh == NULL) {
sb_add(m, "INCOMPLETE [%u bytes] )",
skb->len - ptr);
return;
}
sb_add(m, "SPI=0x%x )", ntohl(eh->spi) );
}
return;
default:
sb_add(m, "Unknown Ext Hdr %u", currenthdr);
return;
}
if (logflags & IP6T_LOG_IPOPT)
sb_add(m, ") ");
currenthdr = hp->nexthdr;
ptr += hdrlen;
}
switch (currenthdr) {
case IPPROTO_TCP: {
struct tcphdr _tcph;
const struct tcphdr *th;
sb_add(m, "PROTO=TCP ");
if (fragment)
break;
th = skb_header_pointer(skb, ptr, sizeof(_tcph), &_tcph);
if (th == NULL) {
sb_add(m, "INCOMPLETE [%u bytes] ", skb->len - ptr);
return;
}
sb_add(m, "SPT=%u DPT=%u ",
ntohs(th->source), ntohs(th->dest));
if (logflags & IP6T_LOG_TCPSEQ)
sb_add(m, "SEQ=%u ACK=%u ",
ntohl(th->seq), ntohl(th->ack_seq));
sb_add(m, "WINDOW=%u ", ntohs(th->window));
sb_add(m, "RES=0x%02x ", (u_int8_t)(ntohl(tcp_flag_word(th) & TCP_RESERVED_BITS) >> 22));
if (th->cwr)
sb_add(m, "CWR ");
if (th->ece)
sb_add(m, "ECE ");
if (th->urg)
sb_add(m, "URG ");
if (th->ack)
sb_add(m, "ACK ");
if (th->psh)
sb_add(m, "PSH ");
if (th->rst)
sb_add(m, "RST ");
if (th->syn)
sb_add(m, "SYN ");
if (th->fin)
sb_add(m, "FIN ");
sb_add(m, "URGP=%u ", ntohs(th->urg_ptr));
if ((logflags & IP6T_LOG_TCPOPT) &&
th->doff * 4 > sizeof(struct tcphdr)) {
u_int8_t _opt[60 - sizeof(struct tcphdr)];
const u_int8_t *op;
unsigned int i;
unsigned int optsize = th->doff * 4
- sizeof(struct tcphdr);
op = skb_header_pointer(skb,
ptr + sizeof(struct tcphdr),
optsize, _opt);
if (op == NULL) {
sb_add(m, "OPT (TRUNCATED)");
return;
}
sb_add(m, "OPT (");
for (i =0; i < optsize; i++)
sb_add(m, "%02X", op[i]);
sb_add(m, ") ");
}
break;
}
case IPPROTO_UDP:
case IPPROTO_UDPLITE: {
struct udphdr _udph;
const struct udphdr *uh;
if (currenthdr == IPPROTO_UDP)
sb_add(m, "PROTO=UDP " );
else
sb_add(m, "PROTO=UDPLITE ");
if (fragment)
break;
uh = skb_header_pointer(skb, ptr, sizeof(_udph), &_udph);
if (uh == NULL) {
sb_add(m, "INCOMPLETE [%u bytes] ", skb->len - ptr);
return;
}
sb_add(m, "SPT=%u DPT=%u LEN=%u ",
ntohs(uh->source), ntohs(uh->dest),
ntohs(uh->len));
break;
}
case IPPROTO_ICMPV6: {
struct icmp6hdr _icmp6h;
const struct icmp6hdr *ic;
sb_add(m, "PROTO=ICMPv6 ");
if (fragment)
break;
ic = skb_header_pointer(skb, ptr, sizeof(_icmp6h), &_icmp6h);
if (ic == NULL) {
sb_add(m, "INCOMPLETE [%u bytes] ", skb->len - ptr);
return;
}
sb_add(m, "TYPE=%u CODE=%u ", ic->icmp6_type, ic->icmp6_code);
switch (ic->icmp6_type) {
case ICMPV6_ECHO_REQUEST:
case ICMPV6_ECHO_REPLY:
sb_add(m, "ID=%u SEQ=%u ",
ntohs(ic->icmp6_identifier),
ntohs(ic->icmp6_sequence));
break;
case ICMPV6_MGM_QUERY:
case ICMPV6_MGM_REPORT:
case ICMPV6_MGM_REDUCTION:
break;
case ICMPV6_PARAMPROB:
sb_add(m, "POINTER=%08x ", ntohl(ic->icmp6_pointer));
case ICMPV6_DEST_UNREACH:
case ICMPV6_PKT_TOOBIG:
case ICMPV6_TIME_EXCEED:
if (recurse) {
sb_add(m, "[");
dump_packet(m, info, skb,
ptr + sizeof(_icmp6h), 0);
sb_add(m, "] ");
}
if (ic->icmp6_type == ICMPV6_PKT_TOOBIG)
sb_add(m, "MTU=%u ", ntohl(ic->icmp6_mtu));
}
break;
}
default:
sb_add(m, "PROTO=%u ", currenthdr);
}
if ((logflags & IP6T_LOG_UID) && recurse && skb->sk) {
read_lock_bh(&skb->sk->sk_callback_lock);
if (skb->sk->sk_socket && skb->sk->sk_socket->file)
sb_add(m, "UID=%u GID=%u ",
skb->sk->sk_socket->file->f_cred->fsuid,
skb->sk->sk_socket->file->f_cred->fsgid);
read_unlock_bh(&skb->sk->sk_callback_lock);
}
if (!recurse && skb->mark)
sb_add(m, "MARK=0x%x ", skb->mark);
}
static void dump_mac_header(struct sbuff *m,
const struct nf_loginfo *info,
const struct sk_buff *skb)
{
struct net_device *dev = skb->dev;
unsigned int logflags = 0;
if (info->type == NF_LOG_TYPE_LOG)
logflags = info->u.log.logflags;
if (!(logflags & IP6T_LOG_MACDECODE))
goto fallback;
switch (dev->type) {
case ARPHRD_ETHER:
sb_add(m, "MACSRC=%pM MACDST=%pM MACPROTO=%04x ",
eth_hdr(skb)->h_source, eth_hdr(skb)->h_dest,
ntohs(eth_hdr(skb)->h_proto));
return;
default:
break;
}
fallback:
sb_add(m, "MAC=");
if (dev->hard_header_len &&
skb->mac_header != skb->network_header) {
const unsigned char *p = skb_mac_header(skb);
unsigned int len = dev->hard_header_len;
unsigned int i;
if (dev->type == ARPHRD_SIT &&
(p -= ETH_HLEN) < skb->head)
p = NULL;
if (p != NULL) {
sb_add(m, "%02x", *p++);
for (i = 1; i < len; i++)
sb_add(m, ":%02x", *p++);
}
sb_add(m, " ");
if (dev->type == ARPHRD_SIT) {
const struct iphdr *iph =
(struct iphdr *)skb_mac_header(skb);
sb_add(m, "TUNNEL=%pI4->%pI4 ", &iph->saddr, &iph->daddr);
}
} else
sb_add(m, " ");
}
static void
ip6t_log_packet(u_int8_t pf,
unsigned int hooknum,
const struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
const struct nf_loginfo *loginfo,
const char *prefix)
{
struct sbuff *m = sb_open();
if (!loginfo)
loginfo = &default_loginfo;
sb_add(m, "<%d>%sIN=%s OUT=%s ", loginfo->u.log.level,
prefix,
in ? in->name : "",
out ? out->name : "");
if (in != NULL)
dump_mac_header(m, loginfo, skb);
dump_packet(m, loginfo, skb, skb_network_offset(skb), 1);
sb_close(m);
}
static unsigned int
log_tg6(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct ip6t_log_info *loginfo = par->targinfo;
struct nf_loginfo li;
li.type = NF_LOG_TYPE_LOG;
li.u.log.level = loginfo->level;
li.u.log.logflags = loginfo->logflags;
ip6t_log_packet(NFPROTO_IPV6, par->hooknum, skb, par->in, par->out,
&li, loginfo->prefix);
return XT_CONTINUE;
}
static int log_tg6_check(const struct xt_tgchk_param *par)
{
const struct ip6t_log_info *loginfo = par->targinfo;
if (loginfo->level >= 8) {
pr_debug("level %u >= 8\n", loginfo->level);
return -EINVAL;
}
if (loginfo->prefix[sizeof(loginfo->prefix)-1] != '\0') {
pr_debug("prefix not null-terminated\n");
return -EINVAL;
}
return 0;
}
static int __init log_tg6_init(void)
{
int ret;
ret = xt_register_target(&log_tg6_reg);
if (ret < 0)
return ret;
nf_log_register(NFPROTO_IPV6, &ip6t_logger);
return 0;
}
static void __exit log_tg6_exit(void)
{
nf_log_unregister(&ip6t_logger);
xt_unregister_target(&log_tg6_reg);
}
