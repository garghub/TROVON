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
static int F_9 ( struct V_24 * V_25 , struct V_9 * V_10 ,
unsigned int V_26 , int * V_27 )
{
int V_28 = V_16 ;
switch ( F_10 ( V_26 ) ) {
case V_29 :
V_25 -> V_30 = V_31 ;
V_25 -> V_32 . V_12 . V_33 = V_10 -> V_12 . V_34 ;
V_25 -> V_32 . V_12 . V_35 = 0 ;
F_11 ( V_10 , V_36 ) ;
V_28 = V_37 ;
* V_27 = 0 ;
break;
default:
V_28 = V_14 ;
}
return V_28 ;
}
int F_12 ( struct V_24 * V_25 , struct V_9 * V_10 ,
unsigned int V_26 , int * V_27 )
{
int V_28 = V_16 ;
int V_38 = F_13 ( V_26 ) ;
int V_11 = F_14 ( V_26 ) ;
int V_39 = F_15 ( V_26 ) ;
T_2 V_40 ;
switch ( F_16 ( V_26 ) ) {
case 31 :
switch ( F_17 ( V_26 ) ) {
#ifdef F_18
case V_41 :
V_28 = F_5 ( V_10 , V_11 ) ;
break;
case V_42 :
V_28 = F_3 ( V_10 , V_11 ) ;
break;
#endif
case V_43 :
V_28 = F_19 ( V_10 ) ;
break;
case V_44 :
V_28 = F_20 ( V_10 ) ;
break;
case V_45 :
V_40 = F_21 ( V_10 , V_38 , V_11 ) ;
V_28 = F_22 ( V_10 , V_40 ) ;
break;
case V_46 : {
int type = V_39 & 0x3 ;
V_40 = F_21 ( V_10 , V_38 , V_11 ) ;
V_28 = F_23 ( V_10 , type , V_40 ) ;
break;
}
case V_47 :
V_40 = F_21 ( V_10 , V_38 , V_11 ) ;
V_28 = F_24 ( V_10 , V_40 ) ;
break;
case V_48 :
V_28 = F_9 ( V_25 , V_10 , V_26 ,
V_27 ) ;
break;
default:
V_28 = V_14 ;
}
break;
default:
V_28 = V_14 ;
}
if ( V_28 == V_14 )
V_28 = F_25 ( V_25 , V_10 , V_26 , V_27 ) ;
return V_28 ;
}
int F_26 ( struct V_9 * V_10 , int V_49 , T_1 V_50 )
{
struct V_51 * V_52 = F_27 ( V_10 ) ;
int V_28 = V_16 ;
switch ( V_49 ) {
#ifndef F_28
case V_53 :
F_29 ( V_10 , V_50 ) ;
break;
case V_54 :
if ( V_50 != 0 )
return V_14 ;
V_52 -> V_55 [ 1 ] = V_50 ;
break;
case V_56 :
if ( V_50 != 0 )
return V_14 ;
V_52 -> V_55 [ 2 ] = V_50 ;
break;
case V_57 :
V_10 -> V_12 . V_22 -> V_58 = V_50 ;
break;
case V_59 :
V_10 -> V_12 . V_22 -> V_60 = V_50 ;
break;
case V_61 :
V_10 -> V_12 . V_22 -> V_62 = V_50 ;
break;
case V_63 :
V_10 -> V_12 . V_22 -> V_64 &= ~ ( V_65 ) 0xffffffff ;
V_10 -> V_12 . V_22 -> V_64 |= V_50 ;
break;
case V_66 :
V_10 -> V_12 . V_22 -> V_67 = V_50 ;
break;
case V_68 :
V_10 -> V_12 . V_22 -> V_69 = V_50 ;
break;
case V_70 :
V_10 -> V_12 . V_22 -> V_64 &= ( V_65 ) 0xffffffff ;
V_10 -> V_12 . V_22 -> V_64 |= ( V_65 ) V_50 << 32 ;
break;
#endif
case V_71 :
V_52 -> V_72 = V_50 ;
V_52 -> V_72 &= ~ ( V_73 | V_74 ) ;
break;
case V_75 :
V_52 -> V_76 = V_50 ;
break;
case V_77 :
V_52 -> V_78 = V_50 ;
break;
case V_79 :
V_52 -> V_80 = V_50 ;
break;
case V_81 :
V_28 = F_30 ( V_52 ,
V_50 ) ;
break;
case V_82 :
V_10 -> V_12 . V_83 [ V_84 ] = V_50 ;
break;
case V_85 :
V_10 -> V_12 . V_83 [ V_86 ] = V_50 ;
break;
case V_87 :
V_10 -> V_12 . V_83 [ V_88 ] = V_50 ;
break;
case V_89 :
V_10 -> V_12 . V_83 [ V_90 ] = V_50 ;
break;
#ifdef F_28
case V_91 :
V_10 -> V_12 . V_83 [ V_6 ] = V_50 ;
break;
case V_92 :
V_10 -> V_12 . V_83 [ V_8 ] = V_50 ;
break;
#endif
default:
V_28 = F_31 ( V_10 , V_49 , V_50 ) ;
}
return V_28 ;
}
int F_32 ( struct V_9 * V_10 , int V_49 , T_1 * V_50 )
{
struct V_51 * V_52 = F_27 ( V_10 ) ;
int V_28 = V_16 ;
switch ( V_49 ) {
#ifndef F_28
case V_53 :
* V_50 = V_52 -> V_55 [ 0 ] ;
break;
case V_54 :
* V_50 = V_52 -> V_55 [ 1 ] ;
break;
case V_56 :
* V_50 = V_52 -> V_55 [ 2 ] ;
break;
case V_57 :
* V_50 = V_10 -> V_12 . V_22 -> V_58 ;
break;
case V_59 :
* V_50 = V_10 -> V_12 . V_22 -> V_60 ;
break;
case V_61 :
* V_50 = V_10 -> V_12 . V_22 -> V_62 ;
break;
case V_63 :
* V_50 = ( V_93 ) V_10 -> V_12 . V_22 -> V_64 ;
break;
case V_66 :
* V_50 = V_10 -> V_12 . V_22 -> V_67 ;
break;
case V_68 :
* V_50 = V_10 -> V_12 . V_22 -> V_69 ;
break;
case V_70 :
* V_50 = V_10 -> V_12 . V_22 -> V_64 >> 32 ;
break;
#endif
case V_94 :
* V_50 = V_10 -> V_12 . V_95 ;
break;
case V_96 :
* V_50 = V_10 -> V_12 . V_97 [ 0 ] ;
break;
case V_98 :
* V_50 = V_10 -> V_12 . V_97 [ 1 ] ;
break;
case V_99 :
if ( ! F_33 ( V_10 , V_100 ) )
return V_14 ;
* V_50 = V_10 -> V_12 . V_101 [ 0 ] ;
break;
case V_102 :
if ( ! F_33 ( V_10 , V_100 ) )
return V_14 ;
* V_50 = V_10 -> V_12 . V_101 [ 1 ] ;
break;
case V_71 :
* V_50 = V_52 -> V_72 ;
break;
case V_75 :
* V_50 = V_52 -> V_76 ;
break;
case V_77 :
* V_50 = V_52 -> V_78 ;
break;
case V_79 :
* V_50 = V_52 -> V_80 ;
break;
case V_103 :
* V_50 = V_52 -> V_104 ;
break;
case V_81 :
* V_50 = 0 ;
break;
case V_105 :
* V_50 = V_10 -> V_12 . V_106 ;
break;
case V_107 :
if ( ! F_33 ( V_10 , V_100 ) )
return V_14 ;
* V_50 = V_10 -> V_12 . V_108 ;
break;
case V_82 :
* V_50 = V_10 -> V_12 . V_83 [ V_84 ] ;
break;
case V_85 :
* V_50 = V_10 -> V_12 . V_83 [ V_86 ] ;
break;
case V_87 :
* V_50 = V_10 -> V_12 . V_83 [ V_88 ] ;
break;
case V_89 :
* V_50 = V_10 -> V_12 . V_83 [ V_90 ] ;
break;
#ifdef F_28
case V_91 :
* V_50 = V_10 -> V_12 . V_83 [ V_6 ] ;
break;
case V_92 :
* V_50 = V_10 -> V_12 . V_83 [ V_8 ] ;
break;
#endif
default:
V_28 = F_34 ( V_10 , V_49 , V_50 ) ;
}
return V_28 ;
}
