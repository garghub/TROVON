static void omap2_sms_write_rot_control(u32 val, unsigned ctx)
{
__raw_writel(val, vrfb_base + SMS_ROT_CONTROL(ctx));
}
static void omap2_sms_write_rot_size(u32 val, unsigned ctx)
{
__raw_writel(val, vrfb_base + SMS_ROT_SIZE(ctx));
}
static void omap2_sms_write_rot_physical_ba(u32 val, unsigned ctx)
{
__raw_writel(val, vrfb_base + SMS_ROT_PHYSICAL_BA(ctx));
}
static inline void restore_hw_context(int ctx)
{
omap2_sms_write_rot_control(ctxs[ctx].control, ctx);
omap2_sms_write_rot_size(ctxs[ctx].size, ctx);
omap2_sms_write_rot_physical_ba(ctxs[ctx].physical_ba, ctx);
}
static u32 get_image_width_roundup(u16 width, u8 bytespp)
{
unsigned long stride = width * bytespp;
unsigned long ceil_pages_per_stride = (stride / VRFB_PAGE_WIDTH) +
(stride % VRFB_PAGE_WIDTH != 0);
return ceil_pages_per_stride * VRFB_PAGE_WIDTH / bytespp;
}
static inline u32 get_extra_physical_size(u16 image_width_roundup, u8 bytespp)
{
return (OMAP_VRFB_LINE_LEN - image_width_roundup) * VRFB_PAGE_HEIGHT *
bytespp;
}
void omap_vrfb_restore_context(void)
{
int i;
unsigned long map = ctx_map;
for (i = ffs(map); i; i = ffs(map)) {
i--;
map &= ~(1 << i);
restore_hw_context(i);
}
}
void omap_vrfb_adjust_size(u16 *width, u16 *height,
u8 bytespp)
{
*width = ALIGN(*width * bytespp, VRFB_PAGE_WIDTH) / bytespp;
*height = ALIGN(*height, VRFB_PAGE_HEIGHT);
}
u32 omap_vrfb_min_phys_size(u16 width, u16 height, u8 bytespp)
{
unsigned long image_width_roundup = get_image_width_roundup(width,
bytespp);
if (image_width_roundup > OMAP_VRFB_LINE_LEN)
return 0;
return (width * height * bytespp) + get_extra_physical_size(
image_width_roundup, bytespp);
}
u16 omap_vrfb_max_height(u32 phys_size, u16 width, u8 bytespp)
{
unsigned long image_width_roundup = get_image_width_roundup(width,
bytespp);
unsigned long height;
unsigned long extra;
if (image_width_roundup > OMAP_VRFB_LINE_LEN)
return 0;
extra = get_extra_physical_size(image_width_roundup, bytespp);
if (phys_size < extra)
return 0;
height = (phys_size - extra) / (width * bytespp);
return min_t(unsigned long, height, 2048);
}
void omap_vrfb_setup(struct vrfb *vrfb, unsigned long paddr,
u16 width, u16 height,
unsigned bytespp, bool yuv_mode)
{
unsigned pixel_size_exp;
u16 vrfb_width;
u16 vrfb_height;
u8 ctx = vrfb->context;
u32 size;
u32 control;
DBG("omapfb_set_vrfb(%d, %lx, %dx%d, %d, %d)\n", ctx, paddr,
width, height, bytespp, yuv_mode);
if (yuv_mode) {
bytespp *= 2;
width /= 2;
}
if (bytespp == 4)
pixel_size_exp = 2;
else if (bytespp == 2)
pixel_size_exp = 1;
else {
BUG();
return;
}
vrfb_width = ALIGN(width * bytespp, VRFB_PAGE_WIDTH) / bytespp;
vrfb_height = ALIGN(height, VRFB_PAGE_HEIGHT);
DBG("vrfb w %u, h %u bytespp %d\n", vrfb_width, vrfb_height, bytespp);
size = vrfb_width << SMS_IMAGEWIDTH_OFFSET;
size |= vrfb_height << SMS_IMAGEHEIGHT_OFFSET;
control = pixel_size_exp << SMS_PS_OFFSET;
control |= VRFB_PAGE_WIDTH_EXP << SMS_PW_OFFSET;
control |= VRFB_PAGE_HEIGHT_EXP << SMS_PH_OFFSET;
ctxs[ctx].physical_ba = paddr;
ctxs[ctx].size = size;
ctxs[ctx].control = control;
omap2_sms_write_rot_physical_ba(paddr, ctx);
omap2_sms_write_rot_size(size, ctx);
omap2_sms_write_rot_control(control, ctx);
DBG("vrfb offset pixels %d, %d\n",
vrfb_width - width, vrfb_height - height);
vrfb->xres = width;
vrfb->yres = height;
vrfb->xoffset = vrfb_width - width;
vrfb->yoffset = vrfb_height - height;
vrfb->bytespp = bytespp;
vrfb->yuv_mode = yuv_mode;
}
int omap_vrfb_map_angle(struct vrfb *vrfb, u16 height, u8 rot)
{
unsigned long size = height * OMAP_VRFB_LINE_LEN * vrfb->bytespp;
vrfb->vaddr[rot] = ioremap_wc(vrfb->paddr[rot], size);
if (!vrfb->vaddr[rot]) {
printk(KERN_ERR "vrfb: ioremap failed\n");
return -ENOMEM;
}
DBG("ioremapped vrfb area %d of size %lu into %p\n", rot, size,
vrfb->vaddr[rot]);
return 0;
}
void omap_vrfb_release_ctx(struct vrfb *vrfb)
{
int rot;
int ctx = vrfb->context;
if (ctx == 0xff)
return;
DBG("release ctx %d\n", ctx);
mutex_lock(&ctx_lock);
BUG_ON(!(ctx_map & (1 << ctx)));
clear_bit(ctx, &ctx_map);
for (rot = 0; rot < 4; ++rot) {
if (vrfb->paddr[rot]) {
release_mem_region(vrfb->paddr[rot], OMAP_VRFB_SIZE);
vrfb->paddr[rot] = 0;
}
}
vrfb->context = 0xff;
mutex_unlock(&ctx_lock);
}
int omap_vrfb_request_ctx(struct vrfb *vrfb)
{
int rot;
u32 paddr;
u8 ctx;
int r;
DBG("request ctx\n");
mutex_lock(&ctx_lock);
for (ctx = 0; ctx < num_ctxs; ++ctx)
if ((ctx_map & (1 << ctx)) == 0)
break;
if (ctx == num_ctxs) {
pr_err("vrfb: no free contexts\n");
r = -EBUSY;
goto out;
}
DBG("found free ctx %d\n", ctx);
set_bit(ctx, &ctx_map);
memset(vrfb, 0, sizeof(*vrfb));
vrfb->context = ctx;
for (rot = 0; rot < 4; ++rot) {
paddr = ctxs[ctx].base + SMS_ROT_VIRT_BASE(rot);
if (!request_mem_region(paddr, OMAP_VRFB_SIZE, "vrfb")) {
pr_err("vrfb: failed to reserve VRFB "
"area for ctx %d, rotation %d\n",
ctx, rot * 90);
omap_vrfb_release_ctx(vrfb);
r = -ENOMEM;
goto out;
}
vrfb->paddr[rot] = paddr;
DBG("VRFB %d/%d: %lx\n", ctx, rot*90, vrfb->paddr[rot]);
}
r = 0;
out:
mutex_unlock(&ctx_lock);
return r;
}
bool omap_vrfb_supported(void)
{
return vrfb_loaded;
}
static int __init vrfb_probe(struct platform_device *pdev)
{
struct resource *mem;
int i;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(&pdev->dev, "can't get vrfb base address\n");
return -EINVAL;
}
vrfb_base = devm_request_and_ioremap(&pdev->dev, mem);
if (!vrfb_base) {
dev_err(&pdev->dev, "can't ioremap vrfb memory\n");
return -ENOMEM;
}
num_ctxs = pdev->num_resources - 1;
ctxs = devm_kzalloc(&pdev->dev,
sizeof(struct vrfb_ctx) * num_ctxs,
GFP_KERNEL);
if (!ctxs)
return -ENOMEM;
for (i = 0; i < num_ctxs; ++i) {
mem = platform_get_resource(pdev, IORESOURCE_MEM, 1 + i);
if (!mem) {
dev_err(&pdev->dev, "can't get vrfb ctx %d address\n",
i);
return -EINVAL;
}
ctxs[i].base = mem->start;
}
vrfb_loaded = true;
return 0;
}
static void __exit vrfb_remove(struct platform_device *pdev)
{
vrfb_loaded = false;
}
static int __init vrfb_init(void)
{
return platform_driver_probe(&vrfb_driver, &vrfb_probe);
}
static void __exit vrfb_exit(void)
{
platform_driver_unregister(&vrfb_driver);
}
