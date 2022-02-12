static ssize_t iscsi_boot_show_attribute(struct kobject *kobj,
struct attribute *attr, char *buf)
{
struct iscsi_boot_kobj *boot_kobj =
container_of(kobj, struct iscsi_boot_kobj, kobj);
struct iscsi_boot_attr *boot_attr =
container_of(attr, struct iscsi_boot_attr, attr);
ssize_t ret = -EIO;
char *str = buf;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
if (boot_kobj->show)
ret = boot_kobj->show(boot_kobj->data, boot_attr->type, str);
return ret;
}
static void iscsi_boot_kobj_release(struct kobject *kobj)
{
struct iscsi_boot_kobj *boot_kobj =
container_of(kobj, struct iscsi_boot_kobj, kobj);
if (boot_kobj->release)
boot_kobj->release(boot_kobj->data);
kfree(boot_kobj);
}
static umode_t iscsi_boot_tgt_attr_is_visible(struct kobject *kobj,
struct attribute *attr, int i)
{
struct iscsi_boot_kobj *boot_kobj =
container_of(kobj, struct iscsi_boot_kobj, kobj);
if (attr == &iscsi_boot_attr_tgt_index.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_TGT_INDEX);
else if (attr == &iscsi_boot_attr_tgt_flags.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_TGT_FLAGS);
else if (attr == &iscsi_boot_attr_tgt_ip.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_TGT_IP_ADDR);
else if (attr == &iscsi_boot_attr_tgt_port.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_TGT_PORT);
else if (attr == &iscsi_boot_attr_tgt_lun.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_TGT_LUN);
else if (attr == &iscsi_boot_attr_tgt_chap.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_TGT_CHAP_TYPE);
else if (attr == &iscsi_boot_attr_tgt_nic.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_TGT_NIC_ASSOC);
else if (attr == &iscsi_boot_attr_tgt_name.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_TGT_NAME);
else if (attr == &iscsi_boot_attr_tgt_chap_name.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_TGT_CHAP_NAME);
else if (attr == &iscsi_boot_attr_tgt_chap_secret.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_TGT_CHAP_SECRET);
else if (attr == &iscsi_boot_attr_tgt_chap_rev_name.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_TGT_REV_CHAP_NAME);
else if (attr == &iscsi_boot_attr_tgt_chap_rev_secret.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_TGT_REV_CHAP_SECRET);
return 0;
}
static umode_t iscsi_boot_eth_attr_is_visible(struct kobject *kobj,
struct attribute *attr, int i)
{
struct iscsi_boot_kobj *boot_kobj =
container_of(kobj, struct iscsi_boot_kobj, kobj);
if (attr == &iscsi_boot_attr_eth_index.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_ETH_INDEX);
else if (attr == &iscsi_boot_attr_eth_flags.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_ETH_FLAGS);
else if (attr == &iscsi_boot_attr_eth_ip.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_ETH_IP_ADDR);
else if (attr == &iscsi_boot_attr_eth_prefix.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_ETH_PREFIX_LEN);
else if (attr == &iscsi_boot_attr_eth_subnet.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_ETH_SUBNET_MASK);
else if (attr == &iscsi_boot_attr_eth_origin.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_ETH_ORIGIN);
else if (attr == &iscsi_boot_attr_eth_gateway.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_ETH_GATEWAY);
else if (attr == &iscsi_boot_attr_eth_primary_dns.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_ETH_PRIMARY_DNS);
else if (attr == &iscsi_boot_attr_eth_secondary_dns.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_ETH_SECONDARY_DNS);
else if (attr == &iscsi_boot_attr_eth_dhcp.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_ETH_DHCP);
else if (attr == &iscsi_boot_attr_eth_vlan.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_ETH_VLAN);
else if (attr == &iscsi_boot_attr_eth_mac.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_ETH_MAC);
else if (attr == &iscsi_boot_attr_eth_hostname.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_ETH_HOSTNAME);
return 0;
}
static umode_t iscsi_boot_ini_attr_is_visible(struct kobject *kobj,
struct attribute *attr, int i)
{
struct iscsi_boot_kobj *boot_kobj =
container_of(kobj, struct iscsi_boot_kobj, kobj);
if (attr == &iscsi_boot_attr_ini_index.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_INI_INDEX);
if (attr == &iscsi_boot_attr_ini_flags.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_INI_FLAGS);
if (attr == &iscsi_boot_attr_ini_isns.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_INI_ISNS_SERVER);
if (attr == &iscsi_boot_attr_ini_slp.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_INI_SLP_SERVER);
if (attr == &iscsi_boot_attr_ini_primary_radius.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_INI_PRI_RADIUS_SERVER);
if (attr == &iscsi_boot_attr_ini_secondary_radius.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_INI_SEC_RADIUS_SERVER);
if (attr == &iscsi_boot_attr_ini_name.attr)
return boot_kobj->is_visible(boot_kobj->data,
ISCSI_BOOT_INI_INITIATOR_NAME);
return 0;
}
static struct iscsi_boot_kobj *
iscsi_boot_create_kobj(struct iscsi_boot_kset *boot_kset,
struct attribute_group *attr_group,
const char *name, int index, void *data,
ssize_t (*show) (void *data, int type, char *buf),
umode_t (*is_visible) (void *data, int type),
void (*release) (void *data))
{
struct iscsi_boot_kobj *boot_kobj;
boot_kobj = kzalloc(sizeof(*boot_kobj), GFP_KERNEL);
if (!boot_kobj)
return NULL;
INIT_LIST_HEAD(&boot_kobj->list);
boot_kobj->kobj.kset = boot_kset->kset;
if (kobject_init_and_add(&boot_kobj->kobj, &iscsi_boot_ktype,
NULL, name, index)) {
kfree(boot_kobj);
return NULL;
}
boot_kobj->data = data;
boot_kobj->show = show;
boot_kobj->is_visible = is_visible;
boot_kobj->release = release;
if (sysfs_create_group(&boot_kobj->kobj, attr_group)) {
boot_kobj->release = NULL;
kobject_put(&boot_kobj->kobj);
return NULL;
}
boot_kobj->attr_group = attr_group;
kobject_uevent(&boot_kobj->kobj, KOBJ_ADD);
list_add_tail(&boot_kobj->list, &boot_kset->kobj_list);
return boot_kobj;
}
static void iscsi_boot_remove_kobj(struct iscsi_boot_kobj *boot_kobj)
{
list_del(&boot_kobj->list);
sysfs_remove_group(&boot_kobj->kobj, boot_kobj->attr_group);
kobject_put(&boot_kobj->kobj);
}
struct iscsi_boot_kobj *
iscsi_boot_create_target(struct iscsi_boot_kset *boot_kset, int index,
void *data,
ssize_t (*show) (void *data, int type, char *buf),
umode_t (*is_visible) (void *data, int type),
void (*release) (void *data))
{
return iscsi_boot_create_kobj(boot_kset, &iscsi_boot_target_attr_group,
"target%d", index, data, show, is_visible,
release);
}
struct iscsi_boot_kobj *
iscsi_boot_create_initiator(struct iscsi_boot_kset *boot_kset, int index,
void *data,
ssize_t (*show) (void *data, int type, char *buf),
umode_t (*is_visible) (void *data, int type),
void (*release) (void *data))
{
return iscsi_boot_create_kobj(boot_kset,
&iscsi_boot_initiator_attr_group,
"initiator", index, data, show,
is_visible, release);
}
struct iscsi_boot_kobj *
iscsi_boot_create_ethernet(struct iscsi_boot_kset *boot_kset, int index,
void *data,
ssize_t (*show) (void *data, int type, char *buf),
umode_t (*is_visible) (void *data, int type),
void (*release) (void *data))
{
return iscsi_boot_create_kobj(boot_kset,
&iscsi_boot_ethernet_attr_group,
"ethernet%d", index, data, show,
is_visible, release);
}
struct iscsi_boot_kset *iscsi_boot_create_kset(const char *set_name)
{
struct iscsi_boot_kset *boot_kset;
boot_kset = kzalloc(sizeof(*boot_kset), GFP_KERNEL);
if (!boot_kset)
return NULL;
boot_kset->kset = kset_create_and_add(set_name, NULL, firmware_kobj);
if (!boot_kset->kset) {
kfree(boot_kset);
return NULL;
}
INIT_LIST_HEAD(&boot_kset->kobj_list);
return boot_kset;
}
struct iscsi_boot_kset *iscsi_boot_create_host_kset(unsigned int hostno)
{
struct iscsi_boot_kset *boot_kset;
char *set_name;
set_name = kasprintf(GFP_KERNEL, "iscsi_boot%u", hostno);
if (!set_name)
return NULL;
boot_kset = iscsi_boot_create_kset(set_name);
kfree(set_name);
return boot_kset;
}
void iscsi_boot_destroy_kset(struct iscsi_boot_kset *boot_kset)
{
struct iscsi_boot_kobj *boot_kobj, *tmp_kobj;
if (!boot_kset)
return;
list_for_each_entry_safe(boot_kobj, tmp_kobj,
&boot_kset->kobj_list, list)
iscsi_boot_remove_kobj(boot_kobj);
kset_unregister(boot_kset->kset);
kfree(boot_kset);
}
