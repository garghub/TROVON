static unsigned int helper_hash(const struct nf_conntrack_tuple *tuple)
{
return (((tuple->src.l3num << 8) | tuple->dst.protonum) ^
(__force __u16)tuple->src.u.all) % nf_ct_helper_hsize;
}
static struct nf_conntrack_helper *
__nf_ct_helper_find(const struct nf_conntrack_tuple *tuple)
{
struct nf_conntrack_helper *helper;
struct nf_conntrack_tuple_mask mask = { .src.u.all = htons(0xFFFF) };
struct hlist_node *n;
unsigned int h;
if (!nf_ct_helper_count)
return NULL;
h = helper_hash(tuple);
hlist_for_each_entry_rcu(helper, n, &nf_ct_helper_hash[h], hnode) {
if (nf_ct_tuple_src_mask_cmp(tuple, &helper->tuple, &mask))
return helper;
}
return NULL;
}
struct nf_conntrack_helper *
__nf_conntrack_helper_find(const char *name, u16 l3num, u8 protonum)
{
struct nf_conntrack_helper *h;
struct hlist_node *n;
unsigned int i;
for (i = 0; i < nf_ct_helper_hsize; i++) {
hlist_for_each_entry_rcu(h, n, &nf_ct_helper_hash[i], hnode) {
if (!strcmp(h->name, name) &&
h->tuple.src.l3num == l3num &&
h->tuple.dst.protonum == protonum)
return h;
}
}
return NULL;
}
struct nf_conntrack_helper *
nf_conntrack_helper_try_module_get(const char *name, u16 l3num, u8 protonum)
{
struct nf_conntrack_helper *h;
h = __nf_conntrack_helper_find(name, l3num, protonum);
#ifdef CONFIG_MODULES
if (h == NULL) {
if (request_module("nfct-helper-%s", name) == 0)
h = __nf_conntrack_helper_find(name, l3num, protonum);
}
#endif
if (h != NULL && !try_module_get(h->me))
h = NULL;
return h;
}
struct nf_conn_help *nf_ct_helper_ext_add(struct nf_conn *ct, gfp_t gfp)
{
struct nf_conn_help *help;
help = nf_ct_ext_add(ct, NF_CT_EXT_HELPER, gfp);
if (help)
INIT_HLIST_HEAD(&help->expectations);
else
pr_debug("failed to add helper extension area");
return help;
}
int __nf_ct_try_assign_helper(struct nf_conn *ct, struct nf_conn *tmpl,
gfp_t flags)
{
struct nf_conntrack_helper *helper = NULL;
struct nf_conn_help *help;
int ret = 0;
if (tmpl != NULL) {
help = nfct_help(tmpl);
if (help != NULL)
helper = help->helper;
}
help = nfct_help(ct);
if (helper == NULL)
helper = __nf_ct_helper_find(&ct->tuplehash[IP_CT_DIR_REPLY].tuple);
if (helper == NULL) {
if (help)
RCU_INIT_POINTER(help->helper, NULL);
goto out;
}
if (help == NULL) {
help = nf_ct_helper_ext_add(ct, flags);
if (help == NULL) {
ret = -ENOMEM;
goto out;
}
} else {
memset(&help->help, 0, sizeof(help->help));
}
RCU_INIT_POINTER(help->helper, helper);
out:
return ret;
}
static inline int unhelp(struct nf_conntrack_tuple_hash *i,
const struct nf_conntrack_helper *me)
{
struct nf_conn *ct = nf_ct_tuplehash_to_ctrack(i);
struct nf_conn_help *help = nfct_help(ct);
if (help && rcu_dereference_protected(
help->helper,
lockdep_is_held(&nf_conntrack_lock)
) == me) {
nf_conntrack_event(IPCT_HELPER, ct);
RCU_INIT_POINTER(help->helper, NULL);
}
return 0;
}
void nf_ct_helper_destroy(struct nf_conn *ct)
{
struct nf_conn_help *help = nfct_help(ct);
struct nf_conntrack_helper *helper;
if (help) {
rcu_read_lock();
helper = rcu_dereference(help->helper);
if (helper && helper->destroy)
helper->destroy(ct);
rcu_read_unlock();
}
}
int nf_conntrack_helper_register(struct nf_conntrack_helper *me)
{
unsigned int h = helper_hash(&me->tuple);
BUG_ON(me->expect_policy == NULL);
BUG_ON(me->expect_class_max >= NF_CT_MAX_EXPECT_CLASSES);
BUG_ON(strlen(me->name) > NF_CT_HELPER_NAME_LEN - 1);
mutex_lock(&nf_ct_helper_mutex);
hlist_add_head_rcu(&me->hnode, &nf_ct_helper_hash[h]);
nf_ct_helper_count++;
mutex_unlock(&nf_ct_helper_mutex);
return 0;
}
static void __nf_conntrack_helper_unregister(struct nf_conntrack_helper *me,
struct net *net)
{
struct nf_conntrack_tuple_hash *h;
struct nf_conntrack_expect *exp;
const struct hlist_node *n, *next;
const struct hlist_nulls_node *nn;
unsigned int i;
for (i = 0; i < nf_ct_expect_hsize; i++) {
hlist_for_each_entry_safe(exp, n, next,
&net->ct.expect_hash[i], hnode) {
struct nf_conn_help *help = nfct_help(exp->master);
if ((rcu_dereference_protected(
help->helper,
lockdep_is_held(&nf_conntrack_lock)
) == me || exp->helper == me) &&
del_timer(&exp->timeout)) {
nf_ct_unlink_expect(exp);
nf_ct_expect_put(exp);
}
}
}
hlist_nulls_for_each_entry(h, nn, &net->ct.unconfirmed, hnnode)
unhelp(h, me);
for (i = 0; i < net->ct.htable_size; i++) {
hlist_nulls_for_each_entry(h, nn, &net->ct.hash[i], hnnode)
unhelp(h, me);
}
}
void nf_conntrack_helper_unregister(struct nf_conntrack_helper *me)
{
struct net *net;
mutex_lock(&nf_ct_helper_mutex);
hlist_del_rcu(&me->hnode);
nf_ct_helper_count--;
mutex_unlock(&nf_ct_helper_mutex);
synchronize_rcu();
rtnl_lock();
spin_lock_bh(&nf_conntrack_lock);
for_each_net(net)
__nf_conntrack_helper_unregister(me, net);
spin_unlock_bh(&nf_conntrack_lock);
rtnl_unlock();
}
int nf_conntrack_helper_init(void)
{
int err;
nf_ct_helper_hsize = 1;
nf_ct_helper_hash = nf_ct_alloc_hashtable(&nf_ct_helper_hsize, 0);
if (!nf_ct_helper_hash)
return -ENOMEM;
err = nf_ct_extend_register(&helper_extend);
if (err < 0)
goto err1;
return 0;
err1:
nf_ct_free_hashtable(nf_ct_helper_hash, nf_ct_helper_hsize);
return err;
}
void nf_conntrack_helper_fini(void)
{
nf_ct_extend_unregister(&helper_extend);
nf_ct_free_hashtable(nf_ct_helper_hash, nf_ct_helper_hsize);
}
