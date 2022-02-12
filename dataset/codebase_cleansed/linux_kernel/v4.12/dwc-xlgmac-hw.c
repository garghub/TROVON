static int xlgmac_tx_complete(struct xlgmac_dma_desc *dma_desc)
{
return !XLGMAC_GET_REG_BITS_LE(dma_desc->desc3,
TX_NORMAL_DESC3_OWN_POS,
TX_NORMAL_DESC3_OWN_LEN);
}
static int xlgmac_disable_rx_csum(struct xlgmac_pdata *pdata)
{
u32 regval;
regval = readl(pdata->mac_regs + MAC_RCR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_RCR_IPC_POS,
MAC_RCR_IPC_LEN, 0);
writel(regval, pdata->mac_regs + MAC_RCR);
return 0;
}
static int xlgmac_enable_rx_csum(struct xlgmac_pdata *pdata)
{
u32 regval;
regval = readl(pdata->mac_regs + MAC_RCR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_RCR_IPC_POS,
MAC_RCR_IPC_LEN, 1);
writel(regval, pdata->mac_regs + MAC_RCR);
return 0;
}
static int xlgmac_set_mac_address(struct xlgmac_pdata *pdata, u8 *addr)
{
unsigned int mac_addr_hi, mac_addr_lo;
mac_addr_hi = (addr[5] << 8) | (addr[4] << 0);
mac_addr_lo = (addr[3] << 24) | (addr[2] << 16) |
(addr[1] << 8) | (addr[0] << 0);
writel(mac_addr_hi, pdata->mac_regs + MAC_MACA0HR);
writel(mac_addr_lo, pdata->mac_regs + MAC_MACA0LR);
return 0;
}
static void xlgmac_set_mac_reg(struct xlgmac_pdata *pdata,
struct netdev_hw_addr *ha,
unsigned int *mac_reg)
{
unsigned int mac_addr_hi, mac_addr_lo;
u8 *mac_addr;
mac_addr_lo = 0;
mac_addr_hi = 0;
if (ha) {
mac_addr = (u8 *)&mac_addr_lo;
mac_addr[0] = ha->addr[0];
mac_addr[1] = ha->addr[1];
mac_addr[2] = ha->addr[2];
mac_addr[3] = ha->addr[3];
mac_addr = (u8 *)&mac_addr_hi;
mac_addr[0] = ha->addr[4];
mac_addr[1] = ha->addr[5];
netif_dbg(pdata, drv, pdata->netdev,
"adding mac address %pM at %#x\n",
ha->addr, *mac_reg);
mac_addr_hi = XLGMAC_SET_REG_BITS(mac_addr_hi,
MAC_MACA1HR_AE_POS,
MAC_MACA1HR_AE_LEN,
1);
}
writel(mac_addr_hi, pdata->mac_regs + *mac_reg);
*mac_reg += MAC_MACA_INC;
writel(mac_addr_lo, pdata->mac_regs + *mac_reg);
*mac_reg += MAC_MACA_INC;
}
static int xlgmac_enable_rx_vlan_stripping(struct xlgmac_pdata *pdata)
{
u32 regval;
regval = readl(pdata->mac_regs + MAC_VLANTR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_VLANTR_EVLRXS_POS,
MAC_VLANTR_EVLRXS_LEN, 1);
regval = XLGMAC_SET_REG_BITS(regval, MAC_VLANTR_DOVLTC_POS,
MAC_VLANTR_DOVLTC_LEN, 1);
regval = XLGMAC_SET_REG_BITS(regval, MAC_VLANTR_ERSVLM_POS,
MAC_VLANTR_ERSVLM_LEN, 0);
regval = XLGMAC_SET_REG_BITS(regval, MAC_VLANTR_ESVL_POS,
MAC_VLANTR_ESVL_LEN, 0);
regval = XLGMAC_SET_REG_BITS(regval, MAC_VLANTR_EVLS_POS,
MAC_VLANTR_EVLS_LEN, 0x3);
writel(regval, pdata->mac_regs + MAC_VLANTR);
return 0;
}
static int xlgmac_disable_rx_vlan_stripping(struct xlgmac_pdata *pdata)
{
u32 regval;
regval = readl(pdata->mac_regs + MAC_VLANTR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_VLANTR_EVLS_POS,
MAC_VLANTR_EVLS_LEN, 0);
writel(regval, pdata->mac_regs + MAC_VLANTR);
return 0;
}
static int xlgmac_enable_rx_vlan_filtering(struct xlgmac_pdata *pdata)
{
u32 regval;
regval = readl(pdata->mac_regs + MAC_PFR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_PFR_VTFE_POS,
MAC_PFR_VTFE_LEN, 1);
writel(regval, pdata->mac_regs + MAC_PFR);
regval = readl(pdata->mac_regs + MAC_VLANTR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_VLANTR_VTHM_POS,
MAC_VLANTR_VTHM_LEN, 1);
regval = XLGMAC_SET_REG_BITS(regval, MAC_VLANTR_VTIM_POS,
MAC_VLANTR_VTIM_LEN, 0);
regval = XLGMAC_SET_REG_BITS(regval, MAC_VLANTR_ETV_POS,
MAC_VLANTR_ETV_LEN, 1);
regval = XLGMAC_SET_REG_BITS(regval, MAC_VLANTR_VL_POS,
MAC_VLANTR_VL_LEN, 1);
writel(regval, pdata->mac_regs + MAC_VLANTR);
return 0;
}
static int xlgmac_disable_rx_vlan_filtering(struct xlgmac_pdata *pdata)
{
u32 regval;
regval = readl(pdata->mac_regs + MAC_PFR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_PFR_VTFE_POS,
MAC_PFR_VTFE_LEN, 0);
writel(regval, pdata->mac_regs + MAC_PFR);
return 0;
}
static u32 xlgmac_vid_crc32_le(__le16 vid_le)
{
unsigned char *data = (unsigned char *)&vid_le;
unsigned char data_byte = 0;
u32 poly = 0xedb88320;
u32 crc = ~0;
u32 temp = 0;
int i, bits;
bits = get_bitmask_order(VLAN_VID_MASK);
for (i = 0; i < bits; i++) {
if ((i % 8) == 0)
data_byte = data[i / 8];
temp = ((crc & 1) ^ data_byte) & 1;
crc >>= 1;
data_byte >>= 1;
if (temp)
crc ^= poly;
}
return crc;
}
static int xlgmac_update_vlan_hash_table(struct xlgmac_pdata *pdata)
{
u16 vlan_hash_table = 0;
__le16 vid_le;
u32 regval;
u32 crc;
u16 vid;
for_each_set_bit(vid, pdata->active_vlans, VLAN_N_VID) {
vid_le = cpu_to_le16(vid);
crc = bitrev32(~xlgmac_vid_crc32_le(vid_le)) >> 28;
vlan_hash_table |= (1 << crc);
}
regval = readl(pdata->mac_regs + MAC_VLANHTR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_VLANHTR_VLHT_POS,
MAC_VLANHTR_VLHT_LEN, vlan_hash_table);
writel(regval, pdata->mac_regs + MAC_VLANHTR);
return 0;
}
static int xlgmac_set_promiscuous_mode(struct xlgmac_pdata *pdata,
unsigned int enable)
{
unsigned int val = enable ? 1 : 0;
u32 regval;
regval = XLGMAC_GET_REG_BITS(readl(pdata->mac_regs + MAC_PFR),
MAC_PFR_PR_POS, MAC_PFR_PR_LEN);
if (regval == val)
return 0;
netif_dbg(pdata, drv, pdata->netdev, "%s promiscuous mode\n",
enable ? "entering" : "leaving");
regval = readl(pdata->mac_regs + MAC_PFR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_PFR_PR_POS,
MAC_PFR_PR_LEN, val);
writel(regval, pdata->mac_regs + MAC_PFR);
if (enable) {
xlgmac_disable_rx_vlan_filtering(pdata);
} else {
if (pdata->netdev->features & NETIF_F_HW_VLAN_CTAG_FILTER)
xlgmac_enable_rx_vlan_filtering(pdata);
}
return 0;
}
static int xlgmac_set_all_multicast_mode(struct xlgmac_pdata *pdata,
unsigned int enable)
{
unsigned int val = enable ? 1 : 0;
u32 regval;
regval = XLGMAC_GET_REG_BITS(readl(pdata->mac_regs + MAC_PFR),
MAC_PFR_PM_POS, MAC_PFR_PM_LEN);
if (regval == val)
return 0;
netif_dbg(pdata, drv, pdata->netdev, "%s allmulti mode\n",
enable ? "entering" : "leaving");
regval = readl(pdata->mac_regs + MAC_PFR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_PFR_PM_POS,
MAC_PFR_PM_LEN, val);
writel(regval, pdata->mac_regs + MAC_PFR);
return 0;
}
static void xlgmac_set_mac_addn_addrs(struct xlgmac_pdata *pdata)
{
struct net_device *netdev = pdata->netdev;
struct netdev_hw_addr *ha;
unsigned int addn_macs;
unsigned int mac_reg;
mac_reg = MAC_MACA1HR;
addn_macs = pdata->hw_feat.addn_mac;
if (netdev_uc_count(netdev) > addn_macs) {
xlgmac_set_promiscuous_mode(pdata, 1);
} else {
netdev_for_each_uc_addr(ha, netdev) {
xlgmac_set_mac_reg(pdata, ha, &mac_reg);
addn_macs--;
}
if (netdev_mc_count(netdev) > addn_macs) {
xlgmac_set_all_multicast_mode(pdata, 1);
} else {
netdev_for_each_mc_addr(ha, netdev) {
xlgmac_set_mac_reg(pdata, ha, &mac_reg);
addn_macs--;
}
}
}
while (addn_macs--)
xlgmac_set_mac_reg(pdata, NULL, &mac_reg);
}
static void xlgmac_set_mac_hash_table(struct xlgmac_pdata *pdata)
{
unsigned int hash_table_shift, hash_table_count;
u32 hash_table[XLGMAC_MAC_HASH_TABLE_SIZE];
struct net_device *netdev = pdata->netdev;
struct netdev_hw_addr *ha;
unsigned int hash_reg;
unsigned int i;
u32 crc;
hash_table_shift = 26 - (pdata->hw_feat.hash_table_size >> 7);
hash_table_count = pdata->hw_feat.hash_table_size / 32;
memset(hash_table, 0, sizeof(hash_table));
netdev_for_each_uc_addr(ha, netdev) {
crc = bitrev32(~crc32_le(~0, ha->addr, ETH_ALEN));
crc >>= hash_table_shift;
hash_table[crc >> 5] |= (1 << (crc & 0x1f));
}
netdev_for_each_mc_addr(ha, netdev) {
crc = bitrev32(~crc32_le(~0, ha->addr, ETH_ALEN));
crc >>= hash_table_shift;
hash_table[crc >> 5] |= (1 << (crc & 0x1f));
}
hash_reg = MAC_HTR0;
for (i = 0; i < hash_table_count; i++) {
writel(hash_table[i], pdata->mac_regs + hash_reg);
hash_reg += MAC_HTR_INC;
}
}
static int xlgmac_add_mac_addresses(struct xlgmac_pdata *pdata)
{
if (pdata->hw_feat.hash_table_size)
xlgmac_set_mac_hash_table(pdata);
else
xlgmac_set_mac_addn_addrs(pdata);
return 0;
}
static void xlgmac_config_mac_address(struct xlgmac_pdata *pdata)
{
u32 regval;
xlgmac_set_mac_address(pdata, pdata->netdev->dev_addr);
if (pdata->hw_feat.hash_table_size) {
regval = readl(pdata->mac_regs + MAC_PFR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_PFR_HPF_POS,
MAC_PFR_HPF_LEN, 1);
regval = XLGMAC_SET_REG_BITS(regval, MAC_PFR_HUC_POS,
MAC_PFR_HUC_LEN, 1);
regval = XLGMAC_SET_REG_BITS(regval, MAC_PFR_HMC_POS,
MAC_PFR_HMC_LEN, 1);
writel(regval, pdata->mac_regs + MAC_PFR);
}
}
static void xlgmac_config_jumbo_enable(struct xlgmac_pdata *pdata)
{
unsigned int val;
u32 regval;
val = (pdata->netdev->mtu > XLGMAC_STD_PACKET_MTU) ? 1 : 0;
regval = readl(pdata->mac_regs + MAC_RCR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_RCR_JE_POS,
MAC_RCR_JE_LEN, val);
writel(regval, pdata->mac_regs + MAC_RCR);
}
static void xlgmac_config_checksum_offload(struct xlgmac_pdata *pdata)
{
if (pdata->netdev->features & NETIF_F_RXCSUM)
xlgmac_enable_rx_csum(pdata);
else
xlgmac_disable_rx_csum(pdata);
}
static void xlgmac_config_vlan_support(struct xlgmac_pdata *pdata)
{
u32 regval;
regval = readl(pdata->mac_regs + MAC_VLANIR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_VLANIR_CSVL_POS,
MAC_VLANIR_CSVL_LEN, 0);
regval = XLGMAC_SET_REG_BITS(regval, MAC_VLANIR_VLTI_POS,
MAC_VLANIR_VLTI_LEN, 1);
writel(regval, pdata->mac_regs + MAC_VLANIR);
xlgmac_update_vlan_hash_table(pdata);
if (pdata->netdev->features & NETIF_F_HW_VLAN_CTAG_FILTER)
xlgmac_enable_rx_vlan_filtering(pdata);
else
xlgmac_disable_rx_vlan_filtering(pdata);
if (pdata->netdev->features & NETIF_F_HW_VLAN_CTAG_RX)
xlgmac_enable_rx_vlan_stripping(pdata);
else
xlgmac_disable_rx_vlan_stripping(pdata);
}
static int xlgmac_config_rx_mode(struct xlgmac_pdata *pdata)
{
struct net_device *netdev = pdata->netdev;
unsigned int pr_mode, am_mode;
pr_mode = ((netdev->flags & IFF_PROMISC) != 0);
am_mode = ((netdev->flags & IFF_ALLMULTI) != 0);
xlgmac_set_promiscuous_mode(pdata, pr_mode);
xlgmac_set_all_multicast_mode(pdata, am_mode);
xlgmac_add_mac_addresses(pdata);
return 0;
}
static void xlgmac_prepare_tx_stop(struct xlgmac_pdata *pdata,
struct xlgmac_channel *channel)
{
unsigned int tx_dsr, tx_pos, tx_qidx;
unsigned long tx_timeout;
unsigned int tx_status;
if (channel->queue_index < DMA_DSRX_FIRST_QUEUE) {
tx_dsr = DMA_DSR0;
tx_pos = (channel->queue_index * DMA_DSR_Q_LEN) +
DMA_DSR0_TPS_START;
} else {
tx_qidx = channel->queue_index - DMA_DSRX_FIRST_QUEUE;
tx_dsr = DMA_DSR1 + ((tx_qidx / DMA_DSRX_QPR) * DMA_DSRX_INC);
tx_pos = ((tx_qidx % DMA_DSRX_QPR) * DMA_DSR_Q_LEN) +
DMA_DSRX_TPS_START;
}
tx_timeout = jiffies + (XLGMAC_DMA_STOP_TIMEOUT * HZ);
while (time_before(jiffies, tx_timeout)) {
tx_status = readl(pdata->mac_regs + tx_dsr);
tx_status = XLGMAC_GET_REG_BITS(tx_status, tx_pos,
DMA_DSR_TPS_LEN);
if ((tx_status == DMA_TPS_STOPPED) ||
(tx_status == DMA_TPS_SUSPENDED))
break;
usleep_range(500, 1000);
}
if (!time_before(jiffies, tx_timeout))
netdev_info(pdata->netdev,
"timed out waiting for Tx DMA channel %u to stop\n",
channel->queue_index);
}
static void xlgmac_enable_tx(struct xlgmac_pdata *pdata)
{
struct xlgmac_channel *channel;
unsigned int i;
u32 regval;
channel = pdata->channel_head;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->tx_ring)
break;
regval = readl(XLGMAC_DMA_REG(channel, DMA_CH_TCR));
regval = XLGMAC_SET_REG_BITS(regval, DMA_CH_TCR_ST_POS,
DMA_CH_TCR_ST_LEN, 1);
writel(regval, XLGMAC_DMA_REG(channel, DMA_CH_TCR));
}
for (i = 0; i < pdata->tx_q_count; i++) {
regval = readl(XLGMAC_MTL_REG(pdata, i, MTL_Q_TQOMR));
regval = XLGMAC_SET_REG_BITS(regval, MTL_Q_TQOMR_TXQEN_POS,
MTL_Q_TQOMR_TXQEN_LEN,
MTL_Q_ENABLED);
writel(regval, XLGMAC_MTL_REG(pdata, i, MTL_Q_TQOMR));
}
regval = readl(pdata->mac_regs + MAC_TCR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_TCR_TE_POS,
MAC_TCR_TE_LEN, 1);
writel(regval, pdata->mac_regs + MAC_TCR);
}
static void xlgmac_disable_tx(struct xlgmac_pdata *pdata)
{
struct xlgmac_channel *channel;
unsigned int i;
u32 regval;
channel = pdata->channel_head;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->tx_ring)
break;
xlgmac_prepare_tx_stop(pdata, channel);
}
regval = readl(pdata->mac_regs + MAC_TCR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_TCR_TE_POS,
MAC_TCR_TE_LEN, 0);
writel(regval, pdata->mac_regs + MAC_TCR);
for (i = 0; i < pdata->tx_q_count; i++) {
regval = readl(XLGMAC_MTL_REG(pdata, i, MTL_Q_TQOMR));
regval = XLGMAC_SET_REG_BITS(regval, MTL_Q_TQOMR_TXQEN_POS,
MTL_Q_TQOMR_TXQEN_LEN, 0);
writel(regval, XLGMAC_MTL_REG(pdata, i, MTL_Q_TQOMR));
}
channel = pdata->channel_head;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->tx_ring)
break;
regval = readl(XLGMAC_DMA_REG(channel, DMA_CH_TCR));
regval = XLGMAC_SET_REG_BITS(regval, DMA_CH_TCR_ST_POS,
DMA_CH_TCR_ST_LEN, 0);
writel(regval, XLGMAC_DMA_REG(channel, DMA_CH_TCR));
}
}
static void xlgmac_prepare_rx_stop(struct xlgmac_pdata *pdata,
unsigned int queue)
{
unsigned int rx_status, prxq, rxqsts;
unsigned long rx_timeout;
rx_timeout = jiffies + (XLGMAC_DMA_STOP_TIMEOUT * HZ);
while (time_before(jiffies, rx_timeout)) {
rx_status = readl(XLGMAC_MTL_REG(pdata, queue, MTL_Q_RQDR));
prxq = XLGMAC_GET_REG_BITS(rx_status, MTL_Q_RQDR_PRXQ_POS,
MTL_Q_RQDR_PRXQ_LEN);
rxqsts = XLGMAC_GET_REG_BITS(rx_status, MTL_Q_RQDR_RXQSTS_POS,
MTL_Q_RQDR_RXQSTS_LEN);
if ((prxq == 0) && (rxqsts == 0))
break;
usleep_range(500, 1000);
}
if (!time_before(jiffies, rx_timeout))
netdev_info(pdata->netdev,
"timed out waiting for Rx queue %u to empty\n",
queue);
}
static void xlgmac_enable_rx(struct xlgmac_pdata *pdata)
{
struct xlgmac_channel *channel;
unsigned int regval, i;
channel = pdata->channel_head;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->rx_ring)
break;
regval = readl(XLGMAC_DMA_REG(channel, DMA_CH_RCR));
regval = XLGMAC_SET_REG_BITS(regval, DMA_CH_RCR_SR_POS,
DMA_CH_RCR_SR_LEN, 1);
writel(regval, XLGMAC_DMA_REG(channel, DMA_CH_RCR));
}
regval = 0;
for (i = 0; i < pdata->rx_q_count; i++)
regval |= (0x02 << (i << 1));
writel(regval, pdata->mac_regs + MAC_RQC0R);
regval = readl(pdata->mac_regs + MAC_RCR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_RCR_DCRCC_POS,
MAC_RCR_DCRCC_LEN, 1);
regval = XLGMAC_SET_REG_BITS(regval, MAC_RCR_CST_POS,
MAC_RCR_CST_LEN, 1);
regval = XLGMAC_SET_REG_BITS(regval, MAC_RCR_ACS_POS,
MAC_RCR_ACS_LEN, 1);
regval = XLGMAC_SET_REG_BITS(regval, MAC_RCR_RE_POS,
MAC_RCR_RE_LEN, 1);
writel(regval, pdata->mac_regs + MAC_RCR);
}
static void xlgmac_disable_rx(struct xlgmac_pdata *pdata)
{
struct xlgmac_channel *channel;
unsigned int i;
u32 regval;
regval = readl(pdata->mac_regs + MAC_RCR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_RCR_DCRCC_POS,
MAC_RCR_DCRCC_LEN, 0);
regval = XLGMAC_SET_REG_BITS(regval, MAC_RCR_CST_POS,
MAC_RCR_CST_LEN, 0);
regval = XLGMAC_SET_REG_BITS(regval, MAC_RCR_ACS_POS,
MAC_RCR_ACS_LEN, 0);
regval = XLGMAC_SET_REG_BITS(regval, MAC_RCR_RE_POS,
MAC_RCR_RE_LEN, 0);
writel(regval, pdata->mac_regs + MAC_RCR);
for (i = 0; i < pdata->rx_q_count; i++)
xlgmac_prepare_rx_stop(pdata, i);
writel(0, pdata->mac_regs + MAC_RQC0R);
channel = pdata->channel_head;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->rx_ring)
break;
regval = readl(XLGMAC_DMA_REG(channel, DMA_CH_RCR));
regval = XLGMAC_SET_REG_BITS(regval, DMA_CH_RCR_SR_POS,
DMA_CH_RCR_SR_LEN, 0);
writel(regval, XLGMAC_DMA_REG(channel, DMA_CH_RCR));
}
}
static void xlgmac_tx_start_xmit(struct xlgmac_channel *channel,
struct xlgmac_ring *ring)
{
struct xlgmac_pdata *pdata = channel->pdata;
struct xlgmac_desc_data *desc_data;
wmb();
desc_data = XLGMAC_GET_DESC_DATA(ring, ring->cur);
writel(lower_32_bits(desc_data->dma_desc_addr),
XLGMAC_DMA_REG(channel, DMA_CH_TDTR_LO));
if (pdata->tx_usecs && !channel->tx_timer_active) {
channel->tx_timer_active = 1;
mod_timer(&channel->tx_timer,
jiffies + usecs_to_jiffies(pdata->tx_usecs));
}
ring->tx.xmit_more = 0;
}
static void xlgmac_dev_xmit(struct xlgmac_channel *channel)
{
struct xlgmac_pdata *pdata = channel->pdata;
struct xlgmac_ring *ring = channel->tx_ring;
unsigned int tso_context, vlan_context;
struct xlgmac_desc_data *desc_data;
struct xlgmac_dma_desc *dma_desc;
struct xlgmac_pkt_info *pkt_info;
unsigned int csum, tso, vlan;
int start_index = ring->cur;
int cur_index = ring->cur;
unsigned int tx_set_ic;
int i;
pkt_info = &ring->pkt_info;
csum = XLGMAC_GET_REG_BITS(pkt_info->attributes,
TX_PACKET_ATTRIBUTES_CSUM_ENABLE_POS,
TX_PACKET_ATTRIBUTES_CSUM_ENABLE_LEN);
tso = XLGMAC_GET_REG_BITS(pkt_info->attributes,
TX_PACKET_ATTRIBUTES_TSO_ENABLE_POS,
TX_PACKET_ATTRIBUTES_TSO_ENABLE_LEN);
vlan = XLGMAC_GET_REG_BITS(pkt_info->attributes,
TX_PACKET_ATTRIBUTES_VLAN_CTAG_POS,
TX_PACKET_ATTRIBUTES_VLAN_CTAG_LEN);
if (tso && (pkt_info->mss != ring->tx.cur_mss))
tso_context = 1;
else
tso_context = 0;
if (vlan && (pkt_info->vlan_ctag != ring->tx.cur_vlan_ctag))
vlan_context = 1;
else
vlan_context = 0;
ring->coalesce_count += pkt_info->tx_packets;
if (!pdata->tx_frames)
tx_set_ic = 0;
else if (pkt_info->tx_packets > pdata->tx_frames)
tx_set_ic = 1;
else if ((ring->coalesce_count % pdata->tx_frames) <
pkt_info->tx_packets)
tx_set_ic = 1;
else
tx_set_ic = 0;
desc_data = XLGMAC_GET_DESC_DATA(ring, cur_index);
dma_desc = desc_data->dma_desc;
if (tso_context || vlan_context) {
if (tso_context) {
netif_dbg(pdata, tx_queued, pdata->netdev,
"TSO context descriptor, mss=%u\n",
pkt_info->mss);
dma_desc->desc2 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc2,
TX_CONTEXT_DESC2_MSS_POS,
TX_CONTEXT_DESC2_MSS_LEN,
pkt_info->mss);
dma_desc->desc3 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc3,
TX_CONTEXT_DESC3_CTXT_POS,
TX_CONTEXT_DESC3_CTXT_LEN,
1);
dma_desc->desc3 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc3,
TX_CONTEXT_DESC3_TCMSSV_POS,
TX_CONTEXT_DESC3_TCMSSV_LEN,
1);
ring->tx.cur_mss = pkt_info->mss;
}
if (vlan_context) {
netif_dbg(pdata, tx_queued, pdata->netdev,
"VLAN context descriptor, ctag=%u\n",
pkt_info->vlan_ctag);
dma_desc->desc3 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc3,
TX_CONTEXT_DESC3_CTXT_POS,
TX_CONTEXT_DESC3_CTXT_LEN,
1);
dma_desc->desc3 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc3,
TX_CONTEXT_DESC3_VT_POS,
TX_CONTEXT_DESC3_VT_LEN,
pkt_info->vlan_ctag);
dma_desc->desc3 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc3,
TX_CONTEXT_DESC3_VLTV_POS,
TX_CONTEXT_DESC3_VLTV_LEN,
1);
ring->tx.cur_vlan_ctag = pkt_info->vlan_ctag;
}
cur_index++;
desc_data = XLGMAC_GET_DESC_DATA(ring, cur_index);
dma_desc = desc_data->dma_desc;
}
dma_desc->desc0 = cpu_to_le32(lower_32_bits(desc_data->skb_dma));
dma_desc->desc1 = cpu_to_le32(upper_32_bits(desc_data->skb_dma));
dma_desc->desc2 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc2,
TX_NORMAL_DESC2_HL_B1L_POS,
TX_NORMAL_DESC2_HL_B1L_LEN,
desc_data->skb_dma_len);
if (vlan) {
dma_desc->desc2 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc2,
TX_NORMAL_DESC2_VTIR_POS,
TX_NORMAL_DESC2_VTIR_LEN,
TX_NORMAL_DESC2_VLAN_INSERT);
pdata->stats.tx_vlan_packets++;
}
if (XLGMAC_GET_REG_BITS(pkt_info->attributes,
TX_PACKET_ATTRIBUTES_PTP_POS,
TX_PACKET_ATTRIBUTES_PTP_LEN))
dma_desc->desc2 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc2,
TX_NORMAL_DESC2_TTSE_POS,
TX_NORMAL_DESC2_TTSE_LEN,
1);
dma_desc->desc3 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc3,
TX_NORMAL_DESC3_FD_POS,
TX_NORMAL_DESC3_FD_LEN,
1);
dma_desc->desc3 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc3,
TX_NORMAL_DESC3_CTXT_POS,
TX_NORMAL_DESC3_CTXT_LEN,
0);
if (cur_index != start_index)
dma_desc->desc3 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc3,
TX_NORMAL_DESC3_OWN_POS,
TX_NORMAL_DESC3_OWN_LEN,
1);
if (tso) {
dma_desc->desc3 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc3,
TX_NORMAL_DESC3_TSE_POS,
TX_NORMAL_DESC3_TSE_LEN, 1);
dma_desc->desc3 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc3,
TX_NORMAL_DESC3_TCPPL_POS,
TX_NORMAL_DESC3_TCPPL_LEN,
pkt_info->tcp_payload_len);
dma_desc->desc3 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc3,
TX_NORMAL_DESC3_TCPHDRLEN_POS,
TX_NORMAL_DESC3_TCPHDRLEN_LEN,
pkt_info->tcp_header_len / 4);
pdata->stats.tx_tso_packets++;
} else {
dma_desc->desc3 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc3,
TX_NORMAL_DESC3_CPC_POS,
TX_NORMAL_DESC3_CPC_LEN, 0);
if (csum)
dma_desc->desc3 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc3,
TX_NORMAL_DESC3_CIC_POS,
TX_NORMAL_DESC3_CIC_LEN,
0x3);
dma_desc->desc3 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc3,
TX_NORMAL_DESC3_FL_POS,
TX_NORMAL_DESC3_FL_LEN,
pkt_info->length);
}
for (i = cur_index - start_index + 1; i < pkt_info->desc_count; i++) {
cur_index++;
desc_data = XLGMAC_GET_DESC_DATA(ring, cur_index);
dma_desc = desc_data->dma_desc;
dma_desc->desc0 =
cpu_to_le32(lower_32_bits(desc_data->skb_dma));
dma_desc->desc1 =
cpu_to_le32(upper_32_bits(desc_data->skb_dma));
dma_desc->desc2 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc2,
TX_NORMAL_DESC2_HL_B1L_POS,
TX_NORMAL_DESC2_HL_B1L_LEN,
desc_data->skb_dma_len);
dma_desc->desc3 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc3,
TX_NORMAL_DESC3_OWN_POS,
TX_NORMAL_DESC3_OWN_LEN, 1);
dma_desc->desc3 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc3,
TX_NORMAL_DESC3_CTXT_POS,
TX_NORMAL_DESC3_CTXT_LEN, 0);
if (csum)
dma_desc->desc3 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc3,
TX_NORMAL_DESC3_CIC_POS,
TX_NORMAL_DESC3_CIC_LEN,
0x3);
}
dma_desc->desc3 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc3,
TX_NORMAL_DESC3_LD_POS,
TX_NORMAL_DESC3_LD_LEN, 1);
if (tx_set_ic)
dma_desc->desc2 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc2,
TX_NORMAL_DESC2_IC_POS,
TX_NORMAL_DESC2_IC_LEN, 1);
desc_data->tx.packets = pkt_info->tx_packets;
desc_data->tx.bytes = pkt_info->tx_bytes;
dma_wmb();
desc_data = XLGMAC_GET_DESC_DATA(ring, start_index);
dma_desc = desc_data->dma_desc;
dma_desc->desc3 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc3,
TX_NORMAL_DESC3_OWN_POS,
TX_NORMAL_DESC3_OWN_LEN, 1);
if (netif_msg_tx_queued(pdata))
xlgmac_dump_tx_desc(pdata, ring, start_index,
pkt_info->desc_count, 1);
smp_wmb();
ring->cur = cur_index + 1;
if (!pkt_info->skb->xmit_more ||
netif_xmit_stopped(netdev_get_tx_queue(pdata->netdev,
channel->queue_index)))
xlgmac_tx_start_xmit(channel, ring);
else
ring->tx.xmit_more = 1;
XLGMAC_PR("%s: descriptors %u to %u written\n",
channel->name, start_index & (ring->dma_desc_count - 1),
(ring->cur - 1) & (ring->dma_desc_count - 1));
}
static void xlgmac_get_rx_tstamp(struct xlgmac_pkt_info *pkt_info,
struct xlgmac_dma_desc *dma_desc)
{
u32 tsa, tsd;
u64 nsec;
tsa = XLGMAC_GET_REG_BITS_LE(dma_desc->desc3,
RX_CONTEXT_DESC3_TSA_POS,
RX_CONTEXT_DESC3_TSA_LEN);
tsd = XLGMAC_GET_REG_BITS_LE(dma_desc->desc3,
RX_CONTEXT_DESC3_TSD_POS,
RX_CONTEXT_DESC3_TSD_LEN);
if (tsa && !tsd) {
nsec = le32_to_cpu(dma_desc->desc1);
nsec <<= 32;
nsec |= le32_to_cpu(dma_desc->desc0);
if (nsec != 0xffffffffffffffffULL) {
pkt_info->rx_tstamp = nsec;
pkt_info->attributes = XLGMAC_SET_REG_BITS(
pkt_info->attributes,
RX_PACKET_ATTRIBUTES_RX_TSTAMP_POS,
RX_PACKET_ATTRIBUTES_RX_TSTAMP_LEN,
1);
}
}
}
static void xlgmac_tx_desc_reset(struct xlgmac_desc_data *desc_data)
{
struct xlgmac_dma_desc *dma_desc = desc_data->dma_desc;
dma_desc->desc0 = 0;
dma_desc->desc1 = 0;
dma_desc->desc2 = 0;
dma_desc->desc3 = 0;
dma_wmb();
}
static void xlgmac_tx_desc_init(struct xlgmac_channel *channel)
{
struct xlgmac_ring *ring = channel->tx_ring;
struct xlgmac_desc_data *desc_data;
int start_index = ring->cur;
int i;
for (i = 0; i < ring->dma_desc_count; i++) {
desc_data = XLGMAC_GET_DESC_DATA(ring, i);
xlgmac_tx_desc_reset(desc_data);
}
writel(ring->dma_desc_count - 1, XLGMAC_DMA_REG(channel, DMA_CH_TDRLR));
desc_data = XLGMAC_GET_DESC_DATA(ring, start_index);
writel(upper_32_bits(desc_data->dma_desc_addr),
XLGMAC_DMA_REG(channel, DMA_CH_TDLR_HI));
writel(lower_32_bits(desc_data->dma_desc_addr),
XLGMAC_DMA_REG(channel, DMA_CH_TDLR_LO));
}
static void xlgmac_rx_desc_reset(struct xlgmac_pdata *pdata,
struct xlgmac_desc_data *desc_data,
unsigned int index)
{
struct xlgmac_dma_desc *dma_desc = desc_data->dma_desc;
unsigned int rx_frames = pdata->rx_frames;
unsigned int rx_usecs = pdata->rx_usecs;
dma_addr_t hdr_dma, buf_dma;
unsigned int inte;
if (!rx_usecs && !rx_frames) {
inte = 1;
} else {
if (rx_frames && !((index + 1) % rx_frames))
inte = 1;
else
inte = 0;
}
hdr_dma = desc_data->rx.hdr.dma_base + desc_data->rx.hdr.dma_off;
buf_dma = desc_data->rx.buf.dma_base + desc_data->rx.buf.dma_off;
dma_desc->desc0 = cpu_to_le32(lower_32_bits(hdr_dma));
dma_desc->desc1 = cpu_to_le32(upper_32_bits(hdr_dma));
dma_desc->desc2 = cpu_to_le32(lower_32_bits(buf_dma));
dma_desc->desc3 = cpu_to_le32(upper_32_bits(buf_dma));
dma_desc->desc3 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc3,
RX_NORMAL_DESC3_INTE_POS,
RX_NORMAL_DESC3_INTE_LEN,
inte);
dma_wmb();
dma_desc->desc3 = XLGMAC_SET_REG_BITS_LE(
dma_desc->desc3,
RX_NORMAL_DESC3_OWN_POS,
RX_NORMAL_DESC3_OWN_LEN,
1);
dma_wmb();
}
static void xlgmac_rx_desc_init(struct xlgmac_channel *channel)
{
struct xlgmac_pdata *pdata = channel->pdata;
struct xlgmac_ring *ring = channel->rx_ring;
unsigned int start_index = ring->cur;
struct xlgmac_desc_data *desc_data;
unsigned int i;
for (i = 0; i < ring->dma_desc_count; i++) {
desc_data = XLGMAC_GET_DESC_DATA(ring, i);
xlgmac_rx_desc_reset(pdata, desc_data, i);
}
writel(ring->dma_desc_count - 1, XLGMAC_DMA_REG(channel, DMA_CH_RDRLR));
desc_data = XLGMAC_GET_DESC_DATA(ring, start_index);
writel(upper_32_bits(desc_data->dma_desc_addr),
XLGMAC_DMA_REG(channel, DMA_CH_RDLR_HI));
writel(lower_32_bits(desc_data->dma_desc_addr),
XLGMAC_DMA_REG(channel, DMA_CH_RDLR_LO));
desc_data = XLGMAC_GET_DESC_DATA(ring, start_index +
ring->dma_desc_count - 1);
writel(lower_32_bits(desc_data->dma_desc_addr),
XLGMAC_DMA_REG(channel, DMA_CH_RDTR_LO));
}
static int xlgmac_is_context_desc(struct xlgmac_dma_desc *dma_desc)
{
return XLGMAC_GET_REG_BITS_LE(dma_desc->desc3,
TX_NORMAL_DESC3_CTXT_POS,
TX_NORMAL_DESC3_CTXT_LEN);
}
static int xlgmac_is_last_desc(struct xlgmac_dma_desc *dma_desc)
{
return XLGMAC_GET_REG_BITS_LE(dma_desc->desc3,
TX_NORMAL_DESC3_LD_POS,
TX_NORMAL_DESC3_LD_LEN);
}
static int xlgmac_disable_tx_flow_control(struct xlgmac_pdata *pdata)
{
unsigned int max_q_count, q_count;
unsigned int reg, regval;
unsigned int i;
for (i = 0; i < pdata->rx_q_count; i++) {
regval = readl(XLGMAC_MTL_REG(pdata, i, MTL_Q_RQOMR));
regval = XLGMAC_SET_REG_BITS(regval, MTL_Q_RQOMR_EHFC_POS,
MTL_Q_RQOMR_EHFC_LEN, 0);
writel(regval, XLGMAC_MTL_REG(pdata, i, MTL_Q_RQOMR));
}
max_q_count = XLGMAC_MAX_FLOW_CONTROL_QUEUES;
q_count = min_t(unsigned int, pdata->tx_q_count, max_q_count);
reg = MAC_Q0TFCR;
for (i = 0; i < q_count; i++) {
regval = readl(pdata->mac_regs + reg);
regval = XLGMAC_SET_REG_BITS(regval,
MAC_Q0TFCR_TFE_POS,
MAC_Q0TFCR_TFE_LEN,
0);
writel(regval, pdata->mac_regs + reg);
reg += MAC_QTFCR_INC;
}
return 0;
}
static int xlgmac_enable_tx_flow_control(struct xlgmac_pdata *pdata)
{
unsigned int max_q_count, q_count;
unsigned int reg, regval;
unsigned int i;
for (i = 0; i < pdata->rx_q_count; i++) {
regval = readl(XLGMAC_MTL_REG(pdata, i, MTL_Q_RQOMR));
regval = XLGMAC_SET_REG_BITS(regval, MTL_Q_RQOMR_EHFC_POS,
MTL_Q_RQOMR_EHFC_LEN, 1);
writel(regval, XLGMAC_MTL_REG(pdata, i, MTL_Q_RQOMR));
}
max_q_count = XLGMAC_MAX_FLOW_CONTROL_QUEUES;
q_count = min_t(unsigned int, pdata->tx_q_count, max_q_count);
reg = MAC_Q0TFCR;
for (i = 0; i < q_count; i++) {
regval = readl(pdata->mac_regs + reg);
regval = XLGMAC_SET_REG_BITS(regval, MAC_Q0TFCR_TFE_POS,
MAC_Q0TFCR_TFE_LEN, 1);
regval = XLGMAC_SET_REG_BITS(regval, MAC_Q0TFCR_PT_POS,
MAC_Q0TFCR_PT_LEN, 0xffff);
writel(regval, pdata->mac_regs + reg);
reg += MAC_QTFCR_INC;
}
return 0;
}
static int xlgmac_disable_rx_flow_control(struct xlgmac_pdata *pdata)
{
u32 regval;
regval = readl(pdata->mac_regs + MAC_RFCR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_RFCR_RFE_POS,
MAC_RFCR_RFE_LEN, 0);
writel(regval, pdata->mac_regs + MAC_RFCR);
return 0;
}
static int xlgmac_enable_rx_flow_control(struct xlgmac_pdata *pdata)
{
u32 regval;
regval = readl(pdata->mac_regs + MAC_RFCR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_RFCR_RFE_POS,
MAC_RFCR_RFE_LEN, 1);
writel(regval, pdata->mac_regs + MAC_RFCR);
return 0;
}
static int xlgmac_config_tx_flow_control(struct xlgmac_pdata *pdata)
{
if (pdata->tx_pause)
xlgmac_enable_tx_flow_control(pdata);
else
xlgmac_disable_tx_flow_control(pdata);
return 0;
}
static int xlgmac_config_rx_flow_control(struct xlgmac_pdata *pdata)
{
if (pdata->rx_pause)
xlgmac_enable_rx_flow_control(pdata);
else
xlgmac_disable_rx_flow_control(pdata);
return 0;
}
static int xlgmac_config_rx_coalesce(struct xlgmac_pdata *pdata)
{
struct xlgmac_channel *channel;
unsigned int i;
u32 regval;
channel = pdata->channel_head;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->rx_ring)
break;
regval = readl(XLGMAC_DMA_REG(channel, DMA_CH_RIWT));
regval = XLGMAC_SET_REG_BITS(regval, DMA_CH_RIWT_RWT_POS,
DMA_CH_RIWT_RWT_LEN,
pdata->rx_riwt);
writel(regval, XLGMAC_DMA_REG(channel, DMA_CH_RIWT));
}
return 0;
}
static void xlgmac_config_flow_control(struct xlgmac_pdata *pdata)
{
xlgmac_config_tx_flow_control(pdata);
xlgmac_config_rx_flow_control(pdata);
}
static void xlgmac_config_rx_fep_enable(struct xlgmac_pdata *pdata)
{
unsigned int i;
u32 regval;
for (i = 0; i < pdata->rx_q_count; i++) {
regval = readl(XLGMAC_MTL_REG(pdata, i, MTL_Q_RQOMR));
regval = XLGMAC_SET_REG_BITS(regval, MTL_Q_RQOMR_FEP_POS,
MTL_Q_RQOMR_FEP_LEN, 1);
writel(regval, XLGMAC_MTL_REG(pdata, i, MTL_Q_RQOMR));
}
}
static void xlgmac_config_rx_fup_enable(struct xlgmac_pdata *pdata)
{
unsigned int i;
u32 regval;
for (i = 0; i < pdata->rx_q_count; i++) {
regval = readl(XLGMAC_MTL_REG(pdata, i, MTL_Q_RQOMR));
regval = XLGMAC_SET_REG_BITS(regval, MTL_Q_RQOMR_FUP_POS,
MTL_Q_RQOMR_FUP_LEN, 1);
writel(regval, XLGMAC_MTL_REG(pdata, i, MTL_Q_RQOMR));
}
}
static int xlgmac_config_tx_coalesce(struct xlgmac_pdata *pdata)
{
return 0;
}
static void xlgmac_config_rx_buffer_size(struct xlgmac_pdata *pdata)
{
struct xlgmac_channel *channel;
unsigned int i;
u32 regval;
channel = pdata->channel_head;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->rx_ring)
break;
regval = readl(XLGMAC_DMA_REG(channel, DMA_CH_RCR));
regval = XLGMAC_SET_REG_BITS(regval, DMA_CH_RCR_RBSZ_POS,
DMA_CH_RCR_RBSZ_LEN,
pdata->rx_buf_size);
writel(regval, XLGMAC_DMA_REG(channel, DMA_CH_RCR));
}
}
static void xlgmac_config_tso_mode(struct xlgmac_pdata *pdata)
{
struct xlgmac_channel *channel;
unsigned int i;
u32 regval;
channel = pdata->channel_head;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->tx_ring)
break;
if (pdata->hw_feat.tso) {
regval = readl(XLGMAC_DMA_REG(channel, DMA_CH_TCR));
regval = XLGMAC_SET_REG_BITS(regval, DMA_CH_TCR_TSE_POS,
DMA_CH_TCR_TSE_LEN, 1);
writel(regval, XLGMAC_DMA_REG(channel, DMA_CH_TCR));
}
}
}
static void xlgmac_config_sph_mode(struct xlgmac_pdata *pdata)
{
struct xlgmac_channel *channel;
unsigned int i;
u32 regval;
channel = pdata->channel_head;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->rx_ring)
break;
regval = readl(XLGMAC_DMA_REG(channel, DMA_CH_CR));
regval = XLGMAC_SET_REG_BITS(regval, DMA_CH_CR_SPH_POS,
DMA_CH_CR_SPH_LEN, 1);
writel(regval, XLGMAC_DMA_REG(channel, DMA_CH_CR));
}
regval = readl(pdata->mac_regs + MAC_RCR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_RCR_HDSMS_POS,
MAC_RCR_HDSMS_LEN,
XLGMAC_SPH_HDSMS_SIZE);
writel(regval, pdata->mac_regs + MAC_RCR);
}
static unsigned int xlgmac_usec_to_riwt(struct xlgmac_pdata *pdata,
unsigned int usec)
{
unsigned long rate;
unsigned int ret;
rate = pdata->sysclk_rate;
ret = (usec * (rate / 1000000)) / 256;
return ret;
}
static unsigned int xlgmac_riwt_to_usec(struct xlgmac_pdata *pdata,
unsigned int riwt)
{
unsigned long rate;
unsigned int ret;
rate = pdata->sysclk_rate;
ret = (riwt * 256) / (rate / 1000000);
return ret;
}
static int xlgmac_config_rx_threshold(struct xlgmac_pdata *pdata,
unsigned int val)
{
unsigned int i;
u32 regval;
for (i = 0; i < pdata->rx_q_count; i++) {
regval = readl(XLGMAC_MTL_REG(pdata, i, MTL_Q_RQOMR));
regval = XLGMAC_SET_REG_BITS(regval, MTL_Q_RQOMR_RTC_POS,
MTL_Q_RQOMR_RTC_LEN, val);
writel(regval, XLGMAC_MTL_REG(pdata, i, MTL_Q_RQOMR));
}
return 0;
}
static void xlgmac_config_mtl_mode(struct xlgmac_pdata *pdata)
{
unsigned int i;
u32 regval;
regval = readl(pdata->mac_regs + MTL_OMR);
regval = XLGMAC_SET_REG_BITS(regval, MTL_OMR_ETSALG_POS,
MTL_OMR_ETSALG_LEN, MTL_ETSALG_WRR);
writel(regval, pdata->mac_regs + MTL_OMR);
for (i = 0; i < pdata->hw_feat.tc_cnt; i++) {
regval = readl(XLGMAC_MTL_REG(pdata, i, MTL_TC_ETSCR));
regval = XLGMAC_SET_REG_BITS(regval, MTL_TC_ETSCR_TSA_POS,
MTL_TC_ETSCR_TSA_LEN, MTL_TSA_ETS);
writel(regval, XLGMAC_MTL_REG(pdata, i, MTL_TC_ETSCR));
regval = readl(XLGMAC_MTL_REG(pdata, i, MTL_TC_QWR));
regval = XLGMAC_SET_REG_BITS(regval, MTL_TC_QWR_QW_POS,
MTL_TC_QWR_QW_LEN, 1);
writel(regval, XLGMAC_MTL_REG(pdata, i, MTL_TC_QWR));
}
regval = readl(pdata->mac_regs + MTL_OMR);
regval = XLGMAC_SET_REG_BITS(regval, MTL_OMR_RAA_POS,
MTL_OMR_RAA_LEN, MTL_RAA_SP);
writel(regval, pdata->mac_regs + MTL_OMR);
}
static void xlgmac_config_queue_mapping(struct xlgmac_pdata *pdata)
{
unsigned int ppq, ppq_extra, prio, prio_queues;
unsigned int qptc, qptc_extra, queue;
unsigned int reg, regval;
unsigned int mask;
unsigned int i, j;
qptc = pdata->tx_q_count / pdata->hw_feat.tc_cnt;
qptc_extra = pdata->tx_q_count % pdata->hw_feat.tc_cnt;
for (i = 0, queue = 0; i < pdata->hw_feat.tc_cnt; i++) {
for (j = 0; j < qptc; j++) {
netif_dbg(pdata, drv, pdata->netdev,
"TXq%u mapped to TC%u\n", queue, i);
regval = readl(XLGMAC_MTL_REG(pdata, queue,
MTL_Q_TQOMR));
regval = XLGMAC_SET_REG_BITS(regval,
MTL_Q_TQOMR_Q2TCMAP_POS,
MTL_Q_TQOMR_Q2TCMAP_LEN,
i);
writel(regval, XLGMAC_MTL_REG(pdata, queue,
MTL_Q_TQOMR));
queue++;
}
if (i < qptc_extra) {
netif_dbg(pdata, drv, pdata->netdev,
"TXq%u mapped to TC%u\n", queue, i);
regval = readl(XLGMAC_MTL_REG(pdata, queue,
MTL_Q_TQOMR));
regval = XLGMAC_SET_REG_BITS(regval,
MTL_Q_TQOMR_Q2TCMAP_POS,
MTL_Q_TQOMR_Q2TCMAP_LEN,
i);
writel(regval, XLGMAC_MTL_REG(pdata, queue,
MTL_Q_TQOMR));
queue++;
}
}
prio_queues = min_t(unsigned int, IEEE_8021QAZ_MAX_TCS,
pdata->rx_q_count);
ppq = IEEE_8021QAZ_MAX_TCS / prio_queues;
ppq_extra = IEEE_8021QAZ_MAX_TCS % prio_queues;
reg = MAC_RQC2R;
regval = 0;
for (i = 0, prio = 0; i < prio_queues;) {
mask = 0;
for (j = 0; j < ppq; j++) {
netif_dbg(pdata, drv, pdata->netdev,
"PRIO%u mapped to RXq%u\n", prio, i);
mask |= (1 << prio);
prio++;
}
if (i < ppq_extra) {
netif_dbg(pdata, drv, pdata->netdev,
"PRIO%u mapped to RXq%u\n", prio, i);
mask |= (1 << prio);
prio++;
}
regval |= (mask << ((i++ % MAC_RQC2_Q_PER_REG) << 3));
if ((i % MAC_RQC2_Q_PER_REG) && (i != prio_queues))
continue;
writel(regval, pdata->mac_regs + reg);
reg += MAC_RQC2_INC;
regval = 0;
}
reg = MTL_RQDCM0R;
regval = readl(pdata->mac_regs + reg);
regval |= (MTL_RQDCM0R_Q0MDMACH | MTL_RQDCM0R_Q1MDMACH |
MTL_RQDCM0R_Q2MDMACH | MTL_RQDCM0R_Q3MDMACH);
writel(regval, pdata->mac_regs + reg);
reg += MTL_RQDCM_INC;
regval = readl(pdata->mac_regs + reg);
regval |= (MTL_RQDCM1R_Q4MDMACH | MTL_RQDCM1R_Q5MDMACH |
MTL_RQDCM1R_Q6MDMACH | MTL_RQDCM1R_Q7MDMACH);
writel(regval, pdata->mac_regs + reg);
reg += MTL_RQDCM_INC;
regval = readl(pdata->mac_regs + reg);
regval |= (MTL_RQDCM2R_Q8MDMACH | MTL_RQDCM2R_Q9MDMACH |
MTL_RQDCM2R_Q10MDMACH | MTL_RQDCM2R_Q11MDMACH);
writel(regval, pdata->mac_regs + reg);
}
static unsigned int xlgmac_calculate_per_queue_fifo(
unsigned int fifo_size,
unsigned int queue_count)
{
unsigned int q_fifo_size;
unsigned int p_fifo;
q_fifo_size = 1 << (fifo_size + 7);
q_fifo_size = min_t(unsigned int, XLGMAC_MAX_FIFO, q_fifo_size);
q_fifo_size = q_fifo_size / queue_count;
p_fifo = q_fifo_size / 256;
if (p_fifo)
p_fifo--;
return p_fifo;
}
static void xlgmac_config_tx_fifo_size(struct xlgmac_pdata *pdata)
{
unsigned int fifo_size;
unsigned int i;
u32 regval;
fifo_size = xlgmac_calculate_per_queue_fifo(
pdata->hw_feat.tx_fifo_size,
pdata->tx_q_count);
for (i = 0; i < pdata->tx_q_count; i++) {
regval = readl(XLGMAC_MTL_REG(pdata, i, MTL_Q_TQOMR));
regval = XLGMAC_SET_REG_BITS(regval, MTL_Q_TQOMR_TQS_POS,
MTL_Q_TQOMR_TQS_LEN, fifo_size);
writel(regval, XLGMAC_MTL_REG(pdata, i, MTL_Q_TQOMR));
}
netif_info(pdata, drv, pdata->netdev,
"%d Tx hardware queues, %d byte fifo per queue\n",
pdata->tx_q_count, ((fifo_size + 1) * 256));
}
static void xlgmac_config_rx_fifo_size(struct xlgmac_pdata *pdata)
{
unsigned int fifo_size;
unsigned int i;
u32 regval;
fifo_size = xlgmac_calculate_per_queue_fifo(
pdata->hw_feat.rx_fifo_size,
pdata->rx_q_count);
for (i = 0; i < pdata->rx_q_count; i++) {
regval = readl(XLGMAC_MTL_REG(pdata, i, MTL_Q_RQOMR));
regval = XLGMAC_SET_REG_BITS(regval, MTL_Q_RQOMR_RQS_POS,
MTL_Q_RQOMR_RQS_LEN, fifo_size);
writel(regval, XLGMAC_MTL_REG(pdata, i, MTL_Q_RQOMR));
}
netif_info(pdata, drv, pdata->netdev,
"%d Rx hardware queues, %d byte fifo per queue\n",
pdata->rx_q_count, ((fifo_size + 1) * 256));
}
static void xlgmac_config_flow_control_threshold(struct xlgmac_pdata *pdata)
{
unsigned int i;
u32 regval;
for (i = 0; i < pdata->rx_q_count; i++) {
regval = readl(XLGMAC_MTL_REG(pdata, i, MTL_Q_RQFCR));
regval = XLGMAC_SET_REG_BITS(regval, MTL_Q_RQFCR_RFA_POS,
MTL_Q_RQFCR_RFA_LEN, 2);
regval = XLGMAC_SET_REG_BITS(regval, MTL_Q_RQFCR_RFD_POS,
MTL_Q_RQFCR_RFD_LEN, 4);
writel(regval, XLGMAC_MTL_REG(pdata, i, MTL_Q_RQFCR));
}
}
static int xlgmac_config_tx_threshold(struct xlgmac_pdata *pdata,
unsigned int val)
{
unsigned int i;
u32 regval;
for (i = 0; i < pdata->tx_q_count; i++) {
regval = readl(XLGMAC_MTL_REG(pdata, i, MTL_Q_TQOMR));
regval = XLGMAC_SET_REG_BITS(regval, MTL_Q_TQOMR_TTC_POS,
MTL_Q_TQOMR_TTC_LEN, val);
writel(regval, XLGMAC_MTL_REG(pdata, i, MTL_Q_TQOMR));
}
return 0;
}
static int xlgmac_config_rsf_mode(struct xlgmac_pdata *pdata,
unsigned int val)
{
unsigned int i;
u32 regval;
for (i = 0; i < pdata->rx_q_count; i++) {
regval = readl(XLGMAC_MTL_REG(pdata, i, MTL_Q_RQOMR));
regval = XLGMAC_SET_REG_BITS(regval, MTL_Q_RQOMR_RSF_POS,
MTL_Q_RQOMR_RSF_LEN, val);
writel(regval, XLGMAC_MTL_REG(pdata, i, MTL_Q_RQOMR));
}
return 0;
}
static int xlgmac_config_tsf_mode(struct xlgmac_pdata *pdata,
unsigned int val)
{
unsigned int i;
u32 regval;
for (i = 0; i < pdata->tx_q_count; i++) {
regval = readl(XLGMAC_MTL_REG(pdata, i, MTL_Q_TQOMR));
regval = XLGMAC_SET_REG_BITS(regval, MTL_Q_TQOMR_TSF_POS,
MTL_Q_TQOMR_TSF_LEN, val);
writel(regval, XLGMAC_MTL_REG(pdata, i, MTL_Q_TQOMR));
}
return 0;
}
static int xlgmac_config_osp_mode(struct xlgmac_pdata *pdata)
{
struct xlgmac_channel *channel;
unsigned int i;
u32 regval;
channel = pdata->channel_head;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->tx_ring)
break;
regval = readl(XLGMAC_DMA_REG(channel, DMA_CH_TCR));
regval = XLGMAC_SET_REG_BITS(regval, DMA_CH_TCR_OSP_POS,
DMA_CH_TCR_OSP_LEN,
pdata->tx_osp_mode);
writel(regval, XLGMAC_DMA_REG(channel, DMA_CH_TCR));
}
return 0;
}
static int xlgmac_config_pblx8(struct xlgmac_pdata *pdata)
{
struct xlgmac_channel *channel;
unsigned int i;
u32 regval;
channel = pdata->channel_head;
for (i = 0; i < pdata->channel_count; i++, channel++) {
regval = readl(XLGMAC_DMA_REG(channel, DMA_CH_CR));
regval = XLGMAC_SET_REG_BITS(regval, DMA_CH_CR_PBLX8_POS,
DMA_CH_CR_PBLX8_LEN,
pdata->pblx8);
writel(regval, XLGMAC_DMA_REG(channel, DMA_CH_CR));
}
return 0;
}
static int xlgmac_get_tx_pbl_val(struct xlgmac_pdata *pdata)
{
u32 regval;
regval = readl(XLGMAC_DMA_REG(pdata->channel_head, DMA_CH_TCR));
regval = XLGMAC_GET_REG_BITS(regval, DMA_CH_TCR_PBL_POS,
DMA_CH_TCR_PBL_LEN);
return regval;
}
static int xlgmac_config_tx_pbl_val(struct xlgmac_pdata *pdata)
{
struct xlgmac_channel *channel;
unsigned int i;
u32 regval;
channel = pdata->channel_head;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->tx_ring)
break;
regval = readl(XLGMAC_DMA_REG(channel, DMA_CH_TCR));
regval = XLGMAC_SET_REG_BITS(regval, DMA_CH_TCR_PBL_POS,
DMA_CH_TCR_PBL_LEN,
pdata->tx_pbl);
writel(regval, XLGMAC_DMA_REG(channel, DMA_CH_TCR));
}
return 0;
}
static int xlgmac_get_rx_pbl_val(struct xlgmac_pdata *pdata)
{
u32 regval;
regval = readl(XLGMAC_DMA_REG(pdata->channel_head, DMA_CH_RCR));
regval = XLGMAC_GET_REG_BITS(regval, DMA_CH_RCR_PBL_POS,
DMA_CH_RCR_PBL_LEN);
return regval;
}
static int xlgmac_config_rx_pbl_val(struct xlgmac_pdata *pdata)
{
struct xlgmac_channel *channel;
unsigned int i;
u32 regval;
channel = pdata->channel_head;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->rx_ring)
break;
regval = readl(XLGMAC_DMA_REG(channel, DMA_CH_RCR));
regval = XLGMAC_SET_REG_BITS(regval, DMA_CH_RCR_PBL_POS,
DMA_CH_RCR_PBL_LEN,
pdata->rx_pbl);
writel(regval, XLGMAC_DMA_REG(channel, DMA_CH_RCR));
}
return 0;
}
static u64 xlgmac_mmc_read(struct xlgmac_pdata *pdata, unsigned int reg_lo)
{
bool read_hi;
u64 val;
switch (reg_lo) {
case MMC_TXOCTETCOUNT_GB_LO:
case MMC_TXOCTETCOUNT_G_LO:
case MMC_RXOCTETCOUNT_GB_LO:
case MMC_RXOCTETCOUNT_G_LO:
read_hi = true;
break;
default:
read_hi = false;
}
val = (u64)readl(pdata->mac_regs + reg_lo);
if (read_hi)
val |= ((u64)readl(pdata->mac_regs + reg_lo + 4) << 32);
return val;
}
static void xlgmac_tx_mmc_int(struct xlgmac_pdata *pdata)
{
unsigned int mmc_isr = readl(pdata->mac_regs + MMC_TISR);
struct xlgmac_stats *stats = &pdata->stats;
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_TISR_TXOCTETCOUNT_GB_POS,
MMC_TISR_TXOCTETCOUNT_GB_LEN))
stats->txoctetcount_gb +=
xlgmac_mmc_read(pdata, MMC_TXOCTETCOUNT_GB_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_TISR_TXFRAMECOUNT_GB_POS,
MMC_TISR_TXFRAMECOUNT_GB_LEN))
stats->txframecount_gb +=
xlgmac_mmc_read(pdata, MMC_TXFRAMECOUNT_GB_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_TISR_TXBROADCASTFRAMES_G_POS,
MMC_TISR_TXBROADCASTFRAMES_G_LEN))
stats->txbroadcastframes_g +=
xlgmac_mmc_read(pdata, MMC_TXBROADCASTFRAMES_G_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_TISR_TXMULTICASTFRAMES_G_POS,
MMC_TISR_TXMULTICASTFRAMES_G_LEN))
stats->txmulticastframes_g +=
xlgmac_mmc_read(pdata, MMC_TXMULTICASTFRAMES_G_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_TISR_TX64OCTETS_GB_POS,
MMC_TISR_TX64OCTETS_GB_LEN))
stats->tx64octets_gb +=
xlgmac_mmc_read(pdata, MMC_TX64OCTETS_GB_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_TISR_TX65TO127OCTETS_GB_POS,
MMC_TISR_TX65TO127OCTETS_GB_LEN))
stats->tx65to127octets_gb +=
xlgmac_mmc_read(pdata, MMC_TX65TO127OCTETS_GB_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_TISR_TX128TO255OCTETS_GB_POS,
MMC_TISR_TX128TO255OCTETS_GB_LEN))
stats->tx128to255octets_gb +=
xlgmac_mmc_read(pdata, MMC_TX128TO255OCTETS_GB_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_TISR_TX256TO511OCTETS_GB_POS,
MMC_TISR_TX256TO511OCTETS_GB_LEN))
stats->tx256to511octets_gb +=
xlgmac_mmc_read(pdata, MMC_TX256TO511OCTETS_GB_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_TISR_TX512TO1023OCTETS_GB_POS,
MMC_TISR_TX512TO1023OCTETS_GB_LEN))
stats->tx512to1023octets_gb +=
xlgmac_mmc_read(pdata, MMC_TX512TO1023OCTETS_GB_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_TISR_TX1024TOMAXOCTETS_GB_POS,
MMC_TISR_TX1024TOMAXOCTETS_GB_LEN))
stats->tx1024tomaxoctets_gb +=
xlgmac_mmc_read(pdata, MMC_TX1024TOMAXOCTETS_GB_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_TISR_TXUNICASTFRAMES_GB_POS,
MMC_TISR_TXUNICASTFRAMES_GB_LEN))
stats->txunicastframes_gb +=
xlgmac_mmc_read(pdata, MMC_TXUNICASTFRAMES_GB_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_TISR_TXMULTICASTFRAMES_GB_POS,
MMC_TISR_TXMULTICASTFRAMES_GB_LEN))
stats->txmulticastframes_gb +=
xlgmac_mmc_read(pdata, MMC_TXMULTICASTFRAMES_GB_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_TISR_TXBROADCASTFRAMES_GB_POS,
MMC_TISR_TXBROADCASTFRAMES_GB_LEN))
stats->txbroadcastframes_g +=
xlgmac_mmc_read(pdata, MMC_TXBROADCASTFRAMES_GB_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_TISR_TXUNDERFLOWERROR_POS,
MMC_TISR_TXUNDERFLOWERROR_LEN))
stats->txunderflowerror +=
xlgmac_mmc_read(pdata, MMC_TXUNDERFLOWERROR_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_TISR_TXOCTETCOUNT_G_POS,
MMC_TISR_TXOCTETCOUNT_G_LEN))
stats->txoctetcount_g +=
xlgmac_mmc_read(pdata, MMC_TXOCTETCOUNT_G_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_TISR_TXFRAMECOUNT_G_POS,
MMC_TISR_TXFRAMECOUNT_G_LEN))
stats->txframecount_g +=
xlgmac_mmc_read(pdata, MMC_TXFRAMECOUNT_G_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_TISR_TXPAUSEFRAMES_POS,
MMC_TISR_TXPAUSEFRAMES_LEN))
stats->txpauseframes +=
xlgmac_mmc_read(pdata, MMC_TXPAUSEFRAMES_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_TISR_TXVLANFRAMES_G_POS,
MMC_TISR_TXVLANFRAMES_G_LEN))
stats->txvlanframes_g +=
xlgmac_mmc_read(pdata, MMC_TXVLANFRAMES_G_LO);
}
static void xlgmac_rx_mmc_int(struct xlgmac_pdata *pdata)
{
unsigned int mmc_isr = readl(pdata->mac_regs + MMC_RISR);
struct xlgmac_stats *stats = &pdata->stats;
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RXFRAMECOUNT_GB_POS,
MMC_RISR_RXFRAMECOUNT_GB_LEN))
stats->rxframecount_gb +=
xlgmac_mmc_read(pdata, MMC_RXFRAMECOUNT_GB_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RXOCTETCOUNT_GB_POS,
MMC_RISR_RXOCTETCOUNT_GB_LEN))
stats->rxoctetcount_gb +=
xlgmac_mmc_read(pdata, MMC_RXOCTETCOUNT_GB_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RXOCTETCOUNT_G_POS,
MMC_RISR_RXOCTETCOUNT_G_LEN))
stats->rxoctetcount_g +=
xlgmac_mmc_read(pdata, MMC_RXOCTETCOUNT_G_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RXBROADCASTFRAMES_G_POS,
MMC_RISR_RXBROADCASTFRAMES_G_LEN))
stats->rxbroadcastframes_g +=
xlgmac_mmc_read(pdata, MMC_RXBROADCASTFRAMES_G_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RXMULTICASTFRAMES_G_POS,
MMC_RISR_RXMULTICASTFRAMES_G_LEN))
stats->rxmulticastframes_g +=
xlgmac_mmc_read(pdata, MMC_RXMULTICASTFRAMES_G_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RXCRCERROR_POS,
MMC_RISR_RXCRCERROR_LEN))
stats->rxcrcerror +=
xlgmac_mmc_read(pdata, MMC_RXCRCERROR_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RXRUNTERROR_POS,
MMC_RISR_RXRUNTERROR_LEN))
stats->rxrunterror +=
xlgmac_mmc_read(pdata, MMC_RXRUNTERROR);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RXJABBERERROR_POS,
MMC_RISR_RXJABBERERROR_LEN))
stats->rxjabbererror +=
xlgmac_mmc_read(pdata, MMC_RXJABBERERROR);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RXUNDERSIZE_G_POS,
MMC_RISR_RXUNDERSIZE_G_LEN))
stats->rxundersize_g +=
xlgmac_mmc_read(pdata, MMC_RXUNDERSIZE_G);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RXOVERSIZE_G_POS,
MMC_RISR_RXOVERSIZE_G_LEN))
stats->rxoversize_g +=
xlgmac_mmc_read(pdata, MMC_RXOVERSIZE_G);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RX64OCTETS_GB_POS,
MMC_RISR_RX64OCTETS_GB_LEN))
stats->rx64octets_gb +=
xlgmac_mmc_read(pdata, MMC_RX64OCTETS_GB_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RX65TO127OCTETS_GB_POS,
MMC_RISR_RX65TO127OCTETS_GB_LEN))
stats->rx65to127octets_gb +=
xlgmac_mmc_read(pdata, MMC_RX65TO127OCTETS_GB_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RX128TO255OCTETS_GB_POS,
MMC_RISR_RX128TO255OCTETS_GB_LEN))
stats->rx128to255octets_gb +=
xlgmac_mmc_read(pdata, MMC_RX128TO255OCTETS_GB_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RX256TO511OCTETS_GB_POS,
MMC_RISR_RX256TO511OCTETS_GB_LEN))
stats->rx256to511octets_gb +=
xlgmac_mmc_read(pdata, MMC_RX256TO511OCTETS_GB_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RX512TO1023OCTETS_GB_POS,
MMC_RISR_RX512TO1023OCTETS_GB_LEN))
stats->rx512to1023octets_gb +=
xlgmac_mmc_read(pdata, MMC_RX512TO1023OCTETS_GB_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RX1024TOMAXOCTETS_GB_POS,
MMC_RISR_RX1024TOMAXOCTETS_GB_LEN))
stats->rx1024tomaxoctets_gb +=
xlgmac_mmc_read(pdata, MMC_RX1024TOMAXOCTETS_GB_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RXUNICASTFRAMES_G_POS,
MMC_RISR_RXUNICASTFRAMES_G_LEN))
stats->rxunicastframes_g +=
xlgmac_mmc_read(pdata, MMC_RXUNICASTFRAMES_G_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RXLENGTHERROR_POS,
MMC_RISR_RXLENGTHERROR_LEN))
stats->rxlengtherror +=
xlgmac_mmc_read(pdata, MMC_RXLENGTHERROR_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RXOUTOFRANGETYPE_POS,
MMC_RISR_RXOUTOFRANGETYPE_LEN))
stats->rxoutofrangetype +=
xlgmac_mmc_read(pdata, MMC_RXOUTOFRANGETYPE_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RXPAUSEFRAMES_POS,
MMC_RISR_RXPAUSEFRAMES_LEN))
stats->rxpauseframes +=
xlgmac_mmc_read(pdata, MMC_RXPAUSEFRAMES_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RXFIFOOVERFLOW_POS,
MMC_RISR_RXFIFOOVERFLOW_LEN))
stats->rxfifooverflow +=
xlgmac_mmc_read(pdata, MMC_RXFIFOOVERFLOW_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RXVLANFRAMES_GB_POS,
MMC_RISR_RXVLANFRAMES_GB_LEN))
stats->rxvlanframes_gb +=
xlgmac_mmc_read(pdata, MMC_RXVLANFRAMES_GB_LO);
if (XLGMAC_GET_REG_BITS(mmc_isr,
MMC_RISR_RXWATCHDOGERROR_POS,
MMC_RISR_RXWATCHDOGERROR_LEN))
stats->rxwatchdogerror +=
xlgmac_mmc_read(pdata, MMC_RXWATCHDOGERROR);
}
static void xlgmac_read_mmc_stats(struct xlgmac_pdata *pdata)
{
struct xlgmac_stats *stats = &pdata->stats;
u32 regval;
regval = readl(pdata->mac_regs + MMC_CR);
regval = XLGMAC_SET_REG_BITS(regval, MMC_CR_MCF_POS,
MMC_CR_MCF_LEN, 1);
writel(regval, pdata->mac_regs + MMC_CR);
stats->txoctetcount_gb +=
xlgmac_mmc_read(pdata, MMC_TXOCTETCOUNT_GB_LO);
stats->txframecount_gb +=
xlgmac_mmc_read(pdata, MMC_TXFRAMECOUNT_GB_LO);
stats->txbroadcastframes_g +=
xlgmac_mmc_read(pdata, MMC_TXBROADCASTFRAMES_G_LO);
stats->txmulticastframes_g +=
xlgmac_mmc_read(pdata, MMC_TXMULTICASTFRAMES_G_LO);
stats->tx64octets_gb +=
xlgmac_mmc_read(pdata, MMC_TX64OCTETS_GB_LO);
stats->tx65to127octets_gb +=
xlgmac_mmc_read(pdata, MMC_TX65TO127OCTETS_GB_LO);
stats->tx128to255octets_gb +=
xlgmac_mmc_read(pdata, MMC_TX128TO255OCTETS_GB_LO);
stats->tx256to511octets_gb +=
xlgmac_mmc_read(pdata, MMC_TX256TO511OCTETS_GB_LO);
stats->tx512to1023octets_gb +=
xlgmac_mmc_read(pdata, MMC_TX512TO1023OCTETS_GB_LO);
stats->tx1024tomaxoctets_gb +=
xlgmac_mmc_read(pdata, MMC_TX1024TOMAXOCTETS_GB_LO);
stats->txunicastframes_gb +=
xlgmac_mmc_read(pdata, MMC_TXUNICASTFRAMES_GB_LO);
stats->txmulticastframes_gb +=
xlgmac_mmc_read(pdata, MMC_TXMULTICASTFRAMES_GB_LO);
stats->txbroadcastframes_g +=
xlgmac_mmc_read(pdata, MMC_TXBROADCASTFRAMES_GB_LO);
stats->txunderflowerror +=
xlgmac_mmc_read(pdata, MMC_TXUNDERFLOWERROR_LO);
stats->txoctetcount_g +=
xlgmac_mmc_read(pdata, MMC_TXOCTETCOUNT_G_LO);
stats->txframecount_g +=
xlgmac_mmc_read(pdata, MMC_TXFRAMECOUNT_G_LO);
stats->txpauseframes +=
xlgmac_mmc_read(pdata, MMC_TXPAUSEFRAMES_LO);
stats->txvlanframes_g +=
xlgmac_mmc_read(pdata, MMC_TXVLANFRAMES_G_LO);
stats->rxframecount_gb +=
xlgmac_mmc_read(pdata, MMC_RXFRAMECOUNT_GB_LO);
stats->rxoctetcount_gb +=
xlgmac_mmc_read(pdata, MMC_RXOCTETCOUNT_GB_LO);
stats->rxoctetcount_g +=
xlgmac_mmc_read(pdata, MMC_RXOCTETCOUNT_G_LO);
stats->rxbroadcastframes_g +=
xlgmac_mmc_read(pdata, MMC_RXBROADCASTFRAMES_G_LO);
stats->rxmulticastframes_g +=
xlgmac_mmc_read(pdata, MMC_RXMULTICASTFRAMES_G_LO);
stats->rxcrcerror +=
xlgmac_mmc_read(pdata, MMC_RXCRCERROR_LO);
stats->rxrunterror +=
xlgmac_mmc_read(pdata, MMC_RXRUNTERROR);
stats->rxjabbererror +=
xlgmac_mmc_read(pdata, MMC_RXJABBERERROR);
stats->rxundersize_g +=
xlgmac_mmc_read(pdata, MMC_RXUNDERSIZE_G);
stats->rxoversize_g +=
xlgmac_mmc_read(pdata, MMC_RXOVERSIZE_G);
stats->rx64octets_gb +=
xlgmac_mmc_read(pdata, MMC_RX64OCTETS_GB_LO);
stats->rx65to127octets_gb +=
xlgmac_mmc_read(pdata, MMC_RX65TO127OCTETS_GB_LO);
stats->rx128to255octets_gb +=
xlgmac_mmc_read(pdata, MMC_RX128TO255OCTETS_GB_LO);
stats->rx256to511octets_gb +=
xlgmac_mmc_read(pdata, MMC_RX256TO511OCTETS_GB_LO);
stats->rx512to1023octets_gb +=
xlgmac_mmc_read(pdata, MMC_RX512TO1023OCTETS_GB_LO);
stats->rx1024tomaxoctets_gb +=
xlgmac_mmc_read(pdata, MMC_RX1024TOMAXOCTETS_GB_LO);
stats->rxunicastframes_g +=
xlgmac_mmc_read(pdata, MMC_RXUNICASTFRAMES_G_LO);
stats->rxlengtherror +=
xlgmac_mmc_read(pdata, MMC_RXLENGTHERROR_LO);
stats->rxoutofrangetype +=
xlgmac_mmc_read(pdata, MMC_RXOUTOFRANGETYPE_LO);
stats->rxpauseframes +=
xlgmac_mmc_read(pdata, MMC_RXPAUSEFRAMES_LO);
stats->rxfifooverflow +=
xlgmac_mmc_read(pdata, MMC_RXFIFOOVERFLOW_LO);
stats->rxvlanframes_gb +=
xlgmac_mmc_read(pdata, MMC_RXVLANFRAMES_GB_LO);
stats->rxwatchdogerror +=
xlgmac_mmc_read(pdata, MMC_RXWATCHDOGERROR);
regval = readl(pdata->mac_regs + MMC_CR);
regval = XLGMAC_SET_REG_BITS(regval, MMC_CR_MCF_POS,
MMC_CR_MCF_LEN, 0);
writel(regval, pdata->mac_regs + MMC_CR);
}
static void xlgmac_config_mmc(struct xlgmac_pdata *pdata)
{
u32 regval;
regval = readl(pdata->mac_regs + MMC_CR);
regval = XLGMAC_SET_REG_BITS(regval, MMC_CR_ROR_POS,
MMC_CR_ROR_LEN, 1);
regval = XLGMAC_SET_REG_BITS(regval, MMC_CR_CR_POS,
MMC_CR_CR_LEN, 1);
writel(regval, pdata->mac_regs + MMC_CR);
}
static int xlgmac_write_rss_reg(struct xlgmac_pdata *pdata, unsigned int type,
unsigned int index, unsigned int val)
{
unsigned int wait;
int ret = 0;
u32 regval;
mutex_lock(&pdata->rss_mutex);
regval = XLGMAC_GET_REG_BITS(readl(pdata->mac_regs + MAC_RSSAR),
MAC_RSSAR_OB_POS, MAC_RSSAR_OB_LEN);
if (regval) {
ret = -EBUSY;
goto unlock;
}
writel(val, pdata->mac_regs + MAC_RSSDR);
regval = readl(pdata->mac_regs + MAC_RSSAR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_RSSAR_RSSIA_POS,
MAC_RSSAR_RSSIA_LEN, index);
regval = XLGMAC_SET_REG_BITS(regval, MAC_RSSAR_ADDRT_POS,
MAC_RSSAR_ADDRT_LEN, type);
regval = XLGMAC_SET_REG_BITS(regval, MAC_RSSAR_CT_POS,
MAC_RSSAR_CT_LEN, 0);
regval = XLGMAC_SET_REG_BITS(regval, MAC_RSSAR_OB_POS,
MAC_RSSAR_OB_LEN, 1);
writel(regval, pdata->mac_regs + MAC_RSSAR);
wait = 1000;
while (wait--) {
regval = XLGMAC_GET_REG_BITS(readl(pdata->mac_regs + MAC_RSSAR),
MAC_RSSAR_OB_POS,
MAC_RSSAR_OB_LEN);
if (!regval)
goto unlock;
usleep_range(1000, 1500);
}
ret = -EBUSY;
unlock:
mutex_unlock(&pdata->rss_mutex);
return ret;
}
static int xlgmac_write_rss_hash_key(struct xlgmac_pdata *pdata)
{
unsigned int key_regs = sizeof(pdata->rss_key) / sizeof(u32);
unsigned int *key = (unsigned int *)&pdata->rss_key;
int ret;
while (key_regs--) {
ret = xlgmac_write_rss_reg(pdata, XLGMAC_RSS_HASH_KEY_TYPE,
key_regs, *key++);
if (ret)
return ret;
}
return 0;
}
static int xlgmac_write_rss_lookup_table(struct xlgmac_pdata *pdata)
{
unsigned int i;
int ret;
for (i = 0; i < ARRAY_SIZE(pdata->rss_table); i++) {
ret = xlgmac_write_rss_reg(pdata,
XLGMAC_RSS_LOOKUP_TABLE_TYPE, i,
pdata->rss_table[i]);
if (ret)
return ret;
}
return 0;
}
static int xlgmac_set_rss_hash_key(struct xlgmac_pdata *pdata, const u8 *key)
{
memcpy(pdata->rss_key, key, sizeof(pdata->rss_key));
return xlgmac_write_rss_hash_key(pdata);
}
static int xlgmac_set_rss_lookup_table(struct xlgmac_pdata *pdata,
const u32 *table)
{
unsigned int i;
u32 tval;
for (i = 0; i < ARRAY_SIZE(pdata->rss_table); i++) {
tval = table[i];
pdata->rss_table[i] = XLGMAC_SET_REG_BITS(
pdata->rss_table[i],
MAC_RSSDR_DMCH_POS,
MAC_RSSDR_DMCH_LEN,
tval);
}
return xlgmac_write_rss_lookup_table(pdata);
}
static int xlgmac_enable_rss(struct xlgmac_pdata *pdata)
{
u32 regval;
int ret;
if (!pdata->hw_feat.rss)
return -EOPNOTSUPP;
ret = xlgmac_write_rss_hash_key(pdata);
if (ret)
return ret;
ret = xlgmac_write_rss_lookup_table(pdata);
if (ret)
return ret;
writel(pdata->rss_options, pdata->mac_regs + MAC_RSSCR);
regval = readl(pdata->mac_regs + MAC_RSSCR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_RSSCR_RSSE_POS,
MAC_RSSCR_RSSE_LEN, 1);
writel(regval, pdata->mac_regs + MAC_RSSCR);
return 0;
}
static int xlgmac_disable_rss(struct xlgmac_pdata *pdata)
{
u32 regval;
if (!pdata->hw_feat.rss)
return -EOPNOTSUPP;
regval = readl(pdata->mac_regs + MAC_RSSCR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_RSSCR_RSSE_POS,
MAC_RSSCR_RSSE_LEN, 0);
writel(regval, pdata->mac_regs + MAC_RSSCR);
return 0;
}
static void xlgmac_config_rss(struct xlgmac_pdata *pdata)
{
int ret;
if (!pdata->hw_feat.rss)
return;
if (pdata->netdev->features & NETIF_F_RXHASH)
ret = xlgmac_enable_rss(pdata);
else
ret = xlgmac_disable_rss(pdata);
if (ret)
netdev_err(pdata->netdev,
"error configuring RSS, RSS disabled\n");
}
static void xlgmac_enable_dma_interrupts(struct xlgmac_pdata *pdata)
{
unsigned int dma_ch_isr, dma_ch_ier;
struct xlgmac_channel *channel;
unsigned int i;
channel = pdata->channel_head;
for (i = 0; i < pdata->channel_count; i++, channel++) {
dma_ch_isr = readl(XLGMAC_DMA_REG(channel, DMA_CH_SR));
writel(dma_ch_isr, XLGMAC_DMA_REG(channel, DMA_CH_SR));
dma_ch_ier = 0;
dma_ch_ier = XLGMAC_SET_REG_BITS(dma_ch_ier,
DMA_CH_IER_NIE_POS,
DMA_CH_IER_NIE_LEN, 1);
dma_ch_ier = XLGMAC_SET_REG_BITS(dma_ch_ier,
DMA_CH_IER_AIE_POS,
DMA_CH_IER_AIE_LEN, 1);
dma_ch_ier = XLGMAC_SET_REG_BITS(dma_ch_ier,
DMA_CH_IER_FBEE_POS,
DMA_CH_IER_FBEE_LEN, 1);
if (channel->tx_ring) {
if (!pdata->per_channel_irq)
dma_ch_ier = XLGMAC_SET_REG_BITS(
dma_ch_ier,
DMA_CH_IER_TIE_POS,
DMA_CH_IER_TIE_LEN,
1);
}
if (channel->rx_ring) {
dma_ch_ier = XLGMAC_SET_REG_BITS(
dma_ch_ier,
DMA_CH_IER_RBUE_POS,
DMA_CH_IER_RBUE_LEN,
1);
if (!pdata->per_channel_irq)
dma_ch_ier = XLGMAC_SET_REG_BITS(
dma_ch_ier,
DMA_CH_IER_RIE_POS,
DMA_CH_IER_RIE_LEN,
1);
}
writel(dma_ch_isr, XLGMAC_DMA_REG(channel, DMA_CH_IER));
}
}
static void xlgmac_enable_mtl_interrupts(struct xlgmac_pdata *pdata)
{
unsigned int q_count, i;
unsigned int mtl_q_isr;
q_count = max(pdata->hw_feat.tx_q_cnt, pdata->hw_feat.rx_q_cnt);
for (i = 0; i < q_count; i++) {
mtl_q_isr = readl(XLGMAC_MTL_REG(pdata, i, MTL_Q_ISR));
writel(mtl_q_isr, XLGMAC_MTL_REG(pdata, i, MTL_Q_ISR));
writel(0, XLGMAC_MTL_REG(pdata, i, MTL_Q_IER));
}
}
static void xlgmac_enable_mac_interrupts(struct xlgmac_pdata *pdata)
{
unsigned int mac_ier = 0;
u32 regval;
mac_ier = XLGMAC_SET_REG_BITS(mac_ier, MAC_IER_TSIE_POS,
MAC_IER_TSIE_LEN, 1);
writel(mac_ier, pdata->mac_regs + MAC_IER);
regval = readl(pdata->mac_regs + MMC_RIER);
regval = XLGMAC_SET_REG_BITS(regval, MMC_RIER_ALL_INTERRUPTS_POS,
MMC_RIER_ALL_INTERRUPTS_LEN, 0xffffffff);
writel(regval, pdata->mac_regs + MMC_RIER);
regval = readl(pdata->mac_regs + MMC_TIER);
regval = XLGMAC_SET_REG_BITS(regval, MMC_TIER_ALL_INTERRUPTS_POS,
MMC_TIER_ALL_INTERRUPTS_LEN, 0xffffffff);
writel(regval, pdata->mac_regs + MMC_TIER);
}
static int xlgmac_set_xlgmii_25000_speed(struct xlgmac_pdata *pdata)
{
u32 regval;
regval = XLGMAC_GET_REG_BITS(readl(pdata->mac_regs + MAC_TCR),
MAC_TCR_SS_POS, MAC_TCR_SS_LEN);
if (regval == 0x1)
return 0;
regval = readl(pdata->mac_regs + MAC_TCR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_TCR_SS_POS,
MAC_TCR_SS_LEN, 0x1);
writel(regval, pdata->mac_regs + MAC_TCR);
return 0;
}
static int xlgmac_set_xlgmii_40000_speed(struct xlgmac_pdata *pdata)
{
u32 regval;
regval = XLGMAC_GET_REG_BITS(readl(pdata->mac_regs + MAC_TCR),
MAC_TCR_SS_POS, MAC_TCR_SS_LEN);
if (regval == 0)
return 0;
regval = readl(pdata->mac_regs + MAC_TCR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_TCR_SS_POS,
MAC_TCR_SS_LEN, 0);
writel(regval, pdata->mac_regs + MAC_TCR);
return 0;
}
static int xlgmac_set_xlgmii_50000_speed(struct xlgmac_pdata *pdata)
{
u32 regval;
regval = XLGMAC_GET_REG_BITS(readl(pdata->mac_regs + MAC_TCR),
MAC_TCR_SS_POS, MAC_TCR_SS_LEN);
if (regval == 0x2)
return 0;
regval = readl(pdata->mac_regs + MAC_TCR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_TCR_SS_POS,
MAC_TCR_SS_LEN, 0x2);
writel(regval, pdata->mac_regs + MAC_TCR);
return 0;
}
static int xlgmac_set_xlgmii_100000_speed(struct xlgmac_pdata *pdata)
{
u32 regval;
regval = XLGMAC_GET_REG_BITS(readl(pdata->mac_regs + MAC_TCR),
MAC_TCR_SS_POS, MAC_TCR_SS_LEN);
if (regval == 0x3)
return 0;
regval = readl(pdata->mac_regs + MAC_TCR);
regval = XLGMAC_SET_REG_BITS(regval, MAC_TCR_SS_POS,
MAC_TCR_SS_LEN, 0x3);
writel(regval, pdata->mac_regs + MAC_TCR);
return 0;
}
static void xlgmac_config_mac_speed(struct xlgmac_pdata *pdata)
{
switch (pdata->phy_speed) {
case SPEED_100000:
xlgmac_set_xlgmii_100000_speed(pdata);
break;
case SPEED_50000:
xlgmac_set_xlgmii_50000_speed(pdata);
break;
case SPEED_40000:
xlgmac_set_xlgmii_40000_speed(pdata);
break;
case SPEED_25000:
xlgmac_set_xlgmii_25000_speed(pdata);
break;
}
}
static int xlgmac_dev_read(struct xlgmac_channel *channel)
{
struct xlgmac_pdata *pdata = channel->pdata;
struct xlgmac_ring *ring = channel->rx_ring;
struct net_device *netdev = pdata->netdev;
struct xlgmac_desc_data *desc_data;
struct xlgmac_dma_desc *dma_desc;
struct xlgmac_pkt_info *pkt_info;
unsigned int err, etlt, l34t;
desc_data = XLGMAC_GET_DESC_DATA(ring, ring->cur);
dma_desc = desc_data->dma_desc;
pkt_info = &ring->pkt_info;
if (XLGMAC_GET_REG_BITS_LE(dma_desc->desc3,
RX_NORMAL_DESC3_OWN_POS,
RX_NORMAL_DESC3_OWN_LEN))
return 1;
dma_rmb();
if (netif_msg_rx_status(pdata))
xlgmac_dump_rx_desc(pdata, ring, ring->cur);
if (XLGMAC_GET_REG_BITS_LE(dma_desc->desc3,
RX_NORMAL_DESC3_CTXT_POS,
RX_NORMAL_DESC3_CTXT_LEN)) {
xlgmac_get_rx_tstamp(pkt_info, dma_desc);
pkt_info->attributes = XLGMAC_SET_REG_BITS(
pkt_info->attributes,
RX_PACKET_ATTRIBUTES_CONTEXT_POS,
RX_PACKET_ATTRIBUTES_CONTEXT_LEN,
1);
pkt_info->attributes = XLGMAC_SET_REG_BITS(
pkt_info->attributes,
RX_PACKET_ATTRIBUTES_CONTEXT_NEXT_POS,
RX_PACKET_ATTRIBUTES_CONTEXT_NEXT_LEN,
0);
return 0;
}
pkt_info->attributes = XLGMAC_SET_REG_BITS(
pkt_info->attributes,
RX_PACKET_ATTRIBUTES_CONTEXT_POS,
RX_PACKET_ATTRIBUTES_CONTEXT_LEN,
0);
if (XLGMAC_GET_REG_BITS_LE(dma_desc->desc3,
RX_NORMAL_DESC3_CDA_POS,
RX_NORMAL_DESC3_CDA_LEN))
pkt_info->attributes = XLGMAC_SET_REG_BITS(
pkt_info->attributes,
RX_PACKET_ATTRIBUTES_CONTEXT_NEXT_POS,
RX_PACKET_ATTRIBUTES_CONTEXT_NEXT_LEN,
1);
if (XLGMAC_GET_REG_BITS_LE(dma_desc->desc3,
RX_NORMAL_DESC3_FD_POS,
RX_NORMAL_DESC3_FD_LEN)) {
desc_data->rx.hdr_len = XLGMAC_GET_REG_BITS_LE(dma_desc->desc2,
RX_NORMAL_DESC2_HL_POS,
RX_NORMAL_DESC2_HL_LEN);
if (desc_data->rx.hdr_len)
pdata->stats.rx_split_header_packets++;
}
if (XLGMAC_GET_REG_BITS_LE(dma_desc->desc3,
RX_NORMAL_DESC3_RSV_POS,
RX_NORMAL_DESC3_RSV_LEN)) {
pkt_info->attributes = XLGMAC_SET_REG_BITS(
pkt_info->attributes,
RX_PACKET_ATTRIBUTES_RSS_HASH_POS,
RX_PACKET_ATTRIBUTES_RSS_HASH_LEN,
1);
pkt_info->rss_hash = le32_to_cpu(dma_desc->desc1);
l34t = XLGMAC_GET_REG_BITS_LE(dma_desc->desc3,
RX_NORMAL_DESC3_L34T_POS,
RX_NORMAL_DESC3_L34T_LEN);
switch (l34t) {
case RX_DESC3_L34T_IPV4_TCP:
case RX_DESC3_L34T_IPV4_UDP:
case RX_DESC3_L34T_IPV6_TCP:
case RX_DESC3_L34T_IPV6_UDP:
pkt_info->rss_hash_type = PKT_HASH_TYPE_L4;
break;
default:
pkt_info->rss_hash_type = PKT_HASH_TYPE_L3;
}
}
desc_data->rx.len = XLGMAC_GET_REG_BITS_LE(dma_desc->desc3,
RX_NORMAL_DESC3_PL_POS,
RX_NORMAL_DESC3_PL_LEN);
if (!XLGMAC_GET_REG_BITS_LE(dma_desc->desc3,
RX_NORMAL_DESC3_LD_POS,
RX_NORMAL_DESC3_LD_LEN)) {
pkt_info->attributes = XLGMAC_SET_REG_BITS(
pkt_info->attributes,
RX_PACKET_ATTRIBUTES_INCOMPLETE_POS,
RX_PACKET_ATTRIBUTES_INCOMPLETE_LEN,
1);
return 0;
}
pkt_info->attributes = XLGMAC_SET_REG_BITS(
pkt_info->attributes,
RX_PACKET_ATTRIBUTES_INCOMPLETE_POS,
RX_PACKET_ATTRIBUTES_INCOMPLETE_LEN,
0);
if (netdev->features & NETIF_F_RXCSUM)
pkt_info->attributes = XLGMAC_SET_REG_BITS(
pkt_info->attributes,
RX_PACKET_ATTRIBUTES_CSUM_DONE_POS,
RX_PACKET_ATTRIBUTES_CSUM_DONE_LEN,
1);
err = XLGMAC_GET_REG_BITS_LE(dma_desc->desc3,
RX_NORMAL_DESC3_ES_POS,
RX_NORMAL_DESC3_ES_LEN);
etlt = XLGMAC_GET_REG_BITS_LE(dma_desc->desc3,
RX_NORMAL_DESC3_ETLT_POS,
RX_NORMAL_DESC3_ETLT_LEN);
netif_dbg(pdata, rx_status, netdev, "err=%u, etlt=%#x\n", err, etlt);
if (!err || !etlt) {
if ((etlt == 0x09) &&
(netdev->features & NETIF_F_HW_VLAN_CTAG_RX)) {
pkt_info->attributes = XLGMAC_SET_REG_BITS(
pkt_info->attributes,
RX_PACKET_ATTRIBUTES_VLAN_CTAG_POS,
RX_PACKET_ATTRIBUTES_VLAN_CTAG_LEN,
1);
pkt_info->vlan_ctag =
XLGMAC_GET_REG_BITS_LE(dma_desc->desc0,
RX_NORMAL_DESC0_OVT_POS,
RX_NORMAL_DESC0_OVT_LEN);
netif_dbg(pdata, rx_status, netdev, "vlan-ctag=%#06x\n",
pkt_info->vlan_ctag);
}
} else {
if ((etlt == 0x05) || (etlt == 0x06))
pkt_info->attributes = XLGMAC_SET_REG_BITS(
pkt_info->attributes,
RX_PACKET_ATTRIBUTES_CSUM_DONE_POS,
RX_PACKET_ATTRIBUTES_CSUM_DONE_LEN,
0);
else
pkt_info->errors = XLGMAC_SET_REG_BITS(
pkt_info->errors,
RX_PACKET_ERRORS_FRAME_POS,
RX_PACKET_ERRORS_FRAME_LEN,
1);
}
XLGMAC_PR("%s - descriptor=%u (cur=%d)\n", channel->name,
ring->cur & (ring->dma_desc_count - 1), ring->cur);
return 0;
}
static int xlgmac_enable_int(struct xlgmac_channel *channel,
enum xlgmac_int int_id)
{
unsigned int dma_ch_ier;
dma_ch_ier = readl(XLGMAC_DMA_REG(channel, DMA_CH_IER));
switch (int_id) {
case XLGMAC_INT_DMA_CH_SR_TI:
dma_ch_ier = XLGMAC_SET_REG_BITS(
dma_ch_ier, DMA_CH_IER_TIE_POS,
DMA_CH_IER_TIE_LEN, 1);
break;
case XLGMAC_INT_DMA_CH_SR_TPS:
dma_ch_ier = XLGMAC_SET_REG_BITS(
dma_ch_ier, DMA_CH_IER_TXSE_POS,
DMA_CH_IER_TXSE_LEN, 1);
break;
case XLGMAC_INT_DMA_CH_SR_TBU:
dma_ch_ier = XLGMAC_SET_REG_BITS(
dma_ch_ier, DMA_CH_IER_TBUE_POS,
DMA_CH_IER_TBUE_LEN, 1);
break;
case XLGMAC_INT_DMA_CH_SR_RI:
dma_ch_ier = XLGMAC_SET_REG_BITS(
dma_ch_ier, DMA_CH_IER_RIE_POS,
DMA_CH_IER_RIE_LEN, 1);
break;
case XLGMAC_INT_DMA_CH_SR_RBU:
dma_ch_ier = XLGMAC_SET_REG_BITS(
dma_ch_ier, DMA_CH_IER_RBUE_POS,
DMA_CH_IER_RBUE_LEN, 1);
break;
case XLGMAC_INT_DMA_CH_SR_RPS:
dma_ch_ier = XLGMAC_SET_REG_BITS(
dma_ch_ier, DMA_CH_IER_RSE_POS,
DMA_CH_IER_RSE_LEN, 1);
break;
case XLGMAC_INT_DMA_CH_SR_TI_RI:
dma_ch_ier = XLGMAC_SET_REG_BITS(
dma_ch_ier, DMA_CH_IER_TIE_POS,
DMA_CH_IER_TIE_LEN, 1);
dma_ch_ier = XLGMAC_SET_REG_BITS(
dma_ch_ier, DMA_CH_IER_RIE_POS,
DMA_CH_IER_RIE_LEN, 1);
break;
case XLGMAC_INT_DMA_CH_SR_FBE:
dma_ch_ier = XLGMAC_SET_REG_BITS(
dma_ch_ier, DMA_CH_IER_FBEE_POS,
DMA_CH_IER_FBEE_LEN, 1);
break;
case XLGMAC_INT_DMA_ALL:
dma_ch_ier |= channel->saved_ier;
break;
default:
return -1;
}
writel(dma_ch_ier, XLGMAC_DMA_REG(channel, DMA_CH_IER));
return 0;
}
static int xlgmac_disable_int(struct xlgmac_channel *channel,
enum xlgmac_int int_id)
{
unsigned int dma_ch_ier;
dma_ch_ier = readl(XLGMAC_DMA_REG(channel, DMA_CH_IER));
switch (int_id) {
case XLGMAC_INT_DMA_CH_SR_TI:
dma_ch_ier = XLGMAC_SET_REG_BITS(
dma_ch_ier, DMA_CH_IER_TIE_POS,
DMA_CH_IER_TIE_LEN, 0);
break;
case XLGMAC_INT_DMA_CH_SR_TPS:
dma_ch_ier = XLGMAC_SET_REG_BITS(
dma_ch_ier, DMA_CH_IER_TXSE_POS,
DMA_CH_IER_TXSE_LEN, 0);
break;
case XLGMAC_INT_DMA_CH_SR_TBU:
dma_ch_ier = XLGMAC_SET_REG_BITS(
dma_ch_ier, DMA_CH_IER_TBUE_POS,
DMA_CH_IER_TBUE_LEN, 0);
break;
case XLGMAC_INT_DMA_CH_SR_RI:
dma_ch_ier = XLGMAC_SET_REG_BITS(
dma_ch_ier, DMA_CH_IER_RIE_POS,
DMA_CH_IER_RIE_LEN, 0);
break;
case XLGMAC_INT_DMA_CH_SR_RBU:
dma_ch_ier = XLGMAC_SET_REG_BITS(
dma_ch_ier, DMA_CH_IER_RBUE_POS,
DMA_CH_IER_RBUE_LEN, 0);
break;
case XLGMAC_INT_DMA_CH_SR_RPS:
dma_ch_ier = XLGMAC_SET_REG_BITS(
dma_ch_ier, DMA_CH_IER_RSE_POS,
DMA_CH_IER_RSE_LEN, 0);
break;
case XLGMAC_INT_DMA_CH_SR_TI_RI:
dma_ch_ier = XLGMAC_SET_REG_BITS(
dma_ch_ier, DMA_CH_IER_TIE_POS,
DMA_CH_IER_TIE_LEN, 0);
dma_ch_ier = XLGMAC_SET_REG_BITS(
dma_ch_ier, DMA_CH_IER_RIE_POS,
DMA_CH_IER_RIE_LEN, 0);
break;
case XLGMAC_INT_DMA_CH_SR_FBE:
dma_ch_ier = XLGMAC_SET_REG_BITS(
dma_ch_ier, DMA_CH_IER_FBEE_POS,
DMA_CH_IER_FBEE_LEN, 0);
break;
case XLGMAC_INT_DMA_ALL:
channel->saved_ier = dma_ch_ier & XLGMAC_DMA_INTERRUPT_MASK;
dma_ch_ier &= ~XLGMAC_DMA_INTERRUPT_MASK;
break;
default:
return -1;
}
writel(dma_ch_ier, XLGMAC_DMA_REG(channel, DMA_CH_IER));
return 0;
}
static int xlgmac_flush_tx_queues(struct xlgmac_pdata *pdata)
{
unsigned int i, count;
u32 regval;
for (i = 0; i < pdata->tx_q_count; i++) {
regval = readl(XLGMAC_MTL_REG(pdata, i, MTL_Q_TQOMR));
regval = XLGMAC_SET_REG_BITS(regval, MTL_Q_TQOMR_FTQ_POS,
MTL_Q_TQOMR_FTQ_LEN, 1);
writel(regval, XLGMAC_MTL_REG(pdata, i, MTL_Q_TQOMR));
}
for (i = 0; i < pdata->tx_q_count; i++) {
count = 2000;
regval = readl(XLGMAC_MTL_REG(pdata, i, MTL_Q_TQOMR));
regval = XLGMAC_GET_REG_BITS(regval, MTL_Q_TQOMR_FTQ_POS,
MTL_Q_TQOMR_FTQ_LEN);
while (--count && regval)
usleep_range(500, 600);
if (!count)
return -EBUSY;
}
return 0;
}
static void xlgmac_config_dma_bus(struct xlgmac_pdata *pdata)
{
u32 regval;
regval = readl(pdata->mac_regs + DMA_SBMR);
regval = XLGMAC_SET_REG_BITS(regval, DMA_SBMR_EAME_POS,
DMA_SBMR_EAME_LEN, 1);
regval = XLGMAC_SET_REG_BITS(regval, DMA_SBMR_UNDEF_POS,
DMA_SBMR_UNDEF_LEN, 1);
regval = XLGMAC_SET_REG_BITS(regval, DMA_SBMR_BLEN_256_POS,
DMA_SBMR_BLEN_256_LEN, 1);
writel(regval, pdata->mac_regs + DMA_SBMR);
}
static int xlgmac_hw_init(struct xlgmac_pdata *pdata)
{
struct xlgmac_desc_ops *desc_ops = &pdata->desc_ops;
int ret;
ret = xlgmac_flush_tx_queues(pdata);
if (ret)
return ret;
xlgmac_config_dma_bus(pdata);
xlgmac_config_osp_mode(pdata);
xlgmac_config_pblx8(pdata);
xlgmac_config_tx_pbl_val(pdata);
xlgmac_config_rx_pbl_val(pdata);
xlgmac_config_rx_coalesce(pdata);
xlgmac_config_tx_coalesce(pdata);
xlgmac_config_rx_buffer_size(pdata);
xlgmac_config_tso_mode(pdata);
xlgmac_config_sph_mode(pdata);
xlgmac_config_rss(pdata);
desc_ops->tx_desc_init(pdata);
desc_ops->rx_desc_init(pdata);
xlgmac_enable_dma_interrupts(pdata);
xlgmac_config_mtl_mode(pdata);
xlgmac_config_queue_mapping(pdata);
xlgmac_config_tsf_mode(pdata, pdata->tx_sf_mode);
xlgmac_config_rsf_mode(pdata, pdata->rx_sf_mode);
xlgmac_config_tx_threshold(pdata, pdata->tx_threshold);
xlgmac_config_rx_threshold(pdata, pdata->rx_threshold);
xlgmac_config_tx_fifo_size(pdata);
xlgmac_config_rx_fifo_size(pdata);
xlgmac_config_flow_control_threshold(pdata);
xlgmac_config_rx_fep_enable(pdata);
xlgmac_config_rx_fup_enable(pdata);
xlgmac_enable_mtl_interrupts(pdata);
xlgmac_config_mac_address(pdata);
xlgmac_config_rx_mode(pdata);
xlgmac_config_jumbo_enable(pdata);
xlgmac_config_flow_control(pdata);
xlgmac_config_mac_speed(pdata);
xlgmac_config_checksum_offload(pdata);
xlgmac_config_vlan_support(pdata);
xlgmac_config_mmc(pdata);
xlgmac_enable_mac_interrupts(pdata);
return 0;
}
static int xlgmac_hw_exit(struct xlgmac_pdata *pdata)
{
unsigned int count = 2000;
u32 regval;
regval = readl(pdata->mac_regs + DMA_MR);
regval = XLGMAC_SET_REG_BITS(regval, DMA_MR_SWR_POS,
DMA_MR_SWR_LEN, 1);
writel(regval, pdata->mac_regs + DMA_MR);
usleep_range(10, 15);
while (--count &&
XLGMAC_GET_REG_BITS(readl(pdata->mac_regs + DMA_MR),
DMA_MR_SWR_POS, DMA_MR_SWR_LEN))
usleep_range(500, 600);
if (!count)
return -EBUSY;
return 0;
}
void xlgmac_init_hw_ops(struct xlgmac_hw_ops *hw_ops)
{
hw_ops->init = xlgmac_hw_init;
hw_ops->exit = xlgmac_hw_exit;
hw_ops->tx_complete = xlgmac_tx_complete;
hw_ops->enable_tx = xlgmac_enable_tx;
hw_ops->disable_tx = xlgmac_disable_tx;
hw_ops->enable_rx = xlgmac_enable_rx;
hw_ops->disable_rx = xlgmac_disable_rx;
hw_ops->dev_xmit = xlgmac_dev_xmit;
hw_ops->dev_read = xlgmac_dev_read;
hw_ops->enable_int = xlgmac_enable_int;
hw_ops->disable_int = xlgmac_disable_int;
hw_ops->set_mac_address = xlgmac_set_mac_address;
hw_ops->config_rx_mode = xlgmac_config_rx_mode;
hw_ops->enable_rx_csum = xlgmac_enable_rx_csum;
hw_ops->disable_rx_csum = xlgmac_disable_rx_csum;
hw_ops->set_xlgmii_25000_speed = xlgmac_set_xlgmii_25000_speed;
hw_ops->set_xlgmii_40000_speed = xlgmac_set_xlgmii_40000_speed;
hw_ops->set_xlgmii_50000_speed = xlgmac_set_xlgmii_50000_speed;
hw_ops->set_xlgmii_100000_speed = xlgmac_set_xlgmii_100000_speed;
hw_ops->tx_desc_init = xlgmac_tx_desc_init;
hw_ops->rx_desc_init = xlgmac_rx_desc_init;
hw_ops->tx_desc_reset = xlgmac_tx_desc_reset;
hw_ops->rx_desc_reset = xlgmac_rx_desc_reset;
hw_ops->is_last_desc = xlgmac_is_last_desc;
hw_ops->is_context_desc = xlgmac_is_context_desc;
hw_ops->tx_start_xmit = xlgmac_tx_start_xmit;
hw_ops->config_tx_flow_control = xlgmac_config_tx_flow_control;
hw_ops->config_rx_flow_control = xlgmac_config_rx_flow_control;
hw_ops->enable_rx_vlan_stripping = xlgmac_enable_rx_vlan_stripping;
hw_ops->disable_rx_vlan_stripping = xlgmac_disable_rx_vlan_stripping;
hw_ops->enable_rx_vlan_filtering = xlgmac_enable_rx_vlan_filtering;
hw_ops->disable_rx_vlan_filtering = xlgmac_disable_rx_vlan_filtering;
hw_ops->update_vlan_hash_table = xlgmac_update_vlan_hash_table;
hw_ops->config_rx_coalesce = xlgmac_config_rx_coalesce;
hw_ops->config_tx_coalesce = xlgmac_config_tx_coalesce;
hw_ops->usec_to_riwt = xlgmac_usec_to_riwt;
hw_ops->riwt_to_usec = xlgmac_riwt_to_usec;
hw_ops->config_rx_threshold = xlgmac_config_rx_threshold;
hw_ops->config_tx_threshold = xlgmac_config_tx_threshold;
hw_ops->config_rsf_mode = xlgmac_config_rsf_mode;
hw_ops->config_tsf_mode = xlgmac_config_tsf_mode;
hw_ops->config_osp_mode = xlgmac_config_osp_mode;
hw_ops->config_rx_pbl_val = xlgmac_config_rx_pbl_val;
hw_ops->get_rx_pbl_val = xlgmac_get_rx_pbl_val;
hw_ops->config_tx_pbl_val = xlgmac_config_tx_pbl_val;
hw_ops->get_tx_pbl_val = xlgmac_get_tx_pbl_val;
hw_ops->config_pblx8 = xlgmac_config_pblx8;
hw_ops->tx_mmc_int = xlgmac_tx_mmc_int;
hw_ops->rx_mmc_int = xlgmac_rx_mmc_int;
hw_ops->read_mmc_stats = xlgmac_read_mmc_stats;
hw_ops->enable_rss = xlgmac_enable_rss;
hw_ops->disable_rss = xlgmac_disable_rss;
hw_ops->set_rss_hash_key = xlgmac_set_rss_hash_key;
hw_ops->set_rss_lookup_table = xlgmac_set_rss_lookup_table;
}
