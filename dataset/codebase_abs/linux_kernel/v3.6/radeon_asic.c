static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( L_1 , V_3 ) ;
F_3 ( 1 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( L_2 ,
V_3 , V_4 ) ;
F_3 ( 1 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
V_2 -> V_5 = & F_1 ;
V_2 -> V_6 = & F_4 ;
V_2 -> V_7 = & F_1 ;
V_2 -> V_8 = & F_4 ;
V_2 -> V_9 = & F_1 ;
V_2 -> V_10 = & F_4 ;
if ( V_2 -> V_11 < V_12 ) {
V_2 -> V_13 = 0xff ;
} else {
V_2 -> V_13 = 0x7ff ;
}
if ( V_2 -> V_11 <= V_14 ) {
V_2 -> V_7 = & V_15 ;
V_2 -> V_8 = & V_16 ;
}
if ( V_2 -> V_11 >= V_17 ) {
V_2 -> V_5 = & V_18 ;
V_2 -> V_6 = & V_19 ;
}
if ( V_2 -> V_11 >= V_12 ) {
V_2 -> V_5 = & V_20 ;
V_2 -> V_6 = & V_21 ;
}
if ( V_2 -> V_11 == V_22 || V_2 -> V_11 == V_23 ) {
V_2 -> V_5 = & V_24 ;
V_2 -> V_6 = & V_25 ;
}
if ( V_2 -> V_11 == V_26 || V_2 -> V_11 == V_27 ) {
V_2 -> V_5 = & V_28 ;
V_2 -> V_6 = & V_29 ;
}
if ( V_2 -> V_11 == V_30 ) {
V_2 -> V_5 = & V_31 ;
V_2 -> V_6 = & V_32 ;
}
if ( V_2 -> V_11 >= V_33 ) {
V_2 -> V_9 = & V_34 ;
V_2 -> V_10 = & V_35 ;
}
}
void F_6 ( struct V_1 * V_2 )
{
V_2 -> V_36 &= ~ V_37 ;
if ( V_2 -> V_11 >= V_33 ) {
F_7 ( L_3 ) ;
V_2 -> V_36 |= V_38 ;
} else if ( V_2 -> V_11 >= V_12 ||
V_2 -> V_11 == V_39 ||
V_2 -> V_11 == V_40 ||
V_2 -> V_11 == V_41 ) {
F_7 ( L_3 ) ;
V_2 -> V_36 |= V_38 ;
V_2 -> V_42 -> V_43 . V_44 = & V_45 ;
V_2 -> V_42 -> V_43 . V_46 = & V_47 ;
} else {
F_7 ( L_4 ) ;
V_2 -> V_36 |= V_48 ;
V_2 -> V_42 -> V_43 . V_44 = & V_49 ;
V_2 -> V_42 -> V_43 . V_46 = & V_50 ;
}
V_2 -> V_51 . V_52 = V_53 * 1024 * 1024 ;
}
int F_8 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
if ( V_2 -> V_36 & V_54 )
V_2 -> V_55 = 1 ;
else
V_2 -> V_55 = 2 ;
switch ( V_2 -> V_11 ) {
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
V_2 -> V_42 = & V_61 ;
break;
case V_62 :
case V_63 :
case V_64 :
case V_65 :
V_2 -> V_42 = & V_66 ;
break;
case V_67 :
case V_68 :
case V_69 :
case V_39 :
if ( V_2 -> V_36 & V_38 )
V_2 -> V_42 = & V_70 ;
else
V_2 -> V_42 = & V_71 ;
break;
case V_17 :
case V_41 :
case V_40 :
V_2 -> V_42 = & V_72 ;
if ( V_2 -> V_73 == NULL ) {
V_2 -> V_42 -> V_74 . V_75 = & V_76 ;
V_2 -> V_42 -> V_74 . V_77 = & V_78 ;
V_2 -> V_42 -> V_74 . V_79 = & V_80 ;
V_2 -> V_42 -> V_74 . V_81 = NULL ;
}
break;
case V_22 :
case V_23 :
V_2 -> V_42 = & V_82 ;
break;
case V_30 :
V_2 -> V_42 = & V_83 ;
break;
case V_26 :
case V_27 :
V_2 -> V_42 = & V_84 ;
break;
case V_12 :
V_2 -> V_42 = & V_85 ;
break;
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_14 :
V_2 -> V_42 = & V_90 ;
break;
case V_33 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
V_2 -> V_42 = & V_96 ;
break;
case V_97 :
case V_98 :
V_2 -> V_42 = & V_99 ;
break;
case V_100 :
case V_101 :
case V_102 :
case V_103 :
V_2 -> V_42 = & V_104 ;
break;
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
if ( V_2 -> V_11 == V_105 )
V_2 -> V_55 = 4 ;
else
V_2 -> V_55 = 6 ;
V_2 -> V_42 = & V_110 ;
break;
case V_111 :
case V_112 :
case V_113 :
V_2 -> V_42 = & V_114 ;
break;
case V_115 :
case V_116 :
case V_117 :
if ( V_2 -> V_11 == V_117 )
V_2 -> V_55 = 4 ;
else
V_2 -> V_55 = 6 ;
V_2 -> V_42 = & V_118 ;
break;
case V_119 :
V_2 -> V_42 = & V_120 ;
V_2 -> V_55 = 6 ;
V_2 -> V_121 . V_122 = & V_123 ;
break;
case V_124 :
V_2 -> V_42 = & V_125 ;
V_2 -> V_55 = 4 ;
V_2 -> V_121 . V_122 = & V_123 ;
break;
case V_126 :
case V_127 :
case V_128 :
V_2 -> V_42 = & V_129 ;
V_2 -> V_55 = 6 ;
V_2 -> V_121 . V_122 = & V_130 ;
break;
default:
return - V_131 ;
}
if ( V_2 -> V_36 & V_132 ) {
V_2 -> V_42 -> V_74 . V_79 = NULL ;
V_2 -> V_42 -> V_74 . V_81 = NULL ;
}
return 0 ;
}
