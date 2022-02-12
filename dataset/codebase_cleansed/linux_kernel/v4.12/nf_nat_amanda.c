static unsigned int help(struct sk_buff *skb,
enum ip_conntrack_info ctinfo,
unsigned int protoff,
unsigned int matchoff,
unsigned int matchlen,
struct nf_conntrack_expect *exp)
{
char buffer[sizeof("65535")];
u_int16_t port;
exp->saved_proto.tcp.port = exp->tuple.dst.u.tcp.port;
exp->dir = IP_CT_DIR_ORIGINAL;
exp->expectfn = nf_nat_follow_master;
for (port = ntohs(exp->saved_proto.tcp.port); port != 0; port++) {
int res;
exp->tuple.dst.u.tcp.port = htons(port);
res = nf_ct_expect_related(exp);
if (res == 0)
break;
else if (res != -EBUSY) {
port = 0;
break;
}
}
if (port == 0) {
nf_ct_helper_log(skb, exp->master, "all ports in use");
return NF_DROP;
}
sprintf(buffer, "%u", port);
if (!nf_nat_mangle_udp_packet(skb, exp->master, ctinfo,
protoff, matchoff, matchlen,
buffer, strlen(buffer))) {
nf_ct_helper_log(skb, exp->master, "cannot mangle packet");
nf_ct_unexpect_related(exp);
return NF_DROP;
}
return NF_ACCEPT;
}
static void __exit nf_nat_amanda_fini(void)
{
RCU_INIT_POINTER(nf_nat_amanda_hook, NULL);
synchronize_rcu();
}
static int __init nf_nat_amanda_init(void)
{
BUG_ON(nf_nat_amanda_hook != NULL);
RCU_INIT_POINTER(nf_nat_amanda_hook, help);
return 0;
}
