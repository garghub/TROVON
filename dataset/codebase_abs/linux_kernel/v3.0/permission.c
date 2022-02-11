int F_1 ( const T_1 V_1 , const struct V_2 * V_2 ,
T_2 V_3 )
{
struct V_4 * V_4 ;
T_2 V_5 ;
int V_6 ;
V_4 = F_2 ( V_1 ) ;
if ( V_4 -> V_7 -> V_8 != V_2 -> V_7 -> V_8 )
goto V_9;
if ( V_4 -> V_10 == V_2 -> V_11 ) {
V_5 = V_4 -> V_3 >> 16 ;
goto V_12;
}
if ( V_4 -> V_13 != - 1 && V_4 -> V_3 & V_14 ) {
if ( V_4 -> V_13 == V_2 -> V_15 ) {
V_5 = V_4 -> V_3 >> 8 ;
goto V_12;
}
V_6 = F_3 ( V_2 -> V_16 , V_4 -> V_13 ) ;
if ( V_6 ) {
V_5 = V_4 -> V_3 >> 8 ;
goto V_12;
}
}
V_9:
V_5 = V_4 -> V_3 ;
V_12:
if ( F_4 ( V_1 ) )
V_5 |= V_4 -> V_3 >> 24 ;
V_5 = V_5 & V_3 & V_17 ;
if ( V_5 != V_3 )
return - V_18 ;
return F_5 ( V_1 , V_2 , V_3 ) ;
}
int F_6 ( struct V_4 * V_4 )
{
struct V_19 V_20 ;
int V_6 = 0 ;
if ( V_4 ) {
V_6 = - V_21 ;
if ( F_7 ( V_22 , & V_4 -> V_23 ) ||
F_7 ( V_24 , & V_4 -> V_23 ) )
goto error;
V_6 = 0 ;
if ( V_4 -> V_25 ) {
V_20 = F_8 () ;
if ( V_20 . V_26 >= V_4 -> V_25 )
V_6 = - V_27 ;
}
}
error:
return V_6 ;
}
