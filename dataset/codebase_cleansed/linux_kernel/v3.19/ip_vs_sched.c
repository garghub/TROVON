int ip_vs_bind_scheduler(struct ip_vs_service *svc,
struct ip_vs_scheduler *scheduler)
{
int ret;
if (scheduler->init_service) {
ret = scheduler->init_service(svc);
if (ret) {
pr_err("%s(): init error\n", __func__);
return ret;
}
}
rcu_assign_pointer(svc->scheduler, scheduler);
return 0;
}
void ip_vs_unbind_scheduler(struct ip_vs_service *svc,
struct ip_vs_scheduler *sched)
{
struct ip_vs_scheduler *cur_sched;
cur_sched = rcu_dereference_protected(svc->scheduler, 1);
if (!cur_sched)
return;
if (sched->done_service)
sched->done_service(svc);
}
static struct ip_vs_scheduler *ip_vs_sched_getbyname(const char *sched_name)
{
struct ip_vs_scheduler *sched;
IP_VS_DBG(2, "%s(): sched_name \"%s\"\n", __func__, sched_name);
mutex_lock(&ip_vs_sched_mutex);
list_for_each_entry(sched, &ip_vs_schedulers, n_list) {
if (sched->module && !try_module_get(sched->module)) {
continue;
}
if (strcmp(sched_name, sched->name)==0) {
mutex_unlock(&ip_vs_sched_mutex);
return sched;
}
module_put(sched->module);
}
mutex_unlock(&ip_vs_sched_mutex);
return NULL;
}
struct ip_vs_scheduler *ip_vs_scheduler_get(const char *sched_name)
{
struct ip_vs_scheduler *sched;
sched = ip_vs_sched_getbyname(sched_name);
if (sched == NULL) {
request_module("ip_vs_%s", sched_name);
sched = ip_vs_sched_getbyname(sched_name);
}
return sched;
}
void ip_vs_scheduler_put(struct ip_vs_scheduler *scheduler)
{
if (scheduler && scheduler->module)
module_put(scheduler->module);
}
void ip_vs_scheduler_err(struct ip_vs_service *svc, const char *msg)
{
struct ip_vs_scheduler *sched;
sched = rcu_dereference(svc->scheduler);
if (svc->fwmark) {
IP_VS_ERR_RL("%s: FWM %u 0x%08X - %s\n",
sched->name, svc->fwmark, svc->fwmark, msg);
#ifdef CONFIG_IP_VS_IPV6
} else if (svc->af == AF_INET6) {
IP_VS_ERR_RL("%s: %s [%pI6c]:%d - %s\n",
sched->name, ip_vs_proto_name(svc->protocol),
&svc->addr.in6, ntohs(svc->port), msg);
#endif
} else {
IP_VS_ERR_RL("%s: %s %pI4:%d - %s\n",
sched->name, ip_vs_proto_name(svc->protocol),
&svc->addr.ip, ntohs(svc->port), msg);
}
}
int register_ip_vs_scheduler(struct ip_vs_scheduler *scheduler)
{
struct ip_vs_scheduler *sched;
if (!scheduler) {
pr_err("%s(): NULL arg\n", __func__);
return -EINVAL;
}
if (!scheduler->name) {
pr_err("%s(): NULL scheduler_name\n", __func__);
return -EINVAL;
}
ip_vs_use_count_inc();
mutex_lock(&ip_vs_sched_mutex);
if (!list_empty(&scheduler->n_list)) {
mutex_unlock(&ip_vs_sched_mutex);
ip_vs_use_count_dec();
pr_err("%s(): [%s] scheduler already linked\n",
__func__, scheduler->name);
return -EINVAL;
}
list_for_each_entry(sched, &ip_vs_schedulers, n_list) {
if (strcmp(scheduler->name, sched->name) == 0) {
mutex_unlock(&ip_vs_sched_mutex);
ip_vs_use_count_dec();
pr_err("%s(): [%s] scheduler already existed "
"in the system\n", __func__, scheduler->name);
return -EINVAL;
}
}
list_add(&scheduler->n_list, &ip_vs_schedulers);
mutex_unlock(&ip_vs_sched_mutex);
pr_info("[%s] scheduler registered.\n", scheduler->name);
return 0;
}
int unregister_ip_vs_scheduler(struct ip_vs_scheduler *scheduler)
{
if (!scheduler) {
pr_err("%s(): NULL arg\n", __func__);
return -EINVAL;
}
mutex_lock(&ip_vs_sched_mutex);
if (list_empty(&scheduler->n_list)) {
mutex_unlock(&ip_vs_sched_mutex);
pr_err("%s(): [%s] scheduler is not in the list. failed\n",
__func__, scheduler->name);
return -EINVAL;
}
list_del(&scheduler->n_list);
mutex_unlock(&ip_vs_sched_mutex);
ip_vs_use_count_dec();
pr_info("[%s] scheduler unregistered.\n", scheduler->name);
return 0;
}
