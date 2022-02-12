static const struct stepping_info *
intel_get_stepping_info(struct drm_i915_private *dev_priv)
{
const struct stepping_info *si;
unsigned int size;
if (IS_SKYLAKE(dev_priv)) {
size = ARRAY_SIZE(skl_stepping_info);
si = skl_stepping_info;
} else if (IS_BROXTON(dev_priv)) {
size = ARRAY_SIZE(bxt_stepping_info);
si = bxt_stepping_info;
} else {
size = 0;
}
if (INTEL_REVID(dev_priv) < size)
return si + INTEL_REVID(dev_priv);
return &no_stepping_info;
}
static void gen9_set_dc_state_debugmask(struct drm_i915_private *dev_priv)
{
uint32_t val, mask;
mask = DC_STATE_DEBUG_MASK_MEMORY_UP;
if (IS_BROXTON(dev_priv))
mask |= DC_STATE_DEBUG_MASK_CORES;
val = I915_READ(DC_STATE_DEBUG);
if ((val & mask) != mask) {
val |= mask;
I915_WRITE(DC_STATE_DEBUG, val);
POSTING_READ(DC_STATE_DEBUG);
}
}
void intel_csr_load_program(struct drm_i915_private *dev_priv)
{
u32 *payload = dev_priv->csr.dmc_payload;
uint32_t i, fw_size;
if (!HAS_CSR(dev_priv)) {
DRM_ERROR("No CSR support available for this platform\n");
return;
}
if (!dev_priv->csr.dmc_payload) {
DRM_ERROR("Tried to program CSR with empty payload\n");
return;
}
fw_size = dev_priv->csr.dmc_fw_size;
for (i = 0; i < fw_size; i++)
I915_WRITE(CSR_PROGRAM(i), payload[i]);
for (i = 0; i < dev_priv->csr.mmio_count; i++) {
I915_WRITE(dev_priv->csr.mmioaddr[i],
dev_priv->csr.mmiodata[i]);
}
dev_priv->csr.dc_state = 0;
gen9_set_dc_state_debugmask(dev_priv);
}
static uint32_t *parse_csr_fw(struct drm_i915_private *dev_priv,
const struct firmware *fw)
{
struct intel_css_header *css_header;
struct intel_package_header *package_header;
struct intel_dmc_header *dmc_header;
struct intel_csr *csr = &dev_priv->csr;
const struct stepping_info *si = intel_get_stepping_info(dev_priv);
uint32_t dmc_offset = CSR_DEFAULT_FW_OFFSET, readcount = 0, nbytes;
uint32_t i;
uint32_t *dmc_payload;
uint32_t required_version;
if (!fw)
return NULL;
css_header = (struct intel_css_header *)fw->data;
if (sizeof(struct intel_css_header) !=
(css_header->header_len * 4)) {
DRM_ERROR("Firmware has wrong CSS header length %u bytes\n",
(css_header->header_len * 4));
return NULL;
}
csr->version = css_header->version;
if (IS_CANNONLAKE(dev_priv)) {
required_version = CNL_CSR_VERSION_REQUIRED;
} else if (IS_GEMINILAKE(dev_priv)) {
required_version = GLK_CSR_VERSION_REQUIRED;
} else if (IS_KABYLAKE(dev_priv) || IS_COFFEELAKE(dev_priv)) {
required_version = KBL_CSR_VERSION_REQUIRED;
} else if (IS_SKYLAKE(dev_priv)) {
required_version = SKL_CSR_VERSION_REQUIRED;
} else if (IS_BROXTON(dev_priv)) {
required_version = BXT_CSR_VERSION_REQUIRED;
} else {
MISSING_CASE(INTEL_REVID(dev_priv));
required_version = 0;
}
if (csr->version != required_version) {
DRM_INFO("Refusing to load DMC firmware v%u.%u,"
" please use v%u.%u [" FIRMWARE_URL "].\n",
CSR_VERSION_MAJOR(csr->version),
CSR_VERSION_MINOR(csr->version),
CSR_VERSION_MAJOR(required_version),
CSR_VERSION_MINOR(required_version));
return NULL;
}
readcount += sizeof(struct intel_css_header);
package_header = (struct intel_package_header *)
&fw->data[readcount];
if (sizeof(struct intel_package_header) !=
(package_header->header_len * 4)) {
DRM_ERROR("Firmware has wrong package header length %u bytes\n",
(package_header->header_len * 4));
return NULL;
}
readcount += sizeof(struct intel_package_header);
for (i = 0; i < package_header->num_entries; i++) {
if (package_header->fw_info[i].substepping == '*' &&
si->stepping == package_header->fw_info[i].stepping) {
dmc_offset = package_header->fw_info[i].offset;
break;
} else if (si->stepping == package_header->fw_info[i].stepping &&
si->substepping == package_header->fw_info[i].substepping) {
dmc_offset = package_header->fw_info[i].offset;
break;
} else if (package_header->fw_info[i].stepping == '*' &&
package_header->fw_info[i].substepping == '*')
dmc_offset = package_header->fw_info[i].offset;
}
if (dmc_offset == CSR_DEFAULT_FW_OFFSET) {
DRM_ERROR("Firmware not supported for %c stepping\n",
si->stepping);
return NULL;
}
readcount += dmc_offset;
dmc_header = (struct intel_dmc_header *)&fw->data[readcount];
if (sizeof(struct intel_dmc_header) != (dmc_header->header_len)) {
DRM_ERROR("Firmware has wrong dmc header length %u bytes\n",
(dmc_header->header_len));
return NULL;
}
readcount += sizeof(struct intel_dmc_header);
if (dmc_header->mmio_count > ARRAY_SIZE(csr->mmioaddr)) {
DRM_ERROR("Firmware has wrong mmio count %u\n",
dmc_header->mmio_count);
return NULL;
}
csr->mmio_count = dmc_header->mmio_count;
for (i = 0; i < dmc_header->mmio_count; i++) {
if (dmc_header->mmioaddr[i] < CSR_MMIO_START_RANGE ||
dmc_header->mmioaddr[i] > CSR_MMIO_END_RANGE) {
DRM_ERROR(" Firmware has wrong mmio address 0x%x\n",
dmc_header->mmioaddr[i]);
return NULL;
}
csr->mmioaddr[i] = _MMIO(dmc_header->mmioaddr[i]);
csr->mmiodata[i] = dmc_header->mmiodata[i];
}
nbytes = dmc_header->fw_size * 4;
if (nbytes > CSR_MAX_FW_SIZE) {
DRM_ERROR("CSR firmware too big (%u) bytes\n", nbytes);
return NULL;
}
csr->dmc_fw_size = dmc_header->fw_size;
dmc_payload = kmalloc(nbytes, GFP_KERNEL);
if (!dmc_payload) {
DRM_ERROR("Memory allocation failed for dmc payload\n");
return NULL;
}
return memcpy(dmc_payload, &fw->data[readcount], nbytes);
}
static void csr_load_work_fn(struct work_struct *work)
{
struct drm_i915_private *dev_priv;
struct intel_csr *csr;
const struct firmware *fw = NULL;
dev_priv = container_of(work, typeof(*dev_priv), csr.work);
csr = &dev_priv->csr;
request_firmware(&fw, dev_priv->csr.fw_path, &dev_priv->drm.pdev->dev);
if (fw)
dev_priv->csr.dmc_payload = parse_csr_fw(dev_priv, fw);
if (dev_priv->csr.dmc_payload) {
intel_csr_load_program(dev_priv);
intel_display_power_put(dev_priv, POWER_DOMAIN_INIT);
DRM_INFO("Finished loading DMC firmware %s (v%u.%u)\n",
dev_priv->csr.fw_path,
CSR_VERSION_MAJOR(csr->version),
CSR_VERSION_MINOR(csr->version));
} else {
dev_notice(dev_priv->drm.dev,
"Failed to load DMC firmware"
" [" FIRMWARE_URL "],"
" disabling runtime power management.\n");
}
release_firmware(fw);
}
void intel_csr_ucode_init(struct drm_i915_private *dev_priv)
{
struct intel_csr *csr = &dev_priv->csr;
INIT_WORK(&dev_priv->csr.work, csr_load_work_fn);
if (!HAS_CSR(dev_priv))
return;
if (IS_CANNONLAKE(dev_priv))
csr->fw_path = I915_CSR_CNL;
else if (IS_GEMINILAKE(dev_priv))
csr->fw_path = I915_CSR_GLK;
else if (IS_KABYLAKE(dev_priv) || IS_COFFEELAKE(dev_priv))
csr->fw_path = I915_CSR_KBL;
else if (IS_SKYLAKE(dev_priv))
csr->fw_path = I915_CSR_SKL;
else if (IS_BROXTON(dev_priv))
csr->fw_path = I915_CSR_BXT;
else {
DRM_ERROR("Unexpected: no known CSR firmware for platform\n");
return;
}
DRM_DEBUG_KMS("Loading %s\n", csr->fw_path);
intel_display_power_get(dev_priv, POWER_DOMAIN_INIT);
schedule_work(&dev_priv->csr.work);
}
void intel_csr_ucode_suspend(struct drm_i915_private *dev_priv)
{
if (!HAS_CSR(dev_priv))
return;
flush_work(&dev_priv->csr.work);
if (!dev_priv->csr.dmc_payload)
intel_display_power_put(dev_priv, POWER_DOMAIN_INIT);
}
void intel_csr_ucode_resume(struct drm_i915_private *dev_priv)
{
if (!HAS_CSR(dev_priv))
return;
if (!dev_priv->csr.dmc_payload)
intel_display_power_get(dev_priv, POWER_DOMAIN_INIT);
}
void intel_csr_ucode_fini(struct drm_i915_private *dev_priv)
{
if (!HAS_CSR(dev_priv))
return;
intel_csr_ucode_suspend(dev_priv);
kfree(dev_priv->csr.dmc_payload);
}
