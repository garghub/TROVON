static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 , V_8 = 0 , V_9 = 0 ;
V_6 -> V_10 = 1 ;
V_6 -> V_11 = 0 ;
for( V_7 = 0 ; V_7 < 256 ; V_7 ++ )
V_6 -> V_12 [ V_7 ] = V_7 ;
for( V_7 = 0 ; V_7 < 256 ; V_7 ++ )
{
T_1 V_13 = V_6 -> V_12 [ V_7 ] ;
V_8 = ( V_8 + V_3 [ V_9 ] + V_13 ) & 0xff ;
V_6 -> V_12 [ V_7 ] = V_6 -> V_12 [ V_8 ] ;
V_6 -> V_12 [ V_8 ] = V_13 ;
if( ++ V_9 >= V_4 )
V_9 = 0 ;
}
return 0 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 * V_14 , const T_1 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 * const V_12 = V_6 -> V_12 ;
T_1 V_10 = V_6 -> V_10 ;
T_1 V_11 = V_6 -> V_11 ;
T_1 V_13 , V_16 ;
V_13 = V_12 [ V_10 ] ;
V_11 = ( V_11 + V_13 ) & 0xff ;
V_16 = V_12 [ V_11 ] ;
V_12 [ V_10 ] = V_16 ;
V_12 [ V_11 ] = V_13 ;
V_10 = ( V_10 + 1 ) & 0xff ;
* V_14 ++ = * V_15 ^ V_12 [ ( V_13 + V_16 ) & 0xff ] ;
V_6 -> V_10 = V_10 ;
V_6 -> V_11 = V_11 ;
}
static int T_2 F_4 ( void )
{
return F_5 ( & V_17 ) ;
}
static void T_3 F_6 ( void )
{
F_7 ( & V_17 ) ;
}
