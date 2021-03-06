static acpi_status acpi_pci_link_check_possible(struct acpi_resource *resource,
void *context)
{
struct acpi_pci_link *link = context;
u32 i;
switch (resource->type) {
case ACPI_RESOURCE_TYPE_START_DEPENDENT:
case ACPI_RESOURCE_TYPE_END_TAG:
return AE_OK;
case ACPI_RESOURCE_TYPE_IRQ:
{
struct acpi_resource_irq *p = &resource->data.irq;
if (!p || !p->interrupt_count) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Blank _PRS IRQ resource\n"));
return AE_OK;
}
for (i = 0;
(i < p->interrupt_count
&& i < ACPI_PCI_LINK_MAX_POSSIBLE); i++) {
if (!p->interrupts[i]) {
printk(KERN_WARNING PREFIX
"Invalid _PRS IRQ %d\n",
p->interrupts[i]);
continue;
}
link->irq.possible[i] = p->interrupts[i];
link->irq.possible_count++;
}
link->irq.triggering = p->triggering;
link->irq.polarity = p->polarity;
link->irq.resource_type = ACPI_RESOURCE_TYPE_IRQ;
break;
}
case ACPI_RESOURCE_TYPE_EXTENDED_IRQ:
{
struct acpi_resource_extended_irq *p =
&resource->data.extended_irq;
if (!p || !p->interrupt_count) {
printk(KERN_WARNING PREFIX
"Blank _PRS EXT IRQ resource\n");
return AE_OK;
}
for (i = 0;
(i < p->interrupt_count
&& i < ACPI_PCI_LINK_MAX_POSSIBLE); i++) {
if (!p->interrupts[i]) {
printk(KERN_WARNING PREFIX
"Invalid _PRS IRQ %d\n",
p->interrupts[i]);
continue;
}
link->irq.possible[i] = p->interrupts[i];
link->irq.possible_count++;
}
link->irq.triggering = p->triggering;
link->irq.polarity = p->polarity;
link->irq.resource_type = ACPI_RESOURCE_TYPE_EXTENDED_IRQ;
break;
}
default:
printk(KERN_ERR PREFIX "_PRS resource type 0x%x isn't an IRQ\n",
resource->type);
return AE_OK;
}
return AE_CTRL_TERMINATE;
}
static int acpi_pci_link_get_possible(struct acpi_pci_link *link)
{
acpi_status status;
status = acpi_walk_resources(link->device->handle, METHOD_NAME__PRS,
acpi_pci_link_check_possible, link);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Evaluating _PRS"));
return -ENODEV;
}
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Found %d possible IRQs\n",
link->irq.possible_count));
return 0;
}
static acpi_status acpi_pci_link_check_current(struct acpi_resource *resource,
void *context)
{
int *irq = context;
switch (resource->type) {
case ACPI_RESOURCE_TYPE_START_DEPENDENT:
case ACPI_RESOURCE_TYPE_END_TAG:
return AE_OK;
case ACPI_RESOURCE_TYPE_IRQ:
{
struct acpi_resource_irq *p = &resource->data.irq;
if (!p || !p->interrupt_count) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Blank _CRS IRQ resource\n"));
return AE_OK;
}
*irq = p->interrupts[0];
break;
}
case ACPI_RESOURCE_TYPE_EXTENDED_IRQ:
{
struct acpi_resource_extended_irq *p =
&resource->data.extended_irq;
if (!p || !p->interrupt_count) {
printk(KERN_WARNING PREFIX
"Blank _CRS EXT IRQ resource\n");
return AE_OK;
}
*irq = p->interrupts[0];
break;
}
break;
default:
printk(KERN_ERR PREFIX "_CRS resource type 0x%x isn't an IRQ\n",
resource->type);
return AE_OK;
}
return AE_CTRL_TERMINATE;
}
static int acpi_pci_link_get_current(struct acpi_pci_link *link)
{
int result = 0;
acpi_status status;
int irq = 0;
link->irq.active = 0;
if (acpi_strict) {
result = acpi_bus_get_status(link->device);
if (result) {
printk(KERN_ERR PREFIX "Unable to read status\n");
goto end;
}
if (!link->device->status.enabled) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Link disabled\n"));
return 0;
}
}
status = acpi_walk_resources(link->device->handle, METHOD_NAME__CRS,
acpi_pci_link_check_current, &irq);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Evaluating _CRS"));
result = -ENODEV;
goto end;
}
if (acpi_strict && !irq) {
printk(KERN_ERR PREFIX "_CRS returned 0\n");
result = -ENODEV;
}
link->irq.active = irq;
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Link at IRQ %d \n", link->irq.active));
end:
return result;
}
static int acpi_pci_link_set(struct acpi_pci_link *link, int irq)
{
int result;
acpi_status status;
struct {
struct acpi_resource res;
struct acpi_resource end;
} *resource;
struct acpi_buffer buffer = { 0, NULL };
if (!irq)
return -EINVAL;
resource = kzalloc(sizeof(*resource) + 1, irqs_disabled() ? GFP_ATOMIC: GFP_KERNEL);
if (!resource)
return -ENOMEM;
buffer.length = sizeof(*resource) + 1;
buffer.pointer = resource;
switch (link->irq.resource_type) {
case ACPI_RESOURCE_TYPE_IRQ:
resource->res.type = ACPI_RESOURCE_TYPE_IRQ;
resource->res.length = sizeof(struct acpi_resource);
resource->res.data.irq.triggering = link->irq.triggering;
resource->res.data.irq.polarity =
link->irq.polarity;
if (link->irq.triggering == ACPI_EDGE_SENSITIVE)
resource->res.data.irq.sharable =
ACPI_EXCLUSIVE;
else
resource->res.data.irq.sharable = ACPI_SHARED;
resource->res.data.irq.interrupt_count = 1;
resource->res.data.irq.interrupts[0] = irq;
break;
case ACPI_RESOURCE_TYPE_EXTENDED_IRQ:
resource->res.type = ACPI_RESOURCE_TYPE_EXTENDED_IRQ;
resource->res.length = sizeof(struct acpi_resource);
resource->res.data.extended_irq.producer_consumer =
ACPI_CONSUMER;
resource->res.data.extended_irq.triggering =
link->irq.triggering;
resource->res.data.extended_irq.polarity =
link->irq.polarity;
if (link->irq.triggering == ACPI_EDGE_SENSITIVE)
resource->res.data.irq.sharable =
ACPI_EXCLUSIVE;
else
resource->res.data.irq.sharable = ACPI_SHARED;
resource->res.data.extended_irq.interrupt_count = 1;
resource->res.data.extended_irq.interrupts[0] = irq;
break;
default:
printk(KERN_ERR PREFIX "Invalid Resource_type %d\n", link->irq.resource_type);
result = -EINVAL;
goto end;
}
resource->end.type = ACPI_RESOURCE_TYPE_END_TAG;
resource->end.length = sizeof(struct acpi_resource);
status = acpi_set_current_resources(link->device->handle, &buffer);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Evaluating _SRS"));
result = -ENODEV;
goto end;
}
result = acpi_bus_get_status(link->device);
if (result) {
printk(KERN_ERR PREFIX "Unable to read status\n");
goto end;
}
if (!link->device->status.enabled) {
printk(KERN_WARNING PREFIX
"%s [%s] disabled and referenced, BIOS bug\n",
acpi_device_name(link->device),
acpi_device_bid(link->device));
}
result = acpi_pci_link_get_current(link);
if (result) {
goto end;
}
if (link->irq.active != irq) {
printk(KERN_WARNING PREFIX
"%s [%s] BIOS reported IRQ %d, using IRQ %d\n",
acpi_device_name(link->device),
acpi_device_bid(link->device), link->irq.active, irq);
link->irq.active = irq;
}
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Set IRQ %d\n", link->irq.active));
end:
kfree(resource);
return result;
}
int __init acpi_irq_penalty_init(void)
{
struct acpi_pci_link *link;
int i;
list_for_each_entry(link, &acpi_link_list, list) {
if (link->irq.possible_count) {
int penalty =
PIRQ_PENALTY_PCI_POSSIBLE /
link->irq.possible_count;
for (i = 0; i < link->irq.possible_count; i++) {
if (link->irq.possible[i] < ACPI_MAX_ISA_IRQ)
acpi_irq_penalty[link->irq.
possible[i]] +=
penalty;
}
} else if (link->irq.active) {
acpi_irq_penalty[link->irq.active] +=
PIRQ_PENALTY_PCI_POSSIBLE;
}
}
return 0;
}
static int acpi_pci_link_allocate(struct acpi_pci_link *link)
{
int irq;
int i;
if (link->irq.initialized) {
if (link->refcnt == 0)
acpi_pci_link_set(link, link->irq.active);
return 0;
}
for (i = 0; i < link->irq.possible_count; ++i) {
if (link->irq.active == link->irq.possible[i])
break;
}
if (i == link->irq.possible_count) {
if (acpi_strict)
printk(KERN_WARNING PREFIX "_CRS %d not found"
" in _PRS\n", link->irq.active);
link->irq.active = 0;
}
if (link->irq.active)
irq = link->irq.active;
else
irq = link->irq.possible[link->irq.possible_count - 1];
if (acpi_irq_balance || !link->irq.active) {
for (i = (link->irq.possible_count - 1); i >= 0; i--) {
if (acpi_irq_penalty[irq] >
acpi_irq_penalty[link->irq.possible[i]])
irq = link->irq.possible[i];
}
}
if (acpi_irq_penalty[irq] >= PIRQ_PENALTY_ISA_ALWAYS) {
printk(KERN_ERR PREFIX "No IRQ available for %s [%s]. "
"Try pci=noacpi or acpi=off\n",
acpi_device_name(link->device),
acpi_device_bid(link->device));
return -ENODEV;
}
if (acpi_pci_link_set(link, irq)) {
printk(KERN_ERR PREFIX "Unable to set IRQ for %s [%s]. "
"Try pci=noacpi or acpi=off\n",
acpi_device_name(link->device),
acpi_device_bid(link->device));
return -ENODEV;
} else {
acpi_irq_penalty[link->irq.active] += PIRQ_PENALTY_PCI_USING;
printk(KERN_WARNING PREFIX "%s [%s] enabled at IRQ %d\n",
acpi_device_name(link->device),
acpi_device_bid(link->device), link->irq.active);
}
link->irq.initialized = 1;
return 0;
}
int acpi_pci_link_allocate_irq(acpi_handle handle, int index, int *triggering,
int *polarity, char **name)
{
int result;
struct acpi_device *device;
struct acpi_pci_link *link;
result = acpi_bus_get_device(handle, &device);
if (result) {
printk(KERN_ERR PREFIX "Invalid link device\n");
return -1;
}
link = acpi_driver_data(device);
if (!link) {
printk(KERN_ERR PREFIX "Invalid link context\n");
return -1;
}
if (index) {
printk(KERN_ERR PREFIX "Invalid index %d\n", index);
return -1;
}
mutex_lock(&acpi_link_lock);
if (acpi_pci_link_allocate(link)) {
mutex_unlock(&acpi_link_lock);
return -1;
}
if (!link->irq.active) {
mutex_unlock(&acpi_link_lock);
printk(KERN_ERR PREFIX "Link active IRQ is 0!\n");
return -1;
}
link->refcnt++;
mutex_unlock(&acpi_link_lock);
if (triggering)
*triggering = link->irq.triggering;
if (polarity)
*polarity = link->irq.polarity;
if (name)
*name = acpi_device_bid(link->device);
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Link %s is referenced\n",
acpi_device_bid(link->device)));
return (link->irq.active);
}
int acpi_pci_link_free_irq(acpi_handle handle)
{
struct acpi_device *device;
struct acpi_pci_link *link;
acpi_status result;
result = acpi_bus_get_device(handle, &device);
if (result) {
printk(KERN_ERR PREFIX "Invalid link device\n");
return -1;
}
link = acpi_driver_data(device);
if (!link) {
printk(KERN_ERR PREFIX "Invalid link context\n");
return -1;
}
mutex_lock(&acpi_link_lock);
if (!link->irq.initialized) {
mutex_unlock(&acpi_link_lock);
printk(KERN_ERR PREFIX "Link isn't initialized\n");
return -1;
}
#ifdef FUTURE_USE
link->refcnt--;
#endif
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Link %s is dereferenced\n",
acpi_device_bid(link->device)));
if (link->refcnt == 0)
acpi_evaluate_object(link->device->handle, "_DIS", NULL, NULL);
mutex_unlock(&acpi_link_lock);
return (link->irq.active);
}
static int acpi_pci_link_add(struct acpi_device *device,
const struct acpi_device_id *not_used)
{
int result;
struct acpi_pci_link *link;
int i;
int found = 0;
link = kzalloc(sizeof(struct acpi_pci_link), GFP_KERNEL);
if (!link)
return -ENOMEM;
link->device = device;
strcpy(acpi_device_name(device), ACPI_PCI_LINK_DEVICE_NAME);
strcpy(acpi_device_class(device), ACPI_PCI_LINK_CLASS);
device->driver_data = link;
mutex_lock(&acpi_link_lock);
result = acpi_pci_link_get_possible(link);
if (result)
goto end;
acpi_pci_link_get_current(link);
printk(KERN_INFO PREFIX "%s [%s] (IRQs", acpi_device_name(device),
acpi_device_bid(device));
for (i = 0; i < link->irq.possible_count; i++) {
if (link->irq.active == link->irq.possible[i]) {
printk(KERN_CONT " *%d", link->irq.possible[i]);
found = 1;
} else
printk(KERN_CONT " %d", link->irq.possible[i]);
}
printk(KERN_CONT ")");
if (!found)
printk(KERN_CONT " *%d", link->irq.active);
if (!link->device->status.enabled)
printk(KERN_CONT ", disabled.");
printk(KERN_CONT "\n");
list_add_tail(&link->list, &acpi_link_list);
end:
acpi_evaluate_object(device->handle, "_DIS", NULL, NULL);
mutex_unlock(&acpi_link_lock);
if (result)
kfree(link);
return result < 0 ? result : 1;
}
static int acpi_pci_link_resume(struct acpi_pci_link *link)
{
if (link->refcnt && link->irq.active && link->irq.initialized)
return (acpi_pci_link_set(link, link->irq.active));
return 0;
}
static void irqrouter_resume(void)
{
struct acpi_pci_link *link;
list_for_each_entry(link, &acpi_link_list, list) {
acpi_pci_link_resume(link);
}
}
static void acpi_pci_link_remove(struct acpi_device *device)
{
struct acpi_pci_link *link;
link = acpi_driver_data(device);
mutex_lock(&acpi_link_lock);
list_del(&link->list);
mutex_unlock(&acpi_link_lock);
kfree(link);
}
static int __init acpi_irq_penalty_update(char *str, int used)
{
int i;
for (i = 0; i < 16; i++) {
int retval;
int irq;
retval = get_option(&str, &irq);
if (!retval)
break;
if (irq < 0)
continue;
if (irq >= ARRAY_SIZE(acpi_irq_penalty))
continue;
if (used)
acpi_irq_penalty[irq] += PIRQ_PENALTY_ISA_USED;
else
acpi_irq_penalty[irq] = PIRQ_PENALTY_PCI_AVAILABLE;
if (retval != 2)
break;
}
return 1;
}
void acpi_penalize_isa_irq(int irq, int active)
{
if (irq >= 0 && irq < ARRAY_SIZE(acpi_irq_penalty)) {
if (active)
acpi_irq_penalty[irq] += PIRQ_PENALTY_ISA_USED;
else
acpi_irq_penalty[irq] += PIRQ_PENALTY_PCI_USING;
}
}
bool acpi_isa_irq_available(int irq)
{
return irq >= 0 && (irq >= ARRAY_SIZE(acpi_irq_penalty) ||
acpi_irq_penalty[irq] < PIRQ_PENALTY_ISA_ALWAYS);
}
void acpi_penalize_sci_irq(int irq, int trigger, int polarity)
{
if (irq >= 0 && irq < ARRAY_SIZE(acpi_irq_penalty)) {
if (trigger != ACPI_MADT_TRIGGER_LEVEL ||
polarity != ACPI_MADT_POLARITY_ACTIVE_LOW)
acpi_irq_penalty[irq] += PIRQ_PENALTY_ISA_ALWAYS;
else
acpi_irq_penalty[irq] += PIRQ_PENALTY_PCI_USING;
}
}
static int __init acpi_irq_isa(char *str)
{
return acpi_irq_penalty_update(str, 1);
}
static int __init acpi_irq_pci(char *str)
{
return acpi_irq_penalty_update(str, 0);
}
static int __init acpi_irq_nobalance_set(char *str)
{
acpi_irq_balance = 0;
return 1;
}
static int __init acpi_irq_balance_set(char *str)
{
acpi_irq_balance = 1;
return 1;
}
void __init acpi_pci_link_init(void)
{
if (acpi_noirq)
return;
if (acpi_irq_balance == -1) {
if (acpi_irq_model == ACPI_IRQ_MODEL_IOAPIC)
acpi_irq_balance = 1;
else
acpi_irq_balance = 0;
}
register_syscore_ops(&irqrouter_syscore_ops);
acpi_scan_add_handler(&pci_link_handler);
}
