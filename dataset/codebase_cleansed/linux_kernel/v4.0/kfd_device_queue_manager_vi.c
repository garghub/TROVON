void device_queue_manager_init_vi(struct device_queue_manager_ops *ops)
{
pr_warn("amdkfd: VI DQM is not currently supported\n");
ops->set_cache_memory_policy = set_cache_memory_policy_vi;
ops->register_process = register_process_vi;
ops->initialize = initialize_cpsch_vi;
}
static bool set_cache_memory_policy_vi(struct device_queue_manager *dqm,
struct qcm_process_device *qpd,
enum cache_policy default_policy,
enum cache_policy alternate_policy,
void __user *alternate_aperture_base,
uint64_t alternate_aperture_size)
{
return false;
}
static int register_process_vi(struct device_queue_manager *dqm,
struct qcm_process_device *qpd)
{
return -1;
}
static int initialize_cpsch_vi(struct device_queue_manager *dqm)
{
return 0;
}
