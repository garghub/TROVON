static __inline__ int radeon_check_and_fixup_offset(drm_radeon_private_t *
dev_priv,
struct drm_file * file_priv,
u32 *offset)
{
u64 off = *offset;
u32 fb_end = dev_priv->fb_location + dev_priv->fb_size - 1;
struct drm_radeon_driver_file_fields *radeon_priv;
if (radeon_check_offset(dev_priv, off))
return 0;
if (off < (dev_priv->fb_size + dev_priv->gart_size)) {
radeon_priv = file_priv->driver_priv;
off += radeon_priv->radeon_fb_delta;
}
if (off > fb_end)
off = off - fb_end - 1 + dev_priv->gart_vm_start;
if (radeon_check_offset(dev_priv, off)) {
DRM_DEBUG("offset fixed up to 0x%x\n", (unsigned int)off);
*offset = off;
return 0;
}
return -EINVAL;
}
static __inline__ int radeon_check_and_fixup_packets(drm_radeon_private_t *
dev_priv,
struct drm_file *file_priv,
int id, struct drm_buffer *buf)
{
u32 *data;
switch (id) {
case RADEON_EMIT_PP_MISC:
data = drm_buffer_pointer_to_dword(buf,
(RADEON_RB3D_DEPTHOFFSET - RADEON_PP_MISC) / 4);
if (radeon_check_and_fixup_offset(dev_priv, file_priv, data)) {
DRM_ERROR("Invalid depth buffer offset\n");
return -EINVAL;
}
dev_priv->have_z_offset = 1;
break;
case RADEON_EMIT_PP_CNTL:
data = drm_buffer_pointer_to_dword(buf,
(RADEON_RB3D_COLOROFFSET - RADEON_PP_CNTL) / 4);
if (radeon_check_and_fixup_offset(dev_priv, file_priv, data)) {
DRM_ERROR("Invalid colour buffer offset\n");
return -EINVAL;
}
break;
case R200_EMIT_PP_TXOFFSET_0:
case R200_EMIT_PP_TXOFFSET_1:
case R200_EMIT_PP_TXOFFSET_2:
case R200_EMIT_PP_TXOFFSET_3:
case R200_EMIT_PP_TXOFFSET_4:
case R200_EMIT_PP_TXOFFSET_5:
data = drm_buffer_pointer_to_dword(buf, 0);
if (radeon_check_and_fixup_offset(dev_priv, file_priv, data)) {
DRM_ERROR("Invalid R200 texture offset\n");
return -EINVAL;
}
break;
case RADEON_EMIT_PP_TXFILTER_0:
case RADEON_EMIT_PP_TXFILTER_1:
case RADEON_EMIT_PP_TXFILTER_2:
data = drm_buffer_pointer_to_dword(buf,
(RADEON_PP_TXOFFSET_0 - RADEON_PP_TXFILTER_0) / 4);
if (radeon_check_and_fixup_offset(dev_priv, file_priv, data)) {
DRM_ERROR("Invalid R100 texture offset\n");
return -EINVAL;
}
break;
case R200_EMIT_PP_CUBIC_OFFSETS_0:
case R200_EMIT_PP_CUBIC_OFFSETS_1:
case R200_EMIT_PP_CUBIC_OFFSETS_2:
case R200_EMIT_PP_CUBIC_OFFSETS_3:
case R200_EMIT_PP_CUBIC_OFFSETS_4:
case R200_EMIT_PP_CUBIC_OFFSETS_5:{
int i;
for (i = 0; i < 5; i++) {
data = drm_buffer_pointer_to_dword(buf, i);
if (radeon_check_and_fixup_offset(dev_priv,
file_priv,
data)) {
DRM_ERROR
("Invalid R200 cubic texture offset\n");
return -EINVAL;
}
}
break;
}
case RADEON_EMIT_PP_CUBIC_OFFSETS_T0:
case RADEON_EMIT_PP_CUBIC_OFFSETS_T1:
case RADEON_EMIT_PP_CUBIC_OFFSETS_T2:{
int i;
for (i = 0; i < 5; i++) {
data = drm_buffer_pointer_to_dword(buf, i);
if (radeon_check_and_fixup_offset(dev_priv,
file_priv,
data)) {
DRM_ERROR
("Invalid R100 cubic texture offset\n");
return -EINVAL;
}
}
}
break;
case R200_EMIT_VAP_CTL:{
RING_LOCALS;
BEGIN_RING(2);
OUT_RING_REG(RADEON_SE_TCL_STATE_FLUSH, 0);
ADVANCE_RING();
}
break;
case RADEON_EMIT_RB3D_COLORPITCH:
case RADEON_EMIT_RE_LINE_PATTERN:
case RADEON_EMIT_SE_LINE_WIDTH:
case RADEON_EMIT_PP_LUM_MATRIX:
case RADEON_EMIT_PP_ROT_MATRIX_0:
case RADEON_EMIT_RB3D_STENCILREFMASK:
case RADEON_EMIT_SE_VPORT_XSCALE:
case RADEON_EMIT_SE_CNTL:
case RADEON_EMIT_SE_CNTL_STATUS:
case RADEON_EMIT_RE_MISC:
case RADEON_EMIT_PP_BORDER_COLOR_0:
case RADEON_EMIT_PP_BORDER_COLOR_1:
case RADEON_EMIT_PP_BORDER_COLOR_2:
case RADEON_EMIT_SE_ZBIAS_FACTOR:
case RADEON_EMIT_SE_TCL_OUTPUT_VTX_FMT:
case RADEON_EMIT_SE_TCL_MATERIAL_EMMISSIVE_RED:
case R200_EMIT_PP_TXCBLEND_0:
case R200_EMIT_PP_TXCBLEND_1:
case R200_EMIT_PP_TXCBLEND_2:
case R200_EMIT_PP_TXCBLEND_3:
case R200_EMIT_PP_TXCBLEND_4:
case R200_EMIT_PP_TXCBLEND_5:
case R200_EMIT_PP_TXCBLEND_6:
case R200_EMIT_PP_TXCBLEND_7:
case R200_EMIT_TCL_LIGHT_MODEL_CTL_0:
case R200_EMIT_TFACTOR_0:
case R200_EMIT_VTX_FMT_0:
case R200_EMIT_MATRIX_SELECT_0:
case R200_EMIT_TEX_PROC_CTL_2:
case R200_EMIT_TCL_UCP_VERT_BLEND_CTL:
case R200_EMIT_PP_TXFILTER_0:
case R200_EMIT_PP_TXFILTER_1:
case R200_EMIT_PP_TXFILTER_2:
case R200_EMIT_PP_TXFILTER_3:
case R200_EMIT_PP_TXFILTER_4:
case R200_EMIT_PP_TXFILTER_5:
case R200_EMIT_VTE_CNTL:
case R200_EMIT_OUTPUT_VTX_COMP_SEL:
case R200_EMIT_PP_TAM_DEBUG3:
case R200_EMIT_PP_CNTL_X:
case R200_EMIT_RB3D_DEPTHXY_OFFSET:
case R200_EMIT_RE_AUX_SCISSOR_CNTL:
case R200_EMIT_RE_SCISSOR_TL_0:
case R200_EMIT_RE_SCISSOR_TL_1:
case R200_EMIT_RE_SCISSOR_TL_2:
case R200_EMIT_SE_VAP_CNTL_STATUS:
case R200_EMIT_SE_VTX_STATE_CNTL:
case R200_EMIT_RE_POINTSIZE:
case R200_EMIT_TCL_INPUT_VTX_VECTOR_ADDR_0:
case R200_EMIT_PP_CUBIC_FACES_0:
case R200_EMIT_PP_CUBIC_FACES_1:
case R200_EMIT_PP_CUBIC_FACES_2:
case R200_EMIT_PP_CUBIC_FACES_3:
case R200_EMIT_PP_CUBIC_FACES_4:
case R200_EMIT_PP_CUBIC_FACES_5:
case RADEON_EMIT_PP_TEX_SIZE_0:
case RADEON_EMIT_PP_TEX_SIZE_1:
case RADEON_EMIT_PP_TEX_SIZE_2:
case R200_EMIT_RB3D_BLENDCOLOR:
case R200_EMIT_TCL_POINT_SPRITE_CNTL:
case RADEON_EMIT_PP_CUBIC_FACES_0:
case RADEON_EMIT_PP_CUBIC_FACES_1:
case RADEON_EMIT_PP_CUBIC_FACES_2:
case R200_EMIT_PP_TRI_PERF_CNTL:
case R200_EMIT_PP_AFS_0:
case R200_EMIT_PP_AFS_1:
case R200_EMIT_ATF_TFACTOR:
case R200_EMIT_PP_TXCTLALL_0:
case R200_EMIT_PP_TXCTLALL_1:
case R200_EMIT_PP_TXCTLALL_2:
case R200_EMIT_PP_TXCTLALL_3:
case R200_EMIT_PP_TXCTLALL_4:
case R200_EMIT_PP_TXCTLALL_5:
case R200_EMIT_VAP_PVS_CNTL:
break;
default:
DRM_ERROR("Unknown state packet ID %d\n", id);
return -EINVAL;
}
return 0;
}
static int radeon_check_and_fixup_packet3(drm_radeon_private_t *
dev_priv,
struct drm_file *file_priv,
drm_radeon_kcmd_buffer_t *
cmdbuf,
unsigned int *cmdsz)
{
u32 *cmd = drm_buffer_pointer_to_dword(cmdbuf->buffer, 0);
u32 offset, narrays;
int count, i, k;
count = ((*cmd & RADEON_CP_PACKET_COUNT_MASK) >> 16);
*cmdsz = 2 + count;
if ((*cmd & 0xc0000000) != RADEON_CP_PACKET3) {
DRM_ERROR("Not a type 3 packet\n");
return -EINVAL;
}
if (4 * *cmdsz > drm_buffer_unprocessed(cmdbuf->buffer)) {
DRM_ERROR("Packet size larger than size of data provided\n");
return -EINVAL;
}
switch (*cmd & 0xff00) {
case RADEON_3D_DRAW_IMMD:
case RADEON_3D_DRAW_VBUF:
case RADEON_3D_DRAW_INDX:
case RADEON_WAIT_FOR_IDLE:
case RADEON_CP_NOP:
case RADEON_3D_CLEAR_ZMASK:
break;
case RADEON_CP_3D_DRAW_IMMD_2:
case RADEON_CP_3D_DRAW_VBUF_2:
case RADEON_CP_3D_DRAW_INDX_2:
case RADEON_3D_CLEAR_HIZ:
if (dev_priv->microcode_version != UCODE_R200) {
DRM_ERROR("Invalid 3d packet for r100-class chip\n");
return -EINVAL;
}
break;
case RADEON_3D_LOAD_VBPNTR:
if (count > 18) {
DRM_ERROR("Too large payload in 3D_LOAD_VBPNTR (count=%d)\n",
count);
return -EINVAL;
}
cmd = drm_buffer_pointer_to_dword(cmdbuf->buffer, 1);
narrays = *cmd & ~0xc000;
k = 0;
i = 2;
while ((k < narrays) && (i < (count + 2))) {
i++;
cmd = drm_buffer_pointer_to_dword(cmdbuf->buffer, i);
if (radeon_check_and_fixup_offset(dev_priv, file_priv,
cmd)) {
DRM_ERROR
("Invalid offset (k=%d i=%d) in 3D_LOAD_VBPNTR packet.\n",
k, i);
return -EINVAL;
}
k++;
i++;
if (k == narrays)
break;
cmd = drm_buffer_pointer_to_dword(cmdbuf->buffer, i);
if (radeon_check_and_fixup_offset(dev_priv,
file_priv, cmd))
{
DRM_ERROR
("Invalid offset (k=%d i=%d) in 3D_LOAD_VBPNTR packet.\n",
k, i);
return -EINVAL;
}
k++;
i++;
}
if ((k != narrays) || (i != (count + 2))) {
DRM_ERROR
("Malformed 3D_LOAD_VBPNTR packet (k=%d i=%d narrays=%d count+1=%d).\n",
k, i, narrays, count + 1);
return -EINVAL;
}
break;
case RADEON_3D_RNDR_GEN_INDX_PRIM:
if (dev_priv->microcode_version != UCODE_R100) {
DRM_ERROR("Invalid 3d packet for r200-class chip\n");
return -EINVAL;
}
cmd = drm_buffer_pointer_to_dword(cmdbuf->buffer, 1);
if (radeon_check_and_fixup_offset(dev_priv, file_priv, cmd)) {
DRM_ERROR("Invalid rndr_gen_indx offset\n");
return -EINVAL;
}
break;
case RADEON_CP_INDX_BUFFER:
if (dev_priv->microcode_version != UCODE_R200) {
DRM_ERROR("Invalid 3d packet for r100-class chip\n");
return -EINVAL;
}
cmd = drm_buffer_pointer_to_dword(cmdbuf->buffer, 1);
if ((*cmd & 0x8000ffff) != 0x80000810) {
DRM_ERROR("Invalid indx_buffer reg address %08X\n", *cmd);
return -EINVAL;
}
cmd = drm_buffer_pointer_to_dword(cmdbuf->buffer, 2);
if (radeon_check_and_fixup_offset(dev_priv, file_priv, cmd)) {
DRM_ERROR("Invalid indx_buffer offset is %08X\n", *cmd);
return -EINVAL;
}
break;
case RADEON_CNTL_HOSTDATA_BLT:
case RADEON_CNTL_PAINT_MULTI:
case RADEON_CNTL_BITBLT_MULTI:
cmd = drm_buffer_pointer_to_dword(cmdbuf->buffer, 1);
if (*cmd & (RADEON_GMC_SRC_PITCH_OFFSET_CNTL
| RADEON_GMC_DST_PITCH_OFFSET_CNTL)) {
u32 *cmd2 = drm_buffer_pointer_to_dword(cmdbuf->buffer, 2);
offset = *cmd2 << 10;
if (radeon_check_and_fixup_offset
(dev_priv, file_priv, &offset)) {
DRM_ERROR("Invalid first packet offset\n");
return -EINVAL;
}
*cmd2 = (*cmd2 & 0xffc00000) | offset >> 10;
}
if ((*cmd & RADEON_GMC_SRC_PITCH_OFFSET_CNTL) &&
(*cmd & RADEON_GMC_DST_PITCH_OFFSET_CNTL)) {
u32 *cmd3 = drm_buffer_pointer_to_dword(cmdbuf->buffer, 3);
offset = *cmd3 << 10;
if (radeon_check_and_fixup_offset
(dev_priv, file_priv, &offset)) {
DRM_ERROR("Invalid second packet offset\n");
return -EINVAL;
}
*cmd3 = (*cmd3 & 0xffc00000) | offset >> 10;
}
break;
default:
DRM_ERROR("Invalid packet type %x\n", *cmd & 0xff00);
return -EINVAL;
}
return 0;
}
static void radeon_emit_clip_rect(drm_radeon_private_t * dev_priv,
struct drm_clip_rect * box)
{
RING_LOCALS;
DRM_DEBUG(" box: x1=%d y1=%d x2=%d y2=%d\n",
box->x1, box->y1, box->x2, box->y2);
BEGIN_RING(4);
OUT_RING(CP_PACKET0(RADEON_RE_TOP_LEFT, 0));
OUT_RING((box->y1 << 16) | box->x1);
OUT_RING(CP_PACKET0(RADEON_RE_WIDTH_HEIGHT, 0));
OUT_RING(((box->y2 - 1) << 16) | (box->x2 - 1));
ADVANCE_RING();
}
static int radeon_emit_state(drm_radeon_private_t * dev_priv,
struct drm_file *file_priv,
drm_radeon_context_regs_t * ctx,
drm_radeon_texture_regs_t * tex,
unsigned int dirty)
{
RING_LOCALS;
DRM_DEBUG("dirty=0x%08x\n", dirty);
if (dirty & RADEON_UPLOAD_CONTEXT) {
if (radeon_check_and_fixup_offset(dev_priv, file_priv,
&ctx->rb3d_depthoffset)) {
DRM_ERROR("Invalid depth buffer offset\n");
return -EINVAL;
}
if (radeon_check_and_fixup_offset(dev_priv, file_priv,
&ctx->rb3d_coloroffset)) {
DRM_ERROR("Invalid depth buffer offset\n");
return -EINVAL;
}
BEGIN_RING(14);
OUT_RING(CP_PACKET0(RADEON_PP_MISC, 6));
OUT_RING(ctx->pp_misc);
OUT_RING(ctx->pp_fog_color);
OUT_RING(ctx->re_solid_color);
OUT_RING(ctx->rb3d_blendcntl);
OUT_RING(ctx->rb3d_depthoffset);
OUT_RING(ctx->rb3d_depthpitch);
OUT_RING(ctx->rb3d_zstencilcntl);
OUT_RING(CP_PACKET0(RADEON_PP_CNTL, 2));
OUT_RING(ctx->pp_cntl);
OUT_RING(ctx->rb3d_cntl);
OUT_RING(ctx->rb3d_coloroffset);
OUT_RING(CP_PACKET0(RADEON_RB3D_COLORPITCH, 0));
OUT_RING(ctx->rb3d_colorpitch);
ADVANCE_RING();
}
if (dirty & RADEON_UPLOAD_VERTFMT) {
BEGIN_RING(2);
OUT_RING(CP_PACKET0(RADEON_SE_COORD_FMT, 0));
OUT_RING(ctx->se_coord_fmt);
ADVANCE_RING();
}
if (dirty & RADEON_UPLOAD_LINE) {
BEGIN_RING(5);
OUT_RING(CP_PACKET0(RADEON_RE_LINE_PATTERN, 1));
OUT_RING(ctx->re_line_pattern);
OUT_RING(ctx->re_line_state);
OUT_RING(CP_PACKET0(RADEON_SE_LINE_WIDTH, 0));
OUT_RING(ctx->se_line_width);
ADVANCE_RING();
}
if (dirty & RADEON_UPLOAD_BUMPMAP) {
BEGIN_RING(5);
OUT_RING(CP_PACKET0(RADEON_PP_LUM_MATRIX, 0));
OUT_RING(ctx->pp_lum_matrix);
OUT_RING(CP_PACKET0(RADEON_PP_ROT_MATRIX_0, 1));
OUT_RING(ctx->pp_rot_matrix_0);
OUT_RING(ctx->pp_rot_matrix_1);
ADVANCE_RING();
}
if (dirty & RADEON_UPLOAD_MASKS) {
BEGIN_RING(4);
OUT_RING(CP_PACKET0(RADEON_RB3D_STENCILREFMASK, 2));
OUT_RING(ctx->rb3d_stencilrefmask);
OUT_RING(ctx->rb3d_ropcntl);
OUT_RING(ctx->rb3d_planemask);
ADVANCE_RING();
}
if (dirty & RADEON_UPLOAD_VIEWPORT) {
BEGIN_RING(7);
OUT_RING(CP_PACKET0(RADEON_SE_VPORT_XSCALE, 5));
OUT_RING(ctx->se_vport_xscale);
OUT_RING(ctx->se_vport_xoffset);
OUT_RING(ctx->se_vport_yscale);
OUT_RING(ctx->se_vport_yoffset);
OUT_RING(ctx->se_vport_zscale);
OUT_RING(ctx->se_vport_zoffset);
ADVANCE_RING();
}
if (dirty & RADEON_UPLOAD_SETUP) {
BEGIN_RING(4);
OUT_RING(CP_PACKET0(RADEON_SE_CNTL, 0));
OUT_RING(ctx->se_cntl);
OUT_RING(CP_PACKET0(RADEON_SE_CNTL_STATUS, 0));
OUT_RING(ctx->se_cntl_status);
ADVANCE_RING();
}
if (dirty & RADEON_UPLOAD_MISC) {
BEGIN_RING(2);
OUT_RING(CP_PACKET0(RADEON_RE_MISC, 0));
OUT_RING(ctx->re_misc);
ADVANCE_RING();
}
if (dirty & RADEON_UPLOAD_TEX0) {
if (radeon_check_and_fixup_offset(dev_priv, file_priv,
&tex[0].pp_txoffset)) {
DRM_ERROR("Invalid texture offset for unit 0\n");
return -EINVAL;
}
BEGIN_RING(9);
OUT_RING(CP_PACKET0(RADEON_PP_TXFILTER_0, 5));
OUT_RING(tex[0].pp_txfilter);
OUT_RING(tex[0].pp_txformat);
OUT_RING(tex[0].pp_txoffset);
OUT_RING(tex[0].pp_txcblend);
OUT_RING(tex[0].pp_txablend);
OUT_RING(tex[0].pp_tfactor);
OUT_RING(CP_PACKET0(RADEON_PP_BORDER_COLOR_0, 0));
OUT_RING(tex[0].pp_border_color);
ADVANCE_RING();
}
if (dirty & RADEON_UPLOAD_TEX1) {
if (radeon_check_and_fixup_offset(dev_priv, file_priv,
&tex[1].pp_txoffset)) {
DRM_ERROR("Invalid texture offset for unit 1\n");
return -EINVAL;
}
BEGIN_RING(9);
OUT_RING(CP_PACKET0(RADEON_PP_TXFILTER_1, 5));
OUT_RING(tex[1].pp_txfilter);
OUT_RING(tex[1].pp_txformat);
OUT_RING(tex[1].pp_txoffset);
OUT_RING(tex[1].pp_txcblend);
OUT_RING(tex[1].pp_txablend);
OUT_RING(tex[1].pp_tfactor);
OUT_RING(CP_PACKET0(RADEON_PP_BORDER_COLOR_1, 0));
OUT_RING(tex[1].pp_border_color);
ADVANCE_RING();
}
if (dirty & RADEON_UPLOAD_TEX2) {
if (radeon_check_and_fixup_offset(dev_priv, file_priv,
&tex[2].pp_txoffset)) {
DRM_ERROR("Invalid texture offset for unit 2\n");
return -EINVAL;
}
BEGIN_RING(9);
OUT_RING(CP_PACKET0(RADEON_PP_TXFILTER_2, 5));
OUT_RING(tex[2].pp_txfilter);
OUT_RING(tex[2].pp_txformat);
OUT_RING(tex[2].pp_txoffset);
OUT_RING(tex[2].pp_txcblend);
OUT_RING(tex[2].pp_txablend);
OUT_RING(tex[2].pp_tfactor);
OUT_RING(CP_PACKET0(RADEON_PP_BORDER_COLOR_2, 0));
OUT_RING(tex[2].pp_border_color);
ADVANCE_RING();
}
return 0;
}
static int radeon_emit_state2(drm_radeon_private_t * dev_priv,
struct drm_file *file_priv,
drm_radeon_state_t * state)
{
RING_LOCALS;
if (state->dirty & RADEON_UPLOAD_ZBIAS) {
BEGIN_RING(3);
OUT_RING(CP_PACKET0(RADEON_SE_ZBIAS_FACTOR, 1));
OUT_RING(state->context2.se_zbias_factor);
OUT_RING(state->context2.se_zbias_constant);
ADVANCE_RING();
}
return radeon_emit_state(dev_priv, file_priv, &state->context,
state->tex, state->dirty);
}
static void radeon_clear_box(drm_radeon_private_t * dev_priv,
struct drm_radeon_master_private *master_priv,
int x, int y, int w, int h, int r, int g, int b)
{
u32 color;
RING_LOCALS;
x += master_priv->sarea_priv->boxes[0].x1;
y += master_priv->sarea_priv->boxes[0].y1;
switch (dev_priv->color_fmt) {
case RADEON_COLOR_FORMAT_RGB565:
color = (((r & 0xf8) << 8) |
((g & 0xfc) << 3) | ((b & 0xf8) >> 3));
break;
case RADEON_COLOR_FORMAT_ARGB8888:
default:
color = (((0xff) << 24) | (r << 16) | (g << 8) | b);
break;
}
BEGIN_RING(4);
RADEON_WAIT_UNTIL_3D_IDLE();
OUT_RING(CP_PACKET0(RADEON_DP_WRITE_MASK, 0));
OUT_RING(0xffffffff);
ADVANCE_RING();
BEGIN_RING(6);
OUT_RING(CP_PACKET3(RADEON_CNTL_PAINT_MULTI, 4));
OUT_RING(RADEON_GMC_DST_PITCH_OFFSET_CNTL |
RADEON_GMC_BRUSH_SOLID_COLOR |
(dev_priv->color_fmt << 8) |
RADEON_GMC_SRC_DATATYPE_COLOR |
RADEON_ROP3_P | RADEON_GMC_CLR_CMP_CNTL_DIS);
if (master_priv->sarea_priv->pfCurrentPage == 1) {
OUT_RING(dev_priv->front_pitch_offset);
} else {
OUT_RING(dev_priv->back_pitch_offset);
}
OUT_RING(color);
OUT_RING((x << 16) | y);
OUT_RING((w << 16) | h);
ADVANCE_RING();
}
static void radeon_cp_performance_boxes(drm_radeon_private_t *dev_priv, struct drm_radeon_master_private *master_priv)
{
if (dev_priv->stats.last_frame_reads > 1 ||
dev_priv->stats.last_clear_reads > dev_priv->stats.clears) {
dev_priv->stats.boxes |= RADEON_BOX_WAIT_IDLE;
}
if (dev_priv->stats.freelist_loops) {
dev_priv->stats.boxes |= RADEON_BOX_WAIT_IDLE;
}
if (dev_priv->stats.boxes & RADEON_BOX_FLIP)
radeon_clear_box(dev_priv, master_priv, 4, 4, 8, 8, 255, 0, 255);
if (dev_priv->stats.boxes & RADEON_BOX_WAIT_IDLE)
radeon_clear_box(dev_priv, master_priv, 16, 4, 8, 8, 255, 0, 0);
if (dev_priv->stats.boxes & RADEON_BOX_TEXTURE_LOAD)
radeon_clear_box(dev_priv, master_priv, 40, 4, 8, 8, 255, 255, 0);
if (!(dev_priv->stats.boxes & RADEON_BOX_DMA_IDLE))
radeon_clear_box(dev_priv, master_priv, 64, 4, 8, 8, 0, 255, 0);
if (dev_priv->stats.requested_bufs) {
if (dev_priv->stats.requested_bufs > 100)
dev_priv->stats.requested_bufs = 100;
radeon_clear_box(dev_priv, master_priv, 4, 16,
dev_priv->stats.requested_bufs, 4,
196, 128, 128);
}
memset(&dev_priv->stats, 0, sizeof(dev_priv->stats));
}
static void radeon_cp_dispatch_clear(struct drm_device * dev,
struct drm_master *master,
drm_radeon_clear_t * clear,
drm_radeon_clear_rect_t * depth_boxes)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
struct drm_radeon_master_private *master_priv = master->driver_priv;
drm_radeon_sarea_t *sarea_priv = master_priv->sarea_priv;
drm_radeon_depth_clear_t *depth_clear = &dev_priv->depth_clear;
int nbox = sarea_priv->nbox;
struct drm_clip_rect *pbox = sarea_priv->boxes;
unsigned int flags = clear->flags;
u32 rb3d_cntl = 0, rb3d_stencilrefmask = 0;
int i;
RING_LOCALS;
DRM_DEBUG("flags = 0x%x\n", flags);
dev_priv->stats.clears++;
if (sarea_priv->pfCurrentPage == 1) {
unsigned int tmp = flags;
flags &= ~(RADEON_FRONT | RADEON_BACK);
if (tmp & RADEON_FRONT)
flags |= RADEON_BACK;
if (tmp & RADEON_BACK)
flags |= RADEON_FRONT;
}
if (flags & (RADEON_DEPTH|RADEON_STENCIL)) {
if (!dev_priv->have_z_offset) {
printk_once(KERN_ERR "radeon: illegal depth clear request. Buggy mesa detected - please update.\n");
flags &= ~(RADEON_DEPTH | RADEON_STENCIL);
}
}
if (flags & (RADEON_FRONT | RADEON_BACK)) {
BEGIN_RING(4);
RADEON_WAIT_UNTIL_3D_IDLE();
OUT_RING(CP_PACKET0(RADEON_DP_WRITE_MASK, 0));
OUT_RING(clear->color_mask);
ADVANCE_RING();
sarea_priv->ctx_owner = 0;
for (i = 0; i < nbox; i++) {
int x = pbox[i].x1;
int y = pbox[i].y1;
int w = pbox[i].x2 - x;
int h = pbox[i].y2 - y;
DRM_DEBUG("%d,%d-%d,%d flags 0x%x\n",
x, y, w, h, flags);
if (flags & RADEON_FRONT) {
BEGIN_RING(6);
OUT_RING(CP_PACKET3
(RADEON_CNTL_PAINT_MULTI, 4));
OUT_RING(RADEON_GMC_DST_PITCH_OFFSET_CNTL |
RADEON_GMC_BRUSH_SOLID_COLOR |
(dev_priv->
color_fmt << 8) |
RADEON_GMC_SRC_DATATYPE_COLOR |
RADEON_ROP3_P |
RADEON_GMC_CLR_CMP_CNTL_DIS);
OUT_RING(dev_priv->front_pitch_offset);
OUT_RING(clear->clear_color);
OUT_RING((x << 16) | y);
OUT_RING((w << 16) | h);
ADVANCE_RING();
}
if (flags & RADEON_BACK) {
BEGIN_RING(6);
OUT_RING(CP_PACKET3
(RADEON_CNTL_PAINT_MULTI, 4));
OUT_RING(RADEON_GMC_DST_PITCH_OFFSET_CNTL |
RADEON_GMC_BRUSH_SOLID_COLOR |
(dev_priv->
color_fmt << 8) |
RADEON_GMC_SRC_DATATYPE_COLOR |
RADEON_ROP3_P |
RADEON_GMC_CLR_CMP_CNTL_DIS);
OUT_RING(dev_priv->back_pitch_offset);
OUT_RING(clear->clear_color);
OUT_RING((x << 16) | y);
OUT_RING((w << 16) | h);
ADVANCE_RING();
}
}
}
if ((flags & (RADEON_DEPTH | RADEON_STENCIL))
&& (flags & RADEON_CLEAR_FASTZ)) {
int i;
int depthpixperline =
dev_priv->depth_fmt ==
RADEON_DEPTH_FORMAT_16BIT_INT_Z ? (dev_priv->depth_pitch /
2) : (dev_priv->
depth_pitch / 4);
u32 clearmask;
u32 tempRB3D_DEPTHCLEARVALUE = clear->clear_depth |
((clear->depth_mask & 0xff) << 24);
sarea_priv->ctx_owner = 0;
if ((dev_priv->flags & RADEON_HAS_HIERZ)
&& (flags & RADEON_USE_HIERZ)) {
clearmask = (0xff << 22) | (0xff << 6) | 0x003f003f;
} else {
clearmask = 0x0;
}
BEGIN_RING(8);
RADEON_WAIT_UNTIL_2D_IDLE();
OUT_RING_REG(RADEON_RB3D_DEPTHCLEARVALUE,
tempRB3D_DEPTHCLEARVALUE);
OUT_RING_REG(RADEON_RB3D_ZMASKOFFSET, 0);
OUT_RING_REG(RADEON_RB3D_ZCACHE_CTLSTAT,
RADEON_RB3D_ZC_FLUSH_ALL);
ADVANCE_RING();
for (i = 0; i < nbox; i++) {
int tileoffset, nrtilesx, nrtilesy, j;
if ((dev_priv->flags & RADEON_HAS_HIERZ)
&& !(dev_priv->microcode_version == UCODE_R200)) {
tileoffset =
((pbox[i].y1 >> 3) * depthpixperline +
pbox[i].x1) >> 6;
nrtilesx =
((pbox[i].x2 & ~63) -
(pbox[i].x1 & ~63)) >> 4;
nrtilesy =
(pbox[i].y2 >> 3) - (pbox[i].y1 >> 3);
for (j = 0; j <= nrtilesy; j++) {
BEGIN_RING(4);
OUT_RING(CP_PACKET3
(RADEON_3D_CLEAR_ZMASK, 2));
OUT_RING(tileoffset * 8);
OUT_RING(nrtilesx + 4);
OUT_RING(clearmask);
ADVANCE_RING();
tileoffset += depthpixperline >> 6;
}
} else if (dev_priv->microcode_version == UCODE_R200) {
tileoffset =
((pbox[i].y1 >> 3) * depthpixperline +
pbox[i].x1) >> 5;
nrtilesx =
(pbox[i].x2 >> 5) - (pbox[i].x1 >> 5);
nrtilesy =
(pbox[i].y2 >> 3) - (pbox[i].y1 >> 3);
for (j = 0; j <= nrtilesy; j++) {
BEGIN_RING(4);
OUT_RING(CP_PACKET3
(RADEON_3D_CLEAR_ZMASK, 2));
OUT_RING(tileoffset * 16);
OUT_RING(nrtilesx + 1);
OUT_RING(clearmask);
ADVANCE_RING();
tileoffset += depthpixperline >> 5;
}
} else {
tileoffset =
((pbox[i].y1 >> 4) * depthpixperline +
pbox[i].x1) >> 6;
nrtilesx =
((pbox[i].x2 & ~63) -
(pbox[i].x1 & ~63)) >> 4;
nrtilesy =
(pbox[i].y2 >> 4) - (pbox[i].y1 >> 4);
for (j = 0; j <= nrtilesy; j++) {
BEGIN_RING(4);
OUT_RING(CP_PACKET3
(RADEON_3D_CLEAR_ZMASK, 2));
OUT_RING(tileoffset * 128);
OUT_RING(nrtilesx + 4);
OUT_RING(clearmask);
ADVANCE_RING();
tileoffset += depthpixperline >> 6;
}
}
}
if ((dev_priv->flags & RADEON_HAS_HIERZ)
&& (dev_priv->microcode_version == UCODE_R200)
&& (flags & RADEON_USE_HIERZ))
{
BEGIN_RING(4);
OUT_RING(CP_PACKET3(RADEON_3D_CLEAR_HIZ, 2));
OUT_RING(0x0);
OUT_RING(0x3cc0);
OUT_RING((0xff << 22) | (0xff << 6) | 0x003f003f);
ADVANCE_RING();
}
}
else if ((dev_priv->microcode_version == UCODE_R200) &&
(flags & (RADEON_DEPTH | RADEON_STENCIL))) {
int tempPP_CNTL;
int tempRE_CNTL;
int tempRB3D_CNTL;
int tempRB3D_ZSTENCILCNTL;
int tempRB3D_STENCILREFMASK;
int tempRB3D_PLANEMASK;
int tempSE_CNTL;
int tempSE_VTE_CNTL;
int tempSE_VTX_FMT_0;
int tempSE_VTX_FMT_1;
int tempSE_VAP_CNTL;
int tempRE_AUX_SCISSOR_CNTL;
tempPP_CNTL = 0;
tempRE_CNTL = 0;
tempRB3D_CNTL = depth_clear->rb3d_cntl;
tempRB3D_ZSTENCILCNTL = depth_clear->rb3d_zstencilcntl;
tempRB3D_STENCILREFMASK = 0x0;
tempSE_CNTL = depth_clear->se_cntl;
tempSE_VAP_CNTL = (
(0x9 <<
SE_VAP_CNTL__VF_MAX_VTX_NUM__SHIFT));
tempRB3D_PLANEMASK = 0x0;
tempRE_AUX_SCISSOR_CNTL = 0x0;
tempSE_VTE_CNTL =
SE_VTE_CNTL__VTX_XY_FMT_MASK | SE_VTE_CNTL__VTX_Z_FMT_MASK;
tempSE_VTX_FMT_0 =
SE_VTX_FMT_0__VTX_Z0_PRESENT_MASK |
SE_VTX_FMT_0__VTX_W0_PRESENT_MASK;
tempSE_VTX_FMT_1 = 0x0;
if (flags & RADEON_DEPTH) {
tempRB3D_CNTL |= RADEON_Z_ENABLE;
} else {
tempRB3D_CNTL &= ~RADEON_Z_ENABLE;
}
if (flags & RADEON_STENCIL) {
tempRB3D_CNTL |= RADEON_STENCIL_ENABLE;
tempRB3D_STENCILREFMASK = clear->depth_mask;
} else {
tempRB3D_CNTL &= ~RADEON_STENCIL_ENABLE;
tempRB3D_STENCILREFMASK = 0x00000000;
}
if (flags & RADEON_USE_COMP_ZBUF) {
tempRB3D_ZSTENCILCNTL |= RADEON_Z_COMPRESSION_ENABLE |
RADEON_Z_DECOMPRESSION_ENABLE;
}
if (flags & RADEON_USE_HIERZ) {
tempRB3D_ZSTENCILCNTL |= RADEON_Z_HIERARCHY_ENABLE;
}
BEGIN_RING(26);
RADEON_WAIT_UNTIL_2D_IDLE();
OUT_RING_REG(RADEON_PP_CNTL, tempPP_CNTL);
OUT_RING_REG(R200_RE_CNTL, tempRE_CNTL);
OUT_RING_REG(RADEON_RB3D_CNTL, tempRB3D_CNTL);
OUT_RING_REG(RADEON_RB3D_ZSTENCILCNTL, tempRB3D_ZSTENCILCNTL);
OUT_RING_REG(RADEON_RB3D_STENCILREFMASK,
tempRB3D_STENCILREFMASK);
OUT_RING_REG(RADEON_RB3D_PLANEMASK, tempRB3D_PLANEMASK);
OUT_RING_REG(RADEON_SE_CNTL, tempSE_CNTL);
OUT_RING_REG(R200_SE_VTE_CNTL, tempSE_VTE_CNTL);
OUT_RING_REG(R200_SE_VTX_FMT_0, tempSE_VTX_FMT_0);
OUT_RING_REG(R200_SE_VTX_FMT_1, tempSE_VTX_FMT_1);
OUT_RING_REG(R200_SE_VAP_CNTL, tempSE_VAP_CNTL);
OUT_RING_REG(R200_RE_AUX_SCISSOR_CNTL, tempRE_AUX_SCISSOR_CNTL);
ADVANCE_RING();
sarea_priv->ctx_owner = 0;
for (i = 0; i < nbox; i++) {
radeon_emit_clip_rect(dev_priv, &sarea_priv->boxes[i]);
BEGIN_RING(14);
OUT_RING(CP_PACKET3(R200_3D_DRAW_IMMD_2, 12));
OUT_RING((RADEON_PRIM_TYPE_RECT_LIST |
RADEON_PRIM_WALK_RING |
(3 << RADEON_NUM_VERTICES_SHIFT)));
OUT_RING(depth_boxes[i].ui[CLEAR_X1]);
OUT_RING(depth_boxes[i].ui[CLEAR_Y1]);
OUT_RING(depth_boxes[i].ui[CLEAR_DEPTH]);
OUT_RING(0x3f800000);
OUT_RING(depth_boxes[i].ui[CLEAR_X1]);
OUT_RING(depth_boxes[i].ui[CLEAR_Y2]);
OUT_RING(depth_boxes[i].ui[CLEAR_DEPTH]);
OUT_RING(0x3f800000);
OUT_RING(depth_boxes[i].ui[CLEAR_X2]);
OUT_RING(depth_boxes[i].ui[CLEAR_Y2]);
OUT_RING(depth_boxes[i].ui[CLEAR_DEPTH]);
OUT_RING(0x3f800000);
ADVANCE_RING();
}
} else if ((flags & (RADEON_DEPTH | RADEON_STENCIL))) {
int tempRB3D_ZSTENCILCNTL = depth_clear->rb3d_zstencilcntl;
rb3d_cntl = depth_clear->rb3d_cntl;
if (flags & RADEON_DEPTH) {
rb3d_cntl |= RADEON_Z_ENABLE;
} else {
rb3d_cntl &= ~RADEON_Z_ENABLE;
}
if (flags & RADEON_STENCIL) {
rb3d_cntl |= RADEON_STENCIL_ENABLE;
rb3d_stencilrefmask = clear->depth_mask;
} else {
rb3d_cntl &= ~RADEON_STENCIL_ENABLE;
rb3d_stencilrefmask = 0x00000000;
}
if (flags & RADEON_USE_COMP_ZBUF) {
tempRB3D_ZSTENCILCNTL |= RADEON_Z_COMPRESSION_ENABLE |
RADEON_Z_DECOMPRESSION_ENABLE;
}
if (flags & RADEON_USE_HIERZ) {
tempRB3D_ZSTENCILCNTL |= RADEON_Z_HIERARCHY_ENABLE;
}
BEGIN_RING(13);
RADEON_WAIT_UNTIL_2D_IDLE();
OUT_RING(CP_PACKET0(RADEON_PP_CNTL, 1));
OUT_RING(0x00000000);
OUT_RING(rb3d_cntl);
OUT_RING_REG(RADEON_RB3D_ZSTENCILCNTL, tempRB3D_ZSTENCILCNTL);
OUT_RING_REG(RADEON_RB3D_STENCILREFMASK, rb3d_stencilrefmask);
OUT_RING_REG(RADEON_RB3D_PLANEMASK, 0x00000000);
OUT_RING_REG(RADEON_SE_CNTL, depth_clear->se_cntl);
ADVANCE_RING();
sarea_priv->ctx_owner = 0;
for (i = 0; i < nbox; i++) {
radeon_emit_clip_rect(dev_priv, &sarea_priv->boxes[i]);
BEGIN_RING(15);
OUT_RING(CP_PACKET3(RADEON_3D_DRAW_IMMD, 13));
OUT_RING(RADEON_VTX_Z_PRESENT |
RADEON_VTX_PKCOLOR_PRESENT);
OUT_RING((RADEON_PRIM_TYPE_RECT_LIST |
RADEON_PRIM_WALK_RING |
RADEON_MAOS_ENABLE |
RADEON_VTX_FMT_RADEON_MODE |
(3 << RADEON_NUM_VERTICES_SHIFT)));
OUT_RING(depth_boxes[i].ui[CLEAR_X1]);
OUT_RING(depth_boxes[i].ui[CLEAR_Y1]);
OUT_RING(depth_boxes[i].ui[CLEAR_DEPTH]);
OUT_RING(0x0);
OUT_RING(depth_boxes[i].ui[CLEAR_X1]);
OUT_RING(depth_boxes[i].ui[CLEAR_Y2]);
OUT_RING(depth_boxes[i].ui[CLEAR_DEPTH]);
OUT_RING(0x0);
OUT_RING(depth_boxes[i].ui[CLEAR_X2]);
OUT_RING(depth_boxes[i].ui[CLEAR_Y2]);
OUT_RING(depth_boxes[i].ui[CLEAR_DEPTH]);
OUT_RING(0x0);
ADVANCE_RING();
}
}
sarea_priv->last_clear++;
BEGIN_RING(4);
RADEON_CLEAR_AGE(sarea_priv->last_clear);
RADEON_WAIT_UNTIL_IDLE();
ADVANCE_RING();
}
static void radeon_cp_dispatch_swap(struct drm_device *dev, struct drm_master *master)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
struct drm_radeon_master_private *master_priv = master->driver_priv;
drm_radeon_sarea_t *sarea_priv = master_priv->sarea_priv;
int nbox = sarea_priv->nbox;
struct drm_clip_rect *pbox = sarea_priv->boxes;
int i;
RING_LOCALS;
DRM_DEBUG("\n");
if (dev_priv->do_boxes)
radeon_cp_performance_boxes(dev_priv, master_priv);
BEGIN_RING(2);
RADEON_WAIT_UNTIL_3D_IDLE();
ADVANCE_RING();
for (i = 0; i < nbox; i++) {
int x = pbox[i].x1;
int y = pbox[i].y1;
int w = pbox[i].x2 - x;
int h = pbox[i].y2 - y;
DRM_DEBUG("%d,%d-%d,%d\n", x, y, w, h);
BEGIN_RING(9);
OUT_RING(CP_PACKET0(RADEON_DP_GUI_MASTER_CNTL, 0));
OUT_RING(RADEON_GMC_SRC_PITCH_OFFSET_CNTL |
RADEON_GMC_DST_PITCH_OFFSET_CNTL |
RADEON_GMC_BRUSH_NONE |
(dev_priv->color_fmt << 8) |
RADEON_GMC_SRC_DATATYPE_COLOR |
RADEON_ROP3_S |
RADEON_DP_SRC_SOURCE_MEMORY |
RADEON_GMC_CLR_CMP_CNTL_DIS | RADEON_GMC_WR_MSK_DIS);
OUT_RING(CP_PACKET0(RADEON_SRC_PITCH_OFFSET, 1));
if (sarea_priv->pfCurrentPage == 0) {
OUT_RING(dev_priv->back_pitch_offset);
OUT_RING(dev_priv->front_pitch_offset);
} else {
OUT_RING(dev_priv->front_pitch_offset);
OUT_RING(dev_priv->back_pitch_offset);
}
OUT_RING(CP_PACKET0(RADEON_SRC_X_Y, 2));
OUT_RING((x << 16) | y);
OUT_RING((x << 16) | y);
OUT_RING((w << 16) | h);
ADVANCE_RING();
}
sarea_priv->last_frame++;
BEGIN_RING(4);
RADEON_FRAME_AGE(sarea_priv->last_frame);
RADEON_WAIT_UNTIL_2D_IDLE();
ADVANCE_RING();
}
void radeon_cp_dispatch_flip(struct drm_device *dev, struct drm_master *master)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
struct drm_radeon_master_private *master_priv = master->driver_priv;
struct drm_sarea *sarea = (struct drm_sarea *)master_priv->sarea->handle;
int offset = (master_priv->sarea_priv->pfCurrentPage == 1)
? dev_priv->front_offset : dev_priv->back_offset;
RING_LOCALS;
DRM_DEBUG("pfCurrentPage=%d\n",
master_priv->sarea_priv->pfCurrentPage);
if (dev_priv->do_boxes) {
dev_priv->stats.boxes |= RADEON_BOX_FLIP;
radeon_cp_performance_boxes(dev_priv, master_priv);
}
BEGIN_RING(6);
RADEON_WAIT_UNTIL_3D_IDLE();
OUT_RING_REG(RADEON_CRTC_OFFSET,
((sarea->frame.y * dev_priv->front_pitch +
sarea->frame.x * (dev_priv->color_fmt - 2)) & ~7)
+ offset);
OUT_RING_REG(RADEON_CRTC2_OFFSET, master_priv->sarea_priv->crtc2_base
+ offset);
ADVANCE_RING();
master_priv->sarea_priv->last_frame++;
master_priv->sarea_priv->pfCurrentPage =
1 - master_priv->sarea_priv->pfCurrentPage;
BEGIN_RING(2);
RADEON_FRAME_AGE(master_priv->sarea_priv->last_frame);
ADVANCE_RING();
}
static int bad_prim_vertex_nr(int primitive, int nr)
{
switch (primitive & RADEON_PRIM_TYPE_MASK) {
case RADEON_PRIM_TYPE_NONE:
case RADEON_PRIM_TYPE_POINT:
return nr < 1;
case RADEON_PRIM_TYPE_LINE:
return (nr & 1) || nr == 0;
case RADEON_PRIM_TYPE_LINE_STRIP:
return nr < 2;
case RADEON_PRIM_TYPE_TRI_LIST:
case RADEON_PRIM_TYPE_3VRT_POINT_LIST:
case RADEON_PRIM_TYPE_3VRT_LINE_LIST:
case RADEON_PRIM_TYPE_RECT_LIST:
return nr % 3 || nr == 0;
case RADEON_PRIM_TYPE_TRI_FAN:
case RADEON_PRIM_TYPE_TRI_STRIP:
return nr < 3;
default:
return 1;
}
}
static void radeon_cp_dispatch_vertex(struct drm_device * dev,
struct drm_file *file_priv,
struct drm_buf * buf,
drm_radeon_tcl_prim_t * prim)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
struct drm_radeon_master_private *master_priv = file_priv->master->driver_priv;
drm_radeon_sarea_t *sarea_priv = master_priv->sarea_priv;
int offset = dev_priv->gart_buffers_offset + buf->offset + prim->start;
int numverts = (int)prim->numverts;
int nbox = sarea_priv->nbox;
int i = 0;
RING_LOCALS;
DRM_DEBUG("hwprim 0x%x vfmt 0x%x %d..%d %d verts\n",
prim->prim,
prim->vc_format, prim->start, prim->finish, prim->numverts);
if (bad_prim_vertex_nr(prim->prim, prim->numverts)) {
DRM_ERROR("bad prim %x numverts %d\n",
prim->prim, prim->numverts);
return;
}
do {
if (i < nbox) {
radeon_emit_clip_rect(dev_priv, &sarea_priv->boxes[i]);
}
BEGIN_RING(5);
OUT_RING(CP_PACKET3(RADEON_3D_RNDR_GEN_INDX_PRIM, 3));
OUT_RING(offset);
OUT_RING(numverts);
OUT_RING(prim->vc_format);
OUT_RING(prim->prim | RADEON_PRIM_WALK_LIST |
RADEON_COLOR_ORDER_RGBA |
RADEON_VTX_FMT_RADEON_MODE |
(numverts << RADEON_NUM_VERTICES_SHIFT));
ADVANCE_RING();
i++;
} while (i < nbox);
}
void radeon_cp_discard_buffer(struct drm_device *dev, struct drm_master *master, struct drm_buf *buf)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
struct drm_radeon_master_private *master_priv = master->driver_priv;
drm_radeon_buf_priv_t *buf_priv = buf->dev_private;
RING_LOCALS;
buf_priv->age = ++master_priv->sarea_priv->last_dispatch;
if ((dev_priv->flags & RADEON_FAMILY_MASK) >= CHIP_R600) {
BEGIN_RING(3);
R600_DISPATCH_AGE(buf_priv->age);
ADVANCE_RING();
} else {
BEGIN_RING(2);
RADEON_DISPATCH_AGE(buf_priv->age);
ADVANCE_RING();
}
buf->pending = 1;
buf->used = 0;
}
static void radeon_cp_dispatch_indirect(struct drm_device * dev,
struct drm_buf * buf, int start, int end)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
RING_LOCALS;
DRM_DEBUG("buf=%d s=0x%x e=0x%x\n", buf->idx, start, end);
if (start != end) {
int offset = (dev_priv->gart_buffers_offset
+ buf->offset + start);
int dwords = (end - start + 3) / sizeof(u32);
if (dwords & 1) {
u32 *data = (u32 *)
((char *)dev->agp_buffer_map->handle
+ buf->offset + start);
data[dwords++] = RADEON_CP_PACKET2;
}
BEGIN_RING(3);
OUT_RING(CP_PACKET0(RADEON_CP_IB_BASE, 1));
OUT_RING(offset);
OUT_RING(dwords);
ADVANCE_RING();
}
}
static void radeon_cp_dispatch_indices(struct drm_device *dev,
struct drm_master *master,
struct drm_buf * elt_buf,
drm_radeon_tcl_prim_t * prim)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
struct drm_radeon_master_private *master_priv = master->driver_priv;
drm_radeon_sarea_t *sarea_priv = master_priv->sarea_priv;
int offset = dev_priv->gart_buffers_offset + prim->offset;
u32 *data;
int dwords;
int i = 0;
int start = prim->start + RADEON_INDEX_PRIM_OFFSET;
int count = (prim->finish - start) / sizeof(u16);
int nbox = sarea_priv->nbox;
DRM_DEBUG("hwprim 0x%x vfmt 0x%x %d..%d offset: %x nr %d\n",
prim->prim,
prim->vc_format,
prim->start, prim->finish, prim->offset, prim->numverts);
if (bad_prim_vertex_nr(prim->prim, count)) {
DRM_ERROR("bad prim %x count %d\n", prim->prim, count);
return;
}
if (start >= prim->finish || (prim->start & 0x7)) {
DRM_ERROR("buffer prim %d\n", prim->prim);
return;
}
dwords = (prim->finish - prim->start + 3) / sizeof(u32);
data = (u32 *) ((char *)dev->agp_buffer_map->handle +
elt_buf->offset + prim->start);
data[0] = CP_PACKET3(RADEON_3D_RNDR_GEN_INDX_PRIM, dwords - 2);
data[1] = offset;
data[2] = prim->numverts;
data[3] = prim->vc_format;
data[4] = (prim->prim |
RADEON_PRIM_WALK_IND |
RADEON_COLOR_ORDER_RGBA |
RADEON_VTX_FMT_RADEON_MODE |
(count << RADEON_NUM_VERTICES_SHIFT));
do {
if (i < nbox)
radeon_emit_clip_rect(dev_priv, &sarea_priv->boxes[i]);
radeon_cp_dispatch_indirect(dev, elt_buf,
prim->start, prim->finish);
i++;
} while (i < nbox);
}
static int radeon_cp_dispatch_texture(struct drm_device * dev,
struct drm_file *file_priv,
drm_radeon_texture_t * tex,
drm_radeon_tex_image_t * image)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
struct drm_buf *buf;
u32 format;
u32 *buffer;
const u8 __user *data;
int size, dwords, tex_width, blit_width, spitch;
u32 height;
int i;
u32 texpitch, microtile;
u32 offset, byte_offset;
RING_LOCALS;
if (radeon_check_and_fixup_offset(dev_priv, file_priv, &tex->offset)) {
DRM_ERROR("Invalid destination offset\n");
return -EINVAL;
}
dev_priv->stats.boxes |= RADEON_BOX_TEXTURE_LOAD;
BEGIN_RING(4);
RADEON_FLUSH_CACHE();
RADEON_WAIT_UNTIL_IDLE();
ADVANCE_RING();
switch (tex->format) {
case RADEON_TXFORMAT_ARGB8888:
case RADEON_TXFORMAT_RGBA8888:
format = RADEON_COLOR_FORMAT_ARGB8888;
tex_width = tex->width * 4;
blit_width = image->width * 4;
break;
case RADEON_TXFORMAT_AI88:
case RADEON_TXFORMAT_ARGB1555:
case RADEON_TXFORMAT_RGB565:
case RADEON_TXFORMAT_ARGB4444:
case RADEON_TXFORMAT_VYUY422:
case RADEON_TXFORMAT_YVYU422:
format = RADEON_COLOR_FORMAT_RGB565;
tex_width = tex->width * 2;
blit_width = image->width * 2;
break;
case RADEON_TXFORMAT_I8:
case RADEON_TXFORMAT_RGB332:
format = RADEON_COLOR_FORMAT_CI8;
tex_width = tex->width * 1;
blit_width = image->width * 1;
break;
default:
DRM_ERROR("invalid texture format %d\n", tex->format);
return -EINVAL;
}
spitch = blit_width >> 6;
if (spitch == 0 && image->height > 1)
return -EINVAL;
texpitch = tex->pitch;
if ((texpitch << 22) & RADEON_DST_TILE_MICRO) {
microtile = 1;
if (tex_width < 64) {
texpitch &= ~(RADEON_DST_TILE_MICRO >> 22);
image->x *= 2;
}
} else
microtile = 0;
if (!radeon_check_offset(dev_priv, tex->offset + image->height *
blit_width - 1)) {
DRM_ERROR("Invalid final destination offset\n");
return -EINVAL;
}
DRM_DEBUG("tex=%dx%d blit=%d\n", tex_width, tex->height, blit_width);
do {
DRM_DEBUG("tex: ofs=0x%x p=%d f=%d x=%hd y=%hd w=%hd h=%hd\n",
tex->offset >> 10, tex->pitch, tex->format,
image->x, image->y, image->width, image->height);
height = image->height;
data = (const u8 __user *)image->data;
size = height * blit_width;
if (size > RADEON_MAX_TEXTURE_SIZE) {
height = RADEON_MAX_TEXTURE_SIZE / blit_width;
size = height * blit_width;
} else if (size < 4 && size > 0) {
size = 4;
} else if (size == 0) {
return 0;
}
buf = radeon_freelist_get(dev);
if (0 && !buf) {
radeon_do_cp_idle(dev_priv);
buf = radeon_freelist_get(dev);
}
if (!buf) {
DRM_DEBUG("EAGAIN\n");
if (DRM_COPY_TO_USER(tex->image, image, sizeof(*image)))
return -EFAULT;
return -EAGAIN;
}
buffer =
(u32 *) ((char *)dev->agp_buffer_map->handle + buf->offset);
dwords = size / 4;
#define RADEON_COPY_MT(_buf, _data, _width) \
do { \
if (DRM_COPY_FROM_USER(_buf, _data, (_width))) {\
DRM_ERROR("EFAULT on pad, %d bytes\n", (_width)); \
return -EFAULT; \
} \
} while(0)
if (microtile) {
if (tex->height == 1) {
if (tex_width >= 64 || tex_width <= 16) {
RADEON_COPY_MT(buffer, data,
(int)(tex_width * sizeof(u32)));
} else if (tex_width == 32) {
RADEON_COPY_MT(buffer, data, 16);
RADEON_COPY_MT(buffer + 8,
data + 16, 16);
}
} else if (tex_width >= 64 || tex_width == 16) {
RADEON_COPY_MT(buffer, data,
(int)(dwords * sizeof(u32)));
} else if (tex_width < 16) {
for (i = 0; i < tex->height; i++) {
RADEON_COPY_MT(buffer, data, tex_width);
buffer += 4;
data += tex_width;
}
} else if (tex_width == 32) {
for (i = 0; i < tex->height; i += 2) {
RADEON_COPY_MT(buffer, data, 16);
data += 16;
RADEON_COPY_MT(buffer + 8, data, 16);
data += 16;
RADEON_COPY_MT(buffer + 4, data, 16);
data += 16;
RADEON_COPY_MT(buffer + 12, data, 16);
data += 16;
buffer += 16;
}
}
} else {
if (tex_width >= 32) {
RADEON_COPY_MT(buffer, data,
(int)(dwords * sizeof(u32)));
} else {
for (i = 0; i < tex->height; i++) {
RADEON_COPY_MT(buffer, data, tex_width);
buffer += 8;
data += tex_width;
}
}
}
#undef RADEON_COPY_MT
byte_offset = (image->y & ~2047) * blit_width;
buf->file_priv = file_priv;
buf->used = size;
offset = dev_priv->gart_buffers_offset + buf->offset;
BEGIN_RING(9);
OUT_RING(CP_PACKET3(RADEON_CNTL_BITBLT_MULTI, 5));
OUT_RING(RADEON_GMC_SRC_PITCH_OFFSET_CNTL |
RADEON_GMC_DST_PITCH_OFFSET_CNTL |
RADEON_GMC_BRUSH_NONE |
(format << 8) |
RADEON_GMC_SRC_DATATYPE_COLOR |
RADEON_ROP3_S |
RADEON_DP_SRC_SOURCE_MEMORY |
RADEON_GMC_CLR_CMP_CNTL_DIS | RADEON_GMC_WR_MSK_DIS);
OUT_RING((spitch << 22) | (offset >> 10));
OUT_RING((texpitch << 22) | ((tex->offset >> 10) + (byte_offset >> 10)));
OUT_RING(0);
OUT_RING((image->x << 16) | (image->y % 2048));
OUT_RING((image->width << 16) | height);
RADEON_WAIT_UNTIL_2D_IDLE();
ADVANCE_RING();
COMMIT_RING();
radeon_cp_discard_buffer(dev, file_priv->master, buf);
image->y += height;
image->height -= height;
image->data = (const u8 __user *)image->data + size;
} while (image->height > 0);
BEGIN_RING(4);
RADEON_FLUSH_CACHE();
RADEON_WAIT_UNTIL_2D_IDLE();
ADVANCE_RING();
COMMIT_RING();
return 0;
}
static void radeon_cp_dispatch_stipple(struct drm_device * dev, u32 * stipple)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
int i;
RING_LOCALS;
DRM_DEBUG("\n");
BEGIN_RING(35);
OUT_RING(CP_PACKET0(RADEON_RE_STIPPLE_ADDR, 0));
OUT_RING(0x00000000);
OUT_RING(CP_PACKET0_TABLE(RADEON_RE_STIPPLE_DATA, 31));
for (i = 0; i < 32; i++) {
OUT_RING(stipple[i]);
}
ADVANCE_RING();
}
static void radeon_apply_surface_regs(int surf_index,
drm_radeon_private_t *dev_priv)
{
if (!dev_priv->mmio)
return;
radeon_do_cp_idle(dev_priv);
RADEON_WRITE(RADEON_SURFACE0_INFO + 16 * surf_index,
dev_priv->surfaces[surf_index].flags);
RADEON_WRITE(RADEON_SURFACE0_LOWER_BOUND + 16 * surf_index,
dev_priv->surfaces[surf_index].lower);
RADEON_WRITE(RADEON_SURFACE0_UPPER_BOUND + 16 * surf_index,
dev_priv->surfaces[surf_index].upper);
}
static int alloc_surface(drm_radeon_surface_alloc_t *new,
drm_radeon_private_t *dev_priv,
struct drm_file *file_priv)
{
struct radeon_virt_surface *s;
int i;
int virt_surface_index;
uint32_t new_upper, new_lower;
new_lower = new->address;
new_upper = new_lower + new->size - 1;
if ((new_lower >= new_upper) || (new->flags == 0) || (new->size == 0) ||
((new_upper & RADEON_SURF_ADDRESS_FIXED_MASK) !=
RADEON_SURF_ADDRESS_FIXED_MASK)
|| ((new_lower & RADEON_SURF_ADDRESS_FIXED_MASK) != 0))
return -1;
for (i = 0; i < RADEON_MAX_SURFACES; i++) {
if ((dev_priv->surfaces[i].refcount != 0) &&
(((new_lower >= dev_priv->surfaces[i].lower) &&
(new_lower < dev_priv->surfaces[i].upper)) ||
((new_lower < dev_priv->surfaces[i].lower) &&
(new_upper > dev_priv->surfaces[i].lower)))) {
return -1;
}
}
for (i = 0; i < 2 * RADEON_MAX_SURFACES; i++)
if (dev_priv->virt_surfaces[i].file_priv == NULL)
break;
if (i == 2 * RADEON_MAX_SURFACES) {
return -1;
}
virt_surface_index = i;
for (i = 0; i < RADEON_MAX_SURFACES; i++) {
if ((dev_priv->surfaces[i].refcount == 1) &&
(new->flags == dev_priv->surfaces[i].flags) &&
(new_upper + 1 == dev_priv->surfaces[i].lower)) {
s = &(dev_priv->virt_surfaces[virt_surface_index]);
s->surface_index = i;
s->lower = new_lower;
s->upper = new_upper;
s->flags = new->flags;
s->file_priv = file_priv;
dev_priv->surfaces[i].refcount++;
dev_priv->surfaces[i].lower = s->lower;
radeon_apply_surface_regs(s->surface_index, dev_priv);
return virt_surface_index;
}
if ((dev_priv->surfaces[i].refcount == 1) &&
(new->flags == dev_priv->surfaces[i].flags) &&
(new_lower == dev_priv->surfaces[i].upper + 1)) {
s = &(dev_priv->virt_surfaces[virt_surface_index]);
s->surface_index = i;
s->lower = new_lower;
s->upper = new_upper;
s->flags = new->flags;
s->file_priv = file_priv;
dev_priv->surfaces[i].refcount++;
dev_priv->surfaces[i].upper = s->upper;
radeon_apply_surface_regs(s->surface_index, dev_priv);
return virt_surface_index;
}
}
for (i = 0; i < RADEON_MAX_SURFACES; i++) {
if (dev_priv->surfaces[i].refcount == 0) {
s = &(dev_priv->virt_surfaces[virt_surface_index]);
s->surface_index = i;
s->lower = new_lower;
s->upper = new_upper;
s->flags = new->flags;
s->file_priv = file_priv;
dev_priv->surfaces[i].refcount = 1;
dev_priv->surfaces[i].lower = s->lower;
dev_priv->surfaces[i].upper = s->upper;
dev_priv->surfaces[i].flags = s->flags;
radeon_apply_surface_regs(s->surface_index, dev_priv);
return virt_surface_index;
}
}
return -1;
}
static int free_surface(struct drm_file *file_priv,
drm_radeon_private_t * dev_priv,
int lower)
{
struct radeon_virt_surface *s;
int i;
for (i = 0; i < 2 * RADEON_MAX_SURFACES; i++) {
s = &(dev_priv->virt_surfaces[i]);
if (s->file_priv) {
if ((lower == s->lower) && (file_priv == s->file_priv))
{
if (dev_priv->surfaces[s->surface_index].
lower == s->lower)
dev_priv->surfaces[s->surface_index].
lower = s->upper;
if (dev_priv->surfaces[s->surface_index].
upper == s->upper)
dev_priv->surfaces[s->surface_index].
upper = s->lower;
dev_priv->surfaces[s->surface_index].refcount--;
if (dev_priv->surfaces[s->surface_index].
refcount == 0)
dev_priv->surfaces[s->surface_index].
flags = 0;
s->file_priv = NULL;
radeon_apply_surface_regs(s->surface_index,
dev_priv);
return 0;
}
}
}
return 1;
}
static void radeon_surfaces_release(struct drm_file *file_priv,
drm_radeon_private_t * dev_priv)
{
int i;
for (i = 0; i < 2 * RADEON_MAX_SURFACES; i++) {
if (dev_priv->virt_surfaces[i].file_priv == file_priv)
free_surface(file_priv, dev_priv,
dev_priv->virt_surfaces[i].lower);
}
}
static int radeon_surface_alloc(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
drm_radeon_surface_alloc_t *alloc = data;
if (alloc_surface(alloc, dev_priv, file_priv) == -1)
return -EINVAL;
else
return 0;
}
static int radeon_surface_free(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
drm_radeon_surface_free_t *memfree = data;
if (free_surface(file_priv, dev_priv, memfree->address))
return -EINVAL;
else
return 0;
}
static int radeon_cp_clear(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
struct drm_radeon_master_private *master_priv = file_priv->master->driver_priv;
drm_radeon_sarea_t *sarea_priv = master_priv->sarea_priv;
drm_radeon_clear_t *clear = data;
drm_radeon_clear_rect_t depth_boxes[RADEON_NR_SAREA_CLIPRECTS];
DRM_DEBUG("\n");
LOCK_TEST_WITH_RETURN(dev, file_priv);
RING_SPACE_TEST_WITH_RETURN(dev_priv);
if (sarea_priv->nbox > RADEON_NR_SAREA_CLIPRECTS)
sarea_priv->nbox = RADEON_NR_SAREA_CLIPRECTS;
if (DRM_COPY_FROM_USER(&depth_boxes, clear->depth_boxes,
sarea_priv->nbox * sizeof(depth_boxes[0])))
return -EFAULT;
radeon_cp_dispatch_clear(dev, file_priv->master, clear, depth_boxes);
COMMIT_RING();
return 0;
}
static int radeon_do_init_pageflip(struct drm_device *dev, struct drm_master *master)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
struct drm_radeon_master_private *master_priv = master->driver_priv;
RING_LOCALS;
DRM_DEBUG("\n");
BEGIN_RING(6);
RADEON_WAIT_UNTIL_3D_IDLE();
OUT_RING(CP_PACKET0(RADEON_CRTC_OFFSET_CNTL, 0));
OUT_RING(RADEON_READ(RADEON_CRTC_OFFSET_CNTL) |
RADEON_CRTC_OFFSET_FLIP_CNTL);
OUT_RING(CP_PACKET0(RADEON_CRTC2_OFFSET_CNTL, 0));
OUT_RING(RADEON_READ(RADEON_CRTC2_OFFSET_CNTL) |
RADEON_CRTC_OFFSET_FLIP_CNTL);
ADVANCE_RING();
dev_priv->page_flipping = 1;
if (master_priv->sarea_priv->pfCurrentPage != 1)
master_priv->sarea_priv->pfCurrentPage = 0;
return 0;
}
static int radeon_cp_flip(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
DRM_DEBUG("\n");
LOCK_TEST_WITH_RETURN(dev, file_priv);
RING_SPACE_TEST_WITH_RETURN(dev_priv);
if (!dev_priv->page_flipping)
radeon_do_init_pageflip(dev, file_priv->master);
radeon_cp_dispatch_flip(dev, file_priv->master);
COMMIT_RING();
return 0;
}
static int radeon_cp_swap(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
struct drm_radeon_master_private *master_priv = file_priv->master->driver_priv;
drm_radeon_sarea_t *sarea_priv = master_priv->sarea_priv;
DRM_DEBUG("\n");
LOCK_TEST_WITH_RETURN(dev, file_priv);
RING_SPACE_TEST_WITH_RETURN(dev_priv);
if (sarea_priv->nbox > RADEON_NR_SAREA_CLIPRECTS)
sarea_priv->nbox = RADEON_NR_SAREA_CLIPRECTS;
if ((dev_priv->flags & RADEON_FAMILY_MASK) >= CHIP_R600)
r600_cp_dispatch_swap(dev, file_priv);
else
radeon_cp_dispatch_swap(dev, file_priv->master);
sarea_priv->ctx_owner = 0;
COMMIT_RING();
return 0;
}
static int radeon_cp_vertex(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
struct drm_radeon_master_private *master_priv = file_priv->master->driver_priv;
drm_radeon_sarea_t *sarea_priv;
struct drm_device_dma *dma = dev->dma;
struct drm_buf *buf;
drm_radeon_vertex_t *vertex = data;
drm_radeon_tcl_prim_t prim;
LOCK_TEST_WITH_RETURN(dev, file_priv);
sarea_priv = master_priv->sarea_priv;
DRM_DEBUG("pid=%d index=%d count=%d discard=%d\n",
DRM_CURRENTPID, vertex->idx, vertex->count, vertex->discard);
if (vertex->idx < 0 || vertex->idx >= dma->buf_count) {
DRM_ERROR("buffer index %d (of %d max)\n",
vertex->idx, dma->buf_count - 1);
return -EINVAL;
}
if (vertex->prim < 0 || vertex->prim > RADEON_PRIM_TYPE_3VRT_LINE_LIST) {
DRM_ERROR("buffer prim %d\n", vertex->prim);
return -EINVAL;
}
RING_SPACE_TEST_WITH_RETURN(dev_priv);
VB_AGE_TEST_WITH_RETURN(dev_priv);
buf = dma->buflist[vertex->idx];
if (buf->file_priv != file_priv) {
DRM_ERROR("process %d using buffer owned by %p\n",
DRM_CURRENTPID, buf->file_priv);
return -EINVAL;
}
if (buf->pending) {
DRM_ERROR("sending pending buffer %d\n", vertex->idx);
return -EINVAL;
}
if (vertex->count) {
buf->used = vertex->count;
if (sarea_priv->dirty & ~RADEON_UPLOAD_CLIPRECTS) {
if (radeon_emit_state(dev_priv, file_priv,
&sarea_priv->context_state,
sarea_priv->tex_state,
sarea_priv->dirty)) {
DRM_ERROR("radeon_emit_state failed\n");
return -EINVAL;
}
sarea_priv->dirty &= ~(RADEON_UPLOAD_TEX0IMAGES |
RADEON_UPLOAD_TEX1IMAGES |
RADEON_UPLOAD_TEX2IMAGES |
RADEON_REQUIRE_QUIESCENCE);
}
prim.start = 0;
prim.finish = vertex->count;
prim.prim = vertex->prim;
prim.numverts = vertex->count;
prim.vc_format = sarea_priv->vc_format;
radeon_cp_dispatch_vertex(dev, file_priv, buf, &prim);
}
if (vertex->discard) {
radeon_cp_discard_buffer(dev, file_priv->master, buf);
}
COMMIT_RING();
return 0;
}
static int radeon_cp_indices(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
struct drm_radeon_master_private *master_priv = file_priv->master->driver_priv;
drm_radeon_sarea_t *sarea_priv;
struct drm_device_dma *dma = dev->dma;
struct drm_buf *buf;
drm_radeon_indices_t *elts = data;
drm_radeon_tcl_prim_t prim;
int count;
LOCK_TEST_WITH_RETURN(dev, file_priv);
sarea_priv = master_priv->sarea_priv;
DRM_DEBUG("pid=%d index=%d start=%d end=%d discard=%d\n",
DRM_CURRENTPID, elts->idx, elts->start, elts->end,
elts->discard);
if (elts->idx < 0 || elts->idx >= dma->buf_count) {
DRM_ERROR("buffer index %d (of %d max)\n",
elts->idx, dma->buf_count - 1);
return -EINVAL;
}
if (elts->prim < 0 || elts->prim > RADEON_PRIM_TYPE_3VRT_LINE_LIST) {
DRM_ERROR("buffer prim %d\n", elts->prim);
return -EINVAL;
}
RING_SPACE_TEST_WITH_RETURN(dev_priv);
VB_AGE_TEST_WITH_RETURN(dev_priv);
buf = dma->buflist[elts->idx];
if (buf->file_priv != file_priv) {
DRM_ERROR("process %d using buffer owned by %p\n",
DRM_CURRENTPID, buf->file_priv);
return -EINVAL;
}
if (buf->pending) {
DRM_ERROR("sending pending buffer %d\n", elts->idx);
return -EINVAL;
}
count = (elts->end - elts->start) / sizeof(u16);
elts->start -= RADEON_INDEX_PRIM_OFFSET;
if (elts->start & 0x7) {
DRM_ERROR("misaligned buffer 0x%x\n", elts->start);
return -EINVAL;
}
if (elts->start < buf->used) {
DRM_ERROR("no header 0x%x - 0x%x\n", elts->start, buf->used);
return -EINVAL;
}
buf->used = elts->end;
if (sarea_priv->dirty & ~RADEON_UPLOAD_CLIPRECTS) {
if (radeon_emit_state(dev_priv, file_priv,
&sarea_priv->context_state,
sarea_priv->tex_state,
sarea_priv->dirty)) {
DRM_ERROR("radeon_emit_state failed\n");
return -EINVAL;
}
sarea_priv->dirty &= ~(RADEON_UPLOAD_TEX0IMAGES |
RADEON_UPLOAD_TEX1IMAGES |
RADEON_UPLOAD_TEX2IMAGES |
RADEON_REQUIRE_QUIESCENCE);
}
prim.start = elts->start;
prim.finish = elts->end;
prim.prim = elts->prim;
prim.offset = 0;
prim.numverts = RADEON_MAX_VB_VERTS;
prim.vc_format = sarea_priv->vc_format;
radeon_cp_dispatch_indices(dev, file_priv->master, buf, &prim);
if (elts->discard) {
radeon_cp_discard_buffer(dev, file_priv->master, buf);
}
COMMIT_RING();
return 0;
}
static int radeon_cp_texture(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
drm_radeon_texture_t *tex = data;
drm_radeon_tex_image_t image;
int ret;
LOCK_TEST_WITH_RETURN(dev, file_priv);
if (tex->image == NULL) {
DRM_ERROR("null texture image!\n");
return -EINVAL;
}
if (DRM_COPY_FROM_USER(&image,
(drm_radeon_tex_image_t __user *) tex->image,
sizeof(image)))
return -EFAULT;
RING_SPACE_TEST_WITH_RETURN(dev_priv);
VB_AGE_TEST_WITH_RETURN(dev_priv);
if ((dev_priv->flags & RADEON_FAMILY_MASK) >= CHIP_R600)
ret = r600_cp_dispatch_texture(dev, file_priv, tex, &image);
else
ret = radeon_cp_dispatch_texture(dev, file_priv, tex, &image);
return ret;
}
static int radeon_cp_stipple(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
drm_radeon_stipple_t *stipple = data;
u32 mask[32];
LOCK_TEST_WITH_RETURN(dev, file_priv);
if (DRM_COPY_FROM_USER(&mask, stipple->mask, 32 * sizeof(u32)))
return -EFAULT;
RING_SPACE_TEST_WITH_RETURN(dev_priv);
radeon_cp_dispatch_stipple(dev, mask);
COMMIT_RING();
return 0;
}
static int radeon_cp_indirect(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
struct drm_device_dma *dma = dev->dma;
struct drm_buf *buf;
drm_radeon_indirect_t *indirect = data;
RING_LOCALS;
LOCK_TEST_WITH_RETURN(dev, file_priv);
DRM_DEBUG("idx=%d s=%d e=%d d=%d\n",
indirect->idx, indirect->start, indirect->end,
indirect->discard);
if (indirect->idx < 0 || indirect->idx >= dma->buf_count) {
DRM_ERROR("buffer index %d (of %d max)\n",
indirect->idx, dma->buf_count - 1);
return -EINVAL;
}
buf = dma->buflist[indirect->idx];
if (buf->file_priv != file_priv) {
DRM_ERROR("process %d using buffer owned by %p\n",
DRM_CURRENTPID, buf->file_priv);
return -EINVAL;
}
if (buf->pending) {
DRM_ERROR("sending pending buffer %d\n", indirect->idx);
return -EINVAL;
}
if (indirect->start < buf->used) {
DRM_ERROR("reusing indirect: start=0x%x actual=0x%x\n",
indirect->start, buf->used);
return -EINVAL;
}
RING_SPACE_TEST_WITH_RETURN(dev_priv);
VB_AGE_TEST_WITH_RETURN(dev_priv);
buf->used = indirect->end;
if ((dev_priv->flags & RADEON_FAMILY_MASK) >= CHIP_R600)
r600_cp_dispatch_indirect(dev, buf, indirect->start, indirect->end);
else {
BEGIN_RING(2);
RADEON_WAIT_UNTIL_3D_IDLE();
ADVANCE_RING();
radeon_cp_dispatch_indirect(dev, buf, indirect->start, indirect->end);
}
if (indirect->discard) {
radeon_cp_discard_buffer(dev, file_priv->master, buf);
}
COMMIT_RING();
return 0;
}
static int radeon_cp_vertex2(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
struct drm_radeon_master_private *master_priv = file_priv->master->driver_priv;
drm_radeon_sarea_t *sarea_priv;
struct drm_device_dma *dma = dev->dma;
struct drm_buf *buf;
drm_radeon_vertex2_t *vertex = data;
int i;
unsigned char laststate;
LOCK_TEST_WITH_RETURN(dev, file_priv);
sarea_priv = master_priv->sarea_priv;
DRM_DEBUG("pid=%d index=%d discard=%d\n",
DRM_CURRENTPID, vertex->idx, vertex->discard);
if (vertex->idx < 0 || vertex->idx >= dma->buf_count) {
DRM_ERROR("buffer index %d (of %d max)\n",
vertex->idx, dma->buf_count - 1);
return -EINVAL;
}
RING_SPACE_TEST_WITH_RETURN(dev_priv);
VB_AGE_TEST_WITH_RETURN(dev_priv);
buf = dma->buflist[vertex->idx];
if (buf->file_priv != file_priv) {
DRM_ERROR("process %d using buffer owned by %p\n",
DRM_CURRENTPID, buf->file_priv);
return -EINVAL;
}
if (buf->pending) {
DRM_ERROR("sending pending buffer %d\n", vertex->idx);
return -EINVAL;
}
if (sarea_priv->nbox > RADEON_NR_SAREA_CLIPRECTS)
return -EINVAL;
for (laststate = 0xff, i = 0; i < vertex->nr_prims; i++) {
drm_radeon_prim_t prim;
drm_radeon_tcl_prim_t tclprim;
if (DRM_COPY_FROM_USER(&prim, &vertex->prim[i], sizeof(prim)))
return -EFAULT;
if (prim.stateidx != laststate) {
drm_radeon_state_t state;
if (DRM_COPY_FROM_USER(&state,
&vertex->state[prim.stateidx],
sizeof(state)))
return -EFAULT;
if (radeon_emit_state2(dev_priv, file_priv, &state)) {
DRM_ERROR("radeon_emit_state2 failed\n");
return -EINVAL;
}
laststate = prim.stateidx;
}
tclprim.start = prim.start;
tclprim.finish = prim.finish;
tclprim.prim = prim.prim;
tclprim.vc_format = prim.vc_format;
if (prim.prim & RADEON_PRIM_WALK_IND) {
tclprim.offset = prim.numverts * 64;
tclprim.numverts = RADEON_MAX_VB_VERTS;
radeon_cp_dispatch_indices(dev, file_priv->master, buf, &tclprim);
} else {
tclprim.numverts = prim.numverts;
tclprim.offset = 0;
radeon_cp_dispatch_vertex(dev, file_priv, buf, &tclprim);
}
if (sarea_priv->nbox == 1)
sarea_priv->nbox = 0;
}
if (vertex->discard) {
radeon_cp_discard_buffer(dev, file_priv->master, buf);
}
COMMIT_RING();
return 0;
}
static int radeon_emit_packets(drm_radeon_private_t * dev_priv,
struct drm_file *file_priv,
drm_radeon_cmd_header_t header,
drm_radeon_kcmd_buffer_t *cmdbuf)
{
int id = (int)header.packet.packet_id;
int sz, reg;
RING_LOCALS;
if (id >= RADEON_MAX_STATE_PACKETS)
return -EINVAL;
sz = packet[id].len;
reg = packet[id].start;
if (sz * sizeof(u32) > drm_buffer_unprocessed(cmdbuf->buffer)) {
DRM_ERROR("Packet size provided larger than data provided\n");
return -EINVAL;
}
if (radeon_check_and_fixup_packets(dev_priv, file_priv, id,
cmdbuf->buffer)) {
DRM_ERROR("Packet verification failed\n");
return -EINVAL;
}
BEGIN_RING(sz + 1);
OUT_RING(CP_PACKET0(reg, (sz - 1)));
OUT_RING_DRM_BUFFER(cmdbuf->buffer, sz);
ADVANCE_RING();
return 0;
}
static __inline__ int radeon_emit_scalars(drm_radeon_private_t *dev_priv,
drm_radeon_cmd_header_t header,
drm_radeon_kcmd_buffer_t *cmdbuf)
{
int sz = header.scalars.count;
int start = header.scalars.offset;
int stride = header.scalars.stride;
RING_LOCALS;
BEGIN_RING(3 + sz);
OUT_RING(CP_PACKET0(RADEON_SE_TCL_SCALAR_INDX_REG, 0));
OUT_RING(start | (stride << RADEON_SCAL_INDX_DWORD_STRIDE_SHIFT));
OUT_RING(CP_PACKET0_TABLE(RADEON_SE_TCL_SCALAR_DATA_REG, sz - 1));
OUT_RING_DRM_BUFFER(cmdbuf->buffer, sz);
ADVANCE_RING();
return 0;
}
static __inline__ int radeon_emit_scalars2(drm_radeon_private_t *dev_priv,
drm_radeon_cmd_header_t header,
drm_radeon_kcmd_buffer_t *cmdbuf)
{
int sz = header.scalars.count;
int start = ((unsigned int)header.scalars.offset) + 0x100;
int stride = header.scalars.stride;
RING_LOCALS;
BEGIN_RING(3 + sz);
OUT_RING(CP_PACKET0(RADEON_SE_TCL_SCALAR_INDX_REG, 0));
OUT_RING(start | (stride << RADEON_SCAL_INDX_DWORD_STRIDE_SHIFT));
OUT_RING(CP_PACKET0_TABLE(RADEON_SE_TCL_SCALAR_DATA_REG, sz - 1));
OUT_RING_DRM_BUFFER(cmdbuf->buffer, sz);
ADVANCE_RING();
return 0;
}
static __inline__ int radeon_emit_vectors(drm_radeon_private_t *dev_priv,
drm_radeon_cmd_header_t header,
drm_radeon_kcmd_buffer_t *cmdbuf)
{
int sz = header.vectors.count;
int start = header.vectors.offset;
int stride = header.vectors.stride;
RING_LOCALS;
BEGIN_RING(5 + sz);
OUT_RING_REG(RADEON_SE_TCL_STATE_FLUSH, 0);
OUT_RING(CP_PACKET0(RADEON_SE_TCL_VECTOR_INDX_REG, 0));
OUT_RING(start | (stride << RADEON_VEC_INDX_OCTWORD_STRIDE_SHIFT));
OUT_RING(CP_PACKET0_TABLE(RADEON_SE_TCL_VECTOR_DATA_REG, (sz - 1)));
OUT_RING_DRM_BUFFER(cmdbuf->buffer, sz);
ADVANCE_RING();
return 0;
}
static __inline__ int radeon_emit_veclinear(drm_radeon_private_t *dev_priv,
drm_radeon_cmd_header_t header,
drm_radeon_kcmd_buffer_t *cmdbuf)
{
int sz = header.veclinear.count * 4;
int start = header.veclinear.addr_lo | (header.veclinear.addr_hi << 8);
RING_LOCALS;
if (!sz)
return 0;
if (sz * 4 > drm_buffer_unprocessed(cmdbuf->buffer))
return -EINVAL;
BEGIN_RING(5 + sz);
OUT_RING_REG(RADEON_SE_TCL_STATE_FLUSH, 0);
OUT_RING(CP_PACKET0(RADEON_SE_TCL_VECTOR_INDX_REG, 0));
OUT_RING(start | (1 << RADEON_VEC_INDX_OCTWORD_STRIDE_SHIFT));
OUT_RING(CP_PACKET0_TABLE(RADEON_SE_TCL_VECTOR_DATA_REG, (sz - 1)));
OUT_RING_DRM_BUFFER(cmdbuf->buffer, sz);
ADVANCE_RING();
return 0;
}
static int radeon_emit_packet3(struct drm_device * dev,
struct drm_file *file_priv,
drm_radeon_kcmd_buffer_t *cmdbuf)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
unsigned int cmdsz;
int ret;
RING_LOCALS;
DRM_DEBUG("\n");
if ((ret = radeon_check_and_fixup_packet3(dev_priv, file_priv,
cmdbuf, &cmdsz))) {
DRM_ERROR("Packet verification failed\n");
return ret;
}
BEGIN_RING(cmdsz);
OUT_RING_DRM_BUFFER(cmdbuf->buffer, cmdsz);
ADVANCE_RING();
return 0;
}
static int radeon_emit_packet3_cliprect(struct drm_device *dev,
struct drm_file *file_priv,
drm_radeon_kcmd_buffer_t *cmdbuf,
int orig_nbox)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
struct drm_clip_rect box;
unsigned int cmdsz;
int ret;
struct drm_clip_rect __user *boxes = cmdbuf->boxes;
int i = 0;
RING_LOCALS;
DRM_DEBUG("\n");
if ((ret = radeon_check_and_fixup_packet3(dev_priv, file_priv,
cmdbuf, &cmdsz))) {
DRM_ERROR("Packet verification failed\n");
return ret;
}
if (!orig_nbox)
goto out;
do {
if (i < cmdbuf->nbox) {
if (DRM_COPY_FROM_USER(&box, &boxes[i], sizeof(box)))
return -EFAULT;
if (i) {
BEGIN_RING(2);
RADEON_WAIT_UNTIL_3D_IDLE();
ADVANCE_RING();
}
radeon_emit_clip_rect(dev_priv, &box);
}
BEGIN_RING(cmdsz);
OUT_RING_DRM_BUFFER(cmdbuf->buffer, cmdsz);
ADVANCE_RING();
} while (++i < cmdbuf->nbox);
if (cmdbuf->nbox == 1)
cmdbuf->nbox = 0;
return 0;
out:
drm_buffer_advance(cmdbuf->buffer, cmdsz * 4);
return 0;
}
static int radeon_emit_wait(struct drm_device * dev, int flags)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
RING_LOCALS;
DRM_DEBUG("%x\n", flags);
switch (flags) {
case RADEON_WAIT_2D:
BEGIN_RING(2);
RADEON_WAIT_UNTIL_2D_IDLE();
ADVANCE_RING();
break;
case RADEON_WAIT_3D:
BEGIN_RING(2);
RADEON_WAIT_UNTIL_3D_IDLE();
ADVANCE_RING();
break;
case RADEON_WAIT_2D | RADEON_WAIT_3D:
BEGIN_RING(2);
RADEON_WAIT_UNTIL_IDLE();
ADVANCE_RING();
break;
default:
return -EINVAL;
}
return 0;
}
static int radeon_cp_cmdbuf(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
struct drm_device_dma *dma = dev->dma;
struct drm_buf *buf = NULL;
drm_radeon_cmd_header_t stack_header;
int idx;
drm_radeon_kcmd_buffer_t *cmdbuf = data;
int orig_nbox;
LOCK_TEST_WITH_RETURN(dev, file_priv);
RING_SPACE_TEST_WITH_RETURN(dev_priv);
VB_AGE_TEST_WITH_RETURN(dev_priv);
if (cmdbuf->bufsz > 64 * 1024 || cmdbuf->bufsz < 0) {
return -EINVAL;
}
if (cmdbuf->bufsz != 0) {
int rv;
void __user *buffer = cmdbuf->buffer;
rv = drm_buffer_alloc(&cmdbuf->buffer, cmdbuf->bufsz);
if (rv)
return rv;
rv = drm_buffer_copy_from_user(cmdbuf->buffer, buffer,
cmdbuf->bufsz);
if (rv) {
drm_buffer_free(cmdbuf->buffer);
return rv;
}
} else
goto done;
orig_nbox = cmdbuf->nbox;
if (dev_priv->microcode_version == UCODE_R300) {
int temp;
temp = r300_do_cp_cmdbuf(dev, file_priv, cmdbuf);
drm_buffer_free(cmdbuf->buffer);
return temp;
}
while (drm_buffer_unprocessed(cmdbuf->buffer) >= sizeof(stack_header)) {
drm_radeon_cmd_header_t *header;
header = drm_buffer_read_object(cmdbuf->buffer,
sizeof(stack_header), &stack_header);
switch (header->header.cmd_type) {
case RADEON_CMD_PACKET:
DRM_DEBUG("RADEON_CMD_PACKET\n");
if (radeon_emit_packets
(dev_priv, file_priv, *header, cmdbuf)) {
DRM_ERROR("radeon_emit_packets failed\n");
goto err;
}
break;
case RADEON_CMD_SCALARS:
DRM_DEBUG("RADEON_CMD_SCALARS\n");
if (radeon_emit_scalars(dev_priv, *header, cmdbuf)) {
DRM_ERROR("radeon_emit_scalars failed\n");
goto err;
}
break;
case RADEON_CMD_VECTORS:
DRM_DEBUG("RADEON_CMD_VECTORS\n");
if (radeon_emit_vectors(dev_priv, *header, cmdbuf)) {
DRM_ERROR("radeon_emit_vectors failed\n");
goto err;
}
break;
case RADEON_CMD_DMA_DISCARD:
DRM_DEBUG("RADEON_CMD_DMA_DISCARD\n");
idx = header->dma.buf_idx;
if (idx < 0 || idx >= dma->buf_count) {
DRM_ERROR("buffer index %d (of %d max)\n",
idx, dma->buf_count - 1);
goto err;
}
buf = dma->buflist[idx];
if (buf->file_priv != file_priv || buf->pending) {
DRM_ERROR("bad buffer %p %p %d\n",
buf->file_priv, file_priv,
buf->pending);
goto err;
}
radeon_cp_discard_buffer(dev, file_priv->master, buf);
break;
case RADEON_CMD_PACKET3:
DRM_DEBUG("RADEON_CMD_PACKET3\n");
if (radeon_emit_packet3(dev, file_priv, cmdbuf)) {
DRM_ERROR("radeon_emit_packet3 failed\n");
goto err;
}
break;
case RADEON_CMD_PACKET3_CLIP:
DRM_DEBUG("RADEON_CMD_PACKET3_CLIP\n");
if (radeon_emit_packet3_cliprect
(dev, file_priv, cmdbuf, orig_nbox)) {
DRM_ERROR("radeon_emit_packet3_clip failed\n");
goto err;
}
break;
case RADEON_CMD_SCALARS2:
DRM_DEBUG("RADEON_CMD_SCALARS2\n");
if (radeon_emit_scalars2(dev_priv, *header, cmdbuf)) {
DRM_ERROR("radeon_emit_scalars2 failed\n");
goto err;
}
break;
case RADEON_CMD_WAIT:
DRM_DEBUG("RADEON_CMD_WAIT\n");
if (radeon_emit_wait(dev, header->wait.flags)) {
DRM_ERROR("radeon_emit_wait failed\n");
goto err;
}
break;
case RADEON_CMD_VECLINEAR:
DRM_DEBUG("RADEON_CMD_VECLINEAR\n");
if (radeon_emit_veclinear(dev_priv, *header, cmdbuf)) {
DRM_ERROR("radeon_emit_veclinear failed\n");
goto err;
}
break;
default:
DRM_ERROR("bad cmd_type %d at byte %d\n",
header->header.cmd_type,
cmdbuf->buffer->iterator);
goto err;
}
}
drm_buffer_free(cmdbuf->buffer);
done:
DRM_DEBUG("DONE\n");
COMMIT_RING();
return 0;
err:
drm_buffer_free(cmdbuf->buffer);
return -EINVAL;
}
static int radeon_cp_getparam(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
drm_radeon_getparam_t *param = data;
int value;
DRM_DEBUG("pid=%d\n", DRM_CURRENTPID);
switch (param->param) {
case RADEON_PARAM_GART_BUFFER_OFFSET:
value = dev_priv->gart_buffers_offset;
break;
case RADEON_PARAM_LAST_FRAME:
dev_priv->stats.last_frame_reads++;
value = GET_SCRATCH(dev_priv, 0);
break;
case RADEON_PARAM_LAST_DISPATCH:
value = GET_SCRATCH(dev_priv, 1);
break;
case RADEON_PARAM_LAST_CLEAR:
dev_priv->stats.last_clear_reads++;
value = GET_SCRATCH(dev_priv, 2);
break;
case RADEON_PARAM_IRQ_NR:
if ((dev_priv->flags & RADEON_FAMILY_MASK) >= CHIP_R600)
value = 0;
else
value = drm_dev_to_irq(dev);
break;
case RADEON_PARAM_GART_BASE:
value = dev_priv->gart_vm_start;
break;
case RADEON_PARAM_REGISTER_HANDLE:
value = dev_priv->mmio->offset;
break;
case RADEON_PARAM_STATUS_HANDLE:
value = dev_priv->ring_rptr_offset;
break;
#if BITS_PER_LONG == 32
case RADEON_PARAM_SAREA_HANDLE:
break;
#endif
case RADEON_PARAM_GART_TEX_HANDLE:
value = dev_priv->gart_textures_offset;
break;
case RADEON_PARAM_SCRATCH_OFFSET:
if (!dev_priv->writeback_works)
return -EINVAL;
if ((dev_priv->flags & RADEON_FAMILY_MASK) >= CHIP_R600)
value = R600_SCRATCH_REG_OFFSET;
else
value = RADEON_SCRATCH_REG_OFFSET;
break;
case RADEON_PARAM_CARD_TYPE:
if (dev_priv->flags & RADEON_IS_PCIE)
value = RADEON_CARD_PCIE;
else if (dev_priv->flags & RADEON_IS_AGP)
value = RADEON_CARD_AGP;
else
value = RADEON_CARD_PCI;
break;
case RADEON_PARAM_VBLANK_CRTC:
value = radeon_vblank_crtc_get(dev);
break;
case RADEON_PARAM_FB_LOCATION:
value = radeon_read_fb_location(dev_priv);
break;
case RADEON_PARAM_NUM_GB_PIPES:
value = dev_priv->num_gb_pipes;
break;
case RADEON_PARAM_NUM_Z_PIPES:
value = dev_priv->num_z_pipes;
break;
default:
DRM_DEBUG("Invalid parameter %d\n", param->param);
return -EINVAL;
}
if (DRM_COPY_TO_USER(param->value, &value, sizeof(int))) {
DRM_ERROR("copy_to_user\n");
return -EFAULT;
}
return 0;
}
static int radeon_cp_setparam(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
struct drm_radeon_master_private *master_priv = file_priv->master->driver_priv;
drm_radeon_setparam_t *sp = data;
struct drm_radeon_driver_file_fields *radeon_priv;
switch (sp->param) {
case RADEON_SETPARAM_FB_LOCATION:
radeon_priv = file_priv->driver_priv;
radeon_priv->radeon_fb_delta = dev_priv->fb_location -
sp->value;
break;
case RADEON_SETPARAM_SWITCH_TILING:
if (sp->value == 0) {
DRM_DEBUG("color tiling disabled\n");
dev_priv->front_pitch_offset &= ~RADEON_DST_TILE_MACRO;
dev_priv->back_pitch_offset &= ~RADEON_DST_TILE_MACRO;
if (master_priv->sarea_priv)
master_priv->sarea_priv->tiling_enabled = 0;
} else if (sp->value == 1) {
DRM_DEBUG("color tiling enabled\n");
dev_priv->front_pitch_offset |= RADEON_DST_TILE_MACRO;
dev_priv->back_pitch_offset |= RADEON_DST_TILE_MACRO;
if (master_priv->sarea_priv)
master_priv->sarea_priv->tiling_enabled = 1;
}
break;
case RADEON_SETPARAM_PCIGART_LOCATION:
dev_priv->pcigart_offset = sp->value;
dev_priv->pcigart_offset_set = 1;
break;
case RADEON_SETPARAM_NEW_MEMMAP:
dev_priv->new_memmap = sp->value;
break;
case RADEON_SETPARAM_PCIGART_TABLE_SIZE:
dev_priv->gart_info.table_size = sp->value;
if (dev_priv->gart_info.table_size < RADEON_PCIGART_TABLE_SIZE)
dev_priv->gart_info.table_size = RADEON_PCIGART_TABLE_SIZE;
break;
case RADEON_SETPARAM_VBLANK_CRTC:
return radeon_vblank_crtc_set(dev, sp->value);
break;
default:
DRM_DEBUG("Invalid parameter %d\n", sp->param);
return -EINVAL;
}
return 0;
}
void radeon_driver_preclose(struct drm_device *dev, struct drm_file *file_priv)
{
if (dev->dev_private) {
drm_radeon_private_t *dev_priv = dev->dev_private;
dev_priv->page_flipping = 0;
radeon_mem_release(file_priv, dev_priv->gart_heap);
radeon_mem_release(file_priv, dev_priv->fb_heap);
radeon_surfaces_release(file_priv, dev_priv);
}
}
void radeon_driver_lastclose(struct drm_device *dev)
{
radeon_surfaces_release(PCIGART_FILE_PRIV, dev->dev_private);
radeon_do_release(dev);
}
int radeon_driver_open(struct drm_device *dev, struct drm_file *file_priv)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
struct drm_radeon_driver_file_fields *radeon_priv;
DRM_DEBUG("\n");
radeon_priv = kmalloc(sizeof(*radeon_priv), GFP_KERNEL);
if (!radeon_priv)
return -ENOMEM;
file_priv->driver_priv = radeon_priv;
if (dev_priv)
radeon_priv->radeon_fb_delta = dev_priv->fb_location;
else
radeon_priv->radeon_fb_delta = 0;
return 0;
}
void radeon_driver_postclose(struct drm_device *dev, struct drm_file *file_priv)
{
struct drm_radeon_driver_file_fields *radeon_priv =
file_priv->driver_priv;
kfree(radeon_priv);
}
