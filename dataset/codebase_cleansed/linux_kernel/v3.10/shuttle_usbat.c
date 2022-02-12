static void usbat_pack_ata_sector_cmd(unsigned char *buf,
unsigned char thistime,
u32 sector, unsigned char cmd)
{
buf[0] = 0;
buf[1] = thistime;
buf[2] = sector & 0xFF;
buf[3] = (sector >> 8) & 0xFF;
buf[4] = (sector >> 16) & 0xFF;
buf[5] = 0xE0 | ((sector >> 24) & 0x0F);
buf[6] = cmd;
}
static int usbat_get_device_type(struct us_data *us)
{
return ((struct usbat_info*)us->extra)->devicetype;
}
static int usbat_read(struct us_data *us,
unsigned char access,
unsigned char reg,
unsigned char *content)
{
return usb_stor_ctrl_transfer(us,
us->recv_ctrl_pipe,
access | USBAT_CMD_READ_REG,
0xC0,
(u16)reg,
0,
content,
1);
}
static int usbat_write(struct us_data *us,
unsigned char access,
unsigned char reg,
unsigned char content)
{
return usb_stor_ctrl_transfer(us,
us->send_ctrl_pipe,
access | USBAT_CMD_WRITE_REG,
0x40,
short_pack(reg, content),
0,
NULL,
0);
}
static int usbat_bulk_read(struct us_data *us,
void* buf,
unsigned int len,
int use_sg)
{
if (len == 0)
return USB_STOR_XFER_GOOD;
usb_stor_dbg(us, "len = %d\n", len);
return usb_stor_bulk_transfer_sg(us, us->recv_bulk_pipe, buf, len, use_sg, NULL);
}
static int usbat_bulk_write(struct us_data *us,
void* buf,
unsigned int len,
int use_sg)
{
if (len == 0)
return USB_STOR_XFER_GOOD;
usb_stor_dbg(us, "len = %d\n", len);
return usb_stor_bulk_transfer_sg(us, us->send_bulk_pipe, buf, len, use_sg, NULL);
}
static int usbat_execute_command(struct us_data *us,
unsigned char *commands,
unsigned int len)
{
return usb_stor_ctrl_transfer(us, us->send_ctrl_pipe,
USBAT_CMD_EXEC_CMD, 0x40, 0, 0,
commands, len);
}
static int usbat_get_status(struct us_data *us, unsigned char *status)
{
int rc;
rc = usbat_read(us, USBAT_ATA, USBAT_ATA_STATUS, status);
usb_stor_dbg(us, "0x%02X\n", *status);
return rc;
}
static int usbat_check_status(struct us_data *us)
{
unsigned char *reply = us->iobuf;
int rc;
rc = usbat_get_status(us, reply);
if (rc != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_FAILED;
if (*reply & 0x01 && *reply != 0x51)
return USB_STOR_TRANSPORT_FAILED;
if (*reply & 0x20)
return USB_STOR_TRANSPORT_FAILED;
return USB_STOR_TRANSPORT_GOOD;
}
static int usbat_set_shuttle_features(struct us_data *us,
unsigned char external_trigger,
unsigned char epp_control,
unsigned char mask_byte,
unsigned char test_pattern,
unsigned char subcountH,
unsigned char subcountL)
{
unsigned char *command = us->iobuf;
command[0] = 0x40;
command[1] = USBAT_CMD_SET_FEAT;
command[2] = epp_control;
command[3] = external_trigger;
command[4] = test_pattern;
command[5] = mask_byte;
command[6] = subcountL;
command[7] = subcountH;
return usbat_execute_command(us, command, 8);
}
static int usbat_wait_not_busy(struct us_data *us, int minutes)
{
int i;
int result;
unsigned char *status = us->iobuf;
for (i=0; i<1200+minutes*60; i++) {
result = usbat_get_status(us, status);
if (result!=USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
if (*status & 0x01) {
result = usbat_read(us, USBAT_ATA, 0x10, status);
return USB_STOR_TRANSPORT_FAILED;
}
if (*status & 0x20)
return USB_STOR_TRANSPORT_FAILED;
if ((*status & 0x80)==0x00) {
usb_stor_dbg(us, "Waited not busy for %d steps\n", i);
return USB_STOR_TRANSPORT_GOOD;
}
if (i<500)
msleep(10);
else if (i<700)
msleep(50);
else if (i<1200)
msleep(100);
else
msleep(1000);
}
usb_stor_dbg(us, "Waited not busy for %d minutes, timing out\n",
minutes);
return USB_STOR_TRANSPORT_FAILED;
}
static int usbat_read_block(struct us_data *us,
void* buf,
unsigned short len,
int use_sg)
{
int result;
unsigned char *command = us->iobuf;
if (!len)
return USB_STOR_TRANSPORT_GOOD;
command[0] = 0xC0;
command[1] = USBAT_ATA | USBAT_CMD_READ_BLOCK;
command[2] = USBAT_ATA_DATA;
command[3] = 0;
command[4] = 0;
command[5] = 0;
command[6] = LSB_of(len);
command[7] = MSB_of(len);
result = usbat_execute_command(us, command, 8);
if (result != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
result = usbat_bulk_read(us, buf, len, use_sg);
return (result == USB_STOR_XFER_GOOD ?
USB_STOR_TRANSPORT_GOOD : USB_STOR_TRANSPORT_ERROR);
}
static int usbat_write_block(struct us_data *us,
unsigned char access,
void* buf,
unsigned short len,
int minutes,
int use_sg)
{
int result;
unsigned char *command = us->iobuf;
if (!len)
return USB_STOR_TRANSPORT_GOOD;
command[0] = 0x40;
command[1] = access | USBAT_CMD_WRITE_BLOCK;
command[2] = USBAT_ATA_DATA;
command[3] = 0;
command[4] = 0;
command[5] = 0;
command[6] = LSB_of(len);
command[7] = MSB_of(len);
result = usbat_execute_command(us, command, 8);
if (result != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
result = usbat_bulk_write(us, buf, len, use_sg);
if (result != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
return usbat_wait_not_busy(us, minutes);
}
static int usbat_hp8200e_rw_block_test(struct us_data *us,
unsigned char access,
unsigned char *registers,
unsigned char *data_out,
unsigned short num_registers,
unsigned char data_reg,
unsigned char status_reg,
unsigned char timeout,
unsigned char qualifier,
int direction,
void *buf,
unsigned short len,
int use_sg,
int minutes)
{
int result;
unsigned int pipe = (direction == DMA_FROM_DEVICE) ?
us->recv_bulk_pipe : us->send_bulk_pipe;
unsigned char *command = us->iobuf;
int i, j;
int cmdlen;
unsigned char *data = us->iobuf;
unsigned char *status = us->iobuf;
BUG_ON(num_registers > US_IOBUF_SIZE/2);
for (i=0; i<20; i++) {
if (i==0) {
cmdlen = 16;
command[0] = 0x40;
command[1] = access | USBAT_CMD_WRITE_REGS;
command[2] = 0x07;
command[3] = 0x17;
command[4] = 0xFC;
command[5] = 0xE7;
command[6] = LSB_of(num_registers*2);
command[7] = MSB_of(num_registers*2);
} else
cmdlen = 8;
command[cmdlen-8] = (direction==DMA_TO_DEVICE ? 0x40 : 0xC0);
command[cmdlen-7] = access |
(direction==DMA_TO_DEVICE ?
USBAT_CMD_COND_WRITE_BLOCK : USBAT_CMD_COND_READ_BLOCK);
command[cmdlen-6] = data_reg;
command[cmdlen-5] = status_reg;
command[cmdlen-4] = timeout;
command[cmdlen-3] = qualifier;
command[cmdlen-2] = LSB_of(len);
command[cmdlen-1] = MSB_of(len);
result = usbat_execute_command(us, command, cmdlen);
if (result != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
if (i==0) {
for (j=0; j<num_registers; j++) {
data[j<<1] = registers[j];
data[1+(j<<1)] = data_out[j];
}
result = usbat_bulk_write(us, data, num_registers*2, 0);
if (result != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
}
result = usb_stor_bulk_transfer_sg(us,
pipe, buf, len, use_sg, NULL);
if (result == USB_STOR_XFER_SHORT ||
result == USB_STOR_XFER_STALLED) {
if (direction==DMA_FROM_DEVICE && i==0) {
if (usb_stor_clear_halt(us,
us->send_bulk_pipe) < 0)
return USB_STOR_TRANSPORT_ERROR;
}
result = usbat_read(us, USBAT_ATA,
direction==DMA_TO_DEVICE ?
USBAT_ATA_STATUS : USBAT_ATA_ALTSTATUS,
status);
if (result!=USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
if (*status & 0x01)
return USB_STOR_TRANSPORT_FAILED;
if (*status & 0x20)
return USB_STOR_TRANSPORT_FAILED;
usb_stor_dbg(us, "Redoing %s\n",
direction == DMA_TO_DEVICE
? "write" : "read");
} else if (result != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
else
return usbat_wait_not_busy(us, minutes);
}
usb_stor_dbg(us, "Bummer! %s bulk data 20 times failed\n",
direction == DMA_TO_DEVICE ? "Writing" : "Reading");
return USB_STOR_TRANSPORT_FAILED;
}
static int usbat_multiple_write(struct us_data *us,
unsigned char *registers,
unsigned char *data_out,
unsigned short num_registers)
{
int i, result;
unsigned char *data = us->iobuf;
unsigned char *command = us->iobuf;
BUG_ON(num_registers > US_IOBUF_SIZE/2);
command[0] = 0x40;
command[1] = USBAT_ATA | USBAT_CMD_WRITE_REGS;
command[2] = 0;
command[3] = 0;
command[4] = 0;
command[5] = 0;
command[6] = LSB_of(num_registers*2);
command[7] = MSB_of(num_registers*2);
result = usbat_execute_command(us, command, 8);
if (result != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
for (i=0; i<num_registers; i++) {
data[i<<1] = registers[i];
data[1+(i<<1)] = data_out[i];
}
result = usbat_bulk_write(us, data, num_registers*2, 0);
if (result != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
if (usbat_get_device_type(us) == USBAT_DEV_HP8200)
return usbat_wait_not_busy(us, 0);
else
return USB_STOR_TRANSPORT_GOOD;
}
static int usbat_read_blocks(struct us_data *us,
void* buffer,
int len,
int use_sg)
{
int result;
unsigned char *command = us->iobuf;
command[0] = 0xC0;
command[1] = USBAT_ATA | USBAT_CMD_COND_READ_BLOCK;
command[2] = USBAT_ATA_DATA;
command[3] = USBAT_ATA_STATUS;
command[4] = 0xFD;
command[5] = USBAT_QUAL_FCQ;
command[6] = LSB_of(len);
command[7] = MSB_of(len);
result = usbat_execute_command(us, command, 8);
if (result != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_FAILED;
result = usbat_bulk_read(us, buffer, len, use_sg);
if (result != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_FAILED;
return USB_STOR_TRANSPORT_GOOD;
}
static int usbat_write_blocks(struct us_data *us,
void* buffer,
int len,
int use_sg)
{
int result;
unsigned char *command = us->iobuf;
command[0] = 0x40;
command[1] = USBAT_ATA | USBAT_CMD_COND_WRITE_BLOCK;
command[2] = USBAT_ATA_DATA;
command[3] = USBAT_ATA_STATUS;
command[4] = 0xFD;
command[5] = USBAT_QUAL_FCQ;
command[6] = LSB_of(len);
command[7] = MSB_of(len);
result = usbat_execute_command(us, command, 8);
if (result != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_FAILED;
result = usbat_bulk_write(us, buffer, len, use_sg);
if (result != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_FAILED;
return USB_STOR_TRANSPORT_GOOD;
}
static int usbat_read_user_io(struct us_data *us, unsigned char *data_flags)
{
int result;
result = usb_stor_ctrl_transfer(us,
us->recv_ctrl_pipe,
USBAT_CMD_UIO,
0xC0,
0,
0,
data_flags,
USBAT_UIO_READ);
usb_stor_dbg(us, "UIO register reads %02X\n", *data_flags);
return result;
}
static int usbat_write_user_io(struct us_data *us,
unsigned char enable_flags,
unsigned char data_flags)
{
return usb_stor_ctrl_transfer(us,
us->send_ctrl_pipe,
USBAT_CMD_UIO,
0x40,
short_pack(enable_flags, data_flags),
0,
NULL,
USBAT_UIO_WRITE);
}
static int usbat_device_reset(struct us_data *us)
{
int rc;
rc = usbat_write_user_io(us,
USBAT_UIO_DRVRST | USBAT_UIO_OE1 | USBAT_UIO_OE0,
USBAT_UIO_EPAD | USBAT_UIO_1);
if (rc != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
rc = usbat_write_user_io(us,
USBAT_UIO_OE1 | USBAT_UIO_OE0,
USBAT_UIO_EPAD | USBAT_UIO_1);
if (rc != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
return USB_STOR_TRANSPORT_GOOD;
}
static int usbat_device_enable_cdt(struct us_data *us)
{
int rc;
rc = usbat_write_user_io(us,
USBAT_UIO_ACKD | USBAT_UIO_OE1 | USBAT_UIO_OE0,
USBAT_UIO_EPAD | USBAT_UIO_1);
if (rc != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
return USB_STOR_TRANSPORT_GOOD;
}
static int usbat_flash_check_media_present(struct us_data *us,
unsigned char *uio)
{
if (*uio & USBAT_UIO_UI0) {
usb_stor_dbg(us, "no media detected\n");
return USBAT_FLASH_MEDIA_NONE;
}
return USBAT_FLASH_MEDIA_CF;
}
static int usbat_flash_check_media_changed(struct us_data *us,
unsigned char *uio)
{
if (*uio & USBAT_UIO_0) {
usb_stor_dbg(us, "media change detected\n");
return USBAT_FLASH_MEDIA_CHANGED;
}
return USBAT_FLASH_MEDIA_SAME;
}
static int usbat_flash_check_media(struct us_data *us,
struct usbat_info *info)
{
int rc;
unsigned char *uio = us->iobuf;
rc = usbat_read_user_io(us, uio);
if (rc != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
rc = usbat_flash_check_media_present(us, uio);
if (rc == USBAT_FLASH_MEDIA_NONE) {
info->sense_key = 0x02;
info->sense_asc = 0x3A;
info->sense_ascq = 0x00;
return USB_STOR_TRANSPORT_FAILED;
}
rc = usbat_flash_check_media_changed(us, uio);
if (rc == USBAT_FLASH_MEDIA_CHANGED) {
rc = usbat_device_reset(us);
if (rc != USB_STOR_TRANSPORT_GOOD)
return rc;
rc = usbat_device_enable_cdt(us);
if (rc != USB_STOR_TRANSPORT_GOOD)
return rc;
msleep(50);
rc = usbat_read_user_io(us, uio);
if (rc != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
info->sense_key = UNIT_ATTENTION;
info->sense_asc = 0x28;
info->sense_ascq = 0x00;
return USB_STOR_TRANSPORT_FAILED;
}
return USB_STOR_TRANSPORT_GOOD;
}
static int usbat_identify_device(struct us_data *us,
struct usbat_info *info)
{
int rc;
unsigned char status;
if (!us || !info)
return USB_STOR_TRANSPORT_ERROR;
rc = usbat_device_reset(us);
if (rc != USB_STOR_TRANSPORT_GOOD)
return rc;
msleep(500);
rc = usbat_write(us, USBAT_ATA, USBAT_ATA_CMD, 0xA1);
if (rc != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
rc = usbat_get_status(us, &status);
if (rc != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
if (status == 0xA1 || !(status & 0x01)) {
usb_stor_dbg(us, "Detected HP8200 CDRW\n");
info->devicetype = USBAT_DEV_HP8200;
} else {
usb_stor_dbg(us, "Detected Flash reader/writer\n");
info->devicetype = USBAT_DEV_FLASH;
}
return USB_STOR_TRANSPORT_GOOD;
}
static int usbat_set_transport(struct us_data *us,
struct usbat_info *info,
int devicetype)
{
if (!info->devicetype)
info->devicetype = devicetype;
if (!info->devicetype)
usbat_identify_device(us, info);
switch (info->devicetype) {
default:
return USB_STOR_TRANSPORT_ERROR;
case USBAT_DEV_HP8200:
us->transport = usbat_hp8200e_transport;
break;
case USBAT_DEV_FLASH:
us->transport = usbat_flash_transport;
break;
}
return 0;
}
static int usbat_flash_get_sector_count(struct us_data *us,
struct usbat_info *info)
{
unsigned char registers[3] = {
USBAT_ATA_SECCNT,
USBAT_ATA_DEVICE,
USBAT_ATA_CMD,
};
unsigned char command[3] = { 0x01, 0xA0, 0xEC };
unsigned char *reply;
unsigned char status;
int rc;
if (!us || !info)
return USB_STOR_TRANSPORT_ERROR;
reply = kmalloc(512, GFP_NOIO);
if (!reply)
return USB_STOR_TRANSPORT_ERROR;
rc = usbat_multiple_write(us, registers, command, 3);
if (rc != USB_STOR_XFER_GOOD) {
usb_stor_dbg(us, "Gah! identify_device failed\n");
rc = USB_STOR_TRANSPORT_ERROR;
goto leave;
}
if (usbat_get_status(us, &status) != USB_STOR_XFER_GOOD) {
rc = USB_STOR_TRANSPORT_ERROR;
goto leave;
}
msleep(100);
rc = usbat_read_block(us, reply, 512, 0);
if (rc != USB_STOR_TRANSPORT_GOOD)
goto leave;
info->sectors = ((u32)(reply[117]) << 24) |
((u32)(reply[116]) << 16) |
((u32)(reply[115]) << 8) |
((u32)(reply[114]) );
rc = USB_STOR_TRANSPORT_GOOD;
leave:
kfree(reply);
return rc;
}
static int usbat_flash_read_data(struct us_data *us,
struct usbat_info *info,
u32 sector,
u32 sectors)
{
unsigned char registers[7] = {
USBAT_ATA_FEATURES,
USBAT_ATA_SECCNT,
USBAT_ATA_SECNUM,
USBAT_ATA_LBA_ME,
USBAT_ATA_LBA_HI,
USBAT_ATA_DEVICE,
USBAT_ATA_STATUS,
};
unsigned char command[7];
unsigned char *buffer;
unsigned char thistime;
unsigned int totallen, alloclen;
int len, result;
unsigned int sg_offset = 0;
struct scatterlist *sg = NULL;
result = usbat_flash_check_media(us, info);
if (result != USB_STOR_TRANSPORT_GOOD)
return result;
if (sector > 0x0FFFFFFF)
return USB_STOR_TRANSPORT_ERROR;
totallen = sectors * info->ssize;
alloclen = min(totallen, 65536u);
buffer = kmalloc(alloclen, GFP_NOIO);
if (buffer == NULL)
return USB_STOR_TRANSPORT_ERROR;
do {
len = min(totallen, alloclen);
thistime = (len / info->ssize) & 0xff;
usbat_pack_ata_sector_cmd(command, thistime, sector, 0x20);
result = usbat_multiple_write(us, registers, command, 7);
if (result != USB_STOR_TRANSPORT_GOOD)
goto leave;
result = usbat_read_blocks(us, buffer, len, 0);
if (result != USB_STOR_TRANSPORT_GOOD)
goto leave;
usb_stor_dbg(us, "%d bytes\n", len);
usb_stor_access_xfer_buf(buffer, len, us->srb,
&sg, &sg_offset, TO_XFER_BUF);
sector += thistime;
totallen -= len;
} while (totallen > 0);
kfree(buffer);
return USB_STOR_TRANSPORT_GOOD;
leave:
kfree(buffer);
return USB_STOR_TRANSPORT_ERROR;
}
static int usbat_flash_write_data(struct us_data *us,
struct usbat_info *info,
u32 sector,
u32 sectors)
{
unsigned char registers[7] = {
USBAT_ATA_FEATURES,
USBAT_ATA_SECCNT,
USBAT_ATA_SECNUM,
USBAT_ATA_LBA_ME,
USBAT_ATA_LBA_HI,
USBAT_ATA_DEVICE,
USBAT_ATA_STATUS,
};
unsigned char command[7];
unsigned char *buffer;
unsigned char thistime;
unsigned int totallen, alloclen;
int len, result;
unsigned int sg_offset = 0;
struct scatterlist *sg = NULL;
result = usbat_flash_check_media(us, info);
if (result != USB_STOR_TRANSPORT_GOOD)
return result;
if (sector > 0x0FFFFFFF)
return USB_STOR_TRANSPORT_ERROR;
totallen = sectors * info->ssize;
alloclen = min(totallen, 65536u);
buffer = kmalloc(alloclen, GFP_NOIO);
if (buffer == NULL)
return USB_STOR_TRANSPORT_ERROR;
do {
len = min(totallen, alloclen);
thistime = (len / info->ssize) & 0xff;
usb_stor_access_xfer_buf(buffer, len, us->srb,
&sg, &sg_offset, FROM_XFER_BUF);
usbat_pack_ata_sector_cmd(command, thistime, sector, 0x30);
result = usbat_multiple_write(us, registers, command, 7);
if (result != USB_STOR_TRANSPORT_GOOD)
goto leave;
result = usbat_write_blocks(us, buffer, len, 0);
if (result != USB_STOR_TRANSPORT_GOOD)
goto leave;
sector += thistime;
totallen -= len;
} while (totallen > 0);
kfree(buffer);
return result;
leave:
kfree(buffer);
return USB_STOR_TRANSPORT_ERROR;
}
static int usbat_hp8200e_handle_read10(struct us_data *us,
unsigned char *registers,
unsigned char *data,
struct scsi_cmnd *srb)
{
int result = USB_STOR_TRANSPORT_GOOD;
unsigned char *buffer;
unsigned int len;
unsigned int sector;
unsigned int sg_offset = 0;
struct scatterlist *sg = NULL;
usb_stor_dbg(us, "transfersize %d\n", srb->transfersize);
if (scsi_bufflen(srb) < 0x10000) {
result = usbat_hp8200e_rw_block_test(us, USBAT_ATA,
registers, data, 19,
USBAT_ATA_DATA, USBAT_ATA_STATUS, 0xFD,
(USBAT_QUAL_FCQ | USBAT_QUAL_ALQ),
DMA_FROM_DEVICE,
scsi_sglist(srb),
scsi_bufflen(srb), scsi_sg_count(srb), 1);
return result;
}
if (data[7+0] == GPCMD_READ_CD) {
len = short_pack(data[7+9], data[7+8]);
len <<= 16;
len |= data[7+7];
usb_stor_dbg(us, "GPCMD_READ_CD: len %d\n", len);
srb->transfersize = scsi_bufflen(srb)/len;
}
if (!srb->transfersize) {
srb->transfersize = 2048;
usb_stor_dbg(us, "transfersize 0, forcing %d\n",
srb->transfersize);
}
len = (65535/srb->transfersize) * srb->transfersize;
usb_stor_dbg(us, "Max read is %d bytes\n", len);
len = min(len, scsi_bufflen(srb));
buffer = kmalloc(len, GFP_NOIO);
if (buffer == NULL)
return USB_STOR_TRANSPORT_FAILED;
sector = short_pack(data[7+3], data[7+2]);
sector <<= 16;
sector |= short_pack(data[7+5], data[7+4]);
transferred = 0;
while (transferred != scsi_bufflen(srb)) {
if (len > scsi_bufflen(srb) - transferred)
len = scsi_bufflen(srb) - transferred;
data[3] = len&0xFF;
data[4] = (len>>8)&0xFF;
data[7+2] = MSB_of(sector>>16);
data[7+3] = LSB_of(sector>>16);
data[7+4] = MSB_of(sector&0xFFFF);
data[7+5] = LSB_of(sector&0xFFFF);
if (data[7+0] == GPCMD_READ_CD)
data[7+6] = 0;
data[7+7] = MSB_of(len / srb->transfersize);
data[7+8] = LSB_of(len / srb->transfersize);
result = usbat_hp8200e_rw_block_test(us, USBAT_ATA,
registers, data, 19,
USBAT_ATA_DATA, USBAT_ATA_STATUS, 0xFD,
(USBAT_QUAL_FCQ | USBAT_QUAL_ALQ),
DMA_FROM_DEVICE,
buffer,
len, 0, 1);
if (result != USB_STOR_TRANSPORT_GOOD)
break;
usb_stor_access_xfer_buf(buffer, len, srb,
&sg, &sg_offset, TO_XFER_BUF);
transferred += len;
sector += len / srb->transfersize;
}
kfree(buffer);
return result;
}
static int usbat_select_and_test_registers(struct us_data *us)
{
int selector;
unsigned char *status = us->iobuf;
for (selector = 0xA0; selector <= 0xB0; selector += 0x10) {
if (usbat_write(us, USBAT_ATA, USBAT_ATA_DEVICE, selector) !=
USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
if (usbat_read(us, USBAT_ATA, USBAT_ATA_STATUS, status) !=
USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
if (usbat_read(us, USBAT_ATA, USBAT_ATA_DEVICE, status) !=
USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
if (usbat_read(us, USBAT_ATA, USBAT_ATA_LBA_ME, status) !=
USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
if (usbat_read(us, USBAT_ATA, USBAT_ATA_LBA_HI, status) !=
USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
if (usbat_write(us, USBAT_ATA, USBAT_ATA_LBA_ME, 0x55) !=
USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
if (usbat_write(us, USBAT_ATA, USBAT_ATA_LBA_HI, 0xAA) !=
USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
if (usbat_read(us, USBAT_ATA, USBAT_ATA_LBA_ME, status) !=
USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
if (usbat_read(us, USBAT_ATA, USBAT_ATA_LBA_ME, status) !=
USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
}
return USB_STOR_TRANSPORT_GOOD;
}
static int init_usbat(struct us_data *us, int devicetype)
{
int rc;
struct usbat_info *info;
unsigned char subcountH = USBAT_ATA_LBA_HI;
unsigned char subcountL = USBAT_ATA_LBA_ME;
unsigned char *status = us->iobuf;
us->extra = kzalloc(sizeof(struct usbat_info), GFP_NOIO);
if (!us->extra)
return 1;
info = (struct usbat_info *) (us->extra);
rc = usbat_write_user_io(us,
USBAT_UIO_OE1 | USBAT_UIO_OE0,
USBAT_UIO_EPAD | USBAT_UIO_1);
if (rc != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
usb_stor_dbg(us, "INIT 1\n");
msleep(2000);
rc = usbat_read_user_io(us, status);
if (rc != USB_STOR_TRANSPORT_GOOD)
return rc;
usb_stor_dbg(us, "INIT 2\n");
rc = usbat_read_user_io(us, status);
if (rc != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
rc = usbat_read_user_io(us, status);
if (rc != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
usb_stor_dbg(us, "INIT 3\n");
rc = usbat_select_and_test_registers(us);
if (rc != USB_STOR_TRANSPORT_GOOD)
return rc;
usb_stor_dbg(us, "INIT 4\n");
rc = usbat_read_user_io(us, status);
if (rc != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
usb_stor_dbg(us, "INIT 5\n");
rc = usbat_device_enable_cdt(us);
if (rc != USB_STOR_TRANSPORT_GOOD)
return rc;
usb_stor_dbg(us, "INIT 6\n");
rc = usbat_read_user_io(us, status);
if (rc != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
usb_stor_dbg(us, "INIT 7\n");
msleep(1400);
rc = usbat_read_user_io(us, status);
if (rc != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
usb_stor_dbg(us, "INIT 8\n");
rc = usbat_select_and_test_registers(us);
if (rc != USB_STOR_TRANSPORT_GOOD)
return rc;
usb_stor_dbg(us, "INIT 9\n");
if (usbat_set_transport(us, info, devicetype))
return USB_STOR_TRANSPORT_ERROR;
usb_stor_dbg(us, "INIT 10\n");
if (usbat_get_device_type(us) == USBAT_DEV_FLASH) {
subcountH = 0x02;
subcountL = 0x00;
}
rc = usbat_set_shuttle_features(us, (USBAT_FEAT_ETEN | USBAT_FEAT_ET2 | USBAT_FEAT_ET1),
0x00, 0x88, 0x08, subcountH, subcountL);
if (rc != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
usb_stor_dbg(us, "INIT 11\n");
return USB_STOR_TRANSPORT_GOOD;
}
static int usbat_hp8200e_transport(struct scsi_cmnd *srb, struct us_data *us)
{
int result;
unsigned char *status = us->iobuf;
unsigned char registers[32];
unsigned char data[32];
unsigned int len;
int i;
len = scsi_bufflen(srb);
registers[0] = USBAT_ATA_FEATURES;
registers[1] = USBAT_ATA_SECCNT;
registers[2] = USBAT_ATA_SECNUM;
registers[3] = USBAT_ATA_LBA_ME;
registers[4] = USBAT_ATA_LBA_HI;
registers[5] = USBAT_ATA_DEVICE;
registers[6] = USBAT_ATA_CMD;
data[0] = 0x00;
data[1] = 0x00;
data[2] = 0x00;
data[3] = len&0xFF;
data[4] = (len>>8)&0xFF;
data[5] = 0xB0;
data[6] = 0xA0;
for (i=7; i<19; i++) {
registers[i] = 0x10;
data[i] = (i-7 >= srb->cmd_len) ? 0 : srb->cmnd[i-7];
}
result = usbat_get_status(us, status);
usb_stor_dbg(us, "Status = %02X\n", *status);
if (result != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
if (srb->cmnd[0] == TEST_UNIT_READY)
transferred = 0;
if (srb->sc_data_direction == DMA_TO_DEVICE) {
result = usbat_hp8200e_rw_block_test(us, USBAT_ATA,
registers, data, 19,
USBAT_ATA_DATA, USBAT_ATA_STATUS, 0xFD,
(USBAT_QUAL_FCQ | USBAT_QUAL_ALQ),
DMA_TO_DEVICE,
scsi_sglist(srb),
len, scsi_sg_count(srb), 10);
if (result == USB_STOR_TRANSPORT_GOOD) {
transferred += len;
usb_stor_dbg(us, "Wrote %08X bytes\n", transferred);
}
return result;
} else if (srb->cmnd[0] == READ_10 ||
srb->cmnd[0] == GPCMD_READ_CD) {
return usbat_hp8200e_handle_read10(us, registers, data, srb);
}
if (len > 0xFFFF) {
usb_stor_dbg(us, "Error: len = %08X... what do I do now?\n",
len);
return USB_STOR_TRANSPORT_ERROR;
}
result = usbat_multiple_write(us, registers, data, 7);
if (result != USB_STOR_TRANSPORT_GOOD)
return result;
result = usbat_write_block(us, USBAT_ATA, srb->cmnd, 12,
srb->cmnd[0] == GPCMD_BLANK ? 75 : 10, 0);
if (result != USB_STOR_TRANSPORT_GOOD)
return result;
if (len != 0 && (srb->sc_data_direction == DMA_FROM_DEVICE)) {
if (usbat_read(us, USBAT_ATA, USBAT_ATA_LBA_ME, status) !=
USB_STOR_XFER_GOOD) {
return USB_STOR_TRANSPORT_ERROR;
}
if (len > 0xFF) {
len = *status;
if (usbat_read(us, USBAT_ATA, USBAT_ATA_LBA_HI, status) !=
USB_STOR_XFER_GOOD) {
return USB_STOR_TRANSPORT_ERROR;
}
len += ((unsigned int) *status)<<8;
}
else
len = *status;
result = usbat_read_block(us, scsi_sglist(srb), len,
scsi_sg_count(srb));
}
return result;
}
static int usbat_flash_transport(struct scsi_cmnd * srb, struct us_data *us)
{
int rc;
struct usbat_info *info = (struct usbat_info *) (us->extra);
unsigned long block, blocks;
unsigned char *ptr = us->iobuf;
static unsigned char inquiry_response[36] = {
0x00, 0x80, 0x00, 0x01, 0x1F, 0x00, 0x00, 0x00
};
if (srb->cmnd[0] == INQUIRY) {
usb_stor_dbg(us, "INQUIRY - Returning bogus response\n");
memcpy(ptr, inquiry_response, sizeof(inquiry_response));
fill_inquiry_response(us, ptr, 36);
return USB_STOR_TRANSPORT_GOOD;
}
if (srb->cmnd[0] == READ_CAPACITY) {
rc = usbat_flash_check_media(us, info);
if (rc != USB_STOR_TRANSPORT_GOOD)
return rc;
rc = usbat_flash_get_sector_count(us, info);
if (rc != USB_STOR_TRANSPORT_GOOD)
return rc;
info->ssize = 0x200;
usb_stor_dbg(us, "READ_CAPACITY: %ld sectors, %ld bytes per sector\n",
info->sectors, info->ssize);
((__be32 *) ptr)[0] = cpu_to_be32(info->sectors - 1);
((__be32 *) ptr)[1] = cpu_to_be32(info->ssize);
usb_stor_set_xfer_buf(ptr, 8, srb);
return USB_STOR_TRANSPORT_GOOD;
}
if (srb->cmnd[0] == MODE_SELECT_10) {
usb_stor_dbg(us, "Gah! MODE_SELECT_10\n");
return USB_STOR_TRANSPORT_ERROR;
}
if (srb->cmnd[0] == READ_10) {
block = ((u32)(srb->cmnd[2]) << 24) | ((u32)(srb->cmnd[3]) << 16) |
((u32)(srb->cmnd[4]) << 8) | ((u32)(srb->cmnd[5]));
blocks = ((u32)(srb->cmnd[7]) << 8) | ((u32)(srb->cmnd[8]));
usb_stor_dbg(us, "READ_10: read block 0x%04lx count %ld\n",
block, blocks);
return usbat_flash_read_data(us, info, block, blocks);
}
if (srb->cmnd[0] == READ_12) {
block = ((u32)(srb->cmnd[2]) << 24) | ((u32)(srb->cmnd[3]) << 16) |
((u32)(srb->cmnd[4]) << 8) | ((u32)(srb->cmnd[5]));
blocks = ((u32)(srb->cmnd[6]) << 24) | ((u32)(srb->cmnd[7]) << 16) |
((u32)(srb->cmnd[8]) << 8) | ((u32)(srb->cmnd[9]));
usb_stor_dbg(us, "READ_12: read block 0x%04lx count %ld\n",
block, blocks);
return usbat_flash_read_data(us, info, block, blocks);
}
if (srb->cmnd[0] == WRITE_10) {
block = ((u32)(srb->cmnd[2]) << 24) | ((u32)(srb->cmnd[3]) << 16) |
((u32)(srb->cmnd[4]) << 8) | ((u32)(srb->cmnd[5]));
blocks = ((u32)(srb->cmnd[7]) << 8) | ((u32)(srb->cmnd[8]));
usb_stor_dbg(us, "WRITE_10: write block 0x%04lx count %ld\n",
block, blocks);
return usbat_flash_write_data(us, info, block, blocks);
}
if (srb->cmnd[0] == WRITE_12) {
block = ((u32)(srb->cmnd[2]) << 24) | ((u32)(srb->cmnd[3]) << 16) |
((u32)(srb->cmnd[4]) << 8) | ((u32)(srb->cmnd[5]));
blocks = ((u32)(srb->cmnd[6]) << 24) | ((u32)(srb->cmnd[7]) << 16) |
((u32)(srb->cmnd[8]) << 8) | ((u32)(srb->cmnd[9]));
usb_stor_dbg(us, "WRITE_12: write block 0x%04lx count %ld\n",
block, blocks);
return usbat_flash_write_data(us, info, block, blocks);
}
if (srb->cmnd[0] == TEST_UNIT_READY) {
usb_stor_dbg(us, "TEST_UNIT_READY\n");
rc = usbat_flash_check_media(us, info);
if (rc != USB_STOR_TRANSPORT_GOOD)
return rc;
return usbat_check_status(us);
}
if (srb->cmnd[0] == REQUEST_SENSE) {
usb_stor_dbg(us, "REQUEST_SENSE\n");
memset(ptr, 0, 18);
ptr[0] = 0xF0;
ptr[2] = info->sense_key;
ptr[7] = 11;
ptr[12] = info->sense_asc;
ptr[13] = info->sense_ascq;
usb_stor_set_xfer_buf(ptr, 18, srb);
return USB_STOR_TRANSPORT_GOOD;
}
if (srb->cmnd[0] == ALLOW_MEDIUM_REMOVAL) {
return USB_STOR_TRANSPORT_GOOD;
}
usb_stor_dbg(us, "Gah! Unknown command: %d (0x%x)\n",
srb->cmnd[0], srb->cmnd[0]);
info->sense_key = 0x05;
info->sense_asc = 0x20;
info->sense_ascq = 0x00;
return USB_STOR_TRANSPORT_FAILED;
}
static int init_usbat_cd(struct us_data *us)
{
return init_usbat(us, USBAT_DEV_HP8200);
}
static int init_usbat_flash(struct us_data *us)
{
return init_usbat(us, USBAT_DEV_FLASH);
}
static int usbat_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct us_data *us;
int result;
result = usb_stor_probe1(&us, intf, id,
(id - usbat_usb_ids) + usbat_unusual_dev_list);
if (result)
return result;
us->transport_name = "Shuttle USBAT";
us->transport = usbat_flash_transport;
us->transport_reset = usb_stor_CB_reset;
us->max_lun = 1;
result = usb_stor_probe2(us);
return result;
}
