static int get_tpkt_data(struct sk_buff *skb, unsigned int protoff,
struct nf_conn *ct, enum ip_conntrack_info ctinfo,
unsigned char **data, int *datalen, int *dataoff)
{
struct nf_ct_h323_master *info = nfct_help_data(ct);
int dir = CTINFO2DIR(ctinfo);
const struct tcphdr *th;
struct tcphdr _tcph;
int tcpdatalen;
int tcpdataoff;
unsigned char *tpkt;
int tpktlen;
int tpktoff;
th = skb_header_pointer(skb, protoff, sizeof(_tcph), &_tcph);
if (th == NULL)
return 0;
tcpdataoff = protoff + th->doff * 4;
tcpdatalen = skb->len - tcpdataoff;
if (tcpdatalen <= 0)
goto clear_out;
if (*data == NULL) {
tpkt = skb_header_pointer(skb, tcpdataoff, tcpdatalen,
h323_buffer);
BUG_ON(tpkt == NULL);
if (tcpdatalen < 4 || tpkt[0] != 0x03 || tpkt[1] != 0) {
if (info->tpkt_len[dir] > 0) {
pr_debug("nf_ct_h323: previous packet "
"indicated separate TPKT data of %hu "
"bytes\n", info->tpkt_len[dir]);
if (info->tpkt_len[dir] <= tcpdatalen) {
*data = tpkt;
*datalen = info->tpkt_len[dir];
*dataoff = 0;
goto out;
}
pr_debug("nf_ct_h323: fragmented TPKT\n");
goto clear_out;
}
return 0;
}
tpktoff = 0;
} else {
tpktoff = *dataoff + *datalen;
tcpdatalen -= tpktoff;
if (tcpdatalen <= 4)
goto clear_out;
tpkt = *data + *datalen;
if (tpkt[0] != 0x03 || tpkt[1] != 0)
goto clear_out;
}
tpktlen = tpkt[2] * 256 + tpkt[3];
if (tpktlen < 4)
goto clear_out;
if (tpktlen > tcpdatalen) {
if (tcpdatalen == 4) {
pr_debug("nf_ct_h323: separate TPKT header indicates "
"there will be TPKT data of %hu bytes\n",
tpktlen - 4);
info->tpkt_len[dir] = tpktlen - 4;
return 0;
}
pr_debug("nf_ct_h323: incomplete TPKT (fragmented?)\n");
goto clear_out;
}
*data = tpkt + 4;
*datalen = tpktlen - 4;
*dataoff = tpktoff + 4;
out:
info->tpkt_len[dir] = 0;
return 1;
clear_out:
info->tpkt_len[dir] = 0;
return 0;
}
static int get_h245_addr(struct nf_conn *ct, const unsigned char *data,
H245_TransportAddress *taddr,
union nf_inet_addr *addr, __be16 *port)
{
const unsigned char *p;
int len;
if (taddr->choice != eH245_TransportAddress_unicastAddress)
return 0;
switch (taddr->unicastAddress.choice) {
case eUnicastAddress_iPAddress:
if (nf_ct_l3num(ct) != AF_INET)
return 0;
p = data + taddr->unicastAddress.iPAddress.network;
len = 4;
break;
case eUnicastAddress_iP6Address:
if (nf_ct_l3num(ct) != AF_INET6)
return 0;
p = data + taddr->unicastAddress.iP6Address.network;
len = 16;
break;
default:
return 0;
}
memcpy(addr, p, len);
memset((void *)addr + len, 0, sizeof(*addr) - len);
memcpy(port, p + len, sizeof(__be16));
return 1;
}
static int expect_rtp_rtcp(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, int dataoff,
H245_TransportAddress *taddr)
{
int dir = CTINFO2DIR(ctinfo);
int ret = 0;
__be16 port;
__be16 rtp_port, rtcp_port;
union nf_inet_addr addr;
struct nf_conntrack_expect *rtp_exp;
struct nf_conntrack_expect *rtcp_exp;
typeof(nat_rtp_rtcp_hook) nat_rtp_rtcp;
if (!get_h245_addr(ct, *data, taddr, &addr, &port) ||
memcmp(&addr, &ct->tuplehash[dir].tuple.src.u3, sizeof(addr)) ||
port == 0)
return 0;
rtp_port = port & ~htons(1);
rtcp_port = port | htons(1);
if ((rtp_exp = nf_ct_expect_alloc(ct)) == NULL)
return -1;
nf_ct_expect_init(rtp_exp, NF_CT_EXPECT_CLASS_DEFAULT, nf_ct_l3num(ct),
&ct->tuplehash[!dir].tuple.src.u3,
&ct->tuplehash[!dir].tuple.dst.u3,
IPPROTO_UDP, NULL, &rtp_port);
if ((rtcp_exp = nf_ct_expect_alloc(ct)) == NULL) {
nf_ct_expect_put(rtp_exp);
return -1;
}
nf_ct_expect_init(rtcp_exp, NF_CT_EXPECT_CLASS_DEFAULT, nf_ct_l3num(ct),
&ct->tuplehash[!dir].tuple.src.u3,
&ct->tuplehash[!dir].tuple.dst.u3,
IPPROTO_UDP, NULL, &rtcp_port);
if (memcmp(&ct->tuplehash[dir].tuple.src.u3,
&ct->tuplehash[!dir].tuple.dst.u3,
sizeof(ct->tuplehash[dir].tuple.src.u3)) &&
(nat_rtp_rtcp = rcu_dereference(nat_rtp_rtcp_hook)) &&
nf_ct_l3num(ct) == NFPROTO_IPV4 &&
ct->status & IPS_NAT_MASK) {
ret = nat_rtp_rtcp(skb, ct, ctinfo, protoff, data, dataoff,
taddr, port, rtp_port, rtp_exp, rtcp_exp);
} else {
if (nf_ct_expect_related(rtp_exp) == 0) {
if (nf_ct_expect_related(rtcp_exp) == 0) {
pr_debug("nf_ct_h323: expect RTP ");
nf_ct_dump_tuple(&rtp_exp->tuple);
pr_debug("nf_ct_h323: expect RTCP ");
nf_ct_dump_tuple(&rtcp_exp->tuple);
} else {
nf_ct_unexpect_related(rtp_exp);
ret = -1;
}
} else
ret = -1;
}
nf_ct_expect_put(rtp_exp);
nf_ct_expect_put(rtcp_exp);
return ret;
}
static int expect_t120(struct sk_buff *skb,
struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, int dataoff,
H245_TransportAddress *taddr)
{
int dir = CTINFO2DIR(ctinfo);
int ret = 0;
__be16 port;
union nf_inet_addr addr;
struct nf_conntrack_expect *exp;
typeof(nat_t120_hook) nat_t120;
if (!get_h245_addr(ct, *data, taddr, &addr, &port) ||
memcmp(&addr, &ct->tuplehash[dir].tuple.src.u3, sizeof(addr)) ||
port == 0)
return 0;
if ((exp = nf_ct_expect_alloc(ct)) == NULL)
return -1;
nf_ct_expect_init(exp, NF_CT_EXPECT_CLASS_DEFAULT, nf_ct_l3num(ct),
&ct->tuplehash[!dir].tuple.src.u3,
&ct->tuplehash[!dir].tuple.dst.u3,
IPPROTO_TCP, NULL, &port);
exp->flags = NF_CT_EXPECT_PERMANENT;
if (memcmp(&ct->tuplehash[dir].tuple.src.u3,
&ct->tuplehash[!dir].tuple.dst.u3,
sizeof(ct->tuplehash[dir].tuple.src.u3)) &&
(nat_t120 = rcu_dereference(nat_t120_hook)) &&
nf_ct_l3num(ct) == NFPROTO_IPV4 &&
ct->status & IPS_NAT_MASK) {
ret = nat_t120(skb, ct, ctinfo, protoff, data, dataoff, taddr,
port, exp);
} else {
if (nf_ct_expect_related(exp) == 0) {
pr_debug("nf_ct_h323: expect T.120 ");
nf_ct_dump_tuple(&exp->tuple);
} else
ret = -1;
}
nf_ct_expect_put(exp);
return ret;
}
static int process_h245_channel(struct sk_buff *skb,
struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, int dataoff,
H2250LogicalChannelParameters *channel)
{
int ret;
if (channel->options & eH2250LogicalChannelParameters_mediaChannel) {
ret = expect_rtp_rtcp(skb, ct, ctinfo, protoff, data, dataoff,
&channel->mediaChannel);
if (ret < 0)
return -1;
}
if (channel->
options & eH2250LogicalChannelParameters_mediaControlChannel) {
ret = expect_rtp_rtcp(skb, ct, ctinfo, protoff, data, dataoff,
&channel->mediaControlChannel);
if (ret < 0)
return -1;
}
return 0;
}
static int process_olc(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, int dataoff,
OpenLogicalChannel *olc)
{
int ret;
pr_debug("nf_ct_h323: OpenLogicalChannel\n");
if (olc->forwardLogicalChannelParameters.multiplexParameters.choice ==
eOpenLogicalChannel_forwardLogicalChannelParameters_multiplexParameters_h2250LogicalChannelParameters)
{
ret = process_h245_channel(skb, ct, ctinfo,
protoff, data, dataoff,
&olc->
forwardLogicalChannelParameters.
multiplexParameters.
h2250LogicalChannelParameters);
if (ret < 0)
return -1;
}
if ((olc->options &
eOpenLogicalChannel_reverseLogicalChannelParameters) &&
(olc->reverseLogicalChannelParameters.options &
eOpenLogicalChannel_reverseLogicalChannelParameters_multiplexParameters)
&& (olc->reverseLogicalChannelParameters.multiplexParameters.
choice ==
eOpenLogicalChannel_reverseLogicalChannelParameters_multiplexParameters_h2250LogicalChannelParameters))
{
ret =
process_h245_channel(skb, ct, ctinfo,
protoff, data, dataoff,
&olc->
reverseLogicalChannelParameters.
multiplexParameters.
h2250LogicalChannelParameters);
if (ret < 0)
return -1;
}
if ((olc->options & eOpenLogicalChannel_separateStack) &&
olc->forwardLogicalChannelParameters.dataType.choice ==
eDataType_data &&
olc->forwardLogicalChannelParameters.dataType.data.application.
choice == eDataApplicationCapability_application_t120 &&
olc->forwardLogicalChannelParameters.dataType.data.application.
t120.choice == eDataProtocolCapability_separateLANStack &&
olc->separateStack.networkAddress.choice ==
eNetworkAccessParameters_networkAddress_localAreaAddress) {
ret = expect_t120(skb, ct, ctinfo, protoff, data, dataoff,
&olc->separateStack.networkAddress.
localAreaAddress);
if (ret < 0)
return -1;
}
return 0;
}
static int process_olca(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff, unsigned char **data, int dataoff,
OpenLogicalChannelAck *olca)
{
H2250LogicalChannelAckParameters *ack;
int ret;
pr_debug("nf_ct_h323: OpenLogicalChannelAck\n");
if ((olca->options &
eOpenLogicalChannelAck_reverseLogicalChannelParameters) &&
(olca->reverseLogicalChannelParameters.options &
eOpenLogicalChannelAck_reverseLogicalChannelParameters_multiplexParameters)
&& (olca->reverseLogicalChannelParameters.multiplexParameters.
choice ==
eOpenLogicalChannelAck_reverseLogicalChannelParameters_multiplexParameters_h2250LogicalChannelParameters))
{
ret = process_h245_channel(skb, ct, ctinfo,
protoff, data, dataoff,
&olca->
reverseLogicalChannelParameters.
multiplexParameters.
h2250LogicalChannelParameters);
if (ret < 0)
return -1;
}
if ((olca->options &
eOpenLogicalChannelAck_forwardMultiplexAckParameters) &&
(olca->forwardMultiplexAckParameters.choice ==
eOpenLogicalChannelAck_forwardMultiplexAckParameters_h2250LogicalChannelAckParameters))
{
ack = &olca->forwardMultiplexAckParameters.
h2250LogicalChannelAckParameters;
if (ack->options &
eH2250LogicalChannelAckParameters_mediaChannel) {
ret = expect_rtp_rtcp(skb, ct, ctinfo,
protoff, data, dataoff,
&ack->mediaChannel);
if (ret < 0)
return -1;
}
if (ack->options &
eH2250LogicalChannelAckParameters_mediaControlChannel) {
ret = expect_rtp_rtcp(skb, ct, ctinfo,
protoff, data, dataoff,
&ack->mediaControlChannel);
if (ret < 0)
return -1;
}
}
if ((olca->options & eOpenLogicalChannelAck_separateStack) &&
olca->separateStack.networkAddress.choice ==
eNetworkAccessParameters_networkAddress_localAreaAddress) {
ret = expect_t120(skb, ct, ctinfo, protoff, data, dataoff,
&olca->separateStack.networkAddress.
localAreaAddress);
if (ret < 0)
return -1;
}
return 0;
}
static int process_h245(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff, unsigned char **data, int dataoff,
MultimediaSystemControlMessage *mscm)
{
switch (mscm->choice) {
case eMultimediaSystemControlMessage_request:
if (mscm->request.choice ==
eRequestMessage_openLogicalChannel) {
return process_olc(skb, ct, ctinfo,
protoff, data, dataoff,
&mscm->request.openLogicalChannel);
}
pr_debug("nf_ct_h323: H.245 Request %d\n",
mscm->request.choice);
break;
case eMultimediaSystemControlMessage_response:
if (mscm->response.choice ==
eResponseMessage_openLogicalChannelAck) {
return process_olca(skb, ct, ctinfo,
protoff, data, dataoff,
&mscm->response.
openLogicalChannelAck);
}
pr_debug("nf_ct_h323: H.245 Response %d\n",
mscm->response.choice);
break;
default:
pr_debug("nf_ct_h323: H.245 signal %d\n", mscm->choice);
break;
}
return 0;
}
static int h245_help(struct sk_buff *skb, unsigned int protoff,
struct nf_conn *ct, enum ip_conntrack_info ctinfo)
{
static MultimediaSystemControlMessage mscm;
unsigned char *data = NULL;
int datalen;
int dataoff;
int ret;
if (ctinfo != IP_CT_ESTABLISHED && ctinfo != IP_CT_ESTABLISHED_REPLY)
return NF_ACCEPT;
pr_debug("nf_ct_h245: skblen = %u\n", skb->len);
spin_lock_bh(&nf_h323_lock);
while (get_tpkt_data(skb, protoff, ct, ctinfo,
&data, &datalen, &dataoff)) {
pr_debug("nf_ct_h245: TPKT len=%d ", datalen);
nf_ct_dump_tuple(&ct->tuplehash[CTINFO2DIR(ctinfo)].tuple);
ret = DecodeMultimediaSystemControlMessage(data, datalen,
&mscm);
if (ret < 0) {
pr_debug("nf_ct_h245: decoding error: %s\n",
ret == H323_ERROR_BOUND ?
"out of bound" : "out of range");
break;
}
if (process_h245(skb, ct, ctinfo, protoff,
&data, dataoff, &mscm) < 0)
goto drop;
}
spin_unlock_bh(&nf_h323_lock);
return NF_ACCEPT;
drop:
spin_unlock_bh(&nf_h323_lock);
nf_ct_helper_log(skb, ct, "cannot process H.245 message");
return NF_DROP;
}
int get_h225_addr(struct nf_conn *ct, unsigned char *data,
TransportAddress *taddr,
union nf_inet_addr *addr, __be16 *port)
{
const unsigned char *p;
int len;
switch (taddr->choice) {
case eTransportAddress_ipAddress:
if (nf_ct_l3num(ct) != AF_INET)
return 0;
p = data + taddr->ipAddress.ip;
len = 4;
break;
case eTransportAddress_ip6Address:
if (nf_ct_l3num(ct) != AF_INET6)
return 0;
p = data + taddr->ip6Address.ip;
len = 16;
break;
default:
return 0;
}
memcpy(addr, p, len);
memset((void *)addr + len, 0, sizeof(*addr) - len);
memcpy(port, p + len, sizeof(__be16));
return 1;
}
static int expect_h245(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff, unsigned char **data, int dataoff,
TransportAddress *taddr)
{
int dir = CTINFO2DIR(ctinfo);
int ret = 0;
__be16 port;
union nf_inet_addr addr;
struct nf_conntrack_expect *exp;
typeof(nat_h245_hook) nat_h245;
if (!get_h225_addr(ct, *data, taddr, &addr, &port) ||
memcmp(&addr, &ct->tuplehash[dir].tuple.src.u3, sizeof(addr)) ||
port == 0)
return 0;
if ((exp = nf_ct_expect_alloc(ct)) == NULL)
return -1;
nf_ct_expect_init(exp, NF_CT_EXPECT_CLASS_DEFAULT, nf_ct_l3num(ct),
&ct->tuplehash[!dir].tuple.src.u3,
&ct->tuplehash[!dir].tuple.dst.u3,
IPPROTO_TCP, NULL, &port);
exp->helper = &nf_conntrack_helper_h245;
if (memcmp(&ct->tuplehash[dir].tuple.src.u3,
&ct->tuplehash[!dir].tuple.dst.u3,
sizeof(ct->tuplehash[dir].tuple.src.u3)) &&
(nat_h245 = rcu_dereference(nat_h245_hook)) &&
nf_ct_l3num(ct) == NFPROTO_IPV4 &&
ct->status & IPS_NAT_MASK) {
ret = nat_h245(skb, ct, ctinfo, protoff, data, dataoff, taddr,
port, exp);
} else {
if (nf_ct_expect_related(exp) == 0) {
pr_debug("nf_ct_q931: expect H.245 ");
nf_ct_dump_tuple(&exp->tuple);
} else
ret = -1;
}
nf_ct_expect_put(exp);
return ret;
}
static int callforward_do_filter(const union nf_inet_addr *src,
const union nf_inet_addr *dst,
u_int8_t family)
{
const struct nf_afinfo *afinfo;
int ret = 0;
afinfo = nf_get_afinfo(family);
if (!afinfo)
return 0;
switch (family) {
case AF_INET: {
struct flowi4 fl1, fl2;
struct rtable *rt1, *rt2;
memset(&fl1, 0, sizeof(fl1));
fl1.daddr = src->ip;
memset(&fl2, 0, sizeof(fl2));
fl2.daddr = dst->ip;
if (!afinfo->route(&init_net, (struct dst_entry **)&rt1,
flowi4_to_flowi(&fl1), false)) {
if (!afinfo->route(&init_net, (struct dst_entry **)&rt2,
flowi4_to_flowi(&fl2), false)) {
if (rt_nexthop(rt1, fl1.daddr) ==
rt_nexthop(rt2, fl2.daddr) &&
rt1->dst.dev == rt2->dst.dev)
ret = 1;
dst_release(&rt2->dst);
}
dst_release(&rt1->dst);
}
break;
}
#if IS_ENABLED(CONFIG_NF_CONNTRACK_IPV6)
case AF_INET6: {
struct flowi6 fl1, fl2;
struct rt6_info *rt1, *rt2;
memset(&fl1, 0, sizeof(fl1));
fl1.daddr = src->in6;
memset(&fl2, 0, sizeof(fl2));
fl2.daddr = dst->in6;
if (!afinfo->route(&init_net, (struct dst_entry **)&rt1,
flowi6_to_flowi(&fl1), false)) {
if (!afinfo->route(&init_net, (struct dst_entry **)&rt2,
flowi6_to_flowi(&fl2), false)) {
if (ipv6_addr_equal(rt6_nexthop(rt1),
rt6_nexthop(rt2)) &&
rt1->dst.dev == rt2->dst.dev)
ret = 1;
dst_release(&rt2->dst);
}
dst_release(&rt1->dst);
}
break;
}
#endif
}
return ret;
}
static int expect_callforwarding(struct sk_buff *skb,
struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, int dataoff,
TransportAddress *taddr)
{
int dir = CTINFO2DIR(ctinfo);
int ret = 0;
__be16 port;
union nf_inet_addr addr;
struct nf_conntrack_expect *exp;
typeof(nat_callforwarding_hook) nat_callforwarding;
if (!get_h225_addr(ct, *data, taddr, &addr, &port) || port == 0)
return 0;
if (callforward_filter &&
callforward_do_filter(&addr, &ct->tuplehash[!dir].tuple.src.u3,
nf_ct_l3num(ct))) {
pr_debug("nf_ct_q931: Call Forwarding not tracked\n");
return 0;
}
if ((exp = nf_ct_expect_alloc(ct)) == NULL)
return -1;
nf_ct_expect_init(exp, NF_CT_EXPECT_CLASS_DEFAULT, nf_ct_l3num(ct),
&ct->tuplehash[!dir].tuple.src.u3, &addr,
IPPROTO_TCP, NULL, &port);
exp->helper = nf_conntrack_helper_q931;
if (memcmp(&ct->tuplehash[dir].tuple.src.u3,
&ct->tuplehash[!dir].tuple.dst.u3,
sizeof(ct->tuplehash[dir].tuple.src.u3)) &&
(nat_callforwarding = rcu_dereference(nat_callforwarding_hook)) &&
nf_ct_l3num(ct) == NFPROTO_IPV4 &&
ct->status & IPS_NAT_MASK) {
ret = nat_callforwarding(skb, ct, ctinfo,
protoff, data, dataoff,
taddr, port, exp);
} else {
if (nf_ct_expect_related(exp) == 0) {
pr_debug("nf_ct_q931: expect Call Forwarding ");
nf_ct_dump_tuple(&exp->tuple);
} else
ret = -1;
}
nf_ct_expect_put(exp);
return ret;
}
static int process_setup(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, int dataoff,
Setup_UUIE *setup)
{
int dir = CTINFO2DIR(ctinfo);
int ret;
int i;
__be16 port;
union nf_inet_addr addr;
typeof(set_h225_addr_hook) set_h225_addr;
pr_debug("nf_ct_q931: Setup\n");
if (setup->options & eSetup_UUIE_h245Address) {
ret = expect_h245(skb, ct, ctinfo, protoff, data, dataoff,
&setup->h245Address);
if (ret < 0)
return -1;
}
set_h225_addr = rcu_dereference(set_h225_addr_hook);
if ((setup->options & eSetup_UUIE_destCallSignalAddress) &&
(set_h225_addr) && nf_ct_l3num(ct) == NFPROTO_IPV4 &&
ct->status & IPS_NAT_MASK &&
get_h225_addr(ct, *data, &setup->destCallSignalAddress,
&addr, &port) &&
memcmp(&addr, &ct->tuplehash[!dir].tuple.src.u3, sizeof(addr))) {
pr_debug("nf_ct_q931: set destCallSignalAddress %pI6:%hu->%pI6:%hu\n",
&addr, ntohs(port), &ct->tuplehash[!dir].tuple.src.u3,
ntohs(ct->tuplehash[!dir].tuple.src.u.tcp.port));
ret = set_h225_addr(skb, protoff, data, dataoff,
&setup->destCallSignalAddress,
&ct->tuplehash[!dir].tuple.src.u3,
ct->tuplehash[!dir].tuple.src.u.tcp.port);
if (ret < 0)
return -1;
}
if ((setup->options & eSetup_UUIE_sourceCallSignalAddress) &&
(set_h225_addr) && nf_ct_l3num(ct) == NFPROTO_IPV4 &&
ct->status & IPS_NAT_MASK &&
get_h225_addr(ct, *data, &setup->sourceCallSignalAddress,
&addr, &port) &&
memcmp(&addr, &ct->tuplehash[!dir].tuple.dst.u3, sizeof(addr))) {
pr_debug("nf_ct_q931: set sourceCallSignalAddress %pI6:%hu->%pI6:%hu\n",
&addr, ntohs(port), &ct->tuplehash[!dir].tuple.dst.u3,
ntohs(ct->tuplehash[!dir].tuple.dst.u.tcp.port));
ret = set_h225_addr(skb, protoff, data, dataoff,
&setup->sourceCallSignalAddress,
&ct->tuplehash[!dir].tuple.dst.u3,
ct->tuplehash[!dir].tuple.dst.u.tcp.port);
if (ret < 0)
return -1;
}
if (setup->options & eSetup_UUIE_fastStart) {
for (i = 0; i < setup->fastStart.count; i++) {
ret = process_olc(skb, ct, ctinfo,
protoff, data, dataoff,
&setup->fastStart.item[i]);
if (ret < 0)
return -1;
}
}
return 0;
}
static int process_callproceeding(struct sk_buff *skb,
struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, int dataoff,
CallProceeding_UUIE *callproc)
{
int ret;
int i;
pr_debug("nf_ct_q931: CallProceeding\n");
if (callproc->options & eCallProceeding_UUIE_h245Address) {
ret = expect_h245(skb, ct, ctinfo, protoff, data, dataoff,
&callproc->h245Address);
if (ret < 0)
return -1;
}
if (callproc->options & eCallProceeding_UUIE_fastStart) {
for (i = 0; i < callproc->fastStart.count; i++) {
ret = process_olc(skb, ct, ctinfo,
protoff, data, dataoff,
&callproc->fastStart.item[i]);
if (ret < 0)
return -1;
}
}
return 0;
}
static int process_connect(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, int dataoff,
Connect_UUIE *connect)
{
int ret;
int i;
pr_debug("nf_ct_q931: Connect\n");
if (connect->options & eConnect_UUIE_h245Address) {
ret = expect_h245(skb, ct, ctinfo, protoff, data, dataoff,
&connect->h245Address);
if (ret < 0)
return -1;
}
if (connect->options & eConnect_UUIE_fastStart) {
for (i = 0; i < connect->fastStart.count; i++) {
ret = process_olc(skb, ct, ctinfo,
protoff, data, dataoff,
&connect->fastStart.item[i]);
if (ret < 0)
return -1;
}
}
return 0;
}
static int process_alerting(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, int dataoff,
Alerting_UUIE *alert)
{
int ret;
int i;
pr_debug("nf_ct_q931: Alerting\n");
if (alert->options & eAlerting_UUIE_h245Address) {
ret = expect_h245(skb, ct, ctinfo, protoff, data, dataoff,
&alert->h245Address);
if (ret < 0)
return -1;
}
if (alert->options & eAlerting_UUIE_fastStart) {
for (i = 0; i < alert->fastStart.count; i++) {
ret = process_olc(skb, ct, ctinfo,
protoff, data, dataoff,
&alert->fastStart.item[i]);
if (ret < 0)
return -1;
}
}
return 0;
}
static int process_facility(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, int dataoff,
Facility_UUIE *facility)
{
int ret;
int i;
pr_debug("nf_ct_q931: Facility\n");
if (facility->reason.choice == eFacilityReason_callForwarded) {
if (facility->options & eFacility_UUIE_alternativeAddress)
return expect_callforwarding(skb, ct, ctinfo,
protoff, data, dataoff,
&facility->
alternativeAddress);
return 0;
}
if (facility->options & eFacility_UUIE_h245Address) {
ret = expect_h245(skb, ct, ctinfo, protoff, data, dataoff,
&facility->h245Address);
if (ret < 0)
return -1;
}
if (facility->options & eFacility_UUIE_fastStart) {
for (i = 0; i < facility->fastStart.count; i++) {
ret = process_olc(skb, ct, ctinfo,
protoff, data, dataoff,
&facility->fastStart.item[i]);
if (ret < 0)
return -1;
}
}
return 0;
}
static int process_progress(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, int dataoff,
Progress_UUIE *progress)
{
int ret;
int i;
pr_debug("nf_ct_q931: Progress\n");
if (progress->options & eProgress_UUIE_h245Address) {
ret = expect_h245(skb, ct, ctinfo, protoff, data, dataoff,
&progress->h245Address);
if (ret < 0)
return -1;
}
if (progress->options & eProgress_UUIE_fastStart) {
for (i = 0; i < progress->fastStart.count; i++) {
ret = process_olc(skb, ct, ctinfo,
protoff, data, dataoff,
&progress->fastStart.item[i]);
if (ret < 0)
return -1;
}
}
return 0;
}
static int process_q931(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff, unsigned char **data, int dataoff,
Q931 *q931)
{
H323_UU_PDU *pdu = &q931->UUIE.h323_uu_pdu;
int i;
int ret = 0;
switch (pdu->h323_message_body.choice) {
case eH323_UU_PDU_h323_message_body_setup:
ret = process_setup(skb, ct, ctinfo, protoff, data, dataoff,
&pdu->h323_message_body.setup);
break;
case eH323_UU_PDU_h323_message_body_callProceeding:
ret = process_callproceeding(skb, ct, ctinfo,
protoff, data, dataoff,
&pdu->h323_message_body.
callProceeding);
break;
case eH323_UU_PDU_h323_message_body_connect:
ret = process_connect(skb, ct, ctinfo, protoff, data, dataoff,
&pdu->h323_message_body.connect);
break;
case eH323_UU_PDU_h323_message_body_alerting:
ret = process_alerting(skb, ct, ctinfo, protoff, data, dataoff,
&pdu->h323_message_body.alerting);
break;
case eH323_UU_PDU_h323_message_body_facility:
ret = process_facility(skb, ct, ctinfo, protoff, data, dataoff,
&pdu->h323_message_body.facility);
break;
case eH323_UU_PDU_h323_message_body_progress:
ret = process_progress(skb, ct, ctinfo, protoff, data, dataoff,
&pdu->h323_message_body.progress);
break;
default:
pr_debug("nf_ct_q931: Q.931 signal %d\n",
pdu->h323_message_body.choice);
break;
}
if (ret < 0)
return -1;
if (pdu->options & eH323_UU_PDU_h245Control) {
for (i = 0; i < pdu->h245Control.count; i++) {
ret = process_h245(skb, ct, ctinfo,
protoff, data, dataoff,
&pdu->h245Control.item[i]);
if (ret < 0)
return -1;
}
}
return 0;
}
static int q931_help(struct sk_buff *skb, unsigned int protoff,
struct nf_conn *ct, enum ip_conntrack_info ctinfo)
{
static Q931 q931;
unsigned char *data = NULL;
int datalen;
int dataoff;
int ret;
if (ctinfo != IP_CT_ESTABLISHED && ctinfo != IP_CT_ESTABLISHED_REPLY)
return NF_ACCEPT;
pr_debug("nf_ct_q931: skblen = %u\n", skb->len);
spin_lock_bh(&nf_h323_lock);
while (get_tpkt_data(skb, protoff, ct, ctinfo,
&data, &datalen, &dataoff)) {
pr_debug("nf_ct_q931: TPKT len=%d ", datalen);
nf_ct_dump_tuple(&ct->tuplehash[CTINFO2DIR(ctinfo)].tuple);
ret = DecodeQ931(data, datalen, &q931);
if (ret < 0) {
pr_debug("nf_ct_q931: decoding error: %s\n",
ret == H323_ERROR_BOUND ?
"out of bound" : "out of range");
break;
}
if (process_q931(skb, ct, ctinfo, protoff,
&data, dataoff, &q931) < 0)
goto drop;
}
spin_unlock_bh(&nf_h323_lock);
return NF_ACCEPT;
drop:
spin_unlock_bh(&nf_h323_lock);
nf_ct_helper_log(skb, ct, "cannot process Q.931 message");
return NF_DROP;
}
static unsigned char *get_udp_data(struct sk_buff *skb, unsigned int protoff,
int *datalen)
{
const struct udphdr *uh;
struct udphdr _uh;
int dataoff;
uh = skb_header_pointer(skb, protoff, sizeof(_uh), &_uh);
if (uh == NULL)
return NULL;
dataoff = protoff + sizeof(_uh);
if (dataoff >= skb->len)
return NULL;
*datalen = skb->len - dataoff;
return skb_header_pointer(skb, dataoff, *datalen, h323_buffer);
}
static struct nf_conntrack_expect *find_expect(struct nf_conn *ct,
union nf_inet_addr *addr,
__be16 port)
{
struct net *net = nf_ct_net(ct);
struct nf_conntrack_expect *exp;
struct nf_conntrack_tuple tuple;
memset(&tuple.src.u3, 0, sizeof(tuple.src.u3));
tuple.src.u.tcp.port = 0;
memcpy(&tuple.dst.u3, addr, sizeof(tuple.dst.u3));
tuple.dst.u.tcp.port = port;
tuple.dst.protonum = IPPROTO_TCP;
exp = __nf_ct_expect_find(net, nf_ct_zone(ct), &tuple);
if (exp && exp->master == ct)
return exp;
return NULL;
}
static int set_expect_timeout(struct nf_conntrack_expect *exp,
unsigned int timeout)
{
if (!exp || !del_timer(&exp->timeout))
return 0;
exp->timeout.expires = jiffies + timeout * HZ;
add_timer(&exp->timeout);
return 1;
}
static int expect_q931(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff, unsigned char **data,
TransportAddress *taddr, int count)
{
struct nf_ct_h323_master *info = nfct_help_data(ct);
int dir = CTINFO2DIR(ctinfo);
int ret = 0;
int i;
__be16 port;
union nf_inet_addr addr;
struct nf_conntrack_expect *exp;
typeof(nat_q931_hook) nat_q931;
for (i = 0; i < count; i++) {
if (get_h225_addr(ct, *data, &taddr[i], &addr, &port) &&
memcmp(&addr, &ct->tuplehash[dir].tuple.src.u3,
sizeof(addr)) == 0 && port != 0)
break;
}
if (i >= count)
return 0;
if ((exp = nf_ct_expect_alloc(ct)) == NULL)
return -1;
nf_ct_expect_init(exp, NF_CT_EXPECT_CLASS_DEFAULT, nf_ct_l3num(ct),
gkrouted_only ?
&ct->tuplehash[!dir].tuple.src.u3 : NULL,
&ct->tuplehash[!dir].tuple.dst.u3,
IPPROTO_TCP, NULL, &port);
exp->helper = nf_conntrack_helper_q931;
exp->flags = NF_CT_EXPECT_PERMANENT;
nat_q931 = rcu_dereference(nat_q931_hook);
if (nat_q931 && nf_ct_l3num(ct) == NFPROTO_IPV4 &&
ct->status & IPS_NAT_MASK) {
ret = nat_q931(skb, ct, ctinfo, protoff, data,
taddr, i, port, exp);
} else {
if (nf_ct_expect_related(exp) == 0) {
pr_debug("nf_ct_ras: expect Q.931 ");
nf_ct_dump_tuple(&exp->tuple);
info->sig_port[dir] = port;
} else
ret = -1;
}
nf_ct_expect_put(exp);
return ret;
}
static int process_grq(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, GatekeeperRequest *grq)
{
typeof(set_ras_addr_hook) set_ras_addr;
pr_debug("nf_ct_ras: GRQ\n");
set_ras_addr = rcu_dereference(set_ras_addr_hook);
if (set_ras_addr && nf_ct_l3num(ct) == NFPROTO_IPV4 &&
ct->status & IPS_NAT_MASK)
return set_ras_addr(skb, ct, ctinfo, protoff, data,
&grq->rasAddress, 1);
return 0;
}
static int process_gcf(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, GatekeeperConfirm *gcf)
{
int dir = CTINFO2DIR(ctinfo);
int ret = 0;
__be16 port;
union nf_inet_addr addr;
struct nf_conntrack_expect *exp;
pr_debug("nf_ct_ras: GCF\n");
if (!get_h225_addr(ct, *data, &gcf->rasAddress, &addr, &port))
return 0;
if (!memcmp(&addr, &ct->tuplehash[dir].tuple.src.u3, sizeof(addr)) &&
port == ct->tuplehash[dir].tuple.src.u.udp.port)
return 0;
if (test_bit(IPS_EXPECTED_BIT, &ct->status))
return 0;
if ((exp = nf_ct_expect_alloc(ct)) == NULL)
return -1;
nf_ct_expect_init(exp, NF_CT_EXPECT_CLASS_DEFAULT, nf_ct_l3num(ct),
&ct->tuplehash[!dir].tuple.src.u3, &addr,
IPPROTO_UDP, NULL, &port);
exp->helper = nf_conntrack_helper_ras;
if (nf_ct_expect_related(exp) == 0) {
pr_debug("nf_ct_ras: expect RAS ");
nf_ct_dump_tuple(&exp->tuple);
} else
ret = -1;
nf_ct_expect_put(exp);
return ret;
}
static int process_rrq(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, RegistrationRequest *rrq)
{
struct nf_ct_h323_master *info = nfct_help_data(ct);
int ret;
typeof(set_ras_addr_hook) set_ras_addr;
pr_debug("nf_ct_ras: RRQ\n");
ret = expect_q931(skb, ct, ctinfo, protoff, data,
rrq->callSignalAddress.item,
rrq->callSignalAddress.count);
if (ret < 0)
return -1;
set_ras_addr = rcu_dereference(set_ras_addr_hook);
if (set_ras_addr && nf_ct_l3num(ct) == NFPROTO_IPV4 &&
ct->status & IPS_NAT_MASK) {
ret = set_ras_addr(skb, ct, ctinfo, protoff, data,
rrq->rasAddress.item,
rrq->rasAddress.count);
if (ret < 0)
return -1;
}
if (rrq->options & eRegistrationRequest_timeToLive) {
pr_debug("nf_ct_ras: RRQ TTL = %u seconds\n", rrq->timeToLive);
info->timeout = rrq->timeToLive;
} else
info->timeout = default_rrq_ttl;
return 0;
}
static int process_rcf(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, RegistrationConfirm *rcf)
{
struct nf_ct_h323_master *info = nfct_help_data(ct);
int dir = CTINFO2DIR(ctinfo);
int ret;
struct nf_conntrack_expect *exp;
typeof(set_sig_addr_hook) set_sig_addr;
pr_debug("nf_ct_ras: RCF\n");
set_sig_addr = rcu_dereference(set_sig_addr_hook);
if (set_sig_addr && nf_ct_l3num(ct) == NFPROTO_IPV4 &&
ct->status & IPS_NAT_MASK) {
ret = set_sig_addr(skb, ct, ctinfo, protoff, data,
rcf->callSignalAddress.item,
rcf->callSignalAddress.count);
if (ret < 0)
return -1;
}
if (rcf->options & eRegistrationConfirm_timeToLive) {
pr_debug("nf_ct_ras: RCF TTL = %u seconds\n", rcf->timeToLive);
info->timeout = rcf->timeToLive;
}
if (info->timeout > 0) {
pr_debug("nf_ct_ras: set RAS connection timeout to "
"%u seconds\n", info->timeout);
nf_ct_refresh(ct, skb, info->timeout * HZ);
spin_lock_bh(&nf_conntrack_lock);
exp = find_expect(ct, &ct->tuplehash[dir].tuple.dst.u3,
info->sig_port[!dir]);
if (exp) {
pr_debug("nf_ct_ras: set Q.931 expect "
"timeout to %u seconds for",
info->timeout);
nf_ct_dump_tuple(&exp->tuple);
set_expect_timeout(exp, info->timeout);
}
spin_unlock_bh(&nf_conntrack_lock);
}
return 0;
}
static int process_urq(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, UnregistrationRequest *urq)
{
struct nf_ct_h323_master *info = nfct_help_data(ct);
int dir = CTINFO2DIR(ctinfo);
int ret;
typeof(set_sig_addr_hook) set_sig_addr;
pr_debug("nf_ct_ras: URQ\n");
set_sig_addr = rcu_dereference(set_sig_addr_hook);
if (set_sig_addr && nf_ct_l3num(ct) == NFPROTO_IPV4 &&
ct->status & IPS_NAT_MASK) {
ret = set_sig_addr(skb, ct, ctinfo, protoff, data,
urq->callSignalAddress.item,
urq->callSignalAddress.count);
if (ret < 0)
return -1;
}
nf_ct_remove_expectations(ct);
info->sig_port[dir] = 0;
info->sig_port[!dir] = 0;
nf_ct_refresh(ct, skb, 30 * HZ);
return 0;
}
static int process_arq(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, AdmissionRequest *arq)
{
const struct nf_ct_h323_master *info = nfct_help_data(ct);
int dir = CTINFO2DIR(ctinfo);
__be16 port;
union nf_inet_addr addr;
typeof(set_h225_addr_hook) set_h225_addr;
pr_debug("nf_ct_ras: ARQ\n");
set_h225_addr = rcu_dereference(set_h225_addr_hook);
if ((arq->options & eAdmissionRequest_destCallSignalAddress) &&
get_h225_addr(ct, *data, &arq->destCallSignalAddress,
&addr, &port) &&
!memcmp(&addr, &ct->tuplehash[dir].tuple.src.u3, sizeof(addr)) &&
port == info->sig_port[dir] &&
nf_ct_l3num(ct) == NFPROTO_IPV4 &&
set_h225_addr && ct->status & IPS_NAT_MASK) {
return set_h225_addr(skb, protoff, data, 0,
&arq->destCallSignalAddress,
&ct->tuplehash[!dir].tuple.dst.u3,
info->sig_port[!dir]);
}
if ((arq->options & eAdmissionRequest_srcCallSignalAddress) &&
get_h225_addr(ct, *data, &arq->srcCallSignalAddress,
&addr, &port) &&
!memcmp(&addr, &ct->tuplehash[dir].tuple.src.u3, sizeof(addr)) &&
set_h225_addr && nf_ct_l3num(ct) == NFPROTO_IPV4 &&
ct->status & IPS_NAT_MASK) {
return set_h225_addr(skb, protoff, data, 0,
&arq->srcCallSignalAddress,
&ct->tuplehash[!dir].tuple.dst.u3,
port);
}
return 0;
}
static int process_acf(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, AdmissionConfirm *acf)
{
int dir = CTINFO2DIR(ctinfo);
int ret = 0;
__be16 port;
union nf_inet_addr addr;
struct nf_conntrack_expect *exp;
typeof(set_sig_addr_hook) set_sig_addr;
pr_debug("nf_ct_ras: ACF\n");
if (!get_h225_addr(ct, *data, &acf->destCallSignalAddress,
&addr, &port))
return 0;
if (!memcmp(&addr, &ct->tuplehash[dir].tuple.dst.u3, sizeof(addr))) {
set_sig_addr = rcu_dereference(set_sig_addr_hook);
if (set_sig_addr && nf_ct_l3num(ct) == NFPROTO_IPV4 &&
ct->status & IPS_NAT_MASK)
return set_sig_addr(skb, ct, ctinfo, protoff, data,
&acf->destCallSignalAddress, 1);
return 0;
}
if ((exp = nf_ct_expect_alloc(ct)) == NULL)
return -1;
nf_ct_expect_init(exp, NF_CT_EXPECT_CLASS_DEFAULT, nf_ct_l3num(ct),
&ct->tuplehash[!dir].tuple.src.u3, &addr,
IPPROTO_TCP, NULL, &port);
exp->flags = NF_CT_EXPECT_PERMANENT;
exp->helper = nf_conntrack_helper_q931;
if (nf_ct_expect_related(exp) == 0) {
pr_debug("nf_ct_ras: expect Q.931 ");
nf_ct_dump_tuple(&exp->tuple);
} else
ret = -1;
nf_ct_expect_put(exp);
return ret;
}
static int process_lrq(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, LocationRequest *lrq)
{
typeof(set_ras_addr_hook) set_ras_addr;
pr_debug("nf_ct_ras: LRQ\n");
set_ras_addr = rcu_dereference(set_ras_addr_hook);
if (set_ras_addr && nf_ct_l3num(ct) == NFPROTO_IPV4 &&
ct->status & IPS_NAT_MASK)
return set_ras_addr(skb, ct, ctinfo, protoff, data,
&lrq->replyAddress, 1);
return 0;
}
static int process_lcf(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, LocationConfirm *lcf)
{
int dir = CTINFO2DIR(ctinfo);
int ret = 0;
__be16 port;
union nf_inet_addr addr;
struct nf_conntrack_expect *exp;
pr_debug("nf_ct_ras: LCF\n");
if (!get_h225_addr(ct, *data, &lcf->callSignalAddress,
&addr, &port))
return 0;
if ((exp = nf_ct_expect_alloc(ct)) == NULL)
return -1;
nf_ct_expect_init(exp, NF_CT_EXPECT_CLASS_DEFAULT, nf_ct_l3num(ct),
&ct->tuplehash[!dir].tuple.src.u3, &addr,
IPPROTO_TCP, NULL, &port);
exp->flags = NF_CT_EXPECT_PERMANENT;
exp->helper = nf_conntrack_helper_q931;
if (nf_ct_expect_related(exp) == 0) {
pr_debug("nf_ct_ras: expect Q.931 ");
nf_ct_dump_tuple(&exp->tuple);
} else
ret = -1;
nf_ct_expect_put(exp);
return ret;
}
static int process_irr(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, InfoRequestResponse *irr)
{
int ret;
typeof(set_ras_addr_hook) set_ras_addr;
typeof(set_sig_addr_hook) set_sig_addr;
pr_debug("nf_ct_ras: IRR\n");
set_ras_addr = rcu_dereference(set_ras_addr_hook);
if (set_ras_addr && nf_ct_l3num(ct) == NFPROTO_IPV4 &&
ct->status & IPS_NAT_MASK) {
ret = set_ras_addr(skb, ct, ctinfo, protoff, data,
&irr->rasAddress, 1);
if (ret < 0)
return -1;
}
set_sig_addr = rcu_dereference(set_sig_addr_hook);
if (set_sig_addr && nf_ct_l3num(ct) == NFPROTO_IPV4 &&
ct->status & IPS_NAT_MASK) {
ret = set_sig_addr(skb, ct, ctinfo, protoff, data,
irr->callSignalAddress.item,
irr->callSignalAddress.count);
if (ret < 0)
return -1;
}
return 0;
}
static int process_ras(struct sk_buff *skb, struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned char **data, RasMessage *ras)
{
switch (ras->choice) {
case eRasMessage_gatekeeperRequest:
return process_grq(skb, ct, ctinfo, protoff, data,
&ras->gatekeeperRequest);
case eRasMessage_gatekeeperConfirm:
return process_gcf(skb, ct, ctinfo, protoff, data,
&ras->gatekeeperConfirm);
case eRasMessage_registrationRequest:
return process_rrq(skb, ct, ctinfo, protoff, data,
&ras->registrationRequest);
case eRasMessage_registrationConfirm:
return process_rcf(skb, ct, ctinfo, protoff, data,
&ras->registrationConfirm);
case eRasMessage_unregistrationRequest:
return process_urq(skb, ct, ctinfo, protoff, data,
&ras->unregistrationRequest);
case eRasMessage_admissionRequest:
return process_arq(skb, ct, ctinfo, protoff, data,
&ras->admissionRequest);
case eRasMessage_admissionConfirm:
return process_acf(skb, ct, ctinfo, protoff, data,
&ras->admissionConfirm);
case eRasMessage_locationRequest:
return process_lrq(skb, ct, ctinfo, protoff, data,
&ras->locationRequest);
case eRasMessage_locationConfirm:
return process_lcf(skb, ct, ctinfo, protoff, data,
&ras->locationConfirm);
case eRasMessage_infoRequestResponse:
return process_irr(skb, ct, ctinfo, protoff, data,
&ras->infoRequestResponse);
default:
pr_debug("nf_ct_ras: RAS message %d\n", ras->choice);
break;
}
return 0;
}
static int ras_help(struct sk_buff *skb, unsigned int protoff,
struct nf_conn *ct, enum ip_conntrack_info ctinfo)
{
static RasMessage ras;
unsigned char *data;
int datalen = 0;
int ret;
pr_debug("nf_ct_ras: skblen = %u\n", skb->len);
spin_lock_bh(&nf_h323_lock);
data = get_udp_data(skb, protoff, &datalen);
if (data == NULL)
goto accept;
pr_debug("nf_ct_ras: RAS message len=%d ", datalen);
nf_ct_dump_tuple(&ct->tuplehash[CTINFO2DIR(ctinfo)].tuple);
ret = DecodeRasMessage(data, datalen, &ras);
if (ret < 0) {
pr_debug("nf_ct_ras: decoding error: %s\n",
ret == H323_ERROR_BOUND ?
"out of bound" : "out of range");
goto accept;
}
if (process_ras(skb, ct, ctinfo, protoff, &data, &ras) < 0)
goto drop;
accept:
spin_unlock_bh(&nf_h323_lock);
return NF_ACCEPT;
drop:
spin_unlock_bh(&nf_h323_lock);
nf_ct_helper_log(skb, ct, "cannot process RAS message");
return NF_DROP;
}
static void __exit nf_conntrack_h323_fini(void)
{
nf_conntrack_helper_unregister(&nf_conntrack_helper_ras[1]);
nf_conntrack_helper_unregister(&nf_conntrack_helper_ras[0]);
nf_conntrack_helper_unregister(&nf_conntrack_helper_q931[1]);
nf_conntrack_helper_unregister(&nf_conntrack_helper_q931[0]);
nf_conntrack_helper_unregister(&nf_conntrack_helper_h245);
kfree(h323_buffer);
pr_debug("nf_ct_h323: fini\n");
}
static int __init nf_conntrack_h323_init(void)
{
int ret;
h323_buffer = kmalloc(65536, GFP_KERNEL);
if (!h323_buffer)
return -ENOMEM;
ret = nf_conntrack_helper_register(&nf_conntrack_helper_h245);
if (ret < 0)
goto err1;
ret = nf_conntrack_helper_register(&nf_conntrack_helper_q931[0]);
if (ret < 0)
goto err2;
ret = nf_conntrack_helper_register(&nf_conntrack_helper_q931[1]);
if (ret < 0)
goto err3;
ret = nf_conntrack_helper_register(&nf_conntrack_helper_ras[0]);
if (ret < 0)
goto err4;
ret = nf_conntrack_helper_register(&nf_conntrack_helper_ras[1]);
if (ret < 0)
goto err5;
pr_debug("nf_ct_h323: init success\n");
return 0;
err5:
nf_conntrack_helper_unregister(&nf_conntrack_helper_ras[0]);
err4:
nf_conntrack_helper_unregister(&nf_conntrack_helper_q931[1]);
err3:
nf_conntrack_helper_unregister(&nf_conntrack_helper_q931[0]);
err2:
nf_conntrack_helper_unregister(&nf_conntrack_helper_h245);
err1:
kfree(h323_buffer);
return ret;
}
