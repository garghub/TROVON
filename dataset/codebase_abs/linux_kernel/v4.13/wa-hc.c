int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 )
{
int V_6 ;
struct V_7 * V_8 = & V_4 -> V_8 ;
if ( V_4 -> V_9 -> V_10 . V_11 < 3 )
return - V_12 ;
V_6 = F_2 ( V_2 ) ;
if ( V_6 < 0 )
goto V_13;
V_2 -> V_5 = V_5 ;
V_2 -> V_14 = & V_4 -> V_9 -> V_15 [ 1 ] . V_10 ;
V_2 -> V_16 = & V_4 -> V_9 -> V_15 [ 2 ] . V_10 ;
V_2 -> V_17 = F_3 ( V_2 -> V_14 ) ;
V_2 -> V_18 = F_4 ( V_2 -> V_17 , V_19 ) ;
if ( V_2 -> V_18 == NULL ) {
V_6 = - V_20 ;
goto V_21;
}
V_6 = F_5 ( V_2 , V_4 ) ;
if ( V_6 < 0 ) {
F_6 ( V_8 , L_1 ,
V_6 ) ;
goto V_22;
}
return 0 ;
V_22:
F_7 ( V_2 -> V_18 ) ;
V_21:
F_8 ( V_2 ) ;
V_13:
return V_6 ;
}
void F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 ) {
F_10 ( V_2 -> V_23 ) ;
F_11 ( V_2 -> V_23 ) ;
}
F_7 ( V_2 -> V_18 ) ;
F_12 ( V_2 ) ;
F_8 ( V_2 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
F_14 ( V_2 -> V_24 ) ;
}
