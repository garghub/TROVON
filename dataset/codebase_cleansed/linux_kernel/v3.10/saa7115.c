static inline struct saa711x_state *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct saa711x_state, sd);
}
static inline struct v4l2_subdev *to_sd(struct v4l2_ctrl *ctrl)
{
return &container_of(ctrl->handler, struct saa711x_state, hdl)->sd;
}
static inline int saa711x_write(struct v4l2_subdev *sd, u8 reg, u8 value)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return i2c_smbus_write_byte_data(client, reg, value);
}
static int saa711x_has_reg(const int id, const u8 reg)
{
if (id == V4L2_IDENT_SAA7111)
return reg < 0x20 && reg != 0x01 && reg != 0x0f &&
(reg < 0x13 || reg > 0x19) && reg != 0x1d && reg != 0x1e;
if (id == V4L2_IDENT_SAA7111A)
return reg < 0x20 && reg != 0x01 && reg != 0x0f &&
reg != 0x14 && reg != 0x18 && reg != 0x19 &&
reg != 0x1d && reg != 0x1e;
if (unlikely((reg >= 0x3b && reg <= 0x3f) || reg == 0x5c || reg == 0x5f ||
reg == 0xa3 || reg == 0xa7 || reg == 0xab || reg == 0xaf || (reg >= 0xb5 && reg <= 0xb7) ||
reg == 0xd3 || reg == 0xd7 || reg == 0xdb || reg == 0xdf || (reg >= 0xe5 && reg <= 0xe7) ||
reg == 0x82 || (reg >= 0x89 && reg <= 0x8e)))
return 0;
switch (id) {
case V4L2_IDENT_SAA7113:
return reg != 0x14 && (reg < 0x18 || reg > 0x1e) && (reg < 0x20 || reg > 0x3f) &&
reg != 0x5d && reg < 0x63;
case V4L2_IDENT_SAA7114:
return (reg < 0x1a || reg > 0x1e) && (reg < 0x20 || reg > 0x2f) &&
(reg < 0x63 || reg > 0x7f) && reg != 0x33 && reg != 0x37 &&
reg != 0x81 && reg < 0xf0;
case V4L2_IDENT_SAA7115:
return (reg < 0x20 || reg > 0x2f) && reg != 0x65 && (reg < 0xfc || reg > 0xfe);
case V4L2_IDENT_SAA7118:
return (reg < 0x1a || reg > 0x1d) && (reg < 0x20 || reg > 0x22) &&
(reg < 0x26 || reg > 0x28) && reg != 0x33 && reg != 0x37 &&
(reg < 0x63 || reg > 0x7f) && reg != 0x81 && reg < 0xf0;
}
return 1;
}
static int saa711x_writeregs(struct v4l2_subdev *sd, const unsigned char *regs)
{
struct saa711x_state *state = to_state(sd);
unsigned char reg, data;
while (*regs != 0x00) {
reg = *(regs++);
data = *(regs++);
if (saa711x_has_reg(state->ident, reg)) {
if (saa711x_write(sd, reg, data) < 0)
return -1;
} else {
v4l2_dbg(1, debug, sd, "tried to access reserved reg 0x%02x\n", reg);
}
}
return 0;
}
static inline int saa711x_read(struct v4l2_subdev *sd, u8 reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return i2c_smbus_read_byte_data(client, reg);
}
static int saa711x_odd_parity(u8 c)
{
c ^= (c >> 4);
c ^= (c >> 2);
c ^= (c >> 1);
return c & 1;
}
static int saa711x_decode_vps(u8 *dst, u8 *p)
{
static const u8 biphase_tbl[] = {
0xf0, 0x78, 0x70, 0xf0, 0xb4, 0x3c, 0x34, 0xb4,
0xb0, 0x38, 0x30, 0xb0, 0xf0, 0x78, 0x70, 0xf0,
0xd2, 0x5a, 0x52, 0xd2, 0x96, 0x1e, 0x16, 0x96,
0x92, 0x1a, 0x12, 0x92, 0xd2, 0x5a, 0x52, 0xd2,
0xd0, 0x58, 0x50, 0xd0, 0x94, 0x1c, 0x14, 0x94,
0x90, 0x18, 0x10, 0x90, 0xd0, 0x58, 0x50, 0xd0,
0xf0, 0x78, 0x70, 0xf0, 0xb4, 0x3c, 0x34, 0xb4,
0xb0, 0x38, 0x30, 0xb0, 0xf0, 0x78, 0x70, 0xf0,
0xe1, 0x69, 0x61, 0xe1, 0xa5, 0x2d, 0x25, 0xa5,
0xa1, 0x29, 0x21, 0xa1, 0xe1, 0x69, 0x61, 0xe1,
0xc3, 0x4b, 0x43, 0xc3, 0x87, 0x0f, 0x07, 0x87,
0x83, 0x0b, 0x03, 0x83, 0xc3, 0x4b, 0x43, 0xc3,
0xc1, 0x49, 0x41, 0xc1, 0x85, 0x0d, 0x05, 0x85,
0x81, 0x09, 0x01, 0x81, 0xc1, 0x49, 0x41, 0xc1,
0xe1, 0x69, 0x61, 0xe1, 0xa5, 0x2d, 0x25, 0xa5,
0xa1, 0x29, 0x21, 0xa1, 0xe1, 0x69, 0x61, 0xe1,
0xe0, 0x68, 0x60, 0xe0, 0xa4, 0x2c, 0x24, 0xa4,
0xa0, 0x28, 0x20, 0xa0, 0xe0, 0x68, 0x60, 0xe0,
0xc2, 0x4a, 0x42, 0xc2, 0x86, 0x0e, 0x06, 0x86,
0x82, 0x0a, 0x02, 0x82, 0xc2, 0x4a, 0x42, 0xc2,
0xc0, 0x48, 0x40, 0xc0, 0x84, 0x0c, 0x04, 0x84,
0x80, 0x08, 0x00, 0x80, 0xc0, 0x48, 0x40, 0xc0,
0xe0, 0x68, 0x60, 0xe0, 0xa4, 0x2c, 0x24, 0xa4,
0xa0, 0x28, 0x20, 0xa0, 0xe0, 0x68, 0x60, 0xe0,
0xf0, 0x78, 0x70, 0xf0, 0xb4, 0x3c, 0x34, 0xb4,
0xb0, 0x38, 0x30, 0xb0, 0xf0, 0x78, 0x70, 0xf0,
0xd2, 0x5a, 0x52, 0xd2, 0x96, 0x1e, 0x16, 0x96,
0x92, 0x1a, 0x12, 0x92, 0xd2, 0x5a, 0x52, 0xd2,
0xd0, 0x58, 0x50, 0xd0, 0x94, 0x1c, 0x14, 0x94,
0x90, 0x18, 0x10, 0x90, 0xd0, 0x58, 0x50, 0xd0,
0xf0, 0x78, 0x70, 0xf0, 0xb4, 0x3c, 0x34, 0xb4,
0xb0, 0x38, 0x30, 0xb0, 0xf0, 0x78, 0x70, 0xf0,
};
int i;
u8 c, err = 0;
for (i = 0; i < 2 * 13; i += 2) {
err |= biphase_tbl[p[i]] | biphase_tbl[p[i + 1]];
c = (biphase_tbl[p[i + 1]] & 0xf) | ((biphase_tbl[p[i]] & 0xf) << 4);
dst[i / 2] = c;
}
return err & 0xf0;
}
static int saa711x_decode_wss(u8 *p)
{
static const int wss_bits[8] = {
0, 0, 0, 1, 0, 1, 1, 1
};
unsigned char parity;
int wss = 0;
int i;
for (i = 0; i < 16; i++) {
int b1 = wss_bits[p[i] & 7];
int b2 = wss_bits[(p[i] >> 3) & 7];
if (b1 == b2)
return -1;
wss |= b2 << i;
}
parity = wss & 15;
parity ^= parity >> 2;
parity ^= parity >> 1;
if (!(parity & 1))
return -1;
return wss;
}
static int saa711x_s_clock_freq(struct v4l2_subdev *sd, u32 freq)
{
struct saa711x_state *state = to_state(sd);
u32 acpf;
u32 acni;
u32 hz;
u64 f;
u8 acc = 0;
if (!saa711x_has_reg(state->ident, R_30_AUD_MAST_CLK_CYCLES_PER_FIELD))
return 0;
v4l2_dbg(1, debug, sd, "set audio clock freq: %d\n", freq);
if (freq < 32000 || freq > 48000)
return -EINVAL;
hz = (state->std & V4L2_STD_525_60) ? 5994 : 5000;
acpf = (25600 * freq) / hz;
f = freq;
f = f << 31;
do_div(f, state->crystal_freq);
acni = f;
if (state->ucgc) {
acpf = acpf * state->cgcdiv / 16;
acni = acni * state->cgcdiv / 16;
acc = 0x80;
if (state->cgcdiv == 3)
acc |= 0x40;
}
if (state->apll)
acc |= 0x08;
if (state->double_asclk) {
acpf <<= 1;
acni <<= 1;
}
saa711x_write(sd, R_38_CLK_RATIO_AMXCLK_TO_ASCLK, 0x03);
saa711x_write(sd, R_39_CLK_RATIO_ASCLK_TO_ALRCLK, 0x10 << state->double_asclk);
saa711x_write(sd, R_3A_AUD_CLK_GEN_BASIC_SETUP, acc);
saa711x_write(sd, R_30_AUD_MAST_CLK_CYCLES_PER_FIELD, acpf & 0xff);
saa711x_write(sd, R_30_AUD_MAST_CLK_CYCLES_PER_FIELD+1,
(acpf >> 8) & 0xff);
saa711x_write(sd, R_30_AUD_MAST_CLK_CYCLES_PER_FIELD+2,
(acpf >> 16) & 0x03);
saa711x_write(sd, R_34_AUD_MAST_CLK_NOMINAL_INC, acni & 0xff);
saa711x_write(sd, R_34_AUD_MAST_CLK_NOMINAL_INC+1, (acni >> 8) & 0xff);
saa711x_write(sd, R_34_AUD_MAST_CLK_NOMINAL_INC+2, (acni >> 16) & 0x3f);
state->audclk_freq = freq;
return 0;
}
static int saa711x_g_volatile_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
struct saa711x_state *state = to_state(sd);
switch (ctrl->id) {
case V4L2_CID_CHROMA_AGC:
if (state->agc->val)
state->gain->val =
saa711x_read(sd, R_0F_CHROMA_GAIN_CNTL) & 0x7f;
break;
}
return 0;
}
static int saa711x_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
struct saa711x_state *state = to_state(sd);
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
saa711x_write(sd, R_0A_LUMA_BRIGHT_CNTL, ctrl->val);
break;
case V4L2_CID_CONTRAST:
saa711x_write(sd, R_0B_LUMA_CONTRAST_CNTL, ctrl->val);
break;
case V4L2_CID_SATURATION:
saa711x_write(sd, R_0C_CHROMA_SAT_CNTL, ctrl->val);
break;
case V4L2_CID_HUE:
saa711x_write(sd, R_0D_CHROMA_HUE_CNTL, ctrl->val);
break;
case V4L2_CID_CHROMA_AGC:
if (state->agc->val)
saa711x_write(sd, R_0F_CHROMA_GAIN_CNTL, state->gain->val);
else
saa711x_write(sd, R_0F_CHROMA_GAIN_CNTL, state->gain->val | 0x80);
break;
default:
return -EINVAL;
}
return 0;
}
static int saa711x_set_size(struct v4l2_subdev *sd, int width, int height)
{
struct saa711x_state *state = to_state(sd);
int HPSC, HFSC;
int VSCY;
int res;
int is_50hz = state->std & V4L2_STD_625_50;
int Vsrc = is_50hz ? 576 : 480;
v4l2_dbg(1, debug, sd, "decoder set size to %ix%i\n", width, height);
if ((width < 1) || (width > 1440))
return -EINVAL;
if ((height < 1) || (height > Vsrc))
return -EINVAL;
if (!saa711x_has_reg(state->ident, R_D0_B_HORIZ_PRESCALING)) {
if (width != 720)
return -EINVAL;
if (height != Vsrc)
return -EINVAL;
}
state->width = width;
state->height = height;
if (!saa711x_has_reg(state->ident, R_CC_B_HORIZ_OUTPUT_WINDOW_LENGTH))
return 0;
saa711x_write(sd, R_CC_B_HORIZ_OUTPUT_WINDOW_LENGTH,
(u8) (width & 0xff));
saa711x_write(sd, R_CD_B_HORIZ_OUTPUT_WINDOW_LENGTH_MSB,
(u8) ((width >> 8) & 0xff));
res = height / 2;
if (!is_50hz)
res += (VRES_60HZ - 480) >> 1;
saa711x_write(sd, R_CE_B_VERT_OUTPUT_WINDOW_LENGTH,
(u8) (res & 0xff));
saa711x_write(sd, R_CF_B_VERT_OUTPUT_WINDOW_LENGTH_MSB,
(u8) ((res >> 8) & 0xff));
HPSC = (int)(720 / width);
HPSC = HPSC ? HPSC : 1;
HFSC = (int)((1024 * 720) / (HPSC * width));
saa711x_write(sd, R_D0_B_HORIZ_PRESCALING,
(u8) (HPSC & 0x3f));
v4l2_dbg(1, debug, sd, "Hpsc: 0x%05x, Hfsc: 0x%05x\n", HPSC, HFSC);
saa711x_write(sd, R_D8_B_HORIZ_LUMA_SCALING_INC,
(u8) (HFSC & 0xff));
saa711x_write(sd, R_D9_B_HORIZ_LUMA_SCALING_INC_MSB,
(u8) ((HFSC >> 8) & 0xff));
saa711x_write(sd, R_DC_B_HORIZ_CHROMA_SCALING,
(u8) ((HFSC >> 1) & 0xff));
saa711x_write(sd, R_DD_B_HORIZ_CHROMA_SCALING_MSB,
(u8) ((HFSC >> 9) & 0xff));
VSCY = (int)((1024 * Vsrc) / height);
v4l2_dbg(1, debug, sd, "Vsrc: %d, Vscy: 0x%05x\n", Vsrc, VSCY);
saa711x_write(sd, R_D5_B_LUMA_CONTRAST_CNTL,
(u8) (64 * 1024 / VSCY));
saa711x_write(sd, R_D6_B_CHROMA_SATURATION_CNTL,
(u8) (64 * 1024 / VSCY));
saa711x_write(sd, R_E0_B_VERT_LUMA_SCALING_INC,
(u8) (VSCY & 0xff));
saa711x_write(sd, R_E1_B_VERT_LUMA_SCALING_INC_MSB,
(u8) ((VSCY >> 8) & 0xff));
saa711x_write(sd, R_E2_B_VERT_CHROMA_SCALING_INC,
(u8) (VSCY & 0xff));
saa711x_write(sd, R_E3_B_VERT_CHROMA_SCALING_INC_MSB,
(u8) ((VSCY >> 8) & 0xff));
saa711x_writeregs(sd, saa7115_cfg_reset_scaler);
saa711x_write(sd, R_80_GLOBAL_CNTL_1,
saa711x_read(sd, R_80_GLOBAL_CNTL_1) | 0x20);
return 0;
}
static void saa711x_set_v4lstd(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct saa711x_state *state = to_state(sd);
if (std == state->std)
return;
state->std = std;
if (std & V4L2_STD_525_60) {
v4l2_dbg(1, debug, sd, "decoder set standard 60 Hz\n");
saa711x_writeregs(sd, saa7115_cfg_60hz_video);
saa711x_set_size(sd, 720, 480);
} else {
v4l2_dbg(1, debug, sd, "decoder set standard 50 Hz\n");
saa711x_writeregs(sd, saa7115_cfg_50hz_video);
saa711x_set_size(sd, 720, 576);
}
if (state->ident <= V4L2_IDENT_SAA7113) {
u8 reg = saa711x_read(sd, R_0E_CHROMA_CNTL_1) & 0x8f;
if (std == V4L2_STD_PAL_M) {
reg |= 0x30;
} else if (std == V4L2_STD_PAL_Nc) {
reg |= 0x20;
} else if (std == V4L2_STD_PAL_60) {
reg |= 0x10;
} else if (std == V4L2_STD_NTSC_M_JP) {
reg |= 0x40;
} else if (std & V4L2_STD_SECAM) {
reg |= 0x50;
}
saa711x_write(sd, R_0E_CHROMA_CNTL_1, reg);
} else {
int taskb = saa711x_read(sd, R_80_GLOBAL_CNTL_1) & 0x10;
if (taskb && state->ident == V4L2_IDENT_SAA7114) {
saa711x_writeregs(sd, saa7115_cfg_vbi_on);
}
saa711x_s_clock_freq(sd, state->audclk_freq);
}
}
static void saa711x_set_lcr(struct v4l2_subdev *sd, struct v4l2_sliced_vbi_format *fmt)
{
struct saa711x_state *state = to_state(sd);
int is_50hz = (state->std & V4L2_STD_625_50);
u8 lcr[24];
int i, x;
#if 1
if (!saa711x_has_reg(state->ident, R_41_LCR_BASE))
return;
#else
if (state->ident != V4L2_IDENT_SAA7115)
return;
#endif
for (i = 0; i <= 23; i++)
lcr[i] = 0xff;
if (fmt == NULL) {
if (is_50hz)
for (i = 6; i <= 23; i++)
lcr[i] = 0xdd;
else
for (i = 10; i <= 21; i++)
lcr[i] = 0xdd;
} else {
if (is_50hz) {
for (i = 0; i <= 5; i++)
fmt->service_lines[0][i] =
fmt->service_lines[1][i] = 0;
}
else {
for (i = 0; i <= 9; i++)
fmt->service_lines[0][i] =
fmt->service_lines[1][i] = 0;
for (i = 22; i <= 23; i++)
fmt->service_lines[0][i] =
fmt->service_lines[1][i] = 0;
}
for (i = 6; i <= 23; i++) {
lcr[i] = 0;
for (x = 0; x <= 1; x++) {
switch (fmt->service_lines[1-x][i]) {
case 0:
lcr[i] |= 0xf << (4 * x);
break;
case V4L2_SLICED_TELETEXT_B:
lcr[i] |= 1 << (4 * x);
break;
case V4L2_SLICED_CAPTION_525:
lcr[i] |= 4 << (4 * x);
break;
case V4L2_SLICED_WSS_625:
lcr[i] |= 5 << (4 * x);
break;
case V4L2_SLICED_VPS:
lcr[i] |= 7 << (4 * x);
break;
}
}
}
}
for (i = 2; i <= 23; i++) {
saa711x_write(sd, i - 2 + R_41_LCR_BASE, lcr[i]);
}
saa711x_writeregs(sd, fmt == NULL ?
saa7115_cfg_vbi_on :
saa7115_cfg_vbi_off);
}
static int saa711x_g_sliced_fmt(struct v4l2_subdev *sd, struct v4l2_sliced_vbi_format *sliced)
{
static u16 lcr2vbi[] = {
0, V4L2_SLICED_TELETEXT_B, 0,
0, V4L2_SLICED_CAPTION_525,
V4L2_SLICED_WSS_625, 0,
V4L2_SLICED_VPS, 0, 0, 0, 0,
0, 0, 0, 0
};
int i;
memset(sliced->service_lines, 0, sizeof(sliced->service_lines));
sliced->service_set = 0;
if (saa711x_read(sd, R_80_GLOBAL_CNTL_1) & 0x10)
return 0;
for (i = 2; i <= 23; i++) {
u8 v = saa711x_read(sd, i - 2 + R_41_LCR_BASE);
sliced->service_lines[0][i] = lcr2vbi[v >> 4];
sliced->service_lines[1][i] = lcr2vbi[v & 0xf];
sliced->service_set |=
sliced->service_lines[0][i] | sliced->service_lines[1][i];
}
return 0;
}
static int saa711x_s_raw_fmt(struct v4l2_subdev *sd, struct v4l2_vbi_format *fmt)
{
saa711x_set_lcr(sd, NULL);
return 0;
}
static int saa711x_s_sliced_fmt(struct v4l2_subdev *sd, struct v4l2_sliced_vbi_format *fmt)
{
saa711x_set_lcr(sd, fmt);
return 0;
}
static int saa711x_s_mbus_fmt(struct v4l2_subdev *sd, struct v4l2_mbus_framefmt *fmt)
{
if (fmt->code != V4L2_MBUS_FMT_FIXED)
return -EINVAL;
fmt->field = V4L2_FIELD_INTERLACED;
fmt->colorspace = V4L2_COLORSPACE_SMPTE170M;
return saa711x_set_size(sd, fmt->width, fmt->height);
}
static int saa711x_decode_vbi_line(struct v4l2_subdev *sd, struct v4l2_decode_vbi_line *vbi)
{
struct saa711x_state *state = to_state(sd);
static const char vbi_no_data_pattern[] = {
0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0
};
u8 *p = vbi->p;
u32 wss;
int id1, id2;
vbi->type = 0;
id1 = p[2];
id2 = p[3];
if (state->std & V4L2_STD_525_60)
id1 ^= 0x40;
p += 4;
vbi->p = p;
vbi->is_second_field = ((id1 & 0x40) != 0);
vbi->line = (id1 & 0x3f) << 3;
vbi->line |= (id2 & 0x70) >> 4;
id2 &= 0xf;
if (!memcmp(p, vbi_no_data_pattern, sizeof(vbi_no_data_pattern)))
return 0;
switch (id2) {
case 1:
vbi->type = V4L2_SLICED_TELETEXT_B;
break;
case 4:
if (!saa711x_odd_parity(p[0]) || !saa711x_odd_parity(p[1]))
return 0;
vbi->type = V4L2_SLICED_CAPTION_525;
break;
case 5:
wss = saa711x_decode_wss(p);
if (wss == -1)
return 0;
p[0] = wss & 0xff;
p[1] = wss >> 8;
vbi->type = V4L2_SLICED_WSS_625;
break;
case 7:
if (saa711x_decode_vps(p, p) != 0)
return 0;
vbi->type = V4L2_SLICED_VPS;
break;
default:
break;
}
return 0;
}
static int saa711x_g_tuner(struct v4l2_subdev *sd, struct v4l2_tuner *vt)
{
struct saa711x_state *state = to_state(sd);
int status;
if (state->radio)
return 0;
status = saa711x_read(sd, R_1F_STATUS_BYTE_2_VD_DEC);
v4l2_dbg(1, debug, sd, "status: 0x%02x\n", status);
vt->signal = ((status & (1 << 6)) == 0) ? 0xffff : 0x0;
return 0;
}
static int saa711x_s_std(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct saa711x_state *state = to_state(sd);
state->radio = 0;
saa711x_set_v4lstd(sd, std);
return 0;
}
static int saa711x_s_radio(struct v4l2_subdev *sd)
{
struct saa711x_state *state = to_state(sd);
state->radio = 1;
return 0;
}
static int saa711x_s_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct saa711x_state *state = to_state(sd);
u8 mask = (state->ident <= V4L2_IDENT_SAA7111A) ? 0xf8 : 0xf0;
v4l2_dbg(1, debug, sd, "decoder set input %d output %d\n",
input, output);
if (state->ident <= V4L2_IDENT_SAA7113 &&
(input == SAA7115_COMPOSITE4 ||
input == SAA7115_COMPOSITE5)) {
return -EINVAL;
}
if (input > SAA7115_SVIDEO3)
return -EINVAL;
if (state->input == input && state->output == output)
return 0;
v4l2_dbg(1, debug, sd, "now setting %s input %s output\n",
(input >= SAA7115_SVIDEO0) ? "S-Video" : "Composite",
(output == SAA7115_IPORT_ON) ? "iport on" : "iport off");
state->input = input;
if (state->ident <= V4L2_IDENT_SAA7111A) {
if (input >= SAA7115_COMPOSITE4)
input -= 2;
saa711x_write(sd, R_10_CHROMA_CNTL_2,
(saa711x_read(sd, R_10_CHROMA_CNTL_2) & 0x3f) |
((output & 0xc0) ^ 0x40));
saa711x_write(sd, R_13_RT_X_PORT_OUT_CNTL,
(saa711x_read(sd, R_13_RT_X_PORT_OUT_CNTL) & 0xf0) |
((output & 2) ? 0x0a : 0));
}
saa711x_write(sd, R_02_INPUT_CNTL_1,
(saa711x_read(sd, R_02_INPUT_CNTL_1) & mask) |
input);
saa711x_write(sd, R_09_LUMA_CNTL,
(saa711x_read(sd, R_09_LUMA_CNTL) & 0x7f) |
(state->input >= SAA7115_SVIDEO0 ? 0x80 : 0x0));
state->output = output;
if (state->ident == V4L2_IDENT_SAA7114 ||
state->ident == V4L2_IDENT_SAA7115) {
saa711x_write(sd, R_83_X_PORT_I_O_ENA_AND_OUT_CLK,
(saa711x_read(sd, R_83_X_PORT_I_O_ENA_AND_OUT_CLK) & 0xfe) |
(state->output & 0x01));
}
if (state->ident > V4L2_IDENT_SAA7111A) {
if (config & SAA7115_IDQ_IS_DEFAULT)
saa711x_write(sd, R_85_I_PORT_SIGNAL_POLAR, 0x20);
else
saa711x_write(sd, R_85_I_PORT_SIGNAL_POLAR, 0x21);
}
return 0;
}
static int saa711x_s_gpio(struct v4l2_subdev *sd, u32 val)
{
struct saa711x_state *state = to_state(sd);
if (state->ident > V4L2_IDENT_SAA7111A)
return -EINVAL;
saa711x_write(sd, 0x11, (saa711x_read(sd, 0x11) & 0x7f) |
(val ? 0x80 : 0));
return 0;
}
static int saa711x_s_stream(struct v4l2_subdev *sd, int enable)
{
struct saa711x_state *state = to_state(sd);
v4l2_dbg(1, debug, sd, "%s output\n",
enable ? "enable" : "disable");
if (state->enable == enable)
return 0;
state->enable = enable;
if (!saa711x_has_reg(state->ident, R_87_I_PORT_I_O_ENA_OUT_CLK_AND_GATED))
return 0;
saa711x_write(sd, R_87_I_PORT_I_O_ENA_OUT_CLK_AND_GATED, state->enable);
return 0;
}
static int saa711x_s_crystal_freq(struct v4l2_subdev *sd, u32 freq, u32 flags)
{
struct saa711x_state *state = to_state(sd);
if (freq != SAA7115_FREQ_32_11_MHZ && freq != SAA7115_FREQ_24_576_MHZ)
return -EINVAL;
state->crystal_freq = freq;
state->double_asclk = flags & SAA7115_FREQ_FL_DOUBLE_ASCLK;
state->cgcdiv = (flags & SAA7115_FREQ_FL_CGCDIV) ? 3 : 4;
state->ucgc = flags & SAA7115_FREQ_FL_UCGC;
state->apll = flags & SAA7115_FREQ_FL_APLL;
saa711x_s_clock_freq(sd, state->audclk_freq);
return 0;
}
static int saa711x_reset(struct v4l2_subdev *sd, u32 val)
{
v4l2_dbg(1, debug, sd, "decoder RESET\n");
saa711x_writeregs(sd, saa7115_cfg_reset_scaler);
return 0;
}
static int saa711x_g_vbi_data(struct v4l2_subdev *sd, struct v4l2_sliced_vbi_data *data)
{
switch (data->id) {
case V4L2_SLICED_WSS_625:
if (saa711x_read(sd, 0x6b) & 0xc0)
return -EIO;
data->data[0] = saa711x_read(sd, 0x6c);
data->data[1] = saa711x_read(sd, 0x6d);
return 0;
case V4L2_SLICED_CAPTION_525:
if (data->field == 0) {
if (saa711x_read(sd, 0x66) & 0x30)
return -EIO;
data->data[0] = saa711x_read(sd, 0x69);
data->data[1] = saa711x_read(sd, 0x6a);
return 0;
}
if (saa711x_read(sd, 0x66) & 0xc0)
return -EIO;
data->data[0] = saa711x_read(sd, 0x67);
data->data[1] = saa711x_read(sd, 0x68);
return 0;
default:
return -EINVAL;
}
}
static int saa711x_querystd(struct v4l2_subdev *sd, v4l2_std_id *std)
{
struct saa711x_state *state = to_state(sd);
int reg1f, reg1e;
reg1f = saa711x_read(sd, R_1F_STATUS_BYTE_2_VD_DEC);
if (state->ident == V4L2_IDENT_SAA7115) {
reg1e = saa711x_read(sd, R_1E_STATUS_BYTE_1_VD_DEC);
v4l2_dbg(1, debug, sd, "Status byte 1 (0x1e)=0x%02x\n", reg1e);
switch (reg1e & 0x03) {
case 1:
*std &= V4L2_STD_NTSC;
break;
case 2:
*std &= V4L2_STD_PAL | V4L2_STD_PAL_N | V4L2_STD_PAL_Nc |
V4L2_STD_PAL_M | V4L2_STD_PAL_60;
break;
case 3:
*std &= V4L2_STD_SECAM;
break;
default:
break;
}
}
v4l2_dbg(1, debug, sd, "Status byte 2 (0x1f)=0x%02x\n", reg1f);
if (reg1f & 0x40)
goto ret;
if (reg1f & 0x20)
*std &= V4L2_STD_525_60;
else
*std &= V4L2_STD_625_50;
ret:
v4l2_dbg(1, debug, sd, "detected std mask = %08Lx\n", *std);
return 0;
}
static int saa711x_g_input_status(struct v4l2_subdev *sd, u32 *status)
{
struct saa711x_state *state = to_state(sd);
int reg1e = 0x80;
int reg1f;
*status = V4L2_IN_ST_NO_SIGNAL;
if (state->ident == V4L2_IDENT_SAA7115)
reg1e = saa711x_read(sd, R_1E_STATUS_BYTE_1_VD_DEC);
reg1f = saa711x_read(sd, R_1F_STATUS_BYTE_2_VD_DEC);
if ((reg1f & 0xc1) == 0x81 && (reg1e & 0xc0) == 0x80)
*status = 0;
return 0;
}
static int saa711x_g_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
reg->val = saa711x_read(sd, reg->reg & 0xff);
reg->size = 1;
return 0;
}
static int saa711x_s_register(struct v4l2_subdev *sd, const struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
saa711x_write(sd, reg->reg & 0xff, reg->val & 0xff);
return 0;
}
static int saa711x_g_chip_ident(struct v4l2_subdev *sd, struct v4l2_dbg_chip_ident *chip)
{
struct saa711x_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
return v4l2_chip_ident_i2c_client(client, chip, state->ident, 0);
}
static int saa711x_log_status(struct v4l2_subdev *sd)
{
struct saa711x_state *state = to_state(sd);
int reg1e, reg1f;
int signalOk;
int vcr;
v4l2_info(sd, "Audio frequency: %d Hz\n", state->audclk_freq);
if (state->ident != V4L2_IDENT_SAA7115) {
reg1f = saa711x_read(sd, R_1F_STATUS_BYTE_2_VD_DEC);
signalOk = (reg1f & 0xc1) == 0x81;
v4l2_info(sd, "Video signal: %s\n", signalOk ? "ok" : "bad");
v4l2_info(sd, "Frequency: %s\n", (reg1f & 0x20) ? "60 Hz" : "50 Hz");
return 0;
}
reg1e = saa711x_read(sd, R_1E_STATUS_BYTE_1_VD_DEC);
reg1f = saa711x_read(sd, R_1F_STATUS_BYTE_2_VD_DEC);
signalOk = (reg1f & 0xc1) == 0x81 && (reg1e & 0xc0) == 0x80;
vcr = !(reg1f & 0x10);
if (state->input >= 6)
v4l2_info(sd, "Input: S-Video %d\n", state->input - 6);
else
v4l2_info(sd, "Input: Composite %d\n", state->input);
v4l2_info(sd, "Video signal: %s\n", signalOk ? (vcr ? "VCR" : "broadcast/DVD") : "bad");
v4l2_info(sd, "Frequency: %s\n", (reg1f & 0x20) ? "60 Hz" : "50 Hz");
switch (reg1e & 0x03) {
case 1:
v4l2_info(sd, "Detected format: NTSC\n");
break;
case 2:
v4l2_info(sd, "Detected format: PAL\n");
break;
case 3:
v4l2_info(sd, "Detected format: SECAM\n");
break;
default:
v4l2_info(sd, "Detected format: BW/No color\n");
break;
}
v4l2_info(sd, "Width, Height: %d, %d\n", state->width, state->height);
v4l2_ctrl_handler_log_status(&state->hdl, sd->name);
return 0;
}
static int saa711x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct saa711x_state *state;
struct v4l2_subdev *sd;
struct v4l2_ctrl_handler *hdl;
int i;
char name[17];
char chip_id;
int autodetect = !id || id->driver_data == 1;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
for (i = 0; i < 0x0f; i++) {
i2c_smbus_write_byte_data(client, 0, i);
name[i] = (i2c_smbus_read_byte_data(client, 0) & 0x0f) + '0';
if (name[i] > '9')
name[i] += 'a' - '9' - 1;
}
name[i] = '\0';
chip_id = name[5];
if (memcmp(name + 1, "f711", 4)) {
v4l_dbg(1, debug, client, "chip found @ 0x%x (ID %s) does not match a known saa711x chip.\n",
client->addr << 1, name);
return -ENODEV;
}
if (!autodetect && id->name[6] != chip_id) {
v4l_warn(client, "found saa711%c while %s was expected\n",
chip_id, id->name);
}
snprintf(client->name, sizeof(client->name), "saa711%c", chip_id);
v4l_info(client, "saa711%c found (%s) @ 0x%x (%s)\n", chip_id, name,
client->addr << 1, client->adapter->name);
state = kzalloc(sizeof(struct saa711x_state), GFP_KERNEL);
if (state == NULL)
return -ENOMEM;
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &saa711x_ops);
hdl = &state->hdl;
v4l2_ctrl_handler_init(hdl, 6);
v4l2_ctrl_new_std(hdl, &saa711x_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 255, 1, 128);
v4l2_ctrl_new_std(hdl, &saa711x_ctrl_ops,
V4L2_CID_CONTRAST, 0, 127, 1, 64);
v4l2_ctrl_new_std(hdl, &saa711x_ctrl_ops,
V4L2_CID_SATURATION, 0, 127, 1, 64);
v4l2_ctrl_new_std(hdl, &saa711x_ctrl_ops,
V4L2_CID_HUE, -128, 127, 1, 0);
state->agc = v4l2_ctrl_new_std(hdl, &saa711x_ctrl_ops,
V4L2_CID_CHROMA_AGC, 0, 1, 1, 1);
state->gain = v4l2_ctrl_new_std(hdl, &saa711x_ctrl_ops,
V4L2_CID_CHROMA_GAIN, 0, 127, 1, 40);
sd->ctrl_handler = hdl;
if (hdl->error) {
int err = hdl->error;
v4l2_ctrl_handler_free(hdl);
kfree(state);
return err;
}
v4l2_ctrl_auto_cluster(2, &state->agc, 0, true);
state->input = -1;
state->output = SAA7115_IPORT_ON;
state->enable = 1;
state->radio = 0;
switch (chip_id) {
case '1':
state->ident = V4L2_IDENT_SAA7111;
if (saa711x_read(sd, R_00_CHIP_VERSION) & 0xf0) {
v4l_info(client, "saa7111a variant found\n");
state->ident = V4L2_IDENT_SAA7111A;
}
break;
case '3':
state->ident = V4L2_IDENT_SAA7113;
break;
case '4':
state->ident = V4L2_IDENT_SAA7114;
break;
case '5':
state->ident = V4L2_IDENT_SAA7115;
break;
case '8':
state->ident = V4L2_IDENT_SAA7118;
break;
default:
state->ident = V4L2_IDENT_SAA7111;
v4l2_info(sd, "WARNING: Chip is not known - Falling back to saa7111\n");
break;
}
state->audclk_freq = 48000;
v4l2_dbg(1, debug, sd, "writing init values\n");
state->crystal_freq = SAA7115_FREQ_24_576_MHZ;
switch (state->ident) {
case V4L2_IDENT_SAA7111:
case V4L2_IDENT_SAA7111A:
saa711x_writeregs(sd, saa7111_init);
break;
case V4L2_IDENT_SAA7113:
saa711x_writeregs(sd, saa7113_init);
break;
default:
state->crystal_freq = SAA7115_FREQ_32_11_MHZ;
saa711x_writeregs(sd, saa7115_init_auto_input);
}
if (state->ident > V4L2_IDENT_SAA7111A)
saa711x_writeregs(sd, saa7115_init_misc);
saa711x_set_v4lstd(sd, V4L2_STD_NTSC);
v4l2_ctrl_handler_setup(hdl);
v4l2_dbg(1, debug, sd, "status: (1E) 0x%02x, (1F) 0x%02x\n",
saa711x_read(sd, R_1E_STATUS_BYTE_1_VD_DEC),
saa711x_read(sd, R_1F_STATUS_BYTE_2_VD_DEC));
return 0;
}
static int saa711x_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
v4l2_ctrl_handler_free(sd->ctrl_handler);
kfree(to_state(sd));
return 0;
}
