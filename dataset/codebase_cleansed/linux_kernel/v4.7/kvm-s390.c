unsigned long kvm_s390_fac_list_mask_size(void)
{
BUILD_BUG_ON(ARRAY_SIZE(kvm_s390_fac_list_mask) > S390_ARCH_FAC_MASK_SIZE_U64);
return ARRAY_SIZE(kvm_s390_fac_list_mask);
}
int kvm_arch_hardware_enable(void)
{
return 0;
}
static int kvm_clock_sync(struct notifier_block *notifier, unsigned long val,
void *v)
{
struct kvm *kvm;
struct kvm_vcpu *vcpu;
int i;
unsigned long long *delta = v;
list_for_each_entry(kvm, &vm_list, vm_list) {
kvm->arch.epoch -= *delta;
kvm_for_each_vcpu(i, vcpu, kvm) {
vcpu->arch.sie_block->epoch -= *delta;
if (vcpu->arch.cputm_enabled)
vcpu->arch.cputm_start += *delta;
}
}
return NOTIFY_OK;
}
int kvm_arch_hardware_setup(void)
{
gmap_notifier.notifier_call = kvm_gmap_notifier;
gmap_register_ipte_notifier(&gmap_notifier);
atomic_notifier_chain_register(&s390_epoch_delta_notifier,
&kvm_clock_notifier);
return 0;
}
void kvm_arch_hardware_unsetup(void)
{
gmap_unregister_ipte_notifier(&gmap_notifier);
atomic_notifier_chain_unregister(&s390_epoch_delta_notifier,
&kvm_clock_notifier);
}
int kvm_arch_init(void *opaque)
{
kvm_s390_dbf = debug_register("kvm-trace", 32, 1, 7 * sizeof(long));
if (!kvm_s390_dbf)
return -ENOMEM;
if (debug_register_view(kvm_s390_dbf, &debug_sprintf_view)) {
debug_unregister(kvm_s390_dbf);
return -ENOMEM;
}
return kvm_register_device_ops(&kvm_flic_ops, KVM_DEV_TYPE_FLIC);
}
void kvm_arch_exit(void)
{
debug_unregister(kvm_s390_dbf);
}
long kvm_arch_dev_ioctl(struct file *filp,
unsigned int ioctl, unsigned long arg)
{
if (ioctl == KVM_S390_ENABLE_SIE)
return s390_enable_sie();
return -EINVAL;
}
int kvm_vm_ioctl_check_extension(struct kvm *kvm, long ext)
{
int r;
switch (ext) {
case KVM_CAP_S390_PSW:
case KVM_CAP_S390_GMAP:
case KVM_CAP_SYNC_MMU:
#ifdef CONFIG_KVM_S390_UCONTROL
case KVM_CAP_S390_UCONTROL:
#endif
case KVM_CAP_ASYNC_PF:
case KVM_CAP_SYNC_REGS:
case KVM_CAP_ONE_REG:
case KVM_CAP_ENABLE_CAP:
case KVM_CAP_S390_CSS_SUPPORT:
case KVM_CAP_IOEVENTFD:
case KVM_CAP_DEVICE_CTRL:
case KVM_CAP_ENABLE_CAP_VM:
case KVM_CAP_S390_IRQCHIP:
case KVM_CAP_VM_ATTRIBUTES:
case KVM_CAP_MP_STATE:
case KVM_CAP_S390_INJECT_IRQ:
case KVM_CAP_S390_USER_SIGP:
case KVM_CAP_S390_USER_STSI:
case KVM_CAP_S390_SKEYS:
case KVM_CAP_S390_IRQ_STATE:
r = 1;
break;
case KVM_CAP_S390_MEM_OP:
r = MEM_OP_MAX_SIZE;
break;
case KVM_CAP_NR_VCPUS:
case KVM_CAP_MAX_VCPUS:
r = sclp.has_esca ? KVM_S390_ESCA_CPU_SLOTS
: KVM_S390_BSCA_CPU_SLOTS;
break;
case KVM_CAP_NR_MEMSLOTS:
r = KVM_USER_MEM_SLOTS;
break;
case KVM_CAP_S390_COW:
r = MACHINE_HAS_ESOP;
break;
case KVM_CAP_S390_VECTOR_REGISTERS:
r = MACHINE_HAS_VX;
break;
case KVM_CAP_S390_RI:
r = test_facility(64);
break;
default:
r = 0;
}
return r;
}
static void kvm_s390_sync_dirty_log(struct kvm *kvm,
struct kvm_memory_slot *memslot)
{
gfn_t cur_gfn, last_gfn;
unsigned long address;
struct gmap *gmap = kvm->arch.gmap;
last_gfn = memslot->base_gfn + memslot->npages;
for (cur_gfn = memslot->base_gfn; cur_gfn <= last_gfn; cur_gfn++) {
address = gfn_to_hva_memslot(memslot, cur_gfn);
if (test_and_clear_guest_dirty(gmap->mm, address))
mark_page_dirty(kvm, cur_gfn);
if (fatal_signal_pending(current))
return;
cond_resched();
}
}
int kvm_vm_ioctl_get_dirty_log(struct kvm *kvm,
struct kvm_dirty_log *log)
{
int r;
unsigned long n;
struct kvm_memslots *slots;
struct kvm_memory_slot *memslot;
int is_dirty = 0;
mutex_lock(&kvm->slots_lock);
r = -EINVAL;
if (log->slot >= KVM_USER_MEM_SLOTS)
goto out;
slots = kvm_memslots(kvm);
memslot = id_to_memslot(slots, log->slot);
r = -ENOENT;
if (!memslot->dirty_bitmap)
goto out;
kvm_s390_sync_dirty_log(kvm, memslot);
r = kvm_get_dirty_log(kvm, log, &is_dirty);
if (r)
goto out;
if (is_dirty) {
n = kvm_dirty_bitmap_bytes(memslot);
memset(memslot->dirty_bitmap, 0, n);
}
r = 0;
out:
mutex_unlock(&kvm->slots_lock);
return r;
}
static int kvm_vm_ioctl_enable_cap(struct kvm *kvm, struct kvm_enable_cap *cap)
{
int r;
if (cap->flags)
return -EINVAL;
switch (cap->cap) {
case KVM_CAP_S390_IRQCHIP:
VM_EVENT(kvm, 3, "%s", "ENABLE: CAP_S390_IRQCHIP");
kvm->arch.use_irqchip = 1;
r = 0;
break;
case KVM_CAP_S390_USER_SIGP:
VM_EVENT(kvm, 3, "%s", "ENABLE: CAP_S390_USER_SIGP");
kvm->arch.user_sigp = 1;
r = 0;
break;
case KVM_CAP_S390_VECTOR_REGISTERS:
mutex_lock(&kvm->lock);
if (atomic_read(&kvm->online_vcpus)) {
r = -EBUSY;
} else if (MACHINE_HAS_VX) {
set_kvm_facility(kvm->arch.model.fac_mask, 129);
set_kvm_facility(kvm->arch.model.fac_list, 129);
r = 0;
} else
r = -EINVAL;
mutex_unlock(&kvm->lock);
VM_EVENT(kvm, 3, "ENABLE: CAP_S390_VECTOR_REGISTERS %s",
r ? "(not available)" : "(success)");
break;
case KVM_CAP_S390_RI:
r = -EINVAL;
mutex_lock(&kvm->lock);
if (atomic_read(&kvm->online_vcpus)) {
r = -EBUSY;
} else if (test_facility(64)) {
set_kvm_facility(kvm->arch.model.fac_mask, 64);
set_kvm_facility(kvm->arch.model.fac_list, 64);
r = 0;
}
mutex_unlock(&kvm->lock);
VM_EVENT(kvm, 3, "ENABLE: CAP_S390_RI %s",
r ? "(not available)" : "(success)");
break;
case KVM_CAP_S390_USER_STSI:
VM_EVENT(kvm, 3, "%s", "ENABLE: CAP_S390_USER_STSI");
kvm->arch.user_stsi = 1;
r = 0;
break;
default:
r = -EINVAL;
break;
}
return r;
}
static int kvm_s390_get_mem_control(struct kvm *kvm, struct kvm_device_attr *attr)
{
int ret;
switch (attr->attr) {
case KVM_S390_VM_MEM_LIMIT_SIZE:
ret = 0;
VM_EVENT(kvm, 3, "QUERY: max guest memory: %lu bytes",
kvm->arch.mem_limit);
if (put_user(kvm->arch.mem_limit, (u64 __user *)attr->addr))
ret = -EFAULT;
break;
default:
ret = -ENXIO;
break;
}
return ret;
}
static int kvm_s390_set_mem_control(struct kvm *kvm, struct kvm_device_attr *attr)
{
int ret;
unsigned int idx;
switch (attr->attr) {
case KVM_S390_VM_MEM_ENABLE_CMMA:
ret = -EINVAL;
if (!MACHINE_IS_LPAR || !MACHINE_HAS_EDAT1)
break;
ret = -EBUSY;
VM_EVENT(kvm, 3, "%s", "ENABLE: CMMA support");
mutex_lock(&kvm->lock);
if (atomic_read(&kvm->online_vcpus) == 0) {
kvm->arch.use_cmma = 1;
ret = 0;
}
mutex_unlock(&kvm->lock);
break;
case KVM_S390_VM_MEM_CLR_CMMA:
ret = -EINVAL;
if (!kvm->arch.use_cmma)
break;
VM_EVENT(kvm, 3, "%s", "RESET: CMMA states");
mutex_lock(&kvm->lock);
idx = srcu_read_lock(&kvm->srcu);
s390_reset_cmma(kvm->arch.gmap->mm);
srcu_read_unlock(&kvm->srcu, idx);
mutex_unlock(&kvm->lock);
ret = 0;
break;
case KVM_S390_VM_MEM_LIMIT_SIZE: {
unsigned long new_limit;
if (kvm_is_ucontrol(kvm))
return -EINVAL;
if (get_user(new_limit, (u64 __user *)attr->addr))
return -EFAULT;
if (kvm->arch.mem_limit != KVM_S390_NO_MEM_LIMIT &&
new_limit > kvm->arch.mem_limit)
return -E2BIG;
if (!new_limit)
return -EINVAL;
if (new_limit != KVM_S390_NO_MEM_LIMIT)
new_limit -= 1;
ret = -EBUSY;
mutex_lock(&kvm->lock);
if (atomic_read(&kvm->online_vcpus) == 0) {
struct gmap *new = gmap_alloc(current->mm, new_limit);
if (!new) {
ret = -ENOMEM;
} else {
gmap_free(kvm->arch.gmap);
new->private = kvm;
kvm->arch.gmap = new;
ret = 0;
}
}
mutex_unlock(&kvm->lock);
VM_EVENT(kvm, 3, "SET: max guest address: %lu", new_limit);
VM_EVENT(kvm, 3, "New guest asce: 0x%pK",
(void *) kvm->arch.gmap->asce);
break;
}
default:
ret = -ENXIO;
break;
}
return ret;
}
static int kvm_s390_vm_set_crypto(struct kvm *kvm, struct kvm_device_attr *attr)
{
struct kvm_vcpu *vcpu;
int i;
if (!test_kvm_facility(kvm, 76))
return -EINVAL;
mutex_lock(&kvm->lock);
switch (attr->attr) {
case KVM_S390_VM_CRYPTO_ENABLE_AES_KW:
get_random_bytes(
kvm->arch.crypto.crycb->aes_wrapping_key_mask,
sizeof(kvm->arch.crypto.crycb->aes_wrapping_key_mask));
kvm->arch.crypto.aes_kw = 1;
VM_EVENT(kvm, 3, "%s", "ENABLE: AES keywrapping support");
break;
case KVM_S390_VM_CRYPTO_ENABLE_DEA_KW:
get_random_bytes(
kvm->arch.crypto.crycb->dea_wrapping_key_mask,
sizeof(kvm->arch.crypto.crycb->dea_wrapping_key_mask));
kvm->arch.crypto.dea_kw = 1;
VM_EVENT(kvm, 3, "%s", "ENABLE: DEA keywrapping support");
break;
case KVM_S390_VM_CRYPTO_DISABLE_AES_KW:
kvm->arch.crypto.aes_kw = 0;
memset(kvm->arch.crypto.crycb->aes_wrapping_key_mask, 0,
sizeof(kvm->arch.crypto.crycb->aes_wrapping_key_mask));
VM_EVENT(kvm, 3, "%s", "DISABLE: AES keywrapping support");
break;
case KVM_S390_VM_CRYPTO_DISABLE_DEA_KW:
kvm->arch.crypto.dea_kw = 0;
memset(kvm->arch.crypto.crycb->dea_wrapping_key_mask, 0,
sizeof(kvm->arch.crypto.crycb->dea_wrapping_key_mask));
VM_EVENT(kvm, 3, "%s", "DISABLE: DEA keywrapping support");
break;
default:
mutex_unlock(&kvm->lock);
return -ENXIO;
}
kvm_for_each_vcpu(i, vcpu, kvm) {
kvm_s390_vcpu_crypto_setup(vcpu);
exit_sie(vcpu);
}
mutex_unlock(&kvm->lock);
return 0;
}
static int kvm_s390_set_tod_high(struct kvm *kvm, struct kvm_device_attr *attr)
{
u8 gtod_high;
if (copy_from_user(&gtod_high, (void __user *)attr->addr,
sizeof(gtod_high)))
return -EFAULT;
if (gtod_high != 0)
return -EINVAL;
VM_EVENT(kvm, 3, "SET: TOD extension: 0x%x", gtod_high);
return 0;
}
static int kvm_s390_set_tod_low(struct kvm *kvm, struct kvm_device_attr *attr)
{
u64 gtod;
if (copy_from_user(&gtod, (void __user *)attr->addr, sizeof(gtod)))
return -EFAULT;
kvm_s390_set_tod_clock(kvm, gtod);
VM_EVENT(kvm, 3, "SET: TOD base: 0x%llx", gtod);
return 0;
}
static int kvm_s390_set_tod(struct kvm *kvm, struct kvm_device_attr *attr)
{
int ret;
if (attr->flags)
return -EINVAL;
switch (attr->attr) {
case KVM_S390_VM_TOD_HIGH:
ret = kvm_s390_set_tod_high(kvm, attr);
break;
case KVM_S390_VM_TOD_LOW:
ret = kvm_s390_set_tod_low(kvm, attr);
break;
default:
ret = -ENXIO;
break;
}
return ret;
}
static int kvm_s390_get_tod_high(struct kvm *kvm, struct kvm_device_attr *attr)
{
u8 gtod_high = 0;
if (copy_to_user((void __user *)attr->addr, &gtod_high,
sizeof(gtod_high)))
return -EFAULT;
VM_EVENT(kvm, 3, "QUERY: TOD extension: 0x%x", gtod_high);
return 0;
}
static int kvm_s390_get_tod_low(struct kvm *kvm, struct kvm_device_attr *attr)
{
u64 gtod;
gtod = kvm_s390_get_tod_clock_fast(kvm);
if (copy_to_user((void __user *)attr->addr, &gtod, sizeof(gtod)))
return -EFAULT;
VM_EVENT(kvm, 3, "QUERY: TOD base: 0x%llx", gtod);
return 0;
}
static int kvm_s390_get_tod(struct kvm *kvm, struct kvm_device_attr *attr)
{
int ret;
if (attr->flags)
return -EINVAL;
switch (attr->attr) {
case KVM_S390_VM_TOD_HIGH:
ret = kvm_s390_get_tod_high(kvm, attr);
break;
case KVM_S390_VM_TOD_LOW:
ret = kvm_s390_get_tod_low(kvm, attr);
break;
default:
ret = -ENXIO;
break;
}
return ret;
}
static int kvm_s390_set_processor(struct kvm *kvm, struct kvm_device_attr *attr)
{
struct kvm_s390_vm_cpu_processor *proc;
u16 lowest_ibc, unblocked_ibc;
int ret = 0;
mutex_lock(&kvm->lock);
if (atomic_read(&kvm->online_vcpus)) {
ret = -EBUSY;
goto out;
}
proc = kzalloc(sizeof(*proc), GFP_KERNEL);
if (!proc) {
ret = -ENOMEM;
goto out;
}
if (!copy_from_user(proc, (void __user *)attr->addr,
sizeof(*proc))) {
kvm->arch.model.cpuid = proc->cpuid;
lowest_ibc = sclp.ibc >> 16 & 0xfff;
unblocked_ibc = sclp.ibc & 0xfff;
if (lowest_ibc && proc->ibc) {
if (proc->ibc > unblocked_ibc)
kvm->arch.model.ibc = unblocked_ibc;
else if (proc->ibc < lowest_ibc)
kvm->arch.model.ibc = lowest_ibc;
else
kvm->arch.model.ibc = proc->ibc;
}
memcpy(kvm->arch.model.fac_list, proc->fac_list,
S390_ARCH_FAC_LIST_SIZE_BYTE);
} else
ret = -EFAULT;
kfree(proc);
out:
mutex_unlock(&kvm->lock);
return ret;
}
static int kvm_s390_set_cpu_model(struct kvm *kvm, struct kvm_device_attr *attr)
{
int ret = -ENXIO;
switch (attr->attr) {
case KVM_S390_VM_CPU_PROCESSOR:
ret = kvm_s390_set_processor(kvm, attr);
break;
}
return ret;
}
static int kvm_s390_get_processor(struct kvm *kvm, struct kvm_device_attr *attr)
{
struct kvm_s390_vm_cpu_processor *proc;
int ret = 0;
proc = kzalloc(sizeof(*proc), GFP_KERNEL);
if (!proc) {
ret = -ENOMEM;
goto out;
}
proc->cpuid = kvm->arch.model.cpuid;
proc->ibc = kvm->arch.model.ibc;
memcpy(&proc->fac_list, kvm->arch.model.fac_list,
S390_ARCH_FAC_LIST_SIZE_BYTE);
if (copy_to_user((void __user *)attr->addr, proc, sizeof(*proc)))
ret = -EFAULT;
kfree(proc);
out:
return ret;
}
static int kvm_s390_get_machine(struct kvm *kvm, struct kvm_device_attr *attr)
{
struct kvm_s390_vm_cpu_machine *mach;
int ret = 0;
mach = kzalloc(sizeof(*mach), GFP_KERNEL);
if (!mach) {
ret = -ENOMEM;
goto out;
}
get_cpu_id((struct cpuid *) &mach->cpuid);
mach->ibc = sclp.ibc;
memcpy(&mach->fac_mask, kvm->arch.model.fac_mask,
S390_ARCH_FAC_LIST_SIZE_BYTE);
memcpy((unsigned long *)&mach->fac_list, S390_lowcore.stfle_fac_list,
S390_ARCH_FAC_LIST_SIZE_BYTE);
if (copy_to_user((void __user *)attr->addr, mach, sizeof(*mach)))
ret = -EFAULT;
kfree(mach);
out:
return ret;
}
static int kvm_s390_get_cpu_model(struct kvm *kvm, struct kvm_device_attr *attr)
{
int ret = -ENXIO;
switch (attr->attr) {
case KVM_S390_VM_CPU_PROCESSOR:
ret = kvm_s390_get_processor(kvm, attr);
break;
case KVM_S390_VM_CPU_MACHINE:
ret = kvm_s390_get_machine(kvm, attr);
break;
}
return ret;
}
static int kvm_s390_vm_set_attr(struct kvm *kvm, struct kvm_device_attr *attr)
{
int ret;
switch (attr->group) {
case KVM_S390_VM_MEM_CTRL:
ret = kvm_s390_set_mem_control(kvm, attr);
break;
case KVM_S390_VM_TOD:
ret = kvm_s390_set_tod(kvm, attr);
break;
case KVM_S390_VM_CPU_MODEL:
ret = kvm_s390_set_cpu_model(kvm, attr);
break;
case KVM_S390_VM_CRYPTO:
ret = kvm_s390_vm_set_crypto(kvm, attr);
break;
default:
ret = -ENXIO;
break;
}
return ret;
}
static int kvm_s390_vm_get_attr(struct kvm *kvm, struct kvm_device_attr *attr)
{
int ret;
switch (attr->group) {
case KVM_S390_VM_MEM_CTRL:
ret = kvm_s390_get_mem_control(kvm, attr);
break;
case KVM_S390_VM_TOD:
ret = kvm_s390_get_tod(kvm, attr);
break;
case KVM_S390_VM_CPU_MODEL:
ret = kvm_s390_get_cpu_model(kvm, attr);
break;
default:
ret = -ENXIO;
break;
}
return ret;
}
static int kvm_s390_vm_has_attr(struct kvm *kvm, struct kvm_device_attr *attr)
{
int ret;
switch (attr->group) {
case KVM_S390_VM_MEM_CTRL:
switch (attr->attr) {
case KVM_S390_VM_MEM_ENABLE_CMMA:
case KVM_S390_VM_MEM_CLR_CMMA:
case KVM_S390_VM_MEM_LIMIT_SIZE:
ret = 0;
break;
default:
ret = -ENXIO;
break;
}
break;
case KVM_S390_VM_TOD:
switch (attr->attr) {
case KVM_S390_VM_TOD_LOW:
case KVM_S390_VM_TOD_HIGH:
ret = 0;
break;
default:
ret = -ENXIO;
break;
}
break;
case KVM_S390_VM_CPU_MODEL:
switch (attr->attr) {
case KVM_S390_VM_CPU_PROCESSOR:
case KVM_S390_VM_CPU_MACHINE:
ret = 0;
break;
default:
ret = -ENXIO;
break;
}
break;
case KVM_S390_VM_CRYPTO:
switch (attr->attr) {
case KVM_S390_VM_CRYPTO_ENABLE_AES_KW:
case KVM_S390_VM_CRYPTO_ENABLE_DEA_KW:
case KVM_S390_VM_CRYPTO_DISABLE_AES_KW:
case KVM_S390_VM_CRYPTO_DISABLE_DEA_KW:
ret = 0;
break;
default:
ret = -ENXIO;
break;
}
break;
default:
ret = -ENXIO;
break;
}
return ret;
}
static long kvm_s390_get_skeys(struct kvm *kvm, struct kvm_s390_skeys *args)
{
uint8_t *keys;
uint64_t hva;
unsigned long curkey;
int i, r = 0;
if (args->flags != 0)
return -EINVAL;
if (!mm_use_skey(current->mm))
return KVM_S390_GET_SKEYS_NONE;
if (args->count < 1 || args->count > KVM_S390_SKEYS_MAX)
return -EINVAL;
keys = kmalloc_array(args->count, sizeof(uint8_t),
GFP_KERNEL | __GFP_NOWARN);
if (!keys)
keys = vmalloc(sizeof(uint8_t) * args->count);
if (!keys)
return -ENOMEM;
for (i = 0; i < args->count; i++) {
hva = gfn_to_hva(kvm, args->start_gfn + i);
if (kvm_is_error_hva(hva)) {
r = -EFAULT;
goto out;
}
curkey = get_guest_storage_key(current->mm, hva);
if (IS_ERR_VALUE(curkey)) {
r = curkey;
goto out;
}
keys[i] = curkey;
}
r = copy_to_user((uint8_t __user *)args->skeydata_addr, keys,
sizeof(uint8_t) * args->count);
if (r)
r = -EFAULT;
out:
kvfree(keys);
return r;
}
static long kvm_s390_set_skeys(struct kvm *kvm, struct kvm_s390_skeys *args)
{
uint8_t *keys;
uint64_t hva;
int i, r = 0;
if (args->flags != 0)
return -EINVAL;
if (args->count < 1 || args->count > KVM_S390_SKEYS_MAX)
return -EINVAL;
keys = kmalloc_array(args->count, sizeof(uint8_t),
GFP_KERNEL | __GFP_NOWARN);
if (!keys)
keys = vmalloc(sizeof(uint8_t) * args->count);
if (!keys)
return -ENOMEM;
r = copy_from_user(keys, (uint8_t __user *)args->skeydata_addr,
sizeof(uint8_t) * args->count);
if (r) {
r = -EFAULT;
goto out;
}
r = s390_enable_skey();
if (r)
goto out;
for (i = 0; i < args->count; i++) {
hva = gfn_to_hva(kvm, args->start_gfn + i);
if (kvm_is_error_hva(hva)) {
r = -EFAULT;
goto out;
}
if (keys[i] & 0x01) {
r = -EINVAL;
goto out;
}
r = set_guest_storage_key(current->mm, hva,
(unsigned long)keys[i], 0);
if (r)
goto out;
}
out:
kvfree(keys);
return r;
}
long kvm_arch_vm_ioctl(struct file *filp,
unsigned int ioctl, unsigned long arg)
{
struct kvm *kvm = filp->private_data;
void __user *argp = (void __user *)arg;
struct kvm_device_attr attr;
int r;
switch (ioctl) {
case KVM_S390_INTERRUPT: {
struct kvm_s390_interrupt s390int;
r = -EFAULT;
if (copy_from_user(&s390int, argp, sizeof(s390int)))
break;
r = kvm_s390_inject_vm(kvm, &s390int);
break;
}
case KVM_ENABLE_CAP: {
struct kvm_enable_cap cap;
r = -EFAULT;
if (copy_from_user(&cap, argp, sizeof(cap)))
break;
r = kvm_vm_ioctl_enable_cap(kvm, &cap);
break;
}
case KVM_CREATE_IRQCHIP: {
struct kvm_irq_routing_entry routing;
r = -EINVAL;
if (kvm->arch.use_irqchip) {
memset(&routing, 0, sizeof(routing));
r = kvm_set_irq_routing(kvm, &routing, 0, 0);
}
break;
}
case KVM_SET_DEVICE_ATTR: {
r = -EFAULT;
if (copy_from_user(&attr, (void __user *)arg, sizeof(attr)))
break;
r = kvm_s390_vm_set_attr(kvm, &attr);
break;
}
case KVM_GET_DEVICE_ATTR: {
r = -EFAULT;
if (copy_from_user(&attr, (void __user *)arg, sizeof(attr)))
break;
r = kvm_s390_vm_get_attr(kvm, &attr);
break;
}
case KVM_HAS_DEVICE_ATTR: {
r = -EFAULT;
if (copy_from_user(&attr, (void __user *)arg, sizeof(attr)))
break;
r = kvm_s390_vm_has_attr(kvm, &attr);
break;
}
case KVM_S390_GET_SKEYS: {
struct kvm_s390_skeys args;
r = -EFAULT;
if (copy_from_user(&args, argp,
sizeof(struct kvm_s390_skeys)))
break;
r = kvm_s390_get_skeys(kvm, &args);
break;
}
case KVM_S390_SET_SKEYS: {
struct kvm_s390_skeys args;
r = -EFAULT;
if (copy_from_user(&args, argp,
sizeof(struct kvm_s390_skeys)))
break;
r = kvm_s390_set_skeys(kvm, &args);
break;
}
default:
r = -ENOTTY;
}
return r;
}
static int kvm_s390_query_ap_config(u8 *config)
{
u32 fcn_code = 0x04000000UL;
u32 cc = 0;
memset(config, 0, 128);
asm volatile(
"lgr 0,%1\n"
"lgr 2,%2\n"
".long 0xb2af0000\n"
"0: ipm %0\n"
"srl %0,28\n"
"1:\n"
EX_TABLE(0b, 1b)
: "+r" (cc)
: "r" (fcn_code), "r" (config)
: "cc", "0", "2", "memory"
);
return cc;
}
static int kvm_s390_apxa_installed(void)
{
u8 config[128];
int cc;
if (test_facility(12)) {
cc = kvm_s390_query_ap_config(config);
if (cc)
pr_err("PQAP(QCI) failed with cc=%d", cc);
else
return config[0] & 0x40;
}
return 0;
}
static void kvm_s390_set_crycb_format(struct kvm *kvm)
{
kvm->arch.crypto.crycbd = (__u32)(unsigned long) kvm->arch.crypto.crycb;
if (kvm_s390_apxa_installed())
kvm->arch.crypto.crycbd |= CRYCB_FORMAT2;
else
kvm->arch.crypto.crycbd |= CRYCB_FORMAT1;
}
static u64 kvm_s390_get_initial_cpuid(void)
{
struct cpuid cpuid;
get_cpu_id(&cpuid);
cpuid.version = 0xff;
return *((u64 *) &cpuid);
}
static void kvm_s390_crypto_init(struct kvm *kvm)
{
if (!test_kvm_facility(kvm, 76))
return;
kvm->arch.crypto.crycb = &kvm->arch.sie_page2->crycb;
kvm_s390_set_crycb_format(kvm);
kvm->arch.crypto.aes_kw = 1;
kvm->arch.crypto.dea_kw = 1;
get_random_bytes(kvm->arch.crypto.crycb->aes_wrapping_key_mask,
sizeof(kvm->arch.crypto.crycb->aes_wrapping_key_mask));
get_random_bytes(kvm->arch.crypto.crycb->dea_wrapping_key_mask,
sizeof(kvm->arch.crypto.crycb->dea_wrapping_key_mask));
}
static void sca_dispose(struct kvm *kvm)
{
if (kvm->arch.use_esca)
free_pages_exact(kvm->arch.sca, sizeof(struct esca_block));
else
free_page((unsigned long)(kvm->arch.sca));
kvm->arch.sca = NULL;
}
int kvm_arch_init_vm(struct kvm *kvm, unsigned long type)
{
int i, rc;
char debug_name[16];
static unsigned long sca_offset;
rc = -EINVAL;
#ifdef CONFIG_KVM_S390_UCONTROL
if (type & ~KVM_VM_S390_UCONTROL)
goto out_err;
if ((type & KVM_VM_S390_UCONTROL) && (!capable(CAP_SYS_ADMIN)))
goto out_err;
#else
if (type)
goto out_err;
#endif
rc = s390_enable_sie();
if (rc)
goto out_err;
rc = -ENOMEM;
kvm->arch.use_esca = 0;
rwlock_init(&kvm->arch.sca_lock);
kvm->arch.sca = (struct bsca_block *) get_zeroed_page(GFP_KERNEL);
if (!kvm->arch.sca)
goto out_err;
spin_lock(&kvm_lock);
sca_offset += 16;
if (sca_offset + sizeof(struct bsca_block) > PAGE_SIZE)
sca_offset = 0;
kvm->arch.sca = (struct bsca_block *)
((char *) kvm->arch.sca + sca_offset);
spin_unlock(&kvm_lock);
sprintf(debug_name, "kvm-%u", current->pid);
kvm->arch.dbf = debug_register(debug_name, 32, 1, 7 * sizeof(long));
if (!kvm->arch.dbf)
goto out_err;
kvm->arch.sie_page2 =
(struct sie_page2 *) get_zeroed_page(GFP_KERNEL | GFP_DMA);
if (!kvm->arch.sie_page2)
goto out_err;
memcpy(kvm->arch.model.fac_mask, S390_lowcore.stfle_fac_list,
S390_ARCH_FAC_LIST_SIZE_BYTE);
for (i = 0; i < S390_ARCH_FAC_LIST_SIZE_U64; i++) {
if (i < kvm_s390_fac_list_mask_size())
kvm->arch.model.fac_mask[i] &= kvm_s390_fac_list_mask[i];
else
kvm->arch.model.fac_mask[i] = 0UL;
}
kvm->arch.model.fac_list = kvm->arch.sie_page2->fac_list;
memcpy(kvm->arch.model.fac_list, kvm->arch.model.fac_mask,
S390_ARCH_FAC_LIST_SIZE_BYTE);
kvm->arch.model.cpuid = kvm_s390_get_initial_cpuid();
kvm->arch.model.ibc = sclp.ibc & 0x0fff;
kvm_s390_crypto_init(kvm);
spin_lock_init(&kvm->arch.float_int.lock);
for (i = 0; i < FIRQ_LIST_COUNT; i++)
INIT_LIST_HEAD(&kvm->arch.float_int.lists[i]);
init_waitqueue_head(&kvm->arch.ipte_wq);
mutex_init(&kvm->arch.ipte_mutex);
debug_register_view(kvm->arch.dbf, &debug_sprintf_view);
VM_EVENT(kvm, 3, "vm created with type %lu", type);
if (type & KVM_VM_S390_UCONTROL) {
kvm->arch.gmap = NULL;
kvm->arch.mem_limit = KVM_S390_NO_MEM_LIMIT;
} else {
if (sclp.hamax == U64_MAX)
kvm->arch.mem_limit = TASK_MAX_SIZE;
else
kvm->arch.mem_limit = min_t(unsigned long, TASK_MAX_SIZE,
sclp.hamax + 1);
kvm->arch.gmap = gmap_alloc(current->mm, kvm->arch.mem_limit - 1);
if (!kvm->arch.gmap)
goto out_err;
kvm->arch.gmap->private = kvm;
kvm->arch.gmap->pfault_enabled = 0;
}
kvm->arch.css_support = 0;
kvm->arch.use_irqchip = 0;
kvm->arch.epoch = 0;
spin_lock_init(&kvm->arch.start_stop_lock);
KVM_EVENT(3, "vm 0x%pK created by pid %u", kvm, current->pid);
return 0;
out_err:
free_page((unsigned long)kvm->arch.sie_page2);
debug_unregister(kvm->arch.dbf);
sca_dispose(kvm);
KVM_EVENT(3, "creation of vm failed: %d", rc);
return rc;
}
void kvm_arch_vcpu_destroy(struct kvm_vcpu *vcpu)
{
VCPU_EVENT(vcpu, 3, "%s", "free cpu");
trace_kvm_s390_destroy_vcpu(vcpu->vcpu_id);
kvm_s390_clear_local_irqs(vcpu);
kvm_clear_async_pf_completion_queue(vcpu);
if (!kvm_is_ucontrol(vcpu->kvm))
sca_del_vcpu(vcpu);
if (kvm_is_ucontrol(vcpu->kvm))
gmap_free(vcpu->arch.gmap);
if (vcpu->kvm->arch.use_cmma)
kvm_s390_vcpu_unsetup_cmma(vcpu);
free_page((unsigned long)(vcpu->arch.sie_block));
kvm_vcpu_uninit(vcpu);
kmem_cache_free(kvm_vcpu_cache, vcpu);
}
static void kvm_free_vcpus(struct kvm *kvm)
{
unsigned int i;
struct kvm_vcpu *vcpu;
kvm_for_each_vcpu(i, vcpu, kvm)
kvm_arch_vcpu_destroy(vcpu);
mutex_lock(&kvm->lock);
for (i = 0; i < atomic_read(&kvm->online_vcpus); i++)
kvm->vcpus[i] = NULL;
atomic_set(&kvm->online_vcpus, 0);
mutex_unlock(&kvm->lock);
}
void kvm_arch_destroy_vm(struct kvm *kvm)
{
kvm_free_vcpus(kvm);
sca_dispose(kvm);
debug_unregister(kvm->arch.dbf);
free_page((unsigned long)kvm->arch.sie_page2);
if (!kvm_is_ucontrol(kvm))
gmap_free(kvm->arch.gmap);
kvm_s390_destroy_adapters(kvm);
kvm_s390_clear_float_irqs(kvm);
KVM_EVENT(3, "vm 0x%pK destroyed", kvm);
}
static int __kvm_ucontrol_vcpu_init(struct kvm_vcpu *vcpu)
{
vcpu->arch.gmap = gmap_alloc(current->mm, -1UL);
if (!vcpu->arch.gmap)
return -ENOMEM;
vcpu->arch.gmap->private = vcpu->kvm;
return 0;
}
static void sca_del_vcpu(struct kvm_vcpu *vcpu)
{
read_lock(&vcpu->kvm->arch.sca_lock);
if (vcpu->kvm->arch.use_esca) {
struct esca_block *sca = vcpu->kvm->arch.sca;
clear_bit_inv(vcpu->vcpu_id, (unsigned long *) sca->mcn);
sca->cpu[vcpu->vcpu_id].sda = 0;
} else {
struct bsca_block *sca = vcpu->kvm->arch.sca;
clear_bit_inv(vcpu->vcpu_id, (unsigned long *) &sca->mcn);
sca->cpu[vcpu->vcpu_id].sda = 0;
}
read_unlock(&vcpu->kvm->arch.sca_lock);
}
static void sca_add_vcpu(struct kvm_vcpu *vcpu)
{
read_lock(&vcpu->kvm->arch.sca_lock);
if (vcpu->kvm->arch.use_esca) {
struct esca_block *sca = vcpu->kvm->arch.sca;
sca->cpu[vcpu->vcpu_id].sda = (__u64) vcpu->arch.sie_block;
vcpu->arch.sie_block->scaoh = (__u32)(((__u64)sca) >> 32);
vcpu->arch.sie_block->scaol = (__u32)(__u64)sca & ~0x3fU;
vcpu->arch.sie_block->ecb2 |= 0x04U;
set_bit_inv(vcpu->vcpu_id, (unsigned long *) sca->mcn);
} else {
struct bsca_block *sca = vcpu->kvm->arch.sca;
sca->cpu[vcpu->vcpu_id].sda = (__u64) vcpu->arch.sie_block;
vcpu->arch.sie_block->scaoh = (__u32)(((__u64)sca) >> 32);
vcpu->arch.sie_block->scaol = (__u32)(__u64)sca;
set_bit_inv(vcpu->vcpu_id, (unsigned long *) &sca->mcn);
}
read_unlock(&vcpu->kvm->arch.sca_lock);
}
static inline void sca_copy_entry(struct esca_entry *d, struct bsca_entry *s)
{
d->sda = s->sda;
d->sigp_ctrl.c = s->sigp_ctrl.c;
d->sigp_ctrl.scn = s->sigp_ctrl.scn;
}
static void sca_copy_b_to_e(struct esca_block *d, struct bsca_block *s)
{
int i;
d->ipte_control = s->ipte_control;
d->mcn[0] = s->mcn;
for (i = 0; i < KVM_S390_BSCA_CPU_SLOTS; i++)
sca_copy_entry(&d->cpu[i], &s->cpu[i]);
}
static int sca_switch_to_extended(struct kvm *kvm)
{
struct bsca_block *old_sca = kvm->arch.sca;
struct esca_block *new_sca;
struct kvm_vcpu *vcpu;
unsigned int vcpu_idx;
u32 scaol, scaoh;
new_sca = alloc_pages_exact(sizeof(*new_sca), GFP_KERNEL|__GFP_ZERO);
if (!new_sca)
return -ENOMEM;
scaoh = (u32)((u64)(new_sca) >> 32);
scaol = (u32)(u64)(new_sca) & ~0x3fU;
kvm_s390_vcpu_block_all(kvm);
write_lock(&kvm->arch.sca_lock);
sca_copy_b_to_e(new_sca, old_sca);
kvm_for_each_vcpu(vcpu_idx, vcpu, kvm) {
vcpu->arch.sie_block->scaoh = scaoh;
vcpu->arch.sie_block->scaol = scaol;
vcpu->arch.sie_block->ecb2 |= 0x04U;
}
kvm->arch.sca = new_sca;
kvm->arch.use_esca = 1;
write_unlock(&kvm->arch.sca_lock);
kvm_s390_vcpu_unblock_all(kvm);
free_page((unsigned long)old_sca);
VM_EVENT(kvm, 2, "Switched to ESCA (0x%pK -> 0x%pK)",
old_sca, kvm->arch.sca);
return 0;
}
static int sca_can_add_vcpu(struct kvm *kvm, unsigned int id)
{
int rc;
if (id < KVM_S390_BSCA_CPU_SLOTS)
return true;
if (!sclp.has_esca)
return false;
mutex_lock(&kvm->lock);
rc = kvm->arch.use_esca ? 0 : sca_switch_to_extended(kvm);
mutex_unlock(&kvm->lock);
return rc == 0 && id < KVM_S390_ESCA_CPU_SLOTS;
}
int kvm_arch_vcpu_init(struct kvm_vcpu *vcpu)
{
vcpu->arch.pfault_token = KVM_S390_PFAULT_TOKEN_INVALID;
kvm_clear_async_pf_completion_queue(vcpu);
vcpu->run->kvm_valid_regs = KVM_SYNC_PREFIX |
KVM_SYNC_GPRS |
KVM_SYNC_ACRS |
KVM_SYNC_CRS |
KVM_SYNC_ARCH0 |
KVM_SYNC_PFAULT;
if (test_kvm_facility(vcpu->kvm, 64))
vcpu->run->kvm_valid_regs |= KVM_SYNC_RICCB;
if (MACHINE_HAS_VX)
vcpu->run->kvm_valid_regs |= KVM_SYNC_VRS;
else
vcpu->run->kvm_valid_regs |= KVM_SYNC_FPRS;
if (kvm_is_ucontrol(vcpu->kvm))
return __kvm_ucontrol_vcpu_init(vcpu);
return 0;
}
static void __start_cpu_timer_accounting(struct kvm_vcpu *vcpu)
{
WARN_ON_ONCE(vcpu->arch.cputm_start != 0);
raw_write_seqcount_begin(&vcpu->arch.cputm_seqcount);
vcpu->arch.cputm_start = get_tod_clock_fast();
raw_write_seqcount_end(&vcpu->arch.cputm_seqcount);
}
static void __stop_cpu_timer_accounting(struct kvm_vcpu *vcpu)
{
WARN_ON_ONCE(vcpu->arch.cputm_start == 0);
raw_write_seqcount_begin(&vcpu->arch.cputm_seqcount);
vcpu->arch.sie_block->cputm -= get_tod_clock_fast() - vcpu->arch.cputm_start;
vcpu->arch.cputm_start = 0;
raw_write_seqcount_end(&vcpu->arch.cputm_seqcount);
}
static void __enable_cpu_timer_accounting(struct kvm_vcpu *vcpu)
{
WARN_ON_ONCE(vcpu->arch.cputm_enabled);
vcpu->arch.cputm_enabled = true;
__start_cpu_timer_accounting(vcpu);
}
static void __disable_cpu_timer_accounting(struct kvm_vcpu *vcpu)
{
WARN_ON_ONCE(!vcpu->arch.cputm_enabled);
__stop_cpu_timer_accounting(vcpu);
vcpu->arch.cputm_enabled = false;
}
static void enable_cpu_timer_accounting(struct kvm_vcpu *vcpu)
{
preempt_disable();
__enable_cpu_timer_accounting(vcpu);
preempt_enable();
}
static void disable_cpu_timer_accounting(struct kvm_vcpu *vcpu)
{
preempt_disable();
__disable_cpu_timer_accounting(vcpu);
preempt_enable();
}
void kvm_s390_set_cpu_timer(struct kvm_vcpu *vcpu, __u64 cputm)
{
preempt_disable();
raw_write_seqcount_begin(&vcpu->arch.cputm_seqcount);
if (vcpu->arch.cputm_enabled)
vcpu->arch.cputm_start = get_tod_clock_fast();
vcpu->arch.sie_block->cputm = cputm;
raw_write_seqcount_end(&vcpu->arch.cputm_seqcount);
preempt_enable();
}
__u64 kvm_s390_get_cpu_timer(struct kvm_vcpu *vcpu)
{
unsigned int seq;
__u64 value;
if (unlikely(!vcpu->arch.cputm_enabled))
return vcpu->arch.sie_block->cputm;
preempt_disable();
do {
seq = raw_read_seqcount(&vcpu->arch.cputm_seqcount);
WARN_ON_ONCE((seq & 1) && smp_processor_id() == vcpu->cpu);
value = vcpu->arch.sie_block->cputm;
if (likely(vcpu->arch.cputm_start))
value -= get_tod_clock_fast() - vcpu->arch.cputm_start;
} while (read_seqcount_retry(&vcpu->arch.cputm_seqcount, seq & ~1));
preempt_enable();
return value;
}
void kvm_arch_vcpu_load(struct kvm_vcpu *vcpu, int cpu)
{
save_fpu_regs();
vcpu->arch.host_fpregs.fpc = current->thread.fpu.fpc;
vcpu->arch.host_fpregs.regs = current->thread.fpu.regs;
if (MACHINE_HAS_VX)
current->thread.fpu.regs = vcpu->run->s.regs.vrs;
else
current->thread.fpu.regs = vcpu->run->s.regs.fprs;
current->thread.fpu.fpc = vcpu->run->s.regs.fpc;
if (test_fp_ctl(current->thread.fpu.fpc))
current->thread.fpu.fpc = 0;
save_access_regs(vcpu->arch.host_acrs);
restore_access_regs(vcpu->run->s.regs.acrs);
gmap_enable(vcpu->arch.gmap);
atomic_or(CPUSTAT_RUNNING, &vcpu->arch.sie_block->cpuflags);
if (vcpu->arch.cputm_enabled && !is_vcpu_idle(vcpu))
__start_cpu_timer_accounting(vcpu);
vcpu->cpu = cpu;
}
void kvm_arch_vcpu_put(struct kvm_vcpu *vcpu)
{
vcpu->cpu = -1;
if (vcpu->arch.cputm_enabled && !is_vcpu_idle(vcpu))
__stop_cpu_timer_accounting(vcpu);
atomic_andnot(CPUSTAT_RUNNING, &vcpu->arch.sie_block->cpuflags);
gmap_disable(vcpu->arch.gmap);
save_fpu_regs();
vcpu->run->s.regs.fpc = current->thread.fpu.fpc;
current->thread.fpu.fpc = vcpu->arch.host_fpregs.fpc;
current->thread.fpu.regs = vcpu->arch.host_fpregs.regs;
save_access_regs(vcpu->run->s.regs.acrs);
restore_access_regs(vcpu->arch.host_acrs);
}
static void kvm_s390_vcpu_initial_reset(struct kvm_vcpu *vcpu)
{
vcpu->arch.sie_block->gpsw.mask = 0UL;
vcpu->arch.sie_block->gpsw.addr = 0UL;
kvm_s390_set_prefix(vcpu, 0);
kvm_s390_set_cpu_timer(vcpu, 0);
vcpu->arch.sie_block->ckc = 0UL;
vcpu->arch.sie_block->todpr = 0;
memset(vcpu->arch.sie_block->gcr, 0, 16 * sizeof(__u64));
vcpu->arch.sie_block->gcr[0] = 0xE0UL;
vcpu->arch.sie_block->gcr[14] = 0xC2000000UL;
save_fpu_regs();
current->thread.fpu.fpc = 0;
vcpu->arch.sie_block->gbea = 1;
vcpu->arch.sie_block->pp = 0;
vcpu->arch.pfault_token = KVM_S390_PFAULT_TOKEN_INVALID;
kvm_clear_async_pf_completion_queue(vcpu);
if (!kvm_s390_user_cpu_state_ctrl(vcpu->kvm))
kvm_s390_vcpu_stop(vcpu);
kvm_s390_clear_local_irqs(vcpu);
}
void kvm_arch_vcpu_postcreate(struct kvm_vcpu *vcpu)
{
mutex_lock(&vcpu->kvm->lock);
preempt_disable();
vcpu->arch.sie_block->epoch = vcpu->kvm->arch.epoch;
preempt_enable();
mutex_unlock(&vcpu->kvm->lock);
if (!kvm_is_ucontrol(vcpu->kvm)) {
vcpu->arch.gmap = vcpu->kvm->arch.gmap;
sca_add_vcpu(vcpu);
}
}
static void kvm_s390_vcpu_crypto_setup(struct kvm_vcpu *vcpu)
{
if (!test_kvm_facility(vcpu->kvm, 76))
return;
vcpu->arch.sie_block->ecb3 &= ~(ECB3_AES | ECB3_DEA);
if (vcpu->kvm->arch.crypto.aes_kw)
vcpu->arch.sie_block->ecb3 |= ECB3_AES;
if (vcpu->kvm->arch.crypto.dea_kw)
vcpu->arch.sie_block->ecb3 |= ECB3_DEA;
vcpu->arch.sie_block->crycbd = vcpu->kvm->arch.crypto.crycbd;
}
void kvm_s390_vcpu_unsetup_cmma(struct kvm_vcpu *vcpu)
{
free_page(vcpu->arch.sie_block->cbrlo);
vcpu->arch.sie_block->cbrlo = 0;
}
int kvm_s390_vcpu_setup_cmma(struct kvm_vcpu *vcpu)
{
vcpu->arch.sie_block->cbrlo = get_zeroed_page(GFP_KERNEL);
if (!vcpu->arch.sie_block->cbrlo)
return -ENOMEM;
vcpu->arch.sie_block->ecb2 |= 0x80;
vcpu->arch.sie_block->ecb2 &= ~0x08;
return 0;
}
static void kvm_s390_vcpu_setup_model(struct kvm_vcpu *vcpu)
{
struct kvm_s390_cpu_model *model = &vcpu->kvm->arch.model;
vcpu->arch.sie_block->ibc = model->ibc;
if (test_kvm_facility(vcpu->kvm, 7))
vcpu->arch.sie_block->fac = (u32)(u64) model->fac_list;
}
int kvm_arch_vcpu_setup(struct kvm_vcpu *vcpu)
{
int rc = 0;
atomic_set(&vcpu->arch.sie_block->cpuflags, CPUSTAT_ZARCH |
CPUSTAT_SM |
CPUSTAT_STOPPED);
if (test_kvm_facility(vcpu->kvm, 78))
atomic_or(CPUSTAT_GED2, &vcpu->arch.sie_block->cpuflags);
else if (test_kvm_facility(vcpu->kvm, 8))
atomic_or(CPUSTAT_GED, &vcpu->arch.sie_block->cpuflags);
kvm_s390_vcpu_setup_model(vcpu);
vcpu->arch.sie_block->ecb = 0x02;
if (test_kvm_facility(vcpu->kvm, 9))
vcpu->arch.sie_block->ecb |= 0x04;
if (test_kvm_facility(vcpu->kvm, 50) && test_kvm_facility(vcpu->kvm, 73))
vcpu->arch.sie_block->ecb |= 0x10;
if (test_kvm_facility(vcpu->kvm, 8))
vcpu->arch.sie_block->ecb2 |= 0x08;
vcpu->arch.sie_block->eca = 0xC1002000U;
if (sclp.has_siif)
vcpu->arch.sie_block->eca |= 1;
if (sclp.has_sigpif)
vcpu->arch.sie_block->eca |= 0x10000000U;
if (test_kvm_facility(vcpu->kvm, 64))
vcpu->arch.sie_block->ecb3 |= 0x01;
if (test_kvm_facility(vcpu->kvm, 129)) {
vcpu->arch.sie_block->eca |= 0x00020000;
vcpu->arch.sie_block->ecd |= 0x20000000;
}
vcpu->arch.sie_block->riccbd = (unsigned long) &vcpu->run->s.regs.riccb;
vcpu->arch.sie_block->ictl |= ICTL_ISKE | ICTL_SSKE | ICTL_RRBE;
if (vcpu->kvm->arch.use_cmma) {
rc = kvm_s390_vcpu_setup_cmma(vcpu);
if (rc)
return rc;
}
hrtimer_init(&vcpu->arch.ckc_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
vcpu->arch.ckc_timer.function = kvm_s390_idle_wakeup;
kvm_s390_vcpu_crypto_setup(vcpu);
return rc;
}
struct kvm_vcpu *kvm_arch_vcpu_create(struct kvm *kvm,
unsigned int id)
{
struct kvm_vcpu *vcpu;
struct sie_page *sie_page;
int rc = -EINVAL;
if (!kvm_is_ucontrol(kvm) && !sca_can_add_vcpu(kvm, id))
goto out;
rc = -ENOMEM;
vcpu = kmem_cache_zalloc(kvm_vcpu_cache, GFP_KERNEL);
if (!vcpu)
goto out;
sie_page = (struct sie_page *) get_zeroed_page(GFP_KERNEL);
if (!sie_page)
goto out_free_cpu;
vcpu->arch.sie_block = &sie_page->sie_block;
vcpu->arch.sie_block->itdba = (unsigned long) &sie_page->itdb;
vcpu->arch.sie_block->icpua = id;
spin_lock_init(&vcpu->arch.local_int.lock);
vcpu->arch.local_int.float_int = &kvm->arch.float_int;
vcpu->arch.local_int.wq = &vcpu->wq;
vcpu->arch.local_int.cpuflags = &vcpu->arch.sie_block->cpuflags;
seqcount_init(&vcpu->arch.cputm_seqcount);
rc = kvm_vcpu_init(vcpu, kvm, id);
if (rc)
goto out_free_sie_block;
VM_EVENT(kvm, 3, "create cpu %d at 0x%pK, sie block at 0x%pK", id, vcpu,
vcpu->arch.sie_block);
trace_kvm_s390_create_vcpu(id, vcpu, vcpu->arch.sie_block);
return vcpu;
out_free_sie_block:
free_page((unsigned long)(vcpu->arch.sie_block));
out_free_cpu:
kmem_cache_free(kvm_vcpu_cache, vcpu);
out:
return ERR_PTR(rc);
}
int kvm_arch_vcpu_runnable(struct kvm_vcpu *vcpu)
{
return kvm_s390_vcpu_has_irq(vcpu, 0);
}
void kvm_s390_vcpu_block(struct kvm_vcpu *vcpu)
{
atomic_or(PROG_BLOCK_SIE, &vcpu->arch.sie_block->prog20);
exit_sie(vcpu);
}
void kvm_s390_vcpu_unblock(struct kvm_vcpu *vcpu)
{
atomic_andnot(PROG_BLOCK_SIE, &vcpu->arch.sie_block->prog20);
}
static void kvm_s390_vcpu_request(struct kvm_vcpu *vcpu)
{
atomic_or(PROG_REQUEST, &vcpu->arch.sie_block->prog20);
exit_sie(vcpu);
}
static void kvm_s390_vcpu_request_handled(struct kvm_vcpu *vcpu)
{
atomic_andnot(PROG_REQUEST, &vcpu->arch.sie_block->prog20);
}
void exit_sie(struct kvm_vcpu *vcpu)
{
atomic_or(CPUSTAT_STOP_INT, &vcpu->arch.sie_block->cpuflags);
while (vcpu->arch.sie_block->prog0c & PROG_IN_SIE)
cpu_relax();
}
void kvm_s390_sync_request(int req, struct kvm_vcpu *vcpu)
{
kvm_make_request(req, vcpu);
kvm_s390_vcpu_request(vcpu);
}
static void kvm_gmap_notifier(struct gmap *gmap, unsigned long address)
{
int i;
struct kvm *kvm = gmap->private;
struct kvm_vcpu *vcpu;
kvm_for_each_vcpu(i, vcpu, kvm) {
if (kvm_s390_get_prefix(vcpu) == (address & ~0x1000UL)) {
VCPU_EVENT(vcpu, 2, "gmap notifier for %lx", address);
kvm_s390_sync_request(KVM_REQ_MMU_RELOAD, vcpu);
}
}
}
int kvm_arch_vcpu_should_kick(struct kvm_vcpu *vcpu)
{
BUG();
return 0;
}
static int kvm_arch_vcpu_ioctl_get_one_reg(struct kvm_vcpu *vcpu,
struct kvm_one_reg *reg)
{
int r = -EINVAL;
switch (reg->id) {
case KVM_REG_S390_TODPR:
r = put_user(vcpu->arch.sie_block->todpr,
(u32 __user *)reg->addr);
break;
case KVM_REG_S390_EPOCHDIFF:
r = put_user(vcpu->arch.sie_block->epoch,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_CPU_TIMER:
r = put_user(kvm_s390_get_cpu_timer(vcpu),
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_CLOCK_COMP:
r = put_user(vcpu->arch.sie_block->ckc,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_PFTOKEN:
r = put_user(vcpu->arch.pfault_token,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_PFCOMPARE:
r = put_user(vcpu->arch.pfault_compare,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_PFSELECT:
r = put_user(vcpu->arch.pfault_select,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_PP:
r = put_user(vcpu->arch.sie_block->pp,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_GBEA:
r = put_user(vcpu->arch.sie_block->gbea,
(u64 __user *)reg->addr);
break;
default:
break;
}
return r;
}
static int kvm_arch_vcpu_ioctl_set_one_reg(struct kvm_vcpu *vcpu,
struct kvm_one_reg *reg)
{
int r = -EINVAL;
__u64 val;
switch (reg->id) {
case KVM_REG_S390_TODPR:
r = get_user(vcpu->arch.sie_block->todpr,
(u32 __user *)reg->addr);
break;
case KVM_REG_S390_EPOCHDIFF:
r = get_user(vcpu->arch.sie_block->epoch,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_CPU_TIMER:
r = get_user(val, (u64 __user *)reg->addr);
if (!r)
kvm_s390_set_cpu_timer(vcpu, val);
break;
case KVM_REG_S390_CLOCK_COMP:
r = get_user(vcpu->arch.sie_block->ckc,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_PFTOKEN:
r = get_user(vcpu->arch.pfault_token,
(u64 __user *)reg->addr);
if (vcpu->arch.pfault_token == KVM_S390_PFAULT_TOKEN_INVALID)
kvm_clear_async_pf_completion_queue(vcpu);
break;
case KVM_REG_S390_PFCOMPARE:
r = get_user(vcpu->arch.pfault_compare,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_PFSELECT:
r = get_user(vcpu->arch.pfault_select,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_PP:
r = get_user(vcpu->arch.sie_block->pp,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_GBEA:
r = get_user(vcpu->arch.sie_block->gbea,
(u64 __user *)reg->addr);
break;
default:
break;
}
return r;
}
static int kvm_arch_vcpu_ioctl_initial_reset(struct kvm_vcpu *vcpu)
{
kvm_s390_vcpu_initial_reset(vcpu);
return 0;
}
int kvm_arch_vcpu_ioctl_set_regs(struct kvm_vcpu *vcpu, struct kvm_regs *regs)
{
memcpy(&vcpu->run->s.regs.gprs, &regs->gprs, sizeof(regs->gprs));
return 0;
}
int kvm_arch_vcpu_ioctl_get_regs(struct kvm_vcpu *vcpu, struct kvm_regs *regs)
{
memcpy(&regs->gprs, &vcpu->run->s.regs.gprs, sizeof(regs->gprs));
return 0;
}
int kvm_arch_vcpu_ioctl_set_sregs(struct kvm_vcpu *vcpu,
struct kvm_sregs *sregs)
{
memcpy(&vcpu->run->s.regs.acrs, &sregs->acrs, sizeof(sregs->acrs));
memcpy(&vcpu->arch.sie_block->gcr, &sregs->crs, sizeof(sregs->crs));
restore_access_regs(vcpu->run->s.regs.acrs);
return 0;
}
int kvm_arch_vcpu_ioctl_get_sregs(struct kvm_vcpu *vcpu,
struct kvm_sregs *sregs)
{
memcpy(&sregs->acrs, &vcpu->run->s.regs.acrs, sizeof(sregs->acrs));
memcpy(&sregs->crs, &vcpu->arch.sie_block->gcr, sizeof(sregs->crs));
return 0;
}
int kvm_arch_vcpu_ioctl_set_fpu(struct kvm_vcpu *vcpu, struct kvm_fpu *fpu)
{
save_fpu_regs();
if (test_fp_ctl(fpu->fpc))
return -EINVAL;
current->thread.fpu.fpc = fpu->fpc;
if (MACHINE_HAS_VX)
convert_fp_to_vx(current->thread.fpu.vxrs, (freg_t *)fpu->fprs);
else
memcpy(current->thread.fpu.fprs, &fpu->fprs, sizeof(fpu->fprs));
return 0;
}
int kvm_arch_vcpu_ioctl_get_fpu(struct kvm_vcpu *vcpu, struct kvm_fpu *fpu)
{
save_fpu_regs();
if (MACHINE_HAS_VX)
convert_vx_to_fp((freg_t *)fpu->fprs, current->thread.fpu.vxrs);
else
memcpy(fpu->fprs, current->thread.fpu.fprs, sizeof(fpu->fprs));
fpu->fpc = current->thread.fpu.fpc;
return 0;
}
static int kvm_arch_vcpu_ioctl_set_initial_psw(struct kvm_vcpu *vcpu, psw_t psw)
{
int rc = 0;
if (!is_vcpu_stopped(vcpu))
rc = -EBUSY;
else {
vcpu->run->psw_mask = psw.mask;
vcpu->run->psw_addr = psw.addr;
}
return rc;
}
int kvm_arch_vcpu_ioctl_translate(struct kvm_vcpu *vcpu,
struct kvm_translation *tr)
{
return -EINVAL;
}
int kvm_arch_vcpu_ioctl_set_guest_debug(struct kvm_vcpu *vcpu,
struct kvm_guest_debug *dbg)
{
int rc = 0;
vcpu->guest_debug = 0;
kvm_s390_clear_bp_data(vcpu);
if (dbg->control & ~VALID_GUESTDBG_FLAGS)
return -EINVAL;
if (dbg->control & KVM_GUESTDBG_ENABLE) {
vcpu->guest_debug = dbg->control;
atomic_or(CPUSTAT_P, &vcpu->arch.sie_block->cpuflags);
if (dbg->control & KVM_GUESTDBG_USE_HW_BP)
rc = kvm_s390_import_bp_data(vcpu, dbg);
} else {
atomic_andnot(CPUSTAT_P, &vcpu->arch.sie_block->cpuflags);
vcpu->arch.guestdbg.last_bp = 0;
}
if (rc) {
vcpu->guest_debug = 0;
kvm_s390_clear_bp_data(vcpu);
atomic_andnot(CPUSTAT_P, &vcpu->arch.sie_block->cpuflags);
}
return rc;
}
int kvm_arch_vcpu_ioctl_get_mpstate(struct kvm_vcpu *vcpu,
struct kvm_mp_state *mp_state)
{
return is_vcpu_stopped(vcpu) ? KVM_MP_STATE_STOPPED :
KVM_MP_STATE_OPERATING;
}
int kvm_arch_vcpu_ioctl_set_mpstate(struct kvm_vcpu *vcpu,
struct kvm_mp_state *mp_state)
{
int rc = 0;
vcpu->kvm->arch.user_cpu_state_ctrl = 1;
switch (mp_state->mp_state) {
case KVM_MP_STATE_STOPPED:
kvm_s390_vcpu_stop(vcpu);
break;
case KVM_MP_STATE_OPERATING:
kvm_s390_vcpu_start(vcpu);
break;
case KVM_MP_STATE_LOAD:
case KVM_MP_STATE_CHECK_STOP:
default:
rc = -ENXIO;
}
return rc;
}
static bool ibs_enabled(struct kvm_vcpu *vcpu)
{
return atomic_read(&vcpu->arch.sie_block->cpuflags) & CPUSTAT_IBS;
}
static int kvm_s390_handle_requests(struct kvm_vcpu *vcpu)
{
retry:
kvm_s390_vcpu_request_handled(vcpu);
if (!vcpu->requests)
return 0;
if (kvm_check_request(KVM_REQ_MMU_RELOAD, vcpu)) {
int rc;
rc = gmap_ipte_notify(vcpu->arch.gmap,
kvm_s390_get_prefix(vcpu),
PAGE_SIZE * 2);
if (rc)
return rc;
goto retry;
}
if (kvm_check_request(KVM_REQ_TLB_FLUSH, vcpu)) {
vcpu->arch.sie_block->ihcpu = 0xffff;
goto retry;
}
if (kvm_check_request(KVM_REQ_ENABLE_IBS, vcpu)) {
if (!ibs_enabled(vcpu)) {
trace_kvm_s390_enable_disable_ibs(vcpu->vcpu_id, 1);
atomic_or(CPUSTAT_IBS,
&vcpu->arch.sie_block->cpuflags);
}
goto retry;
}
if (kvm_check_request(KVM_REQ_DISABLE_IBS, vcpu)) {
if (ibs_enabled(vcpu)) {
trace_kvm_s390_enable_disable_ibs(vcpu->vcpu_id, 0);
atomic_andnot(CPUSTAT_IBS,
&vcpu->arch.sie_block->cpuflags);
}
goto retry;
}
clear_bit(KVM_REQ_UNHALT, &vcpu->requests);
return 0;
}
void kvm_s390_set_tod_clock(struct kvm *kvm, u64 tod)
{
struct kvm_vcpu *vcpu;
int i;
mutex_lock(&kvm->lock);
preempt_disable();
kvm->arch.epoch = tod - get_tod_clock();
kvm_s390_vcpu_block_all(kvm);
kvm_for_each_vcpu(i, vcpu, kvm)
vcpu->arch.sie_block->epoch = kvm->arch.epoch;
kvm_s390_vcpu_unblock_all(kvm);
preempt_enable();
mutex_unlock(&kvm->lock);
}
long kvm_arch_fault_in_page(struct kvm_vcpu *vcpu, gpa_t gpa, int writable)
{
return gmap_fault(vcpu->arch.gmap, gpa,
writable ? FAULT_FLAG_WRITE : 0);
}
static void __kvm_inject_pfault_token(struct kvm_vcpu *vcpu, bool start_token,
unsigned long token)
{
struct kvm_s390_interrupt inti;
struct kvm_s390_irq irq;
if (start_token) {
irq.u.ext.ext_params2 = token;
irq.type = KVM_S390_INT_PFAULT_INIT;
WARN_ON_ONCE(kvm_s390_inject_vcpu(vcpu, &irq));
} else {
inti.type = KVM_S390_INT_PFAULT_DONE;
inti.parm64 = token;
WARN_ON_ONCE(kvm_s390_inject_vm(vcpu->kvm, &inti));
}
}
void kvm_arch_async_page_not_present(struct kvm_vcpu *vcpu,
struct kvm_async_pf *work)
{
trace_kvm_s390_pfault_init(vcpu, work->arch.pfault_token);
__kvm_inject_pfault_token(vcpu, true, work->arch.pfault_token);
}
void kvm_arch_async_page_present(struct kvm_vcpu *vcpu,
struct kvm_async_pf *work)
{
trace_kvm_s390_pfault_done(vcpu, work->arch.pfault_token);
__kvm_inject_pfault_token(vcpu, false, work->arch.pfault_token);
}
void kvm_arch_async_page_ready(struct kvm_vcpu *vcpu,
struct kvm_async_pf *work)
{
}
bool kvm_arch_can_inject_async_page_present(struct kvm_vcpu *vcpu)
{
return true;
}
static int kvm_arch_setup_async_pf(struct kvm_vcpu *vcpu)
{
hva_t hva;
struct kvm_arch_async_pf arch;
int rc;
if (vcpu->arch.pfault_token == KVM_S390_PFAULT_TOKEN_INVALID)
return 0;
if ((vcpu->arch.sie_block->gpsw.mask & vcpu->arch.pfault_select) !=
vcpu->arch.pfault_compare)
return 0;
if (psw_extint_disabled(vcpu))
return 0;
if (kvm_s390_vcpu_has_irq(vcpu, 0))
return 0;
if (!(vcpu->arch.sie_block->gcr[0] & 0x200ul))
return 0;
if (!vcpu->arch.gmap->pfault_enabled)
return 0;
hva = gfn_to_hva(vcpu->kvm, gpa_to_gfn(current->thread.gmap_addr));
hva += current->thread.gmap_addr & ~PAGE_MASK;
if (read_guest_real(vcpu, vcpu->arch.pfault_token, &arch.pfault_token, 8))
return 0;
rc = kvm_setup_async_pf(vcpu, current->thread.gmap_addr, hva, &arch);
return rc;
}
static int vcpu_pre_run(struct kvm_vcpu *vcpu)
{
int rc, cpuflags;
kvm_check_async_pf_completion(vcpu);
vcpu->arch.sie_block->gg14 = vcpu->run->s.regs.gprs[14];
vcpu->arch.sie_block->gg15 = vcpu->run->s.regs.gprs[15];
if (need_resched())
schedule();
if (test_cpu_flag(CIF_MCCK_PENDING))
s390_handle_mcck();
if (!kvm_is_ucontrol(vcpu->kvm)) {
rc = kvm_s390_deliver_pending_interrupts(vcpu);
if (rc)
return rc;
}
rc = kvm_s390_handle_requests(vcpu);
if (rc)
return rc;
if (guestdbg_enabled(vcpu)) {
kvm_s390_backup_guest_per_regs(vcpu);
kvm_s390_patch_guest_per_regs(vcpu);
}
vcpu->arch.sie_block->icptcode = 0;
cpuflags = atomic_read(&vcpu->arch.sie_block->cpuflags);
VCPU_EVENT(vcpu, 6, "entering sie flags %x", cpuflags);
trace_kvm_s390_sie_enter(vcpu, cpuflags);
return 0;
}
static int vcpu_post_run_fault_in_sie(struct kvm_vcpu *vcpu)
{
struct kvm_s390_pgm_info pgm_info = {
.code = PGM_ADDRESSING,
};
u8 opcode, ilen;
int rc;
VCPU_EVENT(vcpu, 3, "%s", "fault in sie instruction");
trace_kvm_s390_sie_fault(vcpu);
rc = read_guest_instr(vcpu, &opcode, 1);
ilen = insn_length(opcode);
if (rc < 0) {
return rc;
} else if (rc) {
pgm_info = vcpu->arch.pgm;
ilen = 4;
}
pgm_info.flags = ilen | KVM_S390_PGM_FLAGS_ILC_VALID;
kvm_s390_forward_psw(vcpu, ilen);
return kvm_s390_inject_prog_irq(vcpu, &pgm_info);
}
static int vcpu_post_run(struct kvm_vcpu *vcpu, int exit_reason)
{
VCPU_EVENT(vcpu, 6, "exit sie icptcode %d",
vcpu->arch.sie_block->icptcode);
trace_kvm_s390_sie_exit(vcpu, vcpu->arch.sie_block->icptcode);
if (guestdbg_enabled(vcpu))
kvm_s390_restore_guest_per_regs(vcpu);
vcpu->run->s.regs.gprs[14] = vcpu->arch.sie_block->gg14;
vcpu->run->s.regs.gprs[15] = vcpu->arch.sie_block->gg15;
if (vcpu->arch.sie_block->icptcode > 0) {
int rc = kvm_handle_sie_intercept(vcpu);
if (rc != -EOPNOTSUPP)
return rc;
vcpu->run->exit_reason = KVM_EXIT_S390_SIEIC;
vcpu->run->s390_sieic.icptcode = vcpu->arch.sie_block->icptcode;
vcpu->run->s390_sieic.ipa = vcpu->arch.sie_block->ipa;
vcpu->run->s390_sieic.ipb = vcpu->arch.sie_block->ipb;
return -EREMOTE;
} else if (exit_reason != -EFAULT) {
vcpu->stat.exit_null++;
return 0;
} else if (kvm_is_ucontrol(vcpu->kvm)) {
vcpu->run->exit_reason = KVM_EXIT_S390_UCONTROL;
vcpu->run->s390_ucontrol.trans_exc_code =
current->thread.gmap_addr;
vcpu->run->s390_ucontrol.pgm_code = 0x10;
return -EREMOTE;
} else if (current->thread.gmap_pfault) {
trace_kvm_s390_major_guest_pfault(vcpu);
current->thread.gmap_pfault = 0;
if (kvm_arch_setup_async_pf(vcpu))
return 0;
return kvm_arch_fault_in_page(vcpu, current->thread.gmap_addr, 1);
}
return vcpu_post_run_fault_in_sie(vcpu);
}
static int __vcpu_run(struct kvm_vcpu *vcpu)
{
int rc, exit_reason;
vcpu->srcu_idx = srcu_read_lock(&vcpu->kvm->srcu);
do {
rc = vcpu_pre_run(vcpu);
if (rc)
break;
srcu_read_unlock(&vcpu->kvm->srcu, vcpu->srcu_idx);
local_irq_disable();
__kvm_guest_enter();
__disable_cpu_timer_accounting(vcpu);
local_irq_enable();
exit_reason = sie64a(vcpu->arch.sie_block,
vcpu->run->s.regs.gprs);
local_irq_disable();
__enable_cpu_timer_accounting(vcpu);
__kvm_guest_exit();
local_irq_enable();
vcpu->srcu_idx = srcu_read_lock(&vcpu->kvm->srcu);
rc = vcpu_post_run(vcpu, exit_reason);
} while (!signal_pending(current) && !guestdbg_exit_pending(vcpu) && !rc);
srcu_read_unlock(&vcpu->kvm->srcu, vcpu->srcu_idx);
return rc;
}
static void sync_regs(struct kvm_vcpu *vcpu, struct kvm_run *kvm_run)
{
vcpu->arch.sie_block->gpsw.mask = kvm_run->psw_mask;
vcpu->arch.sie_block->gpsw.addr = kvm_run->psw_addr;
if (kvm_run->kvm_dirty_regs & KVM_SYNC_PREFIX)
kvm_s390_set_prefix(vcpu, kvm_run->s.regs.prefix);
if (kvm_run->kvm_dirty_regs & KVM_SYNC_CRS) {
memcpy(&vcpu->arch.sie_block->gcr, &kvm_run->s.regs.crs, 128);
kvm_make_request(KVM_REQ_TLB_FLUSH, vcpu);
}
if (kvm_run->kvm_dirty_regs & KVM_SYNC_ARCH0) {
kvm_s390_set_cpu_timer(vcpu, kvm_run->s.regs.cputm);
vcpu->arch.sie_block->ckc = kvm_run->s.regs.ckc;
vcpu->arch.sie_block->todpr = kvm_run->s.regs.todpr;
vcpu->arch.sie_block->pp = kvm_run->s.regs.pp;
vcpu->arch.sie_block->gbea = kvm_run->s.regs.gbea;
}
if (kvm_run->kvm_dirty_regs & KVM_SYNC_PFAULT) {
vcpu->arch.pfault_token = kvm_run->s.regs.pft;
vcpu->arch.pfault_select = kvm_run->s.regs.pfs;
vcpu->arch.pfault_compare = kvm_run->s.regs.pfc;
if (vcpu->arch.pfault_token == KVM_S390_PFAULT_TOKEN_INVALID)
kvm_clear_async_pf_completion_queue(vcpu);
}
kvm_run->kvm_dirty_regs = 0;
}
static void store_regs(struct kvm_vcpu *vcpu, struct kvm_run *kvm_run)
{
kvm_run->psw_mask = vcpu->arch.sie_block->gpsw.mask;
kvm_run->psw_addr = vcpu->arch.sie_block->gpsw.addr;
kvm_run->s.regs.prefix = kvm_s390_get_prefix(vcpu);
memcpy(&kvm_run->s.regs.crs, &vcpu->arch.sie_block->gcr, 128);
kvm_run->s.regs.cputm = kvm_s390_get_cpu_timer(vcpu);
kvm_run->s.regs.ckc = vcpu->arch.sie_block->ckc;
kvm_run->s.regs.todpr = vcpu->arch.sie_block->todpr;
kvm_run->s.regs.pp = vcpu->arch.sie_block->pp;
kvm_run->s.regs.gbea = vcpu->arch.sie_block->gbea;
kvm_run->s.regs.pft = vcpu->arch.pfault_token;
kvm_run->s.regs.pfs = vcpu->arch.pfault_select;
kvm_run->s.regs.pfc = vcpu->arch.pfault_compare;
}
int kvm_arch_vcpu_ioctl_run(struct kvm_vcpu *vcpu, struct kvm_run *kvm_run)
{
int rc;
sigset_t sigsaved;
if (guestdbg_exit_pending(vcpu)) {
kvm_s390_prepare_debug_exit(vcpu);
return 0;
}
if (vcpu->sigset_active)
sigprocmask(SIG_SETMASK, &vcpu->sigset, &sigsaved);
if (!kvm_s390_user_cpu_state_ctrl(vcpu->kvm)) {
kvm_s390_vcpu_start(vcpu);
} else if (is_vcpu_stopped(vcpu)) {
pr_err_ratelimited("can't run stopped vcpu %d\n",
vcpu->vcpu_id);
return -EINVAL;
}
sync_regs(vcpu, kvm_run);
enable_cpu_timer_accounting(vcpu);
might_fault();
rc = __vcpu_run(vcpu);
if (signal_pending(current) && !rc) {
kvm_run->exit_reason = KVM_EXIT_INTR;
rc = -EINTR;
}
if (guestdbg_exit_pending(vcpu) && !rc) {
kvm_s390_prepare_debug_exit(vcpu);
rc = 0;
}
if (rc == -EREMOTE) {
rc = 0;
}
disable_cpu_timer_accounting(vcpu);
store_regs(vcpu, kvm_run);
if (vcpu->sigset_active)
sigprocmask(SIG_SETMASK, &sigsaved, NULL);
vcpu->stat.exit_userspace++;
return rc;
}
int kvm_s390_store_status_unloaded(struct kvm_vcpu *vcpu, unsigned long gpa)
{
unsigned char archmode = 1;
freg_t fprs[NUM_FPRS];
unsigned int px;
u64 clkcomp, cputm;
int rc;
px = kvm_s390_get_prefix(vcpu);
if (gpa == KVM_S390_STORE_STATUS_NOADDR) {
if (write_guest_abs(vcpu, 163, &archmode, 1))
return -EFAULT;
gpa = 0;
} else if (gpa == KVM_S390_STORE_STATUS_PREFIXED) {
if (write_guest_real(vcpu, 163, &archmode, 1))
return -EFAULT;
gpa = px;
} else
gpa -= __LC_FPREGS_SAVE_AREA;
if (MACHINE_HAS_VX) {
convert_vx_to_fp(fprs, (__vector128 *) vcpu->run->s.regs.vrs);
rc = write_guest_abs(vcpu, gpa + __LC_FPREGS_SAVE_AREA,
fprs, 128);
} else {
rc = write_guest_abs(vcpu, gpa + __LC_FPREGS_SAVE_AREA,
vcpu->run->s.regs.fprs, 128);
}
rc |= write_guest_abs(vcpu, gpa + __LC_GPREGS_SAVE_AREA,
vcpu->run->s.regs.gprs, 128);
rc |= write_guest_abs(vcpu, gpa + __LC_PSW_SAVE_AREA,
&vcpu->arch.sie_block->gpsw, 16);
rc |= write_guest_abs(vcpu, gpa + __LC_PREFIX_SAVE_AREA,
&px, 4);
rc |= write_guest_abs(vcpu, gpa + __LC_FP_CREG_SAVE_AREA,
&vcpu->run->s.regs.fpc, 4);
rc |= write_guest_abs(vcpu, gpa + __LC_TOD_PROGREG_SAVE_AREA,
&vcpu->arch.sie_block->todpr, 4);
cputm = kvm_s390_get_cpu_timer(vcpu);
rc |= write_guest_abs(vcpu, gpa + __LC_CPU_TIMER_SAVE_AREA,
&cputm, 8);
clkcomp = vcpu->arch.sie_block->ckc >> 8;
rc |= write_guest_abs(vcpu, gpa + __LC_CLOCK_COMP_SAVE_AREA,
&clkcomp, 8);
rc |= write_guest_abs(vcpu, gpa + __LC_AREGS_SAVE_AREA,
&vcpu->run->s.regs.acrs, 64);
rc |= write_guest_abs(vcpu, gpa + __LC_CREGS_SAVE_AREA,
&vcpu->arch.sie_block->gcr, 128);
return rc ? -EFAULT : 0;
}
int kvm_s390_vcpu_store_status(struct kvm_vcpu *vcpu, unsigned long addr)
{
save_fpu_regs();
vcpu->run->s.regs.fpc = current->thread.fpu.fpc;
save_access_regs(vcpu->run->s.regs.acrs);
return kvm_s390_store_status_unloaded(vcpu, addr);
}
int kvm_s390_store_adtl_status_unloaded(struct kvm_vcpu *vcpu,
unsigned long gpa)
{
if (!(gpa & ~0x3ff))
return 0;
return write_guest_abs(vcpu, gpa & ~0x3ff,
(void *)&vcpu->run->s.regs.vrs, 512);
}
int kvm_s390_vcpu_store_adtl_status(struct kvm_vcpu *vcpu, unsigned long addr)
{
if (!test_kvm_facility(vcpu->kvm, 129))
return 0;
save_fpu_regs();
return kvm_s390_store_adtl_status_unloaded(vcpu, addr);
}
static void __disable_ibs_on_vcpu(struct kvm_vcpu *vcpu)
{
kvm_check_request(KVM_REQ_ENABLE_IBS, vcpu);
kvm_s390_sync_request(KVM_REQ_DISABLE_IBS, vcpu);
}
static void __disable_ibs_on_all_vcpus(struct kvm *kvm)
{
unsigned int i;
struct kvm_vcpu *vcpu;
kvm_for_each_vcpu(i, vcpu, kvm) {
__disable_ibs_on_vcpu(vcpu);
}
}
static void __enable_ibs_on_vcpu(struct kvm_vcpu *vcpu)
{
kvm_check_request(KVM_REQ_DISABLE_IBS, vcpu);
kvm_s390_sync_request(KVM_REQ_ENABLE_IBS, vcpu);
}
void kvm_s390_vcpu_start(struct kvm_vcpu *vcpu)
{
int i, online_vcpus, started_vcpus = 0;
if (!is_vcpu_stopped(vcpu))
return;
trace_kvm_s390_vcpu_start_stop(vcpu->vcpu_id, 1);
spin_lock(&vcpu->kvm->arch.start_stop_lock);
online_vcpus = atomic_read(&vcpu->kvm->online_vcpus);
for (i = 0; i < online_vcpus; i++) {
if (!is_vcpu_stopped(vcpu->kvm->vcpus[i]))
started_vcpus++;
}
if (started_vcpus == 0) {
__enable_ibs_on_vcpu(vcpu);
} else if (started_vcpus == 1) {
__disable_ibs_on_all_vcpus(vcpu->kvm);
}
atomic_andnot(CPUSTAT_STOPPED, &vcpu->arch.sie_block->cpuflags);
kvm_make_request(KVM_REQ_TLB_FLUSH, vcpu);
spin_unlock(&vcpu->kvm->arch.start_stop_lock);
return;
}
void kvm_s390_vcpu_stop(struct kvm_vcpu *vcpu)
{
int i, online_vcpus, started_vcpus = 0;
struct kvm_vcpu *started_vcpu = NULL;
if (is_vcpu_stopped(vcpu))
return;
trace_kvm_s390_vcpu_start_stop(vcpu->vcpu_id, 0);
spin_lock(&vcpu->kvm->arch.start_stop_lock);
online_vcpus = atomic_read(&vcpu->kvm->online_vcpus);
kvm_s390_clear_stop_irq(vcpu);
atomic_or(CPUSTAT_STOPPED, &vcpu->arch.sie_block->cpuflags);
__disable_ibs_on_vcpu(vcpu);
for (i = 0; i < online_vcpus; i++) {
if (!is_vcpu_stopped(vcpu->kvm->vcpus[i])) {
started_vcpus++;
started_vcpu = vcpu->kvm->vcpus[i];
}
}
if (started_vcpus == 1) {
__enable_ibs_on_vcpu(started_vcpu);
}
spin_unlock(&vcpu->kvm->arch.start_stop_lock);
return;
}
static int kvm_vcpu_ioctl_enable_cap(struct kvm_vcpu *vcpu,
struct kvm_enable_cap *cap)
{
int r;
if (cap->flags)
return -EINVAL;
switch (cap->cap) {
case KVM_CAP_S390_CSS_SUPPORT:
if (!vcpu->kvm->arch.css_support) {
vcpu->kvm->arch.css_support = 1;
VM_EVENT(vcpu->kvm, 3, "%s", "ENABLE: CSS support");
trace_kvm_s390_enable_css(vcpu->kvm);
}
r = 0;
break;
default:
r = -EINVAL;
break;
}
return r;
}
static long kvm_s390_guest_mem_op(struct kvm_vcpu *vcpu,
struct kvm_s390_mem_op *mop)
{
void __user *uaddr = (void __user *)mop->buf;
void *tmpbuf = NULL;
int r, srcu_idx;
const u64 supported_flags = KVM_S390_MEMOP_F_INJECT_EXCEPTION
| KVM_S390_MEMOP_F_CHECK_ONLY;
if (mop->flags & ~supported_flags)
return -EINVAL;
if (mop->size > MEM_OP_MAX_SIZE)
return -E2BIG;
if (!(mop->flags & KVM_S390_MEMOP_F_CHECK_ONLY)) {
tmpbuf = vmalloc(mop->size);
if (!tmpbuf)
return -ENOMEM;
}
srcu_idx = srcu_read_lock(&vcpu->kvm->srcu);
switch (mop->op) {
case KVM_S390_MEMOP_LOGICAL_READ:
if (mop->flags & KVM_S390_MEMOP_F_CHECK_ONLY) {
r = check_gva_range(vcpu, mop->gaddr, mop->ar,
mop->size, GACC_FETCH);
break;
}
r = read_guest(vcpu, mop->gaddr, mop->ar, tmpbuf, mop->size);
if (r == 0) {
if (copy_to_user(uaddr, tmpbuf, mop->size))
r = -EFAULT;
}
break;
case KVM_S390_MEMOP_LOGICAL_WRITE:
if (mop->flags & KVM_S390_MEMOP_F_CHECK_ONLY) {
r = check_gva_range(vcpu, mop->gaddr, mop->ar,
mop->size, GACC_STORE);
break;
}
if (copy_from_user(tmpbuf, uaddr, mop->size)) {
r = -EFAULT;
break;
}
r = write_guest(vcpu, mop->gaddr, mop->ar, tmpbuf, mop->size);
break;
default:
r = -EINVAL;
}
srcu_read_unlock(&vcpu->kvm->srcu, srcu_idx);
if (r > 0 && (mop->flags & KVM_S390_MEMOP_F_INJECT_EXCEPTION) != 0)
kvm_s390_inject_prog_irq(vcpu, &vcpu->arch.pgm);
vfree(tmpbuf);
return r;
}
long kvm_arch_vcpu_ioctl(struct file *filp,
unsigned int ioctl, unsigned long arg)
{
struct kvm_vcpu *vcpu = filp->private_data;
void __user *argp = (void __user *)arg;
int idx;
long r;
switch (ioctl) {
case KVM_S390_IRQ: {
struct kvm_s390_irq s390irq;
r = -EFAULT;
if (copy_from_user(&s390irq, argp, sizeof(s390irq)))
break;
r = kvm_s390_inject_vcpu(vcpu, &s390irq);
break;
}
case KVM_S390_INTERRUPT: {
struct kvm_s390_interrupt s390int;
struct kvm_s390_irq s390irq;
r = -EFAULT;
if (copy_from_user(&s390int, argp, sizeof(s390int)))
break;
if (s390int_to_s390irq(&s390int, &s390irq))
return -EINVAL;
r = kvm_s390_inject_vcpu(vcpu, &s390irq);
break;
}
case KVM_S390_STORE_STATUS:
idx = srcu_read_lock(&vcpu->kvm->srcu);
r = kvm_s390_vcpu_store_status(vcpu, arg);
srcu_read_unlock(&vcpu->kvm->srcu, idx);
break;
case KVM_S390_SET_INITIAL_PSW: {
psw_t psw;
r = -EFAULT;
if (copy_from_user(&psw, argp, sizeof(psw)))
break;
r = kvm_arch_vcpu_ioctl_set_initial_psw(vcpu, psw);
break;
}
case KVM_S390_INITIAL_RESET:
r = kvm_arch_vcpu_ioctl_initial_reset(vcpu);
break;
case KVM_SET_ONE_REG:
case KVM_GET_ONE_REG: {
struct kvm_one_reg reg;
r = -EFAULT;
if (copy_from_user(&reg, argp, sizeof(reg)))
break;
if (ioctl == KVM_SET_ONE_REG)
r = kvm_arch_vcpu_ioctl_set_one_reg(vcpu, &reg);
else
r = kvm_arch_vcpu_ioctl_get_one_reg(vcpu, &reg);
break;
}
#ifdef CONFIG_KVM_S390_UCONTROL
case KVM_S390_UCAS_MAP: {
struct kvm_s390_ucas_mapping ucasmap;
if (copy_from_user(&ucasmap, argp, sizeof(ucasmap))) {
r = -EFAULT;
break;
}
if (!kvm_is_ucontrol(vcpu->kvm)) {
r = -EINVAL;
break;
}
r = gmap_map_segment(vcpu->arch.gmap, ucasmap.user_addr,
ucasmap.vcpu_addr, ucasmap.length);
break;
}
case KVM_S390_UCAS_UNMAP: {
struct kvm_s390_ucas_mapping ucasmap;
if (copy_from_user(&ucasmap, argp, sizeof(ucasmap))) {
r = -EFAULT;
break;
}
if (!kvm_is_ucontrol(vcpu->kvm)) {
r = -EINVAL;
break;
}
r = gmap_unmap_segment(vcpu->arch.gmap, ucasmap.vcpu_addr,
ucasmap.length);
break;
}
#endif
case KVM_S390_VCPU_FAULT: {
r = gmap_fault(vcpu->arch.gmap, arg, 0);
break;
}
case KVM_ENABLE_CAP:
{
struct kvm_enable_cap cap;
r = -EFAULT;
if (copy_from_user(&cap, argp, sizeof(cap)))
break;
r = kvm_vcpu_ioctl_enable_cap(vcpu, &cap);
break;
}
case KVM_S390_MEM_OP: {
struct kvm_s390_mem_op mem_op;
if (copy_from_user(&mem_op, argp, sizeof(mem_op)) == 0)
r = kvm_s390_guest_mem_op(vcpu, &mem_op);
else
r = -EFAULT;
break;
}
case KVM_S390_SET_IRQ_STATE: {
struct kvm_s390_irq_state irq_state;
r = -EFAULT;
if (copy_from_user(&irq_state, argp, sizeof(irq_state)))
break;
if (irq_state.len > VCPU_IRQS_MAX_BUF ||
irq_state.len == 0 ||
irq_state.len % sizeof(struct kvm_s390_irq) > 0) {
r = -EINVAL;
break;
}
r = kvm_s390_set_irq_state(vcpu,
(void __user *) irq_state.buf,
irq_state.len);
break;
}
case KVM_S390_GET_IRQ_STATE: {
struct kvm_s390_irq_state irq_state;
r = -EFAULT;
if (copy_from_user(&irq_state, argp, sizeof(irq_state)))
break;
if (irq_state.len == 0) {
r = -EINVAL;
break;
}
r = kvm_s390_get_irq_state(vcpu,
(__u8 __user *) irq_state.buf,
irq_state.len);
break;
}
default:
r = -ENOTTY;
}
return r;
}
int kvm_arch_vcpu_fault(struct kvm_vcpu *vcpu, struct vm_fault *vmf)
{
#ifdef CONFIG_KVM_S390_UCONTROL
if ((vmf->pgoff == KVM_S390_SIE_PAGE_OFFSET)
&& (kvm_is_ucontrol(vcpu->kvm))) {
vmf->page = virt_to_page(vcpu->arch.sie_block);
get_page(vmf->page);
return 0;
}
#endif
return VM_FAULT_SIGBUS;
}
int kvm_arch_create_memslot(struct kvm *kvm, struct kvm_memory_slot *slot,
unsigned long npages)
{
return 0;
}
int kvm_arch_prepare_memory_region(struct kvm *kvm,
struct kvm_memory_slot *memslot,
const struct kvm_userspace_memory_region *mem,
enum kvm_mr_change change)
{
if (mem->userspace_addr & 0xffffful)
return -EINVAL;
if (mem->memory_size & 0xffffful)
return -EINVAL;
if (mem->guest_phys_addr + mem->memory_size > kvm->arch.mem_limit)
return -EINVAL;
return 0;
}
void kvm_arch_commit_memory_region(struct kvm *kvm,
const struct kvm_userspace_memory_region *mem,
const struct kvm_memory_slot *old,
const struct kvm_memory_slot *new,
enum kvm_mr_change change)
{
int rc;
if (old->userspace_addr == mem->userspace_addr &&
old->base_gfn * PAGE_SIZE == mem->guest_phys_addr &&
old->npages * PAGE_SIZE == mem->memory_size)
return;
rc = gmap_map_segment(kvm->arch.gmap, mem->userspace_addr,
mem->guest_phys_addr, mem->memory_size);
if (rc)
pr_warn("failed to commit memory region\n");
return;
}
static inline unsigned long nonhyp_mask(int i)
{
unsigned int nonhyp_fai = (sclp.hmfai << i * 2) >> 30;
return 0x0000ffffffffffffUL >> (nonhyp_fai << 4);
}
void kvm_arch_vcpu_block_finish(struct kvm_vcpu *vcpu)
{
vcpu->valid_wakeup = false;
}
static int __init kvm_s390_init(void)
{
int i;
if (!sclp.has_sief2) {
pr_info("SIE not available\n");
return -ENODEV;
}
for (i = 0; i < 16; i++)
kvm_s390_fac_list_mask[i] |=
S390_lowcore.stfle_fac_list[i] & nonhyp_mask(i);
return kvm_init(NULL, sizeof(struct kvm_vcpu), 0, THIS_MODULE);
}
static void __exit kvm_s390_exit(void)
{
kvm_exit();
}
