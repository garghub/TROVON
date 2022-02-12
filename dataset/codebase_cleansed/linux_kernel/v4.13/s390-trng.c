static int trng_open(struct inode *inode, struct file *file)
{
return nonseekable_open(inode, file);
}
static ssize_t trng_read(struct file *file, char __user *ubuf,
size_t nbytes, loff_t *ppos)
{
u8 buf[32];
u8 *p = buf;
unsigned int n;
ssize_t ret = 0;
if (nbytes > sizeof(buf)) {
p = (u8 *) __get_free_page(GFP_KERNEL);
if (!p)
return -ENOMEM;
}
while (nbytes) {
if (need_resched()) {
if (signal_pending(current)) {
if (ret == 0)
ret = -ERESTARTSYS;
break;
}
schedule();
}
n = nbytes > PAGE_SIZE ? PAGE_SIZE : nbytes;
cpacf_trng(NULL, 0, p, n);
atomic64_add(n, &trng_dev_counter);
if (copy_to_user(ubuf, p, n)) {
ret = -EFAULT;
break;
}
nbytes -= n;
ubuf += n;
ret += n;
}
if (p != buf)
free_page((unsigned long) p);
DEBUG_DBG("trng_read()=%zd\n", ret);
return ret;
}
static ssize_t trng_counter_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
u64 dev_counter = atomic64_read(&trng_dev_counter);
u64 hwrng_counter = atomic64_read(&trng_hwrng_counter);
#if IS_ENABLED(CONFIG_ARCH_RANDOM)
u64 arch_counter = atomic64_read(&s390_arch_random_counter);
return snprintf(buf, PAGE_SIZE,
"trng: %llu\n"
"hwrng: %llu\n"
"arch: %llu\n"
"total: %llu\n",
dev_counter, hwrng_counter, arch_counter,
dev_counter + hwrng_counter + arch_counter);
#else
return snprintf(buf, PAGE_SIZE,
"trng: %llu\n"
"hwrng: %llu\n"
"total: %llu\n",
dev_counter, hwrng_counter,
dev_counter + hwrng_counter);
#endif
}
static inline void _trng_hwrng_read(u8 *buf, size_t len)
{
cpacf_trng(NULL, 0, buf, len);
atomic64_add(len, &trng_hwrng_counter);
}
static int trng_hwrng_data_read(struct hwrng *rng, u32 *data)
{
size_t len = sizeof(*data);
_trng_hwrng_read((u8 *) data, len);
DEBUG_DBG("trng_hwrng_data_read()=%zu\n", len);
return len;
}
static int trng_hwrng_read(struct hwrng *rng, void *data, size_t max, bool wait)
{
size_t len = max <= PAGE_SIZE ? max : PAGE_SIZE;
_trng_hwrng_read((u8 *) data, len);
DEBUG_DBG("trng_hwrng_read()=%zu\n", len);
return len;
}
static void __init trng_debug_init(void)
{
debug_info = debug_register("trng", 1, 1, 4 * sizeof(long));
debug_register_view(debug_info, &debug_sprintf_view);
debug_set_level(debug_info, 3);
}
static void trng_debug_exit(void)
{
debug_unregister(debug_info);
}
static int __init trng_init(void)
{
int ret;
trng_debug_init();
if (!cpacf_query_func(CPACF_PRNO, CPACF_PRNO_TRNG)) {
DEBUG_INFO("trng_init CPACF_PRNO_TRNG not available\n");
ret = -ENODEV;
goto out_dbg;
}
ret = misc_register(&trng_dev);
if (ret) {
DEBUG_WARN("trng_init misc_register() failed rc=%d\n", ret);
goto out_dbg;
}
ret = hwrng_register(&trng_hwrng_dev);
if (ret) {
DEBUG_WARN("trng_init hwrng_register() failed rc=%d\n", ret);
goto out_misc;
}
DEBUG_DBG("trng_init successful\n");
return 0;
out_misc:
misc_deregister(&trng_dev);
out_dbg:
trng_debug_exit();
return ret;
}
static void __exit trng_exit(void)
{
hwrng_unregister(&trng_hwrng_dev);
misc_deregister(&trng_dev);
trng_debug_exit();
}
