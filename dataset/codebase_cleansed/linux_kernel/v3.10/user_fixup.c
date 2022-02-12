static unsigned long compute_size(unsigned long start, unsigned long size, unsigned long *offset)
{
unsigned long fault_addr = current_thread_info()->fault_address;
unsigned long end = start + size;
if (fault_addr < start || fault_addr >= end) {
*offset = 0;
} else {
*offset = fault_addr - start;
size = end - fault_addr;
}
return size;
}
unsigned long copy_from_user_fixup(void *to, const void __user *from, unsigned long size)
{
unsigned long offset;
size = compute_size((unsigned long) from, size, &offset);
if (likely(size))
memset(to + offset, 0, size);
return size;
}
unsigned long copy_to_user_fixup(void __user *to, const void *from, unsigned long size)
{
unsigned long offset;
return compute_size((unsigned long) to, size, &offset);
}
unsigned long copy_in_user_fixup(void __user *to, void __user *from, unsigned long size)
{
unsigned long fault_addr = current_thread_info()->fault_address;
unsigned long start = (unsigned long) to;
unsigned long end = start + size;
if (fault_addr >= start && fault_addr < end)
return end - fault_addr;
start = (unsigned long) from;
end = start + size;
if (fault_addr >= start && fault_addr < end)
return end - fault_addr;
return size;
}
