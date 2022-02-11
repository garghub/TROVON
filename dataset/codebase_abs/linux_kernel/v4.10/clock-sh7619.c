static void F_1 ( struct V_1 * V_1 )
{
V_1 -> V_2 *= V_3 * V_4 [ ( F_2 ( V_5 ) >> 8 ) & 7 ] ;
}
static unsigned long F_3 ( struct V_1 * V_1 )
{
int V_6 = ( F_2 ( V_5 ) & 0x0007 ) ;
return V_1 -> V_7 -> V_2 / V_8 [ V_6 ] ;
}
static unsigned long F_4 ( struct V_1 * V_1 )
{
return V_1 -> V_7 -> V_2 / V_4 [ ( F_2 ( V_5 ) >> 8 ) & 7 ] ;
}
void T_1 F_5 ( struct V_9 * * V_10 , int V_6 )
{
if ( F_6 ( V_11 | V_12 ) ||
F_6 ( V_11 | V_13 ) )
V_3 = 2 ;
else if ( F_6 ( V_12 ) || F_6 ( V_13 ) )
V_3 = 4 ;
F_7 ( ! V_3 ) ;
if ( V_6 < F_8 ( V_14 ) )
* V_10 = V_14 [ V_6 ] ;
}
