static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = V_4 ;
if ( V_3 != V_7 )
return V_8 ;
if ( ! V_6 )
return V_9 ;
if ( ! V_6 -> V_10 ) {
V_6 -> V_11 = V_12 ;
F_2 ( V_6 , L_1 ,
V_6 -> V_11 ) ;
}
return V_13 ;
}
static void T_1 F_3 ( void )
{
F_4 () ;
if ( V_14 . V_15 )
F_5 ( & V_16 , & V_14 ) ;
F_6 ( NULL , V_17 , NULL , NULL ) ;
}
static T_2 F_7 ( unsigned long V_18 )
{
return ( T_2 ) ( V_18 ) - V_19 + V_20 ;
}
static void T_1 F_8 ( void )
{
bool V_21 = F_9 ( V_22 ) ;
bool V_23 = F_9 ( V_24 ) ;
T_2 V_25 = V_26 - V_20 ;
T_2 V_27 , V_28 ;
V_27 = F_10 () ;
V_28 = F_11 () ;
if ( V_27 >= V_20 &&
V_28 <= V_29 )
return;
if ( ! V_21 || ! V_23 ) {
F_12 ( L_2 ,
! V_21 ? F_13 ( V_22 ) : L_3 ,
( ! V_21 && ! V_23 ) ? L_4 : L_3 ,
! V_23 ? F_13 ( V_24 ) : L_3 ) ;
}
if ( V_27 < V_30 ||
V_28 > V_31 ) {
F_12 ( L_5 ,
( V_32 ) V_27 , ( V_32 ) V_28 ) ;
}
V_25 += V_30 ;
V_33 = F_14 ( V_25 ) ;
V_34 = ( V_25 - V_35 ) ;
V_36 = F_7 ;
V_14 . V_15 = F_1 ;
V_12 = F_14 ( V_30 -
V_20 ) ;
F_15 ( L_6 , ( V_32 ) V_25 ) ;
}
