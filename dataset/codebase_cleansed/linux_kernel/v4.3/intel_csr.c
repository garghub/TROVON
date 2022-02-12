static char intel_get_stepping(struct drm_device *dev)
{
if (IS_SKYLAKE(dev) && (dev->pdev->revision <
ARRAY_SIZE(skl_stepping_info)))
return skl_stepping_info[dev->pdev->revision].stepping;
else
return -ENODATA;
}
static char intel_get_substepping(struct drm_device *dev)
{
if (IS_SKYLAKE(dev) && (dev->pdev->revision <
ARRAY_SIZE(skl_stepping_info)))
return skl_stepping_info[dev->pdev->revision].substepping;
else
return -ENODATA;
}
enum csr_state intel_csr_load_status_get(struct drm_i915_private *dev_priv)
{
enum csr_state state;
mutex_lock(&dev_priv->csr_lock);
state = dev_priv->csr.state;
mutex_unlock(&dev_priv->csr_lock);
return state;
}
void intel_csr_load_status_set(struct drm_i915_private *dev_priv,
enum csr_state state)
{
mutex_lock(&dev_priv->csr_lock);
dev_priv->csr.state = state;
mutex_unlock(&dev_priv->csr_lock);
}
void intel_csr_load_program(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 *payload = dev_priv->csr.dmc_payload;
uint32_t i, fw_size;
if (!IS_GEN9(dev)) {
DRM_ERROR("No CSR support available for this platform\n");
return;
}
mutex_lock(&dev_priv->csr_lock);
fw_size = dev_priv->csr.dmc_fw_size;
for (i = 0; i < fw_size; i++)
I915_WRITE(CSR_PROGRAM_BASE + i * 4,
payload[i]);
for (i = 0; i < dev_priv->csr.mmio_count; i++) {
I915_WRITE(dev_priv->csr.mmioaddr[i],
dev_priv->csr.mmiodata[i]);
}
dev_priv->csr.state = FW_LOADED;
mutex_unlock(&dev_priv->csr_lock);
}
static void finish_csr_load(const struct firmware *fw, void *context)
{
struct drm_i915_private *dev_priv = context;
struct drm_device *dev = dev_priv->dev;
struct intel_css_header *css_header;
struct intel_package_header *package_header;
struct intel_dmc_header *dmc_header;
struct intel_csr *csr = &dev_priv->csr;
char stepping = intel_get_stepping(dev);
char substepping = intel_get_substepping(dev);
uint32_t dmc_offset = CSR_DEFAULT_FW_OFFSET, readcount = 0, nbytes;
uint32_t i;
uint32_t *dmc_payload;
bool fw_loaded = false;
if (!fw) {
i915_firmware_load_error_print(csr->fw_path, 0);
goto out;
}
if ((stepping == -ENODATA) || (substepping == -ENODATA)) {
DRM_ERROR("Unknown stepping info, firmware loading failed\n");
goto out;
}
css_header = (struct intel_css_header *)fw->data;
if (sizeof(struct intel_css_header) !=
(css_header->header_len * 4)) {
DRM_ERROR("Firmware has wrong CSS header length %u bytes\n",
(css_header->header_len * 4));
goto out;
}
readcount += sizeof(struct intel_css_header);
package_header = (struct intel_package_header *)
&fw->data[readcount];
if (sizeof(struct intel_package_header) !=
(package_header->header_len * 4)) {
DRM_ERROR("Firmware has wrong package header length %u bytes\n",
(package_header->header_len * 4));
goto out;
}
readcount += sizeof(struct intel_package_header);
for (i = 0; i < package_header->num_entries; i++) {
if (package_header->fw_info[i].substepping == '*' &&
stepping == package_header->fw_info[i].stepping) {
dmc_offset = package_header->fw_info[i].offset;
break;
} else if (stepping == package_header->fw_info[i].stepping &&
substepping == package_header->fw_info[i].substepping) {
dmc_offset = package_header->fw_info[i].offset;
break;
} else if (package_header->fw_info[i].stepping == '*' &&
package_header->fw_info[i].substepping == '*')
dmc_offset = package_header->fw_info[i].offset;
}
if (dmc_offset == CSR_DEFAULT_FW_OFFSET) {
DRM_ERROR("Firmware not supported for %c stepping\n", stepping);
goto out;
}
readcount += dmc_offset;
dmc_header = (struct intel_dmc_header *)&fw->data[readcount];
if (sizeof(struct intel_dmc_header) != (dmc_header->header_len)) {
DRM_ERROR("Firmware has wrong dmc header length %u bytes\n",
(dmc_header->header_len));
goto out;
}
readcount += sizeof(struct intel_dmc_header);
if (dmc_header->mmio_count > ARRAY_SIZE(csr->mmioaddr)) {
DRM_ERROR("Firmware has wrong mmio count %u\n",
dmc_header->mmio_count);
goto out;
}
csr->mmio_count = dmc_header->mmio_count;
for (i = 0; i < dmc_header->mmio_count; i++) {
if (dmc_header->mmioaddr[i] < CSR_MMIO_START_RANGE ||
dmc_header->mmioaddr[i] > CSR_MMIO_END_RANGE) {
DRM_ERROR(" Firmware has wrong mmio address 0x%x\n",
dmc_header->mmioaddr[i]);
goto out;
}
csr->mmioaddr[i] = dmc_header->mmioaddr[i];
csr->mmiodata[i] = dmc_header->mmiodata[i];
}
nbytes = dmc_header->fw_size * 4;
if (nbytes > CSR_MAX_FW_SIZE) {
DRM_ERROR("CSR firmware too big (%u) bytes\n", nbytes);
goto out;
}
csr->dmc_fw_size = dmc_header->fw_size;
csr->dmc_payload = kmalloc(nbytes, GFP_KERNEL);
if (!csr->dmc_payload) {
DRM_ERROR("Memory allocation failed for dmc payload\n");
goto out;
}
dmc_payload = csr->dmc_payload;
memcpy(dmc_payload, &fw->data[readcount], nbytes);
intel_csr_load_program(dev);
fw_loaded = true;
DRM_DEBUG_KMS("Finished loading %s\n", dev_priv->csr.fw_path);
out:
if (fw_loaded)
intel_runtime_pm_put(dev_priv);
else
intel_csr_load_status_set(dev_priv, FW_FAILED);
release_firmware(fw);
}
void intel_csr_ucode_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_csr *csr = &dev_priv->csr;
int ret;
if (!HAS_CSR(dev))
return;
if (IS_SKYLAKE(dev))
csr->fw_path = I915_CSR_SKL;
else {
DRM_ERROR("Unexpected: no known CSR firmware for platform\n");
intel_csr_load_status_set(dev_priv, FW_FAILED);
return;
}
DRM_DEBUG_KMS("Loading %s\n", csr->fw_path);
intel_runtime_pm_get(dev_priv);
ret = request_firmware_nowait(THIS_MODULE, true, csr->fw_path,
&dev_priv->dev->pdev->dev,
GFP_KERNEL, dev_priv,
finish_csr_load);
if (ret) {
i915_firmware_load_error_print(csr->fw_path, ret);
intel_csr_load_status_set(dev_priv, FW_FAILED);
}
}
void intel_csr_ucode_fini(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!HAS_CSR(dev))
return;
intel_csr_load_status_set(dev_priv, FW_FAILED);
kfree(dev_priv->csr.dmc_payload);
}
void assert_csr_loaded(struct drm_i915_private *dev_priv)
{
WARN(intel_csr_load_status_get(dev_priv) != FW_LOADED,
"CSR is not loaded.\n");
WARN(!I915_READ(CSR_PROGRAM_BASE),
"CSR program storage start is NULL\n");
WARN(!I915_READ(CSR_SSP_BASE), "CSR SSP Base Not fine\n");
WARN(!I915_READ(CSR_HTP_SKL), "CSR HTP Not fine\n");
}
