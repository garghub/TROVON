static int hv_start_fcopy(struct hv_start_fcopy *smsg)
{
int error = HV_E_FAIL;
char *q, *p;
if (strlen((char *)smsg->path_name) < (W_MAX_PATH - 2))
strcat((char *)smsg->path_name, "/");
p = (char *)smsg->path_name;
snprintf(target_fname, sizeof(target_fname), "%s/%s",
(char *)smsg->path_name, smsg->file_name);
syslog(LOG_INFO, "Target file name: %s", target_fname);
while ((q = strchr(p, '/')) != NULL) {
if (q == p) {
p++;
continue;
}
*q = '\0';
if (access((char *)smsg->path_name, F_OK)) {
if (smsg->copy_flags & CREATE_PATH) {
if (mkdir((char *)smsg->path_name, 0755)) {
syslog(LOG_ERR, "Failed to create %s",
(char *)smsg->path_name);
goto done;
}
} else {
syslog(LOG_ERR, "Invalid path: %s",
(char *)smsg->path_name);
goto done;
}
}
p = q + 1;
*q = '/';
}
if (!access(target_fname, F_OK)) {
syslog(LOG_INFO, "File: %s exists", target_fname);
if (!(smsg->copy_flags & OVER_WRITE)) {
error = HV_ERROR_ALREADY_EXISTS;
goto done;
}
}
target_fd = open(target_fname, O_RDWR | O_CREAT | O_CLOEXEC, 0744);
if (target_fd == -1) {
syslog(LOG_INFO, "Open Failed: %s", strerror(errno));
goto done;
}
error = 0;
done:
return error;
}
static int hv_copy_data(struct hv_do_fcopy *cpmsg)
{
ssize_t bytes_written;
bytes_written = pwrite(target_fd, cpmsg->data, cpmsg->size,
cpmsg->offset);
if (bytes_written != cpmsg->size)
return HV_E_FAIL;
return 0;
}
static int hv_copy_finished(void)
{
close(target_fd);
return 0;
}
static int hv_copy_cancel(void)
{
close(target_fd);
unlink(target_fname);
return 0;
}
int main(void)
{
int fd, fcopy_fd, len;
int error;
int version = FCOPY_CURRENT_VERSION;
char *buffer[4096 * 2];
struct hv_fcopy_hdr *in_msg;
if (daemon(1, 0)) {
syslog(LOG_ERR, "daemon() failed; error: %s", strerror(errno));
exit(EXIT_FAILURE);
}
openlog("HV_FCOPY", 0, LOG_USER);
syslog(LOG_INFO, "HV_FCOPY starting; pid is:%d", getpid());
fcopy_fd = open("/dev/vmbus/hv_fcopy", O_RDWR);
if (fcopy_fd < 0) {
syslog(LOG_ERR, "open /dev/vmbus/hv_fcopy failed; error: %d %s",
errno, strerror(errno));
exit(EXIT_FAILURE);
}
if ((write(fcopy_fd, &version, sizeof(int))) != sizeof(int)) {
syslog(LOG_ERR, "Registration failed: %s", strerror(errno));
exit(EXIT_FAILURE);
}
while (1) {
len = pread(fcopy_fd, buffer, (4096 * 2), 0);
if (len < 0) {
syslog(LOG_ERR, "pread failed: %s", strerror(errno));
exit(EXIT_FAILURE);
}
in_msg = (struct hv_fcopy_hdr *)buffer;
switch (in_msg->operation) {
case START_FILE_COPY:
error = hv_start_fcopy((struct hv_start_fcopy *)in_msg);
break;
case WRITE_TO_FILE:
error = hv_copy_data((struct hv_do_fcopy *)in_msg);
break;
case COMPLETE_FCOPY:
error = hv_copy_finished();
break;
case CANCEL_FCOPY:
error = hv_copy_cancel();
break;
default:
syslog(LOG_ERR, "Unknown operation: %d",
in_msg->operation);
}
if (pwrite(fcopy_fd, &error, sizeof(int), 0) != sizeof(int)) {
syslog(LOG_ERR, "pwrite failed: %s", strerror(errno));
exit(EXIT_FAILURE);
}
}
}
