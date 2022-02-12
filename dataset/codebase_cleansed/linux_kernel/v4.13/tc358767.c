static inline struct tc_data *aux_to_tc(struct drm_dp_aux *a)
{
return container_of(a, struct tc_data, aux);
}
static inline struct tc_data *bridge_to_tc(struct drm_bridge *b)
{
return container_of(b, struct tc_data, bridge);
}
static inline struct tc_data *connector_to_tc(struct drm_connector *c)
{
return container_of(c, struct tc_data, connector);
}
static inline int tc_poll_timeout(struct regmap *map, unsigned int addr,
unsigned int cond_mask,
unsigned int cond_value,
unsigned long sleep_us, u64 timeout_us)
{
ktime_t timeout = ktime_add_us(ktime_get(), timeout_us);
unsigned int val;
int ret;
for (;;) {
ret = regmap_read(map, addr, &val);
if (ret)
break;
if ((val & cond_mask) == cond_value)
break;
if (timeout_us && ktime_compare(ktime_get(), timeout) > 0) {
ret = regmap_read(map, addr, &val);
break;
}
if (sleep_us)
usleep_range((sleep_us >> 2) + 1, sleep_us);
}
return ret ?: (((val & cond_mask) == cond_value) ? 0 : -ETIMEDOUT);
}
static int tc_aux_wait_busy(struct tc_data *tc, unsigned int timeout_ms)
{
return tc_poll_timeout(tc->regmap, DP0_AUXSTATUS, AUX_BUSY, 0,
1000, 1000 * timeout_ms);
}
static int tc_aux_get_status(struct tc_data *tc, u8 *reply)
{
int ret;
u32 value;
ret = regmap_read(tc->regmap, DP0_AUXSTATUS, &value);
if (ret < 0)
return ret;
if (value & AUX_BUSY) {
if (value & AUX_TIMEOUT) {
dev_err(tc->dev, "i2c access timeout!\n");
return -ETIMEDOUT;
}
return -EBUSY;
}
*reply = (value & AUX_STATUS_MASK) >> AUX_STATUS_SHIFT;
return 0;
}
static ssize_t tc_aux_transfer(struct drm_dp_aux *aux,
struct drm_dp_aux_msg *msg)
{
struct tc_data *tc = aux_to_tc(aux);
size_t size = min_t(size_t, 8, msg->size);
u8 request = msg->request & ~DP_AUX_I2C_MOT;
u8 *buf = msg->buffer;
u32 tmp = 0;
int i = 0;
int ret;
if (size == 0)
return 0;
ret = tc_aux_wait_busy(tc, 100);
if (ret)
goto err;
if (request == DP_AUX_I2C_WRITE || request == DP_AUX_NATIVE_WRITE) {
while (i < size) {
if (request == DP_AUX_NATIVE_WRITE)
tmp = tmp | (buf[i] << (8 * (i & 0x3)));
else
tmp = (tmp << 8) | buf[i];
i++;
if (((i % 4) == 0) || (i == size)) {
tc_write(DP0_AUXWDATA(i >> 2), tmp);
tmp = 0;
}
}
} else if (request != DP_AUX_I2C_READ &&
request != DP_AUX_NATIVE_READ) {
return -EINVAL;
}
tc_write(DP0_AUXADDR, msg->address);
tc_write(DP0_AUXCFG0, ((size - 1) << 8) | request);
ret = tc_aux_wait_busy(tc, 100);
if (ret)
goto err;
ret = tc_aux_get_status(tc, &msg->reply);
if (ret)
goto err;
if (request == DP_AUX_I2C_READ || request == DP_AUX_NATIVE_READ) {
while (i < size) {
if ((i % 4) == 0)
tc_read(DP0_AUXRDATA(i >> 2), &tmp);
buf[i] = tmp & 0xff;
tmp = tmp >> 8;
i++;
}
}
return size;
err:
return ret;
}
static u32 tc_srcctrl(struct tc_data *tc)
{
u32 reg = DP0_SRCCTRL_NOTP | DP0_SRCCTRL_LANESKEW;
if (tc->link.scrambler_dis)
reg |= DP0_SRCCTRL_SCRMBLDIS;
if (tc->link.coding8b10b)
reg |= DP0_SRCCTRL_EN810B;
if (tc->link.spread)
reg |= DP0_SRCCTRL_SSCG;
if (tc->link.base.num_lanes == 2)
reg |= DP0_SRCCTRL_LANES_2;
if (tc->link.base.rate != 162000)
reg |= DP0_SRCCTRL_BW27;
return reg;
}
static void tc_wait_pll_lock(struct tc_data *tc)
{
usleep_range(3000, 6000);
}
static int tc_pxl_pll_en(struct tc_data *tc, u32 refclk, u32 pixelclock)
{
int ret;
int i_pre, best_pre = 1;
int i_post, best_post = 1;
int div, best_div = 1;
int mul, best_mul = 1;
int delta, best_delta;
int ext_div[] = {1, 2, 3, 5, 7};
int best_pixelclock = 0;
int vco_hi = 0;
dev_dbg(tc->dev, "PLL: requested %d pixelclock, ref %d\n", pixelclock,
refclk);
best_delta = pixelclock;
for (i_pre = 0; i_pre < ARRAY_SIZE(ext_div); i_pre++) {
if (refclk / ext_div[i_pre] < 1000000)
continue;
for (i_post = 0; i_post < ARRAY_SIZE(ext_div); i_post++) {
for (div = 1; div <= 16; div++) {
u32 clk;
u64 tmp;
tmp = pixelclock * ext_div[i_pre] *
ext_div[i_post] * div;
do_div(tmp, refclk);
mul = tmp;
if ((mul < 1) || (mul > 128))
continue;
clk = (refclk / ext_div[i_pre] / div) * mul;
if ((clk > 650000000) || (clk < 150000000))
continue;
clk = clk / ext_div[i_post];
delta = clk - pixelclock;
if (abs(delta) < abs(best_delta)) {
best_pre = i_pre;
best_post = i_post;
best_div = div;
best_mul = mul;
best_delta = delta;
best_pixelclock = clk;
}
}
}
}
if (best_pixelclock == 0) {
dev_err(tc->dev, "Failed to calc clock for %d pixelclock\n",
pixelclock);
return -EINVAL;
}
dev_dbg(tc->dev, "PLL: got %d, delta %d\n", best_pixelclock,
best_delta);
dev_dbg(tc->dev, "PLL: %d / %d / %d * %d / %d\n", refclk,
ext_div[best_pre], best_div, best_mul, ext_div[best_post]);
if (refclk / ext_div[best_pre] / best_div * best_mul >= 300000000)
vco_hi = 1;
if (best_div == 16)
best_div = 0;
if (best_mul == 128)
best_mul = 0;
tc_write(PXL_PLLCTRL, PLLBYP | PLLEN);
tc_write(PXL_PLLPARAM,
(vco_hi << 24) |
(ext_div[best_pre] << 20) |
(ext_div[best_post] << 16) |
IN_SEL_REFCLK |
(best_div << 8) |
(best_mul << 0));
tc_write(PXL_PLLCTRL, PLLUPDATE | PLLEN);
tc_wait_pll_lock(tc);
return 0;
err:
return ret;
}
static int tc_pxl_pll_dis(struct tc_data *tc)
{
return regmap_write(tc->regmap, PXL_PLLCTRL, PLLBYP);
}
static int tc_stream_clock_calc(struct tc_data *tc)
{
int ret;
tc_write(DP0_VIDMNGEN1, 32768);
return 0;
err:
return ret;
}
static int tc_aux_link_setup(struct tc_data *tc)
{
unsigned long rate;
u32 value;
int ret;
rate = clk_get_rate(tc->refclk);
switch (rate) {
case 38400000:
value = REF_FREQ_38M4;
break;
case 26000000:
value = REF_FREQ_26M;
break;
case 19200000:
value = REF_FREQ_19M2;
break;
case 13000000:
value = REF_FREQ_13M;
break;
default:
dev_err(tc->dev, "Invalid refclk rate: %lu Hz\n", rate);
return -EINVAL;
}
value |= SYSCLK_SEL_LSCLK | LSCLK_DIV_2;
tc_write(SYS_PLLPARAM, value);
tc_write(DP_PHY_CTRL, BGREN | PWR_SW_EN | BIT(2) | PHY_A0_EN);
tc_write(DP0_PLLCTRL, PLLUPDATE | PLLEN);
tc_wait_pll_lock(tc);
tc_write(DP1_PLLCTRL, PLLUPDATE | PLLEN);
tc_wait_pll_lock(tc);
ret = tc_poll_timeout(tc->regmap, DP_PHY_CTRL, PHY_RDY, PHY_RDY, 1,
1000);
if (ret == -ETIMEDOUT) {
dev_err(tc->dev, "Timeout waiting for PHY to become ready");
return ret;
} else if (ret)
goto err;
tc_write(DP0_AUXCFG1, AUX_RX_FILTER_EN |
(0x06 << 8) |
(0x3f << 0));
return 0;
err:
dev_err(tc->dev, "tc_aux_link_setup failed: %d\n", ret);
return ret;
}
static int tc_get_display_props(struct tc_data *tc)
{
int ret;
u8 tmp[8];
ret = drm_dp_link_probe(&tc->aux, &tc->link.base);
if (ret < 0)
goto err_dpcd_read;
if ((tc->link.base.rate != 162000) && (tc->link.base.rate != 270000))
goto err_dpcd_inval;
ret = drm_dp_dpcd_readb(&tc->aux, DP_MAX_DOWNSPREAD, tmp);
if (ret < 0)
goto err_dpcd_read;
tc->link.spread = tmp[0] & BIT(0);
ret = drm_dp_dpcd_readb(&tc->aux, DP_MAIN_LINK_CHANNEL_CODING, tmp);
if (ret < 0)
goto err_dpcd_read;
tc->link.coding8b10b = tmp[0] & BIT(0);
tc->link.scrambler_dis = 0;
ret = drm_dp_dpcd_readb(&tc->aux, DP_EDP_CONFIGURATION_SET, tmp);
if (ret < 0)
goto err_dpcd_read;
tc->link.assr = tmp[0] & DP_ALTERNATE_SCRAMBLER_RESET_ENABLE;
dev_dbg(tc->dev, "DPCD rev: %d.%d, rate: %s, lanes: %d, framing: %s\n",
tc->link.base.revision >> 4, tc->link.base.revision & 0x0f,
(tc->link.base.rate == 162000) ? "1.62Gbps" : "2.7Gbps",
tc->link.base.num_lanes,
(tc->link.base.capabilities & DP_LINK_CAP_ENHANCED_FRAMING) ?
"enhanced" : "non-enhanced");
dev_dbg(tc->dev, "ANSI 8B/10B: %d\n", tc->link.coding8b10b);
dev_dbg(tc->dev, "Display ASSR: %d, TC358767 ASSR: %d\n",
tc->link.assr, tc->assr);
return 0;
err_dpcd_read:
dev_err(tc->dev, "failed to read DPCD: %d\n", ret);
return ret;
err_dpcd_inval:
dev_err(tc->dev, "invalid DPCD\n");
return -EINVAL;
}
static int tc_set_video_mode(struct tc_data *tc, struct drm_display_mode *mode)
{
int ret;
int vid_sync_dly;
int max_tu_symbol;
int left_margin = mode->htotal - mode->hsync_end;
int right_margin = mode->hsync_start - mode->hdisplay;
int hsync_len = mode->hsync_end - mode->hsync_start;
int upper_margin = mode->vtotal - mode->vsync_end;
int lower_margin = mode->vsync_start - mode->vdisplay;
int vsync_len = mode->vsync_end - mode->vsync_start;
dev_dbg(tc->dev, "set mode %dx%d\n",
mode->hdisplay, mode->vdisplay);
dev_dbg(tc->dev, "H margin %d,%d sync %d\n",
left_margin, right_margin, hsync_len);
dev_dbg(tc->dev, "V margin %d,%d sync %d\n",
upper_margin, lower_margin, vsync_len);
dev_dbg(tc->dev, "total: %dx%d\n", mode->htotal, mode->vtotal);
tc_write(VPCTRL0, (0x40 << 20) |
OPXLFMT_RGB888 | FRMSYNC_DISABLED | MSF_DISABLED);
tc_write(HTIM01, (left_margin << 16) |
(hsync_len << 0));
tc_write(HTIM02, (right_margin << 16) |
(mode->hdisplay << 0));
tc_write(VTIM01, (upper_margin << 16) |
(vsync_len << 0));
tc_write(VTIM02, (lower_margin << 16) |
(mode->vdisplay << 0));
tc_write(VFUEN0, VFUEN);
tc_write(TSTCTL,
(120 << 24) |
(20 << 16) |
(99 << 8) |
(1 << 4) |
(2 << 0) |
0);
vid_sync_dly = hsync_len + left_margin + mode->hdisplay;
tc_write(DP0_VIDSYNCDELAY,
(0x003e << 16) |
(vid_sync_dly << 0));
tc_write(DP0_TOTALVAL, (mode->vtotal << 16) | (mode->htotal));
tc_write(DP0_STARTVAL,
((upper_margin + vsync_len) << 16) |
((left_margin + hsync_len) << 0));
tc_write(DP0_ACTIVEVAL, (mode->vdisplay << 16) | (mode->hdisplay));
tc_write(DP0_SYNCVAL, (vsync_len << 16) | (hsync_len << 0));
tc_write(DPIPXLFMT, VS_POL_ACTIVE_LOW | HS_POL_ACTIVE_LOW |
DE_POL_ACTIVE_HIGH | SUB_CFG_TYPE_CONFIG1 | DPI_BPP_RGB888);
max_tu_symbol = TU_SIZE_RECOMMENDED - 1;
tc_write(DP0_MISC, (max_tu_symbol << 23) | TU_SIZE_RECOMMENDED | BPC_8);
return 0;
err:
return ret;
}
static int tc_link_training(struct tc_data *tc, int pattern)
{
const char * const *errors;
u32 srcctrl = tc_srcctrl(tc) | DP0_SRCCTRL_SCRMBLDIS |
DP0_SRCCTRL_AUTOCORRECT;
int timeout;
int retry;
u32 value;
int ret;
if (pattern == DP_TRAINING_PATTERN_1) {
srcctrl |= DP0_SRCCTRL_TP1;
errors = training_pattern1_errors;
} else {
srcctrl |= DP0_SRCCTRL_TP2;
errors = training_pattern2_errors;
}
tc_write(DP0_SNKLTCTRL, DP_LINK_SCRAMBLING_DISABLE | pattern);
tc_write(DP0_LTLOOPCTRL,
(0x0f << 28) |
(0x0f << 24) |
(0x0d << 0));
retry = 5;
do {
tc_write(DP0_SRCCTRL, srcctrl);
tc_write(DP0CTL, DP_EN);
timeout = 1000;
do {
tc_read(DP0_LTSTAT, &value);
udelay(1);
} while ((!(value & LT_LOOPDONE)) && (--timeout));
if (timeout == 0) {
dev_err(tc->dev, "Link training timeout!\n");
} else {
int pattern = (value >> 11) & 0x3;
int error = (value >> 8) & 0x7;
dev_dbg(tc->dev,
"Link training phase %d done after %d uS: %s\n",
pattern, 1000 - timeout, errors[error]);
if (pattern == DP_TRAINING_PATTERN_1 && error == 0)
break;
if (pattern == DP_TRAINING_PATTERN_2) {
value &= LT_CHANNEL1_EQ_BITS |
LT_INTERLANE_ALIGN_DONE |
LT_CHANNEL0_EQ_BITS;
if ((tc->link.base.num_lanes == 2) &&
(value == (LT_CHANNEL1_EQ_BITS |
LT_INTERLANE_ALIGN_DONE |
LT_CHANNEL0_EQ_BITS)))
break;
if ((tc->link.base.num_lanes == 1) &&
(value == (LT_INTERLANE_ALIGN_DONE |
LT_CHANNEL0_EQ_BITS)))
break;
}
}
tc_write(DP0CTL, 0);
usleep_range(10, 20);
} while (--retry);
if (retry == 0) {
dev_err(tc->dev, "Failed to finish training phase %d\n",
pattern);
}
return 0;
err:
return ret;
}
static int tc_main_link_setup(struct tc_data *tc)
{
struct drm_dp_aux *aux = &tc->aux;
struct device *dev = tc->dev;
unsigned int rate;
u32 dp_phy_ctrl;
int timeout;
bool aligned;
bool ready;
u32 value;
int ret;
u8 tmp[8];
if (!tc->mode)
return -EINVAL;
tc_write(DP0_SRCCTRL, DP0_SRCCTRL_SCRMBLDIS | DP0_SRCCTRL_EN810B |
DP0_SRCCTRL_LANESKEW | DP0_SRCCTRL_LANES_2 |
DP0_SRCCTRL_BW27 | DP0_SRCCTRL_AUTOCORRECT);
tc_write(0x07a0, 0x00003083);
rate = clk_get_rate(tc->refclk);
switch (rate) {
case 38400000:
value = REF_FREQ_38M4;
break;
case 26000000:
value = REF_FREQ_26M;
break;
case 19200000:
value = REF_FREQ_19M2;
break;
case 13000000:
value = REF_FREQ_13M;
break;
default:
return -EINVAL;
}
value |= SYSCLK_SEL_LSCLK | LSCLK_DIV_2;
tc_write(SYS_PLLPARAM, value);
dp_phy_ctrl = BGREN | PWR_SW_EN | BIT(2) | PHY_A0_EN | PHY_M0_EN;
tc_write(DP_PHY_CTRL, dp_phy_ctrl);
msleep(100);
tc_write(DP0_PLLCTRL, PLLUPDATE | PLLEN);
tc_wait_pll_lock(tc);
tc_write(DP1_PLLCTRL, PLLUPDATE | PLLEN);
tc_wait_pll_lock(tc);
if (tc_test_pattern) {
ret = tc_pxl_pll_en(tc, clk_get_rate(tc->refclk),
1000 * tc->mode->clock);
if (ret)
goto err;
}
dp_phy_ctrl |= DP_PHY_RST | PHY_M1_RST | PHY_M0_RST;
tc_write(DP_PHY_CTRL, dp_phy_ctrl);
usleep_range(100, 200);
dp_phy_ctrl &= ~(DP_PHY_RST | PHY_M1_RST | PHY_M0_RST);
tc_write(DP_PHY_CTRL, dp_phy_ctrl);
timeout = 1000;
do {
tc_read(DP_PHY_CTRL, &value);
udelay(1);
} while ((!(value & PHY_RDY)) && (--timeout));
if (timeout == 0) {
dev_err(dev, "timeout waiting for phy become ready");
return -ETIMEDOUT;
}
ret = regmap_update_bits(tc->regmap, DP0_MISC, BPC_8, BPC_8);
if (ret)
goto err;
if (tc->assr != tc->link.assr) {
dev_dbg(dev, "Trying to set display to ASSR: %d\n",
tc->assr);
tmp[0] = tc->assr;
ret = drm_dp_dpcd_writeb(aux, DP_EDP_CONFIGURATION_SET, tmp[0]);
if (ret < 0)
goto err_dpcd_read;
ret = drm_dp_dpcd_readb(aux, DP_EDP_CONFIGURATION_SET, tmp);
if (ret < 0)
goto err_dpcd_read;
if (tmp[0] != tc->assr) {
dev_dbg(dev, "Failed to switch display ASSR to %d, falling back to unscrambled mode\n",
tc->assr);
tc->link.scrambler_dis = 1;
}
}
ret = drm_dp_link_configure(aux, &tc->link.base);
if (ret < 0)
goto err_dpcd_write;
tmp[0] = tc->link.spread ? DP_SPREAD_AMP_0_5 : 0x00;
tmp[1] = tc->link.coding8b10b ? DP_SET_ANSI_8B10B : 0x00;
ret = drm_dp_dpcd_write(aux, DP_DOWNSPREAD_CTRL, tmp, 2);
if (ret < 0)
goto err_dpcd_write;
ret = tc_link_training(tc, DP_TRAINING_PATTERN_1);
if (ret)
goto err;
ret = tc_link_training(tc, DP_TRAINING_PATTERN_2);
if (ret)
goto err;
tmp[0] = tc->link.scrambler_dis ? DP_LINK_SCRAMBLING_DISABLE : 0x00;
ret = drm_dp_dpcd_writeb(aux, DP_TRAINING_PATTERN_SET, tmp[0]);
if (ret < 0)
goto err_dpcd_write;
tc_write(DP0_SRCCTRL, tc_srcctrl(tc) | DP0_SRCCTRL_AUTOCORRECT);
timeout = 100;
do {
udelay(1);
ret = drm_dp_dpcd_read_link_status(aux, tmp + 2);
if (ret < 0)
goto err_dpcd_read;
ready = (tmp[2] == ((DP_CHANNEL_EQ_BITS << 4) |
DP_CHANNEL_EQ_BITS));
aligned = tmp[4] & DP_INTERLANE_ALIGN_DONE;
} while ((--timeout) && !(ready && aligned));
if (timeout == 0) {
ret = drm_dp_dpcd_read(aux, DP_SINK_COUNT, tmp, 2);
if (ret < 0)
goto err_dpcd_read;
dev_info(dev, "0x0200 SINK_COUNT: 0x%02x\n", tmp[0]);
dev_info(dev, "0x0201 DEVICE_SERVICE_IRQ_VECTOR: 0x%02x\n",
tmp[1]);
dev_info(dev, "0x0202 LANE0_1_STATUS: 0x%02x\n", tmp[2]);
dev_info(dev, "0x0204 LANE_ALIGN_STATUS_UPDATED: 0x%02x\n",
tmp[4]);
dev_info(dev, "0x0205 SINK_STATUS: 0x%02x\n", tmp[5]);
dev_info(dev, "0x0206 ADJUST_REQUEST_LANE0_1: 0x%02x\n",
tmp[6]);
if (!ready)
dev_err(dev, "Lane0/1 not ready\n");
if (!aligned)
dev_err(dev, "Lane0/1 not aligned\n");
return -EAGAIN;
}
ret = tc_set_video_mode(tc, tc->mode);
if (ret)
goto err;
ret = tc_stream_clock_calc(tc);
if (ret)
goto err;
return 0;
err_dpcd_read:
dev_err(tc->dev, "Failed to read DPCD: %d\n", ret);
return ret;
err_dpcd_write:
dev_err(tc->dev, "Failed to write DPCD: %d\n", ret);
err:
return ret;
}
static int tc_main_link_stream(struct tc_data *tc, int state)
{
int ret;
u32 value;
dev_dbg(tc->dev, "stream: %d\n", state);
if (state) {
value = VID_MN_GEN | DP_EN;
if (tc->link.base.capabilities & DP_LINK_CAP_ENHANCED_FRAMING)
value |= EF_EN;
tc_write(DP0CTL, value);
usleep_range(500, 1000);
value |= VID_EN;
tc_write(DP0CTL, value);
value = DP0_AUDSRC_NO_INPUT;
if (tc_test_pattern)
value |= DP0_VIDSRC_COLOR_BAR;
else
value |= DP0_VIDSRC_DPI_RX;
tc_write(SYSCTRL, value);
} else {
tc_write(DP0CTL, 0);
}
return 0;
err:
return ret;
}
static void tc_bridge_pre_enable(struct drm_bridge *bridge)
{
struct tc_data *tc = bridge_to_tc(bridge);
drm_panel_prepare(tc->panel);
}
static void tc_bridge_enable(struct drm_bridge *bridge)
{
struct tc_data *tc = bridge_to_tc(bridge);
int ret;
ret = tc_main_link_setup(tc);
if (ret < 0) {
dev_err(tc->dev, "main link setup error: %d\n", ret);
return;
}
ret = tc_main_link_stream(tc, 1);
if (ret < 0) {
dev_err(tc->dev, "main link stream start error: %d\n", ret);
return;
}
drm_panel_enable(tc->panel);
}
static void tc_bridge_disable(struct drm_bridge *bridge)
{
struct tc_data *tc = bridge_to_tc(bridge);
int ret;
drm_panel_disable(tc->panel);
ret = tc_main_link_stream(tc, 0);
if (ret < 0)
dev_err(tc->dev, "main link stream stop error: %d\n", ret);
}
static void tc_bridge_post_disable(struct drm_bridge *bridge)
{
struct tc_data *tc = bridge_to_tc(bridge);
drm_panel_unprepare(tc->panel);
}
static bool tc_bridge_mode_fixup(struct drm_bridge *bridge,
const struct drm_display_mode *mode,
struct drm_display_mode *adj)
{
adj->flags = mode->flags;
adj->flags |= (DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_NVSYNC);
adj->flags &= ~(DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC);
return true;
}
static int tc_connector_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
return MODE_OK;
}
static void tc_bridge_mode_set(struct drm_bridge *bridge,
struct drm_display_mode *mode,
struct drm_display_mode *adj)
{
struct tc_data *tc = bridge_to_tc(bridge);
tc->mode = mode;
}
static int tc_connector_get_modes(struct drm_connector *connector)
{
struct tc_data *tc = connector_to_tc(connector);
struct edid *edid;
unsigned int count;
if (tc->panel && tc->panel->funcs && tc->panel->funcs->get_modes) {
count = tc->panel->funcs->get_modes(tc->panel);
if (count > 0)
return count;
}
edid = drm_get_edid(connector, &tc->aux.ddc);
kfree(tc->edid);
tc->edid = edid;
if (!edid)
return 0;
drm_mode_connector_update_edid_property(connector, edid);
count = drm_add_edid_modes(connector, edid);
return count;
}
static void tc_connector_set_polling(struct tc_data *tc,
struct drm_connector *connector)
{
connector->polled = DRM_CONNECTOR_POLL_CONNECT |
DRM_CONNECTOR_POLL_DISCONNECT;
}
static struct drm_encoder *
tc_connector_best_encoder(struct drm_connector *connector)
{
struct tc_data *tc = connector_to_tc(connector);
return tc->bridge.encoder;
}
static int tc_bridge_attach(struct drm_bridge *bridge)
{
u32 bus_format = MEDIA_BUS_FMT_RGB888_1X24;
struct tc_data *tc = bridge_to_tc(bridge);
struct drm_device *drm = bridge->dev;
int ret;
drm_connector_helper_add(&tc->connector, &tc_connector_helper_funcs);
ret = drm_connector_init(drm, &tc->connector, &tc_connector_funcs,
DRM_MODE_CONNECTOR_eDP);
if (ret)
return ret;
if (tc->panel)
drm_panel_attach(tc->panel, &tc->connector);
drm_display_info_set_bus_formats(&tc->connector.display_info,
&bus_format, 1);
drm_mode_connector_attach_encoder(&tc->connector, tc->bridge.encoder);
return 0;
}
static bool tc_readable_reg(struct device *dev, unsigned int reg)
{
return reg != SYSCTRL;
}
static bool tc_writeable_reg(struct device *dev, unsigned int reg)
{
return (reg != TC_IDREG) &&
(reg != DP0_LTSTAT) &&
(reg != DP0_SNKLTCHGREQ);
}
static int tc_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct tc_data *tc;
int ret;
tc = devm_kzalloc(dev, sizeof(*tc), GFP_KERNEL);
if (!tc)
return -ENOMEM;
tc->dev = dev;
ret = drm_of_find_panel_or_bridge(dev->of_node, 2, 0, &tc->panel, NULL);
if (ret && ret != -ENODEV)
return ret;
tc->sd_gpio = devm_gpiod_get_optional(dev, "shutdown", GPIOD_OUT_HIGH);
if (IS_ERR(tc->sd_gpio))
return PTR_ERR(tc->sd_gpio);
if (tc->sd_gpio) {
gpiod_set_value_cansleep(tc->sd_gpio, 0);
usleep_range(5000, 10000);
}
tc->reset_gpio = devm_gpiod_get_optional(dev, "reset", GPIOD_OUT_LOW);
if (IS_ERR(tc->reset_gpio))
return PTR_ERR(tc->reset_gpio);
if (tc->reset_gpio) {
gpiod_set_value_cansleep(tc->reset_gpio, 1);
usleep_range(5000, 10000);
}
tc->refclk = devm_clk_get(dev, "ref");
if (IS_ERR(tc->refclk)) {
ret = PTR_ERR(tc->refclk);
dev_err(dev, "Failed to get refclk: %d\n", ret);
return ret;
}
tc->regmap = devm_regmap_init_i2c(client, &tc_regmap_config);
if (IS_ERR(tc->regmap)) {
ret = PTR_ERR(tc->regmap);
dev_err(dev, "Failed to initialize regmap: %d\n", ret);
return ret;
}
ret = regmap_read(tc->regmap, TC_IDREG, &tc->rev);
if (ret) {
dev_err(tc->dev, "can not read device ID: %d\n", ret);
return ret;
}
if ((tc->rev != 0x6601) && (tc->rev != 0x6603)) {
dev_err(tc->dev, "invalid device ID: 0x%08x\n", tc->rev);
return -EINVAL;
}
tc->assr = (tc->rev == 0x6601);
ret = tc_aux_link_setup(tc);
if (ret)
return ret;
tc->aux.name = "TC358767 AUX i2c adapter";
tc->aux.dev = tc->dev;
tc->aux.transfer = tc_aux_transfer;
ret = drm_dp_aux_register(&tc->aux);
if (ret)
return ret;
ret = tc_get_display_props(tc);
if (ret)
goto err_unregister_aux;
tc_connector_set_polling(tc, &tc->connector);
tc->bridge.funcs = &tc_bridge_funcs;
tc->bridge.of_node = dev->of_node;
ret = drm_bridge_add(&tc->bridge);
if (ret) {
dev_err(dev, "Failed to add drm_bridge: %d\n", ret);
goto err_unregister_aux;
}
i2c_set_clientdata(client, tc);
return 0;
err_unregister_aux:
drm_dp_aux_unregister(&tc->aux);
return ret;
}
static int tc_remove(struct i2c_client *client)
{
struct tc_data *tc = i2c_get_clientdata(client);
drm_bridge_remove(&tc->bridge);
drm_dp_aux_unregister(&tc->aux);
tc_pxl_pll_dis(tc);
return 0;
}
