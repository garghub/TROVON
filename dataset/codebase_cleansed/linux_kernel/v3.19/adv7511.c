static struct adv7511 *encoder_to_adv7511(struct drm_encoder *encoder)
{
return to_encoder_slave(encoder)->slave_priv;
}
static bool adv7511_register_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case ADV7511_REG_CHIP_REVISION:
case ADV7511_REG_SPDIF_FREQ:
case ADV7511_REG_CTS_AUTOMATIC1:
case ADV7511_REG_CTS_AUTOMATIC2:
case ADV7511_REG_VIC_DETECTED:
case ADV7511_REG_VIC_SEND:
case ADV7511_REG_AUX_VIC_DETECTED:
case ADV7511_REG_STATUS:
case ADV7511_REG_GC(1):
case ADV7511_REG_INT(0):
case ADV7511_REG_INT(1):
case ADV7511_REG_PLL_STATUS:
case ADV7511_REG_AN(0):
case ADV7511_REG_AN(1):
case ADV7511_REG_AN(2):
case ADV7511_REG_AN(3):
case ADV7511_REG_AN(4):
case ADV7511_REG_AN(5):
case ADV7511_REG_AN(6):
case ADV7511_REG_AN(7):
case ADV7511_REG_HDCP_STATUS:
case ADV7511_REG_BCAPS:
case ADV7511_REG_BKSV(0):
case ADV7511_REG_BKSV(1):
case ADV7511_REG_BKSV(2):
case ADV7511_REG_BKSV(3):
case ADV7511_REG_BKSV(4):
case ADV7511_REG_DDC_STATUS:
case ADV7511_REG_BSTATUS(0):
case ADV7511_REG_BSTATUS(1):
case ADV7511_REG_CHIP_ID_HIGH:
case ADV7511_REG_CHIP_ID_LOW:
return true;
}
return false;
}
static void adv7511_set_colormap(struct adv7511 *adv7511, bool enable,
const uint16_t *coeff,
unsigned int scaling_factor)
{
unsigned int i;
regmap_update_bits(adv7511->regmap, ADV7511_REG_CSC_UPPER(1),
ADV7511_CSC_UPDATE_MODE, ADV7511_CSC_UPDATE_MODE);
if (enable) {
for (i = 0; i < 12; ++i) {
regmap_update_bits(adv7511->regmap,
ADV7511_REG_CSC_UPPER(i),
0x1f, coeff[i] >> 8);
regmap_write(adv7511->regmap,
ADV7511_REG_CSC_LOWER(i),
coeff[i] & 0xff);
}
}
if (enable)
regmap_update_bits(adv7511->regmap, ADV7511_REG_CSC_UPPER(0),
0xe0, 0x80 | (scaling_factor << 5));
else
regmap_update_bits(adv7511->regmap, ADV7511_REG_CSC_UPPER(0),
0x80, 0x00);
regmap_update_bits(adv7511->regmap, ADV7511_REG_CSC_UPPER(1),
ADV7511_CSC_UPDATE_MODE, 0);
}
static int adv7511_packet_enable(struct adv7511 *adv7511, unsigned int packet)
{
if (packet & 0xff)
regmap_update_bits(adv7511->regmap, ADV7511_REG_PACKET_ENABLE0,
packet, 0xff);
if (packet & 0xff00) {
packet >>= 8;
regmap_update_bits(adv7511->regmap, ADV7511_REG_PACKET_ENABLE1,
packet, 0xff);
}
return 0;
}
static int adv7511_packet_disable(struct adv7511 *adv7511, unsigned int packet)
{
if (packet & 0xff)
regmap_update_bits(adv7511->regmap, ADV7511_REG_PACKET_ENABLE0,
packet, 0x00);
if (packet & 0xff00) {
packet >>= 8;
regmap_update_bits(adv7511->regmap, ADV7511_REG_PACKET_ENABLE1,
packet, 0x00);
}
return 0;
}
static void adv7511_set_config_csc(struct adv7511 *adv7511,
struct drm_connector *connector,
bool rgb)
{
struct adv7511_video_config config;
bool output_format_422, output_format_ycbcr;
unsigned int mode;
uint8_t infoframe[17];
if (adv7511->edid)
config.hdmi_mode = drm_detect_hdmi_monitor(adv7511->edid);
else
config.hdmi_mode = false;
hdmi_avi_infoframe_init(&config.avi_infoframe);
config.avi_infoframe.scan_mode = HDMI_SCAN_MODE_UNDERSCAN;
if (rgb) {
config.csc_enable = false;
config.avi_infoframe.colorspace = HDMI_COLORSPACE_RGB;
} else {
config.csc_scaling_factor = ADV7511_CSC_SCALING_4;
config.csc_coefficents = adv7511_csc_ycbcr_to_rgb;
if ((connector->display_info.color_formats &
DRM_COLOR_FORMAT_YCRCB422) &&
config.hdmi_mode) {
config.csc_enable = false;
config.avi_infoframe.colorspace =
HDMI_COLORSPACE_YUV422;
} else {
config.csc_enable = true;
config.avi_infoframe.colorspace = HDMI_COLORSPACE_RGB;
}
}
if (config.hdmi_mode) {
mode = ADV7511_HDMI_CFG_MODE_HDMI;
switch (config.avi_infoframe.colorspace) {
case HDMI_COLORSPACE_YUV444:
output_format_422 = false;
output_format_ycbcr = true;
break;
case HDMI_COLORSPACE_YUV422:
output_format_422 = true;
output_format_ycbcr = true;
break;
default:
output_format_422 = false;
output_format_ycbcr = false;
break;
}
} else {
mode = ADV7511_HDMI_CFG_MODE_DVI;
output_format_422 = false;
output_format_ycbcr = false;
}
adv7511_packet_disable(adv7511, ADV7511_PACKET_ENABLE_AVI_INFOFRAME);
adv7511_set_colormap(adv7511, config.csc_enable,
config.csc_coefficents,
config.csc_scaling_factor);
regmap_update_bits(adv7511->regmap, ADV7511_REG_VIDEO_INPUT_CFG1, 0x81,
(output_format_422 << 7) | output_format_ycbcr);
regmap_update_bits(adv7511->regmap, ADV7511_REG_HDCP_HDMI_CFG,
ADV7511_HDMI_CFG_MODE_MASK, mode);
hdmi_avi_infoframe_pack(&config.avi_infoframe, infoframe,
sizeof(infoframe));
regmap_bulk_write(adv7511->regmap, ADV7511_REG_AVI_INFOFRAME_VERSION,
infoframe + 1, sizeof(infoframe) - 1);
adv7511_packet_enable(adv7511, ADV7511_PACKET_ENABLE_AVI_INFOFRAME);
}
static void adv7511_set_link_config(struct adv7511 *adv7511,
const struct adv7511_link_config *config)
{
static const unsigned int input_styles[4] = { 0, 2, 1, 3 };
unsigned int clock_delay;
unsigned int color_depth;
unsigned int input_id;
clock_delay = (config->clock_delay + 1200) / 400;
color_depth = config->input_color_depth == 8 ? 3
: (config->input_color_depth == 10 ? 1 : 2);
if (config->input_colorspace != HDMI_COLORSPACE_YUV422)
input_id = config->input_clock == ADV7511_INPUT_CLOCK_DDR
? 5 : 0;
else if (config->input_clock == ADV7511_INPUT_CLOCK_DDR)
input_id = config->embedded_sync ? 8 : 7;
else if (config->input_clock == ADV7511_INPUT_CLOCK_2X)
input_id = config->embedded_sync ? 4 : 3;
else
input_id = config->embedded_sync ? 2 : 1;
regmap_update_bits(adv7511->regmap, ADV7511_REG_I2C_FREQ_ID_CFG, 0xf,
input_id);
regmap_update_bits(adv7511->regmap, ADV7511_REG_VIDEO_INPUT_CFG1, 0x7e,
(color_depth << 4) |
(input_styles[config->input_style] << 2));
regmap_write(adv7511->regmap, ADV7511_REG_VIDEO_INPUT_CFG2,
config->input_justification << 3);
regmap_write(adv7511->regmap, ADV7511_REG_TIMING_GEN_SEQ,
config->sync_pulse << 2);
regmap_write(adv7511->regmap, 0xba, clock_delay << 5);
adv7511->embedded_sync = config->embedded_sync;
adv7511->hsync_polarity = config->hsync_polarity;
adv7511->vsync_polarity = config->vsync_polarity;
adv7511->rgb = config->input_colorspace == HDMI_COLORSPACE_RGB;
}
static bool adv7511_hpd(struct adv7511 *adv7511)
{
unsigned int irq0;
int ret;
ret = regmap_read(adv7511->regmap, ADV7511_REG_INT(0), &irq0);
if (ret < 0)
return false;
if (irq0 & ADV7511_INT0_HDP) {
regmap_write(adv7511->regmap, ADV7511_REG_INT(0),
ADV7511_INT0_HDP);
return true;
}
return false;
}
static irqreturn_t adv7511_irq_handler(int irq, void *devid)
{
struct adv7511 *adv7511 = devid;
if (adv7511_hpd(adv7511))
drm_helper_hpd_irq_event(adv7511->encoder->dev);
wake_up_all(&adv7511->wq);
return IRQ_HANDLED;
}
static unsigned int adv7511_is_interrupt_pending(struct adv7511 *adv7511,
unsigned int irq)
{
unsigned int irq0, irq1;
unsigned int pending;
int ret;
ret = regmap_read(adv7511->regmap, ADV7511_REG_INT(0), &irq0);
if (ret < 0)
return 0;
ret = regmap_read(adv7511->regmap, ADV7511_REG_INT(1), &irq1);
if (ret < 0)
return 0;
pending = (irq1 << 8) | irq0;
return pending & irq;
}
static int adv7511_wait_for_interrupt(struct adv7511 *adv7511, int irq,
int timeout)
{
unsigned int pending;
int ret;
if (adv7511->i2c_main->irq) {
ret = wait_event_interruptible_timeout(adv7511->wq,
adv7511_is_interrupt_pending(adv7511, irq),
msecs_to_jiffies(timeout));
if (ret <= 0)
return 0;
pending = adv7511_is_interrupt_pending(adv7511, irq);
} else {
if (timeout < 25)
timeout = 25;
do {
pending = adv7511_is_interrupt_pending(adv7511, irq);
if (pending)
break;
msleep(25);
timeout -= 25;
} while (timeout >= 25);
}
return pending;
}
static int adv7511_get_edid_block(void *data, u8 *buf, unsigned int block,
size_t len)
{
struct adv7511 *adv7511 = data;
struct i2c_msg xfer[2];
uint8_t offset;
unsigned int i;
int ret;
if (len > 128)
return -EINVAL;
if (adv7511->current_edid_segment != block / 2) {
unsigned int status;
ret = regmap_read(adv7511->regmap, ADV7511_REG_DDC_STATUS,
&status);
if (ret < 0)
return ret;
if (status != 2) {
regmap_write(adv7511->regmap, ADV7511_REG_EDID_SEGMENT,
block);
ret = adv7511_wait_for_interrupt(adv7511,
ADV7511_INT0_EDID_READY |
ADV7511_INT1_DDC_ERROR, 200);
if (!(ret & ADV7511_INT0_EDID_READY))
return -EIO;
}
regmap_write(adv7511->regmap, ADV7511_REG_INT(0),
ADV7511_INT0_EDID_READY | ADV7511_INT1_DDC_ERROR);
xfer[0].addr = adv7511->i2c_edid->addr;
xfer[0].flags = 0;
xfer[0].len = 1;
xfer[0].buf = &offset;
xfer[1].addr = adv7511->i2c_edid->addr;
xfer[1].flags = I2C_M_RD;
xfer[1].len = 64;
xfer[1].buf = adv7511->edid_buf;
offset = 0;
for (i = 0; i < 4; ++i) {
ret = i2c_transfer(adv7511->i2c_edid->adapter, xfer,
ARRAY_SIZE(xfer));
if (ret < 0)
return ret;
else if (ret != 2)
return -EIO;
xfer[1].buf += 64;
offset += 64;
}
adv7511->current_edid_segment = block / 2;
}
if (block % 2 == 0)
memcpy(buf, adv7511->edid_buf, len);
else
memcpy(buf, adv7511->edid_buf + 128, len);
return 0;
}
static int adv7511_get_modes(struct drm_encoder *encoder,
struct drm_connector *connector)
{
struct adv7511 *adv7511 = encoder_to_adv7511(encoder);
struct edid *edid;
unsigned int count;
if (adv7511->dpms_mode != DRM_MODE_DPMS_ON) {
regmap_write(adv7511->regmap, ADV7511_REG_INT(0),
ADV7511_INT0_EDID_READY | ADV7511_INT1_DDC_ERROR);
regmap_update_bits(adv7511->regmap, ADV7511_REG_POWER,
ADV7511_POWER_POWER_DOWN, 0);
adv7511->current_edid_segment = -1;
}
edid = drm_do_get_edid(connector, adv7511_get_edid_block, adv7511);
if (adv7511->dpms_mode != DRM_MODE_DPMS_ON)
regmap_update_bits(adv7511->regmap, ADV7511_REG_POWER,
ADV7511_POWER_POWER_DOWN,
ADV7511_POWER_POWER_DOWN);
kfree(adv7511->edid);
adv7511->edid = edid;
if (!edid)
return 0;
drm_mode_connector_update_edid_property(connector, edid);
count = drm_add_edid_modes(connector, edid);
adv7511_set_config_csc(adv7511, connector, adv7511->rgb);
return count;
}
static void adv7511_encoder_dpms(struct drm_encoder *encoder, int mode)
{
struct adv7511 *adv7511 = encoder_to_adv7511(encoder);
switch (mode) {
case DRM_MODE_DPMS_ON:
adv7511->current_edid_segment = -1;
regmap_write(adv7511->regmap, ADV7511_REG_INT(0),
ADV7511_INT0_EDID_READY | ADV7511_INT1_DDC_ERROR);
regmap_update_bits(adv7511->regmap, ADV7511_REG_POWER,
ADV7511_POWER_POWER_DOWN, 0);
regmap_update_bits(adv7511->regmap, ADV7511_REG_POWER2,
ADV7511_REG_POWER2_HDP_SRC_MASK,
ADV7511_REG_POWER2_HDP_SRC_NONE);
regcache_sync(adv7511->regmap);
break;
default:
regmap_update_bits(adv7511->regmap, ADV7511_REG_POWER,
ADV7511_POWER_POWER_DOWN,
ADV7511_POWER_POWER_DOWN);
regcache_mark_dirty(adv7511->regmap);
break;
}
adv7511->dpms_mode = mode;
}
static enum drm_connector_status
adv7511_encoder_detect(struct drm_encoder *encoder,
struct drm_connector *connector)
{
struct adv7511 *adv7511 = encoder_to_adv7511(encoder);
enum drm_connector_status status;
unsigned int val;
bool hpd;
int ret;
ret = regmap_read(adv7511->regmap, ADV7511_REG_STATUS, &val);
if (ret < 0)
return connector_status_disconnected;
if (val & ADV7511_STATUS_HPD)
status = connector_status_connected;
else
status = connector_status_disconnected;
hpd = adv7511_hpd(adv7511);
if (status == connector_status_connected && hpd &&
adv7511->dpms_mode == DRM_MODE_DPMS_ON) {
regcache_mark_dirty(adv7511->regmap);
adv7511_encoder_dpms(encoder, adv7511->dpms_mode);
adv7511_get_modes(encoder, connector);
if (adv7511->status == connector_status_connected)
status = connector_status_disconnected;
} else {
regmap_update_bits(adv7511->regmap, ADV7511_REG_POWER2,
ADV7511_REG_POWER2_HDP_SRC_MASK,
ADV7511_REG_POWER2_HDP_SRC_BOTH);
}
adv7511->status = status;
return status;
}
static int adv7511_encoder_mode_valid(struct drm_encoder *encoder,
struct drm_display_mode *mode)
{
if (mode->clock > 165000)
return MODE_CLOCK_HIGH;
if (mode->flags & DRM_MODE_FLAG_INTERLACE)
return MODE_NO_INTERLACE;
return MODE_OK;
}
static void adv7511_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adj_mode)
{
struct adv7511 *adv7511 = encoder_to_adv7511(encoder);
unsigned int low_refresh_rate;
unsigned int hsync_polarity = 0;
unsigned int vsync_polarity = 0;
if (adv7511->embedded_sync) {
unsigned int hsync_offset, hsync_len;
unsigned int vsync_offset, vsync_len;
hsync_offset = adj_mode->crtc_hsync_start -
adj_mode->crtc_hdisplay;
vsync_offset = adj_mode->crtc_vsync_start -
adj_mode->crtc_vdisplay;
hsync_len = adj_mode->crtc_hsync_end -
adj_mode->crtc_hsync_start;
vsync_len = adj_mode->crtc_vsync_end -
adj_mode->crtc_vsync_start;
vsync_offset += 1;
regmap_write(adv7511->regmap, ADV7511_REG_HSYNC_PLACEMENT_MSB,
((hsync_offset >> 10) & 0x7) << 5);
regmap_write(adv7511->regmap, ADV7511_REG_SYNC_DECODER(0),
(hsync_offset >> 2) & 0xff);
regmap_write(adv7511->regmap, ADV7511_REG_SYNC_DECODER(1),
((hsync_offset & 0x3) << 6) |
((hsync_len >> 4) & 0x3f));
regmap_write(adv7511->regmap, ADV7511_REG_SYNC_DECODER(2),
((hsync_len & 0xf) << 4) |
((vsync_offset >> 6) & 0xf));
regmap_write(adv7511->regmap, ADV7511_REG_SYNC_DECODER(3),
((vsync_offset & 0x3f) << 2) |
((vsync_len >> 8) & 0x3));
regmap_write(adv7511->regmap, ADV7511_REG_SYNC_DECODER(4),
vsync_len & 0xff);
hsync_polarity = !(adj_mode->flags & DRM_MODE_FLAG_PHSYNC);
vsync_polarity = !(adj_mode->flags & DRM_MODE_FLAG_PVSYNC);
} else {
enum adv7511_sync_polarity mode_hsync_polarity;
enum adv7511_sync_polarity mode_vsync_polarity;
if (adj_mode->flags & DRM_MODE_FLAG_NHSYNC)
mode_hsync_polarity = ADV7511_SYNC_POLARITY_LOW;
else
mode_hsync_polarity = ADV7511_SYNC_POLARITY_HIGH;
if (adj_mode->flags & DRM_MODE_FLAG_NVSYNC)
mode_vsync_polarity = ADV7511_SYNC_POLARITY_LOW;
else
mode_vsync_polarity = ADV7511_SYNC_POLARITY_HIGH;
if (adv7511->hsync_polarity != mode_hsync_polarity &&
adv7511->hsync_polarity !=
ADV7511_SYNC_POLARITY_PASSTHROUGH)
hsync_polarity = 1;
if (adv7511->vsync_polarity != mode_vsync_polarity &&
adv7511->vsync_polarity !=
ADV7511_SYNC_POLARITY_PASSTHROUGH)
vsync_polarity = 1;
}
if (mode->vrefresh <= 24000)
low_refresh_rate = ADV7511_LOW_REFRESH_RATE_24HZ;
else if (mode->vrefresh <= 25000)
low_refresh_rate = ADV7511_LOW_REFRESH_RATE_25HZ;
else if (mode->vrefresh <= 30000)
low_refresh_rate = ADV7511_LOW_REFRESH_RATE_30HZ;
else
low_refresh_rate = ADV7511_LOW_REFRESH_RATE_NONE;
regmap_update_bits(adv7511->regmap, 0xfb,
0x6, low_refresh_rate << 1);
regmap_update_bits(adv7511->regmap, 0x17,
0x60, (vsync_polarity << 6) | (hsync_polarity << 5));
adv7511->f_tmds = mode->clock;
}
static int adv7511_parse_dt(struct device_node *np,
struct adv7511_link_config *config)
{
const char *str;
int ret;
memset(config, 0, sizeof(*config));
of_property_read_u32(np, "adi,input-depth", &config->input_color_depth);
if (config->input_color_depth != 8 && config->input_color_depth != 10 &&
config->input_color_depth != 12)
return -EINVAL;
ret = of_property_read_string(np, "adi,input-colorspace", &str);
if (ret < 0)
return ret;
if (!strcmp(str, "rgb"))
config->input_colorspace = HDMI_COLORSPACE_RGB;
else if (!strcmp(str, "yuv422"))
config->input_colorspace = HDMI_COLORSPACE_YUV422;
else if (!strcmp(str, "yuv444"))
config->input_colorspace = HDMI_COLORSPACE_YUV444;
else
return -EINVAL;
ret = of_property_read_string(np, "adi,input-clock", &str);
if (ret < 0)
return ret;
if (!strcmp(str, "1x"))
config->input_clock = ADV7511_INPUT_CLOCK_1X;
else if (!strcmp(str, "2x"))
config->input_clock = ADV7511_INPUT_CLOCK_2X;
else if (!strcmp(str, "ddr"))
config->input_clock = ADV7511_INPUT_CLOCK_DDR;
else
return -EINVAL;
if (config->input_colorspace == HDMI_COLORSPACE_YUV422 ||
config->input_clock != ADV7511_INPUT_CLOCK_1X) {
ret = of_property_read_u32(np, "adi,input-style",
&config->input_style);
if (ret)
return ret;
if (config->input_style < 1 || config->input_style > 3)
return -EINVAL;
ret = of_property_read_string(np, "adi,input-justification",
&str);
if (ret < 0)
return ret;
if (!strcmp(str, "left"))
config->input_justification =
ADV7511_INPUT_JUSTIFICATION_LEFT;
else if (!strcmp(str, "evenly"))
config->input_justification =
ADV7511_INPUT_JUSTIFICATION_EVENLY;
else if (!strcmp(str, "right"))
config->input_justification =
ADV7511_INPUT_JUSTIFICATION_RIGHT;
else
return -EINVAL;
} else {
config->input_style = 1;
config->input_justification = ADV7511_INPUT_JUSTIFICATION_LEFT;
}
of_property_read_u32(np, "adi,clock-delay", &config->clock_delay);
if (config->clock_delay < -1200 || config->clock_delay > 1600)
return -EINVAL;
config->embedded_sync = of_property_read_bool(np, "adi,embedded-sync");
config->sync_pulse = ADV7511_INPUT_SYNC_PULSE_NONE;
config->vsync_polarity = ADV7511_SYNC_POLARITY_PASSTHROUGH;
config->hsync_polarity = ADV7511_SYNC_POLARITY_PASSTHROUGH;
return 0;
}
static int adv7511_probe(struct i2c_client *i2c, const struct i2c_device_id *id)
{
struct adv7511_link_config link_config;
struct adv7511 *adv7511;
struct device *dev = &i2c->dev;
unsigned int val;
int ret;
if (!dev->of_node)
return -EINVAL;
adv7511 = devm_kzalloc(dev, sizeof(*adv7511), GFP_KERNEL);
if (!adv7511)
return -ENOMEM;
adv7511->dpms_mode = DRM_MODE_DPMS_OFF;
adv7511->status = connector_status_disconnected;
ret = adv7511_parse_dt(dev->of_node, &link_config);
if (ret)
return ret;
adv7511->gpio_pd = devm_gpiod_get_optional(dev, "pd", GPIOD_OUT_HIGH);
if (IS_ERR(adv7511->gpio_pd))
return PTR_ERR(adv7511->gpio_pd);
if (adv7511->gpio_pd) {
mdelay(5);
gpiod_set_value_cansleep(adv7511->gpio_pd, 0);
}
adv7511->regmap = devm_regmap_init_i2c(i2c, &adv7511_regmap_config);
if (IS_ERR(adv7511->regmap))
return PTR_ERR(adv7511->regmap);
ret = regmap_read(adv7511->regmap, ADV7511_REG_CHIP_REVISION, &val);
if (ret)
return ret;
dev_dbg(dev, "Rev. %d\n", val);
ret = regmap_register_patch(adv7511->regmap, adv7511_fixed_registers,
ARRAY_SIZE(adv7511_fixed_registers));
if (ret)
return ret;
regmap_write(adv7511->regmap, ADV7511_REG_EDID_I2C_ADDR, edid_i2c_addr);
regmap_write(adv7511->regmap, ADV7511_REG_PACKET_I2C_ADDR,
packet_i2c_addr);
regmap_write(adv7511->regmap, ADV7511_REG_CEC_I2C_ADDR, cec_i2c_addr);
adv7511_packet_disable(adv7511, 0xffff);
adv7511->i2c_main = i2c;
adv7511->i2c_edid = i2c_new_dummy(i2c->adapter, edid_i2c_addr >> 1);
if (!adv7511->i2c_edid)
return -ENOMEM;
if (i2c->irq) {
init_waitqueue_head(&adv7511->wq);
ret = devm_request_threaded_irq(dev, i2c->irq, NULL,
adv7511_irq_handler,
IRQF_ONESHOT, dev_name(dev),
adv7511);
if (ret)
goto err_i2c_unregister_device;
}
regmap_write(adv7511->regmap, ADV7511_REG_CEC_CTRL,
ADV7511_CEC_CTRL_POWER_DOWN);
regmap_update_bits(adv7511->regmap, ADV7511_REG_POWER,
ADV7511_POWER_POWER_DOWN, ADV7511_POWER_POWER_DOWN);
adv7511->current_edid_segment = -1;
i2c_set_clientdata(i2c, adv7511);
adv7511_set_link_config(adv7511, &link_config);
return 0;
err_i2c_unregister_device:
i2c_unregister_device(adv7511->i2c_edid);
return ret;
}
static int adv7511_remove(struct i2c_client *i2c)
{
struct adv7511 *adv7511 = i2c_get_clientdata(i2c);
i2c_unregister_device(adv7511->i2c_edid);
kfree(adv7511->edid);
return 0;
}
static int adv7511_encoder_init(struct i2c_client *i2c, struct drm_device *dev,
struct drm_encoder_slave *encoder)
{
struct adv7511 *adv7511 = i2c_get_clientdata(i2c);
encoder->slave_priv = adv7511;
encoder->slave_funcs = &adv7511_encoder_funcs;
adv7511->encoder = &encoder->base;
return 0;
}
static int __init adv7511_init(void)
{
return drm_i2c_encoder_register(THIS_MODULE, &adv7511_driver);
}
static void __exit adv7511_exit(void)
{
drm_i2c_encoder_unregister(&adv7511_driver);
}
