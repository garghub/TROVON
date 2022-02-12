static struct net_device_stats *et131x_stats(struct net_device *netdev)
{
struct et131x_adapter *adapter = netdev_priv(netdev);
struct net_device_stats *stats = &adapter->net_stats;
struct ce_stats *devstat = &adapter->stats;
stats->rx_errors = devstat->length_err + devstat->alignment_err +
devstat->crc_err + devstat->code_violations + devstat->other_errors;
stats->tx_errors = devstat->max_pkt_error;
stats->multicast = devstat->multircv;
stats->collisions = devstat->collisions;
stats->rx_length_errors = devstat->length_err;
stats->rx_over_errors = devstat->rx_ov_flow;
stats->rx_crc_errors = devstat->crc_err;
return stats;
}
int et131x_open(struct net_device *netdev)
{
int result = 0;
struct et131x_adapter *adapter = netdev_priv(netdev);
add_timer(&adapter->ErrorTimer);
result = request_irq(netdev->irq, et131x_isr, IRQF_SHARED,
netdev->name, netdev);
if (result) {
dev_err(&adapter->pdev->dev, "c ould not register IRQ %d\n",
netdev->irq);
return result;
}
et131x_rx_dma_enable(adapter);
et131x_tx_dma_enable(adapter);
et131x_enable_interrupts(adapter);
adapter->flags |= fMP_ADAPTER_INTERRUPT_IN_USE;
netif_start_queue(netdev);
return result;
}
int et131x_close(struct net_device *netdev)
{
struct et131x_adapter *adapter = netdev_priv(netdev);
netif_stop_queue(netdev);
et131x_rx_dma_disable(adapter);
et131x_tx_dma_disable(adapter);
et131x_disable_interrupts(adapter);
adapter->flags &= ~fMP_ADAPTER_INTERRUPT_IN_USE;
free_irq(netdev->irq, netdev);
del_timer_sync(&adapter->ErrorTimer);
return 0;
}
int et131x_ioctl_mii(struct net_device *netdev, struct ifreq *reqbuf, int cmd)
{
int status = 0;
struct et131x_adapter *etdev = netdev_priv(netdev);
struct mii_ioctl_data *data = if_mii(reqbuf);
switch (cmd) {
case SIOCGMIIPHY:
data->phy_id = etdev->stats.xcvr_addr;
break;
case SIOCGMIIREG:
if (!capable(CAP_NET_ADMIN))
status = -EPERM;
else
status = MiRead(etdev,
data->reg_num, &data->val_out);
break;
case SIOCSMIIREG:
if (!capable(CAP_NET_ADMIN))
status = -EPERM;
else
status = MiWrite(etdev, data->reg_num,
data->val_in);
break;
default:
status = -EOPNOTSUPP;
}
return status;
}
int et131x_ioctl(struct net_device *netdev, struct ifreq *reqbuf, int cmd)
{
int status = 0;
switch (cmd) {
case SIOCGMIIPHY:
case SIOCGMIIREG:
case SIOCSMIIREG:
status = et131x_ioctl_mii(netdev, reqbuf, cmd);
break;
default:
status = -EOPNOTSUPP;
}
return status;
}
int et131x_set_packet_filter(struct et131x_adapter *adapter)
{
int status = 0;
uint32_t filter = adapter->PacketFilter;
u32 ctrl;
u32 pf_ctrl;
ctrl = readl(&adapter->regs->rxmac.ctrl);
pf_ctrl = readl(&adapter->regs->rxmac.pf_ctrl);
ctrl |= 0x04;
if ((filter & ET131X_PACKET_TYPE_PROMISCUOUS) || filter == 0)
pf_ctrl &= ~7;
else {
if (filter & ET131X_PACKET_TYPE_ALL_MULTICAST)
pf_ctrl &= ~2;
else {
SetupDeviceForMulticast(adapter);
pf_ctrl |= 2;
ctrl &= ~0x04;
}
if (filter & ET131X_PACKET_TYPE_DIRECTED) {
SetupDeviceForUnicast(adapter);
pf_ctrl |= 4;
ctrl &= ~0x04;
}
if (filter & ET131X_PACKET_TYPE_BROADCAST) {
pf_ctrl |= 1;
ctrl &= ~0x04;
} else
pf_ctrl &= ~1;
writel(pf_ctrl, &adapter->regs->rxmac.pf_ctrl);
writel(ctrl, &adapter->regs->rxmac.ctrl);
}
return status;
}
void et131x_multicast(struct net_device *netdev)
{
struct et131x_adapter *adapter = netdev_priv(netdev);
uint32_t PacketFilter = 0;
unsigned long flags;
struct netdev_hw_addr *ha;
int i;
spin_lock_irqsave(&adapter->Lock, flags);
PacketFilter = adapter->PacketFilter;
PacketFilter &= ~ET131X_PACKET_TYPE_MULTICAST;
if (netdev->flags & IFF_PROMISC)
adapter->PacketFilter |= ET131X_PACKET_TYPE_PROMISCUOUS;
else
adapter->PacketFilter &= ~ET131X_PACKET_TYPE_PROMISCUOUS;
if (netdev->flags & IFF_ALLMULTI)
adapter->PacketFilter |= ET131X_PACKET_TYPE_ALL_MULTICAST;
if (netdev_mc_count(netdev) > NIC_MAX_MCAST_LIST)
adapter->PacketFilter |= ET131X_PACKET_TYPE_ALL_MULTICAST;
if (netdev_mc_count(netdev) < 1) {
adapter->PacketFilter &= ~ET131X_PACKET_TYPE_ALL_MULTICAST;
adapter->PacketFilter &= ~ET131X_PACKET_TYPE_MULTICAST;
} else
adapter->PacketFilter |= ET131X_PACKET_TYPE_MULTICAST;
i = 0;
netdev_for_each_mc_addr(ha, netdev) {
if (i == NIC_MAX_MCAST_LIST)
break;
memcpy(adapter->MCList[i++], ha->addr, ETH_ALEN);
}
adapter->MCAddressCount = i;
if (PacketFilter != adapter->PacketFilter) {
et131x_set_packet_filter(adapter);
}
spin_unlock_irqrestore(&adapter->Lock, flags);
}
int et131x_tx(struct sk_buff *skb, struct net_device *netdev)
{
int status = 0;
netdev->trans_start = jiffies;
status = et131x_send_packets(skb, netdev);
if (status != 0) {
if (status == -ENOMEM) {
netif_stop_queue(netdev);
status = NETDEV_TX_BUSY;
} else {
status = NETDEV_TX_OK;
}
}
return status;
}
void et131x_tx_timeout(struct net_device *netdev)
{
struct et131x_adapter *etdev = netdev_priv(netdev);
struct tcb *tcb;
unsigned long flags;
if (etdev->flags & fMP_ADAPTER_NON_RECOVER_ERROR)
return;
if (etdev->flags & fMP_ADAPTER_HARDWARE_ERROR) {
dev_err(&etdev->pdev->dev, "hardware error - reset\n");
return;
}
spin_lock_irqsave(&etdev->TCBSendQLock, flags);
tcb = etdev->tx_ring.send_head;
if (tcb != NULL) {
tcb->count++;
if (tcb->count > NIC_SEND_HANG_THRESHOLD) {
spin_unlock_irqrestore(&etdev->TCBSendQLock,
flags);
dev_warn(&etdev->pdev->dev,
"Send stuck - reset. tcb->WrIndex %x, flags 0x%08x\n",
tcb->index,
tcb->flags);
et131x_close(netdev);
et131x_open(netdev);
return;
}
}
spin_unlock_irqrestore(&etdev->TCBSendQLock, flags);
}
int et131x_change_mtu(struct net_device *netdev, int new_mtu)
{
int result = 0;
struct et131x_adapter *adapter = netdev_priv(netdev);
if (new_mtu < 64 || new_mtu > 9216)
return -EINVAL;
netif_stop_queue(netdev);
et131x_rx_dma_disable(adapter);
et131x_tx_dma_disable(adapter);
et131x_disable_interrupts(adapter);
et131x_handle_send_interrupt(adapter);
et131x_handle_recv_interrupt(adapter);
netdev->mtu = new_mtu;
et131x_adapter_memory_free(adapter);
adapter->RegistryJumboPacket = new_mtu + 14;
et131x_soft_reset(adapter);
result = et131x_adapter_memory_alloc(adapter);
if (result != 0) {
dev_warn(&adapter->pdev->dev,
"Change MTU failed; couldn't re-alloc DMA memory\n");
return result;
}
et131x_init_send(adapter);
et131x_hwaddr_init(adapter);
memcpy(netdev->dev_addr, adapter->addr, ETH_ALEN);
et131x_adapter_setup(adapter);
if (adapter->flags & fMP_ADAPTER_INTERRUPT_IN_USE)
et131x_enable_interrupts(adapter);
et131x_rx_dma_enable(adapter);
et131x_tx_dma_enable(adapter);
netif_wake_queue(netdev);
return result;
}
int et131x_set_mac_addr(struct net_device *netdev, void *new_mac)
{
int result = 0;
struct et131x_adapter *adapter = netdev_priv(netdev);
struct sockaddr *address = new_mac;
if (adapter == NULL)
return -ENODEV;
if (!is_valid_ether_addr(address->sa_data))
return -EINVAL;
netif_stop_queue(netdev);
et131x_rx_dma_disable(adapter);
et131x_tx_dma_disable(adapter);
et131x_disable_interrupts(adapter);
et131x_handle_send_interrupt(adapter);
et131x_handle_recv_interrupt(adapter);
memcpy(netdev->dev_addr, address->sa_data, netdev->addr_len);
printk(KERN_INFO "%s: Setting MAC address to %pM\n",
netdev->name, netdev->dev_addr);
et131x_adapter_memory_free(adapter);
et131x_soft_reset(adapter);
result = et131x_adapter_memory_alloc(adapter);
if (result != 0) {
dev_err(&adapter->pdev->dev,
"Change MAC failed; couldn't re-alloc DMA memory\n");
return result;
}
et131x_init_send(adapter);
et131x_hwaddr_init(adapter);
et131x_adapter_setup(adapter);
if (adapter->flags & fMP_ADAPTER_INTERRUPT_IN_USE)
et131x_enable_interrupts(adapter);
et131x_rx_dma_enable(adapter);
et131x_tx_dma_enable(adapter);
netif_wake_queue(netdev);
return result;
}
struct net_device *et131x_device_alloc(void)
{
struct net_device *netdev;
netdev = alloc_etherdev(sizeof(struct et131x_adapter));
if (netdev == NULL) {
printk(KERN_ERR "et131x: Alloc of net_device struct failed\n");
return NULL;
}
netdev->watchdog_timeo = ET131X_TX_TIMEOUT;
netdev->netdev_ops = &et131x_netdev_ops;
return netdev;
}
