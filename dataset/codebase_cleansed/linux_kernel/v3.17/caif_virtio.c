static void cfv_release_cb(struct virtqueue *vq_tx)
{
struct cfv_info *cfv = vq_tx->vdev->priv;
++cfv->stats.tx_kicks;
tasklet_schedule(&cfv->tx_release_tasklet);
}
static void free_buf_info(struct cfv_info *cfv, struct buf_info *buf_info)
{
if (!buf_info)
return;
gen_pool_free(cfv->genpool, (unsigned long) buf_info->vaddr,
buf_info->size);
kfree(buf_info);
}
static void cfv_release_used_buf(struct virtqueue *vq_tx)
{
struct cfv_info *cfv = vq_tx->vdev->priv;
unsigned long flags;
BUG_ON(vq_tx != cfv->vq_tx);
for (;;) {
unsigned int len;
struct buf_info *buf_info;
spin_lock_irqsave(&cfv->tx_lock, flags);
buf_info = virtqueue_get_buf(vq_tx, &len);
spin_unlock_irqrestore(&cfv->tx_lock, flags);
if (!buf_info)
break;
free_buf_info(cfv, buf_info);
if (cfv->vq_tx->num_free <= cfv->watermark_tx)
continue;
if (cfv->reserved_mem == 0 && cfv->genpool)
cfv->reserved_mem =
gen_pool_alloc(cfv->genpool,
cfv->reserved_size);
if (cfv->reserved_mem) {
cfv->watermark_tx =
virtqueue_get_vring_size(cfv->vq_tx);
netif_tx_wake_all_queues(cfv->ndev);
virtqueue_disable_cb(cfv->vq_tx);
++cfv->stats.tx_flow_on;
} else {
WARN_ON(cfv->watermark_tx >
virtqueue_get_vring_size(cfv->vq_tx));
cfv->watermark_tx +=
virtqueue_get_vring_size(cfv->vq_tx) / 4;
}
}
}
static struct sk_buff *cfv_alloc_and_copy_skb(int *err,
struct cfv_info *cfv,
u8 *frm, u32 frm_len)
{
struct sk_buff *skb;
u32 cfpkt_len, pad_len;
*err = 0;
if (frm_len > cfv->mru || frm_len <= cfv->rx_hr + cfv->rx_tr) {
netdev_err(cfv->ndev,
"Invalid frmlen:%u mtu:%u hr:%d tr:%d\n",
frm_len, cfv->mru, cfv->rx_hr,
cfv->rx_tr);
*err = -EPROTO;
return NULL;
}
cfpkt_len = frm_len - (cfv->rx_hr + cfv->rx_tr);
pad_len = (unsigned long)(frm + cfv->rx_hr) & (IP_HDR_ALIGN - 1);
skb = netdev_alloc_skb(cfv->ndev, frm_len + pad_len);
if (!skb) {
*err = -ENOMEM;
return NULL;
}
skb_reserve(skb, cfv->rx_hr + pad_len);
memcpy(skb_put(skb, cfpkt_len), frm + cfv->rx_hr, cfpkt_len);
return skb;
}
static int cfv_rx_poll(struct napi_struct *napi, int quota)
{
struct cfv_info *cfv = container_of(napi, struct cfv_info, napi);
int rxcnt = 0;
int err = 0;
void *buf;
struct sk_buff *skb;
struct vringh_kiov *riov = &cfv->ctx.riov;
unsigned int skb_len;
again:
do {
skb = NULL;
if (riov->i == riov->used) {
if (cfv->ctx.head != USHRT_MAX) {
vringh_complete_kern(cfv->vr_rx,
cfv->ctx.head,
0);
cfv->ctx.head = USHRT_MAX;
}
err = vringh_getdesc_kern(
cfv->vr_rx,
riov,
NULL,
&cfv->ctx.head,
GFP_ATOMIC);
if (err <= 0)
goto exit;
}
buf = phys_to_virt((unsigned long) riov->iov[riov->i].iov_base);
skb = cfv_alloc_and_copy_skb(&err, cfv, buf,
riov->iov[riov->i].iov_len);
if (unlikely(err))
goto exit;
skb_len = skb->len;
skb->protocol = htons(ETH_P_CAIF);
skb_reset_mac_header(skb);
skb->dev = cfv->ndev;
err = netif_receive_skb(skb);
if (unlikely(err)) {
++cfv->ndev->stats.rx_dropped;
} else {
++cfv->ndev->stats.rx_packets;
cfv->ndev->stats.rx_bytes += skb_len;
}
++riov->i;
++rxcnt;
} while (rxcnt < quota);
++cfv->stats.rx_napi_resched;
goto out;
exit:
switch (err) {
case 0:
++cfv->stats.rx_napi_complete;
napi_complete(napi);
if (unlikely(!vringh_notify_enable_kern(cfv->vr_rx)) &&
napi_schedule_prep(napi)) {
vringh_notify_disable_kern(cfv->vr_rx);
__napi_schedule(napi);
goto again;
}
break;
case -ENOMEM:
++cfv->stats.rx_nomem;
dev_kfree_skb(skb);
napi_complete(napi);
vringh_notify_enable_kern(cfv->vr_rx);
break;
default:
netdev_warn(cfv->ndev, "Bad ring, disable device\n");
cfv->ndev->stats.rx_dropped = riov->used - riov->i;
napi_complete(napi);
vringh_notify_disable_kern(cfv->vr_rx);
netif_carrier_off(cfv->ndev);
break;
}
out:
if (rxcnt && vringh_need_notify_kern(cfv->vr_rx) > 0)
vringh_notify(cfv->vr_rx);
return rxcnt;
}
static void cfv_recv(struct virtio_device *vdev, struct vringh *vr_rx)
{
struct cfv_info *cfv = vdev->priv;
++cfv->stats.rx_kicks;
vringh_notify_disable_kern(cfv->vr_rx);
napi_schedule(&cfv->napi);
}
static void cfv_destroy_genpool(struct cfv_info *cfv)
{
if (cfv->alloc_addr)
dma_free_coherent(cfv->vdev->dev.parent->parent,
cfv->allocsz, cfv->alloc_addr,
cfv->alloc_dma);
if (!cfv->genpool)
return;
gen_pool_free(cfv->genpool, cfv->reserved_mem,
cfv->reserved_size);
gen_pool_destroy(cfv->genpool);
cfv->genpool = NULL;
}
static int cfv_create_genpool(struct cfv_info *cfv)
{
int err;
err = -ENOMEM;
cfv->allocsz = (virtqueue_get_vring_size(cfv->vq_tx) *
(ETH_DATA_LEN + cfv->tx_hr + cfv->tx_tr) * 11)/10;
if (cfv->allocsz <= (num_possible_cpus() + 1) * cfv->ndev->mtu)
return -EINVAL;
for (;;) {
if (cfv->allocsz <= num_possible_cpus() * cfv->ndev->mtu) {
netdev_info(cfv->ndev, "Not enough device memory\n");
return -ENOMEM;
}
cfv->alloc_addr = dma_alloc_coherent(
cfv->vdev->dev.parent->parent,
cfv->allocsz, &cfv->alloc_dma,
GFP_ATOMIC);
if (cfv->alloc_addr)
break;
cfv->allocsz = (cfv->allocsz * 3) >> 2;
}
netdev_dbg(cfv->ndev, "Allocated %zd bytes from dma-memory\n",
cfv->allocsz);
cfv->genpool = gen_pool_create(7, -1);
if (!cfv->genpool)
goto err;
err = gen_pool_add_virt(cfv->genpool, (unsigned long)cfv->alloc_addr,
(phys_addr_t)virt_to_phys(cfv->alloc_addr),
cfv->allocsz, -1);
if (err)
goto err;
cfv->reserved_size = num_possible_cpus() * cfv->ndev->mtu;
cfv->reserved_mem = gen_pool_alloc(cfv->genpool,
cfv->reserved_size);
if (!cfv->reserved_mem) {
err = -ENOMEM;
goto err;
}
cfv->watermark_tx = virtqueue_get_vring_size(cfv->vq_tx);
return 0;
err:
cfv_destroy_genpool(cfv);
return err;
}
static int cfv_netdev_open(struct net_device *netdev)
{
struct cfv_info *cfv = netdev_priv(netdev);
if (cfv_create_genpool(cfv))
return -ENOMEM;
netif_carrier_on(netdev);
napi_enable(&cfv->napi);
napi_schedule(&cfv->napi);
return 0;
}
static int cfv_netdev_close(struct net_device *netdev)
{
struct cfv_info *cfv = netdev_priv(netdev);
unsigned long flags;
struct buf_info *buf_info;
netif_carrier_off(netdev);
virtqueue_disable_cb(cfv->vq_tx);
vringh_notify_disable_kern(cfv->vr_rx);
napi_disable(&cfv->napi);
cfv_release_used_buf(cfv->vq_tx);
spin_lock_irqsave(&cfv->tx_lock, flags);
while ((buf_info = virtqueue_detach_unused_buf(cfv->vq_tx)))
free_buf_info(cfv, buf_info);
spin_unlock_irqrestore(&cfv->tx_lock, flags);
cfv_destroy_genpool(cfv);
return 0;
}
static struct buf_info *cfv_alloc_and_copy_to_shm(struct cfv_info *cfv,
struct sk_buff *skb,
struct scatterlist *sg)
{
struct caif_payload_info *info = (void *)&skb->cb;
struct buf_info *buf_info = NULL;
u8 pad_len, hdr_ofs;
if (!cfv->genpool)
goto err;
if (unlikely(cfv->tx_hr + skb->len + cfv->tx_tr > cfv->mtu)) {
netdev_warn(cfv->ndev, "Invalid packet len (%d > %d)\n",
cfv->tx_hr + skb->len + cfv->tx_tr, cfv->mtu);
goto err;
}
buf_info = kmalloc(sizeof(struct buf_info), GFP_ATOMIC);
if (unlikely(!buf_info))
goto err;
hdr_ofs = cfv->tx_hr + info->hdr_len;
pad_len = hdr_ofs & (IP_HDR_ALIGN - 1);
buf_info->size = cfv->tx_hr + skb->len + cfv->tx_tr + pad_len;
buf_info->vaddr = (void *)gen_pool_alloc(cfv->genpool, buf_info->size);
if (unlikely(!buf_info->vaddr))
goto err;
skb_copy_bits(skb, 0, buf_info->vaddr + cfv->tx_hr + pad_len, skb->len);
sg_init_one(sg, buf_info->vaddr + pad_len,
skb->len + cfv->tx_hr + cfv->rx_hr);
return buf_info;
err:
kfree(buf_info);
return NULL;
}
static int cfv_netdev_tx(struct sk_buff *skb, struct net_device *netdev)
{
struct cfv_info *cfv = netdev_priv(netdev);
struct buf_info *buf_info;
struct scatterlist sg;
unsigned long flags;
bool flow_off = false;
int ret;
cfv_release_used_buf(cfv->vq_tx);
spin_lock_irqsave(&cfv->tx_lock, flags);
if (unlikely(cfv->vq_tx->num_free <= num_present_cpus())) {
flow_off = true;
cfv->stats.tx_full_ring++;
}
buf_info = cfv_alloc_and_copy_to_shm(cfv, skb, &sg);
if (unlikely(!buf_info)) {
cfv->stats.tx_no_mem++;
flow_off = true;
if (cfv->reserved_mem && cfv->genpool) {
gen_pool_free(cfv->genpool, cfv->reserved_mem,
cfv->reserved_size);
cfv->reserved_mem = 0;
buf_info = cfv_alloc_and_copy_to_shm(cfv, skb, &sg);
}
}
if (unlikely(flow_off)) {
cfv->watermark_tx = virtqueue_get_vring_size(cfv->vq_tx) / 4;
virtqueue_enable_cb(cfv->vq_tx);
netif_tx_stop_all_queues(netdev);
}
if (unlikely(!buf_info)) {
netdev_warn(cfv->ndev, "Out of gen_pool memory\n");
goto err;
}
ret = virtqueue_add_outbuf(cfv->vq_tx, &sg, 1, buf_info, GFP_ATOMIC);
if (unlikely((ret < 0))) {
netdev_warn(cfv->ndev, "Failed adding buffer to TX vring:%d\n",
ret);
goto err;
}
cfv->ndev->stats.tx_packets++;
cfv->ndev->stats.tx_bytes += skb->len;
spin_unlock_irqrestore(&cfv->tx_lock, flags);
virtqueue_kick(cfv->vq_tx);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
err:
spin_unlock_irqrestore(&cfv->tx_lock, flags);
cfv->ndev->stats.tx_dropped++;
free_buf_info(cfv, buf_info);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static void cfv_tx_release_tasklet(unsigned long drv)
{
struct cfv_info *cfv = (struct cfv_info *)drv;
cfv_release_used_buf(cfv->vq_tx);
}
static void cfv_netdev_setup(struct net_device *netdev)
{
netdev->netdev_ops = &cfv_netdev_ops;
netdev->type = ARPHRD_CAIF;
netdev->tx_queue_len = 100;
netdev->flags = IFF_POINTOPOINT | IFF_NOARP;
netdev->mtu = CFV_DEF_MTU_SIZE;
netdev->destructor = free_netdev;
}
static inline void debugfs_init(struct cfv_info *cfv)
{
cfv->debugfs =
debugfs_create_dir(netdev_name(cfv->ndev), NULL);
if (IS_ERR(cfv->debugfs))
return;
debugfs_create_u32("rx-napi-complete", S_IRUSR, cfv->debugfs,
&cfv->stats.rx_napi_complete);
debugfs_create_u32("rx-napi-resched", S_IRUSR, cfv->debugfs,
&cfv->stats.rx_napi_resched);
debugfs_create_u32("rx-nomem", S_IRUSR, cfv->debugfs,
&cfv->stats.rx_nomem);
debugfs_create_u32("rx-kicks", S_IRUSR, cfv->debugfs,
&cfv->stats.rx_kicks);
debugfs_create_u32("tx-full-ring", S_IRUSR, cfv->debugfs,
&cfv->stats.tx_full_ring);
debugfs_create_u32("tx-no-mem", S_IRUSR, cfv->debugfs,
&cfv->stats.tx_no_mem);
debugfs_create_u32("tx-kicks", S_IRUSR, cfv->debugfs,
&cfv->stats.tx_kicks);
debugfs_create_u32("tx-flow-on", S_IRUSR, cfv->debugfs,
&cfv->stats.tx_flow_on);
}
static int cfv_probe(struct virtio_device *vdev)
{
vq_callback_t *vq_cbs = cfv_release_cb;
vrh_callback_t *vrh_cbs = cfv_recv;
const char *names = "output";
const char *cfv_netdev_name = "cfvrt";
struct net_device *netdev;
struct cfv_info *cfv;
int err = -EINVAL;
netdev = alloc_netdev(sizeof(struct cfv_info), cfv_netdev_name,
NET_NAME_UNKNOWN, cfv_netdev_setup);
if (!netdev)
return -ENOMEM;
cfv = netdev_priv(netdev);
cfv->vdev = vdev;
cfv->ndev = netdev;
spin_lock_init(&cfv->tx_lock);
err = -ENODEV;
if (!vdev->vringh_config || !vdev->vringh_config->find_vrhs)
goto err;
err = vdev->vringh_config->find_vrhs(vdev, 1, &cfv->vr_rx, &vrh_cbs);
if (err)
goto err;
err = vdev->config->find_vqs(vdev, 1, &cfv->vq_tx, &vq_cbs, &names);
if (err)
goto err;
if (vdev->config->get) {
virtio_cread(vdev, struct virtio_caif_transf_config, headroom,
&cfv->tx_hr);
virtio_cread(vdev, struct virtio_caif_transf_config, headroom,
&cfv->rx_hr);
virtio_cread(vdev, struct virtio_caif_transf_config, tailroom,
&cfv->tx_tr);
virtio_cread(vdev, struct virtio_caif_transf_config, tailroom,
&cfv->rx_tr);
virtio_cread(vdev, struct virtio_caif_transf_config, mtu,
&cfv->mtu);
virtio_cread(vdev, struct virtio_caif_transf_config, mtu,
&cfv->mru);
} else {
cfv->tx_hr = CFV_DEF_HEADROOM;
cfv->rx_hr = CFV_DEF_HEADROOM;
cfv->tx_tr = CFV_DEF_TAILROOM;
cfv->rx_tr = CFV_DEF_TAILROOM;
cfv->mtu = CFV_DEF_MTU_SIZE;
cfv->mru = CFV_DEF_MTU_SIZE;
}
netdev->needed_headroom = cfv->tx_hr;
netdev->needed_tailroom = cfv->tx_tr;
virtqueue_disable_cb(cfv->vq_tx);
netdev->mtu = cfv->mtu - cfv->tx_tr;
vdev->priv = cfv;
vringh_kiov_init(&cfv->ctx.riov, NULL, 0);
cfv->ctx.head = USHRT_MAX;
netif_napi_add(netdev, &cfv->napi, cfv_rx_poll, CFV_DEFAULT_QUOTA);
tasklet_init(&cfv->tx_release_tasklet,
cfv_tx_release_tasklet,
(unsigned long)cfv);
netif_carrier_off(netdev);
err = register_netdev(netdev);
if (err) {
dev_err(&vdev->dev, "Unable to register netdev (%d)\n", err);
goto err;
}
debugfs_init(cfv);
return 0;
err:
netdev_warn(cfv->ndev, "CAIF Virtio probe failed:%d\n", err);
if (cfv->vr_rx)
vdev->vringh_config->del_vrhs(cfv->vdev);
if (cfv->vdev)
vdev->config->del_vqs(cfv->vdev);
free_netdev(netdev);
return err;
}
static void cfv_remove(struct virtio_device *vdev)
{
struct cfv_info *cfv = vdev->priv;
rtnl_lock();
dev_close(cfv->ndev);
rtnl_unlock();
tasklet_kill(&cfv->tx_release_tasklet);
debugfs_remove_recursive(cfv->debugfs);
vringh_kiov_cleanup(&cfv->ctx.riov);
vdev->config->reset(vdev);
vdev->vringh_config->del_vrhs(cfv->vdev);
cfv->vr_rx = NULL;
vdev->config->del_vqs(cfv->vdev);
unregister_netdev(cfv->ndev);
}
