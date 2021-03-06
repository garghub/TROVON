static int tftp_help(struct sk_buff *skb,
unsigned int protoff,
struct nf_conn *ct,
enum ip_conntrack_info ctinfo)
{
const struct tftphdr *tfh;
struct tftphdr _tftph;
struct nf_conntrack_expect *exp;
struct nf_conntrack_tuple *tuple;
unsigned int ret = NF_ACCEPT;
typeof(nf_nat_tftp_hook) nf_nat_tftp;
tfh = skb_header_pointer(skb, protoff + sizeof(struct udphdr),
sizeof(_tftph), &_tftph);
if (tfh == NULL)
return NF_ACCEPT;
switch (ntohs(tfh->opcode)) {
case TFTP_OPCODE_READ:
case TFTP_OPCODE_WRITE:
nf_ct_dump_tuple(&ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple);
nf_ct_dump_tuple(&ct->tuplehash[IP_CT_DIR_REPLY].tuple);
exp = nf_ct_expect_alloc(ct);
if (exp == NULL)
return NF_DROP;
tuple = &ct->tuplehash[IP_CT_DIR_REPLY].tuple;
nf_ct_expect_init(exp, NF_CT_EXPECT_CLASS_DEFAULT,
nf_ct_l3num(ct),
&tuple->src.u3, &tuple->dst.u3,
IPPROTO_UDP, NULL, &tuple->dst.u.udp.port);
pr_debug("expect: ");
nf_ct_dump_tuple(&exp->tuple);
nf_nat_tftp = rcu_dereference(nf_nat_tftp_hook);
if (nf_nat_tftp && ct->status & IPS_NAT_MASK)
ret = nf_nat_tftp(skb, ctinfo, exp);
else if (nf_ct_expect_related(exp) != 0)
ret = NF_DROP;
nf_ct_expect_put(exp);
break;
case TFTP_OPCODE_DATA:
case TFTP_OPCODE_ACK:
pr_debug("Data/ACK opcode\n");
break;
case TFTP_OPCODE_ERROR:
pr_debug("Error opcode\n");
break;
default:
pr_debug("Unknown opcode\n");
}
return ret;
}
static void nf_conntrack_tftp_fini(void)
{
int i, j;
for (i = 0; i < ports_c; i++) {
for (j = 0; j < 2; j++)
nf_conntrack_helper_unregister(&tftp[i][j]);
}
}
static int __init nf_conntrack_tftp_init(void)
{
int i, j, ret;
if (ports_c == 0)
ports[ports_c++] = TFTP_PORT;
for (i = 0; i < ports_c; i++) {
memset(&tftp[i], 0, sizeof(tftp[i]));
tftp[i][0].tuple.src.l3num = AF_INET;
tftp[i][1].tuple.src.l3num = AF_INET6;
for (j = 0; j < 2; j++) {
tftp[i][j].tuple.dst.protonum = IPPROTO_UDP;
tftp[i][j].tuple.src.u.udp.port = htons(ports[i]);
tftp[i][j].expect_policy = &tftp_exp_policy;
tftp[i][j].me = THIS_MODULE;
tftp[i][j].help = tftp_help;
if (ports[i] == TFTP_PORT)
sprintf(tftp[i][j].name, "tftp");
else
sprintf(tftp[i][j].name, "tftp-%u", i);
ret = nf_conntrack_helper_register(&tftp[i][j]);
if (ret) {
printk(KERN_ERR "nf_ct_tftp: failed to register"
" helper for pf: %u port: %u\n",
tftp[i][j].tuple.src.l3num, ports[i]);
nf_conntrack_tftp_fini();
return ret;
}
}
}
return 0;
}
