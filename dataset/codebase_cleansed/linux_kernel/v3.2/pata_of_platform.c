static int __devinit pata_of_platform_probe(struct platform_device *ofdev)
{
int ret;
struct device_node *dn = ofdev->dev.of_node;
struct resource io_res;
struct resource ctl_res;
struct resource irq_res;
unsigned int reg_shift = 0;
int pio_mode = 0;
int pio_mask;
const u32 *prop;
ret = of_address_to_resource(dn, 0, &io_res);
if (ret) {
dev_err(&ofdev->dev, "can't get IO address from "
"device tree\n");
return -EINVAL;
}
if (of_device_is_compatible(dn, "electra-ide")) {
ctl_res = io_res;
ctl_res.start = ctl_res.start+0x3f6;
io_res.end = ctl_res.start-1;
} else {
ret = of_address_to_resource(dn, 1, &ctl_res);
if (ret) {
dev_err(&ofdev->dev, "can't get CTL address from "
"device tree\n");
return -EINVAL;
}
}
ret = of_irq_to_resource(dn, 0, &irq_res);
if (!ret)
irq_res.start = irq_res.end = 0;
else
irq_res.flags = 0;
prop = of_get_property(dn, "reg-shift", NULL);
if (prop)
reg_shift = be32_to_cpup(prop);
prop = of_get_property(dn, "pio-mode", NULL);
if (prop) {
pio_mode = be32_to_cpup(prop);
if (pio_mode > 6) {
dev_err(&ofdev->dev, "invalid pio-mode\n");
return -EINVAL;
}
} else {
dev_info(&ofdev->dev, "pio-mode unspecified, assuming PIO0\n");
}
pio_mask = 1 << pio_mode;
pio_mask |= (1 << pio_mode) - 1;
return __pata_platform_probe(&ofdev->dev, &io_res, &ctl_res, &irq_res,
reg_shift, pio_mask);
}
static int __devexit pata_of_platform_remove(struct platform_device *ofdev)
{
return __pata_platform_remove(&ofdev->dev);
}
static int __init pata_of_platform_init(void)
{
return platform_driver_register(&pata_of_platform_driver);
}
static void __exit pata_of_platform_exit(void)
{
platform_driver_unregister(&pata_of_platform_driver);
}
