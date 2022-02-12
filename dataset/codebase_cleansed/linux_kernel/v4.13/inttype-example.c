static int __init testfunc(void)
{
int buf[6];
int i, j;
unsigned int ret;
printk(KERN_INFO "int fifo test start\n");
for (i = 0; i != 10; i++)
kfifo_put(&test, i);
printk(KERN_INFO "fifo len: %u\n", kfifo_len(&test));
ret = kfifo_out(&test, buf, 2);
printk(KERN_INFO "ret: %d\n", ret);
ret = kfifo_in(&test, buf, ret);
printk(KERN_INFO "ret: %d\n", ret);
printk(KERN_INFO "skip 1st element\n");
kfifo_skip(&test);
for (i = 20; kfifo_put(&test, i); i++)
;
printk(KERN_INFO "queue len: %u\n", kfifo_len(&test));
if (kfifo_peek(&test, &i))
printk(KERN_INFO "%d\n", i);
j = 0;
while (kfifo_get(&test, &i)) {
printk(KERN_INFO "item = %d\n", i);
if (i != expected_result[j++]) {
printk(KERN_WARNING "value mismatch: test failed\n");
return -EIO;
}
}
if (j != ARRAY_SIZE(expected_result)) {
printk(KERN_WARNING "size mismatch: test failed\n");
return -EIO;
}
printk(KERN_INFO "test passed\n");
return 0;
}
static ssize_t fifo_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
int ret;
unsigned int copied;
if (mutex_lock_interruptible(&write_lock))
return -ERESTARTSYS;
ret = kfifo_from_user(&test, buf, count, &copied);
mutex_unlock(&write_lock);
return ret ? ret : copied;
}
static ssize_t fifo_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
int ret;
unsigned int copied;
if (mutex_lock_interruptible(&read_lock))
return -ERESTARTSYS;
ret = kfifo_to_user(&test, buf, count, &copied);
mutex_unlock(&read_lock);
return ret ? ret : copied;
}
static int __init example_init(void)
{
#ifdef DYNAMIC
int ret;
ret = kfifo_alloc(&test, FIFO_SIZE, GFP_KERNEL);
if (ret) {
printk(KERN_ERR "error kfifo_alloc\n");
return ret;
}
#endif
if (testfunc() < 0) {
#ifdef DYNAMIC
kfifo_free(&test);
#endif
return -EIO;
}
if (proc_create(PROC_FIFO, 0, NULL, &fifo_fops) == NULL) {
#ifdef DYNAMIC
kfifo_free(&test);
#endif
return -ENOMEM;
}
return 0;
}
static void __exit example_exit(void)
{
remove_proc_entry(PROC_FIFO, NULL);
#ifdef DYNAMIC
kfifo_free(&test);
#endif
}
