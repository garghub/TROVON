static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_8 * V_9 ;
struct V_8 V_10 ;
const T_1 * V_11 ;
T_2 V_12 [ 15 * 4 - sizeof( V_10 ) ] ;
unsigned int V_13 , V_14 ;
V_9 = F_2 ( V_2 , V_4 -> V_15 , sizeof( V_10 ) , & V_10 ) ;
if ( V_9 == NULL )
goto V_16;
if ( V_9 -> V_17 * 4 < sizeof( * V_9 ) )
goto V_16;
V_14 = V_9 -> V_17 * 4 - sizeof( * V_9 ) ;
if ( ! V_14 )
goto V_18;
V_11 = F_2 ( V_2 , V_4 -> V_15 + sizeof( * V_9 ) , V_14 , V_12 ) ;
if ( V_11 == NULL )
goto V_16;
for ( V_13 = 0 ; V_13 < V_14 ; ) {
if ( V_11 [ V_13 ] == V_19
&& ( V_14 - V_13 ) >= V_20
&& V_11 [ V_13 + 1 ] == V_20 ) {
T_3 V_21 ;
V_21 = ( V_11 [ V_13 + 2 ] << 8 ) | V_11 [ V_13 + 3 ] ;
return ( V_21 >= V_6 -> V_22 &&
V_21 <= V_6 -> V_23 ) ^ V_6 -> V_24 ;
}
if ( V_11 [ V_13 ] < 2 )
V_13 ++ ;
else
V_13 += V_11 [ V_13 + 1 ] ? : 1 ;
}
V_18:
return V_6 -> V_24 ;
V_16:
V_4 -> V_25 = true ;
return false ;
}
static int T_4 F_3 ( void )
{
return F_4 ( V_26 , F_5 ( V_26 ) ) ;
}
static void T_5 F_6 ( void )
{
F_7 ( V_26 , F_5 ( V_26 ) ) ;
}
