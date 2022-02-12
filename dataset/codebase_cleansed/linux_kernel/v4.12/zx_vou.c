static inline struct zx_vou_hw *crtc_to_vou(struct drm_crtc *crtc)
{
struct zx_crtc *zcrtc = to_zx_crtc(crtc);
return zcrtc->vou;
}
void vou_inf_hdmi_audio_sel(struct drm_crtc *crtc,
enum vou_inf_hdmi_audio aud)
{
struct zx_crtc *zcrtc = to_zx_crtc(crtc);
struct zx_vou_hw *vou = zcrtc->vou;
zx_writel_mask(vou->vouctl + VOU_INF_HDMI_CTRL, VOU_HDMI_AUD_MASK, aud);
}
void vou_inf_enable(enum vou_inf_id id, struct drm_crtc *crtc)
{
struct zx_crtc *zcrtc = to_zx_crtc(crtc);
struct zx_vou_hw *vou = zcrtc->vou;
struct vou_inf *inf = &vou_infs[id];
bool is_main = zcrtc->chn_type == VOU_CHN_MAIN;
u32 data_sel_shift = id << 1;
zx_writel_mask(vou->vouctl + VOU_INF_DATA_SEL, 0x3 << data_sel_shift,
inf->data_sel << data_sel_shift);
zx_writel_mask(vou->vouctl + VOU_INF_CH_SEL, 0x1 << id,
zcrtc->chn_type << id);
zx_writel_mask(vou->vouctl + VOU_CLK_SEL, inf->clocks_sel_bits,
is_main ? 0 : inf->clocks_sel_bits);
zx_writel_mask(vou->vouctl + VOU_CLK_EN, inf->clocks_en_bits,
inf->clocks_en_bits);
zx_writel_mask(vou->vouctl + VOU_INF_EN, 1 << id, 1 << id);
}
void vou_inf_disable(enum vou_inf_id id, struct drm_crtc *crtc)
{
struct zx_vou_hw *vou = crtc_to_vou(crtc);
struct vou_inf *inf = &vou_infs[id];
zx_writel_mask(vou->vouctl + VOU_INF_EN, 1 << id, 0);
zx_writel_mask(vou->vouctl + VOU_CLK_EN, inf->clocks_en_bits, 0);
}
void zx_vou_config_dividers(struct drm_crtc *crtc,
struct vou_div_config *configs, int num)
{
struct zx_crtc *zcrtc = to_zx_crtc(crtc);
struct zx_vou_hw *vou = zcrtc->vou;
const struct zx_crtc_bits *bits = zcrtc->bits;
int i;
zx_writel_mask(vou->vouctl + VOU_DIV_PARA, DIV_PARA_UPDATE, 0);
for (i = 0; i < num; i++) {
struct vou_div_config *cfg = configs + i;
u32 reg, shift;
switch (cfg->id) {
case VOU_DIV_VGA:
reg = VOU_CLK_SEL;
shift = bits->div_vga_shift;
break;
case VOU_DIV_PIC:
reg = VOU_CLK_SEL;
shift = bits->div_pic_shift;
break;
case VOU_DIV_TVENC:
reg = VOU_DIV_PARA;
shift = bits->div_tvenc_shift;
break;
case VOU_DIV_HDMI_PNX:
reg = VOU_DIV_PARA;
shift = bits->div_hdmi_pnx_shift;
break;
case VOU_DIV_HDMI:
reg = VOU_DIV_PARA;
shift = bits->div_hdmi_shift;
break;
case VOU_DIV_INF:
reg = VOU_DIV_PARA;
shift = bits->div_inf_shift;
break;
case VOU_DIV_LAYER:
reg = VOU_DIV_PARA;
shift = bits->div_layer_shift;
break;
default:
continue;
}
zx_writel_mask(vou->vouctl + reg, 0x7 << shift,
cfg->val << shift);
}
zx_writel_mask(vou->vouctl + VOU_DIV_PARA, DIV_PARA_UPDATE,
DIV_PARA_UPDATE);
}
static inline void vou_chn_set_update(struct zx_crtc *zcrtc)
{
zx_writel(zcrtc->chnreg + CHN_UPDATE, 1);
}
static void zx_crtc_enable(struct drm_crtc *crtc)
{
struct drm_display_mode *mode = &crtc->state->adjusted_mode;
bool interlaced = mode->flags & DRM_MODE_FLAG_INTERLACE;
struct zx_crtc *zcrtc = to_zx_crtc(crtc);
struct zx_vou_hw *vou = zcrtc->vou;
const struct zx_crtc_regs *regs = zcrtc->regs;
const struct zx_crtc_bits *bits = zcrtc->bits;
struct videomode vm;
u32 scan_mask;
u32 pol = 0;
u32 val;
int ret;
drm_display_mode_to_videomode(mode, &vm);
val = V_ACTIVE((interlaced ? vm.vactive / 2 : vm.vactive) - 1);
val |= H_ACTIVE(vm.hactive - 1);
zx_writel(vou->timing + regs->fir_active, val);
val = SYNC_WIDE(vm.hsync_len - 1);
val |= BACK_PORCH(vm.hback_porch - 1);
val |= FRONT_PORCH(vm.hfront_porch - 1);
zx_writel(vou->timing + regs->fir_htiming, val);
val = SYNC_WIDE(vm.vsync_len - 1);
val |= BACK_PORCH(vm.vback_porch - 1);
val |= FRONT_PORCH(vm.vfront_porch - 1);
zx_writel(vou->timing + regs->fir_vtiming, val);
if (interlaced) {
u32 shift = bits->sec_vactive_shift;
u32 mask = bits->sec_vactive_mask;
val = zx_readl(vou->timing + SEC_V_ACTIVE);
val &= ~mask;
val |= ((vm.vactive / 2 - 1) << shift) & mask;
zx_writel(vou->timing + SEC_V_ACTIVE, val);
val = SYNC_WIDE(vm.vsync_len - 1);
val |= BACK_PORCH(vm.vback_porch);
val |= FRONT_PORCH(vm.vfront_porch - 1);
zx_writel(vou->timing + regs->sec_vtiming, val);
}
if (vm.flags & DISPLAY_FLAGS_VSYNC_LOW)
pol |= 1 << POL_VSYNC_SHIFT;
if (vm.flags & DISPLAY_FLAGS_HSYNC_LOW)
pol |= 1 << POL_HSYNC_SHIFT;
zx_writel_mask(vou->timing + TIMING_CTRL, bits->polarity_mask,
pol << bits->polarity_shift);
val = H_SHIFT_VAL;
if (interlaced)
val |= V_SHIFT_VAL << 16;
zx_writel(vou->timing + regs->timing_shift, val);
zx_writel(vou->timing + regs->timing_pi_shift, H_PI_SHIFT_VAL);
scan_mask = bits->interlace_select | bits->pi_enable;
zx_writel_mask(vou->timing + SCAN_CTRL, scan_mask,
interlaced ? scan_mask : 0);
zx_writel_mask(vou->timing + TIMING_TC_ENABLE, bits->tc_enable,
bits->tc_enable);
zx_writel_mask(zcrtc->chnreg + CHN_CTRL1, CHN_SCREEN_W_MASK,
vm.hactive << CHN_SCREEN_W_SHIFT);
zx_writel_mask(zcrtc->chnreg + CHN_CTRL1, CHN_SCREEN_H_MASK,
vm.vactive << CHN_SCREEN_H_SHIFT);
zx_writel_mask(zcrtc->chnreg + CHN_INTERLACE_BUF_CTRL, CHN_INTERLACE_EN,
interlaced ? CHN_INTERLACE_EN : 0);
vou_chn_set_update(zcrtc);
zx_writel_mask(zcrtc->chnreg + CHN_CTRL0, CHN_ENABLE, CHN_ENABLE);
drm_crtc_vblank_on(crtc);
ret = clk_set_rate(zcrtc->pixclk, mode->clock * 1000);
if (ret) {
DRM_DEV_ERROR(vou->dev, "failed to set pixclk rate: %d\n", ret);
return;
}
ret = clk_prepare_enable(zcrtc->pixclk);
if (ret)
DRM_DEV_ERROR(vou->dev, "failed to enable pixclk: %d\n", ret);
}
static void zx_crtc_disable(struct drm_crtc *crtc)
{
struct zx_crtc *zcrtc = to_zx_crtc(crtc);
const struct zx_crtc_bits *bits = zcrtc->bits;
struct zx_vou_hw *vou = zcrtc->vou;
clk_disable_unprepare(zcrtc->pixclk);
drm_crtc_vblank_off(crtc);
zx_writel_mask(zcrtc->chnreg + CHN_CTRL0, CHN_ENABLE, 0);
zx_writel_mask(vou->timing + TIMING_TC_ENABLE, bits->tc_enable, 0);
}
static void zx_crtc_atomic_flush(struct drm_crtc *crtc,
struct drm_crtc_state *old_state)
{
struct drm_pending_vblank_event *event = crtc->state->event;
if (!event)
return;
crtc->state->event = NULL;
spin_lock_irq(&crtc->dev->event_lock);
if (drm_crtc_vblank_get(crtc) == 0)
drm_crtc_arm_vblank_event(crtc, event);
else
drm_crtc_send_vblank_event(crtc, event);
spin_unlock_irq(&crtc->dev->event_lock);
}
static int zx_vou_enable_vblank(struct drm_crtc *crtc)
{
struct zx_crtc *zcrtc = to_zx_crtc(crtc);
struct zx_vou_hw *vou = crtc_to_vou(crtc);
u32 int_frame_mask = zcrtc->bits->int_frame_mask;
zx_writel_mask(vou->timing + TIMING_INT_CTRL, int_frame_mask,
int_frame_mask);
return 0;
}
static void zx_vou_disable_vblank(struct drm_crtc *crtc)
{
struct zx_crtc *zcrtc = to_zx_crtc(crtc);
struct zx_vou_hw *vou = crtc_to_vou(crtc);
zx_writel_mask(vou->timing + TIMING_INT_CTRL,
zcrtc->bits->int_frame_mask, 0);
}
static int zx_crtc_init(struct drm_device *drm, struct zx_vou_hw *vou,
enum vou_chn_type chn_type)
{
struct device *dev = vou->dev;
struct zx_plane *zplane;
struct zx_crtc *zcrtc;
int ret;
zcrtc = devm_kzalloc(dev, sizeof(*zcrtc), GFP_KERNEL);
if (!zcrtc)
return -ENOMEM;
zcrtc->vou = vou;
zcrtc->chn_type = chn_type;
zplane = devm_kzalloc(dev, sizeof(*zplane), GFP_KERNEL);
if (!zplane)
return -ENOMEM;
zplane->dev = dev;
if (chn_type == VOU_CHN_MAIN) {
zplane->layer = vou->osd + MAIN_GL_OFFSET;
zplane->csc = vou->osd + MAIN_CSC_OFFSET;
zplane->hbsc = vou->osd + MAIN_HBSC_OFFSET;
zplane->rsz = vou->otfppu + MAIN_RSZ_OFFSET;
zplane->bits = &zx_gl_bits[0];
zcrtc->chnreg = vou->osd + OSD_MAIN_CHN;
zcrtc->regs = &main_crtc_regs;
zcrtc->bits = &main_crtc_bits;
} else {
zplane->layer = vou->osd + AUX_GL_OFFSET;
zplane->csc = vou->osd + AUX_CSC_OFFSET;
zplane->hbsc = vou->osd + AUX_HBSC_OFFSET;
zplane->rsz = vou->otfppu + AUX_RSZ_OFFSET;
zplane->bits = &zx_gl_bits[1];
zcrtc->chnreg = vou->osd + OSD_AUX_CHN;
zcrtc->regs = &aux_crtc_regs;
zcrtc->bits = &aux_crtc_bits;
}
zcrtc->pixclk = devm_clk_get(dev, (chn_type == VOU_CHN_MAIN) ?
"main_wclk" : "aux_wclk");
if (IS_ERR(zcrtc->pixclk)) {
ret = PTR_ERR(zcrtc->pixclk);
DRM_DEV_ERROR(dev, "failed to get pix clk: %d\n", ret);
return ret;
}
ret = zx_plane_init(drm, zplane, DRM_PLANE_TYPE_PRIMARY);
if (ret) {
DRM_DEV_ERROR(dev, "failed to init primary plane: %d\n", ret);
return ret;
}
zcrtc->primary = &zplane->plane;
ret = drm_crtc_init_with_planes(drm, &zcrtc->crtc, zcrtc->primary, NULL,
&zx_crtc_funcs, NULL);
if (ret) {
DRM_DEV_ERROR(dev, "failed to init drm crtc: %d\n", ret);
return ret;
}
drm_crtc_helper_add(&zcrtc->crtc, &zx_crtc_helper_funcs);
if (chn_type == VOU_CHN_MAIN)
vou->main_crtc = zcrtc;
else
vou->aux_crtc = zcrtc;
return 0;
}
void zx_vou_layer_enable(struct drm_plane *plane)
{
struct zx_crtc *zcrtc = to_zx_crtc(plane->state->crtc);
struct zx_vou_hw *vou = zcrtc->vou;
struct zx_plane *zplane = to_zx_plane(plane);
const struct vou_layer_bits *bits = zplane->bits;
if (zcrtc->chn_type == VOU_CHN_MAIN) {
zx_writel_mask(vou->osd + OSD_CTRL0, bits->chnsel, 0);
zx_writel_mask(vou->vouctl + VOU_CLK_SEL, bits->clksel, 0);
} else {
zx_writel_mask(vou->osd + OSD_CTRL0, bits->chnsel,
bits->chnsel);
zx_writel_mask(vou->vouctl + VOU_CLK_SEL, bits->clksel,
bits->clksel);
}
zx_writel_mask(vou->osd + OSD_CTRL0, bits->enable, bits->enable);
}
void zx_vou_layer_disable(struct drm_plane *plane)
{
struct zx_crtc *zcrtc = to_zx_crtc(plane->crtc);
struct zx_vou_hw *vou = zcrtc->vou;
struct zx_plane *zplane = to_zx_plane(plane);
const struct vou_layer_bits *bits = zplane->bits;
zx_writel_mask(vou->osd + OSD_CTRL0, bits->enable, 0);
}
static void zx_overlay_init(struct drm_device *drm, struct zx_vou_hw *vou)
{
struct device *dev = vou->dev;
struct zx_plane *zplane;
int i;
int ret;
for (i = 1; i < VL_NUM; i++) {
zplane = devm_kzalloc(dev, sizeof(*zplane), GFP_KERNEL);
if (!zplane) {
DRM_DEV_ERROR(dev, "failed to allocate zplane %d\n", i);
return;
}
zplane->layer = vou->osd + OSD_VL_OFFSET(i);
zplane->hbsc = vou->osd + HBSC_VL_OFFSET(i);
zplane->rsz = vou->otfppu + RSZ_VL_OFFSET(i);
zplane->bits = &zx_vl_bits[i];
ret = zx_plane_init(drm, zplane, DRM_PLANE_TYPE_OVERLAY);
if (ret) {
DRM_DEV_ERROR(dev, "failed to init overlay %d\n", i);
continue;
}
}
}
static inline void zx_osd_int_update(struct zx_crtc *zcrtc)
{
struct drm_crtc *crtc = &zcrtc->crtc;
struct drm_plane *plane;
vou_chn_set_update(zcrtc);
drm_for_each_plane_mask(plane, crtc->dev, crtc->state->plane_mask)
zx_plane_set_update(plane);
}
static irqreturn_t vou_irq_handler(int irq, void *dev_id)
{
struct zx_vou_hw *vou = dev_id;
u32 state;
state = zx_readl(vou->timing + TIMING_INT_STATE);
zx_writel(vou->timing + TIMING_INT_STATE, state);
if (state & TIMING_INT_MAIN_FRAME)
drm_crtc_handle_vblank(&vou->main_crtc->crtc);
if (state & TIMING_INT_AUX_FRAME)
drm_crtc_handle_vblank(&vou->aux_crtc->crtc);
state = zx_readl(vou->osd + OSD_INT_STA);
zx_writel(vou->osd + OSD_INT_CLRSTA, state);
if (state & OSD_INT_MAIN_UPT)
zx_osd_int_update(vou->main_crtc);
if (state & OSD_INT_AUX_UPT)
zx_osd_int_update(vou->aux_crtc);
if (state & OSD_INT_ERROR)
DRM_DEV_ERROR(vou->dev, "OSD ERROR: 0x%08x!\n", state);
return IRQ_HANDLED;
}
static void vou_dtrc_init(struct zx_vou_hw *vou)
{
zx_writel_mask(vou->dtrc + DTRC_DETILE_CTRL,
TILE2RASTESCAN_BYPASS_MODE, 0);
zx_writel_mask(vou->dtrc + DTRC_DETILE_CTRL, DETILE_ARIDR_MODE_MASK,
DETILE_ARID_IN_ARIDR);
zx_writel_mask(vou->dtrc + DTRC_F0_CTRL, DTRC_DECOMPRESS_BYPASS,
DTRC_DECOMPRESS_BYPASS);
zx_writel_mask(vou->dtrc + DTRC_F1_CTRL, DTRC_DECOMPRESS_BYPASS,
DTRC_DECOMPRESS_BYPASS);
zx_writel(vou->dtrc + DTRC_ARID, DTRC_ARID3(0xf) | DTRC_ARID2(0xe) |
DTRC_ARID1(0xf) | DTRC_ARID0(0xe));
}
static void vou_hw_init(struct zx_vou_hw *vou)
{
zx_writel(vou->vouctl + VOU_SOFT_RST, ~0);
zx_writel(vou->vouctl + VOU_CLK_REQEN, ~0);
zx_writel(vou->vouctl + VOU_CLK_EN, ~0);
zx_writel(vou->osd + OSD_INT_CLRSTA, ~0);
zx_writel(vou->timing + TIMING_INT_STATE, ~0);
zx_writel(vou->osd + OSD_INT_MSK, OSD_INT_ENABLE);
zx_writel(vou->timing + TIMING_INT_CTRL, TIMING_INT_ENABLE);
zx_writel(vou->otfppu + OTFPPU_RSZ_DATA_SOURCE, 0x2a);
zx_writel_mask(vou->osd + OSD_RST_CLR, RST_PER_FRAME, RST_PER_FRAME);
vou_dtrc_init(vou);
}
static int zx_crtc_bind(struct device *dev, struct device *master, void *data)
{
struct platform_device *pdev = to_platform_device(dev);
struct drm_device *drm = data;
struct zx_vou_hw *vou;
struct resource *res;
int irq;
int ret;
vou = devm_kzalloc(dev, sizeof(*vou), GFP_KERNEL);
if (!vou)
return -ENOMEM;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "osd");
vou->osd = devm_ioremap_resource(dev, res);
if (IS_ERR(vou->osd)) {
ret = PTR_ERR(vou->osd);
DRM_DEV_ERROR(dev, "failed to remap osd region: %d\n", ret);
return ret;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "timing_ctrl");
vou->timing = devm_ioremap_resource(dev, res);
if (IS_ERR(vou->timing)) {
ret = PTR_ERR(vou->timing);
DRM_DEV_ERROR(dev, "failed to remap timing_ctrl region: %d\n",
ret);
return ret;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "dtrc");
vou->dtrc = devm_ioremap_resource(dev, res);
if (IS_ERR(vou->dtrc)) {
ret = PTR_ERR(vou->dtrc);
DRM_DEV_ERROR(dev, "failed to remap dtrc region: %d\n", ret);
return ret;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "vou_ctrl");
vou->vouctl = devm_ioremap_resource(dev, res);
if (IS_ERR(vou->vouctl)) {
ret = PTR_ERR(vou->vouctl);
DRM_DEV_ERROR(dev, "failed to remap vou_ctrl region: %d\n",
ret);
return ret;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "otfppu");
vou->otfppu = devm_ioremap_resource(dev, res);
if (IS_ERR(vou->otfppu)) {
ret = PTR_ERR(vou->otfppu);
DRM_DEV_ERROR(dev, "failed to remap otfppu region: %d\n", ret);
return ret;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
vou->axi_clk = devm_clk_get(dev, "aclk");
if (IS_ERR(vou->axi_clk)) {
ret = PTR_ERR(vou->axi_clk);
DRM_DEV_ERROR(dev, "failed to get axi_clk: %d\n", ret);
return ret;
}
vou->ppu_clk = devm_clk_get(dev, "ppu_wclk");
if (IS_ERR(vou->ppu_clk)) {
ret = PTR_ERR(vou->ppu_clk);
DRM_DEV_ERROR(dev, "failed to get ppu_clk: %d\n", ret);
return ret;
}
ret = clk_prepare_enable(vou->axi_clk);
if (ret) {
DRM_DEV_ERROR(dev, "failed to enable axi_clk: %d\n", ret);
return ret;
}
clk_prepare_enable(vou->ppu_clk);
if (ret) {
DRM_DEV_ERROR(dev, "failed to enable ppu_clk: %d\n", ret);
goto disable_axi_clk;
}
vou->dev = dev;
dev_set_drvdata(dev, vou);
vou_hw_init(vou);
ret = devm_request_irq(dev, irq, vou_irq_handler, 0, "zx_vou", vou);
if (ret < 0) {
DRM_DEV_ERROR(dev, "failed to request vou irq: %d\n", ret);
goto disable_ppu_clk;
}
ret = zx_crtc_init(drm, vou, VOU_CHN_MAIN);
if (ret) {
DRM_DEV_ERROR(dev, "failed to init main channel crtc: %d\n",
ret);
goto disable_ppu_clk;
}
ret = zx_crtc_init(drm, vou, VOU_CHN_AUX);
if (ret) {
DRM_DEV_ERROR(dev, "failed to init aux channel crtc: %d\n",
ret);
goto disable_ppu_clk;
}
zx_overlay_init(drm, vou);
return 0;
disable_ppu_clk:
clk_disable_unprepare(vou->ppu_clk);
disable_axi_clk:
clk_disable_unprepare(vou->axi_clk);
return ret;
}
static void zx_crtc_unbind(struct device *dev, struct device *master,
void *data)
{
struct zx_vou_hw *vou = dev_get_drvdata(dev);
clk_disable_unprepare(vou->axi_clk);
clk_disable_unprepare(vou->ppu_clk);
}
static int zx_crtc_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &zx_crtc_component_ops);
}
static int zx_crtc_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &zx_crtc_component_ops);
return 0;
}
