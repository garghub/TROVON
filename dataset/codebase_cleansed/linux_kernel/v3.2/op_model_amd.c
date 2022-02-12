static unsigned int lfsr_random(void)
{
static unsigned int lfsr_value = 0xF00D;
unsigned int bit;
bit = ((lfsr_value >> 0) ^
(lfsr_value >> 2) ^
(lfsr_value >> 3) ^
(lfsr_value >> 5)) & 0x0001;
lfsr_value = (lfsr_value >> 1) | (bit << 15);
return lfsr_value;
}
static inline u64 op_amd_randomize_ibs_op(u64 val)
{
unsigned int random = lfsr_random();
if (!(ibs_caps & IBS_CAPS_RDWROPCNT))
val += (s8)(random >> 4);
else
val |= (u64)(random & IBS_RANDOM_MASK) << 32;
return val;
}
static inline void
op_amd_handle_ibs(struct pt_regs * const regs,
struct op_msrs const * const msrs)
{
u64 val, ctl;
struct op_entry entry;
if (!ibs_caps)
return;
if (ibs_config.fetch_enabled) {
rdmsrl(MSR_AMD64_IBSFETCHCTL, ctl);
if (ctl & IBS_FETCH_VAL) {
rdmsrl(MSR_AMD64_IBSFETCHLINAD, val);
oprofile_write_reserve(&entry, regs, val,
IBS_FETCH_CODE, IBS_FETCH_SIZE);
oprofile_add_data64(&entry, val);
oprofile_add_data64(&entry, ctl);
rdmsrl(MSR_AMD64_IBSFETCHPHYSAD, val);
oprofile_add_data64(&entry, val);
oprofile_write_commit(&entry);
ctl &= ~(IBS_FETCH_VAL | IBS_FETCH_CNT);
ctl |= IBS_FETCH_ENABLE;
wrmsrl(MSR_AMD64_IBSFETCHCTL, ctl);
}
}
if (ibs_config.op_enabled) {
rdmsrl(MSR_AMD64_IBSOPCTL, ctl);
if (ctl & IBS_OP_VAL) {
rdmsrl(MSR_AMD64_IBSOPRIP, val);
oprofile_write_reserve(&entry, regs, val, IBS_OP_CODE,
ibs_state.sample_size);
oprofile_add_data64(&entry, val);
rdmsrl(MSR_AMD64_IBSOPDATA, val);
oprofile_add_data64(&entry, val);
rdmsrl(MSR_AMD64_IBSOPDATA2, val);
oprofile_add_data64(&entry, val);
rdmsrl(MSR_AMD64_IBSOPDATA3, val);
oprofile_add_data64(&entry, val);
rdmsrl(MSR_AMD64_IBSDCLINAD, val);
oprofile_add_data64(&entry, val);
rdmsrl(MSR_AMD64_IBSDCPHYSAD, val);
oprofile_add_data64(&entry, val);
if (ibs_state.branch_target) {
rdmsrl(MSR_AMD64_IBSBRTARGET, val);
oprofile_add_data(&entry, (unsigned long)val);
}
oprofile_write_commit(&entry);
ctl = op_amd_randomize_ibs_op(ibs_state.ibs_op_ctl);
wrmsrl(MSR_AMD64_IBSOPCTL, ctl);
}
}
}
static inline void op_amd_start_ibs(void)
{
u64 val;
if (!ibs_caps)
return;
memset(&ibs_state, 0, sizeof(ibs_state));
if (ibs_config.fetch_enabled) {
val = ibs_config.max_cnt_fetch >> 4;
val = min(val, IBS_FETCH_MAX_CNT);
ibs_config.max_cnt_fetch = val << 4;
val |= ibs_config.rand_en ? IBS_FETCH_RAND_EN : 0;
val |= IBS_FETCH_ENABLE;
wrmsrl(MSR_AMD64_IBSFETCHCTL, val);
}
if (ibs_config.op_enabled) {
val = ibs_config.max_cnt_op >> 4;
if (!(ibs_caps & IBS_CAPS_RDWROPCNT)) {
val = clamp(val, 0x0081ULL, 0xFF80ULL);
ibs_config.max_cnt_op = val << 4;
} else {
val += IBS_RANDOM_MAXCNT_OFFSET;
if (ibs_caps & IBS_CAPS_OPCNTEXT)
val = min(val, IBS_OP_MAX_CNT_EXT);
else
val = min(val, IBS_OP_MAX_CNT);
ibs_config.max_cnt_op =
(val - IBS_RANDOM_MAXCNT_OFFSET) << 4;
}
val = ((val & ~IBS_OP_MAX_CNT) << 4) | (val & IBS_OP_MAX_CNT);
val |= ibs_config.dispatched_ops ? IBS_OP_CNT_CTL : 0;
val |= IBS_OP_ENABLE;
ibs_state.ibs_op_ctl = val;
ibs_state.sample_size = IBS_OP_SIZE;
if (ibs_config.branch_target) {
ibs_state.branch_target = 1;
ibs_state.sample_size++;
}
val = op_amd_randomize_ibs_op(ibs_state.ibs_op_ctl);
wrmsrl(MSR_AMD64_IBSOPCTL, val);
}
}
static void op_amd_stop_ibs(void)
{
if (!ibs_caps)
return;
if (ibs_config.fetch_enabled)
wrmsrl(MSR_AMD64_IBSFETCHCTL, 0);
if (ibs_config.op_enabled)
wrmsrl(MSR_AMD64_IBSOPCTL, 0);
}
static void op_mux_switch_ctrl(struct op_x86_model_spec const *model,
struct op_msrs const * const msrs)
{
u64 val;
int i;
for (i = 0; i < num_counters; ++i) {
int virt = op_x86_phys_to_virt(i);
if (!reset_value[virt])
continue;
rdmsrl(msrs->controls[i].addr, val);
val &= model->reserved;
val |= op_x86_get_ctrl(model, &counter_config[virt]);
wrmsrl(msrs->controls[i].addr, val);
}
}
static void op_amd_shutdown(struct op_msrs const * const msrs)
{
int i;
for (i = 0; i < num_counters; ++i) {
if (!msrs->counters[i].addr)
continue;
release_perfctr_nmi(MSR_K7_PERFCTR0 + i);
release_evntsel_nmi(MSR_K7_EVNTSEL0 + i);
}
}
static int op_amd_fill_in_addresses(struct op_msrs * const msrs)
{
int i;
for (i = 0; i < num_counters; i++) {
if (!reserve_perfctr_nmi(MSR_K7_PERFCTR0 + i))
goto fail;
if (!reserve_evntsel_nmi(MSR_K7_EVNTSEL0 + i)) {
release_perfctr_nmi(MSR_K7_PERFCTR0 + i);
goto fail;
}
if (num_counters == AMD64_NUM_COUNTERS_F15H) {
msrs->counters[i].addr = MSR_F15H_PERF_CTR + (i << 1);
msrs->controls[i].addr = MSR_F15H_PERF_CTL + (i << 1);
} else {
msrs->controls[i].addr = MSR_K7_EVNTSEL0 + i;
msrs->counters[i].addr = MSR_K7_PERFCTR0 + i;
}
continue;
fail:
if (!counter_config[i].enabled)
continue;
op_x86_warn_reserved(i);
op_amd_shutdown(msrs);
return -EBUSY;
}
return 0;
}
static void op_amd_setup_ctrs(struct op_x86_model_spec const *model,
struct op_msrs const * const msrs)
{
u64 val;
int i;
for (i = 0; i < OP_MAX_COUNTER; ++i) {
if (counter_config[i].enabled
&& msrs->counters[op_x86_virt_to_phys(i)].addr)
reset_value[i] = counter_config[i].count;
else
reset_value[i] = 0;
}
for (i = 0; i < num_counters; ++i) {
if (!msrs->controls[i].addr)
continue;
rdmsrl(msrs->controls[i].addr, val);
if (val & ARCH_PERFMON_EVENTSEL_ENABLE)
op_x86_warn_in_use(i);
val &= model->reserved;
wrmsrl(msrs->controls[i].addr, val);
wrmsrl(msrs->counters[i].addr, -1LL);
}
for (i = 0; i < num_counters; ++i) {
int virt = op_x86_phys_to_virt(i);
if (!reset_value[virt])
continue;
wrmsrl(msrs->counters[i].addr, -(u64)reset_value[virt]);
rdmsrl(msrs->controls[i].addr, val);
val &= model->reserved;
val |= op_x86_get_ctrl(model, &counter_config[virt]);
wrmsrl(msrs->controls[i].addr, val);
}
}
static int op_amd_check_ctrs(struct pt_regs * const regs,
struct op_msrs const * const msrs)
{
u64 val;
int i;
for (i = 0; i < num_counters; ++i) {
int virt = op_x86_phys_to_virt(i);
if (!reset_value[virt])
continue;
rdmsrl(msrs->counters[i].addr, val);
if (val & OP_CTR_OVERFLOW)
continue;
oprofile_add_sample(regs, virt);
wrmsrl(msrs->counters[i].addr, -(u64)reset_value[virt]);
}
op_amd_handle_ibs(regs, msrs);
return 1;
}
static void op_amd_start(struct op_msrs const * const msrs)
{
u64 val;
int i;
for (i = 0; i < num_counters; ++i) {
if (!reset_value[op_x86_phys_to_virt(i)])
continue;
rdmsrl(msrs->controls[i].addr, val);
val |= ARCH_PERFMON_EVENTSEL_ENABLE;
wrmsrl(msrs->controls[i].addr, val);
}
op_amd_start_ibs();
}
static void op_amd_stop(struct op_msrs const * const msrs)
{
u64 val;
int i;
for (i = 0; i < num_counters; ++i) {
if (!reset_value[op_x86_phys_to_virt(i)])
continue;
rdmsrl(msrs->controls[i].addr, val);
val &= ~ARCH_PERFMON_EVENTSEL_ENABLE;
wrmsrl(msrs->controls[i].addr, val);
}
op_amd_stop_ibs();
}
static void init_ibs(void)
{
ibs_caps = get_ibs_caps();
if (!ibs_caps)
return;
printk(KERN_INFO "oprofile: AMD IBS detected (0x%08x)\n", ibs_caps);
}
static int setup_ibs_files(struct super_block *sb, struct dentry *root)
{
struct dentry *dir;
int ret = 0;
if (create_arch_files)
ret = create_arch_files(sb, root);
if (ret)
return ret;
if (!ibs_caps)
return ret;
memset(&ibs_config, 0, sizeof(ibs_config));
ibs_config.max_cnt_fetch = 250000;
ibs_config.max_cnt_op = 250000;
if (ibs_caps & IBS_CAPS_FETCHSAM) {
dir = oprofilefs_mkdir(sb, root, "ibs_fetch");
oprofilefs_create_ulong(sb, dir, "enable",
&ibs_config.fetch_enabled);
oprofilefs_create_ulong(sb, dir, "max_count",
&ibs_config.max_cnt_fetch);
oprofilefs_create_ulong(sb, dir, "rand_enable",
&ibs_config.rand_en);
}
if (ibs_caps & IBS_CAPS_OPSAM) {
dir = oprofilefs_mkdir(sb, root, "ibs_op");
oprofilefs_create_ulong(sb, dir, "enable",
&ibs_config.op_enabled);
oprofilefs_create_ulong(sb, dir, "max_count",
&ibs_config.max_cnt_op);
if (ibs_caps & IBS_CAPS_OPCNT)
oprofilefs_create_ulong(sb, dir, "dispatched_ops",
&ibs_config.dispatched_ops);
if (ibs_caps & IBS_CAPS_BRNTRGT)
oprofilefs_create_ulong(sb, dir, "branch_target",
&ibs_config.branch_target);
}
return 0;
}
static int op_amd_init(struct oprofile_operations *ops)
{
init_ibs();
create_arch_files = ops->create_files;
ops->create_files = setup_ibs_files;
if (boot_cpu_data.x86 == 0x15) {
num_counters = AMD64_NUM_COUNTERS_F15H;
} else {
num_counters = AMD64_NUM_COUNTERS;
}
op_amd_spec.num_counters = num_counters;
op_amd_spec.num_controls = num_counters;
op_amd_spec.num_virt_counters = max(num_counters, NUM_VIRT_COUNTERS);
return 0;
}
