T_1
F_1 ( T_2 V_1 )
{
return V_2 [ V_1 ] ;
}
T_1
F_2 ( T_2 V_1 )
{
return V_3 [ V_1 ] ;
}
T_1
F_3 ( const void * V_4 , int V_5 , T_1 V_6 )
{
const T_3 * V_7 = ( const T_3 * ) V_4 ;
V_6 = F_4 ( V_6 ) ;
while ( V_5 -- > 0 ) {
F_5 ( V_6 , * V_7 ++ ) ;
}
return F_4 ( V_6 ) ;
}
T_1
F_6 ( const void * V_4 , int V_5 , T_1 V_6 )
{
const T_3 * V_7 = ( const T_3 * ) V_4 ;
while ( V_5 -- > 0 ) {
F_5 ( V_6 , * V_7 ++ ) ;
}
return V_6 ;
}
T_1
F_7 ( const T_3 * V_4 , T_4 V_5 )
{
return ( F_8 ( V_4 , V_5 , V_8 ) ) ;
}
T_1
F_8 ( const T_3 * V_4 , T_4 V_5 , T_1 V_9 )
{
T_4 V_10 ;
T_1 V_11 = V_9 ;
for ( V_10 = 0 ; V_10 < V_5 ; V_10 ++ )
V_11 = V_3 [ ( V_11 ^ V_4 [ V_10 ] ) & 0xff ] ^ ( V_11 >> 8 ) ;
return ( ~ V_11 ) ;
}
T_1
F_9 ( const T_3 * V_4 , T_4 V_5 , T_1 V_9 )
{
T_4 V_10 ;
T_1 V_11 ;
V_11 = V_9 ;
for ( V_10 = 0 ; V_10 < V_5 ; V_10 ++ )
V_11 = ( V_11 << 8 ) ^ V_12 [ ( ( V_11 >> 24 ) ^ V_4 [ V_10 ] ) & 0xff ] ;
return ( V_11 ) ;
}
