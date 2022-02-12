int
uisutil_add_proc_line_ex(int *total, char **buffer, int *buffer_remaining,
char *format, ...)
{
va_list args;
int len;
va_start(args, format);
len = vsnprintf(*buffer, *buffer_remaining, format, args);
va_end(args);
if (len >= *buffer_remaining) {
*buffer += *buffer_remaining;
*total += *buffer_remaining;
*buffer_remaining = 0;
return -1;
}
*buffer_remaining -= len;
*buffer += len;
*total += len;
return len;
}
int
uisctrl_register_req_handler(int type, void *fptr,
struct ultra_vbus_deviceinfo *chipset_driver_info)
{
switch (type) {
case 2:
if (fptr) {
if (!virt_control_chan_func)
atomic_inc(&uisutils_registered_services);
virt_control_chan_func = fptr;
} else {
if (virt_control_chan_func)
atomic_dec(&uisutils_registered_services);
virt_control_chan_func = NULL;
}
break;
default:
return 0;
}
if (chipset_driver_info)
bus_device_info_init(chipset_driver_info, "chipset", "uislib",
VERSION, NULL);
return 1;
}
struct req_handler_info *
req_handler_find(uuid_le switch_uuid)
{
struct list_head *lelt, *tmp;
struct req_handler_info *entry = NULL;
spin_lock(&req_handler_info_list_lock);
list_for_each_safe(lelt, tmp, &req_handler_info_list) {
entry = list_entry(lelt, struct req_handler_info, list_link);
if (uuid_le_cmp(entry->switch_uuid, switch_uuid) == 0) {
spin_unlock(&req_handler_info_list_lock);
return entry;
}
}
spin_unlock(&req_handler_info_list_lock);
return NULL;
}
