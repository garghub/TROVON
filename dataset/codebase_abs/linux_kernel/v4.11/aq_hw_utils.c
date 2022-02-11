void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_5 , T_1 V_6 )
{
if ( V_4 ^ ~ 0 ) {
T_1 V_7 , V_8 ;
V_7 = F_2 ( V_2 , V_3 ) ;
V_8 = ( V_7 & ( ~ V_4 ) ) | ( V_6 << V_5 ) ;
if ( V_7 != V_8 )
F_3 ( V_2 , V_3 , V_8 ) ;
} else {
F_3 ( V_2 , V_3 , V_6 ) ;
}
}
T_1 F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
return ( ( F_2 ( V_2 , V_3 ) & V_4 ) >> V_5 ) ;
}
T_1 F_2 ( struct V_1 * V_9 , T_1 V_10 )
{
T_1 V_11 = F_5 ( V_9 -> V_12 + V_10 ) ;
if ( ( ~ 0U ) == V_11 && ( ~ 0U ) == F_5 ( V_9 -> V_12 + V_9 -> V_13 ) )
F_6 ( & V_9 -> V_14 . V_15 , V_16 ) ;
return V_11 ;
}
void F_3 ( struct V_1 * V_9 , T_1 V_10 , T_1 V_11 )
{
F_7 ( V_11 , V_9 -> V_12 + V_10 ) ;
}
int F_8 ( struct V_1 * V_9 )
{
int V_17 = 0 ;
if ( F_9 ( & V_9 -> V_14 . V_15 , V_16 ) ) {
V_17 = - V_18 ;
goto V_19;
}
if ( F_9 ( & V_9 -> V_14 . V_15 , V_20 ) ) {
V_17 = - V_21 ;
goto V_19;
}
V_19:
return V_17 ;
}
