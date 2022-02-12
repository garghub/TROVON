static void inet_frag_secret_rebuild(unsigned long dummy)
{
struct inet_frags *f = (struct inet_frags *)dummy;
unsigned long now = jiffies;
int i;
write_lock(&f->lock);
get_random_bytes(&f->rnd, sizeof(u32));
for (i = 0; i < INETFRAGS_HASHSZ; i++) {
struct inet_frag_bucket *hb;
struct inet_frag_queue *q;
struct hlist_node *n;
hb = &f->hash[i];
hlist_for_each_entry_safe(q, n, &hb->chain, list) {
unsigned int hval = f->hashfn(q);
if (hval != i) {
struct inet_frag_bucket *hb_dest;
hlist_del(&q->list);
hb_dest = &f->hash[hval];
hlist_add_head(&q->list, &hb_dest->chain);
}
}
}
write_unlock(&f->lock);
mod_timer(&f->secret_timer, now + f->secret_interval);
}
void inet_frags_init(struct inet_frags *f)
{
int i;
for (i = 0; i < INETFRAGS_HASHSZ; i++) {
struct inet_frag_bucket *hb = &f->hash[i];
spin_lock_init(&hb->chain_lock);
INIT_HLIST_HEAD(&hb->chain);
}
rwlock_init(&f->lock);
f->rnd = (u32) ((totalram_pages ^ (totalram_pages >> 7)) ^
(jiffies ^ (jiffies >> 6)));
setup_timer(&f->secret_timer, inet_frag_secret_rebuild,
(unsigned long)f);
f->secret_timer.expires = jiffies + f->secret_interval;
add_timer(&f->secret_timer);
}
void inet_frags_init_net(struct netns_frags *nf)
{
nf->nqueues = 0;
init_frag_mem_limit(nf);
INIT_LIST_HEAD(&nf->lru_list);
spin_lock_init(&nf->lru_lock);
}
void inet_frags_fini(struct inet_frags *f)
{
del_timer(&f->secret_timer);
}
void inet_frags_exit_net(struct netns_frags *nf, struct inet_frags *f)
{
nf->low_thresh = 0;
local_bh_disable();
inet_frag_evictor(nf, f, true);
local_bh_enable();
percpu_counter_destroy(&nf->mem);
}
static inline void fq_unlink(struct inet_frag_queue *fq, struct inet_frags *f)
{
struct inet_frag_bucket *hb;
unsigned int hash;
read_lock(&f->lock);
hash = f->hashfn(fq);
hb = &f->hash[hash];
spin_lock(&hb->chain_lock);
hlist_del(&fq->list);
spin_unlock(&hb->chain_lock);
read_unlock(&f->lock);
inet_frag_lru_del(fq);
}
void inet_frag_kill(struct inet_frag_queue *fq, struct inet_frags *f)
{
if (del_timer(&fq->timer))
atomic_dec(&fq->refcnt);
if (!(fq->last_in & INET_FRAG_COMPLETE)) {
fq_unlink(fq, f);
atomic_dec(&fq->refcnt);
fq->last_in |= INET_FRAG_COMPLETE;
}
}
static inline void frag_kfree_skb(struct netns_frags *nf, struct inet_frags *f,
struct sk_buff *skb)
{
if (f->skb_free)
f->skb_free(skb);
kfree_skb(skb);
}
void inet_frag_destroy(struct inet_frag_queue *q, struct inet_frags *f,
int *work)
{
struct sk_buff *fp;
struct netns_frags *nf;
unsigned int sum, sum_truesize = 0;
WARN_ON(!(q->last_in & INET_FRAG_COMPLETE));
WARN_ON(del_timer(&q->timer) != 0);
fp = q->fragments;
nf = q->net;
while (fp) {
struct sk_buff *xp = fp->next;
sum_truesize += fp->truesize;
frag_kfree_skb(nf, f, fp);
fp = xp;
}
sum = sum_truesize + f->qsize;
if (work)
*work -= sum;
sub_frag_mem_limit(q, sum);
if (f->destructor)
f->destructor(q);
kfree(q);
}
int inet_frag_evictor(struct netns_frags *nf, struct inet_frags *f, bool force)
{
struct inet_frag_queue *q;
int work, evicted = 0;
if (!force) {
if (frag_mem_limit(nf) <= nf->high_thresh)
return 0;
}
work = frag_mem_limit(nf) - nf->low_thresh;
while (work > 0) {
spin_lock(&nf->lru_lock);
if (list_empty(&nf->lru_list)) {
spin_unlock(&nf->lru_lock);
break;
}
q = list_first_entry(&nf->lru_list,
struct inet_frag_queue, lru_list);
atomic_inc(&q->refcnt);
list_del_init(&q->lru_list);
spin_unlock(&nf->lru_lock);
spin_lock(&q->lock);
if (!(q->last_in & INET_FRAG_COMPLETE))
inet_frag_kill(q, f);
spin_unlock(&q->lock);
if (atomic_dec_and_test(&q->refcnt))
inet_frag_destroy(q, f, &work);
evicted++;
}
return evicted;
}
static struct inet_frag_queue *inet_frag_intern(struct netns_frags *nf,
struct inet_frag_queue *qp_in, struct inet_frags *f,
void *arg)
{
struct inet_frag_bucket *hb;
struct inet_frag_queue *qp;
unsigned int hash;
read_lock(&f->lock);
hash = f->hashfn(qp_in);
hb = &f->hash[hash];
spin_lock(&hb->chain_lock);
#ifdef CONFIG_SMP
hlist_for_each_entry(qp, &hb->chain, list) {
if (qp->net == nf && f->match(qp, arg)) {
atomic_inc(&qp->refcnt);
spin_unlock(&hb->chain_lock);
read_unlock(&f->lock);
qp_in->last_in |= INET_FRAG_COMPLETE;
inet_frag_put(qp_in, f);
return qp;
}
}
#endif
qp = qp_in;
if (!mod_timer(&qp->timer, jiffies + nf->timeout))
atomic_inc(&qp->refcnt);
atomic_inc(&qp->refcnt);
hlist_add_head(&qp->list, &hb->chain);
spin_unlock(&hb->chain_lock);
read_unlock(&f->lock);
inet_frag_lru_add(nf, qp);
return qp;
}
static struct inet_frag_queue *inet_frag_alloc(struct netns_frags *nf,
struct inet_frags *f, void *arg)
{
struct inet_frag_queue *q;
q = kzalloc(f->qsize, GFP_ATOMIC);
if (q == NULL)
return NULL;
q->net = nf;
f->constructor(q, arg);
add_frag_mem_limit(q, f->qsize);
setup_timer(&q->timer, f->frag_expire, (unsigned long)q);
spin_lock_init(&q->lock);
atomic_set(&q->refcnt, 1);
INIT_LIST_HEAD(&q->lru_list);
return q;
}
static struct inet_frag_queue *inet_frag_create(struct netns_frags *nf,
struct inet_frags *f, void *arg)
{
struct inet_frag_queue *q;
q = inet_frag_alloc(nf, f, arg);
if (q == NULL)
return NULL;
return inet_frag_intern(nf, q, f, arg);
}
struct inet_frag_queue *inet_frag_find(struct netns_frags *nf,
struct inet_frags *f, void *key, unsigned int hash)
__releases(&f->lock
void inet_frag_maybe_warn_overflow(struct inet_frag_queue *q,
const char *prefix)
{
static const char msg[] = "inet_frag_find: Fragment hash bucket"
" list length grew over limit " __stringify(INETFRAGS_MAXDEPTH)
". Dropping fragment.\n";
if (PTR_ERR(q) == -ENOBUFS)
LIMIT_NETDEBUG(KERN_WARNING "%s%s", prefix, msg);
}
