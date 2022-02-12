static loff_t page_map_seek(struct file *file, loff_t off, int whence)
{
return fixed_size_llseek(file, off, whence, PAGE_SIZE);
}
static ssize_t page_map_read( struct file *file, char __user *buf, size_t nbytes,
loff_t *ppos)
{
return simple_read_from_buffer(buf, nbytes, ppos,
PDE_DATA(file_inode(file)), PAGE_SIZE);
}
static int page_map_mmap( struct file *file, struct vm_area_struct *vma )
{
if ((vma->vm_end - vma->vm_start) > PAGE_SIZE)
return -EINVAL;
remap_pfn_range(vma, vma->vm_start,
__pa(PDE_DATA(file_inode(file))) >> PAGE_SHIFT,
PAGE_SIZE, vma->vm_page_prot);
return 0;
}
static int __init proc_ppc64_init(void)
{
struct proc_dir_entry *pde;
pde = proc_create_data("powerpc/systemcfg", S_IFREG|S_IRUGO, NULL,
&page_map_fops, vdso_data);
if (!pde)
return 1;
proc_set_size(pde, PAGE_SIZE);
return 0;
}
static int __init proc_ppc64_create(void)
{
struct proc_dir_entry *root;
root = proc_mkdir("powerpc", NULL);
if (!root)
return 1;
#ifdef CONFIG_PPC64
if (!proc_symlink("ppc64", NULL, "powerpc"))
pr_err("Failed to create link /proc/ppc64 -> /proc/powerpc\n");
#endif
if (!of_find_node_by_path("/rtas"))
return 0;
if (!proc_mkdir("rtas", root))
return 1;
if (!proc_symlink("rtas", NULL, "powerpc/rtas"))
return 1;
return 0;
}
