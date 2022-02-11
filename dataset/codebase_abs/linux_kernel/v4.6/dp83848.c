static int F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 , V_4 ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_5 , V_6 ;
V_5 = F_2 ( V_2 , V_7 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_2 -> V_8 == V_9 ) {
V_5 |= V_10 ;
V_5 |= V_11 ;
V_6 = F_4 ( V_2 , V_4 , V_12 ) ;
if ( V_6 < 0 )
return V_6 ;
} else {
V_5 &= ~ V_11 ;
}
return F_4 ( V_2 , V_7 , V_5 ) ;
}
