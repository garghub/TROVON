int transport_subsystem_register(struct se_subsystem_api *sub_api)
{
struct se_subsystem_api *s;
INIT_LIST_HEAD(&sub_api->sub_api_list);
mutex_lock(&subsystem_mutex);
list_for_each_entry(s, &subsystem_list, sub_api_list) {
if (!strcmp(s->name, sub_api->name)) {
pr_err("%p is already registered with"
" duplicate name %s, unable to process"
" request\n", s, s->name);
mutex_unlock(&subsystem_mutex);
return -EEXIST;
}
}
list_add_tail(&sub_api->sub_api_list, &subsystem_list);
mutex_unlock(&subsystem_mutex);
pr_debug("TCM: Registered subsystem plugin: %s struct module:"
" %p\n", sub_api->name, sub_api->owner);
return 0;
}
void transport_subsystem_release(struct se_subsystem_api *sub_api)
{
mutex_lock(&subsystem_mutex);
list_del(&sub_api->sub_api_list);
mutex_unlock(&subsystem_mutex);
}
static struct se_subsystem_api *core_get_backend(const char *sub_name)
{
struct se_subsystem_api *s;
mutex_lock(&subsystem_mutex);
list_for_each_entry(s, &subsystem_list, sub_api_list) {
if (!strcmp(s->name, sub_name))
goto found;
}
mutex_unlock(&subsystem_mutex);
return NULL;
found:
if (s->owner && !try_module_get(s->owner))
s = NULL;
mutex_unlock(&subsystem_mutex);
return s;
}
struct se_hba *
core_alloc_hba(const char *plugin_name, u32 plugin_dep_id, u32 hba_flags)
{
struct se_hba *hba;
int ret = 0;
hba = kzalloc(sizeof(*hba), GFP_KERNEL);
if (!hba) {
pr_err("Unable to allocate struct se_hba\n");
return ERR_PTR(-ENOMEM);
}
INIT_LIST_HEAD(&hba->hba_dev_list);
spin_lock_init(&hba->device_lock);
mutex_init(&hba->hba_access_mutex);
hba->hba_index = scsi_get_new_index(SCSI_INST_INDEX);
hba->hba_flags |= hba_flags;
hba->transport = core_get_backend(plugin_name);
if (!hba->transport) {
ret = -EINVAL;
goto out_free_hba;
}
ret = hba->transport->attach_hba(hba, plugin_dep_id);
if (ret < 0)
goto out_module_put;
spin_lock(&hba_lock);
hba->hba_id = hba_id_counter++;
list_add_tail(&hba->hba_node, &hba_list);
spin_unlock(&hba_lock);
pr_debug("CORE_HBA[%d] - Attached HBA to Generic Target"
" Core\n", hba->hba_id);
return hba;
out_module_put:
if (hba->transport->owner)
module_put(hba->transport->owner);
hba->transport = NULL;
out_free_hba:
kfree(hba);
return ERR_PTR(ret);
}
int
core_delete_hba(struct se_hba *hba)
{
if (!list_empty(&hba->hba_dev_list))
dump_stack();
hba->transport->detach_hba(hba);
spin_lock(&hba_lock);
list_del(&hba->hba_node);
spin_unlock(&hba_lock);
pr_debug("CORE_HBA[%d] - Detached HBA from Generic Target"
" Core\n", hba->hba_id);
if (hba->transport->owner)
module_put(hba->transport->owner);
hba->transport = NULL;
kfree(hba);
return 0;
}
