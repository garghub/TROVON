static inline void desc_set_label(struct gpio_desc *d, const char *label)
{
d->label = label;
}
struct gpio_desc *gpio_to_desc(unsigned gpio)
{
struct gpio_device *gdev;
unsigned long flags;
spin_lock_irqsave(&gpio_lock, flags);
list_for_each_entry(gdev, &gpio_devices, list) {
if (gdev->base <= gpio &&
gdev->base + gdev->ngpio > gpio) {
spin_unlock_irqrestore(&gpio_lock, flags);
return &gdev->descs[gpio - gdev->base];
}
}
spin_unlock_irqrestore(&gpio_lock, flags);
if (!gpio_is_valid(gpio))
WARN(1, "invalid GPIO %d\n", gpio);
return NULL;
}
struct gpio_desc *gpiochip_get_desc(struct gpio_chip *chip,
u16 hwnum)
{
struct gpio_device *gdev = chip->gpiodev;
if (hwnum >= gdev->ngpio)
return ERR_PTR(-EINVAL);
return &gdev->descs[hwnum];
}
int desc_to_gpio(const struct gpio_desc *desc)
{
return desc->gdev->base + (desc - &desc->gdev->descs[0]);
}
struct gpio_chip *gpiod_to_chip(const struct gpio_desc *desc)
{
if (!desc || !desc->gdev || !desc->gdev->chip)
return NULL;
return desc->gdev->chip;
}
static int gpiochip_find_base(int ngpio)
{
struct gpio_device *gdev;
int base = ARCH_NR_GPIOS - ngpio;
list_for_each_entry_reverse(gdev, &gpio_devices, list) {
if (gdev->base + gdev->ngpio <= base)
break;
else
base = gdev->base - ngpio;
}
if (gpio_is_valid(base)) {
pr_debug("%s: found new base at %d\n", __func__, base);
return base;
} else {
pr_err("%s: cannot find free range\n", __func__);
return -ENOSPC;
}
}
int gpiod_get_direction(struct gpio_desc *desc)
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
clear_bit(FLAG_IS_OUT, &desc->flags);
}
if (status == 0) {
set_bit(FLAG_IS_OUT, &desc->flags);
}
return status;
}
static int gpiodev_add_to_list(struct gpio_device *gdev)
{
struct gpio_device *prev, *next;
if (list_empty(&gpio_devices)) {
list_add_tail(&gdev->list, &gpio_devices);
return 0;
}
next = list_entry(gpio_devices.next, struct gpio_device, list);
if (gdev->base + gdev->ngpio <= next->base) {
list_add(&gdev->list, &gpio_devices);
return 0;
}
prev = list_entry(gpio_devices.prev, struct gpio_device, list);
if (prev->base + prev->ngpio <= gdev->base) {
list_add_tail(&gdev->list, &gpio_devices);
return 0;
}
list_for_each_entry_safe(prev, next, &gpio_devices, list) {
if (&next->list == &gpio_devices)
break;
if (prev->base + prev->ngpio <= gdev->base
&& gdev->base + gdev->ngpio <= next->base) {
list_add(&gdev->list, &prev->list);
return 0;
}
}
dev_err(&gdev->dev, "GPIO integer space overlap, cannot add chip\n");
return -EBUSY;
}
static struct gpio_desc *gpio_name_to_desc(const char * const name)
{
struct gpio_device *gdev;
unsigned long flags;
spin_lock_irqsave(&gpio_lock, flags);
list_for_each_entry(gdev, &gpio_devices, list) {
int i;
for (i = 0; i != gdev->ngpio; ++i) {
struct gpio_desc *desc = &gdev->descs[i];
if (!desc->name || !name)
continue;
if (!strcmp(desc->name, name)) {
spin_unlock_irqrestore(&gpio_lock, flags);
return desc;
}
}
}
spin_unlock_irqrestore(&gpio_lock, flags);
return NULL;
}
static int gpiochip_set_desc_names(struct gpio_chip *gc)
{
struct gpio_device *gdev = gc->gpiodev;
int i;
if (!gc->names)
return 0;
for (i = 0; i != gc->ngpio; ++i) {
struct gpio_desc *gpio;
gpio = gpio_name_to_desc(gc->names[i]);
if (gpio)
dev_warn(&gdev->dev,
"Detected name collision for GPIO name '%s'\n",
gc->names[i]);
}
for (i = 0; i != gc->ngpio; ++i)
gdev->descs[i].name = gc->names[i];
return 0;
}
static long linehandle_ioctl(struct file *filep, unsigned int cmd,
unsigned long arg)
{
struct linehandle_state *lh = filep->private_data;
void __user *ip = (void __user *)arg;
struct gpiohandle_data ghd;
int i;
if (cmd == GPIOHANDLE_GET_LINE_VALUES_IOCTL) {
int val;
memset(&ghd, 0, sizeof(ghd));
for (i = 0; i < lh->numdescs; i++) {
val = gpiod_get_value_cansleep(lh->descs[i]);
if (val < 0)
return val;
ghd.values[i] = val;
}
if (copy_to_user(ip, &ghd, sizeof(ghd)))
return -EFAULT;
return 0;
} else if (cmd == GPIOHANDLE_SET_LINE_VALUES_IOCTL) {
int vals[GPIOHANDLES_MAX];
if (copy_from_user(&ghd, ip, sizeof(ghd)))
return -EFAULT;
for (i = 0; i < lh->numdescs; i++)
vals[i] = !!ghd.values[i];
gpiod_set_array_value_complex(false,
true,
lh->numdescs,
lh->descs,
vals);
return 0;
}
return -EINVAL;
}
static long linehandle_ioctl_compat(struct file *filep, unsigned int cmd,
unsigned long arg)
{
return linehandle_ioctl(filep, cmd, (unsigned long)compat_ptr(arg));
}
static int linehandle_release(struct inode *inode, struct file *filep)
{
struct linehandle_state *lh = filep->private_data;
struct gpio_device *gdev = lh->gdev;
int i;
for (i = 0; i < lh->numdescs; i++)
gpiod_free(lh->descs[i]);
kfree(lh->label);
kfree(lh);
put_device(&gdev->dev);
return 0;
}
static int linehandle_create(struct gpio_device *gdev, void __user *ip)
{
struct gpiohandle_request handlereq;
struct linehandle_state *lh;
struct file *file;
int fd, i, ret;
if (copy_from_user(&handlereq, ip, sizeof(handlereq)))
return -EFAULT;
if ((handlereq.lines == 0) || (handlereq.lines > GPIOHANDLES_MAX))
return -EINVAL;
lh = kzalloc(sizeof(*lh), GFP_KERNEL);
if (!lh)
return -ENOMEM;
lh->gdev = gdev;
get_device(&gdev->dev);
handlereq.consumer_label[sizeof(handlereq.consumer_label)-1] = '\0';
if (strlen(handlereq.consumer_label)) {
lh->label = kstrdup(handlereq.consumer_label,
GFP_KERNEL);
if (!lh->label) {
ret = -ENOMEM;
goto out_free_lh;
}
}
for (i = 0; i < handlereq.lines; i++) {
u32 offset = handlereq.lineoffsets[i];
u32 lflags = handlereq.flags;
struct gpio_desc *desc;
if (offset >= gdev->ngpio) {
ret = -EINVAL;
goto out_free_descs;
}
if (lflags & ~GPIOHANDLE_REQUEST_VALID_FLAGS) {
ret = -EINVAL;
goto out_free_descs;
}
desc = &gdev->descs[offset];
ret = gpiod_request(desc, lh->label);
if (ret)
goto out_free_descs;
lh->descs[i] = desc;
if (lflags & GPIOHANDLE_REQUEST_ACTIVE_LOW)
set_bit(FLAG_ACTIVE_LOW, &desc->flags);
if (lflags & GPIOHANDLE_REQUEST_OPEN_DRAIN)
set_bit(FLAG_OPEN_DRAIN, &desc->flags);
if (lflags & GPIOHANDLE_REQUEST_OPEN_SOURCE)
set_bit(FLAG_OPEN_SOURCE, &desc->flags);
if (lflags & GPIOHANDLE_REQUEST_OUTPUT) {
int val = !!handlereq.default_values[i];
ret = gpiod_direction_output(desc, val);
if (ret)
goto out_free_descs;
} else if (lflags & GPIOHANDLE_REQUEST_INPUT) {
ret = gpiod_direction_input(desc);
if (ret)
goto out_free_descs;
}
dev_dbg(&gdev->dev, "registered chardev handle for line %d\n",
offset);
}
i--;
lh->numdescs = handlereq.lines;
fd = get_unused_fd_flags(O_RDONLY | O_CLOEXEC);
if (fd < 0) {
ret = fd;
goto out_free_descs;
}
file = anon_inode_getfile("gpio-linehandle",
&linehandle_fileops,
lh,
O_RDONLY | O_CLOEXEC);
if (IS_ERR(file)) {
ret = PTR_ERR(file);
goto out_put_unused_fd;
}
handlereq.fd = fd;
if (copy_to_user(ip, &handlereq, sizeof(handlereq))) {
fput(file);
put_unused_fd(fd);
return -EFAULT;
}
fd_install(fd, file);
dev_dbg(&gdev->dev, "registered chardev handle for %d lines\n",
lh->numdescs);
return 0;
out_put_unused_fd:
put_unused_fd(fd);
out_free_descs:
for (; i >= 0; i--)
gpiod_free(lh->descs[i]);
kfree(lh->label);
out_free_lh:
kfree(lh);
put_device(&gdev->dev);
return ret;
}
static unsigned int lineevent_poll(struct file *filep,
struct poll_table_struct *wait)
{
struct lineevent_state *le = filep->private_data;
unsigned int events = 0;
poll_wait(filep, &le->wait, wait);
if (!kfifo_is_empty(&le->events))
events = POLLIN | POLLRDNORM;
return events;
}
static ssize_t lineevent_read(struct file *filep,
char __user *buf,
size_t count,
loff_t *f_ps)
{
struct lineevent_state *le = filep->private_data;
unsigned int copied;
int ret;
if (count < sizeof(struct gpioevent_data))
return -EINVAL;
do {
if (kfifo_is_empty(&le->events)) {
if (filep->f_flags & O_NONBLOCK)
return -EAGAIN;
ret = wait_event_interruptible(le->wait,
!kfifo_is_empty(&le->events));
if (ret)
return ret;
}
if (mutex_lock_interruptible(&le->read_lock))
return -ERESTARTSYS;
ret = kfifo_to_user(&le->events, buf, count, &copied);
mutex_unlock(&le->read_lock);
if (ret)
return ret;
if (copied == 0 && (filep->f_flags & O_NONBLOCK))
return -EAGAIN;
} while (copied == 0);
return copied;
}
static int lineevent_release(struct inode *inode, struct file *filep)
{
struct lineevent_state *le = filep->private_data;
struct gpio_device *gdev = le->gdev;
free_irq(le->irq, le);
gpiod_free(le->desc);
kfree(le->label);
kfree(le);
put_device(&gdev->dev);
return 0;
}
static long lineevent_ioctl(struct file *filep, unsigned int cmd,
unsigned long arg)
{
struct lineevent_state *le = filep->private_data;
void __user *ip = (void __user *)arg;
struct gpiohandle_data ghd;
if (cmd == GPIOHANDLE_GET_LINE_VALUES_IOCTL) {
int val;
memset(&ghd, 0, sizeof(ghd));
val = gpiod_get_value_cansleep(le->desc);
if (val < 0)
return val;
ghd.values[0] = val;
if (copy_to_user(ip, &ghd, sizeof(ghd)))
return -EFAULT;
return 0;
}
return -EINVAL;
}
static long lineevent_ioctl_compat(struct file *filep, unsigned int cmd,
unsigned long arg)
{
return lineevent_ioctl(filep, cmd, (unsigned long)compat_ptr(arg));
}
static irqreturn_t lineevent_irq_thread(int irq, void *p)
{
struct lineevent_state *le = p;
struct gpioevent_data ge;
int ret;
ge.timestamp = ktime_get_real_ns();
if (le->eflags & GPIOEVENT_REQUEST_BOTH_EDGES) {
int level = gpiod_get_value_cansleep(le->desc);
if (level)
ge.id = GPIOEVENT_EVENT_RISING_EDGE;
else
ge.id = GPIOEVENT_EVENT_FALLING_EDGE;
} else if (le->eflags & GPIOEVENT_REQUEST_RISING_EDGE) {
ge.id = GPIOEVENT_EVENT_RISING_EDGE;
} else if (le->eflags & GPIOEVENT_REQUEST_FALLING_EDGE) {
ge.id = GPIOEVENT_EVENT_FALLING_EDGE;
} else {
return IRQ_NONE;
}
ret = kfifo_put(&le->events, ge);
if (ret != 0)
wake_up_poll(&le->wait, POLLIN);
return IRQ_HANDLED;
}
static int lineevent_create(struct gpio_device *gdev, void __user *ip)
{
struct gpioevent_request eventreq;
struct lineevent_state *le;
struct gpio_desc *desc;
struct file *file;
u32 offset;
u32 lflags;
u32 eflags;
int fd;
int ret;
int irqflags = 0;
if (copy_from_user(&eventreq, ip, sizeof(eventreq)))
return -EFAULT;
le = kzalloc(sizeof(*le), GFP_KERNEL);
if (!le)
return -ENOMEM;
le->gdev = gdev;
get_device(&gdev->dev);
eventreq.consumer_label[sizeof(eventreq.consumer_label)-1] = '\0';
if (strlen(eventreq.consumer_label)) {
le->label = kstrdup(eventreq.consumer_label,
GFP_KERNEL);
if (!le->label) {
ret = -ENOMEM;
goto out_free_le;
}
}
offset = eventreq.lineoffset;
lflags = eventreq.handleflags;
eflags = eventreq.eventflags;
if (offset >= gdev->ngpio) {
ret = -EINVAL;
goto out_free_label;
}
if ((lflags & ~GPIOHANDLE_REQUEST_VALID_FLAGS) ||
(eflags & ~GPIOEVENT_REQUEST_VALID_FLAGS)) {
ret = -EINVAL;
goto out_free_label;
}
if (lflags & GPIOHANDLE_REQUEST_OUTPUT) {
ret = -EINVAL;
goto out_free_label;
}
desc = &gdev->descs[offset];
ret = gpiod_request(desc, le->label);
if (ret)
goto out_free_desc;
le->desc = desc;
le->eflags = eflags;
if (lflags & GPIOHANDLE_REQUEST_ACTIVE_LOW)
set_bit(FLAG_ACTIVE_LOW, &desc->flags);
if (lflags & GPIOHANDLE_REQUEST_OPEN_DRAIN)
set_bit(FLAG_OPEN_DRAIN, &desc->flags);
if (lflags & GPIOHANDLE_REQUEST_OPEN_SOURCE)
set_bit(FLAG_OPEN_SOURCE, &desc->flags);
ret = gpiod_direction_input(desc);
if (ret)
goto out_free_desc;
le->irq = gpiod_to_irq(desc);
if (le->irq <= 0) {
ret = -ENODEV;
goto out_free_desc;
}
if (eflags & GPIOEVENT_REQUEST_RISING_EDGE)
irqflags |= IRQF_TRIGGER_RISING;
if (eflags & GPIOEVENT_REQUEST_FALLING_EDGE)
irqflags |= IRQF_TRIGGER_FALLING;
irqflags |= IRQF_ONESHOT;
irqflags |= IRQF_SHARED;
INIT_KFIFO(le->events);
init_waitqueue_head(&le->wait);
mutex_init(&le->read_lock);
ret = request_threaded_irq(le->irq,
NULL,
lineevent_irq_thread,
irqflags,
le->label,
le);
if (ret)
goto out_free_desc;
fd = get_unused_fd_flags(O_RDONLY | O_CLOEXEC);
if (fd < 0) {
ret = fd;
goto out_free_irq;
}
file = anon_inode_getfile("gpio-event",
&lineevent_fileops,
le,
O_RDONLY | O_CLOEXEC);
if (IS_ERR(file)) {
ret = PTR_ERR(file);
goto out_put_unused_fd;
}
eventreq.fd = fd;
if (copy_to_user(ip, &eventreq, sizeof(eventreq))) {
fput(file);
put_unused_fd(fd);
return -EFAULT;
}
fd_install(fd, file);
return 0;
out_put_unused_fd:
put_unused_fd(fd);
out_free_irq:
free_irq(le->irq, le);
out_free_desc:
gpiod_free(le->desc);
out_free_label:
kfree(le->label);
out_free_le:
kfree(le);
put_device(&gdev->dev);
return ret;
}
static long gpio_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
struct gpio_device *gdev = filp->private_data;
struct gpio_chip *chip = gdev->chip;
void __user *ip = (void __user *)arg;
if (!chip)
return -ENODEV;
if (cmd == GPIO_GET_CHIPINFO_IOCTL) {
struct gpiochip_info chipinfo;
memset(&chipinfo, 0, sizeof(chipinfo));
strncpy(chipinfo.name, dev_name(&gdev->dev),
sizeof(chipinfo.name));
chipinfo.name[sizeof(chipinfo.name)-1] = '\0';
strncpy(chipinfo.label, gdev->label,
sizeof(chipinfo.label));
chipinfo.label[sizeof(chipinfo.label)-1] = '\0';
chipinfo.lines = gdev->ngpio;
if (copy_to_user(ip, &chipinfo, sizeof(chipinfo)))
return -EFAULT;
return 0;
} else if (cmd == GPIO_GET_LINEINFO_IOCTL) {
struct gpioline_info lineinfo;
struct gpio_desc *desc;
if (copy_from_user(&lineinfo, ip, sizeof(lineinfo)))
return -EFAULT;
if (lineinfo.line_offset >= gdev->ngpio)
return -EINVAL;
desc = &gdev->descs[lineinfo.line_offset];
if (desc->name) {
strncpy(lineinfo.name, desc->name,
sizeof(lineinfo.name));
lineinfo.name[sizeof(lineinfo.name)-1] = '\0';
} else {
lineinfo.name[0] = '\0';
}
if (desc->label) {
strncpy(lineinfo.consumer, desc->label,
sizeof(lineinfo.consumer));
lineinfo.consumer[sizeof(lineinfo.consumer)-1] = '\0';
} else {
lineinfo.consumer[0] = '\0';
}
lineinfo.flags = 0;
if (test_bit(FLAG_REQUESTED, &desc->flags) ||
test_bit(FLAG_IS_HOGGED, &desc->flags) ||
test_bit(FLAG_USED_AS_IRQ, &desc->flags) ||
test_bit(FLAG_EXPORT, &desc->flags) ||
test_bit(FLAG_SYSFS, &desc->flags))
lineinfo.flags |= GPIOLINE_FLAG_KERNEL;
if (test_bit(FLAG_IS_OUT, &desc->flags))
lineinfo.flags |= GPIOLINE_FLAG_IS_OUT;
if (test_bit(FLAG_ACTIVE_LOW, &desc->flags))
lineinfo.flags |= GPIOLINE_FLAG_ACTIVE_LOW;
if (test_bit(FLAG_OPEN_DRAIN, &desc->flags))
lineinfo.flags |= GPIOLINE_FLAG_OPEN_DRAIN;
if (test_bit(FLAG_OPEN_SOURCE, &desc->flags))
lineinfo.flags |= GPIOLINE_FLAG_OPEN_SOURCE;
if (copy_to_user(ip, &lineinfo, sizeof(lineinfo)))
return -EFAULT;
return 0;
} else if (cmd == GPIO_GET_LINEHANDLE_IOCTL) {
return linehandle_create(gdev, ip);
} else if (cmd == GPIO_GET_LINEEVENT_IOCTL) {
return lineevent_create(gdev, ip);
}
return -EINVAL;
}
static long gpio_ioctl_compat(struct file *filp, unsigned int cmd,
unsigned long arg)
{
return gpio_ioctl(filp, cmd, (unsigned long)compat_ptr(arg));
}
static int gpio_chrdev_open(struct inode *inode, struct file *filp)
{
struct gpio_device *gdev = container_of(inode->i_cdev,
struct gpio_device, chrdev);
if (!gdev || !gdev->chip)
return -ENODEV;
get_device(&gdev->dev);
filp->private_data = gdev;
return 0;
}
static int gpio_chrdev_release(struct inode *inode, struct file *filp)
{
struct gpio_device *gdev = container_of(inode->i_cdev,
struct gpio_device, chrdev);
if (!gdev)
return -ENODEV;
put_device(&gdev->dev);
return 0;
}
static void gpiodevice_release(struct device *dev)
{
struct gpio_device *gdev = dev_get_drvdata(dev);
list_del(&gdev->list);
ida_simple_remove(&gpio_ida, gdev->id);
kfree(gdev->label);
kfree(gdev->descs);
kfree(gdev);
}
static int gpiochip_setup_dev(struct gpio_device *gdev)
{
int status;
cdev_init(&gdev->chrdev, &gpio_fileops);
gdev->chrdev.owner = THIS_MODULE;
gdev->chrdev.kobj.parent = &gdev->dev.kobj;
gdev->dev.devt = MKDEV(MAJOR(gpio_devt), gdev->id);
status = cdev_add(&gdev->chrdev, gdev->dev.devt, 1);
if (status < 0)
chip_warn(gdev->chip, "failed to add char device %d:%d\n",
MAJOR(gpio_devt), gdev->id);
else
chip_dbg(gdev->chip, "added GPIO chardev (%d:%d)\n",
MAJOR(gpio_devt), gdev->id);
status = device_add(&gdev->dev);
if (status)
goto err_remove_chardev;
status = gpiochip_sysfs_register(gdev);
if (status)
goto err_remove_device;
gdev->dev.release = gpiodevice_release;
pr_debug("%s: registered GPIOs %d to %d on device: %s (%s)\n",
__func__, gdev->base, gdev->base + gdev->ngpio - 1,
dev_name(&gdev->dev), gdev->chip->label ? : "generic");
return 0;
err_remove_device:
device_del(&gdev->dev);
err_remove_chardev:
cdev_del(&gdev->chrdev);
return status;
}
static void gpiochip_setup_devs(void)
{
struct gpio_device *gdev;
int err;
list_for_each_entry(gdev, &gpio_devices, list) {
err = gpiochip_setup_dev(gdev);
if (err)
pr_err("%s: Failed to initialize gpio device (%d)\n",
dev_name(&gdev->dev), err);
}
}
int gpiochip_add_data(struct gpio_chip *chip, void *data)
{
unsigned long flags;
int status = 0;
unsigned i;
int base = chip->base;
struct gpio_device *gdev;
gdev = kzalloc(sizeof(*gdev), GFP_KERNEL);
if (!gdev)
return -ENOMEM;
gdev->dev.bus = &gpio_bus_type;
gdev->chip = chip;
chip->gpiodev = gdev;
if (chip->parent) {
gdev->dev.parent = chip->parent;
gdev->dev.of_node = chip->parent->of_node;
}
#ifdef CONFIG_OF_GPIO
if (chip->of_node)
gdev->dev.of_node = chip->of_node;
#endif
gdev->id = ida_simple_get(&gpio_ida, 0, 0, GFP_KERNEL);
if (gdev->id < 0) {
status = gdev->id;
goto err_free_gdev;
}
dev_set_name(&gdev->dev, "gpiochip%d", gdev->id);
device_initialize(&gdev->dev);
dev_set_drvdata(&gdev->dev, gdev);
if (chip->parent && chip->parent->driver)
gdev->owner = chip->parent->driver->owner;
else if (chip->owner)
gdev->owner = chip->owner;
else
gdev->owner = THIS_MODULE;
gdev->descs = kcalloc(chip->ngpio, sizeof(gdev->descs[0]), GFP_KERNEL);
if (!gdev->descs) {
status = -ENOMEM;
goto err_free_gdev;
}
if (chip->ngpio == 0) {
chip_err(chip, "tried to insert a GPIO chip with zero lines\n");
status = -EINVAL;
goto err_free_descs;
}
if (chip->label)
gdev->label = kstrdup(chip->label, GFP_KERNEL);
else
gdev->label = kstrdup("unknown", GFP_KERNEL);
if (!gdev->label) {
status = -ENOMEM;
goto err_free_descs;
}
gdev->ngpio = chip->ngpio;
gdev->data = data;
spin_lock_irqsave(&gpio_lock, flags);
if (base < 0) {
base = gpiochip_find_base(chip->ngpio);
if (base < 0) {
status = base;
spin_unlock_irqrestore(&gpio_lock, flags);
goto err_free_label;
}
chip->base = base;
}
gdev->base = base;
status = gpiodev_add_to_list(gdev);
if (status) {
spin_unlock_irqrestore(&gpio_lock, flags);
goto err_free_label;
}
spin_unlock_irqrestore(&gpio_lock, flags);
for (i = 0; i < chip->ngpio; i++) {
struct gpio_desc *desc = &gdev->descs[i];
desc->gdev = gdev;
if (chip->get_direction) {
int dir = chip->get_direction(chip, i);
if (!dir)
set_bit(FLAG_IS_OUT, &desc->flags);
} else if (!chip->direction_input) {
set_bit(FLAG_IS_OUT, &desc->flags);
}
}
#ifdef CONFIG_PINCTRL
INIT_LIST_HEAD(&gdev->pin_ranges);
#endif
status = gpiochip_set_desc_names(chip);
if (status)
goto err_remove_from_list;
status = gpiochip_irqchip_init_valid_mask(chip);
if (status)
goto err_remove_from_list;
status = of_gpiochip_add(chip);
if (status)
goto err_remove_chip;
acpi_gpiochip_add(chip);
if (gpiolib_initialized) {
status = gpiochip_setup_dev(gdev);
if (status)
goto err_remove_chip;
}
return 0;
err_remove_chip:
acpi_gpiochip_remove(chip);
gpiochip_free_hogs(chip);
of_gpiochip_remove(chip);
gpiochip_irqchip_free_valid_mask(chip);
err_remove_from_list:
spin_lock_irqsave(&gpio_lock, flags);
list_del(&gdev->list);
spin_unlock_irqrestore(&gpio_lock, flags);
err_free_label:
kfree(gdev->label);
err_free_descs:
kfree(gdev->descs);
err_free_gdev:
ida_simple_remove(&gpio_ida, gdev->id);
pr_err("%s: GPIOs %d..%d (%s) failed to register\n", __func__,
gdev->base, gdev->base + gdev->ngpio - 1,
chip->label ? : "generic");
kfree(gdev);
return status;
}
void *gpiochip_get_data(struct gpio_chip *chip)
{
return chip->gpiodev->data;
}
void gpiochip_remove(struct gpio_chip *chip)
{
struct gpio_device *gdev = chip->gpiodev;
struct gpio_desc *desc;
unsigned long flags;
unsigned i;
bool requested = false;
gpiochip_sysfs_unregister(gdev);
gdev->chip = NULL;
gpiochip_irqchip_remove(chip);
acpi_gpiochip_remove(chip);
gpiochip_remove_pin_ranges(chip);
gpiochip_free_hogs(chip);
of_gpiochip_remove(chip);
gdev->data = NULL;
spin_lock_irqsave(&gpio_lock, flags);
for (i = 0; i < gdev->ngpio; i++) {
desc = &gdev->descs[i];
if (test_bit(FLAG_REQUESTED, &desc->flags))
requested = true;
}
spin_unlock_irqrestore(&gpio_lock, flags);
if (requested)
dev_crit(&gdev->dev,
"REMOVING GPIOCHIP WITH GPIOS STILL REQUESTED\n");
cdev_del(&gdev->chrdev);
device_del(&gdev->dev);
put_device(&gdev->dev);
}
static void devm_gpio_chip_release(struct device *dev, void *res)
{
struct gpio_chip *chip = *(struct gpio_chip **)res;
gpiochip_remove(chip);
}
static int devm_gpio_chip_match(struct device *dev, void *res, void *data)
{
struct gpio_chip **r = res;
if (!r || !*r) {
WARN_ON(!r || !*r);
return 0;
}
return *r == data;
}
int devm_gpiochip_add_data(struct device *dev, struct gpio_chip *chip,
void *data)
{
struct gpio_chip **ptr;
int ret;
ptr = devres_alloc(devm_gpio_chip_release, sizeof(*ptr),
GFP_KERNEL);
if (!ptr)
return -ENOMEM;
ret = gpiochip_add_data(chip, data);
if (ret < 0) {
devres_free(ptr);
return ret;
}
*ptr = chip;
devres_add(dev, ptr);
return 0;
}
void devm_gpiochip_remove(struct device *dev, struct gpio_chip *chip)
{
int ret;
ret = devres_release(dev, devm_gpio_chip_release,
devm_gpio_chip_match, chip);
if (!ret)
WARN_ON(ret);
}
struct gpio_chip *gpiochip_find(void *data,
int (*match)(struct gpio_chip *chip,
void *data))
{
struct gpio_device *gdev;
struct gpio_chip *chip = NULL;
unsigned long flags;
spin_lock_irqsave(&gpio_lock, flags);
list_for_each_entry(gdev, &gpio_devices, list)
if (gdev->chip && match(gdev->chip, data)) {
chip = gdev->chip;
break;
}
spin_unlock_irqrestore(&gpio_lock, flags);
return chip;
}
static int gpiochip_match_name(struct gpio_chip *chip, void *data)
{
const char *name = data;
return !strcmp(chip->label, name);
}
static struct gpio_chip *find_chip_by_name(const char *name)
{
return gpiochip_find((void *)name, gpiochip_match_name);
}
static int gpiochip_irqchip_init_valid_mask(struct gpio_chip *gpiochip)
{
int i;
if (!gpiochip->irq_need_valid_mask)
return 0;
gpiochip->irq_valid_mask = kcalloc(BITS_TO_LONGS(gpiochip->ngpio),
sizeof(long), GFP_KERNEL);
if (!gpiochip->irq_valid_mask)
return -ENOMEM;
for (i = 0; i < gpiochip->ngpio; i++)
set_bit(i, gpiochip->irq_valid_mask);
return 0;
}
static void gpiochip_irqchip_free_valid_mask(struct gpio_chip *gpiochip)
{
kfree(gpiochip->irq_valid_mask);
gpiochip->irq_valid_mask = NULL;
}
static bool gpiochip_irqchip_irq_valid(const struct gpio_chip *gpiochip,
unsigned int offset)
{
if (likely(!gpiochip->irq_valid_mask))
return true;
return test_bit(offset, gpiochip->irq_valid_mask);
}
void gpiochip_set_chained_irqchip(struct gpio_chip *gpiochip,
struct irq_chip *irqchip,
int parent_irq,
irq_flow_handler_t parent_handler)
{
unsigned int offset;
if (!gpiochip->irqdomain) {
chip_err(gpiochip, "called %s before setting up irqchip\n",
__func__);
return;
}
if (parent_handler) {
if (gpiochip->can_sleep) {
chip_err(gpiochip,
"you cannot have chained interrupts on a "
"chip that may sleep\n");
return;
}
irq_set_chained_handler_and_data(parent_irq, parent_handler,
gpiochip);
gpiochip->irq_parent = parent_irq;
}
for (offset = 0; offset < gpiochip->ngpio; offset++) {
if (!gpiochip_irqchip_irq_valid(gpiochip, offset))
continue;
irq_set_parent(irq_find_mapping(gpiochip->irqdomain, offset),
parent_irq);
}
}
static int gpiochip_irq_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hwirq)
{
struct gpio_chip *chip = d->host_data;
irq_set_chip_data(irq, chip);
irq_set_lockdep_class(irq, chip->lock_key);
irq_set_chip_and_handler(irq, chip->irqchip, chip->irq_handler);
if (chip->can_sleep && !chip->irq_not_threaded)
irq_set_nested_thread(irq, 1);
irq_set_noprobe(irq);
if (chip->irq_default_type != IRQ_TYPE_NONE)
irq_set_irq_type(irq, chip->irq_default_type);
return 0;
}
static void gpiochip_irq_unmap(struct irq_domain *d, unsigned int irq)
{
struct gpio_chip *chip = d->host_data;
if (chip->can_sleep)
irq_set_nested_thread(irq, 0);
irq_set_chip_and_handler(irq, NULL, NULL);
irq_set_chip_data(irq, NULL);
}
static int gpiochip_irq_reqres(struct irq_data *d)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(d);
if (!try_module_get(chip->gpiodev->owner))
return -ENODEV;
if (gpiochip_lock_as_irq(chip, d->hwirq)) {
chip_err(chip,
"unable to lock HW IRQ %lu for IRQ\n",
d->hwirq);
module_put(chip->gpiodev->owner);
return -EINVAL;
}
return 0;
}
static void gpiochip_irq_relres(struct irq_data *d)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(d);
gpiochip_unlock_as_irq(chip, d->hwirq);
module_put(chip->gpiodev->owner);
}
static int gpiochip_to_irq(struct gpio_chip *chip, unsigned offset)
{
return irq_find_mapping(chip->irqdomain, offset);
}
static void gpiochip_irqchip_remove(struct gpio_chip *gpiochip)
{
unsigned int offset;
acpi_gpiochip_free_interrupts(gpiochip);
if (gpiochip->irq_parent) {
irq_set_chained_handler(gpiochip->irq_parent, NULL);
irq_set_handler_data(gpiochip->irq_parent, NULL);
}
if (gpiochip->irqdomain) {
for (offset = 0; offset < gpiochip->ngpio; offset++) {
if (!gpiochip_irqchip_irq_valid(gpiochip, offset))
continue;
irq_dispose_mapping(
irq_find_mapping(gpiochip->irqdomain, offset));
}
irq_domain_remove(gpiochip->irqdomain);
}
if (gpiochip->irqchip) {
gpiochip->irqchip->irq_request_resources = NULL;
gpiochip->irqchip->irq_release_resources = NULL;
gpiochip->irqchip = NULL;
}
gpiochip_irqchip_free_valid_mask(gpiochip);
}
int _gpiochip_irqchip_add(struct gpio_chip *gpiochip,
struct irq_chip *irqchip,
unsigned int first_irq,
irq_flow_handler_t handler,
unsigned int type,
struct lock_class_key *lock_key)
{
struct device_node *of_node;
bool irq_base_set = false;
unsigned int offset;
unsigned irq_base = 0;
if (!gpiochip || !irqchip)
return -EINVAL;
if (!gpiochip->parent) {
pr_err("missing gpiochip .dev parent pointer\n");
return -EINVAL;
}
of_node = gpiochip->parent->of_node;
#ifdef CONFIG_OF_GPIO
if (gpiochip->of_node)
of_node = gpiochip->of_node;
#endif
if (WARN(of_node && type != IRQ_TYPE_NONE,
"%s: Ignoring %d default trigger\n", of_node->full_name, type))
type = IRQ_TYPE_NONE;
if (has_acpi_companion(gpiochip->parent) && type != IRQ_TYPE_NONE) {
acpi_handle_warn(ACPI_HANDLE(gpiochip->parent),
"Ignoring %d default trigger\n", type);
type = IRQ_TYPE_NONE;
}
gpiochip->irqchip = irqchip;
gpiochip->irq_handler = handler;
gpiochip->irq_default_type = type;
gpiochip->to_irq = gpiochip_to_irq;
gpiochip->lock_key = lock_key;
gpiochip->irqdomain = irq_domain_add_simple(of_node,
gpiochip->ngpio, first_irq,
&gpiochip_domain_ops, gpiochip);
if (!gpiochip->irqdomain) {
gpiochip->irqchip = NULL;
return -EINVAL;
}
if (!irqchip->irq_request_resources &&
!irqchip->irq_release_resources) {
irqchip->irq_request_resources = gpiochip_irq_reqres;
irqchip->irq_release_resources = gpiochip_irq_relres;
}
for (offset = 0; offset < gpiochip->ngpio; offset++) {
if (!gpiochip_irqchip_irq_valid(gpiochip, offset))
continue;
irq_base = irq_create_mapping(gpiochip->irqdomain, offset);
if (!irq_base_set) {
gpiochip->irq_base = irq_base;
irq_base_set = true;
}
}
acpi_gpiochip_request_interrupts(gpiochip);
return 0;
}
static void gpiochip_irqchip_remove(struct gpio_chip *gpiochip) {}
static inline int gpiochip_irqchip_init_valid_mask(struct gpio_chip *gpiochip)
{
return 0;
}
static inline void gpiochip_irqchip_free_valid_mask(struct gpio_chip *gpiochip)
{ }
int gpiochip_generic_request(struct gpio_chip *chip, unsigned offset)
{
return pinctrl_request_gpio(chip->gpiodev->base + offset);
}
void gpiochip_generic_free(struct gpio_chip *chip, unsigned offset)
{
pinctrl_free_gpio(chip->gpiodev->base + offset);
}
int gpiochip_add_pingroup_range(struct gpio_chip *chip,
struct pinctrl_dev *pctldev,
unsigned int gpio_offset, const char *pin_group)
{
struct gpio_pin_range *pin_range;
struct gpio_device *gdev = chip->gpiodev;
int ret;
pin_range = kzalloc(sizeof(*pin_range), GFP_KERNEL);
if (!pin_range) {
chip_err(chip, "failed to allocate pin ranges\n");
return -ENOMEM;
}
pin_range->range.id = gpio_offset;
pin_range->range.gc = chip;
pin_range->range.name = chip->label;
pin_range->range.base = gdev->base + gpio_offset;
pin_range->pctldev = pctldev;
ret = pinctrl_get_group_pins(pctldev, pin_group,
&pin_range->range.pins,
&pin_range->range.npins);
if (ret < 0) {
kfree(pin_range);
return ret;
}
pinctrl_add_gpio_range(pctldev, &pin_range->range);
chip_dbg(chip, "created GPIO range %d->%d ==> %s PINGRP %s\n",
gpio_offset, gpio_offset + pin_range->range.npins - 1,
pinctrl_dev_get_devname(pctldev), pin_group);
list_add_tail(&pin_range->node, &gdev->pin_ranges);
return 0;
}
int gpiochip_add_pin_range(struct gpio_chip *chip, const char *pinctl_name,
unsigned int gpio_offset, unsigned int pin_offset,
unsigned int npins)
{
struct gpio_pin_range *pin_range;
struct gpio_device *gdev = chip->gpiodev;
int ret;
pin_range = kzalloc(sizeof(*pin_range), GFP_KERNEL);
if (!pin_range) {
chip_err(chip, "failed to allocate pin ranges\n");
return -ENOMEM;
}
pin_range->range.id = gpio_offset;
pin_range->range.gc = chip;
pin_range->range.name = chip->label;
pin_range->range.base = gdev->base + gpio_offset;
pin_range->range.pin_base = pin_offset;
pin_range->range.npins = npins;
pin_range->pctldev = pinctrl_find_and_add_gpio_range(pinctl_name,
&pin_range->range);
if (IS_ERR(pin_range->pctldev)) {
ret = PTR_ERR(pin_range->pctldev);
chip_err(chip, "could not create pin range\n");
kfree(pin_range);
return ret;
}
chip_dbg(chip, "created GPIO range %d->%d ==> %s PIN %d->%d\n",
gpio_offset, gpio_offset + npins - 1,
pinctl_name,
pin_offset, pin_offset + npins - 1);
list_add_tail(&pin_range->node, &gdev->pin_ranges);
return 0;
}
void gpiochip_remove_pin_ranges(struct gpio_chip *chip)
{
struct gpio_pin_range *pin_range, *tmp;
struct gpio_device *gdev = chip->gpiodev;
list_for_each_entry_safe(pin_range, tmp, &gdev->pin_ranges, node) {
list_del(&pin_range->node);
pinctrl_remove_gpio_range(pin_range->pctldev,
&pin_range->range);
kfree(pin_range);
}
}
static int __gpiod_request(struct gpio_desc *desc, const char *label)
{
struct gpio_chip *chip = desc->gdev->chip;
int status;
unsigned long flags;
spin_lock_irqsave(&gpio_lock, flags);
if (test_and_set_bit(FLAG_REQUESTED, &desc->flags) == 0) {
desc_set_label(desc, label ? : "?");
status = 0;
} else {
status = -EBUSY;
goto done;
}
if (chip->request) {
spin_unlock_irqrestore(&gpio_lock, flags);
status = chip->request(chip, gpio_chip_hwgpio(desc));
spin_lock_irqsave(&gpio_lock, flags);
if (status < 0) {
desc_set_label(desc, NULL);
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
spin_unlock_irqrestore(&gpio_lock, flags);
return status;
}
int gpiod_request(struct gpio_desc *desc, const char *label)
{
int status = -EPROBE_DEFER;
struct gpio_device *gdev;
VALIDATE_DESC(desc);
gdev = desc->gdev;
if (try_module_get(gdev->owner)) {
status = __gpiod_request(desc, label);
if (status < 0)
module_put(gdev->owner);
else
get_device(&gdev->dev);
}
if (status)
gpiod_dbg(desc, "%s: status %d\n", __func__, status);
return status;
}
static bool __gpiod_free(struct gpio_desc *desc)
{
bool ret = false;
unsigned long flags;
struct gpio_chip *chip;
might_sleep();
gpiod_unexport(desc);
spin_lock_irqsave(&gpio_lock, flags);
chip = desc->gdev->chip;
if (chip && test_bit(FLAG_REQUESTED, &desc->flags)) {
if (chip->free) {
spin_unlock_irqrestore(&gpio_lock, flags);
might_sleep_if(chip->can_sleep);
chip->free(chip, gpio_chip_hwgpio(desc));
spin_lock_irqsave(&gpio_lock, flags);
}
desc_set_label(desc, NULL);
clear_bit(FLAG_ACTIVE_LOW, &desc->flags);
clear_bit(FLAG_REQUESTED, &desc->flags);
clear_bit(FLAG_OPEN_DRAIN, &desc->flags);
clear_bit(FLAG_OPEN_SOURCE, &desc->flags);
clear_bit(FLAG_IS_HOGGED, &desc->flags);
ret = true;
}
spin_unlock_irqrestore(&gpio_lock, flags);
return ret;
}
void gpiod_free(struct gpio_desc *desc)
{
if (desc && desc->gdev && __gpiod_free(desc)) {
module_put(desc->gdev->owner);
put_device(&desc->gdev->dev);
} else {
WARN_ON(extra_checks);
}
}
const char *gpiochip_is_requested(struct gpio_chip *chip, unsigned offset)
{
struct gpio_desc *desc;
if (offset >= chip->ngpio)
return NULL;
desc = &chip->gpiodev->descs[offset];
if (test_bit(FLAG_REQUESTED, &desc->flags) == 0)
return NULL;
return desc->label;
}
struct gpio_desc *gpiochip_request_own_desc(struct gpio_chip *chip, u16 hwnum,
const char *label)
{
struct gpio_desc *desc = gpiochip_get_desc(chip, hwnum);
int err;
if (IS_ERR(desc)) {
chip_err(chip, "failed to get GPIO descriptor\n");
return desc;
}
err = __gpiod_request(desc, label);
if (err < 0)
return ERR_PTR(err);
return desc;
}
void gpiochip_free_own_desc(struct gpio_desc *desc)
{
if (desc)
__gpiod_free(desc);
}
int gpiod_direction_input(struct gpio_desc *desc)
{
struct gpio_chip *chip;
int status = -EINVAL;
VALIDATE_DESC(desc);
chip = desc->gdev->chip;
if (!chip->get || !chip->direction_input) {
gpiod_warn(desc,
"%s: missing get() or direction_input() operations\n",
__func__);
return -EIO;
}
status = chip->direction_input(chip, gpio_chip_hwgpio(desc));
if (status == 0)
clear_bit(FLAG_IS_OUT, &desc->flags);
trace_gpio_direction(desc_to_gpio(desc), 1, status);
return status;
}
static int _gpiod_direction_output_raw(struct gpio_desc *desc, int value)
{
struct gpio_chip *gc = desc->gdev->chip;
int ret;
if (test_bit(FLAG_USED_AS_IRQ, &desc->flags)) {
gpiod_err(desc,
"%s: tried to set a GPIO tied to an IRQ as output\n",
__func__);
return -EIO;
}
if (test_bit(FLAG_OPEN_DRAIN, &desc->flags)) {
if (gc->set_single_ended) {
ret = gc->set_single_ended(gc, gpio_chip_hwgpio(desc),
LINE_MODE_OPEN_DRAIN);
if (!ret)
goto set_output_value;
}
if (value)
return gpiod_direction_input(desc);
}
else if (test_bit(FLAG_OPEN_SOURCE, &desc->flags)) {
if (gc->set_single_ended) {
ret = gc->set_single_ended(gc, gpio_chip_hwgpio(desc),
LINE_MODE_OPEN_SOURCE);
if (!ret)
goto set_output_value;
}
if (!value)
return gpiod_direction_input(desc);
} else {
if (gc->set_single_ended)
gc->set_single_ended(gc,
gpio_chip_hwgpio(desc),
LINE_MODE_PUSH_PULL);
}
set_output_value:
if (!gc->set || !gc->direction_output) {
gpiod_warn(desc,
"%s: missing set() or direction_output() operations\n",
__func__);
return -EIO;
}
ret = gc->direction_output(gc, gpio_chip_hwgpio(desc), value);
if (!ret)
set_bit(FLAG_IS_OUT, &desc->flags);
trace_gpio_value(desc_to_gpio(desc), 0, value);
trace_gpio_direction(desc_to_gpio(desc), 0, ret);
return ret;
}
int gpiod_direction_output_raw(struct gpio_desc *desc, int value)
{
VALIDATE_DESC(desc);
return _gpiod_direction_output_raw(desc, value);
}
int gpiod_direction_output(struct gpio_desc *desc, int value)
{
VALIDATE_DESC(desc);
if (test_bit(FLAG_ACTIVE_LOW, &desc->flags))
value = !value;
return _gpiod_direction_output_raw(desc, value);
}
int gpiod_set_debounce(struct gpio_desc *desc, unsigned debounce)
{
struct gpio_chip *chip;
VALIDATE_DESC(desc);
chip = desc->gdev->chip;
if (!chip->set || !chip->set_debounce) {
gpiod_dbg(desc,
"%s: missing set() or set_debounce() operations\n",
__func__);
return -ENOTSUPP;
}
return chip->set_debounce(chip, gpio_chip_hwgpio(desc), debounce);
}
int gpiod_is_active_low(const struct gpio_desc *desc)
{
VALIDATE_DESC(desc);
return test_bit(FLAG_ACTIVE_LOW, &desc->flags);
}
static int _gpiod_get_raw_value(const struct gpio_desc *desc)
{
struct gpio_chip *chip;
int offset;
int value;
chip = desc->gdev->chip;
offset = gpio_chip_hwgpio(desc);
value = chip->get ? chip->get(chip, offset) : -EIO;
value = value < 0 ? value : !!value;
trace_gpio_value(desc_to_gpio(desc), 1, value);
return value;
}
int gpiod_get_raw_value(const struct gpio_desc *desc)
{
VALIDATE_DESC(desc);
WARN_ON(desc->gdev->chip->can_sleep);
return _gpiod_get_raw_value(desc);
}
int gpiod_get_value(const struct gpio_desc *desc)
{
int value;
VALIDATE_DESC(desc);
WARN_ON(desc->gdev->chip->can_sleep);
value = _gpiod_get_raw_value(desc);
if (value < 0)
return value;
if (test_bit(FLAG_ACTIVE_LOW, &desc->flags))
value = !value;
return value;
}
static void _gpio_set_open_drain_value(struct gpio_desc *desc, bool value)
{
int err = 0;
struct gpio_chip *chip = desc->gdev->chip;
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
gpiod_err(desc,
"%s: Error in set_value for open drain err %d\n",
__func__, err);
}
static void _gpio_set_open_source_value(struct gpio_desc *desc, bool value)
{
int err = 0;
struct gpio_chip *chip = desc->gdev->chip;
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
gpiod_err(desc,
"%s: Error in set_value for open source err %d\n",
__func__, err);
}
static void _gpiod_set_raw_value(struct gpio_desc *desc, bool value)
{
struct gpio_chip *chip;
chip = desc->gdev->chip;
trace_gpio_value(desc_to_gpio(desc), 0, value);
if (test_bit(FLAG_OPEN_DRAIN, &desc->flags))
_gpio_set_open_drain_value(desc, value);
else if (test_bit(FLAG_OPEN_SOURCE, &desc->flags))
_gpio_set_open_source_value(desc, value);
else
chip->set(chip, gpio_chip_hwgpio(desc), value);
}
static void gpio_chip_set_multiple(struct gpio_chip *chip,
unsigned long *mask, unsigned long *bits)
{
if (chip->set_multiple) {
chip->set_multiple(chip, mask, bits);
} else {
int i;
for (i = 0; i < chip->ngpio; i++) {
if (mask[BIT_WORD(i)] == 0) {
i = (BIT_WORD(i) + 1) * BITS_PER_LONG - 1;
continue;
}
if (__test_and_clear_bit(i, mask))
chip->set(chip, i, test_bit(i, bits));
}
}
}
void gpiod_set_array_value_complex(bool raw, bool can_sleep,
unsigned int array_size,
struct gpio_desc **desc_array,
int *value_array)
{
int i = 0;
while (i < array_size) {
struct gpio_chip *chip = desc_array[i]->gdev->chip;
unsigned long mask[BITS_TO_LONGS(chip->ngpio)];
unsigned long bits[BITS_TO_LONGS(chip->ngpio)];
int count = 0;
if (!can_sleep)
WARN_ON(chip->can_sleep);
memset(mask, 0, sizeof(mask));
do {
struct gpio_desc *desc = desc_array[i];
int hwgpio = gpio_chip_hwgpio(desc);
int value = value_array[i];
if (!raw && test_bit(FLAG_ACTIVE_LOW, &desc->flags))
value = !value;
trace_gpio_value(desc_to_gpio(desc), 0, value);
if (test_bit(FLAG_OPEN_DRAIN, &desc->flags)) {
_gpio_set_open_drain_value(desc, value);
} else if (test_bit(FLAG_OPEN_SOURCE, &desc->flags)) {
_gpio_set_open_source_value(desc, value);
} else {
__set_bit(hwgpio, mask);
if (value)
__set_bit(hwgpio, bits);
else
__clear_bit(hwgpio, bits);
count++;
}
i++;
} while ((i < array_size) &&
(desc_array[i]->gdev->chip == chip));
if (count != 0)
gpio_chip_set_multiple(chip, mask, bits);
}
}
void gpiod_set_raw_value(struct gpio_desc *desc, int value)
{
VALIDATE_DESC_VOID(desc);
WARN_ON(desc->gdev->chip->can_sleep);
_gpiod_set_raw_value(desc, value);
}
void gpiod_set_value(struct gpio_desc *desc, int value)
{
VALIDATE_DESC_VOID(desc);
WARN_ON(desc->gdev->chip->can_sleep);
if (test_bit(FLAG_ACTIVE_LOW, &desc->flags))
value = !value;
_gpiod_set_raw_value(desc, value);
}
void gpiod_set_raw_array_value(unsigned int array_size,
struct gpio_desc **desc_array, int *value_array)
{
if (!desc_array)
return;
gpiod_set_array_value_complex(true, false, array_size, desc_array,
value_array);
}
void gpiod_set_array_value(unsigned int array_size,
struct gpio_desc **desc_array, int *value_array)
{
if (!desc_array)
return;
gpiod_set_array_value_complex(false, false, array_size, desc_array,
value_array);
}
int gpiod_cansleep(const struct gpio_desc *desc)
{
VALIDATE_DESC(desc);
return desc->gdev->chip->can_sleep;
}
int gpiod_to_irq(const struct gpio_desc *desc)
{
struct gpio_chip *chip;
int offset;
if (!desc || IS_ERR(desc) || !desc->gdev || !desc->gdev->chip)
return -EINVAL;
chip = desc->gdev->chip;
offset = gpio_chip_hwgpio(desc);
if (chip->to_irq) {
int retirq = chip->to_irq(chip, offset);
if (!retirq)
return -ENXIO;
return retirq;
}
return -ENXIO;
}
int gpiochip_lock_as_irq(struct gpio_chip *chip, unsigned int offset)
{
struct gpio_desc *desc;
desc = gpiochip_get_desc(chip, offset);
if (IS_ERR(desc))
return PTR_ERR(desc);
if (!chip->can_sleep && chip->get_direction) {
int dir = chip->get_direction(chip, offset);
if (dir)
clear_bit(FLAG_IS_OUT, &desc->flags);
else
set_bit(FLAG_IS_OUT, &desc->flags);
}
if (test_bit(FLAG_IS_OUT, &desc->flags)) {
chip_err(chip,
"%s: tried to flag a GPIO set as output for IRQ\n",
__func__);
return -EIO;
}
set_bit(FLAG_USED_AS_IRQ, &desc->flags);
return 0;
}
void gpiochip_unlock_as_irq(struct gpio_chip *chip, unsigned int offset)
{
if (offset >= chip->ngpio)
return;
clear_bit(FLAG_USED_AS_IRQ, &chip->gpiodev->descs[offset].flags);
}
bool gpiochip_line_is_irq(struct gpio_chip *chip, unsigned int offset)
{
if (offset >= chip->ngpio)
return false;
return test_bit(FLAG_USED_AS_IRQ, &chip->gpiodev->descs[offset].flags);
}
bool gpiochip_line_is_open_drain(struct gpio_chip *chip, unsigned int offset)
{
if (offset >= chip->ngpio)
return false;
return test_bit(FLAG_OPEN_DRAIN, &chip->gpiodev->descs[offset].flags);
}
bool gpiochip_line_is_open_source(struct gpio_chip *chip, unsigned int offset)
{
if (offset >= chip->ngpio)
return false;
return test_bit(FLAG_OPEN_SOURCE, &chip->gpiodev->descs[offset].flags);
}
int gpiod_get_raw_value_cansleep(const struct gpio_desc *desc)
{
might_sleep_if(extra_checks);
VALIDATE_DESC(desc);
return _gpiod_get_raw_value(desc);
}
int gpiod_get_value_cansleep(const struct gpio_desc *desc)
{
int value;
might_sleep_if(extra_checks);
VALIDATE_DESC(desc);
value = _gpiod_get_raw_value(desc);
if (value < 0)
return value;
if (test_bit(FLAG_ACTIVE_LOW, &desc->flags))
value = !value;
return value;
}
void gpiod_set_raw_value_cansleep(struct gpio_desc *desc, int value)
{
might_sleep_if(extra_checks);
VALIDATE_DESC_VOID(desc);
_gpiod_set_raw_value(desc, value);
}
void gpiod_set_value_cansleep(struct gpio_desc *desc, int value)
{
might_sleep_if(extra_checks);
VALIDATE_DESC_VOID(desc);
if (test_bit(FLAG_ACTIVE_LOW, &desc->flags))
value = !value;
_gpiod_set_raw_value(desc, value);
}
void gpiod_set_raw_array_value_cansleep(unsigned int array_size,
struct gpio_desc **desc_array,
int *value_array)
{
might_sleep_if(extra_checks);
if (!desc_array)
return;
gpiod_set_array_value_complex(true, true, array_size, desc_array,
value_array);
}
void gpiod_set_array_value_cansleep(unsigned int array_size,
struct gpio_desc **desc_array,
int *value_array)
{
might_sleep_if(extra_checks);
if (!desc_array)
return;
gpiod_set_array_value_complex(false, true, array_size, desc_array,
value_array);
}
void gpiod_add_lookup_table(struct gpiod_lookup_table *table)
{
mutex_lock(&gpio_lookup_lock);
list_add_tail(&table->list, &gpio_lookup_list);
mutex_unlock(&gpio_lookup_lock);
}
void gpiod_remove_lookup_table(struct gpiod_lookup_table *table)
{
mutex_lock(&gpio_lookup_lock);
list_del(&table->list);
mutex_unlock(&gpio_lookup_lock);
}
static struct gpiod_lookup_table *gpiod_find_lookup_table(struct device *dev)
{
const char *dev_id = dev ? dev_name(dev) : NULL;
struct gpiod_lookup_table *table;
mutex_lock(&gpio_lookup_lock);
list_for_each_entry(table, &gpio_lookup_list, list) {
if (table->dev_id && dev_id) {
if (!strcmp(table->dev_id, dev_id))
goto found;
} else {
if (dev_id == table->dev_id)
goto found;
}
}
table = NULL;
found:
mutex_unlock(&gpio_lookup_lock);
return table;
}
static struct gpio_desc *gpiod_find(struct device *dev, const char *con_id,
unsigned int idx,
enum gpio_lookup_flags *flags)
{
struct gpio_desc *desc = ERR_PTR(-ENOENT);
struct gpiod_lookup_table *table;
struct gpiod_lookup *p;
table = gpiod_find_lookup_table(dev);
if (!table)
return desc;
for (p = &table->table[0]; p->chip_label; p++) {
struct gpio_chip *chip;
if (p->idx != idx)
continue;
if (p->con_id && (!con_id || strcmp(p->con_id, con_id)))
continue;
chip = find_chip_by_name(p->chip_label);
if (!chip) {
dev_err(dev, "cannot find GPIO chip %s\n",
p->chip_label);
return ERR_PTR(-ENODEV);
}
if (chip->ngpio <= p->chip_hwnum) {
dev_err(dev,
"requested GPIO %d is out of range [0..%d] for chip %s\n",
idx, chip->ngpio, chip->label);
return ERR_PTR(-EINVAL);
}
desc = gpiochip_get_desc(chip, p->chip_hwnum);
*flags = p->flags;
return desc;
}
return desc;
}
static int dt_gpio_count(struct device *dev, const char *con_id)
{
int ret;
char propname[32];
unsigned int i;
for (i = 0; i < ARRAY_SIZE(gpio_suffixes); i++) {
if (con_id)
snprintf(propname, sizeof(propname), "%s-%s",
con_id, gpio_suffixes[i]);
else
snprintf(propname, sizeof(propname), "%s",
gpio_suffixes[i]);
ret = of_gpio_named_count(dev->of_node, propname);
if (ret >= 0)
break;
}
return ret;
}
static int platform_gpio_count(struct device *dev, const char *con_id)
{
struct gpiod_lookup_table *table;
struct gpiod_lookup *p;
unsigned int count = 0;
table = gpiod_find_lookup_table(dev);
if (!table)
return -ENOENT;
for (p = &table->table[0]; p->chip_label; p++) {
if ((con_id && p->con_id && !strcmp(con_id, p->con_id)) ||
(!con_id && !p->con_id))
count++;
}
if (!count)
return -ENOENT;
return count;
}
int gpiod_count(struct device *dev, const char *con_id)
{
int count = -ENOENT;
if (IS_ENABLED(CONFIG_OF) && dev && dev->of_node)
count = dt_gpio_count(dev, con_id);
else if (IS_ENABLED(CONFIG_ACPI) && dev && ACPI_HANDLE(dev))
count = acpi_gpio_count(dev, con_id);
if (count < 0)
count = platform_gpio_count(dev, con_id);
return count;
}
struct gpio_desc *__must_check gpiod_get(struct device *dev, const char *con_id,
enum gpiod_flags flags)
{
return gpiod_get_index(dev, con_id, 0, flags);
}
struct gpio_desc *__must_check gpiod_get_optional(struct device *dev,
const char *con_id,
enum gpiod_flags flags)
{
return gpiod_get_index_optional(dev, con_id, 0, flags);
}
static int gpiod_configure_flags(struct gpio_desc *desc, const char *con_id,
unsigned long lflags, enum gpiod_flags dflags)
{
int status;
if (lflags & GPIO_ACTIVE_LOW)
set_bit(FLAG_ACTIVE_LOW, &desc->flags);
if (lflags & GPIO_OPEN_DRAIN)
set_bit(FLAG_OPEN_DRAIN, &desc->flags);
if (lflags & GPIO_OPEN_SOURCE)
set_bit(FLAG_OPEN_SOURCE, &desc->flags);
if (!(dflags & GPIOD_FLAGS_BIT_DIR_SET)) {
pr_debug("no flags found for %s\n", con_id);
return 0;
}
if (dflags & GPIOD_FLAGS_BIT_DIR_OUT)
status = gpiod_direction_output(desc,
dflags & GPIOD_FLAGS_BIT_DIR_VAL);
else
status = gpiod_direction_input(desc);
return status;
}
struct gpio_desc *__must_check gpiod_get_index(struct device *dev,
const char *con_id,
unsigned int idx,
enum gpiod_flags flags)
{
struct gpio_desc *desc = NULL;
int status;
enum gpio_lookup_flags lookupflags = 0;
dev_dbg(dev, "GPIO lookup for consumer %s\n", con_id);
if (dev) {
if (IS_ENABLED(CONFIG_OF) && dev->of_node) {
dev_dbg(dev, "using device tree for GPIO lookup\n");
desc = of_find_gpio(dev, con_id, idx, &lookupflags);
} else if (ACPI_COMPANION(dev)) {
dev_dbg(dev, "using ACPI for GPIO lookup\n");
desc = acpi_find_gpio(dev, con_id, idx, flags, &lookupflags);
}
}
if (!desc || desc == ERR_PTR(-ENOENT)) {
dev_dbg(dev, "using lookup tables for GPIO lookup\n");
desc = gpiod_find(dev, con_id, idx, &lookupflags);
}
if (IS_ERR(desc)) {
dev_dbg(dev, "lookup for GPIO %s failed\n", con_id);
return desc;
}
status = gpiod_request(desc, con_id);
if (status < 0)
return ERR_PTR(status);
status = gpiod_configure_flags(desc, con_id, lookupflags, flags);
if (status < 0) {
dev_dbg(dev, "setup of GPIO %s failed\n", con_id);
gpiod_put(desc);
return ERR_PTR(status);
}
return desc;
}
struct gpio_desc *fwnode_get_named_gpiod(struct fwnode_handle *fwnode,
const char *propname)
{
struct gpio_desc *desc = ERR_PTR(-ENODEV);
bool active_low = false;
bool single_ended = false;
int ret;
if (!fwnode)
return ERR_PTR(-EINVAL);
if (is_of_node(fwnode)) {
enum of_gpio_flags flags;
desc = of_get_named_gpiod_flags(to_of_node(fwnode), propname, 0,
&flags);
if (!IS_ERR(desc)) {
active_low = flags & OF_GPIO_ACTIVE_LOW;
single_ended = flags & OF_GPIO_SINGLE_ENDED;
}
} else if (is_acpi_node(fwnode)) {
struct acpi_gpio_info info;
desc = acpi_node_get_gpiod(fwnode, propname, 0, &info);
if (!IS_ERR(desc))
active_low = info.polarity == GPIO_ACTIVE_LOW;
}
if (IS_ERR(desc))
return desc;
ret = gpiod_request(desc, NULL);
if (ret)
return ERR_PTR(ret);
if (active_low)
set_bit(FLAG_ACTIVE_LOW, &desc->flags);
if (single_ended) {
if (active_low)
set_bit(FLAG_OPEN_DRAIN, &desc->flags);
else
set_bit(FLAG_OPEN_SOURCE, &desc->flags);
}
return desc;
}
struct gpio_desc *__must_check gpiod_get_index_optional(struct device *dev,
const char *con_id,
unsigned int index,
enum gpiod_flags flags)
{
struct gpio_desc *desc;
desc = gpiod_get_index(dev, con_id, index, flags);
if (IS_ERR(desc)) {
if (PTR_ERR(desc) == -ENOENT)
return NULL;
}
return desc;
}
int gpiod_hog(struct gpio_desc *desc, const char *name,
unsigned long lflags, enum gpiod_flags dflags)
{
struct gpio_chip *chip;
struct gpio_desc *local_desc;
int hwnum;
int status;
chip = gpiod_to_chip(desc);
hwnum = gpio_chip_hwgpio(desc);
local_desc = gpiochip_request_own_desc(chip, hwnum, name);
if (IS_ERR(local_desc)) {
status = PTR_ERR(local_desc);
pr_err("requesting hog GPIO %s (chip %s, offset %d) failed, %d\n",
name, chip->label, hwnum, status);
return status;
}
status = gpiod_configure_flags(desc, name, lflags, dflags);
if (status < 0) {
pr_err("setup of hog GPIO %s (chip %s, offset %d) failed, %d\n",
name, chip->label, hwnum, status);
gpiochip_free_own_desc(desc);
return status;
}
set_bit(FLAG_IS_HOGGED, &desc->flags);
pr_info("GPIO line %d (%s) hogged as %s%s\n",
desc_to_gpio(desc), name,
(dflags&GPIOD_FLAGS_BIT_DIR_OUT) ? "output" : "input",
(dflags&GPIOD_FLAGS_BIT_DIR_OUT) ?
(dflags&GPIOD_FLAGS_BIT_DIR_VAL) ? "/high" : "/low":"");
return 0;
}
static void gpiochip_free_hogs(struct gpio_chip *chip)
{
int id;
for (id = 0; id < chip->ngpio; id++) {
if (test_bit(FLAG_IS_HOGGED, &chip->gpiodev->descs[id].flags))
gpiochip_free_own_desc(&chip->gpiodev->descs[id]);
}
}
struct gpio_descs *__must_check gpiod_get_array(struct device *dev,
const char *con_id,
enum gpiod_flags flags)
{
struct gpio_desc *desc;
struct gpio_descs *descs;
int count;
count = gpiod_count(dev, con_id);
if (count < 0)
return ERR_PTR(count);
descs = kzalloc(sizeof(*descs) + sizeof(descs->desc[0]) * count,
GFP_KERNEL);
if (!descs)
return ERR_PTR(-ENOMEM);
for (descs->ndescs = 0; descs->ndescs < count; ) {
desc = gpiod_get_index(dev, con_id, descs->ndescs, flags);
if (IS_ERR(desc)) {
gpiod_put_array(descs);
return ERR_CAST(desc);
}
descs->desc[descs->ndescs] = desc;
descs->ndescs++;
}
return descs;
}
struct gpio_descs *__must_check gpiod_get_array_optional(struct device *dev,
const char *con_id,
enum gpiod_flags flags)
{
struct gpio_descs *descs;
descs = gpiod_get_array(dev, con_id, flags);
if (IS_ERR(descs) && (PTR_ERR(descs) == -ENOENT))
return NULL;
return descs;
}
void gpiod_put(struct gpio_desc *desc)
{
gpiod_free(desc);
}
void gpiod_put_array(struct gpio_descs *descs)
{
unsigned int i;
for (i = 0; i < descs->ndescs; i++)
gpiod_put(descs->desc[i]);
kfree(descs);
}
static int __init gpiolib_dev_init(void)
{
int ret;
ret = bus_register(&gpio_bus_type);
if (ret < 0) {
pr_err("gpiolib: could not register GPIO bus type\n");
return ret;
}
ret = alloc_chrdev_region(&gpio_devt, 0, GPIO_DEV_MAX, "gpiochip");
if (ret < 0) {
pr_err("gpiolib: failed to allocate char dev region\n");
bus_unregister(&gpio_bus_type);
} else {
gpiolib_initialized = true;
gpiochip_setup_devs();
}
return ret;
}
static void gpiolib_dbg_show(struct seq_file *s, struct gpio_device *gdev)
{
unsigned i;
struct gpio_chip *chip = gdev->chip;
unsigned gpio = gdev->base;
struct gpio_desc *gdesc = &gdev->descs[0];
int is_out;
int is_irq;
for (i = 0; i < gdev->ngpio; i++, gpio++, gdesc++) {
if (!test_bit(FLAG_REQUESTED, &gdesc->flags)) {
if (gdesc->name) {
seq_printf(s, " gpio-%-3d (%-20.20s)\n",
gpio, gdesc->name);
}
continue;
}
gpiod_get_direction(gdesc);
is_out = test_bit(FLAG_IS_OUT, &gdesc->flags);
is_irq = test_bit(FLAG_USED_AS_IRQ, &gdesc->flags);
seq_printf(s, " gpio-%-3d (%-20.20s|%-20.20s) %s %s %s",
gpio, gdesc->name ? gdesc->name : "", gdesc->label,
is_out ? "out" : "in ",
chip->get
? (chip->get(chip, i) ? "hi" : "lo")
: "? ",
is_irq ? "IRQ" : " ");
seq_printf(s, "\n");
}
}
static void *gpiolib_seq_start(struct seq_file *s, loff_t *pos)
{
unsigned long flags;
struct gpio_device *gdev = NULL;
loff_t index = *pos;
s->private = "";
spin_lock_irqsave(&gpio_lock, flags);
list_for_each_entry(gdev, &gpio_devices, list)
if (index-- == 0) {
spin_unlock_irqrestore(&gpio_lock, flags);
return gdev;
}
spin_unlock_irqrestore(&gpio_lock, flags);
return NULL;
}
static void *gpiolib_seq_next(struct seq_file *s, void *v, loff_t *pos)
{
unsigned long flags;
struct gpio_device *gdev = v;
void *ret = NULL;
spin_lock_irqsave(&gpio_lock, flags);
if (list_is_last(&gdev->list, &gpio_devices))
ret = NULL;
else
ret = list_entry(gdev->list.next, struct gpio_device, list);
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
struct gpio_device *gdev = v;
struct gpio_chip *chip = gdev->chip;
struct device *parent;
if (!chip) {
seq_printf(s, "%s%s: (dangling chip)", (char *)s->private,
dev_name(&gdev->dev));
return 0;
}
seq_printf(s, "%s%s: GPIOs %d-%d", (char *)s->private,
dev_name(&gdev->dev),
gdev->base, gdev->base + gdev->ngpio - 1);
parent = chip->parent;
if (parent)
seq_printf(s, ", parent: %s/%s",
parent->bus ? parent->bus->name : "no-bus",
dev_name(parent));
if (chip->label)
seq_printf(s, ", %s", chip->label);
if (chip->can_sleep)
seq_printf(s, ", can sleep");
seq_printf(s, ":\n");
if (chip->dbg_show)
chip->dbg_show(s, chip);
else
gpiolib_dbg_show(s, gdev);
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
