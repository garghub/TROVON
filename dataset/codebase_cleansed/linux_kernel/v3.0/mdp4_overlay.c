void mdp4_overlay_dmap_cfg(struct msm_fb_data_type *mfd, int lcdc)
{
uint32 dma2_cfg_reg;
dma2_cfg_reg = DMA_DITHER_EN;
if (mfd->fb_imgType == MDP_BGR_565)
dma2_cfg_reg |= DMA_PACK_PATTERN_BGR;
else
dma2_cfg_reg |= DMA_PACK_PATTERN_RGB;
if (mfd->panel_info.bpp == 18) {
dma2_cfg_reg |= DMA_DSTC0G_6BITS |
DMA_DSTC1B_6BITS | DMA_DSTC2R_6BITS;
} else if (mfd->panel_info.bpp == 16) {
dma2_cfg_reg |= DMA_DSTC0G_6BITS |
DMA_DSTC1B_5BITS | DMA_DSTC2R_5BITS;
} else {
dma2_cfg_reg |= DMA_DSTC0G_8BITS |
DMA_DSTC1B_8BITS | DMA_DSTC2R_8BITS;
}
if (lcdc)
dma2_cfg_reg |= DMA_PACK_ALIGN_MSB;
MDP_OUTP(MDP_BASE + 0x90000, dma2_cfg_reg);
}
void mdp4_overlay_dmap_xy(struct mdp4_overlay_pipe *pipe)
{
MDP_OUTP(MDP_BASE + 0x90004,
(pipe->src_height << 16 | pipe->src_width));
MDP_OUTP(MDP_BASE + 0x90008, pipe->srcp0_addr);
MDP_OUTP(MDP_BASE + 0x9000c, pipe->srcp0_ystride);
MDP_OUTP(MDP_BASE + 0x90010, (pipe->dst_y << 16 | pipe->dst_x));
}
static int mdp4_leading_0(uint32 num)
{
uint32 bit = 0x80000000;
int i;
for (i = 0; i < 32; i++) {
if (bit & num)
return i;
bit >>= 1;
}
return i;
}
static uint32 mdp4_scale_phase_step(int f_num, uint32 src, uint32 dst)
{
uint32 val;
int n;
n = mdp4_leading_0(src);
if (n > f_num)
n = f_num;
val = src << n;
val /= dst;
if (n < f_num) {
n = f_num - n;
val <<= n;
}
return val;
}
static void mdp4_scale_setup(struct mdp4_overlay_pipe *pipe)
{
pipe->phasex_step = MDP4_VG_PHASE_STEP_DEFAULT;
pipe->phasey_step = MDP4_VG_PHASE_STEP_DEFAULT;
if (pipe->dst_h && pipe->src_h != pipe->dst_h) {
if (pipe->dst_h >= pipe->src_h * 8)
return;
pipe->op_mode |= MDP4_OP_SCALEY_EN;
if (pipe->pipe_type == OVERLAY_TYPE_VG) {
if (pipe->dst_h <= (pipe->src_h / 4))
pipe->op_mode |= MDP4_OP_SCALEY_MN_PHASE;
else
pipe->op_mode |= MDP4_OP_SCALEY_FIR;
}
pipe->phasey_step = mdp4_scale_phase_step(29,
pipe->src_h, pipe->dst_h);
}
if (pipe->dst_w && pipe->src_w != pipe->dst_w) {
if (pipe->dst_w >= pipe->src_w * 8)
return;
pipe->op_mode |= MDP4_OP_SCALEX_EN;
if (pipe->pipe_type == OVERLAY_TYPE_VG) {
if (pipe->dst_w <= (pipe->src_w / 4))
pipe->op_mode |= MDP4_OP_SCALEY_MN_PHASE;
else
pipe->op_mode |= MDP4_OP_SCALEY_FIR;
}
pipe->phasex_step = mdp4_scale_phase_step(29,
pipe->src_w, pipe->dst_w);
}
}
void mdp4_overlay_rgb_setup(struct mdp4_overlay_pipe *pipe)
{
char *rgb_base;
uint32 src_size, src_xy, dst_size, dst_xy;
uint32 format, pattern;
rgb_base = MDP_BASE + MDP4_RGB_BASE;
rgb_base += (MDP4_RGB_OFF * pipe->pipe_num);
src_size = ((pipe->src_h << 16) | pipe->src_w);
src_xy = ((pipe->src_y << 16) | pipe->src_x);
dst_size = ((pipe->dst_h << 16) | pipe->dst_w);
dst_xy = ((pipe->dst_y << 16) | pipe->dst_x);
format = mdp4_overlay_format(pipe);
pattern = mdp4_overlay_unpack_pattern(pipe);
pipe->op_mode |= MDP4_OP_IGC_LUT_EN;
mdp4_scale_setup(pipe);
outpdw(rgb_base + 0x0000, src_size);
outpdw(rgb_base + 0x0004, src_xy);
outpdw(rgb_base + 0x0008, dst_size);
outpdw(rgb_base + 0x000c, dst_xy);
outpdw(rgb_base + 0x0010, pipe->srcp0_addr);
outpdw(rgb_base + 0x0040, pipe->srcp0_ystride);
outpdw(rgb_base + 0x0050, format);
outpdw(rgb_base + 0x0054, pattern);
outpdw(rgb_base + 0x0058, pipe->op_mode);
outpdw(rgb_base + 0x005c, pipe->phasex_step);
outpdw(rgb_base + 0x0060, pipe->phasey_step);
outpdw(rgb_base + 0x1004, 0xc2);
}
void mdp4_overlay_vg_setup(struct mdp4_overlay_pipe *pipe)
{
char *vg_base;
uint32 frame_size, src_size, src_xy, dst_size, dst_xy;
uint32 format, pattern;
vg_base = MDP_BASE + MDP4_VIDEO_BASE;
vg_base += (MDP4_VIDEO_OFF * pipe->pipe_num);
frame_size = ((pipe->src_height << 16) | pipe->src_width);
src_size = ((pipe->src_h << 16) | pipe->src_w);
src_xy = ((pipe->src_y << 16) | pipe->src_x);
dst_size = ((pipe->dst_h << 16) | pipe->dst_w);
dst_xy = ((pipe->dst_y << 16) | pipe->dst_x);
format = mdp4_overlay_format(pipe);
pattern = mdp4_overlay_unpack_pattern(pipe);
pipe->op_mode |= (MDP4_OP_CSC_EN | MDP4_OP_SRC_DATA_YCBCR |
MDP4_OP_IGC_LUT_EN);
mdp4_scale_setup(pipe);
outpdw(vg_base + 0x0000, src_size);
outpdw(vg_base + 0x0004, src_xy);
outpdw(vg_base + 0x0008, dst_size);
outpdw(vg_base + 0x000c, dst_xy);
outpdw(vg_base + 0x0048, frame_size);
outpdw(vg_base + 0x0010, pipe->srcp0_addr);
outpdw(vg_base + 0x0014, pipe->srcp1_addr);
outpdw(vg_base + 0x0040,
pipe->srcp1_ystride << 16 | pipe->srcp0_ystride);
outpdw(vg_base + 0x0050, format);
outpdw(vg_base + 0x0054, pattern);
outpdw(vg_base + 0x0058, pipe->op_mode);
outpdw(vg_base + 0x005c, pipe->phasex_step);
outpdw(vg_base + 0x0060, pipe->phasey_step);
if (pipe->op_mode & MDP4_OP_DITHER_EN) {
outpdw(vg_base + 0x0068,
pipe->r_bit << 4 | pipe->b_bit << 2 | pipe->g_bit);
}
outpdw(vg_base + 0x1004, 0xc2);
}
int mdp4_overlay_format2type(uint32 format)
{
switch (format) {
case MDP_RGB_565:
case MDP_RGB_888:
case MDP_BGR_565:
case MDP_ARGB_8888:
case MDP_RGBA_8888:
case MDP_BGRA_8888:
return OVERLAY_TYPE_RGB;
case MDP_YCRYCB_H2V1:
case MDP_Y_CRCB_H2V1:
case MDP_Y_CBCR_H2V1:
case MDP_Y_CRCB_H2V2:
case MDP_Y_CBCR_H2V2:
case MDP_Y_CBCR_H2V2_TILE:
case MDP_Y_CRCB_H2V2_TILE:
return OVERLAY_TYPE_VG;
default:
return -ERANGE;
}
}
int mdp4_overlay_format2pipe(struct mdp4_overlay_pipe *pipe)
{
switch (pipe->src_format) {
case MDP_RGB_565:
pipe->frame_format = MDP4_FRAME_FORMAT_LINEAR;
pipe->fetch_plane = OVERLAY_PLANE_INTERLEAVED;
pipe->a_bit = 0;
pipe->r_bit = 1;
pipe->b_bit = 1;
pipe->g_bit = 2;
pipe->alpha_enable = 0;
pipe->unpack_tight = 1;
pipe->unpack_align_msb = 0;
pipe->unpack_count = 2;
pipe->element2 = C2_R_Cr;
pipe->element1 = C0_G_Y;
pipe->element0 = C1_B_Cb;
pipe->bpp = 2;
break;
case MDP_RGB_888:
pipe->frame_format = MDP4_FRAME_FORMAT_LINEAR;
pipe->fetch_plane = OVERLAY_PLANE_INTERLEAVED;
pipe->a_bit = 0;
pipe->r_bit = 3;
pipe->b_bit = 3;
pipe->g_bit = 3;
pipe->alpha_enable = 0;
pipe->unpack_tight = 1;
pipe->unpack_align_msb = 0;
pipe->unpack_count = 2;
pipe->element2 = C2_R_Cr;
pipe->element1 = C0_G_Y;
pipe->element0 = C1_B_Cb;
pipe->bpp = 3;
break;
case MDP_BGR_565:
pipe->frame_format = MDP4_FRAME_FORMAT_LINEAR;
pipe->fetch_plane = OVERLAY_PLANE_INTERLEAVED;
pipe->a_bit = 0;
pipe->r_bit = 1;
pipe->b_bit = 1;
pipe->g_bit = 2;
pipe->alpha_enable = 0;
pipe->unpack_tight = 1;
pipe->unpack_align_msb = 0;
pipe->unpack_count = 2;
pipe->element2 = C1_B_Cb;
pipe->element1 = C0_G_Y;
pipe->element0 = C2_R_Cr;
pipe->bpp = 2;
break;
case MDP_ARGB_8888:
pipe->frame_format = MDP4_FRAME_FORMAT_LINEAR;
pipe->fetch_plane = OVERLAY_PLANE_INTERLEAVED;
pipe->a_bit = 3;
pipe->r_bit = 3;
pipe->b_bit = 3;
pipe->g_bit = 3;
pipe->alpha_enable = 1;
pipe->unpack_tight = 1;
pipe->unpack_align_msb = 0;
pipe->unpack_count = 3;
pipe->element3 = C3_ALPHA;
pipe->element2 = C2_R_Cr;
pipe->element1 = C0_G_Y;
pipe->element0 = C1_B_Cb;
pipe->bpp = 4;
break;
case MDP_RGBA_8888:
pipe->frame_format = MDP4_FRAME_FORMAT_LINEAR;
pipe->fetch_plane = OVERLAY_PLANE_INTERLEAVED;
pipe->a_bit = 3;
pipe->r_bit = 3;
pipe->b_bit = 3;
pipe->g_bit = 3;
pipe->alpha_enable = 1;
pipe->unpack_tight = 1;
pipe->unpack_align_msb = 0;
pipe->unpack_count = 3;
pipe->element3 = C2_R_Cr;
pipe->element2 = C0_G_Y;
pipe->element1 = C1_B_Cb;
pipe->element0 = C3_ALPHA;
pipe->bpp = 4;
break;
case MDP_BGRA_8888:
pipe->frame_format = MDP4_FRAME_FORMAT_LINEAR;
pipe->fetch_plane = OVERLAY_PLANE_INTERLEAVED;
pipe->a_bit = 3;
pipe->r_bit = 3;
pipe->b_bit = 3;
pipe->g_bit = 3;
pipe->alpha_enable = 1;
pipe->unpack_tight = 1;
pipe->unpack_align_msb = 0;
pipe->unpack_count = 3;
pipe->element3 = C1_B_Cb;
pipe->element2 = C0_G_Y;
pipe->element1 = C2_R_Cr;
pipe->element0 = C3_ALPHA;
pipe->bpp = 4;
break;
case MDP_YCRYCB_H2V1:
pipe->frame_format = MDP4_FRAME_FORMAT_LINEAR;
pipe->fetch_plane = OVERLAY_PLANE_INTERLEAVED;
pipe->a_bit = 0;
pipe->r_bit = 3;
pipe->b_bit = 3;
pipe->g_bit = 3;
pipe->alpha_enable = 0;
pipe->unpack_tight = 1;
pipe->unpack_align_msb = 0;
pipe->unpack_count = 3;
pipe->element3 = C0_G_Y;
pipe->element2 = C2_R_Cr;
pipe->element1 = C0_G_Y;
pipe->element0 = C1_B_Cb;
pipe->bpp = 2;
pipe->chroma_sample = MDP4_CHROMA_H2V1;
break;
case MDP_Y_CRCB_H2V1:
case MDP_Y_CBCR_H2V1:
case MDP_Y_CRCB_H2V2:
case MDP_Y_CBCR_H2V2:
pipe->frame_format = MDP4_FRAME_FORMAT_LINEAR;
pipe->fetch_plane = OVERLAY_PLANE_PSEUDO_PLANAR;
pipe->a_bit = 0;
pipe->r_bit = 3;
pipe->b_bit = 3;
pipe->g_bit = 3;
pipe->alpha_enable = 0;
pipe->unpack_tight = 1;
pipe->unpack_align_msb = 0;
pipe->unpack_count = 1;
pipe->element3 = C0_G_Y;
pipe->element2 = C0_G_Y;
if (pipe->src_format == MDP_Y_CRCB_H2V1) {
pipe->element1 = C2_R_Cr;
pipe->element0 = C1_B_Cb;
pipe->chroma_sample = MDP4_CHROMA_H2V1;
} else if (pipe->src_format == MDP_Y_CBCR_H2V1) {
pipe->element1 = C1_B_Cb;
pipe->element0 = C2_R_Cr;
pipe->chroma_sample = MDP4_CHROMA_H2V1;
} else if (pipe->src_format == MDP_Y_CRCB_H2V2) {
pipe->element1 = C2_R_Cr;
pipe->element0 = C1_B_Cb;
pipe->chroma_sample = MDP4_CHROMA_420;
} else if (pipe->src_format == MDP_Y_CBCR_H2V2) {
pipe->element1 = C1_B_Cb;
pipe->element0 = C2_R_Cr;
pipe->chroma_sample = MDP4_CHROMA_420;
}
pipe->bpp = 2;
break;
case MDP_Y_CBCR_H2V2_TILE:
case MDP_Y_CRCB_H2V2_TILE:
pipe->frame_format = MDP4_FRAME_FORMAT_VIDEO_SUPERTILE;
pipe->fetch_plane = OVERLAY_PLANE_PSEUDO_PLANAR;
pipe->a_bit = 0;
pipe->r_bit = 3;
pipe->b_bit = 3;
pipe->g_bit = 3;
pipe->alpha_enable = 0;
pipe->unpack_tight = 1;
pipe->unpack_align_msb = 0;
pipe->unpack_count = 1;
pipe->element3 = C0_G_Y;
pipe->element2 = C0_G_Y;
if (pipe->src_format == MDP_Y_CRCB_H2V2_TILE) {
pipe->element1 = C2_R_Cr;
pipe->element0 = C1_B_Cb;
pipe->chroma_sample = MDP4_CHROMA_420;
} else if (pipe->src_format == MDP_Y_CBCR_H2V2_TILE) {
pipe->element1 = C1_B_Cb;
pipe->element0 = C2_R_Cr;
pipe->chroma_sample = MDP4_CHROMA_420;
}
pipe->bpp = 2;
break;
default:
return -ERANGE;
}
return 0;
}
static uint32 color_key_convert(int start, int num, uint32 color)
{
uint32 data;
data = (color >> start) & ((1 << num) - 1);
if (num == 5)
data = (data << 7) + (data << 2) + (data >> 3);
else if (num == 6)
data = (data << 6) + data;
else
data = (data << 4) + (data >> 4);
return data;
}
void transp_color_key(int format, uint32 transp,
uint32 *c0, uint32 *c1, uint32 *c2)
{
int b_start, g_start, r_start;
int b_num, g_num, r_num;
switch (format) {
case MDP_RGB_565:
b_start = 0;
g_start = 5;
r_start = 11;
r_num = 5;
g_num = 6;
b_num = 5;
break;
case MDP_RGB_888:
case MDP_XRGB_8888:
case MDP_ARGB_8888:
b_start = 0;
g_start = 8;
r_start = 16;
r_num = 8;
g_num = 8;
b_num = 8;
break;
case MDP_BGR_565:
b_start = 11;
g_start = 5;
r_start = 0;
r_num = 5;
g_num = 6;
b_num = 5;
break;
case MDP_Y_CBCR_H2V2:
case MDP_Y_CBCR_H2V1:
b_start = 8;
g_start = 16;
r_start = 0;
r_num = 8;
g_num = 8;
b_num = 8;
break;
case MDP_Y_CRCB_H2V2:
case MDP_Y_CRCB_H2V1:
b_start = 0;
g_start = 16;
r_start = 8;
r_num = 8;
g_num = 8;
b_num = 8;
break;
default:
b_start = 0;
g_start = 8;
r_start = 16;
r_num = 8;
g_num = 8;
b_num = 8;
break;
}
*c0 = color_key_convert(g_start, g_num, transp);
*c1 = color_key_convert(b_start, b_num, transp);
*c2 = color_key_convert(r_start, r_num, transp);
}
uint32 mdp4_overlay_format(struct mdp4_overlay_pipe *pipe)
{
uint32 format;
format = 0;
if (pipe->solid_fill)
format |= MDP4_FORMAT_SOLID_FILL;
if (pipe->unpack_align_msb)
format |= MDP4_FORMAT_UNPACK_ALIGN_MSB;
if (pipe->unpack_tight)
format |= MDP4_FORMAT_UNPACK_TIGHT;
if (pipe->alpha_enable)
format |= MDP4_FORMAT_ALPHA_ENABLE;
format |= (pipe->unpack_count << 13);
format |= ((pipe->bpp - 1) << 9);
format |= (pipe->a_bit << 6);
format |= (pipe->r_bit << 4);
format |= (pipe->b_bit << 2);
format |= pipe->g_bit;
format |= (pipe->frame_format << 29);
if (pipe->fetch_plane == OVERLAY_PLANE_PSEUDO_PLANAR) {
format |= (pipe->fetch_plane << 19);
format |= (pipe->chroma_site << 28);
format |= (pipe->chroma_sample << 26);
}
return format;
}
uint32 mdp4_overlay_unpack_pattern(struct mdp4_overlay_pipe *pipe)
{
return (pipe->element3 << 24) | (pipe->element2 << 16) |
(pipe->element1 << 8) | pipe->element0;
}
void mdp4_overlayproc_cfg(struct mdp4_overlay_pipe *pipe)
{
uint32 data;
char *overlay_base;
if (pipe->mixer_num == MDP4_MIXER1)
overlay_base = MDP_BASE + MDP4_OVERLAYPROC1_BASE;
else
overlay_base = MDP_BASE + MDP4_OVERLAYPROC0_BASE;
outpdw(overlay_base + 0x0004, 0x01);
data = pipe->src_height;
data <<= 16;
data |= pipe->src_width;
outpdw(overlay_base + 0x0008, data);
outpdw(overlay_base + 0x000c, pipe->srcp0_addr);
outpdw(overlay_base + 0x0010, pipe->srcp0_ystride);
outpdw(overlay_base + 0x0014, 0x4);
}
int mdp4_overlay_active(int mixer)
{
uint32 data, mask, i;
int p1, p2;
data = inpdw(MDP_BASE + 0x10100);
p1 = 0;
p2 = 0;
for (i = 0; i < 8; i++) {
mask = data & 0x0f;
if (mask) {
if (mask <= 4)
p1++;
else
p2++;
}
data >>= 4;
}
if (mixer)
return p2;
else
return p1;
}
void mdp4_mixer_stage_up(struct mdp4_overlay_pipe *pipe)
{
uint32 data, mask, snum, stage, mixer;
stage = pipe->mixer_stage;
mixer = pipe->mixer_num;
data = inpdw(MDP_BASE + 0x10100);
if (mixer == MDP4_MIXER1)
stage += 8;
if (pipe->pipe_type == OVERLAY_TYPE_VG) {
snum = 0;
snum += (4 * pipe->pipe_num);
} else {
snum = 8;
snum += (4 * pipe->pipe_num);
}
mask = 0x0f;
mask <<= snum;
stage <<= snum;
data &= ~mask;
data |= stage;
outpdw(MDP_BASE + 0x10100, data);
data = inpdw(MDP_BASE + 0x10100);
ctrl->stage[pipe->mixer_num][pipe->mixer_stage] = pipe;
}
void mdp4_mixer_stage_down(struct mdp4_overlay_pipe *pipe)
{
uint32 data, mask, snum, stage, mixer;
stage = pipe->mixer_stage;
mixer = pipe->mixer_num;
if (pipe != ctrl->stage[mixer][stage])
return;
data = inpdw(MDP_BASE + 0x10100);
if (mixer == MDP4_MIXER1)
stage += 8;
if (pipe->pipe_type == OVERLAY_TYPE_VG) {
snum = 0;
snum += (4 * pipe->pipe_num);
} else {
snum = 8;
snum += (4 * pipe->pipe_num);
}
mask = 0x0f;
mask <<= snum;
data &= ~mask;
outpdw(MDP_BASE + 0x10100, data);
data = inpdw(MDP_BASE + 0x10100);
ctrl->stage[pipe->mixer_num][pipe->mixer_stage] = NULL;
}
void mdp4_mixer_blend_setup(struct mdp4_overlay_pipe *pipe)
{
unsigned char *overlay_base;
uint32 c0, c1, c2, blend_op;
int off;
if (pipe->mixer_num)
overlay_base = MDP_BASE + MDP4_OVERLAYPROC1_BASE;
else
overlay_base = MDP_BASE + MDP4_OVERLAYPROC0_BASE;
off = 0x20 * (pipe->mixer_stage - MDP4_MIXER_STAGE0);
blend_op = 0;
if (pipe->alpha_enable)
blend_op = MDP4_BLEND_FG_ALPHA_FG_PIXEL |
MDP4_BLEND_BG_ALPHA_FG_PIXEL;
else
blend_op = (MDP4_BLEND_BG_ALPHA_BG_CONST |
MDP4_BLEND_FG_ALPHA_FG_CONST);
if (pipe->alpha_enable == 0) {
if (pipe->is_fg) {
outpdw(overlay_base + off + 0x108, pipe->alpha);
outpdw(overlay_base + off + 0x10c, 0xff - pipe->alpha);
} else {
outpdw(overlay_base + off + 0x108, 0xff - pipe->alpha);
outpdw(overlay_base + off + 0x10c, pipe->alpha);
}
}
if (pipe->transp != MDP_TRANSP_NOP) {
transp_color_key(pipe->src_format, pipe->transp, &c0, &c1, &c2);
if (pipe->is_fg) {
blend_op |= MDP4_BLEND_FG_TRANSP_EN;
if (c0 > 0x10)
c0 -= 0x10;
if (c1 > 0x10)
c1 -= 0x10;
if (c2 > 0x10)
c2 -= 0x10;
outpdw(overlay_base + off + 0x110,
(c1 << 16 | c0));
outpdw(overlay_base + off + 0x114, c2);
if ((c0 + 0x20) < 0x0fff)
c0 += 0x20;
else
c0 = 0x0fff;
if ((c1 + 0x20) < 0x0fff)
c1 += 0x20;
else
c1 = 0x0fff;
if ((c2 + 0x20) < 0x0fff)
c2 += 0x20;
else
c2 = 0x0fff;
outpdw(overlay_base + off + 0x118,
(c1 << 16 | c0));
outpdw(overlay_base + off + 0x11c, c2);
} else {
blend_op |= MDP4_BLEND_BG_TRANSP_EN;
if (c0 > 0x10)
c0 -= 0x10;
if (c1 > 0x10)
c1 -= 0x10;
if (c2 > 0x10)
c2 -= 0x10;
outpdw(overlay_base + 0x180,
(c1 << 16 | c0));
outpdw(overlay_base + 0x184, c2);
if ((c0 + 0x20) < 0x0fff)
c0 += 0x20;
else
c0 = 0x0fff;
if ((c1 + 0x20) < 0x0fff)
c1 += 0x20;
else
c1 = 0x0fff;
if ((c2 + 0x20) < 0x0fff)
c2 += 0x20;
else
c2 = 0x0fff;
outpdw(overlay_base + 0x188,
(c1 << 16 | c0));
outpdw(overlay_base + 0x18c, c2);
}
}
outpdw(overlay_base + off + 0x104, blend_op);
}
void mdp4_overlay_reg_flush(struct mdp4_overlay_pipe *pipe, int all)
{
uint32 bits = 0;
if (pipe->mixer_num == MDP4_MIXER1)
bits |= 0x02;
else
bits |= 0x01;
if (all) {
if (pipe->pipe_type == OVERLAY_TYPE_RGB) {
if (pipe->pipe_num == OVERLAY_PIPE_RGB2)
bits |= 0x20;
else
bits |= 0x10;
} else {
if (pipe->pipe_num == OVERLAY_PIPE_VG2)
bits |= 0x08;
else
bits |= 0x04;
}
}
outpdw(MDP_BASE + 0x18000, bits);
while (inpdw(MDP_BASE + 0x18000) & bits)
;
}
struct mdp4_overlay_pipe *mdp4_overlay_ndx2pipe(int ndx)
{
struct mdp4_overlay_pipe *pipe;
if (ndx == 0 || ndx >= MDP4_MAX_OVERLAY_PIPE)
return NULL;
pipe = &ctrl->plist[ndx - 1];
if (pipe->pipe_ndx == 0)
return NULL;
return pipe;
}
struct mdp4_overlay_pipe *mdp4_overlay_pipe_alloc(void)
{
int i;
struct mdp4_overlay_pipe *pipe;
pipe = &ctrl->plist[0];
for (i = 0; i < MDP4_MAX_OVERLAY_PIPE; i++) {
if (pipe->pipe_ndx == 0) {
pipe->pipe_ndx = i + 1;
init_completion(&pipe->comp);
printk(KERN_INFO "mdp4_overlay_pipe_alloc: pipe=%p ndx=%d\n",
pipe, pipe->pipe_ndx);
return pipe;
}
pipe++;
}
return NULL;
}
void mdp4_overlay_pipe_free(struct mdp4_overlay_pipe *pipe)
{
printk(KERN_INFO "mdp4_overlay_pipe_free: pipe=%p ndx=%d\n",
pipe, pipe->pipe_ndx);
memset(pipe, 0, sizeof(*pipe));
}
static int get_pipe_num(int ptype, int stage)
{
if (ptype == OVERLAY_TYPE_RGB) {
if (stage == MDP4_MIXER_STAGE_BASE)
return OVERLAY_PIPE_RGB1;
else
return OVERLAY_PIPE_RGB2;
} else {
if (stage == MDP4_MIXER_STAGE0)
return OVERLAY_PIPE_VG1;
else
return OVERLAY_PIPE_VG2;
}
}
int mdp4_overlay_req_check(uint32 id, uint32 z_order, uint32 mixer)
{
struct mdp4_overlay_pipe *pipe;
pipe = ctrl->stage[mixer][z_order];
if (pipe == NULL)
return 0;
if (pipe->pipe_ndx == id)
return 0;
return -EPERM;
}
static int mdp4_overlay_req2pipe(struct mdp_overlay *req, int mixer,
struct mdp4_overlay_pipe **ppipe)
{
struct mdp4_overlay_pipe *pipe;
int ret, ptype;
if (mixer >= MDP4_MAX_MIXER) {
printk(KERN_ERR "mpd_overlay_req2pipe: mixer out of range!\n");
return -ERANGE;
}
if (req->z_order < 0 || req->z_order > 2) {
printk(KERN_ERR "mpd_overlay_req2pipe: z_order=%d out of range!\n",
req->z_order);
return -ERANGE;
}
if (req->src_rect.h == 0 || req->src_rect.w == 0) {
printk(KERN_ERR "mpd_overlay_req2pipe: src img of zero size!\n");
return -EINVAL;
}
ret = mdp4_overlay_req_check(req->id, req->z_order, mixer);
if (ret < 0)
return ret;
ptype = mdp4_overlay_format2type(req->src.format);
if (ptype < 0)
return ptype;
if (req->id == MSMFB_NEW_REQUEST)
pipe = mdp4_overlay_pipe_alloc();
else
pipe = mdp4_overlay_ndx2pipe(req->id);
if (pipe == NULL)
return -ENOMEM;
pipe->src_format = req->src.format;
ret = mdp4_overlay_format2pipe(pipe);
if (ret < 0)
return ret;
if (req->id == MSMFB_NEW_REQUEST) {
pipe->mixer_stage = req->z_order + MDP4_MIXER_STAGE0;
pipe->pipe_type = ptype;
pipe->pipe_num = get_pipe_num(ptype, pipe->mixer_stage);
printk(KERN_INFO "mpd4_overlay_req2pipe: zorder=%d pipe_num=%d\n",
req->z_order, pipe->pipe_num);
}
pipe->src_width = req->src.width & 0x07ff;
pipe->src_height = req->src.height & 0x07ff;
pipe->src_h = req->src_rect.h & 0x07ff;
pipe->src_w = req->src_rect.w & 0x07ff;
pipe->src_y = req->src_rect.y & 0x07ff;
pipe->src_x = req->src_rect.x & 0x07ff;
pipe->dst_h = req->dst_rect.h & 0x07ff;
pipe->dst_w = req->dst_rect.w & 0x07ff;
pipe->dst_y = req->dst_rect.y & 0x07ff;
pipe->dst_x = req->dst_rect.x & 0x07ff;
if (req->flags & MDP_FLIP_LR)
pipe->op_mode |= MDP4_OP_FLIP_LR;
if (req->flags & MDP_FLIP_UD)
pipe->op_mode |= MDP4_OP_FLIP_UD;
if (req->flags & MDP_DITHER)
pipe->op_mode |= MDP4_OP_DITHER_EN;
if (req->flags & MDP_DEINTERLACE)
pipe->op_mode |= MDP4_OP_DEINT_ODD_REF;
pipe->is_fg = req->is_fg;
pipe->alpha = req->alpha & 0x0ff;
pipe->transp = req->transp_mask;
*ppipe = pipe;
return 0;
}
int get_img(struct msmfb_data *img, struct fb_info *info,
unsigned long *start, unsigned long *len, struct file **pp_file)
{
int put_needed, ret = 0;
struct file *file;
#ifdef CONFIG_ANDROID_PMEM
unsigned long vstart;
#endif
#ifdef CONFIG_ANDROID_PMEM
if (!get_pmem_file(img->memory_id, start, &vstart, len, pp_file))
return 0;
#endif
file = fget_light(img->memory_id, &put_needed);
if (file == NULL)
return -1;
if (MAJOR(file->f_dentry->d_inode->i_rdev) == FB_MAJOR) {
*start = info->fix.smem_start;
*len = info->fix.smem_len;
*pp_file = file;
} else {
ret = -1;
fput_light(file, put_needed);
}
return ret;
}
int mdp4_overlay_get(struct fb_info *info, struct mdp_overlay *req)
{
struct mdp4_overlay_pipe *pipe;
pipe = mdp4_overlay_ndx2pipe(req->id);
if (pipe == NULL)
return -ENODEV;
*req = pipe->req_data;
return 0;
}
int mdp4_overlay_set(struct fb_info *info, struct mdp_overlay *req)
{
struct msm_fb_data_type *mfd = (struct msm_fb_data_type *)info->par;
int ret, mixer;
struct mdp4_overlay_pipe *pipe;
int lcdc;
if (mfd == NULL)
return -ENODEV;
if (req->src.format == MDP_FB_FORMAT)
req->src.format = mfd->fb_imgType;
if (mutex_lock_interruptible(&mfd->dma->ov_mutex))
return -EINTR;
mixer = info->node;
ret = mdp4_overlay_req2pipe(req, mixer, &pipe);
if (ret < 0) {
mutex_unlock(&mfd->dma->ov_mutex);
return ret;
}
lcdc = inpdw(MDP_BASE + 0xc0000);
if (lcdc == 0) {
mdp_pipe_ctrl(MDP_CMD_BLOCK, MDP_BLOCK_POWER_ON, FALSE);
}
req->id = pipe->pipe_ndx;
pipe->req_data = *req;
mutex_unlock(&mfd->dma->ov_mutex);
return 0;
}
int mdp4_overlay_unset(struct fb_info *info, int ndx)
{
struct msm_fb_data_type *mfd = (struct msm_fb_data_type *)info->par;
struct mdp4_overlay_pipe *pipe;
int lcdc;
if (mfd == NULL)
return -ENODEV;
if (mutex_lock_interruptible(&mfd->dma->ov_mutex))
return -EINTR;
pipe = mdp4_overlay_ndx2pipe(ndx);
if (pipe == NULL) {
mutex_unlock(&mfd->dma->ov_mutex);
return -ENODEV;
}
lcdc = inpdw(MDP_BASE + 0xc0000);
mdp4_mixer_stage_down(pipe);
if (lcdc == 0) {
mdp_pipe_ctrl(MDP_CMD_BLOCK, MDP_BLOCK_POWER_OFF, FALSE);
}
if (lcdc)
mdp4_overlay_reg_flush(pipe, 0);
mdp4_overlay_pipe_free(pipe);
if (lcdc == 0) {
mdp4_mddi_overlay_restore();
}
mutex_unlock(&mfd->dma->ov_mutex);
return 0;
}
void tile_samsung(struct tile_desc *tp)
{
tp->width = 64;
tp->row_tile_w = 2;
tp->height = 32;
tp->row_tile_h = 1;
}
uint32 tile_mem_size(struct mdp4_overlay_pipe *pipe, struct tile_desc *tp)
{
uint32 tile_w, tile_h;
uint32 row_num_w, row_num_h;
tile_w = tp->width * tp->row_tile_w;
tile_h = tp->height * tp->row_tile_h;
row_num_w = (pipe->src_width + tile_w - 1) / tile_w;
row_num_h = (pipe->src_height + tile_h - 1) / tile_h;
return row_num_w * row_num_h * tile_w * tile_h;
}
int mdp4_overlay_play(struct fb_info *info, struct msmfb_overlay_data *req,
struct file **pp_src_file)
{
struct msm_fb_data_type *mfd = (struct msm_fb_data_type *)info->par;
struct msmfb_data *img;
struct mdp4_overlay_pipe *pipe;
ulong start, addr;
ulong len = 0;
struct file *p_src_file = 0;
int lcdc;
if (mfd == NULL)
return -ENODEV;
pipe = mdp4_overlay_ndx2pipe(req->id);
if (pipe == NULL)
return -ENODEV;
if (mutex_lock_interruptible(&mfd->dma->ov_mutex))
return -EINTR;
img = &req->data;
get_img(img, info, &start, &len, &p_src_file);
if (len == 0) {
mutex_unlock(&mfd->dma->ov_mutex);
printk(KERN_ERR "mdp_overlay_play: could not retrieve"
" image from memory\n");
return -1;
}
*pp_src_file = p_src_file;
addr = start + img->offset;
pipe->srcp0_addr = addr;
pipe->srcp0_ystride = pipe->src_width * pipe->bpp;
if (pipe->fetch_plane == OVERLAY_PLANE_PSEUDO_PLANAR) {
if (pipe->frame_format == MDP4_FRAME_FORMAT_VIDEO_SUPERTILE) {
struct tile_desc tile;
tile_samsung(&tile);
pipe->srcp1_addr = addr + tile_mem_size(pipe, &tile);
} else
pipe->srcp1_addr = addr +
pipe->src_width * pipe->src_height;
pipe->srcp0_ystride = pipe->src_width;
pipe->srcp1_ystride = pipe->src_width;
}
lcdc = inpdw(MDP_BASE + 0xc0000);
lcdc &= 0x01;
if (pipe->pipe_type == OVERLAY_TYPE_VG)
mdp4_overlay_vg_setup(pipe);
else
mdp4_overlay_rgb_setup(pipe);
mdp4_mixer_blend_setup(pipe);
mdp4_mixer_stage_up(pipe);
if (lcdc) {
mdp4_overlay_reg_flush(pipe, 1);
}
if (lcdc) {
if (pipe->mixer_stage != MDP4_MIXER_STAGE_BASE) {
mutex_unlock(&mfd->dma->ov_mutex);
return 0;
}
}
if (lcdc == 0) {
#ifdef MDP4_NONBLOCKING
if (mfd->panel_power_on)
#else
if (!mfd->dma->busy && mfd->panel_power_on)
#endif
mdp4_mddi_overlay_kickoff(mfd, pipe);
}
mutex_unlock(&mfd->dma->ov_mutex);
return 0;
}
