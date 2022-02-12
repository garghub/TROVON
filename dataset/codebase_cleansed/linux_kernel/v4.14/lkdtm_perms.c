static void do_nothing(void)
{
return;
}
static void do_overwritten(void)
{
pr_info("do_overwritten wasn't overwritten!\n");
return;
}
static noinline void execute_location(void *dst, bool write)
{
void (*func)(void) = dst;
pr_info("attempting ok execution at %p\n", do_nothing);
do_nothing();
if (write == CODE_WRITE) {
memcpy(dst, do_nothing, EXEC_SIZE);
flush_icache_range((unsigned long)dst,
(unsigned long)dst + EXEC_SIZE);
}
pr_info("attempting bad execution at %p\n", func);
func();
}
static void execute_user_location(void *dst)
{
int copied;
void (*func)(void) = dst;
pr_info("attempting ok execution at %p\n", do_nothing);
do_nothing();
copied = access_process_vm(current, (unsigned long)dst, do_nothing,
EXEC_SIZE, FOLL_WRITE);
if (copied < EXEC_SIZE)
return;
pr_info("attempting bad execution at %p\n", func);
func();
}
void lkdtm_WRITE_RO(void)
{
unsigned long *ptr = (unsigned long *)&rodata;
pr_info("attempting bad rodata write at %p\n", ptr);
*ptr ^= 0xabcd1234;
}
void lkdtm_WRITE_RO_AFTER_INIT(void)
{
unsigned long *ptr = &ro_after_init;
if ((*ptr & 0xAA) != 0xAA) {
pr_info("%p was NOT written during init!?\n", ptr);
return;
}
pr_info("attempting bad ro_after_init write at %p\n", ptr);
*ptr ^= 0xabcd1234;
}
void lkdtm_WRITE_KERN(void)
{
size_t size;
unsigned char *ptr;
size = (unsigned long)do_overwritten - (unsigned long)do_nothing;
ptr = (unsigned char *)do_overwritten;
pr_info("attempting bad %zu byte write at %p\n", size, ptr);
memcpy(ptr, (unsigned char *)do_nothing, size);
flush_icache_range((unsigned long)ptr, (unsigned long)(ptr + size));
do_overwritten();
}
void lkdtm_EXEC_DATA(void)
{
execute_location(data_area, CODE_WRITE);
}
void lkdtm_EXEC_STACK(void)
{
u8 stack_area[EXEC_SIZE];
execute_location(stack_area, CODE_WRITE);
}
void lkdtm_EXEC_KMALLOC(void)
{
u32 *kmalloc_area = kmalloc(EXEC_SIZE, GFP_KERNEL);
execute_location(kmalloc_area, CODE_WRITE);
kfree(kmalloc_area);
}
void lkdtm_EXEC_VMALLOC(void)
{
u32 *vmalloc_area = vmalloc(EXEC_SIZE);
execute_location(vmalloc_area, CODE_WRITE);
vfree(vmalloc_area);
}
void lkdtm_EXEC_RODATA(void)
{
execute_location(lkdtm_rodata_do_nothing, CODE_AS_IS);
}
void lkdtm_EXEC_USERSPACE(void)
{
unsigned long user_addr;
user_addr = vm_mmap(NULL, 0, PAGE_SIZE,
PROT_READ | PROT_WRITE | PROT_EXEC,
MAP_ANONYMOUS | MAP_PRIVATE, 0);
if (user_addr >= TASK_SIZE) {
pr_warn("Failed to allocate user memory\n");
return;
}
execute_user_location((void *)user_addr);
vm_munmap(user_addr, PAGE_SIZE);
}
void lkdtm_ACCESS_USERSPACE(void)
{
unsigned long user_addr, tmp = 0;
unsigned long *ptr;
user_addr = vm_mmap(NULL, 0, PAGE_SIZE,
PROT_READ | PROT_WRITE | PROT_EXEC,
MAP_ANONYMOUS | MAP_PRIVATE, 0);
if (user_addr >= TASK_SIZE) {
pr_warn("Failed to allocate user memory\n");
return;
}
if (copy_to_user((void __user *)user_addr, &tmp, sizeof(tmp))) {
pr_warn("copy_to_user failed\n");
vm_munmap(user_addr, PAGE_SIZE);
return;
}
ptr = (unsigned long *)user_addr;
pr_info("attempting bad read at %p\n", ptr);
tmp = *ptr;
tmp += 0xc0dec0de;
pr_info("attempting bad write at %p\n", ptr);
*ptr = tmp;
vm_munmap(user_addr, PAGE_SIZE);
}
void __init lkdtm_perms_init(void)
{
ro_after_init |= 0xAA;
}
