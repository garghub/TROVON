static int simplefb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
u_int transp, struct fb_info *info)
{
u32 *pal = info->pseudo_palette;
u32 cr = red >> (16 - info->var.red.length);
u32 cg = green >> (16 - info->var.green.length);
u32 cb = blue >> (16 - info->var.blue.length);
u32 value;
if (regno >= PSEUDO_PALETTE_SIZE)
return -EINVAL;
value = (cr << info->var.red.offset) |
(cg << info->var.green.offset) |
(cb << info->var.blue.offset);
if (info->var.transp.length > 0) {
u32 mask = (1 << info->var.transp.length) - 1;
mask <<= info->var.transp.offset;
value |= mask;
}
pal[regno] = value;
return 0;
}
static void simplefb_destroy(struct fb_info *info)
{
simplefb_regulators_destroy(info->par);
simplefb_clocks_destroy(info->par);
if (info->screen_base)
iounmap(info->screen_base);
}
static int simplefb_parse_dt(struct platform_device *pdev,
struct simplefb_params *params)
{
struct device_node *np = pdev->dev.of_node;
int ret;
const char *format;
int i;
ret = of_property_read_u32(np, "width", &params->width);
if (ret) {
dev_err(&pdev->dev, "Can't parse width property\n");
return ret;
}
ret = of_property_read_u32(np, "height", &params->height);
if (ret) {
dev_err(&pdev->dev, "Can't parse height property\n");
return ret;
}
ret = of_property_read_u32(np, "stride", &params->stride);
if (ret) {
dev_err(&pdev->dev, "Can't parse stride property\n");
return ret;
}
ret = of_property_read_string(np, "format", &format);
if (ret) {
dev_err(&pdev->dev, "Can't parse format property\n");
return ret;
}
params->format = NULL;
for (i = 0; i < ARRAY_SIZE(simplefb_formats); i++) {
if (strcmp(format, simplefb_formats[i].name))
continue;
params->format = &simplefb_formats[i];
break;
}
if (!params->format) {
dev_err(&pdev->dev, "Invalid format value\n");
return -EINVAL;
}
return 0;
}
static int simplefb_parse_pd(struct platform_device *pdev,
struct simplefb_params *params)
{
struct simplefb_platform_data *pd = dev_get_platdata(&pdev->dev);
int i;
params->width = pd->width;
params->height = pd->height;
params->stride = pd->stride;
params->format = NULL;
for (i = 0; i < ARRAY_SIZE(simplefb_formats); i++) {
if (strcmp(pd->format, simplefb_formats[i].name))
continue;
params->format = &simplefb_formats[i];
break;
}
if (!params->format) {
dev_err(&pdev->dev, "Invalid format value\n");
return -EINVAL;
}
return 0;
}
static int simplefb_clocks_init(struct simplefb_par *par,
struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct clk *clock;
int i, ret;
if (dev_get_platdata(&pdev->dev) || !np)
return 0;
par->clk_count = of_clk_get_parent_count(np);
if (!par->clk_count)
return 0;
par->clks = kcalloc(par->clk_count, sizeof(struct clk *), GFP_KERNEL);
if (!par->clks)
return -ENOMEM;
for (i = 0; i < par->clk_count; i++) {
clock = of_clk_get(np, i);
if (IS_ERR(clock)) {
if (PTR_ERR(clock) == -EPROBE_DEFER) {
while (--i >= 0) {
if (par->clks[i])
clk_put(par->clks[i]);
}
kfree(par->clks);
return -EPROBE_DEFER;
}
dev_err(&pdev->dev, "%s: clock %d not found: %ld\n",
__func__, i, PTR_ERR(clock));
continue;
}
par->clks[i] = clock;
}
for (i = 0; i < par->clk_count; i++) {
if (par->clks[i]) {
ret = clk_prepare_enable(par->clks[i]);
if (ret) {
dev_err(&pdev->dev,
"%s: failed to enable clock %d: %d\n",
__func__, i, ret);
clk_put(par->clks[i]);
par->clks[i] = NULL;
}
}
}
return 0;
}
static void simplefb_clocks_destroy(struct simplefb_par *par)
{
int i;
if (!par->clks)
return;
for (i = 0; i < par->clk_count; i++) {
if (par->clks[i]) {
clk_disable_unprepare(par->clks[i]);
clk_put(par->clks[i]);
}
}
kfree(par->clks);
}
static int simplefb_clocks_init(struct simplefb_par *par,
struct platform_device *pdev) { return 0; }
static void simplefb_clocks_destroy(struct simplefb_par *par) { }
static int simplefb_regulators_init(struct simplefb_par *par,
struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct property *prop;
struct regulator *regulator;
const char *p;
int count = 0, i = 0, ret;
if (dev_get_platdata(&pdev->dev) || !np)
return 0;
for_each_property_of_node(np, prop) {
p = strstr(prop->name, SUPPLY_SUFFIX);
if (p && p != prop->name)
count++;
}
if (!count)
return 0;
par->regulators = devm_kcalloc(&pdev->dev, count,
sizeof(struct regulator *), GFP_KERNEL);
if (!par->regulators)
return -ENOMEM;
for_each_property_of_node(np, prop) {
char name[32];
p = strstr(prop->name, SUPPLY_SUFFIX);
if (!p || p == prop->name)
continue;
strlcpy(name, prop->name,
strlen(prop->name) - strlen(SUPPLY_SUFFIX) + 1);
regulator = devm_regulator_get_optional(&pdev->dev, name);
if (IS_ERR(regulator)) {
if (PTR_ERR(regulator) == -EPROBE_DEFER)
return -EPROBE_DEFER;
dev_err(&pdev->dev, "regulator %s not found: %ld\n",
name, PTR_ERR(regulator));
continue;
}
par->regulators[i++] = regulator;
}
par->regulator_count = i;
for (i = 0; i < par->regulator_count; i++) {
ret = regulator_enable(par->regulators[i]);
if (ret) {
dev_err(&pdev->dev,
"failed to enable regulator %d: %d\n",
i, ret);
devm_regulator_put(par->regulators[i]);
par->regulators[i] = NULL;
}
}
return 0;
}
static void simplefb_regulators_destroy(struct simplefb_par *par)
{
int i;
if (!par->regulators)
return;
for (i = 0; i < par->regulator_count; i++)
if (par->regulators[i])
regulator_disable(par->regulators[i]);
}
static int simplefb_regulators_init(struct simplefb_par *par,
struct platform_device *pdev) { return 0; }
static void simplefb_regulators_destroy(struct simplefb_par *par) { }
static int simplefb_probe(struct platform_device *pdev)
{
int ret;
struct simplefb_params params;
struct fb_info *info;
struct simplefb_par *par;
struct resource *mem;
if (fb_get_options("simplefb", NULL))
return -ENODEV;
ret = -ENODEV;
if (dev_get_platdata(&pdev->dev))
ret = simplefb_parse_pd(pdev, &params);
else if (pdev->dev.of_node)
ret = simplefb_parse_dt(pdev, &params);
if (ret)
return ret;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(&pdev->dev, "No memory resource\n");
return -EINVAL;
}
info = framebuffer_alloc(sizeof(struct simplefb_par), &pdev->dev);
if (!info)
return -ENOMEM;
platform_set_drvdata(pdev, info);
par = info->par;
info->fix = simplefb_fix;
info->fix.smem_start = mem->start;
info->fix.smem_len = resource_size(mem);
info->fix.line_length = params.stride;
info->var = simplefb_var;
info->var.xres = params.width;
info->var.yres = params.height;
info->var.xres_virtual = params.width;
info->var.yres_virtual = params.height;
info->var.bits_per_pixel = params.format->bits_per_pixel;
info->var.red = params.format->red;
info->var.green = params.format->green;
info->var.blue = params.format->blue;
info->var.transp = params.format->transp;
info->apertures = alloc_apertures(1);
if (!info->apertures) {
ret = -ENOMEM;
goto error_fb_release;
}
info->apertures->ranges[0].base = info->fix.smem_start;
info->apertures->ranges[0].size = info->fix.smem_len;
info->fbops = &simplefb_ops;
info->flags = FBINFO_DEFAULT | FBINFO_MISC_FIRMWARE;
info->screen_base = ioremap_wc(info->fix.smem_start,
info->fix.smem_len);
if (!info->screen_base) {
ret = -ENOMEM;
goto error_fb_release;
}
info->pseudo_palette = par->palette;
ret = simplefb_clocks_init(par, pdev);
if (ret < 0)
goto error_unmap;
ret = simplefb_regulators_init(par, pdev);
if (ret < 0)
goto error_clocks;
dev_info(&pdev->dev, "framebuffer at 0x%lx, 0x%x bytes, mapped to 0x%p\n",
info->fix.smem_start, info->fix.smem_len,
info->screen_base);
dev_info(&pdev->dev, "format=%s, mode=%dx%dx%d, linelength=%d\n",
params.format->name,
info->var.xres, info->var.yres,
info->var.bits_per_pixel, info->fix.line_length);
ret = register_framebuffer(info);
if (ret < 0) {
dev_err(&pdev->dev, "Unable to register simplefb: %d\n", ret);
goto error_regulators;
}
dev_info(&pdev->dev, "fb%d: simplefb registered!\n", info->node);
return 0;
error_regulators:
simplefb_regulators_destroy(par);
error_clocks:
simplefb_clocks_destroy(par);
error_unmap:
iounmap(info->screen_base);
error_fb_release:
framebuffer_release(info);
return ret;
}
static int simplefb_remove(struct platform_device *pdev)
{
struct fb_info *info = platform_get_drvdata(pdev);
unregister_framebuffer(info);
framebuffer_release(info);
return 0;
}
static int __init simplefb_init(void)
{
int ret;
struct device_node *np;
ret = platform_driver_register(&simplefb_driver);
if (ret)
return ret;
if (IS_ENABLED(CONFIG_OF_ADDRESS) && of_chosen) {
for_each_child_of_node(of_chosen, np) {
if (of_device_is_compatible(np, "simple-framebuffer"))
of_platform_device_create(np, NULL, NULL);
}
}
return 0;
}
