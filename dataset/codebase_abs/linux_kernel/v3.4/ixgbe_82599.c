static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
if ( V_4 -> V_5 . V_6 ( V_2 ) == V_7 ) {
V_4 -> V_5 . V_8 =
& V_9 ;
V_4 -> V_5 . V_10 =
& V_11 ;
V_4 -> V_5 . V_12 = & V_13 ;
} else {
V_4 -> V_5 . V_8 = NULL ;
V_4 -> V_5 . V_10 = NULL ;
V_4 -> V_5 . V_12 = NULL ;
}
if ( V_2 -> V_14 . V_15 ) {
V_4 -> V_5 . V_16 = & V_17 ;
} else {
if ( ( V_4 -> V_5 . V_6 ( V_2 ) ==
V_18 ) &&
( V_2 -> V_14 . V_19 == V_20 ||
V_2 -> V_14 . V_19 == V_21 ) &&
! F_2 ( V_2 ) )
V_4 -> V_5 . V_16 = & V_22 ;
else
V_4 -> V_5 . V_16 = & V_23 ;
}
}
static T_1 F_3 ( struct V_1 * V_2 )
{
T_1 V_24 = 0 ;
T_2 V_25 = 0 ;
T_2 V_26 = 0 ;
T_3 V_27 , V_28 , V_29 ;
if ( V_2 -> V_14 . V_30 != V_31 ) {
F_1 ( V_2 ) ;
V_2 -> V_14 . V_5 . V_32 = NULL ;
V_24 = F_4 ( V_2 , & V_27 ,
& V_28 ) ;
if ( V_24 != 0 )
goto V_33;
V_24 = V_2 -> V_4 . V_5 . V_34 ( V_2 ,
V_35 ) ;
if ( V_24 != 0 ) {
V_24 = V_36 ;
goto V_33;
}
V_2 -> V_37 . V_5 . V_38 ( V_2 , ++ V_28 , & V_29 ) ;
while ( V_29 != 0xffff ) {
F_5 ( V_2 , V_39 , V_29 ) ;
F_6 ( V_2 ) ;
V_2 -> V_37 . V_5 . V_38 ( V_2 , ++ V_28 , & V_29 ) ;
}
V_2 -> V_4 . V_5 . V_40 ( V_2 , V_35 ) ;
F_7 ( V_2 -> V_37 . V_41 * 1000 ,
V_2 -> V_37 . V_41 * 2000 ) ;
F_5 ( V_2 , V_42 , ( ( F_8 ( V_2 ,
V_42 ) & ~ V_43 ) |
V_44 ) ) ;
for ( V_26 = 0 ; V_26 < 10 ; V_26 ++ ) {
F_7 ( 4000 , 8000 ) ;
V_25 = F_8 ( V_2 , V_45 ) ;
if ( V_25 & V_46 )
break;
}
if ( ! ( V_25 & V_46 ) ) {
F_9 ( V_2 , L_1 ) ;
V_24 = V_47 ;
goto V_33;
}
F_5 ( V_2 , V_42 , ( F_8 ( V_2 ,
V_42 ) | V_48 |
V_44 ) ) ;
}
V_33:
return V_24 ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_1 ( V_2 ) ;
V_4 -> V_49 = V_50 ;
V_4 -> V_51 = V_52 ;
V_4 -> V_53 = V_54 ;
V_4 -> V_55 = V_56 ;
V_4 -> V_57 = V_58 ;
V_4 -> V_59 = F_11 ( V_2 ) ;
return 0 ;
}
static T_1 F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_60 * V_14 = & V_2 -> V_14 ;
T_1 V_24 = 0 ;
V_24 = V_14 -> V_5 . V_61 ( V_2 ) ;
F_1 ( V_2 ) ;
if ( V_4 -> V_5 . V_6 ( V_2 ) == V_62 ) {
V_4 -> V_5 . V_16 = & V_63 ;
V_4 -> V_5 . V_64 =
& V_65 ;
}
switch ( V_2 -> V_14 . type ) {
case V_66 :
V_14 -> V_5 . V_67 = & V_68 ;
V_14 -> V_5 . V_16 = & V_69 ;
V_14 -> V_5 . V_70 =
& V_71 ;
break;
default:
break;
}
return V_24 ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
T_4 * V_72 ,
bool * V_73 )
{
T_1 V_74 = 0 ;
T_2 V_75 = 0 ;
if ( V_2 -> V_14 . V_30 == V_76 ||
V_2 -> V_14 . V_30 == V_77 ) {
* V_72 = V_78 ;
* V_73 = true ;
goto V_79;
}
if ( V_2 -> V_4 . V_80 )
V_75 = V_2 -> V_4 . V_81 ;
else
V_75 = F_8 ( V_2 , V_42 ) ;
switch ( V_75 & V_43 ) {
case V_82 :
* V_72 = V_78 ;
* V_73 = false ;
break;
case V_83 :
* V_72 = V_84 ;
* V_73 = false ;
break;
case V_85 :
* V_72 = V_78 ;
* V_73 = true ;
break;
case V_48 :
* V_72 = V_84 ;
* V_73 = false ;
break;
case V_86 :
case V_87 :
* V_72 = V_88 ;
if ( V_75 & V_89 )
* V_72 |= V_84 ;
if ( V_75 & V_90 )
* V_72 |= V_84 ;
if ( V_75 & V_91 )
* V_72 |= V_78 ;
* V_73 = true ;
break;
case V_92 :
* V_72 = V_93 ;
if ( V_75 & V_89 )
* V_72 |= V_84 ;
if ( V_75 & V_90 )
* V_72 |= V_84 ;
if ( V_75 & V_91 )
* V_72 |= V_78 ;
* V_73 = true ;
break;
case V_94 :
* V_72 = V_78 | V_93 ;
* V_73 = false ;
break;
default:
V_74 = V_95 ;
goto V_79;
break;
}
if ( V_2 -> V_14 . V_15 ) {
* V_72 |= V_84 |
V_78 ;
* V_73 = true ;
}
V_79:
return V_74 ;
}
static enum V_96 F_14 ( struct V_1 * V_2 )
{
enum V_96 V_97 ;
switch ( V_2 -> V_14 . type ) {
case V_98 :
case V_66 :
V_97 = V_62 ;
goto V_79;
default:
break;
}
switch ( V_2 -> V_99 ) {
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
V_97 = V_18 ;
break;
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
V_97 = V_7 ;
break;
case V_112 :
V_97 = V_113 ;
break;
case V_114 :
V_97 = V_62 ;
break;
case V_115 :
V_97 = V_116 ;
break;
default:
V_97 = V_117 ;
break;
}
V_79:
return V_97 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
bool V_118 )
{
T_2 V_119 ;
T_2 V_120 ;
T_2 V_26 ;
T_1 V_74 = 0 ;
V_119 = F_8 ( V_2 , V_42 ) ;
V_119 |= V_44 ;
F_5 ( V_2 , V_42 , V_119 ) ;
if ( V_118 ) {
if ( ( V_119 & V_43 ) ==
V_86 ||
( V_119 & V_43 ) ==
V_87 ||
( V_119 & V_43 ) ==
V_92 ) {
V_120 = 0 ;
for ( V_26 = 0 ; V_26 < V_121 ; V_26 ++ ) {
V_120 = F_8 ( V_2 , V_122 ) ;
if ( V_120 & V_123 )
break;
F_16 ( 100 ) ;
}
if ( ! ( V_120 & V_123 ) ) {
V_74 = V_124 ;
F_9 ( V_2 , L_2 ) ;
}
}
}
F_16 ( 50 ) ;
return V_74 ;
}
static void V_9 ( struct V_1 * V_2 )
{
T_2 V_125 = F_8 ( V_2 , V_126 ) ;
V_125 |= V_127 ;
F_5 ( V_2 , V_126 , V_125 ) ;
F_6 ( V_2 ) ;
F_17 ( 100 ) ;
}
static void V_11 ( struct V_1 * V_2 )
{
T_2 V_125 = F_8 ( V_2 , V_126 ) ;
V_125 &= ~ V_127 ;
F_5 ( V_2 , V_126 , V_125 ) ;
F_6 ( V_2 ) ;
F_16 ( 100 ) ;
}
static void V_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 . V_128 ) {
V_9 ( V_2 ) ;
V_11 ( V_2 ) ;
V_2 -> V_4 . V_128 = false ;
}
}
static T_1 V_17 ( struct V_1 * V_2 ,
T_4 V_72 ,
bool V_129 ,
bool V_118 )
{
T_1 V_74 = 0 ;
T_4 V_130 = V_88 ;
T_4 V_131 = V_88 ;
T_2 V_132 = 0 ;
T_2 V_125 = F_8 ( V_2 , V_126 ) ;
T_2 V_26 = 0 ;
bool V_133 = false ;
bool V_73 ;
V_74 = V_2 -> V_4 . V_5 . V_64 ( V_2 , & V_130 ,
& V_73 ) ;
if ( V_74 != 0 )
return V_74 ;
V_72 &= V_130 ;
if ( V_72 & V_84 ) {
V_132 ++ ;
V_131 = V_84 ;
V_74 = V_2 -> V_4 . V_5 . V_67 ( V_2 , & V_130 , & V_133 ,
false ) ;
if ( V_74 != 0 )
return V_74 ;
if ( ( V_130 == V_84 ) && V_133 )
goto V_79;
V_125 |= ( V_134 | V_135 ) ;
F_5 ( V_2 , V_126 , V_125 ) ;
F_6 ( V_2 ) ;
F_16 ( 40 ) ;
V_74 = V_23 ( V_2 ,
V_84 ,
V_129 ,
V_118 ) ;
if ( V_74 != 0 )
return V_74 ;
V_2 -> V_4 . V_5 . V_12 ( V_2 ) ;
for ( V_26 = 0 ; V_26 < 5 ; V_26 ++ ) {
F_16 ( 100 ) ;
V_74 = V_2 -> V_4 . V_5 . V_67 ( V_2 , & V_130 ,
& V_133 , false ) ;
if ( V_74 != 0 )
return V_74 ;
if ( V_133 )
goto V_79;
}
}
if ( V_72 & V_78 ) {
V_132 ++ ;
if ( V_131 == V_88 )
V_131 = V_78 ;
V_74 = V_2 -> V_4 . V_5 . V_67 ( V_2 , & V_130 , & V_133 ,
false ) ;
if ( V_74 != 0 )
return V_74 ;
if ( ( V_130 == V_78 ) && V_133 )
goto V_79;
V_125 &= ~ V_135 ;
V_125 |= V_134 ;
F_5 ( V_2 , V_126 , V_125 ) ;
F_6 ( V_2 ) ;
F_16 ( 40 ) ;
V_74 = V_23 ( V_2 ,
V_78 ,
V_129 ,
V_118 ) ;
if ( V_74 != 0 )
return V_74 ;
V_2 -> V_4 . V_5 . V_12 ( V_2 ) ;
F_16 ( 100 ) ;
V_74 = V_2 -> V_4 . V_5 . V_67 ( V_2 , & V_130 , & V_133 ,
false ) ;
if ( V_74 != 0 )
return V_74 ;
if ( V_133 )
goto V_79;
}
if ( V_132 > 1 )
V_74 = V_17 ( V_2 ,
V_131 ,
V_129 ,
V_118 ) ;
V_79:
V_2 -> V_14 . V_136 = 0 ;
if ( V_72 & V_84 )
V_2 -> V_14 . V_136 |= V_84 ;
if ( V_72 & V_78 )
V_2 -> V_14 . V_136 |= V_78 ;
return V_74 ;
}
static T_1 V_22 ( struct V_1 * V_2 ,
T_4 V_72 , bool V_129 ,
bool V_118 )
{
T_1 V_74 = 0 ;
T_4 V_130 = V_88 ;
T_1 V_26 , V_137 ;
bool V_133 = false ;
T_2 V_119 = F_8 ( V_2 , V_42 ) ;
V_2 -> V_14 . V_136 = 0 ;
if ( V_72 & V_84 )
V_2 -> V_14 . V_136 |= V_84 ;
if ( V_72 & V_78 )
V_2 -> V_14 . V_136 |= V_78 ;
if ( V_72 & V_93 )
V_2 -> V_14 . V_136 |= V_93 ;
V_2 -> V_14 . V_138 = false ;
for ( V_137 = 0 ; V_137 < V_139 ; V_137 ++ ) {
V_74 = V_23 ( V_2 , V_72 , V_129 ,
V_118 ) ;
if ( V_74 != 0 )
goto V_79;
for ( V_26 = 0 ; V_26 < 5 ; V_26 ++ ) {
F_18 ( 100 ) ;
V_74 = V_2 -> V_4 . V_5 . V_67 ( V_2 , & V_130 ,
& V_133 , false ) ;
if ( V_74 != 0 )
goto V_79;
if ( V_133 )
goto V_79;
}
}
if ( ( ( V_119 & V_89 ) == 0 ) ||
( ( V_119 & V_140 ) == 0 ) )
goto V_79;
V_2 -> V_14 . V_138 = true ;
V_74 = V_23 ( V_2 , V_72 , V_129 ,
V_118 ) ;
if ( V_74 != 0 )
goto V_79;
for ( V_26 = 0 ; V_26 < 6 ; V_26 ++ ) {
F_18 ( 100 ) ;
V_74 = V_2 -> V_4 . V_5 . V_67 ( V_2 , & V_130 ,
& V_133 , false ) ;
if ( V_74 != 0 )
goto V_79;
if ( V_133 )
goto V_79;
}
V_2 -> V_14 . V_138 = false ;
V_74 = V_23 ( V_2 , V_72 , V_129 ,
V_118 ) ;
V_79:
if ( V_133 && ( V_130 == V_78 ) )
F_9 ( V_2 , L_3
L_4 ) ;
return V_74 ;
}
static T_1 V_23 ( struct V_1 * V_2 ,
T_4 V_72 , bool V_129 ,
bool V_118 )
{
T_1 V_74 = 0 ;
T_2 V_75 = F_8 ( V_2 , V_42 ) ;
T_2 V_141 = F_8 ( V_2 , V_142 ) ;
T_2 V_143 = V_75 ;
T_2 V_81 = 0 ;
T_2 V_144 = V_75 & V_43 ;
T_2 V_145 = V_75 & V_146 ;
T_2 V_147 = V_141 & V_148 ;
T_2 V_120 ;
T_2 V_26 ;
T_4 V_149 = V_88 ;
V_74 = V_2 -> V_4 . V_5 . V_64 ( V_2 , & V_149 ,
& V_129 ) ;
if ( V_74 != 0 )
goto V_79;
V_72 &= V_149 ;
if ( V_72 == V_88 ) {
V_74 = V_95 ;
goto V_79;
}
if ( V_2 -> V_4 . V_80 )
V_81 = V_2 -> V_4 . V_81 ;
else
V_81 = V_75 ;
if ( V_144 == V_86 ||
V_144 == V_87 ||
V_144 == V_92 ) {
V_75 &= ~ ( V_140 | V_89 ) ;
if ( V_72 & V_84 )
if ( V_81 & V_90 )
V_75 |= V_90 ;
if ( ( V_81 & V_89 ) &&
( V_2 -> V_14 . V_138 == false ) )
V_75 |= V_89 ;
if ( V_72 & V_78 )
V_75 |= V_91 ;
} else if ( ( V_145 == V_150 ) &&
( V_144 == V_82 ||
V_144 == V_85 ) ) {
if ( ( V_72 == V_84 ) &&
( V_147 == V_151 ) ) {
V_75 &= ~ V_43 ;
V_75 |= V_48 ;
}
} else if ( ( V_147 == V_151 ) &&
( V_144 == V_48 ) ) {
if ( ( V_72 == V_78 ) &&
( V_145 == V_150 ) ) {
V_75 &= ~ V_43 ;
if ( V_129 )
V_75 |= V_85 ;
else
V_75 |= V_82 ;
}
}
if ( V_75 != V_143 ) {
V_75 |= V_44 ;
F_5 ( V_2 , V_42 , V_75 ) ;
if ( V_118 ) {
if ( V_144 == V_86 ||
V_144 == V_87 ||
V_144 == V_92 ) {
V_120 = 0 ;
for ( V_26 = 0 ; V_26 < V_121 ; V_26 ++ ) {
V_120 =
F_8 ( V_2 , V_122 ) ;
if ( V_120 & V_123 )
break;
F_16 ( 100 ) ;
}
if ( ! ( V_120 & V_123 ) ) {
V_74 =
V_124 ;
F_9 ( V_2 , L_5
L_6 ) ;
}
}
}
F_16 ( 50 ) ;
}
V_79:
return V_74 ;
}
static T_1 V_63 ( struct V_1 * V_2 ,
T_4 V_72 ,
bool V_129 ,
bool V_118 )
{
T_1 V_74 ;
V_74 = V_2 -> V_14 . V_5 . V_152 ( V_2 , V_72 , V_129 ,
V_118 ) ;
F_15 ( V_2 , V_118 ) ;
return V_74 ;
}
static T_1 F_19 ( struct V_1 * V_2 )
{
T_4 V_130 ;
T_1 V_74 ;
T_2 V_153 , V_26 , V_75 , V_141 ;
bool V_133 = false ;
V_74 = V_2 -> V_4 . V_5 . V_154 ( V_2 ) ;
if ( V_74 != 0 )
goto V_155;
F_20 ( V_2 ) ;
V_74 = V_2 -> V_14 . V_5 . V_156 ( V_2 ) ;
if ( V_74 == V_157 )
goto V_155;
if ( V_2 -> V_14 . V_158 ) {
V_74 = V_2 -> V_4 . V_5 . V_159 ( V_2 ) ;
V_2 -> V_14 . V_158 = false ;
}
if ( V_74 == V_157 )
goto V_155;
if ( V_2 -> V_14 . V_160 == false && V_2 -> V_14 . V_5 . V_32 != NULL )
V_2 -> V_14 . V_5 . V_32 ( V_2 ) ;
V_161:
V_153 = V_162 ;
if ( ! V_2 -> V_163 ) {
V_2 -> V_4 . V_5 . V_67 ( V_2 , & V_130 , & V_133 , false ) ;
if ( V_133 )
V_153 = V_164 ;
}
V_153 |= F_8 ( V_2 , V_165 ) ;
F_5 ( V_2 , V_165 , V_153 ) ;
F_6 ( V_2 ) ;
for ( V_26 = 0 ; V_26 < 10 ; V_26 ++ ) {
F_17 ( 1 ) ;
V_153 = F_8 ( V_2 , V_165 ) ;
if ( ! ( V_153 & V_166 ) )
break;
}
if ( V_153 & V_166 ) {
V_74 = V_167 ;
F_9 ( V_2 , L_7 ) ;
}
F_16 ( 50 ) ;
if ( V_2 -> V_4 . V_168 & V_169 ) {
V_2 -> V_4 . V_168 &= ~ V_169 ;
goto V_161;
}
V_75 = F_8 ( V_2 , V_42 ) ;
V_141 = F_8 ( V_2 , V_142 ) ;
if ( V_2 -> V_4 . V_80 == false ) {
V_2 -> V_4 . V_81 = V_75 ;
V_2 -> V_4 . V_170 = V_141 ;
V_2 -> V_4 . V_80 = true ;
} else {
if ( V_75 != V_2 -> V_4 . V_81 )
F_5 ( V_2 , V_42 , ( V_2 -> V_4 . V_81 |
V_44 ) ) ;
if ( ( V_141 & V_171 ) !=
( V_2 -> V_4 . V_170 & V_171 ) ) {
V_141 &= ~ V_171 ;
V_141 |= ( V_2 -> V_4 . V_170 &
V_171 ) ;
F_5 ( V_2 , V_142 , V_141 ) ;
}
}
V_2 -> V_4 . V_5 . V_172 ( V_2 , V_2 -> V_4 . V_173 ) ;
V_2 -> V_4 . V_53 = 128 ;
V_2 -> V_4 . V_5 . V_174 ( V_2 ) ;
V_2 -> V_4 . V_5 . V_175 ( V_2 , V_2 -> V_4 . V_176 ) ;
if ( F_21 ( V_2 -> V_4 . V_176 ) == 0 ) {
V_2 -> V_4 . V_5 . V_177 ( V_2 , V_2 -> V_4 . V_53 - 1 ,
V_2 -> V_4 . V_176 , 0 , V_178 ) ;
V_2 -> V_4 . V_53 -- ;
}
V_2 -> V_4 . V_5 . V_179 ( V_2 , & V_2 -> V_4 . V_180 ,
& V_2 -> V_4 . V_181 ) ;
V_155:
return V_74 ;
}
T_1 F_22 ( struct V_1 * V_2 )
{
int V_26 ;
T_2 V_182 = F_8 ( V_2 , V_183 ) ;
V_182 &= ~ V_184 ;
for ( V_26 = 0 ; V_26 < V_185 ; V_26 ++ ) {
if ( ! ( F_8 ( V_2 , V_186 ) &
V_187 ) )
break;
F_17 ( 10 ) ;
}
if ( V_26 >= V_185 ) {
F_9 ( V_2 , L_8
L_9 ) ;
return V_188 ;
}
F_5 ( V_2 , V_189 , 0 ) ;
F_6 ( V_2 ) ;
F_5 ( V_2 , V_186 ,
( F_8 ( V_2 , V_186 ) |
V_190 ) ) ;
F_6 ( V_2 ) ;
F_5 ( V_2 , V_186 ,
( F_8 ( V_2 , V_186 ) &
~ V_190 ) ) ;
F_6 ( V_2 ) ;
F_5 ( V_2 , V_191 , 0x00 ) ;
F_6 ( V_2 ) ;
F_5 ( V_2 , V_183 , V_182 ) ;
F_6 ( V_2 ) ;
for ( V_26 = 0 ; V_26 < V_192 ; V_26 ++ ) {
if ( F_8 ( V_2 , V_183 ) &
V_184 )
break;
F_17 ( 10 ) ;
}
if ( V_26 >= V_192 ) {
F_9 ( V_2 , L_10 ) ;
return V_188 ;
}
F_8 ( V_2 , V_193 ) ;
F_8 ( V_2 , V_194 ) ;
F_8 ( V_2 , V_195 ) ;
F_8 ( V_2 , V_196 ) ;
F_8 ( V_2 , V_197 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 , T_2 V_182 )
{
int V_26 ;
F_5 ( V_2 , V_198 , V_199 ) ;
F_5 ( V_2 , V_200 , V_201 ) ;
F_5 ( V_2 , V_183 , V_182 ) ;
F_6 ( V_2 ) ;
for ( V_26 = 0 ; V_26 < V_192 ; V_26 ++ ) {
if ( F_8 ( V_2 , V_183 ) &
V_184 )
break;
F_7 ( 1000 , 2000 ) ;
}
if ( V_26 >= V_192 )
F_9 ( V_2 , L_11 ) ;
}
T_1 F_24 ( struct V_1 * V_2 , T_2 V_182 )
{
V_182 |= ( 0x6 << V_202 ) |
( 0xA << V_203 ) |
( 4 << V_204 ) ;
F_23 ( V_2 , V_182 ) ;
return 0 ;
}
T_1 F_25 ( struct V_1 * V_2 , T_2 V_182 )
{
V_182 |= V_205 |
V_206 |
( V_207 << V_208 ) |
( 0x6 << V_202 ) |
( 0xA << V_203 ) |
( 4 << V_204 ) ;
F_23 ( V_2 , V_182 ) ;
return 0 ;
}
static T_2 F_26 ( union V_209 V_210 ,
union V_209 V_211 )
{
T_2 V_212 , V_213 , V_214 ;
T_2 V_215 = 0 , V_216 = 0 , V_217 = 0 ;
V_214 = F_27 ( V_210 . V_218 ) ;
V_212 = F_27 ( V_211 . V_218 ) ;
V_213 = ( V_212 >> 16 ) | ( V_212 << 16 ) ;
V_212 ^= V_214 ^ ( V_214 >> 16 ) ;
F_28 ( 0 ) ;
V_213 ^= V_214 ^ ( V_214 << 16 ) ;
F_28 ( 1 ) ;
F_28 ( 2 ) ;
F_28 ( 3 ) ;
F_28 ( 4 ) ;
F_28 ( 5 ) ;
F_28 ( 6 ) ;
F_28 ( 7 ) ;
F_28 ( 8 ) ;
F_28 ( 9 ) ;
F_28 ( 10 ) ;
F_28 ( 11 ) ;
F_28 ( 12 ) ;
F_28 ( 13 ) ;
F_28 ( 14 ) ;
F_28 ( 15 ) ;
V_216 ^= V_217 ;
V_216 &= V_219 ;
V_215 ^= V_217 << 16 ;
V_215 &= V_219 << 16 ;
return V_215 ^ V_216 ;
}
T_1 F_29 ( struct V_1 * V_2 ,
union V_209 V_210 ,
union V_209 V_211 ,
T_5 V_220 )
{
T_6 V_221 ;
T_2 V_222 ;
switch ( V_210 . V_223 . V_224 ) {
case V_225 :
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case V_230 :
break;
default:
F_9 ( V_2 , L_12 ) ;
return V_231 ;
}
V_222 = V_232 | V_233 |
V_234 | V_235 ;
V_222 |= V_210 . V_223 . V_224 << V_236 ;
V_222 |= ( T_2 ) V_220 << V_237 ;
V_221 = ( T_6 ) V_222 << 32 ;
V_221 |= F_26 ( V_210 , V_211 ) ;
F_30 ( V_2 , V_191 , V_221 ) ;
F_9 ( V_2 , L_13 , V_220 , ( T_2 ) V_221 ) ;
return 0 ;
}
void F_31 ( union V_238 * V_210 ,
union V_238 * V_239 )
{
T_2 V_212 , V_213 , V_214 ;
T_2 V_216 = 0 ;
V_210 -> V_240 [ 0 ] &= V_239 -> V_240 [ 0 ] ;
V_210 -> V_240 [ 1 ] &= V_239 -> V_240 [ 1 ] ;
V_210 -> V_240 [ 2 ] &= V_239 -> V_240 [ 2 ] ;
V_210 -> V_240 [ 3 ] &= V_239 -> V_240 [ 3 ] ;
V_210 -> V_240 [ 4 ] &= V_239 -> V_240 [ 4 ] ;
V_210 -> V_240 [ 5 ] &= V_239 -> V_240 [ 5 ] ;
V_210 -> V_240 [ 6 ] &= V_239 -> V_240 [ 6 ] ;
V_210 -> V_240 [ 7 ] &= V_239 -> V_240 [ 7 ] ;
V_210 -> V_240 [ 8 ] &= V_239 -> V_240 [ 8 ] ;
V_210 -> V_240 [ 9 ] &= V_239 -> V_240 [ 9 ] ;
V_210 -> V_240 [ 10 ] &= V_239 -> V_240 [ 10 ] ;
V_214 = F_27 ( V_210 -> V_240 [ 0 ] ) ;
V_212 = F_27 ( V_210 -> V_240 [ 1 ] ^
V_210 -> V_240 [ 2 ] ^
V_210 -> V_240 [ 3 ] ^
V_210 -> V_240 [ 4 ] ^
V_210 -> V_240 [ 5 ] ^
V_210 -> V_240 [ 6 ] ^
V_210 -> V_240 [ 7 ] ^
V_210 -> V_240 [ 8 ] ^
V_210 -> V_240 [ 9 ] ^
V_210 -> V_240 [ 10 ] ) ;
V_213 = ( V_212 >> 16 ) | ( V_212 << 16 ) ;
V_212 ^= V_214 ^ ( V_214 >> 16 ) ;
F_32 ( 0 ) ;
V_213 ^= V_214 ^ ( V_214 << 16 ) ;
F_32 ( 1 ) ;
F_32 ( 2 ) ;
F_32 ( 3 ) ;
F_32 ( 4 ) ;
F_32 ( 5 ) ;
F_32 ( 6 ) ;
F_32 ( 7 ) ;
F_32 ( 8 ) ;
F_32 ( 9 ) ;
F_32 ( 10 ) ;
F_32 ( 11 ) ;
F_32 ( 12 ) ;
F_32 ( 13 ) ;
F_32 ( 14 ) ;
F_32 ( 15 ) ;
V_210 -> V_223 . V_241 = V_216 & 0x1FFF ;
}
static T_2 F_33 ( union V_238 * V_239 )
{
T_2 V_242 = F_34 ( V_239 -> V_223 . V_243 ) ;
V_242 <<= V_244 ;
V_242 |= F_34 ( V_239 -> V_223 . V_245 ) ;
V_242 = ( ( V_242 & 0x55555555 ) << 1 ) | ( ( V_242 & 0xAAAAAAAA ) >> 1 ) ;
V_242 = ( ( V_242 & 0x33333333 ) << 2 ) | ( ( V_242 & 0xCCCCCCCC ) >> 2 ) ;
V_242 = ( ( V_242 & 0x0F0F0F0F ) << 4 ) | ( ( V_242 & 0xF0F0F0F0 ) >> 4 ) ;
return ( ( V_242 & 0x00FF00FF ) << 8 ) | ( ( V_242 & 0xFF00FF00 ) >> 8 ) ;
}
T_1 F_35 ( struct V_1 * V_2 ,
union V_238 * V_239 )
{
T_2 V_246 = V_247 ;
T_2 V_248 ;
if ( V_239 -> V_223 . V_241 )
F_9 ( V_2 , L_14 ) ;
switch ( V_239 -> V_223 . V_249 & 0x7F ) {
case 0x0 :
V_246 |= V_250 ;
case 0x7F :
break;
default:
F_9 ( V_2 , L_15 ) ;
return V_231 ;
}
switch ( V_239 -> V_223 . V_224 & V_251 ) {
case 0x0 :
V_246 |= V_252 ;
if ( V_239 -> V_223 . V_243 ||
V_239 -> V_223 . V_245 ) {
F_9 ( V_2 , L_16 ) ;
return V_231 ;
}
case V_251 :
break;
default:
F_9 ( V_2 , L_17 ) ;
return V_231 ;
}
switch ( F_34 ( V_239 -> V_223 . V_253 ) & 0xEFFF ) {
case 0x0000 :
V_246 |= V_254 ;
case 0x0FFF :
V_246 |= V_255 ;
break;
case 0xE000 :
V_246 |= V_254 ;
case 0xEFFF :
break;
default:
F_9 ( V_2 , L_18 ) ;
return V_231 ;
}
switch ( V_239 -> V_223 . V_256 & 0xFFFF ) {
case 0x0000 :
V_246 |= V_257 ;
case 0xFFFF :
break;
default:
F_9 ( V_2 , L_19 ) ;
return V_231 ;
}
F_5 ( V_2 , V_258 , V_246 ) ;
V_248 = F_33 ( V_239 ) ;
F_5 ( V_2 , V_259 , ~ V_248 ) ;
F_5 ( V_2 , V_260 , ~ V_248 ) ;
F_36 ( V_2 , V_261 ,
~ V_239 -> V_223 . V_262 [ 0 ] ) ;
F_36 ( V_2 , V_263 ,
~ V_239 -> V_223 . V_264 [ 0 ] ) ;
return 0 ;
}
T_1 F_37 ( struct V_1 * V_2 ,
union V_238 * V_210 ,
T_3 V_265 , T_5 V_220 )
{
T_2 V_266 , V_267 , V_268 , V_222 ;
F_36 ( V_2 , F_38 ( 0 ) ,
V_210 -> V_223 . V_262 [ 0 ] ) ;
F_36 ( V_2 , F_38 ( 1 ) ,
V_210 -> V_223 . V_262 [ 1 ] ) ;
F_36 ( V_2 , F_38 ( 2 ) ,
V_210 -> V_223 . V_262 [ 2 ] ) ;
F_36 ( V_2 , V_269 , V_210 -> V_223 . V_262 [ 0 ] ) ;
F_36 ( V_2 , V_270 , V_210 -> V_223 . V_264 [ 0 ] ) ;
V_266 = F_34 ( V_210 -> V_223 . V_243 ) ;
V_266 <<= V_271 ;
V_266 |= F_34 ( V_210 -> V_223 . V_245 ) ;
F_5 ( V_2 , V_272 , V_266 ) ;
V_267 = F_39 ( V_210 -> V_223 . V_256 ) ;
V_267 <<= V_273 ;
V_267 |= F_34 ( V_210 -> V_223 . V_253 ) ;
F_5 ( V_2 , V_274 , V_267 ) ;
V_268 = V_210 -> V_223 . V_241 ;
V_268 |= V_265 << V_275 ;
F_5 ( V_2 , V_191 , V_268 ) ;
F_6 ( V_2 ) ;
V_222 = V_232 | V_233 |
V_234 | V_235 ;
if ( V_220 == V_207 )
V_222 |= V_276 ;
V_222 |= V_210 -> V_223 . V_224 << V_236 ;
V_222 |= ( T_2 ) V_220 << V_237 ;
V_222 |= ( T_2 ) V_210 -> V_223 . V_249 << V_277 ;
F_5 ( V_2 , V_186 , V_222 ) ;
return 0 ;
}
T_1 F_40 ( struct V_1 * V_2 ,
union V_238 * V_210 ,
T_3 V_265 )
{
T_2 V_268 ;
T_2 V_222 = 0 ;
T_2 V_278 ;
T_1 V_279 = 0 ;
V_268 = V_210 -> V_223 . V_241 ;
V_268 |= V_265 << V_275 ;
F_5 ( V_2 , V_191 , V_268 ) ;
F_6 ( V_2 ) ;
F_5 ( V_2 , V_186 , V_280 ) ;
for ( V_278 = 10 ; V_278 ; V_278 -- ) {
F_17 ( 10 ) ;
V_222 = F_8 ( V_2 , V_186 ) ;
if ( ! ( V_222 & V_187 ) )
break;
}
if ( ! V_278 )
V_279 = V_188 ;
if ( V_222 & V_281 ) {
F_5 ( V_2 , V_191 , V_268 ) ;
F_6 ( V_2 ) ;
F_5 ( V_2 , V_186 ,
V_282 ) ;
}
return V_279 ;
}
static T_1 F_41 ( struct V_1 * V_2 , T_2 V_283 , T_5 * V_284 )
{
T_2 V_285 ;
F_5 ( V_2 , V_39 , V_286 |
( V_283 << 8 ) ) ;
F_6 ( V_2 ) ;
F_17 ( 10 ) ;
V_285 = F_8 ( V_2 , V_39 ) ;
* V_284 = ( T_5 ) V_285 ;
return 0 ;
}
static T_1 F_42 ( struct V_1 * V_2 , T_2 V_283 , T_5 V_284 )
{
T_2 V_285 ;
V_285 = ( V_283 << 8 ) | V_284 ;
F_5 ( V_2 , V_39 , V_285 ) ;
F_6 ( V_2 ) ;
F_17 ( 10 ) ;
return 0 ;
}
static T_1 F_43 ( struct V_1 * V_2 )
{
T_1 V_24 = 0 ;
V_24 = F_44 ( V_2 ) ;
if ( V_24 != 0 )
goto V_79;
V_24 = F_45 ( V_2 ) ;
if ( V_24 != 0 )
goto V_79;
V_2 -> V_4 . V_128 = true ;
V_2 -> V_4 . V_287 = V_288 ;
if ( V_24 == 0 )
V_24 = F_46 ( V_2 ) ;
V_79:
return V_24 ;
}
static T_1 F_47 ( struct V_1 * V_2 )
{
T_1 V_74 = V_289 ;
V_74 = F_48 ( V_2 ) ;
if ( V_74 != 0 ) {
if ( V_2 -> V_4 . V_5 . V_6 ( V_2 ) == V_62 )
goto V_79;
else
V_74 = F_49 ( V_2 ) ;
}
if ( V_2 -> V_14 . type == V_290 ) {
V_2 -> V_14 . type = V_291 ;
V_74 = 0 ;
}
if ( V_2 -> V_14 . type == V_292 )
V_74 = V_157 ;
V_79:
return V_74 ;
}
static T_2 F_50 ( struct V_1 * V_2 )
{
T_2 V_293 = V_294 ;
T_2 V_75 = F_8 ( V_2 , V_42 ) ;
T_2 V_141 = F_8 ( V_2 , V_142 ) ;
T_2 V_147 = V_141 & V_148 ;
T_2 V_295 = V_75 & V_296 ;
T_2 V_145 = V_75 & V_146 ;
T_3 V_297 = 0 ;
T_5 V_298 = 0 ;
T_5 V_299 = 0 ;
V_2 -> V_14 . V_5 . V_61 ( V_2 ) ;
switch ( V_2 -> V_14 . type ) {
case V_66 :
case V_98 :
V_2 -> V_14 . V_5 . V_300 ( V_2 , V_301 , V_302 ,
& V_297 ) ;
if ( V_297 & V_303 )
V_293 |= V_304 ;
if ( V_297 & V_305 )
V_293 |= V_306 ;
if ( V_297 & V_307 )
V_293 |= V_308 ;
goto V_79;
default:
break;
}
switch ( V_75 & V_43 ) {
case V_85 :
case V_82 :
if ( V_145 == V_309 ) {
V_293 = V_310 |
V_311 ;
goto V_79;
} else
goto V_312;
break;
case V_83 :
if ( V_295 == V_313 )
V_293 = V_314 ;
else if ( V_295 == V_315 )
V_293 = V_316 ;
else if ( V_295 == V_317 )
V_293 = V_318 ;
goto V_79;
break;
case V_48 :
if ( V_147 == V_319 ) {
V_293 = V_320 ;
goto V_79;
} else if ( V_147 == V_151 )
goto V_312;
break;
case V_86 :
case V_87 :
if ( V_75 & V_91 )
V_293 |= V_310 ;
if ( V_75 & V_90 )
V_293 |= V_316 ;
if ( V_75 & V_89 )
V_293 |= V_320 ;
goto V_79;
break;
default:
goto V_79;
break;
}
V_312:
V_2 -> V_14 . V_5 . V_321 ( V_2 ) ;
if ( V_2 -> V_14 . V_30 == V_322 )
goto V_79;
switch ( V_2 -> V_14 . type ) {
case V_323 :
case V_324 :
V_293 = V_325 ;
break;
case V_326 :
case V_327 :
V_293 = V_328 ;
break;
case V_329 :
case V_330 :
case V_331 :
case V_332 :
V_2 -> V_14 . V_5 . V_333 ( V_2 ,
V_334 , & V_299 ) ;
V_2 -> V_14 . V_5 . V_333 ( V_2 ,
V_335 , & V_298 ) ;
if ( V_298 & V_336 )
V_293 = V_337 ;
else if ( V_298 & V_338 )
V_293 = V_339 ;
else if ( V_299 & V_340 )
V_293 = V_306 ;
break;
default:
break;
}
V_79:
return V_293 ;
}
static T_1 F_51 ( struct V_1 * V_2 , T_2 V_341 )
{
V_2 -> V_4 . V_5 . V_342 ( V_2 ) ;
F_5 ( V_2 , V_343 , V_341 ) ;
V_2 -> V_4 . V_5 . V_344 ( V_2 ) ;
return 0 ;
}
static T_1 F_46 ( struct V_1 * V_2 )
{
T_1 V_74 = V_345 ;
T_3 V_346 , V_347 ;
T_3 V_348 = 0 ;
if ( V_2 -> V_14 . V_97 != V_7 ) {
V_74 = 0 ;
goto V_349;
}
V_2 -> V_37 . V_5 . V_38 ( V_2 , V_350 , & V_346 ) ;
if ( ( V_346 == 0 ) || ( V_346 == 0xFFFF ) )
goto V_349;
V_2 -> V_37 . V_5 . V_38 ( V_2 , ( V_346 +
V_351 ) ,
& V_347 ) ;
if ( ( V_347 == 0 ) || ( V_347 == 0xFFFF ) )
goto V_349;
V_2 -> V_37 . V_5 . V_38 ( V_2 , ( V_347 +
V_352 ) ,
& V_348 ) ;
if ( V_348 > 0x5 )
V_74 = 0 ;
V_349:
return V_74 ;
}
static bool F_2 ( struct V_1 * V_2 )
{
bool V_353 = false ;
T_3 V_346 , V_354 , V_355 ;
T_1 V_74 ;
V_74 = V_2 -> V_37 . V_5 . V_38 ( V_2 , V_350 , & V_346 ) ;
if ( ( V_74 != 0 ) ||
( V_346 == 0 ) || ( V_346 == 0xFFFF ) )
goto V_79;
V_74 = V_2 -> V_37 . V_5 . V_38 ( V_2 , ( V_346 +
V_356 ) ,
& V_354 ) ;
if ( ( V_74 != 0 ) ||
( V_354 == 0 ) || ( V_354 == 0xFFFF ) )
goto V_79;
V_74 = V_2 -> V_37 . V_5 . V_38 ( V_2 , ( V_354 +
V_357 ) ,
& V_355 ) ;
if ( ( V_74 == 0 ) &&
( V_355 & V_358 ) )
V_353 = true ;
V_79:
return V_353 ;
}
static T_1 F_52 ( struct V_1 * V_2 , T_3 V_359 ,
T_3 V_360 , T_3 * V_361 )
{
struct V_362 * V_37 = & V_2 -> V_37 ;
T_1 V_24 = V_231 ;
if ( ( V_37 -> type == V_363 ) &&
( V_359 + ( V_360 - 1 ) <= V_364 ) )
V_24 = F_53 ( V_2 , V_359 , V_360 ,
V_361 ) ;
else
V_24 = F_54 ( V_2 , V_359 ,
V_360 ,
V_361 ) ;
return V_24 ;
}
static T_1 F_55 ( struct V_1 * V_2 ,
T_3 V_359 , T_3 * V_361 )
{
struct V_362 * V_37 = & V_2 -> V_37 ;
T_1 V_24 = V_231 ;
if ( ( V_37 -> type == V_363 ) &&
( V_359 <= V_364 ) )
V_24 = F_56 ( V_2 , V_359 , V_361 ) ;
else
V_24 = F_57 ( V_2 , V_359 , V_361 ) ;
return V_24 ;
}
