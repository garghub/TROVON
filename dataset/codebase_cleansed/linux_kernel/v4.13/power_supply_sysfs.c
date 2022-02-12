static ssize_t power_supply_show_property(struct device *dev,
struct device_attribute *attr,
char *buf) {
ssize_t ret = 0;
struct power_supply *psy = dev_get_drvdata(dev);
const ptrdiff_t off = attr - power_supply_attrs;
union power_supply_propval value;
if (off == POWER_SUPPLY_PROP_TYPE) {
value.intval = psy->desc->type;
} else {
ret = power_supply_get_property(psy, off, &value);
if (ret < 0) {
if (ret == -ENODATA)
dev_dbg(dev, "driver has no data for `%s' property\n",
attr->attr.name);
else if (ret != -ENODEV && ret != -EAGAIN)
dev_err(dev, "driver failed to report `%s' property: %zd\n",
attr->attr.name, ret);
return ret;
}
}
if (off == POWER_SUPPLY_PROP_STATUS)
return sprintf(buf, "%s\n",
power_supply_status_text[value.intval]);
else if (off == POWER_SUPPLY_PROP_CHARGE_TYPE)
return sprintf(buf, "%s\n",
power_supply_charge_type_text[value.intval]);
else if (off == POWER_SUPPLY_PROP_HEALTH)
return sprintf(buf, "%s\n",
power_supply_health_text[value.intval]);
else if (off == POWER_SUPPLY_PROP_TECHNOLOGY)
return sprintf(buf, "%s\n",
power_supply_technology_text[value.intval]);
else if (off == POWER_SUPPLY_PROP_CAPACITY_LEVEL)
return sprintf(buf, "%s\n",
power_supply_capacity_level_text[value.intval]);
else if (off == POWER_SUPPLY_PROP_TYPE)
return sprintf(buf, "%s\n",
power_supply_type_text[value.intval]);
else if (off == POWER_SUPPLY_PROP_SCOPE)
return sprintf(buf, "%s\n",
power_supply_scope_text[value.intval]);
else if (off >= POWER_SUPPLY_PROP_MODEL_NAME)
return sprintf(buf, "%s\n", value.strval);
return sprintf(buf, "%d\n", value.intval);
}
static ssize_t power_supply_store_property(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count) {
ssize_t ret;
struct power_supply *psy = dev_get_drvdata(dev);
const ptrdiff_t off = attr - power_supply_attrs;
union power_supply_propval value;
switch (off) {
case POWER_SUPPLY_PROP_STATUS:
ret = sysfs_match_string(power_supply_status_text, buf);
break;
case POWER_SUPPLY_PROP_CHARGE_TYPE:
ret = sysfs_match_string(power_supply_charge_type_text, buf);
break;
case POWER_SUPPLY_PROP_HEALTH:
ret = sysfs_match_string(power_supply_health_text, buf);
break;
case POWER_SUPPLY_PROP_TECHNOLOGY:
ret = sysfs_match_string(power_supply_technology_text, buf);
break;
case POWER_SUPPLY_PROP_CAPACITY_LEVEL:
ret = sysfs_match_string(power_supply_capacity_level_text, buf);
break;
case POWER_SUPPLY_PROP_SCOPE:
ret = sysfs_match_string(power_supply_scope_text, buf);
break;
default:
ret = -EINVAL;
}
if (ret < 0) {
long long_val;
ret = kstrtol(buf, 10, &long_val);
if (ret < 0)
return ret;
ret = long_val;
}
value.intval = ret;
ret = power_supply_set_property(psy, off, &value);
if (ret < 0)
return ret;
return count;
}
static umode_t power_supply_attr_is_visible(struct kobject *kobj,
struct attribute *attr,
int attrno)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct power_supply *psy = dev_get_drvdata(dev);
umode_t mode = S_IRUSR | S_IRGRP | S_IROTH;
int i;
if (attrno == POWER_SUPPLY_PROP_TYPE)
return mode;
for (i = 0; i < psy->desc->num_properties; i++) {
int property = psy->desc->properties[i];
if (property == attrno) {
if (psy->desc->property_is_writeable &&
psy->desc->property_is_writeable(psy, property) > 0)
mode |= S_IWUSR;
return mode;
}
}
return 0;
}
void power_supply_init_attrs(struct device_type *dev_type)
{
int i;
dev_type->groups = power_supply_attr_groups;
for (i = 0; i < ARRAY_SIZE(power_supply_attrs); i++)
__power_supply_attrs[i] = &power_supply_attrs[i].attr;
}
static char *kstruprdup(const char *str, gfp_t gfp)
{
char *ret, *ustr;
ustr = ret = kmalloc(strlen(str) + 1, gfp);
if (!ret)
return NULL;
while (*str)
*ustr++ = toupper(*str++);
*ustr = 0;
return ret;
}
int power_supply_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct power_supply *psy = dev_get_drvdata(dev);
int ret = 0, j;
char *prop_buf;
char *attrname;
dev_dbg(dev, "uevent\n");
if (!psy || !psy->desc) {
dev_dbg(dev, "No power supply yet\n");
return ret;
}
dev_dbg(dev, "POWER_SUPPLY_NAME=%s\n", psy->desc->name);
ret = add_uevent_var(env, "POWER_SUPPLY_NAME=%s", psy->desc->name);
if (ret)
return ret;
prop_buf = (char *)get_zeroed_page(GFP_KERNEL);
if (!prop_buf)
return -ENOMEM;
for (j = 0; j < psy->desc->num_properties; j++) {
struct device_attribute *attr;
char *line;
attr = &power_supply_attrs[psy->desc->properties[j]];
ret = power_supply_show_property(dev, attr, prop_buf);
if (ret == -ENODEV || ret == -ENODATA) {
ret = 0;
continue;
}
if (ret < 0)
goto out;
line = strchr(prop_buf, '\n');
if (line)
*line = 0;
attrname = kstruprdup(attr->attr.name, GFP_KERNEL);
if (!attrname) {
ret = -ENOMEM;
goto out;
}
dev_dbg(dev, "prop %s=%s\n", attrname, prop_buf);
ret = add_uevent_var(env, "POWER_SUPPLY_%s=%s", attrname, prop_buf);
kfree(attrname);
if (ret)
goto out;
}
out:
free_page((unsigned long)prop_buf);
return ret;
}
