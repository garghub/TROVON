void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 [ V_4 -> V_6 ] ;
T_1 V_7 = V_2 -> V_8 [ V_4 -> V_6 ] . V_9 ;
F_2 ( V_6 , F_3 ( V_10 , 0 ) ) ;
F_2 ( V_6 , V_4 -> V_11 ) ;
F_2 ( V_6 , F_3 ( V_12 , 0 ) ) ;
F_2 ( V_6 , F_4 ( V_7 ) ) ;
F_2 ( V_6 , F_3 ( V_13 , 0 ) ) ;
F_2 ( V_6 , F_5 ( V_7 ) & 0xff ) ;
F_2 ( V_6 , F_3 ( V_14 , 0 ) ) ;
F_2 ( V_6 , 0 ) ;
F_2 ( V_6 , F_3 ( V_12 , 0 ) ) ;
F_2 ( V_6 , 0 ) ;
F_2 ( V_6 , F_3 ( V_13 , 0 ) ) ;
F_2 ( V_6 , 0 ) ;
F_2 ( V_6 , F_3 ( V_14 , 0 ) ) ;
F_2 ( V_6 , 2 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
T_1 V_7 ;
T_2 V_15 , V_16 ;
int V_17 ;
V_17 = F_7 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_7 = V_2 -> V_18 . V_9 >> 3 ;
V_16 = F_8 ( V_2 -> V_19 -> V_16 + 4 ) >> 3 ;
F_9 ( V_20 , V_7 ) ;
F_9 ( V_21 , V_16 ) ;
V_7 += V_16 ;
V_16 = V_22 >> 3 ;
F_9 ( V_23 , V_7 ) ;
F_9 ( V_24 , V_16 ) ;
V_7 += V_16 ;
V_16 = V_25 >> 3 ;
F_9 ( V_26 , V_7 ) ;
F_9 ( V_27 , V_16 ) ;
V_7 = ( V_2 -> V_18 . V_9 >> 28 ) & 0xF ;
F_9 ( V_28 , ( V_7 << 12 ) | ( V_7 << 0 ) ) ;
V_7 = ( V_2 -> V_18 . V_9 >> 32 ) & 0xFF ;
F_9 ( V_29 , V_7 | ( 0x9 << 16 ) | ( 0x1 << 31 ) ) ;
switch ( V_2 -> V_30 ) {
default:
return - V_31 ;
case V_32 :
V_15 = 0x01000005 ;
break;
case V_33 :
V_15 = 0x01000006 ;
break;
case V_34 :
V_15 = 0x01000007 ;
break;
case V_35 :
case V_36 :
V_15 = 0x01000008 ;
break;
case V_37 :
V_15 = 0x01000009 ;
break;
case V_38 :
V_15 = 0x0100000a ;
break;
case V_39 :
V_15 = 0x0100000b ;
break;
case V_40 :
case V_41 :
V_15 = 0x0100000c ;
break;
case V_42 :
V_15 = 0x0100000e ;
break;
case V_43 :
V_15 = 0x0100000f ;
break;
case V_44 :
V_15 = 0x01000010 ;
break;
case V_45 :
V_15 = 0x01000011 ;
break;
case V_46 :
V_15 = 0x01000012 ;
break;
case V_47 :
V_15 = 0x01000014 ;
break;
case V_48 :
V_15 = 0x01000015 ;
break;
case V_49 :
case V_50 :
V_15 = 0x01000016 ;
break;
case V_51 :
V_15 = 0x01000017 ;
break;
}
F_9 ( V_52 , V_15 ) ;
return 0 ;
}
