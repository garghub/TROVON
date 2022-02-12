static int set_unload_heads_path(char *device)
{
if (strlen(device) <= 5 || strncmp(device, "/dev/", 5) != 0)
return -EINVAL;
strncpy(device_path, device, sizeof(device_path) - 1);
snprintf(unload_heads_path, sizeof(unload_heads_path) - 1,
"/sys/block/%s/device/unload_heads", device+5);
return 0;
}
static int valid_disk(void)
{
int fd = open(unload_heads_path, O_RDONLY);
if (fd < 0) {
perror(unload_heads_path);
return 0;
}
close(fd);
return 1;
}
static void write_int(char *path, int i)
{
char buf[1024];
int fd = open(path, O_RDWR);
if (fd < 0) {
perror("open");
exit(1);
}
sprintf(buf, "%d", i);
if (write(fd, buf, strlen(buf)) != strlen(buf)) {
perror("write");
exit(1);
}
close(fd);
}
static void set_led(int on)
{
if (noled)
return;
write_int("/sys/class/leds/hp::hddprotect/brightness", on);
}
static void protect(int seconds)
{
const char *str = (seconds == 0) ? "Unparked" : "Parked";
write_int(unload_heads_path, seconds*1000);
syslog(LOG_INFO, "%s %s disk head\n", str, device_path);
}
static int on_ac(void)
{
return 1;
}
static int lid_open(void)
{
return 1;
}
static void ignore_me(int signum)
{
protect(0);
set_led(0);
}
int main(int argc, char **argv)
{
int fd, ret;
struct stat st;
struct sched_param param;
if (argc == 1)
ret = set_unload_heads_path("/dev/sda");
else if (argc == 2)
ret = set_unload_heads_path(argv[1]);
else
ret = -EINVAL;
if (ret || !valid_disk()) {
fprintf(stderr, "usage: %s <device> (default: /dev/sda)\n",
argv[0]);
exit(1);
}
fd = open("/dev/freefall", O_RDONLY);
if (fd < 0) {
perror("/dev/freefall");
return EXIT_FAILURE;
}
if (stat("/sys/class/leds/hp::hddprotect/brightness", &st))
noled = 1;
if (daemon(0, 0) != 0) {
perror("daemon");
return EXIT_FAILURE;
}
openlog(app_name, LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
param.sched_priority = sched_get_priority_max(SCHED_FIFO);
sched_setscheduler(0, SCHED_FIFO, &param);
mlockall(MCL_CURRENT|MCL_FUTURE);
signal(SIGALRM, ignore_me);
for (;;) {
unsigned char count;
ret = read(fd, &count, sizeof(count));
alarm(0);
if ((ret == -1) && (errno == EINTR)) {
continue;
}
if (ret != sizeof(count)) {
perror("read");
break;
}
protect(21);
set_led(1);
if (1 || on_ac() || lid_open())
alarm(2);
else
alarm(20);
}
closelog();
close(fd);
return EXIT_SUCCESS;
}
