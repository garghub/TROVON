int ipv4_skb_to_auditdata(struct sk_buff *skb,
struct common_audit_data *ad, u8 *proto)
{
int ret = 0;
struct iphdr *ih;
ih = ip_hdr(skb);
if (ih == NULL)
return -EINVAL;
ad->u.net->v4info.saddr = ih->saddr;
ad->u.net->v4info.daddr = ih->daddr;
if (proto)
*proto = ih->protocol;
if (ntohs(ih->frag_off) & IP_OFFSET)
return 0;
switch (ih->protocol) {
case IPPROTO_TCP: {
struct tcphdr *th = tcp_hdr(skb);
if (th == NULL)
break;
ad->u.net->sport = th->source;
ad->u.net->dport = th->dest;
break;
}
case IPPROTO_UDP: {
struct udphdr *uh = udp_hdr(skb);
if (uh == NULL)
break;
ad->u.net->sport = uh->source;
ad->u.net->dport = uh->dest;
break;
}
case IPPROTO_DCCP: {
struct dccp_hdr *dh = dccp_hdr(skb);
if (dh == NULL)
break;
ad->u.net->sport = dh->dccph_sport;
ad->u.net->dport = dh->dccph_dport;
break;
}
case IPPROTO_SCTP: {
struct sctphdr *sh = sctp_hdr(skb);
if (sh == NULL)
break;
ad->u.net->sport = sh->source;
ad->u.net->dport = sh->dest;
break;
}
default:
ret = -EINVAL;
}
return ret;
}
int ipv6_skb_to_auditdata(struct sk_buff *skb,
struct common_audit_data *ad, u8 *proto)
{
int offset, ret = 0;
struct ipv6hdr *ip6;
u8 nexthdr;
__be16 frag_off;
ip6 = ipv6_hdr(skb);
if (ip6 == NULL)
return -EINVAL;
ad->u.net->v6info.saddr = ip6->saddr;
ad->u.net->v6info.daddr = ip6->daddr;
ret = 0;
offset = skb_network_offset(skb);
offset += sizeof(*ip6);
nexthdr = ip6->nexthdr;
offset = ipv6_skip_exthdr(skb, offset, &nexthdr, &frag_off);
if (offset < 0)
return 0;
if (proto)
*proto = nexthdr;
switch (nexthdr) {
case IPPROTO_TCP: {
struct tcphdr _tcph, *th;
th = skb_header_pointer(skb, offset, sizeof(_tcph), &_tcph);
if (th == NULL)
break;
ad->u.net->sport = th->source;
ad->u.net->dport = th->dest;
break;
}
case IPPROTO_UDP: {
struct udphdr _udph, *uh;
uh = skb_header_pointer(skb, offset, sizeof(_udph), &_udph);
if (uh == NULL)
break;
ad->u.net->sport = uh->source;
ad->u.net->dport = uh->dest;
break;
}
case IPPROTO_DCCP: {
struct dccp_hdr _dccph, *dh;
dh = skb_header_pointer(skb, offset, sizeof(_dccph), &_dccph);
if (dh == NULL)
break;
ad->u.net->sport = dh->dccph_sport;
ad->u.net->dport = dh->dccph_dport;
break;
}
case IPPROTO_SCTP: {
struct sctphdr _sctph, *sh;
sh = skb_header_pointer(skb, offset, sizeof(_sctph), &_sctph);
if (sh == NULL)
break;
ad->u.net->sport = sh->source;
ad->u.net->dport = sh->dest;
break;
}
default:
ret = -EINVAL;
}
return ret;
}
static inline void print_ipv6_addr(struct audit_buffer *ab,
struct in6_addr *addr, __be16 port,
char *name1, char *name2)
{
if (!ipv6_addr_any(addr))
audit_log_format(ab, " %s=%pI6c", name1, addr);
if (port)
audit_log_format(ab, " %s=%d", name2, ntohs(port));
}
static inline void print_ipv4_addr(struct audit_buffer *ab, __be32 addr,
__be16 port, char *name1, char *name2)
{
if (addr)
audit_log_format(ab, " %s=%pI4", name1, &addr);
if (port)
audit_log_format(ab, " %s=%d", name2, ntohs(port));
}
static void dump_common_audit_data(struct audit_buffer *ab,
struct common_audit_data *a)
{
struct task_struct *tsk = current;
BUILD_BUG_ON(sizeof(a->u) > sizeof(void *)*2);
audit_log_format(ab, " pid=%d comm=", tsk->pid);
audit_log_untrustedstring(ab, tsk->comm);
switch (a->type) {
case LSM_AUDIT_DATA_NONE:
return;
case LSM_AUDIT_DATA_IPC:
audit_log_format(ab, " key=%d ", a->u.ipc_id);
break;
case LSM_AUDIT_DATA_CAP:
audit_log_format(ab, " capability=%d ", a->u.cap);
break;
case LSM_AUDIT_DATA_PATH: {
struct inode *inode;
audit_log_d_path(ab, " path=", &a->u.path);
inode = a->u.path.dentry->d_inode;
if (inode) {
audit_log_format(ab, " dev=");
audit_log_untrustedstring(ab, inode->i_sb->s_id);
audit_log_format(ab, " ino=%lu", inode->i_ino);
}
break;
}
case LSM_AUDIT_DATA_DENTRY: {
struct inode *inode;
audit_log_format(ab, " name=");
audit_log_untrustedstring(ab, a->u.dentry->d_name.name);
inode = a->u.dentry->d_inode;
if (inode) {
audit_log_format(ab, " dev=");
audit_log_untrustedstring(ab, inode->i_sb->s_id);
audit_log_format(ab, " ino=%lu", inode->i_ino);
}
break;
}
case LSM_AUDIT_DATA_INODE: {
struct dentry *dentry;
struct inode *inode;
inode = a->u.inode;
dentry = d_find_alias(inode);
if (dentry) {
audit_log_format(ab, " name=");
audit_log_untrustedstring(ab,
dentry->d_name.name);
dput(dentry);
}
audit_log_format(ab, " dev=");
audit_log_untrustedstring(ab, inode->i_sb->s_id);
audit_log_format(ab, " ino=%lu", inode->i_ino);
break;
}
case LSM_AUDIT_DATA_TASK:
tsk = a->u.tsk;
if (tsk && tsk->pid) {
audit_log_format(ab, " pid=%d comm=", tsk->pid);
audit_log_untrustedstring(ab, tsk->comm);
}
break;
case LSM_AUDIT_DATA_NET:
if (a->u.net->sk) {
struct sock *sk = a->u.net->sk;
struct unix_sock *u;
int len = 0;
char *p = NULL;
switch (sk->sk_family) {
case AF_INET: {
struct inet_sock *inet = inet_sk(sk);
print_ipv4_addr(ab, inet->inet_rcv_saddr,
inet->inet_sport,
"laddr", "lport");
print_ipv4_addr(ab, inet->inet_daddr,
inet->inet_dport,
"faddr", "fport");
break;
}
#if IS_ENABLED(CONFIG_IPV6)
case AF_INET6: {
struct inet_sock *inet = inet_sk(sk);
print_ipv6_addr(ab, &sk->sk_v6_rcv_saddr,
inet->inet_sport,
"laddr", "lport");
print_ipv6_addr(ab, &sk->sk_v6_daddr,
inet->inet_dport,
"faddr", "fport");
break;
}
#endif
case AF_UNIX:
u = unix_sk(sk);
if (u->path.dentry) {
audit_log_d_path(ab, " path=", &u->path);
break;
}
if (!u->addr)
break;
len = u->addr->len-sizeof(short);
p = &u->addr->name->sun_path[0];
audit_log_format(ab, " path=");
if (*p)
audit_log_untrustedstring(ab, p);
else
audit_log_n_hex(ab, p, len);
break;
}
}
switch (a->u.net->family) {
case AF_INET:
print_ipv4_addr(ab, a->u.net->v4info.saddr,
a->u.net->sport,
"saddr", "src");
print_ipv4_addr(ab, a->u.net->v4info.daddr,
a->u.net->dport,
"daddr", "dest");
break;
case AF_INET6:
print_ipv6_addr(ab, &a->u.net->v6info.saddr,
a->u.net->sport,
"saddr", "src");
print_ipv6_addr(ab, &a->u.net->v6info.daddr,
a->u.net->dport,
"daddr", "dest");
break;
}
if (a->u.net->netif > 0) {
struct net_device *dev;
dev = dev_get_by_index(&init_net, a->u.net->netif);
if (dev) {
audit_log_format(ab, " netif=%s", dev->name);
dev_put(dev);
}
}
break;
#ifdef CONFIG_KEYS
case LSM_AUDIT_DATA_KEY:
audit_log_format(ab, " key_serial=%u", a->u.key_struct.key);
if (a->u.key_struct.key_desc) {
audit_log_format(ab, " key_desc=");
audit_log_untrustedstring(ab, a->u.key_struct.key_desc);
}
break;
#endif
case LSM_AUDIT_DATA_KMOD:
audit_log_format(ab, " kmod=");
audit_log_untrustedstring(ab, a->u.kmod_name);
break;
}
}
void common_lsm_audit(struct common_audit_data *a,
void (*pre_audit)(struct audit_buffer *, void *),
void (*post_audit)(struct audit_buffer *, void *))
{
struct audit_buffer *ab;
if (a == NULL)
return;
ab = audit_log_start(current->audit_context, GFP_ATOMIC | __GFP_NOWARN,
AUDIT_AVC);
if (ab == NULL)
return;
if (pre_audit)
pre_audit(ab, a);
dump_common_audit_data(ab, a);
if (post_audit)
post_audit(ab, a);
audit_log_end(ab);
}
