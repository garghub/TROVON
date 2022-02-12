int nf_log_dump_udp_header(struct nf_log_buf *m, const struct sk_buff *skb,
u8 proto, int fragment, unsigned int offset)
{
struct udphdr _udph;
const struct udphdr *uh;
if (proto == IPPROTO_UDP)
nf_log_buf_add(m, "PROTO=UDP ");
else
nf_log_buf_add(m, "PROTO=UDPLITE ");
if (fragment)
goto out;
uh = skb_header_pointer(skb, offset, sizeof(_udph), &_udph);
if (uh == NULL) {
nf_log_buf_add(m, "INCOMPLETE [%u bytes] ", skb->len - offset);
return 1;
}
nf_log_buf_add(m, "SPT=%u DPT=%u LEN=%u ",
ntohs(uh->source), ntohs(uh->dest), ntohs(uh->len));
out:
return 0;
}
int nf_log_dump_tcp_header(struct nf_log_buf *m, const struct sk_buff *skb,
u8 proto, int fragment, unsigned int offset,
unsigned int logflags)
{
struct tcphdr _tcph;
const struct tcphdr *th;
nf_log_buf_add(m, "PROTO=TCP ");
if (fragment)
return 0;
th = skb_header_pointer(skb, offset, sizeof(_tcph), &_tcph);
if (th == NULL) {
nf_log_buf_add(m, "INCOMPLETE [%u bytes] ", skb->len - offset);
return 1;
}
nf_log_buf_add(m, "SPT=%u DPT=%u ",
ntohs(th->source), ntohs(th->dest));
if (logflags & NF_LOG_TCPSEQ) {
nf_log_buf_add(m, "SEQ=%u ACK=%u ",
ntohl(th->seq), ntohl(th->ack_seq));
}
nf_log_buf_add(m, "WINDOW=%u ", ntohs(th->window));
nf_log_buf_add(m, "RES=0x%02x ", (u_int8_t)(ntohl(tcp_flag_word(th) &
TCP_RESERVED_BITS) >> 22));
if (th->cwr)
nf_log_buf_add(m, "CWR ");
if (th->ece)
nf_log_buf_add(m, "ECE ");
if (th->urg)
nf_log_buf_add(m, "URG ");
if (th->ack)
nf_log_buf_add(m, "ACK ");
if (th->psh)
nf_log_buf_add(m, "PSH ");
if (th->rst)
nf_log_buf_add(m, "RST ");
if (th->syn)
nf_log_buf_add(m, "SYN ");
if (th->fin)
nf_log_buf_add(m, "FIN ");
nf_log_buf_add(m, "URGP=%u ", ntohs(th->urg_ptr));
if ((logflags & NF_LOG_TCPOPT) && th->doff*4 > sizeof(struct tcphdr)) {
u_int8_t _opt[60 - sizeof(struct tcphdr)];
const u_int8_t *op;
unsigned int i;
unsigned int optsize = th->doff*4 - sizeof(struct tcphdr);
op = skb_header_pointer(skb, offset + sizeof(struct tcphdr),
optsize, _opt);
if (op == NULL) {
nf_log_buf_add(m, "OPT (TRUNCATED)");
return 1;
}
nf_log_buf_add(m, "OPT (");
for (i = 0; i < optsize; i++)
nf_log_buf_add(m, "%02X", op[i]);
nf_log_buf_add(m, ") ");
}
return 0;
}
void nf_log_dump_sk_uid_gid(struct nf_log_buf *m, struct sock *sk)
{
if (!sk || !sk_fullsock(sk))
return;
read_lock_bh(&sk->sk_callback_lock);
if (sk->sk_socket && sk->sk_socket->file) {
const struct cred *cred = sk->sk_socket->file->f_cred;
nf_log_buf_add(m, "UID=%u GID=%u ",
from_kuid_munged(&init_user_ns, cred->fsuid),
from_kgid_munged(&init_user_ns, cred->fsgid));
}
read_unlock_bh(&sk->sk_callback_lock);
}
void
nf_log_dump_packet_common(struct nf_log_buf *m, u_int8_t pf,
unsigned int hooknum, const struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
const struct nf_loginfo *loginfo, const char *prefix)
{
nf_log_buf_add(m, KERN_SOH "%c%sIN=%s OUT=%s ",
'0' + loginfo->u.log.level, prefix,
in ? in->name : "",
out ? out->name : "");
#if IS_ENABLED(CONFIG_BRIDGE_NETFILTER)
if (skb->nf_bridge) {
const struct net_device *physindev;
const struct net_device *physoutdev;
physindev = nf_bridge_get_physindev(skb);
if (physindev && in != physindev)
nf_log_buf_add(m, "PHYSIN=%s ", physindev->name);
physoutdev = nf_bridge_get_physoutdev(skb);
if (physoutdev && out != physoutdev)
nf_log_buf_add(m, "PHYSOUT=%s ", physoutdev->name);
}
#endif
}
static int __init nf_log_common_init(void)
{
return 0;
}
static void __exit nf_log_common_exit(void) {}
