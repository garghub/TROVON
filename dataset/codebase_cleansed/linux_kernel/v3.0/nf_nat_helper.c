static inline void
adjust_tcp_sequence(u32 seq,
int sizediff,
struct nf_conn *ct,
enum ip_conntrack_info ctinfo)
{
enum ip_conntrack_dir dir = CTINFO2DIR(ctinfo);
struct nf_conn_nat *nat = nfct_nat(ct);
struct nf_nat_seq *this_way = &nat->seq[dir];
pr_debug("adjust_tcp_sequence: seq = %u, sizediff = %d\n",
seq, sizediff);
pr_debug("adjust_tcp_sequence: Seq_offset before: ");
DUMP_OFFSET(this_way);
spin_lock_bh(&nf_nat_seqofs_lock);
if (this_way->offset_before == this_way->offset_after ||
before(this_way->correction_pos, seq)) {
this_way->correction_pos = seq;
this_way->offset_before = this_way->offset_after;
this_way->offset_after += sizediff;
}
spin_unlock_bh(&nf_nat_seqofs_lock);
pr_debug("adjust_tcp_sequence: Seq_offset after: ");
DUMP_OFFSET(this_way);
}
s16 nf_nat_get_offset(const struct nf_conn *ct,
enum ip_conntrack_dir dir,
u32 seq)
{
struct nf_conn_nat *nat = nfct_nat(ct);
struct nf_nat_seq *this_way;
s16 offset;
if (!nat)
return 0;
this_way = &nat->seq[dir];
spin_lock_bh(&nf_nat_seqofs_lock);
offset = after(seq, this_way->correction_pos)
? this_way->offset_after : this_way->offset_before;
spin_unlock_bh(&nf_nat_seqofs_lock);
return offset;
}
static void mangle_contents(struct sk_buff *skb,
unsigned int dataoff,
unsigned int match_offset,
unsigned int match_len,
const char *rep_buffer,
unsigned int rep_len)
{
unsigned char *data;
BUG_ON(skb_is_nonlinear(skb));
data = skb_network_header(skb) + dataoff;
memmove(data + match_offset + rep_len,
data + match_offset + match_len,
skb->tail - (skb->network_header + dataoff +
match_offset + match_len));
memcpy(data + match_offset, rep_buffer, rep_len);
if (rep_len > match_len) {
pr_debug("nf_nat_mangle_packet: Extending packet by "
"%u from %u bytes\n", rep_len - match_len, skb->len);
skb_put(skb, rep_len - match_len);
} else {
pr_debug("nf_nat_mangle_packet: Shrinking packet from "
"%u from %u bytes\n", match_len - rep_len, skb->len);
__skb_trim(skb, skb->len + rep_len - match_len);
}
ip_hdr(skb)->tot_len = htons(skb->len);
ip_send_check(ip_hdr(skb));
}
static int enlarge_skb(struct sk_buff *skb, unsigned int extra)
{
if (skb->len + extra > 65535)
return 0;
if (pskb_expand_head(skb, 0, extra - skb_tailroom(skb), GFP_ATOMIC))
return 0;
return 1;
}
void nf_nat_set_seq_adjust(struct nf_conn *ct, enum ip_conntrack_info ctinfo,
__be32 seq, s16 off)
{
if (!off)
return;
set_bit(IPS_SEQ_ADJUST_BIT, &ct->status);
adjust_tcp_sequence(ntohl(seq), off, ct, ctinfo);
nf_conntrack_event_cache(IPCT_NATSEQADJ, ct);
}
static void nf_nat_csum(struct sk_buff *skb, const struct iphdr *iph, void *data,
int datalen, __sum16 *check, int oldlen)
{
struct rtable *rt = skb_rtable(skb);
if (skb->ip_summed != CHECKSUM_PARTIAL) {
if (!(rt->rt_flags & RTCF_LOCAL) &&
(!skb->dev || skb->dev->features & NETIF_F_V4_CSUM)) {
skb->ip_summed = CHECKSUM_PARTIAL;
skb->csum_start = skb_headroom(skb) +
skb_network_offset(skb) +
iph->ihl * 4;
skb->csum_offset = (void *)check - data;
*check = ~csum_tcpudp_magic(iph->saddr, iph->daddr,
datalen, iph->protocol, 0);
} else {
*check = 0;
*check = csum_tcpudp_magic(iph->saddr, iph->daddr,
datalen, iph->protocol,
csum_partial(data, datalen,
0));
if (iph->protocol == IPPROTO_UDP && !*check)
*check = CSUM_MANGLED_0;
}
} else
inet_proto_csum_replace2(check, skb,
htons(oldlen), htons(datalen), 1);
}
int __nf_nat_mangle_tcp_packet(struct sk_buff *skb,
struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int match_offset,
unsigned int match_len,
const char *rep_buffer,
unsigned int rep_len, bool adjust)
{
struct iphdr *iph;
struct tcphdr *tcph;
int oldlen, datalen;
if (!skb_make_writable(skb, skb->len))
return 0;
if (rep_len > match_len &&
rep_len - match_len > skb_tailroom(skb) &&
!enlarge_skb(skb, rep_len - match_len))
return 0;
SKB_LINEAR_ASSERT(skb);
iph = ip_hdr(skb);
tcph = (void *)iph + iph->ihl*4;
oldlen = skb->len - iph->ihl*4;
mangle_contents(skb, iph->ihl*4 + tcph->doff*4,
match_offset, match_len, rep_buffer, rep_len);
datalen = skb->len - iph->ihl*4;
nf_nat_csum(skb, iph, tcph, datalen, &tcph->check, oldlen);
if (adjust && rep_len != match_len)
nf_nat_set_seq_adjust(ct, ctinfo, tcph->seq,
(int)rep_len - (int)match_len);
return 1;
}
int
nf_nat_mangle_udp_packet(struct sk_buff *skb,
struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int match_offset,
unsigned int match_len,
const char *rep_buffer,
unsigned int rep_len)
{
struct iphdr *iph;
struct udphdr *udph;
int datalen, oldlen;
iph = ip_hdr(skb);
if (skb->len < iph->ihl*4 + sizeof(*udph) +
match_offset + match_len)
return 0;
if (!skb_make_writable(skb, skb->len))
return 0;
if (rep_len > match_len &&
rep_len - match_len > skb_tailroom(skb) &&
!enlarge_skb(skb, rep_len - match_len))
return 0;
iph = ip_hdr(skb);
udph = (void *)iph + iph->ihl*4;
oldlen = skb->len - iph->ihl*4;
mangle_contents(skb, iph->ihl*4 + sizeof(*udph),
match_offset, match_len, rep_buffer, rep_len);
datalen = skb->len - iph->ihl*4;
udph->len = htons(datalen);
if (!udph->check && skb->ip_summed != CHECKSUM_PARTIAL)
return 1;
nf_nat_csum(skb, iph, udph, datalen, &udph->check, oldlen);
return 1;
}
static void
sack_adjust(struct sk_buff *skb,
struct tcphdr *tcph,
unsigned int sackoff,
unsigned int sackend,
struct nf_nat_seq *natseq)
{
while (sackoff < sackend) {
struct tcp_sack_block_wire *sack;
__be32 new_start_seq, new_end_seq;
sack = (void *)skb->data + sackoff;
if (after(ntohl(sack->start_seq) - natseq->offset_before,
natseq->correction_pos))
new_start_seq = htonl(ntohl(sack->start_seq)
- natseq->offset_after);
else
new_start_seq = htonl(ntohl(sack->start_seq)
- natseq->offset_before);
if (after(ntohl(sack->end_seq) - natseq->offset_before,
natseq->correction_pos))
new_end_seq = htonl(ntohl(sack->end_seq)
- natseq->offset_after);
else
new_end_seq = htonl(ntohl(sack->end_seq)
- natseq->offset_before);
pr_debug("sack_adjust: start_seq: %d->%d, end_seq: %d->%d\n",
ntohl(sack->start_seq), new_start_seq,
ntohl(sack->end_seq), new_end_seq);
inet_proto_csum_replace4(&tcph->check, skb,
sack->start_seq, new_start_seq, 0);
inet_proto_csum_replace4(&tcph->check, skb,
sack->end_seq, new_end_seq, 0);
sack->start_seq = new_start_seq;
sack->end_seq = new_end_seq;
sackoff += sizeof(*sack);
}
}
static inline unsigned int
nf_nat_sack_adjust(struct sk_buff *skb,
struct tcphdr *tcph,
struct nf_conn *ct,
enum ip_conntrack_info ctinfo)
{
unsigned int dir, optoff, optend;
struct nf_conn_nat *nat = nfct_nat(ct);
optoff = ip_hdrlen(skb) + sizeof(struct tcphdr);
optend = ip_hdrlen(skb) + tcph->doff * 4;
if (!skb_make_writable(skb, optend))
return 0;
dir = CTINFO2DIR(ctinfo);
while (optoff < optend) {
unsigned char *op = skb->data + optoff;
switch (op[0]) {
case TCPOPT_EOL:
return 1;
case TCPOPT_NOP:
optoff++;
continue;
default:
if (optoff + 1 == optend ||
optoff + op[1] > optend ||
op[1] < 2)
return 0;
if (op[0] == TCPOPT_SACK &&
op[1] >= 2+TCPOLEN_SACK_PERBLOCK &&
((op[1] - 2) % TCPOLEN_SACK_PERBLOCK) == 0)
sack_adjust(skb, tcph, optoff+2,
optoff+op[1], &nat->seq[!dir]);
optoff += op[1];
}
}
return 1;
}
int
nf_nat_seq_adjust(struct sk_buff *skb,
struct nf_conn *ct,
enum ip_conntrack_info ctinfo)
{
struct tcphdr *tcph;
int dir;
__be32 newseq, newack;
s16 seqoff, ackoff;
struct nf_conn_nat *nat = nfct_nat(ct);
struct nf_nat_seq *this_way, *other_way;
dir = CTINFO2DIR(ctinfo);
this_way = &nat->seq[dir];
other_way = &nat->seq[!dir];
if (!skb_make_writable(skb, ip_hdrlen(skb) + sizeof(*tcph)))
return 0;
tcph = (void *)skb->data + ip_hdrlen(skb);
if (after(ntohl(tcph->seq), this_way->correction_pos))
seqoff = this_way->offset_after;
else
seqoff = this_way->offset_before;
if (after(ntohl(tcph->ack_seq) - other_way->offset_before,
other_way->correction_pos))
ackoff = other_way->offset_after;
else
ackoff = other_way->offset_before;
newseq = htonl(ntohl(tcph->seq) + seqoff);
newack = htonl(ntohl(tcph->ack_seq) - ackoff);
inet_proto_csum_replace4(&tcph->check, skb, tcph->seq, newseq, 0);
inet_proto_csum_replace4(&tcph->check, skb, tcph->ack_seq, newack, 0);
pr_debug("Adjusting sequence number from %u->%u, ack from %u->%u\n",
ntohl(tcph->seq), ntohl(newseq), ntohl(tcph->ack_seq),
ntohl(newack));
tcph->seq = newseq;
tcph->ack_seq = newack;
return nf_nat_sack_adjust(skb, tcph, ct, ctinfo);
}
void nf_nat_follow_master(struct nf_conn *ct,
struct nf_conntrack_expect *exp)
{
struct nf_nat_range range;
BUG_ON(ct->status & IPS_NAT_DONE_MASK);
range.flags = IP_NAT_RANGE_MAP_IPS;
range.min_ip = range.max_ip
= ct->master->tuplehash[!exp->dir].tuple.dst.u3.ip;
nf_nat_setup_info(ct, &range, IP_NAT_MANIP_SRC);
range.flags = (IP_NAT_RANGE_MAP_IPS | IP_NAT_RANGE_PROTO_SPECIFIED);
range.min = range.max = exp->saved_proto;
range.min_ip = range.max_ip
= ct->master->tuplehash[!exp->dir].tuple.src.u3.ip;
nf_nat_setup_info(ct, &range, IP_NAT_MANIP_DST);
}
