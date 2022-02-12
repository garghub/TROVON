void nfp_net_get_fw_version(struct nfp_net_fw_version *fw_ver,
void __iomem *ctrl_bar)
{
u32 reg;
reg = readl(ctrl_bar + NFP_NET_CFG_VERSION);
put_unaligned_le32(reg, fw_ver);
}
static void nfp_net_reconfig_start(struct nfp_net *nn, u32 update)
{
nn_writel(nn, NFP_NET_CFG_UPDATE, update);
nn_pci_flush(nn);
nfp_qcp_wr_ptr_add(nn->qcp_cfg, 1);
}
static void nfp_net_reconfig_start_async(struct nfp_net *nn, u32 update)
{
update |= nn->reconfig_posted;
nn->reconfig_posted = 0;
nfp_net_reconfig_start(nn, update);
nn->reconfig_timer_active = true;
mod_timer(&nn->reconfig_timer, jiffies + NFP_NET_POLL_TIMEOUT * HZ);
}
static bool nfp_net_reconfig_check_done(struct nfp_net *nn, bool last_check)
{
u32 reg;
reg = nn_readl(nn, NFP_NET_CFG_UPDATE);
if (reg == 0)
return true;
if (reg & NFP_NET_CFG_UPDATE_ERR) {
nn_err(nn, "Reconfig error: 0x%08x\n", reg);
return true;
} else if (last_check) {
nn_err(nn, "Reconfig timeout: 0x%08x\n", reg);
return true;
}
return false;
}
static int nfp_net_reconfig_wait(struct nfp_net *nn, unsigned long deadline)
{
bool timed_out = false;
while (!nfp_net_reconfig_check_done(nn, timed_out)) {
msleep(1);
timed_out = time_is_before_eq_jiffies(deadline);
}
if (nn_readl(nn, NFP_NET_CFG_UPDATE) & NFP_NET_CFG_UPDATE_ERR)
return -EIO;
return timed_out ? -EIO : 0;
}
static void nfp_net_reconfig_timer(unsigned long data)
{
struct nfp_net *nn = (void *)data;
spin_lock_bh(&nn->reconfig_lock);
nn->reconfig_timer_active = false;
if (nn->reconfig_sync_present)
goto done;
nfp_net_reconfig_check_done(nn, true);
if (nn->reconfig_posted)
nfp_net_reconfig_start_async(nn, 0);
done:
spin_unlock_bh(&nn->reconfig_lock);
}
static void nfp_net_reconfig_post(struct nfp_net *nn, u32 update)
{
spin_lock_bh(&nn->reconfig_lock);
if (nn->reconfig_sync_present) {
nn->reconfig_posted |= update;
goto done;
}
if (!nn->reconfig_timer_active ||
nfp_net_reconfig_check_done(nn, false))
nfp_net_reconfig_start_async(nn, update);
else
nn->reconfig_posted |= update;
done:
spin_unlock_bh(&nn->reconfig_lock);
}
int nfp_net_reconfig(struct nfp_net *nn, u32 update)
{
bool cancelled_timer = false;
u32 pre_posted_requests;
int ret;
spin_lock_bh(&nn->reconfig_lock);
nn->reconfig_sync_present = true;
if (nn->reconfig_timer_active) {
del_timer(&nn->reconfig_timer);
nn->reconfig_timer_active = false;
cancelled_timer = true;
}
pre_posted_requests = nn->reconfig_posted;
nn->reconfig_posted = 0;
spin_unlock_bh(&nn->reconfig_lock);
if (cancelled_timer)
nfp_net_reconfig_wait(nn, nn->reconfig_timer.expires);
if (pre_posted_requests) {
nfp_net_reconfig_start(nn, pre_posted_requests);
nfp_net_reconfig_wait(nn, jiffies + HZ * NFP_NET_POLL_TIMEOUT);
}
nfp_net_reconfig_start(nn, update);
ret = nfp_net_reconfig_wait(nn, jiffies + HZ * NFP_NET_POLL_TIMEOUT);
spin_lock_bh(&nn->reconfig_lock);
if (nn->reconfig_posted)
nfp_net_reconfig_start_async(nn, 0);
nn->reconfig_sync_present = false;
spin_unlock_bh(&nn->reconfig_lock);
return ret;
}
static void nfp_net_irq_unmask_msix(struct nfp_net *nn, unsigned int entry_nr)
{
struct list_head *msi_head = &nn->pdev->dev.msi_list;
struct msi_desc *entry;
u32 off;
entry = list_first_entry(msi_head, struct msi_desc, list);
off = (PCI_MSIX_ENTRY_SIZE * entry_nr) +
PCI_MSIX_ENTRY_VECTOR_CTRL;
writel(0, entry->mask_base + off);
readl(entry->mask_base);
}
static void nfp_net_irq_unmask(struct nfp_net *nn, unsigned int entry_nr)
{
if (nn->ctrl & NFP_NET_CFG_CTRL_MSIXAUTO) {
nfp_net_irq_unmask_msix(nn, entry_nr);
return;
}
nn_writeb(nn, NFP_NET_CFG_ICR(entry_nr), NFP_NET_CFG_ICR_UNMASKED);
nn_pci_flush(nn);
}
static int nfp_net_msix_alloc(struct nfp_net *nn, int nr_vecs)
{
struct pci_dev *pdev = nn->pdev;
int nvecs;
int i;
for (i = 0; i < nr_vecs; i++)
nn->irq_entries[i].entry = i;
nvecs = pci_enable_msix_range(pdev, nn->irq_entries,
NFP_NET_NON_Q_VECTORS + 1, nr_vecs);
if (nvecs < 0) {
nn_warn(nn, "Failed to enable MSI-X. Wanted %d-%d (err=%d)\n",
NFP_NET_NON_Q_VECTORS + 1, nr_vecs, nvecs);
return 0;
}
return nvecs;
}
static int nfp_net_irqs_wanted(struct nfp_net *nn)
{
int ncpus;
int vecs;
ncpus = num_online_cpus();
vecs = max_t(int, nn->num_tx_rings, nn->num_rx_rings);
vecs = min_t(int, vecs, ncpus);
return vecs + NFP_NET_NON_Q_VECTORS;
}
int nfp_net_irqs_alloc(struct nfp_net *nn)
{
int wanted_irqs;
wanted_irqs = nfp_net_irqs_wanted(nn);
nn->num_irqs = nfp_net_msix_alloc(nn, wanted_irqs);
if (nn->num_irqs == 0) {
nn_err(nn, "Failed to allocate MSI-X IRQs\n");
return 0;
}
nn->num_r_vecs = nn->num_irqs - NFP_NET_NON_Q_VECTORS;
if (nn->num_irqs < wanted_irqs)
nn_warn(nn, "Unable to allocate %d vectors. Got %d instead\n",
wanted_irqs, nn->num_irqs);
return nn->num_irqs;
}
void nfp_net_irqs_disable(struct nfp_net *nn)
{
pci_disable_msix(nn->pdev);
}
static irqreturn_t nfp_net_irq_rxtx(int irq, void *data)
{
struct nfp_net_r_vector *r_vec = data;
napi_schedule_irqoff(&r_vec->napi);
return IRQ_HANDLED;
}
static void nfp_net_read_link_status(struct nfp_net *nn)
{
unsigned long flags;
bool link_up;
u32 sts;
spin_lock_irqsave(&nn->link_status_lock, flags);
sts = nn_readl(nn, NFP_NET_CFG_STS);
link_up = !!(sts & NFP_NET_CFG_STS_LINK);
if (nn->link_up == link_up)
goto out;
nn->link_up = link_up;
if (nn->link_up) {
netif_carrier_on(nn->netdev);
netdev_info(nn->netdev, "NIC Link is Up\n");
} else {
netif_carrier_off(nn->netdev);
netdev_info(nn->netdev, "NIC Link is Down\n");
}
out:
spin_unlock_irqrestore(&nn->link_status_lock, flags);
}
static irqreturn_t nfp_net_irq_lsc(int irq, void *data)
{
struct nfp_net *nn = data;
nfp_net_read_link_status(nn);
nfp_net_irq_unmask(nn, NFP_NET_IRQ_LSC_IDX);
return IRQ_HANDLED;
}
static irqreturn_t nfp_net_irq_exn(int irq, void *data)
{
struct nfp_net *nn = data;
nn_err(nn, "%s: UNIMPLEMENTED.\n", __func__);
return IRQ_HANDLED;
}
static void
nfp_net_tx_ring_init(struct nfp_net_tx_ring *tx_ring,
struct nfp_net_r_vector *r_vec, unsigned int idx)
{
struct nfp_net *nn = r_vec->nfp_net;
tx_ring->idx = idx;
tx_ring->r_vec = r_vec;
tx_ring->qcidx = tx_ring->idx * nn->stride_tx;
tx_ring->qcp_q = nn->tx_bar + NFP_QCP_QUEUE_OFF(tx_ring->qcidx);
}
static void
nfp_net_rx_ring_init(struct nfp_net_rx_ring *rx_ring,
struct nfp_net_r_vector *r_vec, unsigned int idx)
{
struct nfp_net *nn = r_vec->nfp_net;
rx_ring->idx = idx;
rx_ring->r_vec = r_vec;
rx_ring->fl_qcidx = rx_ring->idx * nn->stride_rx;
rx_ring->rx_qcidx = rx_ring->fl_qcidx + (nn->stride_rx - 1);
rx_ring->qcp_fl = nn->rx_bar + NFP_QCP_QUEUE_OFF(rx_ring->fl_qcidx);
rx_ring->qcp_rx = nn->rx_bar + NFP_QCP_QUEUE_OFF(rx_ring->rx_qcidx);
}
static void nfp_net_irqs_assign(struct net_device *netdev)
{
struct nfp_net *nn = netdev_priv(netdev);
struct nfp_net_r_vector *r_vec;
int r;
if (nn->num_tx_rings > nn->num_r_vecs) {
nn_warn(nn, "More rings (%d) than vectors (%d).\n",
nn->num_tx_rings, nn->num_r_vecs);
nn->num_tx_rings = nn->num_r_vecs;
nn->num_rx_rings = nn->num_r_vecs;
}
nn->lsc_handler = nfp_net_irq_lsc;
nn->exn_handler = nfp_net_irq_exn;
for (r = 0; r < nn->num_r_vecs; r++) {
r_vec = &nn->r_vecs[r];
r_vec->nfp_net = nn;
r_vec->handler = nfp_net_irq_rxtx;
r_vec->irq_idx = NFP_NET_NON_Q_VECTORS + r;
cpumask_set_cpu(r, &r_vec->affinity_mask);
}
}
static int
nfp_net_aux_irq_request(struct nfp_net *nn, u32 ctrl_offset,
const char *format, char *name, size_t name_sz,
unsigned int vector_idx, irq_handler_t handler)
{
struct msix_entry *entry;
int err;
entry = &nn->irq_entries[vector_idx];
snprintf(name, name_sz, format, netdev_name(nn->netdev));
err = request_irq(entry->vector, handler, 0, name, nn);
if (err) {
nn_err(nn, "Failed to request IRQ %d (err=%d).\n",
entry->vector, err);
return err;
}
nn_writeb(nn, ctrl_offset, vector_idx);
return 0;
}
static void nfp_net_aux_irq_free(struct nfp_net *nn, u32 ctrl_offset,
unsigned int vector_idx)
{
nn_writeb(nn, ctrl_offset, 0xff);
free_irq(nn->irq_entries[vector_idx].vector, nn);
}
static inline int nfp_net_tx_full(struct nfp_net_tx_ring *tx_ring, int dcnt)
{
return (tx_ring->wr_p - tx_ring->rd_p) >= (tx_ring->cnt - dcnt);
}
static int nfp_net_tx_ring_should_wake(struct nfp_net_tx_ring *tx_ring)
{
return !nfp_net_tx_full(tx_ring, MAX_SKB_FRAGS * 4);
}
static int nfp_net_tx_ring_should_stop(struct nfp_net_tx_ring *tx_ring)
{
return nfp_net_tx_full(tx_ring, MAX_SKB_FRAGS + 1);
}
static void nfp_net_tx_ring_stop(struct netdev_queue *nd_q,
struct nfp_net_tx_ring *tx_ring)
{
netif_tx_stop_queue(nd_q);
smp_mb();
if (unlikely(nfp_net_tx_ring_should_wake(tx_ring)))
netif_tx_start_queue(nd_q);
}
static void nfp_net_tx_tso(struct nfp_net *nn, struct nfp_net_r_vector *r_vec,
struct nfp_net_tx_buf *txbuf,
struct nfp_net_tx_desc *txd, struct sk_buff *skb)
{
u32 hdrlen;
u16 mss;
if (!skb_is_gso(skb))
return;
if (!skb->encapsulation)
hdrlen = skb_transport_offset(skb) + tcp_hdrlen(skb);
else
hdrlen = skb_inner_transport_header(skb) - skb->data +
inner_tcp_hdrlen(skb);
txbuf->pkt_cnt = skb_shinfo(skb)->gso_segs;
txbuf->real_len += hdrlen * (txbuf->pkt_cnt - 1);
mss = skb_shinfo(skb)->gso_size & PCIE_DESC_TX_MSS_MASK;
txd->l4_offset = hdrlen;
txd->mss = cpu_to_le16(mss);
txd->flags |= PCIE_DESC_TX_LSO;
u64_stats_update_begin(&r_vec->tx_sync);
r_vec->tx_lso++;
u64_stats_update_end(&r_vec->tx_sync);
}
static void nfp_net_tx_csum(struct nfp_net *nn, struct nfp_net_r_vector *r_vec,
struct nfp_net_tx_buf *txbuf,
struct nfp_net_tx_desc *txd, struct sk_buff *skb)
{
struct ipv6hdr *ipv6h;
struct iphdr *iph;
u8 l4_hdr;
if (!(nn->ctrl & NFP_NET_CFG_CTRL_TXCSUM))
return;
if (skb->ip_summed != CHECKSUM_PARTIAL)
return;
txd->flags |= PCIE_DESC_TX_CSUM;
if (skb->encapsulation)
txd->flags |= PCIE_DESC_TX_ENCAP;
iph = skb->encapsulation ? inner_ip_hdr(skb) : ip_hdr(skb);
ipv6h = skb->encapsulation ? inner_ipv6_hdr(skb) : ipv6_hdr(skb);
if (iph->version == 4) {
txd->flags |= PCIE_DESC_TX_IP4_CSUM;
l4_hdr = iph->protocol;
} else if (ipv6h->version == 6) {
l4_hdr = ipv6h->nexthdr;
} else {
nn_warn_ratelimit(nn, "partial checksum but ipv=%x!\n",
iph->version);
return;
}
switch (l4_hdr) {
case IPPROTO_TCP:
txd->flags |= PCIE_DESC_TX_TCP_CSUM;
break;
case IPPROTO_UDP:
txd->flags |= PCIE_DESC_TX_UDP_CSUM;
break;
default:
nn_warn_ratelimit(nn, "partial checksum but l4 proto=%x!\n",
l4_hdr);
return;
}
u64_stats_update_begin(&r_vec->tx_sync);
if (skb->encapsulation)
r_vec->hw_csum_tx_inner += txbuf->pkt_cnt;
else
r_vec->hw_csum_tx += txbuf->pkt_cnt;
u64_stats_update_end(&r_vec->tx_sync);
}
static int nfp_net_tx(struct sk_buff *skb, struct net_device *netdev)
{
struct nfp_net *nn = netdev_priv(netdev);
const struct skb_frag_struct *frag;
struct nfp_net_r_vector *r_vec;
struct nfp_net_tx_desc *txd, txdg;
struct nfp_net_tx_buf *txbuf;
struct nfp_net_tx_ring *tx_ring;
struct netdev_queue *nd_q;
dma_addr_t dma_addr;
unsigned int fsize;
int f, nr_frags;
int wr_idx;
u16 qidx;
qidx = skb_get_queue_mapping(skb);
tx_ring = &nn->tx_rings[qidx];
r_vec = tx_ring->r_vec;
nd_q = netdev_get_tx_queue(nn->netdev, qidx);
nr_frags = skb_shinfo(skb)->nr_frags;
if (unlikely(nfp_net_tx_full(tx_ring, nr_frags + 1))) {
nn_warn_ratelimit(nn, "TX ring %d busy. wrp=%u rdp=%u\n",
qidx, tx_ring->wr_p, tx_ring->rd_p);
netif_tx_stop_queue(nd_q);
u64_stats_update_begin(&r_vec->tx_sync);
r_vec->tx_busy++;
u64_stats_update_end(&r_vec->tx_sync);
return NETDEV_TX_BUSY;
}
dma_addr = dma_map_single(&nn->pdev->dev, skb->data, skb_headlen(skb),
DMA_TO_DEVICE);
if (dma_mapping_error(&nn->pdev->dev, dma_addr))
goto err_free;
wr_idx = tx_ring->wr_p % tx_ring->cnt;
txbuf = &tx_ring->txbufs[wr_idx];
txbuf->skb = skb;
txbuf->dma_addr = dma_addr;
txbuf->fidx = -1;
txbuf->pkt_cnt = 1;
txbuf->real_len = skb->len;
txd = &tx_ring->txds[wr_idx];
txd->offset_eop = (nr_frags == 0) ? PCIE_DESC_TX_EOP : 0;
txd->dma_len = cpu_to_le16(skb_headlen(skb));
nfp_desc_set_dma_addr(txd, dma_addr);
txd->data_len = cpu_to_le16(skb->len);
txd->flags = 0;
txd->mss = 0;
txd->l4_offset = 0;
nfp_net_tx_tso(nn, r_vec, txbuf, txd, skb);
nfp_net_tx_csum(nn, r_vec, txbuf, txd, skb);
if (skb_vlan_tag_present(skb) && nn->ctrl & NFP_NET_CFG_CTRL_TXVLAN) {
txd->flags |= PCIE_DESC_TX_VLAN;
txd->vlan = cpu_to_le16(skb_vlan_tag_get(skb));
}
if (nr_frags > 0) {
txdg = *txd;
for (f = 0; f < nr_frags; f++) {
frag = &skb_shinfo(skb)->frags[f];
fsize = skb_frag_size(frag);
dma_addr = skb_frag_dma_map(&nn->pdev->dev, frag, 0,
fsize, DMA_TO_DEVICE);
if (dma_mapping_error(&nn->pdev->dev, dma_addr))
goto err_unmap;
wr_idx = (wr_idx + 1) % tx_ring->cnt;
tx_ring->txbufs[wr_idx].skb = skb;
tx_ring->txbufs[wr_idx].dma_addr = dma_addr;
tx_ring->txbufs[wr_idx].fidx = f;
txd = &tx_ring->txds[wr_idx];
*txd = txdg;
txd->dma_len = cpu_to_le16(fsize);
nfp_desc_set_dma_addr(txd, dma_addr);
txd->offset_eop =
(f == nr_frags - 1) ? PCIE_DESC_TX_EOP : 0;
}
u64_stats_update_begin(&r_vec->tx_sync);
r_vec->tx_gather++;
u64_stats_update_end(&r_vec->tx_sync);
}
netdev_tx_sent_queue(nd_q, txbuf->real_len);
tx_ring->wr_p += nr_frags + 1;
if (nfp_net_tx_ring_should_stop(tx_ring))
nfp_net_tx_ring_stop(nd_q, tx_ring);
tx_ring->wr_ptr_add += nr_frags + 1;
if (!skb->xmit_more || netif_xmit_stopped(nd_q)) {
wmb();
nfp_qcp_wr_ptr_add(tx_ring->qcp_q, tx_ring->wr_ptr_add);
tx_ring->wr_ptr_add = 0;
}
skb_tx_timestamp(skb);
return NETDEV_TX_OK;
err_unmap:
--f;
while (f >= 0) {
frag = &skb_shinfo(skb)->frags[f];
dma_unmap_page(&nn->pdev->dev,
tx_ring->txbufs[wr_idx].dma_addr,
skb_frag_size(frag), DMA_TO_DEVICE);
tx_ring->txbufs[wr_idx].skb = NULL;
tx_ring->txbufs[wr_idx].dma_addr = 0;
tx_ring->txbufs[wr_idx].fidx = -2;
wr_idx = wr_idx - 1;
if (wr_idx < 0)
wr_idx += tx_ring->cnt;
}
dma_unmap_single(&nn->pdev->dev, tx_ring->txbufs[wr_idx].dma_addr,
skb_headlen(skb), DMA_TO_DEVICE);
tx_ring->txbufs[wr_idx].skb = NULL;
tx_ring->txbufs[wr_idx].dma_addr = 0;
tx_ring->txbufs[wr_idx].fidx = -2;
err_free:
nn_warn_ratelimit(nn, "Failed to map DMA TX buffer\n");
u64_stats_update_begin(&r_vec->tx_sync);
r_vec->tx_errors++;
u64_stats_update_end(&r_vec->tx_sync);
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
static void nfp_net_tx_complete(struct nfp_net_tx_ring *tx_ring)
{
struct nfp_net_r_vector *r_vec = tx_ring->r_vec;
struct nfp_net *nn = r_vec->nfp_net;
const struct skb_frag_struct *frag;
struct netdev_queue *nd_q;
u32 done_pkts = 0, done_bytes = 0;
struct sk_buff *skb;
int todo, nr_frags;
u32 qcp_rd_p;
int fidx;
int idx;
qcp_rd_p = nfp_qcp_rd_ptr_read(tx_ring->qcp_q);
if (qcp_rd_p == tx_ring->qcp_rd_p)
return;
if (qcp_rd_p > tx_ring->qcp_rd_p)
todo = qcp_rd_p - tx_ring->qcp_rd_p;
else
todo = qcp_rd_p + tx_ring->cnt - tx_ring->qcp_rd_p;
while (todo--) {
idx = tx_ring->rd_p % tx_ring->cnt;
tx_ring->rd_p++;
skb = tx_ring->txbufs[idx].skb;
if (!skb)
continue;
nr_frags = skb_shinfo(skb)->nr_frags;
fidx = tx_ring->txbufs[idx].fidx;
if (fidx == -1) {
dma_unmap_single(&nn->pdev->dev,
tx_ring->txbufs[idx].dma_addr,
skb_headlen(skb), DMA_TO_DEVICE);
done_pkts += tx_ring->txbufs[idx].pkt_cnt;
done_bytes += tx_ring->txbufs[idx].real_len;
} else {
frag = &skb_shinfo(skb)->frags[fidx];
dma_unmap_page(&nn->pdev->dev,
tx_ring->txbufs[idx].dma_addr,
skb_frag_size(frag), DMA_TO_DEVICE);
}
if (fidx == nr_frags - 1)
dev_kfree_skb_any(skb);
tx_ring->txbufs[idx].dma_addr = 0;
tx_ring->txbufs[idx].skb = NULL;
tx_ring->txbufs[idx].fidx = -2;
}
tx_ring->qcp_rd_p = qcp_rd_p;
u64_stats_update_begin(&r_vec->tx_sync);
r_vec->tx_bytes += done_bytes;
r_vec->tx_pkts += done_pkts;
u64_stats_update_end(&r_vec->tx_sync);
nd_q = netdev_get_tx_queue(nn->netdev, tx_ring->idx);
netdev_tx_completed_queue(nd_q, done_pkts, done_bytes);
if (nfp_net_tx_ring_should_wake(tx_ring)) {
smp_mb();
if (unlikely(netif_tx_queue_stopped(nd_q)))
netif_tx_wake_queue(nd_q);
}
WARN_ONCE(tx_ring->wr_p - tx_ring->rd_p > tx_ring->cnt,
"TX ring corruption rd_p=%u wr_p=%u cnt=%u\n",
tx_ring->rd_p, tx_ring->wr_p, tx_ring->cnt);
}
static void
nfp_net_tx_ring_reset(struct nfp_net *nn, struct nfp_net_tx_ring *tx_ring)
{
const struct skb_frag_struct *frag;
struct netdev_queue *nd_q;
struct pci_dev *pdev = nn->pdev;
while (tx_ring->rd_p != tx_ring->wr_p) {
int nr_frags, fidx, idx;
struct sk_buff *skb;
idx = tx_ring->rd_p % tx_ring->cnt;
skb = tx_ring->txbufs[idx].skb;
nr_frags = skb_shinfo(skb)->nr_frags;
fidx = tx_ring->txbufs[idx].fidx;
if (fidx == -1) {
dma_unmap_single(&pdev->dev,
tx_ring->txbufs[idx].dma_addr,
skb_headlen(skb), DMA_TO_DEVICE);
} else {
frag = &skb_shinfo(skb)->frags[fidx];
dma_unmap_page(&pdev->dev,
tx_ring->txbufs[idx].dma_addr,
skb_frag_size(frag), DMA_TO_DEVICE);
}
if (fidx == nr_frags - 1)
dev_kfree_skb_any(skb);
tx_ring->txbufs[idx].dma_addr = 0;
tx_ring->txbufs[idx].skb = NULL;
tx_ring->txbufs[idx].fidx = -2;
tx_ring->qcp_rd_p++;
tx_ring->rd_p++;
}
memset(tx_ring->txds, 0, sizeof(*tx_ring->txds) * tx_ring->cnt);
tx_ring->wr_p = 0;
tx_ring->rd_p = 0;
tx_ring->qcp_rd_p = 0;
tx_ring->wr_ptr_add = 0;
nd_q = netdev_get_tx_queue(nn->netdev, tx_ring->idx);
netdev_tx_reset_queue(nd_q);
}
static void nfp_net_tx_timeout(struct net_device *netdev)
{
struct nfp_net *nn = netdev_priv(netdev);
int i;
for (i = 0; i < nn->num_tx_rings; i++) {
if (!netif_tx_queue_stopped(netdev_get_tx_queue(netdev, i)))
continue;
nn_warn(nn, "TX timeout on ring: %d\n", i);
}
nn_warn(nn, "TX watchdog timeout\n");
}
static inline int nfp_net_rx_space(struct nfp_net_rx_ring *rx_ring)
{
return (rx_ring->cnt - 1) - (rx_ring->wr_p - rx_ring->rd_p);
}
static struct sk_buff *
nfp_net_rx_alloc_one(struct nfp_net_rx_ring *rx_ring, dma_addr_t *dma_addr,
unsigned int fl_bufsz)
{
struct nfp_net *nn = rx_ring->r_vec->nfp_net;
struct sk_buff *skb;
skb = netdev_alloc_skb(nn->netdev, fl_bufsz);
if (!skb) {
nn_warn_ratelimit(nn, "Failed to alloc receive SKB\n");
return NULL;
}
*dma_addr = dma_map_single(&nn->pdev->dev, skb->data,
fl_bufsz, DMA_FROM_DEVICE);
if (dma_mapping_error(&nn->pdev->dev, *dma_addr)) {
dev_kfree_skb_any(skb);
nn_warn_ratelimit(nn, "Failed to map DMA RX buffer\n");
return NULL;
}
return skb;
}
static void nfp_net_rx_give_one(struct nfp_net_rx_ring *rx_ring,
struct sk_buff *skb, dma_addr_t dma_addr)
{
unsigned int wr_idx;
wr_idx = rx_ring->wr_p % rx_ring->cnt;
rx_ring->rxbufs[wr_idx].skb = skb;
rx_ring->rxbufs[wr_idx].dma_addr = dma_addr;
rx_ring->rxds[wr_idx].fld.reserved = 0;
rx_ring->rxds[wr_idx].fld.meta_len_dd = 0;
nfp_desc_set_dma_addr(&rx_ring->rxds[wr_idx].fld, dma_addr);
rx_ring->wr_p++;
rx_ring->wr_ptr_add++;
if (rx_ring->wr_ptr_add >= NFP_NET_FL_BATCH) {
wmb();
nfp_qcp_wr_ptr_add(rx_ring->qcp_fl, rx_ring->wr_ptr_add);
rx_ring->wr_ptr_add = 0;
}
}
static void nfp_net_rx_ring_reset(struct nfp_net_rx_ring *rx_ring)
{
unsigned int wr_idx, last_idx;
wr_idx = rx_ring->wr_p % rx_ring->cnt;
last_idx = rx_ring->cnt - 1;
rx_ring->rxbufs[wr_idx].dma_addr = rx_ring->rxbufs[last_idx].dma_addr;
rx_ring->rxbufs[wr_idx].skb = rx_ring->rxbufs[last_idx].skb;
rx_ring->rxbufs[last_idx].dma_addr = 0;
rx_ring->rxbufs[last_idx].skb = NULL;
memset(rx_ring->rxds, 0, sizeof(*rx_ring->rxds) * rx_ring->cnt);
rx_ring->wr_p = 0;
rx_ring->rd_p = 0;
rx_ring->wr_ptr_add = 0;
}
static void
nfp_net_rx_ring_bufs_free(struct nfp_net *nn, struct nfp_net_rx_ring *rx_ring)
{
struct pci_dev *pdev = nn->pdev;
unsigned int i;
for (i = 0; i < rx_ring->cnt - 1; i++) {
if (!rx_ring->rxbufs[i].skb)
continue;
dma_unmap_single(&pdev->dev, rx_ring->rxbufs[i].dma_addr,
rx_ring->bufsz, DMA_FROM_DEVICE);
dev_kfree_skb_any(rx_ring->rxbufs[i].skb);
rx_ring->rxbufs[i].dma_addr = 0;
rx_ring->rxbufs[i].skb = NULL;
}
}
static int
nfp_net_rx_ring_bufs_alloc(struct nfp_net *nn, struct nfp_net_rx_ring *rx_ring)
{
struct nfp_net_rx_buf *rxbufs;
unsigned int i;
rxbufs = rx_ring->rxbufs;
for (i = 0; i < rx_ring->cnt - 1; i++) {
rxbufs[i].skb =
nfp_net_rx_alloc_one(rx_ring, &rxbufs[i].dma_addr,
rx_ring->bufsz);
if (!rxbufs[i].skb) {
nfp_net_rx_ring_bufs_free(nn, rx_ring);
return -ENOMEM;
}
}
return 0;
}
static void nfp_net_rx_ring_fill_freelist(struct nfp_net_rx_ring *rx_ring)
{
unsigned int i;
for (i = 0; i < rx_ring->cnt - 1; i++)
nfp_net_rx_give_one(rx_ring, rx_ring->rxbufs[i].skb,
rx_ring->rxbufs[i].dma_addr);
}
static int nfp_net_rx_csum_has_errors(u16 flags)
{
u16 csum_all_checked, csum_all_ok;
csum_all_checked = flags & __PCIE_DESC_RX_CSUM_ALL;
csum_all_ok = flags & __PCIE_DESC_RX_CSUM_ALL_OK;
return csum_all_checked != (csum_all_ok << PCIE_DESC_RX_CSUM_OK_SHIFT);
}
static void nfp_net_rx_csum(struct nfp_net *nn, struct nfp_net_r_vector *r_vec,
struct nfp_net_rx_desc *rxd, struct sk_buff *skb)
{
skb_checksum_none_assert(skb);
if (!(nn->netdev->features & NETIF_F_RXCSUM))
return;
if (nfp_net_rx_csum_has_errors(le16_to_cpu(rxd->rxd.flags))) {
u64_stats_update_begin(&r_vec->rx_sync);
r_vec->hw_csum_rx_error++;
u64_stats_update_end(&r_vec->rx_sync);
return;
}
if (rxd->rxd.flags & PCIE_DESC_RX_TCP_CSUM_OK ||
rxd->rxd.flags & PCIE_DESC_RX_UDP_CSUM_OK) {
__skb_incr_checksum_unnecessary(skb);
u64_stats_update_begin(&r_vec->rx_sync);
r_vec->hw_csum_rx_ok++;
u64_stats_update_end(&r_vec->rx_sync);
}
if (rxd->rxd.flags & PCIE_DESC_RX_I_TCP_CSUM_OK ||
rxd->rxd.flags & PCIE_DESC_RX_I_UDP_CSUM_OK) {
__skb_incr_checksum_unnecessary(skb);
u64_stats_update_begin(&r_vec->rx_sync);
r_vec->hw_csum_rx_inner_ok++;
u64_stats_update_end(&r_vec->rx_sync);
}
}
static void nfp_net_set_hash(struct net_device *netdev, struct sk_buff *skb,
struct nfp_net_rx_desc *rxd)
{
struct nfp_net_rx_hash *rx_hash;
if (!(rxd->rxd.flags & PCIE_DESC_RX_RSS) ||
!(netdev->features & NETIF_F_RXHASH))
return;
rx_hash = (struct nfp_net_rx_hash *)(skb->data - sizeof(*rx_hash));
switch (be32_to_cpu(rx_hash->hash_type)) {
case NFP_NET_RSS_IPV4:
case NFP_NET_RSS_IPV6:
case NFP_NET_RSS_IPV6_EX:
skb_set_hash(skb, be32_to_cpu(rx_hash->hash), PKT_HASH_TYPE_L3);
break;
default:
skb_set_hash(skb, be32_to_cpu(rx_hash->hash), PKT_HASH_TYPE_L4);
break;
}
}
static int nfp_net_rx(struct nfp_net_rx_ring *rx_ring, int budget)
{
struct nfp_net_r_vector *r_vec = rx_ring->r_vec;
struct nfp_net *nn = r_vec->nfp_net;
unsigned int data_len, meta_len;
int avail = 0, pkts_polled = 0;
struct sk_buff *skb, *new_skb;
struct nfp_net_rx_desc *rxd;
dma_addr_t new_dma_addr;
u32 qcp_wr_p;
int idx;
if (nn->is_nfp3200) {
qcp_wr_p = nfp_qcp_wr_ptr_read(rx_ring->qcp_rx);
idx = rx_ring->rd_p % rx_ring->cnt;
if (qcp_wr_p == idx)
return 0;
if (qcp_wr_p > idx)
avail = qcp_wr_p - idx;
else
avail = qcp_wr_p + rx_ring->cnt - idx;
} else {
avail = budget + 1;
}
while (avail > 0 && pkts_polled < budget) {
idx = rx_ring->rd_p % rx_ring->cnt;
rxd = &rx_ring->rxds[idx];
if (!(rxd->rxd.meta_len_dd & PCIE_DESC_RX_DD)) {
if (nn->is_nfp3200)
nn_dbg(nn, "RX descriptor not valid (DD)%d:%u rxd[0]=%#x rxd[1]=%#x\n",
rx_ring->idx, idx,
rxd->vals[0], rxd->vals[1]);
break;
}
dma_rmb();
rx_ring->rd_p++;
pkts_polled++;
avail--;
skb = rx_ring->rxbufs[idx].skb;
new_skb = nfp_net_rx_alloc_one(rx_ring, &new_dma_addr,
nn->fl_bufsz);
if (!new_skb) {
nfp_net_rx_give_one(rx_ring, rx_ring->rxbufs[idx].skb,
rx_ring->rxbufs[idx].dma_addr);
u64_stats_update_begin(&r_vec->rx_sync);
r_vec->rx_drops++;
u64_stats_update_end(&r_vec->rx_sync);
continue;
}
dma_unmap_single(&nn->pdev->dev,
rx_ring->rxbufs[idx].dma_addr,
nn->fl_bufsz, DMA_FROM_DEVICE);
nfp_net_rx_give_one(rx_ring, new_skb, new_dma_addr);
meta_len = rxd->rxd.meta_len_dd & PCIE_DESC_RX_META_LEN_MASK;
data_len = le16_to_cpu(rxd->rxd.data_len);
if (nn->rx_offset == NFP_NET_CFG_RX_OFFSET_DYNAMIC)
skb_reserve(skb, meta_len);
else
skb_reserve(skb, nn->rx_offset);
skb_put(skb, data_len - meta_len);
nfp_net_set_hash(nn->netdev, skb, rxd);
u64_stats_update_begin(&r_vec->rx_sync);
r_vec->rx_pkts++;
r_vec->rx_bytes += skb->len;
u64_stats_update_end(&r_vec->rx_sync);
skb_record_rx_queue(skb, rx_ring->idx);
skb->protocol = eth_type_trans(skb, nn->netdev);
nfp_net_rx_csum(nn, r_vec, rxd, skb);
if (rxd->rxd.flags & PCIE_DESC_RX_VLAN)
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q),
le16_to_cpu(rxd->rxd.vlan));
napi_gro_receive(&rx_ring->r_vec->napi, skb);
}
if (nn->is_nfp3200)
nfp_qcp_rd_ptr_add(rx_ring->qcp_rx, pkts_polled);
return pkts_polled;
}
static int nfp_net_poll(struct napi_struct *napi, int budget)
{
struct nfp_net_r_vector *r_vec =
container_of(napi, struct nfp_net_r_vector, napi);
struct nfp_net_rx_ring *rx_ring = r_vec->rx_ring;
struct nfp_net_tx_ring *tx_ring = r_vec->tx_ring;
struct nfp_net *nn = r_vec->nfp_net;
struct netdev_queue *txq;
unsigned int pkts_polled;
tx_ring = &nn->tx_rings[rx_ring->idx];
txq = netdev_get_tx_queue(nn->netdev, tx_ring->idx);
nfp_net_tx_complete(tx_ring);
pkts_polled = nfp_net_rx(rx_ring, budget);
if (pkts_polled < budget) {
napi_complete_done(napi, pkts_polled);
nfp_net_irq_unmask(nn, r_vec->irq_idx);
}
return pkts_polled;
}
static void nfp_net_tx_ring_free(struct nfp_net_tx_ring *tx_ring)
{
struct nfp_net_r_vector *r_vec = tx_ring->r_vec;
struct nfp_net *nn = r_vec->nfp_net;
struct pci_dev *pdev = nn->pdev;
kfree(tx_ring->txbufs);
if (tx_ring->txds)
dma_free_coherent(&pdev->dev, tx_ring->size,
tx_ring->txds, tx_ring->dma);
tx_ring->cnt = 0;
tx_ring->txbufs = NULL;
tx_ring->txds = NULL;
tx_ring->dma = 0;
tx_ring->size = 0;
}
static int nfp_net_tx_ring_alloc(struct nfp_net_tx_ring *tx_ring, u32 cnt)
{
struct nfp_net_r_vector *r_vec = tx_ring->r_vec;
struct nfp_net *nn = r_vec->nfp_net;
struct pci_dev *pdev = nn->pdev;
int sz;
tx_ring->cnt = cnt;
tx_ring->size = sizeof(*tx_ring->txds) * tx_ring->cnt;
tx_ring->txds = dma_zalloc_coherent(&pdev->dev, tx_ring->size,
&tx_ring->dma, GFP_KERNEL);
if (!tx_ring->txds)
goto err_alloc;
sz = sizeof(*tx_ring->txbufs) * tx_ring->cnt;
tx_ring->txbufs = kzalloc(sz, GFP_KERNEL);
if (!tx_ring->txbufs)
goto err_alloc;
netif_set_xps_queue(nn->netdev, &r_vec->affinity_mask, tx_ring->idx);
nn_dbg(nn, "TxQ%02d: QCidx=%02d cnt=%d dma=%#llx host=%p\n",
tx_ring->idx, tx_ring->qcidx,
tx_ring->cnt, (unsigned long long)tx_ring->dma, tx_ring->txds);
return 0;
err_alloc:
nfp_net_tx_ring_free(tx_ring);
return -ENOMEM;
}
static struct nfp_net_tx_ring *
nfp_net_shadow_tx_rings_prepare(struct nfp_net *nn, u32 buf_cnt)
{
struct nfp_net_tx_ring *rings;
unsigned int r;
rings = kcalloc(nn->num_tx_rings, sizeof(*rings), GFP_KERNEL);
if (!rings)
return NULL;
for (r = 0; r < nn->num_tx_rings; r++) {
nfp_net_tx_ring_init(&rings[r], nn->tx_rings[r].r_vec, r);
if (nfp_net_tx_ring_alloc(&rings[r], buf_cnt))
goto err_free_prev;
}
return rings;
err_free_prev:
while (r--)
nfp_net_tx_ring_free(&rings[r]);
kfree(rings);
return NULL;
}
static struct nfp_net_tx_ring *
nfp_net_shadow_tx_rings_swap(struct nfp_net *nn, struct nfp_net_tx_ring *rings)
{
struct nfp_net_tx_ring *old = nn->tx_rings;
unsigned int r;
for (r = 0; r < nn->num_tx_rings; r++)
old[r].r_vec->tx_ring = &rings[r];
nn->tx_rings = rings;
return old;
}
static void
nfp_net_shadow_tx_rings_free(struct nfp_net *nn, struct nfp_net_tx_ring *rings)
{
unsigned int r;
if (!rings)
return;
for (r = 0; r < nn->num_tx_rings; r++)
nfp_net_tx_ring_free(&rings[r]);
kfree(rings);
}
static void nfp_net_rx_ring_free(struct nfp_net_rx_ring *rx_ring)
{
struct nfp_net_r_vector *r_vec = rx_ring->r_vec;
struct nfp_net *nn = r_vec->nfp_net;
struct pci_dev *pdev = nn->pdev;
kfree(rx_ring->rxbufs);
if (rx_ring->rxds)
dma_free_coherent(&pdev->dev, rx_ring->size,
rx_ring->rxds, rx_ring->dma);
rx_ring->cnt = 0;
rx_ring->rxbufs = NULL;
rx_ring->rxds = NULL;
rx_ring->dma = 0;
rx_ring->size = 0;
}
static int
nfp_net_rx_ring_alloc(struct nfp_net_rx_ring *rx_ring, unsigned int fl_bufsz,
u32 cnt)
{
struct nfp_net_r_vector *r_vec = rx_ring->r_vec;
struct nfp_net *nn = r_vec->nfp_net;
struct pci_dev *pdev = nn->pdev;
int sz;
rx_ring->cnt = cnt;
rx_ring->bufsz = fl_bufsz;
rx_ring->size = sizeof(*rx_ring->rxds) * rx_ring->cnt;
rx_ring->rxds = dma_zalloc_coherent(&pdev->dev, rx_ring->size,
&rx_ring->dma, GFP_KERNEL);
if (!rx_ring->rxds)
goto err_alloc;
sz = sizeof(*rx_ring->rxbufs) * rx_ring->cnt;
rx_ring->rxbufs = kzalloc(sz, GFP_KERNEL);
if (!rx_ring->rxbufs)
goto err_alloc;
nn_dbg(nn, "RxQ%02d: FlQCidx=%02d RxQCidx=%02d cnt=%d dma=%#llx host=%p\n",
rx_ring->idx, rx_ring->fl_qcidx, rx_ring->rx_qcidx,
rx_ring->cnt, (unsigned long long)rx_ring->dma, rx_ring->rxds);
return 0;
err_alloc:
nfp_net_rx_ring_free(rx_ring);
return -ENOMEM;
}
static struct nfp_net_rx_ring *
nfp_net_shadow_rx_rings_prepare(struct nfp_net *nn, unsigned int fl_bufsz,
u32 buf_cnt)
{
struct nfp_net_rx_ring *rings;
unsigned int r;
rings = kcalloc(nn->num_rx_rings, sizeof(*rings), GFP_KERNEL);
if (!rings)
return NULL;
for (r = 0; r < nn->num_rx_rings; r++) {
nfp_net_rx_ring_init(&rings[r], nn->rx_rings[r].r_vec, r);
if (nfp_net_rx_ring_alloc(&rings[r], fl_bufsz, buf_cnt))
goto err_free_prev;
if (nfp_net_rx_ring_bufs_alloc(nn, &rings[r]))
goto err_free_ring;
}
return rings;
err_free_prev:
while (r--) {
nfp_net_rx_ring_bufs_free(nn, &rings[r]);
err_free_ring:
nfp_net_rx_ring_free(&rings[r]);
}
kfree(rings);
return NULL;
}
static struct nfp_net_rx_ring *
nfp_net_shadow_rx_rings_swap(struct nfp_net *nn, struct nfp_net_rx_ring *rings)
{
struct nfp_net_rx_ring *old = nn->rx_rings;
unsigned int r;
for (r = 0; r < nn->num_rx_rings; r++)
old[r].r_vec->rx_ring = &rings[r];
nn->rx_rings = rings;
return old;
}
static void
nfp_net_shadow_rx_rings_free(struct nfp_net *nn, struct nfp_net_rx_ring *rings)
{
unsigned int r;
if (!rings)
return;
for (r = 0; r < nn->num_r_vecs; r++) {
nfp_net_rx_ring_bufs_free(nn, &rings[r]);
nfp_net_rx_ring_free(&rings[r]);
}
kfree(rings);
}
static int
nfp_net_prepare_vector(struct nfp_net *nn, struct nfp_net_r_vector *r_vec,
int idx)
{
struct msix_entry *entry = &nn->irq_entries[r_vec->irq_idx];
int err;
r_vec->tx_ring = &nn->tx_rings[idx];
nfp_net_tx_ring_init(r_vec->tx_ring, r_vec, idx);
r_vec->rx_ring = &nn->rx_rings[idx];
nfp_net_rx_ring_init(r_vec->rx_ring, r_vec, idx);
snprintf(r_vec->name, sizeof(r_vec->name),
"%s-rxtx-%d", nn->netdev->name, idx);
err = request_irq(entry->vector, r_vec->handler, 0, r_vec->name, r_vec);
if (err) {
nn_err(nn, "Error requesting IRQ %d\n", entry->vector);
return err;
}
disable_irq(entry->vector);
netif_napi_add(nn->netdev, &r_vec->napi,
nfp_net_poll, NAPI_POLL_WEIGHT);
irq_set_affinity_hint(entry->vector, &r_vec->affinity_mask);
nn_dbg(nn, "RV%02d: irq=%03d/%03d\n", idx, entry->vector, entry->entry);
return 0;
}
static void
nfp_net_cleanup_vector(struct nfp_net *nn, struct nfp_net_r_vector *r_vec)
{
struct msix_entry *entry = &nn->irq_entries[r_vec->irq_idx];
irq_set_affinity_hint(entry->vector, NULL);
netif_napi_del(&r_vec->napi);
free_irq(entry->vector, r_vec);
}
void nfp_net_rss_write_itbl(struct nfp_net *nn)
{
int i;
for (i = 0; i < NFP_NET_CFG_RSS_ITBL_SZ; i += 4)
nn_writel(nn, NFP_NET_CFG_RSS_ITBL + i,
get_unaligned_le32(nn->rss_itbl + i));
}
void nfp_net_rss_write_key(struct nfp_net *nn)
{
int i;
for (i = 0; i < NFP_NET_CFG_RSS_KEY_SZ; i += 4)
nn_writel(nn, NFP_NET_CFG_RSS_KEY + i,
get_unaligned_le32(nn->rss_key + i));
}
void nfp_net_coalesce_write_cfg(struct nfp_net *nn)
{
u8 i;
u32 factor;
u32 value;
factor = nn->me_freq_mhz / 16;
value = (nn->rx_coalesce_max_frames << 16) |
(factor * nn->rx_coalesce_usecs);
for (i = 0; i < nn->num_r_vecs; i++)
nn_writel(nn, NFP_NET_CFG_RXR_IRQ_MOD(i), value);
value = (nn->tx_coalesce_max_frames << 16) |
(factor * nn->tx_coalesce_usecs);
for (i = 0; i < nn->num_r_vecs; i++)
nn_writel(nn, NFP_NET_CFG_TXR_IRQ_MOD(i), value);
}
static void nfp_net_write_mac_addr(struct nfp_net *nn)
{
nn_writel(nn, NFP_NET_CFG_MACADDR + 0,
get_unaligned_be32(nn->netdev->dev_addr));
nn_writel(nn, NFP_NET_CFG_MACADDR + 4,
get_unaligned_be16(nn->netdev->dev_addr + 4) << 16);
}
static void nfp_net_vec_clear_ring_data(struct nfp_net *nn, unsigned int idx)
{
nn_writeq(nn, NFP_NET_CFG_RXR_ADDR(idx), 0);
nn_writeb(nn, NFP_NET_CFG_RXR_SZ(idx), 0);
nn_writeb(nn, NFP_NET_CFG_RXR_VEC(idx), 0);
nn_writeq(nn, NFP_NET_CFG_TXR_ADDR(idx), 0);
nn_writeb(nn, NFP_NET_CFG_TXR_SZ(idx), 0);
nn_writeb(nn, NFP_NET_CFG_TXR_VEC(idx), 0);
}
static void nfp_net_clear_config_and_disable(struct nfp_net *nn)
{
u32 new_ctrl, update;
unsigned int r;
int err;
new_ctrl = nn->ctrl;
new_ctrl &= ~NFP_NET_CFG_CTRL_ENABLE;
update = NFP_NET_CFG_UPDATE_GEN;
update |= NFP_NET_CFG_UPDATE_MSIX;
update |= NFP_NET_CFG_UPDATE_RING;
if (nn->cap & NFP_NET_CFG_CTRL_RINGCFG)
new_ctrl &= ~NFP_NET_CFG_CTRL_RINGCFG;
nn_writeq(nn, NFP_NET_CFG_TXRS_ENABLE, 0);
nn_writeq(nn, NFP_NET_CFG_RXRS_ENABLE, 0);
nn_writel(nn, NFP_NET_CFG_CTRL, new_ctrl);
err = nfp_net_reconfig(nn, update);
if (err)
nn_err(nn, "Could not disable device: %d\n", err);
for (r = 0; r < nn->num_r_vecs; r++) {
nfp_net_rx_ring_reset(nn->r_vecs[r].rx_ring);
nfp_net_tx_ring_reset(nn, nn->r_vecs[r].tx_ring);
nfp_net_vec_clear_ring_data(nn, r);
}
nn->ctrl = new_ctrl;
}
static void
nfp_net_vec_write_ring_data(struct nfp_net *nn, struct nfp_net_r_vector *r_vec,
unsigned int idx)
{
nn_writeq(nn, NFP_NET_CFG_RXR_ADDR(idx), r_vec->rx_ring->dma);
nn_writeb(nn, NFP_NET_CFG_RXR_SZ(idx), ilog2(r_vec->rx_ring->cnt));
nn_writeb(nn, NFP_NET_CFG_RXR_VEC(idx), r_vec->irq_idx);
nn_writeq(nn, NFP_NET_CFG_TXR_ADDR(idx), r_vec->tx_ring->dma);
nn_writeb(nn, NFP_NET_CFG_TXR_SZ(idx), ilog2(r_vec->tx_ring->cnt));
nn_writeb(nn, NFP_NET_CFG_TXR_VEC(idx), r_vec->irq_idx);
}
static int __nfp_net_set_config_and_enable(struct nfp_net *nn)
{
u32 new_ctrl, update = 0;
unsigned int r;
int err;
new_ctrl = nn->ctrl;
if (nn->cap & NFP_NET_CFG_CTRL_RSS) {
nfp_net_rss_write_key(nn);
nfp_net_rss_write_itbl(nn);
nn_writel(nn, NFP_NET_CFG_RSS_CTRL, nn->rss_cfg);
update |= NFP_NET_CFG_UPDATE_RSS;
}
if (nn->cap & NFP_NET_CFG_CTRL_IRQMOD) {
nfp_net_coalesce_write_cfg(nn);
new_ctrl |= NFP_NET_CFG_CTRL_IRQMOD;
update |= NFP_NET_CFG_UPDATE_IRQMOD;
}
for (r = 0; r < nn->num_r_vecs; r++)
nfp_net_vec_write_ring_data(nn, &nn->r_vecs[r], r);
nn_writeq(nn, NFP_NET_CFG_TXRS_ENABLE, nn->num_tx_rings == 64 ?
0xffffffffffffffffULL : ((u64)1 << nn->num_tx_rings) - 1);
nn_writeq(nn, NFP_NET_CFG_RXRS_ENABLE, nn->num_rx_rings == 64 ?
0xffffffffffffffffULL : ((u64)1 << nn->num_rx_rings) - 1);
nfp_net_write_mac_addr(nn);
nn_writel(nn, NFP_NET_CFG_MTU, nn->netdev->mtu);
nn_writel(nn, NFP_NET_CFG_FLBUFSZ, nn->fl_bufsz);
new_ctrl |= NFP_NET_CFG_CTRL_ENABLE;
update |= NFP_NET_CFG_UPDATE_GEN;
update |= NFP_NET_CFG_UPDATE_MSIX;
update |= NFP_NET_CFG_UPDATE_RING;
if (nn->cap & NFP_NET_CFG_CTRL_RINGCFG)
new_ctrl |= NFP_NET_CFG_CTRL_RINGCFG;
nn_writel(nn, NFP_NET_CFG_CTRL, new_ctrl);
err = nfp_net_reconfig(nn, update);
nn->ctrl = new_ctrl;
for (r = 0; r < nn->num_r_vecs; r++)
nfp_net_rx_ring_fill_freelist(nn->r_vecs[r].rx_ring);
if (nn->ctrl & NFP_NET_CFG_CTRL_VXLAN) {
memset(&nn->vxlan_ports, 0, sizeof(nn->vxlan_ports));
memset(&nn->vxlan_usecnt, 0, sizeof(nn->vxlan_usecnt));
udp_tunnel_get_rx_info(nn->netdev);
}
return err;
}
static int nfp_net_set_config_and_enable(struct nfp_net *nn)
{
int err;
err = __nfp_net_set_config_and_enable(nn);
if (err)
nfp_net_clear_config_and_disable(nn);
return err;
}
static void nfp_net_open_stack(struct nfp_net *nn)
{
unsigned int r;
for (r = 0; r < nn->num_r_vecs; r++) {
napi_enable(&nn->r_vecs[r].napi);
enable_irq(nn->irq_entries[nn->r_vecs[r].irq_idx].vector);
}
netif_tx_wake_all_queues(nn->netdev);
enable_irq(nn->irq_entries[NFP_NET_IRQ_LSC_IDX].vector);
nfp_net_read_link_status(nn);
}
static int nfp_net_netdev_open(struct net_device *netdev)
{
struct nfp_net *nn = netdev_priv(netdev);
int err, r;
if (nn->ctrl & NFP_NET_CFG_CTRL_ENABLE) {
nn_err(nn, "Dev is already enabled: 0x%08x\n", nn->ctrl);
return -EBUSY;
}
err = nfp_net_aux_irq_request(nn, NFP_NET_CFG_EXN, "%s-exn",
nn->exn_name, sizeof(nn->exn_name),
NFP_NET_IRQ_EXN_IDX, nn->exn_handler);
if (err)
return err;
err = nfp_net_aux_irq_request(nn, NFP_NET_CFG_LSC, "%s-lsc",
nn->lsc_name, sizeof(nn->lsc_name),
NFP_NET_IRQ_LSC_IDX, nn->lsc_handler);
if (err)
goto err_free_exn;
disable_irq(nn->irq_entries[NFP_NET_IRQ_LSC_IDX].vector);
nn->rx_rings = kcalloc(nn->num_rx_rings, sizeof(*nn->rx_rings),
GFP_KERNEL);
if (!nn->rx_rings) {
err = -ENOMEM;
goto err_free_lsc;
}
nn->tx_rings = kcalloc(nn->num_tx_rings, sizeof(*nn->tx_rings),
GFP_KERNEL);
if (!nn->tx_rings) {
err = -ENOMEM;
goto err_free_rx_rings;
}
for (r = 0; r < nn->num_r_vecs; r++) {
err = nfp_net_prepare_vector(nn, &nn->r_vecs[r], r);
if (err)
goto err_free_prev_vecs;
err = nfp_net_tx_ring_alloc(nn->r_vecs[r].tx_ring, nn->txd_cnt);
if (err)
goto err_cleanup_vec_p;
err = nfp_net_rx_ring_alloc(nn->r_vecs[r].rx_ring,
nn->fl_bufsz, nn->rxd_cnt);
if (err)
goto err_free_tx_ring_p;
err = nfp_net_rx_ring_bufs_alloc(nn, nn->r_vecs[r].rx_ring);
if (err)
goto err_flush_rx_ring_p;
}
err = netif_set_real_num_tx_queues(netdev, nn->num_tx_rings);
if (err)
goto err_free_rings;
err = netif_set_real_num_rx_queues(netdev, nn->num_rx_rings);
if (err)
goto err_free_rings;
err = nfp_net_set_config_and_enable(nn);
if (err)
goto err_free_rings;
nfp_net_open_stack(nn);
return 0;
err_free_rings:
r = nn->num_r_vecs;
err_free_prev_vecs:
while (r--) {
nfp_net_rx_ring_bufs_free(nn, nn->r_vecs[r].rx_ring);
err_flush_rx_ring_p:
nfp_net_rx_ring_free(nn->r_vecs[r].rx_ring);
err_free_tx_ring_p:
nfp_net_tx_ring_free(nn->r_vecs[r].tx_ring);
err_cleanup_vec_p:
nfp_net_cleanup_vector(nn, &nn->r_vecs[r]);
}
kfree(nn->tx_rings);
err_free_rx_rings:
kfree(nn->rx_rings);
err_free_lsc:
nfp_net_aux_irq_free(nn, NFP_NET_CFG_LSC, NFP_NET_IRQ_LSC_IDX);
err_free_exn:
nfp_net_aux_irq_free(nn, NFP_NET_CFG_EXN, NFP_NET_IRQ_EXN_IDX);
return err;
}
static void nfp_net_close_stack(struct nfp_net *nn)
{
unsigned int r;
disable_irq(nn->irq_entries[NFP_NET_IRQ_LSC_IDX].vector);
netif_carrier_off(nn->netdev);
nn->link_up = false;
for (r = 0; r < nn->num_r_vecs; r++) {
disable_irq(nn->irq_entries[nn->r_vecs[r].irq_idx].vector);
napi_disable(&nn->r_vecs[r].napi);
}
netif_tx_disable(nn->netdev);
}
static void nfp_net_close_free_all(struct nfp_net *nn)
{
unsigned int r;
for (r = 0; r < nn->num_r_vecs; r++) {
nfp_net_rx_ring_bufs_free(nn, nn->r_vecs[r].rx_ring);
nfp_net_rx_ring_free(nn->r_vecs[r].rx_ring);
nfp_net_tx_ring_free(nn->r_vecs[r].tx_ring);
nfp_net_cleanup_vector(nn, &nn->r_vecs[r]);
}
kfree(nn->rx_rings);
kfree(nn->tx_rings);
nfp_net_aux_irq_free(nn, NFP_NET_CFG_LSC, NFP_NET_IRQ_LSC_IDX);
nfp_net_aux_irq_free(nn, NFP_NET_CFG_EXN, NFP_NET_IRQ_EXN_IDX);
}
static int nfp_net_netdev_close(struct net_device *netdev)
{
struct nfp_net *nn = netdev_priv(netdev);
if (!(nn->ctrl & NFP_NET_CFG_CTRL_ENABLE)) {
nn_err(nn, "Dev is not up: 0x%08x\n", nn->ctrl);
return 0;
}
nfp_net_close_stack(nn);
nfp_net_clear_config_and_disable(nn);
nfp_net_close_free_all(nn);
nn_dbg(nn, "%s down", netdev->name);
return 0;
}
static void nfp_net_set_rx_mode(struct net_device *netdev)
{
struct nfp_net *nn = netdev_priv(netdev);
u32 new_ctrl;
new_ctrl = nn->ctrl;
if (netdev->flags & IFF_PROMISC) {
if (nn->cap & NFP_NET_CFG_CTRL_PROMISC)
new_ctrl |= NFP_NET_CFG_CTRL_PROMISC;
else
nn_warn(nn, "FW does not support promiscuous mode\n");
} else {
new_ctrl &= ~NFP_NET_CFG_CTRL_PROMISC;
}
if (new_ctrl == nn->ctrl)
return;
nn_writel(nn, NFP_NET_CFG_CTRL, new_ctrl);
nfp_net_reconfig_post(nn, NFP_NET_CFG_UPDATE_GEN);
nn->ctrl = new_ctrl;
}
static int nfp_net_change_mtu(struct net_device *netdev, int new_mtu)
{
unsigned int old_mtu, old_fl_bufsz, new_fl_bufsz;
struct nfp_net *nn = netdev_priv(netdev);
struct nfp_net_rx_ring *tmp_rings;
int err;
if (new_mtu < 68 || new_mtu > nn->max_mtu) {
nn_err(nn, "New MTU (%d) is not valid\n", new_mtu);
return -EINVAL;
}
old_mtu = netdev->mtu;
old_fl_bufsz = nn->fl_bufsz;
new_fl_bufsz = NFP_NET_MAX_PREPEND + ETH_HLEN + VLAN_HLEN * 2 + new_mtu;
if (!netif_running(netdev)) {
netdev->mtu = new_mtu;
nn->fl_bufsz = new_fl_bufsz;
return 0;
}
tmp_rings = nfp_net_shadow_rx_rings_prepare(nn, new_fl_bufsz,
nn->rxd_cnt);
if (!tmp_rings)
return -ENOMEM;
nfp_net_close_stack(nn);
nfp_net_clear_config_and_disable(nn);
tmp_rings = nfp_net_shadow_rx_rings_swap(nn, tmp_rings);
netdev->mtu = new_mtu;
nn->fl_bufsz = new_fl_bufsz;
err = nfp_net_set_config_and_enable(nn);
if (err) {
const int err_new = err;
tmp_rings = nfp_net_shadow_rx_rings_swap(nn, tmp_rings);
netdev->mtu = old_mtu;
nn->fl_bufsz = old_fl_bufsz;
err = __nfp_net_set_config_and_enable(nn);
if (err)
nn_err(nn, "Can't restore MTU - FW communication failed (%d,%d)\n",
err_new, err);
}
nfp_net_shadow_rx_rings_free(nn, tmp_rings);
nfp_net_open_stack(nn);
return err;
}
int nfp_net_set_ring_size(struct nfp_net *nn, u32 rxd_cnt, u32 txd_cnt)
{
struct nfp_net_tx_ring *tx_rings = NULL;
struct nfp_net_rx_ring *rx_rings = NULL;
u32 old_rxd_cnt, old_txd_cnt;
int err;
if (!netif_running(nn->netdev)) {
nn->rxd_cnt = rxd_cnt;
nn->txd_cnt = txd_cnt;
return 0;
}
old_rxd_cnt = nn->rxd_cnt;
old_txd_cnt = nn->txd_cnt;
if (nn->rxd_cnt != rxd_cnt) {
rx_rings = nfp_net_shadow_rx_rings_prepare(nn, nn->fl_bufsz,
rxd_cnt);
if (!rx_rings)
return -ENOMEM;
}
if (nn->txd_cnt != txd_cnt) {
tx_rings = nfp_net_shadow_tx_rings_prepare(nn, txd_cnt);
if (!tx_rings) {
nfp_net_shadow_rx_rings_free(nn, rx_rings);
return -ENOMEM;
}
}
nfp_net_close_stack(nn);
nfp_net_clear_config_and_disable(nn);
if (rx_rings)
rx_rings = nfp_net_shadow_rx_rings_swap(nn, rx_rings);
if (tx_rings)
tx_rings = nfp_net_shadow_tx_rings_swap(nn, tx_rings);
nn->rxd_cnt = rxd_cnt;
nn->txd_cnt = txd_cnt;
err = nfp_net_set_config_and_enable(nn);
if (err) {
const int err_new = err;
if (rx_rings)
rx_rings = nfp_net_shadow_rx_rings_swap(nn, rx_rings);
if (tx_rings)
tx_rings = nfp_net_shadow_tx_rings_swap(nn, tx_rings);
nn->rxd_cnt = old_rxd_cnt;
nn->txd_cnt = old_txd_cnt;
err = __nfp_net_set_config_and_enable(nn);
if (err)
nn_err(nn, "Can't restore ring config - FW communication failed (%d,%d)\n",
err_new, err);
}
nfp_net_shadow_rx_rings_free(nn, rx_rings);
nfp_net_shadow_tx_rings_free(nn, tx_rings);
nfp_net_open_stack(nn);
return err;
}
static struct rtnl_link_stats64 *nfp_net_stat64(struct net_device *netdev,
struct rtnl_link_stats64 *stats)
{
struct nfp_net *nn = netdev_priv(netdev);
int r;
for (r = 0; r < nn->num_r_vecs; r++) {
struct nfp_net_r_vector *r_vec = &nn->r_vecs[r];
u64 data[3];
unsigned int start;
do {
start = u64_stats_fetch_begin(&r_vec->rx_sync);
data[0] = r_vec->rx_pkts;
data[1] = r_vec->rx_bytes;
data[2] = r_vec->rx_drops;
} while (u64_stats_fetch_retry(&r_vec->rx_sync, start));
stats->rx_packets += data[0];
stats->rx_bytes += data[1];
stats->rx_dropped += data[2];
do {
start = u64_stats_fetch_begin(&r_vec->tx_sync);
data[0] = r_vec->tx_pkts;
data[1] = r_vec->tx_bytes;
data[2] = r_vec->tx_errors;
} while (u64_stats_fetch_retry(&r_vec->tx_sync, start));
stats->tx_packets += data[0];
stats->tx_bytes += data[1];
stats->tx_errors += data[2];
}
return stats;
}
static int nfp_net_set_features(struct net_device *netdev,
netdev_features_t features)
{
netdev_features_t changed = netdev->features ^ features;
struct nfp_net *nn = netdev_priv(netdev);
u32 new_ctrl;
int err;
new_ctrl = nn->ctrl;
if (changed & NETIF_F_RXCSUM) {
if (features & NETIF_F_RXCSUM)
new_ctrl |= NFP_NET_CFG_CTRL_RXCSUM;
else
new_ctrl &= ~NFP_NET_CFG_CTRL_RXCSUM;
}
if (changed & (NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM)) {
if (features & (NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM))
new_ctrl |= NFP_NET_CFG_CTRL_TXCSUM;
else
new_ctrl &= ~NFP_NET_CFG_CTRL_TXCSUM;
}
if (changed & (NETIF_F_TSO | NETIF_F_TSO6)) {
if (features & (NETIF_F_TSO | NETIF_F_TSO6))
new_ctrl |= NFP_NET_CFG_CTRL_LSO;
else
new_ctrl &= ~NFP_NET_CFG_CTRL_LSO;
}
if (changed & NETIF_F_HW_VLAN_CTAG_RX) {
if (features & NETIF_F_HW_VLAN_CTAG_RX)
new_ctrl |= NFP_NET_CFG_CTRL_RXVLAN;
else
new_ctrl &= ~NFP_NET_CFG_CTRL_RXVLAN;
}
if (changed & NETIF_F_HW_VLAN_CTAG_TX) {
if (features & NETIF_F_HW_VLAN_CTAG_TX)
new_ctrl |= NFP_NET_CFG_CTRL_TXVLAN;
else
new_ctrl &= ~NFP_NET_CFG_CTRL_TXVLAN;
}
if (changed & NETIF_F_SG) {
if (features & NETIF_F_SG)
new_ctrl |= NFP_NET_CFG_CTRL_GATHER;
else
new_ctrl &= ~NFP_NET_CFG_CTRL_GATHER;
}
nn_dbg(nn, "Feature change 0x%llx -> 0x%llx (changed=0x%llx)\n",
netdev->features, features, changed);
if (new_ctrl == nn->ctrl)
return 0;
nn_dbg(nn, "NIC ctrl: 0x%x -> 0x%x\n", nn->ctrl, new_ctrl);
nn_writel(nn, NFP_NET_CFG_CTRL, new_ctrl);
err = nfp_net_reconfig(nn, NFP_NET_CFG_UPDATE_GEN);
if (err)
return err;
nn->ctrl = new_ctrl;
return 0;
}
static netdev_features_t
nfp_net_features_check(struct sk_buff *skb, struct net_device *dev,
netdev_features_t features)
{
u8 l4_hdr;
features &= vlan_features_check(skb, features);
if (!skb->encapsulation)
return features;
if (skb_is_gso(skb)) {
u32 hdrlen;
hdrlen = skb_inner_transport_header(skb) - skb->data +
inner_tcp_hdrlen(skb);
if (unlikely(hdrlen > NFP_NET_LSO_MAX_HDR_SZ))
features &= ~NETIF_F_GSO_MASK;
}
switch (vlan_get_protocol(skb)) {
case htons(ETH_P_IP):
l4_hdr = ip_hdr(skb)->protocol;
break;
case htons(ETH_P_IPV6):
l4_hdr = ipv6_hdr(skb)->nexthdr;
break;
default:
return features & ~(NETIF_F_CSUM_MASK | NETIF_F_GSO_MASK);
}
if (skb->inner_protocol_type != ENCAP_TYPE_ETHER ||
skb->inner_protocol != htons(ETH_P_TEB) ||
(l4_hdr != IPPROTO_UDP && l4_hdr != IPPROTO_GRE) ||
(l4_hdr == IPPROTO_UDP &&
(skb_inner_mac_header(skb) - skb_transport_header(skb) !=
sizeof(struct udphdr) + sizeof(struct vxlanhdr))))
return features & ~(NETIF_F_CSUM_MASK | NETIF_F_GSO_MASK);
return features;
}
static void nfp_net_set_vxlan_port(struct nfp_net *nn, int idx, __be16 port)
{
int i;
nn->vxlan_ports[idx] = port;
if (!(nn->ctrl & NFP_NET_CFG_CTRL_VXLAN))
return;
BUILD_BUG_ON(NFP_NET_N_VXLAN_PORTS & 1);
for (i = 0; i < NFP_NET_N_VXLAN_PORTS; i += 2)
nn_writel(nn, NFP_NET_CFG_VXLAN_PORT + i * sizeof(port),
be16_to_cpu(nn->vxlan_ports[i + 1]) << 16 |
be16_to_cpu(nn->vxlan_ports[i]));
nfp_net_reconfig_post(nn, NFP_NET_CFG_UPDATE_VXLAN);
}
static int nfp_net_find_vxlan_idx(struct nfp_net *nn, __be16 port)
{
int i, free_idx = -ENOSPC;
for (i = 0; i < NFP_NET_N_VXLAN_PORTS; i++) {
if (nn->vxlan_ports[i] == port)
return i;
if (!nn->vxlan_usecnt[i])
free_idx = i;
}
return free_idx;
}
static void nfp_net_add_vxlan_port(struct net_device *netdev,
struct udp_tunnel_info *ti)
{
struct nfp_net *nn = netdev_priv(netdev);
int idx;
if (ti->type != UDP_TUNNEL_TYPE_VXLAN)
return;
idx = nfp_net_find_vxlan_idx(nn, ti->port);
if (idx == -ENOSPC)
return;
if (!nn->vxlan_usecnt[idx]++)
nfp_net_set_vxlan_port(nn, idx, ti->port);
}
static void nfp_net_del_vxlan_port(struct net_device *netdev,
struct udp_tunnel_info *ti)
{
struct nfp_net *nn = netdev_priv(netdev);
int idx;
if (ti->type != UDP_TUNNEL_TYPE_VXLAN)
return;
idx = nfp_net_find_vxlan_idx(nn, ti->port);
if (idx == -ENOSPC || !nn->vxlan_usecnt[idx])
return;
if (!--nn->vxlan_usecnt[idx])
nfp_net_set_vxlan_port(nn, idx, 0);
}
void nfp_net_info(struct nfp_net *nn)
{
nn_info(nn, "Netronome %s %sNetdev: TxQs=%d/%d RxQs=%d/%d\n",
nn->is_nfp3200 ? "NFP-32xx" : "NFP-6xxx",
nn->is_vf ? "VF " : "",
nn->num_tx_rings, nn->max_tx_rings,
nn->num_rx_rings, nn->max_rx_rings);
nn_info(nn, "VER: %d.%d.%d.%d, Maximum supported MTU: %d\n",
nn->fw_ver.resv, nn->fw_ver.class,
nn->fw_ver.major, nn->fw_ver.minor,
nn->max_mtu);
nn_info(nn, "CAP: %#x %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s\n",
nn->cap,
nn->cap & NFP_NET_CFG_CTRL_PROMISC ? "PROMISC " : "",
nn->cap & NFP_NET_CFG_CTRL_L2BC ? "L2BCFILT " : "",
nn->cap & NFP_NET_CFG_CTRL_L2MC ? "L2MCFILT " : "",
nn->cap & NFP_NET_CFG_CTRL_RXCSUM ? "RXCSUM " : "",
nn->cap & NFP_NET_CFG_CTRL_TXCSUM ? "TXCSUM " : "",
nn->cap & NFP_NET_CFG_CTRL_RXVLAN ? "RXVLAN " : "",
nn->cap & NFP_NET_CFG_CTRL_TXVLAN ? "TXVLAN " : "",
nn->cap & NFP_NET_CFG_CTRL_SCATTER ? "SCATTER " : "",
nn->cap & NFP_NET_CFG_CTRL_GATHER ? "GATHER " : "",
nn->cap & NFP_NET_CFG_CTRL_LSO ? "TSO " : "",
nn->cap & NFP_NET_CFG_CTRL_RSS ? "RSS " : "",
nn->cap & NFP_NET_CFG_CTRL_L2SWITCH ? "L2SWITCH " : "",
nn->cap & NFP_NET_CFG_CTRL_MSIXAUTO ? "AUTOMASK " : "",
nn->cap & NFP_NET_CFG_CTRL_IRQMOD ? "IRQMOD " : "",
nn->cap & NFP_NET_CFG_CTRL_VXLAN ? "VXLAN " : "",
nn->cap & NFP_NET_CFG_CTRL_NVGRE ? "NVGRE " : "");
}
struct nfp_net *nfp_net_netdev_alloc(struct pci_dev *pdev,
int max_tx_rings, int max_rx_rings)
{
struct net_device *netdev;
struct nfp_net *nn;
int nqs;
netdev = alloc_etherdev_mqs(sizeof(struct nfp_net),
max_tx_rings, max_rx_rings);
if (!netdev)
return ERR_PTR(-ENOMEM);
SET_NETDEV_DEV(netdev, &pdev->dev);
nn = netdev_priv(netdev);
nn->netdev = netdev;
nn->pdev = pdev;
nn->max_tx_rings = max_tx_rings;
nn->max_rx_rings = max_rx_rings;
nqs = netif_get_num_default_rss_queues();
nn->num_tx_rings = min_t(int, nqs, max_tx_rings);
nn->num_rx_rings = min_t(int, nqs, max_rx_rings);
nn->txd_cnt = NFP_NET_TX_DESCS_DEFAULT;
nn->rxd_cnt = NFP_NET_RX_DESCS_DEFAULT;
spin_lock_init(&nn->reconfig_lock);
spin_lock_init(&nn->link_status_lock);
setup_timer(&nn->reconfig_timer,
nfp_net_reconfig_timer, (unsigned long)nn);
return nn;
}
void nfp_net_netdev_free(struct nfp_net *nn)
{
free_netdev(nn->netdev);
}
static void nfp_net_rss_init(struct nfp_net *nn)
{
int i;
netdev_rss_key_fill(nn->rss_key, NFP_NET_CFG_RSS_KEY_SZ);
for (i = 0; i < sizeof(nn->rss_itbl); i++)
nn->rss_itbl[i] =
ethtool_rxfh_indir_default(i, nn->num_rx_rings);
nn->rss_cfg = NFP_NET_CFG_RSS_IPV4_TCP |
NFP_NET_CFG_RSS_IPV6_TCP |
NFP_NET_CFG_RSS_TOEPLITZ |
NFP_NET_CFG_RSS_MASK;
}
static void nfp_net_irqmod_init(struct nfp_net *nn)
{
nn->rx_coalesce_usecs = 50;
nn->rx_coalesce_max_frames = 64;
nn->tx_coalesce_usecs = 50;
nn->tx_coalesce_max_frames = 64;
}
int nfp_net_netdev_init(struct net_device *netdev)
{
struct nfp_net *nn = netdev_priv(netdev);
int err;
nn->cap = nn_readl(nn, NFP_NET_CFG_CAP);
nn->max_mtu = nn_readl(nn, NFP_NET_CFG_MAX_MTU);
nfp_net_write_mac_addr(nn);
if (nn->max_mtu < NFP_NET_DEFAULT_MTU)
netdev->mtu = nn->max_mtu;
else
netdev->mtu = NFP_NET_DEFAULT_MTU;
nn->fl_bufsz = NFP_NET_DEFAULT_RX_BUFSZ;
netdev->hw_features = NETIF_F_HIGHDMA;
if (nn->cap & NFP_NET_CFG_CTRL_RXCSUM) {
netdev->hw_features |= NETIF_F_RXCSUM;
nn->ctrl |= NFP_NET_CFG_CTRL_RXCSUM;
}
if (nn->cap & NFP_NET_CFG_CTRL_TXCSUM) {
netdev->hw_features |= NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM;
nn->ctrl |= NFP_NET_CFG_CTRL_TXCSUM;
}
if (nn->cap & NFP_NET_CFG_CTRL_GATHER) {
netdev->hw_features |= NETIF_F_SG;
nn->ctrl |= NFP_NET_CFG_CTRL_GATHER;
}
if ((nn->cap & NFP_NET_CFG_CTRL_LSO) && nn->fw_ver.major > 2) {
netdev->hw_features |= NETIF_F_TSO | NETIF_F_TSO6;
nn->ctrl |= NFP_NET_CFG_CTRL_LSO;
}
if (nn->cap & NFP_NET_CFG_CTRL_RSS) {
netdev->hw_features |= NETIF_F_RXHASH;
nfp_net_rss_init(nn);
nn->ctrl |= NFP_NET_CFG_CTRL_RSS;
}
if (nn->cap & NFP_NET_CFG_CTRL_VXLAN &&
nn->cap & NFP_NET_CFG_CTRL_NVGRE) {
if (nn->cap & NFP_NET_CFG_CTRL_LSO)
netdev->hw_features |= NETIF_F_GSO_GRE |
NETIF_F_GSO_UDP_TUNNEL;
nn->ctrl |= NFP_NET_CFG_CTRL_VXLAN | NFP_NET_CFG_CTRL_NVGRE;
netdev->hw_enc_features = netdev->hw_features;
}
netdev->vlan_features = netdev->hw_features;
if (nn->cap & NFP_NET_CFG_CTRL_RXVLAN) {
netdev->hw_features |= NETIF_F_HW_VLAN_CTAG_RX;
nn->ctrl |= NFP_NET_CFG_CTRL_RXVLAN;
}
if (nn->cap & NFP_NET_CFG_CTRL_TXVLAN) {
netdev->hw_features |= NETIF_F_HW_VLAN_CTAG_TX;
nn->ctrl |= NFP_NET_CFG_CTRL_TXVLAN;
}
netdev->features = netdev->hw_features;
netdev->features &= ~(NETIF_F_TSO | NETIF_F_TSO6);
if (nn->cap & NFP_NET_CFG_CTRL_L2BC)
nn->ctrl |= NFP_NET_CFG_CTRL_L2BC;
if (nn->cap & NFP_NET_CFG_CTRL_L2MC)
nn->ctrl |= NFP_NET_CFG_CTRL_L2MC;
if (nn->cap & NFP_NET_CFG_CTRL_IRQMOD) {
nfp_net_irqmod_init(nn);
nn->ctrl |= NFP_NET_CFG_CTRL_IRQMOD;
}
if (nn->is_nfp3200 && nn->cap & NFP_NET_CFG_CTRL_MSIXAUTO)
nn->ctrl |= NFP_NET_CFG_CTRL_MSIXAUTO;
if (nn->fw_ver.major >= 2)
nn->rx_offset = nn_readl(nn, NFP_NET_CFG_RX_OFFSET);
else
nn->rx_offset = NFP_NET_RX_OFFSET;
nn->qcp_cfg = nn->tx_bar + NFP_QCP_QUEUE_ADDR_SZ;
nn_writel(nn, NFP_NET_CFG_CTRL, 0);
nn_writeq(nn, NFP_NET_CFG_TXRS_ENABLE, 0);
nn_writeq(nn, NFP_NET_CFG_RXRS_ENABLE, 0);
err = nfp_net_reconfig(nn, NFP_NET_CFG_UPDATE_RING |
NFP_NET_CFG_UPDATE_GEN);
if (err)
return err;
ether_setup(netdev);
netdev->netdev_ops = &nfp_net_netdev_ops;
netdev->watchdog_timeo = msecs_to_jiffies(5 * 1000);
netif_carrier_off(netdev);
nfp_net_set_ethtool_ops(netdev);
nfp_net_irqs_assign(netdev);
return register_netdev(netdev);
}
void nfp_net_netdev_clean(struct net_device *netdev)
{
unregister_netdev(netdev);
}
