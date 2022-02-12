static inline bool is_pset_node(struct fwnode_handle *fwnode)
{
return !IS_ERR_OR_NULL(fwnode) && fwnode->type == FWNODE_PDATA;
}
static inline struct property_set *to_pset_node(struct fwnode_handle *fwnode)
{
return is_pset_node(fwnode) ?
container_of(fwnode, struct property_set, fwnode) : NULL;
}
static const struct property_entry *pset_prop_get(struct property_set *pset,
const char *name)
{
const struct property_entry *prop;
if (!pset || !pset->properties)
return NULL;
for (prop = pset->properties; prop->name; prop++)
if (!strcmp(name, prop->name))
return prop;
return NULL;
}
static const void *pset_prop_find(struct property_set *pset,
const char *propname, size_t length)
{
const struct property_entry *prop;
const void *pointer;
prop = pset_prop_get(pset, propname);
if (!prop)
return ERR_PTR(-EINVAL);
if (prop->is_array)
pointer = prop->pointer.raw_data;
else
pointer = &prop->value.raw_data;
if (!pointer)
return ERR_PTR(-ENODATA);
if (length > prop->length)
return ERR_PTR(-EOVERFLOW);
return pointer;
}
static int pset_prop_read_u8_array(struct property_set *pset,
const char *propname,
u8 *values, size_t nval)
{
const void *pointer;
size_t length = nval * sizeof(*values);
pointer = pset_prop_find(pset, propname, length);
if (IS_ERR(pointer))
return PTR_ERR(pointer);
memcpy(values, pointer, length);
return 0;
}
static int pset_prop_read_u16_array(struct property_set *pset,
const char *propname,
u16 *values, size_t nval)
{
const void *pointer;
size_t length = nval * sizeof(*values);
pointer = pset_prop_find(pset, propname, length);
if (IS_ERR(pointer))
return PTR_ERR(pointer);
memcpy(values, pointer, length);
return 0;
}
static int pset_prop_read_u32_array(struct property_set *pset,
const char *propname,
u32 *values, size_t nval)
{
const void *pointer;
size_t length = nval * sizeof(*values);
pointer = pset_prop_find(pset, propname, length);
if (IS_ERR(pointer))
return PTR_ERR(pointer);
memcpy(values, pointer, length);
return 0;
}
static int pset_prop_read_u64_array(struct property_set *pset,
const char *propname,
u64 *values, size_t nval)
{
const void *pointer;
size_t length = nval * sizeof(*values);
pointer = pset_prop_find(pset, propname, length);
if (IS_ERR(pointer))
return PTR_ERR(pointer);
memcpy(values, pointer, length);
return 0;
}
static int pset_prop_count_elems_of_size(struct property_set *pset,
const char *propname, size_t length)
{
const struct property_entry *prop;
prop = pset_prop_get(pset, propname);
if (!prop)
return -EINVAL;
return prop->length / length;
}
static int pset_prop_read_string_array(struct property_set *pset,
const char *propname,
const char **strings, size_t nval)
{
const struct property_entry *prop;
const void *pointer;
size_t array_len, length;
prop = pset_prop_get(pset, propname);
if (!prop)
return -EINVAL;
if (!prop->is_array)
array_len = 1;
else
array_len = pset_prop_count_elems_of_size(pset, propname,
sizeof(const char *));
if (!strings)
return array_len;
array_len = min(nval, array_len);
length = array_len * sizeof(*strings);
pointer = pset_prop_find(pset, propname, length);
if (IS_ERR(pointer))
return PTR_ERR(pointer);
memcpy(strings, pointer, length);
return array_len;
}
struct fwnode_handle *dev_fwnode(struct device *dev)
{
return IS_ENABLED(CONFIG_OF) && dev->of_node ?
&dev->of_node->fwnode : dev->fwnode;
}
static bool pset_fwnode_property_present(struct fwnode_handle *fwnode,
const char *propname)
{
return !!pset_prop_get(to_pset_node(fwnode), propname);
}
static int pset_fwnode_read_int_array(struct fwnode_handle *fwnode,
const char *propname,
unsigned int elem_size, void *val,
size_t nval)
{
struct property_set *node = to_pset_node(fwnode);
if (!val)
return pset_prop_count_elems_of_size(node, propname, elem_size);
switch (elem_size) {
case sizeof(u8):
return pset_prop_read_u8_array(node, propname, val, nval);
case sizeof(u16):
return pset_prop_read_u16_array(node, propname, val, nval);
case sizeof(u32):
return pset_prop_read_u32_array(node, propname, val, nval);
case sizeof(u64):
return pset_prop_read_u64_array(node, propname, val, nval);
}
return -ENXIO;
}
static int pset_fwnode_property_read_string_array(struct fwnode_handle *fwnode,
const char *propname,
const char **val, size_t nval)
{
return pset_prop_read_string_array(to_pset_node(fwnode), propname,
val, nval);
}
bool device_property_present(struct device *dev, const char *propname)
{
return fwnode_property_present(dev_fwnode(dev), propname);
}
bool fwnode_property_present(struct fwnode_handle *fwnode, const char *propname)
{
bool ret;
ret = fwnode_call_bool_op(fwnode, property_present, propname);
if (ret == false && !IS_ERR_OR_NULL(fwnode) &&
!IS_ERR_OR_NULL(fwnode->secondary))
ret = fwnode_call_bool_op(fwnode->secondary, property_present,
propname);
return ret;
}
int device_property_read_u8_array(struct device *dev, const char *propname,
u8 *val, size_t nval)
{
return fwnode_property_read_u8_array(dev_fwnode(dev), propname, val, nval);
}
int device_property_read_u16_array(struct device *dev, const char *propname,
u16 *val, size_t nval)
{
return fwnode_property_read_u16_array(dev_fwnode(dev), propname, val, nval);
}
int device_property_read_u32_array(struct device *dev, const char *propname,
u32 *val, size_t nval)
{
return fwnode_property_read_u32_array(dev_fwnode(dev), propname, val, nval);
}
int device_property_read_u64_array(struct device *dev, const char *propname,
u64 *val, size_t nval)
{
return fwnode_property_read_u64_array(dev_fwnode(dev), propname, val, nval);
}
int device_property_read_string_array(struct device *dev, const char *propname,
const char **val, size_t nval)
{
return fwnode_property_read_string_array(dev_fwnode(dev), propname, val, nval);
}
int device_property_read_string(struct device *dev, const char *propname,
const char **val)
{
return fwnode_property_read_string(dev_fwnode(dev), propname, val);
}
int device_property_match_string(struct device *dev, const char *propname,
const char *string)
{
return fwnode_property_match_string(dev_fwnode(dev), propname, string);
}
static int fwnode_property_read_int_array(struct fwnode_handle *fwnode,
const char *propname,
unsigned int elem_size, void *val,
size_t nval)
{
int ret;
ret = fwnode_call_int_op(fwnode, property_read_int_array, propname,
elem_size, val, nval);
if (ret == -EINVAL && !IS_ERR_OR_NULL(fwnode) &&
!IS_ERR_OR_NULL(fwnode->secondary))
ret = fwnode_call_int_op(
fwnode->secondary, property_read_int_array, propname,
elem_size, val, nval);
return ret;
}
int fwnode_property_read_u8_array(struct fwnode_handle *fwnode,
const char *propname, u8 *val, size_t nval)
{
return fwnode_property_read_int_array(fwnode, propname, sizeof(u8),
val, nval);
}
int fwnode_property_read_u16_array(struct fwnode_handle *fwnode,
const char *propname, u16 *val, size_t nval)
{
return fwnode_property_read_int_array(fwnode, propname, sizeof(u16),
val, nval);
}
int fwnode_property_read_u32_array(struct fwnode_handle *fwnode,
const char *propname, u32 *val, size_t nval)
{
return fwnode_property_read_int_array(fwnode, propname, sizeof(u32),
val, nval);
}
int fwnode_property_read_u64_array(struct fwnode_handle *fwnode,
const char *propname, u64 *val, size_t nval)
{
return fwnode_property_read_int_array(fwnode, propname, sizeof(u64),
val, nval);
}
int fwnode_property_read_string_array(struct fwnode_handle *fwnode,
const char *propname, const char **val,
size_t nval)
{
int ret;
ret = fwnode_call_int_op(fwnode, property_read_string_array, propname,
val, nval);
if (ret == -EINVAL && !IS_ERR_OR_NULL(fwnode) &&
!IS_ERR_OR_NULL(fwnode->secondary))
ret = fwnode_call_int_op(fwnode->secondary,
property_read_string_array, propname,
val, nval);
return ret;
}
int fwnode_property_read_string(struct fwnode_handle *fwnode,
const char *propname, const char **val)
{
int ret = fwnode_property_read_string_array(fwnode, propname, val, 1);
return ret < 0 ? ret : 0;
}
int fwnode_property_match_string(struct fwnode_handle *fwnode,
const char *propname, const char *string)
{
const char **values;
int nval, ret;
nval = fwnode_property_read_string_array(fwnode, propname, NULL, 0);
if (nval < 0)
return nval;
if (nval == 0)
return -ENODATA;
values = kcalloc(nval, sizeof(*values), GFP_KERNEL);
if (!values)
return -ENOMEM;
ret = fwnode_property_read_string_array(fwnode, propname, values, nval);
if (ret < 0)
goto out;
ret = match_string(values, nval, string);
if (ret < 0)
ret = -ENODATA;
out:
kfree(values);
return ret;
}
static int property_copy_string_array(struct property_entry *dst,
const struct property_entry *src)
{
char **d;
size_t nval = src->length / sizeof(*d);
int i;
d = kcalloc(nval, sizeof(*d), GFP_KERNEL);
if (!d)
return -ENOMEM;
for (i = 0; i < nval; i++) {
d[i] = kstrdup(src->pointer.str[i], GFP_KERNEL);
if (!d[i] && src->pointer.str[i]) {
while (--i >= 0)
kfree(d[i]);
kfree(d);
return -ENOMEM;
}
}
dst->pointer.raw_data = d;
return 0;
}
static int property_entry_copy_data(struct property_entry *dst,
const struct property_entry *src)
{
int error;
dst->name = kstrdup(src->name, GFP_KERNEL);
if (!dst->name)
return -ENOMEM;
if (src->is_array) {
if (!src->length) {
error = -ENODATA;
goto out_free_name;
}
if (src->is_string) {
error = property_copy_string_array(dst, src);
if (error)
goto out_free_name;
} else {
dst->pointer.raw_data = kmemdup(src->pointer.raw_data,
src->length, GFP_KERNEL);
if (!dst->pointer.raw_data) {
error = -ENOMEM;
goto out_free_name;
}
}
} else if (src->is_string) {
dst->value.str = kstrdup(src->value.str, GFP_KERNEL);
if (!dst->value.str && src->value.str) {
error = -ENOMEM;
goto out_free_name;
}
} else {
dst->value.raw_data = src->value.raw_data;
}
dst->length = src->length;
dst->is_array = src->is_array;
dst->is_string = src->is_string;
return 0;
out_free_name:
kfree(dst->name);
return error;
}
static void property_entry_free_data(const struct property_entry *p)
{
size_t i, nval;
if (p->is_array) {
if (p->is_string && p->pointer.str) {
nval = p->length / sizeof(const char *);
for (i = 0; i < nval; i++)
kfree(p->pointer.str[i]);
}
kfree(p->pointer.raw_data);
} else if (p->is_string) {
kfree(p->value.str);
}
kfree(p->name);
}
struct property_entry *
property_entries_dup(const struct property_entry *properties)
{
struct property_entry *p;
int i, n = 0;
while (properties[n].name)
n++;
p = kcalloc(n + 1, sizeof(*p), GFP_KERNEL);
if (!p)
return ERR_PTR(-ENOMEM);
for (i = 0; i < n; i++) {
int ret = property_entry_copy_data(&p[i], &properties[i]);
if (ret) {
while (--i >= 0)
property_entry_free_data(&p[i]);
kfree(p);
return ERR_PTR(ret);
}
}
return p;
}
void property_entries_free(const struct property_entry *properties)
{
const struct property_entry *p;
for (p = properties; p->name; p++)
property_entry_free_data(p);
kfree(properties);
}
static void pset_free_set(struct property_set *pset)
{
if (!pset)
return;
property_entries_free(pset->properties);
kfree(pset);
}
static struct property_set *pset_copy_set(const struct property_set *pset)
{
struct property_entry *properties;
struct property_set *p;
p = kzalloc(sizeof(*p), GFP_KERNEL);
if (!p)
return ERR_PTR(-ENOMEM);
properties = property_entries_dup(pset->properties);
if (IS_ERR(properties)) {
kfree(p);
return ERR_CAST(properties);
}
p->properties = properties;
return p;
}
void device_remove_properties(struct device *dev)
{
struct fwnode_handle *fwnode;
fwnode = dev_fwnode(dev);
if (!fwnode)
return;
if (is_pset_node(fwnode)) {
set_primary_fwnode(dev, NULL);
pset_free_set(to_pset_node(fwnode));
} else {
fwnode = fwnode->secondary;
if (!IS_ERR(fwnode) && is_pset_node(fwnode)) {
set_secondary_fwnode(dev, NULL);
pset_free_set(to_pset_node(fwnode));
}
}
}
int device_add_properties(struct device *dev,
const struct property_entry *properties)
{
struct property_set *p, pset;
if (!properties)
return -EINVAL;
pset.properties = properties;
p = pset_copy_set(&pset);
if (IS_ERR(p))
return PTR_ERR(p);
p->fwnode.type = FWNODE_PDATA;
p->fwnode.ops = &pset_fwnode_ops;
set_secondary_fwnode(dev, &p->fwnode);
return 0;
}
struct fwnode_handle *fwnode_get_next_parent(struct fwnode_handle *fwnode)
{
struct fwnode_handle *parent = fwnode_get_parent(fwnode);
fwnode_handle_put(fwnode);
return parent;
}
struct fwnode_handle *fwnode_get_parent(struct fwnode_handle *fwnode)
{
return fwnode_call_ptr_op(fwnode, get_parent);
}
struct fwnode_handle *fwnode_get_next_child_node(struct fwnode_handle *fwnode,
struct fwnode_handle *child)
{
return fwnode_call_ptr_op(fwnode, get_next_child_node, child);
}
struct fwnode_handle *device_get_next_child_node(struct device *dev,
struct fwnode_handle *child)
{
struct acpi_device *adev = ACPI_COMPANION(dev);
struct fwnode_handle *fwnode = NULL;
if (dev->of_node)
fwnode = &dev->of_node->fwnode;
else if (adev)
fwnode = acpi_fwnode_handle(adev);
return fwnode_get_next_child_node(fwnode, child);
}
struct fwnode_handle *fwnode_get_named_child_node(struct fwnode_handle *fwnode,
const char *childname)
{
return fwnode_call_ptr_op(fwnode, get_named_child_node, childname);
}
struct fwnode_handle *device_get_named_child_node(struct device *dev,
const char *childname)
{
return fwnode_get_named_child_node(dev_fwnode(dev), childname);
}
void fwnode_handle_get(struct fwnode_handle *fwnode)
{
fwnode_call_void_op(fwnode, get);
}
void fwnode_handle_put(struct fwnode_handle *fwnode)
{
fwnode_call_void_op(fwnode, put);
}
bool fwnode_device_is_available(struct fwnode_handle *fwnode)
{
return fwnode_call_bool_op(fwnode, device_is_available);
}
unsigned int device_get_child_node_count(struct device *dev)
{
struct fwnode_handle *child;
unsigned int count = 0;
device_for_each_child_node(dev, child)
count++;
return count;
}
bool device_dma_supported(struct device *dev)
{
if (IS_ENABLED(CONFIG_OF) && dev->of_node)
return true;
return acpi_dma_supported(ACPI_COMPANION(dev));
}
enum dev_dma_attr device_get_dma_attr(struct device *dev)
{
enum dev_dma_attr attr = DEV_DMA_NOT_SUPPORTED;
if (IS_ENABLED(CONFIG_OF) && dev->of_node) {
if (of_dma_is_coherent(dev->of_node))
attr = DEV_DMA_COHERENT;
else
attr = DEV_DMA_NON_COHERENT;
} else
attr = acpi_get_dma_attr(ACPI_COMPANION(dev));
return attr;
}
int device_get_phy_mode(struct device *dev)
{
const char *pm;
int err, i;
err = device_property_read_string(dev, "phy-mode", &pm);
if (err < 0)
err = device_property_read_string(dev,
"phy-connection-type", &pm);
if (err < 0)
return err;
for (i = 0; i < PHY_INTERFACE_MODE_MAX; i++)
if (!strcasecmp(pm, phy_modes(i)))
return i;
return -ENODEV;
}
static void *device_get_mac_addr(struct device *dev,
const char *name, char *addr,
int alen)
{
int ret = device_property_read_u8_array(dev, name, addr, alen);
if (ret == 0 && alen == ETH_ALEN && is_valid_ether_addr(addr))
return addr;
return NULL;
}
void *device_get_mac_address(struct device *dev, char *addr, int alen)
{
char *res;
res = device_get_mac_addr(dev, "mac-address", addr, alen);
if (res)
return res;
res = device_get_mac_addr(dev, "local-mac-address", addr, alen);
if (res)
return res;
return device_get_mac_addr(dev, "address", addr, alen);
}
struct fwnode_handle *
fwnode_graph_get_next_endpoint(struct fwnode_handle *fwnode,
struct fwnode_handle *prev)
{
return fwnode_call_ptr_op(fwnode, graph_get_next_endpoint, prev);
}
struct fwnode_handle *
fwnode_graph_get_port_parent(struct fwnode_handle *endpoint)
{
struct fwnode_handle *port, *parent;
port = fwnode_get_parent(endpoint);
parent = fwnode_call_ptr_op(port, graph_get_port_parent);
fwnode_handle_put(port);
return parent;
}
struct fwnode_handle *
fwnode_graph_get_remote_port_parent(struct fwnode_handle *fwnode)
{
struct fwnode_handle *endpoint, *parent;
endpoint = fwnode_graph_get_remote_endpoint(fwnode);
parent = fwnode_graph_get_port_parent(endpoint);
fwnode_handle_put(endpoint);
return parent;
}
struct fwnode_handle *fwnode_graph_get_remote_port(struct fwnode_handle *fwnode)
{
return fwnode_get_next_parent(fwnode_graph_get_remote_endpoint(fwnode));
}
struct fwnode_handle *
fwnode_graph_get_remote_endpoint(struct fwnode_handle *fwnode)
{
return fwnode_call_ptr_op(fwnode, graph_get_remote_endpoint);
}
struct fwnode_handle *fwnode_graph_get_remote_node(struct fwnode_handle *fwnode,
u32 port_id, u32 endpoint_id)
{
struct fwnode_handle *endpoint = NULL;
while ((endpoint = fwnode_graph_get_next_endpoint(fwnode, endpoint))) {
struct fwnode_endpoint fwnode_ep;
struct fwnode_handle *remote;
int ret;
ret = fwnode_graph_parse_endpoint(endpoint, &fwnode_ep);
if (ret < 0)
continue;
if (fwnode_ep.port != port_id || fwnode_ep.id != endpoint_id)
continue;
remote = fwnode_graph_get_remote_port_parent(endpoint);
if (!remote)
return NULL;
return fwnode_device_is_available(remote) ? remote : NULL;
}
return NULL;
}
int fwnode_graph_parse_endpoint(struct fwnode_handle *fwnode,
struct fwnode_endpoint *endpoint)
{
memset(endpoint, 0, sizeof(*endpoint));
return fwnode_call_int_op(fwnode, graph_parse_endpoint, endpoint);
}
