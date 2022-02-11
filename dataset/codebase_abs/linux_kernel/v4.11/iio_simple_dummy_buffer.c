static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = 0 ;
T_2 * V_8 ;
V_8 = F_2 ( V_6 -> V_9 , V_10 ) ;
if ( ! V_8 )
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
F_6 ( V_6 , V_8 ,
F_7 ( V_6 ) ) ;
F_8 ( V_8 ) ;
V_11:
F_9 ( V_6 -> V_17 ) ;
return V_18 ;
}
int F_10 ( struct V_5 * V_6 )
{
int V_19 ;
struct V_20 * V_21 ;
V_21 = F_11 () ;
if ( ! V_21 ) {
V_19 = - V_22 ;
goto V_23;
}
F_12 ( V_6 , V_21 ) ;
V_6 -> V_24 = & V_25 ;
V_6 -> V_26 = F_13 ( NULL ,
& F_1 ,
V_27 ,
V_6 ,
L_1 ,
V_6 -> V_28 ) ;
if ( ! V_6 -> V_26 ) {
V_19 = - V_22 ;
goto V_29;
}
V_6 -> V_30 |= V_31 ;
return 0 ;
V_29:
F_14 ( V_6 -> V_21 ) ;
V_23:
return V_19 ;
}
void F_15 ( struct V_5 * V_6 )
{
F_16 ( V_6 -> V_26 ) ;
F_14 ( V_6 -> V_21 ) ;
}
