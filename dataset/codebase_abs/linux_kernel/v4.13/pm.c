static void F_1 ( void )
{
if ( V_1 . V_2 . V_3 ) {
asm volatile("lcallw *%0"
: : "m" (boot_params.hdr.realmode_swtch)
: "eax", "ebx", "ecx", "edx");
} else {
asm volatile("cli");
F_2 ( 0x80 , 0x70 ) ;
F_3 () ;
}
}
static void F_4 ( void )
{
F_2 ( 0xff , 0xa1 ) ;
F_3 () ;
F_2 ( 0xfb , 0x21 ) ;
F_3 () ;
}
static void F_5 ( void )
{
F_2 ( 0 , 0xf0 ) ;
F_3 () ;
F_2 ( 0 , 0xf1 ) ;
F_3 () ;
}
static void F_6 ( void )
{
static const T_1 V_4 [] V_5 ( ( F_7 ( 16 ) ) ) = {
[ V_6 ] = F_8 ( 0xc09b , 0 , 0xfffff ) ,
[ V_7 ] = F_8 ( 0xc093 , 0 , 0xfffff ) ,
[ V_8 ] = F_8 ( 0x0089 , 4096 , 103 ) ,
} ;
static struct V_9 V_10 ;
V_10 . V_11 = sizeof( V_4 ) - 1 ;
V_10 . V_12 = ( V_13 ) & V_4 + ( F_9 () << 4 ) ;
asm volatile("lgdtl %0" : : "m" (gdt));
}
static void F_10 ( void )
{
static const struct V_9 V_14 = { 0 , 0 } ;
asm volatile("lidtl %0" : : "m" (null_idt));
}
void F_11 ( void )
{
F_1 () ;
if ( F_12 () ) {
puts ( L_1 ) ;
F_13 () ;
}
F_5 () ;
F_4 () ;
F_10 () ;
F_6 () ;
F_14 ( V_1 . V_2 . V_15 ,
( V_13 ) & V_1 + ( F_9 () << 4 ) ) ;
}
