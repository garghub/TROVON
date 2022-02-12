int kgd2kfd_init(unsigned interface_version, const struct kgd2kfd_calls **g2f)
{
if (!amdkfd_init_completed)
return -EPROBE_DEFER;
if (interface_version != KFD_INTERFACE_VERSION)
return -EINVAL;
*g2f = &kgd2kfd;
return 0;
}
void kgd2kfd_exit(void)
{
}
static int __init kfd_module_init(void)
{
int err;
if ((sched_policy < KFD_SCHED_POLICY_HWS) ||
(sched_policy > KFD_SCHED_POLICY_NO_HWS)) {
pr_err("kfd: sched_policy has invalid value\n");
return -1;
}
if ((max_num_of_queues_per_device < 1) ||
(max_num_of_queues_per_device >
KFD_MAX_NUM_OF_QUEUES_PER_DEVICE)) {
pr_err("kfd: max_num_of_queues_per_device must be between 1 to KFD_MAX_NUM_OF_QUEUES_PER_DEVICE\n");
return -1;
}
err = kfd_pasid_init();
if (err < 0)
goto err_pasid;
err = kfd_chardev_init();
if (err < 0)
goto err_ioctl;
err = kfd_topology_init();
if (err < 0)
goto err_topology;
kfd_process_create_wq();
amdkfd_init_completed = 1;
dev_info(kfd_device, "Initialized module\n");
return 0;
err_topology:
kfd_chardev_exit();
err_ioctl:
kfd_pasid_exit();
err_pasid:
return err;
}
static void __exit kfd_module_exit(void)
{
amdkfd_init_completed = 0;
kfd_process_destroy_wq();
kfd_topology_shutdown();
kfd_chardev_exit();
kfd_pasid_exit();
dev_info(kfd_device, "Removed module\n");
}
