static int
freecom_readdata (struct scsi_cmnd *srb, struct us_data *us,
unsigned int ipipe, unsigned int opipe, int count)
{
struct freecom_xfer_wrap *fxfr =
(struct freecom_xfer_wrap *) us->iobuf;
int result;
fxfr->Type = FCM_PACKET_INPUT | 0x00;
fxfr->Timeout = 0;
fxfr->Count = cpu_to_le32 (count);
memset (fxfr->Pad, 0, sizeof (fxfr->Pad));
US_DEBUGP("Read data Freecom! (c=%d)\n", count);
result = usb_stor_bulk_transfer_buf (us, opipe, fxfr,
FCM_PACKET_LENGTH, NULL);
if (result != USB_STOR_XFER_GOOD) {
US_DEBUGP ("Freecom readdata transport error\n");
return USB_STOR_TRANSPORT_ERROR;
}
US_DEBUGP("Start of read\n");
result = usb_stor_bulk_srb(us, ipipe, srb);
US_DEBUGP("freecom_readdata done!\n");
if (result > USB_STOR_XFER_SHORT)
return USB_STOR_TRANSPORT_ERROR;
return USB_STOR_TRANSPORT_GOOD;
}
static int
freecom_writedata (struct scsi_cmnd *srb, struct us_data *us,
int unsigned ipipe, unsigned int opipe, int count)
{
struct freecom_xfer_wrap *fxfr =
(struct freecom_xfer_wrap *) us->iobuf;
int result;
fxfr->Type = FCM_PACKET_OUTPUT | 0x00;
fxfr->Timeout = 0;
fxfr->Count = cpu_to_le32 (count);
memset (fxfr->Pad, 0, sizeof (fxfr->Pad));
US_DEBUGP("Write data Freecom! (c=%d)\n", count);
result = usb_stor_bulk_transfer_buf (us, opipe, fxfr,
FCM_PACKET_LENGTH, NULL);
if (result != USB_STOR_XFER_GOOD) {
US_DEBUGP ("Freecom writedata transport error\n");
return USB_STOR_TRANSPORT_ERROR;
}
US_DEBUGP("Start of write\n");
result = usb_stor_bulk_srb(us, opipe, srb);
US_DEBUGP("freecom_writedata done!\n");
if (result > USB_STOR_XFER_SHORT)
return USB_STOR_TRANSPORT_ERROR;
return USB_STOR_TRANSPORT_GOOD;
}
static int freecom_transport(struct scsi_cmnd *srb, struct us_data *us)
{
struct freecom_cb_wrap *fcb;
struct freecom_status *fst;
unsigned int ipipe, opipe;
int result;
unsigned int partial;
int length;
fcb = (struct freecom_cb_wrap *) us->iobuf;
fst = (struct freecom_status *) us->iobuf;
US_DEBUGP("Freecom TRANSPORT STARTED\n");
opipe = us->send_bulk_pipe;
ipipe = us->recv_bulk_pipe;
fcb->Type = FCM_PACKET_ATAPI | 0x00;
fcb->Timeout = 0;
memcpy (fcb->Atapi, srb->cmnd, 12);
memset (fcb->Filler, 0, sizeof (fcb->Filler));
US_DEBUG(pdump (srb->cmnd, 12));
result = usb_stor_bulk_transfer_buf (us, opipe, fcb,
FCM_PACKET_LENGTH, NULL);
if (result != USB_STOR_XFER_GOOD) {
US_DEBUGP ("freecom transport error\n");
return USB_STOR_TRANSPORT_ERROR;
}
result = usb_stor_bulk_transfer_buf (us, ipipe, fst,
FCM_STATUS_PACKET_LENGTH, &partial);
US_DEBUGP("foo Status result %d %u\n", result, partial);
if (result != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
US_DEBUG(pdump ((void *) fst, partial));
while (fst->Status & FCM_STATUS_BUSY) {
US_DEBUGP("20 second USB/ATAPI bridge TIMEOUT occurred!\n");
US_DEBUGP("fst->Status is %x\n", fst->Status);
fcb->Type = FCM_PACKET_STATUS;
fcb->Timeout = 0;
memset (fcb->Atapi, 0, sizeof(fcb->Atapi));
memset (fcb->Filler, 0, sizeof (fcb->Filler));
result = usb_stor_bulk_transfer_buf (us, opipe, fcb,
FCM_PACKET_LENGTH, NULL);
if (result != USB_STOR_XFER_GOOD) {
US_DEBUGP ("freecom transport error\n");
return USB_STOR_TRANSPORT_ERROR;
}
result = usb_stor_bulk_transfer_buf (us, ipipe, fst,
FCM_STATUS_PACKET_LENGTH, &partial);
US_DEBUGP("bar Status result %d %u\n", result, partial);
if (result != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
US_DEBUG(pdump ((void *) fst, partial));
}
if (partial != 4)
return USB_STOR_TRANSPORT_ERROR;
if ((fst->Status & 1) != 0) {
US_DEBUGP("operation failed\n");
return USB_STOR_TRANSPORT_FAILED;
}
US_DEBUGP("Device indicates that it has %d bytes available\n",
le16_to_cpu (fst->Count));
US_DEBUGP("SCSI requested %d\n", scsi_bufflen(srb));
switch (srb->cmnd[0]) {
case INQUIRY:
case REQUEST_SENSE:
case MODE_SENSE:
case MODE_SENSE_10:
length = le16_to_cpu(fst->Count);
break;
default:
length = scsi_bufflen(srb);
}
if (length > scsi_bufflen(srb)) {
length = scsi_bufflen(srb);
US_DEBUGP("Truncating request to match buffer length: %d\n", length);
}
switch (us->srb->sc_data_direction) {
case DMA_FROM_DEVICE:
if (!length)
break;
if ((fst->Status & DRQ_STAT) == 0 || (fst->Reason & 3) != 2) {
US_DEBUGP("SCSI wants data, drive doesn't have any\n");
return USB_STOR_TRANSPORT_FAILED;
}
result = freecom_readdata (srb, us, ipipe, opipe, length);
if (result != USB_STOR_TRANSPORT_GOOD)
return result;
US_DEBUGP("FCM: Waiting for status\n");
result = usb_stor_bulk_transfer_buf (us, ipipe, fst,
FCM_PACKET_LENGTH, &partial);
US_DEBUG(pdump ((void *) fst, partial));
if (partial != 4 || result > USB_STOR_XFER_SHORT)
return USB_STOR_TRANSPORT_ERROR;
if ((fst->Status & ERR_STAT) != 0) {
US_DEBUGP("operation failed\n");
return USB_STOR_TRANSPORT_FAILED;
}
if ((fst->Reason & 3) != 3) {
US_DEBUGP("Drive seems still hungry\n");
return USB_STOR_TRANSPORT_FAILED;
}
US_DEBUGP("Transfer happy\n");
break;
case DMA_TO_DEVICE:
if (!length)
break;
result = freecom_writedata (srb, us, ipipe, opipe, length);
if (result != USB_STOR_TRANSPORT_GOOD)
return result;
US_DEBUGP("FCM: Waiting for status\n");
result = usb_stor_bulk_transfer_buf (us, ipipe, fst,
FCM_PACKET_LENGTH, &partial);
if (partial != 4 || result > USB_STOR_XFER_SHORT)
return USB_STOR_TRANSPORT_ERROR;
if ((fst->Status & ERR_STAT) != 0) {
US_DEBUGP("operation failed\n");
return USB_STOR_TRANSPORT_FAILED;
}
if ((fst->Reason & 3) != 3) {
US_DEBUGP("Drive seems still hungry\n");
return USB_STOR_TRANSPORT_FAILED;
}
US_DEBUGP("Transfer happy\n");
break;
case DMA_NONE:
break;
default:
US_DEBUGP ("freecom unimplemented direction: %d\n",
us->srb->sc_data_direction);
return USB_STOR_TRANSPORT_FAILED;
break;
}
return USB_STOR_TRANSPORT_GOOD;
}
static int init_freecom(struct us_data *us)
{
int result;
char *buffer = us->iobuf;
result = usb_stor_control_msg(us, us->recv_ctrl_pipe,
0x4c, 0xc0, 0x4346, 0x0, buffer, 0x20, 3*HZ);
buffer[32] = '\0';
US_DEBUGP("String returned from FC init is: %s\n", buffer);
result = usb_stor_control_msg(us, us->send_ctrl_pipe,
0x4d, 0x40, 0x24d8, 0x0, NULL, 0x0, 3*HZ);
US_DEBUGP("result from activate reset is %d\n", result);
mdelay(250);
result = usb_stor_control_msg(us, us->send_ctrl_pipe,
0x4d, 0x40, 0x24f8, 0x0, NULL, 0x0, 3*HZ);
US_DEBUGP("result from clear reset is %d\n", result);
mdelay(3 * 1000);
return USB_STOR_TRANSPORT_GOOD;
}
static int usb_stor_freecom_reset(struct us_data *us)
{
printk (KERN_CRIT "freecom reset called\n");
return FAILED;
}
static void pdump (void *ibuffer, int length)
{
static char line[80];
int offset = 0;
unsigned char *buffer = (unsigned char *) ibuffer;
int i, j;
int from, base;
offset = 0;
for (i = 0; i < length; i++) {
if ((i & 15) == 0) {
if (i > 0) {
offset += sprintf (line+offset, " - ");
for (j = i - 16; j < i; j++) {
if (buffer[j] >= 32 && buffer[j] <= 126)
line[offset++] = buffer[j];
else
line[offset++] = '.';
}
line[offset] = 0;
US_DEBUGP("%s\n", line);
offset = 0;
}
offset += sprintf (line+offset, "%08x:", i);
} else if ((i & 7) == 0) {
offset += sprintf (line+offset, " -");
}
offset += sprintf (line+offset, " %02x", buffer[i] & 0xff);
}
from = (length - 1) % 16;
base = ((length - 1) / 16) * 16;
for (i = from + 1; i < 16; i++)
offset += sprintf (line+offset, " ");
if (from < 8)
offset += sprintf (line+offset, " ");
offset += sprintf (line+offset, " - ");
for (i = 0; i <= from; i++) {
if (buffer[base+i] >= 32 && buffer[base+i] <= 126)
line[offset++] = buffer[base+i];
else
line[offset++] = '.';
}
line[offset] = 0;
US_DEBUGP("%s\n", line);
offset = 0;
}
static int freecom_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct us_data *us;
int result;
result = usb_stor_probe1(&us, intf, id,
(id - freecom_usb_ids) + freecom_unusual_dev_list);
if (result)
return result;
us->transport_name = "Freecom";
us->transport = freecom_transport;
us->transport_reset = usb_stor_freecom_reset;
us->max_lun = 0;
result = usb_stor_probe2(us);
return result;
}
static int __init freecom_init(void)
{
return usb_register(&freecom_driver);
}
static void __exit freecom_exit(void)
{
usb_deregister(&freecom_driver);
}
