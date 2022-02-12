static int __init testfunc(void)
{
char buf[100];
unsigned int i;
unsigned int ret;
struct { unsigned char buf[6]; } hello = { "hello" };
printk(KERN_INFO "record fifo test start\n");
kfifo_in(&test, &hello, sizeof(hello));
printk(KERN_INFO "fifo peek len: %u\n", kfifo_peek_len(&test));
for (i = 0; i < 10; i++) {
memset(buf, 'a' + i, i + 1);
kfifo_in(&test, buf, i + 1);
}
printk(KERN_INFO "skip 1st element\n");
kfifo_skip(&test);
printk(KERN_INFO "fifo len: %u\n", kfifo_len(&test));
ret = kfifo_out_peek(&test, buf, sizeof(buf));
if (ret)
printk(KERN_INFO "%.*s\n", ret, buf);
i = 0;
while (!kfifo_is_empty(&test)) {
ret = kfifo_out(&test, buf, sizeof(buf));
buf[ret] = '\0';
printk(KERN_INFO "item = %.*s\n", ret, buf);
if (strcmp(buf, expected_result[i++])) {
printk(KERN_WARNING "value mismatch: test failed\n");
return -EIO;
}
}
if (i != ARRAY_SIZE(expected_result)) {
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
#else
INIT_KFIFO(test);
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
