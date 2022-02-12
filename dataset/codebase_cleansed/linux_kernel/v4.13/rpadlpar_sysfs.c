static ssize_t add_slot_store(struct kobject *kobj, struct kobj_attribute *attr,
const char *buf, size_t nbytes)
{
char drc_name[MAX_DRC_NAME_LEN];
char *end;
int rc;
if (nbytes >= MAX_DRC_NAME_LEN)
return 0;
memcpy(drc_name, buf, nbytes);
end = strchr(drc_name, '\n');
if (!end)
end = &drc_name[nbytes];
*end = '\0';
rc = dlpar_add_slot(drc_name);
if (rc)
return rc;
return nbytes;
}
static ssize_t add_slot_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "0\n");
}
static ssize_t remove_slot_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t nbytes)
{
char drc_name[MAX_DRC_NAME_LEN];
int rc;
char *end;
if (nbytes >= MAX_DRC_NAME_LEN)
return 0;
memcpy(drc_name, buf, nbytes);
end = strchr(drc_name, '\n');
if (!end)
end = &drc_name[nbytes];
*end = '\0';
rc = dlpar_remove_slot(drc_name);
if (rc)
return rc;
return nbytes;
}
static ssize_t remove_slot_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "0\n");
}
int dlpar_sysfs_init(void)
{
int error;
dlpar_kobj = kobject_create_and_add(DLPAR_KOBJ_NAME,
&pci_slots_kset->kobj);
if (!dlpar_kobj)
return -EINVAL;
error = sysfs_create_group(dlpar_kobj, &dlpar_attr_group);
if (error)
kobject_put(dlpar_kobj);
return error;
}
void dlpar_sysfs_exit(void)
{
sysfs_remove_group(dlpar_kobj, &dlpar_attr_group);
kobject_put(dlpar_kobj);
}
