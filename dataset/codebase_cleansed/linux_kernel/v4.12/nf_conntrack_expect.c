void nf_ct_unlink_expect_report(struct nf_conntrack_expect *exp,
u32 portid, int report)
{
struct nf_conn_help *master_help = nfct_help(exp->master);
struct net *net = nf_ct_exp_net(exp);
NF_CT_ASSERT(master_help);
NF_CT_ASSERT(!timer_pending(&exp->timeout));
hlist_del_rcu(&exp->hnode);
net->ct.expect_count--;
hlist_del_rcu(&exp->lnode);
master_help->expecting[exp->class]--;
nf_ct_expect_event_report(IPEXP_DESTROY, exp, portid, report);
nf_ct_expect_put(exp);
NF_CT_STAT_INC(net, expect_delete);
}
static void nf_ct_expectation_timed_out(unsigned long ul_expect)
{
struct nf_conntrack_expect *exp = (void *)ul_expect;
spin_lock_bh(&nf_conntrack_expect_lock);
nf_ct_unlink_expect(exp);
spin_unlock_bh(&nf_conntrack_expect_lock);
nf_ct_expect_put(exp);
}
static unsigned int nf_ct_expect_dst_hash(const struct net *n, const struct nf_conntrack_tuple *tuple)
{
unsigned int hash, seed;
get_random_once(&nf_ct_expect_hashrnd, sizeof(nf_ct_expect_hashrnd));
seed = nf_ct_expect_hashrnd ^ net_hash_mix(n);
hash = jhash2(tuple->dst.u3.all, ARRAY_SIZE(tuple->dst.u3.all),
(((tuple->dst.protonum ^ tuple->src.l3num) << 16) |
(__force __u16)tuple->dst.u.all) ^ seed);
return reciprocal_scale(hash, nf_ct_expect_hsize);
}
static bool
nf_ct_exp_equal(const struct nf_conntrack_tuple *tuple,
const struct nf_conntrack_expect *i,
const struct nf_conntrack_zone *zone,
const struct net *net)
{
return nf_ct_tuple_mask_cmp(tuple, &i->tuple, &i->mask) &&
net_eq(net, nf_ct_net(i->master)) &&
nf_ct_zone_equal_any(i->master, zone);
}
bool nf_ct_remove_expect(struct nf_conntrack_expect *exp)
{
if (del_timer(&exp->timeout)) {
nf_ct_unlink_expect(exp);
nf_ct_expect_put(exp);
return true;
}
return false;
}
struct nf_conntrack_expect *
__nf_ct_expect_find(struct net *net,
const struct nf_conntrack_zone *zone,
const struct nf_conntrack_tuple *tuple)
{
struct nf_conntrack_expect *i;
unsigned int h;
if (!net->ct.expect_count)
return NULL;
h = nf_ct_expect_dst_hash(net, tuple);
hlist_for_each_entry_rcu(i, &nf_ct_expect_hash[h], hnode) {
if (nf_ct_exp_equal(tuple, i, zone, net))
return i;
}
return NULL;
}
struct nf_conntrack_expect *
nf_ct_expect_find_get(struct net *net,
const struct nf_conntrack_zone *zone,
const struct nf_conntrack_tuple *tuple)
{
struct nf_conntrack_expect *i;
rcu_read_lock();
i = __nf_ct_expect_find(net, zone, tuple);
if (i && !refcount_inc_not_zero(&i->use))
i = NULL;
rcu_read_unlock();
return i;
}
struct nf_conntrack_expect *
nf_ct_find_expectation(struct net *net,
const struct nf_conntrack_zone *zone,
const struct nf_conntrack_tuple *tuple)
{
struct nf_conntrack_expect *i, *exp = NULL;
unsigned int h;
if (!net->ct.expect_count)
return NULL;
h = nf_ct_expect_dst_hash(net, tuple);
hlist_for_each_entry(i, &nf_ct_expect_hash[h], hnode) {
if (!(i->flags & NF_CT_EXPECT_INACTIVE) &&
nf_ct_exp_equal(tuple, i, zone, net)) {
exp = i;
break;
}
}
if (!exp)
return NULL;
if (!nf_ct_is_confirmed(exp->master))
return NULL;
if (unlikely(nf_ct_is_dying(exp->master) ||
!atomic_inc_not_zero(&exp->master->ct_general.use)))
return NULL;
if (exp->flags & NF_CT_EXPECT_PERMANENT) {
refcount_inc(&exp->use);
return exp;
} else if (del_timer(&exp->timeout)) {
nf_ct_unlink_expect(exp);
return exp;
}
nf_ct_put(exp->master);
return NULL;
}
void nf_ct_remove_expectations(struct nf_conn *ct)
{
struct nf_conn_help *help = nfct_help(ct);
struct nf_conntrack_expect *exp;
struct hlist_node *next;
if (!help)
return;
spin_lock_bh(&nf_conntrack_expect_lock);
hlist_for_each_entry_safe(exp, next, &help->expectations, lnode) {
nf_ct_remove_expect(exp);
}
spin_unlock_bh(&nf_conntrack_expect_lock);
}
static inline int expect_clash(const struct nf_conntrack_expect *a,
const struct nf_conntrack_expect *b)
{
struct nf_conntrack_tuple_mask intersect_mask;
int count;
intersect_mask.src.u.all = a->mask.src.u.all & b->mask.src.u.all;
for (count = 0; count < NF_CT_TUPLE_L3SIZE; count++){
intersect_mask.src.u3.all[count] =
a->mask.src.u3.all[count] & b->mask.src.u3.all[count];
}
return nf_ct_tuple_mask_cmp(&a->tuple, &b->tuple, &intersect_mask) &&
net_eq(nf_ct_net(a->master), nf_ct_net(b->master)) &&
nf_ct_zone_equal_any(a->master, nf_ct_zone(b->master));
}
static inline int expect_matches(const struct nf_conntrack_expect *a,
const struct nf_conntrack_expect *b)
{
return a->master == b->master && a->class == b->class &&
nf_ct_tuple_equal(&a->tuple, &b->tuple) &&
nf_ct_tuple_mask_equal(&a->mask, &b->mask) &&
net_eq(nf_ct_net(a->master), nf_ct_net(b->master)) &&
nf_ct_zone_equal_any(a->master, nf_ct_zone(b->master));
}
void nf_ct_unexpect_related(struct nf_conntrack_expect *exp)
{
spin_lock_bh(&nf_conntrack_expect_lock);
nf_ct_remove_expect(exp);
spin_unlock_bh(&nf_conntrack_expect_lock);
}
struct nf_conntrack_expect *nf_ct_expect_alloc(struct nf_conn *me)
{
struct nf_conntrack_expect *new;
new = kmem_cache_alloc(nf_ct_expect_cachep, GFP_ATOMIC);
if (!new)
return NULL;
new->master = me;
refcount_set(&new->use, 1);
return new;
}
void nf_ct_expect_init(struct nf_conntrack_expect *exp, unsigned int class,
u_int8_t family,
const union nf_inet_addr *saddr,
const union nf_inet_addr *daddr,
u_int8_t proto, const __be16 *src, const __be16 *dst)
{
int len;
if (family == AF_INET)
len = 4;
else
len = 16;
exp->flags = 0;
exp->class = class;
exp->expectfn = NULL;
exp->helper = NULL;
exp->tuple.src.l3num = family;
exp->tuple.dst.protonum = proto;
if (saddr) {
memcpy(&exp->tuple.src.u3, saddr, len);
if (sizeof(exp->tuple.src.u3) > len)
memset((void *)&exp->tuple.src.u3 + len, 0x00,
sizeof(exp->tuple.src.u3) - len);
memset(&exp->mask.src.u3, 0xFF, len);
if (sizeof(exp->mask.src.u3) > len)
memset((void *)&exp->mask.src.u3 + len, 0x00,
sizeof(exp->mask.src.u3) - len);
} else {
memset(&exp->tuple.src.u3, 0x00, sizeof(exp->tuple.src.u3));
memset(&exp->mask.src.u3, 0x00, sizeof(exp->mask.src.u3));
}
if (src) {
exp->tuple.src.u.all = *src;
exp->mask.src.u.all = htons(0xFFFF);
} else {
exp->tuple.src.u.all = 0;
exp->mask.src.u.all = 0;
}
memcpy(&exp->tuple.dst.u3, daddr, len);
if (sizeof(exp->tuple.dst.u3) > len)
memset((void *)&exp->tuple.dst.u3 + len, 0x00,
sizeof(exp->tuple.dst.u3) - len);
exp->tuple.dst.u.all = *dst;
#ifdef CONFIG_NF_NAT_NEEDED
memset(&exp->saved_addr, 0, sizeof(exp->saved_addr));
memset(&exp->saved_proto, 0, sizeof(exp->saved_proto));
#endif
}
static void nf_ct_expect_free_rcu(struct rcu_head *head)
{
struct nf_conntrack_expect *exp;
exp = container_of(head, struct nf_conntrack_expect, rcu);
kmem_cache_free(nf_ct_expect_cachep, exp);
}
void nf_ct_expect_put(struct nf_conntrack_expect *exp)
{
if (refcount_dec_and_test(&exp->use))
call_rcu(&exp->rcu, nf_ct_expect_free_rcu);
}
static void nf_ct_expect_insert(struct nf_conntrack_expect *exp)
{
struct nf_conn_help *master_help = nfct_help(exp->master);
struct nf_conntrack_helper *helper;
struct net *net = nf_ct_exp_net(exp);
unsigned int h = nf_ct_expect_dst_hash(net, &exp->tuple);
refcount_add(2, &exp->use);
hlist_add_head_rcu(&exp->lnode, &master_help->expectations);
master_help->expecting[exp->class]++;
hlist_add_head_rcu(&exp->hnode, &nf_ct_expect_hash[h]);
net->ct.expect_count++;
setup_timer(&exp->timeout, nf_ct_expectation_timed_out,
(unsigned long)exp);
helper = rcu_dereference_protected(master_help->helper,
lockdep_is_held(&nf_conntrack_expect_lock));
if (helper) {
exp->timeout.expires = jiffies +
helper->expect_policy[exp->class].timeout * HZ;
}
add_timer(&exp->timeout);
NF_CT_STAT_INC(net, expect_create);
}
static void evict_oldest_expect(struct nf_conn *master,
struct nf_conntrack_expect *new)
{
struct nf_conn_help *master_help = nfct_help(master);
struct nf_conntrack_expect *exp, *last = NULL;
hlist_for_each_entry(exp, &master_help->expectations, lnode) {
if (exp->class == new->class)
last = exp;
}
if (last)
nf_ct_remove_expect(last);
}
static inline int __nf_ct_expect_check(struct nf_conntrack_expect *expect)
{
const struct nf_conntrack_expect_policy *p;
struct nf_conntrack_expect *i;
struct nf_conn *master = expect->master;
struct nf_conn_help *master_help = nfct_help(master);
struct nf_conntrack_helper *helper;
struct net *net = nf_ct_exp_net(expect);
struct hlist_node *next;
unsigned int h;
int ret = 0;
if (!master_help) {
ret = -ESHUTDOWN;
goto out;
}
h = nf_ct_expect_dst_hash(net, &expect->tuple);
hlist_for_each_entry_safe(i, next, &nf_ct_expect_hash[h], hnode) {
if (expect_matches(i, expect)) {
if (nf_ct_remove_expect(expect))
break;
} else if (expect_clash(i, expect)) {
ret = -EBUSY;
goto out;
}
}
helper = rcu_dereference_protected(master_help->helper,
lockdep_is_held(&nf_conntrack_expect_lock));
if (helper) {
p = &helper->expect_policy[expect->class];
if (p->max_expected &&
master_help->expecting[expect->class] >= p->max_expected) {
evict_oldest_expect(master, expect);
if (master_help->expecting[expect->class]
>= p->max_expected) {
ret = -EMFILE;
goto out;
}
}
}
if (net->ct.expect_count >= nf_ct_expect_max) {
net_warn_ratelimited("nf_conntrack: expectation table full\n");
ret = -EMFILE;
}
out:
return ret;
}
int nf_ct_expect_related_report(struct nf_conntrack_expect *expect,
u32 portid, int report)
{
int ret;
spin_lock_bh(&nf_conntrack_expect_lock);
ret = __nf_ct_expect_check(expect);
if (ret < 0)
goto out;
nf_ct_expect_insert(expect);
spin_unlock_bh(&nf_conntrack_expect_lock);
nf_ct_expect_event_report(IPEXP_NEW, expect, portid, report);
return 0;
out:
spin_unlock_bh(&nf_conntrack_expect_lock);
return ret;
}
static struct hlist_node *ct_expect_get_first(struct seq_file *seq)
{
struct ct_expect_iter_state *st = seq->private;
struct hlist_node *n;
for (st->bucket = 0; st->bucket < nf_ct_expect_hsize; st->bucket++) {
n = rcu_dereference(hlist_first_rcu(&nf_ct_expect_hash[st->bucket]));
if (n)
return n;
}
return NULL;
}
static struct hlist_node *ct_expect_get_next(struct seq_file *seq,
struct hlist_node *head)
{
struct ct_expect_iter_state *st = seq->private;
head = rcu_dereference(hlist_next_rcu(head));
while (head == NULL) {
if (++st->bucket >= nf_ct_expect_hsize)
return NULL;
head = rcu_dereference(hlist_first_rcu(&nf_ct_expect_hash[st->bucket]));
}
return head;
}
static struct hlist_node *ct_expect_get_idx(struct seq_file *seq, loff_t pos)
{
struct hlist_node *head = ct_expect_get_first(seq);
if (head)
while (pos && (head = ct_expect_get_next(seq, head)))
pos--;
return pos ? NULL : head;
}
static void *exp_seq_start(struct seq_file *seq, loff_t *pos)
__acquires(RCU)
{
rcu_read_lock();
return ct_expect_get_idx(seq, *pos);
}
static void *exp_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
(*pos)++;
return ct_expect_get_next(seq, v);
}
static void exp_seq_stop(struct seq_file *seq, void *v)
__releases(RCU)
{
rcu_read_unlock();
}
static int exp_seq_show(struct seq_file *s, void *v)
{
struct nf_conntrack_expect *expect;
struct nf_conntrack_helper *helper;
struct hlist_node *n = v;
char *delim = "";
expect = hlist_entry(n, struct nf_conntrack_expect, hnode);
if (expect->timeout.function)
seq_printf(s, "%ld ", timer_pending(&expect->timeout)
? (long)(expect->timeout.expires - jiffies)/HZ : 0);
else
seq_puts(s, "- ");
seq_printf(s, "l3proto = %u proto=%u ",
expect->tuple.src.l3num,
expect->tuple.dst.protonum);
print_tuple(s, &expect->tuple,
__nf_ct_l3proto_find(expect->tuple.src.l3num),
__nf_ct_l4proto_find(expect->tuple.src.l3num,
expect->tuple.dst.protonum));
if (expect->flags & NF_CT_EXPECT_PERMANENT) {
seq_puts(s, "PERMANENT");
delim = ",";
}
if (expect->flags & NF_CT_EXPECT_INACTIVE) {
seq_printf(s, "%sINACTIVE", delim);
delim = ",";
}
if (expect->flags & NF_CT_EXPECT_USERSPACE)
seq_printf(s, "%sUSERSPACE", delim);
helper = rcu_dereference(nfct_help(expect->master)->helper);
if (helper) {
seq_printf(s, "%s%s", expect->flags ? " " : "", helper->name);
if (helper->expect_policy[expect->class].name[0])
seq_printf(s, "/%s",
helper->expect_policy[expect->class].name);
}
seq_putc(s, '\n');
return 0;
}
static int exp_open(struct inode *inode, struct file *file)
{
return seq_open_net(inode, file, &exp_seq_ops,
sizeof(struct ct_expect_iter_state));
}
static int exp_proc_init(struct net *net)
{
#ifdef CONFIG_NF_CONNTRACK_PROCFS
struct proc_dir_entry *proc;
kuid_t root_uid;
kgid_t root_gid;
proc = proc_create("nf_conntrack_expect", 0440, net->proc_net,
&exp_file_ops);
if (!proc)
return -ENOMEM;
root_uid = make_kuid(net->user_ns, 0);
root_gid = make_kgid(net->user_ns, 0);
if (uid_valid(root_uid) && gid_valid(root_gid))
proc_set_user(proc, root_uid, root_gid);
#endif
return 0;
}
static void exp_proc_remove(struct net *net)
{
#ifdef CONFIG_NF_CONNTRACK_PROCFS
remove_proc_entry("nf_conntrack_expect", net->proc_net);
#endif
}
int nf_conntrack_expect_pernet_init(struct net *net)
{
net->ct.expect_count = 0;
return exp_proc_init(net);
}
void nf_conntrack_expect_pernet_fini(struct net *net)
{
exp_proc_remove(net);
}
int nf_conntrack_expect_init(void)
{
if (!nf_ct_expect_hsize) {
nf_ct_expect_hsize = nf_conntrack_htable_size / 256;
if (!nf_ct_expect_hsize)
nf_ct_expect_hsize = 1;
}
nf_ct_expect_max = nf_ct_expect_hsize * 4;
nf_ct_expect_cachep = kmem_cache_create("nf_conntrack_expect",
sizeof(struct nf_conntrack_expect),
0, 0, NULL);
if (!nf_ct_expect_cachep)
return -ENOMEM;
nf_ct_expect_hash = nf_ct_alloc_hashtable(&nf_ct_expect_hsize, 0);
if (!nf_ct_expect_hash) {
kmem_cache_destroy(nf_ct_expect_cachep);
return -ENOMEM;
}
return 0;
}
void nf_conntrack_expect_fini(void)
{
rcu_barrier();
kmem_cache_destroy(nf_ct_expect_cachep);
nf_ct_free_hashtable(nf_ct_expect_hash, nf_ct_expect_hsize);
}
