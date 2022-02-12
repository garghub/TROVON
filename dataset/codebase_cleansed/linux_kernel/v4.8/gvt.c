int intel_gvt_init_host(void)
{
if (intel_gvt_host.initialized)
return 0;
if (xen_domain() && !xen_initial_domain())
return -ENODEV;
if (xen_initial_domain()) {
intel_gvt_host.mpt = try_then_request_module(
symbol_get(xengt_mpt), "xengt");
intel_gvt_host.hypervisor_type = INTEL_GVT_HYPERVISOR_XEN;
} else {
intel_gvt_host.mpt = try_then_request_module(
symbol_get(kvmgt_mpt), "kvm");
intel_gvt_host.hypervisor_type = INTEL_GVT_HYPERVISOR_KVM;
}
if (!intel_gvt_host.mpt)
return -EINVAL;
if (!intel_gvt_hypervisor_detect_host())
return -ENODEV;
gvt_dbg_core("Running with hypervisor %s in host mode\n",
supported_hypervisors[intel_gvt_host.hypervisor_type]);
intel_gvt_host.initialized = true;
return 0;
}
static void init_device_info(struct intel_gvt *gvt)
{
if (IS_BROADWELL(gvt->dev_priv))
gvt->device_info.max_support_vgpus = 8;
}
void intel_gvt_clean_device(struct drm_i915_private *dev_priv)
{
struct intel_gvt *gvt = &dev_priv->gvt;
if (WARN_ON(!gvt->initialized))
return;
gvt->initialized = false;
}
int intel_gvt_init_device(struct drm_i915_private *dev_priv)
{
struct intel_gvt *gvt = &dev_priv->gvt;
if (WARN_ON(!intel_gvt_host.initialized))
return -EINVAL;
if (WARN_ON(gvt->initialized))
return -EEXIST;
gvt_dbg_core("init gvt device\n");
init_device_info(gvt);
gvt_dbg_core("gvt device creation is done\n");
gvt->initialized = true;
return 0;
}
