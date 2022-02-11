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
unsigned int F_5 ( T_4 V_13 , T_2 V_2 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_13 -> V_14 ; V_4 ++ ) {
if ( V_13 -> V_15 [ V_4 ] . V_16 &&
F_3 ( V_13 -> V_15 [ V_4 ] . V_11 ,
V_2 -> V_11 ) ) {
return V_4 ;
}
}
return V_13 -> V_14 ;
}
unsigned int F_6 ( T_4 V_13 , T_2 V_2 )
{
unsigned int V_4 ;
if ( V_13 -> V_17 == 0 )
return V_13 -> V_14 ;
for ( V_4 = 0 ; V_4 < V_13 -> V_14 ; V_4 ++ ) {
if ( ! V_13 -> V_15 [ V_4 ] . V_16 ) {
V_13 -> V_17 -- ;
V_13 -> V_15 [ V_4 ] . V_18 = V_13 -> V_19 ;
V_13 -> V_15 [ V_4 ] . V_16 = true ;
V_13 -> V_15 [ V_4 ] . V_20 = ( V_2 -> V_10 >> 4 ) ;
V_13 -> V_15 [ V_4 ] . V_21 = ( V_2 -> V_10 & 0x000F ) ;
memcpy ( & ( V_13 -> V_15 [ V_4 ] . V_11 [ 0 ] ) , & ( V_2 -> V_11 [ 0 ] ) , V_12 ) ;
return V_4 ;
}
}
return V_13 -> V_14 ;
}
bool F_7 ( T_4 V_13 , T_2 V_2 , unsigned int V_22 , bool V_23 , bool V_24 )
{
unsigned int V_25 ;
if ( V_23 ) {
V_25 = 28 ;
if ( V_24 )
V_25 += 4 ;
} else {
V_25 = 24 ;
}
if ( F_8 ( V_2 ) ) {
V_13 -> V_26 = F_5 ( V_13 , V_2 ) ;
if ( V_13 -> V_26 < V_13 -> V_14 ) {
V_13 -> V_15 [ V_13 -> V_26 ] . V_18 = V_13 -> V_19 ;
V_13 -> V_15 [ V_13 -> V_26 ] . V_20 = ( V_2 -> V_10 >> 4 ) ;
V_13 -> V_15 [ V_13 -> V_26 ] . V_21 = ( V_2 -> V_10 & 0x000F ) ;
} else {
V_13 -> V_26 = F_6 ( V_13 , V_2 ) ;
if ( V_13 -> V_26 == V_13 -> V_14 )
return false ;
}
V_13 -> V_15 [ V_13 -> V_26 ] . V_27 = ( unsigned char * ) ( V_13 -> V_15 [ V_13 -> V_26 ] . V_28 -> V_29 + 4 ) ;
memcpy ( V_13 -> V_15 [ V_13 -> V_26 ] . V_27 , V_2 , V_22 ) ;
V_13 -> V_15 [ V_13 -> V_26 ] . V_22 = V_22 ;
V_13 -> V_15 [ V_13 -> V_26 ] . V_27 += V_22 ;
V_13 -> V_15 [ V_13 -> V_26 ] . V_21 ++ ;
return false ;
} else {
V_13 -> V_26 = F_5 ( V_13 , V_2 ) ;
if ( V_13 -> V_26 != V_13 -> V_14 ) {
if ( ( V_13 -> V_15 [ V_13 -> V_26 ] . V_20 == ( V_2 -> V_10 >> 4 ) ) &&
( V_13 -> V_15 [ V_13 -> V_26 ] . V_21 == ( V_2 -> V_10 & 0x000F ) ) &&
( ( V_13 -> V_15 [ V_13 -> V_26 ] . V_22 + V_22 - V_25 ) < 2346 ) ) {
memcpy ( V_13 -> V_15 [ V_13 -> V_26 ] . V_27 , ( ( unsigned char * ) ( V_2 ) + V_25 ) , ( V_22 - V_25 ) ) ;
V_13 -> V_15 [ V_13 -> V_26 ] . V_22 += ( V_22 - V_25 ) ;
V_13 -> V_15 [ V_13 -> V_26 ] . V_27 += ( V_22 - V_25 ) ;
V_13 -> V_15 [ V_13 -> V_26 ] . V_21 ++ ;
} else {
V_13 -> V_17 ++ ;
V_13 -> V_15 [ V_13 -> V_26 ] . V_16 = false ;
return false ;
}
} else {
return false ;
}
if ( F_9 ( V_2 ) ) {
V_13 -> V_17 ++ ;
V_13 -> V_15 [ V_13 -> V_26 ] . V_16 = false ;
return true ;
}
return false ;
}
}
