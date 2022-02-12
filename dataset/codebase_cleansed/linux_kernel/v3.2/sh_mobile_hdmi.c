static void hdmi_write(struct sh_hdmi *hdmi, u8 data, u8 reg)
{
iowrite8(data, hdmi->base + reg);
}
static u8 hdmi_read(struct sh_hdmi *hdmi, u8 reg)
{
return ioread8(hdmi->base + reg);
}
static unsigned int sh_hdmi_snd_read(struct snd_soc_codec *codec,
unsigned int reg)
{
struct sh_hdmi *hdmi = snd_soc_codec_get_drvdata(codec);
return hdmi_read(hdmi, reg);
}
static int sh_hdmi_snd_write(struct snd_soc_codec *codec,
unsigned int reg,
unsigned int value)
{
struct sh_hdmi *hdmi = snd_soc_codec_get_drvdata(codec);
hdmi_write(hdmi, value, reg);
return 0;
}
static int sh_hdmi_snd_probe(struct snd_soc_codec *codec)
{
dev_info(codec->dev, "SH Mobile HDMI Audio Codec");
return 0;
}
static void sh_hdmi_external_video_param(struct sh_hdmi *hdmi)
{
struct fb_var_screeninfo *var = &hdmi->var;
u16 htotal, hblank, hdelay, vtotal, vblank, vdelay, voffset;
u8 sync = 0;
htotal = var->xres + var->right_margin + var->left_margin + var->hsync_len;
hdelay = var->hsync_len + var->left_margin;
hblank = var->right_margin + hdelay;
vtotal = var->yres + var->upper_margin + var->lower_margin + var->vsync_len;
vdelay = var->vsync_len + var->upper_margin;
vblank = var->lower_margin + vdelay;
voffset = min(var->upper_margin / 2, 6U);
if (var->sync & FB_SYNC_HOR_HIGH_ACT)
sync |= 4;
if (var->sync & FB_SYNC_VERT_HIGH_ACT)
sync |= 8;
dev_dbg(hdmi->dev, "H: %u, %u, %u, %u; V: %u, %u, %u, %u; sync 0x%x\n",
htotal, hblank, hdelay, var->hsync_len,
vtotal, vblank, vdelay, var->vsync_len, sync);
hdmi_write(hdmi, sync | (voffset << 4), HDMI_EXTERNAL_VIDEO_PARAM_SETTINGS);
hdmi_write(hdmi, htotal, HDMI_EXTERNAL_H_TOTAL_7_0);
hdmi_write(hdmi, htotal >> 8, HDMI_EXTERNAL_H_TOTAL_11_8);
hdmi_write(hdmi, hblank, HDMI_EXTERNAL_H_BLANK_7_0);
hdmi_write(hdmi, hblank >> 8, HDMI_EXTERNAL_H_BLANK_9_8);
hdmi_write(hdmi, hdelay, HDMI_EXTERNAL_H_DELAY_7_0);
hdmi_write(hdmi, hdelay >> 8, HDMI_EXTERNAL_H_DELAY_9_8);
hdmi_write(hdmi, var->hsync_len, HDMI_EXTERNAL_H_DURATION_7_0);
hdmi_write(hdmi, var->hsync_len >> 8, HDMI_EXTERNAL_H_DURATION_9_8);
hdmi_write(hdmi, vtotal, HDMI_EXTERNAL_V_TOTAL_7_0);
hdmi_write(hdmi, vtotal >> 8, HDMI_EXTERNAL_V_TOTAL_9_8);
hdmi_write(hdmi, vblank, HDMI_EXTERNAL_V_BLANK);
hdmi_write(hdmi, vdelay, HDMI_EXTERNAL_V_DELAY);
hdmi_write(hdmi, var->vsync_len, HDMI_EXTERNAL_V_DURATION);
if (!hdmi->preprogrammed_vic)
hdmi_write(hdmi, sync | 1 | (voffset << 4),
HDMI_EXTERNAL_VIDEO_PARAM_SETTINGS);
}
static void sh_hdmi_video_config(struct sh_hdmi *hdmi)
{
hdmi_write(hdmi, 0x20, HDMI_AUDIO_VIDEO_SETTING_1);
hdmi_write(hdmi, 0x34, HDMI_VIDEO_SETTING_1);
hdmi_write(hdmi, 0x20, HDMI_DEEP_COLOR_MODES);
}
static void sh_hdmi_audio_config(struct sh_hdmi *hdmi)
{
u8 data;
struct sh_mobile_hdmi_info *pdata = hdmi->dev->platform_data;
hdmi_write(hdmi, 0x00, HDMI_L_R_DATA_SWAP_CTRL_RPKT);
hdmi_write(hdmi, 0x18, HDMI_20_BIT_N_FOR_AUDIO_RPKT_15_8);
hdmi_write(hdmi, 0x00, HDMI_20_BIT_N_FOR_AUDIO_RPKT_7_0);
hdmi_write(hdmi, 0x20, HDMI_SPDIF_AUDIO_SAMP_FREQ_CTS);
switch (pdata->flags & HDMI_SND_SRC_MASK) {
default:
case HDMI_SND_SRC_I2S:
data = 0x0 << 3;
break;
case HDMI_SND_SRC_SPDIF:
data = 0x1 << 3;
break;
case HDMI_SND_SRC_DSD:
data = 0x2 << 3;
break;
case HDMI_SND_SRC_HBR:
data = 0x3 << 3;
break;
}
hdmi_write(hdmi, data, HDMI_AUDIO_SETTING_1);
hdmi_write(hdmi, 0x40, HDMI_AUDIO_SETTING_2);
hdmi_write(hdmi, 0x04, HDMI_I2S_AUDIO_SET);
hdmi_write(hdmi, 0x00, HDMI_DSD_AUDIO_SET);
hdmi_write(hdmi, 0x00, HDMI_I2S_INPUT_PIN_SWAP);
hdmi_write(hdmi, 0x00, HDMI_AUDIO_STATUS_BITS_SETTING_1);
hdmi_write(hdmi, 0x00, HDMI_AUDIO_STATUS_BITS_SETTING_2);
hdmi_write(hdmi, 0x00, HDMI_CATEGORY_CODE);
hdmi_write(hdmi, 0x00, HDMI_SOURCE_NUM_AUDIO_WORD_LEN);
hdmi_write(hdmi, 0x20, HDMI_AUDIO_VIDEO_SETTING_1);
}
static void sh_hdmi_phy_config(struct sh_hdmi *hdmi)
{
if (hdmi->var.pixclock < 10000) {
hdmi_write(hdmi, 0x1d, HDMI_SLIPHDMIT_PARAM_SETTINGS_1);
hdmi_write(hdmi, 0x00, HDMI_SLIPHDMIT_PARAM_SETTINGS_2);
hdmi_write(hdmi, 0x00, HDMI_SLIPHDMIT_PARAM_SETTINGS_3);
hdmi_write(hdmi, 0x4c, HDMI_SLIPHDMIT_PARAM_SETTINGS_5);
hdmi_write(hdmi, 0x1e, HDMI_SLIPHDMIT_PARAM_SETTINGS_6);
hdmi_write(hdmi, 0x48, HDMI_SLIPHDMIT_PARAM_SETTINGS_7);
hdmi_write(hdmi, 0x0e, HDMI_SLIPHDMIT_PARAM_SETTINGS_8);
hdmi_write(hdmi, 0x25, HDMI_SLIPHDMIT_PARAM_SETTINGS_9);
hdmi_write(hdmi, 0x04, HDMI_SLIPHDMIT_PARAM_SETTINGS_10);
} else if (hdmi->var.pixclock < 30000) {
hdmi_write(hdmi, 0x0f, HDMI_SLIPHDMIT_PARAM_SETTINGS_1);
hdmi_write(hdmi, 0x00, HDMI_SLIPHDMIT_PARAM_SETTINGS_2);
hdmi_write(hdmi, 0x00, HDMI_SLIPHDMIT_PARAM_SETTINGS_3);
hdmi_write(hdmi, 0x44, HDMI_SLIPHDMIT_PARAM_SETTINGS_5);
hdmi_write(hdmi, 0x32, HDMI_SLIPHDMIT_PARAM_SETTINGS_6);
hdmi_write(hdmi, 0x4A, HDMI_SLIPHDMIT_PARAM_SETTINGS_7);
hdmi_write(hdmi, 0x00, HDMI_SLIPHDMIT_PARAM_SETTINGS_8);
hdmi_write(hdmi, 0x25, HDMI_SLIPHDMIT_PARAM_SETTINGS_9);
hdmi_write(hdmi, 0x04, HDMI_SLIPHDMIT_PARAM_SETTINGS_10);
} else {
hdmi_write(hdmi, 0x19, HDMI_SLIPHDMIT_PARAM_SETTINGS_1);
hdmi_write(hdmi, 0x00, HDMI_SLIPHDMIT_PARAM_SETTINGS_2);
hdmi_write(hdmi, 0x00, HDMI_SLIPHDMIT_PARAM_SETTINGS_3);
hdmi_write(hdmi, 0x44, HDMI_SLIPHDMIT_PARAM_SETTINGS_5);
hdmi_write(hdmi, 0x32, HDMI_SLIPHDMIT_PARAM_SETTINGS_6);
hdmi_write(hdmi, 0x48, HDMI_SLIPHDMIT_PARAM_SETTINGS_7);
hdmi_write(hdmi, 0x0F, HDMI_SLIPHDMIT_PARAM_SETTINGS_8);
hdmi_write(hdmi, 0x20, HDMI_SLIPHDMIT_PARAM_SETTINGS_9);
hdmi_write(hdmi, 0x04, HDMI_SLIPHDMIT_PARAM_SETTINGS_10);
}
}
static void sh_hdmi_avi_infoframe_setup(struct sh_hdmi *hdmi)
{
u8 vic;
hdmi_write(hdmi, 0x06, HDMI_CTRL_PKT_BUF_INDEX);
hdmi_write(hdmi, 0x82, HDMI_CTRL_PKT_BUF_ACCESS_HB0);
hdmi_write(hdmi, 0x02, HDMI_CTRL_PKT_BUF_ACCESS_HB1);
hdmi_write(hdmi, 0x0D, HDMI_CTRL_PKT_BUF_ACCESS_HB2);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB0);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB1);
hdmi_write(hdmi, 0x28, HDMI_CTRL_PKT_BUF_ACCESS_PB2);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB3);
if (hdmi->preprogrammed_vic)
vic = hdmi->preprogrammed_vic;
else
vic = 4;
hdmi_write(hdmi, vic, HDMI_CTRL_PKT_BUF_ACCESS_PB4);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB5);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB6);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB7);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB8);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB9);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB10);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB11);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB12);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB13);
}
static void sh_hdmi_audio_infoframe_setup(struct sh_hdmi *hdmi)
{
hdmi_write(hdmi, 0x08, HDMI_CTRL_PKT_BUF_INDEX);
hdmi_write(hdmi, 0x84, HDMI_CTRL_PKT_BUF_ACCESS_HB0);
hdmi_write(hdmi, 0x01, HDMI_CTRL_PKT_BUF_ACCESS_HB1);
hdmi_write(hdmi, 0x0A, HDMI_CTRL_PKT_BUF_ACCESS_HB2);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB0);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB1);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB2);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB3);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB4);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB5);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB6);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB7);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB8);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB9);
hdmi_write(hdmi, 0x00, HDMI_CTRL_PKT_BUF_ACCESS_PB10);
}
static void sh_hdmi_configure(struct sh_hdmi *hdmi)
{
sh_hdmi_video_config(hdmi);
sh_hdmi_audio_config(hdmi);
sh_hdmi_phy_config(hdmi);
sh_hdmi_avi_infoframe_setup(hdmi);
sh_hdmi_audio_infoframe_setup(hdmi);
hdmi_write(hdmi, 0x8E, HDMI_CTRL_PKT_AUTO_SEND);
msleep(10);
hdmi_write(hdmi, 0x4C, HDMI_SYSTEM_CTRL);
udelay(10);
hdmi_write(hdmi, 0x40, HDMI_SYSTEM_CTRL);
}
static unsigned long sh_hdmi_rate_error(struct sh_hdmi *hdmi,
const struct fb_videomode *mode,
unsigned long *hdmi_rate, unsigned long *parent_rate)
{
unsigned long target = PICOS2KHZ(mode->pixclock) * 1000, rate_error;
struct sh_mobile_hdmi_info *pdata = hdmi->dev->platform_data;
*hdmi_rate = clk_round_rate(hdmi->hdmi_clk, target);
if ((long)*hdmi_rate < 0)
*hdmi_rate = clk_get_rate(hdmi->hdmi_clk);
rate_error = (long)*hdmi_rate > 0 ? abs(*hdmi_rate - target) : ULONG_MAX;
if (rate_error && pdata->clk_optimize_parent)
rate_error = pdata->clk_optimize_parent(target, hdmi_rate, parent_rate);
else if (clk_get_parent(hdmi->hdmi_clk))
*parent_rate = clk_get_rate(clk_get_parent(hdmi->hdmi_clk));
dev_dbg(hdmi->dev, "%u-%u-%u-%u x %u-%u-%u-%u\n",
mode->left_margin, mode->xres,
mode->right_margin, mode->hsync_len,
mode->upper_margin, mode->yres,
mode->lower_margin, mode->vsync_len);
dev_dbg(hdmi->dev, "\t@%lu(+/-%lu)Hz, e=%lu / 1000, r=%uHz, p=%luHz\n", target,
rate_error, rate_error ? 10000 / (10 * target / rate_error) : 0,
mode->refresh, *parent_rate);
return rate_error;
}
static int sh_hdmi_read_edid(struct sh_hdmi *hdmi, unsigned long *hdmi_rate,
unsigned long *parent_rate)
{
struct fb_var_screeninfo tmpvar;
struct fb_var_screeninfo *var = &tmpvar;
const struct fb_videomode *mode, *found = NULL;
struct fb_info *info = hdmi->info;
struct fb_modelist *modelist = NULL;
unsigned int f_width = 0, f_height = 0, f_refresh = 0;
unsigned long found_rate_error = ULONG_MAX;
bool scanning = false, preferred_bad = false;
u8 edid[128];
char *forced;
int i;
dev_dbg(hdmi->dev, "Read back EDID code:");
for (i = 0; i < 128; i++) {
edid[i] = hdmi_read(hdmi, HDMI_EDID_KSV_FIFO_ACCESS_WINDOW);
#ifdef DEBUG
if ((i % 16) == 0) {
printk(KERN_CONT "\n");
printk(KERN_DEBUG "%02X | %02X", i, edid[i]);
} else {
printk(KERN_CONT " %02X", edid[i]);
}
#endif
}
#ifdef DEBUG
printk(KERN_CONT "\n");
#endif
if (!hdmi->edid_blocks) {
fb_edid_to_monspecs(edid, &hdmi->monspec);
hdmi->edid_blocks = edid[126] + 1;
dev_dbg(hdmi->dev, "%d main modes, %d extension blocks\n",
hdmi->monspec.modedb_len, hdmi->edid_blocks - 1);
} else {
dev_dbg(hdmi->dev, "Extension %u detected, DTD start %u\n",
edid[0], edid[2]);
fb_edid_add_monspecs(edid, &hdmi->monspec);
}
if (hdmi->edid_blocks > hdmi->edid_segment_nr * 2 +
(hdmi->edid_block_addr >> 7) + 1) {
if (hdmi->edid_block_addr) {
hdmi->edid_block_addr = 0;
hdmi->edid_segment_nr++;
} else {
hdmi->edid_block_addr = 0x80;
}
hdmi_write(hdmi, hdmi->edid_block_addr, HDMI_EDID_WORD_ADDRESS);
hdmi_write(hdmi, 0xC6, HDMI_INTERRUPT_MASK_1);
hdmi_write(hdmi, hdmi->edid_segment_nr, HDMI_EDID_SEGMENT_POINTER);
return -EAGAIN;
}
dev_dbg(hdmi->dev, "%d main and extended modes\n", hdmi->monspec.modedb_len);
fb_get_options("sh_mobile_lcdc", &forced);
if (forced && *forced) {
i = sscanf(forced, "%ux%u@%u",
&f_width, &f_height, &f_refresh);
if (i < 2) {
f_width = 0;
f_height = 0;
} else {
scanning = true;
}
dev_dbg(hdmi->dev, "Forced mode %ux%u@%uHz\n",
f_width, f_height, f_refresh);
}
for (i = 0, mode = hdmi->monspec.modedb;
i < hdmi->monspec.modedb_len && scanning;
i++, mode++) {
unsigned long rate_error;
if (!f_width && !f_height) {
if ((mode->flag & FB_MODE_IS_FIRST) || preferred_bad)
scanning = false;
else
continue;
} else if (f_width != mode->xres || f_height != mode->yres) {
continue;
}
rate_error = sh_hdmi_rate_error(hdmi, mode, hdmi_rate, parent_rate);
if (scanning) {
if (f_refresh == mode->refresh || (!f_refresh && !rate_error))
scanning = false;
else if (found && found_rate_error <= rate_error)
continue;
}
fb_videomode_to_var(var, mode);
var->bits_per_pixel = info->var.bits_per_pixel;
if (info && info->fbops->fb_check_var &&
info->fbops->fb_check_var(var, info)) {
scanning = true;
preferred_bad = true;
continue;
}
found = mode;
found_rate_error = rate_error;
}
hdmi->var.width = hdmi->monspec.max_x * 10;
hdmi->var.height = hdmi->monspec.max_y * 10;
if (info && !found) {
modelist = info->modelist.next &&
!list_empty(&info->modelist) ?
list_entry(info->modelist.next,
struct fb_modelist, list) :
NULL;
if (modelist) {
found = &modelist->mode;
found_rate_error = sh_hdmi_rate_error(hdmi, found, hdmi_rate, parent_rate);
}
}
if (!found)
return -ENXIO;
if (found->xres == 640 && found->yres == 480 && found->refresh == 60)
hdmi->preprogrammed_vic = 1;
else if (found->xres == 720 && found->yres == 480 && found->refresh == 60)
hdmi->preprogrammed_vic = 2;
else if (found->xres == 720 && found->yres == 576 && found->refresh == 50)
hdmi->preprogrammed_vic = 17;
else if (found->xres == 1280 && found->yres == 720 && found->refresh == 60)
hdmi->preprogrammed_vic = 4;
else if (found->xres == 1920 && found->yres == 1080 && found->refresh == 24)
hdmi->preprogrammed_vic = 32;
else if (found->xres == 1920 && found->yres == 1080 && found->refresh == 50)
hdmi->preprogrammed_vic = 31;
else if (found->xres == 1920 && found->yres == 1080 && found->refresh == 60)
hdmi->preprogrammed_vic = 16;
else
hdmi->preprogrammed_vic = 0;
dev_dbg(hdmi->dev, "Using %s %s mode %ux%u@%uHz (%luHz), clock error %luHz\n",
modelist ? "default" : "EDID", hdmi->preprogrammed_vic ? "VIC" : "external",
found->xres, found->yres, found->refresh,
PICOS2KHZ(found->pixclock) * 1000, found_rate_error);
fb_videomode_to_var(&hdmi->var, found);
sh_hdmi_external_video_param(hdmi);
return 0;
}
static irqreturn_t sh_hdmi_hotplug(int irq, void *dev_id)
{
struct sh_hdmi *hdmi = dev_id;
u8 status1, status2, mask1, mask2;
hdmi_write(hdmi, 0x2C, HDMI_SYSTEM_CTRL);
udelay(10);
hdmi_write(hdmi, 0x20, HDMI_SYSTEM_CTRL);
status1 = hdmi_read(hdmi, HDMI_INTERRUPT_STATUS_1);
status2 = hdmi_read(hdmi, HDMI_INTERRUPT_STATUS_2);
mask1 = hdmi_read(hdmi, HDMI_INTERRUPT_MASK_1);
mask2 = hdmi_read(hdmi, HDMI_INTERRUPT_MASK_2);
hdmi_write(hdmi, 0xFF, HDMI_INTERRUPT_STATUS_1);
hdmi_write(hdmi, 0xFF, HDMI_INTERRUPT_STATUS_2);
if (printk_ratelimit())
dev_dbg(hdmi->dev, "IRQ #%d: Status #1: 0x%x & 0x%x, #2: 0x%x & 0x%x\n",
irq, status1, mask1, status2, mask2);
if (!((status1 & mask1) | (status2 & mask2))) {
return IRQ_NONE;
} else if (status1 & 0xc0) {
u8 msens;
udelay(500);
msens = hdmi_read(hdmi, HDMI_HOT_PLUG_MSENS_STATUS);
dev_dbg(hdmi->dev, "MSENS 0x%x\n", msens);
if ((msens & 0xC0) == 0xC0) {
hdmi->edid_segment_nr = 0;
hdmi->edid_block_addr = 0;
hdmi->edid_blocks = 0;
hdmi->hp_state = HDMI_HOTPLUG_CONNECTED;
hdmi_write(hdmi, 0x00, HDMI_EDID_WORD_ADDRESS);
hdmi_write(hdmi, 0xC6, HDMI_INTERRUPT_MASK_1);
hdmi_write(hdmi, 0x00, HDMI_EDID_SEGMENT_POINTER);
} else if (!(status1 & 0x80)) {
if (hdmi->hp_state != HDMI_HOTPLUG_DISCONNECTED) {
hdmi->hp_state = HDMI_HOTPLUG_DISCONNECTED;
schedule_delayed_work(&hdmi->edid_work, 0);
}
}
} else if (status1 & 2) {
hdmi_write(hdmi, hdmi->edid_block_addr, HDMI_EDID_WORD_ADDRESS);
hdmi_write(hdmi, hdmi->edid_segment_nr, HDMI_EDID_SEGMENT_POINTER);
} else if (status1 & 4) {
hdmi_write(hdmi, 0xC0, HDMI_INTERRUPT_MASK_1);
schedule_delayed_work(&hdmi->edid_work, msecs_to_jiffies(10));
}
return IRQ_HANDLED;
}
static void sh_hdmi_display_on(void *arg, struct fb_info *info)
{
struct sh_hdmi *hdmi = arg;
struct sh_mobile_hdmi_info *pdata = hdmi->dev->platform_data;
struct sh_mobile_lcdc_chan *ch = info->par;
dev_dbg(hdmi->dev, "%s(%p): state %x\n", __func__,
pdata->lcd_dev, info->state);
hdmi->info = info;
switch (hdmi->hp_state) {
case HDMI_HOTPLUG_EDID_DONE:
hdmi_write(hdmi, 0x80, HDMI_SYSTEM_CTRL);
dev_dbg(hdmi->dev, "HDMI running\n");
break;
case HDMI_HOTPLUG_DISCONNECTED:
info->state = FBINFO_STATE_SUSPENDED;
default:
hdmi->var = ch->display_var;
}
}
static void sh_hdmi_display_off(void *arg)
{
struct sh_hdmi *hdmi = arg;
struct sh_mobile_hdmi_info *pdata = hdmi->dev->platform_data;
dev_dbg(hdmi->dev, "%s(%p)\n", __func__, pdata->lcd_dev);
hdmi_write(hdmi, 0x10, HDMI_SYSTEM_CTRL);
}
static bool sh_hdmi_must_reconfigure(struct sh_hdmi *hdmi)
{
struct fb_info *info = hdmi->info;
struct sh_mobile_lcdc_chan *ch = info->par;
struct fb_var_screeninfo *new_var = &hdmi->var, *old_var = &ch->display_var;
struct fb_videomode mode1, mode2;
fb_var_to_videomode(&mode1, old_var);
fb_var_to_videomode(&mode2, new_var);
dev_dbg(info->dev, "Old %ux%u, new %ux%u\n",
mode1.xres, mode1.yres, mode2.xres, mode2.yres);
if (fb_mode_is_equal(&mode1, &mode2)) {
old_var->width = new_var->width;
old_var->height = new_var->height;
return false;
}
dev_dbg(info->dev, "Switching %u -> %u lines\n",
mode1.yres, mode2.yres);
*old_var = *new_var;
return true;
}
static long sh_hdmi_clk_configure(struct sh_hdmi *hdmi, unsigned long hdmi_rate,
unsigned long parent_rate)
{
int ret;
if (parent_rate && clk_get_parent(hdmi->hdmi_clk)) {
ret = clk_set_rate(clk_get_parent(hdmi->hdmi_clk), parent_rate);
if (ret < 0) {
dev_warn(hdmi->dev, "Cannot set parent rate %ld: %d\n", parent_rate, ret);
hdmi_rate = clk_round_rate(hdmi->hdmi_clk, hdmi_rate);
} else {
dev_dbg(hdmi->dev, "HDMI set parent frequency %lu\n", parent_rate);
}
}
ret = clk_set_rate(hdmi->hdmi_clk, hdmi_rate);
if (ret < 0) {
dev_warn(hdmi->dev, "Cannot set rate %ld: %d\n", hdmi_rate, ret);
hdmi_rate = 0;
} else {
dev_dbg(hdmi->dev, "HDMI set frequency %lu\n", hdmi_rate);
}
return hdmi_rate;
}
static void sh_hdmi_edid_work_fn(struct work_struct *work)
{
struct sh_hdmi *hdmi = container_of(work, struct sh_hdmi, edid_work.work);
struct fb_info *info;
struct sh_mobile_hdmi_info *pdata = hdmi->dev->platform_data;
struct sh_mobile_lcdc_chan *ch;
int ret;
dev_dbg(hdmi->dev, "%s(%p): begin, hotplug status %d\n", __func__,
pdata->lcd_dev, hdmi->hp_state);
if (!pdata->lcd_dev)
return;
mutex_lock(&hdmi->mutex);
info = hdmi->info;
if (hdmi->hp_state == HDMI_HOTPLUG_CONNECTED) {
unsigned long parent_rate = 0, hdmi_rate;
ret = sh_hdmi_read_edid(hdmi, &hdmi_rate, &parent_rate);
if (ret < 0)
goto out;
hdmi->hp_state = HDMI_HOTPLUG_EDID_DONE;
ret = sh_hdmi_clk_configure(hdmi, hdmi_rate, parent_rate);
if (ret < 0)
goto out;
msleep(10);
sh_hdmi_configure(hdmi);
msleep(10);
if (!info)
goto out;
ch = info->par;
if (lock_fb_info(info)) {
console_lock();
if (!sh_hdmi_must_reconfigure(hdmi) &&
info->state == FBINFO_STATE_RUNNING) {
info->var.width = hdmi->var.width;
info->var.height = hdmi->var.height;
sh_hdmi_display_on(hdmi, info);
} else {
fb_set_suspend(info, 0);
}
console_unlock();
unlock_fb_info(info);
}
} else {
ret = 0;
if (!info)
goto out;
hdmi->monspec.modedb_len = 0;
fb_destroy_modedb(hdmi->monspec.modedb);
hdmi->monspec.modedb = NULL;
if (lock_fb_info(info)) {
console_lock();
fb_set_suspend(info, 1);
console_unlock();
unlock_fb_info(info);
}
}
out:
if (ret < 0 && ret != -EAGAIN)
hdmi->hp_state = HDMI_HOTPLUG_DISCONNECTED;
mutex_unlock(&hdmi->mutex);
dev_dbg(hdmi->dev, "%s(%p): end\n", __func__, pdata->lcd_dev);
}
static int sh_hdmi_notify(struct notifier_block *nb,
unsigned long action, void *data)
{
struct fb_event *event = data;
struct fb_info *info = event->info;
struct sh_mobile_lcdc_chan *ch = info->par;
struct sh_mobile_lcdc_board_cfg *board_cfg = &ch->cfg.board_cfg;
struct sh_hdmi *hdmi = board_cfg->board_data;
if (!hdmi || nb != &hdmi->notifier || hdmi->info != info)
return NOTIFY_DONE;
switch(action) {
case FB_EVENT_FB_REGISTERED:
break;
case FB_EVENT_FB_UNREGISTERED:
unlock_fb_info(info);
mutex_lock(&hdmi->mutex);
hdmi->info = NULL;
mutex_unlock(&hdmi->mutex);
lock_fb_info(info);
return NOTIFY_OK;
}
return NOTIFY_DONE;
}
static int __init sh_hdmi_probe(struct platform_device *pdev)
{
struct sh_mobile_hdmi_info *pdata = pdev->dev.platform_data;
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
struct sh_mobile_lcdc_board_cfg *board_cfg;
int irq = platform_get_irq(pdev, 0), ret;
struct sh_hdmi *hdmi;
long rate;
if (!res || !pdata || irq < 0)
return -ENODEV;
hdmi = kzalloc(sizeof(*hdmi), GFP_KERNEL);
if (!hdmi) {
dev_err(&pdev->dev, "Cannot allocate device data\n");
return -ENOMEM;
}
mutex_init(&hdmi->mutex);
hdmi->dev = &pdev->dev;
hdmi->hdmi_clk = clk_get(&pdev->dev, "ick");
if (IS_ERR(hdmi->hdmi_clk)) {
ret = PTR_ERR(hdmi->hdmi_clk);
dev_err(&pdev->dev, "Unable to get clock: %d\n", ret);
goto egetclk;
}
rate = clk_round_rate(hdmi->hdmi_clk, PICOS2KHZ(37037));
if (rate > 0)
rate = sh_hdmi_clk_configure(hdmi, rate, 0);
if (rate < 0) {
ret = rate;
goto erate;
}
ret = clk_enable(hdmi->hdmi_clk);
if (ret < 0) {
dev_err(hdmi->dev, "Cannot enable clock: %d\n", ret);
goto erate;
}
dev_dbg(&pdev->dev, "Enabled HDMI clock at %luHz\n", rate);
if (!request_mem_region(res->start, resource_size(res), dev_name(&pdev->dev))) {
dev_err(&pdev->dev, "HDMI register region already claimed\n");
ret = -EBUSY;
goto ereqreg;
}
hdmi->base = ioremap(res->start, resource_size(res));
if (!hdmi->base) {
dev_err(&pdev->dev, "HDMI register region already claimed\n");
ret = -ENOMEM;
goto emap;
}
platform_set_drvdata(pdev, hdmi);
board_cfg = &pdata->lcd_chan->board_cfg;
board_cfg->owner = THIS_MODULE;
board_cfg->board_data = hdmi;
board_cfg->display_on = sh_hdmi_display_on;
board_cfg->display_off = sh_hdmi_display_off;
INIT_DELAYED_WORK(&hdmi->edid_work, sh_hdmi_edid_work_fn);
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
dev_info(&pdev->dev, "Detected HDMI controller 0x%x:0x%x\n",
hdmi_read(hdmi, HDMI_PRODUCT_ID), hdmi_read(hdmi, HDMI_REVISION_ID));
ret = request_irq(irq, sh_hdmi_hotplug, 0,
dev_name(&pdev->dev), hdmi);
if (ret < 0) {
dev_err(&pdev->dev, "Unable to request irq: %d\n", ret);
goto ereqirq;
}
ret = snd_soc_register_codec(&pdev->dev,
&soc_codec_dev_sh_hdmi, &sh_hdmi_dai, 1);
if (ret < 0) {
dev_err(&pdev->dev, "codec registration failed\n");
goto ecodec;
}
hdmi->notifier.notifier_call = sh_hdmi_notify;
fb_register_client(&hdmi->notifier);
return 0;
ecodec:
free_irq(irq, hdmi);
ereqirq:
pm_runtime_put(&pdev->dev);
pm_runtime_disable(&pdev->dev);
iounmap(hdmi->base);
emap:
release_mem_region(res->start, resource_size(res));
ereqreg:
clk_disable(hdmi->hdmi_clk);
erate:
clk_put(hdmi->hdmi_clk);
egetclk:
mutex_destroy(&hdmi->mutex);
kfree(hdmi);
return ret;
}
static int __exit sh_hdmi_remove(struct platform_device *pdev)
{
struct sh_mobile_hdmi_info *pdata = pdev->dev.platform_data;
struct sh_hdmi *hdmi = platform_get_drvdata(pdev);
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
struct sh_mobile_lcdc_board_cfg *board_cfg = &pdata->lcd_chan->board_cfg;
int irq = platform_get_irq(pdev, 0);
snd_soc_unregister_codec(&pdev->dev);
fb_unregister_client(&hdmi->notifier);
board_cfg->display_on = NULL;
board_cfg->display_off = NULL;
board_cfg->board_data = NULL;
board_cfg->owner = NULL;
free_irq(irq, hdmi);
cancel_delayed_work_sync(&hdmi->edid_work);
pm_runtime_put(&pdev->dev);
pm_runtime_disable(&pdev->dev);
clk_disable(hdmi->hdmi_clk);
clk_put(hdmi->hdmi_clk);
iounmap(hdmi->base);
release_mem_region(res->start, resource_size(res));
mutex_destroy(&hdmi->mutex);
kfree(hdmi);
return 0;
}
static int __init sh_hdmi_init(void)
{
return platform_driver_probe(&sh_hdmi_driver, sh_hdmi_probe);
}
static void __exit sh_hdmi_exit(void)
{
platform_driver_unregister(&sh_hdmi_driver);
}
