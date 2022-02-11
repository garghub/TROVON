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
#define F_3 ( T_2 , T_3 , T_4 ) do \
{ i += 2; v1 = Array[i]; \
v2 = Array[i+1]; } while (0)
T_1 V_10 = 0 ;
T_1 T_4 = 0 ;
T_5 V_11 = V_9 -> V_12 ;
T_5 V_13 = V_9 -> V_14 ;
T_5 V_15 = V_9 -> V_16 ;
T_1 V_17 = sizeof( V_18 ) / sizeof( T_1 ) ;
T_1 * V_19 = V_18 ;
bool V_20 = false ;
struct V_21 * V_22 = V_9 -> V_22 ;
struct V_23 * V_24 = NULL ;
T_5 V_25 = 1 ;
enum V_7 V_26 = V_27 ;
V_10 += V_15 ;
V_10 += V_13 << 8 ;
V_10 += V_11 << 16 ;
V_10 += 0xFF000000 ;
V_20 = F_4 ( V_22 ) ;
if ( V_20 ) {
V_24 = F_5 ( V_22 ) ;
if ( V_24 == NULL ) {
F_6 ( L_1 ) ;
return V_28 ;
}
}
for ( T_4 = 0 ; T_4 < V_17 ; T_4 += 2 ) {
T_1 T_2 = V_19 [ T_4 ] ;
T_1 T_3 = V_19 [ T_4 + 1 ] ;
if ( T_2 < 0xCDCDCDCD ) {
if ( V_20 ) {
if ( F_7 ( V_24 ) )
V_25 ++ ;
if ( T_2 == 0xffe )
F_8 ( V_24 , 50 ) ;
else if ( T_2 == 0xfd )
F_8 ( V_24 , 5 ) ;
else if ( T_2 == 0xfc )
F_8 ( V_24 , 1 ) ;
else if ( T_2 == 0xfb )
F_9 ( V_24 , 50 ) ;
else if ( T_2 == 0xfa )
F_9 ( V_24 , 5 ) ;
else if ( T_2 == 0xf9 )
F_9 ( V_24 , 1 ) ;
else
F_10 ( V_24 , V_29 , ( V_30 ) T_2 , T_3 , V_31 ) ;
} else {
F_11 ( V_9 , T_2 , T_3 ) ;
}
continue;
} else {
if ( ! F_1 ( V_19 [ T_4 ] , V_10 ) ) {
F_3 ( T_2 , T_3 , T_4 ) ;
while ( T_3 != 0xDEAD &&
T_3 != 0xCDEF &&
T_3 != 0xCDCD && T_4 < V_17 - 2 )
F_3 ( T_2 , T_3 , T_4 ) ;
T_4 -= 2 ;
} else {
F_3 ( T_2 , T_3 , T_4 ) ;
while ( T_3 != 0xDEAD &&
T_3 != 0xCDEF &&
T_3 != 0xCDCD && T_4 < V_17 - 2 ) {
if ( V_20 ) {
if ( F_7 ( V_24 ) )
V_25 ++ ;
if ( T_2 == 0xffe )
F_8 ( V_24 , 50 ) ;
else if ( T_2 == 0xfd )
F_8 ( V_24 , 5 ) ;
else if ( T_2 == 0xfc )
F_8 ( V_24 , 1 ) ;
else if ( T_2 == 0xfb )
F_9 ( V_24 , 50 ) ;
else if ( T_2 == 0xfa )
F_9 ( V_24 , 5 ) ;
else if ( T_2 == 0xf9 )
F_9 ( V_24 , 1 ) ;
else
F_10 ( V_24 , V_29 , ( V_30 ) T_2 , T_3 , V_31 ) ;
} else {
F_11 ( V_9 , T_2 , T_3 ) ;
}
F_3 ( T_2 , T_3 , T_4 ) ;
}
while ( T_3 != 0xDEAD && T_4 < V_17 - 2 )
F_3 ( T_2 , T_3 , T_4 ) ;
}
}
}
if ( V_20 ) {
if ( ! F_12 ( V_9 -> V_22 , V_24 , 1000 , V_25 ) ) {
V_26 = V_28 ;
F_6 ( L_2 , V_32 ) ;
}
}
return V_26 ;
}
