int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 , V_5 , V_6 , V_7 ;
for ( V_4 = 1 ; V_4 <= 5 ; V_4 ++ ) {
V_5 = V_2 -> V_8 ( V_2 -> V_9 , V_3 , V_4 , V_10 ) ;
if ( V_5 < 0 ||
( V_5 & V_11 ) != V_12 )
continue;
V_6 = V_2 -> V_8 ( V_2 -> V_9 , V_3 , V_4 , V_13 ) ;
V_7 = V_2 -> V_8 ( V_2 -> V_9 , V_3 , V_4 , V_14 ) ;
if ( V_6 < 0 || V_7 < 0 )
continue;
V_2 -> V_3 = V_3 ;
V_2 -> V_15 = V_6 | ( V_7 << 16 ) ;
return 0 ;
}
return - V_16 ;
}
int F_2 ( const struct V_1 * V_2 ,
int V_3 , int V_17 , T_1 V_18 , int V_19 ,
bool V_20 )
{
int V_21 = V_2 -> V_8 ( V_2 -> V_9 , V_3 , V_17 , V_18 ) ;
int V_22 ;
if ( V_21 < 0 )
return V_21 ;
if ( V_20 )
V_22 = V_21 | V_19 ;
else
V_22 = V_21 & ~ V_19 ;
if ( V_21 == V_22 )
return 0 ;
return V_2 -> V_23 ( V_2 -> V_9 , V_3 , V_17 , V_18 , V_22 ) ;
}
int F_3 ( const struct V_1 * V_2 , T_2 V_24 )
{
int V_17 , V_25 ;
if ( ! V_24 ) {
V_25 = V_2 -> V_8 ( V_2 -> V_9 , V_2 -> V_3 ,
V_26 , V_10 ) ;
return V_25 >= 0 && ! ( V_25 & V_27 ) ;
}
for ( V_17 = 0 ; V_24 ; V_17 ++ ) {
if ( V_24 & ( 1 << V_17 ) ) {
V_24 &= ~ ( 1 << V_17 ) ;
V_2 -> V_8 ( V_2 -> V_9 , V_2 -> V_3 ,
V_17 , V_28 ) ;
if ( V_17 == V_29 || V_17 == V_30 ||
V_17 == V_26 || V_17 == V_31 )
V_2 -> V_8 ( V_2 -> V_9 , V_2 -> V_3 ,
V_17 , V_10 ) ;
V_25 = V_2 -> V_8 ( V_2 -> V_9 , V_2 -> V_3 ,
V_17 , V_28 ) ;
if ( V_25 < 0 ||
( V_25 & ( V_32 | V_33 ) ) !=
V_33 )
return false ;
}
}
return true ;
}
int F_4 ( const struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_15 & V_34 ) )
return - V_35 ;
F_2 ( V_2 , V_2 -> V_3 , V_36 , V_37 ,
V_38 , true ) ;
return 0 ;
}
static T_2 F_5 ( const struct V_1 * V_2 , T_1 V_18 )
{
T_2 V_39 = 0 ;
int V_25 ;
V_25 = V_2 -> V_8 ( V_2 -> V_9 , V_2 -> V_3 , V_36 , V_18 ) ;
if ( V_25 & V_40 )
V_39 |= V_41 ;
if ( V_25 & V_42 )
V_39 |= V_43 ;
if ( V_25 & V_44 )
V_39 |= V_45 ;
if ( V_25 & V_46 )
V_39 |= V_47 ;
if ( V_25 & V_48 )
V_39 |= V_49 ;
if ( V_25 & V_50 )
V_39 |= V_51 ;
return V_39 ;
}
void F_6 ( const struct V_1 * V_2 ,
struct V_52 * V_53 ,
T_2 V_54 , T_2 V_55 )
{
int V_25 ;
T_2 V_56 ;
F_7 ( V_57 != V_58 ) ;
F_7 ( V_59 != V_60 ) ;
V_53 -> V_61 = V_62 ;
V_53 -> V_63 = V_2 -> V_3 ;
V_53 -> V_64 =
V_2 -> V_65 & ( V_59 | V_57 ) ;
V_25 = V_2 -> V_8 ( V_2 -> V_9 , V_2 -> V_3 , V_29 ,
V_66 ) ;
switch ( V_25 & V_67 ) {
case V_68 :
case V_69 :
case V_70 :
case V_71 :
V_53 -> V_72 = V_73 ;
V_53 -> V_74 = V_75 ;
V_25 = V_2 -> V_8 ( V_2 -> V_9 , V_2 -> V_3 , V_29 ,
V_76 ) ;
if ( V_25 & V_77 )
V_53 -> V_74 |= V_78 ;
if ( V_25 & V_79 )
V_53 -> V_74 |= ( V_80 |
V_81 ) ;
if ( V_25 & V_82 )
V_53 -> V_74 |= ( V_83 |
V_84 ) ;
if ( V_25 & V_85 )
V_53 -> V_74 |= ( V_86 |
V_87 ) ;
V_53 -> V_88 = V_89 ;
break;
case V_90 :
V_53 -> V_72 = V_91 ;
V_53 -> V_74 = 0 ;
V_53 -> V_88 = 0 ;
break;
case V_92 :
case V_93 :
case V_94 :
V_53 -> V_72 = V_91 ;
V_53 -> V_74 = V_95 ;
V_25 = V_2 -> V_8 ( V_2 -> V_9 , V_2 -> V_3 , V_29 ,
V_96 ) ;
if ( V_25 & V_97 )
V_53 -> V_74 |= V_98 ;
if ( V_25 & V_99 )
V_53 -> V_74 |= V_100 ;
if ( V_25 & V_101 )
V_53 -> V_74 |= V_102 ;
V_25 = V_2 -> V_8 ( V_2 -> V_9 , V_2 -> V_3 , V_29 ,
V_103 ) ;
if ( V_25 & V_104 )
V_53 -> V_74 |= V_105 ;
V_53 -> V_88 = V_106 ;
break;
default:
V_53 -> V_72 = V_107 ;
V_53 -> V_74 = V_108 ;
V_53 -> V_88 = V_109 ;
break;
}
if ( V_2 -> V_15 & V_34 ) {
V_53 -> V_74 |= V_110 ;
V_25 = V_2 -> V_8 ( V_2 -> V_9 , V_2 -> V_3 , V_36 ,
V_37 ) ;
if ( V_25 & V_111 ) {
V_53 -> V_112 = V_113 ;
V_53 -> V_88 |=
V_114 |
F_5 ( V_2 , V_115 ) |
V_54 ;
} else {
V_53 -> V_112 = V_116 ;
}
} else {
V_53 -> V_112 = V_116 ;
}
if ( V_53 -> V_112 ) {
T_2 V_117 = 0 ;
int V_118 = V_2 -> V_8 ( V_2 -> V_9 , V_2 -> V_3 ,
V_36 , V_28 ) ;
if ( V_118 & V_119 ) {
V_53 -> V_120 =
F_5 ( V_2 , V_121 ) | V_55 ;
if ( V_118 & V_122 )
V_53 -> V_120 |= V_114 ;
V_117 = V_53 -> V_88 & V_53 -> V_120 ;
}
if ( ( V_117 & ~ V_114 ) == 0 )
V_117 = V_53 -> V_88 ;
if ( V_117 & ( V_123 |
V_124 |
V_125 ) ) {
V_56 = V_126 ;
V_53 -> V_127 = V_128 ;
} else if ( V_117 & ( V_129 |
V_130 |
V_131 ) ) {
V_56 = V_132 ;
V_53 -> V_127 = ! ( V_117 & V_130 ) ;
} else if ( V_117 & ( V_47 |
V_45 ) ) {
V_56 = V_133 ;
V_53 -> V_127 = ! ! ( V_117 & V_47 ) ;
} else {
V_56 = V_134 ;
V_53 -> V_127 = ! ! ( V_117 & V_43 ) ;
}
} else {
V_25 = V_2 -> V_8 ( V_2 -> V_9 , V_2 -> V_3 , V_29 ,
V_37 ) ;
V_56 = ( ( ( V_25 & V_135 ) ? 100 : 1 )
* ( ( V_25 & V_136 ) ? 100 : 10 ) ) ;
V_53 -> V_127 = ( V_25 & V_137 ||
V_56 == V_126 ) ;
}
F_8 ( V_53 , V_56 ) ;
if ( V_53 -> V_72 == V_73
&& ( F_9 ( V_53 ) == V_126 ) ) {
switch ( V_2 -> V_8 ( V_2 -> V_9 , V_2 -> V_3 , V_29 ,
V_138 ) ) {
case V_139 | V_140 :
V_53 -> V_141 = V_142 ;
break;
case 0 :
V_53 -> V_141 = V_143 ;
break;
default:
V_53 -> V_141 = V_144 ;
break;
}
}
}
int F_10 ( const struct V_1 * V_2 ,
struct V_145 * V_146 , int V_147 )
{
int V_3 , V_17 ;
T_1 V_18 = V_146 -> V_148 ;
switch ( V_147 ) {
case V_149 :
if ( V_2 -> V_3 == V_150 )
return - V_35 ;
V_146 -> V_151 = V_2 -> V_3 ;
V_147 = V_152 ;
break;
case V_152 :
case V_153 :
break;
default:
return - V_35 ;
}
if ( ( V_2 -> V_65 & V_59 ) &&
F_11 ( V_146 -> V_151 ) ) {
V_3 = F_12 ( V_146 -> V_151 ) ;
V_17 = F_13 ( V_146 -> V_151 ) ;
} else if ( ( V_2 -> V_65 & V_57 ) &&
V_146 -> V_151 < 0x20 ) {
V_3 = V_146 -> V_151 ;
V_17 = V_154 ;
V_18 &= 0x1f ;
} else if ( ( V_2 -> V_65 & V_155 ) &&
V_2 -> V_3 != V_150 &&
V_146 -> V_151 == V_2 -> V_3 ) {
V_3 = V_2 -> V_3 ;
switch ( V_18 ) {
case V_156 :
case V_157 :
case V_158 :
case V_159 :
V_17 = F_14 ( V_2 -> V_15 ) ;
break;
case V_160 :
case V_161 :
if ( ! ( V_2 -> V_15 & V_34 ) )
return - V_162 ;
V_17 = V_36 ;
if ( V_18 == V_160 )
V_18 = V_115 ;
else
V_18 = V_121 ;
break;
default:
return - V_162 ;
}
} else {
return - V_162 ;
}
if ( V_147 == V_152 ) {
int V_163 = V_2 -> V_8 ( V_2 -> V_9 , V_3 , V_17 , V_18 ) ;
if ( V_163 < 0 )
return V_163 ;
V_146 -> V_164 = V_163 ;
return 0 ;
} else {
return V_2 -> V_23 ( V_2 -> V_9 , V_3 , V_17 , V_18 ,
V_146 -> V_165 ) ;
}
}
