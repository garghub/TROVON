static inline int require_table_link(const void *sdbt)
{
return ((unsigned long) sdbt & ~PAGE_MASK) == CPUM_SF_SDBT_TL_OFFSET;
}
static int sf_disable(void)
{
struct hws_lsctl_request_block sreq;
memset(&sreq, 0, sizeof(sreq));
return lsctl(&sreq);
}
static int sf_buffer_available(struct cpu_hw_sf *cpuhw)
{
return !!cpuhw->sfb.sdbt;
}
static void free_sampling_buffer(struct sf_buffer *sfb)
{
unsigned long *sdbt, *curr;
if (!sfb->sdbt)
return;
sdbt = sfb->sdbt;
curr = sdbt;
while (1) {
if (!*curr || !sdbt)
break;
if (is_link_entry(curr)) {
curr = get_next_sdbt(curr);
if (sdbt)
free_page((unsigned long) sdbt);
if (curr == sfb->sdbt)
break;
else
sdbt = curr;
} else {
if (*curr) {
free_page(*curr);
curr++;
}
}
}
debug_sprintf_event(sfdbg, 5,
"free_sampling_buffer: freed sdbt=%p\n", sfb->sdbt);
memset(sfb, 0, sizeof(*sfb));
}
static int alloc_sample_data_block(unsigned long *sdbt, gfp_t gfp_flags)
{
unsigned long sdb, *trailer;
sdb = get_zeroed_page(gfp_flags);
if (!sdb)
return -ENOMEM;
trailer = trailer_entry_ptr(sdb);
*trailer = SDB_TE_ALERT_REQ_MASK;
*sdbt = sdb;
return 0;
}
static int realloc_sampling_buffer(struct sf_buffer *sfb,
unsigned long num_sdb, gfp_t gfp_flags)
{
int i, rc;
unsigned long *new, *tail;
if (!sfb->sdbt || !sfb->tail)
return -EINVAL;
if (!is_link_entry(sfb->tail))
return -EINVAL;
tail = sfb->tail;
if (sfb->sdbt != get_next_sdbt(tail)) {
debug_sprintf_event(sfdbg, 3, "realloc_sampling_buffer: "
"sampling buffer is not linked: origin=%p"
"tail=%p\n",
(void *) sfb->sdbt, (void *) tail);
return -EINVAL;
}
rc = 0;
for (i = 0; i < num_sdb; i++) {
if (require_table_link(tail)) {
new = (unsigned long *) get_zeroed_page(gfp_flags);
if (!new) {
rc = -ENOMEM;
break;
}
sfb->num_sdbt++;
*tail = (unsigned long)(void *) new + 1;
tail = new;
}
rc = alloc_sample_data_block(tail, gfp_flags);
if (rc)
break;
sfb->num_sdb++;
tail++;
}
*tail = (unsigned long) sfb->sdbt + 1;
sfb->tail = tail;
debug_sprintf_event(sfdbg, 4, "realloc_sampling_buffer: new buffer"
" settings: sdbt=%lu sdb=%lu\n",
sfb->num_sdbt, sfb->num_sdb);
return rc;
}
static int alloc_sampling_buffer(struct sf_buffer *sfb, unsigned long num_sdb)
{
int rc;
if (sfb->sdbt)
return -EINVAL;
sfb->sdbt = (unsigned long *) get_zeroed_page(GFP_KERNEL);
if (!sfb->sdbt)
return -ENOMEM;
sfb->num_sdb = 0;
sfb->num_sdbt = 1;
sfb->tail = sfb->sdbt;
*sfb->tail = (unsigned long)(void *) sfb->sdbt + 1;
rc = realloc_sampling_buffer(sfb, num_sdb, GFP_KERNEL);
if (rc) {
free_sampling_buffer(sfb);
debug_sprintf_event(sfdbg, 4, "alloc_sampling_buffer: "
"realloc_sampling_buffer failed with rc=%i\n", rc);
} else
debug_sprintf_event(sfdbg, 4,
"alloc_sampling_buffer: tear=%p dear=%p\n",
sfb->sdbt, (void *) *sfb->sdbt);
return rc;
}
static void sfb_set_limits(unsigned long min, unsigned long max)
{
struct hws_qsi_info_block si;
CPUM_SF_MIN_SDB = min;
CPUM_SF_MAX_SDB = max;
memset(&si, 0, sizeof(si));
if (!qsi(&si))
CPUM_SF_SDB_DIAG_FACTOR = DIV_ROUND_UP(si.dsdes, si.bsdes);
}
static unsigned long sfb_max_limit(struct hw_perf_event *hwc)
{
return SAMPL_DIAG_MODE(hwc) ? CPUM_SF_MAX_SDB * CPUM_SF_SDB_DIAG_FACTOR
: CPUM_SF_MAX_SDB;
}
static unsigned long sfb_pending_allocs(struct sf_buffer *sfb,
struct hw_perf_event *hwc)
{
if (!sfb->sdbt)
return SFB_ALLOC_REG(hwc);
if (SFB_ALLOC_REG(hwc) > sfb->num_sdb)
return SFB_ALLOC_REG(hwc) - sfb->num_sdb;
return 0;
}
static int sfb_has_pending_allocs(struct sf_buffer *sfb,
struct hw_perf_event *hwc)
{
return sfb_pending_allocs(sfb, hwc) > 0;
}
static void sfb_account_allocs(unsigned long num, struct hw_perf_event *hwc)
{
num = min_t(unsigned long, num, sfb_max_limit(hwc) - SFB_ALLOC_REG(hwc));
if (num)
SFB_ALLOC_REG(hwc) += num;
}
static void sfb_init_allocs(unsigned long num, struct hw_perf_event *hwc)
{
SFB_ALLOC_REG(hwc) = 0;
sfb_account_allocs(num, hwc);
}
static size_t event_sample_size(struct hw_perf_event *hwc)
{
struct sf_raw_sample *sfr = (struct sf_raw_sample *) RAWSAMPLE_REG(hwc);
size_t sample_size;
sample_size = sfr->bsdes;
if (SAMPL_DIAG_MODE(hwc))
sample_size += sfr->dsdes;
return sample_size;
}
static void deallocate_buffers(struct cpu_hw_sf *cpuhw)
{
if (cpuhw->sfb.sdbt)
free_sampling_buffer(&cpuhw->sfb);
}
static int allocate_buffers(struct cpu_hw_sf *cpuhw, struct hw_perf_event *hwc)
{
unsigned long n_sdb, freq, factor;
size_t sfr_size, sample_size;
struct sf_raw_sample *sfr;
sfr_size = ALIGN((sizeof(*sfr) - sizeof(sfr->diag) + cpuhw->qsi.dsdes) +
sizeof(u32), sizeof(u64));
sfr_size -= sizeof(u32);
sfr = kzalloc(sfr_size, GFP_KERNEL);
if (!sfr)
return -ENOMEM;
sfr->size = sfr_size;
sfr->bsdes = cpuhw->qsi.bsdes;
sfr->dsdes = cpuhw->qsi.dsdes;
RAWSAMPLE_REG(hwc) = (unsigned long) sfr;
sample_size = event_sample_size(hwc);
freq = sample_rate_to_freq(&cpuhw->qsi, SAMPL_RATE(hwc));
factor = 1;
n_sdb = DIV_ROUND_UP(freq, factor * ((PAGE_SIZE-64) / sample_size));
if (n_sdb < CPUM_SF_MIN_SDB)
n_sdb = CPUM_SF_MIN_SDB;
sfb_init_allocs(n_sdb, hwc);
if (sf_buffer_available(cpuhw))
return 0;
debug_sprintf_event(sfdbg, 3,
"allocate_buffers: rate=%lu f=%lu sdb=%lu/%lu"
" sample_size=%lu cpuhw=%p\n",
SAMPL_RATE(hwc), freq, n_sdb, sfb_max_limit(hwc),
sample_size, cpuhw);
return alloc_sampling_buffer(&cpuhw->sfb,
sfb_pending_allocs(&cpuhw->sfb, hwc));
}
static unsigned long min_percent(unsigned int percent, unsigned long base,
unsigned long min)
{
return min_t(unsigned long, min, DIV_ROUND_UP(percent * base, 100));
}
static unsigned long compute_sfb_extent(unsigned long ratio, unsigned long base)
{
if (ratio <= 5)
return 0;
if (ratio <= 25)
return min_percent(1, base, 1);
if (ratio <= 50)
return min_percent(1, base, 1);
if (ratio <= 75)
return min_percent(2, base, 2);
if (ratio <= 100)
return min_percent(3, base, 3);
if (ratio <= 250)
return min_percent(4, base, 4);
return min_percent(5, base, 8);
}
static void sfb_account_overflows(struct cpu_hw_sf *cpuhw,
struct hw_perf_event *hwc)
{
unsigned long ratio, num;
if (!OVERFLOW_REG(hwc))
return;
ratio = DIV_ROUND_UP(100 * OVERFLOW_REG(hwc) * cpuhw->sfb.num_sdb,
sample_rate_to_freq(&cpuhw->qsi, SAMPL_RATE(hwc)));
num = compute_sfb_extent(ratio, cpuhw->sfb.num_sdb);
if (num)
sfb_account_allocs(num, hwc);
debug_sprintf_event(sfdbg, 5, "sfb: overflow: overflow=%llu ratio=%lu"
" num=%lu\n", OVERFLOW_REG(hwc), ratio, num);
OVERFLOW_REG(hwc) = 0;
}
static void extend_sampling_buffer(struct sf_buffer *sfb,
struct hw_perf_event *hwc)
{
unsigned long num, num_old;
int rc;
num = sfb_pending_allocs(sfb, hwc);
if (!num)
return;
num_old = sfb->num_sdb;
sf_disable();
rc = realloc_sampling_buffer(sfb, num, GFP_ATOMIC);
if (rc)
debug_sprintf_event(sfdbg, 5, "sfb: extend: realloc "
"failed with rc=%i\n", rc);
if (sfb_has_pending_allocs(sfb, hwc))
debug_sprintf_event(sfdbg, 5, "sfb: extend: "
"req=%lu alloc=%lu remaining=%lu\n",
num, sfb->num_sdb - num_old,
sfb_pending_allocs(sfb, hwc));
}
static void setup_pmc_cpu(void *flags)
{
int err;
struct cpu_hw_sf *cpusf = this_cpu_ptr(&cpu_hw_sf);
err = 0;
switch (*((int *) flags)) {
case PMC_INIT:
memset(cpusf, 0, sizeof(*cpusf));
err = qsi(&cpusf->qsi);
if (err)
break;
cpusf->flags |= PMU_F_RESERVED;
err = sf_disable();
if (err)
pr_err("Switching off the sampling facility failed "
"with rc=%i\n", err);
debug_sprintf_event(sfdbg, 5,
"setup_pmc_cpu: initialized: cpuhw=%p\n", cpusf);
break;
case PMC_RELEASE:
cpusf->flags &= ~PMU_F_RESERVED;
err = sf_disable();
if (err) {
pr_err("Switching off the sampling facility failed "
"with rc=%i\n", err);
} else
deallocate_buffers(cpusf);
debug_sprintf_event(sfdbg, 5,
"setup_pmc_cpu: released: cpuhw=%p\n", cpusf);
break;
}
if (err)
*((int *) flags) |= PMC_FAILURE;
}
static void release_pmc_hardware(void)
{
int flags = PMC_RELEASE;
irq_subclass_unregister(IRQ_SUBCLASS_MEASUREMENT_ALERT);
on_each_cpu(setup_pmc_cpu, &flags, 1);
}
static int reserve_pmc_hardware(void)
{
int flags = PMC_INIT;
on_each_cpu(setup_pmc_cpu, &flags, 1);
if (flags & PMC_FAILURE) {
release_pmc_hardware();
return -ENODEV;
}
irq_subclass_register(IRQ_SUBCLASS_MEASUREMENT_ALERT);
return 0;
}
static void hw_perf_event_destroy(struct perf_event *event)
{
if (RAWSAMPLE_REG(&event->hw))
kfree((void *) RAWSAMPLE_REG(&event->hw));
if (!atomic_add_unless(&num_events, -1, 1)) {
mutex_lock(&pmc_reserve_mutex);
if (atomic_dec_return(&num_events) == 0)
release_pmc_hardware();
mutex_unlock(&pmc_reserve_mutex);
}
}
static void hw_init_period(struct hw_perf_event *hwc, u64 period)
{
hwc->sample_period = period;
hwc->last_period = hwc->sample_period;
local64_set(&hwc->period_left, hwc->sample_period);
}
static void hw_reset_registers(struct hw_perf_event *hwc,
unsigned long *sdbt_origin)
{
struct sf_raw_sample *sfr;
TEAR_REG(hwc) = (unsigned long) sdbt_origin;
sfr = (struct sf_raw_sample *) RAWSAMPLE_REG(hwc);
memset(&sfr->basic, 0, sizeof(sfr->basic));
memset(&sfr->diag, 0, sfr->dsdes);
}
static unsigned long hw_limit_rate(const struct hws_qsi_info_block *si,
unsigned long rate)
{
return clamp_t(unsigned long, rate,
si->min_sampl_rate, si->max_sampl_rate);
}
static int __hw_perf_event_init(struct perf_event *event)
{
struct cpu_hw_sf *cpuhw;
struct hws_qsi_info_block si;
struct perf_event_attr *attr = &event->attr;
struct hw_perf_event *hwc = &event->hw;
unsigned long rate;
int cpu, err;
err = 0;
if (!atomic_inc_not_zero(&num_events)) {
mutex_lock(&pmc_reserve_mutex);
if (atomic_read(&num_events) == 0 && reserve_pmc_hardware())
err = -EBUSY;
else
atomic_inc(&num_events);
mutex_unlock(&pmc_reserve_mutex);
}
event->destroy = hw_perf_event_destroy;
if (err)
goto out;
memset(&si, 0, sizeof(si));
cpuhw = NULL;
if (event->cpu == -1)
qsi(&si);
else {
cpuhw = &per_cpu(cpu_hw_sf, event->cpu);
si = cpuhw->qsi;
}
if (!si.as) {
err = -ENOENT;
goto out;
}
SAMPL_FLAGS(hwc) = PERF_CPUM_SF_BASIC_MODE;
if (attr->config == PERF_EVENT_CPUM_SF_DIAG) {
if (!si.ad) {
err = -EPERM;
goto out;
}
SAMPL_FLAGS(hwc) |= PERF_CPUM_SF_DIAG_MODE;
}
if (attr->config1 & PERF_CPUM_SF_FULL_BLOCKS)
SAMPL_FLAGS(hwc) |= PERF_CPUM_SF_FULL_BLOCKS;
rate = 0;
if (attr->freq) {
rate = freq_to_sample_rate(&si, attr->sample_freq);
rate = hw_limit_rate(&si, rate);
attr->freq = 0;
attr->sample_period = rate;
} else {
rate = hw_limit_rate(&si, hwc->sample_period);
if (sample_rate_to_freq(&si, rate) >
sysctl_perf_event_sample_rate) {
err = -EINVAL;
debug_sprintf_event(sfdbg, 1, "Sampling rate exceeds maximum perf sample rate\n");
goto out;
}
}
SAMPL_RATE(hwc) = rate;
hw_init_period(hwc, SAMPL_RATE(hwc));
hwc->extra_reg.reg = REG_OVERFLOW;
OVERFLOW_REG(hwc) = 0;
if (cpuhw)
err = allocate_buffers(cpuhw, hwc);
else {
for_each_online_cpu(cpu) {
cpuhw = &per_cpu(cpu_hw_sf, cpu);
err = allocate_buffers(cpuhw, hwc);
if (err)
break;
}
}
out:
return err;
}
static int cpumsf_pmu_event_init(struct perf_event *event)
{
int err;
if (has_branch_stack(event))
return -EOPNOTSUPP;
switch (event->attr.type) {
case PERF_TYPE_RAW:
if ((event->attr.config != PERF_EVENT_CPUM_SF) &&
(event->attr.config != PERF_EVENT_CPUM_SF_DIAG))
return -ENOENT;
break;
case PERF_TYPE_HARDWARE:
if (event->attr.config != PERF_COUNT_HW_CPU_CYCLES)
return -ENOENT;
if (!is_sampling_event(event))
return -ENOENT;
break;
default:
return -ENOENT;
}
if (event->cpu >= nr_cpumask_bits ||
(event->cpu >= 0 && !cpu_online(event->cpu)))
return -ENODEV;
if (event->attr.exclude_hv)
event->attr.exclude_hv = 0;
if (event->attr.exclude_idle)
event->attr.exclude_idle = 0;
err = __hw_perf_event_init(event);
if (unlikely(err))
if (event->destroy)
event->destroy(event);
return err;
}
static void cpumsf_pmu_enable(struct pmu *pmu)
{
struct cpu_hw_sf *cpuhw = this_cpu_ptr(&cpu_hw_sf);
struct hw_perf_event *hwc;
int err;
if (cpuhw->flags & PMU_F_ENABLED)
return;
if (cpuhw->flags & PMU_F_ERR_MASK)
return;
if (cpuhw->event) {
hwc = &cpuhw->event->hw;
sfb_account_overflows(cpuhw, hwc);
if (sfb_has_pending_allocs(&cpuhw->sfb, hwc))
extend_sampling_buffer(&cpuhw->sfb, hwc);
}
cpuhw->flags |= PMU_F_ENABLED;
barrier();
err = lsctl(&cpuhw->lsctl);
if (err) {
cpuhw->flags &= ~PMU_F_ENABLED;
pr_err("Loading sampling controls failed: op=%i err=%i\n",
1, err);
return;
}
debug_sprintf_event(sfdbg, 6, "pmu_enable: es=%i cs=%i ed=%i cd=%i "
"tear=%p dear=%p\n", cpuhw->lsctl.es, cpuhw->lsctl.cs,
cpuhw->lsctl.ed, cpuhw->lsctl.cd,
(void *) cpuhw->lsctl.tear, (void *) cpuhw->lsctl.dear);
}
static void cpumsf_pmu_disable(struct pmu *pmu)
{
struct cpu_hw_sf *cpuhw = this_cpu_ptr(&cpu_hw_sf);
struct hws_lsctl_request_block inactive;
struct hws_qsi_info_block si;
int err;
if (!(cpuhw->flags & PMU_F_ENABLED))
return;
if (cpuhw->flags & PMU_F_ERR_MASK)
return;
inactive = cpuhw->lsctl;
inactive.cs = 0;
inactive.cd = 0;
err = lsctl(&inactive);
if (err) {
pr_err("Loading sampling controls failed: op=%i err=%i\n",
2, err);
return;
}
if (!qsi(&si)) {
if (si.es) {
cpuhw->lsctl.tear = si.tear;
cpuhw->lsctl.dear = si.dear;
}
} else
debug_sprintf_event(sfdbg, 3, "cpumsf_pmu_disable: "
"qsi() failed with err=%i\n", err);
cpuhw->flags &= ~PMU_F_ENABLED;
}
static int perf_exclude_event(struct perf_event *event, struct pt_regs *regs,
struct perf_sf_sde_regs *sde_regs)
{
if (event->attr.exclude_user && user_mode(regs))
return 1;
if (event->attr.exclude_kernel && !user_mode(regs))
return 1;
if (event->attr.exclude_guest && sde_regs->in_guest)
return 1;
if (event->attr.exclude_host && !sde_regs->in_guest)
return 1;
return 0;
}
static int perf_push_sample(struct perf_event *event, struct sf_raw_sample *sfr)
{
int overflow;
struct pt_regs regs;
struct perf_sf_sde_regs *sde_regs;
struct perf_sample_data data;
struct perf_raw_record raw = {
.frag = {
.size = sfr->size,
.data = sfr,
},
};
perf_sample_data_init(&data, 0, event->hw.last_period);
data.raw = &raw;
memset(&regs, 0, sizeof(regs));
regs.int_code = 0x1407;
regs.int_parm = CPU_MF_INT_SF_PRA;
sde_regs = (struct perf_sf_sde_regs *) &regs.int_parm_long;
regs.psw.addr = sfr->basic.ia;
if (sfr->basic.T)
regs.psw.mask |= PSW_MASK_DAT;
if (sfr->basic.W)
regs.psw.mask |= PSW_MASK_WAIT;
if (sfr->basic.P)
regs.psw.mask |= PSW_MASK_PSTATE;
switch (sfr->basic.AS) {
case 0x0:
regs.psw.mask |= PSW_ASC_PRIMARY;
break;
case 0x1:
regs.psw.mask |= PSW_ASC_ACCREG;
break;
case 0x2:
regs.psw.mask |= PSW_ASC_SECONDARY;
break;
case 0x3:
regs.psw.mask |= PSW_ASC_HOME;
break;
}
if (sfr->basic.gpp || sfr->basic.prim_asn != (u16) sfr->basic.hpp)
sde_regs->in_guest = 1;
overflow = 0;
if (perf_exclude_event(event, &regs, sde_regs))
goto out;
if (perf_event_overflow(event, &data, &regs)) {
overflow = 1;
event->pmu->stop(event, 0);
}
perf_event_update_userpage(event);
out:
return overflow;
}
static void perf_event_count_update(struct perf_event *event, u64 count)
{
local64_add(count, &event->count);
}
static int sample_format_is_valid(struct hws_combined_entry *sample,
unsigned int flags)
{
if (likely(flags & PERF_CPUM_SF_BASIC_MODE))
if (sample->basic.def != 0x0001)
return 0;
if (flags & PERF_CPUM_SF_DIAG_MODE)
if (sample->diag.def < 0x8001)
return 0;
return 1;
}
static int sample_is_consistent(struct hws_combined_entry *sample,
unsigned long flags)
{
if (unlikely(!(flags & PERF_CPUM_SF_BASIC_MODE)))
return 0;
if (sample->basic.I || sample->basic.W)
return 0;
return 1;
}
static void reset_sample_slot(struct hws_combined_entry *sample,
unsigned long flags)
{
if (likely(flags & PERF_CPUM_SF_BASIC_MODE))
sample->basic.def = 0;
if (flags & PERF_CPUM_SF_DIAG_MODE)
sample->diag.def = 0;
}
static void sfr_store_sample(struct sf_raw_sample *sfr,
struct hws_combined_entry *sample)
{
if (likely(sfr->format & PERF_CPUM_SF_BASIC_MODE))
sfr->basic = sample->basic;
if (sfr->format & PERF_CPUM_SF_DIAG_MODE)
memcpy(&sfr->diag, &sample->diag, sfr->dsdes);
}
static void debug_sample_entry(struct hws_combined_entry *sample,
struct hws_trailer_entry *te,
unsigned long flags)
{
debug_sprintf_event(sfdbg, 4, "hw_collect_samples: Found unknown "
"sampling data entry: te->f=%i basic.def=%04x (%p)"
" diag.def=%04x (%p)\n", te->f,
sample->basic.def, &sample->basic,
(flags & PERF_CPUM_SF_DIAG_MODE)
? sample->diag.def : 0xFFFF,
(flags & PERF_CPUM_SF_DIAG_MODE)
? &sample->diag : NULL);
}
static void hw_collect_samples(struct perf_event *event, unsigned long *sdbt,
unsigned long long *overflow)
{
unsigned long flags = SAMPL_FLAGS(&event->hw);
struct hws_combined_entry *sample;
struct hws_trailer_entry *te;
struct sf_raw_sample *sfr;
size_t sample_size;
sfr = (struct sf_raw_sample *) RAWSAMPLE_REG(&event->hw);
sfr->format = flags & PERF_CPUM_SF_MODE_MASK;
sample_size = event_sample_size(&event->hw);
te = (struct hws_trailer_entry *) trailer_entry_ptr(*sdbt);
sample = (struct hws_combined_entry *) *sdbt;
while ((unsigned long *) sample < (unsigned long *) te) {
if (!sample->basic.def)
break;
perf_event_count_update(event, SAMPL_RATE(&event->hw));
if (sample_format_is_valid(sample, flags)) {
if (!*overflow) {
if (sample_is_consistent(sample, flags)) {
sfr_store_sample(sfr, sample);
*overflow = perf_push_sample(event, sfr);
}
} else
*overflow += 1;
} else {
debug_sample_entry(sample, te, flags);
if (!te->f)
break;
}
reset_sample_slot(sample, flags);
sample += sample_size;
}
}
static void hw_perf_event_update(struct perf_event *event, int flush_all)
{
struct hw_perf_event *hwc = &event->hw;
struct hws_trailer_entry *te;
unsigned long *sdbt;
unsigned long long event_overflow, sampl_overflow, num_sdb, te_flags;
int done;
if (flush_all && SDB_FULL_BLOCKS(hwc))
flush_all = 0;
sdbt = (unsigned long *) TEAR_REG(hwc);
done = event_overflow = sampl_overflow = num_sdb = 0;
while (!done) {
te = (struct hws_trailer_entry *) trailer_entry_ptr(*sdbt);
if (!te->f) {
done = 1;
if (!flush_all)
break;
}
if (te->overflow)
sampl_overflow += te->overflow;
debug_sprintf_event(sfdbg, 6, "hw_perf_event_update: sdbt=%p "
"overflow=%llu timestamp=0x%llx\n",
sdbt, te->overflow,
(te->f) ? trailer_timestamp(te) : 0ULL);
hw_collect_samples(event, sdbt, &event_overflow);
num_sdb++;
do {
te_flags = te->flags & ~SDB_TE_BUFFER_FULL_MASK;
te_flags |= SDB_TE_ALERT_REQ_MASK;
} while (!cmpxchg_double(&te->flags, &te->overflow,
te->flags, te->overflow,
te_flags, 0ULL));
sdbt++;
if (is_link_entry(sdbt))
sdbt = get_next_sdbt(sdbt);
TEAR_REG(hwc) = (unsigned long) sdbt;
if (flush_all && done)
break;
if (event_overflow)
flush_all = 1;
}
if (sampl_overflow)
OVERFLOW_REG(hwc) = DIV_ROUND_UP(OVERFLOW_REG(hwc) +
sampl_overflow, 1 + num_sdb);
if (sampl_overflow || event_overflow)
debug_sprintf_event(sfdbg, 4, "hw_perf_event_update: "
"overflow stats: sample=%llu event=%llu\n",
sampl_overflow, event_overflow);
}
static void cpumsf_pmu_read(struct perf_event *event)
{
}
static void cpumsf_pmu_start(struct perf_event *event, int flags)
{
struct cpu_hw_sf *cpuhw = this_cpu_ptr(&cpu_hw_sf);
if (WARN_ON_ONCE(!(event->hw.state & PERF_HES_STOPPED)))
return;
if (flags & PERF_EF_RELOAD)
WARN_ON_ONCE(!(event->hw.state & PERF_HES_UPTODATE));
perf_pmu_disable(event->pmu);
event->hw.state = 0;
cpuhw->lsctl.cs = 1;
if (SAMPL_DIAG_MODE(&event->hw))
cpuhw->lsctl.cd = 1;
perf_pmu_enable(event->pmu);
}
static void cpumsf_pmu_stop(struct perf_event *event, int flags)
{
struct cpu_hw_sf *cpuhw = this_cpu_ptr(&cpu_hw_sf);
if (event->hw.state & PERF_HES_STOPPED)
return;
perf_pmu_disable(event->pmu);
cpuhw->lsctl.cs = 0;
cpuhw->lsctl.cd = 0;
event->hw.state |= PERF_HES_STOPPED;
if ((flags & PERF_EF_UPDATE) && !(event->hw.state & PERF_HES_UPTODATE)) {
hw_perf_event_update(event, 1);
event->hw.state |= PERF_HES_UPTODATE;
}
perf_pmu_enable(event->pmu);
}
static int cpumsf_pmu_add(struct perf_event *event, int flags)
{
struct cpu_hw_sf *cpuhw = this_cpu_ptr(&cpu_hw_sf);
int err;
if (cpuhw->flags & PMU_F_IN_USE)
return -EAGAIN;
if (!cpuhw->sfb.sdbt)
return -EINVAL;
err = 0;
perf_pmu_disable(event->pmu);
event->hw.state = PERF_HES_UPTODATE | PERF_HES_STOPPED;
cpuhw->lsctl.s = 0;
cpuhw->lsctl.h = 1;
cpuhw->lsctl.tear = (unsigned long) cpuhw->sfb.sdbt;
cpuhw->lsctl.dear = *(unsigned long *) cpuhw->sfb.sdbt;
cpuhw->lsctl.interval = SAMPL_RATE(&event->hw);
hw_reset_registers(&event->hw, cpuhw->sfb.sdbt);
if (WARN_ON_ONCE(cpuhw->lsctl.es == 1 || cpuhw->lsctl.ed == 1)) {
err = -EAGAIN;
goto out;
}
cpuhw->lsctl.es = 1;
if (SAMPL_DIAG_MODE(&event->hw))
cpuhw->lsctl.ed = 1;
cpuhw->event = event;
cpuhw->flags |= PMU_F_IN_USE;
if (flags & PERF_EF_START)
cpumsf_pmu_start(event, PERF_EF_RELOAD);
out:
perf_event_update_userpage(event);
perf_pmu_enable(event->pmu);
return err;
}
static void cpumsf_pmu_del(struct perf_event *event, int flags)
{
struct cpu_hw_sf *cpuhw = this_cpu_ptr(&cpu_hw_sf);
perf_pmu_disable(event->pmu);
cpumsf_pmu_stop(event, PERF_EF_UPDATE);
cpuhw->lsctl.es = 0;
cpuhw->lsctl.ed = 0;
cpuhw->flags &= ~PMU_F_IN_USE;
cpuhw->event = NULL;
perf_event_update_userpage(event);
perf_pmu_enable(event->pmu);
}
static void cpumf_measurement_alert(struct ext_code ext_code,
unsigned int alert, unsigned long unused)
{
struct cpu_hw_sf *cpuhw;
if (!(alert & CPU_MF_INT_SF_MASK))
return;
inc_irq_stat(IRQEXT_CMS);
cpuhw = this_cpu_ptr(&cpu_hw_sf);
if (!(cpuhw->flags & PMU_F_RESERVED))
return;
if (alert & CPU_MF_INT_SF_PRA) {
if (cpuhw->flags & PMU_F_IN_USE)
hw_perf_event_update(cpuhw->event, 0);
else
WARN_ON_ONCE(!(cpuhw->flags & PMU_F_IN_USE));
}
if (alert != CPU_MF_INT_SF_PRA)
debug_sprintf_event(sfdbg, 6, "measurement alert: 0x%x\n", alert);
if (alert & CPU_MF_INT_SF_SACA)
qsi(&cpuhw->qsi);
if (alert & CPU_MF_INT_SF_LSDA) {
pr_err("Sample data was lost\n");
cpuhw->flags |= PMU_F_ERR_LSDA;
sf_disable();
}
if (alert & (CPU_MF_INT_SF_IAE|CPU_MF_INT_SF_ISE)) {
pr_err("A sampling buffer entry is incorrect (alert=0x%x)\n",
alert);
cpuhw->flags |= PMU_F_ERR_IBE;
sf_disable();
}
}
static int cpusf_pmu_setup(unsigned int cpu, int flags)
{
if (!atomic_read(&num_events))
return 0;
local_irq_disable();
setup_pmc_cpu(&flags);
local_irq_enable();
return 0;
}
static int s390_pmu_sf_online_cpu(unsigned int cpu)
{
return cpusf_pmu_setup(cpu, PMC_INIT);
}
static int s390_pmu_sf_offline_cpu(unsigned int cpu)
{
return cpusf_pmu_setup(cpu, PMC_RELEASE);
}
static int param_get_sfb_size(char *buffer, const struct kernel_param *kp)
{
if (!cpum_sf_avail())
return -ENODEV;
return sprintf(buffer, "%lu,%lu", CPUM_SF_MIN_SDB, CPUM_SF_MAX_SDB);
}
static int param_set_sfb_size(const char *val, const struct kernel_param *kp)
{
int rc;
unsigned long min, max;
if (!cpum_sf_avail())
return -ENODEV;
if (!val || !strlen(val))
return -EINVAL;
min = CPUM_SF_MIN_SDB;
max = CPUM_SF_MAX_SDB;
if (strchr(val, ','))
rc = (sscanf(val, "%lu,%lu", &min, &max) == 2) ? 0 : -EINVAL;
else
rc = kstrtoul(val, 10, &max);
if (min < 2 || min >= max || max > get_num_physpages())
rc = -EINVAL;
if (rc)
return rc;
sfb_set_limits(min, max);
pr_info("The sampling buffer limits have changed to: "
"min=%lu max=%lu (diag=x%lu)\n",
CPUM_SF_MIN_SDB, CPUM_SF_MAX_SDB, CPUM_SF_SDB_DIAG_FACTOR);
return 0;
}
static void __init pr_cpumsf_err(unsigned int reason)
{
pr_err("Sampling facility support for perf is not available: "
"reason=%04x\n", reason);
}
static int __init init_cpum_sampling_pmu(void)
{
struct hws_qsi_info_block si;
int err;
if (!cpum_sf_avail())
return -ENODEV;
memset(&si, 0, sizeof(si));
if (qsi(&si)) {
pr_cpumsf_err(RS_INIT_FAILURE_QSI);
return -ENODEV;
}
if (si.bsdes != sizeof(struct hws_basic_entry)) {
pr_cpumsf_err(RS_INIT_FAILURE_BSDES);
return -EINVAL;
}
if (si.ad) {
sfb_set_limits(CPUM_SF_MIN_SDB, CPUM_SF_MAX_SDB);
cpumsf_pmu_events_attr[1] =
CPUMF_EVENT_PTR(SF, SF_CYCLES_BASIC_DIAG);
}
sfdbg = debug_register(KMSG_COMPONENT, 2, 1, 80);
if (!sfdbg)
pr_err("Registering for s390dbf failed\n");
debug_register_view(sfdbg, &debug_sprintf_view);
err = register_external_irq(EXT_IRQ_MEASURE_ALERT,
cpumf_measurement_alert);
if (err) {
pr_cpumsf_err(RS_INIT_FAILURE_ALRT);
goto out;
}
err = perf_pmu_register(&cpumf_sampling, "cpum_sf", PERF_TYPE_RAW);
if (err) {
pr_cpumsf_err(RS_INIT_FAILURE_PERF);
unregister_external_irq(EXT_IRQ_MEASURE_ALERT,
cpumf_measurement_alert);
goto out;
}
cpuhp_setup_state(CPUHP_AP_PERF_S390_SF_ONLINE, "AP_PERF_S390_SF_ONLINE",
s390_pmu_sf_online_cpu, s390_pmu_sf_offline_cpu);
out:
return err;
}
