static bool hsw_power_well_enabled(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
return I915_READ(HSW_PWR_WELL_DRIVER) ==
(HSW_PWR_WELL_ENABLE_REQUEST | HSW_PWR_WELL_STATE_ENABLED);
}
bool __intel_display_power_is_enabled(struct drm_i915_private *dev_priv,
enum intel_display_power_domain domain)
{
struct i915_power_domains *power_domains;
struct i915_power_well *power_well;
bool is_enabled;
int i;
if (dev_priv->pm.suspended)
return false;
power_domains = &dev_priv->power_domains;
is_enabled = true;
for_each_power_well_rev(i, power_well, BIT(domain), power_domains) {
if (power_well->always_on)
continue;
if (!power_well->hw_enabled) {
is_enabled = false;
break;
}
}
return is_enabled;
}
bool intel_display_power_is_enabled(struct drm_i915_private *dev_priv,
enum intel_display_power_domain domain)
{
struct i915_power_domains *power_domains;
bool ret;
power_domains = &dev_priv->power_domains;
mutex_lock(&power_domains->lock);
ret = __intel_display_power_is_enabled(dev_priv, domain);
mutex_unlock(&power_domains->lock);
return ret;
}
void intel_display_set_init_power(struct drm_i915_private *dev_priv,
bool enable)
{
if (dev_priv->power_domains.init_power_on == enable)
return;
if (enable)
intel_display_power_get(dev_priv, POWER_DOMAIN_INIT);
else
intel_display_power_put(dev_priv, POWER_DOMAIN_INIT);
dev_priv->power_domains.init_power_on = enable;
}
static void hsw_power_well_post_enable(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
vga_get_uninterruptible(dev->pdev, VGA_RSRC_LEGACY_IO);
outb(inb(VGA_MSR_READ), VGA_MSR_WRITE);
vga_put(dev->pdev, VGA_RSRC_LEGACY_IO);
if (IS_BROADWELL(dev) || (INTEL_INFO(dev)->gen >= 9))
gen8_irq_power_well_post_enable(dev_priv);
}
static void hsw_set_power_well(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well, bool enable)
{
bool is_enabled, enable_requested;
uint32_t tmp;
tmp = I915_READ(HSW_PWR_WELL_DRIVER);
is_enabled = tmp & HSW_PWR_WELL_STATE_ENABLED;
enable_requested = tmp & HSW_PWR_WELL_ENABLE_REQUEST;
if (enable) {
if (!enable_requested)
I915_WRITE(HSW_PWR_WELL_DRIVER,
HSW_PWR_WELL_ENABLE_REQUEST);
if (!is_enabled) {
DRM_DEBUG_KMS("Enabling power well\n");
if (wait_for((I915_READ(HSW_PWR_WELL_DRIVER) &
HSW_PWR_WELL_STATE_ENABLED), 20))
DRM_ERROR("Timeout enabling power well\n");
hsw_power_well_post_enable(dev_priv);
}
} else {
if (enable_requested) {
I915_WRITE(HSW_PWR_WELL_DRIVER, 0);
POSTING_READ(HSW_PWR_WELL_DRIVER);
DRM_DEBUG_KMS("Requesting to disable the power well\n");
}
}
}
static void hsw_power_well_sync_hw(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
hsw_set_power_well(dev_priv, power_well, power_well->count > 0);
if (I915_READ(HSW_PWR_WELL_BIOS) & HSW_PWR_WELL_ENABLE_REQUEST)
I915_WRITE(HSW_PWR_WELL_BIOS, 0);
}
static void hsw_power_well_enable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
hsw_set_power_well(dev_priv, power_well, true);
}
static void hsw_power_well_disable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
hsw_set_power_well(dev_priv, power_well, false);
}
static void i9xx_always_on_power_well_noop(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
}
static bool i9xx_always_on_power_well_enabled(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
return true;
}
static void vlv_set_power_well(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well, bool enable)
{
enum punit_power_well power_well_id = power_well->data;
u32 mask;
u32 state;
u32 ctrl;
mask = PUNIT_PWRGT_MASK(power_well_id);
state = enable ? PUNIT_PWRGT_PWR_ON(power_well_id) :
PUNIT_PWRGT_PWR_GATE(power_well_id);
mutex_lock(&dev_priv->rps.hw_lock);
#define COND \
((vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_STATUS) & mask) == state)
if (COND)
goto out;
ctrl = vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_CTRL);
ctrl &= ~mask;
ctrl |= state;
vlv_punit_write(dev_priv, PUNIT_REG_PWRGT_CTRL, ctrl);
if (wait_for(COND, 100))
DRM_ERROR("timout setting power well state %08x (%08x)\n",
state,
vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_CTRL));
#undef COND
out:
mutex_unlock(&dev_priv->rps.hw_lock);
}
static void vlv_power_well_sync_hw(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
vlv_set_power_well(dev_priv, power_well, power_well->count > 0);
}
static void vlv_power_well_enable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
vlv_set_power_well(dev_priv, power_well, true);
}
static void vlv_power_well_disable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
vlv_set_power_well(dev_priv, power_well, false);
}
static bool vlv_power_well_enabled(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
int power_well_id = power_well->data;
bool enabled = false;
u32 mask;
u32 state;
u32 ctrl;
mask = PUNIT_PWRGT_MASK(power_well_id);
ctrl = PUNIT_PWRGT_PWR_ON(power_well_id);
mutex_lock(&dev_priv->rps.hw_lock);
state = vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_STATUS) & mask;
WARN_ON(state != PUNIT_PWRGT_PWR_ON(power_well_id) &&
state != PUNIT_PWRGT_PWR_GATE(power_well_id));
if (state == ctrl)
enabled = true;
ctrl = vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_CTRL) & mask;
WARN_ON(ctrl != state);
mutex_unlock(&dev_priv->rps.hw_lock);
return enabled;
}
static void vlv_display_power_well_enable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
WARN_ON_ONCE(power_well->data != PUNIT_POWER_WELL_DISP2D);
vlv_set_power_well(dev_priv, power_well, true);
spin_lock_irq(&dev_priv->irq_lock);
valleyview_enable_display_irqs(dev_priv);
spin_unlock_irq(&dev_priv->irq_lock);
if (dev_priv->power_domains.initializing)
return;
intel_hpd_init(dev_priv);
i915_redisable_vga_power_on(dev_priv->dev);
}
static void vlv_display_power_well_disable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
WARN_ON_ONCE(power_well->data != PUNIT_POWER_WELL_DISP2D);
spin_lock_irq(&dev_priv->irq_lock);
valleyview_disable_display_irqs(dev_priv);
spin_unlock_irq(&dev_priv->irq_lock);
vlv_set_power_well(dev_priv, power_well, false);
vlv_power_sequencer_reset(dev_priv);
}
static void vlv_dpio_cmn_power_well_enable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
WARN_ON_ONCE(power_well->data != PUNIT_POWER_WELL_DPIO_CMN_BC);
I915_WRITE(DPLL(PIPE_B), I915_READ(DPLL(PIPE_B)) |
DPLL_REFA_CLK_ENABLE_VLV | DPLL_INTEGRATED_CRI_CLK_VLV);
udelay(1);
vlv_set_power_well(dev_priv, power_well, true);
I915_WRITE(DPIO_CTL, I915_READ(DPIO_CTL) | DPIO_CMNRST);
}
static void vlv_dpio_cmn_power_well_disable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
enum pipe pipe;
WARN_ON_ONCE(power_well->data != PUNIT_POWER_WELL_DPIO_CMN_BC);
for_each_pipe(dev_priv, pipe)
assert_pll_disabled(dev_priv, pipe);
I915_WRITE(DPIO_CTL, I915_READ(DPIO_CTL) & ~DPIO_CMNRST);
vlv_set_power_well(dev_priv, power_well, false);
}
static void chv_dpio_cmn_power_well_enable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
enum dpio_phy phy;
WARN_ON_ONCE(power_well->data != PUNIT_POWER_WELL_DPIO_CMN_BC &&
power_well->data != PUNIT_POWER_WELL_DPIO_CMN_D);
if (power_well->data == PUNIT_POWER_WELL_DPIO_CMN_BC) {
phy = DPIO_PHY0;
I915_WRITE(DPLL(PIPE_B), I915_READ(DPLL(PIPE_B)) |
DPLL_REFA_CLK_ENABLE_VLV);
I915_WRITE(DPLL(PIPE_B), I915_READ(DPLL(PIPE_B)) |
DPLL_REFA_CLK_ENABLE_VLV | DPLL_INTEGRATED_CRI_CLK_VLV);
} else {
phy = DPIO_PHY1;
I915_WRITE(DPLL(PIPE_C), I915_READ(DPLL(PIPE_C)) |
DPLL_REFA_CLK_ENABLE_VLV | DPLL_INTEGRATED_CRI_CLK_VLV);
}
udelay(1);
vlv_set_power_well(dev_priv, power_well, true);
if (wait_for(I915_READ(DISPLAY_PHY_STATUS) & PHY_POWERGOOD(phy), 1))
DRM_ERROR("Display PHY %d is not power up\n", phy);
I915_WRITE(DISPLAY_PHY_CONTROL, I915_READ(DISPLAY_PHY_CONTROL) |
PHY_COM_LANE_RESET_DEASSERT(phy));
}
static void chv_dpio_cmn_power_well_disable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
enum dpio_phy phy;
WARN_ON_ONCE(power_well->data != PUNIT_POWER_WELL_DPIO_CMN_BC &&
power_well->data != PUNIT_POWER_WELL_DPIO_CMN_D);
if (power_well->data == PUNIT_POWER_WELL_DPIO_CMN_BC) {
phy = DPIO_PHY0;
assert_pll_disabled(dev_priv, PIPE_A);
assert_pll_disabled(dev_priv, PIPE_B);
} else {
phy = DPIO_PHY1;
assert_pll_disabled(dev_priv, PIPE_C);
}
I915_WRITE(DISPLAY_PHY_CONTROL, I915_READ(DISPLAY_PHY_CONTROL) &
~PHY_COM_LANE_RESET_DEASSERT(phy));
vlv_set_power_well(dev_priv, power_well, false);
}
static bool chv_pipe_power_well_enabled(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
enum pipe pipe = power_well->data;
bool enabled;
u32 state, ctrl;
mutex_lock(&dev_priv->rps.hw_lock);
state = vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ) & DP_SSS_MASK(pipe);
WARN_ON(state != DP_SSS_PWR_ON(pipe) && state != DP_SSS_PWR_GATE(pipe));
enabled = state == DP_SSS_PWR_ON(pipe);
ctrl = vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ) & DP_SSC_MASK(pipe);
WARN_ON(ctrl << 16 != state);
mutex_unlock(&dev_priv->rps.hw_lock);
return enabled;
}
static void chv_set_pipe_power_well(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well,
bool enable)
{
enum pipe pipe = power_well->data;
u32 state;
u32 ctrl;
state = enable ? DP_SSS_PWR_ON(pipe) : DP_SSS_PWR_GATE(pipe);
mutex_lock(&dev_priv->rps.hw_lock);
#define COND \
((vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ) & DP_SSS_MASK(pipe)) == state)
if (COND)
goto out;
ctrl = vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ);
ctrl &= ~DP_SSC_MASK(pipe);
ctrl |= enable ? DP_SSC_PWR_ON(pipe) : DP_SSC_PWR_GATE(pipe);
vlv_punit_write(dev_priv, PUNIT_REG_DSPFREQ, ctrl);
if (wait_for(COND, 100))
DRM_ERROR("timout setting power well state %08x (%08x)\n",
state,
vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ));
#undef COND
out:
mutex_unlock(&dev_priv->rps.hw_lock);
}
static void chv_pipe_power_well_sync_hw(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
chv_set_pipe_power_well(dev_priv, power_well, power_well->count > 0);
}
static void chv_pipe_power_well_enable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
WARN_ON_ONCE(power_well->data != PIPE_A &&
power_well->data != PIPE_B &&
power_well->data != PIPE_C);
chv_set_pipe_power_well(dev_priv, power_well, true);
if (power_well->data == PIPE_A) {
spin_lock_irq(&dev_priv->irq_lock);
valleyview_enable_display_irqs(dev_priv);
spin_unlock_irq(&dev_priv->irq_lock);
if (dev_priv->power_domains.initializing)
return;
intel_hpd_init(dev_priv);
i915_redisable_vga_power_on(dev_priv->dev);
}
}
static void chv_pipe_power_well_disable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
WARN_ON_ONCE(power_well->data != PIPE_A &&
power_well->data != PIPE_B &&
power_well->data != PIPE_C);
if (power_well->data == PIPE_A) {
spin_lock_irq(&dev_priv->irq_lock);
valleyview_disable_display_irqs(dev_priv);
spin_unlock_irq(&dev_priv->irq_lock);
}
chv_set_pipe_power_well(dev_priv, power_well, false);
if (power_well->data == PIPE_A)
vlv_power_sequencer_reset(dev_priv);
}
void intel_display_power_get(struct drm_i915_private *dev_priv,
enum intel_display_power_domain domain)
{
struct i915_power_domains *power_domains;
struct i915_power_well *power_well;
int i;
intel_runtime_pm_get(dev_priv);
power_domains = &dev_priv->power_domains;
mutex_lock(&power_domains->lock);
for_each_power_well(i, power_well, BIT(domain), power_domains) {
if (!power_well->count++) {
DRM_DEBUG_KMS("enabling %s\n", power_well->name);
power_well->ops->enable(dev_priv, power_well);
power_well->hw_enabled = true;
}
}
power_domains->domain_use_count[domain]++;
mutex_unlock(&power_domains->lock);
}
void intel_display_power_put(struct drm_i915_private *dev_priv,
enum intel_display_power_domain domain)
{
struct i915_power_domains *power_domains;
struct i915_power_well *power_well;
int i;
power_domains = &dev_priv->power_domains;
mutex_lock(&power_domains->lock);
WARN_ON(!power_domains->domain_use_count[domain]);
power_domains->domain_use_count[domain]--;
for_each_power_well_rev(i, power_well, BIT(domain), power_domains) {
WARN_ON(!power_well->count);
if (!--power_well->count && i915.disable_power_well) {
DRM_DEBUG_KMS("disabling %s\n", power_well->name);
power_well->hw_enabled = false;
power_well->ops->disable(dev_priv, power_well);
}
}
mutex_unlock(&power_domains->lock);
intel_runtime_pm_put(dev_priv);
}
static struct i915_power_well *lookup_power_well(struct drm_i915_private *dev_priv,
enum punit_power_well power_well_id)
{
struct i915_power_domains *power_domains = &dev_priv->power_domains;
struct i915_power_well *power_well;
int i;
for_each_power_well(i, power_well, POWER_DOMAIN_MASK, power_domains) {
if (power_well->data == power_well_id)
return power_well;
}
return NULL;
}
int intel_power_domains_init(struct drm_i915_private *dev_priv)
{
struct i915_power_domains *power_domains = &dev_priv->power_domains;
mutex_init(&power_domains->lock);
if (IS_HASWELL(dev_priv->dev)) {
set_power_wells(power_domains, hsw_power_wells);
hsw_pwr = power_domains;
} else if (IS_BROADWELL(dev_priv->dev)) {
set_power_wells(power_domains, bdw_power_wells);
hsw_pwr = power_domains;
} else if (IS_CHERRYVIEW(dev_priv->dev)) {
set_power_wells(power_domains, chv_power_wells);
} else if (IS_VALLEYVIEW(dev_priv->dev)) {
set_power_wells(power_domains, vlv_power_wells);
} else {
set_power_wells(power_domains, i9xx_always_on_power_well);
}
return 0;
}
static void intel_runtime_pm_disable(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
struct device *device = &dev->pdev->dev;
if (!HAS_RUNTIME_PM(dev))
return;
if (!intel_enable_rc6(dev))
return;
pm_runtime_get_sync(device);
pm_runtime_disable(device);
}
void intel_power_domains_fini(struct drm_i915_private *dev_priv)
{
intel_runtime_pm_disable(dev_priv);
intel_display_set_init_power(dev_priv, true);
hsw_pwr = NULL;
}
static void intel_power_domains_resume(struct drm_i915_private *dev_priv)
{
struct i915_power_domains *power_domains = &dev_priv->power_domains;
struct i915_power_well *power_well;
int i;
mutex_lock(&power_domains->lock);
for_each_power_well(i, power_well, POWER_DOMAIN_MASK, power_domains) {
power_well->ops->sync_hw(dev_priv, power_well);
power_well->hw_enabled = power_well->ops->is_enabled(dev_priv,
power_well);
}
mutex_unlock(&power_domains->lock);
}
static void vlv_cmnlane_wa(struct drm_i915_private *dev_priv)
{
struct i915_power_well *cmn =
lookup_power_well(dev_priv, PUNIT_POWER_WELL_DPIO_CMN_BC);
struct i915_power_well *disp2d =
lookup_power_well(dev_priv, PUNIT_POWER_WELL_DISP2D);
if (cmn->ops->is_enabled(dev_priv, cmn) &&
disp2d->ops->is_enabled(dev_priv, disp2d) &&
I915_READ(DPIO_CTL) & DPIO_CMNRST)
return;
DRM_DEBUG_KMS("toggling display PHY side reset\n");
disp2d->ops->enable(dev_priv, disp2d);
cmn->ops->disable(dev_priv, cmn);
}
void intel_power_domains_init_hw(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
struct i915_power_domains *power_domains = &dev_priv->power_domains;
power_domains->initializing = true;
if (IS_VALLEYVIEW(dev) && !IS_CHERRYVIEW(dev)) {
mutex_lock(&power_domains->lock);
vlv_cmnlane_wa(dev_priv);
mutex_unlock(&power_domains->lock);
}
intel_display_set_init_power(dev_priv, true);
intel_power_domains_resume(dev_priv);
power_domains->initializing = false;
}
void intel_aux_display_runtime_get(struct drm_i915_private *dev_priv)
{
intel_runtime_pm_get(dev_priv);
}
void intel_aux_display_runtime_put(struct drm_i915_private *dev_priv)
{
intel_runtime_pm_put(dev_priv);
}
void intel_runtime_pm_get(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
struct device *device = &dev->pdev->dev;
if (!HAS_RUNTIME_PM(dev))
return;
pm_runtime_get_sync(device);
WARN(dev_priv->pm.suspended, "Device still suspended.\n");
}
void intel_runtime_pm_get_noresume(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
struct device *device = &dev->pdev->dev;
if (!HAS_RUNTIME_PM(dev))
return;
WARN(dev_priv->pm.suspended, "Getting nosync-ref while suspended.\n");
pm_runtime_get_noresume(device);
}
void intel_runtime_pm_put(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
struct device *device = &dev->pdev->dev;
if (!HAS_RUNTIME_PM(dev))
return;
pm_runtime_mark_last_busy(device);
pm_runtime_put_autosuspend(device);
}
void intel_runtime_pm_enable(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
struct device *device = &dev->pdev->dev;
if (!HAS_RUNTIME_PM(dev))
return;
pm_runtime_set_active(device);
if (!intel_enable_rc6(dev)) {
DRM_INFO("RC6 disabled, disabling runtime PM support\n");
return;
}
pm_runtime_set_autosuspend_delay(device, 10000);
pm_runtime_mark_last_busy(device);
pm_runtime_use_autosuspend(device);
pm_runtime_put_autosuspend(device);
}
int i915_request_power_well(void)
{
struct drm_i915_private *dev_priv;
if (!hsw_pwr)
return -ENODEV;
dev_priv = container_of(hsw_pwr, struct drm_i915_private,
power_domains);
intel_display_power_get(dev_priv, POWER_DOMAIN_AUDIO);
return 0;
}
int i915_release_power_well(void)
{
struct drm_i915_private *dev_priv;
if (!hsw_pwr)
return -ENODEV;
dev_priv = container_of(hsw_pwr, struct drm_i915_private,
power_domains);
intel_display_power_put(dev_priv, POWER_DOMAIN_AUDIO);
return 0;
}
int i915_get_cdclk_freq(void)
{
struct drm_i915_private *dev_priv;
if (!hsw_pwr)
return -ENODEV;
dev_priv = container_of(hsw_pwr, struct drm_i915_private,
power_domains);
return intel_ddi_get_cdclk_freq(dev_priv);
}
