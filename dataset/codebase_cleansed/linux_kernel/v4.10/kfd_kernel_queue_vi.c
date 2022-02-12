void kernel_queue_init_vi(struct kernel_queue_ops *ops)
{
ops->initialize = initialize_vi;
ops->uninitialize = uninitialize_vi;
}
static bool initialize_vi(struct kernel_queue *kq, struct kfd_dev *dev,
enum kfd_queue_type type, unsigned int queue_size)
{
int retval;
retval = kfd_gtt_sa_allocate(dev, PAGE_SIZE, &kq->eop_mem);
if (retval != 0)
return false;
kq->eop_gpu_addr = kq->eop_mem->gpu_addr;
kq->eop_kernel_addr = kq->eop_mem->cpu_ptr;
memset(kq->eop_kernel_addr, 0, PAGE_SIZE);
return true;
}
static void uninitialize_vi(struct kernel_queue *kq)
{
kfd_gtt_sa_free(kq->dev, kq->eop_mem);
}
