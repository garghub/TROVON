static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
T_1 V_4 = V_3 ;
if ( V_4 >= V_5 )
return - V_6 ;
F_2 ( & V_7 ) ;
if ( F_3 ( V_2 -> V_8 , L_1 ) ) {
F_4 ( F_5 ( V_9 +
( V_4 / 32 ) * 4 ) | ( 1 << V_4 ) ,
V_9 + ( V_4 / 32 ) * 4 ) ;
F_6 ( 20 ) ;
F_4 ( F_5 ( V_9 +
( V_4 / 32 ) * 4 ) & ~ ( 1 << V_4 ) ,
V_9 + ( V_4 / 32 ) * 4 ) ;
} else {
F_4 ( 1 << V_4 ,
V_9 + ( V_4 / 32 ) * 8 ) ;
F_6 ( 20 ) ;
F_4 ( 1 << V_4 ,
V_9 + ( V_4 / 32 ) * 8 + 4 ) ;
}
F_7 ( & V_7 ) ;
return 0 ;
}
static void F_8 ( enum V_10 V_11 , const char * V_12 )
{
F_4 ( V_13 , V_9 ) ;
}
static int F_9 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 . V_8 ;
V_9 = F_10 ( V_17 , 0 ) ;
if ( ! V_9 ) {
F_11 ( & V_15 -> V_18 , L_2 ) ;
return - V_19 ;
}
V_20 . V_8 = V_17 ;
V_21 = F_8 ;
if ( F_12 ( V_22 ) )
F_13 ( & V_20 ) ;
return 0 ;
}
static int T_2 F_14 ( void )
{
return F_15 ( & V_23 ) ;
}
