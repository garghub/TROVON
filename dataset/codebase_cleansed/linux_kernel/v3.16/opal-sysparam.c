static ssize_t opal_get_sys_param(u32 param_id, u32 length, void *buffer)
{
struct opal_msg msg;
ssize_t ret;
int token;
token = opal_async_get_token_interruptible();
if (token < 0) {
if (token != -ERESTARTSYS)
pr_err("%s: Couldn't get the token, returning\n",
__func__);
ret = token;
goto out;
}
ret = opal_get_param(token, param_id, (u64)buffer, length);
if (ret != OPAL_ASYNC_COMPLETION)
goto out_token;
ret = opal_async_wait_response(token, &msg);
if (ret) {
pr_err("%s: Failed to wait for the async response, %zd\n",
__func__, ret);
goto out_token;
}
ret = be64_to_cpu(msg.params[1]);
out_token:
opal_async_release_token(token);
out:
return ret;
}
static int opal_set_sys_param(u32 param_id, u32 length, void *buffer)
{
struct opal_msg msg;
int ret, token;
token = opal_async_get_token_interruptible();
if (token < 0) {
if (token != -ERESTARTSYS)
pr_err("%s: Couldn't get the token, returning\n",
__func__);
ret = token;
goto out;
}
ret = opal_set_param(token, param_id, (u64)buffer, length);
if (ret != OPAL_ASYNC_COMPLETION)
goto out_token;
ret = opal_async_wait_response(token, &msg);
if (ret) {
pr_err("%s: Failed to wait for the async response, %d\n",
__func__, ret);
goto out_token;
}
ret = be64_to_cpu(msg.params[1]);
out_token:
opal_async_release_token(token);
out:
return ret;
}
static ssize_t sys_param_show(struct kobject *kobj,
struct kobj_attribute *kobj_attr, char *buf)
{
struct param_attr *attr = container_of(kobj_attr, struct param_attr,
kobj_attr);
ssize_t ret;
mutex_lock(&opal_sysparam_mutex);
ret = opal_get_sys_param(attr->param_id, attr->param_size,
param_data_buf);
if (ret)
goto out;
memcpy(buf, param_data_buf, attr->param_size);
ret = attr->param_size;
out:
mutex_unlock(&opal_sysparam_mutex);
return ret;
}
static ssize_t sys_param_store(struct kobject *kobj,
struct kobj_attribute *kobj_attr, const char *buf, size_t count)
{
struct param_attr *attr = container_of(kobj_attr, struct param_attr,
kobj_attr);
ssize_t ret;
if (count > MAX_PARAM_DATA_LEN)
count = MAX_PARAM_DATA_LEN;
mutex_lock(&opal_sysparam_mutex);
memcpy(param_data_buf, buf, count);
ret = opal_set_sys_param(attr->param_id, attr->param_size,
param_data_buf);
mutex_unlock(&opal_sysparam_mutex);
if (!ret)
ret = count;
return ret;
}
void __init opal_sys_param_init(void)
{
struct device_node *sysparam;
struct param_attr *attr;
u32 *id, *size;
int count, i;
u8 *perm;
if (!opal_kobj) {
pr_warn("SYSPARAM: opal kobject is not available\n");
goto out;
}
sysparam_kobj = kobject_create_and_add("sysparams", opal_kobj);
if (!sysparam_kobj) {
pr_err("SYSPARAM: Failed to create sysparam kobject\n");
goto out;
}
param_data_buf = kzalloc(MAX_PARAM_DATA_LEN, GFP_KERNEL);
if (!param_data_buf) {
pr_err("SYSPARAM: Failed to allocate memory for param data "
"buf\n");
goto out_kobj_put;
}
sysparam = of_find_node_by_path("/ibm,opal/sysparams");
if (!sysparam) {
pr_err("SYSPARAM: Opal sysparam node not found\n");
goto out_param_buf;
}
if (!of_device_is_compatible(sysparam, "ibm,opal-sysparams")) {
pr_err("SYSPARAM: Opal sysparam node not compatible\n");
goto out_node_put;
}
count = of_property_count_strings(sysparam, "param-name");
if (count < 0) {
pr_err("SYSPARAM: No string found of property param-name in "
"the node %s\n", sysparam->name);
goto out_node_put;
}
id = kzalloc(sizeof(*id) * count, GFP_KERNEL);
if (!id) {
pr_err("SYSPARAM: Failed to allocate memory to read parameter "
"id\n");
goto out_node_put;
}
size = kzalloc(sizeof(*size) * count, GFP_KERNEL);
if (!size) {
pr_err("SYSPARAM: Failed to allocate memory to read parameter "
"size\n");
goto out_free_id;
}
perm = kzalloc(sizeof(*perm) * count, GFP_KERNEL);
if (!perm) {
pr_err("SYSPARAM: Failed to allocate memory to read supported "
"action on the parameter");
goto out_free_size;
}
if (of_property_read_u32_array(sysparam, "param-id", id, count)) {
pr_err("SYSPARAM: Missing property param-id in the DT\n");
goto out_free_perm;
}
if (of_property_read_u32_array(sysparam, "param-len", size, count)) {
pr_err("SYSPARAM: Missing property param-len in the DT\n");
goto out_free_perm;
}
if (of_property_read_u8_array(sysparam, "param-perm", perm, count)) {
pr_err("SYSPARAM: Missing property param-perm in the DT\n");
goto out_free_perm;
}
attr = kzalloc(sizeof(*attr) * count, GFP_KERNEL);
if (!attr) {
pr_err("SYSPARAM: Failed to allocate memory for parameter "
"attributes\n");
goto out_free_perm;
}
for (i = 0; i < count; i++) {
if (size[i] > MAX_PARAM_DATA_LEN) {
pr_warn("SYSPARAM: Not creating parameter %d as size "
"exceeds buffer length\n", i);
continue;
}
sysfs_attr_init(&attr[i].kobj_attr.attr);
attr[i].param_id = id[i];
attr[i].param_size = size[i];
if (of_property_read_string_index(sysparam, "param-name", i,
&attr[i].kobj_attr.attr.name))
continue;
switch (perm[i] & 3) {
case OPAL_SYSPARAM_READ:
attr[i].kobj_attr.attr.mode = S_IRUGO;
break;
case OPAL_SYSPARAM_WRITE:
attr[i].kobj_attr.attr.mode = S_IWUSR;
break;
case OPAL_SYSPARAM_RW:
attr[i].kobj_attr.attr.mode = S_IRUGO | S_IWUSR;
break;
default:
break;
}
attr[i].kobj_attr.show = sys_param_show;
attr[i].kobj_attr.store = sys_param_store;
if (sysfs_create_file(sysparam_kobj, &attr[i].kobj_attr.attr)) {
pr_err("SYSPARAM: Failed to create sysfs file %s\n",
attr[i].kobj_attr.attr.name);
goto out_free_attr;
}
}
kfree(perm);
kfree(size);
kfree(id);
of_node_put(sysparam);
return;
out_free_attr:
kfree(attr);
out_free_perm:
kfree(perm);
out_free_size:
kfree(size);
out_free_id:
kfree(id);
out_node_put:
of_node_put(sysparam);
out_param_buf:
kfree(param_data_buf);
out_kobj_put:
kobject_put(sysparam_kobj);
out:
return;
}
