static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 * V_5 , void * * V_6 , T_3 * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
* V_6 = V_9 -> V_6 + V_3 ;
if ( V_7 )
* V_7 = V_9 -> V_7 + V_3 ;
* V_5 = V_4 ;
return ( 0 ) ;
}
static int T_4 F_2 ( void )
{
struct V_1 * V_2 ;
struct V_8 * V_11 ;
V_11 = & V_12 ;
if ( V_13 == - 1 )
V_11 -> V_7 = ( T_3 ) V_14 ;
else
V_11 -> V_7 = V_13 ;
if ( ! V_11 -> V_15 )
V_11 -> V_15 = F_3 ( F_4 ( * ( ( unsigned long * ) ( V_11 -> V_7 + 8 ) ) ) ) ;
V_11 -> V_16 = 4 ;
F_5 ( L_1 ,
( int ) V_11 -> V_7 , ( int ) V_11 -> V_15 ) ;
V_11 -> V_6 = F_6 ( V_11 -> V_7 ) ;
if ( V_11 -> V_6 == 0 ) {
F_5 ( L_2 ) ;
return ( - V_17 ) ;
}
F_7 ( V_11 ) ;
V_2 = F_8 ( L_3 V_18 , V_11 ) ;
if ( ! V_2 ) {
F_5 ( L_4 ) ;
return ( - V_19 ) ;
}
V_2 -> V_20 = V_21 ;
V_2 -> V_22 = F_1 ;
V_2 -> V_10 = V_11 ;
V_23 = V_2 ;
F_9 ( V_2 , V_24 , V_25 ) ;
return ( 0 ) ;
}
