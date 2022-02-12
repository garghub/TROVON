int kfd_interrupt_init(struct kfd_dev *kfd)
{
void *interrupt_ring = kmalloc_array(KFD_INTERRUPT_RING_SIZE,
kfd->device_info->ih_ring_entry_size,
GFP_KERNEL);
if (!interrupt_ring)
return -ENOMEM;
kfd->interrupt_ring = interrupt_ring;
kfd->interrupt_ring_size =
KFD_INTERRUPT_RING_SIZE * kfd->device_info->ih_ring_entry_size;
atomic_set(&kfd->interrupt_ring_wptr, 0);
atomic_set(&kfd->interrupt_ring_rptr, 0);
spin_lock_init(&kfd->interrupt_lock);
INIT_WORK(&kfd->interrupt_work, interrupt_wq);
kfd->interrupts_active = true;
smp_wmb();
return 0;
}
void kfd_interrupt_exit(struct kfd_dev *kfd)
{
unsigned long flags;
spin_lock_irqsave(&kfd->interrupt_lock, flags);
kfd->interrupts_active = false;
spin_unlock_irqrestore(&kfd->interrupt_lock, flags);
flush_scheduled_work();
kfree(kfd->interrupt_ring);
}
bool enqueue_ih_ring_entry(struct kfd_dev *kfd, const void *ih_ring_entry)
{
unsigned int rptr = atomic_read(&kfd->interrupt_ring_rptr);
unsigned int wptr = atomic_read(&kfd->interrupt_ring_wptr);
if ((rptr - wptr) % kfd->interrupt_ring_size ==
kfd->device_info->ih_ring_entry_size) {
dev_err_ratelimited(kfd_chardev(),
"Interrupt ring overflow, dropping interrupt.\n");
return false;
}
memcpy(kfd->interrupt_ring + wptr, ih_ring_entry,
kfd->device_info->ih_ring_entry_size);
wptr = (wptr + kfd->device_info->ih_ring_entry_size) %
kfd->interrupt_ring_size;
smp_wmb();
atomic_set(&kfd->interrupt_ring_wptr, wptr);
return true;
}
static bool dequeue_ih_ring_entry(struct kfd_dev *kfd, void *ih_ring_entry)
{
unsigned int wptr = atomic_read(&kfd->interrupt_ring_wptr);
unsigned int rptr = atomic_read(&kfd->interrupt_ring_rptr);
if (rptr == wptr)
return false;
memcpy(ih_ring_entry, kfd->interrupt_ring + rptr,
kfd->device_info->ih_ring_entry_size);
rptr = (rptr + kfd->device_info->ih_ring_entry_size) %
kfd->interrupt_ring_size;
smp_mb();
atomic_set(&kfd->interrupt_ring_rptr, rptr);
return true;
}
static void interrupt_wq(struct work_struct *work)
{
struct kfd_dev *dev = container_of(work, struct kfd_dev,
interrupt_work);
uint32_t ih_ring_entry[DIV_ROUND_UP(
dev->device_info->ih_ring_entry_size,
sizeof(uint32_t))];
while (dequeue_ih_ring_entry(dev, ih_ring_entry))
dev->device_info->event_interrupt_class->interrupt_wq(dev,
ih_ring_entry);
}
bool interrupt_is_wanted(struct kfd_dev *dev, const uint32_t *ih_ring_entry)
{
unsigned int wanted = 0;
wanted |= dev->device_info->event_interrupt_class->interrupt_isr(dev,
ih_ring_entry);
return wanted != 0;
}
