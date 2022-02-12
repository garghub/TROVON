static int vlv_sideband_rw(struct drm_i915_private *dev_priv, u32 devfn,
u32 port, u32 opcode, u32 addr, u32 *val)
{
u32 cmd, be = 0xf, bar = 0;
bool is_read = (opcode == SB_MRD_NP || opcode == SB_CRRDDA_NP);
cmd = (devfn << IOSF_DEVFN_SHIFT) | (opcode << IOSF_OPCODE_SHIFT) |
(port << IOSF_PORT_SHIFT) | (be << IOSF_BYTE_ENABLES_SHIFT) |
(bar << IOSF_BAR_SHIFT);
WARN_ON(!mutex_is_locked(&dev_priv->sb_lock));
if (wait_for((I915_READ(VLV_IOSF_DOORBELL_REQ) & IOSF_SB_BUSY) == 0, 5)) {
DRM_DEBUG_DRIVER("IOSF sideband idle wait (%s) timed out\n",
is_read ? "read" : "write");
return -EAGAIN;
}
I915_WRITE(VLV_IOSF_ADDR, addr);
if (!is_read)
I915_WRITE(VLV_IOSF_DATA, *val);
I915_WRITE(VLV_IOSF_DOORBELL_REQ, cmd);
if (wait_for((I915_READ(VLV_IOSF_DOORBELL_REQ) & IOSF_SB_BUSY) == 0, 5)) {
DRM_DEBUG_DRIVER("IOSF sideband finish wait (%s) timed out\n",
is_read ? "read" : "write");
return -ETIMEDOUT;
}
if (is_read)
*val = I915_READ(VLV_IOSF_DATA);
I915_WRITE(VLV_IOSF_DATA, 0);
return 0;
}
u32 vlv_punit_read(struct drm_i915_private *dev_priv, u32 addr)
{
u32 val = 0;
WARN_ON(!mutex_is_locked(&dev_priv->rps.hw_lock));
mutex_lock(&dev_priv->sb_lock);
vlv_sideband_rw(dev_priv, PCI_DEVFN(0, 0), IOSF_PORT_PUNIT,
SB_CRRDDA_NP, addr, &val);
mutex_unlock(&dev_priv->sb_lock);
return val;
}
void vlv_punit_write(struct drm_i915_private *dev_priv, u32 addr, u32 val)
{
WARN_ON(!mutex_is_locked(&dev_priv->rps.hw_lock));
mutex_lock(&dev_priv->sb_lock);
vlv_sideband_rw(dev_priv, PCI_DEVFN(0, 0), IOSF_PORT_PUNIT,
SB_CRWRDA_NP, addr, &val);
mutex_unlock(&dev_priv->sb_lock);
}
u32 vlv_bunit_read(struct drm_i915_private *dev_priv, u32 reg)
{
u32 val = 0;
vlv_sideband_rw(dev_priv, PCI_DEVFN(0, 0), IOSF_PORT_BUNIT,
SB_CRRDDA_NP, reg, &val);
return val;
}
void vlv_bunit_write(struct drm_i915_private *dev_priv, u32 reg, u32 val)
{
vlv_sideband_rw(dev_priv, PCI_DEVFN(0, 0), IOSF_PORT_BUNIT,
SB_CRWRDA_NP, reg, &val);
}
u32 vlv_nc_read(struct drm_i915_private *dev_priv, u8 addr)
{
u32 val = 0;
WARN_ON(!mutex_is_locked(&dev_priv->rps.hw_lock));
mutex_lock(&dev_priv->sb_lock);
vlv_sideband_rw(dev_priv, PCI_DEVFN(0, 0), IOSF_PORT_NC,
SB_CRRDDA_NP, addr, &val);
mutex_unlock(&dev_priv->sb_lock);
return val;
}
u32 vlv_gpio_nc_read(struct drm_i915_private *dev_priv, u32 reg)
{
u32 val = 0;
vlv_sideband_rw(dev_priv, PCI_DEVFN(0, 0), IOSF_PORT_GPIO_NC,
SB_CRRDDA_NP, reg, &val);
return val;
}
void vlv_gpio_nc_write(struct drm_i915_private *dev_priv, u32 reg, u32 val)
{
vlv_sideband_rw(dev_priv, PCI_DEVFN(0, 0), IOSF_PORT_GPIO_NC,
SB_CRWRDA_NP, reg, &val);
}
u32 vlv_cck_read(struct drm_i915_private *dev_priv, u32 reg)
{
u32 val = 0;
vlv_sideband_rw(dev_priv, PCI_DEVFN(0, 0), IOSF_PORT_CCK,
SB_CRRDDA_NP, reg, &val);
return val;
}
void vlv_cck_write(struct drm_i915_private *dev_priv, u32 reg, u32 val)
{
vlv_sideband_rw(dev_priv, PCI_DEVFN(0, 0), IOSF_PORT_CCK,
SB_CRWRDA_NP, reg, &val);
}
u32 vlv_ccu_read(struct drm_i915_private *dev_priv, u32 reg)
{
u32 val = 0;
vlv_sideband_rw(dev_priv, PCI_DEVFN(0, 0), IOSF_PORT_CCU,
SB_CRRDDA_NP, reg, &val);
return val;
}
void vlv_ccu_write(struct drm_i915_private *dev_priv, u32 reg, u32 val)
{
vlv_sideband_rw(dev_priv, PCI_DEVFN(0, 0), IOSF_PORT_CCU,
SB_CRWRDA_NP, reg, &val);
}
u32 vlv_gps_core_read(struct drm_i915_private *dev_priv, u32 reg)
{
u32 val = 0;
vlv_sideband_rw(dev_priv, PCI_DEVFN(0, 0), IOSF_PORT_GPS_CORE,
SB_CRRDDA_NP, reg, &val);
return val;
}
void vlv_gps_core_write(struct drm_i915_private *dev_priv, u32 reg, u32 val)
{
vlv_sideband_rw(dev_priv, PCI_DEVFN(0, 0), IOSF_PORT_GPS_CORE,
SB_CRWRDA_NP, reg, &val);
}
u32 vlv_dpio_read(struct drm_i915_private *dev_priv, enum pipe pipe, int reg)
{
u32 val = 0;
vlv_sideband_rw(dev_priv, DPIO_DEVFN, DPIO_PHY_IOSF_PORT(DPIO_PHY(pipe)),
SB_MRD_NP, reg, &val);
WARN(val == 0xffffffff, "DPIO read pipe %c reg 0x%x == 0x%x\n",
pipe_name(pipe), reg, val);
return val;
}
void vlv_dpio_write(struct drm_i915_private *dev_priv, enum pipe pipe, int reg, u32 val)
{
vlv_sideband_rw(dev_priv, DPIO_DEVFN, DPIO_PHY_IOSF_PORT(DPIO_PHY(pipe)),
SB_MWR_NP, reg, &val);
}
u32 intel_sbi_read(struct drm_i915_private *dev_priv, u16 reg,
enum intel_sbi_destination destination)
{
u32 value = 0;
WARN_ON(!mutex_is_locked(&dev_priv->sb_lock));
if (wait_for((I915_READ(SBI_CTL_STAT) & SBI_BUSY) == 0,
100)) {
DRM_ERROR("timeout waiting for SBI to become ready\n");
return 0;
}
I915_WRITE(SBI_ADDR, (reg << 16));
if (destination == SBI_ICLK)
value = SBI_CTL_DEST_ICLK | SBI_CTL_OP_CRRD;
else
value = SBI_CTL_DEST_MPHY | SBI_CTL_OP_IORD;
I915_WRITE(SBI_CTL_STAT, value | SBI_BUSY);
if (wait_for((I915_READ(SBI_CTL_STAT) & (SBI_BUSY | SBI_RESPONSE_FAIL)) == 0,
100)) {
DRM_ERROR("timeout waiting for SBI to complete read transaction\n");
return 0;
}
return I915_READ(SBI_DATA);
}
void intel_sbi_write(struct drm_i915_private *dev_priv, u16 reg, u32 value,
enum intel_sbi_destination destination)
{
u32 tmp;
WARN_ON(!mutex_is_locked(&dev_priv->sb_lock));
if (wait_for((I915_READ(SBI_CTL_STAT) & SBI_BUSY) == 0,
100)) {
DRM_ERROR("timeout waiting for SBI to become ready\n");
return;
}
I915_WRITE(SBI_ADDR, (reg << 16));
I915_WRITE(SBI_DATA, value);
if (destination == SBI_ICLK)
tmp = SBI_CTL_DEST_ICLK | SBI_CTL_OP_CRWR;
else
tmp = SBI_CTL_DEST_MPHY | SBI_CTL_OP_IOWR;
I915_WRITE(SBI_CTL_STAT, SBI_BUSY | tmp);
if (wait_for((I915_READ(SBI_CTL_STAT) & (SBI_BUSY | SBI_RESPONSE_FAIL)) == 0,
100)) {
DRM_ERROR("timeout waiting for SBI to complete write transaction\n");
return;
}
}
u32 vlv_flisdsi_read(struct drm_i915_private *dev_priv, u32 reg)
{
u32 val = 0;
vlv_sideband_rw(dev_priv, DPIO_DEVFN, IOSF_PORT_FLISDSI, SB_CRRDDA_NP,
reg, &val);
return val;
}
void vlv_flisdsi_write(struct drm_i915_private *dev_priv, u32 reg, u32 val)
{
vlv_sideband_rw(dev_priv, DPIO_DEVFN, IOSF_PORT_FLISDSI, SB_CRWRDA_NP,
reg, &val);
}
