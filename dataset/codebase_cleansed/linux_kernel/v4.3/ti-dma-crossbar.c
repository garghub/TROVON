static inline void ti_dma_xbar_write(void __iomem *iomem, int xbar, u16 val)
{
writew_relaxed(val, iomem + (xbar * 2));
}
static void ti_dma_xbar_free(struct device *dev, void *route_data)
{
struct ti_dma_xbar_data *xbar = dev_get_drvdata(dev);
struct ti_dma_xbar_map *map = route_data;
dev_dbg(dev, "Unmapping XBAR%u (was routed to %d)\n",
map->xbar_in, map->xbar_out);
ti_dma_xbar_write(xbar->iomem, map->xbar_out, xbar->safe_val);
idr_remove(&xbar->map_idr, map->xbar_out);
kfree(map);
}
static void *ti_dma_xbar_route_allocate(struct of_phandle_args *dma_spec,
struct of_dma *ofdma)
{
struct platform_device *pdev = of_find_device_by_node(ofdma->of_node);
struct ti_dma_xbar_data *xbar = platform_get_drvdata(pdev);
struct ti_dma_xbar_map *map;
if (dma_spec->args[0] >= xbar->xbar_requests) {
dev_err(&pdev->dev, "Invalid XBAR request number: %d\n",
dma_spec->args[0]);
return ERR_PTR(-EINVAL);
}
dma_spec->np = of_parse_phandle(ofdma->of_node, "dma-masters", 0);
if (!dma_spec->np) {
dev_err(&pdev->dev, "Can't get DMA master\n");
return ERR_PTR(-EINVAL);
}
map = kzalloc(sizeof(*map), GFP_KERNEL);
if (!map) {
of_node_put(dma_spec->np);
return ERR_PTR(-ENOMEM);
}
map->xbar_out = idr_alloc(&xbar->map_idr, NULL, 0, xbar->dma_requests,
GFP_KERNEL);
map->xbar_in = (u16)dma_spec->args[0];
dma_spec->args[0] = map->xbar_out + xbar->dma_offset;
dev_dbg(&pdev->dev, "Mapping XBAR%u to DMA%d\n",
map->xbar_in, map->xbar_out);
ti_dma_xbar_write(xbar->iomem, map->xbar_out, map->xbar_in);
return map;
}
static int ti_dma_xbar_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
const struct of_device_id *match;
struct device_node *dma_node;
struct ti_dma_xbar_data *xbar;
struct resource *res;
u32 safe_val;
void __iomem *iomem;
int i, ret;
if (!node)
return -ENODEV;
xbar = devm_kzalloc(&pdev->dev, sizeof(*xbar), GFP_KERNEL);
if (!xbar)
return -ENOMEM;
idr_init(&xbar->map_idr);
dma_node = of_parse_phandle(node, "dma-masters", 0);
if (!dma_node) {
dev_err(&pdev->dev, "Can't get DMA master node\n");
return -ENODEV;
}
match = of_match_node(ti_dma_master_match, dma_node);
if (!match) {
dev_err(&pdev->dev, "DMA master is not supported\n");
return -EINVAL;
}
if (of_property_read_u32(dma_node, "dma-requests",
&xbar->dma_requests)) {
dev_info(&pdev->dev,
"Missing XBAR output information, using %u.\n",
TI_XBAR_OUTPUTS);
xbar->dma_requests = TI_XBAR_OUTPUTS;
}
of_node_put(dma_node);
if (of_property_read_u32(node, "dma-requests", &xbar->xbar_requests)) {
dev_info(&pdev->dev,
"Missing XBAR input information, using %u.\n",
TI_XBAR_INPUTS);
xbar->xbar_requests = TI_XBAR_INPUTS;
}
if (!of_property_read_u32(node, "ti,dma-safe-map", &safe_val))
xbar->safe_val = (u16)safe_val;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
iomem = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(iomem))
return PTR_ERR(iomem);
xbar->iomem = iomem;
xbar->dmarouter.dev = &pdev->dev;
xbar->dmarouter.route_free = ti_dma_xbar_free;
xbar->dma_offset = (u32)match->data;
platform_set_drvdata(pdev, xbar);
for (i = 0; i < xbar->dma_requests; i++)
ti_dma_xbar_write(xbar->iomem, i, xbar->safe_val);
ret = of_dma_router_register(node, ti_dma_xbar_route_allocate,
&xbar->dmarouter);
if (ret) {
for (i = 0; i < xbar->dma_requests; i++)
ti_dma_xbar_write(xbar->iomem, i, i);
}
return ret;
}
int omap_dmaxbar_init(void)
{
return platform_driver_register(&ti_dma_xbar_driver);
}
