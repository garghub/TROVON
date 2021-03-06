static void
intel_get_adjust_train(struct intel_dp *intel_dp,
const uint8_t link_status[DP_LINK_STATUS_SIZE])
{
uint8_t v = 0;
uint8_t p = 0;
int lane;
uint8_t voltage_max;
uint8_t preemph_max;
for (lane = 0; lane < intel_dp->lane_count; lane++) {
uint8_t this_v = drm_dp_get_adjust_request_voltage(link_status, lane);
uint8_t this_p = drm_dp_get_adjust_request_pre_emphasis(link_status, lane);
if (this_v > v)
v = this_v;
if (this_p > p)
p = this_p;
}
voltage_max = intel_dp_voltage_max(intel_dp);
if (v >= voltage_max)
v = voltage_max | DP_TRAIN_MAX_SWING_REACHED;
preemph_max = intel_dp_pre_emphasis_max(intel_dp, v);
if (p >= preemph_max)
p = preemph_max | DP_TRAIN_MAX_PRE_EMPHASIS_REACHED;
for (lane = 0; lane < 4; lane++)
intel_dp->train_set[lane] = v | p;
}
static bool
intel_dp_set_link_train(struct intel_dp *intel_dp,
uint8_t dp_train_pat)
{
uint8_t buf[sizeof(intel_dp->train_set) + 1];
int ret, len;
intel_dp_program_link_training_pattern(intel_dp, dp_train_pat);
buf[0] = dp_train_pat;
if ((dp_train_pat & DP_TRAINING_PATTERN_MASK) ==
DP_TRAINING_PATTERN_DISABLE) {
len = 1;
} else {
memcpy(buf + 1, intel_dp->train_set, intel_dp->lane_count);
len = intel_dp->lane_count + 1;
}
ret = drm_dp_dpcd_write(&intel_dp->aux, DP_TRAINING_PATTERN_SET,
buf, len);
return ret == len;
}
static bool
intel_dp_reset_link_train(struct intel_dp *intel_dp,
uint8_t dp_train_pat)
{
memset(intel_dp->train_set, 0, sizeof(intel_dp->train_set));
intel_dp_set_signal_levels(intel_dp);
return intel_dp_set_link_train(intel_dp, dp_train_pat);
}
static bool
intel_dp_update_link_train(struct intel_dp *intel_dp)
{
int ret;
intel_dp_set_signal_levels(intel_dp);
ret = drm_dp_dpcd_write(&intel_dp->aux, DP_TRAINING_LANE0_SET,
intel_dp->train_set, intel_dp->lane_count);
return ret == intel_dp->lane_count;
}
static void
intel_dp_link_training_clock_recovery(struct intel_dp *intel_dp)
{
int i;
uint8_t voltage;
int voltage_tries, loop_tries;
uint8_t link_config[2];
uint8_t link_bw, rate_select;
if (intel_dp->prepare_link_retrain)
intel_dp->prepare_link_retrain(intel_dp);
intel_dp_compute_rate(intel_dp, intel_dp->link_rate,
&link_bw, &rate_select);
link_config[0] = link_bw;
link_config[1] = intel_dp->lane_count;
if (drm_dp_enhanced_frame_cap(intel_dp->dpcd))
link_config[1] |= DP_LANE_COUNT_ENHANCED_FRAME_EN;
drm_dp_dpcd_write(&intel_dp->aux, DP_LINK_BW_SET, link_config, 2);
if (intel_dp->num_sink_rates)
drm_dp_dpcd_write(&intel_dp->aux, DP_LINK_RATE_SET,
&rate_select, 1);
link_config[0] = 0;
link_config[1] = DP_SET_ANSI_8B10B;
drm_dp_dpcd_write(&intel_dp->aux, DP_DOWNSPREAD_CTRL, link_config, 2);
intel_dp->DP |= DP_PORT_EN;
if (!intel_dp_reset_link_train(intel_dp,
DP_TRAINING_PATTERN_1 |
DP_LINK_SCRAMBLING_DISABLE)) {
DRM_ERROR("failed to enable link training\n");
return;
}
voltage = 0xff;
voltage_tries = 0;
loop_tries = 0;
for (;;) {
uint8_t link_status[DP_LINK_STATUS_SIZE];
drm_dp_link_train_clock_recovery_delay(intel_dp->dpcd);
if (!intel_dp_get_link_status(intel_dp, link_status)) {
DRM_ERROR("failed to get link status\n");
break;
}
if (drm_dp_clock_recovery_ok(link_status, intel_dp->lane_count)) {
DRM_DEBUG_KMS("clock recovery OK\n");
break;
}
for (i = 0; i < intel_dp->lane_count; i++)
if ((intel_dp->train_set[i] & DP_TRAIN_MAX_SWING_REACHED) == 0)
break;
if (i == intel_dp->lane_count) {
++loop_tries;
if (loop_tries == 5) {
DRM_ERROR("too many full retries, give up\n");
break;
}
intel_dp_reset_link_train(intel_dp,
DP_TRAINING_PATTERN_1 |
DP_LINK_SCRAMBLING_DISABLE);
voltage_tries = 0;
continue;
}
if ((intel_dp->train_set[0] & DP_TRAIN_VOLTAGE_SWING_MASK) == voltage) {
++voltage_tries;
if (voltage_tries == 5) {
DRM_ERROR("too many voltage retries, give up\n");
break;
}
} else
voltage_tries = 0;
voltage = intel_dp->train_set[0] & DP_TRAIN_VOLTAGE_SWING_MASK;
intel_get_adjust_train(intel_dp, link_status);
if (!intel_dp_update_link_train(intel_dp)) {
DRM_ERROR("failed to update link training\n");
break;
}
}
}
static u32 intel_dp_training_pattern(struct intel_dp *intel_dp)
{
u32 training_pattern = DP_TRAINING_PATTERN_2;
bool source_tps3, sink_tps3;
source_tps3 = intel_dp_source_supports_hbr2(intel_dp);
sink_tps3 = drm_dp_tps3_supported(intel_dp->dpcd);
if (source_tps3 && sink_tps3) {
training_pattern = DP_TRAINING_PATTERN_3;
} else if (intel_dp->link_rate == 540000) {
if (!source_tps3)
DRM_DEBUG_KMS("5.4 Gbps link rate without source HBR2/TPS3 support\n");
if (!sink_tps3)
DRM_DEBUG_KMS("5.4 Gbps link rate without sink TPS3 support\n");
}
return training_pattern;
}
static void
intel_dp_link_training_channel_equalization(struct intel_dp *intel_dp)
{
bool channel_eq = false;
int tries, cr_tries;
u32 training_pattern;
training_pattern = intel_dp_training_pattern(intel_dp);
if (!intel_dp_set_link_train(intel_dp,
training_pattern |
DP_LINK_SCRAMBLING_DISABLE)) {
DRM_ERROR("failed to start channel equalization\n");
return;
}
tries = 0;
cr_tries = 0;
channel_eq = false;
for (;;) {
uint8_t link_status[DP_LINK_STATUS_SIZE];
if (cr_tries > 5) {
DRM_ERROR("failed to train DP, aborting\n");
break;
}
drm_dp_link_train_channel_eq_delay(intel_dp->dpcd);
if (!intel_dp_get_link_status(intel_dp, link_status)) {
DRM_ERROR("failed to get link status\n");
break;
}
if (!drm_dp_clock_recovery_ok(link_status,
intel_dp->lane_count)) {
intel_dp_link_training_clock_recovery(intel_dp);
intel_dp_set_link_train(intel_dp,
training_pattern |
DP_LINK_SCRAMBLING_DISABLE);
cr_tries++;
continue;
}
if (drm_dp_channel_eq_ok(link_status,
intel_dp->lane_count)) {
channel_eq = true;
break;
}
if (tries > 5) {
intel_dp_link_training_clock_recovery(intel_dp);
intel_dp_set_link_train(intel_dp,
training_pattern |
DP_LINK_SCRAMBLING_DISABLE);
tries = 0;
cr_tries++;
continue;
}
intel_get_adjust_train(intel_dp, link_status);
if (!intel_dp_update_link_train(intel_dp)) {
DRM_ERROR("failed to update link training\n");
break;
}
++tries;
}
intel_dp_set_idle_link_train(intel_dp);
if (channel_eq)
DRM_DEBUG_KMS("Channel EQ done. DP Training successful\n");
}
void intel_dp_stop_link_train(struct intel_dp *intel_dp)
{
intel_dp_set_link_train(intel_dp,
DP_TRAINING_PATTERN_DISABLE);
}
void
intel_dp_start_link_train(struct intel_dp *intel_dp)
{
intel_dp_link_training_clock_recovery(intel_dp);
intel_dp_link_training_channel_equalization(intel_dp);
}
