static unsigned amd_find_arch_event(struct kvm_pmu *pmu,
u8 event_select,
u8 unit_mask)
{
int i;
for (i = 0; i < ARRAY_SIZE(amd_event_mapping); i++)
if (amd_event_mapping[i].eventsel == event_select
&& amd_event_mapping[i].unit_mask == unit_mask)
break;
if (i == ARRAY_SIZE(amd_event_mapping))
return PERF_COUNT_HW_MAX;
return amd_event_mapping[i].event_type;
}
static unsigned amd_find_fixed_event(int idx)
{
return PERF_COUNT_HW_MAX;
}
static bool amd_pmc_is_enabled(struct kvm_pmc *pmc)
{
return true;
}
static struct kvm_pmc *amd_pmc_idx_to_pmc(struct kvm_pmu *pmu, int pmc_idx)
{
return get_gp_pmc(pmu, MSR_K7_EVNTSEL0 + pmc_idx, MSR_K7_EVNTSEL0);
}
static int amd_is_valid_msr_idx(struct kvm_vcpu *vcpu, unsigned idx)
{
struct kvm_pmu *pmu = vcpu_to_pmu(vcpu);
idx &= ~(3u << 30);
return (idx >= pmu->nr_arch_gp_counters);
}
static struct kvm_pmc *amd_msr_idx_to_pmc(struct kvm_vcpu *vcpu, unsigned idx)
{
struct kvm_pmu *pmu = vcpu_to_pmu(vcpu);
struct kvm_pmc *counters;
idx &= ~(3u << 30);
if (idx >= pmu->nr_arch_gp_counters)
return NULL;
counters = pmu->gp_counters;
return &counters[idx];
}
static bool amd_is_valid_msr(struct kvm_vcpu *vcpu, u32 msr)
{
struct kvm_pmu *pmu = vcpu_to_pmu(vcpu);
int ret = false;
ret = get_gp_pmc(pmu, msr, MSR_K7_PERFCTR0) ||
get_gp_pmc(pmu, msr, MSR_K7_EVNTSEL0);
return ret;
}
static int amd_pmu_get_msr(struct kvm_vcpu *vcpu, u32 msr, u64 *data)
{
struct kvm_pmu *pmu = vcpu_to_pmu(vcpu);
struct kvm_pmc *pmc;
pmc = get_gp_pmc(pmu, msr, MSR_K7_PERFCTR0);
if (pmc) {
*data = pmc_read_counter(pmc);
return 0;
}
pmc = get_gp_pmc(pmu, msr, MSR_K7_EVNTSEL0);
if (pmc) {
*data = pmc->eventsel;
return 0;
}
return 1;
}
static int amd_pmu_set_msr(struct kvm_vcpu *vcpu, struct msr_data *msr_info)
{
struct kvm_pmu *pmu = vcpu_to_pmu(vcpu);
struct kvm_pmc *pmc;
u32 msr = msr_info->index;
u64 data = msr_info->data;
pmc = get_gp_pmc(pmu, msr, MSR_K7_PERFCTR0);
if (pmc) {
pmc->counter += data - pmc_read_counter(pmc);
return 0;
}
pmc = get_gp_pmc(pmu, msr, MSR_K7_EVNTSEL0);
if (pmc) {
if (data == pmc->eventsel)
return 0;
if (!(data & pmu->reserved_bits)) {
reprogram_gp_counter(pmc, data);
return 0;
}
}
return 1;
}
static void amd_pmu_refresh(struct kvm_vcpu *vcpu)
{
struct kvm_pmu *pmu = vcpu_to_pmu(vcpu);
pmu->nr_arch_gp_counters = AMD64_NUM_COUNTERS;
pmu->counter_bitmask[KVM_PMC_GP] = ((u64)1 << 48) - 1;
pmu->reserved_bits = 0xffffffff00200000ull;
pmu->counter_bitmask[KVM_PMC_FIXED] = 0;
pmu->nr_arch_fixed_counters = 0;
pmu->version = 0;
pmu->global_status = 0;
}
static void amd_pmu_init(struct kvm_vcpu *vcpu)
{
struct kvm_pmu *pmu = vcpu_to_pmu(vcpu);
int i;
for (i = 0; i < AMD64_NUM_COUNTERS ; i++) {
pmu->gp_counters[i].type = KVM_PMC_GP;
pmu->gp_counters[i].vcpu = vcpu;
pmu->gp_counters[i].idx = i;
}
}
static void amd_pmu_reset(struct kvm_vcpu *vcpu)
{
struct kvm_pmu *pmu = vcpu_to_pmu(vcpu);
int i;
for (i = 0; i < AMD64_NUM_COUNTERS; i++) {
struct kvm_pmc *pmc = &pmu->gp_counters[i];
pmc_stop_counter(pmc);
pmc->counter = pmc->eventsel = 0;
}
}
