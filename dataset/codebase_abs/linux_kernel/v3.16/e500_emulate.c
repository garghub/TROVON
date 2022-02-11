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
static int F_12 ( struct V_9 * V_10 )
{
struct V_38 * V_39 = F_13 ( V_10 ) ;
V_39 -> V_40 |= V_41 ;
return V_16 ;
}
int F_14 ( struct V_24 * V_25 , struct V_9 * V_10 ,
unsigned int V_26 , int * V_27 )
{
int V_28 = V_16 ;
int V_42 = F_15 ( V_26 ) ;
int V_11 = F_16 ( V_26 ) ;
int V_43 = F_17 ( V_26 ) ;
T_2 V_44 ;
switch ( F_18 ( V_26 ) ) {
case 31 :
switch ( F_19 ( V_26 ) ) {
case V_45 :
V_28 = F_12 ( V_10 ) ;
break;
#ifdef F_20
case V_46 :
V_28 = F_5 ( V_10 , V_11 ) ;
break;
case V_47 :
V_28 = F_3 ( V_10 , V_11 ) ;
break;
#endif
case V_48 :
V_28 = F_21 ( V_10 ) ;
break;
case V_49 :
V_28 = F_22 ( V_10 ) ;
break;
case V_50 :
V_44 = F_23 ( V_10 , V_42 , V_11 ) ;
V_28 = F_24 ( V_10 , V_44 ) ;
break;
case V_51 : {
int type = V_43 & 0x3 ;
V_44 = F_23 ( V_10 , V_42 , V_11 ) ;
V_28 = F_25 ( V_10 , type , V_44 ) ;
break;
}
case V_52 :
V_44 = F_23 ( V_10 , V_42 , V_11 ) ;
V_28 = F_26 ( V_10 , V_44 ) ;
break;
case V_53 :
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
V_28 = F_27 ( V_25 , V_10 , V_26 , V_27 ) ;
return V_28 ;
}
int F_28 ( struct V_9 * V_10 , int V_54 , T_1 V_55 )
{
struct V_38 * V_39 = F_13 ( V_10 ) ;
int V_28 = V_16 ;
switch ( V_54 ) {
#ifndef F_29
case V_56 :
F_30 ( V_10 , V_55 ) ;
break;
case V_57 :
if ( V_55 != 0 )
return V_14 ;
V_39 -> V_58 [ 1 ] = V_55 ;
break;
case V_59 :
if ( V_55 != 0 )
return V_14 ;
V_39 -> V_58 [ 2 ] = V_55 ;
break;
case V_60 :
V_10 -> V_12 . V_22 -> V_61 = V_55 ;
break;
case V_62 :
V_10 -> V_12 . V_22 -> V_63 = V_55 ;
break;
case V_64 :
V_10 -> V_12 . V_22 -> V_65 = V_55 ;
break;
case V_66 :
V_10 -> V_12 . V_22 -> V_67 &= ~ ( V_68 ) 0xffffffff ;
V_10 -> V_12 . V_22 -> V_67 |= V_55 ;
break;
case V_69 :
V_10 -> V_12 . V_22 -> V_70 = V_55 ;
break;
case V_71 :
V_10 -> V_12 . V_22 -> V_72 = V_55 ;
break;
case V_73 :
V_10 -> V_12 . V_22 -> V_67 &= ( V_68 ) 0xffffffff ;
V_10 -> V_12 . V_22 -> V_67 |= ( V_68 ) V_55 << 32 ;
break;
#endif
case V_74 :
V_39 -> V_40 = V_55 ;
V_39 -> V_40 &= ~ ( V_75 | V_76 ) ;
break;
case V_77 :
V_39 -> V_78 = V_55 ;
V_39 -> V_78 &= ~ ( V_79 | V_80 ) ;
break;
case V_81 :
V_39 -> V_82 = V_55 ;
break;
case V_83 :
V_39 -> V_84 = V_55 ;
break;
case V_85 :
V_28 = F_31 ( V_39 ,
V_55 ) ;
break;
case V_86 :
V_10 -> V_12 . V_87 [ V_88 ] = V_55 ;
break;
case V_89 :
V_10 -> V_12 . V_87 [ V_90 ] = V_55 ;
break;
case V_91 :
V_10 -> V_12 . V_87 [ V_92 ] = V_55 ;
break;
case V_93 :
V_10 -> V_12 . V_87 [ V_94 ] = V_55 ;
break;
#ifdef F_29
case V_95 :
V_10 -> V_12 . V_87 [ V_6 ] = V_55 ;
break;
case V_96 :
V_10 -> V_12 . V_87 [ V_8 ] = V_55 ;
break;
#endif
default:
V_28 = F_32 ( V_10 , V_54 , V_55 ) ;
}
return V_28 ;
}
int F_33 ( struct V_9 * V_10 , int V_54 , T_1 * V_55 )
{
struct V_38 * V_39 = F_13 ( V_10 ) ;
int V_28 = V_16 ;
switch ( V_54 ) {
#ifndef F_29
case V_56 :
* V_55 = V_39 -> V_58 [ 0 ] ;
break;
case V_57 :
* V_55 = V_39 -> V_58 [ 1 ] ;
break;
case V_59 :
* V_55 = V_39 -> V_58 [ 2 ] ;
break;
case V_60 :
* V_55 = V_10 -> V_12 . V_22 -> V_61 ;
break;
case V_62 :
* V_55 = V_10 -> V_12 . V_22 -> V_63 ;
break;
case V_64 :
* V_55 = V_10 -> V_12 . V_22 -> V_65 ;
break;
case V_66 :
* V_55 = ( V_97 ) V_10 -> V_12 . V_22 -> V_67 ;
break;
case V_69 :
* V_55 = V_10 -> V_12 . V_22 -> V_70 ;
break;
case V_71 :
* V_55 = V_10 -> V_12 . V_22 -> V_72 ;
break;
case V_73 :
* V_55 = V_10 -> V_12 . V_22 -> V_67 >> 32 ;
break;
#endif
case V_98 :
* V_55 = V_10 -> V_12 . V_99 ;
break;
case V_100 :
* V_55 = V_10 -> V_12 . V_101 [ 0 ] ;
break;
case V_102 :
* V_55 = V_10 -> V_12 . V_101 [ 1 ] ;
break;
case V_103 :
if ( ! F_34 ( V_10 , V_104 ) )
return V_14 ;
* V_55 = V_10 -> V_12 . V_105 [ 0 ] ;
break;
case V_106 :
if ( ! F_34 ( V_10 , V_104 ) )
return V_14 ;
* V_55 = V_10 -> V_12 . V_105 [ 1 ] ;
break;
case V_74 :
* V_55 = V_39 -> V_40 ;
break;
case V_77 :
* V_55 = V_39 -> V_78 ;
break;
case V_81 :
* V_55 = V_39 -> V_82 ;
break;
case V_83 :
* V_55 = V_39 -> V_84 ;
break;
case V_107 :
* V_55 = V_39 -> V_108 ;
break;
case V_85 :
* V_55 = 0 ;
break;
case V_109 :
* V_55 = V_10 -> V_12 . V_110 ;
break;
case V_111 :
if ( ! F_34 ( V_10 , V_104 ) )
return V_14 ;
* V_55 = V_10 -> V_12 . V_112 ;
break;
case V_86 :
* V_55 = V_10 -> V_12 . V_87 [ V_88 ] ;
break;
case V_89 :
* V_55 = V_10 -> V_12 . V_87 [ V_90 ] ;
break;
case V_91 :
* V_55 = V_10 -> V_12 . V_87 [ V_92 ] ;
break;
case V_93 :
* V_55 = V_10 -> V_12 . V_87 [ V_94 ] ;
break;
#ifdef F_29
case V_95 :
* V_55 = V_10 -> V_12 . V_87 [ V_6 ] ;
break;
case V_96 :
* V_55 = V_10 -> V_12 . V_87 [ V_8 ] ;
break;
#endif
default:
V_28 = F_35 ( V_10 , V_54 , V_55 ) ;
}
return V_28 ;
}
