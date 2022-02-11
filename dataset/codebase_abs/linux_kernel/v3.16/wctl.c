bool F_1 ( T_1 V_1 , struct V_2 * V_3 )
{
unsigned int V_4 ;
unsigned int V_5 ;
T_2 V_6 ;
if ( F_2 ( V_3 ) ) {
V_4 = V_1 -> V_7 ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ ) {
V_6 = & ( V_1 -> V_9 [ V_4 ] ) ;
if ( ( V_6 -> V_10 == V_3 -> V_11 ) &&
F_3 ( V_6 -> V_12 , V_3 -> V_13 ) &&
( V_6 -> V_14 == V_3 -> V_15 )
) {
return true ;
}
F_4 ( V_4 , V_8 ) ;
}
}
V_6 = & V_1 -> V_9 [ V_1 -> V_7 ] ;
V_6 -> V_10 = V_3 -> V_11 ;
memcpy ( & ( V_6 -> V_12 [ 0 ] ) , & ( V_3 -> V_13 [ 0 ] ) , V_16 ) ;
V_6 -> V_14 = V_3 -> V_15 ;
F_4 ( V_1 -> V_7 , V_8 ) ;
return false ;
}
unsigned int F_5 ( struct V_17 * V_18 ,
struct V_2 * V_3 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_18 -> V_19 ; V_5 ++ ) {
if ( ( V_18 -> V_20 [ V_5 ] . V_21 == true ) &&
F_3 ( V_18 -> V_20 [ V_5 ] . V_12 ,
V_3 -> V_13 ) ) {
return V_5 ;
}
}
return V_18 -> V_19 ;
}
unsigned int F_6 ( struct V_17 * V_18 ,
struct V_2 * V_3 )
{
unsigned int V_5 ;
if ( V_18 -> V_22 == 0 )
return ( V_18 -> V_19 ) ;
for ( V_5 = 0 ; V_5 < V_18 -> V_19 ; V_5 ++ ) {
if ( V_18 -> V_20 [ V_5 ] . V_21 == false ) {
V_18 -> V_22 -- ;
V_18 -> V_20 [ V_5 ] . V_23 = V_18 -> V_24 ;
V_18 -> V_20 [ V_5 ] . V_21 = true ;
V_18 -> V_20 [ V_5 ] . V_25 = ( V_3 -> V_11 >> 4 ) ;
V_18 -> V_20 [ V_5 ] . V_26 = ( V_3 -> V_11 & 0x000F ) ;
memcpy ( & ( V_18 -> V_20 [ V_5 ] . V_12 [ 0 ] ) ,
& ( V_3 -> V_13 [ 0 ] ) ,
V_16 ) ;
return ( V_5 ) ;
}
}
return ( V_18 -> V_19 ) ;
}
bool F_7 ( struct V_17 * V_18 , struct V_2 * V_3 , unsigned int V_27 , bool V_28 , bool V_29 )
{
unsigned int V_30 ;
if ( V_28 == true ) {
V_30 = 28 ;
if ( V_29 )
V_30 += 4 ;
}
else {
V_30 = 24 ;
}
if ( F_8 ( V_3 ) ) {
V_18 -> V_31 = F_5 ( V_18 , V_3 ) ;
if ( V_18 -> V_31 < V_18 -> V_19 ) {
V_18 -> V_20 [ V_18 -> V_31 ] . V_23 = V_18 -> V_24 ;
V_18 -> V_20 [ V_18 -> V_31 ] . V_25 = ( V_3 -> V_11 >> 4 ) ;
V_18 -> V_20 [ V_18 -> V_31 ] . V_26 = ( V_3 -> V_11 & 0x000F ) ;
}
else {
V_18 -> V_31 = F_6 ( V_18 , V_3 ) ;
if ( V_18 -> V_31 == V_18 -> V_19 ) {
return ( false ) ;
}
}
V_18 -> V_20 [ V_18 -> V_31 ] . V_32 = ( V_33 * ) ( V_18 -> V_20 [ V_18 -> V_31 ] . V_34 -> V_35 + 8 ) ;
memcpy ( V_18 -> V_20 [ V_18 -> V_31 ] . V_32 , V_3 , V_27 ) ;
V_18 -> V_20 [ V_18 -> V_31 ] . V_27 = V_27 ;
V_18 -> V_20 [ V_18 -> V_31 ] . V_32 += V_27 ;
V_18 -> V_20 [ V_18 -> V_31 ] . V_26 ++ ;
return ( false ) ;
}
else {
V_18 -> V_31 = F_5 ( V_18 , V_3 ) ;
if ( V_18 -> V_31 != V_18 -> V_19 ) {
if ( ( V_18 -> V_20 [ V_18 -> V_31 ] . V_25 == ( V_3 -> V_11 >> 4 ) ) &&
( V_18 -> V_20 [ V_18 -> V_31 ] . V_26 == ( V_3 -> V_11 & 0x000F ) ) &&
( ( V_18 -> V_20 [ V_18 -> V_31 ] . V_27 + V_27 - V_30 ) < 2346 ) ) {
memcpy ( V_18 -> V_20 [ V_18 -> V_31 ] . V_32 , ( ( V_33 * ) ( V_3 ) + V_30 ) , ( V_27 - V_30 ) ) ;
V_18 -> V_20 [ V_18 -> V_31 ] . V_27 += ( V_27 - V_30 ) ;
V_18 -> V_20 [ V_18 -> V_31 ] . V_32 += ( V_27 - V_30 ) ;
V_18 -> V_20 [ V_18 -> V_31 ] . V_26 ++ ;
}
else {
V_18 -> V_22 ++ ;
V_18 -> V_20 [ V_18 -> V_31 ] . V_21 = false ;
return ( false ) ;
}
}
else {
return ( false ) ;
}
if ( F_9 ( V_3 ) ) {
V_18 -> V_22 ++ ;
V_18 -> V_20 [ V_18 -> V_31 ] . V_21 = false ;
return ( true ) ;
}
return ( false ) ;
}
}
