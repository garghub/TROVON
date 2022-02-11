static void F_1 ( struct V_1 * V_1 )
{
V_1 -> V_2 = 10000000 * V_3 *
V_4 [ ( F_2 ( V_5 ) >> 8 ) & 0x0007 ] ;
}
static unsigned long F_3 ( struct V_1 * V_1 )
{
int V_6 = ( F_2 ( V_5 ) & 0x0007 ) ;
return V_1 -> V_7 -> V_2 / V_8 [ V_6 ] ;
}
static unsigned long F_4 ( struct V_1 * V_1 )
{
int V_6 = ( F_2 ( V_5 ) & 0x0007 ) ;
return V_1 -> V_7 -> V_2 / V_8 [ V_6 ] ;
}
static unsigned long F_5 ( struct V_1 * V_1 )
{
int V_6 = ( ( F_2 ( V_5 ) >> 4 ) & 0x0007 ) ;
return V_1 -> V_7 -> V_2 / V_9 [ V_6 ] ;
}
void T_1 F_6 ( struct V_10 * * V_11 , int V_6 )
{
if ( F_7 ( V_12 | V_13 ) )
V_3 = 1 ;
else if ( F_7 ( V_12 ) )
V_3 = 2 ;
else
V_3 = 4 ;
if ( V_6 < F_8 ( V_14 ) )
* V_11 = V_14 [ V_6 ] ;
}
