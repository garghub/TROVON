static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_5 ;
if ( V_2 -> V_4 . V_6 != V_7 ) {
V_4 -> type = V_8 ;
return 0 ;
}
V_4 -> V_9 = 1 ;
V_4 -> V_10 = V_11 ;
V_4 -> V_12 = 100 ;
V_4 -> V_13 . V_14 = V_15 ;
V_4 -> V_13 . V_16 = V_17 ;
switch ( V_2 -> V_18 . type ) {
case V_19 :
case V_20 :
V_4 -> type = V_21 ;
break;
case V_22 :
V_4 -> type = V_23 ;
break;
case V_24 :
case V_25 :
V_4 -> type = V_26 ;
V_4 -> V_13 . V_27 = V_28 ;
V_4 -> V_13 . V_29 = V_30 ;
V_4 -> V_13 . V_31 = V_32 ;
V_4 -> V_13 . V_33 = V_34 ;
break;
default:
return - V_35 ;
break;
}
V_5 = F_2 ( V_2 ) ;
if ( V_5 ) {
F_3 ( L_1 ) ;
return V_5 ;
}
switch ( V_2 -> V_18 . type ) {
case V_19 :
case V_20 :
if ( V_4 -> V_36 != V_37 )
V_5 = - V_35 ;
break;
case V_22 :
if ( V_4 -> V_36 != V_38 )
V_5 = - V_35 ;
break;
case V_24 :
case V_25 :
if ( V_4 -> V_36 != V_39 )
V_5 = - V_35 ;
break;
default:
V_5 = - V_35 ;
break;
}
if ( V_5 )
F_3 ( L_2 , V_4 -> V_36 ) ;
return V_5 ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = & V_2 -> V_41 ;
T_2 V_42 = F_5 ( V_43 ) ;
T_3 V_44 ;
V_41 -> V_45 = 8 ;
V_41 -> V_46 = 1 ;
switch ( V_41 -> V_47 ) {
case V_48 :
V_41 -> V_49 = 32 ;
V_41 -> V_50 = 16 ;
break;
case V_51 :
V_41 -> V_49 = 8 ;
V_41 -> V_50 = 8 ;
break;
default:
V_41 -> V_49 = V_42 & V_52 ? 32 : 8 ;
V_41 -> V_50 = V_42 & V_52 ? 16 : 8 ;
break;
}
switch ( V_2 -> V_18 . type ) {
case V_22 :
case V_24 :
case V_25 :
if ( ( ( V_42 >> 15 ) & 0x3 ) == 0x3 ) {
V_41 -> type = V_53 ;
V_41 -> V_54 = 2048 ;
V_42 &= ~ V_55 ;
F_6 ( V_43 , V_42 ) ;
break;
}
default:
V_41 -> type = V_56 ;
V_44 = ( T_3 ) ( ( V_42 & V_57 ) >>
V_58 ) ;
V_44 += V_59 ;
if ( V_44 > 14 )
V_44 = 14 ;
V_41 -> V_54 = 1 << V_44 ;
break;
}
switch ( V_2 -> V_18 . type ) {
case V_24 :
case V_25 :
V_41 -> V_13 . V_27 = V_28 ;
V_41 -> V_13 . V_29 = V_30 ;
break;
default:
break;
}
return 0 ;
}
static T_1 F_7 ( struct V_1 * V_2 )
{
struct V_60 * V_18 = & V_2 -> V_18 ;
T_2 V_61 = 0 ;
T_2 V_62 = 0 ;
bool V_63 = false ;
switch ( V_2 -> V_64 -> V_65 -> V_66 ) {
case V_67 :
case V_68 :
case V_69 :
V_2 -> V_4 . V_6 = V_70 ;
V_18 -> V_13 . V_71 =
V_72 ;
V_18 -> V_13 . V_73 = V_74 ;
V_18 -> V_13 . V_75 =
V_76 ;
break;
case V_77 :
case V_78 :
case V_79 :
case V_80 :
V_2 -> V_4 . V_6 = V_81 ;
V_18 -> V_13 . V_71 =
V_72 ;
V_18 -> V_13 . V_73 = V_82 ;
V_18 -> V_13 . V_75 =
V_76 ;
break;
default:
V_2 -> V_4 . V_6 = V_7 ;
V_18 -> V_13 . V_71 =
V_83 ;
V_18 -> V_13 . V_73 = V_84 ;
V_18 -> V_13 . V_75 = V_85 ;
break;
}
V_18 -> V_86 = 128 ;
V_18 -> V_87 = V_88 ;
V_18 -> V_89 = true ;
switch ( V_2 -> V_18 . type ) {
case V_22 :
V_18 -> V_13 . V_90 = V_91 ;
V_18 -> V_13 . V_92 = V_93 ;
V_18 -> V_13 . V_94 = V_95 ;
V_18 -> V_13 . V_96 = V_97 ;
V_18 -> V_98 = true ;
V_18 -> V_99 = ! ! ( F_5 ( V_100 ) &
V_101 ) ;
break;
case V_24 :
case V_25 :
V_18 -> V_13 . V_90 = V_91 ;
V_18 -> V_13 . V_92 = V_102 ;
V_18 -> V_13 . V_94 = V_103 ;
break;
default:
V_18 -> V_13 . V_92 = V_93 ;
V_18 -> V_13 . V_94 = V_95 ;
V_18 -> V_13 . V_96 = V_97 ;
V_18 -> V_98 = true ;
break;
}
switch ( V_2 -> V_18 . type ) {
case V_19 :
case V_20 :
V_62 = F_5 ( V_104 ) ;
if ( ! ( V_62 & V_105 ) ) {
F_6 ( V_104 , V_62 | V_105 ) ;
V_63 = true ;
} else {
V_63 = false ;
}
break;
default:
V_63 = true ;
break;
}
if ( V_63 ) {
V_61 = F_5 ( V_106 ) ;
if ( V_61 & V_107 ) {
F_3 ( L_3 ) ;
}
F_6 ( V_106 , V_61 & ~ V_107 ) ;
}
V_2 -> V_108 . V_109 . V_110 = 0 ;
return 0 ;
}
static T_1 F_8 ( struct V_111 * V_64 )
{
struct V_1 * V_2 = & V_64 -> V_2 ;
static int V_112 ;
struct V_113 * V_65 = V_64 -> V_65 ;
int V_114 = F_5 ( V_115 ) & V_116 ;
T_1 V_117 ;
V_117 = F_7 ( V_2 ) ;
if ( V_117 )
return V_117 ;
V_117 = F_4 ( V_2 ) ;
if ( V_117 )
return V_117 ;
V_117 = F_1 ( V_2 ) ;
if ( V_117 )
return V_117 ;
switch ( V_65 -> V_66 ) {
case V_118 :
case V_69 :
case V_119 :
case V_120 :
V_64 -> V_121 |= V_122 ;
if ( V_112 == 0 )
V_64 -> V_121 |= V_123 ;
V_112 ++ ;
if ( V_112 == 4 )
V_112 = 0 ;
break;
default:
break;
}
switch ( V_64 -> V_2 . V_18 . type ) {
case V_19 :
if ( ( ( V_65 -> V_66 == V_67 ) ||
( V_65 -> V_66 == V_77 ) ||
( V_65 -> V_66 == V_124 ) ) &&
( V_114 ) )
V_64 -> V_121 &= ~ V_125 ;
if ( V_64 -> V_121 & V_122 &&
( ! ( V_64 -> V_121 & V_123 ) ) )
V_64 -> V_121 &= ~ V_125 ;
if ( V_65 -> V_66 == V_79 )
V_64 -> V_121 &= ~ V_125 ;
break;
case V_22 :
if ( V_65 -> V_66 == V_126 ) {
V_64 -> V_121 |= V_127 ;
V_64 -> V_128 = V_129 ;
}
break;
default:
break;
}
return 0 ;
}
static T_1 F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_5 ;
T_3 V_130 = 0 ;
switch ( V_2 -> V_18 . type ) {
case V_19 :
case V_20 :
V_4 -> V_36 = V_37 ;
break;
case V_22 :
return F_9 ( V_2 ) ;
break;
case V_24 :
case V_25 :
V_5 = F_10 ( V_2 , V_131 , & V_130 ) ;
if ( V_5 )
return V_5 ;
V_4 -> V_36 = ( T_2 ) ( V_130 << 16 ) ;
F_11 ( 20 , 40 ) ;
V_5 = F_10 ( V_2 , V_132 , & V_130 ) ;
if ( V_5 )
return V_5 ;
V_4 -> V_36 |= ( T_2 ) ( V_130 ) ;
V_4 -> V_133 = ( T_2 ) ( V_130 & ~ V_134 ) ;
break;
default:
return - V_35 ;
break;
}
return 0 ;
}
static T_1 F_12 ( struct V_1 * V_2 )
{
T_2 V_61 ;
T_1 V_135 = V_2 -> V_41 . V_54 + 1 ;
T_1 V_136 = V_2 -> V_41 . V_54 + 1 ;
T_1 V_137 = 0 ;
if ( V_2 -> V_108 . V_109 . V_110 > 2 )
V_135 = 1 ;
while ( V_137 < V_135 ) {
V_61 = F_5 ( V_106 ) ;
if ( ! ( V_61 & V_107 ) )
break;
F_11 ( 50 , 100 ) ;
V_137 ++ ;
}
if ( V_137 == V_135 ) {
F_3 ( L_4 ) ;
V_2 -> V_108 . V_109 . V_110 ++ ;
}
for ( V_137 = 0 ; V_137 < V_136 ; V_137 ++ ) {
V_61 = F_5 ( V_106 ) ;
F_6 ( V_106 , V_61 | V_138 ) ;
if ( F_5 ( V_106 ) & V_138 )
break;
F_11 ( 50 , 100 ) ;
}
if ( V_137 == V_136 ) {
F_13 ( V_2 ) ;
F_3 ( L_5 ) ;
return - V_139 ;
}
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_2 V_61 ;
V_61 = F_5 ( V_106 ) ;
V_61 &= ~ ( V_107 | V_138 ) ;
F_6 ( V_106 , V_61 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 )
{
T_2 V_140 ;
T_1 V_137 = 0 ;
V_140 = F_5 ( V_141 ) ;
do {
V_140 |= V_142 ;
F_6 ( V_141 , V_140 ) ;
V_140 = F_5 ( V_141 ) ;
if ( V_140 & V_142 )
break;
F_11 ( 2000 , 4000 ) ;
V_137 ++ ;
} while ( V_137 < V_143 );
if ( V_137 == V_143 ) {
F_15 ( V_2 ) ;
F_3 ( L_6 ) ;
return - V_35 ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
T_2 V_140 ;
V_140 = F_5 ( V_141 ) ;
V_140 &= ~ V_142 ;
F_6 ( V_141 , V_140 ) ;
}
static T_1 V_28 ( struct V_1 * V_2 )
{
T_1 V_5 ;
F_16 ( & V_144 ) ;
V_5 = F_14 ( V_2 ) ;
if ( V_5 )
F_17 ( & V_144 ) ;
return V_5 ;
}
static void V_30 ( struct V_1 * V_2 )
{
F_15 ( V_2 ) ;
F_17 ( & V_144 ) ;
}
static T_1 V_32 ( struct V_1 * V_2 , bool V_145 )
{
T_2 V_146 = F_5 ( V_147 ) ;
if ( V_145 )
V_146 |= V_148 ;
else
V_146 &= ~ V_148 ;
F_6 ( V_147 , V_146 ) ;
return 0 ;
}
static T_1 V_34 ( struct V_1 * V_2 , bool V_145 )
{
T_2 V_146 = F_5 ( V_147 ) ;
if ( ! V_145 ) {
V_146 &= ~ V_149 ;
} else if ( ( V_2 -> V_4 . V_150 == V_151 ) ||
( V_2 -> V_4 . V_150 == V_152 ) ||
( V_2 -> V_4 . V_150 == V_153 ) ) {
V_146 |= V_149 ;
}
F_6 ( V_147 , V_146 ) ;
return 0 ;
}
static T_1 F_18 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_12 ( V_2 ) ;
if ( V_5 )
return V_5 ;
switch ( V_2 -> V_18 . type ) {
case V_22 :
break;
default:
V_5 = F_19 ( V_2 ) ;
break;
}
if ( V_5 )
F_13 ( V_2 ) ;
return V_5 ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_13 ( V_2 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 , T_3 V_154 , T_3 V_155 ,
T_3 * V_146 )
{
T_1 V_5 ;
switch ( V_2 -> V_18 . type ) {
case V_22 :
case V_24 :
case V_25 :
V_5 = F_23 ( V_2 , V_154 , V_155 , V_146 ) ;
break;
case V_19 :
case V_20 :
V_5 = F_24 ( V_2 , V_154 , V_155 , V_146 ) ;
break;
default:
V_5 = - V_139 ;
break;
}
return V_5 ;
}
static T_1 F_25 ( struct V_1 * V_2 )
{
T_2 V_42 ;
T_1 V_5 ;
T_3 V_137 ;
V_5 = F_26 ( V_2 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_41 . type != V_53 )
return 0 ;
for ( V_137 = 0 ; V_137 < V_156 ; V_137 ++ ) {
F_11 ( 1000 , 2000 ) ;
if ( ! ( F_5 ( V_43 ) & V_157 ) )
break;
}
if ( V_137 == V_156 )
return - V_139 ;
if ( ( F_5 ( V_158 ) & 0xFF00 ) == V_159 ) {
F_6 ( V_160 , V_161 ) ;
F_27 () ;
F_6 ( V_160 , V_162 ) ;
}
V_42 = F_5 ( V_43 ) | V_157 ;
F_6 ( V_43 , V_42 ) ;
for ( V_137 = 0 ; V_137 < V_156 ; V_137 ++ ) {
F_11 ( 1000 , 2000 ) ;
if ( ! ( F_5 ( V_43 ) & V_157 ) )
break;
}
if ( V_137 == V_156 )
return - V_139 ;
return 0 ;
}
static T_1 F_28 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 . type == V_53 )
F_29 ( V_2 ) ;
return F_30 ( V_2 ) ;
}
static T_1 F_23 ( struct V_1 * V_2 , T_3 V_154 ,
T_3 V_155 , T_3 * V_146 )
{
struct V_40 * V_41 = & V_2 -> V_41 ;
T_2 V_137 , V_163 = 0 ;
T_1 V_5 = 0 ;
if ( ( V_154 >= V_41 -> V_54 ) || ( V_155 > ( V_41 -> V_54 - V_154 ) ) ||
( V_155 == 0 ) ) {
F_3 ( L_7 ) ;
return - V_139 ;
}
for ( V_137 = 0 ; V_137 < V_155 ; V_137 ++ ) {
V_163 = ( ( V_146 [ V_137 ] << V_164 ) |
( ( V_154 + V_137 ) << V_165 ) |
V_166 ) ;
V_5 = F_31 ( V_2 , V_167 ) ;
if ( V_5 )
break;
F_6 ( V_168 , V_163 ) ;
V_5 = F_31 ( V_2 , V_167 ) ;
if ( V_5 )
break;
}
return V_5 ;
}
static T_1 F_32 ( struct V_1 * V_2 )
{
T_1 V_169 = V_170 ;
while ( V_169 ) {
if ( F_5 ( V_171 ) & V_172 )
break;
F_11 ( 1000 , 2000 ) ;
V_169 -- ;
}
if ( ! V_169 ) {
F_3 ( L_8 ) ;
return - V_173 ;
}
return 0 ;
}
static T_1 F_33 ( struct V_1 * V_2 , bool V_145 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_5 ;
T_3 V_146 ;
V_5 = F_10 ( V_2 , V_174 , & V_146 ) ;
if ( V_5 )
return V_5 ;
if ( V_145 ) {
V_146 |= V_175 ;
V_5 = F_34 ( V_2 , V_174 , V_146 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_10 ( V_2 , V_176 , & V_146 ) ;
if ( V_5 )
return V_5 ;
V_146 &= ~ V_177 ;
V_5 = F_34 ( V_2 , V_176 , V_146 ) ;
if ( V_5 )
return V_5 ;
} else {
V_146 &= ~ V_175 ;
V_5 = F_34 ( V_2 , V_174 , V_146 ) ;
if ( V_4 -> V_178 == V_179 ) {
V_5 = F_10 ( V_2 , V_176 ,
& V_146 ) ;
if ( V_5 )
return V_5 ;
V_146 |= V_177 ;
V_5 = F_34 ( V_2 , V_176 ,
V_146 ) ;
if ( V_5 )
return V_5 ;
} else if ( V_4 -> V_178 == V_180 ) {
V_5 = F_10 ( V_2 , V_176 ,
& V_146 ) ;
if ( V_5 )
return V_5 ;
V_146 &= ~ V_177 ;
V_5 = F_34 ( V_2 , V_176 ,
V_146 ) ;
if ( V_5 )
return V_5 ;
}
}
return 0 ;
}
static T_1 F_35 ( struct V_1 * V_2 )
{
T_2 V_181 , V_182 , V_42 , V_183 ;
T_1 V_5 ;
V_5 = F_36 ( V_2 ) ;
if ( V_5 )
F_3 ( L_9 ) ;
F_3 ( L_10 ) ;
F_6 ( V_184 , 0xffffffff ) ;
F_6 ( V_185 , 0 ) ;
V_183 = F_5 ( V_186 ) ;
V_183 &= ~ V_187 ;
F_6 ( V_186 , V_183 ) ;
F_27 () ;
F_11 ( 10000 , 20000 ) ;
switch ( V_2 -> V_18 . type ) {
case V_22 :
V_5 = F_14 ( V_2 ) ;
break;
case V_24 :
case V_25 :
V_5 = V_28 ( V_2 ) ;
break;
default:
break;
}
if ( V_5 )
F_3 ( L_11 ) ;
V_181 = F_5 ( V_188 ) ;
F_3 ( L_12 ) ;
F_6 ( V_188 , V_181 | V_189 ) ;
switch ( V_2 -> V_18 . type ) {
case V_24 :
case V_25 :
V_30 ( V_2 ) ;
break;
default:
break;
}
if ( V_2 -> V_41 . type == V_53 ) {
F_11 ( 10 , 20 ) ;
V_182 = F_5 ( V_190 ) ;
V_182 |= V_191 ;
F_6 ( V_190 , V_182 ) ;
F_27 () ;
}
V_5 = F_37 ( V_2 ) ;
if ( V_5 )
return V_5 ;
switch ( V_2 -> V_18 . type ) {
case V_19 :
case V_20 :
V_42 = F_5 ( V_43 ) ;
V_42 &= ~ ( V_192 | V_193 ) ;
F_6 ( V_43 , V_42 ) ;
break;
case V_22 :
case V_24 :
case V_25 :
F_38 ( 25 ) ;
break;
default:
break;
}
F_6 ( V_184 , 0xffffffff ) ;
F_5 ( V_194 ) ;
if ( V_2 -> V_18 . type == V_19 ) {
V_5 = F_39 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_40 ( V_2 , true ) ;
}
if ( V_2 -> V_4 . V_6 == V_81 )
V_2 -> V_18 . V_195 = V_196 ;
return 0 ;
}
static T_1 F_41 ( struct V_1 * V_2 )
{
struct V_60 * V_18 = & V_2 -> V_18 ;
T_2 V_197 ;
T_1 V_5 ;
T_3 V_137 , V_198 = V_18 -> V_87 ;
F_42 ( V_2 ) ;
V_5 = V_18 -> V_13 . V_199 ( V_2 ) ;
if ( V_5 )
F_3 ( L_13 ) ;
F_3 ( L_14 ) ;
V_18 -> V_13 . V_200 ( V_2 ) ;
if ( F_43 ( V_2 ) )
V_198 -- ;
F_44 ( V_2 , V_198 ) ;
F_3 ( L_15 ) ;
for ( V_137 = 0 ; V_137 < V_18 -> V_86 ; V_137 ++ )
F_45 ( V_2 , V_201 , V_137 , 0 ) ;
V_5 = V_18 -> V_13 . V_202 ( V_2 ) ;
V_197 = F_5 ( F_46 ( 0 ) ) ;
V_197 = ( ( V_197 & ~ V_203 ) |
V_204 | V_205 ) ;
F_6 ( F_46 ( 0 ) , V_197 ) ;
switch ( V_18 -> type ) {
case V_22 :
F_47 ( V_2 ) ;
case V_24 :
case V_25 :
V_197 = F_5 ( V_206 ) ;
V_197 |= V_207 ;
F_6 ( V_206 , V_197 ) ;
break;
default:
V_197 = F_5 ( F_46 ( 1 ) ) ;
V_197 = ( ( V_197 & ~ V_203 ) |
V_204 |
V_205 ) ;
F_6 ( F_46 ( 1 ) , V_197 ) ;
break;
}
F_48 ( V_2 ) ;
return V_5 ;
}
static void F_42 ( struct V_1 * V_2 )
{
T_2 V_208 ;
V_208 = F_5 ( F_46 ( 0 ) ) ;
V_208 |= ( 1 << 22 ) ;
F_6 ( F_46 ( 0 ) , V_208 ) ;
V_208 = F_5 ( F_46 ( 1 ) ) ;
V_208 |= ( 1 << 22 ) ;
F_6 ( F_46 ( 1 ) , V_208 ) ;
V_208 = F_5 ( F_49 ( 0 ) ) ;
V_208 &= ~ ( 0xF << 27 ) ;
switch ( V_2 -> V_18 . type ) {
case V_19 :
case V_20 :
V_208 |= ( 1 << 23 ) | ( 1 << 24 ) | ( 1 << 25 ) | ( 1 << 26 ) ;
break;
case V_24 :
case V_25 :
V_208 |= ( 1 << 26 ) ;
break;
default:
break;
}
F_6 ( F_49 ( 0 ) , V_208 ) ;
V_208 = F_5 ( F_49 ( 1 ) ) ;
switch ( V_2 -> V_18 . type ) {
case V_19 :
case V_20 :
V_208 &= ~ ( ( 1 << 29 ) | ( 1 << 30 ) ) ;
V_208 |= ( 1 << 22 ) | ( 1 << 24 ) | ( 1 << 25 ) | ( 1 << 26 ) ;
if ( F_5 ( V_186 ) & V_209 )
V_208 &= ~ ( 1 << 28 ) ;
else
V_208 |= ( 1 << 28 ) ;
F_6 ( F_49 ( 1 ) , V_208 ) ;
break;
default:
break;
}
switch ( V_2 -> V_18 . type ) {
case V_22 :
case V_24 :
case V_25 :
V_208 = F_5 ( V_188 ) ;
V_208 &= ~ ( 1 << 29 ) ;
F_6 ( V_188 , V_208 ) ;
break;
default:
break;
}
switch ( V_2 -> V_18 . type ) {
case V_22 :
case V_24 :
case V_25 :
V_208 = F_5 ( V_190 ) ;
V_208 &= ~ ( 1 << 23 ) ;
V_208 |= ( 1 << 22 ) ;
F_6 ( V_190 , V_208 ) ;
break;
default:
break;
}
if ( V_2 -> V_18 . type == V_19 ) {
V_208 = F_5 ( V_210 ) ;
V_208 |= V_211 ;
F_6 ( V_210 , V_208 ) ;
}
if ( ( V_2 -> V_18 . type == V_19 ) || ( V_2 -> V_18 . type == V_20 ) ) {
V_208 = F_5 ( V_190 ) ;
V_208 &= ~ V_212 ;
F_6 ( V_190 , V_208 ) ;
}
if ( V_2 -> V_18 . type <= V_22 ) {
V_208 = F_5 ( V_213 ) ;
V_208 |= ( V_214 | V_215 ) ;
F_6 ( V_213 , V_208 ) ;
}
switch ( V_2 -> V_18 . type ) {
case V_24 :
case V_25 :
V_208 = F_5 ( V_206 ) ;
V_208 |= ( 1 << 22 ) ;
F_6 ( V_206 , V_208 ) ;
V_208 = F_5 ( V_216 ) ;
V_208 |= 1 ;
F_6 ( V_216 , V_208 ) ;
break;
default:
break;
}
}
static void F_50 ( struct V_1 * V_2 )
{
T_2 V_154 ;
T_2 V_217 = 0 ;
T_2 V_218 = 0 ;
T_2 V_219 = 0 ;
switch ( V_2 -> V_18 . type ) {
case V_22 :
case V_24 :
case V_25 :
if ( V_2 -> V_220 . V_221 != 0 ) {
V_218 = ( V_2 -> V_220 . V_221 >>
V_222 ) &
V_223 ;
V_219 =
1 << ( V_2 -> V_220 . V_221 &
V_224 ) ;
}
break;
default:
break;
}
for ( V_154 = 0 ; V_154 < V_225 ; V_154 ++ ) {
V_217 = ( V_154 == V_218 ) ? V_219 : 0 ;
F_45 ( V_2 , V_226 , V_154 , V_217 ) ;
F_27 () ;
}
}
static bool V_102 ( struct V_1 * V_2 )
{
T_3 V_146 ;
F_51 ( V_2 , V_227 , 1 , & V_146 ) ;
return ( V_146 & V_228 ) != 0 ;
}
static T_1 V_103 ( struct V_1 * V_2 )
{
T_2 V_181 ;
T_2 V_137 ;
V_181 = V_2 -> V_18 . V_229 ;
if ( ! ( V_230 & F_5 ( V_115 ) ) ) {
for ( V_137 = 0 ; V_137 < 4 ; V_137 ++ )
if ( ( ( V_2 -> V_18 . V_229 >> ( V_137 * 8 ) ) & 0xFF ) ==
V_231 )
V_181 |= ( V_232 << ( V_137 * 8 ) ) ;
}
F_6 ( V_233 , V_181 ) ;
return 0 ;
}
bool F_52 ( struct V_1 * V_2 )
{
T_3 V_234 = 0 ;
T_3 V_235 = 0 ;
T_1 V_5 ;
V_5 = F_10 ( V_2 , V_236 , & V_235 ) ;
if ( V_5 )
return false ;
if ( V_235 == V_237 ) {
V_5 = F_10 ( V_2 , V_238 , & V_234 ) ;
if ( V_5 )
return false ;
if ( ( V_234 & V_239 ) ==
V_239 )
return true ;
}
return false ;
}
static T_1 F_53 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_18 . type ) {
case V_22 :
case V_24 :
case V_25 :
if ( V_2 -> V_240 . V_241 == V_242 )
V_2 -> V_240 . V_241 = V_243 ;
break;
default:
break;
}
return F_54 ( V_2 ) ;
}
static T_1 V_83 ( struct V_1 * V_2 )
{
T_2 V_181 ;
T_1 V_5 ;
V_181 = F_5 ( V_188 ) ;
V_181 |= V_244 ;
V_181 &= ~ ( V_245 | V_246 ) ;
F_6 ( V_188 , V_181 ) ;
switch ( V_2 -> V_4 . type ) {
case V_23 :
case V_26 :
V_5 = F_55 ( V_2 ) ;
break;
case V_21 :
V_5 = F_56 ( V_2 ) ;
break;
default:
return - V_35 ;
break;
}
if ( V_5 )
return V_5 ;
return F_57 ( V_2 ) ;
}
static T_1 V_72 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_18 . type ) {
case V_19 :
case V_20 :
F_6 ( V_247 , V_248 ) ;
break;
default:
break;
}
return F_58 ( V_2 ) ;
}
static T_1 V_82 ( struct V_1 * V_2 )
{
struct V_60 * V_18 = & V_2 -> V_18 ;
T_2 V_249 ;
T_2 V_181 ;
T_2 V_250 ;
T_2 V_251 ;
T_2 V_137 ;
T_1 V_5 = 0 ;
V_181 = F_5 ( V_188 ) ;
V_250 = F_5 ( V_115 ) ;
F_5 ( V_252 ) ;
F_11 ( 10 , 20 ) ;
V_249 = F_5 ( V_252 ) ;
if ( ( V_249 & V_253 ) && ! ( V_249 & V_254 ) ) {
switch ( V_18 -> V_195 ) {
case V_255 :
if ( ! ( V_250 & V_230 ) ) {
V_18 -> V_195 =
V_256 ;
V_18 -> V_257 = false ;
F_3 ( L_16 ) ;
} else {
V_18 -> V_257 = true ;
}
break;
case V_258 :
if ( V_249 & V_259 ) {
F_6 ( V_260 , V_18 -> V_251 ) ;
F_6 ( V_188 , ( V_181 & ~ V_244 ) ) ;
V_18 -> V_195 =
V_256 ;
V_18 -> V_257 = false ;
F_3 ( L_17 ) ;
} else {
V_18 -> V_257 = true ;
}
break;
case V_256 :
if ( V_249 & V_259 ) {
if ( V_250 & V_230 ) {
V_18 -> V_195 =
V_255 ;
F_3 ( L_18 ) ;
V_18 -> V_257 = true ;
} else {
V_18 -> V_195 =
V_196 ;
F_3 ( L_19 ) ;
}
} else {
F_6 ( V_260 , ( V_18 -> V_251 & ~ V_261 ) ) ;
V_181 |= ( V_244 | V_262 ) ;
F_6 ( V_188 , V_181 ) ;
V_5 = F_59 ( V_2 ) ;
if ( V_5 ) {
F_3 ( L_20 ) ;
break;
}
V_18 -> V_195 =
V_258 ;
V_18 -> V_257 = true ;
F_3 ( L_21 ) ;
}
break;
case V_196 :
default:
F_6 ( V_260 , V_18 -> V_251 ) ;
F_6 ( V_188 , ( V_181 & ~ V_244 ) ) ;
V_18 -> V_195 =
V_256 ;
V_18 -> V_257 = false ;
F_3 ( L_22 ) ;
break;
}
} else {
if ( ! ( V_249 & V_253 ) ) {
V_18 -> V_257 = false ;
V_18 -> V_195 = V_196 ;
F_3 ( L_23 ) ;
} else {
for ( V_137 = 0 ; V_137 < V_263 ; V_137 ++ ) {
F_11 ( 10 , 20 ) ;
V_249 = F_5 ( V_252 ) ;
if ( ( V_249 & V_253 ) &&
( V_249 & V_259 ) )
continue;
if ( V_249 & V_254 ) {
V_18 -> V_257 = false ;
V_18 -> V_195 =
V_196 ;
F_3 ( L_23 ) ;
break;
}
}
if ( V_137 == V_263 ) {
V_251 = F_5 ( V_260 ) ;
V_251 |= V_261 ;
F_6 ( V_260 , V_251 ) ;
V_18 -> V_195 =
V_256 ;
V_18 -> V_257 = false ;
F_3 ( L_24 ) ;
}
}
}
return V_5 ;
}
static T_1 F_60 ( struct V_1 * V_2 , T_3 * V_146 )
{
T_1 V_5 ;
V_5 = F_51 ( V_2 , V_264 , 1 , V_146 ) ;
if ( V_5 ) {
F_3 ( L_25 ) ;
return V_5 ;
}
switch ( V_2 -> V_18 . type ) {
case V_22 :
case V_24 :
case V_25 :
if ( * V_146 == V_265 )
* V_146 = V_266 ;
break;
default:
if ( * V_146 == V_267 ||
* V_146 == V_268 )
* V_146 = V_269 ;
break;
}
return 0 ;
}
bool F_43 ( struct V_1 * V_2 )
{
if ( V_2 -> V_18 . type != V_19 )
return false ;
return V_2 -> V_108 . V_109 . V_270 ;
}
void F_40 ( struct V_1 * V_2 , bool V_271 )
{
if ( V_2 -> V_18 . type != V_19 )
return;
V_2 -> V_108 . V_109 . V_270 = V_271 ;
if ( V_271 )
V_2 -> V_18 . V_13 . V_272 ( V_2 , V_2 -> V_18 . V_9 ,
V_2 -> V_18 . V_87 - 1 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = & V_2 -> V_41 ;
T_1 V_5 ;
T_3 V_146 ;
if ( V_41 -> type != V_53 )
return 0 ;
V_5 = F_51 ( V_2 , 0x10 , 1 , & V_146 ) ;
if ( V_5 )
return V_5 ;
if ( ! ( V_146 & 0x10 ) ) {
V_5 = F_51 ( V_2 , 0x23 , 1 , & V_146 ) ;
if ( V_5 )
return V_5 ;
if ( ! ( V_146 & 0x8000 ) ) {
V_146 |= 0x8000 ;
V_5 = F_61 ( V_2 , 0x23 , 1 , & V_146 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_62 ( V_2 ) ;
if ( V_5 )
return V_5 ;
}
}
return 0 ;
}
static T_1 F_63 ( struct V_1 * V_2 )
{
if ( V_2 -> V_18 . type == V_19 ) {
T_1 V_5 ;
V_5 = F_39 ( V_2 ) ;
if ( V_5 )
return V_5 ;
}
return F_64 ( V_2 ) ;
}
static void V_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_60 * V_18 = & V_2 -> V_18 ;
if ( ! V_4 -> V_13 . V_273 )
return;
if ( ! ( V_18 -> V_13 . V_92 ( V_2 ) || V_4 -> V_13 . V_273 ( V_2 ) ) )
F_65 ( V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_66 ( V_2 ) ;
F_5 ( V_274 ) ;
F_5 ( V_275 ) ;
F_5 ( V_276 ) ;
F_5 ( V_277 ) ;
F_5 ( V_278 ) ;
F_5 ( V_279 ) ;
F_5 ( V_280 ) ;
F_5 ( V_281 ) ;
F_5 ( V_282 ) ;
F_5 ( V_283 ) ;
F_5 ( V_284 ) ;
F_5 ( V_285 ) ;
F_5 ( V_286 ) ;
F_5 ( V_287 ) ;
F_5 ( V_288 ) ;
F_5 ( V_289 ) ;
F_5 ( V_290 ) ;
F_5 ( V_291 ) ;
F_5 ( V_292 ) ;
F_5 ( V_293 ) ;
F_5 ( V_294 ) ;
F_5 ( V_295 ) ;
F_5 ( V_296 ) ;
F_5 ( V_297 ) ;
F_5 ( V_298 ) ;
F_5 ( V_299 ) ;
F_5 ( V_300 ) ;
F_5 ( V_301 ) ;
F_5 ( V_302 ) ;
F_5 ( V_303 ) ;
}
