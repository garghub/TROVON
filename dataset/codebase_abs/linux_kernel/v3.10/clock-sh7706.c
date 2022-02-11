static void F_1 ( struct V_1 * V_1 )
{
int V_2 = F_2 ( V_3 ) ;
int V_4 = ( ( V_2 & 0x2000 ) >> 11 ) | ( V_2 & 0x0003 ) ;
V_1 -> V_5 *= V_6 [ V_4 ] ;
}
static unsigned long F_3 ( struct V_1 * V_1 )
{
int V_2 = F_2 ( V_3 ) ;
int V_4 = ( ( V_2 & 0x2000 ) >> 11 ) | ( V_2 & 0x0003 ) ;
return V_1 -> V_7 -> V_5 / V_6 [ V_4 ] ;
}
static unsigned long F_4 ( struct V_1 * V_1 )
{
int V_2 = F_2 ( V_3 ) ;
int V_4 = ( ( V_2 & 0x8000 ) >> 13 ) | ( ( V_2 & 0x0030 ) >> 4 ) ;
return V_1 -> V_7 -> V_5 / V_8 [ V_4 ] ;
}
static unsigned long F_5 ( struct V_1 * V_1 )
{
int V_2 = F_2 ( V_3 ) ;
int V_4 = ( ( V_2 & 0x4000 ) >> 12 ) | ( ( V_2 & 0x000c ) >> 2 ) ;
return V_1 -> V_7 -> V_5 / V_9 [ V_4 ] ;
}
void T_1 F_6 ( struct V_10 * * V_11 , int V_4 )
{
if ( V_4 < F_7 ( V_12 ) )
* V_11 = V_12 [ V_4 ] ;
}
