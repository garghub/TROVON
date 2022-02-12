static inline struct msi001_dev *sd_to_msi001_dev(struct v4l2_subdev *sd)
{
return container_of(sd, struct msi001_dev, sd);
}
static int msi001_wreg(struct msi001_dev *dev, u32 data)
{
return spi_write(dev->spi, &data, 3);
}
static int msi001_set_gain(struct msi001_dev *dev, int lna_gain, int mixer_gain,
int if_gain)
{
struct spi_device *spi = dev->spi;
int ret;
u32 reg;
dev_dbg(&spi->dev, "lna=%d mixer=%d if=%d\n",
lna_gain, mixer_gain, if_gain);
reg = 1 << 0;
reg |= (59 - if_gain) << 4;
reg |= 0 << 10;
reg |= (1 - mixer_gain) << 12;
reg |= (1 - lna_gain) << 13;
reg |= 4 << 14;
reg |= 0 << 17;
ret = msi001_wreg(dev, reg);
if (ret)
goto err;
return 0;
err:
dev_dbg(&spi->dev, "failed %d\n", ret);
return ret;
}
static int msi001_set_tuner(struct msi001_dev *dev)
{
struct spi_device *spi = dev->spi;
int ret, i;
unsigned int uitmp, div_n, k, k_thresh, k_frac, div_lo, f_if1;
u32 reg;
u64 f_vco;
u8 mode, filter_mode;
static const struct {
u32 rf;
u8 mode;
u8 div_lo;
} band_lut[] = {
{ 50000000, 0xe1, 16},
{108000000, 0x42, 32},
{330000000, 0x44, 16},
{960000000, 0x48, 4},
{ ~0U, 0x50, 2},
};
static const struct {
u32 freq;
u8 filter_mode;
} if_freq_lut[] = {
{ 0, 0x03},
{ 450000, 0x02},
{1620000, 0x01},
{2048000, 0x00},
};
static const struct {
u32 freq;
u8 val;
} bandwidth_lut[] = {
{ 200000, 0x00},
{ 300000, 0x01},
{ 600000, 0x02},
{1536000, 0x03},
{5000000, 0x04},
{6000000, 0x05},
{7000000, 0x06},
{8000000, 0x07},
};
unsigned int f_rf = dev->f_tuner;
unsigned int bandwidth;
unsigned int f_if = 0;
#define F_REF 24000000
#define DIV_PRE_N 4
#define F_VCO_STEP div_lo
dev_dbg(&spi->dev, "f_rf=%d f_if=%d\n", f_rf, f_if);
for (i = 0; i < ARRAY_SIZE(band_lut); i++) {
if (f_rf <= band_lut[i].rf) {
mode = band_lut[i].mode;
div_lo = band_lut[i].div_lo;
break;
}
}
if (i == ARRAY_SIZE(band_lut)) {
ret = -EINVAL;
goto err;
}
if ((mode >> 0) & 0x1)
f_if1 = 5 * F_REF;
else
f_if1 = 0;
for (i = 0; i < ARRAY_SIZE(if_freq_lut); i++) {
if (f_if == if_freq_lut[i].freq) {
filter_mode = if_freq_lut[i].filter_mode;
break;
}
}
if (i == ARRAY_SIZE(if_freq_lut)) {
ret = -EINVAL;
goto err;
}
bandwidth = dev->bandwidth->val;
bandwidth = clamp(bandwidth, 200000U, 8000000U);
for (i = 0; i < ARRAY_SIZE(bandwidth_lut); i++) {
if (bandwidth <= bandwidth_lut[i].freq) {
bandwidth = bandwidth_lut[i].val;
break;
}
}
if (i == ARRAY_SIZE(bandwidth_lut)) {
ret = -EINVAL;
goto err;
}
dev->bandwidth->val = bandwidth_lut[i].freq;
dev_dbg(&spi->dev, "bandwidth selected=%d\n", bandwidth_lut[i].freq);
f_vco = (u64) (f_rf + f_if + f_if1) * div_lo;
div_n = div_u64_rem(f_vco, DIV_PRE_N * F_REF, &k);
k_thresh = (DIV_PRE_N * F_REF) / F_VCO_STEP;
k_frac = div_u64((u64) k * k_thresh, (DIV_PRE_N * F_REF));
uitmp = gcd(k_thresh, k_frac);
k_thresh /= uitmp;
k_frac /= uitmp;
uitmp = DIV_ROUND_UP(k_thresh, 4095);
k_thresh = DIV_ROUND_CLOSEST(k_thresh, uitmp);
k_frac = DIV_ROUND_CLOSEST(k_frac, uitmp);
uitmp = (unsigned int) F_REF * DIV_PRE_N * div_n;
uitmp += (unsigned int) F_REF * DIV_PRE_N * k_frac / k_thresh;
uitmp /= div_lo;
dev_dbg(&spi->dev,
"f_rf=%u:%u f_vco=%llu div_n=%u k_thresh=%u k_frac=%u div_lo=%u\n",
f_rf, uitmp, f_vco, div_n, k_thresh, k_frac, div_lo);
ret = msi001_wreg(dev, 0x00000e);
if (ret)
goto err;
ret = msi001_wreg(dev, 0x000003);
if (ret)
goto err;
reg = 0 << 0;
reg |= mode << 4;
reg |= filter_mode << 12;
reg |= bandwidth << 14;
reg |= 0x02 << 17;
reg |= 0x00 << 20;
ret = msi001_wreg(dev, reg);
if (ret)
goto err;
reg = 5 << 0;
reg |= k_thresh << 4;
reg |= 1 << 19;
reg |= 1 << 21;
ret = msi001_wreg(dev, reg);
if (ret)
goto err;
reg = 2 << 0;
reg |= k_frac << 4;
reg |= div_n << 16;
ret = msi001_wreg(dev, reg);
if (ret)
goto err;
ret = msi001_set_gain(dev, dev->lna_gain->cur.val,
dev->mixer_gain->cur.val, dev->if_gain->cur.val);
if (ret)
goto err;
reg = 6 << 0;
reg |= 63 << 4;
reg |= 4095 << 10;
ret = msi001_wreg(dev, reg);
if (ret)
goto err;
return 0;
err:
dev_dbg(&spi->dev, "failed %d\n", ret);
return ret;
}
static int msi001_s_power(struct v4l2_subdev *sd, int on)
{
struct msi001_dev *dev = sd_to_msi001_dev(sd);
struct spi_device *spi = dev->spi;
int ret;
dev_dbg(&spi->dev, "on=%d\n", on);
if (on)
ret = 0;
else
ret = msi001_wreg(dev, 0x000000);
return ret;
}
static int msi001_g_tuner(struct v4l2_subdev *sd, struct v4l2_tuner *v)
{
struct msi001_dev *dev = sd_to_msi001_dev(sd);
struct spi_device *spi = dev->spi;
dev_dbg(&spi->dev, "index=%d\n", v->index);
strlcpy(v->name, "Mirics MSi001", sizeof(v->name));
v->type = V4L2_TUNER_RF;
v->capability = V4L2_TUNER_CAP_1HZ | V4L2_TUNER_CAP_FREQ_BANDS;
v->rangelow = 49000000;
v->rangehigh = 960000000;
return 0;
}
static int msi001_s_tuner(struct v4l2_subdev *sd, const struct v4l2_tuner *v)
{
struct msi001_dev *dev = sd_to_msi001_dev(sd);
struct spi_device *spi = dev->spi;
dev_dbg(&spi->dev, "index=%d\n", v->index);
return 0;
}
static int msi001_g_frequency(struct v4l2_subdev *sd, struct v4l2_frequency *f)
{
struct msi001_dev *dev = sd_to_msi001_dev(sd);
struct spi_device *spi = dev->spi;
dev_dbg(&spi->dev, "tuner=%d\n", f->tuner);
f->frequency = dev->f_tuner;
return 0;
}
static int msi001_s_frequency(struct v4l2_subdev *sd,
const struct v4l2_frequency *f)
{
struct msi001_dev *dev = sd_to_msi001_dev(sd);
struct spi_device *spi = dev->spi;
unsigned int band;
dev_dbg(&spi->dev, "tuner=%d type=%d frequency=%u\n",
f->tuner, f->type, f->frequency);
if (f->frequency < ((bands[0].rangehigh + bands[1].rangelow) / 2))
band = 0;
else
band = 1;
dev->f_tuner = clamp_t(unsigned int, f->frequency,
bands[band].rangelow, bands[band].rangehigh);
return msi001_set_tuner(dev);
}
static int msi001_enum_freq_bands(struct v4l2_subdev *sd,
struct v4l2_frequency_band *band)
{
struct msi001_dev *dev = sd_to_msi001_dev(sd);
struct spi_device *spi = dev->spi;
dev_dbg(&spi->dev, "tuner=%d type=%d index=%d\n",
band->tuner, band->type, band->index);
if (band->index >= ARRAY_SIZE(bands))
return -EINVAL;
band->capability = bands[band->index].capability;
band->rangelow = bands[band->index].rangelow;
band->rangehigh = bands[band->index].rangehigh;
return 0;
}
static int msi001_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct msi001_dev *dev = container_of(ctrl->handler, struct msi001_dev, hdl);
struct spi_device *spi = dev->spi;
int ret;
dev_dbg(&spi->dev, "id=%d name=%s val=%d min=%lld max=%lld step=%lld\n",
ctrl->id, ctrl->name, ctrl->val, ctrl->minimum, ctrl->maximum,
ctrl->step);
switch (ctrl->id) {
case V4L2_CID_RF_TUNER_BANDWIDTH_AUTO:
case V4L2_CID_RF_TUNER_BANDWIDTH:
ret = msi001_set_tuner(dev);
break;
case V4L2_CID_RF_TUNER_LNA_GAIN:
ret = msi001_set_gain(dev, dev->lna_gain->val,
dev->mixer_gain->cur.val,
dev->if_gain->cur.val);
break;
case V4L2_CID_RF_TUNER_MIXER_GAIN:
ret = msi001_set_gain(dev, dev->lna_gain->cur.val,
dev->mixer_gain->val,
dev->if_gain->cur.val);
break;
case V4L2_CID_RF_TUNER_IF_GAIN:
ret = msi001_set_gain(dev, dev->lna_gain->cur.val,
dev->mixer_gain->cur.val,
dev->if_gain->val);
break;
default:
dev_dbg(&spi->dev, "unknown control %d\n", ctrl->id);
ret = -EINVAL;
}
return ret;
}
static int msi001_probe(struct spi_device *spi)
{
struct msi001_dev *dev;
int ret;
dev_dbg(&spi->dev, "\n");
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev) {
ret = -ENOMEM;
goto err;
}
dev->spi = spi;
dev->f_tuner = bands[0].rangelow;
v4l2_spi_subdev_init(&dev->sd, spi, &msi001_ops);
v4l2_ctrl_handler_init(&dev->hdl, 5);
dev->bandwidth_auto = v4l2_ctrl_new_std(&dev->hdl, &msi001_ctrl_ops,
V4L2_CID_RF_TUNER_BANDWIDTH_AUTO, 0, 1, 1, 1);
dev->bandwidth = v4l2_ctrl_new_std(&dev->hdl, &msi001_ctrl_ops,
V4L2_CID_RF_TUNER_BANDWIDTH, 200000, 8000000, 1, 200000);
v4l2_ctrl_auto_cluster(2, &dev->bandwidth_auto, 0, false);
dev->lna_gain = v4l2_ctrl_new_std(&dev->hdl, &msi001_ctrl_ops,
V4L2_CID_RF_TUNER_LNA_GAIN, 0, 1, 1, 1);
dev->mixer_gain = v4l2_ctrl_new_std(&dev->hdl, &msi001_ctrl_ops,
V4L2_CID_RF_TUNER_MIXER_GAIN, 0, 1, 1, 1);
dev->if_gain = v4l2_ctrl_new_std(&dev->hdl, &msi001_ctrl_ops,
V4L2_CID_RF_TUNER_IF_GAIN, 0, 59, 1, 0);
if (dev->hdl.error) {
ret = dev->hdl.error;
dev_err(&spi->dev, "Could not initialize controls\n");
goto err_ctrl_handler_free;
}
dev->sd.ctrl_handler = &dev->hdl;
return 0;
err_ctrl_handler_free:
v4l2_ctrl_handler_free(&dev->hdl);
kfree(dev);
err:
return ret;
}
static int msi001_remove(struct spi_device *spi)
{
struct v4l2_subdev *sd = spi_get_drvdata(spi);
struct msi001_dev *dev = sd_to_msi001_dev(sd);
dev_dbg(&spi->dev, "\n");
v4l2_device_unregister_subdev(&dev->sd);
v4l2_ctrl_handler_free(&dev->hdl);
kfree(dev);
return 0;
}
