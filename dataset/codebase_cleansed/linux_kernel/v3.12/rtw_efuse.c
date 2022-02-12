bool
Efuse_Read1ByteFromFakeContent(
struct adapter *pAdapter,
u16 Offset,
u8 *Value)
{
if (Offset >= EFUSE_MAX_HW_SIZE)
return false;
if (fakeEfuseBank == 0)
*Value = fakeEfuseContent[Offset];
else
*Value = fakeBTEfuseContent[fakeEfuseBank-1][Offset];
return true;
}
static bool
Efuse_Write1ByteToFakeContent(
struct adapter *pAdapter,
u16 Offset,
u8 Value)
{
if (Offset >= EFUSE_MAX_HW_SIZE)
return false;
if (fakeEfuseBank == 0) {
fakeEfuseContent[Offset] = Value;
} else {
fakeBTEfuseContent[fakeEfuseBank-1][Offset] = Value;
}
return true;
}
void
Efuse_PowerSwitch(
struct adapter *pAdapter,
u8 write,
u8 PwrState)
{
pAdapter->HalFunc.EfusePowerSwitch(pAdapter, write, PwrState);
}
u16
Efuse_GetCurrentSize(
struct adapter *pAdapter,
u8 efuseType,
bool pseudo)
{
u16 ret = 0;
ret = pAdapter->HalFunc.EfuseGetCurrentSize(pAdapter, efuseType, pseudo);
return ret;
}
u8
Efuse_CalculateWordCnts(u8 word_en)
{
u8 word_cnts = 0;
if (!(word_en & BIT(0)))
word_cnts++;
if (!(word_en & BIT(1)))
word_cnts++;
if (!(word_en & BIT(2)))
word_cnts++;
if (!(word_en & BIT(3)))
word_cnts++;
return word_cnts;
}
void
ReadEFuseByte(
struct adapter *Adapter,
u16 _offset,
u8 *pbuf,
bool pseudo)
{
u32 value32;
u8 readbyte;
u16 retry;
if (pseudo) {
Efuse_Read1ByteFromFakeContent(Adapter, _offset, pbuf);
return;
}
rtw_write8(Adapter, EFUSE_CTRL+1, (_offset & 0xff));
readbyte = rtw_read8(Adapter, EFUSE_CTRL+2);
rtw_write8(Adapter, EFUSE_CTRL+2, ((_offset >> 8) & 0x03) | (readbyte & 0xfc));
readbyte = rtw_read8(Adapter, EFUSE_CTRL+3);
rtw_write8(Adapter, EFUSE_CTRL+3, (readbyte & 0x7f));
retry = 0;
value32 = rtw_read32(Adapter, EFUSE_CTRL);
while (!(((value32 >> 24) & 0xff) & 0x80) && (retry < 10000)) {
value32 = rtw_read32(Adapter, EFUSE_CTRL);
retry++;
}
rtw_udelay_os(50);
value32 = rtw_read32(Adapter, EFUSE_CTRL);
*pbuf = (u8)(value32 & 0xff);
}
static void efuse_ReadEFuse(struct adapter *Adapter, u8 efuseType, u16 _offset, u16 _size_byte, u8 *pbuf, bool pseudo)
{
Adapter->HalFunc.ReadEFuse(Adapter, efuseType, _offset, _size_byte, pbuf, pseudo);
}
void EFUSE_GetEfuseDefinition(struct adapter *pAdapter, u8 efuseType, u8 type, void *pOut, bool pseudo
)
{
pAdapter->HalFunc.EFUSEGetEfuseDefinition(pAdapter, efuseType, type, pOut, pseudo);
}
u8 EFUSE_Read1Byte(struct adapter *Adapter, u16 Address)
{
u8 data;
u8 Bytetemp = {0x00};
u8 temp = {0x00};
u32 k = 0;
u16 contentLen = 0;
EFUSE_GetEfuseDefinition(Adapter, EFUSE_WIFI , TYPE_EFUSE_REAL_CONTENT_LEN, (void *)&contentLen, false);
if (Address < contentLen) {
temp = Address & 0xFF;
rtw_write8(Adapter, EFUSE_CTRL+1, temp);
Bytetemp = rtw_read8(Adapter, EFUSE_CTRL+2);
temp = ((Address >> 8) & 0x03) | (Bytetemp & 0xFC);
rtw_write8(Adapter, EFUSE_CTRL+2, temp);
Bytetemp = rtw_read8(Adapter, EFUSE_CTRL+3);
temp = Bytetemp & 0x7F;
rtw_write8(Adapter, EFUSE_CTRL+3, temp);
Bytetemp = rtw_read8(Adapter, EFUSE_CTRL+3);
while (!(Bytetemp & 0x80)) {
Bytetemp = rtw_read8(Adapter, EFUSE_CTRL+3);
k++;
if (k == 1000) {
k = 0;
break;
}
}
data = rtw_read8(Adapter, EFUSE_CTRL);
return data;
} else {
return 0xFF;
}
}
u8 efuse_OneByteRead(struct adapter *pAdapter, u16 addr, u8 *data, bool pseudo)
{
u8 tmpidx = 0;
u8 result;
if (pseudo) {
result = Efuse_Read1ByteFromFakeContent(pAdapter, addr, data);
return result;
}
rtw_write8(pAdapter, EFUSE_CTRL+1, (u8)(addr & 0xff));
rtw_write8(pAdapter, EFUSE_CTRL+2, ((u8)((addr>>8) & 0x03)) |
(rtw_read8(pAdapter, EFUSE_CTRL+2) & 0xFC));
rtw_write8(pAdapter, EFUSE_CTRL+3, 0x72);
while (!(0x80 & rtw_read8(pAdapter, EFUSE_CTRL+3)) && (tmpidx < 100))
tmpidx++;
if (tmpidx < 100) {
*data = rtw_read8(pAdapter, EFUSE_CTRL);
result = true;
} else {
*data = 0xff;
result = false;
}
return result;
}
u8 efuse_OneByteWrite(struct adapter *pAdapter, u16 addr, u8 data, bool pseudo)
{
u8 tmpidx = 0;
u8 result;
if (pseudo) {
result = Efuse_Write1ByteToFakeContent(pAdapter, addr, data);
return result;
}
rtw_write8(pAdapter, EFUSE_CTRL+1, (u8)(addr&0xff));
rtw_write8(pAdapter, EFUSE_CTRL+2,
(rtw_read8(pAdapter, EFUSE_CTRL+2) & 0xFC) |
(u8)((addr>>8) & 0x03));
rtw_write8(pAdapter, EFUSE_CTRL, data);
rtw_write8(pAdapter, EFUSE_CTRL+3, 0xF2);
while ((0x80 & rtw_read8(pAdapter, EFUSE_CTRL+3)) && (tmpidx < 100))
tmpidx++;
if (tmpidx < 100)
result = true;
else
result = false;
return result;
}
int Efuse_PgPacketRead(struct adapter *pAdapter, u8 offset, u8 *data, bool pseudo)
{
int ret = 0;
ret = pAdapter->HalFunc.Efuse_PgPacketRead(pAdapter, offset, data, pseudo);
return ret;
}
int Efuse_PgPacketWrite(struct adapter *pAdapter, u8 offset, u8 word_en, u8 *data, bool pseudo)
{
int ret;
ret = pAdapter->HalFunc.Efuse_PgPacketWrite(pAdapter, offset, word_en, data, pseudo);
return ret;
}
static int Efuse_PgPacketWrite_BT(struct adapter *pAdapter, u8 offset, u8 word_en, u8 *data, bool pseudo)
{
int ret;
ret = pAdapter->HalFunc.Efuse_PgPacketWrite_BT(pAdapter, offset, word_en, data, pseudo);
return ret;
}
void efuse_WordEnableDataRead(u8 word_en, u8 *sourdata, u8 *targetdata)
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
u8 Efuse_WordEnableDataWrite(struct adapter *pAdapter, u16 efuse_addr, u8 word_en, u8 *data, bool pseudo)
{
u8 ret = 0;
ret = pAdapter->HalFunc.Efuse_WordEnableDataWrite(pAdapter, efuse_addr, word_en, data, pseudo);
return ret;
}
static u8 efuse_read8(struct adapter *padapter, u16 address, u8 *value)
{
return efuse_OneByteRead(padapter, address, value, false);
}
static u8 efuse_write8(struct adapter *padapter, u16 address, u8 *value)
{
return efuse_OneByteWrite(padapter, address, *value, false);
}
u8 rtw_efuse_access(struct adapter *padapter, u8 write, u16 start_addr, u16 cnts, u8 *data)
{
int i = 0;
u16 real_content_len = 0, max_available_size = 0;
u8 res = _FAIL ;
u8 (*rw8)(struct adapter *, u16, u8*);
EFUSE_GetEfuseDefinition(padapter, EFUSE_WIFI, TYPE_EFUSE_REAL_CONTENT_LEN, (void *)&real_content_len, false);
EFUSE_GetEfuseDefinition(padapter, EFUSE_WIFI, TYPE_AVAILABLE_EFUSE_BYTES_TOTAL, (void *)&max_available_size, false);
if (start_addr > real_content_len)
return _FAIL;
if (write) {
if ((start_addr + cnts) > max_available_size)
return _FAIL;
rw8 = &efuse_write8;
} else {
rw8 = &efuse_read8;
}
Efuse_PowerSwitch(padapter, write, true);
for (i = 0; i < cnts; i++) {
if (start_addr >= real_content_len) {
res = _FAIL;
break;
}
res = rw8(padapter, start_addr++, data++);
if (_FAIL == res)
break;
}
Efuse_PowerSwitch(padapter, write, false);
return res;
}
u16 efuse_GetMaxSize(struct adapter *padapter)
{
u16 max_size;
EFUSE_GetEfuseDefinition(padapter, EFUSE_WIFI , TYPE_AVAILABLE_EFUSE_BYTES_TOTAL, (void *)&max_size, false);
return max_size;
}
u8 efuse_GetCurrentSize(struct adapter *padapter, u16 *size)
{
Efuse_PowerSwitch(padapter, false, true);
*size = Efuse_GetCurrentSize(padapter, EFUSE_WIFI, false);
Efuse_PowerSwitch(padapter, false, false);
return _SUCCESS;
}
u8 rtw_efuse_map_read(struct adapter *padapter, u16 addr, u16 cnts, u8 *data)
{
u16 mapLen = 0;
EFUSE_GetEfuseDefinition(padapter, EFUSE_WIFI, TYPE_EFUSE_MAP_LEN, (void *)&mapLen, false);
if ((addr + cnts) > mapLen)
return _FAIL;
Efuse_PowerSwitch(padapter, false, true);
efuse_ReadEFuse(padapter, EFUSE_WIFI, addr, cnts, data, false);
Efuse_PowerSwitch(padapter, false, false);
return _SUCCESS;
}
u8 rtw_BT_efuse_map_read(struct adapter *padapter, u16 addr, u16 cnts, u8 *data)
{
u16 mapLen = 0;
EFUSE_GetEfuseDefinition(padapter, EFUSE_BT, TYPE_EFUSE_MAP_LEN, (void *)&mapLen, false);
if ((addr + cnts) > mapLen)
return _FAIL;
Efuse_PowerSwitch(padapter, false, true);
efuse_ReadEFuse(padapter, EFUSE_BT, addr, cnts, data, false);
Efuse_PowerSwitch(padapter, false, false);
return _SUCCESS;
}
u8 rtw_efuse_map_write(struct adapter *padapter, u16 addr, u16 cnts, u8 *data)
{
u8 offset, word_en;
u8 *map;
u8 newdata[PGPKT_DATA_SIZE];
s32 i, idx;
u8 ret = _SUCCESS;
u16 mapLen = 0;
EFUSE_GetEfuseDefinition(padapter, EFUSE_WIFI, TYPE_EFUSE_MAP_LEN, (void *)&mapLen, false);
if ((addr + cnts) > mapLen)
return _FAIL;
map = rtw_zmalloc(mapLen);
if (map == NULL)
return _FAIL;
ret = rtw_efuse_map_read(padapter, 0, mapLen, map);
if (ret == _FAIL)
goto exit;
Efuse_PowerSwitch(padapter, true, true);
offset = (addr >> 3);
word_en = 0xF;
_rtw_memset(newdata, 0xFF, PGPKT_DATA_SIZE);
i = addr & 0x7;
idx = 0;
if (i & 0x1) {
if (data[idx] != map[addr+idx]) {
word_en &= ~BIT(i >> 1);
newdata[i-1] = map[addr+idx-1];
newdata[i] = data[idx];
}
i++;
idx++;
}
do {
for (; i < PGPKT_DATA_SIZE; i += 2) {
if (cnts == idx)
break;
if ((cnts - idx) == 1) {
if (data[idx] != map[addr+idx]) {
word_en &= ~BIT(i >> 1);
newdata[i] = data[idx];
newdata[i+1] = map[addr+idx+1];
}
idx++;
break;
} else {
if ((data[idx] != map[addr+idx]) ||
(data[idx+1] != map[addr+idx+1])) {
word_en &= ~BIT(i >> 1);
newdata[i] = data[idx];
newdata[i+1] = data[idx + 1];
}
idx += 2;
}
if (idx == cnts)
break;
}
if (word_en != 0xF) {
ret = Efuse_PgPacketWrite(padapter, offset, word_en, newdata, false);
DBG_88E("offset=%x\n", offset);
DBG_88E("word_en=%x\n", word_en);
for (i = 0; i < PGPKT_DATA_SIZE; i++)
DBG_88E("data=%x \t", newdata[i]);
if (ret == _FAIL)
break;
}
if (idx == cnts)
break;
offset++;
i = 0;
word_en = 0xF;
_rtw_memset(newdata, 0xFF, PGPKT_DATA_SIZE);
} while (1);
Efuse_PowerSwitch(padapter, true, false);
exit:
kfree(map);
return ret;
}
u8 rtw_BT_efuse_map_write(struct adapter *padapter, u16 addr, u16 cnts, u8 *data)
{
u8 offset, word_en;
u8 *map;
u8 newdata[PGPKT_DATA_SIZE];
s32 i, idx;
u8 ret = _SUCCESS;
u16 mapLen = 0;
EFUSE_GetEfuseDefinition(padapter, EFUSE_BT, TYPE_EFUSE_MAP_LEN, (void *)&mapLen, false);
if ((addr + cnts) > mapLen)
return _FAIL;
map = rtw_zmalloc(mapLen);
if (map == NULL)
return _FAIL;
ret = rtw_BT_efuse_map_read(padapter, 0, mapLen, map);
if (ret == _FAIL)
goto exit;
Efuse_PowerSwitch(padapter, true, true);
offset = (addr >> 3);
word_en = 0xF;
_rtw_memset(newdata, 0xFF, PGPKT_DATA_SIZE);
i = addr & 0x7;
idx = 0;
if (i & 0x1) {
if (data[idx] != map[addr+idx]) {
word_en &= ~BIT(i >> 1);
newdata[i-1] = map[addr+idx-1];
newdata[i] = data[idx];
}
i++;
idx++;
}
do {
for (; i < PGPKT_DATA_SIZE; i += 2) {
if (cnts == idx)
break;
if ((cnts - idx) == 1) {
if (data[idx] != map[addr+idx]) {
word_en &= ~BIT(i >> 1);
newdata[i] = data[idx];
newdata[i+1] = map[addr+idx+1];
}
idx++;
break;
} else {
if ((data[idx] != map[addr+idx]) ||
(data[idx+1] != map[addr+idx+1])) {
word_en &= ~BIT(i >> 1);
newdata[i] = data[idx];
newdata[i+1] = data[idx + 1];
}
idx += 2;
}
if (idx == cnts)
break;
}
if (word_en != 0xF) {
DBG_88E("%s: offset=%#X\n", __func__, offset);
DBG_88E("%s: word_en=%#X\n", __func__, word_en);
DBG_88E("%s: data=", __func__);
for (i = 0; i < PGPKT_DATA_SIZE; i++)
DBG_88E("0x%02X ", newdata[i]);
DBG_88E("\n");
ret = Efuse_PgPacketWrite_BT(padapter, offset, word_en, newdata, false);
if (ret == _FAIL)
break;
}
if (idx == cnts)
break;
offset++;
i = 0;
word_en = 0xF;
_rtw_memset(newdata, 0xFF, PGPKT_DATA_SIZE);
} while (1);
Efuse_PowerSwitch(padapter, true, false);
exit:
kfree(map);
return ret;
}
static void
efuse_ShadowRead1Byte(
struct adapter *pAdapter,
u16 Offset,
u8 *Value)
{
struct eeprom_priv *pEEPROM = GET_EEPROM_EFUSE_PRIV(pAdapter);
*Value = pEEPROM->efuse_eeprom_data[Offset];
}
static void
efuse_ShadowRead2Byte(
struct adapter *pAdapter,
u16 Offset,
u16 *Value)
{
struct eeprom_priv *pEEPROM = GET_EEPROM_EFUSE_PRIV(pAdapter);
*Value = pEEPROM->efuse_eeprom_data[Offset];
*Value |= pEEPROM->efuse_eeprom_data[Offset+1]<<8;
}
static void
efuse_ShadowRead4Byte(
struct adapter *pAdapter,
u16 Offset,
u32 *Value)
{
struct eeprom_priv *pEEPROM = GET_EEPROM_EFUSE_PRIV(pAdapter);
*Value = pEEPROM->efuse_eeprom_data[Offset];
*Value |= pEEPROM->efuse_eeprom_data[Offset+1]<<8;
*Value |= pEEPROM->efuse_eeprom_data[Offset+2]<<16;
*Value |= pEEPROM->efuse_eeprom_data[Offset+3]<<24;
}
static void Efuse_ReadAllMap(struct adapter *pAdapter, u8 efuseType, u8 *Efuse, bool pseudo)
{
u16 mapLen = 0;
Efuse_PowerSwitch(pAdapter, false, true);
EFUSE_GetEfuseDefinition(pAdapter, efuseType, TYPE_EFUSE_MAP_LEN, (void *)&mapLen, pseudo);
efuse_ReadEFuse(pAdapter, efuseType, 0, mapLen, Efuse, pseudo);
Efuse_PowerSwitch(pAdapter, false, false);
}
void EFUSE_ShadowMapUpdate(
struct adapter *pAdapter,
u8 efuseType,
bool pseudo)
{
struct eeprom_priv *pEEPROM = GET_EEPROM_EFUSE_PRIV(pAdapter);
u16 mapLen = 0;
EFUSE_GetEfuseDefinition(pAdapter, efuseType, TYPE_EFUSE_MAP_LEN, (void *)&mapLen, pseudo);
if (pEEPROM->bautoload_fail_flag)
_rtw_memset(pEEPROM->efuse_eeprom_data, 0xFF, mapLen);
else
Efuse_ReadAllMap(pAdapter, efuseType, pEEPROM->efuse_eeprom_data, pseudo);
}
void EFUSE_ShadowRead(struct adapter *pAdapter, u8 Type, u16 Offset, u32 *Value)
{
if (Type == 1)
efuse_ShadowRead1Byte(pAdapter, Offset, (u8 *)Value);
else if (Type == 2)
efuse_ShadowRead2Byte(pAdapter, Offset, (u16 *)Value);
else if (Type == 4)
efuse_ShadowRead4Byte(pAdapter, Offset, (u32 *)Value);
}
