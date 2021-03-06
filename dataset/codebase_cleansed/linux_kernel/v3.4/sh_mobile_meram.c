static inline void meram_write_icb(void __iomem *base, unsigned int idx,
unsigned int off, unsigned long val)
{
iowrite32(val, MERAM_ICB_OFFSET(base, idx, off));
}
static inline unsigned long meram_read_icb(void __iomem *base, unsigned int idx,
unsigned int off)
{
return ioread32(MERAM_ICB_OFFSET(base, idx, off));
}
static inline void meram_write_reg(void __iomem *base, unsigned int off,
unsigned long val)
{
iowrite32(val, base + off);
}
static inline unsigned long meram_read_reg(void __iomem *base, unsigned int off)
{
return ioread32(base + off);
}
static int __meram_alloc(struct sh_mobile_meram_priv *priv,
struct sh_mobile_meram_fb_plane *plane,
size_t size)
{
unsigned long mem;
unsigned long idx;
idx = find_first_zero_bit(&priv->used_icb, 28);
if (idx == 28)
return -ENOMEM;
plane->cache = &priv->icbs[idx];
idx = find_next_zero_bit(&priv->used_icb, 32, 28);
if (idx == 32)
return -ENOMEM;
plane->marker = &priv->icbs[idx];
mem = gen_pool_alloc(priv->pool, size * 1024);
if (mem == 0)
return -ENOMEM;
__set_bit(plane->marker->index, &priv->used_icb);
__set_bit(plane->cache->index, &priv->used_icb);
plane->marker->offset = mem - priv->meram;
plane->marker->size = size;
return 0;
}
static void __meram_free(struct sh_mobile_meram_priv *priv,
struct sh_mobile_meram_fb_plane *plane)
{
gen_pool_free(priv->pool, priv->meram + plane->marker->offset,
plane->marker->size * 1024);
__clear_bit(plane->marker->index, &priv->used_icb);
__clear_bit(plane->cache->index, &priv->used_icb);
}
static int is_nvcolor(int cspace)
{
if (cspace == SH_MOBILE_MERAM_PF_NV ||
cspace == SH_MOBILE_MERAM_PF_NV24)
return 1;
return 0;
}
static struct sh_mobile_meram_fb_cache *
meram_alloc(struct sh_mobile_meram_priv *priv,
const struct sh_mobile_meram_cfg *cfg,
int pixelformat)
{
struct sh_mobile_meram_fb_cache *cache;
unsigned int nplanes = is_nvcolor(pixelformat) ? 2 : 1;
int ret;
if (cfg->icb[0].meram_size == 0)
return ERR_PTR(-EINVAL);
if (nplanes == 2 && cfg->icb[1].meram_size == 0)
return ERR_PTR(-EINVAL);
cache = kzalloc(sizeof(*cache), GFP_KERNEL);
if (cache == NULL)
return ERR_PTR(-ENOMEM);
cache->nplanes = nplanes;
ret = __meram_alloc(priv, &cache->planes[0], cfg->icb[0].meram_size);
if (ret < 0)
goto error;
cache->planes[0].marker->current_reg = 1;
cache->planes[0].marker->pixelformat = pixelformat;
if (cache->nplanes == 1)
return cache;
ret = __meram_alloc(priv, &cache->planes[1], cfg->icb[1].meram_size);
if (ret < 0) {
__meram_free(priv, &cache->planes[0]);
goto error;
}
return cache;
error:
kfree(cache);
return ERR_PTR(-ENOMEM);
}
static void meram_free(struct sh_mobile_meram_priv *priv,
struct sh_mobile_meram_fb_cache *cache)
{
__meram_free(priv, &cache->planes[0]);
if (cache->nplanes == 2)
__meram_free(priv, &cache->planes[1]);
kfree(cache);
}
static void meram_set_next_addr(struct sh_mobile_meram_priv *priv,
struct sh_mobile_meram_fb_cache *cache,
unsigned long base_addr_y,
unsigned long base_addr_c)
{
struct sh_mobile_meram_icb *icb = cache->planes[0].marker;
unsigned long target;
icb->current_reg ^= 1;
target = icb->current_reg ? MExxSARB : MExxSARA;
meram_write_icb(priv->base, cache->planes[0].cache->index, target,
base_addr_y);
meram_write_icb(priv->base, cache->planes[0].marker->index, target,
base_addr_y + cache->planes[0].marker->cache_unit);
if (cache->nplanes == 2) {
meram_write_icb(priv->base, cache->planes[1].cache->index,
target, base_addr_c);
meram_write_icb(priv->base, cache->planes[1].marker->index,
target, base_addr_c +
cache->planes[1].marker->cache_unit);
}
}
static void
meram_get_next_icb_addr(struct sh_mobile_meram_info *pdata,
struct sh_mobile_meram_fb_cache *cache,
unsigned long *icb_addr_y, unsigned long *icb_addr_c)
{
struct sh_mobile_meram_icb *icb = cache->planes[0].marker;
unsigned long icb_offset;
if (pdata->addr_mode == SH_MOBILE_MERAM_MODE0)
icb_offset = 0x80000000 | (icb->current_reg << 29);
else
icb_offset = 0xc0000000 | (icb->current_reg << 23);
*icb_addr_y = icb_offset | (cache->planes[0].marker->index << 24);
if (cache->nplanes == 2)
*icb_addr_c = icb_offset
| (cache->planes[1].marker->index << 24);
}
static int meram_init(struct sh_mobile_meram_priv *priv,
struct sh_mobile_meram_fb_plane *plane,
unsigned int xres, unsigned int yres,
unsigned int *out_pitch)
{
struct sh_mobile_meram_icb *marker = plane->marker;
unsigned long total_byte_count = MERAM_CALC_BYTECOUNT(xres, yres);
unsigned long bnm;
unsigned int lcdc_pitch;
unsigned int xpitch;
unsigned int line_cnt;
unsigned int save_lines;
lcdc_pitch = (xres - 1) | 1023;
lcdc_pitch = lcdc_pitch | (lcdc_pitch >> 1);
lcdc_pitch = lcdc_pitch | (lcdc_pitch >> 2);
lcdc_pitch += 1;
if (lcdc_pitch == 8192 && yres >= 1024) {
lcdc_pitch = xpitch = MERAM_LINE_WIDTH;
line_cnt = total_byte_count >> 11;
*out_pitch = xres;
save_lines = plane->marker->size / 16 / MERAM_SEC_LINE;
save_lines *= MERAM_SEC_LINE;
} else {
xpitch = xres;
line_cnt = yres;
*out_pitch = lcdc_pitch;
save_lines = plane->marker->size / (lcdc_pitch >> 10) / 2;
save_lines &= 0xff;
}
bnm = (save_lines - 1) << 16;
meram_write_icb(priv->base, plane->cache->index, MExxBSIZE,
MERAM_MExxBSIZE_VAL(0x0, line_cnt - 1, xpitch - 1));
meram_write_icb(priv->base, plane->marker->index, MExxBSIZE,
MERAM_MExxBSIZE_VAL(0xf, line_cnt - 1, xpitch - 1));
meram_write_icb(priv->base, plane->cache->index, MExxMNCF, bnm);
meram_write_icb(priv->base, plane->marker->index, MExxMNCF, bnm);
meram_write_icb(priv->base, plane->cache->index, MExxSBSIZE, xpitch);
meram_write_icb(priv->base, plane->marker->index, MExxSBSIZE, xpitch);
plane->cache->cache_unit = xres * save_lines;
plane->marker->cache_unit = xres * save_lines;
meram_write_icb(priv->base, plane->cache->index, MExxCTL,
MERAM_MExxCTL_VAL(plane->marker->index, marker->offset)
| MExxCTL_WD1 | MExxCTL_WD0 | MExxCTL_WS | MExxCTL_CM |
MExxCTL_MD_FB);
meram_write_icb(priv->base, plane->marker->index, MExxCTL,
MERAM_MExxCTL_VAL(plane->cache->index, marker->offset +
plane->marker->size / 2) |
MExxCTL_WD1 | MExxCTL_WD0 | MExxCTL_WS | MExxCTL_CM |
MExxCTL_MD_FB);
return 0;
}
static void meram_deinit(struct sh_mobile_meram_priv *priv,
struct sh_mobile_meram_fb_plane *plane)
{
meram_write_icb(priv->base, plane->cache->index, MExxCTL,
MExxCTL_WBF | MExxCTL_WF | MExxCTL_RF);
meram_write_icb(priv->base, plane->marker->index, MExxCTL,
MExxCTL_WBF | MExxCTL_WF | MExxCTL_RF);
plane->cache->cache_unit = 0;
plane->marker->cache_unit = 0;
}
static void *sh_mobile_meram_register(struct sh_mobile_meram_info *pdata,
const struct sh_mobile_meram_cfg *cfg,
unsigned int xres, unsigned int yres,
unsigned int pixelformat,
unsigned int *pitch)
{
struct sh_mobile_meram_fb_cache *cache;
struct sh_mobile_meram_priv *priv = pdata->priv;
struct platform_device *pdev = pdata->pdev;
unsigned int out_pitch;
if (pixelformat != SH_MOBILE_MERAM_PF_NV &&
pixelformat != SH_MOBILE_MERAM_PF_NV24 &&
pixelformat != SH_MOBILE_MERAM_PF_RGB)
return ERR_PTR(-EINVAL);
dev_dbg(&pdev->dev, "registering %dx%d (%s)", xres, yres,
!pixelformat ? "yuv" : "rgb");
if (xres > 8192) {
dev_err(&pdev->dev, "width exceeding the limit (> 8192).");
return ERR_PTR(-EINVAL);
}
mutex_lock(&priv->lock);
cache = meram_alloc(priv, cfg, pixelformat);
if (IS_ERR(cache)) {
dev_err(&pdev->dev, "MERAM allocation failed (%ld).",
PTR_ERR(cache));
goto err;
}
meram_init(priv, &cache->planes[0], xres, yres, &out_pitch);
*pitch = out_pitch;
if (pixelformat == SH_MOBILE_MERAM_PF_NV)
meram_init(priv, &cache->planes[1], xres, (yres + 1) / 2,
&out_pitch);
else if (pixelformat == SH_MOBILE_MERAM_PF_NV24)
meram_init(priv, &cache->planes[1], 2 * xres, (yres + 1) / 2,
&out_pitch);
err:
mutex_unlock(&priv->lock);
return cache;
}
static void
sh_mobile_meram_unregister(struct sh_mobile_meram_info *pdata, void *data)
{
struct sh_mobile_meram_fb_cache *cache = data;
struct sh_mobile_meram_priv *priv = pdata->priv;
mutex_lock(&priv->lock);
meram_deinit(priv, &cache->planes[0]);
if (cache->nplanes == 2)
meram_deinit(priv, &cache->planes[1]);
meram_free(priv, cache);
mutex_unlock(&priv->lock);
}
static void
sh_mobile_meram_update(struct sh_mobile_meram_info *pdata, void *data,
unsigned long base_addr_y, unsigned long base_addr_c,
unsigned long *icb_addr_y, unsigned long *icb_addr_c)
{
struct sh_mobile_meram_fb_cache *cache = data;
struct sh_mobile_meram_priv *priv = pdata->priv;
mutex_lock(&priv->lock);
meram_set_next_addr(priv, cache, base_addr_y, base_addr_c);
meram_get_next_icb_addr(pdata, cache, icb_addr_y, icb_addr_c);
mutex_unlock(&priv->lock);
}
static int sh_mobile_meram_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct sh_mobile_meram_priv *priv = platform_get_drvdata(pdev);
unsigned int i, j;
for (i = 0; i < MERAM_REGS_SIZE; i++)
priv->regs[i] = meram_read_reg(priv->base, common_regs[i]);
for (i = 0; i < 32; i++) {
if (!test_bit(i, &priv->used_icb))
continue;
for (j = 0; j < ICB_REGS_SIZE; j++) {
priv->icbs[i].regs[j] =
meram_read_icb(priv->base, i, icb_regs[j]);
if (icb_regs[j] == MExxCTL)
priv->icbs[i].regs[j] |=
MExxCTL_WBF | MExxCTL_WF | MExxCTL_RF;
}
}
return 0;
}
static int sh_mobile_meram_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct sh_mobile_meram_priv *priv = platform_get_drvdata(pdev);
unsigned int i, j;
for (i = 0; i < 32; i++) {
if (!test_bit(i, &priv->used_icb))
continue;
for (j = 0; j < ICB_REGS_SIZE; j++)
meram_write_icb(priv->base, i, icb_regs[j],
priv->icbs[i].regs[j]);
}
for (i = 0; i < MERAM_REGS_SIZE; i++)
meram_write_reg(priv->base, common_regs[i], priv->regs[i]);
return 0;
}
static int __devinit sh_mobile_meram_probe(struct platform_device *pdev)
{
struct sh_mobile_meram_priv *priv;
struct sh_mobile_meram_info *pdata = pdev->dev.platform_data;
struct resource *regs;
struct resource *meram;
unsigned int i;
int error;
if (!pdata) {
dev_err(&pdev->dev, "no platform data defined\n");
return -EINVAL;
}
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
meram = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (regs == NULL || meram == NULL) {
dev_err(&pdev->dev, "cannot get platform resources\n");
return -ENOENT;
}
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(&pdev->dev, "cannot allocate device data\n");
return -ENOMEM;
}
mutex_init(&priv->lock);
priv->used_icb = pdata->reserved_icbs;
for (i = 0; i < MERAM_ICB_NUM; ++i)
priv->icbs[i].index = i;
pdata->ops = &sh_mobile_meram_ops;
pdata->priv = priv;
pdata->pdev = pdev;
if (!request_mem_region(regs->start, resource_size(regs), pdev->name)) {
dev_err(&pdev->dev, "MERAM registers region already claimed\n");
error = -EBUSY;
goto err_req_regs;
}
if (!request_mem_region(meram->start, resource_size(meram),
pdev->name)) {
dev_err(&pdev->dev, "MERAM memory region already claimed\n");
error = -EBUSY;
goto err_req_meram;
}
priv->base = ioremap_nocache(regs->start, resource_size(regs));
if (!priv->base) {
dev_err(&pdev->dev, "ioremap failed\n");
error = -EFAULT;
goto err_ioremap;
}
priv->meram = meram->start;
priv->pool = gen_pool_create(ilog2(MERAM_GRANULARITY), -1);
if (priv->pool == NULL) {
error = -ENOMEM;
goto err_genpool;
}
error = gen_pool_add(priv->pool, meram->start, resource_size(meram),
-1);
if (error < 0)
goto err_genpool;
if (pdata->addr_mode == SH_MOBILE_MERAM_MODE1)
meram_write_reg(priv->base, MEVCR1, MEVCR1_AMD1);
platform_set_drvdata(pdev, priv);
pm_runtime_enable(&pdev->dev);
dev_info(&pdev->dev, "sh_mobile_meram initialized.");
return 0;
err_genpool:
if (priv->pool)
gen_pool_destroy(priv->pool);
iounmap(priv->base);
err_ioremap:
release_mem_region(meram->start, resource_size(meram));
err_req_meram:
release_mem_region(regs->start, resource_size(regs));
err_req_regs:
mutex_destroy(&priv->lock);
kfree(priv);
return error;
}
static int sh_mobile_meram_remove(struct platform_device *pdev)
{
struct sh_mobile_meram_priv *priv = platform_get_drvdata(pdev);
struct resource *regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
struct resource *meram = platform_get_resource(pdev, IORESOURCE_MEM, 1);
pm_runtime_disable(&pdev->dev);
gen_pool_destroy(priv->pool);
iounmap(priv->base);
release_mem_region(meram->start, resource_size(meram));
release_mem_region(regs->start, resource_size(regs));
mutex_destroy(&priv->lock);
kfree(priv);
return 0;
}
