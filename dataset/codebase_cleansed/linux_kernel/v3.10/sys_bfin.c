asmlinkage void *sys_sram_alloc(size_t size, unsigned long flags)
{
return sram_alloc_with_lsl(size, flags);
}
asmlinkage int sys_sram_free(const void *addr)
{
return sram_free_with_lsl(addr);
}
asmlinkage void *sys_dma_memcpy(void *dest, const void *src, size_t len)
{
return safe_dma_memcpy(dest, src, len);
}
unsigned long get_fb_unmapped_area(struct file *filp, unsigned long orig_addr,
unsigned long len, unsigned long pgoff, unsigned long flags)
{
struct fb_info *info = filp->private_data;
return (unsigned long)info->screen_base;
}
asmlinkage int sys_bfin_spinlock(int *p)
{
int ret, tmp = 0;
spin_lock(&bfin_spinlock_lock);
ret = get_user(tmp, p);
if (likely(ret == 0)) {
if (unlikely(tmp))
ret = 1;
else
put_user(1, p);
}
spin_unlock(&bfin_spinlock_lock);
return ret;
}
