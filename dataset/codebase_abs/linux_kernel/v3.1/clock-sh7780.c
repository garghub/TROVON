static void F_1 ( struct V_1 * V_1 )
{
V_1 -> V_2 *= V_3 [ F_2 ( V_4 ) & 0x0003 ] ;
}
static unsigned long F_3 ( struct V_1 * V_1 )
{
int V_5 = ( F_2 ( V_4 ) & 0x0003 ) ;
return V_1 -> V_6 -> V_2 / V_3 [ V_5 ] ;
}
static unsigned long F_4 ( struct V_1 * V_1 )
{
int V_5 = ( ( F_2 ( V_4 ) >> 16 ) & 0x0007 ) ;
return V_1 -> V_6 -> V_2 / V_7 [ V_5 ] ;
}
static unsigned long F_5 ( struct V_1 * V_1 )
{
int V_5 = ( ( F_2 ( V_4 ) >> 24 ) & 0x0001 ) ;
return V_1 -> V_6 -> V_2 / V_8 [ V_5 ] ;
}
void T_1 F_6 ( struct V_9 * * V_10 , int V_5 )
{
if ( V_5 < F_7 ( V_11 ) )
* V_10 = V_11 [ V_5 ] ;
}
static unsigned long F_8 ( struct V_1 * V_1 )
{
int V_5 = ( ( F_2 ( V_4 ) >> 20 ) & 0x0007 ) ;
return V_1 -> V_6 -> V_2 / V_12 [ V_5 ] ;
}
int T_1 F_9 ( void )
{
struct V_1 * V_1 ;
int V_13 , V_14 = 0 ;
F_10 () ;
V_1 = F_11 ( NULL , L_1 ) ;
for ( V_13 = 0 ; V_13 < F_7 ( V_15 ) ; V_13 ++ ) {
struct V_1 * V_16 = V_15 [ V_13 ] ;
V_16 -> V_6 = V_1 ;
V_14 |= F_12 ( V_16 ) ;
}
F_13 ( V_1 ) ;
F_14 ( V_17 , F_7 ( V_17 ) ) ;
return V_14 ;
}
