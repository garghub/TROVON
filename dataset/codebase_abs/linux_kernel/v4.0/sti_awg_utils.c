static int F_1 ( enum V_1 V_1 ,
long int V_2 ,
long int V_3 ,
long int V_4 ,
struct V_5 * V_6 )
{
T_1 V_7 = 0 ;
T_1 V_8 = ( V_3 << 8 ) & 0x1ff ;
T_1 V_9 = ( V_4 << 9 ) & 0x2ff ;
long int V_10 = V_2 ;
while ( V_10 > 0 ) {
V_2 = V_10 ;
if ( V_6 -> V_11 >= V_12 ) {
F_2 ( L_1 ) ;
return - V_13 ;
}
switch ( V_1 ) {
case V_14 :
V_2 -- ;
V_10 -- ;
if ( V_2 < 0 ) {
return 0 ;
}
if ( V_2 == 0 ) {
V_1 = V_15 ;
break;
}
V_8 = 0 ;
V_9 = 0 ;
V_2 = ( V_2 << 22 ) >> 22 ;
V_2 &= ( 0x3ff ) ;
break;
case V_16 :
case V_17 :
if ( V_2 == 0 ) {
return 0 ;
}
V_8 = 0 ;
V_9 = 0 ;
V_2 = ( V_2 << 22 ) >> 22 ;
V_2 &= ( 0x3ff ) ;
break;
case V_18 :
V_8 = 0 ;
V_9 = 0 ;
V_2 |= 0x40 ;
V_2 = ( V_2 << 22 ) >> 22 ;
V_2 &= 0x3ff ;
break;
case V_19 :
V_2 = 0 ;
break;
case V_15 :
case V_20 :
case V_21 :
case V_22 :
V_2 = ( V_2 << 24 ) >> 24 ;
V_2 &= ( 0x0ff ) ;
break;
default:
F_2 ( L_2 , V_1 ) ;
return - V_13 ;
}
V_10 = V_10 - V_2 ;
V_2 = ( ( V_2 + V_8 ) + V_9 ) ;
V_7 = ( ( V_1 ) << V_23 ) | V_2 ;
V_6 -> V_24 [ V_6 -> V_11 ] =
V_7 & ( 0x3fff ) ;
V_6 -> V_11 ++ ;
}
return 0 ;
}
int F_3 (
struct V_5 * V_6 ,
struct V_25 * V_26 )
{
long int V_27 ;
long int V_4 ;
int V_28 = 0 ;
if ( V_26 -> V_29 > 0 ) {
V_27 = V_26 -> V_30 ;
V_4 = 0 ;
V_28 |= F_1 ( V_21 , V_27 , 0 , V_4 , V_6 ) ;
V_27 = V_26 -> V_29 - 1 ;
V_4 = 0 ;
V_28 |= F_1 ( V_17 , V_27 , 0 , V_4 , V_6 ) ;
}
if ( V_26 -> V_31 > 0 ) {
V_27 = V_26 -> V_30 ;
V_4 = 0 ;
V_28 |= F_1 ( V_21 , V_27 , 0 , V_4 , V_6 ) ;
V_27 = V_26 -> V_31 - 1 ;
V_4 = 0 ;
V_28 |= F_1 ( V_14 , V_27 , 0 , V_4 , V_6 ) ;
}
V_27 = V_26 -> V_30 ;
V_4 = 1 ;
V_28 |= F_1 ( ( V_26 -> V_31 > 0 ) ? V_15 : V_21 ,
V_27 , 0 , V_4 , V_6 ) ;
if ( V_26 -> V_32 > 0 ) {
V_27 = V_26 -> V_33 - 1 ;
V_4 = 1 ;
V_28 |= F_1 ( V_14 , V_27 , 0 , V_4 , V_6 ) ;
V_27 = V_26 -> V_30 ;
V_4 = 0 ;
V_28 |= F_1 ( V_15 , V_27 , 0 , V_4 , V_6 ) ;
}
V_27 = V_26 -> V_34 - 1 ;
V_4 = 0 ;
V_28 |= F_1 ( V_17 , V_27 , 0 , V_4 , V_6 ) ;
if ( V_26 -> V_35 > 0 ) {
V_27 = V_26 -> V_30 ;
V_4 = 0 ;
V_28 |= F_1 ( V_21 , V_27 , 0 , V_4 , V_6 ) ;
V_27 = V_26 -> V_35 - 1 ;
V_4 = 0 ;
V_28 |= F_1 ( V_17 , V_27 , 0 , V_4 , V_6 ) ;
}
return V_28 ;
}
