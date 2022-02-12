static inline char pin_name(int pin)
{
return 'A' + pin - 1;
}
static void do_prt_fixups(struct acpi_prt_entry *entry,
struct acpi_pci_routing_table *prt)
{
int i;
const struct prt_quirk *quirk;
for (i = 0; i < ARRAY_SIZE(prt_quirks); i++) {
quirk = &prt_quirks[i];
if (!prt->source)
continue;
if (dmi_check_system(quirk->system) &&
entry->id.segment == quirk->segment &&
entry->id.bus == quirk->bus &&
entry->id.device == quirk->device &&
entry->pin == quirk->pin &&
!strcmp(prt->source, quirk->source) &&
strlen(prt->source) >= strlen(quirk->actual_source)) {
printk(KERN_WARNING PREFIX "firmware reports "
"%04x:%02x:%02x PCI INT %c connected to %s; "
"changing to %s\n",
entry->id.segment, entry->id.bus,
entry->id.device, pin_name(entry->pin),
prt->source, quirk->actual_source);
strcpy(prt->source, quirk->actual_source);
}
}
}
static int acpi_pci_irq_check_entry(acpi_handle handle, struct pci_dev *dev,
int pin, struct acpi_pci_routing_table *prt,
struct acpi_prt_entry **entry_ptr)
{
int segment = pci_domain_nr(dev->bus);
int bus = dev->bus->number;
int device = PCI_SLOT(dev->devfn);
struct acpi_prt_entry *entry;
if (((prt->address >> 16) & 0xffff) != device ||
prt->pin + 1 != pin)
return -ENODEV;
entry = kzalloc(sizeof(struct acpi_prt_entry), GFP_KERNEL);
if (!entry)
return -ENOMEM;
entry->id.segment = segment;
entry->id.bus = bus;
entry->id.device = (prt->address >> 16) & 0xFFFF;
entry->pin = prt->pin + 1;
do_prt_fixups(entry, prt);
entry->index = prt->source_index;
if (prt->source[0])
acpi_get_handle(handle, prt->source, &entry->link);
ACPI_DEBUG_PRINT_RAW((ACPI_DB_INFO,
" %04x:%02x:%02x[%c] -> %s[%d]\n",
entry->id.segment, entry->id.bus,
entry->id.device, pin_name(entry->pin),
prt->source, entry->index));
*entry_ptr = entry;
return 0;
}
static int acpi_pci_irq_find_prt_entry(struct pci_dev *dev,
int pin, struct acpi_prt_entry **entry_ptr)
{
acpi_status status;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
struct acpi_pci_routing_table *entry;
acpi_handle handle = NULL;
if (dev->bus->bridge)
handle = ACPI_HANDLE(dev->bus->bridge);
if (!handle)
return -ENODEV;
status = acpi_get_irq_routing_table(handle, &buffer);
if (ACPI_FAILURE(status)) {
kfree(buffer.pointer);
return -ENODEV;
}
entry = buffer.pointer;
while (entry && (entry->length > 0)) {
if (!acpi_pci_irq_check_entry(handle, dev, pin,
entry, entry_ptr))
break;
entry = (struct acpi_pci_routing_table *)
((unsigned long)entry + entry->length);
}
kfree(buffer.pointer);
return 0;
}
static int bridge_has_boot_interrupt_variant(struct pci_bus *bus)
{
struct pci_bus *bus_it;
for (bus_it = bus ; bus_it ; bus_it = bus_it->parent) {
if (!bus_it->self)
return 0;
if (bus_it->self->irq_reroute_variant)
return bus_it->self->irq_reroute_variant;
}
return 0;
}
static int acpi_reroute_boot_interrupt(struct pci_dev *dev,
struct acpi_prt_entry *entry)
{
if (noioapicquirk || noioapicreroute) {
return 0;
} else {
switch (bridge_has_boot_interrupt_variant(dev->bus)) {
case 0:
return 0;
case INTEL_IRQ_REROUTE_VARIANT:
dev_info(&dev->dev, "PCI IRQ %d -> rerouted to legacy "
"IRQ %d\n", entry->index,
(entry->index % 4) + 16);
entry->index = (entry->index % 4) + 16;
return 1;
default:
dev_warn(&dev->dev, "Cannot reroute IRQ %d to legacy "
"IRQ: unknown mapping\n", entry->index);
return -1;
}
}
}
static struct acpi_prt_entry *acpi_pci_irq_lookup(struct pci_dev *dev, int pin)
{
struct acpi_prt_entry *entry = NULL;
struct pci_dev *bridge;
u8 bridge_pin, orig_pin = pin;
int ret;
ret = acpi_pci_irq_find_prt_entry(dev, pin, &entry);
if (!ret && entry) {
#ifdef CONFIG_X86_IO_APIC
acpi_reroute_boot_interrupt(dev, entry);
#endif
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Found %s[%c] _PRT entry\n",
pci_name(dev), pin_name(pin)));
return entry;
}
bridge = dev->bus->self;
while (bridge) {
pin = pci_swizzle_interrupt_pin(dev, pin);
if ((bridge->class >> 8) == PCI_CLASS_BRIDGE_CARDBUS) {
bridge_pin = bridge->pin;
if (!bridge_pin) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"No interrupt pin configured for device %s\n",
pci_name(bridge)));
return NULL;
}
pin = bridge_pin;
}
ret = acpi_pci_irq_find_prt_entry(bridge, pin, &entry);
if (!ret && entry) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Derived GSI for %s INT %c from %s\n",
pci_name(dev), pin_name(orig_pin),
pci_name(bridge)));
return entry;
}
dev = bridge;
bridge = dev->bus->self;
}
dev_warn(&dev->dev, "can't derive routing for PCI INT %c\n",
pin_name(orig_pin));
return NULL;
}
static int acpi_isa_register_gsi(struct pci_dev *dev)
{
u32 dev_gsi;
if (dev->irq > 0 && (dev->irq <= 0xF) &&
(acpi_isa_irq_to_gsi(dev->irq, &dev_gsi) == 0)) {
dev_warn(&dev->dev, "PCI INT %c: no GSI - using ISA IRQ %d\n",
pin_name(dev->pin), dev->irq);
acpi_register_gsi(&dev->dev, dev_gsi,
ACPI_LEVEL_SENSITIVE,
ACPI_ACTIVE_LOW);
return 0;
}
return -EINVAL;
}
static inline int acpi_isa_register_gsi(struct pci_dev *dev)
{
return -ENODEV;
}
int acpi_pci_irq_enable(struct pci_dev *dev)
{
struct acpi_prt_entry *entry;
int gsi;
u8 pin;
int triggering = ACPI_LEVEL_SENSITIVE;
int polarity = ACPI_ACTIVE_LOW;
char *link = NULL;
char link_desc[16];
int rc;
pin = dev->pin;
if (!pin) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"No interrupt pin configured for device %s\n",
pci_name(dev)));
return 0;
}
if (dev->irq_managed && dev->irq > 0)
return 0;
entry = acpi_pci_irq_lookup(dev, pin);
if (!entry) {
if (dev->class >> 8 == PCI_CLASS_STORAGE_IDE &&
(dev->class & 0x05) == 0)
return 0;
}
if (entry) {
if (entry->link)
gsi = acpi_pci_link_allocate_irq(entry->link,
entry->index,
&triggering, &polarity,
&link);
else
gsi = entry->index;
} else
gsi = -1;
if (gsi < 0) {
if (acpi_isa_register_gsi(dev))
dev_warn(&dev->dev, "PCI INT %c: no GSI\n",
pin_name(pin));
kfree(entry);
return 0;
}
rc = acpi_register_gsi(&dev->dev, gsi, triggering, polarity);
if (rc < 0) {
dev_warn(&dev->dev, "PCI INT %c: failed to register GSI\n",
pin_name(pin));
kfree(entry);
return rc;
}
dev->irq = rc;
dev->irq_managed = 1;
if (link)
snprintf(link_desc, sizeof(link_desc), " -> Link[%s]", link);
else
link_desc[0] = '\0';
dev_dbg(&dev->dev, "PCI INT %c%s -> GSI %u (%s, %s) -> IRQ %d\n",
pin_name(pin), link_desc, gsi,
(triggering == ACPI_LEVEL_SENSITIVE) ? "level" : "edge",
(polarity == ACPI_ACTIVE_LOW) ? "low" : "high", dev->irq);
kfree(entry);
return 0;
}
void acpi_pci_irq_disable(struct pci_dev *dev)
{
struct acpi_prt_entry *entry;
int gsi;
u8 pin;
pin = dev->pin;
if (!pin || !dev->irq_managed || dev->irq <= 0)
return;
if (dev->dev.power.is_prepared)
return;
#ifdef CONFIG_PM
if (dev->dev.power.runtime_status == RPM_SUSPENDING)
return;
#endif
entry = acpi_pci_irq_lookup(dev, pin);
if (!entry)
return;
if (entry->link)
gsi = acpi_pci_link_free_irq(entry->link);
else
gsi = entry->index;
kfree(entry);
dev_dbg(&dev->dev, "PCI INT %c disabled\n", pin_name(pin));
if (gsi >= 0) {
acpi_unregister_gsi(gsi);
dev->irq_managed = 0;
}
}
