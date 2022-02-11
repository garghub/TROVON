int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 ;
V_7 -> V_10 = L_1 ;
V_7 -> V_11 = V_12 |
V_13 |
V_14 |
V_15 |
V_16 ;
V_7 -> V_11 |= V_17 |
V_18 ;
if ( F_2 ( V_2 ) . V_19 & V_20 )
V_7 -> V_11 |= V_21 |
V_22 ;
#ifndef F_3
if ( V_4 -> V_11 & V_23 )
#endif
V_7 -> V_11 |= V_24 ;
V_7 -> V_25 = sizeof( struct V_26 ) ;
V_7 -> V_27 = sizeof( struct V_28 ) ;
F_4 (priv, ctx) {
V_7 -> V_29 -> V_30 |= V_9 -> V_30 ;
V_7 -> V_29 -> V_30 |= V_9 -> V_31 ;
}
F_5 ( V_32 != 2 ) ;
if ( V_7 -> V_29 -> V_30 & F_6 ( V_33 ) ) {
V_7 -> V_29 -> V_34 = V_35 ;
V_7 -> V_29 -> V_36 =
F_7 ( V_35 ) ;
} else if ( V_7 -> V_29 -> V_30 & F_6 ( V_37 ) ) {
V_7 -> V_29 -> V_34 =
V_38 ;
V_7 -> V_29 -> V_36 =
F_7 ( V_38 ) ;
}
V_7 -> V_29 -> V_39 = 1000 ;
V_7 -> V_29 -> V_11 |= V_40 |
V_41 |
V_42 ;
if ( V_2 -> V_43 -> V_44 [ V_45 ] . V_46 [ 0 ] . V_47 &&
F_8 ( V_2 ) -> V_48 -> V_49 &&
F_9 ( F_8 ( V_2 ) -> V_50 ) ) {
V_7 -> V_29 -> V_51 . V_11 = V_52 |
V_53 |
V_54 |
V_55 ;
if ( ! V_56 . V_57 )
V_7 -> V_29 -> V_51 . V_11 |=
V_58 |
V_59 ;
V_7 -> V_29 -> V_51 . V_60 = V_61 ;
V_7 -> V_29 -> V_51 . V_62 =
V_63 ;
V_7 -> V_29 -> V_51 . V_64 =
V_65 ;
}
if ( V_56 . V_66 )
V_7 -> V_29 -> V_11 |= V_67 ;
else
V_7 -> V_29 -> V_11 &= ~ V_67 ;
V_7 -> V_29 -> V_68 = V_69 ;
V_7 -> V_29 -> V_70 = V_4 -> V_71 - 24 - 2 ;
V_7 -> V_72 = 4 ;
V_7 -> V_73 = V_74 ;
if ( V_2 -> V_75 [ V_76 ] . V_77 )
V_2 -> V_7 -> V_29 -> V_75 [ V_76 ] =
& V_2 -> V_75 [ V_76 ] ;
if ( V_2 -> V_75 [ V_78 ] . V_77 )
V_2 -> V_7 -> V_29 -> V_75 [ V_78 ] =
& V_2 -> V_75 [ V_78 ] ;
V_7 -> V_29 -> V_79 = F_8 ( V_2 ) -> V_80 ;
F_10 ( V_2 ) ;
V_5 = F_11 ( V_2 -> V_7 ) ;
if ( V_5 ) {
F_12 ( V_2 , L_2 , V_5 ) ;
return V_5 ;
}
V_2 -> V_81 = 1 ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_81 )
return;
F_14 ( V_2 ) ;
F_15 ( V_2 -> V_7 ) ;
V_2 -> V_81 = 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
int V_5 ;
F_17 ( & V_2 -> V_82 ) ;
if ( F_18 ( V_83 , & V_2 -> V_84 ) ) {
F_19 ( V_2 , L_3 ) ;
return - V_85 ;
}
F_4 (priv, ctx) {
V_5 = F_20 ( V_2 , V_9 ) ;
if ( V_5 ) {
F_21 ( V_2 ) ;
return V_5 ;
}
}
V_5 = F_22 ( V_2 ) ;
if ( V_5 ) {
F_12 ( V_2 , L_4 , V_5 ) ;
goto error;
}
V_5 = F_23 ( V_2 , V_86 ) ;
if ( V_5 ) {
F_12 ( V_2 , L_5 , V_5 ) ;
goto error;
}
V_5 = F_24 ( V_2 ) ;
if ( V_5 )
goto error;
return 0 ;
error:
F_25 ( V_83 , & V_2 -> V_84 ) ;
F_26 ( V_2 ) ;
F_27 ( V_83 , & V_2 -> V_84 ) ;
F_12 ( V_2 , L_6 ) ;
return V_5 ;
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
int V_5 ;
F_30 ( V_2 , L_7 ) ;
F_31 ( & V_2 -> V_82 ) ;
V_5 = F_16 ( V_2 ) ;
F_32 ( & V_2 -> V_82 ) ;
if ( V_5 )
return V_5 ;
F_33 ( V_2 , L_8 ) ;
if ( F_34 ( ! F_18 ( V_87 , & V_2 -> V_84 ) ) )
V_5 = - V_85 ;
F_35 ( V_2 ) ;
V_2 -> V_88 = 1 ;
F_30 ( V_2 , L_9 ) ;
return 0 ;
}
static void F_36 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
F_30 ( V_2 , L_7 ) ;
if ( ! V_2 -> V_88 )
return;
V_2 -> V_88 = 0 ;
F_31 ( & V_2 -> V_82 ) ;
F_26 ( V_2 ) ;
F_32 ( & V_2 -> V_82 ) ;
F_37 ( V_2 ) ;
F_38 ( V_2 -> V_89 ) ;
F_39 ( F_8 ( V_2 ) ) ;
F_30 ( V_2 , L_9 ) ;
}
static void F_40 ( struct V_6 * V_7 ,
struct V_90 * V_91 ,
struct V_92 * V_93 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
if ( V_56 . V_57 )
return;
F_30 ( V_2 , L_7 ) ;
F_31 ( & V_2 -> V_82 ) ;
if ( V_2 -> V_94 [ V_95 ] . V_91 != V_91 )
goto V_96;
memcpy ( V_2 -> V_97 , V_93 -> V_97 , V_98 ) ;
memcpy ( V_2 -> V_99 , V_93 -> V_99 , V_100 ) ;
V_2 -> V_101 =
F_41 ( F_42 ( ( V_102 * ) & V_93 -> V_101 ) ) ;
V_2 -> V_103 = true ;
V_96:
F_32 ( & V_2 -> V_82 ) ;
F_30 ( V_2 , L_9 ) ;
}
static int F_43 ( struct V_6 * V_7 ,
struct V_104 * V_51 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
struct V_8 * V_9 = & V_2 -> V_94 [ V_95 ] ;
int V_5 ;
if ( F_34 ( ! V_51 ) )
return - V_105 ;
F_30 ( V_2 , L_7 ) ;
F_31 ( & V_2 -> V_82 ) ;
if ( ! V_9 -> V_91 || V_9 -> V_91 -> type != V_106 ||
! F_44 ( V_9 ) ) {
V_5 = 1 ;
goto V_96;
}
V_5 = F_45 ( V_2 , V_51 ) ;
if ( V_5 )
goto error;
F_46 ( F_8 ( V_2 ) -> V_50 , true ) ;
F_47 ( F_8 ( V_2 ) ) ;
goto V_96;
error:
V_2 -> V_51 = false ;
F_48 ( V_2 ) ;
F_49 ( V_2 -> V_7 ) ;
V_96:
F_32 ( & V_2 -> V_82 ) ;
F_30 ( V_2 , L_9 ) ;
return V_5 ;
}
static int F_50 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
struct V_8 * V_9 = & V_2 -> V_94 [ V_95 ] ;
struct V_90 * V_91 ;
unsigned long V_11 ;
T_1 V_107 , V_84 = 0xffffffff ;
int V_5 = - V_85 ;
const struct V_108 * V_44 ;
F_30 ( V_2 , L_7 ) ;
F_31 ( & V_2 -> V_82 ) ;
F_51 ( F_8 ( V_2 ) , V_109 ,
V_110 ) ;
V_107 = V_2 -> V_111 -> V_112 . V_113 ;
if ( F_52 ( V_107 ) ) {
F_53 ( & F_8 ( V_2 ) -> V_114 , V_11 ) ;
V_5 = F_54 ( F_8 ( V_2 ) ) ;
if ( F_55 ( V_5 == 0 ) ) {
F_51 ( F_8 ( V_2 ) , V_115 , V_107 ) ;
V_84 = F_56 ( F_8 ( V_2 ) , V_116 ) ;
F_57 ( F_8 ( V_2 ) ) ;
}
F_58 ( & F_8 ( V_2 ) -> V_114 , V_11 ) ;
#ifdef F_59
if ( V_5 == 0 ) {
V_44 = & ( V_2 -> V_43 -> V_44 [ V_45 ] ) ;
if ( ! V_2 -> V_117 ) {
V_2 -> V_117 =
F_60 ( V_44 -> V_46 [ V_118 ] . V_47 ,
V_119 ) ;
}
if ( V_2 -> V_117 )
F_61 (
F_8 ( V_2 ) , 0x800000 ,
V_2 -> V_117 ,
V_44 -> V_46 [ V_118 ] . V_47 / 4 ) ;
}
#endif
}
V_91 = V_9 -> V_91 ;
V_2 -> V_51 = false ;
F_46 ( F_8 ( V_2 ) -> V_50 , false ) ;
F_48 ( V_2 ) ;
memset ( ( void * ) & V_9 -> V_120 , 0 , sizeof( V_9 -> V_120 ) ) ;
F_62 ( V_2 , V_9 ) ;
F_63 ( V_2 , V_9 ) ;
F_32 ( & V_2 -> V_82 ) ;
F_30 ( V_2 , L_9 ) ;
F_64 ( V_91 ) ;
return 1 ;
}
static void F_65 ( struct V_6 * V_7 , struct V_121 * V_122 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
F_66 ( V_2 , L_10 , V_122 -> V_47 ,
F_67 ( V_7 , F_68 ( V_122 ) ) -> V_123 ) ;
if ( F_69 ( V_2 , V_122 ) )
F_70 ( V_122 ) ;
}
static void F_71 ( struct V_6 * V_7 ,
struct V_90 * V_91 ,
struct V_124 * V_125 ,
struct V_126 * V_127 ,
T_1 V_128 , T_2 * V_129 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
F_72 ( V_2 , V_91 , V_125 , V_127 , V_128 , V_129 ) ;
}
static int F_73 ( struct V_6 * V_7 , enum V_130 V_131 ,
struct V_90 * V_91 ,
struct V_126 * V_127 ,
struct V_124 * V_132 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
struct V_28 * V_133 = ( void * ) V_91 -> V_134 ;
struct V_8 * V_9 = V_133 -> V_9 ;
int V_5 ;
bool V_135 = false ;
F_30 ( V_2 , L_7 ) ;
if ( V_56 . V_57 ) {
F_30 ( V_2 , L_11 ) ;
return - V_136 ;
}
switch ( V_132 -> V_137 ) {
case V_138 :
V_132 -> V_11 |= V_139 ;
case V_140 :
V_132 -> V_11 |= V_141 ;
break;
default:
break;
}
if ( V_91 -> type == V_142 &&
! ( V_132 -> V_11 & V_143 ) ) {
V_132 -> V_144 = V_145 ;
return 0 ;
}
if ( V_131 == V_146 && V_132 -> V_144 == V_145 )
return 0 ;
F_31 ( & V_2 -> V_82 ) ;
F_74 ( V_2 , 100 ) ;
F_5 ( V_145 == V_147 ) ;
if ( ( V_132 -> V_137 == V_148 ||
V_132 -> V_137 == V_149 ) && ! V_127 ) {
if ( V_131 == V_150 )
V_135 = ! V_9 -> V_151 ;
else
V_135 =
V_132 -> V_144 == V_147 ;
}
switch ( V_131 ) {
case V_150 :
if ( V_135 ) {
V_5 = F_75 ( V_2 , V_133 -> V_9 , V_132 ) ;
break;
}
V_5 = F_76 ( V_2 , V_133 -> V_9 , V_132 , V_127 ) ;
if ( V_5 ) {
V_5 = 0 ;
V_132 -> V_144 = V_145 ;
}
F_30 ( V_2 , L_12 ) ;
break;
case V_146 :
if ( V_135 )
V_5 = F_77 ( V_2 , V_9 , V_132 ) ;
else
V_5 = F_78 ( V_2 , V_9 , V_132 , V_127 ) ;
F_30 ( V_2 , L_13 ) ;
break;
default:
V_5 = - V_105 ;
}
F_32 ( & V_2 -> V_82 ) ;
F_30 ( V_2 , L_9 ) ;
return V_5 ;
}
static int F_79 ( struct V_6 * V_7 ,
struct V_90 * V_91 ,
enum V_152 V_153 ,
struct V_126 * V_127 , T_2 V_154 , T_2 * V_155 ,
T_3 V_156 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
int V_5 = - V_105 ;
struct V_26 * V_157 = ( void * ) V_127 -> V_134 ;
F_80 ( V_2 , L_14 ,
V_127 -> V_158 , V_154 ) ;
if ( ! ( F_2 ( V_2 ) . V_19 & V_20 ) )
return - V_159 ;
F_30 ( V_2 , L_7 ) ;
F_31 ( & V_2 -> V_82 ) ;
switch ( V_153 ) {
case V_160 :
if ( V_56 . V_161 & V_162 )
break;
F_80 ( V_2 , L_15 ) ;
V_5 = F_81 ( V_2 , V_127 , V_154 , * V_155 ) ;
break;
case V_163 :
F_80 ( V_2 , L_16 ) ;
V_5 = F_82 ( V_2 , V_127 , V_154 ) ;
break;
case V_164 :
if ( V_56 . V_161 & V_165 )
break;
F_80 ( V_2 , L_17 ) ;
V_5 = F_83 ( V_2 , V_91 , V_127 , V_154 , V_155 ) ;
break;
case V_166 :
F_80 ( V_2 , L_18 ) ;
V_5 = F_84 ( V_2 , V_91 , V_127 , V_154 ) ;
if ( ( V_5 == 0 ) && ( V_2 -> V_167 > 0 ) ) {
V_2 -> V_167 -- ;
F_80 ( V_2 , L_19 ,
V_2 -> V_167 ) ;
}
if ( ! V_2 -> V_167 &&
F_2 ( V_2 ) . V_168 ) {
V_157 -> V_169 . V_170 . V_171 . V_11 &=
~ V_172 ;
F_85 ( V_2 , F_86 ( V_91 ) ,
& V_157 -> V_169 . V_170 , V_173 , false ) ;
}
break;
case V_174 :
V_5 = F_87 ( V_2 , V_91 , V_127 , V_154 , V_156 ) ;
break;
}
F_32 ( & V_2 -> V_82 ) ;
F_30 ( V_2 , L_9 ) ;
return V_5 ;
}
static int F_88 ( struct V_6 * V_7 ,
struct V_90 * V_91 ,
struct V_126 * V_127 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
struct V_26 * V_157 = ( void * ) V_127 -> V_134 ;
struct V_28 * V_133 = ( void * ) V_91 -> V_134 ;
bool V_175 = V_91 -> type == V_106 ;
int V_5 ;
T_3 V_176 ;
F_33 ( V_2 , L_20 ,
V_127 -> V_158 ) ;
V_157 -> V_176 = V_177 ;
F_89 ( & V_157 -> V_178 , 0 ) ;
if ( V_91 -> type == V_37 )
V_157 -> V_179 = true ;
V_5 = F_90 ( V_2 , V_133 -> V_9 , V_127 -> V_158 ,
V_175 , V_127 , & V_176 ) ;
if ( V_5 ) {
F_12 ( V_2 , L_21 ,
V_127 -> V_158 , V_5 ) ;
return V_5 ;
}
V_157 -> V_176 = V_176 ;
return 0 ;
}
static int F_91 ( struct V_6 * V_7 ,
struct V_90 * V_91 ,
struct V_126 * V_127 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
struct V_26 * V_157 = ( void * ) V_127 -> V_134 ;
int V_5 ;
F_33 ( V_2 , L_22 , V_127 -> V_158 ) ;
if ( V_91 -> type == V_106 ) {
V_5 = 0 ;
F_92 ( V_2 , V_157 -> V_176 , V_127 -> V_158 ) ;
} else {
V_5 = F_93 ( V_2 , V_157 -> V_176 , V_127 -> V_158 ) ;
if ( V_5 )
F_94 ( V_2 ,
L_23 , V_127 -> V_158 ) ;
}
return V_5 ;
}
static int F_95 ( struct V_6 * V_7 ,
struct V_90 * V_91 ,
struct V_126 * V_127 ,
enum V_180 V_181 ,
enum V_180 V_182 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
struct V_28 * V_133 = ( void * ) V_91 -> V_134 ;
enum {
V_183 , V_184 , REMOVE , V_185 , V_186 ,
} V_187 = V_183 ;
int V_5 ;
F_30 ( V_2 , L_24 ,
V_127 -> V_158 , V_181 , V_182 ) ;
F_31 ( & V_2 -> V_82 ) ;
if ( V_91 -> type == V_106 ) {
if ( V_181 == V_188 &&
V_182 == V_189 )
V_187 = V_184 ;
else if ( V_181 == V_189 &&
V_182 == V_188 )
V_187 = REMOVE ;
else if ( V_181 == V_190 &&
V_182 == V_191 )
V_187 = V_185 ;
} else {
if ( V_181 == V_190 &&
V_182 == V_191 )
V_187 = V_186 ;
else if ( V_181 == V_191 &&
V_182 == V_190 )
V_187 = REMOVE ;
}
switch ( V_187 ) {
case V_184 :
V_5 = F_88 ( V_7 , V_91 , V_127 ) ;
break;
case REMOVE :
V_5 = F_91 ( V_7 , V_91 , V_127 ) ;
break;
case V_186 :
V_5 = F_88 ( V_7 , V_91 , V_127 ) ;
if ( V_5 )
break;
F_33 ( V_2 ,
L_25 ,
V_127 -> V_158 ) ;
F_96 ( V_2 , V_127 , F_97 ( V_127 ) ) ;
V_5 = 0 ;
break;
case V_185 :
V_5 = F_98 ( V_2 , V_133 -> V_9 , V_127 ) ;
if ( V_5 )
break;
F_33 ( V_2 ,
L_25 ,
V_127 -> V_158 ) ;
F_96 ( V_2 , V_127 , F_97 ( V_127 ) ) ;
V_5 = 0 ;
break;
default:
V_5 = 0 ;
break;
}
if ( F_99 ( V_2 ) )
V_5 = 0 ;
F_32 ( & V_2 -> V_82 ) ;
F_30 ( V_2 , L_9 ) ;
return V_5 ;
}
static void F_100 ( struct V_6 * V_7 ,
struct V_192 * V_193 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
const struct V_194 * V_195 ;
struct V_196 * V_197 = & V_7 -> V_197 ;
struct V_198 * V_199 = V_193 -> V_199 ;
struct V_200 * V_201 = & V_2 -> V_202 ;
struct V_8 * V_9 = & V_2 -> V_94 [ V_95 ] ;
T_2 V_203 ;
F_30 ( V_2 , L_7 ) ;
F_31 ( & V_2 -> V_82 ) ;
if ( F_99 ( V_2 ) )
goto V_96;
if ( F_18 ( V_83 , & V_2 -> V_84 ) ||
F_18 ( V_204 , & V_2 -> V_84 ) ||
F_18 ( V_205 , & V_2 -> V_84 ) )
goto V_96;
if ( ! F_44 ( V_9 ) )
goto V_96;
if ( ! F_101 ( V_2 ) -> V_206 -> V_207 )
goto V_96;
V_203 = V_199 -> V_208 ;
if ( F_102 ( V_9 -> V_120 . V_199 ) == V_203 )
goto V_96;
V_195 = F_103 ( V_2 , V_199 -> V_209 , V_203 ) ;
if ( ! F_104 ( V_195 ) ) {
F_30 ( V_2 , L_26 ) ;
goto V_96;
}
V_2 -> V_202 . V_210 = V_197 -> V_211 ;
V_9 -> V_212 . V_213 = F_105 ( V_197 ) ;
if ( V_9 -> V_212 . V_213 )
F_106 ( V_197 , V_9 ) ;
else
V_9 -> V_212 . V_214 = false ;
if ( ( F_102 ( V_9 -> V_215 . V_199 ) != V_203 ) )
V_9 -> V_215 . V_11 = 0 ;
F_107 ( V_2 , V_199 , V_9 ) ;
F_108 ( V_2 , V_201 ) ;
F_109 ( V_2 , V_9 , V_199 -> V_209 , V_9 -> V_91 ) ;
F_110 ( V_2 ) ;
F_25 ( V_205 , & V_2 -> V_84 ) ;
V_2 -> V_216 = F_111 ( V_203 ) ;
if ( F_101 ( V_2 ) -> V_206 -> V_207 ( V_2 , V_193 ) ) {
F_27 ( V_205 , & V_2 -> V_84 ) ;
V_2 -> V_216 = 0 ;
F_112 ( V_9 -> V_91 , false ) ;
}
V_96:
F_32 ( & V_2 -> V_82 ) ;
F_30 ( V_2 , L_9 ) ;
}
static void F_113 ( struct V_6 * V_7 ,
unsigned int V_217 ,
unsigned int * V_218 ,
T_4 V_219 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
T_5 V_220 = 0 , V_221 = 0 ;
struct V_8 * V_9 ;
#define F_114 ( T_6 , T_7 ) do { \
if (*total_flags & (test)) \
filter_or |= (flag); \
else \
filter_nand |= (flag); \
} while (0)
F_30 ( V_2 , L_27 ,
V_217 , * V_218 ) ;
F_114 ( V_222 | V_223 , V_224 ) ;
F_114 ( V_225 , V_226 | V_224 ) ;
F_114 ( V_227 , V_228 ) ;
#undef F_114
F_31 ( & V_2 -> V_82 ) ;
F_4 (priv, ctx) {
V_9 -> V_215 . V_229 &= ~ V_221 ;
V_9 -> V_215 . V_229 |= V_220 ;
}
F_32 ( & V_2 -> V_82 ) ;
* V_218 &= V_222 | V_230 | V_223 |
V_227 | V_225 ;
}
static void F_115 ( struct V_6 * V_7 , bool V_231 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
F_31 ( & V_2 -> V_82 ) ;
F_30 ( V_2 , L_7 ) ;
if ( F_18 ( V_83 , & V_2 -> V_84 ) ) {
F_66 ( V_2 , L_28 ) ;
goto V_232;
}
if ( F_99 ( V_2 ) ) {
F_66 ( V_2 , L_29 ) ;
goto V_232;
}
if ( V_231 ) {
F_30 ( V_2 , L_30 ) ;
if ( F_116 ( V_2 , V_233 ) ) {
F_12 ( V_2 , L_31 ) ;
goto V_232;
}
}
F_30 ( V_2 , L_32 ) ;
F_117 ( F_8 ( V_2 ) ) ;
V_232:
F_32 ( & V_2 -> V_82 ) ;
F_30 ( V_2 , L_9 ) ;
}
static int F_118 ( struct V_6 * V_7 ,
struct V_198 * V_199 ,
enum V_234 V_235 ,
int V_236 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
struct V_8 * V_9 = & V_2 -> V_94 [ V_237 ] ;
int V_238 = 0 ;
if ( ! ( V_2 -> V_111 -> V_239 & F_6 ( V_237 ) ) )
return - V_136 ;
if ( ! ( V_9 -> V_30 & F_6 ( V_33 ) ) )
return - V_136 ;
F_30 ( V_2 , L_7 ) ;
F_31 ( & V_2 -> V_82 ) ;
if ( F_18 ( V_240 , & V_2 -> V_84 ) ) {
V_238 = - V_241 ;
goto V_96;
}
V_2 -> V_242 = V_199 ;
V_2 -> V_243 = V_235 ;
V_2 -> V_244 = F_119 ( 1000 * V_236 , 1024 ) ;
V_2 -> V_245 = false ;
F_120 ( & V_2 -> V_246 ) ;
if ( ! V_9 -> V_247 ) {
static const struct V_248 V_249 = {
. V_250 = {
. V_251 [ 0 ] = {
. V_252 = F_111 ( 3 ) ,
. V_253 = F_111 ( 7 ) ,
. V_254 = 2 ,
. V_255 = F_111 ( 1504 ) ,
} ,
. V_251 [ 1 ] = {
. V_252 = F_111 ( 7 ) ,
. V_253 = F_111 ( 15 ) ,
. V_254 = 2 ,
. V_255 = F_111 ( 3008 ) ,
} ,
. V_251 [ 2 ] = {
. V_252 = F_111 ( 15 ) ,
. V_253 = F_111 ( 1023 ) ,
. V_254 = 3 ,
} ,
. V_251 [ 3 ] = {
. V_252 = F_111 ( 15 ) ,
. V_253 = F_111 ( 1023 ) ,
. V_254 = 7 ,
} ,
} ,
} ;
V_9 -> V_247 = true ;
V_9 -> V_256 = V_249 ;
V_9 -> V_215 . V_257 = V_258 ;
memcpy ( V_9 -> V_215 . V_259 ,
V_2 -> V_94 [ V_95 ] . V_215 . V_259 ,
V_260 ) ;
memcpy ( V_9 -> V_215 . V_261 ,
V_2 -> V_94 [ V_95 ] . V_215 . V_259 ,
V_260 ) ;
V_238 = F_121 ( V_2 , V_9 ) ;
if ( V_238 )
goto V_96;
V_9 -> V_215 . V_229 |= V_262 |
V_224 |
V_226 ;
V_238 = F_121 ( V_2 , V_9 ) ;
if ( V_238 ) {
F_122 ( V_2 ) ;
goto V_96;
}
V_2 -> V_263 = true ;
}
V_238 = F_123 ( V_2 , V_9 -> V_91 , V_264 , V_199 -> V_209 ) ;
if ( V_238 )
F_122 ( V_2 ) ;
V_96:
F_32 ( & V_2 -> V_82 ) ;
F_30 ( V_2 , L_9 ) ;
return V_238 ;
}
static int F_124 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
if ( ! ( V_2 -> V_111 -> V_239 & F_6 ( V_237 ) ) )
return - V_136 ;
F_30 ( V_2 , L_7 ) ;
F_31 ( & V_2 -> V_82 ) ;
F_74 ( V_2 , V_2 -> V_244 ) ;
F_122 ( V_2 ) ;
F_32 ( & V_2 -> V_82 ) ;
F_30 ( V_2 , L_9 ) ;
return 0 ;
}
static void F_125 ( struct V_6 * V_7 ,
enum V_265 V_266 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
F_30 ( V_2 , L_7 ) ;
F_31 ( & V_2 -> V_82 ) ;
if ( F_101 ( V_2 ) -> V_267 &&
F_101 ( V_2 ) -> V_267 -> V_268 ) {
if ( V_266 == V_269 )
V_2 -> V_270 = true ;
else if ( V_266 == V_271 )
V_2 -> V_270 = false ;
F_126 ( V_2 ) ;
} else {
F_30 ( V_2 , L_33
L_34 ) ;
}
F_32 ( & V_2 -> V_82 ) ;
F_30 ( V_2 , L_9 ) ;
}
static int F_127 ( struct V_6 * V_7 ,
struct V_126 * V_127 , bool V_272 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
F_128 ( V_2 -> V_89 , & V_2 -> V_273 ) ;
return 0 ;
}
static int F_129 ( struct V_6 * V_7 ,
struct V_90 * V_91 , T_2 V_274 ,
const struct V_275 * V_276 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
struct V_28 * V_133 = ( void * ) V_91 -> V_134 ;
struct V_8 * V_9 = V_133 -> V_9 ;
int V_277 ;
if ( F_34 ( ! V_9 ) )
return - V_105 ;
F_30 ( V_2 , L_7 ) ;
if ( ! F_130 ( V_2 ) ) {
F_30 ( V_2 , L_35 ) ;
return - V_85 ;
}
if ( V_274 >= V_278 ) {
F_30 ( V_2 , L_36 , V_274 ) ;
return 0 ;
}
V_277 = V_278 - 1 - V_274 ;
F_31 ( & V_2 -> V_82 ) ;
V_9 -> V_256 . V_250 . V_251 [ V_277 ] . V_252 =
F_111 ( V_276 -> V_252 ) ;
V_9 -> V_256 . V_250 . V_251 [ V_277 ] . V_253 =
F_111 ( V_276 -> V_253 ) ;
V_9 -> V_256 . V_250 . V_251 [ V_277 ] . V_254 = V_276 -> V_279 ;
V_9 -> V_256 . V_250 . V_251 [ V_277 ] . V_255 =
F_111 ( ( V_276 -> V_280 * 32 ) ) ;
V_9 -> V_256 . V_250 . V_251 [ V_277 ] . V_281 = 0 ;
F_32 ( & V_2 -> V_82 ) ;
F_30 ( V_2 , L_9 ) ;
return 0 ;
}
static int F_131 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
return V_2 -> V_282 == V_283 ;
}
static int F_132 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
F_62 ( V_2 , V_9 ) ;
F_63 ( V_2 , V_9 ) ;
return F_121 ( V_2 , V_9 ) ;
}
static int F_133 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_90 * V_91 = V_9 -> V_91 ;
int V_238 ;
F_17 ( & V_2 -> V_82 ) ;
V_2 -> V_284 = V_91 -> type ;
V_9 -> V_247 = true ;
V_238 = F_132 ( V_2 , V_9 ) ;
if ( V_238 ) {
if ( ! V_9 -> V_285 )
V_9 -> V_247 = false ;
return V_238 ;
}
if ( F_101 ( V_2 ) -> V_267 && F_101 ( V_2 ) -> V_267 -> V_268 &&
V_91 -> type == V_142 ) {
V_2 -> V_286 = V_287 ;
}
return 0 ;
}
static int F_134 ( struct V_6 * V_7 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
struct V_28 * V_133 = ( void * ) V_91 -> V_134 ;
struct V_8 * V_288 , * V_9 = NULL ;
int V_238 ;
enum V_289 V_290 = F_135 ( V_91 ) ;
bool V_291 = false ;
F_30 ( V_2 , L_37 ,
V_290 , V_91 -> V_158 ) ;
F_136 ( & V_2 -> V_246 ) ;
F_31 ( & V_2 -> V_82 ) ;
F_122 ( V_2 ) ;
if ( ! F_130 ( V_2 ) ) {
F_19 ( V_2 , L_38 ) ;
V_238 = - V_105 ;
goto V_96;
}
F_4 (priv, tmp) {
T_1 V_292 =
V_288 -> V_30 | V_288 -> V_31 ;
if ( V_288 -> V_91 ) {
if ( V_288 -> V_91 == V_91 ) {
V_291 = true ;
V_9 = V_288 ;
break;
}
if ( V_288 -> V_31 &
F_6 ( V_288 -> V_91 -> type ) ) {
V_238 = - V_105 ;
goto V_96;
}
continue;
}
if ( ! ( V_292 & F_6 ( V_290 ) ) )
continue;
V_9 = V_288 ;
break;
}
if ( ! V_9 ) {
V_238 = - V_136 ;
goto V_96;
}
V_133 -> V_9 = V_9 ;
V_9 -> V_91 = V_91 ;
V_238 = F_133 ( V_2 , V_9 ) ;
if ( ! V_238 || V_291 )
goto V_96;
V_9 -> V_91 = NULL ;
V_2 -> V_284 = V_106 ;
V_96:
F_32 ( & V_2 -> V_82 ) ;
F_30 ( V_2 , L_9 ) ;
return V_238 ;
}
static void F_137 ( struct V_1 * V_2 ,
struct V_90 * V_91 ,
bool V_293 )
{
struct V_8 * V_9 = F_86 ( V_91 ) ;
F_17 ( & V_2 -> V_82 ) ;
if ( V_2 -> V_294 == V_91 ) {
F_74 ( V_2 , 200 ) ;
F_138 ( V_2 ) ;
}
if ( ! V_293 ) {
F_132 ( V_2 , V_9 ) ;
if ( ! V_9 -> V_285 )
V_9 -> V_247 = false ;
}
if ( V_91 -> type == V_142 )
V_2 -> V_286 = V_2 -> V_295 ;
}
static void F_139 ( struct V_6 * V_7 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
struct V_8 * V_9 = F_86 ( V_91 ) ;
F_30 ( V_2 , L_7 ) ;
F_31 ( & V_2 -> V_82 ) ;
if ( F_34 ( V_9 -> V_91 != V_91 ) ) {
struct V_8 * V_288 ;
F_12 ( V_2 , L_39 , V_9 -> V_91 , V_91 ) ;
F_4 (priv, tmp)
F_12 ( V_2 , L_40 ,
V_288 -> V_296 , V_288 , V_288 -> V_91 ) ;
}
V_9 -> V_91 = NULL ;
F_137 ( V_2 , V_91 , false ) ;
F_32 ( & V_2 -> V_82 ) ;
F_30 ( V_2 , L_9 ) ;
}
static int F_140 ( struct V_6 * V_7 ,
struct V_90 * V_91 ,
enum V_289 V_297 , bool V_298 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
struct V_8 * V_9 = F_86 ( V_91 ) ;
struct V_8 * V_299 = & V_2 -> V_94 [ V_95 ] ;
struct V_8 * V_288 ;
enum V_289 V_300 = V_297 ;
T_1 V_30 ;
int V_238 ;
F_30 ( V_2 , L_7 ) ;
V_297 = F_141 ( V_297 , V_298 ) ;
F_31 ( & V_2 -> V_82 ) ;
if ( ! V_9 -> V_91 || ! F_130 ( V_2 ) ) {
V_238 = - V_241 ;
goto V_96;
}
V_30 = V_9 -> V_30 | V_9 -> V_31 ;
if ( ! ( V_30 & F_6 ( V_297 ) ) ) {
V_238 = - V_241 ;
goto V_96;
}
if ( V_9 -> V_296 == V_237 && ! V_299 -> V_91 &&
( V_299 -> V_30 & F_6 ( V_297 ) ||
V_299 -> V_31 & F_6 ( V_297 ) ) ) {
F_5 ( V_32 != 2 ) ;
V_238 = - V_241 ;
goto V_96;
}
if ( V_9 -> V_31 & F_6 ( V_297 ) ) {
F_4 (priv, tmp) {
if ( V_9 == V_288 )
continue;
if ( ! V_288 -> V_91 )
continue;
V_238 = - V_241 ;
goto V_96;
}
}
F_137 ( V_2 , V_91 , true ) ;
V_91 -> type = V_300 ;
V_91 -> V_301 = V_298 ;
V_238 = F_133 ( V_2 , V_9 ) ;
F_34 ( V_238 ) ;
V_238 = 0 ;
V_96:
F_32 ( & V_2 -> V_82 ) ;
F_30 ( V_2 , L_9 ) ;
return V_238 ;
}
static int F_142 ( struct V_6 * V_7 ,
struct V_90 * V_91 ,
struct V_302 * V_303 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
int V_5 ;
F_30 ( V_2 , L_7 ) ;
if ( V_303 -> V_77 == 0 )
return - V_105 ;
F_31 ( & V_2 -> V_82 ) ;
if ( V_2 -> V_304 != V_305 ) {
F_143 ( V_2 ,
L_41 ) ;
V_2 -> V_306 = V_303 ;
V_2 -> V_294 = V_91 ;
V_5 = 0 ;
} else {
V_2 -> V_306 = V_303 ;
V_2 -> V_294 = V_91 ;
V_5 = F_123 ( V_2 , V_91 , V_305 ,
V_303 -> V_307 [ 0 ] -> V_209 ) ;
if ( V_5 ) {
V_2 -> V_306 = NULL ;
V_2 -> V_294 = NULL ;
}
}
F_30 ( V_2 , L_9 ) ;
F_32 ( & V_2 -> V_82 ) ;
return V_5 ;
}
static void F_144 ( struct V_1 * V_2 , int V_176 )
{
struct V_308 V_131 = {
. V_309 = V_310 ,
. V_311 = V_312 ,
. V_127 . V_176 = V_176 ,
} ;
F_145 ( V_2 , & V_131 , V_173 ) ;
}
static void F_146 ( struct V_6 * V_7 ,
struct V_90 * V_91 ,
enum V_313 V_131 ,
struct V_126 * V_127 )
{
struct V_1 * V_2 = F_29 ( V_7 ) ;
struct V_26 * V_157 = ( void * ) V_127 -> V_134 ;
int V_176 ;
F_30 ( V_2 , L_7 ) ;
switch ( V_131 ) {
case V_314 :
F_34 ( ! V_157 -> V_179 ) ;
V_157 -> V_315 = true ;
if ( F_147 ( & V_157 -> V_178 ) > 0 )
F_148 ( V_7 , V_127 , true ) ;
break;
case V_316 :
F_34 ( ! V_157 -> V_179 ) ;
if ( ! V_157 -> V_315 )
break;
V_157 -> V_315 = false ;
V_176 = F_97 ( V_127 ) ;
if ( V_176 != V_177 )
F_144 ( V_2 , V_176 ) ;
break;
default:
break;
}
F_30 ( V_2 , L_9 ) ;
}
struct V_6 * F_149 ( void )
{
struct V_1 * V_2 ;
struct V_317 * V_318 ;
struct V_6 * V_7 ;
V_7 = F_150 ( sizeof( struct V_1 ) +
sizeof( struct V_317 ) , & V_319 ) ;
if ( ! V_7 )
goto V_96;
V_318 = V_7 -> V_2 ;
V_2 = F_151 ( V_318 ) ;
V_2 -> V_7 = V_7 ;
V_96:
return V_7 ;
}
