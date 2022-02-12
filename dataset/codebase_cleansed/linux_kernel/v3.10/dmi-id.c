static ssize_t sys_dmi_field_show(struct device *dev,
struct device_attribute *attr,
char *page)
{
int field = to_dmi_dev_attr(attr)->field;
ssize_t len;
len = scnprintf(page, PAGE_SIZE, "%s\n", dmi_get_system_info(field));
page[len-1] = '\n';
return len;
}
static void ascii_filter(char *d, const char *s)
{
for (; *s; s++)
if (*s > ' ' && *s < 127 && *s != ':')
*(d++) = *s;
*d = 0;
}
static ssize_t get_modalias(char *buffer, size_t buffer_size)
{
static const struct mafield {
const char *prefix;
int field;
} fields[] = {
{ "bvn", DMI_BIOS_VENDOR },
{ "bvr", DMI_BIOS_VERSION },
{ "bd", DMI_BIOS_DATE },
{ "svn", DMI_SYS_VENDOR },
{ "pn", DMI_PRODUCT_NAME },
{ "pvr", DMI_PRODUCT_VERSION },
{ "rvn", DMI_BOARD_VENDOR },
{ "rn", DMI_BOARD_NAME },
{ "rvr", DMI_BOARD_VERSION },
{ "cvn", DMI_CHASSIS_VENDOR },
{ "ct", DMI_CHASSIS_TYPE },
{ "cvr", DMI_CHASSIS_VERSION },
{ NULL, DMI_NONE }
};
ssize_t l, left;
char *p;
const struct mafield *f;
strcpy(buffer, "dmi");
p = buffer + 3; left = buffer_size - 4;
for (f = fields; f->prefix && left > 0; f++) {
const char *c;
char *t;
c = dmi_get_system_info(f->field);
if (!c)
continue;
t = kmalloc(strlen(c) + 1, GFP_KERNEL);
if (!t)
break;
ascii_filter(t, c);
l = scnprintf(p, left, ":%s%s", f->prefix, t);
kfree(t);
p += l;
left -= l;
}
p[0] = ':';
p[1] = 0;
return p - buffer + 1;
}
static ssize_t sys_dmi_modalias_show(struct device *dev,
struct device_attribute *attr, char *page)
{
ssize_t r;
r = get_modalias(page, PAGE_SIZE-1);
page[r] = '\n';
page[r+1] = 0;
return r+1;
}
static int dmi_dev_uevent(struct device *dev, struct kobj_uevent_env *env)
{
ssize_t len;
if (add_uevent_var(env, "MODALIAS="))
return -ENOMEM;
len = get_modalias(&env->buf[env->buflen - 1],
sizeof(env->buf) - env->buflen);
if (len >= (sizeof(env->buf) - env->buflen))
return -ENOMEM;
env->buflen += len;
return 0;
}
static void __init dmi_id_init_attr_table(void)
{
int i;
i = 0;
ADD_DMI_ATTR(bios_vendor, DMI_BIOS_VENDOR);
ADD_DMI_ATTR(bios_version, DMI_BIOS_VERSION);
ADD_DMI_ATTR(bios_date, DMI_BIOS_DATE);
ADD_DMI_ATTR(sys_vendor, DMI_SYS_VENDOR);
ADD_DMI_ATTR(product_name, DMI_PRODUCT_NAME);
ADD_DMI_ATTR(product_version, DMI_PRODUCT_VERSION);
ADD_DMI_ATTR(product_serial, DMI_PRODUCT_SERIAL);
ADD_DMI_ATTR(product_uuid, DMI_PRODUCT_UUID);
ADD_DMI_ATTR(board_vendor, DMI_BOARD_VENDOR);
ADD_DMI_ATTR(board_name, DMI_BOARD_NAME);
ADD_DMI_ATTR(board_version, DMI_BOARD_VERSION);
ADD_DMI_ATTR(board_serial, DMI_BOARD_SERIAL);
ADD_DMI_ATTR(board_asset_tag, DMI_BOARD_ASSET_TAG);
ADD_DMI_ATTR(chassis_vendor, DMI_CHASSIS_VENDOR);
ADD_DMI_ATTR(chassis_type, DMI_CHASSIS_TYPE);
ADD_DMI_ATTR(chassis_version, DMI_CHASSIS_VERSION);
ADD_DMI_ATTR(chassis_serial, DMI_CHASSIS_SERIAL);
ADD_DMI_ATTR(chassis_asset_tag, DMI_CHASSIS_ASSET_TAG);
sys_dmi_attributes[i++] = &sys_dmi_modalias_attr.attr;
}
static int __init dmi_id_init(void)
{
int ret;
if (!dmi_available)
return -ENODEV;
dmi_id_init_attr_table();
ret = class_register(&dmi_class);
if (ret)
return ret;
dmi_dev = kzalloc(sizeof(*dmi_dev), GFP_KERNEL);
if (!dmi_dev) {
ret = -ENOMEM;
goto fail_class_unregister;
}
dmi_dev->class = &dmi_class;
dev_set_name(dmi_dev, "id");
dmi_dev->groups = sys_dmi_attribute_groups;
ret = device_register(dmi_dev);
if (ret)
goto fail_free_dmi_dev;
return 0;
fail_free_dmi_dev:
kfree(dmi_dev);
fail_class_unregister:
class_unregister(&dmi_class);
return ret;
}
