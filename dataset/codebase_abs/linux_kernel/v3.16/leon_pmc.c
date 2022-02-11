static int F_1 ( void )
{
unsigned int V_1 = V_2 >> 16 ;
unsigned int * V_3 ;
V_3 = & V_4 [ 0 ] ;
while ( * V_3 != 0 ) {
if ( * V_3 == V_1 )
return 1 ;
V_3 ++ ;
}
return 0 ;
}
static void F_2 ( void )
{
register unsigned int V_5 = ( unsigned int ) V_6 ;
F_3 () ;
__asm__ __volatile__ (
"wr %%g0, %%asr19\n"
"lda [%0] %1, %%g0\n"
:
: "r"(address), "i"(ASI_LEON_BYPASS));
}
static void F_4 ( void )
{
F_3 () ;
__asm__ __volatile__ ("wr %g0, %asr19\n\t");
}
static int T_1 F_5 ( void )
{
if ( V_7 == V_8 ) {
if ( F_1 () )
V_9 = F_2 ;
else
V_9 = F_4 ;
F_6 ( V_10 L_1 ) ;
}
return 0 ;
}
