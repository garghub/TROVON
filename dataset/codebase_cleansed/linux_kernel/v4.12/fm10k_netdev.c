int fm10k_setup_tx_resources(struct fm10k_ring *tx_ring)
{
struct device *dev = tx_ring->dev;
int size;
size = sizeof(struct fm10k_tx_buffer) * tx_ring->count;
tx_ring->tx_buffer = vzalloc(size);
if (!tx_ring->tx_buffer)
goto err;
u64_stats_init(&tx_ring->syncp);
tx_ring->size = tx_ring->count * sizeof(struct fm10k_tx_desc);
tx_ring->size = ALIGN(tx_ring->size, 4096);
tx_ring->desc = dma_alloc_coherent(dev, tx_ring->size,
&tx_ring->dma, GFP_KERNEL);
if (!tx_ring->desc)
goto err;
return 0;
err:
vfree(tx_ring->tx_buffer);
tx_ring->tx_buffer = NULL;
return -ENOMEM;
}
static int fm10k_setup_all_tx_resources(struct fm10k_intfc *interface)
{
int i, err = 0;
for (i = 0; i < interface->num_tx_queues; i++) {
err = fm10k_setup_tx_resources(interface->tx_ring[i]);
if (!err)
continue;
netif_err(interface, probe, interface->netdev,
"Allocation for Tx Queue %u failed\n", i);
goto err_setup_tx;
}
return 0;
err_setup_tx:
while (i--)
fm10k_free_tx_resources(interface->tx_ring[i]);
return err;
}
int fm10k_setup_rx_resources(struct fm10k_ring *rx_ring)
{
struct device *dev = rx_ring->dev;
int size;
size = sizeof(struct fm10k_rx_buffer) * rx_ring->count;
rx_ring->rx_buffer = vzalloc(size);
if (!rx_ring->rx_buffer)
goto err;
u64_stats_init(&rx_ring->syncp);
rx_ring->size = rx_ring->count * sizeof(union fm10k_rx_desc);
rx_ring->size = ALIGN(rx_ring->size, 4096);
rx_ring->desc = dma_alloc_coherent(dev, rx_ring->size,
&rx_ring->dma, GFP_KERNEL);
if (!rx_ring->desc)
goto err;
return 0;
err:
vfree(rx_ring->rx_buffer);
rx_ring->rx_buffer = NULL;
return -ENOMEM;
}
static int fm10k_setup_all_rx_resources(struct fm10k_intfc *interface)
{
int i, err = 0;
for (i = 0; i < interface->num_rx_queues; i++) {
err = fm10k_setup_rx_resources(interface->rx_ring[i]);
if (!err)
continue;
netif_err(interface, probe, interface->netdev,
"Allocation for Rx Queue %u failed\n", i);
goto err_setup_rx;
}
return 0;
err_setup_rx:
while (i--)
fm10k_free_rx_resources(interface->rx_ring[i]);
return err;
}
void fm10k_unmap_and_free_tx_resource(struct fm10k_ring *ring,
struct fm10k_tx_buffer *tx_buffer)
{
if (tx_buffer->skb) {
dev_kfree_skb_any(tx_buffer->skb);
if (dma_unmap_len(tx_buffer, len))
dma_unmap_single(ring->dev,
dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
DMA_TO_DEVICE);
} else if (dma_unmap_len(tx_buffer, len)) {
dma_unmap_page(ring->dev,
dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
DMA_TO_DEVICE);
}
tx_buffer->next_to_watch = NULL;
tx_buffer->skb = NULL;
dma_unmap_len_set(tx_buffer, len, 0);
}
static void fm10k_clean_tx_ring(struct fm10k_ring *tx_ring)
{
struct fm10k_tx_buffer *tx_buffer;
unsigned long size;
u16 i;
if (!tx_ring->tx_buffer)
return;
for (i = 0; i < tx_ring->count; i++) {
tx_buffer = &tx_ring->tx_buffer[i];
fm10k_unmap_and_free_tx_resource(tx_ring, tx_buffer);
}
netdev_tx_reset_queue(txring_txq(tx_ring));
size = sizeof(struct fm10k_tx_buffer) * tx_ring->count;
memset(tx_ring->tx_buffer, 0, size);
memset(tx_ring->desc, 0, tx_ring->size);
}
void fm10k_free_tx_resources(struct fm10k_ring *tx_ring)
{
fm10k_clean_tx_ring(tx_ring);
vfree(tx_ring->tx_buffer);
tx_ring->tx_buffer = NULL;
if (!tx_ring->desc)
return;
dma_free_coherent(tx_ring->dev, tx_ring->size,
tx_ring->desc, tx_ring->dma);
tx_ring->desc = NULL;
}
void fm10k_clean_all_tx_rings(struct fm10k_intfc *interface)
{
int i;
for (i = 0; i < interface->num_tx_queues; i++)
fm10k_clean_tx_ring(interface->tx_ring[i]);
}
static void fm10k_free_all_tx_resources(struct fm10k_intfc *interface)
{
int i = interface->num_tx_queues;
while (i--)
fm10k_free_tx_resources(interface->tx_ring[i]);
}
static void fm10k_clean_rx_ring(struct fm10k_ring *rx_ring)
{
unsigned long size;
u16 i;
if (!rx_ring->rx_buffer)
return;
if (rx_ring->skb)
dev_kfree_skb(rx_ring->skb);
rx_ring->skb = NULL;
for (i = 0; i < rx_ring->count; i++) {
struct fm10k_rx_buffer *buffer = &rx_ring->rx_buffer[i];
if (!buffer->page)
continue;
dma_unmap_page(rx_ring->dev, buffer->dma,
PAGE_SIZE, DMA_FROM_DEVICE);
__free_page(buffer->page);
buffer->page = NULL;
}
size = sizeof(struct fm10k_rx_buffer) * rx_ring->count;
memset(rx_ring->rx_buffer, 0, size);
memset(rx_ring->desc, 0, rx_ring->size);
rx_ring->next_to_alloc = 0;
rx_ring->next_to_clean = 0;
rx_ring->next_to_use = 0;
}
void fm10k_free_rx_resources(struct fm10k_ring *rx_ring)
{
fm10k_clean_rx_ring(rx_ring);
vfree(rx_ring->rx_buffer);
rx_ring->rx_buffer = NULL;
if (!rx_ring->desc)
return;
dma_free_coherent(rx_ring->dev, rx_ring->size,
rx_ring->desc, rx_ring->dma);
rx_ring->desc = NULL;
}
void fm10k_clean_all_rx_rings(struct fm10k_intfc *interface)
{
int i;
for (i = 0; i < interface->num_rx_queues; i++)
fm10k_clean_rx_ring(interface->rx_ring[i]);
}
static void fm10k_free_all_rx_resources(struct fm10k_intfc *interface)
{
int i = interface->num_rx_queues;
while (i--)
fm10k_free_rx_resources(interface->rx_ring[i]);
}
static void fm10k_request_glort_range(struct fm10k_intfc *interface)
{
struct fm10k_hw *hw = &interface->hw;
u16 mask = (~hw->mac.dglort_map) >> FM10K_DGLORTMAP_MASK_SHIFT;
interface->glort = hw->mac.dglort_map & FM10K_DGLORTMAP_NONE;
interface->glort_count = 0;
if (hw->mac.dglort_map == FM10K_DGLORTMAP_NONE)
return;
if (mask <= hw->iov.total_vfs) {
interface->glort_count = 1;
interface->glort += mask;
} else if (mask < 64) {
interface->glort_count = (mask + 1) / 2;
interface->glort += interface->glort_count;
} else {
interface->glort_count = mask - 63;
interface->glort += 64;
}
}
static void fm10k_free_udp_port_info(struct fm10k_intfc *interface)
{
struct fm10k_udp_port *port;
port = list_first_entry_or_null(&interface->vxlan_port,
struct fm10k_udp_port, list);
while (port) {
list_del(&port->list);
kfree(port);
port = list_first_entry_or_null(&interface->vxlan_port,
struct fm10k_udp_port,
list);
}
port = list_first_entry_or_null(&interface->geneve_port,
struct fm10k_udp_port, list);
while (port) {
list_del(&port->list);
kfree(port);
port = list_first_entry_or_null(&interface->vxlan_port,
struct fm10k_udp_port,
list);
}
}
static void fm10k_restore_udp_port_info(struct fm10k_intfc *interface)
{
struct fm10k_hw *hw = &interface->hw;
struct fm10k_udp_port *port;
if (hw->mac.type != fm10k_mac_pf)
return;
port = list_first_entry_or_null(&interface->vxlan_port,
struct fm10k_udp_port, list);
fm10k_write_reg(hw, FM10K_TUNNEL_CFG,
(port ? ntohs(port->port) : 0) |
(ETH_P_TEB << FM10K_TUNNEL_CFG_NVGRE_SHIFT));
port = list_first_entry_or_null(&interface->geneve_port,
struct fm10k_udp_port, list);
fm10k_write_reg(hw, FM10K_TUNNEL_CFG_GENEVE,
(port ? ntohs(port->port) : 0));
}
static struct fm10k_udp_port *
fm10k_remove_tunnel_port(struct list_head *ports,
struct udp_tunnel_info *ti)
{
struct fm10k_udp_port *port;
list_for_each_entry(port, ports, list) {
if ((port->port == ti->port) &&
(port->sa_family == ti->sa_family)) {
list_del(&port->list);
return port;
}
}
return NULL;
}
static void fm10k_insert_tunnel_port(struct list_head *ports,
struct udp_tunnel_info *ti)
{
struct fm10k_udp_port *port;
port = fm10k_remove_tunnel_port(ports, ti);
if (!port) {
port = kmalloc(sizeof(*port), GFP_ATOMIC);
if (!port)
return;
port->port = ti->port;
port->sa_family = ti->sa_family;
}
list_add_tail(&port->list, ports);
}
static void fm10k_udp_tunnel_add(struct net_device *dev,
struct udp_tunnel_info *ti)
{
struct fm10k_intfc *interface = netdev_priv(dev);
if (interface->hw.mac.type != fm10k_mac_pf)
return;
switch (ti->type) {
case UDP_TUNNEL_TYPE_VXLAN:
fm10k_insert_tunnel_port(&interface->vxlan_port, ti);
break;
case UDP_TUNNEL_TYPE_GENEVE:
fm10k_insert_tunnel_port(&interface->geneve_port, ti);
break;
default:
return;
}
fm10k_restore_udp_port_info(interface);
}
static void fm10k_udp_tunnel_del(struct net_device *dev,
struct udp_tunnel_info *ti)
{
struct fm10k_intfc *interface = netdev_priv(dev);
struct fm10k_udp_port *port = NULL;
if (interface->hw.mac.type != fm10k_mac_pf)
return;
switch (ti->type) {
case UDP_TUNNEL_TYPE_VXLAN:
port = fm10k_remove_tunnel_port(&interface->vxlan_port, ti);
break;
case UDP_TUNNEL_TYPE_GENEVE:
port = fm10k_remove_tunnel_port(&interface->geneve_port, ti);
break;
default:
return;
}
kfree(port);
fm10k_restore_udp_port_info(interface);
}
int fm10k_open(struct net_device *netdev)
{
struct fm10k_intfc *interface = netdev_priv(netdev);
int err;
err = fm10k_setup_all_tx_resources(interface);
if (err)
goto err_setup_tx;
err = fm10k_setup_all_rx_resources(interface);
if (err)
goto err_setup_rx;
err = fm10k_qv_request_irq(interface);
if (err)
goto err_req_irq;
fm10k_request_glort_range(interface);
err = netif_set_real_num_tx_queues(netdev,
interface->num_tx_queues);
if (err)
goto err_set_queues;
err = netif_set_real_num_rx_queues(netdev,
interface->num_rx_queues);
if (err)
goto err_set_queues;
udp_tunnel_get_rx_info(netdev);
fm10k_up(interface);
return 0;
err_set_queues:
fm10k_qv_free_irq(interface);
err_req_irq:
fm10k_free_all_rx_resources(interface);
err_setup_rx:
fm10k_free_all_tx_resources(interface);
err_setup_tx:
return err;
}
int fm10k_close(struct net_device *netdev)
{
struct fm10k_intfc *interface = netdev_priv(netdev);
fm10k_down(interface);
fm10k_qv_free_irq(interface);
fm10k_free_udp_port_info(interface);
fm10k_free_all_tx_resources(interface);
fm10k_free_all_rx_resources(interface);
return 0;
}
static netdev_tx_t fm10k_xmit_frame(struct sk_buff *skb, struct net_device *dev)
{
struct fm10k_intfc *interface = netdev_priv(dev);
unsigned int r_idx = skb->queue_mapping;
int err;
if ((skb->protocol == htons(ETH_P_8021Q)) &&
!skb_vlan_tag_present(skb)) {
struct vlan_hdr *vhdr;
__be16 proto;
skb = skb_share_check(skb, GFP_ATOMIC);
if (!skb)
return NETDEV_TX_OK;
if (unlikely(!pskb_may_pull(skb, VLAN_ETH_HLEN)))
return NETDEV_TX_OK;
err = skb_cow_head(skb, 0);
if (err) {
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
vhdr = (struct vlan_hdr *)(skb->data + ETH_HLEN);
__vlan_hwaccel_put_tag(skb,
htons(ETH_P_8021Q),
ntohs(vhdr->h_vlan_TCI));
proto = vhdr->h_vlan_encapsulated_proto;
skb->protocol = (ntohs(proto) >= 1536) ? proto :
htons(ETH_P_802_2);
memmove(skb->data + VLAN_HLEN, skb->data, 12);
__skb_pull(skb, VLAN_HLEN);
skb_reset_mac_header(skb);
}
if (unlikely(skb->len < 17)) {
int pad_len = 17 - skb->len;
if (skb_pad(skb, pad_len))
return NETDEV_TX_OK;
__skb_put(skb, pad_len);
}
if (r_idx >= interface->num_tx_queues)
r_idx %= interface->num_tx_queues;
err = fm10k_xmit_frame_ring(skb, interface->tx_ring[r_idx]);
return err;
}
static void fm10k_tx_timeout(struct net_device *netdev)
{
struct fm10k_intfc *interface = netdev_priv(netdev);
bool real_tx_hang = false;
int i;
#define TX_TIMEO_LIMIT 16000
for (i = 0; i < interface->num_tx_queues; i++) {
struct fm10k_ring *tx_ring = interface->tx_ring[i];
if (check_for_tx_hang(tx_ring) && fm10k_check_tx_hang(tx_ring))
real_tx_hang = true;
}
if (real_tx_hang) {
fm10k_tx_timeout_reset(interface);
} else {
netif_info(interface, drv, netdev,
"Fake Tx hang detected with timeout of %d seconds\n",
netdev->watchdog_timeo / HZ);
if (netdev->watchdog_timeo < TX_TIMEO_LIMIT)
netdev->watchdog_timeo *= 2;
}
}
static bool fm10k_host_mbx_ready(struct fm10k_intfc *interface)
{
struct fm10k_hw *hw = &interface->hw;
return (hw->mac.type == fm10k_mac_vf || interface->host_ready);
}
static int fm10k_uc_vlan_unsync(struct net_device *netdev,
const unsigned char *uc_addr)
{
struct fm10k_intfc *interface = netdev_priv(netdev);
struct fm10k_hw *hw = &interface->hw;
u16 glort = interface->glort;
u16 vid = interface->vid;
bool set = !!(vid / VLAN_N_VID);
int err = -EHOSTDOWN;
vid &= VLAN_N_VID - 1;
if (fm10k_host_mbx_ready(interface))
err = hw->mac.ops.update_uc_addr(hw, glort, uc_addr,
vid, set, 0);
if (err)
return err;
return 1;
}
static int fm10k_mc_vlan_unsync(struct net_device *netdev,
const unsigned char *mc_addr)
{
struct fm10k_intfc *interface = netdev_priv(netdev);
struct fm10k_hw *hw = &interface->hw;
u16 glort = interface->glort;
u16 vid = interface->vid;
bool set = !!(vid / VLAN_N_VID);
int err = -EHOSTDOWN;
vid &= VLAN_N_VID - 1;
if (fm10k_host_mbx_ready(interface))
err = hw->mac.ops.update_mc_addr(hw, glort, mc_addr, vid, set);
if (err)
return err;
return 1;
}
static int fm10k_update_vid(struct net_device *netdev, u16 vid, bool set)
{
struct fm10k_intfc *interface = netdev_priv(netdev);
struct fm10k_hw *hw = &interface->hw;
s32 err;
int i;
if (!vid)
return 0;
if (vid >= VLAN_N_VID)
return -EINVAL;
if (hw->mac.vlan_override)
return -EACCES;
set_bit(vid, interface->active_vlans);
if (!set)
clear_bit(vid, interface->active_vlans);
for (i = 0; i < interface->num_rx_queues; i++) {
struct fm10k_ring *rx_ring = interface->rx_ring[i];
u16 rx_vid = rx_ring->vid & (VLAN_N_VID - 1);
if (test_bit(rx_vid, interface->active_vlans))
rx_ring->vid |= FM10K_VLAN_CLEAR;
else
rx_ring->vid &= ~FM10K_VLAN_CLEAR;
}
if (!set && vid == hw->mac.default_vid)
return 0;
if (test_bit(__FM10K_DOWN, interface->state))
return 0;
fm10k_mbx_lock(interface);
if (!(netdev->flags & IFF_PROMISC)) {
err = hw->mac.ops.update_vlan(hw, vid, 0, set);
if (err)
goto err_out;
}
if (fm10k_host_mbx_ready(interface))
err = hw->mac.ops.update_uc_addr(hw, interface->glort,
hw->mac.addr, vid, set, 0);
else
err = -EHOSTDOWN;
if (err)
goto err_out;
interface->vid = vid + (set ? VLAN_N_VID : 0);
__dev_uc_unsync(netdev, fm10k_uc_vlan_unsync);
__dev_mc_unsync(netdev, fm10k_mc_vlan_unsync);
err_out:
fm10k_mbx_unlock(interface);
return err;
}
static int fm10k_vlan_rx_add_vid(struct net_device *netdev,
__always_unused __be16 proto, u16 vid)
{
return fm10k_update_vid(netdev, vid, true);
}
static int fm10k_vlan_rx_kill_vid(struct net_device *netdev,
__always_unused __be16 proto, u16 vid)
{
return fm10k_update_vid(netdev, vid, false);
}
static u16 fm10k_find_next_vlan(struct fm10k_intfc *interface, u16 vid)
{
struct fm10k_hw *hw = &interface->hw;
u16 default_vid = hw->mac.default_vid;
u16 vid_limit = vid < default_vid ? default_vid : VLAN_N_VID;
vid = find_next_bit(interface->active_vlans, vid_limit, ++vid);
return vid;
}
static void fm10k_clear_unused_vlans(struct fm10k_intfc *interface)
{
struct fm10k_hw *hw = &interface->hw;
u32 vid, prev_vid;
for (vid = 0, prev_vid = 0;
prev_vid < VLAN_N_VID;
prev_vid = vid + 1, vid = fm10k_find_next_vlan(interface, vid)) {
if (prev_vid == vid)
continue;
prev_vid += (vid - prev_vid - 1) << FM10K_VLAN_LENGTH_SHIFT;
hw->mac.ops.update_vlan(hw, prev_vid, 0, false);
}
}
static int __fm10k_uc_sync(struct net_device *dev,
const unsigned char *addr, bool sync)
{
struct fm10k_intfc *interface = netdev_priv(dev);
struct fm10k_hw *hw = &interface->hw;
u16 vid, glort = interface->glort;
s32 err;
if (!is_valid_ether_addr(addr))
return -EADDRNOTAVAIL;
if (!fm10k_host_mbx_ready(interface))
return -EHOSTDOWN;
for (vid = hw->mac.default_vid ? fm10k_find_next_vlan(interface, 0) : 1;
vid < VLAN_N_VID;
vid = fm10k_find_next_vlan(interface, vid)) {
err = hw->mac.ops.update_uc_addr(hw, glort, addr,
vid, sync, 0);
if (err)
return err;
}
return 0;
}
static int fm10k_uc_sync(struct net_device *dev,
const unsigned char *addr)
{
return __fm10k_uc_sync(dev, addr, true);
}
static int fm10k_uc_unsync(struct net_device *dev,
const unsigned char *addr)
{
return __fm10k_uc_sync(dev, addr, false);
}
static int fm10k_set_mac(struct net_device *dev, void *p)
{
struct fm10k_intfc *interface = netdev_priv(dev);
struct fm10k_hw *hw = &interface->hw;
struct sockaddr *addr = p;
s32 err = 0;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
if (dev->flags & IFF_UP) {
fm10k_mbx_lock(interface);
err = fm10k_uc_sync(dev, addr->sa_data);
if (!err)
fm10k_uc_unsync(dev, hw->mac.addr);
fm10k_mbx_unlock(interface);
}
if (!err) {
ether_addr_copy(dev->dev_addr, addr->sa_data);
ether_addr_copy(hw->mac.addr, addr->sa_data);
dev->addr_assign_type &= ~NET_ADDR_RANDOM;
}
return err ? -EAGAIN : 0;
}
static int __fm10k_mc_sync(struct net_device *dev,
const unsigned char *addr, bool sync)
{
struct fm10k_intfc *interface = netdev_priv(dev);
struct fm10k_hw *hw = &interface->hw;
u16 vid, glort = interface->glort;
if (!fm10k_host_mbx_ready(interface))
return 0;
for (vid = hw->mac.default_vid ? fm10k_find_next_vlan(interface, 0) : 1;
vid < VLAN_N_VID;
vid = fm10k_find_next_vlan(interface, vid)) {
hw->mac.ops.update_mc_addr(hw, glort, addr, vid, sync);
}
return 0;
}
static int fm10k_mc_sync(struct net_device *dev,
const unsigned char *addr)
{
return __fm10k_mc_sync(dev, addr, true);
}
static int fm10k_mc_unsync(struct net_device *dev,
const unsigned char *addr)
{
return __fm10k_mc_sync(dev, addr, false);
}
static void fm10k_set_rx_mode(struct net_device *dev)
{
struct fm10k_intfc *interface = netdev_priv(dev);
struct fm10k_hw *hw = &interface->hw;
int xcast_mode;
if (!(dev->flags & IFF_UP))
return;
xcast_mode = (dev->flags & IFF_PROMISC) ? FM10K_XCAST_MODE_PROMISC :
(dev->flags & IFF_ALLMULTI) ? FM10K_XCAST_MODE_ALLMULTI :
(dev->flags & (IFF_BROADCAST | IFF_MULTICAST)) ?
FM10K_XCAST_MODE_MULTI : FM10K_XCAST_MODE_NONE;
fm10k_mbx_lock(interface);
if (interface->xcast_mode != xcast_mode) {
if (xcast_mode == FM10K_XCAST_MODE_PROMISC)
hw->mac.ops.update_vlan(hw, FM10K_VLAN_ALL, 0, true);
if (interface->xcast_mode == FM10K_XCAST_MODE_PROMISC)
fm10k_clear_unused_vlans(interface);
if (fm10k_host_mbx_ready(interface))
hw->mac.ops.update_xcast_mode(hw, interface->glort,
xcast_mode);
interface->xcast_mode = xcast_mode;
}
__dev_uc_sync(dev, fm10k_uc_sync, fm10k_uc_unsync);
__dev_mc_sync(dev, fm10k_mc_sync, fm10k_mc_unsync);
fm10k_mbx_unlock(interface);
}
void fm10k_restore_rx_state(struct fm10k_intfc *interface)
{
struct net_device *netdev = interface->netdev;
struct fm10k_hw *hw = &interface->hw;
int xcast_mode;
u16 vid, glort;
glort = interface->glort;
if (netdev->flags & IFF_PROMISC)
xcast_mode = FM10K_XCAST_MODE_PROMISC;
else if (netdev->flags & IFF_ALLMULTI)
xcast_mode = FM10K_XCAST_MODE_ALLMULTI;
else if (netdev->flags & (IFF_BROADCAST | IFF_MULTICAST))
xcast_mode = FM10K_XCAST_MODE_MULTI;
else
xcast_mode = FM10K_XCAST_MODE_NONE;
fm10k_mbx_lock(interface);
if (fm10k_host_mbx_ready(interface))
hw->mac.ops.update_lport_state(hw, glort,
interface->glort_count, true);
hw->mac.ops.update_vlan(hw, FM10K_VLAN_ALL, 0,
xcast_mode == FM10K_XCAST_MODE_PROMISC);
hw->mac.ops.update_vlan(hw, 0, 0, true);
for (vid = hw->mac.default_vid ? fm10k_find_next_vlan(interface, 0) : 1;
vid < VLAN_N_VID;
vid = fm10k_find_next_vlan(interface, vid)) {
hw->mac.ops.update_vlan(hw, vid, 0, true);
if (fm10k_host_mbx_ready(interface))
hw->mac.ops.update_uc_addr(hw, glort, hw->mac.addr,
vid, true, 0);
}
if (fm10k_host_mbx_ready(interface))
hw->mac.ops.update_xcast_mode(hw, glort, xcast_mode);
__dev_uc_sync(netdev, fm10k_uc_sync, fm10k_uc_unsync);
__dev_mc_sync(netdev, fm10k_mc_sync, fm10k_mc_unsync);
fm10k_mbx_unlock(interface);
interface->xcast_mode = xcast_mode;
fm10k_restore_udp_port_info(interface);
}
void fm10k_reset_rx_state(struct fm10k_intfc *interface)
{
struct net_device *netdev = interface->netdev;
struct fm10k_hw *hw = &interface->hw;
fm10k_mbx_lock(interface);
if (fm10k_host_mbx_ready(interface))
hw->mac.ops.update_lport_state(hw, interface->glort,
interface->glort_count, false);
fm10k_mbx_unlock(interface);
interface->xcast_mode = FM10K_XCAST_MODE_NONE;
__dev_uc_unsync(netdev, NULL);
__dev_mc_unsync(netdev, NULL);
}
static void fm10k_get_stats64(struct net_device *netdev,
struct rtnl_link_stats64 *stats)
{
struct fm10k_intfc *interface = netdev_priv(netdev);
struct fm10k_ring *ring;
unsigned int start, i;
u64 bytes, packets;
rcu_read_lock();
for (i = 0; i < interface->num_rx_queues; i++) {
ring = READ_ONCE(interface->rx_ring[i]);
if (!ring)
continue;
do {
start = u64_stats_fetch_begin_irq(&ring->syncp);
packets = ring->stats.packets;
bytes = ring->stats.bytes;
} while (u64_stats_fetch_retry_irq(&ring->syncp, start));
stats->rx_packets += packets;
stats->rx_bytes += bytes;
}
for (i = 0; i < interface->num_tx_queues; i++) {
ring = READ_ONCE(interface->tx_ring[i]);
if (!ring)
continue;
do {
start = u64_stats_fetch_begin_irq(&ring->syncp);
packets = ring->stats.packets;
bytes = ring->stats.bytes;
} while (u64_stats_fetch_retry_irq(&ring->syncp, start));
stats->tx_packets += packets;
stats->tx_bytes += bytes;
}
rcu_read_unlock();
stats->rx_missed_errors = netdev->stats.rx_missed_errors;
}
int fm10k_setup_tc(struct net_device *dev, u8 tc)
{
struct fm10k_intfc *interface = netdev_priv(dev);
int err;
if (tc && (interface->hw.mac.type != fm10k_mac_pf))
return -EINVAL;
if (tc > 8)
return -EINVAL;
if (netif_running(dev))
fm10k_close(dev);
fm10k_mbx_free_irq(interface);
fm10k_clear_queueing_scheme(interface);
netdev_reset_tc(dev);
netdev_set_num_tc(dev, tc);
err = fm10k_init_queueing_scheme(interface);
if (err)
goto err_queueing_scheme;
err = fm10k_mbx_request_irq(interface);
if (err)
goto err_mbx_irq;
err = netif_running(dev) ? fm10k_open(dev) : 0;
if (err)
goto err_open;
set_bit(FM10K_FLAG_SWPRI_CONFIG, interface->flags);
return 0;
err_open:
fm10k_mbx_free_irq(interface);
err_mbx_irq:
fm10k_clear_queueing_scheme(interface);
err_queueing_scheme:
netif_device_detach(dev);
return err;
}
static int __fm10k_setup_tc(struct net_device *dev, u32 handle, __be16 proto,
struct tc_to_netdev *tc)
{
if (tc->type != TC_SETUP_MQPRIO)
return -EINVAL;
tc->mqprio->hw = TC_MQPRIO_HW_OFFLOAD_TCS;
return fm10k_setup_tc(dev, tc->mqprio->num_tc);
}
static void fm10k_assign_l2_accel(struct fm10k_intfc *interface,
struct fm10k_l2_accel *l2_accel)
{
struct fm10k_ring *ring;
int i;
for (i = 0; i < interface->num_rx_queues; i++) {
ring = interface->rx_ring[i];
rcu_assign_pointer(ring->l2_accel, l2_accel);
}
interface->l2_accel = l2_accel;
}
static void *fm10k_dfwd_add_station(struct net_device *dev,
struct net_device *sdev)
{
struct fm10k_intfc *interface = netdev_priv(dev);
struct fm10k_l2_accel *l2_accel = interface->l2_accel;
struct fm10k_l2_accel *old_l2_accel = NULL;
struct fm10k_dglort_cfg dglort = { 0 };
struct fm10k_hw *hw = &interface->hw;
int size = 0, i;
u16 glort;
if (!l2_accel) {
if (interface->glort_count < 7)
return ERR_PTR(-EBUSY);
size = offsetof(struct fm10k_l2_accel, macvlan[7]);
l2_accel = kzalloc(size, GFP_KERNEL);
if (!l2_accel)
return ERR_PTR(-ENOMEM);
l2_accel->size = 7;
l2_accel->dglort = interface->glort;
fm10k_assign_l2_accel(interface, l2_accel);
} else if ((l2_accel->count == FM10K_MAX_STATIONS) ||
(l2_accel->count == (interface->glort_count - 1))) {
return ERR_PTR(-EBUSY);
} else if (l2_accel->count == l2_accel->size) {
old_l2_accel = l2_accel;
size = offsetof(struct fm10k_l2_accel,
macvlan[(l2_accel->size * 2) + 1]);
l2_accel = kzalloc(size, GFP_KERNEL);
if (!l2_accel)
return ERR_PTR(-ENOMEM);
memcpy(l2_accel, old_l2_accel,
offsetof(struct fm10k_l2_accel,
macvlan[old_l2_accel->size]));
l2_accel->size = (old_l2_accel->size * 2) + 1;
fm10k_assign_l2_accel(interface, l2_accel);
kfree_rcu(old_l2_accel, rcu);
}
for (i = 0; i < l2_accel->size; i++) {
if (!l2_accel->macvlan[i])
break;
}
l2_accel->macvlan[i] = sdev;
l2_accel->count++;
dglort.idx = fm10k_dglort_pf_rss;
dglort.inner_rss = 1;
dglort.rss_l = fls(interface->ring_feature[RING_F_RSS].mask);
dglort.pc_l = fls(interface->ring_feature[RING_F_QOS].mask);
dglort.glort = interface->glort;
dglort.shared_l = fls(l2_accel->size);
hw->mac.ops.configure_dglort_map(hw, &dglort);
fm10k_mbx_lock(interface);
glort = l2_accel->dglort + 1 + i;
if (fm10k_host_mbx_ready(interface)) {
hw->mac.ops.update_xcast_mode(hw, glort,
FM10K_XCAST_MODE_MULTI);
hw->mac.ops.update_uc_addr(hw, glort, sdev->dev_addr,
0, true, 0);
}
fm10k_mbx_unlock(interface);
return sdev;
}
static void fm10k_dfwd_del_station(struct net_device *dev, void *priv)
{
struct fm10k_intfc *interface = netdev_priv(dev);
struct fm10k_l2_accel *l2_accel = READ_ONCE(interface->l2_accel);
struct fm10k_dglort_cfg dglort = { 0 };
struct fm10k_hw *hw = &interface->hw;
struct net_device *sdev = priv;
int i;
u16 glort;
if (!l2_accel)
return;
for (i = 0; i < l2_accel->size; i++) {
if (l2_accel->macvlan[i] == sdev)
break;
}
if (i == l2_accel->size)
return;
fm10k_mbx_lock(interface);
glort = l2_accel->dglort + 1 + i;
if (fm10k_host_mbx_ready(interface)) {
hw->mac.ops.update_xcast_mode(hw, glort,
FM10K_XCAST_MODE_NONE);
hw->mac.ops.update_uc_addr(hw, glort, sdev->dev_addr,
0, false, 0);
}
fm10k_mbx_unlock(interface);
l2_accel->macvlan[i] = NULL;
l2_accel->count--;
dglort.idx = fm10k_dglort_pf_rss;
dglort.inner_rss = 1;
dglort.rss_l = fls(interface->ring_feature[RING_F_RSS].mask);
dglort.pc_l = fls(interface->ring_feature[RING_F_QOS].mask);
dglort.glort = interface->glort;
dglort.shared_l = fls(l2_accel->size);
hw->mac.ops.configure_dglort_map(hw, &dglort);
if (l2_accel->count == 0) {
fm10k_assign_l2_accel(interface, NULL);
kfree_rcu(l2_accel, rcu);
}
}
static netdev_features_t fm10k_features_check(struct sk_buff *skb,
struct net_device *dev,
netdev_features_t features)
{
if (!skb->encapsulation || fm10k_tx_encap_offload(skb))
return features;
return features & ~(NETIF_F_CSUM_MASK | NETIF_F_GSO_MASK);
}
struct net_device *fm10k_alloc_netdev(const struct fm10k_info *info)
{
netdev_features_t hw_features;
struct fm10k_intfc *interface;
struct net_device *dev;
dev = alloc_etherdev_mq(sizeof(struct fm10k_intfc), MAX_QUEUES);
if (!dev)
return NULL;
dev->netdev_ops = &fm10k_netdev_ops;
fm10k_set_ethtool_ops(dev);
interface = netdev_priv(dev);
interface->msg_enable = BIT(DEFAULT_DEBUG_LEVEL_SHIFT) - 1;
dev->features |= NETIF_F_IP_CSUM |
NETIF_F_IPV6_CSUM |
NETIF_F_SG |
NETIF_F_TSO |
NETIF_F_TSO6 |
NETIF_F_TSO_ECN |
NETIF_F_RXHASH |
NETIF_F_RXCSUM;
if (info->mac == fm10k_mac_pf) {
dev->hw_enc_features = NETIF_F_IP_CSUM |
NETIF_F_TSO |
NETIF_F_TSO6 |
NETIF_F_TSO_ECN |
NETIF_F_GSO_UDP_TUNNEL |
NETIF_F_IPV6_CSUM |
NETIF_F_SG;
dev->features |= NETIF_F_GSO_UDP_TUNNEL;
}
hw_features = dev->features;
hw_features |= NETIF_F_HW_L2FW_DOFFLOAD;
dev->vlan_features |= dev->features;
dev->features |= NETIF_F_HW_VLAN_CTAG_TX |
NETIF_F_HW_VLAN_CTAG_RX |
NETIF_F_HW_VLAN_CTAG_FILTER;
dev->priv_flags |= IFF_UNICAST_FLT;
dev->hw_features |= hw_features;
dev->min_mtu = ETH_MIN_MTU;
dev->max_mtu = FM10K_MAX_JUMBO_FRAME_SIZE;
return dev;
}
