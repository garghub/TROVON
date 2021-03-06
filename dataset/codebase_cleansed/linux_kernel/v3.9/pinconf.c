int pinconf_check_ops(struct pinctrl_dev *pctldev)
{
const struct pinconf_ops *ops = pctldev->desc->confops;
if (!ops->pin_config_get && !ops->pin_config_group_get) {
dev_err(pctldev->dev,
"pinconf must be able to read out pin status\n");
return -EINVAL;
}
if (!ops->pin_config_set && !ops->pin_config_group_set) {
dev_err(pctldev->dev,
"pinconf has to be able to set a pins config\n");
return -EINVAL;
}
return 0;
}
int pinconf_validate_map(struct pinctrl_map const *map, int i)
{
if (!map->data.configs.group_or_pin) {
pr_err("failed to register map %s (%d): no group/pin given\n",
map->name, i);
return -EINVAL;
}
if (!map->data.configs.num_configs ||
!map->data.configs.configs) {
pr_err("failed to register map %s (%d): no configs given\n",
map->name, i);
return -EINVAL;
}
return 0;
}
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
mutex_lock(&pinctrl_mutex);
pctldev = get_pinctrl_dev_from_devname(dev_name);
if (!pctldev) {
pin = -EINVAL;
goto unlock;
}
pin = pin_get_from_name(pctldev, name);
if (pin < 0)
goto unlock;
pin = pin_config_get_for_pin(pctldev, pin, config);
unlock:
mutex_unlock(&pinctrl_mutex);
return pin;
}
static int pin_config_set_for_pin(struct pinctrl_dev *pctldev, unsigned pin,
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
int pin, ret;
mutex_lock(&pinctrl_mutex);
pctldev = get_pinctrl_dev_from_devname(dev_name);
if (!pctldev) {
ret = -EINVAL;
goto unlock;
}
pin = pin_get_from_name(pctldev, name);
if (pin < 0) {
ret = pin;
goto unlock;
}
ret = pin_config_set_for_pin(pctldev, pin, config);
unlock:
mutex_unlock(&pinctrl_mutex);
return ret;
}
int pin_config_group_get(const char *dev_name, const char *pin_group,
unsigned long *config)
{
struct pinctrl_dev *pctldev;
const struct pinconf_ops *ops;
int selector, ret;
mutex_lock(&pinctrl_mutex);
pctldev = get_pinctrl_dev_from_devname(dev_name);
if (!pctldev) {
ret = -EINVAL;
goto unlock;
}
ops = pctldev->desc->confops;
if (!ops || !ops->pin_config_group_get) {
dev_err(pctldev->dev, "cannot get configuration for pin "
"group, missing group config get function in "
"driver\n");
ret = -EINVAL;
goto unlock;
}
selector = pinctrl_get_group_selector(pctldev, pin_group);
if (selector < 0) {
ret = selector;
goto unlock;
}
ret = ops->pin_config_group_get(pctldev, selector, config);
unlock:
mutex_unlock(&pinctrl_mutex);
return ret;
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
mutex_lock(&pinctrl_mutex);
pctldev = get_pinctrl_dev_from_devname(dev_name);
if (!pctldev) {
ret = -EINVAL;
goto unlock;
}
ops = pctldev->desc->confops;
pctlops = pctldev->desc->pctlops;
if (!ops || (!ops->pin_config_group_set && !ops->pin_config_set)) {
dev_err(pctldev->dev, "cannot configure pin group, missing "
"config function in driver\n");
ret = -EINVAL;
goto unlock;
}
selector = pinctrl_get_group_selector(pctldev, pin_group);
if (selector < 0) {
ret = selector;
goto unlock;
}
ret = pctlops->get_group_pins(pctldev, selector, &pins, &num_pins);
if (ret) {
dev_err(pctldev->dev, "cannot configure pin group, error "
"getting pins\n");
goto unlock;
}
if (ops->pin_config_group_set) {
ret = ops->pin_config_group_set(pctldev, selector, config);
if (ret != -EAGAIN)
goto unlock;
}
if (!ops->pin_config_set) {
ret = 0;
goto unlock;
}
for (i = 0; i < num_pins; i++) {
ret = ops->pin_config_set(pctldev, pins[i], config);
if (ret < 0)
goto unlock;
}
ret = 0;
unlock:
mutex_unlock(&pinctrl_mutex);
return ret;
}
int pinconf_map_to_setting(struct pinctrl_map const *map,
struct pinctrl_setting *setting)
{
struct pinctrl_dev *pctldev = setting->pctldev;
int pin;
switch (setting->type) {
case PIN_MAP_TYPE_CONFIGS_PIN:
pin = pin_get_from_name(pctldev,
map->data.configs.group_or_pin);
if (pin < 0) {
dev_err(pctldev->dev, "could not map pin config for \"%s\"",
map->data.configs.group_or_pin);
return pin;
}
setting->data.configs.group_or_pin = pin;
break;
case PIN_MAP_TYPE_CONFIGS_GROUP:
pin = pinctrl_get_group_selector(pctldev,
map->data.configs.group_or_pin);
if (pin < 0) {
dev_err(pctldev->dev, "could not map group config for \"%s\"",
map->data.configs.group_or_pin);
return pin;
}
setting->data.configs.group_or_pin = pin;
break;
default:
return -EINVAL;
}
setting->data.configs.num_configs = map->data.configs.num_configs;
setting->data.configs.configs = map->data.configs.configs;
return 0;
}
void pinconf_free_setting(struct pinctrl_setting const *setting)
{
}
int pinconf_apply_setting(struct pinctrl_setting const *setting)
{
struct pinctrl_dev *pctldev = setting->pctldev;
const struct pinconf_ops *ops = pctldev->desc->confops;
int i, ret;
if (!ops) {
dev_err(pctldev->dev, "missing confops\n");
return -EINVAL;
}
switch (setting->type) {
case PIN_MAP_TYPE_CONFIGS_PIN:
if (!ops->pin_config_set) {
dev_err(pctldev->dev, "missing pin_config_set op\n");
return -EINVAL;
}
for (i = 0; i < setting->data.configs.num_configs; i++) {
ret = ops->pin_config_set(pctldev,
setting->data.configs.group_or_pin,
setting->data.configs.configs[i]);
if (ret < 0) {
dev_err(pctldev->dev,
"pin_config_set op failed for pin %d config %08lx\n",
setting->data.configs.group_or_pin,
setting->data.configs.configs[i]);
return ret;
}
}
break;
case PIN_MAP_TYPE_CONFIGS_GROUP:
if (!ops->pin_config_group_set) {
dev_err(pctldev->dev,
"missing pin_config_group_set op\n");
return -EINVAL;
}
for (i = 0; i < setting->data.configs.num_configs; i++) {
ret = ops->pin_config_group_set(pctldev,
setting->data.configs.group_or_pin,
setting->data.configs.configs[i]);
if (ret < 0) {
dev_err(pctldev->dev,
"pin_config_group_set op failed for group %d config %08lx\n",
setting->data.configs.group_or_pin,
setting->data.configs.configs[i]);
return ret;
}
}
break;
default:
return -EINVAL;
}
return 0;
}
void pinconf_show_map(struct seq_file *s, struct pinctrl_map const *map)
{
struct pinctrl_dev *pctldev;
const struct pinconf_ops *confops;
int i;
pctldev = get_pinctrl_dev_from_devname(map->ctrl_dev_name);
if (pctldev)
confops = pctldev->desc->confops;
else
confops = NULL;
switch (map->type) {
case PIN_MAP_TYPE_CONFIGS_PIN:
seq_printf(s, "pin ");
break;
case PIN_MAP_TYPE_CONFIGS_GROUP:
seq_printf(s, "group ");
break;
default:
break;
}
seq_printf(s, "%s\n", map->data.configs.group_or_pin);
for (i = 0; i < map->data.configs.num_configs; i++) {
seq_printf(s, "config ");
if (confops && confops->pin_config_config_dbg_show)
confops->pin_config_config_dbg_show(pctldev, s,
map->data.configs.configs[i]);
else
seq_printf(s, "%08lx", map->data.configs.configs[i]);
seq_printf(s, "\n");
}
}
void pinconf_show_setting(struct seq_file *s,
struct pinctrl_setting const *setting)
{
struct pinctrl_dev *pctldev = setting->pctldev;
const struct pinctrl_ops *pctlops = pctldev->desc->pctlops;
const struct pinconf_ops *confops = pctldev->desc->confops;
struct pin_desc *desc;
int i;
switch (setting->type) {
case PIN_MAP_TYPE_CONFIGS_PIN:
desc = pin_desc_get(setting->pctldev,
setting->data.configs.group_or_pin);
seq_printf(s, "pin %s (%d)",
desc->name ? desc->name : "unnamed",
setting->data.configs.group_or_pin);
break;
case PIN_MAP_TYPE_CONFIGS_GROUP:
seq_printf(s, "group %s (%d)",
pctlops->get_group_name(pctldev,
setting->data.configs.group_or_pin),
setting->data.configs.group_or_pin);
break;
default:
break;
}
for (i = 0; i < setting->data.configs.num_configs; i++) {
seq_printf(s, " ");
if (confops && confops->pin_config_config_dbg_show)
confops->pin_config_config_dbg_show(pctldev, s,
setting->data.configs.configs[i]);
else
seq_printf(s, "%08lx",
setting->data.configs.configs[i]);
}
seq_printf(s, "\n");
}
static void pinconf_dump_pin(struct pinctrl_dev *pctldev,
struct seq_file *s, int pin)
{
const struct pinconf_ops *ops = pctldev->desc->confops;
pinconf_generic_dump_pin(pctldev, s, pin);
if (ops && ops->pin_config_dbg_show)
ops->pin_config_dbg_show(pctldev, s, pin);
}
static int pinconf_pins_show(struct seq_file *s, void *what)
{
struct pinctrl_dev *pctldev = s->private;
const struct pinconf_ops *ops = pctldev->desc->confops;
unsigned i, pin;
if (!ops || !ops->pin_config_get)
return 0;
seq_puts(s, "Pin config settings per pin\n");
seq_puts(s, "Format: pin (name): configs\n");
mutex_lock(&pinctrl_mutex);
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
mutex_unlock(&pinctrl_mutex);
return 0;
}
static void pinconf_dump_group(struct pinctrl_dev *pctldev,
struct seq_file *s, unsigned selector,
const char *gname)
{
const struct pinconf_ops *ops = pctldev->desc->confops;
pinconf_generic_dump_group(pctldev, s, gname);
if (ops && ops->pin_config_group_dbg_show)
ops->pin_config_group_dbg_show(pctldev, s, selector);
}
static int pinconf_groups_show(struct seq_file *s, void *what)
{
struct pinctrl_dev *pctldev = s->private;
const struct pinctrl_ops *pctlops = pctldev->desc->pctlops;
const struct pinconf_ops *ops = pctldev->desc->confops;
unsigned ngroups = pctlops->get_groups_count(pctldev);
unsigned selector = 0;
if (!ops || !ops->pin_config_group_get)
return 0;
seq_puts(s, "Pin config settings per pin group\n");
seq_puts(s, "Format: group (name): configs\n");
while (selector < ngroups) {
const char *gname = pctlops->get_group_name(pctldev, selector);
seq_printf(s, "%u (%s):", selector, gname);
pinconf_dump_group(pctldev, s, selector, gname);
seq_printf(s, "\n");
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
static int pinconf_dbg_pinname_print(struct seq_file *s, void *d)
{
if (strlen(dbg_pinname))
seq_printf(s, "%s\n", dbg_pinname);
else
seq_printf(s, "No pin name set\n");
return 0;
}
static int pinconf_dbg_pinname_open(struct inode *inode, struct file *file)
{
return single_open(file, pinconf_dbg_pinname_print, inode->i_private);
}
static int pinconf_dbg_pinname_write(struct file *file,
const char __user *user_buf, size_t count, loff_t *ppos)
{
int err;
if (count > MAX_NAME_LEN)
return -EINVAL;
err = sscanf(user_buf, "%15s", dbg_pinname);
if (err != 1)
return -EINVAL;
return count;
}
static int pinconf_dbg_state_print(struct seq_file *s, void *d)
{
if (strlen(dbg_state_name))
seq_printf(s, "%s\n", dbg_state_name);
else
seq_printf(s, "No pin state set\n");
return 0;
}
static int pinconf_dbg_state_open(struct inode *inode, struct file *file)
{
return single_open(file, pinconf_dbg_state_print, inode->i_private);
}
static int pinconf_dbg_state_write(struct file *file,
const char __user *user_buf, size_t count, loff_t *ppos)
{
int err;
if (count > MAX_NAME_LEN)
return -EINVAL;
err = sscanf(user_buf, "%15s", dbg_state_name);
if (err != 1)
return -EINVAL;
return count;
}
static int pinconf_dbg_config_print(struct seq_file *s, void *d)
{
struct pinctrl_maps *maps_node;
struct pinctrl_map const *map;
struct pinctrl_dev *pctldev = NULL;
struct pinconf_ops *confops = NULL;
int i, j;
bool found = false;
mutex_lock(&pinctrl_mutex);
for_each_maps(maps_node, i, map) {
if (map->type != PIN_MAP_TYPE_CONFIGS_PIN)
continue;
if (strncmp(map->name, dbg_state_name, MAX_NAME_LEN) > 0)
continue;
for (j = 0; j < map->data.configs.num_configs; j++) {
if (0 == strncmp(map->data.configs.group_or_pin,
dbg_pinname, MAX_NAME_LEN)) {
dbg_config = map->data.configs.configs[j];
pctldev = get_pinctrl_dev_from_devname
(map->ctrl_dev_name);
found = true;
break;
}
}
}
mutex_unlock(&pinctrl_mutex);
if (found) {
seq_printf(s, "Config of %s in state %s: 0x%08X\n", dbg_pinname,
dbg_state_name, dbg_config);
if (pctldev)
confops = pctldev->desc->confops;
if (confops && confops->pin_config_config_dbg_show)
confops->pin_config_config_dbg_show(pctldev,
s, dbg_config);
} else {
seq_printf(s, "No pin found for defined name/state\n");
}
return 0;
}
static int pinconf_dbg_config_open(struct inode *inode, struct file *file)
{
return single_open(file, pinconf_dbg_config_print, inode->i_private);
}
static int pinconf_dbg_config_write(struct file *file,
const char __user *user_buf, size_t count, loff_t *ppos)
{
int err;
unsigned long config;
struct pinctrl_maps *maps_node;
struct pinctrl_map const *map;
int i, j;
err = kstrtoul_from_user(user_buf, count, 0, &config);
if (err)
return err;
dbg_config = config;
mutex_lock(&pinctrl_mutex);
for_each_maps(maps_node, i, map) {
if (map->type != PIN_MAP_TYPE_CONFIGS_PIN)
continue;
if (strncmp(map->name, dbg_state_name, MAX_NAME_LEN) > 0)
continue;
for (j = 0; j < map->data.configs.num_configs; j++) {
if (strncmp(map->data.configs.group_or_pin, dbg_pinname,
MAX_NAME_LEN) == 0)
map->data.configs.configs[j] = dbg_config;
}
}
mutex_unlock(&pinctrl_mutex);
return count;
}
void pinconf_init_device_debugfs(struct dentry *devroot,
struct pinctrl_dev *pctldev)
{
debugfs_create_file("pinconf-pins", S_IFREG | S_IRUGO,
devroot, pctldev, &pinconf_pins_ops);
debugfs_create_file("pinconf-groups", S_IFREG | S_IRUGO,
devroot, pctldev, &pinconf_groups_ops);
debugfs_create_file("pinconf-name", (S_IRUGO | S_IWUSR | S_IWGRP),
devroot, pctldev, &pinconf_dbg_pinname_fops);
debugfs_create_file("pinconf-state", (S_IRUGO | S_IWUSR | S_IWGRP),
devroot, pctldev, &pinconf_dbg_pinstate_fops);
debugfs_create_file("pinconf-config", (S_IRUGO | S_IWUSR | S_IWGRP),
devroot, pctldev, &pinconf_dbg_pinconfig_fops);
}
