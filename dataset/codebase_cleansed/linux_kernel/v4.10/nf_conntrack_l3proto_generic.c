static bool generic_pkt_to_tuple(const struct sk_buff *skb, unsigned int nhoff,
struct nf_conntrack_tuple *tuple)
{
memset(&tuple->src.u3, 0, sizeof(tuple->src.u3));
memset(&tuple->dst.u3, 0, sizeof(tuple->dst.u3));
return true;
}
static bool generic_invert_tuple(struct nf_conntrack_tuple *tuple,
const struct nf_conntrack_tuple *orig)
{
memset(&tuple->src.u3, 0, sizeof(tuple->src.u3));
memset(&tuple->dst.u3, 0, sizeof(tuple->dst.u3));
return true;
}
static void generic_print_tuple(struct seq_file *s,
const struct nf_conntrack_tuple *tuple)
{
}
static int generic_get_l4proto(const struct sk_buff *skb, unsigned int nhoff,
unsigned int *dataoff, u_int8_t *protonum)
{
return -NF_ACCEPT;
}
