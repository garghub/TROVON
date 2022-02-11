static void T_1 * F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_4 )
{
if ( V_2 -> V_5 != 0 || ( V_3 >> 3 ) != 0 )
return NULL ;
return ( void T_1 * ) V_6 +
( ( V_2 -> V_5 << 16 ) | ( V_3 << 8 ) | ( V_4 & ~ 3 ) ) ;
}
static int T_2 F_2 ( const struct V_7 * V_8 , T_3 V_9 ,
T_3 V_10 )
{
return V_11 ;
}
static int T_2 F_3 ( struct V_12 * V_13 )
{
if ( F_4 ( & V_14 , & V_15 ) ) {
F_5 ( V_16 L_1 ) ;
return - V_17 ;
}
if ( F_4 ( & V_18 , & V_19 ) ) {
F_6 ( & V_15 ) ;
F_5 ( V_16 L_2 ) ;
return - V_17 ;
}
if ( F_4 ( & V_18 , & V_20 ) ) {
F_6 ( & V_15 ) ;
F_6 ( & V_19 ) ;
F_5 ( V_16 L_3 ) ;
return - V_17 ;
}
F_7 ( & V_13 -> V_21 , & V_15 , V_13 -> V_22 ) ;
F_7 ( & V_13 -> V_21 ,
& V_19 , V_13 -> V_23 ) ;
F_7 ( & V_13 -> V_21 ,
& V_20 , V_13 -> V_23 ) ;
return 1 ;
}
int T_2 F_8 ( int V_24 , struct V_12 * V_13 )
{
int V_25 = 0 ;
V_26 = 0 ;
V_27 = 0 ;
if ( V_24 == 0 ) {
V_13 -> V_23 = V_28 ;
V_13 -> V_22 = 0x400 ;
V_25 = F_3 ( V_13 ) ;
V_29 = ( V_29 & ~ V_30 ) | V_31 ;
V_32 |= V_31 | V_30 ;
V_33 |= V_34 ;
}
return V_25 ;
}
static int T_2 F_9 ( void )
{
if ( F_10 () )
F_11 ( & V_35 ) ;
return 0 ;
}
