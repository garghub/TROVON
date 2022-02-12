void usbip_detach_usage(void)
{
printf("usage: %s", usbip_detach_usage_string);
}
static int detach_port(char *port)
{
int ret;
uint8_t portnum;
char path[PATH_MAX+1];
for (unsigned int i = 0; i < strlen(port); i++)
if (!isdigit(port[i])) {
err("invalid port %s", port);
return -1;
}
portnum = atoi(port);
snprintf(path, PATH_MAX, VHCI_STATE_PATH"/port%d", portnum);
remove(path);
rmdir(VHCI_STATE_PATH);
ret = usbip_vhci_driver_open();
if (ret < 0) {
err("open vhci_driver");
return -1;
}
ret = usbip_vhci_detach_device(portnum);
if (ret < 0)
return -1;
usbip_vhci_driver_close();
return ret;
}
int usbip_detach(int argc, char *argv[])
{
static const struct option opts[] = {
{ "port", required_argument, NULL, 'p' },
{ NULL, 0, NULL, 0 }
};
int opt;
int ret = -1;
for (;;) {
opt = getopt_long(argc, argv, "p:", opts, NULL);
if (opt == -1)
break;
switch (opt) {
case 'p':
ret = detach_port(optarg);
goto out;
default:
goto err_out;
}
}
err_out:
usbip_detach_usage();
out:
return ret;
}
