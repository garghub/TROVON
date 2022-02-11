static void F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
static T_1 V_8 = V_9 ;
T_1 V_10 ;
if ( V_4 & V_11 ) {
V_10 = V_12 | V_9 ;
if ( V_4 & V_13 )
V_10 &= ~ V_12 ;
if ( V_4 & V_14 )
V_10 |= V_15 ;
if ( V_4 & V_16 )
V_10 |= V_17 ;
V_8 &= ~ ( V_12 |
V_15 |
V_17 ) ;
V_8 |= V_10 ;
F_2 ( V_8 , F_3 ( V_6 ) ) ;
}
if ( V_3 != V_18 )
F_2 ( ( V_3 & 0xff ) | V_8 , V_6 -> V_19 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
return ! ! ( F_5 ( F_3 ( V_6 ) ) & V_20 ) ;
}
static void T_2 F_6 ( void )
{
F_7 () ;
F_8 ( & V_21 , 1 ) ;
F_9 ( & V_22 , V_23 ,
F_10 ( V_23 ) ) ;
F_11 ( & V_24 ) ;
F_12 () ;
F_13 ( & V_25 ) ;
}
