static inline int
datafab_bulk_read(struct us_data *us, unsigned char *data, unsigned int len) {
if (len == 0)
return USB_STOR_XFER_GOOD;
usb_stor_dbg(us, "len = %d\n", len);
return usb_stor_bulk_transfer_buf(us, us->recv_bulk_pipe,
data, len, NULL);
}
static inline int
datafab_bulk_write(struct us_data *us, unsigned char *data, unsigned int len) {
if (len == 0)
return USB_STOR_XFER_GOOD;
usb_stor_dbg(us, "len = %d\n", len);
return usb_stor_bulk_transfer_buf(us, us->send_bulk_pipe,
data, len, NULL);
}
static int datafab_read_data(struct us_data *us,
struct datafab_info *info,
u32 sector,
u32 sectors)
{
unsigned char *command = us->iobuf;
unsigned char *buffer;
unsigned char thistime;
unsigned int totallen, alloclen;
int len, result;
unsigned int sg_offset = 0;
struct scatterlist *sg = NULL;
if (sectors > 0x0FFFFFFF)
return USB_STOR_TRANSPORT_ERROR;
if (info->lun == -1) {
result = datafab_determine_lun(us, info);
if (result != USB_STOR_TRANSPORT_GOOD)
return result;
}
totallen = sectors * info->ssize;
alloclen = min(totallen, 65536u);
buffer = kmalloc(alloclen, GFP_NOIO);
if (buffer == NULL)
return USB_STOR_TRANSPORT_ERROR;
do {
len = min(totallen, alloclen);
thistime = (len / info->ssize) & 0xff;
command[0] = 0;
command[1] = thistime;
command[2] = sector & 0xFF;
command[3] = (sector >> 8) & 0xFF;
command[4] = (sector >> 16) & 0xFF;
command[5] = 0xE0 + (info->lun << 4);
command[5] |= (sector >> 24) & 0x0F;
command[6] = 0x20;
command[7] = 0x01;
result = datafab_bulk_write(us, command, 8);
if (result != USB_STOR_XFER_GOOD)
goto leave;
result = datafab_bulk_read(us, buffer, len);
if (result != USB_STOR_XFER_GOOD)
goto leave;
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
static int datafab_write_data(struct us_data *us,
struct datafab_info *info,
u32 sector,
u32 sectors)
{
unsigned char *command = us->iobuf;
unsigned char *reply = us->iobuf;
unsigned char *buffer;
unsigned char thistime;
unsigned int totallen, alloclen;
int len, result;
unsigned int sg_offset = 0;
struct scatterlist *sg = NULL;
if (sectors > 0x0FFFFFFF)
return USB_STOR_TRANSPORT_ERROR;
if (info->lun == -1) {
result = datafab_determine_lun(us, info);
if (result != USB_STOR_TRANSPORT_GOOD)
return result;
}
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
command[0] = 0;
command[1] = thistime;
command[2] = sector & 0xFF;
command[3] = (sector >> 8) & 0xFF;
command[4] = (sector >> 16) & 0xFF;
command[5] = 0xE0 + (info->lun << 4);
command[5] |= (sector >> 24) & 0x0F;
command[6] = 0x30;
command[7] = 0x02;
result = datafab_bulk_write(us, command, 8);
if (result != USB_STOR_XFER_GOOD)
goto leave;
result = datafab_bulk_write(us, buffer, len);
if (result != USB_STOR_XFER_GOOD)
goto leave;
result = datafab_bulk_read(us, reply, 2);
if (result != USB_STOR_XFER_GOOD)
goto leave;
if (reply[0] != 0x50 && reply[1] != 0) {
usb_stor_dbg(us, "Gah! write return code: %02x %02x\n",
reply[0], reply[1]);
result = USB_STOR_TRANSPORT_ERROR;
goto leave;
}
sector += thistime;
totallen -= len;
} while (totallen > 0);
kfree(buffer);
return USB_STOR_TRANSPORT_GOOD;
leave:
kfree(buffer);
return USB_STOR_TRANSPORT_ERROR;
}
static int datafab_determine_lun(struct us_data *us,
struct datafab_info *info)
{
static unsigned char scommand[8] = { 0, 1, 0, 0, 0, 0xa0, 0xec, 1 };
unsigned char *command = us->iobuf;
unsigned char *buf;
int count = 0, rc;
if (!info)
return USB_STOR_TRANSPORT_ERROR;
memcpy(command, scommand, 8);
buf = kmalloc(512, GFP_NOIO);
if (!buf)
return USB_STOR_TRANSPORT_ERROR;
usb_stor_dbg(us, "locating...\n");
while (count++ < 3) {
command[5] = 0xa0;
rc = datafab_bulk_write(us, command, 8);
if (rc != USB_STOR_XFER_GOOD) {
rc = USB_STOR_TRANSPORT_ERROR;
goto leave;
}
rc = datafab_bulk_read(us, buf, 512);
if (rc == USB_STOR_XFER_GOOD) {
info->lun = 0;
rc = USB_STOR_TRANSPORT_GOOD;
goto leave;
}
command[5] = 0xb0;
rc = datafab_bulk_write(us, command, 8);
if (rc != USB_STOR_XFER_GOOD) {
rc = USB_STOR_TRANSPORT_ERROR;
goto leave;
}
rc = datafab_bulk_read(us, buf, 512);
if (rc == USB_STOR_XFER_GOOD) {
info->lun = 1;
rc = USB_STOR_TRANSPORT_GOOD;
goto leave;
}
msleep(20);
}
rc = USB_STOR_TRANSPORT_ERROR;
leave:
kfree(buf);
return rc;
}
static int datafab_id_device(struct us_data *us,
struct datafab_info *info)
{
static unsigned char scommand[8] = { 0, 1, 0, 0, 0, 0xa0, 0xec, 1 };
unsigned char *command = us->iobuf;
unsigned char *reply;
int rc;
if (!info)
return USB_STOR_TRANSPORT_ERROR;
if (info->lun == -1) {
rc = datafab_determine_lun(us, info);
if (rc != USB_STOR_TRANSPORT_GOOD)
return rc;
}
memcpy(command, scommand, 8);
reply = kmalloc(512, GFP_NOIO);
if (!reply)
return USB_STOR_TRANSPORT_ERROR;
command[5] += (info->lun << 4);
rc = datafab_bulk_write(us, command, 8);
if (rc != USB_STOR_XFER_GOOD) {
rc = USB_STOR_TRANSPORT_ERROR;
goto leave;
}
rc = datafab_bulk_read(us, reply, 512);
if (rc == USB_STOR_XFER_GOOD) {
info->sectors = ((u32)(reply[117]) << 24) |
((u32)(reply[116]) << 16) |
((u32)(reply[115]) << 8) |
((u32)(reply[114]) );
rc = USB_STOR_TRANSPORT_GOOD;
goto leave;
}
rc = USB_STOR_TRANSPORT_ERROR;
leave:
kfree(reply);
return rc;
}
static int datafab_handle_mode_sense(struct us_data *us,
struct scsi_cmnd * srb,
int sense_6)
{
static unsigned char rw_err_page[12] = {
0x1, 0xA, 0x21, 1, 0, 0, 0, 0, 1, 0, 0, 0
};
static unsigned char cache_page[12] = {
0x8, 0xA, 0x1, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
static unsigned char rbac_page[12] = {
0x1B, 0xA, 0, 0x81, 0, 0, 0, 0, 0, 0, 0, 0
};
static unsigned char timer_page[8] = {
0x1C, 0x6, 0, 0, 0, 0
};
unsigned char pc, page_code;
unsigned int i = 0;
struct datafab_info *info = (struct datafab_info *) (us->extra);
unsigned char *ptr = us->iobuf;
pc = srb->cmnd[2] >> 6;
page_code = srb->cmnd[2] & 0x3F;
switch (pc) {
case 0x0:
usb_stor_dbg(us, "Current values\n");
break;
case 0x1:
usb_stor_dbg(us, "Changeable values\n");
break;
case 0x2:
usb_stor_dbg(us, "Default values\n");
break;
case 0x3:
usb_stor_dbg(us, "Saves values\n");
break;
}
memset(ptr, 0, 8);
if (sense_6) {
ptr[2] = 0x00;
i = 4;
} else {
ptr[3] = 0x00;
i = 8;
}
switch (page_code) {
default:
info->sense_key = 0x05;
info->sense_asc = 0x24;
info->sense_ascq = 0x00;
return USB_STOR_TRANSPORT_FAILED;
case 0x1:
memcpy(ptr + i, rw_err_page, sizeof(rw_err_page));
i += sizeof(rw_err_page);
break;
case 0x8:
memcpy(ptr + i, cache_page, sizeof(cache_page));
i += sizeof(cache_page);
break;
case 0x1B:
memcpy(ptr + i, rbac_page, sizeof(rbac_page));
i += sizeof(rbac_page);
break;
case 0x1C:
memcpy(ptr + i, timer_page, sizeof(timer_page));
i += sizeof(timer_page);
break;
case 0x3F:
memcpy(ptr + i, timer_page, sizeof(timer_page));
i += sizeof(timer_page);
memcpy(ptr + i, rbac_page, sizeof(rbac_page));
i += sizeof(rbac_page);
memcpy(ptr + i, cache_page, sizeof(cache_page));
i += sizeof(cache_page);
memcpy(ptr + i, rw_err_page, sizeof(rw_err_page));
i += sizeof(rw_err_page);
break;
}
if (sense_6)
ptr[0] = i - 1;
else
((__be16 *) ptr)[0] = cpu_to_be16(i - 2);
usb_stor_set_xfer_buf(ptr, i, srb);
return USB_STOR_TRANSPORT_GOOD;
}
static void datafab_info_destructor(void *extra)
{
}
static int datafab_transport(struct scsi_cmnd *srb, struct us_data *us)
{
struct datafab_info *info;
int rc;
unsigned long block, blocks;
unsigned char *ptr = us->iobuf;
static unsigned char inquiry_reply[8] = {
0x00, 0x80, 0x00, 0x01, 0x1F, 0x00, 0x00, 0x00
};
if (!us->extra) {
us->extra = kzalloc(sizeof(struct datafab_info), GFP_NOIO);
if (!us->extra)
return USB_STOR_TRANSPORT_ERROR;
us->extra_destructor = datafab_info_destructor;
((struct datafab_info *)us->extra)->lun = -1;
}
info = (struct datafab_info *) (us->extra);
if (srb->cmnd[0] == INQUIRY) {
usb_stor_dbg(us, "INQUIRY - Returning bogus response\n");
memcpy(ptr, inquiry_reply, sizeof(inquiry_reply));
fill_inquiry_response(us, ptr, 36);
return USB_STOR_TRANSPORT_GOOD;
}
if (srb->cmnd[0] == READ_CAPACITY) {
info->ssize = 0x200;
rc = datafab_id_device(us, info);
if (rc != USB_STOR_TRANSPORT_GOOD)
return rc;
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
return datafab_read_data(us, info, block, blocks);
}
if (srb->cmnd[0] == READ_12) {
block = ((u32)(srb->cmnd[2]) << 24) | ((u32)(srb->cmnd[3]) << 16) |
((u32)(srb->cmnd[4]) << 8) | ((u32)(srb->cmnd[5]));
blocks = ((u32)(srb->cmnd[6]) << 24) | ((u32)(srb->cmnd[7]) << 16) |
((u32)(srb->cmnd[8]) << 8) | ((u32)(srb->cmnd[9]));
usb_stor_dbg(us, "READ_12: read block 0x%04lx count %ld\n",
block, blocks);
return datafab_read_data(us, info, block, blocks);
}
if (srb->cmnd[0] == WRITE_10) {
block = ((u32)(srb->cmnd[2]) << 24) | ((u32)(srb->cmnd[3]) << 16) |
((u32)(srb->cmnd[4]) << 8) | ((u32)(srb->cmnd[5]));
blocks = ((u32)(srb->cmnd[7]) << 8) | ((u32)(srb->cmnd[8]));
usb_stor_dbg(us, "WRITE_10: write block 0x%04lx count %ld\n",
block, blocks);
return datafab_write_data(us, info, block, blocks);
}
if (srb->cmnd[0] == WRITE_12) {
block = ((u32)(srb->cmnd[2]) << 24) | ((u32)(srb->cmnd[3]) << 16) |
((u32)(srb->cmnd[4]) << 8) | ((u32)(srb->cmnd[5]));
blocks = ((u32)(srb->cmnd[6]) << 24) | ((u32)(srb->cmnd[7]) << 16) |
((u32)(srb->cmnd[8]) << 8) | ((u32)(srb->cmnd[9]));
usb_stor_dbg(us, "WRITE_12: write block 0x%04lx count %ld\n",
block, blocks);
return datafab_write_data(us, info, block, blocks);
}
if (srb->cmnd[0] == TEST_UNIT_READY) {
usb_stor_dbg(us, "TEST_UNIT_READY\n");
return datafab_id_device(us, info);
}
if (srb->cmnd[0] == REQUEST_SENSE) {
usb_stor_dbg(us, "REQUEST_SENSE - Returning faked response\n");
memset(ptr, 0, 18);
ptr[0] = 0xF0;
ptr[2] = info->sense_key;
ptr[7] = 11;
ptr[12] = info->sense_asc;
ptr[13] = info->sense_ascq;
usb_stor_set_xfer_buf(ptr, 18, srb);
return USB_STOR_TRANSPORT_GOOD;
}
if (srb->cmnd[0] == MODE_SENSE) {
usb_stor_dbg(us, "MODE_SENSE_6 detected\n");
return datafab_handle_mode_sense(us, srb, 1);
}
if (srb->cmnd[0] == MODE_SENSE_10) {
usb_stor_dbg(us, "MODE_SENSE_10 detected\n");
return datafab_handle_mode_sense(us, srb, 0);
}
if (srb->cmnd[0] == ALLOW_MEDIUM_REMOVAL) {
return USB_STOR_TRANSPORT_GOOD;
}
if (srb->cmnd[0] == START_STOP) {
usb_stor_dbg(us, "START_STOP\n");
rc = datafab_id_device(us, info);
if (rc == USB_STOR_TRANSPORT_GOOD) {
info->sense_key = NO_SENSE;
srb->result = SUCCESS;
} else {
info->sense_key = UNIT_ATTENTION;
srb->result = SAM_STAT_CHECK_CONDITION;
}
return rc;
}
usb_stor_dbg(us, "Gah! Unknown command: %d (0x%x)\n",
srb->cmnd[0], srb->cmnd[0]);
info->sense_key = 0x05;
info->sense_asc = 0x20;
info->sense_ascq = 0x00;
return USB_STOR_TRANSPORT_FAILED;
}
static int datafab_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct us_data *us;
int result;
result = usb_stor_probe1(&us, intf, id,
(id - datafab_usb_ids) + datafab_unusual_dev_list);
if (result)
return result;
us->transport_name = "Datafab Bulk-Only";
us->transport = datafab_transport;
us->transport_reset = usb_stor_Bulk_reset;
us->max_lun = 1;
result = usb_stor_probe2(us);
return result;
}
