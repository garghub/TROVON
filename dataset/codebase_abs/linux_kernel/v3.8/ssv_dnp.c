static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_7 [ 0 ] ) {
F_2 ( V_8 , V_9 ) ;
F_2 ( ( F_3 ( V_10 )
& ~ ( V_11 ) ( V_7 [ 0 ] & 0x0000FF ) )
| ( V_11 ) ( V_7 [ 1 ] & 0x0000FF ) , V_10 ) ;
F_2 ( V_12 , V_9 ) ;
F_2 ( ( F_3 ( V_10 )
& ~ ( V_11 ) ( ( V_7 [ 0 ] & 0x00FF00 ) >> 8 ) )
| ( V_11 ) ( ( V_7 [ 1 ] & 0x00FF00 ) >> 8 ) , V_10 ) ;
F_2 ( V_13 , V_9 ) ;
F_2 ( ( F_3 ( V_10 )
& ~ ( V_11 ) ( ( V_7 [ 0 ] & 0x0F0000 ) >> 12 ) )
| ( V_11 ) ( ( V_7 [ 1 ] & 0x0F0000 ) >> 12 ) , V_10 ) ;
}
F_2 ( V_8 , V_9 ) ;
V_7 [ 0 ] = F_3 ( V_10 ) ;
F_2 ( V_12 , V_9 ) ;
V_7 [ 0 ] += F_3 ( V_10 ) << 8 ;
F_2 ( V_13 , V_9 ) ;
V_7 [ 0 ] += ( ( F_3 ( V_10 ) & 0xF0 ) << 12 ) ;
return V_6 -> V_14 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_11 V_15 ;
int V_16 = F_5 ( V_6 -> V_17 ) ;
switch ( V_7 [ 0 ] ) {
case V_18 :
case V_19 :
break;
case V_20 :
V_7 [ 1 ] =
( F_3 ( V_10 ) & ( 1 << V_16 ) ) ? V_21 : V_22 ;
return V_6 -> V_14 ;
break;
default:
return - V_23 ;
break;
}
if ( ( V_16 >= 0 ) && ( V_16 <= 7 ) ) {
F_2 ( V_24 , V_9 ) ;
} else if ( ( V_16 >= 8 ) && ( V_16 <= 15 ) ) {
V_16 -= 8 ;
F_2 ( V_25 , V_9 ) ;
} else if ( ( V_16 >= 16 ) && ( V_16 <= 19 ) ) {
V_16 -= 16 ;
V_16 *= 2 ;
F_2 ( V_26 , V_9 ) ;
} else {
return - V_23 ;
}
V_15 = F_3 ( V_10 ) ;
if ( V_7 [ 0 ] == V_21 )
V_15 |= ( 1 << V_16 ) ;
else
V_15 &= ~ ( 1 << V_16 ) ;
F_2 ( V_15 , V_10 ) ;
return 1 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_3 * V_4 ;
int V_29 ;
V_2 -> V_30 = V_2 -> V_31 -> V_32 ;
V_29 = F_7 ( V_2 , 1 ) ;
if ( V_29 )
return V_29 ;
V_4 = & V_2 -> V_33 [ 0 ] ;
V_4 -> type = V_34 ;
V_4 -> V_35 = V_36 | V_37 ;
V_4 -> V_38 = 20 ;
V_4 -> V_39 = 1 ;
V_4 -> V_40 = & V_41 ;
V_4 -> V_42 = F_1 ;
V_4 -> V_43 = F_4 ;
F_2 ( V_24 , V_9 ) ;
F_2 ( 0x00 , V_10 ) ;
F_2 ( V_25 , V_9 ) ;
F_2 ( 0x00 , V_10 ) ;
F_2 ( V_26 , V_9 ) ;
F_2 ( ( F_3 ( V_10 ) & 0xAA ) , V_10 ) ;
F_8 ( V_2 -> V_44 , L_1 , V_2 -> V_30 ) ;
return 1 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_2 ( V_24 , V_9 ) ;
F_2 ( 0x00 , V_10 ) ;
F_2 ( V_25 , V_9 ) ;
F_2 ( 0x00 , V_10 ) ;
F_2 ( V_26 , V_9 ) ;
F_2 ( ( F_3 ( V_10 ) & 0xAA ) , V_10 ) ;
}
