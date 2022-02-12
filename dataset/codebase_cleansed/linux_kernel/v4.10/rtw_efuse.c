void Efuse_PowerSwitch(
struct adapter *pAdapter,
u8 bWrite,
u8 PwrState)
{
u8 tempval;
u16 tmpV16;
if (PwrState) {
usb_write8(pAdapter, REG_EFUSE_ACCESS, EFUSE_ACCESS_ON);
tmpV16 = usb_read16(pAdapter, REG_SYS_ISO_CTRL);
if (!(tmpV16 & PWC_EV12V)) {
tmpV16 |= PWC_EV12V;
usb_write16(pAdapter, REG_SYS_ISO_CTRL, tmpV16);
}
tmpV16 = usb_read16(pAdapter, REG_SYS_FUNC_EN);
if (!(tmpV16 & FEN_ELDR)) {
tmpV16 |= FEN_ELDR;
usb_write16(pAdapter, REG_SYS_FUNC_EN, tmpV16);
}
tmpV16 = usb_read16(pAdapter, REG_SYS_CLKR);
if ((!(tmpV16 & LOADER_CLK_EN)) || (!(tmpV16 & ANA8M))) {
tmpV16 |= (LOADER_CLK_EN | ANA8M);
usb_write16(pAdapter, REG_SYS_CLKR, tmpV16);
}
if (bWrite) {
tempval = usb_read8(pAdapter, EFUSE_TEST+3);
tempval &= 0x0F;
tempval |= (VOLTAGE_V25 << 4);
usb_write8(pAdapter, EFUSE_TEST+3, (tempval | 0x80));
}
} else {
usb_write8(pAdapter, REG_EFUSE_ACCESS, EFUSE_ACCESS_OFF);
if (bWrite) {
tempval = usb_read8(pAdapter, EFUSE_TEST+3);
usb_write8(pAdapter, EFUSE_TEST+3, (tempval & 0x7F));
}
}
}
static void
efuse_phymap_to_logical(u8 *phymap, u16 _offset, u16 _size_byte, u8 *pbuf)
{
u8 *efuseTbl = NULL;
u8 rtemp8;
u16 eFuse_Addr = 0;
u8 offset, wren;
u16 i, j;
u16 **eFuseWord = NULL;
u16 efuse_utilized = 0;
u8 u1temp = 0;
efuseTbl = kzalloc(EFUSE_MAP_LEN_88E, GFP_KERNEL);
if (!efuseTbl)
return;
eFuseWord = (u16 **)rtw_malloc2d(EFUSE_MAX_SECTION_88E, EFUSE_MAX_WORD_UNIT, sizeof(u16));
if (!eFuseWord) {
DBG_88E("%s: alloc eFuseWord fail!\n", __func__);
goto eFuseWord_failed;
}
for (i = 0; i < EFUSE_MAX_SECTION_88E; i++)
for (j = 0; j < EFUSE_MAX_WORD_UNIT; j++)
eFuseWord[i][j] = 0xFFFF;
rtemp8 = *(phymap+eFuse_Addr);
if (rtemp8 != 0xFF) {
efuse_utilized++;
eFuse_Addr++;
} else {
DBG_88E("EFUSE is empty efuse_Addr-%d efuse_data =%x\n", eFuse_Addr, rtemp8);
goto exit;
}
while ((rtemp8 != 0xFF) && (eFuse_Addr < EFUSE_REAL_CONTENT_LEN_88E)) {
if ((rtemp8 & 0x1F) == 0x0F) {
u1temp = (rtemp8 & 0xE0) >> 5;
rtemp8 = *(phymap+eFuse_Addr);
if ((rtemp8 & 0x0F) == 0x0F) {
eFuse_Addr++;
rtemp8 = *(phymap+eFuse_Addr);
if (rtemp8 != 0xFF && (eFuse_Addr < EFUSE_REAL_CONTENT_LEN_88E))
eFuse_Addr++;
continue;
} else {
offset = ((rtemp8 & 0xF0) >> 1) | u1temp;
wren = rtemp8 & 0x0F;
eFuse_Addr++;
}
} else {
offset = (rtemp8 >> 4) & 0x0f;
wren = rtemp8 & 0x0f;
}
if (offset < EFUSE_MAX_SECTION_88E) {
for (i = 0; i < EFUSE_MAX_WORD_UNIT; i++) {
if (!(wren & 0x01)) {
rtemp8 = *(phymap+eFuse_Addr);
eFuse_Addr++;
efuse_utilized++;
eFuseWord[offset][i] = (rtemp8 & 0xff);
if (eFuse_Addr >= EFUSE_REAL_CONTENT_LEN_88E)
break;
rtemp8 = *(phymap+eFuse_Addr);
eFuse_Addr++;
efuse_utilized++;
eFuseWord[offset][i] |= (((u16)rtemp8 << 8) & 0xff00);
if (eFuse_Addr >= EFUSE_REAL_CONTENT_LEN_88E)
break;
}
wren >>= 1;
}
}
rtemp8 = *(phymap+eFuse_Addr);
if (rtemp8 != 0xFF && (eFuse_Addr < EFUSE_REAL_CONTENT_LEN_88E)) {
efuse_utilized++;
eFuse_Addr++;
}
}
for (i = 0; i < EFUSE_MAX_SECTION_88E; i++) {
for (j = 0; j < EFUSE_MAX_WORD_UNIT; j++) {
efuseTbl[(i*8)+(j*2)] = (eFuseWord[i][j] & 0xff);
efuseTbl[(i*8)+((j*2)+1)] = ((eFuseWord[i][j] >> 8) & 0xff);
}
}
for (i = 0; i < _size_byte; i++)
pbuf[i] = efuseTbl[_offset+i];
exit:
kfree(eFuseWord);
eFuseWord_failed:
kfree(efuseTbl);
}
static void efuse_read_phymap_from_txpktbuf(
struct adapter *adapter,
int bcnhead,
u8 *content,
u16 *size
)
{
u16 dbg_addr = 0;
unsigned long start = 0;
u8 reg_0x143 = 0;
u32 lo32 = 0, hi32 = 0;
u16 len = 0, count = 0;
int i = 0;
u16 limit = *size;
u8 *pos = content;
if (bcnhead < 0)
bcnhead = usb_read8(adapter, REG_TDECTRL+1);
DBG_88E("%s bcnhead:%d\n", __func__, bcnhead);
usb_write8(adapter, REG_PKT_BUFF_ACCESS_CTRL, TXPKT_BUF_SELECT);
dbg_addr = bcnhead*128/8;
while (1) {
usb_write16(adapter, REG_PKTBUF_DBG_ADDR, dbg_addr+i);
usb_write8(adapter, REG_TXPKTBUF_DBG, 0);
start = jiffies;
while (!(reg_0x143 = usb_read8(adapter, REG_TXPKTBUF_DBG)) &&
jiffies_to_msecs(jiffies - start) < 1000) {
DBG_88E("%s polling reg_0x143:0x%02x, reg_0x106:0x%02x\n", __func__, reg_0x143, usb_read8(adapter, 0x106));
usleep_range(1000, 2000);
}
lo32 = usb_read32(adapter, REG_PKTBUF_DBG_DATA_L);
hi32 = usb_read32(adapter, REG_PKTBUF_DBG_DATA_H);
if (i == 0) {
u8 lenc[2];
u16 lenbak, aaabak;
u16 aaa;
lenc[0] = usb_read8(adapter, REG_PKTBUF_DBG_DATA_L);
lenc[1] = usb_read8(adapter, REG_PKTBUF_DBG_DATA_L+1);
aaabak = le16_to_cpup((__le16 *)lenc);
lenbak = le16_to_cpu(*((__le16 *)lenc));
aaa = le16_to_cpup((__le16 *)&lo32);
len = le16_to_cpu(*((__le16 *)&lo32));
limit = min_t(u16, len-2, limit);
DBG_88E("%s len:%u, lenbak:%u, aaa:%u, aaabak:%u\n", __func__, len, lenbak, aaa, aaabak);
memcpy(pos, ((u8 *)&lo32)+2, (limit >= count+2) ? 2 : limit-count);
count += (limit >= count+2) ? 2 : limit-count;
pos = content+count;
} else {
memcpy(pos, ((u8 *)&lo32), (limit >= count+4) ? 4 : limit-count);
count += (limit >= count+4) ? 4 : limit-count;
pos = content+count;
}
if (limit > count && len-2 > count) {
memcpy(pos, (u8 *)&hi32, (limit >= count+4) ? 4 : limit-count);
count += (limit >= count+4) ? 4 : limit-count;
pos = content+count;
}
if (limit <= count || len-2 <= count)
break;
i++;
}
usb_write8(adapter, REG_PKT_BUFF_ACCESS_CTRL, DISABLE_TRXPKT_BUF_ACCESS);
DBG_88E("%s read count:%u\n", __func__, count);
*size = count;
}
static s32 iol_read_efuse(struct adapter *padapter, u8 txpktbuf_bndy, u16 offset, u16 size_byte, u8 *logical_map)
{
s32 status = _FAIL;
u8 physical_map[512];
u16 size = 512;
usb_write8(padapter, REG_TDECTRL+1, txpktbuf_bndy);
memset(physical_map, 0xFF, 512);
usb_write8(padapter, REG_PKT_BUFF_ACCESS_CTRL, TXPKT_BUF_SELECT);
status = iol_execute(padapter, CMD_READ_EFUSE_MAP);
if (status == _SUCCESS)
efuse_read_phymap_from_txpktbuf(padapter, txpktbuf_bndy, physical_map, &size);
efuse_phymap_to_logical(physical_map, offset, size_byte, logical_map);
return status;
}
void efuse_ReadEFuse(struct adapter *Adapter, u8 efuseType, u16 _offset, u16 _size_byte, u8 *pbuf)
{
if (rtw_IOL_applied(Adapter)) {
rtw_hal_power_on(Adapter);
iol_mode_enable(Adapter, 1);
iol_read_efuse(Adapter, 0, _offset, _size_byte, pbuf);
iol_mode_enable(Adapter, 0);
}
}
u8 Efuse_WordEnableDataWrite(struct adapter *pAdapter, u16 efuse_addr, u8 word_en, u8 *data)
{
u16 tmpaddr = 0;
u16 start_addr = efuse_addr;
u8 badworden = 0x0F;
u8 tmpdata[8];
memset(tmpdata, 0xff, PGPKT_DATA_SIZE);
if (!(word_en & BIT(0))) {
tmpaddr = start_addr;
efuse_OneByteWrite(pAdapter, start_addr++, data[0]);
efuse_OneByteWrite(pAdapter, start_addr++, data[1]);
efuse_OneByteRead(pAdapter, tmpaddr, &tmpdata[0]);
efuse_OneByteRead(pAdapter, tmpaddr+1, &tmpdata[1]);
if ((data[0] != tmpdata[0]) || (data[1] != tmpdata[1]))
badworden &= (~BIT(0));
}
if (!(word_en & BIT(1))) {
tmpaddr = start_addr;
efuse_OneByteWrite(pAdapter, start_addr++, data[2]);
efuse_OneByteWrite(pAdapter, start_addr++, data[3]);
efuse_OneByteRead(pAdapter, tmpaddr, &tmpdata[2]);
efuse_OneByteRead(pAdapter, tmpaddr+1, &tmpdata[3]);
if ((data[2] != tmpdata[2]) || (data[3] != tmpdata[3]))
badworden &= (~BIT(1));
}
if (!(word_en & BIT(2))) {
tmpaddr = start_addr;
efuse_OneByteWrite(pAdapter, start_addr++, data[4]);
efuse_OneByteWrite(pAdapter, start_addr++, data[5]);
efuse_OneByteRead(pAdapter, tmpaddr, &tmpdata[4]);
efuse_OneByteRead(pAdapter, tmpaddr+1, &tmpdata[5]);
if ((data[4] != tmpdata[4]) || (data[5] != tmpdata[5]))
badworden &= (~BIT(2));
}
if (!(word_en & BIT(3))) {
tmpaddr = start_addr;
efuse_OneByteWrite(pAdapter, start_addr++, data[6]);
efuse_OneByteWrite(pAdapter, start_addr++, data[7]);
efuse_OneByteRead(pAdapter, tmpaddr, &tmpdata[6]);
efuse_OneByteRead(pAdapter, tmpaddr+1, &tmpdata[7]);
if ((data[6] != tmpdata[6]) || (data[7] != tmpdata[7]))
badworden &= (~BIT(3));
}
return badworden;
}
static u16 Efuse_GetCurrentSize(struct adapter *pAdapter)
{
int bContinual = true;
u16 efuse_addr = 0;
u8 hoffset = 0, hworden = 0;
u8 efuse_data, word_cnts = 0;
rtw_hal_get_hwreg(pAdapter, HW_VAR_EFUSE_BYTES, (u8 *)&efuse_addr);
while (bContinual &&
efuse_OneByteRead(pAdapter, efuse_addr, &efuse_data) &&
AVAILABLE_EFUSE_ADDR(efuse_addr)) {
if (efuse_data != 0xFF) {
if ((efuse_data&0x1F) == 0x0F) {
hoffset = efuse_data;
efuse_addr++;
efuse_OneByteRead(pAdapter, efuse_addr, &efuse_data);
if ((efuse_data & 0x0F) == 0x0F) {
efuse_addr++;
continue;
} else {
hoffset = ((hoffset & 0xE0) >> 5) | ((efuse_data & 0xF0) >> 1);
hworden = efuse_data & 0x0F;
}
} else {
hoffset = (efuse_data>>4) & 0x0F;
hworden = efuse_data & 0x0F;
}
word_cnts = Efuse_CalculateWordCnts(hworden);
efuse_addr = efuse_addr + (word_cnts*2)+1;
} else {
bContinual = false;
}
}
rtw_hal_set_hwreg(pAdapter, HW_VAR_EFUSE_BYTES, (u8 *)&efuse_addr);
return efuse_addr;
}
int Efuse_PgPacketRead(struct adapter *pAdapter, u8 offset, u8 *data)
{
u8 ReadState = PG_STATE_HEADER;
int bContinual = true;
int bDataEmpty = true;
u8 efuse_data, word_cnts = 0;
u16 efuse_addr = 0;
u8 hoffset = 0, hworden = 0;
u8 tmpidx = 0;
u8 tmpdata[8];
u8 tmp_header = 0;
if (!data)
return false;
if (offset > EFUSE_MAX_SECTION_88E)
return false;
memset(data, 0xff, sizeof(u8) * PGPKT_DATA_SIZE);
memset(tmpdata, 0xff, sizeof(u8) * PGPKT_DATA_SIZE);
while (bContinual && AVAILABLE_EFUSE_ADDR(efuse_addr)) {
if (ReadState & PG_STATE_HEADER) {
if (efuse_OneByteRead(pAdapter, efuse_addr, &efuse_data) && (efuse_data != 0xFF)) {
if (EXT_HEADER(efuse_data)) {
tmp_header = efuse_data;
efuse_addr++;
efuse_OneByteRead(pAdapter, efuse_addr, &efuse_data);
if (!ALL_WORDS_DISABLED(efuse_data)) {
hoffset = ((tmp_header & 0xE0) >> 5) | ((efuse_data & 0xF0) >> 1);
hworden = efuse_data & 0x0F;
} else {
DBG_88E("Error, All words disabled\n");
efuse_addr++;
continue;
}
} else {
hoffset = (efuse_data>>4) & 0x0F;
hworden = efuse_data & 0x0F;
}
word_cnts = Efuse_CalculateWordCnts(hworden);
bDataEmpty = true;
if (hoffset == offset) {
for (tmpidx = 0; tmpidx < word_cnts*2; tmpidx++) {
if (efuse_OneByteRead(pAdapter, efuse_addr+1+tmpidx, &efuse_data)) {
tmpdata[tmpidx] = efuse_data;
if (efuse_data != 0xff)
bDataEmpty = false;
}
}
if (bDataEmpty == false) {
ReadState = PG_STATE_DATA;
} else {
efuse_addr = efuse_addr + (word_cnts*2)+1;
ReadState = PG_STATE_HEADER;
}
} else {
efuse_addr = efuse_addr + (word_cnts*2)+1;
ReadState = PG_STATE_HEADER;
}
} else {
bContinual = false;
}
} else if (ReadState & PG_STATE_DATA) {
efuse_WordEnableDataRead(hworden, tmpdata, data);
efuse_addr = efuse_addr + (word_cnts*2)+1;
ReadState = PG_STATE_HEADER;
}
}
if ((data[0] == 0xff) && (data[1] == 0xff) && (data[2] == 0xff) && (data[3] == 0xff) &&
(data[4] == 0xff) && (data[5] == 0xff) && (data[6] == 0xff) && (data[7] == 0xff))
return false;
else
return true;
}
static bool hal_EfuseFixHeaderProcess(struct adapter *pAdapter, u8 efuseType, struct pgpkt *pFixPkt, u16 *pAddr)
{
u8 originaldata[8], badworden = 0;
u16 efuse_addr = *pAddr;
u32 PgWriteSuccess = 0;
memset(originaldata, 0xff, 8);
if (Efuse_PgPacketRead(pAdapter, pFixPkt->offset, originaldata)) {
badworden = Efuse_WordEnableDataWrite(pAdapter, efuse_addr+1, pFixPkt->word_en, originaldata);
if (badworden != 0xf) {
PgWriteSuccess = Efuse_PgPacketWrite(pAdapter, pFixPkt->offset, badworden, originaldata);
if (!PgWriteSuccess)
return false;
else
efuse_addr = Efuse_GetCurrentSize(pAdapter);
} else {
efuse_addr = efuse_addr + (pFixPkt->word_cnts*2) + 1;
}
} else {
efuse_addr = efuse_addr + (pFixPkt->word_cnts*2) + 1;
}
*pAddr = efuse_addr;
return true;
}
static bool hal_EfusePgPacketWrite2ByteHeader(struct adapter *pAdapter, u8 efuseType, u16 *pAddr, struct pgpkt *pTargetPkt)
{
bool bRet = false;
u16 efuse_addr = *pAddr;
u16 efuse_max_available_len =
EFUSE_REAL_CONTENT_LEN_88E - EFUSE_OOB_PROTECT_BYTES_88E;
u8 pg_header = 0, tmp_header = 0, pg_header_temp = 0;
u8 repeatcnt = 0;
while (efuse_addr < efuse_max_available_len) {
pg_header = ((pTargetPkt->offset & 0x07) << 5) | 0x0F;
efuse_OneByteWrite(pAdapter, efuse_addr, pg_header);
efuse_OneByteRead(pAdapter, efuse_addr, &tmp_header);
while (tmp_header == 0xFF) {
if (repeatcnt++ > EFUSE_REPEAT_THRESHOLD_)
return false;
efuse_OneByteWrite(pAdapter, efuse_addr, pg_header);
efuse_OneByteRead(pAdapter, efuse_addr, &tmp_header);
}
if (tmp_header == pg_header) {
efuse_addr++;
pg_header_temp = pg_header;
pg_header = ((pTargetPkt->offset & 0x78) << 1) | pTargetPkt->word_en;
efuse_OneByteWrite(pAdapter, efuse_addr, pg_header);
efuse_OneByteRead(pAdapter, efuse_addr, &tmp_header);
while (tmp_header == 0xFF) {
if (repeatcnt++ > EFUSE_REPEAT_THRESHOLD_)
return false;
efuse_OneByteWrite(pAdapter, efuse_addr, pg_header);
efuse_OneByteRead(pAdapter, efuse_addr, &tmp_header);
}
if ((tmp_header & 0x0F) == 0x0F) {
if (repeatcnt++ > EFUSE_REPEAT_THRESHOLD_) {
return false;
}
efuse_addr++;
continue;
} else if (pg_header != tmp_header) {
struct pgpkt fixPkt;
fixPkt.offset = ((pg_header_temp & 0xE0) >> 5) | ((tmp_header & 0xF0) >> 1);
fixPkt.word_en = tmp_header & 0x0F;
fixPkt.word_cnts = Efuse_CalculateWordCnts(fixPkt.word_en);
if (!hal_EfuseFixHeaderProcess(pAdapter, efuseType, &fixPkt, &efuse_addr))
return false;
} else {
bRet = true;
break;
}
} else if ((tmp_header & 0x1F) == 0x0F) {
efuse_addr += 2;
continue;
}
}
*pAddr = efuse_addr;
return bRet;
}
static bool hal_EfusePgPacketWrite1ByteHeader(struct adapter *pAdapter, u8 efuseType, u16 *pAddr, struct pgpkt *pTargetPkt)
{
bool bRet = false;
u8 pg_header = 0, tmp_header = 0;
u16 efuse_addr = *pAddr;
u8 repeatcnt = 0;
pg_header = ((pTargetPkt->offset << 4) & 0xf0) | pTargetPkt->word_en;
efuse_OneByteWrite(pAdapter, efuse_addr, pg_header);
efuse_OneByteRead(pAdapter, efuse_addr, &tmp_header);
while (tmp_header == 0xFF) {
if (repeatcnt++ > EFUSE_REPEAT_THRESHOLD_)
return false;
efuse_OneByteWrite(pAdapter, efuse_addr, pg_header);
efuse_OneByteRead(pAdapter, efuse_addr, &tmp_header);
}
if (pg_header == tmp_header) {
bRet = true;
} else {
struct pgpkt fixPkt;
fixPkt.offset = (tmp_header>>4) & 0x0F;
fixPkt.word_en = tmp_header & 0x0F;
fixPkt.word_cnts = Efuse_CalculateWordCnts(fixPkt.word_en);
if (!hal_EfuseFixHeaderProcess(pAdapter, efuseType, &fixPkt, &efuse_addr))
return false;
}
*pAddr = efuse_addr;
return bRet;
}
static bool hal_EfusePgPacketWriteData(struct adapter *pAdapter, u8 efuseType, u16 *pAddr, struct pgpkt *pTargetPkt)
{
u16 efuse_addr = *pAddr;
u8 badworden = 0;
u32 PgWriteSuccess = 0;
badworden = 0x0f;
badworden = Efuse_WordEnableDataWrite(pAdapter, efuse_addr+1, pTargetPkt->word_en, pTargetPkt->data);
if (badworden == 0x0F) {
return true;
}
PgWriteSuccess = Efuse_PgPacketWrite(pAdapter, pTargetPkt->offset, badworden, pTargetPkt->data);
if (!PgWriteSuccess)
return false;
else
return true;
}
static bool
hal_EfusePgPacketWriteHeader(
struct adapter *pAdapter,
u8 efuseType,
u16 *pAddr,
struct pgpkt *pTargetPkt)
{
bool bRet = false;
if (pTargetPkt->offset >= EFUSE_MAX_SECTION_BASE)
bRet = hal_EfusePgPacketWrite2ByteHeader(pAdapter, efuseType, pAddr, pTargetPkt);
else
bRet = hal_EfusePgPacketWrite1ByteHeader(pAdapter, efuseType, pAddr, pTargetPkt);
return bRet;
}
static bool wordEnMatched(struct pgpkt *pTargetPkt, struct pgpkt *pCurPkt,
u8 *pWden)
{
u8 match_word_en = 0x0F;
if (((pTargetPkt->word_en & BIT(0)) == 0) &&
((pCurPkt->word_en & BIT(0)) == 0))
match_word_en &= ~BIT(0);
if (((pTargetPkt->word_en & BIT(1)) == 0) &&
((pCurPkt->word_en & BIT(1)) == 0))
match_word_en &= ~BIT(1);
if (((pTargetPkt->word_en & BIT(2)) == 0) &&
((pCurPkt->word_en & BIT(2)) == 0))
match_word_en &= ~BIT(2);
if (((pTargetPkt->word_en & BIT(3)) == 0) &&
((pCurPkt->word_en & BIT(3)) == 0))
match_word_en &= ~BIT(3);
*pWden = match_word_en;
if (match_word_en != 0xf)
return true;
else
return false;
}
static bool hal_EfuseCheckIfDatafollowed(struct adapter *pAdapter, u8 word_cnts, u16 startAddr)
{
bool bRet = false;
u8 i, efuse_data;
for (i = 0; i < (word_cnts*2); i++) {
if (efuse_OneByteRead(pAdapter, (startAddr+i), &efuse_data) && (efuse_data != 0xFF))
bRet = true;
}
return bRet;
}
static bool hal_EfusePartialWriteCheck(struct adapter *pAdapter, u8 efuseType, u16 *pAddr, struct pgpkt *pTargetPkt)
{
bool bRet = false;
u8 i, efuse_data = 0, cur_header = 0;
u8 matched_wden = 0, badworden = 0;
u16 startAddr = 0;
u16 efuse_max_available_len =
EFUSE_REAL_CONTENT_LEN_88E - EFUSE_OOB_PROTECT_BYTES_88E;
struct pgpkt curPkt;
rtw_hal_get_hwreg(pAdapter, HW_VAR_EFUSE_BYTES, (u8 *)&startAddr);
startAddr %= EFUSE_REAL_CONTENT_LEN;
while (1) {
if (startAddr >= efuse_max_available_len) {
bRet = false;
break;
}
if (efuse_OneByteRead(pAdapter, startAddr, &efuse_data) && (efuse_data != 0xFF)) {
if (EXT_HEADER(efuse_data)) {
cur_header = efuse_data;
startAddr++;
efuse_OneByteRead(pAdapter, startAddr, &efuse_data);
if (ALL_WORDS_DISABLED(efuse_data)) {
bRet = false;
break;
} else {
curPkt.offset = ((cur_header & 0xE0) >> 5) | ((efuse_data & 0xF0) >> 1);
curPkt.word_en = efuse_data & 0x0F;
}
} else {
cur_header = efuse_data;
curPkt.offset = (cur_header>>4) & 0x0F;
curPkt.word_en = cur_header & 0x0F;
}
curPkt.word_cnts = Efuse_CalculateWordCnts(curPkt.word_en);
if ((curPkt.offset == pTargetPkt->offset) &&
(!hal_EfuseCheckIfDatafollowed(pAdapter, curPkt.word_cnts, startAddr+1)) &&
wordEnMatched(pTargetPkt, &curPkt, &matched_wden)) {
badworden = Efuse_WordEnableDataWrite(pAdapter, startAddr+1, matched_wden, pTargetPkt->data);
if (badworden != 0x0F) {
u32 PgWriteSuccess = 0;
PgWriteSuccess = Efuse_PgPacketWrite(pAdapter, pTargetPkt->offset, badworden, pTargetPkt->data);
if (!PgWriteSuccess) {
bRet = false;
break;
}
}
for (i = 0; i < 4; i++) {
if ((matched_wden & (0x1<<i)) == 0)
pTargetPkt->word_en |= (0x1<<i);
}
pTargetPkt->word_cnts = Efuse_CalculateWordCnts(pTargetPkt->word_en);
}
startAddr = startAddr + (curPkt.word_cnts*2) + 1;
} else {
*pAddr = startAddr;
bRet = true;
break;
}
}
return bRet;
}
static bool
hal_EfusePgCheckAvailableAddr(
struct adapter *pAdapter,
u8 efuseType
)
{
if (Efuse_GetCurrentSize(pAdapter) >= EFUSE_MAP_LEN_88E)
return false;
return true;
}
static void hal_EfuseConstructPGPkt(u8 offset, u8 word_en, u8 *pData, struct pgpkt *pTargetPkt)
{
memset((void *)pTargetPkt->data, 0xFF, sizeof(u8)*8);
pTargetPkt->offset = offset;
pTargetPkt->word_en = word_en;
efuse_WordEnableDataRead(word_en, pData, pTargetPkt->data);
pTargetPkt->word_cnts = Efuse_CalculateWordCnts(pTargetPkt->word_en);
}
bool Efuse_PgPacketWrite(struct adapter *pAdapter, u8 offset, u8 word_en, u8 *pData)
{
struct pgpkt targetPkt;
u16 startAddr = 0;
u8 efuseType = EFUSE_WIFI;
if (!hal_EfusePgCheckAvailableAddr(pAdapter, efuseType))
return false;
hal_EfuseConstructPGPkt(offset, word_en, pData, &targetPkt);
if (!hal_EfusePartialWriteCheck(pAdapter, efuseType, &startAddr, &targetPkt))
return false;
if (!hal_EfusePgPacketWriteHeader(pAdapter, efuseType, &startAddr, &targetPkt))
return false;
if (!hal_EfusePgPacketWriteData(pAdapter, efuseType, &startAddr, &targetPkt))
return false;
return true;
}
u8 Efuse_CalculateWordCnts(u8 word_en)
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
u8 efuse_OneByteRead(struct adapter *pAdapter, u16 addr, u8 *data)
{
u8 tmpidx = 0;
u8 result;
usb_write8(pAdapter, EFUSE_CTRL+1, (u8)(addr & 0xff));
usb_write8(pAdapter, EFUSE_CTRL+2, ((u8)((addr>>8) & 0x03)) |
(usb_read8(pAdapter, EFUSE_CTRL+2) & 0xFC));
usb_write8(pAdapter, EFUSE_CTRL+3, 0x72);
while (!(0x80 & usb_read8(pAdapter, EFUSE_CTRL+3)) && (tmpidx < 100))
tmpidx++;
if (tmpidx < 100) {
*data = usb_read8(pAdapter, EFUSE_CTRL);
result = true;
} else {
*data = 0xff;
result = false;
}
return result;
}
u8 efuse_OneByteWrite(struct adapter *pAdapter, u16 addr, u8 data)
{
u8 tmpidx = 0;
u8 result;
usb_write8(pAdapter, EFUSE_CTRL+1, (u8)(addr&0xff));
usb_write8(pAdapter, EFUSE_CTRL+2,
(usb_read8(pAdapter, EFUSE_CTRL+2) & 0xFC) |
(u8)((addr>>8) & 0x03));
usb_write8(pAdapter, EFUSE_CTRL, data);
usb_write8(pAdapter, EFUSE_CTRL+3, 0xF2);
while ((0x80 & usb_read8(pAdapter, EFUSE_CTRL+3)) && (tmpidx < 100))
tmpidx++;
if (tmpidx < 100)
result = true;
else
result = false;
return result;
}
void efuse_WordEnableDataRead(u8 word_en, u8 *sourdata, u8 *targetdata)
{
if (!(word_en & BIT(0))) {
targetdata[0] = sourdata[0];
targetdata[1] = sourdata[1];
}
if (!(word_en & BIT(1))) {
targetdata[2] = sourdata[2];
targetdata[3] = sourdata[3];
}
if (!(word_en & BIT(2))) {
targetdata[4] = sourdata[4];
targetdata[5] = sourdata[5];
}
if (!(word_en & BIT(3))) {
targetdata[6] = sourdata[6];
targetdata[7] = sourdata[7];
}
}
static void Efuse_ReadAllMap(struct adapter *pAdapter, u8 efuseType, u8 *Efuse)
{
Efuse_PowerSwitch(pAdapter, false, true);
efuse_ReadEFuse(pAdapter, efuseType, 0, EFUSE_MAP_LEN_88E, Efuse);
Efuse_PowerSwitch(pAdapter, false, false);
}
void EFUSE_ShadowMapUpdate(
struct adapter *pAdapter,
u8 efuseType)
{
struct eeprom_priv *pEEPROM = GET_EEPROM_EFUSE_PRIV(pAdapter);
if (pEEPROM->bautoload_fail_flag)
memset(pEEPROM->efuse_eeprom_data, 0xFF, EFUSE_MAP_LEN_88E);
else
Efuse_ReadAllMap(pAdapter, efuseType, pEEPROM->efuse_eeprom_data);
}
