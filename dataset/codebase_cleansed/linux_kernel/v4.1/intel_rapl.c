static struct rapl_package *find_package_by_id(int id)
{
struct rapl_package *rp;
list_for_each_entry(rp, &rapl_packages, plist) {
if (rp->id == id)
return rp;
}
return NULL;
}
static int find_active_cpu_on_package(int package_id)
{
int i;
for_each_online_cpu(i) {
if (topology_physical_package_id(i) == package_id)
return i;
}
return -ENODEV;
}
static void rapl_cleanup_data(void)
{
struct rapl_package *p, *tmp;
list_for_each_entry_safe(p, tmp, &rapl_packages, plist) {
kfree(p->domains);
list_del(&p->plist);
kfree(p);
}
}
static int get_energy_counter(struct powercap_zone *power_zone, u64 *energy_raw)
{
struct rapl_domain *rd;
u64 energy_now;
get_online_cpus();
rd = power_zone_to_rapl_domain(power_zone);
if (!rapl_read_data_raw(rd, ENERGY_COUNTER, true, &energy_now)) {
*energy_raw = energy_now;
put_online_cpus();
return 0;
}
put_online_cpus();
return -EIO;
}
static int get_max_energy_counter(struct powercap_zone *pcd_dev, u64 *energy)
{
struct rapl_domain *rd = power_zone_to_rapl_domain(pcd_dev);
*energy = rapl_unit_xlate(rd, 0, ENERGY_UNIT, ENERGY_STATUS_MASK, 0);
return 0;
}
static int release_zone(struct powercap_zone *power_zone)
{
struct rapl_domain *rd = power_zone_to_rapl_domain(power_zone);
struct rapl_package *rp;
if (rd->id == RAPL_DOMAIN_PACKAGE) {
rp = find_package_by_id(rd->package_id);
if (!rp) {
dev_warn(&power_zone->dev, "no package id %s\n",
rd->name);
return -ENODEV;
}
kfree(rd);
rp->domains = NULL;
}
return 0;
}
static int find_nr_power_limit(struct rapl_domain *rd)
{
int i;
for (i = 0; i < NR_POWER_LIMITS; i++) {
if (rd->rpl[i].name == NULL)
break;
}
return i;
}
static int set_domain_enable(struct powercap_zone *power_zone, bool mode)
{
struct rapl_domain *rd = power_zone_to_rapl_domain(power_zone);
if (rd->state & DOMAIN_STATE_BIOS_LOCKED)
return -EACCES;
get_online_cpus();
rapl_write_data_raw(rd, PL1_ENABLE, mode);
rapl_defaults->set_floor_freq(rd, mode);
put_online_cpus();
return 0;
}
static int get_domain_enable(struct powercap_zone *power_zone, bool *mode)
{
struct rapl_domain *rd = power_zone_to_rapl_domain(power_zone);
u64 val;
if (rd->state & DOMAIN_STATE_BIOS_LOCKED) {
*mode = false;
return 0;
}
get_online_cpus();
if (rapl_read_data_raw(rd, PL1_ENABLE, true, &val)) {
put_online_cpus();
return -EIO;
}
*mode = val;
put_online_cpus();
return 0;
}
static int set_power_limit(struct powercap_zone *power_zone, int id,
u64 power_limit)
{
struct rapl_domain *rd;
struct rapl_package *rp;
int ret = 0;
get_online_cpus();
rd = power_zone_to_rapl_domain(power_zone);
rp = find_package_by_id(rd->package_id);
if (!rp) {
ret = -ENODEV;
goto set_exit;
}
if (rd->state & DOMAIN_STATE_BIOS_LOCKED) {
dev_warn(&power_zone->dev, "%s locked by BIOS, monitoring only\n",
rd->name);
ret = -EACCES;
goto set_exit;
}
switch (rd->rpl[id].prim_id) {
case PL1_ENABLE:
rapl_write_data_raw(rd, POWER_LIMIT1, power_limit);
break;
case PL2_ENABLE:
rapl_write_data_raw(rd, POWER_LIMIT2, power_limit);
break;
default:
ret = -EINVAL;
}
if (!ret)
package_power_limit_irq_save(rd->package_id);
set_exit:
put_online_cpus();
return ret;
}
static int get_current_power_limit(struct powercap_zone *power_zone, int id,
u64 *data)
{
struct rapl_domain *rd;
u64 val;
int prim;
int ret = 0;
get_online_cpus();
rd = power_zone_to_rapl_domain(power_zone);
switch (rd->rpl[id].prim_id) {
case PL1_ENABLE:
prim = POWER_LIMIT1;
break;
case PL2_ENABLE:
prim = POWER_LIMIT2;
break;
default:
put_online_cpus();
return -EINVAL;
}
if (rapl_read_data_raw(rd, prim, true, &val))
ret = -EIO;
else
*data = val;
put_online_cpus();
return ret;
}
static int set_time_window(struct powercap_zone *power_zone, int id,
u64 window)
{
struct rapl_domain *rd;
int ret = 0;
get_online_cpus();
rd = power_zone_to_rapl_domain(power_zone);
switch (rd->rpl[id].prim_id) {
case PL1_ENABLE:
rapl_write_data_raw(rd, TIME_WINDOW1, window);
break;
case PL2_ENABLE:
rapl_write_data_raw(rd, TIME_WINDOW2, window);
break;
default:
ret = -EINVAL;
}
put_online_cpus();
return ret;
}
static int get_time_window(struct powercap_zone *power_zone, int id, u64 *data)
{
struct rapl_domain *rd;
u64 val;
int ret = 0;
get_online_cpus();
rd = power_zone_to_rapl_domain(power_zone);
switch (rd->rpl[id].prim_id) {
case PL1_ENABLE:
ret = rapl_read_data_raw(rd, TIME_WINDOW1, true, &val);
break;
case PL2_ENABLE:
ret = rapl_read_data_raw(rd, TIME_WINDOW2, true, &val);
break;
default:
put_online_cpus();
return -EINVAL;
}
if (!ret)
*data = val;
put_online_cpus();
return ret;
}
static const char *get_constraint_name(struct powercap_zone *power_zone, int id)
{
struct rapl_power_limit *rpl;
struct rapl_domain *rd;
rd = power_zone_to_rapl_domain(power_zone);
rpl = (struct rapl_power_limit *) &rd->rpl[id];
return rpl->name;
}
static int get_max_power(struct powercap_zone *power_zone, int id,
u64 *data)
{
struct rapl_domain *rd;
u64 val;
int prim;
int ret = 0;
get_online_cpus();
rd = power_zone_to_rapl_domain(power_zone);
switch (rd->rpl[id].prim_id) {
case PL1_ENABLE:
prim = THERMAL_SPEC_POWER;
break;
case PL2_ENABLE:
prim = MAX_POWER;
break;
default:
put_online_cpus();
return -EINVAL;
}
if (rapl_read_data_raw(rd, prim, true, &val))
ret = -EIO;
else
*data = val;
put_online_cpus();
return ret;
}
static void rapl_init_domains(struct rapl_package *rp)
{
int i;
struct rapl_domain *rd = rp->domains;
for (i = 0; i < RAPL_DOMAIN_MAX; i++) {
unsigned int mask = rp->domain_map & (1 << i);
switch (mask) {
case BIT(RAPL_DOMAIN_PACKAGE):
rd->name = rapl_domain_names[RAPL_DOMAIN_PACKAGE];
rd->id = RAPL_DOMAIN_PACKAGE;
rd->msrs[0] = MSR_PKG_POWER_LIMIT;
rd->msrs[1] = MSR_PKG_ENERGY_STATUS;
rd->msrs[2] = MSR_PKG_PERF_STATUS;
rd->msrs[3] = 0;
rd->msrs[4] = MSR_PKG_POWER_INFO;
rd->rpl[0].prim_id = PL1_ENABLE;
rd->rpl[0].name = pl1_name;
rd->rpl[1].prim_id = PL2_ENABLE;
rd->rpl[1].name = pl2_name;
break;
case BIT(RAPL_DOMAIN_PP0):
rd->name = rapl_domain_names[RAPL_DOMAIN_PP0];
rd->id = RAPL_DOMAIN_PP0;
rd->msrs[0] = MSR_PP0_POWER_LIMIT;
rd->msrs[1] = MSR_PP0_ENERGY_STATUS;
rd->msrs[2] = 0;
rd->msrs[3] = MSR_PP0_POLICY;
rd->msrs[4] = 0;
rd->rpl[0].prim_id = PL1_ENABLE;
rd->rpl[0].name = pl1_name;
break;
case BIT(RAPL_DOMAIN_PP1):
rd->name = rapl_domain_names[RAPL_DOMAIN_PP1];
rd->id = RAPL_DOMAIN_PP1;
rd->msrs[0] = MSR_PP1_POWER_LIMIT;
rd->msrs[1] = MSR_PP1_ENERGY_STATUS;
rd->msrs[2] = 0;
rd->msrs[3] = MSR_PP1_POLICY;
rd->msrs[4] = 0;
rd->rpl[0].prim_id = PL1_ENABLE;
rd->rpl[0].name = pl1_name;
break;
case BIT(RAPL_DOMAIN_DRAM):
rd->name = rapl_domain_names[RAPL_DOMAIN_DRAM];
rd->id = RAPL_DOMAIN_DRAM;
rd->msrs[0] = MSR_DRAM_POWER_LIMIT;
rd->msrs[1] = MSR_DRAM_ENERGY_STATUS;
rd->msrs[2] = MSR_DRAM_PERF_STATUS;
rd->msrs[3] = 0;
rd->msrs[4] = MSR_DRAM_POWER_INFO;
rd->rpl[0].prim_id = PL1_ENABLE;
rd->rpl[0].name = pl1_name;
rd->domain_energy_unit =
rapl_defaults->dram_domain_energy_unit;
if (rd->domain_energy_unit)
pr_info("DRAM domain energy unit %dpj\n",
rd->domain_energy_unit);
break;
}
if (mask) {
rd->package_id = rp->id;
rd++;
}
}
}
static u64 rapl_unit_xlate(struct rapl_domain *rd, int package,
enum unit_type type, u64 value,
int to_raw)
{
u64 units = 1;
struct rapl_package *rp;
u64 scale = 1;
rp = find_package_by_id(package);
if (!rp)
return value;
switch (type) {
case POWER_UNIT:
units = rp->power_unit;
break;
case ENERGY_UNIT:
scale = ENERGY_UNIT_SCALE;
if (rd && rd->domain_energy_unit)
units = rd->domain_energy_unit;
else
units = rp->energy_unit;
break;
case TIME_UNIT:
return rapl_defaults->compute_time_window(rp, value, to_raw);
case ARBITRARY_UNIT:
default:
return value;
};
if (to_raw)
return div64_u64(value, units) * scale;
value *= units;
return div64_u64(value, scale);
}
static int rapl_read_data_raw(struct rapl_domain *rd,
enum rapl_primitives prim,
bool xlate, u64 *data)
{
u64 value, final;
u32 msr;
struct rapl_primitive_info *rp = &rpi[prim];
int cpu;
if (!rp->name || rp->flag & RAPL_PRIMITIVE_DUMMY)
return -EINVAL;
msr = rd->msrs[rp->id];
if (!msr)
return -EINVAL;
cpu = find_active_cpu_on_package(rd->package_id);
if (cpu < 0)
return cpu;
if (prim == FW_LOCK && rd->id == RAPL_DOMAIN_PACKAGE) {
rp->mask = POWER_PACKAGE_LOCK;
rp->shift = 63;
}
if (rp->flag & RAPL_PRIMITIVE_DERIVED) {
*data = rd->rdd.primitives[prim];
return 0;
}
if (rdmsrl_safe_on_cpu(cpu, msr, &value)) {
pr_debug("failed to read msr 0x%x on cpu %d\n", msr, cpu);
return -EIO;
}
final = value & rp->mask;
final = final >> rp->shift;
if (xlate)
*data = rapl_unit_xlate(rd, rd->package_id, rp->unit, final, 0);
else
*data = final;
return 0;
}
static int rapl_write_data_raw(struct rapl_domain *rd,
enum rapl_primitives prim,
unsigned long long value)
{
u64 msr_val;
u32 msr;
struct rapl_primitive_info *rp = &rpi[prim];
int cpu;
cpu = find_active_cpu_on_package(rd->package_id);
if (cpu < 0)
return cpu;
msr = rd->msrs[rp->id];
if (rdmsrl_safe_on_cpu(cpu, msr, &msr_val)) {
dev_dbg(&rd->power_zone.dev,
"failed to read msr 0x%x on cpu %d\n", msr, cpu);
return -EIO;
}
value = rapl_unit_xlate(rd, rd->package_id, rp->unit, value, 1);
msr_val &= ~rp->mask;
msr_val |= value << rp->shift;
if (wrmsrl_safe_on_cpu(cpu, msr, msr_val)) {
dev_dbg(&rd->power_zone.dev,
"failed to write msr 0x%x on cpu %d\n", msr, cpu);
return -EIO;
}
return 0;
}
static int rapl_check_unit_core(struct rapl_package *rp, int cpu)
{
u64 msr_val;
u32 value;
if (rdmsrl_safe_on_cpu(cpu, MSR_RAPL_POWER_UNIT, &msr_val)) {
pr_err("Failed to read power unit MSR 0x%x on CPU %d, exit.\n",
MSR_RAPL_POWER_UNIT, cpu);
return -ENODEV;
}
value = (msr_val & ENERGY_UNIT_MASK) >> ENERGY_UNIT_OFFSET;
rp->energy_unit = ENERGY_UNIT_SCALE * 1000000 / (1 << value);
value = (msr_val & POWER_UNIT_MASK) >> POWER_UNIT_OFFSET;
rp->power_unit = 1000000 / (1 << value);
value = (msr_val & TIME_UNIT_MASK) >> TIME_UNIT_OFFSET;
rp->time_unit = 1000000 / (1 << value);
pr_debug("Core CPU package %d energy=%dpJ, time=%dus, power=%duW\n",
rp->id, rp->energy_unit, rp->time_unit, rp->power_unit);
return 0;
}
static int rapl_check_unit_atom(struct rapl_package *rp, int cpu)
{
u64 msr_val;
u32 value;
if (rdmsrl_safe_on_cpu(cpu, MSR_RAPL_POWER_UNIT, &msr_val)) {
pr_err("Failed to read power unit MSR 0x%x on CPU %d, exit.\n",
MSR_RAPL_POWER_UNIT, cpu);
return -ENODEV;
}
value = (msr_val & ENERGY_UNIT_MASK) >> ENERGY_UNIT_OFFSET;
rp->energy_unit = ENERGY_UNIT_SCALE * 1 << value;
value = (msr_val & POWER_UNIT_MASK) >> POWER_UNIT_OFFSET;
rp->power_unit = (1 << value) * 1000;
value = (msr_val & TIME_UNIT_MASK) >> TIME_UNIT_OFFSET;
rp->time_unit = 1000000 / (1 << value);
pr_debug("Atom package %d energy=%dpJ, time=%dus, power=%duW\n",
rp->id, rp->energy_unit, rp->time_unit, rp->power_unit);
return 0;
}
static void package_power_limit_irq_save(int package_id)
{
u32 l, h = 0;
int cpu;
struct rapl_package *rp;
rp = find_package_by_id(package_id);
if (!rp)
return;
if (!boot_cpu_has(X86_FEATURE_PTS) || !boot_cpu_has(X86_FEATURE_PLN))
return;
cpu = find_active_cpu_on_package(package_id);
if (cpu < 0)
return;
rdmsr_safe_on_cpu(cpu, MSR_IA32_PACKAGE_THERM_INTERRUPT, &l, &h);
if (!(rp->power_limit_irq & PACKAGE_PLN_INT_SAVED)) {
rp->power_limit_irq = l & PACKAGE_THERM_INT_PLN_ENABLE;
rp->power_limit_irq |= PACKAGE_PLN_INT_SAVED;
}
l &= ~PACKAGE_THERM_INT_PLN_ENABLE;
wrmsr_on_cpu(cpu, MSR_IA32_PACKAGE_THERM_INTERRUPT, l, h);
}
static void package_power_limit_irq_restore(int package_id)
{
u32 l, h;
int cpu;
struct rapl_package *rp;
rp = find_package_by_id(package_id);
if (!rp)
return;
if (!boot_cpu_has(X86_FEATURE_PTS) || !boot_cpu_has(X86_FEATURE_PLN))
return;
cpu = find_active_cpu_on_package(package_id);
if (cpu < 0)
return;
if (!(rp->power_limit_irq & PACKAGE_PLN_INT_SAVED))
return;
rdmsr_safe_on_cpu(cpu, MSR_IA32_PACKAGE_THERM_INTERRUPT, &l, &h);
if (rp->power_limit_irq & PACKAGE_THERM_INT_PLN_ENABLE)
l |= PACKAGE_THERM_INT_PLN_ENABLE;
else
l &= ~PACKAGE_THERM_INT_PLN_ENABLE;
wrmsr_on_cpu(cpu, MSR_IA32_PACKAGE_THERM_INTERRUPT, l, h);
}
static void set_floor_freq_default(struct rapl_domain *rd, bool mode)
{
int nr_powerlimit = find_nr_power_limit(rd);
rapl_write_data_raw(rd, PL1_CLAMP, mode);
if (nr_powerlimit > 1) {
rapl_write_data_raw(rd, PL2_ENABLE, mode);
rapl_write_data_raw(rd, PL2_CLAMP, mode);
}
}
static void set_floor_freq_atom(struct rapl_domain *rd, bool enable)
{
static u32 power_ctrl_orig_val;
u32 mdata;
if (!power_ctrl_orig_val)
iosf_mbi_read(BT_MBI_UNIT_PMC, BT_MBI_PMC_READ,
IOSF_CPU_POWER_BUDGET_CTL, &power_ctrl_orig_val);
mdata = power_ctrl_orig_val;
if (enable) {
mdata &= ~(0x7f << 8);
mdata |= 1 << 8;
}
iosf_mbi_write(BT_MBI_UNIT_PMC, BT_MBI_PMC_WRITE,
IOSF_CPU_POWER_BUDGET_CTL, mdata);
}
static u64 rapl_compute_time_window_core(struct rapl_package *rp, u64 value,
bool to_raw)
{
u64 f, y;
if (!to_raw) {
f = (value & 0x60) >> 5;
y = value & 0x1f;
value = (1 << y) * (4 + f) * rp->time_unit / 4;
} else {
do_div(value, rp->time_unit);
y = ilog2(value);
f = div64_u64(4 * (value - (1 << y)), 1 << y);
value = (y & 0x1f) | ((f & 0x3) << 5);
}
return value;
}
static u64 rapl_compute_time_window_atom(struct rapl_package *rp, u64 value,
bool to_raw)
{
if (!to_raw)
return (value) ? value *= rp->time_unit : rp->time_unit;
else
value = div64_u64(value, rp->time_unit);
return value;
}
static void rapl_update_domain_data(void)
{
int dmn, prim;
u64 val;
struct rapl_package *rp;
list_for_each_entry(rp, &rapl_packages, plist) {
for (dmn = 0; dmn < rp->nr_domains; dmn++) {
pr_debug("update package %d domain %s data\n", rp->id,
rp->domains[dmn].name);
for (prim = 0; prim < NR_RAW_PRIMITIVES; prim++)
if (!rapl_read_data_raw(&rp->domains[dmn], prim,
rpi[prim].unit,
&val))
rp->domains[dmn].rdd.primitives[prim] =
val;
}
}
}
static int rapl_unregister_powercap(void)
{
struct rapl_package *rp;
struct rapl_domain *rd, *rd_package = NULL;
list_for_each_entry(rp, &rapl_packages, plist) {
package_power_limit_irq_restore(rp->id);
for (rd = rp->domains; rd < rp->domains + rp->nr_domains;
rd++) {
pr_debug("remove package, undo power limit on %d: %s\n",
rp->id, rd->name);
rapl_write_data_raw(rd, PL1_ENABLE, 0);
rapl_write_data_raw(rd, PL2_ENABLE, 0);
rapl_write_data_raw(rd, PL1_CLAMP, 0);
rapl_write_data_raw(rd, PL2_CLAMP, 0);
if (rd->id == RAPL_DOMAIN_PACKAGE) {
rd_package = rd;
continue;
}
powercap_unregister_zone(control_type, &rd->power_zone);
}
if (rd_package)
powercap_unregister_zone(control_type,
&rd_package->power_zone);
}
powercap_unregister_control_type(control_type);
return 0;
}
static int rapl_package_register_powercap(struct rapl_package *rp)
{
struct rapl_domain *rd;
int ret = 0;
char dev_name[17];
struct powercap_zone *power_zone = NULL;
int nr_pl;
for (rd = rp->domains; rd < rp->domains + rp->nr_domains; rd++) {
if (rd->id == RAPL_DOMAIN_PACKAGE) {
nr_pl = find_nr_power_limit(rd);
pr_debug("register socket %d package domain %s\n",
rp->id, rd->name);
memset(dev_name, 0, sizeof(dev_name));
snprintf(dev_name, sizeof(dev_name), "%s-%d",
rd->name, rp->id);
power_zone = powercap_register_zone(&rd->power_zone,
control_type,
dev_name, NULL,
&zone_ops[rd->id],
nr_pl,
&constraint_ops);
if (IS_ERR(power_zone)) {
pr_debug("failed to register package, %d\n",
rp->id);
ret = PTR_ERR(power_zone);
goto exit_package;
}
rp->power_zone = power_zone;
break;
}
}
if (!power_zone) {
pr_err("no package domain found, unknown topology!\n");
ret = -ENODEV;
goto exit_package;
}
for (rd = rp->domains; rd < rp->domains + rp->nr_domains; rd++) {
if (rd->id == RAPL_DOMAIN_PACKAGE)
continue;
nr_pl = find_nr_power_limit(rd);
power_zone = powercap_register_zone(&rd->power_zone,
control_type, rd->name,
rp->power_zone,
&zone_ops[rd->id], nr_pl,
&constraint_ops);
if (IS_ERR(power_zone)) {
pr_debug("failed to register power_zone, %d:%s:%s\n",
rp->id, rd->name, dev_name);
ret = PTR_ERR(power_zone);
goto err_cleanup;
}
}
exit_package:
return ret;
err_cleanup:
while (--rd >= rp->domains) {
pr_debug("unregister package %d domain %s\n", rp->id, rd->name);
powercap_unregister_zone(control_type, &rd->power_zone);
}
return ret;
}
static int rapl_register_powercap(void)
{
struct rapl_domain *rd;
struct rapl_package *rp;
int ret = 0;
control_type = powercap_register_control_type(NULL, "intel-rapl", NULL);
if (IS_ERR(control_type)) {
pr_debug("failed to register powercap control_type.\n");
return PTR_ERR(control_type);
}
rapl_update_domain_data();
list_for_each_entry(rp, &rapl_packages, plist)
if (rapl_package_register_powercap(rp))
goto err_cleanup_package;
return ret;
err_cleanup_package:
list_for_each_entry_continue_reverse(rp, &rapl_packages, plist) {
for (rd = rp->domains; rd < rp->domains + rp->nr_domains;
rd++) {
pr_debug("unregister zone/package %d, %s domain\n",
rp->id, rd->name);
powercap_unregister_zone(control_type, &rd->power_zone);
}
}
return ret;
}
static int rapl_check_domain(int cpu, int domain)
{
unsigned msr;
u64 val = 0;
switch (domain) {
case RAPL_DOMAIN_PACKAGE:
msr = MSR_PKG_ENERGY_STATUS;
break;
case RAPL_DOMAIN_PP0:
msr = MSR_PP0_ENERGY_STATUS;
break;
case RAPL_DOMAIN_PP1:
msr = MSR_PP1_ENERGY_STATUS;
break;
case RAPL_DOMAIN_DRAM:
msr = MSR_DRAM_ENERGY_STATUS;
break;
default:
pr_err("invalid domain id %d\n", domain);
return -EINVAL;
}
if (rdmsrl_safe_on_cpu(cpu, msr, &val) || !val)
return -ENODEV;
return 0;
}
static int rapl_detect_domains(struct rapl_package *rp, int cpu)
{
int i;
int ret = 0;
struct rapl_domain *rd;
u64 locked;
for (i = 0; i < RAPL_DOMAIN_MAX; i++) {
if (!rapl_check_domain(cpu, i)) {
rp->domain_map |= 1 << i;
pr_info("Found RAPL domain %s\n", rapl_domain_names[i]);
}
}
rp->nr_domains = bitmap_weight(&rp->domain_map, RAPL_DOMAIN_MAX);
if (!rp->nr_domains) {
pr_err("no valid rapl domains found in package %d\n", rp->id);
ret = -ENODEV;
goto done;
}
pr_debug("found %d domains on package %d\n", rp->nr_domains, rp->id);
rp->domains = kcalloc(rp->nr_domains + 1, sizeof(struct rapl_domain),
GFP_KERNEL);
if (!rp->domains) {
ret = -ENOMEM;
goto done;
}
rapl_init_domains(rp);
for (rd = rp->domains; rd < rp->domains + rp->nr_domains; rd++) {
if (rapl_read_data_raw(rd, FW_LOCK, false, &locked)) {
pr_info("RAPL package %d domain %s locked by BIOS\n",
rp->id, rd->name);
rd->state |= DOMAIN_STATE_BIOS_LOCKED;
}
}
done:
return ret;
}
static bool is_package_new(int package)
{
struct rapl_package *rp;
list_for_each_entry(rp, &rapl_packages, plist)
if (package == rp->id)
return false;
return true;
}
static int rapl_detect_topology(void)
{
int i;
int phy_package_id;
struct rapl_package *new_package, *rp;
for_each_online_cpu(i) {
phy_package_id = topology_physical_package_id(i);
if (is_package_new(phy_package_id)) {
new_package = kzalloc(sizeof(*rp), GFP_KERNEL);
if (!new_package) {
rapl_cleanup_data();
return -ENOMEM;
}
new_package->id = phy_package_id;
new_package->nr_cpus = 1;
if (rapl_detect_domains(new_package, i) ||
rapl_defaults->check_unit(new_package, i)) {
kfree(new_package->domains);
kfree(new_package);
rapl_cleanup_data();
return -ENODEV;
}
INIT_LIST_HEAD(&new_package->plist);
list_add(&new_package->plist, &rapl_packages);
} else {
rp = find_package_by_id(phy_package_id);
if (rp)
++rp->nr_cpus;
}
}
return 0;
}
static void rapl_remove_package(struct rapl_package *rp)
{
struct rapl_domain *rd, *rd_package = NULL;
for (rd = rp->domains; rd < rp->domains + rp->nr_domains; rd++) {
if (rd->id == RAPL_DOMAIN_PACKAGE) {
rd_package = rd;
continue;
}
pr_debug("remove package %d, %s domain\n", rp->id, rd->name);
powercap_unregister_zone(control_type, &rd->power_zone);
}
powercap_unregister_zone(control_type, &rd_package->power_zone);
list_del(&rp->plist);
kfree(rp);
}
static int rapl_add_package(int cpu)
{
int ret = 0;
int phy_package_id;
struct rapl_package *rp;
phy_package_id = topology_physical_package_id(cpu);
rp = kzalloc(sizeof(struct rapl_package), GFP_KERNEL);
if (!rp)
return -ENOMEM;
rp->id = phy_package_id;
rp->nr_cpus = 1;
if (rapl_detect_domains(rp, cpu) ||
rapl_defaults->check_unit(rp, cpu)) {
ret = -ENODEV;
goto err_free_package;
}
if (!rapl_package_register_powercap(rp)) {
INIT_LIST_HEAD(&rp->plist);
list_add(&rp->plist, &rapl_packages);
return ret;
}
err_free_package:
kfree(rp->domains);
kfree(rp);
return ret;
}
static int rapl_cpu_callback(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
unsigned long cpu = (unsigned long)hcpu;
int phy_package_id;
struct rapl_package *rp;
phy_package_id = topology_physical_package_id(cpu);
switch (action) {
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
case CPU_DOWN_FAILED:
case CPU_DOWN_FAILED_FROZEN:
rp = find_package_by_id(phy_package_id);
if (rp)
++rp->nr_cpus;
else
rapl_add_package(cpu);
break;
case CPU_DOWN_PREPARE:
case CPU_DOWN_PREPARE_FROZEN:
rp = find_package_by_id(phy_package_id);
if (!rp)
break;
if (--rp->nr_cpus == 0)
rapl_remove_package(rp);
}
return NOTIFY_OK;
}
static int __init rapl_init(void)
{
int ret = 0;
const struct x86_cpu_id *id;
id = x86_match_cpu(rapl_ids);
if (!id) {
pr_err("driver does not support CPU family %d model %d\n",
boot_cpu_data.x86, boot_cpu_data.x86_model);
return -ENODEV;
}
rapl_defaults = (struct rapl_defaults *)id->driver_data;
cpu_notifier_register_begin();
get_online_cpus();
ret = rapl_detect_topology();
if (ret)
goto done;
if (rapl_register_powercap()) {
rapl_cleanup_data();
ret = -ENODEV;
goto done;
}
__register_hotcpu_notifier(&rapl_cpu_notifier);
done:
put_online_cpus();
cpu_notifier_register_done();
return ret;
}
static void __exit rapl_exit(void)
{
cpu_notifier_register_begin();
get_online_cpus();
__unregister_hotcpu_notifier(&rapl_cpu_notifier);
rapl_unregister_powercap();
rapl_cleanup_data();
put_online_cpus();
cpu_notifier_register_done();
}
