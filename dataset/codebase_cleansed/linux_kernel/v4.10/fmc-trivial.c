static irqreturn_t t_handler(int irq, void *dev_id)
{
struct fmc_device *fmc = dev_id;
fmc->op->irq_ack(fmc);
dev_info(&fmc->dev, "received irq %i\n", irq);
return IRQ_HANDLED;
}
static int t_probe(struct fmc_device *fmc)
{
int ret;
int index = 0;
if (fmc->op->validate)
index = fmc->op->validate(fmc, &t_drv);
if (index < 0)
return -EINVAL;
ret = fmc->op->irq_request(fmc, t_handler, "fmc-trivial", IRQF_SHARED);
if (ret < 0)
return ret;
fmc->op->gpio_config(fmc, t_gpio, ARRAY_SIZE(t_gpio));
ret = -ESRCH;
if (fmc->op->reprogram)
ret = fmc->op->reprogram(fmc, &t_drv, "");
if (ret == -ESRCH)
ret = 0;
if (ret < 0)
fmc->op->irq_free(fmc);
return ret;
}
static int t_remove(struct fmc_device *fmc)
{
fmc->op->irq_free(fmc);
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
