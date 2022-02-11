static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
T_1 V_4 = V_3 ;
if ( V_4 >= V_5 )
return - V_6 ;
F_2 ( & V_7 ) ;
F_3 ( F_4 ( V_8 +
( V_4 / 32 ) * 4 ) | ( 1 << V_4 ) ,
V_8 + ( V_4 / 32 ) * 4 ) ;
F_5 ( 20 ) ;
F_3 ( F_4 ( V_8 +
( V_4 / 32 ) * 4 ) & ~ ( 1 << V_4 ) ,
V_8 + ( V_4 / 32 ) * 4 ) ;
F_6 ( & V_7 ) ;
return 0 ;
}
static void F_7 ( enum V_9 V_10 , const char * V_11 )
{
F_3 ( V_12 , V_8 ) ;
}
static int F_8 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 . V_18 ;
V_8 = F_9 ( V_16 , 0 ) ;
if ( ! V_8 ) {
F_10 ( & V_14 -> V_17 , L_1 ) ;
return - V_19 ;
}
V_20 . V_18 = V_16 ;
V_21 = F_7 ;
if ( F_11 ( V_22 ) )
F_12 ( & V_20 ) ;
return 0 ;
}
static int T_2 F_13 ( void )
{
return F_14 ( & V_23 ) ;
}
