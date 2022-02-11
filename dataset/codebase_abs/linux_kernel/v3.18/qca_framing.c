T_1
F_1 ( T_2 * V_1 , T_1 V_2 )
{
T_3 V_3 ;
if ( ! V_1 )
return 0 ;
V_3 = F_2 ( V_2 ) ;
V_1 [ 0 ] = 0xAA ;
V_1 [ 1 ] = 0xAA ;
V_1 [ 2 ] = 0xAA ;
V_1 [ 3 ] = 0xAA ;
V_1 [ 4 ] = V_3 & 0xff ;
V_1 [ 5 ] = ( V_3 >> 8 ) & 0xff ;
V_1 [ 6 ] = 0 ;
V_1 [ 7 ] = 0 ;
return V_4 ;
}
T_1
F_3 ( T_2 * V_1 )
{
if ( ! V_1 )
return 0 ;
V_1 [ 0 ] = 0x55 ;
V_1 [ 1 ] = 0x55 ;
return V_5 ;
}
T_4
F_4 ( struct V_6 * V_7 , T_2 * V_1 , T_1 V_8 , T_2 V_9 )
{
T_4 V_10 = V_11 ;
T_1 V_3 ;
switch ( V_7 -> V_12 ) {
case V_13 :
case V_14 :
V_7 -> V_12 -- ;
if ( V_9 != 0x00 ) {
V_7 -> V_12 = V_13 ;
}
break;
case V_15 :
case V_16 :
V_7 -> V_12 -- ;
break;
case V_17 :
case V_18 :
case V_19 :
case V_20 :
if ( V_9 != 0xAA ) {
V_10 = V_21 ;
V_7 -> V_12 = V_13 ;
} else {
V_7 -> V_12 -- ;
}
break;
case V_22 :
V_7 -> V_23 = V_9 ;
V_7 -> V_12 = V_24 ;
break;
case V_24 :
V_7 -> V_23 = V_7 -> V_23 | ( V_9 << 8 ) ;
V_7 -> V_12 = V_25 ;
break;
case V_25 :
V_7 -> V_12 = V_26 ;
break;
case V_26 :
V_3 = V_7 -> V_23 ;
if ( V_3 > V_8 || V_3 < V_27 ) {
V_10 = V_28 ;
V_7 -> V_12 = V_13 ;
} else {
V_7 -> V_12 = (enum V_29 ) ( V_3 + 1 ) ;
V_7 -> V_23 = 0 ;
}
break;
default:
V_1 [ V_7 -> V_23 ] = V_9 ;
V_7 -> V_23 ++ ;
V_7 -> V_12 -- ;
break;
case V_30 :
if ( V_9 != 0x55 ) {
V_10 = V_31 ;
V_7 -> V_12 = V_13 ;
} else {
V_7 -> V_12 = V_32 ;
}
break;
case V_32 :
if ( V_9 != 0x55 ) {
V_10 = V_31 ;
V_7 -> V_12 = V_13 ;
} else {
V_10 = V_7 -> V_23 ;
V_7 -> V_12 = V_13 ;
}
break;
}
return V_10 ;
}
