static inline char pin_name(int pin)
{
return 'A' + pin - 1;
}
static struct acpi_prt_entry *acpi_pci_irq_find_prt_entry(struct pci_dev *dev,
int pin)
{
struct acpi_prt_entry *entry;
int segment = pci_domain_nr(dev->bus);
int bus = dev->bus->number;
int device = PCI_SLOT(dev->devfn);
spin_lock(&acpi_prt_lock);
list_for_each_entry(entry, &acpi_prt_list, list) {
if ((segment == entry->id.segment)
&& (bus == entry->id.bus)
&& (device == entry->id.device)
&& (pin == entry->pin)) {
spin_unlock(&acpi_prt_lock);
return entry;
}
}
spin_unlock(&acpi_prt_lock);
return NULL;
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
static int acpi_pci_irq_add_entry(acpi_handle handle, struct pci_bus *bus,
struct acpi_pci_routing_table *prt)
{
struct acpi_prt_entry *entry;
entry = kzalloc(sizeof(struct acpi_prt_entry), GFP_KERNEL);
if (!entry)
return -ENOMEM;
entry->id.segment = pci_domain_nr(bus);
entry->id.bus = bus->number;
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
spin_lock(&acpi_prt_lock);
list_add_tail(&entry->list, &acpi_prt_list);
spin_unlock(&acpi_prt_lock);
return 0;
}
int acpi_pci_irq_add_prt(acpi_handle handle, struct pci_bus *bus)
{
acpi_status status;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
struct acpi_pci_routing_table *entry;
status = acpi_get_name(handle, ACPI_FULL_PATHNAME, &buffer);
if (ACPI_FAILURE(status))
return -ENODEV;
printk(KERN_DEBUG "ACPI: PCI Interrupt Routing Table [%s._PRT]\n",
(char *) buffer.pointer);
kfree(buffer.pointer);
buffer.length = ACPI_ALLOCATE_BUFFER;
buffer.pointer = NULL;
status = acpi_get_irq_routing_table(handle, &buffer);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Evaluating _PRT [%s]",
acpi_format_exception(status)));
kfree(buffer.pointer);
return -ENODEV;
}
entry = buffer.pointer;
while (entry && (entry->length > 0)) {
acpi_pci_irq_add_entry(handle, bus, entry);
entry = (struct acpi_pci_routing_table *)
((unsigned long)entry + entry->length);
}
kfree(buffer.pointer);
return 0;
}
void acpi_pci_irq_del_prt(struct pci_bus *bus)
{
struct acpi_prt_entry *entry, *tmp;
printk(KERN_DEBUG
"ACPI: Delete PCI Interrupt Routing Table for %04x:%02x\n",
pci_domain_nr(bus), bus->number);
spin_lock(&acpi_prt_lock);
list_for_each_entry_safe(entry, tmp, &acpi_prt_list, list) {
if (pci_domain_nr(bus) == entry->id.segment
&& bus->number == entry->id.bus) {
list_del(&entry->list);
kfree(entry);
}
}
spin_unlock(&acpi_prt_lock);
}
static struct acpi_prt_entry *acpi_pci_irq_lookup(struct pci_dev *dev, int pin)
{
struct acpi_prt_entry *entry;
struct pci_dev *bridge;
u8 bridge_pin, orig_pin = pin;
entry = acpi_pci_irq_find_prt_entry(dev, pin);
if (entry) {
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
entry = acpi_pci_irq_find_prt_entry(bridge, pin);
if (entry) {
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
u32 dev_gsi;
dev_warn(&dev->dev, "PCI INT %c: no GSI", pin_name(pin));
if (dev->irq > 0 && (dev->irq <= 0xF) &&
(acpi_isa_irq_to_gsi(dev->irq, &dev_gsi) == 0)) {
printk(" - using ISA IRQ %d\n", dev->irq);
acpi_register_gsi(&dev->dev, dev_gsi,
ACPI_LEVEL_SENSITIVE,
ACPI_ACTIVE_LOW);
return 0;
} else {
printk("\n");
return 0;
}
}
rc = acpi_register_gsi(&dev->dev, gsi, triggering, polarity);
if (rc < 0) {
dev_warn(&dev->dev, "PCI INT %c: failed to register GSI\n",
pin_name(pin));
return rc;
}
dev->irq = rc;
if (link)
snprintf(link_desc, sizeof(link_desc), " -> Link[%s]", link);
else
link_desc[0] = '\0';
dev_info(&dev->dev, "PCI INT %c%s -> GSI %u (%s, %s) -> IRQ %d\n",
pin_name(pin), link_desc, gsi,
(triggering == ACPI_LEVEL_SENSITIVE) ? "level" : "edge",
(polarity == ACPI_ACTIVE_LOW) ? "low" : "high", dev->irq);
return 0;
}
void acpi_pci_irq_disable(struct pci_dev *dev)
{
struct acpi_prt_entry *entry;
int gsi;
u8 pin;
pin = dev->pin;
if (!pin)
return;
entry = acpi_pci_irq_lookup(dev, pin);
if (!entry)
return;
if (entry->link)
gsi = acpi_pci_link_free_irq(entry->link);
else
gsi = entry->index;
dev_info(&dev->dev, "PCI INT %c disabled\n", pin_name(pin));
acpi_unregister_gsi(gsi);
}
