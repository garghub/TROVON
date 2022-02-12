static void
preview_config_luma_enhancement(struct isp_prev_device *prev,
const struct prev_params *params)
{
struct isp_device *isp = to_isp_device(prev);
const struct omap3isp_prev_luma *yt = &params->luma;
unsigned int i;
isp_reg_writel(isp, ISPPRV_YENH_TABLE_ADDR,
OMAP3_ISP_IOMEM_PREV, ISPPRV_SET_TBL_ADDR);
for (i = 0; i < OMAP3ISP_PREV_YENH_TBL_SIZE; i++) {
isp_reg_writel(isp, yt->table[i],
OMAP3_ISP_IOMEM_PREV, ISPPRV_SET_TBL_DATA);
}
}
static void
preview_enable_luma_enhancement(struct isp_prev_device *prev, bool enable)
{
struct isp_device *isp = to_isp_device(prev);
if (enable)
isp_reg_set(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_YNENHEN);
else
isp_reg_clr(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_YNENHEN);
}
static void preview_enable_invalaw(struct isp_prev_device *prev, bool enable)
{
struct isp_device *isp = to_isp_device(prev);
if (enable)
isp_reg_set(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_INVALAW);
else
isp_reg_clr(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_INVALAW);
}
static void preview_config_hmed(struct isp_prev_device *prev,
const struct prev_params *params)
{
struct isp_device *isp = to_isp_device(prev);
const struct omap3isp_prev_hmed *hmed = &params->hmed;
isp_reg_writel(isp, (hmed->odddist == 1 ? 0 : ISPPRV_HMED_ODDDIST) |
(hmed->evendist == 1 ? 0 : ISPPRV_HMED_EVENDIST) |
(hmed->thres << ISPPRV_HMED_THRESHOLD_SHIFT),
OMAP3_ISP_IOMEM_PREV, ISPPRV_HMED);
}
static void preview_enable_hmed(struct isp_prev_device *prev, bool enable)
{
struct isp_device *isp = to_isp_device(prev);
if (enable)
isp_reg_set(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_HMEDEN);
else
isp_reg_clr(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_HMEDEN);
}
static void preview_config_cfa(struct isp_prev_device *prev,
const struct prev_params *params)
{
static const unsigned int cfa_coef_order[4][4] = {
{ 0, 1, 2, 3 },
{ 1, 0, 3, 2 },
{ 2, 3, 0, 1 },
{ 3, 2, 1, 0 },
};
const unsigned int *order = cfa_coef_order[prev->params.cfa_order];
const struct omap3isp_prev_cfa *cfa = &params->cfa;
struct isp_device *isp = to_isp_device(prev);
unsigned int i;
unsigned int j;
isp_reg_writel(isp,
(cfa->gradthrs_vert << ISPPRV_CFA_GRADTH_VER_SHIFT) |
(cfa->gradthrs_horz << ISPPRV_CFA_GRADTH_HOR_SHIFT),
OMAP3_ISP_IOMEM_PREV, ISPPRV_CFA);
isp_reg_writel(isp, ISPPRV_CFA_TABLE_ADDR,
OMAP3_ISP_IOMEM_PREV, ISPPRV_SET_TBL_ADDR);
for (i = 0; i < 4; ++i) {
const __u32 *block = cfa->table[order[i]];
for (j = 0; j < OMAP3ISP_PREV_CFA_BLK_SIZE; ++j)
isp_reg_writel(isp, block[j], OMAP3_ISP_IOMEM_PREV,
ISPPRV_SET_TBL_DATA);
}
}
static void
preview_config_chroma_suppression(struct isp_prev_device *prev,
const struct prev_params *params)
{
struct isp_device *isp = to_isp_device(prev);
const struct omap3isp_prev_csup *cs = &params->csup;
isp_reg_writel(isp,
cs->gain | (cs->thres << ISPPRV_CSUP_THRES_SHIFT) |
(cs->hypf_en << ISPPRV_CSUP_HPYF_SHIFT),
OMAP3_ISP_IOMEM_PREV, ISPPRV_CSUP);
}
static void
preview_enable_chroma_suppression(struct isp_prev_device *prev, bool enable)
{
struct isp_device *isp = to_isp_device(prev);
if (enable)
isp_reg_set(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_SUPEN);
else
isp_reg_clr(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_SUPEN);
}
static void
preview_config_whitebalance(struct isp_prev_device *prev,
const struct prev_params *params)
{
struct isp_device *isp = to_isp_device(prev);
const struct omap3isp_prev_wbal *wbal = &params->wbal;
u32 val;
isp_reg_writel(isp, wbal->dgain, OMAP3_ISP_IOMEM_PREV, ISPPRV_WB_DGAIN);
val = wbal->coef0 << ISPPRV_WBGAIN_COEF0_SHIFT;
val |= wbal->coef1 << ISPPRV_WBGAIN_COEF1_SHIFT;
val |= wbal->coef2 << ISPPRV_WBGAIN_COEF2_SHIFT;
val |= wbal->coef3 << ISPPRV_WBGAIN_COEF3_SHIFT;
isp_reg_writel(isp, val, OMAP3_ISP_IOMEM_PREV, ISPPRV_WBGAIN);
isp_reg_writel(isp,
ISPPRV_WBSEL_COEF0 << ISPPRV_WBSEL_N0_0_SHIFT |
ISPPRV_WBSEL_COEF1 << ISPPRV_WBSEL_N0_1_SHIFT |
ISPPRV_WBSEL_COEF0 << ISPPRV_WBSEL_N0_2_SHIFT |
ISPPRV_WBSEL_COEF1 << ISPPRV_WBSEL_N0_3_SHIFT |
ISPPRV_WBSEL_COEF2 << ISPPRV_WBSEL_N1_0_SHIFT |
ISPPRV_WBSEL_COEF3 << ISPPRV_WBSEL_N1_1_SHIFT |
ISPPRV_WBSEL_COEF2 << ISPPRV_WBSEL_N1_2_SHIFT |
ISPPRV_WBSEL_COEF3 << ISPPRV_WBSEL_N1_3_SHIFT |
ISPPRV_WBSEL_COEF0 << ISPPRV_WBSEL_N2_0_SHIFT |
ISPPRV_WBSEL_COEF1 << ISPPRV_WBSEL_N2_1_SHIFT |
ISPPRV_WBSEL_COEF0 << ISPPRV_WBSEL_N2_2_SHIFT |
ISPPRV_WBSEL_COEF1 << ISPPRV_WBSEL_N2_3_SHIFT |
ISPPRV_WBSEL_COEF2 << ISPPRV_WBSEL_N3_0_SHIFT |
ISPPRV_WBSEL_COEF3 << ISPPRV_WBSEL_N3_1_SHIFT |
ISPPRV_WBSEL_COEF2 << ISPPRV_WBSEL_N3_2_SHIFT |
ISPPRV_WBSEL_COEF3 << ISPPRV_WBSEL_N3_3_SHIFT,
OMAP3_ISP_IOMEM_PREV, ISPPRV_WBSEL);
}
static void
preview_config_blkadj(struct isp_prev_device *prev,
const struct prev_params *params)
{
struct isp_device *isp = to_isp_device(prev);
const struct omap3isp_prev_blkadj *blkadj = &params->blkadj;
isp_reg_writel(isp, (blkadj->blue << ISPPRV_BLKADJOFF_B_SHIFT) |
(blkadj->green << ISPPRV_BLKADJOFF_G_SHIFT) |
(blkadj->red << ISPPRV_BLKADJOFF_R_SHIFT),
OMAP3_ISP_IOMEM_PREV, ISPPRV_BLKADJOFF);
}
static void
preview_config_rgb_blending(struct isp_prev_device *prev,
const struct prev_params *params)
{
struct isp_device *isp = to_isp_device(prev);
const struct omap3isp_prev_rgbtorgb *rgbrgb = &params->rgb2rgb;
u32 val;
val = (rgbrgb->matrix[0][0] & 0xfff) << ISPPRV_RGB_MAT1_MTX_RR_SHIFT;
val |= (rgbrgb->matrix[0][1] & 0xfff) << ISPPRV_RGB_MAT1_MTX_GR_SHIFT;
isp_reg_writel(isp, val, OMAP3_ISP_IOMEM_PREV, ISPPRV_RGB_MAT1);
val = (rgbrgb->matrix[0][2] & 0xfff) << ISPPRV_RGB_MAT2_MTX_BR_SHIFT;
val |= (rgbrgb->matrix[1][0] & 0xfff) << ISPPRV_RGB_MAT2_MTX_RG_SHIFT;
isp_reg_writel(isp, val, OMAP3_ISP_IOMEM_PREV, ISPPRV_RGB_MAT2);
val = (rgbrgb->matrix[1][1] & 0xfff) << ISPPRV_RGB_MAT3_MTX_GG_SHIFT;
val |= (rgbrgb->matrix[1][2] & 0xfff) << ISPPRV_RGB_MAT3_MTX_BG_SHIFT;
isp_reg_writel(isp, val, OMAP3_ISP_IOMEM_PREV, ISPPRV_RGB_MAT3);
val = (rgbrgb->matrix[2][0] & 0xfff) << ISPPRV_RGB_MAT4_MTX_RB_SHIFT;
val |= (rgbrgb->matrix[2][1] & 0xfff) << ISPPRV_RGB_MAT4_MTX_GB_SHIFT;
isp_reg_writel(isp, val, OMAP3_ISP_IOMEM_PREV, ISPPRV_RGB_MAT4);
val = (rgbrgb->matrix[2][2] & 0xfff) << ISPPRV_RGB_MAT5_MTX_BB_SHIFT;
isp_reg_writel(isp, val, OMAP3_ISP_IOMEM_PREV, ISPPRV_RGB_MAT5);
val = (rgbrgb->offset[0] & 0x3ff) << ISPPRV_RGB_OFF1_MTX_OFFR_SHIFT;
val |= (rgbrgb->offset[1] & 0x3ff) << ISPPRV_RGB_OFF1_MTX_OFFG_SHIFT;
isp_reg_writel(isp, val, OMAP3_ISP_IOMEM_PREV, ISPPRV_RGB_OFF1);
val = (rgbrgb->offset[2] & 0x3ff) << ISPPRV_RGB_OFF2_MTX_OFFB_SHIFT;
isp_reg_writel(isp, val, OMAP3_ISP_IOMEM_PREV, ISPPRV_RGB_OFF2);
}
static void
preview_config_csc(struct isp_prev_device *prev,
const struct prev_params *params)
{
struct isp_device *isp = to_isp_device(prev);
const struct omap3isp_prev_csc *csc = &params->csc;
u32 val;
val = (csc->matrix[0][0] & 0x3ff) << ISPPRV_CSC0_RY_SHIFT;
val |= (csc->matrix[0][1] & 0x3ff) << ISPPRV_CSC0_GY_SHIFT;
val |= (csc->matrix[0][2] & 0x3ff) << ISPPRV_CSC0_BY_SHIFT;
isp_reg_writel(isp, val, OMAP3_ISP_IOMEM_PREV, ISPPRV_CSC0);
val = (csc->matrix[1][0] & 0x3ff) << ISPPRV_CSC1_RCB_SHIFT;
val |= (csc->matrix[1][1] & 0x3ff) << ISPPRV_CSC1_GCB_SHIFT;
val |= (csc->matrix[1][2] & 0x3ff) << ISPPRV_CSC1_BCB_SHIFT;
isp_reg_writel(isp, val, OMAP3_ISP_IOMEM_PREV, ISPPRV_CSC1);
val = (csc->matrix[2][0] & 0x3ff) << ISPPRV_CSC2_RCR_SHIFT;
val |= (csc->matrix[2][1] & 0x3ff) << ISPPRV_CSC2_GCR_SHIFT;
val |= (csc->matrix[2][2] & 0x3ff) << ISPPRV_CSC2_BCR_SHIFT;
isp_reg_writel(isp, val, OMAP3_ISP_IOMEM_PREV, ISPPRV_CSC2);
val = (csc->offset[0] & 0xff) << ISPPRV_CSC_OFFSET_Y_SHIFT;
val |= (csc->offset[1] & 0xff) << ISPPRV_CSC_OFFSET_CB_SHIFT;
val |= (csc->offset[2] & 0xff) << ISPPRV_CSC_OFFSET_CR_SHIFT;
isp_reg_writel(isp, val, OMAP3_ISP_IOMEM_PREV, ISPPRV_CSC_OFFSET);
}
static void
preview_config_yc_range(struct isp_prev_device *prev,
const struct prev_params *params)
{
struct isp_device *isp = to_isp_device(prev);
const struct omap3isp_prev_yclimit *yc = &params->yclimit;
isp_reg_writel(isp,
yc->maxC << ISPPRV_SETUP_YC_MAXC_SHIFT |
yc->maxY << ISPPRV_SETUP_YC_MAXY_SHIFT |
yc->minC << ISPPRV_SETUP_YC_MINC_SHIFT |
yc->minY << ISPPRV_SETUP_YC_MINY_SHIFT,
OMAP3_ISP_IOMEM_PREV, ISPPRV_SETUP_YC);
}
static void
preview_config_dcor(struct isp_prev_device *prev,
const struct prev_params *params)
{
struct isp_device *isp = to_isp_device(prev);
const struct omap3isp_prev_dcor *dcor = &params->dcor;
isp_reg_writel(isp, dcor->detect_correct[0],
OMAP3_ISP_IOMEM_PREV, ISPPRV_CDC_THR0);
isp_reg_writel(isp, dcor->detect_correct[1],
OMAP3_ISP_IOMEM_PREV, ISPPRV_CDC_THR1);
isp_reg_writel(isp, dcor->detect_correct[2],
OMAP3_ISP_IOMEM_PREV, ISPPRV_CDC_THR2);
isp_reg_writel(isp, dcor->detect_correct[3],
OMAP3_ISP_IOMEM_PREV, ISPPRV_CDC_THR3);
isp_reg_clr_set(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_DCCOUP,
dcor->couplet_mode_en ? ISPPRV_PCR_DCCOUP : 0);
}
static void preview_enable_dcor(struct isp_prev_device *prev, bool enable)
{
struct isp_device *isp = to_isp_device(prev);
if (enable)
isp_reg_set(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_DCOREN);
else
isp_reg_clr(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_DCOREN);
}
static void
preview_enable_drkframe_capture(struct isp_prev_device *prev, bool enable)
{
struct isp_device *isp = to_isp_device(prev);
if (enable)
isp_reg_set(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_DRKFCAP);
else
isp_reg_clr(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_DRKFCAP);
}
static void preview_enable_drkframe(struct isp_prev_device *prev, bool enable)
{
struct isp_device *isp = to_isp_device(prev);
if (enable)
isp_reg_set(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_DRKFEN);
else
isp_reg_clr(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_DRKFEN);
}
static void
preview_config_noisefilter(struct isp_prev_device *prev,
const struct prev_params *params)
{
struct isp_device *isp = to_isp_device(prev);
const struct omap3isp_prev_nf *nf = &params->nf;
unsigned int i;
isp_reg_writel(isp, nf->spread, OMAP3_ISP_IOMEM_PREV, ISPPRV_NF);
isp_reg_writel(isp, ISPPRV_NF_TABLE_ADDR,
OMAP3_ISP_IOMEM_PREV, ISPPRV_SET_TBL_ADDR);
for (i = 0; i < OMAP3ISP_PREV_NF_TBL_SIZE; i++) {
isp_reg_writel(isp, nf->table[i],
OMAP3_ISP_IOMEM_PREV, ISPPRV_SET_TBL_DATA);
}
}
static void
preview_enable_noisefilter(struct isp_prev_device *prev, bool enable)
{
struct isp_device *isp = to_isp_device(prev);
if (enable)
isp_reg_set(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_NFEN);
else
isp_reg_clr(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_NFEN);
}
static void
preview_config_gammacorrn(struct isp_prev_device *prev,
const struct prev_params *params)
{
struct isp_device *isp = to_isp_device(prev);
const struct omap3isp_prev_gtables *gt = &params->gamma;
unsigned int i;
isp_reg_writel(isp, ISPPRV_REDGAMMA_TABLE_ADDR,
OMAP3_ISP_IOMEM_PREV, ISPPRV_SET_TBL_ADDR);
for (i = 0; i < OMAP3ISP_PREV_GAMMA_TBL_SIZE; i++)
isp_reg_writel(isp, gt->red[i], OMAP3_ISP_IOMEM_PREV,
ISPPRV_SET_TBL_DATA);
isp_reg_writel(isp, ISPPRV_GREENGAMMA_TABLE_ADDR,
OMAP3_ISP_IOMEM_PREV, ISPPRV_SET_TBL_ADDR);
for (i = 0; i < OMAP3ISP_PREV_GAMMA_TBL_SIZE; i++)
isp_reg_writel(isp, gt->green[i], OMAP3_ISP_IOMEM_PREV,
ISPPRV_SET_TBL_DATA);
isp_reg_writel(isp, ISPPRV_BLUEGAMMA_TABLE_ADDR,
OMAP3_ISP_IOMEM_PREV, ISPPRV_SET_TBL_ADDR);
for (i = 0; i < OMAP3ISP_PREV_GAMMA_TBL_SIZE; i++)
isp_reg_writel(isp, gt->blue[i], OMAP3_ISP_IOMEM_PREV,
ISPPRV_SET_TBL_DATA);
}
static void
preview_enable_gammacorrn(struct isp_prev_device *prev, bool enable)
{
struct isp_device *isp = to_isp_device(prev);
if (enable)
isp_reg_clr(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_GAMMA_BYPASS);
else
isp_reg_set(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_GAMMA_BYPASS);
}
static void
preview_config_contrast(struct isp_prev_device *prev,
const struct prev_params *params)
{
struct isp_device *isp = to_isp_device(prev);
isp_reg_clr_set(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_CNT_BRT,
0xff << ISPPRV_CNT_BRT_CNT_SHIFT,
params->contrast << ISPPRV_CNT_BRT_CNT_SHIFT);
}
static void
preview_config_brightness(struct isp_prev_device *prev,
const struct prev_params *params)
{
struct isp_device *isp = to_isp_device(prev);
isp_reg_clr_set(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_CNT_BRT,
0xff << ISPPRV_CNT_BRT_BRT_SHIFT,
params->brightness << ISPPRV_CNT_BRT_BRT_SHIFT);
}
static void
preview_update_contrast(struct isp_prev_device *prev, u8 contrast)
{
struct prev_params *params;
unsigned long flags;
spin_lock_irqsave(&prev->params.lock, flags);
params = (prev->params.active & OMAP3ISP_PREV_CONTRAST)
? &prev->params.params[0] : &prev->params.params[1];
if (params->contrast != (contrast * ISPPRV_CONTRAST_UNITS)) {
params->contrast = contrast * ISPPRV_CONTRAST_UNITS;
params->update |= OMAP3ISP_PREV_CONTRAST;
}
spin_unlock_irqrestore(&prev->params.lock, flags);
}
static void
preview_update_brightness(struct isp_prev_device *prev, u8 brightness)
{
struct prev_params *params;
unsigned long flags;
spin_lock_irqsave(&prev->params.lock, flags);
params = (prev->params.active & OMAP3ISP_PREV_BRIGHTNESS)
? &prev->params.params[0] : &prev->params.params[1];
if (params->brightness != (brightness * ISPPRV_BRIGHT_UNITS)) {
params->brightness = brightness * ISPPRV_BRIGHT_UNITS;
params->update |= OMAP3ISP_PREV_BRIGHTNESS;
}
spin_unlock_irqrestore(&prev->params.lock, flags);
}
static u32
preview_params_lock(struct isp_prev_device *prev, u32 update, bool shadow)
{
u32 active = prev->params.active;
if (shadow) {
prev->params.params[0].busy |= ~active & update;
prev->params.params[1].busy |= active & update;
} else {
update = (prev->params.params[0].update & active)
| (prev->params.params[1].update & ~active);
prev->params.params[0].busy |= active & update;
prev->params.params[1].busy |= ~active & update;
}
return update;
}
static void
preview_params_unlock(struct isp_prev_device *prev, u32 update, bool shadow)
{
u32 active = prev->params.active;
if (shadow) {
prev->params.params[0].update |= (~active & update);
prev->params.params[1].update |= (active & update);
prev->params.params[0].busy &= active;
prev->params.params[1].busy &= ~active;
} else {
prev->params.params[0].update &= ~(active & update);
prev->params.params[1].update &= ~(~active & update);
prev->params.params[0].busy &= ~active;
prev->params.params[1].busy &= active;
}
}
static void preview_params_switch(struct isp_prev_device *prev)
{
u32 to_switch;
to_switch = (prev->params.params[0].update & ~prev->params.active)
| (prev->params.params[1].update & prev->params.active);
to_switch &= ~(prev->params.params[0].busy |
prev->params.params[1].busy);
if (to_switch == 0)
return;
prev->params.active ^= to_switch;
prev->params.params[0].update &= ~(~prev->params.active & to_switch);
prev->params.params[1].update &= ~(prev->params.active & to_switch);
}
static int preview_config(struct isp_prev_device *prev,
struct omap3isp_prev_update_config *cfg)
{
unsigned long flags;
unsigned int i;
int rval = 0;
u32 update;
u32 active;
if (cfg->update == 0)
return 0;
spin_lock_irqsave(&prev->params.lock, flags);
preview_params_lock(prev, cfg->update, true);
active = prev->params.active;
spin_unlock_irqrestore(&prev->params.lock, flags);
update = 0;
for (i = 0; i < ARRAY_SIZE(update_attrs); i++) {
const struct preview_update *attr = &update_attrs[i];
struct prev_params *params;
unsigned int bit = 1 << i;
if (attr->skip || !(cfg->update & bit))
continue;
params = &prev->params.params[!!(active & bit)];
if (cfg->flag & bit) {
void __user *from = *(void * __user *)
((void *)cfg + attr->config_offset);
void *to = (void *)params + attr->param_offset;
size_t size = attr->param_size;
if (to && from && size) {
if (copy_from_user(to, from, size)) {
rval = -EFAULT;
break;
}
}
params->features |= bit;
} else {
params->features &= ~bit;
}
update |= bit;
}
spin_lock_irqsave(&prev->params.lock, flags);
preview_params_unlock(prev, update, true);
preview_params_switch(prev);
spin_unlock_irqrestore(&prev->params.lock, flags);
return rval;
}
static void preview_setup_hw(struct isp_prev_device *prev, u32 update,
u32 active)
{
unsigned int i;
u32 features;
if (update == 0)
return;
features = (prev->params.params[0].features & active)
| (prev->params.params[1].features & ~active);
for (i = 0; i < ARRAY_SIZE(update_attrs); i++) {
const struct preview_update *attr = &update_attrs[i];
struct prev_params *params;
unsigned int bit = 1 << i;
if (!(update & bit))
continue;
params = &prev->params.params[!(active & bit)];
if (params->features & bit) {
if (attr->config)
attr->config(prev, params);
if (attr->enable)
attr->enable(prev, true);
} else {
if (attr->enable)
attr->enable(prev, false);
}
}
}
static void preview_config_ycpos(struct isp_prev_device *prev, u32 pixelcode)
{
struct isp_device *isp = to_isp_device(prev);
enum preview_ycpos_mode mode;
switch (pixelcode) {
case MEDIA_BUS_FMT_YUYV8_1X16:
mode = YCPOS_CrYCbY;
break;
case MEDIA_BUS_FMT_UYVY8_1X16:
mode = YCPOS_YCrYCb;
break;
default:
return;
}
isp_reg_clr_set(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_YCPOS_CrYCbY,
mode << ISPPRV_PCR_YCPOS_SHIFT);
}
static void preview_config_averager(struct isp_prev_device *prev, u8 average)
{
struct isp_device *isp = to_isp_device(prev);
isp_reg_writel(isp, ISPPRV_AVE_EVENDIST_2 << ISPPRV_AVE_EVENDIST_SHIFT |
ISPPRV_AVE_ODDDIST_2 << ISPPRV_AVE_ODDDIST_SHIFT |
average, OMAP3_ISP_IOMEM_PREV, ISPPRV_AVE);
}
static void preview_config_input_format(struct isp_prev_device *prev,
const struct isp_format_info *info)
{
struct isp_device *isp = to_isp_device(prev);
struct prev_params *params;
if (info->width == 8)
isp_reg_set(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_WIDTH);
else
isp_reg_clr(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_WIDTH);
switch (info->flavor) {
case MEDIA_BUS_FMT_SGRBG8_1X8:
prev->params.cfa_order = 0;
break;
case MEDIA_BUS_FMT_SRGGB8_1X8:
prev->params.cfa_order = 1;
break;
case MEDIA_BUS_FMT_SBGGR8_1X8:
prev->params.cfa_order = 2;
break;
case MEDIA_BUS_FMT_SGBRG8_1X8:
prev->params.cfa_order = 3;
break;
default:
isp_reg_clr(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_CFAEN);
return;
}
isp_reg_set(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR, ISPPRV_PCR_CFAEN);
isp_reg_clr_set(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_CFAFMT_MASK, ISPPRV_PCR_CFAFMT_BAYER);
params = (prev->params.active & OMAP3ISP_PREV_CFA)
? &prev->params.params[0] : &prev->params.params[1];
preview_config_cfa(prev, params);
}
static void preview_config_input_size(struct isp_prev_device *prev, u32 active)
{
const struct v4l2_mbus_framefmt *format = &prev->formats[PREV_PAD_SINK];
struct isp_device *isp = to_isp_device(prev);
unsigned int sph = prev->crop.left;
unsigned int eph = prev->crop.left + prev->crop.width - 1;
unsigned int slv = prev->crop.top;
unsigned int elv = prev->crop.top + prev->crop.height - 1;
u32 features;
if (format->code != MEDIA_BUS_FMT_Y8_1X8 &&
format->code != MEDIA_BUS_FMT_Y10_1X10) {
sph -= 2;
eph += 2;
slv -= 2;
elv += 2;
}
features = (prev->params.params[0].features & active)
| (prev->params.params[1].features & ~active);
if (features & (OMAP3ISP_PREV_DEFECT_COR | OMAP3ISP_PREV_NF)) {
sph -= 2;
eph += 2;
slv -= 2;
elv += 2;
}
if (features & OMAP3ISP_PREV_HRZ_MED) {
sph -= 2;
eph += 2;
}
if (features & (OMAP3ISP_PREV_CHROMA_SUPP | OMAP3ISP_PREV_LUMAENH))
sph -= 2;
isp_reg_writel(isp, (sph << ISPPRV_HORZ_INFO_SPH_SHIFT) | eph,
OMAP3_ISP_IOMEM_PREV, ISPPRV_HORZ_INFO);
isp_reg_writel(isp, (slv << ISPPRV_VERT_INFO_SLV_SHIFT) | elv,
OMAP3_ISP_IOMEM_PREV, ISPPRV_VERT_INFO);
}
static void
preview_config_inlineoffset(struct isp_prev_device *prev, u32 offset)
{
struct isp_device *isp = to_isp_device(prev);
isp_reg_writel(isp, offset & 0xffff, OMAP3_ISP_IOMEM_PREV,
ISPPRV_RADR_OFFSET);
}
static void preview_set_inaddr(struct isp_prev_device *prev, u32 addr)
{
struct isp_device *isp = to_isp_device(prev);
isp_reg_writel(isp, addr, OMAP3_ISP_IOMEM_PREV, ISPPRV_RSDR_ADDR);
}
static void preview_config_outlineoffset(struct isp_prev_device *prev,
u32 offset)
{
struct isp_device *isp = to_isp_device(prev);
isp_reg_writel(isp, offset & 0xffff, OMAP3_ISP_IOMEM_PREV,
ISPPRV_WADD_OFFSET);
}
static void preview_set_outaddr(struct isp_prev_device *prev, u32 addr)
{
struct isp_device *isp = to_isp_device(prev);
isp_reg_writel(isp, addr, OMAP3_ISP_IOMEM_PREV, ISPPRV_WSDR_ADDR);
}
static void preview_adjust_bandwidth(struct isp_prev_device *prev)
{
struct isp_pipeline *pipe = to_isp_pipeline(&prev->subdev.entity);
struct isp_device *isp = to_isp_device(prev);
const struct v4l2_mbus_framefmt *ifmt = &prev->formats[PREV_PAD_SINK];
unsigned long l3_ick = pipe->l3_ick;
struct v4l2_fract *timeperframe;
unsigned int cycles_per_frame;
unsigned int requests_per_frame;
unsigned int cycles_per_request;
unsigned int minimum;
unsigned int maximum;
unsigned int value;
if (prev->input != PREVIEW_INPUT_MEMORY) {
isp_reg_clr(isp, OMAP3_ISP_IOMEM_SBL, ISPSBL_SDR_REQ_EXP,
ISPSBL_SDR_REQ_PRV_EXP_MASK);
return;
}
cycles_per_request = div_u64((u64)l3_ick / 2 * 256 + pipe->max_rate - 1,
pipe->max_rate);
minimum = DIV_ROUND_UP(cycles_per_request, 32);
timeperframe = &pipe->max_timeperframe;
requests_per_frame = DIV_ROUND_UP(ifmt->width * 2, 256) * ifmt->height;
cycles_per_frame = div_u64((u64)l3_ick * timeperframe->numerator,
timeperframe->denominator);
cycles_per_request = cycles_per_frame / requests_per_frame;
maximum = cycles_per_request / 32;
value = max(minimum, maximum);
dev_dbg(isp->dev, "%s: cycles per request = %u\n", __func__, value);
isp_reg_clr_set(isp, OMAP3_ISP_IOMEM_SBL, ISPSBL_SDR_REQ_EXP,
ISPSBL_SDR_REQ_PRV_EXP_MASK,
value << ISPSBL_SDR_REQ_PRV_EXP_SHIFT);
}
int omap3isp_preview_busy(struct isp_prev_device *prev)
{
struct isp_device *isp = to_isp_device(prev);
return isp_reg_readl(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR)
& ISPPRV_PCR_BUSY;
}
void omap3isp_preview_restore_context(struct isp_device *isp)
{
struct isp_prev_device *prev = &isp->isp_prev;
const u32 update = OMAP3ISP_PREV_FEATURES_END - 1;
prev->params.params[0].update = prev->params.active & update;
prev->params.params[1].update = ~prev->params.active & update;
preview_setup_hw(prev, update, prev->params.active);
prev->params.params[0].update = 0;
prev->params.params[1].update = 0;
}
static void preview_print_status(struct isp_prev_device *prev)
{
struct isp_device *isp = to_isp_device(prev);
dev_dbg(isp->dev, "-------------Preview Register dump----------\n");
PREV_PRINT_REGISTER(isp, PCR);
PREV_PRINT_REGISTER(isp, HORZ_INFO);
PREV_PRINT_REGISTER(isp, VERT_INFO);
PREV_PRINT_REGISTER(isp, RSDR_ADDR);
PREV_PRINT_REGISTER(isp, RADR_OFFSET);
PREV_PRINT_REGISTER(isp, DSDR_ADDR);
PREV_PRINT_REGISTER(isp, DRKF_OFFSET);
PREV_PRINT_REGISTER(isp, WSDR_ADDR);
PREV_PRINT_REGISTER(isp, WADD_OFFSET);
PREV_PRINT_REGISTER(isp, AVE);
PREV_PRINT_REGISTER(isp, HMED);
PREV_PRINT_REGISTER(isp, NF);
PREV_PRINT_REGISTER(isp, WB_DGAIN);
PREV_PRINT_REGISTER(isp, WBGAIN);
PREV_PRINT_REGISTER(isp, WBSEL);
PREV_PRINT_REGISTER(isp, CFA);
PREV_PRINT_REGISTER(isp, BLKADJOFF);
PREV_PRINT_REGISTER(isp, RGB_MAT1);
PREV_PRINT_REGISTER(isp, RGB_MAT2);
PREV_PRINT_REGISTER(isp, RGB_MAT3);
PREV_PRINT_REGISTER(isp, RGB_MAT4);
PREV_PRINT_REGISTER(isp, RGB_MAT5);
PREV_PRINT_REGISTER(isp, RGB_OFF1);
PREV_PRINT_REGISTER(isp, RGB_OFF2);
PREV_PRINT_REGISTER(isp, CSC0);
PREV_PRINT_REGISTER(isp, CSC1);
PREV_PRINT_REGISTER(isp, CSC2);
PREV_PRINT_REGISTER(isp, CSC_OFFSET);
PREV_PRINT_REGISTER(isp, CNT_BRT);
PREV_PRINT_REGISTER(isp, CSUP);
PREV_PRINT_REGISTER(isp, SETUP_YC);
PREV_PRINT_REGISTER(isp, SET_TBL_ADDR);
PREV_PRINT_REGISTER(isp, CDC_THR0);
PREV_PRINT_REGISTER(isp, CDC_THR1);
PREV_PRINT_REGISTER(isp, CDC_THR2);
PREV_PRINT_REGISTER(isp, CDC_THR3);
dev_dbg(isp->dev, "--------------------------------------------\n");
}
static void preview_init_params(struct isp_prev_device *prev)
{
struct prev_params *params;
unsigned int i;
spin_lock_init(&prev->params.lock);
prev->params.active = ~0;
prev->params.params[0].busy = 0;
prev->params.params[0].update = OMAP3ISP_PREV_FEATURES_END - 1;
prev->params.params[1].busy = 0;
prev->params.params[1].update = 0;
params = &prev->params.params[0];
params->contrast = ISPPRV_CONTRAST_DEF * ISPPRV_CONTRAST_UNITS;
params->brightness = ISPPRV_BRIGHT_DEF * ISPPRV_BRIGHT_UNITS;
params->cfa.format = OMAP3ISP_CFAFMT_BAYER;
memcpy(params->cfa.table, cfa_coef_table,
sizeof(params->cfa.table));
params->cfa.gradthrs_horz = FLR_CFA_GRADTHRS_HORZ;
params->cfa.gradthrs_vert = FLR_CFA_GRADTHRS_VERT;
params->csup.gain = FLR_CSUP_GAIN;
params->csup.thres = FLR_CSUP_THRES;
params->csup.hypf_en = 0;
memcpy(params->luma.table, luma_enhance_table,
sizeof(params->luma.table));
params->nf.spread = FLR_NF_STRGTH;
memcpy(params->nf.table, noise_filter_table, sizeof(params->nf.table));
params->dcor.couplet_mode_en = 1;
for (i = 0; i < OMAP3ISP_PREV_DETECT_CORRECT_CHANNELS; i++)
params->dcor.detect_correct[i] = DEF_DETECT_CORRECT_VAL;
memcpy(params->gamma.blue, gamma_table, sizeof(params->gamma.blue));
memcpy(params->gamma.green, gamma_table, sizeof(params->gamma.green));
memcpy(params->gamma.red, gamma_table, sizeof(params->gamma.red));
params->wbal.dgain = FLR_WBAL_DGAIN;
params->wbal.coef0 = FLR_WBAL_COEF;
params->wbal.coef1 = FLR_WBAL_COEF;
params->wbal.coef2 = FLR_WBAL_COEF;
params->wbal.coef3 = FLR_WBAL_COEF;
params->blkadj.red = FLR_BLKADJ_RED;
params->blkadj.green = FLR_BLKADJ_GREEN;
params->blkadj.blue = FLR_BLKADJ_BLUE;
params->rgb2rgb = flr_rgb2rgb;
params->csc = flr_prev_csc;
params->yclimit.minC = ISPPRV_YC_MIN;
params->yclimit.maxC = ISPPRV_YC_MAX;
params->yclimit.minY = ISPPRV_YC_MIN;
params->yclimit.maxY = ISPPRV_YC_MAX;
params->features = OMAP3ISP_PREV_CFA | OMAP3ISP_PREV_DEFECT_COR
| OMAP3ISP_PREV_NF | OMAP3ISP_PREV_GAMMA
| OMAP3ISP_PREV_BLKADJ | OMAP3ISP_PREV_YC_LIMIT
| OMAP3ISP_PREV_RGB2RGB | OMAP3ISP_PREV_COLOR_CONV
| OMAP3ISP_PREV_WB | OMAP3ISP_PREV_BRIGHTNESS
| OMAP3ISP_PREV_CONTRAST;
}
static unsigned int preview_max_out_width(struct isp_prev_device *prev)
{
struct isp_device *isp = to_isp_device(prev);
switch (isp->revision) {
case ISP_REVISION_1_0:
return PREV_MAX_OUT_WIDTH_REV_1;
case ISP_REVISION_2_0:
default:
return PREV_MAX_OUT_WIDTH_REV_2;
case ISP_REVISION_15_0:
return PREV_MAX_OUT_WIDTH_REV_15;
}
}
static void preview_configure(struct isp_prev_device *prev)
{
struct isp_device *isp = to_isp_device(prev);
const struct isp_format_info *info;
struct v4l2_mbus_framefmt *format;
unsigned long flags;
u32 update;
u32 active;
spin_lock_irqsave(&prev->params.lock, flags);
update = preview_params_lock(prev, 0, false);
active = prev->params.active;
spin_unlock_irqrestore(&prev->params.lock, flags);
format = &prev->formats[PREV_PAD_SINK];
info = omap3isp_video_format_info(format->code);
preview_adjust_bandwidth(prev);
preview_config_input_format(prev, info);
preview_config_input_size(prev, active);
if (prev->input == PREVIEW_INPUT_CCDC)
preview_config_inlineoffset(prev, 0);
else
preview_config_inlineoffset(prev, ALIGN(format->width, 0x20) *
info->bpp);
preview_setup_hw(prev, update, active);
format = &prev->formats[PREV_PAD_SOURCE];
if (prev->output & PREVIEW_OUTPUT_MEMORY)
isp_reg_set(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_SDRPORT);
else
isp_reg_clr(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_SDRPORT);
if (prev->output & PREVIEW_OUTPUT_RESIZER)
isp_reg_set(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_RSZPORT);
else
isp_reg_clr(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_RSZPORT);
if (prev->output & PREVIEW_OUTPUT_MEMORY)
preview_config_outlineoffset(prev,
ALIGN(format->width, 0x10) * 2);
preview_config_averager(prev, 0);
preview_config_ycpos(prev, format->code);
spin_lock_irqsave(&prev->params.lock, flags);
preview_params_unlock(prev, update, false);
spin_unlock_irqrestore(&prev->params.lock, flags);
}
static void preview_enable_oneshot(struct isp_prev_device *prev)
{
struct isp_device *isp = to_isp_device(prev);
if (prev->input == PREVIEW_INPUT_MEMORY)
isp_reg_set(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_SOURCE);
isp_reg_set(isp, OMAP3_ISP_IOMEM_PREV, ISPPRV_PCR,
ISPPRV_PCR_EN | ISPPRV_PCR_ONESHOT);
}
void omap3isp_preview_isr_frame_sync(struct isp_prev_device *prev)
{
if (prev->state == ISP_PIPELINE_STREAM_CONTINUOUS &&
prev->video_out.dmaqueue_flags & ISP_VIDEO_DMAQUEUE_QUEUED) {
preview_enable_oneshot(prev);
isp_video_dmaqueue_flags_clr(&prev->video_out);
}
}
static void preview_isr_buffer(struct isp_prev_device *prev)
{
struct isp_pipeline *pipe = to_isp_pipeline(&prev->subdev.entity);
struct isp_buffer *buffer;
int restart = 0;
if (prev->input == PREVIEW_INPUT_MEMORY) {
buffer = omap3isp_video_buffer_next(&prev->video_in);
if (buffer != NULL)
preview_set_inaddr(prev, buffer->dma);
pipe->state |= ISP_PIPELINE_IDLE_INPUT;
}
if (prev->output & PREVIEW_OUTPUT_MEMORY) {
buffer = omap3isp_video_buffer_next(&prev->video_out);
if (buffer != NULL) {
preview_set_outaddr(prev, buffer->dma);
restart = 1;
}
pipe->state |= ISP_PIPELINE_IDLE_OUTPUT;
}
switch (prev->state) {
case ISP_PIPELINE_STREAM_SINGLESHOT:
if (isp_pipeline_ready(pipe))
omap3isp_pipeline_set_stream(pipe,
ISP_PIPELINE_STREAM_SINGLESHOT);
break;
case ISP_PIPELINE_STREAM_CONTINUOUS:
if (restart)
preview_enable_oneshot(prev);
break;
case ISP_PIPELINE_STREAM_STOPPED:
default:
return;
}
}
void omap3isp_preview_isr(struct isp_prev_device *prev)
{
unsigned long flags;
u32 update;
u32 active;
if (omap3isp_module_sync_is_stopping(&prev->wait, &prev->stopping))
return;
spin_lock_irqsave(&prev->params.lock, flags);
preview_params_switch(prev);
update = preview_params_lock(prev, 0, false);
active = prev->params.active;
spin_unlock_irqrestore(&prev->params.lock, flags);
preview_setup_hw(prev, update, active);
preview_config_input_size(prev, active);
if (prev->input == PREVIEW_INPUT_MEMORY ||
prev->output & PREVIEW_OUTPUT_MEMORY)
preview_isr_buffer(prev);
else if (prev->state == ISP_PIPELINE_STREAM_CONTINUOUS)
preview_enable_oneshot(prev);
spin_lock_irqsave(&prev->params.lock, flags);
preview_params_unlock(prev, update, false);
spin_unlock_irqrestore(&prev->params.lock, flags);
}
static int preview_video_queue(struct isp_video *video,
struct isp_buffer *buffer)
{
struct isp_prev_device *prev = &video->isp->isp_prev;
if (video->type == V4L2_BUF_TYPE_VIDEO_OUTPUT)
preview_set_inaddr(prev, buffer->dma);
if (video->type == V4L2_BUF_TYPE_VIDEO_CAPTURE)
preview_set_outaddr(prev, buffer->dma);
return 0;
}
static int preview_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct isp_prev_device *prev =
container_of(ctrl->handler, struct isp_prev_device, ctrls);
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
preview_update_brightness(prev, ctrl->val);
break;
case V4L2_CID_CONTRAST:
preview_update_contrast(prev, ctrl->val);
break;
}
return 0;
}
static long preview_ioctl(struct v4l2_subdev *sd, unsigned int cmd, void *arg)
{
struct isp_prev_device *prev = v4l2_get_subdevdata(sd);
switch (cmd) {
case VIDIOC_OMAP3ISP_PRV_CFG:
return preview_config(prev, arg);
default:
return -ENOIOCTLCMD;
}
}
static int preview_set_stream(struct v4l2_subdev *sd, int enable)
{
struct isp_prev_device *prev = v4l2_get_subdevdata(sd);
struct isp_video *video_out = &prev->video_out;
struct isp_device *isp = to_isp_device(prev);
struct device *dev = to_device(prev);
if (prev->state == ISP_PIPELINE_STREAM_STOPPED) {
if (enable == ISP_PIPELINE_STREAM_STOPPED)
return 0;
omap3isp_subclk_enable(isp, OMAP3_ISP_SUBCLK_PREVIEW);
preview_configure(prev);
atomic_set(&prev->stopping, 0);
preview_print_status(prev);
}
switch (enable) {
case ISP_PIPELINE_STREAM_CONTINUOUS:
if (prev->output & PREVIEW_OUTPUT_MEMORY)
omap3isp_sbl_enable(isp, OMAP3_ISP_SBL_PREVIEW_WRITE);
if (video_out->dmaqueue_flags & ISP_VIDEO_DMAQUEUE_QUEUED ||
!(prev->output & PREVIEW_OUTPUT_MEMORY))
preview_enable_oneshot(prev);
isp_video_dmaqueue_flags_clr(video_out);
break;
case ISP_PIPELINE_STREAM_SINGLESHOT:
if (prev->input == PREVIEW_INPUT_MEMORY)
omap3isp_sbl_enable(isp, OMAP3_ISP_SBL_PREVIEW_READ);
if (prev->output & PREVIEW_OUTPUT_MEMORY)
omap3isp_sbl_enable(isp, OMAP3_ISP_SBL_PREVIEW_WRITE);
preview_enable_oneshot(prev);
break;
case ISP_PIPELINE_STREAM_STOPPED:
if (omap3isp_module_sync_idle(&sd->entity, &prev->wait,
&prev->stopping))
dev_dbg(dev, "%s: stop timeout.\n", sd->name);
omap3isp_sbl_disable(isp, OMAP3_ISP_SBL_PREVIEW_READ);
omap3isp_sbl_disable(isp, OMAP3_ISP_SBL_PREVIEW_WRITE);
omap3isp_subclk_disable(isp, OMAP3_ISP_SUBCLK_PREVIEW);
isp_video_dmaqueue_flags_clr(video_out);
break;
}
prev->state = enable;
return 0;
}
static struct v4l2_mbus_framefmt *
__preview_get_format(struct isp_prev_device *prev, struct v4l2_subdev_pad_config *cfg,
unsigned int pad, enum v4l2_subdev_format_whence which)
{
if (which == V4L2_SUBDEV_FORMAT_TRY)
return v4l2_subdev_get_try_format(&prev->subdev, cfg, pad);
else
return &prev->formats[pad];
}
static struct v4l2_rect *
__preview_get_crop(struct isp_prev_device *prev, struct v4l2_subdev_pad_config *cfg,
enum v4l2_subdev_format_whence which)
{
if (which == V4L2_SUBDEV_FORMAT_TRY)
return v4l2_subdev_get_try_crop(&prev->subdev, cfg, PREV_PAD_SINK);
else
return &prev->crop;
}
static void preview_try_format(struct isp_prev_device *prev,
struct v4l2_subdev_pad_config *cfg, unsigned int pad,
struct v4l2_mbus_framefmt *fmt,
enum v4l2_subdev_format_whence which)
{
u32 pixelcode;
struct v4l2_rect *crop;
unsigned int i;
switch (pad) {
case PREV_PAD_SINK:
if (prev->input == PREVIEW_INPUT_MEMORY) {
fmt->width = clamp_t(u32, fmt->width, PREV_MIN_IN_WIDTH,
preview_max_out_width(prev));
fmt->height = clamp_t(u32, fmt->height,
PREV_MIN_IN_HEIGHT,
PREV_MAX_IN_HEIGHT);
}
fmt->colorspace = V4L2_COLORSPACE_SRGB;
for (i = 0; i < ARRAY_SIZE(preview_input_fmts); i++) {
if (fmt->code == preview_input_fmts[i])
break;
}
if (i >= ARRAY_SIZE(preview_input_fmts))
fmt->code = MEDIA_BUS_FMT_SGRBG10_1X10;
break;
case PREV_PAD_SOURCE:
pixelcode = fmt->code;
*fmt = *__preview_get_format(prev, cfg, PREV_PAD_SINK, which);
switch (pixelcode) {
case MEDIA_BUS_FMT_YUYV8_1X16:
case MEDIA_BUS_FMT_UYVY8_1X16:
fmt->code = pixelcode;
break;
default:
fmt->code = MEDIA_BUS_FMT_YUYV8_1X16;
break;
}
crop = __preview_get_crop(prev, cfg, which);
fmt->width = crop->width;
fmt->height = crop->height;
fmt->colorspace = V4L2_COLORSPACE_JPEG;
break;
}
fmt->field = V4L2_FIELD_NONE;
}
static void preview_try_crop(struct isp_prev_device *prev,
const struct v4l2_mbus_framefmt *sink,
struct v4l2_rect *crop)
{
unsigned int left = PREV_MARGIN_LEFT;
unsigned int right = sink->width - PREV_MARGIN_RIGHT;
unsigned int top = PREV_MARGIN_TOP;
unsigned int bottom = sink->height - PREV_MARGIN_BOTTOM;
if (prev->input == PREVIEW_INPUT_CCDC) {
left += 2;
right -= 2;
}
if (sink->code != MEDIA_BUS_FMT_Y8_1X8 &&
sink->code != MEDIA_BUS_FMT_Y10_1X10) {
left += 2;
right -= 2;
top += 2;
bottom -= 2;
}
crop->left &= ~1;
crop->top &= ~1;
crop->left = clamp_t(u32, crop->left, left, right - PREV_MIN_OUT_WIDTH);
crop->top = clamp_t(u32, crop->top, top, bottom - PREV_MIN_OUT_HEIGHT);
crop->width = clamp_t(u32, crop->width, PREV_MIN_OUT_WIDTH,
right - crop->left);
crop->height = clamp_t(u32, crop->height, PREV_MIN_OUT_HEIGHT,
bottom - crop->top);
}
static int preview_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
switch (code->pad) {
case PREV_PAD_SINK:
if (code->index >= ARRAY_SIZE(preview_input_fmts))
return -EINVAL;
code->code = preview_input_fmts[code->index];
break;
case PREV_PAD_SOURCE:
if (code->index >= ARRAY_SIZE(preview_output_fmts))
return -EINVAL;
code->code = preview_output_fmts[code->index];
break;
default:
return -EINVAL;
}
return 0;
}
static int preview_enum_frame_size(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
struct isp_prev_device *prev = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt format;
if (fse->index != 0)
return -EINVAL;
format.code = fse->code;
format.width = 1;
format.height = 1;
preview_try_format(prev, cfg, fse->pad, &format, fse->which);
fse->min_width = format.width;
fse->min_height = format.height;
if (format.code != fse->code)
return -EINVAL;
format.code = fse->code;
format.width = -1;
format.height = -1;
preview_try_format(prev, cfg, fse->pad, &format, fse->which);
fse->max_width = format.width;
fse->max_height = format.height;
return 0;
}
static int preview_get_selection(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_selection *sel)
{
struct isp_prev_device *prev = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
if (sel->pad != PREV_PAD_SINK)
return -EINVAL;
switch (sel->target) {
case V4L2_SEL_TGT_CROP_BOUNDS:
sel->r.left = 0;
sel->r.top = 0;
sel->r.width = INT_MAX;
sel->r.height = INT_MAX;
format = __preview_get_format(prev, cfg, PREV_PAD_SINK,
sel->which);
preview_try_crop(prev, format, &sel->r);
break;
case V4L2_SEL_TGT_CROP:
sel->r = *__preview_get_crop(prev, cfg, sel->which);
break;
default:
return -EINVAL;
}
return 0;
}
static int preview_set_selection(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_selection *sel)
{
struct isp_prev_device *prev = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
if (sel->target != V4L2_SEL_TGT_CROP ||
sel->pad != PREV_PAD_SINK)
return -EINVAL;
if (prev->state != ISP_PIPELINE_STREAM_STOPPED)
return -EBUSY;
if (sel->flags & V4L2_SEL_FLAG_KEEP_CONFIG) {
sel->r = *__preview_get_crop(prev, cfg, sel->which);
return 0;
}
format = __preview_get_format(prev, cfg, PREV_PAD_SINK, sel->which);
preview_try_crop(prev, format, &sel->r);
*__preview_get_crop(prev, cfg, sel->which) = sel->r;
format = __preview_get_format(prev, cfg, PREV_PAD_SOURCE, sel->which);
preview_try_format(prev, cfg, PREV_PAD_SOURCE, format, sel->which);
return 0;
}
static int preview_get_format(struct v4l2_subdev *sd, struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct isp_prev_device *prev = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
format = __preview_get_format(prev, cfg, fmt->pad, fmt->which);
if (format == NULL)
return -EINVAL;
fmt->format = *format;
return 0;
}
static int preview_set_format(struct v4l2_subdev *sd, struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct isp_prev_device *prev = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
struct v4l2_rect *crop;
format = __preview_get_format(prev, cfg, fmt->pad, fmt->which);
if (format == NULL)
return -EINVAL;
preview_try_format(prev, cfg, fmt->pad, &fmt->format, fmt->which);
*format = fmt->format;
if (fmt->pad == PREV_PAD_SINK) {
crop = __preview_get_crop(prev, cfg, fmt->which);
crop->left = 0;
crop->top = 0;
crop->width = fmt->format.width;
crop->height = fmt->format.height;
preview_try_crop(prev, &fmt->format, crop);
format = __preview_get_format(prev, cfg, PREV_PAD_SOURCE,
fmt->which);
preview_try_format(prev, cfg, PREV_PAD_SOURCE, format,
fmt->which);
}
return 0;
}
static int preview_init_formats(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh)
{
struct v4l2_subdev_format format;
memset(&format, 0, sizeof(format));
format.pad = PREV_PAD_SINK;
format.which = fh ? V4L2_SUBDEV_FORMAT_TRY : V4L2_SUBDEV_FORMAT_ACTIVE;
format.format.code = MEDIA_BUS_FMT_SGRBG10_1X10;
format.format.width = 4096;
format.format.height = 4096;
preview_set_format(sd, fh ? fh->pad : NULL, &format);
return 0;
}
static int preview_link_setup(struct media_entity *entity,
const struct media_pad *local,
const struct media_pad *remote, u32 flags)
{
struct v4l2_subdev *sd = media_entity_to_v4l2_subdev(entity);
struct isp_prev_device *prev = v4l2_get_subdevdata(sd);
switch (local->index | media_entity_type(remote->entity)) {
case PREV_PAD_SINK | MEDIA_ENT_T_DEVNODE:
if (flags & MEDIA_LNK_FL_ENABLED) {
if (prev->input == PREVIEW_INPUT_CCDC)
return -EBUSY;
prev->input = PREVIEW_INPUT_MEMORY;
} else {
if (prev->input == PREVIEW_INPUT_MEMORY)
prev->input = PREVIEW_INPUT_NONE;
}
break;
case PREV_PAD_SINK | MEDIA_ENT_T_V4L2_SUBDEV:
if (flags & MEDIA_LNK_FL_ENABLED) {
if (prev->input == PREVIEW_INPUT_MEMORY)
return -EBUSY;
prev->input = PREVIEW_INPUT_CCDC;
} else {
if (prev->input == PREVIEW_INPUT_CCDC)
prev->input = PREVIEW_INPUT_NONE;
}
break;
case PREV_PAD_SOURCE | MEDIA_ENT_T_DEVNODE:
if (flags & MEDIA_LNK_FL_ENABLED) {
if (prev->output & ~PREVIEW_OUTPUT_MEMORY)
return -EBUSY;
prev->output |= PREVIEW_OUTPUT_MEMORY;
} else {
prev->output &= ~PREVIEW_OUTPUT_MEMORY;
}
break;
case PREV_PAD_SOURCE | MEDIA_ENT_T_V4L2_SUBDEV:
if (flags & MEDIA_LNK_FL_ENABLED) {
if (prev->output & ~PREVIEW_OUTPUT_RESIZER)
return -EBUSY;
prev->output |= PREVIEW_OUTPUT_RESIZER;
} else {
prev->output &= ~PREVIEW_OUTPUT_RESIZER;
}
break;
default:
return -EINVAL;
}
return 0;
}
void omap3isp_preview_unregister_entities(struct isp_prev_device *prev)
{
v4l2_device_unregister_subdev(&prev->subdev);
omap3isp_video_unregister(&prev->video_in);
omap3isp_video_unregister(&prev->video_out);
}
int omap3isp_preview_register_entities(struct isp_prev_device *prev,
struct v4l2_device *vdev)
{
int ret;
ret = v4l2_device_register_subdev(vdev, &prev->subdev);
if (ret < 0)
goto error;
ret = omap3isp_video_register(&prev->video_in, vdev);
if (ret < 0)
goto error;
ret = omap3isp_video_register(&prev->video_out, vdev);
if (ret < 0)
goto error;
return 0;
error:
omap3isp_preview_unregister_entities(prev);
return ret;
}
static int preview_init_entities(struct isp_prev_device *prev)
{
struct v4l2_subdev *sd = &prev->subdev;
struct media_pad *pads = prev->pads;
struct media_entity *me = &sd->entity;
int ret;
prev->input = PREVIEW_INPUT_NONE;
v4l2_subdev_init(sd, &preview_v4l2_ops);
sd->internal_ops = &preview_v4l2_internal_ops;
strlcpy(sd->name, "OMAP3 ISP preview", sizeof(sd->name));
sd->grp_id = 1 << 16;
v4l2_set_subdevdata(sd, prev);
sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
v4l2_ctrl_handler_init(&prev->ctrls, 2);
v4l2_ctrl_new_std(&prev->ctrls, &preview_ctrl_ops, V4L2_CID_BRIGHTNESS,
ISPPRV_BRIGHT_LOW, ISPPRV_BRIGHT_HIGH,
ISPPRV_BRIGHT_STEP, ISPPRV_BRIGHT_DEF);
v4l2_ctrl_new_std(&prev->ctrls, &preview_ctrl_ops, V4L2_CID_CONTRAST,
ISPPRV_CONTRAST_LOW, ISPPRV_CONTRAST_HIGH,
ISPPRV_CONTRAST_STEP, ISPPRV_CONTRAST_DEF);
v4l2_ctrl_handler_setup(&prev->ctrls);
sd->ctrl_handler = &prev->ctrls;
pads[PREV_PAD_SINK].flags = MEDIA_PAD_FL_SINK
| MEDIA_PAD_FL_MUST_CONNECT;
pads[PREV_PAD_SOURCE].flags = MEDIA_PAD_FL_SOURCE;
me->ops = &preview_media_ops;
ret = media_entity_init(me, PREV_PADS_NUM, pads, 0);
if (ret < 0)
return ret;
preview_init_formats(sd, NULL);
prev->video_in.type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
prev->video_in.ops = &preview_video_ops;
prev->video_in.isp = to_isp_device(prev);
prev->video_in.capture_mem = PAGE_ALIGN(4096 * 4096) * 2 * 3;
prev->video_in.bpl_alignment = 64;
prev->video_out.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
prev->video_out.ops = &preview_video_ops;
prev->video_out.isp = to_isp_device(prev);
prev->video_out.capture_mem = PAGE_ALIGN(4096 * 4096) * 2 * 3;
prev->video_out.bpl_alignment = 32;
ret = omap3isp_video_init(&prev->video_in, "preview");
if (ret < 0)
goto error_video_in;
ret = omap3isp_video_init(&prev->video_out, "preview");
if (ret < 0)
goto error_video_out;
ret = media_entity_create_link(&prev->video_in.video.entity, 0,
&prev->subdev.entity, PREV_PAD_SINK, 0);
if (ret < 0)
goto error_link;
ret = media_entity_create_link(&prev->subdev.entity, PREV_PAD_SOURCE,
&prev->video_out.video.entity, 0, 0);
if (ret < 0)
goto error_link;
return 0;
error_link:
omap3isp_video_cleanup(&prev->video_out);
error_video_out:
omap3isp_video_cleanup(&prev->video_in);
error_video_in:
media_entity_cleanup(&prev->subdev.entity);
return ret;
}
int omap3isp_preview_init(struct isp_device *isp)
{
struct isp_prev_device *prev = &isp->isp_prev;
init_waitqueue_head(&prev->wait);
preview_init_params(prev);
return preview_init_entities(prev);
}
void omap3isp_preview_cleanup(struct isp_device *isp)
{
struct isp_prev_device *prev = &isp->isp_prev;
v4l2_ctrl_handler_free(&prev->ctrls);
omap3isp_video_cleanup(&prev->video_in);
omap3isp_video_cleanup(&prev->video_out);
media_entity_cleanup(&prev->subdev.entity);
}
