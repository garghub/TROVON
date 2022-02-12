static void
irqfd_inject(struct work_struct *work)
{
struct kvm_kernel_irqfd *irqfd =
container_of(work, struct kvm_kernel_irqfd, inject);
struct kvm *kvm = irqfd->kvm;
if (!irqfd->resampler) {
kvm_set_irq(kvm, KVM_USERSPACE_IRQ_SOURCE_ID, irqfd->gsi, 1,
false);
kvm_set_irq(kvm, KVM_USERSPACE_IRQ_SOURCE_ID, irqfd->gsi, 0,
false);
} else
kvm_set_irq(kvm, KVM_IRQFD_RESAMPLE_IRQ_SOURCE_ID,
irqfd->gsi, 1, false);
}
static void
irqfd_resampler_ack(struct kvm_irq_ack_notifier *kian)
{
struct kvm_kernel_irqfd_resampler *resampler;
struct kvm *kvm;
struct kvm_kernel_irqfd *irqfd;
int idx;
resampler = container_of(kian,
struct kvm_kernel_irqfd_resampler, notifier);
kvm = resampler->kvm;
kvm_set_irq(kvm, KVM_IRQFD_RESAMPLE_IRQ_SOURCE_ID,
resampler->notifier.gsi, 0, false);
idx = srcu_read_lock(&kvm->irq_srcu);
list_for_each_entry_rcu(irqfd, &resampler->list, resampler_link)
eventfd_signal(irqfd->resamplefd, 1);
srcu_read_unlock(&kvm->irq_srcu, idx);
}
static void
irqfd_resampler_shutdown(struct kvm_kernel_irqfd *irqfd)
{
struct kvm_kernel_irqfd_resampler *resampler = irqfd->resampler;
struct kvm *kvm = resampler->kvm;
mutex_lock(&kvm->irqfds.resampler_lock);
list_del_rcu(&irqfd->resampler_link);
synchronize_srcu(&kvm->irq_srcu);
if (list_empty(&resampler->list)) {
list_del(&resampler->link);
kvm_unregister_irq_ack_notifier(kvm, &resampler->notifier);
kvm_set_irq(kvm, KVM_IRQFD_RESAMPLE_IRQ_SOURCE_ID,
resampler->notifier.gsi, 0, false);
kfree(resampler);
}
mutex_unlock(&kvm->irqfds.resampler_lock);
}
static void
irqfd_shutdown(struct work_struct *work)
{
struct kvm_kernel_irqfd *irqfd =
container_of(work, struct kvm_kernel_irqfd, shutdown);
u64 cnt;
eventfd_ctx_remove_wait_queue(irqfd->eventfd, &irqfd->wait, &cnt);
flush_work(&irqfd->inject);
if (irqfd->resampler) {
irqfd_resampler_shutdown(irqfd);
eventfd_ctx_put(irqfd->resamplefd);
}
#ifdef CONFIG_HAVE_KVM_IRQ_BYPASS
irq_bypass_unregister_consumer(&irqfd->consumer);
#endif
eventfd_ctx_put(irqfd->eventfd);
kfree(irqfd);
}
static bool
irqfd_is_active(struct kvm_kernel_irqfd *irqfd)
{
return list_empty(&irqfd->list) ? false : true;
}
static void
irqfd_deactivate(struct kvm_kernel_irqfd *irqfd)
{
BUG_ON(!irqfd_is_active(irqfd));
list_del_init(&irqfd->list);
queue_work(irqfd_cleanup_wq, &irqfd->shutdown);
}
static int
irqfd_wakeup(wait_queue_entry_t *wait, unsigned mode, int sync, void *key)
{
struct kvm_kernel_irqfd *irqfd =
container_of(wait, struct kvm_kernel_irqfd, wait);
unsigned long flags = (unsigned long)key;
struct kvm_kernel_irq_routing_entry irq;
struct kvm *kvm = irqfd->kvm;
unsigned seq;
int idx;
if (flags & POLLIN) {
idx = srcu_read_lock(&kvm->irq_srcu);
do {
seq = read_seqcount_begin(&irqfd->irq_entry_sc);
irq = irqfd->irq_entry;
} while (read_seqcount_retry(&irqfd->irq_entry_sc, seq));
if (kvm_arch_set_irq_inatomic(&irq, kvm,
KVM_USERSPACE_IRQ_SOURCE_ID, 1,
false) == -EWOULDBLOCK)
schedule_work(&irqfd->inject);
srcu_read_unlock(&kvm->irq_srcu, idx);
}
if (flags & POLLHUP) {
unsigned long flags;
spin_lock_irqsave(&kvm->irqfds.lock, flags);
if (irqfd_is_active(irqfd))
irqfd_deactivate(irqfd);
spin_unlock_irqrestore(&kvm->irqfds.lock, flags);
}
return 0;
}
static void
irqfd_ptable_queue_proc(struct file *file, wait_queue_head_t *wqh,
poll_table *pt)
{
struct kvm_kernel_irqfd *irqfd =
container_of(pt, struct kvm_kernel_irqfd, pt);
add_wait_queue(wqh, &irqfd->wait);
}
static void irqfd_update(struct kvm *kvm, struct kvm_kernel_irqfd *irqfd)
{
struct kvm_kernel_irq_routing_entry *e;
struct kvm_kernel_irq_routing_entry entries[KVM_NR_IRQCHIPS];
int n_entries;
n_entries = kvm_irq_map_gsi(kvm, entries, irqfd->gsi);
write_seqcount_begin(&irqfd->irq_entry_sc);
e = entries;
if (n_entries == 1)
irqfd->irq_entry = *e;
else
irqfd->irq_entry.type = 0;
write_seqcount_end(&irqfd->irq_entry_sc);
}
static int
kvm_irqfd_assign(struct kvm *kvm, struct kvm_irqfd *args)
{
struct kvm_kernel_irqfd *irqfd, *tmp;
struct fd f;
struct eventfd_ctx *eventfd = NULL, *resamplefd = NULL;
int ret;
unsigned int events;
int idx;
if (!kvm_arch_intc_initialized(kvm))
return -EAGAIN;
irqfd = kzalloc(sizeof(*irqfd), GFP_KERNEL);
if (!irqfd)
return -ENOMEM;
irqfd->kvm = kvm;
irqfd->gsi = args->gsi;
INIT_LIST_HEAD(&irqfd->list);
INIT_WORK(&irqfd->inject, irqfd_inject);
INIT_WORK(&irqfd->shutdown, irqfd_shutdown);
seqcount_init(&irqfd->irq_entry_sc);
f = fdget(args->fd);
if (!f.file) {
ret = -EBADF;
goto out;
}
eventfd = eventfd_ctx_fileget(f.file);
if (IS_ERR(eventfd)) {
ret = PTR_ERR(eventfd);
goto fail;
}
irqfd->eventfd = eventfd;
if (args->flags & KVM_IRQFD_FLAG_RESAMPLE) {
struct kvm_kernel_irqfd_resampler *resampler;
resamplefd = eventfd_ctx_fdget(args->resamplefd);
if (IS_ERR(resamplefd)) {
ret = PTR_ERR(resamplefd);
goto fail;
}
irqfd->resamplefd = resamplefd;
INIT_LIST_HEAD(&irqfd->resampler_link);
mutex_lock(&kvm->irqfds.resampler_lock);
list_for_each_entry(resampler,
&kvm->irqfds.resampler_list, link) {
if (resampler->notifier.gsi == irqfd->gsi) {
irqfd->resampler = resampler;
break;
}
}
if (!irqfd->resampler) {
resampler = kzalloc(sizeof(*resampler), GFP_KERNEL);
if (!resampler) {
ret = -ENOMEM;
mutex_unlock(&kvm->irqfds.resampler_lock);
goto fail;
}
resampler->kvm = kvm;
INIT_LIST_HEAD(&resampler->list);
resampler->notifier.gsi = irqfd->gsi;
resampler->notifier.irq_acked = irqfd_resampler_ack;
INIT_LIST_HEAD(&resampler->link);
list_add(&resampler->link, &kvm->irqfds.resampler_list);
kvm_register_irq_ack_notifier(kvm,
&resampler->notifier);
irqfd->resampler = resampler;
}
list_add_rcu(&irqfd->resampler_link, &irqfd->resampler->list);
synchronize_srcu(&kvm->irq_srcu);
mutex_unlock(&kvm->irqfds.resampler_lock);
}
init_waitqueue_func_entry(&irqfd->wait, irqfd_wakeup);
init_poll_funcptr(&irqfd->pt, irqfd_ptable_queue_proc);
spin_lock_irq(&kvm->irqfds.lock);
ret = 0;
list_for_each_entry(tmp, &kvm->irqfds.items, list) {
if (irqfd->eventfd != tmp->eventfd)
continue;
ret = -EBUSY;
spin_unlock_irq(&kvm->irqfds.lock);
goto fail;
}
idx = srcu_read_lock(&kvm->irq_srcu);
irqfd_update(kvm, irqfd);
srcu_read_unlock(&kvm->irq_srcu, idx);
list_add_tail(&irqfd->list, &kvm->irqfds.items);
spin_unlock_irq(&kvm->irqfds.lock);
events = f.file->f_op->poll(f.file, &irqfd->pt);
if (events & POLLIN)
schedule_work(&irqfd->inject);
fdput(f);
#ifdef CONFIG_HAVE_KVM_IRQ_BYPASS
if (kvm_arch_has_irq_bypass()) {
irqfd->consumer.token = (void *)irqfd->eventfd;
irqfd->consumer.add_producer = kvm_arch_irq_bypass_add_producer;
irqfd->consumer.del_producer = kvm_arch_irq_bypass_del_producer;
irqfd->consumer.stop = kvm_arch_irq_bypass_stop;
irqfd->consumer.start = kvm_arch_irq_bypass_start;
ret = irq_bypass_register_consumer(&irqfd->consumer);
if (ret)
pr_info("irq bypass consumer (token %p) registration fails: %d\n",
irqfd->consumer.token, ret);
}
#endif
return 0;
fail:
if (irqfd->resampler)
irqfd_resampler_shutdown(irqfd);
if (resamplefd && !IS_ERR(resamplefd))
eventfd_ctx_put(resamplefd);
if (eventfd && !IS_ERR(eventfd))
eventfd_ctx_put(eventfd);
fdput(f);
out:
kfree(irqfd);
return ret;
}
bool kvm_irq_has_notifier(struct kvm *kvm, unsigned irqchip, unsigned pin)
{
struct kvm_irq_ack_notifier *kian;
int gsi, idx;
idx = srcu_read_lock(&kvm->irq_srcu);
gsi = kvm_irq_map_chip_pin(kvm, irqchip, pin);
if (gsi != -1)
hlist_for_each_entry_rcu(kian, &kvm->irq_ack_notifier_list,
link)
if (kian->gsi == gsi) {
srcu_read_unlock(&kvm->irq_srcu, idx);
return true;
}
srcu_read_unlock(&kvm->irq_srcu, idx);
return false;
}
void kvm_notify_acked_gsi(struct kvm *kvm, int gsi)
{
struct kvm_irq_ack_notifier *kian;
hlist_for_each_entry_rcu(kian, &kvm->irq_ack_notifier_list,
link)
if (kian->gsi == gsi)
kian->irq_acked(kian);
}
void kvm_notify_acked_irq(struct kvm *kvm, unsigned irqchip, unsigned pin)
{
int gsi, idx;
trace_kvm_ack_irq(irqchip, pin);
idx = srcu_read_lock(&kvm->irq_srcu);
gsi = kvm_irq_map_chip_pin(kvm, irqchip, pin);
if (gsi != -1)
kvm_notify_acked_gsi(kvm, gsi);
srcu_read_unlock(&kvm->irq_srcu, idx);
}
void kvm_register_irq_ack_notifier(struct kvm *kvm,
struct kvm_irq_ack_notifier *kian)
{
mutex_lock(&kvm->irq_lock);
hlist_add_head_rcu(&kian->link, &kvm->irq_ack_notifier_list);
mutex_unlock(&kvm->irq_lock);
kvm_arch_post_irq_ack_notifier_list_update(kvm);
}
void kvm_unregister_irq_ack_notifier(struct kvm *kvm,
struct kvm_irq_ack_notifier *kian)
{
mutex_lock(&kvm->irq_lock);
hlist_del_init_rcu(&kian->link);
mutex_unlock(&kvm->irq_lock);
synchronize_srcu(&kvm->irq_srcu);
kvm_arch_post_irq_ack_notifier_list_update(kvm);
}
void
kvm_eventfd_init(struct kvm *kvm)
{
#ifdef CONFIG_HAVE_KVM_IRQFD
spin_lock_init(&kvm->irqfds.lock);
INIT_LIST_HEAD(&kvm->irqfds.items);
INIT_LIST_HEAD(&kvm->irqfds.resampler_list);
mutex_init(&kvm->irqfds.resampler_lock);
#endif
INIT_LIST_HEAD(&kvm->ioeventfds);
}
static int
kvm_irqfd_deassign(struct kvm *kvm, struct kvm_irqfd *args)
{
struct kvm_kernel_irqfd *irqfd, *tmp;
struct eventfd_ctx *eventfd;
eventfd = eventfd_ctx_fdget(args->fd);
if (IS_ERR(eventfd))
return PTR_ERR(eventfd);
spin_lock_irq(&kvm->irqfds.lock);
list_for_each_entry_safe(irqfd, tmp, &kvm->irqfds.items, list) {
if (irqfd->eventfd == eventfd && irqfd->gsi == args->gsi) {
write_seqcount_begin(&irqfd->irq_entry_sc);
irqfd->irq_entry.type = 0;
write_seqcount_end(&irqfd->irq_entry_sc);
irqfd_deactivate(irqfd);
}
}
spin_unlock_irq(&kvm->irqfds.lock);
eventfd_ctx_put(eventfd);
flush_workqueue(irqfd_cleanup_wq);
return 0;
}
int
kvm_irqfd(struct kvm *kvm, struct kvm_irqfd *args)
{
if (args->flags & ~(KVM_IRQFD_FLAG_DEASSIGN | KVM_IRQFD_FLAG_RESAMPLE))
return -EINVAL;
if (args->flags & KVM_IRQFD_FLAG_DEASSIGN)
return kvm_irqfd_deassign(kvm, args);
return kvm_irqfd_assign(kvm, args);
}
void
kvm_irqfd_release(struct kvm *kvm)
{
struct kvm_kernel_irqfd *irqfd, *tmp;
spin_lock_irq(&kvm->irqfds.lock);
list_for_each_entry_safe(irqfd, tmp, &kvm->irqfds.items, list)
irqfd_deactivate(irqfd);
spin_unlock_irq(&kvm->irqfds.lock);
flush_workqueue(irqfd_cleanup_wq);
}
void kvm_irq_routing_update(struct kvm *kvm)
{
struct kvm_kernel_irqfd *irqfd;
spin_lock_irq(&kvm->irqfds.lock);
list_for_each_entry(irqfd, &kvm->irqfds.items, list) {
irqfd_update(kvm, irqfd);
#ifdef CONFIG_HAVE_KVM_IRQ_BYPASS
if (irqfd->producer) {
int ret = kvm_arch_update_irqfd_routing(
irqfd->kvm, irqfd->producer->irq,
irqfd->gsi, 1);
WARN_ON(ret);
}
#endif
}
spin_unlock_irq(&kvm->irqfds.lock);
}
int kvm_irqfd_init(void)
{
irqfd_cleanup_wq = alloc_workqueue("kvm-irqfd-cleanup", 0, 0);
if (!irqfd_cleanup_wq)
return -ENOMEM;
return 0;
}
void kvm_irqfd_exit(void)
{
destroy_workqueue(irqfd_cleanup_wq);
}
static inline struct _ioeventfd *
to_ioeventfd(struct kvm_io_device *dev)
{
return container_of(dev, struct _ioeventfd, dev);
}
static void
ioeventfd_release(struct _ioeventfd *p)
{
eventfd_ctx_put(p->eventfd);
list_del(&p->list);
kfree(p);
}
static bool
ioeventfd_in_range(struct _ioeventfd *p, gpa_t addr, int len, const void *val)
{
u64 _val;
if (addr != p->addr)
return false;
if (!p->length)
return true;
if (len != p->length)
return false;
if (p->wildcard)
return true;
BUG_ON(!IS_ALIGNED((unsigned long)val, len));
switch (len) {
case 1:
_val = *(u8 *)val;
break;
case 2:
_val = *(u16 *)val;
break;
case 4:
_val = *(u32 *)val;
break;
case 8:
_val = *(u64 *)val;
break;
default:
return false;
}
return _val == p->datamatch ? true : false;
}
static int
ioeventfd_write(struct kvm_vcpu *vcpu, struct kvm_io_device *this, gpa_t addr,
int len, const void *val)
{
struct _ioeventfd *p = to_ioeventfd(this);
if (!ioeventfd_in_range(p, addr, len, val))
return -EOPNOTSUPP;
eventfd_signal(p->eventfd, 1);
return 0;
}
static void
ioeventfd_destructor(struct kvm_io_device *this)
{
struct _ioeventfd *p = to_ioeventfd(this);
ioeventfd_release(p);
}
static bool
ioeventfd_check_collision(struct kvm *kvm, struct _ioeventfd *p)
{
struct _ioeventfd *_p;
list_for_each_entry(_p, &kvm->ioeventfds, list)
if (_p->bus_idx == p->bus_idx &&
_p->addr == p->addr &&
(!_p->length || !p->length ||
(_p->length == p->length &&
(_p->wildcard || p->wildcard ||
_p->datamatch == p->datamatch))))
return true;
return false;
}
static enum kvm_bus ioeventfd_bus_from_flags(__u32 flags)
{
if (flags & KVM_IOEVENTFD_FLAG_PIO)
return KVM_PIO_BUS;
if (flags & KVM_IOEVENTFD_FLAG_VIRTIO_CCW_NOTIFY)
return KVM_VIRTIO_CCW_NOTIFY_BUS;
return KVM_MMIO_BUS;
}
static int kvm_assign_ioeventfd_idx(struct kvm *kvm,
enum kvm_bus bus_idx,
struct kvm_ioeventfd *args)
{
struct eventfd_ctx *eventfd;
struct _ioeventfd *p;
int ret;
eventfd = eventfd_ctx_fdget(args->fd);
if (IS_ERR(eventfd))
return PTR_ERR(eventfd);
p = kzalloc(sizeof(*p), GFP_KERNEL);
if (!p) {
ret = -ENOMEM;
goto fail;
}
INIT_LIST_HEAD(&p->list);
p->addr = args->addr;
p->bus_idx = bus_idx;
p->length = args->len;
p->eventfd = eventfd;
if (args->flags & KVM_IOEVENTFD_FLAG_DATAMATCH)
p->datamatch = args->datamatch;
else
p->wildcard = true;
mutex_lock(&kvm->slots_lock);
if (ioeventfd_check_collision(kvm, p)) {
ret = -EEXIST;
goto unlock_fail;
}
kvm_iodevice_init(&p->dev, &ioeventfd_ops);
ret = kvm_io_bus_register_dev(kvm, bus_idx, p->addr, p->length,
&p->dev);
if (ret < 0)
goto unlock_fail;
kvm_get_bus(kvm, bus_idx)->ioeventfd_count++;
list_add_tail(&p->list, &kvm->ioeventfds);
mutex_unlock(&kvm->slots_lock);
return 0;
unlock_fail:
mutex_unlock(&kvm->slots_lock);
fail:
kfree(p);
eventfd_ctx_put(eventfd);
return ret;
}
static int
kvm_deassign_ioeventfd_idx(struct kvm *kvm, enum kvm_bus bus_idx,
struct kvm_ioeventfd *args)
{
struct _ioeventfd *p, *tmp;
struct eventfd_ctx *eventfd;
struct kvm_io_bus *bus;
int ret = -ENOENT;
eventfd = eventfd_ctx_fdget(args->fd);
if (IS_ERR(eventfd))
return PTR_ERR(eventfd);
mutex_lock(&kvm->slots_lock);
list_for_each_entry_safe(p, tmp, &kvm->ioeventfds, list) {
bool wildcard = !(args->flags & KVM_IOEVENTFD_FLAG_DATAMATCH);
if (p->bus_idx != bus_idx ||
p->eventfd != eventfd ||
p->addr != args->addr ||
p->length != args->len ||
p->wildcard != wildcard)
continue;
if (!p->wildcard && p->datamatch != args->datamatch)
continue;
kvm_io_bus_unregister_dev(kvm, bus_idx, &p->dev);
bus = kvm_get_bus(kvm, bus_idx);
if (bus)
bus->ioeventfd_count--;
ioeventfd_release(p);
ret = 0;
break;
}
mutex_unlock(&kvm->slots_lock);
eventfd_ctx_put(eventfd);
return ret;
}
static int kvm_deassign_ioeventfd(struct kvm *kvm, struct kvm_ioeventfd *args)
{
enum kvm_bus bus_idx = ioeventfd_bus_from_flags(args->flags);
int ret = kvm_deassign_ioeventfd_idx(kvm, bus_idx, args);
if (!args->len && bus_idx == KVM_MMIO_BUS)
kvm_deassign_ioeventfd_idx(kvm, KVM_FAST_MMIO_BUS, args);
return ret;
}
static int
kvm_assign_ioeventfd(struct kvm *kvm, struct kvm_ioeventfd *args)
{
enum kvm_bus bus_idx;
int ret;
bus_idx = ioeventfd_bus_from_flags(args->flags);
switch (args->len) {
case 0:
case 1:
case 2:
case 4:
case 8:
break;
default:
return -EINVAL;
}
if (args->addr + args->len < args->addr)
return -EINVAL;
if (args->flags & ~KVM_IOEVENTFD_VALID_FLAG_MASK)
return -EINVAL;
if (!args->len && (args->flags & KVM_IOEVENTFD_FLAG_DATAMATCH))
return -EINVAL;
ret = kvm_assign_ioeventfd_idx(kvm, bus_idx, args);
if (ret)
goto fail;
if (!args->len && bus_idx == KVM_MMIO_BUS) {
ret = kvm_assign_ioeventfd_idx(kvm, KVM_FAST_MMIO_BUS, args);
if (ret < 0)
goto fast_fail;
}
return 0;
fast_fail:
kvm_deassign_ioeventfd_idx(kvm, bus_idx, args);
fail:
return ret;
}
int
kvm_ioeventfd(struct kvm *kvm, struct kvm_ioeventfd *args)
{
if (args->flags & KVM_IOEVENTFD_FLAG_DEASSIGN)
return kvm_deassign_ioeventfd(kvm, args);
return kvm_assign_ioeventfd(kvm, args);
}
