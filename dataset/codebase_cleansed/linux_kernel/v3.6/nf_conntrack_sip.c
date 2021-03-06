static int string_len(const struct nf_conn *ct, const char *dptr,
const char *limit, int *shift)
{
int len = 0;
while (dptr < limit && isalpha(*dptr)) {
dptr++;
len++;
}
return len;
}
static int digits_len(const struct nf_conn *ct, const char *dptr,
const char *limit, int *shift)
{
int len = 0;
while (dptr < limit && isdigit(*dptr)) {
dptr++;
len++;
}
return len;
}
static int iswordc(const char c)
{
if (isalnum(c) || c == '!' || c == '"' || c == '%' ||
(c >= '(' && c <= '/') || c == ':' || c == '<' || c == '>' ||
c == '?' || (c >= '[' && c <= ']') || c == '_' || c == '`' ||
c == '{' || c == '}' || c == '~')
return 1;
return 0;
}
static int word_len(const char *dptr, const char *limit)
{
int len = 0;
while (dptr < limit && iswordc(*dptr)) {
dptr++;
len++;
}
return len;
}
static int callid_len(const struct nf_conn *ct, const char *dptr,
const char *limit, int *shift)
{
int len, domain_len;
len = word_len(dptr, limit);
dptr += len;
if (!len || dptr == limit || *dptr != '@')
return len;
dptr++;
len++;
domain_len = word_len(dptr, limit);
if (!domain_len)
return 0;
return len + domain_len;
}
static int media_len(const struct nf_conn *ct, const char *dptr,
const char *limit, int *shift)
{
int len = string_len(ct, dptr, limit, shift);
dptr += len;
if (dptr >= limit || *dptr != ' ')
return 0;
len++;
dptr++;
return len + digits_len(ct, dptr, limit, shift);
}
static int sip_parse_addr(const struct nf_conn *ct, const char *cp,
const char **endp, union nf_inet_addr *addr,
const char *limit, bool delim)
{
const char *end;
int ret;
if (!ct)
return 0;
memset(addr, 0, sizeof(*addr));
switch (nf_ct_l3num(ct)) {
case AF_INET:
ret = in4_pton(cp, limit - cp, (u8 *)&addr->ip, -1, &end);
if (ret == 0)
return 0;
break;
case AF_INET6:
if (cp < limit && *cp == '[')
cp++;
else if (delim)
return 0;
ret = in6_pton(cp, limit - cp, (u8 *)&addr->ip6, -1, &end);
if (ret == 0)
return 0;
if (end < limit && *end == ']')
end++;
else if (delim)
return 0;
break;
default:
BUG();
}
if (endp)
*endp = end;
return 1;
}
static int epaddr_len(const struct nf_conn *ct, const char *dptr,
const char *limit, int *shift)
{
union nf_inet_addr addr;
const char *aux = dptr;
if (!sip_parse_addr(ct, dptr, &dptr, &addr, limit, true)) {
pr_debug("ip: %s parse failed.!\n", dptr);
return 0;
}
if (*dptr == ':') {
dptr++;
dptr += digits_len(ct, dptr, limit, shift);
}
return dptr - aux;
}
static int skp_epaddr_len(const struct nf_conn *ct, const char *dptr,
const char *limit, int *shift)
{
const char *start = dptr;
int s = *shift;
while (dptr < limit &&
*dptr != '@' && *dptr != '\r' && *dptr != '\n') {
(*shift)++;
dptr++;
}
if (dptr < limit && *dptr == '@') {
dptr++;
(*shift)++;
} else {
dptr = start;
*shift = s;
}
return epaddr_len(ct, dptr, limit, shift);
}
int ct_sip_parse_request(const struct nf_conn *ct,
const char *dptr, unsigned int datalen,
unsigned int *matchoff, unsigned int *matchlen,
union nf_inet_addr *addr, __be16 *port)
{
const char *start = dptr, *limit = dptr + datalen, *end;
unsigned int mlen;
unsigned int p;
int shift = 0;
mlen = string_len(ct, dptr, limit, NULL);
if (!mlen)
return 0;
dptr += mlen;
if (++dptr >= limit)
return 0;
for (; dptr < limit - strlen("sip:"); dptr++) {
if (*dptr == '\r' || *dptr == '\n')
return -1;
if (strnicmp(dptr, "sip:", strlen("sip:")) == 0) {
dptr += strlen("sip:");
break;
}
}
if (!skp_epaddr_len(ct, dptr, limit, &shift))
return 0;
dptr += shift;
if (!sip_parse_addr(ct, dptr, &end, addr, limit, true))
return -1;
if (end < limit && *end == ':') {
end++;
p = simple_strtoul(end, (char **)&end, 10);
if (p < 1024 || p > 65535)
return -1;
*port = htons(p);
} else
*port = htons(SIP_PORT);
if (end == dptr)
return 0;
*matchoff = dptr - start;
*matchlen = end - dptr;
return 1;
}
static const char *sip_follow_continuation(const char *dptr, const char *limit)
{
if (++dptr >= limit)
return NULL;
if (*(dptr - 1) == '\r' && *dptr == '\n') {
if (++dptr >= limit)
return NULL;
}
if (*dptr != ' ' && *dptr != '\t')
return NULL;
for (; dptr < limit; dptr++) {
if (*dptr != ' ' && *dptr != '\t')
break;
}
return dptr;
}
static const char *sip_skip_whitespace(const char *dptr, const char *limit)
{
for (; dptr < limit; dptr++) {
if (*dptr == ' ')
continue;
if (*dptr != '\r' && *dptr != '\n')
break;
dptr = sip_follow_continuation(dptr, limit);
if (dptr == NULL)
return NULL;
}
return dptr;
}
static const char *ct_sip_header_search(const char *dptr, const char *limit,
const char *needle, unsigned int len)
{
for (limit -= len; dptr < limit; dptr++) {
if (*dptr == '\r' || *dptr == '\n') {
dptr = sip_follow_continuation(dptr, limit);
if (dptr == NULL)
break;
continue;
}
if (strnicmp(dptr, needle, len) == 0)
return dptr;
}
return NULL;
}
int ct_sip_get_header(const struct nf_conn *ct, const char *dptr,
unsigned int dataoff, unsigned int datalen,
enum sip_header_types type,
unsigned int *matchoff, unsigned int *matchlen)
{
const struct sip_header *hdr = &ct_sip_hdrs[type];
const char *start = dptr, *limit = dptr + datalen;
int shift = 0;
for (dptr += dataoff; dptr < limit; dptr++) {
if (*dptr != '\r' && *dptr != '\n')
continue;
if (++dptr >= limit)
break;
if (*(dptr - 1) == '\r' && *dptr == '\n') {
if (++dptr >= limit)
break;
}
if (*dptr == ' ' || *dptr == '\t')
continue;
if (limit - dptr >= hdr->len &&
strnicmp(dptr, hdr->name, hdr->len) == 0)
dptr += hdr->len;
else if (hdr->cname && limit - dptr >= hdr->clen + 1 &&
strnicmp(dptr, hdr->cname, hdr->clen) == 0 &&
!isalpha(*(dptr + hdr->clen)))
dptr += hdr->clen;
else
continue;
dptr = sip_skip_whitespace(dptr, limit);
if (dptr == NULL)
break;
if (*dptr != ':' || ++dptr >= limit)
break;
dptr = sip_skip_whitespace(dptr, limit);
if (dptr == NULL)
break;
*matchoff = dptr - start;
if (hdr->search) {
dptr = ct_sip_header_search(dptr, limit, hdr->search,
hdr->slen);
if (!dptr)
return -1;
dptr += hdr->slen;
}
*matchlen = hdr->match_len(ct, dptr, limit, &shift);
if (!*matchlen)
return -1;
*matchoff = dptr - start + shift;
return 1;
}
return 0;
}
static int ct_sip_next_header(const struct nf_conn *ct, const char *dptr,
unsigned int dataoff, unsigned int datalen,
enum sip_header_types type,
unsigned int *matchoff, unsigned int *matchlen)
{
const struct sip_header *hdr = &ct_sip_hdrs[type];
const char *start = dptr, *limit = dptr + datalen;
int shift = 0;
dptr += dataoff;
dptr = ct_sip_header_search(dptr, limit, ",", strlen(","));
if (!dptr)
return 0;
dptr = ct_sip_header_search(dptr, limit, hdr->search, hdr->slen);
if (!dptr)
return 0;
dptr += hdr->slen;
*matchoff = dptr - start;
*matchlen = hdr->match_len(ct, dptr, limit, &shift);
if (!*matchlen)
return -1;
*matchoff += shift;
return 1;
}
static int ct_sip_walk_headers(const struct nf_conn *ct, const char *dptr,
unsigned int dataoff, unsigned int datalen,
enum sip_header_types type, int *in_header,
unsigned int *matchoff, unsigned int *matchlen)
{
int ret;
if (in_header && *in_header) {
while (1) {
ret = ct_sip_next_header(ct, dptr, dataoff, datalen,
type, matchoff, matchlen);
if (ret > 0)
return ret;
if (ret == 0)
break;
dataoff += *matchoff;
}
*in_header = 0;
}
while (1) {
ret = ct_sip_get_header(ct, dptr, dataoff, datalen,
type, matchoff, matchlen);
if (ret > 0)
break;
if (ret == 0)
return ret;
dataoff += *matchoff;
}
if (in_header)
*in_header = 1;
return 1;
}
int ct_sip_parse_header_uri(const struct nf_conn *ct, const char *dptr,
unsigned int *dataoff, unsigned int datalen,
enum sip_header_types type, int *in_header,
unsigned int *matchoff, unsigned int *matchlen,
union nf_inet_addr *addr, __be16 *port)
{
const char *c, *limit = dptr + datalen;
unsigned int p;
int ret;
ret = ct_sip_walk_headers(ct, dptr, dataoff ? *dataoff : 0, datalen,
type, in_header, matchoff, matchlen);
WARN_ON(ret < 0);
if (ret == 0)
return ret;
if (!sip_parse_addr(ct, dptr + *matchoff, &c, addr, limit, true))
return -1;
if (*c == ':') {
c++;
p = simple_strtoul(c, (char **)&c, 10);
if (p < 1024 || p > 65535)
return -1;
*port = htons(p);
} else
*port = htons(SIP_PORT);
if (dataoff)
*dataoff = c - dptr;
return 1;
}
static int ct_sip_parse_param(const struct nf_conn *ct, const char *dptr,
unsigned int dataoff, unsigned int datalen,
const char *name,
unsigned int *matchoff, unsigned int *matchlen)
{
const char *limit = dptr + datalen;
const char *start;
const char *end;
limit = ct_sip_header_search(dptr + dataoff, limit, ",", strlen(","));
if (!limit)
limit = dptr + datalen;
start = ct_sip_header_search(dptr + dataoff, limit, name, strlen(name));
if (!start)
return 0;
start += strlen(name);
end = ct_sip_header_search(start, limit, ";", strlen(";"));
if (!end)
end = limit;
*matchoff = start - dptr;
*matchlen = end - start;
return 1;
}
int ct_sip_parse_address_param(const struct nf_conn *ct, const char *dptr,
unsigned int dataoff, unsigned int datalen,
const char *name,
unsigned int *matchoff, unsigned int *matchlen,
union nf_inet_addr *addr, bool delim)
{
const char *limit = dptr + datalen;
const char *start, *end;
limit = ct_sip_header_search(dptr + dataoff, limit, ",", strlen(","));
if (!limit)
limit = dptr + datalen;
start = ct_sip_header_search(dptr + dataoff, limit, name, strlen(name));
if (!start)
return 0;
start += strlen(name);
if (!sip_parse_addr(ct, start, &end, addr, limit, delim))
return 0;
*matchoff = start - dptr;
*matchlen = end - start;
return 1;
}
int ct_sip_parse_numerical_param(const struct nf_conn *ct, const char *dptr,
unsigned int dataoff, unsigned int datalen,
const char *name,
unsigned int *matchoff, unsigned int *matchlen,
unsigned int *val)
{
const char *limit = dptr + datalen;
const char *start;
char *end;
limit = ct_sip_header_search(dptr + dataoff, limit, ",", strlen(","));
if (!limit)
limit = dptr + datalen;
start = ct_sip_header_search(dptr + dataoff, limit, name, strlen(name));
if (!start)
return 0;
start += strlen(name);
*val = simple_strtoul(start, &end, 0);
if (start == end)
return 0;
if (matchoff && matchlen) {
*matchoff = start - dptr;
*matchlen = end - start;
}
return 1;
}
static int ct_sip_parse_transport(struct nf_conn *ct, const char *dptr,
unsigned int dataoff, unsigned int datalen,
u8 *proto)
{
unsigned int matchoff, matchlen;
if (ct_sip_parse_param(ct, dptr, dataoff, datalen, "transport=",
&matchoff, &matchlen)) {
if (!strnicmp(dptr + matchoff, "TCP", strlen("TCP")))
*proto = IPPROTO_TCP;
else if (!strnicmp(dptr + matchoff, "UDP", strlen("UDP")))
*proto = IPPROTO_UDP;
else
return 0;
if (*proto != nf_ct_protonum(ct))
return 0;
} else
*proto = nf_ct_protonum(ct);
return 1;
}
static int sdp_parse_addr(const struct nf_conn *ct, const char *cp,
const char **endp, union nf_inet_addr *addr,
const char *limit)
{
const char *end;
int ret;
memset(addr, 0, sizeof(*addr));
switch (nf_ct_l3num(ct)) {
case AF_INET:
ret = in4_pton(cp, limit - cp, (u8 *)&addr->ip, -1, &end);
break;
case AF_INET6:
ret = in6_pton(cp, limit - cp, (u8 *)&addr->ip6, -1, &end);
break;
default:
BUG();
}
if (ret == 0)
return 0;
if (endp)
*endp = end;
return 1;
}
static int sdp_addr_len(const struct nf_conn *ct, const char *dptr,
const char *limit, int *shift)
{
union nf_inet_addr addr;
const char *aux = dptr;
if (!sdp_parse_addr(ct, dptr, &dptr, &addr, limit)) {
pr_debug("ip: %s parse failed.!\n", dptr);
return 0;
}
return dptr - aux;
}
static const char *ct_sdp_header_search(const char *dptr, const char *limit,
const char *needle, unsigned int len)
{
for (limit -= len; dptr < limit; dptr++) {
if (*dptr == '\r' || *dptr == '\n')
break;
if (strncmp(dptr, needle, len) == 0)
return dptr;
}
return NULL;
}
int ct_sip_get_sdp_header(const struct nf_conn *ct, const char *dptr,
unsigned int dataoff, unsigned int datalen,
enum sdp_header_types type,
enum sdp_header_types term,
unsigned int *matchoff, unsigned int *matchlen)
{
const struct sip_header *hdr = &ct_sdp_hdrs[type];
const struct sip_header *thdr = &ct_sdp_hdrs[term];
const char *start = dptr, *limit = dptr + datalen;
int shift = 0;
for (dptr += dataoff; dptr < limit; dptr++) {
if (*dptr != '\r' && *dptr != '\n')
continue;
if (++dptr >= limit)
break;
if (*(dptr - 1) == '\r' && *dptr == '\n') {
if (++dptr >= limit)
break;
}
if (term != SDP_HDR_UNSPEC &&
limit - dptr >= thdr->len &&
strnicmp(dptr, thdr->name, thdr->len) == 0)
break;
else if (limit - dptr >= hdr->len &&
strnicmp(dptr, hdr->name, hdr->len) == 0)
dptr += hdr->len;
else
continue;
*matchoff = dptr - start;
if (hdr->search) {
dptr = ct_sdp_header_search(dptr, limit, hdr->search,
hdr->slen);
if (!dptr)
return -1;
dptr += hdr->slen;
}
*matchlen = hdr->match_len(ct, dptr, limit, &shift);
if (!*matchlen)
return -1;
*matchoff = dptr - start + shift;
return 1;
}
return 0;
}
static int ct_sip_parse_sdp_addr(const struct nf_conn *ct, const char *dptr,
unsigned int dataoff, unsigned int datalen,
enum sdp_header_types type,
enum sdp_header_types term,
unsigned int *matchoff, unsigned int *matchlen,
union nf_inet_addr *addr)
{
int ret;
ret = ct_sip_get_sdp_header(ct, dptr, dataoff, datalen, type, term,
matchoff, matchlen);
if (ret <= 0)
return ret;
if (!sdp_parse_addr(ct, dptr + *matchoff, NULL, addr,
dptr + *matchoff + *matchlen))
return -1;
return 1;
}
static int refresh_signalling_expectation(struct nf_conn *ct,
union nf_inet_addr *addr,
u8 proto, __be16 port,
unsigned int expires)
{
struct nf_conn_help *help = nfct_help(ct);
struct nf_conntrack_expect *exp;
struct hlist_node *n, *next;
int found = 0;
spin_lock_bh(&nf_conntrack_lock);
hlist_for_each_entry_safe(exp, n, next, &help->expectations, lnode) {
if (exp->class != SIP_EXPECT_SIGNALLING ||
!nf_inet_addr_cmp(&exp->tuple.dst.u3, addr) ||
exp->tuple.dst.protonum != proto ||
exp->tuple.dst.u.udp.port != port)
continue;
if (!del_timer(&exp->timeout))
continue;
exp->flags &= ~NF_CT_EXPECT_INACTIVE;
exp->timeout.expires = jiffies + expires * HZ;
add_timer(&exp->timeout);
found = 1;
break;
}
spin_unlock_bh(&nf_conntrack_lock);
return found;
}
static void flush_expectations(struct nf_conn *ct, bool media)
{
struct nf_conn_help *help = nfct_help(ct);
struct nf_conntrack_expect *exp;
struct hlist_node *n, *next;
spin_lock_bh(&nf_conntrack_lock);
hlist_for_each_entry_safe(exp, n, next, &help->expectations, lnode) {
if ((exp->class != SIP_EXPECT_SIGNALLING) ^ media)
continue;
if (!del_timer(&exp->timeout))
continue;
nf_ct_unlink_expect(exp);
nf_ct_expect_put(exp);
if (!media)
break;
}
spin_unlock_bh(&nf_conntrack_lock);
}
static int set_expected_rtp_rtcp(struct sk_buff *skb, unsigned int dataoff,
const char **dptr, unsigned int *datalen,
union nf_inet_addr *daddr, __be16 port,
enum sip_expectation_classes class,
unsigned int mediaoff, unsigned int medialen)
{
struct nf_conntrack_expect *exp, *rtp_exp, *rtcp_exp;
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = nf_ct_get(skb, &ctinfo);
struct net *net = nf_ct_net(ct);
enum ip_conntrack_dir dir = CTINFO2DIR(ctinfo);
union nf_inet_addr *saddr;
struct nf_conntrack_tuple tuple;
int direct_rtp = 0, skip_expect = 0, ret = NF_DROP;
u_int16_t base_port;
__be16 rtp_port, rtcp_port;
typeof(nf_nat_sdp_port_hook) nf_nat_sdp_port;
typeof(nf_nat_sdp_media_hook) nf_nat_sdp_media;
saddr = NULL;
if (sip_direct_media) {
if (!nf_inet_addr_cmp(daddr, &ct->tuplehash[dir].tuple.src.u3))
return NF_ACCEPT;
saddr = &ct->tuplehash[!dir].tuple.src.u3;
}
memset(&tuple, 0, sizeof(tuple));
if (saddr)
tuple.src.u3 = *saddr;
tuple.src.l3num = nf_ct_l3num(ct);
tuple.dst.protonum = IPPROTO_UDP;
tuple.dst.u3 = *daddr;
tuple.dst.u.udp.port = port;
rcu_read_lock();
do {
exp = __nf_ct_expect_find(net, nf_ct_zone(ct), &tuple);
if (!exp || exp->master == ct ||
nfct_help(exp->master)->helper != nfct_help(ct)->helper ||
exp->class != class)
break;
#ifdef CONFIG_NF_NAT_NEEDED
if (exp->tuple.src.l3num == AF_INET && !direct_rtp &&
(exp->saved_ip != exp->tuple.dst.u3.ip ||
exp->saved_proto.udp.port != exp->tuple.dst.u.udp.port) &&
ct->status & IPS_NAT_MASK) {
daddr->ip = exp->saved_ip;
tuple.dst.u3.ip = exp->saved_ip;
tuple.dst.u.udp.port = exp->saved_proto.udp.port;
direct_rtp = 1;
} else
#endif
skip_expect = 1;
} while (!skip_expect);
rcu_read_unlock();
base_port = ntohs(tuple.dst.u.udp.port) & ~1;
rtp_port = htons(base_port);
rtcp_port = htons(base_port + 1);
if (direct_rtp) {
nf_nat_sdp_port = rcu_dereference(nf_nat_sdp_port_hook);
if (nf_nat_sdp_port &&
!nf_nat_sdp_port(skb, dataoff, dptr, datalen,
mediaoff, medialen, ntohs(rtp_port)))
goto err1;
}
if (skip_expect)
return NF_ACCEPT;
rtp_exp = nf_ct_expect_alloc(ct);
if (rtp_exp == NULL)
goto err1;
nf_ct_expect_init(rtp_exp, class, nf_ct_l3num(ct), saddr, daddr,
IPPROTO_UDP, NULL, &rtp_port);
rtcp_exp = nf_ct_expect_alloc(ct);
if (rtcp_exp == NULL)
goto err2;
nf_ct_expect_init(rtcp_exp, class, nf_ct_l3num(ct), saddr, daddr,
IPPROTO_UDP, NULL, &rtcp_port);
nf_nat_sdp_media = rcu_dereference(nf_nat_sdp_media_hook);
if (nf_nat_sdp_media && ct->status & IPS_NAT_MASK && !direct_rtp)
ret = nf_nat_sdp_media(skb, dataoff, dptr, datalen,
rtp_exp, rtcp_exp,
mediaoff, medialen, daddr);
else {
if (nf_ct_expect_related(rtp_exp) == 0) {
if (nf_ct_expect_related(rtcp_exp) != 0)
nf_ct_unexpect_related(rtp_exp);
else
ret = NF_ACCEPT;
}
}
nf_ct_expect_put(rtcp_exp);
err2:
nf_ct_expect_put(rtp_exp);
err1:
return ret;
}
static const struct sdp_media_type *sdp_media_type(const char *dptr,
unsigned int matchoff,
unsigned int matchlen)
{
const struct sdp_media_type *t;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(sdp_media_types); i++) {
t = &sdp_media_types[i];
if (matchlen < t->len ||
strncmp(dptr + matchoff, t->name, t->len))
continue;
return t;
}
return NULL;
}
static int process_sdp(struct sk_buff *skb, unsigned int dataoff,
const char **dptr, unsigned int *datalen,
unsigned int cseq)
{
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = nf_ct_get(skb, &ctinfo);
unsigned int matchoff, matchlen;
unsigned int mediaoff, medialen;
unsigned int sdpoff;
unsigned int caddr_len, maddr_len;
unsigned int i;
union nf_inet_addr caddr, maddr, rtp_addr;
unsigned int port;
enum sdp_header_types c_hdr;
const struct sdp_media_type *t;
int ret = NF_ACCEPT;
typeof(nf_nat_sdp_addr_hook) nf_nat_sdp_addr;
typeof(nf_nat_sdp_session_hook) nf_nat_sdp_session;
nf_nat_sdp_addr = rcu_dereference(nf_nat_sdp_addr_hook);
c_hdr = nf_ct_l3num(ct) == AF_INET ? SDP_HDR_CONNECTION_IP4 :
SDP_HDR_CONNECTION_IP6;
if (ct_sip_get_sdp_header(ct, *dptr, 0, *datalen,
SDP_HDR_VERSION, SDP_HDR_UNSPEC,
&matchoff, &matchlen) <= 0)
return NF_ACCEPT;
sdpoff = matchoff;
caddr_len = 0;
if (ct_sip_parse_sdp_addr(ct, *dptr, sdpoff, *datalen,
c_hdr, SDP_HDR_MEDIA,
&matchoff, &matchlen, &caddr) > 0)
caddr_len = matchlen;
mediaoff = sdpoff;
for (i = 0; i < ARRAY_SIZE(sdp_media_types); ) {
if (ct_sip_get_sdp_header(ct, *dptr, mediaoff, *datalen,
SDP_HDR_MEDIA, SDP_HDR_UNSPEC,
&mediaoff, &medialen) <= 0)
break;
t = sdp_media_type(*dptr, mediaoff, medialen);
if (!t) {
mediaoff += medialen;
continue;
}
mediaoff += t->len;
medialen -= t->len;
port = simple_strtoul(*dptr + mediaoff, NULL, 10);
if (port == 0)
continue;
if (port < 1024 || port > 65535)
return NF_DROP;
maddr_len = 0;
if (ct_sip_parse_sdp_addr(ct, *dptr, mediaoff, *datalen,
c_hdr, SDP_HDR_MEDIA,
&matchoff, &matchlen, &maddr) > 0) {
maddr_len = matchlen;
memcpy(&rtp_addr, &maddr, sizeof(rtp_addr));
} else if (caddr_len)
memcpy(&rtp_addr, &caddr, sizeof(rtp_addr));
else
return NF_DROP;
ret = set_expected_rtp_rtcp(skb, dataoff, dptr, datalen,
&rtp_addr, htons(port), t->class,
mediaoff, medialen);
if (ret != NF_ACCEPT)
return ret;
if (maddr_len && nf_nat_sdp_addr && ct->status & IPS_NAT_MASK) {
ret = nf_nat_sdp_addr(skb, dataoff, dptr, datalen,
mediaoff, c_hdr, SDP_HDR_MEDIA,
&rtp_addr);
if (ret != NF_ACCEPT)
return ret;
}
i++;
}
nf_nat_sdp_session = rcu_dereference(nf_nat_sdp_session_hook);
if (nf_nat_sdp_session && ct->status & IPS_NAT_MASK)
ret = nf_nat_sdp_session(skb, dataoff, dptr, datalen, sdpoff,
&rtp_addr);
return ret;
}
static int process_invite_response(struct sk_buff *skb, unsigned int dataoff,
const char **dptr, unsigned int *datalen,
unsigned int cseq, unsigned int code)
{
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = nf_ct_get(skb, &ctinfo);
struct nf_ct_sip_master *ct_sip_info = nfct_help_data(ct);
if ((code >= 100 && code <= 199) ||
(code >= 200 && code <= 299))
return process_sdp(skb, dataoff, dptr, datalen, cseq);
else if (ct_sip_info->invite_cseq == cseq)
flush_expectations(ct, true);
return NF_ACCEPT;
}
static int process_update_response(struct sk_buff *skb, unsigned int dataoff,
const char **dptr, unsigned int *datalen,
unsigned int cseq, unsigned int code)
{
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = nf_ct_get(skb, &ctinfo);
struct nf_ct_sip_master *ct_sip_info = nfct_help_data(ct);
if ((code >= 100 && code <= 199) ||
(code >= 200 && code <= 299))
return process_sdp(skb, dataoff, dptr, datalen, cseq);
else if (ct_sip_info->invite_cseq == cseq)
flush_expectations(ct, true);
return NF_ACCEPT;
}
static int process_prack_response(struct sk_buff *skb, unsigned int dataoff,
const char **dptr, unsigned int *datalen,
unsigned int cseq, unsigned int code)
{
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = nf_ct_get(skb, &ctinfo);
struct nf_ct_sip_master *ct_sip_info = nfct_help_data(ct);
if ((code >= 100 && code <= 199) ||
(code >= 200 && code <= 299))
return process_sdp(skb, dataoff, dptr, datalen, cseq);
else if (ct_sip_info->invite_cseq == cseq)
flush_expectations(ct, true);
return NF_ACCEPT;
}
static int process_invite_request(struct sk_buff *skb, unsigned int dataoff,
const char **dptr, unsigned int *datalen,
unsigned int cseq)
{
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = nf_ct_get(skb, &ctinfo);
struct nf_ct_sip_master *ct_sip_info = nfct_help_data(ct);
unsigned int ret;
flush_expectations(ct, true);
ret = process_sdp(skb, dataoff, dptr, datalen, cseq);
if (ret == NF_ACCEPT)
ct_sip_info->invite_cseq = cseq;
return ret;
}
static int process_bye_request(struct sk_buff *skb, unsigned int dataoff,
const char **dptr, unsigned int *datalen,
unsigned int cseq)
{
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = nf_ct_get(skb, &ctinfo);
flush_expectations(ct, true);
return NF_ACCEPT;
}
static int process_register_request(struct sk_buff *skb, unsigned int dataoff,
const char **dptr, unsigned int *datalen,
unsigned int cseq)
{
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = nf_ct_get(skb, &ctinfo);
struct nf_ct_sip_master *ct_sip_info = nfct_help_data(ct);
enum ip_conntrack_dir dir = CTINFO2DIR(ctinfo);
unsigned int matchoff, matchlen;
struct nf_conntrack_expect *exp;
union nf_inet_addr *saddr, daddr;
__be16 port;
u8 proto;
unsigned int expires = 0;
int ret;
typeof(nf_nat_sip_expect_hook) nf_nat_sip_expect;
if (ct->status & IPS_EXPECTED)
return NF_ACCEPT;
if (ct_sip_get_header(ct, *dptr, 0, *datalen, SIP_HDR_EXPIRES,
&matchoff, &matchlen) > 0)
expires = simple_strtoul(*dptr + matchoff, NULL, 10);
ret = ct_sip_parse_header_uri(ct, *dptr, NULL, *datalen,
SIP_HDR_CONTACT, NULL,
&matchoff, &matchlen, &daddr, &port);
if (ret < 0)
return NF_DROP;
else if (ret == 0)
return NF_ACCEPT;
if (!nf_inet_addr_cmp(&ct->tuplehash[dir].tuple.src.u3, &daddr))
return NF_ACCEPT;
if (ct_sip_parse_transport(ct, *dptr, matchoff + matchlen, *datalen,
&proto) == 0)
return NF_ACCEPT;
if (ct_sip_parse_numerical_param(ct, *dptr,
matchoff + matchlen, *datalen,
"expires=", NULL, NULL, &expires) < 0)
return NF_DROP;
if (expires == 0) {
ret = NF_ACCEPT;
goto store_cseq;
}
exp = nf_ct_expect_alloc(ct);
if (!exp)
return NF_DROP;
saddr = NULL;
if (sip_direct_signalling)
saddr = &ct->tuplehash[!dir].tuple.src.u3;
nf_ct_expect_init(exp, SIP_EXPECT_SIGNALLING, nf_ct_l3num(ct),
saddr, &daddr, proto, NULL, &port);
exp->timeout.expires = sip_timeout * HZ;
exp->helper = nfct_help(ct)->helper;
exp->flags = NF_CT_EXPECT_PERMANENT | NF_CT_EXPECT_INACTIVE;
nf_nat_sip_expect = rcu_dereference(nf_nat_sip_expect_hook);
if (nf_nat_sip_expect && ct->status & IPS_NAT_MASK)
ret = nf_nat_sip_expect(skb, dataoff, dptr, datalen, exp,
matchoff, matchlen);
else {
if (nf_ct_expect_related(exp) != 0)
ret = NF_DROP;
else
ret = NF_ACCEPT;
}
nf_ct_expect_put(exp);
store_cseq:
if (ret == NF_ACCEPT)
ct_sip_info->register_cseq = cseq;
return ret;
}
static int process_register_response(struct sk_buff *skb, unsigned int dataoff,
const char **dptr, unsigned int *datalen,
unsigned int cseq, unsigned int code)
{
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = nf_ct_get(skb, &ctinfo);
struct nf_ct_sip_master *ct_sip_info = nfct_help_data(ct);
enum ip_conntrack_dir dir = CTINFO2DIR(ctinfo);
union nf_inet_addr addr;
__be16 port;
u8 proto;
unsigned int matchoff, matchlen, coff = 0;
unsigned int expires = 0;
int in_contact = 0, ret;
if (ct_sip_info->register_cseq != cseq)
return NF_ACCEPT;
if (code >= 100 && code <= 199)
return NF_ACCEPT;
if (code < 200 || code > 299)
goto flush;
if (ct_sip_get_header(ct, *dptr, 0, *datalen, SIP_HDR_EXPIRES,
&matchoff, &matchlen) > 0)
expires = simple_strtoul(*dptr + matchoff, NULL, 10);
while (1) {
unsigned int c_expires = expires;
ret = ct_sip_parse_header_uri(ct, *dptr, &coff, *datalen,
SIP_HDR_CONTACT, &in_contact,
&matchoff, &matchlen,
&addr, &port);
if (ret < 0)
return NF_DROP;
else if (ret == 0)
break;
if (!nf_inet_addr_cmp(&ct->tuplehash[dir].tuple.dst.u3, &addr))
continue;
if (ct_sip_parse_transport(ct, *dptr, matchoff + matchlen,
*datalen, &proto) == 0)
continue;
ret = ct_sip_parse_numerical_param(ct, *dptr,
matchoff + matchlen,
*datalen, "expires=",
NULL, NULL, &c_expires);
if (ret < 0)
return NF_DROP;
if (c_expires == 0)
break;
if (refresh_signalling_expectation(ct, &addr, proto, port,
c_expires))
return NF_ACCEPT;
}
flush:
flush_expectations(ct, false);
return NF_ACCEPT;
}
static int process_sip_response(struct sk_buff *skb, unsigned int dataoff,
const char **dptr, unsigned int *datalen)
{
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = nf_ct_get(skb, &ctinfo);
unsigned int matchoff, matchlen, matchend;
unsigned int code, cseq, i;
if (*datalen < strlen("SIP/2.0 200"))
return NF_ACCEPT;
code = simple_strtoul(*dptr + strlen("SIP/2.0 "), NULL, 10);
if (!code)
return NF_DROP;
if (ct_sip_get_header(ct, *dptr, 0, *datalen, SIP_HDR_CSEQ,
&matchoff, &matchlen) <= 0)
return NF_DROP;
cseq = simple_strtoul(*dptr + matchoff, NULL, 10);
if (!cseq)
return NF_DROP;
matchend = matchoff + matchlen + 1;
for (i = 0; i < ARRAY_SIZE(sip_handlers); i++) {
const struct sip_handler *handler;
handler = &sip_handlers[i];
if (handler->response == NULL)
continue;
if (*datalen < matchend + handler->len ||
strnicmp(*dptr + matchend, handler->method, handler->len))
continue;
return handler->response(skb, dataoff, dptr, datalen,
cseq, code);
}
return NF_ACCEPT;
}
static int process_sip_request(struct sk_buff *skb, unsigned int dataoff,
const char **dptr, unsigned int *datalen)
{
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = nf_ct_get(skb, &ctinfo);
unsigned int matchoff, matchlen;
unsigned int cseq, i;
for (i = 0; i < ARRAY_SIZE(sip_handlers); i++) {
const struct sip_handler *handler;
handler = &sip_handlers[i];
if (handler->request == NULL)
continue;
if (*datalen < handler->len ||
strnicmp(*dptr, handler->method, handler->len))
continue;
if (ct_sip_get_header(ct, *dptr, 0, *datalen, SIP_HDR_CSEQ,
&matchoff, &matchlen) <= 0)
return NF_DROP;
cseq = simple_strtoul(*dptr + matchoff, NULL, 10);
if (!cseq)
return NF_DROP;
return handler->request(skb, dataoff, dptr, datalen, cseq);
}
return NF_ACCEPT;
}
static int process_sip_msg(struct sk_buff *skb, struct nf_conn *ct,
unsigned int dataoff, const char **dptr,
unsigned int *datalen)
{
typeof(nf_nat_sip_hook) nf_nat_sip;
int ret;
if (strnicmp(*dptr, "SIP/2.0 ", strlen("SIP/2.0 ")) != 0)
ret = process_sip_request(skb, dataoff, dptr, datalen);
else
ret = process_sip_response(skb, dataoff, dptr, datalen);
if (ret == NF_ACCEPT && ct->status & IPS_NAT_MASK) {
nf_nat_sip = rcu_dereference(nf_nat_sip_hook);
if (nf_nat_sip && !nf_nat_sip(skb, dataoff, dptr, datalen))
ret = NF_DROP;
}
return ret;
}
static int sip_help_tcp(struct sk_buff *skb, unsigned int protoff,
struct nf_conn *ct, enum ip_conntrack_info ctinfo)
{
struct tcphdr *th, _tcph;
unsigned int dataoff, datalen;
unsigned int matchoff, matchlen, clen;
unsigned int msglen, origlen;
const char *dptr, *end;
s16 diff, tdiff = 0;
int ret = NF_ACCEPT;
bool term;
typeof(nf_nat_sip_seq_adjust_hook) nf_nat_sip_seq_adjust;
if (ctinfo != IP_CT_ESTABLISHED &&
ctinfo != IP_CT_ESTABLISHED_REPLY)
return NF_ACCEPT;
th = skb_header_pointer(skb, protoff, sizeof(_tcph), &_tcph);
if (th == NULL)
return NF_ACCEPT;
dataoff = protoff + th->doff * 4;
if (dataoff >= skb->len)
return NF_ACCEPT;
nf_ct_refresh(ct, skb, sip_timeout * HZ);
if (unlikely(skb_linearize(skb)))
return NF_DROP;
dptr = skb->data + dataoff;
datalen = skb->len - dataoff;
if (datalen < strlen("SIP/2.0 200"))
return NF_ACCEPT;
while (1) {
if (ct_sip_get_header(ct, dptr, 0, datalen,
SIP_HDR_CONTENT_LENGTH,
&matchoff, &matchlen) <= 0)
break;
clen = simple_strtoul(dptr + matchoff, (char **)&end, 10);
if (dptr + matchoff == end)
break;
term = false;
for (; end + strlen("\r\n\r\n") <= dptr + datalen; end++) {
if (end[0] == '\r' && end[1] == '\n' &&
end[2] == '\r' && end[3] == '\n') {
term = true;
break;
}
}
if (!term)
break;
end += strlen("\r\n\r\n") + clen;
msglen = origlen = end - dptr;
if (msglen > datalen)
return NF_DROP;
ret = process_sip_msg(skb, ct, dataoff, &dptr, &msglen);
if (ret != NF_ACCEPT)
break;
diff = msglen - origlen;
tdiff += diff;
dataoff += msglen;
dptr += msglen;
datalen = datalen + diff - msglen;
}
if (ret == NF_ACCEPT && ct->status & IPS_NAT_MASK) {
nf_nat_sip_seq_adjust = rcu_dereference(nf_nat_sip_seq_adjust_hook);
if (nf_nat_sip_seq_adjust)
nf_nat_sip_seq_adjust(skb, tdiff);
}
return ret;
}
static int sip_help_udp(struct sk_buff *skb, unsigned int protoff,
struct nf_conn *ct, enum ip_conntrack_info ctinfo)
{
unsigned int dataoff, datalen;
const char *dptr;
dataoff = protoff + sizeof(struct udphdr);
if (dataoff >= skb->len)
return NF_ACCEPT;
nf_ct_refresh(ct, skb, sip_timeout * HZ);
if (unlikely(skb_linearize(skb)))
return NF_DROP;
dptr = skb->data + dataoff;
datalen = skb->len - dataoff;
if (datalen < strlen("SIP/2.0 200"))
return NF_ACCEPT;
return process_sip_msg(skb, ct, dataoff, &dptr, &datalen);
}
static void nf_conntrack_sip_fini(void)
{
int i, j;
for (i = 0; i < ports_c; i++) {
for (j = 0; j < ARRAY_SIZE(sip[i]); j++) {
if (sip[i][j].me == NULL)
continue;
nf_conntrack_helper_unregister(&sip[i][j]);
}
}
}
static int __init nf_conntrack_sip_init(void)
{
int i, j, ret;
if (ports_c == 0)
ports[ports_c++] = SIP_PORT;
for (i = 0; i < ports_c; i++) {
memset(&sip[i], 0, sizeof(sip[i]));
sip[i][0].tuple.src.l3num = AF_INET;
sip[i][0].tuple.dst.protonum = IPPROTO_UDP;
sip[i][0].help = sip_help_udp;
sip[i][1].tuple.src.l3num = AF_INET;
sip[i][1].tuple.dst.protonum = IPPROTO_TCP;
sip[i][1].help = sip_help_tcp;
sip[i][2].tuple.src.l3num = AF_INET6;
sip[i][2].tuple.dst.protonum = IPPROTO_UDP;
sip[i][2].help = sip_help_udp;
sip[i][3].tuple.src.l3num = AF_INET6;
sip[i][3].tuple.dst.protonum = IPPROTO_TCP;
sip[i][3].help = sip_help_tcp;
for (j = 0; j < ARRAY_SIZE(sip[i]); j++) {
sip[i][j].data_len = sizeof(struct nf_ct_sip_master);
sip[i][j].tuple.src.u.udp.port = htons(ports[i]);
sip[i][j].expect_policy = sip_exp_policy;
sip[i][j].expect_class_max = SIP_EXPECT_MAX;
sip[i][j].me = THIS_MODULE;
if (ports[i] == SIP_PORT)
sprintf(sip[i][j].name, "sip");
else
sprintf(sip[i][j].name, "sip-%u", i);
pr_debug("port #%u: %u\n", i, ports[i]);
ret = nf_conntrack_helper_register(&sip[i][j]);
if (ret) {
printk(KERN_ERR "nf_ct_sip: failed to register"
" helper for pf: %u port: %u\n",
sip[i][j].tuple.src.l3num, ports[i]);
nf_conntrack_sip_fini();
return ret;
}
}
}
return 0;
}
