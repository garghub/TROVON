static int edp_clk_init(struct edp_ctrl *ctrl)
{
struct device *dev = &ctrl->pdev->dev;
int ret;
ctrl->aux_clk = devm_clk_get(dev, "core_clk");
if (IS_ERR(ctrl->aux_clk)) {
ret = PTR_ERR(ctrl->aux_clk);
pr_err("%s: Can't find aux_clk, %d\n", __func__, ret);
ctrl->aux_clk = NULL;
return ret;
}
ctrl->pixel_clk = devm_clk_get(dev, "pixel_clk");
if (IS_ERR(ctrl->pixel_clk)) {
ret = PTR_ERR(ctrl->pixel_clk);
pr_err("%s: Can't find pixel_clk, %d\n", __func__, ret);
ctrl->pixel_clk = NULL;
return ret;
}
ctrl->ahb_clk = devm_clk_get(dev, "iface_clk");
if (IS_ERR(ctrl->ahb_clk)) {
ret = PTR_ERR(ctrl->ahb_clk);
pr_err("%s: Can't find ahb_clk, %d\n", __func__, ret);
ctrl->ahb_clk = NULL;
return ret;
}
ctrl->link_clk = devm_clk_get(dev, "link_clk");
if (IS_ERR(ctrl->link_clk)) {
ret = PTR_ERR(ctrl->link_clk);
pr_err("%s: Can't find link_clk, %d\n", __func__, ret);
ctrl->link_clk = NULL;
return ret;
}
ctrl->mdp_core_clk = devm_clk_get(dev, "mdp_core_clk");
if (IS_ERR(ctrl->mdp_core_clk)) {
ret = PTR_ERR(ctrl->mdp_core_clk);
pr_err("%s: Can't find mdp_core_clk, %d\n", __func__, ret);
ctrl->mdp_core_clk = NULL;
return ret;
}
return 0;
}
static int edp_clk_enable(struct edp_ctrl *ctrl, u32 clk_mask)
{
int ret;
DBG("mask=%x", clk_mask);
if (clk_mask & EDP_CLK_MASK_AHB) {
ret = clk_prepare_enable(ctrl->ahb_clk);
if (ret) {
pr_err("%s: Failed to enable ahb clk\n", __func__);
goto f0;
}
}
if (clk_mask & EDP_CLK_MASK_AUX) {
ret = clk_set_rate(ctrl->aux_clk, 19200000);
if (ret) {
pr_err("%s: Failed to set rate aux clk\n", __func__);
goto f1;
}
ret = clk_prepare_enable(ctrl->aux_clk);
if (ret) {
pr_err("%s: Failed to enable aux clk\n", __func__);
goto f1;
}
}
if (clk_mask & EDP_CLK_MASK_LINK) {
DBG("edp->link_clk, set_rate %ld",
(unsigned long)ctrl->link_rate * 27000000);
ret = clk_set_rate(ctrl->link_clk,
(unsigned long)ctrl->link_rate * 27000000);
if (ret) {
pr_err("%s: Failed to set rate to link clk\n",
__func__);
goto f2;
}
ret = clk_prepare_enable(ctrl->link_clk);
if (ret) {
pr_err("%s: Failed to enable link clk\n", __func__);
goto f2;
}
}
if (clk_mask & EDP_CLK_MASK_PIXEL) {
DBG("edp->pixel_clk, set_rate %ld",
(unsigned long)ctrl->pixel_rate * 1000);
ret = clk_set_rate(ctrl->pixel_clk,
(unsigned long)ctrl->pixel_rate * 1000);
if (ret) {
pr_err("%s: Failed to set rate to pixel clk\n",
__func__);
goto f3;
}
ret = clk_prepare_enable(ctrl->pixel_clk);
if (ret) {
pr_err("%s: Failed to enable pixel clk\n", __func__);
goto f3;
}
}
if (clk_mask & EDP_CLK_MASK_MDP_CORE) {
ret = clk_prepare_enable(ctrl->mdp_core_clk);
if (ret) {
pr_err("%s: Failed to enable mdp core clk\n", __func__);
goto f4;
}
}
return 0;
f4:
if (clk_mask & EDP_CLK_MASK_PIXEL)
clk_disable_unprepare(ctrl->pixel_clk);
f3:
if (clk_mask & EDP_CLK_MASK_LINK)
clk_disable_unprepare(ctrl->link_clk);
f2:
if (clk_mask & EDP_CLK_MASK_AUX)
clk_disable_unprepare(ctrl->aux_clk);
f1:
if (clk_mask & EDP_CLK_MASK_AHB)
clk_disable_unprepare(ctrl->ahb_clk);
f0:
return ret;
}
static void edp_clk_disable(struct edp_ctrl *ctrl, u32 clk_mask)
{
if (clk_mask & EDP_CLK_MASK_MDP_CORE)
clk_disable_unprepare(ctrl->mdp_core_clk);
if (clk_mask & EDP_CLK_MASK_PIXEL)
clk_disable_unprepare(ctrl->pixel_clk);
if (clk_mask & EDP_CLK_MASK_LINK)
clk_disable_unprepare(ctrl->link_clk);
if (clk_mask & EDP_CLK_MASK_AUX)
clk_disable_unprepare(ctrl->aux_clk);
if (clk_mask & EDP_CLK_MASK_AHB)
clk_disable_unprepare(ctrl->ahb_clk);
}
static int edp_regulator_init(struct edp_ctrl *ctrl)
{
struct device *dev = &ctrl->pdev->dev;
DBG("");
ctrl->vdda_vreg = devm_regulator_get(dev, "vdda");
if (IS_ERR(ctrl->vdda_vreg)) {
pr_err("%s: Could not get vdda reg, ret = %ld\n", __func__,
PTR_ERR(ctrl->vdda_vreg));
ctrl->vdda_vreg = NULL;
return PTR_ERR(ctrl->vdda_vreg);
}
ctrl->lvl_vreg = devm_regulator_get(dev, "lvl-vdd");
if (IS_ERR(ctrl->lvl_vreg)) {
pr_err("Could not get lvl-vdd reg, %ld",
PTR_ERR(ctrl->lvl_vreg));
ctrl->lvl_vreg = NULL;
return PTR_ERR(ctrl->lvl_vreg);
}
return 0;
}
static int edp_regulator_enable(struct edp_ctrl *ctrl)
{
int ret;
ret = regulator_set_voltage(ctrl->vdda_vreg, VDDA_MIN_UV, VDDA_MAX_UV);
if (ret) {
pr_err("%s:vdda_vreg set_voltage failed, %d\n", __func__, ret);
goto vdda_set_fail;
}
ret = regulator_set_optimum_mode(ctrl->vdda_vreg, VDDA_UA_ON_LOAD);
if (ret < 0) {
pr_err("%s: vdda_vreg set regulator mode failed.\n", __func__);
goto vdda_set_fail;
}
ret = regulator_enable(ctrl->vdda_vreg);
if (ret) {
pr_err("%s: Failed to enable vdda_vreg regulator.\n", __func__);
goto vdda_enable_fail;
}
ret = regulator_enable(ctrl->lvl_vreg);
if (ret) {
pr_err("Failed to enable lvl-vdd reg regulator, %d", ret);
goto lvl_enable_fail;
}
DBG("exit");
return 0;
lvl_enable_fail:
regulator_disable(ctrl->vdda_vreg);
vdda_enable_fail:
regulator_set_optimum_mode(ctrl->vdda_vreg, VDDA_UA_OFF_LOAD);
vdda_set_fail:
return ret;
}
static void edp_regulator_disable(struct edp_ctrl *ctrl)
{
regulator_disable(ctrl->lvl_vreg);
regulator_disable(ctrl->vdda_vreg);
regulator_set_optimum_mode(ctrl->vdda_vreg, VDDA_UA_OFF_LOAD);
}
static int edp_gpio_config(struct edp_ctrl *ctrl)
{
struct device *dev = &ctrl->pdev->dev;
int ret;
ctrl->panel_hpd_gpio = devm_gpiod_get(dev, "panel-hpd");
if (IS_ERR(ctrl->panel_hpd_gpio)) {
ret = PTR_ERR(ctrl->panel_hpd_gpio);
ctrl->panel_hpd_gpio = NULL;
pr_err("%s: cannot get panel-hpd-gpios, %d\n", __func__, ret);
return ret;
}
ret = gpiod_direction_input(ctrl->panel_hpd_gpio);
if (ret) {
pr_err("%s: Set direction for hpd failed, %d\n", __func__, ret);
return ret;
}
ctrl->panel_en_gpio = devm_gpiod_get(dev, "panel-en");
if (IS_ERR(ctrl->panel_en_gpio)) {
ret = PTR_ERR(ctrl->panel_en_gpio);
ctrl->panel_en_gpio = NULL;
pr_err("%s: cannot get panel-en-gpios, %d\n", __func__, ret);
return ret;
}
ret = gpiod_direction_output(ctrl->panel_en_gpio, 0);
if (ret) {
pr_err("%s: Set direction for panel_en failed, %d\n",
__func__, ret);
return ret;
}
DBG("gpio on");
return 0;
}
static void edp_ctrl_irq_enable(struct edp_ctrl *ctrl, int enable)
{
unsigned long flags;
DBG("%d", enable);
spin_lock_irqsave(&ctrl->irq_lock, flags);
if (enable) {
edp_write(ctrl->base + REG_EDP_INTERRUPT_REG_1, EDP_INTR_MASK1);
edp_write(ctrl->base + REG_EDP_INTERRUPT_REG_2, EDP_INTR_MASK2);
} else {
edp_write(ctrl->base + REG_EDP_INTERRUPT_REG_1, 0x0);
edp_write(ctrl->base + REG_EDP_INTERRUPT_REG_2, 0x0);
}
spin_unlock_irqrestore(&ctrl->irq_lock, flags);
DBG("exit");
}
static void edp_fill_link_cfg(struct edp_ctrl *ctrl)
{
u32 prate;
u32 lrate;
u32 bpp;
u8 max_lane = ctrl->dp_link.num_lanes;
u8 lane;
prate = ctrl->pixel_rate;
bpp = ctrl->color_depth * 3;
ctrl->link_rate = drm_dp_link_rate_to_bw_code(ctrl->dp_link.rate);
prate *= bpp;
prate /= 8;
lrate = 270000;
lrate *= ctrl->link_rate;
lrate /= 10;
for (lane = 1; lane <= max_lane; lane <<= 1) {
if (lrate >= prate)
break;
lrate <<= 1;
}
ctrl->lane_cnt = lane;
DBG("rate=%d lane=%d", ctrl->link_rate, ctrl->lane_cnt);
}
static void edp_config_ctrl(struct edp_ctrl *ctrl)
{
u32 data;
enum edp_color_depth depth;
data = EDP_CONFIGURATION_CTRL_LANES(ctrl->lane_cnt - 1);
if (ctrl->dp_link.capabilities & DP_LINK_CAP_ENHANCED_FRAMING)
data |= EDP_CONFIGURATION_CTRL_ENHANCED_FRAMING;
depth = EDP_6BIT;
if (ctrl->color_depth == 8)
depth = EDP_8BIT;
data |= EDP_CONFIGURATION_CTRL_COLOR(depth);
if (!ctrl->interlaced)
data |= EDP_CONFIGURATION_CTRL_PROGRESSIVE;
data |= (EDP_CONFIGURATION_CTRL_SYNC_CLK |
EDP_CONFIGURATION_CTRL_STATIC_MVID);
edp_write(ctrl->base + REG_EDP_CONFIGURATION_CTRL, data);
}
static void edp_state_ctrl(struct edp_ctrl *ctrl, u32 state)
{
edp_write(ctrl->base + REG_EDP_STATE_CTRL, state);
wmb();
}
static int edp_lane_set_write(struct edp_ctrl *ctrl,
u8 voltage_level, u8 pre_emphasis_level)
{
int i;
u8 buf[4];
if (voltage_level >= DPCD_LINK_VOLTAGE_MAX)
voltage_level |= 0x04;
if (pre_emphasis_level >= DPCD_LINK_PRE_EMPHASIS_MAX)
pre_emphasis_level |= 0x04;
pre_emphasis_level <<= 3;
for (i = 0; i < 4; i++)
buf[i] = voltage_level | pre_emphasis_level;
DBG("%s: p|v=0x%x", __func__, voltage_level | pre_emphasis_level);
if (drm_dp_dpcd_write(ctrl->drm_aux, 0x103, buf, 4) < 4) {
pr_err("%s: Set sw/pe to panel failed\n", __func__);
return -ENOLINK;
}
return 0;
}
static int edp_train_pattern_set_write(struct edp_ctrl *ctrl, u8 pattern)
{
u8 p = pattern;
DBG("pattern=%x", p);
if (drm_dp_dpcd_write(ctrl->drm_aux,
DP_TRAINING_PATTERN_SET, &p, 1) < 1) {
pr_err("%s: Set training pattern to panel failed\n", __func__);
return -ENOLINK;
}
return 0;
}
static void edp_sink_train_set_adjust(struct edp_ctrl *ctrl,
const u8 *link_status)
{
int i;
u8 max = 0;
u8 data;
for (i = 0; i < ctrl->lane_cnt; i++) {
data = drm_dp_get_adjust_request_voltage(link_status, i);
DBG("lane=%d req_voltage_swing=0x%x", i, data);
if (max < data)
max = data;
}
ctrl->v_level = max >> DP_TRAIN_VOLTAGE_SWING_SHIFT;
max = 0;
for (i = 0; i < ctrl->lane_cnt; i++) {
data = drm_dp_get_adjust_request_pre_emphasis(link_status, i);
DBG("lane=%d req_pre_emphasis=0x%x", i, data);
if (max < data)
max = data;
}
ctrl->p_level = max >> DP_TRAIN_PRE_EMPHASIS_SHIFT;
DBG("v_level=%d, p_level=%d", ctrl->v_level, ctrl->p_level);
}
static void edp_host_train_set(struct edp_ctrl *ctrl, u32 train)
{
int cnt = 10;
u32 data;
u32 shift = train - 1;
DBG("train=%d", train);
edp_state_ctrl(ctrl, EDP_STATE_CTRL_TRAIN_PATTERN_1 << shift);
while (--cnt) {
data = edp_read(ctrl->base + REG_EDP_MAINLINK_READY);
if (data & (EDP_MAINLINK_READY_TRAIN_PATTERN_1_READY << shift))
break;
}
if (cnt == 0)
pr_err("%s: set link_train=%d failed\n", __func__, train);
}
static int edp_voltage_pre_emphasise_set(struct edp_ctrl *ctrl)
{
u32 value0;
u32 value1;
DBG("v=%d p=%d", ctrl->v_level, ctrl->p_level);
value0 = vm_pre_emphasis[(int)(ctrl->v_level)][(int)(ctrl->p_level)];
value1 = vm_voltage_swing[(int)(ctrl->v_level)][(int)(ctrl->p_level)];
if (value0 != 0xFF && value1 != 0xFF) {
msm_edp_phy_vm_pe_cfg(ctrl->phy, value0, value1);
return edp_lane_set_write(ctrl, ctrl->v_level, ctrl->p_level);
}
return -EINVAL;
}
static int edp_start_link_train_1(struct edp_ctrl *ctrl)
{
u8 link_status[DP_LINK_STATUS_SIZE];
u8 old_v_level;
int tries;
int ret;
int rlen;
DBG("");
edp_host_train_set(ctrl, DP_TRAINING_PATTERN_1);
ret = edp_voltage_pre_emphasise_set(ctrl);
if (ret)
return ret;
ret = edp_train_pattern_set_write(ctrl,
DP_TRAINING_PATTERN_1 | DP_RECOVERED_CLOCK_OUT_EN);
if (ret)
return ret;
tries = 0;
old_v_level = ctrl->v_level;
while (1) {
drm_dp_link_train_clock_recovery_delay(ctrl->dpcd);
rlen = drm_dp_dpcd_read_link_status(ctrl->drm_aux, link_status);
if (rlen < DP_LINK_STATUS_SIZE) {
pr_err("%s: read link status failed\n", __func__);
return -ENOLINK;
}
if (drm_dp_clock_recovery_ok(link_status, ctrl->lane_cnt)) {
ret = 0;
break;
}
if (ctrl->v_level == DPCD_LINK_VOLTAGE_MAX) {
ret = -1;
break;
}
if (old_v_level == ctrl->v_level) {
tries++;
if (tries >= 5) {
ret = -1;
break;
}
} else {
tries = 0;
old_v_level = ctrl->v_level;
}
edp_sink_train_set_adjust(ctrl, link_status);
ret = edp_voltage_pre_emphasise_set(ctrl);
if (ret)
return ret;
}
return ret;
}
static int edp_start_link_train_2(struct edp_ctrl *ctrl)
{
u8 link_status[DP_LINK_STATUS_SIZE];
int tries = 0;
int ret;
int rlen;
DBG("");
edp_host_train_set(ctrl, DP_TRAINING_PATTERN_2);
ret = edp_voltage_pre_emphasise_set(ctrl);
if (ret)
return ret;
ret = edp_train_pattern_set_write(ctrl,
DP_TRAINING_PATTERN_2 | DP_RECOVERED_CLOCK_OUT_EN);
if (ret)
return ret;
while (1) {
drm_dp_link_train_channel_eq_delay(ctrl->dpcd);
rlen = drm_dp_dpcd_read_link_status(ctrl->drm_aux, link_status);
if (rlen < DP_LINK_STATUS_SIZE) {
pr_err("%s: read link status failed\n", __func__);
return -ENOLINK;
}
if (drm_dp_channel_eq_ok(link_status, ctrl->lane_cnt)) {
ret = 0;
break;
}
tries++;
if (tries > 10) {
ret = -1;
break;
}
edp_sink_train_set_adjust(ctrl, link_status);
ret = edp_voltage_pre_emphasise_set(ctrl);
if (ret)
return ret;
}
return ret;
}
static int edp_link_rate_down_shift(struct edp_ctrl *ctrl)
{
u32 prate, lrate, bpp;
u8 rate, lane, max_lane;
int changed = 0;
rate = ctrl->link_rate;
lane = ctrl->lane_cnt;
max_lane = ctrl->dp_link.num_lanes;
bpp = ctrl->color_depth * 3;
prate = ctrl->pixel_rate;
prate *= bpp;
prate /= 8;
if (rate > DP_LINK_BW_1_62 && rate <= EDP_LINK_BW_MAX) {
rate -= 4;
changed++;
}
if (changed) {
if (lane >= 1 && lane < max_lane)
lane <<= 1;
lrate = 270000;
lrate *= rate;
lrate /= 10;
lrate *= lane;
DBG("new lrate=%u prate=%u(kHz) rate=%d lane=%d p=%u b=%d",
lrate, prate, rate, lane,
ctrl->pixel_rate,
bpp);
if (lrate > prate) {
ctrl->link_rate = rate;
ctrl->lane_cnt = lane;
DBG("new rate=%d %d", rate, lane);
return 0;
}
}
return -EINVAL;
}
static int edp_clear_training_pattern(struct edp_ctrl *ctrl)
{
int ret;
ret = edp_train_pattern_set_write(ctrl, 0);
drm_dp_link_train_channel_eq_delay(ctrl->dpcd);
return ret;
}
static int edp_do_link_train(struct edp_ctrl *ctrl)
{
int ret;
struct drm_dp_link dp_link;
DBG("");
dp_link.num_lanes = ctrl->lane_cnt;
dp_link.rate = drm_dp_bw_code_to_link_rate(ctrl->link_rate);
dp_link.capabilities = ctrl->dp_link.capabilities;
if (drm_dp_link_configure(ctrl->drm_aux, &dp_link) < 0)
return EDP_TRAIN_FAIL;
ctrl->v_level = 0;
ctrl->p_level = 0;
edp_state_ctrl(ctrl, 0);
if (edp_clear_training_pattern(ctrl))
return EDP_TRAIN_FAIL;
ret = edp_start_link_train_1(ctrl);
if (ret < 0) {
if (edp_link_rate_down_shift(ctrl) == 0) {
DBG("link reconfig");
ret = EDP_TRAIN_RECONFIG;
goto clear;
} else {
pr_err("%s: Training 1 failed", __func__);
ret = EDP_TRAIN_FAIL;
goto clear;
}
}
DBG("Training 1 completed successfully");
edp_state_ctrl(ctrl, 0);
if (edp_clear_training_pattern(ctrl))
return EDP_TRAIN_FAIL;
ret = edp_start_link_train_2(ctrl);
if (ret < 0) {
if (edp_link_rate_down_shift(ctrl) == 0) {
DBG("link reconfig");
ret = EDP_TRAIN_RECONFIG;
goto clear;
} else {
pr_err("%s: Training 2 failed", __func__);
ret = EDP_TRAIN_FAIL;
goto clear;
}
}
DBG("Training 2 completed successfully");
edp_state_ctrl(ctrl, EDP_STATE_CTRL_SEND_VIDEO);
clear:
edp_clear_training_pattern(ctrl);
return ret;
}
static void edp_clock_synchrous(struct edp_ctrl *ctrl, int sync)
{
u32 data;
enum edp_color_depth depth;
data = edp_read(ctrl->base + REG_EDP_MISC1_MISC0);
if (sync)
data |= EDP_MISC1_MISC0_SYNC;
else
data &= ~EDP_MISC1_MISC0_SYNC;
depth = EDP_6BIT;
if (ctrl->color_depth == 8)
depth = EDP_8BIT;
else if (ctrl->color_depth == 10)
depth = EDP_10BIT;
else if (ctrl->color_depth == 12)
depth = EDP_12BIT;
else if (ctrl->color_depth == 16)
depth = EDP_16BIT;
data |= EDP_MISC1_MISC0_COLOR(depth);
edp_write(ctrl->base + REG_EDP_MISC1_MISC0, data);
}
static int edp_sw_mvid_nvid(struct edp_ctrl *ctrl, u32 m, u32 n)
{
u32 n_multi, m_multi = 5;
if (ctrl->link_rate == DP_LINK_BW_1_62) {
n_multi = 1;
} else if (ctrl->link_rate == DP_LINK_BW_2_7) {
n_multi = 2;
} else {
pr_err("%s: Invalid link rate, %d\n", __func__,
ctrl->link_rate);
return -EINVAL;
}
edp_write(ctrl->base + REG_EDP_SOFTWARE_MVID, m * m_multi);
edp_write(ctrl->base + REG_EDP_SOFTWARE_NVID, n * n_multi);
return 0;
}
static void edp_mainlink_ctrl(struct edp_ctrl *ctrl, int enable)
{
u32 data = 0;
edp_write(ctrl->base + REG_EDP_MAINLINK_CTRL, EDP_MAINLINK_CTRL_RESET);
wmb();
usleep_range(500, 1000);
if (enable)
data |= EDP_MAINLINK_CTRL_ENABLE;
edp_write(ctrl->base + REG_EDP_MAINLINK_CTRL, data);
}
static void edp_ctrl_phy_aux_enable(struct edp_ctrl *ctrl, int enable)
{
if (enable) {
edp_regulator_enable(ctrl);
edp_clk_enable(ctrl, EDP_CLK_MASK_AUX_CHAN);
msm_edp_phy_ctrl(ctrl->phy, 1);
msm_edp_aux_ctrl(ctrl->aux, 1);
gpiod_set_value(ctrl->panel_en_gpio, 1);
} else {
gpiod_set_value(ctrl->panel_en_gpio, 0);
msm_edp_aux_ctrl(ctrl->aux, 0);
msm_edp_phy_ctrl(ctrl->phy, 0);
edp_clk_disable(ctrl, EDP_CLK_MASK_AUX_CHAN);
edp_regulator_disable(ctrl);
}
}
static void edp_ctrl_link_enable(struct edp_ctrl *ctrl, int enable)
{
u32 m, n;
if (enable) {
edp_clk_enable(ctrl, EDP_CLK_MASK_LINK_CHAN);
msm_edp_phy_lane_power_ctrl(ctrl->phy, true, ctrl->lane_cnt);
msm_edp_phy_vm_pe_init(ctrl->phy);
wmb();
msm_edp_phy_ready(ctrl->phy);
edp_config_ctrl(ctrl);
msm_edp_ctrl_pixel_clock_valid(ctrl, ctrl->pixel_rate, &m, &n);
edp_sw_mvid_nvid(ctrl, m, n);
edp_mainlink_ctrl(ctrl, 1);
} else {
edp_mainlink_ctrl(ctrl, 0);
msm_edp_phy_lane_power_ctrl(ctrl->phy, false, 0);
edp_clk_disable(ctrl, EDP_CLK_MASK_LINK_CHAN);
}
}
static int edp_ctrl_training(struct edp_ctrl *ctrl)
{
int ret;
if (!ctrl->power_on)
return -EINVAL;
train_start:
ret = edp_do_link_train(ctrl);
if (ret == EDP_TRAIN_RECONFIG) {
edp_ctrl_irq_enable(ctrl, 0);
edp_ctrl_link_enable(ctrl, 0);
msm_edp_phy_ctrl(ctrl->phy, 0);
wmb();
usleep_range(500, 1000);
msm_edp_phy_ctrl(ctrl->phy, 1);
edp_ctrl_link_enable(ctrl, 1);
edp_ctrl_irq_enable(ctrl, 1);
goto train_start;
}
return ret;
}
static void edp_ctrl_on_worker(struct work_struct *work)
{
struct edp_ctrl *ctrl = container_of(
work, struct edp_ctrl, on_work);
int ret;
mutex_lock(&ctrl->dev_mutex);
if (ctrl->power_on) {
DBG("already on");
goto unlock_ret;
}
edp_ctrl_phy_aux_enable(ctrl, 1);
edp_ctrl_link_enable(ctrl, 1);
edp_ctrl_irq_enable(ctrl, 1);
ret = drm_dp_link_power_up(ctrl->drm_aux, &ctrl->dp_link);
if (ret)
goto fail;
ctrl->power_on = true;
ret = edp_ctrl_training(ctrl);
if (ret != EDP_TRAIN_SUCCESS)
goto fail;
DBG("DONE");
goto unlock_ret;
fail:
edp_ctrl_irq_enable(ctrl, 0);
edp_ctrl_link_enable(ctrl, 0);
edp_ctrl_phy_aux_enable(ctrl, 0);
ctrl->power_on = false;
unlock_ret:
mutex_unlock(&ctrl->dev_mutex);
}
static void edp_ctrl_off_worker(struct work_struct *work)
{
struct edp_ctrl *ctrl = container_of(
work, struct edp_ctrl, off_work);
int ret;
mutex_lock(&ctrl->dev_mutex);
if (!ctrl->power_on) {
DBG("already off");
goto unlock_ret;
}
reinit_completion(&ctrl->idle_comp);
edp_state_ctrl(ctrl, EDP_STATE_CTRL_PUSH_IDLE);
ret = wait_for_completion_timeout(&ctrl->idle_comp,
msecs_to_jiffies(500));
if (ret <= 0)
DBG("%s: idle pattern timedout, %d\n",
__func__, ret);
edp_state_ctrl(ctrl, 0);
drm_dp_link_power_down(ctrl->drm_aux, &ctrl->dp_link);
edp_ctrl_irq_enable(ctrl, 0);
edp_ctrl_link_enable(ctrl, 0);
edp_ctrl_phy_aux_enable(ctrl, 0);
ctrl->power_on = false;
unlock_ret:
mutex_unlock(&ctrl->dev_mutex);
}
irqreturn_t msm_edp_ctrl_irq(struct edp_ctrl *ctrl)
{
u32 isr1, isr2, mask1, mask2;
u32 ack;
DBG("");
spin_lock(&ctrl->irq_lock);
isr1 = edp_read(ctrl->base + REG_EDP_INTERRUPT_REG_1);
isr2 = edp_read(ctrl->base + REG_EDP_INTERRUPT_REG_2);
mask1 = isr1 & EDP_INTR_MASK1;
mask2 = isr2 & EDP_INTR_MASK2;
isr1 &= ~mask1;
isr2 &= ~mask2;
DBG("isr=%x mask=%x isr2=%x mask2=%x",
isr1, mask1, isr2, mask2);
ack = isr1 & EDP_INTR_STATUS1;
ack <<= 1;
ack |= mask1;
edp_write(ctrl->base + REG_EDP_INTERRUPT_REG_1, ack);
ack = isr2 & EDP_INTR_STATUS2;
ack <<= 1;
ack |= mask2;
edp_write(ctrl->base + REG_EDP_INTERRUPT_REG_2, ack);
spin_unlock(&ctrl->irq_lock);
if (isr1 & EDP_INTERRUPT_REG_1_HPD)
DBG("edp_hpd");
if (isr2 & EDP_INTERRUPT_REG_2_READY_FOR_VIDEO)
DBG("edp_video_ready");
if (isr2 & EDP_INTERRUPT_REG_2_IDLE_PATTERNs_SENT) {
DBG("idle_patterns_sent");
complete(&ctrl->idle_comp);
}
msm_edp_aux_irq(ctrl->aux, isr1);
return IRQ_HANDLED;
}
void msm_edp_ctrl_power(struct edp_ctrl *ctrl, bool on)
{
if (on)
queue_work(ctrl->workqueue, &ctrl->on_work);
else
queue_work(ctrl->workqueue, &ctrl->off_work);
}
int msm_edp_ctrl_init(struct msm_edp *edp)
{
struct edp_ctrl *ctrl = NULL;
struct device *dev = &edp->pdev->dev;
int ret;
if (!edp) {
pr_err("%s: edp is NULL!\n", __func__);
return -EINVAL;
}
ctrl = devm_kzalloc(dev, sizeof(*ctrl), GFP_KERNEL);
if (!ctrl)
return -ENOMEM;
edp->ctrl = ctrl;
ctrl->pdev = edp->pdev;
ctrl->base = msm_ioremap(ctrl->pdev, "edp", "eDP");
if (IS_ERR(ctrl->base))
return PTR_ERR(ctrl->base);
ret = edp_regulator_init(ctrl);
if (ret) {
pr_err("%s:regulator init fail\n", __func__);
return ret;
}
ret = edp_clk_init(ctrl);
if (ret) {
pr_err("%s:clk init fail\n", __func__);
return ret;
}
ret = edp_gpio_config(ctrl);
if (ret) {
pr_err("%s:failed to configure GPIOs: %d", __func__, ret);
return ret;
}
ctrl->aux = msm_edp_aux_init(dev, ctrl->base, &ctrl->drm_aux);
if (!ctrl->aux || !ctrl->drm_aux) {
pr_err("%s:failed to init aux\n", __func__);
return ret;
}
ctrl->phy = msm_edp_phy_init(dev, ctrl->base);
if (!ctrl->phy) {
pr_err("%s:failed to init phy\n", __func__);
goto err_destory_aux;
}
spin_lock_init(&ctrl->irq_lock);
mutex_init(&ctrl->dev_mutex);
init_completion(&ctrl->idle_comp);
ctrl->workqueue = alloc_ordered_workqueue("edp_drm_work", 0);
INIT_WORK(&ctrl->on_work, edp_ctrl_on_worker);
INIT_WORK(&ctrl->off_work, edp_ctrl_off_worker);
return 0;
err_destory_aux:
msm_edp_aux_destroy(dev, ctrl->aux);
ctrl->aux = NULL;
return ret;
}
void msm_edp_ctrl_destroy(struct edp_ctrl *ctrl)
{
if (!ctrl)
return;
if (ctrl->workqueue) {
flush_workqueue(ctrl->workqueue);
destroy_workqueue(ctrl->workqueue);
ctrl->workqueue = NULL;
}
if (ctrl->aux) {
msm_edp_aux_destroy(&ctrl->pdev->dev, ctrl->aux);
ctrl->aux = NULL;
}
kfree(ctrl->edid);
ctrl->edid = NULL;
mutex_destroy(&ctrl->dev_mutex);
}
bool msm_edp_ctrl_panel_connected(struct edp_ctrl *ctrl)
{
mutex_lock(&ctrl->dev_mutex);
DBG("connect status = %d", ctrl->edp_connected);
if (ctrl->edp_connected) {
mutex_unlock(&ctrl->dev_mutex);
return true;
}
if (!ctrl->power_on) {
edp_ctrl_phy_aux_enable(ctrl, 1);
edp_ctrl_irq_enable(ctrl, 1);
}
if (drm_dp_dpcd_read(ctrl->drm_aux, DP_DPCD_REV, ctrl->dpcd,
DP_RECEIVER_CAP_SIZE) < DP_RECEIVER_CAP_SIZE) {
pr_err("%s: AUX channel is NOT ready\n", __func__);
memset(ctrl->dpcd, 0, DP_RECEIVER_CAP_SIZE);
} else {
ctrl->edp_connected = true;
}
if (!ctrl->power_on) {
edp_ctrl_irq_enable(ctrl, 0);
edp_ctrl_phy_aux_enable(ctrl, 0);
}
DBG("exit: connect status=%d", ctrl->edp_connected);
mutex_unlock(&ctrl->dev_mutex);
return ctrl->edp_connected;
}
int msm_edp_ctrl_get_panel_info(struct edp_ctrl *ctrl,
struct drm_connector *connector, struct edid **edid)
{
int ret = 0;
mutex_lock(&ctrl->dev_mutex);
if (ctrl->edid) {
if (edid) {
DBG("Just return edid buffer");
*edid = ctrl->edid;
}
goto unlock_ret;
}
if (!ctrl->power_on) {
edp_ctrl_phy_aux_enable(ctrl, 1);
edp_ctrl_irq_enable(ctrl, 1);
}
ret = drm_dp_link_probe(ctrl->drm_aux, &ctrl->dp_link);
if (ret) {
pr_err("%s: read dpcd cap failed, %d\n", __func__, ret);
goto disable_ret;
}
ctrl->link_rate = drm_dp_link_rate_to_bw_code(ctrl->dp_link.rate);
ctrl->edid = drm_get_edid(connector, &ctrl->drm_aux->ddc);
if (!ctrl->edid) {
pr_err("%s: edid read fail\n", __func__);
goto disable_ret;
}
if (edid)
*edid = ctrl->edid;
disable_ret:
if (!ctrl->power_on) {
edp_ctrl_irq_enable(ctrl, 0);
edp_ctrl_phy_aux_enable(ctrl, 0);
}
unlock_ret:
mutex_unlock(&ctrl->dev_mutex);
return ret;
}
int msm_edp_ctrl_timing_cfg(struct edp_ctrl *ctrl,
const struct drm_display_mode *mode,
const struct drm_display_info *info)
{
u32 hstart_from_sync, vstart_from_sync;
u32 data;
int ret = 0;
mutex_lock(&ctrl->dev_mutex);
ctrl->color_depth = info->bpc;
ctrl->pixel_rate = mode->clock;
ctrl->interlaced = !!(mode->flags & DRM_MODE_FLAG_INTERLACE);
edp_fill_link_cfg(ctrl);
if (edp_clk_enable(ctrl, EDP_CLK_MASK_AHB)) {
pr_err("%s, fail to prepare enable ahb clk\n", __func__);
ret = -EINVAL;
goto unlock_ret;
}
edp_clock_synchrous(ctrl, 1);
edp_write(ctrl->base + REG_EDP_TOTAL_HOR_VER,
EDP_TOTAL_HOR_VER_HORIZ(mode->htotal) |
EDP_TOTAL_HOR_VER_VERT(mode->vtotal));
vstart_from_sync = mode->vtotal - mode->vsync_start;
hstart_from_sync = mode->htotal - mode->hsync_start;
edp_write(ctrl->base + REG_EDP_START_HOR_VER_FROM_SYNC,
EDP_START_HOR_VER_FROM_SYNC_HORIZ(hstart_from_sync) |
EDP_START_HOR_VER_FROM_SYNC_VERT(vstart_from_sync));
data = EDP_HSYNC_VSYNC_WIDTH_POLARITY_VERT(
mode->vsync_end - mode->vsync_start);
data |= EDP_HSYNC_VSYNC_WIDTH_POLARITY_HORIZ(
mode->hsync_end - mode->hsync_start);
if (mode->flags & DRM_MODE_FLAG_NVSYNC)
data |= EDP_HSYNC_VSYNC_WIDTH_POLARITY_NVSYNC;
if (mode->flags & DRM_MODE_FLAG_NHSYNC)
data |= EDP_HSYNC_VSYNC_WIDTH_POLARITY_NHSYNC;
edp_write(ctrl->base + REG_EDP_HSYNC_VSYNC_WIDTH_POLARITY, data);
edp_write(ctrl->base + REG_EDP_ACTIVE_HOR_VER,
EDP_ACTIVE_HOR_VER_HORIZ(mode->hdisplay) |
EDP_ACTIVE_HOR_VER_VERT(mode->vdisplay));
edp_clk_disable(ctrl, EDP_CLK_MASK_AHB);
unlock_ret:
mutex_unlock(&ctrl->dev_mutex);
return ret;
}
bool msm_edp_ctrl_pixel_clock_valid(struct edp_ctrl *ctrl,
u32 pixel_rate, u32 *pm, u32 *pn)
{
const struct edp_pixel_clk_div *divs;
u32 err = 1;
u32 clk_err;
int i;
if (ctrl->link_rate == DP_LINK_BW_1_62) {
divs = clk_divs[0];
} else if (ctrl->link_rate == DP_LINK_BW_2_7) {
divs = clk_divs[1];
} else {
pr_err("%s: Invalid link rate,%d\n", __func__, ctrl->link_rate);
return false;
}
for (i = 0; i < EDP_PIXEL_CLK_NUM; i++) {
clk_err = abs(divs[i].rate - pixel_rate);
if ((divs[i].rate * err / 100) >= clk_err) {
if (pm)
*pm = divs[i].m;
if (pn)
*pn = divs[i].n;
return true;
}
}
DBG("pixel clock %d(kHz) not supported", pixel_rate);
return false;
}
