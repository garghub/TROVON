static int sun50i_h5_pinctrl_probe(struct platform_device *pdev)
{
switch (of_irq_count(pdev->dev.of_node)) {
case 2:
dev_warn(&pdev->dev,
"Your device tree's pinctrl node is broken, which has no IRQ of PG bank routed.\n");
dev_warn(&pdev->dev,
"Please update the device tree, otherwise PG bank IRQ won't work.\n");
return sunxi_pinctrl_init(pdev,
&sun50i_h5_pinctrl_data_broken);
case 3:
return sunxi_pinctrl_init(pdev,
&sun50i_h5_pinctrl_data);
default:
return -EINVAL;
}
}
