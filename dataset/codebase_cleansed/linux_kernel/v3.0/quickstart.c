static ssize_t buttons_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int count = 0;
struct quickstart_btn *ptr = quickstart_data.btn_lst;
if (!ptr)
return snprintf(buf, PAGE_SIZE, "none");
while (ptr && (count < PAGE_SIZE)) {
if (ptr->name) {
count += snprintf(buf + count,
PAGE_SIZE - count,
"%d\t%s\n", ptr->id, ptr->name);
}
ptr = ptr->next;
}
return count;
}
static ssize_t pressed_button_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s\n",
(quickstart_data.pressed ?
quickstart_data.pressed->name : "none"));
}
static ssize_t pressed_button_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
if (count < 2)
return -EINVAL;
if (strncasecmp(buf, "none", 4) != 0)
return -EINVAL;
quickstart_data.pressed = NULL;
return count;
}
static int quickstart_btnlst_add(struct quickstart_btn **data)
{
struct quickstart_btn **ptr = &quickstart_data.btn_lst;
while (*ptr)
ptr = &((*ptr)->next);
*ptr = kzalloc(sizeof(struct quickstart_btn), GFP_KERNEL);
if (!*ptr) {
*data = NULL;
return -ENOMEM;
}
*data = *ptr;
return 0;
}
static void quickstart_btnlst_del(struct quickstart_btn *data)
{
struct quickstart_btn **ptr = &quickstart_data.btn_lst;
if (!data)
return;
while (*ptr) {
if (*ptr == data) {
*ptr = (*ptr)->next;
kfree(data);
return;
}
ptr = &((*ptr)->next);
}
return;
}
static void quickstart_btnlst_free(void)
{
struct quickstart_btn *ptr = quickstart_data.btn_lst;
struct quickstart_btn *lptr = NULL;
while (ptr) {
lptr = ptr;
ptr = ptr->next;
kfree(lptr->name);
kfree(lptr);
}
return;
}
static void quickstart_acpi_notify(acpi_handle handle, u32 event, void *data)
{
struct quickstart_acpi *quickstart = data;
if (!quickstart)
return;
if (event == QUICKSTART_EVENT_WAKE)
quickstart_data.pressed = quickstart->btn;
else if (event == QUICKSTART_EVENT_RUNTIME) {
input_report_key(quickstart_input, quickstart->btn->id, 1);
input_sync(quickstart_input);
input_report_key(quickstart_input, quickstart->btn->id, 0);
input_sync(quickstart_input);
}
return;
}
static void quickstart_acpi_ghid(struct quickstart_acpi *quickstart)
{
acpi_status status;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
uint32_t usageid = 0;
if (!quickstart)
return;
status = acpi_evaluate_object(quickstart->device->handle,
"GHID", NULL, &buffer);
if (ACPI_FAILURE(status) || !buffer.pointer) {
printk(KERN_ERR "quickstart: %s GHID method failed.\n",
quickstart->btn->name);
return;
}
if (buffer.length < 8)
return;
usageid = *((uint32_t *)(buffer.pointer + (buffer.length - 8)));
quickstart->btn->id = usageid;
kfree(buffer.pointer);
}
static int quickstart_acpi_config(struct quickstart_acpi *quickstart, char *bid)
{
int len = strlen(bid);
int ret;
ret = quickstart_btnlst_add(&quickstart->btn);
if (ret)
return ret;
quickstart->btn->name = kzalloc(len + 1, GFP_KERNEL);
if (!quickstart->btn->name) {
quickstart_btnlst_free();
return -ENOMEM;
}
strcpy(quickstart->btn->name, bid);
return 0;
}
static int quickstart_acpi_add(struct acpi_device *device)
{
int ret = 0;
acpi_status status = AE_OK;
struct quickstart_acpi *quickstart = NULL;
if (!device)
return -EINVAL;
quickstart = kzalloc(sizeof(struct quickstart_acpi), GFP_KERNEL);
if (!quickstart)
return -ENOMEM;
quickstart->device = device;
strcpy(acpi_device_name(device), QUICKSTART_ACPI_DEVICE_NAME);
strcpy(acpi_device_class(device), QUICKSTART_ACPI_CLASS);
device->driver_data = quickstart;
ret = quickstart_acpi_config(quickstart, acpi_device_bid(device));
if (ret)
goto fail_config;
status = acpi_install_notify_handler(device->handle,
ACPI_ALL_NOTIFY,
quickstart_acpi_notify,
quickstart);
if (ACPI_FAILURE(status)) {
printk(KERN_ERR "quickstart: Notify handler install error\n");
ret = -ENODEV;
goto fail_installnotify;
}
quickstart_acpi_ghid(quickstart);
return 0;
fail_installnotify:
quickstart_btnlst_del(quickstart->btn);
fail_config:
kfree(quickstart);
return ret;
}
static int quickstart_acpi_remove(struct acpi_device *device, int type)
{
acpi_status status = 0;
struct quickstart_acpi *quickstart = NULL;
if (!device || !acpi_driver_data(device))
return -EINVAL;
quickstart = acpi_driver_data(device);
status = acpi_remove_notify_handler(device->handle,
ACPI_ALL_NOTIFY,
quickstart_acpi_notify);
if (ACPI_FAILURE(status))
printk(KERN_ERR "quickstart: Error removing notify handler\n");
kfree(quickstart);
return 0;
}
static void quickstart_exit(void)
{
input_unregister_device(quickstart_input);
device_remove_file(&pf_device->dev, &dev_attr_pressed_button);
device_remove_file(&pf_device->dev, &dev_attr_buttons);
platform_device_unregister(pf_device);
platform_driver_unregister(&pf_driver);
acpi_bus_unregister_driver(&quickstart_acpi_driver);
quickstart_btnlst_free();
return;
}
static int __init quickstart_init_input(void)
{
struct quickstart_btn **ptr = &quickstart_data.btn_lst;
int count;
int ret;
quickstart_input = input_allocate_device();
if (!quickstart_input)
return -ENOMEM;
quickstart_input->name = "Quickstart ACPI Buttons";
quickstart_input->id.bustype = BUS_HOST;
while (*ptr) {
count++;
set_bit(EV_KEY, quickstart_input->evbit);
set_bit((*ptr)->id, quickstart_input->keybit);
ptr = &((*ptr)->next);
}
ret = input_register_device(quickstart_input);
if (ret) {
input_free_device(quickstart_input);
return ret;
}
return 0;
}
static int __init quickstart_init(void)
{
int ret;
if (acpi_disabled)
return -ENODEV;
ret = acpi_bus_register_driver(&quickstart_acpi_driver);
if (ret)
return ret;
if (!quickstart_data.btn_lst) {
ret = -ENODEV;
goto fail_pfdrv_reg;
}
ret = platform_driver_register(&pf_driver);
if (ret)
goto fail_pfdrv_reg;
pf_device = platform_device_alloc(QUICKSTART_PF_DEVICE_NAME, -1);
if (!pf_device) {
ret = -ENOMEM;
goto fail_pfdev_alloc;
}
ret = platform_device_add(pf_device);
if (ret)
goto fail_pfdev_add;
ret = device_create_file(&pf_device->dev, &dev_attr_pressed_button);
if (ret)
goto fail_dev_file;
ret = device_create_file(&pf_device->dev, &dev_attr_buttons);
if (ret)
goto fail_dev_file2;
ret = quickstart_init_input();
if (ret)
goto fail_input;
printk(KERN_INFO "quickstart: ACPI Direct App Launch ver %s\n",
QUICKSTART_VERSION);
return 0;
fail_input:
device_remove_file(&pf_device->dev, &dev_attr_buttons);
fail_dev_file2:
device_remove_file(&pf_device->dev, &dev_attr_pressed_button);
fail_dev_file:
platform_device_del(pf_device);
fail_pfdev_add:
platform_device_put(pf_device);
fail_pfdev_alloc:
platform_driver_unregister(&pf_driver);
fail_pfdrv_reg:
acpi_bus_unregister_driver(&quickstart_acpi_driver);
return ret;
}
