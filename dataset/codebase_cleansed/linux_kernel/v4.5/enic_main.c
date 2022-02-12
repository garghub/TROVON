static void enic_init_affinity_hint(struct enic *enic)
{
int numa_node = dev_to_node(&enic->pdev->dev);
int i;
for (i = 0; i < enic->intr_count; i++) {
if (enic_is_err_intr(enic, i) || enic_is_notify_intr(enic, i) ||
(enic->msix[i].affinity_mask &&
!cpumask_empty(enic->msix[i].affinity_mask)))
continue;
if (zalloc_cpumask_var(&enic->msix[i].affinity_mask,
GFP_KERNEL))
cpumask_set_cpu(cpumask_local_spread(i, numa_node),
enic->msix[i].affinity_mask);
}
}
static void enic_free_affinity_hint(struct enic *enic)
{
int i;
for (i = 0; i < enic->intr_count; i++) {
if (enic_is_err_intr(enic, i) || enic_is_notify_intr(enic, i))
continue;
free_cpumask_var(enic->msix[i].affinity_mask);
}
}
static void enic_set_affinity_hint(struct enic *enic)
{
int i;
int err;
for (i = 0; i < enic->intr_count; i++) {
if (enic_is_err_intr(enic, i) ||
enic_is_notify_intr(enic, i) ||
!enic->msix[i].affinity_mask ||
cpumask_empty(enic->msix[i].affinity_mask))
continue;
err = irq_set_affinity_hint(enic->msix_entry[i].vector,
enic->msix[i].affinity_mask);
if (err)
netdev_warn(enic->netdev, "irq_set_affinity_hint failed, err %d\n",
err);
}
for (i = 0; i < enic->wq_count; i++) {
int wq_intr = enic_msix_wq_intr(enic, i);
if (enic->msix[wq_intr].affinity_mask &&
!cpumask_empty(enic->msix[wq_intr].affinity_mask))
netif_set_xps_queue(enic->netdev,
enic->msix[wq_intr].affinity_mask,
i);
}
}
static void enic_unset_affinity_hint(struct enic *enic)
{
int i;
for (i = 0; i < enic->intr_count; i++)
irq_set_affinity_hint(enic->msix_entry[i].vector, NULL);
}
int enic_is_dynamic(struct enic *enic)
{
return enic->pdev->device == PCI_DEVICE_ID_CISCO_VIC_ENET_DYN;
}
int enic_sriov_enabled(struct enic *enic)
{
return (enic->priv_flags & ENIC_SRIOV_ENABLED) ? 1 : 0;
}
static int enic_is_sriov_vf(struct enic *enic)
{
return enic->pdev->device == PCI_DEVICE_ID_CISCO_VIC_ENET_VF;
}
int enic_is_valid_vf(struct enic *enic, int vf)
{
#ifdef CONFIG_PCI_IOV
return vf >= 0 && vf < enic->num_vfs;
#else
return 0;
#endif
}
static void enic_free_wq_buf(struct vnic_wq *wq, struct vnic_wq_buf *buf)
{
struct enic *enic = vnic_dev_priv(wq->vdev);
if (buf->sop)
pci_unmap_single(enic->pdev, buf->dma_addr,
buf->len, PCI_DMA_TODEVICE);
else
pci_unmap_page(enic->pdev, buf->dma_addr,
buf->len, PCI_DMA_TODEVICE);
if (buf->os_buf)
dev_kfree_skb_any(buf->os_buf);
}
static void enic_wq_free_buf(struct vnic_wq *wq,
struct cq_desc *cq_desc, struct vnic_wq_buf *buf, void *opaque)
{
enic_free_wq_buf(wq, buf);
}
static int enic_wq_service(struct vnic_dev *vdev, struct cq_desc *cq_desc,
u8 type, u16 q_number, u16 completed_index, void *opaque)
{
struct enic *enic = vnic_dev_priv(vdev);
spin_lock(&enic->wq_lock[q_number]);
vnic_wq_service(&enic->wq[q_number], cq_desc,
completed_index, enic_wq_free_buf,
opaque);
if (netif_tx_queue_stopped(netdev_get_tx_queue(enic->netdev, q_number)) &&
vnic_wq_desc_avail(&enic->wq[q_number]) >=
(MAX_SKB_FRAGS + ENIC_DESC_MAX_SPLITS))
netif_wake_subqueue(enic->netdev, q_number);
spin_unlock(&enic->wq_lock[q_number]);
return 0;
}
static bool enic_log_q_error(struct enic *enic)
{
unsigned int i;
u32 error_status;
bool err = false;
for (i = 0; i < enic->wq_count; i++) {
error_status = vnic_wq_error_status(&enic->wq[i]);
err |= error_status;
if (error_status)
netdev_err(enic->netdev, "WQ[%d] error_status %d\n",
i, error_status);
}
for (i = 0; i < enic->rq_count; i++) {
error_status = vnic_rq_error_status(&enic->rq[i]);
err |= error_status;
if (error_status)
netdev_err(enic->netdev, "RQ[%d] error_status %d\n",
i, error_status);
}
return err;
}
static void enic_msglvl_check(struct enic *enic)
{
u32 msg_enable = vnic_dev_msg_lvl(enic->vdev);
if (msg_enable != enic->msg_enable) {
netdev_info(enic->netdev, "msg lvl changed from 0x%x to 0x%x\n",
enic->msg_enable, msg_enable);
enic->msg_enable = msg_enable;
}
}
static void enic_mtu_check(struct enic *enic)
{
u32 mtu = vnic_dev_mtu(enic->vdev);
struct net_device *netdev = enic->netdev;
if (mtu && mtu != enic->port_mtu) {
enic->port_mtu = mtu;
if (enic_is_dynamic(enic) || enic_is_sriov_vf(enic)) {
mtu = max_t(int, ENIC_MIN_MTU,
min_t(int, ENIC_MAX_MTU, mtu));
if (mtu != netdev->mtu)
schedule_work(&enic->change_mtu_work);
} else {
if (mtu < netdev->mtu)
netdev_warn(netdev,
"interface MTU (%d) set higher "
"than switch port MTU (%d)\n",
netdev->mtu, mtu);
}
}
}
static void enic_link_check(struct enic *enic)
{
int link_status = vnic_dev_link_status(enic->vdev);
int carrier_ok = netif_carrier_ok(enic->netdev);
if (link_status && !carrier_ok) {
netdev_info(enic->netdev, "Link UP\n");
netif_carrier_on(enic->netdev);
} else if (!link_status && carrier_ok) {
netdev_info(enic->netdev, "Link DOWN\n");
netif_carrier_off(enic->netdev);
}
}
static void enic_notify_check(struct enic *enic)
{
enic_msglvl_check(enic);
enic_mtu_check(enic);
enic_link_check(enic);
}
static irqreturn_t enic_isr_legacy(int irq, void *data)
{
struct net_device *netdev = data;
struct enic *enic = netdev_priv(netdev);
unsigned int io_intr = enic_legacy_io_intr();
unsigned int err_intr = enic_legacy_err_intr();
unsigned int notify_intr = enic_legacy_notify_intr();
u32 pba;
vnic_intr_mask(&enic->intr[io_intr]);
pba = vnic_intr_legacy_pba(enic->legacy_pba);
if (!pba) {
vnic_intr_unmask(&enic->intr[io_intr]);
return IRQ_NONE;
}
if (ENIC_TEST_INTR(pba, notify_intr)) {
enic_notify_check(enic);
vnic_intr_return_all_credits(&enic->intr[notify_intr]);
}
if (ENIC_TEST_INTR(pba, err_intr)) {
vnic_intr_return_all_credits(&enic->intr[err_intr]);
enic_log_q_error(enic);
schedule_work(&enic->reset);
return IRQ_HANDLED;
}
if (ENIC_TEST_INTR(pba, io_intr))
napi_schedule_irqoff(&enic->napi[0]);
else
vnic_intr_unmask(&enic->intr[io_intr]);
return IRQ_HANDLED;
}
static irqreturn_t enic_isr_msi(int irq, void *data)
{
struct enic *enic = data;
napi_schedule_irqoff(&enic->napi[0]);
return IRQ_HANDLED;
}
static irqreturn_t enic_isr_msix(int irq, void *data)
{
struct napi_struct *napi = data;
napi_schedule_irqoff(napi);
return IRQ_HANDLED;
}
static irqreturn_t enic_isr_msix_err(int irq, void *data)
{
struct enic *enic = data;
unsigned int intr = enic_msix_err_intr(enic);
vnic_intr_return_all_credits(&enic->intr[intr]);
if (enic_log_q_error(enic))
schedule_work(&enic->reset);
return IRQ_HANDLED;
}
static irqreturn_t enic_isr_msix_notify(int irq, void *data)
{
struct enic *enic = data;
unsigned int intr = enic_msix_notify_intr(enic);
enic_notify_check(enic);
vnic_intr_return_all_credits(&enic->intr[intr]);
return IRQ_HANDLED;
}
static int enic_queue_wq_skb_cont(struct enic *enic, struct vnic_wq *wq,
struct sk_buff *skb, unsigned int len_left,
int loopback)
{
const skb_frag_t *frag;
dma_addr_t dma_addr;
for (frag = skb_shinfo(skb)->frags; len_left; frag++) {
len_left -= skb_frag_size(frag);
dma_addr = skb_frag_dma_map(&enic->pdev->dev, frag, 0,
skb_frag_size(frag),
DMA_TO_DEVICE);
if (unlikely(enic_dma_map_check(enic, dma_addr)))
return -ENOMEM;
enic_queue_wq_desc_cont(wq, skb, dma_addr, skb_frag_size(frag),
(len_left == 0),
loopback);
}
return 0;
}
static int enic_queue_wq_skb_vlan(struct enic *enic, struct vnic_wq *wq,
struct sk_buff *skb, int vlan_tag_insert,
unsigned int vlan_tag, int loopback)
{
unsigned int head_len = skb_headlen(skb);
unsigned int len_left = skb->len - head_len;
int eop = (len_left == 0);
dma_addr_t dma_addr;
int err = 0;
dma_addr = pci_map_single(enic->pdev, skb->data, head_len,
PCI_DMA_TODEVICE);
if (unlikely(enic_dma_map_check(enic, dma_addr)))
return -ENOMEM;
enic_queue_wq_desc(wq, skb, dma_addr, head_len, vlan_tag_insert,
vlan_tag, eop, loopback);
if (!eop)
err = enic_queue_wq_skb_cont(enic, wq, skb, len_left, loopback);
return err;
}
static int enic_queue_wq_skb_csum_l4(struct enic *enic, struct vnic_wq *wq,
struct sk_buff *skb, int vlan_tag_insert,
unsigned int vlan_tag, int loopback)
{
unsigned int head_len = skb_headlen(skb);
unsigned int len_left = skb->len - head_len;
unsigned int hdr_len = skb_checksum_start_offset(skb);
unsigned int csum_offset = hdr_len + skb->csum_offset;
int eop = (len_left == 0);
dma_addr_t dma_addr;
int err = 0;
dma_addr = pci_map_single(enic->pdev, skb->data, head_len,
PCI_DMA_TODEVICE);
if (unlikely(enic_dma_map_check(enic, dma_addr)))
return -ENOMEM;
enic_queue_wq_desc_csum_l4(wq, skb, dma_addr, head_len, csum_offset,
hdr_len, vlan_tag_insert, vlan_tag, eop,
loopback);
if (!eop)
err = enic_queue_wq_skb_cont(enic, wq, skb, len_left, loopback);
return err;
}
static int enic_queue_wq_skb_tso(struct enic *enic, struct vnic_wq *wq,
struct sk_buff *skb, unsigned int mss,
int vlan_tag_insert, unsigned int vlan_tag,
int loopback)
{
unsigned int frag_len_left = skb_headlen(skb);
unsigned int len_left = skb->len - frag_len_left;
unsigned int hdr_len = skb_transport_offset(skb) + tcp_hdrlen(skb);
int eop = (len_left == 0);
unsigned int len;
dma_addr_t dma_addr;
unsigned int offset = 0;
skb_frag_t *frag;
if (skb->protocol == cpu_to_be16(ETH_P_IP)) {
ip_hdr(skb)->check = 0;
tcp_hdr(skb)->check = ~csum_tcpudp_magic(ip_hdr(skb)->saddr,
ip_hdr(skb)->daddr, 0, IPPROTO_TCP, 0);
} else if (skb->protocol == cpu_to_be16(ETH_P_IPV6)) {
tcp_hdr(skb)->check = ~csum_ipv6_magic(&ipv6_hdr(skb)->saddr,
&ipv6_hdr(skb)->daddr, 0, IPPROTO_TCP, 0);
}
while (frag_len_left) {
len = min(frag_len_left, (unsigned int)WQ_ENET_MAX_DESC_LEN);
dma_addr = pci_map_single(enic->pdev, skb->data + offset, len,
PCI_DMA_TODEVICE);
if (unlikely(enic_dma_map_check(enic, dma_addr)))
return -ENOMEM;
enic_queue_wq_desc_tso(wq, skb, dma_addr, len, mss, hdr_len,
vlan_tag_insert, vlan_tag,
eop && (len == frag_len_left), loopback);
frag_len_left -= len;
offset += len;
}
if (eop)
return 0;
for (frag = skb_shinfo(skb)->frags; len_left; frag++) {
len_left -= skb_frag_size(frag);
frag_len_left = skb_frag_size(frag);
offset = 0;
while (frag_len_left) {
len = min(frag_len_left,
(unsigned int)WQ_ENET_MAX_DESC_LEN);
dma_addr = skb_frag_dma_map(&enic->pdev->dev, frag,
offset, len,
DMA_TO_DEVICE);
if (unlikely(enic_dma_map_check(enic, dma_addr)))
return -ENOMEM;
enic_queue_wq_desc_cont(wq, skb, dma_addr, len,
(len_left == 0) &&
(len == frag_len_left),
loopback);
frag_len_left -= len;
offset += len;
}
}
return 0;
}
static inline void enic_queue_wq_skb(struct enic *enic,
struct vnic_wq *wq, struct sk_buff *skb)
{
unsigned int mss = skb_shinfo(skb)->gso_size;
unsigned int vlan_tag = 0;
int vlan_tag_insert = 0;
int loopback = 0;
int err;
if (skb_vlan_tag_present(skb)) {
vlan_tag_insert = 1;
vlan_tag = skb_vlan_tag_get(skb);
} else if (enic->loop_enable) {
vlan_tag = enic->loop_tag;
loopback = 1;
}
if (mss)
err = enic_queue_wq_skb_tso(enic, wq, skb, mss,
vlan_tag_insert, vlan_tag,
loopback);
else if (skb->ip_summed == CHECKSUM_PARTIAL)
err = enic_queue_wq_skb_csum_l4(enic, wq, skb, vlan_tag_insert,
vlan_tag, loopback);
else
err = enic_queue_wq_skb_vlan(enic, wq, skb, vlan_tag_insert,
vlan_tag, loopback);
if (unlikely(err)) {
struct vnic_wq_buf *buf;
buf = wq->to_use->prev;
while (!buf->os_buf && (buf->next != wq->to_clean)) {
enic_free_wq_buf(wq, buf);
wq->ring.desc_avail++;
buf = buf->prev;
}
wq->to_use = buf->next;
dev_kfree_skb(skb);
}
}
static netdev_tx_t enic_hard_start_xmit(struct sk_buff *skb,
struct net_device *netdev)
{
struct enic *enic = netdev_priv(netdev);
struct vnic_wq *wq;
unsigned int txq_map;
struct netdev_queue *txq;
if (skb->len <= 0) {
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
txq_map = skb_get_queue_mapping(skb) % enic->wq_count;
wq = &enic->wq[txq_map];
txq = netdev_get_tx_queue(netdev, txq_map);
if (skb_shinfo(skb)->gso_size == 0 &&
skb_shinfo(skb)->nr_frags + 1 > ENIC_NON_TSO_MAX_DESC &&
skb_linearize(skb)) {
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
spin_lock(&enic->wq_lock[txq_map]);
if (vnic_wq_desc_avail(wq) <
skb_shinfo(skb)->nr_frags + ENIC_DESC_MAX_SPLITS) {
netif_tx_stop_queue(txq);
netdev_err(netdev, "BUG! Tx ring full when queue awake!\n");
spin_unlock(&enic->wq_lock[txq_map]);
return NETDEV_TX_BUSY;
}
enic_queue_wq_skb(enic, wq, skb);
if (vnic_wq_desc_avail(wq) < MAX_SKB_FRAGS + ENIC_DESC_MAX_SPLITS)
netif_tx_stop_queue(txq);
if (!skb->xmit_more || netif_xmit_stopped(txq))
vnic_wq_doorbell(wq);
spin_unlock(&enic->wq_lock[txq_map]);
return NETDEV_TX_OK;
}
static struct rtnl_link_stats64 *enic_get_stats(struct net_device *netdev,
struct rtnl_link_stats64 *net_stats)
{
struct enic *enic = netdev_priv(netdev);
struct vnic_stats *stats;
int err;
err = enic_dev_stats_dump(enic, &stats);
if (err == -ENOMEM)
return net_stats;
net_stats->tx_packets = stats->tx.tx_frames_ok;
net_stats->tx_bytes = stats->tx.tx_bytes_ok;
net_stats->tx_errors = stats->tx.tx_errors;
net_stats->tx_dropped = stats->tx.tx_drops;
net_stats->rx_packets = stats->rx.rx_frames_ok;
net_stats->rx_bytes = stats->rx.rx_bytes_ok;
net_stats->rx_errors = stats->rx.rx_errors;
net_stats->multicast = stats->rx.rx_multicast_frames_ok;
net_stats->rx_over_errors = enic->rq_truncated_pkts;
net_stats->rx_crc_errors = enic->rq_bad_fcs;
net_stats->rx_dropped = stats->rx.rx_no_bufs + stats->rx.rx_drop;
return net_stats;
}
static int enic_mc_sync(struct net_device *netdev, const u8 *mc_addr)
{
struct enic *enic = netdev_priv(netdev);
if (enic->mc_count == ENIC_MULTICAST_PERFECT_FILTERS) {
unsigned int mc_count = netdev_mc_count(netdev);
netdev_warn(netdev, "Registering only %d out of %d multicast addresses\n",
ENIC_MULTICAST_PERFECT_FILTERS, mc_count);
return -ENOSPC;
}
enic_dev_add_addr(enic, mc_addr);
enic->mc_count++;
return 0;
}
static int enic_mc_unsync(struct net_device *netdev, const u8 *mc_addr)
{
struct enic *enic = netdev_priv(netdev);
enic_dev_del_addr(enic, mc_addr);
enic->mc_count--;
return 0;
}
static int enic_uc_sync(struct net_device *netdev, const u8 *uc_addr)
{
struct enic *enic = netdev_priv(netdev);
if (enic->uc_count == ENIC_UNICAST_PERFECT_FILTERS) {
unsigned int uc_count = netdev_uc_count(netdev);
netdev_warn(netdev, "Registering only %d out of %d unicast addresses\n",
ENIC_UNICAST_PERFECT_FILTERS, uc_count);
return -ENOSPC;
}
enic_dev_add_addr(enic, uc_addr);
enic->uc_count++;
return 0;
}
static int enic_uc_unsync(struct net_device *netdev, const u8 *uc_addr)
{
struct enic *enic = netdev_priv(netdev);
enic_dev_del_addr(enic, uc_addr);
enic->uc_count--;
return 0;
}
void enic_reset_addr_lists(struct enic *enic)
{
struct net_device *netdev = enic->netdev;
__dev_uc_unsync(netdev, NULL);
__dev_mc_unsync(netdev, NULL);
enic->mc_count = 0;
enic->uc_count = 0;
enic->flags = 0;
}
static int enic_set_mac_addr(struct net_device *netdev, char *addr)
{
struct enic *enic = netdev_priv(netdev);
if (enic_is_dynamic(enic) || enic_is_sriov_vf(enic)) {
if (!is_valid_ether_addr(addr) && !is_zero_ether_addr(addr))
return -EADDRNOTAVAIL;
} else {
if (!is_valid_ether_addr(addr))
return -EADDRNOTAVAIL;
}
memcpy(netdev->dev_addr, addr, netdev->addr_len);
return 0;
}
static int enic_set_mac_address_dynamic(struct net_device *netdev, void *p)
{
struct enic *enic = netdev_priv(netdev);
struct sockaddr *saddr = p;
char *addr = saddr->sa_data;
int err;
if (netif_running(enic->netdev)) {
err = enic_dev_del_station_addr(enic);
if (err)
return err;
}
err = enic_set_mac_addr(netdev, addr);
if (err)
return err;
if (netif_running(enic->netdev)) {
err = enic_dev_add_station_addr(enic);
if (err)
return err;
}
return err;
}
static int enic_set_mac_address(struct net_device *netdev, void *p)
{
struct sockaddr *saddr = p;
char *addr = saddr->sa_data;
struct enic *enic = netdev_priv(netdev);
int err;
err = enic_dev_del_station_addr(enic);
if (err)
return err;
err = enic_set_mac_addr(netdev, addr);
if (err)
return err;
return enic_dev_add_station_addr(enic);
}
static void enic_set_rx_mode(struct net_device *netdev)
{
struct enic *enic = netdev_priv(netdev);
int directed = 1;
int multicast = (netdev->flags & IFF_MULTICAST) ? 1 : 0;
int broadcast = (netdev->flags & IFF_BROADCAST) ? 1 : 0;
int promisc = (netdev->flags & IFF_PROMISC) ||
netdev_uc_count(netdev) > ENIC_UNICAST_PERFECT_FILTERS;
int allmulti = (netdev->flags & IFF_ALLMULTI) ||
netdev_mc_count(netdev) > ENIC_MULTICAST_PERFECT_FILTERS;
unsigned int flags = netdev->flags |
(allmulti ? IFF_ALLMULTI : 0) |
(promisc ? IFF_PROMISC : 0);
if (enic->flags != flags) {
enic->flags = flags;
enic_dev_packet_filter(enic, directed,
multicast, broadcast, promisc, allmulti);
}
if (!promisc) {
__dev_uc_sync(netdev, enic_uc_sync, enic_uc_unsync);
if (!allmulti)
__dev_mc_sync(netdev, enic_mc_sync, enic_mc_unsync);
}
}
static void enic_tx_timeout(struct net_device *netdev)
{
struct enic *enic = netdev_priv(netdev);
schedule_work(&enic->tx_hang_reset);
}
static int enic_set_vf_mac(struct net_device *netdev, int vf, u8 *mac)
{
struct enic *enic = netdev_priv(netdev);
struct enic_port_profile *pp;
int err;
ENIC_PP_BY_INDEX(enic, vf, pp, &err);
if (err)
return err;
if (is_valid_ether_addr(mac) || is_zero_ether_addr(mac)) {
if (vf == PORT_SELF_VF) {
memcpy(pp->vf_mac, mac, ETH_ALEN);
return 0;
} else {
ENIC_DEVCMD_PROXY_BY_INDEX(vf, err, enic,
vnic_dev_set_mac_addr, mac);
return enic_dev_status_to_errno(err);
}
} else
return -EINVAL;
}
static int enic_set_vf_port(struct net_device *netdev, int vf,
struct nlattr *port[])
{
struct enic *enic = netdev_priv(netdev);
struct enic_port_profile prev_pp;
struct enic_port_profile *pp;
int err = 0, restore_pp = 1;
ENIC_PP_BY_INDEX(enic, vf, pp, &err);
if (err)
return err;
if (!port[IFLA_PORT_REQUEST])
return -EOPNOTSUPP;
memcpy(&prev_pp, pp, sizeof(*enic->pp));
memset(pp, 0, sizeof(*enic->pp));
pp->set |= ENIC_SET_REQUEST;
pp->request = nla_get_u8(port[IFLA_PORT_REQUEST]);
if (port[IFLA_PORT_PROFILE]) {
pp->set |= ENIC_SET_NAME;
memcpy(pp->name, nla_data(port[IFLA_PORT_PROFILE]),
PORT_PROFILE_MAX);
}
if (port[IFLA_PORT_INSTANCE_UUID]) {
pp->set |= ENIC_SET_INSTANCE;
memcpy(pp->instance_uuid,
nla_data(port[IFLA_PORT_INSTANCE_UUID]), PORT_UUID_MAX);
}
if (port[IFLA_PORT_HOST_UUID]) {
pp->set |= ENIC_SET_HOST;
memcpy(pp->host_uuid,
nla_data(port[IFLA_PORT_HOST_UUID]), PORT_UUID_MAX);
}
if (vf == PORT_SELF_VF) {
if (!is_zero_ether_addr(prev_pp.vf_mac))
memcpy(pp->mac_addr, prev_pp.vf_mac, ETH_ALEN);
if (is_zero_ether_addr(netdev->dev_addr))
eth_hw_addr_random(netdev);
} else {
ENIC_DEVCMD_PROXY_BY_INDEX(vf, err, enic,
vnic_dev_get_mac_addr, pp->mac_addr);
if (err) {
netdev_err(netdev, "Error getting mac for vf %d\n", vf);
memcpy(pp, &prev_pp, sizeof(*pp));
return enic_dev_status_to_errno(err);
}
}
err = enic_process_set_pp_request(enic, vf, &prev_pp, &restore_pp);
if (err) {
if (restore_pp) {
memcpy(pp, &prev_pp, sizeof(*pp));
} else {
memset(pp, 0, sizeof(*pp));
if (vf == PORT_SELF_VF)
eth_zero_addr(netdev->dev_addr);
}
} else {
pp->set |= ENIC_PORT_REQUEST_APPLIED;
if (pp->request == PORT_REQUEST_DISASSOCIATE) {
eth_zero_addr(pp->mac_addr);
if (vf == PORT_SELF_VF)
eth_zero_addr(netdev->dev_addr);
}
}
if (vf == PORT_SELF_VF)
eth_zero_addr(pp->vf_mac);
return err;
}
static int enic_get_vf_port(struct net_device *netdev, int vf,
struct sk_buff *skb)
{
struct enic *enic = netdev_priv(netdev);
u16 response = PORT_PROFILE_RESPONSE_SUCCESS;
struct enic_port_profile *pp;
int err;
ENIC_PP_BY_INDEX(enic, vf, pp, &err);
if (err)
return err;
if (!(pp->set & ENIC_PORT_REQUEST_APPLIED))
return -ENODATA;
err = enic_process_get_pp_request(enic, vf, pp->request, &response);
if (err)
return err;
if (nla_put_u16(skb, IFLA_PORT_REQUEST, pp->request) ||
nla_put_u16(skb, IFLA_PORT_RESPONSE, response) ||
((pp->set & ENIC_SET_NAME) &&
nla_put(skb, IFLA_PORT_PROFILE, PORT_PROFILE_MAX, pp->name)) ||
((pp->set & ENIC_SET_INSTANCE) &&
nla_put(skb, IFLA_PORT_INSTANCE_UUID, PORT_UUID_MAX,
pp->instance_uuid)) ||
((pp->set & ENIC_SET_HOST) &&
nla_put(skb, IFLA_PORT_HOST_UUID, PORT_UUID_MAX, pp->host_uuid)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -EMSGSIZE;
}
static void enic_free_rq_buf(struct vnic_rq *rq, struct vnic_rq_buf *buf)
{
struct enic *enic = vnic_dev_priv(rq->vdev);
if (!buf->os_buf)
return;
pci_unmap_single(enic->pdev, buf->dma_addr,
buf->len, PCI_DMA_FROMDEVICE);
dev_kfree_skb_any(buf->os_buf);
buf->os_buf = NULL;
}
static int enic_rq_alloc_buf(struct vnic_rq *rq)
{
struct enic *enic = vnic_dev_priv(rq->vdev);
struct net_device *netdev = enic->netdev;
struct sk_buff *skb;
unsigned int len = netdev->mtu + VLAN_ETH_HLEN;
unsigned int os_buf_index = 0;
dma_addr_t dma_addr;
struct vnic_rq_buf *buf = rq->to_use;
if (buf->os_buf) {
enic_queue_rq_desc(rq, buf->os_buf, os_buf_index, buf->dma_addr,
buf->len);
return 0;
}
skb = netdev_alloc_skb_ip_align(netdev, len);
if (!skb)
return -ENOMEM;
dma_addr = pci_map_single(enic->pdev, skb->data, len,
PCI_DMA_FROMDEVICE);
if (unlikely(enic_dma_map_check(enic, dma_addr))) {
dev_kfree_skb(skb);
return -ENOMEM;
}
enic_queue_rq_desc(rq, skb, os_buf_index,
dma_addr, len);
return 0;
}
static void enic_intr_update_pkt_size(struct vnic_rx_bytes_counter *pkt_size,
u32 pkt_len)
{
if (ENIC_LARGE_PKT_THRESHOLD <= pkt_len)
pkt_size->large_pkt_bytes_cnt += pkt_len;
else
pkt_size->small_pkt_bytes_cnt += pkt_len;
}
static bool enic_rxcopybreak(struct net_device *netdev, struct sk_buff **skb,
struct vnic_rq_buf *buf, u16 len)
{
struct enic *enic = netdev_priv(netdev);
struct sk_buff *new_skb;
if (len > enic->rx_copybreak)
return false;
new_skb = netdev_alloc_skb_ip_align(netdev, len);
if (!new_skb)
return false;
pci_dma_sync_single_for_cpu(enic->pdev, buf->dma_addr, len,
DMA_FROM_DEVICE);
memcpy(new_skb->data, (*skb)->data, len);
*skb = new_skb;
return true;
}
static void enic_rq_indicate_buf(struct vnic_rq *rq,
struct cq_desc *cq_desc, struct vnic_rq_buf *buf,
int skipped, void *opaque)
{
struct enic *enic = vnic_dev_priv(rq->vdev);
struct net_device *netdev = enic->netdev;
struct sk_buff *skb;
struct vnic_cq *cq = &enic->cq[enic_cq_rq(enic, rq->index)];
u8 type, color, eop, sop, ingress_port, vlan_stripped;
u8 fcoe, fcoe_sof, fcoe_fc_crc_ok, fcoe_enc_error, fcoe_eof;
u8 tcp_udp_csum_ok, udp, tcp, ipv4_csum_ok;
u8 ipv6, ipv4, ipv4_fragment, fcs_ok, rss_type, csum_not_calc;
u8 packet_error;
u16 q_number, completed_index, bytes_written, vlan_tci, checksum;
u32 rss_hash;
if (skipped)
return;
skb = buf->os_buf;
cq_enet_rq_desc_dec((struct cq_enet_rq_desc *)cq_desc,
&type, &color, &q_number, &completed_index,
&ingress_port, &fcoe, &eop, &sop, &rss_type,
&csum_not_calc, &rss_hash, &bytes_written,
&packet_error, &vlan_stripped, &vlan_tci, &checksum,
&fcoe_sof, &fcoe_fc_crc_ok, &fcoe_enc_error,
&fcoe_eof, &tcp_udp_csum_ok, &udp, &tcp,
&ipv4_csum_ok, &ipv6, &ipv4, &ipv4_fragment,
&fcs_ok);
if (packet_error) {
if (!fcs_ok) {
if (bytes_written > 0)
enic->rq_bad_fcs++;
else if (bytes_written == 0)
enic->rq_truncated_pkts++;
}
pci_unmap_single(enic->pdev, buf->dma_addr, buf->len,
PCI_DMA_FROMDEVICE);
dev_kfree_skb_any(skb);
buf->os_buf = NULL;
return;
}
if (eop && bytes_written > 0) {
if (!enic_rxcopybreak(netdev, &skb, buf, bytes_written)) {
buf->os_buf = NULL;
pci_unmap_single(enic->pdev, buf->dma_addr, buf->len,
PCI_DMA_FROMDEVICE);
}
prefetch(skb->data - NET_IP_ALIGN);
skb_put(skb, bytes_written);
skb->protocol = eth_type_trans(skb, netdev);
skb_record_rx_queue(skb, q_number);
if (netdev->features & NETIF_F_RXHASH) {
skb_set_hash(skb, rss_hash,
(rss_type &
(NIC_CFG_RSS_HASH_TYPE_TCP_IPV6_EX |
NIC_CFG_RSS_HASH_TYPE_TCP_IPV6 |
NIC_CFG_RSS_HASH_TYPE_TCP_IPV4)) ?
PKT_HASH_TYPE_L4 : PKT_HASH_TYPE_L3);
}
if ((netdev->features & NETIF_F_RXCSUM) && tcp_udp_csum_ok &&
ipv4_csum_ok)
skb->ip_summed = CHECKSUM_UNNECESSARY;
if (vlan_stripped)
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q), vlan_tci);
skb_mark_napi_id(skb, &enic->napi[rq->index]);
if (enic_poll_busy_polling(rq) ||
!(netdev->features & NETIF_F_GRO))
netif_receive_skb(skb);
else
napi_gro_receive(&enic->napi[q_number], skb);
if (enic->rx_coalesce_setting.use_adaptive_rx_coalesce)
enic_intr_update_pkt_size(&cq->pkt_size_counter,
bytes_written);
} else {
pci_unmap_single(enic->pdev, buf->dma_addr, buf->len,
PCI_DMA_FROMDEVICE);
dev_kfree_skb_any(skb);
buf->os_buf = NULL;
}
}
static int enic_rq_service(struct vnic_dev *vdev, struct cq_desc *cq_desc,
u8 type, u16 q_number, u16 completed_index, void *opaque)
{
struct enic *enic = vnic_dev_priv(vdev);
vnic_rq_service(&enic->rq[q_number], cq_desc,
completed_index, VNIC_RQ_RETURN_DESC,
enic_rq_indicate_buf, opaque);
return 0;
}
static void enic_set_int_moderation(struct enic *enic, struct vnic_rq *rq)
{
unsigned int intr = enic_msix_rq_intr(enic, rq->index);
struct vnic_cq *cq = &enic->cq[enic_cq_rq(enic, rq->index)];
u32 timer = cq->tobe_rx_coal_timeval;
if (cq->tobe_rx_coal_timeval != cq->cur_rx_coal_timeval) {
vnic_intr_coalescing_timer_set(&enic->intr[intr], timer);
cq->cur_rx_coal_timeval = cq->tobe_rx_coal_timeval;
}
}
static void enic_calc_int_moderation(struct enic *enic, struct vnic_rq *rq)
{
struct enic_rx_coal *rx_coal = &enic->rx_coalesce_setting;
struct vnic_cq *cq = &enic->cq[enic_cq_rq(enic, rq->index)];
struct vnic_rx_bytes_counter *pkt_size_counter = &cq->pkt_size_counter;
int index;
u32 timer;
u32 range_start;
u32 traffic;
u64 delta;
ktime_t now = ktime_get();
delta = ktime_us_delta(now, cq->prev_ts);
if (delta < ENIC_AIC_TS_BREAK)
return;
cq->prev_ts = now;
traffic = pkt_size_counter->large_pkt_bytes_cnt +
pkt_size_counter->small_pkt_bytes_cnt;
traffic <<= 3;
traffic = delta > UINT_MAX ? 0 : traffic / (u32)delta;
for (index = 0; index < ENIC_MAX_COALESCE_TIMERS; index++)
if (traffic < mod_table[index].rx_rate)
break;
range_start = (pkt_size_counter->small_pkt_bytes_cnt >
pkt_size_counter->large_pkt_bytes_cnt << 1) ?
rx_coal->small_pkt_range_start :
rx_coal->large_pkt_range_start;
timer = range_start + ((rx_coal->range_end - range_start) *
mod_table[index].range_percent / 100);
cq->tobe_rx_coal_timeval = (timer + cq->tobe_rx_coal_timeval) >> 1;
pkt_size_counter->large_pkt_bytes_cnt = 0;
pkt_size_counter->small_pkt_bytes_cnt = 0;
}
static int enic_poll(struct napi_struct *napi, int budget)
{
struct net_device *netdev = napi->dev;
struct enic *enic = netdev_priv(netdev);
unsigned int cq_rq = enic_cq_rq(enic, 0);
unsigned int cq_wq = enic_cq_wq(enic, 0);
unsigned int intr = enic_legacy_io_intr();
unsigned int rq_work_to_do = budget;
unsigned int wq_work_to_do = -1;
unsigned int work_done, rq_work_done = 0, wq_work_done;
int err;
wq_work_done = vnic_cq_service(&enic->cq[cq_wq], wq_work_to_do,
enic_wq_service, NULL);
if (!enic_poll_lock_napi(&enic->rq[cq_rq])) {
if (wq_work_done > 0)
vnic_intr_return_credits(&enic->intr[intr],
wq_work_done,
0 ,
0 );
return budget;
}
if (budget > 0)
rq_work_done = vnic_cq_service(&enic->cq[cq_rq],
rq_work_to_do, enic_rq_service, NULL);
work_done = rq_work_done + wq_work_done;
if (work_done > 0)
vnic_intr_return_credits(&enic->intr[intr],
work_done,
0 ,
0 );
err = vnic_rq_fill(&enic->rq[0], enic_rq_alloc_buf);
enic_poll_unlock_napi(&enic->rq[cq_rq], napi);
if (err)
rq_work_done = rq_work_to_do;
if (enic->rx_coalesce_setting.use_adaptive_rx_coalesce)
enic_calc_int_moderation(enic, &enic->rq[0]);
if (rq_work_done < rq_work_to_do) {
napi_complete(napi);
if (enic->rx_coalesce_setting.use_adaptive_rx_coalesce)
enic_set_int_moderation(enic, &enic->rq[0]);
vnic_intr_unmask(&enic->intr[intr]);
}
return rq_work_done;
}
static void enic_free_rx_cpu_rmap(struct enic *enic)
{
free_irq_cpu_rmap(enic->netdev->rx_cpu_rmap);
enic->netdev->rx_cpu_rmap = NULL;
}
static void enic_set_rx_cpu_rmap(struct enic *enic)
{
int i, res;
if (vnic_dev_get_intr_mode(enic->vdev) == VNIC_DEV_INTR_MODE_MSIX) {
enic->netdev->rx_cpu_rmap = alloc_irq_cpu_rmap(enic->rq_count);
if (unlikely(!enic->netdev->rx_cpu_rmap))
return;
for (i = 0; i < enic->rq_count; i++) {
res = irq_cpu_rmap_add(enic->netdev->rx_cpu_rmap,
enic->msix_entry[i].vector);
if (unlikely(res)) {
enic_free_rx_cpu_rmap(enic);
return;
}
}
}
}
static void enic_free_rx_cpu_rmap(struct enic *enic)
{
}
static void enic_set_rx_cpu_rmap(struct enic *enic)
{
}
static int enic_busy_poll(struct napi_struct *napi)
{
struct net_device *netdev = napi->dev;
struct enic *enic = netdev_priv(netdev);
unsigned int rq = (napi - &enic->napi[0]);
unsigned int cq = enic_cq_rq(enic, rq);
unsigned int intr = enic_msix_rq_intr(enic, rq);
unsigned int work_to_do = -1;
unsigned int work_done;
if (!enic_poll_lock_poll(&enic->rq[rq]))
return LL_FLUSH_BUSY;
work_done = vnic_cq_service(&enic->cq[cq], work_to_do,
enic_rq_service, NULL);
if (work_done > 0)
vnic_intr_return_credits(&enic->intr[intr],
work_done, 0, 0);
vnic_rq_fill(&enic->rq[rq], enic_rq_alloc_buf);
if (enic->rx_coalesce_setting.use_adaptive_rx_coalesce)
enic_calc_int_moderation(enic, &enic->rq[rq]);
enic_poll_unlock_poll(&enic->rq[rq]);
return work_done;
}
static int enic_poll_msix_wq(struct napi_struct *napi, int budget)
{
struct net_device *netdev = napi->dev;
struct enic *enic = netdev_priv(netdev);
unsigned int wq_index = (napi - &enic->napi[0]) - enic->rq_count;
struct vnic_wq *wq = &enic->wq[wq_index];
unsigned int cq;
unsigned int intr;
unsigned int wq_work_to_do = -1;
unsigned int wq_work_done;
unsigned int wq_irq;
wq_irq = wq->index;
cq = enic_cq_wq(enic, wq_irq);
intr = enic_msix_wq_intr(enic, wq_irq);
wq_work_done = vnic_cq_service(&enic->cq[cq], wq_work_to_do,
enic_wq_service, NULL);
vnic_intr_return_credits(&enic->intr[intr], wq_work_done,
0 ,
1 );
if (!wq_work_done) {
napi_complete(napi);
vnic_intr_unmask(&enic->intr[intr]);
return 0;
}
return budget;
}
static int enic_poll_msix_rq(struct napi_struct *napi, int budget)
{
struct net_device *netdev = napi->dev;
struct enic *enic = netdev_priv(netdev);
unsigned int rq = (napi - &enic->napi[0]);
unsigned int cq = enic_cq_rq(enic, rq);
unsigned int intr = enic_msix_rq_intr(enic, rq);
unsigned int work_to_do = budget;
unsigned int work_done = 0;
int err;
if (!enic_poll_lock_napi(&enic->rq[rq]))
return budget;
if (budget > 0)
work_done = vnic_cq_service(&enic->cq[cq],
work_to_do, enic_rq_service, NULL);
if (work_done > 0)
vnic_intr_return_credits(&enic->intr[intr],
work_done,
0 ,
0 );
err = vnic_rq_fill(&enic->rq[rq], enic_rq_alloc_buf);
if (err)
work_done = work_to_do;
if (enic->rx_coalesce_setting.use_adaptive_rx_coalesce)
enic_calc_int_moderation(enic, &enic->rq[rq]);
enic_poll_unlock_napi(&enic->rq[rq], napi);
if (work_done < work_to_do) {
napi_complete(napi);
if (enic->rx_coalesce_setting.use_adaptive_rx_coalesce)
enic_set_int_moderation(enic, &enic->rq[rq]);
vnic_intr_unmask(&enic->intr[intr]);
}
return work_done;
}
static void enic_notify_timer(unsigned long data)
{
struct enic *enic = (struct enic *)data;
enic_notify_check(enic);
mod_timer(&enic->notify_timer,
round_jiffies(jiffies + ENIC_NOTIFY_TIMER_PERIOD));
}
static void enic_free_intr(struct enic *enic)
{
struct net_device *netdev = enic->netdev;
unsigned int i;
enic_free_rx_cpu_rmap(enic);
switch (vnic_dev_get_intr_mode(enic->vdev)) {
case VNIC_DEV_INTR_MODE_INTX:
free_irq(enic->pdev->irq, netdev);
break;
case VNIC_DEV_INTR_MODE_MSI:
free_irq(enic->pdev->irq, enic);
break;
case VNIC_DEV_INTR_MODE_MSIX:
for (i = 0; i < ARRAY_SIZE(enic->msix); i++)
if (enic->msix[i].requested)
free_irq(enic->msix_entry[i].vector,
enic->msix[i].devid);
break;
default:
break;
}
}
static int enic_request_intr(struct enic *enic)
{
struct net_device *netdev = enic->netdev;
unsigned int i, intr;
int err = 0;
enic_set_rx_cpu_rmap(enic);
switch (vnic_dev_get_intr_mode(enic->vdev)) {
case VNIC_DEV_INTR_MODE_INTX:
err = request_irq(enic->pdev->irq, enic_isr_legacy,
IRQF_SHARED, netdev->name, netdev);
break;
case VNIC_DEV_INTR_MODE_MSI:
err = request_irq(enic->pdev->irq, enic_isr_msi,
0, netdev->name, enic);
break;
case VNIC_DEV_INTR_MODE_MSIX:
for (i = 0; i < enic->rq_count; i++) {
intr = enic_msix_rq_intr(enic, i);
snprintf(enic->msix[intr].devname,
sizeof(enic->msix[intr].devname),
"%.11s-rx-%d", netdev->name, i);
enic->msix[intr].isr = enic_isr_msix;
enic->msix[intr].devid = &enic->napi[i];
}
for (i = 0; i < enic->wq_count; i++) {
int wq = enic_cq_wq(enic, i);
intr = enic_msix_wq_intr(enic, i);
snprintf(enic->msix[intr].devname,
sizeof(enic->msix[intr].devname),
"%.11s-tx-%d", netdev->name, i);
enic->msix[intr].isr = enic_isr_msix;
enic->msix[intr].devid = &enic->napi[wq];
}
intr = enic_msix_err_intr(enic);
snprintf(enic->msix[intr].devname,
sizeof(enic->msix[intr].devname),
"%.11s-err", netdev->name);
enic->msix[intr].isr = enic_isr_msix_err;
enic->msix[intr].devid = enic;
intr = enic_msix_notify_intr(enic);
snprintf(enic->msix[intr].devname,
sizeof(enic->msix[intr].devname),
"%.11s-notify", netdev->name);
enic->msix[intr].isr = enic_isr_msix_notify;
enic->msix[intr].devid = enic;
for (i = 0; i < ARRAY_SIZE(enic->msix); i++)
enic->msix[i].requested = 0;
for (i = 0; i < enic->intr_count; i++) {
err = request_irq(enic->msix_entry[i].vector,
enic->msix[i].isr, 0,
enic->msix[i].devname,
enic->msix[i].devid);
if (err) {
enic_free_intr(enic);
break;
}
enic->msix[i].requested = 1;
}
break;
default:
break;
}
return err;
}
static void enic_synchronize_irqs(struct enic *enic)
{
unsigned int i;
switch (vnic_dev_get_intr_mode(enic->vdev)) {
case VNIC_DEV_INTR_MODE_INTX:
case VNIC_DEV_INTR_MODE_MSI:
synchronize_irq(enic->pdev->irq);
break;
case VNIC_DEV_INTR_MODE_MSIX:
for (i = 0; i < enic->intr_count; i++)
synchronize_irq(enic->msix_entry[i].vector);
break;
default:
break;
}
}
static void enic_set_rx_coal_setting(struct enic *enic)
{
unsigned int speed;
int index = -1;
struct enic_rx_coal *rx_coal = &enic->rx_coalesce_setting;
speed = vnic_dev_port_speed(enic->vdev);
if (ENIC_LINK_SPEED_10G < speed)
index = ENIC_LINK_40G_INDEX;
else if (ENIC_LINK_SPEED_4G < speed)
index = ENIC_LINK_10G_INDEX;
else
index = ENIC_LINK_4G_INDEX;
rx_coal->small_pkt_range_start = mod_range[index].small_pkt_range_start;
rx_coal->large_pkt_range_start = mod_range[index].large_pkt_range_start;
rx_coal->range_end = ENIC_RX_COALESCE_RANGE_END;
for (index = 0; index < enic->rq_count; index++)
enic->cq[index].cur_rx_coal_timeval =
enic->config.intr_timer_usec;
rx_coal->use_adaptive_rx_coalesce = 1;
}
static int enic_dev_notify_set(struct enic *enic)
{
int err;
spin_lock_bh(&enic->devcmd_lock);
switch (vnic_dev_get_intr_mode(enic->vdev)) {
case VNIC_DEV_INTR_MODE_INTX:
err = vnic_dev_notify_set(enic->vdev,
enic_legacy_notify_intr());
break;
case VNIC_DEV_INTR_MODE_MSIX:
err = vnic_dev_notify_set(enic->vdev,
enic_msix_notify_intr(enic));
break;
default:
err = vnic_dev_notify_set(enic->vdev, -1 );
break;
}
spin_unlock_bh(&enic->devcmd_lock);
return err;
}
static void enic_notify_timer_start(struct enic *enic)
{
switch (vnic_dev_get_intr_mode(enic->vdev)) {
case VNIC_DEV_INTR_MODE_MSI:
mod_timer(&enic->notify_timer, jiffies);
break;
default:
break;
}
}
static int enic_open(struct net_device *netdev)
{
struct enic *enic = netdev_priv(netdev);
unsigned int i;
int err;
err = enic_request_intr(enic);
if (err) {
netdev_err(netdev, "Unable to request irq.\n");
return err;
}
enic_init_affinity_hint(enic);
enic_set_affinity_hint(enic);
err = enic_dev_notify_set(enic);
if (err) {
netdev_err(netdev,
"Failed to alloc notify buffer, aborting.\n");
goto err_out_free_intr;
}
for (i = 0; i < enic->rq_count; i++) {
vnic_rq_fill(&enic->rq[i], enic_rq_alloc_buf);
if (vnic_rq_desc_used(&enic->rq[i]) == 0) {
netdev_err(netdev, "Unable to alloc receive buffers\n");
err = -ENOMEM;
goto err_out_free_rq;
}
}
for (i = 0; i < enic->wq_count; i++)
vnic_wq_enable(&enic->wq[i]);
for (i = 0; i < enic->rq_count; i++)
vnic_rq_enable(&enic->rq[i]);
if (!enic_is_dynamic(enic) && !enic_is_sriov_vf(enic))
enic_dev_add_station_addr(enic);
enic_set_rx_mode(netdev);
netif_tx_wake_all_queues(netdev);
for (i = 0; i < enic->rq_count; i++) {
enic_busy_poll_init_lock(&enic->rq[i]);
napi_enable(&enic->napi[i]);
}
if (vnic_dev_get_intr_mode(enic->vdev) == VNIC_DEV_INTR_MODE_MSIX)
for (i = 0; i < enic->wq_count; i++)
napi_enable(&enic->napi[enic_cq_wq(enic, i)]);
enic_dev_enable(enic);
for (i = 0; i < enic->intr_count; i++)
vnic_intr_unmask(&enic->intr[i]);
enic_notify_timer_start(enic);
enic_rfs_flw_tbl_init(enic);
return 0;
err_out_free_rq:
for (i = 0; i < enic->rq_count; i++)
vnic_rq_clean(&enic->rq[i], enic_free_rq_buf);
enic_dev_notify_unset(enic);
err_out_free_intr:
enic_unset_affinity_hint(enic);
enic_free_intr(enic);
return err;
}
static int enic_stop(struct net_device *netdev)
{
struct enic *enic = netdev_priv(netdev);
unsigned int i;
int err;
for (i = 0; i < enic->intr_count; i++) {
vnic_intr_mask(&enic->intr[i]);
(void)vnic_intr_masked(&enic->intr[i]);
}
enic_synchronize_irqs(enic);
del_timer_sync(&enic->notify_timer);
enic_rfs_flw_tbl_free(enic);
enic_dev_disable(enic);
for (i = 0; i < enic->rq_count; i++) {
napi_disable(&enic->napi[i]);
local_bh_disable();
while (!enic_poll_lock_napi(&enic->rq[i]))
mdelay(1);
local_bh_enable();
}
netif_carrier_off(netdev);
netif_tx_disable(netdev);
if (vnic_dev_get_intr_mode(enic->vdev) == VNIC_DEV_INTR_MODE_MSIX)
for (i = 0; i < enic->wq_count; i++)
napi_disable(&enic->napi[enic_cq_wq(enic, i)]);
if (!enic_is_dynamic(enic) && !enic_is_sriov_vf(enic))
enic_dev_del_station_addr(enic);
for (i = 0; i < enic->wq_count; i++) {
err = vnic_wq_disable(&enic->wq[i]);
if (err)
return err;
}
for (i = 0; i < enic->rq_count; i++) {
err = vnic_rq_disable(&enic->rq[i]);
if (err)
return err;
}
enic_dev_notify_unset(enic);
enic_unset_affinity_hint(enic);
enic_free_intr(enic);
for (i = 0; i < enic->wq_count; i++)
vnic_wq_clean(&enic->wq[i], enic_free_wq_buf);
for (i = 0; i < enic->rq_count; i++)
vnic_rq_clean(&enic->rq[i], enic_free_rq_buf);
for (i = 0; i < enic->cq_count; i++)
vnic_cq_clean(&enic->cq[i]);
for (i = 0; i < enic->intr_count; i++)
vnic_intr_clean(&enic->intr[i]);
return 0;
}
static int enic_change_mtu(struct net_device *netdev, int new_mtu)
{
struct enic *enic = netdev_priv(netdev);
int running = netif_running(netdev);
if (new_mtu < ENIC_MIN_MTU || new_mtu > ENIC_MAX_MTU)
return -EINVAL;
if (enic_is_dynamic(enic) || enic_is_sriov_vf(enic))
return -EOPNOTSUPP;
if (running)
enic_stop(netdev);
netdev->mtu = new_mtu;
if (netdev->mtu > enic->port_mtu)
netdev_warn(netdev,
"interface MTU (%d) set higher than port MTU (%d)\n",
netdev->mtu, enic->port_mtu);
if (running)
enic_open(netdev);
return 0;
}
static void enic_change_mtu_work(struct work_struct *work)
{
struct enic *enic = container_of(work, struct enic, change_mtu_work);
struct net_device *netdev = enic->netdev;
int new_mtu = vnic_dev_mtu(enic->vdev);
int err;
unsigned int i;
new_mtu = max_t(int, ENIC_MIN_MTU, min_t(int, ENIC_MAX_MTU, new_mtu));
rtnl_lock();
del_timer_sync(&enic->notify_timer);
for (i = 0; i < enic->rq_count; i++)
napi_disable(&enic->napi[i]);
vnic_intr_mask(&enic->intr[0]);
enic_synchronize_irqs(enic);
err = vnic_rq_disable(&enic->rq[0]);
if (err) {
rtnl_unlock();
netdev_err(netdev, "Unable to disable RQ.\n");
return;
}
vnic_rq_clean(&enic->rq[0], enic_free_rq_buf);
vnic_cq_clean(&enic->cq[0]);
vnic_intr_clean(&enic->intr[0]);
netdev->mtu = new_mtu;
vnic_rq_fill(&enic->rq[0], enic_rq_alloc_buf);
if (vnic_rq_desc_used(&enic->rq[0]) == 0) {
rtnl_unlock();
netdev_err(netdev, "Unable to alloc receive buffers.\n");
return;
}
vnic_rq_enable(&enic->rq[0]);
napi_enable(&enic->napi[0]);
vnic_intr_unmask(&enic->intr[0]);
enic_notify_timer_start(enic);
rtnl_unlock();
netdev_info(netdev, "interface MTU set as %d\n", netdev->mtu);
}
static void enic_poll_controller(struct net_device *netdev)
{
struct enic *enic = netdev_priv(netdev);
struct vnic_dev *vdev = enic->vdev;
unsigned int i, intr;
switch (vnic_dev_get_intr_mode(vdev)) {
case VNIC_DEV_INTR_MODE_MSIX:
for (i = 0; i < enic->rq_count; i++) {
intr = enic_msix_rq_intr(enic, i);
enic_isr_msix(enic->msix_entry[intr].vector,
&enic->napi[i]);
}
for (i = 0; i < enic->wq_count; i++) {
intr = enic_msix_wq_intr(enic, i);
enic_isr_msix(enic->msix_entry[intr].vector,
&enic->napi[enic_cq_wq(enic, i)]);
}
break;
case VNIC_DEV_INTR_MODE_MSI:
enic_isr_msi(enic->pdev->irq, enic);
break;
case VNIC_DEV_INTR_MODE_INTX:
enic_isr_legacy(enic->pdev->irq, netdev);
break;
default:
break;
}
}
static int enic_dev_wait(struct vnic_dev *vdev,
int (*start)(struct vnic_dev *, int),
int (*finished)(struct vnic_dev *, int *),
int arg)
{
unsigned long time;
int done;
int err;
BUG_ON(in_interrupt());
err = start(vdev, arg);
if (err)
return err;
time = jiffies + (HZ * 2);
do {
err = finished(vdev, &done);
if (err)
return err;
if (done)
return 0;
schedule_timeout_uninterruptible(HZ / 10);
} while (time_after(time, jiffies));
return -ETIMEDOUT;
}
static int enic_dev_open(struct enic *enic)
{
int err;
err = enic_dev_wait(enic->vdev, vnic_dev_open,
vnic_dev_open_done, 0);
if (err)
dev_err(enic_get_dev(enic), "vNIC device open failed, err %d\n",
err);
return err;
}
static int enic_dev_soft_reset(struct enic *enic)
{
int err;
err = enic_dev_wait(enic->vdev, vnic_dev_soft_reset,
vnic_dev_soft_reset_done, 0);
if (err)
netdev_err(enic->netdev, "vNIC soft reset failed, err %d\n",
err);
return err;
}
static int enic_dev_hang_reset(struct enic *enic)
{
int err;
err = enic_dev_wait(enic->vdev, vnic_dev_hang_reset,
vnic_dev_hang_reset_done, 0);
if (err)
netdev_err(enic->netdev, "vNIC hang reset failed, err %d\n",
err);
return err;
}
int __enic_set_rsskey(struct enic *enic)
{
union vnic_rss_key *rss_key_buf_va;
dma_addr_t rss_key_buf_pa;
int i, kidx, bidx, err;
rss_key_buf_va = pci_zalloc_consistent(enic->pdev,
sizeof(union vnic_rss_key),
&rss_key_buf_pa);
if (!rss_key_buf_va)
return -ENOMEM;
for (i = 0; i < ENIC_RSS_LEN; i++) {
kidx = i / ENIC_RSS_BYTES_PER_KEY;
bidx = i % ENIC_RSS_BYTES_PER_KEY;
rss_key_buf_va->key[kidx].b[bidx] = enic->rss_key[i];
}
spin_lock_bh(&enic->devcmd_lock);
err = enic_set_rss_key(enic,
rss_key_buf_pa,
sizeof(union vnic_rss_key));
spin_unlock_bh(&enic->devcmd_lock);
pci_free_consistent(enic->pdev, sizeof(union vnic_rss_key),
rss_key_buf_va, rss_key_buf_pa);
return err;
}
static int enic_set_rsskey(struct enic *enic)
{
netdev_rss_key_fill(enic->rss_key, ENIC_RSS_LEN);
return __enic_set_rsskey(enic);
}
static int enic_set_rsscpu(struct enic *enic, u8 rss_hash_bits)
{
dma_addr_t rss_cpu_buf_pa;
union vnic_rss_cpu *rss_cpu_buf_va = NULL;
unsigned int i;
int err;
rss_cpu_buf_va = pci_alloc_consistent(enic->pdev,
sizeof(union vnic_rss_cpu), &rss_cpu_buf_pa);
if (!rss_cpu_buf_va)
return -ENOMEM;
for (i = 0; i < (1 << rss_hash_bits); i++)
(*rss_cpu_buf_va).cpu[i/4].b[i%4] = i % enic->rq_count;
spin_lock_bh(&enic->devcmd_lock);
err = enic_set_rss_cpu(enic,
rss_cpu_buf_pa,
sizeof(union vnic_rss_cpu));
spin_unlock_bh(&enic->devcmd_lock);
pci_free_consistent(enic->pdev, sizeof(union vnic_rss_cpu),
rss_cpu_buf_va, rss_cpu_buf_pa);
return err;
}
static int enic_set_niccfg(struct enic *enic, u8 rss_default_cpu,
u8 rss_hash_type, u8 rss_hash_bits, u8 rss_base_cpu, u8 rss_enable)
{
const u8 tso_ipid_split_en = 0;
const u8 ig_vlan_strip_en = 1;
int err;
spin_lock_bh(&enic->devcmd_lock);
err = enic_set_nic_cfg(enic,
rss_default_cpu, rss_hash_type,
rss_hash_bits, rss_base_cpu,
rss_enable, tso_ipid_split_en,
ig_vlan_strip_en);
spin_unlock_bh(&enic->devcmd_lock);
return err;
}
static int enic_set_rss_nic_cfg(struct enic *enic)
{
struct device *dev = enic_get_dev(enic);
const u8 rss_default_cpu = 0;
const u8 rss_hash_type = NIC_CFG_RSS_HASH_TYPE_IPV4 |
NIC_CFG_RSS_HASH_TYPE_TCP_IPV4 |
NIC_CFG_RSS_HASH_TYPE_IPV6 |
NIC_CFG_RSS_HASH_TYPE_TCP_IPV6;
const u8 rss_hash_bits = 7;
const u8 rss_base_cpu = 0;
u8 rss_enable = ENIC_SETTING(enic, RSS) && (enic->rq_count > 1);
if (rss_enable) {
if (!enic_set_rsskey(enic)) {
if (enic_set_rsscpu(enic, rss_hash_bits)) {
rss_enable = 0;
dev_warn(dev, "RSS disabled, "
"Failed to set RSS cpu indirection table.");
}
} else {
rss_enable = 0;
dev_warn(dev, "RSS disabled, Failed to set RSS key.\n");
}
}
return enic_set_niccfg(enic, rss_default_cpu, rss_hash_type,
rss_hash_bits, rss_base_cpu, rss_enable);
}
static void enic_reset(struct work_struct *work)
{
struct enic *enic = container_of(work, struct enic, reset);
if (!netif_running(enic->netdev))
return;
rtnl_lock();
spin_lock(&enic->enic_api_lock);
enic_stop(enic->netdev);
enic_dev_soft_reset(enic);
enic_reset_addr_lists(enic);
enic_init_vnic_resources(enic);
enic_set_rss_nic_cfg(enic);
enic_dev_set_ig_vlan_rewrite_mode(enic);
enic_open(enic->netdev);
spin_unlock(&enic->enic_api_lock);
call_netdevice_notifiers(NETDEV_REBOOT, enic->netdev);
rtnl_unlock();
}
static void enic_tx_hang_reset(struct work_struct *work)
{
struct enic *enic = container_of(work, struct enic, tx_hang_reset);
rtnl_lock();
spin_lock(&enic->enic_api_lock);
enic_dev_hang_notify(enic);
enic_stop(enic->netdev);
enic_dev_hang_reset(enic);
enic_reset_addr_lists(enic);
enic_init_vnic_resources(enic);
enic_set_rss_nic_cfg(enic);
enic_dev_set_ig_vlan_rewrite_mode(enic);
enic_open(enic->netdev);
spin_unlock(&enic->enic_api_lock);
call_netdevice_notifiers(NETDEV_REBOOT, enic->netdev);
rtnl_unlock();
}
static int enic_set_intr_mode(struct enic *enic)
{
unsigned int n = min_t(unsigned int, enic->rq_count, ENIC_RQ_MAX);
unsigned int m = min_t(unsigned int, enic->wq_count, ENIC_WQ_MAX);
unsigned int i;
BUG_ON(ARRAY_SIZE(enic->msix_entry) < n + m + 2);
for (i = 0; i < n + m + 2; i++)
enic->msix_entry[i].entry = i;
if (ENIC_SETTING(enic, RSS) &&
enic->config.intr_mode < 1 &&
enic->rq_count >= n &&
enic->wq_count >= m &&
enic->cq_count >= n + m &&
enic->intr_count >= n + m + 2) {
if (pci_enable_msix_range(enic->pdev, enic->msix_entry,
n + m + 2, n + m + 2) > 0) {
enic->rq_count = n;
enic->wq_count = m;
enic->cq_count = n + m;
enic->intr_count = n + m + 2;
vnic_dev_set_intr_mode(enic->vdev,
VNIC_DEV_INTR_MODE_MSIX);
return 0;
}
}
if (enic->config.intr_mode < 1 &&
enic->rq_count >= 1 &&
enic->wq_count >= m &&
enic->cq_count >= 1 + m &&
enic->intr_count >= 1 + m + 2) {
if (pci_enable_msix_range(enic->pdev, enic->msix_entry,
1 + m + 2, 1 + m + 2) > 0) {
enic->rq_count = 1;
enic->wq_count = m;
enic->cq_count = 1 + m;
enic->intr_count = 1 + m + 2;
vnic_dev_set_intr_mode(enic->vdev,
VNIC_DEV_INTR_MODE_MSIX);
return 0;
}
}
if (enic->config.intr_mode < 2 &&
enic->rq_count >= 1 &&
enic->wq_count >= 1 &&
enic->cq_count >= 2 &&
enic->intr_count >= 1 &&
!pci_enable_msi(enic->pdev)) {
enic->rq_count = 1;
enic->wq_count = 1;
enic->cq_count = 2;
enic->intr_count = 1;
vnic_dev_set_intr_mode(enic->vdev, VNIC_DEV_INTR_MODE_MSI);
return 0;
}
if (enic->config.intr_mode < 3 &&
enic->rq_count >= 1 &&
enic->wq_count >= 1 &&
enic->cq_count >= 2 &&
enic->intr_count >= 3) {
enic->rq_count = 1;
enic->wq_count = 1;
enic->cq_count = 2;
enic->intr_count = 3;
vnic_dev_set_intr_mode(enic->vdev, VNIC_DEV_INTR_MODE_INTX);
return 0;
}
vnic_dev_set_intr_mode(enic->vdev, VNIC_DEV_INTR_MODE_UNKNOWN);
return -EINVAL;
}
static void enic_clear_intr_mode(struct enic *enic)
{
switch (vnic_dev_get_intr_mode(enic->vdev)) {
case VNIC_DEV_INTR_MODE_MSIX:
pci_disable_msix(enic->pdev);
break;
case VNIC_DEV_INTR_MODE_MSI:
pci_disable_msi(enic->pdev);
break;
default:
break;
}
vnic_dev_set_intr_mode(enic->vdev, VNIC_DEV_INTR_MODE_UNKNOWN);
}
static void enic_dev_deinit(struct enic *enic)
{
unsigned int i;
for (i = 0; i < enic->rq_count; i++) {
napi_hash_del(&enic->napi[i]);
netif_napi_del(&enic->napi[i]);
}
if (vnic_dev_get_intr_mode(enic->vdev) == VNIC_DEV_INTR_MODE_MSIX)
for (i = 0; i < enic->wq_count; i++)
netif_napi_del(&enic->napi[enic_cq_wq(enic, i)]);
enic_free_vnic_resources(enic);
enic_clear_intr_mode(enic);
enic_free_affinity_hint(enic);
}
static void enic_kdump_kernel_config(struct enic *enic)
{
if (is_kdump_kernel()) {
dev_info(enic_get_dev(enic), "Running from within kdump kernel. Using minimal resources\n");
enic->rq_count = 1;
enic->wq_count = 1;
enic->config.rq_desc_count = ENIC_MIN_RQ_DESCS;
enic->config.wq_desc_count = ENIC_MIN_WQ_DESCS;
enic->config.mtu = min_t(u16, 1500, enic->config.mtu);
}
}
static int enic_dev_init(struct enic *enic)
{
struct device *dev = enic_get_dev(enic);
struct net_device *netdev = enic->netdev;
unsigned int i;
int err;
err = enic_dev_intr_coal_timer_info(enic);
if (err) {
dev_warn(dev, "Using default conversion factor for "
"interrupt coalesce timer\n");
vnic_dev_intr_coal_timer_info_default(enic->vdev);
}
err = enic_get_vnic_config(enic);
if (err) {
dev_err(dev, "Get vNIC configuration failed, aborting\n");
return err;
}
enic_get_res_counts(enic);
enic_kdump_kernel_config(enic);
err = enic_set_intr_mode(enic);
if (err) {
dev_err(dev, "Failed to set intr mode based on resource "
"counts and system capabilities, aborting\n");
return err;
}
err = enic_alloc_vnic_resources(enic);
if (err) {
dev_err(dev, "Failed to alloc vNIC resources, aborting\n");
goto err_out_free_vnic_resources;
}
enic_init_vnic_resources(enic);
err = enic_set_rss_nic_cfg(enic);
if (err) {
dev_err(dev, "Failed to config nic, aborting\n");
goto err_out_free_vnic_resources;
}
switch (vnic_dev_get_intr_mode(enic->vdev)) {
default:
netif_napi_add(netdev, &enic->napi[0], enic_poll, 64);
break;
case VNIC_DEV_INTR_MODE_MSIX:
for (i = 0; i < enic->rq_count; i++) {
netif_napi_add(netdev, &enic->napi[i],
enic_poll_msix_rq, NAPI_POLL_WEIGHT);
}
for (i = 0; i < enic->wq_count; i++)
netif_napi_add(netdev, &enic->napi[enic_cq_wq(enic, i)],
enic_poll_msix_wq, NAPI_POLL_WEIGHT);
break;
}
return 0;
err_out_free_vnic_resources:
enic_free_affinity_hint(enic);
enic_clear_intr_mode(enic);
enic_free_vnic_resources(enic);
return err;
}
static void enic_iounmap(struct enic *enic)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(enic->bar); i++)
if (enic->bar[i].vaddr)
iounmap(enic->bar[i].vaddr);
}
static int enic_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct device *dev = &pdev->dev;
struct net_device *netdev;
struct enic *enic;
int using_dac = 0;
unsigned int i;
int err;
#ifdef CONFIG_PCI_IOV
int pos = 0;
#endif
int num_pps = 1;
netdev = alloc_etherdev_mqs(sizeof(struct enic),
ENIC_RQ_MAX, ENIC_WQ_MAX);
if (!netdev)
return -ENOMEM;
pci_set_drvdata(pdev, netdev);
SET_NETDEV_DEV(netdev, &pdev->dev);
enic = netdev_priv(netdev);
enic->netdev = netdev;
enic->pdev = pdev;
err = pci_enable_device_mem(pdev);
if (err) {
dev_err(dev, "Cannot enable PCI device, aborting\n");
goto err_out_free_netdev;
}
err = pci_request_regions(pdev, DRV_NAME);
if (err) {
dev_err(dev, "Cannot request PCI regions, aborting\n");
goto err_out_disable_device;
}
pci_set_master(pdev);
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(64));
if (err) {
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (err) {
dev_err(dev, "No usable DMA configuration, aborting\n");
goto err_out_release_regions;
}
err = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32));
if (err) {
dev_err(dev, "Unable to obtain %u-bit DMA "
"for consistent allocations, aborting\n", 32);
goto err_out_release_regions;
}
} else {
err = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64));
if (err) {
dev_err(dev, "Unable to obtain %u-bit DMA "
"for consistent allocations, aborting\n", 64);
goto err_out_release_regions;
}
using_dac = 1;
}
for (i = 0; i < ARRAY_SIZE(enic->bar); i++) {
if (!(pci_resource_flags(pdev, i) & IORESOURCE_MEM))
continue;
enic->bar[i].len = pci_resource_len(pdev, i);
enic->bar[i].vaddr = pci_iomap(pdev, i, enic->bar[i].len);
if (!enic->bar[i].vaddr) {
dev_err(dev, "Cannot memory-map BAR %d, aborting\n", i);
err = -ENODEV;
goto err_out_iounmap;
}
enic->bar[i].bus_addr = pci_resource_start(pdev, i);
}
enic->vdev = vnic_dev_register(NULL, enic, pdev, enic->bar,
ARRAY_SIZE(enic->bar));
if (!enic->vdev) {
dev_err(dev, "vNIC registration failed, aborting\n");
err = -ENODEV;
goto err_out_iounmap;
}
err = vnic_devcmd_init(enic->vdev);
if (err)
goto err_out_vnic_unregister;
#ifdef CONFIG_PCI_IOV
pos = pci_find_ext_capability(pdev, PCI_EXT_CAP_ID_SRIOV);
if (pos) {
pci_read_config_word(pdev, pos + PCI_SRIOV_TOTAL_VF,
&enic->num_vfs);
if (enic->num_vfs) {
err = pci_enable_sriov(pdev, enic->num_vfs);
if (err) {
dev_err(dev, "SRIOV enable failed, aborting."
" pci_enable_sriov() returned %d\n",
err);
goto err_out_vnic_unregister;
}
enic->priv_flags |= ENIC_SRIOV_ENABLED;
num_pps = enic->num_vfs;
}
}
#endif
enic->pp = kcalloc(num_pps, sizeof(*enic->pp), GFP_KERNEL);
if (!enic->pp) {
err = -ENOMEM;
goto err_out_disable_sriov_pp;
}
err = enic_dev_open(enic);
if (err) {
dev_err(dev, "vNIC dev open failed, aborting\n");
goto err_out_disable_sriov;
}
spin_lock_init(&enic->devcmd_lock);
spin_lock_init(&enic->enic_api_lock);
err = enic_dev_set_ig_vlan_rewrite_mode(enic);
if (err) {
dev_err(dev,
"Failed to set ingress vlan rewrite mode, aborting.\n");
goto err_out_dev_close;
}
netif_carrier_off(netdev);
if (!enic_is_dynamic(enic)) {
err = vnic_dev_init(enic->vdev, 0);
if (err) {
dev_err(dev, "vNIC dev init failed, aborting\n");
goto err_out_dev_close;
}
}
err = enic_dev_init(enic);
if (err) {
dev_err(dev, "Device initialization failed, aborting\n");
goto err_out_dev_close;
}
netif_set_real_num_tx_queues(netdev, enic->wq_count);
netif_set_real_num_rx_queues(netdev, enic->rq_count);
init_timer(&enic->notify_timer);
enic->notify_timer.function = enic_notify_timer;
enic->notify_timer.data = (unsigned long)enic;
enic_set_rx_coal_setting(enic);
INIT_WORK(&enic->reset, enic_reset);
INIT_WORK(&enic->tx_hang_reset, enic_tx_hang_reset);
INIT_WORK(&enic->change_mtu_work, enic_change_mtu_work);
for (i = 0; i < enic->wq_count; i++)
spin_lock_init(&enic->wq_lock[i]);
enic->port_mtu = enic->config.mtu;
(void)enic_change_mtu(netdev, enic->port_mtu);
err = enic_set_mac_addr(netdev, enic->mac_addr);
if (err) {
dev_err(dev, "Invalid MAC address, aborting\n");
goto err_out_dev_deinit;
}
enic->tx_coalesce_usecs = enic->config.intr_timer_usec;
enic->rx_coalesce_usecs = enic->tx_coalesce_usecs;
if (enic_is_dynamic(enic) || enic_is_sriov_vf(enic))
netdev->netdev_ops = &enic_netdev_dynamic_ops;
else
netdev->netdev_ops = &enic_netdev_ops;
netdev->watchdog_timeo = 2 * HZ;
enic_set_ethtool_ops(netdev);
netdev->features |= NETIF_F_HW_VLAN_CTAG_TX | NETIF_F_HW_VLAN_CTAG_RX;
if (ENIC_SETTING(enic, LOOP)) {
netdev->features &= ~NETIF_F_HW_VLAN_CTAG_TX;
enic->loop_enable = 1;
enic->loop_tag = enic->config.loop_tag;
dev_info(dev, "loopback tag=0x%04x\n", enic->loop_tag);
}
if (ENIC_SETTING(enic, TXCSUM))
netdev->hw_features |= NETIF_F_SG | NETIF_F_HW_CSUM;
if (ENIC_SETTING(enic, TSO))
netdev->hw_features |= NETIF_F_TSO |
NETIF_F_TSO6 | NETIF_F_TSO_ECN;
if (ENIC_SETTING(enic, RSS))
netdev->hw_features |= NETIF_F_RXHASH;
if (ENIC_SETTING(enic, RXCSUM))
netdev->hw_features |= NETIF_F_RXCSUM;
netdev->features |= netdev->hw_features;
#ifdef CONFIG_RFS_ACCEL
netdev->hw_features |= NETIF_F_NTUPLE;
#endif
if (using_dac)
netdev->features |= NETIF_F_HIGHDMA;
netdev->priv_flags |= IFF_UNICAST_FLT;
err = register_netdev(netdev);
if (err) {
dev_err(dev, "Cannot register net device, aborting\n");
goto err_out_dev_deinit;
}
enic->rx_copybreak = RX_COPYBREAK_DEFAULT;
return 0;
err_out_dev_deinit:
enic_dev_deinit(enic);
err_out_dev_close:
vnic_dev_close(enic->vdev);
err_out_disable_sriov:
kfree(enic->pp);
err_out_disable_sriov_pp:
#ifdef CONFIG_PCI_IOV
if (enic_sriov_enabled(enic)) {
pci_disable_sriov(pdev);
enic->priv_flags &= ~ENIC_SRIOV_ENABLED;
}
#endif
err_out_vnic_unregister:
vnic_dev_unregister(enic->vdev);
err_out_iounmap:
enic_iounmap(enic);
err_out_release_regions:
pci_release_regions(pdev);
err_out_disable_device:
pci_disable_device(pdev);
err_out_free_netdev:
free_netdev(netdev);
return err;
}
static void enic_remove(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
if (netdev) {
struct enic *enic = netdev_priv(netdev);
cancel_work_sync(&enic->reset);
cancel_work_sync(&enic->change_mtu_work);
unregister_netdev(netdev);
enic_dev_deinit(enic);
vnic_dev_close(enic->vdev);
#ifdef CONFIG_PCI_IOV
if (enic_sriov_enabled(enic)) {
pci_disable_sriov(pdev);
enic->priv_flags &= ~ENIC_SRIOV_ENABLED;
}
#endif
kfree(enic->pp);
vnic_dev_unregister(enic->vdev);
enic_iounmap(enic);
pci_release_regions(pdev);
pci_disable_device(pdev);
free_netdev(netdev);
}
}
static int __init enic_init_module(void)
{
pr_info("%s, ver %s\n", DRV_DESCRIPTION, DRV_VERSION);
return pci_register_driver(&enic_driver);
}
static void __exit enic_cleanup_module(void)
{
pci_unregister_driver(&enic_driver);
}
