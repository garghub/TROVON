static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 = 0 ;
T_2 V_10 = V_8 -> V_11 -> V_12 ( V_8 ) ;
T_3 * V_13 = F_2 ( V_10 , V_14 ) ;
if ( V_13 == NULL )
return - V_15 ;
if ( V_8 -> V_16 ) {
int V_17 , V_18 ;
for ( V_17 = 0 , V_18 = 0 ; V_17 < V_8 -> V_16 ; V_17 ++ ) {
V_18 = F_3 ( V_8 -> V_19 ,
V_6 -> V_20 , V_18 + 1 ) ;
V_13 [ V_17 ] = V_21 [ V_18 ] ;
V_9 += 2 ;
}
}
if ( V_8 -> V_22 )
* ( V_23 * ) ( ( ( V_24 ) V_13 + V_9
+ sizeof( V_23 ) - 1 ) & ~ ( sizeof( V_23 ) - 1 ) )
= F_4 () ;
V_8 -> V_11 -> V_25 ( V_8 , ( V_26 * ) V_13 , V_4 -> V_27 ) ;
F_5 ( V_13 ) ;
F_6 ( V_6 -> V_28 ) ;
return V_29 ;
}
int F_7 ( struct V_5 * V_6 )
{
int V_30 ;
struct V_7 * V_8 ;
V_8 = F_8 ( V_6 ) ;
if ( V_8 == NULL ) {
V_30 = - V_15 ;
goto V_31;
}
V_6 -> V_8 = V_8 ;
V_8 -> V_11 = & V_32 ;
V_8 -> V_33 = 2 ;
V_8 -> V_22 = true ;
V_8 -> V_34 = & V_35 ;
V_8 -> V_36 = V_37 ;
V_6 -> V_38 = F_9 ( NULL ,
& F_1 ,
V_39 ,
V_6 ,
L_1 ,
V_6 -> V_40 ) ;
if ( V_6 -> V_38 == NULL ) {
V_30 = - V_15 ;
goto V_41;
}
V_6 -> V_42 |= V_43 ;
return 0 ;
V_41:
F_10 ( V_6 -> V_8 ) ;
V_31:
return V_30 ;
}
void F_11 ( struct V_5 * V_6 )
{
F_12 ( V_6 -> V_38 ) ;
F_10 ( V_6 -> V_8 ) ;
}
