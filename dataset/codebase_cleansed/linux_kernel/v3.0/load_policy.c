static bool tomoyo_policy_loader_exists(void)
{
struct path path;
if (kern_path(tomoyo_loader, LOOKUP_FOLLOW, &path)) {
printk(KERN_INFO "Not activating Mandatory Access Control now "
"since %s doesn't exist.\n", tomoyo_loader);
return false;
}
path_put(&path);
return true;
}
void tomoyo_load_policy(const char *filename)
{
char *argv[2];
char *envp[3];
if (tomoyo_policy_loaded)
return;
if (strcmp(filename, "/sbin/init") &&
strcmp(filename, "/sbin/tomoyo-start"))
return;
if (!tomoyo_policy_loader_exists())
return;
printk(KERN_INFO "Calling %s to load policy. Please wait.\n",
tomoyo_loader);
argv[0] = (char *) tomoyo_loader;
argv[1] = NULL;
envp[0] = "HOME=/";
envp[1] = "PATH=/sbin:/bin:/usr/sbin:/usr/bin";
envp[2] = NULL;
call_usermodehelper(argv[0], argv, envp, 1);
tomoyo_check_profile();
}
