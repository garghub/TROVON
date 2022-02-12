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
unsigned int retry, native_reply;
int err = 0, ret = 0;
memset(&msg, 0, sizeof(msg));
msg.address = offset;
msg.request = request;
msg.buffer = buffer;
msg.size = size;
mutex_lock(&aux->hw_mutex);
for (retry = 0; retry < 32; retry++) {
if (ret != 0 && ret != -ETIMEDOUT) {
usleep_range(AUX_RETRY_INTERVAL,
AUX_RETRY_INTERVAL + 100);
}
ret = aux->transfer(aux, &msg);
if (ret >= 0) {
native_reply = msg.reply & DP_AUX_NATIVE_REPLY_MASK;
if (native_reply == DP_AUX_NATIVE_REPLY_ACK) {
if (ret == size)
goto unlock;
ret = -EPROTO;
} else
ret = -EIO;
}
if (!err)
err = ret;
}
DRM_DEBUG_KMS("Too many retries, giving up. First error: %d\n", err);
ret = err;
unlock:
mutex_unlock(&aux->hw_mutex);
return ret;
}
ssize_t drm_dp_dpcd_read(struct drm_dp_aux *aux, unsigned int offset,
void *buffer, size_t size)
{
int ret;
ret = drm_dp_dpcd_access(aux, DP_AUX_NATIVE_READ, DP_DPCD_REV, buffer,
1);
if (ret != 1)
return ret;
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
int drm_dp_downstream_max_clock(const u8 dpcd[DP_RECEIVER_CAP_SIZE],
const u8 port_cap[4])
{
int type = port_cap[0] & DP_DS_PORT_TYPE_MASK;
bool detailed_cap_info = dpcd[DP_DOWNSTREAMPORT_PRESENT] &
DP_DETAILED_CAP_INFO_AVAILABLE;
if (!detailed_cap_info)
return 0;
switch (type) {
case DP_DS_PORT_TYPE_VGA:
return port_cap[1] * 8 * 1000;
case DP_DS_PORT_TYPE_DVI:
case DP_DS_PORT_TYPE_HDMI:
case DP_DS_PORT_TYPE_DP_DUALMODE:
return port_cap[1] * 2500;
default:
return 0;
}
}
int drm_dp_downstream_max_bpc(const u8 dpcd[DP_RECEIVER_CAP_SIZE],
const u8 port_cap[4])
{
int type = port_cap[0] & DP_DS_PORT_TYPE_MASK;
bool detailed_cap_info = dpcd[DP_DOWNSTREAMPORT_PRESENT] &
DP_DETAILED_CAP_INFO_AVAILABLE;
int bpc;
if (!detailed_cap_info)
return 0;
switch (type) {
case DP_DS_PORT_TYPE_VGA:
case DP_DS_PORT_TYPE_DVI:
case DP_DS_PORT_TYPE_HDMI:
case DP_DS_PORT_TYPE_DP_DUALMODE:
bpc = port_cap[2] & DP_DS_MAX_BPC_MASK;
switch (bpc) {
case DP_DS_8BPC:
return 8;
case DP_DS_10BPC:
return 10;
case DP_DS_12BPC:
return 12;
case DP_DS_16BPC:
return 16;
}
default:
return 0;
}
}
int drm_dp_downstream_id(struct drm_dp_aux *aux, char id[6])
{
return drm_dp_dpcd_read(aux, DP_BRANCH_ID, id, 6);
}
void drm_dp_downstream_debug(struct seq_file *m,
const u8 dpcd[DP_RECEIVER_CAP_SIZE],
const u8 port_cap[4], struct drm_dp_aux *aux)
{
bool detailed_cap_info = dpcd[DP_DOWNSTREAMPORT_PRESENT] &
DP_DETAILED_CAP_INFO_AVAILABLE;
int clk;
int bpc;
char id[7];
int len;
uint8_t rev[2];
int type = port_cap[0] & DP_DS_PORT_TYPE_MASK;
bool branch_device = dpcd[DP_DOWNSTREAMPORT_PRESENT] &
DP_DWN_STRM_PORT_PRESENT;
seq_printf(m, "\tDP branch device present: %s\n",
branch_device ? "yes" : "no");
if (!branch_device)
return;
switch (type) {
case DP_DS_PORT_TYPE_DP:
seq_puts(m, "\t\tType: DisplayPort\n");
break;
case DP_DS_PORT_TYPE_VGA:
seq_puts(m, "\t\tType: VGA\n");
break;
case DP_DS_PORT_TYPE_DVI:
seq_puts(m, "\t\tType: DVI\n");
break;
case DP_DS_PORT_TYPE_HDMI:
seq_puts(m, "\t\tType: HDMI\n");
break;
case DP_DS_PORT_TYPE_NON_EDID:
seq_puts(m, "\t\tType: others without EDID support\n");
break;
case DP_DS_PORT_TYPE_DP_DUALMODE:
seq_puts(m, "\t\tType: DP++\n");
break;
case DP_DS_PORT_TYPE_WIRELESS:
seq_puts(m, "\t\tType: Wireless\n");
break;
default:
seq_puts(m, "\t\tType: N/A\n");
}
memset(id, 0, sizeof(id));
drm_dp_downstream_id(aux, id);
seq_printf(m, "\t\tID: %s\n", id);
len = drm_dp_dpcd_read(aux, DP_BRANCH_HW_REV, &rev[0], 1);
if (len > 0)
seq_printf(m, "\t\tHW: %d.%d\n",
(rev[0] & 0xf0) >> 4, rev[0] & 0xf);
len = drm_dp_dpcd_read(aux, DP_BRANCH_SW_REV, rev, 2);
if (len > 0)
seq_printf(m, "\t\tSW: %d.%d\n", rev[0], rev[1]);
if (detailed_cap_info) {
clk = drm_dp_downstream_max_clock(dpcd, port_cap);
if (clk > 0) {
if (type == DP_DS_PORT_TYPE_VGA)
seq_printf(m, "\t\tMax dot clock: %d kHz\n", clk);
else
seq_printf(m, "\t\tMax TMDS clock: %d kHz\n", clk);
}
bpc = drm_dp_downstream_max_bpc(dpcd, port_cap);
if (bpc > 0)
seq_printf(m, "\t\tMax bpc: %d\n", bpc);
}
}
static u32 drm_dp_i2c_functionality(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL |
I2C_FUNC_SMBUS_READ_BLOCK_DATA |
I2C_FUNC_SMBUS_BLOCK_PROC_CALL |
I2C_FUNC_10BIT_ADDR;
}
static void drm_dp_i2c_msg_write_status_update(struct drm_dp_aux_msg *msg)
{
if ((msg->request & ~DP_AUX_I2C_MOT) == DP_AUX_I2C_WRITE) {
msg->request &= DP_AUX_I2C_MOT;
msg->request |= DP_AUX_I2C_WRITE_STATUS_UPDATE;
}
}
static int drm_dp_aux_req_duration(const struct drm_dp_aux_msg *msg)
{
int len = AUX_PRECHARGE_LEN + AUX_SYNC_LEN + AUX_STOP_LEN +
AUX_CMD_LEN + AUX_ADDRESS_LEN + AUX_LENGTH_LEN;
if ((msg->request & DP_AUX_I2C_READ) == 0)
len += msg->size * 8;
return len;
}
static int drm_dp_aux_reply_duration(const struct drm_dp_aux_msg *msg)
{
int len = AUX_PRECHARGE_LEN + AUX_SYNC_LEN + AUX_STOP_LEN +
AUX_CMD_LEN + AUX_REPLY_PAD_LEN;
if (msg->request & DP_AUX_I2C_READ)
len += msg->size * 8;
return len;
}
static int drm_dp_i2c_msg_duration(const struct drm_dp_aux_msg *msg,
int i2c_speed_khz)
{
return DIV_ROUND_UP((I2C_START_LEN + I2C_ADDR_LEN +
msg->size * I2C_DATA_LEN +
I2C_STOP_LEN) * 1000, i2c_speed_khz);
}
static int drm_dp_i2c_retry_count(const struct drm_dp_aux_msg *msg,
int i2c_speed_khz)
{
int aux_time_us = drm_dp_aux_req_duration(msg) +
drm_dp_aux_reply_duration(msg);
int i2c_time_us = drm_dp_i2c_msg_duration(msg, i2c_speed_khz);
return DIV_ROUND_UP(i2c_time_us, aux_time_us + AUX_RETRY_INTERVAL);
}
static int drm_dp_i2c_do_msg(struct drm_dp_aux *aux, struct drm_dp_aux_msg *msg)
{
unsigned int retry, defer_i2c;
int ret;
int max_retries = max(7, drm_dp_i2c_retry_count(msg, dp_aux_i2c_speed_khz));
for (retry = 0, defer_i2c = 0; retry < (max_retries + defer_i2c); retry++) {
ret = aux->transfer(aux, msg);
if (ret < 0) {
if (ret == -EBUSY)
continue;
if (ret == -ETIMEDOUT)
DRM_DEBUG_KMS_RATELIMITED("transaction timed out\n");
else
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
usleep_range(AUX_RETRY_INTERVAL, AUX_RETRY_INTERVAL + 100);
continue;
default:
DRM_ERROR("invalid native reply %#04x\n", msg->reply);
return -EREMOTEIO;
}
switch (msg->reply & DP_AUX_I2C_REPLY_MASK) {
case DP_AUX_I2C_REPLY_ACK:
if (ret != msg->size)
drm_dp_i2c_msg_write_status_update(msg);
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
usleep_range(AUX_RETRY_INTERVAL, AUX_RETRY_INTERVAL + 100);
drm_dp_i2c_msg_write_status_update(msg);
continue;
default:
DRM_ERROR("invalid I2C reply %#04x\n", msg->reply);
return -EREMOTEIO;
}
}
DRM_DEBUG_KMS("too many retries, giving up\n");
return -EREMOTEIO;
}
static void drm_dp_i2c_msg_set_request(struct drm_dp_aux_msg *msg,
const struct i2c_msg *i2c_msg)
{
msg->request = (i2c_msg->flags & I2C_M_RD) ?
DP_AUX_I2C_READ : DP_AUX_I2C_WRITE;
msg->request |= DP_AUX_I2C_MOT;
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
drm_dp_i2c_msg_set_request(&msg, &msgs[i]);
msg.buffer = NULL;
msg.size = 0;
err = drm_dp_i2c_do_msg(aux, &msg);
drm_dp_i2c_msg_set_request(&msg, &msgs[i]);
if (err < 0)
break;
transfer_size = dp_aux_i2c_transfer_size;
for (j = 0; j < msgs[i].len; j += msg.size) {
msg.buffer = msgs[i].buf + j;
msg.size = min(transfer_size, msgs[i].len - j);
err = drm_dp_i2c_drain_msg(aux, &msg);
drm_dp_i2c_msg_set_request(&msg, &msgs[i]);
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
static struct drm_dp_aux *i2c_to_aux(struct i2c_adapter *i2c)
{
return container_of(i2c, struct drm_dp_aux, ddc);
}
static void lock_bus(struct i2c_adapter *i2c, unsigned int flags)
{
mutex_lock(&i2c_to_aux(i2c)->hw_mutex);
}
static int trylock_bus(struct i2c_adapter *i2c, unsigned int flags)
{
return mutex_trylock(&i2c_to_aux(i2c)->hw_mutex);
}
static void unlock_bus(struct i2c_adapter *i2c, unsigned int flags)
{
mutex_unlock(&i2c_to_aux(i2c)->hw_mutex);
}
static int drm_dp_aux_get_crc(struct drm_dp_aux *aux, u8 *crc)
{
u8 buf, count;
int ret;
ret = drm_dp_dpcd_readb(aux, DP_TEST_SINK, &buf);
if (ret < 0)
return ret;
WARN_ON(!(buf & DP_TEST_SINK_START));
ret = drm_dp_dpcd_readb(aux, DP_TEST_SINK_MISC, &buf);
if (ret < 0)
return ret;
count = buf & DP_TEST_COUNT_MASK;
if (count == aux->crc_count)
return -EAGAIN;
aux->crc_count = count;
ret = drm_dp_dpcd_read(aux, DP_TEST_CRC_R_CR, crc, 6);
if (ret < 0)
return ret;
return 0;
}
static void drm_dp_aux_crc_work(struct work_struct *work)
{
struct drm_dp_aux *aux = container_of(work, struct drm_dp_aux,
crc_work);
struct drm_crtc *crtc;
u8 crc_bytes[6];
uint32_t crcs[3];
int ret;
if (WARN_ON(!aux->crtc))
return;
crtc = aux->crtc;
while (crtc->crc.opened) {
drm_crtc_wait_one_vblank(crtc);
if (!crtc->crc.opened)
break;
ret = drm_dp_aux_get_crc(aux, crc_bytes);
if (ret == -EAGAIN) {
usleep_range(1000, 2000);
ret = drm_dp_aux_get_crc(aux, crc_bytes);
}
if (ret == -EAGAIN) {
DRM_DEBUG_KMS("Get CRC failed after retrying: %d\n",
ret);
continue;
} else if (ret) {
DRM_DEBUG_KMS("Failed to get a CRC: %d\n", ret);
continue;
}
crcs[0] = crc_bytes[0] | crc_bytes[1] << 8;
crcs[1] = crc_bytes[2] | crc_bytes[3] << 8;
crcs[2] = crc_bytes[4] | crc_bytes[5] << 8;
drm_crtc_add_crc_entry(crtc, false, 0, crcs);
}
}
void drm_dp_aux_init(struct drm_dp_aux *aux)
{
mutex_init(&aux->hw_mutex);
INIT_WORK(&aux->crc_work, drm_dp_aux_crc_work);
aux->ddc.algo = &drm_dp_i2c_algo;
aux->ddc.algo_data = aux;
aux->ddc.retries = 3;
aux->ddc.lock_ops = &drm_dp_i2c_lock_ops;
}
int drm_dp_aux_register(struct drm_dp_aux *aux)
{
int ret;
if (!aux->ddc.algo)
drm_dp_aux_init(aux);
aux->ddc.class = I2C_CLASS_DDC;
aux->ddc.owner = THIS_MODULE;
aux->ddc.dev.parent = aux->dev;
aux->ddc.dev.of_node = aux->dev->of_node;
strlcpy(aux->ddc.name, aux->name ? aux->name : dev_name(aux->dev),
sizeof(aux->ddc.name));
ret = drm_dp_aux_register_devnode(aux);
if (ret)
return ret;
ret = i2c_add_adapter(&aux->ddc);
if (ret) {
drm_dp_aux_unregister_devnode(aux);
return ret;
}
return 0;
}
void drm_dp_aux_unregister(struct drm_dp_aux *aux)
{
drm_dp_aux_unregister_devnode(aux);
i2c_del_adapter(&aux->ddc);
}
int drm_dp_psr_setup_time(const u8 psr_cap[EDP_PSR_RECEIVER_CAP_SIZE])
{
static const u16 psr_setup_time_us[] = {
PSR_SETUP_TIME(330),
PSR_SETUP_TIME(275),
PSR_SETUP_TIME(165),
PSR_SETUP_TIME(110),
PSR_SETUP_TIME(55),
PSR_SETUP_TIME(0),
};
int i;
i = (psr_cap[1] & DP_PSR_SETUP_TIME_MASK) >> DP_PSR_SETUP_TIME_SHIFT;
if (i >= ARRAY_SIZE(psr_setup_time_us))
return -EINVAL;
return psr_setup_time_us[i];
}
int drm_dp_start_crc(struct drm_dp_aux *aux, struct drm_crtc *crtc)
{
u8 buf;
int ret;
ret = drm_dp_dpcd_readb(aux, DP_TEST_SINK, &buf);
if (ret < 0)
return ret;
ret = drm_dp_dpcd_writeb(aux, DP_TEST_SINK, buf | DP_TEST_SINK_START);
if (ret < 0)
return ret;
aux->crc_count = 0;
aux->crtc = crtc;
schedule_work(&aux->crc_work);
return 0;
}
int drm_dp_stop_crc(struct drm_dp_aux *aux)
{
u8 buf;
int ret;
ret = drm_dp_dpcd_readb(aux, DP_TEST_SINK, &buf);
if (ret < 0)
return ret;
ret = drm_dp_dpcd_writeb(aux, DP_TEST_SINK, buf & ~DP_TEST_SINK_START);
if (ret < 0)
return ret;
flush_work(&aux->crc_work);
aux->crtc = NULL;
return 0;
}
static u32
drm_dp_get_quirks(const struct drm_dp_dpcd_ident *ident, bool is_branch)
{
const struct dpcd_quirk *quirk;
u32 quirks = 0;
int i;
for (i = 0; i < ARRAY_SIZE(dpcd_quirk_list); i++) {
quirk = &dpcd_quirk_list[i];
if (quirk->is_branch != is_branch)
continue;
if (memcmp(quirk->oui, ident->oui, sizeof(ident->oui)) != 0)
continue;
quirks |= quirk->quirks;
}
return quirks;
}
int drm_dp_read_desc(struct drm_dp_aux *aux, struct drm_dp_desc *desc,
bool is_branch)
{
struct drm_dp_dpcd_ident *ident = &desc->ident;
unsigned int offset = is_branch ? DP_BRANCH_OUI : DP_SINK_OUI;
int ret, dev_id_len;
ret = drm_dp_dpcd_read(aux, offset, ident, sizeof(*ident));
if (ret < 0)
return ret;
desc->quirks = drm_dp_get_quirks(ident, is_branch);
dev_id_len = strnlen(ident->device_id, sizeof(ident->device_id));
DRM_DEBUG_KMS("DP %s: OUI %*phD dev-ID %*pE HW-rev %d.%d SW-rev %d.%d quirks 0x%04x\n",
is_branch ? "branch" : "sink",
(int)sizeof(ident->oui), ident->oui,
dev_id_len, ident->device_id,
ident->hw_rev >> 4, ident->hw_rev & 0xf,
ident->sw_major_rev, ident->sw_minor_rev,
desc->quirks);
return 0;
}
