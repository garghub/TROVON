void F_1 ( T_1 * V_1 ,
const unsigned char * V_2 , int V_3 )
{
int V_4 ;
unsigned char V_5 = 0 ;
unsigned char * V_6 ;
memset ( V_1 , 0 , sizeof( T_1 ) ) ;
V_6 = V_1 -> V_6 ;
for ( V_4 = 0 ; V_4 < 256 ; V_4 ++ )
{
V_6 [ V_4 ] = ( unsigned char ) V_4 ;
}
for( V_4 = 0 ; V_4 < 256 ; V_4 ++ )
{
unsigned char V_7 ;
V_5 += ( V_6 [ V_4 ] + V_2 [ V_4 % V_3 ] ) ;
V_7 = V_6 [ V_4 ] ;
V_6 [ V_4 ] = V_6 [ V_5 ] ;
V_6 [ V_5 ] = V_7 ;
}
}
void F_2 ( T_1 * V_1 , unsigned char * V_8 , int V_9 )
{
unsigned char * V_6 ;
unsigned char V_10 ;
unsigned char V_11 ;
int V_4 ;
V_10 = V_1 -> V_10 ;
V_11 = V_1 -> V_11 ;
V_6 = V_1 -> V_6 ;
for( V_4 = 0 ; V_4 < V_9 ; V_4 ++ )
{
unsigned char V_7 ;
unsigned char V_12 ;
V_10 ++ ;
V_11 += V_6 [ V_10 ] ;
V_7 = V_6 [ V_10 ] ;
V_6 [ V_10 ] = V_6 [ V_11 ] ;
V_6 [ V_11 ] = V_7 ;
V_12 = V_6 [ V_10 ] + V_6 [ V_11 ] ;
V_8 [ V_4 ] = V_8 [ V_4 ] ^ V_6 [ V_12 ] ;
}
V_1 -> V_10 = V_10 ;
V_1 -> V_11 = V_11 ;
}
