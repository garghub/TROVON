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
void F_2 ( struct V_7 * V_8 )
{
T_1 V_9 ;
T_1 V_10 ;
T_2 V_11 = 0x04 ;
T_2 V_12 = V_8 -> V_13 ;
T_2 V_14 = V_8 -> V_15 ;
T_1 V_16 = sizeof( V_17 ) / sizeof( T_1 ) ;
T_1 * V_18 = V_17 ;
V_9 = V_14 ;
V_9 += V_12 << 8 ;
V_9 += V_11 << 16 ;
V_9 += 0xFF000000 ;
for ( V_10 = 0 ; V_10 < V_16 ; V_10 += 2 ) {
T_1 V_19 = V_18 [ V_10 ] ;
T_1 V_20 = V_18 [ V_10 + 1 ] ;
if ( V_19 < 0xCDCDCDCD ) {
F_3 ( V_8 , V_19 , V_21 , V_20 ) ;
continue;
} else {
if ( ! F_1 ( V_18 [ V_10 ] , V_9 ) ) {
F_4 ( V_19 , V_20 , V_10 ) ;
while ( V_20 != 0xDEAD &&
V_20 != 0xCDEF &&
V_20 != 0xCDCD && V_10 < V_16 - 2 )
F_4 ( V_19 , V_20 , V_10 ) ;
V_10 -= 2 ;
} else {
F_4 ( V_19 , V_20 , V_10 ) ;
while ( V_20 != 0xDEAD &&
V_20 != 0xCDEF &&
V_20 != 0xCDCD && V_10 < V_16 - 2 ) {
F_3 ( V_8 , V_19 , V_21 , V_20 ) ;
F_4 ( V_19 , V_20 , V_10 ) ;
}
while ( V_20 != 0xDEAD && V_10 < V_16 - 2 )
F_4 ( V_19 , V_20 , V_10 ) ;
}
}
}
}
void F_5 ( struct V_7 * V_8 )
{
T_1 V_9 = 0 ;
T_1 V_10 = 0 ;
T_2 V_11 = 0x04 ;
T_2 V_12 = V_8 -> V_13 ;
T_2 V_14 = V_8 -> V_15 ;
T_1 V_16 = sizeof( V_22 ) / sizeof( T_1 ) ;
T_1 * V_18 = V_22 ;
V_9 += V_14 ;
V_9 += V_12 << 8 ;
V_9 += V_11 << 16 ;
V_9 += 0xFF000000 ;
for ( V_10 = 0 ; V_10 < V_16 ; V_10 += 2 ) {
T_1 V_19 = V_18 [ V_10 ] ;
T_1 V_20 = V_18 [ V_10 + 1 ] ;
if ( V_19 < 0xCDCDCDCD ) {
F_6 ( V_8 , V_19 , V_21 , V_20 ) ;
continue;
} else {
if ( ! F_1 ( V_18 [ V_10 ] , V_9 ) ) {
F_4 ( V_19 , V_20 , V_10 ) ;
while ( V_20 != 0xDEAD &&
V_20 != 0xCDEF &&
V_20 != 0xCDCD && V_10 < V_16 - 2 )
F_4 ( V_19 , V_20 , V_10 ) ;
V_10 -= 2 ;
} else {
F_4 ( V_19 , V_20 , V_10 ) ;
while ( V_20 != 0xDEAD &&
V_20 != 0xCDEF &&
V_20 != 0xCDCD && V_10 < V_16 - 2 ) {
F_6 ( V_8 , V_19 , V_21 , V_20 ) ;
F_4 ( V_19 , V_20 , V_10 ) ;
}
while ( V_20 != 0xDEAD && V_10 < V_16 - 2 )
F_4 ( V_19 , V_20 , V_10 ) ;
}
}
}
}
void F_7 ( struct V_7 * V_8 )
{
T_1 V_9 = 0 ;
T_1 V_10 = 0 ;
T_2 V_11 = 0x04 ;
T_2 V_12 = V_8 -> V_13 ;
T_2 V_14 = V_8 -> V_15 ;
T_1 V_16 = sizeof( V_23 ) / sizeof( T_1 ) ;
T_1 * V_18 = V_23 ;
V_9 += V_14 ;
V_9 += V_12 << 8 ;
V_9 += V_11 << 16 ;
V_9 += 0xFF000000 ;
for ( V_10 = 0 ; V_10 < V_16 ; V_10 += 2 ) {
T_1 V_19 = V_18 [ V_10 ] ;
T_1 V_20 = V_18 [ V_10 + 1 ] ;
if ( V_19 < 0xCDCDCDCD ) {
F_6 ( V_8 , V_19 , V_21 , V_20 ) ;
continue;
} else {
if ( ! F_1 ( V_18 [ V_10 ] , V_9 ) ) {
F_4 ( V_19 , V_20 , V_10 ) ;
while ( V_20 != 0xDEAD &&
V_20 != 0xCDEF &&
V_20 != 0xCDCD && V_10 < V_16 - 2 )
F_4 ( V_19 , V_20 , V_10 ) ;
V_10 -= 2 ;
} else {
F_4 ( V_19 , V_20 , V_10 ) ;
while ( V_20 != 0xDEAD &&
V_20 != 0xCDEF &&
V_20 != 0xCDCD && V_10 < V_16 - 2 ) {
F_6 ( V_8 , V_19 , V_21 , V_20 ) ;
F_4 ( V_19 , V_20 , V_10 ) ;
}
while ( V_20 != 0xDEAD && V_10 < V_16 - 2 )
F_4 ( V_19 , V_20 , V_10 ) ;
}
}
}
}
