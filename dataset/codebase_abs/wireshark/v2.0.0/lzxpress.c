T_1 F_1 ( const T_2 * V_1 ,
T_3 V_2 ,
T_2 * V_3 ,
T_3 V_4 )
{
T_3 V_5 , V_6 ;
T_3 V_7 , V_8 ;
T_3 V_9 ;
T_3 V_10 ;
T_3 V_11 ;
V_5 = 0 ;
V_6 = 0 ;
V_7 = 0 ;
V_8 = 0 ;
V_11 = 0 ;
do {
if ( V_8 == 0 ) {
V_7 = F_2 ( V_1 , V_6 ) ;
V_6 += ( T_3 ) sizeof( T_3 ) ;
V_8 = 32 ;
}
V_8 -- ;
if ( ( ( V_7 >> V_8 ) & 1 ) == 0 ) {
V_3 [ V_5 ] = V_1 [ V_6 ] ;
V_6 += ( T_3 ) sizeof( T_2 ) ;
V_5 += ( T_3 ) sizeof( T_2 ) ;
} else {
V_9 = F_3 ( V_1 , V_6 ) ;
V_6 += ( T_3 ) sizeof( V_12 ) ;
V_10 = V_9 / 8 ;
V_9 = V_9 % 8 ;
if ( V_9 == 7 ) {
if ( V_11 == 0 ) {
V_11 = V_6 ;
V_9 = V_1 [ V_6 ] % 16 ;
V_6 += ( T_3 ) sizeof( T_2 ) ;
} else {
V_9 = V_1 [ V_11 ] / 16 ;
V_11 = 0 ;
}
if ( V_9 == 15 ) {
V_9 = V_1 [ V_6 ] ;
V_6 += ( T_3 ) sizeof( T_2 ) ;
if ( V_9 == 255 ) {
V_9 = F_3 ( V_1 , V_6 ) ;
V_6 += ( T_3 ) sizeof( V_12 ) ;
V_9 -= ( 15 + 7 ) ;
}
V_9 += 15 ;
}
V_9 += 7 ;
}
V_9 += 3 ;
do {
if ( ( V_5 >= V_4 ) || ( ( V_10 + 1 ) > V_5 ) ) break;
V_3 [ V_5 ] = V_3 [ V_5 - V_10 - 1 ] ;
V_5 += ( T_3 ) sizeof( T_2 ) ;
V_9 -= ( T_3 ) sizeof( T_2 ) ;
} while ( V_9 != 0 );
}
} while ( ( V_5 < V_4 ) && ( V_6 < ( V_2 ) ) );
return V_5 ;
}
