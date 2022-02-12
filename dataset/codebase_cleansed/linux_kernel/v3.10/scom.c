struct device_node *scom_find_parent(struct device_node *node)
{
struct device_node *par, *tmp;
const u32 *p;
for (par = of_node_get(node); par;) {
if (of_get_property(par, "scom-controller", NULL))
break;
p = of_get_property(par, "scom-parent", NULL);
tmp = par;
if (p == NULL)
par = of_get_parent(par);
else
par = of_find_node_by_phandle(*p);
of_node_put(tmp);
}
return par;
}
scom_map_t scom_map_device(struct device_node *dev, int index)
{
struct device_node *parent;
unsigned int cells, size;
const u32 *prop;
u64 reg, cnt;
scom_map_t ret;
parent = scom_find_parent(dev);
if (parent == NULL)
return 0;
prop = of_get_property(parent, "#scom-cells", NULL);
cells = prop ? *prop : 1;
prop = of_get_property(dev, "scom-reg", &size);
if (!prop)
return 0;
size >>= 2;
if (index >= (size / (2*cells)))
return 0;
reg = of_read_number(&prop[index * cells * 2], cells);
cnt = of_read_number(&prop[index * cells * 2 + cells], cells);
ret = scom_map(parent, reg, cnt);
of_node_put(parent);
return ret;
}
static int scom_addr_set(void *data, u64 val)
{
struct scom_debug_entry *ent = data;
ent->addr = 0;
scom_unmap(ent->map);
ent->map = scom_map(ent->dn, val, 1);
if (scom_map_ok(ent->map))
ent->addr = val;
else
return -EFAULT;
return 0;
}
static int scom_addr_get(void *data, u64 *val)
{
struct scom_debug_entry *ent = data;
*val = ent->addr;
return 0;
}
static int scom_val_set(void *data, u64 val)
{
struct scom_debug_entry *ent = data;
if (!scom_map_ok(ent->map))
return -EFAULT;
scom_write(ent->map, 0, val);
return 0;
}
static int scom_val_get(void *data, u64 *val)
{
struct scom_debug_entry *ent = data;
if (!scom_map_ok(ent->map))
return -EFAULT;
*val = scom_read(ent->map, 0);
return 0;
}
static int scom_debug_init_one(struct dentry *root, struct device_node *dn,
int i)
{
struct scom_debug_entry *ent;
struct dentry *dir;
ent = kzalloc(sizeof(*ent), GFP_KERNEL);
if (!ent)
return -ENOMEM;
ent->dn = of_node_get(dn);
ent->map = SCOM_MAP_INVALID;
spin_lock_init(&ent->lock);
snprintf(ent->name, 8, "scom%d", i);
ent->blob.data = (void*) dn->full_name;
ent->blob.size = strlen(dn->full_name);
dir = debugfs_create_dir(ent->name, root);
if (!dir) {
of_node_put(dn);
kfree(ent);
return -1;
}
debugfs_create_file("addr", 0600, dir, ent, &scom_addr_fops);
debugfs_create_file("value", 0600, dir, ent, &scom_val_fops);
debugfs_create_blob("path", 0400, dir, &ent->blob);
return 0;
}
static int scom_debug_init(void)
{
struct device_node *dn;
struct dentry *root;
int i, rc;
root = debugfs_create_dir("scom", powerpc_debugfs_root);
if (!root)
return -1;
i = rc = 0;
for_each_node_with_property(dn, "scom-controller")
rc |= scom_debug_init_one(root, dn, i++);
return rc;
}
