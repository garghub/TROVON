static u32 *vgic_bitmap_get_reg(struct vgic_bitmap *x,
int cpuid, u32 offset)
{
offset >>= 2;
if (!offset)
return x->percpu[cpuid].reg + (offset ^ REG_OFFSET_SWIZZLE);
else
return x->shared.reg + ((offset - 1) ^ REG_OFFSET_SWIZZLE);
}
static int vgic_bitmap_get_irq_val(struct vgic_bitmap *x,
int cpuid, int irq)
{
if (irq < VGIC_NR_PRIVATE_IRQS)
return test_bit(irq, x->percpu[cpuid].reg_ul);
return test_bit(irq - VGIC_NR_PRIVATE_IRQS, x->shared.reg_ul);
}
static void vgic_bitmap_set_irq_val(struct vgic_bitmap *x, int cpuid,
int irq, int val)
{
unsigned long *reg;
if (irq < VGIC_NR_PRIVATE_IRQS) {
reg = x->percpu[cpuid].reg_ul;
} else {
reg = x->shared.reg_ul;
irq -= VGIC_NR_PRIVATE_IRQS;
}
if (val)
set_bit(irq, reg);
else
clear_bit(irq, reg);
}
static unsigned long *vgic_bitmap_get_cpu_map(struct vgic_bitmap *x, int cpuid)
{
if (unlikely(cpuid >= VGIC_MAX_CPUS))
return NULL;
return x->percpu[cpuid].reg_ul;
}
static unsigned long *vgic_bitmap_get_shared_map(struct vgic_bitmap *x)
{
return x->shared.reg_ul;
}
static u32 *vgic_bytemap_get_reg(struct vgic_bytemap *x, int cpuid, u32 offset)
{
offset >>= 2;
BUG_ON(offset > (VGIC_NR_IRQS / 4));
if (offset < 8)
return x->percpu[cpuid] + offset;
else
return x->shared + offset - 8;
}
static bool vgic_irq_is_edge(struct kvm_vcpu *vcpu, int irq)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
int irq_val;
irq_val = vgic_bitmap_get_irq_val(&dist->irq_cfg, vcpu->vcpu_id, irq);
return irq_val == VGIC_CFG_EDGE;
}
static int vgic_irq_is_enabled(struct kvm_vcpu *vcpu, int irq)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
return vgic_bitmap_get_irq_val(&dist->irq_enabled, vcpu->vcpu_id, irq);
}
static int vgic_irq_is_active(struct kvm_vcpu *vcpu, int irq)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
return vgic_bitmap_get_irq_val(&dist->irq_active, vcpu->vcpu_id, irq);
}
static void vgic_irq_set_active(struct kvm_vcpu *vcpu, int irq)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
vgic_bitmap_set_irq_val(&dist->irq_active, vcpu->vcpu_id, irq, 1);
}
static void vgic_irq_clear_active(struct kvm_vcpu *vcpu, int irq)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
vgic_bitmap_set_irq_val(&dist->irq_active, vcpu->vcpu_id, irq, 0);
}
static int vgic_dist_irq_is_pending(struct kvm_vcpu *vcpu, int irq)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
return vgic_bitmap_get_irq_val(&dist->irq_state, vcpu->vcpu_id, irq);
}
static void vgic_dist_irq_set(struct kvm_vcpu *vcpu, int irq)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
vgic_bitmap_set_irq_val(&dist->irq_state, vcpu->vcpu_id, irq, 1);
}
static void vgic_dist_irq_clear(struct kvm_vcpu *vcpu, int irq)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
vgic_bitmap_set_irq_val(&dist->irq_state, vcpu->vcpu_id, irq, 0);
}
static void vgic_cpu_irq_set(struct kvm_vcpu *vcpu, int irq)
{
if (irq < VGIC_NR_PRIVATE_IRQS)
set_bit(irq, vcpu->arch.vgic_cpu.pending_percpu);
else
set_bit(irq - VGIC_NR_PRIVATE_IRQS,
vcpu->arch.vgic_cpu.pending_shared);
}
static void vgic_cpu_irq_clear(struct kvm_vcpu *vcpu, int irq)
{
if (irq < VGIC_NR_PRIVATE_IRQS)
clear_bit(irq, vcpu->arch.vgic_cpu.pending_percpu);
else
clear_bit(irq - VGIC_NR_PRIVATE_IRQS,
vcpu->arch.vgic_cpu.pending_shared);
}
static u32 mmio_data_read(struct kvm_exit_mmio *mmio, u32 mask)
{
return le32_to_cpu(*((u32 *)mmio->data)) & mask;
}
static void mmio_data_write(struct kvm_exit_mmio *mmio, u32 mask, u32 value)
{
*((u32 *)mmio->data) = cpu_to_le32(value) & mask;
}
static void vgic_reg_access(struct kvm_exit_mmio *mmio, u32 *reg,
phys_addr_t offset, int mode)
{
int word_offset = (offset & 3) * 8;
u32 mask = (1UL << (mmio->len * 8)) - 1;
u32 regval;
if (reg) {
regval = *reg;
} else {
BUG_ON(mode != (ACCESS_READ_RAZ | ACCESS_WRITE_IGNORED));
regval = 0;
}
if (mmio->is_write) {
u32 data = mmio_data_read(mmio, mask) << word_offset;
switch (ACCESS_WRITE_MASK(mode)) {
case ACCESS_WRITE_IGNORED:
return;
case ACCESS_WRITE_SETBIT:
regval |= data;
break;
case ACCESS_WRITE_CLEARBIT:
regval &= ~data;
break;
case ACCESS_WRITE_VALUE:
regval = (regval & ~(mask << word_offset)) | data;
break;
}
*reg = regval;
} else {
switch (ACCESS_READ_MASK(mode)) {
case ACCESS_READ_RAZ:
regval = 0;
case ACCESS_READ_VALUE:
mmio_data_write(mmio, mask, regval >> word_offset);
}
}
}
static bool handle_mmio_misc(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio, phys_addr_t offset)
{
u32 reg;
u32 word_offset = offset & 3;
switch (offset & ~3) {
case 0:
reg = vcpu->kvm->arch.vgic.enabled;
vgic_reg_access(mmio, &reg, word_offset,
ACCESS_READ_VALUE | ACCESS_WRITE_VALUE);
if (mmio->is_write) {
vcpu->kvm->arch.vgic.enabled = reg & 1;
vgic_update_state(vcpu->kvm);
return true;
}
break;
case 4:
reg = (atomic_read(&vcpu->kvm->online_vcpus) - 1) << 5;
reg |= (VGIC_NR_IRQS >> 5) - 1;
vgic_reg_access(mmio, &reg, word_offset,
ACCESS_READ_VALUE | ACCESS_WRITE_IGNORED);
break;
case 8:
reg = (PRODUCT_ID_KVM << 24) | (IMPLEMENTER_ARM << 0);
vgic_reg_access(mmio, &reg, word_offset,
ACCESS_READ_VALUE | ACCESS_WRITE_IGNORED);
break;
}
return false;
}
static bool handle_mmio_raz_wi(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio, phys_addr_t offset)
{
vgic_reg_access(mmio, NULL, offset,
ACCESS_READ_RAZ | ACCESS_WRITE_IGNORED);
return false;
}
static bool handle_mmio_set_enable_reg(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
u32 *reg = vgic_bitmap_get_reg(&vcpu->kvm->arch.vgic.irq_enabled,
vcpu->vcpu_id, offset);
vgic_reg_access(mmio, reg, offset,
ACCESS_READ_VALUE | ACCESS_WRITE_SETBIT);
if (mmio->is_write) {
vgic_update_state(vcpu->kvm);
return true;
}
return false;
}
static bool handle_mmio_clear_enable_reg(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
u32 *reg = vgic_bitmap_get_reg(&vcpu->kvm->arch.vgic.irq_enabled,
vcpu->vcpu_id, offset);
vgic_reg_access(mmio, reg, offset,
ACCESS_READ_VALUE | ACCESS_WRITE_CLEARBIT);
if (mmio->is_write) {
if (offset < 4)
*reg |= 0xffff;
vgic_retire_disabled_irqs(vcpu);
vgic_update_state(vcpu->kvm);
return true;
}
return false;
}
static bool handle_mmio_set_pending_reg(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
u32 *reg = vgic_bitmap_get_reg(&vcpu->kvm->arch.vgic.irq_state,
vcpu->vcpu_id, offset);
vgic_reg_access(mmio, reg, offset,
ACCESS_READ_VALUE | ACCESS_WRITE_SETBIT);
if (mmio->is_write) {
vgic_update_state(vcpu->kvm);
return true;
}
return false;
}
static bool handle_mmio_clear_pending_reg(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
u32 *reg = vgic_bitmap_get_reg(&vcpu->kvm->arch.vgic.irq_state,
vcpu->vcpu_id, offset);
vgic_reg_access(mmio, reg, offset,
ACCESS_READ_VALUE | ACCESS_WRITE_CLEARBIT);
if (mmio->is_write) {
vgic_update_state(vcpu->kvm);
return true;
}
return false;
}
static bool handle_mmio_priority_reg(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
u32 *reg = vgic_bytemap_get_reg(&vcpu->kvm->arch.vgic.irq_priority,
vcpu->vcpu_id, offset);
vgic_reg_access(mmio, reg, offset,
ACCESS_READ_VALUE | ACCESS_WRITE_VALUE);
return false;
}
static u32 vgic_get_target_reg(struct kvm *kvm, int irq)
{
struct vgic_dist *dist = &kvm->arch.vgic;
int i;
u32 val = 0;
irq -= VGIC_NR_PRIVATE_IRQS;
for (i = 0; i < GICD_IRQS_PER_ITARGETSR; i++)
val |= 1 << (dist->irq_spi_cpu[irq + i] + i * 8);
return val;
}
static void vgic_set_target_reg(struct kvm *kvm, u32 val, int irq)
{
struct vgic_dist *dist = &kvm->arch.vgic;
struct kvm_vcpu *vcpu;
int i, c;
unsigned long *bmap;
u32 target;
irq -= VGIC_NR_PRIVATE_IRQS;
for (i = 0; i < GICD_IRQS_PER_ITARGETSR; i++) {
int shift = i * GICD_CPUTARGETS_BITS;
target = ffs((val >> shift) & 0xffU);
target = target ? (target - 1) : 0;
dist->irq_spi_cpu[irq + i] = target;
kvm_for_each_vcpu(c, vcpu, kvm) {
bmap = vgic_bitmap_get_shared_map(&dist->irq_spi_target[c]);
if (c == target)
set_bit(irq + i, bmap);
else
clear_bit(irq + i, bmap);
}
}
}
static bool handle_mmio_target_reg(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
u32 reg;
if (offset < 32) {
u32 roreg = 1 << vcpu->vcpu_id;
roreg |= roreg << 8;
roreg |= roreg << 16;
vgic_reg_access(mmio, &roreg, offset,
ACCESS_READ_VALUE | ACCESS_WRITE_IGNORED);
return false;
}
reg = vgic_get_target_reg(vcpu->kvm, offset & ~3U);
vgic_reg_access(mmio, &reg, offset,
ACCESS_READ_VALUE | ACCESS_WRITE_VALUE);
if (mmio->is_write) {
vgic_set_target_reg(vcpu->kvm, reg, offset & ~3U);
vgic_update_state(vcpu->kvm);
return true;
}
return false;
}
static u32 vgic_cfg_expand(u16 val)
{
u32 res = 0;
int i;
for (i = 0; i < 16; i++)
res |= ((val >> i) & VGIC_CFG_EDGE) << (2 * i + 1);
return res;
}
static u16 vgic_cfg_compress(u32 val)
{
u16 res = 0;
int i;
for (i = 0; i < 16; i++)
res |= ((val >> (i * 2 + 1)) & VGIC_CFG_EDGE) << i;
return res;
}
static bool handle_mmio_cfg_reg(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio, phys_addr_t offset)
{
u32 val;
u32 *reg;
reg = vgic_bitmap_get_reg(&vcpu->kvm->arch.vgic.irq_cfg,
vcpu->vcpu_id, offset >> 1);
if (offset & 4)
val = *reg >> 16;
else
val = *reg & 0xffff;
val = vgic_cfg_expand(val);
vgic_reg_access(mmio, &val, offset,
ACCESS_READ_VALUE | ACCESS_WRITE_VALUE);
if (mmio->is_write) {
if (offset < 8) {
*reg = ~0U;
return false;
}
val = vgic_cfg_compress(val);
if (offset & 4) {
*reg &= 0xffff;
*reg |= val << 16;
} else {
*reg &= 0xffff << 16;
*reg |= val;
}
}
return false;
}
static bool handle_mmio_sgi_reg(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio, phys_addr_t offset)
{
u32 reg;
vgic_reg_access(mmio, &reg, offset,
ACCESS_READ_RAZ | ACCESS_WRITE_VALUE);
if (mmio->is_write) {
vgic_dispatch_sgi(vcpu, reg);
vgic_update_state(vcpu->kvm);
return true;
}
return false;
}
static void vgic_unqueue_irqs(struct kvm_vcpu *vcpu)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
struct vgic_cpu *vgic_cpu = &vcpu->arch.vgic_cpu;
int vcpu_id = vcpu->vcpu_id;
int i;
for_each_set_bit(i, vgic_cpu->lr_used, vgic_cpu->nr_lr) {
struct vgic_lr lr = vgic_get_lr(vcpu, i);
if ((lr.state & LR_STATE_MASK) == LR_STATE_ACTIVE)
continue;
vgic_dist_irq_set(vcpu, lr.irq);
if (lr.irq < VGIC_NR_SGIS)
dist->irq_sgi_sources[vcpu_id][lr.irq] |= 1 << lr.source;
lr.state &= ~LR_STATE_PENDING;
vgic_set_lr(vcpu, i, lr);
if (!(lr.state & LR_STATE_MASK))
vgic_retire_lr(i, lr.irq, vcpu);
vgic_update_state(vcpu->kvm);
}
}
static bool read_set_clear_sgi_pend_reg(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
int sgi;
int min_sgi = (offset & ~0x3) * 4;
int max_sgi = min_sgi + 3;
int vcpu_id = vcpu->vcpu_id;
u32 reg = 0;
for (sgi = min_sgi; sgi <= max_sgi; sgi++) {
int shift = 8 * (sgi - min_sgi);
reg |= (u32)dist->irq_sgi_sources[vcpu_id][sgi] << shift;
}
mmio_data_write(mmio, ~0, reg);
return false;
}
static bool write_set_clear_sgi_pend_reg(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset, bool set)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
int sgi;
int min_sgi = (offset & ~0x3) * 4;
int max_sgi = min_sgi + 3;
int vcpu_id = vcpu->vcpu_id;
u32 reg;
bool updated = false;
reg = mmio_data_read(mmio, ~0);
for (sgi = min_sgi; sgi <= max_sgi; sgi++) {
u8 mask = reg >> (8 * (sgi - min_sgi));
if (set) {
if ((dist->irq_sgi_sources[vcpu_id][sgi] & mask) != mask)
updated = true;
dist->irq_sgi_sources[vcpu_id][sgi] |= mask;
} else {
if (dist->irq_sgi_sources[vcpu_id][sgi] & mask)
updated = true;
dist->irq_sgi_sources[vcpu_id][sgi] &= ~mask;
}
}
if (updated)
vgic_update_state(vcpu->kvm);
return updated;
}
static bool handle_mmio_sgi_set(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
if (!mmio->is_write)
return read_set_clear_sgi_pend_reg(vcpu, mmio, offset);
else
return write_set_clear_sgi_pend_reg(vcpu, mmio, offset, true);
}
static bool handle_mmio_sgi_clear(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
if (!mmio->is_write)
return read_set_clear_sgi_pend_reg(vcpu, mmio, offset);
else
return write_set_clear_sgi_pend_reg(vcpu, mmio, offset, false);
}
static const
struct mmio_range *find_matching_range(const struct mmio_range *ranges,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
const struct mmio_range *r = ranges;
while (r->len) {
if (offset >= r->base &&
(offset + mmio->len) <= (r->base + r->len))
return r;
r++;
}
return NULL;
}
bool vgic_handle_mmio(struct kvm_vcpu *vcpu, struct kvm_run *run,
struct kvm_exit_mmio *mmio)
{
const struct mmio_range *range;
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
unsigned long base = dist->vgic_dist_base;
bool updated_state;
unsigned long offset;
if (!irqchip_in_kernel(vcpu->kvm) ||
mmio->phys_addr < base ||
(mmio->phys_addr + mmio->len) > (base + KVM_VGIC_V2_DIST_SIZE))
return false;
if (mmio->len > 4) {
kvm_inject_dabt(vcpu, mmio->phys_addr);
return true;
}
offset = mmio->phys_addr - base;
range = find_matching_range(vgic_dist_ranges, mmio, offset);
if (unlikely(!range || !range->handle_mmio)) {
pr_warn("Unhandled access %d %08llx %d\n",
mmio->is_write, mmio->phys_addr, mmio->len);
return false;
}
spin_lock(&vcpu->kvm->arch.vgic.lock);
offset = mmio->phys_addr - range->base - base;
updated_state = range->handle_mmio(vcpu, mmio, offset);
spin_unlock(&vcpu->kvm->arch.vgic.lock);
kvm_prepare_mmio(run, mmio);
kvm_handle_mmio_return(vcpu, run);
if (updated_state)
vgic_kick_vcpus(vcpu->kvm);
return true;
}
static void vgic_dispatch_sgi(struct kvm_vcpu *vcpu, u32 reg)
{
struct kvm *kvm = vcpu->kvm;
struct vgic_dist *dist = &kvm->arch.vgic;
int nrcpus = atomic_read(&kvm->online_vcpus);
u8 target_cpus;
int sgi, mode, c, vcpu_id;
vcpu_id = vcpu->vcpu_id;
sgi = reg & 0xf;
target_cpus = (reg >> 16) & 0xff;
mode = (reg >> 24) & 3;
switch (mode) {
case 0:
if (!target_cpus)
return;
break;
case 1:
target_cpus = ((1 << nrcpus) - 1) & ~(1 << vcpu_id) & 0xff;
break;
case 2:
target_cpus = 1 << vcpu_id;
break;
}
kvm_for_each_vcpu(c, vcpu, kvm) {
if (target_cpus & 1) {
vgic_dist_irq_set(vcpu, sgi);
dist->irq_sgi_sources[c][sgi] |= 1 << vcpu_id;
kvm_debug("SGI%d from CPU%d to CPU%d\n", sgi, vcpu_id, c);
}
target_cpus >>= 1;
}
}
static int compute_pending_for_cpu(struct kvm_vcpu *vcpu)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
unsigned long *pending, *enabled, *pend_percpu, *pend_shared;
unsigned long pending_private, pending_shared;
int vcpu_id;
vcpu_id = vcpu->vcpu_id;
pend_percpu = vcpu->arch.vgic_cpu.pending_percpu;
pend_shared = vcpu->arch.vgic_cpu.pending_shared;
pending = vgic_bitmap_get_cpu_map(&dist->irq_state, vcpu_id);
enabled = vgic_bitmap_get_cpu_map(&dist->irq_enabled, vcpu_id);
bitmap_and(pend_percpu, pending, enabled, VGIC_NR_PRIVATE_IRQS);
pending = vgic_bitmap_get_shared_map(&dist->irq_state);
enabled = vgic_bitmap_get_shared_map(&dist->irq_enabled);
bitmap_and(pend_shared, pending, enabled, VGIC_NR_SHARED_IRQS);
bitmap_and(pend_shared, pend_shared,
vgic_bitmap_get_shared_map(&dist->irq_spi_target[vcpu_id]),
VGIC_NR_SHARED_IRQS);
pending_private = find_first_bit(pend_percpu, VGIC_NR_PRIVATE_IRQS);
pending_shared = find_first_bit(pend_shared, VGIC_NR_SHARED_IRQS);
return (pending_private < VGIC_NR_PRIVATE_IRQS ||
pending_shared < VGIC_NR_SHARED_IRQS);
}
static void vgic_update_state(struct kvm *kvm)
{
struct vgic_dist *dist = &kvm->arch.vgic;
struct kvm_vcpu *vcpu;
int c;
if (!dist->enabled) {
set_bit(0, &dist->irq_pending_on_cpu);
return;
}
kvm_for_each_vcpu(c, vcpu, kvm) {
if (compute_pending_for_cpu(vcpu)) {
pr_debug("CPU%d has pending interrupts\n", c);
set_bit(c, &dist->irq_pending_on_cpu);
}
}
}
static struct vgic_lr vgic_get_lr(const struct kvm_vcpu *vcpu, int lr)
{
return vgic_ops->get_lr(vcpu, lr);
}
static void vgic_set_lr(struct kvm_vcpu *vcpu, int lr,
struct vgic_lr vlr)
{
vgic_ops->set_lr(vcpu, lr, vlr);
}
static void vgic_sync_lr_elrsr(struct kvm_vcpu *vcpu, int lr,
struct vgic_lr vlr)
{
vgic_ops->sync_lr_elrsr(vcpu, lr, vlr);
}
static inline u64 vgic_get_elrsr(struct kvm_vcpu *vcpu)
{
return vgic_ops->get_elrsr(vcpu);
}
static inline u64 vgic_get_eisr(struct kvm_vcpu *vcpu)
{
return vgic_ops->get_eisr(vcpu);
}
static inline u32 vgic_get_interrupt_status(struct kvm_vcpu *vcpu)
{
return vgic_ops->get_interrupt_status(vcpu);
}
static inline void vgic_enable_underflow(struct kvm_vcpu *vcpu)
{
vgic_ops->enable_underflow(vcpu);
}
static inline void vgic_disable_underflow(struct kvm_vcpu *vcpu)
{
vgic_ops->disable_underflow(vcpu);
}
static inline void vgic_get_vmcr(struct kvm_vcpu *vcpu, struct vgic_vmcr *vmcr)
{
vgic_ops->get_vmcr(vcpu, vmcr);
}
static void vgic_set_vmcr(struct kvm_vcpu *vcpu, struct vgic_vmcr *vmcr)
{
vgic_ops->set_vmcr(vcpu, vmcr);
}
static inline void vgic_enable(struct kvm_vcpu *vcpu)
{
vgic_ops->enable(vcpu);
}
static void vgic_retire_lr(int lr_nr, int irq, struct kvm_vcpu *vcpu)
{
struct vgic_cpu *vgic_cpu = &vcpu->arch.vgic_cpu;
struct vgic_lr vlr = vgic_get_lr(vcpu, lr_nr);
vlr.state = 0;
vgic_set_lr(vcpu, lr_nr, vlr);
clear_bit(lr_nr, vgic_cpu->lr_used);
vgic_cpu->vgic_irq_lr_map[irq] = LR_EMPTY;
}
static void vgic_retire_disabled_irqs(struct kvm_vcpu *vcpu)
{
struct vgic_cpu *vgic_cpu = &vcpu->arch.vgic_cpu;
int lr;
for_each_set_bit(lr, vgic_cpu->lr_used, vgic->nr_lr) {
struct vgic_lr vlr = vgic_get_lr(vcpu, lr);
if (!vgic_irq_is_enabled(vcpu, vlr.irq)) {
vgic_retire_lr(lr, vlr.irq, vcpu);
if (vgic_irq_is_active(vcpu, vlr.irq))
vgic_irq_clear_active(vcpu, vlr.irq);
}
}
}
static bool vgic_queue_irq(struct kvm_vcpu *vcpu, u8 sgi_source_id, int irq)
{
struct vgic_cpu *vgic_cpu = &vcpu->arch.vgic_cpu;
struct vgic_lr vlr;
int lr;
BUG_ON(sgi_source_id & ~7);
BUG_ON(sgi_source_id && irq >= VGIC_NR_SGIS);
BUG_ON(irq >= VGIC_NR_IRQS);
kvm_debug("Queue IRQ%d\n", irq);
lr = vgic_cpu->vgic_irq_lr_map[irq];
if (lr != LR_EMPTY) {
vlr = vgic_get_lr(vcpu, lr);
if (vlr.source == sgi_source_id) {
kvm_debug("LR%d piggyback for IRQ%d\n", lr, vlr.irq);
BUG_ON(!test_bit(lr, vgic_cpu->lr_used));
vlr.state |= LR_STATE_PENDING;
vgic_set_lr(vcpu, lr, vlr);
return true;
}
}
lr = find_first_zero_bit((unsigned long *)vgic_cpu->lr_used,
vgic->nr_lr);
if (lr >= vgic->nr_lr)
return false;
kvm_debug("LR%d allocated for IRQ%d %x\n", lr, irq, sgi_source_id);
vgic_cpu->vgic_irq_lr_map[irq] = lr;
set_bit(lr, vgic_cpu->lr_used);
vlr.irq = irq;
vlr.source = sgi_source_id;
vlr.state = LR_STATE_PENDING;
if (!vgic_irq_is_edge(vcpu, irq))
vlr.state |= LR_EOI_INT;
vgic_set_lr(vcpu, lr, vlr);
return true;
}
static bool vgic_queue_sgi(struct kvm_vcpu *vcpu, int irq)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
unsigned long sources;
int vcpu_id = vcpu->vcpu_id;
int c;
sources = dist->irq_sgi_sources[vcpu_id][irq];
for_each_set_bit(c, &sources, VGIC_MAX_CPUS) {
if (vgic_queue_irq(vcpu, c, irq))
clear_bit(c, &sources);
}
dist->irq_sgi_sources[vcpu_id][irq] = sources;
if (!sources) {
vgic_dist_irq_clear(vcpu, irq);
vgic_cpu_irq_clear(vcpu, irq);
return true;
}
return false;
}
static bool vgic_queue_hwirq(struct kvm_vcpu *vcpu, int irq)
{
if (vgic_irq_is_active(vcpu, irq))
return true;
if (vgic_queue_irq(vcpu, 0, irq)) {
if (vgic_irq_is_edge(vcpu, irq)) {
vgic_dist_irq_clear(vcpu, irq);
vgic_cpu_irq_clear(vcpu, irq);
} else {
vgic_irq_set_active(vcpu, irq);
}
return true;
}
return false;
}
static void __kvm_vgic_flush_hwstate(struct kvm_vcpu *vcpu)
{
struct vgic_cpu *vgic_cpu = &vcpu->arch.vgic_cpu;
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
int i, vcpu_id;
int overflow = 0;
vcpu_id = vcpu->vcpu_id;
if (!kvm_vgic_vcpu_pending_irq(vcpu)) {
pr_debug("CPU%d has no pending interrupt\n", vcpu_id);
goto epilog;
}
for_each_set_bit(i, vgic_cpu->pending_percpu, VGIC_NR_SGIS) {
if (!vgic_queue_sgi(vcpu, i))
overflow = 1;
}
for_each_set_bit_from(i, vgic_cpu->pending_percpu, VGIC_NR_PRIVATE_IRQS) {
if (!vgic_queue_hwirq(vcpu, i))
overflow = 1;
}
for_each_set_bit(i, vgic_cpu->pending_shared, VGIC_NR_SHARED_IRQS) {
if (!vgic_queue_hwirq(vcpu, i + VGIC_NR_PRIVATE_IRQS))
overflow = 1;
}
epilog:
if (overflow) {
vgic_enable_underflow(vcpu);
} else {
vgic_disable_underflow(vcpu);
clear_bit(vcpu_id, &dist->irq_pending_on_cpu);
}
}
static bool vgic_process_maintenance(struct kvm_vcpu *vcpu)
{
u32 status = vgic_get_interrupt_status(vcpu);
bool level_pending = false;
kvm_debug("STATUS = %08x\n", status);
if (status & INT_STATUS_EOI) {
u64 eisr = vgic_get_eisr(vcpu);
unsigned long *eisr_ptr = (unsigned long *)&eisr;
int lr;
for_each_set_bit(lr, eisr_ptr, vgic->nr_lr) {
struct vgic_lr vlr = vgic_get_lr(vcpu, lr);
vgic_irq_clear_active(vcpu, vlr.irq);
WARN_ON(vlr.state & LR_STATE_MASK);
vlr.state = 0;
vgic_set_lr(vcpu, lr, vlr);
if (vgic_dist_irq_is_pending(vcpu, vlr.irq)) {
vgic_cpu_irq_set(vcpu, vlr.irq);
level_pending = true;
} else {
vgic_cpu_irq_clear(vcpu, vlr.irq);
}
vgic_sync_lr_elrsr(vcpu, lr, vlr);
}
}
if (status & INT_STATUS_UNDERFLOW)
vgic_disable_underflow(vcpu);
return level_pending;
}
static void __kvm_vgic_sync_hwstate(struct kvm_vcpu *vcpu)
{
struct vgic_cpu *vgic_cpu = &vcpu->arch.vgic_cpu;
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
u64 elrsr;
unsigned long *elrsr_ptr;
int lr, pending;
bool level_pending;
level_pending = vgic_process_maintenance(vcpu);
elrsr = vgic_get_elrsr(vcpu);
elrsr_ptr = (unsigned long *)&elrsr;
for_each_set_bit(lr, elrsr_ptr, vgic->nr_lr) {
struct vgic_lr vlr;
if (!test_and_clear_bit(lr, vgic_cpu->lr_used))
continue;
vlr = vgic_get_lr(vcpu, lr);
BUG_ON(vlr.irq >= VGIC_NR_IRQS);
vgic_cpu->vgic_irq_lr_map[vlr.irq] = LR_EMPTY;
}
pending = find_first_zero_bit(elrsr_ptr, vgic->nr_lr);
if (level_pending || pending < vgic->nr_lr)
set_bit(vcpu->vcpu_id, &dist->irq_pending_on_cpu);
}
void kvm_vgic_flush_hwstate(struct kvm_vcpu *vcpu)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
if (!irqchip_in_kernel(vcpu->kvm))
return;
spin_lock(&dist->lock);
__kvm_vgic_flush_hwstate(vcpu);
spin_unlock(&dist->lock);
}
void kvm_vgic_sync_hwstate(struct kvm_vcpu *vcpu)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
if (!irqchip_in_kernel(vcpu->kvm))
return;
spin_lock(&dist->lock);
__kvm_vgic_sync_hwstate(vcpu);
spin_unlock(&dist->lock);
}
int kvm_vgic_vcpu_pending_irq(struct kvm_vcpu *vcpu)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
if (!irqchip_in_kernel(vcpu->kvm))
return 0;
return test_bit(vcpu->vcpu_id, &dist->irq_pending_on_cpu);
}
static void vgic_kick_vcpus(struct kvm *kvm)
{
struct kvm_vcpu *vcpu;
int c;
kvm_for_each_vcpu(c, vcpu, kvm) {
if (kvm_vgic_vcpu_pending_irq(vcpu))
kvm_vcpu_kick(vcpu);
}
}
static int vgic_validate_injection(struct kvm_vcpu *vcpu, int irq, int level)
{
int is_edge = vgic_irq_is_edge(vcpu, irq);
int state = vgic_dist_irq_is_pending(vcpu, irq);
if (is_edge)
return level > state;
else
return level != state;
}
static bool vgic_update_irq_state(struct kvm *kvm, int cpuid,
unsigned int irq_num, bool level)
{
struct vgic_dist *dist = &kvm->arch.vgic;
struct kvm_vcpu *vcpu;
int is_edge, is_level;
int enabled;
bool ret = true;
spin_lock(&dist->lock);
vcpu = kvm_get_vcpu(kvm, cpuid);
is_edge = vgic_irq_is_edge(vcpu, irq_num);
is_level = !is_edge;
if (!vgic_validate_injection(vcpu, irq_num, level)) {
ret = false;
goto out;
}
if (irq_num >= VGIC_NR_PRIVATE_IRQS) {
cpuid = dist->irq_spi_cpu[irq_num - VGIC_NR_PRIVATE_IRQS];
vcpu = kvm_get_vcpu(kvm, cpuid);
}
kvm_debug("Inject IRQ%d level %d CPU%d\n", irq_num, level, cpuid);
if (level)
vgic_dist_irq_set(vcpu, irq_num);
else
vgic_dist_irq_clear(vcpu, irq_num);
enabled = vgic_irq_is_enabled(vcpu, irq_num);
if (!enabled) {
ret = false;
goto out;
}
if (is_level && vgic_irq_is_active(vcpu, irq_num)) {
ret = false;
goto out;
}
if (level) {
vgic_cpu_irq_set(vcpu, irq_num);
set_bit(cpuid, &dist->irq_pending_on_cpu);
}
out:
spin_unlock(&dist->lock);
return ret;
}
int kvm_vgic_inject_irq(struct kvm *kvm, int cpuid, unsigned int irq_num,
bool level)
{
if (vgic_update_irq_state(kvm, cpuid, irq_num, level))
vgic_kick_vcpus(kvm);
return 0;
}
static irqreturn_t vgic_maintenance_handler(int irq, void *data)
{
return IRQ_HANDLED;
}
int kvm_vgic_vcpu_init(struct kvm_vcpu *vcpu)
{
struct vgic_cpu *vgic_cpu = &vcpu->arch.vgic_cpu;
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
int i;
if (vcpu->vcpu_id >= VGIC_MAX_CPUS)
return -EBUSY;
for (i = 0; i < VGIC_NR_IRQS; i++) {
if (i < VGIC_NR_PPIS)
vgic_bitmap_set_irq_val(&dist->irq_enabled,
vcpu->vcpu_id, i, 1);
if (i < VGIC_NR_PRIVATE_IRQS)
vgic_bitmap_set_irq_val(&dist->irq_cfg,
vcpu->vcpu_id, i, VGIC_CFG_EDGE);
vgic_cpu->vgic_irq_lr_map[i] = LR_EMPTY;
}
vgic_cpu->nr_lr = vgic->nr_lr;
vgic_enable(vcpu);
return 0;
}
static void vgic_init_maintenance_interrupt(void *info)
{
enable_percpu_irq(vgic->maint_irq, 0);
}
static int vgic_cpu_notify(struct notifier_block *self,
unsigned long action, void *cpu)
{
switch (action) {
case CPU_STARTING:
case CPU_STARTING_FROZEN:
vgic_init_maintenance_interrupt(NULL);
break;
case CPU_DYING:
case CPU_DYING_FROZEN:
disable_percpu_irq(vgic->maint_irq);
break;
}
return NOTIFY_OK;
}
int kvm_vgic_hyp_init(void)
{
const struct of_device_id *matched_id;
int (*vgic_probe)(struct device_node *,const struct vgic_ops **,
const struct vgic_params **);
struct device_node *vgic_node;
int ret;
vgic_node = of_find_matching_node_and_match(NULL,
vgic_ids, &matched_id);
if (!vgic_node) {
kvm_err("error: no compatible GIC node found\n");
return -ENODEV;
}
vgic_probe = matched_id->data;
ret = vgic_probe(vgic_node, &vgic_ops, &vgic);
if (ret)
return ret;
ret = request_percpu_irq(vgic->maint_irq, vgic_maintenance_handler,
"vgic", kvm_get_running_vcpus());
if (ret) {
kvm_err("Cannot register interrupt %d\n", vgic->maint_irq);
return ret;
}
ret = __register_cpu_notifier(&vgic_cpu_nb);
if (ret) {
kvm_err("Cannot register vgic CPU notifier\n");
goto out_free_irq;
}
vgic_arch_setup(vgic);
on_each_cpu(vgic_init_maintenance_interrupt, NULL, 1);
return 0;
out_free_irq:
free_percpu_irq(vgic->maint_irq, kvm_get_running_vcpus());
return ret;
}
int kvm_vgic_init(struct kvm *kvm)
{
int ret = 0, i;
if (!irqchip_in_kernel(kvm))
return 0;
mutex_lock(&kvm->lock);
if (vgic_initialized(kvm))
goto out;
if (IS_VGIC_ADDR_UNDEF(kvm->arch.vgic.vgic_dist_base) ||
IS_VGIC_ADDR_UNDEF(kvm->arch.vgic.vgic_cpu_base)) {
kvm_err("Need to set vgic cpu and dist addresses first\n");
ret = -ENXIO;
goto out;
}
ret = kvm_phys_addr_ioremap(kvm, kvm->arch.vgic.vgic_cpu_base,
vgic->vcpu_base, KVM_VGIC_V2_CPU_SIZE);
if (ret) {
kvm_err("Unable to remap VGIC CPU to VCPU\n");
goto out;
}
for (i = VGIC_NR_PRIVATE_IRQS; i < VGIC_NR_IRQS; i += 4)
vgic_set_target_reg(kvm, 0, i);
kvm->arch.vgic.ready = true;
out:
mutex_unlock(&kvm->lock);
return ret;
}
int kvm_vgic_create(struct kvm *kvm)
{
int i, vcpu_lock_idx = -1, ret = 0;
struct kvm_vcpu *vcpu;
mutex_lock(&kvm->lock);
if (kvm->arch.vgic.vctrl_base) {
ret = -EEXIST;
goto out;
}
kvm_for_each_vcpu(i, vcpu, kvm) {
if (!mutex_trylock(&vcpu->mutex))
goto out_unlock;
vcpu_lock_idx = i;
}
kvm_for_each_vcpu(i, vcpu, kvm) {
if (vcpu->arch.has_run_once) {
ret = -EBUSY;
goto out_unlock;
}
}
spin_lock_init(&kvm->arch.vgic.lock);
kvm->arch.vgic.in_kernel = true;
kvm->arch.vgic.vctrl_base = vgic->vctrl_base;
kvm->arch.vgic.vgic_dist_base = VGIC_ADDR_UNDEF;
kvm->arch.vgic.vgic_cpu_base = VGIC_ADDR_UNDEF;
out_unlock:
for (; vcpu_lock_idx >= 0; vcpu_lock_idx--) {
vcpu = kvm_get_vcpu(kvm, vcpu_lock_idx);
mutex_unlock(&vcpu->mutex);
}
out:
mutex_unlock(&kvm->lock);
return ret;
}
static bool vgic_ioaddr_overlap(struct kvm *kvm)
{
phys_addr_t dist = kvm->arch.vgic.vgic_dist_base;
phys_addr_t cpu = kvm->arch.vgic.vgic_cpu_base;
if (IS_VGIC_ADDR_UNDEF(dist) || IS_VGIC_ADDR_UNDEF(cpu))
return 0;
if ((dist <= cpu && dist + KVM_VGIC_V2_DIST_SIZE > cpu) ||
(cpu <= dist && cpu + KVM_VGIC_V2_CPU_SIZE > dist))
return -EBUSY;
return 0;
}
static int vgic_ioaddr_assign(struct kvm *kvm, phys_addr_t *ioaddr,
phys_addr_t addr, phys_addr_t size)
{
int ret;
if (addr & ~KVM_PHYS_MASK)
return -E2BIG;
if (addr & (SZ_4K - 1))
return -EINVAL;
if (!IS_VGIC_ADDR_UNDEF(*ioaddr))
return -EEXIST;
if (addr + size < addr)
return -EINVAL;
*ioaddr = addr;
ret = vgic_ioaddr_overlap(kvm);
if (ret)
*ioaddr = VGIC_ADDR_UNDEF;
return ret;
}
int kvm_vgic_addr(struct kvm *kvm, unsigned long type, u64 *addr, bool write)
{
int r = 0;
struct vgic_dist *vgic = &kvm->arch.vgic;
mutex_lock(&kvm->lock);
switch (type) {
case KVM_VGIC_V2_ADDR_TYPE_DIST:
if (write) {
r = vgic_ioaddr_assign(kvm, &vgic->vgic_dist_base,
*addr, KVM_VGIC_V2_DIST_SIZE);
} else {
*addr = vgic->vgic_dist_base;
}
break;
case KVM_VGIC_V2_ADDR_TYPE_CPU:
if (write) {
r = vgic_ioaddr_assign(kvm, &vgic->vgic_cpu_base,
*addr, KVM_VGIC_V2_CPU_SIZE);
} else {
*addr = vgic->vgic_cpu_base;
}
break;
default:
r = -ENODEV;
}
mutex_unlock(&kvm->lock);
return r;
}
static bool handle_cpu_mmio_misc(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio, phys_addr_t offset)
{
bool updated = false;
struct vgic_vmcr vmcr;
u32 *vmcr_field;
u32 reg;
vgic_get_vmcr(vcpu, &vmcr);
switch (offset & ~0x3) {
case GIC_CPU_CTRL:
vmcr_field = &vmcr.ctlr;
break;
case GIC_CPU_PRIMASK:
vmcr_field = &vmcr.pmr;
break;
case GIC_CPU_BINPOINT:
vmcr_field = &vmcr.bpr;
break;
case GIC_CPU_ALIAS_BINPOINT:
vmcr_field = &vmcr.abpr;
break;
default:
BUG();
}
if (!mmio->is_write) {
reg = *vmcr_field;
mmio_data_write(mmio, ~0, reg);
} else {
reg = mmio_data_read(mmio, ~0);
if (reg != *vmcr_field) {
*vmcr_field = reg;
vgic_set_vmcr(vcpu, &vmcr);
updated = true;
}
}
return updated;
}
static bool handle_mmio_abpr(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio, phys_addr_t offset)
{
return handle_cpu_mmio_misc(vcpu, mmio, GIC_CPU_ALIAS_BINPOINT);
}
static bool handle_cpu_mmio_ident(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
u32 reg;
if (mmio->is_write)
return false;
reg = (PRODUCT_ID_KVM << 20) |
(GICC_ARCH_VERSION_V2 << 16) |
(IMPLEMENTER_ARM << 0);
mmio_data_write(mmio, ~0, reg);
return false;
}
static int vgic_attr_regs_access(struct kvm_device *dev,
struct kvm_device_attr *attr,
u32 *reg, bool is_write)
{
const struct mmio_range *r = NULL, *ranges;
phys_addr_t offset;
int ret, cpuid, c;
struct kvm_vcpu *vcpu, *tmp_vcpu;
struct vgic_dist *vgic;
struct kvm_exit_mmio mmio;
offset = attr->attr & KVM_DEV_ARM_VGIC_OFFSET_MASK;
cpuid = (attr->attr & KVM_DEV_ARM_VGIC_CPUID_MASK) >>
KVM_DEV_ARM_VGIC_CPUID_SHIFT;
mutex_lock(&dev->kvm->lock);
if (cpuid >= atomic_read(&dev->kvm->online_vcpus)) {
ret = -EINVAL;
goto out;
}
vcpu = kvm_get_vcpu(dev->kvm, cpuid);
vgic = &dev->kvm->arch.vgic;
mmio.len = 4;
mmio.is_write = is_write;
if (is_write)
mmio_data_write(&mmio, ~0, *reg);
switch (attr->group) {
case KVM_DEV_ARM_VGIC_GRP_DIST_REGS:
mmio.phys_addr = vgic->vgic_dist_base + offset;
ranges = vgic_dist_ranges;
break;
case KVM_DEV_ARM_VGIC_GRP_CPU_REGS:
mmio.phys_addr = vgic->vgic_cpu_base + offset;
ranges = vgic_cpu_ranges;
break;
default:
BUG();
}
r = find_matching_range(ranges, &mmio, offset);
if (unlikely(!r || !r->handle_mmio)) {
ret = -ENXIO;
goto out;
}
spin_lock(&vgic->lock);
kvm_for_each_vcpu(c, tmp_vcpu, dev->kvm) {
if (unlikely(tmp_vcpu->cpu != -1)) {
ret = -EBUSY;
goto out_vgic_unlock;
}
}
kvm_for_each_vcpu(c, tmp_vcpu, dev->kvm)
vgic_unqueue_irqs(tmp_vcpu);
offset -= r->base;
r->handle_mmio(vcpu, &mmio, offset);
if (!is_write)
*reg = mmio_data_read(&mmio, ~0);
ret = 0;
out_vgic_unlock:
spin_unlock(&vgic->lock);
out:
mutex_unlock(&dev->kvm->lock);
return ret;
}
static int vgic_set_attr(struct kvm_device *dev, struct kvm_device_attr *attr)
{
int r;
switch (attr->group) {
case KVM_DEV_ARM_VGIC_GRP_ADDR: {
u64 __user *uaddr = (u64 __user *)(long)attr->addr;
u64 addr;
unsigned long type = (unsigned long)attr->attr;
if (copy_from_user(&addr, uaddr, sizeof(addr)))
return -EFAULT;
r = kvm_vgic_addr(dev->kvm, type, &addr, true);
return (r == -ENODEV) ? -ENXIO : r;
}
case KVM_DEV_ARM_VGIC_GRP_DIST_REGS:
case KVM_DEV_ARM_VGIC_GRP_CPU_REGS: {
u32 __user *uaddr = (u32 __user *)(long)attr->addr;
u32 reg;
if (get_user(reg, uaddr))
return -EFAULT;
return vgic_attr_regs_access(dev, attr, &reg, true);
}
}
return -ENXIO;
}
static int vgic_get_attr(struct kvm_device *dev, struct kvm_device_attr *attr)
{
int r = -ENXIO;
switch (attr->group) {
case KVM_DEV_ARM_VGIC_GRP_ADDR: {
u64 __user *uaddr = (u64 __user *)(long)attr->addr;
u64 addr;
unsigned long type = (unsigned long)attr->attr;
r = kvm_vgic_addr(dev->kvm, type, &addr, false);
if (r)
return (r == -ENODEV) ? -ENXIO : r;
if (copy_to_user(uaddr, &addr, sizeof(addr)))
return -EFAULT;
break;
}
case KVM_DEV_ARM_VGIC_GRP_DIST_REGS:
case KVM_DEV_ARM_VGIC_GRP_CPU_REGS: {
u32 __user *uaddr = (u32 __user *)(long)attr->addr;
u32 reg = 0;
r = vgic_attr_regs_access(dev, attr, &reg, false);
if (r)
return r;
r = put_user(reg, uaddr);
break;
}
}
return r;
}
static int vgic_has_attr_regs(const struct mmio_range *ranges,
phys_addr_t offset)
{
struct kvm_exit_mmio dev_attr_mmio;
dev_attr_mmio.len = 4;
if (find_matching_range(ranges, &dev_attr_mmio, offset))
return 0;
else
return -ENXIO;
}
static int vgic_has_attr(struct kvm_device *dev, struct kvm_device_attr *attr)
{
phys_addr_t offset;
switch (attr->group) {
case KVM_DEV_ARM_VGIC_GRP_ADDR:
switch (attr->attr) {
case KVM_VGIC_V2_ADDR_TYPE_DIST:
case KVM_VGIC_V2_ADDR_TYPE_CPU:
return 0;
}
break;
case KVM_DEV_ARM_VGIC_GRP_DIST_REGS:
offset = attr->attr & KVM_DEV_ARM_VGIC_OFFSET_MASK;
return vgic_has_attr_regs(vgic_dist_ranges, offset);
case KVM_DEV_ARM_VGIC_GRP_CPU_REGS:
offset = attr->attr & KVM_DEV_ARM_VGIC_OFFSET_MASK;
return vgic_has_attr_regs(vgic_cpu_ranges, offset);
}
return -ENXIO;
}
static void vgic_destroy(struct kvm_device *dev)
{
kfree(dev);
}
static int vgic_create(struct kvm_device *dev, u32 type)
{
return kvm_vgic_create(dev->kvm);
}
