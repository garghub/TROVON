static unsigned char atohx(unsigned char *dst, char *src)
{
unsigned char value = 0;
char msb = tolower(*src) - '0';
char lsb = tolower(*(src + 1)) - '0';
if (msb > 9)
msb -= 7;
if (lsb > 9)
lsb -= 7;
*dst = value = ((msb & 0xF) << 4) | (lsb & 0xF);
return value;
}
static int parse_hex_line(unsigned char *fw_data, unsigned char *addr,
unsigned char *data, int *dataLength,
unsigned char *addr_has_changed) {
int count = 0;
unsigned char *src, dst;
if (*fw_data++ != ':') {
pr_err("invalid firmware file\n");
return -EFAULT;
}
for (src = fw_data; *src != '\n'; src += 2) {
atohx(&dst, src);
switch (count) {
case 0:
*dataLength = dst;
break;
case 1:
addr[2] = dst;
break;
case 2:
addr[3] = dst;
break;
case 3:
if (dst == 0x04)
*addr_has_changed = 1;
else
*addr_has_changed = 0;
break;
case 4:
case 5:
if (*addr_has_changed)
addr[(count - 4)] = dst;
else
data[(count - 4)] = dst;
break;
default:
data[(count - 4)] = dst;
break;
}
count++;
}
return (count * 2) + 2;
}
static int as102_firmware_upload(struct as10x_bus_adapter_t *bus_adap,
unsigned char *cmd,
const struct firmware *firmware) {
struct as10x_fw_pkt_t fw_pkt;
int total_read_bytes = 0, errno = 0;
unsigned char addr_has_changed = 0;
ENTER();
for (total_read_bytes = 0; total_read_bytes < firmware->size; ) {
int read_bytes = 0, data_len = 0;
read_bytes = parse_hex_line(
(u8 *) (firmware->data + total_read_bytes),
fw_pkt.raw.address,
fw_pkt.raw.data,
&data_len,
&addr_has_changed);
if (read_bytes <= 0)
goto error;
total_read_bytes += read_bytes;
if (total_read_bytes == firmware->size) {
fw_pkt.u.request[0] = 0x00;
fw_pkt.u.request[1] = 0x03;
errno = bus_adap->ops->upload_fw_pkt(bus_adap,
(uint8_t *)
&fw_pkt, 2, 0);
if (errno < 0)
goto error;
} else {
if (!addr_has_changed) {
fw_pkt.u.request[0] = 0x00;
fw_pkt.u.request[1] = 0x01;
data_len += sizeof(fw_pkt.u.request);
data_len += sizeof(fw_pkt.raw.address);
errno = bus_adap->ops->upload_fw_pkt(bus_adap,
(uint8_t *)
&fw_pkt,
data_len,
0);
if (errno < 0)
goto error;
}
}
}
error:
LEAVE();
return (errno == 0) ? total_read_bytes : errno;
}
int as102_fw_upload(struct as10x_bus_adapter_t *bus_adap)
{
int errno = -EFAULT;
const struct firmware *firmware;
unsigned char *cmd_buf = NULL;
char *fw1, *fw2;
struct usb_device *dev = bus_adap->usb_dev;
ENTER();
if (dual_tuner) {
fw1 = as102_dt_fw1;
fw2 = as102_dt_fw2;
} else {
fw1 = as102_st_fw1;
fw2 = as102_st_fw2;
}
cmd_buf = kzalloc(MAX_FW_PKT_SIZE, GFP_KERNEL);
if (cmd_buf == NULL) {
errno = -ENOMEM;
goto error;
}
errno = request_firmware(&firmware, fw1, &dev->dev);
if (errno < 0) {
pr_err("%s: unable to locate firmware file: %s\n",
DRIVER_NAME, fw1);
goto error;
}
errno = as102_firmware_upload(bus_adap, cmd_buf, firmware);
if (errno < 0) {
pr_err("%s: error during firmware upload part1\n",
DRIVER_NAME);
goto error;
}
pr_info("%s: firmware: %s loaded with success\n",
DRIVER_NAME, fw1);
release_firmware(firmware);
mdelay(100);
errno = request_firmware(&firmware, fw2, &dev->dev);
if (errno < 0) {
pr_err("%s: unable to locate firmware file: %s\n",
DRIVER_NAME, fw2);
goto error;
}
errno = as102_firmware_upload(bus_adap, cmd_buf, firmware);
if (errno < 0) {
pr_err("%s: error during firmware upload part2\n",
DRIVER_NAME);
goto error;
}
pr_info("%s: firmware: %s loaded with success\n",
DRIVER_NAME, fw2);
error:
kfree(cmd_buf);
if (firmware != NULL)
release_firmware(firmware);
LEAVE();
return errno;
}
