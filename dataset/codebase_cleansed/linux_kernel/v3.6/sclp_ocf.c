static void sclp_ocf_change_notify(struct work_struct *work)
{
kobject_uevent(&ocf_kset->kobj, KOBJ_CHANGE);
}
static void sclp_ocf_handler(struct evbuf_header *evbuf)
{
struct gds_vector *v;
struct gds_subvector *sv, *netid, *cpc;
size_t size;
v = sclp_find_gds_vector(evbuf + 1, (void *) evbuf + evbuf->length,
0x9f00);
if (!v)
return;
v = sclp_find_gds_vector(v + 1, (void *) v + v->length, 0x9f22);
if (!v)
return;
sv = sclp_find_gds_subvector(v + 1, (void *) v + v->length, 0x81);
if (!sv)
return;
netid = sclp_find_gds_subvector(sv + 1, (void *) sv + sv->length, 1);
cpc = sclp_find_gds_subvector(sv + 1, (void *) sv + sv->length, 2);
spin_lock(&sclp_ocf_lock);
if (netid) {
size = min(OCF_LENGTH_HMC_NETWORK, (size_t) netid->length);
memcpy(hmc_network, netid + 1, size);
EBCASC(hmc_network, size);
hmc_network[size] = 0;
}
if (cpc) {
size = min(OCF_LENGTH_CPC_NAME, (size_t) cpc->length);
memcpy(cpc_name, cpc + 1, size);
EBCASC(cpc_name, size);
cpc_name[size] = 0;
}
spin_unlock(&sclp_ocf_lock);
schedule_work(&sclp_ocf_change_work);
}
static ssize_t cpc_name_show(struct kobject *kobj,
struct kobj_attribute *attr, char *page)
{
int rc;
spin_lock_irq(&sclp_ocf_lock);
rc = snprintf(page, PAGE_SIZE, "%s\n", cpc_name);
spin_unlock_irq(&sclp_ocf_lock);
return rc;
}
static ssize_t hmc_network_show(struct kobject *kobj,
struct kobj_attribute *attr, char *page)
{
int rc;
spin_lock_irq(&sclp_ocf_lock);
rc = snprintf(page, PAGE_SIZE, "%s\n", hmc_network);
spin_unlock_irq(&sclp_ocf_lock);
return rc;
}
static int __init ocf_init(void)
{
int rc;
INIT_WORK(&sclp_ocf_change_work, sclp_ocf_change_notify);
ocf_kset = kset_create_and_add("ocf", NULL, firmware_kobj);
if (!ocf_kset)
return -ENOMEM;
rc = sysfs_create_group(&ocf_kset->kobj, &ocf_attr_group);
if (rc) {
kset_unregister(ocf_kset);
return rc;
}
return sclp_register(&sclp_ocf_event);
}
