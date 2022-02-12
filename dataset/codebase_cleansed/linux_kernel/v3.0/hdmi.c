static inline void hdmi_write_reg(const struct hdmi_reg idx, u32 val)
{
__raw_writel(val, hdmi.base_wp + idx.idx);
}
static inline u32 hdmi_read_reg(const struct hdmi_reg idx)
{
return __raw_readl(hdmi.base_wp + idx.idx);
}
static inline int hdmi_wait_for_bit_change(const struct hdmi_reg idx,
int b2, int b1, u32 val)
{
u32 t = 0;
while (val != REG_GET(idx, b2, b1)) {
udelay(1);
if (t++ > 10000)
return !val;
}
return val;
}
int hdmi_init_display(struct omap_dss_device *dssdev)
{
DSSDBG("init_display\n");
return 0;
}
static int hdmi_pll_init(enum hdmi_clk_refsel refsel, int dcofreq,
struct hdmi_pll_info *fmt, u16 sd)
{
u32 r;
REG_FLD_MOD(PLLCTRL_PLL_CONTROL, 0x0, 0, 0);
r = hdmi_read_reg(PLLCTRL_CFG1);
r = FLD_MOD(r, fmt->regm, 20, 9);
r = FLD_MOD(r, fmt->regn, 8, 1);
hdmi_write_reg(PLLCTRL_CFG1, r);
r = hdmi_read_reg(PLLCTRL_CFG2);
r = FLD_MOD(r, 0x0, 12, 12);
r = FLD_MOD(r, 0x1, 13, 13);
r = FLD_MOD(r, 0x0, 14, 14);
if (dcofreq) {
REG_FLD_MOD(PLLCTRL_CFG3, sd, 17, 10);
r = FLD_MOD(r, 0x4, 3, 1);
} else {
r = FLD_MOD(r, 0x2, 3, 1);
}
hdmi_write_reg(PLLCTRL_CFG2, r);
r = hdmi_read_reg(PLLCTRL_CFG4);
r = FLD_MOD(r, fmt->regm2, 24, 18);
r = FLD_MOD(r, fmt->regmf, 17, 0);
hdmi_write_reg(PLLCTRL_CFG4, r);
REG_FLD_MOD(PLLCTRL_PLL_GO, 0x1, 0, 0);
if (hdmi_wait_for_bit_change(PLLCTRL_PLL_GO, 0, 0, 1) != 1) {
DSSERR("PLL GO bit not set\n");
return -ETIMEDOUT;
}
if (hdmi_wait_for_bit_change(PLLCTRL_PLL_STATUS, 1, 1, 1) != 1) {
DSSWARN("cannot lock PLL\n");
DSSWARN("CFG1 0x%x\n",
hdmi_read_reg(PLLCTRL_CFG1));
DSSWARN("CFG2 0x%x\n",
hdmi_read_reg(PLLCTRL_CFG2));
DSSWARN("CFG4 0x%x\n",
hdmi_read_reg(PLLCTRL_CFG4));
return -ETIMEDOUT;
}
DSSDBG("PLL locked!\n");
return 0;
}
static int hdmi_set_phy_pwr(enum hdmi_phy_pwr val)
{
REG_FLD_MOD(HDMI_WP_PWR_CTRL, val, 7, 6);
if (hdmi_wait_for_bit_change(HDMI_WP_PWR_CTRL, 5, 4, val) != val) {
DSSERR("Failed to set PHY power mode to %d\n", val);
return -ETIMEDOUT;
}
return 0;
}
static int hdmi_set_pll_pwr(enum hdmi_pll_pwr val)
{
REG_FLD_MOD(HDMI_WP_PWR_CTRL, val, 3, 2);
if (hdmi_wait_for_bit_change(HDMI_WP_PWR_CTRL, 1, 0, val) != val) {
DSSERR("Failed to set PHY_PWR_STATUS\n");
return -ETIMEDOUT;
}
return 0;
}
static int hdmi_pll_reset(void)
{
REG_FLD_MOD(PLLCTRL_PLL_CONTROL, 0x0, 3, 3);
if (hdmi_wait_for_bit_change(PLLCTRL_PLL_STATUS, 0, 0, 1) != 1) {
DSSERR("Failed to sysreset PLL\n");
return -ETIMEDOUT;
}
return 0;
}
static int hdmi_phy_init(void)
{
u16 r = 0;
r = hdmi_set_phy_pwr(HDMI_PHYPWRCMD_LDOON);
if (r)
return r;
r = hdmi_set_phy_pwr(HDMI_PHYPWRCMD_TXON);
if (r)
return r;
hdmi_read_reg(HDMI_TXPHY_TX_CTRL);
REG_FLD_MOD(HDMI_TXPHY_TX_CTRL, 0x1, 31, 30);
hdmi_write_reg(HDMI_TXPHY_DIGITAL_CTRL, 0xF0000000);
REG_FLD_MOD(HDMI_TXPHY_POWER_CTRL, 0xB, 3, 0);
REG_FLD_MOD(HDMI_TXPHY_PAD_CFG_CTRL, 0x1, 27, 27);
return 0;
}
static int hdmi_wait_softreset(void)
{
REG_FLD_MOD(HDMI_WP_SYSCONFIG, 0x1, 0, 0);
if (hdmi_wait_for_bit_change(HDMI_WP_SYSCONFIG, 0, 0, 0) != 0) {
DSSERR("sysconfig reset failed\n");
return -ETIMEDOUT;
}
return 0;
}
static int hdmi_pll_program(struct hdmi_pll_info *fmt)
{
u16 r = 0;
enum hdmi_clk_refsel refsel;
r = hdmi_wait_softreset();
if (r)
return r;
r = hdmi_set_pll_pwr(HDMI_PLLPWRCMD_ALLOFF);
if (r)
return r;
r = hdmi_set_pll_pwr(HDMI_PLLPWRCMD_BOTHON_ALLCLKS);
if (r)
return r;
r = hdmi_pll_reset();
if (r)
return r;
refsel = HDMI_REFSEL_SYSCLK;
r = hdmi_pll_init(refsel, fmt->dcofreq, fmt, fmt->regsd);
if (r)
return r;
return 0;
}
static void hdmi_phy_off(void)
{
hdmi_set_phy_pwr(HDMI_PHYPWRCMD_OFF);
}
static int hdmi_core_ddc_edid(u8 *pedid, int ext)
{
u32 i, j;
char checksum = 0;
u32 offset = 0;
REG_FLD_MOD(HDMI_CORE_AV_DPD, 0x7, 2, 0);
usleep_range(800, 1000);
if (!ext) {
REG_FLD_MOD(HDMI_CORE_DDC_CMD, 0xA, 3, 0);
if (hdmi_wait_for_bit_change(HDMI_CORE_DDC_STATUS,
4, 4, 0) != 0) {
DSSERR("Failed to program DDC\n");
return -ETIMEDOUT;
}
REG_FLD_MOD(HDMI_CORE_DDC_CMD, 0x9, 3, 0);
if (hdmi_wait_for_bit_change(HDMI_CORE_DDC_STATUS,
4, 4, 0) != 0) {
DSSERR("Failed to program DDC\n");
return -ETIMEDOUT;
}
} else {
if (ext % 2 != 0)
offset = 0x80;
}
REG_FLD_MOD(HDMI_CORE_DDC_SEGM, ext/2, 7, 0);
REG_FLD_MOD(HDMI_CORE_DDC_ADDR, 0xA0 >> 1, 7, 1);
REG_FLD_MOD(HDMI_CORE_DDC_OFFSET, offset, 7, 0);
REG_FLD_MOD(HDMI_CORE_DDC_COUNT1, 0x80, 7, 0);
REG_FLD_MOD(HDMI_CORE_DDC_COUNT2, 0x0, 1, 0);
if (ext)
REG_FLD_MOD(HDMI_CORE_DDC_CMD, 0x4, 3, 0);
else
REG_FLD_MOD(HDMI_CORE_DDC_CMD, 0x2, 3, 0);
if (REG_GET(HDMI_CORE_DDC_STATUS, 6, 6) == 1) {
DSSWARN("I2C Bus Low?\n");
return -EIO;
}
if (REG_GET(HDMI_CORE_DDC_STATUS, 5, 5) == 1) {
DSSWARN("I2C No Ack\n");
return -EIO;
}
i = ext * 128;
j = 0;
while (((REG_GET(HDMI_CORE_DDC_STATUS, 4, 4) == 1) ||
(REG_GET(HDMI_CORE_DDC_STATUS, 2, 2) == 0)) &&
j < 128) {
if (REG_GET(HDMI_CORE_DDC_STATUS, 2, 2) == 0) {
pedid[i++] = REG_GET(HDMI_CORE_DDC_DATA, 7, 0);
j++;
}
}
for (j = 0; j < 128; j++)
checksum += pedid[j];
if (checksum != 0) {
DSSERR("E-EDID checksum failed!!\n");
return -EIO;
}
return 0;
}
static int read_edid(u8 *pedid, u16 max_length)
{
int r = 0, n = 0, i = 0;
int max_ext_blocks = (max_length / 128) - 1;
r = hdmi_core_ddc_edid(pedid, 0);
if (r) {
return r;
} else {
n = pedid[0x7e];
if (n > max_ext_blocks)
n = max_ext_blocks;
for (i = 1; i <= n; i++) {
r = hdmi_core_ddc_edid(pedid, i);
if (r)
return r;
}
}
return 0;
}
static int get_timings_index(void)
{
int code;
if (hdmi.mode == 0)
code = code_vesa[hdmi.code];
else
code = code_cea[hdmi.code];
if (code == -1) {
hdmi.code = 4;
hdmi.mode = HDMI_DVI;
code = code_vesa[hdmi.code];
}
return code;
}
static struct hdmi_cm hdmi_get_code(struct omap_video_timings *timing)
{
int i = 0, code = -1, temp_vsync = 0, temp_hsync = 0;
int timing_vsync = 0, timing_hsync = 0;
struct omap_video_timings temp;
struct hdmi_cm cm = {-1};
DSSDBG("hdmi_get_code\n");
for (i = 0; i < OMAP_HDMI_TIMINGS_NB; i++) {
temp = cea_vesa_timings[i].timings;
if ((temp.pixel_clock == timing->pixel_clock) &&
(temp.x_res == timing->x_res) &&
(temp.y_res == timing->y_res)) {
temp_hsync = temp.hfp + temp.hsw + temp.hbp;
timing_hsync = timing->hfp + timing->hsw + timing->hbp;
temp_vsync = temp.vfp + temp.vsw + temp.vbp;
timing_vsync = timing->vfp + timing->vsw + timing->vbp;
DSSDBG("temp_hsync = %d , temp_vsync = %d"
"timing_hsync = %d, timing_vsync = %d\n",
temp_hsync, temp_hsync,
timing_hsync, timing_vsync);
if ((temp_hsync == timing_hsync) &&
(temp_vsync == timing_vsync)) {
code = i;
cm.code = code_index[i];
if (code < 14)
cm.mode = HDMI_HDMI;
else
cm.mode = HDMI_DVI;
DSSDBG("Hdmi_code = %d mode = %d\n",
cm.code, cm.mode);
break;
}
}
}
return cm;
}
static void get_horz_vert_timing_info(int current_descriptor_addrs, u8 *edid ,
struct omap_video_timings *timings)
{
timings->x_res = (((edid[current_descriptor_addrs + 4] & 0xF0) << 4) |
edid[current_descriptor_addrs + 2]);
timings->y_res = (((edid[current_descriptor_addrs + 7] & 0xF0) << 4) |
edid[current_descriptor_addrs + 5]);
timings->pixel_clock = ((edid[current_descriptor_addrs + 1] << 8) |
edid[current_descriptor_addrs]);
timings->pixel_clock = 10 * timings->pixel_clock;
timings->hfp = edid[current_descriptor_addrs + 8] |
((edid[current_descriptor_addrs + 11] & 0xc0) << 2);
timings->hsw = edid[current_descriptor_addrs + 9] |
((edid[current_descriptor_addrs + 11] & 0x30) << 4);
timings->hbp = (((edid[current_descriptor_addrs + 4] & 0x0F) << 8) |
edid[current_descriptor_addrs + 3]) -
(timings->hfp + timings->hsw);
timings->vfp = ((edid[current_descriptor_addrs + 10] & 0xF0) >> 4) |
((edid[current_descriptor_addrs + 11] & 0x0f) << 2);
timings->vsw = (edid[current_descriptor_addrs + 10] & 0x0F) |
((edid[current_descriptor_addrs + 11] & 0x03) << 4);
timings->vbp = (((edid[current_descriptor_addrs + 7] & 0x0F) << 8) |
edid[current_descriptor_addrs + 6]) -
(timings->vfp + timings->vsw);
}
static void get_edid_timing_data(u8 *edid)
{
u8 count;
u16 current_descriptor_addrs;
struct hdmi_cm cm;
struct omap_video_timings edid_timings;
for (count = 0; count < EDID_SIZE_BLOCK0_TIMING_DESCRIPTOR; count++) {
current_descriptor_addrs =
EDID_DESCRIPTOR_BLOCK0_ADDRESS +
count * EDID_TIMING_DESCRIPTOR_SIZE;
get_horz_vert_timing_info(current_descriptor_addrs,
edid, &edid_timings);
cm = hdmi_get_code(&edid_timings);
DSSDBG("Block0[%d] value matches code = %d , mode = %d\n",
count, cm.code, cm.mode);
if (cm.code == -1) {
continue;
} else {
hdmi.code = cm.code;
hdmi.mode = cm.mode;
DSSDBG("code = %d , mode = %d\n",
hdmi.code, hdmi.mode);
return;
}
}
if (edid[0x7e] != 0x00) {
for (count = 0; count < EDID_SIZE_BLOCK1_TIMING_DESCRIPTOR;
count++) {
current_descriptor_addrs =
EDID_DESCRIPTOR_BLOCK1_ADDRESS +
count * EDID_TIMING_DESCRIPTOR_SIZE;
get_horz_vert_timing_info(current_descriptor_addrs,
edid, &edid_timings);
cm = hdmi_get_code(&edid_timings);
DSSDBG("Block1[%d] value matches code = %d, mode = %d",
count, cm.code, cm.mode);
if (cm.code == -1) {
continue;
} else {
hdmi.code = cm.code;
hdmi.mode = cm.mode;
DSSDBG("code = %d , mode = %d\n",
hdmi.code, hdmi.mode);
return;
}
}
}
DSSINFO("no valid timing found , falling back to VGA\n");
hdmi.code = 4;
hdmi.mode = HDMI_DVI;
}
static void hdmi_read_edid(struct omap_video_timings *dp)
{
int ret = 0, code;
memset(hdmi.edid, 0, HDMI_EDID_MAX_LENGTH);
if (!hdmi.edid_set)
ret = read_edid(hdmi.edid, HDMI_EDID_MAX_LENGTH);
if (!ret) {
if (!memcmp(hdmi.edid, edid_header, sizeof(edid_header))) {
get_edid_timing_data(hdmi.edid);
hdmi.edid_set = true;
}
} else {
DSSWARN("failed to read E-EDID\n");
}
if (!hdmi.edid_set) {
DSSINFO("fallback to VGA\n");
hdmi.code = 4;
hdmi.mode = HDMI_DVI;
}
code = get_timings_index();
*dp = cea_vesa_timings[code].timings;
}
static void hdmi_core_init(struct hdmi_core_video_config *video_cfg,
struct hdmi_core_infoframe_avi *avi_cfg,
struct hdmi_core_packet_enable_repeat *repeat_cfg)
{
DSSDBG("Enter hdmi_core_init\n");
video_cfg->ip_bus_width = HDMI_INPUT_8BIT;
video_cfg->op_dither_truc = HDMI_OUTPUTTRUNCATION_8BIT;
video_cfg->deep_color_pkt = HDMI_DEEPCOLORPACKECTDISABLE;
video_cfg->pkt_mode = HDMI_PACKETMODERESERVEDVALUE;
video_cfg->hdmi_dvi = HDMI_DVI;
video_cfg->tclk_sel_clkmult = HDMI_FPLL10IDCK;
avi_cfg->db1_format = 0;
avi_cfg->db1_active_info = 0;
avi_cfg->db1_bar_info_dv = 0;
avi_cfg->db1_scan_info = 0;
avi_cfg->db2_colorimetry = 0;
avi_cfg->db2_aspect_ratio = 0;
avi_cfg->db2_active_fmt_ar = 0;
avi_cfg->db3_itc = 0;
avi_cfg->db3_ec = 0;
avi_cfg->db3_q_range = 0;
avi_cfg->db3_nup_scaling = 0;
avi_cfg->db4_videocode = 0;
avi_cfg->db5_pixel_repeat = 0;
avi_cfg->db6_7_line_eoftop = 0 ;
avi_cfg->db8_9_line_sofbottom = 0;
avi_cfg->db10_11_pixel_eofleft = 0;
avi_cfg->db12_13_pixel_sofright = 0;
repeat_cfg->audio_pkt = 0;
repeat_cfg->audio_pkt_repeat = 0;
repeat_cfg->avi_infoframe = 0;
repeat_cfg->avi_infoframe_repeat = 0;
repeat_cfg->gen_cntrl_pkt = 0;
repeat_cfg->gen_cntrl_pkt_repeat = 0;
repeat_cfg->generic_pkt = 0;
repeat_cfg->generic_pkt_repeat = 0;
}
static void hdmi_core_powerdown_disable(void)
{
DSSDBG("Enter hdmi_core_powerdown_disable\n");
REG_FLD_MOD(HDMI_CORE_CTRL1, 0x0, 0, 0);
}
static void hdmi_core_swreset_release(void)
{
DSSDBG("Enter hdmi_core_swreset_release\n");
REG_FLD_MOD(HDMI_CORE_SYS_SRST, 0x0, 0, 0);
}
static void hdmi_core_swreset_assert(void)
{
DSSDBG("Enter hdmi_core_swreset_assert\n");
REG_FLD_MOD(HDMI_CORE_SYS_SRST, 0x1, 0, 0);
}
static void hdmi_core_video_config(struct hdmi_core_video_config *cfg)
{
u32 r = 0;
r = hdmi_read_reg(HDMI_CORE_CTRL1);
r = FLD_MOD(r, HDMI_CORE_CTRL1_VEN_FOLLOWVSYNC, 5, 5);
r = FLD_MOD(r, HDMI_CORE_CTRL1_HEN_FOLLOWHSYNC, 4, 4);
r = FLD_MOD(r, HDMI_CORE_CTRL1_BSEL_24BITBUS, 2, 2);
r = FLD_MOD(r, HDMI_CORE_CTRL1_EDGE_RISINGEDGE, 1, 1);
hdmi_write_reg(HDMI_CORE_CTRL1, r);
REG_FLD_MOD(HDMI_CORE_SYS_VID_ACEN, cfg->ip_bus_width, 7, 6);
r = hdmi_read_reg(HDMI_CORE_SYS_VID_MODE);
if (cfg->op_dither_truc > HDMI_OUTPUTTRUNCATION_12BIT) {
r = FLD_MOD(r, cfg->op_dither_truc - 3, 7, 6);
r = FLD_MOD(r, 1, 5, 5);
} else {
r = FLD_MOD(r, cfg->op_dither_truc, 7, 6);
r = FLD_MOD(r, 0, 5, 5);
}
hdmi_write_reg(HDMI_CORE_SYS_VID_MODE, r);
r = hdmi_read_reg(HDMI_CORE_AV_HDMI_CTRL);
r = FLD_MOD(r, cfg->deep_color_pkt, 6, 6);
r = FLD_MOD(r, cfg->pkt_mode, 5, 3);
r = FLD_MOD(r, cfg->hdmi_dvi, 0, 0);
hdmi_write_reg(HDMI_CORE_AV_HDMI_CTRL, r);
REG_FLD_MOD(HDMI_CORE_SYS_TMDS_CTRL,
cfg->tclk_sel_clkmult, 6, 5);
}
static void hdmi_core_aux_infoframe_avi_config(
struct hdmi_core_infoframe_avi info_avi)
{
u32 val;
char sum = 0, checksum = 0;
sum += 0x82 + 0x002 + 0x00D;
hdmi_write_reg(HDMI_CORE_AV_AVI_TYPE, 0x082);
hdmi_write_reg(HDMI_CORE_AV_AVI_VERS, 0x002);
hdmi_write_reg(HDMI_CORE_AV_AVI_LEN, 0x00D);
val = (info_avi.db1_format << 5) |
(info_avi.db1_active_info << 4) |
(info_avi.db1_bar_info_dv << 2) |
(info_avi.db1_scan_info);
hdmi_write_reg(HDMI_CORE_AV_AVI_DBYTE(0), val);
sum += val;
val = (info_avi.db2_colorimetry << 6) |
(info_avi.db2_aspect_ratio << 4) |
(info_avi.db2_active_fmt_ar);
hdmi_write_reg(HDMI_CORE_AV_AVI_DBYTE(1), val);
sum += val;
val = (info_avi.db3_itc << 7) |
(info_avi.db3_ec << 4) |
(info_avi.db3_q_range << 2) |
(info_avi.db3_nup_scaling);
hdmi_write_reg(HDMI_CORE_AV_AVI_DBYTE(2), val);
sum += val;
hdmi_write_reg(HDMI_CORE_AV_AVI_DBYTE(3), info_avi.db4_videocode);
sum += info_avi.db4_videocode;
val = info_avi.db5_pixel_repeat;
hdmi_write_reg(HDMI_CORE_AV_AVI_DBYTE(4), val);
sum += val;
val = info_avi.db6_7_line_eoftop & 0x00FF;
hdmi_write_reg(HDMI_CORE_AV_AVI_DBYTE(5), val);
sum += val;
val = ((info_avi.db6_7_line_eoftop >> 8) & 0x00FF);
hdmi_write_reg(HDMI_CORE_AV_AVI_DBYTE(6), val);
sum += val;
val = info_avi.db8_9_line_sofbottom & 0x00FF;
hdmi_write_reg(HDMI_CORE_AV_AVI_DBYTE(7), val);
sum += val;
val = ((info_avi.db8_9_line_sofbottom >> 8) & 0x00FF);
hdmi_write_reg(HDMI_CORE_AV_AVI_DBYTE(8), val);
sum += val;
val = info_avi.db10_11_pixel_eofleft & 0x00FF;
hdmi_write_reg(HDMI_CORE_AV_AVI_DBYTE(9), val);
sum += val;
val = ((info_avi.db10_11_pixel_eofleft >> 8) & 0x00FF);
hdmi_write_reg(HDMI_CORE_AV_AVI_DBYTE(10), val);
sum += val;
val = info_avi.db12_13_pixel_sofright & 0x00FF;
hdmi_write_reg(HDMI_CORE_AV_AVI_DBYTE(11), val);
sum += val;
val = ((info_avi.db12_13_pixel_sofright >> 8) & 0x00FF);
hdmi_write_reg(HDMI_CORE_AV_AVI_DBYTE(12), val);
sum += val;
checksum = 0x100 - sum;
hdmi_write_reg(HDMI_CORE_AV_AVI_CHSUM, checksum);
}
static void hdmi_core_av_packet_config(
struct hdmi_core_packet_enable_repeat repeat_cfg)
{
hdmi_write_reg(HDMI_CORE_AV_PB_CTRL1,
(repeat_cfg.audio_pkt << 5) |
(repeat_cfg.audio_pkt_repeat << 4) |
(repeat_cfg.avi_infoframe << 1) |
(repeat_cfg.avi_infoframe_repeat));
hdmi_write_reg(HDMI_CORE_AV_PB_CTRL2,
(repeat_cfg.gen_cntrl_pkt << 3) |
(repeat_cfg.gen_cntrl_pkt_repeat << 2) |
(repeat_cfg.generic_pkt << 1) |
(repeat_cfg.generic_pkt_repeat));
}
static void hdmi_wp_init(struct omap_video_timings *timings,
struct hdmi_video_format *video_fmt,
struct hdmi_video_interface *video_int)
{
DSSDBG("Enter hdmi_wp_init\n");
timings->hbp = 0;
timings->hfp = 0;
timings->hsw = 0;
timings->vbp = 0;
timings->vfp = 0;
timings->vsw = 0;
video_fmt->packing_mode = HDMI_PACK_10b_RGB_YUV444;
video_fmt->y_res = 0;
video_fmt->x_res = 0;
video_int->vsp = 0;
video_int->hsp = 0;
video_int->interlacing = 0;
video_int->tm = 0;
}
static void hdmi_wp_video_start(bool start)
{
REG_FLD_MOD(HDMI_WP_VIDEO_CFG, start, 31, 31);
}
static void hdmi_wp_video_init_format(struct hdmi_video_format *video_fmt,
struct omap_video_timings *timings, struct hdmi_config *param)
{
DSSDBG("Enter hdmi_wp_video_init_format\n");
video_fmt->y_res = param->timings.timings.y_res;
video_fmt->x_res = param->timings.timings.x_res;
timings->hbp = param->timings.timings.hbp;
timings->hfp = param->timings.timings.hfp;
timings->hsw = param->timings.timings.hsw;
timings->vbp = param->timings.timings.vbp;
timings->vfp = param->timings.timings.vfp;
timings->vsw = param->timings.timings.vsw;
}
static void hdmi_wp_video_config_format(
struct hdmi_video_format *video_fmt)
{
u32 l = 0;
REG_FLD_MOD(HDMI_WP_VIDEO_CFG, video_fmt->packing_mode, 10, 8);
l |= FLD_VAL(video_fmt->y_res, 31, 16);
l |= FLD_VAL(video_fmt->x_res, 15, 0);
hdmi_write_reg(HDMI_WP_VIDEO_SIZE, l);
}
static void hdmi_wp_video_config_interface(
struct hdmi_video_interface *video_int)
{
u32 r;
DSSDBG("Enter hdmi_wp_video_config_interface\n");
r = hdmi_read_reg(HDMI_WP_VIDEO_CFG);
r = FLD_MOD(r, video_int->vsp, 7, 7);
r = FLD_MOD(r, video_int->hsp, 6, 6);
r = FLD_MOD(r, video_int->interlacing, 3, 3);
r = FLD_MOD(r, video_int->tm, 1, 0);
hdmi_write_reg(HDMI_WP_VIDEO_CFG, r);
}
static void hdmi_wp_video_config_timing(
struct omap_video_timings *timings)
{
u32 timing_h = 0;
u32 timing_v = 0;
DSSDBG("Enter hdmi_wp_video_config_timing\n");
timing_h |= FLD_VAL(timings->hbp, 31, 20);
timing_h |= FLD_VAL(timings->hfp, 19, 8);
timing_h |= FLD_VAL(timings->hsw, 7, 0);
hdmi_write_reg(HDMI_WP_VIDEO_TIMING_H, timing_h);
timing_v |= FLD_VAL(timings->vbp, 31, 20);
timing_v |= FLD_VAL(timings->vfp, 19, 8);
timing_v |= FLD_VAL(timings->vsw, 7, 0);
hdmi_write_reg(HDMI_WP_VIDEO_TIMING_V, timing_v);
}
static void hdmi_basic_configure(struct hdmi_config *cfg)
{
struct omap_video_timings video_timing;
struct hdmi_video_format video_format;
struct hdmi_video_interface video_interface;
struct hdmi_core_infoframe_avi avi_cfg;
struct hdmi_core_video_config v_core_cfg;
struct hdmi_core_packet_enable_repeat repeat_cfg;
hdmi_wp_init(&video_timing, &video_format,
&video_interface);
hdmi_core_init(&v_core_cfg,
&avi_cfg,
&repeat_cfg);
hdmi_wp_video_init_format(&video_format,
&video_timing, cfg);
hdmi_wp_video_config_timing(&video_timing);
video_format.packing_mode = HDMI_PACK_24b_RGB_YUV444_YUV422;
hdmi_wp_video_config_format(&video_format);
video_interface.vsp = cfg->timings.vsync_pol;
video_interface.hsp = cfg->timings.hsync_pol;
video_interface.interlacing = cfg->interlace;
video_interface.tm = 1 ;
hdmi_wp_video_config_interface(&video_interface);
hdmi_core_swreset_assert();
hdmi_core_powerdown_disable();
v_core_cfg.pkt_mode = HDMI_PACKETMODE24BITPERPIXEL;
v_core_cfg.hdmi_dvi = cfg->cm.mode;
hdmi_core_video_config(&v_core_cfg);
hdmi_core_swreset_release();
avi_cfg.db1_format = HDMI_INFOFRAME_AVI_DB1Y_RGB;
avi_cfg.db1_active_info =
HDMI_INFOFRAME_AVI_DB1A_ACTIVE_FORMAT_OFF;
avi_cfg.db1_bar_info_dv = HDMI_INFOFRAME_AVI_DB1B_NO;
avi_cfg.db1_scan_info = HDMI_INFOFRAME_AVI_DB1S_0;
avi_cfg.db2_colorimetry = HDMI_INFOFRAME_AVI_DB2C_NO;
avi_cfg.db2_aspect_ratio = HDMI_INFOFRAME_AVI_DB2M_NO;
avi_cfg.db2_active_fmt_ar = HDMI_INFOFRAME_AVI_DB2R_SAME;
avi_cfg.db3_itc = HDMI_INFOFRAME_AVI_DB3ITC_NO;
avi_cfg.db3_ec = HDMI_INFOFRAME_AVI_DB3EC_XVYUV601;
avi_cfg.db3_q_range = HDMI_INFOFRAME_AVI_DB3Q_DEFAULT;
avi_cfg.db3_nup_scaling = HDMI_INFOFRAME_AVI_DB3SC_NO;
avi_cfg.db4_videocode = cfg->cm.code;
avi_cfg.db5_pixel_repeat = HDMI_INFOFRAME_AVI_DB5PR_NO;
avi_cfg.db6_7_line_eoftop = 0;
avi_cfg.db8_9_line_sofbottom = 0;
avi_cfg.db10_11_pixel_eofleft = 0;
avi_cfg.db12_13_pixel_sofright = 0;
hdmi_core_aux_infoframe_avi_config(avi_cfg);
repeat_cfg.avi_infoframe = HDMI_PACKETENABLE;
repeat_cfg.avi_infoframe_repeat = HDMI_PACKETREPEATON;
repeat_cfg.audio_pkt = HDMI_PACKETENABLE;
repeat_cfg.audio_pkt_repeat = HDMI_PACKETREPEATON;
hdmi_core_av_packet_config(repeat_cfg);
}
static void update_hdmi_timings(struct hdmi_config *cfg,
struct omap_video_timings *timings, int code)
{
cfg->timings.timings.x_res = timings->x_res;
cfg->timings.timings.y_res = timings->y_res;
cfg->timings.timings.hbp = timings->hbp;
cfg->timings.timings.hfp = timings->hfp;
cfg->timings.timings.hsw = timings->hsw;
cfg->timings.timings.vbp = timings->vbp;
cfg->timings.timings.vfp = timings->vfp;
cfg->timings.timings.vsw = timings->vsw;
cfg->timings.timings.pixel_clock = timings->pixel_clock;
cfg->timings.vsync_pol = cea_vesa_timings[code].vsync_pol;
cfg->timings.hsync_pol = cea_vesa_timings[code].hsync_pol;
}
static void hdmi_compute_pll(struct omap_dss_device *dssdev, int phy,
struct hdmi_pll_info *pi)
{
unsigned long clkin, refclk;
u32 mf;
clkin = dss_clk_get_rate(DSS_CLK_SYSCK) / 10000;
pi->regn = dssdev->clocks.hdmi.regn;
refclk = clkin / (pi->regn + 1);
pi->regm = (phy * 100 / (refclk)) / 100;
pi->regm2 = dssdev->clocks.hdmi.regm2;
mf = (phy - pi->regm * refclk) * 262144;
pi->regmf = mf / (refclk);
pi->dcofreq = phy > 1000 * 100;
pi->regsd = ((pi->regm * clkin / 10) / ((pi->regn + 1) * 250) + 5) / 10;
DSSDBG("M = %d Mf = %d\n", pi->regm, pi->regmf);
DSSDBG("range = %d sd = %d\n", pi->dcofreq, pi->regsd);
}
static void hdmi_enable_clocks(int enable)
{
if (enable)
dss_clk_enable(DSS_CLK_ICK | DSS_CLK_FCK |
DSS_CLK_SYSCK | DSS_CLK_VIDFCK);
else
dss_clk_disable(DSS_CLK_ICK | DSS_CLK_FCK |
DSS_CLK_SYSCK | DSS_CLK_VIDFCK);
}
static int hdmi_power_on(struct omap_dss_device *dssdev)
{
int r, code = 0;
struct hdmi_pll_info pll_data;
struct omap_video_timings *p;
unsigned long phy;
hdmi_enable_clocks(1);
dispc_enable_channel(OMAP_DSS_CHANNEL_DIGIT, 0);
p = &dssdev->panel.timings;
DSSDBG("hdmi_power_on x_res= %d y_res = %d\n",
dssdev->panel.timings.x_res,
dssdev->panel.timings.y_res);
if (!hdmi.custom_set) {
DSSDBG("Read EDID as no EDID is not set on poweron\n");
hdmi_read_edid(p);
}
code = get_timings_index();
dssdev->panel.timings = cea_vesa_timings[code].timings;
update_hdmi_timings(&hdmi.cfg, p, code);
phy = p->pixel_clock;
hdmi_compute_pll(dssdev, phy, &pll_data);
hdmi_wp_video_start(0);
r = hdmi_pll_program(&pll_data);
if (r) {
DSSDBG("Failed to lock PLL\n");
goto err;
}
r = hdmi_phy_init();
if (r) {
DSSDBG("Failed to start PHY\n");
goto err;
}
hdmi.cfg.cm.mode = hdmi.mode;
hdmi.cfg.cm.code = hdmi.code;
hdmi_basic_configure(&hdmi.cfg);
dss_select_hdmi_venc_clk_source(DSS_HDMI_M_PCLK);
dss_select_dispc_clk_source(dssdev->clocks.dispc.dispc_fclk_src);
dispc_enable_gamma_table(0);
dispc_set_digit_size(dssdev->panel.timings.x_res,
dssdev->panel.timings.y_res);
dispc_enable_channel(OMAP_DSS_CHANNEL_DIGIT, 1);
hdmi_wp_video_start(1);
return 0;
err:
hdmi_enable_clocks(0);
return -EIO;
}
static void hdmi_power_off(struct omap_dss_device *dssdev)
{
dispc_enable_channel(OMAP_DSS_CHANNEL_DIGIT, 0);
hdmi_wp_video_start(0);
hdmi_phy_off();
hdmi_set_pll_pwr(HDMI_PLLPWRCMD_ALLOFF);
hdmi_enable_clocks(0);
hdmi.edid_set = 0;
}
int omapdss_hdmi_display_check_timing(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct hdmi_cm cm;
cm = hdmi_get_code(timings);
if (cm.code == -1) {
DSSERR("Invalid timing entered\n");
return -EINVAL;
}
return 0;
}
void omapdss_hdmi_display_set_timing(struct omap_dss_device *dssdev)
{
struct hdmi_cm cm;
hdmi.custom_set = 1;
cm = hdmi_get_code(&dssdev->panel.timings);
hdmi.code = cm.code;
hdmi.mode = cm.mode;
omapdss_hdmi_display_enable(dssdev);
hdmi.custom_set = 0;
}
int omapdss_hdmi_display_enable(struct omap_dss_device *dssdev)
{
int r = 0;
DSSDBG("ENTER hdmi_display_enable\n");
mutex_lock(&hdmi.lock);
r = omap_dss_start_device(dssdev);
if (r) {
DSSERR("failed to start device\n");
goto err0;
}
if (dssdev->platform_enable) {
r = dssdev->platform_enable(dssdev);
if (r) {
DSSERR("failed to enable GPIO's\n");
goto err1;
}
}
r = hdmi_power_on(dssdev);
if (r) {
DSSERR("failed to power on device\n");
goto err2;
}
mutex_unlock(&hdmi.lock);
return 0;
err2:
if (dssdev->platform_disable)
dssdev->platform_disable(dssdev);
err1:
omap_dss_stop_device(dssdev);
err0:
mutex_unlock(&hdmi.lock);
return r;
}
void omapdss_hdmi_display_disable(struct omap_dss_device *dssdev)
{
DSSDBG("Enter hdmi_display_disable\n");
mutex_lock(&hdmi.lock);
hdmi_power_off(dssdev);
if (dssdev->platform_disable)
dssdev->platform_disable(dssdev);
omap_dss_stop_device(dssdev);
mutex_unlock(&hdmi.lock);
}
static void hdmi_wp_audio_config_format(
struct hdmi_audio_format *aud_fmt)
{
u32 r;
DSSDBG("Enter hdmi_wp_audio_config_format\n");
r = hdmi_read_reg(HDMI_WP_AUDIO_CFG);
r = FLD_MOD(r, aud_fmt->stereo_channels, 26, 24);
r = FLD_MOD(r, aud_fmt->active_chnnls_msk, 23, 16);
r = FLD_MOD(r, aud_fmt->en_sig_blk_strt_end, 5, 5);
r = FLD_MOD(r, aud_fmt->type, 4, 4);
r = FLD_MOD(r, aud_fmt->justification, 3, 3);
r = FLD_MOD(r, aud_fmt->sample_order, 2, 2);
r = FLD_MOD(r, aud_fmt->samples_per_word, 1, 1);
r = FLD_MOD(r, aud_fmt->sample_size, 0, 0);
hdmi_write_reg(HDMI_WP_AUDIO_CFG, r);
}
static void hdmi_wp_audio_config_dma(struct hdmi_audio_dma *aud_dma)
{
u32 r;
DSSDBG("Enter hdmi_wp_audio_config_dma\n");
r = hdmi_read_reg(HDMI_WP_AUDIO_CFG2);
r = FLD_MOD(r, aud_dma->transfer_size, 15, 8);
r = FLD_MOD(r, aud_dma->block_size, 7, 0);
hdmi_write_reg(HDMI_WP_AUDIO_CFG2, r);
r = hdmi_read_reg(HDMI_WP_AUDIO_CTRL);
r = FLD_MOD(r, aud_dma->mode, 9, 9);
r = FLD_MOD(r, aud_dma->fifo_threshold, 8, 0);
hdmi_write_reg(HDMI_WP_AUDIO_CTRL, r);
}
static void hdmi_core_audio_config(struct hdmi_core_audio_config *cfg)
{
u32 r;
r = hdmi_read_reg(HDMI_CORE_AV_ACR_CTRL);
r = FLD_MOD(r, cfg->use_mclk, 2, 2);
r = FLD_MOD(r, cfg->en_acr_pkt, 1, 1);
r = FLD_MOD(r, cfg->cts_mode, 0, 0);
hdmi_write_reg(HDMI_CORE_AV_ACR_CTRL, r);
REG_FLD_MOD(HDMI_CORE_AV_N_SVAL1, cfg->n, 7, 0);
REG_FLD_MOD(HDMI_CORE_AV_N_SVAL2, cfg->n >> 8, 7, 0);
REG_FLD_MOD(HDMI_CORE_AV_N_SVAL3, cfg->n >> 16, 7, 0);
if (cfg->cts_mode == HDMI_AUDIO_CTS_MODE_SW) {
REG_FLD_MOD(HDMI_CORE_AV_CTS_SVAL1, cfg->cts, 7, 0);
REG_FLD_MOD(HDMI_CORE_AV_CTS_SVAL2, cfg->cts >> 8, 7, 0);
REG_FLD_MOD(HDMI_CORE_AV_CTS_SVAL3, cfg->cts >> 16, 7, 0);
} else {
REG_FLD_MOD(HDMI_CORE_AV_FREQ_SVAL, cfg->mclk_mode, 2, 0);
REG_FLD_MOD(HDMI_CORE_AV_AUD_PAR_BUSCLK_1,
cfg->aud_par_busclk, 7, 0);
REG_FLD_MOD(HDMI_CORE_AV_AUD_PAR_BUSCLK_2,
(cfg->aud_par_busclk >> 8), 7, 0);
REG_FLD_MOD(HDMI_CORE_AV_AUD_PAR_BUSCLK_3,
(cfg->aud_par_busclk >> 16), 7, 0);
}
REG_FLD_MOD(HDMI_CORE_AV_SPDIF_CTRL, cfg->fs_override, 1, 1);
REG_FLD_MOD(HDMI_CORE_AV_I2S_CHST4, cfg->freq_sample, 3, 0);
r = hdmi_read_reg(HDMI_CORE_AV_I2S_IN_CTRL);
r = FLD_MOD(r, cfg->i2s_cfg.en_high_bitrate_aud, 7, 7);
r = FLD_MOD(r, cfg->i2s_cfg.sck_edge_mode, 6, 6);
r = FLD_MOD(r, cfg->i2s_cfg.cbit_order, 5, 5);
r = FLD_MOD(r, cfg->i2s_cfg.vbit, 4, 4);
r = FLD_MOD(r, cfg->i2s_cfg.ws_polarity, 3, 3);
r = FLD_MOD(r, cfg->i2s_cfg.justification, 2, 2);
r = FLD_MOD(r, cfg->i2s_cfg.direction, 1, 1);
r = FLD_MOD(r, cfg->i2s_cfg.shift, 0, 0);
hdmi_write_reg(HDMI_CORE_AV_I2S_IN_CTRL, r);
r = hdmi_read_reg(HDMI_CORE_AV_I2S_CHST5);
r = FLD_MOD(r, cfg->freq_sample, 7, 4);
r = FLD_MOD(r, cfg->i2s_cfg.word_length, 3, 1);
r = FLD_MOD(r, cfg->i2s_cfg.word_max_length, 0, 0);
hdmi_write_reg(HDMI_CORE_AV_I2S_CHST5, r);
REG_FLD_MOD(HDMI_CORE_AV_I2S_IN_LEN, cfg->i2s_cfg.in_length_bits, 3, 0);
REG_FLD_MOD(HDMI_CORE_AV_HDMI_CTRL, cfg->layout, 2, 1);
r = hdmi_read_reg(HDMI_CORE_AV_AUD_MODE);
r = FLD_MOD(r, cfg->i2s_cfg.active_sds, 7, 4);
r = FLD_MOD(r, cfg->en_dsd_audio, 3, 3);
r = FLD_MOD(r, cfg->en_parallel_aud_input, 2, 2);
r = FLD_MOD(r, cfg->en_spdif, 1, 1);
hdmi_write_reg(HDMI_CORE_AV_AUD_MODE, r);
}
static void hdmi_core_audio_infoframe_config(
struct hdmi_core_infoframe_audio *info_aud)
{
u8 val;
u8 sum = 0, checksum = 0;
hdmi_write_reg(HDMI_CORE_AV_AUDIO_TYPE, 0x84);
hdmi_write_reg(HDMI_CORE_AV_AUDIO_VERS, 0x01);
hdmi_write_reg(HDMI_CORE_AV_AUDIO_LEN, 0x0a);
sum += 0x84 + 0x001 + 0x00a;
val = (info_aud->db1_coding_type << 4)
| (info_aud->db1_channel_count - 1);
hdmi_write_reg(HDMI_CORE_AV_AUD_DBYTE(0), val);
sum += val;
val = (info_aud->db2_sample_freq << 2) | info_aud->db2_sample_size;
hdmi_write_reg(HDMI_CORE_AV_AUD_DBYTE(1), val);
sum += val;
hdmi_write_reg(HDMI_CORE_AV_AUD_DBYTE(2), 0x00);
val = info_aud->db4_channel_alloc;
hdmi_write_reg(HDMI_CORE_AV_AUD_DBYTE(3), val);
sum += val;
val = (info_aud->db5_downmix_inh << 7) | (info_aud->db5_lsv << 3);
hdmi_write_reg(HDMI_CORE_AV_AUD_DBYTE(4), val);
sum += val;
hdmi_write_reg(HDMI_CORE_AV_AUD_DBYTE(5), 0x00);
hdmi_write_reg(HDMI_CORE_AV_AUD_DBYTE(6), 0x00);
hdmi_write_reg(HDMI_CORE_AV_AUD_DBYTE(7), 0x00);
hdmi_write_reg(HDMI_CORE_AV_AUD_DBYTE(8), 0x00);
hdmi_write_reg(HDMI_CORE_AV_AUD_DBYTE(9), 0x00);
checksum = 0x100 - sum;
hdmi_write_reg(HDMI_CORE_AV_AUDIO_CHSUM, checksum);
}
static int hdmi_config_audio_acr(u32 sample_freq, u32 *n, u32 *cts)
{
u32 r;
u32 deep_color = 0;
u32 pclk = hdmi.cfg.timings.timings.pixel_clock;
if (n == NULL || cts == NULL)
return -EINVAL;
r = REG_GET(HDMI_WP_VIDEO_CFG, 1, 0);
switch (r) {
case 1:
deep_color = 100;
break;
case 2:
deep_color = 125;
break;
case 3:
deep_color = 150;
break;
default:
return -EINVAL;
}
switch (sample_freq) {
case 32000:
if ((deep_color == 125) && ((pclk == 54054)
|| (pclk == 74250)))
*n = 8192;
else
*n = 4096;
break;
case 44100:
*n = 6272;
break;
case 48000:
if ((deep_color == 125) && ((pclk == 54054)
|| (pclk == 74250)))
*n = 8192;
else
*n = 6144;
break;
default:
*n = 0;
return -EINVAL;
}
*cts = pclk * (*n / 128) * deep_color / (sample_freq / 10);
return 0;
}
static int hdmi_audio_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct hdmi_audio_format audio_format;
struct hdmi_audio_dma audio_dma;
struct hdmi_core_audio_config core_cfg;
struct hdmi_core_infoframe_audio aud_if_cfg;
int err, n, cts;
enum hdmi_core_audio_sample_freq sample_freq;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
core_cfg.i2s_cfg.word_max_length =
HDMI_AUDIO_I2S_MAX_WORD_20BITS;
core_cfg.i2s_cfg.word_length = HDMI_AUDIO_I2S_CHST_WORD_16_BITS;
core_cfg.i2s_cfg.in_length_bits =
HDMI_AUDIO_I2S_INPUT_LENGTH_16;
core_cfg.i2s_cfg.justification = HDMI_AUDIO_JUSTIFY_LEFT;
audio_format.samples_per_word = HDMI_AUDIO_ONEWORD_TWOSAMPLES;
audio_format.sample_size = HDMI_AUDIO_SAMPLE_16BITS;
audio_format.justification = HDMI_AUDIO_JUSTIFY_LEFT;
audio_dma.transfer_size = 0x10;
break;
case SNDRV_PCM_FORMAT_S24_LE:
core_cfg.i2s_cfg.word_max_length =
HDMI_AUDIO_I2S_MAX_WORD_24BITS;
core_cfg.i2s_cfg.word_length = HDMI_AUDIO_I2S_CHST_WORD_24_BITS;
core_cfg.i2s_cfg.in_length_bits =
HDMI_AUDIO_I2S_INPUT_LENGTH_24;
audio_format.samples_per_word = HDMI_AUDIO_ONEWORD_ONESAMPLE;
audio_format.sample_size = HDMI_AUDIO_SAMPLE_24BITS;
audio_format.justification = HDMI_AUDIO_JUSTIFY_RIGHT;
core_cfg.i2s_cfg.justification = HDMI_AUDIO_JUSTIFY_RIGHT;
audio_dma.transfer_size = 0x20;
break;
default:
return -EINVAL;
}
switch (params_rate(params)) {
case 32000:
sample_freq = HDMI_AUDIO_FS_32000;
break;
case 44100:
sample_freq = HDMI_AUDIO_FS_44100;
break;
case 48000:
sample_freq = HDMI_AUDIO_FS_48000;
break;
default:
return -EINVAL;
}
err = hdmi_config_audio_acr(params_rate(params), &n, &cts);
if (err < 0)
return err;
audio_format.stereo_channels = HDMI_AUDIO_STEREO_ONECHANNEL;
audio_format.active_chnnls_msk = 0x03;
audio_format.type = HDMI_AUDIO_TYPE_LPCM;
audio_format.sample_order = HDMI_AUDIO_SAMPLE_LEFT_FIRST;
audio_format.en_sig_blk_strt_end = HDMI_AUDIO_BLOCK_SIG_STARTEND_OFF;
audio_dma.block_size = 0xC0;
audio_dma.mode = HDMI_AUDIO_TRANSF_DMA;
audio_dma.fifo_threshold = 0x20;
hdmi_wp_audio_config_dma(&audio_dma);
hdmi_wp_audio_config_format(&audio_format);
core_cfg.i2s_cfg.en_high_bitrate_aud = false;
core_cfg.i2s_cfg.cbit_order = false;
core_cfg.i2s_cfg.sck_edge_mode = HDMI_AUDIO_I2S_SCK_EDGE_RISING;
core_cfg.i2s_cfg.vbit = HDMI_AUDIO_I2S_VBIT_FOR_PCM;
core_cfg.i2s_cfg.ws_polarity = HDMI_AUDIO_I2S_WS_POLARITY_LOW_IS_LEFT;
core_cfg.i2s_cfg.direction = HDMI_AUDIO_I2S_MSB_SHIFTED_FIRST;
core_cfg.i2s_cfg.shift = HDMI_AUDIO_I2S_FIRST_BIT_SHIFT;
core_cfg.i2s_cfg.active_sds = HDMI_AUDIO_I2S_SD0_EN;
core_cfg.freq_sample = sample_freq;
core_cfg.n = n;
core_cfg.cts = cts;
if (dss_has_feature(FEAT_HDMI_CTS_SWMODE)) {
core_cfg.aud_par_busclk = 0;
core_cfg.cts_mode = HDMI_AUDIO_CTS_MODE_SW;
core_cfg.use_mclk = false;
} else {
core_cfg.aud_par_busclk = (((128 * 31) - 1) << 8);
core_cfg.cts_mode = HDMI_AUDIO_CTS_MODE_HW;
core_cfg.use_mclk = true;
core_cfg.mclk_mode = HDMI_AUDIO_MCLK_128FS;
}
core_cfg.layout = HDMI_AUDIO_LAYOUT_2CH;
core_cfg.en_spdif = false;
core_cfg.fs_override = true;
core_cfg.en_acr_pkt = true;
core_cfg.en_dsd_audio = false;
core_cfg.en_parallel_aud_input = true;
hdmi_core_audio_config(&core_cfg);
aud_if_cfg.db1_coding_type = HDMI_INFOFRAME_AUDIO_DB1CT_FROM_STREAM;
aud_if_cfg.db1_channel_count = 2;
aud_if_cfg.db2_sample_freq = HDMI_INFOFRAME_AUDIO_DB2SF_FROM_STREAM;
aud_if_cfg.db2_sample_size = HDMI_INFOFRAME_AUDIO_DB2SS_FROM_STREAM;
aud_if_cfg.db4_channel_alloc = 0x00;
aud_if_cfg.db5_downmix_inh = false;
aud_if_cfg.db5_lsv = 0;
hdmi_core_audio_infoframe_config(&aud_if_cfg);
return 0;
}
static int hdmi_audio_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
int err = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
REG_FLD_MOD(HDMI_CORE_AV_AUD_MODE, 1, 0, 0);
REG_FLD_MOD(HDMI_WP_AUDIO_CTRL, 1, 31, 31);
REG_FLD_MOD(HDMI_WP_AUDIO_CTRL, 1, 30, 30);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
REG_FLD_MOD(HDMI_CORE_AV_AUD_MODE, 0, 0, 0);
REG_FLD_MOD(HDMI_WP_AUDIO_CTRL, 0, 30, 30);
REG_FLD_MOD(HDMI_WP_AUDIO_CTRL, 0, 31, 31);
break;
default:
err = -EINVAL;
}
return err;
}
static int hdmi_audio_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
if (!hdmi.mode) {
pr_err("Current video settings do not support audio.\n");
return -EIO;
}
return 0;
}
static int omapdss_hdmihw_probe(struct platform_device *pdev)
{
struct resource *hdmi_mem;
#if defined(CONFIG_SND_OMAP_SOC_OMAP4_HDMI) || \
defined(CONFIG_SND_OMAP_SOC_OMAP4_HDMI_MODULE)
int ret;
#endif
hdmi.pdata = pdev->dev.platform_data;
hdmi.pdev = pdev;
mutex_init(&hdmi.lock);
hdmi_mem = platform_get_resource(hdmi.pdev, IORESOURCE_MEM, 0);
if (!hdmi_mem) {
DSSERR("can't get IORESOURCE_MEM HDMI\n");
return -EINVAL;
}
hdmi.base_wp = ioremap(hdmi_mem->start, resource_size(hdmi_mem));
if (!hdmi.base_wp) {
DSSERR("can't ioremap WP\n");
return -ENOMEM;
}
hdmi_panel_init();
#if defined(CONFIG_SND_OMAP_SOC_OMAP4_HDMI) || \
defined(CONFIG_SND_OMAP_SOC_OMAP4_HDMI_MODULE)
ret = snd_soc_register_codec(&pdev->dev, &hdmi_audio_codec_drv,
&hdmi_codec_dai_drv, 1);
if (ret) {
DSSERR("can't register ASoC HDMI audio codec\n");
return ret;
}
#endif
return 0;
}
static int omapdss_hdmihw_remove(struct platform_device *pdev)
{
hdmi_panel_exit();
#if defined(CONFIG_SND_OMAP_SOC_OMAP4_HDMI) || \
defined(CONFIG_SND_OMAP_SOC_OMAP4_HDMI_MODULE)
snd_soc_unregister_codec(&pdev->dev);
#endif
iounmap(hdmi.base_wp);
return 0;
}
int hdmi_init_platform_driver(void)
{
return platform_driver_register(&omapdss_hdmihw_driver);
}
void hdmi_uninit_platform_driver(void)
{
return platform_driver_unregister(&omapdss_hdmihw_driver);
}
