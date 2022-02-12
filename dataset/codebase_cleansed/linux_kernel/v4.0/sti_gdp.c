static const uint32_t *sti_gdp_get_formats(struct sti_layer *layer)
{
return gdp_supported_formats;
}
static unsigned int sti_gdp_get_nb_formats(struct sti_layer *layer)
{
return ARRAY_SIZE(gdp_supported_formats);
}
static int sti_gdp_fourcc2format(int fourcc)
{
switch (fourcc) {
case DRM_FORMAT_XRGB8888:
return GDP_RGB888_32;
case DRM_FORMAT_XBGR8888:
return GDP_XBGR8888;
case DRM_FORMAT_ARGB8888:
return GDP_ARGB8888;
case DRM_FORMAT_ABGR8888:
return GDP_ABGR8888;
case DRM_FORMAT_ARGB4444:
return GDP_ARGB4444;
case DRM_FORMAT_ARGB1555:
return GDP_ARGB1555;
case DRM_FORMAT_RGB565:
return GDP_RGB565;
case DRM_FORMAT_RGB888:
return GDP_RGB888;
case DRM_FORMAT_AYUV:
return GDP_AYCBR8888;
case DRM_FORMAT_YUV444:
return GDP_YCBR888;
case DRM_FORMAT_VYUY:
return GDP_YCBR422R;
case DRM_FORMAT_C8:
return GDP_CLUT8;
}
return -1;
}
static int sti_gdp_get_alpharange(int format)
{
switch (format) {
case GDP_ARGB8565:
case GDP_ARGB8888:
case GDP_AYCBR8888:
case GDP_ABGR8888:
return GAM_GDP_ALPHARANGE_255;
}
return 0;
}
static struct sti_gdp_node_list *sti_gdp_get_free_nodes(struct sti_layer *layer)
{
int hw_nvn;
struct sti_gdp *gdp = to_sti_gdp(layer);
unsigned int i;
hw_nvn = readl(layer->regs + GAM_GDP_NVN_OFFSET);
if (!hw_nvn)
goto end;
for (i = 0; i < GDP_NODE_NB_BANK; i++)
if ((hw_nvn != gdp->node_list[i].btm_field_paddr) &&
(hw_nvn != gdp->node_list[i].top_field_paddr))
return &gdp->node_list[i];
DRM_ERROR("inconsistent NVN for %s: 0x%08X\n",
sti_layer_to_str(layer), hw_nvn);
end:
return &gdp->node_list[0];
}
static
struct sti_gdp_node_list *sti_gdp_get_current_nodes(struct sti_layer *layer)
{
int hw_nvn;
struct sti_gdp *gdp = to_sti_gdp(layer);
unsigned int i;
hw_nvn = readl(layer->regs + GAM_GDP_NVN_OFFSET);
if (!hw_nvn)
goto end;
for (i = 0; i < GDP_NODE_NB_BANK; i++)
if ((hw_nvn == gdp->node_list[i].btm_field_paddr) ||
(hw_nvn == gdp->node_list[i].top_field_paddr))
return &gdp->node_list[i];
end:
DRM_DEBUG_DRIVER("Warning, NVN 0x%08X for %s does not match any node\n",
hw_nvn, sti_layer_to_str(layer));
return NULL;
}
static int sti_gdp_prepare_layer(struct sti_layer *layer, bool first_prepare)
{
struct sti_gdp_node_list *list;
struct sti_gdp_node *top_field, *btm_field;
struct drm_display_mode *mode = layer->mode;
struct device *dev = layer->dev;
struct sti_gdp *gdp = to_sti_gdp(layer);
struct sti_compositor *compo = dev_get_drvdata(dev);
int format;
unsigned int depth, bpp;
int rate = mode->clock * 1000;
int res;
u32 ydo, xdo, yds, xds;
list = sti_gdp_get_free_nodes(layer);
top_field = list->top_field;
btm_field = list->btm_field;
dev_dbg(dev, "%s %s top_node:0x%p btm_node:0x%p\n", __func__,
sti_layer_to_str(layer), top_field, btm_field);
top_field->gam_gdp_agc = GAM_GDP_AGC_FULL_RANGE;
top_field->gam_gdp_ctl = WAIT_NEXT_VSYNC;
format = sti_gdp_fourcc2format(layer->format);
if (format == -1) {
DRM_ERROR("Format not supported by GDP %.4s\n",
(char *)&layer->format);
return 1;
}
top_field->gam_gdp_ctl |= format;
top_field->gam_gdp_ctl |= sti_gdp_get_alpharange(format);
top_field->gam_gdp_ppt &= ~GAM_GDP_PPT_IGNORE;
drm_fb_get_bpp_depth(layer->format, &depth, &bpp);
top_field->gam_gdp_pml = (u32) layer->paddr + layer->offsets[0];
top_field->gam_gdp_pml += layer->src_x * (bpp >> 3);
top_field->gam_gdp_pml += layer->src_y * layer->pitches[0];
top_field->gam_gdp_pmp = layer->pitches[0];
top_field->gam_gdp_size =
clamp_val(layer->src_h, 0, GAM_GDP_SIZE_MAX) << 16 |
clamp_val(layer->src_w, 0, GAM_GDP_SIZE_MAX);
ydo = sti_vtg_get_line_number(*mode, layer->dst_y);
yds = sti_vtg_get_line_number(*mode, layer->dst_y + layer->dst_h - 1);
xdo = sti_vtg_get_pixel_number(*mode, layer->dst_x);
xds = sti_vtg_get_pixel_number(*mode, layer->dst_x + layer->dst_w - 1);
top_field->gam_gdp_vpo = (ydo << 16) | xdo;
top_field->gam_gdp_vps = (yds << 16) | xds;
memcpy(btm_field, top_field, sizeof(*btm_field));
top_field->gam_gdp_nvn = list->btm_field_paddr;
btm_field->gam_gdp_nvn = list->top_field_paddr;
if (layer->mode->flags & DRM_MODE_FLAG_INTERLACE)
btm_field->gam_gdp_pml = top_field->gam_gdp_pml +
layer->pitches[0];
if (first_prepare) {
if (sti_vtg_register_client(layer->mixer_id == STI_MIXER_MAIN ?
compo->vtg_main : compo->vtg_aux,
&gdp->vtg_field_nb, layer->mixer_id)) {
DRM_ERROR("Cannot register VTG notifier\n");
return 1;
}
if (gdp->clk_pix) {
struct clk *clkp;
if (layer->mixer_id == STI_MIXER_MAIN)
clkp = gdp->clk_main_parent;
else
clkp = gdp->clk_aux_parent;
if (clkp)
clk_set_parent(gdp->clk_pix, clkp);
res = clk_set_rate(gdp->clk_pix, rate);
if (res < 0) {
DRM_ERROR("Cannot set rate (%dHz) for gdp\n",
rate);
return 1;
}
if (clk_prepare_enable(gdp->clk_pix)) {
DRM_ERROR("Failed to prepare/enable gdp\n");
return 1;
}
}
}
return 0;
}
static int sti_gdp_commit_layer(struct sti_layer *layer)
{
struct sti_gdp_node_list *updated_list = sti_gdp_get_free_nodes(layer);
struct sti_gdp_node *updated_top_node = updated_list->top_field;
struct sti_gdp_node *updated_btm_node = updated_list->btm_field;
struct sti_gdp *gdp = to_sti_gdp(layer);
u32 dma_updated_top = updated_list->top_field_paddr;
u32 dma_updated_btm = updated_list->btm_field_paddr;
struct sti_gdp_node_list *curr_list = sti_gdp_get_current_nodes(layer);
dev_dbg(layer->dev, "%s %s top/btm_node:0x%p/0x%p\n", __func__,
sti_layer_to_str(layer),
updated_top_node, updated_btm_node);
dev_dbg(layer->dev, "Current NVN:0x%X\n",
readl(layer->regs + GAM_GDP_NVN_OFFSET));
dev_dbg(layer->dev, "Posted buff: %lx current buff: %x\n",
(unsigned long)layer->paddr,
readl(layer->regs + GAM_GDP_PML_OFFSET));
if (curr_list == NULL) {
DRM_DEBUG_DRIVER("%s first update (or invalid node)",
sti_layer_to_str(layer));
writel(gdp->is_curr_top == true ?
dma_updated_btm : dma_updated_top,
layer->regs + GAM_GDP_NVN_OFFSET);
return 0;
}
if (layer->mode->flags & DRM_MODE_FLAG_INTERLACE) {
if (gdp->is_curr_top == true) {
curr_list->btm_field->gam_gdp_nvn = dma_updated_top;
} else {
writel(dma_updated_top,
layer->regs + GAM_GDP_NVN_OFFSET);
}
} else {
writel(dma_updated_top, layer->regs + GAM_GDP_NVN_OFFSET);
}
return 0;
}
static int sti_gdp_disable_layer(struct sti_layer *layer)
{
unsigned int i;
struct sti_gdp *gdp = to_sti_gdp(layer);
struct sti_compositor *compo = dev_get_drvdata(layer->dev);
DRM_DEBUG_DRIVER("%s\n", sti_layer_to_str(layer));
for (i = 0; i < GDP_NODE_NB_BANK; i++) {
gdp->node_list[i].top_field->gam_gdp_ppt |= GAM_GDP_PPT_IGNORE;
gdp->node_list[i].btm_field->gam_gdp_ppt |= GAM_GDP_PPT_IGNORE;
}
if (sti_vtg_unregister_client(layer->mixer_id == STI_MIXER_MAIN ?
compo->vtg_main : compo->vtg_aux, &gdp->vtg_field_nb))
DRM_DEBUG_DRIVER("Warning: cannot unregister VTG notifier\n");
if (gdp->clk_pix)
clk_disable_unprepare(gdp->clk_pix);
return 0;
}
int sti_gdp_field_cb(struct notifier_block *nb,
unsigned long event, void *data)
{
struct sti_gdp *gdp = container_of(nb, struct sti_gdp, vtg_field_nb);
switch (event) {
case VTG_TOP_FIELD_EVENT:
gdp->is_curr_top = true;
break;
case VTG_BOTTOM_FIELD_EVENT:
gdp->is_curr_top = false;
break;
default:
DRM_ERROR("unsupported event: %lu\n", event);
break;
}
return 0;
}
static void sti_gdp_init(struct sti_layer *layer)
{
struct sti_gdp *gdp = to_sti_gdp(layer);
struct device_node *np = layer->dev->of_node;
dma_addr_t dma_addr;
void *base;
unsigned int i, size;
size = sizeof(struct sti_gdp_node) *
GDP_NODE_PER_FIELD * GDP_NODE_NB_BANK;
base = dma_alloc_writecombine(layer->dev,
size, &dma_addr, GFP_KERNEL | GFP_DMA);
if (!base) {
DRM_ERROR("Failed to allocate memory for GDP node\n");
return;
}
memset(base, 0, size);
for (i = 0; i < GDP_NODE_NB_BANK; i++) {
if (dma_addr & 0xF) {
DRM_ERROR("Mem alignment failed\n");
return;
}
gdp->node_list[i].top_field = base;
gdp->node_list[i].top_field_paddr = dma_addr;
DRM_DEBUG_DRIVER("node[%d].top_field=%p\n", i, base);
base += sizeof(struct sti_gdp_node);
dma_addr += sizeof(struct sti_gdp_node);
if (dma_addr & 0xF) {
DRM_ERROR("Mem alignment failed\n");
return;
}
gdp->node_list[i].btm_field = base;
gdp->node_list[i].btm_field_paddr = dma_addr;
DRM_DEBUG_DRIVER("node[%d].btm_field=%p\n", i, base);
base += sizeof(struct sti_gdp_node);
dma_addr += sizeof(struct sti_gdp_node);
}
if (of_device_is_compatible(np, "st,stih407-compositor")) {
char *clk_name;
switch (layer->desc) {
case STI_GDP_0:
clk_name = "pix_gdp1";
break;
case STI_GDP_1:
clk_name = "pix_gdp2";
break;
case STI_GDP_2:
clk_name = "pix_gdp3";
break;
case STI_GDP_3:
clk_name = "pix_gdp4";
break;
default:
DRM_ERROR("GDP id not recognized\n");
return;
}
gdp->clk_pix = devm_clk_get(layer->dev, clk_name);
if (IS_ERR(gdp->clk_pix))
DRM_ERROR("Cannot get %s clock\n", clk_name);
gdp->clk_main_parent = devm_clk_get(layer->dev, "main_parent");
if (IS_ERR(gdp->clk_main_parent))
DRM_ERROR("Cannot get main_parent clock\n");
gdp->clk_aux_parent = devm_clk_get(layer->dev, "aux_parent");
if (IS_ERR(gdp->clk_aux_parent))
DRM_ERROR("Cannot get aux_parent clock\n");
}
}
struct sti_layer *sti_gdp_create(struct device *dev, int id)
{
struct sti_gdp *gdp;
gdp = devm_kzalloc(dev, sizeof(*gdp), GFP_KERNEL);
if (!gdp) {
DRM_ERROR("Failed to allocate memory for GDP\n");
return NULL;
}
gdp->layer.ops = &gdp_ops;
gdp->vtg_field_nb.notifier_call = sti_gdp_field_cb;
return (struct sti_layer *)gdp;
}
