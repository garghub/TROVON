static int gpio_mockup_get(struct gpio_chip *gc, unsigned int offset)
{
struct gpio_mockup_chip *chip = gpiochip_get_data(gc);
return chip->lines[offset].value;
}
static void gpio_mockup_set(struct gpio_chip *gc, unsigned int offset,
int value)
{
struct gpio_mockup_chip *chip = gpiochip_get_data(gc);
chip->lines[offset].value = !!value;
}
static int gpio_mockup_dirout(struct gpio_chip *gc, unsigned int offset,
int value)
{
struct gpio_mockup_chip *chip = gpiochip_get_data(gc);
gpio_mockup_set(gc, offset, value);
chip->lines[offset].dir = GPIO_MOCKUP_DIR_OUT;
return 0;
}
static int gpio_mockup_dirin(struct gpio_chip *gc, unsigned int offset)
{
struct gpio_mockup_chip *chip = gpiochip_get_data(gc);
chip->lines[offset].dir = GPIO_MOCKUP_DIR_IN;
return 0;
}
static int gpio_mockup_get_direction(struct gpio_chip *gc, unsigned int offset)
{
struct gpio_mockup_chip *chip = gpiochip_get_data(gc);
return chip->lines[offset].dir;
}
static int gpio_mockup_name_lines(struct device *dev,
struct gpio_mockup_chip *chip)
{
struct gpio_chip *gc = &chip->gc;
char **names;
int i;
names = devm_kcalloc(dev, gc->ngpio, sizeof(char *), GFP_KERNEL);
if (!names)
return -ENOMEM;
for (i = 0; i < gc->ngpio; i++) {
names[i] = devm_kasprintf(dev, GFP_KERNEL,
"%s-%d", gc->label, i);
if (!names[i])
return -ENOMEM;
}
gc->names = (const char *const *)names;
return 0;
}
static int gpio_mockup_to_irq(struct gpio_chip *gc, unsigned int offset)
{
struct gpio_mockup_chip *chip = gpiochip_get_data(gc);
return irq_sim_irqnum(&chip->irqsim, offset);
}
static ssize_t gpio_mockup_event_write(struct file *file,
const char __user *usr_buf,
size_t size, loff_t *ppos)
{
struct gpio_mockup_dbgfs_private *priv;
struct gpio_mockup_chip *chip;
struct seq_file *sfile;
struct gpio_desc *desc;
int rv, val;
rv = kstrtoint_from_user(usr_buf, size, 0, &val);
if (rv)
return rv;
if (val != 0 && val != 1)
return -EINVAL;
sfile = file->private_data;
priv = sfile->private;
desc = priv->desc;
chip = priv->chip;
gpiod_set_value_cansleep(desc, val);
irq_sim_fire(&chip->irqsim, priv->offset);
return size;
}
static int gpio_mockup_event_open(struct inode *inode, struct file *file)
{
return single_open(file, NULL, inode->i_private);
}
static void gpio_mockup_debugfs_setup(struct device *dev,
struct gpio_mockup_chip *chip)
{
struct gpio_mockup_dbgfs_private *priv;
struct dentry *evfile;
struct gpio_chip *gc;
char *name;
int i;
gc = &chip->gc;
chip->dbg_dir = debugfs_create_dir(gc->label, gpio_mockup_dbg_dir);
if (!chip->dbg_dir)
goto err;
for (i = 0; i < gc->ngpio; i++) {
name = devm_kasprintf(dev, GFP_KERNEL, "%d", i);
if (!name)
goto err;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
goto err;
priv->chip = chip;
priv->offset = i;
priv->desc = &gc->gpiodev->descs[i];
evfile = debugfs_create_file(name, 0200, chip->dbg_dir, priv,
&gpio_mockup_event_ops);
if (!evfile)
goto err;
}
return;
err:
dev_err(dev, "error creating debugfs directory\n");
}
static int gpio_mockup_add(struct device *dev,
struct gpio_mockup_chip *chip,
const char *name, int base, int ngpio)
{
struct gpio_chip *gc = &chip->gc;
int ret;
gc->base = base;
gc->ngpio = ngpio;
gc->label = name;
gc->owner = THIS_MODULE;
gc->parent = dev;
gc->get = gpio_mockup_get;
gc->set = gpio_mockup_set;
gc->direction_output = gpio_mockup_dirout;
gc->direction_input = gpio_mockup_dirin;
gc->get_direction = gpio_mockup_get_direction;
gc->to_irq = gpio_mockup_to_irq;
chip->lines = devm_kcalloc(dev, gc->ngpio,
sizeof(*chip->lines), GFP_KERNEL);
if (!chip->lines)
return -ENOMEM;
if (gpio_mockup_named_lines) {
ret = gpio_mockup_name_lines(dev, chip);
if (ret)
return ret;
}
ret = devm_irq_sim_init(dev, &chip->irqsim, gc->ngpio);
if (ret)
return ret;
ret = devm_gpiochip_add_data(dev, &chip->gc, chip);
if (ret)
return ret;
if (gpio_mockup_dbg_dir)
gpio_mockup_debugfs_setup(dev, chip);
return 0;
}
static int gpio_mockup_probe(struct platform_device *pdev)
{
int ret, i, base, ngpio, num_chips;
struct device *dev = &pdev->dev;
struct gpio_mockup_chip *chips;
char *chip_name;
if (gpio_mockup_params_nr < 2 || (gpio_mockup_params_nr % 2))
return -EINVAL;
num_chips = gpio_mockup_params_nr / 2;
chips = devm_kcalloc(dev, num_chips, sizeof(*chips), GFP_KERNEL);
if (!chips)
return -ENOMEM;
platform_set_drvdata(pdev, chips);
for (i = 0; i < num_chips; i++) {
base = gpio_mockup_ranges[i * 2];
if (base == -1)
ngpio = gpio_mockup_ranges[i * 2 + 1];
else
ngpio = gpio_mockup_ranges[i * 2 + 1] - base;
if (ngpio >= 0) {
chip_name = devm_kasprintf(dev, GFP_KERNEL,
"%s-%c", GPIO_MOCKUP_NAME,
gpio_mockup_name_start + i);
if (!chip_name)
return -ENOMEM;
ret = gpio_mockup_add(dev, &chips[i],
chip_name, base, ngpio);
} else {
ret = -EINVAL;
}
if (ret) {
dev_err(dev,
"adding gpiochip failed: %d (base: %d, ngpio: %d)\n",
ret, base, base < 0 ? ngpio : base + ngpio);
return ret;
}
}
return 0;
}
static int __init mock_device_init(void)
{
int err;
gpio_mockup_dbg_dir = debugfs_create_dir("gpio-mockup-event", NULL);
if (!gpio_mockup_dbg_dir)
pr_err("%s: error creating debugfs directory\n",
GPIO_MOCKUP_NAME);
pdev = platform_device_alloc(GPIO_MOCKUP_NAME, -1);
if (!pdev)
return -ENOMEM;
err = platform_device_add(pdev);
if (err) {
platform_device_put(pdev);
return err;
}
err = platform_driver_register(&gpio_mockup_driver);
if (err) {
platform_device_unregister(pdev);
return err;
}
return 0;
}
static void __exit mock_device_exit(void)
{
debugfs_remove_recursive(gpio_mockup_dbg_dir);
platform_driver_unregister(&gpio_mockup_driver);
platform_device_unregister(pdev);
}
