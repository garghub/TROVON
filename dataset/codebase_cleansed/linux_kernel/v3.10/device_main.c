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
PSDevice pDevice = pci_get_drvdata(pcid);
if (pDevice == NULL)
return;
device_free_info(pDevice);
}
static void device_get_options(PSDevice pDevice, int index, char *devname)
{
POPTIONS pOpts = &(pDevice->sOpts);
pOpts->nRxDescs0 = RX_DESC_DEF0;
pOpts->nRxDescs1 = RX_DESC_DEF1;
pOpts->nTxDescs[0] = TX_DESC_DEF0;
pOpts->nTxDescs[1] = TX_DESC_DEF1;
pOpts->flags |= DEVICE_FLAGS_IP_ALIGN;
pOpts->int_works = INT_WORKS_DEF;
pOpts->rts_thresh = RTS_THRESH_DEF;
pOpts->frag_thresh = FRAG_THRESH_DEF;
pOpts->data_rate = DATA_RATE_DEF;
pOpts->channel_num = CHANNEL_DEF;
pOpts->flags |= DEVICE_FLAGS_PREAMBLE_TYPE;
pOpts->flags |= DEVICE_FLAGS_OP_MODE;
pOpts->short_retry = SHORT_RETRY_DEF;
pOpts->long_retry = LONG_RETRY_DEF;
pOpts->bbp_type = BBP_TYPE_DEF;
pOpts->flags |= DEVICE_FLAGS_80211h_MODE;
pOpts->flags |= DEVICE_FLAGS_DiversityANT;
}
static void
device_set_options(PSDevice pDevice) {
unsigned char abyBroadcastAddr[ETH_ALEN] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
unsigned char abySNAP_RFC1042[ETH_ALEN] = {0xAA, 0xAA, 0x03, 0x00, 0x00, 0x00};
unsigned char abySNAP_Bridgetunnel[ETH_ALEN] = {0xAA, 0xAA, 0x03, 0x00, 0x00, 0xF8};
memcpy(pDevice->abyBroadcastAddr, abyBroadcastAddr, ETH_ALEN);
memcpy(pDevice->abySNAP_RFC1042, abySNAP_RFC1042, ETH_ALEN);
memcpy(pDevice->abySNAP_Bridgetunnel, abySNAP_Bridgetunnel, ETH_ALEN);
pDevice->uChannel = pDevice->sOpts.channel_num;
pDevice->wRTSThreshold = pDevice->sOpts.rts_thresh;
pDevice->wFragmentationThreshold = pDevice->sOpts.frag_thresh;
pDevice->byShortRetryLimit = pDevice->sOpts.short_retry;
pDevice->byLongRetryLimit = pDevice->sOpts.long_retry;
pDevice->wMaxTransmitMSDULifetime = DEFAULT_MSDU_LIFETIME;
pDevice->byShortPreamble = (pDevice->sOpts.flags & DEVICE_FLAGS_PREAMBLE_TYPE) ? 1 : 0;
pDevice->byOpMode = (pDevice->sOpts.flags & DEVICE_FLAGS_OP_MODE) ? 1 : 0;
pDevice->ePSMode = (pDevice->sOpts.flags & DEVICE_FLAGS_PS_MODE) ? 1 : 0;
pDevice->b11hEnable = (pDevice->sOpts.flags & DEVICE_FLAGS_80211h_MODE) ? 1 : 0;
pDevice->bDiversityRegCtlON = (pDevice->sOpts.flags & DEVICE_FLAGS_DiversityANT) ? 1 : 0;
pDevice->uConnectionRate = pDevice->sOpts.data_rate;
if (pDevice->uConnectionRate < RATE_AUTO) pDevice->bFixRate = true;
pDevice->byBBType = pDevice->sOpts.bbp_type;
pDevice->byPacketType = pDevice->byBBType;
pDevice->byAutoFBCtrl = AUTO_FB_0;
pDevice->bUpdateBBVGA = true;
pDevice->byFOETuning = 0;
pDevice->wCTSDuration = 0;
pDevice->byPreambleType = 0;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " uChannel= %d\n", (int)pDevice->uChannel);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " byOpMode= %d\n", (int)pDevice->byOpMode);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " ePSMode= %d\n", (int)pDevice->ePSMode);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " wRTSThreshold= %d\n", (int)pDevice->wRTSThreshold);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " byShortRetryLimit= %d\n", (int)pDevice->byShortRetryLimit);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " byLongRetryLimit= %d\n", (int)pDevice->byLongRetryLimit);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " byPreambleType= %d\n", (int)pDevice->byPreambleType);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " byShortPreamble= %d\n", (int)pDevice->byShortPreamble);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " uConnectionRate= %d\n", (int)pDevice->uConnectionRate);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " byBBType= %d\n", (int)pDevice->byBBType);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " pDevice->b11hEnable= %d\n", (int)pDevice->b11hEnable);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " pDevice->bDiversityRegCtlON= %d\n", (int)pDevice->bDiversityRegCtlON);
}
static void s_vCompleteCurrentMeasure(PSDevice pDevice, unsigned char byResult)
{
unsigned int ii;
unsigned long dwDuration = 0;
unsigned char byRPI0 = 0;
for (ii = 1; ii < 8; ii++) {
pDevice->dwRPIs[ii] *= 255;
dwDuration |= *((unsigned short *)(pDevice->pCurrMeasureEID->sReq.abyDuration));
dwDuration <<= 10;
pDevice->dwRPIs[ii] /= dwDuration;
pDevice->abyRPIs[ii] = (unsigned char)pDevice->dwRPIs[ii];
byRPI0 += pDevice->abyRPIs[ii];
}
pDevice->abyRPIs[0] = (0xFF - byRPI0);
if (pDevice->uNumOfMeasureEIDs == 0) {
VNTWIFIbMeasureReport(pDevice->pMgmt,
true,
pDevice->pCurrMeasureEID,
byResult,
pDevice->byBasicMap,
pDevice->byCCAFraction,
pDevice->abyRPIs
);
} else {
VNTWIFIbMeasureReport(pDevice->pMgmt,
false,
pDevice->pCurrMeasureEID,
byResult,
pDevice->byBasicMap,
pDevice->byCCAFraction,
pDevice->abyRPIs
);
CARDbStartMeasure(pDevice, pDevice->pCurrMeasureEID++, pDevice->uNumOfMeasureEIDs);
}
}
static void device_init_registers(PSDevice pDevice, DEVICE_INIT_TYPE InitType)
{
unsigned int ii;
unsigned char byValue;
unsigned char byValue1;
unsigned char byCCKPwrdBm = 0;
unsigned char byOFDMPwrdBm = 0;
int zonetype = 0;
PSMgmtObject pMgmt = &(pDevice->sMgmtObj);
MACbShutdown(pDevice->PortOffset);
BBvSoftwareReset(pDevice->PortOffset);
if ((InitType == DEVICE_INIT_COLD) ||
(InitType == DEVICE_INIT_DXPL)) {
MACbSoftwareReset(pDevice->PortOffset);
pDevice->bCCK = true;
pDevice->bAES = false;
pDevice->bProtectMode = false;
pDevice->bNonERPPresent = false;
pDevice->bBarkerPreambleMd = false;
pDevice->wCurrentRate = RATE_1M;
pDevice->byTopOFDMBasicRate = RATE_24M;
pDevice->byTopCCKBasicRate = RATE_1M;
pDevice->byRevId = 0;
MACvInitialize(pDevice->PortOffset);
VNSvInPortB(pDevice->PortOffset + MAC_REG_LOCALID, &(pDevice->byLocalID));
spin_lock_irq(&pDevice->lock);
SROMvReadAllContents(pDevice->PortOffset, pDevice->abyEEPROM);
spin_unlock_irq(&pDevice->lock);
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
pDevice->ulDiversityNValue = 100*260;
pDevice->ulDiversityMValue = 100*16;
pDevice->byTMax = 1;
pDevice->byTMax2 = 4;
pDevice->ulSQ3TH = 0;
pDevice->byTMax3 = 64;
if (byValue == (EEP_ANTENNA_AUX | EEP_ANTENNA_MAIN)) {
pDevice->byAntennaCount = 2;
pDevice->byTxAntennaMode = ANT_B;
pDevice->dwTxAntennaSel = 1;
pDevice->dwRxAntennaSel = 1;
if (pDevice->bTxRxAntInv == true)
pDevice->byRxAntennaMode = ANT_A;
else
pDevice->byRxAntennaMode = ANT_B;
byValue1 = SROMbyReadEmbedded(pDevice->PortOffset, EEP_OFS_ANTENNA);
if ((byValue1 & 0x08) == 0)
pDevice->bDiversityEnable = false;
else
pDevice->bDiversityEnable = true;
} else {
pDevice->bDiversityEnable = false;
pDevice->byAntennaCount = 1;
pDevice->dwTxAntennaSel = 0;
pDevice->dwRxAntennaSel = 0;
if (byValue & EEP_ANTENNA_AUX) {
pDevice->byTxAntennaMode = ANT_A;
if (pDevice->bTxRxAntInv == true)
pDevice->byRxAntennaMode = ANT_B;
else
pDevice->byRxAntennaMode = ANT_A;
} else {
pDevice->byTxAntennaMode = ANT_B;
if (pDevice->bTxRxAntInv == true)
pDevice->byRxAntennaMode = ANT_A;
else
pDevice->byRxAntennaMode = ANT_B;
}
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "bDiversityEnable=[%d],NValue=[%d],MValue=[%d],TMax=[%d],TMax2=[%d]\n",
pDevice->bDiversityEnable, (int)pDevice->ulDiversityNValue, (int)pDevice->ulDiversityMValue, pDevice->byTMax, pDevice->byTMax2);
pDevice->byOriginalZonetype = pDevice->abyEEPROM[EEP_OFS_ZONETYPE];
zonetype = Config_FileOperation(pDevice, false, NULL);
if (zonetype >= 0) {
if ((zonetype == 0) &&
(pDevice->abyEEPROM[EEP_OFS_ZONETYPE] != 0x00)) {
pDevice->abyEEPROM[EEP_OFS_ZONETYPE] = 0;
pDevice->abyEEPROM[EEP_OFS_MAXCHANNEL] = 0x0B;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Init Zone Type :USA\n");
} else if ((zonetype == 1) &&
(pDevice->abyEEPROM[EEP_OFS_ZONETYPE] != 0x01)) {
pDevice->abyEEPROM[EEP_OFS_ZONETYPE] = 0x01;
pDevice->abyEEPROM[EEP_OFS_MAXCHANNEL] = 0x0D;
} else if ((zonetype == 2) &&
(pDevice->abyEEPROM[EEP_OFS_ZONETYPE] != 0x02)) {
pDevice->abyEEPROM[EEP_OFS_ZONETYPE] = 0x02;
pDevice->abyEEPROM[EEP_OFS_MAXCHANNEL] = 0x0D;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Init Zone Type :Europe\n");
}
else {
if (zonetype != pDevice->abyEEPROM[EEP_OFS_ZONETYPE])
printk("zonetype in file[%02x] mismatch with in EEPROM[%02x]\n", zonetype, pDevice->abyEEPROM[EEP_OFS_ZONETYPE]);
else
printk("Read Zonetype file success,use default zonetype setting[%02x]\n", zonetype);
}
} else
printk("Read Zonetype file fail,use default zonetype setting[%02x]\n", SROMbyReadEmbedded(pDevice->PortOffset, EEP_OFS_ZONETYPE));
pDevice->byRFType = SROMbyReadEmbedded(pDevice->PortOffset, EEP_OFS_RFTYPE);
if ((pDevice->byRFType & RF_EMU) != 0) {
pDevice->byRevId = 0x80;
}
pDevice->byRFType &= RF_MASK;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "pDevice->byRFType = %x\n", pDevice->byRFType);
if (pDevice->bZoneRegExist == false) {
pDevice->byZoneType = pDevice->abyEEPROM[EEP_OFS_ZONETYPE];
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "pDevice->byZoneType = %x\n", pDevice->byZoneType);
RFbInit(pDevice);
pDevice->byCurPwr = 0xFF;
pDevice->byCCKPwr = SROMbyReadEmbedded(pDevice->PortOffset, EEP_OFS_PWR_CCK);
pDevice->byOFDMPwrG = SROMbyReadEmbedded(pDevice->PortOffset, EEP_OFS_PWR_OFDMG);
for (ii = 0; ii < CB_MAX_CHANNEL_24G; ii++) {
pDevice->abyCCKPwrTbl[ii + 1] = SROMbyReadEmbedded(pDevice->PortOffset, (unsigned char)(ii + EEP_OFS_CCK_PWR_TBL));
if (pDevice->abyCCKPwrTbl[ii + 1] == 0) {
pDevice->abyCCKPwrTbl[ii+1] = pDevice->byCCKPwr;
}
pDevice->abyOFDMPwrTbl[ii + 1] = SROMbyReadEmbedded(pDevice->PortOffset, (unsigned char)(ii + EEP_OFS_OFDM_PWR_TBL));
if (pDevice->abyOFDMPwrTbl[ii + 1] == 0) {
pDevice->abyOFDMPwrTbl[ii + 1] = pDevice->byOFDMPwrG;
}
pDevice->abyCCKDefaultPwr[ii + 1] = byCCKPwrdBm;
pDevice->abyOFDMDefaultPwr[ii + 1] = byOFDMPwrdBm;
}
if (((pDevice->abyEEPROM[EEP_OFS_ZONETYPE] == ZoneType_Japan) ||
(pDevice->abyEEPROM[EEP_OFS_ZONETYPE] == ZoneType_Europe)) &&
(pDevice->byOriginalZonetype == ZoneType_USA)) {
for (ii = 11; ii < 14; ii++) {
pDevice->abyCCKPwrTbl[ii] = pDevice->abyCCKPwrTbl[10];
pDevice->abyOFDMPwrTbl[ii] = pDevice->abyOFDMPwrTbl[10];
}
}
for (ii = 0; ii < CB_MAX_CHANNEL_5G; ii++) {
pDevice->abyOFDMPwrTbl[ii + CB_MAX_CHANNEL_24G + 1] = SROMbyReadEmbedded(pDevice->PortOffset, (unsigned char)(ii + EEP_OFS_OFDMA_PWR_TBL));
pDevice->abyOFDMDefaultPwr[ii + CB_MAX_CHANNEL_24G + 1] = SROMbyReadEmbedded(pDevice->PortOffset, (unsigned char)(ii + EEP_OFS_OFDMA_PWR_dBm));
}
init_channel_table((void *)pDevice);
if (pDevice->byLocalID > REV_ID_VT3253_B1) {
MACvSelectPage1(pDevice->PortOffset);
VNSvOutPortB(pDevice->PortOffset + MAC_REG_MSRCTL + 1, (MSRCTL1_TXPWR | MSRCTL1_CSAPAREN));
MACvSelectPage0(pDevice->PortOffset);
}
MACvWordRegBitsOn(pDevice->PortOffset, MAC_REG_CFG, (CFG_TKIPOPT | CFG_NOTXTIMEOUT));
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
BBvSetRxAntennaMode(pDevice->PortOffset, pDevice->byRxAntennaMode);
BBvSetTxAntennaMode(pDevice->PortOffset, pDevice->byTxAntennaMode);
pDevice->byCurrentCh = 0;
if (pDevice->uConnectionRate == RATE_AUTO) {
pDevice->wCurrentRate = RATE_54M;
} else {
pDevice->wCurrentRate = (unsigned short)pDevice->uConnectionRate;
}
VNTWIFIbConfigPhyMode(pDevice->pMgmt, PHY_TYPE_11G);
VNTWIFIbConfigPhyMode(pDevice->pMgmt, PHY_TYPE_AUTO);
pDevice->bRadioOff = false;
pDevice->byRadioCtl = SROMbyReadEmbedded(pDevice->PortOffset, EEP_OFS_RADIOCTL);
pDevice->bHWRadioOff = false;
if (pDevice->byRadioCtl & EEP_RADIOCTL_ENABLE) {
MACvGPIOIn(pDevice->PortOffset, &pDevice->byGPIO);
#ifdef FOR_LED_ON_NOTEBOOK
if (pDevice->byGPIO & GPIO0_DATA) { pDevice->bHWRadioOff = true; }
if (!(pDevice->byGPIO & GPIO0_DATA)) { pDevice->bHWRadioOff = false; }
}
if ((pDevice->bRadioControlOff == true)) {
CARDbRadioPowerOff(pDevice);
} else CARDbRadioPowerOn(pDevice);
#else
if (((pDevice->byGPIO & GPIO0_DATA) && !(pDevice->byRadioCtl & EEP_RADIOCTL_INV)) ||
(!(pDevice->byGPIO & GPIO0_DATA) && (pDevice->byRadioCtl & EEP_RADIOCTL_INV))) {
pDevice->bHWRadioOff = true;
}
}
if ((pDevice->bHWRadioOff == true) || (pDevice->bRadioControlOff == true)) {
CARDbRadioPowerOff(pDevice);
}
#endif
}
void device_init_diversity_timer(PSDevice pDevice) {
init_timer(&pDevice->TimerSQ3Tmax1);
pDevice->TimerSQ3Tmax1.data = (unsigned long) pDevice;
pDevice->TimerSQ3Tmax1.function = (TimerFunction)TimerSQ3CallBack;
pDevice->TimerSQ3Tmax1.expires = RUN_AT(HZ);
init_timer(&pDevice->TimerSQ3Tmax2);
pDevice->TimerSQ3Tmax2.data = (unsigned long) pDevice;
pDevice->TimerSQ3Tmax2.function = (TimerFunction)TimerSQ3CallBack;
pDevice->TimerSQ3Tmax2.expires = RUN_AT(HZ);
init_timer(&pDevice->TimerSQ3Tmax3);
pDevice->TimerSQ3Tmax3.data = (unsigned long) pDevice;
pDevice->TimerSQ3Tmax3.function = (TimerFunction)TimerState1CallBack;
pDevice->TimerSQ3Tmax3.expires = RUN_AT(HZ);
return;
}
static bool device_release_WPADEV(PSDevice pDevice)
{
viawget_wpa_header *wpahdr;
int ii = 0;
if (pDevice->bWPADEVUp == true) {
wpahdr = (viawget_wpa_header *)pDevice->skb->data;
wpahdr->type = VIAWGET_DEVICECLOSE_MSG;
wpahdr->resp_ie_len = 0;
wpahdr->req_ie_len = 0;
skb_put(pDevice->skb, sizeof(viawget_wpa_header));
pDevice->skb->dev = pDevice->wpadev;
skb_reset_mac_header(pDevice->skb);
pDevice->skb->pkt_type = PACKET_HOST;
pDevice->skb->protocol = htons(ETH_P_802_2);
memset(pDevice->skb->cb, 0, sizeof(pDevice->skb->cb));
netif_rx(pDevice->skb);
pDevice->skb = dev_alloc_skb((int)pDevice->rx_buf_sz);
while ((pDevice->bWPADEVUp == true)) {
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(HZ / 20);
ii++;
if (ii > 20)
break;
}
}
return true;
}
static int
vt6655_probe(struct pci_dev *pcid, const struct pci_device_id *ent)
{
static bool bFirst = true;
struct net_device *dev = NULL;
PCHIP_INFO pChip_info = (PCHIP_INFO)ent->driver_data;
PSDevice pDevice;
int rc;
if (device_nics++ >= MAX_UINTS) {
printk(KERN_NOTICE DEVICE_NAME ": already found %d NICs\n", device_nics);
return -ENODEV;
}
dev = alloc_etherdev(sizeof(DEVICE_INFO));
pDevice = (PSDevice) netdev_priv(dev);
if (dev == NULL) {
printk(KERN_ERR DEVICE_NAME ": allocate net device failed \n");
return -ENOMEM;
}
SET_NETDEV_DEV(dev, &pcid->dev);
if (bFirst) {
printk(KERN_NOTICE "%s Ver. %s\n", DEVICE_FULL_DRV_NAM, DEVICE_VERSION);
printk(KERN_NOTICE "Copyright (c) 2003 VIA Networking Technologies, Inc.\n");
bFirst = false;
}
vt6655_init_info(pcid, &pDevice, pChip_info);
pDevice->dev = dev;
pDevice->next_module = root_device_dev;
root_device_dev = dev;
if (pci_enable_device(pcid)) {
device_free_info(pDevice);
return -ENODEV;
}
dev->irq = pcid->irq;
#ifdef DEBUG
printk("Before get pci_info memaddr is %x\n", pDevice->memaddr);
#endif
if (device_get_pci_info(pDevice, pcid) == false) {
printk(KERN_ERR DEVICE_NAME ": Failed to find PCI device.\n");
device_free_info(pDevice);
return -ENODEV;
}
#if 1
#ifdef DEBUG
printk("after get pci_info memaddr is %x, io addr is %x,io_size is %d\n", pDevice->memaddr, pDevice->ioaddr, pDevice->io_size);
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
printk("bar %d is %x\n", i, bar);
if (!bar) {
printk("bar %d not implemented\n", i);
continue;
}
if (bar & PCI_BASE_ADDRESS_SPACE_IO) {
len = bar & (PCI_BASE_ADDRESS_IO_MASK & 0xFFFF);
len = len & ~(len - 1);
printk("IO space: len in IO %x, BAR %d\n", len, i);
} else {
len = bar & 0xFFFFFFF0;
len = ~len + 1;
printk("len in MEM %x, BAR %d\n", len, i);
}
}
}
#endif
#endif
#ifdef DEBUG
#endif
pDevice->PortOffset = (unsigned long)ioremap(pDevice->memaddr & PCI_BASE_ADDRESS_MEM_MASK, pDevice->io_size);
if (pDevice->PortOffset == 0) {
printk(KERN_ERR DEVICE_NAME ": Failed to IO remapping ..\n");
device_free_info(pDevice);
return -ENODEV;
}
rc = pci_request_regions(pcid, DEVICE_NAME);
if (rc) {
printk(KERN_ERR DEVICE_NAME ": Failed to find PCI device\n");
device_free_info(pDevice);
return -ENODEV;
}
dev->base_addr = pDevice->ioaddr;
#ifdef PLICE_DEBUG
unsigned char value;
VNSvInPortB(pDevice->PortOffset+0x4F, &value);
printk("Before write: value is %x\n", value);
VNSvOutPortB(pDevice->PortOffset, value);
VNSvInPortB(pDevice->PortOffset+0x4F, &value);
printk("After write: value is %x\n", value);
#endif
#ifdef IO_MAP
pDevice->PortOffset = pDevice->ioaddr;
#endif
if (!MACbSoftwareReset(pDevice->PortOffset)) {
printk(KERN_ERR DEVICE_NAME ": Failed to access MAC hardware..\n");
device_free_info(pDevice);
return -ENODEV;
}
MACvInitialize(pDevice->PortOffset);
MACvReadEtherAddress(pDevice->PortOffset, dev->dev_addr);
device_get_options(pDevice, device_nics-1, dev->name);
device_set_options(pDevice);
pDevice->sOpts.flags &= pChip_info->flags;
pDevice->flags = pDevice->sOpts.flags | (pChip_info->flags & 0xFF000000UL);
pDevice->tx_80211 = device_dma0_tx_80211;
pDevice->sMgmtObj.pAdapter = (void *)pDevice;
pDevice->pMgmt = &(pDevice->sMgmtObj);
dev->irq = pcid->irq;
dev->netdev_ops = &device_netdev_ops;
dev->wireless_handlers = (struct iw_handler_def *)&iwctl_handler_def;
rc = register_netdev(dev);
if (rc) {
printk(KERN_ERR DEVICE_NAME " Failed to register netdev\n");
device_free_info(pDevice);
return -ENODEV;
}
device_print_info(pDevice);
pci_set_drvdata(pcid, pDevice);
return 0;
}
static void device_print_info(PSDevice pDevice)
{
struct net_device *dev = pDevice->dev;
DBG_PRT(MSG_LEVEL_INFO, KERN_INFO "%s: %s\n", dev->name, get_chip_name(pDevice->chip_id));
DBG_PRT(MSG_LEVEL_INFO, KERN_INFO "%s: MAC=%pM", dev->name, dev->dev_addr);
#ifdef IO_MAP
DBG_PRT(MSG_LEVEL_INFO, KERN_INFO " IO=0x%lx ", (unsigned long)pDevice->ioaddr);
DBG_PRT(MSG_LEVEL_INFO, KERN_INFO " IRQ=%d \n", pDevice->dev->irq);
#else
DBG_PRT(MSG_LEVEL_INFO, KERN_INFO " IO=0x%lx Mem=0x%lx ",
(unsigned long)pDevice->ioaddr, (unsigned long)pDevice->PortOffset);
DBG_PRT(MSG_LEVEL_INFO, KERN_INFO " IRQ=%d \n", pDevice->dev->irq);
#endif
}
static void vt6655_init_info(struct pci_dev *pcid, PSDevice *ppDevice,
PCHIP_INFO pChip_info) {
PSDevice p;
memset(*ppDevice, 0, sizeof(DEVICE_INFO));
if (pDevice_Infos == NULL) {
pDevice_Infos = *ppDevice;
} else {
for (p = pDevice_Infos; p->next != NULL; p = p->next)
do {} while (0);
p->next = *ppDevice;
(*ppDevice)->prev = p;
}
(*ppDevice)->pcid = pcid;
(*ppDevice)->chip_id = pChip_info->chip_id;
(*ppDevice)->io_size = pChip_info->io_size;
(*ppDevice)->nTxQueues = pChip_info->nTxQueue;
(*ppDevice)->multicast_limit = 32;
spin_lock_init(&((*ppDevice)->lock));
}
static bool device_get_pci_info(PSDevice pDevice, struct pci_dev *pcid) {
u16 pci_cmd;
u8 b;
unsigned int cis_addr;
#ifdef PLICE_DEBUG
unsigned char pci_config[256];
unsigned char value = 0x00;
int ii, j;
u16 max_lat = 0x0000;
memset(pci_config, 0x00, 256);
#endif
pci_read_config_byte(pcid, PCI_REVISION_ID, &pDevice->byRevId);
pci_read_config_word(pcid, PCI_SUBSYSTEM_ID, &pDevice->SubSystemID);
pci_read_config_word(pcid, PCI_SUBSYSTEM_VENDOR_ID, &pDevice->SubVendorID);
pci_read_config_word(pcid, PCI_COMMAND, (u16 *)&(pci_cmd));
pci_set_master(pcid);
pDevice->memaddr = pci_resource_start(pcid, 0);
pDevice->ioaddr = pci_resource_start(pcid, 1);
#ifdef DEBUG
#endif
cis_addr = pci_resource_start(pcid, 2);
pDevice->pcid = pcid;
pci_read_config_byte(pcid, PCI_COMMAND, &b);
pci_write_config_byte(pcid, PCI_COMMAND, (b|PCI_COMMAND_MASTER));
#ifdef PLICE_DEBUG
for (ii = 0; ii < 0xFF; ii++) {
pci_read_config_byte(pcid, ii, &value);
pci_config[ii] = value;
}
for (ii = 0, j = 1; ii < 0x100; ii++, j++) {
if (j % 16 == 0) {
printk("%x:", pci_config[ii]);
printk("\n");
} else {
printk("%x:", pci_config[ii]);
}
}
#endif
return true;
}
static void device_free_info(PSDevice pDevice) {
PSDevice ptr;
struct net_device *dev = pDevice->dev;
ASSERT(pDevice);
device_release_WPADEV(pDevice);
if (wpa_set_wpadev(pDevice, 0) != 0)
printk("unregister wpadev fail?\n");
if (pDevice_Infos == NULL)
return;
for (ptr = pDevice_Infos; ptr && (ptr != pDevice); ptr = ptr->next)
do {} while (0);
if (ptr == pDevice) {
if (ptr == pDevice_Infos)
pDevice_Infos = ptr->next;
else
ptr->prev->next = ptr->next;
} else {
DBG_PRT(MSG_LEVEL_ERR, KERN_ERR "info struct not found\n");
return;
}
#ifdef HOSTAP
if (dev)
vt6655_hostap_set_hostapd(pDevice, 0, 0);
#endif
if (dev)
unregister_netdev(dev);
if (pDevice->PortOffset)
iounmap((void *)pDevice->PortOffset);
if (pDevice->pcid)
pci_release_regions(pDevice->pcid);
if (dev)
free_netdev(dev);
if (pDevice->pcid) {
pci_set_drvdata(pDevice->pcid, NULL);
}
}
static bool device_init_rings(PSDevice pDevice) {
void *vir_pool;
vir_pool = pci_alloc_consistent(pDevice->pcid,
pDevice->sOpts.nRxDescs0 * sizeof(SRxDesc) +
pDevice->sOpts.nRxDescs1 * sizeof(SRxDesc) +
pDevice->sOpts.nTxDescs[0] * sizeof(STxDesc) +
pDevice->sOpts.nTxDescs[1] * sizeof(STxDesc),
&pDevice->pool_dma);
if (vir_pool == NULL) {
DBG_PRT(MSG_LEVEL_ERR, KERN_ERR "%s : allocate desc dma memory failed\n", pDevice->dev->name);
return false;
}
memset(vir_pool, 0,
pDevice->sOpts.nRxDescs0 * sizeof(SRxDesc) +
pDevice->sOpts.nRxDescs1 * sizeof(SRxDesc) +
pDevice->sOpts.nTxDescs[0] * sizeof(STxDesc) +
pDevice->sOpts.nTxDescs[1] * sizeof(STxDesc)
);
pDevice->aRD0Ring = vir_pool;
pDevice->aRD1Ring = vir_pool +
pDevice->sOpts.nRxDescs0 * sizeof(SRxDesc);
pDevice->rd0_pool_dma = pDevice->pool_dma;
pDevice->rd1_pool_dma = pDevice->rd0_pool_dma +
pDevice->sOpts.nRxDescs0 * sizeof(SRxDesc);
pDevice->tx0_bufs = pci_alloc_consistent(pDevice->pcid,
pDevice->sOpts.nTxDescs[0] * PKT_BUF_SZ +
pDevice->sOpts.nTxDescs[1] * PKT_BUF_SZ +
CB_BEACON_BUF_SIZE +
CB_MAX_BUF_SIZE,
&pDevice->tx_bufs_dma0);
if (pDevice->tx0_bufs == NULL) {
DBG_PRT(MSG_LEVEL_ERR, KERN_ERR "%s: allocate buf dma memory failed\n", pDevice->dev->name);
pci_free_consistent(pDevice->pcid,
pDevice->sOpts.nRxDescs0 * sizeof(SRxDesc) +
pDevice->sOpts.nRxDescs1 * sizeof(SRxDesc) +
pDevice->sOpts.nTxDescs[0] * sizeof(STxDesc) +
pDevice->sOpts.nTxDescs[1] * sizeof(STxDesc),
vir_pool, pDevice->pool_dma
);
return false;
}
memset(pDevice->tx0_bufs, 0,
pDevice->sOpts.nTxDescs[0] * PKT_BUF_SZ +
pDevice->sOpts.nTxDescs[1] * PKT_BUF_SZ +
CB_BEACON_BUF_SIZE +
CB_MAX_BUF_SIZE
);
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
static void device_free_rings(PSDevice pDevice) {
pci_free_consistent(pDevice->pcid,
pDevice->sOpts.nRxDescs0 * sizeof(SRxDesc) +
pDevice->sOpts.nRxDescs1 * sizeof(SRxDesc) +
pDevice->sOpts.nTxDescs[0] * sizeof(STxDesc) +
pDevice->sOpts.nTxDescs[1] * sizeof(STxDesc)
,
pDevice->aRD0Ring, pDevice->pool_dma
);
if (pDevice->tx0_bufs)
pci_free_consistent(pDevice->pcid,
pDevice->sOpts.nTxDescs[0] * PKT_BUF_SZ +
pDevice->sOpts.nTxDescs[1] * PKT_BUF_SZ +
CB_BEACON_BUF_SIZE +
CB_MAX_BUF_SIZE,
pDevice->tx0_bufs, pDevice->tx_bufs_dma0
);
}
static void device_init_rd0_ring(PSDevice pDevice) {
int i;
dma_addr_t curr = pDevice->rd0_pool_dma;
PSRxDesc pDesc;
for (i = 0; i < pDevice->sOpts.nRxDescs0; i ++, curr += sizeof(SRxDesc)) {
pDesc = &(pDevice->aRD0Ring[i]);
pDesc->pRDInfo = alloc_rd_info();
ASSERT(pDesc->pRDInfo);
if (!device_alloc_rx_buf(pDevice, pDesc)) {
DBG_PRT(MSG_LEVEL_ERR, KERN_ERR "%s: can not alloc rx bufs\n",
pDevice->dev->name);
}
pDesc->next = &(pDevice->aRD0Ring[(i+1) % pDevice->sOpts.nRxDescs0]);
pDesc->pRDInfo->curr_desc = cpu_to_le32(curr);
pDesc->next_desc = cpu_to_le32(curr + sizeof(SRxDesc));
}
if (i > 0)
pDevice->aRD0Ring[i-1].next_desc = cpu_to_le32(pDevice->rd0_pool_dma);
pDevice->pCurrRD[0] = &(pDevice->aRD0Ring[0]);
}
static void device_init_rd1_ring(PSDevice pDevice) {
int i;
dma_addr_t curr = pDevice->rd1_pool_dma;
PSRxDesc pDesc;
for (i = 0; i < pDevice->sOpts.nRxDescs1; i ++, curr += sizeof(SRxDesc)) {
pDesc = &(pDevice->aRD1Ring[i]);
pDesc->pRDInfo = alloc_rd_info();
ASSERT(pDesc->pRDInfo);
if (!device_alloc_rx_buf(pDevice, pDesc)) {
DBG_PRT(MSG_LEVEL_ERR, KERN_ERR "%s: can not alloc rx bufs\n",
pDevice->dev->name);
}
pDesc->next = &(pDevice->aRD1Ring[(i+1) % pDevice->sOpts.nRxDescs1]);
pDesc->pRDInfo->curr_desc = cpu_to_le32(curr);
pDesc->next_desc = cpu_to_le32(curr + sizeof(SRxDesc));
}
if (i > 0)
pDevice->aRD1Ring[i-1].next_desc = cpu_to_le32(pDevice->rd1_pool_dma);
pDevice->pCurrRD[1] = &(pDevice->aRD1Ring[0]);
}
static void device_init_defrag_cb(PSDevice pDevice) {
int i;
PSDeFragControlBlock pDeF;
for (i = 0; i < CB_MAX_RX_FRAG; i++) {
pDeF = &(pDevice->sRxDFCB[i]);
if (!device_alloc_frag_buf(pDevice, pDeF)) {
DBG_PRT(MSG_LEVEL_ERR, KERN_ERR "%s: can not alloc frag bufs\n",
pDevice->dev->name);
}
}
pDevice->cbDFCB = CB_MAX_RX_FRAG;
pDevice->cbFreeDFCB = pDevice->cbDFCB;
}
static void device_free_rd0_ring(PSDevice pDevice) {
int i;
for (i = 0; i < pDevice->sOpts.nRxDescs0; i++) {
PSRxDesc pDesc = &(pDevice->aRD0Ring[i]);
PDEVICE_RD_INFO pRDInfo = pDesc->pRDInfo;
pci_unmap_single(pDevice->pcid, pRDInfo->skb_dma,
pDevice->rx_buf_sz, PCI_DMA_FROMDEVICE);
dev_kfree_skb(pRDInfo->skb);
kfree((void *)pDesc->pRDInfo);
}
}
static void device_free_rd1_ring(PSDevice pDevice) {
int i;
for (i = 0; i < pDevice->sOpts.nRxDescs1; i++) {
PSRxDesc pDesc = &(pDevice->aRD1Ring[i]);
PDEVICE_RD_INFO pRDInfo = pDesc->pRDInfo;
pci_unmap_single(pDevice->pcid, pRDInfo->skb_dma,
pDevice->rx_buf_sz, PCI_DMA_FROMDEVICE);
dev_kfree_skb(pRDInfo->skb);
kfree((void *)pDesc->pRDInfo);
}
}
static void device_free_frag_buf(PSDevice pDevice) {
PSDeFragControlBlock pDeF;
int i;
for (i = 0; i < CB_MAX_RX_FRAG; i++) {
pDeF = &(pDevice->sRxDFCB[i]);
if (pDeF->skb)
dev_kfree_skb(pDeF->skb);
}
}
static void device_init_td0_ring(PSDevice pDevice) {
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
static void device_init_td1_ring(PSDevice pDevice) {
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
static void device_free_td0_ring(PSDevice pDevice) {
int i;
for (i = 0; i < pDevice->sOpts.nTxDescs[0]; i++) {
PSTxDesc pDesc = &(pDevice->apTD0Rings[i]);
PDEVICE_TD_INFO pTDInfo = pDesc->pTDInfo;
if (pTDInfo->skb_dma && (pTDInfo->skb_dma != pTDInfo->buf_dma))
pci_unmap_single(pDevice->pcid, pTDInfo->skb_dma,
pTDInfo->skb->len, PCI_DMA_TODEVICE);
if (pTDInfo->skb)
dev_kfree_skb(pTDInfo->skb);
kfree((void *)pDesc->pTDInfo);
}
}
static void device_free_td1_ring(PSDevice pDevice) {
int i;
for (i = 0; i < pDevice->sOpts.nTxDescs[1]; i++) {
PSTxDesc pDesc = &(pDevice->apTD1Rings[i]);
PDEVICE_TD_INFO pTDInfo = pDesc->pTDInfo;
if (pTDInfo->skb_dma && (pTDInfo->skb_dma != pTDInfo->buf_dma))
pci_unmap_single(pDevice->pcid, pTDInfo->skb_dma,
pTDInfo->skb->len, PCI_DMA_TODEVICE);
if (pTDInfo->skb)
dev_kfree_skb(pTDInfo->skb);
kfree((void *)pDesc->pTDInfo);
}
}
static int device_rx_srv(PSDevice pDevice, unsigned int uIdx) {
PSRxDesc pRD;
int works = 0;
for (pRD = pDevice->pCurrRD[uIdx];
pRD->m_rd0RD0.f1Owner == OWNED_BY_HOST;
pRD = pRD->next) {
if (works++ > 15)
break;
if (device_receive_frame(pDevice, pRD)) {
if (!device_alloc_rx_buf(pDevice, pRD)) {
DBG_PRT(MSG_LEVEL_ERR, KERN_ERR
"%s: can not allocate rx buf\n", pDevice->dev->name);
break;
}
}
pRD->m_rd0RD0.f1Owner = OWNED_BY_NIC;
pDevice->dev->last_rx = jiffies;
}
pDevice->pCurrRD[uIdx] = pRD;
return works;
}
static bool device_alloc_rx_buf(PSDevice pDevice, PSRxDesc pRD) {
PDEVICE_RD_INFO pRDInfo = pRD->pRDInfo;
pRDInfo->skb = dev_alloc_skb((int)pDevice->rx_buf_sz);
if (pRDInfo->skb == NULL)
return false;
ASSERT(pRDInfo->skb);
pRDInfo->skb->dev = pDevice->dev;
pRDInfo->skb_dma = pci_map_single(pDevice->pcid, skb_tail_pointer(pRDInfo->skb),
pDevice->rx_buf_sz, PCI_DMA_FROMDEVICE);
*((unsigned int *)&(pRD->m_rd0RD0)) = 0;
pRD->m_rd0RD0.wResCount = cpu_to_le16(pDevice->rx_buf_sz);
pRD->m_rd0RD0.f1Owner = OWNED_BY_NIC;
pRD->m_rd1RD1.wReqCount = cpu_to_le16(pDevice->rx_buf_sz);
pRD->buff_addr = cpu_to_le32(pRDInfo->skb_dma);
return true;
}
bool device_alloc_frag_buf(PSDevice pDevice, PSDeFragControlBlock pDeF) {
pDeF->skb = dev_alloc_skb((int)pDevice->rx_buf_sz);
if (pDeF->skb == NULL)
return false;
ASSERT(pDeF->skb);
pDeF->skb->dev = pDevice->dev;
return true;
}
static int device_tx_srv(PSDevice pDevice, unsigned int uIdx) {
PSTxDesc pTD;
bool bFull = false;
int works = 0;
unsigned char byTsr0;
unsigned char byTsr1;
unsigned int uFrameSize, uFIFOHeaderSize;
PSTxBufHead pTxBufHead;
struct net_device_stats *pStats = &pDevice->stats;
struct sk_buff *skb;
unsigned int uNodeIndex;
PSMgmtObject pMgmt = pDevice->pMgmt;
for (pTD = pDevice->apTailTD[uIdx]; pDevice->iTDUsed[uIdx] > 0; pTD = pTD->next) {
if (pTD->m_td0TD0.f1Owner == OWNED_BY_NIC)
break;
if (works++ > 15)
break;
byTsr0 = pTD->m_td0TD0.byTSR0;
byTsr1 = pTD->m_td0TD0.byTSR1;
if (pTD->m_td1TD1.byTCR & TCR_STP) {
if ((pTD->pTDInfo->byFlags & TD_FLAGS_NETIF_SKB) != 0) {
uFIFOHeaderSize = pTD->pTDInfo->dwHeaderLength;
uFrameSize = pTD->pTDInfo->dwReqCount - uFIFOHeaderSize;
pTxBufHead = (PSTxBufHead) (pTD->pTDInfo->buf);
STAvUpdateTDStatCounter(&pDevice->scStatistic,
byTsr0, byTsr1,
(unsigned char *)(pTD->pTDInfo->buf + uFIFOHeaderSize),
uFrameSize, uIdx);
BSSvUpdateNodeTxCounter(pDevice,
byTsr0, byTsr1,
(unsigned char *)(pTD->pTDInfo->buf),
uFIFOHeaderSize
);
if (!(byTsr1 & TSR1_TERR)) {
if (byTsr0 != 0) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " Tx[%d] OK but has error. tsr1[%02X] tsr0[%02X].\n",
(int)uIdx, byTsr1, byTsr0);
}
if ((pTxBufHead->wFragCtl & FRAGCTL_ENDFRAG) != FRAGCTL_NONFRAG) {
pDevice->s802_11Counter.TransmittedFragmentCount++;
}
pStats->tx_packets++;
pStats->tx_bytes += pTD->pTDInfo->skb->len;
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " Tx[%d] dropped & tsr1[%02X] tsr0[%02X].\n",
(int)uIdx, byTsr1, byTsr0);
pStats->tx_errors++;
pStats->tx_dropped++;
}
}
if ((pTD->pTDInfo->byFlags & TD_FLAGS_PRIV_SKB) != 0) {
if (pDevice->bEnableHostapd) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "tx call back netif.. \n");
skb = pTD->pTDInfo->skb;
skb->dev = pDevice->apdev;
skb_reset_mac_header(skb);
skb->pkt_type = PACKET_OTHERHOST;
memset(skb->cb, 0, sizeof(skb->cb));
netif_rx(skb);
}
}
if (byTsr1 & TSR1_TERR) {
if ((pTD->pTDInfo->byFlags & TD_FLAGS_PRIV_SKB) != 0) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " Tx[%d] fail has error. tsr1[%02X] tsr0[%02X].\n",
(int)uIdx, byTsr1, byTsr0);
}
if ((pMgmt->eCurrMode == WMAC_MODE_ESS_AP) &&
(pTD->pTDInfo->byFlags & TD_FLAGS_NETIF_SKB)) {
unsigned short wAID;
unsigned char byMask[8] = {1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80};
skb = pTD->pTDInfo->skb;
if (BSSDBbIsSTAInNodeDB(pMgmt, (unsigned char *)(skb->data), &uNodeIndex)) {
if (pMgmt->sNodeDBTable[uNodeIndex].bPSEnable) {
skb_queue_tail(&pMgmt->sNodeDBTable[uNodeIndex].sTxPSQueue, skb);
pMgmt->sNodeDBTable[uNodeIndex].wEnQueueCnt++;
wAID = pMgmt->sNodeDBTable[uNodeIndex].wAID;
pMgmt->abyPSTxMap[wAID >> 3] |= byMask[wAID & 7];
pTD->pTDInfo->byFlags &= ~(TD_FLAGS_NETIF_SKB);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "tx_srv:tx fail re-queue sta index= %d, QueCnt= %d\n"
, (int)uNodeIndex, pMgmt->sNodeDBTable[uNodeIndex].wEnQueueCnt);
pStats->tx_errors--;
pStats->tx_dropped--;
}
}
}
}
device_free_tx_buf(pDevice, pTD);
pDevice->iTDUsed[uIdx]--;
}
}
if (uIdx == TYPE_AC0DMA) {
if (AVAIL_TD(pDevice, uIdx) < RESERV_AC0DMA) {
bFull = true;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " AC0DMA is Full = %d\n", pDevice->iTDUsed[uIdx]);
}
if (netif_queue_stopped(pDevice->dev) && (bFull == false)) {
netif_wake_queue(pDevice->dev);
}
}
pDevice->apTailTD[uIdx] = pTD;
return works;
}
static void device_error(PSDevice pDevice, unsigned short status) {
if (status & ISR_FETALERR) {
DBG_PRT(MSG_LEVEL_ERR, KERN_ERR
"%s: Hardware fatal error.\n",
pDevice->dev->name);
netif_stop_queue(pDevice->dev);
del_timer(&pDevice->sTimerCommand);
del_timer(&(pDevice->pMgmt->sTimerSecondCallback));
pDevice->bCmdRunning = false;
MACbShutdown(pDevice->PortOffset);
return;
}
}
static void device_free_tx_buf(PSDevice pDevice, PSTxDesc pDesc) {
PDEVICE_TD_INFO pTDInfo = pDesc->pTDInfo;
struct sk_buff *skb = pTDInfo->skb;
if (pTDInfo->skb_dma && (pTDInfo->skb_dma != pTDInfo->buf_dma)) {
pci_unmap_single(pDevice->pcid, pTDInfo->skb_dma, skb->len,
PCI_DMA_TODEVICE);
}
if ((pTDInfo->byFlags & TD_FLAGS_NETIF_SKB) != 0)
dev_kfree_skb_irq(skb);
pTDInfo->skb_dma = 0;
pTDInfo->skb = 0;
pTDInfo->byFlags = 0;
}
void InitRxManagementQueue(PSDevice pDevice)
{
pDevice->rxManeQueue.packet_num = 0;
pDevice->rxManeQueue.head = pDevice->rxManeQueue.tail = 0;
}
int MlmeThread(
void *Context)
{
PSDevice pDevice = (PSDevice) Context;
PSRxMgmtPacket pRxMgmtPacket;
#if 1
while (1) {
#if 1
spin_lock_irq(&pDevice->lock);
while (pDevice->rxManeQueue.packet_num != 0) {
pRxMgmtPacket = DeQueue(pDevice);
vMgrRxManagePacket(pDevice, pDevice->pMgmt, pRxMgmtPacket);
}
spin_unlock_irq(&pDevice->lock);
if (mlme_kill == 0)
break;
#endif
schedule();
if (mlme_kill == 0)
break;
}
#endif
return 0;
}
static int device_open(struct net_device *dev) {
PSDevice pDevice = (PSDevice)netdev_priv(dev);
int i;
#ifdef WPA_SM_Transtatus
extern SWPAResult wpa_Result;
#endif
pDevice->rx_buf_sz = PKT_BUF_SZ;
if (!device_init_rings(pDevice)) {
return -ENOMEM;
}
i = request_irq(pDevice->pcid->irq, &device_intr, IRQF_SHARED, dev->name, dev);
if (i)
return i;
#ifdef WPA_SM_Transtatus
memset(wpa_Result.ifname, 0, sizeof(wpa_Result.ifname));
wpa_Result.proto = 0;
wpa_Result.key_mgmt = 0;
wpa_Result.eap_type = 0;
wpa_Result.authenticated = false;
pDevice->fWPA_Authened = false;
#endif
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "call device init rd0 ring\n");
device_init_rd0_ring(pDevice);
device_init_rd1_ring(pDevice);
device_init_defrag_cb(pDevice);
device_init_td0_ring(pDevice);
device_init_td1_ring(pDevice);
if (pDevice->bDiversityRegCtlON) {
device_init_diversity_timer(pDevice);
}
vMgrObjectInit(pDevice);
vMgrTimerInit(pDevice);
#ifdef TASK_LET
tasklet_init(&pDevice->RxMngWorkItem, (void *)MngWorkItem, (unsigned long)pDevice);
#endif
#ifdef THREAD
InitRxManagementQueue(pDevice);
mlme_kill = 0;
mlme_task = kthread_run(MlmeThread, (void *)pDevice, "MLME");
if (IS_ERR(mlme_task)) {
printk("thread create fail\n");
return -1;
}
mlme_kill = 1;
#endif
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "call device_init_registers\n");
device_init_registers(pDevice, DEVICE_INIT_COLD);
MACvReadEtherAddress(pDevice->PortOffset, pDevice->abyCurrentNetAddr);
memcpy(pDevice->pMgmt->abyMACAddr, pDevice->abyCurrentNetAddr, ETH_ALEN);
device_set_multi(pDevice->dev);
KeyvInitTable(&pDevice->sKey, pDevice->PortOffset);
add_timer(&(pDevice->pMgmt->sTimerSecondCallback));
#ifdef WPA_SUPPLICANT_DRIVER_WEXT_SUPPORT
pDevice->bwextcount = 0;
pDevice->bWPASuppWextEnabled = false;
#endif
pDevice->byReAssocCount = 0;
pDevice->bWPADEVUp = false;
if ((pDevice->bEncryptionEnable == true) && (pDevice->bTransmitKey == true)) {
KeybSetDefaultKey(&(pDevice->sKey),
(unsigned long)(pDevice->byKeyIndex | (1 << 31)),
pDevice->uKeyLength,
NULL,
pDevice->abyKey,
KEY_CTL_WEP,
pDevice->PortOffset,
pDevice->byLocalID
);
pDevice->eEncryptionStatus = Ndis802_11Encryption1Enabled;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "call MACvIntEnable\n");
MACvIntEnable(pDevice->PortOffset, IMR_MASK_VALUE);
if (pDevice->pMgmt->eConfigMode == WMAC_CONFIG_AP) {
bScheduleCommand((void *)pDevice, WLAN_CMD_RUN_AP, NULL);
} else {
bScheduleCommand((void *)pDevice, WLAN_CMD_BSSID_SCAN, NULL);
bScheduleCommand((void *)pDevice, WLAN_CMD_SSID, NULL);
}
pDevice->flags |= DEVICE_FLAGS_OPENED;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "device_open success.. \n");
return 0;
}
static int device_close(struct net_device *dev) {
PSDevice pDevice = (PSDevice)netdev_priv(dev);
PSMgmtObject pMgmt = pDevice->pMgmt;
#ifdef THREAD
mlme_kill = 0;
#endif
if (pDevice->bLinkPass) {
bScheduleCommand((void *)pDevice, WLAN_CMD_DISASSOCIATE, NULL);
mdelay(30);
}
#ifdef TxInSleep
del_timer(&pDevice->sTimerTxData);
#endif
del_timer(&pDevice->sTimerCommand);
del_timer(&pMgmt->sTimerSecondCallback);
if (pDevice->bDiversityRegCtlON) {
del_timer(&pDevice->TimerSQ3Tmax1);
del_timer(&pDevice->TimerSQ3Tmax2);
del_timer(&pDevice->TimerSQ3Tmax3);
}
#ifdef TASK_LET
tasklet_kill(&pDevice->RxMngWorkItem);
#endif
netif_stop_queue(dev);
pDevice->bCmdRunning = false;
MACbShutdown(pDevice->PortOffset);
MACbSoftwareReset(pDevice->PortOffset);
CARDbRadioPowerOff(pDevice);
pDevice->bLinkPass = false;
memset(pMgmt->abyCurrBSSID, 0, 6);
pMgmt->eCurrState = WMAC_STATE_IDLE;
device_free_td0_ring(pDevice);
device_free_td1_ring(pDevice);
device_free_rd0_ring(pDevice);
device_free_rd1_ring(pDevice);
device_free_frag_buf(pDevice);
device_free_rings(pDevice);
BSSvClearNodeDBTable(pDevice, 0);
free_irq(dev->irq, dev);
pDevice->flags &= (~DEVICE_FLAGS_OPENED);
device_release_WPADEV(pDevice);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "device_close.. \n");
return 0;
}
static int device_dma0_tx_80211(struct sk_buff *skb, struct net_device *dev) {
PSDevice pDevice = netdev_priv(dev);
unsigned char *pbMPDU;
unsigned int cbMPDULen = 0;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "device_dma0_tx_80211\n");
spin_lock_irq(&pDevice->lock);
if (AVAIL_TD(pDevice, TYPE_TXDMA0) <= 0) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "device_dma0_tx_80211, td0 <=0\n");
dev_kfree_skb_irq(skb);
spin_unlock_irq(&pDevice->lock);
return 0;
}
if (pDevice->bStopTx0Pkt == true) {
dev_kfree_skb_irq(skb);
spin_unlock_irq(&pDevice->lock);
return 0;
}
cbMPDULen = skb->len;
pbMPDU = skb->data;
vDMA0_tx_80211(pDevice, skb, pbMPDU, cbMPDULen);
spin_unlock_irq(&pDevice->lock);
return 0;
}
bool device_dma0_xmit(PSDevice pDevice, struct sk_buff *skb, unsigned int uNodeIndex) {
PSMgmtObject pMgmt = pDevice->pMgmt;
PSTxDesc pHeadTD, pLastTD;
unsigned int cbFrameBodySize;
unsigned int uMACfragNum;
unsigned char byPktType;
bool bNeedEncryption = false;
PSKeyItem pTransmitKey = NULL;
unsigned int cbHeaderSize;
unsigned int ii;
SKeyItem STempKey;
if (pDevice->bStopTx0Pkt == true) {
dev_kfree_skb_irq(skb);
return false;
}
if (AVAIL_TD(pDevice, TYPE_TXDMA0) <= 0) {
dev_kfree_skb_irq(skb);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "device_dma0_xmit, td0 <=0\n");
return false;
}
if (pMgmt->eCurrMode == WMAC_MODE_ESS_AP) {
if (pDevice->uAssocCount == 0) {
dev_kfree_skb_irq(skb);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "device_dma0_xmit, assocCount = 0\n");
return false;
}
}
pHeadTD = pDevice->apCurrTD[TYPE_TXDMA0];
pHeadTD->m_td1TD1.byTCR = (TCR_EDP|TCR_STP);
memcpy(pDevice->sTxEthHeader.abyDstAddr, (unsigned char *)(skb->data), ETH_HLEN);
cbFrameBodySize = skb->len - ETH_HLEN;
if (ntohs(pDevice->sTxEthHeader.wType) > ETH_DATA_LEN) {
cbFrameBodySize += 8;
}
uMACfragNum = cbGetFragCount(pDevice, pTransmitKey, cbFrameBodySize, &pDevice->sTxEthHeader);
if (uMACfragNum > AVAIL_TD(pDevice, TYPE_TXDMA0)) {
dev_kfree_skb_irq(skb);
return false;
}
byPktType = (unsigned char)pDevice->byPacketType;
if (pDevice->bFixRate) {
if (pDevice->eCurrentPHYType == PHY_TYPE_11B) {
if (pDevice->uConnectionRate >= RATE_11M) {
pDevice->wCurrentRate = RATE_11M;
} else {
pDevice->wCurrentRate = (unsigned short)pDevice->uConnectionRate;
}
} else {
if (pDevice->uConnectionRate >= RATE_54M)
pDevice->wCurrentRate = RATE_54M;
else
pDevice->wCurrentRate = (unsigned short)pDevice->uConnectionRate;
}
} else {
pDevice->wCurrentRate = pDevice->pMgmt->sNodeDBTable[uNodeIndex].wTxDataRate;
}
if (pMgmt->sNodeDBTable[uNodeIndex].bShortPreamble) {
pDevice->byPreambleType = pDevice->byShortPreamble;
} else {
pDevice->byPreambleType = PREAMBLE_LONG;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "dma0: pDevice->wCurrentRate = %d \n", pDevice->wCurrentRate);
if (pDevice->wCurrentRate <= RATE_11M) {
byPktType = PK_TYPE_11B;
} else if (pDevice->eCurrentPHYType == PHY_TYPE_11A) {
byPktType = PK_TYPE_11A;
} else {
if (pDevice->bProtectMode == true) {
byPktType = PK_TYPE_11GB;
} else {
byPktType = PK_TYPE_11GA;
}
}
if (pDevice->bEncryptionEnable == true)
bNeedEncryption = true;
if (pDevice->bEnableHostWEP) {
pTransmitKey = &STempKey;
pTransmitKey->byCipherSuite = pMgmt->sNodeDBTable[uNodeIndex].byCipherSuite;
pTransmitKey->dwKeyIndex = pMgmt->sNodeDBTable[uNodeIndex].dwKeyIndex;
pTransmitKey->uKeyLength = pMgmt->sNodeDBTable[uNodeIndex].uWepKeyLength;
pTransmitKey->dwTSC47_16 = pMgmt->sNodeDBTable[uNodeIndex].dwTSC47_16;
pTransmitKey->wTSC15_0 = pMgmt->sNodeDBTable[uNodeIndex].wTSC15_0;
memcpy(pTransmitKey->abyKey,
&pMgmt->sNodeDBTable[uNodeIndex].abyWepKey[0],
pTransmitKey->uKeyLength
);
}
vGenerateFIFOHeader(pDevice, byPktType, pDevice->pbyTmpBuff, bNeedEncryption,
cbFrameBodySize, TYPE_TXDMA0, pHeadTD,
&pDevice->sTxEthHeader, (unsigned char *)skb->data, pTransmitKey, uNodeIndex,
&uMACfragNum,
&cbHeaderSize
);
if (MACbIsRegBitsOn(pDevice->PortOffset, MAC_REG_PSCTL, PSCTL_PS)) {
MACbPSWakeup(pDevice->PortOffset);
}
pDevice->bPWBitOn = false;
pLastTD = pHeadTD;
for (ii = 0; ii < uMACfragNum; ii++) {
wmb();
pHeadTD->m_td0TD0.f1Owner = OWNED_BY_NIC;
wmb();
if (ii == (uMACfragNum - 1))
pLastTD = pHeadTD;
pHeadTD = pHeadTD->next;
}
pLastTD->pTDInfo->skb = skb;
pLastTD->pTDInfo->byFlags = 0;
pLastTD->pTDInfo->byFlags |= TD_FLAGS_NETIF_SKB;
pDevice->apCurrTD[TYPE_TXDMA0] = pHeadTD;
MACvTransmit0(pDevice->PortOffset);
return true;
}
static int device_xmit(struct sk_buff *skb, struct net_device *dev) {
PSDevice pDevice = netdev_priv(dev);
PSMgmtObject pMgmt = pDevice->pMgmt;
PSTxDesc pHeadTD, pLastTD;
unsigned int uNodeIndex = 0;
unsigned char byMask[8] = {1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80};
unsigned short wAID;
unsigned int uMACfragNum = 1;
unsigned int cbFrameBodySize;
unsigned char byPktType;
unsigned int cbHeaderSize;
bool bNeedEncryption = false;
PSKeyItem pTransmitKey = NULL;
SKeyItem STempKey;
unsigned int ii;
bool bTKIP_UseGTK = false;
bool bNeedDeAuth = false;
unsigned char *pbyBSSID;
bool bNodeExist = false;
spin_lock_irq(&pDevice->lock);
if (pDevice->bLinkPass == false) {
dev_kfree_skb_irq(skb);
spin_unlock_irq(&pDevice->lock);
return 0;
}
if (pDevice->bStopDataPkt) {
dev_kfree_skb_irq(skb);
spin_unlock_irq(&pDevice->lock);
return 0;
}
if (pMgmt->eCurrMode == WMAC_MODE_ESS_AP) {
if (pDevice->uAssocCount == 0) {
dev_kfree_skb_irq(skb);
spin_unlock_irq(&pDevice->lock);
return 0;
}
if (is_multicast_ether_addr((unsigned char *)(skb->data))) {
uNodeIndex = 0;
bNodeExist = true;
if (pMgmt->sNodeDBTable[0].bPSEnable) {
skb_queue_tail(&(pMgmt->sNodeDBTable[0].sTxPSQueue), skb);
pMgmt->sNodeDBTable[0].wEnQueueCnt++;
pMgmt->abyPSTxMap[0] |= byMask[0];
spin_unlock_irq(&pDevice->lock);
return 0;
}
} else {
if (BSSDBbIsSTAInNodeDB(pMgmt, (unsigned char *)(skb->data), &uNodeIndex)) {
if (pMgmt->sNodeDBTable[uNodeIndex].bPSEnable) {
skb_queue_tail(&pMgmt->sNodeDBTable[uNodeIndex].sTxPSQueue, skb);
pMgmt->sNodeDBTable[uNodeIndex].wEnQueueCnt++;
wAID = pMgmt->sNodeDBTable[uNodeIndex].wAID;
pMgmt->abyPSTxMap[wAID >> 3] |= byMask[wAID & 7];
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Set:pMgmt->abyPSTxMap[%d]= %d\n",
(wAID >> 3), pMgmt->abyPSTxMap[wAID >> 3]);
spin_unlock_irq(&pDevice->lock);
return 0;
}
if (pMgmt->sNodeDBTable[uNodeIndex].bShortPreamble) {
pDevice->byPreambleType = pDevice->byShortPreamble;
} else {
pDevice->byPreambleType = PREAMBLE_LONG;
}
bNodeExist = true;
}
}
if (bNodeExist == false) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG "Unknown STA not found in node DB \n");
dev_kfree_skb_irq(skb);
spin_unlock_irq(&pDevice->lock);
return 0;
}
}
pHeadTD = pDevice->apCurrTD[TYPE_AC0DMA];
pHeadTD->m_td1TD1.byTCR = (TCR_EDP|TCR_STP);
memcpy(pDevice->sTxEthHeader.abyDstAddr, (unsigned char *)(skb->data), ETH_HLEN);
cbFrameBodySize = skb->len - ETH_HLEN;
if (ntohs(pDevice->sTxEthHeader.wType) > ETH_DATA_LEN) {
cbFrameBodySize += 8;
}
if (pDevice->bEncryptionEnable == true) {
bNeedEncryption = true;
do {
if ((pDevice->pMgmt->eCurrMode == WMAC_MODE_ESS_STA) &&
(pDevice->pMgmt->eCurrState == WMAC_STATE_ASSOC)) {
pbyBSSID = pDevice->abyBSSID;
if (KeybGetTransmitKey(&(pDevice->sKey), pbyBSSID, PAIRWISE_KEY, &pTransmitKey) == false) {
if (KeybGetTransmitKey(&(pDevice->sKey), pbyBSSID, GROUP_KEY, &pTransmitKey) == true) {
bTKIP_UseGTK = true;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG "Get GTK.\n");
break;
}
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG "Get PTK.\n");
break;
}
} else if (pDevice->pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) {
pbyBSSID = pDevice->sTxEthHeader.abyDstAddr;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG "IBSS Serach Key: \n");
for (ii = 0; ii < 6; ii++)
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG "%x \n", *(pbyBSSID+ii));
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG "\n");
if (KeybGetTransmitKey(&(pDevice->sKey), pbyBSSID, PAIRWISE_KEY, &pTransmitKey) == true)
break;
}
pbyBSSID = pDevice->abyBroadcastAddr;
if (KeybGetTransmitKey(&(pDevice->sKey), pbyBSSID, GROUP_KEY, &pTransmitKey) == false) {
pTransmitKey = NULL;
if (pDevice->pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG "IBSS and KEY is NULL. [%d]\n", pDevice->pMgmt->eCurrMode);
} else
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG "NOT IBSS and KEY is NULL. [%d]\n", pDevice->pMgmt->eCurrMode);
} else {
bTKIP_UseGTK = true;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG "Get GTK.\n");
}
} while (false);
}
if (pDevice->bEnableHostWEP) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG "acdma0: STA index %d\n", uNodeIndex);
if (pDevice->bEncryptionEnable == true) {
pTransmitKey = &STempKey;
pTransmitKey->byCipherSuite = pMgmt->sNodeDBTable[uNodeIndex].byCipherSuite;
pTransmitKey->dwKeyIndex = pMgmt->sNodeDBTable[uNodeIndex].dwKeyIndex;
pTransmitKey->uKeyLength = pMgmt->sNodeDBTable[uNodeIndex].uWepKeyLength;
pTransmitKey->dwTSC47_16 = pMgmt->sNodeDBTable[uNodeIndex].dwTSC47_16;
pTransmitKey->wTSC15_0 = pMgmt->sNodeDBTable[uNodeIndex].wTSC15_0;
memcpy(pTransmitKey->abyKey,
&pMgmt->sNodeDBTable[uNodeIndex].abyWepKey[0],
pTransmitKey->uKeyLength
);
}
}
uMACfragNum = cbGetFragCount(pDevice, pTransmitKey, cbFrameBodySize, &pDevice->sTxEthHeader);
if (uMACfragNum > AVAIL_TD(pDevice, TYPE_AC0DMA)) {
DBG_PRT(MSG_LEVEL_ERR, KERN_DEBUG "uMACfragNum > AVAIL_TD(TYPE_AC0DMA) = %d\n", uMACfragNum);
dev_kfree_skb_irq(skb);
spin_unlock_irq(&pDevice->lock);
return 0;
}
if (pTransmitKey != NULL) {
if ((pTransmitKey->byCipherSuite == KEY_CTL_WEP) &&
(pTransmitKey->uKeyLength == WLAN_WEP232_KEYLEN)) {
uMACfragNum = 1;
}
}
byPktType = (unsigned char)pDevice->byPacketType;
if (pDevice->bFixRate) {
#ifdef PLICE_DEBUG
printk("Fix Rate: PhyType is %d,ConnectionRate is %d\n", pDevice->eCurrentPHYType, pDevice->uConnectionRate);
#endif
if (pDevice->eCurrentPHYType == PHY_TYPE_11B) {
if (pDevice->uConnectionRate >= RATE_11M) {
pDevice->wCurrentRate = RATE_11M;
} else {
pDevice->wCurrentRate = (unsigned short)pDevice->uConnectionRate;
}
} else {
if ((pDevice->eCurrentPHYType == PHY_TYPE_11A) &&
(pDevice->uConnectionRate <= RATE_6M)) {
pDevice->wCurrentRate = RATE_6M;
} else {
if (pDevice->uConnectionRate >= RATE_54M)
pDevice->wCurrentRate = RATE_54M;
else
pDevice->wCurrentRate = (unsigned short)pDevice->uConnectionRate;
}
}
pDevice->byACKRate = (unsigned char) pDevice->wCurrentRate;
pDevice->byTopCCKBasicRate = RATE_1M;
pDevice->byTopOFDMBasicRate = RATE_6M;
} else {
if (pDevice->sTxEthHeader.wType == TYPE_PKT_802_1x) {
if (pDevice->eCurrentPHYType != PHY_TYPE_11A) {
pDevice->wCurrentRate = RATE_1M;
pDevice->byACKRate = RATE_1M;
pDevice->byTopCCKBasicRate = RATE_1M;
pDevice->byTopOFDMBasicRate = RATE_6M;
} else {
pDevice->wCurrentRate = RATE_6M;
pDevice->byACKRate = RATE_6M;
pDevice->byTopCCKBasicRate = RATE_1M;
pDevice->byTopOFDMBasicRate = RATE_6M;
}
} else {
VNTWIFIvGetTxRate(pDevice->pMgmt,
pDevice->sTxEthHeader.abyDstAddr,
&(pDevice->wCurrentRate),
&(pDevice->byACKRate),
&(pDevice->byTopCCKBasicRate),
&(pDevice->byTopOFDMBasicRate));
}
}
if (pDevice->wCurrentRate <= RATE_11M) {
byPktType = PK_TYPE_11B;
} else if (pDevice->eCurrentPHYType == PHY_TYPE_11A) {
byPktType = PK_TYPE_11A;
} else {
if (pDevice->bProtectMode == true) {
byPktType = PK_TYPE_11GB;
} else {
byPktType = PK_TYPE_11GA;
}
}
if (bNeedEncryption == true) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "ntohs Pkt Type=%04x\n", ntohs(pDevice->sTxEthHeader.wType));
if ((pDevice->sTxEthHeader.wType) == TYPE_PKT_802_1x) {
bNeedEncryption = false;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Pkt Type=%04x\n", (pDevice->sTxEthHeader.wType));
if ((pDevice->pMgmt->eCurrMode == WMAC_MODE_ESS_STA) && (pDevice->pMgmt->eCurrState == WMAC_STATE_ASSOC)) {
if (pTransmitKey == NULL) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Don't Find TX KEY\n");
} else {
if (bTKIP_UseGTK == true) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "error: KEY is GTK!!~~\n");
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Find PTK [%lX]\n", pTransmitKey->dwKeyIndex);
bNeedEncryption = true;
}
}
}
if (pDevice->byCntMeasure == 2) {
bNeedDeAuth = true;
pDevice->s802_11Counter.TKIPCounterMeasuresInvoked++;
}
if (pDevice->bEnableHostWEP) {
if ((uNodeIndex != 0) &&
(pMgmt->sNodeDBTable[uNodeIndex].dwKeyIndex & PAIRWISE_KEY)) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Find PTK [%lX]\n", pTransmitKey->dwKeyIndex);
bNeedEncryption = true;
}
}
} else {
if (pTransmitKey == NULL) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "return no tx key\n");
dev_kfree_skb_irq(skb);
spin_unlock_irq(&pDevice->lock);
return 0;
}
}
}
vGenerateFIFOHeader(pDevice, byPktType, pDevice->pbyTmpBuff, bNeedEncryption,
cbFrameBodySize, TYPE_AC0DMA, pHeadTD,
&pDevice->sTxEthHeader, (unsigned char *)skb->data, pTransmitKey, uNodeIndex,
&uMACfragNum,
&cbHeaderSize
);
if (MACbIsRegBitsOn(pDevice->PortOffset, MAC_REG_PSCTL, PSCTL_PS)) {
MACbPSWakeup(pDevice->PortOffset);
}
pDevice->bPWBitOn = false;
pLastTD = pHeadTD;
for (ii = 0; ii < uMACfragNum; ii++) {
wmb();
pHeadTD->m_td0TD0.f1Owner = OWNED_BY_NIC;
wmb();
if (ii == uMACfragNum - 1)
pLastTD = pHeadTD;
pHeadTD = pHeadTD->next;
}
pLastTD->pTDInfo->skb = skb;
pLastTD->pTDInfo->byFlags = 0;
pLastTD->pTDInfo->byFlags |= TD_FLAGS_NETIF_SKB;
#ifdef TxInSleep
pDevice->nTxDataTimeCout = 0;
#endif
if (AVAIL_TD(pDevice, TYPE_AC0DMA) <= 1) {
netif_stop_queue(dev);
}
pDevice->apCurrTD[TYPE_AC0DMA] = pHeadTD;
if (pDevice->bFixRate) {
printk("FixRate:Rate is %d,TxPower is %d\n", pDevice->wCurrentRate, pDevice->byCurPwr);
} else {
}
{
unsigned char Protocol_Version;
unsigned char Packet_Type;
unsigned char Descriptor_type;
unsigned short Key_info;
bool bTxeapol_key = false;
Protocol_Version = skb->data[ETH_HLEN];
Packet_Type = skb->data[ETH_HLEN+1];
Descriptor_type = skb->data[ETH_HLEN+1+1+2];
Key_info = (skb->data[ETH_HLEN+1+1+2+1] << 8)|(skb->data[ETH_HLEN+1+1+2+2]);
if (pDevice->sTxEthHeader.wType == TYPE_PKT_802_1x) {
if (((Protocol_Version == 1) || (Protocol_Version == 2)) &&
(Packet_Type == 3)) {
bTxeapol_key = true;
if ((Descriptor_type == 254) || (Descriptor_type == 2)) {
if (!(Key_info & BIT3) &&
(Key_info & BIT8) && (Key_info & BIT9)) {
pDevice->fWPA_Authened = true;
if (Descriptor_type == 254)
printk("WPA ");
else
printk("WPA2 ");
printk("Authentication completed!!\n");
}
}
}
}
}
MACvTransmitAC0(pDevice->PortOffset);
dev->trans_start = jiffies;
spin_unlock_irq(&pDevice->lock);
return 0;
}
static irqreturn_t device_intr(int irq, void *dev_instance) {
struct net_device *dev = dev_instance;
PSDevice pDevice = (PSDevice)netdev_priv(dev);
int max_count = 0;
unsigned long dwMIBCounter = 0;
PSMgmtObject pMgmt = pDevice->pMgmt;
unsigned char byOrgPageSel = 0;
int handled = 0;
unsigned char byData = 0;
int ii = 0;
MACvReadISR(pDevice->PortOffset, &pDevice->dwIsr);
if (pDevice->dwIsr == 0)
return IRQ_RETVAL(handled);
if (pDevice->dwIsr == 0xffffffff) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "dwIsr = 0xffff\n");
return IRQ_RETVAL(handled);
}
handled = 1;
MACvIntDisable(pDevice->PortOffset);
spin_lock_irq(&pDevice->lock);
VNSvInPortB(pDevice->PortOffset + MAC_REG_PAGE1SEL, &byOrgPageSel);
if (byOrgPageSel == 1) {
MACvSelectPage0(pDevice->PortOffset);
} else
byOrgPageSel = 0;
MACvReadMIBCounter(pDevice->PortOffset, &dwMIBCounter);
STAvUpdate802_11Counter(&pDevice->s802_11Counter, &pDevice->scStatistic , dwMIBCounter);
while (pDevice->dwIsr != 0) {
STAvUpdateIsrStatCounter(&pDevice->scStatistic, pDevice->dwIsr);
MACvWriteISR(pDevice->PortOffset, pDevice->dwIsr);
if (pDevice->dwIsr & ISR_FETALERR) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " ISR_FETALERR \n");
VNSvOutPortB(pDevice->PortOffset + MAC_REG_SOFTPWRCTL, 0);
VNSvOutPortW(pDevice->PortOffset + MAC_REG_SOFTPWRCTL, SOFTPWRCTL_SWPECTI);
device_error(pDevice, pDevice->dwIsr);
}
if (pDevice->byLocalID > REV_ID_VT3253_B1) {
if (pDevice->dwIsr & ISR_MEASURESTART) {
pDevice->byOrgChannel = pDevice->byCurrentCh;
VNSvInPortB(pDevice->PortOffset + MAC_REG_RCR, &(pDevice->byOrgRCR));
VNSvOutPortB(pDevice->PortOffset + MAC_REG_RCR, (RCR_RXALLTYPE | RCR_UNICAST | RCR_BROADCAST | RCR_MULTICAST | RCR_WPAERR));
MACvSelectPage1(pDevice->PortOffset);
VNSvInPortD(pDevice->PortOffset + MAC_REG_MAR0, &(pDevice->dwOrgMAR0));
VNSvInPortD(pDevice->PortOffset + MAC_REG_MAR4, &(pDevice->dwOrgMAR4));
MACvSelectPage0(pDevice->PortOffset);
if (set_channel(pDevice, pDevice->pCurrMeasureEID->sReq.byChannel) == true) {
pDevice->bMeasureInProgress = true;
MACvSelectPage1(pDevice->PortOffset);
MACvRegBitsOn(pDevice->PortOffset, MAC_REG_MSRCTL, MSRCTL_READY);
MACvSelectPage0(pDevice->PortOffset);
pDevice->byBasicMap = 0;
pDevice->byCCAFraction = 0;
for (ii = 0; ii < 8; ii++) {
pDevice->dwRPIs[ii] = 0;
}
} else {
MACvRegBitsOff(pDevice->PortOffset, MAC_REG_MSRCTL, MSRCTL_EN);
s_vCompleteCurrentMeasure(pDevice, MEASURE_MODE_INCAPABLE);
MACvSelectPage1(pDevice->PortOffset);
MACvRegBitsOn(pDevice->PortOffset, MAC_REG_MSRCTL+1, MSRCTL1_TXPAUSE);
MACvSelectPage0(pDevice->PortOffset);
}
}
if (pDevice->dwIsr & ISR_MEASUREEND) {
pDevice->bMeasureInProgress = false;
VNSvOutPortB(pDevice->PortOffset + MAC_REG_RCR, pDevice->byOrgRCR);
MACvSelectPage1(pDevice->PortOffset);
VNSvOutPortD(pDevice->PortOffset + MAC_REG_MAR0, pDevice->dwOrgMAR0);
VNSvOutPortD(pDevice->PortOffset + MAC_REG_MAR4, pDevice->dwOrgMAR4);
VNSvInPortB(pDevice->PortOffset + MAC_REG_MSRBBSTS, &byData);
pDevice->byBasicMap |= (byData >> 4);
VNSvInPortB(pDevice->PortOffset + MAC_REG_CCAFRACTION, &pDevice->byCCAFraction);
VNSvInPortB(pDevice->PortOffset + MAC_REG_MSRCTL, &byData);
MACvRegBitsOff(pDevice->PortOffset, MAC_REG_MSRCTL, MSRCTL_EN);
MACvSelectPage0(pDevice->PortOffset);
set_channel(pDevice, pDevice->byOrgChannel);
MACvSelectPage1(pDevice->PortOffset);
MACvRegBitsOn(pDevice->PortOffset, MAC_REG_MSRCTL+1, MSRCTL1_TXPAUSE);
MACvSelectPage0(pDevice->PortOffset);
if (byData & MSRCTL_FINISH) {
s_vCompleteCurrentMeasure(pDevice, 0);
} else {
s_vCompleteCurrentMeasure(pDevice, MEASURE_MODE_LATE);
}
}
if (pDevice->dwIsr & ISR_QUIETSTART) {
do {
;
} while (CARDbStartQuiet(pDevice) == false);
}
}
if (pDevice->dwIsr & ISR_TBTT) {
if (pDevice->bEnableFirstQuiet == true) {
pDevice->byQuietStartCount--;
if (pDevice->byQuietStartCount == 0) {
pDevice->bEnableFirstQuiet = false;
MACvSelectPage1(pDevice->PortOffset);
MACvRegBitsOn(pDevice->PortOffset, MAC_REG_MSRCTL, (MSRCTL_QUIETTXCHK | MSRCTL_QUIETEN));
MACvSelectPage0(pDevice->PortOffset);
}
}
if ((pDevice->bChannelSwitch == true) &&
(pDevice->eOPMode == OP_MODE_INFRASTRUCTURE)) {
pDevice->byChannelSwitchCount--;
if (pDevice->byChannelSwitchCount == 0) {
pDevice->bChannelSwitch = false;
set_channel(pDevice, pDevice->byNewChannel);
VNTWIFIbChannelSwitch(pDevice->pMgmt, pDevice->byNewChannel);
MACvSelectPage1(pDevice->PortOffset);
MACvRegBitsOn(pDevice->PortOffset, MAC_REG_MSRCTL+1, MSRCTL1_TXPAUSE);
MACvSelectPage0(pDevice->PortOffset);
CARDbStartTxPacket(pDevice, PKT_TYPE_802_11_ALL);
}
}
if (pDevice->eOPMode == OP_MODE_ADHOC) {
} else {
if ((pDevice->bUpdateBBVGA) && (pDevice->bLinkPass == true) && (pDevice->uCurrRSSI != 0)) {
long ldBm;
RFvRSSITodBm(pDevice, (unsigned char) pDevice->uCurrRSSI, &ldBm);
for (ii = 0; ii < BB_VGA_LEVEL; ii++) {
if (ldBm < pDevice->ldBmThreshold[ii]) {
pDevice->byBBVGANew = pDevice->abyBBVGA[ii];
break;
}
}
if (pDevice->byBBVGANew != pDevice->byBBVGACurrent) {
pDevice->uBBVGADiffCount++;
if (pDevice->uBBVGADiffCount == 1) {
BBvSetVGAGainOffset(pDevice, pDevice->byBBVGANew);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "First RSSI[%d] NewGain[%d] OldGain[%d] Count[%d]\n",
(int)ldBm, pDevice->byBBVGANew, pDevice->byBBVGACurrent, (int)pDevice->uBBVGADiffCount);
}
if (pDevice->uBBVGADiffCount >= BB_VGA_CHANGE_THRESHOLD) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "RSSI[%d] NewGain[%d] OldGain[%d] Count[%d]\n",
(int)ldBm, pDevice->byBBVGANew, pDevice->byBBVGACurrent, (int)pDevice->uBBVGADiffCount);
BBvSetVGAGainOffset(pDevice, pDevice->byBBVGANew);
}
} else {
pDevice->uBBVGADiffCount = 1;
}
}
}
pDevice->bBeaconSent = false;
if (pDevice->bEnablePSMode) {
PSbIsNextTBTTWakeUp((void *)pDevice);
}
if ((pDevice->eOPMode == OP_MODE_AP) ||
(pDevice->eOPMode == OP_MODE_ADHOC)) {
MACvOneShotTimer1MicroSec(pDevice->PortOffset,
(pMgmt->wIBSSBeaconPeriod - MAKE_BEACON_RESERVED) << 10);
}
if (pDevice->eOPMode == OP_MODE_ADHOC && pDevice->pMgmt->wCurrATIMWindow > 0) {
}
}
if (pDevice->dwIsr & ISR_BNTX) {
if (pDevice->eOPMode == OP_MODE_ADHOC) {
pDevice->bIsBeaconBufReadySet = false;
pDevice->cbBeaconBufReadySetCnt = 0;
}
if (pDevice->eOPMode == OP_MODE_AP) {
if (pMgmt->byDTIMCount > 0) {
pMgmt->byDTIMCount--;
pMgmt->sNodeDBTable[0].bRxPSPoll = false;
} else {
if (pMgmt->byDTIMCount == 0) {
pMgmt->byDTIMCount = pMgmt->byDTIMPeriod - 1;
pMgmt->sNodeDBTable[0].bRxPSPoll = true;
bScheduleCommand((void *)pDevice, WLAN_CMD_RX_PSPOLL, NULL);
}
}
}
pDevice->bBeaconSent = true;
if (pDevice->bChannelSwitch == true) {
pDevice->byChannelSwitchCount--;
if (pDevice->byChannelSwitchCount == 0) {
pDevice->bChannelSwitch = false;
set_channel(pDevice, pDevice->byNewChannel);
VNTWIFIbChannelSwitch(pDevice->pMgmt, pDevice->byNewChannel);
MACvSelectPage1(pDevice->PortOffset);
MACvRegBitsOn(pDevice->PortOffset, MAC_REG_MSRCTL+1, MSRCTL1_TXPAUSE);
MACvSelectPage0(pDevice->PortOffset);
CARDbStartTxPacket(pDevice, PKT_TYPE_802_11_ALL);
}
}
}
if (pDevice->dwIsr & ISR_RXDMA0) {
max_count += device_rx_srv(pDevice, TYPE_RXDMA0);
}
if (pDevice->dwIsr & ISR_RXDMA1) {
max_count += device_rx_srv(pDevice, TYPE_RXDMA1);
}
if (pDevice->dwIsr & ISR_TXDMA0) {
max_count += device_tx_srv(pDevice, TYPE_TXDMA0);
}
if (pDevice->dwIsr & ISR_AC0DMA) {
max_count += device_tx_srv(pDevice, TYPE_AC0DMA);
}
if (pDevice->dwIsr & ISR_SOFTTIMER) {
}
if (pDevice->dwIsr & ISR_SOFTTIMER1) {
if (pDevice->eOPMode == OP_MODE_AP) {
if (pDevice->bShortSlotTime)
pMgmt->wCurrCapInfo |= WLAN_SET_CAP_INFO_SHORTSLOTTIME(1);
else
pMgmt->wCurrCapInfo &= ~(WLAN_SET_CAP_INFO_SHORTSLOTTIME(1));
}
bMgrPrepareBeaconToSend(pDevice, pMgmt);
pDevice->byCntMeasure = 0;
}
MACvReadISR(pDevice->PortOffset, &pDevice->dwIsr);
MACvReceive0(pDevice->PortOffset);
MACvReceive1(pDevice->PortOffset);
if (max_count > pDevice->sOpts.int_works)
break;
}
if (byOrgPageSel == 1) {
MACvSelectPage1(pDevice->PortOffset);
}
spin_unlock_irq(&pDevice->lock);
MACvIntEnable(pDevice->PortOffset, IMR_MASK_VALUE);
return IRQ_RETVAL(handled);
}
static inline u32 ether_crc(int length, unsigned char *data)
{
int crc = -1;
while (--length >= 0) {
unsigned char current_octet = *data++;
int bit;
for (bit = 0; bit < 8; bit++, current_octet >>= 1) {
crc = (crc << 1) ^
((crc < 0) ^ (current_octet & 1) ? ethernet_polynomial : 0);
}
}
return crc;
}
static int Config_FileGetParameter(unsigned char *string,
unsigned char *dest, unsigned char *source)
{
unsigned char buf1[100];
int source_len = strlen(source);
memset(buf1, 0, 100);
strcat(buf1, string);
strcat(buf1, "=");
source += strlen(buf1);
memcpy(dest, source, source_len - strlen(buf1));
return true;
}
int Config_FileOperation(PSDevice pDevice,bool fwrite,unsigned char *Parameter)
{
unsigned char *buffer = kmalloc(1024, GFP_KERNEL);
unsigned char tmpbuffer[20];
struct file *file;
int result=0;
if (!buffer) {
printk("allocate mem for file fail?\n");
return -1;
}
file = filp_open(CONFIG_PATH, O_RDONLY, 0);
if (IS_ERR(file)) {
kfree(buffer);
printk("Config_FileOperation:open file fail?\n");
return -1;
}
if (kernel_read(file, 0, buffer, 1024) < 0) {
printk("read file error?\n");
result = -1;
goto error1;
}
if (Config_FileGetParameter("ZONETYPE",tmpbuffer,buffer)!=true) {
printk("get parameter error?\n");
result = -1;
goto error1;
}
if (memcmp(tmpbuffer,"USA",3)==0) {
result = ZoneType_USA;
} else if(memcmp(tmpbuffer,"JAPAN",5)==0) {
result = ZoneType_Japan;
} else if(memcmp(tmpbuffer,"EUROPE",5)==0) {
result = ZoneType_Europe;
} else {
result = -1;
printk("Unknown Zonetype[%s]?\n",tmpbuffer);
}
error1:
kfree(buffer);
fput(file);
return result;
}
static void device_set_multi(struct net_device *dev) {
PSDevice pDevice = (PSDevice)netdev_priv(dev);
PSMgmtObject pMgmt = pDevice->pMgmt;
u32 mc_filter[2];
struct netdev_hw_addr *ha;
VNSvInPortB(pDevice->PortOffset + MAC_REG_RCR, &(pDevice->byRxMode));
if (dev->flags & IFF_PROMISC) {
DBG_PRT(MSG_LEVEL_ERR, KERN_NOTICE "%s: Promiscuous mode enabled.\n", dev->name);
pDevice->byRxMode |= (RCR_MULTICAST|RCR_BROADCAST|RCR_UNICAST);
} else if ((netdev_mc_count(dev) > pDevice->multicast_limit)
|| (dev->flags & IFF_ALLMULTI)) {
MACvSelectPage1(pDevice->PortOffset);
VNSvOutPortD(pDevice->PortOffset + MAC_REG_MAR0, 0xffffffff);
VNSvOutPortD(pDevice->PortOffset + MAC_REG_MAR0 + 4, 0xffffffff);
MACvSelectPage0(pDevice->PortOffset);
pDevice->byRxMode |= (RCR_MULTICAST|RCR_BROADCAST);
} else {
memset(mc_filter, 0, sizeof(mc_filter));
netdev_for_each_mc_addr(ha, dev) {
int bit_nr = ether_crc(ETH_ALEN, ha->addr) >> 26;
mc_filter[bit_nr >> 5] |= cpu_to_le32(1 << (bit_nr & 31));
}
MACvSelectPage1(pDevice->PortOffset);
VNSvOutPortD(pDevice->PortOffset + MAC_REG_MAR0, mc_filter[0]);
VNSvOutPortD(pDevice->PortOffset + MAC_REG_MAR0 + 4, mc_filter[1]);
MACvSelectPage0(pDevice->PortOffset);
pDevice->byRxMode &= ~(RCR_UNICAST);
pDevice->byRxMode |= (RCR_MULTICAST|RCR_BROADCAST);
}
if (pMgmt->eConfigMode == WMAC_CONFIG_AP) {
pDevice->byRxMode |= (RCR_MULTICAST|RCR_BROADCAST);
pDevice->byRxMode &= ~(RCR_UNICAST);
}
VNSvOutPortB(pDevice->PortOffset + MAC_REG_RCR, pDevice->byRxMode);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "pDevice->byRxMode = %x\n", pDevice->byRxMode);
}
static struct net_device_stats *device_get_stats(struct net_device *dev) {
PSDevice pDevice = (PSDevice)netdev_priv(dev);
return &pDevice->stats;
}
static int device_ioctl(struct net_device *dev, struct ifreq *rq, int cmd) {
PSDevice pDevice = (PSDevice)netdev_priv(dev);
struct iwreq *wrq = (struct iwreq *)rq;
int rc = 0;
PSMgmtObject pMgmt = pDevice->pMgmt;
PSCmdRequest pReq;
if (pMgmt == NULL) {
rc = -EFAULT;
return rc;
}
switch (cmd) {
case SIOCGIWNAME:
rc = iwctl_giwname(dev, NULL, (char *)&(wrq->u.name), NULL);
break;
case SIOCGIWNWID:
rc = -EOPNOTSUPP;
break;
case SIOCSIWFREQ:
rc = iwctl_siwfreq(dev, NULL, &(wrq->u.freq), NULL);
break;
case SIOCGIWFREQ:
rc = iwctl_giwfreq(dev, NULL, &(wrq->u.freq), NULL);
break;
case SIOCSIWESSID:
{
char essid[IW_ESSID_MAX_SIZE+1];
if (wrq->u.essid.length > IW_ESSID_MAX_SIZE) {
rc = -E2BIG;
break;
}
if (copy_from_user(essid, wrq->u.essid.pointer,
wrq->u.essid.length)) {
rc = -EFAULT;
break;
}
rc = iwctl_siwessid(dev, NULL,
&(wrq->u.essid), essid);
}
break;
case SIOCGIWESSID:
{
char essid[IW_ESSID_MAX_SIZE+1];
if (wrq->u.essid.pointer)
rc = iwctl_giwessid(dev, NULL,
&(wrq->u.essid), essid);
if (copy_to_user(wrq->u.essid.pointer,
essid,
wrq->u.essid.length))
rc = -EFAULT;
}
break;
case SIOCSIWAP:
rc = iwctl_siwap(dev, NULL, &(wrq->u.ap_addr), NULL);
break;
case SIOCGIWAP:
rc = iwctl_giwap(dev, NULL, &(wrq->u.ap_addr), NULL);
break;
case SIOCSIWNICKN:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWNICKN \n");
rc = -EOPNOTSUPP;
break;
case SIOCGIWNICKN:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCGIWNICKN \n");
rc = -EOPNOTSUPP;
break;
case SIOCSIWRATE:
rc = iwctl_siwrate(dev, NULL, &(wrq->u.bitrate), NULL);
break;
case SIOCGIWRATE:
rc = iwctl_giwrate(dev, NULL, &(wrq->u.bitrate), NULL);
break;
case SIOCSIWRTS:
rc = iwctl_siwrts(dev, NULL, &(wrq->u.rts), NULL);
break;
case SIOCGIWRTS:
rc = iwctl_giwrts(dev, NULL, &(wrq->u.rts), NULL);
break;
case SIOCSIWFRAG:
rc = iwctl_siwfrag(dev, NULL, &(wrq->u.frag), NULL);
break;
case SIOCGIWFRAG:
rc = iwctl_giwfrag(dev, NULL, &(wrq->u.frag), NULL);
break;
case SIOCSIWMODE:
rc = iwctl_siwmode(dev, NULL, &(wrq->u.mode), NULL);
break;
case SIOCGIWMODE:
rc = iwctl_giwmode(dev, NULL, &(wrq->u.mode), NULL);
break;
case SIOCSIWENCODE: {
char abyKey[WLAN_WEP232_KEYLEN];
if (wrq->u.encoding.pointer) {
if (wrq->u.encoding.length > WLAN_WEP232_KEYLEN) {
rc = -E2BIG;
break;
}
memset(abyKey, 0, WLAN_WEP232_KEYLEN);
if (copy_from_user(abyKey,
wrq->u.encoding.pointer,
wrq->u.encoding.length)) {
rc = -EFAULT;
break;
}
} else if (wrq->u.encoding.length != 0) {
rc = -EINVAL;
break;
}
rc = iwctl_siwencode(dev, NULL, &(wrq->u.encoding), abyKey);
}
break;
case SIOCGIWENCODE:
if (!capable(CAP_NET_ADMIN)) {
rc = -EPERM;
break;
}
{
char abyKey[WLAN_WEP232_KEYLEN];
rc = iwctl_giwencode(dev, NULL, &(wrq->u.encoding), abyKey);
if (rc != 0) break;
if (wrq->u.encoding.pointer) {
if (copy_to_user(wrq->u.encoding.pointer,
abyKey,
wrq->u.encoding.length))
rc = -EFAULT;
}
}
break;
case SIOCGIWTXPOW:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCGIWTXPOW \n");
rc = -EOPNOTSUPP;
break;
case SIOCSIWTXPOW:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWTXPOW \n");
rc = -EOPNOTSUPP;
break;
case SIOCSIWRETRY:
rc = iwctl_siwretry(dev, NULL, &(wrq->u.retry), NULL);
break;
case SIOCGIWRETRY:
rc = iwctl_giwretry(dev, NULL, &(wrq->u.retry), NULL);
break;
case SIOCGIWRANGE:
{
struct iw_range range;
rc = iwctl_giwrange(dev, NULL, &(wrq->u.data), (char *)&range);
if (copy_to_user(wrq->u.data.pointer, &range, sizeof(struct iw_range)))
rc = -EFAULT;
}
break;
case SIOCGIWPOWER:
rc = iwctl_giwpower(dev, NULL, &(wrq->u.power), NULL);
break;
case SIOCSIWPOWER:
rc = iwctl_siwpower(dev, NULL, &(wrq->u.power), NULL);
break;
case SIOCGIWSENS:
rc = iwctl_giwsens(dev, NULL, &(wrq->u.sens), NULL);
break;
case SIOCSIWSENS:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWSENS \n");
rc = -EOPNOTSUPP;
break;
case SIOCGIWAPLIST: {
char buffer[IW_MAX_AP * (sizeof(struct sockaddr) + sizeof(struct iw_quality))];
if (wrq->u.data.pointer) {
rc = iwctl_giwaplist(dev, NULL, &(wrq->u.data), buffer);
if (rc == 0) {
if (copy_to_user(wrq->u.data.pointer,
buffer,
(wrq->u.data.length * (sizeof(struct sockaddr) + sizeof(struct iw_quality)))
))
rc = -EFAULT;
}
}
}
break;
#ifdef WIRELESS_SPY
case SIOCSIWSPY:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWSPY \n");
rc = -EOPNOTSUPP;
break;
case SIOCGIWSPY:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCGIWSPY \n");
rc = -EOPNOTSUPP;
break;
#endif
case SIOCGIWPRIV:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCGIWPRIV \n");
rc = -EOPNOTSUPP;
break;
#ifdef WPA_SUPPLICANT_DRIVER_WEXT_SUPPORT
case SIOCSIWAUTH:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWAUTH \n");
rc = iwctl_siwauth(dev, NULL, &(wrq->u.param), NULL);
break;
case SIOCGIWAUTH:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCGIWAUTH \n");
rc = iwctl_giwauth(dev, NULL, &(wrq->u.param), NULL);
break;
case SIOCSIWGENIE:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWGENIE \n");
rc = iwctl_siwgenie(dev, NULL, &(wrq->u.data), wrq->u.data.pointer);
break;
case SIOCGIWGENIE:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCGIWGENIE \n");
rc = iwctl_giwgenie(dev, NULL, &(wrq->u.data), wrq->u.data.pointer);
break;
case SIOCSIWENCODEEXT: {
char extra[sizeof(struct iw_encode_ext)+MAX_KEY_LEN+1];
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWENCODEEXT \n");
if (wrq->u.encoding.pointer) {
memset(extra, 0, sizeof(struct iw_encode_ext)+MAX_KEY_LEN + 1);
if (wrq->u.encoding.length > (sizeof(struct iw_encode_ext) + MAX_KEY_LEN)) {
rc = -E2BIG;
break;
}
if (copy_from_user(extra, wrq->u.encoding.pointer, wrq->u.encoding.length)) {
rc = -EFAULT;
break;
}
} else if (wrq->u.encoding.length != 0) {
rc = -EINVAL;
break;
}
rc = iwctl_siwencodeext(dev, NULL, &(wrq->u.encoding), extra);
}
break;
case SIOCGIWENCODEEXT:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCGIWENCODEEXT \n");
rc = iwctl_giwencodeext(dev, NULL, &(wrq->u.encoding), NULL);
break;
case SIOCSIWMLME:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWMLME \n");
rc = iwctl_siwmlme(dev, NULL, &(wrq->u.data), wrq->u.data.pointer);
break;
#endif
case IOCTL_CMD_TEST:
if (!(pDevice->flags & DEVICE_FLAGS_OPENED)) {
rc = -EFAULT;
break;
} else {
rc = 0;
}
pReq = (PSCmdRequest)rq;
pReq->wResult = MAGIC_CODE;
break;
case IOCTL_CMD_SET:
#ifdef SndEvt_ToAPI
if ((((PSCmdRequest)rq)->wCmdCode != WLAN_CMD_SET_EVT) &&
!(pDevice->flags & DEVICE_FLAGS_OPENED))
#else
if (!(pDevice->flags & DEVICE_FLAGS_OPENED) &&
(((PSCmdRequest)rq)->wCmdCode != WLAN_CMD_SET_WPA))
#endif
{
rc = -EFAULT;
break;
} else {
rc = 0;
}
if (test_and_set_bit(0, (void *)&(pMgmt->uCmdBusy))) {
return -EBUSY;
}
rc = private_ioctl(pDevice, rq);
clear_bit(0, (void *)&(pMgmt->uCmdBusy));
break;
case IOCTL_CMD_HOSTAPD:
rc = vt6655_hostap_ioctl(pDevice, &wrq->u.data);
break;
case IOCTL_CMD_WPA:
rc = wpa_ioctl(pDevice, &wrq->u.data);
break;
case SIOCETHTOOL:
return ethtool_ioctl(dev, (void *)rq->ifr_data);
default:
rc = -EOPNOTSUPP;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Ioctl command not support..%x\n", cmd);
}
if (pDevice->bCommit) {
if (pMgmt->eConfigMode == WMAC_CONFIG_AP) {
netif_stop_queue(pDevice->dev);
spin_lock_irq(&pDevice->lock);
bScheduleCommand((void *)pDevice, WLAN_CMD_RUN_AP, NULL);
spin_unlock_irq(&pDevice->lock);
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Commit the settings\n");
spin_lock_irq(&pDevice->lock);
pDevice->bLinkPass = false;
memset(pMgmt->abyCurrBSSID, 0, 6);
pMgmt->eCurrState = WMAC_STATE_IDLE;
netif_stop_queue(pDevice->dev);
#ifdef WPA_SUPPLICANT_DRIVER_WEXT_SUPPORT
pMgmt->eScanType = WMAC_SCAN_ACTIVE;
if (pDevice->bWPASuppWextEnabled != true)
#endif
bScheduleCommand((void *)pDevice, WLAN_CMD_BSSID_SCAN, pMgmt->abyDesireSSID);
bScheduleCommand((void *)pDevice, WLAN_CMD_SSID, NULL);
spin_unlock_irq(&pDevice->lock);
}
pDevice->bCommit = false;
}
return rc;
}
static int ethtool_ioctl(struct net_device *dev, void *useraddr)
{
u32 ethcmd;
if (copy_from_user(&ethcmd, useraddr, sizeof(ethcmd)))
return -EFAULT;
switch (ethcmd) {
case ETHTOOL_GDRVINFO: {
struct ethtool_drvinfo info = {ETHTOOL_GDRVINFO};
strncpy(info.driver, DEVICE_NAME, sizeof(info.driver)-1);
strncpy(info.version, DEVICE_VERSION, sizeof(info.version)-1);
if (copy_to_user(useraddr, &info, sizeof(info)))
return -EFAULT;
return 0;
}
}
return -EOPNOTSUPP;
}
static int __init vt6655_init_module(void)
{
int ret;
ret = pci_register_driver(&device_driver);
#ifdef CONFIG_PM
if (ret >= 0)
register_reboot_notifier(&device_notifier);
#endif
return ret;
}
static void __exit vt6655_cleanup_module(void)
{
#ifdef CONFIG_PM
unregister_reboot_notifier(&device_notifier);
#endif
pci_unregister_driver(&device_driver);
}
static int
device_notify_reboot(struct notifier_block *nb, unsigned long event, void *p)
{
struct pci_dev *pdev = NULL;
switch (event) {
case SYS_DOWN:
case SYS_HALT:
case SYS_POWER_OFF:
for_each_pci_dev(pdev) {
if (pci_dev_driver(pdev) == &device_driver) {
if (pci_get_drvdata(pdev))
viawget_suspend(pdev, PMSG_HIBERNATE);
}
}
}
return NOTIFY_DONE;
}
static int
viawget_suspend(struct pci_dev *pcid, pm_message_t state)
{
int power_status;
PSDevice pDevice = pci_get_drvdata(pcid);
PSMgmtObject pMgmt = pDevice->pMgmt;
netif_stop_queue(pDevice->dev);
spin_lock_irq(&pDevice->lock);
pci_save_state(pcid);
del_timer(&pDevice->sTimerCommand);
del_timer(&pMgmt->sTimerSecondCallback);
pDevice->cbFreeCmdQueue = CMD_Q_SIZE;
pDevice->uCmdDequeueIdx = 0;
pDevice->uCmdEnqueueIdx = 0;
pDevice->bCmdRunning = false;
MACbShutdown(pDevice->PortOffset);
MACvSaveContext(pDevice->PortOffset, pDevice->abyMacContext);
pDevice->bLinkPass = false;
memset(pMgmt->abyCurrBSSID, 0, 6);
pMgmt->eCurrState = WMAC_STATE_IDLE;
pci_disable_device(pcid);
power_status = pci_set_power_state(pcid, pci_choose_state(pcid, state));
spin_unlock_irq(&pDevice->lock);
return 0;
}
static int
viawget_resume(struct pci_dev *pcid)
{
PSDevice pDevice = pci_get_drvdata(pcid);
PSMgmtObject pMgmt = pDevice->pMgmt;
int power_status;
power_status = pci_set_power_state(pcid, 0);
power_status = pci_enable_wake(pcid, 0, 0);
pci_restore_state(pcid);
if (netif_running(pDevice->dev)) {
spin_lock_irq(&pDevice->lock);
MACvRestoreContext(pDevice->PortOffset, pDevice->abyMacContext);
device_init_registers(pDevice, DEVICE_INIT_DXPL);
if (pMgmt->sNodeDBTable[0].bActive == true) {
pMgmt->sNodeDBTable[0].bActive = false;
pDevice->bLinkPass = false;
if (pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) {
pMgmt->eCurrState = WMAC_STATE_STARTED;
} else {
pMgmt->eCurrMode = WMAC_MODE_STANDBY;
pMgmt->eCurrState = WMAC_STATE_IDLE;
}
}
init_timer(&pMgmt->sTimerSecondCallback);
init_timer(&pDevice->sTimerCommand);
MACvIntEnable(pDevice->PortOffset, IMR_MASK_VALUE);
BSSvClearBSSList((void *)pDevice, pDevice->bLinkPass);
bScheduleCommand((void *)pDevice, WLAN_CMD_BSSID_SCAN, NULL);
bScheduleCommand((void *)pDevice, WLAN_CMD_SSID, NULL);
spin_unlock_irq(&pDevice->lock);
}
return 0;
}
