static void update_mmap_min_addr(void)
{
#ifdef CONFIG_LSM_MMAP_MIN_ADDR
if (dac_mmap_min_addr > CONFIG_LSM_MMAP_MIN_ADDR)
mmap_min_addr = dac_mmap_min_addr;
else
mmap_min_addr = CONFIG_LSM_MMAP_MIN_ADDR;
#else
mmap_min_addr = dac_mmap_min_addr;
#endif
}
int mmap_min_addr_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
int ret;
if (write && !capable(CAP_SYS_RAWIO))
return -EPERM;
ret = proc_doulongvec_minmax(table, write, buffer, lenp, ppos);
update_mmap_min_addr();
return ret;
}
static int __init init_mmap_min_addr(void)
{
update_mmap_min_addr();
return 0;
}
