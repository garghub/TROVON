void F_1 ( T_1 V_1 , unsigned char * V_2 , unsigned int V_3 )
{
unsigned int V_4 , V_5 ;
unsigned int V_6 ;
unsigned int V_7 ;
unsigned char * V_8 ;
unsigned int V_9 ;
V_8 = V_1 -> V_10 ;
V_1 -> V_11 = 0 ;
V_1 -> V_12 = 0 ;
for ( V_9 = 0 ; V_9 < 256 ; V_9 ++ )
V_8 [ V_9 ] = ( unsigned char ) V_9 ;
V_6 = 0 ;
V_7 = 0 ;
for ( V_9 = 0 ; V_9 < 256 ; V_9 ++ ) {
V_4 = V_8 [ V_9 ] ;
V_7 = ( V_7 + V_2 [ V_6 ] + V_4 ) & 0xff ;
V_5 = V_8 [ V_7 ] ;
V_8 [ V_7 ] = ( unsigned char ) V_4 ;
V_8 [ V_9 ] = ( unsigned char ) V_5 ;
if ( ++ V_6 >= V_3 )
V_6 = 0 ;
}
}
unsigned int F_2 ( T_1 V_1 )
{
unsigned int V_11 ;
unsigned int V_12 ;
unsigned int V_13 , V_14 ;
unsigned char * V_8 ;
V_8 = V_1 -> V_10 ;
V_11 = ( V_1 -> V_11 + 1 ) & 0xff ;
V_13 = V_8 [ V_11 ] ;
V_12 = ( V_13 + V_1 -> V_12 ) & 0xff ;
V_14 = V_8 [ V_12 ] ;
V_1 -> V_11 = V_11 ;
V_1 -> V_12 = V_12 ;
V_8 [ V_12 ] = ( unsigned char ) V_13 ;
V_8 [ V_11 ] = ( unsigned char ) V_14 ;
return V_8 [ ( V_13 + V_14 ) & 0xff ] ;
}
void F_3 ( T_1 V_1 , unsigned char * V_15 ,
unsigned char * V_16 , unsigned int V_17 )
{
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ )
V_15 [ V_18 ] = ( unsigned char ) ( V_16 [ V_18 ] ^ F_2 ( V_1 ) ) ;
}
