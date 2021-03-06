static struct device_node *find_vio_slot_node(char *drc_name)
{
struct device_node *parent = of_find_node_by_name(NULL, "vdevice");
struct device_node *dn = NULL;
char *name;
int rc;
if (!parent)
return NULL;
while ((dn = of_get_next_child(parent, dn))) {
rc = rpaphp_get_drc_props(dn, NULL, &name, NULL, NULL);
if ((rc == 0) && (!strcmp(drc_name, name)))
break;
}
return dn;
}
static struct device_node *find_php_slot_pci_node(char *drc_name,
char *drc_type)
{
struct device_node *np = NULL;
char *name;
char *type;
int rc;
while ((np = of_find_node_by_name(np, "pci"))) {
rc = rpaphp_get_drc_props(np, NULL, &name, &type, NULL);
if (rc == 0)
if (!strcmp(drc_name, name) && !strcmp(drc_type, type))
break;
}
return np;
}
static struct device_node *find_dlpar_node(char *drc_name, int *node_type)
{
struct device_node *dn;
dn = find_php_slot_pci_node(drc_name, "SLOT");
if (dn) {
*node_type = NODE_TYPE_SLOT;
return dn;
}
dn = find_php_slot_pci_node(drc_name, "PHB");
if (dn) {
*node_type = NODE_TYPE_PHB;
return dn;
}
dn = find_vio_slot_node(drc_name);
if (dn) {
*node_type = NODE_TYPE_VIO;
return dn;
}
return NULL;
}
static struct slot *find_php_slot(struct device_node *dn)
{
struct list_head *tmp, *n;
struct slot *slot;
list_for_each_safe(tmp, n, &rpaphp_slot_head) {
slot = list_entry(tmp, struct slot, rpaphp_slot_list);
if (slot->dn == dn)
return slot;
}
return NULL;
}
static struct pci_dev *dlpar_find_new_dev(struct pci_bus *parent,
struct device_node *dev_dn)
{
struct pci_dev *tmp = NULL;
struct device_node *child_dn;
list_for_each_entry(tmp, &parent->devices, bus_list) {
child_dn = pci_device_to_OF_node(tmp);
if (child_dn == dev_dn)
return tmp;
}
return NULL;
}
static void dlpar_pci_add_bus(struct device_node *dn)
{
struct pci_dn *pdn = PCI_DN(dn);
struct pci_controller *phb = pdn->phb;
struct pci_dev *dev = NULL;
eeh_add_device_tree_early(pdn);
dev = of_create_pci_dev(dn, phb->bus, pdn->devfn);
if (!dev) {
printk(KERN_ERR "%s: failed to create pci dev for %s\n",
__func__, dn->full_name);
return;
}
if (pci_is_bridge(dev))
of_scan_pci_bridge(dev);
pcibios_map_io_space(dev->subordinate);
pcibios_finish_adding_to_bus(phb->bus);
}
static int dlpar_add_pci_slot(char *drc_name, struct device_node *dn)
{
struct pci_dev *dev;
struct pci_controller *phb;
if (pcibios_find_pci_bus(dn))
return -EINVAL;
dlpar_pci_add_bus(dn);
phb = PCI_DN(dn)->phb;
dev = dlpar_find_new_dev(phb->bus, dn);
if (!dev) {
printk(KERN_ERR "%s: unable to add bus %s\n", __func__,
drc_name);
return -EIO;
}
if (dev->hdr_type != PCI_HEADER_TYPE_BRIDGE) {
printk(KERN_ERR "%s: unexpected header type %d, unable to add bus %s\n",
__func__, dev->hdr_type, drc_name);
return -EIO;
}
if (rpaphp_add_slot(dn)) {
printk(KERN_ERR "%s: unable to add hotplug slot %s\n",
__func__, drc_name);
return -EIO;
}
return 0;
}
static int dlpar_remove_phb(char *drc_name, struct device_node *dn)
{
struct slot *slot;
struct pci_dn *pdn;
int rc = 0;
if (!pcibios_find_pci_bus(dn))
return -EINVAL;
slot = find_php_slot(dn);
if (slot && rpaphp_deregister_slot(slot)) {
printk(KERN_ERR "%s: unable to remove hotplug slot %s\n",
__func__, drc_name);
return -EIO;
}
pdn = dn->data;
BUG_ON(!pdn || !pdn->phb);
rc = remove_phb_dynamic(pdn->phb);
if (rc < 0)
return rc;
pdn->phb = NULL;
return 0;
}
static int dlpar_add_phb(char *drc_name, struct device_node *dn)
{
struct pci_controller *phb;
if (PCI_DN(dn) && PCI_DN(dn)->phb) {
return -EINVAL;
}
phb = init_phb_dynamic(dn);
if (!phb)
return -EIO;
if (rpaphp_add_slot(dn)) {
printk(KERN_ERR "%s: unable to add hotplug slot %s\n",
__func__, drc_name);
return -EIO;
}
return 0;
}
static int dlpar_add_vio_slot(char *drc_name, struct device_node *dn)
{
if (vio_find_node(dn))
return -EINVAL;
if (!vio_register_device_node(dn)) {
printk(KERN_ERR
"%s: failed to register vio node %s\n",
__func__, drc_name);
return -EIO;
}
return 0;
}
int dlpar_add_slot(char *drc_name)
{
struct device_node *dn = NULL;
int node_type;
int rc = -EIO;
if (mutex_lock_interruptible(&rpadlpar_mutex))
return -ERESTARTSYS;
dn = find_dlpar_node(drc_name, &node_type);
if (!dn) {
rc = -ENODEV;
goto exit;
}
switch (node_type) {
case NODE_TYPE_VIO:
rc = dlpar_add_vio_slot(drc_name, dn);
break;
case NODE_TYPE_SLOT:
rc = dlpar_add_pci_slot(drc_name, dn);
break;
case NODE_TYPE_PHB:
rc = dlpar_add_phb(drc_name, dn);
break;
}
printk(KERN_INFO "%s: slot %s added\n", DLPAR_MODULE_NAME, drc_name);
exit:
mutex_unlock(&rpadlpar_mutex);
return rc;
}
static int dlpar_remove_vio_slot(char *drc_name, struct device_node *dn)
{
struct vio_dev *vio_dev;
vio_dev = vio_find_node(dn);
if (!vio_dev)
return -EINVAL;
vio_unregister_device(vio_dev);
return 0;
}
int dlpar_remove_pci_slot(char *drc_name, struct device_node *dn)
{
struct pci_bus *bus;
struct slot *slot;
int ret = 0;
pci_lock_rescan_remove();
bus = pcibios_find_pci_bus(dn);
if (!bus) {
ret = -EINVAL;
goto out;
}
pr_debug("PCI: Removing PCI slot below EADS bridge %s\n",
bus->self ? pci_name(bus->self) : "<!PHB!>");
slot = find_php_slot(dn);
if (slot) {
pr_debug("PCI: Removing hotplug slot for %04x:%02x...\n",
pci_domain_nr(bus), bus->number);
if (rpaphp_deregister_slot(slot)) {
printk(KERN_ERR
"%s: unable to remove hotplug slot %s\n",
__func__, drc_name);
ret = -EIO;
goto out;
}
}
pcibios_remove_pci_devices(bus);
if (pcibios_unmap_io_space(bus)) {
printk(KERN_ERR "%s: failed to unmap bus range\n",
__func__);
ret = -ERANGE;
goto out;
}
BUG_ON(!bus->self);
pr_debug("PCI: Now removing bridge device %s\n", pci_name(bus->self));
pci_stop_and_remove_bus_device(bus->self);
out:
pci_unlock_rescan_remove();
return ret;
}
int dlpar_remove_slot(char *drc_name)
{
struct device_node *dn;
int node_type;
int rc = 0;
if (mutex_lock_interruptible(&rpadlpar_mutex))
return -ERESTARTSYS;
dn = find_dlpar_node(drc_name, &node_type);
if (!dn) {
rc = -ENODEV;
goto exit;
}
switch (node_type) {
case NODE_TYPE_VIO:
rc = dlpar_remove_vio_slot(drc_name, dn);
break;
case NODE_TYPE_PHB:
rc = dlpar_remove_phb(drc_name, dn);
break;
case NODE_TYPE_SLOT:
rc = dlpar_remove_pci_slot(drc_name, dn);
break;
}
vm_unmap_aliases();
printk(KERN_INFO "%s: slot %s removed\n", DLPAR_MODULE_NAME, drc_name);
exit:
mutex_unlock(&rpadlpar_mutex);
return rc;
}
static inline int is_dlpar_capable(void)
{
int rc = rtas_token("ibm,configure-connector");
return (int) (rc != RTAS_UNKNOWN_SERVICE);
}
int __init rpadlpar_io_init(void)
{
int rc = 0;
if (!is_dlpar_capable()) {
printk(KERN_WARNING "%s: partition not DLPAR capable\n",
__func__);
return -EPERM;
}
rc = dlpar_sysfs_init();
return rc;
}
void rpadlpar_io_exit(void)
{
dlpar_sysfs_exit();
return;
}
