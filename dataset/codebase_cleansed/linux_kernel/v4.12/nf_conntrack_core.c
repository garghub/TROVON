void nf_conntrack_lock(spinlock_t *lock) __acquires(lock)
{
spin_lock(lock);
while (unlikely(nf_conntrack_locks_all)) {
spin_unlock(lock);
smp_rmb();
spin_unlock_wait(&nf_conntrack_locks_all_lock);
spin_lock(lock);
}
}
static void nf_conntrack_double_unlock(unsigned int h1, unsigned int h2)
{
h1 %= CONNTRACK_LOCKS;
h2 %= CONNTRACK_LOCKS;
spin_unlock(&nf_conntrack_locks[h1]);
if (h1 != h2)
spin_unlock(&nf_conntrack_locks[h2]);
}
static bool nf_conntrack_double_lock(struct net *net, unsigned int h1,
unsigned int h2, unsigned int sequence)
{
h1 %= CONNTRACK_LOCKS;
h2 %= CONNTRACK_LOCKS;
if (h1 <= h2) {
nf_conntrack_lock(&nf_conntrack_locks[h1]);
if (h1 != h2)
spin_lock_nested(&nf_conntrack_locks[h2],
SINGLE_DEPTH_NESTING);
} else {
nf_conntrack_lock(&nf_conntrack_locks[h2]);
spin_lock_nested(&nf_conntrack_locks[h1],
SINGLE_DEPTH_NESTING);
}
if (read_seqcount_retry(&nf_conntrack_generation, sequence)) {
nf_conntrack_double_unlock(h1, h2);
return true;
}
return false;
}
static void nf_conntrack_all_lock(void)
{
int i;
spin_lock(&nf_conntrack_locks_all_lock);
nf_conntrack_locks_all = true;
smp_mb();
for (i = 0; i < CONNTRACK_LOCKS; i++) {
spin_unlock_wait(&nf_conntrack_locks[i]);
}
}
static void nf_conntrack_all_unlock(void)
{
smp_store_release(&nf_conntrack_locks_all, false);
spin_unlock(&nf_conntrack_locks_all_lock);
}
static u32 hash_conntrack_raw(const struct nf_conntrack_tuple *tuple,
const struct net *net)
{
unsigned int n;
u32 seed;
get_random_once(&nf_conntrack_hash_rnd, sizeof(nf_conntrack_hash_rnd));
seed = nf_conntrack_hash_rnd ^ net_hash_mix(net);
n = (sizeof(tuple->src) + sizeof(tuple->dst.u3)) / sizeof(u32);
return jhash2((u32 *)tuple, n, seed ^
(((__force __u16)tuple->dst.u.all << 16) |
tuple->dst.protonum));
}
static u32 scale_hash(u32 hash)
{
return reciprocal_scale(hash, nf_conntrack_htable_size);
}
static u32 __hash_conntrack(const struct net *net,
const struct nf_conntrack_tuple *tuple,
unsigned int size)
{
return reciprocal_scale(hash_conntrack_raw(tuple, net), size);
}
static u32 hash_conntrack(const struct net *net,
const struct nf_conntrack_tuple *tuple)
{
return scale_hash(hash_conntrack_raw(tuple, net));
}
bool
nf_ct_get_tuple(const struct sk_buff *skb,
unsigned int nhoff,
unsigned int dataoff,
u_int16_t l3num,
u_int8_t protonum,
struct net *net,
struct nf_conntrack_tuple *tuple,
const struct nf_conntrack_l3proto *l3proto,
const struct nf_conntrack_l4proto *l4proto)
{
memset(tuple, 0, sizeof(*tuple));
tuple->src.l3num = l3num;
if (l3proto->pkt_to_tuple(skb, nhoff, tuple) == 0)
return false;
tuple->dst.protonum = protonum;
tuple->dst.dir = IP_CT_DIR_ORIGINAL;
return l4proto->pkt_to_tuple(skb, dataoff, net, tuple);
}
bool nf_ct_get_tuplepr(const struct sk_buff *skb, unsigned int nhoff,
u_int16_t l3num,
struct net *net, struct nf_conntrack_tuple *tuple)
{
struct nf_conntrack_l3proto *l3proto;
struct nf_conntrack_l4proto *l4proto;
unsigned int protoff;
u_int8_t protonum;
int ret;
rcu_read_lock();
l3proto = __nf_ct_l3proto_find(l3num);
ret = l3proto->get_l4proto(skb, nhoff, &protoff, &protonum);
if (ret != NF_ACCEPT) {
rcu_read_unlock();
return false;
}
l4proto = __nf_ct_l4proto_find(l3num, protonum);
ret = nf_ct_get_tuple(skb, nhoff, protoff, l3num, protonum, net, tuple,
l3proto, l4proto);
rcu_read_unlock();
return ret;
}
bool
nf_ct_invert_tuple(struct nf_conntrack_tuple *inverse,
const struct nf_conntrack_tuple *orig,
const struct nf_conntrack_l3proto *l3proto,
const struct nf_conntrack_l4proto *l4proto)
{
memset(inverse, 0, sizeof(*inverse));
inverse->src.l3num = orig->src.l3num;
if (l3proto->invert_tuple(inverse, orig) == 0)
return false;
inverse->dst.dir = !orig->dst.dir;
inverse->dst.protonum = orig->dst.protonum;
return l4proto->invert_tuple(inverse, orig);
}
static void
clean_from_lists(struct nf_conn *ct)
{
pr_debug("clean_from_lists(%p)\n", ct);
hlist_nulls_del_rcu(&ct->tuplehash[IP_CT_DIR_ORIGINAL].hnnode);
hlist_nulls_del_rcu(&ct->tuplehash[IP_CT_DIR_REPLY].hnnode);
nf_ct_remove_expectations(ct);
}
static void nf_ct_add_to_dying_list(struct nf_conn *ct)
{
struct ct_pcpu *pcpu;
ct->cpu = smp_processor_id();
pcpu = per_cpu_ptr(nf_ct_net(ct)->ct.pcpu_lists, ct->cpu);
spin_lock(&pcpu->lock);
hlist_nulls_add_head(&ct->tuplehash[IP_CT_DIR_ORIGINAL].hnnode,
&pcpu->dying);
spin_unlock(&pcpu->lock);
}
static void nf_ct_add_to_unconfirmed_list(struct nf_conn *ct)
{
struct ct_pcpu *pcpu;
ct->cpu = smp_processor_id();
pcpu = per_cpu_ptr(nf_ct_net(ct)->ct.pcpu_lists, ct->cpu);
spin_lock(&pcpu->lock);
hlist_nulls_add_head(&ct->tuplehash[IP_CT_DIR_ORIGINAL].hnnode,
&pcpu->unconfirmed);
spin_unlock(&pcpu->lock);
}
static void nf_ct_del_from_dying_or_unconfirmed_list(struct nf_conn *ct)
{
struct ct_pcpu *pcpu;
pcpu = per_cpu_ptr(nf_ct_net(ct)->ct.pcpu_lists, ct->cpu);
spin_lock(&pcpu->lock);
BUG_ON(hlist_nulls_unhashed(&ct->tuplehash[IP_CT_DIR_ORIGINAL].hnnode));
hlist_nulls_del_rcu(&ct->tuplehash[IP_CT_DIR_ORIGINAL].hnnode);
spin_unlock(&pcpu->lock);
}
struct nf_conn *nf_ct_tmpl_alloc(struct net *net,
const struct nf_conntrack_zone *zone,
gfp_t flags)
{
struct nf_conn *tmpl, *p;
if (ARCH_KMALLOC_MINALIGN <= NFCT_INFOMASK) {
tmpl = kzalloc(sizeof(*tmpl) + NFCT_INFOMASK, flags);
if (!tmpl)
return NULL;
p = tmpl;
tmpl = (struct nf_conn *)NFCT_ALIGN((unsigned long)p);
if (tmpl != p) {
tmpl = (struct nf_conn *)NFCT_ALIGN((unsigned long)p);
tmpl->proto.tmpl_padto = (char *)tmpl - (char *)p;
}
} else {
tmpl = kzalloc(sizeof(*tmpl), flags);
if (!tmpl)
return NULL;
}
tmpl->status = IPS_TEMPLATE;
write_pnet(&tmpl->ct_net, net);
nf_ct_zone_add(tmpl, zone);
atomic_set(&tmpl->ct_general.use, 0);
return tmpl;
}
void nf_ct_tmpl_free(struct nf_conn *tmpl)
{
nf_ct_ext_destroy(tmpl);
nf_ct_ext_free(tmpl);
if (ARCH_KMALLOC_MINALIGN <= NFCT_INFOMASK)
kfree((char *)tmpl - tmpl->proto.tmpl_padto);
else
kfree(tmpl);
}
static void
destroy_conntrack(struct nf_conntrack *nfct)
{
struct nf_conn *ct = (struct nf_conn *)nfct;
struct nf_conntrack_l4proto *l4proto;
pr_debug("destroy_conntrack(%p)\n", ct);
NF_CT_ASSERT(atomic_read(&nfct->use) == 0);
if (unlikely(nf_ct_is_template(ct))) {
nf_ct_tmpl_free(ct);
return;
}
rcu_read_lock();
l4proto = __nf_ct_l4proto_find(nf_ct_l3num(ct), nf_ct_protonum(ct));
if (l4proto->destroy)
l4proto->destroy(ct);
rcu_read_unlock();
local_bh_disable();
nf_ct_remove_expectations(ct);
nf_ct_del_from_dying_or_unconfirmed_list(ct);
local_bh_enable();
if (ct->master)
nf_ct_put(ct->master);
pr_debug("destroy_conntrack: returning ct=%p to slab\n", ct);
nf_conntrack_free(ct);
}
static void nf_ct_delete_from_lists(struct nf_conn *ct)
{
struct net *net = nf_ct_net(ct);
unsigned int hash, reply_hash;
unsigned int sequence;
nf_ct_helper_destroy(ct);
local_bh_disable();
do {
sequence = read_seqcount_begin(&nf_conntrack_generation);
hash = hash_conntrack(net,
&ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple);
reply_hash = hash_conntrack(net,
&ct->tuplehash[IP_CT_DIR_REPLY].tuple);
} while (nf_conntrack_double_lock(net, hash, reply_hash, sequence));
clean_from_lists(ct);
nf_conntrack_double_unlock(hash, reply_hash);
nf_ct_add_to_dying_list(ct);
local_bh_enable();
}
bool nf_ct_delete(struct nf_conn *ct, u32 portid, int report)
{
struct nf_conn_tstamp *tstamp;
if (test_and_set_bit(IPS_DYING_BIT, &ct->status))
return false;
tstamp = nf_conn_tstamp_find(ct);
if (tstamp && tstamp->stop == 0)
tstamp->stop = ktime_get_real_ns();
if (nf_conntrack_event_report(IPCT_DESTROY, ct,
portid, report) < 0) {
nf_ct_delete_from_lists(ct);
nf_conntrack_ecache_delayed_work(nf_ct_net(ct));
return false;
}
nf_conntrack_ecache_work(nf_ct_net(ct));
nf_ct_delete_from_lists(ct);
nf_ct_put(ct);
return true;
}
static inline bool
nf_ct_key_equal(struct nf_conntrack_tuple_hash *h,
const struct nf_conntrack_tuple *tuple,
const struct nf_conntrack_zone *zone,
const struct net *net)
{
struct nf_conn *ct = nf_ct_tuplehash_to_ctrack(h);
return nf_ct_tuple_equal(tuple, &h->tuple) &&
nf_ct_zone_equal(ct, zone, NF_CT_DIRECTION(h)) &&
nf_ct_is_confirmed(ct) &&
net_eq(net, nf_ct_net(ct));
}
static void nf_ct_gc_expired(struct nf_conn *ct)
{
if (!atomic_inc_not_zero(&ct->ct_general.use))
return;
if (nf_ct_should_gc(ct))
nf_ct_kill(ct);
nf_ct_put(ct);
}
static struct nf_conntrack_tuple_hash *
____nf_conntrack_find(struct net *net, const struct nf_conntrack_zone *zone,
const struct nf_conntrack_tuple *tuple, u32 hash)
{
struct nf_conntrack_tuple_hash *h;
struct hlist_nulls_head *ct_hash;
struct hlist_nulls_node *n;
unsigned int bucket, hsize;
begin:
nf_conntrack_get_ht(&ct_hash, &hsize);
bucket = reciprocal_scale(hash, hsize);
hlist_nulls_for_each_entry_rcu(h, n, &ct_hash[bucket], hnnode) {
struct nf_conn *ct;
ct = nf_ct_tuplehash_to_ctrack(h);
if (nf_ct_is_expired(ct)) {
nf_ct_gc_expired(ct);
continue;
}
if (nf_ct_is_dying(ct))
continue;
if (nf_ct_key_equal(h, tuple, zone, net))
return h;
}
if (get_nulls_value(n) != bucket) {
NF_CT_STAT_INC_ATOMIC(net, search_restart);
goto begin;
}
return NULL;
}
static struct nf_conntrack_tuple_hash *
__nf_conntrack_find_get(struct net *net, const struct nf_conntrack_zone *zone,
const struct nf_conntrack_tuple *tuple, u32 hash)
{
struct nf_conntrack_tuple_hash *h;
struct nf_conn *ct;
rcu_read_lock();
begin:
h = ____nf_conntrack_find(net, zone, tuple, hash);
if (h) {
ct = nf_ct_tuplehash_to_ctrack(h);
if (unlikely(nf_ct_is_dying(ct) ||
!atomic_inc_not_zero(&ct->ct_general.use)))
h = NULL;
else {
if (unlikely(!nf_ct_key_equal(h, tuple, zone, net))) {
nf_ct_put(ct);
goto begin;
}
}
}
rcu_read_unlock();
return h;
}
struct nf_conntrack_tuple_hash *
nf_conntrack_find_get(struct net *net, const struct nf_conntrack_zone *zone,
const struct nf_conntrack_tuple *tuple)
{
return __nf_conntrack_find_get(net, zone, tuple,
hash_conntrack_raw(tuple, net));
}
static void __nf_conntrack_hash_insert(struct nf_conn *ct,
unsigned int hash,
unsigned int reply_hash)
{
hlist_nulls_add_head_rcu(&ct->tuplehash[IP_CT_DIR_ORIGINAL].hnnode,
&nf_conntrack_hash[hash]);
hlist_nulls_add_head_rcu(&ct->tuplehash[IP_CT_DIR_REPLY].hnnode,
&nf_conntrack_hash[reply_hash]);
}
int
nf_conntrack_hash_check_insert(struct nf_conn *ct)
{
const struct nf_conntrack_zone *zone;
struct net *net = nf_ct_net(ct);
unsigned int hash, reply_hash;
struct nf_conntrack_tuple_hash *h;
struct hlist_nulls_node *n;
unsigned int sequence;
zone = nf_ct_zone(ct);
local_bh_disable();
do {
sequence = read_seqcount_begin(&nf_conntrack_generation);
hash = hash_conntrack(net,
&ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple);
reply_hash = hash_conntrack(net,
&ct->tuplehash[IP_CT_DIR_REPLY].tuple);
} while (nf_conntrack_double_lock(net, hash, reply_hash, sequence));
hlist_nulls_for_each_entry(h, n, &nf_conntrack_hash[hash], hnnode)
if (nf_ct_key_equal(h, &ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple,
zone, net))
goto out;
hlist_nulls_for_each_entry(h, n, &nf_conntrack_hash[reply_hash], hnnode)
if (nf_ct_key_equal(h, &ct->tuplehash[IP_CT_DIR_REPLY].tuple,
zone, net))
goto out;
smp_wmb();
atomic_set(&ct->ct_general.use, 2);
__nf_conntrack_hash_insert(ct, hash, reply_hash);
nf_conntrack_double_unlock(hash, reply_hash);
NF_CT_STAT_INC(net, insert);
local_bh_enable();
return 0;
out:
nf_conntrack_double_unlock(hash, reply_hash);
NF_CT_STAT_INC(net, insert_failed);
local_bh_enable();
return -EEXIST;
}
static inline void nf_ct_acct_update(struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int len)
{
struct nf_conn_acct *acct;
acct = nf_conn_acct_find(ct);
if (acct) {
struct nf_conn_counter *counter = acct->counter;
atomic64_inc(&counter[CTINFO2DIR(ctinfo)].packets);
atomic64_add(len, &counter[CTINFO2DIR(ctinfo)].bytes);
}
}
static void nf_ct_acct_merge(struct nf_conn *ct, enum ip_conntrack_info ctinfo,
const struct nf_conn *loser_ct)
{
struct nf_conn_acct *acct;
acct = nf_conn_acct_find(loser_ct);
if (acct) {
struct nf_conn_counter *counter = acct->counter;
unsigned int bytes;
bytes = atomic64_read(&counter[CTINFO2DIR(ctinfo)].bytes);
nf_ct_acct_update(ct, ctinfo, bytes);
}
}
static int nf_ct_resolve_clash(struct net *net, struct sk_buff *skb,
enum ip_conntrack_info ctinfo,
struct nf_conntrack_tuple_hash *h)
{
struct nf_conn *ct = nf_ct_tuplehash_to_ctrack(h);
struct nf_conntrack_l4proto *l4proto;
l4proto = __nf_ct_l4proto_find(nf_ct_l3num(ct), nf_ct_protonum(ct));
if (l4proto->allow_clash &&
((ct->status & IPS_NAT_DONE_MASK) == 0) &&
!nf_ct_is_dying(ct) &&
atomic_inc_not_zero(&ct->ct_general.use)) {
enum ip_conntrack_info oldinfo;
struct nf_conn *loser_ct = nf_ct_get(skb, &oldinfo);
nf_ct_acct_merge(ct, ctinfo, loser_ct);
nf_conntrack_put(&loser_ct->ct_general);
nf_ct_set(skb, ct, oldinfo);
return NF_ACCEPT;
}
NF_CT_STAT_INC(net, drop);
return NF_DROP;
}
int
__nf_conntrack_confirm(struct sk_buff *skb)
{
const struct nf_conntrack_zone *zone;
unsigned int hash, reply_hash;
struct nf_conntrack_tuple_hash *h;
struct nf_conn *ct;
struct nf_conn_help *help;
struct nf_conn_tstamp *tstamp;
struct hlist_nulls_node *n;
enum ip_conntrack_info ctinfo;
struct net *net;
unsigned int sequence;
int ret = NF_DROP;
ct = nf_ct_get(skb, &ctinfo);
net = nf_ct_net(ct);
if (CTINFO2DIR(ctinfo) != IP_CT_DIR_ORIGINAL)
return NF_ACCEPT;
zone = nf_ct_zone(ct);
local_bh_disable();
do {
sequence = read_seqcount_begin(&nf_conntrack_generation);
hash = *(unsigned long *)&ct->tuplehash[IP_CT_DIR_REPLY].hnnode.pprev;
hash = scale_hash(hash);
reply_hash = hash_conntrack(net,
&ct->tuplehash[IP_CT_DIR_REPLY].tuple);
} while (nf_conntrack_double_lock(net, hash, reply_hash, sequence));
NF_CT_ASSERT(!nf_ct_is_confirmed(ct));
pr_debug("Confirming conntrack %p\n", ct);
nf_ct_del_from_dying_or_unconfirmed_list(ct);
if (unlikely(nf_ct_is_dying(ct))) {
nf_ct_add_to_dying_list(ct);
goto dying;
}
hlist_nulls_for_each_entry(h, n, &nf_conntrack_hash[hash], hnnode)
if (nf_ct_key_equal(h, &ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple,
zone, net))
goto out;
hlist_nulls_for_each_entry(h, n, &nf_conntrack_hash[reply_hash], hnnode)
if (nf_ct_key_equal(h, &ct->tuplehash[IP_CT_DIR_REPLY].tuple,
zone, net))
goto out;
ct->timeout += nfct_time_stamp;
atomic_inc(&ct->ct_general.use);
ct->status |= IPS_CONFIRMED;
tstamp = nf_conn_tstamp_find(ct);
if (tstamp) {
if (skb->tstamp == 0)
__net_timestamp(skb);
tstamp->start = ktime_to_ns(skb->tstamp);
}
__nf_conntrack_hash_insert(ct, hash, reply_hash);
nf_conntrack_double_unlock(hash, reply_hash);
local_bh_enable();
help = nfct_help(ct);
if (help && help->helper)
nf_conntrack_event_cache(IPCT_HELPER, ct);
nf_conntrack_event_cache(master_ct(ct) ?
IPCT_RELATED : IPCT_NEW, ct);
return NF_ACCEPT;
out:
nf_ct_add_to_dying_list(ct);
ret = nf_ct_resolve_clash(net, skb, ctinfo, h);
dying:
nf_conntrack_double_unlock(hash, reply_hash);
NF_CT_STAT_INC(net, insert_failed);
local_bh_enable();
return ret;
}
int
nf_conntrack_tuple_taken(const struct nf_conntrack_tuple *tuple,
const struct nf_conn *ignored_conntrack)
{
struct net *net = nf_ct_net(ignored_conntrack);
const struct nf_conntrack_zone *zone;
struct nf_conntrack_tuple_hash *h;
struct hlist_nulls_head *ct_hash;
unsigned int hash, hsize;
struct hlist_nulls_node *n;
struct nf_conn *ct;
zone = nf_ct_zone(ignored_conntrack);
rcu_read_lock();
begin:
nf_conntrack_get_ht(&ct_hash, &hsize);
hash = __hash_conntrack(net, tuple, hsize);
hlist_nulls_for_each_entry_rcu(h, n, &ct_hash[hash], hnnode) {
ct = nf_ct_tuplehash_to_ctrack(h);
if (ct == ignored_conntrack)
continue;
if (nf_ct_is_expired(ct)) {
nf_ct_gc_expired(ct);
continue;
}
if (nf_ct_key_equal(h, tuple, zone, net)) {
NF_CT_STAT_INC_ATOMIC(net, found);
rcu_read_unlock();
return 1;
}
}
if (get_nulls_value(n) != hash) {
NF_CT_STAT_INC_ATOMIC(net, search_restart);
goto begin;
}
rcu_read_unlock();
return 0;
}
static unsigned int early_drop_list(struct net *net,
struct hlist_nulls_head *head)
{
struct nf_conntrack_tuple_hash *h;
struct hlist_nulls_node *n;
unsigned int drops = 0;
struct nf_conn *tmp;
hlist_nulls_for_each_entry_rcu(h, n, head, hnnode) {
tmp = nf_ct_tuplehash_to_ctrack(h);
if (nf_ct_is_expired(tmp)) {
nf_ct_gc_expired(tmp);
continue;
}
if (test_bit(IPS_ASSURED_BIT, &tmp->status) ||
!net_eq(nf_ct_net(tmp), net) ||
nf_ct_is_dying(tmp))
continue;
if (!atomic_inc_not_zero(&tmp->ct_general.use))
continue;
if (net_eq(nf_ct_net(tmp), net) &&
nf_ct_is_confirmed(tmp) &&
nf_ct_delete(tmp, 0, 0))
drops++;
nf_ct_put(tmp);
}
return drops;
}
static noinline int early_drop(struct net *net, unsigned int _hash)
{
unsigned int i;
for (i = 0; i < NF_CT_EVICTION_RANGE; i++) {
struct hlist_nulls_head *ct_hash;
unsigned int hash, hsize, drops;
rcu_read_lock();
nf_conntrack_get_ht(&ct_hash, &hsize);
hash = reciprocal_scale(_hash++, hsize);
drops = early_drop_list(net, &ct_hash[hash]);
rcu_read_unlock();
if (drops) {
NF_CT_STAT_ADD_ATOMIC(net, early_drop, drops);
return true;
}
}
return false;
}
static bool gc_worker_skip_ct(const struct nf_conn *ct)
{
return !nf_ct_is_confirmed(ct) || nf_ct_is_dying(ct);
}
static bool gc_worker_can_early_drop(const struct nf_conn *ct)
{
const struct nf_conntrack_l4proto *l4proto;
if (!test_bit(IPS_ASSURED_BIT, &ct->status))
return true;
l4proto = __nf_ct_l4proto_find(nf_ct_l3num(ct), nf_ct_protonum(ct));
if (l4proto->can_early_drop && l4proto->can_early_drop(ct))
return true;
return false;
}
static void gc_worker(struct work_struct *work)
{
unsigned int min_interval = max(HZ / GC_MAX_BUCKETS_DIV, 1u);
unsigned int i, goal, buckets = 0, expired_count = 0;
unsigned int nf_conntrack_max95 = 0;
struct conntrack_gc_work *gc_work;
unsigned int ratio, scanned = 0;
unsigned long next_run;
gc_work = container_of(work, struct conntrack_gc_work, dwork.work);
goal = nf_conntrack_htable_size / GC_MAX_BUCKETS_DIV;
i = gc_work->last_bucket;
if (gc_work->early_drop)
nf_conntrack_max95 = nf_conntrack_max / 100u * 95u;
do {
struct nf_conntrack_tuple_hash *h;
struct hlist_nulls_head *ct_hash;
struct hlist_nulls_node *n;
unsigned int hashsz;
struct nf_conn *tmp;
i++;
rcu_read_lock();
nf_conntrack_get_ht(&ct_hash, &hashsz);
if (i >= hashsz)
i = 0;
hlist_nulls_for_each_entry_rcu(h, n, &ct_hash[i], hnnode) {
struct net *net;
tmp = nf_ct_tuplehash_to_ctrack(h);
scanned++;
if (nf_ct_is_expired(tmp)) {
nf_ct_gc_expired(tmp);
expired_count++;
continue;
}
if (nf_conntrack_max95 == 0 || gc_worker_skip_ct(tmp))
continue;
net = nf_ct_net(tmp);
if (atomic_read(&net->ct.count) < nf_conntrack_max95)
continue;
if (!atomic_inc_not_zero(&tmp->ct_general.use))
continue;
if (gc_worker_skip_ct(tmp)) {
nf_ct_put(tmp);
continue;
}
if (gc_worker_can_early_drop(tmp))
nf_ct_kill(tmp);
nf_ct_put(tmp);
}
rcu_read_unlock();
cond_resched_rcu_qs();
} while (++buckets < goal);
if (gc_work->exiting)
return;
ratio = scanned ? expired_count * 100 / scanned : 0;
if (ratio > GC_EVICT_RATIO) {
gc_work->next_gc_run = min_interval;
} else {
unsigned int max = GC_MAX_SCAN_JIFFIES / GC_MAX_BUCKETS_DIV;
BUILD_BUG_ON((GC_MAX_SCAN_JIFFIES / GC_MAX_BUCKETS_DIV) == 0);
gc_work->next_gc_run += min_interval;
if (gc_work->next_gc_run > max)
gc_work->next_gc_run = max;
}
next_run = gc_work->next_gc_run;
gc_work->last_bucket = i;
gc_work->early_drop = false;
queue_delayed_work(system_long_wq, &gc_work->dwork, next_run);
}
static void conntrack_gc_work_init(struct conntrack_gc_work *gc_work)
{
INIT_DELAYED_WORK(&gc_work->dwork, gc_worker);
gc_work->next_gc_run = HZ;
gc_work->exiting = false;
}
static struct nf_conn *
__nf_conntrack_alloc(struct net *net,
const struct nf_conntrack_zone *zone,
const struct nf_conntrack_tuple *orig,
const struct nf_conntrack_tuple *repl,
gfp_t gfp, u32 hash)
{
struct nf_conn *ct;
atomic_inc(&net->ct.count);
if (nf_conntrack_max &&
unlikely(atomic_read(&net->ct.count) > nf_conntrack_max)) {
if (!early_drop(net, hash)) {
if (!conntrack_gc_work.early_drop)
conntrack_gc_work.early_drop = true;
atomic_dec(&net->ct.count);
net_warn_ratelimited("nf_conntrack: table full, dropping packet\n");
return ERR_PTR(-ENOMEM);
}
}
ct = kmem_cache_alloc(nf_conntrack_cachep, gfp);
if (ct == NULL)
goto out;
spin_lock_init(&ct->lock);
ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple = *orig;
ct->tuplehash[IP_CT_DIR_ORIGINAL].hnnode.pprev = NULL;
ct->tuplehash[IP_CT_DIR_REPLY].tuple = *repl;
*(unsigned long *)(&ct->tuplehash[IP_CT_DIR_REPLY].hnnode.pprev) = hash;
ct->status = 0;
write_pnet(&ct->ct_net, net);
memset(&ct->__nfct_init_offset[0], 0,
offsetof(struct nf_conn, proto) -
offsetof(struct nf_conn, __nfct_init_offset[0]));
nf_ct_zone_add(ct, zone);
atomic_set(&ct->ct_general.use, 0);
return ct;
out:
atomic_dec(&net->ct.count);
return ERR_PTR(-ENOMEM);
}
struct nf_conn *nf_conntrack_alloc(struct net *net,
const struct nf_conntrack_zone *zone,
const struct nf_conntrack_tuple *orig,
const struct nf_conntrack_tuple *repl,
gfp_t gfp)
{
return __nf_conntrack_alloc(net, zone, orig, repl, gfp, 0);
}
void nf_conntrack_free(struct nf_conn *ct)
{
struct net *net = nf_ct_net(ct);
NF_CT_ASSERT(atomic_read(&ct->ct_general.use) == 0);
nf_ct_ext_destroy(ct);
nf_ct_ext_free(ct);
kmem_cache_free(nf_conntrack_cachep, ct);
smp_mb__before_atomic();
atomic_dec(&net->ct.count);
}
int
resolve_normal_ct(struct net *net, struct nf_conn *tmpl,
struct sk_buff *skb,
unsigned int dataoff,
u_int16_t l3num,
u_int8_t protonum,
struct nf_conntrack_l3proto *l3proto,
struct nf_conntrack_l4proto *l4proto)
{
const struct nf_conntrack_zone *zone;
struct nf_conntrack_tuple tuple;
struct nf_conntrack_tuple_hash *h;
enum ip_conntrack_info ctinfo;
struct nf_conntrack_zone tmp;
struct nf_conn *ct;
u32 hash;
if (!nf_ct_get_tuple(skb, skb_network_offset(skb),
dataoff, l3num, protonum, net, &tuple, l3proto,
l4proto)) {
pr_debug("Can't get tuple\n");
return 0;
}
zone = nf_ct_zone_tmpl(tmpl, skb, &tmp);
hash = hash_conntrack_raw(&tuple, net);
h = __nf_conntrack_find_get(net, zone, &tuple, hash);
if (!h) {
h = init_conntrack(net, tmpl, &tuple, l3proto, l4proto,
skb, dataoff, hash);
if (!h)
return 0;
if (IS_ERR(h))
return PTR_ERR(h);
}
ct = nf_ct_tuplehash_to_ctrack(h);
if (NF_CT_DIRECTION(h) == IP_CT_DIR_REPLY) {
ctinfo = IP_CT_ESTABLISHED_REPLY;
} else {
if (test_bit(IPS_SEEN_REPLY_BIT, &ct->status)) {
pr_debug("normal packet for %p\n", ct);
ctinfo = IP_CT_ESTABLISHED;
} else if (test_bit(IPS_EXPECTED_BIT, &ct->status)) {
pr_debug("related packet for %p\n", ct);
ctinfo = IP_CT_RELATED;
} else {
pr_debug("new packet for %p\n", ct);
ctinfo = IP_CT_NEW;
}
}
nf_ct_set(skb, ct, ctinfo);
return 0;
}
unsigned int
nf_conntrack_in(struct net *net, u_int8_t pf, unsigned int hooknum,
struct sk_buff *skb)
{
struct nf_conn *ct, *tmpl;
enum ip_conntrack_info ctinfo;
struct nf_conntrack_l3proto *l3proto;
struct nf_conntrack_l4proto *l4proto;
unsigned int *timeouts;
unsigned int dataoff;
u_int8_t protonum;
int ret;
tmpl = nf_ct_get(skb, &ctinfo);
if (tmpl || ctinfo == IP_CT_UNTRACKED) {
if ((tmpl && !nf_ct_is_template(tmpl)) ||
ctinfo == IP_CT_UNTRACKED) {
NF_CT_STAT_INC_ATOMIC(net, ignore);
return NF_ACCEPT;
}
skb->_nfct = 0;
}
l3proto = __nf_ct_l3proto_find(pf);
ret = l3proto->get_l4proto(skb, skb_network_offset(skb),
&dataoff, &protonum);
if (ret <= 0) {
pr_debug("not prepared to track yet or error occurred\n");
NF_CT_STAT_INC_ATOMIC(net, error);
NF_CT_STAT_INC_ATOMIC(net, invalid);
ret = -ret;
goto out;
}
l4proto = __nf_ct_l4proto_find(pf, protonum);
if (l4proto->error != NULL) {
ret = l4proto->error(net, tmpl, skb, dataoff, pf, hooknum);
if (ret <= 0) {
NF_CT_STAT_INC_ATOMIC(net, error);
NF_CT_STAT_INC_ATOMIC(net, invalid);
ret = -ret;
goto out;
}
if (skb->_nfct)
goto out;
}
repeat:
ret = resolve_normal_ct(net, tmpl, skb, dataoff, pf, protonum,
l3proto, l4proto);
if (ret < 0) {
NF_CT_STAT_INC_ATOMIC(net, drop);
ret = NF_DROP;
goto out;
}
ct = nf_ct_get(skb, &ctinfo);
if (!ct) {
NF_CT_STAT_INC_ATOMIC(net, invalid);
ret = NF_ACCEPT;
goto out;
}
timeouts = nf_ct_timeout_lookup(net, ct, l4proto);
ret = l4proto->packet(ct, skb, dataoff, ctinfo, pf, hooknum, timeouts);
if (ret <= 0) {
pr_debug("nf_conntrack_in: Can't track with proto module\n");
nf_conntrack_put(&ct->ct_general);
skb->_nfct = 0;
NF_CT_STAT_INC_ATOMIC(net, invalid);
if (ret == -NF_DROP)
NF_CT_STAT_INC_ATOMIC(net, drop);
if (ret == -NF_REPEAT)
goto repeat;
ret = -ret;
goto out;
}
if (ctinfo == IP_CT_ESTABLISHED_REPLY &&
!test_and_set_bit(IPS_SEEN_REPLY_BIT, &ct->status))
nf_conntrack_event_cache(IPCT_REPLY, ct);
out:
if (tmpl)
nf_ct_put(tmpl);
return ret;
}
bool nf_ct_invert_tuplepr(struct nf_conntrack_tuple *inverse,
const struct nf_conntrack_tuple *orig)
{
bool ret;
rcu_read_lock();
ret = nf_ct_invert_tuple(inverse, orig,
__nf_ct_l3proto_find(orig->src.l3num),
__nf_ct_l4proto_find(orig->src.l3num,
orig->dst.protonum));
rcu_read_unlock();
return ret;
}
void nf_conntrack_alter_reply(struct nf_conn *ct,
const struct nf_conntrack_tuple *newreply)
{
struct nf_conn_help *help = nfct_help(ct);
NF_CT_ASSERT(!nf_ct_is_confirmed(ct));
pr_debug("Altering reply tuple of %p to ", ct);
nf_ct_dump_tuple(newreply);
ct->tuplehash[IP_CT_DIR_REPLY].tuple = *newreply;
if (ct->master || (help && !hlist_empty(&help->expectations)))
return;
rcu_read_lock();
__nf_ct_try_assign_helper(ct, NULL, GFP_ATOMIC);
rcu_read_unlock();
}
void __nf_ct_refresh_acct(struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
const struct sk_buff *skb,
unsigned long extra_jiffies,
int do_acct)
{
NF_CT_ASSERT(skb);
if (test_bit(IPS_FIXED_TIMEOUT_BIT, &ct->status))
goto acct;
if (nf_ct_is_confirmed(ct))
extra_jiffies += nfct_time_stamp;
ct->timeout = extra_jiffies;
acct:
if (do_acct)
nf_ct_acct_update(ct, ctinfo, skb->len);
}
bool nf_ct_kill_acct(struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
const struct sk_buff *skb)
{
nf_ct_acct_update(ct, ctinfo, skb->len);
return nf_ct_delete(ct, 0, 0);
}
int nf_ct_port_tuple_to_nlattr(struct sk_buff *skb,
const struct nf_conntrack_tuple *tuple)
{
if (nla_put_be16(skb, CTA_PROTO_SRC_PORT, tuple->src.u.tcp.port) ||
nla_put_be16(skb, CTA_PROTO_DST_PORT, tuple->dst.u.tcp.port))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
int nf_ct_port_nlattr_to_tuple(struct nlattr *tb[],
struct nf_conntrack_tuple *t)
{
if (!tb[CTA_PROTO_SRC_PORT] || !tb[CTA_PROTO_DST_PORT])
return -EINVAL;
t->src.u.tcp.port = nla_get_be16(tb[CTA_PROTO_SRC_PORT]);
t->dst.u.tcp.port = nla_get_be16(tb[CTA_PROTO_DST_PORT]);
return 0;
}
int nf_ct_port_nlattr_tuple_size(void)
{
return nla_policy_len(nf_ct_port_nla_policy, CTA_PROTO_MAX + 1);
}
static void nf_conntrack_attach(struct sk_buff *nskb, const struct sk_buff *skb)
{
struct nf_conn *ct;
enum ip_conntrack_info ctinfo;
ct = nf_ct_get(skb, &ctinfo);
if (CTINFO2DIR(ctinfo) == IP_CT_DIR_ORIGINAL)
ctinfo = IP_CT_RELATED_REPLY;
else
ctinfo = IP_CT_RELATED;
nf_ct_set(nskb, ct, ctinfo);
nf_conntrack_get(skb_nfct(nskb));
}
static struct nf_conn *
get_next_corpse(struct net *net, int (*iter)(struct nf_conn *i, void *data),
void *data, unsigned int *bucket)
{
struct nf_conntrack_tuple_hash *h;
struct nf_conn *ct;
struct hlist_nulls_node *n;
int cpu;
spinlock_t *lockp;
for (; *bucket < nf_conntrack_htable_size; (*bucket)++) {
lockp = &nf_conntrack_locks[*bucket % CONNTRACK_LOCKS];
local_bh_disable();
nf_conntrack_lock(lockp);
if (*bucket < nf_conntrack_htable_size) {
hlist_nulls_for_each_entry(h, n, &nf_conntrack_hash[*bucket], hnnode) {
if (NF_CT_DIRECTION(h) != IP_CT_DIR_ORIGINAL)
continue;
ct = nf_ct_tuplehash_to_ctrack(h);
if (net_eq(nf_ct_net(ct), net) &&
iter(ct, data))
goto found;
}
}
spin_unlock(lockp);
local_bh_enable();
cond_resched();
}
for_each_possible_cpu(cpu) {
struct ct_pcpu *pcpu = per_cpu_ptr(net->ct.pcpu_lists, cpu);
spin_lock_bh(&pcpu->lock);
hlist_nulls_for_each_entry(h, n, &pcpu->unconfirmed, hnnode) {
ct = nf_ct_tuplehash_to_ctrack(h);
if (iter(ct, data))
set_bit(IPS_DYING_BIT, &ct->status);
}
spin_unlock_bh(&pcpu->lock);
cond_resched();
}
return NULL;
found:
atomic_inc(&ct->ct_general.use);
spin_unlock(lockp);
local_bh_enable();
return ct;
}
void nf_ct_iterate_cleanup(struct net *net,
int (*iter)(struct nf_conn *i, void *data),
void *data, u32 portid, int report)
{
struct nf_conn *ct;
unsigned int bucket = 0;
might_sleep();
if (atomic_read(&net->ct.count) == 0)
return;
while ((ct = get_next_corpse(net, iter, data, &bucket)) != NULL) {
nf_ct_delete(ct, portid, report);
nf_ct_put(ct);
cond_resched();
}
}
static int kill_all(struct nf_conn *i, void *data)
{
return 1;
}
void nf_ct_free_hashtable(void *hash, unsigned int size)
{
if (is_vmalloc_addr(hash))
vfree(hash);
else
free_pages((unsigned long)hash,
get_order(sizeof(struct hlist_head) * size));
}
void nf_conntrack_cleanup_start(void)
{
conntrack_gc_work.exiting = true;
RCU_INIT_POINTER(ip_ct_attach, NULL);
}
void nf_conntrack_cleanup_end(void)
{
RCU_INIT_POINTER(nf_ct_destroy, NULL);
cancel_delayed_work_sync(&conntrack_gc_work.dwork);
nf_ct_free_hashtable(nf_conntrack_hash, nf_conntrack_htable_size);
nf_conntrack_proto_fini();
nf_conntrack_seqadj_fini();
nf_conntrack_labels_fini();
nf_conntrack_helper_fini();
nf_conntrack_timeout_fini();
nf_conntrack_ecache_fini();
nf_conntrack_tstamp_fini();
nf_conntrack_acct_fini();
nf_conntrack_expect_fini();
kmem_cache_destroy(nf_conntrack_cachep);
}
void nf_conntrack_cleanup_net(struct net *net)
{
LIST_HEAD(single);
list_add(&net->exit_list, &single);
nf_conntrack_cleanup_net_list(&single);
}
void nf_conntrack_cleanup_net_list(struct list_head *net_exit_list)
{
int busy;
struct net *net;
synchronize_net();
i_see_dead_people:
busy = 0;
list_for_each_entry(net, net_exit_list, exit_list) {
nf_ct_iterate_cleanup(net, kill_all, NULL, 0, 0);
if (atomic_read(&net->ct.count) != 0)
busy = 1;
}
if (busy) {
schedule();
goto i_see_dead_people;
}
list_for_each_entry(net, net_exit_list, exit_list) {
nf_conntrack_proto_pernet_fini(net);
nf_conntrack_helper_pernet_fini(net);
nf_conntrack_ecache_pernet_fini(net);
nf_conntrack_tstamp_pernet_fini(net);
nf_conntrack_acct_pernet_fini(net);
nf_conntrack_expect_pernet_fini(net);
free_percpu(net->ct.stat);
free_percpu(net->ct.pcpu_lists);
}
}
void *nf_ct_alloc_hashtable(unsigned int *sizep, int nulls)
{
struct hlist_nulls_head *hash;
unsigned int nr_slots, i;
size_t sz;
if (*sizep > (UINT_MAX / sizeof(struct hlist_nulls_head)))
return NULL;
BUILD_BUG_ON(sizeof(struct hlist_nulls_head) != sizeof(struct hlist_head));
nr_slots = *sizep = roundup(*sizep, PAGE_SIZE / sizeof(struct hlist_nulls_head));
if (nr_slots > (UINT_MAX / sizeof(struct hlist_nulls_head)))
return NULL;
sz = nr_slots * sizeof(struct hlist_nulls_head);
hash = (void *)__get_free_pages(GFP_KERNEL | __GFP_NOWARN | __GFP_ZERO,
get_order(sz));
if (!hash)
hash = vzalloc(sz);
if (hash && nulls)
for (i = 0; i < nr_slots; i++)
INIT_HLIST_NULLS_HEAD(&hash[i], i);
return hash;
}
int nf_conntrack_hash_resize(unsigned int hashsize)
{
int i, bucket;
unsigned int old_size;
struct hlist_nulls_head *hash, *old_hash;
struct nf_conntrack_tuple_hash *h;
struct nf_conn *ct;
if (!hashsize)
return -EINVAL;
hash = nf_ct_alloc_hashtable(&hashsize, 1);
if (!hash)
return -ENOMEM;
old_size = nf_conntrack_htable_size;
if (old_size == hashsize) {
nf_ct_free_hashtable(hash, hashsize);
return 0;
}
local_bh_disable();
nf_conntrack_all_lock();
write_seqcount_begin(&nf_conntrack_generation);
for (i = 0; i < nf_conntrack_htable_size; i++) {
while (!hlist_nulls_empty(&nf_conntrack_hash[i])) {
h = hlist_nulls_entry(nf_conntrack_hash[i].first,
struct nf_conntrack_tuple_hash, hnnode);
ct = nf_ct_tuplehash_to_ctrack(h);
hlist_nulls_del_rcu(&h->hnnode);
bucket = __hash_conntrack(nf_ct_net(ct),
&h->tuple, hashsize);
hlist_nulls_add_head_rcu(&h->hnnode, &hash[bucket]);
}
}
old_size = nf_conntrack_htable_size;
old_hash = nf_conntrack_hash;
nf_conntrack_hash = hash;
nf_conntrack_htable_size = hashsize;
write_seqcount_end(&nf_conntrack_generation);
nf_conntrack_all_unlock();
local_bh_enable();
synchronize_net();
nf_ct_free_hashtable(old_hash, old_size);
return 0;
}
int nf_conntrack_set_hashsize(const char *val, struct kernel_param *kp)
{
unsigned int hashsize;
int rc;
if (current->nsproxy->net_ns != &init_net)
return -EOPNOTSUPP;
if (!nf_conntrack_htable_size)
return param_set_uint(val, kp);
rc = kstrtouint(val, 0, &hashsize);
if (rc)
return rc;
return nf_conntrack_hash_resize(hashsize);
}
static __always_inline unsigned int total_extension_size(void)
{
BUILD_BUG_ON(NF_CT_EXT_NUM > 9);
return sizeof(struct nf_ct_ext) +
sizeof(struct nf_conn_help)
#if IS_ENABLED(CONFIG_NF_NAT)
+ sizeof(struct nf_conn_nat)
#endif
+ sizeof(struct nf_conn_seqadj)
+ sizeof(struct nf_conn_acct)
#ifdef CONFIG_NF_CONNTRACK_EVENTS
+ sizeof(struct nf_conntrack_ecache)
#endif
#ifdef CONFIG_NF_CONNTRACK_TIMESTAMP
+ sizeof(struct nf_conn_tstamp)
#endif
#ifdef CONFIG_NF_CONNTRACK_TIMEOUT
+ sizeof(struct nf_conn_timeout)
#endif
#ifdef CONFIG_NF_CONNTRACK_LABELS
+ sizeof(struct nf_conn_labels)
#endif
#if IS_ENABLED(CONFIG_NETFILTER_SYNPROXY)
+ sizeof(struct nf_conn_synproxy)
#endif
;
}
int nf_conntrack_init_start(void)
{
int max_factor = 8;
int ret = -ENOMEM;
int i;
BUILD_BUG_ON(total_extension_size() > 255u);
seqcount_init(&nf_conntrack_generation);
for (i = 0; i < CONNTRACK_LOCKS; i++)
spin_lock_init(&nf_conntrack_locks[i]);
if (!nf_conntrack_htable_size) {
nf_conntrack_htable_size
= (((totalram_pages << PAGE_SHIFT) / 16384)
/ sizeof(struct hlist_head));
if (totalram_pages > (4 * (1024 * 1024 * 1024 / PAGE_SIZE)))
nf_conntrack_htable_size = 65536;
else if (totalram_pages > (1024 * 1024 * 1024 / PAGE_SIZE))
nf_conntrack_htable_size = 16384;
if (nf_conntrack_htable_size < 32)
nf_conntrack_htable_size = 32;
max_factor = 4;
}
nf_conntrack_hash = nf_ct_alloc_hashtable(&nf_conntrack_htable_size, 1);
if (!nf_conntrack_hash)
return -ENOMEM;
nf_conntrack_max = max_factor * nf_conntrack_htable_size;
nf_conntrack_cachep = kmem_cache_create("nf_conntrack",
sizeof(struct nf_conn),
NFCT_INFOMASK + 1,
SLAB_TYPESAFE_BY_RCU | SLAB_HWCACHE_ALIGN, NULL);
if (!nf_conntrack_cachep)
goto err_cachep;
printk(KERN_INFO "nf_conntrack version %s (%u buckets, %d max)\n",
NF_CONNTRACK_VERSION, nf_conntrack_htable_size,
nf_conntrack_max);
ret = nf_conntrack_expect_init();
if (ret < 0)
goto err_expect;
ret = nf_conntrack_acct_init();
if (ret < 0)
goto err_acct;
ret = nf_conntrack_tstamp_init();
if (ret < 0)
goto err_tstamp;
ret = nf_conntrack_ecache_init();
if (ret < 0)
goto err_ecache;
ret = nf_conntrack_timeout_init();
if (ret < 0)
goto err_timeout;
ret = nf_conntrack_helper_init();
if (ret < 0)
goto err_helper;
ret = nf_conntrack_labels_init();
if (ret < 0)
goto err_labels;
ret = nf_conntrack_seqadj_init();
if (ret < 0)
goto err_seqadj;
ret = nf_conntrack_proto_init();
if (ret < 0)
goto err_proto;
conntrack_gc_work_init(&conntrack_gc_work);
queue_delayed_work(system_long_wq, &conntrack_gc_work.dwork, HZ);
return 0;
err_proto:
nf_conntrack_seqadj_fini();
err_seqadj:
nf_conntrack_labels_fini();
err_labels:
nf_conntrack_helper_fini();
err_helper:
nf_conntrack_timeout_fini();
err_timeout:
nf_conntrack_ecache_fini();
err_ecache:
nf_conntrack_tstamp_fini();
err_tstamp:
nf_conntrack_acct_fini();
err_acct:
nf_conntrack_expect_fini();
err_expect:
kmem_cache_destroy(nf_conntrack_cachep);
err_cachep:
nf_ct_free_hashtable(nf_conntrack_hash, nf_conntrack_htable_size);
return ret;
}
void nf_conntrack_init_end(void)
{
RCU_INIT_POINTER(ip_ct_attach, nf_conntrack_attach);
RCU_INIT_POINTER(nf_ct_destroy, destroy_conntrack);
}
int nf_conntrack_init_net(struct net *net)
{
int ret = -ENOMEM;
int cpu;
BUILD_BUG_ON(IP_CT_UNTRACKED == IP_CT_NUMBER);
atomic_set(&net->ct.count, 0);
net->ct.pcpu_lists = alloc_percpu(struct ct_pcpu);
if (!net->ct.pcpu_lists)
goto err_stat;
for_each_possible_cpu(cpu) {
struct ct_pcpu *pcpu = per_cpu_ptr(net->ct.pcpu_lists, cpu);
spin_lock_init(&pcpu->lock);
INIT_HLIST_NULLS_HEAD(&pcpu->unconfirmed, UNCONFIRMED_NULLS_VAL);
INIT_HLIST_NULLS_HEAD(&pcpu->dying, DYING_NULLS_VAL);
}
net->ct.stat = alloc_percpu(struct ip_conntrack_stat);
if (!net->ct.stat)
goto err_pcpu_lists;
ret = nf_conntrack_expect_pernet_init(net);
if (ret < 0)
goto err_expect;
ret = nf_conntrack_acct_pernet_init(net);
if (ret < 0)
goto err_acct;
ret = nf_conntrack_tstamp_pernet_init(net);
if (ret < 0)
goto err_tstamp;
ret = nf_conntrack_ecache_pernet_init(net);
if (ret < 0)
goto err_ecache;
ret = nf_conntrack_helper_pernet_init(net);
if (ret < 0)
goto err_helper;
ret = nf_conntrack_proto_pernet_init(net);
if (ret < 0)
goto err_proto;
return 0;
err_proto:
nf_conntrack_helper_pernet_fini(net);
err_helper:
nf_conntrack_ecache_pernet_fini(net);
err_ecache:
nf_conntrack_tstamp_pernet_fini(net);
err_tstamp:
nf_conntrack_acct_pernet_fini(net);
err_acct:
nf_conntrack_expect_pernet_fini(net);
err_expect:
free_percpu(net->ct.stat);
err_pcpu_lists:
free_percpu(net->ct.pcpu_lists);
err_stat:
return ret;
}
