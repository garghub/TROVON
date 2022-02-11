int F_1 ( const T_1 V_1 , const struct V_2 * V_2 ,
T_2 V_3 )
{
struct V_4 * V_4 ;
T_2 V_5 ;
int V_6 ;
V_4 = F_2 ( V_1 ) ;
if ( F_3 ( V_4 -> V_7 , V_2 -> V_8 ) ) {
V_5 = V_4 -> V_3 >> 16 ;
goto V_9;
}
if ( F_4 ( V_4 -> V_10 ) && V_4 -> V_3 & V_11 ) {
if ( F_5 ( V_4 -> V_10 , V_2 -> V_12 ) ) {
V_5 = V_4 -> V_3 >> 8 ;
goto V_9;
}
V_6 = F_6 ( V_2 -> V_13 , V_4 -> V_10 ) ;
if ( V_6 ) {
V_5 = V_4 -> V_3 >> 8 ;
goto V_9;
}
}
V_5 = V_4 -> V_3 ;
V_9:
if ( F_7 ( V_1 ) )
V_5 |= V_4 -> V_3 >> 24 ;
V_5 = V_5 & V_3 & V_14 ;
if ( V_5 != V_3 )
return - V_15 ;
return F_8 ( V_1 , V_2 , V_3 ) ;
}
int F_9 ( const struct V_4 * V_4 )
{
unsigned long V_16 = V_4 -> V_16 ;
if ( V_16 & ( 1 << V_17 ) )
return - V_18 ;
if ( V_16 & ( ( 1 << V_19 ) |
( 1 << V_20 ) ) )
return - V_21 ;
if ( V_4 -> V_22 ) {
struct V_23 V_24 = F_10 () ;
if ( V_24 . V_25 >= V_4 -> V_22 )
return - V_26 ;
}
return 0 ;
}
