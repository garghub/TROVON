static void analogix_dp_init_dp(struct analogix_dp_device *dp)
{
analogix_dp_reset(dp);
analogix_dp_swreset(dp);
analogix_dp_init_analog_param(dp);
analogix_dp_init_interrupt(dp);
analogix_dp_enable_sw_function(dp);
analogix_dp_config_interrupt(dp);
analogix_dp_init_analog_func(dp);
analogix_dp_init_hpd(dp);
analogix_dp_init_aux(dp);
}
static int analogix_dp_detect_hpd(struct analogix_dp_device *dp)
{
int timeout_loop = 0;
while (timeout_loop < DP_TIMEOUT_LOOP_COUNT) {
if (analogix_dp_get_plug_in_status(dp) == 0)
return 0;
timeout_loop++;
usleep_range(10, 11);
}
if (!dp->force_hpd)
return -ETIMEDOUT;
dev_dbg(dp->dev, "failed to get hpd plug status, try to force hpd\n");
analogix_dp_force_hpd(dp);
if (analogix_dp_get_plug_in_status(dp) != 0) {
dev_err(dp->dev, "failed to get hpd plug in status\n");
return -EINVAL;
}
dev_dbg(dp->dev, "success to get plug in status after force hpd\n");
return 0;
}
int analogix_dp_psr_supported(struct device *dev)
{
struct analogix_dp_device *dp = dev_get_drvdata(dev);
return dp->psr_support;
}
int analogix_dp_enable_psr(struct device *dev)
{
struct analogix_dp_device *dp = dev_get_drvdata(dev);
struct edp_vsc_psr psr_vsc;
if (!dp->psr_support)
return 0;
memset(&psr_vsc, 0, sizeof(psr_vsc));
psr_vsc.sdp_header.HB0 = 0;
psr_vsc.sdp_header.HB1 = 0x7;
psr_vsc.sdp_header.HB2 = 0x2;
psr_vsc.sdp_header.HB3 = 0x8;
psr_vsc.DB0 = 0;
psr_vsc.DB1 = EDP_VSC_PSR_STATE_ACTIVE | EDP_VSC_PSR_CRC_VALUES_VALID;
analogix_dp_send_psr_spd(dp, &psr_vsc);
return 0;
}
int analogix_dp_disable_psr(struct device *dev)
{
struct analogix_dp_device *dp = dev_get_drvdata(dev);
struct edp_vsc_psr psr_vsc;
int ret;
if (!dp->psr_support)
return 0;
memset(&psr_vsc, 0, sizeof(psr_vsc));
psr_vsc.sdp_header.HB0 = 0;
psr_vsc.sdp_header.HB1 = 0x7;
psr_vsc.sdp_header.HB2 = 0x2;
psr_vsc.sdp_header.HB3 = 0x8;
psr_vsc.DB0 = 0;
psr_vsc.DB1 = 0;
ret = drm_dp_dpcd_writeb(&dp->aux, DP_SET_POWER, DP_SET_POWER_D0);
if (ret != 1)
dev_err(dp->dev, "Failed to set DP Power0 %d\n", ret);
analogix_dp_send_psr_spd(dp, &psr_vsc);
return 0;
}
static bool analogix_dp_detect_sink_psr(struct analogix_dp_device *dp)
{
unsigned char psr_version;
drm_dp_dpcd_readb(&dp->aux, DP_PSR_SUPPORT, &psr_version);
dev_dbg(dp->dev, "Panel PSR version : %x\n", psr_version);
return (psr_version & DP_PSR_IS_SUPPORTED) ? true : false;
}
static void analogix_dp_enable_sink_psr(struct analogix_dp_device *dp)
{
unsigned char psr_en;
drm_dp_dpcd_readb(&dp->aux, DP_PSR_EN_CFG, &psr_en);
psr_en &= ~DP_PSR_ENABLE;
drm_dp_dpcd_writeb(&dp->aux, DP_PSR_EN_CFG, psr_en);
psr_en = DP_PSR_MAIN_LINK_ACTIVE | DP_PSR_CRC_VERIFICATION;
drm_dp_dpcd_writeb(&dp->aux, DP_PSR_EN_CFG, psr_en);
psr_en = DP_PSR_ENABLE | DP_PSR_MAIN_LINK_ACTIVE |
DP_PSR_CRC_VERIFICATION;
drm_dp_dpcd_writeb(&dp->aux, DP_PSR_EN_CFG, psr_en);
analogix_dp_enable_psr_crc(dp);
}
static void
analogix_dp_enable_rx_to_enhanced_mode(struct analogix_dp_device *dp,
bool enable)
{
u8 data;
drm_dp_dpcd_readb(&dp->aux, DP_LANE_COUNT_SET, &data);
if (enable)
drm_dp_dpcd_writeb(&dp->aux, DP_LANE_COUNT_SET,
DP_LANE_COUNT_ENHANCED_FRAME_EN |
DPCD_LANE_COUNT_SET(data));
else
drm_dp_dpcd_writeb(&dp->aux, DP_LANE_COUNT_SET,
DPCD_LANE_COUNT_SET(data));
}
static int analogix_dp_is_enhanced_mode_available(struct analogix_dp_device *dp)
{
u8 data;
int retval;
drm_dp_dpcd_readb(&dp->aux, DP_MAX_LANE_COUNT, &data);
retval = DPCD_ENHANCED_FRAME_CAP(data);
return retval;
}
static void analogix_dp_set_enhanced_mode(struct analogix_dp_device *dp)
{
u8 data;
data = analogix_dp_is_enhanced_mode_available(dp);
analogix_dp_enable_rx_to_enhanced_mode(dp, data);
analogix_dp_enable_enhanced_mode(dp, data);
}
static void analogix_dp_training_pattern_dis(struct analogix_dp_device *dp)
{
analogix_dp_set_training_pattern(dp, DP_NONE);
drm_dp_dpcd_writeb(&dp->aux, DP_TRAINING_PATTERN_SET,
DP_TRAINING_PATTERN_DISABLE);
}
static void
analogix_dp_set_lane_lane_pre_emphasis(struct analogix_dp_device *dp,
int pre_emphasis, int lane)
{
switch (lane) {
case 0:
analogix_dp_set_lane0_pre_emphasis(dp, pre_emphasis);
break;
case 1:
analogix_dp_set_lane1_pre_emphasis(dp, pre_emphasis);
break;
case 2:
analogix_dp_set_lane2_pre_emphasis(dp, pre_emphasis);
break;
case 3:
analogix_dp_set_lane3_pre_emphasis(dp, pre_emphasis);
break;
}
}
static int analogix_dp_link_start(struct analogix_dp_device *dp)
{
u8 buf[4];
int lane, lane_count, pll_tries, retval;
lane_count = dp->link_train.lane_count;
dp->link_train.lt_state = CLOCK_RECOVERY;
dp->link_train.eq_loop = 0;
for (lane = 0; lane < lane_count; lane++)
dp->link_train.cr_loop[lane] = 0;
analogix_dp_set_link_bandwidth(dp, dp->link_train.link_rate);
analogix_dp_set_lane_count(dp, dp->link_train.lane_count);
buf[0] = dp->link_train.link_rate;
buf[1] = dp->link_train.lane_count;
retval = drm_dp_dpcd_write(&dp->aux, DP_LINK_BW_SET, buf, 2);
if (retval < 0)
return retval;
for (lane = 0; lane < lane_count; lane++)
analogix_dp_set_lane_lane_pre_emphasis(dp,
PRE_EMPHASIS_LEVEL_0, lane);
pll_tries = 0;
while (analogix_dp_get_pll_lock_status(dp) == PLL_UNLOCKED) {
if (pll_tries == DP_TIMEOUT_LOOP_COUNT) {
dev_err(dp->dev, "Wait for PLL lock timed out\n");
return -ETIMEDOUT;
}
pll_tries++;
usleep_range(90, 120);
}
analogix_dp_set_training_pattern(dp, TRAINING_PTN1);
retval = drm_dp_dpcd_writeb(&dp->aux, DP_TRAINING_PATTERN_SET,
DP_LINK_SCRAMBLING_DISABLE |
DP_TRAINING_PATTERN_1);
if (retval < 0)
return retval;
for (lane = 0; lane < lane_count; lane++)
buf[lane] = DP_TRAIN_PRE_EMPH_LEVEL_0 |
DP_TRAIN_VOLTAGE_SWING_LEVEL_0;
retval = drm_dp_dpcd_write(&dp->aux, DP_TRAINING_LANE0_SET, buf,
lane_count);
if (retval < 0)
return retval;
return 0;
}
static unsigned char analogix_dp_get_lane_status(u8 link_status[2], int lane)
{
int shift = (lane & 1) * 4;
u8 link_value = link_status[lane >> 1];
return (link_value >> shift) & 0xf;
}
static int analogix_dp_clock_recovery_ok(u8 link_status[2], int lane_count)
{
int lane;
u8 lane_status;
for (lane = 0; lane < lane_count; lane++) {
lane_status = analogix_dp_get_lane_status(link_status, lane);
if ((lane_status & DP_LANE_CR_DONE) == 0)
return -EINVAL;
}
return 0;
}
static int analogix_dp_channel_eq_ok(u8 link_status[2], u8 link_align,
int lane_count)
{
int lane;
u8 lane_status;
if ((link_align & DP_INTERLANE_ALIGN_DONE) == 0)
return -EINVAL;
for (lane = 0; lane < lane_count; lane++) {
lane_status = analogix_dp_get_lane_status(link_status, lane);
lane_status &= DP_CHANNEL_EQ_BITS;
if (lane_status != DP_CHANNEL_EQ_BITS)
return -EINVAL;
}
return 0;
}
static unsigned char
analogix_dp_get_adjust_request_voltage(u8 adjust_request[2], int lane)
{
int shift = (lane & 1) * 4;
u8 link_value = adjust_request[lane >> 1];
return (link_value >> shift) & 0x3;
}
static unsigned char analogix_dp_get_adjust_request_pre_emphasis(
u8 adjust_request[2],
int lane)
{
int shift = (lane & 1) * 4;
u8 link_value = adjust_request[lane >> 1];
return ((link_value >> shift) & 0xc) >> 2;
}
static void analogix_dp_set_lane_link_training(struct analogix_dp_device *dp,
u8 training_lane_set, int lane)
{
switch (lane) {
case 0:
analogix_dp_set_lane0_link_training(dp, training_lane_set);
break;
case 1:
analogix_dp_set_lane1_link_training(dp, training_lane_set);
break;
case 2:
analogix_dp_set_lane2_link_training(dp, training_lane_set);
break;
case 3:
analogix_dp_set_lane3_link_training(dp, training_lane_set);
break;
}
}
static unsigned int
analogix_dp_get_lane_link_training(struct analogix_dp_device *dp,
int lane)
{
u32 reg;
switch (lane) {
case 0:
reg = analogix_dp_get_lane0_link_training(dp);
break;
case 1:
reg = analogix_dp_get_lane1_link_training(dp);
break;
case 2:
reg = analogix_dp_get_lane2_link_training(dp);
break;
case 3:
reg = analogix_dp_get_lane3_link_training(dp);
break;
default:
WARN_ON(1);
return 0;
}
return reg;
}
static void analogix_dp_reduce_link_rate(struct analogix_dp_device *dp)
{
analogix_dp_training_pattern_dis(dp);
analogix_dp_set_enhanced_mode(dp);
dp->link_train.lt_state = FAILED;
}
static void analogix_dp_get_adjust_training_lane(struct analogix_dp_device *dp,
u8 adjust_request[2])
{
int lane, lane_count;
u8 voltage_swing, pre_emphasis, training_lane;
lane_count = dp->link_train.lane_count;
for (lane = 0; lane < lane_count; lane++) {
voltage_swing = analogix_dp_get_adjust_request_voltage(
adjust_request, lane);
pre_emphasis = analogix_dp_get_adjust_request_pre_emphasis(
adjust_request, lane);
training_lane = DPCD_VOLTAGE_SWING_SET(voltage_swing) |
DPCD_PRE_EMPHASIS_SET(pre_emphasis);
if (voltage_swing == VOLTAGE_LEVEL_3)
training_lane |= DP_TRAIN_MAX_SWING_REACHED;
if (pre_emphasis == PRE_EMPHASIS_LEVEL_3)
training_lane |= DP_TRAIN_MAX_PRE_EMPHASIS_REACHED;
dp->link_train.training_lane[lane] = training_lane;
}
}
static int analogix_dp_process_clock_recovery(struct analogix_dp_device *dp)
{
int lane, lane_count, retval;
u8 voltage_swing, pre_emphasis, training_lane;
u8 link_status[2], adjust_request[2];
usleep_range(100, 101);
lane_count = dp->link_train.lane_count;
retval = drm_dp_dpcd_read(&dp->aux, DP_LANE0_1_STATUS, link_status, 2);
if (retval < 0)
return retval;
retval = drm_dp_dpcd_read(&dp->aux, DP_ADJUST_REQUEST_LANE0_1,
adjust_request, 2);
if (retval < 0)
return retval;
if (analogix_dp_clock_recovery_ok(link_status, lane_count) == 0) {
analogix_dp_set_training_pattern(dp, TRAINING_PTN2);
retval = drm_dp_dpcd_writeb(&dp->aux, DP_TRAINING_PATTERN_SET,
DP_LINK_SCRAMBLING_DISABLE |
DP_TRAINING_PATTERN_2);
if (retval < 0)
return retval;
dev_info(dp->dev, "Link Training Clock Recovery success\n");
dp->link_train.lt_state = EQUALIZER_TRAINING;
} else {
for (lane = 0; lane < lane_count; lane++) {
training_lane = analogix_dp_get_lane_link_training(
dp, lane);
voltage_swing = analogix_dp_get_adjust_request_voltage(
adjust_request, lane);
pre_emphasis = analogix_dp_get_adjust_request_pre_emphasis(
adjust_request, lane);
if (DPCD_VOLTAGE_SWING_GET(training_lane) ==
voltage_swing &&
DPCD_PRE_EMPHASIS_GET(training_lane) ==
pre_emphasis)
dp->link_train.cr_loop[lane]++;
if (dp->link_train.cr_loop[lane] == MAX_CR_LOOP ||
voltage_swing == VOLTAGE_LEVEL_3 ||
pre_emphasis == PRE_EMPHASIS_LEVEL_3) {
dev_err(dp->dev, "CR Max reached (%d,%d,%d)\n",
dp->link_train.cr_loop[lane],
voltage_swing, pre_emphasis);
analogix_dp_reduce_link_rate(dp);
return -EIO;
}
}
}
analogix_dp_get_adjust_training_lane(dp, adjust_request);
for (lane = 0; lane < lane_count; lane++)
analogix_dp_set_lane_link_training(dp,
dp->link_train.training_lane[lane], lane);
retval = drm_dp_dpcd_write(&dp->aux, DP_TRAINING_LANE0_SET,
dp->link_train.training_lane, lane_count);
if (retval < 0)
return retval;
return 0;
}
static int analogix_dp_process_equalizer_training(struct analogix_dp_device *dp)
{
int lane, lane_count, retval;
u32 reg;
u8 link_align, link_status[2], adjust_request[2];
usleep_range(400, 401);
lane_count = dp->link_train.lane_count;
retval = drm_dp_dpcd_read(&dp->aux, DP_LANE0_1_STATUS, link_status, 2);
if (retval < 0)
return retval;
if (analogix_dp_clock_recovery_ok(link_status, lane_count)) {
analogix_dp_reduce_link_rate(dp);
return -EIO;
}
retval = drm_dp_dpcd_read(&dp->aux, DP_ADJUST_REQUEST_LANE0_1,
adjust_request, 2);
if (retval < 0)
return retval;
retval = drm_dp_dpcd_readb(&dp->aux, DP_LANE_ALIGN_STATUS_UPDATED,
&link_align);
if (retval < 0)
return retval;
analogix_dp_get_adjust_training_lane(dp, adjust_request);
if (!analogix_dp_channel_eq_ok(link_status, link_align, lane_count)) {
analogix_dp_training_pattern_dis(dp);
dev_info(dp->dev, "Link Training success!\n");
analogix_dp_get_link_bandwidth(dp, &reg);
dp->link_train.link_rate = reg;
dev_dbg(dp->dev, "final bandwidth = %.2x\n",
dp->link_train.link_rate);
analogix_dp_get_lane_count(dp, &reg);
dp->link_train.lane_count = reg;
dev_dbg(dp->dev, "final lane count = %.2x\n",
dp->link_train.lane_count);
analogix_dp_set_enhanced_mode(dp);
dp->link_train.lt_state = FINISHED;
return 0;
}
dp->link_train.eq_loop++;
if (dp->link_train.eq_loop > MAX_EQ_LOOP) {
dev_err(dp->dev, "EQ Max loop\n");
analogix_dp_reduce_link_rate(dp);
return -EIO;
}
for (lane = 0; lane < lane_count; lane++)
analogix_dp_set_lane_link_training(dp,
dp->link_train.training_lane[lane], lane);
retval = drm_dp_dpcd_write(&dp->aux, DP_TRAINING_LANE0_SET,
dp->link_train.training_lane, lane_count);
if (retval < 0)
return retval;
return 0;
}
static void analogix_dp_get_max_rx_bandwidth(struct analogix_dp_device *dp,
u8 *bandwidth)
{
u8 data;
drm_dp_dpcd_readb(&dp->aux, DP_MAX_LINK_RATE, &data);
*bandwidth = data;
}
static void analogix_dp_get_max_rx_lane_count(struct analogix_dp_device *dp,
u8 *lane_count)
{
u8 data;
drm_dp_dpcd_readb(&dp->aux, DP_MAX_LANE_COUNT, &data);
*lane_count = DPCD_MAX_LANE_COUNT(data);
}
static void analogix_dp_init_training(struct analogix_dp_device *dp,
enum link_lane_count_type max_lane,
int max_rate)
{
analogix_dp_reset_macro(dp);
analogix_dp_get_max_rx_bandwidth(dp, &dp->link_train.link_rate);
analogix_dp_get_max_rx_lane_count(dp, &dp->link_train.lane_count);
if ((dp->link_train.link_rate != DP_LINK_BW_1_62) &&
(dp->link_train.link_rate != DP_LINK_BW_2_7) &&
(dp->link_train.link_rate != DP_LINK_BW_5_4)) {
dev_err(dp->dev, "Rx Max Link Rate is abnormal :%x !\n",
dp->link_train.link_rate);
dp->link_train.link_rate = DP_LINK_BW_1_62;
}
if (dp->link_train.lane_count == 0) {
dev_err(dp->dev, "Rx Max Lane count is abnormal :%x !\n",
dp->link_train.lane_count);
dp->link_train.lane_count = (u8)LANE_COUNT1;
}
if (dp->link_train.lane_count > max_lane)
dp->link_train.lane_count = max_lane;
if (dp->link_train.link_rate > max_rate)
dp->link_train.link_rate = max_rate;
analogix_dp_set_analog_power_down(dp, POWER_ALL, 0);
}
static int analogix_dp_sw_link_training(struct analogix_dp_device *dp)
{
int retval = 0, training_finished = 0;
dp->link_train.lt_state = START;
while (!retval && !training_finished) {
switch (dp->link_train.lt_state) {
case START:
retval = analogix_dp_link_start(dp);
if (retval)
dev_err(dp->dev, "LT link start failed!\n");
break;
case CLOCK_RECOVERY:
retval = analogix_dp_process_clock_recovery(dp);
if (retval)
dev_err(dp->dev, "LT CR failed!\n");
break;
case EQUALIZER_TRAINING:
retval = analogix_dp_process_equalizer_training(dp);
if (retval)
dev_err(dp->dev, "LT EQ failed!\n");
break;
case FINISHED:
training_finished = 1;
break;
case FAILED:
return -EREMOTEIO;
}
}
if (retval)
dev_err(dp->dev, "eDP link training failed (%d)\n", retval);
return retval;
}
static int analogix_dp_set_link_train(struct analogix_dp_device *dp,
u32 count, u32 bwtype)
{
int i;
int retval;
for (i = 0; i < DP_TIMEOUT_LOOP_COUNT; i++) {
analogix_dp_init_training(dp, count, bwtype);
retval = analogix_dp_sw_link_training(dp);
if (retval == 0)
break;
usleep_range(100, 110);
}
return retval;
}
static int analogix_dp_config_video(struct analogix_dp_device *dp)
{
int retval = 0;
int timeout_loop = 0;
int done_count = 0;
analogix_dp_config_video_slave_mode(dp);
analogix_dp_set_video_color_format(dp);
if (analogix_dp_get_pll_lock_status(dp) == PLL_UNLOCKED) {
dev_err(dp->dev, "PLL is not locked yet.\n");
return -EINVAL;
}
for (;;) {
timeout_loop++;
if (analogix_dp_is_slave_video_stream_clock_on(dp) == 0)
break;
if (timeout_loop > DP_TIMEOUT_LOOP_COUNT) {
dev_err(dp->dev, "Timeout of video streamclk ok\n");
return -ETIMEDOUT;
}
usleep_range(1, 2);
}
analogix_dp_set_video_cr_mn(dp, CALCULATED_M, 0, 0);
analogix_dp_set_video_timing_mode(dp, VIDEO_TIMING_FROM_CAPTURE);
analogix_dp_enable_video_mute(dp, 0);
analogix_dp_enable_video_master(dp, 0);
timeout_loop = 0;
for (;;) {
timeout_loop++;
if (analogix_dp_is_video_stream_on(dp) == 0) {
done_count++;
if (done_count > 10)
break;
} else if (done_count) {
done_count = 0;
}
if (timeout_loop > DP_TIMEOUT_LOOP_COUNT) {
dev_err(dp->dev, "Timeout of video streamclk ok\n");
return -ETIMEDOUT;
}
usleep_range(1000, 1001);
}
if (retval != 0)
dev_err(dp->dev, "Video stream is not detected!\n");
return retval;
}
static void analogix_dp_enable_scramble(struct analogix_dp_device *dp,
bool enable)
{
u8 data;
if (enable) {
analogix_dp_enable_scrambling(dp);
drm_dp_dpcd_readb(&dp->aux, DP_TRAINING_PATTERN_SET, &data);
drm_dp_dpcd_writeb(&dp->aux, DP_TRAINING_PATTERN_SET,
(u8)(data & ~DP_LINK_SCRAMBLING_DISABLE));
} else {
analogix_dp_disable_scrambling(dp);
drm_dp_dpcd_readb(&dp->aux, DP_TRAINING_PATTERN_SET, &data);
drm_dp_dpcd_writeb(&dp->aux, DP_TRAINING_PATTERN_SET,
(u8)(data | DP_LINK_SCRAMBLING_DISABLE));
}
}
static irqreturn_t analogix_dp_hardirq(int irq, void *arg)
{
struct analogix_dp_device *dp = arg;
irqreturn_t ret = IRQ_NONE;
enum dp_irq_type irq_type;
irq_type = analogix_dp_get_irq_type(dp);
if (irq_type != DP_IRQ_TYPE_UNKNOWN) {
analogix_dp_mute_hpd_interrupt(dp);
ret = IRQ_WAKE_THREAD;
}
return ret;
}
static irqreturn_t analogix_dp_irq_thread(int irq, void *arg)
{
struct analogix_dp_device *dp = arg;
enum dp_irq_type irq_type;
irq_type = analogix_dp_get_irq_type(dp);
if (irq_type & DP_IRQ_TYPE_HP_CABLE_IN ||
irq_type & DP_IRQ_TYPE_HP_CABLE_OUT) {
dev_dbg(dp->dev, "Detected cable status changed!\n");
if (dp->drm_dev)
drm_helper_hpd_irq_event(dp->drm_dev);
}
if (irq_type != DP_IRQ_TYPE_UNKNOWN) {
analogix_dp_clear_hotplug_interrupts(dp);
analogix_dp_unmute_hpd_interrupt(dp);
}
return IRQ_HANDLED;
}
static void analogix_dp_commit(struct analogix_dp_device *dp)
{
int ret;
if (dp->plat_data->panel) {
if (drm_panel_disable(dp->plat_data->panel))
DRM_ERROR("failed to disable the panel\n");
}
ret = analogix_dp_set_link_train(dp, dp->video_info.max_lane_count,
dp->video_info.max_link_rate);
if (ret) {
dev_err(dp->dev, "unable to do link train\n");
return;
}
analogix_dp_enable_scramble(dp, 1);
analogix_dp_enable_rx_to_enhanced_mode(dp, 1);
analogix_dp_enable_enhanced_mode(dp, 1);
analogix_dp_init_video(dp);
ret = analogix_dp_config_video(dp);
if (ret)
dev_err(dp->dev, "unable to config video\n");
if (dp->plat_data->panel) {
if (drm_panel_enable(dp->plat_data->panel))
DRM_ERROR("failed to enable the panel\n");
}
analogix_dp_start_video(dp);
dp->psr_support = analogix_dp_detect_sink_psr(dp);
if (dp->psr_support)
analogix_dp_enable_sink_psr(dp);
}
static int analogix_dp_prepare_panel(struct analogix_dp_device *dp,
bool prepare, bool is_modeset_prepare)
{
int ret = 0;
if (!dp->plat_data->panel)
return 0;
mutex_lock(&dp->panel_lock);
if (dp->panel_is_modeset && !is_modeset_prepare)
goto out;
if (prepare)
ret = drm_panel_prepare(dp->plat_data->panel);
else
ret = drm_panel_unprepare(dp->plat_data->panel);
if (ret)
goto out;
if (is_modeset_prepare)
dp->panel_is_modeset = prepare;
out:
mutex_unlock(&dp->panel_lock);
return ret;
}
static int analogix_dp_get_modes(struct drm_connector *connector)
{
struct analogix_dp_device *dp = to_dp(connector);
struct edid *edid;
int ret, num_modes = 0;
if (dp->plat_data->panel) {
num_modes += drm_panel_get_modes(dp->plat_data->panel);
} else {
ret = analogix_dp_prepare_panel(dp, true, false);
if (ret) {
DRM_ERROR("Failed to prepare panel (%d)\n", ret);
return 0;
}
edid = drm_get_edid(connector, &dp->aux.ddc);
if (edid) {
drm_mode_connector_update_edid_property(&dp->connector,
edid);
num_modes += drm_add_edid_modes(&dp->connector, edid);
kfree(edid);
}
ret = analogix_dp_prepare_panel(dp, false, false);
if (ret)
DRM_ERROR("Failed to unprepare panel (%d)\n", ret);
}
if (dp->plat_data->get_modes)
num_modes += dp->plat_data->get_modes(dp->plat_data, connector);
return num_modes;
}
static struct drm_encoder *
analogix_dp_best_encoder(struct drm_connector *connector)
{
struct analogix_dp_device *dp = to_dp(connector);
return dp->encoder;
}
static enum drm_connector_status
analogix_dp_detect(struct drm_connector *connector, bool force)
{
struct analogix_dp_device *dp = to_dp(connector);
enum drm_connector_status status = connector_status_disconnected;
int ret;
if (dp->plat_data->panel)
return connector_status_connected;
ret = analogix_dp_prepare_panel(dp, true, false);
if (ret) {
DRM_ERROR("Failed to prepare panel (%d)\n", ret);
return connector_status_disconnected;
}
if (!analogix_dp_detect_hpd(dp))
status = connector_status_connected;
ret = analogix_dp_prepare_panel(dp, false, false);
if (ret)
DRM_ERROR("Failed to unprepare panel (%d)\n", ret);
return status;
}
static int analogix_dp_bridge_attach(struct drm_bridge *bridge)
{
struct analogix_dp_device *dp = bridge->driver_private;
struct drm_encoder *encoder = dp->encoder;
struct drm_connector *connector = &dp->connector;
int ret;
if (!bridge->encoder) {
DRM_ERROR("Parent encoder object not found");
return -ENODEV;
}
connector->polled = DRM_CONNECTOR_POLL_HPD;
ret = drm_connector_init(dp->drm_dev, connector,
&analogix_dp_connector_funcs,
DRM_MODE_CONNECTOR_eDP);
if (ret) {
DRM_ERROR("Failed to initialize connector with drm\n");
return ret;
}
drm_connector_helper_add(connector,
&analogix_dp_connector_helper_funcs);
drm_mode_connector_attach_encoder(connector, encoder);
if (dp->plat_data->attach) {
ret = dp->plat_data->attach(dp->plat_data, bridge, connector);
if (ret) {
DRM_ERROR("Failed at platform attch func\n");
return ret;
}
}
if (dp->plat_data->panel) {
ret = drm_panel_attach(dp->plat_data->panel, &dp->connector);
if (ret) {
DRM_ERROR("Failed to attach panel\n");
return ret;
}
}
return 0;
}
static void analogix_dp_bridge_pre_enable(struct drm_bridge *bridge)
{
struct analogix_dp_device *dp = bridge->driver_private;
int ret;
ret = analogix_dp_prepare_panel(dp, true, true);
if (ret)
DRM_ERROR("failed to setup the panel ret = %d\n", ret);
}
static void analogix_dp_bridge_enable(struct drm_bridge *bridge)
{
struct analogix_dp_device *dp = bridge->driver_private;
if (dp->dpms_mode == DRM_MODE_DPMS_ON)
return;
pm_runtime_get_sync(dp->dev);
if (dp->plat_data->power_on)
dp->plat_data->power_on(dp->plat_data);
phy_power_on(dp->phy);
analogix_dp_init_dp(dp);
enable_irq(dp->irq);
analogix_dp_commit(dp);
dp->dpms_mode = DRM_MODE_DPMS_ON;
}
static void analogix_dp_bridge_disable(struct drm_bridge *bridge)
{
struct analogix_dp_device *dp = bridge->driver_private;
int ret;
if (dp->dpms_mode != DRM_MODE_DPMS_ON)
return;
if (dp->plat_data->panel) {
if (drm_panel_disable(dp->plat_data->panel)) {
DRM_ERROR("failed to disable the panel\n");
return;
}
}
disable_irq(dp->irq);
phy_power_off(dp->phy);
if (dp->plat_data->power_off)
dp->plat_data->power_off(dp->plat_data);
pm_runtime_put_sync(dp->dev);
ret = analogix_dp_prepare_panel(dp, false, true);
if (ret)
DRM_ERROR("failed to setup the panel ret = %d\n", ret);
dp->dpms_mode = DRM_MODE_DPMS_OFF;
}
static void analogix_dp_bridge_mode_set(struct drm_bridge *bridge,
struct drm_display_mode *orig_mode,
struct drm_display_mode *mode)
{
struct analogix_dp_device *dp = bridge->driver_private;
struct drm_display_info *display_info = &dp->connector.display_info;
struct video_info *video = &dp->video_info;
struct device_node *dp_node = dp->dev->of_node;
int vic;
video->interlaced = !!(mode->flags & DRM_MODE_FLAG_INTERLACE);
video->v_sync_polarity = !!(mode->flags & DRM_MODE_FLAG_NVSYNC);
video->h_sync_polarity = !!(mode->flags & DRM_MODE_FLAG_NHSYNC);
vic = drm_match_cea_mode(mode);
if ((vic == 6) || (vic == 7) || (vic == 21) || (vic == 22) ||
(vic == 2) || (vic == 3) || (vic == 17) || (vic == 18)) {
video->dynamic_range = CEA;
video->ycbcr_coeff = COLOR_YCBCR601;
} else if (vic) {
video->dynamic_range = CEA;
video->ycbcr_coeff = COLOR_YCBCR709;
} else {
video->dynamic_range = VESA;
video->ycbcr_coeff = COLOR_YCBCR709;
}
switch (display_info->bpc) {
case 12:
video->color_depth = COLOR_12;
break;
case 10:
video->color_depth = COLOR_10;
break;
case 8:
video->color_depth = COLOR_8;
break;
case 6:
video->color_depth = COLOR_6;
break;
default:
video->color_depth = COLOR_8;
break;
}
if (display_info->color_formats & DRM_COLOR_FORMAT_YCRCB444)
video->color_space = COLOR_YCBCR444;
else if (display_info->color_formats & DRM_COLOR_FORMAT_YCRCB422)
video->color_space = COLOR_YCBCR422;
else if (display_info->color_formats & DRM_COLOR_FORMAT_RGB444)
video->color_space = COLOR_RGB;
else
video->color_space = COLOR_RGB;
of_property_read_u32(dp_node, "samsung,color-space",
&video->color_space);
of_property_read_u32(dp_node, "samsung,dynamic-range",
&video->dynamic_range);
of_property_read_u32(dp_node, "samsung,ycbcr-coeff",
&video->ycbcr_coeff);
of_property_read_u32(dp_node, "samsung,color-depth",
&video->color_depth);
if (of_property_read_bool(dp_node, "hsync-active-high"))
video->h_sync_polarity = true;
if (of_property_read_bool(dp_node, "vsync-active-high"))
video->v_sync_polarity = true;
if (of_property_read_bool(dp_node, "interlaced"))
video->interlaced = true;
}
static void analogix_dp_bridge_nop(struct drm_bridge *bridge)
{
}
static int analogix_dp_create_bridge(struct drm_device *drm_dev,
struct analogix_dp_device *dp)
{
struct drm_bridge *bridge;
int ret;
bridge = devm_kzalloc(drm_dev->dev, sizeof(*bridge), GFP_KERNEL);
if (!bridge) {
DRM_ERROR("failed to allocate for drm bridge\n");
return -ENOMEM;
}
dp->bridge = bridge;
bridge->driver_private = dp;
bridge->funcs = &analogix_dp_bridge_funcs;
ret = drm_bridge_attach(dp->encoder, bridge, NULL);
if (ret) {
DRM_ERROR("failed to attach drm bridge\n");
return -EINVAL;
}
return 0;
}
static int analogix_dp_dt_parse_pdata(struct analogix_dp_device *dp)
{
struct device_node *dp_node = dp->dev->of_node;
struct video_info *video_info = &dp->video_info;
switch (dp->plat_data->dev_type) {
case RK3288_DP:
case RK3399_EDP:
video_info->max_link_rate = 0x0A;
video_info->max_lane_count = 0x04;
break;
case EXYNOS_DP:
of_property_read_u32(dp_node, "samsung,link-rate",
&video_info->max_link_rate);
of_property_read_u32(dp_node, "samsung,lane-count",
&video_info->max_lane_count);
break;
}
return 0;
}
static ssize_t analogix_dpaux_transfer(struct drm_dp_aux *aux,
struct drm_dp_aux_msg *msg)
{
struct analogix_dp_device *dp = to_dp(aux);
return analogix_dp_transfer(dp, msg);
}
int analogix_dp_bind(struct device *dev, struct drm_device *drm_dev,
struct analogix_dp_plat_data *plat_data)
{
struct platform_device *pdev = to_platform_device(dev);
struct analogix_dp_device *dp;
struct resource *res;
unsigned int irq_flags;
int ret;
if (!plat_data) {
dev_err(dev, "Invalided input plat_data\n");
return -EINVAL;
}
dp = devm_kzalloc(dev, sizeof(struct analogix_dp_device), GFP_KERNEL);
if (!dp)
return -ENOMEM;
dev_set_drvdata(dev, dp);
dp->dev = &pdev->dev;
dp->dpms_mode = DRM_MODE_DPMS_OFF;
mutex_init(&dp->panel_lock);
dp->panel_is_modeset = false;
dp->plat_data = plat_data;
ret = analogix_dp_dt_parse_pdata(dp);
if (ret)
return ret;
dp->phy = devm_phy_get(dp->dev, "dp");
if (IS_ERR(dp->phy)) {
dev_err(dp->dev, "no DP phy configured\n");
ret = PTR_ERR(dp->phy);
if (ret) {
if (ret == -ENOSYS || ret == -ENODEV)
dp->phy = NULL;
else
return ret;
}
}
dp->clock = devm_clk_get(&pdev->dev, "dp");
if (IS_ERR(dp->clock)) {
dev_err(&pdev->dev, "failed to get clock\n");
return PTR_ERR(dp->clock);
}
clk_prepare_enable(dp->clock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dp->reg_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(dp->reg_base))
return PTR_ERR(dp->reg_base);
dp->force_hpd = of_property_read_bool(dev->of_node, "force-hpd");
dp->hpd_gpio = of_get_named_gpio(dev->of_node, "hpd-gpios", 0);
if (!gpio_is_valid(dp->hpd_gpio))
dp->hpd_gpio = of_get_named_gpio(dev->of_node,
"samsung,hpd-gpio", 0);
if (gpio_is_valid(dp->hpd_gpio)) {
ret = devm_gpio_request_one(&pdev->dev, dp->hpd_gpio, GPIOF_IN,
"hpd_gpio");
if (ret) {
dev_err(&pdev->dev, "failed to get hpd gpio\n");
return ret;
}
dp->irq = gpio_to_irq(dp->hpd_gpio);
irq_flags = IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING;
} else {
dp->hpd_gpio = -ENODEV;
dp->irq = platform_get_irq(pdev, 0);
irq_flags = 0;
}
if (dp->irq == -ENXIO) {
dev_err(&pdev->dev, "failed to get irq\n");
return -ENODEV;
}
pm_runtime_enable(dev);
pm_runtime_get_sync(dev);
phy_power_on(dp->phy);
analogix_dp_init_dp(dp);
ret = devm_request_threaded_irq(&pdev->dev, dp->irq,
analogix_dp_hardirq,
analogix_dp_irq_thread,
irq_flags, "analogix-dp", dp);
if (ret) {
dev_err(&pdev->dev, "failed to request irq\n");
goto err_disable_pm_runtime;
}
disable_irq(dp->irq);
dp->drm_dev = drm_dev;
dp->encoder = dp->plat_data->encoder;
dp->aux.name = "DP-AUX";
dp->aux.transfer = analogix_dpaux_transfer;
dp->aux.dev = &pdev->dev;
ret = drm_dp_aux_register(&dp->aux);
if (ret)
goto err_disable_pm_runtime;
ret = analogix_dp_create_bridge(drm_dev, dp);
if (ret) {
DRM_ERROR("failed to create bridge (%d)\n", ret);
drm_encoder_cleanup(dp->encoder);
goto err_disable_pm_runtime;
}
phy_power_off(dp->phy);
pm_runtime_put(dev);
return 0;
err_disable_pm_runtime:
phy_power_off(dp->phy);
pm_runtime_put(dev);
pm_runtime_disable(dev);
return ret;
}
void analogix_dp_unbind(struct device *dev, struct device *master,
void *data)
{
struct analogix_dp_device *dp = dev_get_drvdata(dev);
analogix_dp_bridge_disable(dp->bridge);
if (dp->plat_data->panel) {
if (drm_panel_unprepare(dp->plat_data->panel))
DRM_ERROR("failed to turnoff the panel\n");
}
pm_runtime_disable(dev);
}
int analogix_dp_suspend(struct device *dev)
{
struct analogix_dp_device *dp = dev_get_drvdata(dev);
clk_disable_unprepare(dp->clock);
if (dp->plat_data->panel) {
if (drm_panel_unprepare(dp->plat_data->panel))
DRM_ERROR("failed to turnoff the panel\n");
}
return 0;
}
int analogix_dp_resume(struct device *dev)
{
struct analogix_dp_device *dp = dev_get_drvdata(dev);
int ret;
ret = clk_prepare_enable(dp->clock);
if (ret < 0) {
DRM_ERROR("Failed to prepare_enable the clock clk [%d]\n", ret);
return ret;
}
if (dp->plat_data->panel) {
if (drm_panel_prepare(dp->plat_data->panel)) {
DRM_ERROR("failed to setup the panel\n");
return -EBUSY;
}
}
return 0;
}
