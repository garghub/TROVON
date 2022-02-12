static bool event_is_known(struct iio_event_data *event)
{
enum iio_chan_type type = IIO_EVENT_CODE_EXTRACT_CHAN_TYPE(event->id);
enum iio_modifier mod = IIO_EVENT_CODE_EXTRACT_MODIFIER(event->id);
enum iio_event_type ev_type = IIO_EVENT_CODE_EXTRACT_TYPE(event->id);
enum iio_event_direction dir = IIO_EVENT_CODE_EXTRACT_DIR(event->id);
switch (type) {
case IIO_VOLTAGE:
case IIO_CURRENT:
case IIO_POWER:
case IIO_ACCEL:
case IIO_ANGL_VEL:
case IIO_MAGN:
case IIO_LIGHT:
case IIO_INTENSITY:
case IIO_PROXIMITY:
case IIO_TEMP:
case IIO_INCLI:
case IIO_ROT:
case IIO_ANGL:
case IIO_TIMESTAMP:
case IIO_CAPACITANCE:
break;
default:
return false;
}
switch (mod) {
case IIO_NO_MOD:
case IIO_MOD_X:
case IIO_MOD_Y:
case IIO_MOD_Z:
case IIO_MOD_LIGHT_BOTH:
case IIO_MOD_LIGHT_IR:
break;
default:
return false;
}
switch (ev_type) {
case IIO_EV_TYPE_THRESH:
case IIO_EV_TYPE_MAG:
case IIO_EV_TYPE_ROC:
case IIO_EV_TYPE_THRESH_ADAPTIVE:
case IIO_EV_TYPE_MAG_ADAPTIVE:
break;
default:
return false;
}
switch (dir) {
case IIO_EV_DIR_EITHER:
case IIO_EV_DIR_RISING:
case IIO_EV_DIR_FALLING:
break;
default:
return false;
}
return true;
}
static void print_event(struct iio_event_data *event)
{
enum iio_chan_type type = IIO_EVENT_CODE_EXTRACT_CHAN_TYPE(event->id);
enum iio_modifier mod = IIO_EVENT_CODE_EXTRACT_MODIFIER(event->id);
enum iio_event_type ev_type = IIO_EVENT_CODE_EXTRACT_TYPE(event->id);
enum iio_event_direction dir = IIO_EVENT_CODE_EXTRACT_DIR(event->id);
int chan = IIO_EVENT_CODE_EXTRACT_CHAN(event->id);
int chan2 = IIO_EVENT_CODE_EXTRACT_CHAN2(event->id);
bool diff = IIO_EVENT_CODE_EXTRACT_DIFF(event->id);
if (!event_is_known(event)) {
printf("Unknown event: time: %lld, id: %llx\n",
event->timestamp, event->id);
return;
}
printf("Event: time: %lld, ", event->timestamp);
if (mod != IIO_NO_MOD) {
printf("type: %s(%s), ",
iio_chan_type_name_spec[type],
iio_modifier_names[mod]);
} else {
printf("type: %s, ",
iio_chan_type_name_spec[type]);
}
if (diff && chan >= 0 && chan2 >= 0)
printf("channel: %d-%d, ", chan, chan2);
else if (chan >= 0)
printf("channel: %d, ", chan);
printf("evtype: %s, direction: %s\n",
iio_ev_type_text[ev_type],
iio_ev_dir_text[dir]);
}
int main(int argc, char **argv)
{
struct iio_event_data event;
const char *device_name;
char *chrdev_name;
int ret;
int dev_num;
int fd, event_fd;
if (argc <= 1) {
printf("Usage: %s <device_name>\n", argv[0]);
return -1;
}
device_name = argv[1];
dev_num = find_type_by_name(device_name, "iio:device");
if (dev_num >= 0) {
printf("Found IIO device with name %s with device number %d\n",
device_name, dev_num);
ret = asprintf(&chrdev_name, "/dev/iio:device%d", dev_num);
if (ret < 0) {
ret = -ENOMEM;
goto error_ret;
}
} else {
chrdev_name = strdup(device_name);
}
fd = open(chrdev_name, 0);
if (fd == -1) {
fprintf(stdout, "Failed to open %s\n", chrdev_name);
ret = -errno;
goto error_free_chrdev_name;
}
ret = ioctl(fd, IIO_GET_EVENT_FD_IOCTL, &event_fd);
close(fd);
if (ret == -1 || event_fd == -1) {
fprintf(stdout, "Failed to retrieve event fd\n");
ret = -errno;
goto error_free_chrdev_name;
}
while (true) {
ret = read(event_fd, &event, sizeof(event));
if (ret == -1) {
if (errno == EAGAIN) {
printf("nothing available\n");
continue;
} else {
perror("Failed to read event from device");
ret = -errno;
break;
}
}
print_event(&event);
}
close(event_fd);
error_free_chrdev_name:
free(chrdev_name);
error_ret:
return ret;
}
