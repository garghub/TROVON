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
if ((mode->hdisplay == 640 && mode->vdisplay == 480 && mode->clock == 25175) ||
(mode->hdisplay == 800 && mode->vdisplay == 600 && mode->clock == 40000) ||
(mode->hdisplay == 1024 && mode->vdisplay == 768 && mode->clock == 65000)) {
return MODE_OK;
} else {
return MODE_ONE_SIZE;
}
}
static void ns2501_mode_set(struct intel_dvo_device *dvo,
const struct drm_display_mode *mode,
const struct drm_display_mode *adjusted_mode)
{
const struct ns2501_configuration *conf;
struct ns2501_priv *ns = (struct ns2501_priv *)(dvo->dev_priv);
int mode_idx, i;
DRM_DEBUG_KMS
("set mode (hdisplay=%d,htotal=%d,vdisplay=%d,vtotal=%d).\n",
mode->hdisplay, mode->htotal, mode->vdisplay, mode->vtotal);
DRM_DEBUG_KMS("Detailed requested mode settings are:\n"
"clock : %d kHz\n"
"hdisplay : %d\n"
"hblank start : %d\n"
"hblank end : %d\n"
"hsync start : %d\n"
"hsync end : %d\n"
"htotal : %d\n"
"hskew : %d\n"
"vdisplay : %d\n"
"vblank start : %d\n"
"hblank end : %d\n"
"vsync start : %d\n"
"vsync end : %d\n"
"vtotal : %d\n",
adjusted_mode->crtc_clock,
adjusted_mode->crtc_hdisplay,
adjusted_mode->crtc_hblank_start,
adjusted_mode->crtc_hblank_end,
adjusted_mode->crtc_hsync_start,
adjusted_mode->crtc_hsync_end,
adjusted_mode->crtc_htotal,
adjusted_mode->crtc_hskew,
adjusted_mode->crtc_vdisplay,
adjusted_mode->crtc_vblank_start,
adjusted_mode->crtc_vblank_end,
adjusted_mode->crtc_vsync_start,
adjusted_mode->crtc_vsync_end,
adjusted_mode->crtc_vtotal);
if (mode->hdisplay == 640 && mode->vdisplay == 480)
mode_idx = MODE_640x480;
else if (mode->hdisplay == 800 && mode->vdisplay == 600)
mode_idx = MODE_800x600;
else if (mode->hdisplay == 1024 && mode->vdisplay == 768)
mode_idx = MODE_1024x768;
else
return;
for (i = 0; i < ARRAY_SIZE(regs_init); i++)
ns2501_writeb(dvo, regs_init[i].offset, regs_init[i].value);
for (i = 0; i < ARRAY_SIZE(mode_agnostic_values); i++)
ns2501_writeb(dvo, mode_agnostic_values[i].offset,
mode_agnostic_values[i].value);
conf = ns2501_modes + mode_idx;
ns->conf = conf;
ns2501_writeb(dvo, NS2501_REG8, conf->conf);
ns2501_writeb(dvo, NS2501_REG1B, conf->pll_a);
ns2501_writeb(dvo, NS2501_REG1C, conf->pll_b & 0xff);
ns2501_writeb(dvo, NS2501_REG1D, conf->pll_b >> 8);
ns2501_writeb(dvo, NS2501_REGC1, conf->hstart & 0xff);
ns2501_writeb(dvo, NS2501_REGC2, conf->hstart >> 8);
ns2501_writeb(dvo, NS2501_REGC3, conf->hstop & 0xff);
ns2501_writeb(dvo, NS2501_REGC4, conf->hstop >> 8);
ns2501_writeb(dvo, NS2501_REGC5, conf->vstart & 0xff);
ns2501_writeb(dvo, NS2501_REGC6, conf->vstart >> 8);
ns2501_writeb(dvo, NS2501_REGC7, conf->vstop & 0xff);
ns2501_writeb(dvo, NS2501_REGC8, conf->vstop >> 8);
ns2501_writeb(dvo, NS2501_REG80, conf->vsync & 0xff);
ns2501_writeb(dvo, NS2501_REG81, conf->vsync >> 8);
ns2501_writeb(dvo, NS2501_REG82, conf->vtotal & 0xff);
ns2501_writeb(dvo, NS2501_REG83, conf->vtotal >> 8);
ns2501_writeb(dvo, NS2501_REG98, conf->hpos & 0xff);
ns2501_writeb(dvo, NS2501_REG99, conf->hpos >> 8);
ns2501_writeb(dvo, NS2501_REG8E, conf->vpos & 0xff);
ns2501_writeb(dvo, NS2501_REG8F, conf->vpos >> 8);
ns2501_writeb(dvo, NS2501_REG9C, conf->voffs & 0xff);
ns2501_writeb(dvo, NS2501_REG9D, conf->voffs >> 8);
ns2501_writeb(dvo, NS2501_REGB8, conf->hscale & 0xff);
ns2501_writeb(dvo, NS2501_REGB9, conf->hscale >> 8);
ns2501_writeb(dvo, NS2501_REG10, conf->vscale & 0xff);
ns2501_writeb(dvo, NS2501_REG11, conf->vscale >> 8);
ns2501_writeb(dvo, NS2501_REGF9, conf->dither);
ns2501_writeb(dvo, NS2501_REG41, conf->syncb);
ns2501_writeb(dvo, NS2501_REGC0, conf->sync);
}
static bool ns2501_get_hw_state(struct intel_dvo_device *dvo)
{
unsigned char ch;
if (!ns2501_readb(dvo, NS2501_REG8, &ch))
return false;
return ch & NS2501_8_PD;
}
static void ns2501_dpms(struct intel_dvo_device *dvo, bool enable)
{
struct ns2501_priv *ns = (struct ns2501_priv *)(dvo->dev_priv);
DRM_DEBUG_KMS("Trying set the dpms of the DVO to %i\n", enable);
if (enable) {
ns2501_writeb(dvo, NS2501_REGC0, ns->conf->sync | 0x08);
ns2501_writeb(dvo, NS2501_REG41, ns->conf->syncb);
ns2501_writeb(dvo, NS2501_REG34, NS2501_34_ENABLE_OUTPUT);
msleep(15);
ns2501_writeb(dvo, NS2501_REG8,
ns->conf->conf | NS2501_8_BPAS);
if (!(ns->conf->conf & NS2501_8_BPAS))
ns2501_writeb(dvo, NS2501_REG8, ns->conf->conf);
msleep(200);
ns2501_writeb(dvo, NS2501_REG34,
NS2501_34_ENABLE_OUTPUT | NS2501_34_ENABLE_BACKLIGHT);
ns2501_writeb(dvo, NS2501_REGC0, ns->conf->sync);
} else {
ns2501_writeb(dvo, NS2501_REG34, NS2501_34_ENABLE_OUTPUT);
msleep(200);
ns2501_writeb(dvo, NS2501_REG8, NS2501_8_VEN | NS2501_8_HEN |
NS2501_8_BPAS);
msleep(15);
ns2501_writeb(dvo, NS2501_REG34, 0x00);
}
}
static void ns2501_destroy(struct intel_dvo_device *dvo)
{
struct ns2501_priv *ns = dvo->dev_priv;
if (ns) {
kfree(ns);
dvo->dev_priv = NULL;
}
}
