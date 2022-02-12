static int syscon_reboot_mode_write(struct reboot_mode_driver *reboot,
unsigned int magic)
{
struct syscon_reboot_mode *syscon_rbm;
int ret;
syscon_rbm = container_of(reboot, struct syscon_reboot_mode, reboot);
ret = regmap_update_bits(syscon_rbm->map, syscon_rbm->offset,
syscon_rbm->mask, magic);
if (ret < 0)
dev_err(reboot->dev, "update reboot mode bits failed\n");
return ret;
}
static int syscon_reboot_mode_probe(struct platform_device *pdev)
{
int ret;
struct syscon_reboot_mode *syscon_rbm;
syscon_rbm = devm_kzalloc(&pdev->dev, sizeof(*syscon_rbm), GFP_KERNEL);
if (!syscon_rbm)
return -ENOMEM;
syscon_rbm->reboot.dev = &pdev->dev;
syscon_rbm->reboot.write = syscon_reboot_mode_write;
syscon_rbm->mask = 0xffffffff;
dev_set_drvdata(&pdev->dev, syscon_rbm);
syscon_rbm->map = syscon_node_to_regmap(pdev->dev.parent->of_node);
if (IS_ERR(syscon_rbm->map))
return PTR_ERR(syscon_rbm->map);
if (of_property_read_u32(pdev->dev.of_node, "offset",
&syscon_rbm->offset))
return -EINVAL;
of_property_read_u32(pdev->dev.of_node, "mask", &syscon_rbm->mask);
ret = reboot_mode_register(&syscon_rbm->reboot);
if (ret)
dev_err(&pdev->dev, "can't register reboot mode\n");
return ret;
}
static int syscon_reboot_mode_remove(struct platform_device *pdev)
{
struct syscon_reboot_mode *syscon_rbm = dev_get_drvdata(&pdev->dev);
return reboot_mode_unregister(&syscon_rbm->reboot);
}
