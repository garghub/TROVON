void nf_ct_gre_keymap_flush(struct net *net)
{
struct netns_proto_gre *net_gre = net_generic(net, proto_gre_net_id);
struct nf_ct_gre_keymap *km, *tmp;
write_lock_bh(&net_gre->keymap_lock);
list_for_each_entry_safe(km, tmp, &net_gre->keymap_list, list) {
list_del(&km->list);
kfree(km);
}
write_unlock_bh(&net_gre->keymap_lock);
}
static inline int gre_key_cmpfn(const struct nf_ct_gre_keymap *km,
const struct nf_conntrack_tuple *t)
{
return km->tuple.src.l3num == t->src.l3num &&
!memcmp(&km->tuple.src.u3, &t->src.u3, sizeof(t->src.u3)) &&
!memcmp(&km->tuple.dst.u3, &t->dst.u3, sizeof(t->dst.u3)) &&
km->tuple.dst.protonum == t->dst.protonum &&
km->tuple.dst.u.all == t->dst.u.all;
}
static __be16 gre_keymap_lookup(struct net *net, struct nf_conntrack_tuple *t)
{
struct netns_proto_gre *net_gre = net_generic(net, proto_gre_net_id);
struct nf_ct_gre_keymap *km;
__be16 key = 0;
read_lock_bh(&net_gre->keymap_lock);
list_for_each_entry(km, &net_gre->keymap_list, list) {
if (gre_key_cmpfn(km, t)) {
key = km->tuple.src.u.gre.key;
break;
}
}
read_unlock_bh(&net_gre->keymap_lock);
pr_debug("lookup src key 0x%x for ", key);
nf_ct_dump_tuple(t);
return key;
}
int nf_ct_gre_keymap_add(struct nf_conn *ct, enum ip_conntrack_dir dir,
struct nf_conntrack_tuple *t)
{
struct net *net = nf_ct_net(ct);
struct netns_proto_gre *net_gre = net_generic(net, proto_gre_net_id);
struct nf_conn_help *help = nfct_help(ct);
struct nf_ct_gre_keymap **kmp, *km;
kmp = &help->help.ct_pptp_info.keymap[dir];
if (*kmp) {
read_lock_bh(&net_gre->keymap_lock);
list_for_each_entry(km, &net_gre->keymap_list, list) {
if (gre_key_cmpfn(km, t) && km == *kmp) {
read_unlock_bh(&net_gre->keymap_lock);
return 0;
}
}
read_unlock_bh(&net_gre->keymap_lock);
pr_debug("trying to override keymap_%s for ct %p\n",
dir == IP_CT_DIR_REPLY ? "reply" : "orig", ct);
return -EEXIST;
}
km = kmalloc(sizeof(*km), GFP_ATOMIC);
if (!km)
return -ENOMEM;
memcpy(&km->tuple, t, sizeof(*t));
*kmp = km;
pr_debug("adding new entry %p: ", km);
nf_ct_dump_tuple(&km->tuple);
write_lock_bh(&net_gre->keymap_lock);
list_add_tail(&km->list, &net_gre->keymap_list);
write_unlock_bh(&net_gre->keymap_lock);
return 0;
}
void nf_ct_gre_keymap_destroy(struct nf_conn *ct)
{
struct net *net = nf_ct_net(ct);
struct netns_proto_gre *net_gre = net_generic(net, proto_gre_net_id);
struct nf_conn_help *help = nfct_help(ct);
enum ip_conntrack_dir dir;
pr_debug("entering for ct %p\n", ct);
write_lock_bh(&net_gre->keymap_lock);
for (dir = IP_CT_DIR_ORIGINAL; dir < IP_CT_DIR_MAX; dir++) {
if (help->help.ct_pptp_info.keymap[dir]) {
pr_debug("removing %p from list\n",
help->help.ct_pptp_info.keymap[dir]);
list_del(&help->help.ct_pptp_info.keymap[dir]->list);
kfree(help->help.ct_pptp_info.keymap[dir]);
help->help.ct_pptp_info.keymap[dir] = NULL;
}
}
write_unlock_bh(&net_gre->keymap_lock);
}
static bool gre_invert_tuple(struct nf_conntrack_tuple *tuple,
const struct nf_conntrack_tuple *orig)
{
tuple->dst.u.gre.key = orig->src.u.gre.key;
tuple->src.u.gre.key = orig->dst.u.gre.key;
return true;
}
static bool gre_pkt_to_tuple(const struct sk_buff *skb, unsigned int dataoff,
struct nf_conntrack_tuple *tuple)
{
struct net *net = dev_net(skb->dev ? skb->dev : skb_dst(skb)->dev);
const struct gre_hdr_pptp *pgrehdr;
struct gre_hdr_pptp _pgrehdr;
__be16 srckey;
const struct gre_hdr *grehdr;
struct gre_hdr _grehdr;
grehdr = skb_header_pointer(skb, dataoff, sizeof(_grehdr), &_grehdr);
if (!grehdr || grehdr->version != GRE_VERSION_PPTP) {
tuple->src.u.all = 0;
tuple->dst.u.all = 0;
return true;
}
pgrehdr = skb_header_pointer(skb, dataoff, 8, &_pgrehdr);
if (!pgrehdr)
return true;
if (ntohs(grehdr->protocol) != GRE_PROTOCOL_PPTP) {
pr_debug("GRE_VERSION_PPTP but unknown proto\n");
return false;
}
tuple->dst.u.gre.key = pgrehdr->call_id;
srckey = gre_keymap_lookup(net, tuple);
tuple->src.u.gre.key = srckey;
return true;
}
static int gre_print_tuple(struct seq_file *s,
const struct nf_conntrack_tuple *tuple)
{
return seq_printf(s, "srckey=0x%x dstkey=0x%x ",
ntohs(tuple->src.u.gre.key),
ntohs(tuple->dst.u.gre.key));
}
static int gre_print_conntrack(struct seq_file *s, struct nf_conn *ct)
{
return seq_printf(s, "timeout=%u, stream_timeout=%u ",
(ct->proto.gre.timeout / HZ),
(ct->proto.gre.stream_timeout / HZ));
}
static int gre_packet(struct nf_conn *ct,
const struct sk_buff *skb,
unsigned int dataoff,
enum ip_conntrack_info ctinfo,
u_int8_t pf,
unsigned int hooknum)
{
if (ct->status & IPS_SEEN_REPLY) {
nf_ct_refresh_acct(ct, ctinfo, skb,
ct->proto.gre.stream_timeout);
set_bit(IPS_ASSURED_BIT, &ct->status);
nf_conntrack_event_cache(IPCT_ASSURED, ct);
} else
nf_ct_refresh_acct(ct, ctinfo, skb,
ct->proto.gre.timeout);
return NF_ACCEPT;
}
static bool gre_new(struct nf_conn *ct, const struct sk_buff *skb,
unsigned int dataoff)
{
pr_debug(": ");
nf_ct_dump_tuple(&ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple);
ct->proto.gre.stream_timeout = GRE_STREAM_TIMEOUT;
ct->proto.gre.timeout = GRE_TIMEOUT;
return true;
}
static void gre_destroy(struct nf_conn *ct)
{
struct nf_conn *master = ct->master;
pr_debug(" entering\n");
if (!master)
pr_debug("no master !?!\n");
else
nf_ct_gre_keymap_destroy(master);
}
static int proto_gre_net_init(struct net *net)
{
struct netns_proto_gre *net_gre = net_generic(net, proto_gre_net_id);
rwlock_init(&net_gre->keymap_lock);
INIT_LIST_HEAD(&net_gre->keymap_list);
return 0;
}
static void proto_gre_net_exit(struct net *net)
{
nf_ct_gre_keymap_flush(net);
}
static int __init nf_ct_proto_gre_init(void)
{
int rv;
rv = nf_conntrack_l4proto_register(&nf_conntrack_l4proto_gre4);
if (rv < 0)
return rv;
rv = register_pernet_subsys(&proto_gre_net_ops);
if (rv < 0)
nf_conntrack_l4proto_unregister(&nf_conntrack_l4proto_gre4);
return rv;
}
static void __exit nf_ct_proto_gre_fini(void)
{
nf_conntrack_l4proto_unregister(&nf_conntrack_l4proto_gre4);
unregister_pernet_subsys(&proto_gre_net_ops);
}
