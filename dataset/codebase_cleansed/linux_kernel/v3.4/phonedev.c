static int phone_open(struct inode *inode, struct file *file)
{
unsigned int minor = iminor(inode);
int err = 0;
struct phone_device *p;
const struct file_operations *old_fops, *new_fops = NULL;
if (minor >= PHONE_NUM_DEVICES)
return -ENODEV;
mutex_lock(&phone_lock);
p = phone_device[minor];
if (p)
new_fops = fops_get(p->f_op);
if (!new_fops) {
mutex_unlock(&phone_lock);
request_module("char-major-%d-%d", PHONE_MAJOR, minor);
mutex_lock(&phone_lock);
p = phone_device[minor];
if (p == NULL || (new_fops = fops_get(p->f_op)) == NULL)
{
err=-ENODEV;
goto end;
}
}
old_fops = file->f_op;
file->f_op = new_fops;
if (p->open)
err = p->open(p, file);
if (err) {
fops_put(file->f_op);
file->f_op = fops_get(old_fops);
}
fops_put(old_fops);
end:
mutex_unlock(&phone_lock);
return err;
}
int phone_register_device(struct phone_device *p, int unit)
{
int base;
int end;
int i;
base = 0;
end = PHONE_NUM_DEVICES - 1;
if (unit != PHONE_UNIT_ANY) {
base = unit;
end = unit + 1;
}
mutex_lock(&phone_lock);
for (i = base; i < end; i++) {
if (phone_device[i] == NULL) {
phone_device[i] = p;
p->minor = i;
mutex_unlock(&phone_lock);
return 0;
}
}
mutex_unlock(&phone_lock);
return -ENFILE;
}
void phone_unregister_device(struct phone_device *pfd)
{
mutex_lock(&phone_lock);
if (likely(phone_device[pfd->minor] == pfd))
phone_device[pfd->minor] = NULL;
mutex_unlock(&phone_lock);
}
static int __init telephony_init(void)
{
printk(KERN_INFO "Linux telephony interface: v1.00\n");
if (register_chrdev(PHONE_MAJOR, "telephony", &phone_fops)) {
printk("phonedev: unable to get major %d\n", PHONE_MAJOR);
return -EIO;
}
return 0;
}
static void __exit telephony_exit(void)
{
unregister_chrdev(PHONE_MAJOR, "telephony");
}
