static void F_1 ( struct V_1 * V_1 )
{
int V_2 = ( F_2 ( V_3 + 0x00 ) >> 6 ) & 0x0007 ;
V_1 -> V_4 *= V_5 [ V_2 ] ;
}
static unsigned long F_3 ( struct V_1 * V_1 )
{
int V_2 = ( F_4 ( V_3 ) >> 12 ) & 0x0007 ;
return V_1 -> V_6 -> V_4 / V_5 [ V_2 ] ;
}
static unsigned long F_5 ( struct V_1 * V_1 )
{
int V_2 = ( F_4 ( V_3 ) >> 3 ) & 0x0007 ;
return V_1 -> V_6 -> V_4 / V_5 [ V_2 ] ;
}
static unsigned long F_6 ( struct V_1 * V_1 )
{
int V_2 = ( F_4 ( V_3 ) & 0x0007 ) ;
return V_1 -> V_6 -> V_4 / V_5 [ V_2 ] ;
}
void T_1 F_7 ( struct V_7 * * V_8 , int V_2 )
{
V_3 = ( unsigned long ) F_8 ( V_9 , 1024 ) ;
F_9 ( ! V_3 ) ;
if ( V_2 < F_10 ( V_10 ) )
* V_8 = V_10 [ V_2 ] ;
}
