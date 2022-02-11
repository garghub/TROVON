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
static int F_14 ( struct V_9 * V_10 , unsigned int V_26 ,
int V_42 )
{
if ( F_15 ( V_26 ) == V_43 ) {
F_16 ( V_10 , V_42 ,
1 | ( 1 << V_44 ) ) ;
return V_16 ;
}
return V_14 ;
}
int F_17 ( struct V_24 * V_25 , struct V_9 * V_10 ,
unsigned int V_26 , int * V_27 )
{
int V_28 = V_16 ;
int V_45 = F_18 ( V_26 ) ;
int V_11 = F_19 ( V_26 ) ;
int V_42 = F_20 ( V_26 ) ;
T_2 V_46 ;
switch ( F_21 ( V_26 ) ) {
case 31 :
switch ( F_22 ( V_26 ) ) {
case V_47 :
V_28 = F_12 ( V_10 ) ;
break;
#ifdef F_23
case V_48 :
V_28 = F_5 ( V_10 , V_11 ) ;
break;
case V_49 :
V_28 = F_3 ( V_10 , V_11 ) ;
break;
#endif
case V_50 :
V_28 = F_24 ( V_10 ) ;
break;
case V_51 :
V_28 = F_25 ( V_10 ) ;
break;
case V_52 :
V_46 = F_26 ( V_10 , V_45 , V_11 ) ;
V_28 = F_27 ( V_10 , V_46 ) ;
break;
case V_53 : {
int type = V_42 & 0x3 ;
V_46 = F_26 ( V_10 , V_45 , V_11 ) ;
V_28 = F_28 ( V_10 , type , V_46 ) ;
break;
}
case V_54 :
V_46 = F_26 ( V_10 , V_45 , V_11 ) ;
V_28 = F_29 ( V_10 , V_46 ) ;
break;
case V_55 :
V_28 = F_14 ( V_10 , V_26 , V_42 ) ;
break;
case V_56 :
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
V_28 = F_30 ( V_25 , V_10 , V_26 , V_27 ) ;
return V_28 ;
}
int F_31 ( struct V_9 * V_10 , int V_57 , T_1 V_58 )
{
struct V_38 * V_39 = F_13 ( V_10 ) ;
int V_28 = V_16 ;
switch ( V_57 ) {
#ifndef F_32
case V_59 :
F_33 ( V_10 , V_58 ) ;
break;
case V_60 :
if ( V_58 != 0 )
return V_14 ;
V_39 -> V_61 [ 1 ] = V_58 ;
break;
case V_62 :
if ( V_58 != 0 )
return V_14 ;
V_39 -> V_61 [ 2 ] = V_58 ;
break;
case V_63 :
V_10 -> V_12 . V_22 -> V_64 = V_58 ;
break;
case V_65 :
V_10 -> V_12 . V_22 -> V_66 = V_58 ;
break;
case V_67 :
V_10 -> V_12 . V_22 -> V_68 = V_58 ;
break;
case V_69 :
V_10 -> V_12 . V_22 -> V_70 &= ~ ( V_71 ) 0xffffffff ;
V_10 -> V_12 . V_22 -> V_70 |= V_58 ;
break;
case V_72 :
V_10 -> V_12 . V_22 -> V_73 = V_58 ;
break;
case V_74 :
V_10 -> V_12 . V_22 -> V_75 = V_58 ;
break;
case V_76 :
V_10 -> V_12 . V_22 -> V_70 &= ( V_71 ) 0xffffffff ;
V_10 -> V_12 . V_22 -> V_70 |= ( V_71 ) V_58 << 32 ;
break;
#endif
case V_77 :
V_39 -> V_40 = V_58 ;
V_39 -> V_40 &= ~ ( V_78 | V_79 ) ;
break;
case V_80 :
V_39 -> V_81 = V_58 ;
V_39 -> V_81 &= ~ ( V_82 | V_83 ) ;
break;
case V_84 :
V_39 -> V_85 = V_58 ;
break;
case V_86 :
V_39 -> V_87 = V_58 ;
break;
case V_88 :
V_28 = F_34 ( V_39 ,
V_58 ) ;
break;
case V_89 :
V_10 -> V_12 . V_90 = V_58 ;
break;
#ifdef F_35
case V_91 :
V_10 -> V_12 . V_92 [ V_93 ] = V_58 ;
break;
case V_94 :
V_10 -> V_12 . V_92 [ V_95 ] = V_58 ;
break;
case V_96 :
V_10 -> V_12 . V_92 [ V_97 ] = V_58 ;
break;
#endif
#ifdef F_36
case V_91 :
V_10 -> V_12 . V_92 [ V_98 ] = V_58 ;
break;
case V_94 :
V_10 -> V_12 . V_92 [ V_99 ] = V_58 ;
break;
#endif
case V_100 :
V_10 -> V_12 . V_92 [ V_101 ] = V_58 ;
break;
#ifdef F_32
case V_102 :
V_10 -> V_12 . V_92 [ V_6 ] = V_58 ;
break;
case V_103 :
V_10 -> V_12 . V_92 [ V_8 ] = V_58 ;
break;
#endif
default:
V_28 = F_37 ( V_10 , V_57 , V_58 ) ;
}
return V_28 ;
}
int F_38 ( struct V_9 * V_10 , int V_57 , T_1 * V_58 )
{
struct V_38 * V_39 = F_13 ( V_10 ) ;
int V_28 = V_16 ;
switch ( V_57 ) {
#ifndef F_32
case V_59 :
* V_58 = V_39 -> V_61 [ 0 ] ;
break;
case V_60 :
* V_58 = V_39 -> V_61 [ 1 ] ;
break;
case V_62 :
* V_58 = V_39 -> V_61 [ 2 ] ;
break;
case V_63 :
* V_58 = V_10 -> V_12 . V_22 -> V_64 ;
break;
case V_65 :
* V_58 = V_10 -> V_12 . V_22 -> V_66 ;
break;
case V_67 :
* V_58 = V_10 -> V_12 . V_22 -> V_68 ;
break;
case V_69 :
* V_58 = ( V_104 ) V_10 -> V_12 . V_22 -> V_70 ;
break;
case V_72 :
* V_58 = V_10 -> V_12 . V_22 -> V_73 ;
break;
case V_74 :
* V_58 = V_10 -> V_12 . V_22 -> V_75 ;
break;
case V_76 :
* V_58 = V_10 -> V_12 . V_22 -> V_70 >> 32 ;
break;
#endif
case V_105 :
* V_58 = V_10 -> V_12 . V_106 ;
break;
case V_107 :
* V_58 = V_10 -> V_12 . V_108 [ 0 ] ;
break;
case V_109 :
* V_58 = V_10 -> V_12 . V_108 [ 1 ] ;
break;
case V_110 :
if ( ! F_39 ( V_10 , V_111 ) )
return V_14 ;
* V_58 = V_10 -> V_12 . V_112 [ 0 ] ;
break;
case V_113 :
if ( ! F_39 ( V_10 , V_111 ) )
return V_14 ;
* V_58 = V_10 -> V_12 . V_112 [ 1 ] ;
break;
case V_77 :
* V_58 = V_39 -> V_40 ;
break;
case V_80 :
* V_58 = V_39 -> V_81 ;
break;
case V_84 :
* V_58 = V_39 -> V_85 ;
break;
case V_86 :
* V_58 = V_39 -> V_87 ;
break;
case V_114 :
* V_58 = V_39 -> V_115 ;
break;
case V_88 :
* V_58 = 0 ;
break;
case V_116 :
* V_58 = V_10 -> V_12 . V_117 ;
break;
case V_118 :
if ( ! F_39 ( V_10 , V_111 ) )
return V_14 ;
* V_58 = V_10 -> V_12 . V_119 ;
break;
case V_89 :
* V_58 = V_10 -> V_12 . V_90 ;
break;
#ifdef F_35
case V_91 :
* V_58 = V_10 -> V_12 . V_92 [ V_93 ] ;
break;
case V_94 :
* V_58 = V_10 -> V_12 . V_92 [ V_95 ] ;
break;
case V_96 :
* V_58 = V_10 -> V_12 . V_92 [ V_97 ] ;
break;
#endif
#ifdef F_36
case V_91 :
* V_58 = V_10 -> V_12 . V_92 [ V_98 ] ;
break;
case V_94 :
* V_58 = V_10 -> V_12 . V_92 [ V_99 ] ;
break;
#endif
case V_100 :
* V_58 = V_10 -> V_12 . V_92 [ V_101 ] ;
break;
#ifdef F_32
case V_102 :
* V_58 = V_10 -> V_12 . V_92 [ V_6 ] ;
break;
case V_103 :
* V_58 = V_10 -> V_12 . V_92 [ V_8 ] ;
break;
#endif
default:
V_28 = F_40 ( V_10 , V_57 , V_58 ) ;
}
return V_28 ;
}
