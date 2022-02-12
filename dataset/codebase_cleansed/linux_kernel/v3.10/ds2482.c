static inline u8 ds2482_calculate_config(u8 conf)
{
return conf | ((~conf & 0x0f) << 4);
}
static inline int ds2482_select_register(struct ds2482_data *pdev, u8 read_ptr)
{
if (pdev->read_prt != read_ptr) {
if (i2c_smbus_write_byte_data(pdev->client,
DS2482_CMD_SET_READ_PTR,
read_ptr) < 0)
return -1;
pdev->read_prt = read_ptr;
}
return 0;
}
static inline int ds2482_send_cmd(struct ds2482_data *pdev, u8 cmd)
{
if (i2c_smbus_write_byte(pdev->client, cmd) < 0)
return -1;
pdev->read_prt = DS2482_PTR_CODE_STATUS;
return 0;
}
static inline int ds2482_send_cmd_data(struct ds2482_data *pdev,
u8 cmd, u8 byte)
{
if (i2c_smbus_write_byte_data(pdev->client, cmd, byte) < 0)
return -1;
pdev->read_prt = (cmd != DS2482_CMD_WRITE_CONFIG) ?
DS2482_PTR_CODE_STATUS : DS2482_PTR_CODE_CONFIG;
return 0;
}
static int ds2482_wait_1wire_idle(struct ds2482_data *pdev)
{
int temp = -1;
int retries = 0;
if (!ds2482_select_register(pdev, DS2482_PTR_CODE_STATUS)) {
do {
temp = i2c_smbus_read_byte(pdev->client);
} while ((temp >= 0) && (temp & DS2482_REG_STS_1WB) &&
(++retries < DS2482_WAIT_IDLE_TIMEOUT));
}
if (retries >= DS2482_WAIT_IDLE_TIMEOUT)
printk(KERN_ERR "%s: timeout on channel %d\n",
__func__, pdev->channel);
return temp;
}
static int ds2482_set_channel(struct ds2482_data *pdev, u8 channel)
{
if (i2c_smbus_write_byte_data(pdev->client, DS2482_CMD_CHANNEL_SELECT,
ds2482_chan_wr[channel]) < 0)
return -1;
pdev->read_prt = DS2482_PTR_CODE_CHANNEL;
pdev->channel = -1;
if (i2c_smbus_read_byte(pdev->client) == ds2482_chan_rd[channel]) {
pdev->channel = channel;
return 0;
}
return -1;
}
static u8 ds2482_w1_touch_bit(void *data, u8 bit)
{
struct ds2482_w1_chan *pchan = data;
struct ds2482_data *pdev = pchan->pdev;
int status = -1;
mutex_lock(&pdev->access_lock);
ds2482_wait_1wire_idle(pdev);
if (pdev->w1_count > 1)
ds2482_set_channel(pdev, pchan->channel);
if (!ds2482_send_cmd_data(pdev, DS2482_CMD_1WIRE_SINGLE_BIT,
bit ? 0xFF : 0))
status = ds2482_wait_1wire_idle(pdev);
mutex_unlock(&pdev->access_lock);
return (status & DS2482_REG_STS_SBR) ? 1 : 0;
}
static u8 ds2482_w1_triplet(void *data, u8 dbit)
{
struct ds2482_w1_chan *pchan = data;
struct ds2482_data *pdev = pchan->pdev;
int status = (3 << 5);
mutex_lock(&pdev->access_lock);
ds2482_wait_1wire_idle(pdev);
if (pdev->w1_count > 1)
ds2482_set_channel(pdev, pchan->channel);
if (!ds2482_send_cmd_data(pdev, DS2482_CMD_1WIRE_TRIPLET,
dbit ? 0xFF : 0))
status = ds2482_wait_1wire_idle(pdev);
mutex_unlock(&pdev->access_lock);
return (status >> 5);
}
static void ds2482_w1_write_byte(void *data, u8 byte)
{
struct ds2482_w1_chan *pchan = data;
struct ds2482_data *pdev = pchan->pdev;
mutex_lock(&pdev->access_lock);
ds2482_wait_1wire_idle(pdev);
if (pdev->w1_count > 1)
ds2482_set_channel(pdev, pchan->channel);
ds2482_send_cmd_data(pdev, DS2482_CMD_1WIRE_WRITE_BYTE, byte);
mutex_unlock(&pdev->access_lock);
}
static u8 ds2482_w1_read_byte(void *data)
{
struct ds2482_w1_chan *pchan = data;
struct ds2482_data *pdev = pchan->pdev;
int result;
mutex_lock(&pdev->access_lock);
ds2482_wait_1wire_idle(pdev);
if (pdev->w1_count > 1)
ds2482_set_channel(pdev, pchan->channel);
ds2482_send_cmd(pdev, DS2482_CMD_1WIRE_READ_BYTE);
ds2482_wait_1wire_idle(pdev);
ds2482_select_register(pdev, DS2482_PTR_CODE_DATA);
result = i2c_smbus_read_byte(pdev->client);
mutex_unlock(&pdev->access_lock);
return result;
}
static u8 ds2482_w1_reset_bus(void *data)
{
struct ds2482_w1_chan *pchan = data;
struct ds2482_data *pdev = pchan->pdev;
int err;
u8 retval = 1;
mutex_lock(&pdev->access_lock);
ds2482_wait_1wire_idle(pdev);
if (pdev->w1_count > 1)
ds2482_set_channel(pdev, pchan->channel);
err = ds2482_send_cmd(pdev, DS2482_CMD_1WIRE_RESET);
if (err >= 0) {
err = ds2482_wait_1wire_idle(pdev);
retval = !(err & DS2482_REG_STS_PPD);
if (err & DS2482_REG_STS_RST)
ds2482_send_cmd_data(pdev, DS2482_CMD_WRITE_CONFIG,
ds2482_calculate_config(0x00));
}
mutex_unlock(&pdev->access_lock);
return retval;
}
static u8 ds2482_w1_set_pullup(void *data, int delay)
{
struct ds2482_w1_chan *pchan = data;
struct ds2482_data *pdev = pchan->pdev;
u8 retval = 1;
if (delay) {
ds2482_wait_1wire_idle(pdev);
retval = ds2482_send_cmd_data(pdev, DS2482_CMD_WRITE_CONFIG,
ds2482_calculate_config(DS2482_REG_CFG_SPU |
DS2482_REG_CFG_APU));
ds2482_wait_1wire_idle(pdev);
}
return retval;
}
static int ds2482_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ds2482_data *data;
int err = -ENODEV;
int temp1;
int idx;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_WRITE_BYTE_DATA |
I2C_FUNC_SMBUS_BYTE))
return -ENODEV;
if (!(data = kzalloc(sizeof(struct ds2482_data), GFP_KERNEL))) {
err = -ENOMEM;
goto exit;
}
data->client = client;
i2c_set_clientdata(client, data);
if (ds2482_send_cmd(data, DS2482_CMD_RESET) < 0) {
dev_warn(&client->dev, "DS2482 reset failed.\n");
goto exit_free;
}
ndelay(525);
temp1 = i2c_smbus_read_byte(client);
if (temp1 != (DS2482_REG_STS_LL | DS2482_REG_STS_RST)) {
dev_warn(&client->dev, "DS2482 reset status "
"0x%02X - not a DS2482\n", temp1);
goto exit_free;
}
data->w1_count = 1;
if (ds2482_set_channel(data, 7) == 0)
data->w1_count = 8;
ds2482_send_cmd_data(data, DS2482_CMD_WRITE_CONFIG,
ds2482_calculate_config(0x00));
mutex_init(&data->access_lock);
for (idx = 0; idx < data->w1_count; idx++) {
data->w1_ch[idx].pdev = data;
data->w1_ch[idx].channel = idx;
data->w1_ch[idx].w1_bm.data = &data->w1_ch[idx];
data->w1_ch[idx].w1_bm.read_byte = ds2482_w1_read_byte;
data->w1_ch[idx].w1_bm.write_byte = ds2482_w1_write_byte;
data->w1_ch[idx].w1_bm.touch_bit = ds2482_w1_touch_bit;
data->w1_ch[idx].w1_bm.triplet = ds2482_w1_triplet;
data->w1_ch[idx].w1_bm.reset_bus = ds2482_w1_reset_bus;
data->w1_ch[idx].w1_bm.set_pullup = ds2482_w1_set_pullup;
err = w1_add_master_device(&data->w1_ch[idx].w1_bm);
if (err) {
data->w1_ch[idx].pdev = NULL;
goto exit_w1_remove;
}
}
return 0;
exit_w1_remove:
for (idx = 0; idx < data->w1_count; idx++) {
if (data->w1_ch[idx].pdev != NULL)
w1_remove_master_device(&data->w1_ch[idx].w1_bm);
}
exit_free:
kfree(data);
exit:
return err;
}
static int ds2482_remove(struct i2c_client *client)
{
struct ds2482_data *data = i2c_get_clientdata(client);
int idx;
for (idx = 0; idx < data->w1_count; idx++) {
if (data->w1_ch[idx].pdev != NULL)
w1_remove_master_device(&data->w1_ch[idx].w1_bm);
}
kfree(data);
return 0;
}
