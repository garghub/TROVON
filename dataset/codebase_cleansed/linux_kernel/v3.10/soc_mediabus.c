int soc_mbus_samples_per_pixel(const struct soc_mbus_pixelfmt *mf,
unsigned int *numerator, unsigned int *denominator)
{
switch (mf->packing) {
case SOC_MBUS_PACKING_NONE:
case SOC_MBUS_PACKING_EXTEND16:
*numerator = 1;
*denominator = 1;
return 0;
case SOC_MBUS_PACKING_EXTEND32:
*numerator = 1;
*denominator = 1;
return 0;
case SOC_MBUS_PACKING_2X8_PADHI:
case SOC_MBUS_PACKING_2X8_PADLO:
*numerator = 2;
*denominator = 1;
return 0;
case SOC_MBUS_PACKING_1_5X8:
*numerator = 3;
*denominator = 2;
return 0;
case SOC_MBUS_PACKING_VARIABLE:
*numerator = 0;
*denominator = 1;
return 0;
}
return -EINVAL;
}
s32 soc_mbus_bytes_per_line(u32 width, const struct soc_mbus_pixelfmt *mf)
{
if (mf->layout != SOC_MBUS_LAYOUT_PACKED)
return width * mf->bits_per_sample / 8;
switch (mf->packing) {
case SOC_MBUS_PACKING_NONE:
return width * mf->bits_per_sample / 8;
case SOC_MBUS_PACKING_2X8_PADHI:
case SOC_MBUS_PACKING_2X8_PADLO:
case SOC_MBUS_PACKING_EXTEND16:
return width * 2;
case SOC_MBUS_PACKING_1_5X8:
return width * 3 / 2;
case SOC_MBUS_PACKING_VARIABLE:
return 0;
case SOC_MBUS_PACKING_EXTEND32:
return width * 4;
}
return -EINVAL;
}
s32 soc_mbus_image_size(const struct soc_mbus_pixelfmt *mf,
u32 bytes_per_line, u32 height)
{
if (mf->layout == SOC_MBUS_LAYOUT_PACKED)
return bytes_per_line * height;
switch (mf->packing) {
case SOC_MBUS_PACKING_2X8_PADHI:
case SOC_MBUS_PACKING_2X8_PADLO:
return bytes_per_line * height * 2;
case SOC_MBUS_PACKING_1_5X8:
return bytes_per_line * height * 3 / 2;
default:
return -EINVAL;
}
}
const struct soc_mbus_pixelfmt *soc_mbus_find_fmtdesc(
enum v4l2_mbus_pixelcode code,
const struct soc_mbus_lookup *lookup,
int n)
{
int i;
for (i = 0; i < n; i++)
if (lookup[i].code == code)
return &lookup[i].fmt;
return NULL;
}
const struct soc_mbus_pixelfmt *soc_mbus_get_fmtdesc(
enum v4l2_mbus_pixelcode code)
{
return soc_mbus_find_fmtdesc(code, mbus_fmt, ARRAY_SIZE(mbus_fmt));
}
unsigned int soc_mbus_config_compatible(const struct v4l2_mbus_config *cfg,
unsigned int flags)
{
unsigned long common_flags;
bool hsync = true, vsync = true, pclk, data, mode;
bool mipi_lanes, mipi_clock;
common_flags = cfg->flags & flags;
switch (cfg->type) {
case V4L2_MBUS_PARALLEL:
hsync = common_flags & (V4L2_MBUS_HSYNC_ACTIVE_HIGH |
V4L2_MBUS_HSYNC_ACTIVE_LOW);
vsync = common_flags & (V4L2_MBUS_VSYNC_ACTIVE_HIGH |
V4L2_MBUS_VSYNC_ACTIVE_LOW);
case V4L2_MBUS_BT656:
pclk = common_flags & (V4L2_MBUS_PCLK_SAMPLE_RISING |
V4L2_MBUS_PCLK_SAMPLE_FALLING);
data = common_flags & (V4L2_MBUS_DATA_ACTIVE_HIGH |
V4L2_MBUS_DATA_ACTIVE_LOW);
mode = common_flags & (V4L2_MBUS_MASTER | V4L2_MBUS_SLAVE);
return (!hsync || !vsync || !pclk || !data || !mode) ?
0 : common_flags;
case V4L2_MBUS_CSI2:
mipi_lanes = common_flags & V4L2_MBUS_CSI2_LANES;
mipi_clock = common_flags & (V4L2_MBUS_CSI2_NONCONTINUOUS_CLOCK |
V4L2_MBUS_CSI2_CONTINUOUS_CLOCK);
return (!mipi_lanes || !mipi_clock) ? 0 : common_flags;
}
return 0;
}
static int __init soc_mbus_init(void)
{
return 0;
}
static void __exit soc_mbus_exit(void)
{
}
