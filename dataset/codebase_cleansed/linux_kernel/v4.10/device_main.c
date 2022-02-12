static void vt6655_remove(struct pci_dev *pcid)
{
struct vnt_private *priv = pci_get_drvdata(pcid);
if (priv == NULL)
return;
device_free_info(priv);
}
static void device_get_options(struct vnt_private *priv)
{
struct vnt_options *opts = &priv->opts;
opts->rx_descs0 = RX_DESC_DEF0;
opts->rx_descs1 = RX_DESC_DEF1;
opts->tx_descs[0] = TX_DESC_DEF0;
opts->tx_descs[1] = TX_DESC_DEF1;
opts->int_works = INT_WORKS_DEF;
opts->short_retry = SHORT_RETRY_DEF;
opts->long_retry = LONG_RETRY_DEF;
opts->bbp_type = BBP_TYPE_DEF;
}
static void
device_set_options(struct vnt_private *priv)
{
priv->byShortRetryLimit = priv->opts.short_retry;
priv->byLongRetryLimit = priv->opts.long_retry;
priv->byBBType = priv->opts.bbp_type;
priv->byPacketType = priv->byBBType;
priv->byAutoFBCtrl = AUTO_FB_0;
priv->bUpdateBBVGA = true;
priv->byPreambleType = 0;
pr_debug(" byShortRetryLimit= %d\n", (int)priv->byShortRetryLimit);
pr_debug(" byLongRetryLimit= %d\n", (int)priv->byLongRetryLimit);
pr_debug(" byPreambleType= %d\n", (int)priv->byPreambleType);
pr_debug(" byShortPreamble= %d\n", (int)priv->byShortPreamble);
pr_debug(" byBBType= %d\n", (int)priv->byBBType);
}
static void device_init_registers(struct vnt_private *priv)
{
unsigned long flags;
unsigned int ii;
unsigned char byValue;
unsigned char byCCKPwrdBm = 0;
unsigned char byOFDMPwrdBm = 0;
MACbShutdown(priv);
BBvSoftwareReset(priv);
MACbSoftwareReset(priv);
priv->bAES = false;
priv->bProtectMode = false;
priv->bNonERPPresent = false;
priv->bBarkerPreambleMd = false;
priv->wCurrentRate = RATE_1M;
priv->byTopOFDMBasicRate = RATE_24M;
priv->byTopCCKBasicRate = RATE_1M;
MACvInitialize(priv);
VNSvInPortB(priv->PortOffset + MAC_REG_LOCALID, &priv->byLocalID);
spin_lock_irqsave(&priv->lock, flags);
SROMvReadAllContents(priv->PortOffset, priv->abyEEPROM);
spin_unlock_irqrestore(&priv->lock, flags);
priv->byMinChannel = 1;
priv->byMaxChannel = CB_MAX_CHANNEL;
byValue = SROMbyReadEmbedded(priv->PortOffset, EEP_OFS_ANTENNA);
if (byValue & EEP_ANTINV)
priv->bTxRxAntInv = true;
else
priv->bTxRxAntInv = false;
byValue &= (EEP_ANTENNA_AUX | EEP_ANTENNA_MAIN);
if (byValue == 0)
byValue = (EEP_ANTENNA_AUX | EEP_ANTENNA_MAIN);
if (byValue == (EEP_ANTENNA_AUX | EEP_ANTENNA_MAIN)) {
priv->byAntennaCount = 2;
priv->byTxAntennaMode = ANT_B;
priv->dwTxAntennaSel = 1;
priv->dwRxAntennaSel = 1;
if (priv->bTxRxAntInv)
priv->byRxAntennaMode = ANT_A;
else
priv->byRxAntennaMode = ANT_B;
} else {
priv->byAntennaCount = 1;
priv->dwTxAntennaSel = 0;
priv->dwRxAntennaSel = 0;
if (byValue & EEP_ANTENNA_AUX) {
priv->byTxAntennaMode = ANT_A;
if (priv->bTxRxAntInv)
priv->byRxAntennaMode = ANT_B;
else
priv->byRxAntennaMode = ANT_A;
} else {
priv->byTxAntennaMode = ANT_B;
if (priv->bTxRxAntInv)
priv->byRxAntennaMode = ANT_A;
else
priv->byRxAntennaMode = ANT_B;
}
}
BBvSetTxAntennaMode(priv, priv->byTxAntennaMode);
BBvSetRxAntennaMode(priv, priv->byRxAntennaMode);
priv->byOriginalZonetype = priv->abyEEPROM[EEP_OFS_ZONETYPE];
if (!priv->bZoneRegExist)
priv->byZoneType = priv->abyEEPROM[EEP_OFS_ZONETYPE];
pr_debug("priv->byZoneType = %x\n", priv->byZoneType);
RFbInit(priv);
priv->byCurPwr = 0xFF;
priv->byCCKPwr = SROMbyReadEmbedded(priv->PortOffset, EEP_OFS_PWR_CCK);
priv->byOFDMPwrG = SROMbyReadEmbedded(priv->PortOffset, EEP_OFS_PWR_OFDMG);
for (ii = 0; ii < CB_MAX_CHANNEL_24G; ii++) {
priv->abyCCKPwrTbl[ii + 1] =
SROMbyReadEmbedded(priv->PortOffset,
(unsigned char)(ii + EEP_OFS_CCK_PWR_TBL));
if (priv->abyCCKPwrTbl[ii + 1] == 0)
priv->abyCCKPwrTbl[ii + 1] = priv->byCCKPwr;
priv->abyOFDMPwrTbl[ii + 1] =
SROMbyReadEmbedded(priv->PortOffset,
(unsigned char)(ii + EEP_OFS_OFDM_PWR_TBL));
if (priv->abyOFDMPwrTbl[ii + 1] == 0)
priv->abyOFDMPwrTbl[ii + 1] = priv->byOFDMPwrG;
priv->abyCCKDefaultPwr[ii + 1] = byCCKPwrdBm;
priv->abyOFDMDefaultPwr[ii + 1] = byOFDMPwrdBm;
}
for (ii = 11; ii < 14; ii++) {
priv->abyCCKPwrTbl[ii] = priv->abyCCKPwrTbl[10];
priv->abyOFDMPwrTbl[ii] = priv->abyOFDMPwrTbl[10];
}
for (ii = 0; ii < CB_MAX_CHANNEL_5G; ii++) {
priv->abyOFDMPwrTbl[ii + CB_MAX_CHANNEL_24G + 1] =
SROMbyReadEmbedded(priv->PortOffset,
(unsigned char)(ii + EEP_OFS_OFDMA_PWR_TBL));
priv->abyOFDMDefaultPwr[ii + CB_MAX_CHANNEL_24G + 1] =
SROMbyReadEmbedded(priv->PortOffset,
(unsigned char)(ii + EEP_OFS_OFDMA_PWR_dBm));
}
if (priv->byLocalID > REV_ID_VT3253_B1) {
MACvSelectPage1(priv->PortOffset);
VNSvOutPortB(priv->PortOffset + MAC_REG_MSRCTL + 1,
(MSRCTL1_TXPWR | MSRCTL1_CSAPAREN));
MACvSelectPage0(priv->PortOffset);
}
MACvWordRegBitsOn(priv->PortOffset,
MAC_REG_CFG, (CFG_TKIPOPT | CFG_NOTXTIMEOUT));
MACvSetShortRetryLimit(priv, priv->byShortRetryLimit);
MACvSetLongRetryLimit(priv, priv->byLongRetryLimit);
VNSvOutPortB(priv->PortOffset + MAC_REG_TFTCTL, TFTCTL_TSFCNTRST);
VNSvOutPortB(priv->PortOffset + MAC_REG_TFTCTL, TFTCTL_TSFCNTREN);
BBbVT3253Init(priv);
if (priv->bUpdateBBVGA) {
priv->byBBVGACurrent = priv->abyBBVGA[0];
priv->byBBVGANew = priv->byBBVGACurrent;
BBvSetVGAGainOffset(priv, priv->abyBBVGA[0]);
}
BBvSetRxAntennaMode(priv, priv->byRxAntennaMode);
BBvSetTxAntennaMode(priv, priv->byTxAntennaMode);
priv->wCurrentRate = RATE_54M;
priv->bRadioOff = false;
priv->byRadioCtl = SROMbyReadEmbedded(priv->PortOffset,
EEP_OFS_RADIOCTL);
priv->bHWRadioOff = false;
if (priv->byRadioCtl & EEP_RADIOCTL_ENABLE) {
MACvGPIOIn(priv->PortOffset, &priv->byGPIO);
if (((priv->byGPIO & GPIO0_DATA) &&
!(priv->byRadioCtl & EEP_RADIOCTL_INV)) ||
(!(priv->byGPIO & GPIO0_DATA) &&
(priv->byRadioCtl & EEP_RADIOCTL_INV)))
priv->bHWRadioOff = true;
}
if (priv->bHWRadioOff || priv->bRadioControlOff)
CARDbRadioPowerOff(priv);
SROMvReadEtherAddress(priv->PortOffset, priv->abyCurrentNetAddr);
pr_debug("Network address = %pM\n", priv->abyCurrentNetAddr);
CARDvSafeResetRx(priv);
CARDvSafeResetTx(priv);
if (priv->byLocalID <= REV_ID_VT3253_A1)
MACvRegBitsOn(priv->PortOffset, MAC_REG_RCR, RCR_WPAERR);
MACvReceive0(priv->PortOffset);
MACvReceive1(priv->PortOffset);
MACvStart(priv->PortOffset);
}
static void device_print_info(struct vnt_private *priv)
{
dev_info(&priv->pcid->dev, "MAC=%pM IO=0x%lx Mem=0x%lx IRQ=%d\n",
priv->abyCurrentNetAddr, (unsigned long)priv->ioaddr,
(unsigned long)priv->PortOffset, priv->pcid->irq);
}
static void device_free_info(struct vnt_private *priv)
{
if (!priv)
return;
if (priv->mac_hw)
ieee80211_unregister_hw(priv->hw);
if (priv->PortOffset)
iounmap(priv->PortOffset);
if (priv->pcid)
pci_release_regions(priv->pcid);
if (priv->hw)
ieee80211_free_hw(priv->hw);
}
static bool device_init_rings(struct vnt_private *priv)
{
void *vir_pool;
vir_pool = dma_zalloc_coherent(&priv->pcid->dev,
priv->opts.rx_descs0 * sizeof(struct vnt_rx_desc) +
priv->opts.rx_descs1 * sizeof(struct vnt_rx_desc) +
priv->opts.tx_descs[0] * sizeof(struct vnt_tx_desc) +
priv->opts.tx_descs[1] * sizeof(struct vnt_tx_desc),
&priv->pool_dma, GFP_ATOMIC);
if (vir_pool == NULL) {
dev_err(&priv->pcid->dev, "allocate desc dma memory failed\n");
return false;
}
priv->aRD0Ring = vir_pool;
priv->aRD1Ring = vir_pool +
priv->opts.rx_descs0 * sizeof(struct vnt_rx_desc);
priv->rd0_pool_dma = priv->pool_dma;
priv->rd1_pool_dma = priv->rd0_pool_dma +
priv->opts.rx_descs0 * sizeof(struct vnt_rx_desc);
priv->tx0_bufs = dma_zalloc_coherent(&priv->pcid->dev,
priv->opts.tx_descs[0] * PKT_BUF_SZ +
priv->opts.tx_descs[1] * PKT_BUF_SZ +
CB_BEACON_BUF_SIZE +
CB_MAX_BUF_SIZE,
&priv->tx_bufs_dma0,
GFP_ATOMIC);
if (!priv->tx0_bufs) {
dev_err(&priv->pcid->dev, "allocate buf dma memory failed\n");
dma_free_coherent(&priv->pcid->dev,
priv->opts.rx_descs0 * sizeof(struct vnt_rx_desc) +
priv->opts.rx_descs1 * sizeof(struct vnt_rx_desc) +
priv->opts.tx_descs[0] * sizeof(struct vnt_tx_desc) +
priv->opts.tx_descs[1] * sizeof(struct vnt_tx_desc),
vir_pool, priv->pool_dma);
return false;
}
priv->td0_pool_dma = priv->rd1_pool_dma +
priv->opts.rx_descs1 * sizeof(struct vnt_rx_desc);
priv->td1_pool_dma = priv->td0_pool_dma +
priv->opts.tx_descs[0] * sizeof(struct vnt_tx_desc);
priv->apTD0Rings = vir_pool
+ priv->opts.rx_descs0 * sizeof(struct vnt_rx_desc)
+ priv->opts.rx_descs1 * sizeof(struct vnt_rx_desc);
priv->apTD1Rings = vir_pool
+ priv->opts.rx_descs0 * sizeof(struct vnt_rx_desc)
+ priv->opts.rx_descs1 * sizeof(struct vnt_rx_desc)
+ priv->opts.tx_descs[0] * sizeof(struct vnt_tx_desc);
priv->tx1_bufs = priv->tx0_bufs +
priv->opts.tx_descs[0] * PKT_BUF_SZ;
priv->tx_beacon_bufs = priv->tx1_bufs +
priv->opts.tx_descs[1] * PKT_BUF_SZ;
priv->pbyTmpBuff = priv->tx_beacon_bufs +
CB_BEACON_BUF_SIZE;
priv->tx_bufs_dma1 = priv->tx_bufs_dma0 +
priv->opts.tx_descs[0] * PKT_BUF_SZ;
priv->tx_beacon_dma = priv->tx_bufs_dma1 +
priv->opts.tx_descs[1] * PKT_BUF_SZ;
return true;
}
static void device_free_rings(struct vnt_private *priv)
{
dma_free_coherent(&priv->pcid->dev,
priv->opts.rx_descs0 * sizeof(struct vnt_rx_desc) +
priv->opts.rx_descs1 * sizeof(struct vnt_rx_desc) +
priv->opts.tx_descs[0] * sizeof(struct vnt_tx_desc) +
priv->opts.tx_descs[1] * sizeof(struct vnt_tx_desc),
priv->aRD0Ring, priv->pool_dma);
if (priv->tx0_bufs)
dma_free_coherent(&priv->pcid->dev,
priv->opts.tx_descs[0] * PKT_BUF_SZ +
priv->opts.tx_descs[1] * PKT_BUF_SZ +
CB_BEACON_BUF_SIZE +
CB_MAX_BUF_SIZE,
priv->tx0_bufs, priv->tx_bufs_dma0);
}
static void device_init_rd0_ring(struct vnt_private *priv)
{
int i;
dma_addr_t curr = priv->rd0_pool_dma;
struct vnt_rx_desc *desc;
for (i = 0; i < priv->opts.rx_descs0;
i ++, curr += sizeof(struct vnt_rx_desc)) {
desc = &priv->aRD0Ring[i];
desc->rd_info = kzalloc(sizeof(*desc->rd_info), GFP_ATOMIC);
if (!device_alloc_rx_buf(priv, desc))
dev_err(&priv->pcid->dev, "can not alloc rx bufs\n");
desc->next = &(priv->aRD0Ring[(i + 1) % priv->opts.rx_descs0]);
desc->next_desc = cpu_to_le32(curr + sizeof(struct vnt_rx_desc));
}
if (i > 0)
priv->aRD0Ring[i-1].next_desc = cpu_to_le32(priv->rd0_pool_dma);
priv->pCurrRD[0] = &priv->aRD0Ring[0];
}
static void device_init_rd1_ring(struct vnt_private *priv)
{
int i;
dma_addr_t curr = priv->rd1_pool_dma;
struct vnt_rx_desc *desc;
for (i = 0; i < priv->opts.rx_descs1;
i ++, curr += sizeof(struct vnt_rx_desc)) {
desc = &priv->aRD1Ring[i];
desc->rd_info = kzalloc(sizeof(*desc->rd_info), GFP_ATOMIC);
if (!device_alloc_rx_buf(priv, desc))
dev_err(&priv->pcid->dev, "can not alloc rx bufs\n");
desc->next = &(priv->aRD1Ring[(i+1) % priv->opts.rx_descs1]);
desc->next_desc = cpu_to_le32(curr + sizeof(struct vnt_rx_desc));
}
if (i > 0)
priv->aRD1Ring[i-1].next_desc = cpu_to_le32(priv->rd1_pool_dma);
priv->pCurrRD[1] = &priv->aRD1Ring[0];
}
static void device_free_rd0_ring(struct vnt_private *priv)
{
int i;
for (i = 0; i < priv->opts.rx_descs0; i++) {
struct vnt_rx_desc *desc = &(priv->aRD0Ring[i]);
struct vnt_rd_info *rd_info = desc->rd_info;
dma_unmap_single(&priv->pcid->dev, rd_info->skb_dma,
priv->rx_buf_sz, DMA_FROM_DEVICE);
dev_kfree_skb(rd_info->skb);
kfree(desc->rd_info);
}
}
static void device_free_rd1_ring(struct vnt_private *priv)
{
int i;
for (i = 0; i < priv->opts.rx_descs1; i++) {
struct vnt_rx_desc *desc = &priv->aRD1Ring[i];
struct vnt_rd_info *rd_info = desc->rd_info;
dma_unmap_single(&priv->pcid->dev, rd_info->skb_dma,
priv->rx_buf_sz, DMA_FROM_DEVICE);
dev_kfree_skb(rd_info->skb);
kfree(desc->rd_info);
}
}
static void device_init_td0_ring(struct vnt_private *priv)
{
int i;
dma_addr_t curr;
struct vnt_tx_desc *desc;
curr = priv->td0_pool_dma;
for (i = 0; i < priv->opts.tx_descs[0];
i++, curr += sizeof(struct vnt_tx_desc)) {
desc = &priv->apTD0Rings[i];
desc->td_info = kzalloc(sizeof(*desc->td_info), GFP_ATOMIC);
desc->td_info->buf = priv->tx0_bufs + i * PKT_BUF_SZ;
desc->td_info->buf_dma = priv->tx_bufs_dma0 + i * PKT_BUF_SZ;
desc->next = &(priv->apTD0Rings[(i+1) % priv->opts.tx_descs[0]]);
desc->next_desc = cpu_to_le32(curr + sizeof(struct vnt_tx_desc));
}
if (i > 0)
priv->apTD0Rings[i-1].next_desc = cpu_to_le32(priv->td0_pool_dma);
priv->apTailTD[0] = priv->apCurrTD[0] = &priv->apTD0Rings[0];
}
static void device_init_td1_ring(struct vnt_private *priv)
{
int i;
dma_addr_t curr;
struct vnt_tx_desc *desc;
curr = priv->td1_pool_dma;
for (i = 0; i < priv->opts.tx_descs[1];
i++, curr += sizeof(struct vnt_tx_desc)) {
desc = &priv->apTD1Rings[i];
desc->td_info = kzalloc(sizeof(*desc->td_info), GFP_ATOMIC);
desc->td_info->buf = priv->tx1_bufs + i * PKT_BUF_SZ;
desc->td_info->buf_dma = priv->tx_bufs_dma1 + i * PKT_BUF_SZ;
desc->next = &(priv->apTD1Rings[(i + 1) % priv->opts.tx_descs[1]]);
desc->next_desc = cpu_to_le32(curr + sizeof(struct vnt_tx_desc));
}
if (i > 0)
priv->apTD1Rings[i-1].next_desc = cpu_to_le32(priv->td1_pool_dma);
priv->apTailTD[1] = priv->apCurrTD[1] = &priv->apTD1Rings[0];
}
static void device_free_td0_ring(struct vnt_private *priv)
{
int i;
for (i = 0; i < priv->opts.tx_descs[0]; i++) {
struct vnt_tx_desc *desc = &priv->apTD0Rings[i];
struct vnt_td_info *td_info = desc->td_info;
dev_kfree_skb(td_info->skb);
kfree(desc->td_info);
}
}
static void device_free_td1_ring(struct vnt_private *priv)
{
int i;
for (i = 0; i < priv->opts.tx_descs[1]; i++) {
struct vnt_tx_desc *desc = &priv->apTD1Rings[i];
struct vnt_td_info *td_info = desc->td_info;
dev_kfree_skb(td_info->skb);
kfree(desc->td_info);
}
}
static int device_rx_srv(struct vnt_private *priv, unsigned int idx)
{
struct vnt_rx_desc *rd;
int works = 0;
for (rd = priv->pCurrRD[idx];
rd->rd0.owner == OWNED_BY_HOST;
rd = rd->next) {
if (works++ > 15)
break;
if (!rd->rd_info->skb)
break;
if (vnt_receive_frame(priv, rd)) {
if (!device_alloc_rx_buf(priv, rd)) {
dev_err(&priv->pcid->dev,
"can not allocate rx buf\n");
break;
}
}
rd->rd0.owner = OWNED_BY_NIC;
}
priv->pCurrRD[idx] = rd;
return works;
}
static bool device_alloc_rx_buf(struct vnt_private *priv,
struct vnt_rx_desc *rd)
{
struct vnt_rd_info *rd_info = rd->rd_info;
rd_info->skb = dev_alloc_skb((int)priv->rx_buf_sz);
if (!rd_info->skb)
return false;
rd_info->skb_dma =
dma_map_single(&priv->pcid->dev,
skb_put(rd_info->skb, skb_tailroom(rd_info->skb)),
priv->rx_buf_sz, DMA_FROM_DEVICE);
if (dma_mapping_error(&priv->pcid->dev, rd_info->skb_dma)) {
dev_kfree_skb(rd_info->skb);
rd_info->skb = NULL;
return false;
}
*((unsigned int *)&rd->rd0) = 0;
rd->rd0.res_count = cpu_to_le16(priv->rx_buf_sz);
rd->rd0.owner = OWNED_BY_NIC;
rd->rd1.req_count = cpu_to_le16(priv->rx_buf_sz);
rd->buff_addr = cpu_to_le32(rd_info->skb_dma);
return true;
}
static int vnt_int_report_rate(struct vnt_private *priv,
struct vnt_td_info *context, u8 tsr0, u8 tsr1)
{
struct vnt_tx_fifo_head *fifo_head;
struct ieee80211_tx_info *info;
struct ieee80211_rate *rate;
u16 fb_option;
u8 tx_retry = (tsr0 & TSR0_NCR);
s8 idx;
if (!context)
return -ENOMEM;
if (!context->skb)
return -EINVAL;
fifo_head = (struct vnt_tx_fifo_head *)context->buf;
fb_option = (le16_to_cpu(fifo_head->fifo_ctl) &
(FIFOCTL_AUTO_FB_0 | FIFOCTL_AUTO_FB_1));
info = IEEE80211_SKB_CB(context->skb);
idx = info->control.rates[0].idx;
if (fb_option && !(tsr1 & TSR1_TERR)) {
u8 tx_rate;
u8 retry = tx_retry;
rate = ieee80211_get_tx_rate(priv->hw, info);
tx_rate = rate->hw_value - RATE_18M;
if (retry > 4)
retry = 4;
if (fb_option & FIFOCTL_AUTO_FB_0)
tx_rate = fallback_rate0[tx_rate][retry];
else if (fb_option & FIFOCTL_AUTO_FB_1)
tx_rate = fallback_rate1[tx_rate][retry];
if (info->band == NL80211_BAND_5GHZ)
idx = tx_rate - RATE_6M;
else
idx = tx_rate;
}
ieee80211_tx_info_clear_status(info);
info->status.rates[0].count = tx_retry;
if (!(tsr1 & TSR1_TERR)) {
info->status.rates[0].idx = idx;
if (info->flags & IEEE80211_TX_CTL_NO_ACK)
info->flags |= IEEE80211_TX_STAT_NOACK_TRANSMITTED;
else
info->flags |= IEEE80211_TX_STAT_ACK;
}
return 0;
}
static int device_tx_srv(struct vnt_private *priv, unsigned int idx)
{
struct vnt_tx_desc *desc;
int works = 0;
unsigned char byTsr0;
unsigned char byTsr1;
for (desc = priv->apTailTD[idx]; priv->iTDUsed[idx] > 0; desc = desc->next) {
if (desc->td0.owner == OWNED_BY_NIC)
break;
if (works++ > 15)
break;
byTsr0 = desc->td0.tsr0;
byTsr1 = desc->td0.tsr1;
if (desc->td1.tcr & TCR_STP) {
if ((desc->td_info->flags & TD_FLAGS_NETIF_SKB) != 0) {
if (!(byTsr1 & TSR1_TERR)) {
if (byTsr0 != 0) {
pr_debug(" Tx[%d] OK but has error. tsr1[%02X] tsr0[%02X]\n",
(int)idx, byTsr1,
byTsr0);
}
} else {
pr_debug(" Tx[%d] dropped & tsr1[%02X] tsr0[%02X]\n",
(int)idx, byTsr1, byTsr0);
}
}
if (byTsr1 & TSR1_TERR) {
if ((desc->td_info->flags & TD_FLAGS_PRIV_SKB) != 0) {
pr_debug(" Tx[%d] fail has error. tsr1[%02X] tsr0[%02X]\n",
(int)idx, byTsr1, byTsr0);
}
}
vnt_int_report_rate(priv, desc->td_info, byTsr0, byTsr1);
device_free_tx_buf(priv, desc);
priv->iTDUsed[idx]--;
}
}
priv->apTailTD[idx] = desc;
return works;
}
static void device_error(struct vnt_private *priv, unsigned short status)
{
if (status & ISR_FETALERR) {
dev_err(&priv->pcid->dev, "Hardware fatal error\n");
MACbShutdown(priv);
return;
}
}
static void device_free_tx_buf(struct vnt_private *priv,
struct vnt_tx_desc *desc)
{
struct vnt_td_info *td_info = desc->td_info;
struct sk_buff *skb = td_info->skb;
if (skb)
ieee80211_tx_status_irqsafe(priv->hw, skb);
td_info->skb = NULL;
td_info->flags = 0;
}
static void vnt_check_bb_vga(struct vnt_private *priv)
{
long dbm;
int i;
if (!priv->bUpdateBBVGA)
return;
if (priv->hw->conf.flags & IEEE80211_CONF_OFFCHANNEL)
return;
if (!(priv->vif->bss_conf.assoc && priv->uCurrRSSI))
return;
RFvRSSITodBm(priv, (u8)priv->uCurrRSSI, &dbm);
for (i = 0; i < BB_VGA_LEVEL; i++) {
if (dbm < priv->ldBmThreshold[i]) {
priv->byBBVGANew = priv->abyBBVGA[i];
break;
}
}
if (priv->byBBVGANew == priv->byBBVGACurrent) {
priv->uBBVGADiffCount = 1;
return;
}
priv->uBBVGADiffCount++;
if (priv->uBBVGADiffCount == 1) {
BBvSetVGAGainOffset(priv, priv->byBBVGANew);
dev_dbg(&priv->pcid->dev,
"First RSSI[%d] NewGain[%d] OldGain[%d] Count[%d]\n",
(int)dbm, priv->byBBVGANew,
priv->byBBVGACurrent,
(int)priv->uBBVGADiffCount);
}
if (priv->uBBVGADiffCount >= BB_VGA_CHANGE_THRESHOLD) {
dev_dbg(&priv->pcid->dev,
"RSSI[%d] NewGain[%d] OldGain[%d] Count[%d]\n",
(int)dbm, priv->byBBVGANew,
priv->byBBVGACurrent,
(int)priv->uBBVGADiffCount);
BBvSetVGAGainOffset(priv, priv->byBBVGANew);
}
}
static void vnt_interrupt_process(struct vnt_private *priv)
{
struct ieee80211_low_level_stats *low_stats = &priv->low_stats;
int max_count = 0;
u32 mib_counter;
u32 isr;
unsigned long flags;
MACvReadISR(priv->PortOffset, &isr);
if (isr == 0)
return;
if (isr == 0xffffffff) {
pr_debug("isr = 0xffff\n");
return;
}
MACvIntDisable(priv->PortOffset);
spin_lock_irqsave(&priv->lock, flags);
MACvReadMIBCounter(priv->PortOffset, &mib_counter);
low_stats->dot11RTSSuccessCount += mib_counter & 0xff;
low_stats->dot11RTSFailureCount += (mib_counter >> 8) & 0xff;
low_stats->dot11ACKFailureCount += (mib_counter >> 16) & 0xff;
low_stats->dot11FCSErrorCount += (mib_counter >> 24) & 0xff;
while (isr && priv->vif) {
MACvWriteISR(priv->PortOffset, isr);
if (isr & ISR_FETALERR) {
pr_debug(" ISR_FETALERR\n");
VNSvOutPortB(priv->PortOffset + MAC_REG_SOFTPWRCTL, 0);
VNSvOutPortW(priv->PortOffset +
MAC_REG_SOFTPWRCTL, SOFTPWRCTL_SWPECTI);
device_error(priv, isr);
}
if (isr & ISR_TBTT) {
if (priv->op_mode != NL80211_IFTYPE_ADHOC)
vnt_check_bb_vga(priv);
priv->bBeaconSent = false;
if (priv->bEnablePSMode)
PSbIsNextTBTTWakeUp((void *)priv);
if ((priv->op_mode == NL80211_IFTYPE_AP ||
priv->op_mode == NL80211_IFTYPE_ADHOC) &&
priv->vif->bss_conf.enable_beacon) {
MACvOneShotTimer1MicroSec(priv,
(priv->vif->bss_conf.beacon_int - MAKE_BEACON_RESERVED) << 10);
}
}
if (isr & ISR_BNTX) {
if (priv->op_mode == NL80211_IFTYPE_ADHOC) {
priv->bIsBeaconBufReadySet = false;
priv->cbBeaconBufReadySetCnt = 0;
}
priv->bBeaconSent = true;
}
if (isr & ISR_RXDMA0)
max_count += device_rx_srv(priv, TYPE_RXDMA0);
if (isr & ISR_RXDMA1)
max_count += device_rx_srv(priv, TYPE_RXDMA1);
if (isr & ISR_TXDMA0)
max_count += device_tx_srv(priv, TYPE_TXDMA0);
if (isr & ISR_AC0DMA)
max_count += device_tx_srv(priv, TYPE_AC0DMA);
if (isr & ISR_SOFTTIMER1) {
if (priv->vif->bss_conf.enable_beacon)
vnt_beacon_make(priv, priv->vif);
}
if (AVAIL_TD(priv, TYPE_TXDMA0) &&
AVAIL_TD(priv, TYPE_AC0DMA) &&
ieee80211_queue_stopped(priv->hw, 0))
ieee80211_wake_queues(priv->hw);
MACvReadISR(priv->PortOffset, &isr);
MACvReceive0(priv->PortOffset);
MACvReceive1(priv->PortOffset);
if (max_count > priv->opts.int_works)
break;
}
spin_unlock_irqrestore(&priv->lock, flags);
MACvIntEnable(priv->PortOffset, IMR_MASK_VALUE);
}
static void vnt_interrupt_work(struct work_struct *work)
{
struct vnt_private *priv =
container_of(work, struct vnt_private, interrupt_work);
if (priv->vif)
vnt_interrupt_process(priv);
}
static irqreturn_t vnt_interrupt(int irq, void *arg)
{
struct vnt_private *priv = arg;
if (priv->vif)
schedule_work(&priv->interrupt_work);
return IRQ_HANDLED;
}
static int vnt_tx_packet(struct vnt_private *priv, struct sk_buff *skb)
{
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;
struct vnt_tx_desc *head_td;
u32 dma_idx;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
if (ieee80211_is_data(hdr->frame_control))
dma_idx = TYPE_AC0DMA;
else
dma_idx = TYPE_TXDMA0;
if (AVAIL_TD(priv, dma_idx) < 1) {
spin_unlock_irqrestore(&priv->lock, flags);
ieee80211_stop_queues(priv->hw);
return -ENOMEM;
}
head_td = priv->apCurrTD[dma_idx];
head_td->td1.tcr = 0;
head_td->td_info->skb = skb;
if (dma_idx == TYPE_AC0DMA)
head_td->td_info->flags = TD_FLAGS_NETIF_SKB;
priv->apCurrTD[dma_idx] = head_td->next;
spin_unlock_irqrestore(&priv->lock, flags);
vnt_generate_fifo_header(priv, dma_idx, head_td, skb);
spin_lock_irqsave(&priv->lock, flags);
priv->bPWBitOn = false;
head_td->td1.tcr |= (TCR_STP | TCR_EDP | EDMSDU);
head_td->td1.req_count = cpu_to_le16(head_td->td_info->req_count);
head_td->buff_addr = cpu_to_le32(head_td->td_info->buf_dma);
wmb();
head_td->td0.owner = OWNED_BY_NIC;
wmb();
if (head_td->td_info->flags & TD_FLAGS_NETIF_SKB)
MACvTransmitAC0(priv->PortOffset);
else
MACvTransmit0(priv->PortOffset);
priv->iTDUsed[dma_idx]++;
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
static void vnt_tx_80211(struct ieee80211_hw *hw,
struct ieee80211_tx_control *control,
struct sk_buff *skb)
{
struct vnt_private *priv = hw->priv;
if (vnt_tx_packet(priv, skb))
ieee80211_free_txskb(hw, skb);
}
static int vnt_start(struct ieee80211_hw *hw)
{
struct vnt_private *priv = hw->priv;
int ret;
priv->rx_buf_sz = PKT_BUF_SZ;
if (!device_init_rings(priv))
return -ENOMEM;
ret = request_irq(priv->pcid->irq, vnt_interrupt,
IRQF_SHARED, "vt6655", priv);
if (ret) {
dev_dbg(&priv->pcid->dev, "failed to start irq\n");
return ret;
}
dev_dbg(&priv->pcid->dev, "call device init rd0 ring\n");
device_init_rd0_ring(priv);
device_init_rd1_ring(priv);
device_init_td0_ring(priv);
device_init_td1_ring(priv);
device_init_registers(priv);
dev_dbg(&priv->pcid->dev, "call MACvIntEnable\n");
MACvIntEnable(priv->PortOffset, IMR_MASK_VALUE);
ieee80211_wake_queues(hw);
return 0;
}
static void vnt_stop(struct ieee80211_hw *hw)
{
struct vnt_private *priv = hw->priv;
ieee80211_stop_queues(hw);
cancel_work_sync(&priv->interrupt_work);
MACbShutdown(priv);
MACbSoftwareReset(priv);
CARDbRadioPowerOff(priv);
device_free_td0_ring(priv);
device_free_td1_ring(priv);
device_free_rd0_ring(priv);
device_free_rd1_ring(priv);
device_free_rings(priv);
free_irq(priv->pcid->irq, priv);
}
static int vnt_add_interface(struct ieee80211_hw *hw, struct ieee80211_vif *vif)
{
struct vnt_private *priv = hw->priv;
priv->vif = vif;
switch (vif->type) {
case NL80211_IFTYPE_STATION:
break;
case NL80211_IFTYPE_ADHOC:
MACvRegBitsOff(priv->PortOffset, MAC_REG_RCR, RCR_UNICAST);
MACvRegBitsOn(priv->PortOffset, MAC_REG_HOSTCR, HOSTCR_ADHOC);
break;
case NL80211_IFTYPE_AP:
MACvRegBitsOff(priv->PortOffset, MAC_REG_RCR, RCR_UNICAST);
MACvRegBitsOn(priv->PortOffset, MAC_REG_HOSTCR, HOSTCR_AP);
break;
default:
return -EOPNOTSUPP;
}
priv->op_mode = vif->type;
return 0;
}
static void vnt_remove_interface(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
struct vnt_private *priv = hw->priv;
switch (vif->type) {
case NL80211_IFTYPE_STATION:
break;
case NL80211_IFTYPE_ADHOC:
MACvRegBitsOff(priv->PortOffset, MAC_REG_TCR, TCR_AUTOBCNTX);
MACvRegBitsOff(priv->PortOffset,
MAC_REG_TFTCTL, TFTCTL_TSFCNTREN);
MACvRegBitsOff(priv->PortOffset, MAC_REG_HOSTCR, HOSTCR_ADHOC);
break;
case NL80211_IFTYPE_AP:
MACvRegBitsOff(priv->PortOffset, MAC_REG_TCR, TCR_AUTOBCNTX);
MACvRegBitsOff(priv->PortOffset,
MAC_REG_TFTCTL, TFTCTL_TSFCNTREN);
MACvRegBitsOff(priv->PortOffset, MAC_REG_HOSTCR, HOSTCR_AP);
break;
default:
break;
}
priv->op_mode = NL80211_IFTYPE_UNSPECIFIED;
}
static int vnt_config(struct ieee80211_hw *hw, u32 changed)
{
struct vnt_private *priv = hw->priv;
struct ieee80211_conf *conf = &hw->conf;
u8 bb_type;
if (changed & IEEE80211_CONF_CHANGE_PS) {
if (conf->flags & IEEE80211_CONF_PS)
PSvEnablePowerSaving(priv, conf->listen_interval);
else
PSvDisablePowerSaving(priv);
}
if ((changed & IEEE80211_CONF_CHANGE_CHANNEL) ||
(conf->flags & IEEE80211_CONF_OFFCHANNEL)) {
set_channel(priv, conf->chandef.chan);
if (conf->chandef.chan->band == NL80211_BAND_5GHZ)
bb_type = BB_TYPE_11A;
else
bb_type = BB_TYPE_11G;
if (priv->byBBType != bb_type) {
priv->byBBType = bb_type;
CARDbSetPhyParameter(priv, priv->byBBType);
}
}
if (changed & IEEE80211_CONF_CHANGE_POWER) {
if (priv->byBBType == BB_TYPE_11B)
priv->wCurrentRate = RATE_1M;
else
priv->wCurrentRate = RATE_54M;
RFbSetPower(priv, priv->wCurrentRate,
conf->chandef.chan->hw_value);
}
return 0;
}
static void vnt_bss_info_changed(struct ieee80211_hw *hw,
struct ieee80211_vif *vif, struct ieee80211_bss_conf *conf,
u32 changed)
{
struct vnt_private *priv = hw->priv;
priv->current_aid = conf->aid;
if (changed & BSS_CHANGED_BSSID && conf->bssid) {
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
MACvWriteBSSIDAddress(priv->PortOffset, (u8 *)conf->bssid);
spin_unlock_irqrestore(&priv->lock, flags);
}
if (changed & BSS_CHANGED_BASIC_RATES) {
priv->basic_rates = conf->basic_rates;
CARDvUpdateBasicTopRate(priv);
dev_dbg(&priv->pcid->dev,
"basic rates %x\n", conf->basic_rates);
}
if (changed & BSS_CHANGED_ERP_PREAMBLE) {
if (conf->use_short_preamble) {
MACvEnableBarkerPreambleMd(priv->PortOffset);
priv->byPreambleType = true;
} else {
MACvDisableBarkerPreambleMd(priv->PortOffset);
priv->byPreambleType = false;
}
}
if (changed & BSS_CHANGED_ERP_CTS_PROT) {
if (conf->use_cts_prot)
MACvEnableProtectMD(priv->PortOffset);
else
MACvDisableProtectMD(priv->PortOffset);
}
if (changed & BSS_CHANGED_ERP_SLOT) {
if (conf->use_short_slot)
priv->bShortSlotTime = true;
else
priv->bShortSlotTime = false;
CARDbSetPhyParameter(priv, priv->byBBType);
BBvSetVGAGainOffset(priv, priv->abyBBVGA[0]);
}
if (changed & BSS_CHANGED_TXPOWER)
RFbSetPower(priv, priv->wCurrentRate,
conf->chandef.chan->hw_value);
if (changed & BSS_CHANGED_BEACON_ENABLED) {
dev_dbg(&priv->pcid->dev,
"Beacon enable %d\n", conf->enable_beacon);
if (conf->enable_beacon) {
vnt_beacon_enable(priv, vif, conf);
MACvRegBitsOn(priv->PortOffset, MAC_REG_TCR,
TCR_AUTOBCNTX);
} else {
MACvRegBitsOff(priv->PortOffset, MAC_REG_TCR,
TCR_AUTOBCNTX);
}
}
if (changed & (BSS_CHANGED_ASSOC | BSS_CHANGED_BEACON_INFO) &&
priv->op_mode != NL80211_IFTYPE_AP) {
if (conf->assoc && conf->beacon_rate) {
CARDbUpdateTSF(priv, conf->beacon_rate->hw_value,
conf->sync_tsf);
CARDbSetBeaconPeriod(priv, conf->beacon_int);
CARDvSetFirstNextTBTT(priv, conf->beacon_int);
} else {
VNSvOutPortB(priv->PortOffset + MAC_REG_TFTCTL,
TFTCTL_TSFCNTRST);
VNSvOutPortB(priv->PortOffset + MAC_REG_TFTCTL,
TFTCTL_TSFCNTREN);
}
}
}
static u64 vnt_prepare_multicast(struct ieee80211_hw *hw,
struct netdev_hw_addr_list *mc_list)
{
struct vnt_private *priv = hw->priv;
struct netdev_hw_addr *ha;
u64 mc_filter = 0;
u32 bit_nr = 0;
netdev_hw_addr_list_for_each(ha, mc_list) {
bit_nr = ether_crc(ETH_ALEN, ha->addr) >> 26;
mc_filter |= 1ULL << (bit_nr & 0x3f);
}
priv->mc_list_count = mc_list->count;
return mc_filter;
}
static void vnt_configure(struct ieee80211_hw *hw,
unsigned int changed_flags, unsigned int *total_flags, u64 multicast)
{
struct vnt_private *priv = hw->priv;
u8 rx_mode = 0;
*total_flags &= FIF_ALLMULTI | FIF_OTHER_BSS | FIF_BCN_PRBRESP_PROMISC;
VNSvInPortB(priv->PortOffset + MAC_REG_RCR, &rx_mode);
dev_dbg(&priv->pcid->dev, "rx mode in = %x\n", rx_mode);
if (changed_flags & FIF_ALLMULTI) {
if (*total_flags & FIF_ALLMULTI) {
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
if (priv->mc_list_count > 2) {
MACvSelectPage1(priv->PortOffset);
VNSvOutPortD(priv->PortOffset +
MAC_REG_MAR0, 0xffffffff);
VNSvOutPortD(priv->PortOffset +
MAC_REG_MAR0 + 4, 0xffffffff);
MACvSelectPage0(priv->PortOffset);
} else {
MACvSelectPage1(priv->PortOffset);
VNSvOutPortD(priv->PortOffset +
MAC_REG_MAR0, (u32)multicast);
VNSvOutPortD(priv->PortOffset +
MAC_REG_MAR0 + 4,
(u32)(multicast >> 32));
MACvSelectPage0(priv->PortOffset);
}
spin_unlock_irqrestore(&priv->lock, flags);
rx_mode |= RCR_MULTICAST | RCR_BROADCAST;
} else {
rx_mode &= ~(RCR_MULTICAST | RCR_BROADCAST);
}
}
if (changed_flags & (FIF_OTHER_BSS | FIF_BCN_PRBRESP_PROMISC)) {
rx_mode |= RCR_MULTICAST | RCR_BROADCAST;
if (*total_flags & (FIF_OTHER_BSS | FIF_BCN_PRBRESP_PROMISC))
rx_mode &= ~RCR_BSSID;
else
rx_mode |= RCR_BSSID;
}
VNSvOutPortB(priv->PortOffset + MAC_REG_RCR, rx_mode);
dev_dbg(&priv->pcid->dev, "rx mode out= %x\n", rx_mode);
}
static int vnt_set_key(struct ieee80211_hw *hw, enum set_key_cmd cmd,
struct ieee80211_vif *vif, struct ieee80211_sta *sta,
struct ieee80211_key_conf *key)
{
struct vnt_private *priv = hw->priv;
switch (cmd) {
case SET_KEY:
if (vnt_set_keys(hw, sta, vif, key))
return -EOPNOTSUPP;
break;
case DISABLE_KEY:
if (test_bit(key->hw_key_idx, &priv->key_entry_inuse))
clear_bit(key->hw_key_idx, &priv->key_entry_inuse);
default:
break;
}
return 0;
}
static int vnt_get_stats(struct ieee80211_hw *hw,
struct ieee80211_low_level_stats *stats)
{
struct vnt_private *priv = hw->priv;
memcpy(stats, &priv->low_stats, sizeof(*stats));
return 0;
}
static u64 vnt_get_tsf(struct ieee80211_hw *hw, struct ieee80211_vif *vif)
{
struct vnt_private *priv = hw->priv;
u64 tsf;
CARDbGetCurrentTSF(priv, &tsf);
return tsf;
}
static void vnt_set_tsf(struct ieee80211_hw *hw, struct ieee80211_vif *vif,
u64 tsf)
{
struct vnt_private *priv = hw->priv;
CARDvUpdateNextTBTT(priv, tsf, vif->bss_conf.beacon_int);
}
static void vnt_reset_tsf(struct ieee80211_hw *hw, struct ieee80211_vif *vif)
{
struct vnt_private *priv = hw->priv;
VNSvOutPortB(priv->PortOffset + MAC_REG_TFTCTL, TFTCTL_TSFCNTRST);
}
static int vnt_init(struct vnt_private *priv)
{
SET_IEEE80211_PERM_ADDR(priv->hw, priv->abyCurrentNetAddr);
vnt_init_bands(priv);
if (ieee80211_register_hw(priv->hw))
return -ENODEV;
priv->mac_hw = true;
CARDbRadioPowerOff(priv);
return 0;
}
static int
vt6655_probe(struct pci_dev *pcid, const struct pci_device_id *ent)
{
struct vnt_private *priv;
struct ieee80211_hw *hw;
struct wiphy *wiphy;
int rc;
dev_notice(&pcid->dev,
"%s Ver. %s\n", DEVICE_FULL_DRV_NAM, DEVICE_VERSION);
dev_notice(&pcid->dev,
"Copyright (c) 2003 VIA Networking Technologies, Inc.\n");
hw = ieee80211_alloc_hw(sizeof(*priv), &vnt_mac_ops);
if (!hw) {
dev_err(&pcid->dev, "could not register ieee80211_hw\n");
return -ENOMEM;
}
priv = hw->priv;
priv->pcid = pcid;
spin_lock_init(&priv->lock);
priv->hw = hw;
SET_IEEE80211_DEV(priv->hw, &pcid->dev);
if (pci_enable_device(pcid)) {
device_free_info(priv);
return -ENODEV;
}
dev_dbg(&pcid->dev,
"Before get pci_info memaddr is %x\n", priv->memaddr);
pci_set_master(pcid);
priv->memaddr = pci_resource_start(pcid, 0);
priv->ioaddr = pci_resource_start(pcid, 1);
priv->PortOffset = ioremap(priv->memaddr & PCI_BASE_ADDRESS_MEM_MASK,
256);
if (!priv->PortOffset) {
dev_err(&pcid->dev, ": Failed to IO remapping ..\n");
device_free_info(priv);
return -ENODEV;
}
rc = pci_request_regions(pcid, DEVICE_NAME);
if (rc) {
dev_err(&pcid->dev, ": Failed to find PCI device\n");
device_free_info(priv);
return -ENODEV;
}
if (dma_set_mask(&pcid->dev, DMA_BIT_MASK(32))) {
dev_err(&pcid->dev, ": Failed to set dma 32 bit mask\n");
device_free_info(priv);
return -ENODEV;
}
INIT_WORK(&priv->interrupt_work, vnt_interrupt_work);
if (!MACbSoftwareReset(priv)) {
dev_err(&pcid->dev, ": Failed to access MAC hardware..\n");
device_free_info(priv);
return -ENODEV;
}
MACvInitialize(priv);
MACvReadEtherAddress(priv->PortOffset, priv->abyCurrentNetAddr);
priv->byRFType = SROMbyReadEmbedded(priv->PortOffset, EEP_OFS_RFTYPE);
priv->byRFType &= RF_MASK;
dev_dbg(&pcid->dev, "RF Type = %x\n", priv->byRFType);
device_get_options(priv);
device_set_options(priv);
wiphy = priv->hw->wiphy;
wiphy->frag_threshold = FRAG_THRESH_DEF;
wiphy->rts_threshold = RTS_THRESH_DEF;
wiphy->interface_modes = BIT(NL80211_IFTYPE_STATION) |
BIT(NL80211_IFTYPE_ADHOC) | BIT(NL80211_IFTYPE_AP);
ieee80211_hw_set(priv->hw, TIMING_BEACON_ONLY);
ieee80211_hw_set(priv->hw, SIGNAL_DBM);
ieee80211_hw_set(priv->hw, RX_INCLUDES_FCS);
ieee80211_hw_set(priv->hw, REPORTS_TX_ACK_STATUS);
ieee80211_hw_set(priv->hw, SUPPORTS_PS);
priv->hw->max_signal = 100;
if (vnt_init(priv))
return -ENODEV;
device_print_info(priv);
pci_set_drvdata(pcid, priv);
return 0;
}
static int vt6655_suspend(struct pci_dev *pcid, pm_message_t state)
{
struct vnt_private *priv = pci_get_drvdata(pcid);
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
pci_save_state(pcid);
MACbShutdown(priv);
pci_disable_device(pcid);
pci_set_power_state(pcid, pci_choose_state(pcid, state));
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
static int vt6655_resume(struct pci_dev *pcid)
{
pci_set_power_state(pcid, PCI_D0);
pci_enable_wake(pcid, PCI_D0, 0);
pci_restore_state(pcid);
return 0;
}
