int mpc_ioapic_id(int ioapic_idx)
{
return ioapics[ioapic_idx].mp_config.apicid;
}
unsigned int mpc_ioapic_addr(int ioapic_idx)
{
return ioapics[ioapic_idx].mp_config.apicaddr;
}
static inline struct mp_ioapic_gsi *mp_ioapic_gsi_routing(int ioapic_idx)
{
return &ioapics[ioapic_idx].gsi_config;
}
static inline int mp_ioapic_pin_count(int ioapic)
{
struct mp_ioapic_gsi *gsi_cfg = mp_ioapic_gsi_routing(ioapic);
return gsi_cfg->gsi_end - gsi_cfg->gsi_base + 1;
}
static inline u32 mp_pin_to_gsi(int ioapic, int pin)
{
return mp_ioapic_gsi_routing(ioapic)->gsi_base + pin;
}
static inline bool mp_is_legacy_irq(int irq)
{
return irq >= 0 && irq < nr_legacy_irqs();
}
static inline int mp_init_irq_at_boot(int ioapic, int irq)
{
if (!nr_legacy_irqs())
return 0;
return ioapic == 0 || mp_is_legacy_irq(irq);
}
static inline struct irq_domain *mp_ioapic_irqdomain(int ioapic)
{
return ioapics[ioapic].irqdomain;
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
static void alloc_ioapic_saved_registers(int idx)
{
size_t size;
if (ioapics[idx].saved_registers)
return;
size = sizeof(struct IO_APIC_route_entry) * ioapics[idx].nr_registers;
ioapics[idx].saved_registers = kzalloc(size, GFP_KERNEL);
if (!ioapics[idx].saved_registers)
pr_err("IOAPIC %d: suspend/resume impossible!\n", idx);
}
static void free_ioapic_saved_registers(int idx)
{
kfree(ioapics[idx].saved_registers);
ioapics[idx].saved_registers = NULL;
}
int __init arch_early_ioapic_init(void)
{
int i;
if (!nr_legacy_irqs())
io_apic_irqs = ~0UL;
for_each_ioapic(i)
alloc_ioapic_saved_registers(i);
return 0;
}
static inline void io_apic_eoi(unsigned int apic, unsigned int vector)
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
static void io_apic_write(unsigned int apic, unsigned int reg,
unsigned int value)
{
struct io_apic __iomem *io_apic = io_apic_base(apic);
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
union entry_union eu = { .entry.mask = IOAPIC_MASKED };
raw_spin_lock_irqsave(&ioapic_lock, flags);
io_apic_write(apic, 0x10 + 2*pin, eu.w1);
io_apic_write(apic, 0x11 + 2*pin, eu.w2);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
}
static int __add_pin_to_irq_node(struct mp_chip_data *data,
int node, int apic, int pin)
{
struct irq_pin_list *entry;
for_each_irq_pin(entry, data->irq_2_pin)
if (entry->apic == apic && entry->pin == pin)
return 0;
entry = kzalloc_node(sizeof(struct irq_pin_list), GFP_ATOMIC, node);
if (!entry) {
pr_err("can not alloc irq_pin_list (%d,%d,%d)\n",
node, apic, pin);
return -ENOMEM;
}
entry->apic = apic;
entry->pin = pin;
list_add_tail(&entry->list, &data->irq_2_pin);
return 0;
}
static void __remove_pin_from_irq(struct mp_chip_data *data, int apic, int pin)
{
struct irq_pin_list *tmp, *entry;
list_for_each_entry_safe(entry, tmp, &data->irq_2_pin, list)
if (entry->apic == apic && entry->pin == pin) {
list_del(&entry->list);
kfree(entry);
return;
}
}
static void add_pin_to_irq_node(struct mp_chip_data *data,
int node, int apic, int pin)
{
if (__add_pin_to_irq_node(data, node, apic, pin))
panic("IO-APIC: failed to add irq-pin. Can not proceed\n");
}
static void __init replace_pin_at_irq_node(struct mp_chip_data *data, int node,
int oldapic, int oldpin,
int newapic, int newpin)
{
struct irq_pin_list *entry;
for_each_irq_pin(entry, data->irq_2_pin) {
if (entry->apic == oldapic && entry->pin == oldpin) {
entry->apic = newapic;
entry->pin = newpin;
return;
}
}
add_pin_to_irq_node(data, node, newapic, newpin);
}
static void io_apic_modify_irq(struct mp_chip_data *data,
int mask_and, int mask_or,
void (*final)(struct irq_pin_list *entry))
{
union entry_union eu;
struct irq_pin_list *entry;
eu.entry = data->entry;
eu.w1 &= mask_and;
eu.w1 |= mask_or;
data->entry = eu.entry;
for_each_irq_pin(entry, data->irq_2_pin) {
io_apic_write(entry->apic, 0x10 + 2 * entry->pin, eu.w1);
if (final)
final(entry);
}
}
static void io_apic_sync(struct irq_pin_list *entry)
{
struct io_apic __iomem *io_apic;
io_apic = io_apic_base(entry->apic);
readl(&io_apic->data);
}
static void mask_ioapic_irq(struct irq_data *irq_data)
{
struct mp_chip_data *data = irq_data->chip_data;
unsigned long flags;
raw_spin_lock_irqsave(&ioapic_lock, flags);
io_apic_modify_irq(data, ~0, IO_APIC_REDIR_MASKED, &io_apic_sync);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
}
static void __unmask_ioapic(struct mp_chip_data *data)
{
io_apic_modify_irq(data, ~IO_APIC_REDIR_MASKED, 0, NULL);
}
static void unmask_ioapic_irq(struct irq_data *irq_data)
{
struct mp_chip_data *data = irq_data->chip_data;
unsigned long flags;
raw_spin_lock_irqsave(&ioapic_lock, flags);
__unmask_ioapic(data);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
}
static void __eoi_ioapic_pin(int apic, int pin, int vector)
{
if (mpc_ioapic_ver(apic) >= 0x20) {
io_apic_eoi(apic, vector);
} else {
struct IO_APIC_route_entry entry, entry1;
entry = entry1 = __ioapic_read_entry(apic, pin);
entry1.mask = IOAPIC_MASKED;
entry1.trigger = IOAPIC_EDGE;
__ioapic_write_entry(apic, pin, entry1);
__ioapic_write_entry(apic, pin, entry);
}
}
static void eoi_ioapic_pin(int vector, struct mp_chip_data *data)
{
unsigned long flags;
struct irq_pin_list *entry;
raw_spin_lock_irqsave(&ioapic_lock, flags);
for_each_irq_pin(entry, data->irq_2_pin)
__eoi_ioapic_pin(entry->apic, entry->pin, vector);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
}
static void clear_IO_APIC_pin(unsigned int apic, unsigned int pin)
{
struct IO_APIC_route_entry entry;
entry = ioapic_read_entry(apic, pin);
if (entry.delivery_mode == dest_SMI)
return;
if (entry.mask == IOAPIC_UNMASKED) {
entry.mask = IOAPIC_MASKED;
ioapic_write_entry(apic, pin, entry);
entry = ioapic_read_entry(apic, pin);
}
if (entry.irr) {
unsigned long flags;
if (entry.trigger == IOAPIC_EDGE) {
entry.trigger = IOAPIC_LEVEL;
ioapic_write_entry(apic, pin, entry);
}
raw_spin_lock_irqsave(&ioapic_lock, flags);
__eoi_ioapic_pin(apic, pin, entry.vector);
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
for_each_ioapic_pin(apic, pin)
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
for_each_ioapic(apic) {
if (!ioapics[apic].saved_registers) {
err = -ENOMEM;
continue;
}
for_each_pin(apic, pin)
ioapics[apic].saved_registers[pin] =
ioapic_read_entry(apic, pin);
}
return err;
}
void mask_ioapic_entries(void)
{
int apic, pin;
for_each_ioapic(apic) {
if (!ioapics[apic].saved_registers)
continue;
for_each_pin(apic, pin) {
struct IO_APIC_route_entry entry;
entry = ioapics[apic].saved_registers[pin];
if (entry.mask == IOAPIC_UNMASKED) {
entry.mask = IOAPIC_MASKED;
ioapic_write_entry(apic, pin, entry);
}
}
}
}
int restore_ioapic_entries(void)
{
int apic, pin;
for_each_ioapic(apic) {
if (!ioapics[apic].saved_registers)
continue;
for_each_pin(apic, pin)
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
for_each_ioapic(ioapic_idx)
if (mpc_ioapic_id(ioapic_idx) == mp_irqs[i].dstapic)
return ioapic_idx;
}
return -1;
}
static int EISA_ELCR(unsigned int irq)
{
if (irq < nr_legacy_irqs()) {
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
switch (mp_irqs[idx].irqflag & 0x03) {
case 0:
if (test_bit(bus, mp_bus_not_pci))
return default_ISA_polarity(idx);
else
return default_PCI_polarity(idx);
case 1:
return IOAPIC_POL_HIGH;
case 2:
pr_warn("IOAPIC: Invalid polarity: 2, defaulting to low\n");
case 3:
default:
return IOAPIC_POL_LOW;
}
}
static int eisa_irq_trigger(int idx, int bus, int trigger)
{
switch (mp_bus_id_to_type[bus]) {
case MP_BUS_PCI:
case MP_BUS_ISA:
return trigger;
case MP_BUS_EISA:
return default_EISA_trigger(idx);
}
pr_warn("IOAPIC: Invalid srcbus: %d defaulting to level\n", bus);
return IOAPIC_LEVEL;
}
static inline int eisa_irq_trigger(int idx, int bus, int trigger)
{
return trigger;
}
static int irq_trigger(int idx)
{
int bus = mp_irqs[idx].srcbus;
int trigger;
switch ((mp_irqs[idx].irqflag >> 2) & 0x03) {
case 0:
if (test_bit(bus, mp_bus_not_pci))
trigger = default_ISA_trigger(idx);
else
trigger = default_PCI_trigger(idx);
return eisa_irq_trigger(idx, bus, trigger);
case 1:
return IOAPIC_EDGE;
case 2:
pr_warn("IOAPIC: Invalid trigger mode 2 defaulting to level\n");
case 3:
default:
return IOAPIC_LEVEL;
}
}
void ioapic_set_alloc_attr(struct irq_alloc_info *info, int node,
int trigger, int polarity)
{
init_irq_alloc_info(info, NULL);
info->type = X86_IRQ_ALLOC_TYPE_IOAPIC;
info->ioapic_node = node;
info->ioapic_trigger = trigger;
info->ioapic_polarity = polarity;
info->ioapic_valid = 1;
}
static void ioapic_copy_alloc_attr(struct irq_alloc_info *dst,
struct irq_alloc_info *src,
u32 gsi, int ioapic_idx, int pin)
{
int trigger, polarity;
copy_irq_alloc_info(dst, src);
dst->type = X86_IRQ_ALLOC_TYPE_IOAPIC;
dst->ioapic_id = mpc_ioapic_id(ioapic_idx);
dst->ioapic_pin = pin;
dst->ioapic_valid = 1;
if (src && src->ioapic_valid) {
dst->ioapic_node = src->ioapic_node;
dst->ioapic_trigger = src->ioapic_trigger;
dst->ioapic_polarity = src->ioapic_polarity;
} else {
dst->ioapic_node = NUMA_NO_NODE;
if (acpi_get_override_irq(gsi, &trigger, &polarity) >= 0) {
dst->ioapic_trigger = trigger;
dst->ioapic_polarity = polarity;
} else {
dst->ioapic_trigger = IOAPIC_LEVEL;
dst->ioapic_polarity = IOAPIC_POL_LOW;
}
}
}
static int ioapic_alloc_attr_node(struct irq_alloc_info *info)
{
return (info && info->ioapic_valid) ? info->ioapic_node : NUMA_NO_NODE;
}
static void mp_register_handler(unsigned int irq, unsigned long trigger)
{
irq_flow_handler_t hdl;
bool fasteoi;
if (trigger) {
irq_set_status_flags(irq, IRQ_LEVEL);
fasteoi = true;
} else {
irq_clear_status_flags(irq, IRQ_LEVEL);
fasteoi = false;
}
hdl = fasteoi ? handle_fasteoi_irq : handle_edge_irq;
__irq_set_handler(irq, hdl, 0, fasteoi ? "fasteoi" : "edge");
}
static bool mp_check_pin_attr(int irq, struct irq_alloc_info *info)
{
struct mp_chip_data *data = irq_get_chip_data(irq);
if (irq < nr_legacy_irqs() && data->count == 1) {
if (info->ioapic_trigger != data->trigger)
mp_register_handler(irq, info->ioapic_trigger);
data->entry.trigger = data->trigger = info->ioapic_trigger;
data->entry.polarity = data->polarity = info->ioapic_polarity;
}
return data->trigger == info->ioapic_trigger &&
data->polarity == info->ioapic_polarity;
}
static int alloc_irq_from_domain(struct irq_domain *domain, int ioapic, u32 gsi,
struct irq_alloc_info *info)
{
bool legacy = false;
int irq = -1;
int type = ioapics[ioapic].irqdomain_cfg.type;
switch (type) {
case IOAPIC_DOMAIN_LEGACY:
if (!ioapic_initialized || gsi >= nr_legacy_irqs())
irq = gsi;
legacy = mp_is_legacy_irq(irq);
break;
case IOAPIC_DOMAIN_STRICT:
irq = gsi;
break;
case IOAPIC_DOMAIN_DYNAMIC:
break;
default:
WARN(1, "ioapic: unknown irqdomain type %d\n", type);
return -1;
}
return __irq_domain_alloc_irqs(domain, irq, 1,
ioapic_alloc_attr_node(info),
info, legacy);
}
static int alloc_isa_irq_from_domain(struct irq_domain *domain,
int irq, int ioapic, int pin,
struct irq_alloc_info *info)
{
struct mp_chip_data *data;
struct irq_data *irq_data = irq_get_irq_data(irq);
int node = ioapic_alloc_attr_node(info);
if (irq_data && irq_data->parent_data) {
if (!mp_check_pin_attr(irq, info))
return -EBUSY;
if (__add_pin_to_irq_node(irq_data->chip_data, node, ioapic,
info->ioapic_pin))
return -ENOMEM;
} else {
irq = __irq_domain_alloc_irqs(domain, irq, 1, node, info, true);
if (irq >= 0) {
irq_data = irq_domain_get_irq_data(domain, irq);
data = irq_data->chip_data;
data->isa_irq = true;
}
}
return irq;
}
static int mp_map_pin_to_irq(u32 gsi, int idx, int ioapic, int pin,
unsigned int flags, struct irq_alloc_info *info)
{
int irq;
bool legacy = false;
struct irq_alloc_info tmp;
struct mp_chip_data *data;
struct irq_domain *domain = mp_ioapic_irqdomain(ioapic);
if (!domain)
return -ENOSYS;
if (idx >= 0 && test_bit(mp_irqs[idx].srcbus, mp_bus_not_pci)) {
irq = mp_irqs[idx].srcbusirq;
legacy = mp_is_legacy_irq(irq);
}
mutex_lock(&ioapic_mutex);
if (!(flags & IOAPIC_MAP_ALLOC)) {
if (!legacy) {
irq = irq_find_mapping(domain, pin);
if (irq == 0)
irq = -ENOENT;
}
} else {
ioapic_copy_alloc_attr(&tmp, info, gsi, ioapic, pin);
if (legacy)
irq = alloc_isa_irq_from_domain(domain, irq,
ioapic, pin, &tmp);
else if ((irq = irq_find_mapping(domain, pin)) == 0)
irq = alloc_irq_from_domain(domain, ioapic, gsi, &tmp);
else if (!mp_check_pin_attr(irq, &tmp))
irq = -EBUSY;
if (irq >= 0) {
data = irq_get_chip_data(irq);
data->count++;
}
}
mutex_unlock(&ioapic_mutex);
return irq;
}
static int pin_2_irq(int idx, int ioapic, int pin, unsigned int flags)
{
u32 gsi = mp_pin_to_gsi(ioapic, pin);
if (mp_irqs[idx].dstirq != pin)
pr_err("broken BIOS or MPTABLE parser, ayiee!!\n");
#ifdef CONFIG_X86_32
if ((pin >= 16) && (pin <= 23)) {
if (pirq_entries[pin-16] != -1) {
if (!pirq_entries[pin-16]) {
apic_printk(APIC_VERBOSE, KERN_DEBUG
"disabling PIRQ%d\n", pin-16);
} else {
int irq = pirq_entries[pin-16];
apic_printk(APIC_VERBOSE, KERN_DEBUG
"using PIRQ%d -> IRQ %d\n",
pin-16, irq);
return irq;
}
}
}
#endif
return mp_map_pin_to_irq(gsi, idx, ioapic, pin, flags, NULL);
}
int mp_map_gsi_to_irq(u32 gsi, unsigned int flags, struct irq_alloc_info *info)
{
int ioapic, pin, idx;
ioapic = mp_find_ioapic(gsi);
if (ioapic < 0)
return -1;
pin = mp_find_ioapic_pin(ioapic, gsi);
idx = find_irq_entry(ioapic, pin, mp_INT);
if ((flags & IOAPIC_MAP_CHECK) && idx < 0)
return -1;
return mp_map_pin_to_irq(gsi, idx, ioapic, pin, flags, info);
}
void mp_unmap_irq(int irq)
{
struct irq_data *irq_data = irq_get_irq_data(irq);
struct mp_chip_data *data;
if (!irq_data || !irq_data->domain)
return;
data = irq_data->chip_data;
if (!data || data->isa_irq)
return;
mutex_lock(&ioapic_mutex);
if (--data->count == 0)
irq_domain_free_irqs(irq, 1);
mutex_unlock(&ioapic_mutex);
}
int IO_APIC_get_PCI_irq_vector(int bus, int slot, int pin)
{
int irq, i, best_ioapic = -1, best_idx = -1;
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
int ioapic_idx, found = 0;
if (bus != lbus || mp_irqs[i].irqtype != mp_INT ||
slot != ((mp_irqs[i].srcbusirq >> 2) & 0x1f))
continue;
for_each_ioapic(ioapic_idx)
if (mpc_ioapic_id(ioapic_idx) == mp_irqs[i].dstapic ||
mp_irqs[i].dstapic == MP_APIC_ALL) {
found = 1;
break;
}
if (!found)
continue;
irq = pin_2_irq(i, ioapic_idx, mp_irqs[i].dstirq, 0);
if (irq > 0 && !IO_APIC_IRQ(irq))
continue;
if (pin == (mp_irqs[i].srcbusirq & 3)) {
best_idx = i;
best_ioapic = ioapic_idx;
goto out;
}
if (best_idx < 0) {
best_idx = i;
best_ioapic = ioapic_idx;
}
}
if (best_idx < 0)
return -1;
out:
return pin_2_irq(best_idx, best_ioapic, mp_irqs[best_idx].dstirq,
IOAPIC_MAP_ALLOC);
}
static inline int IO_APIC_irq_trigger(int irq)
{
int apic, idx, pin;
for_each_ioapic_pin(apic, pin) {
idx = find_irq_entry(apic, pin, mp_INT);
if ((idx != -1) && (irq == pin_2_irq(idx, apic, pin, 0)))
return irq_trigger(idx);
}
return 0;
}
static inline int IO_APIC_irq_trigger(int irq)
{
return 1;
}
static void __init setup_IO_APIC_irqs(void)
{
unsigned int ioapic, pin;
int idx;
apic_printk(APIC_VERBOSE, KERN_DEBUG "init IO_APIC IRQs\n");
for_each_ioapic_pin(ioapic, pin) {
idx = find_irq_entry(ioapic, pin, mp_INT);
if (idx < 0)
apic_printk(APIC_VERBOSE,
KERN_DEBUG " apic %d pin %d not connected\n",
mpc_ioapic_id(ioapic), pin);
else
pin_2_irq(idx, ioapic, pin,
ioapic ? 0 : IOAPIC_MAP_ALLOC);
}
}
void ioapic_zap_locks(void)
{
raw_spin_lock_init(&ioapic_lock);
}
static void io_apic_print_entries(unsigned int apic, unsigned int nr_entries)
{
int i;
char buf[256];
struct IO_APIC_route_entry entry;
struct IR_IO_APIC_route_entry *ir_entry = (void *)&entry;
printk(KERN_DEBUG "IOAPIC %d:\n", apic);
for (i = 0; i <= nr_entries; i++) {
entry = ioapic_read_entry(apic, i);
snprintf(buf, sizeof(buf),
" pin%02x, %s, %s, %s, V(%02X), IRR(%1d), S(%1d)",
i,
entry.mask == IOAPIC_MASKED ? "disabled" : "enabled ",
entry.trigger == IOAPIC_LEVEL ? "level" : "edge ",
entry.polarity == IOAPIC_POL_LOW ? "low " : "high",
entry.vector, entry.irr, entry.delivery_status);
if (ir_entry->format)
printk(KERN_DEBUG "%s, remapped, I(%04X), Z(%X)\n",
buf, (ir_entry->index << 15) | ir_entry->index,
ir_entry->zero);
else
printk(KERN_DEBUG "%s, %s, D(%02X), M(%1d)\n",
buf,
entry.dest_mode == IOAPIC_DEST_MODE_LOGICAL ?
"logical " : "physical",
entry.dest, entry.delivery_mode);
}
}
static void __init print_IO_APIC(int ioapic_idx)
{
union IO_APIC_reg_00 reg_00;
union IO_APIC_reg_01 reg_01;
union IO_APIC_reg_02 reg_02;
union IO_APIC_reg_03 reg_03;
unsigned long flags;
raw_spin_lock_irqsave(&ioapic_lock, flags);
reg_00.raw = io_apic_read(ioapic_idx, 0);
reg_01.raw = io_apic_read(ioapic_idx, 1);
if (reg_01.bits.version >= 0x10)
reg_02.raw = io_apic_read(ioapic_idx, 2);
if (reg_01.bits.version >= 0x20)
reg_03.raw = io_apic_read(ioapic_idx, 3);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
printk(KERN_DEBUG "IO APIC #%d......\n", mpc_ioapic_id(ioapic_idx));
printk(KERN_DEBUG ".... register #00: %08X\n", reg_00.raw);
printk(KERN_DEBUG "....... : physical APIC id: %02X\n", reg_00.bits.ID);
printk(KERN_DEBUG "....... : Delivery Type: %X\n", reg_00.bits.delivery_type);
printk(KERN_DEBUG "....... : LTS : %X\n", reg_00.bits.LTS);
printk(KERN_DEBUG ".... register #01: %08X\n", *(int *)&reg_01);
printk(KERN_DEBUG "....... : max redirection entries: %02X\n",
reg_01.bits.entries);
printk(KERN_DEBUG "....... : PRQ implemented: %X\n", reg_01.bits.PRQ);
printk(KERN_DEBUG "....... : IO APIC version: %02X\n",
reg_01.bits.version);
if (reg_01.bits.version >= 0x10 && reg_02.raw != reg_01.raw) {
printk(KERN_DEBUG ".... register #02: %08X\n", reg_02.raw);
printk(KERN_DEBUG "....... : arbitration: %02X\n", reg_02.bits.arbitration);
}
if (reg_01.bits.version >= 0x20 && reg_03.raw != reg_02.raw &&
reg_03.raw != reg_01.raw) {
printk(KERN_DEBUG ".... register #03: %08X\n", reg_03.raw);
printk(KERN_DEBUG "....... : Boot DT : %X\n", reg_03.bits.boot_DT);
}
printk(KERN_DEBUG ".... IRQ redirection table:\n");
io_apic_print_entries(ioapic_idx, reg_01.bits.entries);
}
void __init print_IO_APICs(void)
{
int ioapic_idx;
unsigned int irq;
printk(KERN_DEBUG "number of MP IRQ sources: %d.\n", mp_irq_entries);
for_each_ioapic(ioapic_idx)
printk(KERN_DEBUG "number of IO-APIC #%d registers: %d.\n",
mpc_ioapic_id(ioapic_idx),
ioapics[ioapic_idx].nr_registers);
printk(KERN_INFO "testing the IO APIC.......................\n");
for_each_ioapic(ioapic_idx)
print_IO_APIC(ioapic_idx);
printk(KERN_DEBUG "IRQ to pin mappings:\n");
for_each_active_irq(irq) {
struct irq_pin_list *entry;
struct irq_chip *chip;
struct mp_chip_data *data;
chip = irq_get_chip(irq);
if (chip != &ioapic_chip && chip != &ioapic_ir_chip)
continue;
data = irq_get_chip_data(irq);
if (!data)
continue;
if (list_empty(&data->irq_2_pin))
continue;
printk(KERN_DEBUG "IRQ%d ", irq);
for_each_irq_pin(entry, data->irq_2_pin)
pr_cont("-> %d:%d", entry->apic, entry->pin);
pr_cont("\n");
}
printk(KERN_INFO ".................................... done.\n");
}
void __init enable_IO_APIC(void)
{
int i8259_apic, i8259_pin;
int apic, pin;
if (skip_ioapic_setup)
nr_ioapics = 0;
if (!nr_legacy_irqs() || !nr_ioapics)
return;
for_each_ioapic_pin(apic, pin) {
struct IO_APIC_route_entry entry = ioapic_read_entry(apic, pin);
if ((entry.mask == 0) && (entry.delivery_mode == dest_ExtINT)) {
ioapic_i8259.apic = apic;
ioapic_i8259.pin = pin;
goto found_i8259;
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
entry.mask = IOAPIC_UNMASKED;
entry.trigger = IOAPIC_EDGE;
entry.polarity = IOAPIC_POL_HIGH;
entry.dest_mode = IOAPIC_DEST_MODE_PHYSICAL;
entry.delivery_mode = dest_ExtINT;
entry.dest = read_apic_id();
ioapic_write_entry(ioapic_i8259.apic, ioapic_i8259.pin, entry);
}
if (cpu_has_apic || apic_from_smp_config())
disconnect_bsp_APIC(ioapic_i8259.pin != -1);
}
void disable_IO_APIC(void)
{
clear_IO_APIC();
if (!nr_legacy_irqs())
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
for_each_ioapic(ioapic_idx) {
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
if (irq < nr_legacy_irqs()) {
legacy_pic->mask(irq);
if (legacy_pic->irq_pending(irq))
was_pending = 1;
}
__unmask_ioapic(data->chip_data);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
return was_pending;
}
static bool io_apic_level_ack_pending(struct mp_chip_data *data)
{
struct irq_pin_list *entry;
unsigned long flags;
raw_spin_lock_irqsave(&ioapic_lock, flags);
for_each_irq_pin(entry, data->irq_2_pin) {
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
static inline bool ioapic_irqd_mask(struct irq_data *data)
{
if (unlikely(irqd_is_setaffinity_pending(data))) {
mask_ioapic_irq(data);
return true;
}
return false;
}
static inline void ioapic_irqd_unmask(struct irq_data *data, bool masked)
{
if (unlikely(masked)) {
if (!io_apic_level_ack_pending(data->chip_data))
irq_move_masked_irq(data);
unmask_ioapic_irq(data);
}
}
static inline bool ioapic_irqd_mask(struct irq_data *data)
{
return false;
}
static inline void ioapic_irqd_unmask(struct irq_data *data, bool masked)
{
}
static void ioapic_ack_level(struct irq_data *irq_data)
{
struct irq_cfg *cfg = irqd_cfg(irq_data);
unsigned long v;
bool masked;
int i;
irq_complete_move(cfg);
masked = ioapic_irqd_mask(irq_data);
i = cfg->vector;
v = apic_read(APIC_TMR + ((i & ~0x1f) >> 1));
ack_APIC_irq();
if (!(v & (1 << (i & 0x1f)))) {
atomic_inc(&irq_mis_count);
eoi_ioapic_pin(cfg->vector, irq_data->chip_data);
}
ioapic_irqd_unmask(irq_data, masked);
}
static void ioapic_ir_ack_level(struct irq_data *irq_data)
{
struct mp_chip_data *data = irq_data->chip_data;
ack_APIC_irq();
eoi_ioapic_pin(data->entry.vector, data);
}
static int ioapic_set_affinity(struct irq_data *irq_data,
const struct cpumask *mask, bool force)
{
struct irq_data *parent = irq_data->parent_data;
struct mp_chip_data *data = irq_data->chip_data;
struct irq_pin_list *entry;
struct irq_cfg *cfg;
unsigned long flags;
int ret;
ret = parent->chip->irq_set_affinity(parent, mask, force);
raw_spin_lock_irqsave(&ioapic_lock, flags);
if (ret >= 0 && ret != IRQ_SET_MASK_OK_DONE) {
cfg = irqd_cfg(irq_data);
data->entry.dest = cfg->dest_apicid;
data->entry.vector = cfg->vector;
for_each_irq_pin(entry, data->irq_2_pin)
__ioapic_write_entry(entry->apic, entry->pin,
data->entry);
}
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
return ret;
}
static inline void init_IO_APIC_traps(void)
{
struct irq_cfg *cfg;
unsigned int irq;
for_each_active_irq(irq) {
cfg = irq_cfg(irq);
if (IO_APIC_IRQ(irq) && cfg && !cfg->vector) {
if (irq < nr_legacy_irqs())
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
entry1.dest_mode = IOAPIC_DEST_MODE_PHYSICAL;
entry1.mask = IOAPIC_UNMASKED;
entry1.dest = hard_smp_processor_id();
entry1.delivery_mode = dest_ExtINT;
entry1.polarity = entry0.polarity;
entry1.trigger = IOAPIC_EDGE;
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
static int mp_alloc_timer_irq(int ioapic, int pin)
{
int irq = -1;
struct irq_domain *domain = mp_ioapic_irqdomain(ioapic);
if (domain) {
struct irq_alloc_info info;
ioapic_set_alloc_attr(&info, NUMA_NO_NODE, 0, 0);
info.ioapic_id = mpc_ioapic_id(ioapic);
info.ioapic_pin = pin;
mutex_lock(&ioapic_mutex);
irq = alloc_isa_irq_from_domain(domain, 0, ioapic, pin, &info);
mutex_unlock(&ioapic_mutex);
}
return irq;
}
static inline void __init check_timer(void)
{
struct irq_data *irq_data = irq_get_irq_data(0);
struct mp_chip_data *data = irq_data->chip_data;
struct irq_cfg *cfg = irqd_cfg(irq_data);
int node = cpu_to_node(0);
int apic1, pin1, apic2, pin2;
unsigned long flags;
int no_pin1 = 0;
local_irq_save(flags);
legacy_pic->mask(0);
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
mp_alloc_timer_irq(apic1, pin1);
} else {
int idx;
idx = find_irq_entry(apic1, pin1, mp_INT);
if (idx != -1 && irq_trigger(idx))
unmask_ioapic_irq(irq_get_chip_data(0));
}
irq_domain_activate_irq(irq_data);
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
replace_pin_at_irq_node(data, node, apic1, pin1, apic2, pin2);
irq_domain_activate_irq(irq_data);
legacy_pic->unmask(0);
if (timer_irq_works()) {
apic_printk(APIC_QUIET, KERN_INFO "....... works.\n");
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
if (apic_is_x2apic_enabled())
apic_printk(APIC_QUIET, KERN_INFO
"Perhaps problem with the pre-enabled x2apic mode\n"
"Try booting with x2apic and interrupt-remapping disabled in the bios.\n");
panic("IO-APIC + timer doesn't work! Boot with apic=debug and send a "
"report. Then try booting with the 'noapic' option.\n");
out:
local_irq_restore(flags);
}
static int mp_irqdomain_create(int ioapic)
{
struct irq_alloc_info info;
struct irq_domain *parent;
int hwirqs = mp_ioapic_pin_count(ioapic);
struct ioapic *ip = &ioapics[ioapic];
struct ioapic_domain_cfg *cfg = &ip->irqdomain_cfg;
struct mp_ioapic_gsi *gsi_cfg = mp_ioapic_gsi_routing(ioapic);
if (cfg->type == IOAPIC_DOMAIN_INVALID)
return 0;
init_irq_alloc_info(&info, NULL);
info.type = X86_IRQ_ALLOC_TYPE_IOAPIC;
info.ioapic_id = mpc_ioapic_id(ioapic);
parent = irq_remapping_get_ir_irq_domain(&info);
if (!parent)
parent = x86_vector_domain;
ip->irqdomain = irq_domain_add_linear(cfg->dev, hwirqs, cfg->ops,
(void *)(long)ioapic);
if (!ip->irqdomain)
return -ENOMEM;
ip->irqdomain->parent = parent;
if (cfg->type == IOAPIC_DOMAIN_LEGACY ||
cfg->type == IOAPIC_DOMAIN_STRICT)
ioapic_dynirq_base = max(ioapic_dynirq_base,
gsi_cfg->gsi_end + 1);
return 0;
}
static void ioapic_destroy_irqdomain(int idx)
{
if (ioapics[idx].irqdomain) {
irq_domain_remove(ioapics[idx].irqdomain);
ioapics[idx].irqdomain = NULL;
}
}
void __init setup_IO_APIC(void)
{
int ioapic;
if (skip_ioapic_setup || !nr_ioapics)
return;
io_apic_irqs = nr_legacy_irqs() ? ~PIC_IRQS : ~0UL;
apic_printk(APIC_VERBOSE, "ENABLING IO-APIC IRQs\n");
for_each_ioapic(ioapic)
BUG_ON(mp_irqdomain_create(ioapic));
x86_init.mpparse.setup_ioapic_ids();
sync_Arb_IDs();
setup_IO_APIC_irqs();
init_IO_APIC_traps();
if (nr_legacy_irqs())
check_timer();
ioapic_initialized = 1;
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
for_each_ioapic_reverse(ioapic_idx)
resume_ioapic_id(ioapic_idx);
restore_ioapic_entries();
}
static int __init ioapic_init_ops(void)
{
register_syscore_ops(&ioapic_syscore_ops);
return 0;
}
static int io_apic_get_redir_entries(int ioapic)
{
union IO_APIC_reg_01 reg_01;
unsigned long flags;
raw_spin_lock_irqsave(&ioapic_lock, flags);
reg_01.raw = io_apic_read(ioapic, 1);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
return reg_01.bits.entries + 1;
}
unsigned int arch_dynirq_lower_bound(unsigned int from)
{
return ioapic_initialized ? ioapic_dynirq_base : gsi_top;
}
static int io_apic_get_unique_id(int ioapic, int apic_id)
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
static u8 io_apic_unique_id(int idx, u8 id)
{
if ((boot_cpu_data.x86_vendor == X86_VENDOR_INTEL) &&
!APIC_XAPIC(apic_version[boot_cpu_physical_apicid]))
return io_apic_get_unique_id(idx, id);
else
return id;
}
static u8 io_apic_unique_id(int idx, u8 id)
{
union IO_APIC_reg_00 reg_00;
DECLARE_BITMAP(used, 256);
unsigned long flags;
u8 new_id;
int i;
bitmap_zero(used, 256);
for_each_ioapic(i)
__set_bit(mpc_ioapic_id(i), used);
if (!test_bit(id, used))
return id;
raw_spin_lock_irqsave(&ioapic_lock, flags);
reg_00.raw = io_apic_read(idx, 0);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
new_id = reg_00.bits.ID;
if (!test_bit(new_id, used)) {
apic_printk(APIC_VERBOSE, KERN_INFO
"IOAPIC[%d]: Using reg apic_id %d instead of %d\n",
idx, new_id, id);
return new_id;
}
new_id = find_first_zero_bit(used, 256);
reg_00.bits.ID = new_id;
raw_spin_lock_irqsave(&ioapic_lock, flags);
io_apic_write(idx, 0, reg_00.raw);
reg_00.raw = io_apic_read(idx, 0);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
BUG_ON(reg_00.bits.ID != new_id);
return new_id;
}
static int io_apic_get_version(int ioapic)
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
struct irq_chip *chip;
if (skip_ioapic_setup == 1)
return;
for_each_ioapic_pin(ioapic, pin) {
irq_entry = find_irq_entry(ioapic, pin, mp_INT);
if (irq_entry == -1)
continue;
irq = pin_2_irq(irq_entry, ioapic, pin, 0);
if (irq < 0 || !mp_init_irq_at_boot(ioapic, irq))
continue;
idata = irq_get_irq_data(irq);
if (!irqd_can_balance(idata) || irqd_affinity_was_set(idata))
mask = irq_data_get_affinity_mask(idata);
else
mask = apic->target_cpus();
chip = irq_data_get_irq_chip(idata);
if (chip->irq_set_affinity)
chip->irq_set_affinity(idata, mask, false);
}
}
static struct resource * __init ioapic_setup_resources(void)
{
unsigned long n;
struct resource *res;
char *mem;
int i, num = 0;
for_each_ioapic(i)
num++;
if (num == 0)
return NULL;
n = IOAPIC_RESOURCE_NAME_SIZE + sizeof(struct resource);
n *= num;
mem = alloc_bootmem(n);
res = (void *)mem;
mem += sizeof(struct resource) * num;
num = 0;
for_each_ioapic(i) {
res[num].name = mem;
res[num].flags = IORESOURCE_MEM | IORESOURCE_BUSY;
snprintf(mem, IOAPIC_RESOURCE_NAME_SIZE, "IOAPIC %u", i);
mem += IOAPIC_RESOURCE_NAME_SIZE;
num++;
ioapics[i].iomem_res = res;
}
ioapic_resources = res;
return res;
}
void __init io_apic_init_mappings(void)
{
unsigned long ioapic_phys, idx = FIX_IO_APIC_BASE_0;
struct resource *ioapic_res;
int i;
ioapic_res = ioapic_setup_resources();
for_each_ioapic(i) {
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
for_each_ioapic(i) {
insert_resource(&iomem_resource, r);
r++;
}
}
int mp_find_ioapic(u32 gsi)
{
int i;
if (nr_ioapics == 0)
return -1;
for_each_ioapic(i) {
struct mp_ioapic_gsi *gsi_cfg = mp_ioapic_gsi_routing(i);
if (gsi >= gsi_cfg->gsi_base && gsi <= gsi_cfg->gsi_end)
return i;
}
printk(KERN_ERR "ERROR: Unable to locate IOAPIC for GSI %d\n", gsi);
return -1;
}
int mp_find_ioapic_pin(int ioapic, u32 gsi)
{
struct mp_ioapic_gsi *gsi_cfg;
if (WARN_ON(ioapic < 0))
return -1;
gsi_cfg = mp_ioapic_gsi_routing(ioapic);
if (WARN_ON(gsi > gsi_cfg->gsi_end))
return -1;
return gsi - gsi_cfg->gsi_base;
}
static int bad_ioapic_register(int idx)
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
static int find_free_ioapic_entry(void)
{
int idx;
for (idx = 0; idx < MAX_IO_APICS; idx++)
if (ioapics[idx].nr_registers == 0)
return idx;
return MAX_IO_APICS;
}
int mp_register_ioapic(int id, u32 address, u32 gsi_base,
struct ioapic_domain_cfg *cfg)
{
bool hotplug = !!ioapic_initialized;
struct mp_ioapic_gsi *gsi_cfg;
int idx, ioapic, entries;
u32 gsi_end;
if (!address) {
pr_warn("Bogus (zero) I/O APIC address found, skipping!\n");
return -EINVAL;
}
for_each_ioapic(ioapic)
if (ioapics[ioapic].mp_config.apicaddr == address) {
pr_warn("address 0x%x conflicts with IOAPIC%d\n",
address, ioapic);
return -EEXIST;
}
idx = find_free_ioapic_entry();
if (idx >= MAX_IO_APICS) {
pr_warn("Max # of I/O APICs (%d) exceeded (found %d), skipping\n",
MAX_IO_APICS, idx);
return -ENOSPC;
}
ioapics[idx].mp_config.type = MP_IOAPIC;
ioapics[idx].mp_config.flags = MPC_APIC_USABLE;
ioapics[idx].mp_config.apicaddr = address;
set_fixmap_nocache(FIX_IO_APIC_BASE_0 + idx, address);
if (bad_ioapic_register(idx)) {
clear_fixmap(FIX_IO_APIC_BASE_0 + idx);
return -ENODEV;
}
ioapics[idx].mp_config.apicid = io_apic_unique_id(idx, id);
ioapics[idx].mp_config.apicver = io_apic_get_version(idx);
entries = io_apic_get_redir_entries(idx);
gsi_end = gsi_base + entries - 1;
for_each_ioapic(ioapic) {
gsi_cfg = mp_ioapic_gsi_routing(ioapic);
if ((gsi_base >= gsi_cfg->gsi_base &&
gsi_base <= gsi_cfg->gsi_end) ||
(gsi_end >= gsi_cfg->gsi_base &&
gsi_end <= gsi_cfg->gsi_end)) {
pr_warn("GSI range [%u-%u] for new IOAPIC conflicts with GSI[%u-%u]\n",
gsi_base, gsi_end,
gsi_cfg->gsi_base, gsi_cfg->gsi_end);
clear_fixmap(FIX_IO_APIC_BASE_0 + idx);
return -ENOSPC;
}
}
gsi_cfg = mp_ioapic_gsi_routing(idx);
gsi_cfg->gsi_base = gsi_base;
gsi_cfg->gsi_end = gsi_end;
ioapics[idx].irqdomain = NULL;
ioapics[idx].irqdomain_cfg = *cfg;
if (hotplug) {
if (mp_irqdomain_create(idx)) {
clear_fixmap(FIX_IO_APIC_BASE_0 + idx);
return -ENOMEM;
}
alloc_ioapic_saved_registers(idx);
}
if (gsi_cfg->gsi_end >= gsi_top)
gsi_top = gsi_cfg->gsi_end + 1;
if (nr_ioapics <= idx)
nr_ioapics = idx + 1;
ioapics[idx].nr_registers = entries;
pr_info("IOAPIC[%d]: apic_id %d, version %d, address 0x%x, GSI %d-%d\n",
idx, mpc_ioapic_id(idx),
mpc_ioapic_ver(idx), mpc_ioapic_addr(idx),
gsi_cfg->gsi_base, gsi_cfg->gsi_end);
return 0;
}
int mp_unregister_ioapic(u32 gsi_base)
{
int ioapic, pin;
int found = 0;
for_each_ioapic(ioapic)
if (ioapics[ioapic].gsi_config.gsi_base == gsi_base) {
found = 1;
break;
}
if (!found) {
pr_warn("can't find IOAPIC for GSI %d\n", gsi_base);
return -ENODEV;
}
for_each_pin(ioapic, pin) {
u32 gsi = mp_pin_to_gsi(ioapic, pin);
int irq = mp_map_gsi_to_irq(gsi, 0, NULL);
struct mp_chip_data *data;
if (irq >= 0) {
data = irq_get_chip_data(irq);
if (data && data->count) {
pr_warn("pin%d on IOAPIC%d is still in use.\n",
pin, ioapic);
return -EBUSY;
}
}
}
ioapics[ioapic].nr_registers = 0;
ioapic_destroy_irqdomain(ioapic);
free_ioapic_saved_registers(ioapic);
if (ioapics[ioapic].iomem_res)
release_resource(ioapics[ioapic].iomem_res);
clear_fixmap(FIX_IO_APIC_BASE_0 + ioapic);
memset(&ioapics[ioapic], 0, sizeof(ioapics[ioapic]));
return 0;
}
int mp_ioapic_registered(u32 gsi_base)
{
int ioapic;
for_each_ioapic(ioapic)
if (ioapics[ioapic].gsi_config.gsi_base == gsi_base)
return 1;
return 0;
}
static void mp_irqdomain_get_attr(u32 gsi, struct mp_chip_data *data,
struct irq_alloc_info *info)
{
if (info && info->ioapic_valid) {
data->trigger = info->ioapic_trigger;
data->polarity = info->ioapic_polarity;
} else if (acpi_get_override_irq(gsi, &data->trigger,
&data->polarity) < 0) {
data->trigger = IOAPIC_LEVEL;
data->polarity = IOAPIC_POL_LOW;
}
}
static void mp_setup_entry(struct irq_cfg *cfg, struct mp_chip_data *data,
struct IO_APIC_route_entry *entry)
{
memset(entry, 0, sizeof(*entry));
entry->delivery_mode = apic->irq_delivery_mode;
entry->dest_mode = apic->irq_dest_mode;
entry->dest = cfg->dest_apicid;
entry->vector = cfg->vector;
entry->trigger = data->trigger;
entry->polarity = data->polarity;
if (data->trigger == IOAPIC_LEVEL)
entry->mask = IOAPIC_MASKED;
else
entry->mask = IOAPIC_UNMASKED;
}
int mp_irqdomain_alloc(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs, void *arg)
{
int ret, ioapic, pin;
struct irq_cfg *cfg;
struct irq_data *irq_data;
struct mp_chip_data *data;
struct irq_alloc_info *info = arg;
unsigned long flags;
if (!info || nr_irqs > 1)
return -EINVAL;
irq_data = irq_domain_get_irq_data(domain, virq);
if (!irq_data)
return -EINVAL;
ioapic = mp_irqdomain_ioapic_idx(domain);
pin = info->ioapic_pin;
if (irq_find_mapping(domain, (irq_hw_number_t)pin) > 0)
return -EEXIST;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
info->ioapic_entry = &data->entry;
ret = irq_domain_alloc_irqs_parent(domain, virq, nr_irqs, info);
if (ret < 0) {
kfree(data);
return ret;
}
INIT_LIST_HEAD(&data->irq_2_pin);
irq_data->hwirq = info->ioapic_pin;
irq_data->chip = (domain->parent == x86_vector_domain) ?
&ioapic_chip : &ioapic_ir_chip;
irq_data->chip_data = data;
mp_irqdomain_get_attr(mp_pin_to_gsi(ioapic, pin), data, info);
cfg = irqd_cfg(irq_data);
add_pin_to_irq_node(data, ioapic_alloc_attr_node(info), ioapic, pin);
local_irq_save(flags);
if (info->ioapic_entry)
mp_setup_entry(cfg, data, info->ioapic_entry);
mp_register_handler(virq, data->trigger);
if (virq < nr_legacy_irqs())
legacy_pic->mask(virq);
local_irq_restore(flags);
apic_printk(APIC_VERBOSE, KERN_DEBUG
"IOAPIC[%d]: Set routing entry (%d-%d -> 0x%x -> IRQ %d Mode:%i Active:%i Dest:%d)\n",
ioapic, mpc_ioapic_id(ioapic), pin, cfg->vector,
virq, data->trigger, data->polarity, cfg->dest_apicid);
return 0;
}
void mp_irqdomain_free(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs)
{
struct irq_data *irq_data;
struct mp_chip_data *data;
BUG_ON(nr_irqs != 1);
irq_data = irq_domain_get_irq_data(domain, virq);
if (irq_data && irq_data->chip_data) {
data = irq_data->chip_data;
__remove_pin_from_irq(data, mp_irqdomain_ioapic_idx(domain),
(int)irq_data->hwirq);
WARN_ON(!list_empty(&data->irq_2_pin));
kfree(irq_data->chip_data);
}
irq_domain_free_irqs_top(domain, virq, nr_irqs);
}
void mp_irqdomain_activate(struct irq_domain *domain,
struct irq_data *irq_data)
{
unsigned long flags;
struct irq_pin_list *entry;
struct mp_chip_data *data = irq_data->chip_data;
raw_spin_lock_irqsave(&ioapic_lock, flags);
for_each_irq_pin(entry, data->irq_2_pin)
__ioapic_write_entry(entry->apic, entry->pin, data->entry);
raw_spin_unlock_irqrestore(&ioapic_lock, flags);
}
void mp_irqdomain_deactivate(struct irq_domain *domain,
struct irq_data *irq_data)
{
ioapic_mask_entry(mp_irqdomain_ioapic_idx(domain),
(int)irq_data->hwirq);
}
int mp_irqdomain_ioapic_idx(struct irq_domain *domain)
{
return (int)(long)domain->host_data;
}
