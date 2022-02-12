static int nf_nat_ftp_fmt_cmd(struct nf_conn *ct, enum nf_ct_ftp_type type,
char *buffer, size_t buflen,
union nf_inet_addr *addr, u16 port)
{
switch (type) {
case NF_CT_FTP_PORT:
case NF_CT_FTP_PASV:
return snprintf(buffer, buflen, "%u,%u,%u,%u,%u,%u",
((unsigned char *)&addr->ip)[0],
((unsigned char *)&addr->ip)[1],
((unsigned char *)&addr->ip)[2],
((unsigned char *)&addr->ip)[3],
port >> 8,
port & 0xFF);
case NF_CT_FTP_EPRT:
if (nf_ct_l3num(ct) == NFPROTO_IPV4)
return snprintf(buffer, buflen, "|1|%pI4|%u|",
&addr->ip, port);
else
return snprintf(buffer, buflen, "|2|%pI6|%u|",
&addr->ip6, port);
case NF_CT_FTP_EPSV:
return snprintf(buffer, buflen, "|||%u|", port);
}
return 0;
}
static unsigned int nf_nat_ftp(struct sk_buff *skb,
enum ip_conntrack_info ctinfo,
enum nf_ct_ftp_type type,
unsigned int protoff,
unsigned int matchoff,
unsigned int matchlen,
struct nf_conntrack_expect *exp)
{
union nf_inet_addr newaddr;
u_int16_t port;
int dir = CTINFO2DIR(ctinfo);
struct nf_conn *ct = exp->master;
char buffer[sizeof("|1||65535|") + INET6_ADDRSTRLEN];
unsigned int buflen;
pr_debug("FTP_NAT: type %i, off %u len %u\n", type, matchoff, matchlen);
newaddr = ct->tuplehash[!dir].tuple.dst.u3;
exp->saved_proto.tcp.port = exp->tuple.dst.u.tcp.port;
exp->dir = !dir;
exp->expectfn = nf_nat_follow_master;
for (port = ntohs(exp->saved_proto.tcp.port); port != 0; port++) {
int ret;
exp->tuple.dst.u.tcp.port = htons(port);
ret = nf_ct_expect_related(exp);
if (ret == 0)
break;
else if (ret != -EBUSY) {
port = 0;
break;
}
}
if (port == 0) {
nf_ct_helper_log(skb, ct, "all ports in use");
return NF_DROP;
}
buflen = nf_nat_ftp_fmt_cmd(ct, type, buffer, sizeof(buffer),
&newaddr, port);
if (!buflen)
goto out;
pr_debug("calling nf_nat_mangle_tcp_packet\n");
if (!nf_nat_mangle_tcp_packet(skb, ct, ctinfo, protoff, matchoff,
matchlen, buffer, buflen))
goto out;
return NF_ACCEPT;
out:
nf_ct_helper_log(skb, ct, "cannot mangle packet");
nf_ct_unexpect_related(exp);
return NF_DROP;
}
static void __exit nf_nat_ftp_fini(void)
{
RCU_INIT_POINTER(nf_nat_ftp_hook, NULL);
synchronize_rcu();
}
static int __init nf_nat_ftp_init(void)
{
BUG_ON(nf_nat_ftp_hook != NULL);
RCU_INIT_POINTER(nf_nat_ftp_hook, nf_nat_ftp);
return 0;
}
static int warn_set(const char *val, struct kernel_param *kp)
{
printk(KERN_INFO KBUILD_MODNAME
": kernel >= 2.6.10 only uses 'ports' for conntrack modules\n");
return 0;
}
