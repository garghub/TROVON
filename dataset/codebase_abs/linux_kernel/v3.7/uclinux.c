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
if ( ! V_11 -> V_13 )
V_11 -> V_13 = F_3 ( F_4 ( * ( ( unsigned long * ) ( V_11 -> V_7 + 8 ) ) ) ) ;
V_11 -> V_14 = 4 ;
F_5 ( L_1 ,
( int ) V_11 -> V_7 , ( int ) V_11 -> V_13 ) ;
V_11 -> V_6 = F_6 ( V_11 -> V_7 ) ;
if ( V_11 -> V_6 == 0 ) {
F_5 ( L_2 ) ;
return ( - V_15 ) ;
}
F_7 ( V_11 ) ;
V_2 = F_8 ( L_3 , V_11 ) ;
if ( ! V_2 ) {
F_5 ( L_4 ) ;
return ( - V_16 ) ;
}
V_2 -> V_17 = V_18 ;
V_2 -> V_19 = F_1 ;
V_2 -> V_10 = V_11 ;
V_20 = V_2 ;
F_9 ( V_2 , V_21 , V_22 ) ;
return ( 0 ) ;
}
static void T_5 F_10 ( void )
{
if ( V_20 ) {
F_11 ( V_20 ) ;
F_12 ( V_20 ) ;
V_20 = NULL ;
}
if ( V_12 . V_6 )
V_12 . V_6 = 0 ;
}
