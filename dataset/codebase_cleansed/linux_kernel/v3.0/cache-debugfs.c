static int cache_seq_show(struct seq_file *file, void *iter)
{
unsigned int cache_type = (unsigned int)file->private;
struct cache_info *cache;
unsigned int waysize, way;
unsigned long ccr;
unsigned long addrstart = 0;
jump_to_uncached();
ccr = __raw_readl(CCR);
if ((ccr & CCR_CACHE_ENABLE) == 0) {
back_to_cached();
seq_printf(file, "disabled\n");
return 0;
}
if (cache_type == CACHE_TYPE_DCACHE) {
addrstart = CACHE_OC_ADDRESS_ARRAY;
cache = &current_cpu_data.dcache;
} else {
addrstart = CACHE_IC_ADDRESS_ARRAY;
cache = &current_cpu_data.icache;
}
waysize = cache->sets;
if ((ccr & CCR_CACHE_ORA) && cache_type == CACHE_TYPE_DCACHE)
waysize >>= 1;
waysize <<= cache->entry_shift;
for (way = 0; way < cache->ways; way++) {
unsigned long addr;
unsigned int line;
seq_printf(file, "-----------------------------------------\n");
seq_printf(file, "Way %d\n", way);
seq_printf(file, "-----------------------------------------\n");
for (addr = addrstart, line = 0;
addr < addrstart + waysize;
addr += cache->linesz, line++) {
unsigned long data = __raw_readl(addr);
if ((data & 1) == 0)
continue;
seq_printf(file, "%3d: %c 0x%lx\n",
line, data & 2 ? 'U' : ' ',
data & 0x1ffffc00);
}
addrstart += cache->way_incr;
}
back_to_cached();
return 0;
}
static int cache_debugfs_open(struct inode *inode, struct file *file)
{
return single_open(file, cache_seq_show, inode->i_private);
}
static int __init cache_debugfs_init(void)
{
struct dentry *dcache_dentry, *icache_dentry;
dcache_dentry = debugfs_create_file("dcache", S_IRUSR, arch_debugfs_dir,
(unsigned int *)CACHE_TYPE_DCACHE,
&cache_debugfs_fops);
if (!dcache_dentry)
return -ENOMEM;
icache_dentry = debugfs_create_file("icache", S_IRUSR, arch_debugfs_dir,
(unsigned int *)CACHE_TYPE_ICACHE,
&cache_debugfs_fops);
if (!icache_dentry) {
debugfs_remove(dcache_dentry);
return -ENOMEM;
}
return 0;
}
