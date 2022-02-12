void hinic_rxq_clean_stats(struct hinic_rxq *rxq)
{
struct hinic_rxq_stats *rxq_stats = &rxq->rxq_stats;
u64_stats_update_begin(&rxq_stats->syncp);
rxq_stats->pkts = 0;
rxq_stats->bytes = 0;
u64_stats_update_end(&rxq_stats->syncp);
}
void hinic_rxq_get_stats(struct hinic_rxq *rxq, struct hinic_rxq_stats *stats)
{
struct hinic_rxq_stats *rxq_stats = &rxq->rxq_stats;
unsigned int start;
u64_stats_update_begin(&stats->syncp);
do {
start = u64_stats_fetch_begin(&rxq_stats->syncp);
stats->pkts = rxq_stats->pkts;
stats->bytes = rxq_stats->bytes;
} while (u64_stats_fetch_retry(&rxq_stats->syncp, start));
u64_stats_update_end(&stats->syncp);
}
static void rxq_stats_init(struct hinic_rxq *rxq)
{
struct hinic_rxq_stats *rxq_stats = &rxq->rxq_stats;
u64_stats_init(&rxq_stats->syncp);
hinic_rxq_clean_stats(rxq);
}
static struct sk_buff *rx_alloc_skb(struct hinic_rxq *rxq,
dma_addr_t *dma_addr)
{
struct hinic_dev *nic_dev = netdev_priv(rxq->netdev);
struct hinic_hwdev *hwdev = nic_dev->hwdev;
struct hinic_hwif *hwif = hwdev->hwif;
struct pci_dev *pdev = hwif->pdev;
struct sk_buff *skb;
dma_addr_t addr;
int err;
skb = netdev_alloc_skb_ip_align(rxq->netdev, rxq->rq->buf_sz);
if (!skb) {
netdev_err(rxq->netdev, "Failed to allocate Rx SKB\n");
return NULL;
}
addr = dma_map_single(&pdev->dev, skb->data, rxq->rq->buf_sz,
DMA_FROM_DEVICE);
err = dma_mapping_error(&pdev->dev, addr);
if (err) {
dev_err(&pdev->dev, "Failed to map Rx DMA, err = %d\n", err);
goto err_rx_map;
}
*dma_addr = addr;
return skb;
err_rx_map:
dev_kfree_skb_any(skb);
return NULL;
}
static void rx_unmap_skb(struct hinic_rxq *rxq, dma_addr_t dma_addr)
{
struct hinic_dev *nic_dev = netdev_priv(rxq->netdev);
struct hinic_hwdev *hwdev = nic_dev->hwdev;
struct hinic_hwif *hwif = hwdev->hwif;
struct pci_dev *pdev = hwif->pdev;
dma_unmap_single(&pdev->dev, dma_addr, rxq->rq->buf_sz,
DMA_FROM_DEVICE);
}
static void rx_free_skb(struct hinic_rxq *rxq, struct sk_buff *skb,
dma_addr_t dma_addr)
{
rx_unmap_skb(rxq, dma_addr);
dev_kfree_skb_any(skb);
}
static int rx_alloc_pkts(struct hinic_rxq *rxq)
{
struct hinic_dev *nic_dev = netdev_priv(rxq->netdev);
struct hinic_rq_wqe *rq_wqe;
unsigned int free_wqebbs;
struct hinic_sge sge;
dma_addr_t dma_addr;
struct sk_buff *skb;
int i, alloc_more;
u16 prod_idx;
free_wqebbs = hinic_get_rq_free_wqebbs(rxq->rq);
alloc_more = 0;
if (free_wqebbs > nic_dev->rx_weight)
free_wqebbs = nic_dev->rx_weight;
for (i = 0; i < free_wqebbs; i++) {
skb = rx_alloc_skb(rxq, &dma_addr);
if (!skb) {
netdev_err(rxq->netdev, "Failed to alloc Rx skb\n");
alloc_more = 1;
goto skb_out;
}
hinic_set_sge(&sge, dma_addr, skb->len);
rq_wqe = hinic_rq_get_wqe(rxq->rq, HINIC_RQ_WQE_SIZE,
&prod_idx);
if (!rq_wqe) {
rx_free_skb(rxq, skb, dma_addr);
alloc_more = 1;
goto skb_out;
}
hinic_rq_prepare_wqe(rxq->rq, prod_idx, rq_wqe, &sge);
hinic_rq_write_wqe(rxq->rq, prod_idx, rq_wqe, skb);
}
skb_out:
if (i) {
wmb();
hinic_rq_update(rxq->rq, prod_idx);
}
if (alloc_more)
tasklet_schedule(&rxq->rx_task);
return i;
}
static void free_all_rx_skbs(struct hinic_rxq *rxq)
{
struct hinic_rq *rq = rxq->rq;
struct hinic_hw_wqe *hw_wqe;
struct hinic_sge sge;
u16 ci;
while ((hw_wqe = hinic_read_wqe(rq->wq, HINIC_RQ_WQE_SIZE, &ci))) {
if (IS_ERR(hw_wqe))
break;
hinic_rq_get_sge(rq, &hw_wqe->rq_wqe, ci, &sge);
hinic_put_wqe(rq->wq, HINIC_RQ_WQE_SIZE);
rx_free_skb(rxq, rq->saved_skb[ci], hinic_sge_to_dma(&sge));
}
}
static void rx_alloc_task(unsigned long data)
{
struct hinic_rxq *rxq = (struct hinic_rxq *)data;
(void)rx_alloc_pkts(rxq);
}
static int rx_recv_jumbo_pkt(struct hinic_rxq *rxq, struct sk_buff *head_skb,
unsigned int left_pkt_len, u16 ci)
{
struct sk_buff *skb, *curr_skb = head_skb;
struct hinic_rq_wqe *rq_wqe;
unsigned int curr_len;
struct hinic_sge sge;
int num_wqes = 0;
while (left_pkt_len > 0) {
rq_wqe = hinic_rq_read_next_wqe(rxq->rq, HINIC_RQ_WQE_SIZE,
&skb, &ci);
num_wqes++;
hinic_rq_get_sge(rxq->rq, rq_wqe, ci, &sge);
rx_unmap_skb(rxq, hinic_sge_to_dma(&sge));
prefetch(skb->data);
curr_len = (left_pkt_len > HINIC_RX_BUF_SZ) ? HINIC_RX_BUF_SZ :
left_pkt_len;
left_pkt_len -= curr_len;
__skb_put(skb, curr_len);
if (curr_skb == head_skb)
skb_shinfo(head_skb)->frag_list = skb;
else
curr_skb->next = skb;
head_skb->len += skb->len;
head_skb->data_len += skb->len;
head_skb->truesize += skb->truesize;
curr_skb = skb;
}
return num_wqes;
}
static int rxq_recv(struct hinic_rxq *rxq, int budget)
{
struct hinic_qp *qp = container_of(rxq->rq, struct hinic_qp, rq);
u64 pkt_len = 0, rx_bytes = 0;
struct hinic_rq_wqe *rq_wqe;
int num_wqes, pkts = 0;
struct hinic_sge sge;
struct sk_buff *skb;
u16 ci;
while (pkts < budget) {
num_wqes = 0;
rq_wqe = hinic_rq_read_wqe(rxq->rq, HINIC_RQ_WQE_SIZE, &skb,
&ci);
if (!rq_wqe)
break;
hinic_rq_get_sge(rxq->rq, rq_wqe, ci, &sge);
rx_unmap_skb(rxq, hinic_sge_to_dma(&sge));
prefetch(skb->data);
pkt_len = sge.len;
if (pkt_len <= HINIC_RX_BUF_SZ) {
__skb_put(skb, pkt_len);
} else {
__skb_put(skb, HINIC_RX_BUF_SZ);
num_wqes = rx_recv_jumbo_pkt(rxq, skb, pkt_len -
HINIC_RX_BUF_SZ, ci);
}
hinic_rq_put_wqe(rxq->rq, ci,
(num_wqes + 1) * HINIC_RQ_WQE_SIZE);
skb_record_rx_queue(skb, qp->q_id);
skb->protocol = eth_type_trans(skb, rxq->netdev);
napi_gro_receive(&rxq->napi, skb);
pkts++;
rx_bytes += pkt_len;
}
if (pkts)
tasklet_schedule(&rxq->rx_task);
u64_stats_update_begin(&rxq->rxq_stats.syncp);
rxq->rxq_stats.pkts += pkts;
rxq->rxq_stats.bytes += rx_bytes;
u64_stats_update_end(&rxq->rxq_stats.syncp);
return pkts;
}
static int rx_poll(struct napi_struct *napi, int budget)
{
struct hinic_rxq *rxq = container_of(napi, struct hinic_rxq, napi);
struct hinic_rq *rq = rxq->rq;
int pkts;
pkts = rxq_recv(rxq, budget);
if (pkts >= budget)
return budget;
napi_complete(napi);
enable_irq(rq->irq);
return pkts;
}
static void rx_add_napi(struct hinic_rxq *rxq)
{
struct hinic_dev *nic_dev = netdev_priv(rxq->netdev);
netif_napi_add(rxq->netdev, &rxq->napi, rx_poll, nic_dev->rx_weight);
napi_enable(&rxq->napi);
}
static void rx_del_napi(struct hinic_rxq *rxq)
{
napi_disable(&rxq->napi);
netif_napi_del(&rxq->napi);
}
static irqreturn_t rx_irq(int irq, void *data)
{
struct hinic_rxq *rxq = (struct hinic_rxq *)data;
struct hinic_rq *rq = rxq->rq;
struct hinic_dev *nic_dev;
disable_irq_nosync(rq->irq);
nic_dev = netdev_priv(rxq->netdev);
hinic_hwdev_msix_cnt_set(nic_dev->hwdev, rq->msix_entry);
napi_schedule(&rxq->napi);
return IRQ_HANDLED;
}
static int rx_request_irq(struct hinic_rxq *rxq)
{
struct hinic_dev *nic_dev = netdev_priv(rxq->netdev);
struct hinic_hwdev *hwdev = nic_dev->hwdev;
struct hinic_rq *rq = rxq->rq;
int err;
rx_add_napi(rxq);
hinic_hwdev_msix_set(hwdev, rq->msix_entry,
RX_IRQ_NO_PENDING, RX_IRQ_NO_COALESC,
RX_IRQ_NO_LLI_TIMER, RX_IRQ_NO_CREDIT,
RX_IRQ_NO_RESEND_TIMER);
err = request_irq(rq->irq, rx_irq, 0, rxq->irq_name, rxq);
if (err) {
rx_del_napi(rxq);
return err;
}
return 0;
}
static void rx_free_irq(struct hinic_rxq *rxq)
{
struct hinic_rq *rq = rxq->rq;
free_irq(rq->irq, rxq);
rx_del_napi(rxq);
}
int hinic_init_rxq(struct hinic_rxq *rxq, struct hinic_rq *rq,
struct net_device *netdev)
{
struct hinic_qp *qp = container_of(rq, struct hinic_qp, rq);
int err, pkts, irqname_len;
rxq->netdev = netdev;
rxq->rq = rq;
rxq_stats_init(rxq);
irqname_len = snprintf(NULL, 0, "hinic_rxq%d", qp->q_id) + 1;
rxq->irq_name = devm_kzalloc(&netdev->dev, irqname_len, GFP_KERNEL);
if (!rxq->irq_name)
return -ENOMEM;
sprintf(rxq->irq_name, "hinic_rxq%d", qp->q_id);
tasklet_init(&rxq->rx_task, rx_alloc_task, (unsigned long)rxq);
pkts = rx_alloc_pkts(rxq);
if (!pkts) {
err = -ENOMEM;
goto err_rx_pkts;
}
err = rx_request_irq(rxq);
if (err) {
netdev_err(netdev, "Failed to request Rx irq\n");
goto err_req_rx_irq;
}
return 0;
err_req_rx_irq:
err_rx_pkts:
tasklet_kill(&rxq->rx_task);
free_all_rx_skbs(rxq);
devm_kfree(&netdev->dev, rxq->irq_name);
return err;
}
void hinic_clean_rxq(struct hinic_rxq *rxq)
{
struct net_device *netdev = rxq->netdev;
rx_free_irq(rxq);
tasklet_kill(&rxq->rx_task);
free_all_rx_skbs(rxq);
devm_kfree(&netdev->dev, rxq->irq_name);
}
