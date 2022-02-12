asmlinkage long sys_cacheflush(unsigned long start, unsigned long end)
{
if (end < start)
return -EINVAL;
return 0;
}
