static scom_map_t opal_scom_map(struct device_node *dev, u64 reg, u64 count)
{
struct opal_scom_map *m;
const __be32 *gcid;
if (!of_get_property(dev, "scom-controller", NULL)) {
pr_err("%s: device %s is not a SCOM controller\n",
__func__, dev->full_name);
return SCOM_MAP_INVALID;
}
gcid = of_get_property(dev, "ibm,chip-id", NULL);
if (!gcid) {
pr_err("%s: device %s has no ibm,chip-id\n",
__func__, dev->full_name);
return SCOM_MAP_INVALID;
}
m = kmalloc(sizeof(struct opal_scom_map), GFP_KERNEL);
if (!m)
return NULL;
m->chip = be32_to_cpup(gcid);
m->addr = reg;
return (scom_map_t)m;
}
static void opal_scom_unmap(scom_map_t map)
{
kfree(map);
}
static int opal_xscom_err_xlate(int64_t rc)
{
switch(rc) {
case 0:
return 0;
default:
return -EIO;
}
}
static u64 opal_scom_unmangle(u64 addr)
{
if (addr & (0x1full << 59))
addr = (addr & ~(0xffull << 56)) | (1ull << 63);
return addr;
}
static int opal_scom_read(scom_map_t map, u64 reg, u64 *value)
{
struct opal_scom_map *m = map;
int64_t rc;
__be64 v;
reg = opal_scom_unmangle(m->addr + reg);
rc = opal_xscom_read(m->chip, reg, (__be64 *)__pa(&v));
*value = be64_to_cpu(v);
return opal_xscom_err_xlate(rc);
}
static int opal_scom_write(scom_map_t map, u64 reg, u64 value)
{
struct opal_scom_map *m = map;
int64_t rc;
reg = opal_scom_unmangle(m->addr + reg);
rc = opal_xscom_write(m->chip, reg, value);
return opal_xscom_err_xlate(rc);
}
static int opal_xscom_init(void)
{
if (firmware_has_feature(FW_FEATURE_OPALv3))
scom_init(&opal_scom_controller);
return 0;
}
