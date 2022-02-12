static void wait_for_sync_step(int step)
{
int i, cpu = smp_processor_id();
for (i = cpu + 1; i < cpu + threads_per_core; i++)
while(per_cpu(split_state, i).step < step)
barrier();
mb();
}
static void update_hid_in_slw(u64 hid0)
{
u64 idle_states = pnv_get_supported_cpuidle_states();
if (idle_states & OPAL_PM_WINKLE_ENABLED) {
u64 cpu_pir = hard_smp_processor_id();
opal_slw_set_reg(cpu_pir, SPRN_HID0, hid0);
}
}
static void unsplit_core(void)
{
u64 hid0, mask;
int i, cpu;
mask = HID0_POWER8_2LPARMODE | HID0_POWER8_4LPARMODE;
cpu = smp_processor_id();
if (cpu_thread_in_core(cpu) != 0) {
while (mfspr(SPRN_HID0) & mask)
power7_nap(0);
per_cpu(split_state, cpu).step = SYNC_STEP_UNSPLIT;
return;
}
hid0 = mfspr(SPRN_HID0);
hid0 &= ~HID0_POWER8_DYNLPARDIS;
mtspr(SPRN_HID0, hid0);
update_hid_in_slw(hid0);
while (mfspr(SPRN_HID0) & mask)
cpu_relax();
for (i = cpu + 1; i < cpu + threads_per_core; i++)
smp_send_reschedule(i);
wait_for_sync_step(SYNC_STEP_UNSPLIT);
}
static void split_core(int new_mode)
{
struct { u64 value; u64 mask; } split_parms[2] = {
{ HID0_POWER8_1TO2LPAR, HID0_POWER8_2LPARMODE },
{ HID0_POWER8_1TO4LPAR, HID0_POWER8_4LPARMODE }
};
int i, cpu;
u64 hid0;
i = (new_mode >> 1) - 1;
BUG_ON(i < 0 || i > 1);
cpu = smp_processor_id();
if (cpu_thread_in_core(cpu) != 0) {
split_core_secondary_loop(&per_cpu(split_state, cpu).step);
return;
}
wait_for_sync_step(SYNC_STEP_REAL_MODE);
hid0 = mfspr(SPRN_HID0);
hid0 |= HID0_POWER8_DYNLPARDIS | split_parms[i].value;
mtspr(SPRN_HID0, hid0);
update_hid_in_slw(hid0);
while (!(mfspr(SPRN_HID0) & split_parms[i].mask))
cpu_relax();
}
static void cpu_do_split(int new_mode)
{
if (subcores_per_core != 1)
unsplit_core();
if (new_mode != 1)
split_core(new_mode);
mb();
per_cpu(split_state, smp_processor_id()).step = SYNC_STEP_FINISHED;
}
bool cpu_core_split_required(void)
{
smp_rmb();
if (!new_split_mode)
return false;
cpu_do_split(new_split_mode);
return true;
}
void update_subcore_sibling_mask(void)
{
int cpu;
int sibling_mask_first_cpu = (1 << threads_per_subcore) - 1;
for_each_possible_cpu(cpu) {
int tid = cpu_thread_in_core(cpu);
int offset = (tid / threads_per_subcore) * threads_per_subcore;
int mask = sibling_mask_first_cpu << offset;
paca[cpu].subcore_sibling_mask = mask;
}
}
static int cpu_update_split_mode(void *data)
{
int cpu, new_mode = *(int *)data;
if (this_cpu_ptr(&split_state)->master) {
new_split_mode = new_mode;
smp_wmb();
cpumask_andnot(cpu_offline_mask, cpu_present_mask,
cpu_online_mask);
for_each_cpu(cpu, cpu_offline_mask)
smp_send_reschedule(cpu);
}
cpu_do_split(new_mode);
if (this_cpu_ptr(&split_state)->master) {
for_each_present_cpu(cpu) {
if (cpu >= setup_max_cpus)
break;
while(per_cpu(split_state, cpu).step < SYNC_STEP_FINISHED)
barrier();
}
new_split_mode = 0;
subcores_per_core = new_mode;
threads_per_subcore = threads_per_core / subcores_per_core;
update_subcore_sibling_mask();
mb();
}
return 0;
}
static int set_subcores_per_core(int new_mode)
{
struct split_state *state;
int cpu;
if (kvm_hv_mode_active()) {
pr_err("Unable to change split core mode while KVM active.\n");
return -EBUSY;
}
BUG_ON(new_mode < 1 || new_mode > 4 || new_mode == 3);
for_each_present_cpu(cpu) {
state = &per_cpu(split_state, cpu);
state->step = SYNC_STEP_INITIAL;
state->master = 0;
}
get_online_cpus();
this_cpu_ptr(&split_state)->master = 1;
mb();
stop_machine(cpu_update_split_mode, &new_mode, cpu_online_mask);
put_online_cpus();
return 0;
}
static ssize_t __used store_subcores_per_core(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
unsigned long val;
int rc;
rc = sscanf(buf, "%lx", &val);
if (rc != 1)
return -EINVAL;
switch (val) {
case 1:
case 2:
case 4:
if (subcores_per_core == val)
goto out;
break;
default:
return -EINVAL;
}
rc = set_subcores_per_core(val);
if (rc)
return rc;
out:
return count;
}
static ssize_t show_subcores_per_core(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%x\n", subcores_per_core);
}
static int subcore_init(void)
{
if (!cpu_has_feature(CPU_FTR_ARCH_207S))
return 0;
if (setup_max_cpus % threads_per_core)
return 0;
BUG_ON(!alloc_cpumask_var(&cpu_offline_mask, GFP_KERNEL));
set_subcores_per_core(1);
return device_create_file(cpu_subsys.dev_root,
&dev_attr_subcores_per_core);
}
