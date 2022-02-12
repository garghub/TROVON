void __gcov_init(struct gcov_info *info)
{
static unsigned int gcov_version;
mutex_lock(&gcov_lock);
if (gcov_version == 0) {
gcov_version = info->version;
pr_info("version magic: 0x%x\n", gcov_version);
}
info->next = gcov_info_head;
gcov_info_head = info;
if (gcov_events_enabled)
gcov_event(GCOV_ADD, info);
mutex_unlock(&gcov_lock);
}
void __gcov_flush(void)
{
}
void __gcov_merge_add(gcov_type *counters, unsigned int n_counters)
{
}
void __gcov_merge_single(gcov_type *counters, unsigned int n_counters)
{
}
void __gcov_merge_delta(gcov_type *counters, unsigned int n_counters)
{
}
void gcov_enable_events(void)
{
struct gcov_info *info;
mutex_lock(&gcov_lock);
gcov_events_enabled = 1;
for (info = gcov_info_head; info; info = info->next)
gcov_event(GCOV_ADD, info);
mutex_unlock(&gcov_lock);
}
static inline int within(void *addr, void *start, unsigned long size)
{
return ((addr >= start) && (addr < start + size));
}
static int gcov_module_notifier(struct notifier_block *nb, unsigned long event,
void *data)
{
struct module *mod = data;
struct gcov_info *info;
struct gcov_info *prev;
if (event != MODULE_STATE_GOING)
return NOTIFY_OK;
mutex_lock(&gcov_lock);
prev = NULL;
for (info = gcov_info_head; info; info = info->next) {
if (within(info, mod->module_core, mod->core_size)) {
if (prev)
prev->next = info->next;
else
gcov_info_head = info->next;
if (gcov_events_enabled)
gcov_event(GCOV_REMOVE, info);
} else
prev = info;
}
mutex_unlock(&gcov_lock);
return NOTIFY_OK;
}
static int __init gcov_init(void)
{
return register_module_notifier(&gcov_nb);
}
