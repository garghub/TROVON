static ssize_t pci_slot_attr_show(struct kobject *kobj,
struct attribute *attr, char *buf)
{
struct pci_slot *slot = to_pci_slot(kobj);
struct pci_slot_attribute *attribute = to_pci_slot_attr(attr);
return attribute->show ? attribute->show(slot, buf) : -EIO;
}
static ssize_t pci_slot_attr_store(struct kobject *kobj,
struct attribute *attr, const char *buf, size_t len)
{
struct pci_slot *slot = to_pci_slot(kobj);
struct pci_slot_attribute *attribute = to_pci_slot_attr(attr);
return attribute->store ? attribute->store(slot, buf, len) : -EIO;
}
static ssize_t address_read_file(struct pci_slot *slot, char *buf)
{
if (slot->number == 0xff)
return sprintf(buf, "%04x:%02x\n",
pci_domain_nr(slot->bus),
slot->bus->number);
else
return sprintf(buf, "%04x:%02x:%02x\n",
pci_domain_nr(slot->bus),
slot->bus->number,
slot->number);
}
static ssize_t bus_speed_read(enum pci_bus_speed speed, char *buf)
{
const char *speed_string;
if (speed < ARRAY_SIZE(pci_bus_speed_strings))
speed_string = pci_bus_speed_strings[speed];
else
speed_string = "Unknown";
return sprintf(buf, "%s\n", speed_string);
}
static ssize_t max_speed_read_file(struct pci_slot *slot, char *buf)
{
return bus_speed_read(slot->bus->max_bus_speed, buf);
}
static ssize_t cur_speed_read_file(struct pci_slot *slot, char *buf)
{
return bus_speed_read(slot->bus->cur_bus_speed, buf);
}
static void pci_slot_release(struct kobject *kobj)
{
struct pci_dev *dev;
struct pci_slot *slot = to_pci_slot(kobj);
dev_dbg(&slot->bus->dev, "dev %02x, released physical slot %s\n",
slot->number, pci_slot_name(slot));
list_for_each_entry(dev, &slot->bus->devices, bus_list)
if (PCI_SLOT(dev->devfn) == slot->number)
dev->slot = NULL;
list_del(&slot->list);
kfree(slot);
}
static char *make_slot_name(const char *name)
{
char *new_name;
int len, max, dup;
new_name = kstrdup(name, GFP_KERNEL);
if (!new_name)
return NULL;
len = strlen(name) + 2;
max = 1;
dup = 1;
for (;;) {
struct kobject *dup_slot;
dup_slot = kset_find_obj(pci_slots_kset, new_name);
if (!dup_slot)
break;
kobject_put(dup_slot);
if (dup == max) {
len++;
max *= 10;
kfree(new_name);
new_name = kmalloc(len, GFP_KERNEL);
if (!new_name)
break;
}
sprintf(new_name, "%s-%d", name, dup++);
}
return new_name;
}
static int rename_slot(struct pci_slot *slot, const char *name)
{
int result = 0;
char *slot_name;
if (strcmp(pci_slot_name(slot), name) == 0)
return result;
slot_name = make_slot_name(name);
if (!slot_name)
return -ENOMEM;
result = kobject_rename(&slot->kobj, slot_name);
kfree(slot_name);
return result;
}
static struct pci_slot *get_slot(struct pci_bus *parent, int slot_nr)
{
struct pci_slot *slot;
list_for_each_entry(slot, &parent->slots, list)
if (slot->number == slot_nr) {
kobject_get(&slot->kobj);
return slot;
}
return NULL;
}
struct pci_slot *pci_create_slot(struct pci_bus *parent, int slot_nr,
const char *name,
struct hotplug_slot *hotplug)
{
struct pci_dev *dev;
struct pci_slot *slot;
int err = 0;
char *slot_name = NULL;
down_write(&pci_bus_sem);
if (slot_nr == -1)
goto placeholder;
slot = get_slot(parent, slot_nr);
if (slot) {
if (hotplug) {
if ((err = slot->hotplug ? -EBUSY : 0)
|| (err = rename_slot(slot, name))) {
kobject_put(&slot->kobj);
slot = NULL;
goto err;
}
}
goto out;
}
placeholder:
slot = kzalloc(sizeof(*slot), GFP_KERNEL);
if (!slot) {
err = -ENOMEM;
goto err;
}
slot->bus = parent;
slot->number = slot_nr;
slot->kobj.kset = pci_slots_kset;
slot_name = make_slot_name(name);
if (!slot_name) {
err = -ENOMEM;
goto err;
}
err = kobject_init_and_add(&slot->kobj, &pci_slot_ktype, NULL,
"%s", slot_name);
if (err)
goto err;
INIT_LIST_HEAD(&slot->list);
list_add(&slot->list, &parent->slots);
list_for_each_entry(dev, &parent->devices, bus_list)
if (PCI_SLOT(dev->devfn) == slot_nr)
dev->slot = slot;
dev_dbg(&parent->dev, "dev %02x, created physical slot %s\n",
slot_nr, pci_slot_name(slot));
out:
kfree(slot_name);
up_write(&pci_bus_sem);
return slot;
err:
kfree(slot);
slot = ERR_PTR(err);
goto out;
}
void pci_renumber_slot(struct pci_slot *slot, int slot_nr)
{
struct pci_slot *tmp;
down_write(&pci_bus_sem);
list_for_each_entry(tmp, &slot->bus->slots, list) {
WARN_ON(tmp->number == slot_nr);
goto out;
}
slot->number = slot_nr;
out:
up_write(&pci_bus_sem);
}
void pci_destroy_slot(struct pci_slot *slot)
{
dev_dbg(&slot->bus->dev, "dev %02x, dec refcount to %d\n",
slot->number, atomic_read(&slot->kobj.kref.refcount) - 1);
down_write(&pci_bus_sem);
kobject_put(&slot->kobj);
up_write(&pci_bus_sem);
}
void pci_hp_create_module_link(struct pci_slot *pci_slot)
{
struct hotplug_slot *slot = pci_slot->hotplug;
struct kobject *kobj = NULL;
int ret;
if (!slot || !slot->ops)
return;
kobj = kset_find_obj(module_kset, slot->ops->mod_name);
if (!kobj)
return;
ret = sysfs_create_link(&pci_slot->kobj, kobj, "module");
if (ret)
dev_err(&pci_slot->bus->dev, "Error creating sysfs link (%d)\n",
ret);
kobject_put(kobj);
}
void pci_hp_remove_module_link(struct pci_slot *pci_slot)
{
sysfs_remove_link(&pci_slot->kobj, "module");
}
static int pci_slot_init(void)
{
struct kset *pci_bus_kset;
pci_bus_kset = bus_get_kset(&pci_bus_type);
pci_slots_kset = kset_create_and_add("slots", NULL,
&pci_bus_kset->kobj);
if (!pci_slots_kset) {
printk(KERN_ERR "PCI: Slot initialization failure\n");
return -ENOMEM;
}
return 0;
}
