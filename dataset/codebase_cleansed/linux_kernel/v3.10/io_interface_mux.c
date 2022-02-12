static unsigned char clear_group_from_set(const unsigned char groups, struct if_group *group)
{
return (groups & ~group->group);
}
static struct if_group *get_group(const unsigned char groups)
{
int i;
for (i = 0; i < ARRAY_SIZE(if_groups); i++) {
if (groups & if_groups[i].group) {
return &if_groups[i];
}
}
return NULL;
}
static void notify_watchers(void)
{
struct watcher *w = watchers;
DBG(printk("io_interface_mux: notifying watchers\n"));
while (NULL != w) {
w->notify((const unsigned int)gpio_in_pins,
(const unsigned int)gpio_out_pins,
(const unsigned char)gpio_pa_pins,
(const unsigned char)gpio_pb_pins);
w = w->next;
}
}
int cris_request_io_interface(enum cris_io_interface ioif, const char *device_id)
{
int set_gen_config = 0;
int set_gen_config_ii = 0;
unsigned long int gens;
unsigned long int gens_ii;
struct if_group *grp;
unsigned char group_set;
unsigned long flags;
int res = 0;
(void)cris_io_interface_init();
DBG(printk("cris_request_io_interface(%d, \"%s\")\n", ioif, device_id));
if ((ioif >= if_max_interfaces) || (ioif < 0)) {
printk(KERN_CRIT "cris_request_io_interface: Bad interface "
"%u submitted for %s\n",
ioif,
device_id);
return -EINVAL;
}
local_irq_save(flags);
if (interfaces[ioif].used) {
printk(KERN_CRIT "cris_io_interface: Cannot allocate interface "
"%s for %s, in use by %s\n",
interfaces[ioif].name,
device_id,
interfaces[ioif].owner);
res = -EBUSY;
goto exit;
}
group_set = interfaces[ioif].groups;
while (NULL != (grp = get_group(group_set))) {
unsigned int if_group_use = 0;
switch (grp->group) {
case group_a:
if_group_use = interfaces[ioif].group_a;
break;
case group_b:
if_group_use = interfaces[ioif].group_b;
break;
case group_c:
if_group_use = interfaces[ioif].group_c;
break;
case group_d:
if_group_use = interfaces[ioif].group_d;
break;
case group_e:
if_group_use = interfaces[ioif].group_e;
break;
case group_f:
if_group_use = interfaces[ioif].group_f;
break;
default:
BUG_ON(1);
}
if (if_group_use & grp->used) {
printk(KERN_INFO "cris_request_io_interface: group "
"%s needed by %s not available\n",
grp->name, interfaces[ioif].name);
res = -EBUSY;
goto exit;
}
group_set = clear_group_from_set(group_set, grp);
}
if (((interfaces[ioif].gpio_g_in & gpio_in_pins) !=
interfaces[ioif].gpio_g_in) ||
((interfaces[ioif].gpio_g_out & gpio_out_pins) !=
interfaces[ioif].gpio_g_out) ||
((interfaces[ioif].gpio_b & gpio_pb_pins) !=
interfaces[ioif].gpio_b)) {
printk(KERN_CRIT "cris_request_io_interface: Could not get "
"required pins for interface %u\n", ioif);
res = -EBUSY;
goto exit;
}
gens = genconfig_shadow;
gens_ii = gen_config_ii_shadow;
set_gen_config = 1;
switch (ioif)
{
case if_eth:
case if_serial_0:
set_gen_config = 0;
break;
case if_serial_1:
set_gen_config_ii = 1;
SETS(gens_ii, R_GEN_CONFIG_II, sermode1, async);
break;
case if_serial_2:
SETS(gens, R_GEN_CONFIG, ser2, select);
break;
case if_serial_3:
SETS(gens, R_GEN_CONFIG, ser3, select);
set_gen_config_ii = 1;
SETS(gens_ii, R_GEN_CONFIG_II, sermode3, async);
break;
case if_sync_serial_1:
set_gen_config_ii = 1;
SETS(gens_ii, R_GEN_CONFIG_II, sermode1, sync);
break;
case if_sync_serial_3:
SETS(gens, R_GEN_CONFIG, ser3, select);
set_gen_config_ii = 1;
SETS(gens_ii, R_GEN_CONFIG_II, sermode3, sync);
break;
case if_shared_ram:
SETS(gens, R_GEN_CONFIG, mio, select);
break;
case if_shared_ram_w:
SETS(gens, R_GEN_CONFIG, mio_w, select);
break;
case if_par_0:
SETS(gens, R_GEN_CONFIG, par0, select);
break;
case if_par_1:
SETS(gens, R_GEN_CONFIG, par1, select);
break;
case if_par_w:
SETS(gens, R_GEN_CONFIG, par0, select);
SETS(gens, R_GEN_CONFIG, par_w, select);
break;
case if_scsi8_0:
SETS(gens, R_GEN_CONFIG, scsi0, select);
break;
case if_scsi8_1:
SETS(gens, R_GEN_CONFIG, scsi1, select);
break;
case if_scsi_w:
SETS(gens, R_GEN_CONFIG, scsi0, select);
SETS(gens, R_GEN_CONFIG, scsi0w, select);
break;
case if_ata:
SETS(gens, R_GEN_CONFIG, ata, select);
break;
case if_csp:
case if_i2c:
set_gen_config = 0;
break;
case if_usb_1:
SETS(gens, R_GEN_CONFIG, usb1, select);
break;
case if_usb_2:
SETS(gens, R_GEN_CONFIG, usb2, select);
break;
case if_gpio_grp_a:
case if_gpio_grp_b:
case if_gpio_grp_c:
case if_gpio_grp_d:
case if_gpio_grp_e:
case if_gpio_grp_f:
set_gen_config = 0;
break;
default:
printk(KERN_INFO "cris_request_io_interface: Bad interface "
"%u submitted for %s\n",
ioif, device_id);
res = -EBUSY;
goto exit;
}
group_set = interfaces[ioif].groups;
while (NULL != (grp = get_group(group_set))) {
unsigned int if_group_use = 0;
switch (grp->group) {
case group_a:
if_group_use = interfaces[ioif].group_a;
break;
case group_b:
if_group_use = interfaces[ioif].group_b;
break;
case group_c:
if_group_use = interfaces[ioif].group_c;
break;
case group_d:
if_group_use = interfaces[ioif].group_d;
break;
case group_e:
if_group_use = interfaces[ioif].group_e;
break;
case group_f:
if_group_use = interfaces[ioif].group_f;
break;
default:
BUG_ON(1);
}
grp->used |= if_group_use;
group_set = clear_group_from_set(group_set, grp);
}
interfaces[ioif].used = 1;
interfaces[ioif].owner = (char*)device_id;
if (set_gen_config) {
volatile int i;
genconfig_shadow = gens;
*R_GEN_CONFIG = genconfig_shadow;
for(i = 6; i > 0; i--)
nop();
}
if (set_gen_config_ii) {
gen_config_ii_shadow = gens_ii;
*R_GEN_CONFIG_II = gen_config_ii_shadow;
}
DBG(printk(KERN_DEBUG "GPIO pins: available before: "
"g_in=0x%08x g_out=0x%08x pb=0x%02x\n",
gpio_in_pins, gpio_out_pins, gpio_pb_pins));
DBG(printk(KERN_DEBUG
"grabbing pins: g_in=0x%08x g_out=0x%08x pb=0x%02x\n",
interfaces[ioif].gpio_g_in,
interfaces[ioif].gpio_g_out,
interfaces[ioif].gpio_b));
gpio_in_pins &= ~interfaces[ioif].gpio_g_in;
gpio_out_pins &= ~interfaces[ioif].gpio_g_out;
gpio_pb_pins &= ~interfaces[ioif].gpio_b;
DBG(printk(KERN_DEBUG "GPIO pins: available after: "
"g_in=0x%08x g_out=0x%08x pb=0x%02x\n",
gpio_in_pins, gpio_out_pins, gpio_pb_pins));
exit:
local_irq_restore(flags);
if (res == 0)
notify_watchers();
return res;
}
void cris_free_io_interface(enum cris_io_interface ioif)
{
struct if_group *grp;
unsigned char group_set;
unsigned long flags;
(void)cris_io_interface_init();
if ((ioif >= if_max_interfaces) || (ioif < 0)) {
printk(KERN_CRIT "cris_free_io_interface: Bad interface %u\n",
ioif);
return;
}
local_irq_save(flags);
if (!interfaces[ioif].used) {
printk(KERN_CRIT "cris_free_io_interface: Freeing free interface %u\n",
ioif);
local_irq_restore(flags);
return;
}
group_set = interfaces[ioif].groups;
while (NULL != (grp = get_group(group_set))) {
unsigned int if_group_use = 0;
switch (grp->group) {
case group_a:
if_group_use = interfaces[ioif].group_a;
break;
case group_b:
if_group_use = interfaces[ioif].group_b;
break;
case group_c:
if_group_use = interfaces[ioif].group_c;
break;
case group_d:
if_group_use = interfaces[ioif].group_d;
break;
case group_e:
if_group_use = interfaces[ioif].group_e;
break;
case group_f:
if_group_use = interfaces[ioif].group_f;
break;
default:
BUG_ON(1);
}
if ((grp->used & if_group_use) != if_group_use)
BUG_ON(1);
grp->used = grp->used & ~if_group_use;
group_set = clear_group_from_set(group_set, grp);
}
interfaces[ioif].used = 0;
interfaces[ioif].owner = NULL;
DBG(printk("GPIO pins: available before: g_in=0x%08x g_out=0x%08x pb=0x%02x\n",
gpio_in_pins, gpio_out_pins, gpio_pb_pins));
DBG(printk("freeing pins: g_in=0x%08x g_out=0x%08x pb=0x%02x\n",
interfaces[ioif].gpio_g_in,
interfaces[ioif].gpio_g_out,
interfaces[ioif].gpio_b));
gpio_in_pins |= interfaces[ioif].gpio_g_in;
gpio_out_pins |= interfaces[ioif].gpio_g_out;
gpio_pb_pins |= interfaces[ioif].gpio_b;
DBG(printk("GPIO pins: available after: g_in=0x%08x g_out=0x%08x pb=0x%02x\n",
gpio_in_pins, gpio_out_pins, gpio_pb_pins));
local_irq_restore(flags);
notify_watchers();
}
static inline unsigned int create_mask(const unsigned stop_bit)
{
if (stop_bit >= 32) {
return 0xffffffff;
}
return (1<<stop_bit)-1;
}
int cris_io_interface_allocate_pins(const enum cris_io_interface ioif,
const char port,
const unsigned start_bit,
const unsigned stop_bit)
{
unsigned int i;
unsigned int mask = 0;
unsigned int tmp_mask;
unsigned long int flags;
enum cris_io_interface *owners;
(void)cris_io_interface_init();
DBG(printk("cris_io_interface_allocate_pins: if=%d port=%c start=%u stop=%u\n",
ioif, port, start_bit, stop_bit));
if (!((start_bit <= stop_bit) &&
((((port == 'a') || (port == 'b')) && (stop_bit < 8)) ||
((port == 'g') && (stop_bit < 32))))) {
return -EINVAL;
}
mask = create_mask(stop_bit + 1);
tmp_mask = create_mask(start_bit);
mask &= ~tmp_mask;
DBG(printk("cris_io_interface_allocate_pins: port=%c start=%u stop=%u mask=0x%08x\n",
port, start_bit, stop_bit, mask));
local_irq_save(flags);
switch (port) {
case 'a':
if ((gpio_pa_pins & mask) != mask) {
local_irq_restore(flags);
return -EBUSY;
}
owners = gpio_pa_owners;
gpio_pa_pins &= ~mask;
break;
case 'b':
if ((gpio_pb_pins & mask) != mask) {
local_irq_restore(flags);
return -EBUSY;
}
owners = gpio_pb_owners;
gpio_pb_pins &= ~mask;
break;
case 'g':
if (((gpio_in_pins & mask) != mask) ||
((gpio_out_pins & mask) != mask)) {
local_irq_restore(flags);
return -EBUSY;
}
owners = gpio_pg_owners;
gpio_in_pins &= ~mask;
gpio_out_pins &= ~mask;
break;
default:
local_irq_restore(flags);
return -EINVAL;
}
for (i = start_bit; i <= stop_bit; i++) {
owners[i] = ioif;
}
local_irq_restore(flags);
notify_watchers();
return 0;
}
int cris_io_interface_free_pins(const enum cris_io_interface ioif,
const char port,
const unsigned start_bit,
const unsigned stop_bit)
{
unsigned int i;
unsigned int mask = 0;
unsigned int tmp_mask;
unsigned long int flags;
enum cris_io_interface *owners;
(void)cris_io_interface_init();
if (!((start_bit <= stop_bit) &&
((((port == 'a') || (port == 'b')) && (stop_bit < 8)) ||
((port == 'g') && (stop_bit < 32))))) {
return -EINVAL;
}
mask = create_mask(stop_bit + 1);
tmp_mask = create_mask(start_bit);
mask &= ~tmp_mask;
DBG(printk("cris_io_interface_free_pins: port=%c start=%u stop=%u mask=0x%08x\n",
port, start_bit, stop_bit, mask));
local_irq_save(flags);
switch (port) {
case 'a':
if ((~gpio_pa_pins & mask) != mask) {
local_irq_restore(flags);
printk(KERN_CRIT "cris_io_interface_free_pins: Freeing free pins");
}
owners = gpio_pa_owners;
break;
case 'b':
if ((~gpio_pb_pins & mask) != mask) {
local_irq_restore(flags);
printk(KERN_CRIT "cris_io_interface_free_pins: Freeing free pins");
}
owners = gpio_pb_owners;
break;
case 'g':
if (((~gpio_in_pins & mask) != mask) ||
((~gpio_out_pins & mask) != mask)) {
local_irq_restore(flags);
printk(KERN_CRIT "cris_io_interface_free_pins: Freeing free pins");
}
owners = gpio_pg_owners;
break;
default:
owners = NULL;
}
for (i = start_bit; i <= stop_bit; i++) {
if (owners[i] != ioif) {
printk(KERN_CRIT "cris_io_interface_free_pins: Freeing unowned pins");
}
}
switch (port) {
case 'a':
gpio_pa_pins |= mask;
break;
case 'b':
gpio_pb_pins |= mask;
break;
case 'g':
gpio_in_pins |= mask;
gpio_out_pins |= mask;
break;
}
for (i = start_bit; i <= stop_bit; i++) {
owners[i] = if_unclaimed;
}
local_irq_restore(flags);
notify_watchers();
return 0;
}
int cris_io_interface_register_watcher(void (*notify)(const unsigned int gpio_in_available,
const unsigned int gpio_out_available,
const unsigned char pa_available,
const unsigned char pb_available))
{
struct watcher *w;
(void)cris_io_interface_init();
if (NULL == notify) {
return -EINVAL;
}
w = kmalloc(sizeof(*w), GFP_KERNEL);
if (!w) {
return -ENOMEM;
}
w->notify = notify;
w->next = watchers;
watchers = w;
w->notify((const unsigned int)gpio_in_pins,
(const unsigned int)gpio_out_pins,
(const unsigned char)gpio_pa_pins,
(const unsigned char)gpio_pb_pins);
return 0;
}
void cris_io_interface_delete_watcher(void (*notify)(const unsigned int gpio_in_available,
const unsigned int gpio_out_available,
const unsigned char pa_available,
const unsigned char pb_available))
{
struct watcher *w = watchers, *prev = NULL;
(void)cris_io_interface_init();
while ((NULL != w) && (w->notify != notify)){
prev = w;
w = w->next;
}
if (NULL != w) {
if (NULL != prev) {
prev->next = w->next;
} else {
watchers = w->next;
}
kfree(w);
return;
}
printk(KERN_WARNING "cris_io_interface_delete_watcher: Deleting unknown watcher 0x%p\n", notify);
}
static int cris_io_interface_init(void)
{
static int first = 1;
int i;
if (!first) {
return 0;
}
first = 0;
for (i = 0; i<8; i++) {
gpio_pa_owners[i] = if_unclaimed;
gpio_pb_owners[i] = if_unclaimed;
gpio_pg_owners[i] = if_unclaimed;
}
for (; i<32; i++) {
gpio_pg_owners[i] = if_unclaimed;
}
return 0;
}
