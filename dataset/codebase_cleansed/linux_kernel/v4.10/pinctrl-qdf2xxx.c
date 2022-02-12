static int qdf2xxx_pinctrl_probe(struct platform_device *pdev)
{
struct pinctrl_pin_desc *pins;
struct msm_pingroup *groups;
unsigned int i;
u32 num_gpios;
int ret;
ret = device_property_read_u32(&pdev->dev, "num-gpios", &num_gpios);
if (ret < 0) {
dev_warn(&pdev->dev, "missing num-gpios property\n");
return ret;
}
if (!num_gpios || num_gpios > MAX_GPIOS) {
dev_warn(&pdev->dev, "invalid num-gpios property\n");
return -ENODEV;
}
pins = devm_kcalloc(&pdev->dev, num_gpios,
sizeof(struct pinctrl_pin_desc), GFP_KERNEL);
groups = devm_kcalloc(&pdev->dev, num_gpios,
sizeof(struct msm_pingroup), GFP_KERNEL);
if (!pins || !groups)
return -ENOMEM;
for (i = 0; i < num_gpios; i++) {
pins[i].number = i;
groups[i].npins = 1,
groups[i].pins = &pins[i].number;
groups[i].ctl_reg = 0x10000 * i;
groups[i].io_reg = 0x04 + 0x10000 * i;
groups[i].intr_cfg_reg = 0x08 + 0x10000 * i;
groups[i].intr_status_reg = 0x0c + 0x10000 * i;
groups[i].intr_target_reg = 0x08 + 0x10000 * i;
groups[i].mux_bit = 2;
groups[i].pull_bit = 0;
groups[i].drv_bit = 6;
groups[i].oe_bit = 9;
groups[i].in_bit = 0;
groups[i].out_bit = 1;
groups[i].intr_enable_bit = 0;
groups[i].intr_status_bit = 0;
groups[i].intr_target_bit = 5;
groups[i].intr_target_kpss_val = 1;
groups[i].intr_raw_status_bit = 4;
groups[i].intr_polarity_bit = 1;
groups[i].intr_detection_bit = 2;
groups[i].intr_detection_width = 2;
}
qdf2xxx_pinctrl.pins = pins;
qdf2xxx_pinctrl.groups = groups;
qdf2xxx_pinctrl.npins = num_gpios;
qdf2xxx_pinctrl.ngroups = num_gpios;
qdf2xxx_pinctrl.ngpios = num_gpios;
return msm_pinctrl_probe(pdev, &qdf2xxx_pinctrl);
}
static int __init qdf2xxx_pinctrl_init(void)
{
return platform_driver_register(&qdf2xxx_pinctrl_driver);
}
static void __exit qdf2xxx_pinctrl_exit(void)
{
platform_driver_unregister(&qdf2xxx_pinctrl_driver);
}
