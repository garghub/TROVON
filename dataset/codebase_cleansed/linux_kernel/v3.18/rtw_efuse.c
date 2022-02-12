static void Efuse_PowerSwitch(struct rtw_adapter *padapter,
u8 bWrite, u8 PwrState)
{
u8 tempval;
u16 tmpV16;
if (PwrState == true) {
rtl8723au_write8(padapter, REG_EFUSE_ACCESS, EFUSE_ACCESS_ON);
tmpV16 = rtl8723au_read16(padapter, REG_SYS_ISO_CTRL);
if (!(tmpV16 & PWC_EV12V)) {
tmpV16 |= PWC_EV12V;
rtl8723au_write16(padapter, REG_SYS_ISO_CTRL, tmpV16);
}
tmpV16 = rtl8723au_read16(padapter, REG_SYS_FUNC_EN);
if (!(tmpV16 & FEN_ELDR)) {
tmpV16 |= FEN_ELDR;
rtl8723au_write16(padapter, REG_SYS_FUNC_EN, tmpV16);
}
tmpV16 = rtl8723au_read16(padapter, REG_SYS_CLKR);
if ((!(tmpV16 & LOADER_CLK_EN)) || (!(tmpV16 & ANA8M))) {
tmpV16 |= (LOADER_CLK_EN | ANA8M);
rtl8723au_write16(padapter, REG_SYS_CLKR, tmpV16);
}
if (bWrite == true) {
tempval = rtl8723au_read8(padapter, EFUSE_TEST + 3);
tempval &= 0x0F;
tempval |= (VOLTAGE_V25 << 4);
rtl8723au_write8(padapter, EFUSE_TEST + 3,
tempval | 0x80);
}
} else {
rtl8723au_write8(padapter, REG_EFUSE_ACCESS, EFUSE_ACCESS_OFF);
if (bWrite == true) {
tempval = rtl8723au_read8(padapter, EFUSE_TEST + 3);
rtl8723au_write8(padapter, EFUSE_TEST + 3,
tempval & 0x7F);
}
}
}
u16
Efuse_GetCurrentSize23a(struct rtw_adapter *pAdapter, u8 efuseType)
{
u16 ret = 0;
if (efuseType == EFUSE_WIFI)
ret = rtl8723a_EfuseGetCurrentSize_WiFi(pAdapter);
else
ret = rtl8723a_EfuseGetCurrentSize_BT(pAdapter);
return ret;
}
u8
Efuse_CalculateWordCnts23a(u8 word_en)
{
u8 word_cnts = 0;
if (!(word_en & BIT(0))) word_cnts++;
if (!(word_en & BIT(1))) word_cnts++;
if (!(word_en & BIT(2))) word_cnts++;
if (!(word_en & BIT(3))) word_cnts++;
return word_cnts;
}
void
ReadEFuseByte23a(struct rtw_adapter *Adapter, u16 _offset, u8 *pbuf)
{
u32 value32;
u8 readbyte;
u16 retry;
rtl8723au_write8(Adapter, EFUSE_CTRL+1, (_offset & 0xff));
readbyte = rtl8723au_read8(Adapter, EFUSE_CTRL+2);
rtl8723au_write8(Adapter, EFUSE_CTRL+2,
((_offset >> 8) & 0x03) | (readbyte & 0xfc));
readbyte = rtl8723au_read8(Adapter, EFUSE_CTRL+3);
rtl8723au_write8(Adapter, EFUSE_CTRL+3, readbyte & 0x7f);
retry = 0;
value32 = rtl8723au_read32(Adapter, EFUSE_CTRL);
while (!((value32 >> 24) & 0x80) && retry < 10000) {
value32 = rtl8723au_read32(Adapter, EFUSE_CTRL);
retry++;
}
udelay(50);
value32 = rtl8723au_read32(Adapter, EFUSE_CTRL);
*pbuf = (u8)(value32 & 0xff);
}
void
EFUSE_GetEfuseDefinition23a(struct rtw_adapter *pAdapter, u8 efuseType,
u8 type, void *pOut)
{
u8 *pu1Tmp;
u16 *pu2Tmp;
u8 *pMax_section;
switch (type) {
case TYPE_EFUSE_MAX_SECTION:
pMax_section = (u8 *) pOut;
if (efuseType == EFUSE_WIFI)
*pMax_section = EFUSE_MAX_SECTION_8723A;
else
*pMax_section = EFUSE_BT_MAX_SECTION;
break;
case TYPE_EFUSE_REAL_CONTENT_LEN:
pu2Tmp = (u16 *) pOut;
if (efuseType == EFUSE_WIFI)
*pu2Tmp = EFUSE_REAL_CONTENT_LEN_8723A;
else
*pu2Tmp = EFUSE_BT_REAL_CONTENT_LEN;
break;
case TYPE_AVAILABLE_EFUSE_BYTES_BANK:
pu2Tmp = (u16 *) pOut;
if (efuseType == EFUSE_WIFI)
*pu2Tmp = (EFUSE_REAL_CONTENT_LEN_8723A -
EFUSE_OOB_PROTECT_BYTES);
else
*pu2Tmp = (EFUSE_BT_REAL_BANK_CONTENT_LEN -
EFUSE_PROTECT_BYTES_BANK);
break;
case TYPE_AVAILABLE_EFUSE_BYTES_TOTAL:
pu2Tmp = (u16 *) pOut;
if (efuseType == EFUSE_WIFI)
*pu2Tmp = (EFUSE_REAL_CONTENT_LEN_8723A -
EFUSE_OOB_PROTECT_BYTES);
else
*pu2Tmp = (EFUSE_BT_REAL_CONTENT_LEN -
(EFUSE_PROTECT_BYTES_BANK * 3));
break;
case TYPE_EFUSE_MAP_LEN:
pu2Tmp = (u16 *) pOut;
if (efuseType == EFUSE_WIFI)
*pu2Tmp = EFUSE_MAP_LEN_8723A;
else
*pu2Tmp = EFUSE_BT_MAP_LEN;
break;
case TYPE_EFUSE_PROTECT_BYTES_BANK:
pu1Tmp = (u8 *) pOut;
if (efuseType == EFUSE_WIFI)
*pu1Tmp = EFUSE_OOB_PROTECT_BYTES;
else
*pu1Tmp = EFUSE_PROTECT_BYTES_BANK;
break;
case TYPE_EFUSE_CONTENT_LEN_BANK:
pu2Tmp = (u16 *) pOut;
if (efuseType == EFUSE_WIFI)
*pu2Tmp = EFUSE_REAL_CONTENT_LEN_8723A;
else
*pu2Tmp = EFUSE_BT_REAL_BANK_CONTENT_LEN;
break;
default:
pu1Tmp = (u8 *) pOut;
*pu1Tmp = 0;
break;
}
}
u8
EFUSE_Read1Byte23a(struct rtw_adapter *Adapter, u16 Address)
{
u8 data;
u8 Bytetemp = {0x00};
u8 temp = {0x00};
u32 k = 0;
u16 contentLen = 0;
EFUSE_GetEfuseDefinition23a(Adapter, EFUSE_WIFI,
TYPE_EFUSE_REAL_CONTENT_LEN,
(void *)&contentLen);
if (Address < contentLen) {
temp = Address & 0xFF;
rtl8723au_write8(Adapter, EFUSE_CTRL+1, temp);
Bytetemp = rtl8723au_read8(Adapter, EFUSE_CTRL+2);
temp = ((Address >> 8) & 0x03) | (Bytetemp & 0xFC);
rtl8723au_write8(Adapter, EFUSE_CTRL+2, temp);
Bytetemp = rtl8723au_read8(Adapter, EFUSE_CTRL+3);
temp = Bytetemp & 0x7F;
rtl8723au_write8(Adapter, EFUSE_CTRL+3, temp);
Bytetemp = rtl8723au_read8(Adapter, EFUSE_CTRL+3);
while (!(Bytetemp & 0x80)) {
Bytetemp = rtl8723au_read8(Adapter, EFUSE_CTRL+3);
k++;
if (k == 1000) {
k = 0;
break;
}
}
data = rtl8723au_read8(Adapter, EFUSE_CTRL);
return data;
}
else
return 0xFF;
}
void
EFUSE_Write1Byte(
struct rtw_adapter * Adapter,
u16 Address,
u8 Value)
{
u8 Bytetemp = {0x00};
u8 temp = {0x00};
u32 k = 0;
u16 contentLen = 0;
EFUSE_GetEfuseDefinition23a(Adapter, EFUSE_WIFI,
TYPE_EFUSE_REAL_CONTENT_LEN,
(void *)&contentLen);
if (Address < contentLen) {
rtl8723au_write8(Adapter, EFUSE_CTRL, Value);
temp = Address & 0xFF;
rtl8723au_write8(Adapter, EFUSE_CTRL+1, temp);
Bytetemp = rtl8723au_read8(Adapter, EFUSE_CTRL+2);
temp = ((Address >> 8) & 0x03) | (Bytetemp & 0xFC);
rtl8723au_write8(Adapter, EFUSE_CTRL+2, temp);
Bytetemp = rtl8723au_read8(Adapter, EFUSE_CTRL+3);
temp = Bytetemp | 0x80;
rtl8723au_write8(Adapter, EFUSE_CTRL+3, temp);
Bytetemp = rtl8723au_read8(Adapter, EFUSE_CTRL+3);
while (Bytetemp & 0x80) {
Bytetemp = rtl8723au_read8(Adapter, EFUSE_CTRL+3);
k++;
if (k == 100) {
k = 0;
break;
}
}
}
}
int
efuse_OneByteRead23a(struct rtw_adapter *pAdapter, u16 addr, u8 *data)
{
u8 tmpidx = 0;
int bResult;
rtl8723au_write8(pAdapter, EFUSE_CTRL+1, (u8)(addr&0xff));
rtl8723au_write8(pAdapter, EFUSE_CTRL+2, ((u8)((addr>>8) &0x03)) |
(rtl8723au_read8(pAdapter, EFUSE_CTRL+2)&0xFC));
rtl8723au_write8(pAdapter, EFUSE_CTRL+3, 0x72);
while(!(0x80 &rtl8723au_read8(pAdapter, EFUSE_CTRL+3)) && (tmpidx<100))
tmpidx++;
if (tmpidx < 100) {
*data = rtl8723au_read8(pAdapter, EFUSE_CTRL);
bResult = _SUCCESS;
} else {
*data = 0xff;
bResult = _FAIL;
}
return bResult;
}
int
efuse_OneByteWrite23a(struct rtw_adapter *pAdapter, u16 addr, u8 data)
{
u8 tmpidx = 0;
int bResult;
rtl8723au_write8(pAdapter, EFUSE_CTRL+1, (u8)(addr&0xff));
rtl8723au_write8(pAdapter, EFUSE_CTRL+2,
(rtl8723au_read8(pAdapter, EFUSE_CTRL+2)&0xFC)|(u8)((addr>>8)&0x03));
rtl8723au_write8(pAdapter, EFUSE_CTRL, data);
rtl8723au_write8(pAdapter, EFUSE_CTRL+3, 0xF2);
while((0x80 & rtl8723au_read8(pAdapter, EFUSE_CTRL+3)) &&
(tmpidx<100)) {
tmpidx++;
}
if (tmpidx < 100)
bResult = _SUCCESS;
else
bResult = _FAIL;
return bResult;
}
void
efuse_WordEnableDataRead23a(u8 word_en,
u8 *sourdata,
u8 *targetdata)
{
if (!(word_en&BIT(0))) {
targetdata[0] = sourdata[0];
targetdata[1] = sourdata[1];
}
if (!(word_en&BIT(1))) {
targetdata[2] = sourdata[2];
targetdata[3] = sourdata[3];
}
if (!(word_en&BIT(2))) {
targetdata[4] = sourdata[4];
targetdata[5] = sourdata[5];
}
if (!(word_en&BIT(3))) {
targetdata[6] = sourdata[6];
targetdata[7] = sourdata[7];
}
}
static int efuse_read8(struct rtw_adapter *padapter, u16 address, u8 *value)
{
return efuse_OneByteRead23a(padapter, address, value);
}
static int efuse_write8(struct rtw_adapter *padapter, u16 address, u8 *value)
{
return efuse_OneByteWrite23a(padapter, address, *value);
}
int rtw_efuse_access23a(struct rtw_adapter *padapter, u8 bWrite, u16 start_addr,
u16 cnts, u8 *data)
{
int i = 0;
u16 real_content_len = 0, max_available_size = 0;
int res = _FAIL ;
int (*rw8)(struct rtw_adapter *, u16, u8*);
EFUSE_GetEfuseDefinition23a(padapter, EFUSE_WIFI,
TYPE_EFUSE_REAL_CONTENT_LEN,
(void *)&real_content_len);
EFUSE_GetEfuseDefinition23a(padapter, EFUSE_WIFI,
TYPE_AVAILABLE_EFUSE_BYTES_TOTAL,
(void *)&max_available_size);
if (start_addr > real_content_len)
return _FAIL;
if (true == bWrite) {
if ((start_addr + cnts) > max_available_size)
return _FAIL;
rw8 = &efuse_write8;
} else
rw8 = &efuse_read8;
Efuse_PowerSwitch(padapter, bWrite, true);
for (i = 0; i < cnts; i++) {
if (start_addr >= real_content_len) {
res = _FAIL;
break;
}
res = rw8(padapter, start_addr++, data++);
if (res == _FAIL)
break;
}
Efuse_PowerSwitch(padapter, bWrite, false);
return res;
}
u16 efuse_GetMaxSize23a(struct rtw_adapter *padapter)
{
u16 max_size;
EFUSE_GetEfuseDefinition23a(padapter, EFUSE_WIFI,
TYPE_AVAILABLE_EFUSE_BYTES_TOTAL,
(void *)&max_size);
return max_size;
}
int rtw_efuse_map_read23a(struct rtw_adapter *padapter,
u16 addr, u16 cnts, u8 *data)
{
u16 mapLen = 0;
EFUSE_GetEfuseDefinition23a(padapter, EFUSE_WIFI,
TYPE_EFUSE_MAP_LEN, (void *)&mapLen);
if ((addr + cnts) > mapLen)
return _FAIL;
Efuse_PowerSwitch(padapter, false, true);
rtl8723a_readefuse(padapter, EFUSE_WIFI, addr, cnts, data);
Efuse_PowerSwitch(padapter, false, false);
return _SUCCESS;
}
int rtw_BT_efuse_map_read23a(struct rtw_adapter *padapter,
u16 addr, u16 cnts, u8 *data)
{
u16 mapLen = 0;
EFUSE_GetEfuseDefinition23a(padapter, EFUSE_BT,
TYPE_EFUSE_MAP_LEN, (void *)&mapLen);
if ((addr + cnts) > mapLen)
return _FAIL;
Efuse_PowerSwitch(padapter, false, true);
rtl8723a_readefuse(padapter, EFUSE_BT, addr, cnts, data);
Efuse_PowerSwitch(padapter, false, false);
return _SUCCESS;
}
void
Efuse_ReadAllMap(struct rtw_adapter *pAdapter, u8 efuseType, u8 *Efuse)
{
u16 mapLen = 0;
Efuse_PowerSwitch(pAdapter, false, true);
EFUSE_GetEfuseDefinition23a(pAdapter, efuseType, TYPE_EFUSE_MAP_LEN,
(void *)&mapLen);
rtl8723a_readefuse(pAdapter, efuseType, 0, mapLen, Efuse);
Efuse_PowerSwitch(pAdapter, false, false);
}
static void
efuse_ShadowRead1Byte(
struct rtw_adapter * pAdapter,
u16 Offset,
u8 *Value)
{
struct eeprom_priv *pEEPROM = GET_EEPROM_EFUSE_PRIV(pAdapter);
*Value = pEEPROM->efuse_eeprom_data[Offset];
}
static void
efuse_ShadowRead2Byte(
struct rtw_adapter * pAdapter,
u16 Offset,
u16 *Value)
{
struct eeprom_priv *pEEPROM = GET_EEPROM_EFUSE_PRIV(pAdapter);
*Value = pEEPROM->efuse_eeprom_data[Offset];
*Value |= pEEPROM->efuse_eeprom_data[Offset+1]<<8;
}
static void
efuse_ShadowRead4Byte(
struct rtw_adapter * pAdapter,
u16 Offset,
u32 *Value)
{
struct eeprom_priv *pEEPROM = GET_EEPROM_EFUSE_PRIV(pAdapter);
*Value = pEEPROM->efuse_eeprom_data[Offset];
*Value |= pEEPROM->efuse_eeprom_data[Offset+1]<<8;
*Value |= pEEPROM->efuse_eeprom_data[Offset+2]<<16;
*Value |= pEEPROM->efuse_eeprom_data[Offset+3]<<24;
}
void EFUSE_ShadowMapUpdate23a(struct rtw_adapter *pAdapter, u8 efuseType)
{
struct eeprom_priv *pEEPROM = GET_EEPROM_EFUSE_PRIV(pAdapter);
u16 mapLen = 0;
EFUSE_GetEfuseDefinition23a(pAdapter, efuseType,
TYPE_EFUSE_MAP_LEN, (void *)&mapLen);
if (pEEPROM->bautoload_fail_flag == true)
memset(pEEPROM->efuse_eeprom_data, 0xFF, mapLen);
else
Efuse_ReadAllMap(pAdapter, efuseType,
pEEPROM->efuse_eeprom_data);
}
void
EFUSE_ShadowRead23a(
struct rtw_adapter * pAdapter,
u8 Type,
u16 Offset,
u32 *Value)
{
if (Type == 1)
efuse_ShadowRead1Byte(pAdapter, Offset, (u8 *)Value);
else if (Type == 2)
efuse_ShadowRead2Byte(pAdapter, Offset, (u16 *)Value);
else if (Type == 4)
efuse_ShadowRead4Byte(pAdapter, Offset, (u32 *)Value);
}
