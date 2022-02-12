static int cht_int33fe_probe(struct i2c_client *client)
{
struct device *dev = &client->dev;
struct i2c_board_info board_info;
struct cht_int33fe_data *data;
unsigned long long ptyp;
acpi_status status;
int fusb302_irq;
status = acpi_evaluate_integer(ACPI_HANDLE(dev), "PTYP", NULL, &ptyp);
if (ACPI_FAILURE(status)) {
dev_err(dev, "Error getting PTYPE\n");
return -ENODEV;
}
if (ptyp != EXPECTED_PTYPE)
return -ENODEV;
fusb302_irq = acpi_dev_gpio_irq_get(ACPI_COMPANION(dev), 1);
if (fusb302_irq < 0) {
if (fusb302_irq != -EPROBE_DEFER)
dev_err(dev, "Error getting FUSB302 irq\n");
return fusb302_irq;
}
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
memset(&board_info, 0, sizeof(board_info));
strlcpy(board_info.type, "max17047", I2C_NAME_SIZE);
data->max17047 = i2c_acpi_new_device(dev, 1, &board_info);
if (!data->max17047)
return -EPROBE_DEFER;
memset(&board_info, 0, sizeof(board_info));
strlcpy(board_info.type, "fusb302", I2C_NAME_SIZE);
board_info.irq = fusb302_irq;
data->fusb302 = i2c_acpi_new_device(dev, 2, &board_info);
if (!data->fusb302)
goto out_unregister_max17047;
memset(&board_info, 0, sizeof(board_info));
strlcpy(board_info.type, "pi3usb30532", I2C_NAME_SIZE);
data->pi3usb30532 = i2c_acpi_new_device(dev, 3, &board_info);
if (!data->pi3usb30532)
goto out_unregister_fusb302;
i2c_set_clientdata(client, data);
return 0;
out_unregister_fusb302:
i2c_unregister_device(data->fusb302);
out_unregister_max17047:
i2c_unregister_device(data->max17047);
return -EPROBE_DEFER;
}
static int cht_int33fe_remove(struct i2c_client *i2c)
{
struct cht_int33fe_data *data = i2c_get_clientdata(i2c);
i2c_unregister_device(data->pi3usb30532);
i2c_unregister_device(data->fusb302);
i2c_unregister_device(data->max17047);
return 0;
}
