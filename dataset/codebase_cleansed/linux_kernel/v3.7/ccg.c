static void ccg_work(struct work_struct *data)
{
struct ccg_dev *dev = container_of(data, struct ccg_dev, work);
struct usb_composite_dev *cdev = dev->cdev;
static char *disconnected[2] = { "USB_STATE=DISCONNECTED", NULL };
static char *connected[2] = { "USB_STATE=CONNECTED", NULL };
static char *configured[2] = { "USB_STATE=CONFIGURED", NULL };
char **uevent_envp = NULL;
unsigned long flags;
spin_lock_irqsave(&cdev->lock, flags);
if (cdev->config)
uevent_envp = configured;
else if (dev->connected != dev->sw_connected)
uevent_envp = dev->connected ? connected : disconnected;
dev->sw_connected = dev->connected;
spin_unlock_irqrestore(&cdev->lock, flags);
if (uevent_envp) {
kobject_uevent_env(&dev->dev->kobj, KOBJ_CHANGE, uevent_envp);
pr_info("%s: sent uevent %s\n", __func__, uevent_envp[0]);
} else {
pr_info("%s: did not send uevent (%d %d %p)\n", __func__,
dev->connected, dev->sw_connected, cdev->config);
}
}
static struct ffs_obj *functionfs_find_dev(struct ccg_dev *dev,
const char *dev_name)
{
int i;
for (i = 0; i < dev->max_func_num; i++)
if (strcmp(dev->ffs_tab[i].name, dev_name) == 0)
return &dev->ffs_tab[i];
return NULL;
}
static bool functionfs_all_ready(struct ccg_dev *dev)
{
int i;
for (i = 0; i < dev->max_func_num; i++)
if (dev->ffs_tab[i].used && !dev->ffs_tab[i].desc_ready)
return false;
return true;
}
static int functionfs_ready_callback(struct ffs_data *ffs)
{
struct ffs_obj *ffs_obj;
int ret;
mutex_lock(&_ccg_dev->mutex);
ffs_obj = ffs->private_data;
if (!ffs_obj) {
ret = -EINVAL;
goto done;
}
if (WARN_ON(ffs_obj->desc_ready)) {
ret = -EBUSY;
goto done;
}
ffs_obj->ffs_data = ffs;
if (functionfs_all_ready(_ccg_dev)) {
ret = -EBUSY;
goto done;
}
ffs_obj->desc_ready = true;
done:
mutex_unlock(&_ccg_dev->mutex);
return ret;
}
static void reset_usb(struct ccg_dev *dev)
{
usb_ep_dequeue(dev->cdev->gadget->ep0, dev->cdev->req);
usb_remove_config(dev->cdev, &ccg_config_driver);
dev->enabled = false;
usb_gadget_disconnect(dev->cdev->gadget);
}
static void functionfs_closed_callback(struct ffs_data *ffs)
{
struct ffs_obj *ffs_obj;
mutex_lock(&_ccg_dev->mutex);
ffs_obj = ffs->private_data;
if (!ffs_obj)
goto done;
ffs_obj->desc_ready = false;
if (_ccg_dev->enabled)
reset_usb(_ccg_dev);
done:
mutex_unlock(&_ccg_dev->mutex);
}
static void *functionfs_acquire_dev_callback(const char *dev_name)
{
struct ffs_obj *ffs_dev;
mutex_lock(&_ccg_dev->mutex);
ffs_dev = functionfs_find_dev(_ccg_dev, dev_name);
if (!ffs_dev) {
ffs_dev = ERR_PTR(-ENODEV);
goto done;
}
if (ffs_dev->mounted) {
ffs_dev = ERR_PTR(-EBUSY);
goto done;
}
ffs_dev->mounted = true;
done:
mutex_unlock(&_ccg_dev->mutex);
return ffs_dev;
}
static void functionfs_release_dev_callback(struct ffs_data *ffs_data)
{
struct ffs_obj *ffs_dev;
mutex_lock(&_ccg_dev->mutex);
ffs_dev = ffs_data->private_data;
if (ffs_dev)
ffs_dev->mounted = false;
mutex_unlock(&_ccg_dev->mutex);
}
static int functionfs_function_init(struct ccg_usb_function *f,
struct usb_composite_dev *cdev)
{
return functionfs_init();
}
static void functionfs_function_cleanup(struct ccg_usb_function *f)
{
functionfs_cleanup();
}
static int functionfs_function_bind_config(struct ccg_usb_function *f,
struct usb_configuration *c)
{
struct ccg_dev *dev = _ccg_dev;
int i, ret;
for (i = dev->max_func_num; i--; ) {
if (!dev->ffs_tab[i].used)
continue;
ret = functionfs_bind(dev->ffs_tab[i].ffs_data, c->cdev);
if (unlikely(ret < 0)) {
while (++i < dev->max_func_num)
functionfs_unbind(dev->ffs_tab[i].ffs_data);
return ret;
}
}
for (i = dev->max_func_num; i--; ) {
if (!dev->ffs_tab[i].used)
continue;
ret = functionfs_bind_config(c->cdev, c,
dev->ffs_tab[i].ffs_data);
if (unlikely(ret < 0))
return ret;
}
return 0;
}
static void functionfs_function_unbind_config(struct ccg_usb_function *f,
struct usb_configuration *c)
{
struct ccg_dev *dev = _ccg_dev;
int i;
for (i = dev->max_func_num; i--; )
if (dev->ffs_tab[i].ffs_data)
functionfs_unbind(dev->ffs_tab[i].ffs_data);
}
static ssize_t functionfs_user_functions_show(struct device *_dev,
struct device_attribute *attr,
char *buf)
{
struct ccg_dev *dev = _ccg_dev;
char *buff = buf;
int i;
mutex_lock(&dev->mutex);
for (i = 0; i < dev->max_func_num; i++)
buff += snprintf(buff, PAGE_SIZE + buf - buff, "%s,",
dev->ffs_tab[i].name);
mutex_unlock(&dev->mutex);
if (buff != buf)
*(buff - 1) = '\n';
return buff - buf;
}
static ssize_t functionfs_user_functions_store(struct device *_dev,
struct device_attribute *attr,
const char *buff, size_t size)
{
struct ccg_dev *dev = _ccg_dev;
char *name, *b;
ssize_t ret = size;
int i;
buff = skip_spaces(buff);
if (!*buff)
return -EINVAL;
mutex_lock(&dev->mutex);
if (dev->enabled) {
ret = -EBUSY;
goto end;
}
for (i = 0; i < dev->max_func_num; i++)
if (dev->ffs_tab[i].mounted) {
ret = -EBUSY;
goto end;
}
strlcpy(func_names_buf, buff, sizeof(func_names_buf));
b = strim(func_names_buf);
dev->max_func_num = 0;
while (b) {
name = strsep(&b, ",");
if (dev->max_func_num == GFS_MAX_DEVS) {
ret = -ENOSPC;
goto end;
}
if (functionfs_find_dev(dev, name)) {
ret = -EEXIST;
continue;
}
dev->ffs_tab[dev->max_func_num++].name = name;
}
end:
mutex_unlock(&dev->mutex);
return ret;
}
static ssize_t functionfs_max_user_functions_show(struct device *_dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%d", GFS_MAX_DEVS);
}
static int
acm_function_init(struct ccg_usb_function *f, struct usb_composite_dev *cdev)
{
f->config = kzalloc(sizeof(struct acm_function_config), GFP_KERNEL);
if (!f->config)
return -ENOMEM;
return gserial_setup(cdev->gadget, MAX_ACM_INSTANCES);
}
static void acm_function_cleanup(struct ccg_usb_function *f)
{
gserial_cleanup();
kfree(f->config);
f->config = NULL;
}
static int
acm_function_bind_config(struct ccg_usb_function *f,
struct usb_configuration *c)
{
int i;
int ret = 0;
struct acm_function_config *config = f->config;
for (i = 0; i < config->instances; i++) {
ret = acm_bind_config(c, i);
if (ret) {
pr_err("Could not bind acm%u config\n", i);
break;
}
}
return ret;
}
static ssize_t acm_instances_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ccg_usb_function *f = dev_get_drvdata(dev);
struct acm_function_config *config = f->config;
return sprintf(buf, "%d\n", config->instances);
}
static ssize_t acm_instances_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct ccg_usb_function *f = dev_get_drvdata(dev);
struct acm_function_config *config = f->config;
int value;
int ret = 0;
ret = kstrtoint(buf, 10, &value);
if (ret)
return ret;
if (value > MAX_ACM_INSTANCES)
return -EINVAL;
config->instances = value;
return size;
}
static int rndis_function_init(struct ccg_usb_function *f,
struct usb_composite_dev *cdev)
{
f->config = kzalloc(sizeof(struct rndis_function_config), GFP_KERNEL);
if (!f->config)
return -ENOMEM;
return 0;
}
static void rndis_function_cleanup(struct ccg_usb_function *f)
{
kfree(f->config);
f->config = NULL;
}
static int rndis_function_bind_config(struct ccg_usb_function *f,
struct usb_configuration *c)
{
int ret;
struct rndis_function_config *rndis = f->config;
if (!rndis) {
pr_err("%s: rndis_pdata\n", __func__);
return -1;
}
pr_info("%s MAC: %pM\n", __func__, rndis->ethaddr);
ret = gether_setup_name(c->cdev->gadget, rndis->ethaddr, "rndis");
if (ret) {
pr_err("%s: gether_setup failed\n", __func__);
return ret;
}
if (rndis->wceis) {
rndis_iad_descriptor.bFunctionClass =
USB_CLASS_WIRELESS_CONTROLLER;
rndis_iad_descriptor.bFunctionSubClass = 0x01;
rndis_iad_descriptor.bFunctionProtocol = 0x03;
rndis_control_intf.bInterfaceClass =
USB_CLASS_WIRELESS_CONTROLLER;
rndis_control_intf.bInterfaceSubClass = 0x01;
rndis_control_intf.bInterfaceProtocol = 0x03;
}
return rndis_bind_config_vendor(c, rndis->ethaddr, rndis->vendorID,
rndis->manufacturer);
}
static void rndis_function_unbind_config(struct ccg_usb_function *f,
struct usb_configuration *c)
{
gether_cleanup();
}
static ssize_t rndis_manufacturer_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ccg_usb_function *f = dev_get_drvdata(dev);
struct rndis_function_config *config = f->config;
return sprintf(buf, "%s\n", config->manufacturer);
}
static ssize_t rndis_manufacturer_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct ccg_usb_function *f = dev_get_drvdata(dev);
struct rndis_function_config *config = f->config;
if (size >= sizeof(config->manufacturer))
return -EINVAL;
memcpy(config->manufacturer, buf, size);
config->manufacturer[size] = 0;
return size;
}
static ssize_t rndis_wceis_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ccg_usb_function *f = dev_get_drvdata(dev);
struct rndis_function_config *config = f->config;
return sprintf(buf, "%d\n", config->wceis);
}
static ssize_t rndis_wceis_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct ccg_usb_function *f = dev_get_drvdata(dev);
struct rndis_function_config *config = f->config;
int value;
int ret;
ret = kstrtoint(buf, 10, &value);
if (ret)
return ret;
config->wceis = value;
return size;
}
static ssize_t rndis_ethaddr_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ccg_usb_function *f = dev_get_drvdata(dev);
struct rndis_function_config *rndis = f->config;
return sprintf(buf, "%pM\n", rndis->ethaddr);
}
static ssize_t rndis_ethaddr_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct ccg_usb_function *f = dev_get_drvdata(dev);
struct rndis_function_config *rndis = f->config;
unsigned char tmp[6];
if (sscanf(buf, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx",
tmp + 0, tmp + 1, tmp + 2, tmp + 3, tmp + 4, tmp + 5) !=
ETH_ALEN)
return -EINVAL;
memcpy(rndis->ethaddr, tmp, ETH_ALEN);
return ETH_ALEN;
}
static ssize_t rndis_vendorID_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ccg_usb_function *f = dev_get_drvdata(dev);
struct rndis_function_config *config = f->config;
return sprintf(buf, "%04x\n", config->vendorID);
}
static ssize_t rndis_vendorID_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct ccg_usb_function *f = dev_get_drvdata(dev);
struct rndis_function_config *config = f->config;
int value;
int ret;
ret = kstrtou32(buf, 16, &value);
if (ret)
return ret;
config->vendorID = value;
return size;
}
static int mass_storage_function_init(struct ccg_usb_function *f,
struct usb_composite_dev *cdev)
{
struct fsg_config fsg;
struct fsg_common *common;
int err;
memset(&fsg, 0, sizeof(fsg));
fsg.nluns = 1;
fsg.luns[0].removable = 1;
fsg.vendor_name = iManufacturer;
fsg.product_name = iProduct;
common = fsg_common_init(NULL, cdev, &fsg);
if (IS_ERR(common))
return PTR_ERR(common);
err = sysfs_create_link(&f->dev->kobj,
&common->luns[0].dev.kobj,
"lun");
if (err) {
fsg_common_put(common);
return err;
}
f->config = common;
return 0;
}
static void mass_storage_function_cleanup(struct ccg_usb_function *f)
{
fsg_common_put(f->config);
f->config = NULL;
}
static int mass_storage_function_bind_config(struct ccg_usb_function *f,
struct usb_configuration *c)
{
struct fsg_common *common = f->config;
return fsg_bind_config(c->cdev, c, common);
}
static int ccg_init_functions(struct ccg_usb_function **functions,
struct usb_composite_dev *cdev)
{
struct ccg_dev *dev = _ccg_dev;
struct ccg_usb_function *f;
struct device_attribute **attrs;
struct device_attribute *attr;
int err;
int index = 0;
for (; (f = *functions++); index++) {
f->dev_name = kasprintf(GFP_KERNEL, "f_%s", f->name);
if (!f->dev_name) {
pr_err("%s: Failed to alloc name %s", __func__,
f->name);
err = -ENOMEM;
goto err_alloc;
}
f->dev = device_create(ccg_class, dev->dev,
MKDEV(0, index), f, f->dev_name);
if (IS_ERR(f->dev)) {
pr_err("%s: Failed to create dev %s", __func__,
f->dev_name);
err = PTR_ERR(f->dev);
f->dev = NULL;
goto err_create;
}
if (f->init) {
err = f->init(f, cdev);
if (err) {
pr_err("%s: Failed to init %s", __func__,
f->name);
goto err_out;
}
}
attrs = f->attributes;
if (attrs) {
while ((attr = *attrs++) && !err)
err = device_create_file(f->dev, attr);
}
if (err) {
pr_err("%s: Failed to create function %s attributes",
__func__, f->name);
goto err_uninit;
}
}
return 0;
err_uninit:
if (f->cleanup)
f->cleanup(f);
err_out:
device_destroy(ccg_class, f->dev->devt);
f->dev = NULL;
err_create:
kfree(f->dev_name);
err_alloc:
return err;
}
static void ccg_cleanup_functions(struct ccg_usb_function **functions)
{
struct ccg_usb_function *f;
while (*functions) {
f = *functions++;
if (f->dev) {
if (f->cleanup)
f->cleanup(f);
device_destroy(ccg_class, f->dev->devt);
kfree(f->dev_name);
}
}
}
static int ccg_bind_enabled_functions(struct ccg_dev *dev,
struct usb_configuration *c)
{
struct ccg_usb_function *f;
int ret;
list_for_each_entry(f, &dev->enabled_functions, enabled_list) {
ret = f->bind_config(f, c);
if (ret) {
pr_err("%s: %s failed", __func__, f->name);
return ret;
}
}
return 0;
}
static void ccg_unbind_enabled_functions(struct ccg_dev *dev,
struct usb_configuration *c)
{
struct ccg_usb_function *f;
list_for_each_entry(f, &dev->enabled_functions, enabled_list)
if (f->unbind_config)
f->unbind_config(f, c);
}
static int ccg_enable_function(struct ccg_dev *dev, char *name)
{
struct ccg_usb_function **functions = dev->functions;
struct ccg_usb_function *f;
while ((f = *functions++)) {
if (!strcmp(name, f->name)) {
list_add_tail(&f->enabled_list,
&dev->enabled_functions);
return 0;
}
}
return -EINVAL;
}
static ssize_t
functions_show(struct device *pdev, struct device_attribute *attr, char *buf)
{
struct ccg_dev *dev = dev_get_drvdata(pdev);
struct ccg_usb_function *f;
char *buff = buf;
int i;
mutex_lock(&dev->mutex);
list_for_each_entry(f, &dev->enabled_functions, enabled_list)
buff += sprintf(buff, "%s,", f->name);
for (i = 0; i < dev->max_func_num; i++)
if (dev->ffs_tab[i].used)
buff += sprintf(buff, "%s", dev->ffs_tab[i].name);
mutex_unlock(&dev->mutex);
if (buff != buf)
*(buff-1) = '\n';
return buff - buf;
}
static ssize_t
functions_store(struct device *pdev, struct device_attribute *attr,
const char *buff, size_t size)
{
struct ccg_dev *dev = dev_get_drvdata(pdev);
char *name;
char buf[256], *b;
int err, i;
bool functionfs_enabled;
buff = skip_spaces(buff);
if (!*buff)
return -EINVAL;
mutex_lock(&dev->mutex);
if (dev->enabled) {
mutex_unlock(&dev->mutex);
return -EBUSY;
}
INIT_LIST_HEAD(&dev->enabled_functions);
functionfs_enabled = false;
for (i = 0; i < dev->max_func_num; i++)
dev->ffs_tab[i].used = false;
strlcpy(buf, buff, sizeof(buf));
b = strim(buf);
while (b) {
struct ffs_obj *user_func;
name = strsep(&b, ",");
if (!strcmp(name, functionfs_function.name)) {
pr_err("ccg_usb: Cannot explicitly enable '%s'", name);
continue;
}
user_func = functionfs_find_dev(dev, name);
if (user_func)
name = functionfs_function.name;
err = 0;
if (!user_func || !functionfs_enabled)
err = ccg_enable_function(dev, name);
if (err)
pr_err("ccg_usb: Cannot enable '%s'", name);
else if (user_func) {
user_func->used = true;
dev->func_num++;
functionfs_enabled = true;
}
}
mutex_unlock(&dev->mutex);
return size;
}
static ssize_t enable_show(struct device *pdev, struct device_attribute *attr,
char *buf)
{
struct ccg_dev *dev = dev_get_drvdata(pdev);
return sprintf(buf, "%d\n", dev->enabled);
}
static ssize_t enable_store(struct device *pdev, struct device_attribute *attr,
const char *buff, size_t size)
{
struct ccg_dev *dev = dev_get_drvdata(pdev);
struct usb_composite_dev *cdev = dev->cdev;
int enabled = 0;
mutex_lock(&dev->mutex);
sscanf(buff, "%d", &enabled);
if (enabled && dev->func_num && !functionfs_all_ready(dev)) {
mutex_unlock(&dev->mutex);
return -ENODEV;
}
if (enabled && !dev->enabled) {
int ret;
cdev->next_string_id = 0;
cdev->desc.bDeviceClass = device_desc.bDeviceClass;
cdev->desc.bDeviceSubClass = device_desc.bDeviceSubClass;
cdev->desc.bDeviceProtocol = device_desc.bDeviceProtocol;
cdev->desc.idVendor = idVendor;
cdev->desc.idProduct = idProduct;
cdev->desc.bcdDevice = bcdDevice;
usb_add_config(cdev, &ccg_config_driver, ccg_bind_config);
dev->enabled = true;
ret = usb_gadget_connect(cdev->gadget);
if (ret) {
dev->enabled = false;
usb_remove_config(cdev, &ccg_config_driver);
}
} else if (!enabled && dev->enabled) {
reset_usb(dev);
} else {
pr_err("ccg_usb: already %s\n",
dev->enabled ? "enabled" : "disabled");
}
mutex_unlock(&dev->mutex);
return size;
}
static ssize_t state_show(struct device *pdev, struct device_attribute *attr,
char *buf)
{
struct ccg_dev *dev = dev_get_drvdata(pdev);
struct usb_composite_dev *cdev = dev->cdev;
char *state = "DISCONNECTED";
unsigned long flags;
if (!cdev)
goto out;
spin_lock_irqsave(&cdev->lock, flags);
if (cdev->config)
state = "CONFIGURED";
else if (dev->connected)
state = "CONNECTED";
spin_unlock_irqrestore(&cdev->lock, flags);
out:
return sprintf(buf, "%s\n", state);
}
static int ccg_bind_config(struct usb_configuration *c)
{
struct ccg_dev *dev = _ccg_dev;
return ccg_bind_enabled_functions(dev, c);
}
static void ccg_unbind_config(struct usb_configuration *c)
{
struct ccg_dev *dev = _ccg_dev;
ccg_unbind_enabled_functions(dev, c);
usb_ep_autoconfig_reset(dev->cdev->gadget);
}
static int ccg_bind(struct usb_composite_dev *cdev)
{
struct ccg_dev *dev = _ccg_dev;
struct usb_gadget *gadget = cdev->gadget;
int gcnum, ret;
usb_gadget_disconnect(gadget);
ret = ccg_init_functions(dev->functions, cdev);
if (ret)
return ret;
gcnum = usb_gadget_controller_number(gadget);
if (gcnum >= 0)
device_desc.bcdDevice = cpu_to_le16(0x0200 + gcnum);
else {
pr_warn("%s: controller '%s' not recognized\n",
longname, gadget->name);
device_desc.bcdDevice = __constant_cpu_to_le16(0x9999);
}
usb_gadget_set_selfpowered(gadget);
dev->cdev = cdev;
return 0;
}
static int ccg_usb_unbind(struct usb_composite_dev *cdev)
{
struct ccg_dev *dev = _ccg_dev;
cancel_work_sync(&dev->work);
ccg_cleanup_functions(dev->functions);
return 0;
}
static int ccg_setup(struct usb_gadget *gadget, const struct usb_ctrlrequest *c)
{
struct ccg_dev *dev = _ccg_dev;
struct usb_composite_dev *cdev = get_gadget_data(gadget);
struct usb_request *req = cdev->req;
struct ccg_usb_function *f;
int value = -EOPNOTSUPP;
unsigned long flags;
req->zero = 0;
req->complete = composite_setup_complete;
req->length = 0;
gadget->ep0->driver_data = cdev;
list_for_each_entry(f, &dev->enabled_functions, enabled_list) {
if (f->ctrlrequest) {
value = f->ctrlrequest(f, cdev, c);
if (value >= 0)
break;
}
}
if (value < 0)
value = composite_setup(gadget, c);
spin_lock_irqsave(&cdev->lock, flags);
if (!dev->connected) {
dev->connected = 1;
schedule_work(&dev->work);
} else if (c->bRequest == USB_REQ_SET_CONFIGURATION &&
cdev->config) {
schedule_work(&dev->work);
}
spin_unlock_irqrestore(&cdev->lock, flags);
return value;
}
static void ccg_disconnect(struct usb_gadget *gadget)
{
struct ccg_dev *dev = _ccg_dev;
struct usb_composite_dev *cdev = get_gadget_data(gadget);
unsigned long flags;
composite_disconnect(gadget);
spin_lock_irqsave(&cdev->lock, flags);
dev->connected = 0;
schedule_work(&dev->work);
spin_unlock_irqrestore(&cdev->lock, flags);
}
static int ccg_create_device(struct ccg_dev *dev)
{
struct device_attribute **attrs = ccg_usb_attributes;
struct device_attribute *attr;
int err;
dev->dev = device_create(ccg_class, NULL, MKDEV(0, 0), NULL, "ccg0");
if (IS_ERR(dev->dev))
return PTR_ERR(dev->dev);
dev_set_drvdata(dev->dev, dev);
while ((attr = *attrs++)) {
err = device_create_file(dev->dev, attr);
if (err) {
device_destroy(ccg_class, dev->dev->devt);
return err;
}
}
return 0;
}
static int __init init(void)
{
struct ccg_dev *dev;
int err;
ccg_class = class_create(THIS_MODULE, "ccg_usb");
if (IS_ERR(ccg_class))
return PTR_ERR(ccg_class);
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev) {
class_destroy(ccg_class);
return -ENOMEM;
}
dev->functions = supported_functions;
INIT_LIST_HEAD(&dev->enabled_functions);
INIT_WORK(&dev->work, ccg_work);
mutex_init(&dev->mutex);
err = ccg_create_device(dev);
if (err) {
class_destroy(ccg_class);
kfree(dev);
return err;
}
_ccg_dev = dev;
composite_driver.setup = ccg_setup;
composite_driver.disconnect = ccg_disconnect;
err = usb_composite_probe(&ccg_usb_driver);
if (err) {
class_destroy(ccg_class);
kfree(dev);
}
return err;
}
static void __exit cleanup(void)
{
usb_composite_unregister(&ccg_usb_driver);
class_destroy(ccg_class);
kfree(_ccg_dev);
_ccg_dev = NULL;
}
