static int __init gef_gpio_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(gef_gpio_ids, &pdev->dev);
struct bgpio_chip *bgc;
void __iomem *regs;
int ret;
bgc = devm_kzalloc(&pdev->dev, sizeof(*bgc), GFP_KERNEL);
if (!bgc)
return -ENOMEM;
regs = of_iomap(pdev->dev.of_node, 0);
if (!regs)
return -ENOMEM;
ret = bgpio_init(bgc, &pdev->dev, 4, regs + GEF_GPIO_IN,
regs + GEF_GPIO_OUT, NULL, NULL,
regs + GEF_GPIO_DIRECT, BGPIOF_BIG_ENDIAN_BYTE_ORDER);
if (ret) {
dev_err(&pdev->dev, "bgpio_init failed\n");
goto err0;
}
bgc->gc.label = devm_kstrdup(&pdev->dev, pdev->dev.of_node->full_name,
GFP_KERNEL);
if (!bgc->gc.label) {
ret = -ENOMEM;
goto err0;
}
bgc->gc.base = -1;
bgc->gc.ngpio = (u16)(uintptr_t)of_id->data;
bgc->gc.of_gpio_n_cells = 2;
bgc->gc.of_node = pdev->dev.of_node;
ret = gpiochip_add(&bgc->gc);
if (ret)
goto err0;
return 0;
err0:
iounmap(regs);
pr_err("%s: GPIO chip registration failed\n",
pdev->dev.of_node->full_name);
return ret;
}
