static int men_z127_debounce(struct gpio_chip *gc, unsigned gpio,
unsigned debounce)
{
struct men_z127_gpio *priv = gpiochip_get_data(gc);
struct device *dev = &priv->mdev->dev;
unsigned int rnd;
u32 db_en, db_cnt;
if (!MEN_Z127_DB_IN_RANGE(debounce)) {
dev_err(dev, "debounce value %u out of range", debounce);
return -EINVAL;
}
if (debounce > 0) {
rnd = fls(debounce) - 1;
if (rnd && (debounce & BIT(rnd - 1)))
debounce = round_up(debounce, MEN_Z127_DB_MIN_US);
else
debounce = round_down(debounce, MEN_Z127_DB_MIN_US);
if (debounce > MEN_Z127_DB_MAX_US)
debounce = MEN_Z127_DB_MAX_US;
debounce /= 50;
}
spin_lock(&gc->bgpio_lock);
db_en = readl(priv->reg_base + MEN_Z127_DBER);
if (debounce == 0) {
db_en &= ~BIT(gpio);
db_cnt = 0;
} else {
db_en |= BIT(gpio);
db_cnt = debounce;
}
writel(db_en, priv->reg_base + MEN_Z127_DBER);
writel(db_cnt, priv->reg_base + GPIO_TO_DBCNT_REG(gpio));
spin_unlock(&gc->bgpio_lock);
return 0;
}
static int men_z127_request(struct gpio_chip *gc, unsigned gpio_pin)
{
struct men_z127_gpio *priv = gpiochip_get_data(gc);
u32 od_en;
if (gpio_pin >= gc->ngpio)
return -EINVAL;
spin_lock(&gc->bgpio_lock);
od_en = readl(priv->reg_base + MEN_Z127_ODER);
if (gpiochip_line_is_open_drain(gc, gpio_pin))
od_en |= BIT(gpio_pin);
else
od_en &= ~BIT(gpio_pin);
writel(od_en, priv->reg_base + MEN_Z127_ODER);
spin_unlock(&gc->bgpio_lock);
return 0;
}
static int men_z127_probe(struct mcb_device *mdev,
const struct mcb_device_id *id)
{
struct men_z127_gpio *men_z127_gpio;
struct device *dev = &mdev->dev;
int ret;
men_z127_gpio = devm_kzalloc(dev, sizeof(struct men_z127_gpio),
GFP_KERNEL);
if (!men_z127_gpio)
return -ENOMEM;
men_z127_gpio->mem = mcb_request_mem(mdev, dev_name(dev));
if (IS_ERR(men_z127_gpio->mem)) {
dev_err(dev, "failed to request device memory");
return PTR_ERR(men_z127_gpio->mem);
}
men_z127_gpio->reg_base = ioremap(men_z127_gpio->mem->start,
resource_size(men_z127_gpio->mem));
if (men_z127_gpio->reg_base == NULL) {
ret = -ENXIO;
goto err_release;
}
men_z127_gpio->mdev = mdev;
mcb_set_drvdata(mdev, men_z127_gpio);
ret = bgpio_init(&men_z127_gpio->gc, &mdev->dev, 4,
men_z127_gpio->reg_base + MEN_Z127_PSR,
men_z127_gpio->reg_base + MEN_Z127_CTRL,
NULL,
men_z127_gpio->reg_base + MEN_Z127_GPIODR,
NULL, 0);
if (ret)
goto err_unmap;
men_z127_gpio->gc.set_debounce = men_z127_debounce;
men_z127_gpio->gc.request = men_z127_request;
ret = gpiochip_add_data(&men_z127_gpio->gc, men_z127_gpio);
if (ret) {
dev_err(dev, "failed to register MEN 16Z127 GPIO controller");
goto err_unmap;
}
dev_info(dev, "MEN 16Z127 GPIO driver registered");
return 0;
err_unmap:
iounmap(men_z127_gpio->reg_base);
err_release:
mcb_release_mem(men_z127_gpio->mem);
return ret;
}
static void men_z127_remove(struct mcb_device *mdev)
{
struct men_z127_gpio *men_z127_gpio = mcb_get_drvdata(mdev);
gpiochip_remove(&men_z127_gpio->gc);
iounmap(men_z127_gpio->reg_base);
mcb_release_mem(men_z127_gpio->mem);
}
