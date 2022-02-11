static void F_1 ( struct V_1 * V_1 )
{
V_1 -> V_2 *= V_3 [ F_2 ( V_4 ) & 0x0007 ] ;
}
static unsigned long F_3 ( struct V_1 * V_1 )
{
int V_5 = ( F_2 ( V_4 ) & 0x0007 ) ;
return V_1 -> V_6 -> V_2 / V_3 [ V_5 ] ;
}
static unsigned long F_4 ( struct V_1 * V_1 )
{
int V_5 = ( F_2 ( V_4 ) & 0x0700 ) >> 8 ;
return V_1 -> V_6 -> V_2 / V_3 [ V_5 ] ;
}
static unsigned long F_5 ( struct V_1 * V_1 )
{
int V_5 = ( F_2 ( V_4 ) & 0x0070 ) >> 4 ;
return V_1 -> V_6 -> V_2 / V_3 [ V_5 ] ;
}
void T_1 F_6 ( struct V_7 * * V_8 , int V_5 )
{
if ( V_5 < F_7 ( V_9 ) )
* V_8 = V_9 [ V_5 ] ;
}
