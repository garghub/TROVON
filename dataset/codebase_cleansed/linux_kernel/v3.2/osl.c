static u32 acpi_osi_handler(acpi_string interface, u32 supported)
{
if (!strcmp("Linux", interface)) {
printk_once(KERN_NOTICE FW_BUG PREFIX
"BIOS _OSI(Linux) query %s%s\n",
osi_linux.enable ? "honored" : "ignored",
osi_linux.cmdline ? " via cmdline" :
osi_linux.dmi ? " via DMI" : "");
}
return supported;
}
static void __init acpi_request_region (struct acpi_generic_address *addr,
unsigned int length, char *desc)
{
if (!addr->address || !length)
return;
if (addr->space_id == ACPI_ADR_SPACE_SYSTEM_IO)
request_region(addr->address, length, desc);
else if (addr->space_id == ACPI_ADR_SPACE_SYSTEM_MEMORY)
request_mem_region(addr->address, length, desc);
}
static int __init acpi_reserve_resources(void)
{
acpi_request_region(&acpi_gbl_FADT.xpm1a_event_block, acpi_gbl_FADT.pm1_event_length,
"ACPI PM1a_EVT_BLK");
acpi_request_region(&acpi_gbl_FADT.xpm1b_event_block, acpi_gbl_FADT.pm1_event_length,
"ACPI PM1b_EVT_BLK");
acpi_request_region(&acpi_gbl_FADT.xpm1a_control_block, acpi_gbl_FADT.pm1_control_length,
"ACPI PM1a_CNT_BLK");
acpi_request_region(&acpi_gbl_FADT.xpm1b_control_block, acpi_gbl_FADT.pm1_control_length,
"ACPI PM1b_CNT_BLK");
if (acpi_gbl_FADT.pm_timer_length == 4)
acpi_request_region(&acpi_gbl_FADT.xpm_timer_block, 4, "ACPI PM_TMR");
acpi_request_region(&acpi_gbl_FADT.xpm2_control_block, acpi_gbl_FADT.pm2_control_length,
"ACPI PM2_CNT_BLK");
if (!(acpi_gbl_FADT.gpe0_block_length & 0x1))
acpi_request_region(&acpi_gbl_FADT.xgpe0_block,
acpi_gbl_FADT.gpe0_block_length, "ACPI GPE0_BLK");
if (!(acpi_gbl_FADT.gpe1_block_length & 0x1))
acpi_request_region(&acpi_gbl_FADT.xgpe1_block,
acpi_gbl_FADT.gpe1_block_length, "ACPI GPE1_BLK");
return 0;
}
void acpi_os_printf(const char *fmt, ...)
{
va_list args;
va_start(args, fmt);
acpi_os_vprintf(fmt, args);
va_end(args);
}
void acpi_os_vprintf(const char *fmt, va_list args)
{
static char buffer[512];
vsprintf(buffer, fmt, args);
#ifdef ENABLE_DEBUGGER
if (acpi_in_debugger) {
kdb_printf("%s", buffer);
} else {
printk(KERN_CONT "%s", buffer);
}
#else
printk(KERN_CONT "%s", buffer);
#endif
}
static int __init setup_acpi_rsdp(char *arg)
{
acpi_rsdp = simple_strtoul(arg, NULL, 16);
return 0;
}
acpi_physical_address __init acpi_os_get_root_pointer(void)
{
#ifdef CONFIG_KEXEC
if (acpi_rsdp)
return acpi_rsdp;
#endif
if (efi_enabled) {
if (efi.acpi20 != EFI_INVALID_TABLE_ADDR)
return efi.acpi20;
else if (efi.acpi != EFI_INVALID_TABLE_ADDR)
return efi.acpi;
else {
printk(KERN_ERR PREFIX
"System description tables not found\n");
return 0;
}
} else {
acpi_physical_address pa = 0;
acpi_find_root_pointer(&pa);
return pa;
}
}
static struct acpi_ioremap *
acpi_map_lookup(acpi_physical_address phys, acpi_size size)
{
struct acpi_ioremap *map;
list_for_each_entry_rcu(map, &acpi_ioremaps, list)
if (map->phys <= phys &&
phys + size <= map->phys + map->size)
return map;
return NULL;
}
static void __iomem *
acpi_map_vaddr_lookup(acpi_physical_address phys, unsigned int size)
{
struct acpi_ioremap *map;
map = acpi_map_lookup(phys, size);
if (map)
return map->virt + (phys - map->phys);
return NULL;
}
void __iomem *acpi_os_get_iomem(acpi_physical_address phys, unsigned int size)
{
struct acpi_ioremap *map;
void __iomem *virt = NULL;
mutex_lock(&acpi_ioremap_lock);
map = acpi_map_lookup(phys, size);
if (map) {
virt = map->virt + (phys - map->phys);
map->refcount++;
}
mutex_unlock(&acpi_ioremap_lock);
return virt;
}
static struct acpi_ioremap *
acpi_map_lookup_virt(void __iomem *virt, acpi_size size)
{
struct acpi_ioremap *map;
list_for_each_entry_rcu(map, &acpi_ioremaps, list)
if (map->virt <= virt &&
virt + size <= map->virt + map->size)
return map;
return NULL;
}
void __iomem *__init_refok
acpi_os_map_memory(acpi_physical_address phys, acpi_size size)
{
struct acpi_ioremap *map;
void __iomem *virt;
acpi_physical_address pg_off;
acpi_size pg_sz;
if (phys > ULONG_MAX) {
printk(KERN_ERR PREFIX "Cannot map memory that high\n");
return NULL;
}
if (!acpi_gbl_permanent_mmap)
return __acpi_map_table((unsigned long)phys, size);
mutex_lock(&acpi_ioremap_lock);
map = acpi_map_lookup(phys, size);
if (map) {
map->refcount++;
goto out;
}
map = kzalloc(sizeof(*map), GFP_KERNEL);
if (!map) {
mutex_unlock(&acpi_ioremap_lock);
return NULL;
}
pg_off = round_down(phys, PAGE_SIZE);
pg_sz = round_up(phys + size, PAGE_SIZE) - pg_off;
virt = acpi_os_ioremap(pg_off, pg_sz);
if (!virt) {
mutex_unlock(&acpi_ioremap_lock);
kfree(map);
return NULL;
}
INIT_LIST_HEAD(&map->list);
map->virt = virt;
map->phys = pg_off;
map->size = pg_sz;
map->refcount = 1;
list_add_tail_rcu(&map->list, &acpi_ioremaps);
out:
mutex_unlock(&acpi_ioremap_lock);
return map->virt + (phys - map->phys);
}
static void acpi_os_drop_map_ref(struct acpi_ioremap *map)
{
if (!--map->refcount)
list_del_rcu(&map->list);
}
static void acpi_os_map_cleanup(struct acpi_ioremap *map)
{
if (!map->refcount) {
synchronize_rcu();
iounmap(map->virt);
kfree(map);
}
}
void __ref acpi_os_unmap_memory(void __iomem *virt, acpi_size size)
{
struct acpi_ioremap *map;
if (!acpi_gbl_permanent_mmap) {
__acpi_unmap_table(virt, size);
return;
}
mutex_lock(&acpi_ioremap_lock);
map = acpi_map_lookup_virt(virt, size);
if (!map) {
mutex_unlock(&acpi_ioremap_lock);
WARN(true, PREFIX "%s: bad address %p\n", __func__, virt);
return;
}
acpi_os_drop_map_ref(map);
mutex_unlock(&acpi_ioremap_lock);
acpi_os_map_cleanup(map);
}
void __init early_acpi_os_unmap_memory(void __iomem *virt, acpi_size size)
{
if (!acpi_gbl_permanent_mmap)
__acpi_unmap_table(virt, size);
}
static int acpi_os_map_generic_address(struct acpi_generic_address *addr)
{
void __iomem *virt;
if (addr->space_id != ACPI_ADR_SPACE_SYSTEM_MEMORY)
return 0;
if (!addr->address || !addr->bit_width)
return -EINVAL;
virt = acpi_os_map_memory(addr->address, addr->bit_width / 8);
if (!virt)
return -EIO;
return 0;
}
static void acpi_os_unmap_generic_address(struct acpi_generic_address *addr)
{
struct acpi_ioremap *map;
if (addr->space_id != ACPI_ADR_SPACE_SYSTEM_MEMORY)
return;
if (!addr->address || !addr->bit_width)
return;
mutex_lock(&acpi_ioremap_lock);
map = acpi_map_lookup(addr->address, addr->bit_width / 8);
if (!map) {
mutex_unlock(&acpi_ioremap_lock);
return;
}
acpi_os_drop_map_ref(map);
mutex_unlock(&acpi_ioremap_lock);
acpi_os_map_cleanup(map);
}
acpi_status
acpi_os_get_physical_address(void *virt, acpi_physical_address * phys)
{
if (!phys || !virt)
return AE_BAD_PARAMETER;
*phys = virt_to_phys(virt);
return AE_OK;
}
acpi_status
acpi_os_predefined_override(const struct acpi_predefined_names *init_val,
acpi_string * new_val)
{
if (!init_val || !new_val)
return AE_BAD_PARAMETER;
*new_val = NULL;
if (!memcmp(init_val->name, "_OS_", 4) && strlen(acpi_os_name)) {
printk(KERN_INFO PREFIX "Overriding _OS definition to '%s'\n",
acpi_os_name);
*new_val = acpi_os_name;
}
return AE_OK;
}
acpi_status
acpi_os_table_override(struct acpi_table_header * existing_table,
struct acpi_table_header ** new_table)
{
if (!existing_table || !new_table)
return AE_BAD_PARAMETER;
*new_table = NULL;
#ifdef CONFIG_ACPI_CUSTOM_DSDT
if (strncmp(existing_table->signature, "DSDT", 4) == 0)
*new_table = (struct acpi_table_header *)AmlCode;
#endif
if (*new_table != NULL) {
printk(KERN_WARNING PREFIX "Override [%4.4s-%8.8s], "
"this is unsafe: tainting kernel\n",
existing_table->signature,
existing_table->oem_table_id);
add_taint(TAINT_OVERRIDDEN_ACPI_TABLE);
}
return AE_OK;
}
static irqreturn_t acpi_irq(int irq, void *dev_id)
{
u32 handled;
handled = (*acpi_irq_handler) (acpi_irq_context);
if (handled) {
acpi_irq_handled++;
return IRQ_HANDLED;
} else {
acpi_irq_not_handled++;
return IRQ_NONE;
}
}
acpi_status
acpi_os_install_interrupt_handler(u32 gsi, acpi_osd_handler handler,
void *context)
{
unsigned int irq;
acpi_irq_stats_init();
if (gsi != acpi_gbl_FADT.sci_interrupt)
return AE_BAD_PARAMETER;
if (acpi_irq_handler)
return AE_ALREADY_ACQUIRED;
if (acpi_gsi_to_irq(gsi, &irq) < 0) {
printk(KERN_ERR PREFIX "SCI (ACPI GSI %d) not registered\n",
gsi);
return AE_OK;
}
acpi_irq_handler = handler;
acpi_irq_context = context;
if (request_irq(irq, acpi_irq, IRQF_SHARED, "acpi", acpi_irq)) {
printk(KERN_ERR PREFIX "SCI (IRQ%d) allocation failed\n", irq);
acpi_irq_handler = NULL;
return AE_NOT_ACQUIRED;
}
return AE_OK;
}
acpi_status acpi_os_remove_interrupt_handler(u32 irq, acpi_osd_handler handler)
{
if (irq != acpi_gbl_FADT.sci_interrupt)
return AE_BAD_PARAMETER;
free_irq(irq, acpi_irq);
acpi_irq_handler = NULL;
return AE_OK;
}
void acpi_os_sleep(u64 ms)
{
schedule_timeout_interruptible(msecs_to_jiffies(ms));
}
void acpi_os_stall(u32 us)
{
while (us) {
u32 delay = 1000;
if (delay > us)
delay = us;
udelay(delay);
touch_nmi_watchdog();
us -= delay;
}
}
u64 acpi_os_get_timer(void)
{
static u64 t;
#ifdef CONFIG_HPET
#endif
#ifdef CONFIG_X86_PM_TIMER
#endif
if (!t)
printk(KERN_ERR PREFIX "acpi_os_get_timer() TBD\n");
return ++t;
}
acpi_status acpi_os_read_port(acpi_io_address port, u32 * value, u32 width)
{
u32 dummy;
if (!value)
value = &dummy;
*value = 0;
if (width <= 8) {
*(u8 *) value = inb(port);
} else if (width <= 16) {
*(u16 *) value = inw(port);
} else if (width <= 32) {
*(u32 *) value = inl(port);
} else {
BUG();
}
return AE_OK;
}
acpi_status acpi_os_write_port(acpi_io_address port, u32 value, u32 width)
{
if (width <= 8) {
outb(value, port);
} else if (width <= 16) {
outw(value, port);
} else if (width <= 32) {
outl(value, port);
} else {
BUG();
}
return AE_OK;
}
acpi_status
acpi_os_read_memory(acpi_physical_address phys_addr, u32 * value, u32 width)
{
void __iomem *virt_addr;
unsigned int size = width / 8;
bool unmap = false;
u32 dummy;
rcu_read_lock();
virt_addr = acpi_map_vaddr_lookup(phys_addr, size);
if (!virt_addr) {
rcu_read_unlock();
virt_addr = acpi_os_ioremap(phys_addr, size);
if (!virt_addr)
return AE_BAD_ADDRESS;
unmap = true;
}
if (!value)
value = &dummy;
switch (width) {
case 8:
*(u8 *) value = readb(virt_addr);
break;
case 16:
*(u16 *) value = readw(virt_addr);
break;
case 32:
*(u32 *) value = readl(virt_addr);
break;
default:
BUG();
}
if (unmap)
iounmap(virt_addr);
else
rcu_read_unlock();
return AE_OK;
}
acpi_status
acpi_os_write_memory(acpi_physical_address phys_addr, u32 value, u32 width)
{
void __iomem *virt_addr;
unsigned int size = width / 8;
bool unmap = false;
rcu_read_lock();
virt_addr = acpi_map_vaddr_lookup(phys_addr, size);
if (!virt_addr) {
rcu_read_unlock();
virt_addr = acpi_os_ioremap(phys_addr, size);
if (!virt_addr)
return AE_BAD_ADDRESS;
unmap = true;
}
switch (width) {
case 8:
writeb(value, virt_addr);
break;
case 16:
writew(value, virt_addr);
break;
case 32:
writel(value, virt_addr);
break;
default:
BUG();
}
if (unmap)
iounmap(virt_addr);
else
rcu_read_unlock();
return AE_OK;
}
acpi_status
acpi_os_read_pci_configuration(struct acpi_pci_id * pci_id, u32 reg,
u64 *value, u32 width)
{
int result, size;
u32 value32;
if (!value)
return AE_BAD_PARAMETER;
switch (width) {
case 8:
size = 1;
break;
case 16:
size = 2;
break;
case 32:
size = 4;
break;
default:
return AE_ERROR;
}
result = raw_pci_read(pci_id->segment, pci_id->bus,
PCI_DEVFN(pci_id->device, pci_id->function),
reg, size, &value32);
*value = value32;
return (result ? AE_ERROR : AE_OK);
}
acpi_status
acpi_os_write_pci_configuration(struct acpi_pci_id * pci_id, u32 reg,
u64 value, u32 width)
{
int result, size;
switch (width) {
case 8:
size = 1;
break;
case 16:
size = 2;
break;
case 32:
size = 4;
break;
default:
return AE_ERROR;
}
result = raw_pci_write(pci_id->segment, pci_id->bus,
PCI_DEVFN(pci_id->device, pci_id->function),
reg, size, value);
return (result ? AE_ERROR : AE_OK);
}
static void acpi_os_execute_deferred(struct work_struct *work)
{
struct acpi_os_dpc *dpc = container_of(work, struct acpi_os_dpc, work);
if (dpc->wait)
acpi_os_wait_events_complete(NULL);
dpc->function(dpc->context);
kfree(dpc);
}
static acpi_status __acpi_os_execute(acpi_execute_type type,
acpi_osd_exec_callback function, void *context, int hp)
{
acpi_status status = AE_OK;
struct acpi_os_dpc *dpc;
struct workqueue_struct *queue;
int ret;
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"Scheduling function [%p(%p)] for deferred execution.\n",
function, context));
dpc = kmalloc(sizeof(struct acpi_os_dpc), GFP_ATOMIC);
if (!dpc)
return AE_NO_MEMORY;
dpc->function = function;
dpc->context = context;
queue = hp ? kacpi_hotplug_wq :
(type == OSL_NOTIFY_HANDLER ? kacpi_notify_wq : kacpid_wq);
dpc->wait = hp ? 1 : 0;
if (queue == kacpi_hotplug_wq)
INIT_WORK(&dpc->work, acpi_os_execute_deferred);
else if (queue == kacpi_notify_wq)
INIT_WORK(&dpc->work, acpi_os_execute_deferred);
else
INIT_WORK(&dpc->work, acpi_os_execute_deferred);
ret = queue_work_on(0, queue, &dpc->work);
if (!ret) {
printk(KERN_ERR PREFIX
"Call to queue_work() failed.\n");
status = AE_ERROR;
kfree(dpc);
}
return status;
}
acpi_status acpi_os_execute(acpi_execute_type type,
acpi_osd_exec_callback function, void *context)
{
return __acpi_os_execute(type, function, context, 0);
}
acpi_status acpi_os_hotplug_execute(acpi_osd_exec_callback function,
void *context)
{
return __acpi_os_execute(0, function, context, 1);
}
void acpi_os_wait_events_complete(void *context)
{
flush_workqueue(kacpid_wq);
flush_workqueue(kacpi_notify_wq);
}
acpi_status
acpi_os_create_semaphore(u32 max_units, u32 initial_units, acpi_handle * handle)
{
struct semaphore *sem = NULL;
sem = acpi_os_allocate(sizeof(struct semaphore));
if (!sem)
return AE_NO_MEMORY;
memset(sem, 0, sizeof(struct semaphore));
sema_init(sem, initial_units);
*handle = (acpi_handle *) sem;
ACPI_DEBUG_PRINT((ACPI_DB_MUTEX, "Creating semaphore[%p|%d].\n",
*handle, initial_units));
return AE_OK;
}
acpi_status acpi_os_delete_semaphore(acpi_handle handle)
{
struct semaphore *sem = (struct semaphore *)handle;
if (!sem)
return AE_BAD_PARAMETER;
ACPI_DEBUG_PRINT((ACPI_DB_MUTEX, "Deleting semaphore[%p].\n", handle));
BUG_ON(!list_empty(&sem->wait_list));
kfree(sem);
sem = NULL;
return AE_OK;
}
acpi_status acpi_os_wait_semaphore(acpi_handle handle, u32 units, u16 timeout)
{
acpi_status status = AE_OK;
struct semaphore *sem = (struct semaphore *)handle;
long jiffies;
int ret = 0;
if (!sem || (units < 1))
return AE_BAD_PARAMETER;
if (units > 1)
return AE_SUPPORT;
ACPI_DEBUG_PRINT((ACPI_DB_MUTEX, "Waiting for semaphore[%p|%d|%d]\n",
handle, units, timeout));
if (timeout == ACPI_WAIT_FOREVER)
jiffies = MAX_SCHEDULE_TIMEOUT;
else
jiffies = msecs_to_jiffies(timeout);
ret = down_timeout(sem, jiffies);
if (ret)
status = AE_TIME;
if (ACPI_FAILURE(status)) {
ACPI_DEBUG_PRINT((ACPI_DB_MUTEX,
"Failed to acquire semaphore[%p|%d|%d], %s",
handle, units, timeout,
acpi_format_exception(status)));
} else {
ACPI_DEBUG_PRINT((ACPI_DB_MUTEX,
"Acquired semaphore[%p|%d|%d]", handle,
units, timeout));
}
return status;
}
acpi_status acpi_os_signal_semaphore(acpi_handle handle, u32 units)
{
struct semaphore *sem = (struct semaphore *)handle;
if (!sem || (units < 1))
return AE_BAD_PARAMETER;
if (units > 1)
return AE_SUPPORT;
ACPI_DEBUG_PRINT((ACPI_DB_MUTEX, "Signaling semaphore[%p|%d]\n", handle,
units));
up(sem);
return AE_OK;
}
u32 acpi_os_get_line(char *buffer)
{
#ifdef ENABLE_DEBUGGER
if (acpi_in_debugger) {
u32 chars;
kdb_read(buffer, sizeof(line_buf));
chars = strlen(buffer) - 1;
buffer[chars] = '\0';
}
#endif
return 0;
}
acpi_status acpi_os_signal(u32 function, void *info)
{
switch (function) {
case ACPI_SIGNAL_FATAL:
printk(KERN_ERR PREFIX "Fatal opcode executed\n");
break;
case ACPI_SIGNAL_BREAKPOINT:
break;
default:
break;
}
return AE_OK;
}
static int __init acpi_os_name_setup(char *str)
{
char *p = acpi_os_name;
int count = ACPI_MAX_OVERRIDE_LEN - 1;
if (!str || !*str)
return 0;
for (; count-- && str && *str; str++) {
if (isalnum(*str) || *str == ' ' || *str == ':')
*p++ = *str;
else if (*str == '\'' || *str == '"')
continue;
else
break;
}
*p = 0;
return 1;
}
void __init acpi_osi_setup(char *str)
{
struct osi_setup_entry *osi;
bool enable = true;
int i;
if (!acpi_gbl_create_osi_method)
return;
if (str == NULL || *str == '\0') {
printk(KERN_INFO PREFIX "_OSI method disabled\n");
acpi_gbl_create_osi_method = FALSE;
return;
}
if (*str == '!') {
str++;
enable = false;
}
for (i = 0; i < OSI_STRING_ENTRIES_MAX; i++) {
osi = &osi_setup_entries[i];
if (!strcmp(osi->string, str)) {
osi->enable = enable;
break;
} else if (osi->string[0] == '\0') {
osi->enable = enable;
strncpy(osi->string, str, OSI_STRING_LENGTH_MAX);
break;
}
}
}
static void __init set_osi_linux(unsigned int enable)
{
if (osi_linux.enable != enable)
osi_linux.enable = enable;
if (osi_linux.enable)
acpi_osi_setup("Linux");
else
acpi_osi_setup("!Linux");
return;
}
static void __init acpi_cmdline_osi_linux(unsigned int enable)
{
osi_linux.cmdline = 1;
osi_linux.dmi = 0;
set_osi_linux(enable);
return;
}
void __init acpi_dmi_osi_linux(int enable, const struct dmi_system_id *d)
{
printk(KERN_NOTICE PREFIX "DMI detected: %s\n", d->ident);
if (enable == -1)
return;
osi_linux.dmi = 1;
set_osi_linux(enable);
return;
}
static void __init acpi_osi_setup_late(void)
{
struct osi_setup_entry *osi;
char *str;
int i;
acpi_status status;
for (i = 0; i < OSI_STRING_ENTRIES_MAX; i++) {
osi = &osi_setup_entries[i];
str = osi->string;
if (*str == '\0')
break;
if (osi->enable) {
status = acpi_install_interface(str);
if (ACPI_SUCCESS(status))
printk(KERN_INFO PREFIX "Added _OSI(%s)\n", str);
} else {
status = acpi_remove_interface(str);
if (ACPI_SUCCESS(status))
printk(KERN_INFO PREFIX "Deleted _OSI(%s)\n", str);
}
}
}
static int __init osi_setup(char *str)
{
if (str && !strcmp("Linux", str))
acpi_cmdline_osi_linux(1);
else if (str && !strcmp("!Linux", str))
acpi_cmdline_osi_linux(0);
else
acpi_osi_setup(str);
return 1;
}
static int __init acpi_serialize_setup(char *str)
{
printk(KERN_INFO PREFIX "serialize enabled\n");
acpi_gbl_all_methods_serialized = TRUE;
return 1;
}
static int __init acpi_enforce_resources_setup(char *str)
{
if (str == NULL || *str == '\0')
return 0;
if (!strcmp("strict", str))
acpi_enforce_resources = ENFORCE_RESOURCES_STRICT;
else if (!strcmp("lax", str))
acpi_enforce_resources = ENFORCE_RESOURCES_LAX;
else if (!strcmp("no", str))
acpi_enforce_resources = ENFORCE_RESOURCES_NO;
return 1;
}
int acpi_check_resource_conflict(const struct resource *res)
{
struct acpi_res_list *res_list_elem;
int ioport = 0, clash = 0;
if (acpi_enforce_resources == ENFORCE_RESOURCES_NO)
return 0;
if (!(res->flags & IORESOURCE_IO) && !(res->flags & IORESOURCE_MEM))
return 0;
ioport = res->flags & IORESOURCE_IO;
spin_lock(&acpi_res_lock);
list_for_each_entry(res_list_elem, &resource_list_head,
resource_list) {
if (ioport && (res_list_elem->resource_type
!= ACPI_ADR_SPACE_SYSTEM_IO))
continue;
if (!ioport && (res_list_elem->resource_type
!= ACPI_ADR_SPACE_SYSTEM_MEMORY))
continue;
if (res->end < res_list_elem->start
|| res_list_elem->end < res->start)
continue;
clash = 1;
break;
}
spin_unlock(&acpi_res_lock);
if (clash) {
if (acpi_enforce_resources != ENFORCE_RESOURCES_NO) {
printk(KERN_WARNING "ACPI: resource %s %pR"
" conflicts with ACPI region %s "
"[%s 0x%zx-0x%zx]\n",
res->name, res, res_list_elem->name,
(res_list_elem->resource_type ==
ACPI_ADR_SPACE_SYSTEM_IO) ? "io" : "mem",
(size_t) res_list_elem->start,
(size_t) res_list_elem->end);
if (acpi_enforce_resources == ENFORCE_RESOURCES_LAX)
printk(KERN_NOTICE "ACPI: This conflict may"
" cause random problems and system"
" instability\n");
printk(KERN_INFO "ACPI: If an ACPI driver is available"
" for this device, you should use it instead of"
" the native driver\n");
}
if (acpi_enforce_resources == ENFORCE_RESOURCES_STRICT)
return -EBUSY;
}
return 0;
}
int acpi_check_region(resource_size_t start, resource_size_t n,
const char *name)
{
struct resource res = {
.start = start,
.end = start + n - 1,
.name = name,
.flags = IORESOURCE_IO,
};
return acpi_check_resource_conflict(&res);
}
int acpi_resources_are_enforced(void)
{
return acpi_enforce_resources == ENFORCE_RESOURCES_STRICT;
}
void acpi_os_delete_lock(acpi_spinlock handle)
{
ACPI_FREE(handle);
}
acpi_cpu_flags acpi_os_acquire_lock(acpi_spinlock lockp)
{
acpi_cpu_flags flags;
spin_lock_irqsave(lockp, flags);
return flags;
}
void acpi_os_release_lock(acpi_spinlock lockp, acpi_cpu_flags flags)
{
spin_unlock_irqrestore(lockp, flags);
}
acpi_status
acpi_os_create_cache(char *name, u16 size, u16 depth, acpi_cache_t ** cache)
{
*cache = kmem_cache_create(name, size, 0, 0, NULL);
if (*cache == NULL)
return AE_ERROR;
else
return AE_OK;
}
acpi_status acpi_os_purge_cache(acpi_cache_t * cache)
{
kmem_cache_shrink(cache);
return (AE_OK);
}
acpi_status acpi_os_delete_cache(acpi_cache_t * cache)
{
kmem_cache_destroy(cache);
return (AE_OK);
}
acpi_status acpi_os_release_object(acpi_cache_t * cache, void *object)
{
kmem_cache_free(cache, object);
return (AE_OK);
}
static inline int acpi_res_list_add(struct acpi_res_list *res)
{
struct acpi_res_list *res_list_elem;
list_for_each_entry(res_list_elem, &resource_list_head,
resource_list) {
if (res->resource_type == res_list_elem->resource_type &&
res->start == res_list_elem->start &&
res->end == res_list_elem->end) {
res_list_elem->count++;
return 0;
}
}
res->count = 1;
list_add(&res->resource_list, &resource_list_head);
return 1;
}
static inline void acpi_res_list_del(struct acpi_res_list *res)
{
struct acpi_res_list *res_list_elem;
list_for_each_entry(res_list_elem, &resource_list_head,
resource_list) {
if (res->resource_type == res_list_elem->resource_type &&
res->start == res_list_elem->start &&
res->end == res_list_elem->end) {
if (--res_list_elem->count == 0) {
list_del(&res_list_elem->resource_list);
kfree(res_list_elem);
}
return;
}
}
}
acpi_status
acpi_os_invalidate_address(
u8 space_id,
acpi_physical_address address,
acpi_size length)
{
struct acpi_res_list res;
switch (space_id) {
case ACPI_ADR_SPACE_SYSTEM_IO:
case ACPI_ADR_SPACE_SYSTEM_MEMORY:
res.start = address;
res.end = address + length - 1;
res.resource_type = space_id;
spin_lock(&acpi_res_lock);
acpi_res_list_del(&res);
spin_unlock(&acpi_res_lock);
break;
case ACPI_ADR_SPACE_PCI_CONFIG:
case ACPI_ADR_SPACE_EC:
case ACPI_ADR_SPACE_SMBUS:
case ACPI_ADR_SPACE_CMOS:
case ACPI_ADR_SPACE_PCI_BAR_TARGET:
case ACPI_ADR_SPACE_DATA_TABLE:
case ACPI_ADR_SPACE_FIXED_HARDWARE:
break;
}
return AE_OK;
}
acpi_status
acpi_os_validate_address (
u8 space_id,
acpi_physical_address address,
acpi_size length,
char *name)
{
struct acpi_res_list *res;
int added;
if (acpi_enforce_resources == ENFORCE_RESOURCES_NO)
return AE_OK;
switch (space_id) {
case ACPI_ADR_SPACE_SYSTEM_IO:
case ACPI_ADR_SPACE_SYSTEM_MEMORY:
res = kzalloc(sizeof(struct acpi_res_list), GFP_KERNEL);
if (!res)
return AE_OK;
strlcpy(res->name, name, 5);
res->start = address;
res->end = address + length - 1;
res->resource_type = space_id;
spin_lock(&acpi_res_lock);
added = acpi_res_list_add(res);
spin_unlock(&acpi_res_lock);
pr_debug("%s %s resource: start: 0x%llx, end: 0x%llx, "
"name: %s\n", added ? "Added" : "Already exist",
(space_id == ACPI_ADR_SPACE_SYSTEM_IO)
? "SystemIO" : "System Memory",
(unsigned long long)res->start,
(unsigned long long)res->end,
res->name);
if (!added)
kfree(res);
break;
case ACPI_ADR_SPACE_PCI_CONFIG:
case ACPI_ADR_SPACE_EC:
case ACPI_ADR_SPACE_SMBUS:
case ACPI_ADR_SPACE_CMOS:
case ACPI_ADR_SPACE_PCI_BAR_TARGET:
case ACPI_ADR_SPACE_DATA_TABLE:
case ACPI_ADR_SPACE_FIXED_HARDWARE:
break;
}
return AE_OK;
}
acpi_status __init acpi_os_initialize(void)
{
acpi_os_map_generic_address(&acpi_gbl_FADT.xpm1a_event_block);
acpi_os_map_generic_address(&acpi_gbl_FADT.xpm1b_event_block);
acpi_os_map_generic_address(&acpi_gbl_FADT.xgpe0_block);
acpi_os_map_generic_address(&acpi_gbl_FADT.xgpe1_block);
return AE_OK;
}
acpi_status __init acpi_os_initialize1(void)
{
kacpid_wq = alloc_workqueue("kacpid", 0, 1);
kacpi_notify_wq = alloc_workqueue("kacpi_notify", 0, 1);
kacpi_hotplug_wq = alloc_workqueue("kacpi_hotplug", 0, 1);
BUG_ON(!kacpid_wq);
BUG_ON(!kacpi_notify_wq);
BUG_ON(!kacpi_hotplug_wq);
acpi_install_interface_handler(acpi_osi_handler);
acpi_osi_setup_late();
return AE_OK;
}
acpi_status acpi_os_terminate(void)
{
if (acpi_irq_handler) {
acpi_os_remove_interrupt_handler(acpi_gbl_FADT.sci_interrupt,
acpi_irq_handler);
}
acpi_os_unmap_generic_address(&acpi_gbl_FADT.xgpe1_block);
acpi_os_unmap_generic_address(&acpi_gbl_FADT.xgpe0_block);
acpi_os_unmap_generic_address(&acpi_gbl_FADT.xpm1b_event_block);
acpi_os_unmap_generic_address(&acpi_gbl_FADT.xpm1a_event_block);
destroy_workqueue(kacpid_wq);
destroy_workqueue(kacpi_notify_wq);
destroy_workqueue(kacpi_hotplug_wq);
return AE_OK;
}
