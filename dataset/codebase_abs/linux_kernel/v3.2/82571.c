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
static T_1 F_7 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = & V_61 -> V_2 ;
struct V_62 * V_18 = & V_2 -> V_18 ;
struct V_63 * V_64 = & V_18 -> V_13 ;
T_2 V_65 = 0 ;
T_2 V_66 = 0 ;
bool V_67 = false ;
switch ( V_61 -> V_68 -> V_69 ) {
case V_70 :
case V_71 :
case V_72 :
V_2 -> V_4 . V_6 = V_73 ;
break;
case V_74 :
case V_75 :
case V_76 :
case V_77 :
V_2 -> V_4 . V_6 = V_78 ;
break;
default:
V_2 -> V_4 . V_6 = V_7 ;
break;
}
V_18 -> V_79 = 128 ;
V_18 -> V_80 = V_81 ;
V_18 -> V_82 = true ;
switch ( V_2 -> V_4 . V_6 ) {
case V_7 :
V_64 -> V_83 = V_84 ;
V_64 -> V_85 = V_86 ;
V_64 -> V_87 = V_88 ;
break;
case V_73 :
V_64 -> V_83 =
V_89 ;
V_64 -> V_85 = V_90 ;
V_64 -> V_87 =
V_91 ;
break;
case V_78 :
V_64 -> V_83 =
V_89 ;
V_64 -> V_85 = V_92 ;
V_64 -> V_87 =
V_91 ;
break;
default:
return - V_93 ;
break;
}
switch ( V_2 -> V_18 . type ) {
case V_22 :
V_64 -> V_94 = V_95 ;
V_64 -> V_96 = V_97 ;
V_64 -> V_98 = V_99 ;
V_64 -> V_100 = V_101 ;
V_18 -> V_102 = true ;
V_18 -> V_103 =
( F_5 ( V_104 ) & V_105 )
? true : false ;
break;
case V_24 :
case V_25 :
V_64 -> V_94 = V_95 ;
V_64 -> V_96 = V_106 ;
V_64 -> V_98 = V_107 ;
break;
default:
V_64 -> V_96 = V_97 ;
V_64 -> V_98 = V_99 ;
V_64 -> V_100 = V_101 ;
V_18 -> V_102 = true ;
break;
}
switch ( V_2 -> V_18 . type ) {
case V_19 :
case V_20 :
V_66 = F_5 ( V_108 ) ;
if ( ! ( V_66 & V_109 ) ) {
F_6 ( V_108 ,
V_66 | V_109 ) ;
V_67 = true ;
} else
V_67 = false ;
break;
default:
V_67 = true ;
break;
}
if ( V_67 ) {
V_65 = F_5 ( V_110 ) ;
if ( V_65 & V_111 ) {
F_3 ( L_3 ) ;
}
F_6 ( V_110 , V_65 & ~ V_111 ) ;
}
V_2 -> V_112 . V_113 . V_114 = 0 ;
return 0 ;
}
static T_1 F_8 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = & V_61 -> V_2 ;
static int V_115 ;
struct V_116 * V_68 = V_61 -> V_68 ;
int V_117 = F_5 ( V_118 ) & V_119 ;
T_1 V_120 ;
V_120 = F_7 ( V_61 ) ;
if ( V_120 )
return V_120 ;
V_120 = F_4 ( V_2 ) ;
if ( V_120 )
return V_120 ;
V_120 = F_1 ( V_2 ) ;
if ( V_120 )
return V_120 ;
switch ( V_68 -> V_69 ) {
case V_121 :
case V_72 :
case V_122 :
case V_123 :
V_61 -> V_124 |= V_125 ;
if ( V_115 == 0 )
V_61 -> V_124 |= V_126 ;
V_115 ++ ;
if ( V_115 == 4 )
V_115 = 0 ;
break;
default:
break;
}
switch ( V_61 -> V_2 . V_18 . type ) {
case V_19 :
if ( ( ( V_68 -> V_69 == V_70 ) ||
( V_68 -> V_69 == V_74 ) ||
( V_68 -> V_69 == V_127 ) ) &&
( V_117 ) )
V_61 -> V_124 &= ~ V_128 ;
if ( V_61 -> V_124 & V_125 &&
( ! ( V_61 -> V_124 & V_126 ) ) )
V_61 -> V_124 &= ~ V_128 ;
if ( V_68 -> V_69 == V_77 )
V_61 -> V_124 &= ~ V_128 ;
break;
case V_22 :
if ( V_68 -> V_69 == V_129 ) {
V_61 -> V_124 |= V_130 ;
V_61 -> V_131 = V_132 ;
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
T_3 V_133 = 0 ;
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
V_5 = F_10 ( V_2 , V_134 , & V_133 ) ;
if ( V_5 )
return V_5 ;
V_4 -> V_36 = ( T_2 ) ( V_133 << 16 ) ;
F_11 ( 20 ) ;
V_5 = F_10 ( V_2 , V_135 , & V_133 ) ;
if ( V_5 )
return V_5 ;
V_4 -> V_36 |= ( T_2 ) ( V_133 ) ;
V_4 -> V_136 = ( T_2 ) ( V_133 & ~ V_137 ) ;
break;
default:
return - V_35 ;
break;
}
return 0 ;
}
static T_1 F_12 ( struct V_1 * V_2 )
{
T_2 V_65 ;
T_1 V_138 = V_2 -> V_41 . V_54 + 1 ;
T_1 V_139 = V_2 -> V_41 . V_54 + 1 ;
T_1 V_140 = 0 ;
if ( V_2 -> V_112 . V_113 . V_114 > 2 )
V_138 = 1 ;
while ( V_140 < V_138 ) {
V_65 = F_5 ( V_110 ) ;
if ( ! ( V_65 & V_111 ) )
break;
F_11 ( 50 ) ;
V_140 ++ ;
}
if ( V_140 == V_138 ) {
F_3 ( L_4 ) ;
V_2 -> V_112 . V_113 . V_114 ++ ;
}
for ( V_140 = 0 ; V_140 < V_139 ; V_140 ++ ) {
V_65 = F_5 ( V_110 ) ;
F_6 ( V_110 , V_65 | V_141 ) ;
if ( F_5 ( V_110 ) & V_141 )
break;
F_11 ( 50 ) ;
}
if ( V_140 == V_139 ) {
F_13 ( V_2 ) ;
F_3 ( L_5 ) ;
return - V_142 ;
}
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_2 V_65 ;
V_65 = F_5 ( V_110 ) ;
V_65 &= ~ ( V_111 | V_141 ) ;
F_6 ( V_110 , V_65 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 )
{
T_2 V_143 ;
T_1 V_5 = 0 ;
T_1 V_140 = 0 ;
V_143 = F_5 ( V_144 ) ;
V_143 |= V_145 ;
do {
F_6 ( V_144 , V_143 ) ;
V_143 = F_5 ( V_144 ) ;
if ( V_143 & V_145 )
break;
V_143 |= V_145 ;
F_15 ( 2000 , 4000 ) ;
V_140 ++ ;
} while ( V_140 < V_146 );
if ( V_140 == V_146 ) {
F_16 ( V_2 ) ;
F_3 ( L_6 ) ;
V_5 = - V_35 ;
goto V_147;
}
V_147:
return V_5 ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_2 V_143 ;
V_143 = F_5 ( V_144 ) ;
V_143 &= ~ V_145 ;
F_6 ( V_144 , V_143 ) ;
}
static T_1 V_28 ( struct V_1 * V_2 )
{
T_1 V_5 ;
F_17 ( & V_148 ) ;
V_5 = F_14 ( V_2 ) ;
if ( V_5 )
F_18 ( & V_148 ) ;
return V_5 ;
}
static void V_30 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
F_18 ( & V_148 ) ;
}
static T_1 V_32 ( struct V_1 * V_2 , bool V_149 )
{
T_3 V_150 = F_5 ( V_151 ) ;
if ( V_149 )
V_150 |= V_152 ;
else
V_150 &= ~ V_152 ;
F_6 ( V_151 , V_150 ) ;
return 0 ;
}
static T_1 V_34 ( struct V_1 * V_2 , bool V_149 )
{
T_3 V_150 = F_5 ( V_151 ) ;
if ( ! V_149 ) {
V_150 &= ~ V_153 ;
} else if ( ( V_2 -> V_4 . V_154 == V_155 ) ||
( V_2 -> V_4 . V_154 == V_156 ) ||
( V_2 -> V_4 . V_154 == V_157 ) ) {
V_150 |= V_153 ;
}
F_6 ( V_151 , V_150 ) ;
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
static T_1 F_23 ( struct V_1 * V_2 , T_3 V_158 , T_3 V_159 ,
T_3 * V_150 )
{
T_1 V_5 ;
switch ( V_2 -> V_18 . type ) {
case V_22 :
case V_24 :
case V_25 :
V_5 = F_24 ( V_2 , V_158 , V_159 , V_150 ) ;
break;
case V_19 :
case V_20 :
V_5 = F_25 ( V_2 , V_158 , V_159 , V_150 ) ;
break;
default:
V_5 = - V_142 ;
break;
}
return V_5 ;
}
static T_1 F_26 ( struct V_1 * V_2 )
{
T_2 V_42 ;
T_1 V_5 ;
T_3 V_140 ;
V_5 = F_27 ( V_2 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_41 . type != V_53 )
return V_5 ;
for ( V_140 = 0 ; V_140 < V_160 ; V_140 ++ ) {
F_15 ( 1000 , 2000 ) ;
if ( ( F_5 ( V_43 ) & V_161 ) == 0 )
break;
}
if ( V_140 == V_160 )
return - V_142 ;
if ( ( F_5 ( V_162 ) & 0xFF00 ) == V_163 ) {
F_6 ( V_164 , V_165 ) ;
F_28 () ;
F_6 ( V_164 , V_166 ) ;
}
V_42 = F_5 ( V_43 ) | V_161 ;
F_6 ( V_43 , V_42 ) ;
for ( V_140 = 0 ; V_140 < V_160 ; V_140 ++ ) {
F_15 ( 1000 , 2000 ) ;
if ( ( F_5 ( V_43 ) & V_161 ) == 0 )
break;
}
if ( V_140 == V_160 )
return - V_142 ;
return 0 ;
}
static T_1 F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 . type == V_53 )
F_30 ( V_2 ) ;
return F_31 ( V_2 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_3 V_158 ,
T_3 V_159 , T_3 * V_150 )
{
struct V_40 * V_41 = & V_2 -> V_41 ;
T_2 V_140 , V_167 = 0 ;
T_1 V_5 = 0 ;
if ( ( V_158 >= V_41 -> V_54 ) || ( V_159 > ( V_41 -> V_54 - V_158 ) ) ||
( V_159 == 0 ) ) {
F_3 ( L_7 ) ;
return - V_142 ;
}
for ( V_140 = 0 ; V_140 < V_159 ; V_140 ++ ) {
V_167 = ( V_150 [ V_140 ] << V_168 ) |
( ( V_158 + V_140 ) << V_169 ) |
V_170 ;
V_5 = F_32 ( V_2 , V_171 ) ;
if ( V_5 )
break;
F_6 ( V_172 , V_167 ) ;
V_5 = F_32 ( V_2 , V_171 ) ;
if ( V_5 )
break;
}
return V_5 ;
}
static T_1 F_33 ( struct V_1 * V_2 )
{
T_1 V_173 = V_174 ;
while ( V_173 ) {
if ( F_5 ( V_175 ) &
V_176 )
break;
F_15 ( 1000 , 2000 ) ;
V_173 -- ;
}
if ( ! V_173 ) {
F_3 ( L_8 ) ;
return - V_177 ;
}
return 0 ;
}
static T_1 F_34 ( struct V_1 * V_2 , bool V_149 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_5 ;
T_3 V_150 ;
V_5 = F_10 ( V_2 , V_178 , & V_150 ) ;
if ( V_5 )
return V_5 ;
if ( V_149 ) {
V_150 |= V_179 ;
V_5 = F_35 ( V_2 , V_178 , V_150 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_10 ( V_2 , V_180 , & V_150 ) ;
V_150 &= ~ V_181 ;
V_5 = F_35 ( V_2 , V_180 , V_150 ) ;
if ( V_5 )
return V_5 ;
} else {
V_150 &= ~ V_179 ;
V_5 = F_35 ( V_2 , V_178 , V_150 ) ;
if ( V_4 -> V_182 == V_183 ) {
V_5 = F_10 ( V_2 , V_180 ,
& V_150 ) ;
if ( V_5 )
return V_5 ;
V_150 |= V_181 ;
V_5 = F_35 ( V_2 , V_180 ,
V_150 ) ;
if ( V_5 )
return V_5 ;
} else if ( V_4 -> V_182 == V_184 ) {
V_5 = F_10 ( V_2 , V_180 ,
& V_150 ) ;
if ( V_5 )
return V_5 ;
V_150 &= ~ V_181 ;
V_5 = F_35 ( V_2 , V_180 ,
V_150 ) ;
if ( V_5 )
return V_5 ;
}
}
return 0 ;
}
static T_1 F_36 ( struct V_1 * V_2 )
{
T_2 V_185 , V_186 ;
T_1 V_5 ;
V_5 = F_37 ( V_2 ) ;
if ( V_5 )
F_3 ( L_9 ) ;
F_3 ( L_10 ) ;
F_6 ( V_187 , 0xffffffff ) ;
F_6 ( V_188 , 0 ) ;
F_6 ( V_189 , V_190 ) ;
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
V_185 = F_5 ( V_191 ) ;
F_3 ( L_12 ) ;
F_6 ( V_191 , V_185 | V_192 ) ;
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
V_186 = F_5 ( V_193 ) ;
V_186 |= V_194 ;
F_6 ( V_193 , V_186 ) ;
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
F_6 ( V_187 , 0xffffffff ) ;
F_5 ( V_195 ) ;
if ( V_2 -> V_18 . type == V_19 ) {
V_5 = F_40 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_41 ( V_2 , true ) ;
}
if ( V_2 -> V_4 . V_6 == V_78 )
V_2 -> V_18 . V_196 = V_197 ;
return 0 ;
}
static T_1 F_42 ( struct V_1 * V_2 )
{
struct V_62 * V_18 = & V_2 -> V_18 ;
T_2 V_198 ;
T_1 V_5 ;
T_3 V_140 , V_199 = V_18 -> V_80 ;
F_43 ( V_2 ) ;
V_5 = F_44 ( V_2 ) ;
if ( V_5 )
F_3 ( L_13 ) ;
F_3 ( L_14 ) ;
V_18 -> V_13 . V_200 ( V_2 ) ;
if ( F_45 ( V_2 ) )
V_199 -- ;
F_46 ( V_2 , V_199 ) ;
F_3 ( L_15 ) ;
for ( V_140 = 0 ; V_140 < V_18 -> V_79 ; V_140 ++ )
F_47 ( V_2 , V_201 , V_140 , 0 ) ;
V_5 = F_48 ( V_2 ) ;
V_198 = F_5 ( F_49 ( 0 ) ) ;
V_198 = ( V_198 & ~ V_202 ) |
V_203 |
V_204 ;
F_6 ( F_49 ( 0 ) , V_198 ) ;
switch ( V_18 -> type ) {
case V_22 :
F_50 ( V_2 ) ;
case V_24 :
case V_25 :
V_198 = F_5 ( V_205 ) ;
V_198 |= V_206 ;
F_6 ( V_205 , V_198 ) ;
break;
default:
V_198 = F_5 ( F_49 ( 1 ) ) ;
V_198 = ( V_198 & ~ V_202 ) |
V_203 |
V_204 ;
F_6 ( F_49 ( 1 ) , V_198 ) ;
break;
}
F_51 ( V_2 ) ;
return V_5 ;
}
static void F_43 ( struct V_1 * V_2 )
{
T_2 V_207 ;
V_207 = F_5 ( F_49 ( 0 ) ) ;
V_207 |= ( 1 << 22 ) ;
F_6 ( F_49 ( 0 ) , V_207 ) ;
V_207 = F_5 ( F_49 ( 1 ) ) ;
V_207 |= ( 1 << 22 ) ;
F_6 ( F_49 ( 1 ) , V_207 ) ;
V_207 = F_5 ( F_52 ( 0 ) ) ;
V_207 &= ~ ( 0xF << 27 ) ;
switch ( V_2 -> V_18 . type ) {
case V_19 :
case V_20 :
V_207 |= ( 1 << 23 ) | ( 1 << 24 ) | ( 1 << 25 ) | ( 1 << 26 ) ;
break;
default:
break;
}
F_6 ( F_52 ( 0 ) , V_207 ) ;
V_207 = F_5 ( F_52 ( 1 ) ) ;
switch ( V_2 -> V_18 . type ) {
case V_19 :
case V_20 :
V_207 &= ~ ( ( 1 << 29 ) | ( 1 << 30 ) ) ;
V_207 |= ( 1 << 22 ) | ( 1 << 24 ) | ( 1 << 25 ) | ( 1 << 26 ) ;
if ( F_5 ( V_189 ) & V_208 )
V_207 &= ~ ( 1 << 28 ) ;
else
V_207 |= ( 1 << 28 ) ;
F_6 ( F_52 ( 1 ) , V_207 ) ;
break;
default:
break;
}
switch ( V_2 -> V_18 . type ) {
case V_22 :
case V_24 :
case V_25 :
V_207 = F_5 ( V_191 ) ;
V_207 &= ~ ( 1 << 29 ) ;
F_6 ( V_191 , V_207 ) ;
break;
default:
break;
}
switch ( V_2 -> V_18 . type ) {
case V_22 :
case V_24 :
case V_25 :
V_207 = F_5 ( V_193 ) ;
V_207 &= ~ ( 1 << 23 ) ;
V_207 |= ( 1 << 22 ) ;
F_6 ( V_193 , V_207 ) ;
break;
default:
break;
}
if ( V_2 -> V_18 . type == V_19 ) {
V_207 = F_5 ( V_209 ) ;
V_207 |= V_210 ;
F_6 ( V_209 , V_207 ) ;
}
if ( ( V_2 -> V_18 . type == V_19 ) ||
( V_2 -> V_18 . type == V_20 ) ) {
V_207 = F_5 ( V_193 ) ;
V_207 &= ~ V_211 ;
F_6 ( V_193 , V_207 ) ;
}
switch ( V_2 -> V_18 . type ) {
case V_24 :
case V_25 :
V_207 = F_5 ( V_205 ) ;
V_207 |= ( 1 << 22 ) ;
F_6 ( V_205 , V_207 ) ;
V_207 = F_5 ( V_212 ) ;
V_207 |= 1 ;
F_6 ( V_212 , V_207 ) ;
break;
default:
break;
}
}
static void F_53 ( struct V_1 * V_2 )
{
T_2 V_158 ;
T_2 V_213 = 0 ;
T_2 V_214 = 0 ;
T_2 V_215 = 0 ;
switch ( V_2 -> V_18 . type ) {
case V_22 :
case V_24 :
case V_25 :
if ( V_2 -> V_216 . V_217 != 0 ) {
V_214 = ( V_2 -> V_216 . V_217 >>
V_218 ) &
V_219 ;
V_215 = 1 << ( V_2 -> V_216 . V_217 &
V_220 ) ;
}
break;
default:
break;
}
for ( V_158 = 0 ; V_158 < V_221 ; V_158 ++ ) {
V_213 = ( V_158 == V_214 ) ? V_215 : 0 ;
F_47 ( V_2 , V_222 , V_158 , V_213 ) ;
F_28 () ;
}
}
static bool V_106 ( struct V_1 * V_2 )
{
T_3 V_150 ;
F_54 ( V_2 , V_223 , 1 , & V_150 ) ;
return ( V_150 & V_224 ) != 0 ;
}
static T_1 V_107 ( struct V_1 * V_2 )
{
T_2 V_185 ;
T_2 V_140 ;
V_185 = V_2 -> V_18 . V_225 ;
if ( ! ( V_226 & F_5 ( V_118 ) ) ) {
for ( V_140 = 0 ; V_140 < 4 ; V_140 ++ )
if ( ( ( V_2 -> V_18 . V_225 >> ( V_140 * 8 ) ) & 0xFF ) ==
V_227 )
V_185 |= ( V_228 << ( V_140 * 8 ) ) ;
}
F_6 ( V_229 , V_185 ) ;
return 0 ;
}
bool F_55 ( struct V_1 * V_2 )
{
T_3 V_230 = 0 ;
T_3 V_231 = 0 ;
bool V_232 = false ;
T_1 V_5 = 0 ;
V_5 = F_10 ( V_2 , V_233 , & V_231 ) ;
if ( V_5 )
goto V_147;
if ( V_231 == V_234 ) {
V_5 = F_10 ( V_2 , V_235 , & V_230 ) ;
if ( V_5 )
goto V_147;
if ( ( V_230 & V_236 ) ==
V_236 )
V_232 = true ;
}
V_147:
return V_232 ;
}
static T_1 F_48 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_18 . type ) {
case V_22 :
case V_24 :
case V_25 :
if ( V_2 -> V_237 . V_238 == V_239 )
V_2 -> V_237 . V_238 = V_240 ;
break;
default:
break;
}
return F_56 ( V_2 ) ;
}
static T_1 V_84 ( struct V_1 * V_2 )
{
T_2 V_185 ;
T_1 V_5 ;
V_185 = F_5 ( V_191 ) ;
V_185 |= V_241 ;
V_185 &= ~ ( V_242 | V_243 ) ;
F_6 ( V_191 , V_185 ) ;
switch ( V_2 -> V_4 . type ) {
case V_23 :
case V_26 :
V_5 = F_57 ( V_2 ) ;
break;
case V_21 :
V_5 = F_58 ( V_2 ) ;
break;
default:
return - V_35 ;
break;
}
if ( V_5 )
return V_5 ;
V_5 = F_59 ( V_2 ) ;
return V_5 ;
}
static T_1 V_89 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_18 . type ) {
case V_19 :
case V_20 :
F_6 ( V_244 , V_245 ) ;
break;
default:
break;
}
return F_60 ( V_2 ) ;
}
static T_1 V_92 ( struct V_1 * V_2 )
{
struct V_62 * V_18 = & V_2 -> V_18 ;
T_2 V_246 ;
T_2 V_185 ;
T_2 V_247 ;
T_2 V_248 ;
T_2 V_140 ;
T_1 V_5 = 0 ;
V_185 = F_5 ( V_191 ) ;
V_247 = F_5 ( V_118 ) ;
V_246 = F_5 ( V_249 ) ;
if ( ( V_246 & V_250 ) && ! ( V_246 & V_251 ) ) {
switch ( V_18 -> V_196 ) {
case V_252 :
if ( ! ( V_247 & V_226 ) ) {
V_18 -> V_196 =
V_253 ;
V_18 -> V_254 = false ;
F_3 ( L_16 ) ;
} else {
V_18 -> V_254 = true ;
}
break;
case V_255 :
if ( ( V_246 & V_256 ) || ! ( V_246 & V_257 ) ) {
F_6 ( V_258 , V_18 -> V_248 ) ;
F_6 ( V_191 , ( V_185 & ~ V_241 ) ) ;
V_18 -> V_196 =
V_253 ;
V_18 -> V_254 = false ;
F_3 ( L_17 ) ;
} else {
V_18 -> V_254 = true ;
}
break;
case V_253 :
if ( V_246 & V_256 ) {
if ( V_247 & V_226 ) {
V_18 -> V_196 =
V_252 ;
F_3 ( L_18 ) ;
V_18 -> V_254 = true ;
} else {
V_18 -> V_196 =
V_197 ;
F_3 ( L_19 ) ;
}
} else {
F_6 ( V_258 , ( V_18 -> V_248 & ~ V_259 ) ) ;
V_185 |= ( V_241 | V_260 ) ;
F_6 ( V_191 , V_185 ) ;
V_5 = F_61 ( V_2 ) ;
if ( V_5 ) {
F_3 ( L_20 ) ;
break;
}
V_18 -> V_196 =
V_255 ;
V_18 -> V_254 = true ;
F_3 ( L_21 ) ;
}
break;
case V_197 :
default:
F_6 ( V_258 , V_18 -> V_248 ) ;
F_6 ( V_191 , ( V_185 & ~ V_241 ) ) ;
V_18 -> V_196 =
V_253 ;
V_18 -> V_254 = false ;
F_3 ( L_22 ) ;
break;
}
} else {
if ( ! ( V_246 & V_250 ) ) {
V_18 -> V_254 = false ;
V_18 -> V_196 = V_197 ;
F_3 ( L_23 ) ;
} else {
for ( V_140 = 0 ; V_140 < V_261 ; V_140 ++ ) {
F_11 ( 10 ) ;
V_246 = F_5 ( V_249 ) ;
if ( ( V_246 & V_251 ) &&
! ( ( V_246 & V_250 ) &&
( V_246 & V_256 ) ) ) {
V_18 -> V_254 = false ;
V_18 -> V_196 =
V_197 ;
F_3 ( L_23 ) ;
break;
}
}
if ( V_140 == V_261 ) {
V_248 = F_5 ( V_258 ) ;
V_248 |= V_259 ;
F_6 ( V_258 , V_248 ) ;
V_18 -> V_196 =
V_253 ;
V_18 -> V_254 = false ;
F_3 ( L_24 ) ;
}
}
}
return V_5 ;
}
static T_1 F_62 ( struct V_1 * V_2 , T_3 * V_150 )
{
T_1 V_5 ;
V_5 = F_54 ( V_2 , V_262 , 1 , V_150 ) ;
if ( V_5 ) {
F_3 ( L_25 ) ;
return V_5 ;
}
switch ( V_2 -> V_18 . type ) {
case V_22 :
case V_24 :
case V_25 :
if ( * V_150 == V_263 )
* V_150 = V_264 ;
break;
default:
if ( * V_150 == V_265 ||
* V_150 == V_266 )
* V_150 = V_267 ;
break;
}
return 0 ;
}
bool F_45 ( struct V_1 * V_2 )
{
if ( V_2 -> V_18 . type != V_19 )
return false ;
return V_2 -> V_112 . V_113 . V_268 ;
}
void F_41 ( struct V_1 * V_2 , bool V_269 )
{
if ( V_2 -> V_18 . type != V_19 )
return;
V_2 -> V_112 . V_113 . V_268 = V_269 ;
if ( V_269 )
F_63 ( V_2 , V_2 -> V_18 . V_9 , V_2 -> V_18 . V_80 - 1 ) ;
}
static T_1 F_30 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = & V_2 -> V_41 ;
T_1 V_5 ;
T_3 V_150 ;
if ( V_41 -> type != V_53 )
return 0 ;
V_5 = F_54 ( V_2 , 0x10 , 1 , & V_150 ) ;
if ( V_5 )
return V_5 ;
if ( ! ( V_150 & 0x10 ) ) {
V_5 = F_54 ( V_2 , 0x23 , 1 , & V_150 ) ;
if ( V_5 )
return V_5 ;
if ( ! ( V_150 & 0x8000 ) ) {
V_150 |= 0x8000 ;
V_5 = F_64 ( V_2 , 0x23 , 1 , & V_150 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_65 ( V_2 ) ;
}
}
return 0 ;
}
static T_1 F_66 ( struct V_1 * V_2 )
{
T_1 V_5 = 0 ;
if ( V_2 -> V_18 . type == V_19 ) {
V_5 = F_40 ( V_2 ) ;
if ( V_5 )
goto V_147;
}
V_5 = F_67 ( V_2 ) ;
V_147:
return V_5 ;
}
static void V_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_62 * V_18 = & V_2 -> V_18 ;
if ( ! ( V_4 -> V_13 . V_270 ) )
return;
if ( ! ( V_18 -> V_13 . V_96 ( V_2 ) || V_4 -> V_13 . V_270 ( V_2 ) ) )
F_68 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_69 ( V_2 ) ;
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
F_5 ( V_298 ) ;
F_5 ( V_299 ) ;
F_5 ( V_300 ) ;
}
