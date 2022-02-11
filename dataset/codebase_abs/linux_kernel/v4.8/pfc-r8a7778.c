static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
void T_1 * V_4 ;
if ( F_2 ( ! V_5 [ V_3 ] . V_6 ) )
return V_7 ;
V_4 = V_2 -> V_8 -> V_9 + V_5 [ V_3 ] . V_6 ;
if ( F_3 ( V_4 ) & F_4 ( V_5 [ V_3 ] . V_10 ) )
return V_11 ;
else
return V_7 ;
}
static void F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_12 )
{
void T_1 * V_4 ;
T_2 V_13 ;
T_2 V_10 ;
if ( F_2 ( ! V_5 [ V_3 ] . V_6 ) )
return;
V_4 = V_2 -> V_8 -> V_9 + V_5 [ V_3 ] . V_6 ;
V_10 = F_4 ( V_5 [ V_3 ] . V_10 ) ;
V_13 = F_3 ( V_4 ) & ~ V_10 ;
if ( V_12 == V_11 )
V_13 |= V_10 ;
F_6 ( V_13 , V_4 ) ;
}
