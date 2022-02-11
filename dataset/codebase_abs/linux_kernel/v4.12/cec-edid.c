static unsigned int F_1 ( const T_1 * V_1 , unsigned int V_2 )
{
unsigned int V_3 = V_2 / 128 ;
unsigned int V_4 ;
T_1 V_5 ;
if ( V_3 < 2 || V_2 % 128 )
return 0 ;
if ( V_1 [ 0x7e ] + 1 < V_3 )
V_3 = V_1 [ 0x7e ] + 1 ;
for ( V_4 = 1 ; V_4 < V_3 ; V_4 ++ ) {
unsigned int V_6 = V_4 * 128 ;
if ( V_1 [ V_6 ] != 0x02 || V_1 [ V_6 + 1 ] != 0x03 )
continue;
V_5 = V_1 [ V_6 + 2 ] & 0x7f ;
if ( V_5 <= 4 )
continue;
if ( V_5 > 4 ) {
unsigned int V_7 = V_6 + 4 ;
unsigned int V_8 = V_6 + V_5 ;
do {
T_1 V_9 = V_1 [ V_7 ] >> 5 ;
T_1 V_10 = V_1 [ V_7 ] & 0x1f ;
if ( V_9 == 3 && V_10 >= 5 && V_7 + V_10 <= V_8 &&
V_1 [ V_7 + 1 ] == 0x03 &&
V_1 [ V_7 + 2 ] == 0x0c &&
V_1 [ V_7 + 3 ] == 0x00 )
return V_7 + 4 ;
V_7 += V_10 + 1 ;
} while ( V_7 < V_8 );
}
}
return 0 ;
}
T_2 F_2 ( const T_1 * V_1 , unsigned int V_2 ,
unsigned int * V_6 )
{
unsigned int V_11 = F_1 ( V_1 , V_2 ) ;
if ( V_6 )
* V_6 = V_11 ;
if ( V_11 == 0 )
return V_12 ;
return ( V_1 [ V_11 ] << 8 ) | V_1 [ V_11 + 1 ] ;
}
void F_3 ( T_1 * V_1 , unsigned int V_2 , T_2 V_13 )
{
unsigned int V_11 = F_1 ( V_1 , V_2 ) ;
T_1 V_14 = 0 ;
unsigned int V_7 ;
if ( V_11 == 0 )
return;
V_1 [ V_11 ] = V_13 >> 8 ;
V_1 [ V_11 + 1 ] = V_13 & 0xff ;
V_11 &= ~ 0x7f ;
for ( V_7 = V_11 ; V_7 < V_11 + 127 ; V_7 ++ )
V_14 += V_1 [ V_7 ] ;
V_1 [ V_7 ] = 256 - V_14 ;
}
T_2 F_4 ( T_2 V_13 , T_1 V_15 )
{
if ( F_5 ( V_15 == 0 || V_15 > 0xf ) )
return V_12 ;
if ( V_13 == 0 )
return V_15 << 12 ;
if ( ( V_13 & 0x0fff ) == 0 )
return V_13 | ( V_15 << 8 ) ;
if ( ( V_13 & 0x00ff ) == 0 )
return V_13 | ( V_15 << 4 ) ;
if ( ( V_13 & 0x000f ) == 0 )
return V_13 | V_15 ;
return V_12 ;
}
int F_6 ( T_2 V_13 , T_2 * V_16 , T_2 * V_17 )
{
int V_7 ;
if ( V_16 )
* V_16 = V_13 ;
if ( V_17 )
* V_17 = 0 ;
if ( V_13 == V_12 )
return 0 ;
for ( V_7 = 0 ; V_7 < 16 ; V_7 += 4 )
if ( V_13 & ( 0xf << V_7 ) )
break;
if ( V_7 == 16 )
return 0 ;
if ( V_16 )
* V_16 = V_13 & ( 0xfff0 << V_7 ) ;
if ( V_17 )
* V_17 = ( V_13 >> V_7 ) & 0xf ;
for ( V_7 += 4 ; V_7 < 16 ; V_7 += 4 )
if ( ( V_13 & ( 0xf << V_7 ) ) == 0 )
return - V_18 ;
return 0 ;
}
