struct clcd_panel *versatile_clcd_get_panel(const char *name)
{
int i;
for (i = 0; i < ARRAY_SIZE(panels); i++)
if (strcmp(panels[i]->mode.name, name) == 0)
break;
if (i < ARRAY_SIZE(panels))
return panels[i];
pr_err("CLCD: couldn't get parameters for panel %s\n", name);
return NULL;
}
int versatile_clcd_setup_dma(struct clcd_fb *fb, unsigned long framesize)
{
dma_addr_t dma;
fb->fb.screen_base = dma_alloc_wc(&fb->dev->dev, framesize, &dma,
GFP_KERNEL);
if (!fb->fb.screen_base) {
pr_err("CLCD: unable to map framebuffer\n");
return -ENOMEM;
}
fb->fb.fix.smem_start = dma;
fb->fb.fix.smem_len = framesize;
return 0;
}
int versatile_clcd_mmap_dma(struct clcd_fb *fb, struct vm_area_struct *vma)
{
return dma_mmap_wc(&fb->dev->dev, vma, fb->fb.screen_base,
fb->fb.fix.smem_start, fb->fb.fix.smem_len);
}
void versatile_clcd_remove_dma(struct clcd_fb *fb)
{
dma_free_wc(&fb->dev->dev, fb->fb.fix.smem_len, fb->fb.screen_base,
fb->fb.fix.smem_start);
}
static void integrator_clcd_enable(struct clcd_fb *fb)
{
struct fb_var_screeninfo *var = &fb->fb.var;
u32 val;
dev_info(&fb->dev->dev, "enable Integrator CLCD connectors\n");
val = INTEGRATOR_CLCD_LCD_STATIC1 | INTEGRATOR_CLCD_LCD_STATIC2 |
INTEGRATOR_CLCD_LCD0_EN | INTEGRATOR_CLCD_LCD1_EN;
if (var->bits_per_pixel <= 8 ||
(var->bits_per_pixel == 16 && var->green.length == 5))
val |= INTEGRATOR_CLCD_LCDMUX_VGA555;
else if (fb->fb.var.bits_per_pixel <= 16)
val |= INTEGRATOR_CLCD_LCDMUX_VGA565;
else
val = 0;
regmap_update_bits(versatile_syscon_map,
INTEGRATOR_HDR_CTRL_OFFSET,
INTEGRATOR_CLCD_MASK,
val);
}
static void versatile_clcd_disable(struct clcd_fb *fb)
{
dev_info(&fb->dev->dev, "disable Versatile CLCD connectors\n");
regmap_update_bits(versatile_syscon_map,
SYS_CLCD,
SYS_CLCD_CONNECTOR_MASK,
0);
if (versatile_ib2_map) {
dev_info(&fb->dev->dev, "disable IB2 display\n");
regmap_update_bits(versatile_ib2_map,
IB2_CTRL,
IB2_CTRL_LCD_MASK,
IB2_CTRL_LCD_SD);
}
}
static void versatile_clcd_enable(struct clcd_fb *fb)
{
struct fb_var_screeninfo *var = &fb->fb.var;
u32 val = 0;
dev_info(&fb->dev->dev, "enable Versatile CLCD connectors\n");
switch (var->green.length) {
case 5:
val |= SYS_CLCD_MODE_5551;
break;
case 6:
if (var->red.offset == 0)
val |= SYS_CLCD_MODE_565_R_LSB;
else
val |= SYS_CLCD_MODE_565_B_LSB;
break;
case 8:
val |= SYS_CLCD_MODE_888;
break;
}
regmap_update_bits(versatile_syscon_map,
SYS_CLCD,
SYS_CLCD_MODE_MASK,
val);
regmap_update_bits(versatile_syscon_map,
SYS_CLCD,
SYS_CLCD_CONNECTOR_MASK,
SYS_CLCD_NLCDIOON | SYS_CLCD_PWR3V5SWITCH);
if (versatile_ib2_map) {
dev_info(&fb->dev->dev, "enable IB2 display\n");
regmap_update_bits(versatile_ib2_map,
IB2_CTRL,
IB2_CTRL_LCD_MASK,
IB2_CTRL_LCD_BL_ON);
}
}
static void versatile_clcd_decode(struct clcd_fb *fb, struct clcd_regs *regs)
{
clcdfb_decode(fb, regs);
if (fb->fb.var.green.length == 6)
regs->cntl &= ~CNTL_BGR;
}
static void realview_clcd_disable(struct clcd_fb *fb)
{
dev_info(&fb->dev->dev, "disable RealView CLCD connectors\n");
regmap_update_bits(versatile_syscon_map,
SYS_CLCD,
SYS_CLCD_CONNECTOR_MASK,
0);
}
static void realview_clcd_enable(struct clcd_fb *fb)
{
dev_info(&fb->dev->dev, "enable RealView CLCD connectors\n");
regmap_update_bits(versatile_syscon_map,
SYS_CLCD,
SYS_CLCD_CONNECTOR_MASK,
SYS_CLCD_NLCDIOON | SYS_CLCD_PWR3V5SWITCH);
}
static void versatile_panel_probe(struct device *dev,
struct device_node *endpoint)
{
struct versatile_panel const *vpanel = NULL;
struct device_node *panel = NULL;
u32 val;
int ret;
int i;
ret = regmap_read(versatile_syscon_map, SYS_CLCD, &val);
if (ret) {
dev_err(dev, "cannot read CLCD syscon register\n");
return;
}
val &= SYS_CLCD_CLCDID_MASK;
for (i = 0; i < ARRAY_SIZE(versatile_panels); i++) {
vpanel = &versatile_panels[i];
if (val == vpanel->id) {
dev_err(dev, "autodetected panel \"%s\"\n",
vpanel->compatible);
break;
}
}
if (i == ARRAY_SIZE(versatile_panels)) {
dev_err(dev, "could not auto-detect panel\n");
return;
}
panel = of_graph_get_remote_port_parent(endpoint);
if (!panel) {
dev_err(dev, "could not locate panel in DT\n");
return;
}
if (!of_device_is_compatible(panel, vpanel->compatible))
dev_err(dev, "panel in DT is not compatible with the "
"auto-detected panel, continuing anyway\n");
if (!vpanel->ib2)
return;
versatile_ib2_map = syscon_regmap_lookup_by_compatible(
"arm,versatile-ib2-syscon");
if (IS_ERR(versatile_ib2_map)) {
dev_err(dev, "could not locate IB2 control register\n");
versatile_ib2_map = NULL;
return;
}
}
int versatile_clcd_init_panel(struct clcd_fb *fb,
struct device_node *endpoint)
{
const struct of_device_id *clcd_id;
enum versatile_clcd versatile_clcd_type;
struct device_node *np;
struct regmap *map;
struct device *dev = &fb->dev->dev;
np = of_find_matching_node_and_match(NULL, versatile_clcd_of_match,
&clcd_id);
if (!np) {
return 0;
}
versatile_clcd_type = (enum versatile_clcd)clcd_id->data;
map = syscon_node_to_regmap(np);
if (IS_ERR(map)) {
dev_err(dev, "no Versatile syscon regmap\n");
return PTR_ERR(map);
}
switch (versatile_clcd_type) {
case INTEGRATOR_CLCD_CM:
versatile_syscon_map = map;
fb->board->enable = integrator_clcd_enable;
fb->board->caps = CLCD_CAP_5551 | CLCD_CAP_RGB565 |
CLCD_CAP_888;
dev_info(dev, "set up callbacks for Integrator PL110\n");
break;
case VERSATILE_CLCD:
versatile_syscon_map = map;
fb->board->enable = versatile_clcd_enable;
fb->board->disable = versatile_clcd_disable;
fb->board->decode = versatile_clcd_decode;
versatile_panel_probe(dev, endpoint);
dev_info(dev, "set up callbacks for Versatile\n");
break;
case REALVIEW_CLCD_EB:
case REALVIEW_CLCD_PB1176:
case REALVIEW_CLCD_PB11MP:
case REALVIEW_CLCD_PBA8:
case REALVIEW_CLCD_PBX:
versatile_syscon_map = map;
fb->board->enable = realview_clcd_enable;
fb->board->disable = realview_clcd_disable;
dev_info(dev, "set up callbacks for RealView PL111\n");
break;
default:
dev_info(dev, "unknown Versatile system controller\n");
break;
}
return 0;
}
