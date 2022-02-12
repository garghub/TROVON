void card_bootload(struct net_device *dev)
{
FT1000_INFO *info = (PFT1000_INFO) netdev_priv(dev);
unsigned long flags;
PULONG pdata;
UINT size;
UINT i;
ULONG templong;
DEBUG(0, "card_bootload is called\n");
pdata = (PULONG) bootimage;
size = sizeof(bootimage);
if (size & 0x0003) {
size += 4;
}
spin_lock_irqsave(&info->dpram_lock, flags);
ft1000_write_reg(dev, FT1000_REG_DPRAM_ADDR, FT1000_DPRAM_BASE);
for (i = 0; i < (size >> 2); i++) {
templong = *pdata++;
outl(templong, dev->base_addr + FT1000_REG_MAG_DPDATA);
}
spin_unlock_irqrestore(&info->dpram_lock, flags);
}
USHORT get_handshake(struct net_device *dev, USHORT expected_value)
{
FT1000_INFO *info = (PFT1000_INFO) netdev_priv(dev);
USHORT handshake;
ULONG tempx;
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
handshake = (USHORT) tempx;
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
void put_handshake(struct net_device *dev, USHORT handshake_value)
{
FT1000_INFO *info = (PFT1000_INFO) netdev_priv(dev);
ULONG tempx;
if (info->AsicID == ELECTRABUZZ_ID) {
ft1000_write_reg(dev, FT1000_REG_DPRAM_ADDR,
DWNLD_HANDSHAKE_LOC);
ft1000_write_reg(dev, FT1000_REG_DPRAM_DATA, handshake_value);
} else {
tempx = (ULONG) handshake_value;
tempx = ntohl(tempx);
ft1000_write_dpram_mag_32(dev, DWNLD_MAG_HANDSHAKE_LOC, tempx);
}
}
USHORT get_request_type(struct net_device *dev)
{
FT1000_INFO *info = (PFT1000_INFO) netdev_priv(dev);
USHORT request_type;
ULONG tempx;
if (info->AsicID == ELECTRABUZZ_ID) {
ft1000_write_reg(dev, FT1000_REG_DPRAM_ADDR, DWNLD_TYPE_LOC);
request_type = ft1000_read_reg(dev, FT1000_REG_DPRAM_DATA);
} else {
tempx = ft1000_read_dpram_mag_32(dev, DWNLD_MAG_TYPE_LOC);
tempx = ntohl(tempx);
request_type = (USHORT) tempx;
}
return request_type;
}
long get_request_value(struct net_device *dev)
{
FT1000_INFO *info = (PFT1000_INFO) netdev_priv(dev);
long value;
USHORT w_val;
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
FT1000_INFO *info = (PFT1000_INFO) netdev_priv(dev);
USHORT size;
ULONG tempx;
if (info->AsicID == ELECTRABUZZ_ID) {
size = (USHORT) (lvalue >> 16);
ft1000_write_reg(dev, FT1000_REG_DPRAM_ADDR,
DWNLD_SIZE_MSW_LOC);
ft1000_write_reg(dev, FT1000_REG_DPRAM_DATA, size);
size = (USHORT) (lvalue);
ft1000_write_reg(dev, FT1000_REG_DPRAM_ADDR,
DWNLD_SIZE_LSW_LOC);
ft1000_write_reg(dev, FT1000_REG_DPRAM_DATA, size);
} else {
tempx = ntohl(lvalue);
ft1000_write_dpram_mag_32(dev, DWNLD_MAG_SIZE_LOC, tempx);
}
}
USHORT hdr_checksum(PPSEUDO_HDR pHdr)
{
USHORT *usPtr = (USHORT *) pHdr;
USHORT chksum;
chksum = ((((((usPtr[0] ^ usPtr[1]) ^ usPtr[2]) ^ usPtr[3]) ^
usPtr[4]) ^ usPtr[5]) ^ usPtr[6]);
return chksum;
}
int card_download(struct net_device *dev, const u8 *pFileStart, UINT FileLength)
{
FT1000_INFO *info = (PFT1000_INFO) netdev_priv(dev);
int Status = SUCCESS;
USHORT DspWordCnt = 0;
UINT uiState;
USHORT handshake;
PPSEUDO_HDR pHdr;
USHORT usHdrLength;
PDSP_FILE_HDR pFileHdr;
long word_length;
USHORT request;
USHORT temp;
PPROV_RECORD pprov_record;
PUCHAR pbuffer;
PDSP_FILE_HDR_5 pFileHdr5;
PDSP_IMAGE_INFO pDspImageInfo = NULL;
PDSP_IMAGE_INFO_V6 pDspImageInfoV6 = NULL;
long requested_version;
BOOLEAN bGoodVersion = 0;
PDRVMSG pMailBoxData;
USHORT *pUsData = NULL;
USHORT *pUsFile = NULL;
UCHAR *pUcFile = NULL;
UCHAR *pBootEnd = NULL;
UCHAR *pCodeEnd = NULL;
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
uiState = STATE_START_DWNLD;
pFileHdr = (PDSP_FILE_HDR) pFileStart;
pFileHdr5 = (PDSP_FILE_HDR_5) pFileStart;
switch (file_version) {
case 5:
case 6:
pUsFile =
(USHORT *) ((long)pFileStart + pFileHdr5->loader_offset);
pUcFile =
(UCHAR *) ((long)pFileStart + pFileHdr5->loader_offset);
pBootEnd =
(UCHAR *) ((long)pFileStart + pFileHdr5->loader_code_end);
loader_code_address = pFileHdr5->loader_code_address;
loader_code_size = pFileHdr5->loader_code_size;
bGoodVersion = FALSE;
break;
default:
Status = FAILURE;
break;
}
while ((Status == SUCCESS) && (uiState != STATE_DONE_FILE)) {
switch (uiState) {
case STATE_START_DWNLD:
handshake = get_handshake(dev, HANDSHAKE_DSP_BL_READY);
if (handshake == HANDSHAKE_DSP_BL_READY) {
put_handshake(dev, HANDSHAKE_DRIVER_READY);
} else {
Status = FAILURE;
}
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
pUsFile = (USHORT *) ((long)pBootEnd);
pUcFile = (UCHAR *) ((long)pBootEnd);
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
if (file_version == 5) {
ft1000_write_reg(dev,
FT1000_REG_DPRAM_ADDR,
DWNLD_PS_HDR_LOC);
for (; word_length > 0; word_length--) {
ft1000_write_reg(dev,
FT1000_REG_DPRAM_DATA,
*pUsFile);
pUsFile++;
pUcFile += 2;
DspWordCnt++;
}
} else {
outw(DWNLD_MAG_PS_HDR_LOC,
dev->base_addr +
FT1000_REG_DPRAM_ADDR);
if (word_length & 0x01) {
word_length++;
}
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
switch (file_version) {
case 5:
case 6:
pUsFile =
(USHORT *) ((long)pFileStart
+
pFileHdr5->
commands_offset);
pUcFile =
(UCHAR *) ((long)pFileStart
+
pFileHdr5->
commands_offset);
break;
default:
Status = FAILURE;
break;
}
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
if (file_version == 5) {
ft1000_write_reg(dev,
FT1000_REG_DPRAM_ADDR,
DWNLD_PS_HDR_LOC);
for (; word_length > 0; word_length--) {
ft1000_write_reg(dev,
FT1000_REG_DPRAM_DATA,
*pUsFile);
pUsFile++;
pUcFile += 2;
DspWordCnt++;
}
} else {
outw(DWNLD_MAG_PS_HDR_LOC,
dev->base_addr +
FT1000_REG_DPRAM_ADDR);
if (word_length & 0x01) {
word_length++;
}
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
}
break;
case REQUEST_MAILBOX_DATA:
word_length =
(long)(info->DSPInfoBlklen + 1) / 2;
put_request_value(dev, word_length);
pMailBoxData =
(PDRVMSG) & info->DSPInfoBlk[0];
pUsData =
(USHORT *) & pMailBoxData->data[0];
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
if (word_length & 0x01) {
word_length++;
}
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
(USHORT *) ((long)pFileStart +
pFileHdr5->
version_data_offset);
spin_lock_irqsave(&info->dpram_lock,
flags);
if (file_version == 5) {
ft1000_write_reg(dev,
FT1000_REG_DPRAM_ADDR,
DWNLD_PS_HDR_LOC);
for (; word_length > 0; word_length--) {
ft1000_write_reg(dev,
FT1000_REG_DPRAM_DATA,
*pUsFile
);
pUsFile++;
}
} else {
outw(DWNLD_MAG_PS_HDR_LOC,
dev->base_addr +
FT1000_REG_DPRAM_ADDR);
if (word_length & 0x01) {
word_length++;
}
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
}
spin_unlock_irqrestore(&info->
dpram_lock,
flags);
break;
case REQUEST_CODE_BY_VERSION:
bGoodVersion = FALSE;
requested_version =
get_request_value(dev);
if (file_version == 5) {
pDspImageInfo =
(PDSP_IMAGE_INFO) ((long)
pFileStart
+
sizeof
(DSP_FILE_HDR_5));
for (imageN = 0;
imageN <
pFileHdr5->nDspImages;
imageN++) {
if (pDspImageInfo->
version ==
requested_version) {
bGoodVersion =
TRUE;
pUsFile =
(USHORT
*) ((long)
pFileStart
+
pDspImageInfo->
begin_offset);
pUcFile =
(UCHAR
*) ((long)
pFileStart
+
pDspImageInfo->
begin_offset);
pCodeEnd =
(UCHAR
*) ((long)
pFileStart
+
pDspImageInfo->
end_offset);
run_address =
pDspImageInfo->
run_address;
run_size =
pDspImageInfo->
image_size;
break;
}
pDspImageInfo++;
}
} else {
pDspImageInfoV6 =
(PDSP_IMAGE_INFO_V6) ((long)
pFileStart
+
sizeof
(DSP_FILE_HDR_5));
for (imageN = 0;
imageN <
pFileHdr5->nDspImages;
imageN++) {
temp = (USHORT)
(pDspImageInfoV6->
version);
templong = temp;
temp = (USHORT)
(pDspImageInfoV6->
version >> 16);
templong |=
(temp << 16);
if (templong ==
requested_version) {
bGoodVersion =
TRUE;
pUsFile =
(USHORT
*) ((long)
pFileStart
+
pDspImageInfoV6->
begin_offset);
pUcFile =
(UCHAR
*) ((long)
pFileStart
+
pDspImageInfoV6->
begin_offset);
pCodeEnd =
(UCHAR
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
(ULONG)
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
pHdr = (PPSEUDO_HDR) pUsFile;
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
pHdr = (PPSEUDO_HDR) pUcFile;
if (pHdr->checksum == hdr_checksum(pHdr)) {
if (pHdr->portdest != 0x80 ) {
uiState = STATE_DONE_PROV;
break;
}
usHdrLength = ntohs(pHdr->length);
pbuffer =
kmalloc((usHdrLength + sizeof(PSEUDO_HDR)),
GFP_ATOMIC);
if (pbuffer) {
memcpy(pbuffer, (void *)pUcFile,
(UINT) (usHdrLength +
sizeof(PSEUDO_HDR)));
pprov_record =
kmalloc(sizeof(PROV_RECORD),
GFP_ATOMIC);
if (pprov_record) {
pprov_record->pprov_data =
pbuffer;
list_add_tail(&pprov_record->
list,
&info->prov_list);
pUcFile =
(UCHAR *) ((unsigned long) pUcFile +
(unsigned long) ((usHdrLength + 1) & 0xFFFFFFFE) + sizeof(PSEUDO_HDR));
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
