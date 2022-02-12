int check_user_usb_string(const char *name,
struct usb_gadget_strings *stringtab_dev)
{
unsigned primary_lang;
unsigned sub_lang;
u16 num;
int ret;
ret = kstrtou16(name, 0, &num);
if (ret)
return ret;
primary_lang = num & 0x3ff;
sub_lang = num >> 10;
switch (primary_lang) {
case 0:
case 0x62 ... 0xfe:
case 0x100 ... 0x3ff:
return -EINVAL;
}
if (!sub_lang)
return -EINVAL;
stringtab_dev->language = num;
return 0;
}
static int usb_string_copy(const char *s, char **s_copy)
{
int ret;
char *str;
char *copy = *s_copy;
ret = strlen(s);
if (ret > 126)
return -EOVERFLOW;
str = kstrdup(s, GFP_KERNEL);
if (!str)
return -ENOMEM;
if (str[ret - 1] == '\n')
str[ret - 1] = '\0';
kfree(copy);
*s_copy = str;
return 0;
}
static ssize_t is_valid_bcd(u16 bcd_val)
{
if ((bcd_val & 0xf) > 9)
return -EINVAL;
if (((bcd_val >> 4) & 0xf) > 9)
return -EINVAL;
if (((bcd_val >> 8) & 0xf) > 9)
return -EINVAL;
if (((bcd_val >> 12) & 0xf) > 9)
return -EINVAL;
return 0;
}
static ssize_t gadget_dev_desc_bcdDevice_store(struct gadget_info *gi,
const char *page, size_t len)
{
u16 bcdDevice;
int ret;
ret = kstrtou16(page, 0, &bcdDevice);
if (ret)
return ret;
ret = is_valid_bcd(bcdDevice);
if (ret)
return ret;
gi->cdev.desc.bcdDevice = cpu_to_le16(bcdDevice);
return len;
}
static ssize_t gadget_dev_desc_bcdUSB_store(struct gadget_info *gi,
const char *page, size_t len)
{
u16 bcdUSB;
int ret;
ret = kstrtou16(page, 0, &bcdUSB);
if (ret)
return ret;
ret = is_valid_bcd(bcdUSB);
if (ret)
return ret;
gi->cdev.desc.bcdUSB = cpu_to_le16(bcdUSB);
return len;
}
static ssize_t gadget_dev_desc_UDC_show(struct gadget_info *gi, char *page)
{
return sprintf(page, "%s\n", gi->udc_name ?: "");
}
static int unregister_gadget(struct gadget_info *gi)
{
int ret;
if (!gi->udc_name)
return -ENODEV;
ret = usb_gadget_unregister_driver(&gi->composite.gadget_driver);
if (ret)
return ret;
kfree(gi->udc_name);
gi->udc_name = NULL;
return 0;
}
static ssize_t gadget_dev_desc_UDC_store(struct gadget_info *gi,
const char *page, size_t len)
{
char *name;
int ret;
name = kstrdup(page, GFP_KERNEL);
if (!name)
return -ENOMEM;
if (name[len - 1] == '\n')
name[len - 1] = '\0';
mutex_lock(&gi->lock);
if (!strlen(name)) {
ret = unregister_gadget(gi);
if (ret)
goto err;
} else {
if (gi->udc_name) {
ret = -EBUSY;
goto err;
}
ret = udc_attach_driver(name, &gi->composite.gadget_driver);
if (ret)
goto err;
gi->udc_name = name;
}
mutex_unlock(&gi->lock);
return len;
err:
kfree(name);
mutex_unlock(&gi->lock);
return ret;
}
static inline struct gadget_info *to_gadget_info(struct config_item *item)
{
return container_of(to_config_group(item), struct gadget_info, group);
}
static inline struct gadget_strings *to_gadget_strings(struct config_item *item)
{
return container_of(to_config_group(item), struct gadget_strings,
group);
}
static inline struct gadget_config_name *to_gadget_config_name(
struct config_item *item)
{
return container_of(to_config_group(item), struct gadget_config_name,
group);
}
static inline struct config_usb_cfg *to_config_usb_cfg(struct config_item *item)
{
return container_of(to_config_group(item), struct config_usb_cfg,
group);
}
static inline struct usb_function_instance *to_usb_function_instance(
struct config_item *item)
{
return container_of(to_config_group(item),
struct usb_function_instance, group);
}
static void gadget_info_attr_release(struct config_item *item)
{
struct gadget_info *gi = to_gadget_info(item);
WARN_ON(!list_empty(&gi->cdev.configs));
WARN_ON(!list_empty(&gi->string_list));
WARN_ON(!list_empty(&gi->available_func));
kfree(gi->composite.gadget_driver.function);
kfree(gi);
}
static void gadget_config_attr_release(struct config_item *item)
{
struct config_usb_cfg *cfg = to_config_usb_cfg(item);
WARN_ON(!list_empty(&cfg->c.functions));
list_del(&cfg->c.list);
kfree(cfg->c.label);
kfree(cfg);
}
static int config_usb_cfg_link(
struct config_item *usb_cfg_ci,
struct config_item *usb_func_ci)
{
struct config_usb_cfg *cfg = to_config_usb_cfg(usb_cfg_ci);
struct usb_composite_dev *cdev = cfg->c.cdev;
struct gadget_info *gi = container_of(cdev, struct gadget_info, cdev);
struct config_group *group = to_config_group(usb_func_ci);
struct usb_function_instance *fi = container_of(group,
struct usb_function_instance, group);
struct usb_function_instance *a_fi;
struct usb_function *f;
int ret;
mutex_lock(&gi->lock);
list_for_each_entry(a_fi, &gi->available_func, cfs_list) {
if (a_fi == fi)
break;
}
if (a_fi != fi) {
ret = -EINVAL;
goto out;
}
list_for_each_entry(f, &cfg->func_list, list) {
if (f->fi == fi) {
ret = -EEXIST;
goto out;
}
}
f = usb_get_function(fi);
if (IS_ERR(f)) {
ret = PTR_ERR(f);
goto out;
}
list_add_tail(&f->list, &cfg->func_list);
ret = 0;
out:
mutex_unlock(&gi->lock);
return ret;
}
static int config_usb_cfg_unlink(
struct config_item *usb_cfg_ci,
struct config_item *usb_func_ci)
{
struct config_usb_cfg *cfg = to_config_usb_cfg(usb_cfg_ci);
struct usb_composite_dev *cdev = cfg->c.cdev;
struct gadget_info *gi = container_of(cdev, struct gadget_info, cdev);
struct config_group *group = to_config_group(usb_func_ci);
struct usb_function_instance *fi = container_of(group,
struct usb_function_instance, group);
struct usb_function *f;
mutex_lock(&gi->lock);
if (gi->udc_name)
unregister_gadget(gi);
WARN_ON(gi->udc_name);
list_for_each_entry(f, &cfg->func_list, list) {
if (f->fi == fi) {
list_del(&f->list);
usb_put_function(f);
mutex_unlock(&gi->lock);
return 0;
}
}
mutex_unlock(&gi->lock);
WARN(1, "Unable to locate function to unbind\n");
return 0;
}
static ssize_t gadget_config_desc_MaxPower_show(struct config_usb_cfg *cfg,
char *page)
{
return sprintf(page, "%u\n", cfg->c.MaxPower);
}
static ssize_t gadget_config_desc_MaxPower_store(struct config_usb_cfg *cfg,
const char *page, size_t len)
{
u16 val;
int ret;
ret = kstrtou16(page, 0, &val);
if (ret)
return ret;
if (DIV_ROUND_UP(val, 8) > 0xff)
return -ERANGE;
cfg->c.MaxPower = val;
return len;
}
static ssize_t gadget_config_desc_bmAttributes_show(struct config_usb_cfg *cfg,
char *page)
{
return sprintf(page, "0x%02x\n", cfg->c.bmAttributes);
}
static ssize_t gadget_config_desc_bmAttributes_store(struct config_usb_cfg *cfg,
const char *page, size_t len)
{
u8 val;
int ret;
ret = kstrtou8(page, 0, &val);
if (ret)
return ret;
if (!(val & USB_CONFIG_ATT_ONE))
return -EINVAL;
if (val & ~(USB_CONFIG_ATT_ONE | USB_CONFIG_ATT_SELFPOWER |
USB_CONFIG_ATT_WAKEUP))
return -EINVAL;
cfg->c.bmAttributes = val;
return len;
}
static void composite_init_dev(struct usb_composite_dev *cdev)
{
spin_lock_init(&cdev->lock);
INIT_LIST_HEAD(&cdev->configs);
INIT_LIST_HEAD(&cdev->gstrings);
}
static struct config_group *function_make(
struct config_group *group,
const char *name)
{
struct gadget_info *gi;
struct usb_function_instance *fi;
char buf[MAX_NAME_LEN];
char *func_name;
char *instance_name;
int ret;
ret = snprintf(buf, MAX_NAME_LEN, "%s", name);
if (ret >= MAX_NAME_LEN)
return ERR_PTR(-ENAMETOOLONG);
func_name = buf;
instance_name = strchr(func_name, '.');
if (!instance_name) {
pr_err("Unable to locate . in FUNC.INSTANCE\n");
return ERR_PTR(-EINVAL);
}
*instance_name = '\0';
instance_name++;
fi = usb_get_function_instance(func_name);
if (IS_ERR(fi))
return ERR_CAST(fi);
ret = config_item_set_name(&fi->group.cg_item, name);
if (ret) {
usb_put_function_instance(fi);
return ERR_PTR(ret);
}
if (fi->set_inst_name) {
ret = fi->set_inst_name(fi, instance_name);
if (ret) {
usb_put_function_instance(fi);
return ERR_PTR(ret);
}
}
gi = container_of(group, struct gadget_info, functions_group);
mutex_lock(&gi->lock);
list_add_tail(&fi->cfs_list, &gi->available_func);
mutex_unlock(&gi->lock);
return &fi->group;
}
static void function_drop(
struct config_group *group,
struct config_item *item)
{
struct usb_function_instance *fi = to_usb_function_instance(item);
struct gadget_info *gi;
gi = container_of(group, struct gadget_info, functions_group);
mutex_lock(&gi->lock);
list_del(&fi->cfs_list);
mutex_unlock(&gi->lock);
config_item_put(item);
}
static void gadget_config_name_attr_release(struct config_item *item)
{
struct gadget_config_name *cn = to_gadget_config_name(item);
kfree(cn->configuration);
list_del(&cn->list);
kfree(cn);
}
static struct config_group *config_desc_make(
struct config_group *group,
const char *name)
{
struct gadget_info *gi;
struct config_usb_cfg *cfg;
char buf[MAX_NAME_LEN];
char *num_str;
u8 num;
int ret;
gi = container_of(group, struct gadget_info, configs_group);
ret = snprintf(buf, MAX_NAME_LEN, "%s", name);
if (ret >= MAX_NAME_LEN)
return ERR_PTR(-ENAMETOOLONG);
num_str = strchr(buf, '.');
if (!num_str) {
pr_err("Unable to locate . in name.bConfigurationValue\n");
return ERR_PTR(-EINVAL);
}
*num_str = '\0';
num_str++;
if (!strlen(buf))
return ERR_PTR(-EINVAL);
ret = kstrtou8(num_str, 0, &num);
if (ret)
return ERR_PTR(ret);
cfg = kzalloc(sizeof(*cfg), GFP_KERNEL);
if (!cfg)
return ERR_PTR(-ENOMEM);
cfg->c.label = kstrdup(buf, GFP_KERNEL);
if (!cfg->c.label) {
ret = -ENOMEM;
goto err;
}
cfg->c.bConfigurationValue = num;
cfg->c.MaxPower = CONFIG_USB_GADGET_VBUS_DRAW;
cfg->c.bmAttributes = USB_CONFIG_ATT_ONE;
INIT_LIST_HEAD(&cfg->string_list);
INIT_LIST_HEAD(&cfg->func_list);
cfg->group.default_groups = cfg->default_groups;
cfg->default_groups[0] = &cfg->strings_group;
config_group_init_type_name(&cfg->group, name,
&gadget_config_type);
config_group_init_type_name(&cfg->strings_group, "strings",
&gadget_config_name_strings_type);
ret = usb_add_config_only(&gi->cdev, &cfg->c);
if (ret)
goto err;
return &cfg->group;
err:
kfree(cfg->c.label);
kfree(cfg);
return ERR_PTR(ret);
}
static void config_desc_drop(
struct config_group *group,
struct config_item *item)
{
config_item_put(item);
}
static void gadget_strings_attr_release(struct config_item *item)
{
struct gadget_strings *gs = to_gadget_strings(item);
kfree(gs->manufacturer);
kfree(gs->product);
kfree(gs->serialnumber);
list_del(&gs->list);
kfree(gs);
}
static int configfs_do_nothing(struct usb_composite_dev *cdev)
{
WARN_ON(1);
return -EINVAL;
}
static void purge_configs_funcs(struct gadget_info *gi)
{
struct usb_configuration *c;
list_for_each_entry(c, &gi->cdev.configs, list) {
struct usb_function *f, *tmp;
struct config_usb_cfg *cfg;
cfg = container_of(c, struct config_usb_cfg, c);
list_for_each_entry_safe(f, tmp, &c->functions, list) {
list_move_tail(&f->list, &cfg->func_list);
if (f->unbind) {
dev_err(&gi->cdev.gadget->dev, "unbind function"
" '%s'/%p\n", f->name, f);
f->unbind(c, f);
}
}
c->next_interface_id = 0;
c->superspeed = 0;
c->highspeed = 0;
c->fullspeed = 0;
}
}
static int configfs_composite_bind(struct usb_gadget *gadget,
struct usb_gadget_driver *gdriver)
{
struct usb_composite_driver *composite = to_cdriver(gdriver);
struct gadget_info *gi = container_of(composite,
struct gadget_info, composite);
struct usb_composite_dev *cdev = &gi->cdev;
struct usb_configuration *c;
struct usb_string *s;
unsigned i;
int ret;
cdev->gadget = gadget;
set_gadget_data(gadget, cdev);
ret = composite_dev_prepare(composite, cdev);
if (ret)
return ret;
ret = -EINVAL;
if (list_empty(&gi->cdev.configs)) {
pr_err("Need atleast one configuration in %s.\n",
gi->composite.name);
goto err_comp_cleanup;
}
list_for_each_entry(c, &gi->cdev.configs, list) {
struct config_usb_cfg *cfg;
cfg = container_of(c, struct config_usb_cfg, c);
if (list_empty(&cfg->func_list)) {
pr_err("Config %s/%d of %s needs atleast one function.\n",
c->label, c->bConfigurationValue,
gi->composite.name);
goto err_comp_cleanup;
}
}
if (!list_empty(&gi->string_list)) {
struct gadget_strings *gs;
i = 0;
list_for_each_entry(gs, &gi->string_list, list) {
gi->gstrings[i] = &gs->stringtab_dev;
gs->stringtab_dev.strings = gs->strings;
gs->strings[USB_GADGET_MANUFACTURER_IDX].s =
gs->manufacturer;
gs->strings[USB_GADGET_PRODUCT_IDX].s = gs->product;
gs->strings[USB_GADGET_SERIAL_IDX].s = gs->serialnumber;
i++;
}
gi->gstrings[i] = NULL;
s = usb_gstrings_attach(&gi->cdev, gi->gstrings,
USB_GADGET_FIRST_AVAIL_IDX);
if (IS_ERR(s)) {
ret = PTR_ERR(s);
goto err_comp_cleanup;
}
gi->cdev.desc.iManufacturer = s[USB_GADGET_MANUFACTURER_IDX].id;
gi->cdev.desc.iProduct = s[USB_GADGET_PRODUCT_IDX].id;
gi->cdev.desc.iSerialNumber = s[USB_GADGET_SERIAL_IDX].id;
}
list_for_each_entry(c, &gi->cdev.configs, list) {
struct config_usb_cfg *cfg;
struct usb_function *f;
struct usb_function *tmp;
struct gadget_config_name *cn;
cfg = container_of(c, struct config_usb_cfg, c);
if (!list_empty(&cfg->string_list)) {
i = 0;
list_for_each_entry(cn, &cfg->string_list, list) {
cfg->gstrings[i] = &cn->stringtab_dev;
cn->stringtab_dev.strings = &cn->strings;
cn->strings.s = cn->configuration;
i++;
}
cfg->gstrings[i] = NULL;
s = usb_gstrings_attach(&gi->cdev, cfg->gstrings, 1);
if (IS_ERR(s)) {
ret = PTR_ERR(s);
goto err_comp_cleanup;
}
c->iConfiguration = s[0].id;
}
list_for_each_entry_safe(f, tmp, &cfg->func_list, list) {
list_del(&f->list);
ret = usb_add_function(c, f);
if (ret) {
list_add(&f->list, &cfg->func_list);
goto err_purge_funcs;
}
}
usb_ep_autoconfig_reset(cdev->gadget);
}
usb_ep_autoconfig_reset(cdev->gadget);
return 0;
err_purge_funcs:
purge_configs_funcs(gi);
err_comp_cleanup:
composite_dev_cleanup(cdev);
return ret;
}
static void configfs_composite_unbind(struct usb_gadget *gadget)
{
struct usb_composite_dev *cdev;
struct gadget_info *gi;
cdev = get_gadget_data(gadget);
gi = container_of(cdev, struct gadget_info, cdev);
purge_configs_funcs(gi);
composite_dev_cleanup(cdev);
usb_ep_autoconfig_reset(cdev->gadget);
cdev->gadget = NULL;
set_gadget_data(gadget, NULL);
}
static struct config_group *gadgets_make(
struct config_group *group,
const char *name)
{
struct gadget_info *gi;
gi = kzalloc(sizeof(*gi), GFP_KERNEL);
if (!gi)
return ERR_PTR(-ENOMEM);
gi->group.default_groups = gi->default_groups;
gi->group.default_groups[0] = &gi->functions_group;
gi->group.default_groups[1] = &gi->configs_group;
gi->group.default_groups[2] = &gi->strings_group;
config_group_init_type_name(&gi->functions_group, "functions",
&functions_type);
config_group_init_type_name(&gi->configs_group, "configs",
&config_desc_type);
config_group_init_type_name(&gi->strings_group, "strings",
&gadget_strings_strings_type);
gi->composite.bind = configfs_do_nothing;
gi->composite.unbind = configfs_do_nothing;
gi->composite.suspend = NULL;
gi->composite.resume = NULL;
gi->composite.max_speed = USB_SPEED_SUPER;
mutex_init(&gi->lock);
INIT_LIST_HEAD(&gi->string_list);
INIT_LIST_HEAD(&gi->available_func);
composite_init_dev(&gi->cdev);
gi->cdev.desc.bLength = USB_DT_DEVICE_SIZE;
gi->cdev.desc.bDescriptorType = USB_DT_DEVICE;
gi->cdev.desc.bcdDevice = cpu_to_le16(get_default_bcdDevice());
gi->composite.gadget_driver = configfs_driver_template;
gi->composite.gadget_driver.function = kstrdup(name, GFP_KERNEL);
gi->composite.name = gi->composite.gadget_driver.function;
if (!gi->composite.gadget_driver.function)
goto err;
#ifdef CONFIG_USB_OTG
gi->otg.bLength = sizeof(struct usb_otg_descriptor);
gi->otg.bDescriptorType = USB_DT_OTG;
gi->otg.bmAttributes = USB_OTG_SRP | USB_OTG_HNP;
#endif
config_group_init_type_name(&gi->group, name,
&gadget_root_type);
return &gi->group;
err:
kfree(gi);
return ERR_PTR(-ENOMEM);
}
static void gadgets_drop(struct config_group *group, struct config_item *item)
{
config_item_put(item);
}
void unregister_gadget_item(struct config_item *item)
{
struct gadget_info *gi = to_gadget_info(item);
unregister_gadget(gi);
}
static int __init gadget_cfs_init(void)
{
int ret;
config_group_init(&gadget_subsys.su_group);
ret = configfs_register_subsystem(&gadget_subsys);
return ret;
}
static void __exit gadget_cfs_exit(void)
{
configfs_unregister_subsystem(&gadget_subsys);
}
