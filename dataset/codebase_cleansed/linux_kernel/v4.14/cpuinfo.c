static int c_show(struct seq_file *m, void *v)
{
int i, j;
bool compat = personality(current->personality) == PER_LINUX32;
for_each_online_cpu(i) {
struct cpuinfo_arm64 *cpuinfo = &per_cpu(cpu_data, i);
u32 midr = cpuinfo->reg_midr;
seq_printf(m, "processor\t: %d\n", i);
if (compat)
seq_printf(m, "model name\t: ARMv8 Processor rev %d (%s)\n",
MIDR_REVISION(midr), COMPAT_ELF_PLATFORM);
seq_printf(m, "BogoMIPS\t: %lu.%02lu\n",
loops_per_jiffy / (500000UL/HZ),
loops_per_jiffy / (5000UL/HZ) % 100);
seq_puts(m, "Features\t:");
if (compat) {
#ifdef CONFIG_COMPAT
for (j = 0; compat_hwcap_str[j]; j++)
if (compat_elf_hwcap & (1 << j))
seq_printf(m, " %s", compat_hwcap_str[j]);
for (j = 0; compat_hwcap2_str[j]; j++)
if (compat_elf_hwcap2 & (1 << j))
seq_printf(m, " %s", compat_hwcap2_str[j]);
#endif
} else {
for (j = 0; hwcap_str[j]; j++)
if (elf_hwcap & (1 << j))
seq_printf(m, " %s", hwcap_str[j]);
}
seq_puts(m, "\n");
seq_printf(m, "CPU implementer\t: 0x%02x\n",
MIDR_IMPLEMENTOR(midr));
seq_printf(m, "CPU architecture: 8\n");
seq_printf(m, "CPU variant\t: 0x%x\n", MIDR_VARIANT(midr));
seq_printf(m, "CPU part\t: 0x%03x\n", MIDR_PARTNUM(midr));
seq_printf(m, "CPU revision\t: %d\n\n", MIDR_REVISION(midr));
}
return 0;
}
static void *c_start(struct seq_file *m, loff_t *pos)
{
return *pos < 1 ? (void *)1 : NULL;
}
static void *c_next(struct seq_file *m, void *v, loff_t *pos)
{
++*pos;
return NULL;
}
static void c_stop(struct seq_file *m, void *v)
{
}
static int cpuid_cpu_online(unsigned int cpu)
{
int rc;
struct device *dev;
struct cpuinfo_arm64 *info = &per_cpu(cpu_data, cpu);
dev = get_cpu_device(cpu);
if (!dev) {
rc = -ENODEV;
goto out;
}
rc = kobject_add(&info->kobj, &dev->kobj, "regs");
if (rc)
goto out;
rc = sysfs_create_group(&info->kobj, &cpuregs_attr_group);
if (rc)
kobject_del(&info->kobj);
out:
return rc;
}
static int cpuid_cpu_offline(unsigned int cpu)
{
struct device *dev;
struct cpuinfo_arm64 *info = &per_cpu(cpu_data, cpu);
dev = get_cpu_device(cpu);
if (!dev)
return -ENODEV;
if (info->kobj.parent) {
sysfs_remove_group(&info->kobj, &cpuregs_attr_group);
kobject_del(&info->kobj);
}
return 0;
}
static int __init cpuinfo_regs_init(void)
{
int cpu, ret;
for_each_possible_cpu(cpu) {
struct cpuinfo_arm64 *info = &per_cpu(cpu_data, cpu);
kobject_init(&info->kobj, &cpuregs_kobj_type);
}
ret = cpuhp_setup_state(CPUHP_AP_ONLINE_DYN, "arm64/cpuinfo:online",
cpuid_cpu_online, cpuid_cpu_offline);
if (ret < 0) {
pr_err("cpuinfo: failed to register hotplug callbacks.\n");
return ret;
}
return 0;
}
static void cpuinfo_detect_icache_policy(struct cpuinfo_arm64 *info)
{
unsigned int cpu = smp_processor_id();
u32 l1ip = CTR_L1IP(info->reg_ctr);
switch (l1ip) {
case ICACHE_POLICY_PIPT:
break;
case ICACHE_POLICY_VPIPT:
set_bit(ICACHEF_VPIPT, &__icache_flags);
break;
default:
case ICACHE_POLICY_VIPT:
set_bit(ICACHEF_ALIASING, &__icache_flags);
}
pr_info("Detected %s I-cache on CPU%d\n", icache_policy_str[l1ip], cpu);
}
static void __cpuinfo_store_cpu(struct cpuinfo_arm64 *info)
{
info->reg_cntfrq = arch_timer_get_cntfrq();
info->reg_ctr = read_cpuid_cachetype();
info->reg_dczid = read_cpuid(DCZID_EL0);
info->reg_midr = read_cpuid_id();
info->reg_revidr = read_cpuid(REVIDR_EL1);
info->reg_id_aa64dfr0 = read_cpuid(ID_AA64DFR0_EL1);
info->reg_id_aa64dfr1 = read_cpuid(ID_AA64DFR1_EL1);
info->reg_id_aa64isar0 = read_cpuid(ID_AA64ISAR0_EL1);
info->reg_id_aa64isar1 = read_cpuid(ID_AA64ISAR1_EL1);
info->reg_id_aa64mmfr0 = read_cpuid(ID_AA64MMFR0_EL1);
info->reg_id_aa64mmfr1 = read_cpuid(ID_AA64MMFR1_EL1);
info->reg_id_aa64mmfr2 = read_cpuid(ID_AA64MMFR2_EL1);
info->reg_id_aa64pfr0 = read_cpuid(ID_AA64PFR0_EL1);
info->reg_id_aa64pfr1 = read_cpuid(ID_AA64PFR1_EL1);
if (id_aa64pfr0_32bit_el0(info->reg_id_aa64pfr0)) {
info->reg_id_dfr0 = read_cpuid(ID_DFR0_EL1);
info->reg_id_isar0 = read_cpuid(ID_ISAR0_EL1);
info->reg_id_isar1 = read_cpuid(ID_ISAR1_EL1);
info->reg_id_isar2 = read_cpuid(ID_ISAR2_EL1);
info->reg_id_isar3 = read_cpuid(ID_ISAR3_EL1);
info->reg_id_isar4 = read_cpuid(ID_ISAR4_EL1);
info->reg_id_isar5 = read_cpuid(ID_ISAR5_EL1);
info->reg_id_mmfr0 = read_cpuid(ID_MMFR0_EL1);
info->reg_id_mmfr1 = read_cpuid(ID_MMFR1_EL1);
info->reg_id_mmfr2 = read_cpuid(ID_MMFR2_EL1);
info->reg_id_mmfr3 = read_cpuid(ID_MMFR3_EL1);
info->reg_id_pfr0 = read_cpuid(ID_PFR0_EL1);
info->reg_id_pfr1 = read_cpuid(ID_PFR1_EL1);
info->reg_mvfr0 = read_cpuid(MVFR0_EL1);
info->reg_mvfr1 = read_cpuid(MVFR1_EL1);
info->reg_mvfr2 = read_cpuid(MVFR2_EL1);
}
cpuinfo_detect_icache_policy(info);
}
void cpuinfo_store_cpu(void)
{
struct cpuinfo_arm64 *info = this_cpu_ptr(&cpu_data);
__cpuinfo_store_cpu(info);
update_cpu_features(smp_processor_id(), info, &boot_cpu_data);
}
void __init cpuinfo_store_boot_cpu(void)
{
struct cpuinfo_arm64 *info = &per_cpu(cpu_data, 0);
__cpuinfo_store_cpu(info);
boot_cpu_data = *info;
init_cpu_features(&boot_cpu_data);
}
