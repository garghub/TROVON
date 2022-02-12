static int
i2c_algo_dp_aux_transaction(struct i2c_adapter *adapter, int mode,
uint8_t write_byte, uint8_t *read_byte)
{
struct i2c_algo_dp_aux_data *algo_data = adapter->algo_data;
int ret;
ret = (*algo_data->aux_ch)(adapter, mode,
write_byte, read_byte);
return ret;
}
static int
i2c_algo_dp_aux_address(struct i2c_adapter *adapter, u16 address, bool reading)
{
struct i2c_algo_dp_aux_data *algo_data = adapter->algo_data;
int mode = MODE_I2C_START;
int ret;
if (reading)
mode |= MODE_I2C_READ;
else
mode |= MODE_I2C_WRITE;
algo_data->address = address;
algo_data->running = true;
ret = i2c_algo_dp_aux_transaction(adapter, mode, 0, NULL);
return ret;
}
static void
i2c_algo_dp_aux_stop(struct i2c_adapter *adapter, bool reading)
{
struct i2c_algo_dp_aux_data *algo_data = adapter->algo_data;
int mode = MODE_I2C_STOP;
if (reading)
mode |= MODE_I2C_READ;
else
mode |= MODE_I2C_WRITE;
if (algo_data->running) {
(void) i2c_algo_dp_aux_transaction(adapter, mode, 0, NULL);
algo_data->running = false;
}
}
static int
i2c_algo_dp_aux_put_byte(struct i2c_adapter *adapter, u8 byte)
{
struct i2c_algo_dp_aux_data *algo_data = adapter->algo_data;
int ret;
if (!algo_data->running)
return -EIO;
ret = i2c_algo_dp_aux_transaction(adapter, MODE_I2C_WRITE, byte, NULL);
return ret;
}
static int
i2c_algo_dp_aux_get_byte(struct i2c_adapter *adapter, u8 *byte_ret)
{
struct i2c_algo_dp_aux_data *algo_data = adapter->algo_data;
int ret;
if (!algo_data->running)
return -EIO;
ret = i2c_algo_dp_aux_transaction(adapter, MODE_I2C_READ, 0, byte_ret);
return ret;
}
static int
i2c_algo_dp_aux_xfer(struct i2c_adapter *adapter,
struct i2c_msg *msgs,
int num)
{
int ret = 0;
bool reading = false;
int m;
int b;
for (m = 0; m < num; m++) {
u16 len = msgs[m].len;
u8 *buf = msgs[m].buf;
reading = (msgs[m].flags & I2C_M_RD) != 0;
ret = i2c_algo_dp_aux_address(adapter, msgs[m].addr, reading);
if (ret < 0)
break;
if (reading) {
for (b = 0; b < len; b++) {
ret = i2c_algo_dp_aux_get_byte(adapter, &buf[b]);
if (ret < 0)
break;
}
} else {
for (b = 0; b < len; b++) {
ret = i2c_algo_dp_aux_put_byte(adapter, buf[b]);
if (ret < 0)
break;
}
}
if (ret < 0)
break;
}
if (ret >= 0)
ret = num;
i2c_algo_dp_aux_stop(adapter, reading);
DRM_DEBUG_KMS("dp_aux_xfer return %d\n", ret);
return ret;
}
static u32
i2c_algo_dp_aux_functionality(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL |
I2C_FUNC_SMBUS_READ_BLOCK_DATA |
I2C_FUNC_SMBUS_BLOCK_PROC_CALL |
I2C_FUNC_10BIT_ADDR;
}
static void
i2c_dp_aux_reset_bus(struct i2c_adapter *adapter)
{
(void) i2c_algo_dp_aux_address(adapter, 0, false);
(void) i2c_algo_dp_aux_stop(adapter, false);
}
static int
i2c_dp_aux_prepare_bus(struct i2c_adapter *adapter)
{
adapter->algo = &i2c_dp_aux_algo;
adapter->retries = 3;
i2c_dp_aux_reset_bus(adapter);
return 0;
}
int
i2c_dp_aux_add_bus(struct i2c_adapter *adapter)
{
int error;
error = i2c_dp_aux_prepare_bus(adapter);
if (error)
return error;
error = i2c_add_adapter(adapter);
return error;
}
static u8 dp_link_status(const u8 link_status[DP_LINK_STATUS_SIZE], int r)
{
return link_status[r - DP_LANE0_1_STATUS];
}
static u8 dp_get_lane_status(const u8 link_status[DP_LINK_STATUS_SIZE],
int lane)
{
int i = DP_LANE0_1_STATUS + (lane >> 1);
int s = (lane & 1) * 4;
u8 l = dp_link_status(link_status, i);
return (l >> s) & 0xf;
}
bool drm_dp_channel_eq_ok(const u8 link_status[DP_LINK_STATUS_SIZE],
int lane_count)
{
u8 lane_align;
u8 lane_status;
int lane;
lane_align = dp_link_status(link_status,
DP_LANE_ALIGN_STATUS_UPDATED);
if ((lane_align & DP_INTERLANE_ALIGN_DONE) == 0)
return false;
for (lane = 0; lane < lane_count; lane++) {
lane_status = dp_get_lane_status(link_status, lane);
if ((lane_status & DP_CHANNEL_EQ_BITS) != DP_CHANNEL_EQ_BITS)
return false;
}
return true;
}
bool drm_dp_clock_recovery_ok(const u8 link_status[DP_LINK_STATUS_SIZE],
int lane_count)
{
int lane;
u8 lane_status;
for (lane = 0; lane < lane_count; lane++) {
lane_status = dp_get_lane_status(link_status, lane);
if ((lane_status & DP_LANE_CR_DONE) == 0)
return false;
}
return true;
}
u8 drm_dp_get_adjust_request_voltage(const u8 link_status[DP_LINK_STATUS_SIZE],
int lane)
{
int i = DP_ADJUST_REQUEST_LANE0_1 + (lane >> 1);
int s = ((lane & 1) ?
DP_ADJUST_VOLTAGE_SWING_LANE1_SHIFT :
DP_ADJUST_VOLTAGE_SWING_LANE0_SHIFT);
u8 l = dp_link_status(link_status, i);
return ((l >> s) & 0x3) << DP_TRAIN_VOLTAGE_SWING_SHIFT;
}
u8 drm_dp_get_adjust_request_pre_emphasis(const u8 link_status[DP_LINK_STATUS_SIZE],
int lane)
{
int i = DP_ADJUST_REQUEST_LANE0_1 + (lane >> 1);
int s = ((lane & 1) ?
DP_ADJUST_PRE_EMPHASIS_LANE1_SHIFT :
DP_ADJUST_PRE_EMPHASIS_LANE0_SHIFT);
u8 l = dp_link_status(link_status, i);
return ((l >> s) & 0x3) << DP_TRAIN_PRE_EMPHASIS_SHIFT;
}
void drm_dp_link_train_clock_recovery_delay(const u8 dpcd[DP_RECEIVER_CAP_SIZE]) {
if (dpcd[DP_TRAINING_AUX_RD_INTERVAL] == 0)
udelay(100);
else
mdelay(dpcd[DP_TRAINING_AUX_RD_INTERVAL] * 4);
}
void drm_dp_link_train_channel_eq_delay(const u8 dpcd[DP_RECEIVER_CAP_SIZE]) {
if (dpcd[DP_TRAINING_AUX_RD_INTERVAL] == 0)
udelay(400);
else
mdelay(dpcd[DP_TRAINING_AUX_RD_INTERVAL] * 4);
}
u8 drm_dp_link_rate_to_bw_code(int link_rate)
{
switch (link_rate) {
case 162000:
default:
return DP_LINK_BW_1_62;
case 270000:
return DP_LINK_BW_2_7;
case 540000:
return DP_LINK_BW_5_4;
}
}
int drm_dp_bw_code_to_link_rate(u8 link_bw)
{
switch (link_bw) {
case DP_LINK_BW_1_62:
default:
return 162000;
case DP_LINK_BW_2_7:
return 270000;
case DP_LINK_BW_5_4:
return 540000;
}
}
static int drm_dp_dpcd_access(struct drm_dp_aux *aux, u8 request,
unsigned int offset, void *buffer, size_t size)
{
struct drm_dp_aux_msg msg;
unsigned int retry;
int err;
memset(&msg, 0, sizeof(msg));
msg.address = offset;
msg.request = request;
msg.buffer = buffer;
msg.size = size;
for (retry = 0; retry < 7; retry++) {
mutex_lock(&aux->hw_mutex);
err = aux->transfer(aux, &msg);
mutex_unlock(&aux->hw_mutex);
if (err < 0) {
if (err == -EBUSY)
continue;
return err;
}
switch (msg.reply & DP_AUX_NATIVE_REPLY_MASK) {
case DP_AUX_NATIVE_REPLY_ACK:
if (err < size)
return -EPROTO;
return err;
case DP_AUX_NATIVE_REPLY_NACK:
return -EIO;
case DP_AUX_NATIVE_REPLY_DEFER:
usleep_range(400, 500);
break;
}
}
DRM_DEBUG_KMS("too many retries, giving up\n");
return -EIO;
}
ssize_t drm_dp_dpcd_read(struct drm_dp_aux *aux, unsigned int offset,
void *buffer, size_t size)
{
return drm_dp_dpcd_access(aux, DP_AUX_NATIVE_READ, offset, buffer,
size);
}
ssize_t drm_dp_dpcd_write(struct drm_dp_aux *aux, unsigned int offset,
void *buffer, size_t size)
{
return drm_dp_dpcd_access(aux, DP_AUX_NATIVE_WRITE, offset, buffer,
size);
}
int drm_dp_dpcd_read_link_status(struct drm_dp_aux *aux,
u8 status[DP_LINK_STATUS_SIZE])
{
return drm_dp_dpcd_read(aux, DP_LANE0_1_STATUS, status,
DP_LINK_STATUS_SIZE);
}
int drm_dp_link_probe(struct drm_dp_aux *aux, struct drm_dp_link *link)
{
u8 values[3];
int err;
memset(link, 0, sizeof(*link));
err = drm_dp_dpcd_read(aux, DP_DPCD_REV, values, sizeof(values));
if (err < 0)
return err;
link->revision = values[0];
link->rate = drm_dp_bw_code_to_link_rate(values[1]);
link->num_lanes = values[2] & DP_MAX_LANE_COUNT_MASK;
if (values[2] & DP_ENHANCED_FRAME_CAP)
link->capabilities |= DP_LINK_CAP_ENHANCED_FRAMING;
return 0;
}
int drm_dp_link_power_up(struct drm_dp_aux *aux, struct drm_dp_link *link)
{
u8 value;
int err;
if (link->revision < 0x11)
return 0;
err = drm_dp_dpcd_readb(aux, DP_SET_POWER, &value);
if (err < 0)
return err;
value &= ~DP_SET_POWER_MASK;
value |= DP_SET_POWER_D0;
err = drm_dp_dpcd_writeb(aux, DP_SET_POWER, value);
if (err < 0)
return err;
usleep_range(1000, 2000);
return 0;
}
int drm_dp_link_configure(struct drm_dp_aux *aux, struct drm_dp_link *link)
{
u8 values[2];
int err;
values[0] = drm_dp_link_rate_to_bw_code(link->rate);
values[1] = link->num_lanes;
if (link->capabilities & DP_LINK_CAP_ENHANCED_FRAMING)
values[1] |= DP_LANE_COUNT_ENHANCED_FRAME_EN;
err = drm_dp_dpcd_write(aux, DP_LINK_BW_SET, values, sizeof(values));
if (err < 0)
return err;
return 0;
}
static u32 drm_dp_i2c_functionality(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL |
I2C_FUNC_SMBUS_READ_BLOCK_DATA |
I2C_FUNC_SMBUS_BLOCK_PROC_CALL |
I2C_FUNC_10BIT_ADDR;
}
static int drm_dp_i2c_do_msg(struct drm_dp_aux *aux, struct drm_dp_aux_msg *msg)
{
unsigned int retry;
int err;
for (retry = 0; retry < 7; retry++) {
mutex_lock(&aux->hw_mutex);
err = aux->transfer(aux, msg);
mutex_unlock(&aux->hw_mutex);
if (err < 0) {
if (err == -EBUSY)
continue;
DRM_DEBUG_KMS("transaction failed: %d\n", err);
return err;
}
switch (msg->reply & DP_AUX_NATIVE_REPLY_MASK) {
case DP_AUX_NATIVE_REPLY_ACK:
break;
case DP_AUX_NATIVE_REPLY_NACK:
DRM_DEBUG_KMS("native nack\n");
return -EREMOTEIO;
case DP_AUX_NATIVE_REPLY_DEFER:
DRM_DEBUG_KMS("native defer");
usleep_range(500, 600);
continue;
default:
DRM_ERROR("invalid native reply %#04x\n", msg->reply);
return -EREMOTEIO;
}
switch (msg->reply & DP_AUX_I2C_REPLY_MASK) {
case DP_AUX_I2C_REPLY_ACK:
if (err < msg->size)
return -EPROTO;
return 0;
case DP_AUX_I2C_REPLY_NACK:
DRM_DEBUG_KMS("I2C nack\n");
return -EREMOTEIO;
case DP_AUX_I2C_REPLY_DEFER:
DRM_DEBUG_KMS("I2C defer\n");
usleep_range(400, 500);
continue;
default:
DRM_ERROR("invalid I2C reply %#04x\n", msg->reply);
return -EREMOTEIO;
}
}
DRM_DEBUG_KMS("too many retries, giving up\n");
return -EREMOTEIO;
}
static int drm_dp_i2c_xfer(struct i2c_adapter *adapter, struct i2c_msg *msgs,
int num)
{
struct drm_dp_aux *aux = adapter->algo_data;
unsigned int i, j;
struct drm_dp_aux_msg msg;
int err = 0;
memset(&msg, 0, sizeof(msg));
for (i = 0; i < num; i++) {
msg.address = msgs[i].addr;
msg.request = (msgs[i].flags & I2C_M_RD) ?
DP_AUX_I2C_READ :
DP_AUX_I2C_WRITE;
msg.request |= DP_AUX_I2C_MOT;
msg.buffer = NULL;
msg.size = 0;
err = drm_dp_i2c_do_msg(aux, &msg);
if (err < 0)
break;
for (j = 0; j < msgs[i].len; j++) {
msg.buffer = msgs[i].buf + j;
msg.size = 1;
err = drm_dp_i2c_do_msg(aux, &msg);
if (err < 0)
break;
}
if (err < 0)
break;
}
if (err >= 0)
err = num;
msg.request &= ~DP_AUX_I2C_MOT;
msg.buffer = NULL;
msg.size = 0;
(void)drm_dp_i2c_do_msg(aux, &msg);
return err;
}
int drm_dp_aux_register(struct drm_dp_aux *aux)
{
mutex_init(&aux->hw_mutex);
aux->ddc.algo = &drm_dp_i2c_algo;
aux->ddc.algo_data = aux;
aux->ddc.retries = 3;
aux->ddc.class = I2C_CLASS_DDC;
aux->ddc.owner = THIS_MODULE;
aux->ddc.dev.parent = aux->dev;
aux->ddc.dev.of_node = aux->dev->of_node;
strlcpy(aux->ddc.name, aux->name ? aux->name : dev_name(aux->dev),
sizeof(aux->ddc.name));
return i2c_add_adapter(&aux->ddc);
}
void drm_dp_aux_unregister(struct drm_dp_aux *aux)
{
i2c_del_adapter(&aux->ddc);
}
