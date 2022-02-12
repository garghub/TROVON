static char *get_chip_name(int chip_id)
{
int i;
for (i = 0; chip_info_table[i].name != NULL; i++)
if (chip_info_table[i].chip_id == chip_id)
break;
return chip_info_table[i].name;
}
static void vt6655_remove(struct pci_dev *pcid)
{
struct vnt_private *pDevice = pci_get_drvdata(pcid);
if (pDevice == NULL)
return;
device_free_info(pDevice);
}
static void device_get_options(struct vnt_private *pDevice)
{
POPTIONS pOpts = &(pDevice->sOpts);
pOpts->nRxDescs0 = RX_DESC_DEF0;
pOpts->nRxDescs1 = RX_DESC_DEF1;
pOpts->nTxDescs[0] = TX_DESC_DEF0;
pOpts->nTxDescs[1] = TX_DESC_DEF1;
pOpts->int_works = INT_WORKS_DEF;
pOpts->short_retry = SHORT_RETRY_DEF;
pOpts->long_retry = LONG_RETRY_DEF;
pOpts->bbp_type = BBP_TYPE_DEF;
}
static void
device_set_options(struct vnt_private *pDevice)
{
pDevice->byShortRetryLimit = pDevice->sOpts.short_retry;
pDevice->byLongRetryLimit = pDevice->sOpts.long_retry;
pDevice->byBBType = pDevice->sOpts.bbp_type;
pDevice->byPacketType = pDevice->byBBType;
pDevice->byAutoFBCtrl = AUTO_FB_0;
pDevice->bUpdateBBVGA = true;
pDevice->byPreambleType = 0;
pr_debug(" byShortRetryLimit= %d\n", (int)pDevice->byShortRetryLimit);
pr_debug(" byLongRetryLimit= %d\n", (int)pDevice->byLongRetryLimit);
pr_debug(" byPreambleType= %d\n", (int)pDevice->byPreambleType);
pr_debug(" byShortPreamble= %d\n", (int)pDevice->byShortPreamble);
pr_debug(" byBBType= %d\n", (int)pDevice->byBBType);
}
static void device_init_registers(struct vnt_private *pDevice)
{
unsigned long flags;
unsigned int ii;
unsigned char byValue;
unsigned char byCCKPwrdBm = 0;
unsigned char byOFDMPwrdBm = 0;
MACbShutdown(pDevice->PortOffset);
BBvSoftwareReset(pDevice);
MACbSoftwareReset(pDevice->PortOffset);
pDevice->bAES = false;
pDevice->bProtectMode = false;
pDevice->bNonERPPresent = false;
pDevice->bBarkerPreambleMd = false;
pDevice->wCurrentRate = RATE_1M;
pDevice->byTopOFDMBasicRate = RATE_24M;
pDevice->byTopCCKBasicRate = RATE_1M;
pDevice->byRevId = 0;
MACvInitialize(pDevice->PortOffset);
VNSvInPortB(pDevice->PortOffset + MAC_REG_LOCALID, &pDevice->byLocalID);
spin_lock_irqsave(&pDevice->lock, flags);
SROMvReadAllContents(pDevice->PortOffset, pDevice->abyEEPROM);
spin_unlock_irqrestore(&pDevice->lock, flags);
pDevice->byMinChannel = 1;
pDevice->byMaxChannel = CB_MAX_CHANNEL;
byValue = SROMbyReadEmbedded(pDevice->PortOffset, EEP_OFS_ANTENNA);
if (byValue & EEP_ANTINV)
pDevice->bTxRxAntInv = true;
else
pDevice->bTxRxAntInv = false;
byValue &= (EEP_ANTENNA_AUX | EEP_ANTENNA_MAIN);
if (byValue == 0)
byValue = (EEP_ANTENNA_AUX | EEP_ANTENNA_MAIN);
if (byValue == (EEP_ANTENNA_AUX | EEP_ANTENNA_MAIN)) {
pDevice->byAntennaCount = 2;
pDevice->byTxAntennaMode = ANT_B;
pDevice->dwTxAntennaSel = 1;
pDevice->dwRxAntennaSel = 1;
if (pDevice->bTxRxAntInv)
pDevice->byRxAntennaMode = ANT_A;
else
pDevice->byRxAntennaMode = ANT_B;
} else {
pDevice->byAntennaCount = 1;
pDevice->dwTxAntennaSel = 0;
pDevice->dwRxAntennaSel = 0;
if (byValue & EEP_ANTENNA_AUX) {
pDevice->byTxAntennaMode = ANT_A;
if (pDevice->bTxRxAntInv)
pDevice->byRxAntennaMode = ANT_B;
else
pDevice->byRxAntennaMode = ANT_A;
} else {
pDevice->byTxAntennaMode = ANT_B;
if (pDevice->bTxRxAntInv)
pDevice->byRxAntennaMode = ANT_A;
else
pDevice->byRxAntennaMode = ANT_B;
}
}
BBvSetTxAntennaMode(pDevice, pDevice->byTxAntennaMode);
BBvSetRxAntennaMode(pDevice, pDevice->byRxAntennaMode);
pDevice->byOriginalZonetype = pDevice->abyEEPROM[EEP_OFS_ZONETYPE];
if (!pDevice->bZoneRegExist)
pDevice->byZoneType = pDevice->abyEEPROM[EEP_OFS_ZONETYPE];
pr_debug("pDevice->byZoneType = %x\n", pDevice->byZoneType);
RFbInit(pDevice);
pDevice->byCurPwr = 0xFF;
pDevice->byCCKPwr = SROMbyReadEmbedded(pDevice->PortOffset, EEP_OFS_PWR_CCK);
pDevice->byOFDMPwrG = SROMbyReadEmbedded(pDevice->PortOffset, EEP_OFS_PWR_OFDMG);
for (ii = 0; ii < CB_MAX_CHANNEL_24G; ii++) {
pDevice->abyCCKPwrTbl[ii + 1] =
SROMbyReadEmbedded(pDevice->PortOffset,
(unsigned char)(ii + EEP_OFS_CCK_PWR_TBL));
if (pDevice->abyCCKPwrTbl[ii + 1] == 0)
pDevice->abyCCKPwrTbl[ii+1] = pDevice->byCCKPwr;
pDevice->abyOFDMPwrTbl[ii + 1] =
SROMbyReadEmbedded(pDevice->PortOffset,
(unsigned char)(ii + EEP_OFS_OFDM_PWR_TBL));
if (pDevice->abyOFDMPwrTbl[ii + 1] == 0)
pDevice->abyOFDMPwrTbl[ii + 1] = pDevice->byOFDMPwrG;
pDevice->abyCCKDefaultPwr[ii + 1] = byCCKPwrdBm;
pDevice->abyOFDMDefaultPwr[ii + 1] = byOFDMPwrdBm;
}
for (ii = 11; ii < 14; ii++) {
pDevice->abyCCKPwrTbl[ii] = pDevice->abyCCKPwrTbl[10];
pDevice->abyOFDMPwrTbl[ii] = pDevice->abyOFDMPwrTbl[10];
}
for (ii = 0; ii < CB_MAX_CHANNEL_5G; ii++) {
pDevice->abyOFDMPwrTbl[ii + CB_MAX_CHANNEL_24G + 1] =
SROMbyReadEmbedded(pDevice->PortOffset,
(unsigned char)(ii + EEP_OFS_OFDMA_PWR_TBL));
pDevice->abyOFDMDefaultPwr[ii + CB_MAX_CHANNEL_24G + 1] =
SROMbyReadEmbedded(pDevice->PortOffset,
(unsigned char)(ii + EEP_OFS_OFDMA_PWR_dBm));
}
if (pDevice->byLocalID > REV_ID_VT3253_B1) {
MACvSelectPage1(pDevice->PortOffset);
VNSvOutPortB(pDevice->PortOffset + MAC_REG_MSRCTL + 1,
(MSRCTL1_TXPWR | MSRCTL1_CSAPAREN));
MACvSelectPage0(pDevice->PortOffset);
}
MACvWordRegBitsOn(pDevice->PortOffset,
MAC_REG_CFG, (CFG_TKIPOPT | CFG_NOTXTIMEOUT));
MACvSetShortRetryLimit(pDevice->PortOffset, pDevice->byShortRetryLimit);
MACvSetLongRetryLimit(pDevice->PortOffset, pDevice->byLongRetryLimit);
VNSvOutPortB(pDevice->PortOffset + MAC_REG_TFTCTL, TFTCTL_TSFCNTRST);
VNSvOutPortB(pDevice->PortOffset + MAC_REG_TFTCTL, TFTCTL_TSFCNTREN);
BBbVT3253Init(pDevice);
if (pDevice->bUpdateBBVGA) {
pDevice->byBBVGACurrent = pDevice->abyBBVGA[0];
pDevice->byBBVGANew = pDevice->byBBVGACurrent;
BBvSetVGAGainOffset(pDevice, pDevice->abyBBVGA[0]);
}
BBvSetRxAntennaMode(pDevice, pDevice->byRxAntennaMode);
BBvSetTxAntennaMode(pDevice, pDevice->byTxAntennaMode);
pDevice->wCurrentRate = RATE_54M;
pDevice->bRadioOff = false;
pDevice->byRadioCtl = SROMbyReadEmbedded(pDevice->PortOffset,
EEP_OFS_RADIOCTL);
pDevice->bHWRadioOff = false;
if (pDevice->byRadioCtl & EEP_RADIOCTL_ENABLE) {
MACvGPIOIn(pDevice->PortOffset, &pDevice->byGPIO);
if (((pDevice->byGPIO & GPIO0_DATA) &&
!(pDevice->byRadioCtl & EEP_RADIOCTL_INV)) ||
(!(pDevice->byGPIO & GPIO0_DATA) &&
(pDevice->byRadioCtl & EEP_RADIOCTL_INV)))
pDevice->bHWRadioOff = true;
}
if (pDevice->bHWRadioOff || pDevice->bRadioControlOff)
CARDbRadioPowerOff(pDevice);
SROMvReadEtherAddress(pDevice->PortOffset, pDevice->abyCurrentNetAddr);
pr_debug("Network address = %pM\n", pDevice->abyCurrentNetAddr);
CARDvSafeResetRx(pDevice);
CARDvSafeResetTx(pDevice);
if (pDevice->byLocalID <= REV_ID_VT3253_A1)
MACvRegBitsOn(pDevice->PortOffset, MAC_REG_RCR, RCR_WPAERR);
MACvReceive0(pDevice->PortOffset);
MACvReceive1(pDevice->PortOffset);
MACvStart(pDevice->PortOffset);
}
static void device_print_info(struct vnt_private *pDevice)
{
dev_info(&pDevice->pcid->dev, "%s\n", get_chip_name(pDevice->chip_id));
dev_info(&pDevice->pcid->dev, "MAC=%pM IO=0x%lx Mem=0x%lx IRQ=%d\n",
pDevice->abyCurrentNetAddr, (unsigned long)pDevice->ioaddr,
(unsigned long)pDevice->PortOffset, pDevice->pcid->irq);
}
static void vt6655_init_info(struct pci_dev *pcid,
struct vnt_private **ppDevice,
PCHIP_INFO pChip_info)
{
memset(*ppDevice, 0, sizeof(**ppDevice));
(*ppDevice)->pcid = pcid;
(*ppDevice)->chip_id = pChip_info->chip_id;
(*ppDevice)->io_size = pChip_info->io_size;
(*ppDevice)->nTxQueues = pChip_info->nTxQueue;
(*ppDevice)->multicast_limit = 32;
spin_lock_init(&((*ppDevice)->lock));
}
static bool device_get_pci_info(struct vnt_private *pDevice,
struct pci_dev *pcid)
{
u16 pci_cmd;
u8 b;
unsigned int cis_addr;
pci_read_config_byte(pcid, PCI_REVISION_ID, &pDevice->byRevId);
pci_read_config_word(pcid, PCI_SUBSYSTEM_ID, &pDevice->SubSystemID);
pci_read_config_word(pcid, PCI_SUBSYSTEM_VENDOR_ID, &pDevice->SubVendorID);
pci_read_config_word(pcid, PCI_COMMAND, (u16 *)&(pci_cmd));
pci_set_master(pcid);
pDevice->memaddr = pci_resource_start(pcid, 0);
pDevice->ioaddr = pci_resource_start(pcid, 1);
cis_addr = pci_resource_start(pcid, 2);
pDevice->pcid = pcid;
pci_read_config_byte(pcid, PCI_COMMAND, &b);
pci_write_config_byte(pcid, PCI_COMMAND, (b|PCI_COMMAND_MASTER));
return true;
}
static void device_free_info(struct vnt_private *pDevice)
{
if (!pDevice)
return;
if (pDevice->mac_hw)
ieee80211_unregister_hw(pDevice->hw);
if (pDevice->PortOffset)
iounmap(pDevice->PortOffset);
if (pDevice->pcid)
pci_release_regions(pDevice->pcid);
if (pDevice->hw)
ieee80211_free_hw(pDevice->hw);
}
static bool device_init_rings(struct vnt_private *pDevice)
{
void *vir_pool;
vir_pool = dma_zalloc_coherent(&pDevice->pcid->dev,
pDevice->sOpts.nRxDescs0 * sizeof(SRxDesc) +
pDevice->sOpts.nRxDescs1 * sizeof(SRxDesc) +
pDevice->sOpts.nTxDescs[0] * sizeof(STxDesc) +
pDevice->sOpts.nTxDescs[1] * sizeof(STxDesc),
&pDevice->pool_dma, GFP_ATOMIC);
if (vir_pool == NULL) {
dev_err(&pDevice->pcid->dev, "allocate desc dma memory failed\n");
return false;
}
pDevice->aRD0Ring = vir_pool;
pDevice->aRD1Ring = vir_pool +
pDevice->sOpts.nRxDescs0 * sizeof(SRxDesc);
pDevice->rd0_pool_dma = pDevice->pool_dma;
pDevice->rd1_pool_dma = pDevice->rd0_pool_dma +
pDevice->sOpts.nRxDescs0 * sizeof(SRxDesc);
pDevice->tx0_bufs = dma_zalloc_coherent(&pDevice->pcid->dev,
pDevice->sOpts.nTxDescs[0] * PKT_BUF_SZ +
pDevice->sOpts.nTxDescs[1] * PKT_BUF_SZ +
CB_BEACON_BUF_SIZE +
CB_MAX_BUF_SIZE,
&pDevice->tx_bufs_dma0,
GFP_ATOMIC);
if (pDevice->tx0_bufs == NULL) {
dev_err(&pDevice->pcid->dev, "allocate buf dma memory failed\n");
dma_free_coherent(&pDevice->pcid->dev,
pDevice->sOpts.nRxDescs0 * sizeof(SRxDesc) +
pDevice->sOpts.nRxDescs1 * sizeof(SRxDesc) +
pDevice->sOpts.nTxDescs[0] * sizeof(STxDesc) +
pDevice->sOpts.nTxDescs[1] * sizeof(STxDesc),
vir_pool, pDevice->pool_dma
);
return false;
}
pDevice->td0_pool_dma = pDevice->rd1_pool_dma +
pDevice->sOpts.nRxDescs1 * sizeof(SRxDesc);
pDevice->td1_pool_dma = pDevice->td0_pool_dma +
pDevice->sOpts.nTxDescs[0] * sizeof(STxDesc);
pDevice->apTD0Rings = vir_pool
+ pDevice->sOpts.nRxDescs0 * sizeof(SRxDesc)
+ pDevice->sOpts.nRxDescs1 * sizeof(SRxDesc);
pDevice->apTD1Rings = vir_pool
+ pDevice->sOpts.nRxDescs0 * sizeof(SRxDesc)
+ pDevice->sOpts.nRxDescs1 * sizeof(SRxDesc)
+ pDevice->sOpts.nTxDescs[0] * sizeof(STxDesc);
pDevice->tx1_bufs = pDevice->tx0_bufs +
pDevice->sOpts.nTxDescs[0] * PKT_BUF_SZ;
pDevice->tx_beacon_bufs = pDevice->tx1_bufs +
pDevice->sOpts.nTxDescs[1] * PKT_BUF_SZ;
pDevice->pbyTmpBuff = pDevice->tx_beacon_bufs +
CB_BEACON_BUF_SIZE;
pDevice->tx_bufs_dma1 = pDevice->tx_bufs_dma0 +
pDevice->sOpts.nTxDescs[0] * PKT_BUF_SZ;
pDevice->tx_beacon_dma = pDevice->tx_bufs_dma1 +
pDevice->sOpts.nTxDescs[1] * PKT_BUF_SZ;
return true;
}
static void device_free_rings(struct vnt_private *pDevice)
{
dma_free_coherent(&pDevice->pcid->dev,
pDevice->sOpts.nRxDescs0 * sizeof(SRxDesc) +
pDevice->sOpts.nRxDescs1 * sizeof(SRxDesc) +
pDevice->sOpts.nTxDescs[0] * sizeof(STxDesc) +
pDevice->sOpts.nTxDescs[1] * sizeof(STxDesc)
,
pDevice->aRD0Ring, pDevice->pool_dma
);
if (pDevice->tx0_bufs)
dma_free_coherent(&pDevice->pcid->dev,
pDevice->sOpts.nTxDescs[0] * PKT_BUF_SZ +
pDevice->sOpts.nTxDescs[1] * PKT_BUF_SZ +
CB_BEACON_BUF_SIZE +
CB_MAX_BUF_SIZE,
pDevice->tx0_bufs, pDevice->tx_bufs_dma0
);
}
static void device_init_rd0_ring(struct vnt_private *pDevice)
{
int i;
dma_addr_t curr = pDevice->rd0_pool_dma;
PSRxDesc pDesc;
for (i = 0; i < pDevice->sOpts.nRxDescs0; i ++, curr += sizeof(SRxDesc)) {
pDesc = &(pDevice->aRD0Ring[i]);
pDesc->pRDInfo = alloc_rd_info();
ASSERT(pDesc->pRDInfo);
if (!device_alloc_rx_buf(pDevice, pDesc))
dev_err(&pDevice->pcid->dev, "can not alloc rx bufs\n");
pDesc->next = &(pDevice->aRD0Ring[(i+1) % pDevice->sOpts.nRxDescs0]);
pDesc->pRDInfo->curr_desc = cpu_to_le32(curr);
pDesc->next_desc = cpu_to_le32(curr + sizeof(SRxDesc));
}
if (i > 0)
pDevice->aRD0Ring[i-1].next_desc = cpu_to_le32(pDevice->rd0_pool_dma);
pDevice->pCurrRD[0] = &(pDevice->aRD0Ring[0]);
}
static void device_init_rd1_ring(struct vnt_private *pDevice)
{
int i;
dma_addr_t curr = pDevice->rd1_pool_dma;
PSRxDesc pDesc;
for (i = 0; i < pDevice->sOpts.nRxDescs1; i ++, curr += sizeof(SRxDesc)) {
pDesc = &(pDevice->aRD1Ring[i]);
pDesc->pRDInfo = alloc_rd_info();
ASSERT(pDesc->pRDInfo);
if (!device_alloc_rx_buf(pDevice, pDesc))
dev_err(&pDevice->pcid->dev, "can not alloc rx bufs\n");
pDesc->next = &(pDevice->aRD1Ring[(i+1) % pDevice->sOpts.nRxDescs1]);
pDesc->pRDInfo->curr_desc = cpu_to_le32(curr);
pDesc->next_desc = cpu_to_le32(curr + sizeof(SRxDesc));
}
if (i > 0)
pDevice->aRD1Ring[i-1].next_desc = cpu_to_le32(pDevice->rd1_pool_dma);
pDevice->pCurrRD[1] = &(pDevice->aRD1Ring[0]);
}
static void device_free_rd0_ring(struct vnt_private *pDevice)
{
int i;
for (i = 0; i < pDevice->sOpts.nRxDescs0; i++) {
PSRxDesc pDesc = &(pDevice->aRD0Ring[i]);
PDEVICE_RD_INFO pRDInfo = pDesc->pRDInfo;
dma_unmap_single(&pDevice->pcid->dev, pRDInfo->skb_dma,
pDevice->rx_buf_sz, DMA_FROM_DEVICE);
dev_kfree_skb(pRDInfo->skb);
kfree(pDesc->pRDInfo);
}
}
static void device_free_rd1_ring(struct vnt_private *pDevice)
{
int i;
for (i = 0; i < pDevice->sOpts.nRxDescs1; i++) {
PSRxDesc pDesc = &(pDevice->aRD1Ring[i]);
PDEVICE_RD_INFO pRDInfo = pDesc->pRDInfo;
dma_unmap_single(&pDevice->pcid->dev, pRDInfo->skb_dma,
pDevice->rx_buf_sz, DMA_FROM_DEVICE);
dev_kfree_skb(pRDInfo->skb);
kfree(pDesc->pRDInfo);
}
}
static void device_init_td0_ring(struct vnt_private *pDevice)
{
int i;
dma_addr_t curr;
PSTxDesc pDesc;
curr = pDevice->td0_pool_dma;
for (i = 0; i < pDevice->sOpts.nTxDescs[0]; i++, curr += sizeof(STxDesc)) {
pDesc = &(pDevice->apTD0Rings[i]);
pDesc->pTDInfo = alloc_td_info();
ASSERT(pDesc->pTDInfo);
if (pDevice->flags & DEVICE_FLAGS_TX_ALIGN) {
pDesc->pTDInfo->buf = pDevice->tx0_bufs + (i)*PKT_BUF_SZ;
pDesc->pTDInfo->buf_dma = pDevice->tx_bufs_dma0 + (i)*PKT_BUF_SZ;
}
pDesc->next = &(pDevice->apTD0Rings[(i+1) % pDevice->sOpts.nTxDescs[0]]);
pDesc->pTDInfo->curr_desc = cpu_to_le32(curr);
pDesc->next_desc = cpu_to_le32(curr+sizeof(STxDesc));
}
if (i > 0)
pDevice->apTD0Rings[i-1].next_desc = cpu_to_le32(pDevice->td0_pool_dma);
pDevice->apTailTD[0] = pDevice->apCurrTD[0] = &(pDevice->apTD0Rings[0]);
}
static void device_init_td1_ring(struct vnt_private *pDevice)
{
int i;
dma_addr_t curr;
PSTxDesc pDesc;
curr = pDevice->td1_pool_dma;
for (i = 0; i < pDevice->sOpts.nTxDescs[1]; i++, curr += sizeof(STxDesc)) {
pDesc = &(pDevice->apTD1Rings[i]);
pDesc->pTDInfo = alloc_td_info();
ASSERT(pDesc->pTDInfo);
if (pDevice->flags & DEVICE_FLAGS_TX_ALIGN) {
pDesc->pTDInfo->buf = pDevice->tx1_bufs + (i) * PKT_BUF_SZ;
pDesc->pTDInfo->buf_dma = pDevice->tx_bufs_dma1 + (i) * PKT_BUF_SZ;
}
pDesc->next = &(pDevice->apTD1Rings[(i + 1) % pDevice->sOpts.nTxDescs[1]]);
pDesc->pTDInfo->curr_desc = cpu_to_le32(curr);
pDesc->next_desc = cpu_to_le32(curr+sizeof(STxDesc));
}
if (i > 0)
pDevice->apTD1Rings[i-1].next_desc = cpu_to_le32(pDevice->td1_pool_dma);
pDevice->apTailTD[1] = pDevice->apCurrTD[1] = &(pDevice->apTD1Rings[0]);
}
static void device_free_td0_ring(struct vnt_private *pDevice)
{
int i;
for (i = 0; i < pDevice->sOpts.nTxDescs[0]; i++) {
PSTxDesc pDesc = &(pDevice->apTD0Rings[i]);
PDEVICE_TD_INFO pTDInfo = pDesc->pTDInfo;
if (pTDInfo->skb_dma && (pTDInfo->skb_dma != pTDInfo->buf_dma))
dma_unmap_single(&pDevice->pcid->dev, pTDInfo->skb_dma,
pTDInfo->skb->len, DMA_TO_DEVICE);
if (pTDInfo->skb)
dev_kfree_skb(pTDInfo->skb);
kfree(pDesc->pTDInfo);
}
}
static void device_free_td1_ring(struct vnt_private *pDevice)
{
int i;
for (i = 0; i < pDevice->sOpts.nTxDescs[1]; i++) {
PSTxDesc pDesc = &(pDevice->apTD1Rings[i]);
PDEVICE_TD_INFO pTDInfo = pDesc->pTDInfo;
if (pTDInfo->skb_dma && (pTDInfo->skb_dma != pTDInfo->buf_dma))
dma_unmap_single(&pDevice->pcid->dev, pTDInfo->skb_dma,
pTDInfo->skb->len, DMA_TO_DEVICE);
if (pTDInfo->skb)
dev_kfree_skb(pTDInfo->skb);
kfree(pDesc->pTDInfo);
}
}
static int device_rx_srv(struct vnt_private *pDevice, unsigned int uIdx)
{
PSRxDesc pRD;
int works = 0;
for (pRD = pDevice->pCurrRD[uIdx];
pRD->m_rd0RD0.f1Owner == OWNED_BY_HOST;
pRD = pRD->next) {
if (works++ > 15)
break;
if (!pRD->pRDInfo->skb)
break;
if (vnt_receive_frame(pDevice, pRD)) {
if (!device_alloc_rx_buf(pDevice, pRD)) {
dev_err(&pDevice->pcid->dev,
"can not allocate rx buf\n");
break;
}
}
pRD->m_rd0RD0.f1Owner = OWNED_BY_NIC;
}
pDevice->pCurrRD[uIdx] = pRD;
return works;
}
static bool device_alloc_rx_buf(struct vnt_private *pDevice, PSRxDesc pRD)
{
PDEVICE_RD_INFO pRDInfo = pRD->pRDInfo;
pRDInfo->skb = dev_alloc_skb((int)pDevice->rx_buf_sz);
if (pRDInfo->skb == NULL)
return false;
ASSERT(pRDInfo->skb);
pRDInfo->skb_dma =
dma_map_single(&pDevice->pcid->dev,
skb_put(pRDInfo->skb, skb_tailroom(pRDInfo->skb)),
pDevice->rx_buf_sz, DMA_FROM_DEVICE);
*((unsigned int *)&(pRD->m_rd0RD0)) = 0;
pRD->m_rd0RD0.wResCount = cpu_to_le16(pDevice->rx_buf_sz);
pRD->m_rd0RD0.f1Owner = OWNED_BY_NIC;
pRD->m_rd1RD1.wReqCount = cpu_to_le16(pDevice->rx_buf_sz);
pRD->buff_addr = cpu_to_le32(pRDInfo->skb_dma);
return true;
}
static int vnt_int_report_rate(struct vnt_private *priv,
PDEVICE_TD_INFO context, u8 tsr0, u8 tsr1)
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
if (info->band == IEEE80211_BAND_5GHZ)
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
static int device_tx_srv(struct vnt_private *pDevice, unsigned int uIdx)
{
PSTxDesc pTD;
int works = 0;
unsigned char byTsr0;
unsigned char byTsr1;
for (pTD = pDevice->apTailTD[uIdx]; pDevice->iTDUsed[uIdx] > 0; pTD = pTD->next) {
if (pTD->m_td0TD0.f1Owner == OWNED_BY_NIC)
break;
if (works++ > 15)
break;
byTsr0 = pTD->m_td0TD0.byTSR0;
byTsr1 = pTD->m_td0TD0.byTSR1;
if (pTD->m_td1TD1.byTCR & TCR_STP) {
if ((pTD->pTDInfo->byFlags & TD_FLAGS_NETIF_SKB) != 0) {
if (!(byTsr1 & TSR1_TERR)) {
if (byTsr0 != 0) {
pr_debug(" Tx[%d] OK but has error. tsr1[%02X] tsr0[%02X]\n",
(int)uIdx, byTsr1,
byTsr0);
}
} else {
pr_debug(" Tx[%d] dropped & tsr1[%02X] tsr0[%02X]\n",
(int)uIdx, byTsr1, byTsr0);
}
}
if (byTsr1 & TSR1_TERR) {
if ((pTD->pTDInfo->byFlags & TD_FLAGS_PRIV_SKB) != 0) {
pr_debug(" Tx[%d] fail has error. tsr1[%02X] tsr0[%02X]\n",
(int)uIdx, byTsr1, byTsr0);
}
}
vnt_int_report_rate(pDevice, pTD->pTDInfo, byTsr0, byTsr1);
device_free_tx_buf(pDevice, pTD);
pDevice->iTDUsed[uIdx]--;
}
}
pDevice->apTailTD[uIdx] = pTD;
return works;
}
static void device_error(struct vnt_private *pDevice, unsigned short status)
{
if (status & ISR_FETALERR) {
dev_err(&pDevice->pcid->dev, "Hardware fatal error\n");
MACbShutdown(pDevice->PortOffset);
return;
}
}
static void device_free_tx_buf(struct vnt_private *pDevice, PSTxDesc pDesc)
{
PDEVICE_TD_INFO pTDInfo = pDesc->pTDInfo;
struct sk_buff *skb = pTDInfo->skb;
if (pTDInfo->skb_dma && (pTDInfo->skb_dma != pTDInfo->buf_dma)) {
dma_unmap_single(&pDevice->pcid->dev, pTDInfo->skb_dma,
skb->len, DMA_TO_DEVICE);
}
if (skb)
ieee80211_tx_status_irqsafe(pDevice->hw, skb);
pTDInfo->skb_dma = 0;
pTDInfo->skb = NULL;
pTDInfo->byFlags = 0;
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
MACvOneShotTimer1MicroSec(priv->PortOffset,
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
if (max_count > priv->sOpts.int_works)
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
PSTxDesc head_td;
u32 dma_idx;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
if (ieee80211_is_data(hdr->frame_control))
dma_idx = TYPE_AC0DMA;
else
dma_idx = TYPE_TXDMA0;
if (AVAIL_TD(priv, dma_idx) < 1) {
spin_unlock_irqrestore(&priv->lock, flags);
return -ENOMEM;
}
head_td = priv->apCurrTD[dma_idx];
head_td->m_td1TD1.byTCR = 0;
head_td->pTDInfo->skb = skb;
if (dma_idx == TYPE_AC0DMA)
head_td->pTDInfo->byFlags = TD_FLAGS_NETIF_SKB;
priv->apCurrTD[dma_idx] = head_td->next;
spin_unlock_irqrestore(&priv->lock, flags);
vnt_generate_fifo_header(priv, dma_idx, head_td, skb);
if (MACbIsRegBitsOn(priv->PortOffset, MAC_REG_PSCTL, PSCTL_PS))
MACbPSWakeup(priv->PortOffset);
spin_lock_irqsave(&priv->lock, flags);
priv->bPWBitOn = false;
head_td->m_td1TD1.byTCR |= (TCR_STP | TCR_EDP | EDMSDU);
head_td->m_td1TD1.wReqCount =
cpu_to_le16((u16)head_td->pTDInfo->dwReqCount);
head_td->buff_addr = cpu_to_le32(head_td->pTDInfo->skb_dma);
wmb();
head_td->m_td0TD0.f1Owner = OWNED_BY_NIC;
wmb();
if (head_td->pTDInfo->byFlags & TD_FLAGS_NETIF_SKB)
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
ieee80211_stop_queues(hw);
if (vnt_tx_packet(priv, skb)) {
ieee80211_free_txskb(hw, skb);
ieee80211_wake_queues(hw);
}
}
static int vnt_start(struct ieee80211_hw *hw)
{
struct vnt_private *priv = hw->priv;
int ret;
priv->rx_buf_sz = PKT_BUF_SZ;
if (!device_init_rings(priv))
return -ENOMEM;
ret = request_irq(priv->pcid->irq, &vnt_interrupt,
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
MACbShutdown(priv->PortOffset);
MACbSoftwareReset(priv->PortOffset);
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
if (conf->chandef.chan->band == IEEE80211_BAND_5GHZ)
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
PCHIP_INFO pChip_info = (PCHIP_INFO)ent->driver_data;
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
vt6655_init_info(pcid, &priv, pChip_info);
priv->hw = hw;
SET_IEEE80211_DEV(priv->hw, &pcid->dev);
if (pci_enable_device(pcid)) {
device_free_info(priv);
return -ENODEV;
}
dev_dbg(&pcid->dev,
"Before get pci_info memaddr is %x\n", priv->memaddr);
if (!device_get_pci_info(priv, pcid)) {
dev_err(&pcid->dev, ": Failed to find PCI device.\n");
device_free_info(priv);
return -ENODEV;
}
#ifdef DEBUG
dev_dbg(&pcid->dev,
"after get pci_info memaddr is %x, io addr is %x,io_size is %d\n",
priv->memaddr, priv->ioaddr, priv->io_size);
{
int i;
u32 bar, len;
u32 address[] = {
PCI_BASE_ADDRESS_0,
PCI_BASE_ADDRESS_1,
PCI_BASE_ADDRESS_2,
PCI_BASE_ADDRESS_3,
PCI_BASE_ADDRESS_4,
PCI_BASE_ADDRESS_5,
0};
for (i = 0; address[i]; i++) {
pci_read_config_dword(pcid, address[i], &bar);
dev_dbg(&pcid->dev, "bar %d is %x\n", i, bar);
if (!bar) {
dev_dbg(&pcid->dev,
"bar %d not implemented\n", i);
continue;
}
if (bar & PCI_BASE_ADDRESS_SPACE_IO) {
len = bar & (PCI_BASE_ADDRESS_IO_MASK & 0xffff);
len = len & ~(len - 1);
dev_dbg(&pcid->dev,
"IO space: len in IO %x, BAR %d\n",
len, i);
} else {
len = bar & 0xfffffff0;
len = ~len + 1;
dev_dbg(&pcid->dev,
"len in MEM %x, BAR %d\n", len, i);
}
}
}
#endif
priv->PortOffset = ioremap(priv->memaddr & PCI_BASE_ADDRESS_MEM_MASK,
priv->io_size);
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
INIT_WORK(&priv->interrupt_work, vnt_interrupt_work);
if (!MACbSoftwareReset(priv->PortOffset)) {
dev_err(&pcid->dev, ": Failed to access MAC hardware..\n");
device_free_info(priv);
return -ENODEV;
}
MACvInitialize(priv->PortOffset);
MACvReadEtherAddress(priv->PortOffset, priv->abyCurrentNetAddr);
priv->byRFType = SROMbyReadEmbedded(priv->PortOffset, EEP_OFS_RFTYPE);
priv->byRFType &= RF_MASK;
dev_dbg(&pcid->dev, "RF Type = %x\n", priv->byRFType);
device_get_options(priv);
device_set_options(priv);
priv->sOpts.flags &= pChip_info->flags;
priv->flags = priv->sOpts.flags | (pChip_info->flags & 0xff000000UL);
wiphy = priv->hw->wiphy;
wiphy->frag_threshold = FRAG_THRESH_DEF;
wiphy->rts_threshold = RTS_THRESH_DEF;
wiphy->interface_modes = BIT(NL80211_IFTYPE_STATION) |
BIT(NL80211_IFTYPE_ADHOC) | BIT(NL80211_IFTYPE_AP);
ieee80211_hw_set(priv->hw, TIMING_BEACON_ONLY);
ieee80211_hw_set(priv->hw, SIGNAL_DBM);
ieee80211_hw_set(priv->hw, RX_INCLUDES_FCS);
ieee80211_hw_set(priv->hw, REPORTS_TX_ACK_STATUS);
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
MACbShutdown(priv->PortOffset);
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
