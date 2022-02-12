int gpiotools_request_linehandle(const char *device_name, unsigned int *lines,
unsigned int nlines, unsigned int flag,
struct gpiohandle_data *data,
const char *consumer_label)
{
struct gpiohandle_request req;
char *chrdev_name;
int fd;
int i;
int ret;
ret = asprintf(&chrdev_name, "/dev/%s", device_name);
if (ret < 0)
return -ENOMEM;
fd = open(chrdev_name, 0);
if (fd == -1) {
ret = -errno;
fprintf(stderr, "Failed to open %s\n", chrdev_name);
goto exit_close_error;
}
for (i = 0; i < nlines; i++)
req.lineoffsets[i] = lines[i];
req.flags = flag;
strcpy(req.consumer_label, consumer_label);
req.lines = nlines;
if (flag & GPIOHANDLE_REQUEST_OUTPUT)
memcpy(req.default_values, data, sizeof(req.default_values));
ret = ioctl(fd, GPIO_GET_LINEHANDLE_IOCTL, &req);
if (ret == -1) {
ret = -errno;
fprintf(stderr, "Failed to issue GET LINEHANDLE IOCTL (%d)\n",
ret);
}
exit_close_error:
if (close(fd) == -1)
perror("Failed to close GPIO character device file");
free(chrdev_name);
return ret < 0 ? ret : req.fd;
}
int gpiotools_set_values(const int fd, struct gpiohandle_data *data)
{
int ret;
ret = ioctl(fd, GPIOHANDLE_SET_LINE_VALUES_IOCTL, data);
if (ret == -1) {
ret = -errno;
fprintf(stderr, "Failed to issue %s (%d)\n",
"GPIOHANDLE_SET_LINE_VALUES_IOCTL", ret);
}
return ret;
}
int gpiotools_get_values(const int fd, struct gpiohandle_data *data)
{
int ret;
ret = ioctl(fd, GPIOHANDLE_GET_LINE_VALUES_IOCTL, data);
if (ret == -1) {
ret = -errno;
fprintf(stderr, "Failed to issue %s (%d)\n",
"GPIOHANDLE_GET_LINE_VALUES_IOCTL", ret);
}
return ret;
}
int gpiotools_release_linehandle(const int fd)
{
int ret;
ret = close(fd);
if (ret == -1) {
perror("Failed to close GPIO LINEHANDLE device file");
ret = -errno;
}
return ret;
}
int gpiotools_get(const char *device_name, unsigned int line)
{
struct gpiohandle_data data;
unsigned int lines[] = {line};
gpiotools_gets(device_name, lines, 1, &data);
return data.values[0];
}
int gpiotools_gets(const char *device_name, unsigned int *lines,
unsigned int nlines, struct gpiohandle_data *data)
{
int fd;
int ret;
int ret_close;
ret = gpiotools_request_linehandle(device_name, lines, nlines,
GPIOHANDLE_REQUEST_INPUT, data,
COMSUMER);
if (ret < 0)
return ret;
fd = ret;
ret = gpiotools_get_values(fd, data);
ret_close = gpiotools_release_linehandle(fd);
return ret < 0 ? ret : ret_close;
}
int gpiotools_set(const char *device_name, unsigned int line,
unsigned int value)
{
struct gpiohandle_data data;
unsigned int lines[] = {line};
data.values[0] = value;
return gpiotools_sets(device_name, lines, 1, &data);
}
int gpiotools_sets(const char *device_name, unsigned int *lines,
unsigned int nlines, struct gpiohandle_data *data)
{
int ret;
ret = gpiotools_request_linehandle(device_name, lines, nlines,
GPIOHANDLE_REQUEST_OUTPUT, data,
COMSUMER);
if (ret < 0)
return ret;
return gpiotools_release_linehandle(ret);
}
