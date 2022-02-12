static irqreturn_t mmc_cd_gpio_irqt(int irq, void *dev_id)
{
mmc_detect_change(dev_id, msecs_to_jiffies(100));
return IRQ_HANDLED;
}
int mmc_cd_gpio_request(struct mmc_host *host, unsigned int gpio,
unsigned int irq, unsigned long flags)
{
size_t len = strlen(dev_name(host->parent)) + 4;
struct mmc_cd_gpio *cd = kmalloc(sizeof(*cd) + len, GFP_KERNEL);
int ret;
if (!cd)
return -ENOMEM;
snprintf(cd->label, len, "%s cd", dev_name(host->parent));
ret = gpio_request_one(gpio, GPIOF_DIR_IN, cd->label);
if (ret < 0)
goto egpioreq;
ret = request_threaded_irq(irq, NULL, mmc_cd_gpio_irqt,
flags, cd->label, host);
if (ret < 0)
goto eirqreq;
cd->gpio = gpio;
host->hotplug.irq = irq;
host->hotplug.handler_priv = cd;
return 0;
eirqreq:
gpio_free(gpio);
egpioreq:
kfree(cd);
return ret;
}
void mmc_cd_gpio_free(struct mmc_host *host)
{
struct mmc_cd_gpio *cd = host->hotplug.handler_priv;
free_irq(host->hotplug.irq, host);
gpio_free(cd->gpio);
kfree(cd);
}
