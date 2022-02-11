static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_3 = F_2 ( V_2 , V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 |= V_6 ;
V_4 = F_3 ( V_2 , V_5 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_3 = ~ ( V_7 |
V_8 |
V_9 ) |
V_10 ;
return F_3 ( V_2 , V_5 , V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_3 = F_2 ( V_2 , V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_11 == V_12 )
V_3 &= ~ V_6 ;
else
V_3 |= V_6 ;
V_4 = F_3 ( V_2 , V_5 , V_3 ) ;
return V_4 ;
}
