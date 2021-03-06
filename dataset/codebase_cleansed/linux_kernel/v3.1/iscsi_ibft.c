static ssize_t sprintf_ipaddr(char *buf, u8 *ip)
{
char *str = buf;
if (ip[0] == 0 && ip[1] == 0 && ip[2] == 0 && ip[3] == 0 &&
ip[4] == 0 && ip[5] == 0 && ip[6] == 0 && ip[7] == 0 &&
ip[8] == 0 && ip[9] == 0 && ip[10] == 0xff && ip[11] == 0xff) {
str += sprintf(buf, "%pI4", ip + 12);
} else {
str += sprintf(str, "%pI6", ip);
}
str += sprintf(str, "\n");
return str - buf;
}
static ssize_t sprintf_string(char *str, int len, char *buf)
{
return sprintf(str, "%.*s\n", len, buf);
}
static int ibft_verify_hdr(char *t, struct ibft_hdr *hdr, int id, int length)
{
if (hdr->id != id) {
printk(KERN_ERR "iBFT error: We expected the %s " \
"field header.id to have %d but " \
"found %d instead!\n", t, id, hdr->id);
return -ENODEV;
}
if (hdr->length != length) {
printk(KERN_ERR "iBFT error: We expected the %s " \
"field header.length to have %d but " \
"found %d instead!\n", t, length, hdr->length);
return -ENODEV;
}
return 0;
}
static ssize_t ibft_attr_show_initiator(void *data, int type, char *buf)
{
struct ibft_kobject *entry = data;
struct ibft_initiator *initiator = entry->initiator;
void *ibft_loc = entry->header;
char *str = buf;
if (!initiator)
return 0;
switch (type) {
case ISCSI_BOOT_INI_INDEX:
str += sprintf(str, "%d\n", initiator->hdr.index);
break;
case ISCSI_BOOT_INI_FLAGS:
str += sprintf(str, "%d\n", initiator->hdr.flags);
break;
case ISCSI_BOOT_INI_ISNS_SERVER:
str += sprintf_ipaddr(str, initiator->isns_server);
break;
case ISCSI_BOOT_INI_SLP_SERVER:
str += sprintf_ipaddr(str, initiator->slp_server);
break;
case ISCSI_BOOT_INI_PRI_RADIUS_SERVER:
str += sprintf_ipaddr(str, initiator->pri_radius_server);
break;
case ISCSI_BOOT_INI_SEC_RADIUS_SERVER:
str += sprintf_ipaddr(str, initiator->sec_radius_server);
break;
case ISCSI_BOOT_INI_INITIATOR_NAME:
str += sprintf_string(str, initiator->initiator_name_len,
(char *)ibft_loc +
initiator->initiator_name_off);
break;
default:
break;
}
return str - buf;
}
static ssize_t ibft_attr_show_nic(void *data, int type, char *buf)
{
struct ibft_kobject *entry = data;
struct ibft_nic *nic = entry->nic;
void *ibft_loc = entry->header;
char *str = buf;
__be32 val;
if (!nic)
return 0;
switch (type) {
case ISCSI_BOOT_ETH_INDEX:
str += sprintf(str, "%d\n", nic->hdr.index);
break;
case ISCSI_BOOT_ETH_FLAGS:
str += sprintf(str, "%d\n", nic->hdr.flags);
break;
case ISCSI_BOOT_ETH_IP_ADDR:
str += sprintf_ipaddr(str, nic->ip_addr);
break;
case ISCSI_BOOT_ETH_SUBNET_MASK:
val = cpu_to_be32(~((1 << (32-nic->subnet_mask_prefix))-1));
str += sprintf(str, "%pI4", &val);
break;
case ISCSI_BOOT_ETH_ORIGIN:
str += sprintf(str, "%d\n", nic->origin);
break;
case ISCSI_BOOT_ETH_GATEWAY:
str += sprintf_ipaddr(str, nic->gateway);
break;
case ISCSI_BOOT_ETH_PRIMARY_DNS:
str += sprintf_ipaddr(str, nic->primary_dns);
break;
case ISCSI_BOOT_ETH_SECONDARY_DNS:
str += sprintf_ipaddr(str, nic->secondary_dns);
break;
case ISCSI_BOOT_ETH_DHCP:
str += sprintf_ipaddr(str, nic->dhcp);
break;
case ISCSI_BOOT_ETH_VLAN:
str += sprintf(str, "%d\n", nic->vlan);
break;
case ISCSI_BOOT_ETH_MAC:
str += sprintf(str, "%pM\n", nic->mac);
break;
case ISCSI_BOOT_ETH_HOSTNAME:
str += sprintf_string(str, nic->hostname_len,
(char *)ibft_loc + nic->hostname_off);
break;
default:
break;
}
return str - buf;
}
static ssize_t ibft_attr_show_target(void *data, int type, char *buf)
{
struct ibft_kobject *entry = data;
struct ibft_tgt *tgt = entry->tgt;
void *ibft_loc = entry->header;
char *str = buf;
int i;
if (!tgt)
return 0;
switch (type) {
case ISCSI_BOOT_TGT_INDEX:
str += sprintf(str, "%d\n", tgt->hdr.index);
break;
case ISCSI_BOOT_TGT_FLAGS:
str += sprintf(str, "%d\n", tgt->hdr.flags);
break;
case ISCSI_BOOT_TGT_IP_ADDR:
str += sprintf_ipaddr(str, tgt->ip_addr);
break;
case ISCSI_BOOT_TGT_PORT:
str += sprintf(str, "%d\n", tgt->port);
break;
case ISCSI_BOOT_TGT_LUN:
for (i = 0; i < 8; i++)
str += sprintf(str, "%x", (u8)tgt->lun[i]);
str += sprintf(str, "\n");
break;
case ISCSI_BOOT_TGT_NIC_ASSOC:
str += sprintf(str, "%d\n", tgt->nic_assoc);
break;
case ISCSI_BOOT_TGT_CHAP_TYPE:
str += sprintf(str, "%d\n", tgt->chap_type);
break;
case ISCSI_BOOT_TGT_NAME:
str += sprintf_string(str, tgt->tgt_name_len,
(char *)ibft_loc + tgt->tgt_name_off);
break;
case ISCSI_BOOT_TGT_CHAP_NAME:
str += sprintf_string(str, tgt->chap_name_len,
(char *)ibft_loc + tgt->chap_name_off);
break;
case ISCSI_BOOT_TGT_CHAP_SECRET:
str += sprintf_string(str, tgt->chap_secret_len,
(char *)ibft_loc + tgt->chap_secret_off);
break;
case ISCSI_BOOT_TGT_REV_CHAP_NAME:
str += sprintf_string(str, tgt->rev_chap_name_len,
(char *)ibft_loc +
tgt->rev_chap_name_off);
break;
case ISCSI_BOOT_TGT_REV_CHAP_SECRET:
str += sprintf_string(str, tgt->rev_chap_secret_len,
(char *)ibft_loc +
tgt->rev_chap_secret_off);
break;
default:
break;
}
return str - buf;
}
static int __init ibft_check_device(void)
{
int len;
u8 *pos;
u8 csum = 0;
len = ibft_addr->header.length;
if (ibft_addr->header.revision != 1) {
printk(KERN_ERR "iBFT module supports only revision 1, " \
"while this is %d.\n",
ibft_addr->header.revision);
return -ENOENT;
}
for (pos = (u8 *)ibft_addr; pos < (u8 *)ibft_addr + len; pos++)
csum += *pos;
if (csum) {
printk(KERN_ERR "iBFT has incorrect checksum (0x%x)!\n", csum);
return -ENOENT;
}
return 0;
}
static mode_t ibft_check_nic_for(void *data, int type)
{
struct ibft_kobject *entry = data;
struct ibft_nic *nic = entry->nic;
mode_t rc = 0;
switch (type) {
case ISCSI_BOOT_ETH_INDEX:
case ISCSI_BOOT_ETH_FLAGS:
rc = S_IRUGO;
break;
case ISCSI_BOOT_ETH_IP_ADDR:
if (memcmp(nic->ip_addr, nulls, sizeof(nic->ip_addr)))
rc = S_IRUGO;
break;
case ISCSI_BOOT_ETH_SUBNET_MASK:
if (nic->subnet_mask_prefix)
rc = S_IRUGO;
break;
case ISCSI_BOOT_ETH_ORIGIN:
rc = S_IRUGO;
break;
case ISCSI_BOOT_ETH_GATEWAY:
if (memcmp(nic->gateway, nulls, sizeof(nic->gateway)))
rc = S_IRUGO;
break;
case ISCSI_BOOT_ETH_PRIMARY_DNS:
if (memcmp(nic->primary_dns, nulls,
sizeof(nic->primary_dns)))
rc = S_IRUGO;
break;
case ISCSI_BOOT_ETH_SECONDARY_DNS:
if (memcmp(nic->secondary_dns, nulls,
sizeof(nic->secondary_dns)))
rc = S_IRUGO;
break;
case ISCSI_BOOT_ETH_DHCP:
if (memcmp(nic->dhcp, nulls, sizeof(nic->dhcp)))
rc = S_IRUGO;
break;
case ISCSI_BOOT_ETH_VLAN:
case ISCSI_BOOT_ETH_MAC:
rc = S_IRUGO;
break;
case ISCSI_BOOT_ETH_HOSTNAME:
if (nic->hostname_off)
rc = S_IRUGO;
break;
default:
break;
}
return rc;
}
static mode_t __init ibft_check_tgt_for(void *data, int type)
{
struct ibft_kobject *entry = data;
struct ibft_tgt *tgt = entry->tgt;
mode_t rc = 0;
switch (type) {
case ISCSI_BOOT_TGT_INDEX:
case ISCSI_BOOT_TGT_FLAGS:
case ISCSI_BOOT_TGT_IP_ADDR:
case ISCSI_BOOT_TGT_PORT:
case ISCSI_BOOT_TGT_LUN:
case ISCSI_BOOT_TGT_NIC_ASSOC:
case ISCSI_BOOT_TGT_CHAP_TYPE:
rc = S_IRUGO;
case ISCSI_BOOT_TGT_NAME:
if (tgt->tgt_name_len)
rc = S_IRUGO;
break;
case ISCSI_BOOT_TGT_CHAP_NAME:
case ISCSI_BOOT_TGT_CHAP_SECRET:
if (tgt->chap_name_len)
rc = S_IRUGO;
break;
case ISCSI_BOOT_TGT_REV_CHAP_NAME:
case ISCSI_BOOT_TGT_REV_CHAP_SECRET:
if (tgt->rev_chap_name_len)
rc = S_IRUGO;
break;
default:
break;
}
return rc;
}
static mode_t __init ibft_check_initiator_for(void *data, int type)
{
struct ibft_kobject *entry = data;
struct ibft_initiator *init = entry->initiator;
mode_t rc = 0;
switch (type) {
case ISCSI_BOOT_INI_INDEX:
case ISCSI_BOOT_INI_FLAGS:
rc = S_IRUGO;
break;
case ISCSI_BOOT_INI_ISNS_SERVER:
if (memcmp(init->isns_server, nulls,
sizeof(init->isns_server)))
rc = S_IRUGO;
break;
case ISCSI_BOOT_INI_SLP_SERVER:
if (memcmp(init->slp_server, nulls,
sizeof(init->slp_server)))
rc = S_IRUGO;
break;
case ISCSI_BOOT_INI_PRI_RADIUS_SERVER:
if (memcmp(init->pri_radius_server, nulls,
sizeof(init->pri_radius_server)))
rc = S_IRUGO;
break;
case ISCSI_BOOT_INI_SEC_RADIUS_SERVER:
if (memcmp(init->sec_radius_server, nulls,
sizeof(init->sec_radius_server)))
rc = S_IRUGO;
break;
case ISCSI_BOOT_INI_INITIATOR_NAME:
if (init->initiator_name_len)
rc = S_IRUGO;
break;
default:
break;
}
return rc;
}
static void ibft_kobj_release(void *data)
{
kfree(data);
}
static int __init ibft_create_kobject(struct acpi_table_ibft *header,
struct ibft_hdr *hdr)
{
struct iscsi_boot_kobj *boot_kobj = NULL;
struct ibft_kobject *ibft_kobj = NULL;
struct ibft_nic *nic = (struct ibft_nic *)hdr;
struct pci_dev *pci_dev;
int rc = 0;
ibft_kobj = kzalloc(sizeof(*ibft_kobj), GFP_KERNEL);
if (!ibft_kobj)
return -ENOMEM;
ibft_kobj->header = header;
ibft_kobj->hdr = hdr;
switch (hdr->id) {
case id_initiator:
rc = ibft_verify_hdr("initiator", hdr, id_initiator,
sizeof(*ibft_kobj->initiator));
if (rc)
break;
boot_kobj = iscsi_boot_create_initiator(boot_kset, hdr->index,
ibft_kobj,
ibft_attr_show_initiator,
ibft_check_initiator_for,
ibft_kobj_release);
if (!boot_kobj) {
rc = -ENOMEM;
goto free_ibft_obj;
}
break;
case id_nic:
rc = ibft_verify_hdr("ethernet", hdr, id_nic,
sizeof(*ibft_kobj->nic));
if (rc)
break;
boot_kobj = iscsi_boot_create_ethernet(boot_kset, hdr->index,
ibft_kobj,
ibft_attr_show_nic,
ibft_check_nic_for,
ibft_kobj_release);
if (!boot_kobj) {
rc = -ENOMEM;
goto free_ibft_obj;
}
break;
case id_target:
rc = ibft_verify_hdr("target", hdr, id_target,
sizeof(*ibft_kobj->tgt));
if (rc)
break;
boot_kobj = iscsi_boot_create_target(boot_kset, hdr->index,
ibft_kobj,
ibft_attr_show_target,
ibft_check_tgt_for,
ibft_kobj_release);
if (!boot_kobj) {
rc = -ENOMEM;
goto free_ibft_obj;
}
break;
case id_reserved:
case id_control:
case id_extensions:
rc = 1;
break;
default:
printk(KERN_ERR "iBFT has unknown structure type (%d). " \
"Report this bug to %.6s!\n", hdr->id,
header->header.oem_id);
rc = 1;
break;
}
if (rc) {
rc = 0;
goto free_ibft_obj;
}
if (hdr->id == id_nic) {
pci_dev = pci_get_bus_and_slot((nic->pci_bdf & 0xff00) >> 8,
(nic->pci_bdf & 0xff));
if (pci_dev) {
rc = sysfs_create_link(&boot_kobj->kobj,
&pci_dev->dev.kobj, "device");
pci_dev_put(pci_dev);
}
}
return 0;
free_ibft_obj:
kfree(ibft_kobj);
return rc;
}
static int __init ibft_register_kobjects(struct acpi_table_ibft *header)
{
struct ibft_control *control = NULL;
void *ptr, *end;
int rc = 0;
u16 offset;
u16 eot_offset;
control = (void *)header + sizeof(*header);
end = (void *)control + control->hdr.length;
eot_offset = (void *)header + header->header.length - (void *)control;
rc = ibft_verify_hdr("control", (struct ibft_hdr *)control, id_control,
sizeof(*control));
rc |= ((control->hdr.index) ? -ENODEV : 0);
if (rc) {
printk(KERN_ERR "iBFT error: Control header is invalid!\n");
return rc;
}
for (ptr = &control->initiator_off; ptr < end; ptr += sizeof(u16)) {
offset = *(u16 *)ptr;
if (offset && offset < header->header.length &&
offset < eot_offset) {
rc = ibft_create_kobject(header,
(void *)header + offset);
if (rc)
break;
}
}
return rc;
}
static void ibft_unregister(void)
{
struct iscsi_boot_kobj *boot_kobj, *tmp_kobj;
struct ibft_kobject *ibft_kobj;
list_for_each_entry_safe(boot_kobj, tmp_kobj,
&boot_kset->kobj_list, list) {
ibft_kobj = boot_kobj->data;
if (ibft_kobj->hdr->id == id_nic)
sysfs_remove_link(&boot_kobj->kobj, "device");
};
}
static void ibft_cleanup(void)
{
if (boot_kset) {
ibft_unregister();
iscsi_boot_destroy_kset(boot_kset);
}
}
static void __exit ibft_exit(void)
{
ibft_cleanup();
}
static int __init ibft_init(void)
{
int rc = 0;
if (ibft_addr) {
printk(KERN_INFO "iBFT detected at 0x%llx.\n",
(u64)isa_virt_to_bus(ibft_addr));
rc = ibft_check_device();
if (rc)
return rc;
boot_kset = iscsi_boot_create_kset("ibft");
if (!boot_kset)
return -ENOMEM;
rc = ibft_register_kobjects(ibft_addr);
if (rc)
goto out_free;
} else
printk(KERN_INFO "No iBFT detected.\n");
return 0;
out_free:
ibft_cleanup();
return rc;
}
