static void __devinit palmas_dt_to_pdata(struct device_node *node,
struct palmas_platform_data *pdata)
{
int ret;
u32 prop;
ret = of_property_read_u32(node, "ti,mux_pad1", &prop);
if (!ret) {
pdata->mux_from_pdata = 1;
pdata->pad1 = prop;
}
ret = of_property_read_u32(node, "ti,mux_pad2", &prop);
if (!ret) {
pdata->mux_from_pdata = 1;
pdata->pad2 = prop;
}
ret = of_property_read_u32(node, "ti,power_ctrl", &prop);
if (!ret)
pdata->power_ctrl = prop;
else
pdata->power_ctrl = PALMAS_POWER_CTRL_NSLEEP_MASK |
PALMAS_POWER_CTRL_ENABLE1_MASK |
PALMAS_POWER_CTRL_ENABLE2_MASK;
}
static int __devinit palmas_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct palmas *palmas;
struct palmas_platform_data *pdata;
struct device_node *node = i2c->dev.of_node;
int ret = 0, i;
unsigned int reg, addr;
int slave;
struct mfd_cell *children;
pdata = dev_get_platdata(&i2c->dev);
if (node && !pdata) {
pdata = devm_kzalloc(&i2c->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
palmas_dt_to_pdata(node, pdata);
}
if (!pdata)
return -EINVAL;
palmas = devm_kzalloc(&i2c->dev, sizeof(struct palmas), GFP_KERNEL);
if (palmas == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, palmas);
palmas->dev = &i2c->dev;
palmas->id = id->driver_data;
palmas->irq = i2c->irq;
for (i = 0; i < PALMAS_NUM_CLIENTS; i++) {
if (i == 0)
palmas->i2c_clients[i] = i2c;
else {
palmas->i2c_clients[i] =
i2c_new_dummy(i2c->adapter,
i2c->addr + i);
if (!palmas->i2c_clients[i]) {
dev_err(palmas->dev,
"can't attach client %d\n", i);
ret = -ENOMEM;
goto err;
}
}
palmas->regmap[i] = devm_regmap_init_i2c(palmas->i2c_clients[i],
&palmas_regmap_config[i]);
if (IS_ERR(palmas->regmap[i])) {
ret = PTR_ERR(palmas->regmap[i]);
dev_err(palmas->dev,
"Failed to allocate regmap %d, err: %d\n",
i, ret);
goto err;
}
}
slave = PALMAS_BASE_TO_SLAVE(PALMAS_INTERRUPT_BASE);
addr = PALMAS_BASE_TO_REG(PALMAS_INTERRUPT_BASE, PALMAS_INT_CTRL);
reg = PALMAS_INT_CTRL_INT_CLEAR;
regmap_write(palmas->regmap[slave], addr, reg);
ret = regmap_add_irq_chip(palmas->regmap[slave], palmas->irq,
IRQF_ONESHOT | IRQF_TRIGGER_LOW, 0, &palmas_irq_chip,
&palmas->irq_data);
if (ret < 0)
goto err;
slave = PALMAS_BASE_TO_SLAVE(PALMAS_PU_PD_OD_BASE);
addr = PALMAS_BASE_TO_REG(PALMAS_PU_PD_OD_BASE,
PALMAS_PRIMARY_SECONDARY_PAD1);
if (pdata->mux_from_pdata) {
reg = pdata->pad1;
ret = regmap_write(palmas->regmap[slave], addr, reg);
if (ret)
goto err_irq;
} else {
ret = regmap_read(palmas->regmap[slave], addr, &reg);
if (ret)
goto err_irq;
}
if (!(reg & PALMAS_PRIMARY_SECONDARY_PAD1_GPIO_0))
palmas->gpio_muxed |= PALMAS_GPIO_0_MUXED;
if (!(reg & PALMAS_PRIMARY_SECONDARY_PAD1_GPIO_1_MASK))
palmas->gpio_muxed |= PALMAS_GPIO_1_MUXED;
else if ((reg & PALMAS_PRIMARY_SECONDARY_PAD1_GPIO_1_MASK) ==
(2 << PALMAS_PRIMARY_SECONDARY_PAD1_GPIO_1_SHIFT))
palmas->led_muxed |= PALMAS_LED1_MUXED;
else if ((reg & PALMAS_PRIMARY_SECONDARY_PAD1_GPIO_1_MASK) ==
(3 << PALMAS_PRIMARY_SECONDARY_PAD1_GPIO_1_SHIFT))
palmas->pwm_muxed |= PALMAS_PWM1_MUXED;
if (!(reg & PALMAS_PRIMARY_SECONDARY_PAD1_GPIO_2_MASK))
palmas->gpio_muxed |= PALMAS_GPIO_2_MUXED;
else if ((reg & PALMAS_PRIMARY_SECONDARY_PAD1_GPIO_2_MASK) ==
(2 << PALMAS_PRIMARY_SECONDARY_PAD1_GPIO_2_SHIFT))
palmas->led_muxed |= PALMAS_LED2_MUXED;
else if ((reg & PALMAS_PRIMARY_SECONDARY_PAD1_GPIO_2_MASK) ==
(3 << PALMAS_PRIMARY_SECONDARY_PAD1_GPIO_2_SHIFT))
palmas->pwm_muxed |= PALMAS_PWM2_MUXED;
if (!(reg & PALMAS_PRIMARY_SECONDARY_PAD1_GPIO_3))
palmas->gpio_muxed |= PALMAS_GPIO_3_MUXED;
addr = PALMAS_BASE_TO_REG(PALMAS_PU_PD_OD_BASE,
PALMAS_PRIMARY_SECONDARY_PAD2);
if (pdata->mux_from_pdata) {
reg = pdata->pad2;
ret = regmap_write(palmas->regmap[slave], addr, reg);
if (ret)
goto err_irq;
} else {
ret = regmap_read(palmas->regmap[slave], addr, &reg);
if (ret)
goto err_irq;
}
if (!(reg & PALMAS_PRIMARY_SECONDARY_PAD2_GPIO_4))
palmas->gpio_muxed |= PALMAS_GPIO_4_MUXED;
if (!(reg & PALMAS_PRIMARY_SECONDARY_PAD2_GPIO_5_MASK))
palmas->gpio_muxed |= PALMAS_GPIO_5_MUXED;
if (!(reg & PALMAS_PRIMARY_SECONDARY_PAD2_GPIO_6))
palmas->gpio_muxed |= PALMAS_GPIO_6_MUXED;
if (!(reg & PALMAS_PRIMARY_SECONDARY_PAD2_GPIO_7_MASK))
palmas->gpio_muxed |= PALMAS_GPIO_7_MUXED;
dev_info(palmas->dev, "Muxing GPIO %x, PWM %x, LED %x\n",
palmas->gpio_muxed, palmas->pwm_muxed,
palmas->led_muxed);
reg = pdata->power_ctrl;
slave = PALMAS_BASE_TO_SLAVE(PALMAS_PMU_CONTROL_BASE);
addr = PALMAS_BASE_TO_REG(PALMAS_PMU_CONTROL_BASE, PALMAS_POWER_CTRL);
ret = regmap_write(palmas->regmap[slave], addr, reg);
if (ret)
goto err_irq;
if (node) {
ret = of_platform_populate(node, NULL, NULL, &i2c->dev);
if (ret < 0)
goto err_irq;
else
return ret;
}
children = kmemdup(palmas_children, sizeof(palmas_children),
GFP_KERNEL);
if (!children) {
ret = -ENOMEM;
goto err_irq;
}
children[PALMAS_PMIC_ID].platform_data = pdata->pmic_pdata;
children[PALMAS_PMIC_ID].pdata_size = sizeof(*pdata->pmic_pdata);
children[PALMAS_GPADC_ID].platform_data = pdata->gpadc_pdata;
children[PALMAS_GPADC_ID].pdata_size = sizeof(*pdata->gpadc_pdata);
children[PALMAS_RESOURCE_ID].platform_data = pdata->resource_pdata;
children[PALMAS_RESOURCE_ID].pdata_size =
sizeof(*pdata->resource_pdata);
children[PALMAS_USB_ID].platform_data = pdata->usb_pdata;
children[PALMAS_USB_ID].pdata_size = sizeof(*pdata->usb_pdata);
children[PALMAS_CLK_ID].platform_data = pdata->clk_pdata;
children[PALMAS_CLK_ID].pdata_size = sizeof(*pdata->clk_pdata);
ret = mfd_add_devices(palmas->dev, -1,
children, ARRAY_SIZE(palmas_children),
NULL, regmap_irq_chip_get_base(palmas->irq_data),
NULL);
kfree(children);
if (ret < 0)
goto err_devices;
return ret;
err_devices:
mfd_remove_devices(palmas->dev);
err_irq:
regmap_del_irq_chip(palmas->irq, palmas->irq_data);
err:
return ret;
}
static int palmas_i2c_remove(struct i2c_client *i2c)
{
struct palmas *palmas = i2c_get_clientdata(i2c);
mfd_remove_devices(palmas->dev);
regmap_del_irq_chip(palmas->irq, palmas->irq_data);
return 0;
}
static int __init palmas_i2c_init(void)
{
return i2c_add_driver(&palmas_i2c_driver);
}
static void __exit palmas_i2c_exit(void)
{
i2c_del_driver(&palmas_i2c_driver);
}
