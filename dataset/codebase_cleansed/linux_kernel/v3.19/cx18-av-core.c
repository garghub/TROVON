int cx18_av_write(struct cx18 *cx, u16 addr, u8 value)
{
u32 reg = 0xc40000 + (addr & ~3);
u32 mask = 0xff;
int shift = (addr & 3) * 8;
u32 x = cx18_read_reg(cx, reg);
x = (x & ~(mask << shift)) | ((u32)value << shift);
cx18_write_reg(cx, x, reg);
return 0;
}
int cx18_av_write_expect(struct cx18 *cx, u16 addr, u8 value, u8 eval, u8 mask)
{
u32 reg = 0xc40000 + (addr & ~3);
int shift = (addr & 3) * 8;
u32 x = cx18_read_reg(cx, reg);
x = (x & ~((u32)0xff << shift)) | ((u32)value << shift);
cx18_write_reg_expect(cx, x, reg,
((u32)eval << shift), ((u32)mask << shift));
return 0;
}
int cx18_av_write4(struct cx18 *cx, u16 addr, u32 value)
{
cx18_write_reg(cx, value, 0xc40000 + addr);
return 0;
}
int
cx18_av_write4_expect(struct cx18 *cx, u16 addr, u32 value, u32 eval, u32 mask)
{
cx18_write_reg_expect(cx, value, 0xc40000 + addr, eval, mask);
return 0;
}
int cx18_av_write4_noretry(struct cx18 *cx, u16 addr, u32 value)
{
cx18_write_reg_noretry(cx, value, 0xc40000 + addr);
return 0;
}
u8 cx18_av_read(struct cx18 *cx, u16 addr)
{
u32 x = cx18_read_reg(cx, 0xc40000 + (addr & ~3));
int shift = (addr & 3) * 8;
return (x >> shift) & 0xff;
}
u32 cx18_av_read4(struct cx18 *cx, u16 addr)
{
return cx18_read_reg(cx, 0xc40000 + addr);
}
int cx18_av_and_or(struct cx18 *cx, u16 addr, unsigned and_mask,
u8 or_value)
{
return cx18_av_write(cx, addr,
(cx18_av_read(cx, addr) & and_mask) |
or_value);
}
int cx18_av_and_or4(struct cx18 *cx, u16 addr, u32 and_mask,
u32 or_value)
{
return cx18_av_write4(cx, addr,
(cx18_av_read4(cx, addr) & and_mask) |
or_value);
}
static void cx18_av_init(struct cx18 *cx)
{
cx18_av_write4(cx, CXADEC_PLL_CTRL1, 0x160e040f);
cx18_av_write4(cx, CXADEC_VID_PLL_FRAC, 0x002be2fe);
cx18_av_write4(cx, CXADEC_AUX_PLL_FRAC, 0x005227ad);
cx18_av_write(cx, CXADEC_I2S_MCLK, 0x56);
}
static void cx18_av_initialize(struct v4l2_subdev *sd)
{
struct cx18_av_state *state = to_cx18_av_state(sd);
struct cx18 *cx = v4l2_get_subdevdata(sd);
int default_volume;
u32 v;
cx18_av_loadfw(cx);
cx18_av_write4_expect(cx, CXADEC_DL_CTL, 0x03000000,
0x03000000, 0x13000000);
v = cx18_av_read4(cx, CXADEC_HOST_REG1);
cx18_av_write4_expect(cx, CXADEC_HOST_REG1, v | 1, v, 0xfffe);
cx18_av_write4_expect(cx, CXADEC_HOST_REG1, v & 0xfffe,
v & 0xfffe, 0xffff);
v = cx18_av_read4(cx, CXADEC_DLL1_DIAG_CTRL) & 0xE1FFFEFF;
cx18_av_write4(cx, CXADEC_DLL1_DIAG_CTRL, v);
cx18_av_write4(cx, CXADEC_DLL1_DIAG_CTRL, v | 0x10000100);
v = cx18_av_read4(cx, CXADEC_DLL2_DIAG_CTRL) & 0xE1FFFEFF;
cx18_av_write4(cx, CXADEC_DLL2_DIAG_CTRL, v);
cx18_av_write4(cx, CXADEC_DLL2_DIAG_CTRL, v | 0x06000100);
cx18_av_write4(cx, CXADEC_AFE_DIAG_CTRL1, 0x000A1802);
v = cx18_av_read4(cx, CXADEC_AFE_DIAG_CTRL3) | 1;
cx18_av_write4_expect(cx, CXADEC_AFE_DIAG_CTRL3, v, v, 0x03009F0F);
cx18_av_write4_expect(cx, CXADEC_AFE_DIAG_CTRL3,
v & 0xFFFFFFFE, v & 0xFFFFFFFE, 0x03009F0F);
cx18_av_and_or4(cx, CXADEC_PIN_CTRL1, ~0, 0x040C00);
cx18_av_and_or4(cx, CXADEC_PIN_CTRL2, ~0, 0x2);
cx18_av_write4(cx, CXADEC_SOFT_RST_CTRL, 0x8000);
cx18_av_write4(cx, CXADEC_SOFT_RST_CTRL, 0);
cx18_av_and_or4(cx, CXADEC_CHIP_CTRL, 0xFFFBFFFF, 0x00120000);
cx18_av_init(cx);
cx18_av_and_or4(cx, CXADEC_MODE_CTRL, 0xFFF7E7F0, 0x02040800);
cx18_av_and_or4(cx, CXADEC_CRUSH_CTRL, ~0, 0x00500000);
cx18_av_and_or4(cx, CXADEC_DFE_CTRL2, 0xFFFF00FF, 0x00002000);
cx18_av_write4(cx, CXADEC_OUT_CTRL1, 0x4013252e);
cx18_av_and_or4(cx, CXADEC_AFE_CTRL, 0xFF000000, 0x00005D00);
cx18_av_write4(cx, CXADEC_SRC_COMB_CFG, 0x6628021F);
default_volume = cx18_av_read(cx, 0x8d4);
if (default_volume > 228) {
default_volume = 228;
cx18_av_write(cx, 0x8d4, 228);
} else if (default_volume < 20) {
default_volume = 20;
cx18_av_write(cx, 0x8d4, 20);
}
default_volume = (((228 - default_volume) >> 1) + 23) << 9;
state->volume->cur.val = state->volume->default_value = default_volume;
v4l2_ctrl_handler_setup(&state->hdl);
}
static int cx18_av_reset(struct v4l2_subdev *sd, u32 val)
{
cx18_av_initialize(sd);
return 0;
}
static int cx18_av_load_fw(struct v4l2_subdev *sd)
{
struct cx18_av_state *state = to_cx18_av_state(sd);
if (!state->is_initialized) {
state->is_initialized = 1;
cx18_av_initialize(sd);
}
return 0;
}
void cx18_av_std_setup(struct cx18 *cx)
{
struct cx18_av_state *state = &cx->av_state;
struct v4l2_subdev *sd = &state->sd;
v4l2_std_id std = state->std;
const int src_decimation = 0x21f;
int hblank, hactive, burst, vblank, vactive, sc;
int vblank656;
int luma_lpf, uv_lpf, comb;
u32 pll_int, pll_frac, pll_post;
if (std & ~V4L2_STD_NTSC)
cx18_av_write(cx, 0x49f, 0x11);
else
cx18_av_write(cx, 0x49f, 0x14);
if (std & V4L2_STD_625_50) {
vblank656 = 48;
vblank = 38;
vactive = 579;
hblank = 132;
hactive = 720;
burst = 93;
luma_lpf = 2;
if (std & V4L2_STD_PAL) {
uv_lpf = 1;
comb = 0x20;
sc = 688700;
} else if (std == V4L2_STD_PAL_Nc) {
uv_lpf = 1;
comb = 0x20;
sc = 556422;
} else {
uv_lpf = 0;
comb = 0;
sc = 672314;
}
} else {
vblank656 = 38;
vblank = 26;
vactive = 481;
hactive = 720;
hblank = 122;
luma_lpf = 1;
uv_lpf = 1;
if (std == V4L2_STD_PAL_60) {
burst = 90;
luma_lpf = 2;
comb = 0x20;
sc = 688700;
} else if (std == V4L2_STD_PAL_M) {
burst = 97;
comb = 0x20;
sc = 555421;
} else {
burst = 90;
comb = 0x66;
sc = 556032;
}
}
pll_int = cx18_av_read(cx, 0x108);
pll_frac = cx18_av_read4(cx, 0x10c) & 0x1ffffff;
pll_post = cx18_av_read(cx, 0x109);
CX18_DEBUG_INFO_DEV(sd, "PLL regs = int: %u, frac: %u, post: %u\n",
pll_int, pll_frac, pll_post);
if (pll_post) {
int fsc, pll;
u64 tmp;
pll = (28636360L * ((((u64)pll_int) << 25) + pll_frac)) >> 25;
pll /= pll_post;
CX18_DEBUG_INFO_DEV(sd, "Video PLL = %d.%06d MHz\n",
pll / 1000000, pll % 1000000);
CX18_DEBUG_INFO_DEV(sd, "Pixel rate = %d.%06d Mpixel/sec\n",
pll / 8000000, (pll / 8) % 1000000);
CX18_DEBUG_INFO_DEV(sd, "ADC XTAL/pixel clock decimation ratio "
"= %d.%03d\n", src_decimation / 256,
((src_decimation % 256) * 1000) / 256);
tmp = 28636360 * (u64) sc;
do_div(tmp, src_decimation);
fsc = tmp >> 13;
CX18_DEBUG_INFO_DEV(sd,
"Chroma sub-carrier initial freq = %d.%06d "
"MHz\n", fsc / 1000000, fsc % 1000000);
CX18_DEBUG_INFO_DEV(sd, "hblank %i, hactive %i, vblank %i, "
"vactive %i, vblank656 %i, src_dec %i, "
"burst 0x%02x, luma_lpf %i, uv_lpf %i, "
"comb 0x%02x, sc 0x%06x\n",
hblank, hactive, vblank, vactive, vblank656,
src_decimation, burst, luma_lpf, uv_lpf,
comb, sc);
}
cx18_av_write(cx, 0x470, hblank);
cx18_av_write(cx, 0x471,
(((hblank >> 8) & 0x3) | (hactive << 4)) & 0xff);
cx18_av_write(cx, 0x472, hactive >> 4);
cx18_av_write(cx, 0x473, burst);
cx18_av_write(cx, 0x474, vblank);
cx18_av_write(cx, 0x475,
(((vblank >> 8) & 0x3) | (vactive << 4)) & 0xff);
cx18_av_write(cx, 0x476, vactive >> 4);
cx18_av_write(cx, 0x477, vblank656);
cx18_av_write(cx, 0x478, src_decimation & 0xff);
cx18_av_write(cx, 0x479, (src_decimation >> 8) & 0xff);
cx18_av_write(cx, 0x47a, luma_lpf << 6 | ((uv_lpf << 4) & 0x30));
cx18_av_write(cx, 0x47b, comb);
cx18_av_write(cx, 0x47c, sc);
cx18_av_write(cx, 0x47d, (sc >> 8) & 0xff);
cx18_av_write(cx, 0x47e, (sc >> 16) & 0xff);
if (std & V4L2_STD_625_50) {
state->slicer_line_delay = 1;
state->slicer_line_offset = (6 + state->slicer_line_delay - 2);
} else {
state->slicer_line_delay = 0;
state->slicer_line_offset = (10 + state->slicer_line_delay - 2);
}
cx18_av_write(cx, 0x47f, state->slicer_line_delay);
}
static void input_change(struct cx18 *cx)
{
struct cx18_av_state *state = &cx->av_state;
v4l2_std_id std = state->std;
u8 v;
cx18_av_write(cx, 0x49f, (std & V4L2_STD_NTSC) ? 0x14 : 0x11);
cx18_av_and_or(cx, 0x401, ~0x60, 0);
cx18_av_and_or(cx, 0x401, ~0x60, 0x60);
if (std & V4L2_STD_525_60) {
if (std == V4L2_STD_NTSC_M_JP) {
cx18_av_write_expect(cx, 0x808, 0xf7, 0xf7, 0xff);
cx18_av_write_expect(cx, 0x80b, 0x02, 0x02, 0x3f);
} else if (std == V4L2_STD_NTSC_M_KR) {
cx18_av_write_expect(cx, 0x808, 0xf8, 0xf8, 0xff);
cx18_av_write_expect(cx, 0x80b, 0x03, 0x03, 0x3f);
} else {
cx18_av_write_expect(cx, 0x808, 0xf6, 0xf6, 0xff);
cx18_av_write_expect(cx, 0x80b, 0x01, 0x01, 0x3f);
}
} else if (std & V4L2_STD_PAL) {
cx18_av_write_expect(cx, 0x808, 0xff, 0xff, 0xff);
cx18_av_write_expect(cx, 0x80b, 0x03, 0x03, 0x3f);
} else if (std & V4L2_STD_SECAM) {
cx18_av_write_expect(cx, 0x808, 0xff, 0xff, 0xff);
cx18_av_write_expect(cx, 0x80b, 0x03, 0x03, 0x3f);
}
v = cx18_av_read(cx, 0x803);
if (v & 0x10) {
v &= ~0x10;
cx18_av_write_expect(cx, 0x803, v, v, 0x1f);
v |= 0x10;
cx18_av_write_expect(cx, 0x803, v, v, 0x1f);
}
}
static int cx18_av_s_frequency(struct v4l2_subdev *sd,
const struct v4l2_frequency *freq)
{
struct cx18 *cx = v4l2_get_subdevdata(sd);
input_change(cx);
return 0;
}
static int set_input(struct cx18 *cx, enum cx18_av_video_input vid_input,
enum cx18_av_audio_input aud_input)
{
struct cx18_av_state *state = &cx->av_state;
struct v4l2_subdev *sd = &state->sd;
enum analog_signal_type {
NONE, CVBS, Y, C, SIF, Pb, Pr
} ch[3] = {NONE, NONE, NONE};
u8 afe_mux_cfg;
u8 adc2_cfg;
u8 input_mode;
u32 afe_cfg;
int i;
CX18_DEBUG_INFO_DEV(sd, "decoder set video input %d, audio input %d\n",
vid_input, aud_input);
if (vid_input >= CX18_AV_COMPOSITE1 &&
vid_input <= CX18_AV_COMPOSITE8) {
afe_mux_cfg = 0xf0 + (vid_input - CX18_AV_COMPOSITE1);
ch[0] = CVBS;
input_mode = 0x0;
} else if (vid_input >= CX18_AV_COMPONENT_LUMA1) {
int luma = vid_input & 0xf000;
int r_chroma = vid_input & 0xf0000;
int b_chroma = vid_input & 0xf00000;
if ((vid_input & ~0xfff000) ||
luma < CX18_AV_COMPONENT_LUMA1 ||
luma > CX18_AV_COMPONENT_LUMA8 ||
r_chroma < CX18_AV_COMPONENT_R_CHROMA4 ||
r_chroma > CX18_AV_COMPONENT_R_CHROMA6 ||
b_chroma < CX18_AV_COMPONENT_B_CHROMA7 ||
b_chroma > CX18_AV_COMPONENT_B_CHROMA8) {
CX18_ERR_DEV(sd, "0x%06x is not a valid video input!\n",
vid_input);
return -EINVAL;
}
afe_mux_cfg = (luma - CX18_AV_COMPONENT_LUMA1) >> 12;
ch[0] = Y;
afe_mux_cfg |= (r_chroma - CX18_AV_COMPONENT_R_CHROMA4) >> 12;
ch[1] = Pr;
afe_mux_cfg |= (b_chroma - CX18_AV_COMPONENT_B_CHROMA7) >> 14;
ch[2] = Pb;
input_mode = 0x6;
} else {
int luma = vid_input & 0xf0;
int chroma = vid_input & 0xf00;
if ((vid_input & ~0xff0) ||
luma < CX18_AV_SVIDEO_LUMA1 ||
luma > CX18_AV_SVIDEO_LUMA8 ||
chroma < CX18_AV_SVIDEO_CHROMA4 ||
chroma > CX18_AV_SVIDEO_CHROMA8) {
CX18_ERR_DEV(sd, "0x%06x is not a valid video input!\n",
vid_input);
return -EINVAL;
}
afe_mux_cfg = 0xf0 + ((luma - CX18_AV_SVIDEO_LUMA1) >> 4);
ch[0] = Y;
if (chroma >= CX18_AV_SVIDEO_CHROMA7) {
afe_mux_cfg &= 0x3f;
afe_mux_cfg |= (chroma - CX18_AV_SVIDEO_CHROMA7) >> 2;
ch[2] = C;
} else {
afe_mux_cfg &= 0xcf;
afe_mux_cfg |= (chroma - CX18_AV_SVIDEO_CHROMA4) >> 4;
ch[1] = C;
}
input_mode = 0x2;
}
switch (aud_input) {
case CX18_AV_AUDIO_SERIAL1:
case CX18_AV_AUDIO_SERIAL2:
break;
case CX18_AV_AUDIO4:
afe_mux_cfg &= ~0x30;
ch[1] = SIF;
break;
case CX18_AV_AUDIO5:
afe_mux_cfg = (afe_mux_cfg & ~0x30) | 0x10;
ch[1] = SIF;
break;
case CX18_AV_AUDIO6:
afe_mux_cfg = (afe_mux_cfg & ~0x30) | 0x20;
ch[1] = SIF;
break;
case CX18_AV_AUDIO7:
afe_mux_cfg &= ~0xc0;
ch[2] = SIF;
break;
case CX18_AV_AUDIO8:
afe_mux_cfg = (afe_mux_cfg & ~0xc0) | 0x40;
ch[2] = SIF;
break;
default:
CX18_ERR_DEV(sd, "0x%04x is not a valid audio input!\n",
aud_input);
return -EINVAL;
}
cx18_av_write_expect(cx, 0x103, afe_mux_cfg, afe_mux_cfg, 0xf7);
cx18_av_and_or(cx, 0x401, ~0x6, input_mode);
adc2_cfg = cx18_av_read(cx, 0x102);
if (ch[2] == NONE)
adc2_cfg &= ~0x2;
else
adc2_cfg |= 0x2;
if (ch[1] != NONE && ch[2] != NONE)
adc2_cfg |= 0x4;
else
adc2_cfg &= ~0x4;
cx18_av_write_expect(cx, 0x102, adc2_cfg, adc2_cfg, 0x17);
afe_cfg = cx18_av_read4(cx, CXADEC_AFE_CTRL);
afe_cfg &= 0xff000000;
afe_cfg |= 0x00005000;
if (ch[1] != NONE && ch[2] != NONE)
afe_cfg |= 0x00000030;
for (i = 0; i < 3; i++) {
switch (ch[i]) {
default:
case NONE:
afe_cfg |= (0x00000200 << i);
break;
case CVBS:
case Y:
if (i > 0)
afe_cfg |= 0x00002000;
break;
case C:
case Pb:
case Pr:
afe_cfg |= (0x00000200 << i);
if (i == 0 && ch[i] == C)
afe_cfg &= ~0x00001000;
break;
case SIF:
afe_cfg |= (0x00000240 << i);
if (i == 0)
afe_cfg &= ~0x00004000;
break;
}
}
cx18_av_write4(cx, CXADEC_AFE_CTRL, afe_cfg);
state->vid_input = vid_input;
state->aud_input = aud_input;
cx18_av_audio_set_path(cx);
input_change(cx);
return 0;
}
static int cx18_av_s_video_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct cx18_av_state *state = to_cx18_av_state(sd);
struct cx18 *cx = v4l2_get_subdevdata(sd);
return set_input(cx, input, state->aud_input);
}
static int cx18_av_s_audio_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct cx18_av_state *state = to_cx18_av_state(sd);
struct cx18 *cx = v4l2_get_subdevdata(sd);
return set_input(cx, state->vid_input, input);
}
static int cx18_av_g_tuner(struct v4l2_subdev *sd, struct v4l2_tuner *vt)
{
struct cx18_av_state *state = to_cx18_av_state(sd);
struct cx18 *cx = v4l2_get_subdevdata(sd);
u8 vpres;
u8 mode;
int val = 0;
if (state->radio)
return 0;
vpres = cx18_av_read(cx, 0x40e) & 0x20;
vt->signal = vpres ? 0xffff : 0x0;
vt->capability |=
V4L2_TUNER_CAP_STEREO | V4L2_TUNER_CAP_LANG1 |
V4L2_TUNER_CAP_LANG2 | V4L2_TUNER_CAP_SAP;
mode = cx18_av_read(cx, 0x804);
if ((mode & 0xf) == 1)
val |= V4L2_TUNER_SUB_STEREO;
else
val |= V4L2_TUNER_SUB_MONO;
if (mode == 2 || mode == 4)
val = V4L2_TUNER_SUB_LANG1 | V4L2_TUNER_SUB_LANG2;
if (mode & 0x10)
val |= V4L2_TUNER_SUB_SAP;
vt->rxsubchans = val;
vt->audmode = state->audmode;
return 0;
}
static int cx18_av_s_tuner(struct v4l2_subdev *sd, const struct v4l2_tuner *vt)
{
struct cx18_av_state *state = to_cx18_av_state(sd);
struct cx18 *cx = v4l2_get_subdevdata(sd);
u8 v;
if (state->radio)
return 0;
v = cx18_av_read(cx, 0x809);
v &= ~0xf;
switch (vt->audmode) {
case V4L2_TUNER_MODE_MONO:
break;
case V4L2_TUNER_MODE_STEREO:
case V4L2_TUNER_MODE_LANG1:
v |= 0x4;
break;
case V4L2_TUNER_MODE_LANG1_LANG2:
v |= 0x7;
break;
case V4L2_TUNER_MODE_LANG2:
v |= 0x1;
break;
default:
return -EINVAL;
}
cx18_av_write_expect(cx, 0x809, v, v, 0xff);
state->audmode = vt->audmode;
return 0;
}
static int cx18_av_s_std(struct v4l2_subdev *sd, v4l2_std_id norm)
{
struct cx18_av_state *state = to_cx18_av_state(sd);
struct cx18 *cx = v4l2_get_subdevdata(sd);
u8 fmt = 0;
u8 pal_m = 0;
if (state->radio == 0 && state->std == norm)
return 0;
state->radio = 0;
state->std = norm;
if (state->std == V4L2_STD_NTSC_M_JP) {
fmt = 0x2;
} else if (state->std == V4L2_STD_NTSC_443) {
fmt = 0x3;
} else if (state->std == V4L2_STD_PAL_M) {
pal_m = 1;
fmt = 0x5;
} else if (state->std == V4L2_STD_PAL_N) {
fmt = 0x6;
} else if (state->std == V4L2_STD_PAL_Nc) {
fmt = 0x7;
} else if (state->std == V4L2_STD_PAL_60) {
fmt = 0x8;
} else {
if (state->std & V4L2_STD_NTSC)
fmt = 0x1;
else if (state->std & V4L2_STD_PAL)
fmt = 0x4;
else if (state->std & V4L2_STD_SECAM)
fmt = 0xc;
}
CX18_DEBUG_INFO_DEV(sd, "changing video std to fmt %i\n", fmt);
if (fmt >= 4 && fmt < 8) {
cx18_av_and_or(cx, 0x400, ~0xf, 1);
cx18_av_and_or(cx, 0x47b, ~6, 0);
}
cx18_av_and_or(cx, 0x400, ~0x2f, fmt | 0x20);
cx18_av_and_or(cx, 0x403, ~0x3, pal_m);
cx18_av_std_setup(cx);
input_change(cx);
return 0;
}
static int cx18_av_s_radio(struct v4l2_subdev *sd)
{
struct cx18_av_state *state = to_cx18_av_state(sd);
state->radio = 1;
return 0;
}
static int cx18_av_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
struct cx18 *cx = v4l2_get_subdevdata(sd);
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
cx18_av_write(cx, 0x414, ctrl->val - 128);
break;
case V4L2_CID_CONTRAST:
cx18_av_write(cx, 0x415, ctrl->val << 1);
break;
case V4L2_CID_SATURATION:
cx18_av_write(cx, 0x420, ctrl->val << 1);
cx18_av_write(cx, 0x421, ctrl->val << 1);
break;
case V4L2_CID_HUE:
cx18_av_write(cx, 0x422, ctrl->val);
break;
default:
return -EINVAL;
}
return 0;
}
static int cx18_av_s_mbus_fmt(struct v4l2_subdev *sd, struct v4l2_mbus_framefmt *fmt)
{
struct cx18_av_state *state = to_cx18_av_state(sd);
struct cx18 *cx = v4l2_get_subdevdata(sd);
int HSC, VSC, Vsrc, Hsrc, filter, Vlines;
int is_50Hz = !(state->std & V4L2_STD_525_60);
if (fmt->code != MEDIA_BUS_FMT_FIXED)
return -EINVAL;
fmt->field = V4L2_FIELD_INTERLACED;
fmt->colorspace = V4L2_COLORSPACE_SMPTE170M;
Vsrc = (cx18_av_read(cx, 0x476) & 0x3f) << 4;
Vsrc |= (cx18_av_read(cx, 0x475) & 0xf0) >> 4;
Hsrc = (cx18_av_read(cx, 0x472) & 0x3f) << 4;
Hsrc |= (cx18_av_read(cx, 0x471) & 0xf0) >> 4;
Vlines = fmt->height + (is_50Hz ? 3 : 1);
if ((fmt->width * 16 < Hsrc) || (Hsrc < fmt->width) ||
(Vlines * 8 < Vsrc) || (Vsrc < Vlines)) {
CX18_ERR_DEV(sd, "%dx%d is not a valid size!\n",
fmt->width, fmt->height);
return -ERANGE;
}
HSC = (Hsrc * (1 << 20)) / fmt->width - (1 << 20);
VSC = (1 << 16) - (Vsrc * (1 << 9) / Vlines - (1 << 9));
VSC &= 0x1fff;
if (fmt->width >= 385)
filter = 0;
else if (fmt->width > 192)
filter = 1;
else if (fmt->width > 96)
filter = 2;
else
filter = 3;
CX18_DEBUG_INFO_DEV(sd,
"decoder set size %dx%d -> scale %ux%u\n",
fmt->width, fmt->height, HSC, VSC);
cx18_av_write(cx, 0x418, HSC & 0xff);
cx18_av_write(cx, 0x419, (HSC >> 8) & 0xff);
cx18_av_write(cx, 0x41a, HSC >> 16);
cx18_av_write(cx, 0x41c, VSC & 0xff);
cx18_av_write(cx, 0x41d, VSC >> 8);
cx18_av_write(cx, 0x41e, 0x8 | filter);
return 0;
}
static int cx18_av_s_stream(struct v4l2_subdev *sd, int enable)
{
struct cx18 *cx = v4l2_get_subdevdata(sd);
CX18_DEBUG_INFO_DEV(sd, "%s output\n", enable ? "enable" : "disable");
if (enable) {
cx18_av_write(cx, 0x115, 0x8c);
cx18_av_write(cx, 0x116, 0x07);
} else {
cx18_av_write(cx, 0x115, 0x00);
cx18_av_write(cx, 0x116, 0x00);
}
return 0;
}
static void log_video_status(struct cx18 *cx)
{
static const char *const fmt_strs[] = {
"0x0",
"NTSC-M", "NTSC-J", "NTSC-4.43",
"PAL-BDGHI", "PAL-M", "PAL-N", "PAL-Nc", "PAL-60",
"0x9", "0xA", "0xB",
"SECAM",
"0xD", "0xE", "0xF"
};
struct cx18_av_state *state = &cx->av_state;
struct v4l2_subdev *sd = &state->sd;
u8 vidfmt_sel = cx18_av_read(cx, 0x400) & 0xf;
u8 gen_stat1 = cx18_av_read(cx, 0x40d);
u8 gen_stat2 = cx18_av_read(cx, 0x40e);
int vid_input = state->vid_input;
CX18_INFO_DEV(sd, "Video signal: %spresent\n",
(gen_stat2 & 0x20) ? "" : "not ");
CX18_INFO_DEV(sd, "Detected format: %s\n",
fmt_strs[gen_stat1 & 0xf]);
CX18_INFO_DEV(sd, "Specified standard: %s\n",
vidfmt_sel ? fmt_strs[vidfmt_sel]
: "automatic detection");
if (vid_input >= CX18_AV_COMPOSITE1 &&
vid_input <= CX18_AV_COMPOSITE8) {
CX18_INFO_DEV(sd, "Specified video input: Composite %d\n",
vid_input - CX18_AV_COMPOSITE1 + 1);
} else {
CX18_INFO_DEV(sd, "Specified video input: "
"S-Video (Luma In%d, Chroma In%d)\n",
(vid_input & 0xf0) >> 4,
(vid_input & 0xf00) >> 8);
}
CX18_INFO_DEV(sd, "Specified audioclock freq: %d Hz\n",
state->audclk_freq);
}
static void log_audio_status(struct cx18 *cx)
{
struct cx18_av_state *state = &cx->av_state;
struct v4l2_subdev *sd = &state->sd;
u8 download_ctl = cx18_av_read(cx, 0x803);
u8 mod_det_stat0 = cx18_av_read(cx, 0x804);
u8 mod_det_stat1 = cx18_av_read(cx, 0x805);
u8 audio_config = cx18_av_read(cx, 0x808);
u8 pref_mode = cx18_av_read(cx, 0x809);
u8 afc0 = cx18_av_read(cx, 0x80b);
u8 mute_ctl = cx18_av_read(cx, 0x8d3);
int aud_input = state->aud_input;
char *p;
switch (mod_det_stat0) {
case 0x00: p = "mono"; break;
case 0x01: p = "stereo"; break;
case 0x02: p = "dual"; break;
case 0x04: p = "tri"; break;
case 0x10: p = "mono with SAP"; break;
case 0x11: p = "stereo with SAP"; break;
case 0x12: p = "dual with SAP"; break;
case 0x14: p = "tri with SAP"; break;
case 0xfe: p = "forced mode"; break;
default: p = "not defined"; break;
}
CX18_INFO_DEV(sd, "Detected audio mode: %s\n", p);
switch (mod_det_stat1) {
case 0x00: p = "not defined"; break;
case 0x01: p = "EIAJ"; break;
case 0x02: p = "A2-M"; break;
case 0x03: p = "A2-BG"; break;
case 0x04: p = "A2-DK1"; break;
case 0x05: p = "A2-DK2"; break;
case 0x06: p = "A2-DK3"; break;
case 0x07: p = "A1 (6.0 MHz FM Mono)"; break;
case 0x08: p = "AM-L"; break;
case 0x09: p = "NICAM-BG"; break;
case 0x0a: p = "NICAM-DK"; break;
case 0x0b: p = "NICAM-I"; break;
case 0x0c: p = "NICAM-L"; break;
case 0x0d: p = "BTSC/EIAJ/A2-M Mono (4.5 MHz FMMono)"; break;
case 0x0e: p = "IF FM Radio"; break;
case 0x0f: p = "BTSC"; break;
case 0x10: p = "detected chrominance"; break;
case 0xfd: p = "unknown audio standard"; break;
case 0xfe: p = "forced audio standard"; break;
case 0xff: p = "no detected audio standard"; break;
default: p = "not defined"; break;
}
CX18_INFO_DEV(sd, "Detected audio standard: %s\n", p);
CX18_INFO_DEV(sd, "Audio muted: %s\n",
(mute_ctl & 0x2) ? "yes" : "no");
CX18_INFO_DEV(sd, "Audio microcontroller: %s\n",
(download_ctl & 0x10) ? "running" : "stopped");
switch (audio_config >> 4) {
case 0x00: p = "undefined"; break;
case 0x01: p = "BTSC"; break;
case 0x02: p = "EIAJ"; break;
case 0x03: p = "A2-M"; break;
case 0x04: p = "A2-BG"; break;
case 0x05: p = "A2-DK1"; break;
case 0x06: p = "A2-DK2"; break;
case 0x07: p = "A2-DK3"; break;
case 0x08: p = "A1 (6.0 MHz FM Mono)"; break;
case 0x09: p = "AM-L"; break;
case 0x0a: p = "NICAM-BG"; break;
case 0x0b: p = "NICAM-DK"; break;
case 0x0c: p = "NICAM-I"; break;
case 0x0d: p = "NICAM-L"; break;
case 0x0e: p = "FM radio"; break;
case 0x0f: p = "automatic detection"; break;
default: p = "undefined"; break;
}
CX18_INFO_DEV(sd, "Configured audio standard: %s\n", p);
if ((audio_config >> 4) < 0xF) {
switch (audio_config & 0xF) {
case 0x00: p = "MONO1 (LANGUAGE A/Mono L+R channel for BTSC, EIAJ, A2)"; break;
case 0x01: p = "MONO2 (LANGUAGE B)"; break;
case 0x02: p = "MONO3 (STEREO forced MONO)"; break;
case 0x03: p = "MONO4 (NICAM ANALOG-Language C/Analog Fallback)"; break;
case 0x04: p = "STEREO"; break;
case 0x05: p = "DUAL1 (AC)"; break;
case 0x06: p = "DUAL2 (BC)"; break;
case 0x07: p = "DUAL3 (AB)"; break;
default: p = "undefined";
}
CX18_INFO_DEV(sd, "Configured audio mode: %s\n", p);
} else {
switch (audio_config & 0xF) {
case 0x00: p = "BG"; break;
case 0x01: p = "DK1"; break;
case 0x02: p = "DK2"; break;
case 0x03: p = "DK3"; break;
case 0x04: p = "I"; break;
case 0x05: p = "L"; break;
case 0x06: p = "BTSC"; break;
case 0x07: p = "EIAJ"; break;
case 0x08: p = "A2-M"; break;
case 0x09: p = "FM Radio (4.5 MHz)"; break;
case 0x0a: p = "FM Radio (5.5 MHz)"; break;
case 0x0b: p = "S-Video"; break;
case 0x0f: p = "automatic standard and mode detection"; break;
default: p = "undefined"; break;
}
CX18_INFO_DEV(sd, "Configured audio system: %s\n", p);
}
if (aud_input)
CX18_INFO_DEV(sd, "Specified audio input: Tuner (In%d)\n",
aud_input);
else
CX18_INFO_DEV(sd, "Specified audio input: External\n");
switch (pref_mode & 0xf) {
case 0: p = "mono/language A"; break;
case 1: p = "language B"; break;
case 2: p = "language C"; break;
case 3: p = "analog fallback"; break;
case 4: p = "stereo"; break;
case 5: p = "language AC"; break;
case 6: p = "language BC"; break;
case 7: p = "language AB"; break;
default: p = "undefined"; break;
}
CX18_INFO_DEV(sd, "Preferred audio mode: %s\n", p);
if ((audio_config & 0xf) == 0xf) {
switch ((afc0 >> 3) & 0x1) {
case 0: p = "system DK"; break;
case 1: p = "system L"; break;
}
CX18_INFO_DEV(sd, "Selected 65 MHz format: %s\n", p);
switch (afc0 & 0x7) {
case 0: p = "Chroma"; break;
case 1: p = "BTSC"; break;
case 2: p = "EIAJ"; break;
case 3: p = "A2-M"; break;
case 4: p = "autodetect"; break;
default: p = "undefined"; break;
}
CX18_INFO_DEV(sd, "Selected 45 MHz format: %s\n", p);
}
}
static int cx18_av_log_status(struct v4l2_subdev *sd)
{
struct cx18 *cx = v4l2_get_subdevdata(sd);
log_video_status(cx);
log_audio_status(cx);
return 0;
}
static int cx18_av_g_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct cx18 *cx = v4l2_get_subdevdata(sd);
if ((reg->reg & 0x3) != 0)
return -EINVAL;
reg->size = 4;
reg->val = cx18_av_read4(cx, reg->reg & 0x00000ffc);
return 0;
}
static int cx18_av_s_register(struct v4l2_subdev *sd,
const struct v4l2_dbg_register *reg)
{
struct cx18 *cx = v4l2_get_subdevdata(sd);
if ((reg->reg & 0x3) != 0)
return -EINVAL;
cx18_av_write4(cx, reg->reg & 0x00000ffc, reg->val);
return 0;
}
int cx18_av_probe(struct cx18 *cx)
{
struct cx18_av_state *state = &cx->av_state;
struct v4l2_subdev *sd;
int err;
state->rev = cx18_av_read4(cx, CXADEC_CHIP_CTRL) & 0xffff;
state->vid_input = CX18_AV_COMPOSITE7;
state->aud_input = CX18_AV_AUDIO8;
state->audclk_freq = 48000;
state->audmode = V4L2_TUNER_MODE_LANG1;
state->slicer_line_delay = 0;
state->slicer_line_offset = (10 + state->slicer_line_delay - 2);
sd = &state->sd;
v4l2_subdev_init(sd, &cx18_av_ops);
v4l2_set_subdevdata(sd, cx);
snprintf(sd->name, sizeof(sd->name),
"%s %03x", cx->v4l2_dev.name, (state->rev >> 4));
sd->grp_id = CX18_HW_418_AV;
v4l2_ctrl_handler_init(&state->hdl, 9);
v4l2_ctrl_new_std(&state->hdl, &cx18_av_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 255, 1, 128);
v4l2_ctrl_new_std(&state->hdl, &cx18_av_ctrl_ops,
V4L2_CID_CONTRAST, 0, 127, 1, 64);
v4l2_ctrl_new_std(&state->hdl, &cx18_av_ctrl_ops,
V4L2_CID_SATURATION, 0, 127, 1, 64);
v4l2_ctrl_new_std(&state->hdl, &cx18_av_ctrl_ops,
V4L2_CID_HUE, -128, 127, 1, 0);
state->volume = v4l2_ctrl_new_std(&state->hdl,
&cx18_av_audio_ctrl_ops, V4L2_CID_AUDIO_VOLUME,
0, 65535, 65535 / 100, 0);
v4l2_ctrl_new_std(&state->hdl,
&cx18_av_audio_ctrl_ops, V4L2_CID_AUDIO_MUTE,
0, 1, 1, 0);
v4l2_ctrl_new_std(&state->hdl, &cx18_av_audio_ctrl_ops,
V4L2_CID_AUDIO_BALANCE,
0, 65535, 65535 / 100, 32768);
v4l2_ctrl_new_std(&state->hdl, &cx18_av_audio_ctrl_ops,
V4L2_CID_AUDIO_BASS,
0, 65535, 65535 / 100, 32768);
v4l2_ctrl_new_std(&state->hdl, &cx18_av_audio_ctrl_ops,
V4L2_CID_AUDIO_TREBLE,
0, 65535, 65535 / 100, 32768);
sd->ctrl_handler = &state->hdl;
if (state->hdl.error) {
int err = state->hdl.error;
v4l2_ctrl_handler_free(&state->hdl);
return err;
}
err = v4l2_device_register_subdev(&cx->v4l2_dev, sd);
if (err)
v4l2_ctrl_handler_free(&state->hdl);
else
cx18_av_init(cx);
return err;
}
