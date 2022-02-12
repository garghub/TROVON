static char *ch7xxx_get_id(uint8_t vid)
{
int i;
for (i = 0; i < ARRAY_SIZE(ch7xxx_ids); i++) {
if (ch7xxx_ids[i].vid == vid)
return ch7xxx_ids[i].name;
}
return NULL;
}
static char *ch7xxx_get_did(uint8_t did)
{
int i;
for (i = 0; i < ARRAY_SIZE(ch7xxx_dids); i++) {
if (ch7xxx_dids[i].did == did)
return ch7xxx_dids[i].name;
}
return NULL;
}
static bool ch7xxx_readb(struct intel_dvo_device *dvo, int addr, uint8_t *ch)
{
struct ch7xxx_priv *ch7xxx = dvo->dev_priv;
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
if (!ch7xxx->quiet) {
DRM_DEBUG_KMS("Unable to read register 0x%02x from %s:%02x.\n",
addr, adapter->name, dvo->slave_addr);
}
return false;
}
static bool ch7xxx_writeb(struct intel_dvo_device *dvo, int addr, uint8_t ch)
{
struct ch7xxx_priv *ch7xxx = dvo->dev_priv;
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
if (!ch7xxx->quiet) {
DRM_DEBUG_KMS("Unable to write register 0x%02x to %s:%d.\n",
addr, adapter->name, dvo->slave_addr);
}
return false;
}
static bool ch7xxx_init(struct intel_dvo_device *dvo,
struct i2c_adapter *adapter)
{
struct ch7xxx_priv *ch7xxx;
uint8_t vendor, device;
char *name, *devid;
ch7xxx = kzalloc(sizeof(struct ch7xxx_priv), GFP_KERNEL);
if (ch7xxx == NULL)
return false;
dvo->i2c_bus = adapter;
dvo->dev_priv = ch7xxx;
ch7xxx->quiet = true;
if (!ch7xxx_readb(dvo, CH7xxx_REG_VID, &vendor))
goto out;
name = ch7xxx_get_id(vendor);
if (!name) {
DRM_DEBUG_KMS("ch7xxx not detected; got 0x%02x from %s "
"slave %d.\n",
vendor, adapter->name, dvo->slave_addr);
goto out;
}
if (!ch7xxx_readb(dvo, CH7xxx_REG_DID, &device))
goto out;
devid = ch7xxx_get_did(device);
if (!devid) {
DRM_DEBUG_KMS("ch7xxx not detected; got 0x%02x from %s "
"slave %d.\n",
vendor, adapter->name, dvo->slave_addr);
goto out;
}
ch7xxx->quiet = false;
DRM_DEBUG_KMS("Detected %s chipset, vendor/device ID 0x%02x/0x%02x\n",
name, vendor, device);
return true;
out:
kfree(ch7xxx);
return false;
}
static enum drm_connector_status ch7xxx_detect(struct intel_dvo_device *dvo)
{
uint8_t cdet, orig_pm, pm;
ch7xxx_readb(dvo, CH7xxx_PM, &orig_pm);
pm = orig_pm;
pm &= ~CH7xxx_PM_FPD;
pm |= CH7xxx_PM_DVIL | CH7xxx_PM_DVIP;
ch7xxx_writeb(dvo, CH7xxx_PM, pm);
ch7xxx_readb(dvo, CH7xxx_CONNECTION_DETECT, &cdet);
ch7xxx_writeb(dvo, CH7xxx_PM, orig_pm);
if (cdet & CH7xxx_CDET_DVI)
return connector_status_connected;
return connector_status_disconnected;
}
static enum drm_mode_status ch7xxx_mode_valid(struct intel_dvo_device *dvo,
struct drm_display_mode *mode)
{
if (mode->clock > 165000)
return MODE_CLOCK_HIGH;
return MODE_OK;
}
static void ch7xxx_mode_set(struct intel_dvo_device *dvo,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
uint8_t tvco, tpcp, tpd, tlpf, idf;
if (mode->clock <= 65000) {
tvco = 0x23;
tpcp = 0x08;
tpd = 0x16;
tlpf = 0x60;
} else {
tvco = 0x2d;
tpcp = 0x06;
tpd = 0x26;
tlpf = 0xa0;
}
ch7xxx_writeb(dvo, CH7xxx_TCTL, 0x00);
ch7xxx_writeb(dvo, CH7xxx_TVCO, tvco);
ch7xxx_writeb(dvo, CH7xxx_TPCP, tpcp);
ch7xxx_writeb(dvo, CH7xxx_TPD, tpd);
ch7xxx_writeb(dvo, CH7xxx_TPVT, 0x30);
ch7xxx_writeb(dvo, CH7xxx_TLPF, tlpf);
ch7xxx_writeb(dvo, CH7xxx_TCT, 0x00);
ch7xxx_readb(dvo, CH7xxx_IDF, &idf);
idf &= ~(CH7xxx_IDF_HSP | CH7xxx_IDF_VSP);
if (mode->flags & DRM_MODE_FLAG_PHSYNC)
idf |= CH7xxx_IDF_HSP;
if (mode->flags & DRM_MODE_FLAG_PVSYNC)
idf |= CH7xxx_IDF_HSP;
ch7xxx_writeb(dvo, CH7xxx_IDF, idf);
}
static void ch7xxx_dpms(struct intel_dvo_device *dvo, bool enable)
{
if (enable)
ch7xxx_writeb(dvo, CH7xxx_PM, CH7xxx_PM_DVIL | CH7xxx_PM_DVIP);
else
ch7xxx_writeb(dvo, CH7xxx_PM, CH7xxx_PM_FPD);
}
static bool ch7xxx_get_hw_state(struct intel_dvo_device *dvo)
{
u8 val;
ch7xxx_readb(dvo, CH7xxx_PM, &val);
if (val & (CH7xxx_PM_DVIL | CH7xxx_PM_DVIP))
return true;
else
return false;
}
static void ch7xxx_dump_regs(struct intel_dvo_device *dvo)
{
int i;
for (i = 0; i < CH7xxx_NUM_REGS; i++) {
uint8_t val;
if ((i % 8) == 0)
DRM_LOG_KMS("\n %02X: ", i);
ch7xxx_readb(dvo, i, &val);
DRM_LOG_KMS("%02X ", val);
}
}
static void ch7xxx_destroy(struct intel_dvo_device *dvo)
{
struct ch7xxx_priv *ch7xxx = dvo->dev_priv;
if (ch7xxx) {
kfree(ch7xxx);
dvo->dev_priv = NULL;
}
}
