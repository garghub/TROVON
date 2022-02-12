static int amdgpu_atombios_dp_process_aux_ch(struct amdgpu_i2c_chan *chan,
u8 *send, int send_bytes,
u8 *recv, int recv_size,
u8 delay, u8 *ack)
{
struct drm_device *dev = chan->dev;
struct amdgpu_device *adev = dev->dev_private;
union aux_channel_transaction args;
int index = GetIndexIntoMasterTable(COMMAND, ProcessAuxChannelTransaction);
unsigned char *base;
int recv_bytes;
int r = 0;
memset(&args, 0, sizeof(args));
mutex_lock(&chan->mutex);
base = (unsigned char *)(adev->mode_info.atom_context->scratch + 1);
amdgpu_atombios_copy_swap(base, send, send_bytes, true);
args.v2.lpAuxRequest = cpu_to_le16((u16)(0 + 4));
args.v2.lpDataOut = cpu_to_le16((u16)(16 + 4));
args.v2.ucDataOutLen = 0;
args.v2.ucChannelID = chan->rec.i2c_id;
args.v2.ucDelay = delay / 10;
args.v2.ucHPD_ID = chan->rec.hpd;
amdgpu_atom_execute_table(adev->mode_info.atom_context, index, (uint32_t *)&args);
*ack = args.v2.ucReplyStatus;
if (args.v2.ucReplyStatus == 1) {
r = -ETIMEDOUT;
goto done;
}
if (args.v2.ucReplyStatus == 2) {
DRM_DEBUG_KMS("dp_aux_ch flags not zero\n");
r = -EIO;
goto done;
}
if (args.v2.ucReplyStatus == 3) {
DRM_DEBUG_KMS("dp_aux_ch error\n");
r = -EIO;
goto done;
}
recv_bytes = args.v1.ucDataOutLen;
if (recv_bytes > recv_size)
recv_bytes = recv_size;
if (recv && recv_size)
amdgpu_atombios_copy_swap(recv, base + 16, recv_bytes, false);
r = recv_bytes;
done:
mutex_unlock(&chan->mutex);
return r;
}
static ssize_t
amdgpu_atombios_dp_aux_transfer(struct drm_dp_aux *aux, struct drm_dp_aux_msg *msg)
{
struct amdgpu_i2c_chan *chan =
container_of(aux, struct amdgpu_i2c_chan, aux);
int ret;
u8 tx_buf[20];
size_t tx_size;
u8 ack, delay = 0;
if (WARN_ON(msg->size > 16))
return -E2BIG;
tx_buf[0] = msg->address & 0xff;
tx_buf[1] = msg->address >> 8;
tx_buf[2] = (msg->request << 4) |
((msg->address >> 16) & 0xf);
tx_buf[3] = msg->size ? (msg->size - 1) : 0;
switch (msg->request & ~DP_AUX_I2C_MOT) {
case DP_AUX_NATIVE_WRITE:
case DP_AUX_I2C_WRITE:
tx_size = HEADER_SIZE + msg->size;
if (msg->size == 0)
tx_buf[3] |= BARE_ADDRESS_SIZE << 4;
else
tx_buf[3] |= tx_size << 4;
memcpy(tx_buf + HEADER_SIZE, msg->buffer, msg->size);
ret = amdgpu_atombios_dp_process_aux_ch(chan,
tx_buf, tx_size, NULL, 0, delay, &ack);
if (ret >= 0)
ret = msg->size;
break;
case DP_AUX_NATIVE_READ:
case DP_AUX_I2C_READ:
tx_size = HEADER_SIZE;
if (msg->size == 0)
tx_buf[3] |= BARE_ADDRESS_SIZE << 4;
else
tx_buf[3] |= tx_size << 4;
ret = amdgpu_atombios_dp_process_aux_ch(chan,
tx_buf, tx_size, msg->buffer, msg->size, delay, &ack);
break;
default:
ret = -EINVAL;
break;
}
if (ret >= 0)
msg->reply = ack >> 4;
return ret;
}
void amdgpu_atombios_dp_aux_init(struct amdgpu_connector *amdgpu_connector)
{
int ret;
amdgpu_connector->ddc_bus->rec.hpd = amdgpu_connector->hpd.hpd;
amdgpu_connector->ddc_bus->aux.dev = amdgpu_connector->base.kdev;
amdgpu_connector->ddc_bus->aux.transfer = amdgpu_atombios_dp_aux_transfer;
ret = drm_dp_aux_register(&amdgpu_connector->ddc_bus->aux);
if (!ret)
amdgpu_connector->ddc_bus->has_aux = true;
WARN(ret, "drm_dp_aux_register_i2c_bus() failed with error %d\n", ret);
}
static void amdgpu_atombios_dp_get_adjust_train(const u8 link_status[DP_LINK_STATUS_SIZE],
int lane_count,
u8 train_set[4])
{
u8 v = 0;
u8 p = 0;
int lane;
for (lane = 0; lane < lane_count; lane++) {
u8 this_v = drm_dp_get_adjust_request_voltage(link_status, lane);
u8 this_p = drm_dp_get_adjust_request_pre_emphasis(link_status, lane);
DRM_DEBUG_KMS("requested signal parameters: lane %d voltage %s pre_emph %s\n",
lane,
voltage_names[this_v >> DP_TRAIN_VOLTAGE_SWING_SHIFT],
pre_emph_names[this_p >> DP_TRAIN_PRE_EMPHASIS_SHIFT]);
if (this_v > v)
v = this_v;
if (this_p > p)
p = this_p;
}
if (v >= DP_VOLTAGE_MAX)
v |= DP_TRAIN_MAX_SWING_REACHED;
if (p >= DP_PRE_EMPHASIS_MAX)
p |= DP_TRAIN_MAX_PRE_EMPHASIS_REACHED;
DRM_DEBUG_KMS("using signal parameters: voltage %s pre_emph %s\n",
voltage_names[(v & DP_TRAIN_VOLTAGE_SWING_MASK) >> DP_TRAIN_VOLTAGE_SWING_SHIFT],
pre_emph_names[(p & DP_TRAIN_PRE_EMPHASIS_MASK) >> DP_TRAIN_PRE_EMPHASIS_SHIFT]);
for (lane = 0; lane < 4; lane++)
train_set[lane] = v | p;
}
static unsigned amdgpu_atombios_dp_convert_bpc_to_bpp(int bpc)
{
if (bpc == 0)
return 24;
else
return bpc * 3;
}
static int amdgpu_atombios_dp_get_dp_link_config(struct drm_connector *connector,
const u8 dpcd[DP_DPCD_SIZE],
unsigned pix_clock,
unsigned *dp_lanes, unsigned *dp_rate)
{
unsigned bpp =
amdgpu_atombios_dp_convert_bpc_to_bpp(amdgpu_connector_get_monitor_bpc(connector));
static const unsigned link_rates[3] = { 162000, 270000, 540000 };
unsigned max_link_rate = drm_dp_max_link_rate(dpcd);
unsigned max_lane_num = drm_dp_max_lane_count(dpcd);
unsigned lane_num, i, max_pix_clock;
if (amdgpu_connector_encoder_get_dp_bridge_encoder_id(connector) ==
ENCODER_OBJECT_ID_NUTMEG) {
for (lane_num = 1; lane_num <= max_lane_num; lane_num <<= 1) {
max_pix_clock = (lane_num * 270000 * 8) / bpp;
if (max_pix_clock >= pix_clock) {
*dp_lanes = lane_num;
*dp_rate = 270000;
return 0;
}
}
} else {
for (i = 0; i < ARRAY_SIZE(link_rates) && link_rates[i] <= max_link_rate; i++) {
for (lane_num = 1; lane_num <= max_lane_num; lane_num <<= 1) {
max_pix_clock = (lane_num * link_rates[i] * 8) / bpp;
if (max_pix_clock >= pix_clock) {
*dp_lanes = lane_num;
*dp_rate = link_rates[i];
return 0;
}
}
}
}
return -EINVAL;
}
static u8 amdgpu_atombios_dp_encoder_service(struct amdgpu_device *adev,
int action, int dp_clock,
u8 ucconfig, u8 lane_num)
{
DP_ENCODER_SERVICE_PARAMETERS args;
int index = GetIndexIntoMasterTable(COMMAND, DPEncoderService);
memset(&args, 0, sizeof(args));
args.ucLinkClock = dp_clock / 10;
args.ucConfig = ucconfig;
args.ucAction = action;
args.ucLaneNum = lane_num;
args.ucStatus = 0;
amdgpu_atom_execute_table(adev->mode_info.atom_context, index, (uint32_t *)&args);
return args.ucStatus;
}
u8 amdgpu_atombios_dp_get_sinktype(struct amdgpu_connector *amdgpu_connector)
{
struct drm_device *dev = amdgpu_connector->base.dev;
struct amdgpu_device *adev = dev->dev_private;
return amdgpu_atombios_dp_encoder_service(adev, ATOM_DP_ACTION_GET_SINK_TYPE, 0,
amdgpu_connector->ddc_bus->rec.i2c_id, 0);
}
static void amdgpu_atombios_dp_probe_oui(struct amdgpu_connector *amdgpu_connector)
{
struct amdgpu_connector_atom_dig *dig_connector = amdgpu_connector->con_priv;
u8 buf[3];
if (!(dig_connector->dpcd[DP_DOWN_STREAM_PORT_COUNT] & DP_OUI_SUPPORT))
return;
if (drm_dp_dpcd_read(&amdgpu_connector->ddc_bus->aux, DP_SINK_OUI, buf, 3) == 3)
DRM_DEBUG_KMS("Sink OUI: %02hx%02hx%02hx\n",
buf[0], buf[1], buf[2]);
if (drm_dp_dpcd_read(&amdgpu_connector->ddc_bus->aux, DP_BRANCH_OUI, buf, 3) == 3)
DRM_DEBUG_KMS("Branch OUI: %02hx%02hx%02hx\n",
buf[0], buf[1], buf[2]);
}
int amdgpu_atombios_dp_get_dpcd(struct amdgpu_connector *amdgpu_connector)
{
struct amdgpu_connector_atom_dig *dig_connector = amdgpu_connector->con_priv;
u8 msg[DP_DPCD_SIZE];
int ret;
ret = drm_dp_dpcd_read(&amdgpu_connector->ddc_bus->aux, DP_DPCD_REV,
msg, DP_DPCD_SIZE);
if (ret == DP_DPCD_SIZE) {
memcpy(dig_connector->dpcd, msg, DP_DPCD_SIZE);
DRM_DEBUG_KMS("DPCD: %*ph\n", (int)sizeof(dig_connector->dpcd),
dig_connector->dpcd);
amdgpu_atombios_dp_probe_oui(amdgpu_connector);
return 0;
}
dig_connector->dpcd[0] = 0;
return -EINVAL;
}
int amdgpu_atombios_dp_get_panel_mode(struct drm_encoder *encoder,
struct drm_connector *connector)
{
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
struct amdgpu_connector_atom_dig *dig_connector;
int panel_mode = DP_PANEL_MODE_EXTERNAL_DP_MODE;
u16 dp_bridge = amdgpu_connector_encoder_get_dp_bridge_encoder_id(connector);
u8 tmp;
if (!amdgpu_connector->con_priv)
return panel_mode;
dig_connector = amdgpu_connector->con_priv;
if (dp_bridge != ENCODER_OBJECT_ID_NONE) {
if (drm_dp_dpcd_readb(&amdgpu_connector->ddc_bus->aux,
DP_EDP_CONFIGURATION_CAP, &tmp) == 1) {
if (tmp & 1)
panel_mode = DP_PANEL_MODE_INTERNAL_DP2_MODE;
else if ((dp_bridge == ENCODER_OBJECT_ID_NUTMEG) ||
(dp_bridge == ENCODER_OBJECT_ID_TRAVIS))
panel_mode = DP_PANEL_MODE_INTERNAL_DP1_MODE;
else
panel_mode = DP_PANEL_MODE_EXTERNAL_DP_MODE;
}
} else if (connector->connector_type == DRM_MODE_CONNECTOR_eDP) {
if (drm_dp_dpcd_readb(&amdgpu_connector->ddc_bus->aux,
DP_EDP_CONFIGURATION_CAP, &tmp) == 1) {
if (tmp & 1)
panel_mode = DP_PANEL_MODE_INTERNAL_DP2_MODE;
}
}
return panel_mode;
}
void amdgpu_atombios_dp_set_link_config(struct drm_connector *connector,
const struct drm_display_mode *mode)
{
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
struct amdgpu_connector_atom_dig *dig_connector;
int ret;
if (!amdgpu_connector->con_priv)
return;
dig_connector = amdgpu_connector->con_priv;
if ((dig_connector->dp_sink_type == CONNECTOR_OBJECT_ID_DISPLAYPORT) ||
(dig_connector->dp_sink_type == CONNECTOR_OBJECT_ID_eDP)) {
ret = amdgpu_atombios_dp_get_dp_link_config(connector, dig_connector->dpcd,
mode->clock,
&dig_connector->dp_lane_count,
&dig_connector->dp_clock);
if (ret) {
dig_connector->dp_clock = 0;
dig_connector->dp_lane_count = 0;
}
}
}
int amdgpu_atombios_dp_mode_valid_helper(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
struct amdgpu_connector_atom_dig *dig_connector;
unsigned dp_lanes, dp_clock;
int ret;
if (!amdgpu_connector->con_priv)
return MODE_CLOCK_HIGH;
dig_connector = amdgpu_connector->con_priv;
ret = amdgpu_atombios_dp_get_dp_link_config(connector, dig_connector->dpcd,
mode->clock, &dp_lanes, &dp_clock);
if (ret)
return MODE_CLOCK_HIGH;
if ((dp_clock == 540000) &&
(!amdgpu_connector_is_dp12_capable(connector)))
return MODE_CLOCK_HIGH;
return MODE_OK;
}
bool amdgpu_atombios_dp_needs_link_train(struct amdgpu_connector *amdgpu_connector)
{
u8 link_status[DP_LINK_STATUS_SIZE];
struct amdgpu_connector_atom_dig *dig = amdgpu_connector->con_priv;
if (drm_dp_dpcd_read_link_status(&amdgpu_connector->ddc_bus->aux, link_status)
<= 0)
return false;
if (drm_dp_channel_eq_ok(link_status, dig->dp_lane_count))
return false;
return true;
}
void amdgpu_atombios_dp_set_rx_power_state(struct drm_connector *connector,
u8 power_state)
{
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
struct amdgpu_connector_atom_dig *dig_connector;
if (!amdgpu_connector->con_priv)
return;
dig_connector = amdgpu_connector->con_priv;
if (dig_connector->dpcd[0] >= 0x11) {
drm_dp_dpcd_writeb(&amdgpu_connector->ddc_bus->aux,
DP_SET_POWER, power_state);
usleep_range(1000, 2000);
}
}
static void
amdgpu_atombios_dp_update_vs_emph(struct amdgpu_atombios_dp_link_train_info *dp_info)
{
amdgpu_atombios_encoder_setup_dig_transmitter(dp_info->encoder,
ATOM_TRANSMITTER_ACTION_SETUP_VSEMPH,
0, dp_info->train_set[0]);
drm_dp_dpcd_write(dp_info->aux, DP_TRAINING_LANE0_SET,
dp_info->train_set, dp_info->dp_lane_count);
}
static void
amdgpu_atombios_dp_set_tp(struct amdgpu_atombios_dp_link_train_info *dp_info, int tp)
{
int rtp = 0;
switch (tp) {
case DP_TRAINING_PATTERN_1:
rtp = ATOM_ENCODER_CMD_DP_LINK_TRAINING_PATTERN1;
break;
case DP_TRAINING_PATTERN_2:
rtp = ATOM_ENCODER_CMD_DP_LINK_TRAINING_PATTERN2;
break;
case DP_TRAINING_PATTERN_3:
rtp = ATOM_ENCODER_CMD_DP_LINK_TRAINING_PATTERN3;
break;
}
amdgpu_atombios_encoder_setup_dig_encoder(dp_info->encoder, rtp, 0);
drm_dp_dpcd_writeb(dp_info->aux, DP_TRAINING_PATTERN_SET, tp);
}
static int
amdgpu_atombios_dp_link_train_init(struct amdgpu_atombios_dp_link_train_info *dp_info)
{
struct amdgpu_encoder *amdgpu_encoder = to_amdgpu_encoder(dp_info->encoder);
struct amdgpu_encoder_atom_dig *dig = amdgpu_encoder->enc_priv;
u8 tmp;
amdgpu_atombios_dp_set_rx_power_state(dp_info->connector, DP_SET_POWER_D0);
if (dp_info->dpcd[3] & 0x1)
drm_dp_dpcd_writeb(dp_info->aux,
DP_DOWNSPREAD_CTRL, DP_SPREAD_AMP_0_5);
else
drm_dp_dpcd_writeb(dp_info->aux,
DP_DOWNSPREAD_CTRL, 0);
if (dig->panel_mode == DP_PANEL_MODE_INTERNAL_DP2_MODE)
drm_dp_dpcd_writeb(dp_info->aux, DP_EDP_CONFIGURATION_SET, 1);
tmp = dp_info->dp_lane_count;
if (drm_dp_enhanced_frame_cap(dp_info->dpcd))
tmp |= DP_LANE_COUNT_ENHANCED_FRAME_EN;
drm_dp_dpcd_writeb(dp_info->aux, DP_LANE_COUNT_SET, tmp);
tmp = drm_dp_link_rate_to_bw_code(dp_info->dp_clock);
drm_dp_dpcd_writeb(dp_info->aux, DP_LINK_BW_SET, tmp);
amdgpu_atombios_encoder_setup_dig_encoder(dp_info->encoder,
ATOM_ENCODER_CMD_DP_LINK_TRAINING_START, 0);
drm_dp_dpcd_writeb(dp_info->aux,
DP_TRAINING_PATTERN_SET,
DP_TRAINING_PATTERN_DISABLE);
return 0;
}
static int
amdgpu_atombios_dp_link_train_finish(struct amdgpu_atombios_dp_link_train_info *dp_info)
{
udelay(400);
drm_dp_dpcd_writeb(dp_info->aux,
DP_TRAINING_PATTERN_SET,
DP_TRAINING_PATTERN_DISABLE);
amdgpu_atombios_encoder_setup_dig_encoder(dp_info->encoder,
ATOM_ENCODER_CMD_DP_LINK_TRAINING_COMPLETE, 0);
return 0;
}
static int
amdgpu_atombios_dp_link_train_cr(struct amdgpu_atombios_dp_link_train_info *dp_info)
{
bool clock_recovery;
u8 voltage;
int i;
amdgpu_atombios_dp_set_tp(dp_info, DP_TRAINING_PATTERN_1);
memset(dp_info->train_set, 0, 4);
amdgpu_atombios_dp_update_vs_emph(dp_info);
udelay(400);
clock_recovery = false;
dp_info->tries = 0;
voltage = 0xff;
while (1) {
drm_dp_link_train_clock_recovery_delay(dp_info->dpcd);
if (drm_dp_dpcd_read_link_status(dp_info->aux,
dp_info->link_status) <= 0) {
DRM_ERROR("displayport link status failed\n");
break;
}
if (drm_dp_clock_recovery_ok(dp_info->link_status, dp_info->dp_lane_count)) {
clock_recovery = true;
break;
}
for (i = 0; i < dp_info->dp_lane_count; i++) {
if ((dp_info->train_set[i] & DP_TRAIN_MAX_SWING_REACHED) == 0)
break;
}
if (i == dp_info->dp_lane_count) {
DRM_ERROR("clock recovery reached max voltage\n");
break;
}
if ((dp_info->train_set[0] & DP_TRAIN_VOLTAGE_SWING_MASK) == voltage) {
++dp_info->tries;
if (dp_info->tries == 5) {
DRM_ERROR("clock recovery tried 5 times\n");
break;
}
} else
dp_info->tries = 0;
voltage = dp_info->train_set[0] & DP_TRAIN_VOLTAGE_SWING_MASK;
amdgpu_atombios_dp_get_adjust_train(dp_info->link_status, dp_info->dp_lane_count,
dp_info->train_set);
amdgpu_atombios_dp_update_vs_emph(dp_info);
}
if (!clock_recovery) {
DRM_ERROR("clock recovery failed\n");
return -1;
} else {
DRM_DEBUG_KMS("clock recovery at voltage %d pre-emphasis %d\n",
dp_info->train_set[0] & DP_TRAIN_VOLTAGE_SWING_MASK,
(dp_info->train_set[0] & DP_TRAIN_PRE_EMPHASIS_MASK) >>
DP_TRAIN_PRE_EMPHASIS_SHIFT);
return 0;
}
}
static int
amdgpu_atombios_dp_link_train_ce(struct amdgpu_atombios_dp_link_train_info *dp_info)
{
bool channel_eq;
if (dp_info->tp3_supported)
amdgpu_atombios_dp_set_tp(dp_info, DP_TRAINING_PATTERN_3);
else
amdgpu_atombios_dp_set_tp(dp_info, DP_TRAINING_PATTERN_2);
dp_info->tries = 0;
channel_eq = false;
while (1) {
drm_dp_link_train_channel_eq_delay(dp_info->dpcd);
if (drm_dp_dpcd_read_link_status(dp_info->aux,
dp_info->link_status) <= 0) {
DRM_ERROR("displayport link status failed\n");
break;
}
if (drm_dp_channel_eq_ok(dp_info->link_status, dp_info->dp_lane_count)) {
channel_eq = true;
break;
}
if (dp_info->tries > 5) {
DRM_ERROR("channel eq failed: 5 tries\n");
break;
}
amdgpu_atombios_dp_get_adjust_train(dp_info->link_status, dp_info->dp_lane_count,
dp_info->train_set);
amdgpu_atombios_dp_update_vs_emph(dp_info);
dp_info->tries++;
}
if (!channel_eq) {
DRM_ERROR("channel eq failed\n");
return -1;
} else {
DRM_DEBUG_KMS("channel eq at voltage %d pre-emphasis %d\n",
dp_info->train_set[0] & DP_TRAIN_VOLTAGE_SWING_MASK,
(dp_info->train_set[0] & DP_TRAIN_PRE_EMPHASIS_MASK)
>> DP_TRAIN_PRE_EMPHASIS_SHIFT);
return 0;
}
}
void amdgpu_atombios_dp_link_train(struct drm_encoder *encoder,
struct drm_connector *connector)
{
struct drm_device *dev = encoder->dev;
struct amdgpu_device *adev = dev->dev_private;
struct amdgpu_encoder *amdgpu_encoder = to_amdgpu_encoder(encoder);
struct amdgpu_encoder_atom_dig *dig;
struct amdgpu_connector *amdgpu_connector;
struct amdgpu_connector_atom_dig *dig_connector;
struct amdgpu_atombios_dp_link_train_info dp_info;
u8 tmp;
if (!amdgpu_encoder->enc_priv)
return;
dig = amdgpu_encoder->enc_priv;
amdgpu_connector = to_amdgpu_connector(connector);
if (!amdgpu_connector->con_priv)
return;
dig_connector = amdgpu_connector->con_priv;
if ((dig_connector->dp_sink_type != CONNECTOR_OBJECT_ID_DISPLAYPORT) &&
(dig_connector->dp_sink_type != CONNECTOR_OBJECT_ID_eDP))
return;
if (drm_dp_dpcd_readb(&amdgpu_connector->ddc_bus->aux, DP_MAX_LANE_COUNT, &tmp)
== 1) {
if (tmp & DP_TPS3_SUPPORTED)
dp_info.tp3_supported = true;
else
dp_info.tp3_supported = false;
} else {
dp_info.tp3_supported = false;
}
memcpy(dp_info.dpcd, dig_connector->dpcd, DP_RECEIVER_CAP_SIZE);
dp_info.adev = adev;
dp_info.encoder = encoder;
dp_info.connector = connector;
dp_info.dp_lane_count = dig_connector->dp_lane_count;
dp_info.dp_clock = dig_connector->dp_clock;
dp_info.aux = &amdgpu_connector->ddc_bus->aux;
if (amdgpu_atombios_dp_link_train_init(&dp_info))
goto done;
if (amdgpu_atombios_dp_link_train_cr(&dp_info))
goto done;
if (amdgpu_atombios_dp_link_train_ce(&dp_info))
goto done;
done:
if (amdgpu_atombios_dp_link_train_finish(&dp_info))
return;
}
