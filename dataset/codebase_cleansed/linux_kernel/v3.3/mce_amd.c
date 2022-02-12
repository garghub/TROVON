static int lvt_off_valid(struct threshold_block *b, int apic, u32 lo, u32 hi)
{
int msr = (hi & MASK_LVTOFF_HI) >> 20;
if (apic < 0) {
pr_err(FW_BUG "cpu %d, failed to setup threshold interrupt "
"for bank %d, block %d (MSR%08X=0x%x%08x)\n", b->cpu,
b->bank, b->block, b->address, hi, lo);
return 0;
}
if (apic != msr) {
pr_err(FW_BUG "cpu %d, invalid threshold interrupt offset %d "
"for bank %d, block %d (MSR%08X=0x%x%08x)\n",
b->cpu, apic, b->bank, b->block, b->address, hi, lo);
return 0;
}
return 1;
}
static void threshold_restart_bank(void *_tr)
{
struct thresh_restart *tr = _tr;
u32 hi, lo;
rdmsr(tr->b->address, lo, hi);
if (tr->b->threshold_limit < (hi & THRESHOLD_MAX))
tr->reset = 1;
if (tr->reset) {
hi =
(hi & ~(MASK_ERR_COUNT_HI | MASK_OVERFLOW_HI)) |
(THRESHOLD_MAX - tr->b->threshold_limit);
} else if (tr->old_limit) {
int new_count = (hi & THRESHOLD_MAX) +
(tr->old_limit - tr->b->threshold_limit);
hi = (hi & ~MASK_ERR_COUNT_HI) |
(new_count & THRESHOLD_MAX);
}
if (tr->set_lvt_off) {
if (lvt_off_valid(tr->b, tr->lvt_off, lo, hi)) {
hi &= ~MASK_LVTOFF_HI;
hi |= tr->lvt_off << 20;
}
}
tr->b->interrupt_enable ?
(hi = (hi & ~MASK_INT_TYPE_HI) | INT_TYPE_APIC) :
(hi &= ~MASK_INT_TYPE_HI);
hi |= MASK_COUNT_EN_HI;
wrmsr(tr->b->address, lo, hi);
}
static void mce_threshold_block_init(struct threshold_block *b, int offset)
{
struct thresh_restart tr = {
.b = b,
.set_lvt_off = 1,
.lvt_off = offset,
};
b->threshold_limit = THRESHOLD_MAX;
threshold_restart_bank(&tr);
}
static int setup_APIC_mce(int reserved, int new)
{
if (reserved < 0 && !setup_APIC_eilvt(new, THRESHOLD_APIC_VECTOR,
APIC_EILVT_MSG_FIX, 0))
return new;
return reserved;
}
void mce_amd_feature_init(struct cpuinfo_x86 *c)
{
struct threshold_block b;
unsigned int cpu = smp_processor_id();
u32 low = 0, high = 0, address = 0;
unsigned int bank, block;
int offset = -1;
for (bank = 0; bank < NR_BANKS; ++bank) {
for (block = 0; block < NR_BLOCKS; ++block) {
if (block == 0)
address = MSR_IA32_MC0_MISC + bank * 4;
else if (block == 1) {
address = (low & MASK_BLKPTR_LO) >> 21;
if (!address)
break;
address += MCG_XBLK_ADDR;
} else
++address;
if (rdmsr_safe(address, &low, &high))
break;
if (!(high & MASK_VALID_HI))
continue;
if (!(high & MASK_CNTP_HI) ||
(high & MASK_LOCKED_HI))
continue;
if (!block)
per_cpu(bank_map, cpu) |= (1 << bank);
if (shared_bank[bank] && c->cpu_core_id)
break;
offset = setup_APIC_mce(offset,
(high & MASK_LVTOFF_HI) >> 20);
memset(&b, 0, sizeof(b));
b.cpu = cpu;
b.bank = bank;
b.block = block;
b.address = address;
mce_threshold_block_init(&b, offset);
mce_threshold_vector = amd_threshold_interrupt;
}
}
}
static void amd_threshold_interrupt(void)
{
u32 low = 0, high = 0, address = 0;
unsigned int bank, block;
struct mce m;
mce_setup(&m);
for (bank = 0; bank < NR_BANKS; ++bank) {
if (!(per_cpu(bank_map, m.cpu) & (1 << bank)))
continue;
for (block = 0; block < NR_BLOCKS; ++block) {
if (block == 0) {
address = MSR_IA32_MC0_MISC + bank * 4;
} else if (block == 1) {
address = (low & MASK_BLKPTR_LO) >> 21;
if (!address)
break;
address += MCG_XBLK_ADDR;
} else {
++address;
}
if (rdmsr_safe(address, &low, &high))
break;
if (!(high & MASK_VALID_HI)) {
if (block)
continue;
else
break;
}
if (!(high & MASK_CNTP_HI) ||
(high & MASK_LOCKED_HI))
continue;
machine_check_poll(MCP_TIMESTAMP,
&__get_cpu_var(mce_poll_banks));
if (high & MASK_OVERFLOW_HI) {
rdmsrl(address, m.misc);
rdmsrl(MSR_IA32_MC0_STATUS + bank * 4,
m.status);
m.bank = K8_MCE_THRESHOLD_BASE
+ bank * NR_BLOCKS
+ block;
mce_log(&m);
return;
}
}
}
}
static ssize_t
store_interrupt_enable(struct threshold_block *b, const char *buf, size_t size)
{
struct thresh_restart tr;
unsigned long new;
if (strict_strtoul(buf, 0, &new) < 0)
return -EINVAL;
b->interrupt_enable = !!new;
memset(&tr, 0, sizeof(tr));
tr.b = b;
smp_call_function_single(b->cpu, threshold_restart_bank, &tr, 1);
return size;
}
static ssize_t
store_threshold_limit(struct threshold_block *b, const char *buf, size_t size)
{
struct thresh_restart tr;
unsigned long new;
if (strict_strtoul(buf, 0, &new) < 0)
return -EINVAL;
if (new > THRESHOLD_MAX)
new = THRESHOLD_MAX;
if (new < 1)
new = 1;
memset(&tr, 0, sizeof(tr));
tr.old_limit = b->threshold_limit;
b->threshold_limit = new;
tr.b = b;
smp_call_function_single(b->cpu, threshold_restart_bank, &tr, 1);
return size;
}
static void local_error_count_handler(void *_tbcc)
{
struct threshold_block_cross_cpu *tbcc = _tbcc;
struct threshold_block *b = tbcc->tb;
u32 low, high;
rdmsr(b->address, low, high);
tbcc->retval = (high & 0xFFF) - (THRESHOLD_MAX - b->threshold_limit);
}
static ssize_t show_error_count(struct threshold_block *b, char *buf)
{
struct threshold_block_cross_cpu tbcc = { .tb = b, };
smp_call_function_single(b->cpu, local_error_count_handler, &tbcc, 1);
return sprintf(buf, "%lx\n", tbcc.retval);
}
static ssize_t store_error_count(struct threshold_block *b,
const char *buf, size_t count)
{
struct thresh_restart tr = { .b = b, .reset = 1, .old_limit = 0 };
smp_call_function_single(b->cpu, threshold_restart_bank, &tr, 1);
return 1;
}
static ssize_t show(struct kobject *kobj, struct attribute *attr, char *buf)
{
struct threshold_block *b = to_block(kobj);
struct threshold_attr *a = to_attr(attr);
ssize_t ret;
ret = a->show ? a->show(b, buf) : -EIO;
return ret;
}
static ssize_t store(struct kobject *kobj, struct attribute *attr,
const char *buf, size_t count)
{
struct threshold_block *b = to_block(kobj);
struct threshold_attr *a = to_attr(attr);
ssize_t ret;
ret = a->store ? a->store(b, buf, count) : -EIO;
return ret;
}
static __cpuinit int allocate_threshold_blocks(unsigned int cpu,
unsigned int bank,
unsigned int block,
u32 address)
{
struct threshold_block *b = NULL;
u32 low, high;
int err;
if ((bank >= NR_BANKS) || (block >= NR_BLOCKS))
return 0;
if (rdmsr_safe_on_cpu(cpu, address, &low, &high))
return 0;
if (!(high & MASK_VALID_HI)) {
if (block)
goto recurse;
else
return 0;
}
if (!(high & MASK_CNTP_HI) ||
(high & MASK_LOCKED_HI))
goto recurse;
b = kzalloc(sizeof(struct threshold_block), GFP_KERNEL);
if (!b)
return -ENOMEM;
b->block = block;
b->bank = bank;
b->cpu = cpu;
b->address = address;
b->interrupt_enable = 0;
b->threshold_limit = THRESHOLD_MAX;
INIT_LIST_HEAD(&b->miscj);
if (per_cpu(threshold_banks, cpu)[bank]->blocks) {
list_add(&b->miscj,
&per_cpu(threshold_banks, cpu)[bank]->blocks->miscj);
} else {
per_cpu(threshold_banks, cpu)[bank]->blocks = b;
}
err = kobject_init_and_add(&b->kobj, &threshold_ktype,
per_cpu(threshold_banks, cpu)[bank]->kobj,
"misc%i", block);
if (err)
goto out_free;
recurse:
if (!block) {
address = (low & MASK_BLKPTR_LO) >> 21;
if (!address)
return 0;
address += MCG_XBLK_ADDR;
} else {
++address;
}
err = allocate_threshold_blocks(cpu, bank, ++block, address);
if (err)
goto out_free;
if (b)
kobject_uevent(&b->kobj, KOBJ_ADD);
return err;
out_free:
if (b) {
kobject_put(&b->kobj);
list_del(&b->miscj);
kfree(b);
}
return err;
}
static __cpuinit long
local_allocate_threshold_blocks(int cpu, unsigned int bank)
{
return allocate_threshold_blocks(cpu, bank, 0,
MSR_IA32_MC0_MISC + bank * 4);
}
static __cpuinit int threshold_create_bank(unsigned int cpu, unsigned int bank)
{
int i, err = 0;
struct threshold_bank *b = NULL;
struct device *dev = mce_device[cpu];
char name[32];
sprintf(name, "threshold_bank%i", bank);
#ifdef CONFIG_SMP
if (cpu_data(cpu).cpu_core_id && shared_bank[bank]) {
i = cpumask_first(cpu_llc_shared_mask(cpu));
if (cpu_data(i).cpu_core_id)
goto out;
if (per_cpu(threshold_banks, cpu)[bank])
goto out;
b = per_cpu(threshold_banks, i)[bank];
if (!b)
goto out;
err = sysfs_create_link(&dev->kobj, b->kobj, name);
if (err)
goto out;
cpumask_copy(b->cpus, cpu_llc_shared_mask(cpu));
per_cpu(threshold_banks, cpu)[bank] = b;
goto out;
}
#endif
b = kzalloc(sizeof(struct threshold_bank), GFP_KERNEL);
if (!b) {
err = -ENOMEM;
goto out;
}
if (!zalloc_cpumask_var(&b->cpus, GFP_KERNEL)) {
kfree(b);
err = -ENOMEM;
goto out;
}
b->kobj = kobject_create_and_add(name, &dev->kobj);
if (!b->kobj)
goto out_free;
#ifndef CONFIG_SMP
cpumask_setall(b->cpus);
#else
cpumask_set_cpu(cpu, b->cpus);
#endif
per_cpu(threshold_banks, cpu)[bank] = b;
err = local_allocate_threshold_blocks(cpu, bank);
if (err)
goto out_free;
for_each_cpu(i, b->cpus) {
if (i == cpu)
continue;
dev = mce_device[i];
if (dev)
err = sysfs_create_link(&dev->kobj,b->kobj, name);
if (err)
goto out;
per_cpu(threshold_banks, i)[bank] = b;
}
goto out;
out_free:
per_cpu(threshold_banks, cpu)[bank] = NULL;
free_cpumask_var(b->cpus);
kfree(b);
out:
return err;
}
static __cpuinit int threshold_create_device(unsigned int cpu)
{
unsigned int bank;
int err = 0;
for (bank = 0; bank < NR_BANKS; ++bank) {
if (!(per_cpu(bank_map, cpu) & (1 << bank)))
continue;
err = threshold_create_bank(cpu, bank);
if (err)
return err;
}
return err;
}
static void deallocate_threshold_block(unsigned int cpu,
unsigned int bank)
{
struct threshold_block *pos = NULL;
struct threshold_block *tmp = NULL;
struct threshold_bank *head = per_cpu(threshold_banks, cpu)[bank];
if (!head)
return;
list_for_each_entry_safe(pos, tmp, &head->blocks->miscj, miscj) {
kobject_put(&pos->kobj);
list_del(&pos->miscj);
kfree(pos);
}
kfree(per_cpu(threshold_banks, cpu)[bank]->blocks);
per_cpu(threshold_banks, cpu)[bank]->blocks = NULL;
}
static void threshold_remove_bank(unsigned int cpu, int bank)
{
struct threshold_bank *b;
struct device *dev;
char name[32];
int i = 0;
b = per_cpu(threshold_banks, cpu)[bank];
if (!b)
return;
if (!b->blocks)
goto free_out;
sprintf(name, "threshold_bank%i", bank);
#ifdef CONFIG_SMP
if (shared_bank[bank] && b->blocks->cpu != cpu) {
sysfs_remove_link(&mce_device[cpu]->kobj, name);
per_cpu(threshold_banks, cpu)[bank] = NULL;
return;
}
#endif
for_each_cpu(i, b->cpus) {
if (i == cpu)
continue;
dev = mce_device[i];
if (dev)
sysfs_remove_link(&dev->kobj, name);
per_cpu(threshold_banks, i)[bank] = NULL;
}
deallocate_threshold_block(cpu, bank);
free_out:
kobject_del(b->kobj);
kobject_put(b->kobj);
free_cpumask_var(b->cpus);
kfree(b);
per_cpu(threshold_banks, cpu)[bank] = NULL;
}
static void threshold_remove_device(unsigned int cpu)
{
unsigned int bank;
for (bank = 0; bank < NR_BANKS; ++bank) {
if (!(per_cpu(bank_map, cpu) & (1 << bank)))
continue;
threshold_remove_bank(cpu, bank);
}
}
static void __cpuinit
amd_64_threshold_cpu_callback(unsigned long action, unsigned int cpu)
{
switch (action) {
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
threshold_create_device(cpu);
break;
case CPU_DEAD:
case CPU_DEAD_FROZEN:
threshold_remove_device(cpu);
break;
default:
break;
}
}
static __init int threshold_init_device(void)
{
unsigned lcpu = 0;
for_each_online_cpu(lcpu) {
int err = threshold_create_device(lcpu);
if (err)
return err;
}
threshold_cpu_callback = amd_64_threshold_cpu_callback;
return 0;
}
