int _access_ok(unsigned long addr, unsigned long size)
{
if (!size)
return 1;
if (!addr || addr > (0xffffffffUL - (size - 1)))
goto _bad_access;
if (segment_eq(get_fs(), KERNEL_DS))
return 1;
if (memory_start <= addr && (addr + size - 1) < memory_end)
return 1;
_bad_access:
pr_debug("Bad access attempt: pid[%d] addr[%08lx] size[0x%lx]\n",
current->pid, addr, size);
return 0;
}
asmlinkage int sys_cache_sync(unsigned long s, unsigned long e)
{
L1D_cache_block_writeback_invalidate(s, e);
L1P_cache_block_invalidate(s, e);
return 0;
}
