static int F_1 ( T_1 V_1 )
{
int V_2 = V_1 & V_3 ;
int V_4 = - 1 ;
switch ( V_2 ) {
case F_2 ( V_5 ) :
V_4 = V_6 ;
break;
case F_2 ( V_7 ) :
V_4 = V_8 ;
break;
default:
break;
}
return V_4 ;
}
static int F_3 ( struct V_9 * V_10 , int V_11 )
{
T_1 V_1 = V_10 -> V_12 . V_13 [ V_11 ] ;
int V_4 = F_1 ( V_1 ) ;
if ( V_4 < 0 )
return V_14 ;
F_4 ( V_4 , & V_10 -> V_12 . V_15 ) ;
return V_16 ;
}
static int F_5 ( struct V_9 * V_10 , int V_11 )
{
T_1 V_1 = V_10 -> V_12 . V_13 [ V_11 ] ;
int V_4 = F_1 ( V_11 ) ;
int V_17 = V_1 & V_18 ;
int V_19 ;
struct V_9 * V_20 ;
if ( V_4 < 0 )
return V_14 ;
F_6 (i, cvcpu, vcpu->kvm) {
int V_21 = V_20 -> V_12 . V_22 -> V_17 ;
if ( ( V_1 & V_23 ) || ( V_21 == V_17 ) ) {
F_7 ( V_4 , & V_20 -> V_12 . V_15 ) ;
F_8 ( V_20 ) ;
}
}
return V_16 ;
}
int F_9 ( struct V_24 * V_25 , struct V_9 * V_10 ,
unsigned int V_26 , int * V_27 )
{
int V_28 = V_16 ;
int V_29 = F_10 ( V_26 ) ;
int V_11 = F_11 ( V_26 ) ;
int V_30 = F_12 ( V_26 ) ;
T_2 V_31 ;
switch ( F_13 ( V_26 ) ) {
case 31 :
switch ( F_14 ( V_26 ) ) {
#ifdef F_15
case V_32 :
V_28 = F_5 ( V_10 , V_11 ) ;
break;
case V_33 :
V_28 = F_3 ( V_10 , V_11 ) ;
break;
#endif
case V_34 :
V_28 = F_16 ( V_10 ) ;
break;
case V_35 :
V_28 = F_17 ( V_10 ) ;
break;
case V_36 :
V_31 = F_18 ( V_10 , V_29 , V_11 ) ;
V_28 = F_19 ( V_10 , V_31 ) ;
break;
case V_37 : {
int type = V_30 & 0x3 ;
V_31 = F_18 ( V_10 , V_29 , V_11 ) ;
V_28 = F_20 ( V_10 , type , V_31 ) ;
break;
}
case V_38 :
V_31 = F_18 ( V_10 , V_29 , V_11 ) ;
V_28 = F_21 ( V_10 , V_31 ) ;
break;
default:
V_28 = V_14 ;
}
break;
default:
V_28 = V_14 ;
}
if ( V_28 == V_14 )
V_28 = F_22 ( V_25 , V_10 , V_26 , V_27 ) ;
return V_28 ;
}
int F_23 ( struct V_9 * V_10 , int V_39 , T_1 V_40 )
{
struct V_41 * V_42 = F_24 ( V_10 ) ;
int V_28 = V_16 ;
switch ( V_39 ) {
#ifndef F_25
case V_43 :
F_26 ( V_10 , V_40 ) ;
break;
case V_44 :
if ( V_40 != 0 )
return V_14 ;
V_42 -> V_45 [ 1 ] = V_40 ;
break;
case V_46 :
if ( V_40 != 0 )
return V_14 ;
V_42 -> V_45 [ 2 ] = V_40 ;
break;
case V_47 :
V_10 -> V_12 . V_22 -> V_48 = V_40 ;
break;
case V_49 :
V_10 -> V_12 . V_22 -> V_50 = V_40 ;
break;
case V_51 :
V_10 -> V_12 . V_22 -> V_52 = V_40 ;
break;
case V_53 :
V_10 -> V_12 . V_22 -> V_54 &= ~ ( V_55 ) 0xffffffff ;
V_10 -> V_12 . V_22 -> V_54 |= V_40 ;
break;
case V_56 :
V_10 -> V_12 . V_22 -> V_57 = V_40 ;
break;
case V_58 :
V_10 -> V_12 . V_22 -> V_59 = V_40 ;
break;
case V_60 :
V_10 -> V_12 . V_22 -> V_54 &= ( V_55 ) 0xffffffff ;
V_10 -> V_12 . V_22 -> V_54 |= ( V_55 ) V_40 << 32 ;
break;
#endif
case V_61 :
V_42 -> V_62 = V_40 ;
V_42 -> V_62 &= ~ ( V_63 | V_64 ) ;
break;
case V_65 :
V_42 -> V_66 = V_40 ;
break;
case V_67 :
V_42 -> V_68 = V_40 ;
break;
case V_69 :
V_42 -> V_70 = V_40 ;
break;
case V_71 :
V_28 = F_27 ( V_42 ,
V_40 ) ;
break;
case V_72 :
V_10 -> V_12 . V_73 [ V_74 ] = V_40 ;
break;
case V_75 :
V_10 -> V_12 . V_73 [ V_76 ] = V_40 ;
break;
case V_77 :
V_10 -> V_12 . V_73 [ V_78 ] = V_40 ;
break;
case V_79 :
V_10 -> V_12 . V_73 [ V_80 ] = V_40 ;
break;
#ifdef F_25
case V_81 :
V_10 -> V_12 . V_73 [ V_6 ] = V_40 ;
break;
case V_82 :
V_10 -> V_12 . V_73 [ V_8 ] = V_40 ;
break;
#endif
default:
V_28 = F_28 ( V_10 , V_39 , V_40 ) ;
}
return V_28 ;
}
int F_29 ( struct V_9 * V_10 , int V_39 , T_1 * V_40 )
{
struct V_41 * V_42 = F_24 ( V_10 ) ;
int V_28 = V_16 ;
switch ( V_39 ) {
#ifndef F_25
case V_43 :
* V_40 = V_42 -> V_45 [ 0 ] ;
break;
case V_44 :
* V_40 = V_42 -> V_45 [ 1 ] ;
break;
case V_46 :
* V_40 = V_42 -> V_45 [ 2 ] ;
break;
case V_47 :
* V_40 = V_10 -> V_12 . V_22 -> V_48 ;
break;
case V_49 :
* V_40 = V_10 -> V_12 . V_22 -> V_50 ;
break;
case V_51 :
* V_40 = V_10 -> V_12 . V_22 -> V_52 ;
break;
case V_53 :
* V_40 = ( V_83 ) V_10 -> V_12 . V_22 -> V_54 ;
break;
case V_56 :
* V_40 = V_10 -> V_12 . V_22 -> V_57 ;
break;
case V_58 :
* V_40 = V_10 -> V_12 . V_22 -> V_59 ;
break;
case V_60 :
* V_40 = V_10 -> V_12 . V_22 -> V_54 >> 32 ;
break;
#endif
case V_84 :
* V_40 = V_10 -> V_12 . V_85 ;
break;
case V_86 :
* V_40 = V_10 -> V_12 . V_87 [ 0 ] ;
break;
case V_88 :
* V_40 = V_10 -> V_12 . V_87 [ 1 ] ;
break;
case V_61 :
* V_40 = V_42 -> V_62 ;
break;
case V_65 :
* V_40 = V_42 -> V_66 ;
break;
case V_67 :
* V_40 = V_42 -> V_68 ;
break;
case V_69 :
* V_40 = V_42 -> V_70 ;
break;
case V_89 :
* V_40 = V_42 -> V_90 ;
break;
case V_71 :
* V_40 = 0 ;
break;
case V_91 :
* V_40 = V_10 -> V_12 . V_92 ;
break;
case V_72 :
* V_40 = V_10 -> V_12 . V_73 [ V_74 ] ;
break;
case V_75 :
* V_40 = V_10 -> V_12 . V_73 [ V_76 ] ;
break;
case V_77 :
* V_40 = V_10 -> V_12 . V_73 [ V_78 ] ;
break;
case V_79 :
* V_40 = V_10 -> V_12 . V_73 [ V_80 ] ;
break;
#ifdef F_25
case V_81 :
* V_40 = V_10 -> V_12 . V_73 [ V_6 ] ;
break;
case V_82 :
* V_40 = V_10 -> V_12 . V_73 [ V_8 ] ;
break;
#endif
default:
V_28 = F_30 ( V_10 , V_39 , V_40 ) ;
}
return V_28 ;
}
