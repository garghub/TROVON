static void F_1 ( int V_1 )
{
}
static void F_2 ( int V_1 )
{
}
static void F_3 ( int V_1 )
{
T_1 V_2 ;
V_2 = ( F_4 ( V_3 ) & ~ ( V_4 | V_5 ) ) | V_6 ;
F_5 ( V_3 , V_2 ) ;
V_2 = F_6 () ;
V_2 |= V_7 ;
asm volatile(
"msync\n"
"mtmsr %0\n"
"isync\n"
:
: "r" (tmp));
}
static void F_7 ( int V_1 )
{
}
static void F_8 ( bool V_8 )
{
T_2 V_9 ;
V_9 = V_10 | V_11 ;
if ( V_8 )
F_9 ( & V_12 -> V_13 , V_9 ) ;
else
F_10 ( & V_12 -> V_13 , V_9 ) ;
F_11 ( & V_12 -> V_13 ) ;
}
int T_3 F_12 ( void )
{
struct V_14 * V_15 ;
V_15 = F_13 ( NULL , V_16 ) ;
if ( V_15 ) {
V_12 = F_14 ( V_15 , 0 ) ;
F_15 ( V_15 ) ;
if ( ! V_12 ) {
F_16 ( L_1 ) ;
return - V_17 ;
}
}
V_18 = & V_19 ;
return 0 ;
}
