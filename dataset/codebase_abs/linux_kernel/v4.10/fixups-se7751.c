int T_1 F_1 ( const struct V_1 * , T_2 V_2 , T_2 V_3 )
{
switch ( V_2 ) {
case 0 : return F_2 ( 0x3a0 ) ;
case 1 : return F_2 ( 0x3a0 ) ;
case 2 : return - 1 ;
case 3 : return - 1 ;
case 4 : return - 1 ;
default:
F_3 ( L_1 , V_2 ) ;
return - 1 ;
}
}
int F_4 ( struct V_4 * V_5 )
{
unsigned long V_6 , V_7 , V_8 , V_9 , V_10 ;
unsigned short V_11 ;
V_6 = ( * ( volatile unsigned long * ) ( V_12 ) ) ;
V_11 = ( * ( volatile unsigned short * ) ( V_13 ) ) ;
V_7 = ( * ( volatile unsigned long * ) ( V_14 ) ) ;
V_8 = ( * ( volatile unsigned long * ) ( V_15 ) ) ;
V_9 = ( * ( volatile unsigned long * ) ( V_16 ) ) ;
V_10 = ( * ( volatile unsigned long * ) ( V_17 ) ) ;
V_6 = V_6 | 0x00080000 ;
( * ( volatile unsigned long * ) ( V_12 ) ) = V_6 ;
V_6 = V_6 | 0x40080000 ;
F_5 ( V_18 , V_6 ) ;
F_5 ( V_19 , V_11 ) ;
F_5 ( V_20 , V_7 ) ;
F_5 ( V_21 , V_8 ) ;
F_5 ( V_22 , V_9 ) ;
V_10 = ( V_10 & V_23 ) & V_24 ;
F_5 ( V_25 , V_10 ) ;
F_5 ( V_26 , 0x0000c3ff ) ;
F_5 ( V_27 , 0x0000380f ) ;
F_5 ( V_28 , 0xF39000C7 ) ;
F_5 ( V_29 , 0x00000000 ) ;
F_5 ( V_30 , 0xab000001 ) ;
F_5 ( V_31 , 0x0c000000 ) ;
F_5 ( V_32 , 0xd0000000 ) ;
F_5 ( V_33 , 0x35051054 ) ;
F_5 ( V_34 , 0x03f00000 ) ;
F_5 ( V_35 , 0x00000000 ) ;
F_5 ( V_36 , 0x0c000000 ) ;
F_5 ( V_37 , 0x00000000 ) ;
F_5 ( V_38 , 0xa5000001 ) ;
F_6 ( V_5 -> V_39 [ 1 ] . V_40 != V_41 ) ;
F_5 ( V_42 , V_5 -> V_39 [ 1 ] . V_40 ) ;
F_5 ( V_43 , ( V_5 -> V_39 [ 0 ] . V_40 & V_44 ) ) ;
F_3 ( L_2 ) ;
return 1 ;
}
