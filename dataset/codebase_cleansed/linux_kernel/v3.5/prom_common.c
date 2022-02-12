int of_getintprop_default(struct device_node *np, const char *name, int def)
{
struct property *prop;
int len;
prop = of_find_property(np, name, &len);
if (!prop || len != 4)
return def;
return *(int *) prop->value;
}
int of_set_property(struct device_node *dp, const char *name, void *val, int len)
{
struct property **prevp;
void *new_val;
int err;
new_val = kmemdup(val, len, GFP_KERNEL);
if (!new_val)
return -ENOMEM;
err = -ENODEV;
mutex_lock(&of_set_property_mutex);
write_lock(&devtree_lock);
prevp = &dp->properties;
while (*prevp) {
struct property *prop = *prevp;
if (!strcasecmp(prop->name, name)) {
void *old_val = prop->value;
int ret;
ret = prom_setprop(dp->phandle, name, val, len);
err = -EINVAL;
if (ret >= 0) {
prop->value = new_val;
prop->length = len;
if (OF_IS_DYNAMIC(prop))
kfree(old_val);
OF_MARK_DYNAMIC(prop);
err = 0;
}
break;
}
prevp = &(*prevp)->next;
}
write_unlock(&devtree_lock);
mutex_unlock(&of_set_property_mutex);
return err;
}
int of_find_in_proplist(const char *list, const char *match, int len)
{
while (len > 0) {
int l;
if (!strcmp(list, match))
return 1;
l = strlen(list) + 1;
list += l;
len -= l;
}
return 0;
}
static int __init handle_nextprop_quirks(char *buf, const char *name)
{
if (!name || strlen(name) == 0)
return -1;
#ifdef CONFIG_SPARC32
strcpy(buf, name);
#endif
return 0;
}
static int __init prom_common_nextprop(phandle node, char *prev, char *buf)
{
const char *name;
buf[0] = '\0';
name = prom_nextprop(node, prev, buf);
return handle_nextprop_quirks(buf, name);
}
void __init prom_build_devicetree(void)
{
of_pdt_build_devicetree(prom_root_node, &prom_sparc_ops);
of_console_init();
pr_info("PROM: Built device tree with %u bytes of memory.\n",
prom_early_allocated);
}
