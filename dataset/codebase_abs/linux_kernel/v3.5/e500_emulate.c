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
switch ( F_13 ( V_26 ) ) {
case 31 :
switch ( F_14 ( V_26 ) ) {
#ifdef F_15
case V_31 :
V_28 = F_5 ( V_10 , V_11 ) ;
break;
case V_32 :
V_28 = F_3 ( V_10 , V_11 ) ;
break;
#endif
case V_33 :
V_28 = F_16 ( V_10 ) ;
break;
case V_34 :
V_28 = F_17 ( V_10 ) ;
break;
case V_35 :
V_28 = F_18 ( V_10 , V_11 ) ;
break;
case V_36 :
V_28 = F_19 ( V_10 , V_30 , V_29 , V_11 ) ;
break;
case V_37 :
V_28 = F_20 ( V_10 , V_29 , V_11 ) ;
break;
default:
V_28 = V_14 ;
}
break;
default:
V_28 = V_14 ;
}
if ( V_28 == V_14 )
V_28 = F_21 ( V_25 , V_10 , V_26 , V_27 ) ;
return V_28 ;
}
int F_22 ( struct V_9 * V_10 , int V_38 , T_1 V_39 )
{
struct V_40 * V_41 = F_23 ( V_10 ) ;
int V_28 = V_16 ;
switch ( V_38 ) {
#ifndef F_24
case V_42 :
F_25 ( V_10 , V_39 ) ;
break;
case V_43 :
if ( V_39 != 0 )
return V_14 ;
V_41 -> V_44 [ 1 ] = V_39 ;
break;
case V_45 :
if ( V_39 != 0 )
return V_14 ;
V_41 -> V_44 [ 2 ] = V_39 ;
break;
case V_46 :
V_10 -> V_12 . V_22 -> V_47 = V_39 ;
break;
case V_48 :
V_10 -> V_12 . V_22 -> V_49 = V_39 ;
break;
case V_50 :
V_10 -> V_12 . V_22 -> V_51 = V_39 ;
break;
case V_52 :
V_10 -> V_12 . V_22 -> V_53 &= ~ ( V_54 ) 0xffffffff ;
V_10 -> V_12 . V_22 -> V_53 |= V_39 ;
break;
case V_55 :
V_10 -> V_12 . V_22 -> V_56 = V_39 ;
break;
case V_57 :
V_10 -> V_12 . V_22 -> V_58 = V_39 ;
break;
case V_59 :
V_10 -> V_12 . V_22 -> V_53 &= ( V_54 ) 0xffffffff ;
V_10 -> V_12 . V_22 -> V_53 |= ( V_54 ) V_39 << 32 ;
break;
#endif
case V_60 :
V_41 -> V_61 = V_39 ;
V_41 -> V_61 &= ~ ( V_62 | V_63 ) ;
break;
case V_64 :
V_41 -> V_65 = V_39 ;
break;
case V_66 :
V_41 -> V_67 = V_39 ;
break;
case V_68 :
V_41 -> V_69 = V_39 ;
break;
case V_70 :
V_28 = F_26 ( V_41 ,
V_39 ) ;
break;
case V_71 :
V_10 -> V_12 . V_72 [ V_73 ] = V_39 ;
break;
case V_74 :
V_10 -> V_12 . V_72 [ V_75 ] = V_39 ;
break;
case V_76 :
V_10 -> V_12 . V_72 [ V_77 ] = V_39 ;
break;
case V_78 :
V_10 -> V_12 . V_72 [ V_79 ] = V_39 ;
break;
#ifdef F_24
case V_80 :
V_10 -> V_12 . V_72 [ V_6 ] = V_39 ;
break;
case V_81 :
V_10 -> V_12 . V_72 [ V_8 ] = V_39 ;
break;
#endif
default:
V_28 = F_27 ( V_10 , V_38 , V_39 ) ;
}
return V_28 ;
}
int F_28 ( struct V_9 * V_10 , int V_38 , T_1 * V_39 )
{
struct V_40 * V_41 = F_23 ( V_10 ) ;
int V_28 = V_16 ;
switch ( V_38 ) {
#ifndef F_24
case V_42 :
* V_39 = V_41 -> V_44 [ 0 ] ;
break;
case V_43 :
* V_39 = V_41 -> V_44 [ 1 ] ;
break;
case V_45 :
* V_39 = V_41 -> V_44 [ 2 ] ;
break;
case V_46 :
* V_39 = V_10 -> V_12 . V_22 -> V_47 ;
break;
case V_48 :
* V_39 = V_10 -> V_12 . V_22 -> V_49 ;
break;
case V_50 :
* V_39 = V_10 -> V_12 . V_22 -> V_51 ;
break;
case V_52 :
* V_39 = ( V_82 ) V_10 -> V_12 . V_22 -> V_53 ;
break;
case V_55 :
* V_39 = V_10 -> V_12 . V_22 -> V_56 ;
break;
case V_57 :
* V_39 = V_10 -> V_12 . V_22 -> V_58 ;
break;
case V_59 :
* V_39 = V_10 -> V_12 . V_22 -> V_53 >> 32 ;
break;
#endif
case V_83 :
* V_39 = V_10 -> V_12 . V_84 [ 0 ] ;
break;
case V_85 :
* V_39 = V_10 -> V_12 . V_84 [ 1 ] ;
break;
case V_60 :
* V_39 = V_41 -> V_61 ;
break;
case V_64 :
* V_39 = V_41 -> V_65 ;
break;
case V_66 :
* V_39 = V_41 -> V_67 ;
break;
case V_68 :
* V_39 = V_41 -> V_69 ;
break;
case V_86 :
* V_39 = V_41 -> V_87 ;
break;
case V_70 :
* V_39 = 0 ;
break;
case V_88 :
* V_39 = V_10 -> V_12 . V_89 ;
break;
case V_71 :
* V_39 = V_10 -> V_12 . V_72 [ V_73 ] ;
break;
case V_74 :
* V_39 = V_10 -> V_12 . V_72 [ V_75 ] ;
break;
case V_76 :
* V_39 = V_10 -> V_12 . V_72 [ V_77 ] ;
break;
case V_78 :
* V_39 = V_10 -> V_12 . V_72 [ V_79 ] ;
break;
#ifdef F_24
case V_80 :
* V_39 = V_10 -> V_12 . V_72 [ V_6 ] ;
break;
case V_81 :
* V_39 = V_10 -> V_12 . V_72 [ V_8 ] ;
break;
#endif
default:
V_28 = F_29 ( V_10 , V_38 , V_39 ) ;
}
return V_28 ;
}
