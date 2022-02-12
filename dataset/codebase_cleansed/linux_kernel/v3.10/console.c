void pm_vt_switch_required(struct device *dev, bool required)
{
struct pm_vt_switch *entry, *tmp;
mutex_lock(&vt_switch_mutex);
list_for_each_entry(tmp, &pm_vt_switch_list, head) {
if (tmp->dev == dev) {
tmp->required = required;
goto out;
}
}
entry = kmalloc(sizeof(*entry), GFP_KERNEL);
if (!entry)
goto out;
entry->required = required;
entry->dev = dev;
list_add(&entry->head, &pm_vt_switch_list);
out:
mutex_unlock(&vt_switch_mutex);
}
void pm_vt_switch_unregister(struct device *dev)
{
struct pm_vt_switch *tmp;
mutex_lock(&vt_switch_mutex);
list_for_each_entry(tmp, &pm_vt_switch_list, head) {
if (tmp->dev == dev) {
list_del(&tmp->head);
break;
}
}
mutex_unlock(&vt_switch_mutex);
}
static bool pm_vt_switch(void)
{
struct pm_vt_switch *entry;
bool ret = true;
mutex_lock(&vt_switch_mutex);
if (list_empty(&pm_vt_switch_list))
goto out;
if (!console_suspend_enabled)
goto out;
list_for_each_entry(entry, &pm_vt_switch_list, head) {
if (entry->required)
goto out;
}
ret = false;
out:
mutex_unlock(&vt_switch_mutex);
return ret;
}
int pm_prepare_console(void)
{
if (!pm_vt_switch())
return 0;
orig_fgconsole = vt_move_to_console(SUSPEND_CONSOLE, 1);
if (orig_fgconsole < 0)
return 1;
orig_kmsg = vt_kmsg_redirect(SUSPEND_CONSOLE);
return 0;
}
void pm_restore_console(void)
{
if (!pm_vt_switch())
return;
if (orig_fgconsole >= 0) {
vt_move_to_console(orig_fgconsole, 0);
vt_kmsg_redirect(orig_kmsg);
}
}
