static int mdio_mux_mmioreg_switch_fn(int current_child, int desired_child,
void *data)
{
struct mdio_mux_mmioreg_state *s = data;
if (current_child ^ desired_child) {
void *p = ioremap(s->phys, 1);
uint8_t x, y;
if (!p)
return -ENOMEM;
x = ioread8(p);
y = (x & ~s->mask) | desired_child;
if (x != y) {
iowrite8((x & ~s->mask) | desired_child, p);
pr_debug("%s: %02x -> %02x\n", __func__, x, y);
}
iounmap(p);
}
return 0;
}
static int __devinit mdio_mux_mmioreg_probe(struct platform_device *pdev)
{
struct device_node *np2, *np = pdev->dev.of_node;
struct mdio_mux_mmioreg_state *s;
struct resource res;
const __be32 *iprop;
int len, ret;
dev_dbg(&pdev->dev, "probing node %s\n", np->full_name);
s = devm_kzalloc(&pdev->dev, sizeof(*s), GFP_KERNEL);
if (!s)
return -ENOMEM;
ret = of_address_to_resource(np, 0, &res);
if (ret) {
dev_err(&pdev->dev, "could not obtain memory map for node %s\n",
np->full_name);
return ret;
}
s->phys = res.start;
if (resource_size(&res) != sizeof(uint8_t)) {
dev_err(&pdev->dev, "only 8-bit registers are supported\n");
return -EINVAL;
}
iprop = of_get_property(np, "mux-mask", &len);
if (!iprop || len != sizeof(uint32_t)) {
dev_err(&pdev->dev, "missing or invalid mux-mask property\n");
return -ENODEV;
}
if (be32_to_cpup(iprop) > 255) {
dev_err(&pdev->dev, "only 8-bit registers are supported\n");
return -EINVAL;
}
s->mask = be32_to_cpup(iprop);
for_each_available_child_of_node(np, np2) {
iprop = of_get_property(np2, "reg", &len);
if (!iprop || len != sizeof(uint32_t)) {
dev_err(&pdev->dev, "mdio-mux child node %s is "
"missing a 'reg' property\n", np2->full_name);
return -ENODEV;
}
if (be32_to_cpup(iprop) & ~s->mask) {
dev_err(&pdev->dev, "mdio-mux child node %s has "
"a 'reg' value with unmasked bits\n",
np2->full_name);
return -ENODEV;
}
}
ret = mdio_mux_init(&pdev->dev, mdio_mux_mmioreg_switch_fn,
&s->mux_handle, s);
if (ret) {
dev_err(&pdev->dev, "failed to register mdio-mux bus %s\n",
np->full_name);
return ret;
}
pdev->dev.platform_data = s;
return 0;
}
static int __devexit mdio_mux_mmioreg_remove(struct platform_device *pdev)
{
struct mdio_mux_mmioreg_state *s = dev_get_platdata(&pdev->dev);
mdio_mux_uninit(s->mux_handle);
return 0;
}
