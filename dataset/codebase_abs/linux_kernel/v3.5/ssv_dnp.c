static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_6 -> V_8 != 2 )
return - V_9 ;
if ( V_7 [ 0 ] ) {
F_2 ( V_10 , V_11 ) ;
F_2 ( ( F_3 ( V_12 )
& ~ ( V_13 ) ( V_7 [ 0 ] & 0x0000FF ) )
| ( V_13 ) ( V_7 [ 1 ] & 0x0000FF ) , V_12 ) ;
F_2 ( V_14 , V_11 ) ;
F_2 ( ( F_3 ( V_12 )
& ~ ( V_13 ) ( ( V_7 [ 0 ] & 0x00FF00 ) >> 8 ) )
| ( V_13 ) ( ( V_7 [ 1 ] & 0x00FF00 ) >> 8 ) , V_12 ) ;
F_2 ( V_15 , V_11 ) ;
F_2 ( ( F_3 ( V_12 )
& ~ ( V_13 ) ( ( V_7 [ 0 ] & 0x0F0000 ) >> 12 ) )
| ( V_13 ) ( ( V_7 [ 1 ] & 0x0F0000 ) >> 12 ) , V_12 ) ;
}
F_2 ( V_10 , V_11 ) ;
V_7 [ 0 ] = F_3 ( V_12 ) ;
F_2 ( V_14 , V_11 ) ;
V_7 [ 0 ] += F_3 ( V_12 ) << 8 ;
F_2 ( V_15 , V_11 ) ;
V_7 [ 0 ] += ( ( F_3 ( V_12 ) & 0xF0 ) << 12 ) ;
return 2 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_13 V_16 ;
int V_17 = F_5 ( V_6 -> V_18 ) ;
switch ( V_7 [ 0 ] ) {
case V_19 :
case V_20 :
break;
case V_21 :
V_7 [ 1 ] =
( F_3 ( V_12 ) & ( 1 << V_17 ) ) ? V_22 : V_23 ;
return V_6 -> V_8 ;
break;
default:
return - V_9 ;
break;
}
if ( ( V_17 >= 0 ) && ( V_17 <= 7 ) ) {
F_2 ( V_24 , V_11 ) ;
} else if ( ( V_17 >= 8 ) && ( V_17 <= 15 ) ) {
V_17 -= 8 ;
F_2 ( V_25 , V_11 ) ;
} else if ( ( V_17 >= 16 ) && ( V_17 <= 19 ) ) {
V_17 -= 16 ;
V_17 *= 2 ;
F_2 ( V_26 , V_11 ) ;
} else {
return - V_9 ;
}
V_16 = F_3 ( V_12 ) ;
if ( V_7 [ 0 ] == V_22 )
V_16 |= ( 1 << V_17 ) ;
else
V_16 &= ~ ( 1 << V_17 ) ;
F_2 ( V_16 , V_12 ) ;
return 1 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_3 * V_4 ;
F_7 ( V_29 L_1 , V_2 -> V_30 ) ;
V_2 -> V_31 = V_32 -> V_33 ;
if ( F_8 ( V_2 , sizeof( struct V_34 ) ) < 0 )
return - V_35 ;
if ( F_9 ( V_2 , 1 ) < 0 )
return - V_35 ;
V_4 = V_2 -> V_36 + 0 ;
V_4 -> type = V_37 ;
V_4 -> V_38 = V_39 | V_40 ;
V_4 -> V_41 = 20 ;
V_4 -> V_42 = 1 ;
V_4 -> V_43 = & V_44 ;
V_4 -> V_45 = F_1 ;
V_4 -> V_46 = F_4 ;
F_7 ( L_2 ) ;
F_2 ( V_24 , V_11 ) ;
F_2 ( 0x00 , V_12 ) ;
F_2 ( V_25 , V_11 ) ;
F_2 ( 0x00 , V_12 ) ;
F_2 ( V_26 , V_11 ) ;
F_2 ( ( F_3 ( V_12 ) & 0xAA ) , V_12 ) ;
return 1 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_2 ( V_24 , V_11 ) ;
F_2 ( 0x00 , V_12 ) ;
F_2 ( V_25 , V_11 ) ;
F_2 ( 0x00 , V_12 ) ;
F_2 ( V_26 , V_11 ) ;
F_2 ( ( F_3 ( V_12 ) & 0xAA ) , V_12 ) ;
}
