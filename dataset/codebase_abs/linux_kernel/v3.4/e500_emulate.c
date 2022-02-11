int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 , int * V_6 )
{
int V_7 = V_8 ;
int V_9 ;
int V_10 ;
switch ( F_2 ( V_5 ) ) {
case 31 :
switch ( F_3 ( V_5 ) ) {
case V_11 :
V_7 = F_4 ( V_4 ) ;
break;
case V_12 :
V_7 = F_5 ( V_4 ) ;
break;
case V_13 :
V_10 = F_6 ( V_5 ) ;
V_7 = F_7 ( V_4 , V_10 ) ;
break;
case V_14 :
V_9 = F_8 ( V_5 ) ;
V_10 = F_6 ( V_5 ) ;
V_7 = F_9 ( V_4 , V_9 , V_10 ) ;
break;
default:
V_7 = V_15 ;
}
break;
default:
V_7 = V_15 ;
}
if ( V_7 == V_15 )
V_7 = F_10 ( V_2 , V_4 , V_5 , V_6 ) ;
return V_7 ;
}
int F_11 ( struct V_3 * V_4 , int V_16 , int V_17 )
{
struct V_18 * V_19 = F_12 ( V_4 ) ;
int V_7 = V_8 ;
T_1 V_20 = F_13 ( V_4 , V_17 ) ;
switch ( V_16 ) {
case V_21 :
F_14 ( V_4 , V_20 ) ;
break;
case V_22 :
if ( V_20 != 0 )
return V_15 ;
V_19 -> V_23 [ 1 ] = V_20 ; break;
case V_24 :
if ( V_20 != 0 )
return V_15 ;
V_19 -> V_23 [ 2 ] = V_20 ; break;
case V_25 :
V_4 -> V_26 . V_27 -> V_28 = V_20 ; break;
case V_29 :
V_4 -> V_26 . V_27 -> V_30 = V_20 ; break;
case V_31 :
V_4 -> V_26 . V_27 -> V_32 = V_20 ; break;
case V_33 :
V_4 -> V_26 . V_27 -> V_34 &= ~ ( V_35 ) 0xffffffff ;
V_4 -> V_26 . V_27 -> V_34 |= V_20 ;
break;
case V_36 :
V_4 -> V_26 . V_27 -> V_37 = V_20 ; break;
case V_38 :
V_4 -> V_26 . V_27 -> V_39 = V_20 ; break;
case V_40 :
V_4 -> V_26 . V_27 -> V_34 &= ( V_35 ) 0xffffffff ;
V_4 -> V_26 . V_27 -> V_34 |= ( V_35 ) V_20 << 32 ;
break;
case V_41 :
V_19 -> V_42 = V_20 ;
V_19 -> V_42 &= ~ ( V_43 | V_44 ) ;
break;
case V_45 :
V_19 -> V_46 = V_20 ; break;
case V_47 :
V_19 -> V_48 = V_20 ; break;
case V_49 :
V_19 -> V_50 = V_20 ; break;
case V_51 :
V_7 = F_15 ( V_19 ,
V_20 ) ;
break;
case V_52 :
V_4 -> V_26 . V_53 [ V_54 ] = V_20 ;
break;
case V_55 :
V_4 -> V_26 . V_53 [ V_56 ] = V_20 ;
break;
case V_57 :
V_4 -> V_26 . V_53 [ V_58 ] = V_20 ;
break;
case V_59 :
V_4 -> V_26 . V_53 [ V_60 ] = V_20 ;
break;
default:
V_7 = F_16 ( V_4 , V_16 , V_17 ) ;
}
return V_7 ;
}
int F_17 ( struct V_3 * V_4 , int V_16 , int V_61 )
{
struct V_18 * V_19 = F_12 ( V_4 ) ;
int V_7 = V_8 ;
unsigned long V_62 ;
switch ( V_16 ) {
case V_21 :
F_18 ( V_4 , V_61 , V_19 -> V_23 [ 0 ] ) ; break;
case V_22 :
F_18 ( V_4 , V_61 , V_19 -> V_23 [ 1 ] ) ; break;
case V_24 :
F_18 ( V_4 , V_61 , V_19 -> V_23 [ 2 ] ) ; break;
case V_25 :
F_18 ( V_4 , V_61 , V_4 -> V_26 . V_27 -> V_28 ) ; break;
case V_29 :
F_18 ( V_4 , V_61 , V_4 -> V_26 . V_27 -> V_30 ) ; break;
case V_31 :
F_18 ( V_4 , V_61 , V_4 -> V_26 . V_27 -> V_32 ) ; break;
case V_33 :
V_62 = ( V_63 ) V_4 -> V_26 . V_27 -> V_34 ;
F_18 ( V_4 , V_61 , V_62 ) ;
break;
case V_36 :
F_18 ( V_4 , V_61 , V_4 -> V_26 . V_27 -> V_37 ) ; break;
case V_38 :
F_18 ( V_4 , V_61 , V_4 -> V_26 . V_27 -> V_39 ) ; break;
case V_40 :
V_62 = V_4 -> V_26 . V_27 -> V_34 >> 32 ;
F_18 ( V_4 , V_61 , V_62 ) ;
break;
case V_64 :
F_18 ( V_4 , V_61 , V_19 -> V_65 ) ; break;
case V_66 :
F_18 ( V_4 , V_61 , V_19 -> V_67 ) ; break;
case V_41 :
F_18 ( V_4 , V_61 , V_19 -> V_42 ) ; break;
case V_45 :
F_18 ( V_4 , V_61 , V_19 -> V_46 ) ; break;
case V_47 :
F_18 ( V_4 , V_61 , V_19 -> V_48 ) ; break;
case V_49 :
F_18 ( V_4 , V_61 , V_19 -> V_50 ) ; break;
case V_68 :
F_18 ( V_4 , V_61 , V_19 -> V_69 ) ; break;
case V_51 :
F_18 ( V_4 , V_61 , 0 ) ; break;
case V_70 :
F_18 ( V_4 , V_61 , F_19 ( V_70 ) ) ; break;
case V_52 :
F_18 ( V_4 , V_61 , V_4 -> V_26 . V_53 [ V_54 ] ) ;
break;
case V_55 :
F_18 ( V_4 , V_61 , V_4 -> V_26 . V_53 [ V_56 ] ) ;
break;
case V_57 :
F_18 ( V_4 , V_61 , V_4 -> V_26 . V_53 [ V_58 ] ) ;
break;
case V_59 :
F_18 ( V_4 , V_61 , V_4 -> V_26 . V_53 [ V_60 ] ) ;
break;
default:
V_7 = F_20 ( V_4 , V_16 , V_61 ) ;
}
return V_7 ;
}
