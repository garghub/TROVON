static int set_attention_status(struct hotplug_slot *hotplug_slot, u8 value)
{
int rc;
struct slot *slot = (struct slot *)hotplug_slot->private;
switch (value) {
case 0:
case 1:
case 2:
break;
default:
value = 1;
break;
}
rc = rtas_set_indicator(DR_INDICATOR, slot->index, value);
if (!rc)
hotplug_slot->info->attention_status = value;
return rc;
}
static int get_power_status(struct hotplug_slot *hotplug_slot, u8 *value)
{
int retval, level;
struct slot *slot = (struct slot *)hotplug_slot->private;
retval = rtas_get_power_level (slot->power_domain, &level);
if (!retval)
*value = level;
return retval;
}
static int get_attention_status(struct hotplug_slot *hotplug_slot, u8 *value)
{
struct slot *slot = (struct slot *)hotplug_slot->private;
*value = slot->hotplug_slot->info->attention_status;
return 0;
}
static int get_adapter_status(struct hotplug_slot *hotplug_slot, u8 *value)
{
struct slot *slot = (struct slot *)hotplug_slot->private;
int rc, state;
rc = rpaphp_get_sensor_state(slot, &state);
*value = NOT_VALID;
if (rc)
return rc;
if (state == EMPTY)
*value = EMPTY;
else if (state == PRESENT)
*value = slot->state;
return 0;
}
static enum pci_bus_speed get_max_bus_speed(struct slot *slot)
{
enum pci_bus_speed speed;
switch (slot->type) {
case 1:
case 2:
case 3:
case 4:
case 5:
case 6:
speed = PCI_SPEED_33MHz;
break;
case 7:
case 8:
speed = PCI_SPEED_66MHz;
break;
case 11:
case 14:
speed = PCI_SPEED_66MHz_PCIX;
break;
case 12:
case 15:
speed = PCI_SPEED_100MHz_PCIX;
break;
case 13:
case 16:
speed = PCI_SPEED_133MHz_PCIX;
break;
default:
speed = PCI_SPEED_UNKNOWN;
break;
}
return speed;
}
static int get_children_props(struct device_node *dn, const int **drc_indexes,
const int **drc_names, const int **drc_types,
const int **drc_power_domains)
{
const int *indexes, *names, *types, *domains;
indexes = of_get_property(dn, "ibm,drc-indexes", NULL);
names = of_get_property(dn, "ibm,drc-names", NULL);
types = of_get_property(dn, "ibm,drc-types", NULL);
domains = of_get_property(dn, "ibm,drc-power-domains", NULL);
if (!indexes || !names || !types || !domains) {
return -EINVAL;
}
if (drc_indexes)
*drc_indexes = indexes;
if (drc_names)
*drc_names = names;
if (drc_types)
*drc_types = types;
if (drc_power_domains)
*drc_power_domains = domains;
return 0;
}
int rpaphp_get_drc_props(struct device_node *dn, int *drc_index,
char **drc_name, char **drc_type, int *drc_power_domain)
{
const int *indexes, *names;
const int *types, *domains;
const unsigned int *my_index;
char *name_tmp, *type_tmp;
int i, rc;
my_index = of_get_property(dn, "ibm,my-drc-index", NULL);
if (!my_index) {
return -EINVAL;
}
rc = get_children_props(dn->parent, &indexes, &names, &types, &domains);
if (rc < 0) {
return -EINVAL;
}
name_tmp = (char *) &names[1];
type_tmp = (char *) &types[1];
for (i = 0; i < be32_to_cpu(indexes[0]); i++) {
if ((unsigned int) indexes[i + 1] == *my_index) {
if (drc_name)
*drc_name = name_tmp;
if (drc_type)
*drc_type = type_tmp;
if (drc_index)
*drc_index = be32_to_cpu(*my_index);
if (drc_power_domain)
*drc_power_domain = be32_to_cpu(domains[i+1]);
return 0;
}
name_tmp += (strlen(name_tmp) + 1);
type_tmp += (strlen(type_tmp) + 1);
}
return -EINVAL;
}
static int is_php_type(char *drc_type)
{
unsigned long value;
char *endptr;
value = simple_strtoul(drc_type, &endptr, 10);
if (endptr == drc_type)
return 0;
return 1;
}
static int is_php_dn(struct device_node *dn, const int **indexes,
const int **names, const int **types, const int **power_domains)
{
const int *drc_types;
int rc;
rc = get_children_props(dn, indexes, names, &drc_types, power_domains);
if (rc < 0)
return 0;
if (!is_php_type((char *) &drc_types[1]))
return 0;
*types = drc_types;
return 1;
}
int rpaphp_add_slot(struct device_node *dn)
{
struct slot *slot;
int retval = 0;
int i;
const int *indexes, *names, *types, *power_domains;
char *name, *type;
if (!dn->name || strcmp(dn->name, "pci"))
return 0;
if (!is_php_dn(dn, &indexes, &names, &types, &power_domains))
return 0;
dbg("Entry %s: dn->full_name=%s\n", __func__, dn->full_name);
name = (char *) &names[1];
type = (char *) &types[1];
for (i = 0; i < be32_to_cpu(indexes[0]); i++) {
int index;
index = be32_to_cpu(indexes[i + 1]);
slot = alloc_slot_struct(dn, index, name,
be32_to_cpu(power_domains[i + 1]));
if (!slot)
return -ENOMEM;
slot->type = simple_strtoul(type, NULL, 10);
dbg("Found drc-index:0x%x drc-name:%s drc-type:%s\n",
index, name, type);
retval = rpaphp_enable_slot(slot);
if (!retval)
retval = rpaphp_register_slot(slot);
if (retval)
dealloc_slot_struct(slot);
name += strlen(name) + 1;
type += strlen(type) + 1;
}
dbg("%s - Exit: rc[%d]\n", __func__, retval);
return retval;
}
static void __exit cleanup_slots(void)
{
struct list_head *tmp, *n;
struct slot *slot;
list_for_each_safe(tmp, n, &rpaphp_slot_head) {
slot = list_entry(tmp, struct slot, rpaphp_slot_list);
list_del(&slot->rpaphp_slot_list);
pci_hp_deregister(slot->hotplug_slot);
}
return;
}
static int __init rpaphp_init(void)
{
struct device_node *dn;
info(DRIVER_DESC " version: " DRIVER_VERSION "\n");
for_each_node_by_name(dn, "pci")
rpaphp_add_slot(dn);
return 0;
}
static void __exit rpaphp_exit(void)
{
cleanup_slots();
}
static int enable_slot(struct hotplug_slot *hotplug_slot)
{
struct slot *slot = (struct slot *)hotplug_slot->private;
int state;
int retval;
if (slot->state == CONFIGURED)
return 0;
retval = rpaphp_get_sensor_state(slot, &state);
if (retval)
return retval;
if (state == PRESENT) {
pci_lock_rescan_remove();
pcibios_add_pci_devices(slot->bus);
pci_unlock_rescan_remove();
slot->state = CONFIGURED;
} else if (state == EMPTY) {
slot->state = EMPTY;
} else {
err("%s: slot[%s] is in invalid state\n", __func__, slot->name);
slot->state = NOT_VALID;
return -EINVAL;
}
slot->bus->max_bus_speed = get_max_bus_speed(slot);
return 0;
}
static int disable_slot(struct hotplug_slot *hotplug_slot)
{
struct slot *slot = (struct slot *)hotplug_slot->private;
if (slot->state == NOT_CONFIGURED)
return -EINVAL;
pci_lock_rescan_remove();
pcibios_remove_pci_devices(slot->bus);
pci_unlock_rescan_remove();
vm_unmap_aliases();
slot->state = NOT_CONFIGURED;
return 0;
}
