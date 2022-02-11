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
if ( ! F_3 ( V_6 -> V_16 , V_6 -> V_17 ) ) {
int V_18 , V_19 ;
for ( V_18 = 0 , V_19 = 0 ;
V_18 < F_4 ( V_6 -> V_16 ,
V_6 -> V_17 ) ;
V_18 ++ ) {
V_19 = F_5 ( V_8 -> V_20 ,
V_6 -> V_17 , V_19 + 1 ) ;
V_13 [ V_18 ] = V_21 [ V_19 ] ;
V_9 += 2 ;
}
}
if ( V_8 -> V_22 )
* ( V_23 * ) ( ( ( V_24 ) V_13 + V_9
+ sizeof( V_23 ) - 1 ) & ~ ( sizeof( V_23 ) - 1 ) )
= F_6 () ;
V_8 -> V_11 -> V_25 ( V_8 , ( V_26 * ) V_13 , V_4 -> V_27 ) ;
F_7 ( V_13 ) ;
F_8 ( V_6 -> V_28 ) ;
return V_29 ;
}
int F_9 ( struct V_5 * V_6 )
{
int V_30 ;
struct V_7 * V_8 ;
V_8 = F_10 ( V_6 ) ;
if ( V_8 == NULL ) {
V_30 = - V_15 ;
goto V_31;
}
V_6 -> V_8 = V_8 ;
V_8 -> V_22 = true ;
V_6 -> V_32 = & V_33 ;
V_6 -> V_34 = F_11 ( NULL ,
& F_1 ,
V_35 ,
V_6 ,
L_1 ,
V_6 -> V_36 ) ;
if ( V_6 -> V_34 == NULL ) {
V_30 = - V_15 ;
goto V_37;
}
V_6 -> V_38 |= V_39 ;
return 0 ;
V_37:
F_12 ( V_6 -> V_8 ) ;
V_31:
return V_30 ;
}
void F_13 ( struct V_5 * V_6 )
{
F_14 ( V_6 -> V_34 ) ;
F_12 ( V_6 -> V_8 ) ;
}
