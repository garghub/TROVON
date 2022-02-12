static unsigned char readb_outer_space(unsigned long long phys)
{
unsigned long long vaddr = IO_BASE_64 | phys;
unsigned char res;
unsigned int sr;
sr = read_c0_status();
write_c0_status((sr | ST0_KX) & ~ ST0_IE);
ssnop_4();
__asm__ __volatile__ (
" .set mips3 \n"
" .set push \n"
" .set noreorder \n"
" .set nomacro \n"
" ld %0, %1 \n"
" .set pop \n"
" lbu %0, (%0) \n"
" .set mips0 \n"
: "=r" (res)
: "R" (vaddr));
write_c0_status(sr);
ssnop_4();
return res;
}
static void writeb_outer_space(unsigned long long phys, unsigned char c)
{
unsigned long long vaddr = IO_BASE_64 | phys;
unsigned long tmp;
unsigned int sr;
sr = read_c0_status();
write_c0_status((sr | ST0_KX) & ~ ST0_IE);
ssnop_4();
__asm__ __volatile__ (
" .set mips3 \n"
" .set push \n"
" .set noreorder \n"
" .set nomacro \n"
" ld %0, %1 \n"
" .set pop \n"
" sb %2, (%0) \n"
" .set mips0 \n"
: "=&r" (tmp)
: "R" (vaddr), "r" (c));
write_c0_status(sr);
ssnop_4();
}
void prom_putchar(char c)
{
unsigned long lsr = 0xfd000008ULL + offsetof(struct yo_uartregs, iu_lsr);
unsigned long thr = 0xfd000008ULL + offsetof(struct yo_uartregs, iu_thr);
while ((readb_outer_space(lsr) & 0x20) == 0);
writeb_outer_space(thr, c);
}
