static irqreturn_t gemini_powerbutton_interrupt(int irq, void *data)
{
struct gemini_powercon *gpw = data;
u32 val;
val = readl(gpw->base + GEMINI_PWC_CTRLREG);
val |= GEMINI_CTRL_IRQ_CLR;
writel(val, gpw->base + GEMINI_PWC_CTRLREG);
val = readl(gpw->base + GEMINI_PWC_STATREG);
val &= 0x70U;
switch (val) {
case GEMINI_STAT_CIR:
dev_info(gpw->dev, "infrared poweroff\n");
orderly_poweroff(true);
break;
case GEMINI_STAT_RTC:
dev_info(gpw->dev, "RTC poweroff\n");
orderly_poweroff(true);
break;
case GEMINI_STAT_POWERBUTTON:
dev_info(gpw->dev, "poweroff button pressed\n");
orderly_poweroff(true);
break;
default:
dev_info(gpw->dev, "other power management IRQ\n");
break;
}
return IRQ_HANDLED;
}
static void gemini_poweroff(void)
{
struct gemini_powercon *gpw = gpw_poweroff;
u32 val;
dev_crit(gpw->dev, "Gemini power off\n");
val = readl(gpw->base + GEMINI_PWC_CTRLREG);
val |= GEMINI_CTRL_ENABLE | GEMINI_CTRL_IRQ_CLR;
writel(val, gpw->base + GEMINI_PWC_CTRLREG);
val &= ~GEMINI_CTRL_ENABLE;
val |= GEMINI_CTRL_SHUTDOWN;
writel(val, gpw->base + GEMINI_PWC_CTRLREG);
}
static int gemini_poweroff_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct gemini_powercon *gpw;
u32 val;
int irq;
int ret;
gpw = devm_kzalloc(dev, sizeof(*gpw), GFP_KERNEL);
if (!gpw)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
gpw->base = devm_ioremap_resource(dev, res);
if (IS_ERR(gpw->base))
return PTR_ERR(gpw->base);
irq = platform_get_irq(pdev, 0);
if (!irq)
return -EINVAL;
gpw->dev = dev;
val = readl(gpw->base + GEMINI_PWC_IDREG);
val &= 0xFFFFFF00U;
if (val != GEMINI_PWC_ID) {
dev_err(dev, "wrong power controller ID: %08x\n",
val);
return -ENODEV;
}
val = readl(gpw->base + GEMINI_PWC_CTRLREG);
val |= GEMINI_CTRL_IRQ_CLR;
writel(val, gpw->base + GEMINI_PWC_CTRLREG);
ret = devm_request_irq(dev, irq, gemini_powerbutton_interrupt, 0,
"poweroff", gpw);
if (ret)
return ret;
pm_power_off = gemini_poweroff;
gpw_poweroff = gpw;
val = readl(gpw->base + GEMINI_PWC_CTRLREG);
val |= GEMINI_CTRL_ENABLE;
writel(val, gpw->base + GEMINI_PWC_CTRLREG);
dev_info(dev, "Gemini poweroff driver registered\n");
return 0;
}
