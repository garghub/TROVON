static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = 0 ;
T_2 * V_8 ;
V_8 = F_2 ( V_6 -> V_9 , V_10 ) ;
if ( V_8 == NULL )
goto V_11;
if ( ! F_3 ( V_6 -> V_12 , V_6 -> V_13 ) ) {
int V_14 , V_15 ;
for ( V_14 = 0 , V_15 = 0 ;
V_14 < F_4 ( V_6 -> V_12 ,
V_6 -> V_13 ) ;
V_14 ++ , V_15 ++ ) {
V_15 = F_5 ( V_6 -> V_12 ,
V_6 -> V_13 , V_15 ) ;
V_8 [ V_14 ] = V_16 [ V_15 ] ;
V_7 += 2 ;
}
}
if ( V_6 -> V_17 )
* ( V_18 * ) ( ( V_19 * ) V_8 + F_6 ( V_7 , sizeof( V_18 ) ) )
= F_7 () ;
F_8 ( V_6 , ( V_19 * ) V_8 ) ;
F_9 ( V_8 ) ;
V_11:
F_10 ( V_6 -> V_20 ) ;
return V_21 ;
}
int F_11 ( struct V_5 * V_6 ,
const struct V_22 * V_23 , unsigned int V_24 )
{
int V_25 ;
struct V_26 * V_27 ;
V_27 = F_12 ( V_6 ) ;
if ( V_27 == NULL ) {
V_25 = - V_28 ;
goto V_29;
}
V_6 -> V_27 = V_27 ;
V_27 -> V_17 = true ;
V_6 -> V_30 = & V_31 ;
V_6 -> V_32 = F_13 ( NULL ,
& F_1 ,
V_33 ,
V_6 ,
L_1 ,
V_6 -> V_34 ) ;
if ( V_6 -> V_32 == NULL ) {
V_25 = - V_28 ;
goto V_35;
}
V_6 -> V_36 |= V_37 ;
V_25 = F_14 ( V_6 , V_23 , V_24 ) ;
if ( V_25 )
goto V_38;
return 0 ;
V_38:
F_15 ( V_6 -> V_32 ) ;
V_35:
F_16 ( V_6 -> V_27 ) ;
V_29:
return V_25 ;
}
void F_17 ( struct V_5 * V_6 )
{
F_18 ( V_6 ) ;
F_15 ( V_6 -> V_32 ) ;
F_16 ( V_6 -> V_27 ) ;
}
