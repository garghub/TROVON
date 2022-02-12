static int __init gef_gpio_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(gef_gpio_ids, &pdev->dev);
struct gpio_chip *gc;
void __iomem *regs;
int ret;
gc = devm_kzalloc(&pdev->dev, sizeof(*gc), GFP_KERNEL);
if (!gc)
return -ENOMEM;
regs = of_iomap(pdev->dev.of_node, 0);
if (!regs)
return -ENOMEM;
ret = bgpio_init(gc, &pdev->dev, 4, regs + GEF_GPIO_IN,
regs + GEF_GPIO_OUT, NULL, NULL,
regs + GEF_GPIO_DIRECT, BGPIOF_BIG_ENDIAN_BYTE_ORDER);
if (ret) {
dev_err(&pdev->dev, "bgpio_init failed\n");
goto err0;
}
gc->label = devm_kasprintf(&pdev->dev, GFP_KERNEL, "%pOF", pdev->dev.of_node);
if (!gc->label) {
ret = -ENOMEM;
goto err0;
}
gc->base = -1;
gc->ngpio = (u16)(uintptr_t)of_id->data;
gc->of_gpio_n_cells = 2;
gc->of_node = pdev->dev.of_node;
ret = devm_gpiochip_add_data(&pdev->dev, gc, NULL);
if (ret)
goto err0;
return 0;
err0:
iounmap(regs);
pr_err("%pOF: GPIO chip registration failed\n", pdev->dev.of_node);
return ret;
}
