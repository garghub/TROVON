void
Efuse_PowerSwitch23a(
struct rtw_adapter * pAdapter,
u8 bWrite,
u8 PwrState)
{
pAdapter->HalFunc.EfusePowerSwitch(pAdapter, bWrite, PwrState);
}
u16
Efuse_GetCurrentSize23a(struct rtw_adapter *pAdapter, u8 efuseType)
{
u16 ret = 0;
ret = pAdapter->HalFunc.EfuseGetCurrentSize(pAdapter, efuseType);
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
rtw_write8(Adapter, EFUSE_CTRL+1, (_offset & 0xff));
readbyte = rtw_read8(Adapter, EFUSE_CTRL+2);
rtw_write8(Adapter, EFUSE_CTRL+2, ((_offset >> 8) & 0x03) | (readbyte & 0xfc));
readbyte = rtw_read8(Adapter, EFUSE_CTRL+3);
rtw_write8(Adapter, EFUSE_CTRL+3, (readbyte & 0x7f));
retry = 0;
value32 = rtw_read32(Adapter, EFUSE_CTRL);
while(!(((value32 >> 24) & 0xff) & 0x80) && (retry<10000))
{
value32 = rtw_read32(Adapter, EFUSE_CTRL);
retry++;
}
udelay(50);
value32 = rtw_read32(Adapter, EFUSE_CTRL);
*pbuf = (u8)(value32 & 0xff);
}
void
efuse_ReadEFuse(struct rtw_adapter *Adapter, u8 efuseType,
u16 _offset, u16 _size_byte, u8 *pbuf)
{
Adapter->HalFunc.ReadEFuse(Adapter, efuseType, _offset,
_size_byte, pbuf);
}
void
EFUSE_GetEfuseDefinition23a(struct rtw_adapter *pAdapter, u8 efuseType,
u8 type, void *pOut)
{
pAdapter->HalFunc.EFUSEGetEfuseDefinition(pAdapter, efuseType,
type, pOut);
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
if (Address < contentLen)
{
temp = Address & 0xFF;
rtw_write8(Adapter, EFUSE_CTRL+1, temp);
Bytetemp = rtw_read8(Adapter, EFUSE_CTRL+2);
temp = ((Address >> 8) & 0x03) | (Bytetemp & 0xFC);
rtw_write8(Adapter, EFUSE_CTRL+2, temp);
Bytetemp = rtw_read8(Adapter, EFUSE_CTRL+3);
temp = Bytetemp & 0x7F;
rtw_write8(Adapter, EFUSE_CTRL+3, temp);
Bytetemp = rtw_read8(Adapter, EFUSE_CTRL+3);
while(!(Bytetemp & 0x80))
{
Bytetemp = rtw_read8(Adapter, EFUSE_CTRL+3);
k++;
if (k == 1000)
{
k = 0;
break;
}
}
data = rtw_read8(Adapter, EFUSE_CTRL);
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
if (Address < contentLen)
{
rtw_write8(Adapter, EFUSE_CTRL, Value);
temp = Address & 0xFF;
rtw_write8(Adapter, EFUSE_CTRL+1, temp);
Bytetemp = rtw_read8(Adapter, EFUSE_CTRL+2);
temp = ((Address >> 8) & 0x03) | (Bytetemp & 0xFC);
rtw_write8(Adapter, EFUSE_CTRL+2, temp);
Bytetemp = rtw_read8(Adapter, EFUSE_CTRL+3);
temp = Bytetemp | 0x80;
rtw_write8(Adapter, EFUSE_CTRL+3, temp);
Bytetemp = rtw_read8(Adapter, EFUSE_CTRL+3);
while(Bytetemp & 0x80)
{
Bytetemp = rtw_read8(Adapter, EFUSE_CTRL+3);
k++;
if (k == 100)
{
k = 0;
break;
}
}
}
}
u8
efuse_OneByteRead23a(struct rtw_adapter *pAdapter, u16 addr, u8 *data)
{
u8 tmpidx = 0;
u8 bResult;
rtw_write8(pAdapter, EFUSE_CTRL+1, (u8)(addr&0xff));
rtw_write8(pAdapter, EFUSE_CTRL+2, ((u8)((addr>>8) &0x03)) |
(rtw_read8(pAdapter, EFUSE_CTRL+2)&0xFC));
rtw_write8(pAdapter, EFUSE_CTRL+3, 0x72);
while(!(0x80 &rtw_read8(pAdapter, EFUSE_CTRL+3)) && (tmpidx<100))
tmpidx++;
if (tmpidx < 100) {
*data = rtw_read8(pAdapter, EFUSE_CTRL);
bResult = true;
} else {
*data = 0xff;
bResult = false;
}
return bResult;
}
u8
efuse_OneByteWrite23a(struct rtw_adapter *pAdapter, u16 addr, u8 data)
{
u8 tmpidx = 0;
u8 bResult;
rtw_write8(pAdapter, EFUSE_CTRL+1, (u8)(addr&0xff));
rtw_write8(pAdapter, EFUSE_CTRL+2,
(rtw_read8(pAdapter, EFUSE_CTRL+2)&0xFC)|(u8)((addr>>8)&0x03));
rtw_write8(pAdapter, EFUSE_CTRL, data);
rtw_write8(pAdapter, EFUSE_CTRL+3, 0xF2);
while((0x80 & rtw_read8(pAdapter, EFUSE_CTRL+3)) && (tmpidx<100)) {
tmpidx++;
}
if (tmpidx<100)
{
bResult = true;
}
else
{
bResult = false;
}
return bResult;
}
int
Efuse_PgPacketRead23a(struct rtw_adapter *pAdapter, u8 offset, u8 *data)
{
int ret = 0;
ret = pAdapter->HalFunc.Efuse_PgPacketRead23a(pAdapter, offset, data);
return ret;
}
int
Efuse_PgPacketWrite23a(struct rtw_adapter *pAdapter, u8 offset,
u8 word_en, u8 *data)
{
int ret;
ret = pAdapter->HalFunc.Efuse_PgPacketWrite23a(pAdapter, offset,
word_en, data);
return ret;
}
void
efuse_WordEnableDataRead23a(u8 word_en,
u8 *sourdata,
u8 *targetdata)
{
if (!(word_en&BIT(0)))
{
targetdata[0] = sourdata[0];
targetdata[1] = sourdata[1];
}
if (!(word_en&BIT(1)))
{
targetdata[2] = sourdata[2];
targetdata[3] = sourdata[3];
}
if (!(word_en&BIT(2)))
{
targetdata[4] = sourdata[4];
targetdata[5] = sourdata[5];
}
if (!(word_en&BIT(3)))
{
targetdata[6] = sourdata[6];
targetdata[7] = sourdata[7];
}
}
u8
Efuse_WordEnableDataWrite23a(struct rtw_adapter *pAdapter, u16 efuse_addr,
u8 word_en, u8 *data)
{
u8 ret = 0;
ret = pAdapter->HalFunc.Efuse_WordEnableDataWrite23a(pAdapter, efuse_addr,
word_en, data);
return ret;
}
static u8 efuse_read8(struct rtw_adapter *padapter, u16 address, u8 *value)
{
return efuse_OneByteRead23a(padapter, address, value);
}
static u8 efuse_write8(struct rtw_adapter *padapter, u16 address, u8 *value)
{
return efuse_OneByteWrite23a(padapter, address, *value);
}
u8 rtw_efuse_access23a(struct rtw_adapter *padapter, u8 bWrite, u16 start_addr,
u16 cnts, u8 *data)
{
int i = 0;
u16 real_content_len = 0, max_available_size = 0;
u8 res = _FAIL ;
u8 (*rw8)(struct rtw_adapter *, u16, u8*);
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
Efuse_PowerSwitch23a(padapter, bWrite, true);
for (i = 0; i < cnts; i++) {
if (start_addr >= real_content_len) {
res = _FAIL;
break;
}
res = rw8(padapter, start_addr++, data++);
if (_FAIL == res) break;
}
Efuse_PowerSwitch23a(padapter, bWrite, false);
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
u8 efuse_GetCurrentSize23a(struct rtw_adapter *padapter, u16 *size)
{
Efuse_PowerSwitch23a(padapter, false, true);
*size = Efuse_GetCurrentSize23a(padapter, EFUSE_WIFI);
Efuse_PowerSwitch23a(padapter, false, false);
return _SUCCESS;
}
u8 rtw_efuse_map_read23a(struct rtw_adapter *padapter, u16 addr, u16 cnts, u8 *data)
{
u16 mapLen = 0;
EFUSE_GetEfuseDefinition23a(padapter, EFUSE_WIFI,
TYPE_EFUSE_MAP_LEN, (void *)&mapLen);
if ((addr + cnts) > mapLen)
return _FAIL;
Efuse_PowerSwitch23a(padapter, false, true);
efuse_ReadEFuse(padapter, EFUSE_WIFI, addr, cnts, data);
Efuse_PowerSwitch23a(padapter, false, false);
return _SUCCESS;
}
u8 rtw_BT_efuse_map_read23a(struct rtw_adapter *padapter, u16 addr, u16 cnts, u8 *data)
{
u16 mapLen = 0;
EFUSE_GetEfuseDefinition23a(padapter, EFUSE_BT,
TYPE_EFUSE_MAP_LEN, (void *)&mapLen);
if ((addr + cnts) > mapLen)
return _FAIL;
Efuse_PowerSwitch23a(padapter, false, true);
efuse_ReadEFuse(padapter, EFUSE_BT, addr, cnts, data);
Efuse_PowerSwitch23a(padapter, false, false);
return _SUCCESS;
}
void
Efuse_ReadAllMap(struct rtw_adapter *pAdapter, u8 efuseType, u8 *Efuse)
{
u16 mapLen = 0;
Efuse_PowerSwitch23a(pAdapter, false, true);
EFUSE_GetEfuseDefinition23a(pAdapter, efuseType, TYPE_EFUSE_MAP_LEN,
(void *)&mapLen);
efuse_ReadEFuse(pAdapter, efuseType, 0, mapLen, Efuse);
Efuse_PowerSwitch23a(pAdapter, false, false);
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
u32 *Value )
{
if (Type == 1)
efuse_ShadowRead1Byte(pAdapter, Offset, (u8 *)Value);
else if (Type == 2)
efuse_ShadowRead2Byte(pAdapter, Offset, (u16 *)Value);
else if (Type == 4)
efuse_ShadowRead4Byte(pAdapter, Offset, (u32 *)Value);
}
