static int ncp_file_mmap_fault(struct vm_area_struct *area,
struct vm_fault *vmf)
{
struct inode *inode = file_inode(area->vm_file);
char *pg_addr;
unsigned int already_read;
unsigned int count;
int bufsize;
int pos;
vmf->page = alloc_page(GFP_HIGHUSER);
if (!vmf->page)
return VM_FAULT_OOM;
pg_addr = kmap(vmf->page);
pos = vmf->pgoff << PAGE_SHIFT;
count = PAGE_SIZE;
bufsize = NCP_SERVER(inode)->buffer_size;
already_read = 0;
if (ncp_make_open(inode, O_RDONLY) >= 0) {
while (already_read < count) {
int read_this_time;
int to_read;
to_read = bufsize - (pos % bufsize);
to_read = min_t(unsigned int, to_read, count - already_read);
if (ncp_read_kernel(NCP_SERVER(inode),
NCP_FINFO(inode)->file_handle,
pos, to_read,
pg_addr + already_read,
&read_this_time) != 0) {
read_this_time = 0;
}
pos += read_this_time;
already_read += read_this_time;
if (read_this_time < to_read) {
break;
}
}
ncp_inode_close(inode);
}
if (already_read < PAGE_SIZE)
memset(pg_addr + already_read, 0, PAGE_SIZE - already_read);
flush_dcache_page(vmf->page);
kunmap(vmf->page);
count_vm_event(PGMAJFAULT);
mem_cgroup_count_vm_event(area->vm_mm, PGMAJFAULT);
return VM_FAULT_MAJOR;
}
int ncp_mmap(struct file *file, struct vm_area_struct *vma)
{
struct inode *inode = file_inode(file);
ncp_dbg(1, "called\n");
if (!ncp_conn_valid(NCP_SERVER(inode)))
return -EIO;
if (vma->vm_flags & VM_SHARED)
return -EINVAL;
if (vma_pages(vma) + vma->vm_pgoff
> (1U << (32 - PAGE_SHIFT)))
return -EFBIG;
vma->vm_ops = &ncp_file_mmap;
file_accessed(file);
return 0;
}
