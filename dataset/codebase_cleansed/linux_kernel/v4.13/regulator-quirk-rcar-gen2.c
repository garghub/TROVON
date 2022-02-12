static int regulator_quirk_notify(struct notifier_block *nb,
unsigned long action, void *data)
{
struct device *dev = data;
struct i2c_client *client;
static bool done;
u32 mon;
if (done)
return 0;
mon = ioread32(irqc + IRQC_MONITOR);
dev_dbg(dev, "%s: %ld, IRQC_MONITOR = 0x%x\n", __func__, action, mon);
if (mon & REGULATOR_IRQ_MASK)
goto remove;
if (action != BUS_NOTIFY_ADD_DEVICE || dev->type == &i2c_adapter_type)
return 0;
client = to_i2c_client(dev);
dev_dbg(dev, "Detected %s\n", client->name);
if ((client->addr == 0x58 && !strcmp(client->name, "da9063")) ||
(client->addr == 0x68 && !strcmp(client->name, "da9210"))) {
int ret;
dev_info(&client->dev, "clearing da9063/da9210 interrupts\n");
ret = i2c_transfer(client->adapter, da9xxx_msgs, ARRAY_SIZE(da9xxx_msgs));
if (ret != ARRAY_SIZE(da9xxx_msgs))
dev_err(&client->dev, "i2c error %d\n", ret);
}
mon = ioread32(irqc + IRQC_MONITOR);
if (mon & REGULATOR_IRQ_MASK)
goto remove;
return 0;
remove:
dev_info(dev, "IRQ2 is not asserted, removing quirk\n");
done = true;
iounmap(irqc);
return 0;
}
static int __init rcar_gen2_regulator_quirk(void)
{
u32 mon;
if (!of_machine_is_compatible("renesas,koelsch") &&
!of_machine_is_compatible("renesas,lager") &&
!of_machine_is_compatible("renesas,gose"))
return -ENODEV;
irqc = ioremap(IRQC_BASE, PAGE_SIZE);
if (!irqc)
return -ENOMEM;
mon = ioread32(irqc + IRQC_MONITOR);
if (mon & REGULATOR_IRQ_MASK) {
pr_debug("%s: IRQ2 is not asserted, not installing quirk\n",
__func__);
iounmap(irqc);
return 0;
}
pr_info("IRQ2 is asserted, installing da9063/da9210 regulator quirk\n");
bus_register_notifier(&i2c_bus_type, &regulator_quirk_nb);
return 0;
}
