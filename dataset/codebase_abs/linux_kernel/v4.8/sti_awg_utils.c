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
V_2 &= V_16 ;
break;
case V_17 :
case V_18 :
if ( V_2 == 0 ) {
return 0 ;
}
V_8 = 0 ;
V_9 = 0 ;
V_2 &= V_16 ;
break;
case V_19 :
V_8 = 0 ;
V_9 = 0 ;
V_2 |= 0x40 ;
V_2 &= V_16 ;
break;
case V_20 :
V_2 = 0 ;
break;
case V_15 :
case V_21 :
case V_22 :
case V_23 :
V_2 &= ( 0x0ff ) ;
break;
default:
F_2 ( L_2 , V_1 ) ;
return - V_13 ;
}
V_10 = V_10 - V_2 ;
V_2 = ( ( V_2 + V_8 ) + V_9 ) ;
V_7 = ( ( V_1 ) << V_24 ) | V_2 ;
V_6 -> V_25 [ V_6 -> V_11 ] =
V_7 & ( 0x3fff ) ;
V_6 -> V_11 ++ ;
}
return 0 ;
}
static int F_3 (
struct V_5 * V_6 ,
struct V_26 * V_27 )
{
long int V_28 ;
int V_29 = 0 ;
if ( V_27 -> V_30 > 0 ) {
V_28 = V_27 -> V_31 ;
V_29 |= F_1 ( V_22 , V_28 , 0 , 0 , V_6 ) ;
V_28 = V_27 -> V_30 - 1 + V_32 ;
V_29 |= F_1 ( V_14 , V_28 , 0 , 0 , V_6 ) ;
}
V_28 = V_27 -> V_31 ;
V_29 |= F_1 ( ( V_27 -> V_30 > 0 ) ? V_15 : V_22 ,
V_28 , 0 , 1 , V_6 ) ;
if ( V_27 -> V_33 > 0 ) {
V_28 = V_27 -> V_34 - 1 ;
V_29 |= F_1 ( V_14 , V_28 , 0 , 1 , V_6 ) ;
V_28 = V_27 -> V_31 ;
V_29 |= F_1 ( V_15 , V_28 , 0 , 0 , V_6 ) ;
}
return V_29 ;
}
int F_4 (
struct V_5 * V_6 ,
struct V_26 * V_27 )
{
long int V_28 , V_35 ;
int V_29 = 0 ;
if ( V_27 -> V_36 > 0 ) {
V_28 = V_27 -> V_31 ;
V_29 |= F_1 ( V_22 , V_28 , 0 , 0 , V_6 ) ;
V_28 = V_27 -> V_36 - 1 ;
V_29 |= F_1 ( V_18 , V_28 , 0 , 0 , V_6 ) ;
}
V_35 = V_27 -> V_37 - 1 ;
while ( V_35 > 0 ) {
V_29 |= F_3 ( V_6 , V_27 ) ;
V_29 |= F_1 ( V_18 ,
F_5 ( int , V_16 , V_35 ) ,
0 , 0 , V_6 ) ;
V_35 -= V_16 ;
}
if ( V_27 -> V_38 > 0 ) {
V_28 = V_27 -> V_31 ;
V_29 |= F_1 ( V_22 , V_28 , 0 , 0 , V_6 ) ;
V_28 = V_27 -> V_38 - 1 ;
V_29 |= F_1 ( V_18 , V_28 , 0 , 0 , V_6 ) ;
}
return V_29 ;
}
