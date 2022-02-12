int main(int argc, char const *argv[])
{
struct uleds_user_dev uleds_dev;
int fd, ret;
int brightness;
struct timespec ts;
if (argc != 2) {
fprintf(stderr, "Requires <device-name> argument\n");
return 1;
}
strncpy(uleds_dev.name, argv[1], LED_MAX_NAME_SIZE);
uleds_dev.max_brightness = 100;
fd = open("/dev/uleds", O_RDWR);
if (fd == -1) {
perror("Failed to open /dev/uleds");
return 1;
}
ret = write(fd, &uleds_dev, sizeof(uleds_dev));
if (ret == -1) {
perror("Failed to write to /dev/uleds");
close(fd);
return 1;
}
while (1) {
ret = read(fd, &brightness, sizeof(brightness));
if (ret == -1) {
perror("Failed to read from /dev/uleds");
close(fd);
return 1;
}
clock_gettime(CLOCK_MONOTONIC, &ts);
printf("[%ld.%09ld] %u\n", ts.tv_sec, ts.tv_nsec, brightness);
}
close(fd);
return 0;
}
