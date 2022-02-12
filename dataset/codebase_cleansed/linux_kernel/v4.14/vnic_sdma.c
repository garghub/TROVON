static void vnic_sdma_complete(struct sdma_txreq *txreq,
int status)
{
struct vnic_txreq *tx = container_of(txreq, struct vnic_txreq, txreq);
struct hfi1_vnic_sdma *vnic_sdma = tx->sdma;
sdma_txclean(vnic_sdma->dd, txreq);
dev_kfree_skb_any(tx->skb);
kmem_cache_free(vnic_sdma->dd->vnic.txreq_cache, tx);
}
static noinline int build_vnic_ulp_payload(struct sdma_engine *sde,
struct vnic_txreq *tx)
{
int i, ret = 0;
ret = sdma_txadd_kvaddr(
sde->dd,
&tx->txreq,
tx->skb->data,
skb_headlen(tx->skb));
if (unlikely(ret))
goto bail_txadd;
for (i = 0; i < skb_shinfo(tx->skb)->nr_frags; i++) {
struct skb_frag_struct *frag = &skb_shinfo(tx->skb)->frags[i];
ret = sdma_txadd_page(sde->dd,
&tx->txreq,
skb_frag_page(frag),
frag->page_offset,
skb_frag_size(frag));
if (unlikely(ret))
goto bail_txadd;
}
if (tx->plen)
ret = sdma_txadd_kvaddr(sde->dd, &tx->txreq,
tx->pad + HFI1_VNIC_MAX_PAD - tx->plen,
tx->plen);
bail_txadd:
return ret;
}
static int build_vnic_tx_desc(struct sdma_engine *sde,
struct vnic_txreq *tx,
u64 pbc)
{
int ret = 0;
u16 hdrbytes = 2 << 2;
ret = sdma_txinit_ahg(
&tx->txreq,
0,
hdrbytes + tx->skb->len + tx->plen,
0,
0,
NULL,
0,
vnic_sdma_complete);
if (unlikely(ret))
goto bail_txadd;
tx->pbc_val = cpu_to_le64(pbc);
ret = sdma_txadd_kvaddr(
sde->dd,
&tx->txreq,
&tx->pbc_val,
hdrbytes);
if (unlikely(ret))
goto bail_txadd;
ret = build_vnic_ulp_payload(sde, tx);
bail_txadd:
return ret;
}
static inline void hfi1_vnic_update_pad(unsigned char *pad, u8 plen)
{
pad[HFI1_VNIC_MAX_PAD - 1] = plen - OPA_VNIC_ICRC_TAIL_LEN;
}
int hfi1_vnic_send_dma(struct hfi1_devdata *dd, u8 q_idx,
struct hfi1_vnic_vport_info *vinfo,
struct sk_buff *skb, u64 pbc, u8 plen)
{
struct hfi1_vnic_sdma *vnic_sdma = &vinfo->sdma[q_idx];
struct sdma_engine *sde = vnic_sdma->sde;
struct vnic_txreq *tx;
int ret = -ECOMM;
if (unlikely(READ_ONCE(vnic_sdma->state) != HFI1_VNIC_SDMA_Q_ACTIVE))
goto tx_err;
if (unlikely(!sde || !sdma_running(sde)))
goto tx_err;
tx = kmem_cache_alloc(dd->vnic.txreq_cache, GFP_ATOMIC);
if (unlikely(!tx)) {
ret = -ENOMEM;
goto tx_err;
}
tx->sdma = vnic_sdma;
tx->skb = skb;
hfi1_vnic_update_pad(tx->pad, plen);
tx->plen = plen;
ret = build_vnic_tx_desc(sde, tx, pbc);
if (unlikely(ret))
goto free_desc;
tx->retry_count = 0;
ret = sdma_send_txreq(sde, &vnic_sdma->wait, &tx->txreq,
vnic_sdma->pkts_sent);
if (unlikely(ret && unlikely(ret != -ECOMM)))
goto free_desc;
if (!ret) {
vnic_sdma->pkts_sent = true;
iowait_starve_clear(vnic_sdma->pkts_sent, &vnic_sdma->wait);
}
return ret;
free_desc:
sdma_txclean(dd, &tx->txreq);
kmem_cache_free(dd->vnic.txreq_cache, tx);
tx_err:
if (ret != -EBUSY)
dev_kfree_skb_any(skb);
else
vnic_sdma->pkts_sent = false;
return ret;
}
static int hfi1_vnic_sdma_sleep(struct sdma_engine *sde,
struct iowait *wait,
struct sdma_txreq *txreq,
uint seq,
bool pkts_sent)
{
struct hfi1_vnic_sdma *vnic_sdma =
container_of(wait, struct hfi1_vnic_sdma, wait);
struct hfi1_ibdev *dev = &vnic_sdma->dd->verbs_dev;
struct vnic_txreq *tx = container_of(txreq, struct vnic_txreq, txreq);
if (sdma_progress(sde, seq, txreq))
if (tx->retry_count++ < HFI1_VNIC_SDMA_RETRY_COUNT)
return -EAGAIN;
vnic_sdma->state = HFI1_VNIC_SDMA_Q_DEFERRED;
write_seqlock(&dev->iowait_lock);
if (list_empty(&vnic_sdma->wait.list))
iowait_queue(pkts_sent, wait, &sde->dmawait);
write_sequnlock(&dev->iowait_lock);
return -EBUSY;
}
static void hfi1_vnic_sdma_wakeup(struct iowait *wait, int reason)
{
struct hfi1_vnic_sdma *vnic_sdma =
container_of(wait, struct hfi1_vnic_sdma, wait);
struct hfi1_vnic_vport_info *vinfo = vnic_sdma->vinfo;
vnic_sdma->state = HFI1_VNIC_SDMA_Q_ACTIVE;
if (__netif_subqueue_stopped(vinfo->netdev, vnic_sdma->q_idx))
netif_wake_subqueue(vinfo->netdev, vnic_sdma->q_idx);
}
inline bool hfi1_vnic_sdma_write_avail(struct hfi1_vnic_vport_info *vinfo,
u8 q_idx)
{
struct hfi1_vnic_sdma *vnic_sdma = &vinfo->sdma[q_idx];
return (READ_ONCE(vnic_sdma->state) == HFI1_VNIC_SDMA_Q_ACTIVE);
}
void hfi1_vnic_sdma_init(struct hfi1_vnic_vport_info *vinfo)
{
int i;
for (i = 0; i < vinfo->num_tx_q; i++) {
struct hfi1_vnic_sdma *vnic_sdma = &vinfo->sdma[i];
iowait_init(&vnic_sdma->wait, 0, NULL, hfi1_vnic_sdma_sleep,
hfi1_vnic_sdma_wakeup, NULL);
vnic_sdma->sde = &vinfo->dd->per_sdma[i];
vnic_sdma->dd = vinfo->dd;
vnic_sdma->vinfo = vinfo;
vnic_sdma->q_idx = i;
vnic_sdma->state = HFI1_VNIC_SDMA_Q_ACTIVE;
if (vnic_sdma->sde->descq_cnt > HFI1_VNIC_SDMA_DESC_WTRMRK) {
INIT_LIST_HEAD(&vnic_sdma->stx.list);
vnic_sdma->stx.num_desc = HFI1_VNIC_SDMA_DESC_WTRMRK;
list_add_tail(&vnic_sdma->stx.list,
&vnic_sdma->wait.tx_head);
}
}
}
int hfi1_vnic_txreq_init(struct hfi1_devdata *dd)
{
char buf[HFI1_VNIC_TXREQ_NAME_LEN];
snprintf(buf, sizeof(buf), "hfi1_%u_vnic_txreq_cache", dd->unit);
dd->vnic.txreq_cache = kmem_cache_create(buf,
sizeof(struct vnic_txreq),
0, SLAB_HWCACHE_ALIGN,
NULL);
if (!dd->vnic.txreq_cache)
return -ENOMEM;
return 0;
}
void hfi1_vnic_txreq_deinit(struct hfi1_devdata *dd)
{
kmem_cache_destroy(dd->vnic.txreq_cache);
dd->vnic.txreq_cache = NULL;
}
