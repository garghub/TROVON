static u32 get_ibs_caps(void)
{
u32 ibs_caps;
unsigned int max_level;
if (!boot_cpu_has(X86_FEATURE_IBS))
return 0;
max_level = cpuid_eax(0x80000000);
if (max_level < IBS_CPUID_FEATURES)
return IBS_CAPS_DEFAULT;
ibs_caps = cpuid_eax(IBS_CPUID_FEATURES);
if (!(ibs_caps & IBS_CAPS_AVAIL))
return IBS_CAPS_DEFAULT;
return ibs_caps;
}
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
static inline int get_eilvt(int offset)
{
return !setup_APIC_eilvt(offset, 0, APIC_EILVT_MSG_NMI, 1);
}
static inline int put_eilvt(int offset)
{
return !setup_APIC_eilvt(offset, 0, 0, 1);
}
static inline int ibs_eilvt_valid(void)
{
int offset;
u64 val;
int valid = 0;
preempt_disable();
rdmsrl(MSR_AMD64_IBSCTL, val);
offset = val & IBSCTL_LVT_OFFSET_MASK;
if (!(val & IBSCTL_LVT_OFFSET_VALID)) {
pr_err(FW_BUG "cpu %d, invalid IBS interrupt offset %d (MSR%08X=0x%016llx)\n",
smp_processor_id(), offset, MSR_AMD64_IBSCTL, val);
goto out;
}
if (!get_eilvt(offset)) {
pr_err(FW_BUG "cpu %d, IBS interrupt offset %d not available (MSR%08X=0x%016llx)\n",
smp_processor_id(), offset, MSR_AMD64_IBSCTL, val);
goto out;
}
valid = 1;
out:
preempt_enable();
return valid;
}
static inline int get_ibs_offset(void)
{
u64 val;
rdmsrl(MSR_AMD64_IBSCTL, val);
if (!(val & IBSCTL_LVT_OFFSET_VALID))
return -EINVAL;
return val & IBSCTL_LVT_OFFSET_MASK;
}
static void setup_APIC_ibs(void)
{
int offset;
offset = get_ibs_offset();
if (offset < 0)
goto failed;
if (!setup_APIC_eilvt(offset, 0, APIC_EILVT_MSG_NMI, 0))
return;
failed:
pr_warn("oprofile: IBS APIC setup failed on cpu #%d\n",
smp_processor_id());
}
static void clear_APIC_ibs(void)
{
int offset;
offset = get_ibs_offset();
if (offset >= 0)
setup_APIC_eilvt(offset, 0, APIC_EILVT_MSG_FIX, 1);
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
if (num_counters == NUM_COUNTERS_F15H) {
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
if (ibs_caps)
setup_APIC_ibs();
}
static void op_amd_cpu_shutdown(void)
{
if (ibs_caps)
clear_APIC_ibs();
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
static int setup_ibs_ctl(int ibs_eilvt_off)
{
struct pci_dev *cpu_cfg;
int nodes;
u32 value = 0;
nodes = 0;
cpu_cfg = NULL;
do {
cpu_cfg = pci_get_device(PCI_VENDOR_ID_AMD,
PCI_DEVICE_ID_AMD_10H_NB_MISC,
cpu_cfg);
if (!cpu_cfg)
break;
++nodes;
pci_write_config_dword(cpu_cfg, IBSCTL, ibs_eilvt_off
| IBSCTL_LVT_OFFSET_VALID);
pci_read_config_dword(cpu_cfg, IBSCTL, &value);
if (value != (ibs_eilvt_off | IBSCTL_LVT_OFFSET_VALID)) {
pci_dev_put(cpu_cfg);
printk(KERN_DEBUG "Failed to setup IBS LVT offset, "
"IBSCTL = 0x%08x\n", value);
return -EINVAL;
}
} while (1);
if (!nodes) {
printk(KERN_DEBUG "No CPU node configured for IBS\n");
return -ENODEV;
}
return 0;
}
static int force_ibs_eilvt_setup(void)
{
int offset;
int ret;
preempt_disable();
for (offset = 1; offset < APIC_EILVT_NR_MAX; offset++) {
if (get_eilvt(offset))
break;
}
preempt_enable();
if (offset == APIC_EILVT_NR_MAX) {
printk(KERN_DEBUG "No EILVT entry available\n");
return -EBUSY;
}
ret = setup_ibs_ctl(offset);
if (ret)
goto out;
if (!ibs_eilvt_valid()) {
ret = -EFAULT;
goto out;
}
pr_err(FW_BUG "using offset %d for IBS interrupts\n", offset);
pr_err(FW_BUG "workaround enabled for IBS LVT offset\n");
return 0;
out:
preempt_disable();
put_eilvt(offset);
preempt_enable();
return ret;
}
static void init_ibs(void)
{
ibs_caps = get_ibs_caps();
if (!ibs_caps)
return;
if (ibs_eilvt_valid())
goto out;
if (!force_ibs_eilvt_setup())
goto out;
ibs_caps = 0;
return;
out:
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
num_counters = NUM_COUNTERS_F15H;
} else {
num_counters = NUM_COUNTERS;
}
op_amd_spec.num_counters = num_counters;
op_amd_spec.num_controls = num_counters;
op_amd_spec.num_virt_counters = max(num_counters, NUM_VIRT_COUNTERS);
return 0;
}
