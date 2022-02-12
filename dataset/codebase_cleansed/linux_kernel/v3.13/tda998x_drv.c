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
static void
reg_write_range(struct drm_encoder *encoder, uint16_t reg, uint8_t *p, int cnt)
{
struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
uint8_t buf[cnt+1];
int ret;
buf[0] = REG2ADDR(reg);
memcpy(&buf[1], p, cnt);
set_page(encoder, reg);
ret = i2c_master_send(client, buf, cnt + 1);
if (ret < 0)
dev_err(&client->dev, "Error %d writing to 0x%x\n", ret, reg);
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
reg_write(encoder, REG_AUDIO_DIV, AUDIO_DIV_SERCLK_8);
reg_write(encoder, REG_SEL_CLK, SEL_CLK_SEL_CLK1 | SEL_CLK_ENA_SC_CLK);
reg_write(encoder, REG_PLL_SCGN1, 0xfa);
reg_write(encoder, REG_PLL_SCGN2, 0x00);
reg_write(encoder, REG_PLL_SCGR1, 0x5b);
reg_write(encoder, REG_PLL_SCGR2, 0x00);
reg_write(encoder, REG_PLL_SCG2, 0x10);
reg_write(encoder, REG_MUX_VP_VIP_OUT, 0x24);
}
static uint8_t tda998x_cksum(uint8_t *buf, size_t bytes)
{
uint8_t sum = 0;
while (bytes--)
sum += *buf++;
return (255 - sum) + 1;
}
static void
tda998x_write_if(struct drm_encoder *encoder, uint8_t bit, uint16_t addr,
uint8_t *buf, size_t size)
{
buf[PB(0)] = tda998x_cksum(buf, size);
reg_clear(encoder, REG_DIP_IF_FLAGS, bit);
reg_write_range(encoder, addr, buf, size);
reg_set(encoder, REG_DIP_IF_FLAGS, bit);
}
static void
tda998x_write_aif(struct drm_encoder *encoder, struct tda998x_encoder_params *p)
{
uint8_t buf[PB(5) + 1];
buf[HB(0)] = 0x84;
buf[HB(1)] = 0x01;
buf[HB(2)] = 10;
buf[PB(0)] = 0;
buf[PB(1)] = p->audio_frame[1] & 0x07;
buf[PB(2)] = p->audio_frame[2] & 0x1c;
buf[PB(4)] = p->audio_frame[4];
buf[PB(5)] = p->audio_frame[5] & 0xf8;
tda998x_write_if(encoder, DIP_IF_FLAGS_IF4, REG_IF4_HB0, buf,
sizeof(buf));
}
static void
tda998x_write_avi(struct drm_encoder *encoder, struct drm_display_mode *mode)
{
uint8_t buf[PB(13) + 1];
memset(buf, 0, sizeof(buf));
buf[HB(0)] = 0x82;
buf[HB(1)] = 0x02;
buf[HB(2)] = 13;
buf[PB(1)] = HDMI_SCAN_MODE_UNDERSCAN;
buf[PB(3)] = HDMI_QUANTIZATION_RANGE_FULL << 2;
buf[PB(4)] = drm_match_cea_mode(mode);
tda998x_write_if(encoder, DIP_IF_FLAGS_IF2, REG_IF2_HB0, buf,
sizeof(buf));
}
static void tda998x_audio_mute(struct drm_encoder *encoder, bool on)
{
if (on) {
reg_set(encoder, REG_SOFTRESET, SOFTRESET_AUDIO);
reg_clear(encoder, REG_SOFTRESET, SOFTRESET_AUDIO);
reg_set(encoder, REG_AIP_CNTRL_0, AIP_CNTRL_0_RST_FIFO);
} else {
reg_clear(encoder, REG_AIP_CNTRL_0, AIP_CNTRL_0_RST_FIFO);
}
}
static void
tda998x_configure_audio(struct drm_encoder *encoder,
struct drm_display_mode *mode, struct tda998x_encoder_params *p)
{
uint8_t buf[6], clksel_aip, clksel_fs, ca_i2s, cts_n, adiv;
uint32_t n;
reg_write(encoder, REG_ENA_AP, p->audio_cfg);
reg_write(encoder, REG_ENA_ACLK, p->audio_clk_cfg);
switch (p->audio_format) {
case AFMT_SPDIF:
reg_write(encoder, REG_MUX_AP, 0x40);
clksel_aip = AIP_CLKSEL_AIP(0);
clksel_fs = AIP_CLKSEL_FS(2);
cts_n = CTS_N_M(3) | CTS_N_K(3);
ca_i2s = 0;
break;
case AFMT_I2S:
reg_write(encoder, REG_MUX_AP, 0x64);
clksel_aip = AIP_CLKSEL_AIP(1);
clksel_fs = AIP_CLKSEL_FS(0);
cts_n = CTS_N_M(3) | CTS_N_K(3);
ca_i2s = CA_I2S_CA_I2S(0);
break;
default:
BUG();
return;
}
reg_write(encoder, REG_AIP_CLKSEL, clksel_aip);
reg_clear(encoder, REG_AIP_CNTRL_0, AIP_CNTRL_0_LAYOUT);
reg_clear(encoder, REG_AIP_CNTRL_0, AIP_CNTRL_0_ACR_MAN);
reg_write(encoder, REG_CTS_N, cts_n);
if (mode->clock > 100000)
adiv = AUDIO_DIV_SERCLK_16;
else
adiv = AUDIO_DIV_SERCLK_8;
reg_write(encoder, REG_AUDIO_DIV, adiv);
n = 128 * p->audio_sample_rate / 1000;
buf[0] = 0x44;
buf[1] = 0x42;
buf[2] = 0x01;
buf[3] = n;
buf[4] = n >> 8;
buf[5] = n >> 16;
reg_write_range(encoder, REG_ACR_CTS_0, buf, 6);
reg_write(encoder, REG_AIP_CLKSEL, clksel_aip | clksel_fs);
reg_set(encoder, REG_AIP_CNTRL_0, AIP_CNTRL_0_RST_CTS);
reg_clear(encoder, REG_AIP_CNTRL_0, AIP_CNTRL_0_RST_CTS);
buf[0] = 0x04;
buf[1] = 0x00;
buf[2] = 0x00;
buf[3] = 0xf1;
reg_write_range(encoder, REG_CH_STAT_B(0), buf, 4);
tda998x_audio_mute(encoder, true);
mdelay(20);
tda998x_audio_mute(encoder, false);
tda998x_write_aif(encoder, p);
}
static void
tda998x_encoder_set_config(struct drm_encoder *encoder, void *params)
{
struct tda998x_priv *priv = to_tda998x_priv(encoder);
struct tda998x_encoder_params *p = params;
priv->vip_cntrl_0 = VIP_CNTRL_0_SWAP_A(p->swap_a) |
(p->mirr_a ? VIP_CNTRL_0_MIRR_A : 0) |
VIP_CNTRL_0_SWAP_B(p->swap_b) |
(p->mirr_b ? VIP_CNTRL_0_MIRR_B : 0);
priv->vip_cntrl_1 = VIP_CNTRL_1_SWAP_C(p->swap_c) |
(p->mirr_c ? VIP_CNTRL_1_MIRR_C : 0) |
VIP_CNTRL_1_SWAP_D(p->swap_d) |
(p->mirr_d ? VIP_CNTRL_1_MIRR_D : 0);
priv->vip_cntrl_2 = VIP_CNTRL_2_SWAP_E(p->swap_e) |
(p->mirr_e ? VIP_CNTRL_2_MIRR_E : 0) |
VIP_CNTRL_2_SWAP_F(p->swap_f) |
(p->mirr_f ? VIP_CNTRL_2_MIRR_F : 0);
priv->params = *p;
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
reg_write(encoder, REG_ENA_VP_0, 0xff);
reg_write(encoder, REG_ENA_VP_1, 0xff);
reg_write(encoder, REG_ENA_VP_2, 0xff);
reg_write(encoder, REG_VIP_CNTRL_0, priv->vip_cntrl_0);
reg_write(encoder, REG_VIP_CNTRL_1, priv->vip_cntrl_1);
reg_write(encoder, REG_VIP_CNTRL_2, priv->vip_cntrl_2);
break;
case DRM_MODE_DPMS_OFF:
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
uint16_t ref_pix, ref_line, n_pix, n_line;
uint16_t hs_pix_s, hs_pix_e;
uint16_t vs1_pix_s, vs1_pix_e, vs1_line_s, vs1_line_e;
uint16_t vs2_pix_s, vs2_pix_e, vs2_line_s, vs2_line_e;
uint16_t vwin1_line_s, vwin1_line_e;
uint16_t vwin2_line_s, vwin2_line_e;
uint16_t de_pix_s, de_pix_e;
uint8_t reg, div, rep;
n_pix = mode->htotal;
n_line = mode->vtotal;
hs_pix_e = mode->hsync_end - mode->hdisplay;
hs_pix_s = mode->hsync_start - mode->hdisplay;
de_pix_e = mode->htotal;
de_pix_s = mode->htotal - mode->hdisplay;
ref_pix = 3 + hs_pix_s;
if (adjusted_mode->flags & DRM_MODE_FLAG_HSKEW)
ref_pix += adjusted_mode->hskew;
if ((mode->flags & DRM_MODE_FLAG_INTERLACE) == 0) {
ref_line = 1 + mode->vsync_start - mode->vdisplay;
vwin1_line_s = mode->vtotal - mode->vdisplay - 1;
vwin1_line_e = vwin1_line_s + mode->vdisplay;
vs1_pix_s = vs1_pix_e = hs_pix_s;
vs1_line_s = mode->vsync_start - mode->vdisplay;
vs1_line_e = vs1_line_s +
mode->vsync_end - mode->vsync_start;
vwin2_line_s = vwin2_line_e = 0;
vs2_pix_s = vs2_pix_e = 0;
vs2_line_s = vs2_line_e = 0;
} else {
ref_line = 1 + (mode->vsync_start - mode->vdisplay)/2;
vwin1_line_s = (mode->vtotal - mode->vdisplay)/2;
vwin1_line_e = vwin1_line_s + mode->vdisplay/2;
vs1_pix_s = vs1_pix_e = hs_pix_s;
vs1_line_s = (mode->vsync_start - mode->vdisplay)/2;
vs1_line_e = vs1_line_s +
(mode->vsync_end - mode->vsync_start)/2;
vwin2_line_s = vwin1_line_s + mode->vtotal/2;
vwin2_line_e = vwin2_line_s + mode->vdisplay/2;
vs2_pix_s = vs2_pix_e = hs_pix_s + mode->htotal/2;
vs2_line_s = vs1_line_s + mode->vtotal/2 ;
vs2_line_e = vs2_line_s +
(mode->vsync_end - mode->vsync_start)/2;
}
div = 148500 / mode->clock;
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
reg_set(encoder, REG_MAT_CONTRL, MAT_CONTRL_MAT_BP);
reg_write(encoder, REG_ANA_GENERAL, 0x09);
reg_clear(encoder, REG_TBG_CNTRL_0, TBG_CNTRL_0_SYNC_MTHD);
reg_write(encoder, REG_VIP_CNTRL_3, 0);
reg_set(encoder, REG_VIP_CNTRL_3, VIP_CNTRL_3_SYNC_HS);
if (mode->flags & DRM_MODE_FLAG_NHSYNC)
reg_set(encoder, REG_VIP_CNTRL_3, VIP_CNTRL_3_H_TGL);
if (mode->flags & DRM_MODE_FLAG_NVSYNC)
reg_set(encoder, REG_VIP_CNTRL_3, VIP_CNTRL_3_V_TGL);
reg = TBG_CNTRL_1_TGL_EN;
if (mode->flags & DRM_MODE_FLAG_NHSYNC)
reg |= TBG_CNTRL_1_H_TGL;
if (mode->flags & DRM_MODE_FLAG_NVSYNC)
reg |= TBG_CNTRL_1_V_TGL;
reg_write(encoder, REG_TBG_CNTRL_1, reg);
reg_write(encoder, REG_VIDFORMAT, 0x00);
reg_write16(encoder, REG_REFPIX_MSB, ref_pix);
reg_write16(encoder, REG_REFLINE_MSB, ref_line);
reg_write16(encoder, REG_NPIX_MSB, n_pix);
reg_write16(encoder, REG_NLINE_MSB, n_line);
reg_write16(encoder, REG_VS_LINE_STRT_1_MSB, vs1_line_s);
reg_write16(encoder, REG_VS_PIX_STRT_1_MSB, vs1_pix_s);
reg_write16(encoder, REG_VS_LINE_END_1_MSB, vs1_line_e);
reg_write16(encoder, REG_VS_PIX_END_1_MSB, vs1_pix_e);
reg_write16(encoder, REG_VS_LINE_STRT_2_MSB, vs2_line_s);
reg_write16(encoder, REG_VS_PIX_STRT_2_MSB, vs2_pix_s);
reg_write16(encoder, REG_VS_LINE_END_2_MSB, vs2_line_e);
reg_write16(encoder, REG_VS_PIX_END_2_MSB, vs2_pix_e);
reg_write16(encoder, REG_HS_PIX_START_MSB, hs_pix_s);
reg_write16(encoder, REG_HS_PIX_STOP_MSB, hs_pix_e);
reg_write16(encoder, REG_VWIN_START_1_MSB, vwin1_line_s);
reg_write16(encoder, REG_VWIN_END_1_MSB, vwin1_line_e);
reg_write16(encoder, REG_VWIN_START_2_MSB, vwin2_line_s);
reg_write16(encoder, REG_VWIN_END_2_MSB, vwin2_line_e);
reg_write16(encoder, REG_DE_START_MSB, de_pix_s);
reg_write16(encoder, REG_DE_STOP_MSB, de_pix_e);
if (priv->rev == TDA19988) {
reg_write(encoder, REG_ENABLE_SPACE, 0x01);
}
reg_clear(encoder, REG_TBG_CNTRL_0, TBG_CNTRL_0_SYNC_ONCE);
if (priv->is_hdmi_sink) {
reg_clear(encoder, REG_TBG_CNTRL_1, TBG_CNTRL_1_DWIN_DIS);
reg_write(encoder, REG_ENC_CNTRL, ENC_CNTRL_CTL_CODE(1));
reg_set(encoder, REG_TX33, TX33_HDMI);
tda998x_write_avi(encoder, adjusted_mode);
if (priv->params.audio_cfg)
tda998x_configure_audio(encoder, adjusted_mode,
&priv->params);
}
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
struct tda998x_priv *priv = to_tda998x_priv(encoder);
int j = 0, valid_extensions = 0;
uint8_t *block, *new;
bool print_bad_edid = drm_debug & DRM_UT_KMS;
if ((block = kmalloc(EDID_LENGTH, GFP_KERNEL)) == NULL)
return NULL;
if (priv->rev == TDA19988)
reg_clear(encoder, REG_TX4, TX4_PD_RAM);
if (read_edid_block(encoder, block, 0))
goto fail;
if (!drm_edid_block_valid(block, 0, print_bad_edid))
goto fail;
if (block[0x7e] == 0)
goto done;
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
done:
if (priv->rev == TDA19988)
reg_set(encoder, REG_TX4, TX4_PD_RAM);
return block;
fail:
if (priv->rev == TDA19988)
reg_set(encoder, REG_TX4, TX4_PD_RAM);
dev_warn(encoder->dev->dev, "failed to read EDID\n");
kfree(block);
return NULL;
}
static int
tda998x_encoder_get_modes(struct drm_encoder *encoder,
struct drm_connector *connector)
{
struct tda998x_priv *priv = to_tda998x_priv(encoder);
struct edid *edid = (struct edid *)do_get_edid(encoder);
int n = 0;
if (edid) {
drm_mode_connector_update_edid_property(connector, edid);
n = drm_add_edid_modes(connector, edid);
priv->is_hdmi_sink = drm_detect_hdmi_monitor(edid);
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
priv->vip_cntrl_0 = VIP_CNTRL_0_SWAP_A(2) | VIP_CNTRL_0_SWAP_B(3);
priv->vip_cntrl_1 = VIP_CNTRL_1_SWAP_C(0) | VIP_CNTRL_1_SWAP_D(1);
priv->vip_cntrl_2 = VIP_CNTRL_2_SWAP_E(4) | VIP_CNTRL_2_SWAP_F(5);
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
