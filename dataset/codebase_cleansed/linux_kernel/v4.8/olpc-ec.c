void olpc_ec_driver_register(struct olpc_ec_driver *drv, void *arg)
{
ec_driver = drv;
ec_cb_arg = arg;
}
static void olpc_ec_worker(struct work_struct *w)
{
struct olpc_ec_priv *ec = container_of(w, struct olpc_ec_priv, worker);
struct ec_cmd_desc *desc = NULL;
unsigned long flags;
spin_lock_irqsave(&ec->cmd_q_lock, flags);
if (!list_empty(&ec->cmd_q)) {
desc = list_first_entry(&ec->cmd_q, struct ec_cmd_desc, node);
list_del(&desc->node);
}
spin_unlock_irqrestore(&ec->cmd_q_lock, flags);
if (!desc)
return;
mutex_lock(&ec->cmd_lock);
desc->err = ec_driver->ec_cmd(desc->cmd, desc->inbuf, desc->inlen,
desc->outbuf, desc->outlen, ec_cb_arg);
mutex_unlock(&ec->cmd_lock);
complete(&desc->finished);
schedule_work(&ec->worker);
}
static void queue_ec_descriptor(struct ec_cmd_desc *desc,
struct olpc_ec_priv *ec)
{
unsigned long flags;
INIT_LIST_HEAD(&desc->node);
spin_lock_irqsave(&ec->cmd_q_lock, flags);
list_add_tail(&desc->node, &ec->cmd_q);
spin_unlock_irqrestore(&ec->cmd_q_lock, flags);
schedule_work(&ec->worker);
}
int olpc_ec_cmd(u8 cmd, u8 *inbuf, size_t inlen, u8 *outbuf, size_t outlen)
{
struct olpc_ec_priv *ec = ec_priv;
struct ec_cmd_desc desc;
if (WARN_ON(!ec_driver || !ec_driver->ec_cmd))
return -ENODEV;
if (!ec)
return -ENOMEM;
if (WARN_ON(ec->suspended))
return -EBUSY;
might_sleep();
desc.cmd = cmd;
desc.inbuf = inbuf;
desc.outbuf = outbuf;
desc.inlen = inlen;
desc.outlen = outlen;
desc.err = 0;
init_completion(&desc.finished);
queue_ec_descriptor(&desc, ec);
wait_for_completion(&desc.finished);
return desc.err;
}
static ssize_t ec_dbgfs_cmd_write(struct file *file, const char __user *buf,
size_t size, loff_t *ppos)
{
int i, m;
unsigned char ec_cmd[EC_MAX_CMD_ARGS];
unsigned int ec_cmd_int[EC_MAX_CMD_ARGS];
char cmdbuf[64];
int ec_cmd_bytes;
mutex_lock(&ec_dbgfs_lock);
size = simple_write_to_buffer(cmdbuf, sizeof(cmdbuf), ppos, buf, size);
m = sscanf(cmdbuf, "%x:%u %x %x %x %x %x", &ec_cmd_int[0],
&ec_dbgfs_resp_bytes, &ec_cmd_int[1], &ec_cmd_int[2],
&ec_cmd_int[3], &ec_cmd_int[4], &ec_cmd_int[5]);
if (m < 2 || ec_dbgfs_resp_bytes > EC_MAX_CMD_REPLY) {
ec_dbgfs_resp_bytes = 0;
pr_debug("olpc-ec: bad ec cmd: cmd:response-count [arg1 [arg2 ...]]\n");
size = -EINVAL;
goto out;
}
ec_cmd_bytes = m - 2;
for (i = 0; i <= ec_cmd_bytes; i++)
ec_cmd[i] = ec_cmd_int[i];
pr_debug("olpc-ec: debugfs cmd 0x%02x with %d args %5ph, want %d returns\n",
ec_cmd[0], ec_cmd_bytes, ec_cmd + 1,
ec_dbgfs_resp_bytes);
olpc_ec_cmd(ec_cmd[0], (ec_cmd_bytes == 0) ? NULL : &ec_cmd[1],
ec_cmd_bytes, ec_dbgfs_resp, ec_dbgfs_resp_bytes);
pr_debug("olpc-ec: response %8ph (%d bytes expected)\n",
ec_dbgfs_resp, ec_dbgfs_resp_bytes);
out:
mutex_unlock(&ec_dbgfs_lock);
return size;
}
static ssize_t ec_dbgfs_cmd_read(struct file *file, char __user *buf,
size_t size, loff_t *ppos)
{
unsigned int i, r;
char *rp;
char respbuf[64];
mutex_lock(&ec_dbgfs_lock);
rp = respbuf;
rp += sprintf(rp, "%02x", ec_dbgfs_resp[0]);
for (i = 1; i < ec_dbgfs_resp_bytes; i++)
rp += sprintf(rp, ", %02x", ec_dbgfs_resp[i]);
mutex_unlock(&ec_dbgfs_lock);
rp += sprintf(rp, "\n");
r = rp - respbuf;
return simple_read_from_buffer(buf, size, ppos, respbuf, r);
}
static struct dentry *olpc_ec_setup_debugfs(void)
{
struct dentry *dbgfs_dir;
dbgfs_dir = debugfs_create_dir("olpc-ec", NULL);
if (IS_ERR_OR_NULL(dbgfs_dir))
return NULL;
debugfs_create_file("cmd", 0600, dbgfs_dir, NULL, &ec_dbgfs_ops);
return dbgfs_dir;
}
static struct dentry *olpc_ec_setup_debugfs(void)
{
return NULL;
}
static int olpc_ec_probe(struct platform_device *pdev)
{
struct olpc_ec_priv *ec;
int err;
if (!ec_driver)
return -ENODEV;
ec = kzalloc(sizeof(*ec), GFP_KERNEL);
if (!ec)
return -ENOMEM;
ec->drv = ec_driver;
INIT_WORK(&ec->worker, olpc_ec_worker);
mutex_init(&ec->cmd_lock);
INIT_LIST_HEAD(&ec->cmd_q);
spin_lock_init(&ec->cmd_q_lock);
ec_priv = ec;
platform_set_drvdata(pdev, ec);
err = ec_driver->probe ? ec_driver->probe(pdev) : 0;
if (err) {
ec_priv = NULL;
kfree(ec);
} else {
ec->dbgfs_dir = olpc_ec_setup_debugfs();
}
return err;
}
static int olpc_ec_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct olpc_ec_priv *ec = platform_get_drvdata(pdev);
int err = 0;
if (ec_driver->suspend)
err = ec_driver->suspend(pdev);
if (!err)
ec->suspended = true;
return err;
}
static int olpc_ec_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct olpc_ec_priv *ec = platform_get_drvdata(pdev);
ec->suspended = false;
return ec_driver->resume ? ec_driver->resume(pdev) : 0;
}
static int __init olpc_ec_init_module(void)
{
return platform_driver_register(&olpc_ec_plat_driver);
}
