static unsigned char F_1 ( unsigned long long V_1 )
{
unsigned long long V_2 = V_3 | V_1 ;
unsigned char V_4 ;
unsigned int V_5 ;
V_5 = F_2 () ;
F_3 ( ( V_5 | V_6 ) & ~ V_7 ) ;
F_4 () ;
__asm__ __volatile__ (
" .set mips3 \n"
" ld %0, %1 \n"
" lbu %0, (%0) \n"
" .set mips0 \n"
: "=r" (res)
: "m" (vaddr));
F_3 ( V_5 ) ;
F_4 () ;
return V_4 ;
}
static void F_5 ( unsigned long long V_1 , unsigned char V_8 )
{
unsigned long long V_2 = V_3 | V_1 ;
unsigned long V_9 ;
unsigned int V_5 ;
V_5 = F_2 () ;
F_3 ( ( V_5 | V_6 ) & ~ V_7 ) ;
F_4 () ;
__asm__ __volatile__ (
" .set mips3 \n"
" ld %0, %1 \n"
" sb %2, (%0) \n"
" .set mips0 \n"
: "=&r" (tmp)
: "m" (vaddr), "r" (c));
F_3 ( V_5 ) ;
F_4 () ;
}
void F_6 ( char V_8 )
{
unsigned long V_10 = 0xfd000008ULL + F_7 ( struct V_11 , V_12 ) ;
unsigned long V_13 = 0xfd000008ULL + F_7 ( struct V_11 , V_14 ) ;
while ( ( F_1 ( V_10 ) & 0x20 ) == 0 ) ;
F_5 ( V_13 , V_8 ) ;
}
