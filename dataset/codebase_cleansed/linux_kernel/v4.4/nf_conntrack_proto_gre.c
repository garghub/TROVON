static inline struct netns_proto_gre *gre_pernet(struct net *net)
{
return net_generic(net, proto_gre_net_id);
}
static void nf_ct_gre_keymap_flush(struct net *net)
{
struct netns_proto_gre *net_gre = gre_pernet(net);
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
struct netns_proto_gre *net_gre = gre_pernet(net);
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
struct netns_proto_gre *net_gre = gre_pernet(net);
struct nf_ct_pptp_master *ct_pptp_info = nfct_help_data(ct);
struct nf_ct_gre_keymap **kmp, *km;
kmp = &ct_pptp_info->keymap[dir];
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
struct netns_proto_gre *net_gre = gre_pernet(net);
struct nf_ct_pptp_master *ct_pptp_info = nfct_help_data(ct);
enum ip_conntrack_dir dir;
pr_debug("entering for ct %p\n", ct);
write_lock_bh(&net_gre->keymap_lock);
for (dir = IP_CT_DIR_ORIGINAL; dir < IP_CT_DIR_MAX; dir++) {
if (ct_pptp_info->keymap[dir]) {
pr_debug("removing %p from list\n",
ct_pptp_info->keymap[dir]);
list_del(&ct_pptp_info->keymap[dir]->list);
kfree(ct_pptp_info->keymap[dir]);
ct_pptp_info->keymap[dir] = NULL;
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
struct net *net, struct nf_conntrack_tuple *tuple)
{
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
static void gre_print_tuple(struct seq_file *s,
const struct nf_conntrack_tuple *tuple)
{
seq_printf(s, "srckey=0x%x dstkey=0x%x ",
ntohs(tuple->src.u.gre.key),
ntohs(tuple->dst.u.gre.key));
}
static void gre_print_conntrack(struct seq_file *s, struct nf_conn *ct)
{
seq_printf(s, "timeout=%u, stream_timeout=%u ",
(ct->proto.gre.timeout / HZ),
(ct->proto.gre.stream_timeout / HZ));
}
static unsigned int *gre_get_timeouts(struct net *net)
{
return gre_pernet(net)->gre_timeouts;
}
static int gre_packet(struct nf_conn *ct,
const struct sk_buff *skb,
unsigned int dataoff,
enum ip_conntrack_info ctinfo,
u_int8_t pf,
unsigned int hooknum,
unsigned int *timeouts)
{
if (ct->status & IPS_SEEN_REPLY) {
nf_ct_refresh_acct(ct, ctinfo, skb,
ct->proto.gre.stream_timeout);
if (!test_and_set_bit(IPS_ASSURED_BIT, &ct->status))
nf_conntrack_event_cache(IPCT_ASSURED, ct);
} else
nf_ct_refresh_acct(ct, ctinfo, skb,
ct->proto.gre.timeout);
return NF_ACCEPT;
}
static bool gre_new(struct nf_conn *ct, const struct sk_buff *skb,
unsigned int dataoff, unsigned int *timeouts)
{
pr_debug(": ");
nf_ct_dump_tuple(&ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple);
ct->proto.gre.stream_timeout = timeouts[GRE_CT_REPLIED];
ct->proto.gre.timeout = timeouts[GRE_CT_UNREPLIED];
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
static int gre_timeout_nlattr_to_obj(struct nlattr *tb[],
struct net *net, void *data)
{
unsigned int *timeouts = data;
struct netns_proto_gre *net_gre = gre_pernet(net);
timeouts[GRE_CT_UNREPLIED] = net_gre->gre_timeouts[GRE_CT_UNREPLIED];
timeouts[GRE_CT_REPLIED] = net_gre->gre_timeouts[GRE_CT_REPLIED];
if (tb[CTA_TIMEOUT_GRE_UNREPLIED]) {
timeouts[GRE_CT_UNREPLIED] =
ntohl(nla_get_be32(tb[CTA_TIMEOUT_GRE_UNREPLIED])) * HZ;
}
if (tb[CTA_TIMEOUT_GRE_REPLIED]) {
timeouts[GRE_CT_REPLIED] =
ntohl(nla_get_be32(tb[CTA_TIMEOUT_GRE_REPLIED])) * HZ;
}
return 0;
}
static int
gre_timeout_obj_to_nlattr(struct sk_buff *skb, const void *data)
{
const unsigned int *timeouts = data;
if (nla_put_be32(skb, CTA_TIMEOUT_GRE_UNREPLIED,
htonl(timeouts[GRE_CT_UNREPLIED] / HZ)) ||
nla_put_be32(skb, CTA_TIMEOUT_GRE_REPLIED,
htonl(timeouts[GRE_CT_REPLIED] / HZ)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -ENOSPC;
}
static int gre_init_net(struct net *net, u_int16_t proto)
{
struct netns_proto_gre *net_gre = gre_pernet(net);
int i;
rwlock_init(&net_gre->keymap_lock);
INIT_LIST_HEAD(&net_gre->keymap_list);
for (i = 0; i < GRE_CT_MAX; i++)
net_gre->gre_timeouts[i] = gre_timeouts[i];
return 0;
}
static int proto_gre_net_init(struct net *net)
{
int ret = 0;
ret = nf_ct_l4proto_pernet_register(net, &nf_conntrack_l4proto_gre4);
if (ret < 0)
pr_err("nf_conntrack_gre4: pernet registration failed.\n");
return ret;
}
static void proto_gre_net_exit(struct net *net)
{
nf_ct_l4proto_pernet_unregister(net, &nf_conntrack_l4proto_gre4);
nf_ct_gre_keymap_flush(net);
}
static int __init nf_ct_proto_gre_init(void)
{
int ret;
ret = register_pernet_subsys(&proto_gre_net_ops);
if (ret < 0)
goto out_pernet;
ret = nf_ct_l4proto_register(&nf_conntrack_l4proto_gre4);
if (ret < 0)
goto out_gre4;
return 0;
out_gre4:
unregister_pernet_subsys(&proto_gre_net_ops);
out_pernet:
return ret;
}
static void __exit nf_ct_proto_gre_fini(void)
{
nf_ct_l4proto_unregister(&nf_conntrack_l4proto_gre4);
unregister_pernet_subsys(&proto_gre_net_ops);
}
