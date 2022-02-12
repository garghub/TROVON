int kfd_init_apertures(struct kfd_process *process)
{
uint8_t id = 0;
struct kfd_dev *dev;
struct kfd_process_device *pdd;
while ((dev = kfd_topology_enum_kfd_devices(id)) != NULL &&
id < NUM_OF_SUPPORTED_GPUS) {
pdd = kfd_create_process_device_data(dev, process);
if (pdd == NULL) {
pr_err("Failed to create process device data\n");
return -1;
}
if (process->is_32bit_user_mode) {
pdd->lds_base = pdd->lds_limit = 0;
pdd->gpuvm_base = pdd->gpuvm_limit = 0;
pdd->scratch_base = pdd->scratch_limit = 0;
} else {
pdd->lds_base = MAKE_LDS_APP_BASE(id + 1);
pdd->lds_limit = MAKE_LDS_APP_LIMIT(pdd->lds_base);
pdd->gpuvm_base = MAKE_GPUVM_APP_BASE(id + 1);
pdd->gpuvm_limit =
MAKE_GPUVM_APP_LIMIT(pdd->gpuvm_base);
pdd->scratch_base = MAKE_SCRATCH_APP_BASE(id + 1);
pdd->scratch_limit =
MAKE_SCRATCH_APP_LIMIT(pdd->scratch_base);
}
dev_dbg(kfd_device, "node id %u\n", id);
dev_dbg(kfd_device, "gpu id %u\n", pdd->dev->id);
dev_dbg(kfd_device, "lds_base %llX\n", pdd->lds_base);
dev_dbg(kfd_device, "lds_limit %llX\n", pdd->lds_limit);
dev_dbg(kfd_device, "gpuvm_base %llX\n", pdd->gpuvm_base);
dev_dbg(kfd_device, "gpuvm_limit %llX\n", pdd->gpuvm_limit);
dev_dbg(kfd_device, "scratch_base %llX\n", pdd->scratch_base);
dev_dbg(kfd_device, "scratch_limit %llX\n", pdd->scratch_limit);
id++;
}
return 0;
}
