static void __init octeon_irq_set_ciu_mapping(int irq, int line, int bit,
struct irq_chip *chip,
irq_flow_handler_t handler)
{
union octeon_ciu_chip_data cd;
irq_set_chip_and_handler(irq, chip, handler);
cd.l = 0;
cd.s.line = line;
cd.s.bit = bit;
irq_set_chip_data(irq, cd.p);
octeon_irq_ciu_to_irq[line][bit] = irq;
}
static int octeon_coreid_for_cpu(int cpu)
{
#ifdef CONFIG_SMP
return cpu_logical_map(cpu);
#else
return cvmx_get_core_num();
#endif
}
static int octeon_cpu_for_coreid(int coreid)
{
#ifdef CONFIG_SMP
return cpu_number_map(coreid);
#else
return smp_processor_id();
#endif
}
static void octeon_irq_core_ack(struct irq_data *data)
{
struct octeon_core_chip_data *cd = irq_data_get_irq_chip_data(data);
unsigned int bit = cd->bit;
clear_c0_status(0x100 << bit);
if (bit < 2)
clear_c0_cause(0x100 << bit);
}
static void octeon_irq_core_eoi(struct irq_data *data)
{
struct octeon_core_chip_data *cd = irq_data_get_irq_chip_data(data);
set_c0_status(0x100 << cd->bit);
}
static void octeon_irq_core_set_enable_local(void *arg)
{
struct irq_data *data = arg;
struct octeon_core_chip_data *cd = irq_data_get_irq_chip_data(data);
unsigned int mask = 0x100 << cd->bit;
if (cd->desired_en)
set_c0_status(mask);
else
clear_c0_status(mask);
}
static void octeon_irq_core_disable(struct irq_data *data)
{
struct octeon_core_chip_data *cd = irq_data_get_irq_chip_data(data);
cd->desired_en = false;
}
static void octeon_irq_core_enable(struct irq_data *data)
{
struct octeon_core_chip_data *cd = irq_data_get_irq_chip_data(data);
cd->desired_en = true;
}
static void octeon_irq_core_bus_lock(struct irq_data *data)
{
struct octeon_core_chip_data *cd = irq_data_get_irq_chip_data(data);
mutex_lock(&cd->core_irq_mutex);
}
static void octeon_irq_core_bus_sync_unlock(struct irq_data *data)
{
struct octeon_core_chip_data *cd = irq_data_get_irq_chip_data(data);
if (cd->desired_en != cd->current_en) {
on_each_cpu(octeon_irq_core_set_enable_local, data, 1);
cd->current_en = cd->desired_en;
}
mutex_unlock(&cd->core_irq_mutex);
}
static void __init octeon_irq_init_core(void)
{
int i;
int irq;
struct octeon_core_chip_data *cd;
for (i = 0; i < MIPS_CORE_IRQ_LINES; i++) {
cd = &octeon_irq_core_chip_data[i];
cd->current_en = false;
cd->desired_en = false;
cd->bit = i;
mutex_init(&cd->core_irq_mutex);
irq = OCTEON_IRQ_SW0 + i;
switch (irq) {
case OCTEON_IRQ_TIMER:
case OCTEON_IRQ_SW0:
case OCTEON_IRQ_SW1:
case OCTEON_IRQ_5:
case OCTEON_IRQ_PERF:
irq_set_chip_data(irq, cd);
irq_set_chip_and_handler(irq, &octeon_irq_chip_core,
handle_percpu_irq);
break;
default:
break;
}
}
}
static int next_cpu_for_irq(struct irq_data *data)
{
#ifdef CONFIG_SMP
int cpu;
int weight = cpumask_weight(data->affinity);
if (weight > 1) {
cpu = smp_processor_id();
for (;;) {
cpu = cpumask_next(cpu, data->affinity);
if (cpu >= nr_cpu_ids) {
cpu = -1;
continue;
} else if (cpumask_test_cpu(cpu, cpu_online_mask)) {
break;
}
}
} else if (weight == 1) {
cpu = cpumask_first(data->affinity);
} else {
cpu = smp_processor_id();
}
return cpu;
#else
return smp_processor_id();
#endif
}
static void octeon_irq_ciu_enable(struct irq_data *data)
{
int cpu = next_cpu_for_irq(data);
int coreid = octeon_coreid_for_cpu(cpu);
unsigned long *pen;
unsigned long flags;
union octeon_ciu_chip_data cd;
cd.p = irq_data_get_irq_chip_data(data);
if (cd.s.line == 0) {
raw_spin_lock_irqsave(&octeon_irq_ciu0_lock, flags);
pen = &per_cpu(octeon_irq_ciu0_en_mirror, cpu);
set_bit(cd.s.bit, pen);
cvmx_write_csr(CVMX_CIU_INTX_EN0(coreid * 2), *pen);
raw_spin_unlock_irqrestore(&octeon_irq_ciu0_lock, flags);
} else {
raw_spin_lock_irqsave(&octeon_irq_ciu1_lock, flags);
pen = &per_cpu(octeon_irq_ciu1_en_mirror, cpu);
set_bit(cd.s.bit, pen);
cvmx_write_csr(CVMX_CIU_INTX_EN1(coreid * 2 + 1), *pen);
raw_spin_unlock_irqrestore(&octeon_irq_ciu1_lock, flags);
}
}
static void octeon_irq_ciu_enable_local(struct irq_data *data)
{
unsigned long *pen;
unsigned long flags;
union octeon_ciu_chip_data cd;
cd.p = irq_data_get_irq_chip_data(data);
if (cd.s.line == 0) {
raw_spin_lock_irqsave(&octeon_irq_ciu0_lock, flags);
pen = &__get_cpu_var(octeon_irq_ciu0_en_mirror);
set_bit(cd.s.bit, pen);
cvmx_write_csr(CVMX_CIU_INTX_EN0(cvmx_get_core_num() * 2), *pen);
raw_spin_unlock_irqrestore(&octeon_irq_ciu0_lock, flags);
} else {
raw_spin_lock_irqsave(&octeon_irq_ciu1_lock, flags);
pen = &__get_cpu_var(octeon_irq_ciu1_en_mirror);
set_bit(cd.s.bit, pen);
cvmx_write_csr(CVMX_CIU_INTX_EN1(cvmx_get_core_num() * 2 + 1), *pen);
raw_spin_unlock_irqrestore(&octeon_irq_ciu1_lock, flags);
}
}
static void octeon_irq_ciu_disable_local(struct irq_data *data)
{
unsigned long *pen;
unsigned long flags;
union octeon_ciu_chip_data cd;
cd.p = irq_data_get_irq_chip_data(data);
if (cd.s.line == 0) {
raw_spin_lock_irqsave(&octeon_irq_ciu0_lock, flags);
pen = &__get_cpu_var(octeon_irq_ciu0_en_mirror);
clear_bit(cd.s.bit, pen);
cvmx_write_csr(CVMX_CIU_INTX_EN0(cvmx_get_core_num() * 2), *pen);
raw_spin_unlock_irqrestore(&octeon_irq_ciu0_lock, flags);
} else {
raw_spin_lock_irqsave(&octeon_irq_ciu1_lock, flags);
pen = &__get_cpu_var(octeon_irq_ciu1_en_mirror);
clear_bit(cd.s.bit, pen);
cvmx_write_csr(CVMX_CIU_INTX_EN1(cvmx_get_core_num() * 2 + 1), *pen);
raw_spin_unlock_irqrestore(&octeon_irq_ciu1_lock, flags);
}
}
static void octeon_irq_ciu_disable_all(struct irq_data *data)
{
unsigned long flags;
unsigned long *pen;
int cpu;
union octeon_ciu_chip_data cd;
wmb();
cd.p = irq_data_get_irq_chip_data(data);
if (cd.s.line == 0) {
raw_spin_lock_irqsave(&octeon_irq_ciu0_lock, flags);
for_each_online_cpu(cpu) {
int coreid = octeon_coreid_for_cpu(cpu);
pen = &per_cpu(octeon_irq_ciu0_en_mirror, cpu);
clear_bit(cd.s.bit, pen);
cvmx_write_csr(CVMX_CIU_INTX_EN0(coreid * 2), *pen);
}
raw_spin_unlock_irqrestore(&octeon_irq_ciu0_lock, flags);
} else {
raw_spin_lock_irqsave(&octeon_irq_ciu1_lock, flags);
for_each_online_cpu(cpu) {
int coreid = octeon_coreid_for_cpu(cpu);
pen = &per_cpu(octeon_irq_ciu1_en_mirror, cpu);
clear_bit(cd.s.bit, pen);
cvmx_write_csr(CVMX_CIU_INTX_EN1(coreid * 2 + 1), *pen);
}
raw_spin_unlock_irqrestore(&octeon_irq_ciu1_lock, flags);
}
}
static void octeon_irq_ciu_enable_all(struct irq_data *data)
{
unsigned long flags;
unsigned long *pen;
int cpu;
union octeon_ciu_chip_data cd;
cd.p = irq_data_get_irq_chip_data(data);
if (cd.s.line == 0) {
raw_spin_lock_irqsave(&octeon_irq_ciu0_lock, flags);
for_each_online_cpu(cpu) {
int coreid = octeon_coreid_for_cpu(cpu);
pen = &per_cpu(octeon_irq_ciu0_en_mirror, cpu);
set_bit(cd.s.bit, pen);
cvmx_write_csr(CVMX_CIU_INTX_EN0(coreid * 2), *pen);
}
raw_spin_unlock_irqrestore(&octeon_irq_ciu0_lock, flags);
} else {
raw_spin_lock_irqsave(&octeon_irq_ciu1_lock, flags);
for_each_online_cpu(cpu) {
int coreid = octeon_coreid_for_cpu(cpu);
pen = &per_cpu(octeon_irq_ciu1_en_mirror, cpu);
set_bit(cd.s.bit, pen);
cvmx_write_csr(CVMX_CIU_INTX_EN1(coreid * 2 + 1), *pen);
}
raw_spin_unlock_irqrestore(&octeon_irq_ciu1_lock, flags);
}
}
static void octeon_irq_ciu_enable_v2(struct irq_data *data)
{
u64 mask;
int cpu = next_cpu_for_irq(data);
union octeon_ciu_chip_data cd;
cd.p = irq_data_get_irq_chip_data(data);
mask = 1ull << (cd.s.bit);
if (cd.s.line == 0) {
int index = octeon_coreid_for_cpu(cpu) * 2;
set_bit(cd.s.bit, &per_cpu(octeon_irq_ciu0_en_mirror, cpu));
cvmx_write_csr(CVMX_CIU_INTX_EN0_W1S(index), mask);
} else {
int index = octeon_coreid_for_cpu(cpu) * 2 + 1;
set_bit(cd.s.bit, &per_cpu(octeon_irq_ciu1_en_mirror, cpu));
cvmx_write_csr(CVMX_CIU_INTX_EN1_W1S(index), mask);
}
}
static void octeon_irq_ciu_enable_local_v2(struct irq_data *data)
{
u64 mask;
union octeon_ciu_chip_data cd;
cd.p = irq_data_get_irq_chip_data(data);
mask = 1ull << (cd.s.bit);
if (cd.s.line == 0) {
int index = cvmx_get_core_num() * 2;
set_bit(cd.s.bit, &__get_cpu_var(octeon_irq_ciu0_en_mirror));
cvmx_write_csr(CVMX_CIU_INTX_EN0_W1S(index), mask);
} else {
int index = cvmx_get_core_num() * 2 + 1;
set_bit(cd.s.bit, &__get_cpu_var(octeon_irq_ciu1_en_mirror));
cvmx_write_csr(CVMX_CIU_INTX_EN1_W1S(index), mask);
}
}
static void octeon_irq_ciu_disable_local_v2(struct irq_data *data)
{
u64 mask;
union octeon_ciu_chip_data cd;
cd.p = irq_data_get_irq_chip_data(data);
mask = 1ull << (cd.s.bit);
if (cd.s.line == 0) {
int index = cvmx_get_core_num() * 2;
clear_bit(cd.s.bit, &__get_cpu_var(octeon_irq_ciu0_en_mirror));
cvmx_write_csr(CVMX_CIU_INTX_EN0_W1C(index), mask);
} else {
int index = cvmx_get_core_num() * 2 + 1;
clear_bit(cd.s.bit, &__get_cpu_var(octeon_irq_ciu1_en_mirror));
cvmx_write_csr(CVMX_CIU_INTX_EN1_W1C(index), mask);
}
}
static void octeon_irq_ciu_ack(struct irq_data *data)
{
u64 mask;
union octeon_ciu_chip_data cd;
cd.p = data->chip_data;
mask = 1ull << (cd.s.bit);
if (cd.s.line == 0) {
int index = cvmx_get_core_num() * 2;
cvmx_write_csr(CVMX_CIU_INTX_SUM0(index), mask);
} else {
cvmx_write_csr(CVMX_CIU_INT_SUM1, mask);
}
}
static void octeon_irq_ciu_disable_all_v2(struct irq_data *data)
{
int cpu;
u64 mask;
union octeon_ciu_chip_data cd;
wmb();
cd.p = data->chip_data;
mask = 1ull << (cd.s.bit);
if (cd.s.line == 0) {
for_each_online_cpu(cpu) {
int index = octeon_coreid_for_cpu(cpu) * 2;
clear_bit(cd.s.bit, &per_cpu(octeon_irq_ciu0_en_mirror, cpu));
cvmx_write_csr(CVMX_CIU_INTX_EN0_W1C(index), mask);
}
} else {
for_each_online_cpu(cpu) {
int index = octeon_coreid_for_cpu(cpu) * 2 + 1;
clear_bit(cd.s.bit, &per_cpu(octeon_irq_ciu1_en_mirror, cpu));
cvmx_write_csr(CVMX_CIU_INTX_EN1_W1C(index), mask);
}
}
}
static void octeon_irq_ciu_enable_all_v2(struct irq_data *data)
{
int cpu;
u64 mask;
union octeon_ciu_chip_data cd;
cd.p = data->chip_data;
mask = 1ull << (cd.s.bit);
if (cd.s.line == 0) {
for_each_online_cpu(cpu) {
int index = octeon_coreid_for_cpu(cpu) * 2;
set_bit(cd.s.bit, &per_cpu(octeon_irq_ciu0_en_mirror, cpu));
cvmx_write_csr(CVMX_CIU_INTX_EN0_W1S(index), mask);
}
} else {
for_each_online_cpu(cpu) {
int index = octeon_coreid_for_cpu(cpu) * 2 + 1;
set_bit(cd.s.bit, &per_cpu(octeon_irq_ciu1_en_mirror, cpu));
cvmx_write_csr(CVMX_CIU_INTX_EN1_W1S(index), mask);
}
}
}
static void octeon_irq_cpu_offline_ciu(struct irq_data *data)
{
int cpu = smp_processor_id();
cpumask_t new_affinity;
if (!cpumask_test_cpu(cpu, data->affinity))
return;
if (cpumask_weight(data->affinity) > 1) {
cpumask_copy(&new_affinity, data->affinity);
cpumask_clear_cpu(cpu, &new_affinity);
} else {
cpumask_clear(&new_affinity);
cpumask_set_cpu(cpumask_first(cpu_online_mask), &new_affinity);
}
__irq_set_affinity_locked(data, &new_affinity);
}
static int octeon_irq_ciu_set_affinity(struct irq_data *data,
const struct cpumask *dest, bool force)
{
int cpu;
bool enable_one = !irqd_irq_disabled(data) && !irqd_irq_masked(data);
unsigned long flags;
union octeon_ciu_chip_data cd;
cd.p = data->chip_data;
if (cpumask_weight(dest) != 1)
return -EINVAL;
if (!enable_one)
return 0;
if (cd.s.line == 0) {
raw_spin_lock_irqsave(&octeon_irq_ciu0_lock, flags);
for_each_online_cpu(cpu) {
int coreid = octeon_coreid_for_cpu(cpu);
unsigned long *pen = &per_cpu(octeon_irq_ciu0_en_mirror, cpu);
if (cpumask_test_cpu(cpu, dest) && enable_one) {
enable_one = false;
set_bit(cd.s.bit, pen);
} else {
clear_bit(cd.s.bit, pen);
}
cvmx_write_csr(CVMX_CIU_INTX_EN0(coreid * 2), *pen);
}
raw_spin_unlock_irqrestore(&octeon_irq_ciu0_lock, flags);
} else {
raw_spin_lock_irqsave(&octeon_irq_ciu1_lock, flags);
for_each_online_cpu(cpu) {
int coreid = octeon_coreid_for_cpu(cpu);
unsigned long *pen = &per_cpu(octeon_irq_ciu1_en_mirror, cpu);
if (cpumask_test_cpu(cpu, dest) && enable_one) {
enable_one = false;
set_bit(cd.s.bit, pen);
} else {
clear_bit(cd.s.bit, pen);
}
cvmx_write_csr(CVMX_CIU_INTX_EN1(coreid * 2 + 1), *pen);
}
raw_spin_unlock_irqrestore(&octeon_irq_ciu1_lock, flags);
}
return 0;
}
static int octeon_irq_ciu_set_affinity_v2(struct irq_data *data,
const struct cpumask *dest,
bool force)
{
int cpu;
bool enable_one = !irqd_irq_disabled(data) && !irqd_irq_masked(data);
u64 mask;
union octeon_ciu_chip_data cd;
if (!enable_one)
return 0;
cd.p = data->chip_data;
mask = 1ull << cd.s.bit;
if (cd.s.line == 0) {
for_each_online_cpu(cpu) {
unsigned long *pen = &per_cpu(octeon_irq_ciu0_en_mirror, cpu);
int index = octeon_coreid_for_cpu(cpu) * 2;
if (cpumask_test_cpu(cpu, dest) && enable_one) {
enable_one = false;
set_bit(cd.s.bit, pen);
cvmx_write_csr(CVMX_CIU_INTX_EN0_W1S(index), mask);
} else {
clear_bit(cd.s.bit, pen);
cvmx_write_csr(CVMX_CIU_INTX_EN0_W1C(index), mask);
}
}
} else {
for_each_online_cpu(cpu) {
unsigned long *pen = &per_cpu(octeon_irq_ciu1_en_mirror, cpu);
int index = octeon_coreid_for_cpu(cpu) * 2 + 1;
if (cpumask_test_cpu(cpu, dest) && enable_one) {
enable_one = false;
set_bit(cd.s.bit, pen);
cvmx_write_csr(CVMX_CIU_INTX_EN1_W1S(index), mask);
} else {
clear_bit(cd.s.bit, pen);
cvmx_write_csr(CVMX_CIU_INTX_EN1_W1C(index), mask);
}
}
}
return 0;
}
static void octeon_irq_dummy_mask(struct irq_data *data)
{
}
static void octeon_irq_ciu_wd_enable(struct irq_data *data)
{
unsigned long flags;
unsigned long *pen;
int coreid = data->irq - OCTEON_IRQ_WDOG0;
int cpu = octeon_cpu_for_coreid(coreid);
raw_spin_lock_irqsave(&octeon_irq_ciu1_lock, flags);
pen = &per_cpu(octeon_irq_ciu1_en_mirror, cpu);
set_bit(coreid, pen);
cvmx_write_csr(CVMX_CIU_INTX_EN1(coreid * 2 + 1), *pen);
raw_spin_unlock_irqrestore(&octeon_irq_ciu1_lock, flags);
}
static void octeon_irq_ciu1_wd_enable_v2(struct irq_data *data)
{
int coreid = data->irq - OCTEON_IRQ_WDOG0;
int cpu = octeon_cpu_for_coreid(coreid);
set_bit(coreid, &per_cpu(octeon_irq_ciu1_en_mirror, cpu));
cvmx_write_csr(CVMX_CIU_INTX_EN1_W1S(coreid * 2 + 1), 1ull << coreid);
}
static void octeon_irq_ip2_v1(void)
{
const unsigned long core_id = cvmx_get_core_num();
u64 ciu_sum = cvmx_read_csr(CVMX_CIU_INTX_SUM0(core_id * 2));
ciu_sum &= __get_cpu_var(octeon_irq_ciu0_en_mirror);
clear_c0_status(STATUSF_IP2);
if (likely(ciu_sum)) {
int bit = fls64(ciu_sum) - 1;
int irq = octeon_irq_ciu_to_irq[0][bit];
if (likely(irq))
do_IRQ(irq);
else
spurious_interrupt();
} else {
spurious_interrupt();
}
set_c0_status(STATUSF_IP2);
}
static void octeon_irq_ip2_v2(void)
{
const unsigned long core_id = cvmx_get_core_num();
u64 ciu_sum = cvmx_read_csr(CVMX_CIU_INTX_SUM0(core_id * 2));
ciu_sum &= __get_cpu_var(octeon_irq_ciu0_en_mirror);
if (likely(ciu_sum)) {
int bit = fls64(ciu_sum) - 1;
int irq = octeon_irq_ciu_to_irq[0][bit];
if (likely(irq))
do_IRQ(irq);
else
spurious_interrupt();
} else {
spurious_interrupt();
}
}
static void octeon_irq_ip3_v1(void)
{
u64 ciu_sum = cvmx_read_csr(CVMX_CIU_INT_SUM1);
ciu_sum &= __get_cpu_var(octeon_irq_ciu1_en_mirror);
clear_c0_status(STATUSF_IP3);
if (likely(ciu_sum)) {
int bit = fls64(ciu_sum) - 1;
int irq = octeon_irq_ciu_to_irq[1][bit];
if (likely(irq))
do_IRQ(irq);
else
spurious_interrupt();
} else {
spurious_interrupt();
}
set_c0_status(STATUSF_IP3);
}
static void octeon_irq_ip3_v2(void)
{
u64 ciu_sum = cvmx_read_csr(CVMX_CIU_INT_SUM1);
ciu_sum &= __get_cpu_var(octeon_irq_ciu1_en_mirror);
if (likely(ciu_sum)) {
int bit = fls64(ciu_sum) - 1;
int irq = octeon_irq_ciu_to_irq[1][bit];
if (likely(irq))
do_IRQ(irq);
else
spurious_interrupt();
} else {
spurious_interrupt();
}
}
static void octeon_irq_ip4_mask(void)
{
clear_c0_status(STATUSF_IP4);
spurious_interrupt();
}
static void __cpuinit octeon_irq_percpu_enable(void)
{
irq_cpu_online();
}
static void __cpuinit octeon_irq_init_ciu_percpu(void)
{
int coreid = cvmx_get_core_num();
cvmx_write_csr(CVMX_CIU_INTX_EN0((coreid * 2)), 0);
cvmx_write_csr(CVMX_CIU_INTX_EN0((coreid * 2 + 1)), 0);
cvmx_write_csr(CVMX_CIU_INTX_EN1((coreid * 2)), 0);
cvmx_write_csr(CVMX_CIU_INTX_EN1((coreid * 2 + 1)), 0);
cvmx_read_csr(CVMX_CIU_INTX_SUM0((coreid * 2)));
}
static void __cpuinit octeon_irq_setup_secondary_ciu(void)
{
__get_cpu_var(octeon_irq_ciu0_en_mirror) = 0;
__get_cpu_var(octeon_irq_ciu1_en_mirror) = 0;
octeon_irq_init_ciu_percpu();
octeon_irq_percpu_enable();
set_c0_status(STATUSF_IP3 | STATUSF_IP2);
clear_c0_status(STATUSF_IP4);
}
static void __init octeon_irq_init_ciu(void)
{
unsigned int i;
struct irq_chip *chip;
struct irq_chip *chip_edge;
struct irq_chip *chip_mbox;
struct irq_chip *chip_wd;
octeon_irq_init_ciu_percpu();
octeon_irq_setup_secondary = octeon_irq_setup_secondary_ciu;
if (OCTEON_IS_MODEL(OCTEON_CN58XX_PASS2_X) ||
OCTEON_IS_MODEL(OCTEON_CN56XX_PASS2_X) ||
OCTEON_IS_MODEL(OCTEON_CN52XX_PASS2_X) ||
OCTEON_IS_MODEL(OCTEON_CN6XXX)) {
octeon_irq_ip2 = octeon_irq_ip2_v2;
octeon_irq_ip3 = octeon_irq_ip3_v2;
chip = &octeon_irq_chip_ciu_v2;
chip_edge = &octeon_irq_chip_ciu_edge_v2;
chip_mbox = &octeon_irq_chip_ciu_mbox_v2;
chip_wd = &octeon_irq_chip_ciu_wd_v2;
} else {
octeon_irq_ip2 = octeon_irq_ip2_v1;
octeon_irq_ip3 = octeon_irq_ip3_v1;
chip = &octeon_irq_chip_ciu;
chip_edge = &octeon_irq_chip_ciu_edge;
chip_mbox = &octeon_irq_chip_ciu_mbox;
chip_wd = &octeon_irq_chip_ciu_wd;
}
octeon_irq_ip4 = octeon_irq_ip4_mask;
octeon_irq_init_core();
for (i = 0; i < 16; i++)
octeon_irq_set_ciu_mapping(i + OCTEON_IRQ_WORKQ0, 0, i + 0, chip, handle_level_irq);
for (i = 0; i < 16; i++)
octeon_irq_set_ciu_mapping(i + OCTEON_IRQ_GPIO0, 0, i + 16, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_MBOX0, 0, 32, chip_mbox, handle_percpu_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_MBOX1, 0, 33, chip_mbox, handle_percpu_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_UART0, 0, 34, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_UART1, 0, 35, chip, handle_level_irq);
for (i = 0; i < 4; i++)
octeon_irq_set_ciu_mapping(i + OCTEON_IRQ_PCI_INT0, 0, i + 36, chip, handle_level_irq);
for (i = 0; i < 4; i++)
octeon_irq_set_ciu_mapping(i + OCTEON_IRQ_PCI_MSI0, 0, i + 40, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_TWSI, 0, 45, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_RML, 0, 46, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_TRACE0, 0, 47, chip, handle_level_irq);
for (i = 0; i < 2; i++)
octeon_irq_set_ciu_mapping(i + OCTEON_IRQ_GMX_DRP0, 0, i + 48, chip_edge, handle_edge_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_IPD_DRP, 0, 50, chip_edge, handle_edge_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_KEY_ZERO, 0, 51, chip_edge, handle_edge_irq);
for (i = 0; i < 4; i++)
octeon_irq_set_ciu_mapping(i + OCTEON_IRQ_TIMER0, 0, i + 52, chip_edge, handle_edge_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_USB0, 0, 56, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_PCM, 0, 57, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_MPI, 0, 58, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_TWSI2, 0, 59, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_POWIQ, 0, 60, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_IPDPPTHR, 0, 61, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_MII0, 0, 62, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_BOOTDMA, 0, 63, chip, handle_level_irq);
for (i = 0; i < 16; i++)
octeon_irq_set_ciu_mapping(i + OCTEON_IRQ_WDOG0, 1, i + 0, chip_wd, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_UART2, 1, 16, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_USB1, 1, 17, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_MII1, 1, 18, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_NAND, 1, 19, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_MIO, 1, 20, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_IOB, 1, 21, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_FPA, 1, 22, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_POW, 1, 23, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_L2C, 1, 24, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_IPD, 1, 25, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_PIP, 1, 26, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_PKO, 1, 27, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_ZIP, 1, 28, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_TIM, 1, 29, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_RAD, 1, 30, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_KEY, 1, 31, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_DFA, 1, 32, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_USBCTL, 1, 33, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_SLI, 1, 34, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_DPI, 1, 35, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_AGX0, 1, 36, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_AGL, 1, 46, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_PTP, 1, 47, chip_edge, handle_edge_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_PEM0, 1, 48, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_PEM1, 1, 49, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_SRIO0, 1, 50, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_SRIO1, 1, 51, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_LMC0, 1, 52, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_DFM, 1, 56, chip, handle_level_irq);
octeon_irq_set_ciu_mapping(OCTEON_IRQ_RST, 1, 63, chip, handle_level_irq);
set_c0_status(STATUSF_IP3 | STATUSF_IP2);
clear_c0_status(STATUSF_IP4);
}
void __init arch_init_irq(void)
{
#ifdef CONFIG_SMP
cpumask_clear(irq_default_affinity);
cpumask_set_cpu(smp_processor_id(), irq_default_affinity);
#endif
octeon_irq_init_ciu();
}
asmlinkage void plat_irq_dispatch(void)
{
unsigned long cop0_cause;
unsigned long cop0_status;
while (1) {
cop0_cause = read_c0_cause();
cop0_status = read_c0_status();
cop0_cause &= cop0_status;
cop0_cause &= ST0_IM;
if (unlikely(cop0_cause & STATUSF_IP2))
octeon_irq_ip2();
else if (unlikely(cop0_cause & STATUSF_IP3))
octeon_irq_ip3();
else if (unlikely(cop0_cause & STATUSF_IP4))
octeon_irq_ip4();
else if (likely(cop0_cause))
do_IRQ(fls(cop0_cause) - 9 + MIPS_CPU_IRQ_BASE);
else
break;
}
}
void fixup_irqs(void)
{
irq_cpu_offline();
}
