static void F_1 ( struct V_1 * V_1 )
{
V_1 -> V_2 *= V_3 [ ( F_2 ( V_4 ) >> 8 ) & 0x0003 ] * V_5 ;
}
static unsigned long F_3 ( struct V_1 * V_1 )
{
int V_6 = ( F_2 ( V_4 ) & 0x0007 ) ;
return V_1 -> V_7 -> V_2 / V_8 [ V_6 ] ;
}
static unsigned long F_4 ( struct V_1 * V_1 )
{
int V_6 = ( F_2 ( V_4 ) & 0x0007 ) ;
return V_1 -> V_7 -> V_2 / V_8 [ V_6 - 2 ] ;
}
void T_1 F_5 ( struct V_9 * * V_10 , int V_6 )
{
if ( F_6 ( V_11 ) )
V_5 = 4 ;
else if ( F_6 ( V_12 ) )
V_5 = 2 ;
else
V_5 = 1 ;
if ( V_6 < F_7 ( V_13 ) )
* V_10 = V_13 [ V_6 ] ;
}
