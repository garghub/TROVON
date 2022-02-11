int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
struct V_10 * V_11 = & V_7 -> V_11 ;
T_1 V_12 [ 4 ] ;
T_2 div ;
struct V_13 V_14 = { . V_15 = 0x61 , . V_16 = 0 , . V_12 = V_12 , . V_17 = sizeof( V_12 ) } ;
div = V_4 -> V_18 / 250 ;
V_12 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_12 [ 1 ] = div & 0xff ;
V_12 [ 2 ] = 0x83 ;
V_12 [ 3 ] = 0xc0 ;
if ( V_4 -> V_18 < 1531000 )
V_12 [ 3 ] |= 0x04 ;
else
V_12 [ 3 ] &= ~ 0x04 ;
if ( F_2 ( V_11 , & V_14 , 1 ) < 0 ) {
F_3 ( V_19 , 1 , L_1 ) ;
return - V_20 ;
}
F_4 ( 100 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 ,
T_2 V_21 , T_2 V_22 )
{
T_1 V_23 = 0 ;
T_1 V_24 = 0 ;
if ( V_21 < 1500000 ) {
V_23 = 0xb7 ;
V_24 = 0x47 ;
} else if ( V_21 < 3000000 ) {
V_23 = 0xb7 ;
V_24 = 0x4b ;
} else if ( V_21 < 7000000 ) {
V_23 = 0xb7 ;
V_24 = 0x4f ;
} else if ( V_21 < 14000000 ) {
V_23 = 0xb7 ;
V_24 = 0x53 ;
} else if ( V_21 < 30000000 ) {
V_23 = 0xb6 ;
V_24 = 0x53 ;
} else if ( V_21 < 45000000 ) {
V_23 = 0xb4 ;
V_24 = 0x51 ;
}
F_6 ( V_2 , 0x13 , V_23 ) ;
F_6 ( V_2 , 0x14 , V_24 ) ;
F_6 ( V_2 , 0x1f , ( V_22 >> 16 ) & 0xff ) ;
F_6 ( V_2 , 0x20 , ( V_22 >> 8 ) & 0xff ) ;
F_6 ( V_2 , 0x21 , V_22 & 0xf0 ) ;
return 0 ;
}
static int F_7 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
struct V_10 * V_11 = & V_7 -> V_11 ;
int V_25 = 0 ;
V_25 = F_8 ( V_7 , V_26 ) ;
if ( V_25 == 0 ) {
F_9 ( V_7 ) ;
F_10 ( 250 ) ;
F_3 ( V_19 , 1 , L_2 ) ;
V_2 = F_11 ( V_27 , & V_28 , V_11 ) ;
if ( V_2 ) {
V_2 -> V_29 . V_30 . V_31 = F_1 ;
F_3 ( V_19 , 1 , L_3 ,
V_28 . V_32 ) ;
F_3 ( V_19 , 1 , L_4 ) ;
} else {
return - 1 ;
}
} else {
F_3 ( V_19 , 1 , L_5 ,
V_11 -> V_33 ,
V_25 ) ;
return - V_20 ;
}
V_7 -> V_2 = V_2 ;
F_3 ( V_19 , 1 , L_6 ) ;
return 0 ;
}
