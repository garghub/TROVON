struct mqd_manager *mqd_manager_init(enum KFD_MQD_TYPE type,
struct kfd_dev *dev)
{
switch (dev->device_info->asic_family) {
case CHIP_KAVERI:
return mqd_manager_init_cik(type, dev);
case CHIP_CARRIZO:
return mqd_manager_init_vi(type, dev);
}
return NULL;
}
