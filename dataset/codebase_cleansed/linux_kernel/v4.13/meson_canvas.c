void meson_canvas_setup(struct meson_drm *priv,
uint32_t canvas_index, uint32_t addr,
uint32_t stride, uint32_t height,
unsigned int wrap,
unsigned int blkmode)
{
unsigned int val;
regmap_write(priv->dmc, DMC_CAV_LUT_DATAL,
(((addr + 7) >> 3)) |
(((stride + 7) >> 3) << CANVAS_WIDTH_LBIT));
regmap_write(priv->dmc, DMC_CAV_LUT_DATAH,
((((stride + 7) >> 3) >> CANVAS_WIDTH_LWID) <<
CANVAS_WIDTH_HBIT) |
(height << CANVAS_HEIGHT_BIT) |
(wrap << 22) |
(blkmode << CANVAS_BLKMODE_BIT));
regmap_write(priv->dmc, DMC_CAV_LUT_ADDR,
CANVAS_LUT_WR_EN | canvas_index);
regmap_read(priv->dmc, DMC_CAV_LUT_DATAH, &val);
}
