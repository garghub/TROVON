void intel_uc_init_early(struct drm_i915_private *dev_priv)
{
mutex_init(&dev_priv->guc.send_mutex);
}
static bool intel_guc_recv(struct intel_guc *guc, u32 *status)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
u32 val = I915_READ(SOFT_SCRATCH(0));
*status = val;
return INTEL_GUC_RECV_IS_RESPONSE(val);
}
int intel_guc_send(struct intel_guc *guc, const u32 *action, u32 len)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
u32 status;
int i;
int ret;
if (WARN_ON(len < 1 || len > 15))
return -EINVAL;
mutex_lock(&guc->send_mutex);
intel_uncore_forcewake_get(dev_priv, FORCEWAKE_ALL);
dev_priv->guc.action_count += 1;
dev_priv->guc.action_cmd = action[0];
for (i = 0; i < len; i++)
I915_WRITE(SOFT_SCRATCH(i), action[i]);
POSTING_READ(SOFT_SCRATCH(i - 1));
I915_WRITE(GUC_SEND_INTERRUPT, GUC_SEND_TRIGGER);
ret = wait_for_us(intel_guc_recv(guc, &status), 10);
if (ret)
ret = wait_for(intel_guc_recv(guc, &status), 10);
if (status != INTEL_GUC_STATUS_SUCCESS) {
if (ret != -ETIMEDOUT)
ret = -EIO;
DRM_WARN("INTEL_GUC_SEND: Action 0x%X failed;"
" ret=%d status=0x%08X response=0x%08X\n",
action[0], ret, status, I915_READ(SOFT_SCRATCH(15)));
dev_priv->guc.action_fail += 1;
dev_priv->guc.action_err = ret;
}
dev_priv->guc.action_status = status;
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_ALL);
mutex_unlock(&guc->send_mutex);
return ret;
}
int intel_guc_sample_forcewake(struct intel_guc *guc)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
u32 action[2];
action[0] = INTEL_GUC_ACTION_SAMPLE_FORCEWAKE;
if (!intel_enable_rc6() || NEEDS_WaRsDisableCoarsePowerGating(dev_priv))
action[1] = 0;
else
action[1] = GUC_FORCEWAKE_RENDER | GUC_FORCEWAKE_MEDIA;
return intel_guc_send(guc, action, ARRAY_SIZE(action));
}
