static void update_edgeport_E2PROM(struct edgeport_serial *edge_serial)
{
struct device *dev = &edge_serial->serial->dev->dev;
__u32 BootCurVer;
__u32 BootNewVer;
__u8 BootMajorVersion;
__u8 BootMinorVersion;
__u16 BootBuildNumber;
__u32 Bootaddr;
const struct ihex_binrec *rec;
const struct firmware *fw;
const char *fw_name;
int response;
switch (edge_serial->product_info.iDownloadFile) {
case EDGE_DOWNLOAD_FILE_I930:
fw_name = "edgeport/boot.fw";
break;
case EDGE_DOWNLOAD_FILE_80251:
fw_name = "edgeport/boot2.fw";
break;
default:
return;
}
response = request_ihex_firmware(&fw, fw_name,
&edge_serial->serial->dev->dev);
if (response) {
dev_err(dev, "Failed to load image \"%s\" err %d\n",
fw_name, response);
return;
}
rec = (const struct ihex_binrec *)fw->data;
BootMajorVersion = rec->data[0];
BootMinorVersion = rec->data[1];
BootBuildNumber = (rec->data[2] << 8) | rec->data[3];
BootCurVer = (edge_serial->boot_descriptor.MajorVersion << 24) +
(edge_serial->boot_descriptor.MinorVersion << 16) +
le16_to_cpu(edge_serial->boot_descriptor.BuildNumber);
BootNewVer = (BootMajorVersion << 24) +
(BootMinorVersion << 16) +
BootBuildNumber;
dev_dbg(dev, "Current Boot Image version %d.%d.%d\n",
edge_serial->boot_descriptor.MajorVersion,
edge_serial->boot_descriptor.MinorVersion,
le16_to_cpu(edge_serial->boot_descriptor.BuildNumber));
if (BootNewVer > BootCurVer) {
dev_dbg(dev, "**Update Boot Image from %d.%d.%d to %d.%d.%d\n",
edge_serial->boot_descriptor.MajorVersion,
edge_serial->boot_descriptor.MinorVersion,
le16_to_cpu(edge_serial->boot_descriptor.BuildNumber),
BootMajorVersion, BootMinorVersion, BootBuildNumber);
dev_dbg(dev, "Downloading new Boot Image\n");
for (rec = ihex_next_binrec(rec); rec;
rec = ihex_next_binrec(rec)) {
Bootaddr = be32_to_cpu(rec->addr);
response = rom_write(edge_serial->serial,
Bootaddr >> 16,
Bootaddr & 0xFFFF,
be16_to_cpu(rec->len),
&rec->data[0]);
if (response < 0) {
dev_err(&edge_serial->serial->dev->dev,
"rom_write failed (%x, %x, %d)\n",
Bootaddr >> 16, Bootaddr & 0xFFFF,
be16_to_cpu(rec->len));
break;
}
}
} else {
dev_dbg(dev, "Boot Image -- already up to date\n");
}
release_firmware(fw);
}
static void dump_product_info(struct edgeport_serial *edge_serial,
struct edgeport_product_info *product_info)
{
struct device *dev = &edge_serial->serial->dev->dev;
dev_dbg(dev, "**Product Information:\n");
dev_dbg(dev, " ProductId %x\n", product_info->ProductId);
dev_dbg(dev, " NumPorts %d\n", product_info->NumPorts);
dev_dbg(dev, " ProdInfoVer %d\n", product_info->ProdInfoVer);
dev_dbg(dev, " IsServer %d\n", product_info->IsServer);
dev_dbg(dev, " IsRS232 %d\n", product_info->IsRS232);
dev_dbg(dev, " IsRS422 %d\n", product_info->IsRS422);
dev_dbg(dev, " IsRS485 %d\n", product_info->IsRS485);
dev_dbg(dev, " RomSize %d\n", product_info->RomSize);
dev_dbg(dev, " RamSize %d\n", product_info->RamSize);
dev_dbg(dev, " CpuRev %x\n", product_info->CpuRev);
dev_dbg(dev, " BoardRev %x\n", product_info->BoardRev);
dev_dbg(dev, " BootMajorVersion %d.%d.%d\n",
product_info->BootMajorVersion,
product_info->BootMinorVersion,
le16_to_cpu(product_info->BootBuildNumber));
dev_dbg(dev, " FirmwareMajorVersion %d.%d.%d\n",
product_info->FirmwareMajorVersion,
product_info->FirmwareMinorVersion,
le16_to_cpu(product_info->FirmwareBuildNumber));
dev_dbg(dev, " ManufactureDescDate %d/%d/%d\n",
product_info->ManufactureDescDate[0],
product_info->ManufactureDescDate[1],
product_info->ManufactureDescDate[2]+1900);
dev_dbg(dev, " iDownloadFile 0x%x\n",
product_info->iDownloadFile);
dev_dbg(dev, " EpicVer %d\n", product_info->EpicVer);
}
static void get_product_info(struct edgeport_serial *edge_serial)
{
struct edgeport_product_info *product_info = &edge_serial->product_info;
memset(product_info, 0, sizeof(struct edgeport_product_info));
product_info->ProductId = (__u16)(le16_to_cpu(edge_serial->serial->dev->descriptor.idProduct) & ~ION_DEVICE_ID_80251_NETCHIP);
product_info->NumPorts = edge_serial->manuf_descriptor.NumPorts;
product_info->ProdInfoVer = 0;
product_info->RomSize = edge_serial->manuf_descriptor.RomSize;
product_info->RamSize = edge_serial->manuf_descriptor.RamSize;
product_info->CpuRev = edge_serial->manuf_descriptor.CpuRev;
product_info->BoardRev = edge_serial->manuf_descriptor.BoardRev;
product_info->BootMajorVersion =
edge_serial->boot_descriptor.MajorVersion;
product_info->BootMinorVersion =
edge_serial->boot_descriptor.MinorVersion;
product_info->BootBuildNumber =
edge_serial->boot_descriptor.BuildNumber;
memcpy(product_info->ManufactureDescDate,
edge_serial->manuf_descriptor.DescDate,
sizeof(edge_serial->manuf_descriptor.DescDate));
if (le16_to_cpu(edge_serial->serial->dev->descriptor.idProduct)
& ION_DEVICE_ID_80251_NETCHIP)
product_info->iDownloadFile = EDGE_DOWNLOAD_FILE_80251;
else
product_info->iDownloadFile = EDGE_DOWNLOAD_FILE_I930;
switch (DEVICE_ID_FROM_USB_PRODUCT_ID(product_info->ProductId)) {
case ION_DEVICE_ID_EDGEPORT_COMPATIBLE:
case ION_DEVICE_ID_EDGEPORT_4T:
case ION_DEVICE_ID_EDGEPORT_4:
case ION_DEVICE_ID_EDGEPORT_2:
case ION_DEVICE_ID_EDGEPORT_8_DUAL_CPU:
case ION_DEVICE_ID_EDGEPORT_8:
case ION_DEVICE_ID_EDGEPORT_421:
case ION_DEVICE_ID_EDGEPORT_21:
case ION_DEVICE_ID_EDGEPORT_2_DIN:
case ION_DEVICE_ID_EDGEPORT_4_DIN:
case ION_DEVICE_ID_EDGEPORT_16_DUAL_CPU:
product_info->IsRS232 = 1;
break;
case ION_DEVICE_ID_EDGEPORT_2I:
product_info->IsRS422 = 1;
product_info->IsRS485 = 1;
break;
case ION_DEVICE_ID_EDGEPORT_8I:
case ION_DEVICE_ID_EDGEPORT_4I:
product_info->IsRS422 = 1;
break;
}
dump_product_info(edge_serial, product_info);
}
static int get_epic_descriptor(struct edgeport_serial *ep)
{
int result;
struct usb_serial *serial = ep->serial;
struct edgeport_product_info *product_info = &ep->product_info;
struct edge_compatibility_descriptor *epic = &ep->epic_descriptor;
struct edge_compatibility_bits *bits;
struct device *dev = &serial->dev->dev;
ep->is_epic = 0;
result = usb_control_msg(serial->dev, usb_rcvctrlpipe(serial->dev, 0),
USB_REQUEST_ION_GET_EPIC_DESC,
0xC0, 0x00, 0x00,
&ep->epic_descriptor,
sizeof(struct edge_compatibility_descriptor),
300);
if (result > 0) {
ep->is_epic = 1;
memset(product_info, 0, sizeof(struct edgeport_product_info));
product_info->NumPorts = epic->NumPorts;
product_info->ProdInfoVer = 0;
product_info->FirmwareMajorVersion = epic->MajorVersion;
product_info->FirmwareMinorVersion = epic->MinorVersion;
product_info->FirmwareBuildNumber = epic->BuildNumber;
product_info->iDownloadFile = epic->iDownloadFile;
product_info->EpicVer = epic->EpicVer;
product_info->Epic = epic->Supports;
product_info->ProductId = ION_DEVICE_ID_EDGEPORT_COMPATIBLE;
dump_product_info(ep, product_info);
bits = &ep->epic_descriptor.Supports;
dev_dbg(dev, "**EPIC descriptor:\n");
dev_dbg(dev, " VendEnableSuspend: %s\n", bits->VendEnableSuspend ? "TRUE": "FALSE");
dev_dbg(dev, " IOSPOpen : %s\n", bits->IOSPOpen ? "TRUE": "FALSE");
dev_dbg(dev, " IOSPClose : %s\n", bits->IOSPClose ? "TRUE": "FALSE");
dev_dbg(dev, " IOSPChase : %s\n", bits->IOSPChase ? "TRUE": "FALSE");
dev_dbg(dev, " IOSPSetRxFlow : %s\n", bits->IOSPSetRxFlow ? "TRUE": "FALSE");
dev_dbg(dev, " IOSPSetTxFlow : %s\n", bits->IOSPSetTxFlow ? "TRUE": "FALSE");
dev_dbg(dev, " IOSPSetXChar : %s\n", bits->IOSPSetXChar ? "TRUE": "FALSE");
dev_dbg(dev, " IOSPRxCheck : %s\n", bits->IOSPRxCheck ? "TRUE": "FALSE");
dev_dbg(dev, " IOSPSetClrBreak : %s\n", bits->IOSPSetClrBreak ? "TRUE": "FALSE");
dev_dbg(dev, " IOSPWriteMCR : %s\n", bits->IOSPWriteMCR ? "TRUE": "FALSE");
dev_dbg(dev, " IOSPWriteLCR : %s\n", bits->IOSPWriteLCR ? "TRUE": "FALSE");
dev_dbg(dev, " IOSPSetBaudRate : %s\n", bits->IOSPSetBaudRate ? "TRUE": "FALSE");
dev_dbg(dev, " TrueEdgeport : %s\n", bits->TrueEdgeport ? "TRUE": "FALSE");
}
return result;
}
static void edge_interrupt_callback(struct urb *urb)
{
struct edgeport_serial *edge_serial = urb->context;
struct device *dev;
struct edgeport_port *edge_port;
struct usb_serial_port *port;
unsigned char *data = urb->transfer_buffer;
int length = urb->actual_length;
int bytes_avail;
int position;
int txCredits;
int portNumber;
int result;
int status = urb->status;
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dev_dbg(&urb->dev->dev, "%s - urb shutting down with status: %d\n", __func__, status);
return;
default:
dev_dbg(&urb->dev->dev, "%s - nonzero urb status received: %d\n", __func__, status);
goto exit;
}
dev = &edge_serial->serial->dev->dev;
if (length) {
usb_serial_debug_data(dev, __func__, length, data);
if (length > 1) {
bytes_avail = data[0] | (data[1] << 8);
if (bytes_avail) {
spin_lock(&edge_serial->es_lock);
edge_serial->rxBytesAvail += bytes_avail;
dev_dbg(dev,
"%s - bytes_avail=%d, rxBytesAvail=%d, read_in_progress=%d\n",
__func__, bytes_avail,
edge_serial->rxBytesAvail,
edge_serial->read_in_progress);
if (edge_serial->rxBytesAvail > 0 &&
!edge_serial->read_in_progress) {
dev_dbg(dev, "%s - posting a read\n", __func__);
edge_serial->read_in_progress = true;
result = usb_submit_urb(edge_serial->read_urb, GFP_ATOMIC);
if (result) {
dev_err(dev,
"%s - usb_submit_urb(read bulk) failed with result = %d\n",
__func__, result);
edge_serial->read_in_progress = false;
}
}
spin_unlock(&edge_serial->es_lock);
}
}
position = 2;
portNumber = 0;
while ((position < length) &&
(portNumber < edge_serial->serial->num_ports)) {
txCredits = data[position] | (data[position+1] << 8);
if (txCredits) {
port = edge_serial->serial->port[portNumber];
edge_port = usb_get_serial_port_data(port);
if (edge_port->open) {
spin_lock(&edge_port->ep_lock);
edge_port->txCredits += txCredits;
spin_unlock(&edge_port->ep_lock);
dev_dbg(dev, "%s - txcredits for port%d = %d\n",
__func__, portNumber,
edge_port->txCredits);
tty_port_tty_wakeup(&edge_port->port->port);
send_more_port_data(edge_serial,
edge_port);
}
}
position += 2;
++portNumber;
}
}
exit:
result = usb_submit_urb(urb, GFP_ATOMIC);
if (result)
dev_err(&urb->dev->dev,
"%s - Error %d submitting control urb\n",
__func__, result);
}
static void edge_bulk_in_callback(struct urb *urb)
{
struct edgeport_serial *edge_serial = urb->context;
struct device *dev;
unsigned char *data = urb->transfer_buffer;
int retval;
__u16 raw_data_length;
int status = urb->status;
if (status) {
dev_dbg(&urb->dev->dev, "%s - nonzero read bulk status received: %d\n",
__func__, status);
edge_serial->read_in_progress = false;
return;
}
if (urb->actual_length == 0) {
dev_dbg(&urb->dev->dev, "%s - read bulk callback with no data\n", __func__);
edge_serial->read_in_progress = false;
return;
}
dev = &edge_serial->serial->dev->dev;
raw_data_length = urb->actual_length;
usb_serial_debug_data(dev, __func__, raw_data_length, data);
spin_lock(&edge_serial->es_lock);
edge_serial->rxBytesAvail -= raw_data_length;
dev_dbg(dev, "%s - Received = %d, rxBytesAvail %d\n", __func__,
raw_data_length, edge_serial->rxBytesAvail);
process_rcvd_data(edge_serial, data, urb->actual_length);
if (edge_serial->rxBytesAvail > 0) {
dev_dbg(dev, "%s - posting a read\n", __func__);
retval = usb_submit_urb(edge_serial->read_urb, GFP_ATOMIC);
if (retval) {
dev_err(dev,
"%s - usb_submit_urb(read bulk) failed, retval = %d\n",
__func__, retval);
edge_serial->read_in_progress = false;
}
} else {
edge_serial->read_in_progress = false;
}
spin_unlock(&edge_serial->es_lock);
}
static void edge_bulk_out_data_callback(struct urb *urb)
{
struct edgeport_port *edge_port = urb->context;
int status = urb->status;
if (status) {
dev_dbg(&urb->dev->dev,
"%s - nonzero write bulk status received: %d\n",
__func__, status);
}
if (edge_port->open)
tty_port_tty_wakeup(&edge_port->port->port);
edge_port->write_in_progress = false;
send_more_port_data((struct edgeport_serial *)
(usb_get_serial_data(edge_port->port->serial)), edge_port);
}
static void edge_bulk_out_cmd_callback(struct urb *urb)
{
struct edgeport_port *edge_port = urb->context;
int status = urb->status;
atomic_dec(&CmdUrbs);
dev_dbg(&urb->dev->dev, "%s - FREE URB %p (outstanding %d)\n",
__func__, urb, atomic_read(&CmdUrbs));
kfree(urb->transfer_buffer);
usb_free_urb(urb);
if (status) {
dev_dbg(&urb->dev->dev,
"%s - nonzero write bulk status received: %d\n",
__func__, status);
return;
}
if (edge_port->open)
tty_port_tty_wakeup(&edge_port->port->port);
edge_port->commandPending = false;
wake_up(&edge_port->wait_command);
}
static int edge_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
struct device *dev = &port->dev;
struct usb_serial *serial;
struct edgeport_serial *edge_serial;
int response;
if (edge_port == NULL)
return -ENODEV;
serial = port->serial;
edge_serial = usb_get_serial_data(serial);
if (edge_serial == NULL)
return -ENODEV;
if (edge_serial->interrupt_in_buffer == NULL) {
struct usb_serial_port *port0 = serial->port[0];
edge_serial->interrupt_in_buffer =
port0->interrupt_in_buffer;
edge_serial->interrupt_in_endpoint =
port0->interrupt_in_endpointAddress;
edge_serial->interrupt_read_urb = port0->interrupt_in_urb;
edge_serial->bulk_in_buffer = port0->bulk_in_buffer;
edge_serial->bulk_in_endpoint =
port0->bulk_in_endpointAddress;
edge_serial->read_urb = port0->read_urb;
edge_serial->bulk_out_endpoint =
port0->bulk_out_endpointAddress;
usb_fill_int_urb(edge_serial->interrupt_read_urb,
serial->dev,
usb_rcvintpipe(serial->dev,
port0->interrupt_in_endpointAddress),
port0->interrupt_in_buffer,
edge_serial->interrupt_read_urb->transfer_buffer_length,
edge_interrupt_callback, edge_serial,
edge_serial->interrupt_read_urb->interval);
usb_fill_bulk_urb(edge_serial->read_urb, serial->dev,
usb_rcvbulkpipe(serial->dev,
port0->bulk_in_endpointAddress),
port0->bulk_in_buffer,
edge_serial->read_urb->transfer_buffer_length,
edge_bulk_in_callback, edge_serial);
edge_serial->read_in_progress = false;
response = usb_submit_urb(edge_serial->interrupt_read_urb,
GFP_KERNEL);
if (response) {
dev_err(dev, "%s - Error %d submitting control urb\n",
__func__, response);
}
}
init_waitqueue_head(&edge_port->wait_open);
init_waitqueue_head(&edge_port->wait_chase);
init_waitqueue_head(&edge_port->wait_command);
edge_port->txCredits = 0;
edge_port->shadowMCR = MCR_MASTER_IE;
edge_port->chaseResponsePending = false;
edge_port->openPending = true;
edge_port->open = false;
response = send_iosp_ext_cmd(edge_port, IOSP_CMD_OPEN_PORT, 0);
if (response < 0) {
dev_err(dev, "%s - error sending open port command\n", __func__);
edge_port->openPending = false;
return -ENODEV;
}
wait_event_timeout(edge_port->wait_open, !edge_port->openPending,
OPEN_TIMEOUT);
if (!edge_port->open) {
dev_dbg(dev, "%s - open timedout\n", __func__);
edge_port->openPending = false;
return -ENODEV;
}
edge_port->txfifo.head = 0;
edge_port->txfifo.tail = 0;
edge_port->txfifo.count = 0;
edge_port->txfifo.size = edge_port->maxTxCredits;
edge_port->txfifo.fifo = kmalloc(edge_port->maxTxCredits, GFP_KERNEL);
if (!edge_port->txfifo.fifo) {
edge_close(port);
return -ENOMEM;
}
edge_port->write_urb = usb_alloc_urb(0, GFP_KERNEL);
edge_port->write_in_progress = false;
if (!edge_port->write_urb) {
edge_close(port);
return -ENOMEM;
}
dev_dbg(dev, "%s - Initialize TX fifo to %d bytes\n",
__func__, edge_port->maxTxCredits);
return 0;
}
static void block_until_chase_response(struct edgeport_port *edge_port)
{
struct device *dev = &edge_port->port->dev;
DEFINE_WAIT(wait);
__u16 lastCredits;
int timeout = 1*HZ;
int loop = 10;
while (1) {
lastCredits = edge_port->txCredits;
if (!edge_port->chaseResponsePending) {
dev_dbg(dev, "%s - Got Chase Response\n", __func__);
if (edge_port->txCredits == edge_port->maxTxCredits) {
dev_dbg(dev, "%s - Got all credits\n", __func__);
return;
}
}
prepare_to_wait(&edge_port->wait_chase, &wait,
TASK_UNINTERRUPTIBLE);
schedule_timeout(timeout);
finish_wait(&edge_port->wait_chase, &wait);
if (lastCredits == edge_port->txCredits) {
loop--;
if (loop == 0) {
edge_port->chaseResponsePending = false;
dev_dbg(dev, "%s - Chase TIMEOUT\n", __func__);
return;
}
} else {
dev_dbg(dev, "%s - Last %d, Current %d\n", __func__,
lastCredits, edge_port->txCredits);
loop = 10;
}
}
}
static void block_until_tx_empty(struct edgeport_port *edge_port)
{
struct device *dev = &edge_port->port->dev;
DEFINE_WAIT(wait);
struct TxFifo *fifo = &edge_port->txfifo;
__u32 lastCount;
int timeout = HZ/10;
int loop = 30;
while (1) {
lastCount = fifo->count;
if (lastCount == 0) {
dev_dbg(dev, "%s - TX Buffer Empty\n", __func__);
return;
}
prepare_to_wait(&edge_port->wait_chase, &wait,
TASK_UNINTERRUPTIBLE);
schedule_timeout(timeout);
finish_wait(&edge_port->wait_chase, &wait);
dev_dbg(dev, "%s wait\n", __func__);
if (lastCount == fifo->count) {
loop--;
if (loop == 0) {
dev_dbg(dev, "%s - TIMEOUT\n", __func__);
return;
}
} else {
loop = 30;
}
}
}
static void edge_close(struct usb_serial_port *port)
{
struct edgeport_serial *edge_serial;
struct edgeport_port *edge_port;
int status;
edge_serial = usb_get_serial_data(port->serial);
edge_port = usb_get_serial_port_data(port);
if (edge_serial == NULL || edge_port == NULL)
return;
block_until_tx_empty(edge_port);
edge_port->closePending = true;
if (!edge_serial->is_epic ||
edge_serial->epic_descriptor.Supports.IOSPChase) {
edge_port->chaseResponsePending = true;
dev_dbg(&port->dev, "%s - Sending IOSP_CMD_CHASE_PORT\n", __func__);
status = send_iosp_ext_cmd(edge_port, IOSP_CMD_CHASE_PORT, 0);
if (status == 0)
block_until_chase_response(edge_port);
else
edge_port->chaseResponsePending = false;
}
if (!edge_serial->is_epic ||
edge_serial->epic_descriptor.Supports.IOSPClose) {
dev_dbg(&port->dev, "%s - Sending IOSP_CMD_CLOSE_PORT\n", __func__);
send_iosp_ext_cmd(edge_port, IOSP_CMD_CLOSE_PORT, 0);
}
edge_port->closePending = false;
edge_port->open = false;
edge_port->openPending = false;
usb_kill_urb(edge_port->write_urb);
if (edge_port->write_urb) {
kfree(edge_port->write_urb->transfer_buffer);
usb_free_urb(edge_port->write_urb);
edge_port->write_urb = NULL;
}
kfree(edge_port->txfifo.fifo);
edge_port->txfifo.fifo = NULL;
}
static int edge_write(struct tty_struct *tty, struct usb_serial_port *port,
const unsigned char *data, int count)
{
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
struct TxFifo *fifo;
int copySize;
int bytesleft;
int firsthalf;
int secondhalf;
unsigned long flags;
if (edge_port == NULL)
return -ENODEV;
fifo = &edge_port->txfifo;
spin_lock_irqsave(&edge_port->ep_lock, flags);
copySize = min((unsigned int)count,
(edge_port->txCredits - fifo->count));
dev_dbg(&port->dev, "%s of %d byte(s) Fifo room %d -- will copy %d bytes\n",
__func__, count, edge_port->txCredits - fifo->count, copySize);
if (copySize == 0) {
dev_dbg(&port->dev, "%s - copySize = Zero\n", __func__);
goto finish_write;
}
bytesleft = fifo->size - fifo->head;
firsthalf = min(bytesleft, copySize);
dev_dbg(&port->dev, "%s - copy %d bytes of %d into fifo \n", __func__,
firsthalf, bytesleft);
memcpy(&fifo->fifo[fifo->head], data, firsthalf);
usb_serial_debug_data(&port->dev, __func__, firsthalf, &fifo->fifo[fifo->head]);
fifo->head += firsthalf;
fifo->count += firsthalf;
if (fifo->head == fifo->size)
fifo->head = 0;
secondhalf = copySize-firsthalf;
if (secondhalf) {
dev_dbg(&port->dev, "%s - copy rest of data %d\n", __func__, secondhalf);
memcpy(&fifo->fifo[fifo->head], &data[firsthalf], secondhalf);
usb_serial_debug_data(&port->dev, __func__, secondhalf, &fifo->fifo[fifo->head]);
fifo->count += secondhalf;
fifo->head += secondhalf;
}
finish_write:
spin_unlock_irqrestore(&edge_port->ep_lock, flags);
send_more_port_data((struct edgeport_serial *)
usb_get_serial_data(port->serial), edge_port);
dev_dbg(&port->dev, "%s wrote %d byte(s) TxCredits %d, Fifo %d\n",
__func__, copySize, edge_port->txCredits, fifo->count);
return copySize;
}
static void send_more_port_data(struct edgeport_serial *edge_serial,
struct edgeport_port *edge_port)
{
struct TxFifo *fifo = &edge_port->txfifo;
struct device *dev = &edge_port->port->dev;
struct urb *urb;
unsigned char *buffer;
int status;
int count;
int bytesleft;
int firsthalf;
int secondhalf;
unsigned long flags;
spin_lock_irqsave(&edge_port->ep_lock, flags);
if (edge_port->write_in_progress ||
!edge_port->open ||
(fifo->count == 0)) {
dev_dbg(dev, "%s EXIT - fifo %d, PendingWrite = %d\n",
__func__, fifo->count, edge_port->write_in_progress);
goto exit_send;
}
if (edge_port->txCredits < EDGE_FW_GET_TX_CREDITS_SEND_THRESHOLD(edge_port->maxTxCredits, EDGE_FW_BULK_MAX_PACKET_SIZE)) {
dev_dbg(dev, "%s Not enough credit - fifo %d TxCredit %d\n",
__func__, fifo->count, edge_port->txCredits);
goto exit_send;
}
edge_port->write_in_progress = true;
urb = edge_port->write_urb;
kfree(urb->transfer_buffer);
urb->transfer_buffer = NULL;
count = fifo->count;
buffer = kmalloc(count+2, GFP_ATOMIC);
if (!buffer) {
edge_port->write_in_progress = false;
goto exit_send;
}
buffer[0] = IOSP_BUILD_DATA_HDR1(edge_port->port->port_number, count);
buffer[1] = IOSP_BUILD_DATA_HDR2(edge_port->port->port_number, count);
bytesleft = fifo->size - fifo->tail;
firsthalf = min(bytesleft, count);
memcpy(&buffer[2], &fifo->fifo[fifo->tail], firsthalf);
fifo->tail += firsthalf;
fifo->count -= firsthalf;
if (fifo->tail == fifo->size)
fifo->tail = 0;
secondhalf = count-firsthalf;
if (secondhalf) {
memcpy(&buffer[2+firsthalf], &fifo->fifo[fifo->tail],
secondhalf);
fifo->tail += secondhalf;
fifo->count -= secondhalf;
}
if (count)
usb_serial_debug_data(&edge_port->port->dev, __func__, count, &buffer[2]);
usb_fill_bulk_urb(urb, edge_serial->serial->dev,
usb_sndbulkpipe(edge_serial->serial->dev,
edge_serial->bulk_out_endpoint),
buffer, count+2,
edge_bulk_out_data_callback, edge_port);
edge_port->txCredits -= count;
edge_port->port->icount.tx += count;
status = usb_submit_urb(urb, GFP_ATOMIC);
if (status) {
dev_err_console(edge_port->port,
"%s - usb_submit_urb(write bulk) failed, status = %d, data lost\n",
__func__, status);
edge_port->write_in_progress = false;
edge_port->txCredits += count;
edge_port->port->icount.tx -= count;
}
dev_dbg(dev, "%s wrote %d byte(s) TxCredit %d, Fifo %d\n",
__func__, count, edge_port->txCredits, fifo->count);
exit_send:
spin_unlock_irqrestore(&edge_port->ep_lock, flags);
}
static int edge_write_room(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
int room;
unsigned long flags;
if (edge_port == NULL)
return 0;
if (edge_port->closePending)
return 0;
if (!edge_port->open) {
dev_dbg(&port->dev, "%s - port not opened\n", __func__);
return 0;
}
spin_lock_irqsave(&edge_port->ep_lock, flags);
room = edge_port->txCredits - edge_port->txfifo.count;
spin_unlock_irqrestore(&edge_port->ep_lock, flags);
dev_dbg(&port->dev, "%s - returns %d\n", __func__, room);
return room;
}
static int edge_chars_in_buffer(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
int num_chars;
unsigned long flags;
if (edge_port == NULL)
return 0;
if (edge_port->closePending)
return 0;
if (!edge_port->open) {
dev_dbg(&port->dev, "%s - port not opened\n", __func__);
return 0;
}
spin_lock_irqsave(&edge_port->ep_lock, flags);
num_chars = edge_port->maxTxCredits - edge_port->txCredits +
edge_port->txfifo.count;
spin_unlock_irqrestore(&edge_port->ep_lock, flags);
if (num_chars) {
dev_dbg(&port->dev, "%s - returns %d\n", __func__, num_chars);
}
return num_chars;
}
static void edge_throttle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
int status;
if (edge_port == NULL)
return;
if (!edge_port->open) {
dev_dbg(&port->dev, "%s - port not opened\n", __func__);
return;
}
if (I_IXOFF(tty)) {
unsigned char stop_char = STOP_CHAR(tty);
status = edge_write(tty, port, &stop_char, 1);
if (status <= 0)
return;
}
if (C_CRTSCTS(tty)) {
edge_port->shadowMCR &= ~MCR_RTS;
status = send_cmd_write_uart_register(edge_port, MCR,
edge_port->shadowMCR);
if (status != 0)
return;
}
}
static void edge_unthrottle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
int status;
if (edge_port == NULL)
return;
if (!edge_port->open) {
dev_dbg(&port->dev, "%s - port not opened\n", __func__);
return;
}
if (I_IXOFF(tty)) {
unsigned char start_char = START_CHAR(tty);
status = edge_write(tty, port, &start_char, 1);
if (status <= 0)
return;
}
if (C_CRTSCTS(tty)) {
edge_port->shadowMCR |= MCR_RTS;
send_cmd_write_uart_register(edge_port, MCR,
edge_port->shadowMCR);
}
}
static void edge_set_termios(struct tty_struct *tty,
struct usb_serial_port *port, struct ktermios *old_termios)
{
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
unsigned int cflag;
cflag = tty->termios.c_cflag;
dev_dbg(&port->dev, "%s - clfag %08x iflag %08x\n", __func__, tty->termios.c_cflag, tty->termios.c_iflag);
dev_dbg(&port->dev, "%s - old clfag %08x old iflag %08x\n", __func__, old_termios->c_cflag, old_termios->c_iflag);
if (edge_port == NULL)
return;
if (!edge_port->open) {
dev_dbg(&port->dev, "%s - port not opened\n", __func__);
return;
}
change_port_settings(tty, edge_port, old_termios);
}
static int get_lsr_info(struct edgeport_port *edge_port,
unsigned int __user *value)
{
unsigned int result = 0;
unsigned long flags;
spin_lock_irqsave(&edge_port->ep_lock, flags);
if (edge_port->maxTxCredits == edge_port->txCredits &&
edge_port->txfifo.count == 0) {
dev_dbg(&edge_port->port->dev, "%s -- Empty\n", __func__);
result = TIOCSER_TEMT;
}
spin_unlock_irqrestore(&edge_port->ep_lock, flags);
if (copy_to_user(value, &result, sizeof(int)))
return -EFAULT;
return 0;
}
static int edge_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct usb_serial_port *port = tty->driver_data;
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
unsigned int mcr;
mcr = edge_port->shadowMCR;
if (set & TIOCM_RTS)
mcr |= MCR_RTS;
if (set & TIOCM_DTR)
mcr |= MCR_DTR;
if (set & TIOCM_LOOP)
mcr |= MCR_LOOPBACK;
if (clear & TIOCM_RTS)
mcr &= ~MCR_RTS;
if (clear & TIOCM_DTR)
mcr &= ~MCR_DTR;
if (clear & TIOCM_LOOP)
mcr &= ~MCR_LOOPBACK;
edge_port->shadowMCR = mcr;
send_cmd_write_uart_register(edge_port, MCR, edge_port->shadowMCR);
return 0;
}
static int edge_tiocmget(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
unsigned int result = 0;
unsigned int msr;
unsigned int mcr;
msr = edge_port->shadowMSR;
mcr = edge_port->shadowMCR;
result = ((mcr & MCR_DTR) ? TIOCM_DTR: 0)
| ((mcr & MCR_RTS) ? TIOCM_RTS: 0)
| ((msr & EDGEPORT_MSR_CTS) ? TIOCM_CTS: 0)
| ((msr & EDGEPORT_MSR_CD) ? TIOCM_CAR: 0)
| ((msr & EDGEPORT_MSR_RI) ? TIOCM_RI: 0)
| ((msr & EDGEPORT_MSR_DSR) ? TIOCM_DSR: 0);
return result;
}
static int get_serial_info(struct edgeport_port *edge_port,
struct serial_struct __user *retinfo)
{
struct serial_struct tmp;
memset(&tmp, 0, sizeof(tmp));
tmp.type = PORT_16550A;
tmp.line = edge_port->port->minor;
tmp.port = edge_port->port->port_number;
tmp.irq = 0;
tmp.flags = ASYNC_SKIP_TEST | ASYNC_AUTO_IRQ;
tmp.xmit_fifo_size = edge_port->maxTxCredits;
tmp.baud_base = 9600;
tmp.close_delay = 5*HZ;
tmp.closing_wait = 30*HZ;
if (copy_to_user(retinfo, &tmp, sizeof(*retinfo)))
return -EFAULT;
return 0;
}
static int edge_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct usb_serial_port *port = tty->driver_data;
DEFINE_WAIT(wait);
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
switch (cmd) {
case TIOCSERGETLSR:
dev_dbg(&port->dev, "%s TIOCSERGETLSR\n", __func__);
return get_lsr_info(edge_port, (unsigned int __user *) arg);
case TIOCGSERIAL:
dev_dbg(&port->dev, "%s TIOCGSERIAL\n", __func__);
return get_serial_info(edge_port, (struct serial_struct __user *) arg);
}
return -ENOIOCTLCMD;
}
static void edge_break(struct tty_struct *tty, int break_state)
{
struct usb_serial_port *port = tty->driver_data;
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
struct edgeport_serial *edge_serial = usb_get_serial_data(port->serial);
int status;
if (!edge_serial->is_epic ||
edge_serial->epic_descriptor.Supports.IOSPChase) {
edge_port->chaseResponsePending = true;
dev_dbg(&port->dev, "%s - Sending IOSP_CMD_CHASE_PORT\n", __func__);
status = send_iosp_ext_cmd(edge_port, IOSP_CMD_CHASE_PORT, 0);
if (status == 0) {
block_until_chase_response(edge_port);
} else {
edge_port->chaseResponsePending = false;
}
}
if (!edge_serial->is_epic ||
edge_serial->epic_descriptor.Supports.IOSPSetClrBreak) {
if (break_state == -1) {
dev_dbg(&port->dev, "%s - Sending IOSP_CMD_SET_BREAK\n", __func__);
status = send_iosp_ext_cmd(edge_port,
IOSP_CMD_SET_BREAK, 0);
} else {
dev_dbg(&port->dev, "%s - Sending IOSP_CMD_CLEAR_BREAK\n", __func__);
status = send_iosp_ext_cmd(edge_port,
IOSP_CMD_CLEAR_BREAK, 0);
}
if (status)
dev_dbg(&port->dev, "%s - error sending break set/clear command.\n",
__func__);
}
}
static void process_rcvd_data(struct edgeport_serial *edge_serial,
unsigned char *buffer, __u16 bufferLength)
{
struct device *dev = &edge_serial->serial->dev->dev;
struct usb_serial_port *port;
struct edgeport_port *edge_port;
__u16 lastBufferLength;
__u16 rxLen;
lastBufferLength = bufferLength + 1;
while (bufferLength > 0) {
if (lastBufferLength == bufferLength) {
dev_dbg(dev, "%s - stuck in loop, exiting it.\n", __func__);
break;
}
lastBufferLength = bufferLength;
switch (edge_serial->rxState) {
case EXPECT_HDR1:
edge_serial->rxHeader1 = *buffer;
++buffer;
--bufferLength;
if (bufferLength == 0) {
edge_serial->rxState = EXPECT_HDR2;
break;
}
case EXPECT_HDR2:
edge_serial->rxHeader2 = *buffer;
++buffer;
--bufferLength;
dev_dbg(dev, "%s - Hdr1=%02X Hdr2=%02X\n", __func__,
edge_serial->rxHeader1, edge_serial->rxHeader2);
if (IS_CMD_STAT_HDR(edge_serial->rxHeader1)) {
edge_serial->rxPort =
IOSP_GET_HDR_PORT(edge_serial->rxHeader1);
edge_serial->rxStatusCode =
IOSP_GET_STATUS_CODE(
edge_serial->rxHeader1);
if (!IOSP_STATUS_IS_2BYTE(
edge_serial->rxStatusCode)) {
edge_serial->rxStatusParam
= edge_serial->rxHeader2;
edge_serial->rxState = EXPECT_HDR3;
break;
}
process_rcvd_status(edge_serial,
edge_serial->rxHeader2, 0);
edge_serial->rxState = EXPECT_HDR1;
break;
} else {
edge_serial->rxPort =
IOSP_GET_HDR_PORT(edge_serial->rxHeader1);
edge_serial->rxBytesRemaining =
IOSP_GET_HDR_DATA_LEN(
edge_serial->rxHeader1,
edge_serial->rxHeader2);
dev_dbg(dev, "%s - Data for Port %u Len %u\n",
__func__,
edge_serial->rxPort,
edge_serial->rxBytesRemaining);
if (bufferLength == 0) {
edge_serial->rxState = EXPECT_DATA;
break;
}
}
case EXPECT_DATA:
if (bufferLength < edge_serial->rxBytesRemaining) {
rxLen = bufferLength;
edge_serial->rxState = EXPECT_DATA;
} else {
rxLen = edge_serial->rxBytesRemaining;
edge_serial->rxState = EXPECT_HDR1;
}
bufferLength -= rxLen;
edge_serial->rxBytesRemaining -= rxLen;
if (rxLen) {
port = edge_serial->serial->port[
edge_serial->rxPort];
edge_port = usb_get_serial_port_data(port);
if (edge_port->open) {
dev_dbg(dev, "%s - Sending %d bytes to TTY for port %d\n",
__func__, rxLen,
edge_serial->rxPort);
edge_tty_recv(edge_port->port, buffer,
rxLen);
edge_port->port->icount.rx += rxLen;
}
buffer += rxLen;
}
break;
case EXPECT_HDR3:
edge_serial->rxHeader3 = *buffer;
++buffer;
--bufferLength;
process_rcvd_status(edge_serial,
edge_serial->rxStatusParam,
edge_serial->rxHeader3);
edge_serial->rxState = EXPECT_HDR1;
break;
}
}
}
static void process_rcvd_status(struct edgeport_serial *edge_serial,
__u8 byte2, __u8 byte3)
{
struct usb_serial_port *port;
struct edgeport_port *edge_port;
struct tty_struct *tty;
struct device *dev;
__u8 code = edge_serial->rxStatusCode;
port = edge_serial->serial->port[edge_serial->rxPort];
edge_port = usb_get_serial_port_data(port);
if (edge_port == NULL) {
dev_err(&edge_serial->serial->dev->dev,
"%s - edge_port == NULL for port %d\n",
__func__, edge_serial->rxPort);
return;
}
dev = &port->dev;
if (code == IOSP_EXT_STATUS) {
switch (byte2) {
case IOSP_EXT_STATUS_CHASE_RSP:
dev_dbg(dev, "%s - Port %u EXT CHASE_RSP Data = %02x\n",
__func__, edge_serial->rxPort, byte3);
edge_port->chaseResponsePending = false;
wake_up(&edge_port->wait_chase);
return;
case IOSP_EXT_STATUS_RX_CHECK_RSP:
dev_dbg(dev, "%s ========== Port %u CHECK_RSP Sequence = %02x =============\n",
__func__, edge_serial->rxPort, byte3);
return;
}
}
if (code == IOSP_STATUS_OPEN_RSP) {
edge_port->txCredits = GET_TX_BUFFER_SIZE(byte3);
edge_port->maxTxCredits = edge_port->txCredits;
dev_dbg(dev, "%s - Port %u Open Response Initial MSR = %02x TxBufferSize = %d\n",
__func__, edge_serial->rxPort, byte2, edge_port->txCredits);
handle_new_msr(edge_port, byte2);
tty = tty_port_tty_get(&edge_port->port->port);
if (tty) {
change_port_settings(tty,
edge_port, &tty->termios);
tty_kref_put(tty);
}
edge_port->openPending = false;
edge_port->open = true;
wake_up(&edge_port->wait_open);
return;
}
if (!edge_port->open || edge_port->closePending)
return;
switch (code) {
case IOSP_STATUS_LSR:
dev_dbg(dev, "%s - Port %u LSR Status = %02x\n",
__func__, edge_serial->rxPort, byte2);
handle_new_lsr(edge_port, false, byte2, 0);
break;
case IOSP_STATUS_LSR_DATA:
dev_dbg(dev, "%s - Port %u LSR Status = %02x, Data = %02x\n",
__func__, edge_serial->rxPort, byte2, byte3);
handle_new_lsr(edge_port, true, byte2, byte3);
break;
case IOSP_STATUS_MSR:
dev_dbg(dev, "%s - Port %u MSR Status = %02x\n",
__func__, edge_serial->rxPort, byte2);
handle_new_msr(edge_port, byte2);
break;
default:
dev_dbg(dev, "%s - Unrecognized IOSP status code %u\n", __func__, code);
break;
}
}
static void edge_tty_recv(struct usb_serial_port *port, unsigned char *data,
int length)
{
int cnt;
cnt = tty_insert_flip_string(&port->port, data, length);
if (cnt < length) {
dev_err(&port->dev, "%s - dropping data, %d bytes lost\n",
__func__, length - cnt);
}
data += cnt;
length -= cnt;
tty_flip_buffer_push(&port->port);
}
static void handle_new_msr(struct edgeport_port *edge_port, __u8 newMsr)
{
struct async_icount *icount;
if (newMsr & (EDGEPORT_MSR_DELTA_CTS | EDGEPORT_MSR_DELTA_DSR |
EDGEPORT_MSR_DELTA_RI | EDGEPORT_MSR_DELTA_CD)) {
icount = &edge_port->port->icount;
if (newMsr & EDGEPORT_MSR_DELTA_CTS)
icount->cts++;
if (newMsr & EDGEPORT_MSR_DELTA_DSR)
icount->dsr++;
if (newMsr & EDGEPORT_MSR_DELTA_CD)
icount->dcd++;
if (newMsr & EDGEPORT_MSR_DELTA_RI)
icount->rng++;
wake_up_interruptible(&edge_port->port->port.delta_msr_wait);
}
edge_port->shadowMSR = newMsr & 0xf0;
}
static void handle_new_lsr(struct edgeport_port *edge_port, __u8 lsrData,
__u8 lsr, __u8 data)
{
__u8 newLsr = (__u8) (lsr & (__u8)
(LSR_OVER_ERR | LSR_PAR_ERR | LSR_FRM_ERR | LSR_BREAK));
struct async_icount *icount;
edge_port->shadowLSR = lsr;
if (newLsr & LSR_BREAK) {
newLsr &= (__u8)(LSR_OVER_ERR | LSR_BREAK);
}
if (lsrData)
edge_tty_recv(edge_port->port, &data, 1);
icount = &edge_port->port->icount;
if (newLsr & LSR_BREAK)
icount->brk++;
if (newLsr & LSR_OVER_ERR)
icount->overrun++;
if (newLsr & LSR_PAR_ERR)
icount->parity++;
if (newLsr & LSR_FRM_ERR)
icount->frame++;
}
static int sram_write(struct usb_serial *serial, __u16 extAddr, __u16 addr,
__u16 length, const __u8 *data)
{
int result;
__u16 current_length;
unsigned char *transfer_buffer;
dev_dbg(&serial->dev->dev, "%s - %x, %x, %d\n", __func__, extAddr, addr, length);
transfer_buffer = kmalloc(64, GFP_KERNEL);
if (!transfer_buffer)
return -ENOMEM;
result = 0;
while (length > 0) {
if (length > 64)
current_length = 64;
else
current_length = length;
memcpy(transfer_buffer, data, current_length);
result = usb_control_msg(serial->dev,
usb_sndctrlpipe(serial->dev, 0),
USB_REQUEST_ION_WRITE_RAM,
0x40, addr, extAddr, transfer_buffer,
current_length, 300);
if (result < 0)
break;
length -= current_length;
addr += current_length;
data += current_length;
}
kfree(transfer_buffer);
return result;
}
static int rom_write(struct usb_serial *serial, __u16 extAddr, __u16 addr,
__u16 length, const __u8 *data)
{
int result;
__u16 current_length;
unsigned char *transfer_buffer;
transfer_buffer = kmalloc(64, GFP_KERNEL);
if (!transfer_buffer)
return -ENOMEM;
result = 0;
while (length > 0) {
if (length > 64)
current_length = 64;
else
current_length = length;
memcpy(transfer_buffer, data, current_length);
result = usb_control_msg(serial->dev,
usb_sndctrlpipe(serial->dev, 0),
USB_REQUEST_ION_WRITE_ROM, 0x40,
addr, extAddr,
transfer_buffer, current_length, 300);
if (result < 0)
break;
length -= current_length;
addr += current_length;
data += current_length;
}
kfree(transfer_buffer);
return result;
}
static int rom_read(struct usb_serial *serial, __u16 extAddr,
__u16 addr, __u16 length, __u8 *data)
{
int result;
__u16 current_length;
unsigned char *transfer_buffer;
transfer_buffer = kmalloc(64, GFP_KERNEL);
if (!transfer_buffer)
return -ENOMEM;
result = 0;
while (length > 0) {
if (length > 64)
current_length = 64;
else
current_length = length;
result = usb_control_msg(serial->dev,
usb_rcvctrlpipe(serial->dev, 0),
USB_REQUEST_ION_READ_ROM,
0xC0, addr, extAddr, transfer_buffer,
current_length, 300);
if (result < 0)
break;
memcpy(data, transfer_buffer, current_length);
length -= current_length;
addr += current_length;
data += current_length;
}
kfree(transfer_buffer);
return result;
}
static int send_iosp_ext_cmd(struct edgeport_port *edge_port,
__u8 command, __u8 param)
{
unsigned char *buffer;
unsigned char *currentCommand;
int length = 0;
int status = 0;
buffer = kmalloc(10, GFP_ATOMIC);
if (!buffer)
return -ENOMEM;
currentCommand = buffer;
MAKE_CMD_EXT_CMD(&currentCommand, &length, edge_port->port->port_number,
command, param);
status = write_cmd_usb(edge_port, buffer, length);
if (status) {
kfree(buffer);
}
return status;
}
static int write_cmd_usb(struct edgeport_port *edge_port,
unsigned char *buffer, int length)
{
struct edgeport_serial *edge_serial =
usb_get_serial_data(edge_port->port->serial);
struct device *dev = &edge_port->port->dev;
int status = 0;
struct urb *urb;
usb_serial_debug_data(dev, __func__, length, buffer);
urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!urb)
return -ENOMEM;
atomic_inc(&CmdUrbs);
dev_dbg(dev, "%s - ALLOCATE URB %p (outstanding %d)\n",
__func__, urb, atomic_read(&CmdUrbs));
usb_fill_bulk_urb(urb, edge_serial->serial->dev,
usb_sndbulkpipe(edge_serial->serial->dev,
edge_serial->bulk_out_endpoint),
buffer, length, edge_bulk_out_cmd_callback, edge_port);
edge_port->commandPending = true;
status = usb_submit_urb(urb, GFP_ATOMIC);
if (status) {
dev_err(dev, "%s - usb_submit_urb(write command) failed, status = %d\n",
__func__, status);
usb_kill_urb(urb);
usb_free_urb(urb);
atomic_dec(&CmdUrbs);
return status;
}
#if 0
wait_event(&edge_port->wait_command, !edge_port->commandPending);
if (edge_port->commandPending) {
dev_dbg(dev, "%s - command timed out\n", __func__);
status = -EINVAL;
}
#endif
return status;
}
static int send_cmd_write_baud_rate(struct edgeport_port *edge_port,
int baudRate)
{
struct edgeport_serial *edge_serial =
usb_get_serial_data(edge_port->port->serial);
struct device *dev = &edge_port->port->dev;
unsigned char *cmdBuffer;
unsigned char *currCmd;
int cmdLen = 0;
int divisor;
int status;
u32 number = edge_port->port->port_number;
if (edge_serial->is_epic &&
!edge_serial->epic_descriptor.Supports.IOSPSetBaudRate) {
dev_dbg(dev, "SendCmdWriteBaudRate - NOT Setting baud rate for port, baud = %d\n",
baudRate);
return 0;
}
dev_dbg(dev, "%s - baud = %d\n", __func__, baudRate);
status = calc_baud_rate_divisor(dev, baudRate, &divisor);
if (status) {
dev_err(dev, "%s - bad baud rate\n", __func__);
return status;
}
cmdBuffer = kmalloc(0x100, GFP_ATOMIC);
if (!cmdBuffer)
return -ENOMEM;
currCmd = cmdBuffer;
MAKE_CMD_WRITE_REG(&currCmd, &cmdLen, number, LCR, LCR_DL_ENABLE);
MAKE_CMD_WRITE_REG(&currCmd, &cmdLen, number, DLL, LOW8(divisor));
MAKE_CMD_WRITE_REG(&currCmd, &cmdLen, number, DLM, HIGH8(divisor));
MAKE_CMD_WRITE_REG(&currCmd, &cmdLen, number, LCR,
edge_port->shadowLCR);
status = write_cmd_usb(edge_port, cmdBuffer, cmdLen);
if (status) {
kfree(cmdBuffer);
}
return status;
}
static int calc_baud_rate_divisor(struct device *dev, int baudrate, int *divisor)
{
int i;
__u16 custom;
for (i = 0; i < ARRAY_SIZE(divisor_table); i++) {
if (divisor_table[i].BaudRate == baudrate) {
*divisor = divisor_table[i].Divisor;
return 0;
}
}
if (baudrate > 50 && baudrate < 230400) {
custom = (__u16)((230400L + baudrate/2) / baudrate);
*divisor = custom;
dev_dbg(dev, "%s - Baud %d = %d\n", __func__, baudrate, custom);
return 0;
}
return -1;
}
static int send_cmd_write_uart_register(struct edgeport_port *edge_port,
__u8 regNum, __u8 regValue)
{
struct edgeport_serial *edge_serial =
usb_get_serial_data(edge_port->port->serial);
struct device *dev = &edge_port->port->dev;
unsigned char *cmdBuffer;
unsigned char *currCmd;
unsigned long cmdLen = 0;
int status;
dev_dbg(dev, "%s - write to %s register 0x%02x\n",
(regNum == MCR) ? "MCR" : "LCR", __func__, regValue);
if (edge_serial->is_epic &&
!edge_serial->epic_descriptor.Supports.IOSPWriteMCR &&
regNum == MCR) {
dev_dbg(dev, "SendCmdWriteUartReg - Not writing to MCR Register\n");
return 0;
}
if (edge_serial->is_epic &&
!edge_serial->epic_descriptor.Supports.IOSPWriteLCR &&
regNum == LCR) {
dev_dbg(dev, "SendCmdWriteUartReg - Not writing to LCR Register\n");
return 0;
}
cmdBuffer = kmalloc(0x10, GFP_ATOMIC);
if (cmdBuffer == NULL)
return -ENOMEM;
currCmd = cmdBuffer;
MAKE_CMD_WRITE_REG(&currCmd, &cmdLen, edge_port->port->port_number,
regNum, regValue);
status = write_cmd_usb(edge_port, cmdBuffer, cmdLen);
if (status) {
kfree(cmdBuffer);
}
return status;
}
static void change_port_settings(struct tty_struct *tty,
struct edgeport_port *edge_port, struct ktermios *old_termios)
{
struct device *dev = &edge_port->port->dev;
struct edgeport_serial *edge_serial =
usb_get_serial_data(edge_port->port->serial);
int baud;
unsigned cflag;
__u8 mask = 0xff;
__u8 lData;
__u8 lParity;
__u8 lStop;
__u8 rxFlow;
__u8 txFlow;
int status;
if (!edge_port->open &&
!edge_port->openPending) {
dev_dbg(dev, "%s - port not opened\n", __func__);
return;
}
cflag = tty->termios.c_cflag;
switch (cflag & CSIZE) {
case CS5:
lData = LCR_BITS_5; mask = 0x1f;
dev_dbg(dev, "%s - data bits = 5\n", __func__);
break;
case CS6:
lData = LCR_BITS_6; mask = 0x3f;
dev_dbg(dev, "%s - data bits = 6\n", __func__);
break;
case CS7:
lData = LCR_BITS_7; mask = 0x7f;
dev_dbg(dev, "%s - data bits = 7\n", __func__);
break;
default:
case CS8:
lData = LCR_BITS_8;
dev_dbg(dev, "%s - data bits = 8\n", __func__);
break;
}
lParity = LCR_PAR_NONE;
if (cflag & PARENB) {
if (cflag & CMSPAR) {
if (cflag & PARODD) {
lParity = LCR_PAR_MARK;
dev_dbg(dev, "%s - parity = mark\n", __func__);
} else {
lParity = LCR_PAR_SPACE;
dev_dbg(dev, "%s - parity = space\n", __func__);
}
} else if (cflag & PARODD) {
lParity = LCR_PAR_ODD;
dev_dbg(dev, "%s - parity = odd\n", __func__);
} else {
lParity = LCR_PAR_EVEN;
dev_dbg(dev, "%s - parity = even\n", __func__);
}
} else {
dev_dbg(dev, "%s - parity = none\n", __func__);
}
if (cflag & CSTOPB) {
lStop = LCR_STOP_2;
dev_dbg(dev, "%s - stop bits = 2\n", __func__);
} else {
lStop = LCR_STOP_1;
dev_dbg(dev, "%s - stop bits = 1\n", __func__);
}
rxFlow = txFlow = 0x00;
if (cflag & CRTSCTS) {
rxFlow |= IOSP_RX_FLOW_RTS;
txFlow |= IOSP_TX_FLOW_CTS;
dev_dbg(dev, "%s - RTS/CTS is enabled\n", __func__);
} else {
dev_dbg(dev, "%s - RTS/CTS is disabled\n", __func__);
}
if (I_IXOFF(tty) || I_IXON(tty)) {
unsigned char stop_char = STOP_CHAR(tty);
unsigned char start_char = START_CHAR(tty);
if (!edge_serial->is_epic ||
edge_serial->epic_descriptor.Supports.IOSPSetXChar) {
send_iosp_ext_cmd(edge_port,
IOSP_CMD_SET_XON_CHAR, start_char);
send_iosp_ext_cmd(edge_port,
IOSP_CMD_SET_XOFF_CHAR, stop_char);
}
if (I_IXOFF(tty)) {
rxFlow |= IOSP_RX_FLOW_XON_XOFF;
dev_dbg(dev, "%s - INBOUND XON/XOFF is enabled, XON = %2x, XOFF = %2x\n",
__func__, start_char, stop_char);
} else {
dev_dbg(dev, "%s - INBOUND XON/XOFF is disabled\n", __func__);
}
if (I_IXON(tty)) {
txFlow |= IOSP_TX_FLOW_XON_XOFF;
dev_dbg(dev, "%s - OUTBOUND XON/XOFF is enabled, XON = %2x, XOFF = %2x\n",
__func__, start_char, stop_char);
} else {
dev_dbg(dev, "%s - OUTBOUND XON/XOFF is disabled\n", __func__);
}
}
if (!edge_serial->is_epic ||
edge_serial->epic_descriptor.Supports.IOSPSetRxFlow)
send_iosp_ext_cmd(edge_port, IOSP_CMD_SET_RX_FLOW, rxFlow);
if (!edge_serial->is_epic ||
edge_serial->epic_descriptor.Supports.IOSPSetTxFlow)
send_iosp_ext_cmd(edge_port, IOSP_CMD_SET_TX_FLOW, txFlow);
edge_port->shadowLCR &= ~(LCR_BITS_MASK | LCR_STOP_MASK | LCR_PAR_MASK);
edge_port->shadowLCR |= (lData | lParity | lStop);
edge_port->validDataMask = mask;
status = send_cmd_write_uart_register(edge_port, LCR,
edge_port->shadowLCR);
if (status != 0)
return;
edge_port->shadowMCR = MCR_MASTER_IE;
if (cflag & CBAUD)
edge_port->shadowMCR |= (MCR_DTR | MCR_RTS);
status = send_cmd_write_uart_register(edge_port, MCR,
edge_port->shadowMCR);
if (status != 0)
return;
baud = tty_get_baud_rate(tty);
if (!baud) {
baud = 9600;
}
dev_dbg(dev, "%s - baud rate = %d\n", __func__, baud);
status = send_cmd_write_baud_rate(edge_port, baud);
if (status == -1) {
baud = tty_termios_baud_rate(old_termios);
tty_encode_baud_rate(tty, baud, baud);
}
}
static void unicode_to_ascii(char *string, int buflen,
__le16 *unicode, int unicode_size)
{
int i;
if (buflen <= 0)
return;
--buflen;
for (i = 0; i < unicode_size; i++) {
if (i >= buflen)
break;
string[i] = (char)(le16_to_cpu(unicode[i]));
}
string[i] = 0x00;
}
static void get_manufacturing_desc(struct edgeport_serial *edge_serial)
{
struct device *dev = &edge_serial->serial->dev->dev;
int response;
dev_dbg(dev, "getting manufacturer descriptor\n");
response = rom_read(edge_serial->serial,
(EDGE_MANUF_DESC_ADDR & 0xffff0000) >> 16,
(__u16)(EDGE_MANUF_DESC_ADDR & 0x0000ffff),
EDGE_MANUF_DESC_LEN,
(__u8 *)(&edge_serial->manuf_descriptor));
if (response < 1)
dev_err(dev, "error in getting manufacturer descriptor\n");
else {
char string[30];
dev_dbg(dev, "**Manufacturer Descriptor\n");
dev_dbg(dev, " RomSize: %dK\n",
edge_serial->manuf_descriptor.RomSize);
dev_dbg(dev, " RamSize: %dK\n",
edge_serial->manuf_descriptor.RamSize);
dev_dbg(dev, " CpuRev: %d\n",
edge_serial->manuf_descriptor.CpuRev);
dev_dbg(dev, " BoardRev: %d\n",
edge_serial->manuf_descriptor.BoardRev);
dev_dbg(dev, " NumPorts: %d\n",
edge_serial->manuf_descriptor.NumPorts);
dev_dbg(dev, " DescDate: %d/%d/%d\n",
edge_serial->manuf_descriptor.DescDate[0],
edge_serial->manuf_descriptor.DescDate[1],
edge_serial->manuf_descriptor.DescDate[2]+1900);
unicode_to_ascii(string, sizeof(string),
edge_serial->manuf_descriptor.SerialNumber,
edge_serial->manuf_descriptor.SerNumLength/2);
dev_dbg(dev, " SerialNumber: %s\n", string);
unicode_to_ascii(string, sizeof(string),
edge_serial->manuf_descriptor.AssemblyNumber,
edge_serial->manuf_descriptor.AssemblyNumLength/2);
dev_dbg(dev, " AssemblyNumber: %s\n", string);
unicode_to_ascii(string, sizeof(string),
edge_serial->manuf_descriptor.OemAssyNumber,
edge_serial->manuf_descriptor.OemAssyNumLength/2);
dev_dbg(dev, " OemAssyNumber: %s\n", string);
dev_dbg(dev, " UartType: %d\n",
edge_serial->manuf_descriptor.UartType);
dev_dbg(dev, " IonPid: %d\n",
edge_serial->manuf_descriptor.IonPid);
dev_dbg(dev, " IonConfig: %d\n",
edge_serial->manuf_descriptor.IonConfig);
}
}
static void get_boot_desc(struct edgeport_serial *edge_serial)
{
struct device *dev = &edge_serial->serial->dev->dev;
int response;
dev_dbg(dev, "getting boot descriptor\n");
response = rom_read(edge_serial->serial,
(EDGE_BOOT_DESC_ADDR & 0xffff0000) >> 16,
(__u16)(EDGE_BOOT_DESC_ADDR & 0x0000ffff),
EDGE_BOOT_DESC_LEN,
(__u8 *)(&edge_serial->boot_descriptor));
if (response < 1)
dev_err(dev, "error in getting boot descriptor\n");
else {
dev_dbg(dev, "**Boot Descriptor:\n");
dev_dbg(dev, " BootCodeLength: %d\n",
le16_to_cpu(edge_serial->boot_descriptor.BootCodeLength));
dev_dbg(dev, " MajorVersion: %d\n",
edge_serial->boot_descriptor.MajorVersion);
dev_dbg(dev, " MinorVersion: %d\n",
edge_serial->boot_descriptor.MinorVersion);
dev_dbg(dev, " BuildNumber: %d\n",
le16_to_cpu(edge_serial->boot_descriptor.BuildNumber));
dev_dbg(dev, " Capabilities: 0x%x\n",
le16_to_cpu(edge_serial->boot_descriptor.Capabilities));
dev_dbg(dev, " UConfig0: %d\n",
edge_serial->boot_descriptor.UConfig0);
dev_dbg(dev, " UConfig1: %d\n",
edge_serial->boot_descriptor.UConfig1);
}
}
static void load_application_firmware(struct edgeport_serial *edge_serial)
{
struct device *dev = &edge_serial->serial->dev->dev;
const struct ihex_binrec *rec;
const struct firmware *fw;
const char *fw_name;
const char *fw_info;
int response;
__u32 Operaddr;
__u16 build;
switch (edge_serial->product_info.iDownloadFile) {
case EDGE_DOWNLOAD_FILE_I930:
fw_info = "downloading firmware version (930)";
fw_name = "edgeport/down.fw";
break;
case EDGE_DOWNLOAD_FILE_80251:
fw_info = "downloading firmware version (80251)";
fw_name = "edgeport/down2.fw";
break;
case EDGE_DOWNLOAD_FILE_NONE:
dev_dbg(dev, "No download file specified, skipping download\n");
return;
default:
return;
}
response = request_ihex_firmware(&fw, fw_name,
&edge_serial->serial->dev->dev);
if (response) {
dev_err(dev, "Failed to load image \"%s\" err %d\n",
fw_name, response);
return;
}
rec = (const struct ihex_binrec *)fw->data;
build = (rec->data[2] << 8) | rec->data[3];
dev_dbg(dev, "%s %d.%d.%d\n", fw_info, rec->data[0], rec->data[1], build);
edge_serial->product_info.FirmwareMajorVersion = rec->data[0];
edge_serial->product_info.FirmwareMinorVersion = rec->data[1];
edge_serial->product_info.FirmwareBuildNumber = cpu_to_le16(build);
for (rec = ihex_next_binrec(rec); rec;
rec = ihex_next_binrec(rec)) {
Operaddr = be32_to_cpu(rec->addr);
response = sram_write(edge_serial->serial,
Operaddr >> 16,
Operaddr & 0xFFFF,
be16_to_cpu(rec->len),
&rec->data[0]);
if (response < 0) {
dev_err(&edge_serial->serial->dev->dev,
"sram_write failed (%x, %x, %d)\n",
Operaddr >> 16, Operaddr & 0xFFFF,
be16_to_cpu(rec->len));
break;
}
}
dev_dbg(dev, "sending exec_dl_code\n");
response = usb_control_msg (edge_serial->serial->dev,
usb_sndctrlpipe(edge_serial->serial->dev, 0),
USB_REQUEST_ION_EXEC_DL_CODE,
0x40, 0x4000, 0x0001, NULL, 0, 3000);
release_firmware(fw);
}
static int edge_startup(struct usb_serial *serial)
{
struct edgeport_serial *edge_serial;
struct usb_device *dev;
struct device *ddev = &serial->dev->dev;
int i;
int response;
bool interrupt_in_found;
bool bulk_in_found;
bool bulk_out_found;
static __u32 descriptor[3] = { EDGE_COMPATIBILITY_MASK0,
EDGE_COMPATIBILITY_MASK1,
EDGE_COMPATIBILITY_MASK2 };
if (serial->num_bulk_in < 1 || serial->num_interrupt_in < 1) {
dev_err(&serial->interface->dev, "missing endpoints\n");
return -ENODEV;
}
dev = serial->dev;
edge_serial = kzalloc(sizeof(struct edgeport_serial), GFP_KERNEL);
if (!edge_serial)
return -ENOMEM;
spin_lock_init(&edge_serial->es_lock);
edge_serial->serial = serial;
usb_set_serial_data(serial, edge_serial);
i = usb_string(dev, dev->descriptor.iManufacturer,
&edge_serial->name[0], MAX_NAME_LEN+1);
if (i < 0)
i = 0;
edge_serial->name[i++] = ' ';
usb_string(dev, dev->descriptor.iProduct,
&edge_serial->name[i], MAX_NAME_LEN+2 - i);
dev_info(&serial->dev->dev, "%s detected\n", edge_serial->name);
if (get_epic_descriptor(edge_serial) <= 0) {
memcpy(&edge_serial->epic_descriptor.Supports, descriptor,
sizeof(struct edge_compatibility_bits));
get_manufacturing_desc(edge_serial);
get_boot_desc(edge_serial);
get_product_info(edge_serial);
}
if ((!edge_serial->is_epic) &&
(edge_serial->product_info.NumPorts != serial->num_ports)) {
dev_warn(ddev,
"Device Reported %d serial ports vs. core thinking we have %d ports, email greg@kroah.com this information.\n",
edge_serial->product_info.NumPorts,
serial->num_ports);
}
dev_dbg(ddev, "%s - time 1 %ld\n", __func__, jiffies);
if (!edge_serial->is_epic) {
load_application_firmware(edge_serial);
dev_dbg(ddev, "%s - time 2 %ld\n", __func__, jiffies);
update_edgeport_E2PROM(edge_serial);
dev_dbg(ddev, "%s - time 3 %ld\n", __func__, jiffies);
}
dev_dbg(ddev, " FirmwareMajorVersion %d.%d.%d\n",
edge_serial->product_info.FirmwareMajorVersion,
edge_serial->product_info.FirmwareMinorVersion,
le16_to_cpu(edge_serial->product_info.FirmwareBuildNumber));
response = 0;
if (edge_serial->is_epic) {
interrupt_in_found = bulk_in_found = bulk_out_found = false;
for (i = 0; i < serial->interface->altsetting[0]
.desc.bNumEndpoints; ++i) {
struct usb_endpoint_descriptor *endpoint;
int buffer_size;
endpoint = &serial->interface->altsetting[0].
endpoint[i].desc;
buffer_size = usb_endpoint_maxp(endpoint);
if (!interrupt_in_found &&
(usb_endpoint_is_int_in(endpoint))) {
dev_dbg(ddev, "found interrupt in\n");
edge_serial->interrupt_read_urb =
usb_alloc_urb(0, GFP_KERNEL);
if (!edge_serial->interrupt_read_urb) {
response = -ENOMEM;
break;
}
edge_serial->interrupt_in_buffer =
kmalloc(buffer_size, GFP_KERNEL);
if (!edge_serial->interrupt_in_buffer) {
response = -ENOMEM;
break;
}
edge_serial->interrupt_in_endpoint =
endpoint->bEndpointAddress;
usb_fill_int_urb(
edge_serial->interrupt_read_urb,
dev,
usb_rcvintpipe(dev,
endpoint->bEndpointAddress),
edge_serial->interrupt_in_buffer,
buffer_size,
edge_interrupt_callback,
edge_serial,
endpoint->bInterval);
interrupt_in_found = true;
}
if (!bulk_in_found &&
(usb_endpoint_is_bulk_in(endpoint))) {
dev_dbg(ddev, "found bulk in\n");
edge_serial->read_urb =
usb_alloc_urb(0, GFP_KERNEL);
if (!edge_serial->read_urb) {
response = -ENOMEM;
break;
}
edge_serial->bulk_in_buffer =
kmalloc(buffer_size, GFP_KERNEL);
if (!edge_serial->bulk_in_buffer) {
response = -ENOMEM;
break;
}
edge_serial->bulk_in_endpoint =
endpoint->bEndpointAddress;
usb_fill_bulk_urb(edge_serial->read_urb, dev,
usb_rcvbulkpipe(dev,
endpoint->bEndpointAddress),
edge_serial->bulk_in_buffer,
usb_endpoint_maxp(endpoint),
edge_bulk_in_callback,
edge_serial);
bulk_in_found = true;
}
if (!bulk_out_found &&
(usb_endpoint_is_bulk_out(endpoint))) {
dev_dbg(ddev, "found bulk out\n");
edge_serial->bulk_out_endpoint =
endpoint->bEndpointAddress;
bulk_out_found = true;
}
}
if (response || !interrupt_in_found || !bulk_in_found ||
!bulk_out_found) {
if (!response) {
dev_err(ddev, "expected endpoints not found\n");
response = -ENODEV;
}
usb_free_urb(edge_serial->interrupt_read_urb);
kfree(edge_serial->interrupt_in_buffer);
usb_free_urb(edge_serial->read_urb);
kfree(edge_serial->bulk_in_buffer);
kfree(edge_serial);
return response;
}
response = usb_submit_urb(edge_serial->interrupt_read_urb,
GFP_KERNEL);
if (response)
dev_err(ddev, "%s - Error %d submitting control urb\n",
__func__, response);
}
return response;
}
static void edge_disconnect(struct usb_serial *serial)
{
struct edgeport_serial *edge_serial = usb_get_serial_data(serial);
if (edge_serial->is_epic) {
usb_kill_urb(edge_serial->interrupt_read_urb);
usb_kill_urb(edge_serial->read_urb);
}
}
static void edge_release(struct usb_serial *serial)
{
struct edgeport_serial *edge_serial = usb_get_serial_data(serial);
if (edge_serial->is_epic) {
usb_kill_urb(edge_serial->interrupt_read_urb);
usb_free_urb(edge_serial->interrupt_read_urb);
kfree(edge_serial->interrupt_in_buffer);
usb_kill_urb(edge_serial->read_urb);
usb_free_urb(edge_serial->read_urb);
kfree(edge_serial->bulk_in_buffer);
}
kfree(edge_serial);
}
static int edge_port_probe(struct usb_serial_port *port)
{
struct edgeport_port *edge_port;
edge_port = kzalloc(sizeof(*edge_port), GFP_KERNEL);
if (!edge_port)
return -ENOMEM;
spin_lock_init(&edge_port->ep_lock);
edge_port->port = port;
usb_set_serial_port_data(port, edge_port);
return 0;
}
static int edge_port_remove(struct usb_serial_port *port)
{
struct edgeport_port *edge_port;
edge_port = usb_get_serial_port_data(port);
kfree(edge_port);
return 0;
}
