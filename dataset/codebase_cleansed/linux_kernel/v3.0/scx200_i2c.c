static void scx200_i2c_setscl(void *data, int state)
{
scx200_gpio_set(scl, state);
}
static void scx200_i2c_setsda(void *data, int state)
{
scx200_gpio_set(sda, state);
}
static int scx200_i2c_getscl(void *data)
{
return scx200_gpio_get(scl);
}
static int scx200_i2c_getsda(void *data)
{
return scx200_gpio_get(sda);
}
static int scx200_i2c_init(void)
{
pr_debug(NAME ": NatSemi SCx200 I2C Driver\n");
if (!scx200_gpio_present()) {
printk(KERN_ERR NAME ": no SCx200 gpio pins available\n");
return -ENODEV;
}
pr_debug(NAME ": SCL=GPIO%02u, SDA=GPIO%02u\n", scl, sda);
if (scl == -1 || sda == -1 || scl == sda) {
printk(KERN_ERR NAME ": scl and sda must be specified\n");
return -EINVAL;
}
scx200_gpio_configure(scl, ~2, 5);
scx200_gpio_configure(sda, ~2, 5);
if (i2c_bit_add_bus(&scx200_i2c_ops) < 0) {
printk(KERN_ERR NAME ": adapter %s registration failed\n",
scx200_i2c_ops.name);
return -ENODEV;
}
return 0;
}
static void scx200_i2c_cleanup(void)
{
i2c_del_adapter(&scx200_i2c_ops);
}
