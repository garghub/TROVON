static u64
get_imm64 (u64 insn_addr)
{
u64 *p = (u64 *) (insn_addr & -16);
return ( (p[1] & 0x0800000000000000UL) << 4) |
((p[1] & 0x00000000007fffffUL) << 40) |
((p[0] & 0xffffc00000000000UL) >> 24) |
((p[1] & 0x0000100000000000UL) >> 23) |
((p[1] & 0x0003e00000000000UL) >> 29) |
((p[1] & 0x07fc000000000000UL) >> 43) |
((p[1] & 0x000007f000000000UL) >> 36);
}
void
ia64_patch (u64 insn_addr, u64 mask, u64 val)
{
u64 m0, m1, v0, v1, b0, b1, *b = (u64 *) (insn_addr & -16);
# define insn_mask ((1UL << 41) - 1)
unsigned long shift;
b0 = b[0]; b1 = b[1];
shift = 5 + 41 * (insn_addr % 16);
if (shift >= 64) {
m1 = mask << (shift - 64);
v1 = val << (shift - 64);
} else {
m0 = mask << shift; m1 = mask >> (64 - shift);
v0 = val << shift; v1 = val >> (64 - shift);
b[0] = (b0 & ~m0) | (v0 & m0);
}
b[1] = (b1 & ~m1) | (v1 & m1);
}
void
ia64_patch_imm64 (u64 insn_addr, u64 val)
{
insn_addr &= -16UL;
ia64_patch(insn_addr + 2,
0x01fffefe000UL, ( ((val & 0x8000000000000000UL) >> 27)
| ((val & 0x0000000000200000UL) << 0)
| ((val & 0x00000000001f0000UL) << 6)
| ((val & 0x000000000000ff80UL) << 20)
| ((val & 0x000000000000007fUL) << 13) ));
ia64_patch(insn_addr + 1, 0x1ffffffffffUL, val >> 22);
}
void
ia64_patch_imm60 (u64 insn_addr, u64 val)
{
insn_addr &= -16UL;
ia64_patch(insn_addr + 2,
0x011ffffe000UL, ( ((val & 0x0800000000000000UL) >> 23)
| ((val & 0x00000000000fffffUL) << 13) ));
ia64_patch(insn_addr + 1, 0x1fffffffffcUL, val >> 18);
}
void __init
ia64_patch_vtop (unsigned long start, unsigned long end)
{
s32 *offp = (s32 *) start;
u64 ip;
while (offp < (s32 *) end) {
ip = (u64) offp + *offp;
ia64_patch_imm64(ip, ia64_tpa(get_imm64(ip)));
ia64_fc((void *) ip);
++offp;
}
ia64_sync_i();
ia64_srlz_i();
}
void __init
ia64_patch_rse (unsigned long start, unsigned long end)
{
s32 *offp = (s32 *) start;
u64 ip, *b;
while (offp < (s32 *) end) {
ip = (u64) offp + *offp;
b = (u64 *)(ip & -16);
b[1] &= ~0xf800000L;
ia64_fc((void *) ip);
++offp;
}
ia64_sync_i();
ia64_srlz_i();
}
void __init
ia64_patch_mckinley_e9 (unsigned long start, unsigned long end)
{
static int first_time = 1;
int need_workaround;
s32 *offp = (s32 *) start;
u64 *wp;
need_workaround = (local_cpu_data->family == 0x1f && local_cpu_data->model == 0);
if (first_time) {
first_time = 0;
if (need_workaround)
printk(KERN_INFO "Leaving McKinley Errata 9 workaround enabled\n");
}
if (need_workaround)
return;
while (offp < (s32 *) end) {
wp = (u64 *) ia64_imva((char *) offp + *offp);
wp[0] = 0x0000000100000011UL;
wp[1] = 0x0084006880000200UL;
wp[2] = 0x0000000100000000UL;
wp[3] = 0x0004000000000200UL;
ia64_fc(wp); ia64_fc(wp + 2);
++offp;
}
ia64_sync_i();
ia64_srlz_i();
}
static void __init
patch_fsyscall_table (unsigned long start, unsigned long end)
{
extern unsigned long fsyscall_table[NR_syscalls];
s32 *offp = (s32 *) start;
u64 ip;
while (offp < (s32 *) end) {
ip = (u64) ia64_imva((char *) offp + *offp);
ia64_patch_imm64(ip, (u64) fsyscall_table);
ia64_fc((void *) ip);
++offp;
}
ia64_sync_i();
ia64_srlz_i();
}
static void __init
patch_brl_fsys_bubble_down (unsigned long start, unsigned long end)
{
extern char fsys_bubble_down[];
s32 *offp = (s32 *) start;
u64 ip;
while (offp < (s32 *) end) {
ip = (u64) offp + *offp;
ia64_patch_imm60((u64) ia64_imva((void *) ip),
(u64) (fsys_bubble_down - (ip & -16)) / 16);
ia64_fc((void *) ip);
++offp;
}
ia64_sync_i();
ia64_srlz_i();
}
void __init
ia64_patch_gate (void)
{
# define START(name) ((unsigned long) __start_gate_##name##_patchlist)
# define END(name) ((unsigned long)__end_gate_##name##_patchlist)
patch_fsyscall_table(START(fsyscall), END(fsyscall));
patch_brl_fsys_bubble_down(START(brl_fsys_bubble_down), END(brl_fsys_bubble_down));
ia64_patch_vtop(START(vtop), END(vtop));
ia64_patch_mckinley_e9(START(mckinley_e9), END(mckinley_e9));
}
void ia64_patch_phys_stack_reg(unsigned long val)
{
s32 * offp = (s32 *) __start___phys_stack_reg_patchlist;
s32 * end = (s32 *) __end___phys_stack_reg_patchlist;
u64 ip, mask, imm;
mask = (0x3fUL << 27) | (0x7f << 13);
imm = (((val >> 7) & 0x3f) << 27) | (val & 0x7f) << 13;
while (offp < end) {
ip = (u64) offp + *offp;
ia64_patch(ip, mask, imm);
ia64_fc((void *)ip);
++offp;
}
ia64_sync_i();
ia64_srlz_i();
}
