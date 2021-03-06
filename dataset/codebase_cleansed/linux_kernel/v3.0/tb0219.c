static inline char get_led(void)
{
return (char)tb0219_read(TB0219_LED);
}
static inline char get_gpio_input_pin(unsigned int pin)
{
uint16_t values;
values = tb0219_read(TB0219_GPIO_INPUT);
if (values & (1 << pin))
return '1';
return '0';
}
static inline char get_gpio_output_pin(unsigned int pin)
{
uint16_t values;
values = tb0219_read(TB0219_GPIO_OUTPUT);
if (values & (1 << pin))
return '1';
return '0';
}
static inline char get_dip_switch(unsigned int pin)
{
uint16_t values;
values = tb0219_read(TB0219_DIP_SWITCH);
if (values & (1 << pin))
return '1';
return '0';
}
static inline int set_led(char command)
{
tb0219_write(TB0219_LED, command);
return 0;
}
static inline int set_gpio_output_pin(unsigned int pin, char command)
{
unsigned long flags;
uint16_t value;
if (command != '0' && command != '1')
return -EINVAL;
spin_lock_irqsave(&tb0219_lock, flags);
value = tb0219_read(TB0219_GPIO_OUTPUT);
if (command == '0')
value &= ~(1 << pin);
else
value |= 1 << pin;
tb0219_write(TB0219_GPIO_OUTPUT, value);
spin_unlock_irqrestore(&tb0219_lock, flags);
return 0;
}
static ssize_t tanbac_tb0219_read(struct file *file, char __user *buf, size_t len,
loff_t *ppos)
{
unsigned int minor;
char value;
minor = iminor(file->f_path.dentry->d_inode);
switch (minor) {
case 0:
value = get_led();
break;
case 16 ... 23:
value = get_gpio_input_pin(minor - 16);
break;
case 32 ... 39:
value = get_gpio_output_pin(minor - 32);
break;
case 48 ... 55:
value = get_dip_switch(minor - 48);
break;
default:
return -EBADF;
}
if (len <= 0)
return -EFAULT;
if (put_user(value, buf))
return -EFAULT;
return 1;
}
static ssize_t tanbac_tb0219_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
unsigned int minor;
tb0219_type_t type;
size_t i;
int retval = 0;
char c;
minor = iminor(file->f_path.dentry->d_inode);
switch (minor) {
case 0:
type = TYPE_LED;
break;
case 32 ... 39:
type = TYPE_GPIO_OUTPUT;
break;
default:
return -EBADF;
}
for (i = 0; i < len; i++) {
if (get_user(c, data + i))
return -EFAULT;
switch (type) {
case TYPE_LED:
retval = set_led(c);
break;
case TYPE_GPIO_OUTPUT:
retval = set_gpio_output_pin(minor - 32, c);
break;
}
if (retval < 0)
break;
}
return i;
}
static int tanbac_tb0219_open(struct inode *inode, struct file *file)
{
unsigned int minor;
minor = iminor(inode);
switch (minor) {
case 0:
case 16 ... 23:
case 32 ... 39:
case 48 ... 55:
return nonseekable_open(inode, file);
default:
break;
}
return -EBADF;
}
static int tanbac_tb0219_release(struct inode *inode, struct file *file)
{
return 0;
}
static void tb0219_restart(char *command)
{
tb0219_write(TB0219_RESET, 0);
}
static void tb0219_pci_irq_init(void)
{
vr41xx_set_irq_trigger(TB0219_PCI_SLOT1_PIN, IRQ_TRIGGER_LEVEL, IRQ_SIGNAL_THROUGH);
vr41xx_set_irq_level(TB0219_PCI_SLOT1_PIN, IRQ_LEVEL_LOW);
vr41xx_set_irq_trigger(TB0219_PCI_SLOT2_PIN, IRQ_TRIGGER_LEVEL, IRQ_SIGNAL_THROUGH);
vr41xx_set_irq_level(TB0219_PCI_SLOT2_PIN, IRQ_LEVEL_LOW);
vr41xx_set_irq_trigger(TB0219_PCI_SLOT3_PIN, IRQ_TRIGGER_LEVEL, IRQ_SIGNAL_THROUGH);
vr41xx_set_irq_level(TB0219_PCI_SLOT3_PIN, IRQ_LEVEL_LOW);
}
static int __devinit tb0219_probe(struct platform_device *dev)
{
int retval;
if (request_mem_region(TB0219_START, TB0219_SIZE, "TB0219") == NULL)
return -EBUSY;
tb0219_base = ioremap(TB0219_START, TB0219_SIZE);
if (tb0219_base == NULL) {
release_mem_region(TB0219_START, TB0219_SIZE);
return -ENOMEM;
}
retval = register_chrdev(major, "TB0219", &tb0219_fops);
if (retval < 0) {
iounmap(tb0219_base);
tb0219_base = NULL;
release_mem_region(TB0219_START, TB0219_SIZE);
return retval;
}
old_machine_restart = _machine_restart;
_machine_restart = tb0219_restart;
tb0219_pci_irq_init();
if (major == 0) {
major = retval;
printk(KERN_INFO "TB0219: major number %d\n", major);
}
return 0;
}
static int __devexit tb0219_remove(struct platform_device *dev)
{
_machine_restart = old_machine_restart;
iounmap(tb0219_base);
tb0219_base = NULL;
release_mem_region(TB0219_START, TB0219_SIZE);
return 0;
}
static int __init tanbac_tb0219_init(void)
{
int retval;
tb0219_platform_device = platform_device_alloc("TB0219", -1);
if (!tb0219_platform_device)
return -ENOMEM;
retval = platform_device_add(tb0219_platform_device);
if (retval < 0) {
platform_device_put(tb0219_platform_device);
return retval;
}
retval = platform_driver_register(&tb0219_device_driver);
if (retval < 0)
platform_device_unregister(tb0219_platform_device);
return retval;
}
static void __exit tanbac_tb0219_exit(void)
{
platform_driver_unregister(&tb0219_device_driver);
platform_device_unregister(tb0219_platform_device);
}
