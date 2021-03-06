static u32 check_usb_db (struct ft1000_usb *ft1000dev)
{
int loopcnt;
u16 temp;
u32 status;
loopcnt = 0;
while (loopcnt < 10) {
status = ft1000_read_register(ft1000dev, &temp,
FT1000_REG_DOORBELL);
DEBUG("check_usb_db: read FT1000_REG_DOORBELL value is %x\n",
temp);
if (temp & 0x0080) {
DEBUG("FT1000:Got checkusb doorbell\n");
status = ft1000_write_register(ft1000dev, 0x0080,
FT1000_REG_DOORBELL);
status = ft1000_write_register(ft1000dev, 0x0100,
FT1000_REG_DOORBELL);
status = ft1000_write_register(ft1000dev, 0x8000,
FT1000_REG_DOORBELL);
break;
} else {
loopcnt++;
msleep(10);
}
}
loopcnt = 0;
while (loopcnt < 20) {
status = ft1000_read_register(ft1000dev, &temp,
FT1000_REG_DOORBELL);
DEBUG("FT1000:check_usb_db:Doorbell = 0x%x\n", temp);
if (temp & 0x8000) {
loopcnt++;
msleep(10);
} else {
DEBUG("check_usb_db: door bell is cleared, return 0\n");
return 0;
}
}
return HANDSHAKE_MAG_TIMEOUT_VALUE;
}
static u16 get_handshake(struct ft1000_usb *ft1000dev, u16 expected_value)
{
u16 handshake;
int loopcnt;
u32 status = 0;
loopcnt = 0;
while (loopcnt < 100) {
status = ft1000_write_register(ft1000dev, FT1000_DB_DNLD_RX,
FT1000_REG_DOORBELL);
if (ft1000dev->fcodeldr) {
DEBUG(" get_handshake: fcodeldr is %d\n",
ft1000dev->fcodeldr);
ft1000dev->fcodeldr = 0;
status = check_usb_db(ft1000dev);
if (status != STATUS_SUCCESS) {
DEBUG("get_handshake: check_usb_db failed\n");
status = STATUS_FAILURE;
break;
}
status = ft1000_write_register(ft1000dev,
FT1000_DB_DNLD_RX,
FT1000_REG_DOORBELL);
}
status = ft1000_read_dpram16(ft1000dev,
DWNLD_MAG1_HANDSHAKE_LOC, (u8 *)&handshake, 1);
handshake = ntohs(handshake);
if (status)
return HANDSHAKE_TIMEOUT_VALUE;
if ((handshake == expected_value) ||
(handshake == HANDSHAKE_RESET_VALUE_USB)) {
return handshake;
} else {
loopcnt++;
msleep(10);
}
}
return HANDSHAKE_TIMEOUT_VALUE;
}
static void put_handshake(struct ft1000_usb *ft1000dev,u16 handshake_value)
{
u32 tempx;
u16 tempword;
u32 status;
tempx = (u32)handshake_value;
tempx = ntohl(tempx);
tempword = (u16)(tempx & 0xffff);
status = ft1000_write_dpram16(ft1000dev, DWNLD_MAG1_HANDSHAKE_LOC,
tempword, 0);
tempword = (u16)(tempx >> 16);
status = ft1000_write_dpram16(ft1000dev, DWNLD_MAG1_HANDSHAKE_LOC,
tempword, 1);
status = ft1000_write_register(ft1000dev, FT1000_DB_DNLD_TX,
FT1000_REG_DOORBELL);
}
static u16 get_handshake_usb(struct ft1000_usb *ft1000dev, u16 expected_value)
{
u16 handshake;
int loopcnt;
u16 temp;
u32 status = 0;
loopcnt = 0;
handshake = 0;
while (loopcnt < 100) {
if (ft1000dev->usbboot == 2) {
status = ft1000_read_dpram32(ft1000dev, 0,
(u8 *)&(ft1000dev->tempbuf[0]), 64);
for (temp = 0; temp < 16; temp++) {
DEBUG("tempbuf %d = 0x%x\n", temp,
ft1000dev->tempbuf[temp]);
}
status = ft1000_read_dpram16(ft1000dev,
DWNLD_MAG1_HANDSHAKE_LOC,
(u8 *)&handshake, 1);
DEBUG("handshake from read_dpram16 = 0x%x\n",
handshake);
if (ft1000dev->dspalive == ft1000dev->tempbuf[6]) {
handshake = 0;
} else {
handshake = ft1000dev->tempbuf[1];
ft1000dev->dspalive =
ft1000dev->tempbuf[6];
}
} else {
status = ft1000_read_dpram16(ft1000dev,
DWNLD_MAG1_HANDSHAKE_LOC,
(u8 *)&handshake, 1);
}
loopcnt++;
msleep(10);
handshake = ntohs(handshake);
if ((handshake == expected_value) ||
(handshake == HANDSHAKE_RESET_VALUE_USB))
return handshake;
}
return HANDSHAKE_TIMEOUT_VALUE;
}
static void put_handshake_usb(struct ft1000_usb *ft1000dev,u16 handshake_value)
{
int i;
for (i=0; i<1000; i++);
}
static u16 get_request_type(struct ft1000_usb *ft1000dev)
{
u16 request_type;
u32 status;
u16 tempword;
u32 tempx;
if (ft1000dev->bootmode == 1) {
status = fix_ft1000_read_dpram32(ft1000dev,
DWNLD_MAG1_TYPE_LOC, (u8 *)&tempx);
tempx = ntohl(tempx);
} else {
tempx = 0;
status = ft1000_read_dpram16(ft1000dev,
DWNLD_MAG1_TYPE_LOC, (u8 *)&tempword, 1);
tempx |= (tempword << 16);
tempx = ntohl(tempx);
}
request_type = (u16)tempx;
return request_type;
}
static u16 get_request_type_usb(struct ft1000_usb *ft1000dev)
{
u16 request_type;
u32 status;
u16 tempword;
u32 tempx;
if (ft1000dev->bootmode == 1) {
status = fix_ft1000_read_dpram32(ft1000dev,
DWNLD_MAG1_TYPE_LOC, (u8 *)&tempx);
tempx = ntohl(tempx);
} else {
if (ft1000dev->usbboot == 2) {
tempx = ft1000dev->tempbuf[2];
tempword = ft1000dev->tempbuf[3];
} else {
tempx = 0;
status = ft1000_read_dpram16(ft1000dev,
DWNLD_MAG1_TYPE_LOC,
(u8 *)&tempword, 1);
}
tempx |= (tempword << 16);
tempx = ntohl(tempx);
}
request_type = (u16)tempx;
return request_type;
}
static long get_request_value(struct ft1000_usb *ft1000dev)
{
u32 value;
u16 tempword;
u32 status;
if (ft1000dev->bootmode == 1) {
status = fix_ft1000_read_dpram32(ft1000dev,
DWNLD_MAG1_SIZE_LOC, (u8 *)&value);
value = ntohl(value);
} else {
status = ft1000_read_dpram16(ft1000dev,
DWNLD_MAG1_SIZE_LOC, (u8 *)&tempword, 0);
value = tempword;
status = ft1000_read_dpram16(ft1000dev,
DWNLD_MAG1_SIZE_LOC, (u8 *)&tempword, 1);
value |= (tempword << 16);
value = ntohl(value);
}
return value;
}
static void put_request_value(struct ft1000_usb *ft1000dev, long lvalue)
{
u32 tempx;
u32 status;
tempx = ntohl(lvalue);
status = fix_ft1000_write_dpram32(ft1000dev, DWNLD_MAG1_SIZE_LOC,
(u8 *)&tempx);
}
static u16 hdr_checksum(struct pseudo_hdr *pHdr)
{
u16 *usPtr = (u16 *)pHdr;
u16 chksum;
chksum = ((((((usPtr[0] ^ usPtr[1]) ^ usPtr[2]) ^ usPtr[3]) ^
usPtr[4]) ^ usPtr[5]) ^ usPtr[6]);
return chksum;
}
static int check_buffers(u16 *buff_w, u16 *buff_r, int len, int offset)
{
int i;
for (i = 0; i < len; i++) {
if (buff_w[i] != buff_r[i + offset])
return -1;
}
return 0;
}
static u32 write_blk (struct ft1000_usb *ft1000dev, u16 **pUsFile, u8 **pUcFile, long word_length)
{
u32 Status = STATUS_SUCCESS;
u16 dpram;
int loopcnt, i, j;
u16 tempword;
u16 tempbuffer[64];
u16 resultbuffer[64];
dpram = (u16)DWNLD_MAG1_PS_HDR_LOC;
tempword = *(*pUsFile);
(*pUsFile)++;
Status = ft1000_write_dpram16(ft1000dev, dpram, tempword, 0);
tempword = *(*pUsFile);
(*pUsFile)++;
Status = ft1000_write_dpram16(ft1000dev, dpram++, tempword, 1);
*pUcFile = *pUcFile + 4;
word_length--;
tempword = (u16)word_length;
word_length = (word_length / 16) + 1;
for (; word_length > 0; word_length--)
{
loopcnt = 0;
for (i=0; i<32; i++)
{
if (tempword != 0)
{
tempbuffer[i++] = *(*pUsFile);
(*pUsFile)++;
tempbuffer[i] = *(*pUsFile);
(*pUsFile)++;
*pUcFile = *pUcFile + 4;
loopcnt++;
tempword--;
}
else
{
tempbuffer[i++] = 0;
tempbuffer[i] = 0;
}
}
if (ft1000dev->bootmode == 0)
{
if (dpram >= 0x3F4)
Status = ft1000_write_dpram32 (ft1000dev, dpram, (u8 *)&tempbuffer[0], 8);
else
Status = ft1000_write_dpram32 (ft1000dev, dpram, (u8 *)&tempbuffer[0], 64);
}
else
{
for (j=0; j<10; j++)
{
Status = ft1000_write_dpram32 (ft1000dev, dpram, (u8 *)&tempbuffer[0], 64);
if (Status == STATUS_SUCCESS)
{
if ( (tempbuffer[31] & 0xfe00) == 0xfe00)
{
Status = ft1000_write_dpram32(ft1000dev, dpram+12, (u8 *)&tempbuffer[24], 64);
}
Status = ft1000_read_dpram32 (ft1000dev, dpram, (u8 *)&resultbuffer[0], 64);
if ( (tempbuffer[31] & 0xfe00) == 0xfe00)
{
if (check_buffers(tempbuffer, resultbuffer, 28, 0)) {
DEBUG("FT1000:download:DPRAM write failed 1 during bootloading\n");
msleep(10);
Status = STATUS_FAILURE;
break;
}
Status = ft1000_read_dpram32 (ft1000dev, dpram+12, (u8 *)&resultbuffer[0], 64);
if (check_buffers(tempbuffer, resultbuffer, 16, 24)) {
DEBUG("FT1000:download:DPRAM write failed 2 during bootloading\n");
msleep(10);
Status = STATUS_FAILURE;
break;
}
}
else
{
if (check_buffers(tempbuffer, resultbuffer, 32, 0)) {
DEBUG("FT1000:download:DPRAM write failed 3 during bootloading\n");
msleep(10);
Status = STATUS_FAILURE;
break;
}
}
if (Status == STATUS_SUCCESS)
break;
}
}
if (Status != STATUS_SUCCESS)
{
DEBUG("FT1000:download:Write failed tempbuffer[31] = 0x%x\n", tempbuffer[31]);
break;
}
}
dpram = dpram + loopcnt;
}
return Status;
}
static void usb_dnld_complete (struct urb *urb)
{
}
static u32 write_blk_fifo(struct ft1000_usb *ft1000dev, u16 **pUsFile,
u8 **pUcFile, long word_length)
{
u32 Status = STATUS_SUCCESS;
int byte_length;
byte_length = word_length * 4;
if (byte_length && ((byte_length % 64) == 0))
byte_length += 4;
if (byte_length < 64)
byte_length = 68;
usb_init_urb(ft1000dev->tx_urb);
memcpy(ft1000dev->tx_buf, *pUcFile, byte_length);
usb_fill_bulk_urb(ft1000dev->tx_urb,
ft1000dev->dev,
usb_sndbulkpipe(ft1000dev->dev,
ft1000dev->bulk_out_endpointAddr),
ft1000dev->tx_buf, byte_length, usb_dnld_complete,
(void *)ft1000dev);
usb_submit_urb(ft1000dev->tx_urb, GFP_ATOMIC);
*pUsFile = *pUsFile + (word_length << 1);
*pUcFile = *pUcFile + (word_length << 2);
return Status;
}
u16 scram_dnldr(struct ft1000_usb *ft1000dev, void *pFileStart,
u32 FileLength)
{
u16 status = STATUS_SUCCESS;
u32 state;
u16 handshake;
struct pseudo_hdr *pseudo_header;
u16 pseudo_header_len;
long word_length;
u16 request;
u16 temp;
u16 tempword;
struct dsp_file_hdr *file_hdr;
struct dsp_image_info *dsp_img_info = NULL;
long requested_version;
bool correct_version;
struct drv_msg *mailbox_data;
u16 *data = NULL;
u16 *s_file = NULL;
u8 *c_file = NULL;
u8 *boot_end = NULL, *code_end = NULL;
int image;
long loader_code_address, loader_code_size = 0;
long run_address = 0, run_size = 0;
u32 templong;
u32 image_chksum = 0;
u16 dpram = 0;
u8 *pbuffer;
struct prov_record *pprov_record;
struct ft1000_info *pft1000info = netdev_priv(ft1000dev->net);
DEBUG("Entered scram_dnldr...\n");
ft1000dev->fcodeldr = 0;
ft1000dev->usbboot = 0;
ft1000dev->dspalive = 0xffff;
state = STATE_START_DWNLD;
file_hdr = (struct dsp_file_hdr *)pFileStart;
ft1000_write_register(ft1000dev, 0x800, FT1000_REG_MAG_WATERMARK);
s_file = (u16 *) (pFileStart + file_hdr->loader_offset);
c_file = (u8 *) (pFileStart + file_hdr->loader_offset);
boot_end = (u8 *) (pFileStart + file_hdr->loader_code_end);
loader_code_address = file_hdr->loader_code_address;
loader_code_size = file_hdr->loader_code_size;
correct_version = FALSE;
while ((status == STATUS_SUCCESS) && (state != STATE_DONE_FILE)) {
switch (state) {
case STATE_START_DWNLD:
DEBUG("FT1000:STATE_START_DWNLD\n");
if (ft1000dev->usbboot)
handshake =
get_handshake_usb(ft1000dev,
HANDSHAKE_DSP_BL_READY);
else
handshake =
get_handshake(ft1000dev,
HANDSHAKE_DSP_BL_READY);
if (handshake == HANDSHAKE_DSP_BL_READY) {
DEBUG
("scram_dnldr: handshake is HANDSHAKE_DSP_BL_READY, call put_handshake(HANDSHAKE_DRIVER_READY)\n");
put_handshake(ft1000dev,
HANDSHAKE_DRIVER_READY);
} else {
DEBUG
("FT1000:download:Download error: Handshake failed\n");
status = STATUS_FAILURE;
}
state = STATE_BOOT_DWNLD;
break;
case STATE_BOOT_DWNLD:
DEBUG("FT1000:STATE_BOOT_DWNLD\n");
ft1000dev->bootmode = 1;
handshake = get_handshake(ft1000dev, HANDSHAKE_REQUEST);
if (handshake == HANDSHAKE_REQUEST) {
request = get_request_type(ft1000dev);
switch (request) {
case REQUEST_RUN_ADDRESS:
DEBUG("FT1000:REQUEST_RUN_ADDRESS\n");
put_request_value(ft1000dev,
loader_code_address);
break;
case REQUEST_CODE_LENGTH:
DEBUG("FT1000:REQUEST_CODE_LENGTH\n");
put_request_value(ft1000dev,
loader_code_size);
break;
case REQUEST_DONE_BL:
DEBUG("FT1000:REQUEST_DONE_BL\n");
s_file = (u16 *) (boot_end);
c_file = (u8 *) (boot_end);
state = STATE_CODE_DWNLD;
ft1000dev->fcodeldr = 1;
break;
case REQUEST_CODE_SEGMENT:
word_length =
get_request_value(ft1000dev);
if (word_length > MAX_LENGTH) {
DEBUG
("FT1000:download:Download error: Max length exceeded\n");
status = STATUS_FAILURE;
break;
}
if ((word_length * 2 + c_file) >
boot_end) {
DEBUG
("FT1000:download:Download error: Requested len=%d exceeds BOOT code boundary.\n",
(int)word_length);
status = STATUS_FAILURE;
break;
}
dpram = (u16) DWNLD_MAG1_PS_HDR_LOC;
if (word_length & 0x1)
word_length++;
word_length = word_length / 2;
status =
write_blk(ft1000dev, &s_file,
&c_file, word_length);
break;
default:
DEBUG
("FT1000:download:Download error: Bad request type=%d in BOOT download state.\n",
request);
status = STATUS_FAILURE;
break;
}
if (ft1000dev->usbboot)
put_handshake_usb(ft1000dev,
HANDSHAKE_RESPONSE);
else
put_handshake(ft1000dev,
HANDSHAKE_RESPONSE);
} else {
DEBUG
("FT1000:download:Download error: Handshake failed\n");
status = STATUS_FAILURE;
}
break;
case STATE_CODE_DWNLD:
ft1000dev->bootmode = 0;
if (ft1000dev->usbboot)
handshake =
get_handshake_usb(ft1000dev,
HANDSHAKE_REQUEST);
else
handshake =
get_handshake(ft1000dev, HANDSHAKE_REQUEST);
if (handshake == HANDSHAKE_REQUEST) {
if (ft1000dev->usbboot)
request =
get_request_type_usb(ft1000dev);
else
request = get_request_type(ft1000dev);
switch (request) {
case REQUEST_FILE_CHECKSUM:
DEBUG
("FT1000:download:image_chksum = 0x%8x\n",
image_chksum);
put_request_value(ft1000dev,
image_chksum);
break;
case REQUEST_RUN_ADDRESS:
DEBUG
("FT1000:download: REQUEST_RUN_ADDRESS\n");
if (correct_version) {
DEBUG
("FT1000:download:run_address = 0x%8x\n",
(int)run_address);
put_request_value(ft1000dev,
run_address);
} else {
DEBUG
("FT1000:download:Download error: Got Run address request before image offset request.\n");
status = STATUS_FAILURE;
break;
}
break;
case REQUEST_CODE_LENGTH:
DEBUG
("FT1000:download:REQUEST_CODE_LENGTH\n");
if (correct_version) {
DEBUG
("FT1000:download:run_size = 0x%8x\n",
(int)run_size);
put_request_value(ft1000dev,
run_size);
} else {
DEBUG
("FT1000:download:Download error: Got Size request before image offset request.\n");
status = STATUS_FAILURE;
break;
}
break;
case REQUEST_DONE_CL:
ft1000dev->usbboot = 3;
s_file =
(u16 *) (pFileStart +
file_hdr->commands_offset);
c_file =
(u8 *) (pFileStart +
file_hdr->commands_offset);
state = STATE_DONE_DWNLD;
break;
case REQUEST_CODE_SEGMENT:
if (!correct_version) {
DEBUG
("FT1000:download:Download error: Got Code Segment request before image offset request.\n");
status = STATUS_FAILURE;
break;
}
word_length =
get_request_value(ft1000dev);
if (word_length > MAX_LENGTH) {
DEBUG
("FT1000:download:Download error: Max length exceeded\n");
status = STATUS_FAILURE;
break;
}
if ((word_length * 2 + c_file) >
code_end) {
DEBUG
("FT1000:download:Download error: Requested len=%d exceeds DSP code boundary.\n",
(int)word_length);
status = STATUS_FAILURE;
break;
}
dpram = (u16) DWNLD_MAG1_PS_HDR_LOC;
if (word_length & 0x1)
word_length++;
word_length = word_length / 2;
write_blk_fifo(ft1000dev, &s_file,
&c_file, word_length);
if (ft1000dev->usbboot == 0)
ft1000dev->usbboot++;
if (ft1000dev->usbboot == 1) {
tempword = 0;
ft1000_write_dpram16(ft1000dev,
DWNLD_MAG1_PS_HDR_LOC,
tempword,
0);
}
break;
case REQUEST_MAILBOX_DATA:
DEBUG
("FT1000:download: REQUEST_MAILBOX_DATA\n");
word_length =
(long)(pft1000info->DSPInfoBlklen +
1) / 2;
put_request_value(ft1000dev,
word_length);
mailbox_data =
(struct drv_msg *)&(pft1000info->
DSPInfoBlk[0]);
data = (u16 *) & mailbox_data->data[0];
dpram = (u16) DWNLD_MAG1_PS_HDR_LOC;
if (word_length & 0x1)
word_length++;
word_length = (word_length / 2);
for (; word_length > 0; word_length--) {
templong = *data++;
templong |= (*data++ << 16);
status =
fix_ft1000_write_dpram32
(ft1000dev, dpram++,
(u8 *) & templong);
}
break;
case REQUEST_VERSION_INFO:
DEBUG
("FT1000:download:REQUEST_VERSION_INFO\n");
word_length =
file_hdr->version_data_size;
put_request_value(ft1000dev,
word_length);
s_file =
(u16 *) (pFileStart +
file_hdr->
version_data_offset);
dpram = (u16) DWNLD_MAG1_PS_HDR_LOC;
if (word_length & 0x1)
word_length++;
word_length = (word_length / 2);
for (; word_length > 0; word_length--) {
templong = ntohs(*s_file++);
temp = ntohs(*s_file++);
templong |= (temp << 16);
status =
fix_ft1000_write_dpram32
(ft1000dev, dpram++,
(u8 *) & templong);
}
break;
case REQUEST_CODE_BY_VERSION:
DEBUG
("FT1000:download:REQUEST_CODE_BY_VERSION\n");
correct_version = FALSE;
requested_version =
get_request_value(ft1000dev);
dsp_img_info =
(struct dsp_image_info *)(pFileStart
+
sizeof
(struct
dsp_file_hdr));
for (image = 0;
image < file_hdr->nDspImages;
image++) {
if (dsp_img_info->version ==
requested_version) {
correct_version = TRUE;
DEBUG
("FT1000:download: correct_version is TRUE\n");
s_file =
(u16 *) (pFileStart
+
dsp_img_info->
begin_offset);
c_file =
(u8 *) (pFileStart +
dsp_img_info->
begin_offset);
code_end =
(u8 *) (pFileStart +
dsp_img_info->
end_offset);
run_address =
dsp_img_info->
run_address;
run_size =
dsp_img_info->
image_size;
image_chksum =
(u32) dsp_img_info->
checksum;
break;
}
dsp_img_info++;
}
if (!correct_version) {
DEBUG
("FT1000:download:Download error: Bad Version Request = 0x%x.\n",
(int)requested_version);
status = STATUS_FAILURE;
break;
}
break;
default:
DEBUG
("FT1000:download:Download error: Bad request type=%d in CODE download state.\n",
request);
status = STATUS_FAILURE;
break;
}
if (ft1000dev->usbboot)
put_handshake_usb(ft1000dev,
HANDSHAKE_RESPONSE);
else
put_handshake(ft1000dev,
HANDSHAKE_RESPONSE);
} else {
DEBUG
("FT1000:download:Download error: Handshake failed\n");
status = STATUS_FAILURE;
}
break;
case STATE_DONE_DWNLD:
DEBUG("FT1000:download:Code loader is done...\n");
state = STATE_SECTION_PROV;
break;
case STATE_SECTION_PROV:
DEBUG("FT1000:download:STATE_SECTION_PROV\n");
pseudo_header = (struct pseudo_hdr *)c_file;
if (pseudo_header->checksum ==
hdr_checksum(pseudo_header)) {
if (pseudo_header->portdest !=
0x80 ) {
state = STATE_DONE_PROV;
break;
}
pseudo_header_len = ntohs(pseudo_header->length);
pbuffer =
kmalloc((pseudo_header_len +
sizeof(struct pseudo_hdr)),
GFP_ATOMIC);
if (pbuffer) {
memcpy(pbuffer, (void *)c_file,
(u32) (pseudo_header_len +
sizeof(struct
pseudo_hdr)));
pprov_record =
kmalloc(sizeof(struct prov_record),
GFP_ATOMIC);
if (pprov_record) {
pprov_record->pprov_data =
pbuffer;
list_add_tail(&pprov_record->
list,
&pft1000info->
prov_list);
c_file =
(u8 *) ((unsigned long)
c_file +
(u32) ((pseudo_header_len + 1) & 0xFFFFFFFE) + sizeof(struct pseudo_hdr));
if ((unsigned long)(c_file) -
(unsigned long)(pFileStart)
>=
(unsigned long)FileLength) {
state = STATE_DONE_FILE;
}
} else {
kfree(pbuffer);
status = STATUS_FAILURE;
}
} else {
status = STATUS_FAILURE;
}
} else {
status = STATUS_FAILURE;
}
DEBUG
("ft1000:download: after STATE_SECTION_PROV, state = %d, status= %d\n",
state, status);
break;
case STATE_DONE_PROV:
DEBUG("FT1000:download:STATE_DONE_PROV\n");
state = STATE_DONE_FILE;
break;
default:
status = STATUS_FAILURE;
break;
}
if (status != STATUS_SUCCESS) {
break;
}
}
DEBUG("Download exiting with status = 0x%8x\n", status);
ft1000_write_register(ft1000dev, FT1000_DB_DNLD_TX,
FT1000_REG_DOORBELL);
return status;
}
