static ssize_t
show_intc_userimask(struct sysdev_class *cls,
struct sysdev_class_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", (__raw_readl(uimask) >> 4) & 0xf);
}
static ssize_t
store_intc_userimask(struct sysdev_class *cls,
struct sysdev_class_attribute *attr,
const char *buf, size_t count)
{
unsigned long level;
level = simple_strtoul(buf, NULL, 10);
if (level >= intc_get_dfl_prio_level())
return -EINVAL;
__raw_writel(0xa5 << 24 | level << 4, uimask);
return count;
}
static int __init userimask_sysdev_init(void)
{
if (unlikely(!uimask))
return -ENXIO;
return sysdev_class_create_file(&intc_sysdev_class, &attr_userimask);
}
int register_intc_userimask(unsigned long addr)
{
if (unlikely(uimask))
return -EBUSY;
uimask = ioremap_nocache(addr, SZ_4K);
if (unlikely(!uimask))
return -ENOMEM;
pr_info("userimask support registered for levels 0 -> %d\n",
intc_get_dfl_prio_level() - 1);
return 0;
}
