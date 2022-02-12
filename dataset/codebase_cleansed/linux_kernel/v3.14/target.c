enum target_errno target__validate(struct target *target)
{
enum target_errno ret = TARGET_ERRNO__SUCCESS;
if (target->pid)
target->tid = target->pid;
if (target->tid && target->cpu_list) {
target->cpu_list = NULL;
if (ret == TARGET_ERRNO__SUCCESS)
ret = TARGET_ERRNO__PID_OVERRIDE_CPU;
}
if (target->tid && target->uid_str) {
target->uid_str = NULL;
if (ret == TARGET_ERRNO__SUCCESS)
ret = TARGET_ERRNO__PID_OVERRIDE_UID;
}
if (target->uid_str && target->cpu_list) {
target->cpu_list = NULL;
if (ret == TARGET_ERRNO__SUCCESS)
ret = TARGET_ERRNO__UID_OVERRIDE_CPU;
}
if (target->tid && target->system_wide) {
target->system_wide = false;
if (ret == TARGET_ERRNO__SUCCESS)
ret = TARGET_ERRNO__PID_OVERRIDE_SYSTEM;
}
if (target->uid_str && target->system_wide) {
target->system_wide = false;
if (ret == TARGET_ERRNO__SUCCESS)
ret = TARGET_ERRNO__UID_OVERRIDE_SYSTEM;
}
if (target->per_thread && (target->system_wide || target->cpu_list)) {
target->per_thread = false;
if (ret == TARGET_ERRNO__SUCCESS)
ret = TARGET_ERRNO__SYSTEM_OVERRIDE_THREAD;
}
return ret;
}
enum target_errno target__parse_uid(struct target *target)
{
struct passwd pwd, *result;
char buf[1024];
const char *str = target->uid_str;
target->uid = UINT_MAX;
if (str == NULL)
return TARGET_ERRNO__SUCCESS;
getpwnam_r(str, &pwd, buf, sizeof(buf), &result);
if (result == NULL) {
char *endptr;
int uid = strtol(str, &endptr, 10);
if (*endptr != '\0')
return TARGET_ERRNO__INVALID_UID;
getpwuid_r(uid, &pwd, buf, sizeof(buf), &result);
if (result == NULL)
return TARGET_ERRNO__USER_NOT_FOUND;
}
target->uid = result->pw_uid;
return TARGET_ERRNO__SUCCESS;
}
int target__strerror(struct target *target, int errnum,
char *buf, size_t buflen)
{
int idx;
const char *msg;
BUG_ON(buflen == 0);
if (errnum >= 0) {
const char *err = strerror_r(errnum, buf, buflen);
if (err != buf) {
size_t len = strlen(err);
memcpy(buf, err, min(buflen - 1, len));
*(buf + min(buflen - 1, len)) = '\0';
}
return 0;
}
if (errnum < __TARGET_ERRNO__START || errnum >= __TARGET_ERRNO__END)
return -1;
idx = errnum - __TARGET_ERRNO__START;
msg = target__error_str[idx];
switch (errnum) {
case TARGET_ERRNO__PID_OVERRIDE_CPU ...
TARGET_ERRNO__SYSTEM_OVERRIDE_THREAD:
snprintf(buf, buflen, "%s", msg);
break;
case TARGET_ERRNO__INVALID_UID:
case TARGET_ERRNO__USER_NOT_FOUND:
snprintf(buf, buflen, msg, target->uid_str);
break;
default:
break;
}
return 0;
}
