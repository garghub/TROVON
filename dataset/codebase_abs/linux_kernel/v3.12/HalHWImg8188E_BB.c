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
T_1 V_2 = 0 ;
T_1 V_10 = 0 ;
T_2 V_11 = V_9 -> V_12 ;
T_2 V_13 = V_9 -> V_14 ;
T_2 V_15 = V_9 -> V_16 ;
T_1 V_17 = sizeof( V_18 ) / sizeof( T_1 ) ;
T_1 * V_19 = V_18 ;
bool V_20 = false ;
struct V_21 * V_21 = V_9 -> V_22 ;
struct V_23 * V_24 = NULL ;
T_2 V_25 = 1 ;
enum V_7 V_26 = V_27 ;
V_2 += V_15 ;
V_2 += V_13 << 8 ;
V_2 += V_11 << 16 ;
V_2 += 0xFF000000 ;
V_20 = F_3 ( V_21 ) ;
if ( V_20 ) {
V_24 = F_4 ( V_21 ) ;
if ( V_24 == NULL ) {
F_5 ( L_1 ) ;
return V_28 ;
}
}
for ( V_10 = 0 ; V_10 < V_17 ; V_10 += 2 ) {
T_1 V_29 = V_19 [ V_10 ] ;
T_1 V_30 = V_19 [ V_10 + 1 ] ;
if ( V_29 < 0xCDCDCDCD ) {
if ( V_20 ) {
if ( F_6 ( V_24 ) )
V_25 ++ ;
F_7 ( V_24 , ( V_31 ) V_29 , V_30 , V_32 ) ;
} else {
F_8 ( V_9 , V_29 , V_32 , V_30 ) ;
}
continue;
} else {
if ( ! F_1 ( V_19 [ V_10 ] , V_2 ) ) {
F_9 ( V_19 , V_29 , V_30 , V_10 ) ;
while ( V_30 != 0xDEAD &&
V_30 != 0xCDEF &&
V_30 != 0xCDCD && V_10 < V_17 - 2 )
F_9 ( V_19 , V_29 , V_30 , V_10 ) ;
V_10 -= 2 ;
} else {
F_9 ( V_19 , V_29 , V_30 , V_10 ) ;
while ( V_30 != 0xDEAD &&
V_30 != 0xCDEF &&
V_30 != 0xCDCD && V_10 < V_17 - 2 ) {
if ( V_20 ) {
if ( F_6 ( V_24 ) )
V_25 ++ ;
F_7 ( V_24 , ( V_31 ) V_29 , V_30 , V_32 ) ;
} else {
F_8 ( V_9 , V_29 , V_32 , V_30 ) ;
}
F_9 ( V_19 , V_29 , V_30 , V_10 ) ;
}
while ( V_30 != 0xDEAD && V_10 < V_17 - 2 )
F_9 ( V_19 , V_29 , V_30 , V_10 ) ;
}
}
}
if ( V_20 ) {
if ( ! F_10 ( V_9 -> V_22 , V_24 , 1000 , V_25 ) ) {
F_11 ( L_2 , V_33 ) ;
V_26 = V_28 ;
}
}
return V_26 ;
}
enum V_7 F_12 ( struct V_8 * V_9 )
{
T_1 V_2 = 0 ;
T_1 V_10 = 0 ;
T_2 V_11 = V_9 -> V_12 ;
T_2 V_13 = V_9 -> V_14 ;
T_2 V_15 = V_9 -> V_16 ;
T_1 V_17 = sizeof( V_34 ) / sizeof( T_1 ) ;
T_1 * V_19 = V_34 ;
bool V_20 = false ;
struct V_21 * V_21 = V_9 -> V_22 ;
struct V_23 * V_24 = NULL ;
T_2 V_25 = 1 ;
enum V_7 V_26 = V_27 ;
V_2 += V_15 ;
V_2 += V_13 << 8 ;
V_2 += V_11 << 16 ;
V_2 += 0xFF000000 ;
V_20 = F_3 ( V_21 ) ;
if ( V_20 ) {
V_24 = F_4 ( V_21 ) ;
if ( V_24 == NULL ) {
F_5 ( L_1 ) ;
return V_28 ;
}
}
for ( V_10 = 0 ; V_10 < V_17 ; V_10 += 2 ) {
T_1 V_29 = V_19 [ V_10 ] ;
T_1 V_30 = V_19 [ V_10 + 1 ] ;
if ( V_29 < 0xCDCDCDCD ) {
if ( V_20 ) {
if ( F_6 ( V_24 ) )
V_25 ++ ;
if ( V_29 == 0xfe ) {
F_13 ( V_24 , 50 ) ;
} else if ( V_29 == 0xfd ) {
F_13 ( V_24 , 5 ) ;
} else if ( V_29 == 0xfc ) {
F_13 ( V_24 , 1 ) ;
} else if ( V_29 == 0xfb ) {
F_14 ( V_24 , 50 ) ;
} else if ( V_29 == 0xfa ) {
F_14 ( V_24 , 5 ) ;
} else if ( V_29 == 0xf9 ) {
F_14 ( V_24 , 1 ) ;
} else {
if ( V_29 == 0xa24 )
V_9 -> V_35 . V_36 = V_30 ;
F_7 ( V_24 , ( V_31 ) V_29 , V_30 , V_32 ) ;
}
} else {
F_15 ( V_9 , V_29 , V_32 , V_30 ) ;
}
continue;
} else {
if ( ! F_1 ( V_19 [ V_10 ] , V_2 ) ) {
F_9 ( V_19 , V_29 , V_30 , V_10 ) ;
while ( V_30 != 0xDEAD &&
V_30 != 0xCDEF &&
V_30 != 0xCDCD && V_10 < V_17 - 2 )
F_9 ( V_19 , V_29 , V_30 , V_10 ) ;
V_10 -= 2 ;
} else {
F_9 ( V_19 , V_29 , V_30 , V_10 ) ;
while ( V_30 != 0xDEAD &&
V_30 != 0xCDEF &&
V_30 != 0xCDCD && V_10 < V_17 - 2 ) {
if ( V_20 ) {
if ( F_6 ( V_24 ) )
V_25 ++ ;
if ( V_29 == 0xfe ) {
F_13 ( V_24 , 50 ) ;
} else if ( V_29 == 0xfd ) {
F_13 ( V_24 , 5 ) ;
} else if ( V_29 == 0xfc ) {
F_13 ( V_24 , 1 ) ;
} else if ( V_29 == 0xfb ) {
F_14 ( V_24 , 50 ) ;
} else if ( V_29 == 0xfa ) {
F_14 ( V_24 , 5 ) ;
} else if ( V_29 == 0xf9 ) {
F_14 ( V_24 , 1 ) ;
} else{
if ( V_29 == 0xa24 )
V_9 -> V_35 . V_36 = V_30 ;
F_7 ( V_24 , ( V_31 ) V_29 , V_30 , V_32 ) ;
}
} else {
F_15 ( V_9 , V_29 , V_32 , V_30 ) ;
}
F_9 ( V_19 , V_29 , V_30 , V_10 ) ;
}
while ( V_30 != 0xDEAD && V_10 < V_17 - 2 )
F_9 ( V_19 , V_29 , V_30 , V_10 ) ;
}
}
}
if ( V_20 ) {
if ( ! F_10 ( V_9 -> V_22 , V_24 , 1000 , V_25 ) ) {
V_26 = V_28 ;
F_5 ( L_3 , V_33 ) ;
}
}
return V_26 ;
}
void F_16 ( struct V_8 * V_9 )
{
T_1 V_2 ;
T_1 V_10 = 0 ;
T_2 V_11 = V_9 -> V_12 ;
T_2 V_13 = V_9 -> V_14 ;
T_2 V_15 = V_9 -> V_16 ;
T_1 V_17 = sizeof( V_37 ) / sizeof( T_1 ) ;
T_1 * V_19 = V_37 ;
V_2 = V_15 + ( V_13 << 8 ) ;
V_2 += ( V_11 << 16 ) + 0xFF000000 ;
for ( V_10 = 0 ; V_10 < V_17 ; V_10 += 3 ) {
T_1 V_29 = V_19 [ V_10 ] ;
T_1 V_30 = V_19 [ V_10 + 1 ] ;
T_1 V_38 = V_19 [ V_10 + 2 ] ;
if ( V_29 < 0xCDCDCDCD ) {
F_17 ( V_9 , V_29 , V_30 , V_38 ) ;
continue;
} else {
if ( ! F_1 ( V_19 [ V_10 ] , V_2 ) ) {
V_10 += 2 ;
V_29 = V_19 [ V_10 ] ;
V_30 = V_19 [ V_10 + 1 ] ;
V_38 = V_19 [ V_10 + 2 ] ;
while ( V_30 != 0xDEAD ) {
V_10 += 3 ;
V_29 = V_19 [ V_10 ] ;
V_30 = V_19 [ V_10 + 1 ] ;
V_38 = V_19 [ V_10 + 1 ] ;
}
}
}
}
}
