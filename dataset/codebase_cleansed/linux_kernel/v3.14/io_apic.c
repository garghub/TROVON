int mpc_ioapic_id(int ioapic_idx)
{
return ioapics[ioapic_idx].mp_config.apicid;
}
unsigned int mpc_ioapic_addr(int ioapic_idx)
{
return ioapics[ioapic_idx].mp_config.apicaddr;
}
struct mp_ioapic_gsi *mp_ioapic_gsi_routing(int ioapic_idx)
{
return &ioapics[ioapic_idx].gsi_config;
}
void disable_ioapic_support(void)
{
#ifdef CONFIG_PCI
noioapicquirk = 1;
noioapicreroute = -1;
#endif
skip_ioapic_setup = 1;
}
static int __init parse_noapic(char *str)
{
disable_ioapic_support();
return 0;
}
void mp_save_irq(struct mpc_intsrc *m)
{
int i;
apic_printk(APIC_VERBOSE, "Int: type %d, pol %d, trig %d, bus %02x,"
" IRQ %02x, APIC ID %x, APIC INT %02x\n",
m->irqtype, m->irqflag & 3, (m->irqflag >> 2) & 3, m->srcbus,
m->srcbusirq, m->dstapic, m->dstirq);
for (i = 0; i < mp_irq_entries; i++) {
if (!memcmp(&mp_irqs[i], m, sizeof(*m)))
return;
}
memcpy(&mp_irqs[mp_irq_entries], m, sizeof(*m));
if (++mp_irq_entries == MAX_IRQ_SOURCES)
panic("Max # of irq sources exceeded!!\n");
}
static struct irq_pin_list *alloc_irq_pin_list(int node)
{
return kzalloc_node(sizeof(struct irq_pin_list), GFP_KERNEL, node);
}
int __init arch_early_irq_init(void)
{
struct irq_cfg *cfg;
int count, node, i;
if (!legacy_pic->nr_legacy_irqs)
io_apic_irqs = ~0UL;
for (i = 0; i < nr_ioapics; i++) {
ioapics[i].saved_registers =
kzalloc(sizeof(struct IO_APIC_route_entry) *
ioapics[i].nr_registers, GFP_KERNEL);
if (!ioapics[i].saved_registers)
pr_err("IOAPIC %d: suspend/resume impossible!\n", i);
}
cfg = irq_cfgx;
count = ARRAY_SIZE(irq_cfgx);
node = cpu_to_node(0);
irq_reserve_irqs(0, legacy_pic->nr_legacy_irqs);
for (i = 0; i < count; i++) {
irq_set_chip_data(i, &cfg[i]);
zalloc_cpumask_var_node(&cfg[i].domain, GFP_KERNEL, node);
zalloc_cpumask_var_node(&cfg[i].old_domain, GFP_KERNEL, node);
if (i < legacy_pic->nr_legacy_irqs) {
cfg[i].vector = IRQ0_VECTOR + i;
cpumask_setall(cfg[i].domain);
}
}
return 0;
}
static struct irq_cfg *irq_cfg(unsigned int irq)
{
return irq_get_chip_data(irq);
}
static struct irq_cfg *alloc_irq_cfg(unsigned int irq, int node)
{
struct irq_cfg *cfg;
cfg = kzalloc_node(sizeof(*cfg), GFP_KERNEL, node);
if (!cfg)
return NULL;
if (!zalloc_cpumask_var_node(&cfg->domain, GFP_KERNEL, node))
goto out_cfg;
if (!zalloc_cpumask_var_node(&cfg->old_domain, GFP_KERNEL, node))
goto out_domain;
return cfg;
out_domain:
free_cpumask_var(cfg->domain);
out_cfg:
kfree(cfg);
return NULL;
}
static void free_irq_cfg(unsigned int at, struct irq_cfg *cfg)
{
if (!cfg)
return;
irq_set_chip_data(at, NULL);
free_cpumask_var(cfg->domain);
free_cpumask_var(cfg->old_domain);
kfree(cfg);
}
static struct irq_cfg *alloc_irq_and_cfg_at(unsigned int at, int node)
{
int res = irq_alloc_desc_at(at, node);
struct irq_cfg *cfg;
if (res < 0) {
if (res != -EEXIST)
return NULL;
cfg = irq_get_chip_data(at);
if (cfg)
return cfg;
}
cfg = alloc_irq_cfg(at, node);
if (cfg)
irq_set_chip_data(at, cfg);
else
irq_free_desc(at);
return cfg;
}
static int alloc_irqs_from(unsigned int from, unsigned int count, int node)
{
return irq_alloc_descs_from(from, count, node);
}
static void free_irq_at(unsigned int at, struct irq_cfg *cfg)
{
free_irq_cfg(at, cfg);
irq_free_desc(at);
}
void io_apic_eoi(unsigned int apic, unsigned int vector)
{
struct io_apic __iomem *io_apic = io_apic_base(apic);
writel(vector, &io_apic->eoi);
}
unsigned int native_io_apic_read(unsigned int apic, unsigned int reg)
{
struct io_apic __iomem *io_apic = io_apic_base(apic);
writel(reg, &io_apic->index);
return readl(&io_apic->data);
}
void native_io_apic_write(unsigned int apic, unsigned int reg, unsigned int value)
{
struct io_apic __iomem *io_apic = io_apic_base(apic);
writel(reg, &io_apic->index);
writel(value, &io_apic->data);
}
void native_io_apic_modify(unsigned int apic, unsigned int reg, unsigned int value)
{
struct io_apic __iomem *io_apic = io_apic_base(apic);
if (sis_apic_bug)
writel(reg, &io_apic->index);
writel(value, &io_apic->data);
}
static struct IO_APIC_route_entry __ioapic_read_entry(int apic, int pin)
{
union entry_union eu;
eu.w1 = io_apic_read(apic, 0x10 + 2 * pin);
eu.w2 = io_apic_read(apic, 0x11 + 2 * pin);
return eu.entry;
}
static struct IO_APIC_route_entry ioapic_read_entry(int apic, int pin)
{
union entry_union eu;
unsigned long flags;
raw_spin_lock_irqsave(&ioapic_lock, flags);
eu.entry = __ioapic_read_entry(apic, pin);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
return eu.entry;
}
static void __ioapic_write_entry(int apic, int pin, struct IO_APIC_route_entry e)
{
union entry_union eu = {{0, 0}};
eu.entry = e;
io_apic_write(apic, 0x11 + 2*pin, eu.w2);
io_apic_write(apic, 0x10 + 2*pin, eu.w1);
}
static void ioapic_write_entry(int apic, int pin, struct IO_APIC_route_entry e)
{
unsigned long flags;
raw_spin_lock_irqsave(&ioapic_lock, flags);
__ioapic_write_entry(apic, pin, e);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
}
static void ioapic_mask_entry(int apic, int pin)
{
unsigned long flags;
union entry_union eu = { .entry.mask = 1 };
raw_spin_lock_irqsave(&ioapic_lock, flags);
io_apic_write(apic, 0x10 + 2*pin, eu.w1);
io_apic_write(apic, 0x11 + 2*pin, eu.w2);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
}
static int __add_pin_to_irq_node(struct irq_cfg *cfg, int node, int apic, int pin)
{
struct irq_pin_list **last, *entry;
last = &cfg->irq_2_pin;
for_each_irq_pin(entry, cfg->irq_2_pin) {
if (entry->apic == apic && entry->pin == pin)
return 0;
last = &entry->next;
}
entry = alloc_irq_pin_list(node);
if (!entry) {
pr_err("can not alloc irq_pin_list (%d,%d,%d)\n",
node, apic, pin);
return -ENOMEM;
}
entry->apic = apic;
entry->pin = pin;
*last = entry;
return 0;
}
static void add_pin_to_irq_node(struct irq_cfg *cfg, int node, int apic, int pin)
{
if (__add_pin_to_irq_node(cfg, node, apic, pin))
panic("IO-APIC: failed to add irq-pin. Can not proceed\n");
}
static void __init replace_pin_at_irq_node(struct irq_cfg *cfg, int node,
int oldapic, int oldpin,
int newapic, int newpin)
{
struct irq_pin_list *entry;
for_each_irq_pin(entry, cfg->irq_2_pin) {
if (entry->apic == oldapic && entry->pin == oldpin) {
entry->apic = newapic;
entry->pin = newpin;
return;
}
}
add_pin_to_irq_node(cfg, node, newapic, newpin);
}
static void __io_apic_modify_irq(struct irq_pin_list *entry,
int mask_and, int mask_or,
void (*final)(struct irq_pin_list *entry))
{
unsigned int reg, pin;
pin = entry->pin;
reg = io_apic_read(entry->apic, 0x10 + pin * 2);
reg &= mask_and;
reg |= mask_or;
io_apic_modify(entry->apic, 0x10 + pin * 2, reg);
if (final)
final(entry);
}
static void io_apic_modify_irq(struct irq_cfg *cfg,
int mask_and, int mask_or,
void (*final)(struct irq_pin_list *entry))
{
struct irq_pin_list *entry;
for_each_irq_pin(entry, cfg->irq_2_pin)
__io_apic_modify_irq(entry, mask_and, mask_or, final);
}
static void io_apic_sync(struct irq_pin_list *entry)
{
struct io_apic __iomem *io_apic;
io_apic = io_apic_base(entry->apic);
readl(&io_apic->data);
}
static void mask_ioapic(struct irq_cfg *cfg)
{
unsigned long flags;
raw_spin_lock_irqsave(&ioapic_lock, flags);
io_apic_modify_irq(cfg, ~0, IO_APIC_REDIR_MASKED, &io_apic_sync);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
}
static void mask_ioapic_irq(struct irq_data *data)
{
mask_ioapic(data->chip_data);
}
static void __unmask_ioapic(struct irq_cfg *cfg)
{
io_apic_modify_irq(cfg, ~IO_APIC_REDIR_MASKED, 0, NULL);
}
static void unmask_ioapic(struct irq_cfg *cfg)
{
unsigned long flags;
raw_spin_lock_irqsave(&ioapic_lock, flags);
__unmask_ioapic(cfg);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
}
static void unmask_ioapic_irq(struct irq_data *data)
{
unmask_ioapic(data->chip_data);
}
void native_eoi_ioapic_pin(int apic, int pin, int vector)
{
if (mpc_ioapic_ver(apic) >= 0x20) {
io_apic_eoi(apic, vector);
} else {
struct IO_APIC_route_entry entry, entry1;
entry = entry1 = __ioapic_read_entry(apic, pin);
entry1.mask = 1;
entry1.trigger = IOAPIC_EDGE;
__ioapic_write_entry(apic, pin, entry1);
__ioapic_write_entry(apic, pin, entry);
}
}
void eoi_ioapic_irq(unsigned int irq, struct irq_cfg *cfg)
{
struct irq_pin_list *entry;
unsigned long flags;
raw_spin_lock_irqsave(&ioapic_lock, flags);
for_each_irq_pin(entry, cfg->irq_2_pin)
x86_io_apic_ops.eoi_ioapic_pin(entry->apic, entry->pin,
cfg->vector);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
}
static void clear_IO_APIC_pin(unsigned int apic, unsigned int pin)
{
struct IO_APIC_route_entry entry;
entry = ioapic_read_entry(apic, pin);
if (entry.delivery_mode == dest_SMI)
return;
if (!entry.mask) {
entry.mask = 1;
ioapic_write_entry(apic, pin, entry);
entry = ioapic_read_entry(apic, pin);
}
if (entry.irr) {
unsigned long flags;
if (!entry.trigger) {
entry.trigger = IOAPIC_LEVEL;
ioapic_write_entry(apic, pin, entry);
}
raw_spin_lock_irqsave(&ioapic_lock, flags);
x86_io_apic_ops.eoi_ioapic_pin(apic, pin, entry.vector);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
}
ioapic_mask_entry(apic, pin);
entry = ioapic_read_entry(apic, pin);
if (entry.irr)
pr_err("Unable to reset IRR for apic: %d, pin :%d\n",
mpc_ioapic_id(apic), pin);
}
static void clear_IO_APIC (void)
{
int apic, pin;
for (apic = 0; apic < nr_ioapics; apic++)
for (pin = 0; pin < ioapics[apic].nr_registers; pin++)
clear_IO_APIC_pin(apic, pin);
}
static int __init ioapic_pirq_setup(char *str)
{
int i, max;
int ints[MAX_PIRQS+1];
get_options(str, ARRAY_SIZE(ints), ints);
apic_printk(APIC_VERBOSE, KERN_INFO
"PIRQ redirection, working around broken MP-BIOS.\n");
max = MAX_PIRQS;
if (ints[0] < MAX_PIRQS)
max = ints[0];
for (i = 0; i < max; i++) {
apic_printk(APIC_VERBOSE, KERN_DEBUG
"... PIRQ%d -> IRQ %d\n", i, ints[i+1]);
pirq_entries[MAX_PIRQS-i-1] = ints[i+1];
}
return 1;
}
int save_ioapic_entries(void)
{
int apic, pin;
int err = 0;
for (apic = 0; apic < nr_ioapics; apic++) {
if (!ioapics[apic].saved_registers) {
err = -ENOMEM;
continue;
}
for (pin = 0; pin < ioapics[apic].nr_registers; pin++)
ioapics[apic].saved_registers[pin] =
ioapic_read_entry(apic, pin);
}
return err;
}
void mask_ioapic_entries(void)
{
int apic, pin;
for (apic = 0; apic < nr_ioapics; apic++) {
if (!ioapics[apic].saved_registers)
continue;
for (pin = 0; pin < ioapics[apic].nr_registers; pin++) {
struct IO_APIC_route_entry entry;
entry = ioapics[apic].saved_registers[pin];
if (!entry.mask) {
entry.mask = 1;
ioapic_write_entry(apic, pin, entry);
}
}
}
}
int restore_ioapic_entries(void)
{
int apic, pin;
for (apic = 0; apic < nr_ioapics; apic++) {
if (!ioapics[apic].saved_registers)
continue;
for (pin = 0; pin < ioapics[apic].nr_registers; pin++)
ioapic_write_entry(apic, pin,
ioapics[apic].saved_registers[pin]);
}
return 0;
}
static int find_irq_entry(int ioapic_idx, int pin, int type)
{
int i;
for (i = 0; i < mp_irq_entries; i++)
if (mp_irqs[i].irqtype == type &&
(mp_irqs[i].dstapic == mpc_ioapic_id(ioapic_idx) ||
mp_irqs[i].dstapic == MP_APIC_ALL) &&
mp_irqs[i].dstirq == pin)
return i;
return -1;
}
static int __init find_isa_irq_pin(int irq, int type)
{
int i;
for (i = 0; i < mp_irq_entries; i++) {
int lbus = mp_irqs[i].srcbus;
if (test_bit(lbus, mp_bus_not_pci) &&
(mp_irqs[i].irqtype == type) &&
(mp_irqs[i].srcbusirq == irq))
return mp_irqs[i].dstirq;
}
return -1;
}
static int __init find_isa_irq_apic(int irq, int type)
{
int i;
for (i = 0; i < mp_irq_entries; i++) {
int lbus = mp_irqs[i].srcbus;
if (test_bit(lbus, mp_bus_not_pci) &&
(mp_irqs[i].irqtype == type) &&
(mp_irqs[i].srcbusirq == irq))
break;
}
if (i < mp_irq_entries) {
int ioapic_idx;
for (ioapic_idx = 0; ioapic_idx < nr_ioapics; ioapic_idx++)
if (mpc_ioapic_id(ioapic_idx) == mp_irqs[i].dstapic)
return ioapic_idx;
}
return -1;
}
static int EISA_ELCR(unsigned int irq)
{
if (irq < legacy_pic->nr_legacy_irqs) {
unsigned int port = 0x4d0 + (irq >> 3);
return (inb(port) >> (irq & 7)) & 1;
}
apic_printk(APIC_VERBOSE, KERN_INFO
"Broken MPtable reports ISA irq %d\n", irq);
return 0;
}
static int irq_polarity(int idx)
{
int bus = mp_irqs[idx].srcbus;
int polarity;
switch (mp_irqs[idx].irqflag & 3)
{
case 0:
if (test_bit(bus, mp_bus_not_pci))
polarity = default_ISA_polarity(idx);
else
polarity = default_PCI_polarity(idx);
break;
case 1:
{
polarity = 0;
break;
}
case 2:
{
pr_warn("broken BIOS!!\n");
polarity = 1;
break;
}
case 3:
{
polarity = 1;
break;
}
default:
{
pr_warn("broken BIOS!!\n");
polarity = 1;
break;
}
}
return polarity;
}
static int irq_trigger(int idx)
{
int bus = mp_irqs[idx].srcbus;
int trigger;
switch ((mp_irqs[idx].irqflag>>2) & 3)
{
case 0:
if (test_bit(bus, mp_bus_not_pci))
trigger = default_ISA_trigger(idx);
else
trigger = default_PCI_trigger(idx);
#ifdef CONFIG_EISA
switch (mp_bus_id_to_type[bus]) {
case MP_BUS_ISA:
{
break;
}
case MP_BUS_EISA:
{
trigger = default_EISA_trigger(idx);
break;
}
case MP_BUS_PCI:
{
break;
}
default:
{
pr_warn("broken BIOS!!\n");
trigger = 1;
break;
}
}
#endif
break;
case 1:
{
trigger = 0;
break;
}
case 2:
{
pr_warn("broken BIOS!!\n");
trigger = 1;
break;
}
case 3:
{
trigger = 1;
break;
}
default:
{
pr_warn("broken BIOS!!\n");
trigger = 0;
break;
}
}
return trigger;
}
static int pin_2_irq(int idx, int apic, int pin)
{
int irq;
int bus = mp_irqs[idx].srcbus;
struct mp_ioapic_gsi *gsi_cfg = mp_ioapic_gsi_routing(apic);
if (mp_irqs[idx].dstirq != pin)
pr_err("broken BIOS or MPTABLE parser, ayiee!!\n");
if (test_bit(bus, mp_bus_not_pci)) {
irq = mp_irqs[idx].srcbusirq;
} else {
u32 gsi = gsi_cfg->gsi_base + pin;
if (gsi >= NR_IRQS_LEGACY)
irq = gsi;
else
irq = gsi_top + gsi;
}
#ifdef CONFIG_X86_32
if ((pin >= 16) && (pin <= 23)) {
if (pirq_entries[pin-16] != -1) {
if (!pirq_entries[pin-16]) {
apic_printk(APIC_VERBOSE, KERN_DEBUG
"disabling PIRQ%d\n", pin-16);
} else {
irq = pirq_entries[pin-16];
apic_printk(APIC_VERBOSE, KERN_DEBUG
"using PIRQ%d -> IRQ %d\n",
pin-16, irq);
}
}
}
#endif
return irq;
}
int IO_APIC_get_PCI_irq_vector(int bus, int slot, int pin,
struct io_apic_irq_attr *irq_attr)
{
int ioapic_idx, i, best_guess = -1;
apic_printk(APIC_DEBUG,
"querying PCI -> IRQ mapping bus:%d, slot:%d, pin:%d.\n",
bus, slot, pin);
if (test_bit(bus, mp_bus_not_pci)) {
apic_printk(APIC_VERBOSE,
"PCI BIOS passed nonexistent PCI bus %d!\n", bus);
return -1;
}
for (i = 0; i < mp_irq_entries; i++) {
int lbus = mp_irqs[i].srcbus;
for (ioapic_idx = 0; ioapic_idx < nr_ioapics; ioapic_idx++)
if (mpc_ioapic_id(ioapic_idx) == mp_irqs[i].dstapic ||
mp_irqs[i].dstapic == MP_APIC_ALL)
break;
if (!test_bit(lbus, mp_bus_not_pci) &&
!mp_irqs[i].irqtype &&
(bus == lbus) &&
(slot == ((mp_irqs[i].srcbusirq >> 2) & 0x1f))) {
int irq = pin_2_irq(i, ioapic_idx, mp_irqs[i].dstirq);
if (!(ioapic_idx || IO_APIC_IRQ(irq)))
continue;
if (pin == (mp_irqs[i].srcbusirq & 3)) {
set_io_apic_irq_attr(irq_attr, ioapic_idx,
mp_irqs[i].dstirq,
irq_trigger(i),
irq_polarity(i));
return irq;
}
if (best_guess < 0) {
set_io_apic_irq_attr(irq_attr, ioapic_idx,
mp_irqs[i].dstirq,
irq_trigger(i),
irq_polarity(i));
best_guess = irq;
}
}
}
return best_guess;
}
void lock_vector_lock(void)
{
raw_spin_lock(&vector_lock);
}
void unlock_vector_lock(void)
{
raw_spin_unlock(&vector_lock);
}
static int
__assign_irq_vector(int irq, struct irq_cfg *cfg, const struct cpumask *mask)
{
static int current_vector = FIRST_EXTERNAL_VECTOR + VECTOR_OFFSET_START;
static int current_offset = VECTOR_OFFSET_START % 16;
int cpu, err;
cpumask_var_t tmp_mask;
if (cfg->move_in_progress)
return -EBUSY;
if (!alloc_cpumask_var(&tmp_mask, GFP_ATOMIC))
return -ENOMEM;
err = -ENOSPC;
cpumask_clear(cfg->old_domain);
cpu = cpumask_first_and(mask, cpu_online_mask);
while (cpu < nr_cpu_ids) {
int new_cpu, vector, offset;
apic->vector_allocation_domain(cpu, tmp_mask, mask);
if (cpumask_subset(tmp_mask, cfg->domain)) {
err = 0;
if (cpumask_equal(tmp_mask, cfg->domain))
break;
cpumask_andnot(cfg->old_domain, cfg->domain, tmp_mask);
cfg->move_in_progress =
cpumask_intersects(cfg->old_domain, cpu_online_mask);
cpumask_and(cfg->domain, cfg->domain, tmp_mask);
break;
}
vector = current_vector;
offset = current_offset;
next:
vector += 16;
if (vector >= first_system_vector) {
offset = (offset + 1) % 16;
vector = FIRST_EXTERNAL_VECTOR + offset;
}
if (unlikely(current_vector == vector)) {
cpumask_or(cfg->old_domain, cfg->old_domain, tmp_mask);
cpumask_andnot(tmp_mask, mask, cfg->old_domain);
cpu = cpumask_first_and(tmp_mask, cpu_online_mask);
continue;
}
if (test_bit(vector, used_vectors))
goto next;
for_each_cpu_and(new_cpu, tmp_mask, cpu_online_mask) {
if (per_cpu(vector_irq, new_cpu)[vector] > VECTOR_UNDEFINED)
goto next;
}
current_vector = vector;
current_offset = offset;
if (cfg->vector) {
cpumask_copy(cfg->old_domain, cfg->domain);
cfg->move_in_progress =
cpumask_intersects(cfg->old_domain, cpu_online_mask);
}
for_each_cpu_and(new_cpu, tmp_mask, cpu_online_mask)
per_cpu(vector_irq, new_cpu)[vector] = irq;
cfg->vector = vector;
cpumask_copy(cfg->domain, tmp_mask);
err = 0;
break;
}
free_cpumask_var(tmp_mask);
return err;
}
int assign_irq_vector(int irq, struct irq_cfg *cfg, const struct cpumask *mask)
{
int err;
unsigned long flags;
raw_spin_lock_irqsave(&vector_lock, flags);
err = __assign_irq_vector(irq, cfg, mask);
raw_spin_unlock_irqrestore(&vector_lock, flags);
return err;
}
static void __clear_irq_vector(int irq, struct irq_cfg *cfg)
{
int cpu, vector;
BUG_ON(!cfg->vector);
vector = cfg->vector;
for_each_cpu_and(cpu, cfg->domain, cpu_online_mask)
per_cpu(vector_irq, cpu)[vector] = VECTOR_UNDEFINED;
cfg->vector = 0;
cpumask_clear(cfg->domain);
if (likely(!cfg->move_in_progress))
return;
for_each_cpu_and(cpu, cfg->old_domain, cpu_online_mask) {
for (vector = FIRST_EXTERNAL_VECTOR; vector < NR_VECTORS; vector++) {
if (per_cpu(vector_irq, cpu)[vector] != irq)
continue;
per_cpu(vector_irq, cpu)[vector] = VECTOR_UNDEFINED;
break;
}
}
cfg->move_in_progress = 0;
}
void __setup_vector_irq(int cpu)
{
int irq, vector;
struct irq_cfg *cfg;
raw_spin_lock(&vector_lock);
for_each_active_irq(irq) {
cfg = irq_get_chip_data(irq);
if (!cfg)
continue;
if (!cpumask_test_cpu(cpu, cfg->domain))
continue;
vector = cfg->vector;
per_cpu(vector_irq, cpu)[vector] = irq;
}
for (vector = 0; vector < NR_VECTORS; ++vector) {
irq = per_cpu(vector_irq, cpu)[vector];
if (irq <= VECTOR_UNDEFINED)
continue;
cfg = irq_cfg(irq);
if (!cpumask_test_cpu(cpu, cfg->domain))
per_cpu(vector_irq, cpu)[vector] = VECTOR_UNDEFINED;
}
raw_spin_unlock(&vector_lock);
}
static inline int IO_APIC_irq_trigger(int irq)
{
int apic, idx, pin;
for (apic = 0; apic < nr_ioapics; apic++) {
for (pin = 0; pin < ioapics[apic].nr_registers; pin++) {
idx = find_irq_entry(apic, pin, mp_INT);
if ((idx != -1) && (irq == pin_2_irq(idx, apic, pin)))
return irq_trigger(idx);
}
}
return 0;
}
static inline int IO_APIC_irq_trigger(int irq)
{
return 1;
}
static void ioapic_register_intr(unsigned int irq, struct irq_cfg *cfg,
unsigned long trigger)
{
struct irq_chip *chip = &ioapic_chip;
irq_flow_handler_t hdl;
bool fasteoi;
if ((trigger == IOAPIC_AUTO && IO_APIC_irq_trigger(irq)) ||
trigger == IOAPIC_LEVEL) {
irq_set_status_flags(irq, IRQ_LEVEL);
fasteoi = true;
} else {
irq_clear_status_flags(irq, IRQ_LEVEL);
fasteoi = false;
}
if (setup_remapped_irq(irq, cfg, chip))
fasteoi = trigger != 0;
hdl = fasteoi ? handle_fasteoi_irq : handle_edge_irq;
irq_set_chip_and_handler_name(irq, chip, hdl,
fasteoi ? "fasteoi" : "edge");
}
int native_setup_ioapic_entry(int irq, struct IO_APIC_route_entry *entry,
unsigned int destination, int vector,
struct io_apic_irq_attr *attr)
{
memset(entry, 0, sizeof(*entry));
entry->delivery_mode = apic->irq_delivery_mode;
entry->dest_mode = apic->irq_dest_mode;
entry->dest = destination;
entry->vector = vector;
entry->mask = 0;
entry->trigger = attr->trigger;
entry->polarity = attr->polarity;
if (attr->trigger)
entry->mask = 1;
return 0;
}
static void setup_ioapic_irq(unsigned int irq, struct irq_cfg *cfg,
struct io_apic_irq_attr *attr)
{
struct IO_APIC_route_entry entry;
unsigned int dest;
if (!IO_APIC_IRQ(irq))
return;
if (assign_irq_vector(irq, cfg, apic->target_cpus()))
return;
if (apic->cpu_mask_to_apicid_and(cfg->domain, apic->target_cpus(),
&dest)) {
pr_warn("Failed to obtain apicid for ioapic %d, pin %d\n",
mpc_ioapic_id(attr->ioapic), attr->ioapic_pin);
__clear_irq_vector(irq, cfg);
return;
}
apic_printk(APIC_VERBOSE,KERN_DEBUG
"IOAPIC[%d]: Set routing entry (%d-%d -> 0x%x -> "
"IRQ %d Mode:%i Active:%i Dest:%d)\n",
attr->ioapic, mpc_ioapic_id(attr->ioapic), attr->ioapic_pin,
cfg->vector, irq, attr->trigger, attr->polarity, dest);
if (x86_io_apic_ops.setup_entry(irq, &entry, dest, cfg->vector, attr)) {
pr_warn("Failed to setup ioapic entry for ioapic %d, pin %d\n",
mpc_ioapic_id(attr->ioapic), attr->ioapic_pin);
__clear_irq_vector(irq, cfg);
return;
}
ioapic_register_intr(irq, cfg, attr->trigger);
if (irq < legacy_pic->nr_legacy_irqs)
legacy_pic->mask(irq);
ioapic_write_entry(attr->ioapic, attr->ioapic_pin, entry);
}
static bool __init io_apic_pin_not_connected(int idx, int ioapic_idx, int pin)
{
if (idx != -1)
return false;
apic_printk(APIC_VERBOSE, KERN_DEBUG " apic %d pin %d not connected\n",
mpc_ioapic_id(ioapic_idx), pin);
return true;
}
static void __init __io_apic_setup_irqs(unsigned int ioapic_idx)
{
int idx, node = cpu_to_node(0);
struct io_apic_irq_attr attr;
unsigned int pin, irq;
for (pin = 0; pin < ioapics[ioapic_idx].nr_registers; pin++) {
idx = find_irq_entry(ioapic_idx, pin, mp_INT);
if (io_apic_pin_not_connected(idx, ioapic_idx, pin))
continue;
irq = pin_2_irq(idx, ioapic_idx, pin);
if ((ioapic_idx > 0) && (irq > 16))
continue;
if (apic->multi_timer_check &&
apic->multi_timer_check(ioapic_idx, irq))
continue;
set_io_apic_irq_attr(&attr, ioapic_idx, pin, irq_trigger(idx),
irq_polarity(idx));
io_apic_setup_irq_pin(irq, node, &attr);
}
}
static void __init setup_IO_APIC_irqs(void)
{
unsigned int ioapic_idx;
apic_printk(APIC_VERBOSE, KERN_DEBUG "init IO_APIC IRQs\n");
for (ioapic_idx = 0; ioapic_idx < nr_ioapics; ioapic_idx++)
__io_apic_setup_irqs(ioapic_idx);
}
void setup_IO_APIC_irq_extra(u32 gsi)
{
int ioapic_idx = 0, pin, idx, irq, node = cpu_to_node(0);
struct io_apic_irq_attr attr;
ioapic_idx = mp_find_ioapic(gsi);
if (ioapic_idx < 0)
return;
pin = mp_find_ioapic_pin(ioapic_idx, gsi);
idx = find_irq_entry(ioapic_idx, pin, mp_INT);
if (idx == -1)
return;
irq = pin_2_irq(idx, ioapic_idx, pin);
if (ioapic_idx == 0 || irq < NR_IRQS_LEGACY)
return;
set_io_apic_irq_attr(&attr, ioapic_idx, pin, irq_trigger(idx),
irq_polarity(idx));
io_apic_setup_irq_pin_once(irq, node, &attr);
}
static void __init setup_timer_IRQ0_pin(unsigned int ioapic_idx,
unsigned int pin, int vector)
{
struct IO_APIC_route_entry entry;
unsigned int dest;
memset(&entry, 0, sizeof(entry));
if (unlikely(apic->cpu_mask_to_apicid_and(apic->target_cpus(),
apic->target_cpus(), &dest)))
dest = BAD_APICID;
entry.dest_mode = apic->irq_dest_mode;
entry.mask = 0;
entry.dest = dest;
entry.delivery_mode = apic->irq_delivery_mode;
entry.polarity = 0;
entry.trigger = 0;
entry.vector = vector;
irq_set_chip_and_handler_name(0, &ioapic_chip, handle_edge_irq,
"edge");
ioapic_write_entry(ioapic_idx, pin, entry);
}
void native_io_apic_print_entries(unsigned int apic, unsigned int nr_entries)
{
int i;
pr_debug(" NR Dst Mask Trig IRR Pol Stat Dmod Deli Vect:\n");
for (i = 0; i <= nr_entries; i++) {
struct IO_APIC_route_entry entry;
entry = ioapic_read_entry(apic, i);
pr_debug(" %02x %02X ", i, entry.dest);
pr_cont("%1d %1d %1d %1d %1d "
"%1d %1d %02X\n",
entry.mask,
entry.trigger,
entry.irr,
entry.polarity,
entry.delivery_status,
entry.dest_mode,
entry.delivery_mode,
entry.vector);
}
}
void intel_ir_io_apic_print_entries(unsigned int apic,
unsigned int nr_entries)
{
int i;
pr_debug(" NR Indx Fmt Mask Trig IRR Pol Stat Indx2 Zero Vect:\n");
for (i = 0; i <= nr_entries; i++) {
struct IR_IO_APIC_route_entry *ir_entry;
struct IO_APIC_route_entry entry;
entry = ioapic_read_entry(apic, i);
ir_entry = (struct IR_IO_APIC_route_entry *)&entry;
pr_debug(" %02x %04X ", i, ir_entry->index);
pr_cont("%1d %1d %1d %1d %1d "
"%1d %1d %X %02X\n",
ir_entry->format,
ir_entry->mask,
ir_entry->trigger,
ir_entry->irr,
ir_entry->polarity,
ir_entry->delivery_status,
ir_entry->index2,
ir_entry->zero,
ir_entry->vector);
}
}
void ioapic_zap_locks(void)
{
raw_spin_lock_init(&ioapic_lock);
}
static __init int setup_show_lapic(char *arg)
{
int num = -1;
if (strcmp(arg, "all") == 0) {
show_lapic = CONFIG_NR_CPUS;
} else {
get_option(&arg, &num);
if (num >= 0)
show_lapic = num;
}
return 1;
}
void __init enable_IO_APIC(void)
{
int i8259_apic, i8259_pin;
int apic;
if (!legacy_pic->nr_legacy_irqs)
return;
for(apic = 0; apic < nr_ioapics; apic++) {
int pin;
for (pin = 0; pin < ioapics[apic].nr_registers; pin++) {
struct IO_APIC_route_entry entry;
entry = ioapic_read_entry(apic, pin);
if ((entry.mask == 0) && (entry.delivery_mode == dest_ExtINT)) {
ioapic_i8259.apic = apic;
ioapic_i8259.pin = pin;
goto found_i8259;
}
}
}
found_i8259:
i8259_pin = find_isa_irq_pin(0, mp_ExtINT);
i8259_apic = find_isa_irq_apic(0, mp_ExtINT);
if ((ioapic_i8259.pin == -1) && (i8259_pin >= 0)) {
printk(KERN_WARNING "ExtINT not setup in hardware but reported by MP table\n");
ioapic_i8259.pin = i8259_pin;
ioapic_i8259.apic = i8259_apic;
}
if (((ioapic_i8259.apic != i8259_apic) || (ioapic_i8259.pin != i8259_pin)) &&
(i8259_pin >= 0) && (ioapic_i8259.pin >= 0))
{
printk(KERN_WARNING "ExtINT in hardware and MP table differ\n");
}
clear_IO_APIC();
}
void native_disable_io_apic(void)
{
if (ioapic_i8259.pin != -1) {
struct IO_APIC_route_entry entry;
memset(&entry, 0, sizeof(entry));
entry.mask = 0;
entry.trigger = 0;
entry.irr = 0;
entry.polarity = 0;
entry.delivery_status = 0;
entry.dest_mode = 0;
entry.delivery_mode = dest_ExtINT;
entry.vector = 0;
entry.dest = read_apic_id();
ioapic_write_entry(ioapic_i8259.apic, ioapic_i8259.pin, entry);
}
if (cpu_has_apic || apic_from_smp_config())
disconnect_bsp_APIC(ioapic_i8259.pin != -1);
}
void disable_IO_APIC(void)
{
clear_IO_APIC();
if (!legacy_pic->nr_legacy_irqs)
return;
x86_io_apic_ops.disable();
}
void __init setup_ioapic_ids_from_mpc_nocheck(void)
{
union IO_APIC_reg_00 reg_00;
physid_mask_t phys_id_present_map;
int ioapic_idx;
int i;
unsigned char old_id;
unsigned long flags;
apic->ioapic_phys_id_map(&phys_cpu_present_map, &phys_id_present_map);
for (ioapic_idx = 0; ioapic_idx < nr_ioapics; ioapic_idx++) {
raw_spin_lock_irqsave(&ioapic_lock, flags);
reg_00.raw = io_apic_read(ioapic_idx, 0);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
old_id = mpc_ioapic_id(ioapic_idx);
if (mpc_ioapic_id(ioapic_idx) >= get_physical_broadcast()) {
printk(KERN_ERR "BIOS bug, IO-APIC#%d ID is %d in the MPC table!...\n",
ioapic_idx, mpc_ioapic_id(ioapic_idx));
printk(KERN_ERR "... fixing up to %d. (tell your hw vendor)\n",
reg_00.bits.ID);
ioapics[ioapic_idx].mp_config.apicid = reg_00.bits.ID;
}
if (apic->check_apicid_used(&phys_id_present_map,
mpc_ioapic_id(ioapic_idx))) {
printk(KERN_ERR "BIOS bug, IO-APIC#%d ID %d is already used!...\n",
ioapic_idx, mpc_ioapic_id(ioapic_idx));
for (i = 0; i < get_physical_broadcast(); i++)
if (!physid_isset(i, phys_id_present_map))
break;
if (i >= get_physical_broadcast())
panic("Max APIC ID exceeded!\n");
printk(KERN_ERR "... fixing up to %d. (tell your hw vendor)\n",
i);
physid_set(i, phys_id_present_map);
ioapics[ioapic_idx].mp_config.apicid = i;
} else {
physid_mask_t tmp;
apic->apicid_to_cpu_present(mpc_ioapic_id(ioapic_idx),
&tmp);
apic_printk(APIC_VERBOSE, "Setting %d in the "
"phys_id_present_map\n",
mpc_ioapic_id(ioapic_idx));
physids_or(phys_id_present_map, phys_id_present_map, tmp);
}
if (old_id != mpc_ioapic_id(ioapic_idx))
for (i = 0; i < mp_irq_entries; i++)
if (mp_irqs[i].dstapic == old_id)
mp_irqs[i].dstapic
= mpc_ioapic_id(ioapic_idx);
if (mpc_ioapic_id(ioapic_idx) == reg_00.bits.ID)
continue;
apic_printk(APIC_VERBOSE, KERN_INFO
"...changing IO-APIC physical APIC ID to %d ...",
mpc_ioapic_id(ioapic_idx));
reg_00.bits.ID = mpc_ioapic_id(ioapic_idx);
raw_spin_lock_irqsave(&ioapic_lock, flags);
io_apic_write(ioapic_idx, 0, reg_00.raw);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
raw_spin_lock_irqsave(&ioapic_lock, flags);
reg_00.raw = io_apic_read(ioapic_idx, 0);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
if (reg_00.bits.ID != mpc_ioapic_id(ioapic_idx))
pr_cont("could not set ID!\n");
else
apic_printk(APIC_VERBOSE, " ok.\n");
}
}
void __init setup_ioapic_ids_from_mpc(void)
{
if (acpi_ioapic)
return;
if (!(boot_cpu_data.x86_vendor == X86_VENDOR_INTEL)
|| APIC_XAPIC(apic_version[boot_cpu_physical_apicid]))
return;
setup_ioapic_ids_from_mpc_nocheck();
}
static int __init notimercheck(char *s)
{
no_timer_check = 1;
return 1;
}
static int __init timer_irq_works(void)
{
unsigned long t1 = jiffies;
unsigned long flags;
if (no_timer_check)
return 1;
local_save_flags(flags);
local_irq_enable();
mdelay((10 * 1000) / HZ);
local_irq_restore(flags);
if (time_after(jiffies, t1 + 4))
return 1;
return 0;
}
static unsigned int startup_ioapic_irq(struct irq_data *data)
{
int was_pending = 0, irq = data->irq;
unsigned long flags;
raw_spin_lock_irqsave(&ioapic_lock, flags);
if (irq < legacy_pic->nr_legacy_irqs) {
legacy_pic->mask(irq);
if (legacy_pic->irq_pending(irq))
was_pending = 1;
}
__unmask_ioapic(data->chip_data);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
return was_pending;
}
static int ioapic_retrigger_irq(struct irq_data *data)
{
struct irq_cfg *cfg = data->chip_data;
unsigned long flags;
int cpu;
raw_spin_lock_irqsave(&vector_lock, flags);
cpu = cpumask_first_and(cfg->domain, cpu_online_mask);
apic->send_IPI_mask(cpumask_of(cpu), cfg->vector);
raw_spin_unlock_irqrestore(&vector_lock, flags);
return 1;
}
void send_cleanup_vector(struct irq_cfg *cfg)
{
cpumask_var_t cleanup_mask;
if (unlikely(!alloc_cpumask_var(&cleanup_mask, GFP_ATOMIC))) {
unsigned int i;
for_each_cpu_and(i, cfg->old_domain, cpu_online_mask)
apic->send_IPI_mask(cpumask_of(i), IRQ_MOVE_CLEANUP_VECTOR);
} else {
cpumask_and(cleanup_mask, cfg->old_domain, cpu_online_mask);
apic->send_IPI_mask(cleanup_mask, IRQ_MOVE_CLEANUP_VECTOR);
free_cpumask_var(cleanup_mask);
}
cfg->move_in_progress = 0;
}
asmlinkage void smp_irq_move_cleanup_interrupt(void)
{
unsigned vector, me;
ack_APIC_irq();
irq_enter();
exit_idle();
me = smp_processor_id();
for (vector = FIRST_EXTERNAL_VECTOR; vector < NR_VECTORS; vector++) {
int irq;
unsigned int irr;
struct irq_desc *desc;
struct irq_cfg *cfg;
irq = __this_cpu_read(vector_irq[vector]);
if (irq <= VECTOR_UNDEFINED)
continue;
desc = irq_to_desc(irq);
if (!desc)
continue;
cfg = irq_cfg(irq);
if (!cfg)
continue;
raw_spin_lock(&desc->lock);
if (cfg->move_in_progress)
goto unlock;
if (vector == cfg->vector && cpumask_test_cpu(me, cfg->domain))
goto unlock;
irr = apic_read(APIC_IRR + (vector / 32 * 0x10));
if (irr & (1 << (vector % 32))) {
apic->send_IPI_self(IRQ_MOVE_CLEANUP_VECTOR);
goto unlock;
}
__this_cpu_write(vector_irq[vector], -1);
unlock:
raw_spin_unlock(&desc->lock);
}
irq_exit();
}
static void __irq_complete_move(struct irq_cfg *cfg, unsigned vector)
{
unsigned me;
if (likely(!cfg->move_in_progress))
return;
me = smp_processor_id();
if (vector == cfg->vector && cpumask_test_cpu(me, cfg->domain))
send_cleanup_vector(cfg);
}
static void irq_complete_move(struct irq_cfg *cfg)
{
__irq_complete_move(cfg, ~get_irq_regs()->orig_ax);
}
void irq_force_complete_move(int irq)
{
struct irq_cfg *cfg = irq_get_chip_data(irq);
if (!cfg)
return;
__irq_complete_move(cfg, cfg->vector);
}
static inline void irq_complete_move(struct irq_cfg *cfg) { }
static void __target_IO_APIC_irq(unsigned int irq, unsigned int dest, struct irq_cfg *cfg)
{
int apic, pin;
struct irq_pin_list *entry;
u8 vector = cfg->vector;
for_each_irq_pin(entry, cfg->irq_2_pin) {
unsigned int reg;
apic = entry->apic;
pin = entry->pin;
io_apic_write(apic, 0x11 + pin*2, dest);
reg = io_apic_read(apic, 0x10 + pin*2);
reg &= ~IO_APIC_REDIR_VECTOR_MASK;
reg |= vector;
io_apic_modify(apic, 0x10 + pin*2, reg);
}
}
int __ioapic_set_affinity(struct irq_data *data, const struct cpumask *mask,
unsigned int *dest_id)
{
struct irq_cfg *cfg = data->chip_data;
unsigned int irq = data->irq;
int err;
if (!config_enabled(CONFIG_SMP))
return -1;
if (!cpumask_intersects(mask, cpu_online_mask))
return -EINVAL;
err = assign_irq_vector(irq, cfg, mask);
if (err)
return err;
err = apic->cpu_mask_to_apicid_and(mask, cfg->domain, dest_id);
if (err) {
if (assign_irq_vector(irq, cfg, data->affinity))
pr_err("Failed to recover vector for irq %d\n", irq);
return err;
}
cpumask_copy(data->affinity, mask);
return 0;
}
int native_ioapic_set_affinity(struct irq_data *data,
const struct cpumask *mask,
bool force)
{
unsigned int dest, irq = data->irq;
unsigned long flags;
int ret;
if (!config_enabled(CONFIG_SMP))
return -1;
raw_spin_lock_irqsave(&ioapic_lock, flags);
ret = __ioapic_set_affinity(data, mask, &dest);
if (!ret) {
dest = SET_APIC_LOGICAL_ID(dest);
__target_IO_APIC_irq(irq, dest, data->chip_data);
ret = IRQ_SET_MASK_OK_NOCOPY;
}
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
return ret;
}
static void ack_apic_edge(struct irq_data *data)
{
irq_complete_move(data->chip_data);
irq_move_irq(data);
ack_APIC_irq();
}
static bool io_apic_level_ack_pending(struct irq_cfg *cfg)
{
struct irq_pin_list *entry;
unsigned long flags;
raw_spin_lock_irqsave(&ioapic_lock, flags);
for_each_irq_pin(entry, cfg->irq_2_pin) {
unsigned int reg;
int pin;
pin = entry->pin;
reg = io_apic_read(entry->apic, 0x10 + pin*2);
if (reg & IO_APIC_REDIR_REMOTE_IRR) {
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
return true;
}
}
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
return false;
}
static inline bool ioapic_irqd_mask(struct irq_data *data, struct irq_cfg *cfg)
{
if (unlikely(irqd_is_setaffinity_pending(data))) {
mask_ioapic(cfg);
return true;
}
return false;
}
static inline void ioapic_irqd_unmask(struct irq_data *data,
struct irq_cfg *cfg, bool masked)
{
if (unlikely(masked)) {
if (!io_apic_level_ack_pending(cfg))
irq_move_masked_irq(data);
unmask_ioapic(cfg);
}
}
static inline bool ioapic_irqd_mask(struct irq_data *data, struct irq_cfg *cfg)
{
return false;
}
static inline void ioapic_irqd_unmask(struct irq_data *data,
struct irq_cfg *cfg, bool masked)
{
}
static void ack_apic_level(struct irq_data *data)
{
struct irq_cfg *cfg = data->chip_data;
int i, irq = data->irq;
unsigned long v;
bool masked;
irq_complete_move(cfg);
masked = ioapic_irqd_mask(data, cfg);
i = cfg->vector;
v = apic_read(APIC_TMR + ((i & ~0x1f) >> 1));
ack_APIC_irq();
if (!(v & (1 << (i & 0x1f)))) {
atomic_inc(&irq_mis_count);
eoi_ioapic_irq(irq, cfg);
}
ioapic_irqd_unmask(data, cfg, masked);
}
static inline void init_IO_APIC_traps(void)
{
struct irq_cfg *cfg;
unsigned int irq;
for_each_active_irq(irq) {
cfg = irq_get_chip_data(irq);
if (IO_APIC_IRQ(irq) && cfg && !cfg->vector) {
if (irq < legacy_pic->nr_legacy_irqs)
legacy_pic->make_irq(irq);
else
irq_set_chip(irq, &no_irq_chip);
}
}
}
static void mask_lapic_irq(struct irq_data *data)
{
unsigned long v;
v = apic_read(APIC_LVT0);
apic_write(APIC_LVT0, v | APIC_LVT_MASKED);
}
static void unmask_lapic_irq(struct irq_data *data)
{
unsigned long v;
v = apic_read(APIC_LVT0);
apic_write(APIC_LVT0, v & ~APIC_LVT_MASKED);
}
static void ack_lapic_irq(struct irq_data *data)
{
ack_APIC_irq();
}
static void lapic_register_intr(int irq)
{
irq_clear_status_flags(irq, IRQ_LEVEL);
irq_set_chip_and_handler_name(irq, &lapic_chip, handle_edge_irq,
"edge");
}
static inline void __init unlock_ExtINT_logic(void)
{
int apic, pin, i;
struct IO_APIC_route_entry entry0, entry1;
unsigned char save_control, save_freq_select;
pin = find_isa_irq_pin(8, mp_INT);
if (pin == -1) {
WARN_ON_ONCE(1);
return;
}
apic = find_isa_irq_apic(8, mp_INT);
if (apic == -1) {
WARN_ON_ONCE(1);
return;
}
entry0 = ioapic_read_entry(apic, pin);
clear_IO_APIC_pin(apic, pin);
memset(&entry1, 0, sizeof(entry1));
entry1.dest_mode = 0;
entry1.mask = 0;
entry1.dest = hard_smp_processor_id();
entry1.delivery_mode = dest_ExtINT;
entry1.polarity = entry0.polarity;
entry1.trigger = 0;
entry1.vector = 0;
ioapic_write_entry(apic, pin, entry1);
save_control = CMOS_READ(RTC_CONTROL);
save_freq_select = CMOS_READ(RTC_FREQ_SELECT);
CMOS_WRITE((save_freq_select & ~RTC_RATE_SELECT) | 0x6,
RTC_FREQ_SELECT);
CMOS_WRITE(save_control | RTC_PIE, RTC_CONTROL);
i = 100;
while (i-- > 0) {
mdelay(10);
if ((CMOS_READ(RTC_INTR_FLAGS) & RTC_PF) == RTC_PF)
i -= 10;
}
CMOS_WRITE(save_control, RTC_CONTROL);
CMOS_WRITE(save_freq_select, RTC_FREQ_SELECT);
clear_IO_APIC_pin(apic, pin);
ioapic_write_entry(apic, pin, entry0);
}
static int __init disable_timer_pin_setup(char *arg)
{
disable_timer_pin_1 = 1;
return 0;
}
static inline void __init check_timer(void)
{
struct irq_cfg *cfg = irq_get_chip_data(0);
int node = cpu_to_node(0);
int apic1, pin1, apic2, pin2;
unsigned long flags;
int no_pin1 = 0;
local_irq_save(flags);
legacy_pic->mask(0);
assign_irq_vector(0, cfg, apic->target_cpus());
apic_write(APIC_LVT0, APIC_LVT_MASKED | APIC_DM_EXTINT);
legacy_pic->init(1);
pin1 = find_isa_irq_pin(0, mp_INT);
apic1 = find_isa_irq_apic(0, mp_INT);
pin2 = ioapic_i8259.pin;
apic2 = ioapic_i8259.apic;
apic_printk(APIC_QUIET, KERN_INFO "..TIMER: vector=0x%02X "
"apic1=%d pin1=%d apic2=%d pin2=%d\n",
cfg->vector, apic1, pin1, apic2, pin2);
if (pin1 == -1) {
panic_if_irq_remap("BIOS bug: timer not connected to IO-APIC");
pin1 = pin2;
apic1 = apic2;
no_pin1 = 1;
} else if (pin2 == -1) {
pin2 = pin1;
apic2 = apic1;
}
if (pin1 != -1) {
if (no_pin1) {
add_pin_to_irq_node(cfg, node, apic1, pin1);
setup_timer_IRQ0_pin(apic1, pin1, cfg->vector);
} else {
int idx;
idx = find_irq_entry(apic1, pin1, mp_INT);
if (idx != -1 && irq_trigger(idx))
unmask_ioapic(cfg);
}
if (timer_irq_works()) {
if (disable_timer_pin_1 > 0)
clear_IO_APIC_pin(0, pin1);
goto out;
}
panic_if_irq_remap("timer doesn't work through Interrupt-remapped IO-APIC");
local_irq_disable();
clear_IO_APIC_pin(apic1, pin1);
if (!no_pin1)
apic_printk(APIC_QUIET, KERN_ERR "..MP-BIOS bug: "
"8254 timer not connected to IO-APIC\n");
apic_printk(APIC_QUIET, KERN_INFO "...trying to set up timer "
"(IRQ0) through the 8259A ...\n");
apic_printk(APIC_QUIET, KERN_INFO
"..... (found apic %d pin %d) ...\n", apic2, pin2);
replace_pin_at_irq_node(cfg, node, apic1, pin1, apic2, pin2);
setup_timer_IRQ0_pin(apic2, pin2, cfg->vector);
legacy_pic->unmask(0);
if (timer_irq_works()) {
apic_printk(APIC_QUIET, KERN_INFO "....... works.\n");
timer_through_8259 = 1;
goto out;
}
local_irq_disable();
legacy_pic->mask(0);
clear_IO_APIC_pin(apic2, pin2);
apic_printk(APIC_QUIET, KERN_INFO "....... failed.\n");
}
apic_printk(APIC_QUIET, KERN_INFO
"...trying to set up timer as Virtual Wire IRQ...\n");
lapic_register_intr(0);
apic_write(APIC_LVT0, APIC_DM_FIXED | cfg->vector);
legacy_pic->unmask(0);
if (timer_irq_works()) {
apic_printk(APIC_QUIET, KERN_INFO "..... works.\n");
goto out;
}
local_irq_disable();
legacy_pic->mask(0);
apic_write(APIC_LVT0, APIC_LVT_MASKED | APIC_DM_FIXED | cfg->vector);
apic_printk(APIC_QUIET, KERN_INFO "..... failed.\n");
apic_printk(APIC_QUIET, KERN_INFO
"...trying to set up timer as ExtINT IRQ...\n");
legacy_pic->init(0);
legacy_pic->make_irq(0);
apic_write(APIC_LVT0, APIC_DM_EXTINT);
unlock_ExtINT_logic();
if (timer_irq_works()) {
apic_printk(APIC_QUIET, KERN_INFO "..... works.\n");
goto out;
}
local_irq_disable();
apic_printk(APIC_QUIET, KERN_INFO "..... failed :(.\n");
if (x2apic_preenabled)
apic_printk(APIC_QUIET, KERN_INFO
"Perhaps problem with the pre-enabled x2apic mode\n"
"Try booting with x2apic and interrupt-remapping disabled in the bios.\n");
panic("IO-APIC + timer doesn't work! Boot with apic=debug and send a "
"report. Then try booting with the 'noapic' option.\n");
out:
local_irq_restore(flags);
}
void __init setup_IO_APIC(void)
{
io_apic_irqs = legacy_pic->nr_legacy_irqs ? ~PIC_IRQS : ~0UL;
apic_printk(APIC_VERBOSE, "ENABLING IO-APIC IRQs\n");
x86_init.mpparse.setup_ioapic_ids();
sync_Arb_IDs();
setup_IO_APIC_irqs();
init_IO_APIC_traps();
if (legacy_pic->nr_legacy_irqs)
check_timer();
}
static int __init io_apic_bug_finalize(void)
{
if (sis_apic_bug == -1)
sis_apic_bug = 0;
return 0;
}
static void resume_ioapic_id(int ioapic_idx)
{
unsigned long flags;
union IO_APIC_reg_00 reg_00;
raw_spin_lock_irqsave(&ioapic_lock, flags);
reg_00.raw = io_apic_read(ioapic_idx, 0);
if (reg_00.bits.ID != mpc_ioapic_id(ioapic_idx)) {
reg_00.bits.ID = mpc_ioapic_id(ioapic_idx);
io_apic_write(ioapic_idx, 0, reg_00.raw);
}
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
}
static void ioapic_resume(void)
{
int ioapic_idx;
for (ioapic_idx = nr_ioapics - 1; ioapic_idx >= 0; ioapic_idx--)
resume_ioapic_id(ioapic_idx);
restore_ioapic_entries();
}
static int __init ioapic_init_ops(void)
{
register_syscore_ops(&ioapic_syscore_ops);
return 0;
}
unsigned int __create_irqs(unsigned int from, unsigned int count, int node)
{
struct irq_cfg **cfg;
unsigned long flags;
int irq, i;
if (from < nr_irqs_gsi)
from = nr_irqs_gsi;
cfg = kzalloc_node(count * sizeof(cfg[0]), GFP_KERNEL, node);
if (!cfg)
return 0;
irq = alloc_irqs_from(from, count, node);
if (irq < 0)
goto out_cfgs;
for (i = 0; i < count; i++) {
cfg[i] = alloc_irq_cfg(irq + i, node);
if (!cfg[i])
goto out_irqs;
}
raw_spin_lock_irqsave(&vector_lock, flags);
for (i = 0; i < count; i++)
if (__assign_irq_vector(irq + i, cfg[i], apic->target_cpus()))
goto out_vecs;
raw_spin_unlock_irqrestore(&vector_lock, flags);
for (i = 0; i < count; i++) {
irq_set_chip_data(irq + i, cfg[i]);
irq_clear_status_flags(irq + i, IRQ_NOREQUEST);
}
kfree(cfg);
return irq;
out_vecs:
for (i--; i >= 0; i--)
__clear_irq_vector(irq + i, cfg[i]);
raw_spin_unlock_irqrestore(&vector_lock, flags);
out_irqs:
for (i = 0; i < count; i++)
free_irq_at(irq + i, cfg[i]);
out_cfgs:
kfree(cfg);
return 0;
}
unsigned int create_irq_nr(unsigned int from, int node)
{
return __create_irqs(from, 1, node);
}
int create_irq(void)
{
int node = cpu_to_node(0);
unsigned int irq_want;
int irq;
irq_want = nr_irqs_gsi;
irq = create_irq_nr(irq_want, node);
if (irq == 0)
irq = -1;
return irq;
}
void destroy_irq(unsigned int irq)
{
struct irq_cfg *cfg = irq_get_chip_data(irq);
unsigned long flags;
irq_set_status_flags(irq, IRQ_NOREQUEST|IRQ_NOPROBE);
free_remapped_irq(irq);
raw_spin_lock_irqsave(&vector_lock, flags);
__clear_irq_vector(irq, cfg);
raw_spin_unlock_irqrestore(&vector_lock, flags);
free_irq_at(irq, cfg);
}
void destroy_irqs(unsigned int irq, unsigned int count)
{
unsigned int i;
for (i = 0; i < count; i++)
destroy_irq(irq + i);
}
void native_compose_msi_msg(struct pci_dev *pdev,
unsigned int irq, unsigned int dest,
struct msi_msg *msg, u8 hpet_id)
{
struct irq_cfg *cfg = irq_cfg(irq);
msg->address_hi = MSI_ADDR_BASE_HI;
if (x2apic_enabled())
msg->address_hi |= MSI_ADDR_EXT_DEST_ID(dest);
msg->address_lo =
MSI_ADDR_BASE_LO |
((apic->irq_dest_mode == 0) ?
MSI_ADDR_DEST_MODE_PHYSICAL:
MSI_ADDR_DEST_MODE_LOGICAL) |
((apic->irq_delivery_mode != dest_LowestPrio) ?
MSI_ADDR_REDIRECTION_CPU:
MSI_ADDR_REDIRECTION_LOWPRI) |
MSI_ADDR_DEST_ID(dest);
msg->data =
MSI_DATA_TRIGGER_EDGE |
MSI_DATA_LEVEL_ASSERT |
((apic->irq_delivery_mode != dest_LowestPrio) ?
MSI_DATA_DELIVERY_FIXED:
MSI_DATA_DELIVERY_LOWPRI) |
MSI_DATA_VECTOR(cfg->vector);
}
static int msi_compose_msg(struct pci_dev *pdev, unsigned int irq,
struct msi_msg *msg, u8 hpet_id)
{
struct irq_cfg *cfg;
int err;
unsigned dest;
if (disable_apic)
return -ENXIO;
cfg = irq_cfg(irq);
err = assign_irq_vector(irq, cfg, apic->target_cpus());
if (err)
return err;
err = apic->cpu_mask_to_apicid_and(cfg->domain,
apic->target_cpus(), &dest);
if (err)
return err;
x86_msi.compose_msi_msg(pdev, irq, dest, msg, hpet_id);
return 0;
}
static int
msi_set_affinity(struct irq_data *data, const struct cpumask *mask, bool force)
{
struct irq_cfg *cfg = data->chip_data;
struct msi_msg msg;
unsigned int dest;
if (__ioapic_set_affinity(data, mask, &dest))
return -1;
__get_cached_msi_msg(data->msi_desc, &msg);
msg.data &= ~MSI_DATA_VECTOR_MASK;
msg.data |= MSI_DATA_VECTOR(cfg->vector);
msg.address_lo &= ~MSI_ADDR_DEST_ID_MASK;
msg.address_lo |= MSI_ADDR_DEST_ID(dest);
__write_msi_msg(data->msi_desc, &msg);
return IRQ_SET_MASK_OK_NOCOPY;
}
int setup_msi_irq(struct pci_dev *dev, struct msi_desc *msidesc,
unsigned int irq_base, unsigned int irq_offset)
{
struct irq_chip *chip = &msi_chip;
struct msi_msg msg;
unsigned int irq = irq_base + irq_offset;
int ret;
ret = msi_compose_msg(dev, irq, &msg, -1);
if (ret < 0)
return ret;
irq_set_msi_desc_off(irq_base, irq_offset, msidesc);
if (!irq_offset)
write_msi_msg(irq, &msg);
setup_remapped_irq(irq, irq_get_chip_data(irq), chip);
irq_set_chip_and_handler_name(irq, chip, handle_edge_irq, "edge");
dev_printk(KERN_DEBUG, &dev->dev, "irq %d for MSI/MSI-X\n", irq);
return 0;
}
int native_setup_msi_irqs(struct pci_dev *dev, int nvec, int type)
{
unsigned int irq, irq_want;
struct msi_desc *msidesc;
int node, ret;
if (type == PCI_CAP_ID_MSI && nvec > 1)
return 1;
node = dev_to_node(&dev->dev);
irq_want = nr_irqs_gsi;
list_for_each_entry(msidesc, &dev->msi_list, list) {
irq = create_irq_nr(irq_want, node);
if (irq == 0)
return -ENOSPC;
irq_want = irq + 1;
ret = setup_msi_irq(dev, msidesc, irq, 0);
if (ret < 0)
goto error;
}
return 0;
error:
destroy_irq(irq);
return ret;
}
void native_teardown_msi_irq(unsigned int irq)
{
destroy_irq(irq);
}
static int
dmar_msi_set_affinity(struct irq_data *data, const struct cpumask *mask,
bool force)
{
struct irq_cfg *cfg = data->chip_data;
unsigned int dest, irq = data->irq;
struct msi_msg msg;
if (__ioapic_set_affinity(data, mask, &dest))
return -1;
dmar_msi_read(irq, &msg);
msg.data &= ~MSI_DATA_VECTOR_MASK;
msg.data |= MSI_DATA_VECTOR(cfg->vector);
msg.address_lo &= ~MSI_ADDR_DEST_ID_MASK;
msg.address_lo |= MSI_ADDR_DEST_ID(dest);
msg.address_hi = MSI_ADDR_BASE_HI | MSI_ADDR_EXT_DEST_ID(dest);
dmar_msi_write(irq, &msg);
return IRQ_SET_MASK_OK_NOCOPY;
}
int arch_setup_dmar_msi(unsigned int irq)
{
int ret;
struct msi_msg msg;
ret = msi_compose_msg(NULL, irq, &msg, -1);
if (ret < 0)
return ret;
dmar_msi_write(irq, &msg);
irq_set_chip_and_handler_name(irq, &dmar_msi_type, handle_edge_irq,
"edge");
return 0;
}
static int hpet_msi_set_affinity(struct irq_data *data,
const struct cpumask *mask, bool force)
{
struct irq_cfg *cfg = data->chip_data;
struct msi_msg msg;
unsigned int dest;
if (__ioapic_set_affinity(data, mask, &dest))
return -1;
hpet_msi_read(data->handler_data, &msg);
msg.data &= ~MSI_DATA_VECTOR_MASK;
msg.data |= MSI_DATA_VECTOR(cfg->vector);
msg.address_lo &= ~MSI_ADDR_DEST_ID_MASK;
msg.address_lo |= MSI_ADDR_DEST_ID(dest);
hpet_msi_write(data->handler_data, &msg);
return IRQ_SET_MASK_OK_NOCOPY;
}
int default_setup_hpet_msi(unsigned int irq, unsigned int id)
{
struct irq_chip *chip = &hpet_msi_type;
struct msi_msg msg;
int ret;
ret = msi_compose_msg(NULL, irq, &msg, id);
if (ret < 0)
return ret;
hpet_msi_write(irq_get_handler_data(irq), &msg);
irq_set_status_flags(irq, IRQ_MOVE_PCNTXT);
setup_remapped_irq(irq, irq_get_chip_data(irq), chip);
irq_set_chip_and_handler_name(irq, chip, handle_edge_irq, "edge");
return 0;
}
static void target_ht_irq(unsigned int irq, unsigned int dest, u8 vector)
{
struct ht_irq_msg msg;
fetch_ht_irq_msg(irq, &msg);
msg.address_lo &= ~(HT_IRQ_LOW_VECTOR_MASK | HT_IRQ_LOW_DEST_ID_MASK);
msg.address_hi &= ~(HT_IRQ_HIGH_DEST_ID_MASK);
msg.address_lo |= HT_IRQ_LOW_VECTOR(vector) | HT_IRQ_LOW_DEST_ID(dest);
msg.address_hi |= HT_IRQ_HIGH_DEST_ID(dest);
write_ht_irq_msg(irq, &msg);
}
static int
ht_set_affinity(struct irq_data *data, const struct cpumask *mask, bool force)
{
struct irq_cfg *cfg = data->chip_data;
unsigned int dest;
if (__ioapic_set_affinity(data, mask, &dest))
return -1;
target_ht_irq(data->irq, dest, cfg->vector);
return IRQ_SET_MASK_OK_NOCOPY;
}
int arch_setup_ht_irq(unsigned int irq, struct pci_dev *dev)
{
struct irq_cfg *cfg;
struct ht_irq_msg msg;
unsigned dest;
int err;
if (disable_apic)
return -ENXIO;
cfg = irq_cfg(irq);
err = assign_irq_vector(irq, cfg, apic->target_cpus());
if (err)
return err;
err = apic->cpu_mask_to_apicid_and(cfg->domain,
apic->target_cpus(), &dest);
if (err)
return err;
msg.address_hi = HT_IRQ_HIGH_DEST_ID(dest);
msg.address_lo =
HT_IRQ_LOW_BASE |
HT_IRQ_LOW_DEST_ID(dest) |
HT_IRQ_LOW_VECTOR(cfg->vector) |
((apic->irq_dest_mode == 0) ?
HT_IRQ_LOW_DM_PHYSICAL :
HT_IRQ_LOW_DM_LOGICAL) |
HT_IRQ_LOW_RQEOI_EDGE |
((apic->irq_delivery_mode != dest_LowestPrio) ?
HT_IRQ_LOW_MT_FIXED :
HT_IRQ_LOW_MT_ARBITRATED) |
HT_IRQ_LOW_IRQ_MASKED;
write_ht_irq_msg(irq, &msg);
irq_set_chip_and_handler_name(irq, &ht_irq_chip,
handle_edge_irq, "edge");
dev_printk(KERN_DEBUG, &dev->dev, "irq %d for HT\n", irq);
return 0;
}
static int
io_apic_setup_irq_pin(unsigned int irq, int node, struct io_apic_irq_attr *attr)
{
struct irq_cfg *cfg = alloc_irq_and_cfg_at(irq, node);
int ret;
if (!cfg)
return -EINVAL;
ret = __add_pin_to_irq_node(cfg, node, attr->ioapic, attr->ioapic_pin);
if (!ret)
setup_ioapic_irq(irq, cfg, attr);
return ret;
}
int io_apic_setup_irq_pin_once(unsigned int irq, int node,
struct io_apic_irq_attr *attr)
{
unsigned int ioapic_idx = attr->ioapic, pin = attr->ioapic_pin;
int ret;
struct IO_APIC_route_entry orig_entry;
if (test_bit(pin, ioapics[ioapic_idx].pin_programmed)) {
pr_debug("Pin %d-%d already programmed\n", mpc_ioapic_id(ioapic_idx), pin);
orig_entry = ioapic_read_entry(attr->ioapic, pin);
if (attr->trigger == orig_entry.trigger && attr->polarity == orig_entry.polarity)
return 0;
return -EBUSY;
}
ret = io_apic_setup_irq_pin(irq, node, attr);
if (!ret)
set_bit(pin, ioapics[ioapic_idx].pin_programmed);
return ret;
}
static int __init io_apic_get_redir_entries(int ioapic)
{
union IO_APIC_reg_01 reg_01;
unsigned long flags;
raw_spin_lock_irqsave(&ioapic_lock, flags);
reg_01.raw = io_apic_read(ioapic, 1);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
return reg_01.bits.entries + 1;
}
static void __init probe_nr_irqs_gsi(void)
{
int nr;
nr = gsi_top + NR_IRQS_LEGACY;
if (nr > nr_irqs_gsi)
nr_irqs_gsi = nr;
printk(KERN_DEBUG "nr_irqs_gsi: %d\n", nr_irqs_gsi);
}
int get_nr_irqs_gsi(void)
{
return nr_irqs_gsi;
}
int __init arch_probe_nr_irqs(void)
{
int nr;
if (nr_irqs > (NR_VECTORS * nr_cpu_ids))
nr_irqs = NR_VECTORS * nr_cpu_ids;
nr = nr_irqs_gsi + 8 * nr_cpu_ids;
#if defined(CONFIG_PCI_MSI) || defined(CONFIG_HT_IRQ)
nr += nr_irqs_gsi * 16;
#endif
if (nr < nr_irqs)
nr_irqs = nr;
return NR_IRQS_LEGACY;
}
int io_apic_set_pci_routing(struct device *dev, int irq,
struct io_apic_irq_attr *irq_attr)
{
int node;
if (!IO_APIC_IRQ(irq)) {
apic_printk(APIC_QUIET,KERN_ERR "IOAPIC[%d]: Invalid reference to IRQ 0\n",
irq_attr->ioapic);
return -EINVAL;
}
node = dev ? dev_to_node(dev) : cpu_to_node(0);
return io_apic_setup_irq_pin_once(irq, node, irq_attr);
}
static int __init io_apic_get_unique_id(int ioapic, int apic_id)
{
union IO_APIC_reg_00 reg_00;
static physid_mask_t apic_id_map = PHYSID_MASK_NONE;
physid_mask_t tmp;
unsigned long flags;
int i = 0;
if (physids_empty(apic_id_map))
apic->ioapic_phys_id_map(&phys_cpu_present_map, &apic_id_map);
raw_spin_lock_irqsave(&ioapic_lock, flags);
reg_00.raw = io_apic_read(ioapic, 0);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
if (apic_id >= get_physical_broadcast()) {
printk(KERN_WARNING "IOAPIC[%d]: Invalid apic_id %d, trying "
"%d\n", ioapic, apic_id, reg_00.bits.ID);
apic_id = reg_00.bits.ID;
}
if (apic->check_apicid_used(&apic_id_map, apic_id)) {
for (i = 0; i < get_physical_broadcast(); i++) {
if (!apic->check_apicid_used(&apic_id_map, i))
break;
}
if (i == get_physical_broadcast())
panic("Max apic_id exceeded!\n");
printk(KERN_WARNING "IOAPIC[%d]: apic_id %d already used, "
"trying %d\n", ioapic, apic_id, i);
apic_id = i;
}
apic->apicid_to_cpu_present(apic_id, &tmp);
physids_or(apic_id_map, apic_id_map, tmp);
if (reg_00.bits.ID != apic_id) {
reg_00.bits.ID = apic_id;
raw_spin_lock_irqsave(&ioapic_lock, flags);
io_apic_write(ioapic, 0, reg_00.raw);
reg_00.raw = io_apic_read(ioapic, 0);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
if (reg_00.bits.ID != apic_id) {
pr_err("IOAPIC[%d]: Unable to change apic_id!\n",
ioapic);
return -1;
}
}
apic_printk(APIC_VERBOSE, KERN_INFO
"IOAPIC[%d]: Assigned apic_id %d\n", ioapic, apic_id);
return apic_id;
}
static u8 __init io_apic_unique_id(u8 id)
{
if ((boot_cpu_data.x86_vendor == X86_VENDOR_INTEL) &&
!APIC_XAPIC(apic_version[boot_cpu_physical_apicid]))
return io_apic_get_unique_id(nr_ioapics, id);
else
return id;
}
static u8 __init io_apic_unique_id(u8 id)
{
int i;
DECLARE_BITMAP(used, 256);
bitmap_zero(used, 256);
for (i = 0; i < nr_ioapics; i++) {
__set_bit(mpc_ioapic_id(i), used);
}
if (!test_bit(id, used))
return id;
return find_first_zero_bit(used, 256);
}
static int __init io_apic_get_version(int ioapic)
{
union IO_APIC_reg_01 reg_01;
unsigned long flags;
raw_spin_lock_irqsave(&ioapic_lock, flags);
reg_01.raw = io_apic_read(ioapic, 1);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
return reg_01.bits.version;
}
int acpi_get_override_irq(u32 gsi, int *trigger, int *polarity)
{
int ioapic, pin, idx;
if (skip_ioapic_setup)
return -1;
ioapic = mp_find_ioapic(gsi);
if (ioapic < 0)
return -1;
pin = mp_find_ioapic_pin(ioapic, gsi);
if (pin < 0)
return -1;
idx = find_irq_entry(ioapic, pin, mp_INT);
if (idx < 0)
return -1;
*trigger = irq_trigger(idx);
*polarity = irq_polarity(idx);
return 0;
}
void __init setup_ioapic_dest(void)
{
int pin, ioapic, irq, irq_entry;
const struct cpumask *mask;
struct irq_data *idata;
if (skip_ioapic_setup == 1)
return;
for (ioapic = 0; ioapic < nr_ioapics; ioapic++)
for (pin = 0; pin < ioapics[ioapic].nr_registers; pin++) {
irq_entry = find_irq_entry(ioapic, pin, mp_INT);
if (irq_entry == -1)
continue;
irq = pin_2_irq(irq_entry, ioapic, pin);
if ((ioapic > 0) && (irq > 16))
continue;
idata = irq_get_irq_data(irq);
if (!irqd_can_balance(idata) || irqd_affinity_was_set(idata))
mask = idata->affinity;
else
mask = apic->target_cpus();
x86_io_apic_ops.set_affinity(idata, mask, false);
}
}
static struct resource * __init ioapic_setup_resources(int nr_ioapics)
{
unsigned long n;
struct resource *res;
char *mem;
int i;
if (nr_ioapics <= 0)
return NULL;
n = IOAPIC_RESOURCE_NAME_SIZE + sizeof(struct resource);
n *= nr_ioapics;
mem = alloc_bootmem(n);
res = (void *)mem;
mem += sizeof(struct resource) * nr_ioapics;
for (i = 0; i < nr_ioapics; i++) {
res[i].name = mem;
res[i].flags = IORESOURCE_MEM | IORESOURCE_BUSY;
snprintf(mem, IOAPIC_RESOURCE_NAME_SIZE, "IOAPIC %u", i);
mem += IOAPIC_RESOURCE_NAME_SIZE;
}
ioapic_resources = res;
return res;
}
void __init native_io_apic_init_mappings(void)
{
unsigned long ioapic_phys, idx = FIX_IO_APIC_BASE_0;
struct resource *ioapic_res;
int i;
ioapic_res = ioapic_setup_resources(nr_ioapics);
for (i = 0; i < nr_ioapics; i++) {
if (smp_found_config) {
ioapic_phys = mpc_ioapic_addr(i);
#ifdef CONFIG_X86_32
if (!ioapic_phys) {
printk(KERN_ERR
"WARNING: bogus zero IO-APIC "
"address found in MPTABLE, "
"disabling IO/APIC support!\n");
smp_found_config = 0;
skip_ioapic_setup = 1;
goto fake_ioapic_page;
}
#endif
} else {
#ifdef CONFIG_X86_32
fake_ioapic_page:
#endif
ioapic_phys = (unsigned long)alloc_bootmem_pages(PAGE_SIZE);
ioapic_phys = __pa(ioapic_phys);
}
set_fixmap_nocache(idx, ioapic_phys);
apic_printk(APIC_VERBOSE, "mapped IOAPIC to %08lx (%08lx)\n",
__fix_to_virt(idx) + (ioapic_phys & ~PAGE_MASK),
ioapic_phys);
idx++;
ioapic_res->start = ioapic_phys;
ioapic_res->end = ioapic_phys + IO_APIC_SLOT_SIZE - 1;
ioapic_res++;
}
probe_nr_irqs_gsi();
}
void __init ioapic_insert_resources(void)
{
int i;
struct resource *r = ioapic_resources;
if (!r) {
if (nr_ioapics > 0)
printk(KERN_ERR
"IO APIC resources couldn't be allocated.\n");
return;
}
for (i = 0; i < nr_ioapics; i++) {
insert_resource(&iomem_resource, r);
r++;
}
}
int mp_find_ioapic(u32 gsi)
{
int i = 0;
if (nr_ioapics == 0)
return -1;
for (i = 0; i < nr_ioapics; i++) {
struct mp_ioapic_gsi *gsi_cfg = mp_ioapic_gsi_routing(i);
if ((gsi >= gsi_cfg->gsi_base)
&& (gsi <= gsi_cfg->gsi_end))
return i;
}
printk(KERN_ERR "ERROR: Unable to locate IOAPIC for GSI %d\n", gsi);
return -1;
}
int mp_find_ioapic_pin(int ioapic, u32 gsi)
{
struct mp_ioapic_gsi *gsi_cfg;
if (WARN_ON(ioapic == -1))
return -1;
gsi_cfg = mp_ioapic_gsi_routing(ioapic);
if (WARN_ON(gsi > gsi_cfg->gsi_end))
return -1;
return gsi - gsi_cfg->gsi_base;
}
static __init int bad_ioapic(unsigned long address)
{
if (nr_ioapics >= MAX_IO_APICS) {
pr_warn("WARNING: Max # of I/O APICs (%d) exceeded (found %d), skipping\n",
MAX_IO_APICS, nr_ioapics);
return 1;
}
if (!address) {
pr_warn("WARNING: Bogus (zero) I/O APIC address found in table, skipping!\n");
return 1;
}
return 0;
}
static __init int bad_ioapic_register(int idx)
{
union IO_APIC_reg_00 reg_00;
union IO_APIC_reg_01 reg_01;
union IO_APIC_reg_02 reg_02;
reg_00.raw = io_apic_read(idx, 0);
reg_01.raw = io_apic_read(idx, 1);
reg_02.raw = io_apic_read(idx, 2);
if (reg_00.raw == -1 && reg_01.raw == -1 && reg_02.raw == -1) {
pr_warn("I/O APIC 0x%x registers return all ones, skipping!\n",
mpc_ioapic_addr(idx));
return 1;
}
return 0;
}
void __init mp_register_ioapic(int id, u32 address, u32 gsi_base)
{
int idx = 0;
int entries;
struct mp_ioapic_gsi *gsi_cfg;
if (bad_ioapic(address))
return;
idx = nr_ioapics;
ioapics[idx].mp_config.type = MP_IOAPIC;
ioapics[idx].mp_config.flags = MPC_APIC_USABLE;
ioapics[idx].mp_config.apicaddr = address;
set_fixmap_nocache(FIX_IO_APIC_BASE_0 + idx, address);
if (bad_ioapic_register(idx)) {
clear_fixmap(FIX_IO_APIC_BASE_0 + idx);
return;
}
ioapics[idx].mp_config.apicid = io_apic_unique_id(id);
ioapics[idx].mp_config.apicver = io_apic_get_version(idx);
entries = io_apic_get_redir_entries(idx);
gsi_cfg = mp_ioapic_gsi_routing(idx);
gsi_cfg->gsi_base = gsi_base;
gsi_cfg->gsi_end = gsi_base + entries - 1;
ioapics[idx].nr_registers = entries;
if (gsi_cfg->gsi_end >= gsi_top)
gsi_top = gsi_cfg->gsi_end + 1;
pr_info("IOAPIC[%d]: apic_id %d, version %d, address 0x%x, GSI %d-%d\n",
idx, mpc_ioapic_id(idx),
mpc_ioapic_ver(idx), mpc_ioapic_addr(idx),
gsi_cfg->gsi_base, gsi_cfg->gsi_end);
nr_ioapics++;
}
void __init pre_init_apic_IRQ0(void)
{
struct io_apic_irq_attr attr = { 0, 0, 0, 0 };
printk(KERN_INFO "Early APIC setup for system timer0\n");
#ifndef CONFIG_SMP
physid_set_mask_of_physid(boot_cpu_physical_apicid,
&phys_cpu_present_map);
#endif
setup_local_APIC();
io_apic_setup_irq_pin(0, 0, &attr);
irq_set_chip_and_handler_name(0, &ioapic_chip, handle_edge_irq,
"edge");
}
