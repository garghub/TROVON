void card_bootload(struct net_device *dev)
{
struct ft1000_info *info = (struct ft1000_info *) netdev_priv(dev);
unsigned long flags;
u32 *pdata;
u32 size;
u32 i;
u32 templong;
DEBUG(0, "card_bootload is called\n");
pdata = (u32 *) bootimage;
size = sizeof(bootimage);
if (size & 0x0003)
size += 4;
spin_lock_irqsave(&info->dpram_lock, flags);
ft1000_write_reg(dev, FT1000_REG_DPRAM_ADDR, FT1000_DPRAM_BASE);
for (i = 0; i < (size >> 2); i++) {
templong = *pdata++;
outl(templong, dev->base_addr + FT1000_REG_MAG_DPDATA);
}
spin_unlock_irqrestore(&info->dpram_lock, flags);
}
u16 get_handshake(struct net_device *dev, u16 expected_value)
{
struct ft1000_info *info = (struct ft1000_info *) netdev_priv(dev);
u16 handshake;
u32 tempx;
int loopcnt;
loopcnt = 0;
while (loopcnt < MAX_DSP_WAIT_LOOPS) {
if (info->AsicID == ELECTRABUZZ_ID) {
ft1000_write_reg(dev, FT1000_REG_DPRAM_ADDR,
DWNLD_HANDSHAKE_LOC);
handshake = ft1000_read_reg(dev, FT1000_REG_DPRAM_DATA);
} else {
tempx =
ntohl(ft1000_read_dpram_mag_32
(dev, DWNLD_MAG_HANDSHAKE_LOC));
handshake = (u16) tempx;
}
if ((handshake == expected_value)
|| (handshake == HANDSHAKE_RESET_VALUE)) {
return handshake;
} else {
loopcnt++;
mdelay(DSP_WAIT_SLEEP_TIME);
}
}
return HANDSHAKE_TIMEOUT_VALUE;
}
void put_handshake(struct net_device *dev, u16 handshake_value)
{
struct ft1000_info *info = (struct ft1000_info *) netdev_priv(dev);
u32 tempx;
if (info->AsicID == ELECTRABUZZ_ID) {
ft1000_write_reg(dev, FT1000_REG_DPRAM_ADDR,
DWNLD_HANDSHAKE_LOC);
ft1000_write_reg(dev, FT1000_REG_DPRAM_DATA, handshake_value);
} else {
tempx = (u32) handshake_value;
tempx = ntohl(tempx);
ft1000_write_dpram_mag_32(dev, DWNLD_MAG_HANDSHAKE_LOC, tempx);
}
}
u16 get_request_type(struct net_device *dev)
{
struct ft1000_info *info = (struct ft1000_info *) netdev_priv(dev);
u16 request_type;
u32 tempx;
if (info->AsicID == ELECTRABUZZ_ID) {
ft1000_write_reg(dev, FT1000_REG_DPRAM_ADDR, DWNLD_TYPE_LOC);
request_type = ft1000_read_reg(dev, FT1000_REG_DPRAM_DATA);
} else {
tempx = ft1000_read_dpram_mag_32(dev, DWNLD_MAG_TYPE_LOC);
tempx = ntohl(tempx);
request_type = (u16) tempx;
}
return request_type;
}
long get_request_value(struct net_device *dev)
{
struct ft1000_info *info = (struct ft1000_info *) netdev_priv(dev);
long value;
u16 w_val;
if (info->AsicID == ELECTRABUZZ_ID) {
ft1000_write_reg(dev, FT1000_REG_DPRAM_ADDR,
DWNLD_SIZE_MSW_LOC);
w_val = ft1000_read_reg(dev, FT1000_REG_DPRAM_DATA);
value = (long)(w_val << 16);
ft1000_write_reg(dev, FT1000_REG_DPRAM_ADDR,
DWNLD_SIZE_LSW_LOC);
w_val = ft1000_read_reg(dev, FT1000_REG_DPRAM_DATA);
value = (long)(value | w_val);
} else {
value = ft1000_read_dpram_mag_32(dev, DWNLD_MAG_SIZE_LOC);
value = ntohl(value);
}
return value;
}
void put_request_value(struct net_device *dev, long lvalue)
{
struct ft1000_info *info = (struct ft1000_info *) netdev_priv(dev);
u16 size;
u32 tempx;
if (info->AsicID == ELECTRABUZZ_ID) {
size = (u16) (lvalue >> 16);
ft1000_write_reg(dev, FT1000_REG_DPRAM_ADDR,
DWNLD_SIZE_MSW_LOC);
ft1000_write_reg(dev, FT1000_REG_DPRAM_DATA, size);
size = (u16) (lvalue);
ft1000_write_reg(dev, FT1000_REG_DPRAM_ADDR,
DWNLD_SIZE_LSW_LOC);
ft1000_write_reg(dev, FT1000_REG_DPRAM_DATA, size);
} else {
tempx = ntohl(lvalue);
ft1000_write_dpram_mag_32(dev, DWNLD_MAG_SIZE_LOC, tempx);
}
}
u16 hdr_checksum(struct pseudo_hdr *pHdr)
{
u16 *usPtr = (u16 *) pHdr;
u16 chksum;
chksum = ((((((usPtr[0] ^ usPtr[1]) ^ usPtr[2]) ^ usPtr[3]) ^
usPtr[4]) ^ usPtr[5]) ^ usPtr[6]);
return chksum;
}
int card_download(struct net_device *dev, const u8 *pFileStart,
size_t FileLength)
{
struct ft1000_info *info = (struct ft1000_info *) netdev_priv(dev);
int Status = SUCCESS;
u32 uiState;
u16 handshake;
struct pseudo_hdr *pHdr;
u16 usHdrLength;
long word_length;
u16 request;
u16 temp;
struct prov_record *pprov_record;
u8 *pbuffer;
struct dsp_file_hdr *pFileHdr5;
struct dsp_image_info *pDspImageInfoV6 = NULL;
long requested_version;
bool bGoodVersion = false;
struct drv_msg *pMailBoxData;
u16 *pUsData = NULL;
u16 *pUsFile = NULL;
u8 *pUcFile = NULL;
u8 *pBootEnd = NULL;
u8 *pCodeEnd = NULL;
int imageN;
long file_version;
long loader_code_address = 0;
long loader_code_size = 0;
long run_address = 0;
long run_size = 0;
unsigned long flags;
unsigned long templong;
unsigned long image_chksum = 0;
file_version = *(long *)pFileStart;
if (file_version != 6) {
printk(KERN_ERR "ft1000: unsupported firmware version %ld\n", file_version);
Status = FAILURE;
}
uiState = STATE_START_DWNLD;
pFileHdr5 = (struct dsp_file_hdr *) pFileStart;
pUsFile = (u16 *) ((long)pFileStart + pFileHdr5->loader_offset);
pUcFile = (u8 *) ((long)pFileStart + pFileHdr5->loader_offset);
pBootEnd = (u8 *) ((long)pFileStart + pFileHdr5->loader_code_end);
loader_code_address = pFileHdr5->loader_code_address;
loader_code_size = pFileHdr5->loader_code_size;
bGoodVersion = false;
while ((Status == SUCCESS) && (uiState != STATE_DONE_FILE)) {
switch (uiState) {
case STATE_START_DWNLD:
handshake = get_handshake(dev, HANDSHAKE_DSP_BL_READY);
if (handshake == HANDSHAKE_DSP_BL_READY)
put_handshake(dev, HANDSHAKE_DRIVER_READY);
else
Status = FAILURE;
uiState = STATE_BOOT_DWNLD;
break;
case STATE_BOOT_DWNLD:
handshake = get_handshake(dev, HANDSHAKE_REQUEST);
if (handshake == HANDSHAKE_REQUEST) {
request = get_request_type(dev);
switch (request) {
case REQUEST_RUN_ADDRESS:
put_request_value(dev,
loader_code_address);
break;
case REQUEST_CODE_LENGTH:
put_request_value(dev,
loader_code_size);
break;
case REQUEST_DONE_BL:
pUsFile = (u16 *) ((long)pBootEnd);
pUcFile = (u8 *) ((long)pBootEnd);
uiState = STATE_CODE_DWNLD;
break;
case REQUEST_CODE_SEGMENT:
word_length = get_request_value(dev);
if (word_length > MAX_LENGTH) {
Status = FAILURE;
break;
}
if ((word_length * 2 + (long)pUcFile) >
(long)pBootEnd) {
Status = FAILURE;
break;
}
spin_lock_irqsave(&info->dpram_lock,
flags);
outw(DWNLD_MAG_PS_HDR_LOC,
dev->base_addr +
FT1000_REG_DPRAM_ADDR);
if (word_length & 0x01)
word_length++;
word_length = word_length / 2;
for (; word_length > 0; word_length--) {
templong = *pUsFile++;
templong |=
(*pUsFile++ << 16);
pUcFile += 4;
outl(templong,
dev->base_addr +
FT1000_REG_MAG_DPDATAL);
}
spin_unlock_irqrestore(&info->
dpram_lock,
flags);
break;
default:
Status = FAILURE;
break;
}
put_handshake(dev, HANDSHAKE_RESPONSE);
} else {
Status = FAILURE;
}
break;
case STATE_CODE_DWNLD:
handshake = get_handshake(dev, HANDSHAKE_REQUEST);
if (handshake == HANDSHAKE_REQUEST) {
request = get_request_type(dev);
switch (request) {
case REQUEST_FILE_CHECKSUM:
DEBUG(0,
"ft1000_dnld: REQUEST_FOR_CHECKSUM\n");
put_request_value(dev, image_chksum);
break;
case REQUEST_RUN_ADDRESS:
if (bGoodVersion) {
put_request_value(dev,
run_address);
} else {
Status = FAILURE;
break;
}
break;
case REQUEST_CODE_LENGTH:
if (bGoodVersion) {
put_request_value(dev,
run_size);
} else {
Status = FAILURE;
break;
}
break;
case REQUEST_DONE_CL:
pUsFile = (u16 *) ((long)pFileStart + pFileHdr5->commands_offset);
pUcFile = (u8 *) ((long)pFileStart + pFileHdr5->commands_offset);
uiState = STATE_DONE_DWNLD;
break;
case REQUEST_CODE_SEGMENT:
if (!bGoodVersion) {
Status = FAILURE;
break;
}
word_length = get_request_value(dev);
if (word_length > MAX_LENGTH) {
Status = FAILURE;
break;
}
if ((word_length * 2 + (long)pUcFile) >
(long)pCodeEnd) {
Status = FAILURE;
break;
}
outw(DWNLD_MAG_PS_HDR_LOC,
dev->base_addr +
FT1000_REG_DPRAM_ADDR);
if (word_length & 0x01)
word_length++;
word_length = word_length / 2;
for (; word_length > 0; word_length--) {
templong = *pUsFile++;
templong |=
(*pUsFile++ << 16);
pUcFile += 4;
outl(templong,
dev->base_addr +
FT1000_REG_MAG_DPDATAL);
}
break;
case REQUEST_MAILBOX_DATA:
word_length =
(long)(info->DSPInfoBlklen + 1) / 2;
put_request_value(dev, word_length);
pMailBoxData =
(struct drv_msg *) &info->DSPInfoBlk[0];
pUsData =
(u16 *) &pMailBoxData->data[0];
spin_lock_irqsave(&info->dpram_lock,
flags);
if (file_version == 5) {
ft1000_write_reg(dev,
FT1000_REG_DPRAM_ADDR,
DWNLD_PS_HDR_LOC);
for (; word_length > 0; word_length--) {
temp = ntohs(*pUsData);
ft1000_write_reg(dev,
FT1000_REG_DPRAM_DATA,
temp);
pUsData++;
}
} else {
outw(DWNLD_MAG_PS_HDR_LOC,
dev->base_addr +
FT1000_REG_DPRAM_ADDR);
if (word_length & 0x01)
word_length++;
word_length = word_length / 2;
for (; word_length > 0; word_length--) {
templong = *pUsData++;
templong |=
(*pUsData++ << 16);
outl(templong,
dev->base_addr +
FT1000_REG_MAG_DPDATAL);
}
}
spin_unlock_irqrestore(&info->
dpram_lock,
flags);
break;
case REQUEST_VERSION_INFO:
word_length =
pFileHdr5->version_data_size;
put_request_value(dev, word_length);
pUsFile =
(u16 *) ((long)pFileStart +
pFileHdr5->
version_data_offset);
spin_lock_irqsave(&info->dpram_lock,
flags);
outw(DWNLD_MAG_PS_HDR_LOC,
dev->base_addr +
FT1000_REG_DPRAM_ADDR);
if (word_length & 0x01)
word_length++;
word_length = word_length / 2;
for (; word_length > 0; word_length--) {
templong =
ntohs(*pUsFile++);
temp =
ntohs(*pUsFile++);
templong |=
(temp << 16);
outl(templong,
dev->base_addr +
FT1000_REG_MAG_DPDATAL);
}
spin_unlock_irqrestore(&info->
dpram_lock,
flags);
break;
case REQUEST_CODE_BY_VERSION:
bGoodVersion = false;
requested_version =
get_request_value(dev);
pDspImageInfoV6 =
(struct dsp_image_info *) ((long)
pFileStart
+
sizeof
(struct dsp_file_hdr));
for (imageN = 0;
imageN <
pFileHdr5->nDspImages;
imageN++) {
temp = (u16)
(pDspImageInfoV6->
version);
templong = temp;
temp = (u16)
(pDspImageInfoV6->
version >> 16);
templong |=
(temp << 16);
if (templong ==
requested_version) {
bGoodVersion =
true;
pUsFile =
(u16
*) ((long)
pFileStart
+
pDspImageInfoV6->
begin_offset);
pUcFile =
(u8
*) ((long)
pFileStart
+
pDspImageInfoV6->
begin_offset);
pCodeEnd =
(u8
*) ((long)
pFileStart
+
pDspImageInfoV6->
end_offset);
run_address =
pDspImageInfoV6->
run_address;
run_size =
pDspImageInfoV6->
image_size;
image_chksum =
(u32)
pDspImageInfoV6->
checksum;
DEBUG(0,
"ft1000_dnld: image_chksum = 0x%8x\n",
(unsigned
int)
image_chksum);
break;
}
pDspImageInfoV6++;
}
if (!bGoodVersion) {
Status = FAILURE;
break;
}
break;
default:
Status = FAILURE;
break;
}
put_handshake(dev, HANDSHAKE_RESPONSE);
} else {
Status = FAILURE;
}
break;
case STATE_DONE_DWNLD:
if (((unsigned long) (pUcFile) - (unsigned long) pFileStart) >=
(unsigned long) FileLength) {
uiState = STATE_DONE_FILE;
break;
}
pHdr = (struct pseudo_hdr *) pUsFile;
if (pHdr->portdest == 0x80
&& (pHdr->portsrc == 0x00
|| pHdr->portsrc == 0x10 )) {
uiState = STATE_SECTION_PROV;
} else {
DEBUG(1,
"FT1000:download:Download error: Bad Port IDs in Pseudo Record\n");
DEBUG(1, "\t Port Source = 0x%2.2x\n",
pHdr->portsrc);
DEBUG(1, "\t Port Destination = 0x%2.2x\n",
pHdr->portdest);
Status = FAILURE;
}
break;
case STATE_SECTION_PROV:
pHdr = (struct pseudo_hdr *) pUcFile;
if (pHdr->checksum == hdr_checksum(pHdr)) {
if (pHdr->portdest != 0x80 ) {
uiState = STATE_DONE_PROV;
break;
}
usHdrLength = ntohs(pHdr->length);
pbuffer =
kmalloc((usHdrLength + sizeof(struct pseudo_hdr)),
GFP_ATOMIC);
if (pbuffer) {
memcpy(pbuffer, (void *)pUcFile,
(u32) (usHdrLength +
sizeof(struct pseudo_hdr)));
pprov_record =
kmalloc(sizeof(struct prov_record),
GFP_ATOMIC);
if (pprov_record) {
pprov_record->pprov_data =
pbuffer;
list_add_tail(&pprov_record->
list,
&info->prov_list);
pUcFile =
(u8 *) ((unsigned long) pUcFile +
(unsigned long) ((usHdrLength + 1) & 0xFFFFFFFE) + sizeof(struct pseudo_hdr));
if ((unsigned long) (pUcFile) -
(unsigned long) (pFileStart) >=
(unsigned long) FileLength) {
uiState =
STATE_DONE_FILE;
}
} else {
kfree(pbuffer);
Status = FAILURE;
}
} else {
Status = FAILURE;
}
} else {
Status = FAILURE;
}
break;
case STATE_DONE_PROV:
uiState = STATE_DONE_FILE;
break;
default:
Status = FAILURE;
break;
}
}
return Status;
}
