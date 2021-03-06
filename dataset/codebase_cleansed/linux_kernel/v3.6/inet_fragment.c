static void inet_frag_secret_rebuild(unsigned long dummy)
{
struct inet_frags *f = (struct inet_frags *)dummy;
unsigned long now = jiffies;
int i;
write_lock(&f->lock);
get_random_bytes(&f->rnd, sizeof(u32));
for (i = 0; i < INETFRAGS_HASHSZ; i++) {
struct inet_frag_queue *q;
struct hlist_node *p, *n;
hlist_for_each_entry_safe(q, p, n, &f->hash[i], list) {
unsigned int hval = f->hashfn(q);
if (hval != i) {
hlist_del(&q->list);
hlist_add_head(&q->list, &f->hash[hval]);
}
}
}
write_unlock(&f->lock);
mod_timer(&f->secret_timer, now + f->secret_interval);
}
void inet_frags_init(struct inet_frags *f)
{
int i;
for (i = 0; i < INETFRAGS_HASHSZ; i++)
INIT_HLIST_HEAD(&f->hash[i]);
rwlock_init(&f->lock);
f->rnd = (u32) ((num_physpages ^ (num_physpages>>7)) ^
(jiffies ^ (jiffies >> 6)));
setup_timer(&f->secret_timer, inet_frag_secret_rebuild,
(unsigned long)f);
f->secret_timer.expires = jiffies + f->secret_interval;
add_timer(&f->secret_timer);
}
void inet_frags_init_net(struct netns_frags *nf)
{
nf->nqueues = 0;
atomic_set(&nf->mem, 0);
INIT_LIST_HEAD(&nf->lru_list);
}
void inet_frags_fini(struct inet_frags *f)
{
del_timer(&f->secret_timer);
}
void inet_frags_exit_net(struct netns_frags *nf, struct inet_frags *f)
{
nf->low_thresh = 0;
local_bh_disable();
inet_frag_evictor(nf, f);
local_bh_enable();
}
static inline void fq_unlink(struct inet_frag_queue *fq, struct inet_frags *f)
{
write_lock(&f->lock);
hlist_del(&fq->list);
list_del(&fq->lru_list);
fq->net->nqueues--;
write_unlock(&f->lock);
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
struct sk_buff *skb, int *work)
{
if (work)
*work -= skb->truesize;
atomic_sub(skb->truesize, &nf->mem);
if (f->skb_free)
f->skb_free(skb);
kfree_skb(skb);
}
void inet_frag_destroy(struct inet_frag_queue *q, struct inet_frags *f,
int *work)
{
struct sk_buff *fp;
struct netns_frags *nf;
WARN_ON(!(q->last_in & INET_FRAG_COMPLETE));
WARN_ON(del_timer(&q->timer) != 0);
fp = q->fragments;
nf = q->net;
while (fp) {
struct sk_buff *xp = fp->next;
frag_kfree_skb(nf, f, fp, work);
fp = xp;
}
if (work)
*work -= f->qsize;
atomic_sub(f->qsize, &nf->mem);
if (f->destructor)
f->destructor(q);
kfree(q);
}
int inet_frag_evictor(struct netns_frags *nf, struct inet_frags *f)
{
struct inet_frag_queue *q;
int work, evicted = 0;
work = atomic_read(&nf->mem) - nf->low_thresh;
while (work > 0) {
read_lock(&f->lock);
if (list_empty(&nf->lru_list)) {
read_unlock(&f->lock);
break;
}
q = list_first_entry(&nf->lru_list,
struct inet_frag_queue, lru_list);
atomic_inc(&q->refcnt);
read_unlock(&f->lock);
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
struct inet_frag_queue *qp;
#ifdef CONFIG_SMP
struct hlist_node *n;
#endif
unsigned int hash;
write_lock(&f->lock);
hash = f->hashfn(qp_in);
#ifdef CONFIG_SMP
hlist_for_each_entry(qp, n, &f->hash[hash], list) {
if (qp->net == nf && f->match(qp, arg)) {
atomic_inc(&qp->refcnt);
write_unlock(&f->lock);
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
hlist_add_head(&qp->list, &f->hash[hash]);
list_add_tail(&qp->lru_list, &nf->lru_list);
nf->nqueues++;
write_unlock(&f->lock);
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
atomic_add(f->qsize, &nf->mem);
setup_timer(&q->timer, f->frag_expire, (unsigned long)q);
spin_lock_init(&q->lock);
atomic_set(&q->refcnt, 1);
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
