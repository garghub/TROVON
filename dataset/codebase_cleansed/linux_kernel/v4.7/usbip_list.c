void usbip_list_usage(void)
{
printf("usage: %s", usbip_list_usage_string);
}
static int get_exported_devices(char *host, int sockfd)
{
char product_name[100];
char class_name[100];
struct op_devlist_reply reply;
uint16_t code = OP_REP_DEVLIST;
struct usbip_usb_device udev;
struct usbip_usb_interface uintf;
unsigned int i;
int rc, j;
rc = usbip_net_send_op_common(sockfd, OP_REQ_DEVLIST, 0);
if (rc < 0) {
dbg("usbip_net_send_op_common failed");
return -1;
}
rc = usbip_net_recv_op_common(sockfd, &code);
if (rc < 0) {
dbg("usbip_net_recv_op_common failed");
return -1;
}
memset(&reply, 0, sizeof(reply));
rc = usbip_net_recv(sockfd, &reply, sizeof(reply));
if (rc < 0) {
dbg("usbip_net_recv_op_devlist failed");
return -1;
}
PACK_OP_DEVLIST_REPLY(0, &reply);
dbg("exportable devices: %d\n", reply.ndev);
if (reply.ndev == 0) {
info("no exportable devices found on %s", host);
return 0;
}
printf("Exportable USB devices\n");
printf("======================\n");
printf(" - %s\n", host);
for (i = 0; i < reply.ndev; i++) {
memset(&udev, 0, sizeof(udev));
rc = usbip_net_recv(sockfd, &udev, sizeof(udev));
if (rc < 0) {
dbg("usbip_net_recv failed: usbip_usb_device[%d]", i);
return -1;
}
usbip_net_pack_usb_device(0, &udev);
usbip_names_get_product(product_name, sizeof(product_name),
udev.idVendor, udev.idProduct);
usbip_names_get_class(class_name, sizeof(class_name),
udev.bDeviceClass, udev.bDeviceSubClass,
udev.bDeviceProtocol);
printf("%11s: %s\n", udev.busid, product_name);
printf("%11s: %s\n", "", udev.path);
printf("%11s: %s\n", "", class_name);
for (j = 0; j < udev.bNumInterfaces; j++) {
rc = usbip_net_recv(sockfd, &uintf, sizeof(uintf));
if (rc < 0) {
err("usbip_net_recv failed: usbip_usb_intf[%d]",
j);
return -1;
}
usbip_net_pack_usb_interface(0, &uintf);
usbip_names_get_class(class_name, sizeof(class_name),
uintf.bInterfaceClass,
uintf.bInterfaceSubClass,
uintf.bInterfaceProtocol);
printf("%11s: %2d - %s\n", "", j, class_name);
}
printf("\n");
}
return 0;
}
static int list_exported_devices(char *host)
{
int rc;
int sockfd;
sockfd = usbip_net_tcp_connect(host, usbip_port_string);
if (sockfd < 0) {
err("could not connect to %s:%s: %s", host,
usbip_port_string, gai_strerror(sockfd));
return -1;
}
dbg("connected to %s:%s", host, usbip_port_string);
rc = get_exported_devices(host, sockfd);
if (rc < 0) {
err("failed to get device list from %s", host);
return -1;
}
close(sockfd);
return 0;
}
static void print_device(const char *busid, const char *vendor,
const char *product, bool parsable)
{
if (parsable)
printf("busid=%s#usbid=%.4s:%.4s#", busid, vendor, product);
else
printf(" - busid %s (%.4s:%.4s)\n", busid, vendor, product);
}
static void print_product_name(char *product_name, bool parsable)
{
if (!parsable)
printf(" %s\n", product_name);
}
static int list_devices(bool parsable)
{
struct udev *udev;
struct udev_enumerate *enumerate;
struct udev_list_entry *devices, *dev_list_entry;
struct udev_device *dev;
const char *path;
const char *idVendor;
const char *idProduct;
const char *bConfValue;
const char *bNumIntfs;
const char *busid;
char product_name[128];
int ret = -1;
udev = udev_new();
enumerate = udev_enumerate_new(udev);
udev_enumerate_add_match_subsystem(enumerate, "usb");
udev_enumerate_add_nomatch_sysattr(enumerate, "bDeviceClass", "09");
udev_enumerate_add_nomatch_sysattr(enumerate, "bInterfaceNumber", NULL);
udev_enumerate_scan_devices(enumerate);
devices = udev_enumerate_get_list_entry(enumerate);
udev_list_entry_foreach(dev_list_entry, devices) {
path = udev_list_entry_get_name(dev_list_entry);
dev = udev_device_new_from_syspath(udev, path);
idVendor = udev_device_get_sysattr_value(dev, "idVendor");
idProduct = udev_device_get_sysattr_value(dev, "idProduct");
bConfValue = udev_device_get_sysattr_value(dev,
"bConfigurationValue");
bNumIntfs = udev_device_get_sysattr_value(dev,
"bNumInterfaces");
busid = udev_device_get_sysname(dev);
if (!idVendor || !idProduct || !bConfValue || !bNumIntfs) {
err("problem getting device attributes: %s",
strerror(errno));
goto err_out;
}
usbip_names_get_product(product_name, sizeof(product_name),
strtol(idVendor, NULL, 16),
strtol(idProduct, NULL, 16));
print_device(busid, idVendor, idProduct, parsable);
print_product_name(product_name, parsable);
printf("\n");
udev_device_unref(dev);
}
ret = 0;
err_out:
udev_enumerate_unref(enumerate);
udev_unref(udev);
return ret;
}
static int list_gadget_devices(bool parsable)
{
int ret = -1;
struct udev *udev;
struct udev_enumerate *enumerate;
struct udev_list_entry *devices, *dev_list_entry;
struct udev_device *dev;
const char *path;
const char *driver;
const struct usb_device_descriptor *d_desc;
const char *descriptors;
char product_name[128];
uint16_t idVendor;
char idVendor_buf[8];
uint16_t idProduct;
char idProduct_buf[8];
const char *busid;
udev = udev_new();
enumerate = udev_enumerate_new(udev);
udev_enumerate_add_match_subsystem(enumerate, "platform");
udev_enumerate_scan_devices(enumerate);
devices = udev_enumerate_get_list_entry(enumerate);
udev_list_entry_foreach(dev_list_entry, devices) {
path = udev_list_entry_get_name(dev_list_entry);
dev = udev_device_new_from_syspath(udev, path);
driver = udev_device_get_driver(dev);
if (driver == NULL || strcmp(driver, USBIP_DEVICE_DRV_NAME))
continue;
descriptors = udev_device_get_sysattr_value(dev,
VUDC_DEVICE_DESCR_FILE);
if (!descriptors) {
err("problem getting device attributes: %s",
strerror(errno));
goto err_out;
}
d_desc = (const struct usb_device_descriptor *) descriptors;
idVendor = le16toh(d_desc->idVendor);
sprintf(idVendor_buf, "0x%4x", idVendor);
idProduct = le16toh(d_desc->idProduct);
sprintf(idProduct_buf, "0x%4x", idVendor);
busid = udev_device_get_sysname(dev);
usbip_names_get_product(product_name, sizeof(product_name),
le16toh(idVendor),
le16toh(idProduct));
print_device(busid, idVendor_buf, idProduct_buf, parsable);
print_product_name(product_name, parsable);
printf("\n");
udev_device_unref(dev);
}
ret = 0;
err_out:
udev_enumerate_unref(enumerate);
udev_unref(udev);
return ret;
}
int usbip_list(int argc, char *argv[])
{
static const struct option opts[] = {
{ "parsable", no_argument, NULL, 'p' },
{ "remote", required_argument, NULL, 'r' },
{ "local", no_argument, NULL, 'l' },
{ "device", no_argument, NULL, 'd' },
{ NULL, 0, NULL, 0 }
};
bool parsable = false;
int opt;
int ret = -1;
if (usbip_names_init(USBIDS_FILE))
err("failed to open %s", USBIDS_FILE);
for (;;) {
opt = getopt_long(argc, argv, "pr:ld", opts, NULL);
if (opt == -1)
break;
switch (opt) {
case 'p':
parsable = true;
break;
case 'r':
ret = list_exported_devices(optarg);
goto out;
case 'l':
ret = list_devices(parsable);
goto out;
case 'd':
ret = list_gadget_devices(parsable);
goto out;
default:
goto err_out;
}
}
err_out:
usbip_list_usage();
out:
usbip_names_free();
return ret;
}
