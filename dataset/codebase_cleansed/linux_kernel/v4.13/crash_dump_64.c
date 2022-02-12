ssize_t copy_oldmem_page(unsigned long pfn, char *buf,
size_t csize, unsigned long offset, int userbuf)
{
void *vaddr;
if (!csize)
return 0;
vaddr = ioremap_cache(pfn << PAGE_SHIFT, PAGE_SIZE);
if (!vaddr)
return -ENOMEM;
if (userbuf) {
if (copy_to_user(buf, vaddr + offset, csize)) {
iounmap(vaddr);
return -EFAULT;
}
} else
memcpy(buf, vaddr + offset, csize);
set_iounmap_nonlazy();
iounmap(vaddr);
return csize;
}
