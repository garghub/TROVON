static inline struct kvm_coalesced_mmio_dev *to_mmio(struct kvm_io_device *dev)
{
return container_of(dev, struct kvm_coalesced_mmio_dev, dev);
}
static int coalesced_mmio_in_range(struct kvm_coalesced_mmio_dev *dev,
gpa_t addr, int len)
{
struct kvm_coalesced_mmio_zone *zone;
struct kvm_coalesced_mmio_ring *ring;
unsigned avail;
int i;
ring = dev->kvm->coalesced_mmio_ring;
avail = (ring->first - ring->last - 1) % KVM_COALESCED_MMIO_MAX;
if (avail < KVM_MAX_VCPUS) {
return 0;
}
for (i = 0; i < dev->nb_zones; i++) {
zone = &dev->zone[i];
if (zone->addr <= addr &&
addr + len <= zone->addr + zone->size)
return 1;
}
return 0;
}
static int coalesced_mmio_write(struct kvm_io_device *this,
gpa_t addr, int len, const void *val)
{
struct kvm_coalesced_mmio_dev *dev = to_mmio(this);
struct kvm_coalesced_mmio_ring *ring = dev->kvm->coalesced_mmio_ring;
if (!coalesced_mmio_in_range(dev, addr, len))
return -EOPNOTSUPP;
spin_lock(&dev->lock);
ring->coalesced_mmio[ring->last].phys_addr = addr;
ring->coalesced_mmio[ring->last].len = len;
memcpy(ring->coalesced_mmio[ring->last].data, val, len);
smp_wmb();
ring->last = (ring->last + 1) % KVM_COALESCED_MMIO_MAX;
spin_unlock(&dev->lock);
return 0;
}
static void coalesced_mmio_destructor(struct kvm_io_device *this)
{
struct kvm_coalesced_mmio_dev *dev = to_mmio(this);
kfree(dev);
}
int kvm_coalesced_mmio_init(struct kvm *kvm)
{
struct kvm_coalesced_mmio_dev *dev;
struct page *page;
int ret;
ret = -ENOMEM;
page = alloc_page(GFP_KERNEL | __GFP_ZERO);
if (!page)
goto out_err;
kvm->coalesced_mmio_ring = page_address(page);
ret = -ENOMEM;
dev = kzalloc(sizeof(struct kvm_coalesced_mmio_dev), GFP_KERNEL);
if (!dev)
goto out_free_page;
spin_lock_init(&dev->lock);
kvm_iodevice_init(&dev->dev, &coalesced_mmio_ops);
dev->kvm = kvm;
kvm->coalesced_mmio_dev = dev;
mutex_lock(&kvm->slots_lock);
ret = kvm_io_bus_register_dev(kvm, KVM_MMIO_BUS, &dev->dev);
mutex_unlock(&kvm->slots_lock);
if (ret < 0)
goto out_free_dev;
return ret;
out_free_dev:
kvm->coalesced_mmio_dev = NULL;
kfree(dev);
out_free_page:
kvm->coalesced_mmio_ring = NULL;
__free_page(page);
out_err:
return ret;
}
void kvm_coalesced_mmio_free(struct kvm *kvm)
{
if (kvm->coalesced_mmio_ring)
free_page((unsigned long)kvm->coalesced_mmio_ring);
}
int kvm_vm_ioctl_register_coalesced_mmio(struct kvm *kvm,
struct kvm_coalesced_mmio_zone *zone)
{
struct kvm_coalesced_mmio_dev *dev = kvm->coalesced_mmio_dev;
if (dev == NULL)
return -ENXIO;
mutex_lock(&kvm->slots_lock);
if (dev->nb_zones >= KVM_COALESCED_MMIO_ZONE_MAX) {
mutex_unlock(&kvm->slots_lock);
return -ENOBUFS;
}
dev->zone[dev->nb_zones] = *zone;
dev->nb_zones++;
mutex_unlock(&kvm->slots_lock);
return 0;
}
int kvm_vm_ioctl_unregister_coalesced_mmio(struct kvm *kvm,
struct kvm_coalesced_mmio_zone *zone)
{
int i;
struct kvm_coalesced_mmio_dev *dev = kvm->coalesced_mmio_dev;
struct kvm_coalesced_mmio_zone *z;
if (dev == NULL)
return -ENXIO;
mutex_lock(&kvm->slots_lock);
i = dev->nb_zones;
while (i) {
z = &dev->zone[i - 1];
if (zone->addr <= z->addr &&
z->addr + z->size <= zone->addr + zone->size) {
dev->nb_zones--;
*z = dev->zone[dev->nb_zones];
}
i--;
}
mutex_unlock(&kvm->slots_lock);
return 0;
}
