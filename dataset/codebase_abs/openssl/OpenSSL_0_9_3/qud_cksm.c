T_1 F_1 ( const unsigned char * V_1 , T_2 V_2 [] ,
long V_3 , int V_4 , T_2 * V_5 )
{
T_1 V_6 , V_7 , V_8 , V_9 ;
int V_10 ;
long V_11 ;
const unsigned char * V_12 ;
unsigned char * V_13 ;
if ( V_4 < 1 ) V_4 = 1 ;
V_13 = & ( V_2 [ 0 ] ) [ 0 ] ;
V_6 = F_2 ( ( * V_5 ) [ 0 ] ) | F_3 ( ( * V_5 ) [ 1 ] ) | F_4 ( ( * V_5 ) [ 2 ] ) | F_5 ( ( * V_5 ) [ 3 ] ) ;
V_7 = F_2 ( ( * V_5 ) [ 4 ] ) | F_3 ( ( * V_5 ) [ 5 ] ) | F_4 ( ( * V_5 ) [ 6 ] ) | F_5 ( ( * V_5 ) [ 7 ] ) ;
for ( V_10 = 0 ; ( ( V_10 < 4 ) && ( V_10 < V_4 ) ) ; V_10 ++ )
{
V_12 = V_1 ;
V_11 = V_3 ;
while ( V_11 > 0 )
{
if ( V_11 > 1 )
{
V_8 = ( T_1 ) ( * ( V_12 ++ ) ) ;
V_8 |= ( T_1 ) F_3 ( * ( V_12 ++ ) ) ;
V_11 -- ;
}
else
V_8 = ( T_1 ) ( * ( V_12 ++ ) ) ;
V_11 -- ;
V_8 += V_6 ;
V_8 &= 0xffffffffL ;
V_9 = V_7 ;
V_6 = ( ( ( ( V_8 * V_8 ) & 0xffffffffL ) + ( ( V_9 * V_9 ) & 0xffffffffL ) )
& 0xffffffffL ) % 0x7fffffffL ;
V_7 = ( ( V_8 * ( ( V_9 + V_14 ) & 0xffffffffL ) ) & 0xffffffffL ) % 0x7fffffffL ;
}
if ( V_13 != NULL )
{
static T_1 V_15 = 1 ;
static unsigned char * V_16 = ( unsigned char * ) & V_15 ;
if ( V_16 [ 0 ] )
{
F_6 ( V_6 , V_13 ) ;
F_6 ( V_7 , V_13 ) ;
}
else
{
V_13 = & ( V_2 [ V_4 - V_10 - 1 ] ) [ 0 ] ;
F_7 ( V_7 , V_13 ) ;
F_7 ( V_6 , V_13 ) ;
}
}
}
return ( V_6 ) ;
}
