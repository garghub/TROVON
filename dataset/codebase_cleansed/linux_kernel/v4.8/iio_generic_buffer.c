int size_from_channelarray(struct iio_channel_info *channels, int num_channels)
{
int bytes = 0;
int i = 0;
while (i < num_channels) {
if (bytes % channels[i].bytes == 0)
channels[i].location = bytes;
else
channels[i].location = bytes - bytes % channels[i].bytes
+ channels[i].bytes;
bytes = channels[i].location + channels[i].bytes;
i++;
}
return bytes;
}
void print1byte(uint8_t input, struct iio_channel_info *info)
{
input >>= info->shift;
input &= info->mask;
if (info->is_signed) {
int8_t val = (int8_t)(input << (8 - info->bits_used)) >>
(8 - info->bits_used);
printf("%05f ", ((float)val + info->offset) * info->scale);
} else {
printf("%05f ", ((float)input + info->offset) * info->scale);
}
}
void print2byte(uint16_t input, struct iio_channel_info *info)
{
if (info->be)
input = be16toh(input);
else
input = le16toh(input);
input >>= info->shift;
input &= info->mask;
if (info->is_signed) {
int16_t val = (int16_t)(input << (16 - info->bits_used)) >>
(16 - info->bits_used);
printf("%05f ", ((float)val + info->offset) * info->scale);
} else {
printf("%05f ", ((float)input + info->offset) * info->scale);
}
}
void print4byte(uint32_t input, struct iio_channel_info *info)
{
if (info->be)
input = be32toh(input);
else
input = le32toh(input);
input >>= info->shift;
input &= info->mask;
if (info->is_signed) {
int32_t val = (int32_t)(input << (32 - info->bits_used)) >>
(32 - info->bits_used);
printf("%05f ", ((float)val + info->offset) * info->scale);
} else {
printf("%05f ", ((float)input + info->offset) * info->scale);
}
}
void print8byte(uint64_t input, struct iio_channel_info *info)
{
if (info->be)
input = be64toh(input);
else
input = le64toh(input);
input >>= info->shift;
input &= info->mask;
if (info->is_signed) {
int64_t val = (int64_t)(input << (64 - info->bits_used)) >>
(64 - info->bits_used);
if (info->scale == 1.0f && info->offset == 0.0f)
printf("%" PRId64 " ", val);
else
printf("%05f ",
((float)val + info->offset) * info->scale);
} else {
printf("%05f ", ((float)input + info->offset) * info->scale);
}
}
void process_scan(char *data,
struct iio_channel_info *channels,
int num_channels)
{
int k;
for (k = 0; k < num_channels; k++)
switch (channels[k].bytes) {
case 1:
print1byte(*(uint8_t *)(data + channels[k].location),
&channels[k]);
break;
case 2:
print2byte(*(uint16_t *)(data + channels[k].location),
&channels[k]);
break;
case 4:
print4byte(*(uint32_t *)(data + channels[k].location),
&channels[k]);
break;
case 8:
print8byte(*(uint64_t *)(data + channels[k].location),
&channels[k]);
break;
default:
break;
}
printf("\n");
}
static int enable_disable_all_channels(char *dev_dir_name, int enable)
{
const struct dirent *ent;
char scanelemdir[256];
DIR *dp;
int ret;
snprintf(scanelemdir, sizeof(scanelemdir),
FORMAT_SCAN_ELEMENTS_DIR, dev_dir_name);
scanelemdir[sizeof(scanelemdir)-1] = '\0';
dp = opendir(scanelemdir);
if (!dp) {
fprintf(stderr, "Enabling/disabling channels: can't open %s\n",
scanelemdir);
return -EIO;
}
ret = -ENOENT;
while (ent = readdir(dp), ent) {
if (iioutils_check_suffix(ent->d_name, "_en")) {
printf("%sabling: %s\n",
enable ? "En" : "Dis",
ent->d_name);
ret = write_sysfs_int(ent->d_name, scanelemdir,
enable);
if (ret < 0)
fprintf(stderr, "Failed to enable/disable %s\n",
ent->d_name);
}
}
if (closedir(dp) == -1) {
perror("Enabling/disabling channels: "
"Failed to close directory");
return -errno;
}
return 0;
}
void print_usage(void)
{
fprintf(stderr, "Usage: generic_buffer [options]...\n"
"Capture, convert and output data from IIO device buffer\n"
" -a Auto-activate all available channels\n"
" -c <n> Do n conversions\n"
" -e Disable wait for event (new data)\n"
" -g Use trigger-less mode\n"
" -l <n> Set buffer length to n samples\n"
" --device-name -n <name>\n"
" --device-num -N <num>\n"
" Set device by name or number (mandatory)\n"
" --trigger-name -t <name>\n"
" --trigger-num -T <num>\n"
" Set trigger by name or number\n"
" -w <n> Set delay between reads in us (event-less mode)\n");
}
void cleanup(void)
{
int ret;
if (dev_dir_name && current_trigger_set) {
ret = write_sysfs_string("trigger/current_trigger",
dev_dir_name, "NULL");
if (ret < 0)
fprintf(stderr, "Failed to disable trigger: %s\n",
strerror(-ret));
current_trigger_set = false;
}
if (buf_dir_name) {
ret = write_sysfs_int("enable", buf_dir_name, 0);
if (ret < 0)
fprintf(stderr, "Failed to disable buffer: %s\n",
strerror(-ret));
}
if (dev_dir_name && autochannels == AUTOCHANNELS_ACTIVE) {
ret = enable_disable_all_channels(dev_dir_name, 0);
if (ret)
fprintf(stderr, "Failed to disable all channels\n");
autochannels = AUTOCHANNELS_DISABLED;
}
}
void sig_handler(int signum)
{
fprintf(stderr, "Caught signal %d\n", signum);
cleanup();
exit(-signum);
}
void register_cleanup(void)
{
struct sigaction sa = { .sa_handler = sig_handler };
const int signums[] = { SIGINT, SIGTERM, SIGABRT };
int ret, i;
for (i = 0; i < ARRAY_SIZE(signums); ++i) {
ret = sigaction(signums[i], &sa, NULL);
if (ret) {
perror("Failed to register signal handler");
exit(-1);
}
}
}
int main(int argc, char **argv)
{
unsigned long num_loops = 2;
unsigned long timedelay = 1000000;
unsigned long buf_len = 128;
int ret, c, i, j, toread;
int fp = -1;
int num_channels = 0;
char *trigger_name = NULL, *device_name = NULL;
char *data = NULL;
ssize_t read_size;
int dev_num = -1, trig_num = -1;
char *buffer_access = NULL;
int scan_size;
int noevents = 0;
int notrigger = 0;
char *dummy;
struct iio_channel_info *channels = NULL;
register_cleanup();
while ((c = getopt_long(argc, argv, "ac:egl:n:N:t:T:w:", longopts, NULL)) != -1) {
switch (c) {
case 'a':
autochannels = AUTOCHANNELS_ENABLED;
break;
case 'c':
errno = 0;
num_loops = strtoul(optarg, &dummy, 10);
if (errno) {
ret = -errno;
goto error;
}
break;
case 'e':
noevents = 1;
break;
case 'g':
notrigger = 1;
break;
case 'l':
errno = 0;
buf_len = strtoul(optarg, &dummy, 10);
if (errno) {
ret = -errno;
goto error;
}
break;
case 'n':
device_name = strdup(optarg);
break;
case 'N':
errno = 0;
dev_num = strtoul(optarg, &dummy, 10);
if (errno) {
ret = -errno;
goto error;
}
break;
case 't':
trigger_name = strdup(optarg);
break;
case 'T':
errno = 0;
trig_num = strtoul(optarg, &dummy, 10);
if (errno)
return -errno;
break;
case 'w':
errno = 0;
timedelay = strtoul(optarg, &dummy, 10);
if (errno) {
ret = -errno;
goto error;
}
break;
case '?':
print_usage();
ret = -1;
goto error;
}
}
if (dev_num < 0 && !device_name) {
fprintf(stderr, "Device not set\n");
print_usage();
ret = -1;
goto error;
} else if (dev_num >= 0 && device_name) {
fprintf(stderr, "Only one of --device-num or --device-name needs to be set\n");
print_usage();
ret = -1;
goto error;
} else if (dev_num < 0) {
dev_num = find_type_by_name(device_name, "iio:device");
if (dev_num < 0) {
fprintf(stderr, "Failed to find the %s\n", device_name);
ret = dev_num;
goto error;
}
}
printf("iio device number being used is %d\n", dev_num);
ret = asprintf(&dev_dir_name, "%siio:device%d", iio_dir, dev_num);
if (ret < 0)
return -ENOMEM;
if (!device_name) {
device_name = malloc(IIO_MAX_NAME_LENGTH);
if (!device_name) {
ret = -ENOMEM;
goto error;
}
ret = read_sysfs_string("name", dev_dir_name, device_name);
if (ret < 0) {
fprintf(stderr, "Failed to read name of device %d\n", dev_num);
goto error;
}
}
if (notrigger) {
printf("trigger-less mode selected\n");
} else if (trig_num >= 0) {
char *trig_dev_name;
ret = asprintf(&trig_dev_name, "%strigger%d", iio_dir, trig_num);
if (ret < 0) {
return -ENOMEM;
}
trigger_name = malloc(IIO_MAX_NAME_LENGTH);
ret = read_sysfs_string("name", trig_dev_name, trigger_name);
free(trig_dev_name);
if (ret < 0) {
fprintf(stderr, "Failed to read trigger%d name from\n", trig_num);
return ret;
}
printf("iio trigger number being used is %d\n", trig_num);
} else {
if (!trigger_name) {
ret = asprintf(&trigger_name,
"%s-dev%d", device_name, dev_num);
if (ret < 0) {
ret = -ENOMEM;
goto error;
}
}
trig_num = find_type_by_name(trigger_name, "trigger");
if (trig_num < 0) {
free(trigger_name);
ret = asprintf(&trigger_name,
"%s-trigger", device_name);
if (ret < 0) {
ret = -ENOMEM;
goto error;
}
}
trig_num = find_type_by_name(trigger_name, "trigger");
if (trig_num < 0) {
fprintf(stderr, "Failed to find the trigger %s\n",
trigger_name);
ret = trig_num;
goto error;
}
printf("iio trigger number being used is %d\n", trig_num);
}
ret = build_channel_array(dev_dir_name, &channels, &num_channels);
if (ret) {
fprintf(stderr, "Problem reading scan element information\n"
"diag %s\n", dev_dir_name);
goto error;
}
if (num_channels && autochannels == AUTOCHANNELS_ENABLED) {
fprintf(stderr, "Auto-channels selected but some channels "
"are already activated in sysfs\n");
fprintf(stderr, "Proceeding without activating any channels\n");
}
if (!num_channels && autochannels == AUTOCHANNELS_ENABLED) {
fprintf(stderr,
"No channels are enabled, enabling all channels\n");
ret = enable_disable_all_channels(dev_dir_name, 1);
if (ret) {
fprintf(stderr, "Failed to enable all channels\n");
goto error;
}
autochannels = AUTOCHANNELS_ACTIVE;
ret = build_channel_array(dev_dir_name, &channels,
&num_channels);
if (ret) {
fprintf(stderr, "Problem reading scan element "
"information\n"
"diag %s\n", dev_dir_name);
goto error;
}
if (!num_channels) {
fprintf(stderr, "Still no channels after "
"auto-enabling, giving up\n");
goto error;
}
}
if (!num_channels && autochannels == AUTOCHANNELS_DISABLED) {
fprintf(stderr,
"No channels are enabled, we have nothing to scan.\n");
fprintf(stderr, "Enable channels manually in "
FORMAT_SCAN_ELEMENTS_DIR
"/*_en or pass -a to autoenable channels and "
"try again.\n", dev_dir_name);
ret = -ENOENT;
goto error;
}
ret = asprintf(&buf_dir_name,
"%siio:device%d/buffer", iio_dir, dev_num);
if (ret < 0) {
ret = -ENOMEM;
goto error;
}
if (!notrigger) {
printf("%s %s\n", dev_dir_name, trigger_name);
ret = write_sysfs_string_and_verify("trigger/current_trigger",
dev_dir_name,
trigger_name);
if (ret < 0) {
fprintf(stderr,
"Failed to write current_trigger file\n");
goto error;
}
}
ret = write_sysfs_int("length", buf_dir_name, buf_len);
if (ret < 0)
goto error;
ret = write_sysfs_int("enable", buf_dir_name, 1);
if (ret < 0) {
fprintf(stderr,
"Failed to enable buffer: %s\n", strerror(-ret));
goto error;
}
scan_size = size_from_channelarray(channels, num_channels);
data = malloc(scan_size * buf_len);
if (!data) {
ret = -ENOMEM;
goto error;
}
ret = asprintf(&buffer_access, "/dev/iio:device%d", dev_num);
if (ret < 0) {
ret = -ENOMEM;
goto error;
}
fp = open(buffer_access, O_RDONLY | O_NONBLOCK);
if (fp == -1) {
ret = -errno;
fprintf(stderr, "Failed to open %s\n", buffer_access);
goto error;
}
for (j = 0; j < num_loops; j++) {
if (!noevents) {
struct pollfd pfd = {
.fd = fp,
.events = POLLIN,
};
ret = poll(&pfd, 1, -1);
if (ret < 0) {
ret = -errno;
goto error;
} else if (ret == 0) {
continue;
}
toread = buf_len;
} else {
usleep(timedelay);
toread = 64;
}
read_size = read(fp, data, toread * scan_size);
if (read_size < 0) {
if (errno == EAGAIN) {
fprintf(stderr, "nothing available\n");
continue;
} else {
break;
}
}
for (i = 0; i < read_size / scan_size; i++)
process_scan(data + scan_size * i, channels,
num_channels);
}
error:
cleanup();
if (fp >= 0 && close(fp) == -1)
perror("Failed to close buffer");
free(buffer_access);
free(data);
free(buf_dir_name);
for (i = num_channels - 1; i >= 0; i--) {
free(channels[i].name);
free(channels[i].generic_name);
}
free(channels);
free(trigger_name);
free(device_name);
free(dev_dir_name);
return ret;
}
