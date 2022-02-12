static int smsg_path_pending(struct iucv_path *path, u8 *ipvmid, u8 *ipuser)
{
if (strncmp(ipvmid, "*MSG ", 8) != 0)
return -EINVAL;
return iucv_path_accept(path, &smsg_handler, "SMSGIUCV ", NULL);
}
static void smsg_message_pending(struct iucv_path *path,
struct iucv_message *msg)
{
struct smsg_callback *cb;
unsigned char *buffer;
unsigned char sender[9];
int rc, i;
buffer = kmalloc(msg->length + 1, GFP_ATOMIC | GFP_DMA);
if (!buffer) {
iucv_message_reject(path, msg);
return;
}
rc = iucv_message_receive(path, msg, 0, buffer, msg->length, NULL);
if (rc == 0) {
buffer[msg->length] = 0;
EBCASC(buffer, msg->length);
memcpy(sender, buffer, 8);
sender[8] = 0;
for (i = 7; i >= 0; i--) {
if (sender[i] != ' ' && sender[i] != '\t')
break;
sender[i] = 0;
}
spin_lock(&smsg_list_lock);
list_for_each_entry(cb, &smsg_list, list)
if (strncmp(buffer + 8, cb->prefix, cb->len) == 0) {
cb->callback(sender, buffer + 8);
break;
}
spin_unlock(&smsg_list_lock);
}
kfree(buffer);
}
int smsg_register_callback(const char *prefix,
void (*callback)(const char *from, char *str))
{
struct smsg_callback *cb;
cb = kmalloc(sizeof(struct smsg_callback), GFP_KERNEL);
if (!cb)
return -ENOMEM;
cb->prefix = prefix;
cb->len = strlen(prefix);
cb->callback = callback;
spin_lock_bh(&smsg_list_lock);
list_add_tail(&cb->list, &smsg_list);
spin_unlock_bh(&smsg_list_lock);
return 0;
}
void smsg_unregister_callback(const char *prefix,
void (*callback)(const char *from,
char *str))
{
struct smsg_callback *cb, *tmp;
spin_lock_bh(&smsg_list_lock);
cb = NULL;
list_for_each_entry(tmp, &smsg_list, list)
if (tmp->callback == callback &&
strcmp(tmp->prefix, prefix) == 0) {
cb = tmp;
list_del(&cb->list);
break;
}
spin_unlock_bh(&smsg_list_lock);
kfree(cb);
}
static int smsg_pm_freeze(struct device *dev)
{
#ifdef CONFIG_PM_DEBUG
printk(KERN_WARNING "smsg_pm_freeze\n");
#endif
if (smsg_path && iucv_path_connected) {
iucv_path_sever(smsg_path, NULL);
iucv_path_connected = 0;
}
return 0;
}
static int smsg_pm_restore_thaw(struct device *dev)
{
int rc;
#ifdef CONFIG_PM_DEBUG
printk(KERN_WARNING "smsg_pm_restore_thaw\n");
#endif
if (smsg_path && !iucv_path_connected) {
memset(smsg_path, 0, sizeof(*smsg_path));
smsg_path->msglim = 255;
smsg_path->flags = 0;
rc = iucv_path_connect(smsg_path, &smsg_handler, "*MSG ",
NULL, NULL, NULL);
#ifdef CONFIG_PM_DEBUG
if (rc)
printk(KERN_ERR
"iucv_path_connect returned with rc %i\n", rc);
#endif
if (!rc)
iucv_path_connected = 1;
cpcmd("SET SMSG IUCV", NULL, 0, NULL);
}
return 0;
}
static void __exit smsg_exit(void)
{
cpcmd("SET SMSG IUCV", NULL, 0, NULL);
device_unregister(smsg_dev);
iucv_unregister(&smsg_handler, 1);
driver_unregister(&smsg_driver);
}
static int __init smsg_init(void)
{
int rc;
if (!MACHINE_IS_VM) {
rc = -EPROTONOSUPPORT;
goto out;
}
rc = driver_register(&smsg_driver);
if (rc != 0)
goto out;
rc = iucv_register(&smsg_handler, 1);
if (rc)
goto out_driver;
smsg_path = iucv_path_alloc(255, 0, GFP_KERNEL);
if (!smsg_path) {
rc = -ENOMEM;
goto out_register;
}
rc = iucv_path_connect(smsg_path, &smsg_handler, "*MSG ",
NULL, NULL, NULL);
if (rc)
goto out_free_path;
else
iucv_path_connected = 1;
smsg_dev = kzalloc(sizeof(struct device), GFP_KERNEL);
if (!smsg_dev) {
rc = -ENOMEM;
goto out_free_path;
}
dev_set_name(smsg_dev, "smsg_iucv");
smsg_dev->bus = &iucv_bus;
smsg_dev->parent = iucv_root;
smsg_dev->release = (void (*)(struct device *))kfree;
smsg_dev->driver = &smsg_driver;
rc = device_register(smsg_dev);
if (rc)
goto out_put;
cpcmd("SET SMSG IUCV", NULL, 0, NULL);
return 0;
out_put:
put_device(smsg_dev);
out_free_path:
iucv_path_free(smsg_path);
smsg_path = NULL;
out_register:
iucv_unregister(&smsg_handler, 1);
out_driver:
driver_unregister(&smsg_driver);
out:
return rc;
}
