static ssize_t vboot_context_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *att, char *buf,
loff_t pos, size_t count)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct cros_ec_dev *ec = container_of(dev, struct cros_ec_dev,
class_dev);
struct cros_ec_device *ecdev = ec->ec_dev;
struct ec_params_vbnvcontext *params;
struct cros_ec_command *msg;
int err;
const size_t para_sz = sizeof(params->op);
const size_t resp_sz = sizeof(struct ec_response_vbnvcontext);
const size_t payload = max(para_sz, resp_sz);
msg = kmalloc(sizeof(*msg) + payload, GFP_KERNEL);
if (!msg)
return -ENOMEM;
params = (struct ec_params_vbnvcontext *)msg->data;
params->op = EC_VBNV_CONTEXT_OP_READ;
msg->version = EC_VER_VBNV_CONTEXT;
msg->command = EC_CMD_VBNV_CONTEXT;
msg->outsize = para_sz;
msg->insize = resp_sz;
err = cros_ec_cmd_xfer(ecdev, msg);
if (err < 0) {
dev_err(dev, "Error sending read request: %d\n", err);
kfree(msg);
return err;
}
memcpy(buf, msg->data, resp_sz);
kfree(msg);
return resp_sz;
}
static ssize_t vboot_context_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr, char *buf,
loff_t pos, size_t count)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct cros_ec_dev *ec = container_of(dev, struct cros_ec_dev,
class_dev);
struct cros_ec_device *ecdev = ec->ec_dev;
struct ec_params_vbnvcontext *params;
struct cros_ec_command *msg;
int err;
const size_t para_sz = sizeof(*params);
const size_t data_sz = sizeof(params->block);
if (count != data_sz)
return -EINVAL;
msg = kmalloc(sizeof(*msg) + para_sz, GFP_KERNEL);
if (!msg)
return -ENOMEM;
params = (struct ec_params_vbnvcontext *)msg->data;
params->op = EC_VBNV_CONTEXT_OP_WRITE;
memcpy(params->block, buf, data_sz);
msg->version = EC_VER_VBNV_CONTEXT;
msg->command = EC_CMD_VBNV_CONTEXT;
msg->outsize = para_sz;
msg->insize = 0;
err = cros_ec_cmd_xfer(ecdev, msg);
if (err < 0) {
dev_err(dev, "Error sending write request: %d\n", err);
kfree(msg);
return err;
}
kfree(msg);
return data_sz;
}
static umode_t cros_ec_vbc_is_visible(struct kobject *kobj,
struct bin_attribute *a, int n)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct cros_ec_dev *ec = container_of(dev, struct cros_ec_dev,
class_dev);
struct device_node *np = ec->ec_dev->dev->of_node;
if (IS_ENABLED(CONFIG_OF) && np) {
if (of_property_read_bool(np, "google,has-vbc-nvram"))
return a->attr.mode;
}
return 0;
}
