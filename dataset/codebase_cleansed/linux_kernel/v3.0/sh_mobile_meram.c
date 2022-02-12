static inline void meram_write_icb(void __iomem *base, int idx, int off,
unsigned long val)
{
iowrite32(val, MERAM_ICB_OFFSET(base, idx, off));
}
static inline unsigned long meram_read_icb(void __iomem *base, int idx, int off)
{
return ioread32(MERAM_ICB_OFFSET(base, idx, off));
}
static inline void meram_write_reg(void __iomem *base, int off,
unsigned long val)
{
iowrite32(val, base + off);
}
static inline unsigned long meram_read_reg(void __iomem *base, int off)
{
return ioread32(base + off);
}
static inline int meram_check_overlap(struct sh_mobile_meram_priv *priv,
struct sh_mobile_meram_icb *new)
{
int i;
int used_start, used_end, meram_start, meram_end;
if (new->marker_icb & ~0x1f || new->cache_icb & ~0x1f)
return 1;
if (test_bit(new->marker_icb, &priv->used_icb) ||
test_bit(new->cache_icb, &priv->used_icb))
return 1;
for (i = 0; i < priv->used_meram_cache_regions; i++) {
used_start = MERAM_CACHE_START(priv->used_meram_cache[i]);
used_end = MERAM_CACHE_END(priv->used_meram_cache[i]);
meram_start = new->meram_offset;
meram_end = new->meram_offset + new->meram_size;
if ((meram_start >= used_start && meram_start < used_end) ||
(meram_end > used_start && meram_end < used_end))
return 1;
}
return 0;
}
static inline void meram_mark(struct sh_mobile_meram_priv *priv,
struct sh_mobile_meram_icb *new)
{
int n;
if (new->marker_icb < 0 || new->cache_icb < 0)
return;
__set_bit(new->marker_icb, &priv->used_icb);
__set_bit(new->cache_icb, &priv->used_icb);
n = priv->used_meram_cache_regions;
priv->used_meram_cache[n] = MERAM_CACHE_SET(new->meram_offset,
new->meram_size);
priv->used_meram_cache_regions++;
}
static inline void meram_unmark(struct sh_mobile_meram_priv *priv,
struct sh_mobile_meram_icb *icb)
{
int i;
unsigned long pattern;
if (icb->marker_icb < 0 || icb->cache_icb < 0)
return;
__clear_bit(icb->marker_icb, &priv->used_icb);
__clear_bit(icb->cache_icb, &priv->used_icb);
pattern = MERAM_CACHE_SET(icb->meram_offset, icb->meram_size);
for (i = 0; i < priv->used_meram_cache_regions; i++) {
if (priv->used_meram_cache[i] == pattern) {
while (i < priv->used_meram_cache_regions - 1) {
priv->used_meram_cache[i] =
priv->used_meram_cache[i + 1] ;
i++;
}
priv->used_meram_cache[i] = 0;
priv->used_meram_cache_regions--;
break;
}
}
}
static inline int is_nvcolor(int cspace)
{
if (cspace == SH_MOBILE_MERAM_PF_NV ||
cspace == SH_MOBILE_MERAM_PF_NV24)
return 1;
return 0;
}
static inline void meram_set_next_addr(struct sh_mobile_meram_priv *priv,
struct sh_mobile_meram_cfg *cfg,
unsigned long base_addr_y,
unsigned long base_addr_c)
{
unsigned long target;
target = (cfg->current_reg) ? MExxSARA : MExxSARB;
cfg->current_reg ^= 1;
meram_write_icb(priv->base, cfg->icb[0].cache_icb, target,
base_addr_y);
meram_write_icb(priv->base, cfg->icb[0].marker_icb, target,
base_addr_y + cfg->icb[0].cache_unit);
if (is_nvcolor(cfg->pixelformat)) {
meram_write_icb(priv->base, cfg->icb[1].cache_icb, target,
base_addr_c);
meram_write_icb(priv->base, cfg->icb[1].marker_icb, target,
base_addr_c + cfg->icb[1].cache_unit);
}
}
static inline void meram_get_next_icb_addr(struct sh_mobile_meram_info *pdata,
struct sh_mobile_meram_cfg *cfg,
unsigned long *icb_addr_y,
unsigned long *icb_addr_c)
{
unsigned long icb_offset;
if (pdata->addr_mode == SH_MOBILE_MERAM_MODE0)
icb_offset = 0x80000000 | (cfg->current_reg << 29);
else
icb_offset = 0xc0000000 | (cfg->current_reg << 23);
*icb_addr_y = icb_offset | (cfg->icb[0].marker_icb << 24);
if (is_nvcolor(cfg->pixelformat))
*icb_addr_c = icb_offset | (cfg->icb[1].marker_icb << 24);
}
static int meram_init(struct sh_mobile_meram_priv *priv,
struct sh_mobile_meram_icb *icb,
int xres, int yres, int *out_pitch)
{
unsigned long total_byte_count = MERAM_CALC_BYTECOUNT(xres, yres);
unsigned long bnm;
int lcdc_pitch, xpitch, line_cnt;
int save_lines;
lcdc_pitch = (xres - 1) | 1023;
lcdc_pitch = lcdc_pitch | (lcdc_pitch >> 1);
lcdc_pitch = lcdc_pitch | (lcdc_pitch >> 2);
lcdc_pitch += 1;
if (lcdc_pitch == 8192 && yres >= 1024) {
lcdc_pitch = xpitch = MERAM_LINE_WIDTH;
line_cnt = total_byte_count >> 11;
*out_pitch = xres;
save_lines = (icb->meram_size / 16 / MERAM_SEC_LINE);
save_lines *= MERAM_SEC_LINE;
} else {
xpitch = xres;
line_cnt = yres;
*out_pitch = lcdc_pitch;
save_lines = icb->meram_size / (lcdc_pitch >> 10) / 2;
save_lines &= 0xff;
}
bnm = (save_lines - 1) << 16;
meram_write_icb(priv->base, icb->cache_icb, MExxBSIZE,
MERAM_MExxBSIZE_VAL(0x0, line_cnt - 1, xpitch - 1));
meram_write_icb(priv->base, icb->marker_icb, MExxBSIZE,
MERAM_MExxBSIZE_VAL(0xf, line_cnt - 1, xpitch - 1));
meram_write_icb(priv->base, icb->cache_icb, MExxMNCF, bnm);
meram_write_icb(priv->base, icb->marker_icb, MExxMNCF, bnm);
meram_write_icb(priv->base, icb->cache_icb, MExxSBSIZE, xpitch);
meram_write_icb(priv->base, icb->marker_icb, MExxSBSIZE, xpitch);
icb->cache_unit = xres * save_lines;
meram_write_icb(priv->base, icb->cache_icb, MExxCTL,
MERAM_MExxCTL_VAL(0x70f, icb->marker_icb,
icb->meram_offset));
meram_write_icb(priv->base, icb->marker_icb, MExxCTL,
MERAM_MExxCTL_VAL(0x70f, icb->cache_icb,
icb->meram_offset +
icb->meram_size / 2));
return 0;
}
static void meram_deinit(struct sh_mobile_meram_priv *priv,
struct sh_mobile_meram_icb *icb)
{
meram_write_icb(priv->base, icb->cache_icb, MExxCTL, 0);
meram_write_icb(priv->base, icb->marker_icb, MExxCTL, 0);
icb->cache_unit = 0;
}
static int sh_mobile_meram_register(struct sh_mobile_meram_info *pdata,
struct sh_mobile_meram_cfg *cfg,
int xres, int yres, int pixelformat,
unsigned long base_addr_y,
unsigned long base_addr_c,
unsigned long *icb_addr_y,
unsigned long *icb_addr_c,
int *pitch)
{
struct platform_device *pdev;
struct sh_mobile_meram_priv *priv;
int n, out_pitch;
int error = 0;
if (!pdata || !pdata->priv || !pdata->pdev || !cfg)
return -EINVAL;
if (pixelformat != SH_MOBILE_MERAM_PF_NV &&
pixelformat != SH_MOBILE_MERAM_PF_NV24 &&
pixelformat != SH_MOBILE_MERAM_PF_RGB)
return -EINVAL;
priv = pdata->priv;
pdev = pdata->pdev;
dev_dbg(&pdev->dev, "registering %dx%d (%s) (y=%08lx, c=%08lx)",
xres, yres, (!pixelformat) ? "yuv" : "rgb",
base_addr_y, base_addr_c);
mutex_lock(&priv->lock);
if (xres > 8192) {
dev_err(&pdev->dev, "width exceeding the limit (> 8192).");
error = -EINVAL;
goto err;
}
if (priv->used_meram_cache_regions + 2 > SH_MOBILE_MERAM_ICB_NUM) {
dev_err(&pdev->dev, "no more ICB available.");
error = -EINVAL;
goto err;
}
if (cfg->icb[0].marker_icb < 0 || cfg->icb[0].cache_icb < 0) {
dev_err(&pdev->dev, "at least one ICB is required.");
error = -EINVAL;
goto err;
}
if (meram_check_overlap(priv, &cfg->icb[0])) {
dev_err(&pdev->dev, "conflicting config detected.");
error = -EINVAL;
goto err;
}
n = 1;
if (cfg->icb[1].marker_icb >= 0 && cfg->icb[1].cache_icb >= 0) {
if (meram_check_overlap(priv, &cfg->icb[1])) {
dev_err(&pdev->dev, "conflicting config detected.");
error = -EINVAL;
goto err;
}
n = 2;
}
if (is_nvcolor(pixelformat) && n != 2) {
dev_err(&pdev->dev, "requires two ICB sets for planar Y/C.");
error = -EINVAL;
goto err;
}
cfg->pixelformat = pixelformat;
meram_mark(priv, &cfg->icb[0]);
if (is_nvcolor(pixelformat))
meram_mark(priv, &cfg->icb[1]);
meram_init(priv, &cfg->icb[0], xres, yres, &out_pitch);
*pitch = out_pitch;
if (pixelformat == SH_MOBILE_MERAM_PF_NV)
meram_init(priv, &cfg->icb[1], xres, (yres + 1) / 2,
&out_pitch);
else if (pixelformat == SH_MOBILE_MERAM_PF_NV24)
meram_init(priv, &cfg->icb[1], 2 * xres, (yres + 1) / 2,
&out_pitch);
cfg->current_reg = 1;
meram_set_next_addr(priv, cfg, base_addr_y, base_addr_c);
meram_get_next_icb_addr(pdata, cfg, icb_addr_y, icb_addr_c);
dev_dbg(&pdev->dev, "registered - can access via y=%08lx, c=%08lx",
*icb_addr_y, *icb_addr_c);
err:
mutex_unlock(&priv->lock);
return error;
}
static int sh_mobile_meram_unregister(struct sh_mobile_meram_info *pdata,
struct sh_mobile_meram_cfg *cfg)
{
struct sh_mobile_meram_priv *priv;
if (!pdata || !pdata->priv || !cfg)
return -EINVAL;
priv = pdata->priv;
mutex_lock(&priv->lock);
if (is_nvcolor(cfg->pixelformat)) {
meram_deinit(priv, &cfg->icb[1]);
meram_unmark(priv, &cfg->icb[1]);
}
meram_deinit(priv, &cfg->icb[0]);
meram_unmark(priv, &cfg->icb[0]);
mutex_unlock(&priv->lock);
return 0;
}
static int sh_mobile_meram_update(struct sh_mobile_meram_info *pdata,
struct sh_mobile_meram_cfg *cfg,
unsigned long base_addr_y,
unsigned long base_addr_c,
unsigned long *icb_addr_y,
unsigned long *icb_addr_c)
{
struct sh_mobile_meram_priv *priv;
if (!pdata || !pdata->priv || !cfg)
return -EINVAL;
priv = pdata->priv;
mutex_lock(&priv->lock);
meram_set_next_addr(priv, cfg, base_addr_y, base_addr_c);
meram_get_next_icb_addr(pdata, cfg, icb_addr_y, icb_addr_c);
mutex_unlock(&priv->lock);
return 0;
}
static int __devinit sh_mobile_meram_probe(struct platform_device *pdev)
{
struct sh_mobile_meram_priv *priv;
struct sh_mobile_meram_info *pdata = pdev->dev.platform_data;
struct resource *res;
int error;
if (!pdata) {
dev_err(&pdev->dev, "no platform data defined\n");
return -EINVAL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "cannot get platform resources\n");
return -ENOENT;
}
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(&pdev->dev, "cannot allocate device data\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, priv);
mutex_init(&priv->lock);
priv->base = ioremap_nocache(res->start, resource_size(res));
if (!priv->base) {
dev_err(&pdev->dev, "ioremap failed\n");
error = -EFAULT;
goto err;
}
pdata->ops = &sh_mobile_meram_ops;
pdata->priv = priv;
pdata->pdev = pdev;
if (pdata->addr_mode == SH_MOBILE_MERAM_MODE1)
meram_write_reg(priv->base, MEVCR1, 1 << 29);
dev_info(&pdev->dev, "sh_mobile_meram initialized.");
return 0;
err:
sh_mobile_meram_remove(pdev);
return error;
}
static int sh_mobile_meram_remove(struct platform_device *pdev)
{
struct sh_mobile_meram_priv *priv = platform_get_drvdata(pdev);
if (priv->base)
iounmap(priv->base);
mutex_destroy(&priv->lock);
kfree(priv);
return 0;
}
static int __init sh_mobile_meram_init(void)
{
return platform_driver_register(&sh_mobile_meram_driver);
}
static void __exit sh_mobile_meram_exit(void)
{
platform_driver_unregister(&sh_mobile_meram_driver);
}
