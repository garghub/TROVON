static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
unsigned long V_7 ;
if ( V_6 == V_8 )
V_7 = V_4 -> V_9 [ 0 ] ;
else
V_7 = V_4 -> V_10 [ 0 ] ;
V_7 &= ~ V_11 ;
V_7 |= V_12 ;
F_2 ( V_7 , V_2 -> V_13 + V_14 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 , V_2 -> V_15 ) ;
}
static int T_1 F_4 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
F_5 () ;
return F_6 ( & V_20 ) ;
}
static int T_1 F_7 ( void )
{
return F_8 ( & V_21 ) ;
}
