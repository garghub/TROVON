static int FlashPoint_ProbeHostAdapter(struct sccb_mgr_info *pCardInfo)
{
static unsigned char first_time = 1;
unsigned char i, j, id, ScamFlg;
unsigned short temp, temp2, temp3, temp4, temp5, temp6;
u32 ioport;
struct nvram_info *pCurrNvRam;
ioport = pCardInfo->si_baseaddr;
if (RD_HARPOON(ioport + hp_vendor_id_0) != ORION_VEND_0)
return (int)FAILURE;
if ((RD_HARPOON(ioport + hp_vendor_id_1) != ORION_VEND_1))
return (int)FAILURE;
if ((RD_HARPOON(ioport + hp_device_id_0) != ORION_DEV_0))
return (int)FAILURE;
if ((RD_HARPOON(ioport + hp_device_id_1) != ORION_DEV_1))
return (int)FAILURE;
if (RD_HARPOON(ioport + hp_rev_num) != 0x0f) {
if (RD_HARPOON(ioport + hp_sub_device_id_0) & 0x0f)
return (int)FAILURE;
}
if (first_time) {
FPT_SccbMgrTableInitAll();
first_time = 0;
FPT_mbCards = 0;
}
if (FPT_RdStack(ioport, 0) != 0x00) {
if (FPT_ChkIfChipInitialized(ioport) == 0) {
pCurrNvRam = NULL;
WR_HARPOON(ioport + hp_semaphore, 0x00);
FPT_XbowInit(ioport, 0);
FPT_DiagEEPROM(ioport);
} else {
if (FPT_mbCards < MAX_MB_CARDS) {
pCurrNvRam = &FPT_nvRamInfo[FPT_mbCards];
FPT_mbCards++;
pCurrNvRam->niBaseAddr = ioport;
FPT_RNVRamData(pCurrNvRam);
} else
return (int)FAILURE;
}
} else
pCurrNvRam = NULL;
WR_HARPOON(ioport + hp_clkctrl_0, CLKCTRL_DEFAULT);
WR_HARPOON(ioport + hp_sys_ctrl, 0x00);
if (pCurrNvRam)
pCardInfo->si_id = pCurrNvRam->niAdapId;
else
pCardInfo->si_id =
(unsigned
char)(FPT_utilEERead(ioport,
(ADAPTER_SCSI_ID /
2)) & (unsigned char)0x0FF);
pCardInfo->si_lun = 0x00;
pCardInfo->si_fw_revision = ORION_FW_REV;
temp2 = 0x0000;
temp3 = 0x0000;
temp4 = 0x0000;
temp5 = 0x0000;
temp6 = 0x0000;
for (id = 0; id < (16 / 2); id++) {
if (pCurrNvRam) {
temp = (unsigned short)pCurrNvRam->niSyncTbl[id];
temp = ((temp & 0x03) + ((temp << 4) & 0xc0)) +
(((temp << 4) & 0x0300) + ((temp << 8) & 0xc000));
} else
temp =
FPT_utilEERead(ioport,
(unsigned short)((SYNC_RATE_TBL / 2)
+ id));
for (i = 0; i < 2; temp >>= 8, i++) {
temp2 >>= 1;
temp3 >>= 1;
temp4 >>= 1;
temp5 >>= 1;
temp6 >>= 1;
switch (temp & 0x3) {
case AUTO_RATE_20:
temp6 |= 0x8000;
case AUTO_RATE_10:
temp5 |= 0x8000;
case AUTO_RATE_05:
temp2 |= 0x8000;
case AUTO_RATE_00:
break;
}
if (temp & DISC_ENABLE_BIT)
temp3 |= 0x8000;
if (temp & WIDE_NEGO_BIT)
temp4 |= 0x8000;
}
}
pCardInfo->si_per_targ_init_sync = temp2;
pCardInfo->si_per_targ_no_disc = temp3;
pCardInfo->si_per_targ_wide_nego = temp4;
pCardInfo->si_per_targ_fast_nego = temp5;
pCardInfo->si_per_targ_ultra_nego = temp6;
if (pCurrNvRam)
i = pCurrNvRam->niSysConf;
else
i = (unsigned
char)(FPT_utilEERead(ioport, (SYSTEM_CONFIG / 2)));
if (pCurrNvRam)
ScamFlg = pCurrNvRam->niScamConf;
else
ScamFlg =
(unsigned char)FPT_utilEERead(ioport, SCAM_CONFIG / 2);
pCardInfo->si_flags = 0x0000;
if (i & 0x01)
pCardInfo->si_flags |= SCSI_PARITY_ENA;
if (!(i & 0x02))
pCardInfo->si_flags |= SOFT_RESET;
if (i & 0x10)
pCardInfo->si_flags |= EXTENDED_TRANSLATION;
if (ScamFlg & SCAM_ENABLED)
pCardInfo->si_flags |= FLAG_SCAM_ENABLED;
if (ScamFlg & SCAM_LEVEL2)
pCardInfo->si_flags |= FLAG_SCAM_LEVEL2;
j = (RD_HARPOON(ioport + hp_bm_ctrl) & ~SCSI_TERM_ENA_L);
if (i & 0x04) {
j |= SCSI_TERM_ENA_L;
}
WR_HARPOON(ioport + hp_bm_ctrl, j);
j = (RD_HARPOON(ioport + hp_ee_ctrl) & ~SCSI_TERM_ENA_H);
if (i & 0x08) {
j |= SCSI_TERM_ENA_H;
}
WR_HARPOON(ioport + hp_ee_ctrl, j);
if (!(RD_HARPOON(ioport + hp_page_ctrl) & NARROW_SCSI_CARD))
pCardInfo->si_flags |= SUPPORT_16TAR_32LUN;
pCardInfo->si_card_family = HARPOON_FAMILY;
pCardInfo->si_bustype = BUSTYPE_PCI;
if (pCurrNvRam) {
pCardInfo->si_card_model[0] = '9';
switch (pCurrNvRam->niModel & 0x0f) {
case MODEL_LT:
pCardInfo->si_card_model[1] = '3';
pCardInfo->si_card_model[2] = '0';
break;
case MODEL_LW:
pCardInfo->si_card_model[1] = '5';
pCardInfo->si_card_model[2] = '0';
break;
case MODEL_DL:
pCardInfo->si_card_model[1] = '3';
pCardInfo->si_card_model[2] = '2';
break;
case MODEL_DW:
pCardInfo->si_card_model[1] = '5';
pCardInfo->si_card_model[2] = '2';
break;
}
} else {
temp = FPT_utilEERead(ioport, (MODEL_NUMB_0 / 2));
pCardInfo->si_card_model[0] = (unsigned char)(temp >> 8);
temp = FPT_utilEERead(ioport, (MODEL_NUMB_2 / 2));
pCardInfo->si_card_model[1] = (unsigned char)(temp & 0x00FF);
pCardInfo->si_card_model[2] = (unsigned char)(temp >> 8);
}
if (pCardInfo->si_card_model[1] == '3') {
if (RD_HARPOON(ioport + hp_ee_ctrl) & BIT(7))
pCardInfo->si_flags |= LOW_BYTE_TERM;
} else if (pCardInfo->si_card_model[2] == '0') {
temp = RD_HARPOON(ioport + hp_xfer_pad);
WR_HARPOON(ioport + hp_xfer_pad, (temp & ~BIT(4)));
if (RD_HARPOON(ioport + hp_ee_ctrl) & BIT(7))
pCardInfo->si_flags |= LOW_BYTE_TERM;
WR_HARPOON(ioport + hp_xfer_pad, (temp | BIT(4)));
if (RD_HARPOON(ioport + hp_ee_ctrl) & BIT(7))
pCardInfo->si_flags |= HIGH_BYTE_TERM;
WR_HARPOON(ioport + hp_xfer_pad, temp);
} else {
temp = RD_HARPOON(ioport + hp_ee_ctrl);
temp2 = RD_HARPOON(ioport + hp_xfer_pad);
WR_HARPOON(ioport + hp_ee_ctrl, (temp | SEE_CS));
WR_HARPOON(ioport + hp_xfer_pad, (temp2 | BIT(4)));
temp3 = 0;
for (i = 0; i < 8; i++) {
temp3 <<= 1;
if (!(RD_HARPOON(ioport + hp_ee_ctrl) & BIT(7)))
temp3 |= 1;
WR_HARPOON(ioport + hp_xfer_pad, (temp2 & ~BIT(4)));
WR_HARPOON(ioport + hp_xfer_pad, (temp2 | BIT(4)));
}
WR_HARPOON(ioport + hp_ee_ctrl, temp);
WR_HARPOON(ioport + hp_xfer_pad, temp2);
if (!(temp3 & BIT(7)))
pCardInfo->si_flags |= LOW_BYTE_TERM;
if (!(temp3 & BIT(6)))
pCardInfo->si_flags |= HIGH_BYTE_TERM;
}
ARAM_ACCESS(ioport);
for (i = 0; i < 4; i++) {
pCardInfo->si_XlatInfo[i] =
RD_HARPOON(ioport + hp_aramBase + BIOS_DATA_OFFSET + i);
}
pCardInfo->si_relative_cardnum =
(unsigned
char)(RD_HARPOON(ioport + hp_aramBase + BIOS_RELATIVE_CARD) - 1);
SGRAM_ACCESS(ioport);
FPT_s_PhaseTbl[0] = FPT_phaseDataOut;
FPT_s_PhaseTbl[1] = FPT_phaseDataIn;
FPT_s_PhaseTbl[2] = FPT_phaseIllegal;
FPT_s_PhaseTbl[3] = FPT_phaseIllegal;
FPT_s_PhaseTbl[4] = FPT_phaseCommand;
FPT_s_PhaseTbl[5] = FPT_phaseStatus;
FPT_s_PhaseTbl[6] = FPT_phaseMsgOut;
FPT_s_PhaseTbl[7] = FPT_phaseMsgIn;
pCardInfo->si_present = 0x01;
return 0;
}
static void *FlashPoint_HardwareResetHostAdapter(struct sccb_mgr_info
*pCardInfo)
{
struct sccb_card *CurrCard = NULL;
struct nvram_info *pCurrNvRam;
unsigned char i, j, thisCard, ScamFlg;
unsigned short temp, sync_bit_map, id;
u32 ioport;
ioport = pCardInfo->si_baseaddr;
for (thisCard = 0; thisCard <= MAX_CARDS; thisCard++) {
if (thisCard == MAX_CARDS)
return (void *)FAILURE;
if (FPT_BL_Card[thisCard].ioPort == ioport) {
CurrCard = &FPT_BL_Card[thisCard];
FPT_SccbMgrTableInitCard(CurrCard, thisCard);
break;
}
else if (FPT_BL_Card[thisCard].ioPort == 0x00) {
FPT_BL_Card[thisCard].ioPort = ioport;
CurrCard = &FPT_BL_Card[thisCard];
if (FPT_mbCards)
for (i = 0; i < FPT_mbCards; i++) {
if (CurrCard->ioPort ==
FPT_nvRamInfo[i].niBaseAddr)
CurrCard->pNvRamInfo =
&FPT_nvRamInfo[i];
}
FPT_SccbMgrTableInitCard(CurrCard, thisCard);
CurrCard->cardIndex = thisCard;
CurrCard->cardInfo = pCardInfo;
break;
}
}
pCurrNvRam = CurrCard->pNvRamInfo;
if (pCurrNvRam) {
ScamFlg = pCurrNvRam->niScamConf;
} else {
ScamFlg =
(unsigned char)FPT_utilEERead(ioport, SCAM_CONFIG / 2);
}
FPT_BusMasterInit(ioport);
FPT_XbowInit(ioport, ScamFlg);
FPT_autoLoadDefaultMap(ioport);
for (i = 0, id = 0x01; i != pCardInfo->si_id; i++, id <<= 1) {
}
WR_HARPOON(ioport + hp_selfid_0, id);
WR_HARPOON(ioport + hp_selfid_1, 0x00);
WR_HARPOON(ioport + hp_arb_id, pCardInfo->si_id);
CurrCard->ourId = pCardInfo->si_id;
i = (unsigned char)pCardInfo->si_flags;
if (i & SCSI_PARITY_ENA)
WR_HARPOON(ioport + hp_portctrl_1, (HOST_MODE8 | CHK_SCSI_P));
j = (RD_HARPOON(ioport + hp_bm_ctrl) & ~SCSI_TERM_ENA_L);
if (i & LOW_BYTE_TERM)
j |= SCSI_TERM_ENA_L;
WR_HARPOON(ioport + hp_bm_ctrl, j);
j = (RD_HARPOON(ioport + hp_ee_ctrl) & ~SCSI_TERM_ENA_H);
if (i & HIGH_BYTE_TERM)
j |= SCSI_TERM_ENA_H;
WR_HARPOON(ioport + hp_ee_ctrl, j);
if (!(pCardInfo->si_flags & SOFT_RESET)) {
FPT_sresb(ioport, thisCard);
FPT_scini(thisCard, pCardInfo->si_id, 0);
}
if (pCardInfo->si_flags & POST_ALL_UNDERRRUNS)
CurrCard->globalFlags |= F_NO_FILTER;
if (pCurrNvRam) {
if (pCurrNvRam->niSysConf & 0x10)
CurrCard->globalFlags |= F_GREEN_PC;
} else {
if (FPT_utilEERead(ioport, (SYSTEM_CONFIG / 2)) & GREEN_PC_ENA)
CurrCard->globalFlags |= F_GREEN_PC;
}
if (pCurrNvRam) {
if (pCurrNvRam->niScsiConf & 0x04)
CurrCard->globalFlags |= F_DO_RENEGO;
} else {
if (FPT_utilEERead(ioport, (SCSI_CONFIG / 2)) & RENEGO_ENA)
CurrCard->globalFlags |= F_DO_RENEGO;
}
if (pCurrNvRam) {
if (pCurrNvRam->niScsiConf & 0x08)
CurrCard->globalFlags |= F_CONLUN_IO;
} else {
if (FPT_utilEERead(ioport, (SCSI_CONFIG / 2)) & CONNIO_ENA)
CurrCard->globalFlags |= F_CONLUN_IO;
}
temp = pCardInfo->si_per_targ_no_disc;
for (i = 0, id = 1; i < MAX_SCSI_TAR; i++, id <<= 1) {
if (temp & id)
FPT_sccbMgrTbl[thisCard][i].TarStatus |= TAR_ALLOW_DISC;
}
sync_bit_map = 0x0001;
for (id = 0; id < (MAX_SCSI_TAR / 2); id++) {
if (pCurrNvRam) {
temp = (unsigned short)pCurrNvRam->niSyncTbl[id];
temp = ((temp & 0x03) + ((temp << 4) & 0xc0)) +
(((temp << 4) & 0x0300) + ((temp << 8) & 0xc000));
} else
temp =
FPT_utilEERead(ioport,
(unsigned short)((SYNC_RATE_TBL / 2)
+ id));
for (i = 0; i < 2; temp >>= 8, i++) {
if (pCardInfo->si_per_targ_init_sync & sync_bit_map) {
FPT_sccbMgrTbl[thisCard][id * 2 +
i].TarEEValue =
(unsigned char)temp;
}
else {
FPT_sccbMgrTbl[thisCard][id * 2 +
i].TarStatus |=
SYNC_SUPPORTED;
FPT_sccbMgrTbl[thisCard][id * 2 +
i].TarEEValue =
(unsigned char)(temp & ~EE_SYNC_MASK);
}
if (pCardInfo->si_per_targ_wide_nego & sync_bit_map) {
FPT_sccbMgrTbl[thisCard][id * 2 +
i].TarEEValue |=
EE_WIDE_SCSI;
}
else {
FPT_sccbMgrTbl[thisCard][id * 2 +
i].TarStatus |=
WIDE_NEGOCIATED;
}
sync_bit_map <<= 1;
}
}
WR_HARPOON((ioport + hp_semaphore),
(unsigned char)(RD_HARPOON((ioport + hp_semaphore)) |
SCCB_MGR_PRESENT));
return (void *)CurrCard;
}
static void FlashPoint_ReleaseHostAdapter(void *pCurrCard)
{
unsigned char i;
u32 portBase;
u32 regOffset;
u32 scamData;
u32 *pScamTbl;
struct nvram_info *pCurrNvRam;
pCurrNvRam = ((struct sccb_card *)pCurrCard)->pNvRamInfo;
if (pCurrNvRam) {
FPT_WrStack(pCurrNvRam->niBaseAddr, 0, pCurrNvRam->niModel);
FPT_WrStack(pCurrNvRam->niBaseAddr, 1, pCurrNvRam->niSysConf);
FPT_WrStack(pCurrNvRam->niBaseAddr, 2, pCurrNvRam->niScsiConf);
FPT_WrStack(pCurrNvRam->niBaseAddr, 3, pCurrNvRam->niScamConf);
FPT_WrStack(pCurrNvRam->niBaseAddr, 4, pCurrNvRam->niAdapId);
for (i = 0; i < MAX_SCSI_TAR / 2; i++)
FPT_WrStack(pCurrNvRam->niBaseAddr,
(unsigned char)(i + 5),
pCurrNvRam->niSyncTbl[i]);
portBase = pCurrNvRam->niBaseAddr;
for (i = 0; i < MAX_SCSI_TAR; i++) {
regOffset = hp_aramBase + 64 + i * 4;
pScamTbl = (u32 *)&pCurrNvRam->niScamTbl[i];
scamData = *pScamTbl;
WR_HARP32(portBase, regOffset, scamData);
}
} else {
FPT_WrStack(((struct sccb_card *)pCurrCard)->ioPort, 0, 0);
}
}
static void FPT_RNVRamData(struct nvram_info *pNvRamInfo)
{
unsigned char i;
u32 portBase;
u32 regOffset;
u32 scamData;
u32 *pScamTbl;
pNvRamInfo->niModel = FPT_RdStack(pNvRamInfo->niBaseAddr, 0);
pNvRamInfo->niSysConf = FPT_RdStack(pNvRamInfo->niBaseAddr, 1);
pNvRamInfo->niScsiConf = FPT_RdStack(pNvRamInfo->niBaseAddr, 2);
pNvRamInfo->niScamConf = FPT_RdStack(pNvRamInfo->niBaseAddr, 3);
pNvRamInfo->niAdapId = FPT_RdStack(pNvRamInfo->niBaseAddr, 4);
for (i = 0; i < MAX_SCSI_TAR / 2; i++)
pNvRamInfo->niSyncTbl[i] =
FPT_RdStack(pNvRamInfo->niBaseAddr, (unsigned char)(i + 5));
portBase = pNvRamInfo->niBaseAddr;
for (i = 0; i < MAX_SCSI_TAR; i++) {
regOffset = hp_aramBase + 64 + i * 4;
RD_HARP32(portBase, regOffset, scamData);
pScamTbl = (u32 *)&pNvRamInfo->niScamTbl[i];
*pScamTbl = scamData;
}
}
static unsigned char FPT_RdStack(u32 portBase, unsigned char index)
{
WR_HARPOON(portBase + hp_stack_addr, index);
return RD_HARPOON(portBase + hp_stack_data);
}
static void FPT_WrStack(u32 portBase, unsigned char index, unsigned char data)
{
WR_HARPOON(portBase + hp_stack_addr, index);
WR_HARPOON(portBase + hp_stack_data, data);
}
static unsigned char FPT_ChkIfChipInitialized(u32 ioPort)
{
if ((RD_HARPOON(ioPort + hp_arb_id) & 0x0f) != FPT_RdStack(ioPort, 4))
return 0;
if ((RD_HARPOON(ioPort + hp_clkctrl_0) & CLKCTRL_DEFAULT)
!= CLKCTRL_DEFAULT)
return 0;
if ((RD_HARPOON(ioPort + hp_seltimeout) == TO_250ms) ||
(RD_HARPOON(ioPort + hp_seltimeout) == TO_290ms))
return 1;
return 0;
}
static void FlashPoint_StartCCB(void *curr_card, struct sccb *p_Sccb)
{
u32 ioport;
unsigned char thisCard, lun;
struct sccb *pSaveSccb;
CALL_BK_FN callback;
struct sccb_card *pCurrCard = curr_card;
thisCard = pCurrCard->cardIndex;
ioport = pCurrCard->ioPort;
if ((p_Sccb->TargID >= MAX_SCSI_TAR) || (p_Sccb->Lun >= MAX_LUN)) {
p_Sccb->HostStatus = SCCB_COMPLETE;
p_Sccb->SccbStatus = SCCB_ERROR;
callback = (CALL_BK_FN) p_Sccb->SccbCallback;
if (callback)
callback(p_Sccb);
return;
}
FPT_sinits(p_Sccb, thisCard);
if (!pCurrCard->cmdCounter) {
WR_HARPOON(ioport + hp_semaphore,
(RD_HARPOON(ioport + hp_semaphore)
| SCCB_MGR_ACTIVE));
if (pCurrCard->globalFlags & F_GREEN_PC) {
WR_HARPOON(ioport + hp_clkctrl_0, CLKCTRL_DEFAULT);
WR_HARPOON(ioport + hp_sys_ctrl, 0x00);
}
}
pCurrCard->cmdCounter++;
if (RD_HARPOON(ioport + hp_semaphore) & BIOS_IN_USE) {
WR_HARPOON(ioport + hp_semaphore,
(RD_HARPOON(ioport + hp_semaphore)
| TICKLE_ME));
if (p_Sccb->OperationCode == RESET_COMMAND) {
pSaveSccb =
pCurrCard->currentSCCB;
pCurrCard->currentSCCB = p_Sccb;
FPT_queueSelectFail(&FPT_BL_Card[thisCard], thisCard);
pCurrCard->currentSCCB =
pSaveSccb;
} else {
FPT_queueAddSccb(p_Sccb, thisCard);
}
}
else if ((RD_HARPOON(ioport + hp_page_ctrl) & G_INT_DISABLE)) {
if (p_Sccb->OperationCode == RESET_COMMAND) {
pSaveSccb =
pCurrCard->currentSCCB;
pCurrCard->currentSCCB = p_Sccb;
FPT_queueSelectFail(&FPT_BL_Card[thisCard], thisCard);
pCurrCard->currentSCCB =
pSaveSccb;
} else {
FPT_queueAddSccb(p_Sccb, thisCard);
}
}
else {
MDISABLE_INT(ioport);
if ((pCurrCard->globalFlags & F_CONLUN_IO) &&
((FPT_sccbMgrTbl[thisCard][p_Sccb->TargID].
TarStatus & TAR_TAG_Q_MASK) != TAG_Q_TRYING))
lun = p_Sccb->Lun;
else
lun = 0;
if ((pCurrCard->currentSCCB == NULL) &&
(FPT_sccbMgrTbl[thisCard][p_Sccb->TargID].TarSelQ_Cnt == 0)
&& (FPT_sccbMgrTbl[thisCard][p_Sccb->TargID].TarLUNBusy[lun]
== 0)) {
pCurrCard->currentSCCB = p_Sccb;
FPT_ssel(p_Sccb->SccbIOPort, thisCard);
}
else {
if (p_Sccb->OperationCode == RESET_COMMAND) {
pSaveSccb = pCurrCard->currentSCCB;
pCurrCard->currentSCCB = p_Sccb;
FPT_queueSelectFail(&FPT_BL_Card[thisCard],
thisCard);
pCurrCard->currentSCCB = pSaveSccb;
} else {
FPT_queueAddSccb(p_Sccb, thisCard);
}
}
MENABLE_INT(ioport);
}
}
static int FlashPoint_AbortCCB(void *pCurrCard, struct sccb *p_Sccb)
{
u32 ioport;
unsigned char thisCard;
CALL_BK_FN callback;
unsigned char TID;
struct sccb *pSaveSCCB;
struct sccb_mgr_tar_info *currTar_Info;
ioport = ((struct sccb_card *)pCurrCard)->ioPort;
thisCard = ((struct sccb_card *)pCurrCard)->cardIndex;
if (!(RD_HARPOON(ioport + hp_page_ctrl) & G_INT_DISABLE)) {
if (FPT_queueFindSccb(p_Sccb, thisCard)) {
((struct sccb_card *)pCurrCard)->cmdCounter--;
if (!((struct sccb_card *)pCurrCard)->cmdCounter)
WR_HARPOON(ioport + hp_semaphore,
(RD_HARPOON(ioport + hp_semaphore)
& (unsigned
char)(~(SCCB_MGR_ACTIVE |
TICKLE_ME))));
p_Sccb->SccbStatus = SCCB_ABORT;
callback = p_Sccb->SccbCallback;
callback(p_Sccb);
return 0;
}
else {
if (((struct sccb_card *)pCurrCard)->currentSCCB ==
p_Sccb) {
p_Sccb->SccbStatus = SCCB_ABORT;
return 0;
}
else {
TID = p_Sccb->TargID;
if (p_Sccb->Sccb_tag) {
MDISABLE_INT(ioport);
if (((struct sccb_card *)pCurrCard)->
discQ_Tbl[p_Sccb->Sccb_tag] ==
p_Sccb) {
p_Sccb->SccbStatus = SCCB_ABORT;
p_Sccb->Sccb_scsistat =
ABORT_ST;
p_Sccb->Sccb_scsimsg =
SMABORT_TAG;
if (((struct sccb_card *)
pCurrCard)->currentSCCB ==
NULL) {
((struct sccb_card *)
pCurrCard)->
currentSCCB = p_Sccb;
FPT_ssel(ioport,
thisCard);
} else {
pSaveSCCB =
((struct sccb_card
*)pCurrCard)->
currentSCCB;
((struct sccb_card *)
pCurrCard)->
currentSCCB = p_Sccb;
FPT_queueSelectFail((struct sccb_card *)pCurrCard, thisCard);
((struct sccb_card *)
pCurrCard)->
currentSCCB = pSaveSCCB;
}
}
MENABLE_INT(ioport);
return 0;
} else {
currTar_Info =
&FPT_sccbMgrTbl[thisCard][p_Sccb->
TargID];
if (FPT_BL_Card[thisCard].
discQ_Tbl[currTar_Info->
LunDiscQ_Idx[p_Sccb->Lun]]
== p_Sccb) {
p_Sccb->SccbStatus = SCCB_ABORT;
return 0;
}
}
}
}
}
return -1;
}
static unsigned char FlashPoint_InterruptPending(void *pCurrCard)
{
u32 ioport;
ioport = ((struct sccb_card *)pCurrCard)->ioPort;
if (RD_HARPOON(ioport + hp_int_status) & INT_ASSERTED) {
return 1;
}
else
return 0;
}
static int FlashPoint_HandleInterrupt(void *pcard)
{
struct sccb *currSCCB;
unsigned char thisCard, result, bm_status, bm_int_st;
unsigned short hp_int;
unsigned char i, target;
struct sccb_card *pCurrCard = pcard;
u32 ioport;
thisCard = pCurrCard->cardIndex;
ioport = pCurrCard->ioPort;
MDISABLE_INT(ioport);
if ((bm_int_st = RD_HARPOON(ioport + hp_int_status)) & EXT_STATUS_ON)
bm_status = RD_HARPOON(ioport + hp_ext_status) &
(unsigned char)BAD_EXT_STATUS;
else
bm_status = 0;
WR_HARPOON(ioport + hp_int_mask, (INT_CMD_COMPL | SCSI_INTERRUPT));
while ((hp_int = RDW_HARPOON((ioport + hp_intstat)) &
FPT_default_intena) | bm_status) {
currSCCB = pCurrCard->currentSCCB;
if (hp_int & (FIFO | TIMEOUT | RESET | SCAM_SEL) || bm_status) {
result =
FPT_SccbMgr_bad_isr(ioport, thisCard, pCurrCard,
hp_int);
WRW_HARPOON((ioport + hp_intstat),
(FIFO | TIMEOUT | RESET | SCAM_SEL));
bm_status = 0;
if (result) {
MENABLE_INT(ioport);
return result;
}
}
else if (hp_int & ICMD_COMP) {
if (!(hp_int & BUS_FREE)) {
while (!
(RDW_HARPOON((ioport + hp_intstat)) &
(BUS_FREE | RSEL))) ;
}
if (pCurrCard->globalFlags & F_HOST_XFER_ACT)
FPT_phaseChkFifo(ioport, thisCard);
WRW_HARPOON((ioport + hp_intstat), CLR_ALL_INT_1);
FPT_autoCmdCmplt(ioport, thisCard);
}
else if (hp_int & ITAR_DISC) {
if (pCurrCard->globalFlags & F_HOST_XFER_ACT)
FPT_phaseChkFifo(ioport, thisCard);
if (RD_HARPOON(ioport + hp_gp_reg_1) ==
SMSAVE_DATA_PTR) {
WR_HARPOON(ioport + hp_gp_reg_1, 0x00);
currSCCB->Sccb_XferState |= F_NO_DATA_YET;
currSCCB->Sccb_savedATC = currSCCB->Sccb_ATC;
}
currSCCB->Sccb_scsistat = DISCONNECT_ST;
FPT_queueDisconnect(currSCCB, thisCard);
while (!
(RDW_HARPOON((ioport + hp_intstat)) &
(BUS_FREE | RSEL))
&& !((RDW_HARPOON((ioport + hp_intstat)) & PHASE)
&& RD_HARPOON((ioport + hp_scsisig)) ==
(SCSI_BSY | SCSI_REQ | SCSI_CD | SCSI_MSG |
SCSI_IOBIT))) ;
if (!
(RDW_HARPOON((ioport + hp_intstat)) &
(BUS_FREE | RSEL))) {
MENABLE_INT(ioport);
return 0xFE;
}
WRW_HARPOON((ioport + hp_intstat),
(BUS_FREE | ITAR_DISC));
pCurrCard->globalFlags |= F_NEW_SCCB_CMD;
}
else if (hp_int & RSEL) {
WRW_HARPOON((ioport + hp_intstat),
(PROG_HLT | RSEL | PHASE | BUS_FREE));
if (RDW_HARPOON((ioport + hp_intstat)) & ITAR_DISC) {
if (pCurrCard->globalFlags & F_HOST_XFER_ACT)
FPT_phaseChkFifo(ioport, thisCard);
if (RD_HARPOON(ioport + hp_gp_reg_1) ==
SMSAVE_DATA_PTR) {
WR_HARPOON(ioport + hp_gp_reg_1, 0x00);
currSCCB->Sccb_XferState |=
F_NO_DATA_YET;
currSCCB->Sccb_savedATC =
currSCCB->Sccb_ATC;
}
WRW_HARPOON((ioport + hp_intstat),
(BUS_FREE | ITAR_DISC));
currSCCB->Sccb_scsistat = DISCONNECT_ST;
FPT_queueDisconnect(currSCCB, thisCard);
}
FPT_sres(ioport, thisCard, pCurrCard);
FPT_phaseDecode(ioport, thisCard);
}
else if ((hp_int & IDO_STRT) && (!(hp_int & BUS_FREE))) {
WRW_HARPOON((ioport + hp_intstat),
(IDO_STRT | XFER_CNT_0));
FPT_phaseDecode(ioport, thisCard);
}
else if ((hp_int & IUNKWN) || (hp_int & PROG_HLT)) {
WRW_HARPOON((ioport + hp_intstat),
(PHASE | IUNKWN | PROG_HLT));
if ((RD_HARPOON(ioport + hp_prgmcnt_0) & (unsigned char)
0x3f) < (unsigned char)SELCHK) {
FPT_phaseDecode(ioport, thisCard);
} else {
i = (unsigned
char)(RD_HARPOON(ioport + hp_fifowrite));
target =
(unsigned
char)(RD_HARPOON(ioport + hp_gp_reg_3));
WR_HARPOON(ioport + hp_xfer_pad,
(unsigned char)ID_UNLOCK);
WR_HARPOON(ioport + hp_select_id,
(unsigned char)(target | target <<
4));
WR_HARPOON(ioport + hp_xfer_pad,
(unsigned char)0x00);
WR_HARPOON(ioport + hp_fifowrite, i);
WR_HARPOON(ioport + hp_autostart_3,
(AUTO_IMMED + TAG_STRT));
}
}
else if (hp_int & XFER_CNT_0) {
WRW_HARPOON((ioport + hp_intstat), XFER_CNT_0);
FPT_schkdd(ioport, thisCard);
}
else if (hp_int & BUS_FREE) {
WRW_HARPOON((ioport + hp_intstat), BUS_FREE);
if (pCurrCard->globalFlags & F_HOST_XFER_ACT) {
FPT_hostDataXferAbort(ioport, thisCard,
currSCCB);
}
FPT_phaseBusFree(ioport, thisCard);
}
else if (hp_int & ITICKLE) {
WRW_HARPOON((ioport + hp_intstat), ITICKLE);
pCurrCard->globalFlags |= F_NEW_SCCB_CMD;
}
if (((struct sccb_card *)pCurrCard)->
globalFlags & F_NEW_SCCB_CMD) {
pCurrCard->globalFlags &= ~F_NEW_SCCB_CMD;
if (pCurrCard->currentSCCB == NULL)
FPT_queueSearchSelect(pCurrCard, thisCard);
if (pCurrCard->currentSCCB != NULL) {
pCurrCard->globalFlags &= ~F_NEW_SCCB_CMD;
FPT_ssel(ioport, thisCard);
}
break;
}
}
MENABLE_INT(ioport);
return 0;
}
static unsigned char FPT_SccbMgr_bad_isr(u32 p_port, unsigned char p_card,
struct sccb_card *pCurrCard,
unsigned short p_int)
{
unsigned char temp, ScamFlg;
struct sccb_mgr_tar_info *currTar_Info;
struct nvram_info *pCurrNvRam;
if (RD_HARPOON(p_port + hp_ext_status) &
(BM_FORCE_OFF | PCI_DEV_TMOUT | BM_PARITY_ERR | PIO_OVERRUN)) {
if (pCurrCard->globalFlags & F_HOST_XFER_ACT) {
FPT_hostDataXferAbort(p_port, p_card,
pCurrCard->currentSCCB);
}
if (RD_HARPOON(p_port + hp_pci_stat_cfg) & REC_MASTER_ABORT)
{
WR_HARPOON(p_port + hp_pci_stat_cfg,
(RD_HARPOON(p_port + hp_pci_stat_cfg) &
~REC_MASTER_ABORT));
WR_HARPOON(p_port + hp_host_blk_cnt, 0x00);
}
if (pCurrCard->currentSCCB != NULL) {
if (!pCurrCard->currentSCCB->HostStatus)
pCurrCard->currentSCCB->HostStatus =
SCCB_BM_ERR;
FPT_sxfrp(p_port, p_card);
temp = (unsigned char)(RD_HARPOON(p_port + hp_ee_ctrl) &
(EXT_ARB_ACK | SCSI_TERM_ENA_H));
WR_HARPOON(p_port + hp_ee_ctrl,
((unsigned char)temp | SEE_MS | SEE_CS));
WR_HARPOON(p_port + hp_ee_ctrl, temp);
if (!
(RDW_HARPOON((p_port + hp_intstat)) &
(BUS_FREE | RESET))) {
FPT_phaseDecode(p_port, p_card);
}
}
}
else if (p_int & RESET) {
WR_HARPOON(p_port + hp_clkctrl_0, CLKCTRL_DEFAULT);
WR_HARPOON(p_port + hp_sys_ctrl, 0x00);
if (pCurrCard->currentSCCB != NULL) {
if (pCurrCard->globalFlags & F_HOST_XFER_ACT)
FPT_hostDataXferAbort(p_port, p_card,
pCurrCard->currentSCCB);
}
DISABLE_AUTO(p_port);
FPT_sresb(p_port, p_card);
while (RD_HARPOON(p_port + hp_scsictrl_0) & SCSI_RST) {
}
pCurrNvRam = pCurrCard->pNvRamInfo;
if (pCurrNvRam) {
ScamFlg = pCurrNvRam->niScamConf;
} else {
ScamFlg =
(unsigned char)FPT_utilEERead(p_port,
SCAM_CONFIG / 2);
}
FPT_XbowInit(p_port, ScamFlg);
FPT_scini(p_card, pCurrCard->ourId, 0);
return 0xFF;
}
else if (p_int & FIFO) {
WRW_HARPOON((p_port + hp_intstat), FIFO);
if (pCurrCard->currentSCCB != NULL)
FPT_sxfrp(p_port, p_card);
}
else if (p_int & TIMEOUT) {
DISABLE_AUTO(p_port);
WRW_HARPOON((p_port + hp_intstat),
(PROG_HLT | TIMEOUT | SEL | BUS_FREE | PHASE |
IUNKWN));
pCurrCard->currentSCCB->HostStatus = SCCB_SELECTION_TIMEOUT;
currTar_Info =
&FPT_sccbMgrTbl[p_card][pCurrCard->currentSCCB->TargID];
if ((pCurrCard->globalFlags & F_CONLUN_IO)
&& ((currTar_Info->TarStatus & TAR_TAG_Q_MASK) !=
TAG_Q_TRYING))
currTar_Info->TarLUNBusy[pCurrCard->currentSCCB->Lun] =
0;
else
currTar_Info->TarLUNBusy[0] = 0;
if (currTar_Info->TarEEValue & EE_SYNC_MASK) {
currTar_Info->TarSyncCtrl = 0;
currTar_Info->TarStatus &= ~TAR_SYNC_MASK;
}
if (currTar_Info->TarEEValue & EE_WIDE_SCSI) {
currTar_Info->TarStatus &= ~TAR_WIDE_MASK;
}
FPT_sssyncv(p_port, pCurrCard->currentSCCB->TargID, NARROW_SCSI,
currTar_Info);
FPT_queueCmdComplete(pCurrCard, pCurrCard->currentSCCB, p_card);
}
else if (p_int & SCAM_SEL) {
FPT_scarb(p_port, LEVEL2_TAR);
FPT_scsel(p_port);
FPT_scasid(p_card, p_port);
FPT_scbusf(p_port);
WRW_HARPOON((p_port + hp_intstat), SCAM_SEL);
}
return 0x00;
}
static void FPT_SccbMgrTableInitAll(void)
{
unsigned char thisCard;
for (thisCard = 0; thisCard < MAX_CARDS; thisCard++) {
FPT_SccbMgrTableInitCard(&FPT_BL_Card[thisCard], thisCard);
FPT_BL_Card[thisCard].ioPort = 0x00;
FPT_BL_Card[thisCard].cardInfo = NULL;
FPT_BL_Card[thisCard].cardIndex = 0xFF;
FPT_BL_Card[thisCard].ourId = 0x00;
FPT_BL_Card[thisCard].pNvRamInfo = NULL;
}
}
static void FPT_SccbMgrTableInitCard(struct sccb_card *pCurrCard,
unsigned char p_card)
{
unsigned char scsiID, qtag;
for (qtag = 0; qtag < QUEUE_DEPTH; qtag++) {
FPT_BL_Card[p_card].discQ_Tbl[qtag] = NULL;
}
for (scsiID = 0; scsiID < MAX_SCSI_TAR; scsiID++) {
FPT_sccbMgrTbl[p_card][scsiID].TarStatus = 0;
FPT_sccbMgrTbl[p_card][scsiID].TarEEValue = 0;
FPT_SccbMgrTableInitTarget(p_card, scsiID);
}
pCurrCard->scanIndex = 0x00;
pCurrCard->currentSCCB = NULL;
pCurrCard->globalFlags = 0x00;
pCurrCard->cmdCounter = 0x00;
pCurrCard->tagQ_Lst = 0x01;
pCurrCard->discQCount = 0;
}
static void FPT_SccbMgrTableInitTarget(unsigned char p_card,
unsigned char target)
{
unsigned char lun, qtag;
struct sccb_mgr_tar_info *currTar_Info;
currTar_Info = &FPT_sccbMgrTbl[p_card][target];
currTar_Info->TarSelQ_Cnt = 0;
currTar_Info->TarSyncCtrl = 0;
currTar_Info->TarSelQ_Head = NULL;
currTar_Info->TarSelQ_Tail = NULL;
currTar_Info->TarTagQ_Cnt = 0;
currTar_Info->TarLUN_CA = 0;
for (lun = 0; lun < MAX_LUN; lun++) {
currTar_Info->TarLUNBusy[lun] = 0;
currTar_Info->LunDiscQ_Idx[lun] = 0;
}
for (qtag = 0; qtag < QUEUE_DEPTH; qtag++) {
if (FPT_BL_Card[p_card].discQ_Tbl[qtag] != NULL) {
if (FPT_BL_Card[p_card].discQ_Tbl[qtag]->TargID ==
target) {
FPT_BL_Card[p_card].discQ_Tbl[qtag] = NULL;
FPT_BL_Card[p_card].discQCount--;
}
}
}
}
static unsigned char FPT_sfm(u32 port, struct sccb *pCurrSCCB)
{
unsigned char message;
unsigned short TimeOutLoop;
TimeOutLoop = 0;
while ((!(RD_HARPOON(port + hp_scsisig) & SCSI_REQ)) &&
(TimeOutLoop++ < 20000)) {
}
WR_HARPOON(port + hp_portctrl_0, SCSI_PORT);
message = RD_HARPOON(port + hp_scsidata_0);
WR_HARPOON(port + hp_scsisig, SCSI_ACK + S_MSGI_PH);
if (TimeOutLoop > 20000)
message = 0x00;
if ((RDW_HARPOON((port + hp_intstat)) & PARITY) &&
(RD_HARPOON(port + hp_addstat) & SCSI_PAR_ERR)) {
WR_HARPOON(port + hp_scsisig, (SCSI_ACK + S_ILL_PH));
WR_HARPOON(port + hp_xferstat, 0);
WR_HARPOON(port + hp_fiforead, 0);
WR_HARPOON(port + hp_fifowrite, 0);
if (pCurrSCCB != NULL) {
pCurrSCCB->Sccb_scsimsg = SMPARITY;
}
message = 0x00;
do {
ACCEPT_MSG_ATN(port);
TimeOutLoop = 0;
while ((!(RD_HARPOON(port + hp_scsisig) & SCSI_REQ)) &&
(TimeOutLoop++ < 20000)) {
}
if (TimeOutLoop > 20000) {
WRW_HARPOON((port + hp_intstat), PARITY);
return message;
}
if ((RD_HARPOON(port + hp_scsisig) & S_SCSI_PHZ) !=
S_MSGI_PH) {
WRW_HARPOON((port + hp_intstat), PARITY);
return message;
}
WR_HARPOON(port + hp_portctrl_0, SCSI_PORT);
RD_HARPOON(port + hp_scsidata_0);
WR_HARPOON(port + hp_scsisig, (SCSI_ACK + S_ILL_PH));
} while (1);
}
WR_HARPOON(port + hp_scsisig, (SCSI_ACK + S_ILL_PH));
WR_HARPOON(port + hp_xferstat, 0);
WR_HARPOON(port + hp_fiforead, 0);
WR_HARPOON(port + hp_fifowrite, 0);
return message;
}
static void FPT_ssel(u32 port, unsigned char p_card)
{
unsigned char auto_loaded, i, target, *theCCB;
u32 cdb_reg;
struct sccb_card *CurrCard;
struct sccb *currSCCB;
struct sccb_mgr_tar_info *currTar_Info;
unsigned char lastTag, lun;
CurrCard = &FPT_BL_Card[p_card];
currSCCB = CurrCard->currentSCCB;
target = currSCCB->TargID;
currTar_Info = &FPT_sccbMgrTbl[p_card][target];
lastTag = CurrCard->tagQ_Lst;
ARAM_ACCESS(port);
if ((currTar_Info->TarStatus & TAR_TAG_Q_MASK) == TAG_Q_REJECT)
currSCCB->ControlByte &= ~F_USE_CMD_Q;
if (((CurrCard->globalFlags & F_CONLUN_IO) &&
((currTar_Info->TarStatus & TAR_TAG_Q_MASK) != TAG_Q_TRYING)))
lun = currSCCB->Lun;
else
lun = 0;
if (CurrCard->globalFlags & F_TAG_STARTED) {
if (!(currSCCB->ControlByte & F_USE_CMD_Q)) {
if ((currTar_Info->TarLUN_CA == 0)
&& ((currTar_Info->TarStatus & TAR_TAG_Q_MASK)
== TAG_Q_TRYING)) {
if (currTar_Info->TarTagQ_Cnt != 0) {
currTar_Info->TarLUNBusy[lun] = 1;
FPT_queueSelectFail(CurrCard, p_card);
SGRAM_ACCESS(port);
return;
}
else {
currTar_Info->TarLUNBusy[lun] = 1;
}
}
else {
currTar_Info->TarLUNBusy[lun] = 1;
}
}
else {
if (currTar_Info->TarLUN_CA == 1) {
FPT_queueSelectFail(CurrCard, p_card);
SGRAM_ACCESS(port);
return;
}
currTar_Info->TarLUNBusy[lun] = 1;
}
}
else {
currTar_Info->TarLUNBusy[lun] = 1;
}
if ((((CurrCard->globalFlags & F_CONLUN_IO) &&
((currTar_Info->TarStatus & TAR_TAG_Q_MASK) != TAG_Q_TRYING))
|| (!(currSCCB->ControlByte & F_USE_CMD_Q)))) {
if (CurrCard->discQCount >= QUEUE_DEPTH) {
currTar_Info->TarLUNBusy[lun] = 1;
FPT_queueSelectFail(CurrCard, p_card);
SGRAM_ACCESS(port);
return;
}
for (i = 1; i < QUEUE_DEPTH; i++) {
if (++lastTag >= QUEUE_DEPTH)
lastTag = 1;
if (CurrCard->discQ_Tbl[lastTag] == NULL) {
CurrCard->tagQ_Lst = lastTag;
currTar_Info->LunDiscQ_Idx[lun] = lastTag;
CurrCard->discQ_Tbl[lastTag] = currSCCB;
CurrCard->discQCount++;
break;
}
}
if (i == QUEUE_DEPTH) {
currTar_Info->TarLUNBusy[lun] = 1;
FPT_queueSelectFail(CurrCard, p_card);
SGRAM_ACCESS(port);
return;
}
}
auto_loaded = 0;
WR_HARPOON(port + hp_select_id, target);
WR_HARPOON(port + hp_gp_reg_3, target);
if (currSCCB->OperationCode == RESET_COMMAND) {
WRW_HARPOON((port + ID_MSG_STRT), (MPM_OP + AMSG_OUT +
(currSCCB->
Sccb_idmsg & ~DISC_PRIV)));
WRW_HARPOON((port + ID_MSG_STRT + 2), BRH_OP + ALWAYS + NP);
currSCCB->Sccb_scsimsg = SMDEV_RESET;
WR_HARPOON(port + hp_autostart_3, (SELECT + SELCHK_STRT));
auto_loaded = 1;
currSCCB->Sccb_scsistat = SELECT_BDR_ST;
if (currTar_Info->TarEEValue & EE_SYNC_MASK) {
currTar_Info->TarSyncCtrl = 0;
currTar_Info->TarStatus &= ~TAR_SYNC_MASK;
}
if (currTar_Info->TarEEValue & EE_WIDE_SCSI) {
currTar_Info->TarStatus &= ~TAR_WIDE_MASK;
}
FPT_sssyncv(port, target, NARROW_SCSI, currTar_Info);
FPT_SccbMgrTableInitTarget(p_card, target);
}
else if (currSCCB->Sccb_scsistat == ABORT_ST) {
WRW_HARPOON((port + ID_MSG_STRT), (MPM_OP + AMSG_OUT +
(currSCCB->
Sccb_idmsg & ~DISC_PRIV)));
WRW_HARPOON((port + ID_MSG_STRT + 2), BRH_OP + ALWAYS + CMDPZ);
WRW_HARPOON((port + SYNC_MSGS + 0), (MPM_OP + AMSG_OUT +
(((unsigned
char)(currSCCB->
ControlByte &
TAG_TYPE_MASK)
>> 6) | (unsigned char)
0x20)));
WRW_HARPOON((port + SYNC_MSGS + 2),
(MPM_OP + AMSG_OUT + currSCCB->Sccb_tag));
WRW_HARPOON((port + SYNC_MSGS + 4), (BRH_OP + ALWAYS + NP));
WR_HARPOON(port + hp_autostart_3, (SELECT + SELCHK_STRT));
auto_loaded = 1;
}
else if (!(currTar_Info->TarStatus & WIDE_NEGOCIATED)) {
auto_loaded = FPT_siwidn(port, p_card);
currSCCB->Sccb_scsistat = SELECT_WN_ST;
}
else if (!((currTar_Info->TarStatus & TAR_SYNC_MASK)
== SYNC_SUPPORTED)) {
auto_loaded = FPT_sisyncn(port, p_card, 0);
currSCCB->Sccb_scsistat = SELECT_SN_ST;
}
if (!auto_loaded) {
if (currSCCB->ControlByte & F_USE_CMD_Q) {
CurrCard->globalFlags |= F_TAG_STARTED;
if ((currTar_Info->TarStatus & TAR_TAG_Q_MASK)
== TAG_Q_REJECT) {
currSCCB->ControlByte &= ~F_USE_CMD_Q;
WRW_HARPOON((port + ID_MSG_STRT),
BRH_OP + ALWAYS + NTCMD);
WRW_HARPOON((port + NON_TAG_ID_MSG),
(MPM_OP + AMSG_OUT +
currSCCB->Sccb_idmsg));
WR_HARPOON(port + hp_autostart_3,
(SELECT + SELCHK_STRT));
currSCCB->Sccb_scsistat = SELECT_ST;
currTar_Info->TarLUNBusy[lun] = 1;
}
else {
WRW_HARPOON((port + ID_MSG_STRT),
(MPM_OP + AMSG_OUT +
currSCCB->Sccb_idmsg));
WRW_HARPOON((port + ID_MSG_STRT + 2),
(MPM_OP + AMSG_OUT +
(((unsigned char)(currSCCB->
ControlByte &
TAG_TYPE_MASK)
>> 6) | (unsigned char)0x20)));
for (i = 1; i < QUEUE_DEPTH; i++) {
if (++lastTag >= QUEUE_DEPTH)
lastTag = 1;
if (CurrCard->discQ_Tbl[lastTag] ==
NULL) {
WRW_HARPOON((port +
ID_MSG_STRT + 6),
(MPM_OP + AMSG_OUT +
lastTag));
CurrCard->tagQ_Lst = lastTag;
currSCCB->Sccb_tag = lastTag;
CurrCard->discQ_Tbl[lastTag] =
currSCCB;
CurrCard->discQCount++;
break;
}
}
if (i == QUEUE_DEPTH) {
currTar_Info->TarLUNBusy[lun] = 1;
FPT_queueSelectFail(CurrCard, p_card);
SGRAM_ACCESS(port);
return;
}
currSCCB->Sccb_scsistat = SELECT_Q_ST;
WR_HARPOON(port + hp_autostart_3,
(SELECT + SELCHK_STRT));
}
}
else {
WRW_HARPOON((port + ID_MSG_STRT),
BRH_OP + ALWAYS + NTCMD);
WRW_HARPOON((port + NON_TAG_ID_MSG),
(MPM_OP + AMSG_OUT + currSCCB->Sccb_idmsg));
currSCCB->Sccb_scsistat = SELECT_ST;
WR_HARPOON(port + hp_autostart_3,
(SELECT + SELCHK_STRT));
}
theCCB = (unsigned char *)&currSCCB->Cdb[0];
cdb_reg = port + CMD_STRT;
for (i = 0; i < currSCCB->CdbLength; i++) {
WRW_HARPOON(cdb_reg, (MPM_OP + ACOMMAND + *theCCB));
cdb_reg += 2;
theCCB++;
}
if (currSCCB->CdbLength != TWELVE_BYTE_CMD)
WRW_HARPOON(cdb_reg, (BRH_OP + ALWAYS + NP));
}
WRW_HARPOON((port + hp_fiforead), (unsigned short)0x00);
WR_HARPOON(port + hp_xferstat, 0x00);
WRW_HARPOON((port + hp_intstat), (PROG_HLT | TIMEOUT | SEL | BUS_FREE));
WR_HARPOON(port + hp_portctrl_0, (SCSI_PORT));
if (!(currSCCB->Sccb_MGRFlags & F_DEV_SELECTED)) {
WR_HARPOON(port + hp_scsictrl_0,
(SEL_TAR | ENA_ATN | ENA_RESEL | ENA_SCAM_SEL));
} else {
auto_loaded = AUTO_IMMED;
DISABLE_AUTO(port);
WR_HARPOON(port + hp_autostart_3, auto_loaded);
}
SGRAM_ACCESS(port);
}
static void FPT_sres(u32 port, unsigned char p_card,
struct sccb_card *pCurrCard)
{
unsigned char our_target, message, lun = 0, tag, msgRetryCount;
struct sccb_mgr_tar_info *currTar_Info;
struct sccb *currSCCB;
if (pCurrCard->currentSCCB != NULL) {
currTar_Info =
&FPT_sccbMgrTbl[p_card][pCurrCard->currentSCCB->TargID];
DISABLE_AUTO(port);
WR_HARPOON((port + hp_scsictrl_0), (ENA_RESEL | ENA_SCAM_SEL));
currSCCB = pCurrCard->currentSCCB;
if (currSCCB->Sccb_scsistat == SELECT_WN_ST) {
currTar_Info->TarStatus &= ~TAR_WIDE_MASK;
currSCCB->Sccb_scsistat = BUS_FREE_ST;
}
if (currSCCB->Sccb_scsistat == SELECT_SN_ST) {
currTar_Info->TarStatus &= ~TAR_SYNC_MASK;
currSCCB->Sccb_scsistat = BUS_FREE_ST;
}
if (((pCurrCard->globalFlags & F_CONLUN_IO) &&
((currTar_Info->TarStatus & TAR_TAG_Q_MASK) !=
TAG_Q_TRYING))) {
currTar_Info->TarLUNBusy[currSCCB->Lun] = 0;
if (currSCCB->Sccb_scsistat != ABORT_ST) {
pCurrCard->discQCount--;
pCurrCard->discQ_Tbl[currTar_Info->
LunDiscQ_Idx[currSCCB->
Lun]]
= NULL;
}
} else {
currTar_Info->TarLUNBusy[0] = 0;
if (currSCCB->Sccb_tag) {
if (currSCCB->Sccb_scsistat != ABORT_ST) {
pCurrCard->discQCount--;
pCurrCard->discQ_Tbl[currSCCB->
Sccb_tag] = NULL;
}
} else {
if (currSCCB->Sccb_scsistat != ABORT_ST) {
pCurrCard->discQCount--;
pCurrCard->discQ_Tbl[currTar_Info->
LunDiscQ_Idx[0]] =
NULL;
}
}
}
FPT_queueSelectFail(&FPT_BL_Card[p_card], p_card);
}
WRW_HARPOON((port + hp_fiforead), (unsigned short)0x00);
our_target = (unsigned char)(RD_HARPOON(port + hp_select_id) >> 4);
currTar_Info = &FPT_sccbMgrTbl[p_card][our_target];
msgRetryCount = 0;
do {
currTar_Info = &FPT_sccbMgrTbl[p_card][our_target];
tag = 0;
while (!(RD_HARPOON(port + hp_scsisig) & SCSI_REQ)) {
if (!(RD_HARPOON(port + hp_scsisig) & SCSI_BSY)) {
WRW_HARPOON((port + hp_intstat), PHASE);
return;
}
}
WRW_HARPOON((port + hp_intstat), PHASE);
if ((RD_HARPOON(port + hp_scsisig) & S_SCSI_PHZ) == S_MSGI_PH) {
message = FPT_sfm(port, pCurrCard->currentSCCB);
if (message) {
if (message <= (0x80 | LUN_MASK)) {
lun = message & (unsigned char)LUN_MASK;
if ((currTar_Info->
TarStatus & TAR_TAG_Q_MASK) ==
TAG_Q_TRYING) {
if (currTar_Info->TarTagQ_Cnt !=
0) {
if (!
(currTar_Info->
TarLUN_CA)) {
ACCEPT_MSG(port);
message =
FPT_sfm
(port,
pCurrCard->
currentSCCB);
if (message) {
ACCEPT_MSG
(port);
}
else
message
= 0;
if (message !=
0) {
tag =
FPT_sfm
(port,
pCurrCard->
currentSCCB);
if (!
(tag))
message
=
0;
}
}
}
}
}
else {
ACCEPT_MSG_ATN(port);
}
}
else {
message = 0;
}
} else {
ACCEPT_MSG_ATN(port);
while (!
(RDW_HARPOON((port + hp_intstat)) &
(PHASE | RESET))
&& !(RD_HARPOON(port + hp_scsisig) & SCSI_REQ)
&& (RD_HARPOON(port + hp_scsisig) & SCSI_BSY)) ;
return;
}
if (message == 0) {
msgRetryCount++;
if (msgRetryCount == 1) {
FPT_SendMsg(port, SMPARITY);
} else {
FPT_SendMsg(port, SMDEV_RESET);
FPT_sssyncv(port, our_target, NARROW_SCSI,
currTar_Info);
if (FPT_sccbMgrTbl[p_card][our_target].
TarEEValue & EE_SYNC_MASK) {
FPT_sccbMgrTbl[p_card][our_target].
TarStatus &= ~TAR_SYNC_MASK;
}
if (FPT_sccbMgrTbl[p_card][our_target].
TarEEValue & EE_WIDE_SCSI) {
FPT_sccbMgrTbl[p_card][our_target].
TarStatus &= ~TAR_WIDE_MASK;
}
FPT_queueFlushTargSccb(p_card, our_target,
SCCB_COMPLETE);
FPT_SccbMgrTableInitTarget(p_card, our_target);
return;
}
}
} while (message == 0);
if (((pCurrCard->globalFlags & F_CONLUN_IO) &&
((currTar_Info->TarStatus & TAR_TAG_Q_MASK) != TAG_Q_TRYING))) {
currTar_Info->TarLUNBusy[lun] = 1;
pCurrCard->currentSCCB =
pCurrCard->discQ_Tbl[currTar_Info->LunDiscQ_Idx[lun]];
if (pCurrCard->currentSCCB != NULL) {
ACCEPT_MSG(port);
} else {
ACCEPT_MSG_ATN(port);
}
} else {
currTar_Info->TarLUNBusy[0] = 1;
if (tag) {
if (pCurrCard->discQ_Tbl[tag] != NULL) {
pCurrCard->currentSCCB =
pCurrCard->discQ_Tbl[tag];
currTar_Info->TarTagQ_Cnt--;
ACCEPT_MSG(port);
} else {
ACCEPT_MSG_ATN(port);
}
} else {
pCurrCard->currentSCCB =
pCurrCard->discQ_Tbl[currTar_Info->LunDiscQ_Idx[0]];
if (pCurrCard->currentSCCB != NULL) {
ACCEPT_MSG(port);
} else {
ACCEPT_MSG_ATN(port);
}
}
}
if (pCurrCard->currentSCCB != NULL) {
if (pCurrCard->currentSCCB->Sccb_scsistat == ABORT_ST) {
FPT_queueFindSccb(pCurrCard->currentSCCB, p_card);
}
}
while (!(RDW_HARPOON((port + hp_intstat)) & (PHASE | RESET)) &&
!(RD_HARPOON(port + hp_scsisig) & SCSI_REQ) &&
(RD_HARPOON(port + hp_scsisig) & SCSI_BSY)) ;
}
static void FPT_SendMsg(u32 port, unsigned char message)
{
while (!(RD_HARPOON(port + hp_scsisig) & SCSI_REQ)) {
if (!(RD_HARPOON(port + hp_scsisig) & SCSI_BSY)) {
WRW_HARPOON((port + hp_intstat), PHASE);
return;
}
}
WRW_HARPOON((port + hp_intstat), PHASE);
if ((RD_HARPOON(port + hp_scsisig) & S_SCSI_PHZ) == S_MSGO_PH) {
WRW_HARPOON((port + hp_intstat),
(BUS_FREE | PHASE | XFER_CNT_0));
WR_HARPOON(port + hp_portctrl_0, SCSI_BUS_EN);
WR_HARPOON(port + hp_scsidata_0, message);
WR_HARPOON(port + hp_scsisig, (SCSI_ACK + S_ILL_PH));
ACCEPT_MSG(port);
WR_HARPOON(port + hp_portctrl_0, 0x00);
if ((message == SMABORT) || (message == SMDEV_RESET) ||
(message == SMABORT_TAG)) {
while (!
(RDW_HARPOON((port + hp_intstat)) &
(BUS_FREE | PHASE))) {
}
if (RDW_HARPOON((port + hp_intstat)) & BUS_FREE) {
WRW_HARPOON((port + hp_intstat), BUS_FREE);
}
}
}
}
static void FPT_sdecm(unsigned char message, u32 port, unsigned char p_card)
{
struct sccb *currSCCB;
struct sccb_card *CurrCard;
struct sccb_mgr_tar_info *currTar_Info;
CurrCard = &FPT_BL_Card[p_card];
currSCCB = CurrCard->currentSCCB;
currTar_Info = &FPT_sccbMgrTbl[p_card][currSCCB->TargID];
if (message == SMREST_DATA_PTR) {
if (!(currSCCB->Sccb_XferState & F_NO_DATA_YET)) {
currSCCB->Sccb_ATC = currSCCB->Sccb_savedATC;
FPT_hostDataXferRestart(currSCCB);
}
ACCEPT_MSG(port);
WR_HARPOON(port + hp_autostart_1,
(AUTO_IMMED + DISCONNECT_START));
}
else if (message == SMCMD_COMP) {
if (currSCCB->Sccb_scsistat == SELECT_Q_ST) {
currTar_Info->TarStatus &=
~(unsigned char)TAR_TAG_Q_MASK;
currTar_Info->TarStatus |= (unsigned char)TAG_Q_REJECT;
}
ACCEPT_MSG(port);
}
else if ((message == SMNO_OP) || (message >= SMIDENT)
|| (message == SMINIT_RECOVERY) || (message == SMREL_RECOVERY)) {
ACCEPT_MSG(port);
WR_HARPOON(port + hp_autostart_1,
(AUTO_IMMED + DISCONNECT_START));
}
else if (message == SMREJECT) {
if ((currSCCB->Sccb_scsistat == SELECT_SN_ST) ||
(currSCCB->Sccb_scsistat == SELECT_WN_ST) ||
((currTar_Info->TarStatus & TAR_SYNC_MASK) == SYNC_TRYING)
|| ((currTar_Info->TarStatus & TAR_TAG_Q_MASK) ==
TAG_Q_TRYING))
{
WRW_HARPOON((port + hp_intstat), BUS_FREE);
ACCEPT_MSG(port);
while ((!(RD_HARPOON(port + hp_scsisig) & SCSI_REQ)) &&
(!(RDW_HARPOON((port + hp_intstat)) & BUS_FREE)))
{
}
if (currSCCB->Lun == 0x00) {
if ((currSCCB->Sccb_scsistat == SELECT_SN_ST)) {
currTar_Info->TarStatus |=
(unsigned char)SYNC_SUPPORTED;
currTar_Info->TarEEValue &=
~EE_SYNC_MASK;
}
else if ((currSCCB->Sccb_scsistat ==
SELECT_WN_ST)) {
currTar_Info->TarStatus =
(currTar_Info->
TarStatus & ~WIDE_ENABLED) |
WIDE_NEGOCIATED;
currTar_Info->TarEEValue &=
~EE_WIDE_SCSI;
}
else if ((currTar_Info->
TarStatus & TAR_TAG_Q_MASK) ==
TAG_Q_TRYING) {
currTar_Info->TarStatus =
(currTar_Info->
TarStatus & ~(unsigned char)
TAR_TAG_Q_MASK) | TAG_Q_REJECT;
currSCCB->ControlByte &= ~F_USE_CMD_Q;
CurrCard->discQCount--;
CurrCard->discQ_Tbl[currSCCB->
Sccb_tag] = NULL;
currSCCB->Sccb_tag = 0x00;
}
}
if (RDW_HARPOON((port + hp_intstat)) & BUS_FREE) {
if (currSCCB->Lun == 0x00) {
WRW_HARPOON((port + hp_intstat),
BUS_FREE);
CurrCard->globalFlags |= F_NEW_SCCB_CMD;
}
}
else {
if ((CurrCard->globalFlags & F_CONLUN_IO) &&
((currTar_Info->
TarStatus & TAR_TAG_Q_MASK) !=
TAG_Q_TRYING))
currTar_Info->TarLUNBusy[currSCCB->
Lun] = 1;
else
currTar_Info->TarLUNBusy[0] = 1;
currSCCB->ControlByte &=
~(unsigned char)F_USE_CMD_Q;
WR_HARPOON(port + hp_autostart_1,
(AUTO_IMMED + DISCONNECT_START));
}
}
else {
ACCEPT_MSG(port);
while ((!(RD_HARPOON(port + hp_scsisig) & SCSI_REQ)) &&
(!(RDW_HARPOON((port + hp_intstat)) & BUS_FREE)))
{
}
if (!(RDW_HARPOON((port + hp_intstat)) & BUS_FREE)) {
WR_HARPOON(port + hp_autostart_1,
(AUTO_IMMED + DISCONNECT_START));
}
}
}
else if (message == SMEXT) {
ACCEPT_MSG(port);
FPT_shandem(port, p_card, currSCCB);
}
else if (message == SMIGNORWR) {
ACCEPT_MSG(port);
message = FPT_sfm(port, currSCCB);
if (currSCCB->Sccb_scsimsg != SMPARITY)
ACCEPT_MSG(port);
WR_HARPOON(port + hp_autostart_1,
(AUTO_IMMED + DISCONNECT_START));
}
else {
currSCCB->HostStatus = SCCB_PHASE_SEQUENCE_FAIL;
currSCCB->Sccb_scsimsg = SMREJECT;
ACCEPT_MSG_ATN(port);
WR_HARPOON(port + hp_autostart_1,
(AUTO_IMMED + DISCONNECT_START));
}
}
static void FPT_shandem(u32 port, unsigned char p_card, struct sccb *pCurrSCCB)
{
unsigned char length, message;
length = FPT_sfm(port, pCurrSCCB);
if (length) {
ACCEPT_MSG(port);
message = FPT_sfm(port, pCurrSCCB);
if (message) {
if (message == SMSYNC) {
if (length == 0x03) {
ACCEPT_MSG(port);
FPT_stsyncn(port, p_card);
} else {
pCurrSCCB->Sccb_scsimsg = SMREJECT;
ACCEPT_MSG_ATN(port);
}
} else if (message == SMWDTR) {
if (length == 0x02) {
ACCEPT_MSG(port);
FPT_stwidn(port, p_card);
} else {
pCurrSCCB->Sccb_scsimsg = SMREJECT;
ACCEPT_MSG_ATN(port);
WR_HARPOON(port + hp_autostart_1,
(AUTO_IMMED +
DISCONNECT_START));
}
} else {
pCurrSCCB->Sccb_scsimsg = SMREJECT;
ACCEPT_MSG_ATN(port);
WR_HARPOON(port + hp_autostart_1,
(AUTO_IMMED + DISCONNECT_START));
}
} else {
if (pCurrSCCB->Sccb_scsimsg != SMPARITY)
ACCEPT_MSG(port);
WR_HARPOON(port + hp_autostart_1,
(AUTO_IMMED + DISCONNECT_START));
}
} else {
if (pCurrSCCB->Sccb_scsimsg == SMPARITY)
WR_HARPOON(port + hp_autostart_1,
(AUTO_IMMED + DISCONNECT_START));
}
}
static unsigned char FPT_sisyncn(u32 port, unsigned char p_card,
unsigned char syncFlag)
{
struct sccb *currSCCB;
struct sccb_mgr_tar_info *currTar_Info;
currSCCB = FPT_BL_Card[p_card].currentSCCB;
currTar_Info = &FPT_sccbMgrTbl[p_card][currSCCB->TargID];
if (!((currTar_Info->TarStatus & TAR_SYNC_MASK) == SYNC_TRYING)) {
WRW_HARPOON((port + ID_MSG_STRT),
(MPM_OP + AMSG_OUT +
(currSCCB->
Sccb_idmsg & ~(unsigned char)DISC_PRIV)));
WRW_HARPOON((port + ID_MSG_STRT + 2), BRH_OP + ALWAYS + CMDPZ);
WRW_HARPOON((port + SYNC_MSGS + 0),
(MPM_OP + AMSG_OUT + SMEXT));
WRW_HARPOON((port + SYNC_MSGS + 2), (MPM_OP + AMSG_OUT + 0x03));
WRW_HARPOON((port + SYNC_MSGS + 4),
(MPM_OP + AMSG_OUT + SMSYNC));
if ((currTar_Info->TarEEValue & EE_SYNC_MASK) == EE_SYNC_20MB)
WRW_HARPOON((port + SYNC_MSGS + 6),
(MPM_OP + AMSG_OUT + 12));
else if ((currTar_Info->TarEEValue & EE_SYNC_MASK) ==
EE_SYNC_10MB)
WRW_HARPOON((port + SYNC_MSGS + 6),
(MPM_OP + AMSG_OUT + 25));
else if ((currTar_Info->TarEEValue & EE_SYNC_MASK) ==
EE_SYNC_5MB)
WRW_HARPOON((port + SYNC_MSGS + 6),
(MPM_OP + AMSG_OUT + 50));
else
WRW_HARPOON((port + SYNC_MSGS + 6),
(MPM_OP + AMSG_OUT + 00));
WRW_HARPOON((port + SYNC_MSGS + 8), (RAT_OP));
WRW_HARPOON((port + SYNC_MSGS + 10),
(MPM_OP + AMSG_OUT + DEFAULT_OFFSET));
WRW_HARPOON((port + SYNC_MSGS + 12), (BRH_OP + ALWAYS + NP));
if (syncFlag == 0) {
WR_HARPOON(port + hp_autostart_3,
(SELECT + SELCHK_STRT));
currTar_Info->TarStatus =
((currTar_Info->
TarStatus & ~(unsigned char)TAR_SYNC_MASK) |
(unsigned char)SYNC_TRYING);
} else {
WR_HARPOON(port + hp_autostart_3,
(AUTO_IMMED + CMD_ONLY_STRT));
}
return 1;
}
else {
currTar_Info->TarStatus |= (unsigned char)SYNC_SUPPORTED;
currTar_Info->TarEEValue &= ~EE_SYNC_MASK;
return 0;
}
}
static void FPT_stsyncn(u32 port, unsigned char p_card)
{
unsigned char sync_msg, offset, sync_reg, our_sync_msg;
struct sccb *currSCCB;
struct sccb_mgr_tar_info *currTar_Info;
currSCCB = FPT_BL_Card[p_card].currentSCCB;
currTar_Info = &FPT_sccbMgrTbl[p_card][currSCCB->TargID];
sync_msg = FPT_sfm(port, currSCCB);
if ((sync_msg == 0x00) && (currSCCB->Sccb_scsimsg == SMPARITY)) {
WR_HARPOON(port + hp_autostart_1,
(AUTO_IMMED + DISCONNECT_START));
return;
}
ACCEPT_MSG(port);
offset = FPT_sfm(port, currSCCB);
if ((offset == 0x00) && (currSCCB->Sccb_scsimsg == SMPARITY)) {
WR_HARPOON(port + hp_autostart_1,
(AUTO_IMMED + DISCONNECT_START));
return;
}
if ((currTar_Info->TarEEValue & EE_SYNC_MASK) == EE_SYNC_20MB)
our_sync_msg = 12;
else if ((currTar_Info->TarEEValue & EE_SYNC_MASK) == EE_SYNC_10MB)
our_sync_msg = 25;
else if ((currTar_Info->TarEEValue & EE_SYNC_MASK) == EE_SYNC_5MB)
our_sync_msg = 50;
else
our_sync_msg = 0;
if (sync_msg < our_sync_msg) {
sync_msg = our_sync_msg;
}
if (offset == ASYNC)
sync_msg = ASYNC;
if (offset > MAX_OFFSET)
offset = MAX_OFFSET;
sync_reg = 0x00;
if (sync_msg > 12)
sync_reg = 0x20;
if (sync_msg > 25)
sync_reg = 0x40;
if (sync_msg > 38)
sync_reg = 0x60;
if (sync_msg > 50)
sync_reg = 0x80;
if (sync_msg > 62)
sync_reg = 0xA0;
if (sync_msg > 75)
sync_reg = 0xC0;
if (sync_msg > 87)
sync_reg = 0xE0;
if (sync_msg > 100) {
sync_reg = 0x00;
offset = 0x00;
}
if (currTar_Info->TarStatus & WIDE_ENABLED)
sync_reg |= offset;
else
sync_reg |= (offset | NARROW_SCSI);
FPT_sssyncv(port, currSCCB->TargID, sync_reg, currTar_Info);
if (currSCCB->Sccb_scsistat == SELECT_SN_ST) {
ACCEPT_MSG(port);
currTar_Info->TarStatus = ((currTar_Info->TarStatus &
~(unsigned char)TAR_SYNC_MASK) |
(unsigned char)SYNC_SUPPORTED);
WR_HARPOON(port + hp_autostart_1,
(AUTO_IMMED + DISCONNECT_START));
}
else {
ACCEPT_MSG_ATN(port);
FPT_sisyncr(port, sync_msg, offset);
currTar_Info->TarStatus = ((currTar_Info->TarStatus &
~(unsigned char)TAR_SYNC_MASK) |
(unsigned char)SYNC_SUPPORTED);
}
}
static void FPT_sisyncr(u32 port, unsigned char sync_pulse,
unsigned char offset)
{
ARAM_ACCESS(port);
WRW_HARPOON((port + SYNC_MSGS + 0), (MPM_OP + AMSG_OUT + SMEXT));
WRW_HARPOON((port + SYNC_MSGS + 2), (MPM_OP + AMSG_OUT + 0x03));
WRW_HARPOON((port + SYNC_MSGS + 4), (MPM_OP + AMSG_OUT + SMSYNC));
WRW_HARPOON((port + SYNC_MSGS + 6), (MPM_OP + AMSG_OUT + sync_pulse));
WRW_HARPOON((port + SYNC_MSGS + 8), (RAT_OP));
WRW_HARPOON((port + SYNC_MSGS + 10), (MPM_OP + AMSG_OUT + offset));
WRW_HARPOON((port + SYNC_MSGS + 12), (BRH_OP + ALWAYS + NP));
SGRAM_ACCESS(port);
WR_HARPOON(port + hp_portctrl_0, SCSI_PORT);
WRW_HARPOON((port + hp_intstat), CLR_ALL_INT_1);
WR_HARPOON(port + hp_autostart_3, (AUTO_IMMED + CMD_ONLY_STRT));
while (!(RDW_HARPOON((port + hp_intstat)) & (BUS_FREE | AUTO_INT))) {
}
}
static unsigned char FPT_siwidn(u32 port, unsigned char p_card)
{
struct sccb *currSCCB;
struct sccb_mgr_tar_info *currTar_Info;
currSCCB = FPT_BL_Card[p_card].currentSCCB;
currTar_Info = &FPT_sccbMgrTbl[p_card][currSCCB->TargID];
if (!((currTar_Info->TarStatus & TAR_WIDE_MASK) == WIDE_NEGOCIATED)) {
WRW_HARPOON((port + ID_MSG_STRT),
(MPM_OP + AMSG_OUT +
(currSCCB->
Sccb_idmsg & ~(unsigned char)DISC_PRIV)));
WRW_HARPOON((port + ID_MSG_STRT + 2), BRH_OP + ALWAYS + CMDPZ);
WRW_HARPOON((port + SYNC_MSGS + 0),
(MPM_OP + AMSG_OUT + SMEXT));
WRW_HARPOON((port + SYNC_MSGS + 2), (MPM_OP + AMSG_OUT + 0x02));
WRW_HARPOON((port + SYNC_MSGS + 4),
(MPM_OP + AMSG_OUT + SMWDTR));
WRW_HARPOON((port + SYNC_MSGS + 6), (RAT_OP));
WRW_HARPOON((port + SYNC_MSGS + 8),
(MPM_OP + AMSG_OUT + SM16BIT));
WRW_HARPOON((port + SYNC_MSGS + 10), (BRH_OP + ALWAYS + NP));
WR_HARPOON(port + hp_autostart_3, (SELECT + SELCHK_STRT));
currTar_Info->TarStatus = ((currTar_Info->TarStatus &
~(unsigned char)TAR_WIDE_MASK) |
(unsigned char)WIDE_ENABLED);
return 1;
}
else {
currTar_Info->TarStatus = ((currTar_Info->TarStatus &
~(unsigned char)TAR_WIDE_MASK) |
WIDE_NEGOCIATED);
currTar_Info->TarEEValue &= ~EE_WIDE_SCSI;
return 0;
}
}
static void FPT_stwidn(u32 port, unsigned char p_card)
{
unsigned char width;
struct sccb *currSCCB;
struct sccb_mgr_tar_info *currTar_Info;
currSCCB = FPT_BL_Card[p_card].currentSCCB;
currTar_Info = &FPT_sccbMgrTbl[p_card][currSCCB->TargID];
width = FPT_sfm(port, currSCCB);
if ((width == 0x00) && (currSCCB->Sccb_scsimsg == SMPARITY)) {
WR_HARPOON(port + hp_autostart_1,
(AUTO_IMMED + DISCONNECT_START));
return;
}
if (!(currTar_Info->TarEEValue & EE_WIDE_SCSI))
width = 0;
if (width) {
currTar_Info->TarStatus |= WIDE_ENABLED;
width = 0;
} else {
width = NARROW_SCSI;
currTar_Info->TarStatus &= ~WIDE_ENABLED;
}
FPT_sssyncv(port, currSCCB->TargID, width, currTar_Info);
if (currSCCB->Sccb_scsistat == SELECT_WN_ST) {
currTar_Info->TarStatus |= WIDE_NEGOCIATED;
if (!
((currTar_Info->TarStatus & TAR_SYNC_MASK) ==
SYNC_SUPPORTED)) {
ACCEPT_MSG_ATN(port);
ARAM_ACCESS(port);
FPT_sisyncn(port, p_card, 1);
currSCCB->Sccb_scsistat = SELECT_SN_ST;
SGRAM_ACCESS(port);
} else {
ACCEPT_MSG(port);
WR_HARPOON(port + hp_autostart_1,
(AUTO_IMMED + DISCONNECT_START));
}
}
else {
ACCEPT_MSG_ATN(port);
if (currTar_Info->TarEEValue & EE_WIDE_SCSI)
width = SM16BIT;
else
width = SM8BIT;
FPT_siwidr(port, width);
currTar_Info->TarStatus |= (WIDE_NEGOCIATED | WIDE_ENABLED);
}
}
static void FPT_siwidr(u32 port, unsigned char width)
{
ARAM_ACCESS(port);
WRW_HARPOON((port + SYNC_MSGS + 0), (MPM_OP + AMSG_OUT + SMEXT));
WRW_HARPOON((port + SYNC_MSGS + 2), (MPM_OP + AMSG_OUT + 0x02));
WRW_HARPOON((port + SYNC_MSGS + 4), (MPM_OP + AMSG_OUT + SMWDTR));
WRW_HARPOON((port + SYNC_MSGS + 6), (RAT_OP));
WRW_HARPOON((port + SYNC_MSGS + 8), (MPM_OP + AMSG_OUT + width));
WRW_HARPOON((port + SYNC_MSGS + 10), (BRH_OP + ALWAYS + NP));
SGRAM_ACCESS(port);
WR_HARPOON(port + hp_portctrl_0, SCSI_PORT);
WRW_HARPOON((port + hp_intstat), CLR_ALL_INT_1);
WR_HARPOON(port + hp_autostart_3, (AUTO_IMMED + CMD_ONLY_STRT));
while (!(RDW_HARPOON((port + hp_intstat)) & (BUS_FREE | AUTO_INT))) {
}
}
static void FPT_sssyncv(u32 p_port, unsigned char p_id,
unsigned char p_sync_value,
struct sccb_mgr_tar_info *currTar_Info)
{
unsigned char index;
index = p_id;
switch (index) {
case 0:
index = 12;
break;
case 1:
index = 13;
break;
case 2:
index = 14;
break;
case 3:
index = 15;
break;
case 4:
index = 8;
break;
case 5:
index = 9;
break;
case 6:
index = 10;
break;
case 7:
index = 11;
break;
case 8:
index = 4;
break;
case 9:
index = 5;
break;
case 10:
index = 6;
break;
case 11:
index = 7;
break;
case 12:
index = 0;
break;
case 13:
index = 1;
break;
case 14:
index = 2;
break;
case 15:
index = 3;
}
WR_HARPOON(p_port + hp_synctarg_base + index, p_sync_value);
currTar_Info->TarSyncCtrl = p_sync_value;
}
static void FPT_sresb(u32 port, unsigned char p_card)
{
unsigned char scsiID, i;
struct sccb_mgr_tar_info *currTar_Info;
WR_HARPOON(port + hp_page_ctrl,
(RD_HARPOON(port + hp_page_ctrl) | G_INT_DISABLE));
WRW_HARPOON((port + hp_intstat), CLR_ALL_INT);
WR_HARPOON(port + hp_scsictrl_0, SCSI_RST);
scsiID = RD_HARPOON(port + hp_seltimeout);
WR_HARPOON(port + hp_seltimeout, TO_5ms);
WRW_HARPOON((port + hp_intstat), TIMEOUT);
WR_HARPOON(port + hp_portctrl_0, (SCSI_PORT | START_TO));
while (!(RDW_HARPOON((port + hp_intstat)) & TIMEOUT)) {
}
WR_HARPOON(port + hp_seltimeout, scsiID);
WR_HARPOON(port + hp_scsictrl_0, ENA_SCAM_SEL);
FPT_Wait(port, TO_5ms);
WRW_HARPOON((port + hp_intstat), CLR_ALL_INT);
WR_HARPOON(port + hp_int_mask, (RD_HARPOON(port + hp_int_mask) | 0x00));
for (scsiID = 0; scsiID < MAX_SCSI_TAR; scsiID++) {
currTar_Info = &FPT_sccbMgrTbl[p_card][scsiID];
if (currTar_Info->TarEEValue & EE_SYNC_MASK) {
currTar_Info->TarSyncCtrl = 0;
currTar_Info->TarStatus &= ~TAR_SYNC_MASK;
}
if (currTar_Info->TarEEValue & EE_WIDE_SCSI) {
currTar_Info->TarStatus &= ~TAR_WIDE_MASK;
}
FPT_sssyncv(port, scsiID, NARROW_SCSI, currTar_Info);
FPT_SccbMgrTableInitTarget(p_card, scsiID);
}
FPT_BL_Card[p_card].scanIndex = 0x00;
FPT_BL_Card[p_card].currentSCCB = NULL;
FPT_BL_Card[p_card].globalFlags &= ~(F_TAG_STARTED | F_HOST_XFER_ACT
| F_NEW_SCCB_CMD);
FPT_BL_Card[p_card].cmdCounter = 0x00;
FPT_BL_Card[p_card].discQCount = 0x00;
FPT_BL_Card[p_card].tagQ_Lst = 0x01;
for (i = 0; i < QUEUE_DEPTH; i++)
FPT_BL_Card[p_card].discQ_Tbl[i] = NULL;
WR_HARPOON(port + hp_page_ctrl,
(RD_HARPOON(port + hp_page_ctrl) & ~G_INT_DISABLE));
}
static void FPT_ssenss(struct sccb_card *pCurrCard)
{
unsigned char i;
struct sccb *currSCCB;
currSCCB = pCurrCard->currentSCCB;
currSCCB->Save_CdbLen = currSCCB->CdbLength;
for (i = 0; i < 6; i++) {
currSCCB->Save_Cdb[i] = currSCCB->Cdb[i];
}
currSCCB->CdbLength = SIX_BYTE_CMD;
currSCCB->Cdb[0] = SCSI_REQUEST_SENSE;
currSCCB->Cdb[1] = currSCCB->Cdb[1] & (unsigned char)0xE0;
currSCCB->Cdb[2] = 0x00;
currSCCB->Cdb[3] = 0x00;
currSCCB->Cdb[4] = currSCCB->RequestSenseLength;
currSCCB->Cdb[5] = 0x00;
currSCCB->Sccb_XferCnt = (u32)currSCCB->RequestSenseLength;
currSCCB->Sccb_ATC = 0x00;
currSCCB->Sccb_XferState |= F_AUTO_SENSE;
currSCCB->Sccb_XferState &= ~F_SG_XFER;
currSCCB->Sccb_idmsg = currSCCB->Sccb_idmsg & ~(unsigned char)DISC_PRIV;
currSCCB->ControlByte = 0x00;
currSCCB->Sccb_MGRFlags &= F_STATUSLOADED;
}
static void FPT_sxfrp(u32 p_port, unsigned char p_card)
{
unsigned char curr_phz;
DISABLE_AUTO(p_port);
if (FPT_BL_Card[p_card].globalFlags & F_HOST_XFER_ACT) {
FPT_hostDataXferAbort(p_port, p_card,
FPT_BL_Card[p_card].currentSCCB);
}
if (RDW_HARPOON((p_port + hp_intstat)) &
(BUS_FREE | XFER_CNT_0 | AUTO_INT))
return;
WR_HARPOON(p_port + hp_xfercnt_0, 0x00);
curr_phz = RD_HARPOON(p_port + hp_scsisig) & (unsigned char)S_SCSI_PHZ;
WRW_HARPOON((p_port + hp_intstat), XFER_CNT_0);
WR_HARPOON(p_port + hp_scsisig, curr_phz);
while (!(RDW_HARPOON((p_port + hp_intstat)) & (BUS_FREE | RESET)) &&
(curr_phz ==
(RD_HARPOON(p_port + hp_scsisig) & (unsigned char)S_SCSI_PHZ)))
{
if (curr_phz & (unsigned char)SCSI_IOBIT) {
WR_HARPOON(p_port + hp_portctrl_0,
(SCSI_PORT | HOST_PORT | SCSI_INBIT));
if (!(RD_HARPOON(p_port + hp_xferstat) & FIFO_EMPTY)) {
RD_HARPOON(p_port + hp_fifodata_0);
}
} else {
WR_HARPOON(p_port + hp_portctrl_0,
(SCSI_PORT | HOST_PORT | HOST_WRT));
if (RD_HARPOON(p_port + hp_xferstat) & FIFO_EMPTY) {
WR_HARPOON(p_port + hp_fifodata_0, 0xFA);
}
}
}
while (!(RDW_HARPOON((p_port + hp_intstat)) & (BUS_FREE | RESET))) {
if (RD_HARPOON(p_port + hp_scsisig) & SCSI_REQ)
break;
}
WR_HARPOON(p_port + hp_portctrl_0,
(SCSI_PORT | HOST_PORT | SCSI_INBIT));
while (!(RD_HARPOON(p_port + hp_xferstat) & FIFO_EMPTY)) {
RD_HARPOON(p_port + hp_fifodata_0);
}
if (!(RDW_HARPOON((p_port + hp_intstat)) & (BUS_FREE | RESET))) {
WR_HARPOON(p_port + hp_autostart_0,
(AUTO_IMMED + DISCONNECT_START));
while (!(RDW_HARPOON((p_port + hp_intstat)) & AUTO_INT)) {
}
if (RDW_HARPOON((p_port + hp_intstat)) &
(ICMD_COMP | ITAR_DISC))
while (!
(RDW_HARPOON((p_port + hp_intstat)) &
(BUS_FREE | RSEL))) ;
}
}
static void FPT_schkdd(u32 port, unsigned char p_card)
{
unsigned short TimeOutLoop;
unsigned char sPhase;
struct sccb *currSCCB;
currSCCB = FPT_BL_Card[p_card].currentSCCB;
if ((currSCCB->Sccb_scsistat != DATA_OUT_ST) &&
(currSCCB->Sccb_scsistat != DATA_IN_ST)) {
return;
}
if (currSCCB->Sccb_XferState & F_ODD_BALL_CNT) {
currSCCB->Sccb_ATC += (currSCCB->Sccb_XferCnt - 1);
currSCCB->Sccb_XferCnt = 1;
currSCCB->Sccb_XferState &= ~F_ODD_BALL_CNT;
WRW_HARPOON((port + hp_fiforead), (unsigned short)0x00);
WR_HARPOON(port + hp_xferstat, 0x00);
}
else {
currSCCB->Sccb_ATC += currSCCB->Sccb_XferCnt;
currSCCB->Sccb_XferCnt = 0;
}
if ((RDW_HARPOON((port + hp_intstat)) & PARITY) &&
(currSCCB->HostStatus == SCCB_COMPLETE)) {
currSCCB->HostStatus = SCCB_PARITY_ERR;
WRW_HARPOON((port + hp_intstat), PARITY);
}
FPT_hostDataXferAbort(port, p_card, currSCCB);
while (RD_HARPOON(port + hp_scsisig) & SCSI_ACK) {
}
TimeOutLoop = 0;
while (RD_HARPOON(port + hp_xferstat) & FIFO_EMPTY) {
if (RDW_HARPOON((port + hp_intstat)) & BUS_FREE) {
return;
}
if (RD_HARPOON(port + hp_offsetctr) & (unsigned char)0x1F) {
break;
}
if (RDW_HARPOON((port + hp_intstat)) & RESET) {
return;
}
if ((RD_HARPOON(port + hp_scsisig) & SCSI_REQ)
|| (TimeOutLoop++ > 0x3000))
break;
}
sPhase = RD_HARPOON(port + hp_scsisig) & (SCSI_BSY | S_SCSI_PHZ);
if ((!(RD_HARPOON(port + hp_xferstat) & FIFO_EMPTY)) ||
(RD_HARPOON(port + hp_offsetctr) & (unsigned char)0x1F) ||
(sPhase == (SCSI_BSY | S_DATAO_PH)) ||
(sPhase == (SCSI_BSY | S_DATAI_PH))) {
WR_HARPOON(port + hp_portctrl_0, SCSI_PORT);
if (!(currSCCB->Sccb_XferState & F_ALL_XFERRED)) {
if (currSCCB->Sccb_XferState & F_HOST_XFER_DIR) {
FPT_phaseDataIn(port, p_card);
}
else {
FPT_phaseDataOut(port, p_card);
}
} else {
FPT_sxfrp(port, p_card);
if (!(RDW_HARPOON((port + hp_intstat)) &
(BUS_FREE | ICMD_COMP | ITAR_DISC | RESET))) {
WRW_HARPOON((port + hp_intstat), AUTO_INT);
FPT_phaseDecode(port, p_card);
}
}
}
else {
WR_HARPOON(port + hp_portctrl_0, 0x00);
}
}
static void FPT_sinits(struct sccb *p_sccb, unsigned char p_card)
{
struct sccb_mgr_tar_info *currTar_Info;
if ((p_sccb->TargID >= MAX_SCSI_TAR) || (p_sccb->Lun >= MAX_LUN)) {
return;
}
currTar_Info = &FPT_sccbMgrTbl[p_card][p_sccb->TargID];
p_sccb->Sccb_XferState = 0x00;
p_sccb->Sccb_XferCnt = p_sccb->DataLength;
if ((p_sccb->OperationCode == SCATTER_GATHER_COMMAND) ||
(p_sccb->OperationCode == RESIDUAL_SG_COMMAND)) {
p_sccb->Sccb_SGoffset = 0;
p_sccb->Sccb_XferState = F_SG_XFER;
p_sccb->Sccb_XferCnt = 0x00;
}
if (p_sccb->DataLength == 0x00)
p_sccb->Sccb_XferState |= F_ALL_XFERRED;
if (p_sccb->ControlByte & F_USE_CMD_Q) {
if ((currTar_Info->TarStatus & TAR_TAG_Q_MASK) == TAG_Q_REJECT)
p_sccb->ControlByte &= ~F_USE_CMD_Q;
else
currTar_Info->TarStatus |= TAG_Q_TRYING;
}
if ((currTar_Info->TarStatus & TAR_ALLOW_DISC) ||
(currTar_Info->TarStatus & TAG_Q_TRYING)) {
p_sccb->Sccb_idmsg =
(unsigned char)(SMIDENT | DISC_PRIV) | p_sccb->Lun;
}
else {
p_sccb->Sccb_idmsg = (unsigned char)SMIDENT | p_sccb->Lun;
}
p_sccb->HostStatus = 0x00;
p_sccb->TargetStatus = 0x00;
p_sccb->Sccb_tag = 0x00;
p_sccb->Sccb_MGRFlags = 0x00;
p_sccb->Sccb_sgseg = 0x00;
p_sccb->Sccb_ATC = 0x00;
p_sccb->Sccb_savedATC = 0x00;
p_sccb->Sccb_scsistat = BUS_FREE_ST;
p_sccb->SccbStatus = SCCB_IN_PROCESS;
p_sccb->Sccb_scsimsg = SMNO_OP;
}
static void FPT_phaseDecode(u32 p_port, unsigned char p_card)
{
unsigned char phase_ref;
void (*phase) (u32, unsigned char);
DISABLE_AUTO(p_port);
phase_ref =
(unsigned char)(RD_HARPOON(p_port + hp_scsisig) & S_SCSI_PHZ);
phase = FPT_s_PhaseTbl[phase_ref];
(*phase) (p_port, p_card);
}
static void FPT_phaseDataOut(u32 port, unsigned char p_card)
{
struct sccb *currSCCB;
currSCCB = FPT_BL_Card[p_card].currentSCCB;
if (currSCCB == NULL) {
return;
}
currSCCB->Sccb_scsistat = DATA_OUT_ST;
currSCCB->Sccb_XferState &= ~(F_HOST_XFER_DIR | F_NO_DATA_YET);
WR_HARPOON(port + hp_portctrl_0, SCSI_PORT);
WRW_HARPOON((port + hp_intstat), XFER_CNT_0);
WR_HARPOON(port + hp_autostart_0, (END_DATA + END_DATA_START));
FPT_dataXferProcessor(port, &FPT_BL_Card[p_card]);
if (currSCCB->Sccb_XferCnt == 0) {
if ((currSCCB->ControlByte & SCCB_DATA_XFER_OUT) &&
(currSCCB->HostStatus == SCCB_COMPLETE))
currSCCB->HostStatus = SCCB_DATA_OVER_RUN;
FPT_sxfrp(port, p_card);
if (!(RDW_HARPOON((port + hp_intstat)) & (BUS_FREE | RESET)))
FPT_phaseDecode(port, p_card);
}
}
static void FPT_phaseDataIn(u32 port, unsigned char p_card)
{
struct sccb *currSCCB;
currSCCB = FPT_BL_Card[p_card].currentSCCB;
if (currSCCB == NULL) {
return;
}
currSCCB->Sccb_scsistat = DATA_IN_ST;
currSCCB->Sccb_XferState |= F_HOST_XFER_DIR;
currSCCB->Sccb_XferState &= ~F_NO_DATA_YET;
WR_HARPOON(port + hp_portctrl_0, SCSI_PORT);
WRW_HARPOON((port + hp_intstat), XFER_CNT_0);
WR_HARPOON(port + hp_autostart_0, (END_DATA + END_DATA_START));
FPT_dataXferProcessor(port, &FPT_BL_Card[p_card]);
if (currSCCB->Sccb_XferCnt == 0) {
if ((currSCCB->ControlByte & SCCB_DATA_XFER_IN) &&
(currSCCB->HostStatus == SCCB_COMPLETE))
currSCCB->HostStatus = SCCB_DATA_OVER_RUN;
FPT_sxfrp(port, p_card);
if (!(RDW_HARPOON((port + hp_intstat)) & (BUS_FREE | RESET)))
FPT_phaseDecode(port, p_card);
}
}
static void FPT_phaseCommand(u32 p_port, unsigned char p_card)
{
struct sccb *currSCCB;
u32 cdb_reg;
unsigned char i;
currSCCB = FPT_BL_Card[p_card].currentSCCB;
if (currSCCB->OperationCode == RESET_COMMAND) {
currSCCB->HostStatus = SCCB_PHASE_SEQUENCE_FAIL;
currSCCB->CdbLength = SIX_BYTE_CMD;
}
WR_HARPOON(p_port + hp_scsisig, 0x00);
ARAM_ACCESS(p_port);
cdb_reg = p_port + CMD_STRT;
for (i = 0; i < currSCCB->CdbLength; i++) {
if (currSCCB->OperationCode == RESET_COMMAND)
WRW_HARPOON(cdb_reg, (MPM_OP + ACOMMAND + 0x00));
else
WRW_HARPOON(cdb_reg,
(MPM_OP + ACOMMAND + currSCCB->Cdb[i]));
cdb_reg += 2;
}
if (currSCCB->CdbLength != TWELVE_BYTE_CMD)
WRW_HARPOON(cdb_reg, (BRH_OP + ALWAYS + NP));
WR_HARPOON(p_port + hp_portctrl_0, (SCSI_PORT));
currSCCB->Sccb_scsistat = COMMAND_ST;
WR_HARPOON(p_port + hp_autostart_3, (AUTO_IMMED | CMD_ONLY_STRT));
SGRAM_ACCESS(p_port);
}
static void FPT_phaseStatus(u32 port, unsigned char p_card)
{
WR_HARPOON(port + hp_scsisig, 0x00);
WR_HARPOON(port + hp_autostart_0, (AUTO_IMMED + END_DATA_START));
}
static void FPT_phaseMsgOut(u32 port, unsigned char p_card)
{
unsigned char message, scsiID;
struct sccb *currSCCB;
struct sccb_mgr_tar_info *currTar_Info;
currSCCB = FPT_BL_Card[p_card].currentSCCB;
if (currSCCB != NULL) {
message = currSCCB->Sccb_scsimsg;
scsiID = currSCCB->TargID;
if (message == SMDEV_RESET) {
currTar_Info = &FPT_sccbMgrTbl[p_card][scsiID];
currTar_Info->TarSyncCtrl = 0;
FPT_sssyncv(port, scsiID, NARROW_SCSI, currTar_Info);
if (FPT_sccbMgrTbl[p_card][scsiID].
TarEEValue & EE_SYNC_MASK) {
FPT_sccbMgrTbl[p_card][scsiID].TarStatus &=
~TAR_SYNC_MASK;
}
if (FPT_sccbMgrTbl[p_card][scsiID].
TarEEValue & EE_WIDE_SCSI) {
FPT_sccbMgrTbl[p_card][scsiID].TarStatus &=
~TAR_WIDE_MASK;
}
FPT_queueFlushSccb(p_card, SCCB_COMPLETE);
FPT_SccbMgrTableInitTarget(p_card, scsiID);
} else if (currSCCB->Sccb_scsistat == ABORT_ST) {
currSCCB->HostStatus = SCCB_COMPLETE;
if (FPT_BL_Card[p_card].discQ_Tbl[currSCCB->Sccb_tag] !=
NULL) {
FPT_BL_Card[p_card].discQ_Tbl[currSCCB->
Sccb_tag] = NULL;
FPT_sccbMgrTbl[p_card][scsiID].TarTagQ_Cnt--;
}
}
else if (currSCCB->Sccb_scsistat < COMMAND_ST) {
if (message == SMNO_OP) {
currSCCB->Sccb_MGRFlags |= F_DEV_SELECTED;
FPT_ssel(port, p_card);
return;
}
} else {
if (message == SMABORT)
FPT_queueFlushSccb(p_card, SCCB_COMPLETE);
}
} else {
message = SMABORT;
}
WRW_HARPOON((port + hp_intstat), (BUS_FREE | PHASE | XFER_CNT_0));
WR_HARPOON(port + hp_portctrl_0, SCSI_BUS_EN);
WR_HARPOON(port + hp_scsidata_0, message);
WR_HARPOON(port + hp_scsisig, (SCSI_ACK + S_ILL_PH));
ACCEPT_MSG(port);
WR_HARPOON(port + hp_portctrl_0, 0x00);
if ((message == SMABORT) || (message == SMDEV_RESET) ||
(message == SMABORT_TAG)) {
while (!(RDW_HARPOON((port + hp_intstat)) & (BUS_FREE | PHASE))) {
}
if (RDW_HARPOON((port + hp_intstat)) & BUS_FREE) {
WRW_HARPOON((port + hp_intstat), BUS_FREE);
if (currSCCB != NULL) {
if ((FPT_BL_Card[p_card].
globalFlags & F_CONLUN_IO)
&&
((FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarStatus & TAR_TAG_Q_MASK) !=
TAG_Q_TRYING))
FPT_sccbMgrTbl[p_card][currSCCB->
TargID].
TarLUNBusy[currSCCB->Lun] = 0;
else
FPT_sccbMgrTbl[p_card][currSCCB->
TargID].
TarLUNBusy[0] = 0;
FPT_queueCmdComplete(&FPT_BL_Card[p_card],
currSCCB, p_card);
}
else {
FPT_BL_Card[p_card].globalFlags |=
F_NEW_SCCB_CMD;
}
}
else {
FPT_sxfrp(port, p_card);
}
}
else {
if (message == SMPARITY) {
currSCCB->Sccb_scsimsg = SMNO_OP;
WR_HARPOON(port + hp_autostart_1,
(AUTO_IMMED + DISCONNECT_START));
} else {
FPT_sxfrp(port, p_card);
}
}
}
static void FPT_phaseMsgIn(u32 port, unsigned char p_card)
{
unsigned char message;
struct sccb *currSCCB;
currSCCB = FPT_BL_Card[p_card].currentSCCB;
if (FPT_BL_Card[p_card].globalFlags & F_HOST_XFER_ACT) {
FPT_phaseChkFifo(port, p_card);
}
message = RD_HARPOON(port + hp_scsidata_0);
if ((message == SMDISC) || (message == SMSAVE_DATA_PTR)) {
WR_HARPOON(port + hp_autostart_1,
(AUTO_IMMED + END_DATA_START));
}
else {
message = FPT_sfm(port, currSCCB);
if (message) {
FPT_sdecm(message, port, p_card);
} else {
if (currSCCB->Sccb_scsimsg != SMPARITY)
ACCEPT_MSG(port);
WR_HARPOON(port + hp_autostart_1,
(AUTO_IMMED + DISCONNECT_START));
}
}
}
static void FPT_phaseIllegal(u32 port, unsigned char p_card)
{
struct sccb *currSCCB;
currSCCB = FPT_BL_Card[p_card].currentSCCB;
WR_HARPOON(port + hp_scsisig, RD_HARPOON(port + hp_scsisig));
if (currSCCB != NULL) {
currSCCB->HostStatus = SCCB_PHASE_SEQUENCE_FAIL;
currSCCB->Sccb_scsistat = ABORT_ST;
currSCCB->Sccb_scsimsg = SMABORT;
}
ACCEPT_MSG_ATN(port);
}
static void FPT_phaseChkFifo(u32 port, unsigned char p_card)
{
u32 xfercnt;
struct sccb *currSCCB;
currSCCB = FPT_BL_Card[p_card].currentSCCB;
if (currSCCB->Sccb_scsistat == DATA_IN_ST) {
while ((!(RD_HARPOON(port + hp_xferstat) & FIFO_EMPTY)) &&
(RD_HARPOON(port + hp_ext_status) & BM_CMD_BUSY)) {
}
if (!(RD_HARPOON(port + hp_xferstat) & FIFO_EMPTY)) {
currSCCB->Sccb_ATC += currSCCB->Sccb_XferCnt;
currSCCB->Sccb_XferCnt = 0;
if ((RDW_HARPOON((port + hp_intstat)) & PARITY) &&
(currSCCB->HostStatus == SCCB_COMPLETE)) {
currSCCB->HostStatus = SCCB_PARITY_ERR;
WRW_HARPOON((port + hp_intstat), PARITY);
}
FPT_hostDataXferAbort(port, p_card, currSCCB);
FPT_dataXferProcessor(port, &FPT_BL_Card[p_card]);
while ((!(RD_HARPOON(port + hp_xferstat) & FIFO_EMPTY))
&& (RD_HARPOON(port + hp_ext_status) &
BM_CMD_BUSY)) {
}
}
}
GET_XFER_CNT(port, xfercnt);
WR_HARPOON(port + hp_xfercnt_0, 0x00);
WR_HARPOON(port + hp_portctrl_0, 0x00);
currSCCB->Sccb_ATC += (currSCCB->Sccb_XferCnt - xfercnt);
currSCCB->Sccb_XferCnt = xfercnt;
if ((RDW_HARPOON((port + hp_intstat)) & PARITY) &&
(currSCCB->HostStatus == SCCB_COMPLETE)) {
currSCCB->HostStatus = SCCB_PARITY_ERR;
WRW_HARPOON((port + hp_intstat), PARITY);
}
FPT_hostDataXferAbort(port, p_card, currSCCB);
WR_HARPOON(port + hp_fifowrite, 0x00);
WR_HARPOON(port + hp_fiforead, 0x00);
WR_HARPOON(port + hp_xferstat, 0x00);
WRW_HARPOON((port + hp_intstat), XFER_CNT_0);
}
static void FPT_phaseBusFree(u32 port, unsigned char p_card)
{
struct sccb *currSCCB;
currSCCB = FPT_BL_Card[p_card].currentSCCB;
if (currSCCB != NULL) {
DISABLE_AUTO(port);
if (currSCCB->OperationCode == RESET_COMMAND) {
if ((FPT_BL_Card[p_card].globalFlags & F_CONLUN_IO) &&
((FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarStatus & TAR_TAG_Q_MASK) != TAG_Q_TRYING))
FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarLUNBusy[currSCCB->Lun] = 0;
else
FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarLUNBusy[0] = 0;
FPT_queueCmdComplete(&FPT_BL_Card[p_card], currSCCB,
p_card);
FPT_queueSearchSelect(&FPT_BL_Card[p_card], p_card);
}
else if (currSCCB->Sccb_scsistat == SELECT_SN_ST) {
FPT_sccbMgrTbl[p_card][currSCCB->TargID].TarStatus |=
(unsigned char)SYNC_SUPPORTED;
FPT_sccbMgrTbl[p_card][currSCCB->TargID].TarEEValue &=
~EE_SYNC_MASK;
}
else if (currSCCB->Sccb_scsistat == SELECT_WN_ST) {
FPT_sccbMgrTbl[p_card][currSCCB->TargID].TarStatus =
(FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarStatus & ~WIDE_ENABLED) | WIDE_NEGOCIATED;
FPT_sccbMgrTbl[p_card][currSCCB->TargID].TarEEValue &=
~EE_WIDE_SCSI;
}
else if (currSCCB->Sccb_scsistat == SELECT_Q_ST) {
if ((!(RD_HARPOON(port + hp_scsisig) & SCSI_BSY)) ||
(RDW_HARPOON((port + hp_intstat)) & RSEL)) {
FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarStatus &= ~TAR_TAG_Q_MASK;
FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarStatus |= TAG_Q_REJECT;
}
else {
return;
}
}
else {
currSCCB->Sccb_scsistat = BUS_FREE_ST;
if (!currSCCB->HostStatus) {
currSCCB->HostStatus = SCCB_PHASE_SEQUENCE_FAIL;
}
if ((FPT_BL_Card[p_card].globalFlags & F_CONLUN_IO) &&
((FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarStatus & TAR_TAG_Q_MASK) != TAG_Q_TRYING))
FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarLUNBusy[currSCCB->Lun] = 0;
else
FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarLUNBusy[0] = 0;
FPT_queueCmdComplete(&FPT_BL_Card[p_card], currSCCB,
p_card);
return;
}
FPT_BL_Card[p_card].globalFlags |= F_NEW_SCCB_CMD;
}
}
static void FPT_autoLoadDefaultMap(u32 p_port)
{
u32 map_addr;
ARAM_ACCESS(p_port);
map_addr = p_port + hp_aramBase;
WRW_HARPOON(map_addr, (MPM_OP + AMSG_OUT + 0xC0));
map_addr += 2;
WRW_HARPOON(map_addr, (MPM_OP + AMSG_OUT + 0x20));
map_addr += 2;
WRW_HARPOON(map_addr, RAT_OP);
map_addr += 2;
WRW_HARPOON(map_addr, (MPM_OP + AMSG_OUT + 0x00));
map_addr += 2;
WRW_HARPOON(map_addr, (MPM_OP + ACOMMAND + 0x00));
map_addr += 2;
WRW_HARPOON(map_addr, (MPM_OP + ACOMMAND + 0x00));
map_addr += 2;
WRW_HARPOON(map_addr, (MPM_OP + ACOMMAND + 0x00));
map_addr += 2;
WRW_HARPOON(map_addr, (MPM_OP + ACOMMAND + 0x00));
map_addr += 2;
WRW_HARPOON(map_addr, (MPM_OP + ACOMMAND + 0x00));
map_addr += 2;
WRW_HARPOON(map_addr, (MPM_OP + ACOMMAND + 0x00));
map_addr += 2;
WRW_HARPOON(map_addr, (MPM_OP + ACOMMAND + 0x00));
map_addr += 2;
WRW_HARPOON(map_addr, (MPM_OP + ACOMMAND + 0x00));
map_addr += 2;
WRW_HARPOON(map_addr, (MPM_OP + ACOMMAND + 0x00));
map_addr += 2;
WRW_HARPOON(map_addr, (MPM_OP + ACOMMAND + 0x00));
map_addr += 2;
WRW_HARPOON(map_addr, (MPM_OP + ACOMMAND + 0x00));
map_addr += 2;
WRW_HARPOON(map_addr, (MPM_OP + ACOMMAND + 0x00));
map_addr += 2;
WRW_HARPOON(map_addr, (CPE_OP + ADATA_OUT + DINT));
map_addr += 2;
WRW_HARPOON(map_addr, (TCB_OP + FIFO_0 + DI));
map_addr += 2;
WRW_HARPOON(map_addr, (SSI_OP + SSI_IDO_STRT));
map_addr += 2;
WRW_HARPOON(map_addr, (CPE_OP + ADATA_IN + DINT));
map_addr += 2;
WRW_HARPOON(map_addr, (CPN_OP + AMSG_IN + ST));
map_addr += 2;
WRW_HARPOON(map_addr, (CRD_OP + SDATA + 0x02));
map_addr += 2;
WRW_HARPOON(map_addr, (BRH_OP + NOT_EQ + DC));
map_addr += 2;
WRW_HARPOON(map_addr, (MRR_OP + SDATA + D_AR1));
map_addr += 2;
WRW_HARPOON(map_addr, (CPN_OP + AMSG_IN + ST));
map_addr += 2;
WRW_HARPOON(map_addr, (CRD_OP + SDATA + 0x04));
map_addr += 2;
WRW_HARPOON(map_addr, (BRH_OP + NOT_EQ + UNKNWN));
map_addr += 2;
WRW_HARPOON(map_addr, (MRR_OP + SDATA + D_BUCKET));
map_addr += 2;
WRW_HARPOON(map_addr, (SSI_OP + SSI_ITAR_DISC));
map_addr += 2;
WRW_HARPOON(map_addr, (CPN_OP + ASTATUS + UNKNWN));
map_addr += 2;
WRW_HARPOON(map_addr, (MRR_OP + SDATA + D_AR0));
map_addr += 2;
WRW_HARPOON(map_addr, (CPN_OP + AMSG_IN + CC));
map_addr += 2;
WRW_HARPOON(map_addr, (CRD_OP + SDATA + 0x00));
map_addr += 2;
WRW_HARPOON(map_addr, (BRH_OP + NOT_EQ + CC));
map_addr += 2;
WRW_HARPOON(map_addr, (MRR_OP + SDATA + D_BUCKET));
map_addr += 2;
WRW_HARPOON(map_addr, (SSI_OP + SSI_ICMD_COMP));
map_addr += 2;
WRW_HARPOON(map_addr, (SSI_OP + SSI_IUNKWN));
map_addr += 2;
WRW_HARPOON(map_addr, (SSI_OP + SSI_INO_CC));
map_addr += 2;
WRW_HARPOON(map_addr, (SSI_OP + SSI_ITICKLE));
map_addr += 2;
WRW_HARPOON(map_addr, (SSI_OP + SSI_IRFAIL));
map_addr += 2;
WRW_HARPOON(map_addr, (CRR_OP + AR3 + S_IDREG));
map_addr += 2;
WRW_HARPOON(map_addr, (BRH_OP + EQUAL + 0x00));
map_addr += 2;
WRW_HARPOON(map_addr, (SSI_OP + SSI_INO_CC));
SGRAM_ACCESS(p_port);
}
static void FPT_autoCmdCmplt(u32 p_port, unsigned char p_card)
{
struct sccb *currSCCB;
unsigned char status_byte;
currSCCB = FPT_BL_Card[p_card].currentSCCB;
status_byte = RD_HARPOON(p_port + hp_gp_reg_0);
FPT_sccbMgrTbl[p_card][currSCCB->TargID].TarLUN_CA = 0;
if (status_byte != SSGOOD) {
if (status_byte == SSQ_FULL) {
if (((FPT_BL_Card[p_card].globalFlags & F_CONLUN_IO) &&
((FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarStatus & TAR_TAG_Q_MASK) != TAG_Q_TRYING))) {
FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarLUNBusy[currSCCB->Lun] = 1;
if (FPT_BL_Card[p_card].discQCount != 0)
FPT_BL_Card[p_card].discQCount--;
FPT_BL_Card[p_card].
discQ_Tbl[FPT_sccbMgrTbl[p_card]
[currSCCB->TargID].
LunDiscQ_Idx[currSCCB->Lun]] =
NULL;
} else {
FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarLUNBusy[0] = 1;
if (currSCCB->Sccb_tag) {
if (FPT_BL_Card[p_card].discQCount != 0)
FPT_BL_Card[p_card].
discQCount--;
FPT_BL_Card[p_card].discQ_Tbl[currSCCB->
Sccb_tag]
= NULL;
} else {
if (FPT_BL_Card[p_card].discQCount != 0)
FPT_BL_Card[p_card].
discQCount--;
FPT_BL_Card[p_card].
discQ_Tbl[FPT_sccbMgrTbl[p_card]
[currSCCB->TargID].
LunDiscQ_Idx[0]] = NULL;
}
}
currSCCB->Sccb_MGRFlags |= F_STATUSLOADED;
FPT_queueSelectFail(&FPT_BL_Card[p_card], p_card);
return;
}
if (currSCCB->Sccb_scsistat == SELECT_SN_ST) {
FPT_sccbMgrTbl[p_card][currSCCB->TargID].TarStatus |=
(unsigned char)SYNC_SUPPORTED;
FPT_sccbMgrTbl[p_card][currSCCB->TargID].TarEEValue &=
~EE_SYNC_MASK;
FPT_BL_Card[p_card].globalFlags |= F_NEW_SCCB_CMD;
if (((FPT_BL_Card[p_card].globalFlags & F_CONLUN_IO) &&
((FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarStatus & TAR_TAG_Q_MASK) != TAG_Q_TRYING))) {
FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarLUNBusy[currSCCB->Lun] = 1;
if (FPT_BL_Card[p_card].discQCount != 0)
FPT_BL_Card[p_card].discQCount--;
FPT_BL_Card[p_card].
discQ_Tbl[FPT_sccbMgrTbl[p_card]
[currSCCB->TargID].
LunDiscQ_Idx[currSCCB->Lun]] =
NULL;
} else {
FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarLUNBusy[0] = 1;
if (currSCCB->Sccb_tag) {
if (FPT_BL_Card[p_card].discQCount != 0)
FPT_BL_Card[p_card].
discQCount--;
FPT_BL_Card[p_card].discQ_Tbl[currSCCB->
Sccb_tag]
= NULL;
} else {
if (FPT_BL_Card[p_card].discQCount != 0)
FPT_BL_Card[p_card].
discQCount--;
FPT_BL_Card[p_card].
discQ_Tbl[FPT_sccbMgrTbl[p_card]
[currSCCB->TargID].
LunDiscQ_Idx[0]] = NULL;
}
}
return;
}
if (currSCCB->Sccb_scsistat == SELECT_WN_ST) {
FPT_sccbMgrTbl[p_card][currSCCB->TargID].TarStatus =
(FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarStatus & ~WIDE_ENABLED) | WIDE_NEGOCIATED;
FPT_sccbMgrTbl[p_card][currSCCB->TargID].TarEEValue &=
~EE_WIDE_SCSI;
FPT_BL_Card[p_card].globalFlags |= F_NEW_SCCB_CMD;
if (((FPT_BL_Card[p_card].globalFlags & F_CONLUN_IO) &&
((FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarStatus & TAR_TAG_Q_MASK) != TAG_Q_TRYING))) {
FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarLUNBusy[currSCCB->Lun] = 1;
if (FPT_BL_Card[p_card].discQCount != 0)
FPT_BL_Card[p_card].discQCount--;
FPT_BL_Card[p_card].
discQ_Tbl[FPT_sccbMgrTbl[p_card]
[currSCCB->TargID].
LunDiscQ_Idx[currSCCB->Lun]] =
NULL;
} else {
FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarLUNBusy[0] = 1;
if (currSCCB->Sccb_tag) {
if (FPT_BL_Card[p_card].discQCount != 0)
FPT_BL_Card[p_card].
discQCount--;
FPT_BL_Card[p_card].discQ_Tbl[currSCCB->
Sccb_tag]
= NULL;
} else {
if (FPT_BL_Card[p_card].discQCount != 0)
FPT_BL_Card[p_card].
discQCount--;
FPT_BL_Card[p_card].
discQ_Tbl[FPT_sccbMgrTbl[p_card]
[currSCCB->TargID].
LunDiscQ_Idx[0]] = NULL;
}
}
return;
}
if (status_byte == SSCHECK) {
if (FPT_BL_Card[p_card].globalFlags & F_DO_RENEGO) {
if (FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarEEValue & EE_SYNC_MASK) {
FPT_sccbMgrTbl[p_card][currSCCB->
TargID].
TarStatus &= ~TAR_SYNC_MASK;
}
if (FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarEEValue & EE_WIDE_SCSI) {
FPT_sccbMgrTbl[p_card][currSCCB->
TargID].
TarStatus &= ~TAR_WIDE_MASK;
}
}
}
if (!(currSCCB->Sccb_XferState & F_AUTO_SENSE)) {
currSCCB->SccbStatus = SCCB_ERROR;
currSCCB->TargetStatus = status_byte;
if (status_byte == SSCHECK) {
FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarLUN_CA = 1;
if (currSCCB->RequestSenseLength !=
NO_AUTO_REQUEST_SENSE) {
if (currSCCB->RequestSenseLength == 0)
currSCCB->RequestSenseLength =
14;
FPT_ssenss(&FPT_BL_Card[p_card]);
FPT_BL_Card[p_card].globalFlags |=
F_NEW_SCCB_CMD;
if (((FPT_BL_Card[p_card].
globalFlags & F_CONLUN_IO)
&&
((FPT_sccbMgrTbl[p_card]
[currSCCB->TargID].
TarStatus & TAR_TAG_Q_MASK) !=
TAG_Q_TRYING))) {
FPT_sccbMgrTbl[p_card]
[currSCCB->TargID].
TarLUNBusy[currSCCB->Lun] =
1;
if (FPT_BL_Card[p_card].
discQCount != 0)
FPT_BL_Card[p_card].
discQCount--;
FPT_BL_Card[p_card].
discQ_Tbl[FPT_sccbMgrTbl
[p_card]
[currSCCB->
TargID].
LunDiscQ_Idx
[currSCCB->Lun]] =
NULL;
} else {
FPT_sccbMgrTbl[p_card]
[currSCCB->TargID].
TarLUNBusy[0] = 1;
if (currSCCB->Sccb_tag) {
if (FPT_BL_Card[p_card].
discQCount != 0)
FPT_BL_Card
[p_card].
discQCount--;
FPT_BL_Card[p_card].
discQ_Tbl[currSCCB->
Sccb_tag]
= NULL;
} else {
if (FPT_BL_Card[p_card].
discQCount != 0)
FPT_BL_Card
[p_card].
discQCount--;
FPT_BL_Card[p_card].
discQ_Tbl
[FPT_sccbMgrTbl
[p_card][currSCCB->
TargID].
LunDiscQ_Idx[0]] =
NULL;
}
}
return;
}
}
}
}
if ((FPT_BL_Card[p_card].globalFlags & F_CONLUN_IO) &&
((FPT_sccbMgrTbl[p_card][currSCCB->TargID].
TarStatus & TAR_TAG_Q_MASK) != TAG_Q_TRYING))
FPT_sccbMgrTbl[p_card][currSCCB->TargID].TarLUNBusy[currSCCB->
Lun] = 0;
else
FPT_sccbMgrTbl[p_card][currSCCB->TargID].TarLUNBusy[0] = 0;
FPT_queueCmdComplete(&FPT_BL_Card[p_card], currSCCB, p_card);
}
static void FPT_dataXferProcessor(u32 port, struct sccb_card *pCurrCard)
{
struct sccb *currSCCB;
currSCCB = pCurrCard->currentSCCB;
if (currSCCB->Sccb_XferState & F_SG_XFER) {
if (pCurrCard->globalFlags & F_HOST_XFER_ACT)
{
currSCCB->Sccb_sgseg += (unsigned char)SG_BUF_CNT;
currSCCB->Sccb_SGoffset = 0x00;
}
pCurrCard->globalFlags |= F_HOST_XFER_ACT;
FPT_busMstrSGDataXferStart(port, currSCCB);
}
else {
if (!(pCurrCard->globalFlags & F_HOST_XFER_ACT)) {
pCurrCard->globalFlags |= F_HOST_XFER_ACT;
FPT_busMstrDataXferStart(port, currSCCB);
}
}
}
static void FPT_busMstrSGDataXferStart(u32 p_port, struct sccb *pcurrSCCB)
{
u32 count, addr, tmpSGCnt;
unsigned int sg_index;
unsigned char sg_count, i;
u32 reg_offset;
struct blogic_sg_seg *segp;
if (pcurrSCCB->Sccb_XferState & F_HOST_XFER_DIR)
count = ((u32)HOST_RD_CMD) << 24;
else
count = ((u32)HOST_WRT_CMD) << 24;
sg_count = 0;
tmpSGCnt = 0;
sg_index = pcurrSCCB->Sccb_sgseg;
reg_offset = hp_aramBase;
i = (unsigned char)(RD_HARPOON(p_port + hp_page_ctrl) &
~(SGRAM_ARAM | SCATTER_EN));
WR_HARPOON(p_port + hp_page_ctrl, i);
while ((sg_count < (unsigned char)SG_BUF_CNT) &&
((sg_index * (unsigned int)SG_ELEMENT_SIZE) <
pcurrSCCB->DataLength)) {
segp = (struct blogic_sg_seg *)(pcurrSCCB->DataPointer) +
sg_index;
tmpSGCnt += segp->segbytes;
count |= segp->segbytes;
addr = segp->segdata;
if ((!sg_count) && (pcurrSCCB->Sccb_SGoffset)) {
addr +=
((count & 0x00FFFFFFL) - pcurrSCCB->Sccb_SGoffset);
count =
(count & 0xFF000000L) | pcurrSCCB->Sccb_SGoffset;
tmpSGCnt = count & 0x00FFFFFFL;
}
WR_HARP32(p_port, reg_offset, addr);
reg_offset += 4;
WR_HARP32(p_port, reg_offset, count);
reg_offset += 4;
count &= 0xFF000000L;
sg_index++;
sg_count++;
}
pcurrSCCB->Sccb_XferCnt = tmpSGCnt;
WR_HARPOON(p_port + hp_sg_addr, (sg_count << 4));
if (pcurrSCCB->Sccb_XferState & F_HOST_XFER_DIR) {
WR_HARP32(p_port, hp_xfercnt_0, tmpSGCnt);
WR_HARPOON(p_port + hp_portctrl_0,
(DMA_PORT | SCSI_PORT | SCSI_INBIT));
WR_HARPOON(p_port + hp_scsisig, S_DATAI_PH);
}
else {
if ((!(RD_HARPOON(p_port + hp_synctarg_0) & NARROW_SCSI)) &&
(tmpSGCnt & 0x000000001)) {
pcurrSCCB->Sccb_XferState |= F_ODD_BALL_CNT;
tmpSGCnt--;
}
WR_HARP32(p_port, hp_xfercnt_0, tmpSGCnt);
WR_HARPOON(p_port + hp_portctrl_0,
(SCSI_PORT | DMA_PORT | DMA_RD));
WR_HARPOON(p_port + hp_scsisig, S_DATAO_PH);
}
WR_HARPOON(p_port + hp_page_ctrl, (unsigned char)(i | SCATTER_EN));
}
static void FPT_busMstrDataXferStart(u32 p_port, struct sccb *pcurrSCCB)
{
u32 addr, count;
if (!(pcurrSCCB->Sccb_XferState & F_AUTO_SENSE)) {
count = pcurrSCCB->Sccb_XferCnt;
addr = (u32)(unsigned long)pcurrSCCB->DataPointer + pcurrSCCB->Sccb_ATC;
}
else {
addr = pcurrSCCB->SensePointer;
count = pcurrSCCB->RequestSenseLength;
}
HP_SETUP_ADDR_CNT(p_port, addr, count);
if (pcurrSCCB->Sccb_XferState & F_HOST_XFER_DIR) {
WR_HARPOON(p_port + hp_portctrl_0,
(DMA_PORT | SCSI_PORT | SCSI_INBIT));
WR_HARPOON(p_port + hp_scsisig, S_DATAI_PH);
WR_HARPOON(p_port + hp_xfer_cmd,
(XFER_DMA_HOST | XFER_HOST_AUTO | XFER_DMA_8BIT));
}
else {
WR_HARPOON(p_port + hp_portctrl_0,
(SCSI_PORT | DMA_PORT | DMA_RD));
WR_HARPOON(p_port + hp_scsisig, S_DATAO_PH);
WR_HARPOON(p_port + hp_xfer_cmd,
(XFER_HOST_DMA | XFER_HOST_AUTO | XFER_DMA_8BIT));
}
}
static unsigned char FPT_busMstrTimeOut(u32 p_port)
{
unsigned long timeout;
timeout = LONG_WAIT;
WR_HARPOON(p_port + hp_sys_ctrl, HALT_MACH);
while ((!(RD_HARPOON(p_port + hp_ext_status) & CMD_ABORTED))
&& timeout--) {
}
if (RD_HARPOON(p_port + hp_ext_status) & BM_CMD_BUSY) {
WR_HARPOON(p_port + hp_sys_ctrl, HARD_ABORT);
timeout = LONG_WAIT;
while ((RD_HARPOON(p_port + hp_ext_status) & BM_CMD_BUSY)
&& timeout--) {
}
}
RD_HARPOON(p_port + hp_int_status);
if (RD_HARPOON(p_port + hp_ext_status) & BM_CMD_BUSY) {
return 1;
}
else {
return 0;
}
}
static void FPT_hostDataXferAbort(u32 port, unsigned char p_card,
struct sccb *pCurrSCCB)
{
unsigned long timeout;
unsigned long remain_cnt;
u32 sg_ptr;
struct blogic_sg_seg *segp;
FPT_BL_Card[p_card].globalFlags &= ~F_HOST_XFER_ACT;
if (pCurrSCCB->Sccb_XferState & F_AUTO_SENSE) {
if (!(RD_HARPOON(port + hp_int_status) & INT_CMD_COMPL)) {
WR_HARPOON(port + hp_bm_ctrl,
(RD_HARPOON(port + hp_bm_ctrl) |
FLUSH_XFER_CNTR));
timeout = LONG_WAIT;
while ((RD_HARPOON(port + hp_ext_status) & BM_CMD_BUSY)
&& timeout--) {
}
WR_HARPOON(port + hp_bm_ctrl,
(RD_HARPOON(port + hp_bm_ctrl) &
~FLUSH_XFER_CNTR));
if (RD_HARPOON(port + hp_ext_status) & BM_CMD_BUSY) {
if (FPT_busMstrTimeOut(port)) {
if (pCurrSCCB->HostStatus == 0x00)
pCurrSCCB->HostStatus =
SCCB_BM_ERR;
}
if (RD_HARPOON(port + hp_int_status) &
INT_EXT_STATUS)
if (RD_HARPOON(port + hp_ext_status) &
BAD_EXT_STATUS)
if (pCurrSCCB->HostStatus ==
0x00)
{
pCurrSCCB->HostStatus =
SCCB_BM_ERR;
}
}
}
}
else if (pCurrSCCB->Sccb_XferCnt) {
if (pCurrSCCB->Sccb_XferState & F_SG_XFER) {
WR_HARPOON(port + hp_page_ctrl,
(RD_HARPOON(port + hp_page_ctrl) &
~SCATTER_EN));
WR_HARPOON(port + hp_sg_addr, 0x00);
sg_ptr = pCurrSCCB->Sccb_sgseg + SG_BUF_CNT;
if (sg_ptr >
(unsigned int)(pCurrSCCB->DataLength /
SG_ELEMENT_SIZE)) {
sg_ptr = (u32)(pCurrSCCB->DataLength /
SG_ELEMENT_SIZE);
}
remain_cnt = pCurrSCCB->Sccb_XferCnt;
while (remain_cnt < 0x01000000L) {
sg_ptr--;
segp = (struct blogic_sg_seg *)(pCurrSCCB->
DataPointer) + (sg_ptr * 2);
if (remain_cnt > (unsigned long)segp->segbytes)
remain_cnt -=
(unsigned long)segp->segbytes;
else
break;
}
if (remain_cnt < 0x01000000L) {
pCurrSCCB->Sccb_SGoffset = remain_cnt;
pCurrSCCB->Sccb_sgseg = (unsigned short)sg_ptr;
if ((unsigned long)(sg_ptr * SG_ELEMENT_SIZE) ==
pCurrSCCB->DataLength && (remain_cnt == 0))
pCurrSCCB->Sccb_XferState |=
F_ALL_XFERRED;
}
else {
if (pCurrSCCB->HostStatus == 0x00) {
pCurrSCCB->HostStatus =
SCCB_GROSS_FW_ERR;
}
}
}
if (!(pCurrSCCB->Sccb_XferState & F_HOST_XFER_DIR)) {
if (RD_HARPOON(port + hp_ext_status) & BM_CMD_BUSY) {
FPT_busMstrTimeOut(port);
}
else {
if (RD_HARPOON(port + hp_int_status) &
INT_EXT_STATUS) {
if (RD_HARPOON(port + hp_ext_status) &
BAD_EXT_STATUS) {
if (pCurrSCCB->HostStatus ==
0x00) {
pCurrSCCB->HostStatus =
SCCB_BM_ERR;
}
}
}
}
}
else {
if ((RD_HARPOON(port + hp_fifo_cnt)) >= BM_THRESHOLD) {
timeout = SHORT_WAIT;
while ((RD_HARPOON(port + hp_ext_status) &
BM_CMD_BUSY)
&& ((RD_HARPOON(port + hp_fifo_cnt)) >=
BM_THRESHOLD) && timeout--) {
}
}
if (RD_HARPOON(port + hp_ext_status) & BM_CMD_BUSY) {
WR_HARPOON(port + hp_bm_ctrl,
(RD_HARPOON(port + hp_bm_ctrl) |
FLUSH_XFER_CNTR));
timeout = LONG_WAIT;
while ((RD_HARPOON(port + hp_ext_status) &
BM_CMD_BUSY) && timeout--) {
}
WR_HARPOON(port + hp_bm_ctrl,
(RD_HARPOON(port + hp_bm_ctrl) &
~FLUSH_XFER_CNTR));
if (RD_HARPOON(port + hp_ext_status) &
BM_CMD_BUSY) {
if (pCurrSCCB->HostStatus == 0x00) {
pCurrSCCB->HostStatus =
SCCB_BM_ERR;
}
FPT_busMstrTimeOut(port);
}
}
if (RD_HARPOON(port + hp_int_status) & INT_EXT_STATUS) {
if (RD_HARPOON(port + hp_ext_status) &
BAD_EXT_STATUS) {
if (pCurrSCCB->HostStatus == 0x00) {
pCurrSCCB->HostStatus =
SCCB_BM_ERR;
}
}
}
}
}
else {
if (RD_HARPOON(port + hp_ext_status) & BM_CMD_BUSY) {
timeout = LONG_WAIT;
while ((RD_HARPOON(port + hp_ext_status) & BM_CMD_BUSY)
&& timeout--) {
}
if (RD_HARPOON(port + hp_ext_status) & BM_CMD_BUSY) {
if (pCurrSCCB->HostStatus == 0x00) {
pCurrSCCB->HostStatus = SCCB_BM_ERR;
}
FPT_busMstrTimeOut(port);
}
}
if (RD_HARPOON(port + hp_int_status) & INT_EXT_STATUS) {
if (RD_HARPOON(port + hp_ext_status) & BAD_EXT_STATUS) {
if (pCurrSCCB->HostStatus == 0x00) {
pCurrSCCB->HostStatus = SCCB_BM_ERR;
}
}
}
if (pCurrSCCB->Sccb_XferState & F_SG_XFER) {
WR_HARPOON(port + hp_page_ctrl,
(RD_HARPOON(port + hp_page_ctrl) &
~SCATTER_EN));
WR_HARPOON(port + hp_sg_addr, 0x00);
pCurrSCCB->Sccb_sgseg += SG_BUF_CNT;
pCurrSCCB->Sccb_SGoffset = 0x00;
if ((u32)(pCurrSCCB->Sccb_sgseg * SG_ELEMENT_SIZE) >=
pCurrSCCB->DataLength) {
pCurrSCCB->Sccb_XferState |= F_ALL_XFERRED;
pCurrSCCB->Sccb_sgseg =
(unsigned short)(pCurrSCCB->DataLength /
SG_ELEMENT_SIZE);
}
}
else {
if (!(pCurrSCCB->Sccb_XferState & F_AUTO_SENSE))
pCurrSCCB->Sccb_XferState |= F_ALL_XFERRED;
}
}
WR_HARPOON(port + hp_int_mask, (INT_CMD_COMPL | SCSI_INTERRUPT));
}
static void FPT_hostDataXferRestart(struct sccb *currSCCB)
{
unsigned long data_count;
unsigned int sg_index;
struct blogic_sg_seg *segp;
if (currSCCB->Sccb_XferState & F_SG_XFER) {
currSCCB->Sccb_XferCnt = 0;
sg_index = 0xffff;
data_count = 0;
while (data_count < currSCCB->Sccb_ATC) {
sg_index++;
segp = (struct blogic_sg_seg *)(currSCCB->DataPointer) +
(sg_index * 2);
data_count += segp->segbytes;
}
if (data_count == currSCCB->Sccb_ATC) {
currSCCB->Sccb_SGoffset = 0;
sg_index++;
}
else {
currSCCB->Sccb_SGoffset =
data_count - currSCCB->Sccb_ATC;
}
currSCCB->Sccb_sgseg = (unsigned short)sg_index;
}
else {
currSCCB->Sccb_XferCnt =
currSCCB->DataLength - currSCCB->Sccb_ATC;
}
}
static void FPT_scini(unsigned char p_card, unsigned char p_our_id,
unsigned char p_power_up)
{
unsigned char loser, assigned_id;
u32 p_port;
unsigned char i, k, ScamFlg;
struct sccb_card *currCard;
struct nvram_info *pCurrNvRam;
currCard = &FPT_BL_Card[p_card];
p_port = currCard->ioPort;
pCurrNvRam = currCard->pNvRamInfo;
if (pCurrNvRam) {
ScamFlg = pCurrNvRam->niScamConf;
i = pCurrNvRam->niSysConf;
} else {
ScamFlg =
(unsigned char)FPT_utilEERead(p_port, SCAM_CONFIG / 2);
i = (unsigned
char)(FPT_utilEERead(p_port, (SYSTEM_CONFIG / 2)));
}
if (!(i & 0x02))
return;
FPT_inisci(p_card, p_port, p_our_id);
FPT_Wait1Second(p_port);
if ((ScamFlg & SCAM_ENABLED) && (ScamFlg & SCAM_LEVEL2)) {
while (!(FPT_scarb(p_port, INIT_SELTD))) {
}
FPT_scsel(p_port);
do {
FPT_scxferc(p_port, SYNC_PTRN);
FPT_scxferc(p_port, DOM_MSTR);
loser =
FPT_scsendi(p_port,
&FPT_scamInfo[p_our_id].id_string[0]);
} while (loser == 0xFF);
FPT_scbusf(p_port);
if ((p_power_up) && (!loser)) {
FPT_sresb(p_port, p_card);
FPT_Wait(p_port, TO_250ms);
while (!(FPT_scarb(p_port, INIT_SELTD))) {
}
FPT_scsel(p_port);
do {
FPT_scxferc(p_port, SYNC_PTRN);
FPT_scxferc(p_port, DOM_MSTR);
loser =
FPT_scsendi(p_port,
&FPT_scamInfo[p_our_id].
id_string[0]);
} while (loser == 0xFF);
FPT_scbusf(p_port);
}
}
else {
loser = 0;
}
if (!loser) {
FPT_scamInfo[p_our_id].state = ID_ASSIGNED;
if (ScamFlg & SCAM_ENABLED) {
for (i = 0; i < MAX_SCSI_TAR; i++) {
if ((FPT_scamInfo[i].state == ID_UNASSIGNED) ||
(FPT_scamInfo[i].state == ID_UNUSED)) {
if (FPT_scsell(p_port, i)) {
FPT_scamInfo[i].state = LEGACY;
if ((FPT_scamInfo[i].
id_string[0] != 0xFF)
|| (FPT_scamInfo[i].
id_string[1] != 0xFA)) {
FPT_scamInfo[i].
id_string[0] = 0xFF;
FPT_scamInfo[i].
id_string[1] = 0xFA;
if (pCurrNvRam == NULL)
currCard->
globalFlags
|=
F_UPDATE_EEPROM;
}
}
}
}
FPT_sresb(p_port, p_card);
FPT_Wait1Second(p_port);
while (!(FPT_scarb(p_port, INIT_SELTD))) {
}
FPT_scsel(p_port);
FPT_scasid(p_card, p_port);
}
}
else if ((loser) && (ScamFlg & SCAM_ENABLED)) {
FPT_scamInfo[p_our_id].id_string[0] = SLV_TYPE_CODE0;
assigned_id = 0;
FPT_scwtsel(p_port);
do {
while (FPT_scxferc(p_port, 0x00) != SYNC_PTRN) {
}
i = FPT_scxferc(p_port, 0x00);
if (i == ASSIGN_ID) {
if (!
(FPT_scsendi
(p_port,
&FPT_scamInfo[p_our_id].id_string[0]))) {
i = FPT_scxferc(p_port, 0x00);
if (FPT_scvalq(i)) {
k = FPT_scxferc(p_port, 0x00);
if (FPT_scvalq(k)) {
currCard->ourId =
((unsigned char)(i
<<
3)
+
(k &
(unsigned char)7))
& (unsigned char)
0x3F;
FPT_inisci(p_card,
p_port,
p_our_id);
FPT_scamInfo[currCard->
ourId].
state = ID_ASSIGNED;
FPT_scamInfo[currCard->
ourId].
id_string[0]
= SLV_TYPE_CODE0;
assigned_id = 1;
}
}
}
}
else if (i == SET_P_FLAG) {
if (!(FPT_scsendi(p_port,
&FPT_scamInfo[p_our_id].
id_string[0])))
FPT_scamInfo[p_our_id].id_string[0] |=
0x80;
}
} while (!assigned_id);
while (FPT_scxferc(p_port, 0x00) != CFG_CMPLT) {
}
}
if (ScamFlg & SCAM_ENABLED) {
FPT_scbusf(p_port);
if (currCard->globalFlags & F_UPDATE_EEPROM) {
FPT_scsavdi(p_card, p_port);
currCard->globalFlags &= ~F_UPDATE_EEPROM;
}
}
}
static int FPT_scarb(u32 p_port, unsigned char p_sel_type)
{
if (p_sel_type == INIT_SELTD) {
while (RD_HARPOON(p_port + hp_scsisig) & (SCSI_SEL | SCSI_BSY)) {
}
if (RD_HARPOON(p_port + hp_scsisig) & SCSI_SEL)
return 0;
if (RD_HARPOON(p_port + hp_scsidata_0) != 00)
return 0;
WR_HARPOON(p_port + hp_scsisig,
(RD_HARPOON(p_port + hp_scsisig) | SCSI_BSY));
if (RD_HARPOON(p_port + hp_scsisig) & SCSI_SEL) {
WR_HARPOON(p_port + hp_scsisig,
(RD_HARPOON(p_port + hp_scsisig) &
~SCSI_BSY));
return 0;
}
WR_HARPOON(p_port + hp_scsisig,
(RD_HARPOON(p_port + hp_scsisig) | SCSI_SEL));
if (RD_HARPOON(p_port + hp_scsidata_0) != 00) {
WR_HARPOON(p_port + hp_scsisig,
(RD_HARPOON(p_port + hp_scsisig) &
~(SCSI_BSY | SCSI_SEL)));
return 0;
}
}
WR_HARPOON(p_port + hp_clkctrl_0, (RD_HARPOON(p_port + hp_clkctrl_0)
& ~ACTdeassert));
WR_HARPOON(p_port + hp_scsireset, SCAM_EN);
WR_HARPOON(p_port + hp_scsidata_0, 0x00);
WR_HARPOON(p_port + hp_scsidata_1, 0x00);
WR_HARPOON(p_port + hp_portctrl_0, SCSI_BUS_EN);
WR_HARPOON(p_port + hp_scsisig,
(RD_HARPOON(p_port + hp_scsisig) | SCSI_MSG));
WR_HARPOON(p_port + hp_scsisig, (RD_HARPOON(p_port + hp_scsisig)
& ~SCSI_BSY));
FPT_Wait(p_port, TO_250ms);
return 1;
}
static void FPT_scbusf(u32 p_port)
{
WR_HARPOON(p_port + hp_page_ctrl,
(RD_HARPOON(p_port + hp_page_ctrl) | G_INT_DISABLE));
WR_HARPOON(p_port + hp_scsidata_0, 0x00);
WR_HARPOON(p_port + hp_portctrl_0, (RD_HARPOON(p_port + hp_portctrl_0)
& ~SCSI_BUS_EN));
WR_HARPOON(p_port + hp_scsisig, 0x00);
WR_HARPOON(p_port + hp_scsireset, (RD_HARPOON(p_port + hp_scsireset)
& ~SCAM_EN));
WR_HARPOON(p_port + hp_clkctrl_0, (RD_HARPOON(p_port + hp_clkctrl_0)
| ACTdeassert));
WRW_HARPOON((p_port + hp_intstat), (BUS_FREE | AUTO_INT | SCAM_SEL));
WR_HARPOON(p_port + hp_page_ctrl,
(RD_HARPOON(p_port + hp_page_ctrl) & ~G_INT_DISABLE));
}
static void FPT_scasid(unsigned char p_card, u32 p_port)
{
unsigned char temp_id_string[ID_STRING_LENGTH];
unsigned char i, k, scam_id;
unsigned char crcBytes[3];
struct nvram_info *pCurrNvRam;
unsigned short *pCrcBytes;
pCurrNvRam = FPT_BL_Card[p_card].pNvRamInfo;
i = 0;
while (!i) {
for (k = 0; k < ID_STRING_LENGTH; k++) {
temp_id_string[k] = (unsigned char)0x00;
}
FPT_scxferc(p_port, SYNC_PTRN);
FPT_scxferc(p_port, ASSIGN_ID);
if (!(FPT_sciso(p_port, &temp_id_string[0]))) {
if (pCurrNvRam) {
pCrcBytes = (unsigned short *)&crcBytes[0];
*pCrcBytes = FPT_CalcCrc16(&temp_id_string[0]);
crcBytes[2] = FPT_CalcLrc(&temp_id_string[0]);
temp_id_string[1] = crcBytes[2];
temp_id_string[2] = crcBytes[0];
temp_id_string[3] = crcBytes[1];
for (k = 4; k < ID_STRING_LENGTH; k++)
temp_id_string[k] = (unsigned char)0x00;
}
i = FPT_scmachid(p_card, temp_id_string);
if (i == CLR_PRIORITY) {
FPT_scxferc(p_port, MISC_CODE);
FPT_scxferc(p_port, CLR_P_FLAG);
i = 0;
}
else if (i != NO_ID_AVAIL) {
if (i < 8)
FPT_scxferc(p_port, ID_0_7);
else
FPT_scxferc(p_port, ID_8_F);
scam_id = (i & (unsigned char)0x07);
for (k = 1; k < 0x08; k <<= 1)
if (!(k & i))
scam_id += 0x08;
FPT_scxferc(p_port, scam_id);
i = 0;
}
}
else {
i = 1;
}
}
FPT_scxferc(p_port, SYNC_PTRN);
FPT_scxferc(p_port, CFG_CMPLT);
}
static void FPT_scsel(u32 p_port)
{
WR_HARPOON(p_port + hp_scsisig, SCSI_SEL);
FPT_scwiros(p_port, SCSI_MSG);
WR_HARPOON(p_port + hp_scsisig, (SCSI_SEL | SCSI_BSY));
WR_HARPOON(p_port + hp_scsisig,
(SCSI_SEL | SCSI_BSY | SCSI_IOBIT | SCSI_CD));
WR_HARPOON(p_port + hp_scsidata_0,
(unsigned char)(RD_HARPOON(p_port + hp_scsidata_0) |
(unsigned char)(BIT(7) + BIT(6))));
WR_HARPOON(p_port + hp_scsisig, (SCSI_BSY | SCSI_IOBIT | SCSI_CD));
FPT_scwiros(p_port, SCSI_SEL);
WR_HARPOON(p_port + hp_scsidata_0,
(unsigned char)(RD_HARPOON(p_port + hp_scsidata_0) &
~(unsigned char)BIT(6)));
FPT_scwirod(p_port, BIT(6));
WR_HARPOON(p_port + hp_scsisig,
(SCSI_SEL | SCSI_BSY | SCSI_IOBIT | SCSI_CD));
}
static unsigned char FPT_scxferc(u32 p_port, unsigned char p_data)
{
unsigned char curr_data, ret_data;
curr_data = p_data | BIT(7) | BIT(5);
WR_HARPOON(p_port + hp_scsidata_0, curr_data);
curr_data &= ~BIT(7);
WR_HARPOON(p_port + hp_scsidata_0, curr_data);
FPT_scwirod(p_port, BIT(7));
while (!(RD_HARPOON(p_port + hp_scsidata_0) & BIT(5))) ;
ret_data = (RD_HARPOON(p_port + hp_scsidata_0) & (unsigned char)0x1F);
curr_data |= BIT(6);
WR_HARPOON(p_port + hp_scsidata_0, curr_data);
curr_data &= ~BIT(5);
WR_HARPOON(p_port + hp_scsidata_0, curr_data);
FPT_scwirod(p_port, BIT(5));
curr_data &= ~(BIT(4) | BIT(3) | BIT(2) | BIT(1) | BIT(0));
curr_data |= BIT(7);
WR_HARPOON(p_port + hp_scsidata_0, curr_data);
curr_data &= ~BIT(6);
WR_HARPOON(p_port + hp_scsidata_0, curr_data);
FPT_scwirod(p_port, BIT(6));
return ret_data;
}
static unsigned char FPT_scsendi(u32 p_port, unsigned char p_id_string[])
{
unsigned char ret_data, byte_cnt, bit_cnt, defer;
defer = 0;
for (byte_cnt = 0; byte_cnt < ID_STRING_LENGTH; byte_cnt++) {
for (bit_cnt = 0x80; bit_cnt != 0; bit_cnt >>= 1) {
if (defer)
ret_data = FPT_scxferc(p_port, 00);
else if (p_id_string[byte_cnt] & bit_cnt)
ret_data = FPT_scxferc(p_port, 02);
else {
ret_data = FPT_scxferc(p_port, 01);
if (ret_data & 02)
defer = 1;
}
if ((ret_data & 0x1C) == 0x10)
return 0x00;
if (ret_data & 0x1C)
return 0xFF;
if ((defer) && (!(ret_data & 0x1F)))
return 0x01;
}
}
if (defer)
return 0x01;
else
return 0;
}
static unsigned char FPT_sciso(u32 p_port, unsigned char p_id_string[])
{
unsigned char ret_data, the_data, byte_cnt, bit_cnt;
the_data = 0;
for (byte_cnt = 0; byte_cnt < ID_STRING_LENGTH; byte_cnt++) {
for (bit_cnt = 0; bit_cnt < 8; bit_cnt++) {
ret_data = FPT_scxferc(p_port, 0);
if (ret_data & 0xFC)
return 0xFF;
else {
the_data <<= 1;
if (ret_data & BIT(1)) {
the_data |= 1;
}
}
if ((ret_data & 0x1F) == 0) {
if (byte_cnt)
return 0x00;
else
return 0xFF;
}
}
p_id_string[byte_cnt] = the_data;
}
return 0;
}
static void FPT_scwirod(u32 p_port, unsigned char p_data_bit)
{
unsigned char i;
i = 0;
while (i < MAX_SCSI_TAR) {
if (RD_HARPOON(p_port + hp_scsidata_0) & p_data_bit)
i = 0;
else
i++;
}
}
static void FPT_scwiros(u32 p_port, unsigned char p_data_bit)
{
unsigned char i;
i = 0;
while (i < MAX_SCSI_TAR) {
if (RD_HARPOON(p_port + hp_scsisig) & p_data_bit)
i = 0;
else
i++;
}
}
static unsigned char FPT_scvalq(unsigned char p_quintet)
{
unsigned char count;
for (count = 1; count < 0x08; count <<= 1) {
if (!(p_quintet & count))
p_quintet -= 0x80;
}
if (p_quintet & 0x18)
return 0;
else
return 1;
}
static unsigned char FPT_scsell(u32 p_port, unsigned char targ_id)
{
unsigned long i;
WR_HARPOON(p_port + hp_page_ctrl,
(RD_HARPOON(p_port + hp_page_ctrl) | G_INT_DISABLE));
ARAM_ACCESS(p_port);
WR_HARPOON(p_port + hp_addstat,
(RD_HARPOON(p_port + hp_addstat) | SCAM_TIMER));
WR_HARPOON(p_port + hp_seltimeout, TO_4ms);
for (i = p_port + CMD_STRT; i < p_port + CMD_STRT + 12; i += 2) {
WRW_HARPOON(i, (MPM_OP + ACOMMAND));
}
WRW_HARPOON(i, (BRH_OP + ALWAYS + NP));
WRW_HARPOON((p_port + hp_intstat),
(RESET | TIMEOUT | SEL | BUS_FREE | AUTO_INT));
WR_HARPOON(p_port + hp_select_id, targ_id);
WR_HARPOON(p_port + hp_portctrl_0, SCSI_PORT);
WR_HARPOON(p_port + hp_autostart_3, (SELECT | CMD_ONLY_STRT));
WR_HARPOON(p_port + hp_scsictrl_0, (SEL_TAR | ENA_RESEL));
while (!(RDW_HARPOON((p_port + hp_intstat)) &
(RESET | PROG_HLT | TIMEOUT | AUTO_INT))) {
}
if (RDW_HARPOON((p_port + hp_intstat)) & RESET)
FPT_Wait(p_port, TO_250ms);
DISABLE_AUTO(p_port);
WR_HARPOON(p_port + hp_addstat,
(RD_HARPOON(p_port + hp_addstat) & ~SCAM_TIMER));
WR_HARPOON(p_port + hp_seltimeout, TO_290ms);
SGRAM_ACCESS(p_port);
if (RDW_HARPOON((p_port + hp_intstat)) & (RESET | TIMEOUT)) {
WRW_HARPOON((p_port + hp_intstat),
(RESET | TIMEOUT | SEL | BUS_FREE | PHASE));
WR_HARPOON(p_port + hp_page_ctrl,
(RD_HARPOON(p_port + hp_page_ctrl) &
~G_INT_DISABLE));
return 0;
}
else {
while (!(RDW_HARPOON((p_port + hp_intstat)) & BUS_FREE)) {
if (RD_HARPOON(p_port + hp_scsisig) & SCSI_REQ) {
WR_HARPOON(p_port + hp_scsisig,
(SCSI_ACK + S_ILL_PH));
ACCEPT_MSG(p_port);
}
}
WRW_HARPOON((p_port + hp_intstat), CLR_ALL_INT_1);
WR_HARPOON(p_port + hp_page_ctrl,
(RD_HARPOON(p_port + hp_page_ctrl) &
~G_INT_DISABLE));
return 1;
}
}
static void FPT_scwtsel(u32 p_port)
{
while (!(RDW_HARPOON((p_port + hp_intstat)) & SCAM_SEL)) {
}
}
static void FPT_inisci(unsigned char p_card, u32 p_port, unsigned char p_our_id)
{
unsigned char i, k, max_id;
unsigned short ee_data;
struct nvram_info *pCurrNvRam;
pCurrNvRam = FPT_BL_Card[p_card].pNvRamInfo;
if (RD_HARPOON(p_port + hp_page_ctrl) & NARROW_SCSI_CARD)
max_id = 0x08;
else
max_id = 0x10;
if (pCurrNvRam) {
for (i = 0; i < max_id; i++) {
for (k = 0; k < 4; k++)
FPT_scamInfo[i].id_string[k] =
pCurrNvRam->niScamTbl[i][k];
for (k = 4; k < ID_STRING_LENGTH; k++)
FPT_scamInfo[i].id_string[k] =
(unsigned char)0x00;
if (FPT_scamInfo[i].id_string[0] == 0x00)
FPT_scamInfo[i].state = ID_UNUSED;
else
FPT_scamInfo[i].state = ID_UNASSIGNED;
}
} else {
for (i = 0; i < max_id; i++) {
for (k = 0; k < ID_STRING_LENGTH; k += 2) {
ee_data =
FPT_utilEERead(p_port,
(unsigned
short)((EE_SCAMBASE / 2) +
(unsigned short)(i *
((unsigned short)ID_STRING_LENGTH / 2)) + (unsigned short)(k / 2)));
FPT_scamInfo[i].id_string[k] =
(unsigned char)ee_data;
ee_data >>= 8;
FPT_scamInfo[i].id_string[k + 1] =
(unsigned char)ee_data;
}
if ((FPT_scamInfo[i].id_string[0] == 0x00) ||
(FPT_scamInfo[i].id_string[0] == 0xFF))
FPT_scamInfo[i].state = ID_UNUSED;
else
FPT_scamInfo[i].state = ID_UNASSIGNED;
}
}
for (k = 0; k < ID_STRING_LENGTH; k++)
FPT_scamInfo[p_our_id].id_string[k] = FPT_scamHAString[k];
}
static unsigned char FPT_scmachid(unsigned char p_card,
unsigned char p_id_string[])
{
unsigned char i, k, match;
for (i = 0; i < MAX_SCSI_TAR; i++) {
match = 1;
for (k = 0; k < ID_STRING_LENGTH; k++) {
if (p_id_string[k] != FPT_scamInfo[i].id_string[k])
match = 0;
}
if (match) {
FPT_scamInfo[i].state = ID_ASSIGNED;
return i;
}
}
if (p_id_string[0] & BIT(5))
i = 8;
else
i = MAX_SCSI_TAR;
if (((p_id_string[0] & 0x06) == 0x02)
|| ((p_id_string[0] & 0x06) == 0x04))
match = p_id_string[1] & (unsigned char)0x1F;
else
match = 7;
while (i > 0) {
i--;
if (FPT_scamInfo[match].state == ID_UNUSED) {
for (k = 0; k < ID_STRING_LENGTH; k++) {
FPT_scamInfo[match].id_string[k] =
p_id_string[k];
}
FPT_scamInfo[match].state = ID_ASSIGNED;
if (FPT_BL_Card[p_card].pNvRamInfo == NULL)
FPT_BL_Card[p_card].globalFlags |=
F_UPDATE_EEPROM;
return match;
}
match--;
if (match == 0xFF) {
if (p_id_string[0] & BIT(5))
match = 7;
else
match = MAX_SCSI_TAR - 1;
}
}
if (p_id_string[0] & BIT(7)) {
return CLR_PRIORITY;
}
if (p_id_string[0] & BIT(5))
i = 8;
else
i = MAX_SCSI_TAR;
if (((p_id_string[0] & 0x06) == 0x02)
|| ((p_id_string[0] & 0x06) == 0x04))
match = p_id_string[1] & (unsigned char)0x1F;
else
match = 7;
while (i > 0) {
i--;
if (FPT_scamInfo[match].state == ID_UNASSIGNED) {
for (k = 0; k < ID_STRING_LENGTH; k++) {
FPT_scamInfo[match].id_string[k] =
p_id_string[k];
}
FPT_scamInfo[match].id_string[0] |= BIT(7);
FPT_scamInfo[match].state = ID_ASSIGNED;
if (FPT_BL_Card[p_card].pNvRamInfo == NULL)
FPT_BL_Card[p_card].globalFlags |=
F_UPDATE_EEPROM;
return match;
}
match--;
if (match == 0xFF) {
if (p_id_string[0] & BIT(5))
match = 7;
else
match = MAX_SCSI_TAR - 1;
}
}
return NO_ID_AVAIL;
}
static void FPT_scsavdi(unsigned char p_card, u32 p_port)
{
unsigned char i, k, max_id;
unsigned short ee_data, sum_data;
sum_data = 0x0000;
for (i = 1; i < EE_SCAMBASE / 2; i++) {
sum_data += FPT_utilEERead(p_port, i);
}
FPT_utilEEWriteOnOff(p_port, 1);
if (RD_HARPOON(p_port + hp_page_ctrl) & NARROW_SCSI_CARD)
max_id = 0x08;
else
max_id = 0x10;
for (i = 0; i < max_id; i++) {
for (k = 0; k < ID_STRING_LENGTH; k += 2) {
ee_data = FPT_scamInfo[i].id_string[k + 1];
ee_data <<= 8;
ee_data |= FPT_scamInfo[i].id_string[k];
sum_data += ee_data;
FPT_utilEEWrite(p_port, ee_data,
(unsigned short)((EE_SCAMBASE / 2) +
(unsigned short)(i *
((unsigned short)ID_STRING_LENGTH / 2)) + (unsigned short)(k / 2)));
}
}
FPT_utilEEWrite(p_port, sum_data, EEPROM_CHECK_SUM / 2);
FPT_utilEEWriteOnOff(p_port, 0);
}
static void FPT_XbowInit(u32 port, unsigned char ScamFlg)
{
unsigned char i;
i = RD_HARPOON(port + hp_page_ctrl);
WR_HARPOON(port + hp_page_ctrl, (unsigned char)(i | G_INT_DISABLE));
WR_HARPOON(port + hp_scsireset, 0x00);
WR_HARPOON(port + hp_portctrl_1, HOST_MODE8);
WR_HARPOON(port + hp_scsireset, (DMA_RESET | HPSCSI_RESET | PROG_RESET |
FIFO_CLR));
WR_HARPOON(port + hp_scsireset, SCSI_INI);
WR_HARPOON(port + hp_clkctrl_0, CLKCTRL_DEFAULT);
WR_HARPOON(port + hp_scsisig, 0x00);
WR_HARPOON(port + hp_scsictrl_0, ENA_SCAM_SEL);
WRW_HARPOON((port + hp_intstat), CLR_ALL_INT);
FPT_default_intena = RESET | RSEL | PROG_HLT | TIMEOUT |
BUS_FREE | XFER_CNT_0 | AUTO_INT;
if ((ScamFlg & SCAM_ENABLED) && (ScamFlg & SCAM_LEVEL2))
FPT_default_intena |= SCAM_SEL;
WRW_HARPOON((port + hp_intena), FPT_default_intena);
WR_HARPOON(port + hp_seltimeout, TO_290ms);
if (RD_HARPOON(port + hp_page_ctrl) & NARROW_SCSI_CARD)
WR_HARPOON(port + hp_addstat, SCSI_MODE8);
WR_HARPOON(port + hp_page_ctrl, i);
}
static void FPT_BusMasterInit(u32 p_port)
{
WR_HARPOON(p_port + hp_sys_ctrl, DRVR_RST);
WR_HARPOON(p_port + hp_sys_ctrl, 0x00);
WR_HARPOON(p_port + hp_host_blk_cnt, XFER_BLK64);
WR_HARPOON(p_port + hp_bm_ctrl, (BMCTRL_DEFAULT));
WR_HARPOON(p_port + hp_ee_ctrl, (SCSI_TERM_ENA_H));
RD_HARPOON(p_port + hp_int_status);
WR_HARPOON(p_port + hp_int_mask, (INT_CMD_COMPL | SCSI_INTERRUPT));
WR_HARPOON(p_port + hp_page_ctrl, (RD_HARPOON(p_port + hp_page_ctrl) &
~SCATTER_EN));
}
static void FPT_DiagEEPROM(u32 p_port)
{
unsigned short index, temp, max_wd_cnt;
if (RD_HARPOON(p_port + hp_page_ctrl) & NARROW_SCSI_CARD)
max_wd_cnt = EEPROM_WD_CNT;
else
max_wd_cnt = EEPROM_WD_CNT * 2;
temp = FPT_utilEERead(p_port, FW_SIGNATURE / 2);
if (temp == 0x4641) {
for (index = 2; index < max_wd_cnt; index++) {
temp += FPT_utilEERead(p_port, index);
}
if (temp == FPT_utilEERead(p_port, EEPROM_CHECK_SUM / 2)) {
return;
}
}
FPT_utilEEWriteOnOff(p_port, (unsigned char)1);
for (index = 0; index < max_wd_cnt; index++) {
FPT_utilEEWrite(p_port, 0x0000, index);
}
temp = 0;
FPT_utilEEWrite(p_port, 0x4641, FW_SIGNATURE / 2);
temp += 0x4641;
FPT_utilEEWrite(p_port, 0x3920, MODEL_NUMB_0 / 2);
temp += 0x3920;
FPT_utilEEWrite(p_port, 0x3033, MODEL_NUMB_2 / 2);
temp += 0x3033;
FPT_utilEEWrite(p_port, 0x2020, MODEL_NUMB_4 / 2);
temp += 0x2020;
FPT_utilEEWrite(p_port, 0x70D3, SYSTEM_CONFIG / 2);
temp += 0x70D3;
FPT_utilEEWrite(p_port, 0x0010, BIOS_CONFIG / 2);
temp += 0x0010;
FPT_utilEEWrite(p_port, 0x0003, SCAM_CONFIG / 2);
temp += 0x0003;
FPT_utilEEWrite(p_port, 0x0007, ADAPTER_SCSI_ID / 2);
temp += 0x0007;
FPT_utilEEWrite(p_port, 0x0000, IGNORE_B_SCAN / 2);
temp += 0x0000;
FPT_utilEEWrite(p_port, 0x0000, SEND_START_ENA / 2);
temp += 0x0000;
FPT_utilEEWrite(p_port, 0x0000, DEVICE_ENABLE / 2);
temp += 0x0000;
FPT_utilEEWrite(p_port, 0x4242, SYNC_RATE_TBL01 / 2);
temp += 0x4242;
FPT_utilEEWrite(p_port, 0x4242, SYNC_RATE_TBL23 / 2);
temp += 0x4242;
FPT_utilEEWrite(p_port, 0x4242, SYNC_RATE_TBL45 / 2);
temp += 0x4242;
FPT_utilEEWrite(p_port, 0x4242, SYNC_RATE_TBL67 / 2);
temp += 0x4242;
FPT_utilEEWrite(p_port, 0x4242, SYNC_RATE_TBL89 / 2);
temp += 0x4242;
FPT_utilEEWrite(p_port, 0x4242, SYNC_RATE_TBLab / 2);
temp += 0x4242;
FPT_utilEEWrite(p_port, 0x4242, SYNC_RATE_TBLcd / 2);
temp += 0x4242;
FPT_utilEEWrite(p_port, 0x4242, SYNC_RATE_TBLef / 2);
temp += 0x4242;
FPT_utilEEWrite(p_port, 0x6C46, 64 / 2);
temp += 0x6C46;
FPT_utilEEWrite(p_port, 0x7361, 66 / 2);
temp += 0x7361;
FPT_utilEEWrite(p_port, 0x5068, 68 / 2);
temp += 0x5068;
FPT_utilEEWrite(p_port, 0x696F, 70 / 2);
temp += 0x696F;
FPT_utilEEWrite(p_port, 0x746E, 72 / 2);
temp += 0x746E;
FPT_utilEEWrite(p_port, 0x4C20, 74 / 2);
temp += 0x4C20;
FPT_utilEEWrite(p_port, 0x2054, 76 / 2);
temp += 0x2054;
FPT_utilEEWrite(p_port, 0x2020, 78 / 2);
temp += 0x2020;
index = ((EE_SCAMBASE / 2) + (7 * 16));
FPT_utilEEWrite(p_port, (0x0700 + TYPE_CODE0), index);
temp += (0x0700 + TYPE_CODE0);
index++;
FPT_utilEEWrite(p_port, 0x5542, index);
temp += 0x5542;
index++;
FPT_utilEEWrite(p_port, 0x4C53, index);
temp += 0x4C53;
index++;
FPT_utilEEWrite(p_port, 0x474F, index);
temp += 0x474F;
index++;
FPT_utilEEWrite(p_port, 0x4349, index);
temp += 0x4349;
index++;
FPT_utilEEWrite(p_port, 0x5442, index);
temp += 0x5442;
index++;
FPT_utilEEWrite(p_port, 0x202D, index);
temp += 0x202D;
index++;
FPT_utilEEWrite(p_port, 0x3339, index);
temp += 0x3339;
index++;
FPT_utilEEWrite(p_port, 0x2030, index);
temp += 0x2030;
index++;
FPT_utilEEWrite(p_port, 0x5453, index);
temp += 0x5453;
index++;
FPT_utilEEWrite(p_port, 0x5645, index);
temp += 0x5645;
index++;
FPT_utilEEWrite(p_port, 0x2045, index);
temp += 0x2045;
index++;
FPT_utilEEWrite(p_port, 0x202F, index);
temp += 0x202F;
index++;
FPT_utilEEWrite(p_port, 0x4F4A, index);
temp += 0x4F4A;
index++;
FPT_utilEEWrite(p_port, 0x204E, index);
temp += 0x204E;
index++;
FPT_utilEEWrite(p_port, 0x3539, index);
temp += 0x3539;
FPT_utilEEWrite(p_port, temp, EEPROM_CHECK_SUM / 2);
FPT_utilEEWriteOnOff(p_port, (unsigned char)0);
}
static void FPT_queueSearchSelect(struct sccb_card *pCurrCard,
unsigned char p_card)
{
unsigned char scan_ptr, lun;
struct sccb_mgr_tar_info *currTar_Info;
struct sccb *pOldSccb;
scan_ptr = pCurrCard->scanIndex;
do {
currTar_Info = &FPT_sccbMgrTbl[p_card][scan_ptr];
if ((pCurrCard->globalFlags & F_CONLUN_IO) &&
((currTar_Info->TarStatus & TAR_TAG_Q_MASK) !=
TAG_Q_TRYING)) {
if (currTar_Info->TarSelQ_Cnt != 0) {
scan_ptr++;
if (scan_ptr == MAX_SCSI_TAR)
scan_ptr = 0;
for (lun = 0; lun < MAX_LUN; lun++) {
if (currTar_Info->TarLUNBusy[lun] == 0) {
pCurrCard->currentSCCB =
currTar_Info->TarSelQ_Head;
pOldSccb = NULL;
while ((pCurrCard->
currentSCCB != NULL)
&& (lun !=
pCurrCard->
currentSCCB->Lun)) {
pOldSccb =
pCurrCard->
currentSCCB;
pCurrCard->currentSCCB =
(struct sccb
*)(pCurrCard->
currentSCCB)->
Sccb_forwardlink;
}
if (pCurrCard->currentSCCB ==
NULL)
continue;
if (pOldSccb != NULL) {
pOldSccb->
Sccb_forwardlink =
(struct sccb
*)(pCurrCard->
currentSCCB)->
Sccb_forwardlink;
pOldSccb->
Sccb_backlink =
(struct sccb
*)(pCurrCard->
currentSCCB)->
Sccb_backlink;
currTar_Info->
TarSelQ_Cnt--;
} else {
currTar_Info->
TarSelQ_Head =
(struct sccb
*)(pCurrCard->
currentSCCB)->
Sccb_forwardlink;
if (currTar_Info->
TarSelQ_Head ==
NULL) {
currTar_Info->
TarSelQ_Tail
= NULL;
currTar_Info->
TarSelQ_Cnt
= 0;
} else {
currTar_Info->
TarSelQ_Cnt--;
currTar_Info->
TarSelQ_Head->
Sccb_backlink
=
(struct sccb
*)NULL;
}
}
pCurrCard->scanIndex = scan_ptr;
pCurrCard->globalFlags |=
F_NEW_SCCB_CMD;
break;
}
}
}
else {
scan_ptr++;
if (scan_ptr == MAX_SCSI_TAR) {
scan_ptr = 0;
}
}
} else {
if ((currTar_Info->TarSelQ_Cnt != 0) &&
(currTar_Info->TarLUNBusy[0] == 0)) {
pCurrCard->currentSCCB =
currTar_Info->TarSelQ_Head;
currTar_Info->TarSelQ_Head =
(struct sccb *)(pCurrCard->currentSCCB)->
Sccb_forwardlink;
if (currTar_Info->TarSelQ_Head == NULL) {
currTar_Info->TarSelQ_Tail = NULL;
currTar_Info->TarSelQ_Cnt = 0;
} else {
currTar_Info->TarSelQ_Cnt--;
currTar_Info->TarSelQ_Head->
Sccb_backlink = (struct sccb *)NULL;
}
scan_ptr++;
if (scan_ptr == MAX_SCSI_TAR)
scan_ptr = 0;
pCurrCard->scanIndex = scan_ptr;
pCurrCard->globalFlags |= F_NEW_SCCB_CMD;
break;
}
else {
scan_ptr++;
if (scan_ptr == MAX_SCSI_TAR) {
scan_ptr = 0;
}
}
}
} while (scan_ptr != pCurrCard->scanIndex);
}
static void FPT_queueSelectFail(struct sccb_card *pCurrCard,
unsigned char p_card)
{
unsigned char thisTarg;
struct sccb_mgr_tar_info *currTar_Info;
if (pCurrCard->currentSCCB != NULL) {
thisTarg =
(unsigned char)(((struct sccb *)(pCurrCard->currentSCCB))->
TargID);
currTar_Info = &FPT_sccbMgrTbl[p_card][thisTarg];
pCurrCard->currentSCCB->Sccb_backlink = (struct sccb *)NULL;
pCurrCard->currentSCCB->Sccb_forwardlink =
currTar_Info->TarSelQ_Head;
if (currTar_Info->TarSelQ_Cnt == 0) {
currTar_Info->TarSelQ_Tail = pCurrCard->currentSCCB;
}
else {
currTar_Info->TarSelQ_Head->Sccb_backlink =
pCurrCard->currentSCCB;
}
currTar_Info->TarSelQ_Head = pCurrCard->currentSCCB;
pCurrCard->currentSCCB = NULL;
currTar_Info->TarSelQ_Cnt++;
}
}
static void FPT_queueCmdComplete(struct sccb_card *pCurrCard,
struct sccb *p_sccb, unsigned char p_card)
{
unsigned char i, SCSIcmd;
CALL_BK_FN callback;
struct sccb_mgr_tar_info *currTar_Info;
SCSIcmd = p_sccb->Cdb[0];
if (!(p_sccb->Sccb_XferState & F_ALL_XFERRED)) {
if ((p_sccb->
ControlByte & (SCCB_DATA_XFER_OUT | SCCB_DATA_XFER_IN))
&& (p_sccb->HostStatus == SCCB_COMPLETE)
&& (p_sccb->TargetStatus != SSCHECK))
if ((SCSIcmd == SCSI_READ) ||
(SCSIcmd == SCSI_WRITE) ||
(SCSIcmd == SCSI_READ_EXTENDED) ||
(SCSIcmd == SCSI_WRITE_EXTENDED) ||
(SCSIcmd == SCSI_WRITE_AND_VERIFY) ||
(SCSIcmd == SCSI_START_STOP_UNIT) ||
(pCurrCard->globalFlags & F_NO_FILTER)
)
p_sccb->HostStatus = SCCB_DATA_UNDER_RUN;
}
if (p_sccb->SccbStatus == SCCB_IN_PROCESS) {
if (p_sccb->HostStatus || p_sccb->TargetStatus)
p_sccb->SccbStatus = SCCB_ERROR;
else
p_sccb->SccbStatus = SCCB_SUCCESS;
}
if (p_sccb->Sccb_XferState & F_AUTO_SENSE) {
p_sccb->CdbLength = p_sccb->Save_CdbLen;
for (i = 0; i < 6; i++) {
p_sccb->Cdb[i] = p_sccb->Save_Cdb[i];
}
}
if ((p_sccb->OperationCode == RESIDUAL_SG_COMMAND) ||
(p_sccb->OperationCode == RESIDUAL_COMMAND)) {
FPT_utilUpdateResidual(p_sccb);
}
pCurrCard->cmdCounter--;
if (!pCurrCard->cmdCounter) {
if (pCurrCard->globalFlags & F_GREEN_PC) {
WR_HARPOON(pCurrCard->ioPort + hp_clkctrl_0,
(PWR_DWN | CLKCTRL_DEFAULT));
WR_HARPOON(pCurrCard->ioPort + hp_sys_ctrl, STOP_CLK);
}
WR_HARPOON(pCurrCard->ioPort + hp_semaphore,
(RD_HARPOON(pCurrCard->ioPort + hp_semaphore) &
~SCCB_MGR_ACTIVE));
}
if (pCurrCard->discQCount != 0) {
currTar_Info = &FPT_sccbMgrTbl[p_card][p_sccb->TargID];
if (((pCurrCard->globalFlags & F_CONLUN_IO) &&
((currTar_Info->TarStatus & TAR_TAG_Q_MASK) !=
TAG_Q_TRYING))) {
pCurrCard->discQCount--;
pCurrCard->discQ_Tbl[currTar_Info->
LunDiscQ_Idx[p_sccb->Lun]] = NULL;
} else {
if (p_sccb->Sccb_tag) {
pCurrCard->discQCount--;
pCurrCard->discQ_Tbl[p_sccb->Sccb_tag] = NULL;
} else {
pCurrCard->discQCount--;
pCurrCard->discQ_Tbl[currTar_Info->
LunDiscQ_Idx[0]] = NULL;
}
}
}
callback = (CALL_BK_FN) p_sccb->SccbCallback;
callback(p_sccb);
pCurrCard->globalFlags |= F_NEW_SCCB_CMD;
pCurrCard->currentSCCB = NULL;
}
static void FPT_queueDisconnect(struct sccb *p_sccb, unsigned char p_card)
{
struct sccb_mgr_tar_info *currTar_Info;
currTar_Info = &FPT_sccbMgrTbl[p_card][p_sccb->TargID];
if (((FPT_BL_Card[p_card].globalFlags & F_CONLUN_IO) &&
((currTar_Info->TarStatus & TAR_TAG_Q_MASK) != TAG_Q_TRYING))) {
FPT_BL_Card[p_card].discQ_Tbl[currTar_Info->
LunDiscQ_Idx[p_sccb->Lun]] =
p_sccb;
} else {
if (p_sccb->Sccb_tag) {
FPT_BL_Card[p_card].discQ_Tbl[p_sccb->Sccb_tag] =
p_sccb;
FPT_sccbMgrTbl[p_card][p_sccb->TargID].TarLUNBusy[0] =
0;
FPT_sccbMgrTbl[p_card][p_sccb->TargID].TarTagQ_Cnt++;
} else {
FPT_BL_Card[p_card].discQ_Tbl[currTar_Info->
LunDiscQ_Idx[0]] = p_sccb;
}
}
FPT_BL_Card[p_card].currentSCCB = NULL;
}
static void FPT_queueFlushSccb(unsigned char p_card, unsigned char error_code)
{
unsigned char qtag, thisTarg;
struct sccb *currSCCB;
struct sccb_mgr_tar_info *currTar_Info;
currSCCB = FPT_BL_Card[p_card].currentSCCB;
if (currSCCB != NULL) {
thisTarg = (unsigned char)currSCCB->TargID;
currTar_Info = &FPT_sccbMgrTbl[p_card][thisTarg];
for (qtag = 0; qtag < QUEUE_DEPTH; qtag++) {
if (FPT_BL_Card[p_card].discQ_Tbl[qtag] &&
(FPT_BL_Card[p_card].discQ_Tbl[qtag]->TargID ==
thisTarg)) {
FPT_BL_Card[p_card].discQ_Tbl[qtag]->
HostStatus = (unsigned char)error_code;
FPT_queueCmdComplete(&FPT_BL_Card[p_card],
FPT_BL_Card[p_card].
discQ_Tbl[qtag], p_card);
FPT_BL_Card[p_card].discQ_Tbl[qtag] = NULL;
currTar_Info->TarTagQ_Cnt--;
}
}
}
}
static void FPT_queueFlushTargSccb(unsigned char p_card, unsigned char thisTarg,
unsigned char error_code)
{
unsigned char qtag;
struct sccb_mgr_tar_info *currTar_Info;
currTar_Info = &FPT_sccbMgrTbl[p_card][thisTarg];
for (qtag = 0; qtag < QUEUE_DEPTH; qtag++) {
if (FPT_BL_Card[p_card].discQ_Tbl[qtag] &&
(FPT_BL_Card[p_card].discQ_Tbl[qtag]->TargID == thisTarg)) {
FPT_BL_Card[p_card].discQ_Tbl[qtag]->HostStatus =
(unsigned char)error_code;
FPT_queueCmdComplete(&FPT_BL_Card[p_card],
FPT_BL_Card[p_card].
discQ_Tbl[qtag], p_card);
FPT_BL_Card[p_card].discQ_Tbl[qtag] = NULL;
currTar_Info->TarTagQ_Cnt--;
}
}
}
static void FPT_queueAddSccb(struct sccb *p_SCCB, unsigned char p_card)
{
struct sccb_mgr_tar_info *currTar_Info;
currTar_Info = &FPT_sccbMgrTbl[p_card][p_SCCB->TargID];
p_SCCB->Sccb_forwardlink = NULL;
p_SCCB->Sccb_backlink = currTar_Info->TarSelQ_Tail;
if (currTar_Info->TarSelQ_Cnt == 0) {
currTar_Info->TarSelQ_Head = p_SCCB;
}
else {
currTar_Info->TarSelQ_Tail->Sccb_forwardlink = p_SCCB;
}
currTar_Info->TarSelQ_Tail = p_SCCB;
currTar_Info->TarSelQ_Cnt++;
}
static unsigned char FPT_queueFindSccb(struct sccb *p_SCCB,
unsigned char p_card)
{
struct sccb *q_ptr;
struct sccb_mgr_tar_info *currTar_Info;
currTar_Info = &FPT_sccbMgrTbl[p_card][p_SCCB->TargID];
q_ptr = currTar_Info->TarSelQ_Head;
while (q_ptr != NULL) {
if (q_ptr == p_SCCB) {
if (currTar_Info->TarSelQ_Head == q_ptr) {
currTar_Info->TarSelQ_Head =
q_ptr->Sccb_forwardlink;
}
if (currTar_Info->TarSelQ_Tail == q_ptr) {
currTar_Info->TarSelQ_Tail =
q_ptr->Sccb_backlink;
}
if (q_ptr->Sccb_forwardlink != NULL) {
q_ptr->Sccb_forwardlink->Sccb_backlink =
q_ptr->Sccb_backlink;
}
if (q_ptr->Sccb_backlink != NULL) {
q_ptr->Sccb_backlink->Sccb_forwardlink =
q_ptr->Sccb_forwardlink;
}
currTar_Info->TarSelQ_Cnt--;
return 1;
}
else {
q_ptr = q_ptr->Sccb_forwardlink;
}
}
return 0;
}
static void FPT_utilUpdateResidual(struct sccb *p_SCCB)
{
unsigned long partial_cnt;
unsigned int sg_index;
struct blogic_sg_seg *segp;
if (p_SCCB->Sccb_XferState & F_ALL_XFERRED) {
p_SCCB->DataLength = 0x0000;
}
else if (p_SCCB->Sccb_XferState & F_SG_XFER) {
partial_cnt = 0x0000;
sg_index = p_SCCB->Sccb_sgseg;
if (p_SCCB->Sccb_SGoffset) {
partial_cnt = p_SCCB->Sccb_SGoffset;
sg_index++;
}
while (((unsigned long)sg_index *
(unsigned long)SG_ELEMENT_SIZE) < p_SCCB->DataLength) {
segp = (struct blogic_sg_seg *)(p_SCCB->DataPointer) +
(sg_index * 2);
partial_cnt += segp->segbytes;
sg_index++;
}
p_SCCB->DataLength = partial_cnt;
}
else {
p_SCCB->DataLength -= p_SCCB->Sccb_ATC;
}
}
static void FPT_Wait1Second(u32 p_port)
{
unsigned char i;
for (i = 0; i < 4; i++) {
FPT_Wait(p_port, TO_250ms);
if ((RD_HARPOON(p_port + hp_scsictrl_0) & SCSI_RST))
break;
if ((RDW_HARPOON((p_port + hp_intstat)) & SCAM_SEL))
break;
}
}
static void FPT_Wait(u32 p_port, unsigned char p_delay)
{
unsigned char old_timer;
unsigned char green_flag;
old_timer = RD_HARPOON(p_port + hp_seltimeout);
green_flag = RD_HARPOON(p_port + hp_clkctrl_0);
WR_HARPOON(p_port + hp_clkctrl_0, CLKCTRL_DEFAULT);
WR_HARPOON(p_port + hp_seltimeout, p_delay);
WRW_HARPOON((p_port + hp_intstat), TIMEOUT);
WRW_HARPOON((p_port + hp_intena), (FPT_default_intena & ~TIMEOUT));
WR_HARPOON(p_port + hp_portctrl_0,
(RD_HARPOON(p_port + hp_portctrl_0) | START_TO));
while (!(RDW_HARPOON((p_port + hp_intstat)) & TIMEOUT)) {
if ((RD_HARPOON(p_port + hp_scsictrl_0) & SCSI_RST))
break;
if ((RDW_HARPOON((p_port + hp_intstat)) & SCAM_SEL))
break;
}
WR_HARPOON(p_port + hp_portctrl_0,
(RD_HARPOON(p_port + hp_portctrl_0) & ~START_TO));
WRW_HARPOON((p_port + hp_intstat), TIMEOUT);
WRW_HARPOON((p_port + hp_intena), FPT_default_intena);
WR_HARPOON(p_port + hp_clkctrl_0, green_flag);
WR_HARPOON(p_port + hp_seltimeout, old_timer);
}
static void FPT_utilEEWriteOnOff(u32 p_port, unsigned char p_mode)
{
unsigned char ee_value;
ee_value =
(unsigned char)(RD_HARPOON(p_port + hp_ee_ctrl) &
(EXT_ARB_ACK | SCSI_TERM_ENA_H));
if (p_mode)
FPT_utilEESendCmdAddr(p_port, EWEN, EWEN_ADDR);
else
FPT_utilEESendCmdAddr(p_port, EWDS, EWDS_ADDR);
WR_HARPOON(p_port + hp_ee_ctrl, (ee_value | SEE_MS));
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
}
static void FPT_utilEEWrite(u32 p_port, unsigned short ee_data,
unsigned short ee_addr)
{
unsigned char ee_value;
unsigned short i;
ee_value =
(unsigned
char)((RD_HARPOON(p_port + hp_ee_ctrl) &
(EXT_ARB_ACK | SCSI_TERM_ENA_H)) | (SEE_MS | SEE_CS));
FPT_utilEESendCmdAddr(p_port, EE_WRITE, ee_addr);
ee_value |= (SEE_MS + SEE_CS);
for (i = 0x8000; i != 0; i >>= 1) {
if (i & ee_data)
ee_value |= SEE_DO;
else
ee_value &= ~SEE_DO;
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
ee_value |= SEE_CLK;
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
ee_value &= ~SEE_CLK;
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
}
ee_value &= (EXT_ARB_ACK | SCSI_TERM_ENA_H);
WR_HARPOON(p_port + hp_ee_ctrl, (ee_value | SEE_MS));
FPT_Wait(p_port, TO_10ms);
WR_HARPOON(p_port + hp_ee_ctrl, (ee_value | SEE_MS | SEE_CS));
WR_HARPOON(p_port + hp_ee_ctrl, (ee_value | SEE_MS));
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
}
static unsigned short FPT_utilEERead(u32 p_port,
unsigned short ee_addr)
{
unsigned short i, ee_data1, ee_data2;
i = 0;
ee_data1 = FPT_utilEEReadOrg(p_port, ee_addr);
do {
ee_data2 = FPT_utilEEReadOrg(p_port, ee_addr);
if (ee_data1 == ee_data2)
return ee_data1;
ee_data1 = ee_data2;
i++;
} while (i < 4);
return ee_data1;
}
static unsigned short FPT_utilEEReadOrg(u32 p_port, unsigned short ee_addr)
{
unsigned char ee_value;
unsigned short i, ee_data;
ee_value =
(unsigned
char)((RD_HARPOON(p_port + hp_ee_ctrl) &
(EXT_ARB_ACK | SCSI_TERM_ENA_H)) | (SEE_MS | SEE_CS));
FPT_utilEESendCmdAddr(p_port, EE_READ, ee_addr);
ee_value |= (SEE_MS + SEE_CS);
ee_data = 0;
for (i = 1; i <= 16; i++) {
ee_value |= SEE_CLK;
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
ee_value &= ~SEE_CLK;
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
ee_data <<= 1;
if (RD_HARPOON(p_port + hp_ee_ctrl) & SEE_DI)
ee_data |= 1;
}
ee_value &= ~(SEE_MS + SEE_CS);
WR_HARPOON(p_port + hp_ee_ctrl, (ee_value | SEE_MS));
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
return ee_data;
}
static void FPT_utilEESendCmdAddr(u32 p_port, unsigned char ee_cmd,
unsigned short ee_addr)
{
unsigned char ee_value;
unsigned char narrow_flg;
unsigned short i;
narrow_flg =
(unsigned char)(RD_HARPOON(p_port + hp_page_ctrl) &
NARROW_SCSI_CARD);
ee_value = SEE_MS;
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
ee_value |= SEE_CS;
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
for (i = 0x04; i != 0; i >>= 1) {
if (i & ee_cmd)
ee_value |= SEE_DO;
else
ee_value &= ~SEE_DO;
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
ee_value |= SEE_CLK;
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
ee_value &= ~SEE_CLK;
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
}
if (narrow_flg)
i = 0x0080;
else
i = 0x0200;
while (i != 0) {
if (i & ee_addr)
ee_value |= SEE_DO;
else
ee_value &= ~SEE_DO;
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
ee_value |= SEE_CLK;
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
ee_value &= ~SEE_CLK;
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
WR_HARPOON(p_port + hp_ee_ctrl, ee_value);
i >>= 1;
}
}
static unsigned short FPT_CalcCrc16(unsigned char buffer[])
{
unsigned short crc = 0;
int i, j;
unsigned short ch;
for (i = 0; i < ID_STRING_LENGTH; i++) {
ch = (unsigned short)buffer[i];
for (j = 0; j < 8; j++) {
if ((crc ^ ch) & 1)
crc = (crc >> 1) ^ CRCMASK;
else
crc >>= 1;
ch >>= 1;
}
}
return crc;
}
static unsigned char FPT_CalcLrc(unsigned char buffer[])
{
int i;
unsigned char lrc;
lrc = 0;
for (i = 0; i < ID_STRING_LENGTH; i++)
lrc ^= buffer[i];
return lrc;
}
static inline unsigned char
FlashPoint__ProbeHostAdapter(struct fpoint_info *FlashPointInfo)
{
return FlashPoint_ProbeHostAdapter((struct sccb_mgr_info *)
FlashPointInfo);
}
static inline void *
FlashPoint__HardwareResetHostAdapter(struct fpoint_info *FlashPointInfo)
{
return FlashPoint_HardwareResetHostAdapter((struct sccb_mgr_info *)
FlashPointInfo);
}
static inline void
FlashPoint__ReleaseHostAdapter(void *CardHandle)
{
FlashPoint_ReleaseHostAdapter(CardHandle);
}
static inline void
FlashPoint__StartCCB(void *CardHandle, struct blogic_ccb *CCB)
{
FlashPoint_StartCCB(CardHandle, (struct sccb *)CCB);
}
static inline void
FlashPoint__AbortCCB(void *CardHandle, struct blogic_ccb *CCB)
{
FlashPoint_AbortCCB(CardHandle, (struct sccb *)CCB);
}
static inline bool
FlashPoint__InterruptPending(void *CardHandle)
{
return FlashPoint_InterruptPending(CardHandle);
}
static inline int
FlashPoint__HandleInterrupt(void *CardHandle)
{
return FlashPoint_HandleInterrupt(CardHandle);
}
