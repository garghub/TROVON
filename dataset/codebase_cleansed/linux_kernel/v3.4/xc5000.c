static inline const struct xc5000_fw_cfg *xc5000_assign_firmware(int chip_id)
{
switch (chip_id) {
default:
case XC5000A:
return &xc5000a_1_6_114;
case XC5000C:
return &xc5000c_41_024_5;
}
}
static int xc_send_i2c_data(struct xc5000_priv *priv, u8 *buf, int len)
{
struct i2c_msg msg = { .addr = priv->i2c_props.addr,
.flags = 0, .buf = buf, .len = len };
if (i2c_transfer(priv->i2c_props.adap, &msg, 1) != 1) {
printk(KERN_ERR "xc5000: I2C write failed (len=%i)\n", len);
return XC_RESULT_I2C_WRITE_FAILURE;
}
return XC_RESULT_SUCCESS;
}
static int xc5000_readreg(struct xc5000_priv *priv, u16 reg, u16 *val)
{
u8 buf[2] = { reg >> 8, reg & 0xff };
u8 bval[2] = { 0, 0 };
struct i2c_msg msg[2] = {
{ .addr = priv->i2c_props.addr,
.flags = 0, .buf = &buf[0], .len = 2 },
{ .addr = priv->i2c_props.addr,
.flags = I2C_M_RD, .buf = &bval[0], .len = 2 },
};
if (i2c_transfer(priv->i2c_props.adap, msg, 2) != 2) {
printk(KERN_WARNING "xc5000: I2C read failed\n");
return -EREMOTEIO;
}
*val = (bval[0] << 8) | bval[1];
return XC_RESULT_SUCCESS;
}
static void xc_wait(int wait_ms)
{
msleep(wait_ms);
}
static int xc5000_TunerReset(struct dvb_frontend *fe)
{
struct xc5000_priv *priv = fe->tuner_priv;
int ret;
dprintk(1, "%s()\n", __func__);
if (fe->callback) {
ret = fe->callback(((fe->dvb) && (fe->dvb->priv)) ?
fe->dvb->priv :
priv->i2c_props.adap->algo_data,
DVB_FRONTEND_COMPONENT_TUNER,
XC5000_TUNER_RESET, 0);
if (ret) {
printk(KERN_ERR "xc5000: reset failed\n");
return XC_RESULT_RESET_FAILURE;
}
} else {
printk(KERN_ERR "xc5000: no tuner reset callback function, fatal\n");
return XC_RESULT_RESET_FAILURE;
}
return XC_RESULT_SUCCESS;
}
static int xc_write_reg(struct xc5000_priv *priv, u16 regAddr, u16 i2cData)
{
u8 buf[4];
int WatchDogTimer = 100;
int result;
buf[0] = (regAddr >> 8) & 0xFF;
buf[1] = regAddr & 0xFF;
buf[2] = (i2cData >> 8) & 0xFF;
buf[3] = i2cData & 0xFF;
result = xc_send_i2c_data(priv, buf, 4);
if (result == XC_RESULT_SUCCESS) {
while ((WatchDogTimer > 0) && (result == XC_RESULT_SUCCESS)) {
result = xc5000_readreg(priv, XREG_BUSY, (u16 *)buf);
if (result == XC_RESULT_SUCCESS) {
if ((buf[0] == 0) && (buf[1] == 0)) {
break;
} else {
xc_wait(5);
WatchDogTimer--;
}
}
}
}
if (WatchDogTimer < 0)
result = XC_RESULT_I2C_WRITE_FAILURE;
return result;
}
static int xc_load_i2c_sequence(struct dvb_frontend *fe, const u8 *i2c_sequence)
{
struct xc5000_priv *priv = fe->tuner_priv;
int i, nbytes_to_send, result;
unsigned int len, pos, index;
u8 buf[XC_MAX_I2C_WRITE_LENGTH];
index = 0;
while ((i2c_sequence[index] != 0xFF) ||
(i2c_sequence[index + 1] != 0xFF)) {
len = i2c_sequence[index] * 256 + i2c_sequence[index+1];
if (len == 0x0000) {
result = xc5000_TunerReset(fe);
index += 2;
if (result != XC_RESULT_SUCCESS)
return result;
} else if (len & 0x8000) {
xc_wait(len & 0x7FFF);
index += 2;
} else {
index += 2;
buf[0] = i2c_sequence[index];
buf[1] = i2c_sequence[index + 1];
pos = 2;
while (pos < len) {
if ((len - pos) > XC_MAX_I2C_WRITE_LENGTH - 2)
nbytes_to_send =
XC_MAX_I2C_WRITE_LENGTH;
else
nbytes_to_send = (len - pos + 2);
for (i = 2; i < nbytes_to_send; i++) {
buf[i] = i2c_sequence[index + pos +
i - 2];
}
result = xc_send_i2c_data(priv, buf,
nbytes_to_send);
if (result != XC_RESULT_SUCCESS)
return result;
pos += nbytes_to_send - 2;
}
index += len;
}
}
return XC_RESULT_SUCCESS;
}
static int xc_initialize(struct xc5000_priv *priv)
{
dprintk(1, "%s()\n", __func__);
return xc_write_reg(priv, XREG_INIT, 0);
}
static int xc_SetTVStandard(struct xc5000_priv *priv,
u16 VideoMode, u16 AudioMode)
{
int ret;
dprintk(1, "%s(0x%04x,0x%04x)\n", __func__, VideoMode, AudioMode);
dprintk(1, "%s() Standard = %s\n",
__func__,
XC5000_Standard[priv->video_standard].Name);
ret = xc_write_reg(priv, XREG_VIDEO_MODE, VideoMode);
if (ret == XC_RESULT_SUCCESS)
ret = xc_write_reg(priv, XREG_AUDIO_MODE, AudioMode);
return ret;
}
static int xc_SetSignalSource(struct xc5000_priv *priv, u16 rf_mode)
{
dprintk(1, "%s(%d) Source = %s\n", __func__, rf_mode,
rf_mode == XC_RF_MODE_AIR ? "ANTENNA" : "CABLE");
if ((rf_mode != XC_RF_MODE_AIR) && (rf_mode != XC_RF_MODE_CABLE)) {
rf_mode = XC_RF_MODE_CABLE;
printk(KERN_ERR
"%s(), Invalid mode, defaulting to CABLE",
__func__);
}
return xc_write_reg(priv, XREG_SIGNALSOURCE, rf_mode);
}
static int xc_set_RF_frequency(struct xc5000_priv *priv, u32 freq_hz)
{
u16 freq_code;
dprintk(1, "%s(%u)\n", __func__, freq_hz);
if ((freq_hz > xc5000_tuner_ops.info.frequency_max) ||
(freq_hz < xc5000_tuner_ops.info.frequency_min))
return XC_RESULT_OUT_OF_RANGE;
freq_code = (u16)(freq_hz / 15625);
return xc_write_reg(priv, XREG_FINERFREQ, freq_code);
}
static int xc_set_IF_frequency(struct xc5000_priv *priv, u32 freq_khz)
{
u32 freq_code = (freq_khz * 1024)/1000;
dprintk(1, "%s(freq_khz = %d) freq_code = 0x%x\n",
__func__, freq_khz, freq_code);
return xc_write_reg(priv, XREG_IF_OUT, freq_code);
}
static int xc_get_ADC_Envelope(struct xc5000_priv *priv, u16 *adc_envelope)
{
return xc5000_readreg(priv, XREG_ADC_ENV, adc_envelope);
}
static int xc_get_frequency_error(struct xc5000_priv *priv, u32 *freq_error_hz)
{
int result;
u16 regData;
u32 tmp;
result = xc5000_readreg(priv, XREG_FREQ_ERROR, &regData);
if (result != XC_RESULT_SUCCESS)
return result;
tmp = (u32)regData;
(*freq_error_hz) = (tmp * 15625) / 1000;
return result;
}
static int xc_get_lock_status(struct xc5000_priv *priv, u16 *lock_status)
{
return xc5000_readreg(priv, XREG_LOCK, lock_status);
}
static int xc_get_version(struct xc5000_priv *priv,
u8 *hw_majorversion, u8 *hw_minorversion,
u8 *fw_majorversion, u8 *fw_minorversion)
{
u16 data;
int result;
result = xc5000_readreg(priv, XREG_VERSION, &data);
if (result != XC_RESULT_SUCCESS)
return result;
(*hw_majorversion) = (data >> 12) & 0x0F;
(*hw_minorversion) = (data >> 8) & 0x0F;
(*fw_majorversion) = (data >> 4) & 0x0F;
(*fw_minorversion) = data & 0x0F;
return 0;
}
static int xc_get_buildversion(struct xc5000_priv *priv, u16 *buildrev)
{
return xc5000_readreg(priv, XREG_BUILD, buildrev);
}
static int xc_get_hsync_freq(struct xc5000_priv *priv, u32 *hsync_freq_hz)
{
u16 regData;
int result;
result = xc5000_readreg(priv, XREG_HSYNC_FREQ, &regData);
if (result != XC_RESULT_SUCCESS)
return result;
(*hsync_freq_hz) = ((regData & 0x0fff) * 763)/100;
return result;
}
static int xc_get_frame_lines(struct xc5000_priv *priv, u16 *frame_lines)
{
return xc5000_readreg(priv, XREG_FRAME_LINES, frame_lines);
}
static int xc_get_quality(struct xc5000_priv *priv, u16 *quality)
{
return xc5000_readreg(priv, XREG_QUALITY, quality);
}
static u16 WaitForLock(struct xc5000_priv *priv)
{
u16 lockState = 0;
int watchDogCount = 40;
while ((lockState == 0) && (watchDogCount > 0)) {
xc_get_lock_status(priv, &lockState);
if (lockState != 1) {
xc_wait(5);
watchDogCount--;
}
}
return lockState;
}
static int xc_tune_channel(struct xc5000_priv *priv, u32 freq_hz, int mode)
{
int found = 0;
dprintk(1, "%s(%u)\n", __func__, freq_hz);
if (xc_set_RF_frequency(priv, freq_hz) != XC_RESULT_SUCCESS)
return 0;
if (mode == XC_TUNE_ANALOG) {
if (WaitForLock(priv) == 1)
found = 1;
}
return found;
}
static int xc_set_xtal(struct dvb_frontend *fe)
{
struct xc5000_priv *priv = fe->tuner_priv;
int ret = XC_RESULT_SUCCESS;
switch (priv->chip_id) {
default:
case XC5000A:
break;
case XC5000C:
switch (priv->xtal_khz) {
default:
case 32000:
break;
case 31875:
ret = xc_write_reg(priv, 0x000f, 0x8081);
break;
}
break;
}
return ret;
}
static int xc5000_fwupload(struct dvb_frontend *fe)
{
struct xc5000_priv *priv = fe->tuner_priv;
const struct firmware *fw;
int ret;
const struct xc5000_fw_cfg *desired_fw =
xc5000_assign_firmware(priv->chip_id);
printk(KERN_INFO "xc5000: waiting for firmware upload (%s)...\n",
desired_fw->name);
ret = request_firmware(&fw, desired_fw->name,
priv->i2c_props.adap->dev.parent);
if (ret) {
printk(KERN_ERR "xc5000: Upload failed. (file not found?)\n");
ret = XC_RESULT_RESET_FAILURE;
goto out;
} else {
printk(KERN_DEBUG "xc5000: firmware read %Zu bytes.\n",
fw->size);
ret = XC_RESULT_SUCCESS;
}
if (fw->size != desired_fw->size) {
printk(KERN_ERR "xc5000: firmware incorrect size\n");
ret = XC_RESULT_RESET_FAILURE;
} else {
printk(KERN_INFO "xc5000: firmware uploading...\n");
ret = xc_load_i2c_sequence(fe, fw->data);
if (XC_RESULT_SUCCESS == ret)
ret = xc_set_xtal(fe);
printk(KERN_INFO "xc5000: firmware upload complete...\n");
}
out:
release_firmware(fw);
return ret;
}
static void xc_debug_dump(struct xc5000_priv *priv)
{
u16 adc_envelope;
u32 freq_error_hz = 0;
u16 lock_status;
u32 hsync_freq_hz = 0;
u16 frame_lines;
u16 quality;
u8 hw_majorversion = 0, hw_minorversion = 0;
u8 fw_majorversion = 0, fw_minorversion = 0;
u16 fw_buildversion = 0;
xc_wait(100);
xc_get_ADC_Envelope(priv, &adc_envelope);
dprintk(1, "*** ADC envelope (0-1023) = %d\n", adc_envelope);
xc_get_frequency_error(priv, &freq_error_hz);
dprintk(1, "*** Frequency error = %d Hz\n", freq_error_hz);
xc_get_lock_status(priv, &lock_status);
dprintk(1, "*** Lock status (0-Wait, 1-Locked, 2-No-signal) = %d\n",
lock_status);
xc_get_version(priv, &hw_majorversion, &hw_minorversion,
&fw_majorversion, &fw_minorversion);
xc_get_buildversion(priv, &fw_buildversion);
dprintk(1, "*** HW: V%02x.%02x, FW: V%02x.%02x.%04x\n",
hw_majorversion, hw_minorversion,
fw_majorversion, fw_minorversion, fw_buildversion);
xc_get_hsync_freq(priv, &hsync_freq_hz);
dprintk(1, "*** Horizontal sync frequency = %d Hz\n", hsync_freq_hz);
xc_get_frame_lines(priv, &frame_lines);
dprintk(1, "*** Frame lines = %d\n", frame_lines);
xc_get_quality(priv, &quality);
dprintk(1, "*** Quality (0:<8dB, 7:>56dB) = %d\n", quality);
}
static int xc5000_set_params(struct dvb_frontend *fe)
{
int ret, b;
struct xc5000_priv *priv = fe->tuner_priv;
u32 bw = fe->dtv_property_cache.bandwidth_hz;
u32 freq = fe->dtv_property_cache.frequency;
u32 delsys = fe->dtv_property_cache.delivery_system;
if (xc5000_is_firmware_loaded(fe) != XC_RESULT_SUCCESS) {
if (xc_load_fw_and_init_tuner(fe) != XC_RESULT_SUCCESS) {
dprintk(1, "Unable to load firmware and init tuner\n");
return -EINVAL;
}
}
dprintk(1, "%s() frequency=%d (Hz)\n", __func__, freq);
switch (delsys) {
case SYS_ATSC:
dprintk(1, "%s() VSB modulation\n", __func__);
priv->rf_mode = XC_RF_MODE_AIR;
priv->freq_hz = freq - 1750000;
priv->video_standard = DTV6;
break;
case SYS_DVBC_ANNEX_B:
dprintk(1, "%s() QAM modulation\n", __func__);
priv->rf_mode = XC_RF_MODE_CABLE;
priv->freq_hz = freq - 1750000;
priv->video_standard = DTV6;
break;
case SYS_DVBT:
case SYS_DVBT2:
dprintk(1, "%s() OFDM\n", __func__);
switch (bw) {
case 6000000:
priv->video_standard = DTV6;
priv->freq_hz = freq - 1750000;
break;
case 7000000:
priv->video_standard = DTV7;
priv->freq_hz = freq - 2250000;
break;
case 8000000:
priv->video_standard = DTV8;
priv->freq_hz = freq - 2750000;
break;
default:
printk(KERN_ERR "xc5000 bandwidth not set!\n");
return -EINVAL;
}
priv->rf_mode = XC_RF_MODE_AIR;
case SYS_DVBC_ANNEX_A:
case SYS_DVBC_ANNEX_C:
dprintk(1, "%s() QAM modulation\n", __func__);
priv->rf_mode = XC_RF_MODE_CABLE;
if (bw <= 6000000) {
priv->video_standard = DTV6;
priv->freq_hz = freq - 1750000;
b = 6;
} else if (bw <= 7000000) {
priv->video_standard = DTV7;
priv->freq_hz = freq - 2250000;
b = 7;
} else {
priv->video_standard = DTV7_8;
priv->freq_hz = freq - 2750000;
b = 8;
}
dprintk(1, "%s() Bandwidth %dMHz (%d)\n", __func__,
b, bw);
break;
default:
printk(KERN_ERR "xc5000: delivery system is not supported!\n");
return -EINVAL;
}
dprintk(1, "%s() frequency=%d (compensated to %d)\n",
__func__, freq, priv->freq_hz);
ret = xc_SetSignalSource(priv, priv->rf_mode);
if (ret != XC_RESULT_SUCCESS) {
printk(KERN_ERR
"xc5000: xc_SetSignalSource(%d) failed\n",
priv->rf_mode);
return -EREMOTEIO;
}
ret = xc_SetTVStandard(priv,
XC5000_Standard[priv->video_standard].VideoMode,
XC5000_Standard[priv->video_standard].AudioMode);
if (ret != XC_RESULT_SUCCESS) {
printk(KERN_ERR "xc5000: xc_SetTVStandard failed\n");
return -EREMOTEIO;
}
ret = xc_set_IF_frequency(priv, priv->if_khz);
if (ret != XC_RESULT_SUCCESS) {
printk(KERN_ERR "xc5000: xc_Set_IF_frequency(%d) failed\n",
priv->if_khz);
return -EIO;
}
xc_write_reg(priv, XREG_OUTPUT_AMP, 0x8a);
xc_tune_channel(priv, priv->freq_hz, XC_TUNE_DIGITAL);
if (debug)
xc_debug_dump(priv);
priv->bandwidth = bw;
return 0;
}
static int xc5000_is_firmware_loaded(struct dvb_frontend *fe)
{
struct xc5000_priv *priv = fe->tuner_priv;
int ret;
u16 id;
ret = xc5000_readreg(priv, XREG_PRODUCT_ID, &id);
if (ret == XC_RESULT_SUCCESS) {
if (id == XC_PRODUCT_ID_FW_NOT_LOADED)
ret = XC_RESULT_RESET_FAILURE;
else
ret = XC_RESULT_SUCCESS;
}
dprintk(1, "%s() returns %s id = 0x%x\n", __func__,
ret == XC_RESULT_SUCCESS ? "True" : "False", id);
return ret;
}
static int xc5000_set_tv_freq(struct dvb_frontend *fe,
struct analog_parameters *params)
{
struct xc5000_priv *priv = fe->tuner_priv;
int ret;
dprintk(1, "%s() frequency=%d (in units of 62.5khz)\n",
__func__, params->frequency);
priv->rf_mode = params->mode;
if (params->mode > XC_RF_MODE_CABLE)
priv->rf_mode = XC_RF_MODE_CABLE;
priv->freq_hz = params->frequency * 62500;
if (params->std & V4L2_STD_MN) {
priv->video_standard = MN_NTSC_PAL_BTSC;
goto tune_channel;
}
if (params->std & V4L2_STD_PAL_BG) {
priv->video_standard = BG_PAL_NICAM;
goto tune_channel;
}
if (params->std & V4L2_STD_PAL_I) {
priv->video_standard = I_PAL_NICAM;
goto tune_channel;
}
if (params->std & V4L2_STD_PAL_DK) {
priv->video_standard = DK_PAL_NICAM;
goto tune_channel;
}
if (params->std & V4L2_STD_SECAM_DK) {
priv->video_standard = DK_SECAM_A2DK1;
goto tune_channel;
}
if (params->std & V4L2_STD_SECAM_L) {
priv->video_standard = L_SECAM_NICAM;
goto tune_channel;
}
if (params->std & V4L2_STD_SECAM_LC) {
priv->video_standard = LC_SECAM_NICAM;
goto tune_channel;
}
tune_channel:
ret = xc_SetSignalSource(priv, priv->rf_mode);
if (ret != XC_RESULT_SUCCESS) {
printk(KERN_ERR
"xc5000: xc_SetSignalSource(%d) failed\n",
priv->rf_mode);
return -EREMOTEIO;
}
ret = xc_SetTVStandard(priv,
XC5000_Standard[priv->video_standard].VideoMode,
XC5000_Standard[priv->video_standard].AudioMode);
if (ret != XC_RESULT_SUCCESS) {
printk(KERN_ERR "xc5000: xc_SetTVStandard failed\n");
return -EREMOTEIO;
}
xc_write_reg(priv, XREG_OUTPUT_AMP, 0x09);
xc_tune_channel(priv, priv->freq_hz, XC_TUNE_ANALOG);
if (debug)
xc_debug_dump(priv);
return 0;
}
static int xc5000_set_radio_freq(struct dvb_frontend *fe,
struct analog_parameters *params)
{
struct xc5000_priv *priv = fe->tuner_priv;
int ret = -EINVAL;
u8 radio_input;
dprintk(1, "%s() frequency=%d (in units of khz)\n",
__func__, params->frequency);
if (priv->radio_input == XC5000_RADIO_NOT_CONFIGURED) {
dprintk(1, "%s() radio input not configured\n", __func__);
return -EINVAL;
}
if (priv->radio_input == XC5000_RADIO_FM1)
radio_input = FM_Radio_INPUT1;
else if (priv->radio_input == XC5000_RADIO_FM2)
radio_input = FM_Radio_INPUT2;
else if (priv->radio_input == XC5000_RADIO_FM1_MONO)
radio_input = FM_Radio_INPUT1_MONO;
else {
dprintk(1, "%s() unknown radio input %d\n", __func__,
priv->radio_input);
return -EINVAL;
}
priv->freq_hz = params->frequency * 125 / 2;
priv->rf_mode = XC_RF_MODE_AIR;
ret = xc_SetTVStandard(priv, XC5000_Standard[radio_input].VideoMode,
XC5000_Standard[radio_input].AudioMode);
if (ret != XC_RESULT_SUCCESS) {
printk(KERN_ERR "xc5000: xc_SetTVStandard failed\n");
return -EREMOTEIO;
}
ret = xc_SetSignalSource(priv, priv->rf_mode);
if (ret != XC_RESULT_SUCCESS) {
printk(KERN_ERR
"xc5000: xc_SetSignalSource(%d) failed\n",
priv->rf_mode);
return -EREMOTEIO;
}
if ((priv->radio_input == XC5000_RADIO_FM1) ||
(priv->radio_input == XC5000_RADIO_FM2))
xc_write_reg(priv, XREG_OUTPUT_AMP, 0x09);
else if (priv->radio_input == XC5000_RADIO_FM1_MONO)
xc_write_reg(priv, XREG_OUTPUT_AMP, 0x06);
xc_tune_channel(priv, priv->freq_hz, XC_TUNE_ANALOG);
return 0;
}
static int xc5000_set_analog_params(struct dvb_frontend *fe,
struct analog_parameters *params)
{
struct xc5000_priv *priv = fe->tuner_priv;
int ret = -EINVAL;
if (priv->i2c_props.adap == NULL)
return -EINVAL;
if (xc5000_is_firmware_loaded(fe) != XC_RESULT_SUCCESS) {
if (xc_load_fw_and_init_tuner(fe) != XC_RESULT_SUCCESS) {
dprintk(1, "Unable to load firmware and init tuner\n");
return -EINVAL;
}
}
switch (params->mode) {
case V4L2_TUNER_RADIO:
ret = xc5000_set_radio_freq(fe, params);
break;
case V4L2_TUNER_ANALOG_TV:
case V4L2_TUNER_DIGITAL_TV:
ret = xc5000_set_tv_freq(fe, params);
break;
}
return ret;
}
static int xc5000_get_frequency(struct dvb_frontend *fe, u32 *freq)
{
struct xc5000_priv *priv = fe->tuner_priv;
dprintk(1, "%s()\n", __func__);
*freq = priv->freq_hz;
return 0;
}
static int xc5000_get_if_frequency(struct dvb_frontend *fe, u32 *freq)
{
struct xc5000_priv *priv = fe->tuner_priv;
dprintk(1, "%s()\n", __func__);
*freq = priv->if_khz * 1000;
return 0;
}
static int xc5000_get_bandwidth(struct dvb_frontend *fe, u32 *bw)
{
struct xc5000_priv *priv = fe->tuner_priv;
dprintk(1, "%s()\n", __func__);
*bw = priv->bandwidth;
return 0;
}
static int xc5000_get_status(struct dvb_frontend *fe, u32 *status)
{
struct xc5000_priv *priv = fe->tuner_priv;
u16 lock_status = 0;
xc_get_lock_status(priv, &lock_status);
dprintk(1, "%s() lock_status = 0x%08x\n", __func__, lock_status);
*status = lock_status;
return 0;
}
static int xc_load_fw_and_init_tuner(struct dvb_frontend *fe)
{
struct xc5000_priv *priv = fe->tuner_priv;
int ret = 0;
if (xc5000_is_firmware_loaded(fe) != XC_RESULT_SUCCESS) {
ret = xc5000_fwupload(fe);
if (ret != XC_RESULT_SUCCESS)
return ret;
}
ret |= xc_initialize(priv);
xc_wait(100);
ret |= xc_write_reg(priv, XREG_SIGNALSOURCE, XC_RF_MODE_CABLE);
return ret;
}
static int xc5000_sleep(struct dvb_frontend *fe)
{
int ret;
dprintk(1, "%s()\n", __func__);
if (no_poweroff)
return 0;
ret = xc5000_TunerReset(fe);
if (ret != XC_RESULT_SUCCESS) {
printk(KERN_ERR
"xc5000: %s() unable to shutdown tuner\n",
__func__);
return -EREMOTEIO;
} else
return XC_RESULT_SUCCESS;
}
static int xc5000_init(struct dvb_frontend *fe)
{
struct xc5000_priv *priv = fe->tuner_priv;
dprintk(1, "%s()\n", __func__);
if (xc_load_fw_and_init_tuner(fe) != XC_RESULT_SUCCESS) {
printk(KERN_ERR "xc5000: Unable to initialise tuner\n");
return -EREMOTEIO;
}
if (debug)
xc_debug_dump(priv);
return 0;
}
static int xc5000_release(struct dvb_frontend *fe)
{
struct xc5000_priv *priv = fe->tuner_priv;
dprintk(1, "%s()\n", __func__);
mutex_lock(&xc5000_list_mutex);
if (priv)
hybrid_tuner_release_state(priv);
mutex_unlock(&xc5000_list_mutex);
fe->tuner_priv = NULL;
return 0;
}
static int xc5000_set_config(struct dvb_frontend *fe, void *priv_cfg)
{
struct xc5000_priv *priv = fe->tuner_priv;
struct xc5000_config *p = priv_cfg;
dprintk(1, "%s()\n", __func__);
if (p->if_khz)
priv->if_khz = p->if_khz;
if (p->radio_input)
priv->radio_input = p->radio_input;
return 0;
}
struct dvb_frontend *xc5000_attach(struct dvb_frontend *fe,
struct i2c_adapter *i2c,
const struct xc5000_config *cfg)
{
struct xc5000_priv *priv = NULL;
int instance;
u16 id = 0;
dprintk(1, "%s(%d-%04x)\n", __func__,
i2c ? i2c_adapter_id(i2c) : -1,
cfg ? cfg->i2c_address : -1);
mutex_lock(&xc5000_list_mutex);
instance = hybrid_tuner_request_state(struct xc5000_priv, priv,
hybrid_tuner_instance_list,
i2c, cfg->i2c_address, "xc5000");
switch (instance) {
case 0:
goto fail;
break;
case 1:
priv->bandwidth = 6000000;
fe->tuner_priv = priv;
break;
default:
fe->tuner_priv = priv;
break;
}
if (priv->if_khz == 0) {
priv->if_khz = cfg->if_khz;
}
if (priv->xtal_khz == 0)
priv->xtal_khz = cfg->xtal_khz;
if (priv->radio_input == 0)
priv->radio_input = cfg->radio_input;
if ((priv->chip_id == 0) || (cfg->chip_id))
priv->chip_id = (cfg->chip_id) ? cfg->chip_id : 0;
if (xc5000_readreg(priv, XREG_PRODUCT_ID, &id) != XC_RESULT_SUCCESS)
goto fail;
switch (id) {
case XC_PRODUCT_ID_FW_LOADED:
printk(KERN_INFO
"xc5000: Successfully identified at address 0x%02x\n",
cfg->i2c_address);
printk(KERN_INFO
"xc5000: Firmware has been loaded previously\n");
break;
case XC_PRODUCT_ID_FW_NOT_LOADED:
printk(KERN_INFO
"xc5000: Successfully identified at address 0x%02x\n",
cfg->i2c_address);
printk(KERN_INFO
"xc5000: Firmware has not been loaded previously\n");
break;
default:
printk(KERN_ERR
"xc5000: Device not found at addr 0x%02x (0x%x)\n",
cfg->i2c_address, id);
goto fail;
}
mutex_unlock(&xc5000_list_mutex);
memcpy(&fe->ops.tuner_ops, &xc5000_tuner_ops,
sizeof(struct dvb_tuner_ops));
return fe;
fail:
mutex_unlock(&xc5000_list_mutex);
xc5000_release(fe);
return NULL;
}
