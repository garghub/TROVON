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
for (retry = 0; retry < 32; retry++) {
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
int drm_dp_link_power_down(struct drm_dp_aux *aux, struct drm_dp_link *link)
{
u8 value;
int err;
if (link->revision < 0x11)
return 0;
err = drm_dp_dpcd_readb(aux, DP_SET_POWER, &value);
if (err < 0)
return err;
value &= ~DP_SET_POWER_MASK;
value |= DP_SET_POWER_D3;
err = drm_dp_dpcd_writeb(aux, DP_SET_POWER, value);
if (err < 0)
return err;
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
unsigned int retry, defer_i2c;
int ret;
for (retry = 0, defer_i2c = 0; retry < (7 + defer_i2c); retry++) {
mutex_lock(&aux->hw_mutex);
ret = aux->transfer(aux, msg);
mutex_unlock(&aux->hw_mutex);
if (ret < 0) {
if (ret == -EBUSY)
continue;
DRM_DEBUG_KMS("transaction failed: %d\n", ret);
return ret;
}
switch (msg->reply & DP_AUX_NATIVE_REPLY_MASK) {
case DP_AUX_NATIVE_REPLY_ACK:
break;
case DP_AUX_NATIVE_REPLY_NACK:
DRM_DEBUG_KMS("native nack (result=%d, size=%zu)\n", ret, msg->size);
return -EREMOTEIO;
case DP_AUX_NATIVE_REPLY_DEFER:
DRM_DEBUG_KMS("native defer\n");
usleep_range(500, 600);
continue;
default:
DRM_ERROR("invalid native reply %#04x\n", msg->reply);
return -EREMOTEIO;
}
switch (msg->reply & DP_AUX_I2C_REPLY_MASK) {
case DP_AUX_I2C_REPLY_ACK:
return ret;
case DP_AUX_I2C_REPLY_NACK:
DRM_DEBUG_KMS("I2C nack (result=%d, size=%zu\n", ret, msg->size);
aux->i2c_nack_count++;
return -EREMOTEIO;
case DP_AUX_I2C_REPLY_DEFER:
DRM_DEBUG_KMS("I2C defer\n");
aux->i2c_defer_count++;
if (defer_i2c < 7)
defer_i2c++;
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
static int drm_dp_i2c_drain_msg(struct drm_dp_aux *aux, struct drm_dp_aux_msg *orig_msg)
{
int err, ret = orig_msg->size;
struct drm_dp_aux_msg msg = *orig_msg;
while (msg.size > 0) {
err = drm_dp_i2c_do_msg(aux, &msg);
if (err <= 0)
return err == 0 ? -EPROTO : err;
if (err < msg.size && err < ret) {
DRM_DEBUG_KMS("Partial I2C reply: requested %zu bytes got %d bytes\n",
msg.size, err);
ret = err;
}
msg.size -= err;
msg.buffer += err;
}
return ret;
}
static int drm_dp_i2c_xfer(struct i2c_adapter *adapter, struct i2c_msg *msgs,
int num)
{
struct drm_dp_aux *aux = adapter->algo_data;
unsigned int i, j;
unsigned transfer_size;
struct drm_dp_aux_msg msg;
int err = 0;
dp_aux_i2c_transfer_size = clamp(dp_aux_i2c_transfer_size, 1, DP_AUX_MAX_PAYLOAD_BYTES);
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
transfer_size = dp_aux_i2c_transfer_size;
for (j = 0; j < msgs[i].len; j += msg.size) {
msg.buffer = msgs[i].buf + j;
msg.size = min(transfer_size, msgs[i].len - j);
err = drm_dp_i2c_drain_msg(aux, &msg);
if (err < 0)
break;
transfer_size = err;
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
