static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
V_3 = F_2 ( V_2 , V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 &= ~ ( V_5 | V_6 | V_7 |
V_8 ) ;
F_3 ( V_2 , V_4 , V_3 | V_9 ) ;
return F_4 ( V_2 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_10 ;
T_1 V_11 ;
static int V_12 ;
V_10 = F_6 ( V_2 ) ;
if ( V_12 != V_2 -> V_12 ) {
V_12 = V_2 -> V_12 ;
V_11 = F_2 ( V_2 , V_13 ) ;
if ( ( V_11 & V_14 ) ==
V_15 ) {
V_11 = F_2 ( V_2 , V_16 ) ;
V_11 &= ~ V_17 ;
F_3 ( V_2 , V_16 , V_11\
| V_18\
| V_19\
| V_20 ) ;
}
}
return V_10 ;
}
