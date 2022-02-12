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
skb_tail_pointer(skb) - (skb_network_header(skb) + dataoff +
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
if (nf_ct_l3num((struct nf_conn *)skb_nfct(skb)) == NFPROTO_IPV4) {
ip_hdr(skb)->tot_len = htons(skb->len);
ip_send_check(ip_hdr(skb));
} else
ipv6_hdr(skb)->payload_len =
htons(skb->len - sizeof(struct ipv6hdr));
}
static int enlarge_skb(struct sk_buff *skb, unsigned int extra)
{
if (skb->len + extra > 65535)
return 0;
if (pskb_expand_head(skb, 0, extra - skb_tailroom(skb), GFP_ATOMIC))
return 0;
return 1;
}
int __nf_nat_mangle_tcp_packet(struct sk_buff *skb,
struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned int match_offset,
unsigned int match_len,
const char *rep_buffer,
unsigned int rep_len, bool adjust)
{
const struct nf_nat_l3proto *l3proto;
struct tcphdr *tcph;
int oldlen, datalen;
if (!skb_make_writable(skb, skb->len))
return 0;
if (rep_len > match_len &&
rep_len - match_len > skb_tailroom(skb) &&
!enlarge_skb(skb, rep_len - match_len))
return 0;
SKB_LINEAR_ASSERT(skb);
tcph = (void *)skb->data + protoff;
oldlen = skb->len - protoff;
mangle_contents(skb, protoff + tcph->doff*4,
match_offset, match_len, rep_buffer, rep_len);
datalen = skb->len - protoff;
l3proto = __nf_nat_l3proto_find(nf_ct_l3num(ct));
l3proto->csum_recalc(skb, IPPROTO_TCP, tcph, &tcph->check,
datalen, oldlen);
if (adjust && rep_len != match_len)
nf_ct_seqadj_set(ct, ctinfo, tcph->seq,
(int)rep_len - (int)match_len);
return 1;
}
int
nf_nat_mangle_udp_packet(struct sk_buff *skb,
struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned int match_offset,
unsigned int match_len,
const char *rep_buffer,
unsigned int rep_len)
{
const struct nf_nat_l3proto *l3proto;
struct udphdr *udph;
int datalen, oldlen;
if (!skb_make_writable(skb, skb->len))
return 0;
if (rep_len > match_len &&
rep_len - match_len > skb_tailroom(skb) &&
!enlarge_skb(skb, rep_len - match_len))
return 0;
udph = (void *)skb->data + protoff;
oldlen = skb->len - protoff;
mangle_contents(skb, protoff + sizeof(*udph),
match_offset, match_len, rep_buffer, rep_len);
datalen = skb->len - protoff;
udph->len = htons(datalen);
if (!udph->check && skb->ip_summed != CHECKSUM_PARTIAL)
return 1;
l3proto = __nf_nat_l3proto_find(nf_ct_l3num(ct));
l3proto->csum_recalc(skb, IPPROTO_UDP, udph, &udph->check,
datalen, oldlen);
return 1;
}
void nf_nat_follow_master(struct nf_conn *ct,
struct nf_conntrack_expect *exp)
{
struct nf_nat_range range;
BUG_ON(ct->status & IPS_NAT_DONE_MASK);
range.flags = NF_NAT_RANGE_MAP_IPS;
range.min_addr = range.max_addr
= ct->master->tuplehash[!exp->dir].tuple.dst.u3;
nf_nat_setup_info(ct, &range, NF_NAT_MANIP_SRC);
range.flags = (NF_NAT_RANGE_MAP_IPS | NF_NAT_RANGE_PROTO_SPECIFIED);
range.min_proto = range.max_proto = exp->saved_proto;
range.min_addr = range.max_addr
= ct->master->tuplehash[!exp->dir].tuple.src.u3;
nf_nat_setup_info(ct, &range, NF_NAT_MANIP_DST);
}
