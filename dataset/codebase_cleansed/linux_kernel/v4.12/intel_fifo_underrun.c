static bool ivb_can_enable_err_int(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *crtc;
enum pipe pipe;
lockdep_assert_held(&dev_priv->irq_lock);
for_each_pipe(dev_priv, pipe) {
crtc = intel_get_crtc_for_pipe(dev_priv, pipe);
if (crtc->cpu_fifo_underrun_disabled)
return false;
}
return true;
}
static bool cpt_can_enable_serr_int(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
enum pipe pipe;
struct intel_crtc *crtc;
lockdep_assert_held(&dev_priv->irq_lock);
for_each_pipe(dev_priv, pipe) {
crtc = intel_get_crtc_for_pipe(dev_priv, pipe);
if (crtc->pch_fifo_underrun_disabled)
return false;
}
return true;
}
static void i9xx_check_fifo_underruns(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
i915_reg_t reg = PIPESTAT(crtc->pipe);
u32 pipestat = I915_READ(reg) & 0xffff0000;
lockdep_assert_held(&dev_priv->irq_lock);
if ((pipestat & PIPE_FIFO_UNDERRUN_STATUS) == 0)
return;
I915_WRITE(reg, pipestat | PIPE_FIFO_UNDERRUN_STATUS);
POSTING_READ(reg);
trace_intel_cpu_fifo_underrun(dev_priv, crtc->pipe);
DRM_ERROR("pipe %c underrun\n", pipe_name(crtc->pipe));
}
static void i9xx_set_fifo_underrun_reporting(struct drm_device *dev,
enum pipe pipe,
bool enable, bool old)
{
struct drm_i915_private *dev_priv = to_i915(dev);
i915_reg_t reg = PIPESTAT(pipe);
u32 pipestat = I915_READ(reg) & 0xffff0000;
lockdep_assert_held(&dev_priv->irq_lock);
if (enable) {
I915_WRITE(reg, pipestat | PIPE_FIFO_UNDERRUN_STATUS);
POSTING_READ(reg);
} else {
if (old && pipestat & PIPE_FIFO_UNDERRUN_STATUS)
DRM_ERROR("pipe %c underrun\n", pipe_name(pipe));
}
}
static void ironlake_set_fifo_underrun_reporting(struct drm_device *dev,
enum pipe pipe, bool enable)
{
struct drm_i915_private *dev_priv = to_i915(dev);
uint32_t bit = (pipe == PIPE_A) ? DE_PIPEA_FIFO_UNDERRUN :
DE_PIPEB_FIFO_UNDERRUN;
if (enable)
ilk_enable_display_irq(dev_priv, bit);
else
ilk_disable_display_irq(dev_priv, bit);
}
static void ivybridge_check_fifo_underruns(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
enum pipe pipe = crtc->pipe;
uint32_t err_int = I915_READ(GEN7_ERR_INT);
lockdep_assert_held(&dev_priv->irq_lock);
if ((err_int & ERR_INT_FIFO_UNDERRUN(pipe)) == 0)
return;
I915_WRITE(GEN7_ERR_INT, ERR_INT_FIFO_UNDERRUN(pipe));
POSTING_READ(GEN7_ERR_INT);
trace_intel_cpu_fifo_underrun(dev_priv, pipe);
DRM_ERROR("fifo underrun on pipe %c\n", pipe_name(pipe));
}
static void ivybridge_set_fifo_underrun_reporting(struct drm_device *dev,
enum pipe pipe,
bool enable, bool old)
{
struct drm_i915_private *dev_priv = to_i915(dev);
if (enable) {
I915_WRITE(GEN7_ERR_INT, ERR_INT_FIFO_UNDERRUN(pipe));
if (!ivb_can_enable_err_int(dev))
return;
ilk_enable_display_irq(dev_priv, DE_ERR_INT_IVB);
} else {
ilk_disable_display_irq(dev_priv, DE_ERR_INT_IVB);
if (old &&
I915_READ(GEN7_ERR_INT) & ERR_INT_FIFO_UNDERRUN(pipe)) {
DRM_ERROR("uncleared fifo underrun on pipe %c\n",
pipe_name(pipe));
}
}
}
static void broadwell_set_fifo_underrun_reporting(struct drm_device *dev,
enum pipe pipe, bool enable)
{
struct drm_i915_private *dev_priv = to_i915(dev);
if (enable)
bdw_enable_pipe_irq(dev_priv, pipe, GEN8_PIPE_FIFO_UNDERRUN);
else
bdw_disable_pipe_irq(dev_priv, pipe, GEN8_PIPE_FIFO_UNDERRUN);
}
static void ibx_set_fifo_underrun_reporting(struct drm_device *dev,
enum transcoder pch_transcoder,
bool enable)
{
struct drm_i915_private *dev_priv = to_i915(dev);
uint32_t bit = (pch_transcoder == TRANSCODER_A) ?
SDE_TRANSA_FIFO_UNDER : SDE_TRANSB_FIFO_UNDER;
if (enable)
ibx_enable_display_interrupt(dev_priv, bit);
else
ibx_disable_display_interrupt(dev_priv, bit);
}
static void cpt_check_pch_fifo_underruns(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
enum transcoder pch_transcoder = (enum transcoder) crtc->pipe;
uint32_t serr_int = I915_READ(SERR_INT);
lockdep_assert_held(&dev_priv->irq_lock);
if ((serr_int & SERR_INT_TRANS_FIFO_UNDERRUN(pch_transcoder)) == 0)
return;
I915_WRITE(SERR_INT, SERR_INT_TRANS_FIFO_UNDERRUN(pch_transcoder));
POSTING_READ(SERR_INT);
trace_intel_pch_fifo_underrun(dev_priv, pch_transcoder);
DRM_ERROR("pch fifo underrun on pch transcoder %s\n",
transcoder_name(pch_transcoder));
}
static void cpt_set_fifo_underrun_reporting(struct drm_device *dev,
enum transcoder pch_transcoder,
bool enable, bool old)
{
struct drm_i915_private *dev_priv = to_i915(dev);
if (enable) {
I915_WRITE(SERR_INT,
SERR_INT_TRANS_FIFO_UNDERRUN(pch_transcoder));
if (!cpt_can_enable_serr_int(dev))
return;
ibx_enable_display_interrupt(dev_priv, SDE_ERROR_CPT);
} else {
ibx_disable_display_interrupt(dev_priv, SDE_ERROR_CPT);
if (old && I915_READ(SERR_INT) &
SERR_INT_TRANS_FIFO_UNDERRUN(pch_transcoder)) {
DRM_ERROR("uncleared pch fifo underrun on pch transcoder %s\n",
transcoder_name(pch_transcoder));
}
}
}
static bool __intel_set_cpu_fifo_underrun_reporting(struct drm_device *dev,
enum pipe pipe, bool enable)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *crtc = intel_get_crtc_for_pipe(dev_priv, pipe);
bool old;
lockdep_assert_held(&dev_priv->irq_lock);
old = !crtc->cpu_fifo_underrun_disabled;
crtc->cpu_fifo_underrun_disabled = !enable;
if (HAS_GMCH_DISPLAY(dev_priv))
i9xx_set_fifo_underrun_reporting(dev, pipe, enable, old);
else if (IS_GEN5(dev_priv) || IS_GEN6(dev_priv))
ironlake_set_fifo_underrun_reporting(dev, pipe, enable);
else if (IS_GEN7(dev_priv))
ivybridge_set_fifo_underrun_reporting(dev, pipe, enable, old);
else if (IS_GEN8(dev_priv) || IS_GEN9(dev_priv))
broadwell_set_fifo_underrun_reporting(dev, pipe, enable);
return old;
}
bool intel_set_cpu_fifo_underrun_reporting(struct drm_i915_private *dev_priv,
enum pipe pipe, bool enable)
{
unsigned long flags;
bool ret;
spin_lock_irqsave(&dev_priv->irq_lock, flags);
ret = __intel_set_cpu_fifo_underrun_reporting(&dev_priv->drm, pipe,
enable);
spin_unlock_irqrestore(&dev_priv->irq_lock, flags);
return ret;
}
bool intel_set_pch_fifo_underrun_reporting(struct drm_i915_private *dev_priv,
enum transcoder pch_transcoder,
bool enable)
{
struct intel_crtc *crtc =
intel_get_crtc_for_pipe(dev_priv, (enum pipe) pch_transcoder);
unsigned long flags;
bool old;
spin_lock_irqsave(&dev_priv->irq_lock, flags);
old = !crtc->pch_fifo_underrun_disabled;
crtc->pch_fifo_underrun_disabled = !enable;
if (HAS_PCH_IBX(dev_priv))
ibx_set_fifo_underrun_reporting(&dev_priv->drm,
pch_transcoder,
enable);
else
cpt_set_fifo_underrun_reporting(&dev_priv->drm,
pch_transcoder,
enable, old);
spin_unlock_irqrestore(&dev_priv->irq_lock, flags);
return old;
}
void intel_cpu_fifo_underrun_irq_handler(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
struct intel_crtc *crtc = intel_get_crtc_for_pipe(dev_priv, pipe);
if (crtc == NULL)
return;
if (HAS_GMCH_DISPLAY(dev_priv) &&
crtc->cpu_fifo_underrun_disabled)
return;
if (intel_set_cpu_fifo_underrun_reporting(dev_priv, pipe, false)) {
trace_intel_cpu_fifo_underrun(dev_priv, pipe);
DRM_ERROR("CPU pipe %c FIFO underrun\n",
pipe_name(pipe));
}
intel_fbc_handle_fifo_underrun_irq(dev_priv);
}
void intel_pch_fifo_underrun_irq_handler(struct drm_i915_private *dev_priv,
enum transcoder pch_transcoder)
{
if (intel_set_pch_fifo_underrun_reporting(dev_priv, pch_transcoder,
false)) {
trace_intel_pch_fifo_underrun(dev_priv, pch_transcoder);
DRM_ERROR("PCH transcoder %s FIFO underrun\n",
transcoder_name(pch_transcoder));
}
}
void intel_check_cpu_fifo_underruns(struct drm_i915_private *dev_priv)
{
struct intel_crtc *crtc;
spin_lock_irq(&dev_priv->irq_lock);
for_each_intel_crtc(&dev_priv->drm, crtc) {
if (crtc->cpu_fifo_underrun_disabled)
continue;
if (HAS_GMCH_DISPLAY(dev_priv))
i9xx_check_fifo_underruns(crtc);
else if (IS_GEN7(dev_priv))
ivybridge_check_fifo_underruns(crtc);
}
spin_unlock_irq(&dev_priv->irq_lock);
}
void intel_check_pch_fifo_underruns(struct drm_i915_private *dev_priv)
{
struct intel_crtc *crtc;
spin_lock_irq(&dev_priv->irq_lock);
for_each_intel_crtc(&dev_priv->drm, crtc) {
if (crtc->pch_fifo_underrun_disabled)
continue;
if (HAS_PCH_CPT(dev_priv))
cpt_check_pch_fifo_underruns(crtc);
}
spin_unlock_irq(&dev_priv->irq_lock);
}
