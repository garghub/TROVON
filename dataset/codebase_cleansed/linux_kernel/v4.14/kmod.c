static void free_modprobe_argv(struct subprocess_info *info)
{
kfree(info->argv[3]);
kfree(info->argv);
}
static int call_modprobe(char *module_name, int wait)
{
struct subprocess_info *info;
static char *envp[] = {
"HOME=/",
"TERM=linux",
"PATH=/sbin:/usr/sbin:/bin:/usr/bin",
NULL
};
char **argv = kmalloc(sizeof(char *[5]), GFP_KERNEL);
if (!argv)
goto out;
module_name = kstrdup(module_name, GFP_KERNEL);
if (!module_name)
goto free_argv;
argv[0] = modprobe_path;
argv[1] = "-q";
argv[2] = "--";
argv[3] = module_name;
argv[4] = NULL;
info = call_usermodehelper_setup(modprobe_path, argv, envp, GFP_KERNEL,
NULL, free_modprobe_argv, NULL);
if (!info)
goto free_module_name;
return call_usermodehelper_exec(info, wait | UMH_KILLABLE);
free_module_name:
kfree(module_name);
free_argv:
kfree(argv);
out:
return -ENOMEM;
}
int __request_module(bool wait, const char *fmt, ...)
{
va_list args;
char module_name[MODULE_NAME_LEN];
int ret;
WARN_ON_ONCE(wait && current_is_async());
if (!modprobe_path[0])
return 0;
va_start(args, fmt);
ret = vsnprintf(module_name, MODULE_NAME_LEN, fmt, args);
va_end(args);
if (ret >= MODULE_NAME_LEN)
return -ENAMETOOLONG;
ret = security_kernel_module_request(module_name);
if (ret)
return ret;
if (atomic_dec_if_positive(&kmod_concurrent_max) < 0) {
pr_warn_ratelimited("request_module: kmod_concurrent_max (%u) close to 0 (max_modprobes: %u), for module %s, throttling...",
atomic_read(&kmod_concurrent_max),
MAX_KMOD_CONCURRENT, module_name);
ret = wait_event_killable_timeout(kmod_wq,
atomic_dec_if_positive(&kmod_concurrent_max) >= 0,
MAX_KMOD_ALL_BUSY_TIMEOUT * HZ);
if (!ret) {
pr_warn_ratelimited("request_module: modprobe %s cannot be processed, kmod busy with %d threads for more than %d seconds now",
module_name, MAX_KMOD_CONCURRENT, MAX_KMOD_ALL_BUSY_TIMEOUT);
return -ETIME;
} else if (ret == -ERESTARTSYS) {
pr_warn_ratelimited("request_module: sigkill sent for modprobe %s, giving up", module_name);
return ret;
}
}
trace_module_request(module_name, wait, _RET_IP_);
ret = call_modprobe(module_name, wait ? UMH_WAIT_PROC : UMH_WAIT_EXEC);
atomic_inc(&kmod_concurrent_max);
wake_up(&kmod_wq);
return ret;
}
