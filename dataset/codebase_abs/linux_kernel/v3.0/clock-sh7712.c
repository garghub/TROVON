static void F_1 ( struct V_1 * V_1 )
{
int V_2 = F_2 ( V_3 ) ;
int V_4 = ( V_2 & 0x0300 ) >> 8 ;
V_1 -> V_5 *= V_6 [ V_4 ] ;
}
static unsigned long F_3 ( struct V_1 * V_1 )
{
int V_2 = F_2 ( V_3 ) ;
int V_4 = V_2 & 0x0007 ;
return V_1 -> V_7 -> V_5 / V_8 [ V_4 ] ;
}
static unsigned long F_4 ( struct V_1 * V_1 )
{
int V_2 = F_2 ( V_3 ) ;
int V_4 = ( V_2 & 0x0030 ) >> 4 ;
return V_1 -> V_7 -> V_5 / V_8 [ V_4 ] ;
}
void T_1 F_5 ( struct V_9 * * V_10 , int V_4 )
{
if ( V_4 < F_6 ( V_11 ) )
* V_10 = V_11 [ V_4 ] ;
}
