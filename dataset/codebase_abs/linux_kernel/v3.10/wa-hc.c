int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 = & V_4 -> V_7 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 < 0 )
goto V_8;
V_2 -> V_9 = & V_4 -> V_10 -> V_11 [ 1 ] . V_12 ;
V_2 -> V_13 = & V_4 -> V_10 -> V_11 [ 2 ] . V_12 ;
V_2 -> V_14 = F_3 ( V_2 -> V_9 ) ;
V_2 -> V_15 = F_4 ( V_2 -> V_14 , V_16 ) ;
if ( V_2 -> V_15 == NULL ) {
V_5 = - V_17 ;
goto V_18;
}
V_5 = F_5 ( V_2 , V_4 ) ;
if ( V_5 < 0 ) {
F_6 ( V_7 , L_1 ,
V_5 ) ;
goto V_19;
}
return 0 ;
V_19:
F_7 ( V_2 -> V_15 ) ;
V_18:
F_8 ( V_2 ) ;
V_8:
return V_5 ;
}
void F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_20 ) {
F_10 ( V_2 -> V_20 ) ;
F_11 ( V_2 -> V_20 ) ;
F_10 ( V_2 -> V_21 ) ;
F_11 ( V_2 -> V_21 ) ;
}
F_7 ( V_2 -> V_15 ) ;
F_12 ( V_2 ) ;
F_8 ( V_2 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
F_14 ( V_2 -> V_22 ) ;
}
