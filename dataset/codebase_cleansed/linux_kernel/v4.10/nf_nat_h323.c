static int set_addr(struct sk_buff *skb, unsigned int protoff,
unsigned char **data, int dataoff,
unsigned int addroff, __be32 ip, __be16 port)
{
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = nf_ct_get(skb, &ctinfo);
struct {
__be32 ip;
__be16 port;
} __attribute__ ((__packed__)) buf;
const struct tcphdr *th;
struct tcphdr _tcph;
buf.ip = ip;
buf.port = port;
addroff += dataoff;
if (ip_hdr(skb)->protocol == IPPROTO_TCP) {
if (!nf_nat_mangle_tcp_packet(skb, ct, ctinfo,
protoff, addroff, sizeof(buf),
(char *) &buf, sizeof(buf))) {
net_notice_ratelimited("nf_nat_h323: nf_nat_mangle_tcp_packet error\n");
return -1;
}
th = skb_header_pointer(skb, ip_hdrlen(skb),
sizeof(_tcph), &_tcph);
if (th == NULL)
return -1;
*data = skb->data + ip_hdrlen(skb) + th->doff * 4 + dataoff;
} else {
if (!nf_nat_mangle_udp_packet(skb, ct, ctinfo,
protoff, addroff, sizeof(buf),
(char *) &buf, sizeof(buf))) {
net_notice_ratelimited("nf_nat_h323: nf_nat_mangle_udp_packet error\n");
return -1;
}
*data = skb->data + ip_hdrlen(skb) + sizeof(struct udphdr);
}
return 0;
}
static int set_h225_addr(struct sk_buff *skb, unsigned int protoff,
unsigned char **data, int dataoff,
TransportAddress *taddr,
union nf_inet_addr *addr, __be16 port)
{
return set_addr(skb, protoff, data, dataoff, taddr->ipAddress.ip,
addr->ip, port);
}
static int set_h245_addr(struct sk_buff *skb, unsigned protoff,
unsigned char **data, int dataoff,
H245_TransportAddress *taddr,
union nf_inet_addr *addr, __be16 port)
{
return set_addr(skb, protoff, data, dataoff,
taddr->unicastAddress.iPAddress.network,
addr->ip, port);
}
static int set_sig_addr(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff, unsigned char **data,
TransportAddress *taddr, int count)
{
const struct nf_ct_h323_master *info = nfct_help_data(ct);
int dir = CTINFO2DIR(ctinfo);
int i;
__be16 port;
union nf_inet_addr addr;
for (i = 0; i < count; i++) {
if (get_h225_addr(ct, *data, &taddr[i], &addr, &port)) {
if (addr.ip == ct->tuplehash[dir].tuple.src.u3.ip &&
port == info->sig_port[dir]) {
if (i > 0 &&
get_h225_addr(ct, *data, &taddr[0],
&addr, &port) &&
(ntohl(addr.ip) & 0xff000000) == 0x7f000000)
i = 0;
pr_debug("nf_nat_ras: set signal address %pI4:%hu->%pI4:%hu\n",
&addr.ip, port,
&ct->tuplehash[!dir].tuple.dst.u3.ip,
info->sig_port[!dir]);
return set_h225_addr(skb, protoff, data, 0,
&taddr[i],
&ct->tuplehash[!dir].
tuple.dst.u3,
info->sig_port[!dir]);
} else if (addr.ip == ct->tuplehash[dir].tuple.dst.u3.ip &&
port == info->sig_port[dir]) {
pr_debug("nf_nat_ras: set signal address %pI4:%hu->%pI4:%hu\n",
&addr.ip, port,
&ct->tuplehash[!dir].tuple.src.u3.ip,
info->sig_port[!dir]);
return set_h225_addr(skb, protoff, data, 0,
&taddr[i],
&ct->tuplehash[!dir].
tuple.src.u3,
info->sig_port[!dir]);
}
}
}
return 0;
}
static int set_ras_addr(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff, unsigned char **data,
TransportAddress *taddr, int count)
{
int dir = CTINFO2DIR(ctinfo);
int i;
__be16 port;
union nf_inet_addr addr;
for (i = 0; i < count; i++) {
if (get_h225_addr(ct, *data, &taddr[i], &addr, &port) &&
addr.ip == ct->tuplehash[dir].tuple.src.u3.ip &&
port == ct->tuplehash[dir].tuple.src.u.udp.port) {
pr_debug("nf_nat_ras: set rasAddress %pI4:%hu->%pI4:%hu\n",
&addr.ip, ntohs(port),
&ct->tuplehash[!dir].tuple.dst.u3.ip,
ntohs(ct->tuplehash[!dir].tuple.dst.u.udp.port));
return set_h225_addr(skb, protoff, data, 0, &taddr[i],
&ct->tuplehash[!dir].tuple.dst.u3,
ct->tuplehash[!dir].tuple.
dst.u.udp.port);
}
}
return 0;
}
static int nat_rtp_rtcp(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff, unsigned char **data, int dataoff,
H245_TransportAddress *taddr,
__be16 port, __be16 rtp_port,
struct nf_conntrack_expect *rtp_exp,
struct nf_conntrack_expect *rtcp_exp)
{
struct nf_ct_h323_master *info = nfct_help_data(ct);
int dir = CTINFO2DIR(ctinfo);
int i;
u_int16_t nated_port;
rtp_exp->saved_proto.udp.port = rtp_exp->tuple.dst.u.udp.port;
rtp_exp->expectfn = nf_nat_follow_master;
rtp_exp->dir = !dir;
rtcp_exp->saved_proto.udp.port = rtcp_exp->tuple.dst.u.udp.port;
rtcp_exp->expectfn = nf_nat_follow_master;
rtcp_exp->dir = !dir;
for (i = 0; i < H323_RTP_CHANNEL_MAX; i++) {
if (info->rtp_port[i][dir] == rtp_port) {
rtp_exp->tuple.dst.u.udp.port = info->rtp_port[i][dir];
rtcp_exp->tuple.dst.u.udp.port =
htons(ntohs(info->rtp_port[i][dir]) + 1);
break;
} else if (info->rtp_port[i][dir] == 0) {
break;
}
}
if (i >= H323_RTP_CHANNEL_MAX) {
net_notice_ratelimited("nf_nat_h323: out of expectations\n");
return 0;
}
for (nated_port = ntohs(rtp_exp->tuple.dst.u.udp.port);
nated_port != 0; nated_port += 2) {
int ret;
rtp_exp->tuple.dst.u.udp.port = htons(nated_port);
ret = nf_ct_expect_related(rtp_exp);
if (ret == 0) {
rtcp_exp->tuple.dst.u.udp.port =
htons(nated_port + 1);
ret = nf_ct_expect_related(rtcp_exp);
if (ret == 0)
break;
else if (ret == -EBUSY) {
nf_ct_unexpect_related(rtp_exp);
continue;
} else if (ret < 0) {
nf_ct_unexpect_related(rtp_exp);
nated_port = 0;
break;
}
} else if (ret != -EBUSY) {
nated_port = 0;
break;
}
}
if (nated_port == 0) {
net_notice_ratelimited("nf_nat_h323: out of RTP ports\n");
return 0;
}
if (set_h245_addr(skb, protoff, data, dataoff, taddr,
&ct->tuplehash[!dir].tuple.dst.u3,
htons((port & htons(1)) ? nated_port + 1 :
nated_port)) == 0) {
info->rtp_port[i][dir] = rtp_port;
info->rtp_port[i][!dir] = htons(nated_port);
} else {
nf_ct_unexpect_related(rtp_exp);
nf_ct_unexpect_related(rtcp_exp);
return -1;
}
pr_debug("nf_nat_h323: expect RTP %pI4:%hu->%pI4:%hu\n",
&rtp_exp->tuple.src.u3.ip,
ntohs(rtp_exp->tuple.src.u.udp.port),
&rtp_exp->tuple.dst.u3.ip,
ntohs(rtp_exp->tuple.dst.u.udp.port));
pr_debug("nf_nat_h323: expect RTCP %pI4:%hu->%pI4:%hu\n",
&rtcp_exp->tuple.src.u3.ip,
ntohs(rtcp_exp->tuple.src.u.udp.port),
&rtcp_exp->tuple.dst.u3.ip,
ntohs(rtcp_exp->tuple.dst.u.udp.port));
return 0;
}
static int nat_t120(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff, unsigned char **data, int dataoff,
H245_TransportAddress *taddr, __be16 port,
struct nf_conntrack_expect *exp)
{
int dir = CTINFO2DIR(ctinfo);
u_int16_t nated_port = ntohs(port);
exp->saved_proto.tcp.port = exp->tuple.dst.u.tcp.port;
exp->expectfn = nf_nat_follow_master;
exp->dir = !dir;
for (; nated_port != 0; nated_port++) {
int ret;
exp->tuple.dst.u.tcp.port = htons(nated_port);
ret = nf_ct_expect_related(exp);
if (ret == 0)
break;
else if (ret != -EBUSY) {
nated_port = 0;
break;
}
}
if (nated_port == 0) {
net_notice_ratelimited("nf_nat_h323: out of TCP ports\n");
return 0;
}
if (set_h245_addr(skb, protoff, data, dataoff, taddr,
&ct->tuplehash[!dir].tuple.dst.u3,
htons(nated_port)) < 0) {
nf_ct_unexpect_related(exp);
return -1;
}
pr_debug("nf_nat_h323: expect T.120 %pI4:%hu->%pI4:%hu\n",
&exp->tuple.src.u3.ip,
ntohs(exp->tuple.src.u.tcp.port),
&exp->tuple.dst.u3.ip,
ntohs(exp->tuple.dst.u.tcp.port));
return 0;
}
static int nat_h245(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff, unsigned char **data, int dataoff,
TransportAddress *taddr, __be16 port,
struct nf_conntrack_expect *exp)
{
struct nf_ct_h323_master *info = nfct_help_data(ct);
int dir = CTINFO2DIR(ctinfo);
u_int16_t nated_port = ntohs(port);
exp->saved_proto.tcp.port = exp->tuple.dst.u.tcp.port;
exp->expectfn = nf_nat_follow_master;
exp->dir = !dir;
if (info->sig_port[dir] == port)
nated_port = ntohs(info->sig_port[!dir]);
for (; nated_port != 0; nated_port++) {
int ret;
exp->tuple.dst.u.tcp.port = htons(nated_port);
ret = nf_ct_expect_related(exp);
if (ret == 0)
break;
else if (ret != -EBUSY) {
nated_port = 0;
break;
}
}
if (nated_port == 0) {
net_notice_ratelimited("nf_nat_q931: out of TCP ports\n");
return 0;
}
if (set_h225_addr(skb, protoff, data, dataoff, taddr,
&ct->tuplehash[!dir].tuple.dst.u3,
htons(nated_port)) == 0) {
info->sig_port[dir] = port;
info->sig_port[!dir] = htons(nated_port);
} else {
nf_ct_unexpect_related(exp);
return -1;
}
pr_debug("nf_nat_q931: expect H.245 %pI4:%hu->%pI4:%hu\n",
&exp->tuple.src.u3.ip,
ntohs(exp->tuple.src.u.tcp.port),
&exp->tuple.dst.u3.ip,
ntohs(exp->tuple.dst.u.tcp.port));
return 0;
}
static void ip_nat_q931_expect(struct nf_conn *new,
struct nf_conntrack_expect *this)
{
struct nf_nat_range range;
if (this->tuple.src.u3.ip != 0) {
nf_nat_follow_master(new, this);
return;
}
BUG_ON(new->status & IPS_NAT_DONE_MASK);
range.flags = NF_NAT_RANGE_MAP_IPS;
range.min_addr = range.max_addr =
new->tuplehash[!this->dir].tuple.src.u3;
nf_nat_setup_info(new, &range, NF_NAT_MANIP_SRC);
range.flags = (NF_NAT_RANGE_MAP_IPS | NF_NAT_RANGE_PROTO_SPECIFIED);
range.min_proto = range.max_proto = this->saved_proto;
range.min_addr = range.max_addr =
new->master->tuplehash[!this->dir].tuple.src.u3;
nf_nat_setup_info(new, &range, NF_NAT_MANIP_DST);
}
static int nat_q931(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff, unsigned char **data,
TransportAddress *taddr, int idx,
__be16 port, struct nf_conntrack_expect *exp)
{
struct nf_ct_h323_master *info = nfct_help_data(ct);
int dir = CTINFO2DIR(ctinfo);
u_int16_t nated_port = ntohs(port);
union nf_inet_addr addr;
exp->saved_proto.tcp.port = exp->tuple.dst.u.tcp.port;
exp->expectfn = ip_nat_q931_expect;
exp->dir = !dir;
if (info->sig_port[dir] == port)
nated_port = ntohs(info->sig_port[!dir]);
for (; nated_port != 0; nated_port++) {
int ret;
exp->tuple.dst.u.tcp.port = htons(nated_port);
ret = nf_ct_expect_related(exp);
if (ret == 0)
break;
else if (ret != -EBUSY) {
nated_port = 0;
break;
}
}
if (nated_port == 0) {
net_notice_ratelimited("nf_nat_ras: out of TCP ports\n");
return 0;
}
if (set_h225_addr(skb, protoff, data, 0, &taddr[idx],
&ct->tuplehash[!dir].tuple.dst.u3,
htons(nated_port)) == 0) {
info->sig_port[dir] = port;
info->sig_port[!dir] = htons(nated_port);
if (idx > 0 &&
get_h225_addr(ct, *data, &taddr[0], &addr, &port) &&
(ntohl(addr.ip) & 0xff000000) == 0x7f000000) {
set_h225_addr(skb, protoff, data, 0, &taddr[0],
&ct->tuplehash[!dir].tuple.dst.u3,
info->sig_port[!dir]);
}
} else {
nf_ct_unexpect_related(exp);
return -1;
}
pr_debug("nf_nat_ras: expect Q.931 %pI4:%hu->%pI4:%hu\n",
&exp->tuple.src.u3.ip,
ntohs(exp->tuple.src.u.tcp.port),
&exp->tuple.dst.u3.ip,
ntohs(exp->tuple.dst.u.tcp.port));
return 0;
}
static void ip_nat_callforwarding_expect(struct nf_conn *new,
struct nf_conntrack_expect *this)
{
struct nf_nat_range range;
BUG_ON(new->status & IPS_NAT_DONE_MASK);
range.flags = NF_NAT_RANGE_MAP_IPS;
range.min_addr = range.max_addr =
new->tuplehash[!this->dir].tuple.src.u3;
nf_nat_setup_info(new, &range, NF_NAT_MANIP_SRC);
range.flags = (NF_NAT_RANGE_MAP_IPS | NF_NAT_RANGE_PROTO_SPECIFIED);
range.min_proto = range.max_proto = this->saved_proto;
range.min_addr = range.max_addr = this->saved_addr;
nf_nat_setup_info(new, &range, NF_NAT_MANIP_DST);
}
static int nat_callforwarding(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, int dataoff,
TransportAddress *taddr, __be16 port,
struct nf_conntrack_expect *exp)
{
int dir = CTINFO2DIR(ctinfo);
u_int16_t nated_port;
exp->saved_addr = exp->tuple.dst.u3;
exp->tuple.dst.u3.ip = ct->tuplehash[!dir].tuple.dst.u3.ip;
exp->saved_proto.tcp.port = exp->tuple.dst.u.tcp.port;
exp->expectfn = ip_nat_callforwarding_expect;
exp->dir = !dir;
for (nated_port = ntohs(port); nated_port != 0; nated_port++) {
int ret;
exp->tuple.dst.u.tcp.port = htons(nated_port);
ret = nf_ct_expect_related(exp);
if (ret == 0)
break;
else if (ret != -EBUSY) {
nated_port = 0;
break;
}
}
if (nated_port == 0) {
net_notice_ratelimited("nf_nat_q931: out of TCP ports\n");
return 0;
}
if (!set_h225_addr(skb, protoff, data, dataoff, taddr,
&ct->tuplehash[!dir].tuple.dst.u3,
htons(nated_port)) == 0) {
nf_ct_unexpect_related(exp);
return -1;
}
pr_debug("nf_nat_q931: expect Call Forwarding %pI4:%hu->%pI4:%hu\n",
&exp->tuple.src.u3.ip,
ntohs(exp->tuple.src.u.tcp.port),
&exp->tuple.dst.u3.ip,
ntohs(exp->tuple.dst.u.tcp.port));
return 0;
}
static int __init init(void)
{
BUG_ON(set_h245_addr_hook != NULL);
BUG_ON(set_h225_addr_hook != NULL);
BUG_ON(set_sig_addr_hook != NULL);
BUG_ON(set_ras_addr_hook != NULL);
BUG_ON(nat_rtp_rtcp_hook != NULL);
BUG_ON(nat_t120_hook != NULL);
BUG_ON(nat_h245_hook != NULL);
BUG_ON(nat_callforwarding_hook != NULL);
BUG_ON(nat_q931_hook != NULL);
RCU_INIT_POINTER(set_h245_addr_hook, set_h245_addr);
RCU_INIT_POINTER(set_h225_addr_hook, set_h225_addr);
RCU_INIT_POINTER(set_sig_addr_hook, set_sig_addr);
RCU_INIT_POINTER(set_ras_addr_hook, set_ras_addr);
RCU_INIT_POINTER(nat_rtp_rtcp_hook, nat_rtp_rtcp);
RCU_INIT_POINTER(nat_t120_hook, nat_t120);
RCU_INIT_POINTER(nat_h245_hook, nat_h245);
RCU_INIT_POINTER(nat_callforwarding_hook, nat_callforwarding);
RCU_INIT_POINTER(nat_q931_hook, nat_q931);
nf_ct_helper_expectfn_register(&q931_nat);
nf_ct_helper_expectfn_register(&callforwarding_nat);
return 0;
}
static void __exit fini(void)
{
RCU_INIT_POINTER(set_h245_addr_hook, NULL);
RCU_INIT_POINTER(set_h225_addr_hook, NULL);
RCU_INIT_POINTER(set_sig_addr_hook, NULL);
RCU_INIT_POINTER(set_ras_addr_hook, NULL);
RCU_INIT_POINTER(nat_rtp_rtcp_hook, NULL);
RCU_INIT_POINTER(nat_t120_hook, NULL);
RCU_INIT_POINTER(nat_h245_hook, NULL);
RCU_INIT_POINTER(nat_callforwarding_hook, NULL);
RCU_INIT_POINTER(nat_q931_hook, NULL);
nf_ct_helper_expectfn_unregister(&q931_nat);
nf_ct_helper_expectfn_unregister(&callforwarding_nat);
synchronize_rcu();
}
