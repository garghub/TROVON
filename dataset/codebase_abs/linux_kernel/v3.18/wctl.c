bool F_1 ( T_1 V_1 , T_2 V_2 )
{
unsigned int V_3 ;
unsigned int V_4 ;
T_3 V_5 ;
if ( F_2 ( V_2 ) ) {
V_3 = V_1 -> V_6 ;
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ ) {
V_5 = & ( V_1 -> V_8 [ V_3 ] ) ;
if ( ( V_5 -> V_9 == V_2 -> V_10 ) &&
F_3 ( V_5 -> V_11 ,
V_2 -> V_11 ) ) {
return true ;
}
F_4 ( V_3 , V_7 ) ;
}
}
V_5 = & V_1 -> V_8 [ V_1 -> V_6 ] ;
V_5 -> V_9 = V_2 -> V_10 ;
memcpy ( & ( V_5 -> V_11 [ 0 ] ) , & ( V_2 -> V_11 [ 0 ] ) , V_12 ) ;
F_4 ( V_1 -> V_6 , V_7 ) ;
return false ;
}
unsigned int F_5 ( struct V_13 * V_14 ,
T_2 V_2 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_14 -> V_15 ; V_4 ++ ) {
if ( V_14 -> V_16 [ V_4 ] . V_17 &&
F_3 ( V_14 -> V_16 [ V_4 ] . V_11 ,
V_2 -> V_11 ) ) {
return V_4 ;
}
}
return V_14 -> V_15 ;
}
unsigned int F_6 ( struct V_13 * V_14 , T_2 V_2 )
{
unsigned int V_4 ;
if ( V_14 -> V_18 == 0 )
return V_14 -> V_15 ;
for ( V_4 = 0 ; V_4 < V_14 -> V_15 ; V_4 ++ ) {
if ( ! V_14 -> V_16 [ V_4 ] . V_17 ) {
V_14 -> V_18 -- ;
V_14 -> V_16 [ V_4 ] . V_19 = V_14 -> V_20 ;
V_14 -> V_16 [ V_4 ] . V_17 = true ;
V_14 -> V_16 [ V_4 ] . V_21 = ( V_2 -> V_10 >> 4 ) ;
V_14 -> V_16 [ V_4 ] . V_22 = ( V_2 -> V_10 & 0x000F ) ;
memcpy ( & ( V_14 -> V_16 [ V_4 ] . V_11 [ 0 ] ) , & ( V_2 -> V_11 [ 0 ] ) , V_12 ) ;
return V_4 ;
}
}
return V_14 -> V_15 ;
}
bool F_7 ( struct V_13 * V_14 , T_2 V_2 ,
unsigned int V_23 , bool V_24 , bool V_25 )
{
unsigned int V_26 ;
if ( V_24 ) {
V_26 = 28 ;
if ( V_25 )
V_26 += 4 ;
} else {
V_26 = 24 ;
}
if ( F_8 ( V_2 ) ) {
V_14 -> V_27 = F_5 ( V_14 , V_2 ) ;
if ( V_14 -> V_27 < V_14 -> V_15 ) {
V_14 -> V_16 [ V_14 -> V_27 ] . V_19 = V_14 -> V_20 ;
V_14 -> V_16 [ V_14 -> V_27 ] . V_21 = ( V_2 -> V_10 >> 4 ) ;
V_14 -> V_16 [ V_14 -> V_27 ] . V_22 = ( V_2 -> V_10 & 0x000F ) ;
} else {
V_14 -> V_27 = F_6 ( V_14 , V_2 ) ;
if ( V_14 -> V_27 == V_14 -> V_15 )
return false ;
}
V_14 -> V_16 [ V_14 -> V_27 ] . V_28 = ( unsigned char * ) ( V_14 -> V_16 [ V_14 -> V_27 ] . V_29 -> V_30 + 4 ) ;
memcpy ( V_14 -> V_16 [ V_14 -> V_27 ] . V_28 , V_2 , V_23 ) ;
V_14 -> V_16 [ V_14 -> V_27 ] . V_23 = V_23 ;
V_14 -> V_16 [ V_14 -> V_27 ] . V_28 += V_23 ;
V_14 -> V_16 [ V_14 -> V_27 ] . V_22 ++ ;
return false ;
} else {
V_14 -> V_27 = F_5 ( V_14 , V_2 ) ;
if ( V_14 -> V_27 != V_14 -> V_15 ) {
if ( ( V_14 -> V_16 [ V_14 -> V_27 ] . V_21 == ( V_2 -> V_10 >> 4 ) ) &&
( V_14 -> V_16 [ V_14 -> V_27 ] . V_22 == ( V_2 -> V_10 & 0x000F ) ) &&
( ( V_14 -> V_16 [ V_14 -> V_27 ] . V_23 + V_23 - V_26 ) < 2346 ) ) {
memcpy ( V_14 -> V_16 [ V_14 -> V_27 ] . V_28 , ( ( unsigned char * ) ( V_2 ) + V_26 ) , ( V_23 - V_26 ) ) ;
V_14 -> V_16 [ V_14 -> V_27 ] . V_23 += ( V_23 - V_26 ) ;
V_14 -> V_16 [ V_14 -> V_27 ] . V_28 += ( V_23 - V_26 ) ;
V_14 -> V_16 [ V_14 -> V_27 ] . V_22 ++ ;
} else {
V_14 -> V_18 ++ ;
V_14 -> V_16 [ V_14 -> V_27 ] . V_17 = false ;
return false ;
}
} else {
return false ;
}
if ( F_9 ( V_2 ) ) {
V_14 -> V_18 ++ ;
V_14 -> V_16 [ V_14 -> V_27 ] . V_17 = false ;
return true ;
}
return false ;
}
}
