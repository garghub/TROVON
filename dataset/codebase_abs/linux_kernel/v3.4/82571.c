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
V_18 -> V_99 =
( F_5 ( V_100 ) & V_101 )
? true : false ;
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
F_11 ( 20 ) ;
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
F_11 ( 50 ) ;
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
F_11 ( 50 ) ;
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
V_140 |= V_142 ;
do {
F_6 ( V_141 , V_140 ) ;
V_140 = F_5 ( V_141 ) ;
if ( V_140 & V_142 )
break;
V_140 |= V_142 ;
F_15 ( 2000 , 4000 ) ;
V_137 ++ ;
} while ( V_137 < V_143 );
if ( V_137 == V_143 ) {
F_16 ( V_2 ) ;
F_3 ( L_6 ) ;
return - V_35 ;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_2 V_140 ;
V_140 = F_5 ( V_141 ) ;
V_140 &= ~ V_142 ;
F_6 ( V_141 , V_140 ) ;
}
static T_1 V_28 ( struct V_1 * V_2 )
{
T_1 V_5 ;
F_17 ( & V_144 ) ;
V_5 = F_14 ( V_2 ) ;
if ( V_5 )
F_18 ( & V_144 ) ;
return V_5 ;
}
static void V_30 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
F_18 ( & V_144 ) ;
}
static T_1 V_32 ( struct V_1 * V_2 , bool V_145 )
{
T_3 V_146 = F_5 ( V_147 ) ;
if ( V_145 )
V_146 |= V_148 ;
else
V_146 &= ~ V_148 ;
F_6 ( V_147 , V_146 ) ;
return 0 ;
}
static T_1 V_34 ( struct V_1 * V_2 , bool V_145 )
{
T_3 V_146 = F_5 ( V_147 ) ;
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
static T_1 F_19 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_12 ( V_2 ) ;
if ( V_5 )
return V_5 ;
switch ( V_2 -> V_18 . type ) {
case V_22 :
break;
default:
V_5 = F_20 ( V_2 ) ;
break;
}
if ( V_5 )
F_13 ( V_2 ) ;
return V_5 ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_13 ( V_2 ) ;
}
static T_1 F_23 ( struct V_1 * V_2 , T_3 V_154 , T_3 V_155 ,
T_3 * V_146 )
{
T_1 V_5 ;
switch ( V_2 -> V_18 . type ) {
case V_22 :
case V_24 :
case V_25 :
V_5 = F_24 ( V_2 , V_154 , V_155 , V_146 ) ;
break;
case V_19 :
case V_20 :
V_5 = F_25 ( V_2 , V_154 , V_155 , V_146 ) ;
break;
default:
V_5 = - V_139 ;
break;
}
return V_5 ;
}
static T_1 F_26 ( struct V_1 * V_2 )
{
T_2 V_42 ;
T_1 V_5 ;
T_3 V_137 ;
V_5 = F_27 ( V_2 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_41 . type != V_53 )
return 0 ;
for ( V_137 = 0 ; V_137 < V_156 ; V_137 ++ ) {
F_15 ( 1000 , 2000 ) ;
if ( ( F_5 ( V_43 ) & V_157 ) == 0 )
break;
}
if ( V_137 == V_156 )
return - V_139 ;
if ( ( F_5 ( V_158 ) & 0xFF00 ) == V_159 ) {
F_6 ( V_160 , V_161 ) ;
F_28 () ;
F_6 ( V_160 , V_162 ) ;
}
V_42 = F_5 ( V_43 ) | V_157 ;
F_6 ( V_43 , V_42 ) ;
for ( V_137 = 0 ; V_137 < V_156 ; V_137 ++ ) {
F_15 ( 1000 , 2000 ) ;
if ( ( F_5 ( V_43 ) & V_157 ) == 0 )
break;
}
if ( V_137 == V_156 )
return - V_139 ;
return 0 ;
}
static T_1 F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 . type == V_53 )
F_30 ( V_2 ) ;
return F_31 ( V_2 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_3 V_154 ,
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
V_163 = ( V_146 [ V_137 ] << V_164 ) |
( ( V_154 + V_137 ) << V_165 ) |
V_166 ;
V_5 = F_32 ( V_2 , V_167 ) ;
if ( V_5 )
break;
F_6 ( V_168 , V_163 ) ;
V_5 = F_32 ( V_2 , V_167 ) ;
if ( V_5 )
break;
}
return V_5 ;
}
static T_1 F_33 ( struct V_1 * V_2 )
{
T_1 V_169 = V_170 ;
while ( V_169 ) {
if ( F_5 ( V_171 ) &
V_172 )
break;
F_15 ( 1000 , 2000 ) ;
V_169 -- ;
}
if ( ! V_169 ) {
F_3 ( L_8 ) ;
return - V_173 ;
}
return 0 ;
}
static T_1 F_34 ( struct V_1 * V_2 , bool V_145 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_5 ;
T_3 V_146 ;
V_5 = F_10 ( V_2 , V_174 , & V_146 ) ;
if ( V_5 )
return V_5 ;
if ( V_145 ) {
V_146 |= V_175 ;
V_5 = F_35 ( V_2 , V_174 , V_146 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_10 ( V_2 , V_176 , & V_146 ) ;
V_146 &= ~ V_177 ;
V_5 = F_35 ( V_2 , V_176 , V_146 ) ;
if ( V_5 )
return V_5 ;
} else {
V_146 &= ~ V_175 ;
V_5 = F_35 ( V_2 , V_174 , V_146 ) ;
if ( V_4 -> V_178 == V_179 ) {
V_5 = F_10 ( V_2 , V_176 ,
& V_146 ) ;
if ( V_5 )
return V_5 ;
V_146 |= V_177 ;
V_5 = F_35 ( V_2 , V_176 ,
V_146 ) ;
if ( V_5 )
return V_5 ;
} else if ( V_4 -> V_178 == V_180 ) {
V_5 = F_10 ( V_2 , V_176 ,
& V_146 ) ;
if ( V_5 )
return V_5 ;
V_146 &= ~ V_177 ;
V_5 = F_35 ( V_2 , V_176 ,
V_146 ) ;
if ( V_5 )
return V_5 ;
}
}
return 0 ;
}
static T_1 F_36 ( struct V_1 * V_2 )
{
T_2 V_181 , V_182 ;
T_1 V_5 ;
V_5 = F_37 ( V_2 ) ;
if ( V_5 )
F_3 ( L_9 ) ;
F_3 ( L_10 ) ;
F_6 ( V_183 , 0xffffffff ) ;
F_6 ( V_184 , 0 ) ;
F_6 ( V_185 , V_186 ) ;
F_28 () ;
F_15 ( 10000 , 20000 ) ;
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
V_181 = F_5 ( V_187 ) ;
F_3 ( L_12 ) ;
F_6 ( V_187 , V_181 | V_188 ) ;
switch ( V_2 -> V_18 . type ) {
case V_24 :
case V_25 :
V_30 ( V_2 ) ;
break;
default:
break;
}
if ( V_2 -> V_41 . type == V_53 ) {
F_11 ( 10 ) ;
V_182 = F_5 ( V_189 ) ;
V_182 |= V_190 ;
F_6 ( V_189 , V_182 ) ;
F_28 () ;
}
V_5 = F_38 ( V_2 ) ;
if ( V_5 )
return V_5 ;
switch ( V_2 -> V_18 . type ) {
case V_22 :
case V_24 :
case V_25 :
F_39 ( 25 ) ;
break;
default:
break;
}
F_6 ( V_183 , 0xffffffff ) ;
F_5 ( V_191 ) ;
if ( V_2 -> V_18 . type == V_19 ) {
V_5 = F_40 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_41 ( V_2 , true ) ;
}
if ( V_2 -> V_4 . V_6 == V_81 )
V_2 -> V_18 . V_192 = V_193 ;
return 0 ;
}
static T_1 F_42 ( struct V_1 * V_2 )
{
struct V_60 * V_18 = & V_2 -> V_18 ;
T_2 V_194 ;
T_1 V_5 ;
T_3 V_137 , V_195 = V_18 -> V_87 ;
F_43 ( V_2 ) ;
V_5 = V_18 -> V_13 . V_196 ( V_2 ) ;
if ( V_5 )
F_3 ( L_13 ) ;
F_3 ( L_14 ) ;
V_18 -> V_13 . V_197 ( V_2 ) ;
if ( F_44 ( V_2 ) )
V_195 -- ;
F_45 ( V_2 , V_195 ) ;
F_3 ( L_15 ) ;
for ( V_137 = 0 ; V_137 < V_18 -> V_86 ; V_137 ++ )
F_46 ( V_2 , V_198 , V_137 , 0 ) ;
V_5 = V_18 -> V_13 . V_199 ( V_2 ) ;
V_194 = F_5 ( F_47 ( 0 ) ) ;
V_194 = ( V_194 & ~ V_200 ) |
V_201 |
V_202 ;
F_6 ( F_47 ( 0 ) , V_194 ) ;
switch ( V_18 -> type ) {
case V_22 :
F_48 ( V_2 ) ;
case V_24 :
case V_25 :
V_194 = F_5 ( V_203 ) ;
V_194 |= V_204 ;
F_6 ( V_203 , V_194 ) ;
break;
default:
V_194 = F_5 ( F_47 ( 1 ) ) ;
V_194 = ( V_194 & ~ V_200 ) |
V_201 |
V_202 ;
F_6 ( F_47 ( 1 ) , V_194 ) ;
break;
}
F_49 ( V_2 ) ;
return V_5 ;
}
static void F_43 ( struct V_1 * V_2 )
{
T_2 V_205 ;
V_205 = F_5 ( F_47 ( 0 ) ) ;
V_205 |= ( 1 << 22 ) ;
F_6 ( F_47 ( 0 ) , V_205 ) ;
V_205 = F_5 ( F_47 ( 1 ) ) ;
V_205 |= ( 1 << 22 ) ;
F_6 ( F_47 ( 1 ) , V_205 ) ;
V_205 = F_5 ( F_50 ( 0 ) ) ;
V_205 &= ~ ( 0xF << 27 ) ;
switch ( V_2 -> V_18 . type ) {
case V_19 :
case V_20 :
V_205 |= ( 1 << 23 ) | ( 1 << 24 ) | ( 1 << 25 ) | ( 1 << 26 ) ;
break;
case V_24 :
case V_25 :
V_205 |= ( 1 << 26 ) ;
break;
default:
break;
}
F_6 ( F_50 ( 0 ) , V_205 ) ;
V_205 = F_5 ( F_50 ( 1 ) ) ;
switch ( V_2 -> V_18 . type ) {
case V_19 :
case V_20 :
V_205 &= ~ ( ( 1 << 29 ) | ( 1 << 30 ) ) ;
V_205 |= ( 1 << 22 ) | ( 1 << 24 ) | ( 1 << 25 ) | ( 1 << 26 ) ;
if ( F_5 ( V_185 ) & V_206 )
V_205 &= ~ ( 1 << 28 ) ;
else
V_205 |= ( 1 << 28 ) ;
F_6 ( F_50 ( 1 ) , V_205 ) ;
break;
default:
break;
}
switch ( V_2 -> V_18 . type ) {
case V_22 :
case V_24 :
case V_25 :
V_205 = F_5 ( V_187 ) ;
V_205 &= ~ ( 1 << 29 ) ;
F_6 ( V_187 , V_205 ) ;
break;
default:
break;
}
switch ( V_2 -> V_18 . type ) {
case V_22 :
case V_24 :
case V_25 :
V_205 = F_5 ( V_189 ) ;
V_205 &= ~ ( 1 << 23 ) ;
V_205 |= ( 1 << 22 ) ;
F_6 ( V_189 , V_205 ) ;
break;
default:
break;
}
if ( V_2 -> V_18 . type == V_19 ) {
V_205 = F_5 ( V_207 ) ;
V_205 |= V_208 ;
F_6 ( V_207 , V_205 ) ;
}
if ( ( V_2 -> V_18 . type == V_19 ) || ( V_2 -> V_18 . type == V_20 ) ) {
V_205 = F_5 ( V_189 ) ;
V_205 &= ~ V_209 ;
F_6 ( V_189 , V_205 ) ;
}
switch ( V_2 -> V_18 . type ) {
case V_24 :
case V_25 :
V_205 = F_5 ( V_203 ) ;
V_205 |= ( 1 << 22 ) ;
F_6 ( V_203 , V_205 ) ;
V_205 = F_5 ( V_210 ) ;
V_205 |= 1 ;
F_6 ( V_210 , V_205 ) ;
break;
default:
break;
}
}
static void F_51 ( struct V_1 * V_2 )
{
T_2 V_154 ;
T_2 V_211 = 0 ;
T_2 V_212 = 0 ;
T_2 V_213 = 0 ;
switch ( V_2 -> V_18 . type ) {
case V_22 :
case V_24 :
case V_25 :
if ( V_2 -> V_214 . V_215 != 0 ) {
V_212 = ( V_2 -> V_214 . V_215 >>
V_216 ) &
V_217 ;
V_213 = 1 << ( V_2 -> V_214 . V_215 &
V_218 ) ;
}
break;
default:
break;
}
for ( V_154 = 0 ; V_154 < V_219 ; V_154 ++ ) {
V_211 = ( V_154 == V_212 ) ? V_213 : 0 ;
F_46 ( V_2 , V_220 , V_154 , V_211 ) ;
F_28 () ;
}
}
static bool V_102 ( struct V_1 * V_2 )
{
T_3 V_146 ;
F_52 ( V_2 , V_221 , 1 , & V_146 ) ;
return ( V_146 & V_222 ) != 0 ;
}
static T_1 V_103 ( struct V_1 * V_2 )
{
T_2 V_181 ;
T_2 V_137 ;
V_181 = V_2 -> V_18 . V_223 ;
if ( ! ( V_224 & F_5 ( V_115 ) ) ) {
for ( V_137 = 0 ; V_137 < 4 ; V_137 ++ )
if ( ( ( V_2 -> V_18 . V_223 >> ( V_137 * 8 ) ) & 0xFF ) ==
V_225 )
V_181 |= ( V_226 << ( V_137 * 8 ) ) ;
}
F_6 ( V_227 , V_181 ) ;
return 0 ;
}
bool F_53 ( struct V_1 * V_2 )
{
T_3 V_228 = 0 ;
T_3 V_229 = 0 ;
T_1 V_5 = 0 ;
V_5 = F_10 ( V_2 , V_230 , & V_229 ) ;
if ( V_5 )
return false ;
if ( V_229 == V_231 ) {
V_5 = F_10 ( V_2 , V_232 , & V_228 ) ;
if ( V_5 )
return false ;
if ( ( V_228 & V_233 ) ==
V_233 )
return true ;
}
return false ;
}
static T_1 F_54 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_18 . type ) {
case V_22 :
case V_24 :
case V_25 :
if ( V_2 -> V_234 . V_235 == V_236 )
V_2 -> V_234 . V_235 = V_237 ;
break;
default:
break;
}
return F_55 ( V_2 ) ;
}
static T_1 V_83 ( struct V_1 * V_2 )
{
T_2 V_181 ;
T_1 V_5 ;
V_181 = F_5 ( V_187 ) ;
V_181 |= V_238 ;
V_181 &= ~ ( V_239 | V_240 ) ;
F_6 ( V_187 , V_181 ) ;
switch ( V_2 -> V_4 . type ) {
case V_23 :
case V_26 :
V_5 = F_56 ( V_2 ) ;
break;
case V_21 :
V_5 = F_57 ( V_2 ) ;
break;
default:
return - V_35 ;
break;
}
if ( V_5 )
return V_5 ;
return F_58 ( V_2 ) ;
}
static T_1 V_72 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_18 . type ) {
case V_19 :
case V_20 :
F_6 ( V_241 , V_242 ) ;
break;
default:
break;
}
return F_59 ( V_2 ) ;
}
static T_1 V_82 ( struct V_1 * V_2 )
{
struct V_60 * V_18 = & V_2 -> V_18 ;
T_2 V_243 ;
T_2 V_181 ;
T_2 V_244 ;
T_2 V_245 ;
T_2 V_137 ;
T_1 V_5 = 0 ;
V_181 = F_5 ( V_187 ) ;
V_244 = F_5 ( V_115 ) ;
V_243 = F_5 ( V_246 ) ;
if ( ( V_243 & V_247 ) && ! ( V_243 & V_248 ) ) {
switch ( V_18 -> V_192 ) {
case V_249 :
if ( ! ( V_244 & V_224 ) ) {
V_18 -> V_192 =
V_250 ;
V_18 -> V_251 = false ;
F_3 ( L_16 ) ;
} else {
V_18 -> V_251 = true ;
}
break;
case V_252 :
if ( ( V_243 & V_253 ) || ! ( V_243 & V_254 ) ) {
F_6 ( V_255 , V_18 -> V_245 ) ;
F_6 ( V_187 , ( V_181 & ~ V_238 ) ) ;
V_18 -> V_192 =
V_250 ;
V_18 -> V_251 = false ;
F_3 ( L_17 ) ;
} else {
V_18 -> V_251 = true ;
}
break;
case V_250 :
if ( V_243 & V_253 ) {
if ( V_244 & V_224 ) {
V_18 -> V_192 =
V_249 ;
F_3 ( L_18 ) ;
V_18 -> V_251 = true ;
} else {
V_18 -> V_192 =
V_193 ;
F_3 ( L_19 ) ;
}
} else {
F_6 ( V_255 , ( V_18 -> V_245 & ~ V_256 ) ) ;
V_181 |= ( V_238 | V_257 ) ;
F_6 ( V_187 , V_181 ) ;
V_5 = F_60 ( V_2 ) ;
if ( V_5 ) {
F_3 ( L_20 ) ;
break;
}
V_18 -> V_192 =
V_252 ;
V_18 -> V_251 = true ;
F_3 ( L_21 ) ;
}
break;
case V_193 :
default:
F_6 ( V_255 , V_18 -> V_245 ) ;
F_6 ( V_187 , ( V_181 & ~ V_238 ) ) ;
V_18 -> V_192 =
V_250 ;
V_18 -> V_251 = false ;
F_3 ( L_22 ) ;
break;
}
} else {
if ( ! ( V_243 & V_247 ) ) {
V_18 -> V_251 = false ;
V_18 -> V_192 = V_193 ;
F_3 ( L_23 ) ;
} else {
for ( V_137 = 0 ; V_137 < V_258 ; V_137 ++ ) {
F_11 ( 10 ) ;
V_243 = F_5 ( V_246 ) ;
if ( ( V_243 & V_248 ) &&
! ( ( V_243 & V_247 ) &&
( V_243 & V_253 ) ) ) {
V_18 -> V_251 = false ;
V_18 -> V_192 =
V_193 ;
F_3 ( L_23 ) ;
break;
}
}
if ( V_137 == V_258 ) {
V_245 = F_5 ( V_255 ) ;
V_245 |= V_256 ;
F_6 ( V_255 , V_245 ) ;
V_18 -> V_192 =
V_250 ;
V_18 -> V_251 = false ;
F_3 ( L_24 ) ;
}
}
}
return V_5 ;
}
static T_1 F_61 ( struct V_1 * V_2 , T_3 * V_146 )
{
T_1 V_5 ;
V_5 = F_52 ( V_2 , V_259 , 1 , V_146 ) ;
if ( V_5 ) {
F_3 ( L_25 ) ;
return V_5 ;
}
switch ( V_2 -> V_18 . type ) {
case V_22 :
case V_24 :
case V_25 :
if ( * V_146 == V_260 )
* V_146 = V_261 ;
break;
default:
if ( * V_146 == V_262 ||
* V_146 == V_263 )
* V_146 = V_264 ;
break;
}
return 0 ;
}
bool F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_18 . type != V_19 )
return false ;
return V_2 -> V_108 . V_109 . V_265 ;
}
void F_41 ( struct V_1 * V_2 , bool V_266 )
{
if ( V_2 -> V_18 . type != V_19 )
return;
V_2 -> V_108 . V_109 . V_265 = V_266 ;
if ( V_266 )
F_62 ( V_2 , V_2 -> V_18 . V_9 , V_2 -> V_18 . V_87 - 1 ) ;
}
static T_1 F_30 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = & V_2 -> V_41 ;
T_1 V_5 ;
T_3 V_146 ;
if ( V_41 -> type != V_53 )
return 0 ;
V_5 = F_52 ( V_2 , 0x10 , 1 , & V_146 ) ;
if ( V_5 )
return V_5 ;
if ( ! ( V_146 & 0x10 ) ) {
V_5 = F_52 ( V_2 , 0x23 , 1 , & V_146 ) ;
if ( V_5 )
return V_5 ;
if ( ! ( V_146 & 0x8000 ) ) {
V_146 |= 0x8000 ;
V_5 = F_63 ( V_2 , 0x23 , 1 , & V_146 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_64 ( V_2 ) ;
}
}
return 0 ;
}
static T_1 F_65 ( struct V_1 * V_2 )
{
if ( V_2 -> V_18 . type == V_19 ) {
T_1 V_5 = 0 ;
V_5 = F_40 ( V_2 ) ;
if ( V_5 )
return V_5 ;
}
return F_66 ( V_2 ) ;
}
static void V_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_60 * V_18 = & V_2 -> V_18 ;
if ( ! V_4 -> V_13 . V_267 )
return;
if ( ! ( V_18 -> V_13 . V_92 ( V_2 ) || V_4 -> V_13 . V_267 ( V_2 ) ) )
F_67 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_68 ( V_2 ) ;
F_5 ( V_268 ) ;
F_5 ( V_269 ) ;
F_5 ( V_270 ) ;
F_5 ( V_271 ) ;
F_5 ( V_272 ) ;
F_5 ( V_273 ) ;
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
}
