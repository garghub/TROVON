static bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 , V_5 ;
V_3 = F_2 ( V_2 , V_6 ) ;
if ( ( V_3 & V_7 ) != V_8 )
return false ;
V_4 = F_2 ( V_2 , V_9 ) ;
if ( ! ( V_4 & V_10 ) )
return false ;
V_5 = F_2 ( V_2 , V_11 ) ;
if ( V_5 & V_12 )
return false ;
return true ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
if ( ( V_14 -> V_15 . V_16 ( V_2 ) == V_17 ) &&
! V_2 -> V_18 ) {
V_14 -> V_15 . V_19 =
& V_20 ;
V_14 -> V_15 . V_21 =
& V_22 ;
V_14 -> V_15 . V_23 = & V_24 ;
} else {
V_14 -> V_15 . V_19 = NULL ;
V_14 -> V_15 . V_21 = NULL ;
V_14 -> V_15 . V_23 = NULL ;
}
if ( V_2 -> V_25 . V_26 ) {
V_14 -> V_15 . V_27 = & V_28 ;
} else {
if ( ( V_14 -> V_15 . V_16 ( V_2 ) ==
V_29 ) &&
( V_2 -> V_25 . V_30 == V_31 ||
V_2 -> V_25 . V_30 == V_32 ) &&
! F_4 ( V_2 ) )
V_14 -> V_15 . V_27 = & V_33 ;
else
V_14 -> V_15 . V_27 = & V_34 ;
}
}
static T_2 F_5 ( struct V_1 * V_2 )
{
T_2 V_35 = 0 ;
T_3 V_36 , V_37 , V_38 ;
bool V_39 = false ;
if ( V_2 -> V_25 . V_40 != V_41 ) {
F_3 ( V_2 ) ;
V_2 -> V_25 . V_15 . V_42 = NULL ;
V_35 = F_6 ( V_2 , & V_36 ,
& V_37 ) ;
if ( V_35 != 0 )
goto V_43;
V_35 = V_2 -> V_14 . V_15 . V_44 ( V_2 ,
V_45 ) ;
if ( V_35 != 0 ) {
V_35 = V_46 ;
goto V_43;
}
V_2 -> V_47 . V_15 . V_48 ( V_2 , ++ V_37 , & V_38 ) ;
while ( V_38 != 0xffff ) {
F_7 ( V_2 , V_49 , V_38 ) ;
F_8 ( V_2 ) ;
V_2 -> V_47 . V_15 . V_48 ( V_2 , ++ V_37 , & V_38 ) ;
}
V_2 -> V_14 . V_15 . V_50 ( V_2 , V_45 ) ;
F_9 ( V_2 -> V_47 . V_51 * 1000 ,
V_2 -> V_47 . V_51 * 2000 ) ;
if ( F_4 ( V_2 ) ) {
V_35 = V_2 -> V_14 . V_15 . V_44 ( V_2 ,
V_45 ) ;
if ( V_35 )
goto V_43;
V_39 = true ;
}
F_7 ( V_2 , V_52 , ( ( V_2 -> V_14 . V_53 ) |
V_54 ) ) ;
V_2 -> V_14 . V_55 = F_2 ( V_2 , V_52 ) ;
V_35 = F_10 ( V_2 ) ;
if ( V_39 ) {
V_2 -> V_14 . V_15 . V_50 ( V_2 ,
V_45 ) ;
V_39 = false ;
}
if ( V_35 ) {
F_11 ( V_2 , L_1 ) ;
V_35 = V_56 ;
goto V_43;
}
}
V_43:
return V_35 ;
}
static T_2 F_12 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
F_3 ( V_2 ) ;
V_14 -> V_57 = V_58 ;
V_14 -> V_59 = V_60 ;
V_14 -> V_61 = V_62 ;
V_14 -> V_63 = V_64 ;
V_14 -> V_65 = V_66 ;
V_14 -> V_67 = F_13 ( V_2 ) ;
return 0 ;
}
static T_2 F_14 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_68 * V_25 = & V_2 -> V_25 ;
T_2 V_35 = 0 ;
V_35 = V_25 -> V_15 . V_69 ( V_2 ) ;
F_3 ( V_2 ) ;
if ( V_14 -> V_15 . V_16 ( V_2 ) == V_70 ) {
V_14 -> V_15 . V_27 = & V_71 ;
V_14 -> V_15 . V_72 =
& V_73 ;
}
switch ( V_2 -> V_25 . type ) {
case V_74 :
V_25 -> V_15 . V_75 = & V_76 ;
V_25 -> V_15 . V_27 = & V_77 ;
V_25 -> V_15 . V_78 =
& V_79 ;
break;
default:
break;
}
return V_35 ;
}
static T_2 F_15 ( struct V_1 * V_2 ,
T_4 * V_80 ,
bool * V_81 )
{
T_2 V_82 = 0 ;
T_1 V_83 = 0 ;
if ( V_2 -> V_25 . V_40 == V_84 ||
V_2 -> V_25 . V_40 == V_85 ||
V_2 -> V_25 . V_40 == V_86 ||
V_2 -> V_25 . V_40 == V_87 ||
V_2 -> V_25 . V_40 == V_88 ||
V_2 -> V_25 . V_40 == V_89 ) {
* V_80 = V_90 ;
* V_81 = true ;
goto V_91;
}
if ( V_2 -> V_14 . V_92 )
V_83 = V_2 -> V_14 . V_53 ;
else
V_83 = F_2 ( V_2 , V_52 ) ;
switch ( V_83 & V_93 ) {
case V_94 :
* V_80 = V_90 ;
* V_81 = false ;
break;
case V_95 :
* V_80 = V_96 ;
* V_81 = false ;
break;
case V_97 :
* V_80 = V_90 ;
* V_81 = true ;
break;
case V_54 :
* V_80 = V_96 ;
* V_81 = false ;
break;
case V_98 :
case V_99 :
* V_80 = V_100 ;
if ( V_83 & V_101 )
* V_80 |= V_96 ;
if ( V_83 & V_102 )
* V_80 |= V_96 ;
if ( V_83 & V_103 )
* V_80 |= V_90 ;
* V_81 = true ;
break;
case V_104 :
* V_80 = V_105 ;
if ( V_83 & V_101 )
* V_80 |= V_96 ;
if ( V_83 & V_102 )
* V_80 |= V_96 ;
if ( V_83 & V_103 )
* V_80 |= V_90 ;
* V_81 = true ;
break;
case V_106 :
* V_80 = V_90 | V_105 ;
* V_81 = false ;
break;
default:
V_82 = V_107 ;
goto V_91;
break;
}
if ( V_2 -> V_25 . V_26 ) {
* V_80 |= V_96 |
V_90 ;
* V_81 = true ;
}
V_91:
return V_82 ;
}
static enum V_108 F_16 ( struct V_1 * V_2 )
{
enum V_108 V_109 ;
switch ( V_2 -> V_25 . type ) {
case V_110 :
case V_74 :
V_109 = V_70 ;
goto V_91;
default:
break;
}
switch ( V_2 -> V_111 ) {
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
V_109 = V_29 ;
break;
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
V_109 = V_17 ;
break;
case V_124 :
V_109 = V_125 ;
break;
case V_126 :
V_109 = V_70 ;
break;
case V_127 :
V_109 = V_128 ;
break;
default:
V_109 = V_129 ;
break;
}
V_91:
return V_109 ;
}
static T_2 F_17 ( struct V_1 * V_2 ,
bool V_130 )
{
T_1 V_131 ;
T_1 V_132 ;
T_1 V_133 ;
T_2 V_82 = 0 ;
bool V_39 = false ;
if ( F_4 ( V_2 ) ) {
V_82 = V_2 -> V_14 . V_15 . V_44 ( V_2 ,
V_45 ) ;
if ( V_82 )
goto V_91;
V_39 = true ;
}
F_10 ( V_2 ) ;
if ( V_39 )
V_2 -> V_14 . V_15 . V_50 ( V_2 , V_45 ) ;
if ( V_130 ) {
V_131 = F_2 ( V_2 , V_52 ) ;
if ( ( V_131 & V_93 ) ==
V_98 ||
( V_131 & V_93 ) ==
V_99 ||
( V_131 & V_93 ) ==
V_104 ) {
V_132 = 0 ;
for ( V_133 = 0 ; V_133 < V_134 ; V_133 ++ ) {
V_132 = F_2 ( V_2 , V_135 ) ;
if ( V_132 & V_136 )
break;
F_18 ( 100 ) ;
}
if ( ! ( V_132 & V_136 ) ) {
V_82 = V_137 ;
F_11 ( V_2 , L_2 ) ;
}
}
}
F_18 ( 50 ) ;
V_91:
return V_82 ;
}
static void V_20 ( struct V_1 * V_2 )
{
T_1 V_138 = F_2 ( V_2 , V_139 ) ;
V_138 |= V_140 ;
F_7 ( V_2 , V_139 , V_138 ) ;
F_8 ( V_2 ) ;
F_19 ( 100 ) ;
}
static void V_22 ( struct V_1 * V_2 )
{
T_1 V_138 = F_2 ( V_2 , V_139 ) ;
V_138 &= ~ V_140 ;
F_7 ( V_2 , V_139 , V_138 ) ;
F_8 ( V_2 ) ;
F_18 ( 100 ) ;
}
static void V_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_141 ) {
V_20 ( V_2 ) ;
V_22 ( V_2 ) ;
V_2 -> V_14 . V_141 = false ;
}
}
static T_2 V_28 ( struct V_1 * V_2 ,
T_4 V_80 ,
bool V_130 )
{
T_2 V_82 = 0 ;
T_4 V_142 = V_100 ;
T_4 V_143 = V_100 ;
T_1 V_144 = 0 ;
T_1 V_138 = F_2 ( V_2 , V_139 ) ;
T_1 V_133 = 0 ;
bool V_145 = false ;
bool V_81 = false ;
V_82 = V_2 -> V_14 . V_15 . V_72 ( V_2 , & V_142 ,
& V_81 ) ;
if ( V_82 != 0 )
return V_82 ;
V_80 &= V_142 ;
if ( V_80 & V_96 ) {
V_144 ++ ;
V_143 = V_96 ;
V_82 = V_2 -> V_14 . V_15 . V_75 ( V_2 , & V_142 , & V_145 ,
false ) ;
if ( V_82 != 0 )
return V_82 ;
if ( ( V_142 == V_96 ) && V_145 )
goto V_91;
V_138 |= ( V_146 | V_147 ) ;
F_7 ( V_2 , V_139 , V_138 ) ;
F_8 ( V_2 ) ;
F_18 ( 40 ) ;
V_82 = V_34 ( V_2 ,
V_96 ,
V_130 ) ;
if ( V_82 != 0 )
return V_82 ;
if ( V_2 -> V_14 . V_15 . V_23 )
V_2 -> V_14 . V_15 . V_23 ( V_2 ) ;
for ( V_133 = 0 ; V_133 < 5 ; V_133 ++ ) {
F_18 ( 100 ) ;
V_82 = V_2 -> V_14 . V_15 . V_75 ( V_2 , & V_142 ,
& V_145 , false ) ;
if ( V_82 != 0 )
return V_82 ;
if ( V_145 )
goto V_91;
}
}
if ( V_80 & V_90 ) {
V_144 ++ ;
if ( V_143 == V_100 )
V_143 = V_90 ;
V_82 = V_2 -> V_14 . V_15 . V_75 ( V_2 , & V_142 , & V_145 ,
false ) ;
if ( V_82 != 0 )
return V_82 ;
if ( ( V_142 == V_90 ) && V_145 )
goto V_91;
V_138 &= ~ V_147 ;
V_138 |= V_146 ;
F_7 ( V_2 , V_139 , V_138 ) ;
F_8 ( V_2 ) ;
F_18 ( 40 ) ;
V_82 = V_34 ( V_2 ,
V_90 ,
V_130 ) ;
if ( V_82 != 0 )
return V_82 ;
if ( V_2 -> V_14 . V_15 . V_23 )
V_2 -> V_14 . V_15 . V_23 ( V_2 ) ;
F_18 ( 100 ) ;
V_82 = V_2 -> V_14 . V_15 . V_75 ( V_2 , & V_142 , & V_145 ,
false ) ;
if ( V_82 != 0 )
return V_82 ;
if ( V_145 )
goto V_91;
}
if ( V_144 > 1 )
V_82 = V_28 ( V_2 ,
V_143 ,
V_130 ) ;
V_91:
V_2 -> V_25 . V_148 = 0 ;
if ( V_80 & V_96 )
V_2 -> V_25 . V_148 |= V_96 ;
if ( V_80 & V_90 )
V_2 -> V_25 . V_148 |= V_90 ;
return V_82 ;
}
static T_2 V_33 ( struct V_1 * V_2 ,
T_4 V_80 ,
bool V_130 )
{
T_2 V_82 = 0 ;
T_4 V_142 = V_100 ;
T_2 V_133 , V_149 ;
bool V_145 = false ;
T_1 V_131 = F_2 ( V_2 , V_52 ) ;
V_2 -> V_25 . V_148 = 0 ;
if ( V_80 & V_96 )
V_2 -> V_25 . V_148 |= V_96 ;
if ( V_80 & V_90 )
V_2 -> V_25 . V_148 |= V_90 ;
if ( V_80 & V_105 )
V_2 -> V_25 . V_148 |= V_105 ;
V_2 -> V_25 . V_150 = false ;
for ( V_149 = 0 ; V_149 < V_151 ; V_149 ++ ) {
V_82 = V_34 ( V_2 , V_80 ,
V_130 ) ;
if ( V_82 != 0 )
goto V_91;
for ( V_133 = 0 ; V_133 < 5 ; V_133 ++ ) {
F_20 ( 100 ) ;
V_82 = V_2 -> V_14 . V_15 . V_75 ( V_2 , & V_142 ,
& V_145 , false ) ;
if ( V_82 != 0 )
goto V_91;
if ( V_145 )
goto V_91;
}
}
if ( ( ( V_131 & V_101 ) == 0 ) ||
( ( V_131 & V_152 ) == 0 ) )
goto V_91;
V_2 -> V_25 . V_150 = true ;
V_82 = V_34 ( V_2 , V_80 ,
V_130 ) ;
if ( V_82 != 0 )
goto V_91;
for ( V_133 = 0 ; V_133 < 6 ; V_133 ++ ) {
F_20 ( 100 ) ;
V_82 = V_2 -> V_14 . V_15 . V_75 ( V_2 , & V_142 ,
& V_145 , false ) ;
if ( V_82 != 0 )
goto V_91;
if ( V_145 )
goto V_91;
}
V_2 -> V_25 . V_150 = false ;
V_82 = V_34 ( V_2 , V_80 ,
V_130 ) ;
V_91:
if ( V_145 && ( V_142 == V_90 ) )
F_11 ( V_2 , L_3
L_4 ) ;
return V_82 ;
}
static T_2 V_34 ( struct V_1 * V_2 ,
T_4 V_80 ,
bool V_130 )
{
T_2 V_82 = 0 ;
T_1 V_83 , V_153 , V_154 , V_155 ;
T_1 V_156 = F_2 ( V_2 , V_157 ) ;
T_1 V_53 = 0 ;
T_1 V_158 = V_156 & V_159 ;
T_1 V_132 ;
T_1 V_133 ;
T_4 V_160 = V_100 ;
bool V_39 = false ;
bool V_81 = false ;
V_82 = V_2 -> V_14 . V_15 . V_72 ( V_2 , & V_160 ,
& V_81 ) ;
if ( V_82 != 0 )
goto V_91;
V_80 &= V_160 ;
if ( V_80 == V_100 ) {
V_82 = V_107 ;
goto V_91;
}
if ( V_2 -> V_14 . V_92 )
V_83 = V_2 -> V_14 . V_53 ;
else
V_83 = F_2 ( V_2 , V_52 ) ;
V_53 = V_83 ;
V_155 = V_2 -> V_14 . V_55 ;
V_154 = V_83 & V_93 ;
V_153 = V_83 & V_161 ;
if ( V_154 == V_98 ||
V_154 == V_99 ||
V_154 == V_104 ) {
V_83 &= ~ ( V_152 | V_101 ) ;
if ( V_80 & V_96 ) {
if ( V_53 & V_102 )
V_83 |= V_102 ;
if ( ( V_53 & V_101 ) &&
( V_2 -> V_25 . V_150 == false ) )
V_83 |= V_101 ;
}
if ( V_80 & V_90 )
V_83 |= V_103 ;
} else if ( ( V_153 == V_162 ) &&
( V_154 == V_94 ||
V_154 == V_97 ) ) {
if ( ( V_80 == V_96 ) &&
( V_158 == V_163 ) ) {
V_83 &= ~ V_93 ;
V_83 |= V_54 ;
}
} else if ( ( V_158 == V_163 ) &&
( V_154 == V_54 ) ) {
if ( ( V_80 == V_90 ) &&
( V_153 == V_162 ) ) {
V_83 &= ~ V_93 ;
if ( V_81 )
V_83 |= V_97 ;
else
V_83 |= V_94 ;
}
}
if ( V_83 != V_155 ) {
if ( F_4 ( V_2 ) ) {
V_82 = V_2 -> V_14 . V_15 . V_44 ( V_2 ,
V_45 ) ;
if ( V_82 != 0 )
goto V_91;
V_39 = true ;
}
F_7 ( V_2 , V_52 , V_83 ) ;
V_2 -> V_14 . V_55 = V_83 ;
F_10 ( V_2 ) ;
if ( V_39 )
V_2 -> V_14 . V_15 . V_50 ( V_2 ,
V_45 ) ;
if ( V_130 ) {
if ( V_154 == V_98 ||
V_154 == V_99 ||
V_154 == V_104 ) {
V_132 = 0 ;
for ( V_133 = 0 ; V_133 < V_134 ; V_133 ++ ) {
V_132 =
F_2 ( V_2 , V_135 ) ;
if ( V_132 & V_136 )
break;
F_18 ( 100 ) ;
}
if ( ! ( V_132 & V_136 ) ) {
V_82 =
V_137 ;
F_11 ( V_2 , L_5
L_6 ) ;
}
}
}
F_18 ( 50 ) ;
}
V_91:
return V_82 ;
}
static T_2 V_71 ( struct V_1 * V_2 ,
T_4 V_80 ,
bool V_130 )
{
T_2 V_82 ;
V_82 = V_2 -> V_25 . V_15 . V_164 ( V_2 , V_80 ,
V_130 ) ;
F_17 ( V_2 , V_130 ) ;
return V_82 ;
}
static T_2 F_21 ( struct V_1 * V_2 )
{
T_4 V_142 ;
T_2 V_82 ;
T_1 V_165 , V_133 , V_156 ;
T_1 V_166 ;
bool V_145 = false ;
V_82 = V_2 -> V_14 . V_15 . V_167 ( V_2 ) ;
if ( V_82 != 0 )
goto V_168;
F_22 ( V_2 ) ;
V_82 = V_2 -> V_25 . V_15 . V_169 ( V_2 ) ;
if ( V_82 == V_170 )
goto V_168;
if ( V_2 -> V_25 . V_171 ) {
V_82 = V_2 -> V_14 . V_15 . V_172 ( V_2 ) ;
V_2 -> V_25 . V_171 = false ;
}
if ( V_82 == V_170 )
goto V_168;
if ( V_2 -> V_25 . V_173 == false && V_2 -> V_25 . V_15 . V_42 != NULL )
V_2 -> V_25 . V_15 . V_42 ( V_2 ) ;
if ( V_2 -> V_14 . V_55 )
V_166 = V_2 -> V_14 . V_55 & V_93 ;
else
V_166 = F_2 ( V_2 , V_52 ) &
V_93 ;
V_174:
V_165 = V_175 ;
if ( ! V_2 -> V_176 ) {
V_2 -> V_14 . V_15 . V_75 ( V_2 , & V_142 , & V_145 , false ) ;
if ( V_145 )
V_165 = V_177 ;
}
V_165 |= F_2 ( V_2 , V_178 ) ;
F_7 ( V_2 , V_178 , V_165 ) ;
F_8 ( V_2 ) ;
for ( V_133 = 0 ; V_133 < 10 ; V_133 ++ ) {
F_19 ( 1 ) ;
V_165 = F_2 ( V_2 , V_178 ) ;
if ( ! ( V_165 & V_179 ) )
break;
}
if ( V_165 & V_179 ) {
V_82 = V_180 ;
F_11 ( V_2 , L_7 ) ;
}
F_18 ( 50 ) ;
if ( V_2 -> V_14 . V_181 & V_182 ) {
V_2 -> V_14 . V_181 &= ~ V_182 ;
goto V_174;
}
V_2 -> V_14 . V_55 = F_2 ( V_2 , V_52 ) ;
V_156 = F_2 ( V_2 , V_157 ) ;
if ( V_156 & V_183 ) {
V_156 &= ~ V_183 ;
F_7 ( V_2 , V_157 , V_156 ) ;
F_8 ( V_2 ) ;
}
if ( V_2 -> V_14 . V_92 == false ) {
V_2 -> V_14 . V_53 = V_2 -> V_14 . V_55 ;
V_2 -> V_14 . V_184 = V_156 ;
V_2 -> V_14 . V_92 = true ;
} else {
if ( ( V_2 -> V_25 . V_26 && V_2 -> V_18 ) ||
V_2 -> V_185 )
V_2 -> V_14 . V_53 =
( V_2 -> V_14 . V_53 & ~ V_93 ) |
V_166 ;
if ( V_2 -> V_14 . V_55 != V_2 -> V_14 . V_53 ) {
bool V_39 = false ;
if ( F_4 ( V_2 ) ) {
V_82 = V_2 -> V_14 . V_15 . V_44 ( V_2 ,
V_45 ) ;
if ( V_82 )
goto V_168;
V_39 = true ;
}
F_7 ( V_2 , V_52 , V_2 -> V_14 . V_53 ) ;
V_2 -> V_14 . V_55 = V_2 -> V_14 . V_53 ;
F_10 ( V_2 ) ;
if ( V_39 )
V_2 -> V_14 . V_15 . V_50 ( V_2 ,
V_45 ) ;
}
if ( ( V_156 & V_186 ) !=
( V_2 -> V_14 . V_184 & V_186 ) ) {
V_156 &= ~ V_186 ;
V_156 |= ( V_2 -> V_14 . V_184 &
V_186 ) ;
F_7 ( V_2 , V_157 , V_156 ) ;
}
}
V_2 -> V_14 . V_15 . V_187 ( V_2 , V_2 -> V_14 . V_188 ) ;
V_2 -> V_14 . V_61 = 128 ;
V_2 -> V_14 . V_15 . V_189 ( V_2 ) ;
V_2 -> V_14 . V_15 . V_190 ( V_2 , V_2 -> V_14 . V_191 ) ;
if ( F_23 ( V_2 -> V_14 . V_191 ) ) {
V_2 -> V_14 . V_15 . V_192 ( V_2 , V_2 -> V_14 . V_61 - 1 ,
V_2 -> V_14 . V_191 , 0 , V_193 ) ;
V_2 -> V_14 . V_194 = V_2 -> V_14 . V_61 - 1 ;
V_2 -> V_14 . V_61 -- ;
}
V_2 -> V_14 . V_15 . V_195 ( V_2 , & V_2 -> V_14 . V_196 ,
& V_2 -> V_14 . V_197 ) ;
V_168:
return V_82 ;
}
T_2 F_24 ( struct V_1 * V_2 )
{
int V_133 ;
T_1 V_198 = F_2 ( V_2 , V_199 ) ;
V_198 &= ~ V_200 ;
for ( V_133 = 0 ; V_133 < V_201 ; V_133 ++ ) {
if ( ! ( F_2 ( V_2 , V_202 ) &
V_203 ) )
break;
F_19 ( 10 ) ;
}
if ( V_133 >= V_201 ) {
F_11 ( V_2 , L_8
L_9 ) ;
return V_204 ;
}
F_7 ( V_2 , V_205 , 0 ) ;
F_8 ( V_2 ) ;
F_7 ( V_2 , V_202 ,
( F_2 ( V_2 , V_202 ) |
V_206 ) ) ;
F_8 ( V_2 ) ;
F_7 ( V_2 , V_202 ,
( F_2 ( V_2 , V_202 ) &
~ V_206 ) ) ;
F_8 ( V_2 ) ;
F_7 ( V_2 , V_207 , 0x00 ) ;
F_8 ( V_2 ) ;
F_7 ( V_2 , V_199 , V_198 ) ;
F_8 ( V_2 ) ;
for ( V_133 = 0 ; V_133 < V_208 ; V_133 ++ ) {
if ( F_2 ( V_2 , V_199 ) &
V_200 )
break;
F_9 ( 1000 , 2000 ) ;
}
if ( V_133 >= V_208 ) {
F_11 ( V_2 , L_10 ) ;
return V_204 ;
}
F_2 ( V_2 , V_209 ) ;
F_2 ( V_2 , V_210 ) ;
F_2 ( V_2 , V_211 ) ;
F_2 ( V_2 , V_212 ) ;
F_2 ( V_2 , V_213 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 , T_1 V_198 )
{
int V_133 ;
F_7 ( V_2 , V_214 , V_215 ) ;
F_7 ( V_2 , V_216 , V_217 ) ;
F_7 ( V_2 , V_199 , V_198 ) ;
F_8 ( V_2 ) ;
for ( V_133 = 0 ; V_133 < V_208 ; V_133 ++ ) {
if ( F_2 ( V_2 , V_199 ) &
V_200 )
break;
F_9 ( 1000 , 2000 ) ;
}
if ( V_133 >= V_208 )
F_11 ( V_2 , L_11 ) ;
}
T_2 F_26 ( struct V_1 * V_2 , T_1 V_198 )
{
V_198 |= ( 0x6 << V_218 ) |
( 0xA << V_219 ) |
( 4 << V_220 ) ;
F_25 ( V_2 , V_198 ) ;
return 0 ;
}
T_2 F_27 ( struct V_1 * V_2 , T_1 V_198 )
{
V_198 |= V_221 |
V_222 |
( V_223 << V_224 ) |
( 0x6 << V_218 ) |
( 0xA << V_219 ) |
( 4 << V_220 ) ;
F_25 ( V_2 , V_198 ) ;
return 0 ;
}
static T_1 F_28 ( union V_225 V_226 ,
union V_225 V_227 )
{
T_1 V_228 , V_229 , V_230 ;
T_1 V_231 = 0 , V_232 = 0 , V_233 = 0 ;
V_230 = F_29 ( V_226 . V_234 ) ;
V_228 = F_29 ( V_227 . V_234 ) ;
V_229 = ( V_228 >> 16 ) | ( V_228 << 16 ) ;
V_228 ^= V_230 ^ ( V_230 >> 16 ) ;
F_30 ( 0 ) ;
V_229 ^= V_230 ^ ( V_230 << 16 ) ;
F_30 ( 1 ) ;
F_30 ( 2 ) ;
F_30 ( 3 ) ;
F_30 ( 4 ) ;
F_30 ( 5 ) ;
F_30 ( 6 ) ;
F_30 ( 7 ) ;
F_30 ( 8 ) ;
F_30 ( 9 ) ;
F_30 ( 10 ) ;
F_30 ( 11 ) ;
F_30 ( 12 ) ;
F_30 ( 13 ) ;
F_30 ( 14 ) ;
F_30 ( 15 ) ;
V_232 ^= V_233 ;
V_232 &= V_235 ;
V_231 ^= V_233 << 16 ;
V_231 &= V_235 << 16 ;
return V_231 ^ V_232 ;
}
T_2 F_31 ( struct V_1 * V_2 ,
union V_225 V_226 ,
union V_225 V_227 ,
T_5 V_236 )
{
T_6 V_237 ;
T_1 V_238 ;
switch ( V_226 . V_239 . V_240 ) {
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
break;
default:
F_11 ( V_2 , L_12 ) ;
return V_247 ;
}
V_238 = V_248 | V_249 |
V_250 | V_251 ;
V_238 |= V_226 . V_239 . V_240 << V_252 ;
V_238 |= ( T_1 ) V_236 << V_253 ;
V_237 = ( T_6 ) V_238 << 32 ;
V_237 |= F_28 ( V_226 , V_227 ) ;
F_32 ( V_2 , V_207 , V_237 ) ;
F_11 ( V_2 , L_13 , V_236 , ( T_1 ) V_237 ) ;
return 0 ;
}
void F_33 ( union V_254 * V_226 ,
union V_254 * V_255 )
{
T_1 V_228 , V_229 , V_230 ;
T_1 V_232 = 0 ;
V_226 -> V_256 [ 0 ] &= V_255 -> V_256 [ 0 ] ;
V_226 -> V_256 [ 1 ] &= V_255 -> V_256 [ 1 ] ;
V_226 -> V_256 [ 2 ] &= V_255 -> V_256 [ 2 ] ;
V_226 -> V_256 [ 3 ] &= V_255 -> V_256 [ 3 ] ;
V_226 -> V_256 [ 4 ] &= V_255 -> V_256 [ 4 ] ;
V_226 -> V_256 [ 5 ] &= V_255 -> V_256 [ 5 ] ;
V_226 -> V_256 [ 6 ] &= V_255 -> V_256 [ 6 ] ;
V_226 -> V_256 [ 7 ] &= V_255 -> V_256 [ 7 ] ;
V_226 -> V_256 [ 8 ] &= V_255 -> V_256 [ 8 ] ;
V_226 -> V_256 [ 9 ] &= V_255 -> V_256 [ 9 ] ;
V_226 -> V_256 [ 10 ] &= V_255 -> V_256 [ 10 ] ;
V_230 = F_29 ( V_226 -> V_256 [ 0 ] ) ;
V_228 = F_29 ( V_226 -> V_256 [ 1 ] ^
V_226 -> V_256 [ 2 ] ^
V_226 -> V_256 [ 3 ] ^
V_226 -> V_256 [ 4 ] ^
V_226 -> V_256 [ 5 ] ^
V_226 -> V_256 [ 6 ] ^
V_226 -> V_256 [ 7 ] ^
V_226 -> V_256 [ 8 ] ^
V_226 -> V_256 [ 9 ] ^
V_226 -> V_256 [ 10 ] ) ;
V_229 = ( V_228 >> 16 ) | ( V_228 << 16 ) ;
V_228 ^= V_230 ^ ( V_230 >> 16 ) ;
F_34 ( 0 ) ;
V_229 ^= V_230 ^ ( V_230 << 16 ) ;
F_34 ( 1 ) ;
F_34 ( 2 ) ;
F_34 ( 3 ) ;
F_34 ( 4 ) ;
F_34 ( 5 ) ;
F_34 ( 6 ) ;
F_34 ( 7 ) ;
F_34 ( 8 ) ;
F_34 ( 9 ) ;
F_34 ( 10 ) ;
F_34 ( 11 ) ;
F_34 ( 12 ) ;
F_34 ( 13 ) ;
F_34 ( 14 ) ;
F_34 ( 15 ) ;
V_226 -> V_239 . V_257 = V_232 & 0x1FFF ;
}
static T_1 F_35 ( union V_254 * V_255 )
{
T_1 V_258 = F_36 ( V_255 -> V_239 . V_259 ) ;
V_258 <<= V_260 ;
V_258 |= F_36 ( V_255 -> V_239 . V_261 ) ;
V_258 = ( ( V_258 & 0x55555555 ) << 1 ) | ( ( V_258 & 0xAAAAAAAA ) >> 1 ) ;
V_258 = ( ( V_258 & 0x33333333 ) << 2 ) | ( ( V_258 & 0xCCCCCCCC ) >> 2 ) ;
V_258 = ( ( V_258 & 0x0F0F0F0F ) << 4 ) | ( ( V_258 & 0xF0F0F0F0 ) >> 4 ) ;
return ( ( V_258 & 0x00FF00FF ) << 8 ) | ( ( V_258 & 0xFF00FF00 ) >> 8 ) ;
}
T_2 F_37 ( struct V_1 * V_2 ,
union V_254 * V_255 )
{
T_1 V_262 = V_263 ;
T_1 V_264 ;
if ( V_255 -> V_239 . V_257 )
F_11 ( V_2 , L_14 ) ;
switch ( V_255 -> V_239 . V_265 & 0x7F ) {
case 0x0 :
V_262 |= V_266 ;
case 0x7F :
break;
default:
F_11 ( V_2 , L_15 ) ;
return V_247 ;
}
switch ( V_255 -> V_239 . V_240 & V_267 ) {
case 0x0 :
V_262 |= V_268 ;
if ( V_255 -> V_239 . V_259 ||
V_255 -> V_239 . V_261 ) {
F_11 ( V_2 , L_16 ) ;
return V_247 ;
}
case V_267 :
break;
default:
F_11 ( V_2 , L_17 ) ;
return V_247 ;
}
switch ( F_36 ( V_255 -> V_239 . V_269 ) & 0xEFFF ) {
case 0x0000 :
V_262 |= V_270 ;
case 0x0FFF :
V_262 |= V_271 ;
break;
case 0xE000 :
V_262 |= V_270 ;
case 0xEFFF :
break;
default:
F_11 ( V_2 , L_18 ) ;
return V_247 ;
}
switch ( V_255 -> V_239 . V_272 & 0xFFFF ) {
case 0x0000 :
V_262 |= V_273 ;
case 0xFFFF :
break;
default:
F_11 ( V_2 , L_19 ) ;
return V_247 ;
}
F_7 ( V_2 , V_274 , V_262 ) ;
V_264 = F_35 ( V_255 ) ;
F_7 ( V_2 , V_275 , ~ V_264 ) ;
F_7 ( V_2 , V_276 , ~ V_264 ) ;
F_38 ( V_2 , V_277 ,
~ V_255 -> V_239 . V_278 [ 0 ] ) ;
F_38 ( V_2 , V_279 ,
~ V_255 -> V_239 . V_280 [ 0 ] ) ;
return 0 ;
}
T_2 F_39 ( struct V_1 * V_2 ,
union V_254 * V_226 ,
T_3 V_281 , T_5 V_236 )
{
T_1 V_282 , V_283 , V_284 , V_238 ;
F_38 ( V_2 , F_40 ( 0 ) ,
V_226 -> V_239 . V_278 [ 0 ] ) ;
F_38 ( V_2 , F_40 ( 1 ) ,
V_226 -> V_239 . V_278 [ 1 ] ) ;
F_38 ( V_2 , F_40 ( 2 ) ,
V_226 -> V_239 . V_278 [ 2 ] ) ;
F_38 ( V_2 , V_285 , V_226 -> V_239 . V_278 [ 0 ] ) ;
F_38 ( V_2 , V_286 , V_226 -> V_239 . V_280 [ 0 ] ) ;
V_282 = F_36 ( V_226 -> V_239 . V_259 ) ;
V_282 <<= V_287 ;
V_282 |= F_36 ( V_226 -> V_239 . V_261 ) ;
F_7 ( V_2 , V_288 , V_282 ) ;
V_283 = F_41 ( V_226 -> V_239 . V_272 ) ;
V_283 <<= V_289 ;
V_283 |= F_36 ( V_226 -> V_239 . V_269 ) ;
F_7 ( V_2 , V_290 , V_283 ) ;
V_284 = V_226 -> V_239 . V_257 ;
V_284 |= V_281 << V_291 ;
F_7 ( V_2 , V_207 , V_284 ) ;
F_8 ( V_2 ) ;
V_238 = V_248 | V_249 |
V_250 | V_251 ;
if ( V_236 == V_223 )
V_238 |= V_292 ;
V_238 |= V_226 -> V_239 . V_240 << V_252 ;
V_238 |= ( T_1 ) V_236 << V_253 ;
V_238 |= ( T_1 ) V_226 -> V_239 . V_265 << V_293 ;
F_7 ( V_2 , V_202 , V_238 ) ;
return 0 ;
}
T_2 F_42 ( struct V_1 * V_2 ,
union V_254 * V_226 ,
T_3 V_281 )
{
T_1 V_284 ;
T_1 V_238 = 0 ;
T_1 V_294 ;
T_2 V_295 = 0 ;
V_284 = V_226 -> V_239 . V_257 ;
V_284 |= V_281 << V_291 ;
F_7 ( V_2 , V_207 , V_284 ) ;
F_8 ( V_2 ) ;
F_7 ( V_2 , V_202 , V_296 ) ;
for ( V_294 = 10 ; V_294 ; V_294 -- ) {
F_19 ( 10 ) ;
V_238 = F_2 ( V_2 , V_202 ) ;
if ( ! ( V_238 & V_203 ) )
break;
}
if ( ! V_294 )
V_295 = V_204 ;
if ( V_238 & V_297 ) {
F_7 ( V_2 , V_207 , V_284 ) ;
F_8 ( V_2 ) ;
F_7 ( V_2 , V_202 ,
V_298 ) ;
}
return V_295 ;
}
static T_2 F_43 ( struct V_1 * V_2 , T_1 V_299 , T_5 * V_300 )
{
T_1 V_301 ;
F_7 ( V_2 , V_49 , V_302 |
( V_299 << 8 ) ) ;
F_8 ( V_2 ) ;
F_19 ( 10 ) ;
V_301 = F_2 ( V_2 , V_49 ) ;
* V_300 = ( T_5 ) V_301 ;
return 0 ;
}
static T_2 F_44 ( struct V_1 * V_2 , T_1 V_299 , T_5 V_300 )
{
T_1 V_301 ;
V_301 = ( V_299 << 8 ) | V_300 ;
F_7 ( V_2 , V_49 , V_301 ) ;
F_8 ( V_2 ) ;
F_19 ( 10 ) ;
return 0 ;
}
static T_2 F_45 ( struct V_1 * V_2 )
{
T_2 V_35 = 0 ;
V_35 = F_46 ( V_2 ) ;
if ( V_35 != 0 )
goto V_91;
V_35 = F_47 ( V_2 ) ;
if ( V_35 != 0 )
goto V_91;
V_2 -> V_14 . V_141 = true ;
V_2 -> V_14 . V_303 = V_304 ;
if ( V_35 == 0 )
V_35 = F_48 ( V_2 ) ;
V_91:
return V_35 ;
}
static T_2 F_49 ( struct V_1 * V_2 )
{
T_2 V_82 = V_305 ;
V_82 = F_50 ( V_2 ) ;
if ( V_82 != 0 ) {
if ( V_2 -> V_14 . V_15 . V_16 ( V_2 ) == V_70 )
goto V_91;
else
V_82 = F_51 ( V_2 ) ;
}
if ( V_2 -> V_25 . type == V_306 ) {
V_2 -> V_25 . type = V_307 ;
V_82 = 0 ;
}
if ( V_2 -> V_25 . type == V_308 )
V_82 = V_170 ;
V_91:
return V_82 ;
}
static T_1 F_52 ( struct V_1 * V_2 )
{
T_1 V_309 = V_310 ;
T_1 V_83 = F_2 ( V_2 , V_52 ) ;
T_1 V_156 = F_2 ( V_2 , V_157 ) ;
T_1 V_158 = V_156 & V_159 ;
T_1 V_311 = V_83 & V_312 ;
T_1 V_153 = V_83 & V_161 ;
T_3 V_313 = 0 ;
T_5 V_314 = 0 ;
T_5 V_315 = 0 ;
V_2 -> V_25 . V_15 . V_69 ( V_2 ) ;
switch ( V_2 -> V_25 . type ) {
case V_74 :
case V_110 :
V_2 -> V_25 . V_15 . V_316 ( V_2 , V_317 , V_318 ,
& V_313 ) ;
if ( V_313 & V_319 )
V_309 |= V_320 ;
if ( V_313 & V_321 )
V_309 |= V_322 ;
if ( V_313 & V_323 )
V_309 |= V_324 ;
goto V_91;
default:
break;
}
switch ( V_83 & V_93 ) {
case V_97 :
case V_94 :
if ( V_153 == V_325 ) {
V_309 = V_326 |
V_327 ;
goto V_91;
} else
goto V_328;
break;
case V_95 :
if ( V_311 == V_329 )
V_309 = V_330 ;
else if ( V_311 == V_331 )
V_309 = V_332 ;
else if ( V_311 == V_333 )
V_309 = V_334 ;
goto V_91;
break;
case V_54 :
if ( V_158 == V_335 ) {
V_309 = V_336 ;
goto V_91;
} else if ( V_158 == V_163 )
goto V_328;
break;
case V_98 :
case V_99 :
if ( V_83 & V_103 )
V_309 |= V_326 ;
if ( V_83 & V_102 )
V_309 |= V_332 ;
if ( V_83 & V_101 )
V_309 |= V_336 ;
goto V_91;
break;
default:
goto V_91;
break;
}
V_328:
V_2 -> V_25 . V_15 . V_337 ( V_2 ) ;
if ( V_2 -> V_25 . V_40 == V_338 )
goto V_91;
switch ( V_2 -> V_25 . type ) {
case V_339 :
case V_340 :
V_309 = V_341 ;
break;
case V_342 :
case V_343 :
V_309 = V_344 ;
break;
case V_345 :
case V_346 :
case V_347 :
case V_348 :
V_2 -> V_25 . V_15 . V_349 ( V_2 ,
V_350 , & V_315 ) ;
V_2 -> V_25 . V_15 . V_349 ( V_2 ,
V_351 , & V_314 ) ;
if ( V_314 & V_352 )
V_309 = V_353 ;
else if ( V_314 & V_354 )
V_309 = V_355 ;
else if ( V_315 & V_356 )
V_309 = V_322 ;
break;
default:
break;
}
V_91:
return V_309 ;
}
static T_2 F_53 ( struct V_1 * V_2 , T_1 V_357 )
{
V_2 -> V_14 . V_15 . V_358 ( V_2 ) ;
F_7 ( V_2 , V_359 , V_357 ) ;
V_2 -> V_14 . V_15 . V_360 ( V_2 ) ;
return 0 ;
}
static T_2 F_48 ( struct V_1 * V_2 )
{
T_2 V_82 = V_361 ;
T_3 V_362 , V_363 ;
T_3 V_364 = 0 ;
if ( V_2 -> V_25 . V_109 != V_17 ) {
V_82 = 0 ;
goto V_365;
}
V_2 -> V_47 . V_15 . V_48 ( V_2 , V_366 , & V_362 ) ;
if ( ( V_362 == 0 ) || ( V_362 == 0xFFFF ) )
goto V_365;
V_2 -> V_47 . V_15 . V_48 ( V_2 , ( V_362 +
V_367 ) ,
& V_363 ) ;
if ( ( V_363 == 0 ) || ( V_363 == 0xFFFF ) )
goto V_365;
V_2 -> V_47 . V_15 . V_48 ( V_2 , ( V_363 +
V_368 ) ,
& V_364 ) ;
if ( V_364 > 0x5 )
V_82 = 0 ;
V_365:
return V_82 ;
}
bool F_4 ( struct V_1 * V_2 )
{
bool V_369 = false ;
T_3 V_362 , V_370 , V_371 ;
T_2 V_82 ;
V_82 = V_2 -> V_47 . V_15 . V_48 ( V_2 , V_366 , & V_362 ) ;
if ( ( V_82 != 0 ) ||
( V_362 == 0 ) || ( V_362 == 0xFFFF ) )
goto V_91;
V_82 = V_2 -> V_47 . V_15 . V_48 ( V_2 , ( V_362 +
V_372 ) ,
& V_370 ) ;
if ( ( V_82 != 0 ) ||
( V_370 == 0 ) || ( V_370 == 0xFFFF ) )
goto V_91;
V_82 = V_2 -> V_47 . V_15 . V_48 ( V_2 , ( V_370 +
V_373 ) ,
& V_371 ) ;
if ( ( V_82 == 0 ) &&
( V_371 & V_374 ) )
V_369 = true ;
V_91:
return V_369 ;
}
static T_2 F_54 ( struct V_1 * V_2 , T_3 V_375 ,
T_3 V_376 , T_3 * V_377 )
{
struct V_378 * V_47 = & V_2 -> V_47 ;
T_2 V_35 = V_247 ;
if ( ( V_47 -> type == V_379 ) &&
( V_375 + ( V_376 - 1 ) <= V_380 ) )
V_35 = F_55 ( V_2 , V_375 , V_376 ,
V_377 ) ;
else
V_35 = F_56 ( V_2 , V_375 ,
V_376 ,
V_377 ) ;
return V_35 ;
}
static T_2 F_57 ( struct V_1 * V_2 ,
T_3 V_375 , T_3 * V_377 )
{
struct V_378 * V_47 = & V_2 -> V_47 ;
T_2 V_35 = V_247 ;
if ( ( V_47 -> type == V_379 ) &&
( V_375 <= V_380 ) )
V_35 = F_58 ( V_2 , V_375 , V_377 ) ;
else
V_35 = F_59 ( V_2 , V_375 , V_377 ) ;
return V_35 ;
}
T_2 F_10 ( struct V_1 * V_2 )
{
T_2 V_35 ;
T_1 V_381 = 0 ;
T_1 V_133 , V_131 , V_382 ;
V_382 = F_2 ( V_2 , V_157 ) ;
if ( V_382 & V_183 ) {
V_382 &= ~ V_183 ;
F_7 ( V_2 , V_157 , V_382 ) ;
F_8 ( V_2 ) ;
}
V_131 = V_2 -> V_14 . V_55 ;
V_131 |= V_383 ;
F_7 ( V_2 , V_52 , V_131 ^ V_97 ) ;
for ( V_133 = 0 ; V_133 < 10 ; V_133 ++ ) {
F_9 ( 4000 , 8000 ) ;
V_381 = F_2 ( V_2 , V_384 ) ;
if ( V_381 & V_385 )
break;
}
if ( ! ( V_381 & V_385 ) ) {
F_11 ( V_2 , L_20 ) ;
V_35 = V_180 ;
goto V_386;
}
V_35 = 0 ;
V_386:
F_7 ( V_2 , V_52 , V_131 ) ;
F_8 ( V_2 ) ;
return V_35 ;
}
