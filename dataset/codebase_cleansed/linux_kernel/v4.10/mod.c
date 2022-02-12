void _p9_debug(enum p9_debug_flags level, const char *func,
const char *fmt, ...)
{
struct va_format vaf;
va_list args;
if ((p9_debug_level & level) != level)
return;
va_start(args, fmt);
vaf.fmt = fmt;
vaf.va = &args;
if (level == P9_DEBUG_9P)
pr_notice("(%8.8d) %pV", task_pid_nr(current), &vaf);
else
pr_notice("-- %s (%d): %pV", func, task_pid_nr(current), &vaf);
va_end(args);
}
void v9fs_register_trans(struct p9_trans_module *m)
{
spin_lock(&v9fs_trans_lock);
list_add_tail(&m->list, &v9fs_trans_list);
spin_unlock(&v9fs_trans_lock);
}
void v9fs_unregister_trans(struct p9_trans_module *m)
{
spin_lock(&v9fs_trans_lock);
list_del_init(&m->list);
spin_unlock(&v9fs_trans_lock);
}
struct p9_trans_module *v9fs_get_trans_by_name(char *s)
{
struct p9_trans_module *t, *found = NULL;
spin_lock(&v9fs_trans_lock);
list_for_each_entry(t, &v9fs_trans_list, list)
if (strcmp(t->name, s) == 0 &&
try_module_get(t->owner)) {
found = t;
break;
}
spin_unlock(&v9fs_trans_lock);
return found;
}
struct p9_trans_module *v9fs_get_default_trans(void)
{
struct p9_trans_module *t, *found = NULL;
spin_lock(&v9fs_trans_lock);
list_for_each_entry(t, &v9fs_trans_list, list)
if (t->def && try_module_get(t->owner)) {
found = t;
break;
}
if (!found)
list_for_each_entry(t, &v9fs_trans_list, list)
if (try_module_get(t->owner)) {
found = t;
break;
}
spin_unlock(&v9fs_trans_lock);
return found;
}
void v9fs_put_trans(struct p9_trans_module *m)
{
if (m)
module_put(m->owner);
}
static int __init init_p9(void)
{
int ret = 0;
p9_error_init();
pr_info("Installing 9P2000 support\n");
p9_trans_fd_init();
return ret;
}
static void __exit exit_p9(void)
{
pr_info("Unloading 9P2000 support\n");
p9_trans_fd_exit();
}
