static void da9xxx_mask_irqs(struct i2c_client *client, const u8 regs[],
unsigned int nregs)
{
unsigned int i;
dev_info(&client->dev, "Masking %s interrupt sources\n", client->name);
for (i = 0; i < nregs; i++) {
int error = i2c_smbus_write_byte_data(client, regs[i], ~0);
if (error) {
dev_err(&client->dev, "i2c error %d\n", error);
return;
}
}
}
static int regulator_quirk_notify(struct notifier_block *nb,
unsigned long action, void *data)
{
struct device *dev = data;
struct i2c_client *client;
u32 mon;
mon = ioread32(irqc + IRQC_MONITOR);
dev_dbg(dev, "%s: %ld, IRQC_MONITOR = 0x%x\n", __func__, action, mon);
if (mon & REGULATOR_IRQ_MASK)
goto remove;
if (action != BUS_NOTIFY_ADD_DEVICE || dev->type == &i2c_adapter_type)
return 0;
client = to_i2c_client(dev);
dev_dbg(dev, "Detected %s\n", client->name);
if ((client->addr == 0x58 && !strcmp(client->name, "da9063")))
da9xxx_mask_irqs(client, da9063_mask_regs,
ARRAY_SIZE(da9063_mask_regs));
else if (client->addr == 0x68 && !strcmp(client->name, "da9210"))
da9xxx_mask_irqs(client, da9210_mask_regs,
ARRAY_SIZE(da9210_mask_regs));
mon = ioread32(irqc + IRQC_MONITOR);
if (mon & REGULATOR_IRQ_MASK)
goto remove;
return 0;
remove:
dev_info(dev, "IRQ2 is not asserted, removing quirk\n");
bus_unregister_notifier(&i2c_bus_type, nb);
iounmap(irqc);
return 0;
}
static int __init rcar_gen2_regulator_quirk(void)
{
u32 mon;
if (!of_machine_is_compatible("renesas,koelsch") &&
!of_machine_is_compatible("renesas,lager"))
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
