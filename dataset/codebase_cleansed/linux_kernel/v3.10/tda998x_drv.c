static void
cec_write(struct drm_encoder *encoder, uint16_t addr, uint8_t val)
{
struct i2c_client *client = to_tda998x_priv(encoder)->cec;
uint8_t buf[] = {addr, val};
int ret;
ret = i2c_master_send(client, buf, ARRAY_SIZE(buf));
if (ret < 0)
dev_err(&client->dev, "Error %d writing to cec:0x%x\n", ret, addr);
}
static uint8_t
cec_read(struct drm_encoder *encoder, uint8_t addr)
{
struct i2c_client *client = to_tda998x_priv(encoder)->cec;
uint8_t val;
int ret;
ret = i2c_master_send(client, &addr, sizeof(addr));
if (ret < 0)
goto fail;
ret = i2c_master_recv(client, &val, sizeof(val));
if (ret < 0)
goto fail;
return val;
fail:
dev_err(&client->dev, "Error %d reading from cec:0x%x\n", ret, addr);
return 0;
}
static void
set_page(struct drm_encoder *encoder, uint16_t reg)
{
struct tda998x_priv *priv = to_tda998x_priv(encoder);
if (REG2PAGE(reg) != priv->current_page) {
struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
uint8_t buf[] = {
REG_CURPAGE, REG2PAGE(reg)
};
int ret = i2c_master_send(client, buf, sizeof(buf));
if (ret < 0)
dev_err(&client->dev, "Error %d writing to REG_CURPAGE\n", ret);
priv->current_page = REG2PAGE(reg);
}
}
static int
reg_read_range(struct drm_encoder *encoder, uint16_t reg, char *buf, int cnt)
{
struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
uint8_t addr = REG2ADDR(reg);
int ret;
set_page(encoder, reg);
ret = i2c_master_send(client, &addr, sizeof(addr));
if (ret < 0)
goto fail;
ret = i2c_master_recv(client, buf, cnt);
if (ret < 0)
goto fail;
return ret;
fail:
dev_err(&client->dev, "Error %d reading from 0x%x\n", ret, reg);
return ret;
}
static uint8_t
reg_read(struct drm_encoder *encoder, uint16_t reg)
{
uint8_t val = 0;
reg_read_range(encoder, reg, &val, sizeof(val));
return val;
}
static void
reg_write(struct drm_encoder *encoder, uint16_t reg, uint8_t val)
{
struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
uint8_t buf[] = {REG2ADDR(reg), val};
int ret;
set_page(encoder, reg);
ret = i2c_master_send(client, buf, ARRAY_SIZE(buf));
if (ret < 0)
dev_err(&client->dev, "Error %d writing to 0x%x\n", ret, reg);
}
static void
reg_write16(struct drm_encoder *encoder, uint16_t reg, uint16_t val)
{
struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
uint8_t buf[] = {REG2ADDR(reg), val >> 8, val};
int ret;
set_page(encoder, reg);
ret = i2c_master_send(client, buf, ARRAY_SIZE(buf));
if (ret < 0)
dev_err(&client->dev, "Error %d writing to 0x%x\n", ret, reg);
}
static void
reg_set(struct drm_encoder *encoder, uint16_t reg, uint8_t val)
{
reg_write(encoder, reg, reg_read(encoder, reg) | val);
}
static void
reg_clear(struct drm_encoder *encoder, uint16_t reg, uint8_t val)
{
reg_write(encoder, reg, reg_read(encoder, reg) & ~val);
}
static void
tda998x_reset(struct drm_encoder *encoder)
{
reg_set(encoder, REG_SOFTRESET, SOFTRESET_AUDIO | SOFTRESET_I2C_MASTER);
msleep(50);
reg_clear(encoder, REG_SOFTRESET, SOFTRESET_AUDIO | SOFTRESET_I2C_MASTER);
msleep(50);
reg_set(encoder, REG_MAIN_CNTRL0, MAIN_CNTRL0_SR);
reg_clear(encoder, REG_MAIN_CNTRL0, MAIN_CNTRL0_SR);
reg_write(encoder, REG_PLL_SERIAL_1, 0x00);
reg_write(encoder, REG_PLL_SERIAL_2, PLL_SERIAL_2_SRL_NOSC(1));
reg_write(encoder, REG_PLL_SERIAL_3, 0x00);
reg_write(encoder, REG_SERIALIZER, 0x00);
reg_write(encoder, REG_BUFFER_OUT, 0x00);
reg_write(encoder, REG_PLL_SCG1, 0x00);
reg_write(encoder, REG_AUDIO_DIV, 0x03);
reg_write(encoder, REG_SEL_CLK, SEL_CLK_SEL_CLK1 | SEL_CLK_ENA_SC_CLK);
reg_write(encoder, REG_PLL_SCGN1, 0xfa);
reg_write(encoder, REG_PLL_SCGN2, 0x00);
reg_write(encoder, REG_PLL_SCGR1, 0x5b);
reg_write(encoder, REG_PLL_SCGR2, 0x00);
reg_write(encoder, REG_PLL_SCG2, 0x10);
}
static void
tda998x_encoder_set_config(struct drm_encoder *encoder, void *params)
{
}
static void
tda998x_encoder_dpms(struct drm_encoder *encoder, int mode)
{
struct tda998x_priv *priv = to_tda998x_priv(encoder);
if (mode != DRM_MODE_DPMS_ON)
mode = DRM_MODE_DPMS_OFF;
if (mode == priv->dpms)
return;
switch (mode) {
case DRM_MODE_DPMS_ON:
reg_write(encoder, REG_ENA_AP, 0xff);
reg_write(encoder, REG_ENA_VP_0, 0xff);
reg_write(encoder, REG_ENA_VP_1, 0xff);
reg_write(encoder, REG_ENA_VP_2, 0xff);
reg_write(encoder, REG_VIP_CNTRL_0,
VIP_CNTRL_0_SWAP_A(2) | VIP_CNTRL_0_SWAP_B(3));
reg_write(encoder, REG_VIP_CNTRL_1,
VIP_CNTRL_1_SWAP_C(0) | VIP_CNTRL_1_SWAP_D(1));
reg_write(encoder, REG_VIP_CNTRL_2,
VIP_CNTRL_2_SWAP_E(4) | VIP_CNTRL_2_SWAP_F(5));
break;
case DRM_MODE_DPMS_OFF:
reg_write(encoder, REG_ENA_AP, 0x00);
reg_write(encoder, REG_ENA_VP_0, 0x00);
reg_write(encoder, REG_ENA_VP_1, 0x00);
reg_write(encoder, REG_ENA_VP_2, 0x00);
break;
}
priv->dpms = mode;
}
static void
tda998x_encoder_save(struct drm_encoder *encoder)
{
DBG("");
}
static void
tda998x_encoder_restore(struct drm_encoder *encoder)
{
DBG("");
}
static bool
tda998x_encoder_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static int
tda998x_encoder_mode_valid(struct drm_encoder *encoder,
struct drm_display_mode *mode)
{
return MODE_OK;
}
static void
tda998x_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct tda998x_priv *priv = to_tda998x_priv(encoder);
uint16_t hs_start, hs_end, line_start, line_end;
uint16_t vwin_start, vwin_end, de_start, de_end;
uint16_t ref_pix, ref_line, pix_start2;
uint8_t reg, div, rep;
hs_start = mode->hsync_start - mode->hdisplay;
hs_end = mode->hsync_end - mode->hdisplay;
line_start = 1;
line_end = 1 + mode->vsync_end - mode->vsync_start;
vwin_start = mode->vtotal - mode->vsync_start;
vwin_end = vwin_start + mode->vdisplay;
de_start = mode->htotal - mode->hdisplay;
de_end = mode->htotal;
pix_start2 = 0;
if (mode->flags & DRM_MODE_FLAG_INTERLACE)
pix_start2 = (mode->htotal / 2) + hs_start;
ref_line = 2;
ref_pix = 3 + hs_start;
div = 148500 / mode->clock;
DBG("clock=%d, div=%u", mode->clock, div);
DBG("hs_start=%u, hs_end=%u, line_start=%u, line_end=%u",
hs_start, hs_end, line_start, line_end);
DBG("vwin_start=%u, vwin_end=%u, de_start=%u, de_end=%u",
vwin_start, vwin_end, de_start, de_end);
DBG("ref_line=%u, ref_pix=%u, pix_start2=%u",
ref_line, ref_pix, pix_start2);
reg_set(encoder, REG_AIP_CNTRL_0, AIP_CNTRL_0_RST_FIFO);
reg_set(encoder, REG_TBG_CNTRL_1, TBG_CNTRL_1_DWIN_DIS);
reg_clear(encoder, REG_TX33, TX33_HDMI);
reg_write(encoder, REG_ENC_CNTRL, ENC_CNTRL_CTL_CODE(0));
reg_write(encoder, REG_HVF_CNTRL_0, HVF_CNTRL_0_PREFIL(0) |
HVF_CNTRL_0_INTPOL(0));
reg_write(encoder, REG_VIP_CNTRL_5, VIP_CNTRL_5_SP_CNT(0));
reg_write(encoder, REG_VIP_CNTRL_4, VIP_CNTRL_4_BLANKIT(0) |
VIP_CNTRL_4_BLC(0));
reg_clear(encoder, REG_PLL_SERIAL_3, PLL_SERIAL_3_SRL_CCIR);
reg_clear(encoder, REG_PLL_SERIAL_1, PLL_SERIAL_1_SRL_MAN_IZ);
reg_clear(encoder, REG_PLL_SERIAL_3, PLL_SERIAL_3_SRL_DE);
reg_write(encoder, REG_SERIALIZER, 0);
reg_write(encoder, REG_HVF_CNTRL_1, HVF_CNTRL_1_VQR(0));
rep = 0;
reg_write(encoder, REG_RPT_CNTRL, 0);
reg_write(encoder, REG_SEL_CLK, SEL_CLK_SEL_VRF_CLK(0) |
SEL_CLK_SEL_CLK1 | SEL_CLK_ENA_SC_CLK);
reg_write(encoder, REG_PLL_SERIAL_2, PLL_SERIAL_2_SRL_NOSC(div) |
PLL_SERIAL_2_SRL_PR(rep));
reg_write16(encoder, REG_VS_PIX_STRT_2_MSB, pix_start2);
reg_write16(encoder, REG_VS_PIX_END_2_MSB, pix_start2);
reg_set(encoder, REG_MAT_CONTRL, MAT_CONTRL_MAT_BP);
reg_write(encoder, REG_ANA_GENERAL, 0x09);
reg_clear(encoder, REG_TBG_CNTRL_0, TBG_CNTRL_0_SYNC_MTHD);
reg_write(encoder, REG_VIP_CNTRL_3, 0);
reg_set(encoder, REG_VIP_CNTRL_3, VIP_CNTRL_3_SYNC_HS);
if (mode->flags & DRM_MODE_FLAG_NVSYNC)
reg_set(encoder, REG_VIP_CNTRL_3, VIP_CNTRL_3_V_TGL);
if (mode->flags & DRM_MODE_FLAG_NHSYNC)
reg_set(encoder, REG_VIP_CNTRL_3, VIP_CNTRL_3_H_TGL);
reg_write(encoder, REG_VIDFORMAT, 0x00);
reg_write16(encoder, REG_NPIX_MSB, mode->hdisplay - 1);
reg_write16(encoder, REG_NLINE_MSB, mode->vdisplay - 1);
reg_write16(encoder, REG_VS_LINE_STRT_1_MSB, line_start);
reg_write16(encoder, REG_VS_LINE_END_1_MSB, line_end);
reg_write16(encoder, REG_VS_PIX_STRT_1_MSB, hs_start);
reg_write16(encoder, REG_VS_PIX_END_1_MSB, hs_start);
reg_write16(encoder, REG_HS_PIX_START_MSB, hs_start);
reg_write16(encoder, REG_HS_PIX_STOP_MSB, hs_end);
reg_write16(encoder, REG_VWIN_START_1_MSB, vwin_start);
reg_write16(encoder, REG_VWIN_END_1_MSB, vwin_end);
reg_write16(encoder, REG_DE_START_MSB, de_start);
reg_write16(encoder, REG_DE_STOP_MSB, de_end);
if (priv->rev == TDA19988) {
reg_write(encoder, REG_ENABLE_SPACE, 0x01);
}
reg_write16(encoder, REG_REFPIX_MSB, ref_pix);
reg_write16(encoder, REG_REFLINE_MSB, ref_line);
reg = TBG_CNTRL_1_VHX_EXT_DE |
TBG_CNTRL_1_VHX_EXT_HS |
TBG_CNTRL_1_VHX_EXT_VS |
TBG_CNTRL_1_DWIN_DIS |
TBG_CNTRL_1_VH_TGL_2;
if (mode->flags & (DRM_MODE_FLAG_NVSYNC | DRM_MODE_FLAG_NHSYNC))
reg |= TBG_CNTRL_1_VH_TGL_0;
reg_set(encoder, REG_TBG_CNTRL_1, reg);
reg_clear(encoder, REG_TBG_CNTRL_0, TBG_CNTRL_0_SYNC_ONCE);
}
static enum drm_connector_status
tda998x_encoder_detect(struct drm_encoder *encoder,
struct drm_connector *connector)
{
uint8_t val = cec_read(encoder, REG_CEC_RXSHPDLEV);
return (val & CEC_RXSHPDLEV_HPD) ? connector_status_connected :
connector_status_disconnected;
}
static int
read_edid_block(struct drm_encoder *encoder, uint8_t *buf, int blk)
{
uint8_t offset, segptr;
int ret, i;
reg_set(encoder, REG_INT_FLAGS_2, INT_FLAGS_2_EDID_BLK_RD);
offset = (blk & 1) ? 128 : 0;
segptr = blk / 2;
reg_write(encoder, REG_DDC_ADDR, 0xa0);
reg_write(encoder, REG_DDC_OFFS, offset);
reg_write(encoder, REG_DDC_SEGM_ADDR, 0x60);
reg_write(encoder, REG_DDC_SEGM, segptr);
reg_write(encoder, REG_EDID_CTRL, 0x1);
reg_write(encoder, REG_EDID_CTRL, 0x0);
for (i = 100; i > 0; i--) {
uint8_t val = reg_read(encoder, REG_INT_FLAGS_2);
if (val & INT_FLAGS_2_EDID_BLK_RD)
break;
msleep(1);
}
if (i == 0)
return -ETIMEDOUT;
ret = reg_read_range(encoder, REG_EDID_DATA_0, buf, EDID_LENGTH);
if (ret != EDID_LENGTH) {
dev_err(encoder->dev->dev, "failed to read edid block %d: %d",
blk, ret);
return ret;
}
reg_clear(encoder, REG_INT_FLAGS_2, INT_FLAGS_2_EDID_BLK_RD);
return 0;
}
static uint8_t *
do_get_edid(struct drm_encoder *encoder)
{
int j = 0, valid_extensions = 0;
uint8_t *block, *new;
bool print_bad_edid = drm_debug & DRM_UT_KMS;
if ((block = kmalloc(EDID_LENGTH, GFP_KERNEL)) == NULL)
return NULL;
if (read_edid_block(encoder, block, 0))
goto fail;
if (!drm_edid_block_valid(block, 0, print_bad_edid))
goto fail;
if (block[0x7e] == 0)
return block;
new = krealloc(block, (block[0x7e] + 1) * EDID_LENGTH, GFP_KERNEL);
if (!new)
goto fail;
block = new;
for (j = 1; j <= block[0x7e]; j++) {
uint8_t *ext_block = block + (valid_extensions + 1) * EDID_LENGTH;
if (read_edid_block(encoder, ext_block, j))
goto fail;
if (!drm_edid_block_valid(ext_block, j, print_bad_edid))
goto fail;
valid_extensions++;
}
if (valid_extensions != block[0x7e]) {
block[EDID_LENGTH-1] += block[0x7e] - valid_extensions;
block[0x7e] = valid_extensions;
new = krealloc(block, (valid_extensions + 1) * EDID_LENGTH, GFP_KERNEL);
if (!new)
goto fail;
block = new;
}
return block;
fail:
dev_warn(encoder->dev->dev, "failed to read EDID\n");
kfree(block);
return NULL;
}
static int
tda998x_encoder_get_modes(struct drm_encoder *encoder,
struct drm_connector *connector)
{
struct edid *edid = (struct edid *)do_get_edid(encoder);
int n = 0;
if (edid) {
drm_mode_connector_update_edid_property(connector, edid);
n = drm_add_edid_modes(connector, edid);
kfree(edid);
}
return n;
}
static int
tda998x_encoder_create_resources(struct drm_encoder *encoder,
struct drm_connector *connector)
{
DBG("");
return 0;
}
static int
tda998x_encoder_set_property(struct drm_encoder *encoder,
struct drm_connector *connector,
struct drm_property *property,
uint64_t val)
{
DBG("");
return 0;
}
static void
tda998x_encoder_destroy(struct drm_encoder *encoder)
{
struct tda998x_priv *priv = to_tda998x_priv(encoder);
drm_i2c_encoder_destroy(encoder);
kfree(priv);
}
static int
tda998x_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
return 0;
}
static int
tda998x_remove(struct i2c_client *client)
{
return 0;
}
static int
tda998x_encoder_init(struct i2c_client *client,
struct drm_device *dev,
struct drm_encoder_slave *encoder_slave)
{
struct drm_encoder *encoder = &encoder_slave->base;
struct tda998x_priv *priv;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->current_page = 0;
priv->cec = i2c_new_dummy(client->adapter, 0x34);
priv->dpms = DRM_MODE_DPMS_OFF;
encoder_slave->slave_priv = priv;
encoder_slave->slave_funcs = &tda998x_encoder_funcs;
cec_write(encoder, REG_CEC_ENAMODS,
CEC_ENAMODS_EN_RXSENS | CEC_ENAMODS_EN_HDMI);
tda998x_reset(encoder);
priv->rev = reg_read(encoder, REG_VERSION_LSB) |
reg_read(encoder, REG_VERSION_MSB) << 8;
priv->rev &= ~0x30;
switch (priv->rev) {
case TDA9989N2: dev_info(dev->dev, "found TDA9989 n2"); break;
case TDA19989: dev_info(dev->dev, "found TDA19989"); break;
case TDA19989N2: dev_info(dev->dev, "found TDA19989 n2"); break;
case TDA19988: dev_info(dev->dev, "found TDA19988"); break;
default:
DBG("found unsupported device: %04x", priv->rev);
goto fail;
}
reg_write(encoder, REG_DDC_DISABLE, 0x00);
reg_write(encoder, REG_TX3, 39);
if (priv->rev == TDA19989)
reg_set(encoder, REG_I2C_MASTER, I2C_MASTER_DIS_MM);
cec_write(encoder, REG_CEC_FRO_IM_CLK_CTRL,
CEC_FRO_IM_CLK_CTRL_GHOST_DIS | CEC_FRO_IM_CLK_CTRL_IMCLK_SEL);
return 0;
fail:
if (priv->cec)
i2c_unregister_device(priv->cec);
kfree(priv);
encoder_slave->slave_priv = NULL;
encoder_slave->slave_funcs = NULL;
return -ENXIO;
}
static int __init
tda998x_init(void)
{
DBG("");
return drm_i2c_encoder_register(THIS_MODULE, &tda998x_driver);
}
static void __exit
tda998x_exit(void)
{
DBG("");
drm_i2c_encoder_unregister(&tda998x_driver);
}
