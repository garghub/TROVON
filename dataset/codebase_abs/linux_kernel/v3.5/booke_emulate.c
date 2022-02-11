static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = V_2 -> V_3 . V_5 -> V_6 ;
F_2 ( V_2 , V_2 -> V_3 . V_5 -> V_7 ) ;
}
int F_3 ( struct V_8 * V_9 , struct V_1 * V_2 ,
unsigned int V_10 , int * V_11 )
{
int V_12 = V_13 ;
int V_14 = F_4 ( V_10 ) ;
int V_15 = F_5 ( V_10 ) ;
switch ( F_6 ( V_10 ) ) {
case 19 :
switch ( F_7 ( V_10 ) ) {
case V_16 :
F_1 ( V_2 ) ;
F_8 ( V_2 , V_17 ) ;
* V_11 = 0 ;
break;
default:
V_12 = V_18 ;
break;
}
break;
case 31 :
switch ( F_7 ( V_10 ) ) {
case V_19 :
F_9 ( V_2 , V_15 , V_2 -> V_3 . V_5 -> V_20 ) ;
F_8 ( V_2 , V_21 ) ;
break;
case V_22 :
F_8 ( V_2 , V_23 ) ;
F_2 ( V_2 , F_10 ( V_2 , V_14 ) ) ;
break;
case V_24 :
V_2 -> V_3 . V_5 -> V_20 = ( V_2 -> V_3 . V_5 -> V_20 & ~ V_25 )
| ( F_10 ( V_2 , V_14 ) & V_25 ) ;
F_8 ( V_2 , V_26 ) ;
break;
case V_27 :
V_2 -> V_3 . V_5 -> V_20 = ( V_2 -> V_3 . V_5 -> V_20 & ~ V_25 )
| ( V_10 & V_25 ) ;
F_8 ( V_2 , V_26 ) ;
break;
default:
V_12 = V_18 ;
}
break;
default:
V_12 = V_18 ;
}
return V_12 ;
}
int F_11 ( struct V_1 * V_2 , int V_28 , T_1 V_29 )
{
int V_12 = V_13 ;
switch ( V_28 ) {
case V_30 :
V_2 -> V_3 . V_5 -> V_31 = V_29 ;
break;
case V_32 :
V_2 -> V_3 . V_5 -> V_33 = V_29 ;
break;
case V_34 :
V_2 -> V_3 . V_35 = V_29 ;
break;
case V_36 :
V_2 -> V_3 . V_37 = V_29 ;
break;
case V_38 :
V_2 -> V_3 . V_39 &= ~ V_29 ;
break;
case V_40 :
F_12 ( V_2 , V_29 ) ;
break;
case V_41 :
F_13 ( V_2 , V_29 ) ;
break;
case V_42 :
V_2 -> V_3 . V_5 -> V_43 = V_29 ;
break;
case V_44 :
V_2 -> V_3 . V_5 -> V_45 = V_29 ;
break;
case V_46 :
V_2 -> V_3 . V_5 -> V_47 = V_29 ;
break;
case V_48 :
V_2 -> V_3 . V_5 -> V_49 = V_29 ;
break;
case V_50 :
V_2 -> V_3 . V_51 = V_29 ;
#ifdef F_14
F_15 ( V_52 , V_29 ) ;
#endif
break;
case V_53 :
V_2 -> V_3 . V_54 [ V_55 ] = V_29 ;
break;
case V_56 :
V_2 -> V_3 . V_54 [ V_57 ] = V_29 ;
break;
case V_58 :
V_2 -> V_3 . V_54 [ V_59 ] = V_29 ;
#ifdef F_14
F_15 ( V_60 , V_29 ) ;
#endif
break;
case V_61 :
V_2 -> V_3 . V_54 [ V_62 ] = V_29 ;
break;
case V_63 :
V_2 -> V_3 . V_54 [ V_64 ] = V_29 ;
break;
case V_65 :
V_2 -> V_3 . V_54 [ V_66 ] = V_29 ;
break;
case V_67 :
V_2 -> V_3 . V_54 [ V_68 ] = V_29 ;
break;
case V_69 :
V_2 -> V_3 . V_54 [ V_70 ] = V_29 ;
break;
case V_71 :
V_2 -> V_3 . V_54 [ V_72 ] = V_29 ;
#ifdef F_14
F_15 ( V_73 , V_29 ) ;
#endif
break;
case V_74 :
V_2 -> V_3 . V_54 [ V_75 ] = V_29 ;
break;
case V_76 :
V_2 -> V_3 . V_54 [ V_77 ] = V_29 ;
break;
case V_78 :
V_2 -> V_3 . V_54 [ V_79 ] = V_29 ;
break;
case V_80 :
V_2 -> V_3 . V_54 [ V_81 ] = V_29 ;
break;
case V_82 :
V_2 -> V_3 . V_54 [ V_83 ] = V_29 ;
break;
case V_84 :
V_2 -> V_3 . V_54 [ V_85 ] = V_29 ;
break;
case V_86 :
V_2 -> V_3 . V_54 [ V_87 ] = V_29 ;
break;
default:
V_12 = V_18 ;
}
return V_12 ;
}
int F_16 ( struct V_1 * V_2 , int V_28 , T_1 * V_29 )
{
int V_12 = V_13 ;
switch ( V_28 ) {
case V_50 :
* V_29 = V_2 -> V_3 . V_51 ;
break;
case V_30 :
* V_29 = V_2 -> V_3 . V_5 -> V_31 ;
break;
case V_32 :
* V_29 = V_2 -> V_3 . V_5 -> V_33 ;
break;
case V_34 :
* V_29 = V_2 -> V_3 . V_35 ;
break;
case V_36 :
* V_29 = V_2 -> V_3 . V_37 ;
break;
case V_38 :
* V_29 = V_2 -> V_3 . V_39 ;
break;
case V_40 :
* V_29 = V_2 -> V_3 . V_88 ;
break;
case V_41 :
* V_29 = V_2 -> V_3 . V_89 ;
break;
case V_53 :
* V_29 = V_2 -> V_3 . V_54 [ V_55 ] ;
break;
case V_56 :
* V_29 = V_2 -> V_3 . V_54 [ V_57 ] ;
break;
case V_58 :
* V_29 = V_2 -> V_3 . V_54 [ V_59 ] ;
break;
case V_61 :
* V_29 = V_2 -> V_3 . V_54 [ V_62 ] ;
break;
case V_63 :
* V_29 = V_2 -> V_3 . V_54 [ V_64 ] ;
break;
case V_65 :
* V_29 = V_2 -> V_3 . V_54 [ V_66 ] ;
break;
case V_67 :
* V_29 = V_2 -> V_3 . V_54 [ V_68 ] ;
break;
case V_69 :
* V_29 = V_2 -> V_3 . V_54 [ V_70 ] ;
break;
case V_71 :
* V_29 = V_2 -> V_3 . V_54 [ V_72 ] ;
break;
case V_74 :
* V_29 = V_2 -> V_3 . V_54 [ V_75 ] ;
break;
case V_76 :
* V_29 = V_2 -> V_3 . V_54 [ V_77 ] ;
break;
case V_78 :
* V_29 = V_2 -> V_3 . V_54 [ V_79 ] ;
break;
case V_80 :
* V_29 = V_2 -> V_3 . V_54 [ V_81 ] ;
break;
case V_82 :
* V_29 = V_2 -> V_3 . V_54 [ V_83 ] ;
break;
case V_84 :
* V_29 = V_2 -> V_3 . V_54 [ V_85 ] ;
break;
case V_86 :
* V_29 = V_2 -> V_3 . V_54 [ V_87 ] ;
break;
default:
V_12 = V_18 ;
}
return V_12 ;
}
