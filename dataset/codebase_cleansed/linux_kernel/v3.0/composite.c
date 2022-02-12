int usb_add_function(struct usb_configuration *config,
struct usb_function *function)
{
int value = -EINVAL;
DBG(config->cdev, "adding '%s'/%p to config '%s'/%p\n",
function->name, function,
config->label, config);
if (!function->set_alt || !function->disable)
goto done;
function->config = config;
list_add_tail(&function->list, &config->functions);
if (function->bind) {
value = function->bind(config, function);
if (value < 0) {
list_del(&function->list);
function->config = NULL;
}
} else
value = 0;
if (!config->fullspeed && function->descriptors)
config->fullspeed = true;
if (!config->highspeed && function->hs_descriptors)
config->highspeed = true;
done:
if (value)
DBG(config->cdev, "adding '%s'/%p --> %d\n",
function->name, function, value);
return value;
}
int usb_function_deactivate(struct usb_function *function)
{
struct usb_composite_dev *cdev = function->config->cdev;
unsigned long flags;
int status = 0;
spin_lock_irqsave(&cdev->lock, flags);
if (cdev->deactivations == 0)
status = usb_gadget_disconnect(cdev->gadget);
if (status == 0)
cdev->deactivations++;
spin_unlock_irqrestore(&cdev->lock, flags);
return status;
}
int usb_function_activate(struct usb_function *function)
{
struct usb_composite_dev *cdev = function->config->cdev;
int status = 0;
spin_lock(&cdev->lock);
if (WARN_ON(cdev->deactivations == 0))
status = -EINVAL;
else {
cdev->deactivations--;
if (cdev->deactivations == 0)
status = usb_gadget_connect(cdev->gadget);
}
spin_unlock(&cdev->lock);
return status;
}
int usb_interface_id(struct usb_configuration *config,
struct usb_function *function)
{
unsigned id = config->next_interface_id;
if (id < MAX_CONFIG_INTERFACES) {
config->interface[id] = function;
config->next_interface_id = id + 1;
return id;
}
return -ENODEV;
}
static int config_buf(struct usb_configuration *config,
enum usb_device_speed speed, void *buf, u8 type)
{
struct usb_config_descriptor *c = buf;
void *next = buf + USB_DT_CONFIG_SIZE;
int len = USB_BUFSIZ - USB_DT_CONFIG_SIZE;
struct usb_function *f;
int status;
c = buf;
c->bLength = USB_DT_CONFIG_SIZE;
c->bDescriptorType = type;
c->bNumInterfaces = config->next_interface_id;
c->bConfigurationValue = config->bConfigurationValue;
c->iConfiguration = config->iConfiguration;
c->bmAttributes = USB_CONFIG_ATT_ONE | config->bmAttributes;
c->bMaxPower = config->bMaxPower ? : (CONFIG_USB_GADGET_VBUS_DRAW / 2);
if (config->descriptors) {
status = usb_descriptor_fillbuf(next, len,
config->descriptors);
if (status < 0)
return status;
len -= status;
next += status;
}
list_for_each_entry(f, &config->functions, list) {
struct usb_descriptor_header **descriptors;
if (speed == USB_SPEED_HIGH)
descriptors = f->hs_descriptors;
else
descriptors = f->descriptors;
if (!descriptors)
continue;
status = usb_descriptor_fillbuf(next, len,
(const struct usb_descriptor_header **) descriptors);
if (status < 0)
return status;
len -= status;
next += status;
}
len = next - buf;
c->wTotalLength = cpu_to_le16(len);
return len;
}
static int config_desc(struct usb_composite_dev *cdev, unsigned w_value)
{
struct usb_gadget *gadget = cdev->gadget;
struct usb_configuration *c;
u8 type = w_value >> 8;
enum usb_device_speed speed = USB_SPEED_UNKNOWN;
if (gadget_is_dualspeed(gadget)) {
int hs = 0;
if (gadget->speed == USB_SPEED_HIGH)
hs = 1;
if (type == USB_DT_OTHER_SPEED_CONFIG)
hs = !hs;
if (hs)
speed = USB_SPEED_HIGH;
}
w_value &= 0xff;
list_for_each_entry(c, &cdev->configs, list) {
if (speed == USB_SPEED_HIGH) {
if (!c->highspeed)
continue;
} else {
if (!c->fullspeed)
continue;
}
if (w_value == 0)
return config_buf(c, speed, cdev->req->buf, type);
w_value--;
}
return -EINVAL;
}
static int count_configs(struct usb_composite_dev *cdev, unsigned type)
{
struct usb_gadget *gadget = cdev->gadget;
struct usb_configuration *c;
unsigned count = 0;
int hs = 0;
if (gadget_is_dualspeed(gadget)) {
if (gadget->speed == USB_SPEED_HIGH)
hs = 1;
if (type == USB_DT_DEVICE_QUALIFIER)
hs = !hs;
}
list_for_each_entry(c, &cdev->configs, list) {
if (hs) {
if (!c->highspeed)
continue;
} else {
if (!c->fullspeed)
continue;
}
count++;
}
return count;
}
static void device_qual(struct usb_composite_dev *cdev)
{
struct usb_qualifier_descriptor *qual = cdev->req->buf;
qual->bLength = sizeof(*qual);
qual->bDescriptorType = USB_DT_DEVICE_QUALIFIER;
qual->bcdUSB = cdev->desc.bcdUSB;
qual->bDeviceClass = cdev->desc.bDeviceClass;
qual->bDeviceSubClass = cdev->desc.bDeviceSubClass;
qual->bDeviceProtocol = cdev->desc.bDeviceProtocol;
qual->bMaxPacketSize0 = cdev->desc.bMaxPacketSize0;
qual->bNumConfigurations = count_configs(cdev, USB_DT_DEVICE_QUALIFIER);
qual->bRESERVED = 0;
}
static void reset_config(struct usb_composite_dev *cdev)
{
struct usb_function *f;
DBG(cdev, "reset config\n");
list_for_each_entry(f, &cdev->config->functions, list) {
if (f->disable)
f->disable(f);
bitmap_zero(f->endpoints, 32);
}
cdev->config = NULL;
}
static int set_config(struct usb_composite_dev *cdev,
const struct usb_ctrlrequest *ctrl, unsigned number)
{
struct usb_gadget *gadget = cdev->gadget;
struct usb_configuration *c = NULL;
int result = -EINVAL;
unsigned power = gadget_is_otg(gadget) ? 8 : 100;
int tmp;
if (cdev->config)
reset_config(cdev);
if (number) {
list_for_each_entry(c, &cdev->configs, list) {
if (c->bConfigurationValue == number) {
result = 0;
break;
}
}
if (result < 0)
goto done;
} else
result = 0;
INFO(cdev, "%s speed config #%d: %s\n",
({ char *speed;
switch (gadget->speed) {
case USB_SPEED_LOW: speed = "low"; break;
case USB_SPEED_FULL: speed = "full"; break;
case USB_SPEED_HIGH: speed = "high"; break;
default: speed = "?"; break;
} ; speed; }), number, c ? c->label : "unconfigured");
if (!c)
goto done;
cdev->config = c;
for (tmp = 0; tmp < MAX_CONFIG_INTERFACES; tmp++) {
struct usb_function *f = c->interface[tmp];
struct usb_descriptor_header **descriptors;
if (!f)
break;
if (gadget->speed == USB_SPEED_HIGH)
descriptors = f->hs_descriptors;
else
descriptors = f->descriptors;
for (; *descriptors; ++descriptors) {
struct usb_endpoint_descriptor *ep;
int addr;
if ((*descriptors)->bDescriptorType != USB_DT_ENDPOINT)
continue;
ep = (struct usb_endpoint_descriptor *)*descriptors;
addr = ((ep->bEndpointAddress & 0x80) >> 3)
| (ep->bEndpointAddress & 0x0f);
set_bit(addr, f->endpoints);
}
result = f->set_alt(f, tmp, 0);
if (result < 0) {
DBG(cdev, "interface %d (%s/%p) alt 0 --> %d\n",
tmp, f->name, f, result);
reset_config(cdev);
goto done;
}
if (result == USB_GADGET_DELAYED_STATUS) {
DBG(cdev,
"%s: interface %d (%s) requested delayed status\n",
__func__, tmp, f->name);
cdev->delayed_status++;
DBG(cdev, "delayed_status count %d\n",
cdev->delayed_status);
}
}
power = c->bMaxPower ? (2 * c->bMaxPower) : CONFIG_USB_GADGET_VBUS_DRAW;
done:
usb_gadget_vbus_draw(gadget, power);
if (result >= 0 && cdev->delayed_status)
result = USB_GADGET_DELAYED_STATUS;
return result;
}
int usb_add_config(struct usb_composite_dev *cdev,
struct usb_configuration *config,
int (*bind)(struct usb_configuration *))
{
int status = -EINVAL;
struct usb_configuration *c;
DBG(cdev, "adding config #%u '%s'/%p\n",
config->bConfigurationValue,
config->label, config);
if (!config->bConfigurationValue || !bind)
goto done;
list_for_each_entry(c, &cdev->configs, list) {
if (c->bConfigurationValue == config->bConfigurationValue) {
status = -EBUSY;
goto done;
}
}
config->cdev = cdev;
list_add_tail(&config->list, &cdev->configs);
INIT_LIST_HEAD(&config->functions);
config->next_interface_id = 0;
status = bind(config);
if (status < 0) {
list_del(&config->list);
config->cdev = NULL;
} else {
unsigned i;
DBG(cdev, "cfg %d/%p speeds:%s%s\n",
config->bConfigurationValue, config,
config->highspeed ? " high" : "",
config->fullspeed
? (gadget_is_dualspeed(cdev->gadget)
? " full"
: " full/low")
: "");
for (i = 0; i < MAX_CONFIG_INTERFACES; i++) {
struct usb_function *f = config->interface[i];
if (!f)
continue;
DBG(cdev, " interface %d = %s/%p\n",
i, f->name, f);
}
}
usb_ep_autoconfig_reset(cdev->gadget);
done:
if (status)
DBG(cdev, "added config '%s'/%u --> %d\n", config->label,
config->bConfigurationValue, status);
return status;
}
static void collect_langs(struct usb_gadget_strings **sp, __le16 *buf)
{
const struct usb_gadget_strings *s;
u16 language;
__le16 *tmp;
while (*sp) {
s = *sp;
language = cpu_to_le16(s->language);
for (tmp = buf; *tmp && tmp < &buf[126]; tmp++) {
if (*tmp == language)
goto repeat;
}
*tmp++ = language;
repeat:
sp++;
}
}
static int lookup_string(
struct usb_gadget_strings **sp,
void *buf,
u16 language,
int id
)
{
struct usb_gadget_strings *s;
int value;
while (*sp) {
s = *sp++;
if (s->language != language)
continue;
value = usb_gadget_get_string(s, id, buf);
if (value > 0)
return value;
}
return -EINVAL;
}
static int get_string(struct usb_composite_dev *cdev,
void *buf, u16 language, int id)
{
struct usb_configuration *c;
struct usb_function *f;
int len;
const char *str;
if (id == 0) {
struct usb_string_descriptor *s = buf;
struct usb_gadget_strings **sp;
memset(s, 0, 256);
s->bDescriptorType = USB_DT_STRING;
sp = composite->strings;
if (sp)
collect_langs(sp, s->wData);
list_for_each_entry(c, &cdev->configs, list) {
sp = c->strings;
if (sp)
collect_langs(sp, s->wData);
list_for_each_entry(f, &c->functions, list) {
sp = f->strings;
if (sp)
collect_langs(sp, s->wData);
}
}
for (len = 0; len <= 126 && s->wData[len]; len++)
continue;
if (!len)
return -EINVAL;
s->bLength = 2 * (len + 1);
return s->bLength;
}
if (cdev->manufacturer_override == id)
str = iManufacturer ?: composite->iManufacturer ?:
composite_manufacturer;
else if (cdev->product_override == id)
str = iProduct ?: composite->iProduct;
else if (cdev->serial_override == id)
str = iSerialNumber;
else
str = NULL;
if (str) {
struct usb_gadget_strings strings = {
.language = language,
.strings = &(struct usb_string) { 0xff, str }
};
return usb_gadget_get_string(&strings, 0xff, buf);
}
if (composite->strings) {
len = lookup_string(composite->strings, buf, language, id);
if (len > 0)
return len;
}
list_for_each_entry(c, &cdev->configs, list) {
if (c->strings) {
len = lookup_string(c->strings, buf, language, id);
if (len > 0)
return len;
}
list_for_each_entry(f, &c->functions, list) {
if (!f->strings)
continue;
len = lookup_string(f->strings, buf, language, id);
if (len > 0)
return len;
}
}
return -EINVAL;
}
int usb_string_id(struct usb_composite_dev *cdev)
{
if (cdev->next_string_id < 254) {
cdev->next_string_id++;
return cdev->next_string_id;
}
return -ENODEV;
}
int usb_string_ids_tab(struct usb_composite_dev *cdev, struct usb_string *str)
{
int next = cdev->next_string_id;
for (; str->s; ++str) {
if (unlikely(next >= 254))
return -ENODEV;
str->id = ++next;
}
cdev->next_string_id = next;
return 0;
}
int usb_string_ids_n(struct usb_composite_dev *c, unsigned n)
{
unsigned next = c->next_string_id;
if (unlikely(n > 254 || (unsigned)next + n > 254))
return -ENODEV;
c->next_string_id += n;
return next + 1;
}
static void composite_setup_complete(struct usb_ep *ep, struct usb_request *req)
{
if (req->status || req->actual != req->length)
DBG((struct usb_composite_dev *) ep->driver_data,
"setup complete --> %d, %d/%d\n",
req->status, req->actual, req->length);
}
static int
composite_setup(struct usb_gadget *gadget, const struct usb_ctrlrequest *ctrl)
{
struct usb_composite_dev *cdev = get_gadget_data(gadget);
struct usb_request *req = cdev->req;
int value = -EOPNOTSUPP;
u16 w_index = le16_to_cpu(ctrl->wIndex);
u8 intf = w_index & 0xFF;
u16 w_value = le16_to_cpu(ctrl->wValue);
u16 w_length = le16_to_cpu(ctrl->wLength);
struct usb_function *f = NULL;
u8 endp;
req->zero = 0;
req->complete = composite_setup_complete;
req->length = 0;
gadget->ep0->driver_data = cdev;
switch (ctrl->bRequest) {
case USB_REQ_GET_DESCRIPTOR:
if (ctrl->bRequestType != USB_DIR_IN)
goto unknown;
switch (w_value >> 8) {
case USB_DT_DEVICE:
cdev->desc.bNumConfigurations =
count_configs(cdev, USB_DT_DEVICE);
value = min(w_length, (u16) sizeof cdev->desc);
memcpy(req->buf, &cdev->desc, value);
break;
case USB_DT_DEVICE_QUALIFIER:
if (!gadget_is_dualspeed(gadget))
break;
device_qual(cdev);
value = min_t(int, w_length,
sizeof(struct usb_qualifier_descriptor));
break;
case USB_DT_OTHER_SPEED_CONFIG:
if (!gadget_is_dualspeed(gadget))
break;
case USB_DT_CONFIG:
value = config_desc(cdev, w_value);
if (value >= 0)
value = min(w_length, (u16) value);
break;
case USB_DT_STRING:
value = get_string(cdev, req->buf,
w_index, w_value & 0xff);
if (value >= 0)
value = min(w_length, (u16) value);
break;
}
break;
case USB_REQ_SET_CONFIGURATION:
if (ctrl->bRequestType != 0)
goto unknown;
if (gadget_is_otg(gadget)) {
if (gadget->a_hnp_support)
DBG(cdev, "HNP available\n");
else if (gadget->a_alt_hnp_support)
DBG(cdev, "HNP on another port\n");
else
VDBG(cdev, "HNP inactive\n");
}
spin_lock(&cdev->lock);
value = set_config(cdev, ctrl, w_value);
spin_unlock(&cdev->lock);
break;
case USB_REQ_GET_CONFIGURATION:
if (ctrl->bRequestType != USB_DIR_IN)
goto unknown;
if (cdev->config)
*(u8 *)req->buf = cdev->config->bConfigurationValue;
else
*(u8 *)req->buf = 0;
value = min(w_length, (u16) 1);
break;
case USB_REQ_SET_INTERFACE:
if (ctrl->bRequestType != USB_RECIP_INTERFACE)
goto unknown;
if (!cdev->config || intf >= MAX_CONFIG_INTERFACES)
break;
f = cdev->config->interface[intf];
if (!f)
break;
if (w_value && !f->set_alt)
break;
value = f->set_alt(f, w_index, w_value);
if (value == USB_GADGET_DELAYED_STATUS) {
DBG(cdev,
"%s: interface %d (%s) requested delayed status\n",
__func__, intf, f->name);
cdev->delayed_status++;
DBG(cdev, "delayed_status count %d\n",
cdev->delayed_status);
}
break;
case USB_REQ_GET_INTERFACE:
if (ctrl->bRequestType != (USB_DIR_IN|USB_RECIP_INTERFACE))
goto unknown;
if (!cdev->config || intf >= MAX_CONFIG_INTERFACES)
break;
f = cdev->config->interface[intf];
if (!f)
break;
value = f->get_alt ? f->get_alt(f, w_index) : 0;
if (value < 0)
break;
*((u8 *)req->buf) = value;
value = min(w_length, (u16) 1);
break;
default:
unknown:
VDBG(cdev,
"non-core control req%02x.%02x v%04x i%04x l%d\n",
ctrl->bRequestType, ctrl->bRequest,
w_value, w_index, w_length);
switch (ctrl->bRequestType & USB_RECIP_MASK) {
case USB_RECIP_INTERFACE:
if (!cdev->config || intf >= MAX_CONFIG_INTERFACES)
break;
f = cdev->config->interface[intf];
break;
case USB_RECIP_ENDPOINT:
endp = ((w_index & 0x80) >> 3) | (w_index & 0x0f);
list_for_each_entry(f, &cdev->config->functions, list) {
if (test_bit(endp, f->endpoints))
break;
}
if (&f->list == &cdev->config->functions)
f = NULL;
break;
}
if (f && f->setup)
value = f->setup(f, ctrl);
else {
struct usb_configuration *c;
c = cdev->config;
if (c && c->setup)
value = c->setup(c, ctrl);
}
goto done;
}
if (value >= 0 && value != USB_GADGET_DELAYED_STATUS) {
req->length = value;
req->zero = value < w_length;
value = usb_ep_queue(gadget->ep0, req, GFP_ATOMIC);
if (value < 0) {
DBG(cdev, "ep_queue --> %d\n", value);
req->status = 0;
composite_setup_complete(gadget->ep0, req);
}
} else if (value == USB_GADGET_DELAYED_STATUS && w_length != 0) {
WARN(cdev,
"%s: Delayed status not supported for w_length != 0",
__func__);
}
done:
return value;
}
static void composite_disconnect(struct usb_gadget *gadget)
{
struct usb_composite_dev *cdev = get_gadget_data(gadget);
unsigned long flags;
spin_lock_irqsave(&cdev->lock, flags);
if (cdev->config)
reset_config(cdev);
if (composite->disconnect)
composite->disconnect(cdev);
spin_unlock_irqrestore(&cdev->lock, flags);
}
static ssize_t composite_show_suspended(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct usb_gadget *gadget = dev_to_usb_gadget(dev);
struct usb_composite_dev *cdev = get_gadget_data(gadget);
return sprintf(buf, "%d\n", cdev->suspended);
}
static void
composite_unbind(struct usb_gadget *gadget)
{
struct usb_composite_dev *cdev = get_gadget_data(gadget);
WARN_ON(cdev->config);
while (!list_empty(&cdev->configs)) {
struct usb_configuration *c;
c = list_first_entry(&cdev->configs,
struct usb_configuration, list);
while (!list_empty(&c->functions)) {
struct usb_function *f;
f = list_first_entry(&c->functions,
struct usb_function, list);
list_del(&f->list);
if (f->unbind) {
DBG(cdev, "unbind function '%s'/%p\n",
f->name, f);
f->unbind(c, f);
}
}
list_del(&c->list);
if (c->unbind) {
DBG(cdev, "unbind config '%s'/%p\n", c->label, c);
c->unbind(c);
}
}
if (composite->unbind)
composite->unbind(cdev);
if (cdev->req) {
kfree(cdev->req->buf);
usb_ep_free_request(gadget->ep0, cdev->req);
}
device_remove_file(&gadget->dev, &dev_attr_suspended);
kfree(cdev);
set_gadget_data(gadget, NULL);
composite = NULL;
}
static u8 override_id(struct usb_composite_dev *cdev, u8 *desc)
{
if (!*desc) {
int ret = usb_string_id(cdev);
if (unlikely(ret < 0))
WARNING(cdev, "failed to override string ID\n");
else
*desc = ret;
}
return *desc;
}
static int composite_bind(struct usb_gadget *gadget)
{
struct usb_composite_dev *cdev;
int status = -ENOMEM;
cdev = kzalloc(sizeof *cdev, GFP_KERNEL);
if (!cdev)
return status;
spin_lock_init(&cdev->lock);
cdev->gadget = gadget;
set_gadget_data(gadget, cdev);
INIT_LIST_HEAD(&cdev->configs);
cdev->req = usb_ep_alloc_request(gadget->ep0, GFP_KERNEL);
if (!cdev->req)
goto fail;
cdev->req->buf = kmalloc(USB_BUFSIZ, GFP_KERNEL);
if (!cdev->req->buf)
goto fail;
cdev->req->complete = composite_setup_complete;
gadget->ep0->driver_data = cdev;
cdev->bufsiz = USB_BUFSIZ;
cdev->driver = composite;
if (CONFIG_USB_GADGET_VBUS_DRAW <= USB_SELF_POWER_VBUS_MAX_DRAW)
usb_gadget_set_selfpowered(gadget);
usb_ep_autoconfig_reset(cdev->gadget);
status = composite_gadget_bind(cdev);
if (status < 0)
goto fail;
cdev->desc = *composite->dev;
cdev->desc.bMaxPacketSize0 = gadget->ep0->maxpacket;
if (idVendor)
cdev->desc.idVendor = cpu_to_le16(idVendor);
if (idProduct)
cdev->desc.idProduct = cpu_to_le16(idProduct);
if (bcdDevice)
cdev->desc.bcdDevice = cpu_to_le16(bcdDevice);
if (iManufacturer || !cdev->desc.iManufacturer) {
if (!iManufacturer && !composite->iManufacturer &&
!*composite_manufacturer)
snprintf(composite_manufacturer,
sizeof composite_manufacturer,
"%s %s with %s",
init_utsname()->sysname,
init_utsname()->release,
gadget->name);
cdev->manufacturer_override =
override_id(cdev, &cdev->desc.iManufacturer);
}
if (iProduct || (!cdev->desc.iProduct && composite->iProduct))
cdev->product_override =
override_id(cdev, &cdev->desc.iProduct);
if (iSerialNumber)
cdev->serial_override =
override_id(cdev, &cdev->desc.iSerialNumber);
if (composite->needs_serial && !cdev->desc.iSerialNumber)
WARNING(cdev, "userspace failed to provide iSerialNumber\n");
status = device_create_file(&gadget->dev, &dev_attr_suspended);
if (status)
goto fail;
INFO(cdev, "%s ready\n", composite->name);
return 0;
fail:
composite_unbind(gadget);
return status;
}
static void
composite_suspend(struct usb_gadget *gadget)
{
struct usb_composite_dev *cdev = get_gadget_data(gadget);
struct usb_function *f;
DBG(cdev, "suspend\n");
if (cdev->config) {
list_for_each_entry(f, &cdev->config->functions, list) {
if (f->suspend)
f->suspend(f);
}
}
if (composite->suspend)
composite->suspend(cdev);
cdev->suspended = 1;
usb_gadget_vbus_draw(gadget, 2);
}
static void
composite_resume(struct usb_gadget *gadget)
{
struct usb_composite_dev *cdev = get_gadget_data(gadget);
struct usb_function *f;
u8 maxpower;
DBG(cdev, "resume\n");
if (composite->resume)
composite->resume(cdev);
if (cdev->config) {
list_for_each_entry(f, &cdev->config->functions, list) {
if (f->resume)
f->resume(f);
}
maxpower = cdev->config->bMaxPower;
usb_gadget_vbus_draw(gadget, maxpower ?
(2 * maxpower) : CONFIG_USB_GADGET_VBUS_DRAW);
}
cdev->suspended = 0;
}
int usb_composite_probe(struct usb_composite_driver *driver,
int (*bind)(struct usb_composite_dev *cdev))
{
if (!driver || !driver->dev || !bind || composite)
return -EINVAL;
if (!driver->name)
driver->name = "composite";
if (!driver->iProduct)
driver->iProduct = driver->name;
composite_driver.function = (char *) driver->name;
composite_driver.driver.name = driver->name;
composite = driver;
composite_gadget_bind = bind;
return usb_gadget_probe_driver(&composite_driver, composite_bind);
}
void usb_composite_unregister(struct usb_composite_driver *driver)
{
if (composite != driver)
return;
usb_gadget_unregister_driver(&composite_driver);
}
void usb_composite_setup_continue(struct usb_composite_dev *cdev)
{
int value;
struct usb_request *req = cdev->req;
unsigned long flags;
DBG(cdev, "%s\n", __func__);
spin_lock_irqsave(&cdev->lock, flags);
if (cdev->delayed_status == 0) {
WARN(cdev, "%s: Unexpected call\n", __func__);
} else if (--cdev->delayed_status == 0) {
DBG(cdev, "%s: Completing delayed status\n", __func__);
req->length = 0;
value = usb_ep_queue(cdev->gadget->ep0, req, GFP_ATOMIC);
if (value < 0) {
DBG(cdev, "ep_queue --> %d\n", value);
req->status = 0;
composite_setup_complete(cdev->gadget->ep0, req);
}
}
spin_unlock_irqrestore(&cdev->lock, flags);
}
