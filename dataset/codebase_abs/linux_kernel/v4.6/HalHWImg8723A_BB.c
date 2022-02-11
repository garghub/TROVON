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
T_1 V_9 ;
T_1 V_10 ;
T_2 V_11 = 0x04 ;
T_2 V_12 = V_8 -> V_13 ;
T_1 V_14 = F_3 ( V_15 ) ;
T_1 * V_16 = V_15 ;
V_9 = V_12 ;
V_9 += V_17 << 8 ;
V_9 += V_11 << 16 ;
V_9 += 0xFF000000 ;
for ( V_10 = 0 ; V_10 < V_14 ; V_10 += 2 ) {
T_1 V_18 = V_16 [ V_10 ] ;
T_1 V_19 = V_16 [ V_10 + 1 ] ;
if ( V_18 < 0xCDCDCDCD ) {
F_4 ( V_8 , V_18 , V_19 ) ;
continue;
} else {
if ( ! F_1 ( V_16 [ V_10 ] , V_9 ) ) {
F_5 ( V_18 , V_19 , V_10 ) ;
while ( V_19 != 0xDEAD &&
V_19 != 0xCDEF &&
V_19 != 0xCDCD && V_10 < V_14 - 2 )
F_5 ( V_18 , V_19 , V_10 ) ;
V_10 -= 2 ;
} else {
F_5 ( V_18 , V_19 , V_10 ) ;
while ( V_19 != 0xDEAD &&
V_19 != 0xCDEF &&
V_19 != 0xCDCD && V_10 < V_14 - 2 ) {
F_4 ( V_8 , V_18 , V_19 ) ;
F_5 ( V_18 , V_19 , V_10 ) ;
}
while ( V_19 != 0xDEAD && V_10 < V_14 - 2 )
F_5 ( V_18 , V_19 , V_10 ) ;
}
}
}
}
void F_6 ( struct V_7 * V_8 )
{
T_1 V_9 = 0 ;
T_1 V_10 = 0 ;
T_2 V_11 = 0x04 ;
T_2 V_12 = V_8 -> V_13 ;
T_1 V_14 = F_3 ( V_20 ) ;
T_1 * V_16 = V_20 ;
V_9 += V_12 ;
V_9 += V_17 << 8 ;
V_9 += V_11 << 16 ;
V_9 += 0xFF000000 ;
for ( V_10 = 0 ; V_10 < V_14 ; V_10 += 2 ) {
T_1 V_18 = V_16 [ V_10 ] ;
T_1 V_19 = V_16 [ V_10 + 1 ] ;
if ( V_18 < 0xCDCDCDCD ) {
F_7 ( V_8 , V_18 , V_19 ) ;
continue;
} else {
if ( ! F_1 ( V_16 [ V_10 ] , V_9 ) ) {
F_5 ( V_18 , V_19 , V_10 ) ;
while ( V_19 != 0xDEAD &&
V_19 != 0xCDEF &&
V_19 != 0xCDCD && V_10 < V_14 - 2 )
F_5 ( V_18 , V_19 , V_10 ) ;
V_10 -= 2 ;
} else {
F_5 ( V_18 , V_19 , V_10 ) ;
while ( V_19 != 0xDEAD &&
V_19 != 0xCDEF &&
V_19 != 0xCDCD && V_10 < V_14 - 2 ) {
F_7 ( V_8 , V_18 , V_19 ) ;
F_5 ( V_18 , V_19 , V_10 ) ;
}
while ( V_19 != 0xDEAD && V_10 < V_14 - 2 )
F_5 ( V_18 , V_19 , V_10 ) ;
}
}
}
}
void F_8 ( struct V_7 * V_8 )
{
T_1 V_9 = 0 ;
T_1 V_10 ;
T_2 V_11 = 0x04 ;
T_2 V_12 = V_8 -> V_13 ;
T_1 V_14 = F_3 ( V_21 ) ;
T_1 * V_16 = V_21 ;
V_9 += V_12 ;
V_9 += V_17 << 8 ;
V_9 += V_11 << 16 ;
V_9 += 0xFF000000 ;
for ( V_10 = 0 ; V_10 < V_14 ; V_10 += 2 ) {
T_1 V_18 = V_16 [ V_10 ] ;
T_1 V_19 = V_16 [ V_10 + 1 ] ;
if ( V_18 < 0xCDCDCDCD ) {
F_7 ( V_8 , V_18 , V_19 ) ;
continue;
} else {
if ( ! F_1 ( V_16 [ V_10 ] , V_9 ) ) {
F_5 ( V_18 , V_19 , V_10 ) ;
while ( V_19 != 0xDEAD &&
V_19 != 0xCDEF &&
V_19 != 0xCDCD && V_10 < V_14 - 2 )
F_5 ( V_18 , V_19 , V_10 ) ;
V_10 -= 2 ;
} else {
F_5 ( V_18 , V_19 , V_10 ) ;
while ( V_19 != 0xDEAD &&
V_19 != 0xCDEF &&
V_19 != 0xCDCD && V_10 < V_14 - 2 ) {
F_7 ( V_8 , V_18 , V_19 ) ;
F_5 ( V_18 , V_19 , V_10 ) ;
}
while ( V_19 != 0xDEAD && V_10 < V_14 - 2 )
F_5 ( V_18 , V_19 , V_10 ) ;
}
}
}
}
