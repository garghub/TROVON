void __init setup_trampolines(void)
{
phys_addr_t mem;
size_t size = PAGE_ALIGN(x86_trampoline_end - x86_trampoline_start);
mem = memblock_find_in_range(0, 1<<20, size, PAGE_SIZE);
if (mem == MEMBLOCK_ERROR)
panic("Cannot allocate trampoline\n");
x86_trampoline_base = __va(mem);
memblock_x86_reserve_range(mem, mem + size, "TRAMPOLINE");
printk(KERN_DEBUG "Base memory trampoline at [%p] %llx size %zu\n",
x86_trampoline_base, (unsigned long long)mem, size);
memcpy(x86_trampoline_base, x86_trampoline_start, size);
}
static int __init configure_trampolines(void)
{
size_t size = PAGE_ALIGN(x86_trampoline_end - x86_trampoline_start);
set_memory_x((unsigned long)x86_trampoline_base, size >> PAGE_SHIFT);
return 0;
}
