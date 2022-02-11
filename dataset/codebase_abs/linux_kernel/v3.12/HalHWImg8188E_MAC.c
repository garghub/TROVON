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
V_6 = V_6 >> 8 ;
if ( ( V_4 & V_6 ) == 0 && V_6 != 0x07 )
return false ;
V_6 = V_1 & 0x00FF0000 ;
V_6 = V_6 >> 16 ;
if ( ( V_5 & V_6 ) == 0 && V_6 != 0x0F )
return false ;
return true ;
}
enum V_7 F_2 ( struct V_8 * V_9 )
{
#define F_3 ( T_2 , T_3 , T_4 ) do { i += 2; v1 = array[i]; v2 = array[i+1]; } while (0)
T_1 V_2 = 0 ;
T_1 T_4 ;
T_5 V_10 = V_9 -> V_11 ;
T_5 V_12 = V_9 -> V_13 ;
T_5 V_14 = V_9 -> V_15 ;
T_1 V_16 = sizeof( V_17 ) / sizeof( T_1 ) ;
T_1 * V_18 = V_17 ;
bool V_19 = false ;
struct V_20 * V_21 = V_9 -> V_22 ;
struct V_23 * V_24 = NULL ;
T_5 V_25 = 1 ;
enum V_7 V_26 = V_27 ;
V_2 += V_14 ;
V_2 += V_12 << 8 ;
V_2 += V_10 << 16 ;
V_2 += 0xFF000000 ;
V_19 = F_4 ( V_21 ) ;
if ( V_19 ) {
V_24 = F_5 ( V_21 ) ;
if ( V_24 == NULL ) {
F_6 ( L_1 ) ;
return V_28 ;
}
}
for ( T_4 = 0 ; T_4 < V_16 ; T_4 += 2 ) {
T_1 T_2 = V_18 [ T_4 ] ;
T_1 T_3 = V_18 [ T_4 + 1 ] ;
if ( T_2 < 0xCDCDCDCD ) {
if ( V_19 ) {
if ( F_7 ( V_24 ) )
V_25 ++ ;
F_8 ( V_24 , ( V_29 ) T_2 , ( T_5 ) T_3 , 0xFF ) ;
} else {
F_9 ( V_9 , T_2 , ( T_5 ) T_3 ) ;
}
continue;
} else {
if ( ! F_1 ( V_18 [ T_4 ] , V_2 ) ) {
F_3 ( T_2 , T_3 , T_4 ) ;
while ( T_3 != 0xDEAD &&
T_3 != 0xCDEF &&
T_3 != 0xCDCD && T_4 < V_16 - 2 ) {
F_3 ( T_2 , T_3 , T_4 ) ;
}
T_4 -= 2 ;
} else {
F_3 ( T_2 , T_3 , T_4 ) ;
while ( T_3 != 0xDEAD &&
T_3 != 0xCDEF &&
T_3 != 0xCDCD && T_4 < V_16 - 2 ) {
if ( V_19 ) {
if ( F_7 ( V_24 ) )
V_25 ++ ;
F_8 ( V_24 , ( V_29 ) T_2 , ( T_5 ) T_3 , 0xFF ) ;
} else {
F_9 ( V_9 , T_2 , ( T_5 ) T_3 ) ;
}
F_3 ( T_2 , T_3 , T_4 ) ;
}
while ( T_3 != 0xDEAD && T_4 < V_16 - 2 )
F_3 ( T_2 , T_3 , T_4 ) ;
}
}
}
if ( V_19 ) {
if ( ! F_10 ( V_9 -> V_22 , V_24 , 1000 , V_25 ) ) {
F_6 ( L_2 ) ;
V_26 = V_28 ;
}
}
return V_26 ;
}
