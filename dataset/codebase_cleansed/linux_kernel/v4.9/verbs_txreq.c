void hfi1_put_txreq(struct verbs_txreq *tx)
{
struct hfi1_ibdev *dev;
struct rvt_qp *qp;
unsigned long flags;
unsigned int seq;
struct hfi1_qp_priv *priv;
qp = tx->qp;
dev = to_idev(qp->ibqp.device);
if (tx->mr)
rvt_put_mr(tx->mr);
sdma_txclean(dd_from_dev(dev), &tx->txreq);
kmem_cache_free(dev->verbs_txreq_cache, tx);
do {
seq = read_seqbegin(&dev->iowait_lock);
if (!list_empty(&dev->txwait)) {
struct iowait *wait;
write_seqlock_irqsave(&dev->iowait_lock, flags);
wait = list_first_entry(&dev->txwait, struct iowait,
list);
qp = iowait_to_qp(wait);
priv = qp->priv;
list_del_init(&priv->s_iowait.list);
write_sequnlock_irqrestore(&dev->iowait_lock, flags);
hfi1_qp_wakeup(qp, RVT_S_WAIT_TX);
break;
}
} while (read_seqretry(&dev->iowait_lock, seq));
}
struct verbs_txreq *__get_txreq(struct hfi1_ibdev *dev,
struct rvt_qp *qp)
__must_hold(&qp->s_lock
static void verbs_txreq_kmem_cache_ctor(void *obj)
{
struct verbs_txreq *tx = (struct verbs_txreq *)obj;
memset(tx, 0, sizeof(*tx));
}
int verbs_txreq_init(struct hfi1_ibdev *dev)
{
char buf[TXREQ_LEN];
struct hfi1_devdata *dd = dd_from_dev(dev);
snprintf(buf, sizeof(buf), "hfi1_%u_vtxreq_cache", dd->unit);
dev->verbs_txreq_cache = kmem_cache_create(buf,
sizeof(struct verbs_txreq),
0, SLAB_HWCACHE_ALIGN,
verbs_txreq_kmem_cache_ctor);
if (!dev->verbs_txreq_cache)
return -ENOMEM;
return 0;
}
void verbs_txreq_exit(struct hfi1_ibdev *dev)
{
kmem_cache_destroy(dev->verbs_txreq_cache);
dev->verbs_txreq_cache = NULL;
}
