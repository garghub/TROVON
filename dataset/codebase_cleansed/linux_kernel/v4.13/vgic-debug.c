static void iter_next(struct vgic_state_iter *iter)
{
if (iter->dist_id == 0) {
iter->dist_id++;
return;
}
iter->intid++;
if (iter->intid == VGIC_NR_PRIVATE_IRQS &&
++iter->vcpu_id < iter->nr_cpus)
iter->intid = 0;
}
static void iter_init(struct kvm *kvm, struct vgic_state_iter *iter,
loff_t pos)
{
int nr_cpus = atomic_read(&kvm->online_vcpus);
memset(iter, 0, sizeof(*iter));
iter->nr_cpus = nr_cpus;
iter->nr_spis = kvm->arch.vgic.nr_spis;
while (pos--)
iter_next(iter);
}
static bool end_of_vgic(struct vgic_state_iter *iter)
{
return iter->dist_id > 0 &&
iter->vcpu_id == iter->nr_cpus &&
(iter->intid - VGIC_NR_PRIVATE_IRQS) == iter->nr_spis;
}
static void *vgic_debug_start(struct seq_file *s, loff_t *pos)
{
struct kvm *kvm = (struct kvm *)s->private;
struct vgic_state_iter *iter;
mutex_lock(&kvm->lock);
iter = kvm->arch.vgic.iter;
if (iter) {
iter = ERR_PTR(-EBUSY);
goto out;
}
iter = kmalloc(sizeof(*iter), GFP_KERNEL);
if (!iter) {
iter = ERR_PTR(-ENOMEM);
goto out;
}
iter_init(kvm, iter, *pos);
kvm->arch.vgic.iter = iter;
if (end_of_vgic(iter))
iter = NULL;
out:
mutex_unlock(&kvm->lock);
return iter;
}
static void *vgic_debug_next(struct seq_file *s, void *v, loff_t *pos)
{
struct kvm *kvm = (struct kvm *)s->private;
struct vgic_state_iter *iter = kvm->arch.vgic.iter;
++*pos;
iter_next(iter);
if (end_of_vgic(iter))
iter = NULL;
return iter;
}
static void vgic_debug_stop(struct seq_file *s, void *v)
{
struct kvm *kvm = (struct kvm *)s->private;
struct vgic_state_iter *iter;
if (IS_ERR(v))
return;
mutex_lock(&kvm->lock);
iter = kvm->arch.vgic.iter;
kfree(iter);
kvm->arch.vgic.iter = NULL;
mutex_unlock(&kvm->lock);
}
static void print_dist_state(struct seq_file *s, struct vgic_dist *dist)
{
seq_printf(s, "Distributor\n");
seq_printf(s, "===========\n");
seq_printf(s, "vgic_model:\t%s\n",
(dist->vgic_model == KVM_DEV_TYPE_ARM_VGIC_V3) ?
"GICv3" : "GICv2");
seq_printf(s, "nr_spis:\t%d\n", dist->nr_spis);
seq_printf(s, "enabled:\t%d\n", dist->enabled);
seq_printf(s, "\n");
seq_printf(s, "P=pending_latch, L=line_level, A=active\n");
seq_printf(s, "E=enabled, H=hw, C=config (level=1, edge=0)\n");
}
static void print_header(struct seq_file *s, struct vgic_irq *irq,
struct kvm_vcpu *vcpu)
{
int id = 0;
char *hdr = "SPI ";
if (vcpu) {
hdr = "VCPU";
id = vcpu->vcpu_id;
}
seq_printf(s, "\n");
seq_printf(s, "%s%2d TYP ID TGT_ID PLAEHC HWID TARGET SRC PRI VCPU_ID\n", hdr, id);
seq_printf(s, "---------------------------------------------------------------\n");
}
static void print_irq_state(struct seq_file *s, struct vgic_irq *irq,
struct kvm_vcpu *vcpu)
{
char *type;
if (irq->intid < VGIC_NR_SGIS)
type = "SGI";
else if (irq->intid < VGIC_NR_PRIVATE_IRQS)
type = "PPI";
else
type = "SPI";
if (irq->intid ==0 || irq->intid == VGIC_NR_PRIVATE_IRQS)
print_header(s, irq, vcpu);
seq_printf(s, " %s %4d "
" %2d "
"%d%d%d%d%d%d "
"%8d "
"%8x "
" %2x "
"%3d "
" %2d "
"\n",
type, irq->intid,
(irq->target_vcpu) ? irq->target_vcpu->vcpu_id : -1,
irq->pending_latch,
irq->line_level,
irq->active,
irq->enabled,
irq->hw,
irq->config == VGIC_CONFIG_LEVEL,
irq->hwintid,
irq->mpidr,
irq->source,
irq->priority,
(irq->vcpu) ? irq->vcpu->vcpu_id : -1);
}
static int vgic_debug_show(struct seq_file *s, void *v)
{
struct kvm *kvm = (struct kvm *)s->private;
struct vgic_state_iter *iter = (struct vgic_state_iter *)v;
struct vgic_irq *irq;
struct kvm_vcpu *vcpu = NULL;
if (iter->dist_id == 0) {
print_dist_state(s, &kvm->arch.vgic);
return 0;
}
if (!kvm->arch.vgic.initialized)
return 0;
if (iter->vcpu_id < iter->nr_cpus) {
vcpu = kvm_get_vcpu(kvm, iter->vcpu_id);
irq = &vcpu->arch.vgic_cpu.private_irqs[iter->intid];
} else {
irq = &kvm->arch.vgic.spis[iter->intid - VGIC_NR_PRIVATE_IRQS];
}
spin_lock(&irq->irq_lock);
print_irq_state(s, irq, vcpu);
spin_unlock(&irq->irq_lock);
return 0;
}
static int debug_open(struct inode *inode, struct file *file)
{
int ret;
ret = seq_open(file, &vgic_debug_seq_ops);
if (!ret) {
struct seq_file *seq;
seq = file->private_data;
seq->private = inode->i_private;
}
return ret;
}
int vgic_debug_init(struct kvm *kvm)
{
if (!kvm->debugfs_dentry)
return -ENOENT;
if (!debugfs_create_file("vgic-state", 0444,
kvm->debugfs_dentry,
kvm,
&vgic_debug_fops))
return -ENOMEM;
return 0;
}
int vgic_debug_destroy(struct kvm *kvm)
{
return 0;
}
