static int
get_ipv6_addr(const char *src, size_t dlen, struct in6_addr *dst, u_int8_t term)
{
const char *end;
int ret = in6_pton(src, min_t(size_t, dlen, 0xffff), (u8 *)dst, term, &end);
if (ret > 0)
return (int)(end - src);
return 0;
}
static int try_number(const char *data, size_t dlen, u_int32_t array[],
int array_size, char sep, char term)
{
u_int32_t i, len;
memset(array, 0, sizeof(array[0])*array_size);
for (i = 0, len = 0; len < dlen && i < array_size; len++, data++) {
if (*data >= '0' && *data <= '9') {
array[i] = array[i]*10 + *data - '0';
}
else if (*data == sep)
i++;
else {
if ((*data == term || !term) && i == array_size - 1)
return len;
pr_debug("Char %u (got %u nums) `%u' unexpected\n",
len, i, *data);
return 0;
}
}
pr_debug("Failed to fill %u numbers separated by %c\n",
array_size, sep);
return 0;
}
static int try_rfc959(const char *data, size_t dlen,
struct nf_conntrack_man *cmd, char term,
unsigned int *offset)
{
int length;
u_int32_t array[6];
length = try_number(data, dlen, array, 6, ',', term);
if (length == 0)
return 0;
cmd->u3.ip = htonl((array[0] << 24) | (array[1] << 16) |
(array[2] << 8) | array[3]);
cmd->u.tcp.port = htons((array[4] << 8) | array[5]);
return length;
}
static int try_rfc1123(const char *data, size_t dlen,
struct nf_conntrack_man *cmd, char term,
unsigned int *offset)
{
int i;
for (i = 0; i < dlen; i++)
if (isdigit(data[i]))
break;
if (i == dlen)
return 0;
*offset += i;
return try_rfc959(data + i, dlen - i, cmd, 0, offset);
}
static int get_port(const char *data, int start, size_t dlen, char delim,
__be16 *port)
{
u_int16_t tmp_port = 0;
int i;
for (i = start; i < dlen; i++) {
if (data[i] == delim) {
if (tmp_port == 0)
break;
*port = htons(tmp_port);
pr_debug("get_port: return %d\n", tmp_port);
return i + 1;
}
else if (data[i] >= '0' && data[i] <= '9')
tmp_port = tmp_port*10 + data[i] - '0';
else {
pr_debug("get_port: invalid char.\n");
break;
}
}
return 0;
}
static int try_eprt(const char *data, size_t dlen, struct nf_conntrack_man *cmd,
char term, unsigned int *offset)
{
char delim;
int length;
if (dlen <= 3) {
pr_debug("EPRT: too short\n");
return 0;
}
delim = data[0];
if (isdigit(delim) || delim < 33 || delim > 126 || data[2] != delim) {
pr_debug("try_eprt: invalid delimitter.\n");
return 0;
}
if ((cmd->l3num == PF_INET && data[1] != '1') ||
(cmd->l3num == PF_INET6 && data[1] != '2')) {
pr_debug("EPRT: invalid protocol number.\n");
return 0;
}
pr_debug("EPRT: Got %c%c%c\n", delim, data[1], delim);
if (data[1] == '1') {
u_int32_t array[4];
length = try_number(data + 3, dlen - 3, array, 4, '.', delim);
if (length != 0)
cmd->u3.ip = htonl((array[0] << 24) | (array[1] << 16)
| (array[2] << 8) | array[3]);
} else {
length = get_ipv6_addr(data + 3, dlen - 3,
(struct in6_addr *)cmd->u3.ip6, delim);
}
if (length == 0)
return 0;
pr_debug("EPRT: Got IP address!\n");
return get_port(data, 3 + length + 1, dlen, delim, &cmd->u.tcp.port);
}
static int try_epsv_response(const char *data, size_t dlen,
struct nf_conntrack_man *cmd, char term,
unsigned int *offset)
{
char delim;
if (dlen <= 3) return 0;
delim = data[0];
if (isdigit(delim) || delim < 33 || delim > 126 ||
data[1] != delim || data[2] != delim)
return 0;
return get_port(data, 3, dlen, delim, &cmd->u.tcp.port);
}
static int find_pattern(const char *data, size_t dlen,
const char *pattern, size_t plen,
char skip, char term,
unsigned int *numoff,
unsigned int *numlen,
struct nf_conntrack_man *cmd,
int (*getnum)(const char *, size_t,
struct nf_conntrack_man *, char,
unsigned int *))
{
size_t i = plen;
pr_debug("find_pattern `%s': dlen = %Zu\n", pattern, dlen);
if (dlen == 0)
return 0;
if (dlen <= plen) {
if (strncasecmp(data, pattern, dlen) == 0)
return -1;
else return 0;
}
if (strncasecmp(data, pattern, plen) != 0) {
#if 0
size_t i;
pr_debug("ftp: string mismatch\n");
for (i = 0; i < plen; i++) {
pr_debug("ftp:char %u `%c'(%u) vs `%c'(%u)\n",
i, data[i], data[i],
pattern[i], pattern[i]);
}
#endif
return 0;
}
pr_debug("Pattern matches!\n");
if (skip) {
for (i = plen; data[i] != skip; i++)
if (i == dlen - 1) return -1;
i++;
}
pr_debug("Skipped up to `%c'!\n", skip);
*numoff = i;
*numlen = getnum(data + i, dlen - i, cmd, term, numoff);
if (!*numlen)
return -1;
pr_debug("Match succeeded!\n");
return 1;
}
static int find_nl_seq(u32 seq, const struct nf_ct_ftp_master *info, int dir)
{
unsigned int i;
for (i = 0; i < info->seq_aft_nl_num[dir]; i++)
if (info->seq_aft_nl[dir][i] == seq)
return 1;
return 0;
}
static void update_nl_seq(struct nf_conn *ct, u32 nl_seq,
struct nf_ct_ftp_master *info, int dir,
struct sk_buff *skb)
{
unsigned int i, oldest;
for (i = 0; i < info->seq_aft_nl_num[dir]; i++) {
if (info->seq_aft_nl[dir][i] == nl_seq)
return;
}
if (info->seq_aft_nl_num[dir] < NUM_SEQ_TO_REMEMBER) {
info->seq_aft_nl[dir][info->seq_aft_nl_num[dir]++] = nl_seq;
} else {
if (before(info->seq_aft_nl[dir][0], info->seq_aft_nl[dir][1]))
oldest = 0;
else
oldest = 1;
if (after(nl_seq, info->seq_aft_nl[dir][oldest]))
info->seq_aft_nl[dir][oldest] = nl_seq;
}
}
static int help(struct sk_buff *skb,
unsigned int protoff,
struct nf_conn *ct,
enum ip_conntrack_info ctinfo)
{
unsigned int dataoff, datalen;
const struct tcphdr *th;
struct tcphdr _tcph;
const char *fb_ptr;
int ret;
u32 seq;
int dir = CTINFO2DIR(ctinfo);
unsigned int uninitialized_var(matchlen), uninitialized_var(matchoff);
struct nf_ct_ftp_master *ct_ftp_info = nfct_help_data(ct);
struct nf_conntrack_expect *exp;
union nf_inet_addr *daddr;
struct nf_conntrack_man cmd = {};
unsigned int i;
int found = 0, ends_in_nl;
typeof(nf_nat_ftp_hook) nf_nat_ftp;
if (ctinfo != IP_CT_ESTABLISHED &&
ctinfo != IP_CT_ESTABLISHED_REPLY) {
pr_debug("ftp: Conntrackinfo = %u\n", ctinfo);
return NF_ACCEPT;
}
th = skb_header_pointer(skb, protoff, sizeof(_tcph), &_tcph);
if (th == NULL)
return NF_ACCEPT;
dataoff = protoff + th->doff * 4;
if (dataoff >= skb->len) {
pr_debug("ftp: dataoff(%u) >= skblen(%u)\n", dataoff,
skb->len);
return NF_ACCEPT;
}
datalen = skb->len - dataoff;
spin_lock_bh(&nf_ftp_lock);
fb_ptr = skb_header_pointer(skb, dataoff, datalen, ftp_buffer);
BUG_ON(fb_ptr == NULL);
ends_in_nl = (fb_ptr[datalen - 1] == '\n');
seq = ntohl(th->seq) + datalen;
if (!find_nl_seq(ntohl(th->seq), ct_ftp_info, dir)) {
if (unlikely(ct_ftp_info->flags[dir] & NF_CT_FTP_SEQ_PICKUP)) {
ct_ftp_info->flags[dir] ^= NF_CT_FTP_SEQ_PICKUP;
goto skip_nl_seq;
}
pr_debug("nf_conntrack_ftp: wrong seq pos %s(%u) or %s(%u)\n",
ct_ftp_info->seq_aft_nl_num[dir] > 0 ? "" : "(UNSET)",
ct_ftp_info->seq_aft_nl[dir][0],
ct_ftp_info->seq_aft_nl_num[dir] > 1 ? "" : "(UNSET)",
ct_ftp_info->seq_aft_nl[dir][1]);
ret = NF_ACCEPT;
goto out_update_nl;
}
skip_nl_seq:
cmd.l3num = nf_ct_l3num(ct);
memcpy(cmd.u3.all, &ct->tuplehash[dir].tuple.src.u3.all,
sizeof(cmd.u3.all));
for (i = 0; i < ARRAY_SIZE(search[dir]); i++) {
found = find_pattern(fb_ptr, datalen,
search[dir][i].pattern,
search[dir][i].plen,
search[dir][i].skip,
search[dir][i].term,
&matchoff, &matchlen,
&cmd,
search[dir][i].getnum);
if (found) break;
}
if (found == -1) {
nf_ct_helper_log(skb, ct, "partial matching of `%s'",
search[dir][i].pattern);
ret = NF_DROP;
goto out;
} else if (found == 0) {
ret = NF_ACCEPT;
goto out_update_nl;
}
pr_debug("conntrack_ftp: match `%.*s' (%u bytes at %u)\n",
matchlen, fb_ptr + matchoff,
matchlen, ntohl(th->seq) + matchoff);
exp = nf_ct_expect_alloc(ct);
if (exp == NULL) {
nf_ct_helper_log(skb, ct, "cannot alloc expectation");
ret = NF_DROP;
goto out;
}
daddr = &ct->tuplehash[!dir].tuple.dst.u3;
if ((cmd.l3num == nf_ct_l3num(ct)) &&
memcmp(&cmd.u3.all, &ct->tuplehash[dir].tuple.src.u3.all,
sizeof(cmd.u3.all))) {
if (cmd.l3num == PF_INET) {
pr_debug("NOT RECORDING: %pI4 != %pI4\n",
&cmd.u3.ip,
&ct->tuplehash[dir].tuple.src.u3.ip);
} else {
pr_debug("NOT RECORDING: %pI6 != %pI6\n",
cmd.u3.ip6,
ct->tuplehash[dir].tuple.src.u3.ip6);
}
if (!loose) {
ret = NF_ACCEPT;
goto out_put_expect;
}
daddr = &cmd.u3;
}
nf_ct_expect_init(exp, NF_CT_EXPECT_CLASS_DEFAULT, cmd.l3num,
&ct->tuplehash[!dir].tuple.src.u3, daddr,
IPPROTO_TCP, NULL, &cmd.u.tcp.port);
nf_nat_ftp = rcu_dereference(nf_nat_ftp_hook);
if (nf_nat_ftp && ct->status & IPS_NAT_MASK)
ret = nf_nat_ftp(skb, ctinfo, search[dir][i].ftptype,
protoff, matchoff, matchlen, exp);
else {
if (nf_ct_expect_related(exp) != 0) {
nf_ct_helper_log(skb, ct, "cannot add expectation");
ret = NF_DROP;
} else
ret = NF_ACCEPT;
}
out_put_expect:
nf_ct_expect_put(exp);
out_update_nl:
if (ends_in_nl)
update_nl_seq(ct, seq, ct_ftp_info, dir, skb);
out:
spin_unlock_bh(&nf_ftp_lock);
return ret;
}
static int nf_ct_ftp_from_nlattr(struct nlattr *attr, struct nf_conn *ct)
{
struct nf_ct_ftp_master *ftp = nfct_help_data(ct);
ftp->flags[IP_CT_DIR_ORIGINAL] |= NF_CT_FTP_SEQ_PICKUP;
ftp->flags[IP_CT_DIR_REPLY] |= NF_CT_FTP_SEQ_PICKUP;
return 0;
}
static void nf_conntrack_ftp_fini(void)
{
int i, j;
for (i = 0; i < ports_c; i++) {
for (j = 0; j < 2; j++) {
if (ftp[i][j].me == NULL)
continue;
pr_debug("unregistering helper for pf: %d port: %d\n",
ftp[i][j].tuple.src.l3num, ports[i]);
nf_conntrack_helper_unregister(&ftp[i][j]);
}
}
kfree(ftp_buffer);
}
static int __init nf_conntrack_ftp_init(void)
{
int i, j = -1, ret = 0;
ftp_buffer = kmalloc(65536, GFP_KERNEL);
if (!ftp_buffer)
return -ENOMEM;
if (ports_c == 0)
ports[ports_c++] = FTP_PORT;
for (i = 0; i < ports_c; i++) {
ftp[i][0].tuple.src.l3num = PF_INET;
ftp[i][1].tuple.src.l3num = PF_INET6;
for (j = 0; j < 2; j++) {
ftp[i][j].data_len = sizeof(struct nf_ct_ftp_master);
ftp[i][j].tuple.src.u.tcp.port = htons(ports[i]);
ftp[i][j].tuple.dst.protonum = IPPROTO_TCP;
ftp[i][j].expect_policy = &ftp_exp_policy;
ftp[i][j].me = THIS_MODULE;
ftp[i][j].help = help;
ftp[i][j].from_nlattr = nf_ct_ftp_from_nlattr;
if (ports[i] == FTP_PORT)
sprintf(ftp[i][j].name, "ftp");
else
sprintf(ftp[i][j].name, "ftp-%d", ports[i]);
pr_debug("registering helper for pf: %d port: %d\n",
ftp[i][j].tuple.src.l3num, ports[i]);
ret = nf_conntrack_helper_register(&ftp[i][j]);
if (ret) {
pr_err("failed to register helper for pf: %d port: %d\n",
ftp[i][j].tuple.src.l3num, ports[i]);
nf_conntrack_ftp_fini();
return ret;
}
}
}
return 0;
}
