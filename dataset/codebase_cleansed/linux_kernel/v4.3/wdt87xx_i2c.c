static int wdt87xx_i2c_xfer(struct i2c_client *client,
void *txdata, size_t txlen,
void *rxdata, size_t rxlen)
{
struct i2c_msg msgs[] = {
{
.addr = client->addr,
.flags = 0,
.len = txlen,
.buf = txdata,
},
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = rxlen,
.buf = rxdata,
},
};
int error;
int ret;
ret = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
if (ret != ARRAY_SIZE(msgs)) {
error = ret < 0 ? ret : -EIO;
dev_err(&client->dev, "%s: i2c transfer failed: %d\n",
__func__, error);
return error;
}
return 0;
}
static int wdt87xx_get_desc(struct i2c_client *client, u8 desc_idx,
u8 *buf, size_t len)
{
u8 tx_buf[] = { 0x22, 0x00, 0x10, 0x0E, 0x23, 0x00 };
int error;
tx_buf[2] |= desc_idx & 0xF;
error = wdt87xx_i2c_xfer(client, tx_buf, sizeof(tx_buf),
buf, len);
if (error) {
dev_err(&client->dev, "get desc failed: %d\n", error);
return error;
}
if (buf[0] != len) {
dev_err(&client->dev, "unexpected response to get desc: %d\n",
buf[0]);
return -EINVAL;
}
mdelay(WDT_COMMAND_DELAY_MS);
return 0;
}
static int wdt87xx_get_string(struct i2c_client *client, u8 str_idx,
u8 *buf, size_t len)
{
u8 tx_buf[] = { 0x22, 0x00, 0x13, 0x0E, str_idx, 0x23, 0x00 };
u8 rx_buf[PKT_WRITE_SIZE];
size_t rx_len = len + 2;
int error;
if (rx_len > sizeof(rx_buf))
return -EINVAL;
error = wdt87xx_i2c_xfer(client, tx_buf, sizeof(tx_buf),
rx_buf, rx_len);
if (error) {
dev_err(&client->dev, "get string failed: %d\n", error);
return error;
}
if (rx_buf[1] != 0x03) {
dev_err(&client->dev, "unexpected response to get string: %d\n",
rx_buf[1]);
return -EINVAL;
}
rx_len = min_t(size_t, len, rx_buf[0]);
memcpy(buf, &rx_buf[2], rx_len);
mdelay(WDT_COMMAND_DELAY_MS);
return 0;
}
static int wdt87xx_get_feature(struct i2c_client *client,
u8 *buf, size_t buf_size)
{
u8 tx_buf[8];
u8 rx_buf[PKT_WRITE_SIZE];
size_t tx_len = 0;
size_t rx_len = buf_size + 2;
int error;
if (rx_len > sizeof(rx_buf))
return -EINVAL;
tx_buf[tx_len++] = 0x22;
tx_buf[tx_len++] = 0x00;
if (buf[CMD_REPORT_ID_OFFSET] > 0xF) {
tx_buf[tx_len++] = 0x30;
tx_buf[tx_len++] = 0x02;
tx_buf[tx_len++] = buf[CMD_REPORT_ID_OFFSET];
} else {
tx_buf[tx_len++] = 0x30 | buf[CMD_REPORT_ID_OFFSET];
tx_buf[tx_len++] = 0x02;
}
tx_buf[tx_len++] = 0x23;
tx_buf[tx_len++] = 0x00;
error = wdt87xx_i2c_xfer(client, tx_buf, tx_len, rx_buf, rx_len);
if (error) {
dev_err(&client->dev, "get feature failed: %d\n", error);
return error;
}
rx_len = min_t(size_t, buf_size, get_unaligned_le16(rx_buf));
memcpy(buf, &rx_buf[2], rx_len);
mdelay(WDT_COMMAND_DELAY_MS);
return 0;
}
static int wdt87xx_set_feature(struct i2c_client *client,
const u8 *buf, size_t buf_size)
{
u8 tx_buf[PKT_WRITE_SIZE];
int tx_len = 0;
int error;
tx_buf[tx_len++] = 0x22;
tx_buf[tx_len++] = 0x00;
if (buf[CMD_REPORT_ID_OFFSET] > 0xF) {
tx_buf[tx_len++] = 0x30;
tx_buf[tx_len++] = 0x03;
tx_buf[tx_len++] = buf[CMD_REPORT_ID_OFFSET];
} else {
tx_buf[tx_len++] = 0x30 | buf[CMD_REPORT_ID_OFFSET];
tx_buf[tx_len++] = 0x03;
}
tx_buf[tx_len++] = 0x23;
tx_buf[tx_len++] = 0x00;
tx_buf[tx_len++] = (buf_size & 0xFF);
tx_buf[tx_len++] = ((buf_size & 0xFF00) >> 8);
if (tx_len + buf_size > sizeof(tx_buf))
return -EINVAL;
memcpy(&tx_buf[tx_len], buf, buf_size);
tx_len += buf_size;
error = i2c_master_send(client, tx_buf, tx_len);
if (error < 0) {
dev_err(&client->dev, "set feature failed: %d\n", error);
return error;
}
mdelay(WDT_COMMAND_DELAY_MS);
return 0;
}
static int wdt87xx_send_command(struct i2c_client *client, int cmd, int value)
{
u8 cmd_buf[CMD_BUF_SIZE];
cmd_buf[CMD_REPORT_ID_OFFSET] = VND_REQ_WRITE;
cmd_buf[CMD_TYPE_OFFSET] = VND_SET_COMMAND_DATA;
put_unaligned_le16((u16)cmd, &cmd_buf[CMD_INDEX_OFFSET]);
switch (cmd) {
case VND_CMD_START:
case VND_CMD_STOP:
case VND_CMD_RESET:
put_unaligned_le32((value & 0xFF), &cmd_buf[CMD_LENGTH_OFFSET]);
break;
case VND_CMD_SFLCK:
put_unaligned_le16(CMD_SFLCK_KEY, &cmd_buf[CMD_KEY_OFFSET]);
break;
case VND_CMD_SFUNL:
put_unaligned_le16(CMD_SFUNL_KEY, &cmd_buf[CMD_KEY_OFFSET]);
break;
case VND_CMD_ERASE:
case VND_SET_CHECKSUM_CALC:
case VND_SET_CHECKSUM_LENGTH:
put_unaligned_le32(value, &cmd_buf[CMD_KEY_OFFSET]);
break;
default:
cmd_buf[CMD_REPORT_ID_OFFSET] = 0;
dev_err(&client->dev, "Invalid command: %d\n", cmd);
return -EINVAL;
}
return wdt87xx_set_feature(client, cmd_buf, sizeof(cmd_buf));
}
static int wdt87xx_sw_reset(struct i2c_client *client)
{
int error;
dev_dbg(&client->dev, "resetting device now\n");
error = wdt87xx_send_command(client, VND_CMD_RESET, 0);
if (error) {
dev_err(&client->dev, "reset failed\n");
return error;
}
msleep(WDT_FW_RESET_TIME);
return 0;
}
static const void *wdt87xx_get_fw_chunk(const struct firmware *fw, u32 id)
{
size_t pos = FW_PAYLOAD_OFFSET;
u32 chunk_id, chunk_size;
while (pos < fw->size) {
chunk_id = get_unaligned_le32(fw->data +
pos + FW_CHUNK_ID_OFFSET);
if (chunk_id == id)
return fw->data + pos;
chunk_size = get_unaligned_le32(fw->data +
pos + FW_CHUNK_SIZE_OFFSET);
pos += chunk_size + 2 * sizeof(u32);
}
return NULL;
}
static int wdt87xx_get_sysparam(struct i2c_client *client,
struct wdt87xx_sys_param *param)
{
u8 buf[PKT_READ_SIZE];
int error;
error = wdt87xx_get_desc(client, WDT_GD_DEVICE, buf, 18);
if (error) {
dev_err(&client->dev, "failed to get device desc\n");
return error;
}
param->vendor_id = get_unaligned_le16(buf + DEV_DESC_OFFSET_VID);
param->product_id = get_unaligned_le16(buf + DEV_DESC_OFFSET_PID);
error = wdt87xx_get_string(client, STRIDX_PARAMETERS, buf, 34);
if (error) {
dev_err(&client->dev, "failed to get parameters\n");
return error;
}
param->xmls_id1 = get_unaligned_le16(buf + CTL_PARAM_OFFSET_XMLS_ID1);
param->xmls_id2 = get_unaligned_le16(buf + CTL_PARAM_OFFSET_XMLS_ID2);
param->phy_ch_x = get_unaligned_le16(buf + CTL_PARAM_OFFSET_PHY_CH_X);
param->phy_ch_y = get_unaligned_le16(buf + CTL_PARAM_OFFSET_PHY_CH_Y);
param->phy_w = get_unaligned_le16(buf + CTL_PARAM_OFFSET_PHY_W) / 10;
param->phy_h = get_unaligned_le16(buf + CTL_PARAM_OFFSET_PHY_H) / 10;
param->scaling_factor =
get_unaligned_le16(buf + CTL_PARAM_OFFSET_FACTOR);
param->max_x = MAX_UNIT_AXIS;
param->max_y = DIV_ROUND_CLOSEST(MAX_UNIT_AXIS * param->phy_h,
param->phy_w);
error = wdt87xx_get_string(client, STRIDX_PLATFORM_ID, buf, 8);
if (error) {
dev_err(&client->dev, "failed to get platform id\n");
return error;
}
param->plat_id = buf[1];
buf[0] = 0xf2;
error = wdt87xx_get_feature(client, buf, 16);
if (error) {
dev_err(&client->dev, "failed to get firmware id\n");
return error;
}
if (buf[0] != 0xf2) {
dev_err(&client->dev, "wrong id of fw response: 0x%x\n",
buf[0]);
return -EINVAL;
}
param->fw_id = get_unaligned_le16(&buf[1]);
dev_info(&client->dev,
"fw_id: 0x%x, plat_id: 0x%x, xml_id1: %04x, xml_id2: %04x\n",
param->fw_id, param->plat_id,
param->xmls_id1, param->xmls_id2);
return 0;
}
static int wdt87xx_validate_firmware(struct wdt87xx_data *wdt,
const struct firmware *fw)
{
const void *fw_chunk;
u32 data1, data2;
u32 size;
u8 fw_chip_id;
u8 chip_id;
data1 = get_unaligned_le32(fw->data + FW_FOURCC1_OFFSET);
data2 = get_unaligned_le32(fw->data + FW_FOURCC2_OFFSET);
if (data1 != FOURCC_ID_RIFF || data2 != FOURCC_ID_WHIF) {
dev_err(&wdt->client->dev, "check fw tag failed\n");
return -EINVAL;
}
size = get_unaligned_le32(fw->data + FW_SIZE_OFFSET);
if (size != fw->size) {
dev_err(&wdt->client->dev,
"fw size mismatch: expected %d, actual %zu\n",
size, fw->size);
return -EINVAL;
}
fw_chunk = wdt87xx_get_fw_chunk(fw, CHUNK_ID_FRWR);
if (!fw_chunk) {
dev_err(&wdt->client->dev,
"unable to locate firmware chunk\n");
return -EINVAL;
}
fw_chip_id = (get_unaligned_le32(fw_chunk +
FW_CHUNK_VERSION_OFFSET) >> 12) & 0xF;
chip_id = (wdt->param.fw_id >> 12) & 0xF;
if (fw_chip_id != chip_id) {
dev_err(&wdt->client->dev,
"fw version mismatch: fw %d vs. chip %d\n",
fw_chip_id, chip_id);
return -ENODEV;
}
return 0;
}
static int wdt87xx_validate_fw_chunk(const void *data, int id)
{
if (id == CHUNK_ID_FRWR) {
u32 fw_id;
fw_id = get_unaligned_le32(data + FW_CHUNK_PAYLOAD_OFFSET);
if (fw_id != WDT_FIRMWARE_ID)
return -EINVAL;
}
return 0;
}
static int wdt87xx_write_data(struct i2c_client *client, const char *data,
u32 address, int length)
{
u16 packet_size;
int count = 0;
int error;
u8 pkt_buf[PKT_BUF_SIZE];
if ((address & 0x3) != 0 || (length & 0x3) != 0) {
dev_err(&client->dev,
"addr & len must be 4 bytes aligned %x, %x\n",
address, length);
return -EINVAL;
}
while (length) {
packet_size = min(length, PACKET_SIZE);
pkt_buf[CMD_REPORT_ID_OFFSET] = VND_REQ_WRITE;
pkt_buf[CMD_TYPE_OFFSET] = VND_SET_DATA;
put_unaligned_le16(packet_size, &pkt_buf[CMD_INDEX_OFFSET]);
put_unaligned_le32(address, &pkt_buf[CMD_LENGTH_OFFSET]);
memcpy(&pkt_buf[CMD_DATA_OFFSET], data, packet_size);
error = wdt87xx_set_feature(client, pkt_buf, sizeof(pkt_buf));
if (error)
return error;
length -= packet_size;
data += packet_size;
address += packet_size;
mdelay(WDT_FLASH_WRITE_DELAY_MS);
if ((++count % 32) == 0) {
msleep(20);
}
}
return 0;
}
static u16 misr(u16 cur_value, u8 new_value)
{
u32 a, b;
u32 bit0;
u32 y;
a = cur_value;
b = new_value;
bit0 = a ^ (b & 1);
bit0 ^= a >> 1;
bit0 ^= a >> 2;
bit0 ^= a >> 4;
bit0 ^= a >> 5;
bit0 ^= a >> 7;
bit0 ^= a >> 11;
bit0 ^= a >> 15;
y = (a << 1) ^ b;
y = (y & ~1) | (bit0 & 1);
return (u16)y;
}
static u16 wdt87xx_calculate_checksum(const u8 *data, size_t length)
{
u16 checksum = 0;
size_t i;
for (i = 0; i < length; i++)
checksum = misr(checksum, data[i]);
return checksum;
}
static int wdt87xx_get_checksum(struct i2c_client *client, u16 *checksum,
u32 address, int length)
{
int error;
int time_delay;
u8 pkt_buf[PKT_BUF_SIZE];
u8 cmd_buf[CMD_BUF_SIZE];
error = wdt87xx_send_command(client, VND_SET_CHECKSUM_LENGTH, length);
if (error) {
dev_err(&client->dev, "failed to set checksum length\n");
return error;
}
error = wdt87xx_send_command(client, VND_SET_CHECKSUM_CALC, address);
if (error) {
dev_err(&client->dev, "failed to set checksum address\n");
return error;
}
time_delay = DIV_ROUND_UP(length, 1024);
msleep(time_delay * 30);
memset(cmd_buf, 0, sizeof(cmd_buf));
cmd_buf[CMD_REPORT_ID_OFFSET] = VND_REQ_READ;
cmd_buf[CMD_TYPE_OFFSET] = VND_GET_CHECKSUM;
error = wdt87xx_set_feature(client, cmd_buf, sizeof(cmd_buf));
if (error) {
dev_err(&client->dev, "failed to request checksum\n");
return error;
}
memset(pkt_buf, 0, sizeof(pkt_buf));
pkt_buf[CMD_REPORT_ID_OFFSET] = VND_READ_DATA;
error = wdt87xx_get_feature(client, pkt_buf, sizeof(pkt_buf));
if (error) {
dev_err(&client->dev, "failed to read checksum\n");
return error;
}
*checksum = get_unaligned_le16(&pkt_buf[CMD_DATA_OFFSET]);
return 0;
}
static int wdt87xx_write_firmware(struct i2c_client *client, const void *chunk)
{
u32 start_addr = get_unaligned_le32(chunk + FW_CHUNK_TGT_START_OFFSET);
u32 size = get_unaligned_le32(chunk + FW_CHUNK_PAYLOAD_LEN_OFFSET);
const void *data = chunk + FW_CHUNK_PAYLOAD_OFFSET;
int error;
int err1;
int page_size;
int retry = 0;
u16 device_checksum, firmware_checksum;
dev_dbg(&client->dev, "start 4k page program\n");
error = wdt87xx_send_command(client, VND_CMD_STOP, MODE_STOP);
if (error) {
dev_err(&client->dev, "stop report mode failed\n");
return error;
}
error = wdt87xx_send_command(client, VND_CMD_SFUNL, 0);
if (error) {
dev_err(&client->dev, "unlock failed\n");
goto out_enable_reporting;
}
mdelay(10);
while (size) {
dev_dbg(&client->dev, "%s: %x, %x\n", __func__,
start_addr, size);
page_size = min_t(u32, size, PG_SIZE);
size -= page_size;
for (retry = 0; retry < MAX_RETRIES; retry++) {
error = wdt87xx_send_command(client, VND_CMD_ERASE,
start_addr);
if (error) {
dev_err(&client->dev,
"erase failed at %#08x\n", start_addr);
break;
}
msleep(50);
error = wdt87xx_write_data(client, data, start_addr,
page_size);
if (error) {
dev_err(&client->dev,
"write failed at %#08x (%d bytes)\n",
start_addr, page_size);
break;
}
error = wdt87xx_get_checksum(client, &device_checksum,
start_addr, page_size);
if (error) {
dev_err(&client->dev,
"failed to retrieve checksum for %#08x (len: %d)\n",
start_addr, page_size);
break;
}
firmware_checksum =
wdt87xx_calculate_checksum(data, page_size);
if (device_checksum == firmware_checksum)
break;
dev_err(&client->dev,
"checksum fail: %d vs %d, retry %d\n",
device_checksum, firmware_checksum, retry);
}
if (retry == MAX_RETRIES) {
dev_err(&client->dev, "page write failed\n");
error = -EIO;
goto out_lock_device;
}
start_addr = start_addr + page_size;
data = data + page_size;
}
out_lock_device:
err1 = wdt87xx_send_command(client, VND_CMD_SFLCK, 0);
if (err1)
dev_err(&client->dev, "lock failed\n");
mdelay(10);
out_enable_reporting:
err1 = wdt87xx_send_command(client, VND_CMD_START, 0);
if (err1)
dev_err(&client->dev, "start to report failed\n");
return error ? error : err1;
}
static int wdt87xx_load_chunk(struct i2c_client *client,
const struct firmware *fw, u32 ck_id)
{
const void *chunk;
int error;
chunk = wdt87xx_get_fw_chunk(fw, ck_id);
if (!chunk) {
dev_err(&client->dev, "unable to locate chunk (type %d)\n",
ck_id);
return -EINVAL;
}
error = wdt87xx_validate_fw_chunk(chunk, ck_id);
if (error) {
dev_err(&client->dev, "invalid chunk (type %d): %d\n",
ck_id, error);
return error;
}
error = wdt87xx_write_firmware(client, chunk);
if (error) {
dev_err(&client->dev,
"failed to write fw chunk (type %d): %d\n",
ck_id, error);
return error;
}
return 0;
}
static int wdt87xx_do_update_firmware(struct i2c_client *client,
const struct firmware *fw,
unsigned int chunk_id)
{
struct wdt87xx_data *wdt = i2c_get_clientdata(client);
int error;
error = wdt87xx_validate_firmware(wdt, fw);
if (error)
return error;
error = mutex_lock_interruptible(&wdt->fw_mutex);
if (error)
return error;
disable_irq(client->irq);
error = wdt87xx_load_chunk(client, fw, chunk_id);
if (error) {
dev_err(&client->dev,
"firmware load failed (type: %d): %d\n",
chunk_id, error);
goto out;
}
error = wdt87xx_sw_reset(client);
if (error) {
dev_err(&client->dev, "soft reset failed: %d\n", error);
goto out;
}
error = wdt87xx_get_sysparam(client, &wdt->param);
if (error)
dev_err(&client->dev,
"failed to refresh system paramaters: %d\n", error);
out:
enable_irq(client->irq);
mutex_unlock(&wdt->fw_mutex);
return error ? error : 0;
}
static int wdt87xx_update_firmware(struct device *dev,
const char *fw_name, unsigned int chunk_id)
{
struct i2c_client *client = to_i2c_client(dev);
const struct firmware *fw;
int error;
error = request_firmware(&fw, fw_name, dev);
if (error) {
dev_err(&client->dev, "unable to retrieve firmware %s: %d\n",
fw_name, error);
return error;
}
error = wdt87xx_do_update_firmware(client, fw, chunk_id);
release_firmware(fw);
return error ? error : 0;
}
static ssize_t config_csum_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct wdt87xx_data *wdt = i2c_get_clientdata(client);
u32 cfg_csum;
cfg_csum = wdt->param.xmls_id1;
cfg_csum = (cfg_csum << 16) | wdt->param.xmls_id2;
return scnprintf(buf, PAGE_SIZE, "%x\n", cfg_csum);
}
static ssize_t fw_version_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct wdt87xx_data *wdt = i2c_get_clientdata(client);
return scnprintf(buf, PAGE_SIZE, "%x\n", wdt->param.fw_id);
}
static ssize_t plat_id_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct wdt87xx_data *wdt = i2c_get_clientdata(client);
return scnprintf(buf, PAGE_SIZE, "%x\n", wdt->param.plat_id);
}
static ssize_t update_config_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int error;
error = wdt87xx_update_firmware(dev, WDT87XX_CFG_NAME, CHUNK_ID_CNFG);
return error ? error : count;
}
static ssize_t update_fw_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int error;
error = wdt87xx_update_firmware(dev, WDT87XX_FW_NAME, CHUNK_ID_FRWR);
return error ? error : count;
}
static void wdt87xx_report_contact(struct input_dev *input,
struct wdt87xx_sys_param *param,
u8 *buf)
{
int finger_id;
u32 x, y, w;
u8 p;
finger_id = (buf[FINGER_EV_V1_OFFSET_ID] >> 3) - 1;
if (finger_id < 0)
return;
if (!(buf[FINGER_EV_V1_OFFSET_ID] & 0x1))
return;
w = buf[FINGER_EV_V1_OFFSET_W];
w *= param->scaling_factor;
p = buf[FINGER_EV_V1_OFFSET_P];
x = get_unaligned_le16(buf + FINGER_EV_V1_OFFSET_X);
y = get_unaligned_le16(buf + FINGER_EV_V1_OFFSET_Y);
y = DIV_ROUND_CLOSEST(y * param->phy_h, param->phy_w);
if (x > param->max_x || y > param->max_y)
return;
dev_dbg(input->dev.parent, "tip on (%d), x(%d), y(%d)\n",
finger_id, x, y);
input_mt_slot(input, finger_id);
input_mt_report_slot_state(input, MT_TOOL_FINGER, 1);
input_report_abs(input, ABS_MT_TOUCH_MAJOR, w);
input_report_abs(input, ABS_MT_PRESSURE, p);
input_report_abs(input, ABS_MT_POSITION_X, x);
input_report_abs(input, ABS_MT_POSITION_Y, y);
}
static irqreturn_t wdt87xx_ts_interrupt(int irq, void *dev_id)
{
struct wdt87xx_data *wdt = dev_id;
struct i2c_client *client = wdt->client;
int i, fingers;
int error;
u8 raw_buf[WDT_V1_RAW_BUF_COUNT] = {0};
error = i2c_master_recv(client, raw_buf, WDT_V1_RAW_BUF_COUNT);
if (error < 0) {
dev_err(&client->dev, "read v1 raw data failed: %d\n", error);
goto irq_exit;
}
fingers = raw_buf[TOUCH_PK_V1_OFFSET_FNGR_NUM];
if (!fingers)
goto irq_exit;
for (i = 0; i < WDT_MAX_FINGER; i++)
wdt87xx_report_contact(wdt->input,
&wdt->param,
&raw_buf[TOUCH_PK_V1_OFFSET_EVENT +
i * FINGER_EV_V1_SIZE]);
input_mt_sync_frame(wdt->input);
input_sync(wdt->input);
irq_exit:
return IRQ_HANDLED;
}
static int wdt87xx_ts_create_input_device(struct wdt87xx_data *wdt)
{
struct device *dev = &wdt->client->dev;
struct input_dev *input;
unsigned int res = DIV_ROUND_CLOSEST(MAX_UNIT_AXIS, wdt->param.phy_w);
int error;
input = devm_input_allocate_device(dev);
if (!input) {
dev_err(dev, "failed to allocate input device\n");
return -ENOMEM;
}
wdt->input = input;
input->name = "WDT87xx Touchscreen";
input->id.bustype = BUS_I2C;
input->id.vendor = wdt->param.vendor_id;
input->id.product = wdt->param.product_id;
input->phys = wdt->phys;
input_set_abs_params(input, ABS_MT_POSITION_X, 0,
wdt->param.max_x, 0, 0);
input_set_abs_params(input, ABS_MT_POSITION_Y, 0,
wdt->param.max_y, 0, 0);
input_abs_set_res(input, ABS_MT_POSITION_X, res);
input_abs_set_res(input, ABS_MT_POSITION_Y, res);
input_set_abs_params(input, ABS_MT_TOUCH_MAJOR,
0, wdt->param.max_x, 0, 0);
input_set_abs_params(input, ABS_MT_PRESSURE, 0, 0xFF, 0, 0);
input_mt_init_slots(input, WDT_MAX_FINGER,
INPUT_MT_DIRECT | INPUT_MT_DROP_UNUSED);
error = input_register_device(input);
if (error) {
dev_err(dev, "failed to register input device: %d\n", error);
return error;
}
return 0;
}
static int wdt87xx_ts_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct wdt87xx_data *wdt;
int error;
dev_dbg(&client->dev, "adapter=%d, client irq: %d\n",
client->adapter->nr, client->irq);
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
return -ENXIO;
wdt = devm_kzalloc(&client->dev, sizeof(*wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
wdt->client = client;
mutex_init(&wdt->fw_mutex);
i2c_set_clientdata(client, wdt);
snprintf(wdt->phys, sizeof(wdt->phys), "i2c-%u-%04x/input0",
client->adapter->nr, client->addr);
error = wdt87xx_get_sysparam(client, &wdt->param);
if (error)
return error;
error = wdt87xx_ts_create_input_device(wdt);
if (error)
return error;
error = devm_request_threaded_irq(&client->dev, client->irq,
NULL, wdt87xx_ts_interrupt,
IRQF_ONESHOT,
client->name, wdt);
if (error) {
dev_err(&client->dev, "request irq failed: %d\n", error);
return error;
}
error = sysfs_create_group(&client->dev.kobj, &wdt87xx_attr_group);
if (error) {
dev_err(&client->dev, "create sysfs failed: %d\n", error);
return error;
}
return 0;
}
static int wdt87xx_ts_remove(struct i2c_client *client)
{
sysfs_remove_group(&client->dev.kobj, &wdt87xx_attr_group);
return 0;
}
static int __maybe_unused wdt87xx_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
int error;
disable_irq(client->irq);
error = wdt87xx_send_command(client, VND_CMD_STOP, MODE_IDLE);
if (error) {
enable_irq(client->irq);
dev_err(&client->dev,
"failed to stop device when suspending: %d\n",
error);
return error;
}
return 0;
}
static int __maybe_unused wdt87xx_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
int error;
mdelay(100);
error = wdt87xx_send_command(client, VND_CMD_START, 0);
if (error)
dev_err(&client->dev,
"failed to start device when resuming: %d\n",
error);
enable_irq(client->irq);
return 0;
}
