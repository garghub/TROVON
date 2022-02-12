int __init kmemcheck_init(void)
{
#ifdef CONFIG_SMP
if (setup_max_cpus > 1) {
printk(KERN_INFO
"kmemcheck: Limiting number of CPUs to 1.\n");
setup_max_cpus = 1;
}
#endif
if (!kmemcheck_selftest()) {
printk(KERN_INFO "kmemcheck: self-tests failed; disabling\n");
kmemcheck_enabled = 0;
return -EINVAL;
}
printk(KERN_INFO "kmemcheck: Initialized\n");
return 0;
}
static int __init param_kmemcheck(char *str)
{
int val;
int ret;
if (!str)
return -EINVAL;
ret = kstrtoint(str, 0, &val);
if (ret)
return ret;
kmemcheck_enabled = val;
return 0;
}
int kmemcheck_show_addr(unsigned long address)
{
pte_t *pte;
pte = kmemcheck_pte_lookup(address);
if (!pte)
return 0;
set_pte(pte, __pte(pte_val(*pte) | _PAGE_PRESENT));
__flush_tlb_one(address);
return 1;
}
int kmemcheck_hide_addr(unsigned long address)
{
pte_t *pte;
pte = kmemcheck_pte_lookup(address);
if (!pte)
return 0;
set_pte(pte, __pte(pte_val(*pte) & ~_PAGE_PRESENT));
__flush_tlb_one(address);
return 1;
}
bool kmemcheck_active(struct pt_regs *regs)
{
struct kmemcheck_context *data = this_cpu_ptr(&kmemcheck_context);
return data->balance > 0;
}
static void kmemcheck_save_addr(unsigned long addr)
{
struct kmemcheck_context *data = this_cpu_ptr(&kmemcheck_context);
BUG_ON(data->n_addrs >= ARRAY_SIZE(data->addr));
data->addr[data->n_addrs++] = addr;
}
static unsigned int kmemcheck_show_all(void)
{
struct kmemcheck_context *data = this_cpu_ptr(&kmemcheck_context);
unsigned int i;
unsigned int n;
n = 0;
for (i = 0; i < data->n_addrs; ++i)
n += kmemcheck_show_addr(data->addr[i]);
return n;
}
static unsigned int kmemcheck_hide_all(void)
{
struct kmemcheck_context *data = this_cpu_ptr(&kmemcheck_context);
unsigned int i;
unsigned int n;
n = 0;
for (i = 0; i < data->n_addrs; ++i)
n += kmemcheck_hide_addr(data->addr[i]);
return n;
}
void kmemcheck_show(struct pt_regs *regs)
{
struct kmemcheck_context *data = this_cpu_ptr(&kmemcheck_context);
BUG_ON(!irqs_disabled());
if (unlikely(data->balance != 0)) {
kmemcheck_show_all();
kmemcheck_error_save_bug(regs);
data->balance = 0;
return;
}
if (kmemcheck_show_all() == 0)
return;
++data->balance;
if (!(regs->flags & X86_EFLAGS_TF))
data->flags = regs->flags;
regs->flags |= X86_EFLAGS_TF;
regs->flags &= ~X86_EFLAGS_IF;
}
void kmemcheck_hide(struct pt_regs *regs)
{
struct kmemcheck_context *data = this_cpu_ptr(&kmemcheck_context);
int n;
BUG_ON(!irqs_disabled());
if (unlikely(data->balance != 1)) {
kmemcheck_show_all();
kmemcheck_error_save_bug(regs);
data->n_addrs = 0;
data->balance = 0;
if (!(data->flags & X86_EFLAGS_TF))
regs->flags &= ~X86_EFLAGS_TF;
if (data->flags & X86_EFLAGS_IF)
regs->flags |= X86_EFLAGS_IF;
return;
}
if (kmemcheck_enabled)
n = kmemcheck_hide_all();
else
n = kmemcheck_show_all();
if (n == 0)
return;
--data->balance;
data->n_addrs = 0;
if (!(data->flags & X86_EFLAGS_TF))
regs->flags &= ~X86_EFLAGS_TF;
if (data->flags & X86_EFLAGS_IF)
regs->flags |= X86_EFLAGS_IF;
}
void kmemcheck_show_pages(struct page *p, unsigned int n)
{
unsigned int i;
for (i = 0; i < n; ++i) {
unsigned long address;
pte_t *pte;
unsigned int level;
address = (unsigned long) page_address(&p[i]);
pte = lookup_address(address, &level);
BUG_ON(!pte);
BUG_ON(level != PG_LEVEL_4K);
set_pte(pte, __pte(pte_val(*pte) | _PAGE_PRESENT));
set_pte(pte, __pte(pte_val(*pte) & ~_PAGE_HIDDEN));
__flush_tlb_one(address);
}
}
bool kmemcheck_page_is_tracked(struct page *p)
{
return kmemcheck_pte_lookup((unsigned long) page_address(p));
}
void kmemcheck_hide_pages(struct page *p, unsigned int n)
{
unsigned int i;
for (i = 0; i < n; ++i) {
unsigned long address;
pte_t *pte;
unsigned int level;
address = (unsigned long) page_address(&p[i]);
pte = lookup_address(address, &level);
BUG_ON(!pte);
BUG_ON(level != PG_LEVEL_4K);
set_pte(pte, __pte(pte_val(*pte) & ~_PAGE_PRESENT));
set_pte(pte, __pte(pte_val(*pte) | _PAGE_HIDDEN));
__flush_tlb_one(address);
}
}
static void kmemcheck_read_strict(struct pt_regs *regs,
unsigned long addr, unsigned int size)
{
void *shadow;
enum kmemcheck_shadow status;
shadow = kmemcheck_shadow_lookup(addr);
if (!shadow)
return;
kmemcheck_save_addr(addr);
status = kmemcheck_shadow_test(shadow, size);
if (status == KMEMCHECK_SHADOW_INITIALIZED)
return;
if (kmemcheck_enabled)
kmemcheck_error_save(status, addr, size, regs);
if (kmemcheck_enabled == 2)
kmemcheck_enabled = 0;
kmemcheck_shadow_set(shadow, size);
}
bool kmemcheck_is_obj_initialized(unsigned long addr, size_t size)
{
enum kmemcheck_shadow status;
void *shadow;
shadow = kmemcheck_shadow_lookup(addr);
if (!shadow)
return true;
status = kmemcheck_shadow_test_all(shadow, size);
return status == KMEMCHECK_SHADOW_INITIALIZED;
}
static void kmemcheck_read(struct pt_regs *regs,
unsigned long addr, unsigned int size)
{
unsigned long page = addr & PAGE_MASK;
unsigned long next_addr = addr + size - 1;
unsigned long next_page = next_addr & PAGE_MASK;
if (likely(page == next_page)) {
kmemcheck_read_strict(regs, addr, size);
return;
}
kmemcheck_read_strict(regs, addr, next_page - addr);
kmemcheck_read_strict(regs, next_page, next_addr - next_page);
}
static void kmemcheck_write_strict(struct pt_regs *regs,
unsigned long addr, unsigned int size)
{
void *shadow;
shadow = kmemcheck_shadow_lookup(addr);
if (!shadow)
return;
kmemcheck_save_addr(addr);
kmemcheck_shadow_set(shadow, size);
}
static void kmemcheck_write(struct pt_regs *regs,
unsigned long addr, unsigned int size)
{
unsigned long page = addr & PAGE_MASK;
unsigned long next_addr = addr + size - 1;
unsigned long next_page = next_addr & PAGE_MASK;
if (likely(page == next_page)) {
kmemcheck_write_strict(regs, addr, size);
return;
}
kmemcheck_write_strict(regs, addr, next_page - addr);
kmemcheck_write_strict(regs, next_page, next_addr - next_page);
}
static void kmemcheck_copy(struct pt_regs *regs,
unsigned long src_addr, unsigned long dst_addr, unsigned int size)
{
uint8_t shadow[8];
enum kmemcheck_shadow status;
unsigned long page;
unsigned long next_addr;
unsigned long next_page;
uint8_t *x;
unsigned int i;
unsigned int n;
BUG_ON(size > sizeof(shadow));
page = src_addr & PAGE_MASK;
next_addr = src_addr + size - 1;
next_page = next_addr & PAGE_MASK;
if (likely(page == next_page)) {
x = kmemcheck_shadow_lookup(src_addr);
if (x) {
kmemcheck_save_addr(src_addr);
for (i = 0; i < size; ++i)
shadow[i] = x[i];
} else {
for (i = 0; i < size; ++i)
shadow[i] = KMEMCHECK_SHADOW_INITIALIZED;
}
} else {
n = next_page - src_addr;
BUG_ON(n > sizeof(shadow));
x = kmemcheck_shadow_lookup(src_addr);
if (x) {
kmemcheck_save_addr(src_addr);
for (i = 0; i < n; ++i)
shadow[i] = x[i];
} else {
for (i = 0; i < n; ++i)
shadow[i] = KMEMCHECK_SHADOW_INITIALIZED;
}
x = kmemcheck_shadow_lookup(next_page);
if (x) {
kmemcheck_save_addr(next_page);
for (i = n; i < size; ++i)
shadow[i] = x[i - n];
} else {
for (i = n; i < size; ++i)
shadow[i] = KMEMCHECK_SHADOW_INITIALIZED;
}
}
page = dst_addr & PAGE_MASK;
next_addr = dst_addr + size - 1;
next_page = next_addr & PAGE_MASK;
if (likely(page == next_page)) {
x = kmemcheck_shadow_lookup(dst_addr);
if (x) {
kmemcheck_save_addr(dst_addr);
for (i = 0; i < size; ++i) {
x[i] = shadow[i];
shadow[i] = KMEMCHECK_SHADOW_INITIALIZED;
}
}
} else {
n = next_page - dst_addr;
BUG_ON(n > sizeof(shadow));
x = kmemcheck_shadow_lookup(dst_addr);
if (x) {
kmemcheck_save_addr(dst_addr);
for (i = 0; i < n; ++i) {
x[i] = shadow[i];
shadow[i] = KMEMCHECK_SHADOW_INITIALIZED;
}
}
x = kmemcheck_shadow_lookup(next_page);
if (x) {
kmemcheck_save_addr(next_page);
for (i = n; i < size; ++i) {
x[i - n] = shadow[i];
shadow[i] = KMEMCHECK_SHADOW_INITIALIZED;
}
}
}
status = kmemcheck_shadow_test(shadow, size);
if (status == KMEMCHECK_SHADOW_INITIALIZED)
return;
if (kmemcheck_enabled)
kmemcheck_error_save(status, src_addr, size, regs);
if (kmemcheck_enabled == 2)
kmemcheck_enabled = 0;
}
static void kmemcheck_access(struct pt_regs *regs,
unsigned long fallback_address, enum kmemcheck_method fallback_method)
{
const uint8_t *insn;
const uint8_t *insn_primary;
unsigned int size;
struct kmemcheck_context *data = this_cpu_ptr(&kmemcheck_context);
if (data->busy) {
kmemcheck_show_addr(fallback_address);
kmemcheck_error_save_bug(regs);
return;
}
data->busy = true;
insn = (const uint8_t *) regs->ip;
insn_primary = kmemcheck_opcode_get_primary(insn);
kmemcheck_opcode_decode(insn, &size);
switch (insn_primary[0]) {
#ifdef CONFIG_KMEMCHECK_BITOPS_OK
case 0x80:
case 0x81:
case 0x82:
case 0x83:
switch ((insn_primary[1] >> 3) & 7) {
case 1:
case 4:
case 6:
kmemcheck_write(regs, fallback_address, size);
goto out;
case 0:
case 2:
case 3:
case 5:
case 7:
break;
}
break;
#endif
case 0xa4:
case 0xa5:
kmemcheck_copy(regs, regs->si, regs->di, size);
goto out;
case 0xa6:
case 0xa7:
kmemcheck_read(regs, regs->si, size);
kmemcheck_read(regs, regs->di, size);
goto out;
}
switch (fallback_method) {
case KMEMCHECK_READ:
kmemcheck_read(regs, fallback_address, size);
goto out;
case KMEMCHECK_WRITE:
kmemcheck_write(regs, fallback_address, size);
goto out;
}
out:
data->busy = false;
}
bool kmemcheck_fault(struct pt_regs *regs, unsigned long address,
unsigned long error_code)
{
pte_t *pte;
if (regs->flags & X86_VM_MASK)
return false;
if (regs->cs != __KERNEL_CS)
return false;
pte = kmemcheck_pte_lookup(address);
if (!pte)
return false;
WARN_ON_ONCE(in_nmi());
if (error_code & 2)
kmemcheck_access(regs, address, KMEMCHECK_WRITE);
else
kmemcheck_access(regs, address, KMEMCHECK_READ);
kmemcheck_show(regs);
return true;
}
bool kmemcheck_trap(struct pt_regs *regs)
{
if (!kmemcheck_active(regs))
return false;
kmemcheck_hide(regs);
return true;
}
