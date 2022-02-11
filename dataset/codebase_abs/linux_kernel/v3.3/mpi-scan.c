int F_1 ( const T_1 V_1 , unsigned V_2 )
{
int V_3 , V_4 ;
unsigned V_5 ;
T_2 V_6 ;
T_3 V_7 ;
V_6 = V_1 -> V_8 ;
for ( V_5 = 0 , V_3 = 0 ; V_3 < V_1 -> V_9 ; V_3 ++ ) {
V_7 = V_6 [ V_3 ] ;
for ( V_4 = 0 ; V_4 < V_10 ; V_4 ++ , V_5 ++ )
if ( V_5 == V_2 )
return ( V_7 >> V_4 * 8 ) & 0xff ;
}
return - 1 ;
}
void F_2 ( T_1 V_1 , unsigned V_2 , int V_11 )
{
int V_3 , V_4 ;
unsigned V_5 ;
T_2 V_6 ;
T_3 V_7 , V_12 ;
V_12 = V_11 & 0xff ;
V_6 = V_1 -> V_8 ;
for ( V_5 = 0 , V_3 = 0 ; V_3 < V_1 -> V_13 ; V_3 ++ ) {
V_7 = V_6 [ V_3 ] ;
for ( V_4 = 0 ; V_4 < V_10 ; V_4 ++ , V_5 ++ )
if ( V_5 == V_2 ) {
#if V_10 == 4
if ( V_4 == 0 )
V_7 = ( V_7 & 0xffffff00 ) | V_12 ;
else if ( V_4 == 1 )
V_7 = ( V_7 & 0xffff00ff ) | ( V_12 << 8 ) ;
else if ( V_4 == 2 )
V_7 = ( V_7 & 0xff00ffff ) | ( V_12 << 16 ) ;
else
V_7 = ( V_7 & 0x00ffffff ) | ( V_12 << 24 ) ;
#elif V_10 == 8
if ( V_4 == 0 )
V_7 = ( V_7 & 0xffffffffffffff00 ) | V_12 ;
else if ( V_4 == 1 )
V_7 =
( V_7 & 0xffffffffffff00ff ) | ( V_12 <<
8 ) ;
else if ( V_4 == 2 )
V_7 =
( V_7 & 0xffffffffff00ffff ) | ( V_12 <<
16 ) ;
else if ( V_4 == 3 )
V_7 =
( V_7 & 0xffffffff00ffffff ) | ( V_12 <<
24 ) ;
else if ( V_4 == 4 )
V_7 =
( V_7 & 0xffffff00ffffffff ) | ( V_12 <<
32 ) ;
else if ( V_4 == 5 )
V_7 =
( V_7 & 0xffff00ffffffffff ) | ( V_12 <<
40 ) ;
else if ( V_4 == 6 )
V_7 =
( V_7 & 0xff00ffffffffffff ) | ( V_12 <<
48 ) ;
else
V_7 =
( V_7 & 0x00ffffffffffffff ) | ( V_12 <<
56 ) ;
#else
#error please enhance this function, its ugly - i know.
#endif
if ( V_1 -> V_9 <= V_3 )
V_1 -> V_9 = V_3 + 1 ;
V_6 [ V_3 ] = V_7 ;
return;
}
}
F_3 ( L_1 ) ;
}
unsigned F_4 ( const T_1 V_1 )
{
unsigned V_5 , V_14 = 0 ;
for ( V_5 = 0 ; V_5 < V_1 -> V_9 ; V_5 ++ ) {
if ( V_1 -> V_8 [ V_5 ] ) {
unsigned V_15 ;
T_3 V_16 = V_1 -> V_8 [ V_5 ] ;
F_5 ( V_15 , V_16 ) ;
V_14 += V_15 ;
break;
}
V_14 += V_17 ;
}
return V_14 ;
}
