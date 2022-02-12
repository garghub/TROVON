static void tv_setup_filter(struct drm_encoder *encoder)
{
struct nv17_tv_encoder *tv_enc = to_tv_enc(encoder);
struct nv17_tv_norm_params *tv_norm = get_tv_norm(encoder);
struct drm_display_mode *mode = &encoder->crtc->mode;
uint32_t (*filters[])[4][7] = {&tv_enc->state.hfilter,
&tv_enc->state.vfilter};
int i, j, k;
int32_t overscan = calc_overscan(tv_enc->overscan);
int64_t flicker = (tv_enc->flicker - 50) * (id3 / 100);
uint64_t rs[] = {mode->hdisplay * id3,
mode->vdisplay * id3};
do_div(rs[0], overscan * tv_norm->tv_enc_mode.hdisplay);
do_div(rs[1], overscan * tv_norm->tv_enc_mode.vdisplay);
for (k = 0; k < 2; k++) {
rs[k] = max((int64_t)rs[k], id2);
for (j = 0; j < 4; j++) {
struct filter_params *p = &fparams[k][j];
for (i = 0; i < 7; i++) {
int64_t c = (p->k1 + p->ki*i + p->ki2*i*i +
p->ki3*i*i*i)
+ (p->kr + p->kir*i + p->ki2r*i*i +
p->ki3r*i*i*i) * rs[k]
+ (p->kf + p->kif*i + p->ki2f*i*i +
p->ki3f*i*i*i) * flicker
+ (p->krf + p->kirf*i + p->ki2rf*i*i +
p->ki3rf*i*i*i) * flicker * rs[k];
(*filters[k])[j][i] = (c + id5/2) >> 39
& (0x1 << 31 | 0x7f << 9);
}
}
}
}
static void tv_save_filter(struct drm_device *dev, uint32_t base,
uint32_t regs[4][7])
{
int i, j;
uint32_t offsets[] = { base, base + 0x1c, base + 0x40, base + 0x5c };
for (i = 0; i < 4; i++) {
for (j = 0; j < 7; j++)
regs[i][j] = nv_read_ptv(dev, offsets[i]+4*j);
}
}
static void tv_load_filter(struct drm_device *dev, uint32_t base,
uint32_t regs[4][7])
{
int i, j;
uint32_t offsets[] = { base, base + 0x1c, base + 0x40, base + 0x5c };
for (i = 0; i < 4; i++) {
for (j = 0; j < 7; j++)
nv_write_ptv(dev, offsets[i]+4*j, regs[i][j]);
}
}
void nv17_tv_state_save(struct drm_device *dev, struct nv17_tv_state *state)
{
int i;
for (i = 0; i < 0x40; i++)
state->tv_enc[i] = nv_read_tv_enc(dev, i);
tv_save_filter(dev, NV_PTV_HFILTER, state->hfilter);
tv_save_filter(dev, NV_PTV_HFILTER2, state->hfilter2);
tv_save_filter(dev, NV_PTV_VFILTER, state->vfilter);
nv_save_ptv(dev, state, 200);
nv_save_ptv(dev, state, 204);
nv_save_ptv(dev, state, 208);
nv_save_ptv(dev, state, 20c);
nv_save_ptv(dev, state, 304);
nv_save_ptv(dev, state, 500);
nv_save_ptv(dev, state, 504);
nv_save_ptv(dev, state, 508);
nv_save_ptv(dev, state, 600);
nv_save_ptv(dev, state, 604);
nv_save_ptv(dev, state, 608);
nv_save_ptv(dev, state, 60c);
nv_save_ptv(dev, state, 610);
nv_save_ptv(dev, state, 614);
}
void nv17_tv_state_load(struct drm_device *dev, struct nv17_tv_state *state)
{
int i;
for (i = 0; i < 0x40; i++)
nv_write_tv_enc(dev, i, state->tv_enc[i]);
tv_load_filter(dev, NV_PTV_HFILTER, state->hfilter);
tv_load_filter(dev, NV_PTV_HFILTER2, state->hfilter2);
tv_load_filter(dev, NV_PTV_VFILTER, state->vfilter);
nv_load_ptv(dev, state, 200);
nv_load_ptv(dev, state, 204);
nv_load_ptv(dev, state, 208);
nv_load_ptv(dev, state, 20c);
nv_load_ptv(dev, state, 304);
nv_load_ptv(dev, state, 500);
nv_load_ptv(dev, state, 504);
nv_load_ptv(dev, state, 508);
nv_load_ptv(dev, state, 600);
nv_load_ptv(dev, state, 604);
nv_load_ptv(dev, state, 608);
nv_load_ptv(dev, state, 60c);
nv_load_ptv(dev, state, 610);
nv_load_ptv(dev, state, 614);
nv_write_tv_enc(dev, 0x3e, 1);
nv_write_tv_enc(dev, 0x3e, 0);
}
void nv17_tv_update_properties(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
struct nv17_tv_encoder *tv_enc = to_tv_enc(encoder);
struct nv17_tv_state *regs = &tv_enc->state;
struct nv17_tv_norm_params *tv_norm = get_tv_norm(encoder);
int subconnector = tv_enc->select_subconnector ?
tv_enc->select_subconnector :
tv_enc->subconnector;
switch (subconnector) {
case DRM_MODE_SUBCONNECTOR_Composite:
{
regs->ptv_204 = 0x2;
if (tv_enc->pin_mask & 0x4)
regs->ptv_204 |= 0x010000;
else if (tv_enc->pin_mask & 0x2)
regs->ptv_204 |= 0x100000;
else
regs->ptv_204 |= 0x110000;
regs->tv_enc[0x7] = 0x10;
break;
}
case DRM_MODE_SUBCONNECTOR_SVIDEO:
regs->ptv_204 = 0x11012;
regs->tv_enc[0x7] = 0x18;
break;
case DRM_MODE_SUBCONNECTOR_Component:
regs->ptv_204 = 0x111333;
regs->tv_enc[0x7] = 0x14;
break;
case DRM_MODE_SUBCONNECTOR_SCART:
regs->ptv_204 = 0x111012;
regs->tv_enc[0x7] = 0x18;
break;
}
regs->tv_enc[0x20] = interpolate(0, tv_norm->tv_enc_mode.tv_enc[0x20],
255, tv_enc->saturation);
regs->tv_enc[0x22] = interpolate(0, tv_norm->tv_enc_mode.tv_enc[0x22],
255, tv_enc->saturation);
regs->tv_enc[0x25] = tv_enc->hue * 255 / 100;
nv_load_ptv(dev, regs, 204);
nv_load_tv_enc(dev, regs, 7);
nv_load_tv_enc(dev, regs, 20);
nv_load_tv_enc(dev, regs, 22);
nv_load_tv_enc(dev, regs, 25);
}
void nv17_tv_update_rescaler(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
struct nv17_tv_encoder *tv_enc = to_tv_enc(encoder);
struct nv17_tv_state *regs = &tv_enc->state;
regs->ptv_208 = 0x40 | (calc_overscan(tv_enc->overscan) << 8);
tv_setup_filter(encoder);
nv_load_ptv(dev, regs, 208);
tv_load_filter(dev, NV_PTV_HFILTER, regs->hfilter);
tv_load_filter(dev, NV_PTV_HFILTER2, regs->hfilter2);
tv_load_filter(dev, NV_PTV_VFILTER, regs->vfilter);
}
void nv17_ctv_update_rescaler(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
struct nv17_tv_encoder *tv_enc = to_tv_enc(encoder);
int head = nouveau_crtc(encoder->crtc)->index;
struct nv04_crtc_reg *regs = &nv04_display(dev)->mode_reg.crtc_reg[head];
struct drm_display_mode *crtc_mode = &encoder->crtc->mode;
struct drm_display_mode *output_mode =
&get_tv_norm(encoder)->ctv_enc_mode.mode;
int overscan, hmargin, vmargin, hratio, vratio;
if (output_mode->flags & DRM_MODE_FLAG_INTERLACE)
overscan = 100;
else
overscan = tv_enc->overscan;
hmargin = (output_mode->hdisplay - crtc_mode->hdisplay) / 2;
vmargin = (output_mode->vdisplay - crtc_mode->vdisplay) / 2;
hmargin = interpolate(0, min(hmargin, output_mode->hdisplay/20),
hmargin, overscan);
vmargin = interpolate(0, min(vmargin, output_mode->vdisplay/20),
vmargin, overscan);
hratio = crtc_mode->hdisplay * 0x800 /
(output_mode->hdisplay - 2*hmargin);
vratio = crtc_mode->vdisplay * 0x800 /
(output_mode->vdisplay - 2*vmargin) & ~3;
regs->fp_horiz_regs[FP_VALID_START] = hmargin;
regs->fp_horiz_regs[FP_VALID_END] = output_mode->hdisplay - hmargin - 1;
regs->fp_vert_regs[FP_VALID_START] = vmargin;
regs->fp_vert_regs[FP_VALID_END] = output_mode->vdisplay - vmargin - 1;
regs->fp_debug_1 = NV_PRAMDAC_FP_DEBUG_1_YSCALE_TESTMODE_ENABLE |
XLATE(vratio, 0, NV_PRAMDAC_FP_DEBUG_1_YSCALE_VALUE) |
NV_PRAMDAC_FP_DEBUG_1_XSCALE_TESTMODE_ENABLE |
XLATE(hratio, 0, NV_PRAMDAC_FP_DEBUG_1_XSCALE_VALUE);
NVWriteRAMDAC(dev, head, NV_PRAMDAC_FP_HVALID_START,
regs->fp_horiz_regs[FP_VALID_START]);
NVWriteRAMDAC(dev, head, NV_PRAMDAC_FP_HVALID_END,
regs->fp_horiz_regs[FP_VALID_END]);
NVWriteRAMDAC(dev, head, NV_PRAMDAC_FP_VVALID_START,
regs->fp_vert_regs[FP_VALID_START]);
NVWriteRAMDAC(dev, head, NV_PRAMDAC_FP_VVALID_END,
regs->fp_vert_regs[FP_VALID_END]);
NVWriteRAMDAC(dev, head, NV_PRAMDAC_FP_DEBUG_1, regs->fp_debug_1);
}
