static void ipv4_dst_ifdown(struct dst_entry *dst, struct net_device *dev,
int how)
{
}
static u32 *ipv4_cow_metrics(struct dst_entry *dst, unsigned long old)
{
struct rtable *rt = (struct rtable *) dst;
struct inet_peer *peer;
u32 *p = NULL;
if (!rt->peer)
rt_bind_peer(rt, rt->rt_dst, 1);
peer = rt->peer;
if (peer) {
u32 *old_p = __DST_METRICS_PTR(old);
unsigned long prev, new;
p = peer->metrics;
if (inet_metrics_new(peer))
memcpy(p, old_p, sizeof(u32) * RTAX_MAX);
new = (unsigned long) p;
prev = cmpxchg(&dst->_metrics, old, new);
if (prev != old) {
p = __DST_METRICS_PTR(prev);
if (prev & DST_METRICS_READ_ONLY)
p = NULL;
} else {
if (rt->fi) {
fib_info_put(rt->fi);
rt->fi = NULL;
}
}
}
return p;
}
static __init void rt_hash_lock_init(void)
{
int i;
rt_hash_locks = kmalloc(sizeof(spinlock_t) * RT_HASH_LOCK_SZ,
GFP_KERNEL);
if (!rt_hash_locks)
panic("IP: failed to allocate rt_hash_locks\n");
for (i = 0; i < RT_HASH_LOCK_SZ; i++)
spin_lock_init(&rt_hash_locks[i]);
}
static inline void rt_hash_lock_init(void)
{
}
static inline unsigned int rt_hash(__be32 daddr, __be32 saddr, int idx,
int genid)
{
return jhash_3words((__force u32)daddr, (__force u32)saddr,
idx, genid)
& rt_hash_mask;
}
static inline int rt_genid(struct net *net)
{
return atomic_read(&net->ipv4.rt_genid);
}
static struct rtable *rt_cache_get_first(struct seq_file *seq)
{
struct rt_cache_iter_state *st = seq->private;
struct rtable *r = NULL;
for (st->bucket = rt_hash_mask; st->bucket >= 0; --st->bucket) {
if (!rcu_dereference_raw(rt_hash_table[st->bucket].chain))
continue;
rcu_read_lock_bh();
r = rcu_dereference_bh(rt_hash_table[st->bucket].chain);
while (r) {
if (dev_net(r->dst.dev) == seq_file_net(seq) &&
r->rt_genid == st->genid)
return r;
r = rcu_dereference_bh(r->dst.rt_next);
}
rcu_read_unlock_bh();
}
return r;
}
static struct rtable *__rt_cache_get_next(struct seq_file *seq,
struct rtable *r)
{
struct rt_cache_iter_state *st = seq->private;
r = rcu_dereference_bh(r->dst.rt_next);
while (!r) {
rcu_read_unlock_bh();
do {
if (--st->bucket < 0)
return NULL;
} while (!rcu_dereference_raw(rt_hash_table[st->bucket].chain));
rcu_read_lock_bh();
r = rcu_dereference_bh(rt_hash_table[st->bucket].chain);
}
return r;
}
static struct rtable *rt_cache_get_next(struct seq_file *seq,
struct rtable *r)
{
struct rt_cache_iter_state *st = seq->private;
while ((r = __rt_cache_get_next(seq, r)) != NULL) {
if (dev_net(r->dst.dev) != seq_file_net(seq))
continue;
if (r->rt_genid == st->genid)
break;
}
return r;
}
static struct rtable *rt_cache_get_idx(struct seq_file *seq, loff_t pos)
{
struct rtable *r = rt_cache_get_first(seq);
if (r)
while (pos && (r = rt_cache_get_next(seq, r)))
--pos;
return pos ? NULL : r;
}
static void *rt_cache_seq_start(struct seq_file *seq, loff_t *pos)
{
struct rt_cache_iter_state *st = seq->private;
if (*pos)
return rt_cache_get_idx(seq, *pos - 1);
st->genid = rt_genid(seq_file_net(seq));
return SEQ_START_TOKEN;
}
static void *rt_cache_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct rtable *r;
if (v == SEQ_START_TOKEN)
r = rt_cache_get_first(seq);
else
r = rt_cache_get_next(seq, v);
++*pos;
return r;
}
static void rt_cache_seq_stop(struct seq_file *seq, void *v)
{
if (v && v != SEQ_START_TOKEN)
rcu_read_unlock_bh();
}
static int rt_cache_seq_show(struct seq_file *seq, void *v)
{
if (v == SEQ_START_TOKEN)
seq_printf(seq, "%-127s\n",
"Iface\tDestination\tGateway \tFlags\t\tRefCnt\tUse\t"
"Metric\tSource\t\tMTU\tWindow\tIRTT\tTOS\tHHRef\t"
"HHUptod\tSpecDst");
else {
struct rtable *r = v;
int len;
seq_printf(seq, "%s\t%08X\t%08X\t%8X\t%d\t%u\t%d\t"
"%08X\t%d\t%u\t%u\t%02X\t%d\t%1d\t%08X%n",
r->dst.dev ? r->dst.dev->name : "*",
(__force u32)r->rt_dst,
(__force u32)r->rt_gateway,
r->rt_flags, atomic_read(&r->dst.__refcnt),
r->dst.__use, 0, (__force u32)r->rt_src,
dst_metric_advmss(&r->dst) + 40,
dst_metric(&r->dst, RTAX_WINDOW),
(int)((dst_metric(&r->dst, RTAX_RTT) >> 3) +
dst_metric(&r->dst, RTAX_RTTVAR)),
r->rt_key_tos,
r->dst.hh ? atomic_read(&r->dst.hh->hh_refcnt) : -1,
r->dst.hh ? (r->dst.hh->hh_output ==
dev_queue_xmit) : 0,
r->rt_spec_dst, &len);
seq_printf(seq, "%*s\n", 127 - len, "");
}
return 0;
}
static int rt_cache_seq_open(struct inode *inode, struct file *file)
{
return seq_open_net(inode, file, &rt_cache_seq_ops,
sizeof(struct rt_cache_iter_state));
}
static void *rt_cpu_seq_start(struct seq_file *seq, loff_t *pos)
{
int cpu;
if (*pos == 0)
return SEQ_START_TOKEN;
for (cpu = *pos-1; cpu < nr_cpu_ids; ++cpu) {
if (!cpu_possible(cpu))
continue;
*pos = cpu+1;
return &per_cpu(rt_cache_stat, cpu);
}
return NULL;
}
static void *rt_cpu_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
int cpu;
for (cpu = *pos; cpu < nr_cpu_ids; ++cpu) {
if (!cpu_possible(cpu))
continue;
*pos = cpu+1;
return &per_cpu(rt_cache_stat, cpu);
}
return NULL;
}
static void rt_cpu_seq_stop(struct seq_file *seq, void *v)
{
}
static int rt_cpu_seq_show(struct seq_file *seq, void *v)
{
struct rt_cache_stat *st = v;
if (v == SEQ_START_TOKEN) {
seq_printf(seq, "entries in_hit in_slow_tot in_slow_mc in_no_route in_brd in_martian_dst in_martian_src out_hit out_slow_tot out_slow_mc gc_total gc_ignored gc_goal_miss gc_dst_overflow in_hlist_search out_hlist_search\n");
return 0;
}
seq_printf(seq,"%08x %08x %08x %08x %08x %08x %08x %08x "
" %08x %08x %08x %08x %08x %08x %08x %08x %08x \n",
dst_entries_get_slow(&ipv4_dst_ops),
st->in_hit,
st->in_slow_tot,
st->in_slow_mc,
st->in_no_route,
st->in_brd,
st->in_martian_dst,
st->in_martian_src,
st->out_hit,
st->out_slow_tot,
st->out_slow_mc,
st->gc_total,
st->gc_ignored,
st->gc_goal_miss,
st->gc_dst_overflow,
st->in_hlist_search,
st->out_hlist_search
);
return 0;
}
static int rt_cpu_seq_open(struct inode *inode, struct file *file)
{
return seq_open(file, &rt_cpu_seq_ops);
}
static int rt_acct_proc_show(struct seq_file *m, void *v)
{
struct ip_rt_acct *dst, *src;
unsigned int i, j;
dst = kcalloc(256, sizeof(struct ip_rt_acct), GFP_KERNEL);
if (!dst)
return -ENOMEM;
for_each_possible_cpu(i) {
src = (struct ip_rt_acct *)per_cpu_ptr(ip_rt_acct, i);
for (j = 0; j < 256; j++) {
dst[j].o_bytes += src[j].o_bytes;
dst[j].o_packets += src[j].o_packets;
dst[j].i_bytes += src[j].i_bytes;
dst[j].i_packets += src[j].i_packets;
}
}
seq_write(m, dst, 256 * sizeof(struct ip_rt_acct));
kfree(dst);
return 0;
}
static int rt_acct_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, rt_acct_proc_show, NULL);
}
static int __net_init ip_rt_do_proc_init(struct net *net)
{
struct proc_dir_entry *pde;
pde = proc_net_fops_create(net, "rt_cache", S_IRUGO,
&rt_cache_seq_fops);
if (!pde)
goto err1;
pde = proc_create("rt_cache", S_IRUGO,
net->proc_net_stat, &rt_cpu_seq_fops);
if (!pde)
goto err2;
#ifdef CONFIG_IP_ROUTE_CLASSID
pde = proc_create("rt_acct", 0, net->proc_net, &rt_acct_proc_fops);
if (!pde)
goto err3;
#endif
return 0;
#ifdef CONFIG_IP_ROUTE_CLASSID
err3:
remove_proc_entry("rt_cache", net->proc_net_stat);
#endif
err2:
remove_proc_entry("rt_cache", net->proc_net);
err1:
return -ENOMEM;
}
static void __net_exit ip_rt_do_proc_exit(struct net *net)
{
remove_proc_entry("rt_cache", net->proc_net_stat);
remove_proc_entry("rt_cache", net->proc_net);
#ifdef CONFIG_IP_ROUTE_CLASSID
remove_proc_entry("rt_acct", net->proc_net);
#endif
}
static int __init ip_rt_proc_init(void)
{
return register_pernet_subsys(&ip_rt_proc_ops);
}
static inline int ip_rt_proc_init(void)
{
return 0;
}
static inline void rt_free(struct rtable *rt)
{
call_rcu_bh(&rt->dst.rcu_head, dst_rcu_free);
}
static inline void rt_drop(struct rtable *rt)
{
ip_rt_put(rt);
call_rcu_bh(&rt->dst.rcu_head, dst_rcu_free);
}
static inline int rt_fast_clean(struct rtable *rth)
{
return (rth->rt_flags & (RTCF_BROADCAST | RTCF_MULTICAST)) &&
rt_is_input_route(rth) && rth->dst.rt_next;
}
static inline int rt_valuable(struct rtable *rth)
{
return (rth->rt_flags & (RTCF_REDIRECTED | RTCF_NOTIFY)) ||
(rth->peer && rth->peer->pmtu_expires);
}
static int rt_may_expire(struct rtable *rth, unsigned long tmo1, unsigned long tmo2)
{
unsigned long age;
int ret = 0;
if (atomic_read(&rth->dst.__refcnt))
goto out;
age = jiffies - rth->dst.lastuse;
if ((age <= tmo1 && !rt_fast_clean(rth)) ||
(age <= tmo2 && rt_valuable(rth)))
goto out;
ret = 1;
out: return ret;
}
static inline u32 rt_score(struct rtable *rt)
{
u32 score = jiffies - rt->dst.lastuse;
score = ~score & ~(3<<30);
if (rt_valuable(rt))
score |= (1<<31);
if (rt_is_output_route(rt) ||
!(rt->rt_flags & (RTCF_BROADCAST|RTCF_MULTICAST|RTCF_LOCAL)))
score |= (1<<30);
return score;
}
static inline bool rt_caching(const struct net *net)
{
return net->ipv4.current_rt_cache_rebuild_count <=
net->ipv4.sysctl_rt_cache_rebuild_count;
}
static inline bool compare_hash_inputs(const struct rtable *rt1,
const struct rtable *rt2)
{
return ((((__force u32)rt1->rt_key_dst ^ (__force u32)rt2->rt_key_dst) |
((__force u32)rt1->rt_key_src ^ (__force u32)rt2->rt_key_src) |
(rt1->rt_iif ^ rt2->rt_iif)) == 0);
}
static inline int compare_keys(struct rtable *rt1, struct rtable *rt2)
{
return (((__force u32)rt1->rt_key_dst ^ (__force u32)rt2->rt_key_dst) |
((__force u32)rt1->rt_key_src ^ (__force u32)rt2->rt_key_src) |
(rt1->rt_mark ^ rt2->rt_mark) |
(rt1->rt_key_tos ^ rt2->rt_key_tos) |
(rt1->rt_oif ^ rt2->rt_oif) |
(rt1->rt_iif ^ rt2->rt_iif)) == 0;
}
static inline int compare_netns(struct rtable *rt1, struct rtable *rt2)
{
return net_eq(dev_net(rt1->dst.dev), dev_net(rt2->dst.dev));
}
static inline int rt_is_expired(struct rtable *rth)
{
return rth->rt_genid != rt_genid(dev_net(rth->dst.dev));
}
static void rt_do_flush(struct net *net, int process_context)
{
unsigned int i;
struct rtable *rth, *next;
for (i = 0; i <= rt_hash_mask; i++) {
struct rtable __rcu **pprev;
struct rtable *list;
if (process_context && need_resched())
cond_resched();
rth = rcu_dereference_raw(rt_hash_table[i].chain);
if (!rth)
continue;
spin_lock_bh(rt_hash_lock_addr(i));
list = NULL;
pprev = &rt_hash_table[i].chain;
rth = rcu_dereference_protected(*pprev,
lockdep_is_held(rt_hash_lock_addr(i)));
while (rth) {
next = rcu_dereference_protected(rth->dst.rt_next,
lockdep_is_held(rt_hash_lock_addr(i)));
if (!net ||
net_eq(dev_net(rth->dst.dev), net)) {
rcu_assign_pointer(*pprev, next);
rcu_assign_pointer(rth->dst.rt_next, list);
list = rth;
} else {
pprev = &rth->dst.rt_next;
}
rth = next;
}
spin_unlock_bh(rt_hash_lock_addr(i));
for (; list; list = next) {
next = rcu_dereference_protected(list->dst.rt_next, 1);
rt_free(list);
}
}
}
static int has_noalias(const struct rtable *head, const struct rtable *rth)
{
const struct rtable *aux = head;
while (aux != rth) {
if (compare_hash_inputs(aux, rth))
return 0;
aux = rcu_dereference_protected(aux->dst.rt_next, 1);
}
return ONE;
}
static void rt_cache_invalidate(struct net *net)
{
unsigned char shuffle;
get_random_bytes(&shuffle, sizeof(shuffle));
atomic_add(shuffle + 1U, &net->ipv4.rt_genid);
}
void rt_cache_flush(struct net *net, int delay)
{
rt_cache_invalidate(net);
if (delay >= 0)
rt_do_flush(net, !in_softirq());
}
void rt_cache_flush_batch(struct net *net)
{
rt_do_flush(net, !in_softirq());
}
static void rt_emergency_hash_rebuild(struct net *net)
{
if (net_ratelimit())
printk(KERN_WARNING "Route hash chain too long!\n");
rt_cache_invalidate(net);
}
static int rt_garbage_collect(struct dst_ops *ops)
{
static unsigned long expire = RT_GC_TIMEOUT;
static unsigned long last_gc;
static int rover;
static int equilibrium;
struct rtable *rth;
struct rtable __rcu **rthp;
unsigned long now = jiffies;
int goal;
int entries = dst_entries_get_fast(&ipv4_dst_ops);
RT_CACHE_STAT_INC(gc_total);
if (now - last_gc < ip_rt_gc_min_interval &&
entries < ip_rt_max_size) {
RT_CACHE_STAT_INC(gc_ignored);
goto out;
}
entries = dst_entries_get_slow(&ipv4_dst_ops);
goal = entries - (ip_rt_gc_elasticity << rt_hash_log);
if (goal <= 0) {
if (equilibrium < ipv4_dst_ops.gc_thresh)
equilibrium = ipv4_dst_ops.gc_thresh;
goal = entries - equilibrium;
if (goal > 0) {
equilibrium += min_t(unsigned int, goal >> 1, rt_hash_mask + 1);
goal = entries - equilibrium;
}
} else {
goal = max_t(unsigned int, goal >> 1, rt_hash_mask + 1);
equilibrium = entries - goal;
}
if (now - last_gc >= ip_rt_gc_min_interval)
last_gc = now;
if (goal <= 0) {
equilibrium += goal;
goto work_done;
}
do {
int i, k;
for (i = rt_hash_mask, k = rover; i >= 0; i--) {
unsigned long tmo = expire;
k = (k + 1) & rt_hash_mask;
rthp = &rt_hash_table[k].chain;
spin_lock_bh(rt_hash_lock_addr(k));
while ((rth = rcu_dereference_protected(*rthp,
lockdep_is_held(rt_hash_lock_addr(k)))) != NULL) {
if (!rt_is_expired(rth) &&
!rt_may_expire(rth, tmo, expire)) {
tmo >>= 1;
rthp = &rth->dst.rt_next;
continue;
}
*rthp = rth->dst.rt_next;
rt_free(rth);
goal--;
}
spin_unlock_bh(rt_hash_lock_addr(k));
if (goal <= 0)
break;
}
rover = k;
if (goal <= 0)
goto work_done;
RT_CACHE_STAT_INC(gc_goal_miss);
if (expire == 0)
break;
expire >>= 1;
if (dst_entries_get_fast(&ipv4_dst_ops) < ip_rt_max_size)
goto out;
} while (!in_softirq() && time_before_eq(jiffies, now));
if (dst_entries_get_fast(&ipv4_dst_ops) < ip_rt_max_size)
goto out;
if (dst_entries_get_slow(&ipv4_dst_ops) < ip_rt_max_size)
goto out;
if (net_ratelimit())
printk(KERN_WARNING "dst cache overflow\n");
RT_CACHE_STAT_INC(gc_dst_overflow);
return 1;
work_done:
expire += ip_rt_gc_min_interval;
if (expire > ip_rt_gc_timeout ||
dst_entries_get_fast(&ipv4_dst_ops) < ipv4_dst_ops.gc_thresh ||
dst_entries_get_slow(&ipv4_dst_ops) < ipv4_dst_ops.gc_thresh)
expire = ip_rt_gc_timeout;
out: return 0;
}
static int slow_chain_length(const struct rtable *head)
{
int length = 0;
const struct rtable *rth = head;
while (rth) {
length += has_noalias(head, rth);
rth = rcu_dereference_protected(rth->dst.rt_next, 1);
}
return length >> FRACT_BITS;
}
static struct rtable *rt_intern_hash(unsigned hash, struct rtable *rt,
struct sk_buff *skb, int ifindex)
{
struct rtable *rth, *cand;
struct rtable __rcu **rthp, **candp;
unsigned long now;
u32 min_score;
int chain_length;
int attempts = !in_softirq();
restart:
chain_length = 0;
min_score = ~(u32)0;
cand = NULL;
candp = NULL;
now = jiffies;
if (!rt_caching(dev_net(rt->dst.dev))) {
rt->dst.flags |= DST_NOCACHE;
if (rt->rt_type == RTN_UNICAST || rt_is_output_route(rt)) {
int err = arp_bind_neighbour(&rt->dst);
if (err) {
if (net_ratelimit())
printk(KERN_WARNING
"Neighbour table failure & not caching routes.\n");
ip_rt_put(rt);
return ERR_PTR(err);
}
}
goto skip_hashing;
}
rthp = &rt_hash_table[hash].chain;
spin_lock_bh(rt_hash_lock_addr(hash));
while ((rth = rcu_dereference_protected(*rthp,
lockdep_is_held(rt_hash_lock_addr(hash)))) != NULL) {
if (rt_is_expired(rth)) {
*rthp = rth->dst.rt_next;
rt_free(rth);
continue;
}
if (compare_keys(rth, rt) && compare_netns(rth, rt)) {
*rthp = rth->dst.rt_next;
rcu_assign_pointer(rth->dst.rt_next,
rt_hash_table[hash].chain);
rcu_assign_pointer(rt_hash_table[hash].chain, rth);
dst_use(&rth->dst, now);
spin_unlock_bh(rt_hash_lock_addr(hash));
rt_drop(rt);
if (skb)
skb_dst_set(skb, &rth->dst);
return rth;
}
if (!atomic_read(&rth->dst.__refcnt)) {
u32 score = rt_score(rth);
if (score <= min_score) {
cand = rth;
candp = rthp;
min_score = score;
}
}
chain_length++;
rthp = &rth->dst.rt_next;
}
if (cand) {
if (chain_length > ip_rt_gc_elasticity) {
*candp = cand->dst.rt_next;
rt_free(cand);
}
} else {
if (chain_length > rt_chain_length_max &&
slow_chain_length(rt_hash_table[hash].chain) > rt_chain_length_max) {
struct net *net = dev_net(rt->dst.dev);
int num = ++net->ipv4.current_rt_cache_rebuild_count;
if (!rt_caching(net)) {
printk(KERN_WARNING "%s: %d rebuilds is over limit, route caching disabled\n",
rt->dst.dev->name, num);
}
rt_emergency_hash_rebuild(net);
spin_unlock_bh(rt_hash_lock_addr(hash));
hash = rt_hash(rt->rt_key_dst, rt->rt_key_src,
ifindex, rt_genid(net));
goto restart;
}
}
if (rt->rt_type == RTN_UNICAST || rt_is_output_route(rt)) {
int err = arp_bind_neighbour(&rt->dst);
if (err) {
spin_unlock_bh(rt_hash_lock_addr(hash));
if (err != -ENOBUFS) {
rt_drop(rt);
return ERR_PTR(err);
}
if (attempts-- > 0) {
int saved_elasticity = ip_rt_gc_elasticity;
int saved_int = ip_rt_gc_min_interval;
ip_rt_gc_elasticity = 1;
ip_rt_gc_min_interval = 0;
rt_garbage_collect(&ipv4_dst_ops);
ip_rt_gc_min_interval = saved_int;
ip_rt_gc_elasticity = saved_elasticity;
goto restart;
}
if (net_ratelimit())
printk(KERN_WARNING "ipv4: Neighbour table overflow.\n");
rt_drop(rt);
return ERR_PTR(-ENOBUFS);
}
}
rt->dst.rt_next = rt_hash_table[hash].chain;
rcu_assign_pointer(rt_hash_table[hash].chain, rt);
spin_unlock_bh(rt_hash_lock_addr(hash));
skip_hashing:
if (skb)
skb_dst_set(skb, &rt->dst);
return rt;
}
static u32 rt_peer_genid(void)
{
return atomic_read(&__rt_peer_genid);
}
void rt_bind_peer(struct rtable *rt, __be32 daddr, int create)
{
struct inet_peer *peer;
peer = inet_getpeer_v4(daddr, create);
if (peer && cmpxchg(&rt->peer, NULL, peer) != NULL)
inet_putpeer(peer);
else
rt->rt_peer_genid = rt_peer_genid();
}
static void ip_select_fb_ident(struct iphdr *iph)
{
static DEFINE_SPINLOCK(ip_fb_id_lock);
static u32 ip_fallback_id;
u32 salt;
spin_lock_bh(&ip_fb_id_lock);
salt = secure_ip_id((__force __be32)ip_fallback_id ^ iph->daddr);
iph->id = htons(salt & 0xFFFF);
ip_fallback_id = salt;
spin_unlock_bh(&ip_fb_id_lock);
}
void __ip_select_ident(struct iphdr *iph, struct dst_entry *dst, int more)
{
struct rtable *rt = (struct rtable *) dst;
if (rt) {
if (rt->peer == NULL)
rt_bind_peer(rt, rt->rt_dst, 1);
if (rt->peer) {
iph->id = htons(inet_getid(rt->peer, more));
return;
}
} else
printk(KERN_DEBUG "rt_bind_peer(0) @%p\n",
__builtin_return_address(0));
ip_select_fb_ident(iph);
}
static void rt_del(unsigned hash, struct rtable *rt)
{
struct rtable __rcu **rthp;
struct rtable *aux;
rthp = &rt_hash_table[hash].chain;
spin_lock_bh(rt_hash_lock_addr(hash));
ip_rt_put(rt);
while ((aux = rcu_dereference_protected(*rthp,
lockdep_is_held(rt_hash_lock_addr(hash)))) != NULL) {
if (aux == rt || rt_is_expired(aux)) {
*rthp = aux->dst.rt_next;
rt_free(aux);
continue;
}
rthp = &aux->dst.rt_next;
}
spin_unlock_bh(rt_hash_lock_addr(hash));
}
void ip_rt_redirect(__be32 old_gw, __be32 daddr, __be32 new_gw,
__be32 saddr, struct net_device *dev)
{
struct in_device *in_dev = __in_dev_get_rcu(dev);
struct inet_peer *peer;
struct net *net;
if (!in_dev)
return;
net = dev_net(dev);
if (new_gw == old_gw || !IN_DEV_RX_REDIRECTS(in_dev) ||
ipv4_is_multicast(new_gw) || ipv4_is_lbcast(new_gw) ||
ipv4_is_zeronet(new_gw))
goto reject_redirect;
if (!IN_DEV_SHARED_MEDIA(in_dev)) {
if (!inet_addr_onlink(in_dev, new_gw, old_gw))
goto reject_redirect;
if (IN_DEV_SEC_REDIRECTS(in_dev) && ip_fib_check_default(new_gw, dev))
goto reject_redirect;
} else {
if (inet_addr_type(net, new_gw) != RTN_UNICAST)
goto reject_redirect;
}
peer = inet_getpeer_v4(daddr, 1);
if (peer) {
peer->redirect_learned.a4 = new_gw;
inet_putpeer(peer);
atomic_inc(&__rt_peer_genid);
}
return;
reject_redirect:
#ifdef CONFIG_IP_ROUTE_VERBOSE
if (IN_DEV_LOG_MARTIANS(in_dev) && net_ratelimit())
printk(KERN_INFO "Redirect from %pI4 on %s about %pI4 ignored.\n"
" Advised path = %pI4 -> %pI4\n",
&old_gw, dev->name, &new_gw,
&saddr, &daddr);
#endif
;
}
static bool peer_pmtu_expired(struct inet_peer *peer)
{
unsigned long orig = ACCESS_ONCE(peer->pmtu_expires);
return orig &&
time_after_eq(jiffies, orig) &&
cmpxchg(&peer->pmtu_expires, orig, 0) == orig;
}
static bool peer_pmtu_cleaned(struct inet_peer *peer)
{
unsigned long orig = ACCESS_ONCE(peer->pmtu_expires);
return orig &&
cmpxchg(&peer->pmtu_expires, orig, 0) == orig;
}
static struct dst_entry *ipv4_negative_advice(struct dst_entry *dst)
{
struct rtable *rt = (struct rtable *)dst;
struct dst_entry *ret = dst;
if (rt) {
if (dst->obsolete > 0) {
ip_rt_put(rt);
ret = NULL;
} else if (rt->rt_flags & RTCF_REDIRECTED) {
unsigned hash = rt_hash(rt->rt_key_dst, rt->rt_key_src,
rt->rt_oif,
rt_genid(dev_net(dst->dev)));
rt_del(hash, rt);
ret = NULL;
} else if (rt->peer && peer_pmtu_expired(rt->peer)) {
dst_metric_set(dst, RTAX_MTU, rt->peer->pmtu_orig);
}
}
return ret;
}
void ip_rt_send_redirect(struct sk_buff *skb)
{
struct rtable *rt = skb_rtable(skb);
struct in_device *in_dev;
struct inet_peer *peer;
int log_martians;
rcu_read_lock();
in_dev = __in_dev_get_rcu(rt->dst.dev);
if (!in_dev || !IN_DEV_TX_REDIRECTS(in_dev)) {
rcu_read_unlock();
return;
}
log_martians = IN_DEV_LOG_MARTIANS(in_dev);
rcu_read_unlock();
if (!rt->peer)
rt_bind_peer(rt, rt->rt_dst, 1);
peer = rt->peer;
if (!peer) {
icmp_send(skb, ICMP_REDIRECT, ICMP_REDIR_HOST, rt->rt_gateway);
return;
}
if (time_after(jiffies, peer->rate_last + ip_rt_redirect_silence))
peer->rate_tokens = 0;
if (peer->rate_tokens >= ip_rt_redirect_number) {
peer->rate_last = jiffies;
return;
}
if (peer->rate_tokens == 0 ||
time_after(jiffies,
(peer->rate_last +
(ip_rt_redirect_load << peer->rate_tokens)))) {
icmp_send(skb, ICMP_REDIRECT, ICMP_REDIR_HOST, rt->rt_gateway);
peer->rate_last = jiffies;
++peer->rate_tokens;
#ifdef CONFIG_IP_ROUTE_VERBOSE
if (log_martians &&
peer->rate_tokens == ip_rt_redirect_number &&
net_ratelimit())
printk(KERN_WARNING "host %pI4/if%d ignores redirects for %pI4 to %pI4.\n",
&ip_hdr(skb)->saddr, rt->rt_iif,
&rt->rt_dst, &rt->rt_gateway);
#endif
}
}
static int ip_error(struct sk_buff *skb)
{
struct rtable *rt = skb_rtable(skb);
struct inet_peer *peer;
unsigned long now;
bool send;
int code;
switch (rt->dst.error) {
case EINVAL:
default:
goto out;
case EHOSTUNREACH:
code = ICMP_HOST_UNREACH;
break;
case ENETUNREACH:
code = ICMP_NET_UNREACH;
IP_INC_STATS_BH(dev_net(rt->dst.dev),
IPSTATS_MIB_INNOROUTES);
break;
case EACCES:
code = ICMP_PKT_FILTERED;
break;
}
if (!rt->peer)
rt_bind_peer(rt, rt->rt_dst, 1);
peer = rt->peer;
send = true;
if (peer) {
now = jiffies;
peer->rate_tokens += now - peer->rate_last;
if (peer->rate_tokens > ip_rt_error_burst)
peer->rate_tokens = ip_rt_error_burst;
peer->rate_last = now;
if (peer->rate_tokens >= ip_rt_error_cost)
peer->rate_tokens -= ip_rt_error_cost;
else
send = false;
}
if (send)
icmp_send(skb, ICMP_DEST_UNREACH, code, 0);
out: kfree_skb(skb);
return 0;
}
static inline unsigned short guess_mtu(unsigned short old_mtu)
{
int i;
for (i = 0; i < ARRAY_SIZE(mtu_plateau); i++)
if (old_mtu > mtu_plateau[i])
return mtu_plateau[i];
return 68;
}
unsigned short ip_rt_frag_needed(struct net *net, const struct iphdr *iph,
unsigned short new_mtu,
struct net_device *dev)
{
unsigned short old_mtu = ntohs(iph->tot_len);
unsigned short est_mtu = 0;
struct inet_peer *peer;
peer = inet_getpeer_v4(iph->daddr, 1);
if (peer) {
unsigned short mtu = new_mtu;
if (new_mtu < 68 || new_mtu >= old_mtu) {
if (mtu == 0 &&
old_mtu >= 68 + (iph->ihl << 2))
old_mtu -= iph->ihl << 2;
mtu = guess_mtu(old_mtu);
}
if (mtu < ip_rt_min_pmtu)
mtu = ip_rt_min_pmtu;
if (!peer->pmtu_expires || mtu < peer->pmtu_learned) {
unsigned long pmtu_expires;
pmtu_expires = jiffies + ip_rt_mtu_expires;
if (!pmtu_expires)
pmtu_expires = 1UL;
est_mtu = mtu;
peer->pmtu_learned = mtu;
peer->pmtu_expires = pmtu_expires;
}
inet_putpeer(peer);
atomic_inc(&__rt_peer_genid);
}
return est_mtu ? : new_mtu;
}
static void check_peer_pmtu(struct dst_entry *dst, struct inet_peer *peer)
{
unsigned long expires = ACCESS_ONCE(peer->pmtu_expires);
if (!expires)
return;
if (time_before(jiffies, expires)) {
u32 orig_dst_mtu = dst_mtu(dst);
if (peer->pmtu_learned < orig_dst_mtu) {
if (!peer->pmtu_orig)
peer->pmtu_orig = dst_metric_raw(dst, RTAX_MTU);
dst_metric_set(dst, RTAX_MTU, peer->pmtu_learned);
}
} else if (cmpxchg(&peer->pmtu_expires, expires, 0) == expires)
dst_metric_set(dst, RTAX_MTU, peer->pmtu_orig);
}
static void ip_rt_update_pmtu(struct dst_entry *dst, u32 mtu)
{
struct rtable *rt = (struct rtable *) dst;
struct inet_peer *peer;
dst_confirm(dst);
if (!rt->peer)
rt_bind_peer(rt, rt->rt_dst, 1);
peer = rt->peer;
if (peer) {
unsigned long pmtu_expires = ACCESS_ONCE(peer->pmtu_expires);
if (mtu < ip_rt_min_pmtu)
mtu = ip_rt_min_pmtu;
if (!pmtu_expires || mtu < peer->pmtu_learned) {
pmtu_expires = jiffies + ip_rt_mtu_expires;
if (!pmtu_expires)
pmtu_expires = 1UL;
peer->pmtu_learned = mtu;
peer->pmtu_expires = pmtu_expires;
atomic_inc(&__rt_peer_genid);
rt->rt_peer_genid = rt_peer_genid();
}
check_peer_pmtu(dst, peer);
}
}
static int check_peer_redir(struct dst_entry *dst, struct inet_peer *peer)
{
struct rtable *rt = (struct rtable *) dst;
__be32 orig_gw = rt->rt_gateway;
dst_confirm(&rt->dst);
neigh_release(rt->dst.neighbour);
rt->dst.neighbour = NULL;
rt->rt_gateway = peer->redirect_learned.a4;
if (arp_bind_neighbour(&rt->dst) ||
!(rt->dst.neighbour->nud_state & NUD_VALID)) {
if (rt->dst.neighbour)
neigh_event_send(rt->dst.neighbour, NULL);
rt->rt_gateway = orig_gw;
return -EAGAIN;
} else {
rt->rt_flags |= RTCF_REDIRECTED;
call_netevent_notifiers(NETEVENT_NEIGH_UPDATE,
rt->dst.neighbour);
}
return 0;
}
static struct dst_entry *ipv4_dst_check(struct dst_entry *dst, u32 cookie)
{
struct rtable *rt = (struct rtable *) dst;
if (rt_is_expired(rt))
return NULL;
if (rt->rt_peer_genid != rt_peer_genid()) {
struct inet_peer *peer;
if (!rt->peer)
rt_bind_peer(rt, rt->rt_dst, 0);
peer = rt->peer;
if (peer) {
check_peer_pmtu(dst, peer);
if (peer->redirect_learned.a4 &&
peer->redirect_learned.a4 != rt->rt_gateway) {
if (check_peer_redir(dst, peer))
return NULL;
}
}
rt->rt_peer_genid = rt_peer_genid();
}
return dst;
}
static void ipv4_dst_destroy(struct dst_entry *dst)
{
struct rtable *rt = (struct rtable *) dst;
struct inet_peer *peer = rt->peer;
if (rt->fi) {
fib_info_put(rt->fi);
rt->fi = NULL;
}
if (peer) {
rt->peer = NULL;
inet_putpeer(peer);
}
}
static void ipv4_link_failure(struct sk_buff *skb)
{
struct rtable *rt;
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_HOST_UNREACH, 0);
rt = skb_rtable(skb);
if (rt && rt->peer && peer_pmtu_cleaned(rt->peer))
dst_metric_set(&rt->dst, RTAX_MTU, rt->peer->pmtu_orig);
}
static int ip_rt_bug(struct sk_buff *skb)
{
printk(KERN_DEBUG "ip_rt_bug: %pI4 -> %pI4, %s\n",
&ip_hdr(skb)->saddr, &ip_hdr(skb)->daddr,
skb->dev ? skb->dev->name : "?");
kfree_skb(skb);
WARN_ON(1);
return 0;
}
void ip_rt_get_source(u8 *addr, struct sk_buff *skb, struct rtable *rt)
{
__be32 src;
if (rt_is_output_route(rt))
src = ip_hdr(skb)->saddr;
else {
struct fib_result res;
struct flowi4 fl4;
struct iphdr *iph;
iph = ip_hdr(skb);
memset(&fl4, 0, sizeof(fl4));
fl4.daddr = iph->daddr;
fl4.saddr = iph->saddr;
fl4.flowi4_tos = iph->tos;
fl4.flowi4_oif = rt->dst.dev->ifindex;
fl4.flowi4_iif = skb->dev->ifindex;
fl4.flowi4_mark = skb->mark;
rcu_read_lock();
if (fib_lookup(dev_net(rt->dst.dev), &fl4, &res) == 0)
src = FIB_RES_PREFSRC(dev_net(rt->dst.dev), res);
else
src = inet_select_addr(rt->dst.dev, rt->rt_gateway,
RT_SCOPE_UNIVERSE);
rcu_read_unlock();
}
memcpy(addr, &src, 4);
}
static void set_class_tag(struct rtable *rt, u32 tag)
{
if (!(rt->dst.tclassid & 0xFFFF))
rt->dst.tclassid |= tag & 0xFFFF;
if (!(rt->dst.tclassid & 0xFFFF0000))
rt->dst.tclassid |= tag & 0xFFFF0000;
}
static unsigned int ipv4_default_advmss(const struct dst_entry *dst)
{
unsigned int advmss = dst_metric_raw(dst, RTAX_ADVMSS);
if (advmss == 0) {
advmss = max_t(unsigned int, dst->dev->mtu - 40,
ip_rt_min_advmss);
if (advmss > 65535 - 40)
advmss = 65535 - 40;
}
return advmss;
}
static unsigned int ipv4_default_mtu(const struct dst_entry *dst)
{
unsigned int mtu = dst->dev->mtu;
if (unlikely(dst_metric_locked(dst, RTAX_MTU))) {
const struct rtable *rt = (const struct rtable *) dst;
if (rt->rt_gateway != rt->rt_dst && mtu > 576)
mtu = 576;
}
if (mtu > IP_MAX_MTU)
mtu = IP_MAX_MTU;
return mtu;
}
static void rt_init_metrics(struct rtable *rt, const struct flowi4 *fl4,
struct fib_info *fi)
{
struct inet_peer *peer;
int create = 0;
if (fl4 && (fl4->flowi4_flags & FLOWI_FLAG_PRECOW_METRICS))
create = 1;
rt->peer = peer = inet_getpeer_v4(rt->rt_dst, create);
if (peer) {
rt->rt_peer_genid = rt_peer_genid();
if (inet_metrics_new(peer))
memcpy(peer->metrics, fi->fib_metrics,
sizeof(u32) * RTAX_MAX);
dst_init_metrics(&rt->dst, peer->metrics, false);
check_peer_pmtu(&rt->dst, peer);
if (peer->redirect_learned.a4 &&
peer->redirect_learned.a4 != rt->rt_gateway) {
rt->rt_gateway = peer->redirect_learned.a4;
rt->rt_flags |= RTCF_REDIRECTED;
}
} else {
if (fi->fib_metrics != (u32 *) dst_default_metrics) {
rt->fi = fi;
atomic_inc(&fi->fib_clntref);
}
dst_init_metrics(&rt->dst, fi->fib_metrics, true);
}
}
static void rt_set_nexthop(struct rtable *rt, const struct flowi4 *fl4,
const struct fib_result *res,
struct fib_info *fi, u16 type, u32 itag)
{
struct dst_entry *dst = &rt->dst;
if (fi) {
if (FIB_RES_GW(*res) &&
FIB_RES_NH(*res).nh_scope == RT_SCOPE_LINK)
rt->rt_gateway = FIB_RES_GW(*res);
rt_init_metrics(rt, fl4, fi);
#ifdef CONFIG_IP_ROUTE_CLASSID
dst->tclassid = FIB_RES_NH(*res).nh_tclassid;
#endif
}
if (dst_mtu(dst) > IP_MAX_MTU)
dst_metric_set(dst, RTAX_MTU, IP_MAX_MTU);
if (dst_metric_raw(dst, RTAX_ADVMSS) > 65535 - 40)
dst_metric_set(dst, RTAX_ADVMSS, 65535 - 40);
#ifdef CONFIG_IP_ROUTE_CLASSID
#ifdef CONFIG_IP_MULTIPLE_TABLES
set_class_tag(rt, fib_rules_tclass(res));
#endif
set_class_tag(rt, itag);
#endif
}
static struct rtable *rt_dst_alloc(struct net_device *dev,
bool nopolicy, bool noxfrm)
{
return dst_alloc(&ipv4_dst_ops, dev, 1, -1,
DST_HOST |
(nopolicy ? DST_NOPOLICY : 0) |
(noxfrm ? DST_NOXFRM : 0));
}
static int ip_route_input_mc(struct sk_buff *skb, __be32 daddr, __be32 saddr,
u8 tos, struct net_device *dev, int our)
{
unsigned int hash;
struct rtable *rth;
__be32 spec_dst;
struct in_device *in_dev = __in_dev_get_rcu(dev);
u32 itag = 0;
int err;
if (in_dev == NULL)
return -EINVAL;
if (ipv4_is_multicast(saddr) || ipv4_is_lbcast(saddr) ||
ipv4_is_loopback(saddr) || skb->protocol != htons(ETH_P_IP))
goto e_inval;
if (ipv4_is_zeronet(saddr)) {
if (!ipv4_is_local_multicast(daddr))
goto e_inval;
spec_dst = inet_select_addr(dev, 0, RT_SCOPE_LINK);
} else {
err = fib_validate_source(skb, saddr, 0, tos, 0, dev, &spec_dst,
&itag);
if (err < 0)
goto e_err;
}
rth = rt_dst_alloc(init_net.loopback_dev,
IN_DEV_CONF_GET(in_dev, NOPOLICY), false);
if (!rth)
goto e_nobufs;
#ifdef CONFIG_IP_ROUTE_CLASSID
rth->dst.tclassid = itag;
#endif
rth->dst.output = ip_rt_bug;
rth->rt_key_dst = daddr;
rth->rt_key_src = saddr;
rth->rt_genid = rt_genid(dev_net(dev));
rth->rt_flags = RTCF_MULTICAST;
rth->rt_type = RTN_MULTICAST;
rth->rt_key_tos = tos;
rth->rt_dst = daddr;
rth->rt_src = saddr;
rth->rt_route_iif = dev->ifindex;
rth->rt_iif = dev->ifindex;
rth->rt_oif = 0;
rth->rt_mark = skb->mark;
rth->rt_gateway = daddr;
rth->rt_spec_dst= spec_dst;
rth->rt_peer_genid = 0;
rth->peer = NULL;
rth->fi = NULL;
if (our) {
rth->dst.input= ip_local_deliver;
rth->rt_flags |= RTCF_LOCAL;
}
#ifdef CONFIG_IP_MROUTE
if (!ipv4_is_local_multicast(daddr) && IN_DEV_MFORWARD(in_dev))
rth->dst.input = ip_mr_input;
#endif
RT_CACHE_STAT_INC(in_slow_mc);
hash = rt_hash(daddr, saddr, dev->ifindex, rt_genid(dev_net(dev)));
rth = rt_intern_hash(hash, rth, skb, dev->ifindex);
return IS_ERR(rth) ? PTR_ERR(rth) : 0;
e_nobufs:
return -ENOBUFS;
e_inval:
return -EINVAL;
e_err:
return err;
}
static void ip_handle_martian_source(struct net_device *dev,
struct in_device *in_dev,
struct sk_buff *skb,
__be32 daddr,
__be32 saddr)
{
RT_CACHE_STAT_INC(in_martian_src);
#ifdef CONFIG_IP_ROUTE_VERBOSE
if (IN_DEV_LOG_MARTIANS(in_dev) && net_ratelimit()) {
printk(KERN_WARNING "martian source %pI4 from %pI4, on dev %s\n",
&daddr, &saddr, dev->name);
if (dev->hard_header_len && skb_mac_header_was_set(skb)) {
int i;
const unsigned char *p = skb_mac_header(skb);
printk(KERN_WARNING "ll header: ");
for (i = 0; i < dev->hard_header_len; i++, p++) {
printk("%02x", *p);
if (i < (dev->hard_header_len - 1))
printk(":");
}
printk("\n");
}
}
#endif
}
static int __mkroute_input(struct sk_buff *skb,
const struct fib_result *res,
struct in_device *in_dev,
__be32 daddr, __be32 saddr, u32 tos,
struct rtable **result)
{
struct rtable *rth;
int err;
struct in_device *out_dev;
unsigned int flags = 0;
__be32 spec_dst;
u32 itag;
out_dev = __in_dev_get_rcu(FIB_RES_DEV(*res));
if (out_dev == NULL) {
if (net_ratelimit())
printk(KERN_CRIT "Bug in ip_route_input" \
"_slow(). Please, report\n");
return -EINVAL;
}
err = fib_validate_source(skb, saddr, daddr, tos, FIB_RES_OIF(*res),
in_dev->dev, &spec_dst, &itag);
if (err < 0) {
ip_handle_martian_source(in_dev->dev, in_dev, skb, daddr,
saddr);
goto cleanup;
}
if (err)
flags |= RTCF_DIRECTSRC;
if (out_dev == in_dev && err &&
(IN_DEV_SHARED_MEDIA(out_dev) ||
inet_addr_onlink(out_dev, saddr, FIB_RES_GW(*res))))
flags |= RTCF_DOREDIRECT;
if (skb->protocol != htons(ETH_P_IP)) {
if (out_dev == in_dev &&
IN_DEV_PROXY_ARP_PVLAN(in_dev) == 0) {
err = -EINVAL;
goto cleanup;
}
}
rth = rt_dst_alloc(out_dev->dev,
IN_DEV_CONF_GET(in_dev, NOPOLICY),
IN_DEV_CONF_GET(out_dev, NOXFRM));
if (!rth) {
err = -ENOBUFS;
goto cleanup;
}
rth->rt_key_dst = daddr;
rth->rt_key_src = saddr;
rth->rt_genid = rt_genid(dev_net(rth->dst.dev));
rth->rt_flags = flags;
rth->rt_type = res->type;
rth->rt_key_tos = tos;
rth->rt_dst = daddr;
rth->rt_src = saddr;
rth->rt_route_iif = in_dev->dev->ifindex;
rth->rt_iif = in_dev->dev->ifindex;
rth->rt_oif = 0;
rth->rt_mark = skb->mark;
rth->rt_gateway = daddr;
rth->rt_spec_dst= spec_dst;
rth->rt_peer_genid = 0;
rth->peer = NULL;
rth->fi = NULL;
rth->dst.input = ip_forward;
rth->dst.output = ip_output;
rt_set_nexthop(rth, NULL, res, res->fi, res->type, itag);
*result = rth;
err = 0;
cleanup:
return err;
}
static int ip_mkroute_input(struct sk_buff *skb,
struct fib_result *res,
const struct flowi4 *fl4,
struct in_device *in_dev,
__be32 daddr, __be32 saddr, u32 tos)
{
struct rtable* rth = NULL;
int err;
unsigned hash;
#ifdef CONFIG_IP_ROUTE_MULTIPATH
if (res->fi && res->fi->fib_nhs > 1)
fib_select_multipath(res);
#endif
err = __mkroute_input(skb, res, in_dev, daddr, saddr, tos, &rth);
if (err)
return err;
hash = rt_hash(daddr, saddr, fl4->flowi4_iif,
rt_genid(dev_net(rth->dst.dev)));
rth = rt_intern_hash(hash, rth, skb, fl4->flowi4_iif);
if (IS_ERR(rth))
return PTR_ERR(rth);
return 0;
}
static int ip_route_input_slow(struct sk_buff *skb, __be32 daddr, __be32 saddr,
u8 tos, struct net_device *dev)
{
struct fib_result res;
struct in_device *in_dev = __in_dev_get_rcu(dev);
struct flowi4 fl4;
unsigned flags = 0;
u32 itag = 0;
struct rtable * rth;
unsigned hash;
__be32 spec_dst;
int err = -EINVAL;
struct net * net = dev_net(dev);
if (!in_dev)
goto out;
if (ipv4_is_multicast(saddr) || ipv4_is_lbcast(saddr) ||
ipv4_is_loopback(saddr))
goto martian_source;
if (ipv4_is_lbcast(daddr) || (saddr == 0 && daddr == 0))
goto brd_input;
if (ipv4_is_zeronet(saddr))
goto martian_source;
if (ipv4_is_zeronet(daddr) || ipv4_is_loopback(daddr))
goto martian_destination;
fl4.flowi4_oif = 0;
fl4.flowi4_iif = dev->ifindex;
fl4.flowi4_mark = skb->mark;
fl4.flowi4_tos = tos;
fl4.flowi4_scope = RT_SCOPE_UNIVERSE;
fl4.daddr = daddr;
fl4.saddr = saddr;
err = fib_lookup(net, &fl4, &res);
if (err != 0) {
if (!IN_DEV_FORWARD(in_dev))
goto e_hostunreach;
goto no_route;
}
RT_CACHE_STAT_INC(in_slow_tot);
if (res.type == RTN_BROADCAST)
goto brd_input;
if (res.type == RTN_LOCAL) {
err = fib_validate_source(skb, saddr, daddr, tos,
net->loopback_dev->ifindex,
dev, &spec_dst, &itag);
if (err < 0)
goto martian_source_keep_err;
if (err)
flags |= RTCF_DIRECTSRC;
spec_dst = daddr;
goto local_input;
}
if (!IN_DEV_FORWARD(in_dev))
goto e_hostunreach;
if (res.type != RTN_UNICAST)
goto martian_destination;
err = ip_mkroute_input(skb, &res, &fl4, in_dev, daddr, saddr, tos);
out: return err;
brd_input:
if (skb->protocol != htons(ETH_P_IP))
goto e_inval;
if (ipv4_is_zeronet(saddr))
spec_dst = inet_select_addr(dev, 0, RT_SCOPE_LINK);
else {
err = fib_validate_source(skb, saddr, 0, tos, 0, dev, &spec_dst,
&itag);
if (err < 0)
goto martian_source_keep_err;
if (err)
flags |= RTCF_DIRECTSRC;
}
flags |= RTCF_BROADCAST;
res.type = RTN_BROADCAST;
RT_CACHE_STAT_INC(in_brd);
local_input:
rth = rt_dst_alloc(net->loopback_dev,
IN_DEV_CONF_GET(in_dev, NOPOLICY), false);
if (!rth)
goto e_nobufs;
rth->dst.input= ip_local_deliver;
rth->dst.output= ip_rt_bug;
#ifdef CONFIG_IP_ROUTE_CLASSID
rth->dst.tclassid = itag;
#endif
rth->rt_key_dst = daddr;
rth->rt_key_src = saddr;
rth->rt_genid = rt_genid(net);
rth->rt_flags = flags|RTCF_LOCAL;
rth->rt_type = res.type;
rth->rt_key_tos = tos;
rth->rt_dst = daddr;
rth->rt_src = saddr;
#ifdef CONFIG_IP_ROUTE_CLASSID
rth->dst.tclassid = itag;
#endif
rth->rt_route_iif = dev->ifindex;
rth->rt_iif = dev->ifindex;
rth->rt_oif = 0;
rth->rt_mark = skb->mark;
rth->rt_gateway = daddr;
rth->rt_spec_dst= spec_dst;
rth->rt_peer_genid = 0;
rth->peer = NULL;
rth->fi = NULL;
if (res.type == RTN_UNREACHABLE) {
rth->dst.input= ip_error;
rth->dst.error= -err;
rth->rt_flags &= ~RTCF_LOCAL;
}
hash = rt_hash(daddr, saddr, fl4.flowi4_iif, rt_genid(net));
rth = rt_intern_hash(hash, rth, skb, fl4.flowi4_iif);
err = 0;
if (IS_ERR(rth))
err = PTR_ERR(rth);
goto out;
no_route:
RT_CACHE_STAT_INC(in_no_route);
spec_dst = inet_select_addr(dev, 0, RT_SCOPE_UNIVERSE);
res.type = RTN_UNREACHABLE;
if (err == -ESRCH)
err = -ENETUNREACH;
goto local_input;
martian_destination:
RT_CACHE_STAT_INC(in_martian_dst);
#ifdef CONFIG_IP_ROUTE_VERBOSE
if (IN_DEV_LOG_MARTIANS(in_dev) && net_ratelimit())
printk(KERN_WARNING "martian destination %pI4 from %pI4, dev %s\n",
&daddr, &saddr, dev->name);
#endif
e_hostunreach:
err = -EHOSTUNREACH;
goto out;
e_inval:
err = -EINVAL;
goto out;
e_nobufs:
err = -ENOBUFS;
goto out;
martian_source:
err = -EINVAL;
martian_source_keep_err:
ip_handle_martian_source(dev, in_dev, skb, daddr, saddr);
goto out;
}
int ip_route_input_common(struct sk_buff *skb, __be32 daddr, __be32 saddr,
u8 tos, struct net_device *dev, bool noref)
{
struct rtable * rth;
unsigned hash;
int iif = dev->ifindex;
struct net *net;
int res;
net = dev_net(dev);
rcu_read_lock();
if (!rt_caching(net))
goto skip_cache;
tos &= IPTOS_RT_MASK;
hash = rt_hash(daddr, saddr, iif, rt_genid(net));
for (rth = rcu_dereference(rt_hash_table[hash].chain); rth;
rth = rcu_dereference(rth->dst.rt_next)) {
if ((((__force u32)rth->rt_key_dst ^ (__force u32)daddr) |
((__force u32)rth->rt_key_src ^ (__force u32)saddr) |
(rth->rt_iif ^ iif) |
rth->rt_oif |
(rth->rt_key_tos ^ tos)) == 0 &&
rth->rt_mark == skb->mark &&
net_eq(dev_net(rth->dst.dev), net) &&
!rt_is_expired(rth)) {
if (noref) {
dst_use_noref(&rth->dst, jiffies);
skb_dst_set_noref(skb, &rth->dst);
} else {
dst_use(&rth->dst, jiffies);
skb_dst_set(skb, &rth->dst);
}
RT_CACHE_STAT_INC(in_hit);
rcu_read_unlock();
return 0;
}
RT_CACHE_STAT_INC(in_hlist_search);
}
skip_cache:
if (ipv4_is_multicast(daddr)) {
struct in_device *in_dev = __in_dev_get_rcu(dev);
if (in_dev) {
int our = ip_check_mc_rcu(in_dev, daddr, saddr,
ip_hdr(skb)->protocol);
if (our
#ifdef CONFIG_IP_MROUTE
||
(!ipv4_is_local_multicast(daddr) &&
IN_DEV_MFORWARD(in_dev))
#endif
) {
int res = ip_route_input_mc(skb, daddr, saddr,
tos, dev, our);
rcu_read_unlock();
return res;
}
}
rcu_read_unlock();
return -EINVAL;
}
res = ip_route_input_slow(skb, daddr, saddr, tos, dev);
rcu_read_unlock();
return res;
}
static struct rtable *__mkroute_output(const struct fib_result *res,
const struct flowi4 *fl4,
__be32 orig_daddr, __be32 orig_saddr,
int orig_oif, struct net_device *dev_out,
unsigned int flags)
{
struct fib_info *fi = res->fi;
u32 tos = RT_FL_TOS(fl4);
struct in_device *in_dev;
u16 type = res->type;
struct rtable *rth;
if (ipv4_is_loopback(fl4->saddr) && !(dev_out->flags & IFF_LOOPBACK))
return ERR_PTR(-EINVAL);
if (ipv4_is_lbcast(fl4->daddr))
type = RTN_BROADCAST;
else if (ipv4_is_multicast(fl4->daddr))
type = RTN_MULTICAST;
else if (ipv4_is_zeronet(fl4->daddr))
return ERR_PTR(-EINVAL);
if (dev_out->flags & IFF_LOOPBACK)
flags |= RTCF_LOCAL;
in_dev = __in_dev_get_rcu(dev_out);
if (!in_dev)
return ERR_PTR(-EINVAL);
if (type == RTN_BROADCAST) {
flags |= RTCF_BROADCAST | RTCF_LOCAL;
fi = NULL;
} else if (type == RTN_MULTICAST) {
flags |= RTCF_MULTICAST | RTCF_LOCAL;
if (!ip_check_mc_rcu(in_dev, fl4->daddr, fl4->saddr,
fl4->flowi4_proto))
flags &= ~RTCF_LOCAL;
if (fi && res->prefixlen < 4)
fi = NULL;
}
rth = rt_dst_alloc(dev_out,
IN_DEV_CONF_GET(in_dev, NOPOLICY),
IN_DEV_CONF_GET(in_dev, NOXFRM));
if (!rth)
return ERR_PTR(-ENOBUFS);
rth->dst.output = ip_output;
rth->rt_key_dst = orig_daddr;
rth->rt_key_src = orig_saddr;
rth->rt_genid = rt_genid(dev_net(dev_out));
rth->rt_flags = flags;
rth->rt_type = type;
rth->rt_key_tos = tos;
rth->rt_dst = fl4->daddr;
rth->rt_src = fl4->saddr;
rth->rt_route_iif = 0;
rth->rt_iif = orig_oif ? : dev_out->ifindex;
rth->rt_oif = orig_oif;
rth->rt_mark = fl4->flowi4_mark;
rth->rt_gateway = fl4->daddr;
rth->rt_spec_dst= fl4->saddr;
rth->rt_peer_genid = 0;
rth->peer = NULL;
rth->fi = NULL;
RT_CACHE_STAT_INC(out_slow_tot);
if (flags & RTCF_LOCAL) {
rth->dst.input = ip_local_deliver;
rth->rt_spec_dst = fl4->daddr;
}
if (flags & (RTCF_BROADCAST | RTCF_MULTICAST)) {
rth->rt_spec_dst = fl4->saddr;
if (flags & RTCF_LOCAL &&
!(dev_out->flags & IFF_LOOPBACK)) {
rth->dst.output = ip_mc_output;
RT_CACHE_STAT_INC(out_slow_mc);
}
#ifdef CONFIG_IP_MROUTE
if (type == RTN_MULTICAST) {
if (IN_DEV_MFORWARD(in_dev) &&
!ipv4_is_local_multicast(fl4->daddr)) {
rth->dst.input = ip_mr_input;
rth->dst.output = ip_mc_output;
}
}
#endif
}
rt_set_nexthop(rth, fl4, res, fi, type, 0);
return rth;
}
static struct rtable *ip_route_output_slow(struct net *net, struct flowi4 *fl4)
{
struct net_device *dev_out = NULL;
u32 tos = RT_FL_TOS(fl4);
unsigned int flags = 0;
struct fib_result res;
struct rtable *rth;
__be32 orig_daddr;
__be32 orig_saddr;
int orig_oif;
res.fi = NULL;
#ifdef CONFIG_IP_MULTIPLE_TABLES
res.r = NULL;
#endif
orig_daddr = fl4->daddr;
orig_saddr = fl4->saddr;
orig_oif = fl4->flowi4_oif;
fl4->flowi4_iif = net->loopback_dev->ifindex;
fl4->flowi4_tos = tos & IPTOS_RT_MASK;
fl4->flowi4_scope = ((tos & RTO_ONLINK) ?
RT_SCOPE_LINK : RT_SCOPE_UNIVERSE);
rcu_read_lock();
if (fl4->saddr) {
rth = ERR_PTR(-EINVAL);
if (ipv4_is_multicast(fl4->saddr) ||
ipv4_is_lbcast(fl4->saddr) ||
ipv4_is_zeronet(fl4->saddr))
goto out;
if (fl4->flowi4_oif == 0 &&
(ipv4_is_multicast(fl4->daddr) ||
ipv4_is_lbcast(fl4->daddr))) {
dev_out = __ip_dev_find(net, fl4->saddr, false);
if (dev_out == NULL)
goto out;
fl4->flowi4_oif = dev_out->ifindex;
goto make_route;
}
if (!(fl4->flowi4_flags & FLOWI_FLAG_ANYSRC)) {
if (!__ip_dev_find(net, fl4->saddr, false))
goto out;
}
}
if (fl4->flowi4_oif) {
dev_out = dev_get_by_index_rcu(net, fl4->flowi4_oif);
rth = ERR_PTR(-ENODEV);
if (dev_out == NULL)
goto out;
if (!(dev_out->flags & IFF_UP) || !__in_dev_get_rcu(dev_out)) {
rth = ERR_PTR(-ENETUNREACH);
goto out;
}
if (ipv4_is_local_multicast(fl4->daddr) ||
ipv4_is_lbcast(fl4->daddr)) {
if (!fl4->saddr)
fl4->saddr = inet_select_addr(dev_out, 0,
RT_SCOPE_LINK);
goto make_route;
}
if (fl4->saddr) {
if (ipv4_is_multicast(fl4->daddr))
fl4->saddr = inet_select_addr(dev_out, 0,
fl4->flowi4_scope);
else if (!fl4->daddr)
fl4->saddr = inet_select_addr(dev_out, 0,
RT_SCOPE_HOST);
}
}
if (!fl4->daddr) {
fl4->daddr = fl4->saddr;
if (!fl4->daddr)
fl4->daddr = fl4->saddr = htonl(INADDR_LOOPBACK);
dev_out = net->loopback_dev;
fl4->flowi4_oif = net->loopback_dev->ifindex;
res.type = RTN_LOCAL;
flags |= RTCF_LOCAL;
goto make_route;
}
if (fib_lookup(net, fl4, &res)) {
res.fi = NULL;
if (fl4->flowi4_oif) {
if (fl4->saddr == 0)
fl4->saddr = inet_select_addr(dev_out, 0,
RT_SCOPE_LINK);
res.type = RTN_UNICAST;
goto make_route;
}
rth = ERR_PTR(-ENETUNREACH);
goto out;
}
if (res.type == RTN_LOCAL) {
if (!fl4->saddr) {
if (res.fi->fib_prefsrc)
fl4->saddr = res.fi->fib_prefsrc;
else
fl4->saddr = fl4->daddr;
}
dev_out = net->loopback_dev;
fl4->flowi4_oif = dev_out->ifindex;
res.fi = NULL;
flags |= RTCF_LOCAL;
goto make_route;
}
#ifdef CONFIG_IP_ROUTE_MULTIPATH
if (res.fi->fib_nhs > 1 && fl4->flowi4_oif == 0)
fib_select_multipath(&res);
else
#endif
if (!res.prefixlen &&
res.table->tb_num_default > 1 &&
res.type == RTN_UNICAST && !fl4->flowi4_oif)
fib_select_default(&res);
if (!fl4->saddr)
fl4->saddr = FIB_RES_PREFSRC(net, res);
dev_out = FIB_RES_DEV(res);
fl4->flowi4_oif = dev_out->ifindex;
make_route:
rth = __mkroute_output(&res, fl4, orig_daddr, orig_saddr, orig_oif,
dev_out, flags);
if (!IS_ERR(rth)) {
unsigned int hash;
hash = rt_hash(orig_daddr, orig_saddr, orig_oif,
rt_genid(dev_net(dev_out)));
rth = rt_intern_hash(hash, rth, NULL, orig_oif);
}
out:
rcu_read_unlock();
return rth;
}
struct rtable *__ip_route_output_key(struct net *net, struct flowi4 *flp4)
{
struct rtable *rth;
unsigned int hash;
if (!rt_caching(net))
goto slow_output;
hash = rt_hash(flp4->daddr, flp4->saddr, flp4->flowi4_oif, rt_genid(net));
rcu_read_lock_bh();
for (rth = rcu_dereference_bh(rt_hash_table[hash].chain); rth;
rth = rcu_dereference_bh(rth->dst.rt_next)) {
if (rth->rt_key_dst == flp4->daddr &&
rth->rt_key_src == flp4->saddr &&
rt_is_output_route(rth) &&
rth->rt_oif == flp4->flowi4_oif &&
rth->rt_mark == flp4->flowi4_mark &&
!((rth->rt_key_tos ^ flp4->flowi4_tos) &
(IPTOS_RT_MASK | RTO_ONLINK)) &&
net_eq(dev_net(rth->dst.dev), net) &&
!rt_is_expired(rth)) {
dst_use(&rth->dst, jiffies);
RT_CACHE_STAT_INC(out_hit);
rcu_read_unlock_bh();
if (!flp4->saddr)
flp4->saddr = rth->rt_src;
if (!flp4->daddr)
flp4->daddr = rth->rt_dst;
return rth;
}
RT_CACHE_STAT_INC(out_hlist_search);
}
rcu_read_unlock_bh();
slow_output:
return ip_route_output_slow(net, flp4);
}
static struct dst_entry *ipv4_blackhole_dst_check(struct dst_entry *dst, u32 cookie)
{
return NULL;
}
static unsigned int ipv4_blackhole_default_mtu(const struct dst_entry *dst)
{
return 0;
}
static void ipv4_rt_blackhole_update_pmtu(struct dst_entry *dst, u32 mtu)
{
}
static u32 *ipv4_rt_blackhole_cow_metrics(struct dst_entry *dst,
unsigned long old)
{
return NULL;
}
struct dst_entry *ipv4_blackhole_route(struct net *net, struct dst_entry *dst_orig)
{
struct rtable *rt = dst_alloc(&ipv4_dst_blackhole_ops, NULL, 1, 0, 0);
struct rtable *ort = (struct rtable *) dst_orig;
if (rt) {
struct dst_entry *new = &rt->dst;
new->__use = 1;
new->input = dst_discard;
new->output = dst_discard;
dst_copy_metrics(new, &ort->dst);
new->dev = ort->dst.dev;
if (new->dev)
dev_hold(new->dev);
rt->rt_key_dst = ort->rt_key_dst;
rt->rt_key_src = ort->rt_key_src;
rt->rt_key_tos = ort->rt_key_tos;
rt->rt_route_iif = ort->rt_route_iif;
rt->rt_iif = ort->rt_iif;
rt->rt_oif = ort->rt_oif;
rt->rt_mark = ort->rt_mark;
rt->rt_genid = rt_genid(net);
rt->rt_flags = ort->rt_flags;
rt->rt_type = ort->rt_type;
rt->rt_dst = ort->rt_dst;
rt->rt_src = ort->rt_src;
rt->rt_gateway = ort->rt_gateway;
rt->rt_spec_dst = ort->rt_spec_dst;
rt->peer = ort->peer;
if (rt->peer)
atomic_inc(&rt->peer->refcnt);
rt->fi = ort->fi;
if (rt->fi)
atomic_inc(&rt->fi->fib_clntref);
dst_free(new);
}
dst_release(dst_orig);
return rt ? &rt->dst : ERR_PTR(-ENOMEM);
}
struct rtable *ip_route_output_flow(struct net *net, struct flowi4 *flp4,
struct sock *sk)
{
struct rtable *rt = __ip_route_output_key(net, flp4);
if (IS_ERR(rt))
return rt;
if (flp4->flowi4_proto)
rt = (struct rtable *) xfrm_lookup(net, &rt->dst,
flowi4_to_flowi(flp4),
sk, 0);
return rt;
}
static int rt_fill_info(struct net *net,
struct sk_buff *skb, u32 pid, u32 seq, int event,
int nowait, unsigned int flags)
{
struct rtable *rt = skb_rtable(skb);
struct rtmsg *r;
struct nlmsghdr *nlh;
long expires = 0;
const struct inet_peer *peer = rt->peer;
u32 id = 0, ts = 0, tsage = 0, error;
nlh = nlmsg_put(skb, pid, seq, event, sizeof(*r), flags);
if (nlh == NULL)
return -EMSGSIZE;
r = nlmsg_data(nlh);
r->rtm_family = AF_INET;
r->rtm_dst_len = 32;
r->rtm_src_len = 0;
r->rtm_tos = rt->rt_key_tos;
r->rtm_table = RT_TABLE_MAIN;
NLA_PUT_U32(skb, RTA_TABLE, RT_TABLE_MAIN);
r->rtm_type = rt->rt_type;
r->rtm_scope = RT_SCOPE_UNIVERSE;
r->rtm_protocol = RTPROT_UNSPEC;
r->rtm_flags = (rt->rt_flags & ~0xFFFF) | RTM_F_CLONED;
if (rt->rt_flags & RTCF_NOTIFY)
r->rtm_flags |= RTM_F_NOTIFY;
NLA_PUT_BE32(skb, RTA_DST, rt->rt_dst);
if (rt->rt_key_src) {
r->rtm_src_len = 32;
NLA_PUT_BE32(skb, RTA_SRC, rt->rt_key_src);
}
if (rt->dst.dev)
NLA_PUT_U32(skb, RTA_OIF, rt->dst.dev->ifindex);
#ifdef CONFIG_IP_ROUTE_CLASSID
if (rt->dst.tclassid)
NLA_PUT_U32(skb, RTA_FLOW, rt->dst.tclassid);
#endif
if (rt_is_input_route(rt))
NLA_PUT_BE32(skb, RTA_PREFSRC, rt->rt_spec_dst);
else if (rt->rt_src != rt->rt_key_src)
NLA_PUT_BE32(skb, RTA_PREFSRC, rt->rt_src);
if (rt->rt_dst != rt->rt_gateway)
NLA_PUT_BE32(skb, RTA_GATEWAY, rt->rt_gateway);
if (rtnetlink_put_metrics(skb, dst_metrics_ptr(&rt->dst)) < 0)
goto nla_put_failure;
if (rt->rt_mark)
NLA_PUT_BE32(skb, RTA_MARK, rt->rt_mark);
error = rt->dst.error;
if (peer) {
inet_peer_refcheck(rt->peer);
id = atomic_read(&peer->ip_id_count) & 0xffff;
if (peer->tcp_ts_stamp) {
ts = peer->tcp_ts;
tsage = get_seconds() - peer->tcp_ts_stamp;
}
expires = ACCESS_ONCE(peer->pmtu_expires);
if (expires)
expires -= jiffies;
}
if (rt_is_input_route(rt)) {
#ifdef CONFIG_IP_MROUTE
__be32 dst = rt->rt_dst;
if (ipv4_is_multicast(dst) && !ipv4_is_local_multicast(dst) &&
IPV4_DEVCONF_ALL(net, MC_FORWARDING)) {
int err = ipmr_get_route(net, skb,
rt->rt_src, rt->rt_dst,
r, nowait);
if (err <= 0) {
if (!nowait) {
if (err == 0)
return 0;
goto nla_put_failure;
} else {
if (err == -EMSGSIZE)
goto nla_put_failure;
error = err;
}
}
} else
#endif
NLA_PUT_U32(skb, RTA_IIF, rt->rt_iif);
}
if (rtnl_put_cacheinfo(skb, &rt->dst, id, ts, tsage,
expires, error) < 0)
goto nla_put_failure;
return nlmsg_end(skb, nlh);
nla_put_failure:
nlmsg_cancel(skb, nlh);
return -EMSGSIZE;
}
static int inet_rtm_getroute(struct sk_buff *in_skb, struct nlmsghdr* nlh, void *arg)
{
struct net *net = sock_net(in_skb->sk);
struct rtmsg *rtm;
struct nlattr *tb[RTA_MAX+1];
struct rtable *rt = NULL;
__be32 dst = 0;
__be32 src = 0;
u32 iif;
int err;
int mark;
struct sk_buff *skb;
err = nlmsg_parse(nlh, sizeof(*rtm), tb, RTA_MAX, rtm_ipv4_policy);
if (err < 0)
goto errout;
rtm = nlmsg_data(nlh);
skb = alloc_skb(NLMSG_GOODSIZE, GFP_KERNEL);
if (skb == NULL) {
err = -ENOBUFS;
goto errout;
}
skb_reset_mac_header(skb);
skb_reset_network_header(skb);
ip_hdr(skb)->protocol = IPPROTO_ICMP;
skb_reserve(skb, MAX_HEADER + sizeof(struct iphdr));
src = tb[RTA_SRC] ? nla_get_be32(tb[RTA_SRC]) : 0;
dst = tb[RTA_DST] ? nla_get_be32(tb[RTA_DST]) : 0;
iif = tb[RTA_IIF] ? nla_get_u32(tb[RTA_IIF]) : 0;
mark = tb[RTA_MARK] ? nla_get_u32(tb[RTA_MARK]) : 0;
if (iif) {
struct net_device *dev;
dev = __dev_get_by_index(net, iif);
if (dev == NULL) {
err = -ENODEV;
goto errout_free;
}
skb->protocol = htons(ETH_P_IP);
skb->dev = dev;
skb->mark = mark;
local_bh_disable();
err = ip_route_input(skb, dst, src, rtm->rtm_tos, dev);
local_bh_enable();
rt = skb_rtable(skb);
if (err == 0 && rt->dst.error)
err = -rt->dst.error;
} else {
struct flowi4 fl4 = {
.daddr = dst,
.saddr = src,
.flowi4_tos = rtm->rtm_tos,
.flowi4_oif = tb[RTA_OIF] ? nla_get_u32(tb[RTA_OIF]) : 0,
.flowi4_mark = mark,
};
rt = ip_route_output_key(net, &fl4);
err = 0;
if (IS_ERR(rt))
err = PTR_ERR(rt);
}
if (err)
goto errout_free;
skb_dst_set(skb, &rt->dst);
if (rtm->rtm_flags & RTM_F_NOTIFY)
rt->rt_flags |= RTCF_NOTIFY;
err = rt_fill_info(net, skb, NETLINK_CB(in_skb).pid, nlh->nlmsg_seq,
RTM_NEWROUTE, 0, 0);
if (err <= 0)
goto errout_free;
err = rtnl_unicast(skb, net, NETLINK_CB(in_skb).pid);
errout:
return err;
errout_free:
kfree_skb(skb);
goto errout;
}
int ip_rt_dump(struct sk_buff *skb, struct netlink_callback *cb)
{
struct rtable *rt;
int h, s_h;
int idx, s_idx;
struct net *net;
net = sock_net(skb->sk);
s_h = cb->args[0];
if (s_h < 0)
s_h = 0;
s_idx = idx = cb->args[1];
for (h = s_h; h <= rt_hash_mask; h++, s_idx = 0) {
if (!rt_hash_table[h].chain)
continue;
rcu_read_lock_bh();
for (rt = rcu_dereference_bh(rt_hash_table[h].chain), idx = 0; rt;
rt = rcu_dereference_bh(rt->dst.rt_next), idx++) {
if (!net_eq(dev_net(rt->dst.dev), net) || idx < s_idx)
continue;
if (rt_is_expired(rt))
continue;
skb_dst_set_noref(skb, &rt->dst);
if (rt_fill_info(net, skb, NETLINK_CB(cb->skb).pid,
cb->nlh->nlmsg_seq, RTM_NEWROUTE,
1, NLM_F_MULTI) <= 0) {
skb_dst_drop(skb);
rcu_read_unlock_bh();
goto done;
}
skb_dst_drop(skb);
}
rcu_read_unlock_bh();
}
done:
cb->args[0] = h;
cb->args[1] = idx;
return skb->len;
}
void ip_rt_multicast_event(struct in_device *in_dev)
{
rt_cache_flush(dev_net(in_dev->dev), 0);
}
static int ipv4_sysctl_rtcache_flush(ctl_table *__ctl, int write,
void __user *buffer,
size_t *lenp, loff_t *ppos)
{
if (write) {
int flush_delay;
ctl_table ctl;
struct net *net;
memcpy(&ctl, __ctl, sizeof(ctl));
ctl.data = &flush_delay;
proc_dointvec(&ctl, write, buffer, lenp, ppos);
net = (struct net *)__ctl->extra1;
rt_cache_flush(net, flush_delay);
return 0;
}
return -EINVAL;
}
static __net_init int sysctl_route_net_init(struct net *net)
{
struct ctl_table *tbl;
tbl = ipv4_route_flush_table;
if (!net_eq(net, &init_net)) {
tbl = kmemdup(tbl, sizeof(ipv4_route_flush_table), GFP_KERNEL);
if (tbl == NULL)
goto err_dup;
}
tbl[0].extra1 = net;
net->ipv4.route_hdr =
register_net_sysctl_table(net, ipv4_route_path, tbl);
if (net->ipv4.route_hdr == NULL)
goto err_reg;
return 0;
err_reg:
if (tbl != ipv4_route_flush_table)
kfree(tbl);
err_dup:
return -ENOMEM;
}
static __net_exit void sysctl_route_net_exit(struct net *net)
{
struct ctl_table *tbl;
tbl = net->ipv4.route_hdr->ctl_table_arg;
unregister_net_sysctl_table(net->ipv4.route_hdr);
BUG_ON(tbl == ipv4_route_flush_table);
kfree(tbl);
}
static __net_init int rt_genid_init(struct net *net)
{
get_random_bytes(&net->ipv4.rt_genid,
sizeof(net->ipv4.rt_genid));
get_random_bytes(&net->ipv4.dev_addr_genid,
sizeof(net->ipv4.dev_addr_genid));
return 0;
}
static int __init set_rhash_entries(char *str)
{
if (!str)
return 0;
rhash_entries = simple_strtoul(str, &str, 0);
return 1;
}
int __init ip_rt_init(void)
{
int rc = 0;
#ifdef CONFIG_IP_ROUTE_CLASSID
ip_rt_acct = __alloc_percpu(256 * sizeof(struct ip_rt_acct), __alignof__(struct ip_rt_acct));
if (!ip_rt_acct)
panic("IP: failed to allocate ip_rt_acct\n");
#endif
ipv4_dst_ops.kmem_cachep =
kmem_cache_create("ip_dst_cache", sizeof(struct rtable), 0,
SLAB_HWCACHE_ALIGN|SLAB_PANIC, NULL);
ipv4_dst_blackhole_ops.kmem_cachep = ipv4_dst_ops.kmem_cachep;
if (dst_entries_init(&ipv4_dst_ops) < 0)
panic("IP: failed to allocate ipv4_dst_ops counter\n");
if (dst_entries_init(&ipv4_dst_blackhole_ops) < 0)
panic("IP: failed to allocate ipv4_dst_blackhole_ops counter\n");
rt_hash_table = (struct rt_hash_bucket *)
alloc_large_system_hash("IP route cache",
sizeof(struct rt_hash_bucket),
rhash_entries,
(totalram_pages >= 128 * 1024) ?
15 : 17,
0,
&rt_hash_log,
&rt_hash_mask,
rhash_entries ? 0 : 512 * 1024);
memset(rt_hash_table, 0, (rt_hash_mask + 1) * sizeof(struct rt_hash_bucket));
rt_hash_lock_init();
ipv4_dst_ops.gc_thresh = (rt_hash_mask + 1);
ip_rt_max_size = (rt_hash_mask + 1) * 16;
devinet_init();
ip_fib_init();
if (ip_rt_proc_init())
printk(KERN_ERR "Unable to create route proc files\n");
#ifdef CONFIG_XFRM
xfrm_init();
xfrm4_init(ip_rt_max_size);
#endif
rtnl_register(PF_INET, RTM_GETROUTE, inet_rtm_getroute, NULL);
#ifdef CONFIG_SYSCTL
register_pernet_subsys(&sysctl_route_ops);
#endif
register_pernet_subsys(&rt_genid_ops);
return rc;
}
void __init ip_static_sysctl_init(void)
{
register_sysctl_paths(ipv4_path, ipv4_skeleton);
}
