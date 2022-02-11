static T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 () ;
}
static T_2 T_3 F_3 ( void )
{
return F_2 () ;
}
static inline unsigned int F_4 ( void )
{
unsigned int V_3 ;
__asm__ __volatile__(
" .set push\n"
" .set mips32r2\n"
" rdhwr %0, $2\n"
" .set pop\n"
: "=r" (count));
return V_3 ;
}
static bool F_5 ( void )
{
unsigned int V_4 , V_5 , V_6 ;
for ( V_6 = 0 , V_4 = F_4 () ; V_6 < 100 ; V_6 ++ ) {
V_5 = F_4 () ;
if ( V_5 != V_4 )
return true ;
V_4 = V_5 ;
}
F_6 ( L_1 ) ;
return false ;
}
int T_4 F_7 ( void )
{
if ( ! V_7 || ! V_8 )
return - V_9 ;
V_10 . V_11 = 200 + V_8 / 10000000 ;
if ( V_12 && F_5 () )
V_10 . V_13 . V_14 = V_15 ;
F_8 ( & V_10 , V_8 ) ;
F_9 ( F_3 , 32 , V_8 ) ;
return 0 ;
}
