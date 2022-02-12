static bool tfp410_readb(struct intel_dvo_device *dvo, int addr, uint8_t *ch)
{
struct tfp410_priv *tfp = dvo->dev_priv;
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
};
if (!tfp->quiet) {
DRM_DEBUG_KMS("Unable to read register 0x%02x from %s:%02x.\n",
addr, adapter->name, dvo->slave_addr);
}
return false;
}
static bool tfp410_writeb(struct intel_dvo_device *dvo, int addr, uint8_t ch)
{
struct tfp410_priv *tfp = dvo->dev_priv;
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
if (!tfp->quiet) {
DRM_DEBUG_KMS("Unable to write register 0x%02x to %s:%d.\n",
addr, adapter->name, dvo->slave_addr);
}
return false;
}
static int tfp410_getid(struct intel_dvo_device *dvo, int addr)
{
uint8_t ch1, ch2;
if (tfp410_readb(dvo, addr+0, &ch1) &&
tfp410_readb(dvo, addr+1, &ch2))
return ((ch2 << 8) & 0xFF00) | (ch1 & 0x00FF);
return -1;
}
static bool tfp410_init(struct intel_dvo_device *dvo,
struct i2c_adapter *adapter)
{
struct tfp410_priv *tfp;
int id;
tfp = kzalloc(sizeof(struct tfp410_priv), GFP_KERNEL);
if (tfp == NULL)
return false;
dvo->i2c_bus = adapter;
dvo->dev_priv = tfp;
tfp->quiet = true;
if ((id = tfp410_getid(dvo, TFP410_VID_LO)) != TFP410_VID) {
DRM_DEBUG_KMS("tfp410 not detected got VID %X: from %s "
"Slave %d.\n",
id, adapter->name, dvo->slave_addr);
goto out;
}
if ((id = tfp410_getid(dvo, TFP410_DID_LO)) != TFP410_DID) {
DRM_DEBUG_KMS("tfp410 not detected got DID %X: from %s "
"Slave %d.\n",
id, adapter->name, dvo->slave_addr);
goto out;
}
tfp->quiet = false;
return true;
out:
kfree(tfp);
return false;
}
static enum drm_connector_status tfp410_detect(struct intel_dvo_device *dvo)
{
enum drm_connector_status ret = connector_status_disconnected;
uint8_t ctl2;
if (tfp410_readb(dvo, TFP410_CTL_2, &ctl2)) {
if (ctl2 & TFP410_CTL_2_RSEN)
ret = connector_status_connected;
else
ret = connector_status_disconnected;
}
return ret;
}
static enum drm_mode_status tfp410_mode_valid(struct intel_dvo_device *dvo,
struct drm_display_mode *mode)
{
return MODE_OK;
}
static void tfp410_mode_set(struct intel_dvo_device *dvo,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return;
}
static void tfp410_dpms(struct intel_dvo_device *dvo, bool enable)
{
uint8_t ctl1;
if (!tfp410_readb(dvo, TFP410_CTL_1, &ctl1))
return;
if (enable)
ctl1 |= TFP410_CTL_1_PD;
else
ctl1 &= ~TFP410_CTL_1_PD;
tfp410_writeb(dvo, TFP410_CTL_1, ctl1);
}
static bool tfp410_get_hw_state(struct intel_dvo_device *dvo)
{
uint8_t ctl1;
if (!tfp410_readb(dvo, TFP410_CTL_1, &ctl1))
return false;
if (ctl1 & TFP410_CTL_1_PD)
return true;
else
return false;
}
static void tfp410_dump_regs(struct intel_dvo_device *dvo)
{
uint8_t val, val2;
tfp410_readb(dvo, TFP410_REV, &val);
DRM_DEBUG_KMS("TFP410_REV: 0x%02X\n", val);
tfp410_readb(dvo, TFP410_CTL_1, &val);
DRM_DEBUG_KMS("TFP410_CTL1: 0x%02X\n", val);
tfp410_readb(dvo, TFP410_CTL_2, &val);
DRM_DEBUG_KMS("TFP410_CTL2: 0x%02X\n", val);
tfp410_readb(dvo, TFP410_CTL_3, &val);
DRM_DEBUG_KMS("TFP410_CTL3: 0x%02X\n", val);
tfp410_readb(dvo, TFP410_USERCFG, &val);
DRM_DEBUG_KMS("TFP410_USERCFG: 0x%02X\n", val);
tfp410_readb(dvo, TFP410_DE_DLY, &val);
DRM_DEBUG_KMS("TFP410_DE_DLY: 0x%02X\n", val);
tfp410_readb(dvo, TFP410_DE_CTL, &val);
DRM_DEBUG_KMS("TFP410_DE_CTL: 0x%02X\n", val);
tfp410_readb(dvo, TFP410_DE_TOP, &val);
DRM_DEBUG_KMS("TFP410_DE_TOP: 0x%02X\n", val);
tfp410_readb(dvo, TFP410_DE_CNT_LO, &val);
tfp410_readb(dvo, TFP410_DE_CNT_HI, &val2);
DRM_DEBUG_KMS("TFP410_DE_CNT: 0x%02X%02X\n", val2, val);
tfp410_readb(dvo, TFP410_DE_LIN_LO, &val);
tfp410_readb(dvo, TFP410_DE_LIN_HI, &val2);
DRM_DEBUG_KMS("TFP410_DE_LIN: 0x%02X%02X\n", val2, val);
tfp410_readb(dvo, TFP410_H_RES_LO, &val);
tfp410_readb(dvo, TFP410_H_RES_HI, &val2);
DRM_DEBUG_KMS("TFP410_H_RES: 0x%02X%02X\n", val2, val);
tfp410_readb(dvo, TFP410_V_RES_LO, &val);
tfp410_readb(dvo, TFP410_V_RES_HI, &val2);
DRM_DEBUG_KMS("TFP410_V_RES: 0x%02X%02X\n", val2, val);
}
static void tfp410_destroy(struct intel_dvo_device *dvo)
{
struct tfp410_priv *tfp = dvo->dev_priv;
if (tfp) {
kfree(tfp);
dvo->dev_priv = NULL;
}
}
