static void F_1 ( struct V_1 * V_1 )
{
V_1 -> V_2 *= V_3 [ ( F_2 ( V_4 ) >> 4 ) & 0x07 ] ;
}
static unsigned long F_3 ( struct V_1 * V_1 )
{
int V_5 = ( ( F_2 ( V_4 ) >> 4 ) & 0x07 ) ;
return V_1 -> V_6 -> V_2 / V_3 [ V_5 ] ;
}
static unsigned long F_4 ( struct V_1 * V_1 )
{
int V_5 = ( ( F_2 ( V_4 ) >> 16 ) & 0x07 ) ;
return V_1 -> V_6 -> V_2 / V_7 [ V_5 ] ;
}
void T_1 F_5 ( struct V_8 * * V_9 , int V_5 )
{
if ( V_5 < F_6 ( V_10 ) )
* V_9 = V_10 [ V_5 ] ;
}
static unsigned long F_7 ( struct V_1 * V_1 )
{
int V_5 = ( ( F_2 ( V_4 ) >> 20 ) & 0x07 ) ;
return V_1 -> V_6 -> V_2 / V_11 [ V_5 ] ;
}
int T_1 F_8 ( void )
{
struct V_1 * V_1 ;
int V_12 , V_13 = 0 ;
F_9 () ;
V_1 = F_10 ( NULL , L_1 ) ;
for ( V_12 = 0 ; V_12 < F_6 ( V_14 ) ; V_12 ++ ) {
struct V_1 * V_15 = V_14 [ V_12 ] ;
V_15 -> V_6 = V_1 ;
V_13 |= F_11 ( V_15 ) ;
}
F_12 ( V_1 ) ;
F_13 ( V_16 , F_6 ( V_16 ) ) ;
return V_13 ;
}
