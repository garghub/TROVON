static int fpuemu_stat_get(void *data, u64 *val)
{
int cpu;
unsigned long sum = 0;
for_each_online_cpu(cpu) {
struct mips_fpu_emulator_stats *ps;
local_t *pv;
ps = &per_cpu(fpuemustats, cpu);
pv = (void *)ps + (unsigned long)data;
sum += local_read(pv);
}
*val = sum;
return 0;
}
static int __init debugfs_fpuemu(void)
{
struct dentry *d, *dir;
if (!mips_debugfs_dir)
return -ENODEV;
dir = debugfs_create_dir("fpuemustats", mips_debugfs_dir);
if (!dir)
return -ENOMEM;
#define FPU_EMU_STAT_OFFSET(m) \
offsetof(struct mips_fpu_emulator_stats, m)
#define FPU_STAT_CREATE(m) \
do { \
d = debugfs_create_file(#m , S_IRUGO, dir, \
(void *)FPU_EMU_STAT_OFFSET(m), \
&fops_fpuemu_stat); \
if (!d) \
return -ENOMEM; \
} while (0)
FPU_STAT_CREATE(emulated);
FPU_STAT_CREATE(loads);
FPU_STAT_CREATE(stores);
FPU_STAT_CREATE(cp1ops);
FPU_STAT_CREATE(cp1xops);
FPU_STAT_CREATE(errors);
FPU_STAT_CREATE(ieee754_inexact);
FPU_STAT_CREATE(ieee754_underflow);
FPU_STAT_CREATE(ieee754_overflow);
FPU_STAT_CREATE(ieee754_zerodiv);
FPU_STAT_CREATE(ieee754_invalidop);
FPU_STAT_CREATE(ds_emul);
return 0;
}
