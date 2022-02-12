static bool sil164_readb(struct intel_dvo_device *dvo, int addr, uint8_t *ch)
{
struct sil164_priv *sil = dvo->dev_priv;
struct i2c_adapter *adapter = dvo->i2c_bus;
u8 out_buf[2];
u8 in_buf[2];
struct i2c_msg msgs[] = {
{
.addr = dvo->slave_addr,
.flags = 0,
.len = 1,
.buf = out_buf,
},
{
.addr = dvo->slave_addr,
.flags = I2C_M_RD,
.len = 1,
.buf = in_buf,
}
};
out_buf[0] = addr;
out_buf[1] = 0;
if (i2c_transfer(adapter, msgs, 2) == 2) {
*ch = in_buf[0];
return true;
}
if (!sil->quiet) {
DRM_DEBUG_KMS("Unable to read register 0x%02x from %s:%02x.\n",
addr, adapter->name, dvo->slave_addr);
}
return false;
}
static bool sil164_writeb(struct intel_dvo_device *dvo, int addr, uint8_t ch)
{
struct sil164_priv *sil = dvo->dev_priv;
struct i2c_adapter *adapter = dvo->i2c_bus;
uint8_t out_buf[2];
struct i2c_msg msg = {
.addr = dvo->slave_addr,
.flags = 0,
.len = 2,
.buf = out_buf,
};
out_buf[0] = addr;
out_buf[1] = ch;
if (i2c_transfer(adapter, &msg, 1) == 1)
return true;
if (!sil->quiet) {
DRM_DEBUG_KMS("Unable to write register 0x%02x to %s:%d.\n",
addr, adapter->name, dvo->slave_addr);
}
return false;
}
static bool sil164_init(struct intel_dvo_device *dvo,
struct i2c_adapter *adapter)
{
struct sil164_priv *sil;
unsigned char ch;
sil = kzalloc(sizeof(struct sil164_priv), GFP_KERNEL);
if (sil == NULL)
return false;
dvo->i2c_bus = adapter;
dvo->dev_priv = sil;
sil->quiet = true;
if (!sil164_readb(dvo, SIL164_VID_LO, &ch))
goto out;
if (ch != (SIL164_VID & 0xff)) {
DRM_DEBUG_KMS("sil164 not detected got %d: from %s Slave %d.\n",
ch, adapter->name, dvo->slave_addr);
goto out;
}
if (!sil164_readb(dvo, SIL164_DID_LO, &ch))
goto out;
if (ch != (SIL164_DID & 0xff)) {
DRM_DEBUG_KMS("sil164 not detected got %d: from %s Slave %d.\n",
ch, adapter->name, dvo->slave_addr);
goto out;
}
sil->quiet = false;
DRM_DEBUG_KMS("init sil164 dvo controller successfully!\n");
return true;
out:
kfree(sil);
return false;
}
static enum drm_connector_status sil164_detect(struct intel_dvo_device *dvo)
{
uint8_t reg9;
sil164_readb(dvo, SIL164_REG9, &reg9);
if (reg9 & SIL164_9_HTPLG)
return connector_status_connected;
else
return connector_status_disconnected;
}
static enum drm_mode_status sil164_mode_valid(struct intel_dvo_device *dvo,
struct drm_display_mode *mode)
{
return MODE_OK;
}
static void sil164_mode_set(struct intel_dvo_device *dvo,
const struct drm_display_mode *mode,
const struct drm_display_mode *adjusted_mode)
{
return;
}
static void sil164_dpms(struct intel_dvo_device *dvo, bool enable)
{
int ret;
unsigned char ch;
ret = sil164_readb(dvo, SIL164_REG8, &ch);
if (ret == false)
return;
if (enable)
ch |= SIL164_8_PD;
else
ch &= ~SIL164_8_PD;
sil164_writeb(dvo, SIL164_REG8, ch);
return;
}
static bool sil164_get_hw_state(struct intel_dvo_device *dvo)
{
int ret;
unsigned char ch;
ret = sil164_readb(dvo, SIL164_REG8, &ch);
if (ret == false)
return false;
if (ch & SIL164_8_PD)
return true;
else
return false;
}
static void sil164_dump_regs(struct intel_dvo_device *dvo)
{
uint8_t val;
sil164_readb(dvo, SIL164_FREQ_LO, &val);
DRM_DEBUG_KMS("SIL164_FREQ_LO: 0x%02x\n", val);
sil164_readb(dvo, SIL164_FREQ_HI, &val);
DRM_DEBUG_KMS("SIL164_FREQ_HI: 0x%02x\n", val);
sil164_readb(dvo, SIL164_REG8, &val);
DRM_DEBUG_KMS("SIL164_REG8: 0x%02x\n", val);
sil164_readb(dvo, SIL164_REG9, &val);
DRM_DEBUG_KMS("SIL164_REG9: 0x%02x\n", val);
sil164_readb(dvo, SIL164_REGC, &val);
DRM_DEBUG_KMS("SIL164_REGC: 0x%02x\n", val);
}
static void sil164_destroy(struct intel_dvo_device *dvo)
{
struct sil164_priv *sil = dvo->dev_priv;
if (sil) {
kfree(sil);
dvo->dev_priv = NULL;
}
}
