void coda_set_gdi_regs(struct coda_ctx *ctx)
{
struct coda_dev *dev = ctx->dev;
const u16 *xy2ca_map;
u32 xy2rbc_config;
int i;
switch (ctx->tiled_map_type) {
case GDI_LINEAR_FRAME_MAP:
default:
xy2ca_map = xy2ca_zero_map;
xy2rbc_config = 0;
break;
case GDI_TILED_FRAME_MB_RASTER_MAP:
xy2ca_map = xy2ca_tiled_map;
xy2rbc_config = CODA9_XY2RBC_TILED_MAP |
CODA9_XY2RBC_CA_INC_HOR |
(16 - 1) << 12 | (8 - 1) << 4;
break;
}
for (i = 0; i < 16; i++)
coda_write(dev, xy2ca_map[i],
CODA9_GDI_XY2_CAS_0 + 4 * i);
for (i = 0; i < 4; i++)
coda_write(dev, XY2(ZERO, 0, ZERO, 0),
CODA9_GDI_XY2_BA_0 + 4 * i);
for (i = 0; i < 16; i++)
coda_write(dev, XY2(ZERO, 0, ZERO, 0),
CODA9_GDI_XY2_RAS_0 + 4 * i);
coda_write(dev, xy2rbc_config, CODA9_GDI_XY2_RBC_CONFIG);
if (xy2rbc_config) {
for (i = 0; i < 32; i++)
coda_write(dev, rbc2axi_tiled_map[i],
CODA9_GDI_RBC2_AXI_0 + 4 * i);
}
}
