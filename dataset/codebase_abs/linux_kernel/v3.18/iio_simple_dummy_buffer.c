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
F_6 ( V_6 , V_8 , F_7 () ) ;
F_8 ( V_8 ) ;
V_11:
F_9 ( V_6 -> V_17 ) ;
return V_18 ;
}
int F_10 ( struct V_5 * V_6 ,
const struct V_19 * V_20 , unsigned int V_21 )
{
int V_22 ;
struct V_23 * V_24 ;
V_24 = F_11 ( V_6 ) ;
if ( V_24 == NULL ) {
V_22 = - V_25 ;
goto V_26;
}
F_12 ( V_6 , V_24 ) ;
V_24 -> V_27 = true ;
V_6 -> V_28 = & V_29 ;
V_6 -> V_30 = F_13 ( NULL ,
& F_1 ,
V_31 ,
V_6 ,
L_1 ,
V_6 -> V_32 ) ;
if ( V_6 -> V_30 == NULL ) {
V_22 = - V_25 ;
goto V_33;
}
V_6 -> V_34 |= V_35 ;
V_22 = F_14 ( V_6 , V_20 , V_21 ) ;
if ( V_22 )
goto V_36;
return 0 ;
V_36:
F_15 ( V_6 -> V_30 ) ;
V_33:
F_16 ( V_6 -> V_24 ) ;
V_26:
return V_22 ;
}
void F_17 ( struct V_5 * V_6 )
{
F_18 ( V_6 ) ;
F_15 ( V_6 -> V_30 ) ;
F_16 ( V_6 -> V_24 ) ;
}
