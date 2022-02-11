int
F_1 ( T_1 * V_1 , int V_2 , T_1 * V_3 , T_2 * V_4 )
{
int V_5 , V_6 = 0 , V_7 = 0 ;
if ( ! V_2 )
return 0 ;
if ( * V_4 ) {
* V_3 ++ = V_8 [ ( ( ( * V_4 ) << 8 ) & 0xff00 ) | ( * V_1 ++ ) ] ;
V_2 -- ;
V_7 ++ ;
}
V_5 = V_2 >> 1 ;
while ( V_6 < V_5 ) {
* V_3 ++ = V_8 [ ( V_1 [ 0 ] << 8 ) | ( V_1 [ 1 ] ) ] ;
V_1 += 2 ;
V_6 ++ ;
V_7 ++ ;
}
if ( V_2 & 1 )
* V_4 = 0x100 + * V_1 ;
else
* V_4 = 0 ;
return V_7 ;
}
int
F_2 ( T_1 * V_1 , int V_2 , T_1 * V_3 )
{
int V_6 = 0 ;
T_3 V_9 ;
while ( V_6 < V_2 ) {
V_9 = V_10 [ * V_1 ++ ] ;
* V_3 ++ = V_9 >> 8 ;
* V_3 ++ = V_9 ;
V_6 ++ ;
}
return V_2 << 1 ;
}
int
F_3 ( T_1 * V_1 , int V_2 , T_1 * V_3 )
{
int V_6 = 0 ;
while ( V_6 < V_2 ) {
* V_3 ++ = V_11 [ * V_1 ++ ] ;
V_6 ++ ;
}
return V_2 ;
}
int
F_4 ( T_1 * V_1 , int V_2 , T_1 * V_3 )
{
int V_6 = 0 ;
while ( V_6 < V_2 ) {
* V_3 ++ = V_12 [ * V_1 ++ ] ;
V_6 ++ ;
}
return V_2 ;
}
void
F_5 ( void )
{
F_6 ( V_10 ) ;
F_6 ( V_8 ) ;
V_8 = NULL ;
V_10 = NULL ;
}
int
F_7 ( int V_13 )
{
int V_14 , V_15 , V_16 , V_17 ;
if ( V_10 )
return 0 ;
V_8 = F_8 ( 65536 ) ;
V_10 = F_8 ( 512 ) ;
if ( ! V_8 || ! V_10 ) {
F_5 () ;
return - V_18 ;
}
V_14 = 0 ;
while ( V_14 < 256 ) {
if ( V_13 )
V_16 = V_19 [ V_14 ] ;
else
V_16 = V_20 [ V_14 ] ;
V_15 = 0 ;
while ( V_15 < 256 ) {
V_8 [ ( V_14 << 8 ) | V_15 ] |= ( V_16 << 4 ) ;
V_8 [ ( V_15 << 8 ) | V_14 ] |= V_16 ;
V_15 ++ ;
}
V_14 ++ ;
}
V_14 = 0 ;
while ( V_14 < 16 ) {
if ( V_13 )
V_17 = V_21 [ V_14 ] ;
else
V_17 = V_22 [ V_14 ] ;
V_15 = 0 ;
while ( V_15 < 16 ) {
V_10 [ ( V_14 << 4 ) | V_15 ] |= ( V_17 << 8 ) ;
V_10 [ ( V_15 << 4 ) | V_14 ] |= V_17 ;
V_15 ++ ;
}
V_14 ++ ;
}
return 0 ;
}
