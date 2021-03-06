static int ti_vread_sync(struct usb_device *dev, __u8 request,
__u16 value, __u16 index, u8 *data, int size)
{
int status;
status = usb_control_msg(dev, usb_rcvctrlpipe(dev, 0), request,
(USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN),
value, index, data, size, 1000);
if (status < 0)
return status;
if (status != size) {
dbg("%s - wanted to write %d, but only wrote %d",
__func__, size, status);
return -ECOMM;
}
return 0;
}
static int ti_vsend_sync(struct usb_device *dev, __u8 request,
__u16 value, __u16 index, u8 *data, int size)
{
int status;
status = usb_control_msg(dev, usb_sndctrlpipe(dev, 0), request,
(USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_OUT),
value, index, data, size, 1000);
if (status < 0)
return status;
if (status != size) {
dbg("%s - wanted to write %d, but only wrote %d",
__func__, size, status);
return -ECOMM;
}
return 0;
}
static int send_cmd(struct usb_device *dev, __u8 command,
__u8 moduleid, __u16 value, u8 *data,
int size)
{
return ti_vsend_sync(dev, command, value, moduleid, data, size);
}
static int purge_port(struct usb_serial_port *port, __u16 mask)
{
int port_number = port->number - port->serial->minor;
dbg("%s - port %d, mask %x", __func__, port_number, mask);
return send_cmd(port->serial->dev,
UMPC_PURGE_PORT,
(__u8)(UMPM_UART1_PORT + port_number),
mask,
NULL,
0);
}
static int read_download_mem(struct usb_device *dev, int start_address,
int length, __u8 address_type, __u8 *buffer)
{
int status = 0;
__u8 read_length;
__be16 be_start_address;
dbg("%s - @ %x for %d", __func__, start_address, length);
while (length) {
if (length > 64)
read_length = 64;
else
read_length = (__u8)length;
if (read_length > 1) {
dbg("%s - @ %x for %d", __func__,
start_address, read_length);
}
be_start_address = cpu_to_be16(start_address);
status = ti_vread_sync(dev, UMPC_MEMORY_READ,
(__u16)address_type,
(__force __u16)be_start_address,
buffer, read_length);
if (status) {
dbg("%s - ERROR %x", __func__, status);
return status;
}
if (read_length > 1)
usb_serial_debug_data(debug, &dev->dev, __func__,
read_length, buffer);
start_address += read_length;
buffer += read_length;
length -= read_length;
}
return status;
}
static int read_ram(struct usb_device *dev, int start_address,
int length, __u8 *buffer)
{
return read_download_mem(dev, start_address, length,
DTK_ADDR_SPACE_XDATA, buffer);
}
static int read_boot_mem(struct edgeport_serial *serial,
int start_address, int length, __u8 *buffer)
{
int status = 0;
int i;
for (i = 0; i < length; i++) {
status = ti_vread_sync(serial->serial->dev,
UMPC_MEMORY_READ, serial->TI_I2C_Type,
(__u16)(start_address+i), &buffer[i], 0x01);
if (status) {
dbg("%s - ERROR %x", __func__, status);
return status;
}
}
dbg("%s - start_address = %x, length = %d",
__func__, start_address, length);
usb_serial_debug_data(debug, &serial->serial->dev->dev,
__func__, length, buffer);
serial->TiReadI2C = 1;
return status;
}
static int write_boot_mem(struct edgeport_serial *serial,
int start_address, int length, __u8 *buffer)
{
int status = 0;
int i;
u8 *temp;
if (!serial->TiReadI2C) {
temp = kmalloc(1, GFP_KERNEL);
if (!temp) {
dev_err(&serial->serial->dev->dev,
"%s - out of memory\n", __func__);
return -ENOMEM;
}
status = read_boot_mem(serial, 0, 1, temp);
kfree(temp);
if (status)
return status;
}
for (i = 0; i < length; ++i) {
status = ti_vsend_sync(serial->serial->dev,
UMPC_MEMORY_WRITE, buffer[i],
(__u16)(i + start_address), NULL, 0);
if (status)
return status;
}
dbg("%s - start_sddr = %x, length = %d",
__func__, start_address, length);
usb_serial_debug_data(debug, &serial->serial->dev->dev,
__func__, length, buffer);
return status;
}
static int write_i2c_mem(struct edgeport_serial *serial,
int start_address, int length, __u8 address_type, __u8 *buffer)
{
int status = 0;
int write_length;
__be16 be_start_address;
write_length = EPROM_PAGE_SIZE -
(start_address & (EPROM_PAGE_SIZE - 1));
if (write_length > length)
write_length = length;
dbg("%s - BytesInFirstPage Addr = %x, length = %d",
__func__, start_address, write_length);
usb_serial_debug_data(debug, &serial->serial->dev->dev,
__func__, write_length, buffer);
be_start_address = cpu_to_be16(start_address);
status = ti_vsend_sync(serial->serial->dev,
UMPC_MEMORY_WRITE, (__u16)address_type,
(__force __u16)be_start_address,
buffer, write_length);
if (status) {
dbg("%s - ERROR %d", __func__, status);
return status;
}
length -= write_length;
start_address += write_length;
buffer += write_length;
while (length) {
if (length > EPROM_PAGE_SIZE)
write_length = EPROM_PAGE_SIZE;
else
write_length = length;
dbg("%s - Page Write Addr = %x, length = %d",
__func__, start_address, write_length);
usb_serial_debug_data(debug, &serial->serial->dev->dev,
__func__, write_length, buffer);
be_start_address = cpu_to_be16(start_address);
status = ti_vsend_sync(serial->serial->dev, UMPC_MEMORY_WRITE,
(__u16)address_type,
(__force __u16)be_start_address,
buffer, write_length);
if (status) {
dev_err(&serial->serial->dev->dev, "%s - ERROR %d\n",
__func__, status);
return status;
}
length -= write_length;
start_address += write_length;
buffer += write_length;
}
return status;
}
static int tx_active(struct edgeport_port *port)
{
int status;
struct out_endpoint_desc_block *oedb;
__u8 *lsr;
int bytes_left = 0;
oedb = kmalloc(sizeof(*oedb), GFP_KERNEL);
if (!oedb) {
dev_err(&port->port->dev, "%s - out of memory\n", __func__);
return -ENOMEM;
}
lsr = kmalloc(1, GFP_KERNEL);
if (!lsr) {
kfree(oedb);
return -ENOMEM;
}
status = read_ram(port->port->serial->dev, port->dma_address,
sizeof(*oedb), (void *)oedb);
if (status)
goto exit_is_tx_active;
dbg("%s - XByteCount 0x%X", __func__, oedb->XByteCount);
status = read_ram(port->port->serial->dev,
port->uart_base + UMPMEM_OFFS_UART_LSR, 1, lsr);
if (status)
goto exit_is_tx_active;
dbg("%s - LSR = 0x%X", __func__, *lsr);
if ((oedb->XByteCount & 0x80) != 0)
bytes_left += 64;
if ((*lsr & UMP_UART_LSR_TX_MASK) == 0)
bytes_left += 1;
exit_is_tx_active:
dbg("%s - return %d", __func__, bytes_left);
kfree(lsr);
kfree(oedb);
return bytes_left;
}
static void chase_port(struct edgeport_port *port, unsigned long timeout,
int flush)
{
int baud_rate;
struct tty_struct *tty = tty_port_tty_get(&port->port->port);
wait_queue_t wait;
unsigned long flags;
if (!timeout)
timeout = (HZ * EDGE_CLOSING_WAIT)/100;
spin_lock_irqsave(&port->ep_lock, flags);
init_waitqueue_entry(&wait, current);
add_wait_queue(&tty->write_wait, &wait);
for (;;) {
set_current_state(TASK_INTERRUPTIBLE);
if (kfifo_len(&port->write_fifo) == 0
|| timeout == 0 || signal_pending(current)
|| !usb_get_intfdata(port->port->serial->interface))
break;
spin_unlock_irqrestore(&port->ep_lock, flags);
timeout = schedule_timeout(timeout);
spin_lock_irqsave(&port->ep_lock, flags);
}
set_current_state(TASK_RUNNING);
remove_wait_queue(&tty->write_wait, &wait);
if (flush)
kfifo_reset_out(&port->write_fifo);
spin_unlock_irqrestore(&port->ep_lock, flags);
tty_kref_put(tty);
timeout += jiffies;
while ((long)(jiffies - timeout) < 0 && !signal_pending(current)
&& usb_get_intfdata(port->port->serial->interface)) {
if (!tx_active(port))
break;
msleep(10);
}
if (!usb_get_intfdata(port->port->serial->interface))
return;
baud_rate = port->baud_rate;
if (baud_rate == 0)
baud_rate = 50;
msleep(max(1, DIV_ROUND_UP(10000, baud_rate)));
}
static int choose_config(struct usb_device *dev)
{
dbg("%s - Number of Interfaces = %d",
__func__, dev->config->desc.bNumInterfaces);
dbg("%s - MAX Power = %d",
__func__, dev->config->desc.bMaxPower * 2);
if (dev->config->desc.bNumInterfaces != 1) {
dev_err(&dev->dev, "%s - bNumInterfaces is not 1, ERROR!\n",
__func__);
return -ENODEV;
}
return 0;
}
static int read_rom(struct edgeport_serial *serial,
int start_address, int length, __u8 *buffer)
{
int status;
if (serial->product_info.TiMode == TI_MODE_DOWNLOAD) {
status = read_download_mem(serial->serial->dev,
start_address,
length,
serial->TI_I2C_Type,
buffer);
} else {
status = read_boot_mem(serial, start_address, length,
buffer);
}
return status;
}
static int write_rom(struct edgeport_serial *serial, int start_address,
int length, __u8 *buffer)
{
if (serial->product_info.TiMode == TI_MODE_BOOT)
return write_boot_mem(serial, start_address, length,
buffer);
if (serial->product_info.TiMode == TI_MODE_DOWNLOAD)
return write_i2c_mem(serial, start_address, length,
serial->TI_I2C_Type, buffer);
return -EINVAL;
}
static int get_descriptor_addr(struct edgeport_serial *serial,
int desc_type, struct ti_i2c_desc *rom_desc)
{
int start_address;
int status;
start_address = 2;
do {
status = read_rom(serial,
start_address,
sizeof(struct ti_i2c_desc),
(__u8 *)rom_desc);
if (status)
return 0;
if (rom_desc->Type == desc_type)
return start_address;
start_address = start_address + sizeof(struct ti_i2c_desc)
+ rom_desc->Size;
} while ((start_address < TI_MAX_I2C_SIZE) && rom_desc->Type);
return 0;
}
static int valid_csum(struct ti_i2c_desc *rom_desc, __u8 *buffer)
{
__u16 i;
__u8 cs = 0;
for (i = 0; i < rom_desc->Size; i++)
cs = (__u8)(cs + buffer[i]);
if (cs != rom_desc->CheckSum) {
dbg("%s - Mismatch %x - %x", __func__, rom_desc->CheckSum, cs);
return -EINVAL;
}
return 0;
}
static int check_i2c_image(struct edgeport_serial *serial)
{
struct device *dev = &serial->serial->dev->dev;
int status = 0;
struct ti_i2c_desc *rom_desc;
int start_address = 2;
__u8 *buffer;
__u16 ttype;
rom_desc = kmalloc(sizeof(*rom_desc), GFP_KERNEL);
if (!rom_desc) {
dev_err(dev, "%s - out of memory\n", __func__);
return -ENOMEM;
}
buffer = kmalloc(TI_MAX_I2C_SIZE, GFP_KERNEL);
if (!buffer) {
dev_err(dev, "%s - out of memory when allocating buffer\n",
__func__);
kfree(rom_desc);
return -ENOMEM;
}
status = read_rom(serial, 0, 1, buffer);
if (status)
goto out;
if (*buffer != UMP5152 && *buffer != UMP3410) {
dev_err(dev, "%s - invalid buffer signature\n", __func__);
status = -ENODEV;
goto out;
}
do {
status = read_rom(serial,
start_address,
sizeof(struct ti_i2c_desc),
(__u8 *)rom_desc);
if (status)
break;
if ((start_address + sizeof(struct ti_i2c_desc) +
rom_desc->Size) > TI_MAX_I2C_SIZE) {
status = -ENODEV;
dbg("%s - structure too big, erroring out.", __func__);
break;
}
dbg("%s Type = 0x%x", __func__, rom_desc->Type);
ttype = rom_desc->Type & 0x0f;
if (ttype != I2C_DESC_TYPE_FIRMWARE_BASIC
&& ttype != I2C_DESC_TYPE_FIRMWARE_AUTO) {
status = read_rom(serial, start_address +
sizeof(struct ti_i2c_desc),
rom_desc->Size, buffer);
if (status)
break;
status = valid_csum(rom_desc, buffer);
if (status)
break;
}
start_address = start_address + sizeof(struct ti_i2c_desc) +
rom_desc->Size;
} while ((rom_desc->Type != I2C_DESC_TYPE_ION) &&
(start_address < TI_MAX_I2C_SIZE));
if ((rom_desc->Type != I2C_DESC_TYPE_ION) ||
(start_address > TI_MAX_I2C_SIZE))
status = -ENODEV;
out:
kfree(buffer);
kfree(rom_desc);
return status;
}
static int get_manuf_info(struct edgeport_serial *serial, __u8 *buffer)
{
int status;
int start_address;
struct ti_i2c_desc *rom_desc;
struct edge_ti_manuf_descriptor *desc;
rom_desc = kmalloc(sizeof(*rom_desc), GFP_KERNEL);
if (!rom_desc) {
dev_err(&serial->serial->dev->dev, "%s - out of memory\n",
__func__);
return -ENOMEM;
}
start_address = get_descriptor_addr(serial, I2C_DESC_TYPE_ION,
rom_desc);
if (!start_address) {
dbg("%s - Edge Descriptor not found in I2C", __func__);
status = -ENODEV;
goto exit;
}
status = read_rom(serial, start_address+sizeof(struct ti_i2c_desc),
rom_desc->Size, buffer);
if (status)
goto exit;
status = valid_csum(rom_desc, buffer);
desc = (struct edge_ti_manuf_descriptor *)buffer;
dbg("%s - IonConfig 0x%x", __func__, desc->IonConfig);
dbg("%s - Version %d", __func__, desc->Version);
dbg("%s - Cpu/Board 0x%x", __func__, desc->CpuRev_BoardRev);
dbg("%s - NumPorts %d", __func__, desc->NumPorts);
dbg("%s - NumVirtualPorts %d", __func__, desc->NumVirtualPorts);
dbg("%s - TotalPorts %d", __func__, desc->TotalPorts);
exit:
kfree(rom_desc);
return status;
}
static int build_i2c_fw_hdr(__u8 *header, struct device *dev)
{
__u8 *buffer;
int buffer_size;
int i;
int err;
__u8 cs = 0;
struct ti_i2c_desc *i2c_header;
struct ti_i2c_image_header *img_header;
struct ti_i2c_firmware_rec *firmware_rec;
const struct firmware *fw;
const char *fw_name = "edgeport/down3.bin";
buffer_size = (((1024 * 16) - 512 ) +
sizeof(struct ti_i2c_firmware_rec));
buffer = kmalloc(buffer_size, GFP_KERNEL);
if (!buffer) {
dev_err(dev, "%s - out of memory\n", __func__);
return -ENOMEM;
}
memset(buffer, 0xff, buffer_size);
err = request_firmware(&fw, fw_name, dev);
if (err) {
printk(KERN_ERR "Failed to load image \"%s\" err %d\n",
fw_name, err);
kfree(buffer);
return err;
}
OperationalMajorVersion = fw->data[0];
OperationalMinorVersion = fw->data[1];
OperationalBuildNumber = fw->data[2] | (fw->data[3] << 8);
firmware_rec = (struct ti_i2c_firmware_rec *)buffer;
firmware_rec->Ver_Major = OperationalMajorVersion;
firmware_rec->Ver_Minor = OperationalMinorVersion;
img_header = (struct ti_i2c_image_header *)&fw->data[4];
memcpy(buffer + sizeof(struct ti_i2c_firmware_rec),
&fw->data[4 + sizeof(struct ti_i2c_image_header)],
le16_to_cpu(img_header->Length));
release_firmware(fw);
for (i=0; i < buffer_size; i++) {
cs = (__u8)(cs + buffer[i]);
}
kfree(buffer);
i2c_header = (struct ti_i2c_desc *)header;
firmware_rec = (struct ti_i2c_firmware_rec*)i2c_header->Data;
i2c_header->Type = I2C_DESC_TYPE_FIRMWARE_BLANK;
i2c_header->Size = (__u16)buffer_size;
i2c_header->CheckSum = cs;
firmware_rec->Ver_Major = OperationalMajorVersion;
firmware_rec->Ver_Minor = OperationalMinorVersion;
return 0;
}
static int i2c_type_bootmode(struct edgeport_serial *serial)
{
int status;
u8 *data;
data = kmalloc(1, GFP_KERNEL);
if (!data) {
dev_err(&serial->serial->dev->dev,
"%s - out of memory\n", __func__);
return -ENOMEM;
}
status = ti_vread_sync(serial->serial->dev, UMPC_MEMORY_READ,
DTK_ADDR_SPACE_I2C_TYPE_II, 0, data, 0x01);
if (status)
dbg("%s - read 2 status error = %d", __func__, status);
else
dbg("%s - read 2 data = 0x%x", __func__, *data);
if ((!status) && (*data == UMP5152 || *data == UMP3410)) {
dbg("%s - ROM_TYPE_II", __func__);
serial->TI_I2C_Type = DTK_ADDR_SPACE_I2C_TYPE_II;
goto out;
}
status = ti_vread_sync(serial->serial->dev, UMPC_MEMORY_READ,
DTK_ADDR_SPACE_I2C_TYPE_III, 0, data, 0x01);
if (status)
dbg("%s - read 3 status error = %d", __func__, status);
else
dbg("%s - read 2 data = 0x%x", __func__, *data);
if ((!status) && (*data == UMP5152 || *data == UMP3410)) {
dbg("%s - ROM_TYPE_III", __func__);
serial->TI_I2C_Type = DTK_ADDR_SPACE_I2C_TYPE_III;
goto out;
}
dbg("%s - Unknown", __func__);
serial->TI_I2C_Type = DTK_ADDR_SPACE_I2C_TYPE_II;
status = -ENODEV;
out:
kfree(data);
return status;
}
static int bulk_xfer(struct usb_serial *serial, void *buffer,
int length, int *num_sent)
{
int status;
status = usb_bulk_msg(serial->dev,
usb_sndbulkpipe(serial->dev,
serial->port[0]->bulk_out_endpointAddress),
buffer, length, num_sent, 1000);
return status;
}
static int download_code(struct edgeport_serial *serial, __u8 *image,
int image_length)
{
int status = 0;
int pos;
int transfer;
int done;
for (pos = 0; pos < image_length; ) {
transfer = image_length - pos;
if (transfer > EDGE_FW_BULK_MAX_PACKET_SIZE)
transfer = EDGE_FW_BULK_MAX_PACKET_SIZE;
status = bulk_xfer(serial->serial, &image[pos],
transfer, &done);
if (status)
break;
pos += done;
}
return status;
}
static int config_boot_dev(struct usb_device *dev)
{
return 0;
}
static int ti_cpu_rev(struct edge_ti_manuf_descriptor *desc)
{
return TI_GET_CPU_REVISION(desc->CpuRev_BoardRev);
}
static int download_fw(struct edgeport_serial *serial)
{
struct device *dev = &serial->serial->dev->dev;
int status = 0;
int start_address;
struct edge_ti_manuf_descriptor *ti_manuf_desc;
struct usb_interface_descriptor *interface;
int download_cur_ver;
int download_new_ver;
serial->product_info.hardware_type = HARDWARE_TYPE_TIUMP;
serial->TI_I2C_Type = DTK_ADDR_SPACE_I2C_TYPE_II;
status = choose_config(serial->serial->dev);
if (status)
return status;
interface = &serial->serial->interface->cur_altsetting->desc;
if (!interface) {
dev_err(dev, "%s - no interface set, error!\n", __func__);
return -ENODEV;
}
if (interface->bNumEndpoints > 1)
serial->product_info.TiMode = TI_MODE_DOWNLOAD;
else
serial->product_info.TiMode = TI_MODE_CONFIGURING;
if (serial->product_info.TiMode == TI_MODE_DOWNLOAD) {
struct ti_i2c_desc *rom_desc;
dbg("%s - RUNNING IN DOWNLOAD MODE", __func__);
status = check_i2c_image(serial);
if (status) {
dbg("%s - DOWNLOAD MODE -- BAD I2C", __func__);
return status;
}
ti_manuf_desc = kmalloc(sizeof(*ti_manuf_desc), GFP_KERNEL);
if (!ti_manuf_desc) {
dev_err(dev, "%s - out of memory.\n", __func__);
return -ENOMEM;
}
status = get_manuf_info(serial, (__u8 *)ti_manuf_desc);
if (status) {
kfree(ti_manuf_desc);
return status;
}
if (!ignore_cpu_rev && ti_cpu_rev(ti_manuf_desc) < 2) {
dbg("%s - Wrong CPU Rev %d (Must be 2)",
__func__, ti_cpu_rev(ti_manuf_desc));
kfree(ti_manuf_desc);
return -EINVAL;
}
rom_desc = kmalloc(sizeof(*rom_desc), GFP_KERNEL);
if (!rom_desc) {
dev_err(dev, "%s - out of memory.\n", __func__);
kfree(ti_manuf_desc);
return -ENOMEM;
}
start_address = get_descriptor_addr(serial,
I2C_DESC_TYPE_FIRMWARE_BASIC, rom_desc);
if (start_address != 0) {
struct ti_i2c_firmware_rec *firmware_version;
u8 *record;
dbg("%s - Found Type FIRMWARE (Type 2) record",
__func__);
firmware_version = kmalloc(sizeof(*firmware_version),
GFP_KERNEL);
if (!firmware_version) {
dev_err(dev, "%s - out of memory.\n", __func__);
kfree(rom_desc);
kfree(ti_manuf_desc);
return -ENOMEM;
}
status = read_rom(serial, start_address +
sizeof(struct ti_i2c_desc),
sizeof(struct ti_i2c_firmware_rec),
(__u8 *)firmware_version);
if (status) {
kfree(firmware_version);
kfree(rom_desc);
kfree(ti_manuf_desc);
return status;
}
download_cur_ver = (firmware_version->Ver_Major << 8) +
(firmware_version->Ver_Minor);
download_new_ver = (OperationalMajorVersion << 8) +
(OperationalMinorVersion);
dbg("%s - >> FW Versions Device %d.%d Driver %d.%d",
__func__,
firmware_version->Ver_Major,
firmware_version->Ver_Minor,
OperationalMajorVersion,
OperationalMinorVersion);
if (download_cur_ver < download_new_ver) {
dbg("%s - Update I2C dld from %d.%d to %d.%d",
__func__,
firmware_version->Ver_Major,
firmware_version->Ver_Minor,
OperationalMajorVersion,
OperationalMinorVersion);
record = kmalloc(1, GFP_KERNEL);
if (!record) {
dev_err(dev, "%s - out of memory.\n",
__func__);
kfree(firmware_version);
kfree(rom_desc);
kfree(ti_manuf_desc);
return -ENOMEM;
}
*record = I2C_DESC_TYPE_FIRMWARE_BLANK;
status = write_rom(serial, start_address,
sizeof(*record), record);
if (status) {
kfree(record);
kfree(firmware_version);
kfree(rom_desc);
kfree(ti_manuf_desc);
return status;
}
status = read_rom(serial,
start_address,
sizeof(*record),
record);
if (status) {
kfree(record);
kfree(firmware_version);
kfree(rom_desc);
kfree(ti_manuf_desc);
return status;
}
if (*record != I2C_DESC_TYPE_FIRMWARE_BLANK) {
dev_err(dev,
"%s - error resetting device\n",
__func__);
kfree(record);
kfree(firmware_version);
kfree(rom_desc);
kfree(ti_manuf_desc);
return -ENODEV;
}
dbg("%s - HARDWARE RESET", __func__);
status = ti_vsend_sync(serial->serial->dev,
UMPC_HARDWARE_RESET,
0, 0, NULL, 0);
dbg("%s - HARDWARE RESET return %d",
__func__, status);
kfree(record);
kfree(firmware_version);
kfree(rom_desc);
kfree(ti_manuf_desc);
return -ENODEV;
}
kfree(firmware_version);
}
else if ((start_address = get_descriptor_addr(serial, I2C_DESC_TYPE_FIRMWARE_BLANK, rom_desc)) != 0) {
#define HEADER_SIZE (sizeof(struct ti_i2c_desc) + \
sizeof(struct ti_i2c_firmware_rec))
__u8 *header;
__u8 *vheader;
header = kmalloc(HEADER_SIZE, GFP_KERNEL);
if (!header) {
dev_err(dev, "%s - out of memory.\n", __func__);
kfree(rom_desc);
kfree(ti_manuf_desc);
return -ENOMEM;
}
vheader = kmalloc(HEADER_SIZE, GFP_KERNEL);
if (!vheader) {
dev_err(dev, "%s - out of memory.\n", __func__);
kfree(header);
kfree(rom_desc);
kfree(ti_manuf_desc);
return -ENOMEM;
}
dbg("%s - Found Type BLANK FIRMWARE (Type F2) record",
__func__);
status = build_i2c_fw_hdr(header, dev);
if (status) {
kfree(vheader);
kfree(header);
kfree(rom_desc);
kfree(ti_manuf_desc);
return -EINVAL;
}
status = write_rom(serial,
start_address,
HEADER_SIZE,
header);
if (status) {
kfree(vheader);
kfree(header);
kfree(rom_desc);
kfree(ti_manuf_desc);
return -EINVAL;
}
status = read_rom(serial, start_address,
HEADER_SIZE, vheader);
if (status) {
dbg("%s - can't read header back", __func__);
kfree(vheader);
kfree(header);
kfree(rom_desc);
kfree(ti_manuf_desc);
return status;
}
if (memcmp(vheader, header, HEADER_SIZE)) {
dbg("%s - write download record failed",
__func__);
kfree(vheader);
kfree(header);
kfree(rom_desc);
kfree(ti_manuf_desc);
return -EINVAL;
}
kfree(vheader);
kfree(header);
dbg("%s - Start firmware update", __func__);
status = ti_vsend_sync(serial->serial->dev,
UMPC_COPY_DNLD_TO_I2C, 0, 0, NULL, 0);
dbg("%s - Update complete 0x%x", __func__, status);
if (status) {
dev_err(dev,
"%s - UMPC_COPY_DNLD_TO_I2C failed\n",
__func__);
kfree(rom_desc);
kfree(ti_manuf_desc);
return status;
}
}
kfree(rom_desc);
kfree(ti_manuf_desc);
return 0;
}
dbg("%s - RUNNING IN BOOT MODE", __func__);
status = config_boot_dev(serial->serial->dev);
if (status)
return status;
if (le16_to_cpu(serial->serial->dev->descriptor.idVendor)
!= USB_VENDOR_ID_ION) {
dbg("%s - VID = 0x%x", __func__,
le16_to_cpu(serial->serial->dev->descriptor.idVendor));
serial->TI_I2C_Type = DTK_ADDR_SPACE_I2C_TYPE_II;
goto stayinbootmode;
}
if (i2c_type_bootmode(serial))
goto stayinbootmode;
if (!check_i2c_image(serial)) {
struct ti_i2c_image_header *header;
int i;
__u8 cs = 0;
__u8 *buffer;
int buffer_size;
int err;
const struct firmware *fw;
const char *fw_name = "edgeport/down3.bin";
ti_manuf_desc = kmalloc(sizeof(*ti_manuf_desc), GFP_KERNEL);
if (!ti_manuf_desc) {
dev_err(dev, "%s - out of memory.\n", __func__);
return -ENOMEM;
}
status = get_manuf_info(serial, (__u8 *)ti_manuf_desc);
if (status) {
kfree(ti_manuf_desc);
goto stayinbootmode;
}
if (!ignore_cpu_rev && ti_cpu_rev(ti_manuf_desc) < 2) {
dbg("%s - Wrong CPU Rev %d (Must be 2)",
__func__, ti_cpu_rev(ti_manuf_desc));
kfree(ti_manuf_desc);
goto stayinbootmode;
}
kfree(ti_manuf_desc);
buffer_size = (((1024 * 16) - 512) +
sizeof(struct ti_i2c_image_header));
buffer = kmalloc(buffer_size, GFP_KERNEL);
if (!buffer) {
dev_err(dev, "%s - out of memory\n", __func__);
return -ENOMEM;
}
memset(buffer, 0xff, buffer_size);
err = request_firmware(&fw, fw_name, dev);
if (err) {
printk(KERN_ERR "Failed to load image \"%s\" err %d\n",
fw_name, err);
kfree(buffer);
return err;
}
memcpy(buffer, &fw->data[4], fw->size - 4);
release_firmware(fw);
for (i = sizeof(struct ti_i2c_image_header);
i < buffer_size; i++) {
cs = (__u8)(cs + buffer[i]);
}
header = (struct ti_i2c_image_header *)buffer;
header->Length = cpu_to_le16((__u16)(buffer_size -
sizeof(struct ti_i2c_image_header)));
header->CheckSum = cs;
dbg("%s - Downloading operational code image (TI UMP)",
__func__);
status = download_code(serial, buffer, buffer_size);
kfree(buffer);
if (status) {
dbg("%s - Error downloading operational code image",
__func__);
return status;
}
serial->product_info.TiMode = TI_MODE_TRANSITIONING;
dbg("%s - Download successful -- Device rebooting...",
__func__);
return -ENODEV;
}
stayinbootmode:
dbg("%s - STAYING IN BOOT MODE", __func__);
serial->product_info.TiMode = TI_MODE_BOOT;
return 0;
}
static int ti_do_config(struct edgeport_port *port, int feature, int on)
{
int port_number = port->port->number - port->port->serial->minor;
on = !!on;
return send_cmd(port->port->serial->dev,
feature, (__u8)(UMPM_UART1_PORT + port_number),
on, NULL, 0);
}
static int restore_mcr(struct edgeport_port *port, __u8 mcr)
{
int status = 0;
dbg("%s - %x", __func__, mcr);
status = ti_do_config(port, UMPC_SET_CLR_DTR, mcr & MCR_DTR);
if (status)
return status;
status = ti_do_config(port, UMPC_SET_CLR_RTS, mcr & MCR_RTS);
if (status)
return status;
return ti_do_config(port, UMPC_SET_CLR_LOOPBACK, mcr & MCR_LOOPBACK);
}
static __u8 map_line_status(__u8 ti_lsr)
{
__u8 lsr = 0;
#define MAP_FLAG(flagUmp, flagUart) \
if (ti_lsr & flagUmp) \
lsr |= flagUart;
MAP_FLAG(UMP_UART_LSR_OV_MASK, LSR_OVER_ERR)
MAP_FLAG(UMP_UART_LSR_PE_MASK, LSR_PAR_ERR)
MAP_FLAG(UMP_UART_LSR_FE_MASK, LSR_FRM_ERR)
MAP_FLAG(UMP_UART_LSR_BR_MASK, LSR_BREAK)
MAP_FLAG(UMP_UART_LSR_RX_MASK, LSR_RX_AVAIL)
MAP_FLAG(UMP_UART_LSR_TX_MASK, LSR_TX_EMPTY)
#undef MAP_FLAG
return lsr;
}
static void handle_new_msr(struct edgeport_port *edge_port, __u8 msr)
{
struct async_icount *icount;
struct tty_struct *tty;
dbg("%s - %02x", __func__, msr);
if (msr & (EDGEPORT_MSR_DELTA_CTS | EDGEPORT_MSR_DELTA_DSR |
EDGEPORT_MSR_DELTA_RI | EDGEPORT_MSR_DELTA_CD)) {
icount = &edge_port->icount;
if (msr & EDGEPORT_MSR_DELTA_CTS)
icount->cts++;
if (msr & EDGEPORT_MSR_DELTA_DSR)
icount->dsr++;
if (msr & EDGEPORT_MSR_DELTA_CD)
icount->dcd++;
if (msr & EDGEPORT_MSR_DELTA_RI)
icount->rng++;
wake_up_interruptible(&edge_port->delta_msr_wait);
}
edge_port->shadow_msr = msr & 0xf0;
tty = tty_port_tty_get(&edge_port->port->port);
if (tty && C_CRTSCTS(tty)) {
if (msr & EDGEPORT_MSR_CTS) {
tty->hw_stopped = 0;
tty_wakeup(tty);
} else {
tty->hw_stopped = 1;
}
}
tty_kref_put(tty);
}
static void handle_new_lsr(struct edgeport_port *edge_port, int lsr_data,
__u8 lsr, __u8 data)
{
struct async_icount *icount;
__u8 new_lsr = (__u8)(lsr & (__u8)(LSR_OVER_ERR | LSR_PAR_ERR |
LSR_FRM_ERR | LSR_BREAK));
struct tty_struct *tty;
dbg("%s - %02x", __func__, new_lsr);
edge_port->shadow_lsr = lsr;
if (new_lsr & LSR_BREAK)
new_lsr &= (__u8)(LSR_OVER_ERR | LSR_BREAK);
if (lsr_data) {
tty = tty_port_tty_get(&edge_port->port->port);
if (tty) {
edge_tty_recv(&edge_port->port->dev, tty, &data, 1);
tty_kref_put(tty);
}
}
icount = &edge_port->icount;
if (new_lsr & LSR_BREAK)
icount->brk++;
if (new_lsr & LSR_OVER_ERR)
icount->overrun++;
if (new_lsr & LSR_PAR_ERR)
icount->parity++;
if (new_lsr & LSR_FRM_ERR)
icount->frame++;
}
static void edge_interrupt_callback(struct urb *urb)
{
struct edgeport_serial *edge_serial = urb->context;
struct usb_serial_port *port;
struct edgeport_port *edge_port;
unsigned char *data = urb->transfer_buffer;
int length = urb->actual_length;
int port_number;
int function;
int retval;
__u8 lsr;
__u8 msr;
int status = urb->status;
dbg("%s", __func__);
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dbg("%s - urb shutting down with status: %d",
__func__, status);
return;
default:
dev_err(&urb->dev->dev, "%s - nonzero urb status received: "
"%d\n", __func__, status);
goto exit;
}
if (!length) {
dbg("%s - no data in urb", __func__);
goto exit;
}
usb_serial_debug_data(debug, &edge_serial->serial->dev->dev,
__func__, length, data);
if (length != 2) {
dbg("%s - expecting packet of size 2, got %d",
__func__, length);
goto exit;
}
port_number = TIUMP_GET_PORT_FROM_CODE(data[0]);
function = TIUMP_GET_FUNC_FROM_CODE(data[0]);
dbg("%s - port_number %d, function %d, info 0x%x",
__func__, port_number, function, data[1]);
port = edge_serial->serial->port[port_number];
edge_port = usb_get_serial_port_data(port);
if (!edge_port) {
dbg("%s - edge_port not found", __func__);
return;
}
switch (function) {
case TIUMP_INTERRUPT_CODE_LSR:
lsr = map_line_status(data[1]);
if (lsr & UMP_UART_LSR_DATA_MASK) {
dbg("%s - LSR Event Port %u LSR Status = %02x",
__func__, port_number, lsr);
edge_port->lsr_event = 1;
edge_port->lsr_mask = lsr;
} else {
dbg("%s - ===== Port %d LSR Status = %02x ======",
__func__, port_number, lsr);
handle_new_lsr(edge_port, 0, lsr, 0);
}
break;
case TIUMP_INTERRUPT_CODE_MSR:
msr = data[1];
dbg("%s - ===== Port %u MSR Status = %02x ======",
__func__, port_number, msr);
handle_new_msr(edge_port, msr);
break;
default:
dev_err(&urb->dev->dev,
"%s - Unknown Interrupt code from UMP %x\n",
__func__, data[1]);
break;
}
exit:
retval = usb_submit_urb(urb, GFP_ATOMIC);
if (retval)
dev_err(&urb->dev->dev,
"%s - usb_submit_urb failed with result %d\n",
__func__, retval);
}
static void edge_bulk_in_callback(struct urb *urb)
{
struct edgeport_port *edge_port = urb->context;
unsigned char *data = urb->transfer_buffer;
struct tty_struct *tty;
int retval = 0;
int port_number;
int status = urb->status;
dbg("%s", __func__);
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dbg("%s - urb shutting down with status: %d",
__func__, status);
return;
default:
dev_err(&urb->dev->dev,
"%s - nonzero read bulk status received: %d\n",
__func__, status);
}
if (status == -EPIPE)
goto exit;
if (status) {
dev_err(&urb->dev->dev, "%s - stopping read!\n", __func__);
return;
}
port_number = edge_port->port->number - edge_port->port->serial->minor;
if (edge_port->lsr_event) {
edge_port->lsr_event = 0;
dbg("%s ===== Port %u LSR Status = %02x, Data = %02x ======",
__func__, port_number, edge_port->lsr_mask, *data);
handle_new_lsr(edge_port, 1, edge_port->lsr_mask, *data);
--urb->actual_length;
++data;
}
tty = tty_port_tty_get(&edge_port->port->port);
if (tty && urb->actual_length) {
usb_serial_debug_data(debug, &edge_port->port->dev,
__func__, urb->actual_length, data);
if (edge_port->close_pending)
dbg("%s - close pending, dropping data on the floor",
__func__);
else
edge_tty_recv(&edge_port->port->dev, tty, data,
urb->actual_length);
edge_port->icount.rx += urb->actual_length;
}
tty_kref_put(tty);
exit:
spin_lock(&edge_port->ep_lock);
if (edge_port->ep_read_urb_state == EDGE_READ_URB_RUNNING) {
urb->dev = edge_port->port->serial->dev;
retval = usb_submit_urb(urb, GFP_ATOMIC);
} else if (edge_port->ep_read_urb_state == EDGE_READ_URB_STOPPING) {
edge_port->ep_read_urb_state = EDGE_READ_URB_STOPPED;
}
spin_unlock(&edge_port->ep_lock);
if (retval)
dev_err(&urb->dev->dev,
"%s - usb_submit_urb failed with result %d\n",
__func__, retval);
}
static void edge_tty_recv(struct device *dev, struct tty_struct *tty,
unsigned char *data, int length)
{
int queued;
queued = tty_insert_flip_string(tty, data, length);
if (queued < length)
dev_err(dev, "%s - dropping data, %d bytes lost\n",
__func__, length - queued);
tty_flip_buffer_push(tty);
}
static void edge_bulk_out_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
int status = urb->status;
struct tty_struct *tty;
dbg("%s - port %d", __func__, port->number);
edge_port->ep_write_urb_in_use = 0;
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dbg("%s - urb shutting down with status: %d",
__func__, status);
return;
default:
dev_err(&urb->dev->dev, "%s - nonzero write bulk status "
"received: %d\n", __func__, status);
}
tty = tty_port_tty_get(&port->port);
edge_send(tty);
tty_kref_put(tty);
}
static int edge_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
struct edgeport_serial *edge_serial;
struct usb_device *dev;
struct urb *urb;
int port_number;
int status;
u16 open_settings;
u8 transaction_timeout;
dbg("%s - port %d", __func__, port->number);
if (edge_port == NULL)
return -ENODEV;
port_number = port->number - port->serial->minor;
switch (port_number) {
case 0:
edge_port->uart_base = UMPMEM_BASE_UART1;
edge_port->dma_address = UMPD_OEDB1_ADDRESS;
break;
case 1:
edge_port->uart_base = UMPMEM_BASE_UART2;
edge_port->dma_address = UMPD_OEDB2_ADDRESS;
break;
default:
dev_err(&port->dev, "Unknown port number!!!\n");
return -ENODEV;
}
dbg("%s - port_number = %d, uart_base = %04x, dma_address = %04x",
__func__, port_number, edge_port->uart_base,
edge_port->dma_address);
dev = port->serial->dev;
memset(&(edge_port->icount), 0x00, sizeof(edge_port->icount));
init_waitqueue_head(&edge_port->delta_msr_wait);
status = ti_do_config(edge_port, UMPC_SET_CLR_LOOPBACK, 0);
if (status) {
dev_err(&port->dev,
"%s - cannot send clear loopback command, %d\n",
__func__, status);
return status;
}
if (tty)
edge_set_termios(tty, port, tty->termios);
transaction_timeout = 2;
edge_port->ump_read_timeout =
max(20, ((transaction_timeout * 3) / 2));
open_settings = (u8)(UMP_DMA_MODE_CONTINOUS |
UMP_PIPE_TRANS_TIMEOUT_ENA |
(transaction_timeout << 2));
dbg("%s - Sending UMPC_OPEN_PORT", __func__);
status = send_cmd(dev, UMPC_OPEN_PORT,
(u8)(UMPM_UART1_PORT + port_number), open_settings, NULL, 0);
if (status) {
dev_err(&port->dev, "%s - cannot send open command, %d\n",
__func__, status);
return status;
}
status = send_cmd(dev, UMPC_START_PORT,
(u8)(UMPM_UART1_PORT + port_number), 0, NULL, 0);
if (status) {
dev_err(&port->dev, "%s - cannot send start DMA command, %d\n",
__func__, status);
return status;
}
status = purge_port(port, UMP_PORT_DIR_OUT | UMP_PORT_DIR_IN);
if (status) {
dev_err(&port->dev,
"%s - cannot send clear buffers command, %d\n",
__func__, status);
return status;
}
status = ti_vread_sync(dev, UMPC_READ_MSR, 0,
(__u16)(UMPM_UART1_PORT + port_number),
&edge_port->shadow_msr, 1);
if (status) {
dev_err(&port->dev, "%s - cannot send read MSR command, %d\n",
__func__, status);
return status;
}
dbg("ShadowMSR 0x%X", edge_port->shadow_msr);
edge_port->shadow_mcr = MCR_RTS | MCR_DTR;
dbg("ShadowMCR 0x%X", edge_port->shadow_mcr);
edge_serial = edge_port->edge_serial;
if (mutex_lock_interruptible(&edge_serial->es_lock))
return -ERESTARTSYS;
if (edge_serial->num_ports_open == 0) {
urb = edge_serial->serial->port[0]->interrupt_in_urb;
if (!urb) {
dev_err(&port->dev,
"%s - no interrupt urb present, exiting\n",
__func__);
status = -EINVAL;
goto release_es_lock;
}
urb->complete = edge_interrupt_callback;
urb->context = edge_serial;
urb->dev = dev;
status = usb_submit_urb(urb, GFP_KERNEL);
if (status) {
dev_err(&port->dev,
"%s - usb_submit_urb failed with value %d\n",
__func__, status);
goto release_es_lock;
}
}
usb_clear_halt(dev, port->write_urb->pipe);
usb_clear_halt(dev, port->read_urb->pipe);
urb = port->read_urb;
if (!urb) {
dev_err(&port->dev, "%s - no read urb present, exiting\n",
__func__);
status = -EINVAL;
goto unlink_int_urb;
}
edge_port->ep_read_urb_state = EDGE_READ_URB_RUNNING;
urb->complete = edge_bulk_in_callback;
urb->context = edge_port;
urb->dev = dev;
status = usb_submit_urb(urb, GFP_KERNEL);
if (status) {
dev_err(&port->dev,
"%s - read bulk usb_submit_urb failed with value %d\n",
__func__, status);
goto unlink_int_urb;
}
++edge_serial->num_ports_open;
dbg("%s - exited", __func__);
goto release_es_lock;
unlink_int_urb:
if (edge_port->edge_serial->num_ports_open == 0)
usb_kill_urb(port->serial->port[0]->interrupt_in_urb);
release_es_lock:
mutex_unlock(&edge_serial->es_lock);
return status;
}
static void edge_close(struct usb_serial_port *port)
{
struct edgeport_serial *edge_serial;
struct edgeport_port *edge_port;
int port_number;
int status;
dbg("%s - port %d", __func__, port->number);
edge_serial = usb_get_serial_data(port->serial);
edge_port = usb_get_serial_port_data(port);
if (edge_serial == NULL || edge_port == NULL)
return;
edge_port->close_pending = 1;
chase_port(edge_port, (HZ * closing_wait) / 100, 1);
usb_kill_urb(port->read_urb);
usb_kill_urb(port->write_urb);
edge_port->ep_write_urb_in_use = 0;
dbg("%s - send umpc_close_port", __func__);
port_number = port->number - port->serial->minor;
status = send_cmd(port->serial->dev,
UMPC_CLOSE_PORT,
(__u8)(UMPM_UART1_PORT + port_number),
0,
NULL,
0);
mutex_lock(&edge_serial->es_lock);
--edge_port->edge_serial->num_ports_open;
if (edge_port->edge_serial->num_ports_open <= 0) {
usb_kill_urb(port->serial->port[0]->interrupt_in_urb);
edge_port->edge_serial->num_ports_open = 0;
}
mutex_unlock(&edge_serial->es_lock);
edge_port->close_pending = 0;
dbg("%s - exited", __func__);
}
static int edge_write(struct tty_struct *tty, struct usb_serial_port *port,
const unsigned char *data, int count)
{
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
dbg("%s - port %d", __func__, port->number);
if (count == 0) {
dbg("%s - write request of 0 bytes", __func__);
return 0;
}
if (edge_port == NULL)
return -ENODEV;
if (edge_port->close_pending == 1)
return -ENODEV;
count = kfifo_in_locked(&edge_port->write_fifo, data, count,
&edge_port->ep_lock);
edge_send(tty);
return count;
}
static void edge_send(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
int count, result;
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
unsigned long flags;
dbg("%s - port %d", __func__, port->number);
spin_lock_irqsave(&edge_port->ep_lock, flags);
if (edge_port->ep_write_urb_in_use) {
spin_unlock_irqrestore(&edge_port->ep_lock, flags);
return;
}
count = kfifo_out(&edge_port->write_fifo,
port->write_urb->transfer_buffer,
port->bulk_out_size);
if (count == 0) {
spin_unlock_irqrestore(&edge_port->ep_lock, flags);
return;
}
edge_port->ep_write_urb_in_use = 1;
spin_unlock_irqrestore(&edge_port->ep_lock, flags);
usb_serial_debug_data(debug, &port->dev, __func__, count,
port->write_urb->transfer_buffer);
usb_fill_bulk_urb(port->write_urb, port->serial->dev,
usb_sndbulkpipe(port->serial->dev,
port->bulk_out_endpointAddress),
port->write_urb->transfer_buffer, count,
edge_bulk_out_callback,
port);
result = usb_submit_urb(port->write_urb, GFP_ATOMIC);
if (result) {
dev_err(&port->dev,
"%s - failed submitting write urb, error %d\n",
__func__, result);
edge_port->ep_write_urb_in_use = 0;
} else
edge_port->icount.tx += count;
if (tty)
tty_wakeup(tty);
}
static int edge_write_room(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
int room = 0;
unsigned long flags;
dbg("%s - port %d", __func__, port->number);
if (edge_port == NULL)
return 0;
if (edge_port->close_pending == 1)
return 0;
spin_lock_irqsave(&edge_port->ep_lock, flags);
room = kfifo_avail(&edge_port->write_fifo);
spin_unlock_irqrestore(&edge_port->ep_lock, flags);
dbg("%s - returns %d", __func__, room);
return room;
}
static int edge_chars_in_buffer(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
int chars = 0;
unsigned long flags;
dbg("%s - port %d", __func__, port->number);
if (edge_port == NULL)
return 0;
if (edge_port->close_pending == 1)
return 0;
spin_lock_irqsave(&edge_port->ep_lock, flags);
chars = kfifo_len(&edge_port->write_fifo);
spin_unlock_irqrestore(&edge_port->ep_lock, flags);
dbg("%s - returns %d", __func__, chars);
return chars;
}
static void edge_throttle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
int status;
dbg("%s - port %d", __func__, port->number);
if (edge_port == NULL)
return;
if (I_IXOFF(tty)) {
unsigned char stop_char = STOP_CHAR(tty);
status = edge_write(tty, port, &stop_char, 1);
if (status <= 0) {
dev_err(&port->dev, "%s - failed to write stop character, %d\n", __func__, status);
}
}
if (C_CRTSCTS(tty))
stop_read(edge_port);
}
static void edge_unthrottle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
int status;
dbg("%s - port %d", __func__, port->number);
if (edge_port == NULL)
return;
if (I_IXOFF(tty)) {
unsigned char start_char = START_CHAR(tty);
status = edge_write(tty, port, &start_char, 1);
if (status <= 0) {
dev_err(&port->dev, "%s - failed to write start character, %d\n", __func__, status);
}
}
if (C_CRTSCTS(tty)) {
status = restart_read(edge_port);
if (status)
dev_err(&port->dev,
"%s - read bulk usb_submit_urb failed: %d\n",
__func__, status);
}
}
static void stop_read(struct edgeport_port *edge_port)
{
unsigned long flags;
spin_lock_irqsave(&edge_port->ep_lock, flags);
if (edge_port->ep_read_urb_state == EDGE_READ_URB_RUNNING)
edge_port->ep_read_urb_state = EDGE_READ_URB_STOPPING;
edge_port->shadow_mcr &= ~MCR_RTS;
spin_unlock_irqrestore(&edge_port->ep_lock, flags);
}
static int restart_read(struct edgeport_port *edge_port)
{
struct urb *urb;
int status = 0;
unsigned long flags;
spin_lock_irqsave(&edge_port->ep_lock, flags);
if (edge_port->ep_read_urb_state == EDGE_READ_URB_STOPPED) {
urb = edge_port->port->read_urb;
urb->complete = edge_bulk_in_callback;
urb->context = edge_port;
urb->dev = edge_port->port->serial->dev;
status = usb_submit_urb(urb, GFP_ATOMIC);
}
edge_port->ep_read_urb_state = EDGE_READ_URB_RUNNING;
edge_port->shadow_mcr |= MCR_RTS;
spin_unlock_irqrestore(&edge_port->ep_lock, flags);
return status;
}
static void change_port_settings(struct tty_struct *tty,
struct edgeport_port *edge_port, struct ktermios *old_termios)
{
struct ump_uart_config *config;
int baud;
unsigned cflag;
int status;
int port_number = edge_port->port->number -
edge_port->port->serial->minor;
dbg("%s - port %d", __func__, edge_port->port->number);
config = kmalloc (sizeof (*config), GFP_KERNEL);
if (!config) {
*tty->termios = *old_termios;
dev_err(&edge_port->port->dev, "%s - out of memory\n",
__func__);
return;
}
cflag = tty->termios->c_cflag;
config->wFlags = 0;
config->wFlags |= UMP_MASK_UART_FLAGS_RECEIVE_MS_INT;
config->wFlags |= UMP_MASK_UART_FLAGS_AUTO_START_ON_ERR;
config->bUartMode = (__u8)(edge_port->bUartMode);
switch (cflag & CSIZE) {
case CS5:
config->bDataBits = UMP_UART_CHAR5BITS;
dbg("%s - data bits = 5", __func__);
break;
case CS6:
config->bDataBits = UMP_UART_CHAR6BITS;
dbg("%s - data bits = 6", __func__);
break;
case CS7:
config->bDataBits = UMP_UART_CHAR7BITS;
dbg("%s - data bits = 7", __func__);
break;
default:
case CS8:
config->bDataBits = UMP_UART_CHAR8BITS;
dbg("%s - data bits = 8", __func__);
break;
}
if (cflag & PARENB) {
if (cflag & PARODD) {
config->wFlags |= UMP_MASK_UART_FLAGS_PARITY;
config->bParity = UMP_UART_ODDPARITY;
dbg("%s - parity = odd", __func__);
} else {
config->wFlags |= UMP_MASK_UART_FLAGS_PARITY;
config->bParity = UMP_UART_EVENPARITY;
dbg("%s - parity = even", __func__);
}
} else {
config->bParity = UMP_UART_NOPARITY;
dbg("%s - parity = none", __func__);
}
if (cflag & CSTOPB) {
config->bStopBits = UMP_UART_STOPBIT2;
dbg("%s - stop bits = 2", __func__);
} else {
config->bStopBits = UMP_UART_STOPBIT1;
dbg("%s - stop bits = 1", __func__);
}
if (cflag & CRTSCTS) {
config->wFlags |= UMP_MASK_UART_FLAGS_OUT_X_CTS_FLOW;
config->wFlags |= UMP_MASK_UART_FLAGS_RTS_FLOW;
dbg("%s - RTS/CTS is enabled", __func__);
} else {
dbg("%s - RTS/CTS is disabled", __func__);
tty->hw_stopped = 0;
restart_read(edge_port);
}
config->cXon = START_CHAR(tty);
config->cXoff = STOP_CHAR(tty);
if (I_IXOFF(tty)) {
config->wFlags |= UMP_MASK_UART_FLAGS_IN_X;
dbg("%s - INBOUND XON/XOFF is enabled, XON = %2x, XOFF = %2x",
__func__, config->cXon, config->cXoff);
} else
dbg("%s - INBOUND XON/XOFF is disabled", __func__);
if (I_IXON(tty)) {
config->wFlags |= UMP_MASK_UART_FLAGS_OUT_X;
dbg("%s - OUTBOUND XON/XOFF is enabled, XON = %2x, XOFF = %2x",
__func__, config->cXon, config->cXoff);
} else
dbg("%s - OUTBOUND XON/XOFF is disabled", __func__);
tty->termios->c_cflag &= ~CMSPAR;
baud = tty_get_baud_rate(tty);
if (!baud) {
baud = 9600;
} else
tty_encode_baud_rate(tty, baud, baud);
edge_port->baud_rate = baud;
config->wBaudRate = (__u16)((461550L + baud/2) / baud);
dbg("%s - baud rate = %d, wBaudRate = %d", __func__, baud,
config->wBaudRate);
dbg("wBaudRate: %d", (int)(461550L / config->wBaudRate));
dbg("wFlags: 0x%x", config->wFlags);
dbg("bDataBits: %d", config->bDataBits);
dbg("bParity: %d", config->bParity);
dbg("bStopBits: %d", config->bStopBits);
dbg("cXon: %d", config->cXon);
dbg("cXoff: %d", config->cXoff);
dbg("bUartMode: %d", config->bUartMode);
cpu_to_be16s(&config->wFlags);
cpu_to_be16s(&config->wBaudRate);
status = send_cmd(edge_port->port->serial->dev, UMPC_SET_CONFIG,
(__u8)(UMPM_UART1_PORT + port_number),
0, (__u8 *)config, sizeof(*config));
if (status)
dbg("%s - error %d when trying to write config to device",
__func__, status);
kfree(config);
}
static void edge_set_termios(struct tty_struct *tty,
struct usb_serial_port *port, struct ktermios *old_termios)
{
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
unsigned int cflag;
cflag = tty->termios->c_cflag;
dbg("%s - clfag %08x iflag %08x", __func__,
tty->termios->c_cflag, tty->termios->c_iflag);
dbg("%s - old clfag %08x old iflag %08x", __func__,
old_termios->c_cflag, old_termios->c_iflag);
dbg("%s - port %d", __func__, port->number);
if (edge_port == NULL)
return;
change_port_settings(tty, edge_port, old_termios);
}
static int edge_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct usb_serial_port *port = tty->driver_data;
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
unsigned int mcr;
unsigned long flags;
dbg("%s - port %d", __func__, port->number);
spin_lock_irqsave(&edge_port->ep_lock, flags);
mcr = edge_port->shadow_mcr;
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
edge_port->shadow_mcr = mcr;
spin_unlock_irqrestore(&edge_port->ep_lock, flags);
restore_mcr(edge_port, mcr);
return 0;
}
static int edge_tiocmget(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
unsigned int result = 0;
unsigned int msr;
unsigned int mcr;
unsigned long flags;
dbg("%s - port %d", __func__, port->number);
spin_lock_irqsave(&edge_port->ep_lock, flags);
msr = edge_port->shadow_msr;
mcr = edge_port->shadow_mcr;
result = ((mcr & MCR_DTR) ? TIOCM_DTR: 0)
| ((mcr & MCR_RTS) ? TIOCM_RTS: 0)
| ((msr & EDGEPORT_MSR_CTS) ? TIOCM_CTS: 0)
| ((msr & EDGEPORT_MSR_CD) ? TIOCM_CAR: 0)
| ((msr & EDGEPORT_MSR_RI) ? TIOCM_RI: 0)
| ((msr & EDGEPORT_MSR_DSR) ? TIOCM_DSR: 0);
dbg("%s -- %x", __func__, result);
spin_unlock_irqrestore(&edge_port->ep_lock, flags);
return result;
}
static int edge_get_icount(struct tty_struct *tty,
struct serial_icounter_struct *icount)
{
struct usb_serial_port *port = tty->driver_data;
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
struct async_icount *ic = &edge_port->icount;
icount->cts = ic->cts;
icount->dsr = ic->dsr;
icount->rng = ic->rng;
icount->dcd = ic->dcd;
icount->tx = ic->tx;
icount->rx = ic->rx;
icount->frame = ic->frame;
icount->parity = ic->parity;
icount->overrun = ic->overrun;
icount->brk = ic->brk;
icount->buf_overrun = ic->buf_overrun;
return 0;
}
static int get_serial_info(struct edgeport_port *edge_port,
struct serial_struct __user *retinfo)
{
struct serial_struct tmp;
if (!retinfo)
return -EFAULT;
memset(&tmp, 0, sizeof(tmp));
tmp.type = PORT_16550A;
tmp.line = edge_port->port->serial->minor;
tmp.port = edge_port->port->number;
tmp.irq = 0;
tmp.flags = ASYNC_SKIP_TEST | ASYNC_AUTO_IRQ;
tmp.xmit_fifo_size = edge_port->port->bulk_out_size;
tmp.baud_base = 9600;
tmp.close_delay = 5*HZ;
tmp.closing_wait = closing_wait;
if (copy_to_user(retinfo, &tmp, sizeof(*retinfo)))
return -EFAULT;
return 0;
}
static int edge_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct usb_serial_port *port = tty->driver_data;
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
struct async_icount cnow;
struct async_icount cprev;
dbg("%s - port %d, cmd = 0x%x", __func__, port->number, cmd);
switch (cmd) {
case TIOCGSERIAL:
dbg("%s - (%d) TIOCGSERIAL", __func__, port->number);
return get_serial_info(edge_port,
(struct serial_struct __user *) arg);
case TIOCMIWAIT:
dbg("%s - (%d) TIOCMIWAIT", __func__, port->number);
cprev = edge_port->icount;
while (1) {
interruptible_sleep_on(&edge_port->delta_msr_wait);
if (signal_pending(current))
return -ERESTARTSYS;
cnow = edge_port->icount;
if (cnow.rng == cprev.rng && cnow.dsr == cprev.dsr &&
cnow.dcd == cprev.dcd && cnow.cts == cprev.cts)
return -EIO;
if (((arg & TIOCM_RNG) && (cnow.rng != cprev.rng)) ||
((arg & TIOCM_DSR) && (cnow.dsr != cprev.dsr)) ||
((arg & TIOCM_CD) && (cnow.dcd != cprev.dcd)) ||
((arg & TIOCM_CTS) && (cnow.cts != cprev.cts))) {
return 0;
}
cprev = cnow;
}
break;
}
return -ENOIOCTLCMD;
}
static void edge_break(struct tty_struct *tty, int break_state)
{
struct usb_serial_port *port = tty->driver_data;
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
int status;
int bv = 0;
dbg("%s - state = %d", __func__, break_state);
chase_port(edge_port, 0, 0);
if (break_state == -1)
bv = 1;
status = ti_do_config(edge_port, UMPC_SET_CLR_BREAK, bv);
if (status)
dbg("%s - error %d sending break set/clear command.",
__func__, status);
}
static int edge_startup(struct usb_serial *serial)
{
struct edgeport_serial *edge_serial;
struct edgeport_port *edge_port;
struct usb_device *dev;
int status;
int i;
dev = serial->dev;
edge_serial = kzalloc(sizeof(struct edgeport_serial), GFP_KERNEL);
if (edge_serial == NULL) {
dev_err(&serial->dev->dev, "%s - Out of memory\n", __func__);
return -ENOMEM;
}
mutex_init(&edge_serial->es_lock);
edge_serial->serial = serial;
usb_set_serial_data(serial, edge_serial);
status = download_fw(edge_serial);
if (status) {
kfree(edge_serial);
return status;
}
for (i = 0; i < serial->num_ports; ++i) {
edge_port = kzalloc(sizeof(struct edgeport_port), GFP_KERNEL);
if (edge_port == NULL) {
dev_err(&serial->dev->dev, "%s - Out of memory\n",
__func__);
goto cleanup;
}
spin_lock_init(&edge_port->ep_lock);
if (kfifo_alloc(&edge_port->write_fifo, EDGE_OUT_BUF_SIZE,
GFP_KERNEL)) {
dev_err(&serial->dev->dev, "%s - Out of memory\n",
__func__);
kfree(edge_port);
goto cleanup;
}
edge_port->port = serial->port[i];
edge_port->edge_serial = edge_serial;
usb_set_serial_port_data(serial->port[i], edge_port);
edge_port->bUartMode = default_uart_mode;
}
return 0;
cleanup:
for (--i; i >= 0; --i) {
edge_port = usb_get_serial_port_data(serial->port[i]);
kfifo_free(&edge_port->write_fifo);
kfree(edge_port);
usb_set_serial_port_data(serial->port[i], NULL);
}
kfree(edge_serial);
usb_set_serial_data(serial, NULL);
return -ENOMEM;
}
static void edge_disconnect(struct usb_serial *serial)
{
int i;
struct edgeport_port *edge_port;
dbg("%s", __func__);
for (i = 0; i < serial->num_ports; ++i) {
edge_port = usb_get_serial_port_data(serial->port[i]);
edge_remove_sysfs_attrs(edge_port->port);
}
}
static void edge_release(struct usb_serial *serial)
{
int i;
struct edgeport_port *edge_port;
dbg("%s", __func__);
for (i = 0; i < serial->num_ports; ++i) {
edge_port = usb_get_serial_port_data(serial->port[i]);
kfifo_free(&edge_port->write_fifo);
kfree(edge_port);
}
kfree(usb_get_serial_data(serial));
}
static ssize_t show_uart_mode(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct usb_serial_port *port = to_usb_serial_port(dev);
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
return sprintf(buf, "%d\n", edge_port->bUartMode);
}
static ssize_t store_uart_mode(struct device *dev,
struct device_attribute *attr, const char *valbuf, size_t count)
{
struct usb_serial_port *port = to_usb_serial_port(dev);
struct edgeport_port *edge_port = usb_get_serial_port_data(port);
unsigned int v = simple_strtoul(valbuf, NULL, 0);
dbg("%s: setting uart_mode = %d", __func__, v);
if (v < 256)
edge_port->bUartMode = v;
else
dev_err(dev, "%s - uart_mode %d is invalid\n", __func__, v);
return count;
}
static int edge_create_sysfs_attrs(struct usb_serial_port *port)
{
return device_create_file(&port->dev, &dev_attr_uart_mode);
}
static int edge_remove_sysfs_attrs(struct usb_serial_port *port)
{
device_remove_file(&port->dev, &dev_attr_uart_mode);
return 0;
}
static int __init edgeport_init(void)
{
int retval;
retval = usb_serial_register(&edgeport_1port_device);
if (retval)
goto failed_1port_device_register;
retval = usb_serial_register(&edgeport_2port_device);
if (retval)
goto failed_2port_device_register;
retval = usb_register(&io_driver);
if (retval)
goto failed_usb_register;
printk(KERN_INFO KBUILD_MODNAME ": " DRIVER_VERSION ":"
DRIVER_DESC "\n");
return 0;
failed_usb_register:
usb_serial_deregister(&edgeport_2port_device);
failed_2port_device_register:
usb_serial_deregister(&edgeport_1port_device);
failed_1port_device_register:
return retval;
}
static void __exit edgeport_exit(void)
{
usb_deregister(&io_driver);
usb_serial_deregister(&edgeport_1port_device);
usb_serial_deregister(&edgeport_2port_device);
}
