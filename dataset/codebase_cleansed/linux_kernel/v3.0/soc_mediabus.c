int soc_mbus_samples_per_pixel(const struct soc_mbus_pixelfmt *mf,
unsigned int *numerator, unsigned int *denominator)
{
switch (mf->packing) {
case SOC_MBUS_PACKING_NONE:
case SOC_MBUS_PACKING_EXTEND16:
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
}
return -EINVAL;
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
static int __init soc_mbus_init(void)
{
return 0;
}
static void __exit soc_mbus_exit(void)
{
}
