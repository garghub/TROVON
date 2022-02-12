static void _FWDownloadEnable(struct rtw_adapter *padapter, bool enable)
{
u8 tmp;
if (enable) {
tmp = rtl8723au_read8(padapter, REG_SYS_FUNC_EN + 1);
rtl8723au_write8(padapter, REG_SYS_FUNC_EN + 1, tmp | 0x04);
tmp = rtl8723au_read8(padapter, REG_MCUFWDL);
rtl8723au_write8(padapter, REG_MCUFWDL, tmp | 0x01);
tmp = rtl8723au_read8(padapter, REG_MCUFWDL + 2);
rtl8723au_write8(padapter, REG_MCUFWDL + 2, tmp & 0xf7);
} else {
tmp = rtl8723au_read8(padapter, REG_MCUFWDL);
rtl8723au_write8(padapter, REG_MCUFWDL, tmp & 0xfe);
rtl8723au_write8(padapter, REG_MCUFWDL + 1, 0x00);
}
}
static int
_PageWrite(struct rtw_adapter *padapter, u32 page, void *buffer, u32 size)
{
u8 value8;
u8 u8Page = (u8) (page & 0x07);
if (size > MAX_PAGE_SIZE)
return _FAIL;
value8 = (rtl8723au_read8(padapter, REG_MCUFWDL + 2) & 0xF8) | u8Page;
rtl8723au_write8(padapter, REG_MCUFWDL + 2, value8);
return rtl8723au_writeN(padapter, FW_8723A_START_ADDRESS, size, buffer);
}
static int _WriteFW(struct rtw_adapter *padapter, void *buffer, u32 size)
{
int ret = _SUCCESS;
u32 pageNums, remainSize;
u32 page, offset;
u8 *bufferPtr = (u8 *) buffer;
pageNums = size / MAX_PAGE_SIZE;
remainSize = size % MAX_PAGE_SIZE;
for (page = 0; page < pageNums; page++) {
offset = page * MAX_PAGE_SIZE;
ret = _PageWrite(padapter, page, bufferPtr + offset,
MAX_PAGE_SIZE);
if (ret == _FAIL)
goto exit;
}
if (remainSize) {
offset = pageNums * MAX_PAGE_SIZE;
page = pageNums;
ret = _PageWrite(padapter, page, bufferPtr + offset,
remainSize);
if (ret == _FAIL)
goto exit;
}
RT_TRACE(_module_hal_init_c_, _drv_info_,
"_WriteFW Done- for Normal chip.\n");
exit:
return ret;
}
static int _FWFreeToGo(struct rtw_adapter *padapter)
{
u32 counter = 0;
u32 value32;
do {
value32 = rtl8723au_read32(padapter, REG_MCUFWDL);
if (value32 & FWDL_ChkSum_rpt)
break;
} while (counter++ < POLLING_READY_TIMEOUT_COUNT);
if (counter >= POLLING_READY_TIMEOUT_COUNT) {
RT_TRACE(_module_hal_init_c_, _drv_err_,
"%s: chksum report fail! REG_MCUFWDL:0x%08x\n",
__func__, value32);
return _FAIL;
}
RT_TRACE(_module_hal_init_c_, _drv_info_,
"%s: Checksum report OK! REG_MCUFWDL:0x%08x\n", __func__,
value32);
value32 = rtl8723au_read32(padapter, REG_MCUFWDL);
value32 |= MCUFWDL_RDY;
value32 &= ~WINTINI_RDY;
rtl8723au_write32(padapter, REG_MCUFWDL, value32);
counter = 0;
do {
value32 = rtl8723au_read32(padapter, REG_MCUFWDL);
if (value32 & WINTINI_RDY) {
RT_TRACE(_module_hal_init_c_, _drv_info_,
"%s: Polling FW ready success!! REG_MCUFWDL:0x%08x\n",
__func__, value32);
return _SUCCESS;
}
udelay(5);
} while (counter++ < POLLING_READY_TIMEOUT_COUNT);
RT_TRACE(_module_hal_init_c_, _drv_err_,
"%s: Polling FW ready fail!! REG_MCUFWDL:0x%08x\n",
__func__, value32);
return _FAIL;
}
void rtl8723a_FirmwareSelfReset(struct rtw_adapter *padapter)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(padapter);
u8 u1bTmp;
u8 Delay = 100;
if (!(IS_FW_81xxC(padapter) &&
((pHalData->FirmwareVersion < 0x21) ||
(pHalData->FirmwareVersion == 0x21 &&
pHalData->FirmwareSubVersion < 0x01)))) {
rtl8723au_write8(padapter, REG_HMETFR + 3, 0x20);
u1bTmp = rtl8723au_read8(padapter, REG_SYS_FUNC_EN + 1);
while (u1bTmp & BIT(2)) {
Delay--;
if (Delay == 0)
break;
udelay(50);
u1bTmp = rtl8723au_read8(padapter, REG_SYS_FUNC_EN + 1);
}
RT_TRACE(_module_hal_init_c_, _drv_info_,
"-%s: 8051 reset success (%d)\n", __func__,
Delay);
if ((Delay == 0)) {
u1bTmp = rtl8723au_read8(padapter, REG_SYS_FUNC_EN + 1);
rtl8723au_write8(padapter, REG_SYS_FUNC_EN + 1,
u1bTmp & ~BIT(2));
}
}
}
int rtl8723a_FirmwareDownload(struct rtw_adapter *padapter)
{
int rtStatus = _SUCCESS;
u8 writeFW_retry = 0;
unsigned long fwdl_start_time;
struct hal_data_8723a *pHalData = GET_HAL_DATA(padapter);
struct dvobj_priv *dvobj = adapter_to_dvobj(padapter);
struct device *device = dvobj_to_dev(dvobj);
struct rt_8723a_firmware_hdr *pFwHdr = NULL;
const struct firmware *fw;
char *fw_name;
u8 *firmware_buf = NULL;
u8 *buf;
int fw_size;
static int log_version;
RT_TRACE(_module_hal_init_c_, _drv_info_, "+%s\n", __func__);
if (IS_8723A_A_CUT(pHalData->VersionID)) {
fw_name = "rtlwifi/rtl8723aufw_A.bin";
RT_TRACE(_module_hal_init_c_, _drv_info_,
"rtl8723a_FirmwareDownload: R8723FwImageArray_UMC for RTL8723A A CUT\n");
} else if (IS_8723A_B_CUT(pHalData->VersionID)) {
if (padapter->registrypriv.wifi_spec == 1) {
fw_name = "rtlwifi/rtl8723aufw_B_NoBT.bin";
DBG_8723A(" Rtl8723_FwUMCBCutImageArrayWithoutBT for "
"RTL8723A B CUT\n");
} else {
if (rtl8723a_BT_coexist(padapter)) {
fw_name = "rtlwifi/rtl8723aufw_B.bin";
DBG_8723A(" Rtl8723_FwUMCBCutImageArrayWithBT "
"for RTL8723A B CUT\n");
} else {
fw_name = "rtlwifi/rtl8723aufw_B_NoBT.bin";
DBG_8723A(" Rtl8723_FwUMCBCutImageArrayWithout "
"BT for RTL8723A B CUT\n");
}
}
} else {
RT_TRACE(_module_hal_init_c_, _drv_err_,
"%s: unknown version!\n", __func__);
rtStatus = _FAIL;
goto Exit;
}
pr_info("rtl8723au: Loading firmware %s\n", fw_name);
if (request_firmware(&fw, fw_name, device)) {
pr_err("rtl8723au: request_firmware load failed\n");
rtStatus = _FAIL;
goto Exit;
}
if (!fw) {
pr_err("rtl8723au: Firmware %s not available\n", fw_name);
rtStatus = _FAIL;
goto Exit;
}
firmware_buf = kmemdup(fw->data, fw->size, GFP_KERNEL);
if (!firmware_buf) {
rtStatus = _FAIL;
goto Exit;
}
buf = firmware_buf;
fw_size = fw->size;
release_firmware(fw);
pFwHdr = (struct rt_8723a_firmware_hdr *)firmware_buf;
pHalData->FirmwareVersion = le16_to_cpu(pFwHdr->Version);
pHalData->FirmwareSubVersion = pFwHdr->Subversion;
pHalData->FirmwareSignature = le16_to_cpu(pFwHdr->Signature);
DBG_8723A("%s: fw_ver =%d fw_subver =%d sig = 0x%x\n",
__func__, pHalData->FirmwareVersion,
pHalData->FirmwareSubVersion, pHalData->FirmwareSignature);
if (!log_version++)
pr_info("%sFirmware Version %d, SubVersion %d, Signature "
"0x%x\n", DRIVER_PREFIX, pHalData->FirmwareVersion,
pHalData->FirmwareSubVersion,
pHalData->FirmwareSignature);
if (IS_FW_HEADER_EXIST(pFwHdr)) {
buf = buf + 32;
fw_size = fw_size - 32;
}
if (rtl8723au_read8(padapter, REG_MCUFWDL) & RAM_DL_SEL) {
rtl8723a_FirmwareSelfReset(padapter);
rtl8723au_write8(padapter, REG_MCUFWDL, 0x00);
}
_FWDownloadEnable(padapter, true);
fwdl_start_time = jiffies;
while (1) {
rtl8723au_write8(padapter, REG_MCUFWDL,
rtl8723au_read8(padapter, REG_MCUFWDL) |
FWDL_ChkSum_rpt);
rtStatus = _WriteFW(padapter, buf, fw_size);
if (rtStatus == _SUCCESS ||
(jiffies_to_msecs(jiffies - fwdl_start_time) > 500 &&
writeFW_retry++ >= 3))
break;
DBG_8723A("%s writeFW_retry:%u, time after fwdl_start_time:"
"%ums\n", __func__, writeFW_retry,
jiffies_to_msecs(jiffies - fwdl_start_time));
}
_FWDownloadEnable(padapter, false);
if (_SUCCESS != rtStatus) {
DBG_8723A("DL Firmware failed!\n");
goto Exit;
}
rtStatus = _FWFreeToGo(padapter);
if (_SUCCESS != rtStatus) {
RT_TRACE(_module_hal_init_c_, _drv_err_,
"DL Firmware failed!\n");
goto Exit;
}
RT_TRACE(_module_hal_init_c_, _drv_info_,
"Firmware is ready to run!\n");
Exit:
kfree(firmware_buf);
return rtStatus;
}
void rtl8723a_InitializeFirmwareVars(struct rtw_adapter *padapter)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(padapter);
padapter->pwrctrlpriv.bFwCurrentInPSMode = false;
pHalData->LastHMEBoxNum = 0;
}
static u8
hal_EfuseSwitchToBank(struct rtw_adapter *padapter, u8 bank)
{
u8 bRet = false;
u32 value32 = 0;
DBG_8723A("%s: Efuse switch bank to %d\n", __func__, bank);
value32 = rtl8723au_read32(padapter, EFUSE_TEST);
bRet = true;
switch (bank) {
case 0:
value32 = (value32 & ~EFUSE_SEL_MASK) |
EFUSE_SEL(EFUSE_WIFI_SEL_0);
break;
case 1:
value32 = (value32 & ~EFUSE_SEL_MASK) |
EFUSE_SEL(EFUSE_BT_SEL_0);
break;
case 2:
value32 = (value32 & ~EFUSE_SEL_MASK) |
EFUSE_SEL(EFUSE_BT_SEL_1);
break;
case 3:
value32 = (value32 & ~EFUSE_SEL_MASK) |
EFUSE_SEL(EFUSE_BT_SEL_2);
break;
default:
value32 = (value32 & ~EFUSE_SEL_MASK) |
EFUSE_SEL(EFUSE_WIFI_SEL_0);
bRet = false;
break;
}
rtl8723au_write32(padapter, EFUSE_TEST, value32);
return bRet;
}
static void
hal_ReadEFuse_WiFi(struct rtw_adapter *padapter,
u16 _offset, u16 _size_byte, u8 *pbuf)
{
u8 *efuseTbl = NULL;
u16 eFuse_Addr = 0;
u8 offset, wden;
u8 efuseHeader, efuseExtHdr, efuseData;
u16 i, total, used;
struct hal_data_8723a *pHalData = GET_HAL_DATA(padapter);
if ((_offset + _size_byte) > EFUSE_MAP_LEN_8723A) {
DBG_8723A("%s: Invalid offset(%#x) with read bytes(%#x)!!\n",
__func__, _offset, _size_byte);
return;
}
efuseTbl = kmalloc(EFUSE_MAP_LEN_8723A, GFP_KERNEL);
if (efuseTbl == NULL) {
DBG_8723A("%s: alloc efuseTbl fail!\n", __func__);
return;
}
memset(efuseTbl, 0xFF, EFUSE_MAP_LEN_8723A);
hal_EfuseSwitchToBank(padapter, 0);
while (AVAILABLE_EFUSE_ADDR(eFuse_Addr)) {
ReadEFuseByte23a(padapter, eFuse_Addr++, &efuseHeader);
if (efuseHeader == 0xFF) {
DBG_8723A("%s: data end at address =%#x\n", __func__,
eFuse_Addr);
break;
}
if (EXT_HEADER(efuseHeader)) {
offset = GET_HDR_OFFSET_2_0(efuseHeader);
ReadEFuseByte23a(padapter, eFuse_Addr++, &efuseExtHdr);
if (ALL_WORDS_DISABLED(efuseExtHdr))
continue;
offset |= ((efuseExtHdr & 0xF0) >> 1);
wden = efuseExtHdr & 0x0F;
} else {
offset = (efuseHeader >> 4) & 0x0f;
wden = efuseHeader & 0x0f;
}
if (offset < EFUSE_MAX_SECTION_8723A) {
u16 addr;
addr = offset * PGPKT_DATA_SIZE;
for (i = 0; i < EFUSE_MAX_WORD_UNIT; i++) {
if (!(wden & (0x01 << i))) {
ReadEFuseByte23a(padapter, eFuse_Addr++,
&efuseData);
efuseTbl[addr] = efuseData;
ReadEFuseByte23a(padapter, eFuse_Addr++,
&efuseData);
efuseTbl[addr + 1] = efuseData;
}
addr += 2;
}
} else {
DBG_8723A(KERN_ERR "%s: offset(%d) is illegal!!\n",
__func__, offset);
eFuse_Addr += Efuse_CalculateWordCnts23a(wden) * 2;
}
}
for (i = 0; i < _size_byte; i++)
pbuf[i] = efuseTbl[_offset + i];
EFUSE_GetEfuseDefinition23a(padapter, EFUSE_WIFI,
TYPE_AVAILABLE_EFUSE_BYTES_TOTAL, &total);
used = eFuse_Addr - 1;
pHalData->EfuseUsedBytes = used;
kfree(efuseTbl);
}
static void
hal_ReadEFuse_BT(struct rtw_adapter *padapter,
u16 _offset, u16 _size_byte, u8 *pbuf)
{
u8 *efuseTbl;
u8 bank;
u16 eFuse_Addr;
u8 efuseHeader, efuseExtHdr, efuseData;
u8 offset, wden;
u16 i, total, used;
struct hal_data_8723a *pHalData = GET_HAL_DATA(padapter);
if ((_offset + _size_byte) > EFUSE_BT_MAP_LEN) {
DBG_8723A("%s: Invalid offset(%#x) with read bytes(%#x)!!\n",
__func__, _offset, _size_byte);
return;
}
efuseTbl = kmalloc(EFUSE_BT_MAP_LEN, GFP_KERNEL);
if (efuseTbl == NULL) {
DBG_8723A("%s: efuseTbl malloc fail!\n", __func__);
return;
}
memset(efuseTbl, 0xFF, EFUSE_BT_MAP_LEN);
EFUSE_GetEfuseDefinition23a(padapter, EFUSE_BT,
TYPE_AVAILABLE_EFUSE_BYTES_BANK, &total);
for (bank = 1; bank < EFUSE_MAX_BANK; bank++) {
if (hal_EfuseSwitchToBank(padapter, bank) == false) {
DBG_8723A("%s: hal_EfuseSwitchToBank Fail!!\n",
__func__);
goto exit;
}
eFuse_Addr = 0;
while (AVAILABLE_EFUSE_ADDR(eFuse_Addr)) {
ReadEFuseByte23a(padapter, eFuse_Addr++, &efuseHeader);
if (efuseHeader == 0xFF)
break;
if (EXT_HEADER(efuseHeader)) {
offset = GET_HDR_OFFSET_2_0(efuseHeader);
ReadEFuseByte23a(padapter, eFuse_Addr++,
&efuseExtHdr);
if (ALL_WORDS_DISABLED(efuseExtHdr))
continue;
offset |= ((efuseExtHdr & 0xF0) >> 1);
wden = efuseExtHdr & 0x0F;
} else {
offset = (efuseHeader >> 4) & 0x0f;
wden = efuseHeader & 0x0f;
}
if (offset < EFUSE_BT_MAX_SECTION) {
u16 addr;
addr = offset * PGPKT_DATA_SIZE;
for (i = 0; i < EFUSE_MAX_WORD_UNIT; i++) {
if (!(wden & (0x01 << i))) {
ReadEFuseByte23a(padapter,
eFuse_Addr++,
&efuseData);
efuseTbl[addr] = efuseData;
ReadEFuseByte23a(padapter,
eFuse_Addr++,
&efuseData);
efuseTbl[addr + 1] = efuseData;
}
addr += 2;
}
} else {
DBG_8723A(KERN_ERR
"%s: offset(%d) is illegal!!\n",
__func__, offset);
eFuse_Addr += Efuse_CalculateWordCnts23a(wden) * 2;
}
}
if ((eFuse_Addr - 1) < total) {
DBG_8723A("%s: bank(%d) data end at %#x\n",
__func__, bank, eFuse_Addr - 1);
break;
}
}
hal_EfuseSwitchToBank(padapter, 0);
for (i = 0; i < _size_byte; i++)
pbuf[i] = efuseTbl[_offset + i];
EFUSE_GetEfuseDefinition23a(padapter, EFUSE_BT,
TYPE_AVAILABLE_EFUSE_BYTES_TOTAL, &total);
used = (EFUSE_BT_REAL_BANK_CONTENT_LEN * (bank - 1)) + eFuse_Addr - 1;
pHalData->BTEfuseUsedBytes = used;
exit:
kfree(efuseTbl);
}
void
rtl8723a_readefuse(struct rtw_adapter *padapter,
u8 efuseType, u16 _offset, u16 _size_byte, u8 *pbuf)
{
if (efuseType == EFUSE_WIFI)
hal_ReadEFuse_WiFi(padapter, _offset, _size_byte, pbuf);
else
hal_ReadEFuse_BT(padapter, _offset, _size_byte, pbuf);
}
u16 rtl8723a_EfuseGetCurrentSize_WiFi(struct rtw_adapter *padapter)
{
u16 efuse_addr = 0;
u8 hoffset = 0, hworden = 0;
u8 efuse_data, word_cnts = 0;
struct hal_data_8723a *pHalData = GET_HAL_DATA(padapter);
efuse_addr = pHalData->EfuseUsedBytes;
DBG_8723A("%s: start_efuse_addr = 0x%X\n", __func__, efuse_addr);
hal_EfuseSwitchToBank(padapter, 0);
while (AVAILABLE_EFUSE_ADDR(efuse_addr)) {
if (efuse_OneByteRead23a(padapter, efuse_addr, &efuse_data) ==
_FAIL) {
DBG_8723A(KERN_ERR "%s: efuse_OneByteRead23a Fail! "
"addr = 0x%X !!\n", __func__, efuse_addr);
break;
}
if (efuse_data == 0xFF)
break;
if (EXT_HEADER(efuse_data)) {
hoffset = GET_HDR_OFFSET_2_0(efuse_data);
efuse_addr++;
efuse_OneByteRead23a(padapter, efuse_addr, &efuse_data);
if (ALL_WORDS_DISABLED(efuse_data))
continue;
hoffset |= ((efuse_data & 0xF0) >> 1);
hworden = efuse_data & 0x0F;
} else {
hoffset = (efuse_data >> 4) & 0x0F;
hworden = efuse_data & 0x0F;
}
word_cnts = Efuse_CalculateWordCnts23a(hworden);
efuse_addr += (word_cnts * 2) + 1;
}
pHalData->EfuseUsedBytes = efuse_addr;
DBG_8723A("%s: CurrentSize =%d\n", __func__, efuse_addr);
return efuse_addr;
}
u16 rtl8723a_EfuseGetCurrentSize_BT(struct rtw_adapter *padapter)
{
u16 btusedbytes;
u16 efuse_addr;
u8 bank, startBank;
u8 hoffset = 0, hworden = 0;
u8 efuse_data, word_cnts = 0;
u16 retU2 = 0;
struct hal_data_8723a *pHalData = GET_HAL_DATA(padapter);
btusedbytes = pHalData->BTEfuseUsedBytes;
efuse_addr = (u16) ((btusedbytes % EFUSE_BT_REAL_BANK_CONTENT_LEN));
startBank = (u8) (1 + (btusedbytes / EFUSE_BT_REAL_BANK_CONTENT_LEN));
DBG_8723A("%s: start from bank =%d addr = 0x%X\n", __func__, startBank,
efuse_addr);
EFUSE_GetEfuseDefinition23a(padapter, EFUSE_BT,
TYPE_AVAILABLE_EFUSE_BYTES_BANK, &retU2);
for (bank = startBank; bank < EFUSE_MAX_BANK; bank++) {
if (hal_EfuseSwitchToBank(padapter, bank) == false) {
DBG_8723A(KERN_ERR "%s: switch bank(%d) Fail!!\n",
__func__, bank);
bank = EFUSE_MAX_BANK;
break;
}
if (bank != startBank)
efuse_addr = 0;
while (AVAILABLE_EFUSE_ADDR(efuse_addr)) {
if (efuse_OneByteRead23a(padapter, efuse_addr,
&efuse_data) == _FAIL) {
DBG_8723A(KERN_ERR "%s: efuse_OneByteRead23a Fail!"
" addr = 0x%X !!\n",
__func__, efuse_addr);
bank = EFUSE_MAX_BANK;
break;
}
if (efuse_data == 0xFF)
break;
if (EXT_HEADER(efuse_data)) {
hoffset = GET_HDR_OFFSET_2_0(efuse_data);
efuse_addr++;
efuse_OneByteRead23a(padapter, efuse_addr,
&efuse_data);
if (ALL_WORDS_DISABLED(efuse_data)) {
efuse_addr++;
continue;
}
hoffset |= ((efuse_data & 0xF0) >> 1);
hworden = efuse_data & 0x0F;
} else {
hoffset = (efuse_data >> 4) & 0x0F;
hworden = efuse_data & 0x0F;
}
word_cnts = Efuse_CalculateWordCnts23a(hworden);
efuse_addr += (word_cnts * 2) + 1;
}
if (efuse_addr < retU2)
break;
}
retU2 = ((bank - 1) * EFUSE_BT_REAL_BANK_CONTENT_LEN) + efuse_addr;
pHalData->BTEfuseUsedBytes = retU2;
DBG_8723A("%s: CurrentSize =%d\n", __func__, retU2);
return retU2;
}
void rtl8723a_read_chip_version(struct rtw_adapter *padapter)
{
u32 value32;
struct hal_version ChipVersion;
struct hal_data_8723a *pHalData;
pHalData = GET_HAL_DATA(padapter);
value32 = rtl8723au_read32(padapter, REG_SYS_CFG);
ChipVersion.ICType = CHIP_8723A;
ChipVersion.ChipType = ((value32 & RTL_ID) ? TEST_CHIP : NORMAL_CHIP);
pHalData->rf_type = RF_1T1R;
ChipVersion.VendorType =
((value32 & VENDOR_ID) ? CHIP_VENDOR_UMC : CHIP_VENDOR_TSMC);
ChipVersion.CUTVersion = (value32 & CHIP_VER_RTL_MASK) >> CHIP_VER_RTL_SHIFT;
pHalData->RegulatorMode = ((value32 & SPS_SEL) ?
RT_LDO_REGULATOR : RT_SWITCHING_REGULATOR);
value32 = rtl8723au_read32(padapter, REG_GPIO_OUTSTS);
ChipVersion.ROMVer = (value32 & RF_RL_ID) >> 20;
pHalData->MultiFunc = RT_MULTI_FUNC_NONE;
value32 = rtl8723au_read32(padapter, REG_MULTI_FUNC_CTRL);
pHalData->MultiFunc |=
((value32 & WL_FUNC_EN) ? RT_MULTI_FUNC_WIFI : 0);
pHalData->MultiFunc |= ((value32 & BT_FUNC_EN) ? RT_MULTI_FUNC_BT : 0);
pHalData->MultiFunc |=
((value32 & GPS_FUNC_EN) ? RT_MULTI_FUNC_GPS : 0);
pHalData->PolarityCtl =
((value32 & WL_HWPDN_SL) ? RT_POLARITY_HIGH_ACT :
RT_POLARITY_LOW_ACT);
pHalData->VersionID = ChipVersion;
MSG_8723A("RF_Type is %x!!\n", pHalData->rf_type);
}
void SetBcnCtrlReg23a(struct rtw_adapter *padapter, u8 SetBits, u8 ClearBits)
{
u8 val8;
val8 = rtl8723au_read8(padapter, REG_BCN_CTRL);
val8 |= SetBits;
val8 &= ~ClearBits;
rtl8723au_write8(padapter, REG_BCN_CTRL, val8);
}
void rtl8723a_InitBeaconParameters(struct rtw_adapter *padapter)
{
rtl8723au_write16(padapter, REG_BCN_CTRL, 0x1010);
rtl8723au_write16(padapter, REG_TBTT_PROHIBIT, 0x6404);
if (check_fwstate(&padapter->mlmepriv, WIFI_STATION_STATE) == false)
rtl8723au_write8(padapter, REG_DRVERLYINT,
DRIVER_EARLY_INT_TIME);
rtl8723au_write8(padapter, REG_BCNDMATIM, BCN_DMA_ATIME_INT_TIME);
rtl8723au_write16(padapter, REG_BCNTCFG, 0x660F);
}
static void ResumeTxBeacon(struct rtw_adapter *padapter)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(padapter);
RT_TRACE(_module_hci_hal_init_c_, _drv_info_, "+ResumeTxBeacon\n");
pHalData->RegFwHwTxQCtrl |= BIT(6);
rtl8723au_write8(padapter, REG_FWHW_TXQ_CTRL + 2,
pHalData->RegFwHwTxQCtrl);
rtl8723au_write8(padapter, REG_TBTT_PROHIBIT + 1, 0xff);
pHalData->RegReg542 |= BIT(0);
rtl8723au_write8(padapter, REG_TBTT_PROHIBIT + 2, pHalData->RegReg542);
}
static void StopTxBeacon(struct rtw_adapter *padapter)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(padapter);
RT_TRACE(_module_hci_hal_init_c_, _drv_info_, "+StopTxBeacon\n");
pHalData->RegFwHwTxQCtrl &= ~BIT(6);
rtl8723au_write8(padapter, REG_FWHW_TXQ_CTRL + 2,
pHalData->RegFwHwTxQCtrl);
rtl8723au_write8(padapter, REG_TBTT_PROHIBIT + 1, 0x64);
pHalData->RegReg542 &= ~BIT(0);
rtl8723au_write8(padapter, REG_TBTT_PROHIBIT + 2, pHalData->RegReg542);
}
static void _BeaconFunctionEnable(struct rtw_adapter *padapter, u8 Enable,
u8 Linked)
{
SetBcnCtrlReg23a(padapter, DIS_TSF_UDT | EN_BCN_FUNCTION | DIS_BCNQ_SUB,
0);
rtl8723au_write8(padapter, REG_RD_CTRL + 1, 0x6F);
}
void rtl8723a_SetBeaconRelatedRegisters(struct rtw_adapter *padapter)
{
u32 value32;
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
struct mlme_ext_info *pmlmeinfo = &pmlmeext->mlmext_info;
rtl8723au_write16(padapter, REG_ATIMWND, 2);
rtl8723au_write16(padapter, REG_BCN_INTERVAL, pmlmeinfo->bcn_interval);
rtl8723a_InitBeaconParameters(padapter);
rtl8723au_write8(padapter, REG_SLOT, 0x09);
value32 = rtl8723au_read32(padapter, REG_TCR);
value32 &= ~TSFRST;
rtl8723au_write32(padapter, REG_TCR, value32);
value32 |= TSFRST;
rtl8723au_write32(padapter, REG_TCR, value32);
if (check_fwstate(&padapter->mlmepriv, WIFI_ADHOC_STATE |
WIFI_ADHOC_MASTER_STATE | WIFI_AP_STATE) == true) {
rtl8723au_write8(padapter, REG_RXTSF_OFFSET_CCK, 0x50);
rtl8723au_write8(padapter, REG_RXTSF_OFFSET_OFDM, 0x50);
}
_BeaconFunctionEnable(padapter, true, true);
ResumeTxBeacon(padapter);
SetBcnCtrlReg23a(padapter, DIS_BCNQ_SUB, 0);
}
void rtl8723a_SetHalODMVar(struct rtw_adapter *Adapter,
enum hal_odm_variable eVariable,
void *pValue1, bool bSet)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
struct dm_odm_t *podmpriv = &pHalData->odmpriv;
switch (eVariable) {
case HAL_ODM_STA_INFO:
{
struct sta_info *psta = (struct sta_info *)pValue1;
if (bSet) {
DBG_8723A("Set STA_(%d) info\n", psta->mac_id);
ODM_CmnInfoPtrArrayHook23a(podmpriv,
ODM_CMNINFO_STA_STATUS,
psta->mac_id, psta);
} else {
DBG_8723A("Clean STA_(%d) info\n", psta->mac_id);
ODM_CmnInfoPtrArrayHook23a(podmpriv,
ODM_CMNINFO_STA_STATUS,
psta->mac_id, NULL);
}
}
break;
case HAL_ODM_P2P_STATE:
ODM_CmnInfoUpdate23a(podmpriv, ODM_CMNINFO_WIFI_DIRECT, bSet);
break;
case HAL_ODM_WIFI_DISPLAY_STATE:
ODM_CmnInfoUpdate23a(podmpriv, ODM_CMNINFO_WIFI_DISPLAY, bSet);
break;
default:
break;
}
}
void rtl8723a_notch_filter(struct rtw_adapter *adapter, bool enable)
{
if (enable) {
DBG_8723A("Enable notch filter\n");
rtl8723au_write8(adapter, rOFDM0_RxDSP + 1,
rtl8723au_read8(adapter, rOFDM0_RxDSP + 1) |
BIT(1));
} else {
DBG_8723A("Disable notch filter\n");
rtl8723au_write8(adapter, rOFDM0_RxDSP + 1,
rtl8723au_read8(adapter, rOFDM0_RxDSP + 1) &
~BIT(1));
}
}
bool c2h_id_filter_ccx_8723a(u8 id)
{
bool ret = false;
if (id == C2H_CCX_TX_RPT)
ret = true;
return ret;
}
int c2h_handler_8723a(struct rtw_adapter *padapter, struct c2h_evt_hdr *c2h_evt)
{
int ret = _SUCCESS;
u8 i = 0;
if (c2h_evt == NULL) {
DBG_8723A("%s c2h_evt is NULL\n", __func__);
ret = _FAIL;
goto exit;
}
switch (c2h_evt->id) {
case C2H_DBG:
RT_TRACE(_module_hal_init_c_, _drv_info_,
"C2HCommandHandler: %s\n", c2h_evt->payload);
break;
case C2H_CCX_TX_RPT:
handle_txrpt_ccx_8723a(padapter, c2h_evt->payload);
break;
case C2H_EXT_RA_RPT:
break;
case C2H_HW_INFO_EXCH:
RT_TRACE(_module_hal_init_c_, _drv_info_,
"[BT], C2H_HW_INFO_EXCH\n");
for (i = 0; i < c2h_evt->plen; i++) {
RT_TRACE(_module_hal_init_c_, _drv_info_,
"[BT], tmpBuf[%d]= 0x%x\n", i,
c2h_evt->payload[i]);
}
break;
case C2H_C2H_H2C_TEST:
RT_TRACE(_module_hal_init_c_, _drv_info_,
"[BT], C2H_H2C_TEST\n");
RT_TRACE(_module_hal_init_c_, _drv_info_,
"[BT], tmpBuf[0]/[1]/[2]/[3]/[4]= 0x%x/ 0x%x/ 0x%x/ 0x%x/ 0x%x\n",
c2h_evt->payload[0],
c2h_evt->payload[1], c2h_evt->payload[2],
c2h_evt->payload[3], c2h_evt->payload[4]);
break;
case C2H_BT_INFO:
DBG_8723A("%s , Got C2H_BT_INFO \n", __func__);
rtl8723a_fw_c2h_BT_info(padapter,
c2h_evt->payload, c2h_evt->plen);
break;
default:
ret = _FAIL;
break;
}
exit:
return ret;
}
void handle_txrpt_ccx_8723a(struct rtw_adapter *adapter, void *buf)
{
struct txrpt_ccx_8723a *txrpt_ccx = buf;
struct submit_ctx *pack_tx_ops = &adapter->xmitpriv.ack_tx_ops;
if (txrpt_ccx->int_ccx && adapter->xmitpriv.ack_tx) {
if (txrpt_ccx->pkt_ok)
rtw23a_sctx_done_err(&pack_tx_ops,
RTW_SCTX_DONE_SUCCESS);
else
rtw23a_sctx_done_err(&pack_tx_ops,
RTW_SCTX_DONE_CCX_PKT_FAIL);
}
}
void rtl8723a_InitAntenna_Selection(struct rtw_adapter *padapter)
{
u8 val;
val = rtl8723au_read8(padapter, REG_LEDCFG2);
val |= BIT(7);
rtl8723au_write8(padapter, REG_LEDCFG2, val);
}
void rtl8723a_CheckAntenna_Selection(struct rtw_adapter *padapter)
{
u8 val;
val = rtl8723au_read8(padapter, REG_LEDCFG2);
if (!(val & BIT(7))) {
val |= BIT(7);
rtl8723au_write8(padapter, REG_LEDCFG2, val);
}
}
void rtl8723a_DeinitAntenna_Selection(struct rtw_adapter *padapter)
{
u8 val;
val = rtl8723au_read8(padapter, REG_LEDCFG2);
val &= ~BIT(7);
rtl8723au_write8(padapter, REG_LEDCFG2, val);
}
void rtl8723a_init_default_value(struct rtw_adapter *padapter)
{
struct hal_data_8723a *pHalData;
struct dm_priv *pdmpriv;
u8 i;
pHalData = GET_HAL_DATA(padapter);
pdmpriv = &pHalData->dmpriv;
pHalData->bIQKInitialized = false;
if (!padapter->pwrctrlpriv.bkeepfwalive)
pHalData->LastHMEBoxNum = 0;
pHalData->bIQKInitialized = false;
pdmpriv->TM_Trigger = 0;
pdmpriv->ThermalValue_HP_index = 0;
for (i = 0; i < HP_THERMAL_NUM; i++)
pdmpriv->ThermalValue_HP[i] = 0;
pHalData->EfuseUsedBytes = 0;
pHalData->BTEfuseUsedBytes = 0;
}
u8 GetEEPROMSize8723A(struct rtw_adapter *padapter)
{
u8 size = 0;
u32 cr;
cr = rtl8723au_read16(padapter, REG_9346CR);
size = (cr & BOOT_FROM_EEPROM) ? 6 : 4;
MSG_8723A("EEPROM type is %s\n", size == 4 ? "E-FUSE" : "93C46");
return size;
}
static int _LLTWrite(struct rtw_adapter *padapter, u32 address, u32 data)
{
int status = _SUCCESS;
s32 count = 0;
u32 value = _LLT_INIT_ADDR(address) | _LLT_INIT_DATA(data) |
_LLT_OP(_LLT_WRITE_ACCESS);
u16 LLTReg = REG_LLT_INIT;
rtl8723au_write32(padapter, LLTReg, value);
do {
value = rtl8723au_read32(padapter, LLTReg);
if (_LLT_NO_ACTIVE == _LLT_OP_VALUE(value))
break;
if (count > POLLING_LLT_THRESHOLD) {
RT_TRACE(_module_hal_init_c_, _drv_err_,
"Failed to polling write LLT done at address %d!\n",
address);
status = _FAIL;
break;
}
} while (count++);
return status;
}
int InitLLTTable23a(struct rtw_adapter *padapter, u32 boundary)
{
int status = _SUCCESS;
u32 i;
u32 txpktbuf_bndy = boundary;
u32 Last_Entry_Of_TxPktBuf = LAST_ENTRY_OF_TX_PKT_BUFFER;
for (i = 0; i < (txpktbuf_bndy - 1); i++) {
status = _LLTWrite(padapter, i, i + 1);
if (status != _SUCCESS)
return status;
}
status = _LLTWrite(padapter, (txpktbuf_bndy - 1), 0xFF);
if (status != _SUCCESS)
return status;
for (i = txpktbuf_bndy; i < Last_Entry_Of_TxPktBuf; i++) {
status = _LLTWrite(padapter, i, (i + 1));
if (_SUCCESS != status)
return status;
}
status = _LLTWrite(padapter, Last_Entry_Of_TxPktBuf, txpktbuf_bndy);
if (status != _SUCCESS)
return status;
return status;
}
static void _DisableGPIO(struct rtw_adapter *padapter)
{
u32 value32;
u32 u4bTmp;
rtl8723au_write16(padapter, REG_GPIO_PIN_CTRL + 2, 0x0000);
value32 = rtl8723au_read32(padapter, REG_GPIO_PIN_CTRL) & 0xFFFF00FF;
u4bTmp = value32 & 0x000000FF;
value32 |= ((u4bTmp << 8) | 0x00FF0000);
rtl8723au_write32(padapter, REG_GPIO_PIN_CTRL, value32);
rtl8723au_write16(padapter, REG_GPIO_IO_SEL_2, 0x0000);
value32 = rtl8723au_read32(padapter, REG_GPIO_PIN_CTRL_2) & 0xFFFF001F;
u4bTmp = value32 & 0x0000001F;
value32 |= ((u4bTmp << 8) | 0x001D0000);
rtl8723au_write32(padapter, REG_GPIO_PIN_CTRL_2, value32);
rtl8723au_write16(padapter, REG_LEDCFG0, 0x8080);
}
static void _DisableRFAFEAndResetBB8192C(struct rtw_adapter *padapter)
{
u8 value8;
rtl8723au_write8(padapter, REG_TXPAUSE, 0xFF);
PHY_SetRFReg(padapter, RF_PATH_A, 0x0, bMaskByte0, 0x0);
value8 = APSDOFF;
rtl8723au_write8(padapter, REG_APSD_CTRL, value8);
value8 = FEN_USBD | FEN_USBA | FEN_BB_GLB_RSTn;
rtl8723au_write8(padapter, REG_SYS_FUNC_EN, value8);
value8 &= ~FEN_BB_GLB_RSTn;
rtl8723au_write8(padapter, REG_SYS_FUNC_EN, value8);
}
static void _ResetDigitalProcedure1_92C(struct rtw_adapter *padapter,
bool bWithoutHWSM)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(padapter);
if (IS_FW_81xxC(padapter) && (pHalData->FirmwareVersion <= 0x20)) {
u16 valu16;
rtl8723au_write8(padapter, REG_MCUFWDL, 0);
valu16 = rtl8723au_read16(padapter, REG_SYS_FUNC_EN);
rtl8723au_write16(padapter, REG_SYS_FUNC_EN,
valu16 & ~FEN_CPUEN);
valu16 = rtl8723au_read16(padapter, REG_SYS_FUNC_EN) & 0x0FFF;
rtl8723au_write16(padapter, REG_SYS_FUNC_EN,
valu16 | FEN_HWPDN | FEN_ELDR);
valu16 = rtl8723au_read16(padapter, REG_SYS_FUNC_EN);
rtl8723au_write16(padapter, REG_SYS_FUNC_EN,
valu16 | FEN_CPUEN);
} else {
u8 retry_cnts = 0;
u8 val8;
val8 = rtl8723au_read8(padapter, REG_MCUFWDL);
if ((val8 & BIT(1)) && padapter->bFWReady) {
rtl8723au_write8(padapter, REG_FWIMR, 0x20);
rtl8723au_write8(padapter, REG_FTIMR, 0x00);
rtl8723au_write8(padapter, REG_FSIMR, 0x00);
rtl8723au_write8(padapter, REG_HMETFR + 3, 0x20);
while ((retry_cnts++ < 100) &&
(rtl8723au_read16(padapter, REG_SYS_FUNC_EN) &
FEN_CPUEN)) {
udelay(50);
}
if (retry_cnts >= 100) {
rtl8723au_write8(padapter,
REG_SYS_FUNC_EN + 1, 0x50);
mdelay(10);
}
}
rtl8723au_write8(padapter, REG_SYS_FUNC_EN + 1, 0x54);
rtl8723au_write8(padapter, REG_MCUFWDL, 0);
}
if (bWithoutHWSM) {
rtl8723au_write16(padapter, REG_SYS_CLKR, 0x70A3);
rtl8723au_write8(padapter, REG_AFE_PLL_CTRL, 0x80);
rtl8723au_write16(padapter, REG_AFE_XTAL_CTRL, 0x880F);
rtl8723au_write8(padapter, REG_SYS_ISO_CTRL, 0xF9);
} else {
rtl8723au_write8(padapter, REG_RF_CTRL, 0x00);
}
}
static void _ResetDigitalProcedure2(struct rtw_adapter *padapter)
{
rtl8723au_write16(padapter, REG_SYS_CLKR, 0x70a3);
rtl8723au_write8(padapter, REG_SYS_ISO_CTRL + 1, 0x82);
}
static void _DisableAnalog(struct rtw_adapter *padapter, bool bWithoutHWSM)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(padapter);
u16 value16;
u8 value8;
if (bWithoutHWSM) {
rtl8723au_write8(padapter, REG_LDOA15_CTRL, 0x04);
value8 = rtl8723au_read8(padapter, REG_LDOV12D_CTRL);
value8 &= ~LDV12_EN;
rtl8723au_write8(padapter, REG_LDOV12D_CTRL, value8);
}
value8 = 0x23;
if (IS_81xxC_VENDOR_UMC_B_CUT(pHalData->VersionID))
value8 |= BIT(3);
rtl8723au_write8(padapter, REG_SPS0_CTRL, value8);
if (bWithoutHWSM) {
value16 = APDM_HOST | AFSM_HSUS | PFM_ALDN;
} else {
value16 = APDM_HOST | AFSM_HSUS | PFM_ALDN;
}
rtl8723au_write16(padapter, REG_APS_FSMCO, value16);
rtl8723au_write8(padapter, REG_RSV_CTRL, 0x0e);
}
int CardDisableHWSM(struct rtw_adapter *padapter, u8 resetMCU)
{
if (padapter->bSurpriseRemoved)
return _SUCCESS;
_DisableRFAFEAndResetBB8192C(padapter);
_ResetDigitalProcedure1_92C(padapter, false);
_DisableGPIO(padapter);
_DisableAnalog(padapter, false);
RT_TRACE(_module_hci_hal_init_c_, _drv_info_,
"======> Card disable finished.\n");
return _SUCCESS;
}
int CardDisableWithoutHWSM(struct rtw_adapter *padapter)
{
if (padapter->bSurpriseRemoved)
return _SUCCESS;
_DisableRFAFEAndResetBB8192C(padapter);
_ResetDigitalProcedure1_92C(padapter, true);
_DisableGPIO(padapter);
_ResetDigitalProcedure2(padapter);
_DisableAnalog(padapter, true);
return _SUCCESS;
}
void Hal_InitPGData(struct rtw_adapter *padapter, u8 *PROMContent)
{
struct eeprom_priv *pEEPROM = GET_EEPROM_EFUSE_PRIV(padapter);
if (!pEEPROM->bautoload_fail_flag) {
if (!pEEPROM->EepromOrEfuse) {
EFUSE_ShadowMapUpdate23a(padapter, EFUSE_WIFI);
memcpy(PROMContent, pEEPROM->efuse_eeprom_data,
HWSET_MAX_SIZE);
}
} else {
RT_TRACE(_module_hci_hal_init_c_, _drv_notice_,
"AutoLoad Fail reported from CR9346!!\n");
if (!pEEPROM->EepromOrEfuse)
EFUSE_ShadowMapUpdate23a(padapter, EFUSE_WIFI);
memcpy(PROMContent, pEEPROM->efuse_eeprom_data,
HWSET_MAX_SIZE);
}
}
void Hal_EfuseParseIDCode(struct rtw_adapter *padapter, u8 *hwinfo)
{
struct eeprom_priv *pEEPROM = GET_EEPROM_EFUSE_PRIV(padapter);
u16 EEPROMId;
EEPROMId = le16_to_cpu(*((u16 *) hwinfo));
if (EEPROMId != RTL_EEPROM_ID) {
DBG_8723A("EEPROM ID(%#x) is invalid!!\n", EEPROMId);
pEEPROM->bautoload_fail_flag = true;
} else {
pEEPROM->bautoload_fail_flag = false;
}
RT_TRACE(_module_hal_init_c_, _drv_info_,
"EEPROM ID = 0x%04x\n", EEPROMId);
}
static void Hal_EEValueCheck(u8 EEType, void *pInValue, void *pOutValue)
{
switch (EEType) {
case EETYPE_TX_PWR:
{
u8 *pIn, *pOut;
pIn = (u8 *) pInValue;
pOut = (u8 *) pOutValue;
if (*pIn <= 63)
*pOut = *pIn;
else {
RT_TRACE(_module_hci_hal_init_c_, _drv_err_,
"EETYPE_TX_PWR, value =%d is invalid, set to default = 0x%x\n",
*pIn, EEPROM_Default_TxPowerLevel);
*pOut = EEPROM_Default_TxPowerLevel;
}
}
break;
default:
break;
}
}
static void
Hal_ReadPowerValueFromPROM_8723A(struct txpowerinfo *pwrInfo,
u8 *PROMContent, bool AutoLoadFail)
{
u32 rfPath, eeAddr, group, rfPathMax = 1;
memset(pwrInfo, 0, sizeof(*pwrInfo));
if (AutoLoadFail) {
for (group = 0; group < MAX_CHNL_GROUP; group++) {
for (rfPath = 0; rfPath < rfPathMax; rfPath++) {
pwrInfo->CCKIndex[rfPath][group] =
EEPROM_Default_TxPowerLevel;
pwrInfo->HT40_1SIndex[rfPath][group] =
EEPROM_Default_TxPowerLevel;
pwrInfo->HT40_2SIndexDiff[rfPath][group] =
EEPROM_Default_HT40_2SDiff;
pwrInfo->HT20IndexDiff[rfPath][group] =
EEPROM_Default_HT20_Diff;
pwrInfo->OFDMIndexDiff[rfPath][group] =
EEPROM_Default_LegacyHTTxPowerDiff;
pwrInfo->HT40MaxOffset[rfPath][group] =
EEPROM_Default_HT40_PwrMaxOffset;
pwrInfo->HT20MaxOffset[rfPath][group] =
EEPROM_Default_HT20_PwrMaxOffset;
}
}
pwrInfo->TSSI_A[0] = EEPROM_Default_TSSI;
return;
}
for (rfPath = 0; rfPath < rfPathMax; rfPath++) {
for (group = 0; group < MAX_CHNL_GROUP; group++) {
eeAddr =
EEPROM_CCK_TX_PWR_INX_8723A + (rfPath * 3) + group;
Hal_EEValueCheck(EETYPE_TX_PWR, &PROMContent[eeAddr],
&pwrInfo->CCKIndex[rfPath][group]);
eeAddr = EEPROM_HT40_1S_TX_PWR_INX_8723A +
(rfPath * 3) + group;
Hal_EEValueCheck(EETYPE_TX_PWR, &PROMContent[eeAddr],
&pwrInfo->HT40_1SIndex[rfPath][group]);
}
}
for (group = 0; group < MAX_CHNL_GROUP; group++) {
for (rfPath = 0; rfPath < rfPathMax; rfPath++) {
pwrInfo->HT40_2SIndexDiff[rfPath][group] = 0;
pwrInfo->HT20IndexDiff[rfPath][group] =
(PROMContent
[EEPROM_HT20_TX_PWR_INX_DIFF_8723A +
group] >> (rfPath * 4)) & 0xF;
if (pwrInfo->HT20IndexDiff[rfPath][group] & BIT(3))
pwrInfo->HT20IndexDiff[rfPath][group] |= 0xF0;
pwrInfo->OFDMIndexDiff[rfPath][group] =
(PROMContent[EEPROM_OFDM_TX_PWR_INX_DIFF_8723A +
group] >> (rfPath * 4)) & 0xF;
pwrInfo->HT40MaxOffset[rfPath][group] =
(PROMContent[EEPROM_HT40_MAX_PWR_OFFSET_8723A +
group] >> (rfPath * 4)) & 0xF;
pwrInfo->HT20MaxOffset[rfPath][group] =
(PROMContent[EEPROM_HT20_MAX_PWR_OFFSET_8723A +
group] >> (rfPath * 4)) & 0xF;
}
}
pwrInfo->TSSI_A[0] = PROMContent[EEPROM_TSSI_A_8723A];
}
static u8 Hal_GetChnlGroup(u8 chnl)
{
u8 group = 0;
if (chnl < 3)
group = 0;
else if (chnl < 9)
group = 1;
else
group = 2;
return group;
}
void
Hal_EfuseParsetxpowerinfo_8723A(struct rtw_adapter *padapter,
u8 *PROMContent, bool AutoLoadFail)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(padapter);
struct txpowerinfo pwrInfo;
u8 rfPath, ch, group, rfPathMax = 1;
u8 pwr, diff;
Hal_ReadPowerValueFromPROM_8723A(&pwrInfo, PROMContent, AutoLoadFail);
for (rfPath = 0; rfPath < rfPathMax; rfPath++) {
for (ch = 0; ch < CHANNEL_MAX_NUMBER; ch++) {
group = Hal_GetChnlGroup(ch);
pHalData->TxPwrLevelCck[rfPath][ch] =
pwrInfo.CCKIndex[rfPath][group];
pHalData->TxPwrLevelHT40_1S[rfPath][ch] =
pwrInfo.HT40_1SIndex[rfPath][group];
pHalData->TxPwrHt20Diff[rfPath][ch] =
pwrInfo.HT20IndexDiff[rfPath][group];
pHalData->TxPwrLegacyHtDiff[rfPath][ch] =
pwrInfo.OFDMIndexDiff[rfPath][group];
pHalData->PwrGroupHT20[rfPath][ch] =
pwrInfo.HT20MaxOffset[rfPath][group];
pHalData->PwrGroupHT40[rfPath][ch] =
pwrInfo.HT40MaxOffset[rfPath][group];
pwr = pwrInfo.HT40_1SIndex[rfPath][group];
diff = pwrInfo.HT40_2SIndexDiff[rfPath][group];
pHalData->TxPwrLevelHT40_2S[rfPath][ch] =
(pwr > diff) ? (pwr - diff) : 0;
}
}
for (rfPath = 0; rfPath < RF_PATH_MAX; rfPath++) {
for (ch = 0; ch < CHANNEL_MAX_NUMBER; ch++) {
RT_TRACE(_module_hci_hal_init_c_, _drv_info_,
"RF(%u)-Ch(%u) [CCK / HT40_1S / HT40_2S] = [0x%x / 0x%x / 0x%x]\n",
rfPath, ch,
pHalData->TxPwrLevelCck[rfPath][ch],
pHalData->TxPwrLevelHT40_1S[rfPath][ch],
pHalData->TxPwrLevelHT40_2S[rfPath][ch]);
}
}
for (ch = 0; ch < CHANNEL_MAX_NUMBER; ch++) {
RT_TRACE(_module_hci_hal_init_c_, _drv_info_,
"RF-A Ht20 to HT40 Diff[%u] = 0x%x(%d)\n", ch,
pHalData->TxPwrHt20Diff[RF_PATH_A][ch],
pHalData->TxPwrHt20Diff[RF_PATH_A][ch]);
}
for (ch = 0; ch < CHANNEL_MAX_NUMBER; ch++)
RT_TRACE(_module_hci_hal_init_c_, _drv_info_,
"RF-A Legacy to Ht40 Diff[%u] = 0x%x\n", ch,
pHalData->TxPwrLegacyHtDiff[RF_PATH_A][ch]);
for (ch = 0; ch < CHANNEL_MAX_NUMBER; ch++) {
RT_TRACE(_module_hci_hal_init_c_, _drv_info_,
"RF-B Ht20 to HT40 Diff[%u] = 0x%x(%d)\n", ch,
pHalData->TxPwrHt20Diff[RF_PATH_B][ch],
pHalData->TxPwrHt20Diff[RF_PATH_B][ch]);
}
for (ch = 0; ch < CHANNEL_MAX_NUMBER; ch++)
RT_TRACE(_module_hci_hal_init_c_, _drv_info_,
"RF-B Legacy to HT40 Diff[%u] = 0x%x\n", ch,
pHalData->TxPwrLegacyHtDiff[RF_PATH_B][ch]);
if (!AutoLoadFail) {
struct registry_priv *registry_par = &padapter->registrypriv;
if (registry_par->regulatory_tid == 0xff) {
if (PROMContent[RF_OPTION1_8723A] == 0xff)
pHalData->EEPROMRegulatory = 0;
else
pHalData->EEPROMRegulatory =
PROMContent[RF_OPTION1_8723A] & 0x7;
} else {
pHalData->EEPROMRegulatory =
registry_par->regulatory_tid;
}
} else {
pHalData->EEPROMRegulatory = 0;
}
RT_TRACE(_module_hci_hal_init_c_, _drv_info_,
"EEPROMRegulatory = 0x%x\n", pHalData->EEPROMRegulatory);
if (!AutoLoadFail)
pHalData->bTXPowerDataReadFromEEPORM = true;
}
void
Hal_EfuseParseBTCoexistInfo_8723A(struct rtw_adapter *padapter,
u8 *hwinfo, bool AutoLoadFail)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(padapter);
u8 tempval;
u32 tmpu4;
if (!AutoLoadFail) {
tmpu4 = rtl8723au_read32(padapter, REG_MULTI_FUNC_CTRL);
if (tmpu4 & BT_FUNC_EN)
pHalData->EEPROMBluetoothCoexist = 1;
else
pHalData->EEPROMBluetoothCoexist = 0;
pHalData->EEPROMBluetoothType = BT_RTL8723A;
tempval = hwinfo[RF_OPTION4_8723A];
pHalData->EEPROMBluetoothAntNum = (tempval & 0x1);
pHalData->EEPROMBluetoothAntIsolation = (tempval & 0x10) >> 4;
pHalData->EEPROMBluetoothRadioShared = (tempval & 0x20) >> 5;
} else {
pHalData->EEPROMBluetoothCoexist = 0;
pHalData->EEPROMBluetoothType = BT_RTL8723A;
pHalData->EEPROMBluetoothAntNum = Ant_x2;
pHalData->EEPROMBluetoothAntIsolation = 0;
pHalData->EEPROMBluetoothRadioShared = BT_Radio_Shared;
}
rtl8723a_BT_init_hal_vars(padapter);
}
void
Hal_EfuseParseEEPROMVer(struct rtw_adapter *padapter,
u8 *hwinfo, bool AutoLoadFail)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(padapter);
if (!AutoLoadFail)
pHalData->EEPROMVersion = hwinfo[EEPROM_VERSION_8723A];
else
pHalData->EEPROMVersion = 1;
RT_TRACE(_module_hci_hal_init_c_, _drv_info_,
"Hal_EfuseParseEEPROMVer(), EEVer = %d\n",
pHalData->EEPROMVersion);
}
void
rtl8723a_EfuseParseChnlPlan(struct rtw_adapter *padapter,
u8 *hwinfo, bool AutoLoadFail)
{
padapter->mlmepriv.ChannelPlan =
hal_com_get_channel_plan23a(padapter, hwinfo ?
hwinfo[EEPROM_ChannelPlan_8723A]:0xFF,
padapter->registrypriv.channel_plan,
RT_CHANNEL_DOMAIN_WORLD_WIDE_13,
AutoLoadFail);
DBG_8723A("mlmepriv.ChannelPlan = 0x%02x\n",
padapter->mlmepriv.ChannelPlan);
}
void
Hal_EfuseParseCustomerID(struct rtw_adapter *padapter,
u8 *hwinfo, bool AutoLoadFail)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(padapter);
if (!AutoLoadFail) {
pHalData->EEPROMCustomerID = hwinfo[EEPROM_CustomID_8723A];
pHalData->EEPROMSubCustomerID =
hwinfo[EEPROM_SubCustomID_8723A];
} else {
pHalData->EEPROMCustomerID = 0;
pHalData->EEPROMSubCustomerID = 0;
}
RT_TRACE(_module_hci_hal_init_c_, _drv_info_,
"EEPROM Customer ID: 0x%2x\n", pHalData->EEPROMCustomerID);
RT_TRACE(_module_hci_hal_init_c_, _drv_info_,
"EEPROM SubCustomer ID: 0x%02x\n",
pHalData->EEPROMSubCustomerID);
}
void
Hal_EfuseParseAntennaDiversity(struct rtw_adapter *padapter,
u8 *hwinfo, bool AutoLoadFail)
{
}
void
Hal_EfuseParseRateIndicationOption(struct rtw_adapter *padapter,
u8 *hwinfo, bool AutoLoadFail)
{
}
void
Hal_EfuseParseXtal_8723A(struct rtw_adapter *pAdapter,
u8 *hwinfo, u8 AutoLoadFail)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(pAdapter);
if (!AutoLoadFail) {
pHalData->CrystalCap = hwinfo[EEPROM_XTAL_K_8723A];
if (pHalData->CrystalCap == 0xFF)
pHalData->CrystalCap = EEPROM_Default_CrystalCap_8723A;
} else {
pHalData->CrystalCap = EEPROM_Default_CrystalCap_8723A;
}
RT_TRACE(_module_hci_hal_init_c_, _drv_info_,
"%s: CrystalCap = 0x%2x\n", __func__,
pHalData->CrystalCap);
}
void
Hal_EfuseParseThermalMeter_8723A(struct rtw_adapter *padapter,
u8 *PROMContent, bool AutoloadFail)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(padapter);
if (!AutoloadFail)
pHalData->EEPROMThermalMeter =
PROMContent[EEPROM_THERMAL_METER_8723A];
else
pHalData->EEPROMThermalMeter = EEPROM_Default_ThermalMeter;
if ((pHalData->EEPROMThermalMeter == 0xff) || AutoloadFail) {
pHalData->bAPKThermalMeterIgnore = true;
pHalData->EEPROMThermalMeter = EEPROM_Default_ThermalMeter;
}
DBG_8723A("%s: ThermalMeter = 0x%x\n", __func__,
pHalData->EEPROMThermalMeter);
}
static void rtl8723a_cal_txdesc_chksum(struct tx_desc *ptxdesc)
{
u16 *usPtr = (u16 *) ptxdesc;
u32 count = 16;
u32 index;
u16 checksum = 0;
ptxdesc->txdw7 &= cpu_to_le32(0xffff0000);
for (index = 0; index < count; index++)
checksum ^= le16_to_cpu(*(usPtr + index));
ptxdesc->txdw7 |= cpu_to_le32(checksum & 0x0000ffff);
}
void rtl8723a_fill_fake_txdesc(struct rtw_adapter *padapter, u8 *pDesc,
u32 BufferLen, u8 IsPsPoll, u8 IsBTQosNull)
{
struct tx_desc *ptxdesc;
ptxdesc = (struct tx_desc *)pDesc;
memset(pDesc, 0, TXDESC_SIZE);
ptxdesc->txdw0 |= cpu_to_le32(OWN | FSG | LSG);
ptxdesc->txdw0 |= cpu_to_le32(((TXDESC_SIZE + OFFSET_SZ) <<
OFFSET_SHT) & 0x00ff0000);
ptxdesc->txdw0 |= cpu_to_le32(BufferLen & 0x0000ffff);
ptxdesc->txdw1 |= cpu_to_le32((QSLT_MGNT << QSEL_SHT) & 0x00001f00);
if (IsPsPoll) {
ptxdesc->txdw1 |= cpu_to_le32(NAVUSEHDR);
} else {
ptxdesc->txdw4 |= cpu_to_le32(BIT(7));
ptxdesc->txdw3 |= cpu_to_le32((8 << 28));
}
if (true == IsBTQosNull)
ptxdesc->txdw2 |= cpu_to_le32(BIT(23));
ptxdesc->txdw4 |= cpu_to_le32(BIT(8));
rtl8723a_cal_txdesc_chksum(ptxdesc);
}
void hw_var_set_opmode(struct rtw_adapter *padapter, u8 mode)
{
u8 val8;
if (mode == MSR_INFRA || mode == MSR_NOLINK) {
StopTxBeacon(padapter);
val8 = DIS_TSF_UDT | EN_BCN_FUNCTION | DIS_ATIM;
SetBcnCtrlReg23a(padapter, val8, ~val8);
} else if (mode == MSR_ADHOC) {
ResumeTxBeacon(padapter);
val8 = DIS_TSF_UDT | EN_BCN_FUNCTION | DIS_BCNQ_SUB;
SetBcnCtrlReg23a(padapter, val8, ~val8);
} else if (mode == MSR_AP) {
rtl8723a_set_BTCoex_AP_mode_FwRsvdPkt_cmd(padapter);
ResumeTxBeacon(padapter);
val8 = DIS_TSF_UDT | DIS_BCNQ_SUB;
SetBcnCtrlReg23a(padapter, val8, ~val8);
rtl8723au_write32(padapter, REG_RCR, 0x7000228e);
rtl8723au_write16(padapter, REG_RXFLTMAP2, 0xFFFF);
rtl8723au_write16(padapter, REG_RXFLTMAP1, 0x0400);
rtl8723au_write8(padapter, REG_BCNDMATIM, 0x02);
rtl8723au_write8(padapter, REG_DRVERLYINT, 0x05);
rtl8723au_write8(padapter, REG_ATIMWND, 0x0a);
rtl8723au_write16(padapter, REG_BCNTCFG, 0x00);
rtl8723au_write16(padapter, REG_TBTT_PROHIBIT, 0xff04);
rtl8723au_write16(padapter, REG_TSFTR_SYN_OFFSET, 0x7fff);
rtl8723au_write8(padapter, REG_DUAL_TSF_RST, BIT(0));
val8 = DIS_TSF_UDT | EN_BCN_FUNCTION |
EN_TXBCN_RPT | DIS_BCNQ_SUB;
SetBcnCtrlReg23a(padapter, val8, ~val8);
}
val8 = rtl8723au_read8(padapter, MSR);
val8 = (val8 & 0xC) | mode;
rtl8723au_write8(padapter, MSR, val8);
}
void hw_var_set_macaddr(struct rtw_adapter *padapter, u8 *val)
{
u8 idx = 0;
u32 reg_macid;
reg_macid = REG_MACID;
for (idx = 0; idx < 6; idx++)
rtl8723au_write8(padapter, (reg_macid + idx), val[idx]);
}
void hw_var_set_bssid(struct rtw_adapter *padapter, u8 *val)
{
u8 idx = 0;
u32 reg_bssid;
reg_bssid = REG_BSSID;
for (idx = 0; idx < 6; idx++)
rtl8723au_write8(padapter, (reg_bssid + idx), val[idx]);
}
void hw_var_set_correct_tsf(struct rtw_adapter *padapter)
{
u64 tsf;
u32 reg_tsftr;
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
struct mlme_ext_info *pmlmeinfo = &pmlmeext->mlmext_info;
tsf = pmlmeext->TSFValue -
do_div(pmlmeext->TSFValue,
(pmlmeinfo->bcn_interval * 1024)) - 1024;
if (((pmlmeinfo->state & 0x03) == MSR_ADHOC) ||
((pmlmeinfo->state & 0x03) == MSR_AP)) {
StopTxBeacon(padapter);
}
reg_tsftr = REG_TSFTR;
SetBcnCtrlReg23a(padapter, 0, EN_BCN_FUNCTION);
rtl8723au_write32(padapter, reg_tsftr, tsf);
rtl8723au_write32(padapter, reg_tsftr + 4, tsf >> 32);
SetBcnCtrlReg23a(padapter, EN_BCN_FUNCTION, 0);
if (((pmlmeinfo->state & 0x03) == MSR_ADHOC) ||
((pmlmeinfo->state & 0x03) == MSR_AP))
ResumeTxBeacon(padapter);
}
void hw_var_set_mlme_disconnect(struct rtw_adapter *padapter)
{
rtl8723au_write16(padapter, REG_RXFLTMAP2, 0);
rtl8723au_write8(padapter, REG_DUAL_TSF_RST, BIT(0));
SetBcnCtrlReg23a(padapter, DIS_TSF_UDT, 0);
}
void hw_var_set_mlme_join(struct rtw_adapter *padapter, u8 type)
{
u8 RetryLimit = 0x30;
struct hal_data_8723a *pHalData = GET_HAL_DATA(padapter);
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
if (type == 0) {
u32 v32;
rtl8723au_write16(padapter, REG_RXFLTMAP2, 0xFFFF);
v32 = rtl8723au_read32(padapter, REG_RCR);
v32 |= RCR_CBSSID_DATA | RCR_CBSSID_BCN;
rtl8723au_write32(padapter, REG_RCR, v32);
if (check_fwstate(pmlmepriv, WIFI_STATION_STATE) == true)
RetryLimit =
(pHalData->CustomerID == RT_CID_CCX) ? 7 : 48;
else
RetryLimit = 0x7;
} else if (type == 1) {
rtl8723au_write16(padapter, REG_RXFLTMAP2, 0);
} else if (type == 2) {
SetBcnCtrlReg23a(padapter, 0, DIS_TSF_UDT);
if (check_fwstate(pmlmepriv,
WIFI_ADHOC_STATE | WIFI_ADHOC_MASTER_STATE)) {
rtl8723au_write8(padapter, 0x542, 0x02);
RetryLimit = 0x7;
}
}
rtl8723au_write16(padapter, REG_RL,
RetryLimit << RETRY_LIMIT_SHORT_SHIFT | RetryLimit <<
RETRY_LIMIT_LONG_SHIFT);
switch (type) {
case 0:
rtl8723a_BT_wifiassociate_notify(padapter, true);
break;
case 1:
rtl8723a_BT_wifiassociate_notify(padapter, false);
break;
case 2:
break;
}
}
