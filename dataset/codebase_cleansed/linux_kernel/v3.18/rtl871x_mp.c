static void _init_mp_priv_(struct mp_priv *pmp_priv)
{
pmp_priv->mode = _LOOPBOOK_MODE_;
pmp_priv->curr_ch = 1;
pmp_priv->curr_modem = MIXED_PHY;
pmp_priv->curr_rateidx = 0;
pmp_priv->curr_txpoweridx = 0x14;
pmp_priv->antenna_tx = ANTENNA_A;
pmp_priv->antenna_rx = ANTENNA_AB;
pmp_priv->check_mp_pkt = 0;
pmp_priv->tx_pktcount = 0;
pmp_priv->rx_pktcount = 0;
pmp_priv->rx_crcerrpktcount = 0;
}
static int init_mp_priv(struct mp_priv *pmp_priv)
{
int i, res;
struct mp_xmit_frame *pmp_xmitframe;
_init_mp_priv_(pmp_priv);
_init_queue(&pmp_priv->free_mp_xmitqueue);
pmp_priv->pallocated_mp_xmitframe_buf = NULL;
pmp_priv->pallocated_mp_xmitframe_buf = kmalloc(NR_MP_XMITFRAME *
sizeof(struct mp_xmit_frame) + 4,
GFP_ATOMIC);
if (pmp_priv->pallocated_mp_xmitframe_buf == NULL) {
res = _FAIL;
goto _exit_init_mp_priv;
}
pmp_priv->pmp_xmtframe_buf = pmp_priv->pallocated_mp_xmitframe_buf +
4 -
((addr_t)(pmp_priv->pallocated_mp_xmitframe_buf) & 3);
pmp_xmitframe = (struct mp_xmit_frame *)pmp_priv->pmp_xmtframe_buf;
for (i = 0; i < NR_MP_XMITFRAME; i++) {
INIT_LIST_HEAD(&(pmp_xmitframe->list));
list_add_tail(&(pmp_xmitframe->list),
&(pmp_priv->free_mp_xmitqueue.queue));
pmp_xmitframe->pkt = NULL;
pmp_xmitframe->frame_tag = MP_FRAMETAG;
pmp_xmitframe->padapter = pmp_priv->papdater;
pmp_xmitframe++;
}
pmp_priv->free_mp_xmitframe_cnt = NR_MP_XMITFRAME;
res = _SUCCESS;
_exit_init_mp_priv:
return res;
}
static int free_mp_priv(struct mp_priv *pmp_priv)
{
kfree(pmp_priv->pallocated_mp_xmitframe_buf);
return 0;
}
void mp871xinit(struct _adapter *padapter)
{
struct mp_priv *pmppriv = &padapter->mppriv;
pmppriv->papdater = padapter;
init_mp_priv(pmppriv);
}
void mp871xdeinit(struct _adapter *padapter)
{
struct mp_priv *pmppriv = &padapter->mppriv;
free_mp_priv(pmppriv);
}
static u32 fw_iocmd_read(struct _adapter *pAdapter, struct IOCMD_STRUCT iocmd)
{
u32 cmd32 = 0, val32 = 0;
u8 iocmd_class = iocmd.cmdclass;
u16 iocmd_value = iocmd.value;
u8 iocmd_idx = iocmd.index;
cmd32 = (iocmd_class << 24) | (iocmd_value << 8) | iocmd_idx;
if (r8712_fw_cmd(pAdapter, cmd32))
r8712_fw_cmd_data(pAdapter, &val32, 1);
else
val32 = 0;
return val32;
}
static u8 fw_iocmd_write(struct _adapter *pAdapter,
struct IOCMD_STRUCT iocmd, u32 value)
{
u32 cmd32 = 0;
u8 iocmd_class = iocmd.cmdclass;
u32 iocmd_value = iocmd.value;
u8 iocmd_idx = iocmd.index;
r8712_fw_cmd_data(pAdapter, &value, 0);
msleep(100);
cmd32 = (iocmd_class << 24) | (iocmd_value << 8) | iocmd_idx;
return r8712_fw_cmd(pAdapter, cmd32);
}
u32 r8712_bb_reg_read(struct _adapter *pAdapter, u16 offset)
{
u8 shift = offset & 0x0003;
u16 bb_addr = offset & 0x0FFC;
u32 bb_val = 0;
struct IOCMD_STRUCT iocmd;
iocmd.cmdclass = IOCMD_CLASS_BB_RF;
iocmd.value = bb_addr;
iocmd.index = IOCMD_BB_READ_IDX;
bb_val = fw_iocmd_read(pAdapter, iocmd);
if (shift != 0) {
u32 bb_val2 = 0;
bb_val >>= (shift * 8);
iocmd.value += 4;
bb_val2 = fw_iocmd_read(pAdapter, iocmd);
bb_val2 <<= ((4 - shift) * 8);
bb_val |= bb_val2;
}
return bb_val;
}
u8 r8712_bb_reg_write(struct _adapter *pAdapter, u16 offset, u32 value)
{
u8 shift = offset & 0x0003;
u16 bb_addr = offset & 0x0FFC;
struct IOCMD_STRUCT iocmd;
iocmd.cmdclass = IOCMD_CLASS_BB_RF;
iocmd.value = bb_addr;
iocmd.index = IOCMD_BB_WRITE_IDX;
if (shift != 0) {
u32 oldValue = 0;
u32 newValue = value;
oldValue = r8712_bb_reg_read(pAdapter, iocmd.value);
oldValue &= (0xFFFFFFFF >> ((4 - shift) * 8));
value = oldValue | (newValue << (shift * 8));
if (fw_iocmd_write(pAdapter, iocmd, value) == false)
return false;
iocmd.value += 4;
oldValue = r8712_bb_reg_read(pAdapter, iocmd.value);
oldValue &= (0xFFFFFFFF << (shift * 8));
value = oldValue | (newValue >> ((4 - shift) * 8));
}
return fw_iocmd_write(pAdapter, iocmd, value);
}
u32 r8712_rf_reg_read(struct _adapter *pAdapter, u8 path, u8 offset)
{
u16 rf_addr = (path << 8) | offset;
struct IOCMD_STRUCT iocmd;
iocmd.cmdclass = IOCMD_CLASS_BB_RF;
iocmd.value = rf_addr;
iocmd.index = IOCMD_RF_READ_IDX;
return fw_iocmd_read(pAdapter, iocmd);
}
u8 r8712_rf_reg_write(struct _adapter *pAdapter, u8 path, u8 offset, u32 value)
{
u16 rf_addr = (path << 8) | offset;
struct IOCMD_STRUCT iocmd;
iocmd.cmdclass = IOCMD_CLASS_BB_RF;
iocmd.value = rf_addr;
iocmd.index = IOCMD_RF_WRIT_IDX;
return fw_iocmd_write(pAdapter, iocmd, value);
}
static u32 bitshift(u32 bitmask)
{
u32 i;
for (i = 0; i <= 31; i++)
if (((bitmask>>i) & 0x1) == 1)
break;
return i;
}
static u32 get_bb_reg(struct _adapter *pAdapter, u16 offset, u32 bitmask)
{
u32 org_value, bit_shift, new_value;
org_value = r8712_bb_reg_read(pAdapter, offset);
bit_shift = bitshift(bitmask);
new_value = (org_value & bitmask) >> bit_shift;
return new_value;
}
static u8 set_bb_reg(struct _adapter *pAdapter,
u16 offset,
u32 bitmask,
u32 value)
{
u32 org_value, bit_shift, new_value;
if (bitmask != bMaskDWord) {
org_value = r8712_bb_reg_read(pAdapter, offset);
bit_shift = bitshift(bitmask);
new_value = ((org_value & (~bitmask)) | (value << bit_shift));
} else
new_value = value;
return r8712_bb_reg_write(pAdapter, offset, new_value);
}
static u32 get_rf_reg(struct _adapter *pAdapter, u8 path, u8 offset,
u32 bitmask)
{
u32 org_value, bit_shift, new_value;
org_value = r8712_rf_reg_read(pAdapter, path, offset);
bit_shift = bitshift(bitmask);
new_value = (org_value & bitmask) >> bit_shift;
return new_value;
}
static u8 set_rf_reg(struct _adapter *pAdapter, u8 path, u8 offset, u32 bitmask,
u32 value)
{
u32 org_value, bit_shift, new_value;
if (bitmask != bMaskDWord) {
org_value = r8712_rf_reg_read(pAdapter, path, offset);
bit_shift = bitshift(bitmask);
new_value = ((org_value & (~bitmask)) | (value << bit_shift));
} else
new_value = value;
return r8712_rf_reg_write(pAdapter, path, offset, new_value);
}
void r8712_SetChannel(struct _adapter *pAdapter)
{
struct cmd_priv *pcmdpriv = &pAdapter->cmdpriv;
struct cmd_obj *pcmd = NULL;
struct SetChannel_parm *pparm = NULL;
u16 code = GEN_CMD_CODE(_SetChannel);
pcmd = kmalloc(sizeof(*pcmd), GFP_ATOMIC);
if (pcmd == NULL)
return;
pparm = kmalloc(sizeof(*pparm), GFP_ATOMIC);
if (pparm == NULL) {
kfree(pcmd);
return;
}
pparm->curr_ch = pAdapter->mppriv.curr_ch;
init_h2fwcmd_w_parm_no_rsp(pcmd, pparm, code);
r8712_enqueue_cmd(pcmdpriv, pcmd);
}
static void SetCCKTxPower(struct _adapter *pAdapter, u8 TxPower)
{
u16 TxAGC = 0;
TxAGC = TxPower;
set_bb_reg(pAdapter, rTxAGC_CCK_Mcs32, bTxAGCRateCCK, TxAGC);
}
static void SetOFDMTxPower(struct _adapter *pAdapter, u8 TxPower)
{
u32 TxAGC = 0;
TxAGC |= ((TxPower<<24)|(TxPower<<16)|(TxPower<<8)|TxPower);
set_bb_reg(pAdapter, rTxAGC_Rate18_06, bTxAGCRate18_06, TxAGC);
set_bb_reg(pAdapter, rTxAGC_Rate54_24, bTxAGCRate54_24, TxAGC);
set_bb_reg(pAdapter, rTxAGC_Mcs03_Mcs00, bTxAGCRateMCS3_MCS0, TxAGC);
set_bb_reg(pAdapter, rTxAGC_Mcs07_Mcs04, bTxAGCRateMCS7_MCS4, TxAGC);
set_bb_reg(pAdapter, rTxAGC_Mcs11_Mcs08, bTxAGCRateMCS11_MCS8, TxAGC);
set_bb_reg(pAdapter, rTxAGC_Mcs15_Mcs12, bTxAGCRateMCS15_MCS12, TxAGC);
}
void r8712_SetTxPower(struct _adapter *pAdapter)
{
u8 TxPower = pAdapter->mppriv.curr_txpoweridx;
SetCCKTxPower(pAdapter, TxPower);
SetOFDMTxPower(pAdapter, TxPower);
}
void r8712_SetTxAGCOffset(struct _adapter *pAdapter, u32 ulTxAGCOffset)
{
u32 TxAGCOffset_B, TxAGCOffset_C, TxAGCOffset_D, tmpAGC;
TxAGCOffset_B = (ulTxAGCOffset&0x000000ff);
TxAGCOffset_C = ((ulTxAGCOffset&0x0000ff00)>>8);
TxAGCOffset_D = ((ulTxAGCOffset&0x00ff0000)>>16);
tmpAGC = (TxAGCOffset_D<<8 | TxAGCOffset_C<<4 | TxAGCOffset_B);
set_bb_reg(pAdapter, rFPGA0_TxGainStage,
(bXBTxAGC|bXCTxAGC|bXDTxAGC), tmpAGC);
}
void r8712_SetDataRate(struct _adapter *pAdapter)
{
u8 path = RF_PATH_A;
u8 offset = RF_SYN_G2;
u32 value;
value = (pAdapter->mppriv.curr_rateidx < 4) ? 0x4440 : 0xF200;
r8712_rf_reg_write(pAdapter, path, offset, value);
}
void r8712_SwitchBandwidth(struct _adapter *pAdapter)
{
u8 regBwOpMode = 0;
u8 Bandwidth = pAdapter->mppriv.curr_bandwidth;
regBwOpMode = r8712_read8(pAdapter, 0x10250203);
if (Bandwidth == HT_CHANNEL_WIDTH_20)
regBwOpMode |= BIT(2);
else
regBwOpMode &= ~(BIT(2));
r8712_write8(pAdapter, 0x10250203, regBwOpMode);
switch (Bandwidth) {
case HT_CHANNEL_WIDTH_20:
set_bb_reg(pAdapter, rFPGA0_RFMOD, bRFMOD, 0x0);
set_bb_reg(pAdapter, rFPGA1_RFMOD, bRFMOD, 0x0);
set_bb_reg(pAdapter, rFPGA0_AnalogParameter2, bMaskDWord, 0x58);
break;
case HT_CHANNEL_WIDTH_40:
set_bb_reg(pAdapter, rFPGA0_RFMOD, bRFMOD, 0x1);
set_bb_reg(pAdapter, rFPGA1_RFMOD, bRFMOD, 0x1);
set_bb_reg(pAdapter, rCCK0_System, bCCKSideBand,
(HAL_PRIME_CHNL_OFFSET_DONT_CARE>>1));
set_bb_reg(pAdapter, rOFDM1_LSTF, 0xC00,
HAL_PRIME_CHNL_OFFSET_DONT_CARE);
set_bb_reg(pAdapter, rFPGA0_AnalogParameter2, bMaskDWord, 0x18);
break;
default:
break;
}
switch (Bandwidth) {
case HT_CHANNEL_WIDTH_20:
set_rf_reg(pAdapter, RF_PATH_A, RF_CHNLBW,
BIT(10) | BIT(11), 0x01);
break;
case HT_CHANNEL_WIDTH_40:
set_rf_reg(pAdapter, RF_PATH_A, RF_CHNLBW,
BIT(10) | BIT(11), 0x00);
break;
default:
break;
}
}
void r8712_SwitchAntenna(struct _adapter *pAdapter)
{
u32 ofdm_tx_en_val = 0, ofdm_tx_ant_sel_val = 0;
u8 ofdm_rx_ant_sel_val = 0;
u8 cck_ant_select_val = 0;
u32 cck_ant_sel_val = 0;
struct R_ANTENNA_SELECT_CCK *p_cck_txrx;
p_cck_txrx = (struct R_ANTENNA_SELECT_CCK *)&cck_ant_select_val;
switch (pAdapter->mppriv.antenna_tx) {
case ANTENNA_A:
set_bb_reg(pAdapter, rFPGA0_XA_HSSIParameter2, 0xe, 2);
set_bb_reg(pAdapter, rFPGA0_XB_HSSIParameter2, 0xe, 1);
ofdm_tx_en_val = 0x3;
ofdm_tx_ant_sel_val = 0x11111111;
p_cck_txrx->r_ccktx_enable = 0x8;
break;
case ANTENNA_B:
set_bb_reg(pAdapter, rFPGA0_XA_HSSIParameter2, 0xe, 1);
set_bb_reg(pAdapter, rFPGA0_XB_HSSIParameter2, 0xe, 2);
ofdm_tx_en_val = 0x3;
ofdm_tx_ant_sel_val = 0x22222222;
p_cck_txrx->r_ccktx_enable = 0x4;
break;
case ANTENNA_AB:
set_bb_reg(pAdapter, rFPGA0_XA_HSSIParameter2, 0xe, 2);
set_bb_reg(pAdapter, rFPGA0_XB_HSSIParameter2, 0xe, 2);
ofdm_tx_en_val = 0x3;
ofdm_tx_ant_sel_val = 0x3321333;
p_cck_txrx->r_ccktx_enable = 0xC;
break;
default:
break;
}
set_bb_reg(pAdapter, rFPGA1_TxInfo, 0xffffffff, ofdm_tx_ant_sel_val);
set_bb_reg(pAdapter, rFPGA0_TxInfo, 0x0000000f, ofdm_tx_en_val);
switch (pAdapter->mppriv.antenna_rx) {
case ANTENNA_A:
ofdm_rx_ant_sel_val = 0x1;
p_cck_txrx->r_cckrx_enable = 0x0;
p_cck_txrx->r_cckrx_enable_2 = 0x0;
break;
case ANTENNA_B:
ofdm_rx_ant_sel_val = 0x2;
p_cck_txrx->r_cckrx_enable = 0x1;
p_cck_txrx->r_cckrx_enable_2 = 0x1;
break;
case ANTENNA_AB:
ofdm_rx_ant_sel_val = 0x3;
p_cck_txrx->r_cckrx_enable = 0x0;
p_cck_txrx->r_cckrx_enable_2 = 0x1;
break;
default:
break;
}
set_bb_reg(pAdapter, rOFDM0_TRxPathEnable, 0x0000000f,
ofdm_rx_ant_sel_val);
set_bb_reg(pAdapter, rOFDM1_TRxPathEnable, 0x0000000f,
ofdm_rx_ant_sel_val);
cck_ant_sel_val = cck_ant_select_val;
set_bb_reg(pAdapter, rCCK0_AFESetting, bMaskByte3, cck_ant_sel_val);
}
void r8712_SetCrystalCap(struct _adapter *pAdapter)
{
set_bb_reg(pAdapter, rFPGA0_AnalogParameter1, bXtalCap,
pAdapter->mppriv.curr_crystalcap);
}
static void TriggerRFThermalMeter(struct _adapter *pAdapter)
{
set_rf_reg(pAdapter, RF_PATH_A, RF_T_METER, bRFRegOffsetMask, 0x60);
}
static u32 ReadRFThermalMeter(struct _adapter *pAdapter)
{
return get_rf_reg(pAdapter, RF_PATH_A, RF_T_METER, 0x1F);
}
void r8712_GetThermalMeter(struct _adapter *pAdapter, u32 *value)
{
TriggerRFThermalMeter(pAdapter);
msleep(1000);
*value = ReadRFThermalMeter(pAdapter);
}
void r8712_SetSingleCarrierTx(struct _adapter *pAdapter, u8 bStart)
{
if (bStart) {
if (!get_bb_reg(pAdapter, rFPGA0_RFMOD, bOFDMEn))
set_bb_reg(pAdapter, rFPGA0_RFMOD, bOFDMEn, bEnable);
set_bb_reg(pAdapter, rCCK0_System, bCCKBBMode, bDisable);
set_bb_reg(pAdapter, rCCK0_System, bCCKScramble, bEnable);
set_bb_reg(pAdapter, rOFDM1_LSTF, bOFDMContinueTx, bDisable);
set_bb_reg(pAdapter, rOFDM1_LSTF, bOFDMSingleCarrier, bEnable);
set_bb_reg(pAdapter, rOFDM1_LSTF, bOFDMSingleTone, bDisable);
} else {
set_bb_reg(pAdapter, rOFDM1_LSTF, bOFDMContinueTx, bDisable);
set_bb_reg(pAdapter, rOFDM1_LSTF, bOFDMSingleCarrier,
bDisable);
set_bb_reg(pAdapter, rOFDM1_LSTF, bOFDMSingleTone, bDisable);
msleep(20);
set_bb_reg(pAdapter, rPMAC_Reset, bBBResetB, 0x0);
set_bb_reg(pAdapter, rPMAC_Reset, bBBResetB, 0x1);
}
}
void r8712_SetSingleToneTx(struct _adapter *pAdapter, u8 bStart)
{
u8 rfPath = pAdapter->mppriv.curr_rfpath;
switch (pAdapter->mppriv.antenna_tx) {
case ANTENNA_B:
rfPath = RF_PATH_B;
break;
case ANTENNA_A:
default:
rfPath = RF_PATH_A;
break;
}
if (bStart) {
set_bb_reg(pAdapter, rFPGA0_RFMOD, bCCKEn, bDisable);
set_bb_reg(pAdapter, rFPGA0_RFMOD, bOFDMEn, bDisable);
set_rf_reg(pAdapter, rfPath, RF_TX_G2, bRFRegOffsetMask,
0xd4000);
msleep(100);
set_rf_reg(pAdapter, rfPath, RF_AC, bRFRegOffsetMask, 0x2001f);
msleep(100);
} else {
set_bb_reg(pAdapter, rFPGA0_RFMOD, bCCKEn, bEnable);
set_bb_reg(pAdapter, rFPGA0_RFMOD, bOFDMEn, bEnable);
set_rf_reg(pAdapter, rfPath, RF_TX_G2, bRFRegOffsetMask,
0x54000);
msleep(100);
set_rf_reg(pAdapter, rfPath, RF_AC, bRFRegOffsetMask, 0x30000);
msleep(100);
}
}
void r8712_SetCarrierSuppressionTx(struct _adapter *pAdapter, u8 bStart)
{
if (bStart) {
if (pAdapter->mppriv.curr_rateidx <= MPT_RATE_11M) {
if (!get_bb_reg(pAdapter, rFPGA0_RFMOD, bCCKEn)) {
set_bb_reg(pAdapter, rFPGA0_RFMOD, bCCKEn,
bEnable);
}
set_bb_reg(pAdapter, rOFDM1_LSTF, bOFDMContinueTx,
bDisable);
set_bb_reg(pAdapter, rOFDM1_LSTF, bOFDMSingleCarrier,
bDisable);
set_bb_reg(pAdapter, rOFDM1_LSTF, bOFDMSingleTone,
bDisable);
set_bb_reg(pAdapter, rCCK0_System, bCCKBBMode, 0x2);
set_bb_reg(pAdapter, rCCK0_System, bCCKScramble,
bDisable);
set_bb_reg(pAdapter, rCCK0_System, bCCKTxRate, 0x0);
}
} else {
if (pAdapter->mppriv.curr_rateidx <= MPT_RATE_11M) {
set_bb_reg(pAdapter, rCCK0_System, bCCKBBMode, 0x0);
set_bb_reg(pAdapter, rCCK0_System, bCCKScramble,
bEnable);
set_bb_reg(pAdapter, rPMAC_Reset, bBBResetB, 0x0);
set_bb_reg(pAdapter, rPMAC_Reset, bBBResetB, 0x1);
}
}
}
static void SetCCKContinuousTx(struct _adapter *pAdapter, u8 bStart)
{
u32 cckrate;
if (bStart) {
if (!get_bb_reg(pAdapter, rFPGA0_RFMOD, bCCKEn)) {
set_bb_reg(pAdapter, rFPGA0_RFMOD, bCCKEn, bEnable);
}
set_bb_reg(pAdapter, rOFDM1_LSTF, bOFDMContinueTx, bDisable);
set_bb_reg(pAdapter, rOFDM1_LSTF, bOFDMSingleCarrier, bDisable);
set_bb_reg(pAdapter, rOFDM1_LSTF, bOFDMSingleTone, bDisable);
cckrate = pAdapter->mppriv.curr_rateidx;
set_bb_reg(pAdapter, rCCK0_System, bCCKTxRate, cckrate);
set_bb_reg(pAdapter, rCCK0_System, bCCKBBMode, 0x2);
set_bb_reg(pAdapter, rCCK0_System, bCCKScramble, bEnable);
} else {
set_bb_reg(pAdapter, rCCK0_System, bCCKBBMode, 0x0);
set_bb_reg(pAdapter, rCCK0_System, bCCKScramble, bEnable);
set_bb_reg(pAdapter, rPMAC_Reset, bBBResetB, 0x0);
set_bb_reg(pAdapter, rPMAC_Reset, bBBResetB, 0x1);
}
}
static void SetOFDMContinuousTx(struct _adapter *pAdapter, u8 bStart)
{
if (bStart) {
if (!get_bb_reg(pAdapter, rFPGA0_RFMOD, bOFDMEn)) {
set_bb_reg(pAdapter, rFPGA0_RFMOD, bOFDMEn, bEnable);
}
set_bb_reg(pAdapter, rCCK0_System, bCCKBBMode, bDisable);
set_bb_reg(pAdapter, rCCK0_System, bCCKScramble, bEnable);
set_bb_reg(pAdapter, rOFDM1_LSTF, bOFDMContinueTx, bEnable);
set_bb_reg(pAdapter, rOFDM1_LSTF, bOFDMSingleCarrier, bDisable);
set_bb_reg(pAdapter, rOFDM1_LSTF, bOFDMSingleTone, bDisable);
} else {
set_bb_reg(pAdapter, rOFDM1_LSTF, bOFDMContinueTx, bDisable);
set_bb_reg(pAdapter, rOFDM1_LSTF, bOFDMSingleCarrier,
bDisable);
set_bb_reg(pAdapter, rOFDM1_LSTF, bOFDMSingleTone, bDisable);
msleep(20);
set_bb_reg(pAdapter, rPMAC_Reset, bBBResetB, 0x0);
set_bb_reg(pAdapter, rPMAC_Reset, bBBResetB, 0x1);
}
}
void r8712_SetContinuousTx(struct _adapter *pAdapter, u8 bStart)
{
if (bStart) {
r8712_bb_reg_write(pAdapter, rRx_Wait_CCCA,
r8712_bb_reg_read(pAdapter,
rRx_Wait_CCCA) & 0xFE1FFFFF);
msleep(100);
}
if (pAdapter->mppriv.curr_rateidx <= MPT_RATE_11M)
SetCCKContinuousTx(pAdapter, bStart);
else if ((pAdapter->mppriv.curr_rateidx >= MPT_RATE_6M) &&
(pAdapter->mppriv.curr_rateidx <= MPT_RATE_MCS15))
SetOFDMContinuousTx(pAdapter, bStart);
if (!bStart)
r8712_bb_reg_write(pAdapter, rRx_Wait_CCCA,
r8712_bb_reg_read(pAdapter,
rRx_Wait_CCCA) | 0x01E00000);
}
void r8712_ResetPhyRxPktCount(struct _adapter *pAdapter)
{
u32 i, phyrx_set = 0;
for (i = OFDM_PPDU_BIT; i <= HT_MPDU_FAIL_BIT; i++) {
phyrx_set = 0;
phyrx_set |= (i << 28);
phyrx_set |= 0x08000000;
r8712_write32(pAdapter, RXERR_RPT, phyrx_set);
}
}
static u32 GetPhyRxPktCounts(struct _adapter *pAdapter, u32 selbit)
{
u32 phyrx_set = 0, count = 0;
u32 SelectBit;
SelectBit = selbit << 28;
phyrx_set |= (SelectBit & 0xF0000000);
r8712_write32(pAdapter, RXERR_RPT, phyrx_set);
count = r8712_read32(pAdapter, RXERR_RPT) & RPTMaxCount;
return count;
}
u32 r8712_GetPhyRxPktReceived(struct _adapter *pAdapter)
{
u32 OFDM_cnt = 0, CCK_cnt = 0, HT_cnt = 0;
OFDM_cnt = GetPhyRxPktCounts(pAdapter, OFDM_MPDU_OK_BIT);
CCK_cnt = GetPhyRxPktCounts(pAdapter, CCK_MPDU_OK_BIT);
HT_cnt = GetPhyRxPktCounts(pAdapter, HT_MPDU_OK_BIT);
return OFDM_cnt + CCK_cnt + HT_cnt;
}
u32 r8712_GetPhyRxPktCRC32Error(struct _adapter *pAdapter)
{
u32 OFDM_cnt = 0, CCK_cnt = 0, HT_cnt = 0;
OFDM_cnt = GetPhyRxPktCounts(pAdapter, OFDM_MPDU_FAIL_BIT);
CCK_cnt = GetPhyRxPktCounts(pAdapter, CCK_MPDU_FAIL_BIT);
HT_cnt = GetPhyRxPktCounts(pAdapter, HT_MPDU_FAIL_BIT);
return OFDM_cnt + CCK_cnt + HT_cnt;
}
