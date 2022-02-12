static int get_timing_param_ps(struct devbus *devbus,
struct device_node *node,
const char *name,
u32 *ticks)
{
u32 time_ps;
int err;
err = of_property_read_u32(node, name, &time_ps);
if (err < 0) {
dev_err(devbus->dev, "%s has no '%s' property\n",
name, node->full_name);
return err;
}
*ticks = (time_ps + devbus->tick_ps - 1) / devbus->tick_ps;
dev_dbg(devbus->dev, "%s: %u ps -> 0x%x\n",
name, time_ps, *ticks);
return 0;
}
static int devbus_set_timing_params(struct devbus *devbus,
struct device_node *node)
{
struct devbus_read_params r;
struct devbus_write_params w;
u32 value;
int err;
dev_dbg(devbus->dev, "Setting timing parameter, tick is %lu ps\n",
devbus->tick_ps);
err = of_property_read_u32(node, "devbus,bus-width", &r.bus_width);
if (err < 0) {
dev_err(devbus->dev,
"%s has no 'devbus,bus-width' property\n",
node->full_name);
return err;
}
if (r.bus_width == 8)
r.bus_width = 0;
else if (r.bus_width == 16)
r.bus_width = 1;
else {
dev_err(devbus->dev, "invalid bus width %d\n", r.bus_width);
return -EINVAL;
}
err = get_timing_param_ps(devbus, node, "devbus,badr-skew-ps",
&r.badr_skew);
if (err < 0)
return err;
err = get_timing_param_ps(devbus, node, "devbus,turn-off-ps",
&r.turn_off);
if (err < 0)
return err;
err = get_timing_param_ps(devbus, node, "devbus,acc-first-ps",
&r.acc_first);
if (err < 0)
return err;
err = get_timing_param_ps(devbus, node, "devbus,acc-next-ps",
&r.acc_next);
if (err < 0)
return err;
err = get_timing_param_ps(devbus, node, "devbus,rd-setup-ps",
&r.rd_setup);
if (err < 0)
return err;
err = get_timing_param_ps(devbus, node, "devbus,rd-hold-ps",
&r.rd_hold);
if (err < 0)
return err;
err = of_property_read_u32(node, "devbus,sync-enable",
&w.sync_enable);
if (err < 0) {
dev_err(devbus->dev,
"%s has no 'devbus,sync-enable' property\n",
node->full_name);
return err;
}
err = get_timing_param_ps(devbus, node, "devbus,ale-wr-ps",
&w.ale_wr);
if (err < 0)
return err;
err = get_timing_param_ps(devbus, node, "devbus,wr-low-ps",
&w.wr_low);
if (err < 0)
return err;
err = get_timing_param_ps(devbus, node, "devbus,wr-high-ps",
&w.wr_high);
if (err < 0)
return err;
value = r.bus_width << DEV_WIDTH_BIT |
r.badr_skew << BADR_SKEW_BIT |
r.rd_hold << RD_HOLD_BIT |
r.acc_next << ACC_NEXT_BIT |
r.rd_setup << RD_SETUP_BIT |
r.acc_first << ACC_FIRST_BIT |
r.turn_off;
dev_dbg(devbus->dev, "read parameters register 0x%p = 0x%x\n",
devbus->base + READ_PARAM_OFFSET,
value);
writel(value, devbus->base + READ_PARAM_OFFSET);
value = w.sync_enable << SYNC_ENABLE_BIT |
w.wr_low << WR_LOW_BIT |
w.wr_high << WR_HIGH_BIT |
w.ale_wr;
dev_dbg(devbus->dev, "write parameters register: 0x%p = 0x%x\n",
devbus->base + WRITE_PARAM_OFFSET,
value);
writel(value, devbus->base + WRITE_PARAM_OFFSET);
return 0;
}
static int mvebu_devbus_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *node = pdev->dev.of_node;
struct devbus *devbus;
struct resource *res;
struct clk *clk;
unsigned long rate;
int err;
devbus = devm_kzalloc(&pdev->dev, sizeof(struct devbus), GFP_KERNEL);
if (!devbus)
return -ENOMEM;
devbus->dev = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
devbus->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(devbus->base))
return PTR_ERR(devbus->base);
clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(clk))
return PTR_ERR(clk);
clk_prepare_enable(clk);
rate = clk_get_rate(clk) / 1000;
devbus->tick_ps = 1000000000 / rate;
err = devbus_set_timing_params(devbus, node);
if (err < 0)
return err;
err = of_platform_populate(node, NULL, NULL, dev);
if (err < 0)
return err;
return 0;
}
static int __init mvebu_devbus_init(void)
{
return platform_driver_register(&mvebu_devbus_driver);
}
