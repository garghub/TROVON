static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 , V_6 ;
V_6 = V_7 << V_4 -> V_8 ;
V_5 = F_3 () ;
return ( ( V_5 & V_6 ) == V_6 ) ? true : false ;
}
int F_4 ( struct V_1 * V_2 )
{
return F_5 () ;
}
int F_6 ( struct V_1 * V_2 )
{
return F_7 () ;
}
static void F_8 ( struct V_3 * V_4 )
{
F_9 () ;
}
static void F_10 ( struct V_3 * V_4 )
{
F_11 () ;
}
static void F_12 ( struct V_3 * V_4 )
{
F_13 () ;
}
static void F_14 ( struct V_3 * V_4 )
{
F_15 () ;
}
void F_16 ( struct V_1 * V_2 )
{
F_17 () ;
}
void F_18 ( struct V_1 * V_2 )
{
F_19 () ;
}
unsigned long F_20 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
return ( F_1 ( V_2 ) ) ? 54000000 : 0 ;
}
unsigned long F_21 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
return ( F_1 ( V_2 ) ) ? 96000000 : 0 ;
}
T_1 F_22 ( void )
{
T_1 V_10 , V_11 = 0 ;
V_10 = F_23 () ;
V_10 &= V_12 ;
V_10 >>= V_13 ;
if ( V_10 == V_14 )
V_11 = 19200000 ;
else if ( V_10 == V_15 )
V_11 = 13000000 ;
else if ( V_10 == V_16 )
V_11 = 12000000 ;
return V_11 ;
}
