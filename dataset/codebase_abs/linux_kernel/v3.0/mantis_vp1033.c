int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = & V_6 -> V_10 ;
T_1 V_11 [ 4 ] ;
T_2 div ;
struct V_12 V_13 = { . V_14 = 0x61 , . V_15 = 0 , . V_11 = V_11 , . V_16 = sizeof( V_11 ) } ;
div = V_4 -> V_17 / 250 ;
V_11 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_11 [ 1 ] = div & 0xff ;
V_11 [ 2 ] = 0x83 ;
V_11 [ 3 ] = 0xc0 ;
if ( V_4 -> V_17 < 1531000 )
V_11 [ 3 ] |= 0x04 ;
else
V_11 [ 3 ] &= ~ 0x04 ;
if ( F_2 ( V_10 , & V_13 , 1 ) < 0 ) {
F_3 ( V_18 , 1 , L_1 ) ;
return - V_19 ;
}
F_4 ( 100 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 ,
T_2 V_20 , T_2 V_21 )
{
T_1 V_22 = 0 ;
T_1 V_23 = 0 ;
if ( V_20 < 1500000 ) {
V_22 = 0xb7 ;
V_23 = 0x47 ;
} else if ( V_20 < 3000000 ) {
V_22 = 0xb7 ;
V_23 = 0x4b ;
} else if ( V_20 < 7000000 ) {
V_22 = 0xb7 ;
V_23 = 0x4f ;
} else if ( V_20 < 14000000 ) {
V_22 = 0xb7 ;
V_23 = 0x53 ;
} else if ( V_20 < 30000000 ) {
V_22 = 0xb6 ;
V_23 = 0x53 ;
} else if ( V_20 < 45000000 ) {
V_22 = 0xb4 ;
V_23 = 0x51 ;
}
F_6 ( V_2 , 0x13 , V_22 ) ;
F_6 ( V_2 , 0x14 , V_23 ) ;
F_6 ( V_2 , 0x1f , ( V_21 >> 16 ) & 0xff ) ;
F_6 ( V_2 , 0x20 , ( V_21 >> 8 ) & 0xff ) ;
F_6 ( V_2 , 0x21 , V_21 & 0xf0 ) ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_6 -> V_10 ;
int V_24 = 0 ;
V_24 = F_8 ( V_6 , V_25 ) ;
if ( V_24 == 0 ) {
F_9 ( V_6 ) ;
F_10 ( 250 ) ;
F_3 ( V_18 , 1 , L_2 ) ;
V_2 = F_11 ( V_26 , & V_27 , V_10 ) ;
if ( V_2 ) {
V_2 -> V_28 . V_29 . V_30 = F_1 ;
F_3 ( V_18 , 1 , L_3 ,
V_27 . V_31 ) ;
F_3 ( V_18 , 1 , L_4 ) ;
} else {
return - 1 ;
}
} else {
F_3 ( V_18 , 1 , L_5 ,
V_10 -> V_32 ,
V_24 ) ;
return - V_19 ;
}
V_6 -> V_2 = V_2 ;
F_3 ( V_18 , 1 , L_6 ) ;
return 0 ;
}
