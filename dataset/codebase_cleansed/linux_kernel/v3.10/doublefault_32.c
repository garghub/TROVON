static void doublefault_fn(void)
{
struct desc_ptr gdt_desc = {0, 0};
unsigned long gdt, tss;
native_store_gdt(&gdt_desc);
gdt = gdt_desc.address;
printk(KERN_EMERG "PANIC: double fault, gdt at %08lx [%d bytes]\n", gdt, gdt_desc.size);
if (ptr_ok(gdt)) {
gdt += GDT_ENTRY_TSS << 3;
tss = get_desc_base((struct desc_struct *)gdt);
printk(KERN_EMERG "double fault, tss at %08lx\n", tss);
if (ptr_ok(tss)) {
struct x86_hw_tss *t = (struct x86_hw_tss *)tss;
printk(KERN_EMERG "eip = %08lx, esp = %08lx\n",
t->ip, t->sp);
printk(KERN_EMERG "eax = %08lx, ebx = %08lx, ecx = %08lx, edx = %08lx\n",
t->ax, t->bx, t->cx, t->dx);
printk(KERN_EMERG "esi = %08lx, edi = %08lx\n",
t->si, t->di);
}
}
for (;;)
cpu_relax();
}
