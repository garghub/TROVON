static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 ;
F_6 ( V_8 L_1 , V_3 -> V_9 ) ;
V_3 -> V_10 = V_11 -> V_12 ;
if ( F_7 ( V_3 , sizeof( struct V_13 ) ) < 0 )
return - V_14 ;
if ( F_8 ( V_3 , 1 ) < 0 )
return - V_14 ;
V_7 = V_3 -> V_15 + 0 ;
V_7 -> type = V_16 ;
V_7 -> V_17 = V_18 | V_19 ;
V_7 -> V_20 = 20 ;
V_7 -> V_21 = 1 ;
V_7 -> V_22 = & V_23 ;
V_7 -> V_24 = V_25 ;
V_7 -> V_26 = V_27 ;
F_6 ( L_2 ) ;
F_9 ( V_28 , V_29 ) ;
F_9 ( 0x00 , V_30 ) ;
F_9 ( V_31 , V_29 ) ;
F_9 ( 0x00 , V_30 ) ;
F_9 ( V_32 , V_29 ) ;
F_9 ( ( F_10 ( V_30 ) & 0xAA ) , V_30 ) ;
return 1 ;
}
static int F_11 ( struct V_2 * V_3 )
{
F_9 ( V_28 , V_29 ) ;
F_9 ( 0x00 , V_30 ) ;
F_9 ( V_31 , V_29 ) ;
F_9 ( 0x00 , V_30 ) ;
F_9 ( V_32 , V_29 ) ;
F_9 ( ( F_10 ( V_30 ) & 0xAA ) , V_30 ) ;
F_6 ( V_8 L_3 , V_3 -> V_9 ) ;
return 0 ;
}
static int V_25 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
struct V_33 * V_34 , unsigned int * V_35 )
{
if ( V_34 -> V_36 != 2 )
return - V_37 ;
if ( V_35 [ 0 ] ) {
F_9 ( V_38 , V_29 ) ;
F_9 ( ( F_10 ( V_30 )
& ~ ( V_39 ) ( V_35 [ 0 ] & 0x0000FF ) )
| ( V_39 ) ( V_35 [ 1 ] & 0x0000FF ) , V_30 ) ;
F_9 ( V_40 , V_29 ) ;
F_9 ( ( F_10 ( V_30 )
& ~ ( V_39 ) ( ( V_35 [ 0 ] & 0x00FF00 ) >> 8 ) )
| ( V_39 ) ( ( V_35 [ 1 ] & 0x00FF00 ) >> 8 ) , V_30 ) ;
F_9 ( V_41 , V_29 ) ;
F_9 ( ( F_10 ( V_30 )
& ~ ( V_39 ) ( ( V_35 [ 0 ] & 0x0F0000 ) >> 12 ) )
| ( V_39 ) ( ( V_35 [ 1 ] & 0x0F0000 ) >> 12 ) , V_30 ) ;
}
F_9 ( V_38 , V_29 ) ;
V_35 [ 0 ] = F_10 ( V_30 ) ;
F_9 ( V_40 , V_29 ) ;
V_35 [ 0 ] += F_10 ( V_30 ) << 8 ;
F_9 ( V_41 , V_29 ) ;
V_35 [ 0 ] += ( ( F_10 ( V_30 ) & 0xF0 ) << 12 ) ;
return 2 ;
}
static int V_27 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
struct V_33 * V_34 , unsigned int * V_35 )
{
V_39 V_42 ;
int V_43 = F_12 ( V_34 -> V_44 ) ;
switch ( V_35 [ 0 ] ) {
case V_45 :
case V_46 :
break;
case V_47 :
V_35 [ 1 ] =
( F_10 ( V_30 ) & ( 1 << V_43 ) ) ? V_48 : V_49 ;
return V_34 -> V_36 ;
break;
default:
return - V_37 ;
break;
}
if ( ( V_43 >= 0 ) && ( V_43 <= 7 ) ) {
F_9 ( V_28 , V_29 ) ;
} else if ( ( V_43 >= 8 ) && ( V_43 <= 15 ) ) {
V_43 -= 8 ;
F_9 ( V_31 , V_29 ) ;
} else if ( ( V_43 >= 16 ) && ( V_43 <= 19 ) ) {
V_43 -= 16 ;
V_43 *= 2 ;
F_9 ( V_32 , V_29 ) ;
} else {
return - V_37 ;
}
V_42 = F_10 ( V_30 ) ;
if ( V_35 [ 0 ] == V_48 )
V_42 |= ( 1 << V_43 ) ;
else
V_42 &= ~ ( 1 << V_43 ) ;
F_9 ( V_42 , V_30 ) ;
return 1 ;
}
