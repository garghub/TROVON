static void F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
static T_1 V_7 = V_8 ;
T_1 V_9 ;
if ( V_4 & V_10 ) {
V_9 = V_11 | V_8 ;
if ( V_4 & V_12 )
V_9 &= ~ V_11 ;
if ( V_4 & V_13 )
V_9 |= V_14 ;
if ( V_4 & V_15 )
V_9 |= V_16 ;
V_7 &= ~ ( V_11 |
V_14 |
V_16 ) ;
V_7 |= V_9 ;
F_3 ( V_7 , F_4 ( V_6 ) ) ;
}
if ( V_3 != V_17 )
F_3 ( ( V_3 & 0xff ) | V_7 , V_6 -> V_18 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return ! ! ( F_6 ( F_4 ( V_6 ) ) & V_19 ) ;
}
static void T_2 F_7 ( void )
{
F_8 () ;
F_9 ( & V_20 ) ;
}
static void T_2 F_10 ( void )
{
F_11 () ;
F_12 ( & V_21 , 1 ) ;
F_13 ( & V_22 , V_23 ,
F_14 ( V_23 ) ) ;
F_15 ( & V_24 ) ;
F_7 () ;
F_9 ( & V_25 ) ;
}
