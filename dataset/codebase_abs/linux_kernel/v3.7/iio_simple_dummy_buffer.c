static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 = 0 ;
T_2 * V_10 ;
V_10 = F_2 ( V_6 -> V_11 , V_12 ) ;
if ( V_10 == NULL )
goto V_13;
if ( ! F_3 ( V_6 -> V_14 , V_6 -> V_15 ) ) {
int V_16 , V_17 ;
for ( V_16 = 0 , V_17 = 0 ;
V_16 < F_4 ( V_6 -> V_14 ,
V_6 -> V_15 ) ;
V_16 ++ , V_17 ++ ) {
V_17 = F_5 ( V_8 -> V_18 ,
V_6 -> V_15 , V_17 ) ;
V_10 [ V_16 ] = V_19 [ V_17 ] ;
V_9 += 2 ;
}
}
if ( V_6 -> V_20 )
* ( V_21 * ) ( ( V_22 * ) V_10 + F_6 ( V_9 , sizeof( V_21 ) ) )
= F_7 () ;
F_8 ( V_8 , ( V_22 * ) V_10 ) ;
F_9 ( V_10 ) ;
V_13:
F_10 ( V_6 -> V_23 ) ;
return V_24 ;
}
int F_11 ( struct V_5 * V_6 ,
const struct V_25 * V_26 , unsigned int V_27 )
{
int V_28 ;
struct V_7 * V_8 ;
V_8 = F_12 ( V_6 ) ;
if ( V_8 == NULL ) {
V_28 = - V_29 ;
goto V_30;
}
V_6 -> V_8 = V_8 ;
V_8 -> V_20 = true ;
V_6 -> V_31 = & V_32 ;
V_6 -> V_33 = F_13 ( NULL ,
& F_1 ,
V_34 ,
V_6 ,
L_1 ,
V_6 -> V_35 ) ;
if ( V_6 -> V_33 == NULL ) {
V_28 = - V_29 ;
goto V_36;
}
V_6 -> V_37 |= V_38 ;
V_28 = F_14 ( V_6 , V_26 , V_27 ) ;
if ( V_28 )
goto V_39;
return 0 ;
V_39:
F_15 ( V_6 -> V_33 ) ;
V_36:
F_16 ( V_6 -> V_8 ) ;
V_30:
return V_28 ;
}
void F_17 ( struct V_5 * V_6 )
{
F_18 ( V_6 ) ;
F_15 ( V_6 -> V_33 ) ;
F_16 ( V_6 -> V_8 ) ;
}
