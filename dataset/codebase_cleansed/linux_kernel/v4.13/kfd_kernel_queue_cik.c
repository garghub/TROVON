void kernel_queue_init_cik(struct kernel_queue_ops *ops)
{
ops->initialize = initialize_cik;
ops->uninitialize = uninitialize_cik;
}
static bool initialize_cik(struct kernel_queue *kq, struct kfd_dev *dev,
enum kfd_queue_type type, unsigned int queue_size)
{
return true;
}
static void uninitialize_cik(struct kernel_queue *kq)
{
}
