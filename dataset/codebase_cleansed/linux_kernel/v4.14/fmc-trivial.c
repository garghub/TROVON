static irqreturn_t t_handler(int irq, void *dev_id)
{
struct fmc_device *fmc = dev_id;
fmc_irq_ack(fmc);
dev_info(&fmc->dev, "received irq %i\n", irq);
return IRQ_HANDLED;
}
static int t_probe(struct fmc_device *fmc)
{
int ret;
int index = 0;
index = fmc_validate(fmc, &t_drv);
if (index < 0)
return -EINVAL;
ret = fmc_irq_request(fmc, t_handler, "fmc-trivial", IRQF_SHARED);
if (ret < 0)
return ret;
fmc_gpio_config(fmc, t_gpio, ARRAY_SIZE(t_gpio));
ret = fmc_reprogram(fmc, &t_drv, "", 0);
if (ret == -EPERM)
ret = 0;
if (ret < 0)
fmc_irq_free(fmc);
return ret;
}
static int t_remove(struct fmc_device *fmc)
{
fmc_irq_free(fmc);
return 0;
}
static int t_init(void)
{
int ret;
ret = fmc_driver_register(&t_drv);
return ret;
}
static void t_exit(void)
{
fmc_driver_unregister(&t_drv);
}
