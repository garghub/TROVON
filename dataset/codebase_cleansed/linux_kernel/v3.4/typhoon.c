static inline void
typhoon_inc_index(u32 *index, const int count, const int num_entries)
{
*index += count * sizeof(struct cmd_desc);
*index %= num_entries * sizeof(struct cmd_desc);
}
static inline void
typhoon_inc_cmd_index(u32 *index, const int count)
{
typhoon_inc_index(index, count, COMMAND_ENTRIES);
}
static inline void
typhoon_inc_resp_index(u32 *index, const int count)
{
typhoon_inc_index(index, count, RESPONSE_ENTRIES);
}
static inline void
typhoon_inc_rxfree_index(u32 *index, const int count)
{
typhoon_inc_index(index, count, RXFREE_ENTRIES);
}
static inline void
typhoon_inc_tx_index(u32 *index, const int count)
{
typhoon_inc_index(index, count, TXLO_ENTRIES);
}
static inline void
typhoon_inc_rx_index(u32 *index, const int count)
{
*index += count * sizeof(struct rx_desc);
*index %= RX_ENTRIES * sizeof(struct rx_desc);
}
static int
typhoon_reset(void __iomem *ioaddr, int wait_type)
{
int i, err = 0;
int timeout;
if(wait_type == WaitNoSleep)
timeout = TYPHOON_RESET_TIMEOUT_NOSLEEP;
else
timeout = TYPHOON_RESET_TIMEOUT_SLEEP;
iowrite32(TYPHOON_INTR_ALL, ioaddr + TYPHOON_REG_INTR_MASK);
iowrite32(TYPHOON_INTR_ALL, ioaddr + TYPHOON_REG_INTR_STATUS);
iowrite32(TYPHOON_RESET_ALL, ioaddr + TYPHOON_REG_SOFT_RESET);
typhoon_post_pci_writes(ioaddr);
udelay(1);
iowrite32(TYPHOON_RESET_NONE, ioaddr + TYPHOON_REG_SOFT_RESET);
if(wait_type != NoWait) {
for(i = 0; i < timeout; i++) {
if(ioread32(ioaddr + TYPHOON_REG_STATUS) ==
TYPHOON_STATUS_WAITING_FOR_HOST)
goto out;
if(wait_type == WaitSleep)
schedule_timeout_uninterruptible(1);
else
udelay(TYPHOON_UDELAY);
}
err = -ETIMEDOUT;
}
out:
iowrite32(TYPHOON_INTR_ALL, ioaddr + TYPHOON_REG_INTR_MASK);
iowrite32(TYPHOON_INTR_ALL, ioaddr + TYPHOON_REG_INTR_STATUS);
if(wait_type == WaitSleep)
msleep(5);
else
udelay(500);
return err;
}
static int
typhoon_wait_status(void __iomem *ioaddr, u32 wait_value)
{
int i, err = 0;
for(i = 0; i < TYPHOON_WAIT_TIMEOUT; i++) {
if(ioread32(ioaddr + TYPHOON_REG_STATUS) == wait_value)
goto out;
udelay(TYPHOON_UDELAY);
}
err = -ETIMEDOUT;
out:
return err;
}
static inline void
typhoon_media_status(struct net_device *dev, struct resp_desc *resp)
{
if(resp->parm1 & TYPHOON_MEDIA_STAT_NO_LINK)
netif_carrier_off(dev);
else
netif_carrier_on(dev);
}
static inline void
typhoon_hello(struct typhoon *tp)
{
struct basic_ring *ring = &tp->cmdRing;
struct cmd_desc *cmd;
if(spin_trylock(&tp->command_lock)) {
cmd = (struct cmd_desc *)(ring->ringBase + ring->lastWrite);
typhoon_inc_cmd_index(&ring->lastWrite, 1);
INIT_COMMAND_NO_RESPONSE(cmd, TYPHOON_CMD_HELLO_RESP);
wmb();
iowrite32(ring->lastWrite, tp->ioaddr + TYPHOON_REG_CMD_READY);
spin_unlock(&tp->command_lock);
}
}
static int
typhoon_process_response(struct typhoon *tp, int resp_size,
struct resp_desc *resp_save)
{
struct typhoon_indexes *indexes = tp->indexes;
struct resp_desc *resp;
u8 *base = tp->respRing.ringBase;
int count, len, wrap_len;
u32 cleared;
u32 ready;
cleared = le32_to_cpu(indexes->respCleared);
ready = le32_to_cpu(indexes->respReady);
while(cleared != ready) {
resp = (struct resp_desc *)(base + cleared);
count = resp->numDesc + 1;
if(resp_save && resp->seqNo) {
if(count > resp_size) {
resp_save->flags = TYPHOON_RESP_ERROR;
goto cleanup;
}
wrap_len = 0;
len = count * sizeof(*resp);
if(unlikely(cleared + len > RESPONSE_RING_SIZE)) {
wrap_len = cleared + len - RESPONSE_RING_SIZE;
len = RESPONSE_RING_SIZE - cleared;
}
memcpy(resp_save, resp, len);
if(unlikely(wrap_len)) {
resp_save += len / sizeof(*resp);
memcpy(resp_save, base, wrap_len);
}
resp_save = NULL;
} else if(resp->cmd == TYPHOON_CMD_READ_MEDIA_STATUS) {
typhoon_media_status(tp->dev, resp);
} else if(resp->cmd == TYPHOON_CMD_HELLO_RESP) {
typhoon_hello(tp);
} else {
netdev_err(tp->dev,
"dumping unexpected response 0x%04x:%d:0x%02x:0x%04x:%08x:%08x\n",
le16_to_cpu(resp->cmd),
resp->numDesc, resp->flags,
le16_to_cpu(resp->parm1),
le32_to_cpu(resp->parm2),
le32_to_cpu(resp->parm3));
}
cleanup:
typhoon_inc_resp_index(&cleared, count);
}
indexes->respCleared = cpu_to_le32(cleared);
wmb();
return resp_save == NULL;
}
static inline int
typhoon_num_free(int lastWrite, int lastRead, int ringSize)
{
lastWrite /= sizeof(struct cmd_desc);
lastRead /= sizeof(struct cmd_desc);
return (ringSize + lastRead - lastWrite - 1) % ringSize;
}
static inline int
typhoon_num_free_cmd(struct typhoon *tp)
{
int lastWrite = tp->cmdRing.lastWrite;
int cmdCleared = le32_to_cpu(tp->indexes->cmdCleared);
return typhoon_num_free(lastWrite, cmdCleared, COMMAND_ENTRIES);
}
static inline int
typhoon_num_free_resp(struct typhoon *tp)
{
int respReady = le32_to_cpu(tp->indexes->respReady);
int respCleared = le32_to_cpu(tp->indexes->respCleared);
return typhoon_num_free(respReady, respCleared, RESPONSE_ENTRIES);
}
static inline int
typhoon_num_free_tx(struct transmit_ring *ring)
{
return typhoon_num_free(ring->lastWrite, ring->lastRead, TXLO_ENTRIES);
}
static int
typhoon_issue_command(struct typhoon *tp, int num_cmd, struct cmd_desc *cmd,
int num_resp, struct resp_desc *resp)
{
struct typhoon_indexes *indexes = tp->indexes;
struct basic_ring *ring = &tp->cmdRing;
struct resp_desc local_resp;
int i, err = 0;
int got_resp;
int freeCmd, freeResp;
int len, wrap_len;
spin_lock(&tp->command_lock);
freeCmd = typhoon_num_free_cmd(tp);
freeResp = typhoon_num_free_resp(tp);
if(freeCmd < num_cmd || freeResp < num_resp) {
netdev_err(tp->dev, "no descs for cmd, had (needed) %d (%d) cmd, %d (%d) resp\n",
freeCmd, num_cmd, freeResp, num_resp);
err = -ENOMEM;
goto out;
}
if(cmd->flags & TYPHOON_CMD_RESPOND) {
tp->awaiting_resp = 1;
if(resp == NULL) {
resp = &local_resp;
num_resp = 1;
}
}
wrap_len = 0;
len = num_cmd * sizeof(*cmd);
if(unlikely(ring->lastWrite + len > COMMAND_RING_SIZE)) {
wrap_len = ring->lastWrite + len - COMMAND_RING_SIZE;
len = COMMAND_RING_SIZE - ring->lastWrite;
}
memcpy(ring->ringBase + ring->lastWrite, cmd, len);
if(unlikely(wrap_len)) {
struct cmd_desc *wrap_ptr = cmd;
wrap_ptr += len / sizeof(*cmd);
memcpy(ring->ringBase, wrap_ptr, wrap_len);
}
typhoon_inc_cmd_index(&ring->lastWrite, num_cmd);
wmb();
iowrite32(ring->lastWrite, tp->ioaddr + TYPHOON_REG_CMD_READY);
typhoon_post_pci_writes(tp->ioaddr);
if((cmd->flags & TYPHOON_CMD_RESPOND) == 0)
goto out;
got_resp = 0;
for(i = 0; i < TYPHOON_WAIT_TIMEOUT && !got_resp; i++) {
if(indexes->respCleared != indexes->respReady)
got_resp = typhoon_process_response(tp, num_resp,
resp);
udelay(TYPHOON_UDELAY);
}
if(!got_resp) {
err = -ETIMEDOUT;
goto out;
}
if(resp->flags & TYPHOON_RESP_ERROR)
err = -EIO;
out:
if(tp->awaiting_resp) {
tp->awaiting_resp = 0;
smp_wmb();
if(indexes->respCleared != indexes->respReady)
iowrite32(1, tp->ioaddr + TYPHOON_REG_SELF_INTERRUPT);
}
spin_unlock(&tp->command_lock);
return err;
}
static inline void
typhoon_tso_fill(struct sk_buff *skb, struct transmit_ring *txRing,
u32 ring_dma)
{
struct tcpopt_desc *tcpd;
u32 tcpd_offset = ring_dma;
tcpd = (struct tcpopt_desc *) (txRing->ringBase + txRing->lastWrite);
tcpd_offset += txRing->lastWrite;
tcpd_offset += offsetof(struct tcpopt_desc, bytesTx);
typhoon_inc_tx_index(&txRing->lastWrite, 1);
tcpd->flags = TYPHOON_OPT_DESC | TYPHOON_OPT_TCP_SEG;
tcpd->numDesc = 1;
tcpd->mss_flags = cpu_to_le16(skb_tso_size(skb));
tcpd->mss_flags |= TYPHOON_TSO_FIRST | TYPHOON_TSO_LAST;
tcpd->respAddrLo = cpu_to_le32(tcpd_offset);
tcpd->bytesTx = cpu_to_le32(skb->len);
tcpd->status = 0;
}
static netdev_tx_t
typhoon_start_tx(struct sk_buff *skb, struct net_device *dev)
{
struct typhoon *tp = netdev_priv(dev);
struct transmit_ring *txRing;
struct tx_desc *txd, *first_txd;
dma_addr_t skb_dma;
int numDesc;
txRing = &tp->txLoRing;
numDesc = skb_shinfo(skb)->nr_frags + 1;
if (skb_is_gso(skb))
numDesc++;
while(unlikely(typhoon_num_free_tx(txRing) < (numDesc + 2)))
smp_rmb();
first_txd = (struct tx_desc *) (txRing->ringBase + txRing->lastWrite);
typhoon_inc_tx_index(&txRing->lastWrite, 1);
first_txd->flags = TYPHOON_TX_DESC | TYPHOON_DESC_VALID;
first_txd->numDesc = 0;
first_txd->len = 0;
first_txd->tx_addr = (u64)((unsigned long) skb);
first_txd->processFlags = 0;
if(skb->ip_summed == CHECKSUM_PARTIAL) {
first_txd->processFlags |= TYPHOON_TX_PF_TCP_CHKSUM;
first_txd->processFlags |= TYPHOON_TX_PF_UDP_CHKSUM;
first_txd->processFlags |= TYPHOON_TX_PF_IP_CHKSUM;
}
if(vlan_tx_tag_present(skb)) {
first_txd->processFlags |=
TYPHOON_TX_PF_INSERT_VLAN | TYPHOON_TX_PF_VLAN_PRIORITY;
first_txd->processFlags |=
cpu_to_le32(htons(vlan_tx_tag_get(skb)) <<
TYPHOON_TX_PF_VLAN_TAG_SHIFT);
}
if (skb_is_gso(skb)) {
first_txd->processFlags |= TYPHOON_TX_PF_TCP_SEGMENT;
first_txd->numDesc++;
typhoon_tso_fill(skb, txRing, tp->txlo_dma_addr);
}
txd = (struct tx_desc *) (txRing->ringBase + txRing->lastWrite);
typhoon_inc_tx_index(&txRing->lastWrite, 1);
if(skb_shinfo(skb)->nr_frags == 0) {
skb_dma = pci_map_single(tp->tx_pdev, skb->data, skb->len,
PCI_DMA_TODEVICE);
txd->flags = TYPHOON_FRAG_DESC | TYPHOON_DESC_VALID;
txd->len = cpu_to_le16(skb->len);
txd->frag.addr = cpu_to_le32(skb_dma);
txd->frag.addrHi = 0;
first_txd->numDesc++;
} else {
int i, len;
len = skb_headlen(skb);
skb_dma = pci_map_single(tp->tx_pdev, skb->data, len,
PCI_DMA_TODEVICE);
txd->flags = TYPHOON_FRAG_DESC | TYPHOON_DESC_VALID;
txd->len = cpu_to_le16(len);
txd->frag.addr = cpu_to_le32(skb_dma);
txd->frag.addrHi = 0;
first_txd->numDesc++;
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
const skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
void *frag_addr;
txd = (struct tx_desc *) (txRing->ringBase +
txRing->lastWrite);
typhoon_inc_tx_index(&txRing->lastWrite, 1);
len = skb_frag_size(frag);
frag_addr = skb_frag_address(frag);
skb_dma = pci_map_single(tp->tx_pdev, frag_addr, len,
PCI_DMA_TODEVICE);
txd->flags = TYPHOON_FRAG_DESC | TYPHOON_DESC_VALID;
txd->len = cpu_to_le16(len);
txd->frag.addr = cpu_to_le32(skb_dma);
txd->frag.addrHi = 0;
first_txd->numDesc++;
}
}
wmb();
iowrite32(txRing->lastWrite, tp->tx_ioaddr + txRing->writeRegister);
numDesc = MAX_SKB_FRAGS + TSO_NUM_DESCRIPTORS + 1;
if(typhoon_num_free_tx(txRing) < (numDesc + 2)) {
netif_stop_queue(dev);
if(typhoon_num_free_tx(txRing) >= (numDesc + 2))
netif_wake_queue(dev);
}
return NETDEV_TX_OK;
}
static void
typhoon_set_rx_mode(struct net_device *dev)
{
struct typhoon *tp = netdev_priv(dev);
struct cmd_desc xp_cmd;
u32 mc_filter[2];
__le16 filter;
filter = TYPHOON_RX_FILTER_DIRECTED | TYPHOON_RX_FILTER_BROADCAST;
if(dev->flags & IFF_PROMISC) {
filter |= TYPHOON_RX_FILTER_PROMISCOUS;
} else if ((netdev_mc_count(dev) > multicast_filter_limit) ||
(dev->flags & IFF_ALLMULTI)) {
filter |= TYPHOON_RX_FILTER_ALL_MCAST;
} else if (!netdev_mc_empty(dev)) {
struct netdev_hw_addr *ha;
memset(mc_filter, 0, sizeof(mc_filter));
netdev_for_each_mc_addr(ha, dev) {
int bit = ether_crc(ETH_ALEN, ha->addr) & 0x3f;
mc_filter[bit >> 5] |= 1 << (bit & 0x1f);
}
INIT_COMMAND_NO_RESPONSE(&xp_cmd,
TYPHOON_CMD_SET_MULTICAST_HASH);
xp_cmd.parm1 = TYPHOON_MCAST_HASH_SET;
xp_cmd.parm2 = cpu_to_le32(mc_filter[0]);
xp_cmd.parm3 = cpu_to_le32(mc_filter[1]);
typhoon_issue_command(tp, 1, &xp_cmd, 0, NULL);
filter |= TYPHOON_RX_FILTER_MCAST_HASH;
}
INIT_COMMAND_WITH_RESPONSE(&xp_cmd, TYPHOON_CMD_SET_RX_FILTER);
xp_cmd.parm1 = filter;
typhoon_issue_command(tp, 1, &xp_cmd, 0, NULL);
}
static int
typhoon_do_get_stats(struct typhoon *tp)
{
struct net_device_stats *stats = &tp->stats;
struct net_device_stats *saved = &tp->stats_saved;
struct cmd_desc xp_cmd;
struct resp_desc xp_resp[7];
struct stats_resp *s = (struct stats_resp *) xp_resp;
int err;
INIT_COMMAND_WITH_RESPONSE(&xp_cmd, TYPHOON_CMD_READ_STATS);
err = typhoon_issue_command(tp, 1, &xp_cmd, 7, xp_resp);
if(err < 0)
return err;
stats->tx_packets = le32_to_cpu(s->txPackets) +
saved->tx_packets;
stats->tx_bytes = le64_to_cpu(s->txBytes) +
saved->tx_bytes;
stats->tx_errors = le32_to_cpu(s->txCarrierLost) +
saved->tx_errors;
stats->tx_carrier_errors = le32_to_cpu(s->txCarrierLost) +
saved->tx_carrier_errors;
stats->collisions = le32_to_cpu(s->txMultipleCollisions) +
saved->collisions;
stats->rx_packets = le32_to_cpu(s->rxPacketsGood) +
saved->rx_packets;
stats->rx_bytes = le64_to_cpu(s->rxBytesGood) +
saved->rx_bytes;
stats->rx_fifo_errors = le32_to_cpu(s->rxFifoOverruns) +
saved->rx_fifo_errors;
stats->rx_errors = le32_to_cpu(s->rxFifoOverruns) +
le32_to_cpu(s->BadSSD) + le32_to_cpu(s->rxCrcErrors) +
saved->rx_errors;
stats->rx_crc_errors = le32_to_cpu(s->rxCrcErrors) +
saved->rx_crc_errors;
stats->rx_length_errors = le32_to_cpu(s->rxOversized) +
saved->rx_length_errors;
tp->speed = (s->linkStatus & TYPHOON_LINK_100MBPS) ?
SPEED_100 : SPEED_10;
tp->duplex = (s->linkStatus & TYPHOON_LINK_FULL_DUPLEX) ?
DUPLEX_FULL : DUPLEX_HALF;
return 0;
}
static struct net_device_stats *
typhoon_get_stats(struct net_device *dev)
{
struct typhoon *tp = netdev_priv(dev);
struct net_device_stats *stats = &tp->stats;
struct net_device_stats *saved = &tp->stats_saved;
smp_rmb();
if(tp->card_state == Sleeping)
return saved;
if(typhoon_do_get_stats(tp) < 0) {
netdev_err(dev, "error getting stats\n");
return saved;
}
return stats;
}
static void
typhoon_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
struct typhoon *tp = netdev_priv(dev);
struct pci_dev *pci_dev = tp->pdev;
struct cmd_desc xp_cmd;
struct resp_desc xp_resp[3];
smp_rmb();
if(tp->card_state == Sleeping) {
strlcpy(info->fw_version, "Sleep image",
sizeof(info->fw_version));
} else {
INIT_COMMAND_WITH_RESPONSE(&xp_cmd, TYPHOON_CMD_READ_VERSIONS);
if(typhoon_issue_command(tp, 1, &xp_cmd, 3, xp_resp) < 0) {
strlcpy(info->fw_version, "Unknown runtime",
sizeof(info->fw_version));
} else {
u32 sleep_ver = le32_to_cpu(xp_resp[0].parm2);
snprintf(info->fw_version, sizeof(info->fw_version),
"%02x.%03x.%03x", sleep_ver >> 24,
(sleep_ver >> 12) & 0xfff, sleep_ver & 0xfff);
}
}
strlcpy(info->driver, KBUILD_MODNAME, sizeof(info->driver));
strlcpy(info->bus_info, pci_name(pci_dev), sizeof(info->bus_info));
}
static int
typhoon_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct typhoon *tp = netdev_priv(dev);
cmd->supported = SUPPORTED_100baseT_Half | SUPPORTED_100baseT_Full |
SUPPORTED_Autoneg;
switch (tp->xcvr_select) {
case TYPHOON_XCVR_10HALF:
cmd->advertising = ADVERTISED_10baseT_Half;
break;
case TYPHOON_XCVR_10FULL:
cmd->advertising = ADVERTISED_10baseT_Full;
break;
case TYPHOON_XCVR_100HALF:
cmd->advertising = ADVERTISED_100baseT_Half;
break;
case TYPHOON_XCVR_100FULL:
cmd->advertising = ADVERTISED_100baseT_Full;
break;
case TYPHOON_XCVR_AUTONEG:
cmd->advertising = ADVERTISED_10baseT_Half |
ADVERTISED_10baseT_Full |
ADVERTISED_100baseT_Half |
ADVERTISED_100baseT_Full |
ADVERTISED_Autoneg;
break;
}
if(tp->capabilities & TYPHOON_FIBER) {
cmd->supported |= SUPPORTED_FIBRE;
cmd->advertising |= ADVERTISED_FIBRE;
cmd->port = PORT_FIBRE;
} else {
cmd->supported |= SUPPORTED_10baseT_Half |
SUPPORTED_10baseT_Full |
SUPPORTED_TP;
cmd->advertising |= ADVERTISED_TP;
cmd->port = PORT_TP;
}
typhoon_do_get_stats(tp);
ethtool_cmd_speed_set(cmd, tp->speed);
cmd->duplex = tp->duplex;
cmd->phy_address = 0;
cmd->transceiver = XCVR_INTERNAL;
if(tp->xcvr_select == TYPHOON_XCVR_AUTONEG)
cmd->autoneg = AUTONEG_ENABLE;
else
cmd->autoneg = AUTONEG_DISABLE;
cmd->maxtxpkt = 1;
cmd->maxrxpkt = 1;
return 0;
}
static int
typhoon_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct typhoon *tp = netdev_priv(dev);
u32 speed = ethtool_cmd_speed(cmd);
struct cmd_desc xp_cmd;
__le16 xcvr;
int err;
err = -EINVAL;
if (cmd->autoneg == AUTONEG_ENABLE) {
xcvr = TYPHOON_XCVR_AUTONEG;
} else {
if (cmd->duplex == DUPLEX_HALF) {
if (speed == SPEED_10)
xcvr = TYPHOON_XCVR_10HALF;
else if (speed == SPEED_100)
xcvr = TYPHOON_XCVR_100HALF;
else
goto out;
} else if (cmd->duplex == DUPLEX_FULL) {
if (speed == SPEED_10)
xcvr = TYPHOON_XCVR_10FULL;
else if (speed == SPEED_100)
xcvr = TYPHOON_XCVR_100FULL;
else
goto out;
} else
goto out;
}
INIT_COMMAND_NO_RESPONSE(&xp_cmd, TYPHOON_CMD_XCVR_SELECT);
xp_cmd.parm1 = xcvr;
err = typhoon_issue_command(tp, 1, &xp_cmd, 0, NULL);
if(err < 0)
goto out;
tp->xcvr_select = xcvr;
if(cmd->autoneg == AUTONEG_ENABLE) {
tp->speed = 0xff;
tp->duplex = 0xff;
} else {
tp->speed = speed;
tp->duplex = cmd->duplex;
}
out:
return err;
}
static void
typhoon_get_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
struct typhoon *tp = netdev_priv(dev);
wol->supported = WAKE_PHY | WAKE_MAGIC;
wol->wolopts = 0;
if(tp->wol_events & TYPHOON_WAKE_LINK_EVENT)
wol->wolopts |= WAKE_PHY;
if(tp->wol_events & TYPHOON_WAKE_MAGIC_PKT)
wol->wolopts |= WAKE_MAGIC;
memset(&wol->sopass, 0, sizeof(wol->sopass));
}
static int
typhoon_set_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
struct typhoon *tp = netdev_priv(dev);
if(wol->wolopts & ~(WAKE_PHY | WAKE_MAGIC))
return -EINVAL;
tp->wol_events = 0;
if(wol->wolopts & WAKE_PHY)
tp->wol_events |= TYPHOON_WAKE_LINK_EVENT;
if(wol->wolopts & WAKE_MAGIC)
tp->wol_events |= TYPHOON_WAKE_MAGIC_PKT;
return 0;
}
static void
typhoon_get_ringparam(struct net_device *dev, struct ethtool_ringparam *ering)
{
ering->rx_max_pending = RXENT_ENTRIES;
ering->tx_max_pending = TXLO_ENTRIES - 1;
ering->rx_pending = RXENT_ENTRIES;
ering->tx_pending = TXLO_ENTRIES - 1;
}
static int
typhoon_wait_interrupt(void __iomem *ioaddr)
{
int i, err = 0;
for(i = 0; i < TYPHOON_WAIT_TIMEOUT; i++) {
if(ioread32(ioaddr + TYPHOON_REG_INTR_STATUS) &
TYPHOON_INTR_BOOTCMD)
goto out;
udelay(TYPHOON_UDELAY);
}
err = -ETIMEDOUT;
out:
iowrite32(TYPHOON_INTR_BOOTCMD, ioaddr + TYPHOON_REG_INTR_STATUS);
return err;
}
static void
typhoon_init_interface(struct typhoon *tp)
{
struct typhoon_interface *iface = &tp->shared->iface;
dma_addr_t shared_dma;
memset(tp->shared, 0, sizeof(struct typhoon_shared));
shared_dma = tp->shared_dma + shared_offset(indexes);
iface->ringIndex = cpu_to_le32(shared_dma);
shared_dma = tp->shared_dma + shared_offset(txLo);
iface->txLoAddr = cpu_to_le32(shared_dma);
iface->txLoSize = cpu_to_le32(TXLO_ENTRIES * sizeof(struct tx_desc));
shared_dma = tp->shared_dma + shared_offset(txHi);
iface->txHiAddr = cpu_to_le32(shared_dma);
iface->txHiSize = cpu_to_le32(TXHI_ENTRIES * sizeof(struct tx_desc));
shared_dma = tp->shared_dma + shared_offset(rxBuff);
iface->rxBuffAddr = cpu_to_le32(shared_dma);
iface->rxBuffSize = cpu_to_le32(RXFREE_ENTRIES *
sizeof(struct rx_free));
shared_dma = tp->shared_dma + shared_offset(rxLo);
iface->rxLoAddr = cpu_to_le32(shared_dma);
iface->rxLoSize = cpu_to_le32(RX_ENTRIES * sizeof(struct rx_desc));
shared_dma = tp->shared_dma + shared_offset(rxHi);
iface->rxHiAddr = cpu_to_le32(shared_dma);
iface->rxHiSize = cpu_to_le32(RX_ENTRIES * sizeof(struct rx_desc));
shared_dma = tp->shared_dma + shared_offset(cmd);
iface->cmdAddr = cpu_to_le32(shared_dma);
iface->cmdSize = cpu_to_le32(COMMAND_RING_SIZE);
shared_dma = tp->shared_dma + shared_offset(resp);
iface->respAddr = cpu_to_le32(shared_dma);
iface->respSize = cpu_to_le32(RESPONSE_RING_SIZE);
shared_dma = tp->shared_dma + shared_offset(zeroWord);
iface->zeroAddr = cpu_to_le32(shared_dma);
tp->indexes = &tp->shared->indexes;
tp->txLoRing.ringBase = (u8 *) tp->shared->txLo;
tp->txHiRing.ringBase = (u8 *) tp->shared->txHi;
tp->rxLoRing.ringBase = (u8 *) tp->shared->rxLo;
tp->rxHiRing.ringBase = (u8 *) tp->shared->rxHi;
tp->rxBuffRing.ringBase = (u8 *) tp->shared->rxBuff;
tp->cmdRing.ringBase = (u8 *) tp->shared->cmd;
tp->respRing.ringBase = (u8 *) tp->shared->resp;
tp->txLoRing.writeRegister = TYPHOON_REG_TX_LO_READY;
tp->txHiRing.writeRegister = TYPHOON_REG_TX_HI_READY;
tp->txlo_dma_addr = le32_to_cpu(iface->txLoAddr);
tp->card_state = Sleeping;
tp->offload = TYPHOON_OFFLOAD_IP_CHKSUM | TYPHOON_OFFLOAD_TCP_CHKSUM;
tp->offload |= TYPHOON_OFFLOAD_UDP_CHKSUM | TSO_OFFLOAD_ON;
tp->offload |= TYPHOON_OFFLOAD_VLAN;
spin_lock_init(&tp->command_lock);
wmb();
}
static void
typhoon_init_rings(struct typhoon *tp)
{
memset(tp->indexes, 0, sizeof(struct typhoon_indexes));
tp->txLoRing.lastWrite = 0;
tp->txHiRing.lastWrite = 0;
tp->rxLoRing.lastWrite = 0;
tp->rxHiRing.lastWrite = 0;
tp->rxBuffRing.lastWrite = 0;
tp->cmdRing.lastWrite = 0;
tp->respRing.lastWrite = 0;
tp->txLoRing.lastRead = 0;
tp->txHiRing.lastRead = 0;
}
static int
typhoon_request_firmware(struct typhoon *tp)
{
const struct typhoon_file_header *fHdr;
const struct typhoon_section_header *sHdr;
const u8 *image_data;
u32 numSections;
u32 section_len;
u32 remaining;
int err;
if (typhoon_fw)
return 0;
err = request_firmware(&typhoon_fw, FIRMWARE_NAME, &tp->pdev->dev);
if (err) {
netdev_err(tp->dev, "Failed to load firmware \"%s\"\n",
FIRMWARE_NAME);
return err;
}
image_data = (u8 *) typhoon_fw->data;
remaining = typhoon_fw->size;
if (remaining < sizeof(struct typhoon_file_header))
goto invalid_fw;
fHdr = (struct typhoon_file_header *) image_data;
if (memcmp(fHdr->tag, "TYPHOON", 8))
goto invalid_fw;
numSections = le32_to_cpu(fHdr->numSections);
image_data += sizeof(struct typhoon_file_header);
remaining -= sizeof(struct typhoon_file_header);
while (numSections--) {
if (remaining < sizeof(struct typhoon_section_header))
goto invalid_fw;
sHdr = (struct typhoon_section_header *) image_data;
image_data += sizeof(struct typhoon_section_header);
section_len = le32_to_cpu(sHdr->len);
if (remaining < section_len)
goto invalid_fw;
image_data += section_len;
remaining -= section_len;
}
return 0;
invalid_fw:
netdev_err(tp->dev, "Invalid firmware image\n");
release_firmware(typhoon_fw);
typhoon_fw = NULL;
return -EINVAL;
}
static int
typhoon_download_firmware(struct typhoon *tp)
{
void __iomem *ioaddr = tp->ioaddr;
struct pci_dev *pdev = tp->pdev;
const struct typhoon_file_header *fHdr;
const struct typhoon_section_header *sHdr;
const u8 *image_data;
void *dpage;
dma_addr_t dpage_dma;
__sum16 csum;
u32 irqEnabled;
u32 irqMasked;
u32 numSections;
u32 section_len;
u32 len;
u32 load_addr;
u32 hmac;
int i;
int err;
image_data = (u8 *) typhoon_fw->data;
fHdr = (struct typhoon_file_header *) image_data;
err = -ENOMEM;
dpage = pci_alloc_consistent(pdev, PAGE_SIZE, &dpage_dma);
if(!dpage) {
netdev_err(tp->dev, "no DMA mem for firmware\n");
goto err_out;
}
irqEnabled = ioread32(ioaddr + TYPHOON_REG_INTR_ENABLE);
iowrite32(irqEnabled | TYPHOON_INTR_BOOTCMD,
ioaddr + TYPHOON_REG_INTR_ENABLE);
irqMasked = ioread32(ioaddr + TYPHOON_REG_INTR_MASK);
iowrite32(irqMasked | TYPHOON_INTR_BOOTCMD,
ioaddr + TYPHOON_REG_INTR_MASK);
err = -ETIMEDOUT;
if(typhoon_wait_status(ioaddr, TYPHOON_STATUS_WAITING_FOR_HOST) < 0) {
netdev_err(tp->dev, "card ready timeout\n");
goto err_out_irq;
}
numSections = le32_to_cpu(fHdr->numSections);
load_addr = le32_to_cpu(fHdr->startAddr);
iowrite32(TYPHOON_INTR_BOOTCMD, ioaddr + TYPHOON_REG_INTR_STATUS);
iowrite32(load_addr, ioaddr + TYPHOON_REG_DOWNLOAD_BOOT_ADDR);
hmac = le32_to_cpu(fHdr->hmacDigest[0]);
iowrite32(hmac, ioaddr + TYPHOON_REG_DOWNLOAD_HMAC_0);
hmac = le32_to_cpu(fHdr->hmacDigest[1]);
iowrite32(hmac, ioaddr + TYPHOON_REG_DOWNLOAD_HMAC_1);
hmac = le32_to_cpu(fHdr->hmacDigest[2]);
iowrite32(hmac, ioaddr + TYPHOON_REG_DOWNLOAD_HMAC_2);
hmac = le32_to_cpu(fHdr->hmacDigest[3]);
iowrite32(hmac, ioaddr + TYPHOON_REG_DOWNLOAD_HMAC_3);
hmac = le32_to_cpu(fHdr->hmacDigest[4]);
iowrite32(hmac, ioaddr + TYPHOON_REG_DOWNLOAD_HMAC_4);
typhoon_post_pci_writes(ioaddr);
iowrite32(TYPHOON_BOOTCMD_RUNTIME_IMAGE, ioaddr + TYPHOON_REG_COMMAND);
image_data += sizeof(struct typhoon_file_header);
for(i = 0; i < numSections; i++) {
sHdr = (struct typhoon_section_header *) image_data;
image_data += sizeof(struct typhoon_section_header);
load_addr = le32_to_cpu(sHdr->startAddr);
section_len = le32_to_cpu(sHdr->len);
while(section_len) {
len = min_t(u32, section_len, PAGE_SIZE);
if(typhoon_wait_interrupt(ioaddr) < 0 ||
ioread32(ioaddr + TYPHOON_REG_STATUS) !=
TYPHOON_STATUS_WAITING_FOR_SEGMENT) {
netdev_err(tp->dev, "segment ready timeout\n");
goto err_out_irq;
}
csum = csum_fold(csum_partial_copy_nocheck(image_data,
dpage, len,
0));
iowrite32(len, ioaddr + TYPHOON_REG_BOOT_LENGTH);
iowrite32(le16_to_cpu((__force __le16)csum),
ioaddr + TYPHOON_REG_BOOT_CHECKSUM);
iowrite32(load_addr,
ioaddr + TYPHOON_REG_BOOT_DEST_ADDR);
iowrite32(0, ioaddr + TYPHOON_REG_BOOT_DATA_HI);
iowrite32(dpage_dma, ioaddr + TYPHOON_REG_BOOT_DATA_LO);
typhoon_post_pci_writes(ioaddr);
iowrite32(TYPHOON_BOOTCMD_SEG_AVAILABLE,
ioaddr + TYPHOON_REG_COMMAND);
image_data += len;
load_addr += len;
section_len -= len;
}
}
if(typhoon_wait_interrupt(ioaddr) < 0 ||
ioread32(ioaddr + TYPHOON_REG_STATUS) !=
TYPHOON_STATUS_WAITING_FOR_SEGMENT) {
netdev_err(tp->dev, "final segment ready timeout\n");
goto err_out_irq;
}
iowrite32(TYPHOON_BOOTCMD_DNLD_COMPLETE, ioaddr + TYPHOON_REG_COMMAND);
if(typhoon_wait_status(ioaddr, TYPHOON_STATUS_WAITING_FOR_BOOT) < 0) {
netdev_err(tp->dev, "boot ready timeout, status 0x%0x\n",
ioread32(ioaddr + TYPHOON_REG_STATUS));
goto err_out_irq;
}
err = 0;
err_out_irq:
iowrite32(irqMasked, ioaddr + TYPHOON_REG_INTR_MASK);
iowrite32(irqEnabled, ioaddr + TYPHOON_REG_INTR_ENABLE);
pci_free_consistent(pdev, PAGE_SIZE, dpage, dpage_dma);
err_out:
return err;
}
static int
typhoon_boot_3XP(struct typhoon *tp, u32 initial_status)
{
void __iomem *ioaddr = tp->ioaddr;
if(typhoon_wait_status(ioaddr, initial_status) < 0) {
netdev_err(tp->dev, "boot ready timeout\n");
goto out_timeout;
}
iowrite32(0, ioaddr + TYPHOON_REG_BOOT_RECORD_ADDR_HI);
iowrite32(tp->shared_dma, ioaddr + TYPHOON_REG_BOOT_RECORD_ADDR_LO);
typhoon_post_pci_writes(ioaddr);
iowrite32(TYPHOON_BOOTCMD_REG_BOOT_RECORD,
ioaddr + TYPHOON_REG_COMMAND);
if(typhoon_wait_status(ioaddr, TYPHOON_STATUS_RUNNING) < 0) {
netdev_err(tp->dev, "boot finish timeout (status 0x%x)\n",
ioread32(ioaddr + TYPHOON_REG_STATUS));
goto out_timeout;
}
iowrite32(0, ioaddr + TYPHOON_REG_TX_HI_READY);
iowrite32(0, ioaddr + TYPHOON_REG_CMD_READY);
iowrite32(0, ioaddr + TYPHOON_REG_TX_LO_READY);
typhoon_post_pci_writes(ioaddr);
iowrite32(TYPHOON_BOOTCMD_BOOT, ioaddr + TYPHOON_REG_COMMAND);
return 0;
out_timeout:
return -ETIMEDOUT;
}
static u32
typhoon_clean_tx(struct typhoon *tp, struct transmit_ring *txRing,
volatile __le32 * index)
{
u32 lastRead = txRing->lastRead;
struct tx_desc *tx;
dma_addr_t skb_dma;
int dma_len;
int type;
while(lastRead != le32_to_cpu(*index)) {
tx = (struct tx_desc *) (txRing->ringBase + lastRead);
type = tx->flags & TYPHOON_TYPE_MASK;
if(type == TYPHOON_TX_DESC) {
unsigned long ptr = tx->tx_addr;
struct sk_buff *skb = (struct sk_buff *) ptr;
dev_kfree_skb_irq(skb);
} else if(type == TYPHOON_FRAG_DESC) {
skb_dma = (dma_addr_t) le32_to_cpu(tx->frag.addr);
dma_len = le16_to_cpu(tx->len);
pci_unmap_single(tp->pdev, skb_dma, dma_len,
PCI_DMA_TODEVICE);
}
tx->flags = 0;
typhoon_inc_tx_index(&lastRead, 1);
}
return lastRead;
}
static void
typhoon_tx_complete(struct typhoon *tp, struct transmit_ring *txRing,
volatile __le32 * index)
{
u32 lastRead;
int numDesc = MAX_SKB_FRAGS + 1;
lastRead = typhoon_clean_tx(tp, txRing, index);
if(netif_queue_stopped(tp->dev) && typhoon_num_free(txRing->lastWrite,
lastRead, TXLO_ENTRIES) > (numDesc + 2))
netif_wake_queue(tp->dev);
txRing->lastRead = lastRead;
smp_wmb();
}
static void
typhoon_recycle_rx_skb(struct typhoon *tp, u32 idx)
{
struct typhoon_indexes *indexes = tp->indexes;
struct rxbuff_ent *rxb = &tp->rxbuffers[idx];
struct basic_ring *ring = &tp->rxBuffRing;
struct rx_free *r;
if((ring->lastWrite + sizeof(*r)) % (RXFREE_ENTRIES * sizeof(*r)) ==
le32_to_cpu(indexes->rxBuffCleared)) {
dev_kfree_skb_any(rxb->skb);
rxb->skb = NULL;
return;
}
r = (struct rx_free *) (ring->ringBase + ring->lastWrite);
typhoon_inc_rxfree_index(&ring->lastWrite, 1);
r->virtAddr = idx;
r->physAddr = cpu_to_le32(rxb->dma_addr);
wmb();
indexes->rxBuffReady = cpu_to_le32(ring->lastWrite);
}
static int
typhoon_alloc_rx_skb(struct typhoon *tp, u32 idx)
{
struct typhoon_indexes *indexes = tp->indexes;
struct rxbuff_ent *rxb = &tp->rxbuffers[idx];
struct basic_ring *ring = &tp->rxBuffRing;
struct rx_free *r;
struct sk_buff *skb;
dma_addr_t dma_addr;
rxb->skb = NULL;
if((ring->lastWrite + sizeof(*r)) % (RXFREE_ENTRIES * sizeof(*r)) ==
le32_to_cpu(indexes->rxBuffCleared))
return -ENOMEM;
skb = netdev_alloc_skb(tp->dev, PKT_BUF_SZ);
if(!skb)
return -ENOMEM;
#if 0
skb_reserve(skb, 2);
#endif
dma_addr = pci_map_single(tp->pdev, skb->data,
PKT_BUF_SZ, PCI_DMA_FROMDEVICE);
r = (struct rx_free *) (ring->ringBase + ring->lastWrite);
typhoon_inc_rxfree_index(&ring->lastWrite, 1);
r->virtAddr = idx;
r->physAddr = cpu_to_le32(dma_addr);
rxb->skb = skb;
rxb->dma_addr = dma_addr;
wmb();
indexes->rxBuffReady = cpu_to_le32(ring->lastWrite);
return 0;
}
static int
typhoon_rx(struct typhoon *tp, struct basic_ring *rxRing, volatile __le32 * ready,
volatile __le32 * cleared, int budget)
{
struct rx_desc *rx;
struct sk_buff *skb, *new_skb;
struct rxbuff_ent *rxb;
dma_addr_t dma_addr;
u32 local_ready;
u32 rxaddr;
int pkt_len;
u32 idx;
__le32 csum_bits;
int received;
received = 0;
local_ready = le32_to_cpu(*ready);
rxaddr = le32_to_cpu(*cleared);
while(rxaddr != local_ready && budget > 0) {
rx = (struct rx_desc *) (rxRing->ringBase + rxaddr);
idx = rx->addr;
rxb = &tp->rxbuffers[idx];
skb = rxb->skb;
dma_addr = rxb->dma_addr;
typhoon_inc_rx_index(&rxaddr, 1);
if(rx->flags & TYPHOON_RX_ERROR) {
typhoon_recycle_rx_skb(tp, idx);
continue;
}
pkt_len = le16_to_cpu(rx->frameLen);
if(pkt_len < rx_copybreak &&
(new_skb = netdev_alloc_skb(tp->dev, pkt_len + 2)) != NULL) {
skb_reserve(new_skb, 2);
pci_dma_sync_single_for_cpu(tp->pdev, dma_addr,
PKT_BUF_SZ,
PCI_DMA_FROMDEVICE);
skb_copy_to_linear_data(new_skb, skb->data, pkt_len);
pci_dma_sync_single_for_device(tp->pdev, dma_addr,
PKT_BUF_SZ,
PCI_DMA_FROMDEVICE);
skb_put(new_skb, pkt_len);
typhoon_recycle_rx_skb(tp, idx);
} else {
new_skb = skb;
skb_put(new_skb, pkt_len);
pci_unmap_single(tp->pdev, dma_addr, PKT_BUF_SZ,
PCI_DMA_FROMDEVICE);
typhoon_alloc_rx_skb(tp, idx);
}
new_skb->protocol = eth_type_trans(new_skb, tp->dev);
csum_bits = rx->rxStatus & (TYPHOON_RX_IP_CHK_GOOD |
TYPHOON_RX_UDP_CHK_GOOD | TYPHOON_RX_TCP_CHK_GOOD);
if(csum_bits ==
(TYPHOON_RX_IP_CHK_GOOD | TYPHOON_RX_TCP_CHK_GOOD) ||
csum_bits ==
(TYPHOON_RX_IP_CHK_GOOD | TYPHOON_RX_UDP_CHK_GOOD)) {
new_skb->ip_summed = CHECKSUM_UNNECESSARY;
} else
skb_checksum_none_assert(new_skb);
if (rx->rxStatus & TYPHOON_RX_VLAN)
__vlan_hwaccel_put_tag(new_skb,
ntohl(rx->vlanTag) & 0xffff);
netif_receive_skb(new_skb);
received++;
budget--;
}
*cleared = cpu_to_le32(rxaddr);
return received;
}
static void
typhoon_fill_free_ring(struct typhoon *tp)
{
u32 i;
for(i = 0; i < RXENT_ENTRIES; i++) {
struct rxbuff_ent *rxb = &tp->rxbuffers[i];
if(rxb->skb)
continue;
if(typhoon_alloc_rx_skb(tp, i) < 0)
break;
}
}
static int
typhoon_poll(struct napi_struct *napi, int budget)
{
struct typhoon *tp = container_of(napi, struct typhoon, napi);
struct typhoon_indexes *indexes = tp->indexes;
int work_done;
rmb();
if(!tp->awaiting_resp && indexes->respReady != indexes->respCleared)
typhoon_process_response(tp, 0, NULL);
if(le32_to_cpu(indexes->txLoCleared) != tp->txLoRing.lastRead)
typhoon_tx_complete(tp, &tp->txLoRing, &indexes->txLoCleared);
work_done = 0;
if(indexes->rxHiCleared != indexes->rxHiReady) {
work_done += typhoon_rx(tp, &tp->rxHiRing, &indexes->rxHiReady,
&indexes->rxHiCleared, budget);
}
if(indexes->rxLoCleared != indexes->rxLoReady) {
work_done += typhoon_rx(tp, &tp->rxLoRing, &indexes->rxLoReady,
&indexes->rxLoCleared, budget - work_done);
}
if(le32_to_cpu(indexes->rxBuffCleared) == tp->rxBuffRing.lastWrite) {
typhoon_fill_free_ring(tp);
}
if (work_done < budget) {
napi_complete(napi);
iowrite32(TYPHOON_INTR_NONE,
tp->ioaddr + TYPHOON_REG_INTR_MASK);
typhoon_post_pci_writes(tp->ioaddr);
}
return work_done;
}
static irqreturn_t
typhoon_interrupt(int irq, void *dev_instance)
{
struct net_device *dev = dev_instance;
struct typhoon *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->ioaddr;
u32 intr_status;
intr_status = ioread32(ioaddr + TYPHOON_REG_INTR_STATUS);
if(!(intr_status & TYPHOON_INTR_HOST_INT))
return IRQ_NONE;
iowrite32(intr_status, ioaddr + TYPHOON_REG_INTR_STATUS);
if (napi_schedule_prep(&tp->napi)) {
iowrite32(TYPHOON_INTR_ALL, ioaddr + TYPHOON_REG_INTR_MASK);
typhoon_post_pci_writes(ioaddr);
__napi_schedule(&tp->napi);
} else {
netdev_err(dev, "Error, poll already scheduled\n");
}
return IRQ_HANDLED;
}
static void
typhoon_free_rx_rings(struct typhoon *tp)
{
u32 i;
for(i = 0; i < RXENT_ENTRIES; i++) {
struct rxbuff_ent *rxb = &tp->rxbuffers[i];
if(rxb->skb) {
pci_unmap_single(tp->pdev, rxb->dma_addr, PKT_BUF_SZ,
PCI_DMA_FROMDEVICE);
dev_kfree_skb(rxb->skb);
rxb->skb = NULL;
}
}
}
static int
typhoon_sleep(struct typhoon *tp, pci_power_t state, __le16 events)
{
struct pci_dev *pdev = tp->pdev;
void __iomem *ioaddr = tp->ioaddr;
struct cmd_desc xp_cmd;
int err;
INIT_COMMAND_WITH_RESPONSE(&xp_cmd, TYPHOON_CMD_ENABLE_WAKE_EVENTS);
xp_cmd.parm1 = events;
err = typhoon_issue_command(tp, 1, &xp_cmd, 0, NULL);
if(err < 0) {
netdev_err(tp->dev, "typhoon_sleep(): wake events cmd err %d\n",
err);
return err;
}
INIT_COMMAND_NO_RESPONSE(&xp_cmd, TYPHOON_CMD_GOTO_SLEEP);
err = typhoon_issue_command(tp, 1, &xp_cmd, 0, NULL);
if(err < 0) {
netdev_err(tp->dev, "typhoon_sleep(): sleep cmd err %d\n", err);
return err;
}
if(typhoon_wait_status(ioaddr, TYPHOON_STATUS_SLEEPING) < 0)
return -ETIMEDOUT;
netif_carrier_off(tp->dev);
pci_enable_wake(tp->pdev, state, 1);
pci_disable_device(pdev);
return pci_set_power_state(pdev, state);
}
static int
typhoon_wakeup(struct typhoon *tp, int wait_type)
{
struct pci_dev *pdev = tp->pdev;
void __iomem *ioaddr = tp->ioaddr;
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
iowrite32(TYPHOON_BOOTCMD_WAKEUP, ioaddr + TYPHOON_REG_COMMAND);
if(typhoon_wait_status(ioaddr, TYPHOON_STATUS_WAITING_FOR_HOST) < 0 ||
(tp->capabilities & TYPHOON_WAKEUP_NEEDS_RESET))
return typhoon_reset(ioaddr, wait_type);
return 0;
}
static int
typhoon_start_runtime(struct typhoon *tp)
{
struct net_device *dev = tp->dev;
void __iomem *ioaddr = tp->ioaddr;
struct cmd_desc xp_cmd;
int err;
typhoon_init_rings(tp);
typhoon_fill_free_ring(tp);
err = typhoon_download_firmware(tp);
if(err < 0) {
netdev_err(tp->dev, "cannot load runtime on 3XP\n");
goto error_out;
}
if(typhoon_boot_3XP(tp, TYPHOON_STATUS_WAITING_FOR_BOOT) < 0) {
netdev_err(tp->dev, "cannot boot 3XP\n");
err = -EIO;
goto error_out;
}
INIT_COMMAND_NO_RESPONSE(&xp_cmd, TYPHOON_CMD_SET_MAX_PKT_SIZE);
xp_cmd.parm1 = cpu_to_le16(PKT_BUF_SZ);
err = typhoon_issue_command(tp, 1, &xp_cmd, 0, NULL);
if(err < 0)
goto error_out;
INIT_COMMAND_NO_RESPONSE(&xp_cmd, TYPHOON_CMD_SET_MAC_ADDRESS);
xp_cmd.parm1 = cpu_to_le16(ntohs(*(__be16 *)&dev->dev_addr[0]));
xp_cmd.parm2 = cpu_to_le32(ntohl(*(__be32 *)&dev->dev_addr[2]));
err = typhoon_issue_command(tp, 1, &xp_cmd, 0, NULL);
if(err < 0)
goto error_out;
INIT_COMMAND_WITH_RESPONSE(&xp_cmd, TYPHOON_CMD_IRQ_COALESCE_CTRL);
xp_cmd.parm1 = 0;
err = typhoon_issue_command(tp, 1, &xp_cmd, 0, NULL);
if(err < 0)
goto error_out;
INIT_COMMAND_NO_RESPONSE(&xp_cmd, TYPHOON_CMD_XCVR_SELECT);
xp_cmd.parm1 = tp->xcvr_select;
err = typhoon_issue_command(tp, 1, &xp_cmd, 0, NULL);
if(err < 0)
goto error_out;
INIT_COMMAND_NO_RESPONSE(&xp_cmd, TYPHOON_CMD_VLAN_TYPE_WRITE);
xp_cmd.parm1 = cpu_to_le16(ETH_P_8021Q);
err = typhoon_issue_command(tp, 1, &xp_cmd, 0, NULL);
if(err < 0)
goto error_out;
INIT_COMMAND_NO_RESPONSE(&xp_cmd, TYPHOON_CMD_SET_OFFLOAD_TASKS);
xp_cmd.parm2 = tp->offload;
xp_cmd.parm3 = tp->offload;
err = typhoon_issue_command(tp, 1, &xp_cmd, 0, NULL);
if(err < 0)
goto error_out;
typhoon_set_rx_mode(dev);
INIT_COMMAND_NO_RESPONSE(&xp_cmd, TYPHOON_CMD_TX_ENABLE);
err = typhoon_issue_command(tp, 1, &xp_cmd, 0, NULL);
if(err < 0)
goto error_out;
INIT_COMMAND_WITH_RESPONSE(&xp_cmd, TYPHOON_CMD_RX_ENABLE);
err = typhoon_issue_command(tp, 1, &xp_cmd, 0, NULL);
if(err < 0)
goto error_out;
tp->card_state = Running;
smp_wmb();
iowrite32(TYPHOON_INTR_ENABLE_ALL, ioaddr + TYPHOON_REG_INTR_ENABLE);
iowrite32(TYPHOON_INTR_NONE, ioaddr + TYPHOON_REG_INTR_MASK);
typhoon_post_pci_writes(ioaddr);
return 0;
error_out:
typhoon_reset(ioaddr, WaitNoSleep);
typhoon_free_rx_rings(tp);
typhoon_init_rings(tp);
return err;
}
static int
typhoon_stop_runtime(struct typhoon *tp, int wait_type)
{
struct typhoon_indexes *indexes = tp->indexes;
struct transmit_ring *txLo = &tp->txLoRing;
void __iomem *ioaddr = tp->ioaddr;
struct cmd_desc xp_cmd;
int i;
iowrite32(TYPHOON_INTR_NONE, ioaddr + TYPHOON_REG_INTR_ENABLE);
INIT_COMMAND_NO_RESPONSE(&xp_cmd, TYPHOON_CMD_RX_DISABLE);
typhoon_issue_command(tp, 1, &xp_cmd, 0, NULL);
for(i = 0; i < TYPHOON_WAIT_TIMEOUT; i++) {
if(indexes->txLoCleared == cpu_to_le32(txLo->lastWrite))
break;
udelay(TYPHOON_UDELAY);
}
if(i == TYPHOON_WAIT_TIMEOUT)
netdev_err(tp->dev, "halt timed out waiting for Tx to complete\n");
INIT_COMMAND_NO_RESPONSE(&xp_cmd, TYPHOON_CMD_TX_DISABLE);
typhoon_issue_command(tp, 1, &xp_cmd, 0, NULL);
tp->card_state = Sleeping;
smp_wmb();
typhoon_do_get_stats(tp);
memcpy(&tp->stats_saved, &tp->stats, sizeof(struct net_device_stats));
INIT_COMMAND_NO_RESPONSE(&xp_cmd, TYPHOON_CMD_HALT);
typhoon_issue_command(tp, 1, &xp_cmd, 0, NULL);
if(typhoon_wait_status(ioaddr, TYPHOON_STATUS_HALTED) < 0)
netdev_err(tp->dev, "timed out waiting for 3XP to halt\n");
if(typhoon_reset(ioaddr, wait_type) < 0) {
netdev_err(tp->dev, "unable to reset 3XP\n");
return -ETIMEDOUT;
}
if(indexes->txLoCleared != cpu_to_le32(txLo->lastWrite)) {
indexes->txLoCleared = cpu_to_le32(txLo->lastWrite);
typhoon_clean_tx(tp, &tp->txLoRing, &indexes->txLoCleared);
}
return 0;
}
static void
typhoon_tx_timeout(struct net_device *dev)
{
struct typhoon *tp = netdev_priv(dev);
if(typhoon_reset(tp->ioaddr, WaitNoSleep) < 0) {
netdev_warn(dev, "could not reset in tx timeout\n");
goto truly_dead;
}
typhoon_clean_tx(tp, &tp->txLoRing, &tp->indexes->txLoCleared);
typhoon_free_rx_rings(tp);
if(typhoon_start_runtime(tp) < 0) {
netdev_err(dev, "could not start runtime in tx timeout\n");
goto truly_dead;
}
netif_wake_queue(dev);
return;
truly_dead:
typhoon_reset(tp->ioaddr, NoWait);
netif_carrier_off(dev);
}
static int
typhoon_open(struct net_device *dev)
{
struct typhoon *tp = netdev_priv(dev);
int err;
err = typhoon_request_firmware(tp);
if (err)
goto out;
err = typhoon_wakeup(tp, WaitSleep);
if(err < 0) {
netdev_err(dev, "unable to wakeup device\n");
goto out_sleep;
}
err = request_irq(dev->irq, typhoon_interrupt, IRQF_SHARED,
dev->name, dev);
if(err < 0)
goto out_sleep;
napi_enable(&tp->napi);
err = typhoon_start_runtime(tp);
if(err < 0) {
napi_disable(&tp->napi);
goto out_irq;
}
netif_start_queue(dev);
return 0;
out_irq:
free_irq(dev->irq, dev);
out_sleep:
if(typhoon_boot_3XP(tp, TYPHOON_STATUS_WAITING_FOR_HOST) < 0) {
netdev_err(dev, "unable to reboot into sleep img\n");
typhoon_reset(tp->ioaddr, NoWait);
goto out;
}
if(typhoon_sleep(tp, PCI_D3hot, 0) < 0)
netdev_err(dev, "unable to go back to sleep\n");
out:
return err;
}
static int
typhoon_close(struct net_device *dev)
{
struct typhoon *tp = netdev_priv(dev);
netif_stop_queue(dev);
napi_disable(&tp->napi);
if(typhoon_stop_runtime(tp, WaitSleep) < 0)
netdev_err(dev, "unable to stop runtime\n");
free_irq(dev->irq, dev);
typhoon_free_rx_rings(tp);
typhoon_init_rings(tp);
if(typhoon_boot_3XP(tp, TYPHOON_STATUS_WAITING_FOR_HOST) < 0)
netdev_err(dev, "unable to boot sleep image\n");
if(typhoon_sleep(tp, PCI_D3hot, 0) < 0)
netdev_err(dev, "unable to put card to sleep\n");
return 0;
}
static int
typhoon_resume(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct typhoon *tp = netdev_priv(dev);
if(!netif_running(dev))
return 0;
if(typhoon_wakeup(tp, WaitNoSleep) < 0) {
netdev_err(dev, "critical: could not wake up in resume\n");
goto reset;
}
if(typhoon_start_runtime(tp) < 0) {
netdev_err(dev, "critical: could not start runtime in resume\n");
goto reset;
}
netif_device_attach(dev);
return 0;
reset:
typhoon_reset(tp->ioaddr, NoWait);
return -EBUSY;
}
static int
typhoon_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct typhoon *tp = netdev_priv(dev);
struct cmd_desc xp_cmd;
if(!netif_running(dev))
return 0;
if(tp->wol_events & TYPHOON_WAKE_MAGIC_PKT)
netdev_warn(dev, "cannot do WAKE_MAGIC with VLAN offloading\n");
netif_device_detach(dev);
if(typhoon_stop_runtime(tp, WaitNoSleep) < 0) {
netdev_err(dev, "unable to stop runtime\n");
goto need_resume;
}
typhoon_free_rx_rings(tp);
typhoon_init_rings(tp);
if(typhoon_boot_3XP(tp, TYPHOON_STATUS_WAITING_FOR_HOST) < 0) {
netdev_err(dev, "unable to boot sleep image\n");
goto need_resume;
}
INIT_COMMAND_NO_RESPONSE(&xp_cmd, TYPHOON_CMD_SET_MAC_ADDRESS);
xp_cmd.parm1 = cpu_to_le16(ntohs(*(__be16 *)&dev->dev_addr[0]));
xp_cmd.parm2 = cpu_to_le32(ntohl(*(__be32 *)&dev->dev_addr[2]));
if(typhoon_issue_command(tp, 1, &xp_cmd, 0, NULL) < 0) {
netdev_err(dev, "unable to set mac address in suspend\n");
goto need_resume;
}
INIT_COMMAND_NO_RESPONSE(&xp_cmd, TYPHOON_CMD_SET_RX_FILTER);
xp_cmd.parm1 = TYPHOON_RX_FILTER_DIRECTED | TYPHOON_RX_FILTER_BROADCAST;
if(typhoon_issue_command(tp, 1, &xp_cmd, 0, NULL) < 0) {
netdev_err(dev, "unable to set rx filter in suspend\n");
goto need_resume;
}
if(typhoon_sleep(tp, pci_choose_state(pdev, state), tp->wol_events) < 0) {
netdev_err(dev, "unable to put card to sleep\n");
goto need_resume;
}
return 0;
need_resume:
typhoon_resume(pdev);
return -EBUSY;
}
static int __devinit
typhoon_test_mmio(struct pci_dev *pdev)
{
void __iomem *ioaddr = pci_iomap(pdev, 1, 128);
int mode = 0;
u32 val;
if(!ioaddr)
goto out;
if(ioread32(ioaddr + TYPHOON_REG_STATUS) !=
TYPHOON_STATUS_WAITING_FOR_HOST)
goto out_unmap;
iowrite32(TYPHOON_INTR_ALL, ioaddr + TYPHOON_REG_INTR_MASK);
iowrite32(TYPHOON_INTR_ALL, ioaddr + TYPHOON_REG_INTR_STATUS);
iowrite32(TYPHOON_INTR_ALL, ioaddr + TYPHOON_REG_INTR_ENABLE);
val = ioread32(ioaddr + TYPHOON_REG_INTR_STATUS);
if((val & TYPHOON_INTR_SELF) == 0) {
iowrite32(1, ioaddr + TYPHOON_REG_SELF_INTERRUPT);
ioread32(ioaddr + TYPHOON_REG_INTR_STATUS);
udelay(50);
val = ioread32(ioaddr + TYPHOON_REG_INTR_STATUS);
if(val & TYPHOON_INTR_SELF)
mode = 1;
}
iowrite32(TYPHOON_INTR_ALL, ioaddr + TYPHOON_REG_INTR_MASK);
iowrite32(TYPHOON_INTR_ALL, ioaddr + TYPHOON_REG_INTR_STATUS);
iowrite32(TYPHOON_INTR_NONE, ioaddr + TYPHOON_REG_INTR_ENABLE);
ioread32(ioaddr + TYPHOON_REG_INTR_STATUS);
out_unmap:
pci_iounmap(pdev, ioaddr);
out:
if(!mode)
pr_info("%s: falling back to port IO\n", pci_name(pdev));
return mode;
}
static int __devinit
typhoon_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct net_device *dev;
struct typhoon *tp;
int card_id = (int) ent->driver_data;
void __iomem *ioaddr;
void *shared;
dma_addr_t shared_dma;
struct cmd_desc xp_cmd;
struct resp_desc xp_resp[3];
int err = 0;
const char *err_msg;
dev = alloc_etherdev(sizeof(*tp));
if(dev == NULL) {
err_msg = "unable to alloc new net device";
err = -ENOMEM;
goto error_out;
}
SET_NETDEV_DEV(dev, &pdev->dev);
err = pci_enable_device(pdev);
if(err < 0) {
err_msg = "unable to enable device";
goto error_out_dev;
}
err = pci_set_mwi(pdev);
if(err < 0) {
err_msg = "unable to set MWI";
goto error_out_disable;
}
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if(err < 0) {
err_msg = "No usable DMA configuration";
goto error_out_mwi;
}
if(!(pci_resource_flags(pdev, 0) & IORESOURCE_IO)) {
err_msg = "region #1 not a PCI IO resource, aborting";
err = -ENODEV;
goto error_out_mwi;
}
if(pci_resource_len(pdev, 0) < 128) {
err_msg = "Invalid PCI IO region size, aborting";
err = -ENODEV;
goto error_out_mwi;
}
if(!(pci_resource_flags(pdev, 1) & IORESOURCE_MEM)) {
err_msg = "region #1 not a PCI MMIO resource, aborting";
err = -ENODEV;
goto error_out_mwi;
}
if(pci_resource_len(pdev, 1) < 128) {
err_msg = "Invalid PCI MMIO region size, aborting";
err = -ENODEV;
goto error_out_mwi;
}
err = pci_request_regions(pdev, KBUILD_MODNAME);
if(err < 0) {
err_msg = "could not request regions";
goto error_out_mwi;
}
if(use_mmio != 0 && use_mmio != 1)
use_mmio = typhoon_test_mmio(pdev);
ioaddr = pci_iomap(pdev, use_mmio, 128);
if (!ioaddr) {
err_msg = "cannot remap registers, aborting";
err = -EIO;
goto error_out_regions;
}
shared = pci_alloc_consistent(pdev, sizeof(struct typhoon_shared),
&shared_dma);
if(!shared) {
err_msg = "could not allocate DMA memory";
err = -ENOMEM;
goto error_out_remap;
}
dev->irq = pdev->irq;
tp = netdev_priv(dev);
tp->shared = shared;
tp->shared_dma = shared_dma;
tp->pdev = pdev;
tp->tx_pdev = pdev;
tp->ioaddr = ioaddr;
tp->tx_ioaddr = ioaddr;
tp->dev = dev;
if (typhoon_reset(ioaddr, WaitSleep) < 0) {
err_msg = "could not reset 3XP";
err = -EIO;
goto error_out_dma;
}
pci_set_master(pdev);
pci_save_state(pdev);
typhoon_init_interface(tp);
typhoon_init_rings(tp);
if(typhoon_boot_3XP(tp, TYPHOON_STATUS_WAITING_FOR_HOST) < 0) {
err_msg = "cannot boot 3XP sleep image";
err = -EIO;
goto error_out_reset;
}
INIT_COMMAND_WITH_RESPONSE(&xp_cmd, TYPHOON_CMD_READ_MAC_ADDRESS);
if(typhoon_issue_command(tp, 1, &xp_cmd, 1, xp_resp) < 0) {
err_msg = "cannot read MAC address";
err = -EIO;
goto error_out_reset;
}
*(__be16 *)&dev->dev_addr[0] = htons(le16_to_cpu(xp_resp[0].parm1));
*(__be32 *)&dev->dev_addr[2] = htonl(le32_to_cpu(xp_resp[0].parm2));
if(!is_valid_ether_addr(dev->dev_addr)) {
err_msg = "Could not obtain valid ethernet address, aborting";
goto error_out_reset;
}
INIT_COMMAND_WITH_RESPONSE(&xp_cmd, TYPHOON_CMD_READ_VERSIONS);
if(typhoon_issue_command(tp, 1, &xp_cmd, 3, xp_resp) < 0) {
err_msg = "Could not get Sleep Image version";
goto error_out_reset;
}
tp->capabilities = typhoon_card_info[card_id].capabilities;
tp->xcvr_select = TYPHOON_XCVR_AUTONEG;
if(xp_resp[0].numDesc != 0)
tp->capabilities |= TYPHOON_WAKEUP_NEEDS_RESET;
if(typhoon_sleep(tp, PCI_D3hot, 0) < 0) {
err_msg = "cannot put adapter to sleep";
err = -EIO;
goto error_out_reset;
}
dev->netdev_ops = &typhoon_netdev_ops;
netif_napi_add(dev, &tp->napi, typhoon_poll, 16);
dev->watchdog_timeo = TX_TIMEOUT;
SET_ETHTOOL_OPS(dev, &typhoon_ethtool_ops);
dev->hw_features = NETIF_F_SG | NETIF_F_IP_CSUM | NETIF_F_TSO |
NETIF_F_HW_VLAN_TX;
dev->features = dev->hw_features |
NETIF_F_HW_VLAN_RX | NETIF_F_RXCSUM;
if(register_netdev(dev) < 0) {
err_msg = "unable to register netdev";
goto error_out_reset;
}
pci_set_drvdata(pdev, dev);
netdev_info(dev, "%s at %s 0x%llx, %pM\n",
typhoon_card_info[card_id].name,
use_mmio ? "MMIO" : "IO",
(unsigned long long)pci_resource_start(pdev, use_mmio),
dev->dev_addr);
if(xp_resp[0].numDesc == 0) {
u16 monthday = le32_to_cpu(xp_resp[0].parm2) & 0xffff;
netdev_info(dev, "Typhoon 1.0 Sleep Image built %02u/%02u/2000\n",
monthday >> 8, monthday & 0xff);
} else if(xp_resp[0].numDesc == 2) {
u32 sleep_ver = le32_to_cpu(xp_resp[0].parm2);
u8 *ver_string = (u8 *) &xp_resp[1];
ver_string[25] = 0;
netdev_info(dev, "Typhoon 1.1+ Sleep Image version %02x.%03x.%03x %s\n",
sleep_ver >> 24, (sleep_ver >> 12) & 0xfff,
sleep_ver & 0xfff, ver_string);
} else {
netdev_warn(dev, "Unknown Sleep Image version (%u:%04x)\n",
xp_resp[0].numDesc, le32_to_cpu(xp_resp[0].parm2));
}
return 0;
error_out_reset:
typhoon_reset(ioaddr, NoWait);
error_out_dma:
pci_free_consistent(pdev, sizeof(struct typhoon_shared),
shared, shared_dma);
error_out_remap:
pci_iounmap(pdev, ioaddr);
error_out_regions:
pci_release_regions(pdev);
error_out_mwi:
pci_clear_mwi(pdev);
error_out_disable:
pci_disable_device(pdev);
error_out_dev:
free_netdev(dev);
error_out:
pr_err("%s: %s\n", pci_name(pdev), err_msg);
return err;
}
static void __devexit
typhoon_remove_one(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct typhoon *tp = netdev_priv(dev);
unregister_netdev(dev);
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
typhoon_reset(tp->ioaddr, NoWait);
pci_iounmap(pdev, tp->ioaddr);
pci_free_consistent(pdev, sizeof(struct typhoon_shared),
tp->shared, tp->shared_dma);
pci_release_regions(pdev);
pci_clear_mwi(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
free_netdev(dev);
}
static int __init
typhoon_init(void)
{
return pci_register_driver(&typhoon_driver);
}
static void __exit
typhoon_cleanup(void)
{
if (typhoon_fw)
release_firmware(typhoon_fw);
pci_unregister_driver(&typhoon_driver);
}
