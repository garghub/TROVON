static ssize_t gpio_direction_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct gpio_desc *desc = dev_get_drvdata(dev);
ssize_t status;
mutex_lock(&sysfs_lock);
if (!test_bit(FLAG_EXPORT, &desc->flags)) {
status = -EIO;
} else {
gpiod_get_direction(desc);
status = sprintf(buf, "%s\n",
test_bit(FLAG_IS_OUT, &desc->flags)
? "out" : "in");
}
mutex_unlock(&sysfs_lock);
return status;
}
static ssize_t gpio_direction_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct gpio_desc *desc = dev_get_drvdata(dev);
ssize_t status;
mutex_lock(&sysfs_lock);
if (!test_bit(FLAG_EXPORT, &desc->flags))
status = -EIO;
else if (sysfs_streq(buf, "high"))
status = gpiod_direction_output_raw(desc, 1);
else if (sysfs_streq(buf, "out") || sysfs_streq(buf, "low"))
status = gpiod_direction_output_raw(desc, 0);
else if (sysfs_streq(buf, "in"))
status = gpiod_direction_input(desc);
else
status = -EINVAL;
mutex_unlock(&sysfs_lock);
return status ? : size;
}
static ssize_t gpio_value_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct gpio_desc *desc = dev_get_drvdata(dev);
ssize_t status;
mutex_lock(&sysfs_lock);
if (!test_bit(FLAG_EXPORT, &desc->flags))
status = -EIO;
else
status = sprintf(buf, "%d\n", gpiod_get_value_cansleep(desc));
mutex_unlock(&sysfs_lock);
return status;
}
static ssize_t gpio_value_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct gpio_desc *desc = dev_get_drvdata(dev);
ssize_t status;
mutex_lock(&sysfs_lock);
if (!test_bit(FLAG_EXPORT, &desc->flags))
status = -EIO;
else if (!test_bit(FLAG_IS_OUT, &desc->flags))
status = -EPERM;
else {
long value;
status = kstrtol(buf, 0, &value);
if (status == 0) {
gpiod_set_value_cansleep(desc, value);
status = size;
}
}
mutex_unlock(&sysfs_lock);
return status;
}
static irqreturn_t gpio_sysfs_irq(int irq, void *priv)
{
struct kernfs_node *value_sd = priv;
sysfs_notify_dirent(value_sd);
return IRQ_HANDLED;
}
static int gpio_setup_irq(struct gpio_desc *desc, struct device *dev,
unsigned long gpio_flags)
{
struct kernfs_node *value_sd;
unsigned long irq_flags;
int ret, irq, id;
if ((desc->flags & GPIO_TRIGGER_MASK) == gpio_flags)
return 0;
irq = gpiod_to_irq(desc);
if (irq < 0)
return -EIO;
id = desc->flags >> ID_SHIFT;
value_sd = idr_find(&dirent_idr, id);
if (value_sd)
free_irq(irq, value_sd);
desc->flags &= ~GPIO_TRIGGER_MASK;
if (!gpio_flags) {
gpiochip_unlock_as_irq(desc->chip, gpio_chip_hwgpio(desc));
ret = 0;
goto free_id;
}
irq_flags = IRQF_SHARED;
if (test_bit(FLAG_TRIG_FALL, &gpio_flags))
irq_flags |= test_bit(FLAG_ACTIVE_LOW, &desc->flags) ?
IRQF_TRIGGER_RISING : IRQF_TRIGGER_FALLING;
if (test_bit(FLAG_TRIG_RISE, &gpio_flags))
irq_flags |= test_bit(FLAG_ACTIVE_LOW, &desc->flags) ?
IRQF_TRIGGER_FALLING : IRQF_TRIGGER_RISING;
if (!value_sd) {
value_sd = sysfs_get_dirent(dev->kobj.sd, "value");
if (!value_sd) {
ret = -ENODEV;
goto err_out;
}
ret = idr_alloc(&dirent_idr, value_sd, 1, 0, GFP_KERNEL);
if (ret < 0)
goto free_sd;
id = ret;
desc->flags &= GPIO_FLAGS_MASK;
desc->flags |= (unsigned long)id << ID_SHIFT;
if (desc->flags >> ID_SHIFT != id) {
ret = -ERANGE;
goto free_id;
}
}
ret = request_any_context_irq(irq, gpio_sysfs_irq, irq_flags,
"gpiolib", value_sd);
if (ret < 0)
goto free_id;
ret = gpiochip_lock_as_irq(desc->chip, gpio_chip_hwgpio(desc));
if (ret < 0) {
gpiod_warn(desc, "failed to flag the GPIO for IRQ\n");
goto free_id;
}
desc->flags |= gpio_flags;
return 0;
free_id:
idr_remove(&dirent_idr, id);
desc->flags &= GPIO_FLAGS_MASK;
free_sd:
if (value_sd)
sysfs_put(value_sd);
err_out:
return ret;
}
static ssize_t gpio_edge_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
const struct gpio_desc *desc = dev_get_drvdata(dev);
ssize_t status;
mutex_lock(&sysfs_lock);
if (!test_bit(FLAG_EXPORT, &desc->flags))
status = -EIO;
else {
int i;
status = 0;
for (i = 0; i < ARRAY_SIZE(trigger_types); i++)
if ((desc->flags & GPIO_TRIGGER_MASK)
== trigger_types[i].flags) {
status = sprintf(buf, "%s\n",
trigger_types[i].name);
break;
}
}
mutex_unlock(&sysfs_lock);
return status;
}
static ssize_t gpio_edge_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct gpio_desc *desc = dev_get_drvdata(dev);
ssize_t status;
int i;
for (i = 0; i < ARRAY_SIZE(trigger_types); i++)
if (sysfs_streq(trigger_types[i].name, buf))
goto found;
return -EINVAL;
found:
mutex_lock(&sysfs_lock);
if (!test_bit(FLAG_EXPORT, &desc->flags))
status = -EIO;
else {
status = gpio_setup_irq(desc, dev, trigger_types[i].flags);
if (!status)
status = size;
}
mutex_unlock(&sysfs_lock);
return status;
}
static int sysfs_set_active_low(struct gpio_desc *desc, struct device *dev,
int value)
{
int status = 0;
if (!!test_bit(FLAG_ACTIVE_LOW, &desc->flags) == !!value)
return 0;
if (value)
set_bit(FLAG_ACTIVE_LOW, &desc->flags);
else
clear_bit(FLAG_ACTIVE_LOW, &desc->flags);
if (dev != NULL && (!!test_bit(FLAG_TRIG_RISE, &desc->flags) ^
!!test_bit(FLAG_TRIG_FALL, &desc->flags))) {
unsigned long trigger_flags = desc->flags & GPIO_TRIGGER_MASK;
gpio_setup_irq(desc, dev, 0);
status = gpio_setup_irq(desc, dev, trigger_flags);
}
return status;
}
static ssize_t gpio_active_low_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
const struct gpio_desc *desc = dev_get_drvdata(dev);
ssize_t status;
mutex_lock(&sysfs_lock);
if (!test_bit(FLAG_EXPORT, &desc->flags))
status = -EIO;
else
status = sprintf(buf, "%d\n",
!!test_bit(FLAG_ACTIVE_LOW, &desc->flags));
mutex_unlock(&sysfs_lock);
return status;
}
static ssize_t gpio_active_low_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct gpio_desc *desc = dev_get_drvdata(dev);
ssize_t status;
mutex_lock(&sysfs_lock);
if (!test_bit(FLAG_EXPORT, &desc->flags)) {
status = -EIO;
} else {
long value;
status = kstrtol(buf, 0, &value);
if (status == 0)
status = sysfs_set_active_low(desc, dev, value != 0);
}
mutex_unlock(&sysfs_lock);
return status ? : size;
}
static umode_t gpio_is_visible(struct kobject *kobj, struct attribute *attr,
int n)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct gpio_desc *desc = dev_get_drvdata(dev);
umode_t mode = attr->mode;
bool show_direction = test_bit(FLAG_SYSFS_DIR, &desc->flags);
if (attr == &dev_attr_direction.attr) {
if (!show_direction)
mode = 0;
} else if (attr == &dev_attr_edge.attr) {
if (gpiod_to_irq(desc) < 0)
mode = 0;
if (!show_direction && test_bit(FLAG_IS_OUT, &desc->flags))
mode = 0;
}
return mode;
}
static ssize_t chip_base_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
const struct gpio_chip *chip = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", chip->base);
}
static ssize_t chip_label_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
const struct gpio_chip *chip = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", chip->label ? : "");
}
static ssize_t chip_ngpio_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
const struct gpio_chip *chip = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", chip->ngpio);
}
static ssize_t export_store(struct class *class,
struct class_attribute *attr,
const char *buf, size_t len)
{
long gpio;
struct gpio_desc *desc;
int status;
status = kstrtol(buf, 0, &gpio);
if (status < 0)
goto done;
desc = gpio_to_desc(gpio);
if (!desc) {
pr_warn("%s: invalid GPIO %ld\n", __func__, gpio);
return -EINVAL;
}
status = gpiod_request(desc, "sysfs");
if (status < 0) {
if (status == -EPROBE_DEFER)
status = -ENODEV;
goto done;
}
status = gpiod_export(desc, true);
if (status < 0)
gpiod_free(desc);
else
set_bit(FLAG_SYSFS, &desc->flags);
done:
if (status)
pr_debug("%s: status %d\n", __func__, status);
return status ? : len;
}
static ssize_t unexport_store(struct class *class,
struct class_attribute *attr,
const char *buf, size_t len)
{
long gpio;
struct gpio_desc *desc;
int status;
status = kstrtol(buf, 0, &gpio);
if (status < 0)
goto done;
desc = gpio_to_desc(gpio);
if (!desc) {
pr_warn("%s: invalid GPIO %ld\n", __func__, gpio);
return -EINVAL;
}
status = -EINVAL;
if (test_and_clear_bit(FLAG_SYSFS, &desc->flags)) {
status = 0;
gpiod_free(desc);
}
done:
if (status)
pr_debug("%s: status %d\n", __func__, status);
return status ? : len;
}
int gpiod_export(struct gpio_desc *desc, bool direction_may_change)
{
struct gpio_chip *chip;
unsigned long flags;
int status;
const char *ioname = NULL;
struct device *dev;
int offset;
if (!gpio_class.p) {
pr_debug("%s: called too early!\n", __func__);
return -ENOENT;
}
if (!desc) {
pr_debug("%s: invalid gpio descriptor\n", __func__);
return -EINVAL;
}
chip = desc->chip;
mutex_lock(&sysfs_lock);
if (!chip || !chip->exported) {
status = -ENODEV;
goto fail_unlock;
}
spin_lock_irqsave(&gpio_lock, flags);
if (!test_bit(FLAG_REQUESTED, &desc->flags) ||
test_bit(FLAG_EXPORT, &desc->flags)) {
spin_unlock_irqrestore(&gpio_lock, flags);
gpiod_dbg(desc, "%s: unavailable (requested=%d, exported=%d)\n",
__func__,
test_bit(FLAG_REQUESTED, &desc->flags),
test_bit(FLAG_EXPORT, &desc->flags));
status = -EPERM;
goto fail_unlock;
}
if (desc->chip->direction_input && desc->chip->direction_output &&
direction_may_change) {
set_bit(FLAG_SYSFS_DIR, &desc->flags);
}
spin_unlock_irqrestore(&gpio_lock, flags);
offset = gpio_chip_hwgpio(desc);
if (desc->chip->names && desc->chip->names[offset])
ioname = desc->chip->names[offset];
dev = device_create_with_groups(&gpio_class, desc->chip->dev,
MKDEV(0, 0), desc, gpio_groups,
ioname ? ioname : "gpio%u",
desc_to_gpio(desc));
if (IS_ERR(dev)) {
status = PTR_ERR(dev);
goto fail_unlock;
}
set_bit(FLAG_EXPORT, &desc->flags);
mutex_unlock(&sysfs_lock);
return 0;
fail_unlock:
mutex_unlock(&sysfs_lock);
gpiod_dbg(desc, "%s: status %d\n", __func__, status);
return status;
}
static int match_export(struct device *dev, const void *data)
{
return dev_get_drvdata(dev) == data;
}
int gpiod_export_link(struct device *dev, const char *name,
struct gpio_desc *desc)
{
int status = -EINVAL;
if (!desc) {
pr_warn("%s: invalid GPIO\n", __func__);
return -EINVAL;
}
mutex_lock(&sysfs_lock);
if (test_bit(FLAG_EXPORT, &desc->flags)) {
struct device *tdev;
tdev = class_find_device(&gpio_class, NULL, desc, match_export);
if (tdev != NULL) {
status = sysfs_create_link(&dev->kobj, &tdev->kobj,
name);
put_device(tdev);
} else {
status = -ENODEV;
}
}
mutex_unlock(&sysfs_lock);
if (status)
gpiod_dbg(desc, "%s: status %d\n", __func__, status);
return status;
}
int gpiod_sysfs_set_active_low(struct gpio_desc *desc, int value)
{
struct device *dev = NULL;
int status = -EINVAL;
if (!desc) {
pr_warn("%s: invalid GPIO\n", __func__);
return -EINVAL;
}
mutex_lock(&sysfs_lock);
if (test_bit(FLAG_EXPORT, &desc->flags)) {
dev = class_find_device(&gpio_class, NULL, desc, match_export);
if (dev == NULL) {
status = -ENODEV;
goto unlock;
}
}
status = sysfs_set_active_low(desc, dev, value);
put_device(dev);
unlock:
mutex_unlock(&sysfs_lock);
if (status)
gpiod_dbg(desc, "%s: status %d\n", __func__, status);
return status;
}
void gpiod_unexport(struct gpio_desc *desc)
{
int status = 0;
struct device *dev = NULL;
if (!desc) {
pr_warn("%s: invalid GPIO\n", __func__);
return;
}
mutex_lock(&sysfs_lock);
if (test_bit(FLAG_EXPORT, &desc->flags)) {
dev = class_find_device(&gpio_class, NULL, desc, match_export);
if (dev) {
gpio_setup_irq(desc, dev, 0);
clear_bit(FLAG_SYSFS_DIR, &desc->flags);
clear_bit(FLAG_EXPORT, &desc->flags);
} else
status = -ENODEV;
}
mutex_unlock(&sysfs_lock);
if (dev) {
device_unregister(dev);
put_device(dev);
}
if (status)
gpiod_dbg(desc, "%s: status %d\n", __func__, status);
}
int gpiochip_export(struct gpio_chip *chip)
{
int status;
struct device *dev;
if (!gpio_class.p)
return 0;
mutex_lock(&sysfs_lock);
dev = device_create_with_groups(&gpio_class, chip->dev, MKDEV(0, 0),
chip, gpiochip_groups,
"gpiochip%d", chip->base);
if (IS_ERR(dev))
status = PTR_ERR(dev);
else
status = 0;
chip->exported = (status == 0);
mutex_unlock(&sysfs_lock);
if (status)
chip_dbg(chip, "%s: status %d\n", __func__, status);
return status;
}
void gpiochip_unexport(struct gpio_chip *chip)
{
int status;
struct device *dev;
struct gpio_desc *desc;
unsigned int i;
mutex_lock(&sysfs_lock);
dev = class_find_device(&gpio_class, NULL, chip, match_export);
if (dev) {
put_device(dev);
device_unregister(dev);
chip->exported = false;
status = 0;
} else
status = -ENODEV;
mutex_unlock(&sysfs_lock);
if (status)
chip_dbg(chip, "%s: status %d\n", __func__, status);
for (i = 0; i < chip->ngpio; i++) {
desc = &chip->desc[i];
if (test_and_clear_bit(FLAG_SYSFS, &desc->flags))
gpiod_free(desc);
}
}
static int __init gpiolib_sysfs_init(void)
{
int status;
unsigned long flags;
struct gpio_chip *chip;
status = class_register(&gpio_class);
if (status < 0)
return status;
spin_lock_irqsave(&gpio_lock, flags);
list_for_each_entry(chip, &gpio_chips, list) {
if (chip->exported)
continue;
spin_unlock_irqrestore(&gpio_lock, flags);
status = gpiochip_export(chip);
spin_lock_irqsave(&gpio_lock, flags);
}
spin_unlock_irqrestore(&gpio_lock, flags);
return status;
}
