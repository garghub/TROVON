static void F_1 ( struct V_1 * V_1 )
{
V_1 -> V_2 *= V_3 [ ( F_2 ( V_4 ) >> 28 ) & 0x000f ] ;
}
static unsigned long F_3 ( struct V_1 * V_1 )
{
int V_5 = ( ( F_2 ( V_4 ) >> 28 ) & 0x000f ) ;
return V_1 -> V_6 -> V_2 / V_3 [ V_5 ] ;
}
static unsigned long F_4 ( struct V_1 * V_1 )
{
int V_5 = ( F_2 ( V_4 ) & 0x000f ) ;
return V_1 -> V_6 -> V_2 / V_7 [ V_5 ] ;
}
static unsigned long F_5 ( struct V_1 * V_1 )
{
int V_5 = ( ( F_2 ( V_4 ) >> 24 ) & 0x000f ) ;
return V_1 -> V_6 -> V_2 / V_8 [ V_5 ] ;
}
void T_1 F_6 ( struct V_9 * * V_10 , int V_5 )
{
if ( V_5 < F_7 ( V_11 ) )
* V_10 = V_11 [ V_5 ] ;
}
