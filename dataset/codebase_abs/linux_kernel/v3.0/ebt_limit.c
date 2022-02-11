static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = ( void * ) V_4 -> V_7 ;
unsigned long V_8 = V_9 ;
F_2 ( & V_10 ) ;
V_6 -> V_11 += ( V_8 - F_3 ( & V_6 -> V_12 , V_8 ) ) * V_13 ;
if ( V_6 -> V_11 > V_6 -> V_14 )
V_6 -> V_11 = V_6 -> V_14 ;
if ( V_6 -> V_11 >= V_6 -> V_15 ) {
V_6 -> V_11 -= V_6 -> V_15 ;
F_4 ( & V_10 ) ;
return true ;
}
F_4 ( & V_10 ) ;
return false ;
}
static T_1
F_5 ( T_1 V_16 )
{
if ( V_16 > 0xFFFFFFFF / ( V_17 * V_13 ) )
return ( V_16 / V_18 ) * V_17 * V_13 ;
return ( V_16 * V_17 * V_13 ) / V_18 ;
}
static int F_6 ( const struct V_19 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_20 == 0 ||
F_5 ( V_6 -> V_21 * V_6 -> V_20 ) < F_5 ( V_6 -> V_21 ) ) {
F_7 ( L_1 ,
V_6 -> V_21 , V_6 -> V_20 ) ;
return - V_22 ;
}
V_6 -> V_12 = V_9 ;
V_6 -> V_11 = F_5 ( V_6 -> V_21 * V_6 -> V_20 ) ;
V_6 -> V_14 = F_5 ( V_6 -> V_21 * V_6 -> V_20 ) ;
V_6 -> V_15 = F_5 ( V_6 -> V_21 ) ;
return 0 ;
}
static int T_2 F_8 ( void )
{
return F_9 ( & V_23 ) ;
}
static void T_3 F_10 ( void )
{
F_11 ( & V_23 ) ;
}
