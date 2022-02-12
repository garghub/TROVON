enum perf_target_errno perf_target__validate(struct perf_target *target)
{
enum perf_target_errno ret = PERF_ERRNO_TARGET__SUCCESS;
if (target->pid)
target->tid = target->pid;
if (target->tid && target->cpu_list) {
target->cpu_list = NULL;
if (ret == PERF_ERRNO_TARGET__SUCCESS)
ret = PERF_ERRNO_TARGET__PID_OVERRIDE_CPU;
}
if (target->tid && target->uid_str) {
target->uid_str = NULL;
if (ret == PERF_ERRNO_TARGET__SUCCESS)
ret = PERF_ERRNO_TARGET__PID_OVERRIDE_UID;
}
if (target->uid_str && target->cpu_list) {
target->cpu_list = NULL;
if (ret == PERF_ERRNO_TARGET__SUCCESS)
ret = PERF_ERRNO_TARGET__UID_OVERRIDE_CPU;
}
if (target->tid && target->system_wide) {
target->system_wide = false;
if (ret == PERF_ERRNO_TARGET__SUCCESS)
ret = PERF_ERRNO_TARGET__PID_OVERRIDE_SYSTEM;
}
if (target->uid_str && target->system_wide) {
target->system_wide = false;
if (ret == PERF_ERRNO_TARGET__SUCCESS)
ret = PERF_ERRNO_TARGET__UID_OVERRIDE_SYSTEM;
}
return ret;
}
enum perf_target_errno perf_target__parse_uid(struct perf_target *target)
{
struct passwd pwd, *result;
char buf[1024];
const char *str = target->uid_str;
target->uid = UINT_MAX;
if (str == NULL)
return PERF_ERRNO_TARGET__SUCCESS;
getpwnam_r(str, &pwd, buf, sizeof(buf), &result);
if (result == NULL) {
char *endptr;
int uid = strtol(str, &endptr, 10);
if (*endptr != '\0')
return PERF_ERRNO_TARGET__INVALID_UID;
getpwuid_r(uid, &pwd, buf, sizeof(buf), &result);
if (result == NULL)
return PERF_ERRNO_TARGET__USER_NOT_FOUND;
}
target->uid = result->pw_uid;
return PERF_ERRNO_TARGET__SUCCESS;
}
int perf_target__strerror(struct perf_target *target, int errnum,
char *buf, size_t buflen)
{
int idx;
const char *msg;
if (errnum >= 0) {
strerror_r(errnum, buf, buflen);
return 0;
}
if (errnum < __PERF_ERRNO_TARGET__START ||
errnum >= __PERF_ERRNO_TARGET__END)
return -1;
idx = errnum - __PERF_ERRNO_TARGET__START;
msg = perf_target__error_str[idx];
switch (errnum) {
case PERF_ERRNO_TARGET__PID_OVERRIDE_CPU
... PERF_ERRNO_TARGET__UID_OVERRIDE_SYSTEM:
snprintf(buf, buflen, "%s", msg);
break;
case PERF_ERRNO_TARGET__INVALID_UID:
case PERF_ERRNO_TARGET__USER_NOT_FOUND:
snprintf(buf, buflen, msg, target->uid_str);
break;
default:
break;
}
return 0;
}
