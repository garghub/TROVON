static bool F_1 ( const T_1 V_1 , const T_1 V_2 )
{
T_1 V_3 = ( V_2 & 0x000000FF ) ;
T_1 V_4 = ( V_2 & 0x0000FF00 ) >> 8 ;
T_1 V_5 = ( V_2 & 0x00FF0000 ) >> 16 ;
T_1 V_6 = V_1 ;
if ( V_1 == 0xCDCDCDCD )
return true ;
V_6 = V_1 & 0x000000FF ;
if ( ( V_3 == V_6 ) && V_6 != 0x00 )
return false ;
V_6 = V_1 & 0x0000FF00 ;
V_6 >>= 8 ;
if ( ( V_4 & V_6 ) == 0 && V_6 != 0x07 )
return false ;
V_6 = V_1 & 0x00FF0000 ;
V_6 >>= 16 ;
if ( ( V_5 & V_6 ) == 0 && V_6 != 0x0F )
return false ;
return true ;
}
void F_2 ( struct V_7 * V_8 )
{
#define F_3 ( T_2 , T_3 , T_4 ) \
do { \
i += 2; v1 = Array[i]; v2 = Array[i+1];\
} while (0)
T_1 V_9 = 0 ;
T_1 T_4 = 0 ;
T_5 V_10 = 0x04 ;
T_5 V_11 = V_8 -> V_12 ;
T_1 V_13 = sizeof( V_14 ) / sizeof( T_1 ) ;
T_1 * V_15 = V_14 ;
V_9 += V_11 ;
V_9 += V_16 << 8 ;
V_9 += V_10 << 16 ;
V_9 += 0xFF000000 ;
for ( T_4 = 0 ; T_4 < V_13 ; T_4 += 2 ) {
T_1 T_2 = V_15 [ T_4 ] ;
T_1 T_3 = V_15 [ T_4 + 1 ] ;
if ( T_2 < 0xCDCDCDCD ) {
F_4 ( V_8 , T_2 , T_3 , V_17 , T_2 ) ;
continue;
} else {
if ( ! F_1 ( V_15 [ T_4 ] , V_9 ) ) {
F_3 ( T_2 , T_3 , T_4 ) ;
while ( T_3 != 0xDEAD &&
T_3 != 0xCDEF &&
T_3 != 0xCDCD && T_4 < V_13 - 2 )
F_3 ( T_2 , T_3 , T_4 ) ;
T_4 -= 2 ;
} else {
F_3 ( T_2 , T_3 , T_4 ) ;
while ( T_3 != 0xDEAD &&
T_3 != 0xCDEF &&
T_3 != 0xCDCD && T_4 < V_13 - 2 ) {
F_4 ( V_8 , T_2 , T_3 ,
V_17 , T_2 ) ;
F_3 ( T_2 , T_3 , T_4 ) ;
}
while ( T_3 != 0xDEAD && T_4 < V_13 - 2 )
F_3 ( T_2 , T_3 , T_4 ) ;
}
}
}
}
