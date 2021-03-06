static int vlv_sideband_rw(struct drm_i915_private *dev_priv, u32 devfn,
u32 port, u32 opcode, u32 addr, u32 *val)
{
u32 cmd, be = 0xf, bar = 0;
bool is_read = (opcode == PUNIT_OPCODE_REG_READ ||
opcode == DPIO_OPCODE_REG_READ);
cmd = (devfn << IOSF_DEVFN_SHIFT) | (opcode << IOSF_OPCODE_SHIFT) |
(port << IOSF_PORT_SHIFT) | (be << IOSF_BYTE_ENABLES_SHIFT) |
(bar << IOSF_BAR_SHIFT);
WARN_ON(!mutex_is_locked(&dev_priv->dpio_lock));
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
u32 vlv_punit_read(struct drm_i915_private *dev_priv, u8 addr)
{
u32 val = 0;
WARN_ON(!mutex_is_locked(&dev_priv->rps.hw_lock));
mutex_lock(&dev_priv->dpio_lock);
vlv_sideband_rw(dev_priv, PCI_DEVFN(2, 0), IOSF_PORT_PUNIT,
PUNIT_OPCODE_REG_READ, addr, &val);
mutex_unlock(&dev_priv->dpio_lock);
return val;
}
void vlv_punit_write(struct drm_i915_private *dev_priv, u8 addr, u32 val)
{
WARN_ON(!mutex_is_locked(&dev_priv->rps.hw_lock));
mutex_lock(&dev_priv->dpio_lock);
vlv_sideband_rw(dev_priv, PCI_DEVFN(2, 0), IOSF_PORT_PUNIT,
PUNIT_OPCODE_REG_WRITE, addr, &val);
mutex_unlock(&dev_priv->dpio_lock);
}
u32 vlv_nc_read(struct drm_i915_private *dev_priv, u8 addr)
{
u32 val = 0;
WARN_ON(!mutex_is_locked(&dev_priv->rps.hw_lock));
mutex_lock(&dev_priv->dpio_lock);
vlv_sideband_rw(dev_priv, PCI_DEVFN(2, 0), IOSF_PORT_NC,
PUNIT_OPCODE_REG_READ, addr, &val);
mutex_unlock(&dev_priv->dpio_lock);
return val;
}
u32 vlv_dpio_read(struct drm_i915_private *dev_priv, int reg)
{
u32 val = 0;
vlv_sideband_rw(dev_priv, DPIO_DEVFN, IOSF_PORT_DPIO,
DPIO_OPCODE_REG_READ, reg, &val);
return val;
}
void vlv_dpio_write(struct drm_i915_private *dev_priv, int reg, u32 val)
{
vlv_sideband_rw(dev_priv, DPIO_DEVFN, IOSF_PORT_DPIO,
DPIO_OPCODE_REG_WRITE, reg, &val);
}
u32 intel_sbi_read(struct drm_i915_private *dev_priv, u16 reg,
enum intel_sbi_destination destination)
{
u32 value = 0;
WARN_ON(!mutex_is_locked(&dev_priv->dpio_lock));
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
WARN_ON(!mutex_is_locked(&dev_priv->dpio_lock));
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
