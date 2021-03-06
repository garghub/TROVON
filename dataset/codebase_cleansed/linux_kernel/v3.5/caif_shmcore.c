static int shm_netdev_open(struct net_device *shm_netdev)
{
netif_wake_queue(shm_netdev);
return 0;
}
static int shm_netdev_close(struct net_device *shm_netdev)
{
netif_stop_queue(shm_netdev);
return 0;
}
int caif_shmdrv_rx_cb(u32 mbx_msg, void *priv)
{
struct buf_list *pbuf;
struct shmdrv_layer *pshm_drv;
struct list_head *pos;
u32 avail_emptybuff = 0;
unsigned long flags = 0;
pshm_drv = priv;
if (mbx_msg & SHM_FULL_MASK) {
int idx;
spin_lock_irqsave(&pshm_drv->lock, flags);
if (list_empty(&pshm_drv->rx_empty_list)) {
spin_unlock_irqrestore(&pshm_drv->lock, flags);
pr_warn("No empty Rx buffers to fill: "
"mbx_msg:%x\n", mbx_msg);
goto err_sync;
}
pbuf =
list_entry(pshm_drv->rx_empty_list.next,
struct buf_list, list);
idx = pbuf->index;
if (idx != SHM_GET_FULL(mbx_msg)) {
pr_warn(
"phyif_shm_mbx_msg_cb: RX full out of sync:"
" idx:%d, msg:%x SHM_GET_FULL(mbx_msg):%x\n",
idx, mbx_msg, SHM_GET_FULL(mbx_msg));
spin_unlock_irqrestore(&pshm_drv->lock, flags);
goto err_sync;
}
list_del_init(&pbuf->list);
list_add_tail(&pbuf->list, &pshm_drv->rx_full_list);
spin_unlock_irqrestore(&pshm_drv->lock, flags);
if (!work_pending(&pshm_drv->shm_rx_work))
queue_work(pshm_drv->pshm_rx_workqueue,
&pshm_drv->shm_rx_work);
}
if (mbx_msg & SHM_EMPTY_MASK) {
int idx;
spin_lock_irqsave(&pshm_drv->lock, flags);
if (list_empty(&pshm_drv->tx_full_list)) {
pr_warn("No TX to empty: msg:%x\n", mbx_msg);
spin_unlock_irqrestore(&pshm_drv->lock, flags);
goto err_sync;
}
pbuf =
list_entry(pshm_drv->tx_full_list.next,
struct buf_list, list);
idx = pbuf->index;
if (idx != SHM_GET_EMPTY(mbx_msg)) {
spin_unlock_irqrestore(&pshm_drv->lock, flags);
pr_warn("TX empty "
"out of sync:idx:%d, msg:%x\n", idx, mbx_msg);
goto err_sync;
}
list_del_init(&pbuf->list);
pbuf->frames = 0;
pbuf->frm_ofs = SHM_CAIF_FRM_OFS;
list_add_tail(&pbuf->list, &pshm_drv->tx_empty_list);
list_for_each(pos, &pshm_drv->tx_empty_list)
avail_emptybuff++;
if ((avail_emptybuff > HIGH_WATERMARK) &&
(!pshm_drv->tx_empty_available)) {
pshm_drv->tx_empty_available = 1;
spin_unlock_irqrestore(&pshm_drv->lock, flags);
pshm_drv->cfdev.flowctrl
(pshm_drv->pshm_dev->pshm_netdev,
CAIF_FLOW_ON);
if (!work_pending(&pshm_drv->shm_tx_work))
queue_work(pshm_drv->pshm_tx_workqueue,
&pshm_drv->shm_tx_work);
} else
spin_unlock_irqrestore(&pshm_drv->lock, flags);
}
return 0;
err_sync:
return -EIO;
}
static void shm_rx_work_func(struct work_struct *rx_work)
{
struct shmdrv_layer *pshm_drv;
struct buf_list *pbuf;
unsigned long flags = 0;
struct sk_buff *skb;
char *p;
int ret;
pshm_drv = container_of(rx_work, struct shmdrv_layer, shm_rx_work);
while (1) {
struct shm_pck_desc *pck_desc;
spin_lock_irqsave(&pshm_drv->lock, flags);
if (list_empty(&pshm_drv->rx_full_list)) {
spin_unlock_irqrestore(&pshm_drv->lock, flags);
break;
}
pbuf =
list_entry(pshm_drv->rx_full_list.next, struct buf_list,
list);
list_del_init(&pbuf->list);
spin_unlock_irqrestore(&pshm_drv->lock, flags);
pck_desc = (struct shm_pck_desc *) pbuf->desc_vptr;
while (pck_desc->frm_ofs) {
unsigned int frm_buf_ofs;
unsigned int frm_pck_ofs;
unsigned int frm_pck_len;
if (pck_desc->frm_ofs <
(pbuf->phy_addr - pshm_drv->shm_base_addr))
break;
if (pck_desc->frm_ofs >
((pbuf->phy_addr - pshm_drv->shm_base_addr) +
pbuf->len))
break;
frm_buf_ofs =
pck_desc->frm_ofs - (pbuf->phy_addr -
pshm_drv->shm_base_addr);
frm_pck_ofs =
frm_buf_ofs + SHM_HDR_LEN +
(*(pbuf->desc_vptr + frm_buf_ofs));
frm_pck_len =
(pck_desc->frm_len - SHM_HDR_LEN -
(*(pbuf->desc_vptr + frm_buf_ofs)));
if ((frm_pck_ofs + pck_desc->frm_len) > pbuf->len)
break;
skb = netdev_alloc_skb(pshm_drv->pshm_dev->pshm_netdev,
frm_pck_len + 1);
if (skb == NULL) {
pr_info("OOM: Try next frame in descriptor\n");
break;
}
p = skb_put(skb, frm_pck_len);
memcpy(p, pbuf->desc_vptr + frm_pck_ofs, frm_pck_len);
skb->protocol = htons(ETH_P_CAIF);
skb_reset_mac_header(skb);
skb->dev = pshm_drv->pshm_dev->pshm_netdev;
ret = netif_rx_ni(skb);
if (!ret) {
pshm_drv->pshm_dev->pshm_netdev->stats.
rx_packets++;
pshm_drv->pshm_dev->pshm_netdev->stats.
rx_bytes += pck_desc->frm_len;
} else
++pshm_drv->pshm_dev->pshm_netdev->stats.
rx_dropped;
pck_desc++;
}
spin_lock_irqsave(&pshm_drv->lock, flags);
list_add_tail(&pbuf->list, &pshm_drv->rx_pend_list);
spin_unlock_irqrestore(&pshm_drv->lock, flags);
}
if (!work_pending(&pshm_drv->shm_tx_work))
queue_work(pshm_drv->pshm_tx_workqueue, &pshm_drv->shm_tx_work);
}
static void shm_tx_work_func(struct work_struct *tx_work)
{
u32 mbox_msg;
unsigned int frmlen, avail_emptybuff, append = 0;
unsigned long flags = 0;
struct buf_list *pbuf = NULL;
struct shmdrv_layer *pshm_drv;
struct shm_caif_frm *frm;
struct sk_buff *skb;
struct shm_pck_desc *pck_desc;
struct list_head *pos;
pshm_drv = container_of(tx_work, struct shmdrv_layer, shm_tx_work);
do {
mbox_msg = 0x00;
avail_emptybuff = 0;
spin_lock_irqsave(&pshm_drv->lock, flags);
if (!list_empty(&pshm_drv->rx_pend_list)) {
pbuf = list_entry(pshm_drv->rx_pend_list.next,
struct buf_list, list);
list_del_init(&pbuf->list);
list_add_tail(&pbuf->list, &pshm_drv->rx_empty_list);
mbox_msg |= SHM_SET_EMPTY(pbuf->index);
}
skb = skb_peek(&pshm_drv->sk_qhead);
if (skb == NULL)
goto send_msg;
list_for_each(pos, &pshm_drv->tx_empty_list)
avail_emptybuff++;
if ((avail_emptybuff < LOW_WATERMARK) &&
pshm_drv->tx_empty_available) {
pshm_drv->tx_empty_available = 0;
spin_unlock_irqrestore(&pshm_drv->lock, flags);
pshm_drv->cfdev.flowctrl
(pshm_drv->pshm_dev->pshm_netdev,
CAIF_FLOW_OFF);
spin_lock_irqsave(&pshm_drv->lock, flags);
}
if (list_empty(&pshm_drv->tx_empty_list))
goto send_msg;
pbuf = list_entry(pshm_drv->tx_empty_list.next,
struct buf_list, list);
do {
if (append) {
skb = skb_peek(&pshm_drv->sk_qhead);
if (skb == NULL)
break;
}
frm = (struct shm_caif_frm *)
(pbuf->desc_vptr + pbuf->frm_ofs);
frm->hdr_ofs = 0;
frmlen = 0;
frmlen += SHM_HDR_LEN + frm->hdr_ofs + skb->len;
if (frmlen % SHM_FRM_PAD_LEN)
frmlen += SHM_FRM_PAD_LEN -
(frmlen % SHM_FRM_PAD_LEN);
if (frmlen >= (pbuf->len - pbuf->frm_ofs))
break;
if (!append) {
list_del_init(&pbuf->list);
append = 1;
}
skb = skb_dequeue(&pshm_drv->sk_qhead);
if (skb == NULL)
break;
skb_copy_bits(skb, 0, pbuf->desc_vptr +
pbuf->frm_ofs + SHM_HDR_LEN +
frm->hdr_ofs, skb->len);
pshm_drv->pshm_dev->pshm_netdev->stats.tx_packets++;
pshm_drv->pshm_dev->pshm_netdev->stats.tx_bytes +=
frmlen;
dev_kfree_skb_irq(skb);
pck_desc = (struct shm_pck_desc *) (pbuf->desc_vptr);
pck_desc += pbuf->frames;
pck_desc->frm_ofs = (pbuf->phy_addr -
pshm_drv->shm_base_addr) +
pbuf->frm_ofs;
pck_desc->frm_len = frmlen;
pck_desc++;
pck_desc->frm_ofs = 0;
pbuf->frames++;
pbuf->frm_ofs += frmlen + (frmlen % 32);
} while (pbuf->frames < SHM_MAX_FRMS_PER_BUF);
list_add_tail(&pbuf->list, &pshm_drv->tx_full_list);
append = 0;
mbox_msg |= SHM_SET_FULL(pbuf->index);
send_msg:
spin_unlock_irqrestore(&pshm_drv->lock, flags);
if (mbox_msg)
pshm_drv->pshm_dev->pshmdev_mbxsend
(pshm_drv->pshm_dev->shm_id, mbox_msg);
} while (mbox_msg);
}
static int shm_netdev_tx(struct sk_buff *skb, struct net_device *shm_netdev)
{
struct shmdrv_layer *pshm_drv;
pshm_drv = netdev_priv(shm_netdev);
skb_queue_tail(&pshm_drv->sk_qhead, skb);
if (!work_pending(&pshm_drv->shm_tx_work))
queue_work(pshm_drv->pshm_tx_workqueue, &pshm_drv->shm_tx_work);
return 0;
}
static void shm_netdev_setup(struct net_device *pshm_netdev)
{
struct shmdrv_layer *pshm_drv;
pshm_netdev->netdev_ops = &netdev_ops;
pshm_netdev->mtu = CAIF_MAX_MTU;
pshm_netdev->type = ARPHRD_CAIF;
pshm_netdev->hard_header_len = CAIF_NEEDED_HEADROOM;
pshm_netdev->tx_queue_len = 0;
pshm_netdev->destructor = free_netdev;
pshm_drv = netdev_priv(pshm_netdev);
memset(pshm_drv, 0, sizeof(struct shmdrv_layer));
pshm_drv->cfdev.link_select = CAIF_LINK_LOW_LATENCY;
}
int caif_shmcore_probe(struct shmdev_layer *pshm_dev)
{
int result, j;
struct shmdrv_layer *pshm_drv = NULL;
pshm_dev->pshm_netdev = alloc_netdev(sizeof(struct shmdrv_layer),
"cfshm%d", shm_netdev_setup);
if (!pshm_dev->pshm_netdev)
return -ENOMEM;
pshm_drv = netdev_priv(pshm_dev->pshm_netdev);
pshm_drv->pshm_dev = pshm_dev;
if ((pshm_dev->pshmdev_mbxsetup
(caif_shmdrv_rx_cb, pshm_dev, pshm_drv)) != 0) {
pr_warn("Could not config. SHM Mailbox,"
" Bailing out.....\n");
free_netdev(pshm_dev->pshm_netdev);
return -ENODEV;
}
skb_queue_head_init(&pshm_drv->sk_qhead);
pr_info("SHM DEVICE[%d] PROBED BY DRIVER, NEW SHM DRIVER"
" INSTANCE AT pshm_drv =0x%p\n",
pshm_drv->pshm_dev->shm_id, pshm_drv);
if (pshm_dev->shm_total_sz <
(NR_TX_BUF * TX_BUF_SZ + NR_RX_BUF * RX_BUF_SZ)) {
pr_warn("ERROR, Amount of available"
" Phys. SHM cannot accommodate current SHM "
"driver configuration, Bailing out ...\n");
free_netdev(pshm_dev->pshm_netdev);
return -ENOMEM;
}
pshm_drv->shm_base_addr = pshm_dev->shm_base_addr;
pshm_drv->shm_tx_addr = pshm_drv->shm_base_addr;
if (pshm_dev->shm_loopback)
pshm_drv->shm_rx_addr = pshm_drv->shm_tx_addr;
else
pshm_drv->shm_rx_addr = pshm_dev->shm_base_addr +
(NR_TX_BUF * TX_BUF_SZ);
spin_lock_init(&pshm_drv->lock);
INIT_LIST_HEAD(&pshm_drv->tx_empty_list);
INIT_LIST_HEAD(&pshm_drv->tx_pend_list);
INIT_LIST_HEAD(&pshm_drv->tx_full_list);
INIT_LIST_HEAD(&pshm_drv->rx_empty_list);
INIT_LIST_HEAD(&pshm_drv->rx_pend_list);
INIT_LIST_HEAD(&pshm_drv->rx_full_list);
INIT_WORK(&pshm_drv->shm_tx_work, shm_tx_work_func);
INIT_WORK(&pshm_drv->shm_rx_work, shm_rx_work_func);
pshm_drv->pshm_tx_workqueue =
create_singlethread_workqueue("shm_tx_work");
pshm_drv->pshm_rx_workqueue =
create_singlethread_workqueue("shm_rx_work");
for (j = 0; j < NR_TX_BUF; j++) {
struct buf_list *tx_buf =
kmalloc(sizeof(struct buf_list), GFP_KERNEL);
if (tx_buf == NULL) {
pr_warn("ERROR, Could not"
" allocate dynamic mem. for tx_buf,"
" Bailing out ...\n");
free_netdev(pshm_dev->pshm_netdev);
return -ENOMEM;
}
tx_buf->index = j;
tx_buf->phy_addr = pshm_drv->shm_tx_addr + (TX_BUF_SZ * j);
tx_buf->len = TX_BUF_SZ;
tx_buf->frames = 0;
tx_buf->frm_ofs = SHM_CAIF_FRM_OFS;
if (pshm_dev->shm_loopback)
tx_buf->desc_vptr = (unsigned char *)tx_buf->phy_addr;
else
tx_buf->desc_vptr =
ioremap(tx_buf->phy_addr, TX_BUF_SZ);
list_add_tail(&tx_buf->list, &pshm_drv->tx_empty_list);
}
for (j = 0; j < NR_RX_BUF; j++) {
struct buf_list *rx_buf =
kmalloc(sizeof(struct buf_list), GFP_KERNEL);
if (rx_buf == NULL) {
pr_warn("ERROR, Could not"
" allocate dynamic mem.for rx_buf,"
" Bailing out ...\n");
free_netdev(pshm_dev->pshm_netdev);
return -ENOMEM;
}
rx_buf->index = j;
rx_buf->phy_addr = pshm_drv->shm_rx_addr + (RX_BUF_SZ * j);
rx_buf->len = RX_BUF_SZ;
if (pshm_dev->shm_loopback)
rx_buf->desc_vptr = (unsigned char *)rx_buf->phy_addr;
else
rx_buf->desc_vptr =
ioremap(rx_buf->phy_addr, RX_BUF_SZ);
list_add_tail(&rx_buf->list, &pshm_drv->rx_empty_list);
}
pshm_drv->tx_empty_available = 1;
result = register_netdev(pshm_dev->pshm_netdev);
if (result)
pr_warn("ERROR[%d], SHM could not, "
"register with NW FRMWK Bailing out ...\n", result);
return result;
}
void caif_shmcore_remove(struct net_device *pshm_netdev)
{
struct buf_list *pbuf;
struct shmdrv_layer *pshm_drv = NULL;
pshm_drv = netdev_priv(pshm_netdev);
while (!(list_empty(&pshm_drv->tx_pend_list))) {
pbuf =
list_entry(pshm_drv->tx_pend_list.next,
struct buf_list, list);
list_del(&pbuf->list);
kfree(pbuf);
}
while (!(list_empty(&pshm_drv->tx_full_list))) {
pbuf =
list_entry(pshm_drv->tx_full_list.next,
struct buf_list, list);
list_del(&pbuf->list);
kfree(pbuf);
}
while (!(list_empty(&pshm_drv->tx_empty_list))) {
pbuf =
list_entry(pshm_drv->tx_empty_list.next,
struct buf_list, list);
list_del(&pbuf->list);
kfree(pbuf);
}
while (!(list_empty(&pshm_drv->rx_full_list))) {
pbuf =
list_entry(pshm_drv->tx_full_list.next,
struct buf_list, list);
list_del(&pbuf->list);
kfree(pbuf);
}
while (!(list_empty(&pshm_drv->rx_pend_list))) {
pbuf =
list_entry(pshm_drv->tx_pend_list.next,
struct buf_list, list);
list_del(&pbuf->list);
kfree(pbuf);
}
while (!(list_empty(&pshm_drv->rx_empty_list))) {
pbuf =
list_entry(pshm_drv->rx_empty_list.next,
struct buf_list, list);
list_del(&pbuf->list);
kfree(pbuf);
}
destroy_workqueue(pshm_drv->pshm_tx_workqueue);
destroy_workqueue(pshm_drv->pshm_rx_workqueue);
unregister_netdev(pshm_netdev);
}
