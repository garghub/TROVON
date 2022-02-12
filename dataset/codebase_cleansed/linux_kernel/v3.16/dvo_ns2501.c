static bool ns2501_readb(struct intel_dvo_device *dvo, int addr, uint8_t * ch)
{
struct ns2501_priv *ns = dvo->dev_priv;
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
if (!ns->quiet) {
DRM_DEBUG_KMS
("Unable to read register 0x%02x from %s:0x%02x.\n", addr,
adapter->name, dvo->slave_addr);
}
return false;
}
static bool ns2501_writeb(struct intel_dvo_device *dvo, int addr, uint8_t ch)
{
struct ns2501_priv *ns = dvo->dev_priv;
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
if (i2c_transfer(adapter, &msg, 1) == 1) {
return true;
}
if (!ns->quiet) {
DRM_DEBUG_KMS("Unable to write register 0x%02x to %s:%d\n",
addr, adapter->name, dvo->slave_addr);
}
return false;
}
static bool ns2501_init(struct intel_dvo_device *dvo,
struct i2c_adapter *adapter)
{
struct ns2501_priv *ns;
unsigned char ch;
ns = kzalloc(sizeof(struct ns2501_priv), GFP_KERNEL);
if (ns == NULL)
return false;
dvo->i2c_bus = adapter;
dvo->dev_priv = ns;
ns->quiet = true;
if (!ns2501_readb(dvo, NS2501_VID_LO, &ch))
goto out;
if (ch != (NS2501_VID & 0xff)) {
DRM_DEBUG_KMS("ns2501 not detected got %d: from %s Slave %d.\n",
ch, adapter->name, dvo->slave_addr);
goto out;
}
if (!ns2501_readb(dvo, NS2501_DID_LO, &ch))
goto out;
if (ch != (NS2501_DID & 0xff)) {
DRM_DEBUG_KMS("ns2501 not detected got %d: from %s Slave %d.\n",
ch, adapter->name, dvo->slave_addr);
goto out;
}
ns->quiet = false;
ns->reg_8_set = 0;
ns->reg_8_shadow =
NS2501_8_PD | NS2501_8_BPAS | NS2501_8_VEN | NS2501_8_HEN;
DRM_DEBUG_KMS("init ns2501 dvo controller successfully!\n");
return true;
out:
kfree(ns);
return false;
}
static enum drm_connector_status ns2501_detect(struct intel_dvo_device *dvo)
{
return connector_status_connected;
}
static enum drm_mode_status ns2501_mode_valid(struct intel_dvo_device *dvo,
struct drm_display_mode *mode)
{
DRM_DEBUG_KMS
("is mode valid (hdisplay=%d,htotal=%d,vdisplay=%d,vtotal=%d)\n",
mode->hdisplay, mode->htotal, mode->vdisplay, mode->vtotal);
if ((mode->hdisplay == 800 && mode->vdisplay == 600) ||
(mode->hdisplay == 640 && mode->vdisplay == 480) ||
(mode->hdisplay == 1024 && mode->vdisplay == 768)) {
return MODE_OK;
} else {
return MODE_ONE_SIZE;
}
}
static void ns2501_mode_set(struct intel_dvo_device *dvo,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
bool ok;
int retries = 10;
struct ns2501_priv *ns = (struct ns2501_priv *)(dvo->dev_priv);
DRM_DEBUG_KMS
("set mode (hdisplay=%d,htotal=%d,vdisplay=%d,vtotal=%d).\n",
mode->hdisplay, mode->htotal, mode->vdisplay, mode->vtotal);
do {
ok = true;
if (mode->hdisplay == 800 && mode->vdisplay == 600) {
ns->reg_8_shadow &= ~NS2501_8_BPAS;
DRM_DEBUG_KMS("switching to 800x600\n");
ok &= ns2501_writeb(dvo, 0x11, 0xc8);
ok &= ns2501_writeb(dvo, 0x1b, 0x19);
ok &= ns2501_writeb(dvo, 0x1c, 0x62);
ok &= ns2501_writeb(dvo, 0x1d, 0x02);
ok &= ns2501_writeb(dvo, 0x34, 0x03);
ok &= ns2501_writeb(dvo, 0x35, 0xff);
ok &= ns2501_writeb(dvo, 0x80, 0x27);
ok &= ns2501_writeb(dvo, 0x81, 0x03);
ok &= ns2501_writeb(dvo, 0x82, 0x41);
ok &= ns2501_writeb(dvo, 0x83, 0x05);
ok &= ns2501_writeb(dvo, 0x8d, 0x02);
ok &= ns2501_writeb(dvo, 0x8e, 0x04);
ok &= ns2501_writeb(dvo, 0x8f, 0x00);
ok &= ns2501_writeb(dvo, 0x90, 0xfe);
ok &= ns2501_writeb(dvo, 0x91, 0x07);
ok &= ns2501_writeb(dvo, 0x94, 0x00);
ok &= ns2501_writeb(dvo, 0x95, 0x00);
ok &= ns2501_writeb(dvo, 0x96, 0x00);
ok &= ns2501_writeb(dvo, 0x99, 0x00);
ok &= ns2501_writeb(dvo, 0x9a, 0x88);
ok &= ns2501_writeb(dvo, 0x9c, 0x23);
ok &= ns2501_writeb(dvo, 0x9d, 0x00);
ok &= ns2501_writeb(dvo, 0x9e, 0x25);
ok &= ns2501_writeb(dvo, 0x9f, 0x03);
ok &= ns2501_writeb(dvo, 0xa4, 0x80);
ok &= ns2501_writeb(dvo, 0xb6, 0x00);
ok &= ns2501_writeb(dvo, 0xb9, 0xc8);
ok &= ns2501_writeb(dvo, 0xba, 0x00);
ok &= ns2501_writeb(dvo, 0xc0, 0x05);
ok &= ns2501_writeb(dvo, 0xc1, 0xd7);
ok &= ns2501_writeb(dvo, 0xc2, 0x00);
ok &= ns2501_writeb(dvo, 0xc3, 0xf8);
ok &= ns2501_writeb(dvo, 0xc4, 0x03);
ok &= ns2501_writeb(dvo, 0xc5, 0x1a);
ok &= ns2501_writeb(dvo, 0xc6, 0x00);
ok &= ns2501_writeb(dvo, 0xc7, 0x73);
ok &= ns2501_writeb(dvo, 0xc8, 0x02);
} else if (mode->hdisplay == 640 && mode->vdisplay == 480) {
DRM_DEBUG_KMS("switching to 640x480\n");
ns->reg_8_shadow &= ~NS2501_8_BPAS;
ok &= ns2501_writeb(dvo, 0x11, 0xa0);
ok &= ns2501_writeb(dvo, 0x1b, 0x11);
ok &= ns2501_writeb(dvo, 0x1c, 0x54);
ok &= ns2501_writeb(dvo, 0x1d, 0x03);
ok &= ns2501_writeb(dvo, 0x34, 0x03);
ok &= ns2501_writeb(dvo, 0x35, 0xff);
ok &= ns2501_writeb(dvo, 0x80, 0xff);
ok &= ns2501_writeb(dvo, 0x81, 0x07);
ok &= ns2501_writeb(dvo, 0x82, 0x3d);
ok &= ns2501_writeb(dvo, 0x83, 0x05);
ok &= ns2501_writeb(dvo, 0x8d, 0x02);
ok &= ns2501_writeb(dvo, 0x8e, 0x10);
ok &= ns2501_writeb(dvo, 0x8f, 0x00);
ok &= ns2501_writeb(dvo, 0x90, 0xff);
ok &= ns2501_writeb(dvo, 0x91, 0x07);
ok &= ns2501_writeb(dvo, 0x94, 0x00);
ok &= ns2501_writeb(dvo, 0x95, 0x00);
ok &= ns2501_writeb(dvo, 0x96, 0x05);
ok &= ns2501_writeb(dvo, 0x99, 0x00);
ok &= ns2501_writeb(dvo, 0x9a, 0x88);
ok &= ns2501_writeb(dvo, 0x9c, 0x24);
ok &= ns2501_writeb(dvo, 0x9d, 0x00);
ok &= ns2501_writeb(dvo, 0x9e, 0x25);
ok &= ns2501_writeb(dvo, 0x9f, 0x03);
ok &= ns2501_writeb(dvo, 0xa4, 0x84);
ok &= ns2501_writeb(dvo, 0xb6, 0x09);
ok &= ns2501_writeb(dvo, 0xb9, 0xa0);
ok &= ns2501_writeb(dvo, 0xba, 0x00);
ok &= ns2501_writeb(dvo, 0xc0, 0x05);
ok &= ns2501_writeb(dvo, 0xc1, 0x90);
ok &= ns2501_writeb(dvo, 0xc2, 0x00);
ok &= ns2501_writeb(dvo, 0xc3, 0x0f);
ok &= ns2501_writeb(dvo, 0xc4, 0x03);
ok &= ns2501_writeb(dvo, 0xc5, 0x16);
ok &= ns2501_writeb(dvo, 0xc6, 0x00);
ok &= ns2501_writeb(dvo, 0xc7, 0x02);
ok &= ns2501_writeb(dvo, 0xc8, 0x02);
} else if (mode->hdisplay == 1024 && mode->vdisplay == 768) {
DRM_DEBUG_KMS("switching to 1024x768\n");
ns->reg_8_shadow |= NS2501_8_BPAS;
ok &= ns2501_writeb(dvo, 0x37, 0x44);
} else {
ns->reg_8_shadow |= NS2501_8_BPAS;
}
ok &= ns2501_writeb(dvo, NS2501_REG8, ns->reg_8_shadow);
} while (!ok && retries--);
}
static bool ns2501_get_hw_state(struct intel_dvo_device *dvo)
{
unsigned char ch;
if (!ns2501_readb(dvo, NS2501_REG8, &ch))
return false;
if (ch & NS2501_8_PD)
return true;
else
return false;
}
static void ns2501_dpms(struct intel_dvo_device *dvo, bool enable)
{
bool ok;
int retries = 10;
struct ns2501_priv *ns = (struct ns2501_priv *)(dvo->dev_priv);
unsigned char ch;
DRM_DEBUG_KMS("Trying set the dpms of the DVO to %i\n", enable);
ch = ns->reg_8_shadow;
if (enable)
ch |= NS2501_8_PD;
else
ch &= ~NS2501_8_PD;
if (ns->reg_8_set == 0 || ns->reg_8_shadow != ch) {
ns->reg_8_set = 1;
ns->reg_8_shadow = ch;
do {
ok = true;
ok &= ns2501_writeb(dvo, NS2501_REG8, ch);
ok &=
ns2501_writeb(dvo, 0x34,
enable ? 0x03 : 0x00);
ok &=
ns2501_writeb(dvo, 0x35,
enable ? 0xff : 0x00);
} while (!ok && retries--);
}
}
static void ns2501_dump_regs(struct intel_dvo_device *dvo)
{
uint8_t val;
ns2501_readb(dvo, NS2501_FREQ_LO, &val);
DRM_DEBUG_KMS("NS2501_FREQ_LO: 0x%02x\n", val);
ns2501_readb(dvo, NS2501_FREQ_HI, &val);
DRM_DEBUG_KMS("NS2501_FREQ_HI: 0x%02x\n", val);
ns2501_readb(dvo, NS2501_REG8, &val);
DRM_DEBUG_KMS("NS2501_REG8: 0x%02x\n", val);
ns2501_readb(dvo, NS2501_REG9, &val);
DRM_DEBUG_KMS("NS2501_REG9: 0x%02x\n", val);
ns2501_readb(dvo, NS2501_REGC, &val);
DRM_DEBUG_KMS("NS2501_REGC: 0x%02x\n", val);
}
static void ns2501_destroy(struct intel_dvo_device *dvo)
{
struct ns2501_priv *ns = dvo->dev_priv;
if (ns) {
kfree(ns);
dvo->dev_priv = NULL;
}
}
