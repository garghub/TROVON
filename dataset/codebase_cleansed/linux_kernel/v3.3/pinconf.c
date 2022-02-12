int pin_config_get_for_pin(struct pinctrl_dev *pctldev, unsigned pin,
unsigned long *config)
{
const struct pinconf_ops *ops = pctldev->desc->confops;
if (!ops || !ops->pin_config_get) {
dev_err(pctldev->dev, "cannot get pin configuration, missing "
"pin_config_get() function in driver\n");
return -EINVAL;
}
return ops->pin_config_get(pctldev, pin, config);
}
int pin_config_get(const char *dev_name, const char *name,
unsigned long *config)
{
struct pinctrl_dev *pctldev;
int pin;
pctldev = get_pinctrl_dev_from_dev(NULL, dev_name);
if (!pctldev)
return -EINVAL;
pin = pin_get_from_name(pctldev, name);
if (pin < 0)
return pin;
return pin_config_get_for_pin(pctldev, pin, config);
}
int pin_config_set_for_pin(struct pinctrl_dev *pctldev, unsigned pin,
unsigned long config)
{
const struct pinconf_ops *ops = pctldev->desc->confops;
int ret;
if (!ops || !ops->pin_config_set) {
dev_err(pctldev->dev, "cannot configure pin, missing "
"config function in driver\n");
return -EINVAL;
}
ret = ops->pin_config_set(pctldev, pin, config);
if (ret) {
dev_err(pctldev->dev,
"unable to set pin configuration on pin %d\n", pin);
return ret;
}
return 0;
}
int pin_config_set(const char *dev_name, const char *name,
unsigned long config)
{
struct pinctrl_dev *pctldev;
int pin;
pctldev = get_pinctrl_dev_from_dev(NULL, dev_name);
if (!pctldev)
return -EINVAL;
pin = pin_get_from_name(pctldev, name);
if (pin < 0)
return pin;
return pin_config_set_for_pin(pctldev, pin, config);
}
int pin_config_group_get(const char *dev_name, const char *pin_group,
unsigned long *config)
{
struct pinctrl_dev *pctldev;
const struct pinconf_ops *ops;
int selector;
pctldev = get_pinctrl_dev_from_dev(NULL, dev_name);
if (!pctldev)
return -EINVAL;
ops = pctldev->desc->confops;
if (!ops || !ops->pin_config_group_get) {
dev_err(pctldev->dev, "cannot get configuration for pin "
"group, missing group config get function in "
"driver\n");
return -EINVAL;
}
selector = pinctrl_get_group_selector(pctldev, pin_group);
if (selector < 0)
return selector;
return ops->pin_config_group_get(pctldev, selector, config);
}
int pin_config_group_set(const char *dev_name, const char *pin_group,
unsigned long config)
{
struct pinctrl_dev *pctldev;
const struct pinconf_ops *ops;
const struct pinctrl_ops *pctlops;
int selector;
const unsigned *pins;
unsigned num_pins;
int ret;
int i;
pctldev = get_pinctrl_dev_from_dev(NULL, dev_name);
if (!pctldev)
return -EINVAL;
ops = pctldev->desc->confops;
pctlops = pctldev->desc->pctlops;
if (!ops || (!ops->pin_config_group_set && !ops->pin_config_set)) {
dev_err(pctldev->dev, "cannot configure pin group, missing "
"config function in driver\n");
return -EINVAL;
}
selector = pinctrl_get_group_selector(pctldev, pin_group);
if (selector < 0)
return selector;
ret = pctlops->get_group_pins(pctldev, selector, &pins, &num_pins);
if (ret) {
dev_err(pctldev->dev, "cannot configure pin group, error "
"getting pins\n");
return ret;
}
if (ops->pin_config_group_set) {
ret = ops->pin_config_group_set(pctldev, selector, config);
if (ret != -EAGAIN)
return ret;
}
if (!ops->pin_config_set)
return 0;
for (i = 0; i < num_pins; i++) {
ret = ops->pin_config_set(pctldev, pins[i], config);
if (ret < 0)
return ret;
}
return 0;
}
int pinconf_check_ops(struct pinctrl_dev *pctldev)
{
const struct pinconf_ops *ops = pctldev->desc->confops;
if (!ops->pin_config_get && !ops->pin_config_group_get)
return -EINVAL;
if (!ops->pin_config_set && !ops->pin_config_group_set)
return -EINVAL;
return 0;
}
static void pinconf_dump_pin(struct pinctrl_dev *pctldev,
struct seq_file *s, int pin)
{
const struct pinconf_ops *ops = pctldev->desc->confops;
if (ops && ops->pin_config_dbg_show)
ops->pin_config_dbg_show(pctldev, s, pin);
}
static int pinconf_pins_show(struct seq_file *s, void *what)
{
struct pinctrl_dev *pctldev = s->private;
unsigned i, pin;
seq_puts(s, "Pin config settings per pin\n");
seq_puts(s, "Format: pin (name): pinmux setting array\n");
for (i = 0; i < pctldev->desc->npins; i++) {
struct pin_desc *desc;
pin = pctldev->desc->pins[i].number;
desc = pin_desc_get(pctldev, pin);
if (desc == NULL)
continue;
seq_printf(s, "pin %d (%s):", pin,
desc->name ? desc->name : "unnamed");
pinconf_dump_pin(pctldev, s, pin);
seq_printf(s, "\n");
}
return 0;
}
static void pinconf_dump_group(struct pinctrl_dev *pctldev,
struct seq_file *s, unsigned selector,
const char *gname)
{
const struct pinconf_ops *ops = pctldev->desc->confops;
if (ops && ops->pin_config_group_dbg_show)
ops->pin_config_group_dbg_show(pctldev, s, selector);
}
static int pinconf_groups_show(struct seq_file *s, void *what)
{
struct pinctrl_dev *pctldev = s->private;
const struct pinctrl_ops *pctlops = pctldev->desc->pctlops;
const struct pinconf_ops *ops = pctldev->desc->confops;
unsigned selector = 0;
if (!ops || !ops->pin_config_group_get)
return 0;
seq_puts(s, "Pin config settings per pin group\n");
seq_puts(s, "Format: group (name): pinmux setting array\n");
while (pctlops->list_groups(pctldev, selector) >= 0) {
const char *gname = pctlops->get_group_name(pctldev, selector);
seq_printf(s, "%u (%s):", selector, gname);
pinconf_dump_group(pctldev, s, selector, gname);
selector++;
}
return 0;
}
static int pinconf_pins_open(struct inode *inode, struct file *file)
{
return single_open(file, pinconf_pins_show, inode->i_private);
}
static int pinconf_groups_open(struct inode *inode, struct file *file)
{
return single_open(file, pinconf_groups_show, inode->i_private);
}
void pinconf_init_device_debugfs(struct dentry *devroot,
struct pinctrl_dev *pctldev)
{
debugfs_create_file("pinconf-pins", S_IFREG | S_IRUGO,
devroot, pctldev, &pinconf_pins_ops);
debugfs_create_file("pinconf-groups", S_IFREG | S_IRUGO,
devroot, pctldev, &pinconf_groups_ops);
}
