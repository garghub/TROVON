static bool msr_mtrr_valid(unsigned msr)
{
switch (msr) {
case 0x200 ... 0x200 + 2 * KVM_NR_VAR_MTRR - 1:
case MSR_MTRRfix64K_00000:
case MSR_MTRRfix16K_80000:
case MSR_MTRRfix16K_A0000:
case MSR_MTRRfix4K_C0000:
case MSR_MTRRfix4K_C8000:
case MSR_MTRRfix4K_D0000:
case MSR_MTRRfix4K_D8000:
case MSR_MTRRfix4K_E0000:
case MSR_MTRRfix4K_E8000:
case MSR_MTRRfix4K_F0000:
case MSR_MTRRfix4K_F8000:
case MSR_MTRRdefType:
case MSR_IA32_CR_PAT:
return true;
case 0x2f8:
return true;
}
return false;
}
static bool valid_pat_type(unsigned t)
{
return t < 8 && (1 << t) & 0xf3;
}
static bool valid_mtrr_type(unsigned t)
{
return t < 8 && (1 << t) & 0x73;
}
bool kvm_mtrr_valid(struct kvm_vcpu *vcpu, u32 msr, u64 data)
{
int i;
u64 mask;
if (!msr_mtrr_valid(msr))
return false;
if (msr == MSR_IA32_CR_PAT) {
for (i = 0; i < 8; i++)
if (!valid_pat_type((data >> (i * 8)) & 0xff))
return false;
return true;
} else if (msr == MSR_MTRRdefType) {
if (data & ~0xcff)
return false;
return valid_mtrr_type(data & 0xff);
} else if (msr >= MSR_MTRRfix64K_00000 && msr <= MSR_MTRRfix4K_F8000) {
for (i = 0; i < 8 ; i++)
if (!valid_mtrr_type((data >> (i * 8)) & 0xff))
return false;
return true;
}
WARN_ON(!(msr >= 0x200 && msr < 0x200 + 2 * KVM_NR_VAR_MTRR));
mask = (~0ULL) << cpuid_maxphyaddr(vcpu);
if ((msr & 1) == 0) {
if (!valid_mtrr_type(data & 0xff))
return false;
mask |= 0xf00;
} else
mask |= 0x7ff;
if (data & mask) {
kvm_inject_gp(vcpu, 0);
return false;
}
return true;
}
static bool mtrr_is_enabled(struct kvm_mtrr *mtrr_state)
{
return !!(mtrr_state->deftype & IA32_MTRR_DEF_TYPE_E);
}
static bool fixed_mtrr_is_enabled(struct kvm_mtrr *mtrr_state)
{
return !!(mtrr_state->deftype & IA32_MTRR_DEF_TYPE_FE);
}
static u8 mtrr_default_type(struct kvm_mtrr *mtrr_state)
{
return mtrr_state->deftype & IA32_MTRR_DEF_TYPE_TYPE_MASK;
}
static u8 mtrr_disabled_type(struct kvm_vcpu *vcpu)
{
if (guest_cpuid_has_mtrr(vcpu))
return MTRR_TYPE_UNCACHABLE;
else
return MTRR_TYPE_WRBACK;
}
static u64 fixed_mtrr_seg_unit_size(int seg)
{
return 8 << fixed_seg_table[seg].range_shift;
}
static bool fixed_msr_to_seg_unit(u32 msr, int *seg, int *unit)
{
switch (msr) {
case MSR_MTRRfix64K_00000:
*seg = 0;
*unit = 0;
break;
case MSR_MTRRfix16K_80000 ... MSR_MTRRfix16K_A0000:
*seg = 1;
*unit = msr - MSR_MTRRfix16K_80000;
break;
case MSR_MTRRfix4K_C0000 ... MSR_MTRRfix4K_F8000:
*seg = 2;
*unit = msr - MSR_MTRRfix4K_C0000;
break;
default:
return false;
}
return true;
}
static void fixed_mtrr_seg_unit_range(int seg, int unit, u64 *start, u64 *end)
{
struct fixed_mtrr_segment *mtrr_seg = &fixed_seg_table[seg];
u64 unit_size = fixed_mtrr_seg_unit_size(seg);
*start = mtrr_seg->start + unit * unit_size;
*end = *start + unit_size;
WARN_ON(*end > mtrr_seg->end);
}
static int fixed_mtrr_seg_unit_range_index(int seg, int unit)
{
struct fixed_mtrr_segment *mtrr_seg = &fixed_seg_table[seg];
WARN_ON(mtrr_seg->start + unit * fixed_mtrr_seg_unit_size(seg)
> mtrr_seg->end);
return mtrr_seg->range_start + 8 * unit;
}
static int fixed_mtrr_seg_end_range_index(int seg)
{
struct fixed_mtrr_segment *mtrr_seg = &fixed_seg_table[seg];
int n;
n = (mtrr_seg->end - mtrr_seg->start) >> mtrr_seg->range_shift;
return mtrr_seg->range_start + n - 1;
}
static bool fixed_msr_to_range(u32 msr, u64 *start, u64 *end)
{
int seg, unit;
if (!fixed_msr_to_seg_unit(msr, &seg, &unit))
return false;
fixed_mtrr_seg_unit_range(seg, unit, start, end);
return true;
}
static int fixed_msr_to_range_index(u32 msr)
{
int seg, unit;
if (!fixed_msr_to_seg_unit(msr, &seg, &unit))
return -1;
return fixed_mtrr_seg_unit_range_index(seg, unit);
}
static int fixed_mtrr_addr_to_seg(u64 addr)
{
struct fixed_mtrr_segment *mtrr_seg;
int seg, seg_num = ARRAY_SIZE(fixed_seg_table);
for (seg = 0; seg < seg_num; seg++) {
mtrr_seg = &fixed_seg_table[seg];
if (mtrr_seg->start <= addr && addr < mtrr_seg->end)
return seg;
}
return -1;
}
static int fixed_mtrr_addr_seg_to_range_index(u64 addr, int seg)
{
struct fixed_mtrr_segment *mtrr_seg;
int index;
mtrr_seg = &fixed_seg_table[seg];
index = mtrr_seg->range_start;
index += (addr - mtrr_seg->start) >> mtrr_seg->range_shift;
return index;
}
static u64 fixed_mtrr_range_end_addr(int seg, int index)
{
struct fixed_mtrr_segment *mtrr_seg = &fixed_seg_table[seg];
int pos = index - mtrr_seg->range_start;
return mtrr_seg->start + ((pos + 1) << mtrr_seg->range_shift);
}
static void var_mtrr_range(struct kvm_mtrr_range *range, u64 *start, u64 *end)
{
u64 mask;
*start = range->base & PAGE_MASK;
mask = range->mask & PAGE_MASK;
*end = (*start | ~mask) + 1;
}
static void update_mtrr(struct kvm_vcpu *vcpu, u32 msr)
{
struct kvm_mtrr *mtrr_state = &vcpu->arch.mtrr_state;
gfn_t start, end;
int index;
if (msr == MSR_IA32_CR_PAT || !tdp_enabled ||
!kvm_arch_has_noncoherent_dma(vcpu->kvm))
return;
if (!mtrr_is_enabled(mtrr_state) && msr != MSR_MTRRdefType)
return;
if (fixed_msr_to_range(msr, &start, &end)) {
if (!fixed_mtrr_is_enabled(mtrr_state))
return;
} else if (msr == MSR_MTRRdefType) {
start = 0x0;
end = ~0ULL;
} else {
index = (msr - 0x200) / 2;
var_mtrr_range(&mtrr_state->var_ranges[index], &start, &end);
}
kvm_zap_gfn_range(vcpu->kvm, gpa_to_gfn(start), gpa_to_gfn(end));
}
static bool var_mtrr_range_is_valid(struct kvm_mtrr_range *range)
{
return (range->mask & (1 << 11)) != 0;
}
static void set_var_mtrr_msr(struct kvm_vcpu *vcpu, u32 msr, u64 data)
{
struct kvm_mtrr *mtrr_state = &vcpu->arch.mtrr_state;
struct kvm_mtrr_range *tmp, *cur;
int index, is_mtrr_mask;
index = (msr - 0x200) / 2;
is_mtrr_mask = msr - 0x200 - 2 * index;
cur = &mtrr_state->var_ranges[index];
if (var_mtrr_range_is_valid(cur))
list_del(&mtrr_state->var_ranges[index].node);
if (!is_mtrr_mask)
cur->base = data;
else
cur->mask = data | (-1LL << cpuid_maxphyaddr(vcpu));
if (var_mtrr_range_is_valid(cur)) {
list_for_each_entry(tmp, &mtrr_state->head, node)
if (cur->base >= tmp->base)
break;
list_add_tail(&cur->node, &tmp->node);
}
}
int kvm_mtrr_set_msr(struct kvm_vcpu *vcpu, u32 msr, u64 data)
{
int index;
if (!kvm_mtrr_valid(vcpu, msr, data))
return 1;
index = fixed_msr_to_range_index(msr);
if (index >= 0)
*(u64 *)&vcpu->arch.mtrr_state.fixed_ranges[index] = data;
else if (msr == MSR_MTRRdefType)
vcpu->arch.mtrr_state.deftype = data;
else if (msr == MSR_IA32_CR_PAT)
vcpu->arch.pat = data;
else
set_var_mtrr_msr(vcpu, msr, data);
update_mtrr(vcpu, msr);
return 0;
}
int kvm_mtrr_get_msr(struct kvm_vcpu *vcpu, u32 msr, u64 *pdata)
{
int index;
if (msr == MSR_MTRRcap) {
*pdata = 0x500 | KVM_NR_VAR_MTRR;
return 0;
}
if (!msr_mtrr_valid(msr))
return 1;
index = fixed_msr_to_range_index(msr);
if (index >= 0)
*pdata = *(u64 *)&vcpu->arch.mtrr_state.fixed_ranges[index];
else if (msr == MSR_MTRRdefType)
*pdata = vcpu->arch.mtrr_state.deftype;
else if (msr == MSR_IA32_CR_PAT)
*pdata = vcpu->arch.pat;
else {
int is_mtrr_mask;
index = (msr - 0x200) / 2;
is_mtrr_mask = msr - 0x200 - 2 * index;
if (!is_mtrr_mask)
*pdata = vcpu->arch.mtrr_state.var_ranges[index].base;
else
*pdata = vcpu->arch.mtrr_state.var_ranges[index].mask;
*pdata &= (1ULL << cpuid_maxphyaddr(vcpu)) - 1;
}
return 0;
}
void kvm_vcpu_mtrr_init(struct kvm_vcpu *vcpu)
{
INIT_LIST_HEAD(&vcpu->arch.mtrr_state.head);
}
static bool mtrr_lookup_fixed_start(struct mtrr_iter *iter)
{
int seg, index;
if (!fixed_mtrr_is_enabled(iter->mtrr_state))
return false;
seg = fixed_mtrr_addr_to_seg(iter->start);
if (seg < 0)
return false;
iter->fixed = true;
index = fixed_mtrr_addr_seg_to_range_index(iter->start, seg);
iter->index = index;
iter->seg = seg;
return true;
}
static bool match_var_range(struct mtrr_iter *iter,
struct kvm_mtrr_range *range)
{
u64 start, end;
var_mtrr_range(range, &start, &end);
if (!(start >= iter->end || end <= iter->start)) {
iter->range = range;
iter->partial_map |= iter->start_max < start;
iter->start_max = max(iter->start_max, end);
return true;
}
return false;
}
static void __mtrr_lookup_var_next(struct mtrr_iter *iter)
{
struct kvm_mtrr *mtrr_state = iter->mtrr_state;
list_for_each_entry_continue(iter->range, &mtrr_state->head, node)
if (match_var_range(iter, iter->range))
return;
iter->range = NULL;
iter->partial_map |= iter->start_max < iter->end;
}
static void mtrr_lookup_var_start(struct mtrr_iter *iter)
{
struct kvm_mtrr *mtrr_state = iter->mtrr_state;
iter->fixed = false;
iter->start_max = iter->start;
iter->range = list_prepare_entry(iter->range, &mtrr_state->head, node);
__mtrr_lookup_var_next(iter);
}
static void mtrr_lookup_fixed_next(struct mtrr_iter *iter)
{
if (fixed_mtrr_range_end_addr(iter->seg, iter->index) >= iter->end) {
iter->fixed = false;
iter->range = NULL;
return;
}
iter->index++;
if (iter->index >= ARRAY_SIZE(iter->mtrr_state->fixed_ranges))
return mtrr_lookup_var_start(iter);
if (iter->index > fixed_mtrr_seg_end_range_index(iter->seg))
iter->seg++;
}
static void mtrr_lookup_var_next(struct mtrr_iter *iter)
{
__mtrr_lookup_var_next(iter);
}
static void mtrr_lookup_start(struct mtrr_iter *iter)
{
if (!mtrr_is_enabled(iter->mtrr_state)) {
iter->mtrr_disabled = true;
return;
}
if (!mtrr_lookup_fixed_start(iter))
mtrr_lookup_var_start(iter);
}
static void mtrr_lookup_init(struct mtrr_iter *iter,
struct kvm_mtrr *mtrr_state, u64 start, u64 end)
{
iter->mtrr_state = mtrr_state;
iter->start = start;
iter->end = end;
iter->mtrr_disabled = false;
iter->partial_map = false;
iter->fixed = false;
iter->range = NULL;
mtrr_lookup_start(iter);
}
static bool mtrr_lookup_okay(struct mtrr_iter *iter)
{
if (iter->fixed) {
iter->mem_type = iter->mtrr_state->fixed_ranges[iter->index];
return true;
}
if (iter->range) {
iter->mem_type = iter->range->base & 0xff;
return true;
}
return false;
}
static void mtrr_lookup_next(struct mtrr_iter *iter)
{
if (iter->fixed)
mtrr_lookup_fixed_next(iter);
else
mtrr_lookup_var_next(iter);
}
u8 kvm_mtrr_get_guest_memory_type(struct kvm_vcpu *vcpu, gfn_t gfn)
{
struct kvm_mtrr *mtrr_state = &vcpu->arch.mtrr_state;
struct mtrr_iter iter;
u64 start, end;
int type = -1;
const int wt_wb_mask = (1 << MTRR_TYPE_WRBACK)
| (1 << MTRR_TYPE_WRTHROUGH);
start = gfn_to_gpa(gfn);
end = start + PAGE_SIZE;
mtrr_for_each_mem_type(&iter, mtrr_state, start, end) {
int curr_type = iter.mem_type;
if (type == -1) {
type = curr_type;
continue;
}
if (type == curr_type)
continue;
if (curr_type == MTRR_TYPE_UNCACHABLE)
return MTRR_TYPE_UNCACHABLE;
if (((1 << type) & wt_wb_mask) &&
((1 << curr_type) & wt_wb_mask)) {
type = MTRR_TYPE_WRTHROUGH;
continue;
}
return MTRR_TYPE_WRBACK;
}
if (iter.mtrr_disabled)
return mtrr_disabled_type(vcpu);
if (type == -1)
return mtrr_default_type(mtrr_state);
WARN_ON(iter.partial_map);
return type;
}
bool kvm_mtrr_check_gfn_range_consistency(struct kvm_vcpu *vcpu, gfn_t gfn,
int page_num)
{
struct kvm_mtrr *mtrr_state = &vcpu->arch.mtrr_state;
struct mtrr_iter iter;
u64 start, end;
int type = -1;
start = gfn_to_gpa(gfn);
end = gfn_to_gpa(gfn + page_num);
mtrr_for_each_mem_type(&iter, mtrr_state, start, end) {
if (type == -1) {
type = iter.mem_type;
continue;
}
if (type != iter.mem_type)
return false;
}
if (iter.mtrr_disabled)
return true;
if (!iter.partial_map)
return true;
if (type == -1)
return true;
return type == mtrr_default_type(mtrr_state);
}
