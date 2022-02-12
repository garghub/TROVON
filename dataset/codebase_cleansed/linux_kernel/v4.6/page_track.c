void kvm_page_track_free_memslot(struct kvm_memory_slot *free,
struct kvm_memory_slot *dont)
{
int i;
for (i = 0; i < KVM_PAGE_TRACK_MAX; i++)
if (!dont || free->arch.gfn_track[i] !=
dont->arch.gfn_track[i]) {
kvfree(free->arch.gfn_track[i]);
free->arch.gfn_track[i] = NULL;
}
}
int kvm_page_track_create_memslot(struct kvm_memory_slot *slot,
unsigned long npages)
{
int i;
for (i = 0; i < KVM_PAGE_TRACK_MAX; i++) {
slot->arch.gfn_track[i] = kvm_kvzalloc(npages *
sizeof(*slot->arch.gfn_track[i]));
if (!slot->arch.gfn_track[i])
goto track_free;
}
return 0;
track_free:
kvm_page_track_free_memslot(slot, NULL);
return -ENOMEM;
}
static inline bool page_track_mode_is_valid(enum kvm_page_track_mode mode)
{
if (mode < 0 || mode >= KVM_PAGE_TRACK_MAX)
return false;
return true;
}
static void update_gfn_track(struct kvm_memory_slot *slot, gfn_t gfn,
enum kvm_page_track_mode mode, short count)
{
int index, val;
index = gfn_to_index(gfn, slot->base_gfn, PT_PAGE_TABLE_LEVEL);
val = slot->arch.gfn_track[mode][index];
if (WARN_ON(val + count < 0 || val + count > USHRT_MAX))
return;
slot->arch.gfn_track[mode][index] += count;
}
void kvm_slot_page_track_add_page(struct kvm *kvm,
struct kvm_memory_slot *slot, gfn_t gfn,
enum kvm_page_track_mode mode)
{
if (WARN_ON(!page_track_mode_is_valid(mode)))
return;
update_gfn_track(slot, gfn, mode, 1);
kvm_mmu_gfn_disallow_lpage(slot, gfn);
if (mode == KVM_PAGE_TRACK_WRITE)
if (kvm_mmu_slot_gfn_write_protect(kvm, slot, gfn))
kvm_flush_remote_tlbs(kvm);
}
void kvm_slot_page_track_remove_page(struct kvm *kvm,
struct kvm_memory_slot *slot, gfn_t gfn,
enum kvm_page_track_mode mode)
{
if (WARN_ON(!page_track_mode_is_valid(mode)))
return;
update_gfn_track(slot, gfn, mode, -1);
kvm_mmu_gfn_allow_lpage(slot, gfn);
}
bool kvm_page_track_is_active(struct kvm_vcpu *vcpu, gfn_t gfn,
enum kvm_page_track_mode mode)
{
struct kvm_memory_slot *slot;
int index;
if (WARN_ON(!page_track_mode_is_valid(mode)))
return false;
slot = kvm_vcpu_gfn_to_memslot(vcpu, gfn);
if (!slot)
return false;
index = gfn_to_index(gfn, slot->base_gfn, PT_PAGE_TABLE_LEVEL);
return !!ACCESS_ONCE(slot->arch.gfn_track[mode][index]);
}
void kvm_page_track_init(struct kvm *kvm)
{
struct kvm_page_track_notifier_head *head;
head = &kvm->arch.track_notifier_head;
init_srcu_struct(&head->track_srcu);
INIT_HLIST_HEAD(&head->track_notifier_list);
}
void
kvm_page_track_register_notifier(struct kvm *kvm,
struct kvm_page_track_notifier_node *n)
{
struct kvm_page_track_notifier_head *head;
head = &kvm->arch.track_notifier_head;
spin_lock(&kvm->mmu_lock);
hlist_add_head_rcu(&n->node, &head->track_notifier_list);
spin_unlock(&kvm->mmu_lock);
}
void
kvm_page_track_unregister_notifier(struct kvm *kvm,
struct kvm_page_track_notifier_node *n)
{
struct kvm_page_track_notifier_head *head;
head = &kvm->arch.track_notifier_head;
spin_lock(&kvm->mmu_lock);
hlist_del_rcu(&n->node);
spin_unlock(&kvm->mmu_lock);
synchronize_srcu(&head->track_srcu);
}
void kvm_page_track_write(struct kvm_vcpu *vcpu, gpa_t gpa, const u8 *new,
int bytes)
{
struct kvm_page_track_notifier_head *head;
struct kvm_page_track_notifier_node *n;
int idx;
head = &vcpu->kvm->arch.track_notifier_head;
if (hlist_empty(&head->track_notifier_list))
return;
idx = srcu_read_lock(&head->track_srcu);
hlist_for_each_entry_rcu(n, &head->track_notifier_list, node)
if (n->track_write)
n->track_write(vcpu, gpa, new, bytes);
srcu_read_unlock(&head->track_srcu, idx);
}
