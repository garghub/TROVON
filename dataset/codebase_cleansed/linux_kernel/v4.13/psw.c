static irqreturn_t psw_irq_handler(int irq, void *arg)
{
struct platform_device *pdev = arg;
struct push_switch *psw = platform_get_drvdata(pdev);
struct push_switch_platform_info *psw_info = pdev->dev.platform_data;
unsigned int l, mask;
int ret = 0;
l = __raw_readw(PA_DBSW);
if (psw->state) {
ret = 1;
goto out;
}
mask = l & 0x70;
if (mask & (1 << psw_info->bit)) {
psw->state = !!(mask & (1 << psw_info->bit));
if (psw->state)
mod_timer(&psw->debounce, jiffies + 50);
ret = 1;
}
out:
l |= (0x7 << 12);
__raw_writew(l, PA_DBSW);
return IRQ_RETVAL(ret);
}
static int __init psw_init(void)
{
return platform_add_devices(psw_devices, ARRAY_SIZE(psw_devices));
}
