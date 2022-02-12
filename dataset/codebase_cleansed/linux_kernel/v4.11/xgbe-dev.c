static inline unsigned int xgbe_get_max_frame(struct xgbe_prv_data *pdata)
{
return pdata->netdev->mtu + ETH_HLEN + ETH_FCS_LEN + VLAN_HLEN;
}
static unsigned int xgbe_usec_to_riwt(struct xgbe_prv_data *pdata,
unsigned int usec)
{
unsigned long rate;
unsigned int ret;
DBGPR("-->xgbe_usec_to_riwt\n");
rate = pdata->sysclk_rate;
ret = (usec * (rate / 1000000)) / 256;
DBGPR("<--xgbe_usec_to_riwt\n");
return ret;
}
static unsigned int xgbe_riwt_to_usec(struct xgbe_prv_data *pdata,
unsigned int riwt)
{
unsigned long rate;
unsigned int ret;
DBGPR("-->xgbe_riwt_to_usec\n");
rate = pdata->sysclk_rate;
ret = (riwt * 256) / (rate / 1000000);
DBGPR("<--xgbe_riwt_to_usec\n");
return ret;
}
static int xgbe_config_pblx8(struct xgbe_prv_data *pdata)
{
struct xgbe_channel *channel;
unsigned int i;
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++)
XGMAC_DMA_IOWRITE_BITS(channel, DMA_CH_CR, PBLX8,
pdata->pblx8);
return 0;
}
static int xgbe_get_tx_pbl_val(struct xgbe_prv_data *pdata)
{
return XGMAC_DMA_IOREAD_BITS(pdata->channel, DMA_CH_TCR, PBL);
}
static int xgbe_config_tx_pbl_val(struct xgbe_prv_data *pdata)
{
struct xgbe_channel *channel;
unsigned int i;
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->tx_ring)
break;
XGMAC_DMA_IOWRITE_BITS(channel, DMA_CH_TCR, PBL,
pdata->tx_pbl);
}
return 0;
}
static int xgbe_get_rx_pbl_val(struct xgbe_prv_data *pdata)
{
return XGMAC_DMA_IOREAD_BITS(pdata->channel, DMA_CH_RCR, PBL);
}
static int xgbe_config_rx_pbl_val(struct xgbe_prv_data *pdata)
{
struct xgbe_channel *channel;
unsigned int i;
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->rx_ring)
break;
XGMAC_DMA_IOWRITE_BITS(channel, DMA_CH_RCR, PBL,
pdata->rx_pbl);
}
return 0;
}
static int xgbe_config_osp_mode(struct xgbe_prv_data *pdata)
{
struct xgbe_channel *channel;
unsigned int i;
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->tx_ring)
break;
XGMAC_DMA_IOWRITE_BITS(channel, DMA_CH_TCR, OSP,
pdata->tx_osp_mode);
}
return 0;
}
static int xgbe_config_rsf_mode(struct xgbe_prv_data *pdata, unsigned int val)
{
unsigned int i;
for (i = 0; i < pdata->rx_q_count; i++)
XGMAC_MTL_IOWRITE_BITS(pdata, i, MTL_Q_RQOMR, RSF, val);
return 0;
}
static int xgbe_config_tsf_mode(struct xgbe_prv_data *pdata, unsigned int val)
{
unsigned int i;
for (i = 0; i < pdata->tx_q_count; i++)
XGMAC_MTL_IOWRITE_BITS(pdata, i, MTL_Q_TQOMR, TSF, val);
return 0;
}
static int xgbe_config_rx_threshold(struct xgbe_prv_data *pdata,
unsigned int val)
{
unsigned int i;
for (i = 0; i < pdata->rx_q_count; i++)
XGMAC_MTL_IOWRITE_BITS(pdata, i, MTL_Q_RQOMR, RTC, val);
return 0;
}
static int xgbe_config_tx_threshold(struct xgbe_prv_data *pdata,
unsigned int val)
{
unsigned int i;
for (i = 0; i < pdata->tx_q_count; i++)
XGMAC_MTL_IOWRITE_BITS(pdata, i, MTL_Q_TQOMR, TTC, val);
return 0;
}
static int xgbe_config_rx_coalesce(struct xgbe_prv_data *pdata)
{
struct xgbe_channel *channel;
unsigned int i;
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->rx_ring)
break;
XGMAC_DMA_IOWRITE_BITS(channel, DMA_CH_RIWT, RWT,
pdata->rx_riwt);
}
return 0;
}
static int xgbe_config_tx_coalesce(struct xgbe_prv_data *pdata)
{
return 0;
}
static void xgbe_config_rx_buffer_size(struct xgbe_prv_data *pdata)
{
struct xgbe_channel *channel;
unsigned int i;
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->rx_ring)
break;
XGMAC_DMA_IOWRITE_BITS(channel, DMA_CH_RCR, RBSZ,
pdata->rx_buf_size);
}
}
static void xgbe_config_tso_mode(struct xgbe_prv_data *pdata)
{
struct xgbe_channel *channel;
unsigned int i;
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->tx_ring)
break;
XGMAC_DMA_IOWRITE_BITS(channel, DMA_CH_TCR, TSE, 1);
}
}
static void xgbe_config_sph_mode(struct xgbe_prv_data *pdata)
{
struct xgbe_channel *channel;
unsigned int i;
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->rx_ring)
break;
XGMAC_DMA_IOWRITE_BITS(channel, DMA_CH_CR, SPH, 1);
}
XGMAC_IOWRITE_BITS(pdata, MAC_RCR, HDSMS, XGBE_SPH_HDSMS_SIZE);
}
static int xgbe_write_rss_reg(struct xgbe_prv_data *pdata, unsigned int type,
unsigned int index, unsigned int val)
{
unsigned int wait;
int ret = 0;
mutex_lock(&pdata->rss_mutex);
if (XGMAC_IOREAD_BITS(pdata, MAC_RSSAR, OB)) {
ret = -EBUSY;
goto unlock;
}
XGMAC_IOWRITE(pdata, MAC_RSSDR, val);
XGMAC_IOWRITE_BITS(pdata, MAC_RSSAR, RSSIA, index);
XGMAC_IOWRITE_BITS(pdata, MAC_RSSAR, ADDRT, type);
XGMAC_IOWRITE_BITS(pdata, MAC_RSSAR, CT, 0);
XGMAC_IOWRITE_BITS(pdata, MAC_RSSAR, OB, 1);
wait = 1000;
while (wait--) {
if (!XGMAC_IOREAD_BITS(pdata, MAC_RSSAR, OB))
goto unlock;
usleep_range(1000, 1500);
}
ret = -EBUSY;
unlock:
mutex_unlock(&pdata->rss_mutex);
return ret;
}
static int xgbe_write_rss_hash_key(struct xgbe_prv_data *pdata)
{
unsigned int key_regs = sizeof(pdata->rss_key) / sizeof(u32);
unsigned int *key = (unsigned int *)&pdata->rss_key;
int ret;
while (key_regs--) {
ret = xgbe_write_rss_reg(pdata, XGBE_RSS_HASH_KEY_TYPE,
key_regs, *key++);
if (ret)
return ret;
}
return 0;
}
static int xgbe_write_rss_lookup_table(struct xgbe_prv_data *pdata)
{
unsigned int i;
int ret;
for (i = 0; i < ARRAY_SIZE(pdata->rss_table); i++) {
ret = xgbe_write_rss_reg(pdata,
XGBE_RSS_LOOKUP_TABLE_TYPE, i,
pdata->rss_table[i]);
if (ret)
return ret;
}
return 0;
}
static int xgbe_set_rss_hash_key(struct xgbe_prv_data *pdata, const u8 *key)
{
memcpy(pdata->rss_key, key, sizeof(pdata->rss_key));
return xgbe_write_rss_hash_key(pdata);
}
static int xgbe_set_rss_lookup_table(struct xgbe_prv_data *pdata,
const u32 *table)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(pdata->rss_table); i++)
XGMAC_SET_BITS(pdata->rss_table[i], MAC_RSSDR, DMCH, table[i]);
return xgbe_write_rss_lookup_table(pdata);
}
static int xgbe_enable_rss(struct xgbe_prv_data *pdata)
{
int ret;
if (!pdata->hw_feat.rss)
return -EOPNOTSUPP;
ret = xgbe_write_rss_hash_key(pdata);
if (ret)
return ret;
ret = xgbe_write_rss_lookup_table(pdata);
if (ret)
return ret;
XGMAC_IOWRITE(pdata, MAC_RSSCR, pdata->rss_options);
XGMAC_IOWRITE_BITS(pdata, MAC_RSSCR, RSSE, 1);
return 0;
}
static int xgbe_disable_rss(struct xgbe_prv_data *pdata)
{
if (!pdata->hw_feat.rss)
return -EOPNOTSUPP;
XGMAC_IOWRITE_BITS(pdata, MAC_RSSCR, RSSE, 0);
return 0;
}
static void xgbe_config_rss(struct xgbe_prv_data *pdata)
{
int ret;
if (!pdata->hw_feat.rss)
return;
if (pdata->netdev->features & NETIF_F_RXHASH)
ret = xgbe_enable_rss(pdata);
else
ret = xgbe_disable_rss(pdata);
if (ret)
netdev_err(pdata->netdev,
"error configuring RSS, RSS disabled\n");
}
static bool xgbe_is_pfc_queue(struct xgbe_prv_data *pdata,
unsigned int queue)
{
unsigned int prio, tc;
for (prio = 0; prio < IEEE_8021QAZ_MAX_TCS; prio++) {
if (pdata->prio2q_map[prio] != queue)
continue;
tc = pdata->ets->prio_tc[prio];
if (pdata->pfc->pfc_en & (1 << tc))
return true;
}
return false;
}
static int xgbe_disable_tx_flow_control(struct xgbe_prv_data *pdata)
{
unsigned int max_q_count, q_count;
unsigned int reg, reg_val;
unsigned int i;
for (i = 0; i < pdata->rx_q_count; i++)
XGMAC_MTL_IOWRITE_BITS(pdata, i, MTL_Q_RQOMR, EHFC, 0);
max_q_count = XGMAC_MAX_FLOW_CONTROL_QUEUES;
q_count = min_t(unsigned int, pdata->tx_q_count, max_q_count);
reg = MAC_Q0TFCR;
for (i = 0; i < q_count; i++) {
reg_val = XGMAC_IOREAD(pdata, reg);
XGMAC_SET_BITS(reg_val, MAC_Q0TFCR, TFE, 0);
XGMAC_IOWRITE(pdata, reg, reg_val);
reg += MAC_QTFCR_INC;
}
return 0;
}
static int xgbe_enable_tx_flow_control(struct xgbe_prv_data *pdata)
{
struct ieee_pfc *pfc = pdata->pfc;
struct ieee_ets *ets = pdata->ets;
unsigned int max_q_count, q_count;
unsigned int reg, reg_val;
unsigned int i;
for (i = 0; i < pdata->rx_q_count; i++) {
unsigned int ehfc = 0;
if (pdata->rx_rfd[i]) {
if (pfc && ets) {
if (xgbe_is_pfc_queue(pdata, i))
ehfc = 1;
} else {
ehfc = 1;
}
}
XGMAC_MTL_IOWRITE_BITS(pdata, i, MTL_Q_RQOMR, EHFC, ehfc);
netif_dbg(pdata, drv, pdata->netdev,
"flow control %s for RXq%u\n",
ehfc ? "enabled" : "disabled", i);
}
max_q_count = XGMAC_MAX_FLOW_CONTROL_QUEUES;
q_count = min_t(unsigned int, pdata->tx_q_count, max_q_count);
reg = MAC_Q0TFCR;
for (i = 0; i < q_count; i++) {
reg_val = XGMAC_IOREAD(pdata, reg);
XGMAC_SET_BITS(reg_val, MAC_Q0TFCR, TFE, 1);
XGMAC_SET_BITS(reg_val, MAC_Q0TFCR, PT, 0xffff);
XGMAC_IOWRITE(pdata, reg, reg_val);
reg += MAC_QTFCR_INC;
}
return 0;
}
static int xgbe_disable_rx_flow_control(struct xgbe_prv_data *pdata)
{
XGMAC_IOWRITE_BITS(pdata, MAC_RFCR, RFE, 0);
return 0;
}
static int xgbe_enable_rx_flow_control(struct xgbe_prv_data *pdata)
{
XGMAC_IOWRITE_BITS(pdata, MAC_RFCR, RFE, 1);
return 0;
}
static int xgbe_config_tx_flow_control(struct xgbe_prv_data *pdata)
{
struct ieee_pfc *pfc = pdata->pfc;
if (pdata->tx_pause || (pfc && pfc->pfc_en))
xgbe_enable_tx_flow_control(pdata);
else
xgbe_disable_tx_flow_control(pdata);
return 0;
}
static int xgbe_config_rx_flow_control(struct xgbe_prv_data *pdata)
{
struct ieee_pfc *pfc = pdata->pfc;
if (pdata->rx_pause || (pfc && pfc->pfc_en))
xgbe_enable_rx_flow_control(pdata);
else
xgbe_disable_rx_flow_control(pdata);
return 0;
}
static void xgbe_config_flow_control(struct xgbe_prv_data *pdata)
{
struct ieee_pfc *pfc = pdata->pfc;
xgbe_config_tx_flow_control(pdata);
xgbe_config_rx_flow_control(pdata);
XGMAC_IOWRITE_BITS(pdata, MAC_RFCR, PFCE,
(pfc && pfc->pfc_en) ? 1 : 0);
}
static void xgbe_enable_dma_interrupts(struct xgbe_prv_data *pdata)
{
struct xgbe_channel *channel;
unsigned int dma_ch_isr, dma_ch_ier;
unsigned int i;
if (pdata->channel_irq_mode)
XGMAC_IOWRITE_BITS(pdata, DMA_MR, INTM,
pdata->channel_irq_mode);
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++) {
dma_ch_isr = XGMAC_DMA_IOREAD(channel, DMA_CH_SR);
XGMAC_DMA_IOWRITE(channel, DMA_CH_SR, dma_ch_isr);
dma_ch_ier = 0;
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, NIE, 1);
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, AIE, 1);
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, FBEE, 1);
if (channel->tx_ring) {
if (!pdata->per_channel_irq || pdata->channel_irq_mode)
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, TIE, 1);
}
if (channel->rx_ring) {
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, RBUE, 1);
if (!pdata->per_channel_irq || pdata->channel_irq_mode)
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, RIE, 1);
}
XGMAC_DMA_IOWRITE(channel, DMA_CH_IER, dma_ch_ier);
}
}
static void xgbe_enable_mtl_interrupts(struct xgbe_prv_data *pdata)
{
unsigned int mtl_q_isr;
unsigned int q_count, i;
q_count = max(pdata->hw_feat.tx_q_cnt, pdata->hw_feat.rx_q_cnt);
for (i = 0; i < q_count; i++) {
mtl_q_isr = XGMAC_MTL_IOREAD(pdata, i, MTL_Q_ISR);
XGMAC_MTL_IOWRITE(pdata, i, MTL_Q_ISR, mtl_q_isr);
XGMAC_MTL_IOWRITE(pdata, i, MTL_Q_IER, 0);
}
}
static void xgbe_enable_mac_interrupts(struct xgbe_prv_data *pdata)
{
unsigned int mac_ier = 0;
XGMAC_SET_BITS(mac_ier, MAC_IER, TSIE, 1);
XGMAC_IOWRITE(pdata, MAC_IER, mac_ier);
XGMAC_IOWRITE_BITS(pdata, MMC_RIER, ALL_INTERRUPTS, 0xffffffff);
XGMAC_IOWRITE_BITS(pdata, MMC_TIER, ALL_INTERRUPTS, 0xffffffff);
XGMAC_IOWRITE_BITS(pdata, MAC_MDIOIER, SNGLCOMPIE, 1);
}
static void xgbe_enable_ecc_interrupts(struct xgbe_prv_data *pdata)
{
unsigned int ecc_isr, ecc_ier = 0;
if (!pdata->vdata->ecc_support)
return;
ecc_isr = XP_IOREAD(pdata, XP_ECC_ISR);
XP_IOWRITE(pdata, XP_ECC_ISR, ecc_isr);
XP_SET_BITS(ecc_ier, XP_ECC_IER, TX_DED, 1);
XP_SET_BITS(ecc_ier, XP_ECC_IER, TX_SEC, 1);
XP_SET_BITS(ecc_ier, XP_ECC_IER, RX_DED, 1);
XP_SET_BITS(ecc_ier, XP_ECC_IER, RX_SEC, 1);
XP_SET_BITS(ecc_ier, XP_ECC_IER, DESC_DED, 1);
XP_SET_BITS(ecc_ier, XP_ECC_IER, DESC_SEC, 1);
XP_IOWRITE(pdata, XP_ECC_IER, ecc_ier);
}
static void xgbe_disable_ecc_ded(struct xgbe_prv_data *pdata)
{
unsigned int ecc_ier;
ecc_ier = XP_IOREAD(pdata, XP_ECC_IER);
XP_SET_BITS(ecc_ier, XP_ECC_IER, TX_DED, 0);
XP_SET_BITS(ecc_ier, XP_ECC_IER, RX_DED, 0);
XP_SET_BITS(ecc_ier, XP_ECC_IER, DESC_DED, 0);
XP_IOWRITE(pdata, XP_ECC_IER, ecc_ier);
}
static void xgbe_disable_ecc_sec(struct xgbe_prv_data *pdata,
enum xgbe_ecc_sec sec)
{
unsigned int ecc_ier;
ecc_ier = XP_IOREAD(pdata, XP_ECC_IER);
switch (sec) {
case XGBE_ECC_SEC_TX:
XP_SET_BITS(ecc_ier, XP_ECC_IER, TX_SEC, 0);
break;
case XGBE_ECC_SEC_RX:
XP_SET_BITS(ecc_ier, XP_ECC_IER, RX_SEC, 0);
break;
case XGBE_ECC_SEC_DESC:
XP_SET_BITS(ecc_ier, XP_ECC_IER, DESC_SEC, 0);
break;
}
XP_IOWRITE(pdata, XP_ECC_IER, ecc_ier);
}
static int xgbe_set_speed(struct xgbe_prv_data *pdata, int speed)
{
unsigned int ss;
switch (speed) {
case SPEED_1000:
ss = 0x03;
break;
case SPEED_2500:
ss = 0x02;
break;
case SPEED_10000:
ss = 0x00;
break;
default:
return -EINVAL;
}
if (XGMAC_IOREAD_BITS(pdata, MAC_TCR, SS) != ss)
XGMAC_IOWRITE_BITS(pdata, MAC_TCR, SS, ss);
return 0;
}
static int xgbe_enable_rx_vlan_stripping(struct xgbe_prv_data *pdata)
{
XGMAC_IOWRITE_BITS(pdata, MAC_VLANTR, EVLRXS, 1);
XGMAC_IOWRITE_BITS(pdata, MAC_VLANTR, DOVLTC, 1);
XGMAC_IOWRITE_BITS(pdata, MAC_VLANTR, ERSVLM, 0);
XGMAC_IOWRITE_BITS(pdata, MAC_VLANTR, ESVL, 0);
XGMAC_IOWRITE_BITS(pdata, MAC_VLANTR, EVLS, 0x3);
return 0;
}
static int xgbe_disable_rx_vlan_stripping(struct xgbe_prv_data *pdata)
{
XGMAC_IOWRITE_BITS(pdata, MAC_VLANTR, EVLS, 0);
return 0;
}
static int xgbe_enable_rx_vlan_filtering(struct xgbe_prv_data *pdata)
{
XGMAC_IOWRITE_BITS(pdata, MAC_PFR, VTFE, 1);
XGMAC_IOWRITE_BITS(pdata, MAC_VLANTR, VTHM, 1);
XGMAC_IOWRITE_BITS(pdata, MAC_VLANTR, VTIM, 0);
XGMAC_IOWRITE_BITS(pdata, MAC_VLANTR, ETV, 1);
XGMAC_IOWRITE_BITS(pdata, MAC_VLANTR, VL, 1);
return 0;
}
static int xgbe_disable_rx_vlan_filtering(struct xgbe_prv_data *pdata)
{
XGMAC_IOWRITE_BITS(pdata, MAC_PFR, VTFE, 0);
return 0;
}
static u32 xgbe_vid_crc32_le(__le16 vid_le)
{
u32 poly = 0xedb88320;
u32 crc = ~0;
u32 temp = 0;
unsigned char *data = (unsigned char *)&vid_le;
unsigned char data_byte = 0;
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
static int xgbe_update_vlan_hash_table(struct xgbe_prv_data *pdata)
{
u32 crc;
u16 vid;
__le16 vid_le;
u16 vlan_hash_table = 0;
for_each_set_bit(vid, pdata->active_vlans, VLAN_N_VID) {
vid_le = cpu_to_le16(vid);
crc = bitrev32(~xgbe_vid_crc32_le(vid_le)) >> 28;
vlan_hash_table |= (1 << crc);
}
XGMAC_IOWRITE_BITS(pdata, MAC_VLANHTR, VLHT, vlan_hash_table);
return 0;
}
static int xgbe_set_promiscuous_mode(struct xgbe_prv_data *pdata,
unsigned int enable)
{
unsigned int val = enable ? 1 : 0;
if (XGMAC_IOREAD_BITS(pdata, MAC_PFR, PR) == val)
return 0;
netif_dbg(pdata, drv, pdata->netdev, "%s promiscuous mode\n",
enable ? "entering" : "leaving");
XGMAC_IOWRITE_BITS(pdata, MAC_PFR, PR, val);
if (enable) {
xgbe_disable_rx_vlan_filtering(pdata);
} else {
if (pdata->netdev->features & NETIF_F_HW_VLAN_CTAG_FILTER)
xgbe_enable_rx_vlan_filtering(pdata);
}
return 0;
}
static int xgbe_set_all_multicast_mode(struct xgbe_prv_data *pdata,
unsigned int enable)
{
unsigned int val = enable ? 1 : 0;
if (XGMAC_IOREAD_BITS(pdata, MAC_PFR, PM) == val)
return 0;
netif_dbg(pdata, drv, pdata->netdev, "%s allmulti mode\n",
enable ? "entering" : "leaving");
XGMAC_IOWRITE_BITS(pdata, MAC_PFR, PM, val);
return 0;
}
static void xgbe_set_mac_reg(struct xgbe_prv_data *pdata,
struct netdev_hw_addr *ha, unsigned int *mac_reg)
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
XGMAC_SET_BITS(mac_addr_hi, MAC_MACA1HR, AE, 1);
}
XGMAC_IOWRITE(pdata, *mac_reg, mac_addr_hi);
*mac_reg += MAC_MACA_INC;
XGMAC_IOWRITE(pdata, *mac_reg, mac_addr_lo);
*mac_reg += MAC_MACA_INC;
}
static void xgbe_set_mac_addn_addrs(struct xgbe_prv_data *pdata)
{
struct net_device *netdev = pdata->netdev;
struct netdev_hw_addr *ha;
unsigned int mac_reg;
unsigned int addn_macs;
mac_reg = MAC_MACA1HR;
addn_macs = pdata->hw_feat.addn_mac;
if (netdev_uc_count(netdev) > addn_macs) {
xgbe_set_promiscuous_mode(pdata, 1);
} else {
netdev_for_each_uc_addr(ha, netdev) {
xgbe_set_mac_reg(pdata, ha, &mac_reg);
addn_macs--;
}
if (netdev_mc_count(netdev) > addn_macs) {
xgbe_set_all_multicast_mode(pdata, 1);
} else {
netdev_for_each_mc_addr(ha, netdev) {
xgbe_set_mac_reg(pdata, ha, &mac_reg);
addn_macs--;
}
}
}
while (addn_macs--)
xgbe_set_mac_reg(pdata, NULL, &mac_reg);
}
static void xgbe_set_mac_hash_table(struct xgbe_prv_data *pdata)
{
struct net_device *netdev = pdata->netdev;
struct netdev_hw_addr *ha;
unsigned int hash_reg;
unsigned int hash_table_shift, hash_table_count;
u32 hash_table[XGBE_MAC_HASH_TABLE_SIZE];
u32 crc;
unsigned int i;
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
XGMAC_IOWRITE(pdata, hash_reg, hash_table[i]);
hash_reg += MAC_HTR_INC;
}
}
static int xgbe_add_mac_addresses(struct xgbe_prv_data *pdata)
{
if (pdata->hw_feat.hash_table_size)
xgbe_set_mac_hash_table(pdata);
else
xgbe_set_mac_addn_addrs(pdata);
return 0;
}
static int xgbe_set_mac_address(struct xgbe_prv_data *pdata, u8 *addr)
{
unsigned int mac_addr_hi, mac_addr_lo;
mac_addr_hi = (addr[5] << 8) | (addr[4] << 0);
mac_addr_lo = (addr[3] << 24) | (addr[2] << 16) |
(addr[1] << 8) | (addr[0] << 0);
XGMAC_IOWRITE(pdata, MAC_MACA0HR, mac_addr_hi);
XGMAC_IOWRITE(pdata, MAC_MACA0LR, mac_addr_lo);
return 0;
}
static int xgbe_config_rx_mode(struct xgbe_prv_data *pdata)
{
struct net_device *netdev = pdata->netdev;
unsigned int pr_mode, am_mode;
pr_mode = ((netdev->flags & IFF_PROMISC) != 0);
am_mode = ((netdev->flags & IFF_ALLMULTI) != 0);
xgbe_set_promiscuous_mode(pdata, pr_mode);
xgbe_set_all_multicast_mode(pdata, am_mode);
xgbe_add_mac_addresses(pdata);
return 0;
}
static int xgbe_clr_gpio(struct xgbe_prv_data *pdata, unsigned int gpio)
{
unsigned int reg;
if (gpio > 15)
return -EINVAL;
reg = XGMAC_IOREAD(pdata, MAC_GPIOSR);
reg &= ~(1 << (gpio + 16));
XGMAC_IOWRITE(pdata, MAC_GPIOSR, reg);
return 0;
}
static int xgbe_set_gpio(struct xgbe_prv_data *pdata, unsigned int gpio)
{
unsigned int reg;
if (gpio > 15)
return -EINVAL;
reg = XGMAC_IOREAD(pdata, MAC_GPIOSR);
reg |= (1 << (gpio + 16));
XGMAC_IOWRITE(pdata, MAC_GPIOSR, reg);
return 0;
}
static int xgbe_read_mmd_regs_v2(struct xgbe_prv_data *pdata, int prtad,
int mmd_reg)
{
unsigned long flags;
unsigned int mmd_address, index, offset;
int mmd_data;
if (mmd_reg & MII_ADDR_C45)
mmd_address = mmd_reg & ~MII_ADDR_C45;
else
mmd_address = (pdata->mdio_mmd << 16) | (mmd_reg & 0xffff);
mmd_address <<= 1;
index = mmd_address & ~pdata->xpcs_window_mask;
offset = pdata->xpcs_window + (mmd_address & pdata->xpcs_window_mask);
spin_lock_irqsave(&pdata->xpcs_lock, flags);
XPCS32_IOWRITE(pdata, pdata->xpcs_window_sel_reg, index);
mmd_data = XPCS16_IOREAD(pdata, offset);
spin_unlock_irqrestore(&pdata->xpcs_lock, flags);
return mmd_data;
}
static void xgbe_write_mmd_regs_v2(struct xgbe_prv_data *pdata, int prtad,
int mmd_reg, int mmd_data)
{
unsigned long flags;
unsigned int mmd_address, index, offset;
if (mmd_reg & MII_ADDR_C45)
mmd_address = mmd_reg & ~MII_ADDR_C45;
else
mmd_address = (pdata->mdio_mmd << 16) | (mmd_reg & 0xffff);
mmd_address <<= 1;
index = mmd_address & ~pdata->xpcs_window_mask;
offset = pdata->xpcs_window + (mmd_address & pdata->xpcs_window_mask);
spin_lock_irqsave(&pdata->xpcs_lock, flags);
XPCS32_IOWRITE(pdata, pdata->xpcs_window_sel_reg, index);
XPCS16_IOWRITE(pdata, offset, mmd_data);
spin_unlock_irqrestore(&pdata->xpcs_lock, flags);
}
static int xgbe_read_mmd_regs_v1(struct xgbe_prv_data *pdata, int prtad,
int mmd_reg)
{
unsigned long flags;
unsigned int mmd_address;
int mmd_data;
if (mmd_reg & MII_ADDR_C45)
mmd_address = mmd_reg & ~MII_ADDR_C45;
else
mmd_address = (pdata->mdio_mmd << 16) | (mmd_reg & 0xffff);
spin_lock_irqsave(&pdata->xpcs_lock, flags);
XPCS32_IOWRITE(pdata, PCS_V1_WINDOW_SELECT, mmd_address >> 8);
mmd_data = XPCS32_IOREAD(pdata, (mmd_address & 0xff) << 2);
spin_unlock_irqrestore(&pdata->xpcs_lock, flags);
return mmd_data;
}
static void xgbe_write_mmd_regs_v1(struct xgbe_prv_data *pdata, int prtad,
int mmd_reg, int mmd_data)
{
unsigned int mmd_address;
unsigned long flags;
if (mmd_reg & MII_ADDR_C45)
mmd_address = mmd_reg & ~MII_ADDR_C45;
else
mmd_address = (pdata->mdio_mmd << 16) | (mmd_reg & 0xffff);
spin_lock_irqsave(&pdata->xpcs_lock, flags);
XPCS32_IOWRITE(pdata, PCS_V1_WINDOW_SELECT, mmd_address >> 8);
XPCS32_IOWRITE(pdata, (mmd_address & 0xff) << 2, mmd_data);
spin_unlock_irqrestore(&pdata->xpcs_lock, flags);
}
static int xgbe_read_mmd_regs(struct xgbe_prv_data *pdata, int prtad,
int mmd_reg)
{
switch (pdata->vdata->xpcs_access) {
case XGBE_XPCS_ACCESS_V1:
return xgbe_read_mmd_regs_v1(pdata, prtad, mmd_reg);
case XGBE_XPCS_ACCESS_V2:
default:
return xgbe_read_mmd_regs_v2(pdata, prtad, mmd_reg);
}
}
static void xgbe_write_mmd_regs(struct xgbe_prv_data *pdata, int prtad,
int mmd_reg, int mmd_data)
{
switch (pdata->vdata->xpcs_access) {
case XGBE_XPCS_ACCESS_V1:
return xgbe_write_mmd_regs_v1(pdata, prtad, mmd_reg, mmd_data);
case XGBE_XPCS_ACCESS_V2:
default:
return xgbe_write_mmd_regs_v2(pdata, prtad, mmd_reg, mmd_data);
}
}
static int xgbe_write_ext_mii_regs(struct xgbe_prv_data *pdata, int addr,
int reg, u16 val)
{
unsigned int mdio_sca, mdio_sccd;
reinit_completion(&pdata->mdio_complete);
mdio_sca = 0;
XGMAC_SET_BITS(mdio_sca, MAC_MDIOSCAR, REG, reg);
XGMAC_SET_BITS(mdio_sca, MAC_MDIOSCAR, DA, addr);
XGMAC_IOWRITE(pdata, MAC_MDIOSCAR, mdio_sca);
mdio_sccd = 0;
XGMAC_SET_BITS(mdio_sccd, MAC_MDIOSCCDR, DATA, val);
XGMAC_SET_BITS(mdio_sccd, MAC_MDIOSCCDR, CMD, 1);
XGMAC_SET_BITS(mdio_sccd, MAC_MDIOSCCDR, BUSY, 1);
XGMAC_IOWRITE(pdata, MAC_MDIOSCCDR, mdio_sccd);
if (!wait_for_completion_timeout(&pdata->mdio_complete, HZ)) {
netdev_err(pdata->netdev, "mdio write operation timed out\n");
return -ETIMEDOUT;
}
return 0;
}
static int xgbe_read_ext_mii_regs(struct xgbe_prv_data *pdata, int addr,
int reg)
{
unsigned int mdio_sca, mdio_sccd;
reinit_completion(&pdata->mdio_complete);
mdio_sca = 0;
XGMAC_SET_BITS(mdio_sca, MAC_MDIOSCAR, REG, reg);
XGMAC_SET_BITS(mdio_sca, MAC_MDIOSCAR, DA, addr);
XGMAC_IOWRITE(pdata, MAC_MDIOSCAR, mdio_sca);
mdio_sccd = 0;
XGMAC_SET_BITS(mdio_sccd, MAC_MDIOSCCDR, CMD, 3);
XGMAC_SET_BITS(mdio_sccd, MAC_MDIOSCCDR, BUSY, 1);
XGMAC_IOWRITE(pdata, MAC_MDIOSCCDR, mdio_sccd);
if (!wait_for_completion_timeout(&pdata->mdio_complete, HZ)) {
netdev_err(pdata->netdev, "mdio read operation timed out\n");
return -ETIMEDOUT;
}
return XGMAC_IOREAD_BITS(pdata, MAC_MDIOSCCDR, DATA);
}
static int xgbe_set_ext_mii_mode(struct xgbe_prv_data *pdata, unsigned int port,
enum xgbe_mdio_mode mode)
{
unsigned int reg_val = XGMAC_IOREAD(pdata, MAC_MDIOCL22R);
switch (mode) {
case XGBE_MDIO_MODE_CL22:
if (port > XGMAC_MAX_C22_PORT)
return -EINVAL;
reg_val |= (1 << port);
break;
case XGBE_MDIO_MODE_CL45:
break;
default:
return -EINVAL;
}
XGMAC_IOWRITE(pdata, MAC_MDIOCL22R, reg_val);
return 0;
}
static int xgbe_tx_complete(struct xgbe_ring_desc *rdesc)
{
return !XGMAC_GET_BITS_LE(rdesc->desc3, TX_NORMAL_DESC3, OWN);
}
static int xgbe_disable_rx_csum(struct xgbe_prv_data *pdata)
{
XGMAC_IOWRITE_BITS(pdata, MAC_RCR, IPC, 0);
return 0;
}
static int xgbe_enable_rx_csum(struct xgbe_prv_data *pdata)
{
XGMAC_IOWRITE_BITS(pdata, MAC_RCR, IPC, 1);
return 0;
}
static void xgbe_tx_desc_reset(struct xgbe_ring_data *rdata)
{
struct xgbe_ring_desc *rdesc = rdata->rdesc;
rdesc->desc0 = 0;
rdesc->desc1 = 0;
rdesc->desc2 = 0;
rdesc->desc3 = 0;
dma_wmb();
}
static void xgbe_tx_desc_init(struct xgbe_channel *channel)
{
struct xgbe_ring *ring = channel->tx_ring;
struct xgbe_ring_data *rdata;
int i;
int start_index = ring->cur;
DBGPR("-->tx_desc_init\n");
for (i = 0; i < ring->rdesc_count; i++) {
rdata = XGBE_GET_DESC_DATA(ring, i);
xgbe_tx_desc_reset(rdata);
}
XGMAC_DMA_IOWRITE(channel, DMA_CH_TDRLR, ring->rdesc_count - 1);
rdata = XGBE_GET_DESC_DATA(ring, start_index);
XGMAC_DMA_IOWRITE(channel, DMA_CH_TDLR_HI,
upper_32_bits(rdata->rdesc_dma));
XGMAC_DMA_IOWRITE(channel, DMA_CH_TDLR_LO,
lower_32_bits(rdata->rdesc_dma));
DBGPR("<--tx_desc_init\n");
}
static void xgbe_rx_desc_reset(struct xgbe_prv_data *pdata,
struct xgbe_ring_data *rdata, unsigned int index)
{
struct xgbe_ring_desc *rdesc = rdata->rdesc;
unsigned int rx_usecs = pdata->rx_usecs;
unsigned int rx_frames = pdata->rx_frames;
unsigned int inte;
dma_addr_t hdr_dma, buf_dma;
if (!rx_usecs && !rx_frames) {
inte = 1;
} else {
if (rx_frames && !((index + 1) % rx_frames))
inte = 1;
else
inte = 0;
}
hdr_dma = rdata->rx.hdr.dma_base + rdata->rx.hdr.dma_off;
buf_dma = rdata->rx.buf.dma_base + rdata->rx.buf.dma_off;
rdesc->desc0 = cpu_to_le32(lower_32_bits(hdr_dma));
rdesc->desc1 = cpu_to_le32(upper_32_bits(hdr_dma));
rdesc->desc2 = cpu_to_le32(lower_32_bits(buf_dma));
rdesc->desc3 = cpu_to_le32(upper_32_bits(buf_dma));
XGMAC_SET_BITS_LE(rdesc->desc3, RX_NORMAL_DESC3, INTE, inte);
dma_wmb();
XGMAC_SET_BITS_LE(rdesc->desc3, RX_NORMAL_DESC3, OWN, 1);
dma_wmb();
}
static void xgbe_rx_desc_init(struct xgbe_channel *channel)
{
struct xgbe_prv_data *pdata = channel->pdata;
struct xgbe_ring *ring = channel->rx_ring;
struct xgbe_ring_data *rdata;
unsigned int start_index = ring->cur;
unsigned int i;
DBGPR("-->rx_desc_init\n");
for (i = 0; i < ring->rdesc_count; i++) {
rdata = XGBE_GET_DESC_DATA(ring, i);
xgbe_rx_desc_reset(pdata, rdata, i);
}
XGMAC_DMA_IOWRITE(channel, DMA_CH_RDRLR, ring->rdesc_count - 1);
rdata = XGBE_GET_DESC_DATA(ring, start_index);
XGMAC_DMA_IOWRITE(channel, DMA_CH_RDLR_HI,
upper_32_bits(rdata->rdesc_dma));
XGMAC_DMA_IOWRITE(channel, DMA_CH_RDLR_LO,
lower_32_bits(rdata->rdesc_dma));
rdata = XGBE_GET_DESC_DATA(ring, start_index + ring->rdesc_count - 1);
XGMAC_DMA_IOWRITE(channel, DMA_CH_RDTR_LO,
lower_32_bits(rdata->rdesc_dma));
DBGPR("<--rx_desc_init\n");
}
static void xgbe_update_tstamp_addend(struct xgbe_prv_data *pdata,
unsigned int addend)
{
XGMAC_IOWRITE(pdata, MAC_TSAR, addend);
XGMAC_IOWRITE_BITS(pdata, MAC_TSCR, TSADDREG, 1);
while (XGMAC_IOREAD_BITS(pdata, MAC_TSCR, TSADDREG))
udelay(5);
}
static void xgbe_set_tstamp_time(struct xgbe_prv_data *pdata, unsigned int sec,
unsigned int nsec)
{
XGMAC_IOWRITE(pdata, MAC_STSUR, sec);
XGMAC_IOWRITE(pdata, MAC_STNUR, nsec);
XGMAC_IOWRITE_BITS(pdata, MAC_TSCR, TSINIT, 1);
while (XGMAC_IOREAD_BITS(pdata, MAC_TSCR, TSINIT))
udelay(5);
}
static u64 xgbe_get_tstamp_time(struct xgbe_prv_data *pdata)
{
u64 nsec;
nsec = XGMAC_IOREAD(pdata, MAC_STSR);
nsec *= NSEC_PER_SEC;
nsec += XGMAC_IOREAD(pdata, MAC_STNR);
return nsec;
}
static u64 xgbe_get_tx_tstamp(struct xgbe_prv_data *pdata)
{
unsigned int tx_snr, tx_ssr;
u64 nsec;
if (pdata->vdata->tx_tstamp_workaround) {
tx_snr = XGMAC_IOREAD(pdata, MAC_TXSNR);
tx_ssr = XGMAC_IOREAD(pdata, MAC_TXSSR);
} else {
tx_ssr = XGMAC_IOREAD(pdata, MAC_TXSSR);
tx_snr = XGMAC_IOREAD(pdata, MAC_TXSNR);
}
if (XGMAC_GET_BITS(tx_snr, MAC_TXSNR, TXTSSTSMIS))
return 0;
nsec = tx_ssr;
nsec *= NSEC_PER_SEC;
nsec += tx_snr;
return nsec;
}
static void xgbe_get_rx_tstamp(struct xgbe_packet_data *packet,
struct xgbe_ring_desc *rdesc)
{
u64 nsec;
if (XGMAC_GET_BITS_LE(rdesc->desc3, RX_CONTEXT_DESC3, TSA) &&
!XGMAC_GET_BITS_LE(rdesc->desc3, RX_CONTEXT_DESC3, TSD)) {
nsec = le32_to_cpu(rdesc->desc1);
nsec <<= 32;
nsec |= le32_to_cpu(rdesc->desc0);
if (nsec != 0xffffffffffffffffULL) {
packet->rx_tstamp = nsec;
XGMAC_SET_BITS(packet->attributes, RX_PACKET_ATTRIBUTES,
RX_TSTAMP, 1);
}
}
}
static int xgbe_config_tstamp(struct xgbe_prv_data *pdata,
unsigned int mac_tscr)
{
XGMAC_SET_BITS(mac_tscr, MAC_TSCR, TSCTRLSSR, 1);
XGMAC_SET_BITS(mac_tscr, MAC_TSCR, TSCFUPDT, 1);
XGMAC_SET_BITS(mac_tscr, MAC_TSCR, TXTSSTSM, 1);
XGMAC_IOWRITE(pdata, MAC_TSCR, mac_tscr);
if (!XGMAC_GET_BITS(mac_tscr, MAC_TSCR, TSENA))
return 0;
XGMAC_IOWRITE_BITS(pdata, MAC_SSIR, SSINC, XGBE_TSTAMP_SSINC);
XGMAC_IOWRITE_BITS(pdata, MAC_SSIR, SNSINC, XGBE_TSTAMP_SNSINC);
xgbe_update_tstamp_addend(pdata, pdata->tstamp_addend);
xgbe_set_tstamp_time(pdata, 0, 0);
timecounter_init(&pdata->tstamp_tc, &pdata->tstamp_cc,
ktime_to_ns(ktime_get_real()));
return 0;
}
static void xgbe_tx_start_xmit(struct xgbe_channel *channel,
struct xgbe_ring *ring)
{
struct xgbe_prv_data *pdata = channel->pdata;
struct xgbe_ring_data *rdata;
wmb();
rdata = XGBE_GET_DESC_DATA(ring, ring->cur);
XGMAC_DMA_IOWRITE(channel, DMA_CH_TDTR_LO,
lower_32_bits(rdata->rdesc_dma));
if (pdata->tx_usecs && !channel->tx_timer_active) {
channel->tx_timer_active = 1;
mod_timer(&channel->tx_timer,
jiffies + usecs_to_jiffies(pdata->tx_usecs));
}
ring->tx.xmit_more = 0;
}
static void xgbe_dev_xmit(struct xgbe_channel *channel)
{
struct xgbe_prv_data *pdata = channel->pdata;
struct xgbe_ring *ring = channel->tx_ring;
struct xgbe_ring_data *rdata;
struct xgbe_ring_desc *rdesc;
struct xgbe_packet_data *packet = &ring->packet_data;
unsigned int csum, tso, vlan;
unsigned int tso_context, vlan_context;
unsigned int tx_set_ic;
int start_index = ring->cur;
int cur_index = ring->cur;
int i;
DBGPR("-->xgbe_dev_xmit\n");
csum = XGMAC_GET_BITS(packet->attributes, TX_PACKET_ATTRIBUTES,
CSUM_ENABLE);
tso = XGMAC_GET_BITS(packet->attributes, TX_PACKET_ATTRIBUTES,
TSO_ENABLE);
vlan = XGMAC_GET_BITS(packet->attributes, TX_PACKET_ATTRIBUTES,
VLAN_CTAG);
if (tso && (packet->mss != ring->tx.cur_mss))
tso_context = 1;
else
tso_context = 0;
if (vlan && (packet->vlan_ctag != ring->tx.cur_vlan_ctag))
vlan_context = 1;
else
vlan_context = 0;
ring->coalesce_count += packet->tx_packets;
if (!pdata->tx_frames)
tx_set_ic = 0;
else if (packet->tx_packets > pdata->tx_frames)
tx_set_ic = 1;
else if ((ring->coalesce_count % pdata->tx_frames) <
packet->tx_packets)
tx_set_ic = 1;
else
tx_set_ic = 0;
rdata = XGBE_GET_DESC_DATA(ring, cur_index);
rdesc = rdata->rdesc;
if (tso_context || vlan_context) {
if (tso_context) {
netif_dbg(pdata, tx_queued, pdata->netdev,
"TSO context descriptor, mss=%u\n",
packet->mss);
XGMAC_SET_BITS_LE(rdesc->desc2, TX_CONTEXT_DESC2,
MSS, packet->mss);
XGMAC_SET_BITS_LE(rdesc->desc3, TX_CONTEXT_DESC3,
CTXT, 1);
XGMAC_SET_BITS_LE(rdesc->desc3, TX_CONTEXT_DESC3,
TCMSSV, 1);
ring->tx.cur_mss = packet->mss;
}
if (vlan_context) {
netif_dbg(pdata, tx_queued, pdata->netdev,
"VLAN context descriptor, ctag=%u\n",
packet->vlan_ctag);
XGMAC_SET_BITS_LE(rdesc->desc3, TX_CONTEXT_DESC3,
CTXT, 1);
XGMAC_SET_BITS_LE(rdesc->desc3, TX_CONTEXT_DESC3,
VT, packet->vlan_ctag);
XGMAC_SET_BITS_LE(rdesc->desc3, TX_CONTEXT_DESC3,
VLTV, 1);
ring->tx.cur_vlan_ctag = packet->vlan_ctag;
}
cur_index++;
rdata = XGBE_GET_DESC_DATA(ring, cur_index);
rdesc = rdata->rdesc;
}
rdesc->desc0 = cpu_to_le32(lower_32_bits(rdata->skb_dma));
rdesc->desc1 = cpu_to_le32(upper_32_bits(rdata->skb_dma));
XGMAC_SET_BITS_LE(rdesc->desc2, TX_NORMAL_DESC2, HL_B1L,
rdata->skb_dma_len);
if (vlan)
XGMAC_SET_BITS_LE(rdesc->desc2, TX_NORMAL_DESC2, VTIR,
TX_NORMAL_DESC2_VLAN_INSERT);
if (XGMAC_GET_BITS(packet->attributes, TX_PACKET_ATTRIBUTES, PTP))
XGMAC_SET_BITS_LE(rdesc->desc2, TX_NORMAL_DESC2, TTSE, 1);
XGMAC_SET_BITS_LE(rdesc->desc3, TX_NORMAL_DESC3, FD, 1);
XGMAC_SET_BITS_LE(rdesc->desc3, TX_NORMAL_DESC3, CTXT, 0);
if (cur_index != start_index)
XGMAC_SET_BITS_LE(rdesc->desc3, TX_NORMAL_DESC3, OWN, 1);
if (tso) {
XGMAC_SET_BITS_LE(rdesc->desc3, TX_NORMAL_DESC3, TSE, 1);
XGMAC_SET_BITS_LE(rdesc->desc3, TX_NORMAL_DESC3, TCPPL,
packet->tcp_payload_len);
XGMAC_SET_BITS_LE(rdesc->desc3, TX_NORMAL_DESC3, TCPHDRLEN,
packet->tcp_header_len / 4);
pdata->ext_stats.tx_tso_packets++;
} else {
XGMAC_SET_BITS_LE(rdesc->desc3, TX_NORMAL_DESC3, CPC, 0);
if (csum)
XGMAC_SET_BITS_LE(rdesc->desc3, TX_NORMAL_DESC3,
CIC, 0x3);
XGMAC_SET_BITS_LE(rdesc->desc3, TX_NORMAL_DESC3, FL,
packet->length);
}
for (i = cur_index - start_index + 1; i < packet->rdesc_count; i++) {
cur_index++;
rdata = XGBE_GET_DESC_DATA(ring, cur_index);
rdesc = rdata->rdesc;
rdesc->desc0 = cpu_to_le32(lower_32_bits(rdata->skb_dma));
rdesc->desc1 = cpu_to_le32(upper_32_bits(rdata->skb_dma));
XGMAC_SET_BITS_LE(rdesc->desc2, TX_NORMAL_DESC2, HL_B1L,
rdata->skb_dma_len);
XGMAC_SET_BITS_LE(rdesc->desc3, TX_NORMAL_DESC3, OWN, 1);
XGMAC_SET_BITS_LE(rdesc->desc3, TX_NORMAL_DESC3, CTXT, 0);
if (csum)
XGMAC_SET_BITS_LE(rdesc->desc3, TX_NORMAL_DESC3,
CIC, 0x3);
}
XGMAC_SET_BITS_LE(rdesc->desc3, TX_NORMAL_DESC3, LD, 1);
if (tx_set_ic)
XGMAC_SET_BITS_LE(rdesc->desc2, TX_NORMAL_DESC2, IC, 1);
rdata->tx.packets = packet->tx_packets;
rdata->tx.bytes = packet->tx_bytes;
dma_wmb();
rdata = XGBE_GET_DESC_DATA(ring, start_index);
rdesc = rdata->rdesc;
XGMAC_SET_BITS_LE(rdesc->desc3, TX_NORMAL_DESC3, OWN, 1);
if (netif_msg_tx_queued(pdata))
xgbe_dump_tx_desc(pdata, ring, start_index,
packet->rdesc_count, 1);
smp_wmb();
ring->cur = cur_index + 1;
if (!packet->skb->xmit_more ||
netif_xmit_stopped(netdev_get_tx_queue(pdata->netdev,
channel->queue_index)))
xgbe_tx_start_xmit(channel, ring);
else
ring->tx.xmit_more = 1;
DBGPR(" %s: descriptors %u to %u written\n",
channel->name, start_index & (ring->rdesc_count - 1),
(ring->cur - 1) & (ring->rdesc_count - 1));
DBGPR("<--xgbe_dev_xmit\n");
}
static int xgbe_dev_read(struct xgbe_channel *channel)
{
struct xgbe_prv_data *pdata = channel->pdata;
struct xgbe_ring *ring = channel->rx_ring;
struct xgbe_ring_data *rdata;
struct xgbe_ring_desc *rdesc;
struct xgbe_packet_data *packet = &ring->packet_data;
struct net_device *netdev = pdata->netdev;
unsigned int err, etlt, l34t;
DBGPR("-->xgbe_dev_read: cur = %d\n", ring->cur);
rdata = XGBE_GET_DESC_DATA(ring, ring->cur);
rdesc = rdata->rdesc;
if (XGMAC_GET_BITS_LE(rdesc->desc3, RX_NORMAL_DESC3, OWN))
return 1;
dma_rmb();
if (netif_msg_rx_status(pdata))
xgbe_dump_rx_desc(pdata, ring, ring->cur);
if (XGMAC_GET_BITS_LE(rdesc->desc3, RX_NORMAL_DESC3, CTXT)) {
xgbe_get_rx_tstamp(packet, rdesc);
XGMAC_SET_BITS(packet->attributes, RX_PACKET_ATTRIBUTES,
CONTEXT, 1);
XGMAC_SET_BITS(packet->attributes, RX_PACKET_ATTRIBUTES,
CONTEXT_NEXT, 0);
return 0;
}
XGMAC_SET_BITS(packet->attributes, RX_PACKET_ATTRIBUTES, CONTEXT, 0);
if (XGMAC_GET_BITS_LE(rdesc->desc3, RX_NORMAL_DESC3, CDA))
XGMAC_SET_BITS(packet->attributes, RX_PACKET_ATTRIBUTES,
CONTEXT_NEXT, 1);
if (XGMAC_GET_BITS_LE(rdesc->desc3, RX_NORMAL_DESC3, FD)) {
XGMAC_SET_BITS(packet->attributes, RX_PACKET_ATTRIBUTES,
FIRST, 1);
rdata->rx.hdr_len = XGMAC_GET_BITS_LE(rdesc->desc2,
RX_NORMAL_DESC2, HL);
if (rdata->rx.hdr_len)
pdata->ext_stats.rx_split_header_packets++;
} else {
XGMAC_SET_BITS(packet->attributes, RX_PACKET_ATTRIBUTES,
FIRST, 0);
}
if (XGMAC_GET_BITS_LE(rdesc->desc3, RX_NORMAL_DESC3, RSV)) {
XGMAC_SET_BITS(packet->attributes, RX_PACKET_ATTRIBUTES,
RSS_HASH, 1);
packet->rss_hash = le32_to_cpu(rdesc->desc1);
l34t = XGMAC_GET_BITS_LE(rdesc->desc3, RX_NORMAL_DESC3, L34T);
switch (l34t) {
case RX_DESC3_L34T_IPV4_TCP:
case RX_DESC3_L34T_IPV4_UDP:
case RX_DESC3_L34T_IPV6_TCP:
case RX_DESC3_L34T_IPV6_UDP:
packet->rss_hash_type = PKT_HASH_TYPE_L4;
break;
default:
packet->rss_hash_type = PKT_HASH_TYPE_L3;
}
}
if (!XGMAC_GET_BITS_LE(rdesc->desc3, RX_NORMAL_DESC3, LD))
return 0;
XGMAC_SET_BITS(packet->attributes, RX_PACKET_ATTRIBUTES,
LAST, 1);
rdata->rx.len = XGMAC_GET_BITS_LE(rdesc->desc3, RX_NORMAL_DESC3, PL);
if (netdev->features & NETIF_F_RXCSUM)
XGMAC_SET_BITS(packet->attributes, RX_PACKET_ATTRIBUTES,
CSUM_DONE, 1);
err = XGMAC_GET_BITS_LE(rdesc->desc3, RX_NORMAL_DESC3, ES);
etlt = XGMAC_GET_BITS_LE(rdesc->desc3, RX_NORMAL_DESC3, ETLT);
netif_dbg(pdata, rx_status, netdev, "err=%u, etlt=%#x\n", err, etlt);
if (!err || !etlt) {
if ((etlt == 0x09) &&
(netdev->features & NETIF_F_HW_VLAN_CTAG_RX)) {
XGMAC_SET_BITS(packet->attributes, RX_PACKET_ATTRIBUTES,
VLAN_CTAG, 1);
packet->vlan_ctag = XGMAC_GET_BITS_LE(rdesc->desc0,
RX_NORMAL_DESC0,
OVT);
netif_dbg(pdata, rx_status, netdev, "vlan-ctag=%#06x\n",
packet->vlan_ctag);
}
} else {
if ((etlt == 0x05) || (etlt == 0x06))
XGMAC_SET_BITS(packet->attributes, RX_PACKET_ATTRIBUTES,
CSUM_DONE, 0);
else
XGMAC_SET_BITS(packet->errors, RX_PACKET_ERRORS,
FRAME, 1);
}
DBGPR("<--xgbe_dev_read: %s - descriptor=%u (cur=%d)\n", channel->name,
ring->cur & (ring->rdesc_count - 1), ring->cur);
return 0;
}
static int xgbe_is_context_desc(struct xgbe_ring_desc *rdesc)
{
return XGMAC_GET_BITS_LE(rdesc->desc3, TX_NORMAL_DESC3, CTXT);
}
static int xgbe_is_last_desc(struct xgbe_ring_desc *rdesc)
{
return XGMAC_GET_BITS_LE(rdesc->desc3, TX_NORMAL_DESC3, LD);
}
static int xgbe_enable_int(struct xgbe_channel *channel,
enum xgbe_int int_id)
{
unsigned int dma_ch_ier;
dma_ch_ier = XGMAC_DMA_IOREAD(channel, DMA_CH_IER);
switch (int_id) {
case XGMAC_INT_DMA_CH_SR_TI:
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, TIE, 1);
break;
case XGMAC_INT_DMA_CH_SR_TPS:
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, TXSE, 1);
break;
case XGMAC_INT_DMA_CH_SR_TBU:
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, TBUE, 1);
break;
case XGMAC_INT_DMA_CH_SR_RI:
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, RIE, 1);
break;
case XGMAC_INT_DMA_CH_SR_RBU:
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, RBUE, 1);
break;
case XGMAC_INT_DMA_CH_SR_RPS:
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, RSE, 1);
break;
case XGMAC_INT_DMA_CH_SR_TI_RI:
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, TIE, 1);
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, RIE, 1);
break;
case XGMAC_INT_DMA_CH_SR_FBE:
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, FBEE, 1);
break;
case XGMAC_INT_DMA_ALL:
dma_ch_ier |= channel->saved_ier;
break;
default:
return -1;
}
XGMAC_DMA_IOWRITE(channel, DMA_CH_IER, dma_ch_ier);
return 0;
}
static int xgbe_disable_int(struct xgbe_channel *channel,
enum xgbe_int int_id)
{
unsigned int dma_ch_ier;
dma_ch_ier = XGMAC_DMA_IOREAD(channel, DMA_CH_IER);
switch (int_id) {
case XGMAC_INT_DMA_CH_SR_TI:
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, TIE, 0);
break;
case XGMAC_INT_DMA_CH_SR_TPS:
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, TXSE, 0);
break;
case XGMAC_INT_DMA_CH_SR_TBU:
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, TBUE, 0);
break;
case XGMAC_INT_DMA_CH_SR_RI:
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, RIE, 0);
break;
case XGMAC_INT_DMA_CH_SR_RBU:
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, RBUE, 0);
break;
case XGMAC_INT_DMA_CH_SR_RPS:
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, RSE, 0);
break;
case XGMAC_INT_DMA_CH_SR_TI_RI:
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, TIE, 0);
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, RIE, 0);
break;
case XGMAC_INT_DMA_CH_SR_FBE:
XGMAC_SET_BITS(dma_ch_ier, DMA_CH_IER, FBEE, 0);
break;
case XGMAC_INT_DMA_ALL:
channel->saved_ier = dma_ch_ier & XGBE_DMA_INTERRUPT_MASK;
dma_ch_ier &= ~XGBE_DMA_INTERRUPT_MASK;
break;
default:
return -1;
}
XGMAC_DMA_IOWRITE(channel, DMA_CH_IER, dma_ch_ier);
return 0;
}
static int __xgbe_exit(struct xgbe_prv_data *pdata)
{
unsigned int count = 2000;
DBGPR("-->xgbe_exit\n");
XGMAC_IOWRITE_BITS(pdata, DMA_MR, SWR, 1);
usleep_range(10, 15);
while (--count && XGMAC_IOREAD_BITS(pdata, DMA_MR, SWR))
usleep_range(500, 600);
if (!count)
return -EBUSY;
DBGPR("<--xgbe_exit\n");
return 0;
}
static int xgbe_exit(struct xgbe_prv_data *pdata)
{
int ret;
ret = __xgbe_exit(pdata);
if (ret)
return ret;
return __xgbe_exit(pdata);
}
static int xgbe_flush_tx_queues(struct xgbe_prv_data *pdata)
{
unsigned int i, count;
if (XGMAC_GET_BITS(pdata->hw_feat.version, MAC_VR, SNPSVER) < 0x21)
return 0;
for (i = 0; i < pdata->tx_q_count; i++)
XGMAC_MTL_IOWRITE_BITS(pdata, i, MTL_Q_TQOMR, FTQ, 1);
for (i = 0; i < pdata->tx_q_count; i++) {
count = 2000;
while (--count && XGMAC_MTL_IOREAD_BITS(pdata, i,
MTL_Q_TQOMR, FTQ))
usleep_range(500, 600);
if (!count)
return -EBUSY;
}
return 0;
}
static void xgbe_config_dma_bus(struct xgbe_prv_data *pdata)
{
XGMAC_IOWRITE_BITS(pdata, DMA_SBMR, EAME, 1);
XGMAC_IOWRITE_BITS(pdata, DMA_SBMR, UNDEF, 1);
XGMAC_IOWRITE_BITS(pdata, DMA_SBMR, BLEN_256, 1);
}
static void xgbe_config_dma_cache(struct xgbe_prv_data *pdata)
{
unsigned int arcache, awcache;
arcache = 0;
XGMAC_SET_BITS(arcache, DMA_AXIARCR, DRC, pdata->arcache);
XGMAC_SET_BITS(arcache, DMA_AXIARCR, DRD, pdata->axdomain);
XGMAC_SET_BITS(arcache, DMA_AXIARCR, TEC, pdata->arcache);
XGMAC_SET_BITS(arcache, DMA_AXIARCR, TED, pdata->axdomain);
XGMAC_SET_BITS(arcache, DMA_AXIARCR, THC, pdata->arcache);
XGMAC_SET_BITS(arcache, DMA_AXIARCR, THD, pdata->axdomain);
XGMAC_IOWRITE(pdata, DMA_AXIARCR, arcache);
awcache = 0;
XGMAC_SET_BITS(awcache, DMA_AXIAWCR, DWC, pdata->awcache);
XGMAC_SET_BITS(awcache, DMA_AXIAWCR, DWD, pdata->axdomain);
XGMAC_SET_BITS(awcache, DMA_AXIAWCR, RPC, pdata->awcache);
XGMAC_SET_BITS(awcache, DMA_AXIAWCR, RPD, pdata->axdomain);
XGMAC_SET_BITS(awcache, DMA_AXIAWCR, RHC, pdata->awcache);
XGMAC_SET_BITS(awcache, DMA_AXIAWCR, RHD, pdata->axdomain);
XGMAC_SET_BITS(awcache, DMA_AXIAWCR, TDC, pdata->awcache);
XGMAC_SET_BITS(awcache, DMA_AXIAWCR, TDD, pdata->axdomain);
XGMAC_IOWRITE(pdata, DMA_AXIAWCR, awcache);
}
static void xgbe_config_mtl_mode(struct xgbe_prv_data *pdata)
{
unsigned int i;
XGMAC_IOWRITE_BITS(pdata, MTL_OMR, ETSALG, MTL_ETSALG_WRR);
for (i = 0; i < pdata->hw_feat.tc_cnt; i++) {
XGMAC_MTL_IOWRITE_BITS(pdata, i, MTL_TC_ETSCR, TSA,
MTL_TSA_ETS);
XGMAC_MTL_IOWRITE_BITS(pdata, i, MTL_TC_QWR, QW, 1);
}
XGMAC_IOWRITE_BITS(pdata, MTL_OMR, RAA, MTL_RAA_SP);
}
static void xgbe_queue_flow_control_threshold(struct xgbe_prv_data *pdata,
unsigned int queue,
unsigned int q_fifo_size)
{
unsigned int frame_fifo_size;
unsigned int rfa, rfd;
frame_fifo_size = XGMAC_FLOW_CONTROL_ALIGN(xgbe_get_max_frame(pdata));
if (pdata->pfcq[queue] && (q_fifo_size > pdata->pfc_rfa)) {
rfa = pdata->pfc_rfa;
rfd = rfa + frame_fifo_size;
if (rfd > XGMAC_FLOW_CONTROL_MAX)
rfd = XGMAC_FLOW_CONTROL_MAX;
if (rfa >= XGMAC_FLOW_CONTROL_MAX)
rfa = XGMAC_FLOW_CONTROL_MAX - XGMAC_FLOW_CONTROL_UNIT;
} else {
if (q_fifo_size <= 2048) {
pdata->rx_rfa[queue] = 0;
pdata->rx_rfd[queue] = 0;
return;
}
if (q_fifo_size <= 4096) {
pdata->rx_rfa[queue] = 0;
pdata->rx_rfd[queue] = 1;
return;
}
if (q_fifo_size <= frame_fifo_size) {
pdata->rx_rfa[queue] = 2;
pdata->rx_rfd[queue] = 5;
return;
}
if (q_fifo_size <= (frame_fifo_size * 3)) {
rfa = q_fifo_size - frame_fifo_size;
rfd = rfa + (frame_fifo_size / 2);
} else {
rfa = frame_fifo_size * 2;
rfa += XGMAC_FLOW_CONTROL_UNIT;
rfd = rfa + frame_fifo_size;
}
}
pdata->rx_rfa[queue] = XGMAC_FLOW_CONTROL_VALUE(rfa);
pdata->rx_rfd[queue] = XGMAC_FLOW_CONTROL_VALUE(rfd);
}
static void xgbe_calculate_flow_control_threshold(struct xgbe_prv_data *pdata,
unsigned int *fifo)
{
unsigned int q_fifo_size;
unsigned int i;
for (i = 0; i < pdata->rx_q_count; i++) {
q_fifo_size = (fifo[i] + 1) * XGMAC_FIFO_UNIT;
xgbe_queue_flow_control_threshold(pdata, i, q_fifo_size);
}
}
static void xgbe_config_flow_control_threshold(struct xgbe_prv_data *pdata)
{
unsigned int i;
for (i = 0; i < pdata->rx_q_count; i++) {
XGMAC_MTL_IOWRITE_BITS(pdata, i, MTL_Q_RQFCR, RFA,
pdata->rx_rfa[i]);
XGMAC_MTL_IOWRITE_BITS(pdata, i, MTL_Q_RQFCR, RFD,
pdata->rx_rfd[i]);
}
}
static unsigned int xgbe_get_tx_fifo_size(struct xgbe_prv_data *pdata)
{
return min_t(unsigned int, pdata->tx_max_fifo_size,
pdata->hw_feat.tx_fifo_size);
}
static unsigned int xgbe_get_rx_fifo_size(struct xgbe_prv_data *pdata)
{
return min_t(unsigned int, pdata->rx_max_fifo_size,
pdata->hw_feat.rx_fifo_size);
}
static void xgbe_calculate_equal_fifo(unsigned int fifo_size,
unsigned int queue_count,
unsigned int *fifo)
{
unsigned int q_fifo_size;
unsigned int p_fifo;
unsigned int i;
q_fifo_size = fifo_size / queue_count;
p_fifo = q_fifo_size / XGMAC_FIFO_UNIT;
if (p_fifo)
p_fifo--;
for (i = 0; i < queue_count; i++)
fifo[i] = p_fifo;
}
static unsigned int xgbe_set_nonprio_fifos(unsigned int fifo_size,
unsigned int queue_count,
unsigned int *fifo)
{
unsigned int i;
BUILD_BUG_ON_NOT_POWER_OF_2(XGMAC_FIFO_MIN_ALLOC);
if (queue_count <= IEEE_8021QAZ_MAX_TCS)
return fifo_size;
for (i = IEEE_8021QAZ_MAX_TCS; i < queue_count; i++) {
fifo[i] = (XGMAC_FIFO_MIN_ALLOC / XGMAC_FIFO_UNIT) - 1;
fifo_size -= XGMAC_FIFO_MIN_ALLOC;
}
return fifo_size;
}
static unsigned int xgbe_get_pfc_delay(struct xgbe_prv_data *pdata)
{
unsigned int delay;
if (pdata->pfc->delay)
return pdata->pfc->delay / 8;
delay = xgbe_get_max_frame(pdata);
delay += XGMAC_ETH_PREAMBLE;
delay *= 2;
delay += XGMAC_PFC_DATA_LEN;
delay += ETH_HLEN + ETH_FCS_LEN;
delay += XGMAC_ETH_PREAMBLE;
delay += XGMAC_PFC_DELAYS;
return delay;
}
static unsigned int xgbe_get_pfc_queues(struct xgbe_prv_data *pdata)
{
unsigned int count, prio_queues;
unsigned int i;
if (!pdata->pfc->pfc_en)
return 0;
count = 0;
prio_queues = XGMAC_PRIO_QUEUES(pdata->rx_q_count);
for (i = 0; i < prio_queues; i++) {
if (!xgbe_is_pfc_queue(pdata, i))
continue;
pdata->pfcq[i] = 1;
count++;
}
return count;
}
static void xgbe_calculate_dcb_fifo(struct xgbe_prv_data *pdata,
unsigned int fifo_size,
unsigned int *fifo)
{
unsigned int q_fifo_size, rem_fifo, addn_fifo;
unsigned int prio_queues;
unsigned int pfc_count;
unsigned int i;
q_fifo_size = XGMAC_FIFO_ALIGN(xgbe_get_max_frame(pdata));
prio_queues = XGMAC_PRIO_QUEUES(pdata->rx_q_count);
pfc_count = xgbe_get_pfc_queues(pdata);
if (!pfc_count || ((q_fifo_size * prio_queues) > fifo_size)) {
xgbe_calculate_equal_fifo(fifo_size, prio_queues, fifo);
return;
}
rem_fifo = fifo_size - (q_fifo_size * prio_queues);
pdata->pfc_rfa = xgbe_get_pfc_delay(pdata);
pdata->pfc_rfa = XGMAC_FLOW_CONTROL_ALIGN(pdata->pfc_rfa);
if (pdata->pfc_rfa > q_fifo_size) {
addn_fifo = pdata->pfc_rfa - q_fifo_size;
addn_fifo = XGMAC_FIFO_ALIGN(addn_fifo);
} else {
addn_fifo = 0;
}
i = prio_queues;
while (i > 0) {
i--;
fifo[i] = (q_fifo_size / XGMAC_FIFO_UNIT) - 1;
if (!pdata->pfcq[i] || !addn_fifo)
continue;
if (addn_fifo > rem_fifo) {
netdev_warn(pdata->netdev,
"RXq%u cannot set needed fifo size\n", i);
if (!rem_fifo)
continue;
addn_fifo = rem_fifo;
}
fifo[i] += (addn_fifo / XGMAC_FIFO_UNIT);
rem_fifo -= addn_fifo;
}
if (rem_fifo) {
unsigned int inc_fifo = rem_fifo / prio_queues;
for (i = 0; i < prio_queues; i++)
fifo[i] += (inc_fifo / XGMAC_FIFO_UNIT);
}
}
static void xgbe_config_tx_fifo_size(struct xgbe_prv_data *pdata)
{
unsigned int fifo_size;
unsigned int fifo[XGBE_MAX_QUEUES];
unsigned int i;
fifo_size = xgbe_get_tx_fifo_size(pdata);
xgbe_calculate_equal_fifo(fifo_size, pdata->tx_q_count, fifo);
for (i = 0; i < pdata->tx_q_count; i++)
XGMAC_MTL_IOWRITE_BITS(pdata, i, MTL_Q_TQOMR, TQS, fifo[i]);
netif_info(pdata, drv, pdata->netdev,
"%d Tx hardware queues, %d byte fifo per queue\n",
pdata->tx_q_count, ((fifo[0] + 1) * XGMAC_FIFO_UNIT));
}
static void xgbe_config_rx_fifo_size(struct xgbe_prv_data *pdata)
{
unsigned int fifo_size;
unsigned int fifo[XGBE_MAX_QUEUES];
unsigned int prio_queues;
unsigned int i;
memset(pdata->pfcq, 0, sizeof(pdata->pfcq));
pdata->pfc_rfa = 0;
fifo_size = xgbe_get_rx_fifo_size(pdata);
prio_queues = XGMAC_PRIO_QUEUES(pdata->rx_q_count);
fifo_size = xgbe_set_nonprio_fifos(fifo_size, pdata->rx_q_count, fifo);
if (pdata->pfc && pdata->ets)
xgbe_calculate_dcb_fifo(pdata, fifo_size, fifo);
else
xgbe_calculate_equal_fifo(fifo_size, prio_queues, fifo);
for (i = 0; i < pdata->rx_q_count; i++)
XGMAC_MTL_IOWRITE_BITS(pdata, i, MTL_Q_RQOMR, RQS, fifo[i]);
xgbe_calculate_flow_control_threshold(pdata, fifo);
xgbe_config_flow_control_threshold(pdata);
if (pdata->pfc && pdata->ets && pdata->pfc->pfc_en) {
netif_info(pdata, drv, pdata->netdev,
"%u Rx hardware queues\n", pdata->rx_q_count);
for (i = 0; i < pdata->rx_q_count; i++)
netif_info(pdata, drv, pdata->netdev,
"RxQ%u, %u byte fifo queue\n", i,
((fifo[i] + 1) * XGMAC_FIFO_UNIT));
} else {
netif_info(pdata, drv, pdata->netdev,
"%u Rx hardware queues, %u byte fifo per queue\n",
pdata->rx_q_count,
((fifo[0] + 1) * XGMAC_FIFO_UNIT));
}
}
static void xgbe_config_queue_mapping(struct xgbe_prv_data *pdata)
{
unsigned int qptc, qptc_extra, queue;
unsigned int prio_queues;
unsigned int ppq, ppq_extra, prio;
unsigned int mask;
unsigned int i, j, reg, reg_val;
qptc = pdata->tx_q_count / pdata->hw_feat.tc_cnt;
qptc_extra = pdata->tx_q_count % pdata->hw_feat.tc_cnt;
for (i = 0, queue = 0; i < pdata->hw_feat.tc_cnt; i++) {
for (j = 0; j < qptc; j++) {
netif_dbg(pdata, drv, pdata->netdev,
"TXq%u mapped to TC%u\n", queue, i);
XGMAC_MTL_IOWRITE_BITS(pdata, queue, MTL_Q_TQOMR,
Q2TCMAP, i);
pdata->q2tc_map[queue++] = i;
}
if (i < qptc_extra) {
netif_dbg(pdata, drv, pdata->netdev,
"TXq%u mapped to TC%u\n", queue, i);
XGMAC_MTL_IOWRITE_BITS(pdata, queue, MTL_Q_TQOMR,
Q2TCMAP, i);
pdata->q2tc_map[queue++] = i;
}
}
prio_queues = XGMAC_PRIO_QUEUES(pdata->rx_q_count);
ppq = IEEE_8021QAZ_MAX_TCS / prio_queues;
ppq_extra = IEEE_8021QAZ_MAX_TCS % prio_queues;
reg = MAC_RQC2R;
reg_val = 0;
for (i = 0, prio = 0; i < prio_queues;) {
mask = 0;
for (j = 0; j < ppq; j++) {
netif_dbg(pdata, drv, pdata->netdev,
"PRIO%u mapped to RXq%u\n", prio, i);
mask |= (1 << prio);
pdata->prio2q_map[prio++] = i;
}
if (i < ppq_extra) {
netif_dbg(pdata, drv, pdata->netdev,
"PRIO%u mapped to RXq%u\n", prio, i);
mask |= (1 << prio);
pdata->prio2q_map[prio++] = i;
}
reg_val |= (mask << ((i++ % MAC_RQC2_Q_PER_REG) << 3));
if ((i % MAC_RQC2_Q_PER_REG) && (i != prio_queues))
continue;
XGMAC_IOWRITE(pdata, reg, reg_val);
reg += MAC_RQC2_INC;
reg_val = 0;
}
reg = MTL_RQDCM0R;
reg_val = 0;
for (i = 0; i < pdata->rx_q_count;) {
reg_val |= (0x80 << ((i++ % MTL_RQDCM_Q_PER_REG) << 3));
if ((i % MTL_RQDCM_Q_PER_REG) && (i != pdata->rx_q_count))
continue;
XGMAC_IOWRITE(pdata, reg, reg_val);
reg += MTL_RQDCM_INC;
reg_val = 0;
}
}
static void xgbe_config_tc(struct xgbe_prv_data *pdata)
{
unsigned int offset, queue, prio;
u8 i;
netdev_reset_tc(pdata->netdev);
if (!pdata->num_tcs)
return;
netdev_set_num_tc(pdata->netdev, pdata->num_tcs);
for (i = 0, queue = 0, offset = 0; i < pdata->num_tcs; i++) {
while ((queue < pdata->tx_q_count) &&
(pdata->q2tc_map[queue] == i))
queue++;
netif_dbg(pdata, drv, pdata->netdev, "TC%u using TXq%u-%u\n",
i, offset, queue - 1);
netdev_set_tc_queue(pdata->netdev, i, queue - offset, offset);
offset = queue;
}
if (!pdata->ets)
return;
for (prio = 0; prio < IEEE_8021QAZ_MAX_TCS; prio++)
netdev_set_prio_tc_map(pdata->netdev, prio,
pdata->ets->prio_tc[prio]);
}
static void xgbe_config_dcb_tc(struct xgbe_prv_data *pdata)
{
struct ieee_ets *ets = pdata->ets;
unsigned int total_weight, min_weight, weight;
unsigned int mask, reg, reg_val;
unsigned int i, prio;
if (!ets)
return;
XGMAC_IOWRITE_BITS(pdata, MTL_OMR, ETSALG, MTL_ETSALG_DWRR);
total_weight = pdata->netdev->mtu * pdata->hw_feat.tc_cnt;
min_weight = total_weight / 100;
if (!min_weight)
min_weight = 1;
for (i = 0; i < pdata->hw_feat.tc_cnt; i++) {
mask = 0;
for (prio = 0; prio < IEEE_8021QAZ_MAX_TCS; prio++) {
if (ets->prio_tc[prio] == i)
mask |= (1 << prio);
}
mask &= 0xff;
netif_dbg(pdata, drv, pdata->netdev, "TC%u PRIO mask=%#x\n",
i, mask);
reg = MTL_TCPM0R + (MTL_TCPM_INC * (i / MTL_TCPM_TC_PER_REG));
reg_val = XGMAC_IOREAD(pdata, reg);
reg_val &= ~(0xff << ((i % MTL_TCPM_TC_PER_REG) << 3));
reg_val |= (mask << ((i % MTL_TCPM_TC_PER_REG) << 3));
XGMAC_IOWRITE(pdata, reg, reg_val);
switch (ets->tc_tsa[i]) {
case IEEE_8021QAZ_TSA_STRICT:
netif_dbg(pdata, drv, pdata->netdev,
"TC%u using SP\n", i);
XGMAC_MTL_IOWRITE_BITS(pdata, i, MTL_TC_ETSCR, TSA,
MTL_TSA_SP);
break;
case IEEE_8021QAZ_TSA_ETS:
weight = total_weight * ets->tc_tx_bw[i] / 100;
weight = clamp(weight, min_weight, total_weight);
netif_dbg(pdata, drv, pdata->netdev,
"TC%u using DWRR (weight %u)\n", i, weight);
XGMAC_MTL_IOWRITE_BITS(pdata, i, MTL_TC_ETSCR, TSA,
MTL_TSA_ETS);
XGMAC_MTL_IOWRITE_BITS(pdata, i, MTL_TC_QWR, QW,
weight);
break;
}
}
xgbe_config_tc(pdata);
}
static void xgbe_config_dcb_pfc(struct xgbe_prv_data *pdata)
{
if (!test_bit(XGBE_DOWN, &pdata->dev_state)) {
netif_tx_stop_all_queues(pdata->netdev);
pdata->hw_if.disable_rx(pdata);
}
xgbe_config_rx_fifo_size(pdata);
xgbe_config_flow_control(pdata);
if (!test_bit(XGBE_DOWN, &pdata->dev_state)) {
pdata->hw_if.enable_rx(pdata);
netif_tx_start_all_queues(pdata->netdev);
}
}
static void xgbe_config_mac_address(struct xgbe_prv_data *pdata)
{
xgbe_set_mac_address(pdata, pdata->netdev->dev_addr);
if (pdata->hw_feat.hash_table_size) {
XGMAC_IOWRITE_BITS(pdata, MAC_PFR, HPF, 1);
XGMAC_IOWRITE_BITS(pdata, MAC_PFR, HUC, 1);
XGMAC_IOWRITE_BITS(pdata, MAC_PFR, HMC, 1);
}
}
static void xgbe_config_jumbo_enable(struct xgbe_prv_data *pdata)
{
unsigned int val;
val = (pdata->netdev->mtu > XGMAC_STD_PACKET_MTU) ? 1 : 0;
XGMAC_IOWRITE_BITS(pdata, MAC_RCR, JE, val);
}
static void xgbe_config_mac_speed(struct xgbe_prv_data *pdata)
{
xgbe_set_speed(pdata, pdata->phy_speed);
}
static void xgbe_config_checksum_offload(struct xgbe_prv_data *pdata)
{
if (pdata->netdev->features & NETIF_F_RXCSUM)
xgbe_enable_rx_csum(pdata);
else
xgbe_disable_rx_csum(pdata);
}
static void xgbe_config_vlan_support(struct xgbe_prv_data *pdata)
{
XGMAC_IOWRITE_BITS(pdata, MAC_VLANIR, CSVL, 0);
XGMAC_IOWRITE_BITS(pdata, MAC_VLANIR, VLTI, 1);
xgbe_update_vlan_hash_table(pdata);
if (pdata->netdev->features & NETIF_F_HW_VLAN_CTAG_FILTER)
xgbe_enable_rx_vlan_filtering(pdata);
else
xgbe_disable_rx_vlan_filtering(pdata);
if (pdata->netdev->features & NETIF_F_HW_VLAN_CTAG_RX)
xgbe_enable_rx_vlan_stripping(pdata);
else
xgbe_disable_rx_vlan_stripping(pdata);
}
static u64 xgbe_mmc_read(struct xgbe_prv_data *pdata, unsigned int reg_lo)
{
bool read_hi;
u64 val;
if (pdata->vdata->mmc_64bit) {
switch (reg_lo) {
case MMC_RXRUNTERROR:
case MMC_RXJABBERERROR:
case MMC_RXUNDERSIZE_G:
case MMC_RXOVERSIZE_G:
case MMC_RXWATCHDOGERROR:
read_hi = false;
break;
default:
read_hi = true;
}
} else {
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
}
val = XGMAC_IOREAD(pdata, reg_lo);
if (read_hi)
val |= ((u64)XGMAC_IOREAD(pdata, reg_lo + 4) << 32);
return val;
}
static void xgbe_tx_mmc_int(struct xgbe_prv_data *pdata)
{
struct xgbe_mmc_stats *stats = &pdata->mmc_stats;
unsigned int mmc_isr = XGMAC_IOREAD(pdata, MMC_TISR);
if (XGMAC_GET_BITS(mmc_isr, MMC_TISR, TXOCTETCOUNT_GB))
stats->txoctetcount_gb +=
xgbe_mmc_read(pdata, MMC_TXOCTETCOUNT_GB_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_TISR, TXFRAMECOUNT_GB))
stats->txframecount_gb +=
xgbe_mmc_read(pdata, MMC_TXFRAMECOUNT_GB_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_TISR, TXBROADCASTFRAMES_G))
stats->txbroadcastframes_g +=
xgbe_mmc_read(pdata, MMC_TXBROADCASTFRAMES_G_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_TISR, TXMULTICASTFRAMES_G))
stats->txmulticastframes_g +=
xgbe_mmc_read(pdata, MMC_TXMULTICASTFRAMES_G_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_TISR, TX64OCTETS_GB))
stats->tx64octets_gb +=
xgbe_mmc_read(pdata, MMC_TX64OCTETS_GB_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_TISR, TX65TO127OCTETS_GB))
stats->tx65to127octets_gb +=
xgbe_mmc_read(pdata, MMC_TX65TO127OCTETS_GB_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_TISR, TX128TO255OCTETS_GB))
stats->tx128to255octets_gb +=
xgbe_mmc_read(pdata, MMC_TX128TO255OCTETS_GB_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_TISR, TX256TO511OCTETS_GB))
stats->tx256to511octets_gb +=
xgbe_mmc_read(pdata, MMC_TX256TO511OCTETS_GB_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_TISR, TX512TO1023OCTETS_GB))
stats->tx512to1023octets_gb +=
xgbe_mmc_read(pdata, MMC_TX512TO1023OCTETS_GB_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_TISR, TX1024TOMAXOCTETS_GB))
stats->tx1024tomaxoctets_gb +=
xgbe_mmc_read(pdata, MMC_TX1024TOMAXOCTETS_GB_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_TISR, TXUNICASTFRAMES_GB))
stats->txunicastframes_gb +=
xgbe_mmc_read(pdata, MMC_TXUNICASTFRAMES_GB_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_TISR, TXMULTICASTFRAMES_GB))
stats->txmulticastframes_gb +=
xgbe_mmc_read(pdata, MMC_TXMULTICASTFRAMES_GB_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_TISR, TXBROADCASTFRAMES_GB))
stats->txbroadcastframes_g +=
xgbe_mmc_read(pdata, MMC_TXBROADCASTFRAMES_GB_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_TISR, TXUNDERFLOWERROR))
stats->txunderflowerror +=
xgbe_mmc_read(pdata, MMC_TXUNDERFLOWERROR_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_TISR, TXOCTETCOUNT_G))
stats->txoctetcount_g +=
xgbe_mmc_read(pdata, MMC_TXOCTETCOUNT_G_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_TISR, TXFRAMECOUNT_G))
stats->txframecount_g +=
xgbe_mmc_read(pdata, MMC_TXFRAMECOUNT_G_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_TISR, TXPAUSEFRAMES))
stats->txpauseframes +=
xgbe_mmc_read(pdata, MMC_TXPAUSEFRAMES_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_TISR, TXVLANFRAMES_G))
stats->txvlanframes_g +=
xgbe_mmc_read(pdata, MMC_TXVLANFRAMES_G_LO);
}
static void xgbe_rx_mmc_int(struct xgbe_prv_data *pdata)
{
struct xgbe_mmc_stats *stats = &pdata->mmc_stats;
unsigned int mmc_isr = XGMAC_IOREAD(pdata, MMC_RISR);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RXFRAMECOUNT_GB))
stats->rxframecount_gb +=
xgbe_mmc_read(pdata, MMC_RXFRAMECOUNT_GB_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RXOCTETCOUNT_GB))
stats->rxoctetcount_gb +=
xgbe_mmc_read(pdata, MMC_RXOCTETCOUNT_GB_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RXOCTETCOUNT_G))
stats->rxoctetcount_g +=
xgbe_mmc_read(pdata, MMC_RXOCTETCOUNT_G_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RXBROADCASTFRAMES_G))
stats->rxbroadcastframes_g +=
xgbe_mmc_read(pdata, MMC_RXBROADCASTFRAMES_G_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RXMULTICASTFRAMES_G))
stats->rxmulticastframes_g +=
xgbe_mmc_read(pdata, MMC_RXMULTICASTFRAMES_G_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RXCRCERROR))
stats->rxcrcerror +=
xgbe_mmc_read(pdata, MMC_RXCRCERROR_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RXRUNTERROR))
stats->rxrunterror +=
xgbe_mmc_read(pdata, MMC_RXRUNTERROR);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RXJABBERERROR))
stats->rxjabbererror +=
xgbe_mmc_read(pdata, MMC_RXJABBERERROR);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RXUNDERSIZE_G))
stats->rxundersize_g +=
xgbe_mmc_read(pdata, MMC_RXUNDERSIZE_G);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RXOVERSIZE_G))
stats->rxoversize_g +=
xgbe_mmc_read(pdata, MMC_RXOVERSIZE_G);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RX64OCTETS_GB))
stats->rx64octets_gb +=
xgbe_mmc_read(pdata, MMC_RX64OCTETS_GB_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RX65TO127OCTETS_GB))
stats->rx65to127octets_gb +=
xgbe_mmc_read(pdata, MMC_RX65TO127OCTETS_GB_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RX128TO255OCTETS_GB))
stats->rx128to255octets_gb +=
xgbe_mmc_read(pdata, MMC_RX128TO255OCTETS_GB_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RX256TO511OCTETS_GB))
stats->rx256to511octets_gb +=
xgbe_mmc_read(pdata, MMC_RX256TO511OCTETS_GB_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RX512TO1023OCTETS_GB))
stats->rx512to1023octets_gb +=
xgbe_mmc_read(pdata, MMC_RX512TO1023OCTETS_GB_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RX1024TOMAXOCTETS_GB))
stats->rx1024tomaxoctets_gb +=
xgbe_mmc_read(pdata, MMC_RX1024TOMAXOCTETS_GB_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RXUNICASTFRAMES_G))
stats->rxunicastframes_g +=
xgbe_mmc_read(pdata, MMC_RXUNICASTFRAMES_G_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RXLENGTHERROR))
stats->rxlengtherror +=
xgbe_mmc_read(pdata, MMC_RXLENGTHERROR_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RXOUTOFRANGETYPE))
stats->rxoutofrangetype +=
xgbe_mmc_read(pdata, MMC_RXOUTOFRANGETYPE_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RXPAUSEFRAMES))
stats->rxpauseframes +=
xgbe_mmc_read(pdata, MMC_RXPAUSEFRAMES_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RXFIFOOVERFLOW))
stats->rxfifooverflow +=
xgbe_mmc_read(pdata, MMC_RXFIFOOVERFLOW_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RXVLANFRAMES_GB))
stats->rxvlanframes_gb +=
xgbe_mmc_read(pdata, MMC_RXVLANFRAMES_GB_LO);
if (XGMAC_GET_BITS(mmc_isr, MMC_RISR, RXWATCHDOGERROR))
stats->rxwatchdogerror +=
xgbe_mmc_read(pdata, MMC_RXWATCHDOGERROR);
}
static void xgbe_read_mmc_stats(struct xgbe_prv_data *pdata)
{
struct xgbe_mmc_stats *stats = &pdata->mmc_stats;
XGMAC_IOWRITE_BITS(pdata, MMC_CR, MCF, 1);
stats->txoctetcount_gb +=
xgbe_mmc_read(pdata, MMC_TXOCTETCOUNT_GB_LO);
stats->txframecount_gb +=
xgbe_mmc_read(pdata, MMC_TXFRAMECOUNT_GB_LO);
stats->txbroadcastframes_g +=
xgbe_mmc_read(pdata, MMC_TXBROADCASTFRAMES_G_LO);
stats->txmulticastframes_g +=
xgbe_mmc_read(pdata, MMC_TXMULTICASTFRAMES_G_LO);
stats->tx64octets_gb +=
xgbe_mmc_read(pdata, MMC_TX64OCTETS_GB_LO);
stats->tx65to127octets_gb +=
xgbe_mmc_read(pdata, MMC_TX65TO127OCTETS_GB_LO);
stats->tx128to255octets_gb +=
xgbe_mmc_read(pdata, MMC_TX128TO255OCTETS_GB_LO);
stats->tx256to511octets_gb +=
xgbe_mmc_read(pdata, MMC_TX256TO511OCTETS_GB_LO);
stats->tx512to1023octets_gb +=
xgbe_mmc_read(pdata, MMC_TX512TO1023OCTETS_GB_LO);
stats->tx1024tomaxoctets_gb +=
xgbe_mmc_read(pdata, MMC_TX1024TOMAXOCTETS_GB_LO);
stats->txunicastframes_gb +=
xgbe_mmc_read(pdata, MMC_TXUNICASTFRAMES_GB_LO);
stats->txmulticastframes_gb +=
xgbe_mmc_read(pdata, MMC_TXMULTICASTFRAMES_GB_LO);
stats->txbroadcastframes_g +=
xgbe_mmc_read(pdata, MMC_TXBROADCASTFRAMES_GB_LO);
stats->txunderflowerror +=
xgbe_mmc_read(pdata, MMC_TXUNDERFLOWERROR_LO);
stats->txoctetcount_g +=
xgbe_mmc_read(pdata, MMC_TXOCTETCOUNT_G_LO);
stats->txframecount_g +=
xgbe_mmc_read(pdata, MMC_TXFRAMECOUNT_G_LO);
stats->txpauseframes +=
xgbe_mmc_read(pdata, MMC_TXPAUSEFRAMES_LO);
stats->txvlanframes_g +=
xgbe_mmc_read(pdata, MMC_TXVLANFRAMES_G_LO);
stats->rxframecount_gb +=
xgbe_mmc_read(pdata, MMC_RXFRAMECOUNT_GB_LO);
stats->rxoctetcount_gb +=
xgbe_mmc_read(pdata, MMC_RXOCTETCOUNT_GB_LO);
stats->rxoctetcount_g +=
xgbe_mmc_read(pdata, MMC_RXOCTETCOUNT_G_LO);
stats->rxbroadcastframes_g +=
xgbe_mmc_read(pdata, MMC_RXBROADCASTFRAMES_G_LO);
stats->rxmulticastframes_g +=
xgbe_mmc_read(pdata, MMC_RXMULTICASTFRAMES_G_LO);
stats->rxcrcerror +=
xgbe_mmc_read(pdata, MMC_RXCRCERROR_LO);
stats->rxrunterror +=
xgbe_mmc_read(pdata, MMC_RXRUNTERROR);
stats->rxjabbererror +=
xgbe_mmc_read(pdata, MMC_RXJABBERERROR);
stats->rxundersize_g +=
xgbe_mmc_read(pdata, MMC_RXUNDERSIZE_G);
stats->rxoversize_g +=
xgbe_mmc_read(pdata, MMC_RXOVERSIZE_G);
stats->rx64octets_gb +=
xgbe_mmc_read(pdata, MMC_RX64OCTETS_GB_LO);
stats->rx65to127octets_gb +=
xgbe_mmc_read(pdata, MMC_RX65TO127OCTETS_GB_LO);
stats->rx128to255octets_gb +=
xgbe_mmc_read(pdata, MMC_RX128TO255OCTETS_GB_LO);
stats->rx256to511octets_gb +=
xgbe_mmc_read(pdata, MMC_RX256TO511OCTETS_GB_LO);
stats->rx512to1023octets_gb +=
xgbe_mmc_read(pdata, MMC_RX512TO1023OCTETS_GB_LO);
stats->rx1024tomaxoctets_gb +=
xgbe_mmc_read(pdata, MMC_RX1024TOMAXOCTETS_GB_LO);
stats->rxunicastframes_g +=
xgbe_mmc_read(pdata, MMC_RXUNICASTFRAMES_G_LO);
stats->rxlengtherror +=
xgbe_mmc_read(pdata, MMC_RXLENGTHERROR_LO);
stats->rxoutofrangetype +=
xgbe_mmc_read(pdata, MMC_RXOUTOFRANGETYPE_LO);
stats->rxpauseframes +=
xgbe_mmc_read(pdata, MMC_RXPAUSEFRAMES_LO);
stats->rxfifooverflow +=
xgbe_mmc_read(pdata, MMC_RXFIFOOVERFLOW_LO);
stats->rxvlanframes_gb +=
xgbe_mmc_read(pdata, MMC_RXVLANFRAMES_GB_LO);
stats->rxwatchdogerror +=
xgbe_mmc_read(pdata, MMC_RXWATCHDOGERROR);
XGMAC_IOWRITE_BITS(pdata, MMC_CR, MCF, 0);
}
static void xgbe_config_mmc(struct xgbe_prv_data *pdata)
{
XGMAC_IOWRITE_BITS(pdata, MMC_CR, ROR, 1);
XGMAC_IOWRITE_BITS(pdata, MMC_CR, CR, 1);
}
static void xgbe_txq_prepare_tx_stop(struct xgbe_prv_data *pdata,
unsigned int queue)
{
unsigned int tx_status;
unsigned long tx_timeout;
tx_timeout = jiffies + (XGBE_DMA_STOP_TIMEOUT * HZ);
while (time_before(jiffies, tx_timeout)) {
tx_status = XGMAC_MTL_IOREAD(pdata, queue, MTL_Q_TQDR);
if ((XGMAC_GET_BITS(tx_status, MTL_Q_TQDR, TRCSTS) != 1) &&
(XGMAC_GET_BITS(tx_status, MTL_Q_TQDR, TXQSTS) == 0))
break;
usleep_range(500, 1000);
}
if (!time_before(jiffies, tx_timeout))
netdev_info(pdata->netdev,
"timed out waiting for Tx queue %u to empty\n",
queue);
}
static void xgbe_prepare_tx_stop(struct xgbe_prv_data *pdata,
unsigned int queue)
{
unsigned int tx_dsr, tx_pos, tx_qidx;
unsigned int tx_status;
unsigned long tx_timeout;
if (XGMAC_GET_BITS(pdata->hw_feat.version, MAC_VR, SNPSVER) > 0x20)
return xgbe_txq_prepare_tx_stop(pdata, queue);
if (queue < DMA_DSRX_FIRST_QUEUE) {
tx_dsr = DMA_DSR0;
tx_pos = (queue * DMA_DSR_Q_WIDTH) + DMA_DSR0_TPS_START;
} else {
tx_qidx = queue - DMA_DSRX_FIRST_QUEUE;
tx_dsr = DMA_DSR1 + ((tx_qidx / DMA_DSRX_QPR) * DMA_DSRX_INC);
tx_pos = ((tx_qidx % DMA_DSRX_QPR) * DMA_DSR_Q_WIDTH) +
DMA_DSRX_TPS_START;
}
tx_timeout = jiffies + (XGBE_DMA_STOP_TIMEOUT * HZ);
while (time_before(jiffies, tx_timeout)) {
tx_status = XGMAC_IOREAD(pdata, tx_dsr);
tx_status = GET_BITS(tx_status, tx_pos, DMA_DSR_TPS_WIDTH);
if ((tx_status == DMA_TPS_STOPPED) ||
(tx_status == DMA_TPS_SUSPENDED))
break;
usleep_range(500, 1000);
}
if (!time_before(jiffies, tx_timeout))
netdev_info(pdata->netdev,
"timed out waiting for Tx DMA channel %u to stop\n",
queue);
}
static void xgbe_enable_tx(struct xgbe_prv_data *pdata)
{
struct xgbe_channel *channel;
unsigned int i;
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->tx_ring)
break;
XGMAC_DMA_IOWRITE_BITS(channel, DMA_CH_TCR, ST, 1);
}
for (i = 0; i < pdata->tx_q_count; i++)
XGMAC_MTL_IOWRITE_BITS(pdata, i, MTL_Q_TQOMR, TXQEN,
MTL_Q_ENABLED);
XGMAC_IOWRITE_BITS(pdata, MAC_TCR, TE, 1);
}
static void xgbe_disable_tx(struct xgbe_prv_data *pdata)
{
struct xgbe_channel *channel;
unsigned int i;
for (i = 0; i < pdata->tx_q_count; i++)
xgbe_prepare_tx_stop(pdata, i);
XGMAC_IOWRITE_BITS(pdata, MAC_TCR, TE, 0);
for (i = 0; i < pdata->tx_q_count; i++)
XGMAC_MTL_IOWRITE_BITS(pdata, i, MTL_Q_TQOMR, TXQEN, 0);
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->tx_ring)
break;
XGMAC_DMA_IOWRITE_BITS(channel, DMA_CH_TCR, ST, 0);
}
}
static void xgbe_prepare_rx_stop(struct xgbe_prv_data *pdata,
unsigned int queue)
{
unsigned int rx_status;
unsigned long rx_timeout;
rx_timeout = jiffies + (XGBE_DMA_STOP_TIMEOUT * HZ);
while (time_before(jiffies, rx_timeout)) {
rx_status = XGMAC_MTL_IOREAD(pdata, queue, MTL_Q_RQDR);
if ((XGMAC_GET_BITS(rx_status, MTL_Q_RQDR, PRXQ) == 0) &&
(XGMAC_GET_BITS(rx_status, MTL_Q_RQDR, RXQSTS) == 0))
break;
usleep_range(500, 1000);
}
if (!time_before(jiffies, rx_timeout))
netdev_info(pdata->netdev,
"timed out waiting for Rx queue %u to empty\n",
queue);
}
static void xgbe_enable_rx(struct xgbe_prv_data *pdata)
{
struct xgbe_channel *channel;
unsigned int reg_val, i;
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->rx_ring)
break;
XGMAC_DMA_IOWRITE_BITS(channel, DMA_CH_RCR, SR, 1);
}
reg_val = 0;
for (i = 0; i < pdata->rx_q_count; i++)
reg_val |= (0x02 << (i << 1));
XGMAC_IOWRITE(pdata, MAC_RQC0R, reg_val);
XGMAC_IOWRITE_BITS(pdata, MAC_RCR, DCRCC, 1);
XGMAC_IOWRITE_BITS(pdata, MAC_RCR, CST, 1);
XGMAC_IOWRITE_BITS(pdata, MAC_RCR, ACS, 1);
XGMAC_IOWRITE_BITS(pdata, MAC_RCR, RE, 1);
}
static void xgbe_disable_rx(struct xgbe_prv_data *pdata)
{
struct xgbe_channel *channel;
unsigned int i;
XGMAC_IOWRITE_BITS(pdata, MAC_RCR, DCRCC, 0);
XGMAC_IOWRITE_BITS(pdata, MAC_RCR, CST, 0);
XGMAC_IOWRITE_BITS(pdata, MAC_RCR, ACS, 0);
XGMAC_IOWRITE_BITS(pdata, MAC_RCR, RE, 0);
for (i = 0; i < pdata->rx_q_count; i++)
xgbe_prepare_rx_stop(pdata, i);
XGMAC_IOWRITE(pdata, MAC_RQC0R, 0);
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->rx_ring)
break;
XGMAC_DMA_IOWRITE_BITS(channel, DMA_CH_RCR, SR, 0);
}
}
static void xgbe_powerup_tx(struct xgbe_prv_data *pdata)
{
struct xgbe_channel *channel;
unsigned int i;
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->tx_ring)
break;
XGMAC_DMA_IOWRITE_BITS(channel, DMA_CH_TCR, ST, 1);
}
XGMAC_IOWRITE_BITS(pdata, MAC_TCR, TE, 1);
}
static void xgbe_powerdown_tx(struct xgbe_prv_data *pdata)
{
struct xgbe_channel *channel;
unsigned int i;
for (i = 0; i < pdata->tx_q_count; i++)
xgbe_prepare_tx_stop(pdata, i);
XGMAC_IOWRITE_BITS(pdata, MAC_TCR, TE, 0);
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->tx_ring)
break;
XGMAC_DMA_IOWRITE_BITS(channel, DMA_CH_TCR, ST, 0);
}
}
static void xgbe_powerup_rx(struct xgbe_prv_data *pdata)
{
struct xgbe_channel *channel;
unsigned int i;
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->rx_ring)
break;
XGMAC_DMA_IOWRITE_BITS(channel, DMA_CH_RCR, SR, 1);
}
}
static void xgbe_powerdown_rx(struct xgbe_prv_data *pdata)
{
struct xgbe_channel *channel;
unsigned int i;
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->rx_ring)
break;
XGMAC_DMA_IOWRITE_BITS(channel, DMA_CH_RCR, SR, 0);
}
}
static int xgbe_init(struct xgbe_prv_data *pdata)
{
struct xgbe_desc_if *desc_if = &pdata->desc_if;
int ret;
DBGPR("-->xgbe_init\n");
ret = xgbe_flush_tx_queues(pdata);
if (ret) {
netdev_err(pdata->netdev, "error flushing TX queues\n");
return ret;
}
xgbe_config_dma_bus(pdata);
xgbe_config_dma_cache(pdata);
xgbe_config_osp_mode(pdata);
xgbe_config_pblx8(pdata);
xgbe_config_tx_pbl_val(pdata);
xgbe_config_rx_pbl_val(pdata);
xgbe_config_rx_coalesce(pdata);
xgbe_config_tx_coalesce(pdata);
xgbe_config_rx_buffer_size(pdata);
xgbe_config_tso_mode(pdata);
xgbe_config_sph_mode(pdata);
xgbe_config_rss(pdata);
desc_if->wrapper_tx_desc_init(pdata);
desc_if->wrapper_rx_desc_init(pdata);
xgbe_enable_dma_interrupts(pdata);
xgbe_config_mtl_mode(pdata);
xgbe_config_queue_mapping(pdata);
xgbe_config_tsf_mode(pdata, pdata->tx_sf_mode);
xgbe_config_rsf_mode(pdata, pdata->rx_sf_mode);
xgbe_config_tx_threshold(pdata, pdata->tx_threshold);
xgbe_config_rx_threshold(pdata, pdata->rx_threshold);
xgbe_config_tx_fifo_size(pdata);
xgbe_config_rx_fifo_size(pdata);
xgbe_config_dcb_tc(pdata);
xgbe_enable_mtl_interrupts(pdata);
xgbe_config_mac_address(pdata);
xgbe_config_rx_mode(pdata);
xgbe_config_jumbo_enable(pdata);
xgbe_config_flow_control(pdata);
xgbe_config_mac_speed(pdata);
xgbe_config_checksum_offload(pdata);
xgbe_config_vlan_support(pdata);
xgbe_config_mmc(pdata);
xgbe_enable_mac_interrupts(pdata);
xgbe_enable_ecc_interrupts(pdata);
DBGPR("<--xgbe_init\n");
return 0;
}
void xgbe_init_function_ptrs_dev(struct xgbe_hw_if *hw_if)
{
DBGPR("-->xgbe_init_function_ptrs\n");
hw_if->tx_complete = xgbe_tx_complete;
hw_if->set_mac_address = xgbe_set_mac_address;
hw_if->config_rx_mode = xgbe_config_rx_mode;
hw_if->enable_rx_csum = xgbe_enable_rx_csum;
hw_if->disable_rx_csum = xgbe_disable_rx_csum;
hw_if->enable_rx_vlan_stripping = xgbe_enable_rx_vlan_stripping;
hw_if->disable_rx_vlan_stripping = xgbe_disable_rx_vlan_stripping;
hw_if->enable_rx_vlan_filtering = xgbe_enable_rx_vlan_filtering;
hw_if->disable_rx_vlan_filtering = xgbe_disable_rx_vlan_filtering;
hw_if->update_vlan_hash_table = xgbe_update_vlan_hash_table;
hw_if->read_mmd_regs = xgbe_read_mmd_regs;
hw_if->write_mmd_regs = xgbe_write_mmd_regs;
hw_if->set_speed = xgbe_set_speed;
hw_if->set_ext_mii_mode = xgbe_set_ext_mii_mode;
hw_if->read_ext_mii_regs = xgbe_read_ext_mii_regs;
hw_if->write_ext_mii_regs = xgbe_write_ext_mii_regs;
hw_if->set_gpio = xgbe_set_gpio;
hw_if->clr_gpio = xgbe_clr_gpio;
hw_if->enable_tx = xgbe_enable_tx;
hw_if->disable_tx = xgbe_disable_tx;
hw_if->enable_rx = xgbe_enable_rx;
hw_if->disable_rx = xgbe_disable_rx;
hw_if->powerup_tx = xgbe_powerup_tx;
hw_if->powerdown_tx = xgbe_powerdown_tx;
hw_if->powerup_rx = xgbe_powerup_rx;
hw_if->powerdown_rx = xgbe_powerdown_rx;
hw_if->dev_xmit = xgbe_dev_xmit;
hw_if->dev_read = xgbe_dev_read;
hw_if->enable_int = xgbe_enable_int;
hw_if->disable_int = xgbe_disable_int;
hw_if->init = xgbe_init;
hw_if->exit = xgbe_exit;
hw_if->tx_desc_init = xgbe_tx_desc_init;
hw_if->rx_desc_init = xgbe_rx_desc_init;
hw_if->tx_desc_reset = xgbe_tx_desc_reset;
hw_if->rx_desc_reset = xgbe_rx_desc_reset;
hw_if->is_last_desc = xgbe_is_last_desc;
hw_if->is_context_desc = xgbe_is_context_desc;
hw_if->tx_start_xmit = xgbe_tx_start_xmit;
hw_if->config_tx_flow_control = xgbe_config_tx_flow_control;
hw_if->config_rx_flow_control = xgbe_config_rx_flow_control;
hw_if->config_rx_coalesce = xgbe_config_rx_coalesce;
hw_if->config_tx_coalesce = xgbe_config_tx_coalesce;
hw_if->usec_to_riwt = xgbe_usec_to_riwt;
hw_if->riwt_to_usec = xgbe_riwt_to_usec;
hw_if->config_rx_threshold = xgbe_config_rx_threshold;
hw_if->config_tx_threshold = xgbe_config_tx_threshold;
hw_if->config_rsf_mode = xgbe_config_rsf_mode;
hw_if->config_tsf_mode = xgbe_config_tsf_mode;
hw_if->config_osp_mode = xgbe_config_osp_mode;
hw_if->config_rx_pbl_val = xgbe_config_rx_pbl_val;
hw_if->get_rx_pbl_val = xgbe_get_rx_pbl_val;
hw_if->config_tx_pbl_val = xgbe_config_tx_pbl_val;
hw_if->get_tx_pbl_val = xgbe_get_tx_pbl_val;
hw_if->config_pblx8 = xgbe_config_pblx8;
hw_if->tx_mmc_int = xgbe_tx_mmc_int;
hw_if->rx_mmc_int = xgbe_rx_mmc_int;
hw_if->read_mmc_stats = xgbe_read_mmc_stats;
hw_if->config_tstamp = xgbe_config_tstamp;
hw_if->update_tstamp_addend = xgbe_update_tstamp_addend;
hw_if->set_tstamp_time = xgbe_set_tstamp_time;
hw_if->get_tstamp_time = xgbe_get_tstamp_time;
hw_if->get_tx_tstamp = xgbe_get_tx_tstamp;
hw_if->config_tc = xgbe_config_tc;
hw_if->config_dcb_tc = xgbe_config_dcb_tc;
hw_if->config_dcb_pfc = xgbe_config_dcb_pfc;
hw_if->enable_rss = xgbe_enable_rss;
hw_if->disable_rss = xgbe_disable_rss;
hw_if->set_rss_hash_key = xgbe_set_rss_hash_key;
hw_if->set_rss_lookup_table = xgbe_set_rss_lookup_table;
hw_if->disable_ecc_ded = xgbe_disable_ecc_ded;
hw_if->disable_ecc_sec = xgbe_disable_ecc_sec;
DBGPR("<--xgbe_init_function_ptrs\n");
}
