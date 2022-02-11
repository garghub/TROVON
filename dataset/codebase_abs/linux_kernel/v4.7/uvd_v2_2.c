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
bool F_6 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_15 * V_16 ,
bool V_17 )
{
T_1 V_7 = V_16 -> V_9 ;
F_2 ( V_6 , F_3 ( V_18 , 0 ) ) ;
F_2 ( V_6 , ( V_7 >> 3 ) & 0x000FFFFF ) ;
F_2 ( V_6 , F_3 ( V_19 , 0 ) ) ;
F_2 ( V_6 , ( V_7 >> 23 ) & 0x000FFFFF ) ;
F_2 ( V_6 , F_3 ( V_20 , 0 ) ) ;
F_2 ( V_6 , V_17 ? 1 : 0 ) ;
return true ;
}
int F_7 ( struct V_1 * V_2 )
{
T_1 V_7 ;
T_2 V_21 , V_22 ;
int V_23 ;
if ( V_2 -> V_24 == V_25 )
return F_8 ( V_2 ) ;
V_23 = F_9 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_7 = V_2 -> V_26 . V_9 >> 3 ;
V_22 = F_10 ( V_2 -> V_27 -> V_22 + 4 ) >> 3 ;
F_11 ( V_28 , V_7 ) ;
F_11 ( V_29 , V_22 ) ;
V_7 += V_22 ;
V_22 = V_30 >> 3 ;
F_11 ( V_31 , V_7 ) ;
F_11 ( V_32 , V_22 ) ;
V_7 += V_22 ;
V_22 = ( V_33 +
( V_34 * V_2 -> V_26 . V_35 ) ) >> 3 ;
F_11 ( V_36 , V_7 ) ;
F_11 ( V_37 , V_22 ) ;
V_7 = ( V_2 -> V_26 . V_9 >> 28 ) & 0xF ;
F_11 ( V_38 , ( V_7 << 12 ) | ( V_7 << 0 ) ) ;
V_7 = ( V_2 -> V_26 . V_9 >> 32 ) & 0xFF ;
F_11 ( V_39 , V_7 | ( 0x9 << 16 ) | ( 0x1 << 31 ) ) ;
switch ( V_2 -> V_24 ) {
default:
return - V_40 ;
case V_41 :
V_21 = 0x01000005 ;
break;
case V_42 :
V_21 = 0x01000006 ;
break;
case V_43 :
V_21 = 0x01000007 ;
break;
case V_44 :
case V_45 :
V_21 = 0x01000008 ;
break;
case V_46 :
V_21 = 0x01000009 ;
break;
case V_47 :
V_21 = 0x0100000a ;
break;
case V_48 :
V_21 = 0x0100000b ;
break;
case V_49 :
case V_50 :
V_21 = 0x0100000c ;
break;
case V_51 :
V_21 = 0x0100000e ;
break;
case V_52 :
V_21 = 0x0100000f ;
break;
case V_53 :
V_21 = 0x01000010 ;
break;
case V_54 :
V_21 = 0x01000011 ;
break;
case V_55 :
V_21 = 0x01000012 ;
break;
case V_56 :
V_21 = 0x01000014 ;
break;
case V_57 :
V_21 = 0x01000015 ;
break;
case V_58 :
case V_59 :
V_21 = 0x01000016 ;
break;
case V_60 :
V_21 = 0x01000017 ;
break;
}
F_11 ( V_61 , V_21 ) ;
return 0 ;
}
