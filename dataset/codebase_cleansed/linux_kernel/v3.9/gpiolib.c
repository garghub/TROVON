static inline void desc_set_label(struct gpio_desc *d, const char *label)
{
#ifdef CONFIG_DEBUG_FS
d->label = label;
#endif
}
static int gpio_chip_hwgpio(const struct gpio_desc *desc)
{
return desc - &desc->chip->desc[0];
}
static struct gpio_desc *gpio_to_desc(unsigned gpio)
{
if (WARN(!gpio_is_valid(gpio), "invalid GPIO %d\n", gpio))
return NULL;
else
return &gpio_desc[gpio];
}
static int desc_to_gpio(const struct gpio_desc *desc)
{
return desc->chip->base + gpio_chip_hwgpio(desc);
}
static int gpio_ensure_requested(struct gpio_desc *desc)
{
const struct gpio_chip *chip = desc->chip;
const int gpio = desc_to_gpio(desc);
if (WARN(test_and_set_bit(FLAG_REQUESTED, &desc->flags) == 0,
"autorequest GPIO-%d\n", gpio)) {
if (!try_module_get(chip->owner)) {
pr_err("GPIO-%d: module can't be gotten \n", gpio);
clear_bit(FLAG_REQUESTED, &desc->flags);
return -EIO;
}
desc_set_label(desc, "[auto]");
if (chip->request)
return 1;
}
return 0;
}
static struct gpio_chip *gpiod_to_chip(const struct gpio_desc *desc)
{
return desc ? desc->chip : NULL;
}
struct gpio_chip *gpio_to_chip(unsigned gpio)
{
return gpiod_to_chip(gpio_to_desc(gpio));
}
static int gpiochip_find_base(int ngpio)
{
struct gpio_chip *chip;
int base = ARCH_NR_GPIOS - ngpio;
list_for_each_entry_reverse(chip, &gpio_chips, list) {
if (chip->base + chip->ngpio <= base)
break;
else
base = chip->base - ngpio;
}
if (gpio_is_valid(base)) {
pr_debug("%s: found new base at %d\n", __func__, base);
return base;
} else {
pr_err("%s: cannot find free range\n", __func__);
return -ENOSPC;
}
}
static int gpiod_get_direction(const struct gpio_desc *desc)
{
struct gpio_chip *chip;
unsigned offset;
int status = -EINVAL;
chip = gpiod_to_chip(desc);
offset = gpio_chip_hwgpio(desc);
if (!chip->get_direction)
return status;
status = chip->get_direction(chip, offset);
if (status > 0) {
status = 1;
clear_bit(FLAG_IS_OUT, &((struct gpio_desc *)desc)->flags);
}
if (status == 0) {
set_bit(FLAG_IS_OUT, &((struct gpio_desc *)desc)->flags);
}
return status;
}
static ssize_t gpio_direction_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
const struct gpio_desc *desc = dev_get_drvdata(dev);
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
status = gpiod_direction_output(desc, 1);
else if (sysfs_streq(buf, "out") || sysfs_streq(buf, "low"))
status = gpiod_direction_output(desc, 0);
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
if (!test_bit(FLAG_EXPORT, &desc->flags)) {
status = -EIO;
} else {
int value;
value = !!gpiod_get_value_cansleep(desc);
if (test_bit(FLAG_ACTIVE_LOW, &desc->flags))
value = !value;
status = sprintf(buf, "%d\n", value);
}
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
status = strict_strtol(buf, 0, &value);
if (status == 0) {
if (test_bit(FLAG_ACTIVE_LOW, &desc->flags))
value = !value;
gpiod_set_value_cansleep(desc, value != 0);
status = size;
}
}
mutex_unlock(&sysfs_lock);
return status;
}
static irqreturn_t gpio_sysfs_irq(int irq, void *priv)
{
struct sysfs_dirent *value_sd = priv;
sysfs_notify_dirent(value_sd);
return IRQ_HANDLED;
}
static int gpio_setup_irq(struct gpio_desc *desc, struct device *dev,
unsigned long gpio_flags)
{
struct sysfs_dirent *value_sd;
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
value_sd = sysfs_get_dirent(dev->kobj.sd, NULL, "value");
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
status = strict_strtol(buf, 0, &value);
if (status == 0)
status = sysfs_set_active_low(desc, dev, value != 0);
}
mutex_unlock(&sysfs_lock);
return status ? : size;
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
status = strict_strtol(buf, 0, &gpio);
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
status = strict_strtol(buf, 0, &gpio);
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
static int gpiod_export(struct gpio_desc *desc, bool direction_may_change)
{
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
mutex_lock(&sysfs_lock);
spin_lock_irqsave(&gpio_lock, flags);
if (!test_bit(FLAG_REQUESTED, &desc->flags) ||
test_bit(FLAG_EXPORT, &desc->flags)) {
spin_unlock_irqrestore(&gpio_lock, flags);
pr_debug("%s: gpio %d unavailable (requested=%d, exported=%d)\n",
__func__, desc_to_gpio(desc),
test_bit(FLAG_REQUESTED, &desc->flags),
test_bit(FLAG_EXPORT, &desc->flags));
status = -EPERM;
goto fail_unlock;
}
if (!desc->chip->direction_input || !desc->chip->direction_output)
direction_may_change = false;
spin_unlock_irqrestore(&gpio_lock, flags);
offset = gpio_chip_hwgpio(desc);
if (desc->chip->names && desc->chip->names[offset])
ioname = desc->chip->names[offset];
dev = device_create(&gpio_class, desc->chip->dev, MKDEV(0, 0),
desc, ioname ? ioname : "gpio%u",
desc_to_gpio(desc));
if (IS_ERR(dev)) {
status = PTR_ERR(dev);
goto fail_unlock;
}
status = sysfs_create_group(&dev->kobj, &gpio_attr_group);
if (status)
goto fail_unregister_device;
if (direction_may_change) {
status = device_create_file(dev, &dev_attr_direction);
if (status)
goto fail_unregister_device;
}
if (gpiod_to_irq(desc) >= 0 && (direction_may_change ||
!test_bit(FLAG_IS_OUT, &desc->flags))) {
status = device_create_file(dev, &dev_attr_edge);
if (status)
goto fail_unregister_device;
}
set_bit(FLAG_EXPORT, &desc->flags);
mutex_unlock(&sysfs_lock);
return 0;
fail_unregister_device:
device_unregister(dev);
fail_unlock:
mutex_unlock(&sysfs_lock);
pr_debug("%s: gpio%d status %d\n", __func__, desc_to_gpio(desc),
status);
return status;
}
int gpio_export(unsigned gpio, bool direction_may_change)
{
return gpiod_export(gpio_to_desc(gpio), direction_may_change);
}
static int match_export(struct device *dev, const void *data)
{
return dev_get_drvdata(dev) == data;
}
static int gpiod_export_link(struct device *dev, const char *name,
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
} else {
status = -ENODEV;
}
}
mutex_unlock(&sysfs_lock);
if (status)
pr_debug("%s: gpio%d status %d\n", __func__, desc_to_gpio(desc),
status);
return status;
}
int gpio_export_link(struct device *dev, const char *name, unsigned gpio)
{
return gpiod_export_link(dev, name, gpio_to_desc(gpio));
}
static int gpiod_sysfs_set_active_low(struct gpio_desc *desc, int value)
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
unlock:
mutex_unlock(&sysfs_lock);
if (status)
pr_debug("%s: gpio%d status %d\n", __func__, desc_to_gpio(desc),
status);
return status;
}
int gpio_sysfs_set_active_low(unsigned gpio, int value)
{
return gpiod_sysfs_set_active_low(gpio_to_desc(gpio), value);
}
static void gpiod_unexport(struct gpio_desc *desc)
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
pr_debug("%s: gpio%d status %d\n", __func__, desc_to_gpio(desc),
status);
}
void gpio_unexport(unsigned gpio)
{
gpiod_unexport(gpio_to_desc(gpio));
}
static int gpiochip_export(struct gpio_chip *chip)
{
int status;
struct device *dev;
if (!gpio_class.p)
return 0;
mutex_lock(&sysfs_lock);
dev = device_create(&gpio_class, chip->dev, MKDEV(0, 0), chip,
"gpiochip%d", chip->base);
if (!IS_ERR(dev)) {
status = sysfs_create_group(&dev->kobj,
&gpiochip_attr_group);
} else
status = PTR_ERR(dev);
chip->exported = (status == 0);
mutex_unlock(&sysfs_lock);
if (status) {
unsigned long flags;
unsigned gpio;
spin_lock_irqsave(&gpio_lock, flags);
gpio = 0;
while (gpio < chip->ngpio)
chip->desc[gpio++].chip = NULL;
spin_unlock_irqrestore(&gpio_lock, flags);
pr_debug("%s: chip %s status %d\n", __func__,
chip->label, status);
}
return status;
}
static void gpiochip_unexport(struct gpio_chip *chip)
{
int status;
struct device *dev;
mutex_lock(&sysfs_lock);
dev = class_find_device(&gpio_class, NULL, chip, match_export);
if (dev) {
put_device(dev);
device_unregister(dev);
chip->exported = 0;
status = 0;
} else
status = -ENODEV;
mutex_unlock(&sysfs_lock);
if (status)
pr_debug("%s: chip %s status %d\n", __func__,
chip->label, status);
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
if (!chip || chip->exported)
continue;
spin_unlock_irqrestore(&gpio_lock, flags);
status = gpiochip_export(chip);
spin_lock_irqsave(&gpio_lock, flags);
}
spin_unlock_irqrestore(&gpio_lock, flags);
return status;
}
static inline int gpiochip_export(struct gpio_chip *chip)
{
return 0;
}
static inline void gpiochip_unexport(struct gpio_chip *chip)
{
}
static inline int gpiod_export(struct gpio_desc *desc,
bool direction_may_change)
{
return -ENOSYS;
}
static inline int gpiod_export_link(struct device *dev, const char *name,
struct gpio_desc *desc)
{
return -ENOSYS;
}
static inline int gpiod_sysfs_set_active_low(struct gpio_desc *desc, int value)
{
return -ENOSYS;
}
static inline void gpiod_unexport(struct gpio_desc *desc)
{
}
static int gpiochip_add_to_list(struct gpio_chip *chip)
{
struct list_head *pos = &gpio_chips;
struct gpio_chip *_chip;
int err = 0;
list_for_each(pos, &gpio_chips) {
_chip = list_entry(pos, struct gpio_chip, list);
if (_chip->base >= chip->base + chip->ngpio)
break;
}
if (pos != &gpio_chips && pos->prev != &gpio_chips) {
_chip = list_entry(pos->prev, struct gpio_chip, list);
if (_chip->base + _chip->ngpio > chip->base) {
dev_err(chip->dev,
"GPIO integer space overlap, cannot add chip\n");
err = -EBUSY;
}
}
if (!err)
list_add_tail(&chip->list, pos);
return err;
}
int gpiochip_add(struct gpio_chip *chip)
{
unsigned long flags;
int status = 0;
unsigned id;
int base = chip->base;
if ((!gpio_is_valid(base) || !gpio_is_valid(base + chip->ngpio - 1))
&& base >= 0) {
status = -EINVAL;
goto fail;
}
spin_lock_irqsave(&gpio_lock, flags);
if (base < 0) {
base = gpiochip_find_base(chip->ngpio);
if (base < 0) {
status = base;
goto unlock;
}
chip->base = base;
}
status = gpiochip_add_to_list(chip);
if (status == 0) {
chip->desc = &gpio_desc[chip->base];
for (id = 0; id < chip->ngpio; id++) {
struct gpio_desc *desc = &chip->desc[id];
desc->chip = chip;
desc->flags = !chip->direction_input
? (1 << FLAG_IS_OUT)
: 0;
}
}
#ifdef CONFIG_PINCTRL
INIT_LIST_HEAD(&chip->pin_ranges);
#endif
of_gpiochip_add(chip);
unlock:
spin_unlock_irqrestore(&gpio_lock, flags);
if (status)
goto fail;
status = gpiochip_export(chip);
if (status)
goto fail;
pr_debug("gpiochip_add: registered GPIOs %d to %d on device: %s\n",
chip->base, chip->base + chip->ngpio - 1,
chip->label ? : "generic");
return 0;
fail:
pr_err("gpiochip_add: gpios %d..%d (%s) failed to register\n",
chip->base, chip->base + chip->ngpio - 1,
chip->label ? : "generic");
return status;
}
int gpiochip_remove(struct gpio_chip *chip)
{
unsigned long flags;
int status = 0;
unsigned id;
spin_lock_irqsave(&gpio_lock, flags);
gpiochip_remove_pin_ranges(chip);
of_gpiochip_remove(chip);
for (id = 0; id < chip->ngpio; id++) {
if (test_bit(FLAG_REQUESTED, &chip->desc[id].flags)) {
status = -EBUSY;
break;
}
}
if (status == 0) {
for (id = 0; id < chip->ngpio; id++)
chip->desc[id].chip = NULL;
list_del(&chip->list);
}
spin_unlock_irqrestore(&gpio_lock, flags);
if (status == 0)
gpiochip_unexport(chip);
return status;
}
struct gpio_chip *gpiochip_find(void *data,
int (*match)(struct gpio_chip *chip,
void *data))
{
struct gpio_chip *chip;
unsigned long flags;
spin_lock_irqsave(&gpio_lock, flags);
list_for_each_entry(chip, &gpio_chips, list)
if (match(chip, data))
break;
if (&chip->list == &gpio_chips)
chip = NULL;
spin_unlock_irqrestore(&gpio_lock, flags);
return chip;
}
int gpiochip_add_pin_range(struct gpio_chip *chip, const char *pinctl_name,
unsigned int gpio_offset, unsigned int pin_offset,
unsigned int npins)
{
struct gpio_pin_range *pin_range;
int ret;
pin_range = kzalloc(sizeof(*pin_range), GFP_KERNEL);
if (!pin_range) {
pr_err("%s: GPIO chip: failed to allocate pin ranges\n",
chip->label);
return -ENOMEM;
}
pin_range->range.id = gpio_offset;
pin_range->range.gc = chip;
pin_range->range.name = chip->label;
pin_range->range.base = chip->base + gpio_offset;
pin_range->range.pin_base = pin_offset;
pin_range->range.npins = npins;
pin_range->pctldev = pinctrl_find_and_add_gpio_range(pinctl_name,
&pin_range->range);
if (IS_ERR(pin_range->pctldev)) {
ret = PTR_ERR(pin_range->pctldev);
pr_err("%s: GPIO chip: could not create pin range\n",
chip->label);
kfree(pin_range);
return ret;
}
pr_debug("GPIO chip %s: created GPIO range %d->%d ==> %s PIN %d->%d\n",
chip->label, gpio_offset, gpio_offset + npins - 1,
pinctl_name,
pin_offset, pin_offset + npins - 1);
list_add_tail(&pin_range->node, &chip->pin_ranges);
return 0;
}
void gpiochip_remove_pin_ranges(struct gpio_chip *chip)
{
struct gpio_pin_range *pin_range, *tmp;
list_for_each_entry_safe(pin_range, tmp, &chip->pin_ranges, node) {
list_del(&pin_range->node);
pinctrl_remove_gpio_range(pin_range->pctldev,
&pin_range->range);
kfree(pin_range);
}
}
static int gpiod_request(struct gpio_desc *desc, const char *label)
{
struct gpio_chip *chip;
int status = -EPROBE_DEFER;
unsigned long flags;
if (!desc) {
pr_warn("%s: invalid GPIO\n", __func__);
return -EINVAL;
}
spin_lock_irqsave(&gpio_lock, flags);
chip = desc->chip;
if (chip == NULL)
goto done;
if (!try_module_get(chip->owner))
goto done;
if (test_and_set_bit(FLAG_REQUESTED, &desc->flags) == 0) {
desc_set_label(desc, label ? : "?");
status = 0;
} else {
status = -EBUSY;
module_put(chip->owner);
goto done;
}
if (chip->request) {
spin_unlock_irqrestore(&gpio_lock, flags);
status = chip->request(chip, gpio_chip_hwgpio(desc));
spin_lock_irqsave(&gpio_lock, flags);
if (status < 0) {
desc_set_label(desc, NULL);
module_put(chip->owner);
clear_bit(FLAG_REQUESTED, &desc->flags);
goto done;
}
}
if (chip->get_direction) {
spin_unlock_irqrestore(&gpio_lock, flags);
gpiod_get_direction(desc);
spin_lock_irqsave(&gpio_lock, flags);
}
done:
if (status)
pr_debug("_gpio_request: gpio-%d (%s) status %d\n",
desc_to_gpio(desc), label ? : "?", status);
spin_unlock_irqrestore(&gpio_lock, flags);
return status;
}
int gpio_request(unsigned gpio, const char *label)
{
return gpiod_request(gpio_to_desc(gpio), label);
}
static void gpiod_free(struct gpio_desc *desc)
{
unsigned long flags;
struct gpio_chip *chip;
might_sleep();
if (!desc) {
WARN_ON(extra_checks);
return;
}
gpiod_unexport(desc);
spin_lock_irqsave(&gpio_lock, flags);
chip = desc->chip;
if (chip && test_bit(FLAG_REQUESTED, &desc->flags)) {
if (chip->free) {
spin_unlock_irqrestore(&gpio_lock, flags);
might_sleep_if(chip->can_sleep);
chip->free(chip, gpio_chip_hwgpio(desc));
spin_lock_irqsave(&gpio_lock, flags);
}
desc_set_label(desc, NULL);
module_put(desc->chip->owner);
clear_bit(FLAG_ACTIVE_LOW, &desc->flags);
clear_bit(FLAG_REQUESTED, &desc->flags);
clear_bit(FLAG_OPEN_DRAIN, &desc->flags);
clear_bit(FLAG_OPEN_SOURCE, &desc->flags);
} else
WARN_ON(extra_checks);
spin_unlock_irqrestore(&gpio_lock, flags);
}
void gpio_free(unsigned gpio)
{
gpiod_free(gpio_to_desc(gpio));
}
int gpio_request_one(unsigned gpio, unsigned long flags, const char *label)
{
struct gpio_desc *desc;
int err;
desc = gpio_to_desc(gpio);
err = gpiod_request(desc, label);
if (err)
return err;
if (flags & GPIOF_OPEN_DRAIN)
set_bit(FLAG_OPEN_DRAIN, &desc->flags);
if (flags & GPIOF_OPEN_SOURCE)
set_bit(FLAG_OPEN_SOURCE, &desc->flags);
if (flags & GPIOF_DIR_IN)
err = gpiod_direction_input(desc);
else
err = gpiod_direction_output(desc,
(flags & GPIOF_INIT_HIGH) ? 1 : 0);
if (err)
goto free_gpio;
if (flags & GPIOF_EXPORT) {
err = gpiod_export(desc, flags & GPIOF_EXPORT_CHANGEABLE);
if (err)
goto free_gpio;
}
return 0;
free_gpio:
gpiod_free(desc);
return err;
}
int gpio_request_array(const struct gpio *array, size_t num)
{
int i, err;
for (i = 0; i < num; i++, array++) {
err = gpio_request_one(array->gpio, array->flags, array->label);
if (err)
goto err_free;
}
return 0;
err_free:
while (i--)
gpio_free((--array)->gpio);
return err;
}
void gpio_free_array(const struct gpio *array, size_t num)
{
while (num--)
gpio_free((array++)->gpio);
}
const char *gpiochip_is_requested(struct gpio_chip *chip, unsigned offset)
{
struct gpio_desc *desc;
if (!GPIO_OFFSET_VALID(chip, offset))
return NULL;
desc = &chip->desc[offset];
if (test_bit(FLAG_REQUESTED, &desc->flags) == 0)
return NULL;
#ifdef CONFIG_DEBUG_FS
return desc->label;
#else
return "?";
#endif
}
static int gpiod_direction_input(struct gpio_desc *desc)
{
unsigned long flags;
struct gpio_chip *chip;
int status = -EINVAL;
int offset;
if (!desc) {
pr_warn("%s: invalid GPIO\n", __func__);
return -EINVAL;
}
spin_lock_irqsave(&gpio_lock, flags);
chip = desc->chip;
if (!chip || !chip->get || !chip->direction_input)
goto fail;
status = gpio_ensure_requested(desc);
if (status < 0)
goto fail;
spin_unlock_irqrestore(&gpio_lock, flags);
might_sleep_if(chip->can_sleep);
offset = gpio_chip_hwgpio(desc);
if (status) {
status = chip->request(chip, offset);
if (status < 0) {
pr_debug("GPIO-%d: chip request fail, %d\n",
desc_to_gpio(desc), status);
goto lose;
}
}
status = chip->direction_input(chip, offset);
if (status == 0)
clear_bit(FLAG_IS_OUT, &desc->flags);
trace_gpio_direction(desc_to_gpio(desc), 1, status);
lose:
return status;
fail:
spin_unlock_irqrestore(&gpio_lock, flags);
if (status)
pr_debug("%s: gpio-%d status %d\n", __func__,
desc_to_gpio(desc), status);
return status;
}
int gpio_direction_input(unsigned gpio)
{
return gpiod_direction_input(gpio_to_desc(gpio));
}
static int gpiod_direction_output(struct gpio_desc *desc, int value)
{
unsigned long flags;
struct gpio_chip *chip;
int status = -EINVAL;
int offset;
if (!desc) {
pr_warn("%s: invalid GPIO\n", __func__);
return -EINVAL;
}
if (value && test_bit(FLAG_OPEN_DRAIN, &desc->flags))
return gpiod_direction_input(desc);
if (!value && test_bit(FLAG_OPEN_SOURCE, &desc->flags))
return gpiod_direction_input(desc);
spin_lock_irqsave(&gpio_lock, flags);
chip = desc->chip;
if (!chip || !chip->set || !chip->direction_output)
goto fail;
status = gpio_ensure_requested(desc);
if (status < 0)
goto fail;
spin_unlock_irqrestore(&gpio_lock, flags);
might_sleep_if(chip->can_sleep);
offset = gpio_chip_hwgpio(desc);
if (status) {
status = chip->request(chip, offset);
if (status < 0) {
pr_debug("GPIO-%d: chip request fail, %d\n",
desc_to_gpio(desc), status);
goto lose;
}
}
status = chip->direction_output(chip, offset, value);
if (status == 0)
set_bit(FLAG_IS_OUT, &desc->flags);
trace_gpio_value(desc_to_gpio(desc), 0, value);
trace_gpio_direction(desc_to_gpio(desc), 0, status);
lose:
return status;
fail:
spin_unlock_irqrestore(&gpio_lock, flags);
if (status)
pr_debug("%s: gpio-%d status %d\n", __func__,
desc_to_gpio(desc), status);
return status;
}
int gpio_direction_output(unsigned gpio, int value)
{
return gpiod_direction_output(gpio_to_desc(gpio), value);
}
static int gpiod_set_debounce(struct gpio_desc *desc, unsigned debounce)
{
unsigned long flags;
struct gpio_chip *chip;
int status = -EINVAL;
int offset;
if (!desc) {
pr_warn("%s: invalid GPIO\n", __func__);
return -EINVAL;
}
spin_lock_irqsave(&gpio_lock, flags);
chip = desc->chip;
if (!chip || !chip->set || !chip->set_debounce)
goto fail;
status = gpio_ensure_requested(desc);
if (status < 0)
goto fail;
spin_unlock_irqrestore(&gpio_lock, flags);
might_sleep_if(chip->can_sleep);
offset = gpio_chip_hwgpio(desc);
return chip->set_debounce(chip, offset, debounce);
fail:
spin_unlock_irqrestore(&gpio_lock, flags);
if (status)
pr_debug("%s: gpio-%d status %d\n", __func__,
desc_to_gpio(desc), status);
return status;
}
int gpio_set_debounce(unsigned gpio, unsigned debounce)
{
return gpiod_set_debounce(gpio_to_desc(gpio), debounce);
}
static int gpiod_get_value(const struct gpio_desc *desc)
{
struct gpio_chip *chip;
int value;
int offset;
if (!desc)
return 0;
chip = desc->chip;
offset = gpio_chip_hwgpio(desc);
WARN_ON(chip->can_sleep);
value = chip->get ? chip->get(chip, offset) : 0;
trace_gpio_value(desc_to_gpio(desc), 1, value);
return value;
}
int __gpio_get_value(unsigned gpio)
{
return gpiod_get_value(gpio_to_desc(gpio));
}
static void _gpio_set_open_drain_value(struct gpio_desc *desc, int value)
{
int err = 0;
struct gpio_chip *chip = desc->chip;
int offset = gpio_chip_hwgpio(desc);
if (value) {
err = chip->direction_input(chip, offset);
if (!err)
clear_bit(FLAG_IS_OUT, &desc->flags);
} else {
err = chip->direction_output(chip, offset, 0);
if (!err)
set_bit(FLAG_IS_OUT, &desc->flags);
}
trace_gpio_direction(desc_to_gpio(desc), value, err);
if (err < 0)
pr_err("%s: Error in set_value for open drain gpio%d err %d\n",
__func__, desc_to_gpio(desc), err);
}
static void _gpio_set_open_source_value(struct gpio_desc *desc, int value)
{
int err = 0;
struct gpio_chip *chip = desc->chip;
int offset = gpio_chip_hwgpio(desc);
if (value) {
err = chip->direction_output(chip, offset, 1);
if (!err)
set_bit(FLAG_IS_OUT, &desc->flags);
} else {
err = chip->direction_input(chip, offset);
if (!err)
clear_bit(FLAG_IS_OUT, &desc->flags);
}
trace_gpio_direction(desc_to_gpio(desc), !value, err);
if (err < 0)
pr_err("%s: Error in set_value for open source gpio%d err %d\n",
__func__, desc_to_gpio(desc), err);
}
static void gpiod_set_value(struct gpio_desc *desc, int value)
{
struct gpio_chip *chip;
if (!desc)
return;
chip = desc->chip;
WARN_ON(chip->can_sleep);
trace_gpio_value(desc_to_gpio(desc), 0, value);
if (test_bit(FLAG_OPEN_DRAIN, &desc->flags))
_gpio_set_open_drain_value(desc, value);
else if (test_bit(FLAG_OPEN_SOURCE, &desc->flags))
_gpio_set_open_source_value(desc, value);
else
chip->set(chip, gpio_chip_hwgpio(desc), value);
}
void __gpio_set_value(unsigned gpio, int value)
{
return gpiod_set_value(gpio_to_desc(gpio), value);
}
static int gpiod_cansleep(const struct gpio_desc *desc)
{
if (!desc)
return 0;
return desc->chip->can_sleep;
}
int __gpio_cansleep(unsigned gpio)
{
return gpiod_cansleep(gpio_to_desc(gpio));
}
static int gpiod_to_irq(const struct gpio_desc *desc)
{
struct gpio_chip *chip;
int offset;
if (!desc)
return -EINVAL;
chip = desc->chip;
offset = gpio_chip_hwgpio(desc);
return chip->to_irq ? chip->to_irq(chip, offset) : -ENXIO;
}
int __gpio_to_irq(unsigned gpio)
{
return gpiod_to_irq(gpio_to_desc(gpio));
}
static int gpiod_get_value_cansleep(const struct gpio_desc *desc)
{
struct gpio_chip *chip;
int value;
int offset;
might_sleep_if(extra_checks);
if (!desc)
return 0;
chip = desc->chip;
offset = gpio_chip_hwgpio(desc);
value = chip->get ? chip->get(chip, offset) : 0;
trace_gpio_value(desc_to_gpio(desc), 1, value);
return value;
}
int gpio_get_value_cansleep(unsigned gpio)
{
return gpiod_get_value_cansleep(gpio_to_desc(gpio));
}
static void gpiod_set_value_cansleep(struct gpio_desc *desc, int value)
{
struct gpio_chip *chip;
might_sleep_if(extra_checks);
if (!desc)
return;
chip = desc->chip;
trace_gpio_value(desc_to_gpio(desc), 0, value);
if (test_bit(FLAG_OPEN_DRAIN, &desc->flags))
_gpio_set_open_drain_value(desc, value);
else if (test_bit(FLAG_OPEN_SOURCE, &desc->flags))
_gpio_set_open_source_value(desc, value);
else
chip->set(chip, gpio_chip_hwgpio(desc), value);
}
void gpio_set_value_cansleep(unsigned gpio, int value)
{
return gpiod_set_value_cansleep(gpio_to_desc(gpio), value);
}
static void gpiolib_dbg_show(struct seq_file *s, struct gpio_chip *chip)
{
unsigned i;
unsigned gpio = chip->base;
struct gpio_desc *gdesc = &chip->desc[0];
int is_out;
for (i = 0; i < chip->ngpio; i++, gpio++, gdesc++) {
if (!test_bit(FLAG_REQUESTED, &gdesc->flags))
continue;
gpiod_get_direction(gdesc);
is_out = test_bit(FLAG_IS_OUT, &gdesc->flags);
seq_printf(s, " gpio-%-3d (%-20.20s) %s %s",
gpio, gdesc->label,
is_out ? "out" : "in ",
chip->get
? (chip->get(chip, i) ? "hi" : "lo")
: "? ");
seq_printf(s, "\n");
}
}
static void *gpiolib_seq_start(struct seq_file *s, loff_t *pos)
{
unsigned long flags;
struct gpio_chip *chip = NULL;
loff_t index = *pos;
s->private = "";
spin_lock_irqsave(&gpio_lock, flags);
list_for_each_entry(chip, &gpio_chips, list)
if (index-- == 0) {
spin_unlock_irqrestore(&gpio_lock, flags);
return chip;
}
spin_unlock_irqrestore(&gpio_lock, flags);
return NULL;
}
static void *gpiolib_seq_next(struct seq_file *s, void *v, loff_t *pos)
{
unsigned long flags;
struct gpio_chip *chip = v;
void *ret = NULL;
spin_lock_irqsave(&gpio_lock, flags);
if (list_is_last(&chip->list, &gpio_chips))
ret = NULL;
else
ret = list_entry(chip->list.next, struct gpio_chip, list);
spin_unlock_irqrestore(&gpio_lock, flags);
s->private = "\n";
++*pos;
return ret;
}
static void gpiolib_seq_stop(struct seq_file *s, void *v)
{
}
static int gpiolib_seq_show(struct seq_file *s, void *v)
{
struct gpio_chip *chip = v;
struct device *dev;
seq_printf(s, "%sGPIOs %d-%d", (char *)s->private,
chip->base, chip->base + chip->ngpio - 1);
dev = chip->dev;
if (dev)
seq_printf(s, ", %s/%s", dev->bus ? dev->bus->name : "no-bus",
dev_name(dev));
if (chip->label)
seq_printf(s, ", %s", chip->label);
if (chip->can_sleep)
seq_printf(s, ", can sleep");
seq_printf(s, ":\n");
if (chip->dbg_show)
chip->dbg_show(s, chip);
else
gpiolib_dbg_show(s, chip);
return 0;
}
static int gpiolib_open(struct inode *inode, struct file *file)
{
return seq_open(file, &gpiolib_seq_ops);
}
static int __init gpiolib_debugfs_init(void)
{
(void) debugfs_create_file("gpio", S_IFREG | S_IRUGO,
NULL, NULL, &gpiolib_operations);
return 0;
}
