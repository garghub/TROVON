static int hibmc_plane_atomic_check(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct drm_framebuffer *fb = state->fb;
struct drm_crtc *crtc = state->crtc;
struct drm_crtc_state *crtc_state;
u32 src_w = state->src_w >> 16;
u32 src_h = state->src_h >> 16;
if (!crtc || !fb)
return 0;
crtc_state = drm_atomic_get_crtc_state(state->state, crtc);
if (IS_ERR(crtc_state))
return PTR_ERR(crtc_state);
if (src_w != state->crtc_w || src_h != state->crtc_h) {
DRM_DEBUG_ATOMIC("scale not support\n");
return -EINVAL;
}
if (state->crtc_x < 0 || state->crtc_y < 0) {
DRM_DEBUG_ATOMIC("crtc_x/y of drm_plane state is invalid\n");
return -EINVAL;
}
if (state->crtc_x + state->crtc_w >
crtc_state->adjusted_mode.hdisplay ||
state->crtc_y + state->crtc_h >
crtc_state->adjusted_mode.vdisplay) {
DRM_DEBUG_ATOMIC("visible portion of plane is invalid\n");
return -EINVAL;
}
return 0;
}
static void hibmc_plane_atomic_update(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct drm_plane_state *state = plane->state;
u32 reg;
int ret;
u64 gpu_addr = 0;
unsigned int line_l;
struct hibmc_drm_private *priv = plane->dev->dev_private;
struct hibmc_framebuffer *hibmc_fb;
struct hibmc_bo *bo;
if (!state->fb)
return;
hibmc_fb = to_hibmc_framebuffer(state->fb);
bo = gem_to_hibmc_bo(hibmc_fb->obj);
ret = ttm_bo_reserve(&bo->bo, true, false, NULL);
if (ret) {
DRM_ERROR("failed to reserve ttm_bo: %d", ret);
return;
}
ret = hibmc_bo_pin(bo, TTM_PL_FLAG_VRAM, &gpu_addr);
ttm_bo_unreserve(&bo->bo);
if (ret) {
DRM_ERROR("failed to pin hibmc_bo: %d", ret);
return;
}
writel(gpu_addr, priv->mmio + HIBMC_CRT_FB_ADDRESS);
reg = state->fb->width * (state->fb->bits_per_pixel / 8);
reg = PADDING(16, reg);
line_l = state->fb->width * state->fb->bits_per_pixel / 8;
line_l = PADDING(16, line_l);
writel(HIBMC_FIELD(HIBMC_CRT_FB_WIDTH_WIDTH, reg) |
HIBMC_FIELD(HIBMC_CRT_FB_WIDTH_OFFS, line_l),
priv->mmio + HIBMC_CRT_FB_WIDTH);
reg = readl(priv->mmio + HIBMC_CRT_DISP_CTL);
reg &= ~HIBMC_CRT_DISP_CTL_FORMAT_MASK;
reg |= HIBMC_FIELD(HIBMC_CRT_DISP_CTL_FORMAT,
state->fb->bits_per_pixel / 16);
writel(reg, priv->mmio + HIBMC_CRT_DISP_CTL);
}
static struct drm_plane *hibmc_plane_init(struct hibmc_drm_private *priv)
{
struct drm_device *dev = priv->dev;
struct drm_plane *plane;
int ret = 0;
plane = devm_kzalloc(dev->dev, sizeof(*plane), GFP_KERNEL);
if (!plane) {
DRM_ERROR("failed to alloc memory when init plane\n");
return ERR_PTR(-ENOMEM);
}
ret = drm_universal_plane_init(dev, plane, 1, &hibmc_plane_funcs,
channel_formats1,
ARRAY_SIZE(channel_formats1),
DRM_PLANE_TYPE_PRIMARY,
NULL);
if (ret) {
DRM_ERROR("failed to init plane: %d\n", ret);
return ERR_PTR(ret);
}
drm_plane_helper_add(plane, &hibmc_plane_helper_funcs);
return plane;
}
static void hibmc_crtc_enable(struct drm_crtc *crtc)
{
unsigned int reg;
struct hibmc_drm_private *priv = crtc->dev->dev_private;
hibmc_set_power_mode(priv, HIBMC_PW_MODE_CTL_MODE_MODE0);
reg = readl(priv->mmio + HIBMC_CURRENT_GATE);
reg &= ~HIBMC_CURR_GATE_LOCALMEM_MASK;
reg &= ~HIBMC_CURR_GATE_DISPLAY_MASK;
reg |= HIBMC_CURR_GATE_LOCALMEM(1);
reg |= HIBMC_CURR_GATE_DISPLAY(1);
hibmc_set_current_gate(priv, reg);
drm_crtc_vblank_on(crtc);
}
static void hibmc_crtc_disable(struct drm_crtc *crtc)
{
unsigned int reg;
struct hibmc_drm_private *priv = crtc->dev->dev_private;
drm_crtc_vblank_off(crtc);
hibmc_set_power_mode(priv, HIBMC_PW_MODE_CTL_MODE_SLEEP);
reg = readl(priv->mmio + HIBMC_CURRENT_GATE);
reg &= ~HIBMC_CURR_GATE_LOCALMEM_MASK;
reg &= ~HIBMC_CURR_GATE_DISPLAY_MASK;
reg |= HIBMC_CURR_GATE_LOCALMEM(0);
reg |= HIBMC_CURR_GATE_DISPLAY(0);
hibmc_set_current_gate(priv, reg);
}
static unsigned int format_pll_reg(void)
{
unsigned int pllreg = 0;
struct hibmc_display_panel_pll pll = {0};
pllreg |= HIBMC_FIELD(HIBMC_PLL_CTRL_BYPASS, 0);
pllreg |= HIBMC_FIELD(HIBMC_PLL_CTRL_POWER, 1);
pllreg |= HIBMC_FIELD(HIBMC_PLL_CTRL_INPUT, 0);
pllreg |= HIBMC_FIELD(HIBMC_PLL_CTRL_POD, pll.POD);
pllreg |= HIBMC_FIELD(HIBMC_PLL_CTRL_OD, pll.OD);
pllreg |= HIBMC_FIELD(HIBMC_PLL_CTRL_N, pll.N);
pllreg |= HIBMC_FIELD(HIBMC_PLL_CTRL_M, pll.M);
return pllreg;
}
static void set_vclock_hisilicon(struct drm_device *dev, unsigned long pll)
{
u32 val;
struct hibmc_drm_private *priv = dev->dev_private;
val = readl(priv->mmio + CRT_PLL1_HS);
val &= ~(CRT_PLL1_HS_OUTER_BYPASS(1));
writel(val, priv->mmio + CRT_PLL1_HS);
val = CRT_PLL1_HS_INTER_BYPASS(1) | CRT_PLL1_HS_POWERON(1);
writel(val, priv->mmio + CRT_PLL1_HS);
writel(pll, priv->mmio + CRT_PLL1_HS);
usleep_range(1000, 2000);
val = pll & ~(CRT_PLL1_HS_POWERON(1));
writel(val, priv->mmio + CRT_PLL1_HS);
usleep_range(1000, 2000);
val &= ~(CRT_PLL1_HS_INTER_BYPASS(1));
writel(val, priv->mmio + CRT_PLL1_HS);
usleep_range(1000, 2000);
val |= CRT_PLL1_HS_OUTER_BYPASS(1);
writel(val, priv->mmio + CRT_PLL1_HS);
}
static void get_pll_config(unsigned long x, unsigned long y,
u32 *pll1, u32 *pll2)
{
int i;
int count = ARRAY_SIZE(hibmc_pll_table);
for (i = 0; i < count; i++) {
if (hibmc_pll_table[i].hdisplay == x &&
hibmc_pll_table[i].vdisplay == y) {
*pll1 = hibmc_pll_table[i].pll1_config_value;
*pll2 = hibmc_pll_table[i].pll2_config_value;
return;
}
}
*pll1 = CRT_PLL1_HS_25MHZ;
*pll2 = CRT_PLL2_HS_25MHZ;
}
static unsigned int display_ctrl_adjust(struct drm_device *dev,
struct drm_display_mode *mode,
unsigned int ctrl)
{
unsigned long x, y;
u32 pll1;
u32 pll2;
struct hibmc_drm_private *priv = dev->dev_private;
x = mode->hdisplay;
y = mode->vdisplay;
get_pll_config(x, y, &pll1, &pll2);
writel(pll2, priv->mmio + CRT_PLL2_HS);
set_vclock_hisilicon(dev, pll1);
writel(HIBMC_FIELD(HIBMC_CRT_AUTO_CENTERING_TL_TOP, 0) |
HIBMC_FIELD(HIBMC_CRT_AUTO_CENTERING_TL_LEFT, 0),
priv->mmio + HIBMC_CRT_AUTO_CENTERING_TL);
writel(HIBMC_FIELD(HIBMC_CRT_AUTO_CENTERING_BR_BOTTOM, y - 1) |
HIBMC_FIELD(HIBMC_CRT_AUTO_CENTERING_BR_RIGHT, x - 1),
priv->mmio + HIBMC_CRT_AUTO_CENTERING_BR);
ctrl &= ~HIBMC_CRT_DISP_CTL_CRTSELECT_MASK;
ctrl &= ~HIBMC_CRT_DISP_CTL_CLOCK_PHASE_MASK;
ctrl |= HIBMC_CRT_DISP_CTL_CRTSELECT(HIBMC_CRTSELECT_CRT);
ctrl |= HIBMC_CRT_DISP_CTL_CLOCK_PHASE(0);
writel(ctrl, priv->mmio + HIBMC_CRT_DISP_CTL);
return ctrl;
}
static void hibmc_crtc_mode_set_nofb(struct drm_crtc *crtc)
{
unsigned int val;
struct drm_display_mode *mode = &crtc->state->mode;
struct drm_device *dev = crtc->dev;
struct hibmc_drm_private *priv = dev->dev_private;
int width = mode->hsync_end - mode->hsync_start;
int height = mode->vsync_end - mode->vsync_start;
writel(format_pll_reg(), priv->mmio + HIBMC_CRT_PLL_CTRL);
writel(HIBMC_FIELD(HIBMC_CRT_HORZ_TOTAL_TOTAL, mode->htotal - 1) |
HIBMC_FIELD(HIBMC_CRT_HORZ_TOTAL_DISP_END, mode->hdisplay - 1),
priv->mmio + HIBMC_CRT_HORZ_TOTAL);
writel(HIBMC_FIELD(HIBMC_CRT_HORZ_SYNC_WIDTH, width) |
HIBMC_FIELD(HIBMC_CRT_HORZ_SYNC_START, mode->hsync_start - 1),
priv->mmio + HIBMC_CRT_HORZ_SYNC);
writel(HIBMC_FIELD(HIBMC_CRT_VERT_TOTAL_TOTAL, mode->vtotal - 1) |
HIBMC_FIELD(HIBMC_CRT_VERT_TOTAL_DISP_END, mode->vdisplay - 1),
priv->mmio + HIBMC_CRT_VERT_TOTAL);
writel(HIBMC_FIELD(HIBMC_CRT_VERT_SYNC_HEIGHT, height) |
HIBMC_FIELD(HIBMC_CRT_VERT_SYNC_START, mode->vsync_start - 1),
priv->mmio + HIBMC_CRT_VERT_SYNC);
val = HIBMC_FIELD(HIBMC_CRT_DISP_CTL_VSYNC_PHASE, 0);
val |= HIBMC_FIELD(HIBMC_CRT_DISP_CTL_HSYNC_PHASE, 0);
val |= HIBMC_CRT_DISP_CTL_TIMING(1);
val |= HIBMC_CRT_DISP_CTL_PLANE(1);
display_ctrl_adjust(dev, mode, val);
}
static void hibmc_crtc_atomic_begin(struct drm_crtc *crtc,
struct drm_crtc_state *old_state)
{
unsigned int reg;
struct drm_device *dev = crtc->dev;
struct hibmc_drm_private *priv = dev->dev_private;
hibmc_set_power_mode(priv, HIBMC_PW_MODE_CTL_MODE_MODE0);
reg = readl(priv->mmio + HIBMC_CURRENT_GATE);
reg &= ~HIBMC_CURR_GATE_DISPLAY_MASK;
reg &= ~HIBMC_CURR_GATE_LOCALMEM_MASK;
reg |= HIBMC_CURR_GATE_DISPLAY(1);
reg |= HIBMC_CURR_GATE_LOCALMEM(1);
hibmc_set_current_gate(priv, reg);
}
static void hibmc_crtc_atomic_flush(struct drm_crtc *crtc,
struct drm_crtc_state *old_state)
{
unsigned long flags;
spin_lock_irqsave(&crtc->dev->event_lock, flags);
if (crtc->state->event)
drm_crtc_send_vblank_event(crtc, crtc->state->event);
crtc->state->event = NULL;
spin_unlock_irqrestore(&crtc->dev->event_lock, flags);
}
int hibmc_de_init(struct hibmc_drm_private *priv)
{
struct drm_device *dev = priv->dev;
struct drm_crtc *crtc;
struct drm_plane *plane;
int ret;
plane = hibmc_plane_init(priv);
if (IS_ERR(plane)) {
DRM_ERROR("failed to create plane: %ld\n", PTR_ERR(plane));
return PTR_ERR(plane);
}
crtc = devm_kzalloc(dev->dev, sizeof(*crtc), GFP_KERNEL);
if (!crtc) {
DRM_ERROR("failed to alloc memory when init crtc\n");
return -ENOMEM;
}
ret = drm_crtc_init_with_planes(dev, crtc, plane,
NULL, &hibmc_crtc_funcs, NULL);
if (ret) {
DRM_ERROR("failed to init crtc: %d\n", ret);
return ret;
}
ret = drm_mode_crtc_set_gamma_size(crtc, 256);
if (ret) {
DRM_ERROR("failed to set gamma size: %d\n", ret);
return ret;
}
drm_crtc_helper_add(crtc, &hibmc_crtc_helper_funcs);
return 0;
}
