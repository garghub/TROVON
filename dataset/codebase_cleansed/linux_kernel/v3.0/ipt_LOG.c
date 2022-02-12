static void dump_packet(struct sbuff *m,
const struct nf_loginfo *info,
const struct sk_buff *skb,
unsigned int iphoff)
{
struct iphdr _iph;
const struct iphdr *ih;
unsigned int logflags;
if (info->type == NF_LOG_TYPE_LOG)
logflags = info->u.log.logflags;
else
logflags = NF_LOG_MASK;
ih = skb_header_pointer(skb, iphoff, sizeof(_iph), &_iph);
if (ih == NULL) {
sb_add(m, "TRUNCATED");
return;
}
sb_add(m, "SRC=%pI4 DST=%pI4 ",
&ih->saddr, &ih->daddr);
sb_add(m, "LEN=%u TOS=0x%02X PREC=0x%02X TTL=%u ID=%u ",
ntohs(ih->tot_len), ih->tos & IPTOS_TOS_MASK,
ih->tos & IPTOS_PREC_MASK, ih->ttl, ntohs(ih->id));
if (ntohs(ih->frag_off) & IP_CE)
sb_add(m, "CE ");
if (ntohs(ih->frag_off) & IP_DF)
sb_add(m, "DF ");
if (ntohs(ih->frag_off) & IP_MF)
sb_add(m, "MF ");
if (ntohs(ih->frag_off) & IP_OFFSET)
sb_add(m, "FRAG:%u ", ntohs(ih->frag_off) & IP_OFFSET);
if ((logflags & IPT_LOG_IPOPT) &&
ih->ihl * 4 > sizeof(struct iphdr)) {
const unsigned char *op;
unsigned char _opt[4 * 15 - sizeof(struct iphdr)];
unsigned int i, optsize;
optsize = ih->ihl * 4 - sizeof(struct iphdr);
op = skb_header_pointer(skb, iphoff+sizeof(_iph),
optsize, _opt);
if (op == NULL) {
sb_add(m, "TRUNCATED");
return;
}
sb_add(m, "OPT (");
for (i = 0; i < optsize; i++)
sb_add(m, "%02X", op[i]);
sb_add(m, ") ");
}
switch (ih->protocol) {
case IPPROTO_TCP: {
struct tcphdr _tcph;
const struct tcphdr *th;
sb_add(m, "PROTO=TCP ");
if (ntohs(ih->frag_off) & IP_OFFSET)
break;
th = skb_header_pointer(skb, iphoff + ih->ihl * 4,
sizeof(_tcph), &_tcph);
if (th == NULL) {
sb_add(m, "INCOMPLETE [%u bytes] ",
skb->len - iphoff - ih->ihl*4);
break;
}
sb_add(m, "SPT=%u DPT=%u ",
ntohs(th->source), ntohs(th->dest));
if (logflags & IPT_LOG_TCPSEQ)
sb_add(m, "SEQ=%u ACK=%u ",
ntohl(th->seq), ntohl(th->ack_seq));
sb_add(m, "WINDOW=%u ", ntohs(th->window));
sb_add(m, "RES=0x%02x ", (u8)(ntohl(tcp_flag_word(th) & TCP_RESERVED_BITS) >> 22));
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
if ((logflags & IPT_LOG_TCPOPT) &&
th->doff * 4 > sizeof(struct tcphdr)) {
unsigned char _opt[4 * 15 - sizeof(struct tcphdr)];
const unsigned char *op;
unsigned int i, optsize;
optsize = th->doff * 4 - sizeof(struct tcphdr);
op = skb_header_pointer(skb,
iphoff+ih->ihl*4+sizeof(_tcph),
optsize, _opt);
if (op == NULL) {
sb_add(m, "TRUNCATED");
return;
}
sb_add(m, "OPT (");
for (i = 0; i < optsize; i++)
sb_add(m, "%02X", op[i]);
sb_add(m, ") ");
}
break;
}
case IPPROTO_UDP:
case IPPROTO_UDPLITE: {
struct udphdr _udph;
const struct udphdr *uh;
if (ih->protocol == IPPROTO_UDP)
sb_add(m, "PROTO=UDP " );
else
sb_add(m, "PROTO=UDPLITE ");
if (ntohs(ih->frag_off) & IP_OFFSET)
break;
uh = skb_header_pointer(skb, iphoff+ih->ihl*4,
sizeof(_udph), &_udph);
if (uh == NULL) {
sb_add(m, "INCOMPLETE [%u bytes] ",
skb->len - iphoff - ih->ihl*4);
break;
}
sb_add(m, "SPT=%u DPT=%u LEN=%u ",
ntohs(uh->source), ntohs(uh->dest),
ntohs(uh->len));
break;
}
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
sb_add(m, "PROTO=ICMP ");
if (ntohs(ih->frag_off) & IP_OFFSET)
break;
ich = skb_header_pointer(skb, iphoff + ih->ihl * 4,
sizeof(_icmph), &_icmph);
if (ich == NULL) {
sb_add(m, "INCOMPLETE [%u bytes] ",
skb->len - iphoff - ih->ihl*4);
break;
}
sb_add(m, "TYPE=%u CODE=%u ", ich->type, ich->code);
if (ich->type <= NR_ICMP_TYPES &&
required_len[ich->type] &&
skb->len-iphoff-ih->ihl*4 < required_len[ich->type]) {
sb_add(m, "INCOMPLETE [%u bytes] ",
skb->len - iphoff - ih->ihl*4);
break;
}
switch (ich->type) {
case ICMP_ECHOREPLY:
case ICMP_ECHO:
sb_add(m, "ID=%u SEQ=%u ",
ntohs(ich->un.echo.id),
ntohs(ich->un.echo.sequence));
break;
case ICMP_PARAMETERPROB:
sb_add(m, "PARAMETER=%u ",
ntohl(ich->un.gateway) >> 24);
break;
case ICMP_REDIRECT:
sb_add(m, "GATEWAY=%pI4 ", &ich->un.gateway);
case ICMP_DEST_UNREACH:
case ICMP_SOURCE_QUENCH:
case ICMP_TIME_EXCEEDED:
if (!iphoff) {
sb_add(m, "[");
dump_packet(m, info, skb,
iphoff + ih->ihl*4+sizeof(_icmph));
sb_add(m, "] ");
}
if (ich->type == ICMP_DEST_UNREACH &&
ich->code == ICMP_FRAG_NEEDED)
sb_add(m, "MTU=%u ", ntohs(ich->un.frag.mtu));
}
break;
}
case IPPROTO_AH: {
struct ip_auth_hdr _ahdr;
const struct ip_auth_hdr *ah;
if (ntohs(ih->frag_off) & IP_OFFSET)
break;
sb_add(m, "PROTO=AH ");
ah = skb_header_pointer(skb, iphoff+ih->ihl*4,
sizeof(_ahdr), &_ahdr);
if (ah == NULL) {
sb_add(m, "INCOMPLETE [%u bytes] ",
skb->len - iphoff - ih->ihl*4);
break;
}
sb_add(m, "SPI=0x%x ", ntohl(ah->spi));
break;
}
case IPPROTO_ESP: {
struct ip_esp_hdr _esph;
const struct ip_esp_hdr *eh;
sb_add(m, "PROTO=ESP ");
if (ntohs(ih->frag_off) & IP_OFFSET)
break;
eh = skb_header_pointer(skb, iphoff+ih->ihl*4,
sizeof(_esph), &_esph);
if (eh == NULL) {
sb_add(m, "INCOMPLETE [%u bytes] ",
skb->len - iphoff - ih->ihl*4);
break;
}
sb_add(m, "SPI=0x%x ", ntohl(eh->spi));
break;
}
default:
sb_add(m, "PROTO=%u ", ih->protocol);
}
if ((logflags & IPT_LOG_UID) && !iphoff && skb->sk) {
read_lock_bh(&skb->sk->sk_callback_lock);
if (skb->sk->sk_socket && skb->sk->sk_socket->file)
sb_add(m, "UID=%u GID=%u ",
skb->sk->sk_socket->file->f_cred->fsuid,
skb->sk->sk_socket->file->f_cred->fsgid);
read_unlock_bh(&skb->sk->sk_callback_lock);
}
if (!iphoff && skb->mark)
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
if (!(logflags & IPT_LOG_MACDECODE))
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
unsigned int i;
sb_add(m, "%02x", *p++);
for (i = 1; i < dev->hard_header_len; i++, p++)
sb_add(m, ":%02x", *p);
}
sb_add(m, " ");
}
static void
ipt_log_packet(u_int8_t pf,
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
#ifdef CONFIG_BRIDGE_NETFILTER
if (skb->nf_bridge) {
const struct net_device *physindev;
const struct net_device *physoutdev;
physindev = skb->nf_bridge->physindev;
if (physindev && in != physindev)
sb_add(m, "PHYSIN=%s ", physindev->name);
physoutdev = skb->nf_bridge->physoutdev;
if (physoutdev && out != physoutdev)
sb_add(m, "PHYSOUT=%s ", physoutdev->name);
}
#endif
if (in != NULL)
dump_mac_header(m, loginfo, skb);
dump_packet(m, loginfo, skb, 0);
sb_close(m);
}
static unsigned int
log_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct ipt_log_info *loginfo = par->targinfo;
struct nf_loginfo li;
li.type = NF_LOG_TYPE_LOG;
li.u.log.level = loginfo->level;
li.u.log.logflags = loginfo->logflags;
ipt_log_packet(NFPROTO_IPV4, par->hooknum, skb, par->in, par->out, &li,
loginfo->prefix);
return XT_CONTINUE;
}
static int log_tg_check(const struct xt_tgchk_param *par)
{
const struct ipt_log_info *loginfo = par->targinfo;
if (loginfo->level >= 8) {
pr_debug("level %u >= 8\n", loginfo->level);
return -EINVAL;
}
if (loginfo->prefix[sizeof(loginfo->prefix)-1] != '\0') {
pr_debug("prefix is not null-terminated\n");
return -EINVAL;
}
return 0;
}
static int __init log_tg_init(void)
{
int ret;
ret = xt_register_target(&log_tg_reg);
if (ret < 0)
return ret;
nf_log_register(NFPROTO_IPV4, &ipt_log_logger);
return 0;
}
static void __exit log_tg_exit(void)
{
nf_log_unregister(&ipt_log_logger);
xt_unregister_target(&log_tg_reg);
}
