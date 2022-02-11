static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
T_2 V_9 ;
T_3 * V_10 ;
int V_11 ;
V_10 = F_3 ( V_6 -> V_12 , V_13 ) ;
if ( V_10 == NULL )
return - V_14 ;
V_11 = F_4 ( V_8 -> V_15 , V_10 ,
V_8 -> V_16 -> V_17 [ 0 ] . V_18 . V_19 / 8 ) ;
if ( V_11 < 0 )
goto V_20;
V_9 = F_5 () ;
if ( V_6 -> V_21 )
memcpy ( V_10 + V_6 -> V_12 - sizeof( T_2 ) ,
& V_9 , sizeof( V_9 ) ) ;
V_6 -> V_22 -> V_23 -> V_24 ( V_6 -> V_22 , V_10 , V_9 ) ;
V_20:
F_6 ( V_6 -> V_25 ) ;
F_7 ( V_10 ) ;
return V_26 ;
}
int F_8 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_6 ) ;
int V_27 = 0 ;
V_6 -> V_22 = F_9 ( V_6 ) ;
if ( ! V_6 -> V_22 ) {
V_27 = - V_14 ;
goto V_28;
}
V_6 -> V_29
= F_10 ( NULL ,
& F_1 ,
V_30 ,
V_6 ,
L_1 ,
F_11 ( V_8 -> V_15 ) -> V_31 ,
V_6 -> V_32 ) ;
if ( V_6 -> V_29 == NULL ) {
V_27 = - V_14 ;
goto V_33;
}
V_6 -> V_34 = & V_35 ;
V_6 -> V_22 -> V_21 = true ;
V_6 -> V_36 |= V_37 ;
return 0 ;
V_33:
F_12 ( V_6 -> V_22 ) ;
V_28:
return V_27 ;
}
void F_13 ( struct V_5 * V_6 )
{
F_14 ( V_6 -> V_29 ) ;
F_12 ( V_6 -> V_22 ) ;
}
