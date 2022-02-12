static irqreturn_t img_ir_isr(int irq, void *dev_id)
{
struct img_ir_priv *priv = dev_id;
u32 irq_status;
spin_lock(&priv->lock);
irq_status = img_ir_read(priv, IMG_IR_IRQ_STATUS);
img_ir_write(priv, IMG_IR_IRQ_CLEAR, irq_status);
irq_status &= img_ir_read(priv, IMG_IR_IRQ_ENABLE);
if (irq_status & IMG_IR_IRQ_EDGE && img_ir_raw_enabled(&priv->raw))
img_ir_isr_raw(priv, irq_status);
if (irq_status & (IMG_IR_IRQ_DATA_MATCH |
IMG_IR_IRQ_DATA_VALID |
IMG_IR_IRQ_DATA2_VALID) &&
img_ir_hw_enabled(&priv->hw))
img_ir_isr_hw(priv, irq_status);
spin_unlock(&priv->lock);
return IRQ_HANDLED;
}
static void img_ir_setup(struct img_ir_priv *priv)
{
img_ir_write(priv, IMG_IR_IRQ_ENABLE, 0);
img_ir_setup_raw(priv);
img_ir_setup_hw(priv);
if (!IS_ERR(priv->clk))
clk_prepare_enable(priv->clk);
}
static void img_ir_ident(struct img_ir_priv *priv)
{
u32 core_rev = img_ir_read(priv, IMG_IR_CORE_REV);
dev_info(priv->dev,
"IMG IR Decoder (%d.%d.%d.%d) probed successfully\n",
(core_rev & IMG_IR_DESIGNER) >> IMG_IR_DESIGNER_SHIFT,
(core_rev & IMG_IR_MAJOR_REV) >> IMG_IR_MAJOR_REV_SHIFT,
(core_rev & IMG_IR_MINOR_REV) >> IMG_IR_MINOR_REV_SHIFT,
(core_rev & IMG_IR_MAINT_REV) >> IMG_IR_MAINT_REV_SHIFT);
dev_info(priv->dev, "Modes:%s%s\n",
img_ir_hw_enabled(&priv->hw) ? " hardware" : "",
img_ir_raw_enabled(&priv->raw) ? " raw" : "");
}
static int img_ir_probe(struct platform_device *pdev)
{
struct img_ir_priv *priv;
struct resource *res_regs;
int irq, error, error2;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "cannot find IRQ resource\n");
return irq;
}
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(&pdev->dev, "cannot allocate device data\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, priv);
priv->dev = &pdev->dev;
spin_lock_init(&priv->lock);
res_regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->reg_base = devm_ioremap_resource(&pdev->dev, res_regs);
if (IS_ERR(priv->reg_base))
return PTR_ERR(priv->reg_base);
priv->clk = devm_clk_get(&pdev->dev, "core");
if (IS_ERR(priv->clk))
dev_warn(&pdev->dev, "cannot get core clock resource\n");
error = img_ir_probe_raw(priv);
error2 = img_ir_probe_hw(priv);
if (error && error2)
return (error == -ENODEV) ? error2 : error;
priv->irq = irq;
error = request_irq(priv->irq, img_ir_isr, 0, "img-ir", priv);
if (error) {
dev_err(&pdev->dev, "cannot register IRQ %u\n",
priv->irq);
error = -EIO;
goto err_irq;
}
img_ir_ident(priv);
img_ir_setup(priv);
return 0;
err_irq:
img_ir_remove_hw(priv);
img_ir_remove_raw(priv);
return error;
}
static int img_ir_remove(struct platform_device *pdev)
{
struct img_ir_priv *priv = platform_get_drvdata(pdev);
free_irq(priv->irq, img_ir_isr);
img_ir_remove_hw(priv);
img_ir_remove_raw(priv);
if (!IS_ERR(priv->clk))
clk_disable_unprepare(priv->clk);
return 0;
}
