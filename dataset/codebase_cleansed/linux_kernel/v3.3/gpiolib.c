static inline void desc_set_label(struct gpio_desc *d, const char *label)
{
#ifdef CONFIG_DEBUG_FS
d->label = label;
#endif
}
static int gpio_ensure_requested(struct gpio_desc *desc, unsigned offset)
{
const struct gpio_chip *chip = desc->chip;
const int gpio = chip->base + offset;
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
struct gpio_chip *gpio_to_chip(unsigned gpio)
{
return gpio_desc[gpio].chip;
}
static int gpiochip_find_base(int ngpio)
{
int i;
int spare = 0;
int base = -ENOSPC;
for (i = ARCH_NR_GPIOS - 1; i >= 0 ; i--) {
struct gpio_desc *desc = &gpio_desc[i];
struct gpio_chip *chip = desc->chip;
if (!chip && !test_bit(FLAG_RESERVED, &desc->flags)) {
spare++;
if (spare == ngpio) {
base = i;
break;
}
} else {
spare = 0;
if (chip)
i -= chip->ngpio - 1;
}
}
if (gpio_is_valid(base))
pr_debug("%s: found new base at %d\n", __func__, base);
return base;
}
int __init gpiochip_reserve(int start, int ngpio)
{
int ret = 0;
unsigned long flags;
int i;
if (!gpio_is_valid(start) || !gpio_is_valid(start + ngpio - 1))
return -EINVAL;
spin_lock_irqsave(&gpio_lock, flags);
for (i = start; i < start + ngpio; i++) {
struct gpio_desc *desc = &gpio_desc[i];
if (desc->chip || test_bit(FLAG_RESERVED, &desc->flags)) {
ret = -EBUSY;
goto err;
}
set_bit(FLAG_RESERVED, &desc->flags);
}
pr_debug("%s: reserved gpios from %d to %d\n",
__func__, start, start + ngpio - 1);
err:
spin_unlock_irqrestore(&gpio_lock, flags);
return ret;
}
static ssize_t gpio_direction_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
const struct gpio_desc *desc = dev_get_drvdata(dev);
ssize_t status;
mutex_lock(&sysfs_lock);
if (!test_bit(FLAG_EXPORT, &desc->flags))
status = -EIO;
else
status = sprintf(buf, "%s\n",
test_bit(FLAG_IS_OUT, &desc->flags)
? "out" : "in");
mutex_unlock(&sysfs_lock);
return status;
}
static ssize_t gpio_direction_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
const struct gpio_desc *desc = dev_get_drvdata(dev);
unsigned gpio = desc - gpio_desc;
ssize_t status;
mutex_lock(&sysfs_lock);
if (!test_bit(FLAG_EXPORT, &desc->flags))
status = -EIO;
else if (sysfs_streq(buf, "high"))
status = gpio_direction_output(gpio, 1);
else if (sysfs_streq(buf, "out") || sysfs_streq(buf, "low"))
status = gpio_direction_output(gpio, 0);
else if (sysfs_streq(buf, "in"))
status = gpio_direction_input(gpio);
else
status = -EINVAL;
mutex_unlock(&sysfs_lock);
return status ? : size;
}
static ssize_t gpio_value_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
const struct gpio_desc *desc = dev_get_drvdata(dev);
unsigned gpio = desc - gpio_desc;
ssize_t status;
mutex_lock(&sysfs_lock);
if (!test_bit(FLAG_EXPORT, &desc->flags)) {
status = -EIO;
} else {
int value;
value = !!gpio_get_value_cansleep(gpio);
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
const struct gpio_desc *desc = dev_get_drvdata(dev);
unsigned gpio = desc - gpio_desc;
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
gpio_set_value_cansleep(gpio, value != 0);
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
irq = gpio_to_irq(desc - gpio_desc);
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
do {
ret = -ENOMEM;
if (idr_pre_get(&dirent_idr, GFP_KERNEL))
ret = idr_get_new_above(&dirent_idr, value_sd,
1, &id);
} while (ret == -EAGAIN);
if (ret)
goto free_sd;
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
int status;
status = strict_strtol(buf, 0, &gpio);
if (status < 0)
goto done;
status = gpio_request(gpio, "sysfs");
if (status < 0)
goto done;
status = gpio_export(gpio, true);
if (status < 0)
gpio_free(gpio);
else
set_bit(FLAG_SYSFS, &gpio_desc[gpio].flags);
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
int status;
status = strict_strtol(buf, 0, &gpio);
if (status < 0)
goto done;
status = -EINVAL;
if (!gpio_is_valid(gpio))
goto done;
if (test_and_clear_bit(FLAG_SYSFS, &gpio_desc[gpio].flags)) {
status = 0;
gpio_free(gpio);
}
done:
if (status)
pr_debug("%s: status %d\n", __func__, status);
return status ? : len;
}
int gpio_export(unsigned gpio, bool direction_may_change)
{
unsigned long flags;
struct gpio_desc *desc;
int status = -EINVAL;
const char *ioname = NULL;
if (!gpio_class.p) {
pr_debug("%s: called too early!\n", __func__);
return -ENOENT;
}
if (!gpio_is_valid(gpio))
goto done;
mutex_lock(&sysfs_lock);
spin_lock_irqsave(&gpio_lock, flags);
desc = &gpio_desc[gpio];
if (test_bit(FLAG_REQUESTED, &desc->flags)
&& !test_bit(FLAG_EXPORT, &desc->flags)) {
status = 0;
if (!desc->chip->direction_input
|| !desc->chip->direction_output)
direction_may_change = false;
}
spin_unlock_irqrestore(&gpio_lock, flags);
if (desc->chip->names && desc->chip->names[gpio - desc->chip->base])
ioname = desc->chip->names[gpio - desc->chip->base];
if (status == 0) {
struct device *dev;
dev = device_create(&gpio_class, desc->chip->dev, MKDEV(0, 0),
desc, ioname ? ioname : "gpio%u", gpio);
if (!IS_ERR(dev)) {
status = sysfs_create_group(&dev->kobj,
&gpio_attr_group);
if (!status && direction_may_change)
status = device_create_file(dev,
&dev_attr_direction);
if (!status && gpio_to_irq(gpio) >= 0
&& (direction_may_change
|| !test_bit(FLAG_IS_OUT,
&desc->flags)))
status = device_create_file(dev,
&dev_attr_edge);
if (status != 0)
device_unregister(dev);
} else
status = PTR_ERR(dev);
if (status == 0)
set_bit(FLAG_EXPORT, &desc->flags);
}
mutex_unlock(&sysfs_lock);
done:
if (status)
pr_debug("%s: gpio%d status %d\n", __func__, gpio, status);
return status;
}
static int match_export(struct device *dev, void *data)
{
return dev_get_drvdata(dev) == data;
}
int gpio_export_link(struct device *dev, const char *name, unsigned gpio)
{
struct gpio_desc *desc;
int status = -EINVAL;
if (!gpio_is_valid(gpio))
goto done;
mutex_lock(&sysfs_lock);
desc = &gpio_desc[gpio];
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
done:
if (status)
pr_debug("%s: gpio%d status %d\n", __func__, gpio, status);
return status;
}
int gpio_sysfs_set_active_low(unsigned gpio, int value)
{
struct gpio_desc *desc;
struct device *dev = NULL;
int status = -EINVAL;
if (!gpio_is_valid(gpio))
goto done;
mutex_lock(&sysfs_lock);
desc = &gpio_desc[gpio];
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
done:
if (status)
pr_debug("%s: gpio%d status %d\n", __func__, gpio, status);
return status;
}
void gpio_unexport(unsigned gpio)
{
struct gpio_desc *desc;
int status = 0;
if (!gpio_is_valid(gpio)) {
status = -EINVAL;
goto done;
}
mutex_lock(&sysfs_lock);
desc = &gpio_desc[gpio];
if (test_bit(FLAG_EXPORT, &desc->flags)) {
struct device *dev = NULL;
dev = class_find_device(&gpio_class, NULL, desc, match_export);
if (dev) {
gpio_setup_irq(desc, dev, 0);
clear_bit(FLAG_EXPORT, &desc->flags);
put_device(dev);
device_unregister(dev);
} else
status = -ENODEV;
}
mutex_unlock(&sysfs_lock);
done:
if (status)
pr_debug("%s: gpio%d status %d\n", __func__, gpio, status);
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
gpio = chip->base;
while (gpio_desc[gpio].chip == chip)
gpio_desc[gpio++].chip = NULL;
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
unsigned gpio;
status = class_register(&gpio_class);
if (status < 0)
return status;
spin_lock_irqsave(&gpio_lock, flags);
for (gpio = 0; gpio < ARCH_NR_GPIOS; gpio++) {
struct gpio_chip *chip;
chip = gpio_desc[gpio].chip;
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
for (id = base; id < base + chip->ngpio; id++) {
if (gpio_desc[id].chip != NULL) {
status = -EBUSY;
break;
}
}
if (status == 0) {
for (id = base; id < base + chip->ngpio; id++) {
gpio_desc[id].chip = chip;
gpio_desc[id].flags = !chip->direction_input
? (1 << FLAG_IS_OUT)
: 0;
}
}
of_gpiochip_add(chip);
unlock:
spin_unlock_irqrestore(&gpio_lock, flags);
if (status)
goto fail;
status = gpiochip_export(chip);
if (status)
goto fail;
pr_info("gpiochip_add: registered GPIOs %d to %d on device: %s\n",
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
of_gpiochip_remove(chip);
for (id = chip->base; id < chip->base + chip->ngpio; id++) {
if (test_bit(FLAG_REQUESTED, &gpio_desc[id].flags)) {
status = -EBUSY;
break;
}
}
if (status == 0) {
for (id = chip->base; id < chip->base + chip->ngpio; id++)
gpio_desc[id].chip = NULL;
}
spin_unlock_irqrestore(&gpio_lock, flags);
if (status == 0)
gpiochip_unexport(chip);
return status;
}
struct gpio_chip *gpiochip_find(void *data,
int (*match)(struct gpio_chip *chip, void *data))
{
struct gpio_chip *chip = NULL;
unsigned long flags;
int i;
spin_lock_irqsave(&gpio_lock, flags);
for (i = 0; i < ARCH_NR_GPIOS; i++) {
if (!gpio_desc[i].chip)
continue;
if (match(gpio_desc[i].chip, data)) {
chip = gpio_desc[i].chip;
break;
}
}
spin_unlock_irqrestore(&gpio_lock, flags);
return chip;
}
int gpio_request(unsigned gpio, const char *label)
{
struct gpio_desc *desc;
struct gpio_chip *chip;
int status = -EINVAL;
unsigned long flags;
spin_lock_irqsave(&gpio_lock, flags);
if (!gpio_is_valid(gpio))
goto done;
desc = &gpio_desc[gpio];
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
status = chip->request(chip, gpio - chip->base);
spin_lock_irqsave(&gpio_lock, flags);
if (status < 0) {
desc_set_label(desc, NULL);
module_put(chip->owner);
clear_bit(FLAG_REQUESTED, &desc->flags);
}
}
done:
if (status)
pr_debug("gpio_request: gpio-%d (%s) status %d\n",
gpio, label ? : "?", status);
spin_unlock_irqrestore(&gpio_lock, flags);
return status;
}
void gpio_free(unsigned gpio)
{
unsigned long flags;
struct gpio_desc *desc;
struct gpio_chip *chip;
might_sleep();
if (!gpio_is_valid(gpio)) {
WARN_ON(extra_checks);
return;
}
gpio_unexport(gpio);
spin_lock_irqsave(&gpio_lock, flags);
desc = &gpio_desc[gpio];
chip = desc->chip;
if (chip && test_bit(FLAG_REQUESTED, &desc->flags)) {
if (chip->free) {
spin_unlock_irqrestore(&gpio_lock, flags);
might_sleep_if(chip->can_sleep);
chip->free(chip, gpio - chip->base);
spin_lock_irqsave(&gpio_lock, flags);
}
desc_set_label(desc, NULL);
module_put(desc->chip->owner);
clear_bit(FLAG_ACTIVE_LOW, &desc->flags);
clear_bit(FLAG_REQUESTED, &desc->flags);
} else
WARN_ON(extra_checks);
spin_unlock_irqrestore(&gpio_lock, flags);
}
int gpio_request_one(unsigned gpio, unsigned long flags, const char *label)
{
int err;
err = gpio_request(gpio, label);
if (err)
return err;
if (flags & GPIOF_DIR_IN)
err = gpio_direction_input(gpio);
else
err = gpio_direction_output(gpio,
(flags & GPIOF_INIT_HIGH) ? 1 : 0);
if (err)
gpio_free(gpio);
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
unsigned gpio = chip->base + offset;
if (!gpio_is_valid(gpio) || gpio_desc[gpio].chip != chip)
return NULL;
if (test_bit(FLAG_REQUESTED, &gpio_desc[gpio].flags) == 0)
return NULL;
#ifdef CONFIG_DEBUG_FS
return gpio_desc[gpio].label;
#else
return "?";
#endif
}
int gpio_direction_input(unsigned gpio)
{
unsigned long flags;
struct gpio_chip *chip;
struct gpio_desc *desc = &gpio_desc[gpio];
int status = -EINVAL;
spin_lock_irqsave(&gpio_lock, flags);
if (!gpio_is_valid(gpio))
goto fail;
chip = desc->chip;
if (!chip || !chip->get || !chip->direction_input)
goto fail;
gpio -= chip->base;
if (gpio >= chip->ngpio)
goto fail;
status = gpio_ensure_requested(desc, gpio);
if (status < 0)
goto fail;
spin_unlock_irqrestore(&gpio_lock, flags);
might_sleep_if(chip->can_sleep);
if (status) {
status = chip->request(chip, gpio);
if (status < 0) {
pr_debug("GPIO-%d: chip request fail, %d\n",
chip->base + gpio, status);
goto lose;
}
}
status = chip->direction_input(chip, gpio);
if (status == 0)
clear_bit(FLAG_IS_OUT, &desc->flags);
trace_gpio_direction(chip->base + gpio, 1, status);
lose:
return status;
fail:
spin_unlock_irqrestore(&gpio_lock, flags);
if (status)
pr_debug("%s: gpio-%d status %d\n",
__func__, gpio, status);
return status;
}
int gpio_direction_output(unsigned gpio, int value)
{
unsigned long flags;
struct gpio_chip *chip;
struct gpio_desc *desc = &gpio_desc[gpio];
int status = -EINVAL;
spin_lock_irqsave(&gpio_lock, flags);
if (!gpio_is_valid(gpio))
goto fail;
chip = desc->chip;
if (!chip || !chip->set || !chip->direction_output)
goto fail;
gpio -= chip->base;
if (gpio >= chip->ngpio)
goto fail;
status = gpio_ensure_requested(desc, gpio);
if (status < 0)
goto fail;
spin_unlock_irqrestore(&gpio_lock, flags);
might_sleep_if(chip->can_sleep);
if (status) {
status = chip->request(chip, gpio);
if (status < 0) {
pr_debug("GPIO-%d: chip request fail, %d\n",
chip->base + gpio, status);
goto lose;
}
}
status = chip->direction_output(chip, gpio, value);
if (status == 0)
set_bit(FLAG_IS_OUT, &desc->flags);
trace_gpio_value(chip->base + gpio, 0, value);
trace_gpio_direction(chip->base + gpio, 0, status);
lose:
return status;
fail:
spin_unlock_irqrestore(&gpio_lock, flags);
if (status)
pr_debug("%s: gpio-%d status %d\n",
__func__, gpio, status);
return status;
}
int gpio_set_debounce(unsigned gpio, unsigned debounce)
{
unsigned long flags;
struct gpio_chip *chip;
struct gpio_desc *desc = &gpio_desc[gpio];
int status = -EINVAL;
spin_lock_irqsave(&gpio_lock, flags);
if (!gpio_is_valid(gpio))
goto fail;
chip = desc->chip;
if (!chip || !chip->set || !chip->set_debounce)
goto fail;
gpio -= chip->base;
if (gpio >= chip->ngpio)
goto fail;
status = gpio_ensure_requested(desc, gpio);
if (status < 0)
goto fail;
spin_unlock_irqrestore(&gpio_lock, flags);
might_sleep_if(chip->can_sleep);
return chip->set_debounce(chip, gpio, debounce);
fail:
spin_unlock_irqrestore(&gpio_lock, flags);
if (status)
pr_debug("%s: gpio-%d status %d\n",
__func__, gpio, status);
return status;
}
int __gpio_get_value(unsigned gpio)
{
struct gpio_chip *chip;
int value;
chip = gpio_to_chip(gpio);
WARN_ON(chip->can_sleep);
value = chip->get ? chip->get(chip, gpio - chip->base) : 0;
trace_gpio_value(gpio, 1, value);
return value;
}
void __gpio_set_value(unsigned gpio, int value)
{
struct gpio_chip *chip;
chip = gpio_to_chip(gpio);
WARN_ON(chip->can_sleep);
trace_gpio_value(gpio, 0, value);
chip->set(chip, gpio - chip->base, value);
}
int __gpio_cansleep(unsigned gpio)
{
struct gpio_chip *chip;
chip = gpio_to_chip(gpio);
return chip->can_sleep;
}
int __gpio_to_irq(unsigned gpio)
{
struct gpio_chip *chip;
chip = gpio_to_chip(gpio);
return chip->to_irq ? chip->to_irq(chip, gpio - chip->base) : -ENXIO;
}
int gpio_get_value_cansleep(unsigned gpio)
{
struct gpio_chip *chip;
int value;
might_sleep_if(extra_checks);
chip = gpio_to_chip(gpio);
value = chip->get ? chip->get(chip, gpio - chip->base) : 0;
trace_gpio_value(gpio, 1, value);
return value;
}
void gpio_set_value_cansleep(unsigned gpio, int value)
{
struct gpio_chip *chip;
might_sleep_if(extra_checks);
chip = gpio_to_chip(gpio);
trace_gpio_value(gpio, 0, value);
chip->set(chip, gpio - chip->base, value);
}
static void gpiolib_dbg_show(struct seq_file *s, struct gpio_chip *chip)
{
unsigned i;
unsigned gpio = chip->base;
struct gpio_desc *gdesc = &gpio_desc[gpio];
int is_out;
for (i = 0; i < chip->ngpio; i++, gpio++, gdesc++) {
if (!test_bit(FLAG_REQUESTED, &gdesc->flags))
continue;
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
static int gpiolib_show(struct seq_file *s, void *unused)
{
struct gpio_chip *chip = NULL;
unsigned gpio;
int started = 0;
for (gpio = 0; gpio_is_valid(gpio); gpio++) {
struct device *dev;
if (chip == gpio_desc[gpio].chip)
continue;
chip = gpio_desc[gpio].chip;
if (!chip)
continue;
seq_printf(s, "%sGPIOs %d-%d",
started ? "\n" : "",
chip->base, chip->base + chip->ngpio - 1);
dev = chip->dev;
if (dev)
seq_printf(s, ", %s/%s",
dev->bus ? dev->bus->name : "no-bus",
dev_name(dev));
if (chip->label)
seq_printf(s, ", %s", chip->label);
if (chip->can_sleep)
seq_printf(s, ", can sleep");
seq_printf(s, ":\n");
started = 1;
if (chip->dbg_show)
chip->dbg_show(s, chip);
else
gpiolib_dbg_show(s, chip);
}
return 0;
}
static int gpiolib_open(struct inode *inode, struct file *file)
{
return single_open(file, gpiolib_show, NULL);
}
static int __init gpiolib_debugfs_init(void)
{
(void) debugfs_create_file("gpio", S_IFREG | S_IRUGO,
NULL, NULL, &gpiolib_operations);
return 0;
}
