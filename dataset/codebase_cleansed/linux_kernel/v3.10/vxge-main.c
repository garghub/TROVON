static inline int is_vxge_card_up(struct vxgedev *vdev)
{
return test_bit(__VXGE_STATE_CARD_UP, &vdev->state);
}
static inline void VXGE_COMPLETE_VPATH_TX(struct vxge_fifo *fifo)
{
struct sk_buff **skb_ptr = NULL;
struct sk_buff **temp;
#define NR_SKB_COMPLETED 128
struct sk_buff *completed[NR_SKB_COMPLETED];
int more;
do {
more = 0;
skb_ptr = completed;
if (__netif_tx_trylock(fifo->txq)) {
vxge_hw_vpath_poll_tx(fifo->handle, &skb_ptr,
NR_SKB_COMPLETED, &more);
__netif_tx_unlock(fifo->txq);
}
for (temp = completed; temp != skb_ptr; temp++)
dev_kfree_skb_irq(*temp);
} while (more);
}
static inline void VXGE_COMPLETE_ALL_TX(struct vxgedev *vdev)
{
int i;
for (i = 0; i < vdev->no_of_vpath; i++)
VXGE_COMPLETE_VPATH_TX(&vdev->vpaths[i].fifo);
}
static inline void VXGE_COMPLETE_ALL_RX(struct vxgedev *vdev)
{
int i;
struct vxge_ring *ring;
for (i = 0; i < vdev->no_of_vpath; i++) {
ring = &vdev->vpaths[i].ring;
vxge_hw_vpath_poll_rx(ring->handle);
}
}
static void vxge_callback_link_up(struct __vxge_hw_device *hldev)
{
struct net_device *dev = hldev->ndev;
struct vxgedev *vdev = netdev_priv(dev);
vxge_debug_entryexit(VXGE_TRACE, "%s: %s:%d",
vdev->ndev->name, __func__, __LINE__);
netdev_notice(vdev->ndev, "Link Up\n");
vdev->stats.link_up++;
netif_carrier_on(vdev->ndev);
netif_tx_wake_all_queues(vdev->ndev);
vxge_debug_entryexit(VXGE_TRACE,
"%s: %s:%d Exiting...", vdev->ndev->name, __func__, __LINE__);
}
static void vxge_callback_link_down(struct __vxge_hw_device *hldev)
{
struct net_device *dev = hldev->ndev;
struct vxgedev *vdev = netdev_priv(dev);
vxge_debug_entryexit(VXGE_TRACE,
"%s: %s:%d", vdev->ndev->name, __func__, __LINE__);
netdev_notice(vdev->ndev, "Link Down\n");
vdev->stats.link_down++;
netif_carrier_off(vdev->ndev);
netif_tx_stop_all_queues(vdev->ndev);
vxge_debug_entryexit(VXGE_TRACE,
"%s: %s:%d Exiting...", vdev->ndev->name, __func__, __LINE__);
}
static struct sk_buff *
vxge_rx_alloc(void *dtrh, struct vxge_ring *ring, const int skb_size)
{
struct net_device *dev;
struct sk_buff *skb;
struct vxge_rx_priv *rx_priv;
dev = ring->ndev;
vxge_debug_entryexit(VXGE_TRACE, "%s: %s:%d",
ring->ndev->name, __func__, __LINE__);
rx_priv = vxge_hw_ring_rxd_private_get(dtrh);
skb = netdev_alloc_skb(dev, skb_size +
VXGE_HW_HEADER_ETHERNET_II_802_3_ALIGN);
if (skb == NULL) {
vxge_debug_mem(VXGE_ERR,
"%s: out of memory to allocate SKB", dev->name);
ring->stats.skb_alloc_fail++;
return NULL;
}
vxge_debug_mem(VXGE_TRACE,
"%s: %s:%d Skb : 0x%p", ring->ndev->name,
__func__, __LINE__, skb);
skb_reserve(skb, VXGE_HW_HEADER_ETHERNET_II_802_3_ALIGN);
rx_priv->skb = skb;
rx_priv->skb_data = NULL;
rx_priv->data_size = skb_size;
vxge_debug_entryexit(VXGE_TRACE,
"%s: %s:%d Exiting...", ring->ndev->name, __func__, __LINE__);
return skb;
}
static int vxge_rx_map(void *dtrh, struct vxge_ring *ring)
{
struct vxge_rx_priv *rx_priv;
dma_addr_t dma_addr;
vxge_debug_entryexit(VXGE_TRACE, "%s: %s:%d",
ring->ndev->name, __func__, __LINE__);
rx_priv = vxge_hw_ring_rxd_private_get(dtrh);
rx_priv->skb_data = rx_priv->skb->data;
dma_addr = pci_map_single(ring->pdev, rx_priv->skb_data,
rx_priv->data_size, PCI_DMA_FROMDEVICE);
if (unlikely(pci_dma_mapping_error(ring->pdev, dma_addr))) {
ring->stats.pci_map_fail++;
return -EIO;
}
vxge_debug_mem(VXGE_TRACE,
"%s: %s:%d 1 buffer mode dma_addr = 0x%llx",
ring->ndev->name, __func__, __LINE__,
(unsigned long long)dma_addr);
vxge_hw_ring_rxd_1b_set(dtrh, dma_addr, rx_priv->data_size);
rx_priv->data_dma = dma_addr;
vxge_debug_entryexit(VXGE_TRACE,
"%s: %s:%d Exiting...", ring->ndev->name, __func__, __LINE__);
return 0;
}
static enum vxge_hw_status
vxge_rx_initial_replenish(void *dtrh, void *userdata)
{
struct vxge_ring *ring = (struct vxge_ring *)userdata;
struct vxge_rx_priv *rx_priv;
vxge_debug_entryexit(VXGE_TRACE, "%s: %s:%d",
ring->ndev->name, __func__, __LINE__);
if (vxge_rx_alloc(dtrh, ring,
VXGE_LL_MAX_FRAME_SIZE(ring->ndev)) == NULL)
return VXGE_HW_FAIL;
if (vxge_rx_map(dtrh, ring)) {
rx_priv = vxge_hw_ring_rxd_private_get(dtrh);
dev_kfree_skb(rx_priv->skb);
return VXGE_HW_FAIL;
}
vxge_debug_entryexit(VXGE_TRACE,
"%s: %s:%d Exiting...", ring->ndev->name, __func__, __LINE__);
return VXGE_HW_OK;
}
static inline void
vxge_rx_complete(struct vxge_ring *ring, struct sk_buff *skb, u16 vlan,
int pkt_length, struct vxge_hw_ring_rxd_info *ext_info)
{
vxge_debug_entryexit(VXGE_TRACE, "%s: %s:%d",
ring->ndev->name, __func__, __LINE__);
skb_record_rx_queue(skb, ring->driver_id);
skb->protocol = eth_type_trans(skb, ring->ndev);
u64_stats_update_begin(&ring->stats.syncp);
ring->stats.rx_frms++;
ring->stats.rx_bytes += pkt_length;
if (skb->pkt_type == PACKET_MULTICAST)
ring->stats.rx_mcast++;
u64_stats_update_end(&ring->stats.syncp);
vxge_debug_rx(VXGE_TRACE,
"%s: %s:%d skb protocol = %d",
ring->ndev->name, __func__, __LINE__, skb->protocol);
if (ext_info->vlan &&
ring->vlan_tag_strip == VXGE_HW_VPATH_RPA_STRIP_VLAN_TAG_ENABLE)
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q), ext_info->vlan);
napi_gro_receive(ring->napi_p, skb);
vxge_debug_entryexit(VXGE_TRACE,
"%s: %s:%d Exiting...", ring->ndev->name, __func__, __LINE__);
}
static inline void vxge_re_pre_post(void *dtr, struct vxge_ring *ring,
struct vxge_rx_priv *rx_priv)
{
pci_dma_sync_single_for_device(ring->pdev,
rx_priv->data_dma, rx_priv->data_size, PCI_DMA_FROMDEVICE);
vxge_hw_ring_rxd_1b_set(dtr, rx_priv->data_dma, rx_priv->data_size);
vxge_hw_ring_rxd_pre_post(ring->handle, dtr);
}
static inline void vxge_post(int *dtr_cnt, void **first_dtr,
void *post_dtr, struct __vxge_hw_ring *ringh)
{
int dtr_count = *dtr_cnt;
if ((*dtr_cnt % VXGE_HW_RXSYNC_FREQ_CNT) == 0) {
if (*first_dtr)
vxge_hw_ring_rxd_post_post_wmb(ringh, *first_dtr);
*first_dtr = post_dtr;
} else
vxge_hw_ring_rxd_post_post(ringh, post_dtr);
dtr_count++;
*dtr_cnt = dtr_count;
}
static enum vxge_hw_status
vxge_rx_1b_compl(struct __vxge_hw_ring *ringh, void *dtr,
u8 t_code, void *userdata)
{
struct vxge_ring *ring = (struct vxge_ring *)userdata;
struct net_device *dev = ring->ndev;
unsigned int dma_sizes;
void *first_dtr = NULL;
int dtr_cnt = 0;
int data_size;
dma_addr_t data_dma;
int pkt_length;
struct sk_buff *skb;
struct vxge_rx_priv *rx_priv;
struct vxge_hw_ring_rxd_info ext_info;
vxge_debug_entryexit(VXGE_TRACE, "%s: %s:%d",
ring->ndev->name, __func__, __LINE__);
do {
prefetch((char *)dtr + L1_CACHE_BYTES);
rx_priv = vxge_hw_ring_rxd_private_get(dtr);
skb = rx_priv->skb;
data_size = rx_priv->data_size;
data_dma = rx_priv->data_dma;
prefetch(rx_priv->skb_data);
vxge_debug_rx(VXGE_TRACE,
"%s: %s:%d skb = 0x%p",
ring->ndev->name, __func__, __LINE__, skb);
vxge_hw_ring_rxd_1b_get(ringh, dtr, &dma_sizes);
pkt_length = dma_sizes;
pkt_length -= ETH_FCS_LEN;
vxge_debug_rx(VXGE_TRACE,
"%s: %s:%d Packet Length = %d",
ring->ndev->name, __func__, __LINE__, pkt_length);
vxge_hw_ring_rxd_1b_info_get(ringh, dtr, &ext_info);
vxge_assert(skb);
prefetch((char *)skb + L1_CACHE_BYTES);
if (unlikely(t_code)) {
if (vxge_hw_ring_handle_tcode(ringh, dtr, t_code) !=
VXGE_HW_OK) {
ring->stats.rx_errors++;
vxge_debug_rx(VXGE_TRACE,
"%s: %s :%d Rx T_code is %d",
ring->ndev->name, __func__,
__LINE__, t_code);
vxge_re_pre_post(dtr, ring, rx_priv);
vxge_post(&dtr_cnt, &first_dtr, dtr, ringh);
ring->stats.rx_dropped++;
continue;
}
}
if (pkt_length > VXGE_LL_RX_COPY_THRESHOLD) {
if (vxge_rx_alloc(dtr, ring, data_size) != NULL) {
if (!vxge_rx_map(dtr, ring)) {
skb_put(skb, pkt_length);
pci_unmap_single(ring->pdev, data_dma,
data_size, PCI_DMA_FROMDEVICE);
vxge_hw_ring_rxd_pre_post(ringh, dtr);
vxge_post(&dtr_cnt, &first_dtr, dtr,
ringh);
} else {
dev_kfree_skb(rx_priv->skb);
rx_priv->skb = skb;
rx_priv->data_size = data_size;
vxge_re_pre_post(dtr, ring, rx_priv);
vxge_post(&dtr_cnt, &first_dtr, dtr,
ringh);
ring->stats.rx_dropped++;
break;
}
} else {
vxge_re_pre_post(dtr, ring, rx_priv);
vxge_post(&dtr_cnt, &first_dtr, dtr, ringh);
ring->stats.rx_dropped++;
break;
}
} else {
struct sk_buff *skb_up;
skb_up = netdev_alloc_skb(dev, pkt_length +
VXGE_HW_HEADER_ETHERNET_II_802_3_ALIGN);
if (skb_up != NULL) {
skb_reserve(skb_up,
VXGE_HW_HEADER_ETHERNET_II_802_3_ALIGN);
pci_dma_sync_single_for_cpu(ring->pdev,
data_dma, data_size,
PCI_DMA_FROMDEVICE);
vxge_debug_mem(VXGE_TRACE,
"%s: %s:%d skb_up = %p",
ring->ndev->name, __func__,
__LINE__, skb);
memcpy(skb_up->data, skb->data, pkt_length);
vxge_re_pre_post(dtr, ring, rx_priv);
vxge_post(&dtr_cnt, &first_dtr, dtr,
ringh);
skb = skb_up;
skb_put(skb, pkt_length);
} else {
vxge_re_pre_post(dtr, ring, rx_priv);
vxge_post(&dtr_cnt, &first_dtr, dtr, ringh);
vxge_debug_rx(VXGE_ERR,
"%s: vxge_rx_1b_compl: out of "
"memory", dev->name);
ring->stats.skb_alloc_fail++;
break;
}
}
if ((ext_info.proto & VXGE_HW_FRAME_PROTO_TCP_OR_UDP) &&
!(ext_info.proto & VXGE_HW_FRAME_PROTO_IP_FRAG) &&
(dev->features & NETIF_F_RXCSUM) &&
ext_info.l3_cksum == VXGE_HW_L3_CKSUM_OK &&
ext_info.l4_cksum == VXGE_HW_L4_CKSUM_OK)
skb->ip_summed = CHECKSUM_UNNECESSARY;
else
skb_checksum_none_assert(skb);
if (ring->rx_hwts) {
struct skb_shared_hwtstamps *skb_hwts;
u32 ns = *(u32 *)(skb->head + pkt_length);
skb_hwts = skb_hwtstamps(skb);
skb_hwts->hwtstamp = ns_to_ktime(ns);
skb_hwts->syststamp.tv64 = 0;
}
if (ext_info.rth_value)
skb->rxhash = ext_info.rth_value;
vxge_rx_complete(ring, skb, ext_info.vlan,
pkt_length, &ext_info);
ring->budget--;
ring->pkts_processed++;
if (!ring->budget)
break;
} while (vxge_hw_ring_rxd_next_completed(ringh, &dtr,
&t_code) == VXGE_HW_OK);
if (first_dtr)
vxge_hw_ring_rxd_post_post_wmb(ringh, first_dtr);
vxge_debug_entryexit(VXGE_TRACE,
"%s:%d Exiting...",
__func__, __LINE__);
return VXGE_HW_OK;
}
static enum vxge_hw_status
vxge_xmit_compl(struct __vxge_hw_fifo *fifo_hw, void *dtr,
enum vxge_hw_fifo_tcode t_code, void *userdata,
struct sk_buff ***skb_ptr, int nr_skb, int *more)
{
struct vxge_fifo *fifo = (struct vxge_fifo *)userdata;
struct sk_buff *skb, **done_skb = *skb_ptr;
int pkt_cnt = 0;
vxge_debug_entryexit(VXGE_TRACE,
"%s:%d Entered....", __func__, __LINE__);
do {
int frg_cnt;
skb_frag_t *frag;
int i = 0, j;
struct vxge_tx_priv *txd_priv =
vxge_hw_fifo_txdl_private_get(dtr);
skb = txd_priv->skb;
frg_cnt = skb_shinfo(skb)->nr_frags;
frag = &skb_shinfo(skb)->frags[0];
vxge_debug_tx(VXGE_TRACE,
"%s: %s:%d fifo_hw = %p dtr = %p "
"tcode = 0x%x", fifo->ndev->name, __func__,
__LINE__, fifo_hw, dtr, t_code);
vxge_assert(skb);
vxge_debug_tx(VXGE_TRACE,
"%s: %s:%d skb = %p itxd_priv = %p frg_cnt = %d",
fifo->ndev->name, __func__, __LINE__,
skb, txd_priv, frg_cnt);
if (unlikely(t_code)) {
fifo->stats.tx_errors++;
vxge_debug_tx(VXGE_ERR,
"%s: tx: dtr %p completed due to "
"error t_code %01x", fifo->ndev->name,
dtr, t_code);
vxge_hw_fifo_handle_tcode(fifo_hw, dtr, t_code);
}
pci_unmap_single(fifo->pdev, txd_priv->dma_buffers[i++],
skb_headlen(skb), PCI_DMA_TODEVICE);
for (j = 0; j < frg_cnt; j++) {
pci_unmap_page(fifo->pdev,
txd_priv->dma_buffers[i++],
skb_frag_size(frag), PCI_DMA_TODEVICE);
frag += 1;
}
vxge_hw_fifo_txdl_free(fifo_hw, dtr);
u64_stats_update_begin(&fifo->stats.syncp);
fifo->stats.tx_frms++;
fifo->stats.tx_bytes += skb->len;
u64_stats_update_end(&fifo->stats.syncp);
*done_skb++ = skb;
if (--nr_skb <= 0) {
*more = 1;
break;
}
pkt_cnt++;
if (pkt_cnt > fifo->indicate_max_pkts)
break;
} while (vxge_hw_fifo_txdl_next_completed(fifo_hw,
&dtr, &t_code) == VXGE_HW_OK);
*skb_ptr = done_skb;
if (netif_tx_queue_stopped(fifo->txq))
netif_tx_wake_queue(fifo->txq);
vxge_debug_entryexit(VXGE_TRACE,
"%s: %s:%d Exiting...",
fifo->ndev->name, __func__, __LINE__);
return VXGE_HW_OK;
}
static u32 vxge_get_vpath_no(struct vxgedev *vdev, struct sk_buff *skb)
{
u16 queue_len, counter = 0;
if (skb->protocol == htons(ETH_P_IP)) {
struct iphdr *ip;
struct tcphdr *th;
ip = ip_hdr(skb);
if (!ip_is_fragment(ip)) {
th = (struct tcphdr *)(((unsigned char *)ip) +
ip->ihl*4);
queue_len = vdev->no_of_vpath;
counter = (ntohs(th->source) +
ntohs(th->dest)) &
vdev->vpath_selector[queue_len - 1];
if (counter >= queue_len)
counter = queue_len - 1;
}
}
return counter;
}
static enum vxge_hw_status vxge_search_mac_addr_in_list(
struct vxge_vpath *vpath, u64 del_mac)
{
struct list_head *entry, *next;
list_for_each_safe(entry, next, &vpath->mac_addr_list) {
if (((struct vxge_mac_addrs *)entry)->macaddr == del_mac)
return TRUE;
}
return FALSE;
}
static int vxge_mac_list_add(struct vxge_vpath *vpath, struct macInfo *mac)
{
struct vxge_mac_addrs *new_mac_entry;
u8 *mac_address = NULL;
if (vpath->mac_addr_cnt >= VXGE_MAX_LEARN_MAC_ADDR_CNT)
return TRUE;
new_mac_entry = kzalloc(sizeof(struct vxge_mac_addrs), GFP_ATOMIC);
if (!new_mac_entry) {
vxge_debug_mem(VXGE_ERR,
"%s: memory allocation failed",
VXGE_DRIVER_NAME);
return FALSE;
}
list_add(&new_mac_entry->item, &vpath->mac_addr_list);
mac_address = (u8 *)&new_mac_entry->macaddr;
memcpy(mac_address, mac->macaddr, ETH_ALEN);
new_mac_entry->state = mac->state;
vpath->mac_addr_cnt++;
if (is_multicast_ether_addr(mac->macaddr))
vpath->mcast_addr_cnt++;
return TRUE;
}
static enum vxge_hw_status
vxge_add_mac_addr(struct vxgedev *vdev, struct macInfo *mac)
{
enum vxge_hw_status status = VXGE_HW_OK;
struct vxge_vpath *vpath;
enum vxge_hw_vpath_mac_addr_add_mode duplicate_mode;
if (is_multicast_ether_addr(mac->macaddr))
duplicate_mode = VXGE_HW_VPATH_MAC_ADDR_ADD_DUPLICATE;
else
duplicate_mode = VXGE_HW_VPATH_MAC_ADDR_REPLACE_DUPLICATE;
vpath = &vdev->vpaths[mac->vpath_no];
status = vxge_hw_vpath_mac_addr_add(vpath->handle, mac->macaddr,
mac->macmask, duplicate_mode);
if (status != VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR,
"DA config add entry failed for vpath:%d",
vpath->device_id);
} else
if (FALSE == vxge_mac_list_add(vpath, mac))
status = -EPERM;
return status;
}
static int vxge_learn_mac(struct vxgedev *vdev, u8 *mac_header)
{
struct macInfo mac_info;
u8 *mac_address = NULL;
u64 mac_addr = 0, vpath_vector = 0;
int vpath_idx = 0;
enum vxge_hw_status status = VXGE_HW_OK;
struct vxge_vpath *vpath = NULL;
struct __vxge_hw_device *hldev;
hldev = pci_get_drvdata(vdev->pdev);
mac_address = (u8 *)&mac_addr;
memcpy(mac_address, mac_header, ETH_ALEN);
for (vpath_idx = 0; vpath_idx < vdev->no_of_vpath; vpath_idx++) {
vpath = &vdev->vpaths[vpath_idx];
if (vxge_search_mac_addr_in_list(vpath, mac_addr))
return vpath_idx;
}
memset(&mac_info, 0, sizeof(struct macInfo));
memcpy(mac_info.macaddr, mac_header, ETH_ALEN);
for (vpath_idx = 0; vpath_idx < vdev->no_of_vpath; vpath_idx++) {
vpath = &vdev->vpaths[vpath_idx];
if (vpath->mac_addr_cnt < vpath->max_mac_addr_cnt) {
mac_info.vpath_no = vpath_idx;
mac_info.state = VXGE_LL_MAC_ADDR_IN_DA_TABLE;
status = vxge_add_mac_addr(vdev, &mac_info);
if (status != VXGE_HW_OK)
return -EPERM;
return vpath_idx;
}
}
mac_info.state = VXGE_LL_MAC_ADDR_IN_LIST;
vpath_idx = 0;
mac_info.vpath_no = vpath_idx;
vpath = &vdev->vpaths[vpath_idx];
if (vpath->mac_addr_cnt > vpath->max_mac_addr_cnt) {
if (FALSE == vxge_mac_list_add(vpath, &mac_info))
return -EPERM;
return vpath_idx;
}
vpath_vector = vxge_mBIT(vpath->device_id);
status = vxge_hw_mgmt_reg_write(vpath->vdev->devh,
vxge_hw_mgmt_reg_type_mrpcim,
0,
(ulong)offsetof(
struct vxge_hw_mrpcim_reg,
rts_mgr_cbasin_cfg),
vpath_vector);
if (status != VXGE_HW_OK) {
vxge_debug_tx(VXGE_ERR,
"%s: Unable to set the vpath-%d in catch-basin mode",
VXGE_DRIVER_NAME, vpath->device_id);
return -EPERM;
}
if (FALSE == vxge_mac_list_add(vpath, &mac_info))
return -EPERM;
return vpath_idx;
}
static netdev_tx_t
vxge_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct vxge_fifo *fifo = NULL;
void *dtr_priv;
void *dtr = NULL;
struct vxgedev *vdev = NULL;
enum vxge_hw_status status;
int frg_cnt, first_frg_len;
skb_frag_t *frag;
int i = 0, j = 0, avail;
u64 dma_pointer;
struct vxge_tx_priv *txdl_priv = NULL;
struct __vxge_hw_fifo *fifo_hw;
int offload_type;
int vpath_no = 0;
vxge_debug_entryexit(VXGE_TRACE, "%s: %s:%d",
dev->name, __func__, __LINE__);
if (unlikely(skb->len <= 0)) {
vxge_debug_tx(VXGE_ERR,
"%s: Buffer has no data..", dev->name);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
vdev = netdev_priv(dev);
if (unlikely(!is_vxge_card_up(vdev))) {
vxge_debug_tx(VXGE_ERR,
"%s: vdev not initialized", dev->name);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
if (vdev->config.addr_learn_en) {
vpath_no = vxge_learn_mac(vdev, skb->data + ETH_ALEN);
if (vpath_no == -EPERM) {
vxge_debug_tx(VXGE_ERR,
"%s: Failed to store the mac address",
dev->name);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
}
if (vdev->config.tx_steering_type == TX_MULTIQ_STEERING)
vpath_no = skb_get_queue_mapping(skb);
else if (vdev->config.tx_steering_type == TX_PORT_STEERING)
vpath_no = vxge_get_vpath_no(vdev, skb);
vxge_debug_tx(VXGE_TRACE, "%s: vpath_no= %d", dev->name, vpath_no);
if (vpath_no >= vdev->no_of_vpath)
vpath_no = 0;
fifo = &vdev->vpaths[vpath_no].fifo;
fifo_hw = fifo->handle;
if (netif_tx_queue_stopped(fifo->txq))
return NETDEV_TX_BUSY;
avail = vxge_hw_fifo_free_txdl_count_get(fifo_hw);
if (avail == 0) {
vxge_debug_tx(VXGE_ERR,
"%s: No free TXDs available", dev->name);
fifo->stats.txd_not_free++;
goto _exit0;
}
if (avail == 1)
netif_tx_stop_queue(fifo->txq);
status = vxge_hw_fifo_txdl_reserve(fifo_hw, &dtr, &dtr_priv);
if (unlikely(status != VXGE_HW_OK)) {
vxge_debug_tx(VXGE_ERR,
"%s: Out of descriptors .", dev->name);
fifo->stats.txd_out_of_desc++;
goto _exit0;
}
vxge_debug_tx(VXGE_TRACE,
"%s: %s:%d fifo_hw = %p dtr = %p dtr_priv = %p",
dev->name, __func__, __LINE__,
fifo_hw, dtr, dtr_priv);
if (vlan_tx_tag_present(skb)) {
u16 vlan_tag = vlan_tx_tag_get(skb);
vxge_hw_fifo_txdl_vlan_set(dtr, vlan_tag);
}
first_frg_len = skb_headlen(skb);
dma_pointer = pci_map_single(fifo->pdev, skb->data, first_frg_len,
PCI_DMA_TODEVICE);
if (unlikely(pci_dma_mapping_error(fifo->pdev, dma_pointer))) {
vxge_hw_fifo_txdl_free(fifo_hw, dtr);
fifo->stats.pci_map_fail++;
goto _exit0;
}
txdl_priv = vxge_hw_fifo_txdl_private_get(dtr);
txdl_priv->skb = skb;
txdl_priv->dma_buffers[j] = dma_pointer;
frg_cnt = skb_shinfo(skb)->nr_frags;
vxge_debug_tx(VXGE_TRACE,
"%s: %s:%d skb = %p txdl_priv = %p "
"frag_cnt = %d dma_pointer = 0x%llx", dev->name,
__func__, __LINE__, skb, txdl_priv,
frg_cnt, (unsigned long long)dma_pointer);
vxge_hw_fifo_txdl_buffer_set(fifo_hw, dtr, j++, dma_pointer,
first_frg_len);
frag = &skb_shinfo(skb)->frags[0];
for (i = 0; i < frg_cnt; i++) {
if (!skb_frag_size(frag))
continue;
dma_pointer = (u64)skb_frag_dma_map(&fifo->pdev->dev, frag,
0, skb_frag_size(frag),
DMA_TO_DEVICE);
if (unlikely(dma_mapping_error(&fifo->pdev->dev, dma_pointer)))
goto _exit2;
vxge_debug_tx(VXGE_TRACE,
"%s: %s:%d frag = %d dma_pointer = 0x%llx",
dev->name, __func__, __LINE__, i,
(unsigned long long)dma_pointer);
txdl_priv->dma_buffers[j] = dma_pointer;
vxge_hw_fifo_txdl_buffer_set(fifo_hw, dtr, j++, dma_pointer,
skb_frag_size(frag));
frag += 1;
}
offload_type = vxge_offload_type(skb);
if (offload_type & (SKB_GSO_TCPV4 | SKB_GSO_TCPV6)) {
int mss = vxge_tcp_mss(skb);
if (mss) {
vxge_debug_tx(VXGE_TRACE, "%s: %s:%d mss = %d",
dev->name, __func__, __LINE__, mss);
vxge_hw_fifo_txdl_mss_set(dtr, mss);
} else {
vxge_assert(skb->len <=
dev->mtu + VXGE_HW_MAC_HEADER_MAX_SIZE);
vxge_assert(0);
goto _exit1;
}
}
if (skb->ip_summed == CHECKSUM_PARTIAL)
vxge_hw_fifo_txdl_cksum_set_bits(dtr,
VXGE_HW_FIFO_TXD_TX_CKO_IPV4_EN |
VXGE_HW_FIFO_TXD_TX_CKO_TCP_EN |
VXGE_HW_FIFO_TXD_TX_CKO_UDP_EN);
vxge_hw_fifo_txdl_post(fifo_hw, dtr);
vxge_debug_entryexit(VXGE_TRACE, "%s: %s:%d Exiting...",
dev->name, __func__, __LINE__);
return NETDEV_TX_OK;
_exit2:
vxge_debug_tx(VXGE_TRACE, "%s: pci_map_page failed", dev->name);
_exit1:
j = 0;
frag = &skb_shinfo(skb)->frags[0];
pci_unmap_single(fifo->pdev, txdl_priv->dma_buffers[j++],
skb_headlen(skb), PCI_DMA_TODEVICE);
for (; j < i; j++) {
pci_unmap_page(fifo->pdev, txdl_priv->dma_buffers[j],
skb_frag_size(frag), PCI_DMA_TODEVICE);
frag += 1;
}
vxge_hw_fifo_txdl_free(fifo_hw, dtr);
_exit0:
netif_tx_stop_queue(fifo->txq);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static void
vxge_rx_term(void *dtrh, enum vxge_hw_rxd_state state, void *userdata)
{
struct vxge_ring *ring = (struct vxge_ring *)userdata;
struct vxge_rx_priv *rx_priv =
vxge_hw_ring_rxd_private_get(dtrh);
vxge_debug_entryexit(VXGE_TRACE, "%s: %s:%d",
ring->ndev->name, __func__, __LINE__);
if (state != VXGE_HW_RXD_STATE_POSTED)
return;
pci_unmap_single(ring->pdev, rx_priv->data_dma,
rx_priv->data_size, PCI_DMA_FROMDEVICE);
dev_kfree_skb(rx_priv->skb);
rx_priv->skb_data = NULL;
vxge_debug_entryexit(VXGE_TRACE,
"%s: %s:%d Exiting...",
ring->ndev->name, __func__, __LINE__);
}
static void
vxge_tx_term(void *dtrh, enum vxge_hw_txdl_state state, void *userdata)
{
struct vxge_fifo *fifo = (struct vxge_fifo *)userdata;
skb_frag_t *frag;
int i = 0, j, frg_cnt;
struct vxge_tx_priv *txd_priv = vxge_hw_fifo_txdl_private_get(dtrh);
struct sk_buff *skb = txd_priv->skb;
vxge_debug_entryexit(VXGE_TRACE, "%s:%d", __func__, __LINE__);
if (state != VXGE_HW_TXDL_STATE_POSTED)
return;
vxge_assert(skb);
frg_cnt = skb_shinfo(skb)->nr_frags;
frag = &skb_shinfo(skb)->frags[0];
pci_unmap_single(fifo->pdev, txd_priv->dma_buffers[i++],
skb_headlen(skb), PCI_DMA_TODEVICE);
for (j = 0; j < frg_cnt; j++) {
pci_unmap_page(fifo->pdev, txd_priv->dma_buffers[i++],
skb_frag_size(frag), PCI_DMA_TODEVICE);
frag += 1;
}
dev_kfree_skb(skb);
vxge_debug_entryexit(VXGE_TRACE,
"%s:%d Exiting...", __func__, __LINE__);
}
static int vxge_mac_list_del(struct vxge_vpath *vpath, struct macInfo *mac)
{
struct list_head *entry, *next;
u64 del_mac = 0;
u8 *mac_address = (u8 *) (&del_mac);
memcpy(mac_address, mac->macaddr, ETH_ALEN);
list_for_each_safe(entry, next, &vpath->mac_addr_list) {
if (((struct vxge_mac_addrs *)entry)->macaddr == del_mac) {
list_del(entry);
kfree((struct vxge_mac_addrs *)entry);
vpath->mac_addr_cnt--;
if (is_multicast_ether_addr(mac->macaddr))
vpath->mcast_addr_cnt--;
return TRUE;
}
}
return FALSE;
}
static enum vxge_hw_status
vxge_del_mac_addr(struct vxgedev *vdev, struct macInfo *mac)
{
enum vxge_hw_status status = VXGE_HW_OK;
struct vxge_vpath *vpath;
vpath = &vdev->vpaths[mac->vpath_no];
status = vxge_hw_vpath_mac_addr_delete(vpath->handle, mac->macaddr,
mac->macmask);
if (status != VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR,
"DA config delete entry failed for vpath:%d",
vpath->device_id);
} else
vxge_mac_list_del(vpath, mac);
return status;
}
static void vxge_set_multicast(struct net_device *dev)
{
struct netdev_hw_addr *ha;
struct vxgedev *vdev;
int i, mcast_cnt = 0;
struct __vxge_hw_device *hldev;
struct vxge_vpath *vpath;
enum vxge_hw_status status = VXGE_HW_OK;
struct macInfo mac_info;
int vpath_idx = 0;
struct vxge_mac_addrs *mac_entry;
struct list_head *list_head;
struct list_head *entry, *next;
u8 *mac_address = NULL;
vxge_debug_entryexit(VXGE_TRACE,
"%s:%d", __func__, __LINE__);
vdev = netdev_priv(dev);
hldev = vdev->devh;
if (unlikely(!is_vxge_card_up(vdev)))
return;
if ((dev->flags & IFF_ALLMULTI) && (!vdev->all_multi_flg)) {
for (i = 0; i < vdev->no_of_vpath; i++) {
vpath = &vdev->vpaths[i];
vxge_assert(vpath->is_open);
status = vxge_hw_vpath_mcast_enable(vpath->handle);
if (status != VXGE_HW_OK)
vxge_debug_init(VXGE_ERR, "failed to enable "
"multicast, status %d", status);
vdev->all_multi_flg = 1;
}
} else if (!(dev->flags & IFF_ALLMULTI) && (vdev->all_multi_flg)) {
for (i = 0; i < vdev->no_of_vpath; i++) {
vpath = &vdev->vpaths[i];
vxge_assert(vpath->is_open);
status = vxge_hw_vpath_mcast_disable(vpath->handle);
if (status != VXGE_HW_OK)
vxge_debug_init(VXGE_ERR, "failed to disable "
"multicast, status %d", status);
vdev->all_multi_flg = 0;
}
}
if (!vdev->config.addr_learn_en) {
for (i = 0; i < vdev->no_of_vpath; i++) {
vpath = &vdev->vpaths[i];
vxge_assert(vpath->is_open);
if (dev->flags & IFF_PROMISC)
status = vxge_hw_vpath_promisc_enable(
vpath->handle);
else
status = vxge_hw_vpath_promisc_disable(
vpath->handle);
if (status != VXGE_HW_OK)
vxge_debug_init(VXGE_ERR, "failed to %s promisc"
", status %d", dev->flags&IFF_PROMISC ?
"enable" : "disable", status);
}
}
memset(&mac_info, 0, sizeof(struct macInfo));
if ((!vdev->all_multi_flg) && netdev_mc_count(dev)) {
mcast_cnt = vdev->vpaths[0].mcast_addr_cnt;
list_head = &vdev->vpaths[0].mac_addr_list;
if ((netdev_mc_count(dev) +
(vdev->vpaths[0].mac_addr_cnt - mcast_cnt)) >
vdev->vpaths[0].max_mac_addr_cnt)
goto _set_all_mcast;
for (i = 0; i < mcast_cnt; i++) {
list_for_each_safe(entry, next, list_head) {
mac_entry = (struct vxge_mac_addrs *)entry;
mac_address = (u8 *)&mac_entry->macaddr;
memcpy(mac_info.macaddr, mac_address, ETH_ALEN);
if (is_multicast_ether_addr(mac_info.macaddr)) {
for (vpath_idx = 0; vpath_idx <
vdev->no_of_vpath;
vpath_idx++) {
mac_info.vpath_no = vpath_idx;
status = vxge_del_mac_addr(
vdev,
&mac_info);
}
}
}
}
netdev_for_each_mc_addr(ha, dev) {
memcpy(mac_info.macaddr, ha->addr, ETH_ALEN);
for (vpath_idx = 0; vpath_idx < vdev->no_of_vpath;
vpath_idx++) {
mac_info.vpath_no = vpath_idx;
mac_info.state = VXGE_LL_MAC_ADDR_IN_DA_TABLE;
status = vxge_add_mac_addr(vdev, &mac_info);
if (status != VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR,
"%s:%d Setting individual"
"multicast address failed",
__func__, __LINE__);
goto _set_all_mcast;
}
}
}
return;
_set_all_mcast:
mcast_cnt = vdev->vpaths[0].mcast_addr_cnt;
for (i = 0; i < mcast_cnt; i++) {
list_for_each_safe(entry, next, list_head) {
mac_entry = (struct vxge_mac_addrs *)entry;
mac_address = (u8 *)&mac_entry->macaddr;
memcpy(mac_info.macaddr, mac_address, ETH_ALEN);
if (is_multicast_ether_addr(mac_info.macaddr))
break;
}
for (vpath_idx = 0; vpath_idx < vdev->no_of_vpath;
vpath_idx++) {
mac_info.vpath_no = vpath_idx;
status = vxge_del_mac_addr(vdev, &mac_info);
}
}
for (i = 0; i < vdev->no_of_vpath; i++) {
vpath = &vdev->vpaths[i];
vxge_assert(vpath->is_open);
status = vxge_hw_vpath_mcast_enable(vpath->handle);
if (status != VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR,
"%s:%d Enabling all multicasts failed",
__func__, __LINE__);
}
vdev->all_multi_flg = 1;
}
dev->flags |= IFF_ALLMULTI;
}
vxge_debug_entryexit(VXGE_TRACE,
"%s:%d Exiting...", __func__, __LINE__);
}
static int vxge_set_mac_addr(struct net_device *dev, void *p)
{
struct sockaddr *addr = p;
struct vxgedev *vdev;
struct __vxge_hw_device *hldev;
enum vxge_hw_status status = VXGE_HW_OK;
struct macInfo mac_info_new, mac_info_old;
int vpath_idx = 0;
vxge_debug_entryexit(VXGE_TRACE, "%s:%d", __func__, __LINE__);
vdev = netdev_priv(dev);
hldev = vdev->devh;
if (!is_valid_ether_addr(addr->sa_data))
return -EINVAL;
memset(&mac_info_new, 0, sizeof(struct macInfo));
memset(&mac_info_old, 0, sizeof(struct macInfo));
vxge_debug_entryexit(VXGE_TRACE, "%s:%d Exiting...",
__func__, __LINE__);
memcpy(mac_info_old.macaddr, dev->dev_addr, dev->addr_len);
memcpy(mac_info_new.macaddr, addr->sa_data, dev->addr_len);
for (vpath_idx = 0; vpath_idx < vdev->no_of_vpath; vpath_idx++) {
struct vxge_vpath *vpath = &vdev->vpaths[vpath_idx];
if (!vpath->is_open) {
vxge_mac_list_del(vpath, &mac_info_old);
vxge_mac_list_add(vpath, &mac_info_new);
continue;
}
mac_info_old.vpath_no = vpath_idx;
status = vxge_del_mac_addr(vdev, &mac_info_old);
}
if (unlikely(!is_vxge_card_up(vdev))) {
memcpy(dev->dev_addr, addr->sa_data, dev->addr_len);
return VXGE_HW_OK;
}
for (vpath_idx = 0; vpath_idx < vdev->no_of_vpath; vpath_idx++) {
mac_info_new.vpath_no = vpath_idx;
mac_info_new.state = VXGE_LL_MAC_ADDR_IN_DA_TABLE;
status = vxge_add_mac_addr(vdev, &mac_info_new);
if (status != VXGE_HW_OK)
return -EINVAL;
}
memcpy(dev->dev_addr, addr->sa_data, dev->addr_len);
return status;
}
static void vxge_vpath_intr_enable(struct vxgedev *vdev, int vp_id)
{
struct vxge_vpath *vpath = &vdev->vpaths[vp_id];
int msix_id = 0;
int tim_msix_id[4] = {0, 1, 0, 0};
int alarm_msix_id = VXGE_ALARM_MSIX_ID;
vxge_hw_vpath_intr_enable(vpath->handle);
if (vdev->config.intr_type == INTA)
vxge_hw_vpath_inta_unmask_tx_rx(vpath->handle);
else {
vxge_hw_vpath_msix_set(vpath->handle, tim_msix_id,
alarm_msix_id);
msix_id = vpath->device_id * VXGE_HW_VPATH_MSIX_ACTIVE;
vxge_hw_vpath_msix_unmask(vpath->handle, msix_id);
vxge_hw_vpath_msix_unmask(vpath->handle, msix_id + 1);
msix_id = (vpath->handle->vpath->hldev->first_vp_id *
VXGE_HW_VPATH_MSIX_ACTIVE) + alarm_msix_id;
vxge_hw_vpath_msix_unmask(vpath->handle, msix_id);
}
}
static void vxge_vpath_intr_disable(struct vxgedev *vdev, int vp_id)
{
struct vxge_vpath *vpath = &vdev->vpaths[vp_id];
struct __vxge_hw_device *hldev;
int msix_id;
hldev = pci_get_drvdata(vdev->pdev);
vxge_hw_vpath_wait_receive_idle(hldev, vpath->device_id);
vxge_hw_vpath_intr_disable(vpath->handle);
if (vdev->config.intr_type == INTA)
vxge_hw_vpath_inta_mask_tx_rx(vpath->handle);
else {
msix_id = vpath->device_id * VXGE_HW_VPATH_MSIX_ACTIVE;
vxge_hw_vpath_msix_mask(vpath->handle, msix_id);
vxge_hw_vpath_msix_mask(vpath->handle, msix_id + 1);
msix_id = (vpath->handle->vpath->hldev->first_vp_id *
VXGE_HW_VPATH_MSIX_ACTIVE) + VXGE_ALARM_MSIX_ID;
vxge_hw_vpath_msix_mask(vpath->handle, msix_id);
}
}
static enum vxge_hw_status
vxge_search_mac_addr_in_da_table(struct vxge_vpath *vpath, struct macInfo *mac)
{
enum vxge_hw_status status = VXGE_HW_OK;
unsigned char macmask[ETH_ALEN];
unsigned char macaddr[ETH_ALEN];
status = vxge_hw_vpath_mac_addr_get(vpath->handle,
macaddr, macmask);
if (status != VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR,
"DA config list entry failed for vpath:%d",
vpath->device_id);
return status;
}
while (memcmp(mac->macaddr, macaddr, ETH_ALEN)) {
status = vxge_hw_vpath_mac_addr_get_next(vpath->handle,
macaddr, macmask);
if (status != VXGE_HW_OK)
break;
}
return status;
}
static enum vxge_hw_status vxge_restore_vpath_mac_addr(struct vxge_vpath *vpath)
{
enum vxge_hw_status status = VXGE_HW_OK;
struct macInfo mac_info;
u8 *mac_address = NULL;
struct list_head *entry, *next;
memset(&mac_info, 0, sizeof(struct macInfo));
if (vpath->is_open) {
list_for_each_safe(entry, next, &vpath->mac_addr_list) {
mac_address =
(u8 *)&
((struct vxge_mac_addrs *)entry)->macaddr;
memcpy(mac_info.macaddr, mac_address, ETH_ALEN);
((struct vxge_mac_addrs *)entry)->state =
VXGE_LL_MAC_ADDR_IN_DA_TABLE;
status = vxge_search_mac_addr_in_da_table(vpath,
&mac_info);
if (status != VXGE_HW_OK) {
status = vxge_hw_vpath_mac_addr_add(
vpath->handle, mac_info.macaddr,
mac_info.macmask,
VXGE_HW_VPATH_MAC_ADDR_ADD_DUPLICATE);
if (status != VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR,
"DA add entry failed for vpath:%d",
vpath->device_id);
((struct vxge_mac_addrs *)entry)->state
= VXGE_LL_MAC_ADDR_IN_LIST;
}
}
}
}
return status;
}
static enum vxge_hw_status
vxge_restore_vpath_vid_table(struct vxge_vpath *vpath)
{
enum vxge_hw_status status = VXGE_HW_OK;
struct vxgedev *vdev = vpath->vdev;
u16 vid;
if (!vpath->is_open)
return status;
for_each_set_bit(vid, vdev->active_vlans, VLAN_N_VID)
status = vxge_hw_vpath_vid_add(vpath->handle, vid);
return status;
}
static int vxge_reset_vpath(struct vxgedev *vdev, int vp_id)
{
enum vxge_hw_status status = VXGE_HW_OK;
struct vxge_vpath *vpath = &vdev->vpaths[vp_id];
int ret = 0;
if (unlikely(!is_vxge_card_up(vdev)))
return 0;
if (test_bit(__VXGE_STATE_RESET_CARD, &vdev->state))
return 0;
if (vpath->handle) {
if (vxge_hw_vpath_reset(vpath->handle) == VXGE_HW_OK) {
if (is_vxge_card_up(vdev) &&
vxge_hw_vpath_recover_from_reset(vpath->handle)
!= VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR,
"vxge_hw_vpath_recover_from_reset"
"failed for vpath:%d", vp_id);
return status;
}
} else {
vxge_debug_init(VXGE_ERR,
"vxge_hw_vpath_reset failed for"
"vpath:%d", vp_id);
return status;
}
} else
return VXGE_HW_FAIL;
vxge_restore_vpath_mac_addr(vpath);
vxge_restore_vpath_vid_table(vpath);
vxge_hw_vpath_bcast_enable(vpath->handle);
if (vdev->all_multi_flg) {
status = vxge_hw_vpath_mcast_enable(vpath->handle);
if (status != VXGE_HW_OK)
vxge_debug_init(VXGE_ERR,
"%s:%d Enabling multicast failed",
__func__, __LINE__);
}
vxge_vpath_intr_enable(vdev, vp_id);
smp_wmb();
vxge_hw_vpath_enable(vpath->handle);
smp_wmb();
vxge_hw_vpath_rx_doorbell_init(vpath->handle);
vpath->ring.last_status = VXGE_HW_OK;
clear_bit(vp_id, &vdev->vp_reset);
if (netif_tx_queue_stopped(vpath->fifo.txq))
netif_tx_wake_queue(vpath->fifo.txq);
return ret;
}
static void vxge_config_ci_for_tti_rti(struct vxgedev *vdev)
{
int i = 0;
if (vdev->config.intr_type == MSI_X) {
for (i = 0; i < vdev->no_of_vpath; i++) {
struct __vxge_hw_ring *hw_ring;
hw_ring = vdev->vpaths[i].ring.handle;
vxge_hw_vpath_dynamic_rti_ci_set(hw_ring);
}
}
for (i = 0; i < vdev->no_of_vpath; i++) {
struct __vxge_hw_fifo *hw_fifo = vdev->vpaths[i].fifo.handle;
vxge_hw_vpath_tti_ci_set(hw_fifo);
if ((vdev->config.intr_type == INTA) && (i == 0))
break;
}
return;
}
static int do_vxge_reset(struct vxgedev *vdev, int event)
{
enum vxge_hw_status status;
int ret = 0, vp_id, i;
vxge_debug_entryexit(VXGE_TRACE, "%s:%d", __func__, __LINE__);
if ((event == VXGE_LL_FULL_RESET) || (event == VXGE_LL_START_RESET)) {
if (unlikely(!is_vxge_card_up(vdev)))
return 0;
if (test_and_set_bit(__VXGE_STATE_RESET_CARD, &vdev->state))
return 0;
}
if (event == VXGE_LL_FULL_RESET) {
netif_carrier_off(vdev->ndev);
for (vp_id = 0; vp_id < vdev->no_of_vpath; vp_id++) {
while (test_bit(vp_id, &vdev->vp_reset))
msleep(50);
}
netif_carrier_on(vdev->ndev);
if (unlikely(vdev->exec_mode)) {
vxge_debug_init(VXGE_ERR,
"%s: execution mode is debug, returning..",
vdev->ndev->name);
clear_bit(__VXGE_STATE_CARD_UP, &vdev->state);
netif_tx_stop_all_queues(vdev->ndev);
return 0;
}
}
if (event == VXGE_LL_FULL_RESET) {
vxge_hw_device_wait_receive_idle(vdev->devh);
vxge_hw_device_intr_disable(vdev->devh);
switch (vdev->cric_err_event) {
case VXGE_HW_EVENT_UNKNOWN:
netif_tx_stop_all_queues(vdev->ndev);
vxge_debug_init(VXGE_ERR,
"fatal: %s: Disabling device due to"
"unknown error",
vdev->ndev->name);
ret = -EPERM;
goto out;
case VXGE_HW_EVENT_RESET_START:
break;
case VXGE_HW_EVENT_RESET_COMPLETE:
case VXGE_HW_EVENT_LINK_DOWN:
case VXGE_HW_EVENT_LINK_UP:
case VXGE_HW_EVENT_ALARM_CLEARED:
case VXGE_HW_EVENT_ECCERR:
case VXGE_HW_EVENT_MRPCIM_ECCERR:
ret = -EPERM;
goto out;
case VXGE_HW_EVENT_FIFO_ERR:
case VXGE_HW_EVENT_VPATH_ERR:
break;
case VXGE_HW_EVENT_CRITICAL_ERR:
netif_tx_stop_all_queues(vdev->ndev);
vxge_debug_init(VXGE_ERR,
"fatal: %s: Disabling device due to"
"serious error",
vdev->ndev->name);
ret = -EPERM;
goto out;
case VXGE_HW_EVENT_SERR:
netif_tx_stop_all_queues(vdev->ndev);
vxge_debug_init(VXGE_ERR,
"fatal: %s: Disabling device due to"
"serious error",
vdev->ndev->name);
ret = -EPERM;
goto out;
case VXGE_HW_EVENT_SRPCIM_SERR:
case VXGE_HW_EVENT_MRPCIM_SERR:
ret = -EPERM;
goto out;
case VXGE_HW_EVENT_SLOT_FREEZE:
netif_tx_stop_all_queues(vdev->ndev);
vxge_debug_init(VXGE_ERR,
"fatal: %s: Disabling device due to"
"slot freeze",
vdev->ndev->name);
ret = -EPERM;
goto out;
default:
break;
}
}
if ((event == VXGE_LL_FULL_RESET) || (event == VXGE_LL_START_RESET))
netif_tx_stop_all_queues(vdev->ndev);
if (event == VXGE_LL_FULL_RESET) {
status = vxge_reset_all_vpaths(vdev);
if (status != VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR,
"fatal: %s: can not reset vpaths",
vdev->ndev->name);
ret = -EPERM;
goto out;
}
}
if (event == VXGE_LL_COMPL_RESET) {
for (i = 0; i < vdev->no_of_vpath; i++)
if (vdev->vpaths[i].handle) {
if (vxge_hw_vpath_recover_from_reset(
vdev->vpaths[i].handle)
!= VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR,
"vxge_hw_vpath_recover_"
"from_reset failed for vpath: "
"%d", i);
ret = -EPERM;
goto out;
}
} else {
vxge_debug_init(VXGE_ERR,
"vxge_hw_vpath_reset failed for "
"vpath:%d", i);
ret = -EPERM;
goto out;
}
}
if ((event == VXGE_LL_FULL_RESET) || (event == VXGE_LL_COMPL_RESET)) {
for (vp_id = 0; vp_id < vdev->no_of_vpath; vp_id++) {
vxge_restore_vpath_mac_addr(&vdev->vpaths[vp_id]);
vxge_restore_vpath_vid_table(&vdev->vpaths[vp_id]);
}
for (i = 0; i < vdev->no_of_vpath; i++)
vxge_vpath_intr_enable(vdev, i);
vxge_hw_device_intr_enable(vdev->devh);
smp_wmb();
set_bit(__VXGE_STATE_CARD_UP, &vdev->state);
for (i = 0; i < vdev->no_of_vpath; i++) {
vxge_hw_vpath_enable(vdev->vpaths[i].handle);
smp_wmb();
vxge_hw_vpath_rx_doorbell_init(vdev->vpaths[i].handle);
}
netif_tx_wake_all_queues(vdev->ndev);
}
vxge_config_ci_for_tti_rti(vdev);
out:
vxge_debug_entryexit(VXGE_TRACE,
"%s:%d Exiting...", __func__, __LINE__);
if ((event == VXGE_LL_FULL_RESET) || (event == VXGE_LL_COMPL_RESET))
clear_bit(__VXGE_STATE_RESET_CARD, &vdev->state);
return ret;
}
static void vxge_reset(struct work_struct *work)
{
struct vxgedev *vdev = container_of(work, struct vxgedev, reset_task);
if (!netif_running(vdev->ndev))
return;
do_vxge_reset(vdev, VXGE_LL_FULL_RESET);
}
static int vxge_poll_msix(struct napi_struct *napi, int budget)
{
struct vxge_ring *ring = container_of(napi, struct vxge_ring, napi);
int pkts_processed;
int budget_org = budget;
ring->budget = budget;
ring->pkts_processed = 0;
vxge_hw_vpath_poll_rx(ring->handle);
pkts_processed = ring->pkts_processed;
if (ring->pkts_processed < budget_org) {
napi_complete(napi);
vxge_hw_channel_msix_unmask(
(struct __vxge_hw_channel *)ring->handle,
ring->rx_vector_no);
mmiowb();
}
return pkts_processed;
}
static int vxge_poll_inta(struct napi_struct *napi, int budget)
{
struct vxgedev *vdev = container_of(napi, struct vxgedev, napi);
int pkts_processed = 0;
int i;
int budget_org = budget;
struct vxge_ring *ring;
struct __vxge_hw_device *hldev = pci_get_drvdata(vdev->pdev);
for (i = 0; i < vdev->no_of_vpath; i++) {
ring = &vdev->vpaths[i].ring;
ring->budget = budget;
ring->pkts_processed = 0;
vxge_hw_vpath_poll_rx(ring->handle);
pkts_processed += ring->pkts_processed;
budget -= ring->pkts_processed;
if (budget <= 0)
break;
}
VXGE_COMPLETE_ALL_TX(vdev);
if (pkts_processed < budget_org) {
napi_complete(napi);
vxge_hw_device_unmask_all(hldev);
vxge_hw_device_flush_io(hldev);
}
return pkts_processed;
}
static void vxge_netpoll(struct net_device *dev)
{
struct vxgedev *vdev = netdev_priv(dev);
struct pci_dev *pdev = vdev->pdev;
struct __vxge_hw_device *hldev = pci_get_drvdata(pdev);
const int irq = pdev->irq;
vxge_debug_entryexit(VXGE_TRACE, "%s:%d", __func__, __LINE__);
if (pci_channel_offline(pdev))
return;
disable_irq(irq);
vxge_hw_device_clear_tx_rx(hldev);
vxge_hw_device_clear_tx_rx(hldev);
VXGE_COMPLETE_ALL_RX(vdev);
VXGE_COMPLETE_ALL_TX(vdev);
enable_irq(irq);
vxge_debug_entryexit(VXGE_TRACE,
"%s:%d Exiting...", __func__, __LINE__);
}
static enum vxge_hw_status vxge_rth_configure(struct vxgedev *vdev)
{
enum vxge_hw_status status = VXGE_HW_OK;
struct vxge_hw_rth_hash_types hash_types;
u8 itable[256] = {0};
u8 mtable[256] = {0};
int index;
for (index = 0; index < (1 << vdev->config.rth_bkt_sz); index++) {
itable[index] = index;
mtable[index] = index % vdev->no_of_vpath;
}
status = vxge_hw_vpath_rts_rth_itable_set(vdev->vp_handles,
vdev->no_of_vpath,
mtable, itable,
vdev->config.rth_bkt_sz);
if (status != VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR,
"RTH indirection table configuration failed "
"for vpath:%d", vdev->vpaths[0].device_id);
return status;
}
hash_types.hash_type_tcpipv4_en = vdev->config.rth_hash_type_tcpipv4;
hash_types.hash_type_ipv4_en = vdev->config.rth_hash_type_ipv4;
hash_types.hash_type_tcpipv6_en = vdev->config.rth_hash_type_tcpipv6;
hash_types.hash_type_ipv6_en = vdev->config.rth_hash_type_ipv6;
hash_types.hash_type_tcpipv6ex_en =
vdev->config.rth_hash_type_tcpipv6ex;
hash_types.hash_type_ipv6ex_en = vdev->config.rth_hash_type_ipv6ex;
for (index = 0; index < vdev->no_of_vpath; index++) {
status = vxge_hw_vpath_rts_rth_set(
vdev->vpaths[index].handle,
vdev->config.rth_algorithm,
&hash_types,
vdev->config.rth_bkt_sz);
if (status != VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR,
"RTH configuration failed for vpath:%d",
vdev->vpaths[index].device_id);
return status;
}
}
return status;
}
enum vxge_hw_status vxge_reset_all_vpaths(struct vxgedev *vdev)
{
enum vxge_hw_status status = VXGE_HW_OK;
struct vxge_vpath *vpath;
int i;
for (i = 0; i < vdev->no_of_vpath; i++) {
vpath = &vdev->vpaths[i];
if (vpath->handle) {
if (vxge_hw_vpath_reset(vpath->handle) == VXGE_HW_OK) {
if (is_vxge_card_up(vdev) &&
vxge_hw_vpath_recover_from_reset(
vpath->handle) != VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR,
"vxge_hw_vpath_recover_"
"from_reset failed for vpath: "
"%d", i);
return status;
}
} else {
vxge_debug_init(VXGE_ERR,
"vxge_hw_vpath_reset failed for "
"vpath:%d", i);
return status;
}
}
}
return status;
}
static void vxge_close_vpaths(struct vxgedev *vdev, int index)
{
struct vxge_vpath *vpath;
int i;
for (i = index; i < vdev->no_of_vpath; i++) {
vpath = &vdev->vpaths[i];
if (vpath->handle && vpath->is_open) {
vxge_hw_vpath_close(vpath->handle);
vdev->stats.vpaths_open--;
}
vpath->is_open = 0;
vpath->handle = NULL;
}
}
static int vxge_open_vpaths(struct vxgedev *vdev)
{
struct vxge_hw_vpath_attr attr;
enum vxge_hw_status status;
struct vxge_vpath *vpath;
u32 vp_id = 0;
int i;
for (i = 0; i < vdev->no_of_vpath; i++) {
vpath = &vdev->vpaths[i];
vxge_assert(vpath->is_configured);
if (!vdev->titan1) {
struct vxge_hw_vp_config *vcfg;
vcfg = &vdev->devh->config.vp_config[vpath->device_id];
vcfg->rti.urange_a = RTI_T1A_RX_URANGE_A;
vcfg->rti.urange_b = RTI_T1A_RX_URANGE_B;
vcfg->rti.urange_c = RTI_T1A_RX_URANGE_C;
vcfg->tti.uec_a = TTI_T1A_TX_UFC_A;
vcfg->tti.uec_b = TTI_T1A_TX_UFC_B;
vcfg->tti.uec_c = TTI_T1A_TX_UFC_C(vdev->mtu);
vcfg->tti.uec_d = TTI_T1A_TX_UFC_D(vdev->mtu);
vcfg->tti.ltimer_val = VXGE_T1A_TTI_LTIMER_VAL;
vcfg->tti.rtimer_val = VXGE_T1A_TTI_RTIMER_VAL;
}
attr.vp_id = vpath->device_id;
attr.fifo_attr.callback = vxge_xmit_compl;
attr.fifo_attr.txdl_term = vxge_tx_term;
attr.fifo_attr.per_txdl_space = sizeof(struct vxge_tx_priv);
attr.fifo_attr.userdata = &vpath->fifo;
attr.ring_attr.callback = vxge_rx_1b_compl;
attr.ring_attr.rxd_init = vxge_rx_initial_replenish;
attr.ring_attr.rxd_term = vxge_rx_term;
attr.ring_attr.per_rxd_space = sizeof(struct vxge_rx_priv);
attr.ring_attr.userdata = &vpath->ring;
vpath->ring.ndev = vdev->ndev;
vpath->ring.pdev = vdev->pdev;
status = vxge_hw_vpath_open(vdev->devh, &attr, &vpath->handle);
if (status == VXGE_HW_OK) {
vpath->fifo.handle =
(struct __vxge_hw_fifo *)attr.fifo_attr.userdata;
vpath->ring.handle =
(struct __vxge_hw_ring *)attr.ring_attr.userdata;
vpath->fifo.tx_steering_type =
vdev->config.tx_steering_type;
vpath->fifo.ndev = vdev->ndev;
vpath->fifo.pdev = vdev->pdev;
if (vdev->config.tx_steering_type)
vpath->fifo.txq =
netdev_get_tx_queue(vdev->ndev, i);
else
vpath->fifo.txq =
netdev_get_tx_queue(vdev->ndev, 0);
vpath->fifo.indicate_max_pkts =
vdev->config.fifo_indicate_max_pkts;
vpath->fifo.tx_vector_no = 0;
vpath->ring.rx_vector_no = 0;
vpath->ring.rx_hwts = vdev->rx_hwts;
vpath->is_open = 1;
vdev->vp_handles[i] = vpath->handle;
vpath->ring.vlan_tag_strip = vdev->vlan_tag_strip;
vdev->stats.vpaths_open++;
} else {
vdev->stats.vpath_open_fail++;
vxge_debug_init(VXGE_ERR, "%s: vpath: %d failed to "
"open with status: %d",
vdev->ndev->name, vpath->device_id,
status);
vxge_close_vpaths(vdev, 0);
return -EPERM;
}
vp_id = vpath->handle->vpath->vp_id;
vdev->vpaths_deployed |= vxge_mBIT(vp_id);
}
return VXGE_HW_OK;
}
static void adaptive_coalesce_tx_interrupts(struct vxge_fifo *fifo)
{
fifo->interrupt_count++;
if (jiffies > fifo->jiffies + HZ / 100) {
struct __vxge_hw_fifo *hw_fifo = fifo->handle;
fifo->jiffies = jiffies;
if (fifo->interrupt_count > VXGE_T1A_MAX_TX_INTERRUPT_COUNT &&
hw_fifo->rtimer != VXGE_TTI_RTIMER_ADAPT_VAL) {
hw_fifo->rtimer = VXGE_TTI_RTIMER_ADAPT_VAL;
vxge_hw_vpath_dynamic_tti_rtimer_set(hw_fifo);
} else if (hw_fifo->rtimer != 0) {
hw_fifo->rtimer = 0;
vxge_hw_vpath_dynamic_tti_rtimer_set(hw_fifo);
}
fifo->interrupt_count = 0;
}
}
static void adaptive_coalesce_rx_interrupts(struct vxge_ring *ring)
{
ring->interrupt_count++;
if (jiffies > ring->jiffies + HZ / 100) {
struct __vxge_hw_ring *hw_ring = ring->handle;
ring->jiffies = jiffies;
if (ring->interrupt_count > VXGE_T1A_MAX_INTERRUPT_COUNT &&
hw_ring->rtimer != VXGE_RTI_RTIMER_ADAPT_VAL) {
hw_ring->rtimer = VXGE_RTI_RTIMER_ADAPT_VAL;
vxge_hw_vpath_dynamic_rti_rtimer_set(hw_ring);
} else if (hw_ring->rtimer != 0) {
hw_ring->rtimer = 0;
vxge_hw_vpath_dynamic_rti_rtimer_set(hw_ring);
}
ring->interrupt_count = 0;
}
}
static irqreturn_t vxge_isr_napi(int irq, void *dev_id)
{
struct net_device *dev;
struct __vxge_hw_device *hldev;
u64 reason;
enum vxge_hw_status status;
struct vxgedev *vdev = (struct vxgedev *)dev_id;
vxge_debug_intr(VXGE_TRACE, "%s:%d", __func__, __LINE__);
dev = vdev->ndev;
hldev = pci_get_drvdata(vdev->pdev);
if (pci_channel_offline(vdev->pdev))
return IRQ_NONE;
if (unlikely(!is_vxge_card_up(vdev)))
return IRQ_HANDLED;
status = vxge_hw_device_begin_irq(hldev, vdev->exec_mode, &reason);
if (status == VXGE_HW_OK) {
vxge_hw_device_mask_all(hldev);
if (reason &
VXGE_HW_TITAN_GENERAL_INT_STATUS_VPATH_TRAFFIC_INT(
vdev->vpaths_deployed >>
(64 - VXGE_HW_MAX_VIRTUAL_PATHS))) {
vxge_hw_device_clear_tx_rx(hldev);
napi_schedule(&vdev->napi);
vxge_debug_intr(VXGE_TRACE,
"%s:%d Exiting...", __func__, __LINE__);
return IRQ_HANDLED;
} else
vxge_hw_device_unmask_all(hldev);
} else if (unlikely((status == VXGE_HW_ERR_VPATH) ||
(status == VXGE_HW_ERR_CRITICAL) ||
(status == VXGE_HW_ERR_FIFO))) {
vxge_hw_device_mask_all(hldev);
vxge_hw_device_flush_io(hldev);
return IRQ_HANDLED;
} else if (unlikely(status == VXGE_HW_ERR_SLOT_FREEZE))
return IRQ_HANDLED;
vxge_debug_intr(VXGE_TRACE, "%s:%d Exiting...", __func__, __LINE__);
return IRQ_NONE;
}
static irqreturn_t vxge_tx_msix_handle(int irq, void *dev_id)
{
struct vxge_fifo *fifo = (struct vxge_fifo *)dev_id;
adaptive_coalesce_tx_interrupts(fifo);
vxge_hw_channel_msix_mask((struct __vxge_hw_channel *)fifo->handle,
fifo->tx_vector_no);
vxge_hw_channel_msix_clear((struct __vxge_hw_channel *)fifo->handle,
fifo->tx_vector_no);
VXGE_COMPLETE_VPATH_TX(fifo);
vxge_hw_channel_msix_unmask((struct __vxge_hw_channel *)fifo->handle,
fifo->tx_vector_no);
mmiowb();
return IRQ_HANDLED;
}
static irqreturn_t vxge_rx_msix_napi_handle(int irq, void *dev_id)
{
struct vxge_ring *ring = (struct vxge_ring *)dev_id;
adaptive_coalesce_rx_interrupts(ring);
vxge_hw_channel_msix_mask((struct __vxge_hw_channel *)ring->handle,
ring->rx_vector_no);
vxge_hw_channel_msix_clear((struct __vxge_hw_channel *)ring->handle,
ring->rx_vector_no);
napi_schedule(&ring->napi);
return IRQ_HANDLED;
}
static irqreturn_t
vxge_alarm_msix_handle(int irq, void *dev_id)
{
int i;
enum vxge_hw_status status;
struct vxge_vpath *vpath = (struct vxge_vpath *)dev_id;
struct vxgedev *vdev = vpath->vdev;
int msix_id = (vpath->handle->vpath->vp_id *
VXGE_HW_VPATH_MSIX_ACTIVE) + VXGE_ALARM_MSIX_ID;
for (i = 0; i < vdev->no_of_vpath; i++) {
vxge_hw_vpath_msix_mask(vdev->vpaths[i].handle, msix_id);
vxge_hw_vpath_msix_clear(vdev->vpaths[i].handle, msix_id);
mmiowb();
status = vxge_hw_vpath_alarm_process(vdev->vpaths[i].handle,
vdev->exec_mode);
if (status == VXGE_HW_OK) {
vxge_hw_vpath_msix_unmask(vdev->vpaths[i].handle,
msix_id);
mmiowb();
continue;
}
vxge_debug_intr(VXGE_ERR,
"%s: vxge_hw_vpath_alarm_process failed %x ",
VXGE_DRIVER_NAME, status);
}
return IRQ_HANDLED;
}
static int vxge_alloc_msix(struct vxgedev *vdev)
{
int j, i, ret = 0;
int msix_intr_vect = 0, temp;
vdev->intr_cnt = 0;
start:
vdev->intr_cnt = vdev->no_of_vpath * 2;
vdev->intr_cnt++;
vdev->entries = kcalloc(vdev->intr_cnt, sizeof(struct msix_entry),
GFP_KERNEL);
if (!vdev->entries) {
vxge_debug_init(VXGE_ERR,
"%s: memory allocation failed",
VXGE_DRIVER_NAME);
ret = -ENOMEM;
goto alloc_entries_failed;
}
vdev->vxge_entries = kcalloc(vdev->intr_cnt,
sizeof(struct vxge_msix_entry),
GFP_KERNEL);
if (!vdev->vxge_entries) {
vxge_debug_init(VXGE_ERR, "%s: memory allocation failed",
VXGE_DRIVER_NAME);
ret = -ENOMEM;
goto alloc_vxge_entries_failed;
}
for (i = 0, j = 0; i < vdev->no_of_vpath; i++) {
msix_intr_vect = i * VXGE_HW_VPATH_MSIX_ACTIVE;
vdev->entries[j].entry = msix_intr_vect;
vdev->vxge_entries[j].entry = msix_intr_vect;
vdev->vxge_entries[j].in_use = 0;
j++;
vdev->entries[j].entry = msix_intr_vect + 1;
vdev->vxge_entries[j].entry = msix_intr_vect + 1;
vdev->vxge_entries[j].in_use = 0;
j++;
}
vdev->entries[j].entry = VXGE_ALARM_MSIX_ID;
vdev->vxge_entries[j].entry = VXGE_ALARM_MSIX_ID;
vdev->vxge_entries[j].in_use = 0;
ret = pci_enable_msix(vdev->pdev, vdev->entries, vdev->intr_cnt);
if (ret > 0) {
vxge_debug_init(VXGE_ERR,
"%s: MSI-X enable failed for %d vectors, ret: %d",
VXGE_DRIVER_NAME, vdev->intr_cnt, ret);
if ((max_config_vpath != VXGE_USE_DEFAULT) || (ret < 3)) {
ret = -ENODEV;
goto enable_msix_failed;
}
kfree(vdev->entries);
kfree(vdev->vxge_entries);
vdev->entries = NULL;
vdev->vxge_entries = NULL;
temp = (ret - 1)/2;
vxge_close_vpaths(vdev, temp);
vdev->no_of_vpath = temp;
goto start;
} else if (ret < 0) {
ret = -ENODEV;
goto enable_msix_failed;
}
return 0;
enable_msix_failed:
kfree(vdev->vxge_entries);
alloc_vxge_entries_failed:
kfree(vdev->entries);
alloc_entries_failed:
return ret;
}
static int vxge_enable_msix(struct vxgedev *vdev)
{
int i, ret = 0;
int tim_msix_id[4] = {0, 1, 0, 0};
vdev->intr_cnt = 0;
ret = vxge_alloc_msix(vdev);
if (!ret) {
for (i = 0; i < vdev->no_of_vpath; i++) {
struct vxge_vpath *vpath = &vdev->vpaths[i];
vpath->ring.rx_vector_no = (vpath->device_id *
VXGE_HW_VPATH_MSIX_ACTIVE) + 1;
vpath->fifo.tx_vector_no = (vpath->device_id *
VXGE_HW_VPATH_MSIX_ACTIVE);
vxge_hw_vpath_msix_set(vpath->handle, tim_msix_id,
VXGE_ALARM_MSIX_ID);
}
}
return ret;
}
static void vxge_rem_msix_isr(struct vxgedev *vdev)
{
int intr_cnt;
for (intr_cnt = 0; intr_cnt < (vdev->no_of_vpath * 2 + 1);
intr_cnt++) {
if (vdev->vxge_entries[intr_cnt].in_use) {
synchronize_irq(vdev->entries[intr_cnt].vector);
free_irq(vdev->entries[intr_cnt].vector,
vdev->vxge_entries[intr_cnt].arg);
vdev->vxge_entries[intr_cnt].in_use = 0;
}
}
kfree(vdev->entries);
kfree(vdev->vxge_entries);
vdev->entries = NULL;
vdev->vxge_entries = NULL;
if (vdev->config.intr_type == MSI_X)
pci_disable_msix(vdev->pdev);
}
static void vxge_rem_isr(struct vxgedev *vdev)
{
struct __vxge_hw_device *hldev;
hldev = pci_get_drvdata(vdev->pdev);
#ifdef CONFIG_PCI_MSI
if (vdev->config.intr_type == MSI_X) {
vxge_rem_msix_isr(vdev);
} else
#endif
if (vdev->config.intr_type == INTA) {
synchronize_irq(vdev->pdev->irq);
free_irq(vdev->pdev->irq, vdev);
}
}
static int vxge_add_isr(struct vxgedev *vdev)
{
int ret = 0;
#ifdef CONFIG_PCI_MSI
int vp_idx = 0, intr_idx = 0, intr_cnt = 0, msix_idx = 0, irq_req = 0;
int pci_fun = PCI_FUNC(vdev->pdev->devfn);
if (vdev->config.intr_type == MSI_X)
ret = vxge_enable_msix(vdev);
if (ret) {
vxge_debug_init(VXGE_ERR,
"%s: Enabling MSI-X Failed", VXGE_DRIVER_NAME);
vxge_debug_init(VXGE_ERR,
"%s: Defaulting to INTA", VXGE_DRIVER_NAME);
vdev->config.intr_type = INTA;
}
if (vdev->config.intr_type == MSI_X) {
for (intr_idx = 0;
intr_idx < (vdev->no_of_vpath *
VXGE_HW_VPATH_MSIX_ACTIVE); intr_idx++) {
msix_idx = intr_idx % VXGE_HW_VPATH_MSIX_ACTIVE;
irq_req = 0;
switch (msix_idx) {
case 0:
snprintf(vdev->desc[intr_cnt], VXGE_INTR_STRLEN,
"%s:vxge:MSI-X %d - Tx - fn:%d vpath:%d",
vdev->ndev->name,
vdev->entries[intr_cnt].entry,
pci_fun, vp_idx);
ret = request_irq(
vdev->entries[intr_cnt].vector,
vxge_tx_msix_handle, 0,
vdev->desc[intr_cnt],
&vdev->vpaths[vp_idx].fifo);
vdev->vxge_entries[intr_cnt].arg =
&vdev->vpaths[vp_idx].fifo;
irq_req = 1;
break;
case 1:
snprintf(vdev->desc[intr_cnt], VXGE_INTR_STRLEN,
"%s:vxge:MSI-X %d - Rx - fn:%d vpath:%d",
vdev->ndev->name,
vdev->entries[intr_cnt].entry,
pci_fun, vp_idx);
ret = request_irq(
vdev->entries[intr_cnt].vector,
vxge_rx_msix_napi_handle,
0,
vdev->desc[intr_cnt],
&vdev->vpaths[vp_idx].ring);
vdev->vxge_entries[intr_cnt].arg =
&vdev->vpaths[vp_idx].ring;
irq_req = 1;
break;
}
if (ret) {
vxge_debug_init(VXGE_ERR,
"%s: MSIX - %d Registration failed",
vdev->ndev->name, intr_cnt);
vxge_rem_msix_isr(vdev);
vdev->config.intr_type = INTA;
vxge_debug_init(VXGE_ERR,
"%s: Defaulting to INTA"
, vdev->ndev->name);
goto INTA_MODE;
}
if (irq_req) {
vdev->vxge_entries[intr_cnt].in_use = 1;
msix_idx += vdev->vpaths[vp_idx].device_id *
VXGE_HW_VPATH_MSIX_ACTIVE;
vxge_hw_vpath_msix_unmask(
vdev->vpaths[vp_idx].handle,
msix_idx);
intr_cnt++;
}
if (((intr_idx + 1) % VXGE_HW_VPATH_MSIX_ACTIVE == 0) &&
(vp_idx < (vdev->no_of_vpath - 1)))
vp_idx++;
}
intr_cnt = vdev->no_of_vpath * 2;
snprintf(vdev->desc[intr_cnt], VXGE_INTR_STRLEN,
"%s:vxge:MSI-X %d - Alarm - fn:%d",
vdev->ndev->name,
vdev->entries[intr_cnt].entry,
pci_fun);
ret = request_irq(vdev->entries[intr_cnt].vector,
vxge_alarm_msix_handle, 0,
vdev->desc[intr_cnt],
&vdev->vpaths[0]);
if (ret) {
vxge_debug_init(VXGE_ERR,
"%s: MSIX - %d Registration failed",
vdev->ndev->name, intr_cnt);
vxge_rem_msix_isr(vdev);
vdev->config.intr_type = INTA;
vxge_debug_init(VXGE_ERR,
"%s: Defaulting to INTA",
vdev->ndev->name);
goto INTA_MODE;
}
msix_idx = (vdev->vpaths[0].handle->vpath->vp_id *
VXGE_HW_VPATH_MSIX_ACTIVE) + VXGE_ALARM_MSIX_ID;
vxge_hw_vpath_msix_unmask(vdev->vpaths[vp_idx].handle,
msix_idx);
vdev->vxge_entries[intr_cnt].in_use = 1;
vdev->vxge_entries[intr_cnt].arg = &vdev->vpaths[0];
}
INTA_MODE:
#endif
if (vdev->config.intr_type == INTA) {
snprintf(vdev->desc[0], VXGE_INTR_STRLEN,
"%s:vxge:INTA", vdev->ndev->name);
vxge_hw_device_set_intr_type(vdev->devh,
VXGE_HW_INTR_MODE_IRQLINE);
vxge_hw_vpath_tti_ci_set(vdev->vpaths[0].fifo.handle);
ret = request_irq((int) vdev->pdev->irq,
vxge_isr_napi,
IRQF_SHARED, vdev->desc[0], vdev);
if (ret) {
vxge_debug_init(VXGE_ERR,
"%s %s-%d: ISR registration failed",
VXGE_DRIVER_NAME, "IRQ", vdev->pdev->irq);
return -ENODEV;
}
vxge_debug_init(VXGE_TRACE,
"new %s-%d line allocated",
"IRQ", vdev->pdev->irq);
}
return VXGE_HW_OK;
}
static void vxge_poll_vp_reset(unsigned long data)
{
struct vxgedev *vdev = (struct vxgedev *)data;
int i, j = 0;
for (i = 0; i < vdev->no_of_vpath; i++) {
if (test_bit(i, &vdev->vp_reset)) {
vxge_reset_vpath(vdev, i);
j++;
}
}
if (j && (vdev->config.intr_type != MSI_X)) {
vxge_hw_device_unmask_all(vdev->devh);
vxge_hw_device_flush_io(vdev->devh);
}
mod_timer(&vdev->vp_reset_timer, jiffies + HZ / 2);
}
static void vxge_poll_vp_lockup(unsigned long data)
{
struct vxgedev *vdev = (struct vxgedev *)data;
enum vxge_hw_status status = VXGE_HW_OK;
struct vxge_vpath *vpath;
struct vxge_ring *ring;
int i;
unsigned long rx_frms;
for (i = 0; i < vdev->no_of_vpath; i++) {
ring = &vdev->vpaths[i].ring;
rx_frms = ACCESS_ONCE(ring->stats.rx_frms);
if (ring->stats.prev_rx_frms == rx_frms) {
status = vxge_hw_vpath_check_leak(ring->handle);
if ((VXGE_HW_FAIL == status) &&
(VXGE_HW_FAIL == ring->last_status)) {
if (!test_and_set_bit(i, &vdev->vp_reset)) {
vpath = &vdev->vpaths[i];
vxge_vpath_intr_disable(vdev, i);
netif_tx_stop_queue(vpath->fifo.txq);
continue;
}
}
}
ring->stats.prev_rx_frms = rx_frms;
ring->last_status = status;
}
mod_timer(&vdev->vp_lockup_timer, jiffies + HZ / 1000);
}
static netdev_features_t vxge_fix_features(struct net_device *dev,
netdev_features_t features)
{
netdev_features_t changed = dev->features ^ features;
if ((changed & NETIF_F_RXHASH) && netif_running(dev))
features ^= NETIF_F_RXHASH;
return features;
}
static int vxge_set_features(struct net_device *dev, netdev_features_t features)
{
struct vxgedev *vdev = netdev_priv(dev);
netdev_features_t changed = dev->features ^ features;
if (!(changed & NETIF_F_RXHASH))
return 0;
vdev->devh->config.rth_en = !!(features & NETIF_F_RXHASH);
if (vxge_reset_all_vpaths(vdev) != VXGE_HW_OK) {
dev->features = features ^ NETIF_F_RXHASH;
vdev->devh->config.rth_en = !!(dev->features & NETIF_F_RXHASH);
return -EIO;
}
return 0;
}
static int vxge_open(struct net_device *dev)
{
enum vxge_hw_status status;
struct vxgedev *vdev;
struct __vxge_hw_device *hldev;
struct vxge_vpath *vpath;
int ret = 0;
int i;
u64 val64, function_mode;
vxge_debug_entryexit(VXGE_TRACE,
"%s: %s:%d", dev->name, __func__, __LINE__);
vdev = netdev_priv(dev);
hldev = pci_get_drvdata(vdev->pdev);
function_mode = vdev->config.device_hw_info.function_mode;
netif_carrier_off(dev);
status = vxge_open_vpaths(vdev);
if (status != VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR,
"%s: fatal: Vpath open failed", vdev->ndev->name);
ret = -EPERM;
goto out0;
}
vdev->mtu = dev->mtu;
status = vxge_add_isr(vdev);
if (status != VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR,
"%s: fatal: ISR add failed", dev->name);
ret = -EPERM;
goto out1;
}
if (vdev->config.intr_type != MSI_X) {
netif_napi_add(dev, &vdev->napi, vxge_poll_inta,
vdev->config.napi_weight);
napi_enable(&vdev->napi);
for (i = 0; i < vdev->no_of_vpath; i++) {
vpath = &vdev->vpaths[i];
vpath->ring.napi_p = &vdev->napi;
}
} else {
for (i = 0; i < vdev->no_of_vpath; i++) {
vpath = &vdev->vpaths[i];
netif_napi_add(dev, &vpath->ring.napi,
vxge_poll_msix, vdev->config.napi_weight);
napi_enable(&vpath->ring.napi);
vpath->ring.napi_p = &vpath->ring.napi;
}
}
if (vdev->config.rth_steering) {
status = vxge_rth_configure(vdev);
if (status != VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR,
"%s: fatal: RTH configuration failed",
dev->name);
ret = -EPERM;
goto out2;
}
}
printk(KERN_INFO "%s: Receive Hashing Offload %s\n", dev->name,
hldev->config.rth_en ? "enabled" : "disabled");
for (i = 0; i < vdev->no_of_vpath; i++) {
vpath = &vdev->vpaths[i];
status = vxge_hw_vpath_mtu_set(vpath->handle, vdev->mtu);
if (status != VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR,
"%s: fatal: can not set new MTU", dev->name);
ret = -EPERM;
goto out2;
}
}
VXGE_DEVICE_DEBUG_LEVEL_SET(VXGE_TRACE, VXGE_COMPONENT_LL, vdev);
vxge_debug_init(vdev->level_trace,
"%s: MTU is %d", vdev->ndev->name, vdev->mtu);
VXGE_DEVICE_DEBUG_LEVEL_SET(VXGE_ERR, VXGE_COMPONENT_LL, vdev);
if (vdev->all_multi_flg) {
for (i = 0; i < vdev->no_of_vpath; i++) {
vpath = &vdev->vpaths[i];
vxge_restore_vpath_mac_addr(vpath);
vxge_restore_vpath_vid_table(vpath);
status = vxge_hw_vpath_mcast_enable(vpath->handle);
if (status != VXGE_HW_OK)
vxge_debug_init(VXGE_ERR,
"%s:%d Enabling multicast failed",
__func__, __LINE__);
}
}
val64 = 0;
for (i = 0; i < VXGE_HW_MAX_VIRTUAL_PATHS; i++)
val64 |= VXGE_HW_RXMAC_AUTHORIZE_ALL_ADDR_VP(i);
vxge_hw_mgmt_reg_write(vdev->devh,
vxge_hw_mgmt_reg_type_mrpcim,
0,
(ulong)offsetof(struct vxge_hw_mrpcim_reg,
rxmac_authorize_all_addr),
val64);
vxge_hw_mgmt_reg_write(vdev->devh,
vxge_hw_mgmt_reg_type_mrpcim,
0,
(ulong)offsetof(struct vxge_hw_mrpcim_reg,
rxmac_authorize_all_vid),
val64);
vxge_set_multicast(dev);
for (i = 0; i < vdev->no_of_vpath; i++) {
vpath = &vdev->vpaths[i];
status = vxge_hw_vpath_bcast_enable(vpath->handle);
if (status != VXGE_HW_OK)
vxge_debug_init(VXGE_ERR,
"%s : Can not enable bcast for vpath "
"id %d", dev->name, i);
if (vdev->config.addr_learn_en) {
status = vxge_hw_vpath_mcast_enable(vpath->handle);
if (status != VXGE_HW_OK)
vxge_debug_init(VXGE_ERR,
"%s : Can not enable mcast for vpath "
"id %d", dev->name, i);
}
}
vxge_hw_device_setpause_data(vdev->devh, 0,
vdev->config.tx_pause_enable,
vdev->config.rx_pause_enable);
if (vdev->vp_reset_timer.function == NULL)
vxge_os_timer(&vdev->vp_reset_timer, vxge_poll_vp_reset, vdev,
HZ / 2);
if (vdev->titan1 && vdev->vp_lockup_timer.function == NULL)
vxge_os_timer(&vdev->vp_lockup_timer, vxge_poll_vp_lockup, vdev,
HZ / 2);
set_bit(__VXGE_STATE_CARD_UP, &vdev->state);
smp_wmb();
if (vxge_hw_device_link_state_get(vdev->devh) == VXGE_HW_LINK_UP) {
netif_carrier_on(vdev->ndev);
netdev_notice(vdev->ndev, "Link Up\n");
vdev->stats.link_up++;
}
vxge_hw_device_intr_enable(vdev->devh);
smp_wmb();
for (i = 0; i < vdev->no_of_vpath; i++) {
vpath = &vdev->vpaths[i];
vxge_hw_vpath_enable(vpath->handle);
smp_wmb();
vxge_hw_vpath_rx_doorbell_init(vpath->handle);
}
netif_tx_start_all_queues(vdev->ndev);
vxge_config_ci_for_tti_rti(vdev);
goto out0;
out2:
vxge_rem_isr(vdev);
if (vdev->config.intr_type != MSI_X)
napi_disable(&vdev->napi);
else {
for (i = 0; i < vdev->no_of_vpath; i++)
napi_disable(&vdev->vpaths[i].ring.napi);
}
out1:
vxge_close_vpaths(vdev, 0);
out0:
vxge_debug_entryexit(VXGE_TRACE,
"%s: %s:%d Exiting...",
dev->name, __func__, __LINE__);
return ret;
}
static void vxge_free_mac_add_list(struct vxge_vpath *vpath)
{
struct list_head *entry, *next;
if (list_empty(&vpath->mac_addr_list))
return;
list_for_each_safe(entry, next, &vpath->mac_addr_list) {
list_del(entry);
kfree((struct vxge_mac_addrs *)entry);
}
}
static void vxge_napi_del_all(struct vxgedev *vdev)
{
int i;
if (vdev->config.intr_type != MSI_X)
netif_napi_del(&vdev->napi);
else {
for (i = 0; i < vdev->no_of_vpath; i++)
netif_napi_del(&vdev->vpaths[i].ring.napi);
}
}
static int do_vxge_close(struct net_device *dev, int do_io)
{
enum vxge_hw_status status;
struct vxgedev *vdev;
struct __vxge_hw_device *hldev;
int i;
u64 val64, vpath_vector;
vxge_debug_entryexit(VXGE_TRACE, "%s: %s:%d",
dev->name, __func__, __LINE__);
vdev = netdev_priv(dev);
hldev = pci_get_drvdata(vdev->pdev);
if (unlikely(!is_vxge_card_up(vdev)))
return 0;
while (test_and_set_bit(__VXGE_STATE_RESET_CARD, &vdev->state))
msleep(50);
if (do_io) {
vpath_vector = vxge_mBIT(vdev->vpaths[0].device_id);
status = vxge_hw_mgmt_reg_read(vdev->devh,
vxge_hw_mgmt_reg_type_mrpcim,
0,
(ulong)offsetof(
struct vxge_hw_mrpcim_reg,
rts_mgr_cbasin_cfg),
&val64);
if (status == VXGE_HW_OK) {
val64 &= ~vpath_vector;
status = vxge_hw_mgmt_reg_write(vdev->devh,
vxge_hw_mgmt_reg_type_mrpcim,
0,
(ulong)offsetof(
struct vxge_hw_mrpcim_reg,
rts_mgr_cbasin_cfg),
val64);
}
vxge_hw_mgmt_reg_write(vdev->devh,
vxge_hw_mgmt_reg_type_mrpcim,
0,
(ulong)offsetof(struct vxge_hw_mrpcim_reg,
rxmac_authorize_all_addr),
0);
vxge_hw_mgmt_reg_write(vdev->devh,
vxge_hw_mgmt_reg_type_mrpcim,
0,
(ulong)offsetof(struct vxge_hw_mrpcim_reg,
rxmac_authorize_all_vid),
0);
smp_wmb();
}
if (vdev->titan1)
del_timer_sync(&vdev->vp_lockup_timer);
del_timer_sync(&vdev->vp_reset_timer);
if (do_io)
vxge_hw_device_wait_receive_idle(hldev);
clear_bit(__VXGE_STATE_CARD_UP, &vdev->state);
if (vdev->config.intr_type != MSI_X)
napi_disable(&vdev->napi);
else {
for (i = 0; i < vdev->no_of_vpath; i++)
napi_disable(&vdev->vpaths[i].ring.napi);
}
netif_carrier_off(vdev->ndev);
netdev_notice(vdev->ndev, "Link Down\n");
netif_tx_stop_all_queues(vdev->ndev);
if (do_io)
vxge_hw_device_intr_disable(vdev->devh);
vxge_rem_isr(vdev);
vxge_napi_del_all(vdev);
if (do_io)
vxge_reset_all_vpaths(vdev);
vxge_close_vpaths(vdev, 0);
vxge_debug_entryexit(VXGE_TRACE,
"%s: %s:%d Exiting...", dev->name, __func__, __LINE__);
clear_bit(__VXGE_STATE_RESET_CARD, &vdev->state);
return 0;
}
static int vxge_close(struct net_device *dev)
{
do_vxge_close(dev, 1);
return 0;
}
static int vxge_change_mtu(struct net_device *dev, int new_mtu)
{
struct vxgedev *vdev = netdev_priv(dev);
vxge_debug_entryexit(vdev->level_trace,
"%s:%d", __func__, __LINE__);
if ((new_mtu < VXGE_HW_MIN_MTU) || (new_mtu > VXGE_HW_MAX_MTU)) {
vxge_debug_init(vdev->level_err,
"%s: mtu size is invalid", dev->name);
return -EPERM;
}
if (unlikely(!is_vxge_card_up(vdev))) {
dev->mtu = new_mtu;
vxge_debug_init(vdev->level_err,
"%s", "device is down on MTU change");
return 0;
}
vxge_debug_init(vdev->level_trace,
"trying to apply new MTU %d", new_mtu);
if (vxge_close(dev))
return -EIO;
dev->mtu = new_mtu;
vdev->mtu = new_mtu;
if (vxge_open(dev))
return -EIO;
vxge_debug_init(vdev->level_trace,
"%s: MTU changed to %d", vdev->ndev->name, new_mtu);
vxge_debug_entryexit(vdev->level_trace,
"%s:%d Exiting...", __func__, __LINE__);
return 0;
}
static struct rtnl_link_stats64 *
vxge_get_stats64(struct net_device *dev, struct rtnl_link_stats64 *net_stats)
{
struct vxgedev *vdev = netdev_priv(dev);
int k;
for (k = 0; k < vdev->no_of_vpath; k++) {
struct vxge_ring_stats *rxstats = &vdev->vpaths[k].ring.stats;
struct vxge_fifo_stats *txstats = &vdev->vpaths[k].fifo.stats;
unsigned int start;
u64 packets, bytes, multicast;
do {
start = u64_stats_fetch_begin_bh(&rxstats->syncp);
packets = rxstats->rx_frms;
multicast = rxstats->rx_mcast;
bytes = rxstats->rx_bytes;
} while (u64_stats_fetch_retry_bh(&rxstats->syncp, start));
net_stats->rx_packets += packets;
net_stats->rx_bytes += bytes;
net_stats->multicast += multicast;
net_stats->rx_errors += rxstats->rx_errors;
net_stats->rx_dropped += rxstats->rx_dropped;
do {
start = u64_stats_fetch_begin_bh(&txstats->syncp);
packets = txstats->tx_frms;
bytes = txstats->tx_bytes;
} while (u64_stats_fetch_retry_bh(&txstats->syncp, start));
net_stats->tx_packets += packets;
net_stats->tx_bytes += bytes;
net_stats->tx_errors += txstats->tx_errors;
}
return net_stats;
}
static enum vxge_hw_status vxge_timestamp_config(struct __vxge_hw_device *devh)
{
enum vxge_hw_status status;
u64 val64;
val64 = VXGE_HW_XMAC_TIMESTAMP_EN |
VXGE_HW_XMAC_TIMESTAMP_USE_LINK_ID(0) |
VXGE_HW_XMAC_TIMESTAMP_INTERVAL(0);
status = vxge_hw_mgmt_reg_write(devh,
vxge_hw_mgmt_reg_type_mrpcim,
0,
offsetof(struct vxge_hw_mrpcim_reg,
xmac_timestamp),
val64);
vxge_hw_device_flush_io(devh);
devh->config.hwts_en = VXGE_HW_HWTS_ENABLE;
return status;
}
static int vxge_hwtstamp_ioctl(struct vxgedev *vdev, void __user *data)
{
struct hwtstamp_config config;
int i;
if (copy_from_user(&config, data, sizeof(config)))
return -EFAULT;
if (config.flags)
return -EINVAL;
switch (config.tx_type) {
case HWTSTAMP_TX_OFF:
break;
case HWTSTAMP_TX_ON:
default:
return -ERANGE;
}
switch (config.rx_filter) {
case HWTSTAMP_FILTER_NONE:
vdev->rx_hwts = 0;
config.rx_filter = HWTSTAMP_FILTER_NONE;
break;
case HWTSTAMP_FILTER_ALL:
case HWTSTAMP_FILTER_SOME:
case HWTSTAMP_FILTER_PTP_V1_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V1_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L4_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_L2_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L2_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_EVENT:
case HWTSTAMP_FILTER_PTP_V2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_DELAY_REQ:
if (vdev->devh->config.hwts_en != VXGE_HW_HWTS_ENABLE)
return -EFAULT;
vdev->rx_hwts = 1;
config.rx_filter = HWTSTAMP_FILTER_ALL;
break;
default:
return -ERANGE;
}
for (i = 0; i < vdev->no_of_vpath; i++)
vdev->vpaths[i].ring.rx_hwts = vdev->rx_hwts;
if (copy_to_user(data, &config, sizeof(config)))
return -EFAULT;
return 0;
}
static int vxge_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct vxgedev *vdev = netdev_priv(dev);
int ret;
switch (cmd) {
case SIOCSHWTSTAMP:
ret = vxge_hwtstamp_ioctl(vdev, rq->ifr_data);
if (ret)
return ret;
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static void vxge_tx_watchdog(struct net_device *dev)
{
struct vxgedev *vdev;
vxge_debug_entryexit(VXGE_TRACE, "%s:%d", __func__, __LINE__);
vdev = netdev_priv(dev);
vdev->cric_err_event = VXGE_HW_EVENT_RESET_START;
schedule_work(&vdev->reset_task);
vxge_debug_entryexit(VXGE_TRACE,
"%s:%d Exiting...", __func__, __LINE__);
}
static int
vxge_vlan_rx_add_vid(struct net_device *dev, __be16 proto, u16 vid)
{
struct vxgedev *vdev = netdev_priv(dev);
struct vxge_vpath *vpath;
int vp_id;
for (vp_id = 0; vp_id < vdev->no_of_vpath; vp_id++) {
vpath = &vdev->vpaths[vp_id];
if (!vpath->is_open)
continue;
vxge_hw_vpath_vid_add(vpath->handle, vid);
}
set_bit(vid, vdev->active_vlans);
return 0;
}
static int
vxge_vlan_rx_kill_vid(struct net_device *dev, __be16 proto, u16 vid)
{
struct vxgedev *vdev = netdev_priv(dev);
struct vxge_vpath *vpath;
int vp_id;
vxge_debug_entryexit(VXGE_TRACE, "%s:%d", __func__, __LINE__);
for (vp_id = 0; vp_id < vdev->no_of_vpath; vp_id++) {
vpath = &vdev->vpaths[vp_id];
if (!vpath->is_open)
continue;
vxge_hw_vpath_vid_delete(vpath->handle, vid);
}
vxge_debug_entryexit(VXGE_TRACE,
"%s:%d Exiting...", __func__, __LINE__);
clear_bit(vid, vdev->active_vlans);
return 0;
}
static int vxge_device_register(struct __vxge_hw_device *hldev,
struct vxge_config *config, int high_dma,
int no_of_vpath, struct vxgedev **vdev_out)
{
struct net_device *ndev;
enum vxge_hw_status status = VXGE_HW_OK;
struct vxgedev *vdev;
int ret = 0, no_of_queue = 1;
u64 stat;
*vdev_out = NULL;
if (config->tx_steering_type)
no_of_queue = no_of_vpath;
ndev = alloc_etherdev_mq(sizeof(struct vxgedev),
no_of_queue);
if (ndev == NULL) {
vxge_debug_init(
vxge_hw_device_trace_level_get(hldev),
"%s : device allocation failed", __func__);
ret = -ENODEV;
goto _out0;
}
vxge_debug_entryexit(
vxge_hw_device_trace_level_get(hldev),
"%s: %s:%d Entering...",
ndev->name, __func__, __LINE__);
vdev = netdev_priv(ndev);
memset(vdev, 0, sizeof(struct vxgedev));
vdev->ndev = ndev;
vdev->devh = hldev;
vdev->pdev = hldev->pdev;
memcpy(&vdev->config, config, sizeof(struct vxge_config));
vdev->rx_hwts = 0;
vdev->titan1 = (vdev->pdev->revision == VXGE_HW_TITAN1_PCI_REVISION);
SET_NETDEV_DEV(ndev, &vdev->pdev->dev);
ndev->hw_features = NETIF_F_RXCSUM | NETIF_F_SG |
NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM |
NETIF_F_TSO | NETIF_F_TSO6 |
NETIF_F_HW_VLAN_CTAG_TX;
if (vdev->config.rth_steering != NO_STEERING)
ndev->hw_features |= NETIF_F_RXHASH;
ndev->features |= ndev->hw_features |
NETIF_F_HW_VLAN_CTAG_RX | NETIF_F_HW_VLAN_CTAG_FILTER;
ndev->netdev_ops = &vxge_netdev_ops;
ndev->watchdog_timeo = VXGE_LL_WATCH_DOG_TIMEOUT;
INIT_WORK(&vdev->reset_task, vxge_reset);
vxge_initialize_ethtool_ops(ndev);
vdev->vpaths = kzalloc((sizeof(struct vxge_vpath)) *
no_of_vpath, GFP_KERNEL);
if (!vdev->vpaths) {
vxge_debug_init(VXGE_ERR,
"%s: vpath memory allocation failed",
vdev->ndev->name);
ret = -ENOMEM;
goto _out1;
}
vxge_debug_init(vxge_hw_device_trace_level_get(hldev),
"%s : checksuming enabled", __func__);
if (high_dma) {
ndev->features |= NETIF_F_HIGHDMA;
vxge_debug_init(vxge_hw_device_trace_level_get(hldev),
"%s : using High DMA", __func__);
}
ret = register_netdev(ndev);
if (ret) {
vxge_debug_init(vxge_hw_device_trace_level_get(hldev),
"%s: %s : device registration failed!",
ndev->name, __func__);
goto _out2;
}
ndev->addr_len = ETH_ALEN;
netif_carrier_off(ndev);
vxge_debug_init(vxge_hw_device_trace_level_get(hldev),
"%s: Ethernet device registered",
ndev->name);
hldev->ndev = ndev;
*vdev_out = vdev;
status = vxge_hw_mrpcim_stats_access(
hldev,
VXGE_HW_STATS_OP_CLEAR_ALL_STATS,
0,
0,
&stat);
if (status == VXGE_HW_ERR_PRIVILAGED_OPEARATION)
vxge_debug_init(
vxge_hw_device_trace_level_get(hldev),
"%s: device stats clear returns"
"VXGE_HW_ERR_PRIVILAGED_OPEARATION", ndev->name);
vxge_debug_entryexit(vxge_hw_device_trace_level_get(hldev),
"%s: %s:%d Exiting...",
ndev->name, __func__, __LINE__);
return ret;
_out2:
kfree(vdev->vpaths);
_out1:
free_netdev(ndev);
_out0:
return ret;
}
static void vxge_device_unregister(struct __vxge_hw_device *hldev)
{
struct vxgedev *vdev;
struct net_device *dev;
char buf[IFNAMSIZ];
dev = hldev->ndev;
vdev = netdev_priv(dev);
vxge_debug_entryexit(vdev->level_trace, "%s: %s:%d", vdev->ndev->name,
__func__, __LINE__);
strncpy(buf, dev->name, IFNAMSIZ);
flush_work(&vdev->reset_task);
unregister_netdev(dev);
kfree(vdev->vpaths);
free_netdev(dev);
vxge_debug_init(vdev->level_trace, "%s: ethernet device unregistered",
buf);
vxge_debug_entryexit(vdev->level_trace, "%s: %s:%d Exiting...", buf,
__func__, __LINE__);
}
static void
vxge_callback_crit_err(struct __vxge_hw_device *hldev,
enum vxge_hw_event type, u64 vp_id)
{
struct net_device *dev = hldev->ndev;
struct vxgedev *vdev = netdev_priv(dev);
struct vxge_vpath *vpath = NULL;
int vpath_idx;
vxge_debug_entryexit(vdev->level_trace,
"%s: %s:%d", vdev->ndev->name, __func__, __LINE__);
vdev->cric_err_event = type;
for (vpath_idx = 0; vpath_idx < vdev->no_of_vpath; vpath_idx++) {
vpath = &vdev->vpaths[vpath_idx];
if (vpath->device_id == vp_id)
break;
}
if (!test_bit(__VXGE_STATE_RESET_CARD, &vdev->state)) {
if (type == VXGE_HW_EVENT_SLOT_FREEZE) {
vxge_debug_init(VXGE_ERR,
"%s: Slot is frozen", vdev->ndev->name);
} else if (type == VXGE_HW_EVENT_SERR) {
vxge_debug_init(VXGE_ERR,
"%s: Encountered Serious Error",
vdev->ndev->name);
} else if (type == VXGE_HW_EVENT_CRITICAL_ERR)
vxge_debug_init(VXGE_ERR,
"%s: Encountered Critical Error",
vdev->ndev->name);
}
if ((type == VXGE_HW_EVENT_SERR) ||
(type == VXGE_HW_EVENT_SLOT_FREEZE)) {
if (unlikely(vdev->exec_mode))
clear_bit(__VXGE_STATE_CARD_UP, &vdev->state);
} else if (type == VXGE_HW_EVENT_CRITICAL_ERR) {
vxge_hw_device_mask_all(hldev);
if (unlikely(vdev->exec_mode))
clear_bit(__VXGE_STATE_CARD_UP, &vdev->state);
} else if ((type == VXGE_HW_EVENT_FIFO_ERR) ||
(type == VXGE_HW_EVENT_VPATH_ERR)) {
if (unlikely(vdev->exec_mode))
clear_bit(__VXGE_STATE_CARD_UP, &vdev->state);
else {
if (!test_and_set_bit(vpath_idx, &vdev->vp_reset)) {
vxge_vpath_intr_disable(vdev, vpath_idx);
netif_tx_stop_queue(vpath->fifo.txq);
}
}
}
vxge_debug_entryexit(vdev->level_trace,
"%s: %s:%d Exiting...",
vdev->ndev->name, __func__, __LINE__);
}
static void verify_bandwidth(void)
{
int i, band_width, total = 0, equal_priority = 0;
for (i = 0; i < VXGE_HW_MAX_VIRTUAL_PATHS; i++) {
if (bw_percentage[i] == 0) {
equal_priority = 1;
break;
}
}
if (!equal_priority) {
for (i = 0; i < VXGE_HW_MAX_VIRTUAL_PATHS; i++) {
if (bw_percentage[i] == 0xFF)
break;
total += bw_percentage[i];
if (total > VXGE_HW_VPATH_BANDWIDTH_MAX) {
equal_priority = 1;
break;
}
}
}
if (!equal_priority) {
if (total < VXGE_HW_VPATH_BANDWIDTH_MAX) {
if (i < VXGE_HW_MAX_VIRTUAL_PATHS) {
band_width =
(VXGE_HW_VPATH_BANDWIDTH_MAX - total) /
(VXGE_HW_MAX_VIRTUAL_PATHS - i);
if (band_width < 2)
equal_priority = 1;
else {
for (; i < VXGE_HW_MAX_VIRTUAL_PATHS;
i++)
bw_percentage[i] =
band_width;
}
}
} else if (i < VXGE_HW_MAX_VIRTUAL_PATHS)
equal_priority = 1;
}
if (equal_priority) {
vxge_debug_init(VXGE_ERR,
"%s: Assigning equal bandwidth to all the vpaths",
VXGE_DRIVER_NAME);
bw_percentage[0] = VXGE_HW_VPATH_BANDWIDTH_MAX /
VXGE_HW_MAX_VIRTUAL_PATHS;
for (i = 1; i < VXGE_HW_MAX_VIRTUAL_PATHS; i++)
bw_percentage[i] = bw_percentage[0];
}
}
static int vxge_config_vpaths(struct vxge_hw_device_config *device_config,
u64 vpath_mask, struct vxge_config *config_param)
{
int i, no_of_vpaths = 0, default_no_vpath = 0, temp;
u32 txdl_size, txdl_per_memblock;
temp = driver_config->vpath_per_dev;
if ((driver_config->vpath_per_dev == VXGE_USE_DEFAULT) &&
(max_config_dev == VXGE_MAX_CONFIG_DEV)) {
if (driver_config->g_no_cpus == -1)
return 0;
if (!driver_config->g_no_cpus)
driver_config->g_no_cpus =
netif_get_num_default_rss_queues();
driver_config->vpath_per_dev = driver_config->g_no_cpus >> 1;
if (!driver_config->vpath_per_dev)
driver_config->vpath_per_dev = 1;
for (i = 0; i < VXGE_HW_MAX_VIRTUAL_PATHS; i++)
if (!vxge_bVALn(vpath_mask, i, 1))
continue;
else
default_no_vpath++;
if (default_no_vpath < driver_config->vpath_per_dev)
driver_config->vpath_per_dev = default_no_vpath;
driver_config->g_no_cpus = driver_config->g_no_cpus -
(driver_config->vpath_per_dev * 2);
if (driver_config->g_no_cpus <= 0)
driver_config->g_no_cpus = -1;
}
if (driver_config->vpath_per_dev == 1) {
vxge_debug_ll_config(VXGE_TRACE,
"%s: Disable tx and rx steering, "
"as single vpath is configured", VXGE_DRIVER_NAME);
config_param->rth_steering = NO_STEERING;
config_param->tx_steering_type = NO_STEERING;
device_config->rth_en = 0;
}
for (i = 0; i < VXGE_HW_MAX_VIRTUAL_PATHS; i++)
device_config->vp_config[i].min_bandwidth = bw_percentage[i];
for (i = 0; i < VXGE_HW_MAX_VIRTUAL_PATHS; i++) {
device_config->vp_config[i].vp_id = i;
device_config->vp_config[i].mtu = VXGE_HW_DEFAULT_MTU;
if (no_of_vpaths < driver_config->vpath_per_dev) {
if (!vxge_bVALn(vpath_mask, i, 1)) {
vxge_debug_ll_config(VXGE_TRACE,
"%s: vpath: %d is not available",
VXGE_DRIVER_NAME, i);
continue;
} else {
vxge_debug_ll_config(VXGE_TRACE,
"%s: vpath: %d available",
VXGE_DRIVER_NAME, i);
no_of_vpaths++;
}
} else {
vxge_debug_ll_config(VXGE_TRACE,
"%s: vpath: %d is not configured, "
"max_config_vpath exceeded",
VXGE_DRIVER_NAME, i);
break;
}
device_config->vp_config[i].fifo.enable =
VXGE_HW_FIFO_ENABLE;
device_config->vp_config[i].fifo.max_frags =
MAX_SKB_FRAGS + 1;
device_config->vp_config[i].fifo.memblock_size =
VXGE_HW_MIN_FIFO_MEMBLOCK_SIZE;
txdl_size = device_config->vp_config[i].fifo.max_frags *
sizeof(struct vxge_hw_fifo_txd);
txdl_per_memblock = VXGE_HW_MIN_FIFO_MEMBLOCK_SIZE / txdl_size;
device_config->vp_config[i].fifo.fifo_blocks =
((VXGE_DEF_FIFO_LENGTH - 1) / txdl_per_memblock) + 1;
device_config->vp_config[i].fifo.intr =
VXGE_HW_FIFO_QUEUE_INTR_DISABLE;
device_config->vp_config[i].tti.intr_enable =
VXGE_HW_TIM_INTR_ENABLE;
device_config->vp_config[i].tti.btimer_val =
(VXGE_TTI_BTIMER_VAL * 1000) / 272;
device_config->vp_config[i].tti.timer_ac_en =
VXGE_HW_TIM_TIMER_AC_ENABLE;
device_config->vp_config[i].tti.timer_ci_en =
VXGE_HW_TIM_TIMER_CI_DISABLE;
device_config->vp_config[i].tti.timer_ri_en =
VXGE_HW_TIM_TIMER_RI_DISABLE;
device_config->vp_config[i].tti.util_sel =
VXGE_HW_TIM_UTIL_SEL_LEGACY_TX_NET_UTIL;
device_config->vp_config[i].tti.ltimer_val =
(VXGE_TTI_LTIMER_VAL * 1000) / 272;
device_config->vp_config[i].tti.rtimer_val =
(VXGE_TTI_RTIMER_VAL * 1000) / 272;
device_config->vp_config[i].tti.urange_a = TTI_TX_URANGE_A;
device_config->vp_config[i].tti.urange_b = TTI_TX_URANGE_B;
device_config->vp_config[i].tti.urange_c = TTI_TX_URANGE_C;
device_config->vp_config[i].tti.uec_a = TTI_TX_UFC_A;
device_config->vp_config[i].tti.uec_b = TTI_TX_UFC_B;
device_config->vp_config[i].tti.uec_c = TTI_TX_UFC_C;
device_config->vp_config[i].tti.uec_d = TTI_TX_UFC_D;
device_config->vp_config[i].ring.enable =
VXGE_HW_RING_ENABLE;
device_config->vp_config[i].ring.ring_blocks =
VXGE_HW_DEF_RING_BLOCKS;
device_config->vp_config[i].ring.buffer_mode =
VXGE_HW_RING_RXD_BUFFER_MODE_1;
device_config->vp_config[i].ring.rxds_limit =
VXGE_HW_DEF_RING_RXDS_LIMIT;
device_config->vp_config[i].ring.scatter_mode =
VXGE_HW_RING_SCATTER_MODE_A;
device_config->vp_config[i].rti.intr_enable =
VXGE_HW_TIM_INTR_ENABLE;
device_config->vp_config[i].rti.btimer_val =
(VXGE_RTI_BTIMER_VAL * 1000)/272;
device_config->vp_config[i].rti.timer_ac_en =
VXGE_HW_TIM_TIMER_AC_ENABLE;
device_config->vp_config[i].rti.timer_ci_en =
VXGE_HW_TIM_TIMER_CI_DISABLE;
device_config->vp_config[i].rti.timer_ri_en =
VXGE_HW_TIM_TIMER_RI_DISABLE;
device_config->vp_config[i].rti.util_sel =
VXGE_HW_TIM_UTIL_SEL_LEGACY_RX_NET_UTIL;
device_config->vp_config[i].rti.urange_a =
RTI_RX_URANGE_A;
device_config->vp_config[i].rti.urange_b =
RTI_RX_URANGE_B;
device_config->vp_config[i].rti.urange_c =
RTI_RX_URANGE_C;
device_config->vp_config[i].rti.uec_a = RTI_RX_UFC_A;
device_config->vp_config[i].rti.uec_b = RTI_RX_UFC_B;
device_config->vp_config[i].rti.uec_c = RTI_RX_UFC_C;
device_config->vp_config[i].rti.uec_d = RTI_RX_UFC_D;
device_config->vp_config[i].rti.rtimer_val =
(VXGE_RTI_RTIMER_VAL * 1000) / 272;
device_config->vp_config[i].rti.ltimer_val =
(VXGE_RTI_LTIMER_VAL * 1000) / 272;
device_config->vp_config[i].rpa_strip_vlan_tag =
vlan_tag_strip;
}
driver_config->vpath_per_dev = temp;
return no_of_vpaths;
}
static void vxge_device_config_init(struct vxge_hw_device_config *device_config,
int *intr_type)
{
device_config->dma_blockpool_initial =
VXGE_HW_INITIAL_DMA_BLOCK_POOL_SIZE;
device_config->dma_blockpool_max =
VXGE_HW_MAX_DMA_BLOCK_POOL_SIZE;
if (max_mac_vpath > VXGE_MAX_MAC_ADDR_COUNT)
max_mac_vpath = VXGE_MAX_MAC_ADDR_COUNT;
#ifndef CONFIG_PCI_MSI
vxge_debug_init(VXGE_ERR,
"%s: This Kernel does not support "
"MSI-X. Defaulting to INTA", VXGE_DRIVER_NAME);
*intr_type = INTA;
#endif
switch (*intr_type) {
case INTA:
device_config->intr_mode = VXGE_HW_INTR_MODE_IRQLINE;
break;
case MSI_X:
device_config->intr_mode = VXGE_HW_INTR_MODE_MSIX_ONE_SHOT;
break;
}
device_config->device_poll_millis = VXGE_TIMER_DELAY;
device_config->rts_mac_en = addr_learn_en;
device_config->rth_it_type = VXGE_HW_RTH_IT_TYPE_MULTI_IT;
vxge_debug_ll_config(VXGE_TRACE, "%s : Device Config Params ",
__func__);
vxge_debug_ll_config(VXGE_TRACE, "intr_mode : %d",
device_config->intr_mode);
vxge_debug_ll_config(VXGE_TRACE, "device_poll_millis : %d",
device_config->device_poll_millis);
vxge_debug_ll_config(VXGE_TRACE, "rth_en : %d",
device_config->rth_en);
vxge_debug_ll_config(VXGE_TRACE, "rth_it_type : %d",
device_config->rth_it_type);
}
static void vxge_print_parm(struct vxgedev *vdev, u64 vpath_mask)
{
int i;
vxge_debug_init(VXGE_TRACE,
"%s: %d Vpath(s) opened",
vdev->ndev->name, vdev->no_of_vpath);
switch (vdev->config.intr_type) {
case INTA:
vxge_debug_init(VXGE_TRACE,
"%s: Interrupt type INTA", vdev->ndev->name);
break;
case MSI_X:
vxge_debug_init(VXGE_TRACE,
"%s: Interrupt type MSI-X", vdev->ndev->name);
break;
}
if (vdev->config.rth_steering) {
vxge_debug_init(VXGE_TRACE,
"%s: RTH steering enabled for TCP_IPV4",
vdev->ndev->name);
} else {
vxge_debug_init(VXGE_TRACE,
"%s: RTH steering disabled", vdev->ndev->name);
}
switch (vdev->config.tx_steering_type) {
case NO_STEERING:
vxge_debug_init(VXGE_TRACE,
"%s: Tx steering disabled", vdev->ndev->name);
break;
case TX_PRIORITY_STEERING:
vxge_debug_init(VXGE_TRACE,
"%s: Unsupported tx steering option",
vdev->ndev->name);
vxge_debug_init(VXGE_TRACE,
"%s: Tx steering disabled", vdev->ndev->name);
vdev->config.tx_steering_type = 0;
break;
case TX_VLAN_STEERING:
vxge_debug_init(VXGE_TRACE,
"%s: Unsupported tx steering option",
vdev->ndev->name);
vxge_debug_init(VXGE_TRACE,
"%s: Tx steering disabled", vdev->ndev->name);
vdev->config.tx_steering_type = 0;
break;
case TX_MULTIQ_STEERING:
vxge_debug_init(VXGE_TRACE,
"%s: Tx multiqueue steering enabled",
vdev->ndev->name);
break;
case TX_PORT_STEERING:
vxge_debug_init(VXGE_TRACE,
"%s: Tx port steering enabled",
vdev->ndev->name);
break;
default:
vxge_debug_init(VXGE_ERR,
"%s: Unsupported tx steering type",
vdev->ndev->name);
vxge_debug_init(VXGE_TRACE,
"%s: Tx steering disabled", vdev->ndev->name);
vdev->config.tx_steering_type = 0;
}
if (vdev->config.addr_learn_en)
vxge_debug_init(VXGE_TRACE,
"%s: MAC Address learning enabled", vdev->ndev->name);
for (i = 0; i < VXGE_HW_MAX_VIRTUAL_PATHS; i++) {
if (!vxge_bVALn(vpath_mask, i, 1))
continue;
vxge_debug_ll_config(VXGE_TRACE,
"%s: MTU size - %d", vdev->ndev->name,
((vdev->devh))->
config.vp_config[i].mtu);
vxge_debug_init(VXGE_TRACE,
"%s: VLAN tag stripping %s", vdev->ndev->name,
((vdev->devh))->
config.vp_config[i].rpa_strip_vlan_tag
? "Enabled" : "Disabled");
vxge_debug_ll_config(VXGE_TRACE,
"%s: Max frags : %d", vdev->ndev->name,
((vdev->devh))->
config.vp_config[i].fifo.max_frags);
break;
}
}
static int vxge_pm_suspend(struct pci_dev *pdev, pm_message_t state)
{
return -ENOSYS;
}
static int vxge_pm_resume(struct pci_dev *pdev)
{
return -ENOSYS;
}
static pci_ers_result_t vxge_io_error_detected(struct pci_dev *pdev,
pci_channel_state_t state)
{
struct __vxge_hw_device *hldev = pci_get_drvdata(pdev);
struct net_device *netdev = hldev->ndev;
netif_device_detach(netdev);
if (state == pci_channel_io_perm_failure)
return PCI_ERS_RESULT_DISCONNECT;
if (netif_running(netdev)) {
do_vxge_close(netdev, 0);
}
pci_disable_device(pdev);
return PCI_ERS_RESULT_NEED_RESET;
}
static pci_ers_result_t vxge_io_slot_reset(struct pci_dev *pdev)
{
struct __vxge_hw_device *hldev = pci_get_drvdata(pdev);
struct net_device *netdev = hldev->ndev;
struct vxgedev *vdev = netdev_priv(netdev);
if (pci_enable_device(pdev)) {
netdev_err(netdev, "Cannot re-enable device after reset\n");
return PCI_ERS_RESULT_DISCONNECT;
}
pci_set_master(pdev);
do_vxge_reset(vdev, VXGE_LL_FULL_RESET);
return PCI_ERS_RESULT_RECOVERED;
}
static void vxge_io_resume(struct pci_dev *pdev)
{
struct __vxge_hw_device *hldev = pci_get_drvdata(pdev);
struct net_device *netdev = hldev->ndev;
if (netif_running(netdev)) {
if (vxge_open(netdev)) {
netdev_err(netdev,
"Can't bring device back up after reset\n");
return;
}
}
netif_device_attach(netdev);
}
static inline u32 vxge_get_num_vfs(u64 function_mode)
{
u32 num_functions = 0;
switch (function_mode) {
case VXGE_HW_FUNCTION_MODE_MULTI_FUNCTION:
case VXGE_HW_FUNCTION_MODE_SRIOV_8:
num_functions = 8;
break;
case VXGE_HW_FUNCTION_MODE_SINGLE_FUNCTION:
num_functions = 1;
break;
case VXGE_HW_FUNCTION_MODE_SRIOV:
case VXGE_HW_FUNCTION_MODE_MRIOV:
case VXGE_HW_FUNCTION_MODE_MULTI_FUNCTION_17:
num_functions = 17;
break;
case VXGE_HW_FUNCTION_MODE_SRIOV_4:
num_functions = 4;
break;
case VXGE_HW_FUNCTION_MODE_MULTI_FUNCTION_2:
num_functions = 2;
break;
case VXGE_HW_FUNCTION_MODE_MRIOV_8:
num_functions = 8;
break;
}
return num_functions;
}
int vxge_fw_upgrade(struct vxgedev *vdev, char *fw_name, int override)
{
struct __vxge_hw_device *hldev = vdev->devh;
u32 maj, min, bld, cmaj, cmin, cbld;
enum vxge_hw_status status;
const struct firmware *fw;
int ret;
ret = request_firmware(&fw, fw_name, &vdev->pdev->dev);
if (ret) {
vxge_debug_init(VXGE_ERR, "%s: Firmware file '%s' not found",
VXGE_DRIVER_NAME, fw_name);
goto out;
}
status = vxge_update_fw_image(hldev, fw->data, fw->size);
if (status != VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR,
"%s: FW image download to adapter failed '%s'.",
VXGE_DRIVER_NAME, fw_name);
ret = -EIO;
goto out;
}
status = vxge_hw_upgrade_read_version(hldev, &maj, &min, &bld);
if (status != VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR,
"%s: Upgrade read version failed '%s'.",
VXGE_DRIVER_NAME, fw_name);
ret = -EIO;
goto out;
}
cmaj = vdev->config.device_hw_info.fw_version.major;
cmin = vdev->config.device_hw_info.fw_version.minor;
cbld = vdev->config.device_hw_info.fw_version.build;
if (VXGE_FW_VER(maj, min, bld) == VXGE_FW_VER(cmaj, cmin, cbld) &&
!override) {
ret = -EINVAL;
goto out;
}
printk(KERN_NOTICE "Upgrade to firmware version %d.%d.%d commencing\n",
maj, min, bld);
status = vxge_hw_flash_fw(hldev);
if (status != VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR, "%s: Upgrade commit failed '%s'.",
VXGE_DRIVER_NAME, fw_name);
ret = -EIO;
goto out;
}
printk(KERN_NOTICE "Upgrade of firmware successful! Adapter must be "
"hard reset before using, thus requiring a system reboot or a "
"hotplug event.\n");
out:
release_firmware(fw);
return ret;
}
static int vxge_probe_fw_update(struct vxgedev *vdev)
{
u32 maj, min, bld;
int ret, gpxe = 0;
char *fw_name;
maj = vdev->config.device_hw_info.fw_version.major;
min = vdev->config.device_hw_info.fw_version.minor;
bld = vdev->config.device_hw_info.fw_version.build;
if (VXGE_FW_VER(maj, min, bld) == VXGE_CERT_FW_VER)
return 0;
if (VXGE_FW_VER(maj, min, 0) > VXGE_CERT_FW_VER) {
vxge_debug_init(VXGE_ERR, "%s: Firmware newer than last known "
"version, unable to load driver\n",
VXGE_DRIVER_NAME);
return -EINVAL;
}
if (VXGE_FW_VER(maj, min, bld) <= VXGE_FW_DEAD_VER) {
vxge_debug_init(VXGE_ERR, "%s: Firmware %d.%d.%d cannot be "
"upgraded\n", VXGE_DRIVER_NAME, maj, min, bld);
return -EINVAL;
}
if (VXGE_FW_VER(maj, min, bld) >= VXGE_EPROM_FW_VER) {
int i;
for (i = 0; i < VXGE_HW_MAX_ROM_IMAGES; i++)
if (vdev->devh->eprom_versions[i]) {
gpxe = 1;
break;
}
}
if (gpxe)
fw_name = "vxge/X3fw-pxe.ncf";
else
fw_name = "vxge/X3fw.ncf";
ret = vxge_fw_upgrade(vdev, fw_name, 0);
if (ret != -EINVAL && ret != -ENOENT)
return -EIO;
else
ret = 0;
if (VXGE_FW_VER(VXGE_CERT_FW_VER_MAJOR, VXGE_CERT_FW_VER_MINOR, 0) >
VXGE_FW_VER(maj, min, 0)) {
vxge_debug_init(VXGE_ERR, "%s: Firmware %d.%d.%d is too old to"
" be used with this driver.",
VXGE_DRIVER_NAME, maj, min, bld);
return -EINVAL;
}
return ret;
}
static int is_sriov_initialized(struct pci_dev *pdev)
{
int pos;
u16 ctrl;
pos = pci_find_ext_capability(pdev, PCI_EXT_CAP_ID_SRIOV);
if (pos) {
pci_read_config_word(pdev, pos + PCI_SRIOV_CTRL, &ctrl);
if (ctrl & PCI_SRIOV_CTRL_VFE)
return 1;
}
return 0;
}
static int
vxge_probe(struct pci_dev *pdev, const struct pci_device_id *pre)
{
struct __vxge_hw_device *hldev;
enum vxge_hw_status status;
int ret;
int high_dma = 0;
u64 vpath_mask = 0;
struct vxgedev *vdev;
struct vxge_config *ll_config = NULL;
struct vxge_hw_device_config *device_config = NULL;
struct vxge_hw_device_attr attr;
int i, j, no_of_vpath = 0, max_vpath_supported = 0;
u8 *macaddr;
struct vxge_mac_addrs *entry;
static int bus = -1, device = -1;
u32 host_type;
u8 new_device = 0;
enum vxge_hw_status is_privileged;
u32 function_mode;
u32 num_vfs = 0;
vxge_debug_entryexit(VXGE_TRACE, "%s:%d", __func__, __LINE__);
attr.pdev = pdev;
if (((bus != pdev->bus->number) || (device != PCI_SLOT(pdev->devfn))) &&
!pdev->is_virtfn)
new_device = 1;
bus = pdev->bus->number;
device = PCI_SLOT(pdev->devfn);
if (new_device) {
if (driver_config->config_dev_cnt &&
(driver_config->config_dev_cnt !=
driver_config->total_dev_cnt))
vxge_debug_init(VXGE_ERR,
"%s: Configured %d of %d devices",
VXGE_DRIVER_NAME,
driver_config->config_dev_cnt,
driver_config->total_dev_cnt);
driver_config->config_dev_cnt = 0;
driver_config->total_dev_cnt = 0;
}
driver_config->g_no_cpus = 0;
driver_config->vpath_per_dev = max_config_vpath;
driver_config->total_dev_cnt++;
if (++driver_config->config_dev_cnt > max_config_dev) {
ret = 0;
goto _exit0;
}
device_config = kzalloc(sizeof(struct vxge_hw_device_config),
GFP_KERNEL);
if (!device_config) {
ret = -ENOMEM;
vxge_debug_init(VXGE_ERR,
"device_config : malloc failed %s %d",
__FILE__, __LINE__);
goto _exit0;
}
ll_config = kzalloc(sizeof(struct vxge_config), GFP_KERNEL);
if (!ll_config) {
ret = -ENOMEM;
vxge_debug_init(VXGE_ERR,
"device_config : malloc failed %s %d",
__FILE__, __LINE__);
goto _exit0;
}
ll_config->tx_steering_type = TX_MULTIQ_STEERING;
ll_config->intr_type = MSI_X;
ll_config->napi_weight = NEW_NAPI_WEIGHT;
ll_config->rth_steering = RTH_STEERING;
vxge_hw_device_config_default_get(device_config);
vxge_device_config_init(device_config, &ll_config->intr_type);
ret = pci_enable_device(pdev);
if (ret) {
vxge_debug_init(VXGE_ERR,
"%s : can not enable PCI device", __func__);
goto _exit0;
}
if (!pci_set_dma_mask(pdev, DMA_BIT_MASK(64))) {
vxge_debug_ll_config(VXGE_TRACE,
"%s : using 64bit DMA", __func__);
high_dma = 1;
if (pci_set_consistent_dma_mask(pdev,
DMA_BIT_MASK(64))) {
vxge_debug_init(VXGE_ERR,
"%s : unable to obtain 64bit DMA for "
"consistent allocations", __func__);
ret = -ENOMEM;
goto _exit1;
}
} else if (!pci_set_dma_mask(pdev, DMA_BIT_MASK(32))) {
vxge_debug_ll_config(VXGE_TRACE,
"%s : using 32bit DMA", __func__);
} else {
ret = -ENOMEM;
goto _exit1;
}
ret = pci_request_region(pdev, 0, VXGE_DRIVER_NAME);
if (ret) {
vxge_debug_init(VXGE_ERR,
"%s : request regions failed", __func__);
goto _exit1;
}
pci_set_master(pdev);
attr.bar0 = pci_ioremap_bar(pdev, 0);
if (!attr.bar0) {
vxge_debug_init(VXGE_ERR,
"%s : cannot remap io memory bar0", __func__);
ret = -ENODEV;
goto _exit2;
}
vxge_debug_ll_config(VXGE_TRACE,
"pci ioremap bar0: %p:0x%llx",
attr.bar0,
(unsigned long long)pci_resource_start(pdev, 0));
status = vxge_hw_device_hw_info_get(attr.bar0,
&ll_config->device_hw_info);
if (status != VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR,
"%s: Reading of hardware info failed."
"Please try upgrading the firmware.", VXGE_DRIVER_NAME);
ret = -EINVAL;
goto _exit3;
}
vpath_mask = ll_config->device_hw_info.vpath_mask;
if (vpath_mask == 0) {
vxge_debug_ll_config(VXGE_TRACE,
"%s: No vpaths available in device", VXGE_DRIVER_NAME);
ret = -EINVAL;
goto _exit3;
}
vxge_debug_ll_config(VXGE_TRACE,
"%s:%d Vpath mask = %llx", __func__, __LINE__,
(unsigned long long)vpath_mask);
function_mode = ll_config->device_hw_info.function_mode;
host_type = ll_config->device_hw_info.host_type;
is_privileged = __vxge_hw_device_is_privilaged(host_type,
ll_config->device_hw_info.func_id);
for (i = 0; i < VXGE_HW_MAX_VIRTUAL_PATHS; i++) {
if (!((vpath_mask) & vxge_mBIT(i)))
continue;
max_vpath_supported++;
}
if (new_device)
num_vfs = vxge_get_num_vfs(function_mode) - 1;
if (is_sriov(function_mode) && !is_sriov_initialized(pdev) &&
(ll_config->intr_type != INTA)) {
ret = pci_enable_sriov(pdev, num_vfs);
if (ret)
vxge_debug_ll_config(VXGE_ERR,
"Failed in enabling SRIOV mode: %d\n", ret);
}
no_of_vpath = vxge_config_vpaths(device_config, vpath_mask, ll_config);
if (!no_of_vpath) {
vxge_debug_ll_config(VXGE_ERR,
"%s: No more vpaths to configure", VXGE_DRIVER_NAME);
ret = 0;
goto _exit3;
}
attr.uld_callbacks = &vxge_callbacks;
status = vxge_hw_device_initialize(&hldev, &attr, device_config);
if (status != VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR,
"Failed to initialize device (%d)", status);
ret = -EINVAL;
goto _exit3;
}
if (VXGE_FW_VER(ll_config->device_hw_info.fw_version.major,
ll_config->device_hw_info.fw_version.minor,
ll_config->device_hw_info.fw_version.build) >=
VXGE_EPROM_FW_VER) {
struct eprom_image img[VXGE_HW_MAX_ROM_IMAGES];
status = vxge_hw_vpath_eprom_img_ver_get(hldev, img);
if (status != VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR, "%s: Reading of EPROM failed",
VXGE_DRIVER_NAME);
}
for (i = 0; i < VXGE_HW_MAX_ROM_IMAGES; i++) {
hldev->eprom_versions[i] = img[i].version;
if (!img[i].is_valid)
break;
vxge_debug_init(VXGE_TRACE, "%s: EPROM %d, version "
"%d.%d.%d.%d", VXGE_DRIVER_NAME, i,
VXGE_EPROM_IMG_MAJOR(img[i].version),
VXGE_EPROM_IMG_MINOR(img[i].version),
VXGE_EPROM_IMG_FIX(img[i].version),
VXGE_EPROM_IMG_BUILD(img[i].version));
}
}
status = vxge_hw_vpath_strip_fcs_check(hldev, vpath_mask);
if (status != VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR, "%s: FCS stripping is enabled in MAC"
" failing driver load", VXGE_DRIVER_NAME);
ret = -EINVAL;
goto _exit4;
}
if (is_privileged == VXGE_HW_OK) {
status = vxge_timestamp_config(hldev);
if (status != VXGE_HW_OK) {
vxge_debug_init(VXGE_ERR, "%s: HWTS enable failed",
VXGE_DRIVER_NAME);
ret = -EFAULT;
goto _exit4;
}
}
vxge_hw_device_debug_set(hldev, VXGE_ERR, VXGE_COMPONENT_LL);
pci_set_drvdata(pdev, hldev);
ll_config->fifo_indicate_max_pkts = VXGE_FIFO_INDICATE_MAX_PKTS;
ll_config->addr_learn_en = addr_learn_en;
ll_config->rth_algorithm = RTH_ALG_JENKINS;
ll_config->rth_hash_type_tcpipv4 = 1;
ll_config->rth_hash_type_ipv4 = 0;
ll_config->rth_hash_type_tcpipv6 = 0;
ll_config->rth_hash_type_ipv6 = 0;
ll_config->rth_hash_type_tcpipv6ex = 0;
ll_config->rth_hash_type_ipv6ex = 0;
ll_config->rth_bkt_sz = RTH_BUCKET_SIZE;
ll_config->tx_pause_enable = VXGE_PAUSE_CTRL_ENABLE;
ll_config->rx_pause_enable = VXGE_PAUSE_CTRL_ENABLE;
ret = vxge_device_register(hldev, ll_config, high_dma, no_of_vpath,
&vdev);
if (ret) {
ret = -EINVAL;
goto _exit4;
}
ret = vxge_probe_fw_update(vdev);
if (ret)
goto _exit5;
vxge_hw_device_debug_set(hldev, VXGE_TRACE, VXGE_COMPONENT_LL);
VXGE_COPY_DEBUG_INFO_TO_LL(vdev, vxge_hw_device_error_level_get(hldev),
vxge_hw_device_trace_level_get(hldev));
vdev->mtu = VXGE_HW_DEFAULT_MTU;
vdev->bar0 = attr.bar0;
vdev->max_vpath_supported = max_vpath_supported;
vdev->no_of_vpath = no_of_vpath;
for (i = 0, j = 0; i < VXGE_HW_MAX_VIRTUAL_PATHS; i++) {
if (!vxge_bVALn(vpath_mask, i, 1))
continue;
if (j >= vdev->no_of_vpath)
break;
vdev->vpaths[j].is_configured = 1;
vdev->vpaths[j].device_id = i;
vdev->vpaths[j].ring.driver_id = j;
vdev->vpaths[j].vdev = vdev;
vdev->vpaths[j].max_mac_addr_cnt = max_mac_vpath;
memcpy((u8 *)vdev->vpaths[j].macaddr,
ll_config->device_hw_info.mac_addrs[i],
ETH_ALEN);
INIT_LIST_HEAD(&vdev->vpaths[j].mac_addr_list);
vdev->vpaths[j].mac_addr_cnt = 0;
vdev->vpaths[j].mcast_addr_cnt = 0;
j++;
}
vdev->exec_mode = VXGE_EXEC_MODE_DISABLE;
vdev->max_config_port = max_config_port;
vdev->vlan_tag_strip = vlan_tag_strip;
for (i = 0; i < vdev->no_of_vpath; i++)
vdev->vpath_selector[i] = vpath_selector[i];
macaddr = (u8 *)vdev->vpaths[0].macaddr;
ll_config->device_hw_info.serial_number[VXGE_HW_INFO_LEN - 1] = '\0';
ll_config->device_hw_info.product_desc[VXGE_HW_INFO_LEN - 1] = '\0';
ll_config->device_hw_info.part_number[VXGE_HW_INFO_LEN - 1] = '\0';
vxge_debug_init(VXGE_TRACE, "%s: SERIAL NUMBER: %s",
vdev->ndev->name, ll_config->device_hw_info.serial_number);
vxge_debug_init(VXGE_TRACE, "%s: PART NUMBER: %s",
vdev->ndev->name, ll_config->device_hw_info.part_number);
vxge_debug_init(VXGE_TRACE, "%s: Neterion %s Server Adapter",
vdev->ndev->name, ll_config->device_hw_info.product_desc);
vxge_debug_init(VXGE_TRACE, "%s: MAC ADDR: %pM",
vdev->ndev->name, macaddr);
vxge_debug_init(VXGE_TRACE, "%s: Link Width x%d",
vdev->ndev->name, vxge_hw_device_link_width_get(hldev));
vxge_debug_init(VXGE_TRACE,
"%s: Firmware version : %s Date : %s", vdev->ndev->name,
ll_config->device_hw_info.fw_version.version,
ll_config->device_hw_info.fw_date.date);
if (new_device) {
switch (ll_config->device_hw_info.function_mode) {
case VXGE_HW_FUNCTION_MODE_SINGLE_FUNCTION:
vxge_debug_init(VXGE_TRACE,
"%s: Single Function Mode Enabled", vdev->ndev->name);
break;
case VXGE_HW_FUNCTION_MODE_MULTI_FUNCTION:
vxge_debug_init(VXGE_TRACE,
"%s: Multi Function Mode Enabled", vdev->ndev->name);
break;
case VXGE_HW_FUNCTION_MODE_SRIOV:
vxge_debug_init(VXGE_TRACE,
"%s: Single Root IOV Mode Enabled", vdev->ndev->name);
break;
case VXGE_HW_FUNCTION_MODE_MRIOV:
vxge_debug_init(VXGE_TRACE,
"%s: Multi Root IOV Mode Enabled", vdev->ndev->name);
break;
}
}
vxge_print_parm(vdev, vpath_mask);
strcpy(vdev->fw_version, ll_config->device_hw_info.fw_version.version);
memcpy(vdev->ndev->dev_addr, (u8 *)vdev->vpaths[0].macaddr, ETH_ALEN);
for (i = 0; i < vdev->no_of_vpath; i++) {
entry = kzalloc(sizeof(struct vxge_mac_addrs), GFP_KERNEL);
if (NULL == entry) {
vxge_debug_init(VXGE_ERR,
"%s: mac_addr_list : memory allocation failed",
vdev->ndev->name);
ret = -EPERM;
goto _exit6;
}
macaddr = (u8 *)&entry->macaddr;
memcpy(macaddr, vdev->ndev->dev_addr, ETH_ALEN);
list_add(&entry->item, &vdev->vpaths[i].mac_addr_list);
vdev->vpaths[i].mac_addr_cnt = 1;
}
kfree(device_config);
if (ll_config->device_hw_info.function_mode ==
VXGE_HW_FUNCTION_MODE_MULTI_FUNCTION)
if (vdev->config.intr_type == INTA)
vxge_hw_device_unmask_all(hldev);
vxge_debug_entryexit(VXGE_TRACE, "%s: %s:%d Exiting...",
vdev->ndev->name, __func__, __LINE__);
vxge_hw_device_debug_set(hldev, VXGE_ERR, VXGE_COMPONENT_LL);
VXGE_COPY_DEBUG_INFO_TO_LL(vdev, vxge_hw_device_error_level_get(hldev),
vxge_hw_device_trace_level_get(hldev));
kfree(ll_config);
return 0;
_exit6:
for (i = 0; i < vdev->no_of_vpath; i++)
vxge_free_mac_add_list(&vdev->vpaths[i]);
_exit5:
vxge_device_unregister(hldev);
_exit4:
pci_set_drvdata(pdev, NULL);
vxge_hw_device_terminate(hldev);
pci_disable_sriov(pdev);
_exit3:
iounmap(attr.bar0);
_exit2:
pci_release_region(pdev, 0);
_exit1:
pci_disable_device(pdev);
_exit0:
kfree(ll_config);
kfree(device_config);
driver_config->config_dev_cnt--;
driver_config->total_dev_cnt--;
return ret;
}
static void vxge_remove(struct pci_dev *pdev)
{
struct __vxge_hw_device *hldev;
struct vxgedev *vdev;
int i;
hldev = pci_get_drvdata(pdev);
if (hldev == NULL)
return;
vdev = netdev_priv(hldev->ndev);
vxge_debug_entryexit(vdev->level_trace, "%s:%d", __func__, __LINE__);
vxge_debug_init(vdev->level_trace, "%s : removing PCI device...",
__func__);
for (i = 0; i < vdev->no_of_vpath; i++)
vxge_free_mac_add_list(&vdev->vpaths[i]);
vxge_device_unregister(hldev);
pci_set_drvdata(pdev, NULL);
vxge_hw_device_terminate(hldev);
iounmap(vdev->bar0);
pci_release_region(pdev, 0);
pci_disable_device(pdev);
driver_config->config_dev_cnt--;
driver_config->total_dev_cnt--;
vxge_debug_init(vdev->level_trace, "%s:%d Device unregistered",
__func__, __LINE__);
vxge_debug_entryexit(vdev->level_trace, "%s:%d Exiting...", __func__,
__LINE__);
}
static int __init
vxge_starter(void)
{
int ret = 0;
pr_info("Copyright(c) 2002-2010 Exar Corp.\n");
pr_info("Driver version: %s\n", DRV_VERSION);
verify_bandwidth();
driver_config = kzalloc(sizeof(struct vxge_drv_config), GFP_KERNEL);
if (!driver_config)
return -ENOMEM;
ret = pci_register_driver(&vxge_driver);
if (ret) {
kfree(driver_config);
goto err;
}
if (driver_config->config_dev_cnt &&
(driver_config->config_dev_cnt != driver_config->total_dev_cnt))
vxge_debug_init(VXGE_ERR,
"%s: Configured %d of %d devices",
VXGE_DRIVER_NAME, driver_config->config_dev_cnt,
driver_config->total_dev_cnt);
err:
return ret;
}
static void __exit
vxge_closer(void)
{
pci_unregister_driver(&vxge_driver);
kfree(driver_config);
}
