static void show_help(void)
{
printf("Usage: usbip_bind_driver [OPTION]\n");
printf("Change driver binding for USB/IP.\n");
printf(" --usbip busid make a device exportable\n");
printf(" --other busid use a device by a local driver\n");
printf(" --list print usb devices and their drivers\n");
printf(" --list2 print usb devices and their drivers in parseable mode\n");
#if 0
printf(" --allusbip make all devices exportable\n");
printf(" --export-to host export the device to 'host'\n");
printf(" --unexport host unexport a device previously exported to 'host'\n");
printf(" --busid busid the busid used for --export-to\n");
#endif
}
static int modify_match_busid(char *busid, int add)
{
int fd;
int ret;
char buff[BUS_ID_SIZE + 4];
if (strnlen(busid, BUS_ID_SIZE) > BUS_ID_SIZE - 1) {
g_warning("too long busid");
return -1;
}
fd = open(match_busid_path, O_WRONLY);
if (fd < 0)
return -1;
if (add)
snprintf(buff, BUS_ID_SIZE + 4, "add %s", busid);
else
snprintf(buff, BUS_ID_SIZE + 4, "del %s", busid);
g_debug("write \"%s\" to %s", buff, match_busid_path);
ret = write(fd, buff, sizeof(buff));
if (ret < 0) {
close(fd);
return -1;
}
close(fd);
return 0;
}
static int unbind_interface_busid(char *busid)
{
char unbind_path[PATH_MAX];
int fd;
int ret;
snprintf(unbind_path, sizeof(unbind_path), unbind_path_format, busid);
fd = open(unbind_path, O_WRONLY);
if (fd < 0) {
g_warning("opening unbind_path failed: %d", fd);
return -1;
}
ret = write(fd, busid, strnlen(busid, BUS_ID_SIZE));
if (ret < 0) {
g_warning("write to unbind_path failed: %d", ret);
close(fd);
return -1;
}
close(fd);
return 0;
}
static int unbind_interface(char *busid, int configvalue, int interface)
{
char inf_busid[BUS_ID_SIZE];
g_debug("unbinding interface");
snprintf(inf_busid, BUS_ID_SIZE, "%s:%d.%d", busid, configvalue, interface);
return unbind_interface_busid(inf_busid);
}
static int bind_interface_busid(char *busid, char *driver)
{
char bind_path[PATH_MAX];
int fd;
int ret;
snprintf(bind_path, sizeof(bind_path), bind_path_format, driver);
fd = open(bind_path, O_WRONLY);
if (fd < 0)
return -1;
ret = write(fd, busid, strnlen(busid, BUS_ID_SIZE));
if (ret < 0) {
close(fd);
return -1;
}
close(fd);
return 0;
}
static int bind_interface(char *busid, int configvalue, int interface, char *driver)
{
char inf_busid[BUS_ID_SIZE];
snprintf(inf_busid, BUS_ID_SIZE, "%s:%d.%d", busid, configvalue, interface);
return bind_interface_busid(inf_busid, driver);
}
static int unbind(char *busid)
{
int configvalue = 0;
int ninterface = 0;
int devclass = 0;
int i;
int failed = 0;
configvalue = read_bConfigurationValue(busid);
ninterface = read_bNumInterfaces(busid);
devclass = read_bDeviceClass(busid);
if (configvalue < 0 || ninterface < 0 || devclass < 0) {
g_warning("read config and ninf value, removed?");
return -1;
}
if (devclass == 0x09) {
g_message("skip unbinding of hub");
return -1;
}
for (i = 0; i < ninterface; i++) {
char driver[PATH_MAX];
int ret;
bzero(&driver, sizeof(driver));
getdriver(busid, configvalue, i, driver, PATH_MAX-1);
g_debug(" %s:%d.%d -> %s ", busid, configvalue, i, driver);
if (!strncmp("none", driver, PATH_MAX))
continue;
#if 0
if (!strncmp("usbip", driver, PATH_MAX))
continue;
#endif
ret = unbind_interface(busid, configvalue, i);
if (ret < 0) {
g_warning("unbind driver at %s:%d.%d failed",
busid, configvalue, i);
failed = 1;
}
}
if (failed)
return -1;
else
return 0;
}
static int bind_to_usbip(char *busid)
{
int configvalue = 0;
int ninterface = 0;
int i;
int failed = 0;
configvalue = read_bConfigurationValue(busid);
ninterface = read_bNumInterfaces(busid);
if (configvalue < 0 || ninterface < 0) {
g_warning("read config and ninf value, removed?");
return -1;
}
for (i = 0; i < ninterface; i++) {
int ret;
ret = bind_interface(busid, configvalue, i, "usbip");
if (ret < 0) {
g_warning("bind usbip at %s:%d.%d, failed",
busid, configvalue, i);
failed = 1;
}
}
if (failed)
return -1;
else
return 0;
}
static int use_device_by_usbip(char *busid)
{
int ret;
ret = unbind(busid);
if (ret < 0) {
g_warning("unbind drivers of %s, failed", busid);
return -1;
}
ret = modify_match_busid(busid, 1);
if (ret < 0) {
g_warning("add %s to match_busid, failed", busid);
return -1;
}
ret = bind_to_usbip(busid);
if (ret < 0) {
g_warning("bind usbip to %s, failed", busid);
modify_match_busid(busid, 0);
return -1;
}
g_message("bind %s to usbip, complete!", busid);
return 0;
}
static int use_device_by_other(char *busid)
{
int ret;
int config;
config = read_bConfigurationValue(busid);
if (config < 0) {
g_warning("read bConfigurationValue of %s, failed", busid);
return -1;
}
ret = modify_match_busid(busid, 0);
if (ret < 0) {
g_warning("del %s to match_busid, failed", busid);
return -1;
}
ret = write_bConfigurationValue(busid, config);
if (ret < 0) {
g_warning("read bConfigurationValue of %s, failed", busid);
return -1;
}
g_message("bind %s to other drivers than usbip, complete!", busid);
return 0;
}
static int is_usb_device(char *busid)
{
int ret;
regex_t regex;
regmatch_t pmatch[1];
ret = regcomp(&regex, "^[0-9]+-[0-9]+(\\.[0-9]+)*$", REG_NOSUB|REG_EXTENDED);
if (ret < 0)
g_error("regcomp: %s\n", strerror(errno));
ret = regexec(&regex, busid, 0, pmatch, 0);
if (ret)
return 0;
return 1;
}
static int show_devices(void)
{
DIR *dir;
dir = opendir("/sys/bus/usb/devices/");
if (!dir)
g_error("opendir: %s", strerror(errno));
printf("List USB devices\n");
for (;;) {
struct dirent *dirent;
char *busid;
dirent = readdir(dir);
if (!dirent)
break;
busid = dirent->d_name;
if (is_usb_device(busid)) {
char name[100] = {'\0'};
char driver[100] = {'\0'};
int conf, ninf = 0;
int i;
conf = read_bConfigurationValue(busid);
ninf = read_bNumInterfaces(busid);
getdevicename(busid, name, sizeof(name));
printf(" - busid %s (%s)\n", busid, name);
for (i = 0; i < ninf; i++) {
getdriver(busid, conf, i, driver, sizeof(driver));
printf(" %s:%d.%d -> %s\n", busid, conf, i, driver);
}
printf("\n");
}
}
closedir(dir);
return 0;
}
static int show_devices2(void)
{
DIR *dir;
dir = opendir("/sys/bus/usb/devices/");
if (!dir)
g_error("opendir: %s", strerror(errno));
for (;;) {
struct dirent *dirent;
char *busid;
dirent = readdir(dir);
if (!dirent)
break;
busid = dirent->d_name;
if (is_usb_device(busid)) {
char name[100] = {'\0'};
char driver[100] = {'\0'};
int conf, ninf = 0;
int i;
conf = read_bConfigurationValue(busid);
ninf = read_bNumInterfaces(busid);
getdevicename(busid, name, sizeof(name));
printf("busid=%s#usbid=%s#", busid, name);
for (i = 0; i < ninf; i++) {
getdriver(busid, conf, i, driver, sizeof(driver));
printf("%s:%d.%d=%s#", busid, conf, i, driver);
}
printf("\n");
}
}
closedir(dir);
return 0;
}
int main(int argc, char **argv)
{
char *busid = NULL;
char *remote_host __attribute__((unused)) = NULL;
enum {
cmd_unknown = 0,
cmd_use_by_usbip,
cmd_use_by_other,
cmd_list,
cmd_list2,
cmd_allusbip,
cmd_export_to,
cmd_unexport,
cmd_help,
} cmd = cmd_unknown;
if (geteuid() != 0)
g_warning("running non-root?");
for (;;) {
int c;
int index = 0;
c = getopt_long(argc, argv, "u:o:hlLae:x:b:", longopts, &index);
if (c == -1)
break;
switch (c) {
case 'u':
cmd = cmd_use_by_usbip;
busid = optarg;
break;
case 'o' :
cmd = cmd_use_by_other;
busid = optarg;
break;
case 'l' :
cmd = cmd_list;
break;
case 'L' :
cmd = cmd_list2;
break;
case 'a' :
cmd = cmd_allusbip;
break;
case 'b':
busid = optarg;
break;
case 'e':
cmd = cmd_export_to;
remote_host = optarg;
break;
case 'x':
cmd = cmd_unexport;
remote_host = optarg;
break;
case 'h':
case '?':
cmd = cmd_help;
break;
default:
g_error("getopt");
}
}
switch (cmd) {
case cmd_use_by_usbip:
use_device_by_usbip(busid);
break;
case cmd_use_by_other:
use_device_by_other(busid);
break;
case cmd_list:
show_devices();
break;
case cmd_list2:
show_devices2();
break;
#if 0
case cmd_allusbip:
allusbip();
break;
case cmd_export_to:
export_to(remote_host, busid);
break;
case cmd_unexport:
unexport_from(remote_host, busid);
break;
#endif
case cmd_help:
case cmd_unknown:
show_help();
break;
default:
g_error("NOT REACHED");
}
return 0;
}
