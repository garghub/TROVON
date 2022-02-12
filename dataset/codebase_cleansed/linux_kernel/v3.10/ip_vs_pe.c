struct ip_vs_pe *__ip_vs_pe_getbyname(const char *pe_name)
{
struct ip_vs_pe *pe;
IP_VS_DBG(10, "%s(): pe_name \"%s\"\n", __func__,
pe_name);
rcu_read_lock();
list_for_each_entry_rcu(pe, &ip_vs_pe, n_list) {
if (pe->module &&
!try_module_get(pe->module)) {
continue;
}
if (strcmp(pe_name, pe->name)==0) {
rcu_read_unlock();
return pe;
}
if (pe->module)
module_put(pe->module);
}
rcu_read_unlock();
return NULL;
}
struct ip_vs_pe *ip_vs_pe_getbyname(const char *name)
{
struct ip_vs_pe *pe;
pe = __ip_vs_pe_getbyname(name);
if (!pe) {
request_module("ip_vs_pe_%s", name);
pe = __ip_vs_pe_getbyname(name);
}
return pe;
}
int register_ip_vs_pe(struct ip_vs_pe *pe)
{
struct ip_vs_pe *tmp;
ip_vs_use_count_inc();
mutex_lock(&ip_vs_pe_mutex);
list_for_each_entry(tmp, &ip_vs_pe, n_list) {
if (strcmp(tmp->name, pe->name) == 0) {
mutex_unlock(&ip_vs_pe_mutex);
ip_vs_use_count_dec();
pr_err("%s(): [%s] pe already existed "
"in the system\n", __func__, pe->name);
return -EINVAL;
}
}
list_add_rcu(&pe->n_list, &ip_vs_pe);
mutex_unlock(&ip_vs_pe_mutex);
pr_info("[%s] pe registered.\n", pe->name);
return 0;
}
int unregister_ip_vs_pe(struct ip_vs_pe *pe)
{
mutex_lock(&ip_vs_pe_mutex);
list_del_rcu(&pe->n_list);
mutex_unlock(&ip_vs_pe_mutex);
ip_vs_use_count_dec();
pr_info("[%s] pe unregistered.\n", pe->name);
return 0;
}
