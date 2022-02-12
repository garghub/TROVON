static unsigned int help(struct sk_buff *skb,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned int matchoff,
unsigned int matchlen,
struct nf_conntrack_expect *exp)
{
char buffer[sizeof("4294967296 65635")];
struct nf_conn *ct = exp->master;
union nf_inet_addr newaddr;
u_int16_t port;
unsigned int ret;
newaddr = ct->tuplehash[IP_CT_DIR_REPLY].tuple.dst.u3;
exp->saved_proto.tcp.port = exp->tuple.dst.u.tcp.port;
exp->dir = IP_CT_DIR_REPLY;
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
snprintf(buffer, sizeof(buffer), "%u %u", ntohl(newaddr.ip), port);
pr_debug("nf_nat_irc: inserting '%s' == %pI4, port %u\n",
buffer, &newaddr.ip, port);
ret = nf_nat_mangle_tcp_packet(skb, ct, ctinfo, protoff, matchoff,
matchlen, buffer, strlen(buffer));
if (ret != NF_ACCEPT) {
nf_ct_helper_log(skb, ct, "cannot mangle packet");
nf_ct_unexpect_related(exp);
}
return ret;
}
static void __exit nf_nat_irc_fini(void)
{
RCU_INIT_POINTER(nf_nat_irc_hook, NULL);
synchronize_rcu();
}
static int __init nf_nat_irc_init(void)
{
BUG_ON(nf_nat_irc_hook != NULL);
RCU_INIT_POINTER(nf_nat_irc_hook, help);
return 0;
}
static int warn_set(const char *val, struct kernel_param *kp)
{
printk(KERN_INFO KBUILD_MODNAME
": kernel >= 2.6.10 only uses 'ports' for conntrack modules\n");
return 0;
}
