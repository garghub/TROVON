static struct V_1 * F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return NULL ;
}
static void F_2 ( struct V_2 * V_3 , const struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
const struct V_10 * V_11 = ( const struct V_10 * ) V_9 ;
F_4 ( V_9 ) ;
V_3 -> V_12 = V_9 ;
F_5 ( V_3 ) -> V_13 = V_7 -> V_14 ;
if ( V_11 -> V_15 )
F_6 ( V_3 ) -> V_16 = V_11 -> V_15 -> V_17 ;
}
static void F_7 ( struct V_2 * V_3 )
{
if ( V_3 -> V_18 != V_19 ) {
if ( F_8 ( V_3 ) -> V_20 == & V_21 ) {
V_22 . V_23 ( V_3 ) ;
return;
}
F_9 () ;
F_10 ( V_3 , NULL ) ;
F_11 () ;
}
}
static T_1 T_2 F_12 ( int V_24 ,
const struct V_4 * V_25 ,
const struct V_4 * V_26 ,
T_3 V_27 )
{
return F_13 ( V_25 , V_26 , V_24 , V_28 , V_27 ) ;
}
static T_4 F_14 ( const struct V_6 * V_7 )
{
return F_15 ( F_16 ( V_7 ) -> V_26 . V_29 ,
F_16 ( V_7 ) -> V_25 . V_29 ,
F_17 ( V_7 ) -> V_30 ,
F_17 ( V_7 ) -> V_31 ) ;
}
static int F_18 ( struct V_2 * V_3 , struct V_32 * V_33 ,
int V_34 )
{
struct V_35 * V_36 = (struct V_35 * ) V_33 ;
struct V_37 * V_38 = F_5 ( V_3 ) ;
struct V_39 * V_40 = F_8 ( V_3 ) ;
struct V_41 * V_42 = F_6 ( V_3 ) ;
struct V_43 * V_44 = F_19 ( V_3 ) ;
struct V_4 * V_25 = NULL , * V_45 , V_46 ;
struct V_10 * V_11 ;
struct V_47 V_48 ;
struct V_8 * V_9 ;
int V_49 ;
int V_50 ;
if ( V_34 < V_51 )
return - V_52 ;
if ( V_36 -> V_53 != V_54 )
return - V_55 ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
if ( V_42 -> V_56 ) {
V_48 . V_57 = V_36 -> V_58 & V_59 ;
F_20 ( V_48 . V_57 ) ;
if ( V_48 . V_57 & V_60 ) {
struct V_61 * V_57 ;
V_57 = F_21 ( V_3 , V_48 . V_57 ) ;
if ( V_57 == NULL )
return - V_52 ;
V_36 -> V_62 = V_57 -> V_9 ;
F_22 ( V_57 ) ;
}
}
if( F_23 ( & V_36 -> V_62 ) )
V_36 -> V_62 . V_63 [ 15 ] = 0x1 ;
V_49 = F_24 ( & V_36 -> V_62 ) ;
if( V_49 & V_64 )
return - V_65 ;
if ( V_49 & V_66 ) {
if ( V_34 >= sizeof( struct V_35 ) &&
V_36 -> V_67 ) {
if ( V_3 -> V_68 &&
V_3 -> V_68 != V_36 -> V_67 )
return - V_52 ;
V_3 -> V_68 = V_36 -> V_67 ;
}
if ( ! V_3 -> V_68 )
return - V_52 ;
}
if ( V_44 -> V_69 . V_70 &&
! F_25 ( & V_42 -> V_26 , & V_36 -> V_62 ) ) {
V_44 -> V_69 . V_71 = 0 ;
V_44 -> V_69 . V_70 = 0 ;
V_44 -> V_72 = 0 ;
}
V_42 -> V_26 = V_36 -> V_62 ;
V_42 -> V_73 = V_48 . V_57 ;
if ( V_49 == V_74 ) {
T_5 V_75 = V_40 -> V_76 ;
struct V_77 sin ;
F_26 ( V_3 , L_1 ) ;
if ( F_27 ( V_3 ) )
return - V_65 ;
sin . V_78 = V_79 ;
sin . V_80 = V_36 -> V_81 ;
sin . V_82 . V_83 = V_36 -> V_62 . V_29 [ 3 ] ;
V_40 -> V_20 = & V_21 ;
V_3 -> V_84 = V_85 ;
#ifdef F_28
V_44 -> V_86 = & V_87 ;
#endif
V_50 = F_29 ( V_3 , (struct V_32 * ) & sin , sizeof( sin ) ) ;
if ( V_50 ) {
V_40 -> V_76 = V_75 ;
V_40 -> V_20 = & V_88 ;
V_3 -> V_84 = V_89 ;
#ifdef F_28
V_44 -> V_86 = & V_90 ;
#endif
goto V_91;
} else {
F_30 ( V_38 -> V_92 , & V_42 -> V_25 ) ;
F_30 ( V_38 -> V_93 ,
& V_42 -> V_94 ) ;
}
return V_50 ;
}
if ( ! F_23 ( & V_42 -> V_94 ) )
V_25 = & V_42 -> V_94 ;
V_48 . V_95 = V_28 ;
V_48 . V_26 = V_42 -> V_26 ;
V_48 . V_25 = V_25 ? * V_25 : V_42 -> V_25 ;
V_48 . V_96 = V_3 -> V_68 ;
V_48 . V_97 = V_3 -> V_98 ;
V_48 . V_99 = V_36 -> V_81 ;
V_48 . V_100 = V_38 -> V_101 ;
V_45 = F_31 ( & V_48 , V_42 -> V_102 , & V_46 ) ;
F_32 ( V_3 , F_33 ( & V_48 ) ) ;
V_9 = F_34 ( V_3 , & V_48 , V_45 , true ) ;
if ( F_35 ( V_9 ) ) {
V_50 = F_36 ( V_9 ) ;
goto V_91;
}
if ( V_25 == NULL ) {
V_25 = & V_48 . V_25 ;
V_42 -> V_94 = * V_25 ;
}
V_42 -> V_25 = * V_25 ;
V_38 -> V_93 = V_103 ;
V_3 -> V_104 = V_105 ;
F_37 ( V_3 , V_9 , NULL , NULL ) ;
V_11 = (struct V_10 * ) V_9 ;
if ( V_106 . V_107 &&
! V_44 -> V_69 . V_70 &&
F_25 ( & V_11 -> V_108 . V_5 , & V_42 -> V_26 ) )
F_38 ( V_3 , V_9 ) ;
V_40 -> V_76 = 0 ;
if ( V_42 -> V_102 )
V_40 -> V_76 = ( V_42 -> V_102 -> V_109 +
V_42 -> V_102 -> V_110 ) ;
V_44 -> V_69 . V_111 = V_112 - sizeof( struct V_113 ) - sizeof( struct V_114 ) ;
V_38 -> V_115 = V_36 -> V_81 ;
F_39 ( V_3 , V_116 ) ;
V_50 = F_40 ( & V_106 , V_3 ) ;
if ( V_50 )
goto V_117;
if ( ! V_44 -> V_72 )
V_44 -> V_72 = F_15 ( V_42 -> V_25 . V_29 ,
V_42 -> V_26 . V_29 ,
V_38 -> V_101 ,
V_38 -> V_115 ) ;
V_50 = F_41 ( V_3 ) ;
if ( V_50 )
goto V_117;
return 0 ;
V_117:
F_39 ( V_3 , V_19 ) ;
F_42 ( V_3 ) ;
V_91:
V_38 -> V_115 = 0 ;
V_3 -> V_118 = 0 ;
return V_50 ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_8 * V_9 ;
if ( ( 1 << V_3 -> V_18 ) & ( V_119 | V_120 ) )
return;
V_9 = F_44 ( V_3 , F_19 ( V_3 ) -> V_121 ) ;
if ( ! V_9 )
return;
if ( F_8 ( V_3 ) -> V_122 > F_45 ( V_9 ) ) {
F_46 ( V_3 , F_45 ( V_9 ) ) ;
F_47 ( V_3 ) ;
}
}
static void F_48 ( struct V_6 * V_7 , struct V_123 * V_102 ,
T_6 type , T_6 V_124 , int V_125 , T_7 V_126 )
{
const struct V_114 * V_127 = ( const struct V_114 * ) V_7 -> V_128 ;
const struct V_113 * V_129 = (struct V_113 * ) ( V_7 -> V_128 + V_125 ) ;
struct V_41 * V_42 ;
struct V_2 * V_3 ;
int V_50 ;
struct V_43 * V_44 ;
T_4 V_130 ;
struct V_131 * V_131 = F_49 ( V_7 -> V_132 ) ;
V_3 = F_50 ( V_131 , & V_133 , & V_127 -> V_26 ,
V_129 -> V_30 , & V_127 -> V_25 , V_129 -> V_31 , V_7 -> V_132 -> V_134 ) ;
if ( V_3 == NULL ) {
F_51 ( V_131 , F_52 ( V_7 -> V_132 ) ,
V_135 ) ;
return;
}
if ( V_3 -> V_18 == V_136 ) {
F_53 ( F_54 ( V_3 ) ) ;
return;
}
F_55 ( V_3 ) ;
if ( F_56 ( V_3 ) && type != V_137 )
F_57 ( V_131 , V_138 ) ;
if ( V_3 -> V_18 == V_19 )
goto V_139;
if ( F_16 ( V_7 ) -> V_140 < F_6 ( V_3 ) -> V_141 ) {
F_57 ( V_131 , V_142 ) ;
goto V_139;
}
V_44 = F_19 ( V_3 ) ;
V_130 = F_58 ( V_129 -> V_130 ) ;
if ( V_3 -> V_18 != V_143 &&
! F_59 ( V_130 , V_44 -> V_144 , V_44 -> V_145 ) ) {
F_57 ( V_131 , V_146 ) ;
goto V_139;
}
V_42 = F_6 ( V_3 ) ;
if ( type == V_147 ) {
struct V_8 * V_9 = F_60 ( V_3 , V_42 -> V_148 ) ;
if ( V_9 )
V_9 -> V_149 -> V_150 ( V_9 , V_3 , V_7 ) ;
}
if ( type == V_137 ) {
V_44 -> V_121 = F_58 ( V_126 ) ;
if ( ! F_56 ( V_3 ) )
F_43 ( V_3 ) ;
else if ( ! F_61 ( V_151 ,
& V_44 -> V_152 ) )
F_62 ( V_3 ) ;
goto V_139;
}
F_63 ( type , V_124 , & V_50 ) ;
switch ( V_3 -> V_18 ) {
struct V_153 * V_154 , * * V_155 ;
case V_143 :
if ( F_56 ( V_3 ) )
goto V_139;
V_154 = F_64 ( V_3 , & V_155 , V_129 -> V_30 , & V_127 -> V_26 ,
& V_127 -> V_25 , F_65 ( V_7 ) ) ;
if ( ! V_154 )
goto V_139;
F_66 ( V_154 -> V_3 != NULL ) ;
if ( V_130 != F_67 ( V_154 ) -> V_156 ) {
F_57 ( V_131 , V_146 ) ;
goto V_139;
}
F_68 ( V_3 , V_154 , V_155 ) ;
goto V_139;
case V_116 :
case V_157 :
if ( ! F_56 ( V_3 ) ) {
V_3 -> V_158 = V_50 ;
V_3 -> V_159 ( V_3 ) ;
F_69 ( V_3 ) ;
} else
V_3 -> V_160 = V_50 ;
goto V_139;
}
if ( ! F_56 ( V_3 ) && V_42 -> V_161 ) {
V_3 -> V_158 = V_50 ;
V_3 -> V_159 ( V_3 ) ;
} else
V_3 -> V_160 = V_50 ;
V_139:
F_70 ( V_3 ) ;
F_71 ( V_3 ) ;
}
static int F_72 ( struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_47 * V_48 ,
struct V_153 * V_154 ,
struct V_162 * V_163 ,
T_8 V_164 )
{
struct V_165 * V_166 = F_73 ( V_154 ) ;
struct V_41 * V_42 = F_6 ( V_3 ) ;
struct V_6 * V_7 ;
int V_50 = - V_167 ;
if ( ! V_9 && ( V_9 = F_74 ( V_3 , V_48 , V_154 ) ) == NULL )
goto V_168;
V_7 = F_75 ( V_3 , V_9 , V_154 , V_163 , NULL ) ;
if ( V_7 ) {
F_76 ( V_7 , & V_166 -> V_169 , & V_166 -> V_170 ) ;
V_48 -> V_26 = V_166 -> V_170 ;
F_77 ( V_7 , V_164 ) ;
V_50 = F_78 ( V_3 , V_7 , V_48 , V_42 -> V_102 , V_42 -> V_171 ) ;
V_50 = F_79 ( V_50 ) ;
}
V_168:
return V_50 ;
}
static int F_80 ( struct V_2 * V_3 , struct V_153 * V_154 ,
struct V_162 * V_163 )
{
struct V_47 V_48 ;
F_81 ( F_82 ( V_3 ) , V_172 ) ;
return F_72 ( V_3 , NULL , & V_48 , V_154 , V_163 , 0 ) ;
}
static void F_83 ( struct V_153 * V_154 )
{
F_84 ( F_73 ( V_154 ) -> V_173 ) ;
}
static struct V_1 * F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_85 ( V_3 , (union V_174 * ) V_5 , V_54 ) ;
}
static struct V_1 * F_86 ( struct V_2 * V_3 ,
struct V_2 * V_175 )
{
return F_1 ( V_3 , & F_6 ( V_175 ) -> V_26 ) ;
}
static struct V_1 * F_87 ( struct V_2 * V_3 ,
struct V_153 * V_154 )
{
return F_1 ( V_3 , & F_73 ( V_154 ) -> V_170 ) ;
}
static int F_88 ( struct V_2 * V_3 , char T_9 * V_176 ,
int V_177 )
{
struct V_178 V_179 ;
struct V_35 * V_180 = (struct V_35 * ) & V_179 . V_181 ;
if ( V_177 < sizeof( V_179 ) )
return - V_52 ;
if ( F_89 ( & V_179 , V_176 , sizeof( V_179 ) ) )
return - V_182 ;
if ( V_180 -> V_53 != V_54 )
return - V_52 ;
if ( ! V_179 . V_183 ) {
if ( F_90 ( & V_180 -> V_62 ) )
return F_91 ( V_3 , (union V_174 * ) & V_180 -> V_62 . V_29 [ 3 ] ,
V_79 ) ;
return F_91 ( V_3 , (union V_174 * ) & V_180 -> V_62 ,
V_54 ) ;
}
if ( V_179 . V_183 > V_184 )
return - V_52 ;
if ( F_90 ( & V_180 -> V_62 ) )
return F_92 ( V_3 , (union V_174 * ) & V_180 -> V_62 . V_29 [ 3 ] ,
V_79 , V_179 . V_185 , V_179 . V_183 , V_186 ) ;
return F_92 ( V_3 , (union V_174 * ) & V_180 -> V_62 ,
V_54 , V_179 . V_185 , V_179 . V_183 , V_186 ) ;
}
static int F_93 ( struct V_187 * V_188 ,
const struct V_4 * V_26 ,
const struct V_4 * V_25 , int V_189 )
{
struct V_190 * V_191 ;
struct V_192 V_193 ;
V_191 = & V_188 -> V_194 . V_195 ;
V_191 -> V_25 = * V_25 ;
V_191 -> V_26 = * V_26 ;
V_191 -> V_196 = F_94 ( V_28 ) ;
V_191 -> V_24 = F_94 ( V_189 ) ;
F_95 ( & V_193 , V_191 , sizeof( * V_191 ) ) ;
return F_96 ( & V_188 -> V_197 , & V_193 , sizeof( * V_191 ) ) ;
}
static int F_97 ( char * V_198 , struct V_1 * V_199 ,
const struct V_4 * V_26 , struct V_4 * V_25 ,
const struct V_113 * V_129 )
{
struct V_187 * V_188 ;
struct V_200 * V_201 ;
V_188 = F_98 () ;
if ( ! V_188 )
goto V_202;
V_201 = & V_188 -> V_197 ;
if ( F_99 ( V_201 ) )
goto V_203;
if ( F_93 ( V_188 , V_26 , V_25 , V_129 -> V_204 << 2 ) )
goto V_203;
if ( F_100 ( V_188 , V_129 ) )
goto V_203;
if ( F_101 ( V_188 , V_199 ) )
goto V_203;
if ( F_102 ( V_201 , V_198 ) )
goto V_203;
F_103 () ;
return 0 ;
V_203:
F_103 () ;
V_202:
memset ( V_198 , 0 , 16 ) ;
return 1 ;
}
static int F_104 ( char * V_198 , struct V_1 * V_199 ,
const struct V_2 * V_3 ,
const struct V_153 * V_154 ,
const struct V_6 * V_7 )
{
const struct V_4 * V_25 , * V_26 ;
struct V_187 * V_188 ;
struct V_200 * V_201 ;
const struct V_113 * V_129 = F_17 ( V_7 ) ;
if ( V_3 ) {
V_25 = & F_6 ( V_3 ) -> V_25 ;
V_26 = & F_6 ( V_3 ) -> V_26 ;
} else if ( V_154 ) {
V_25 = & F_73 ( V_154 ) -> V_169 ;
V_26 = & F_73 ( V_154 ) -> V_170 ;
} else {
const struct V_114 * V_205 = F_16 ( V_7 ) ;
V_25 = & V_205 -> V_25 ;
V_26 = & V_205 -> V_26 ;
}
V_188 = F_98 () ;
if ( ! V_188 )
goto V_202;
V_201 = & V_188 -> V_197 ;
if ( F_99 ( V_201 ) )
goto V_203;
if ( F_93 ( V_188 , V_26 , V_25 , V_7 -> V_24 ) )
goto V_203;
if ( F_100 ( V_188 , V_129 ) )
goto V_203;
if ( F_105 ( V_188 , V_7 , V_129 -> V_204 << 2 ) )
goto V_203;
if ( F_101 ( V_188 , V_199 ) )
goto V_203;
if ( F_102 ( V_201 , V_198 ) )
goto V_203;
F_103 () ;
return 0 ;
V_203:
F_103 () ;
V_202:
memset ( V_198 , 0 , 16 ) ;
return 1 ;
}
static int F_106 ( struct V_2 * V_3 , const struct V_6 * V_7 )
{
const T_10 * V_206 = NULL ;
struct V_1 * V_207 ;
const struct V_114 * V_205 = F_16 ( V_7 ) ;
const struct V_113 * V_129 = F_17 ( V_7 ) ;
int V_208 ;
T_6 V_209 [ 16 ] ;
V_207 = F_1 ( V_3 , & V_205 -> V_25 ) ;
V_206 = F_107 ( V_129 ) ;
if ( ! V_207 && ! V_206 )
return 0 ;
if ( V_207 && ! V_206 ) {
F_57 ( F_82 ( V_3 ) , V_210 ) ;
return 1 ;
}
if ( ! V_207 && V_206 ) {
F_57 ( F_82 ( V_3 ) , V_211 ) ;
return 1 ;
}
V_208 = F_104 ( V_209 ,
V_207 ,
NULL , NULL , V_7 ) ;
if ( V_208 || memcmp ( V_206 , V_209 , 16 ) != 0 ) {
F_108 ( L_2 ,
V_208 ? L_3 : L_4 ,
& V_205 -> V_25 , F_109 ( V_129 -> V_31 ) ,
& V_205 -> V_26 , F_109 ( V_129 -> V_30 ) ) ;
return 1 ;
}
return 0 ;
}
static void F_76 ( struct V_6 * V_7 ,
const struct V_4 * V_25 , const struct V_4 * V_26 )
{
struct V_113 * V_129 = F_17 ( V_7 ) ;
if ( V_7 -> V_212 == V_213 ) {
V_129 -> V_214 = ~ F_12 ( V_7 -> V_24 , V_25 , V_26 , 0 ) ;
V_7 -> V_215 = F_110 ( V_7 ) - V_7 -> V_216 ;
V_7 -> V_217 = F_111 ( struct V_113 , V_214 ) ;
} else {
V_129 -> V_214 = F_12 ( V_7 -> V_24 , V_25 , V_26 ,
F_112 ( V_129 , V_129 -> V_204 << 2 ,
V_7 -> V_218 ) ) ;
}
}
static void F_113 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_41 * V_42 = F_6 ( V_3 ) ;
F_76 ( V_7 , & V_42 -> V_25 , & V_42 -> V_26 ) ;
}
static int F_114 ( struct V_6 * V_7 )
{
const struct V_114 * V_219 ;
struct V_113 * V_129 ;
if ( ! F_115 ( V_7 , sizeof( * V_129 ) ) )
return - V_52 ;
V_219 = F_16 ( V_7 ) ;
V_129 = F_17 ( V_7 ) ;
V_129 -> V_214 = 0 ;
V_7 -> V_212 = V_213 ;
F_76 ( V_7 , & V_219 -> V_25 , & V_219 -> V_26 ) ;
return 0 ;
}
static struct V_6 * * F_116 ( struct V_6 * * V_216 ,
struct V_6 * V_7 )
{
const struct V_114 * V_220 = F_117 ( V_7 ) ;
T_3 V_221 ;
T_2 V_222 ;
switch ( V_7 -> V_212 ) {
case V_223 :
if ( ! F_12 ( F_118 ( V_7 ) , & V_220 -> V_25 , & V_220 -> V_26 ,
V_7 -> V_218 ) ) {
V_7 -> V_212 = V_224 ;
break;
}
V_225:
F_119 ( V_7 ) -> V_225 = 1 ;
return NULL ;
case V_226 :
V_221 = ~ F_120 ( F_13 ( & V_220 -> V_25 , & V_220 -> V_26 ,
F_118 ( V_7 ) ,
V_28 , 0 ) ) ;
V_222 = F_121 ( F_122 ( V_7 ,
F_123 ( V_7 ) ,
F_118 ( V_7 ) ,
V_221 ) ) ;
if ( V_222 )
goto V_225;
V_7 -> V_212 = V_224 ;
break;
}
return F_124 ( V_216 , V_7 ) ;
}
static int F_125 ( struct V_6 * V_7 )
{
const struct V_114 * V_220 = F_16 ( V_7 ) ;
struct V_113 * V_129 = F_17 ( V_7 ) ;
V_129 -> V_214 = ~ F_12 ( V_7 -> V_24 - F_126 ( V_7 ) ,
& V_220 -> V_25 , & V_220 -> V_26 , 0 ) ;
F_127 ( V_7 ) -> V_227 = V_105 ;
return F_128 ( V_7 ) ;
}
static void F_129 ( struct V_6 * V_7 , T_5 V_130 , T_5 V_228 , T_5 V_229 ,
T_5 V_230 , struct V_1 * V_199 , int V_231 , T_6 V_171 )
{
const struct V_113 * V_129 = F_17 ( V_7 ) ;
struct V_113 * V_232 ;
struct V_6 * V_233 ;
struct V_47 V_48 ;
struct V_131 * V_131 = F_49 ( F_3 ( V_7 ) -> V_132 ) ;
struct V_2 * V_234 = V_131 -> V_235 . F_19 ;
unsigned int V_236 = sizeof( struct V_113 ) ;
struct V_8 * V_9 ;
T_7 * V_237 ;
if ( V_230 )
V_236 += V_238 ;
#ifdef F_28
if ( V_199 )
V_236 += V_239 ;
#endif
V_233 = F_130 ( V_240 + sizeof( struct V_114 ) + V_236 ,
V_241 ) ;
if ( V_233 == NULL )
return;
F_131 ( V_233 , V_240 + sizeof( struct V_114 ) + V_236 ) ;
V_232 = (struct V_113 * ) F_132 ( V_233 , V_236 ) ;
F_133 ( V_233 ) ;
memset ( V_232 , 0 , sizeof( * V_232 ) ) ;
V_232 -> V_30 = V_129 -> V_31 ;
V_232 -> V_31 = V_129 -> V_30 ;
V_232 -> V_204 = V_236 / 4 ;
V_232 -> V_130 = F_134 ( V_130 ) ;
V_232 -> V_242 = F_134 ( V_228 ) ;
V_232 -> V_228 = ! V_231 || ! V_129 -> V_228 ;
V_232 -> V_231 = V_231 ;
V_232 -> V_243 = F_135 ( V_229 ) ;
V_237 = ( T_7 * ) ( V_232 + 1 ) ;
if ( V_230 ) {
* V_237 ++ = F_134 ( ( V_244 << 24 ) | ( V_244 << 16 ) |
( V_245 << 8 ) | V_246 ) ;
* V_237 ++ = F_134 ( V_247 ) ;
* V_237 ++ = F_134 ( V_230 ) ;
}
#ifdef F_28
if ( V_199 ) {
* V_237 ++ = F_134 ( ( V_244 << 24 ) | ( V_244 << 16 ) |
( V_248 << 8 ) | V_249 ) ;
F_97 ( ( T_10 * ) V_237 , V_199 ,
& F_16 ( V_7 ) -> V_25 ,
& F_16 ( V_7 ) -> V_26 , V_232 ) ;
}
#endif
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_48 . V_26 = F_16 ( V_7 ) -> V_25 ;
V_48 . V_25 = F_16 ( V_7 ) -> V_26 ;
V_233 -> V_212 = V_213 ;
V_233 -> V_218 = 0 ;
F_76 ( V_233 , & V_48 . V_25 , & V_48 . V_26 ) ;
V_48 . V_95 = V_28 ;
if ( F_24 ( & V_48 . V_26 ) & V_66 )
V_48 . V_96 = F_65 ( V_7 ) ;
V_48 . V_99 = V_232 -> V_30 ;
V_48 . V_100 = V_232 -> V_31 ;
F_136 ( V_7 , F_33 ( & V_48 ) ) ;
V_9 = F_34 ( V_234 , & V_48 , NULL , false ) ;
if ( ! F_35 ( V_9 ) ) {
F_137 ( V_233 , V_9 ) ;
F_78 ( V_234 , V_233 , & V_48 , NULL , V_171 ) ;
F_81 ( V_131 , V_250 ) ;
if ( V_231 )
F_81 ( V_131 , V_251 ) ;
return;
}
F_84 ( V_233 ) ;
}
static void F_138 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
const struct V_113 * V_129 = F_17 ( V_7 ) ;
T_5 V_130 = 0 , V_242 = 0 ;
struct V_1 * V_199 = NULL ;
#ifdef F_28
const T_10 * V_206 = NULL ;
struct V_114 * V_219 = F_16 ( V_7 ) ;
unsigned char V_209 [ 16 ] ;
int V_208 ;
struct V_2 * V_252 = NULL ;
#endif
if ( V_129 -> V_231 )
return;
if ( ! F_139 ( V_7 ) )
return;
#ifdef F_28
V_206 = F_107 ( V_129 ) ;
if ( ! V_3 && V_206 ) {
V_252 = F_140 ( F_49 ( F_3 ( V_7 ) -> V_132 ) ,
& V_133 , & V_219 -> V_26 ,
F_109 ( V_129 -> V_31 ) , F_65 ( V_7 ) ) ;
if ( ! V_252 )
return;
F_141 () ;
V_199 = F_1 ( V_252 , & V_219 -> V_25 ) ;
if ( ! V_199 )
goto V_253;
V_208 = F_104 ( V_209 , V_199 , NULL , NULL , V_7 ) ;
if ( V_208 || memcmp ( V_206 , V_209 , 16 ) != 0 )
goto V_253;
} else {
V_199 = V_3 ? F_1 ( V_3 , & V_219 -> V_25 ) : NULL ;
}
#endif
if ( V_129 -> V_228 )
V_130 = F_58 ( V_129 -> V_242 ) ;
else
V_242 = F_58 ( V_129 -> V_130 ) + V_129 -> V_254 + V_129 -> V_255 + V_7 -> V_24 -
( V_129 -> V_204 << 2 ) ;
F_129 ( V_7 , V_130 , V_242 , 0 , 0 , V_199 , 1 , 0 ) ;
#ifdef F_28
V_253:
if ( V_252 ) {
F_142 () ;
F_71 ( V_252 ) ;
}
#endif
}
static void F_143 ( struct V_6 * V_7 , T_5 V_130 , T_5 V_228 , T_5 V_229 , T_5 V_230 ,
struct V_1 * V_199 , T_6 V_171 )
{
F_129 ( V_7 , V_130 , V_228 , V_229 , V_230 , V_199 , 0 , V_171 ) ;
}
static void F_144 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_256 * V_257 = F_54 ( V_3 ) ;
struct V_258 * V_259 = F_145 ( V_3 ) ;
F_143 ( V_7 , V_259 -> V_260 , V_259 -> V_261 ,
V_259 -> V_262 >> V_257 -> V_263 ,
V_259 -> V_264 , F_146 ( V_259 ) ,
V_257 -> V_265 ) ;
F_53 ( V_257 ) ;
}
static void F_147 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_153 * V_154 )
{
F_143 ( V_7 , F_67 ( V_154 ) -> V_156 + 1 , F_67 ( V_154 ) -> V_266 + 1 , V_154 -> V_267 , V_154 -> V_71 ,
F_1 ( V_3 , & F_16 ( V_7 ) -> V_26 ) , 0 ) ;
}
static struct V_2 * F_148 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_153 * V_154 , * * V_155 ;
const struct V_113 * V_129 = F_17 ( V_7 ) ;
struct V_2 * V_268 ;
V_154 = F_64 ( V_3 , & V_155 , V_129 -> V_31 ,
& F_16 ( V_7 ) -> V_25 ,
& F_16 ( V_7 ) -> V_26 , F_65 ( V_7 ) ) ;
if ( V_154 )
return F_149 ( V_3 , V_7 , V_154 , V_155 , false ) ;
V_268 = F_150 ( F_82 ( V_3 ) , & V_133 ,
& F_16 ( V_7 ) -> V_25 , V_129 -> V_31 ,
& F_16 ( V_7 ) -> V_26 , F_109 ( V_129 -> V_30 ) , F_65 ( V_7 ) ) ;
if ( V_268 ) {
if ( V_268 -> V_18 != V_136 ) {
F_55 ( V_268 ) ;
return V_268 ;
}
F_53 ( F_54 ( V_268 ) ) ;
return NULL ;
}
#ifdef F_151
if ( ! V_129 -> V_254 )
V_3 = F_152 ( V_3 , V_7 ) ;
#endif
return V_3 ;
}
static int F_153 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_269 V_270 ;
struct V_271 V_272 ;
const T_6 * V_206 ;
struct V_153 * V_154 ;
struct V_165 * V_166 ;
struct V_41 * V_42 = F_6 ( V_3 ) ;
struct V_43 * V_44 = F_19 ( V_3 ) ;
T_4 V_273 = F_154 ( V_7 ) -> V_274 ;
struct V_8 * V_9 = NULL ;
struct V_47 V_48 ;
bool V_275 = false ;
if ( V_7 -> V_196 == F_135 ( V_276 ) )
return F_155 ( V_3 , V_7 ) ;
if ( ! F_139 ( V_7 ) )
goto V_277;
if ( F_156 ( V_3 ) && ! V_273 ) {
V_275 = F_157 ( V_3 , V_7 , L_5 ) ;
if ( ! V_275 )
goto V_277;
}
if ( F_158 ( V_3 ) && F_159 ( V_3 ) > 1 )
goto V_277;
V_154 = F_160 ( & V_278 ) ;
if ( V_154 == NULL )
goto V_277;
#ifdef F_28
F_67 ( V_154 ) -> V_86 = & V_279 ;
#endif
F_161 ( & V_272 ) ;
V_272 . V_111 = V_112 - sizeof( struct V_113 ) - sizeof( struct V_114 ) ;
V_272 . V_280 = V_44 -> V_69 . V_280 ;
F_162 ( V_7 , & V_272 , & V_206 , 0 , NULL ) ;
if ( V_272 . V_281 > 0 &&
V_272 . V_282 &&
! V_44 -> V_69 . V_283 &&
( V_284 > 0 ||
( V_44 -> V_285 != NULL &&
V_44 -> V_285 -> V_286 > 0 ) ) ) {
T_6 * V_287 ;
T_5 * V_288 ;
T_5 * V_289 = & V_270 . V_290 [ V_291 ] ;
int V_292 = V_272 . V_281 - V_293 ;
if ( F_163 ( & V_270 . V_290 [ 0 ] ) != 0 )
goto V_294;
V_288 = ( V_295 T_5 * ) & F_16 ( V_7 ) -> V_26 . V_29 [ 0 ] ;
* V_289 ++ ^= * V_288 ++ ;
* V_289 ++ ^= * V_288 ++ ;
* V_289 ++ ^= * V_288 ++ ;
* V_289 ++ ^= * V_288 ++ ;
V_288 = ( V_295 T_5 * ) & F_16 ( V_7 ) -> V_25 . V_29 [ 0 ] ;
* V_289 ++ ^= * V_288 ++ ;
* V_289 ++ ^= * V_288 ++ ;
* V_289 ++ ^= * V_288 ++ ;
* V_289 ++ ^= * V_288 ++ ;
V_287 = ( T_6 * ) V_289 ;
while ( V_292 -- > 0 )
* V_287 ++ ^= * V_206 ++ ;
V_275 = false ;
V_270 . V_283 = 0 ;
V_270 . V_281 = V_272 . V_281 ;
} else if ( ! V_44 -> V_69 . V_296 ) {
V_270 . V_283 = 1 ;
V_270 . V_281 = 0 ;
} else {
goto V_294;
}
V_270 . V_296 = V_44 -> V_69 . V_296 ;
if ( V_275 && ! V_272 . V_282 )
F_161 ( & V_272 ) ;
V_272 . V_297 = V_272 . V_282 ;
F_164 ( V_154 , & V_272 , V_7 ) ;
V_166 = F_73 ( V_154 ) ;
V_166 -> V_170 = F_16 ( V_7 ) -> V_25 ;
V_166 -> V_169 = F_16 ( V_7 ) -> V_26 ;
if ( ! V_275 || V_272 . V_297 )
F_165 ( V_154 , V_7 ) ;
V_166 -> V_298 = V_3 -> V_68 ;
if ( ! V_3 -> V_68 &&
F_24 ( & V_166 -> V_170 ) & V_66 )
V_166 -> V_298 = F_65 ( V_7 ) ;
if ( ! V_273 ) {
if ( F_166 ( V_3 , V_7 ) ||
V_42 -> V_299 . V_300 . V_301 || V_42 -> V_299 . V_300 . V_302 ||
V_42 -> V_299 . V_300 . V_303 || V_42 -> V_299 . V_300 . V_304 ) {
F_167 ( & V_7 -> V_305 ) ;
V_166 -> V_173 = V_7 ;
}
if ( V_275 ) {
V_273 = F_168 ( V_3 , V_7 , & V_154 -> V_306 ) ;
V_154 -> V_307 = V_272 . V_297 ;
goto V_308;
}
if ( V_272 . V_282 &&
V_106 . V_107 &&
( V_9 = F_74 ( V_3 , & V_48 , V_154 ) ) != NULL ) {
if ( ! F_169 ( V_154 , V_9 , true ) ) {
F_57 ( F_82 ( V_3 ) , V_309 ) ;
goto V_310;
}
}
else if ( ! V_311 &&
( V_312 - F_170 ( V_3 ) <
( V_312 >> 2 ) ) &&
! F_169 ( V_154 , V_9 , false ) ) {
F_171 ( V_313 L_6 ,
& V_166 -> V_170 , F_109 ( F_17 ( V_7 ) -> V_31 ) ) ;
goto V_310;
}
V_273 = F_14 ( V_7 ) ;
}
V_308:
F_67 ( V_154 ) -> V_156 = V_273 ;
if ( F_172 ( V_3 , V_7 , V_154 ) )
goto V_310;
if ( F_72 ( V_3 , V_9 , & V_48 , V_154 ,
(struct V_162 * ) & V_270 ,
F_173 ( V_7 ) ) ||
V_275 )
goto V_294;
F_67 ( V_154 ) -> V_314 = V_247 ;
F_67 ( V_154 ) -> V_315 = NULL ;
F_174 ( V_3 , V_154 , V_316 ) ;
return 0 ;
V_310:
F_175 ( V_9 ) ;
V_294:
F_176 ( V_154 ) ;
V_277:
return 0 ;
}
static struct V_2 * F_177 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_153 * V_154 ,
struct V_8 * V_9 )
{
struct V_165 * V_166 ;
struct V_41 * V_317 , * V_42 = F_6 ( V_3 ) ;
struct V_318 * V_319 ;
struct V_37 * V_320 ;
struct V_43 * V_321 ;
struct V_2 * V_322 ;
#ifdef F_28
struct V_1 * V_199 ;
#endif
struct V_47 V_48 ;
if ( V_7 -> V_196 == F_135 ( V_276 ) ) {
V_322 = F_178 ( V_3 , V_7 , V_154 , V_9 ) ;
if ( V_322 == NULL )
return NULL ;
V_319 = (struct V_318 * ) V_322 ;
F_5 ( V_322 ) -> V_323 = & V_319 -> V_324 ;
V_320 = F_5 ( V_322 ) ;
V_317 = F_6 ( V_322 ) ;
V_321 = F_19 ( V_322 ) ;
memcpy ( V_317 , V_42 , sizeof( struct V_41 ) ) ;
F_30 ( V_320 -> V_325 , & V_317 -> V_26 ) ;
F_30 ( V_320 -> V_92 , & V_317 -> V_25 ) ;
V_317 -> V_94 = V_317 -> V_25 ;
F_8 ( V_322 ) -> V_20 = & V_21 ;
V_322 -> V_84 = V_85 ;
#ifdef F_28
V_321 -> V_86 = & V_87 ;
#endif
V_317 -> V_326 = NULL ;
V_317 -> V_327 = NULL ;
V_317 -> V_328 = NULL ;
V_317 -> V_102 = NULL ;
V_317 -> V_329 = F_65 ( V_7 ) ;
V_317 -> V_330 = F_16 ( V_7 ) -> V_140 ;
V_317 -> V_331 = F_179 ( F_16 ( V_7 ) ) ;
F_46 ( V_322 , F_8 ( V_322 ) -> V_122 ) ;
return V_322 ;
}
V_166 = F_73 ( V_154 ) ;
if ( F_158 ( V_3 ) )
goto V_332;
if ( ! V_9 ) {
V_9 = F_74 ( V_3 , & V_48 , V_154 ) ;
if ( ! V_9 )
goto V_139;
}
V_322 = F_180 ( V_3 , V_154 , V_7 ) ;
if ( V_322 == NULL )
goto V_333;
V_322 -> V_104 = V_105 ;
F_37 ( V_322 , V_9 , NULL , NULL ) ;
F_2 ( V_322 , V_7 ) ;
V_319 = (struct V_318 * ) V_322 ;
F_5 ( V_322 ) -> V_323 = & V_319 -> V_324 ;
V_321 = F_19 ( V_322 ) ;
V_320 = F_5 ( V_322 ) ;
V_317 = F_6 ( V_322 ) ;
memcpy ( V_317 , V_42 , sizeof( struct V_41 ) ) ;
V_317 -> V_26 = V_166 -> V_170 ;
V_317 -> V_25 = V_166 -> V_169 ;
V_317 -> V_94 = V_166 -> V_169 ;
V_322 -> V_68 = V_166 -> V_298 ;
V_320 -> V_334 = NULL ;
V_317 -> V_326 = NULL ;
V_317 -> V_327 = NULL ;
V_317 -> V_299 . V_335 = V_42 -> V_299 . V_335 ;
V_317 -> V_328 = NULL ;
if ( V_166 -> V_173 != NULL ) {
V_317 -> V_328 = F_181 ( V_166 -> V_173 ,
F_182 ( V_3 , V_241 ) ) ;
F_183 ( V_166 -> V_173 ) ;
V_166 -> V_173 = NULL ;
if ( V_317 -> V_328 )
F_184 ( V_317 -> V_328 , V_322 ) ;
}
V_317 -> V_102 = NULL ;
V_317 -> V_329 = F_65 ( V_7 ) ;
V_317 -> V_330 = F_16 ( V_7 ) -> V_140 ;
V_317 -> V_331 = F_179 ( F_16 ( V_7 ) ) ;
if ( V_42 -> V_102 )
V_317 -> V_102 = F_185 ( V_322 , V_42 -> V_102 ) ;
F_8 ( V_322 ) -> V_76 = 0 ;
if ( V_317 -> V_102 )
F_8 ( V_322 ) -> V_76 = ( V_317 -> V_102 -> V_110 +
V_317 -> V_102 -> V_109 ) ;
F_186 ( V_322 ) ;
F_46 ( V_322 , F_45 ( V_9 ) ) ;
V_321 -> V_336 = F_187 ( V_9 ) ;
if ( F_19 ( V_3 ) -> V_69 . V_280 &&
F_19 ( V_3 ) -> V_69 . V_280 < V_321 -> V_336 )
V_321 -> V_336 = F_19 ( V_3 ) -> V_69 . V_280 ;
F_188 ( V_322 ) ;
F_189 ( V_322 , V_154 ) ;
V_321 -> V_337 = V_154 -> V_338 ;
V_320 -> V_325 = V_320 -> V_92 = V_103 ;
V_320 -> V_93 = V_103 ;
#ifdef F_28
if ( ( V_199 = F_1 ( V_3 , & V_317 -> V_26 ) ) != NULL ) {
F_92 ( V_322 , (union V_174 * ) & V_317 -> V_26 ,
V_54 , V_199 -> V_199 , V_199 -> V_339 ,
F_182 ( V_3 , V_241 ) ) ;
}
#endif
if ( F_190 ( V_3 , V_322 ) < 0 ) {
F_71 ( V_322 ) ;
goto V_139;
}
F_10 ( V_322 , NULL ) ;
return V_322 ;
V_332:
F_57 ( F_82 ( V_3 ) , V_340 ) ;
V_333:
F_175 ( V_9 ) ;
V_139:
F_57 ( F_82 ( V_3 ) , V_341 ) ;
return NULL ;
}
static T_2 F_191 ( struct V_6 * V_7 )
{
if ( V_7 -> V_212 == V_223 ) {
if ( ! F_12 ( V_7 -> V_24 , & F_16 ( V_7 ) -> V_25 ,
& F_16 ( V_7 ) -> V_26 , V_7 -> V_218 ) ) {
V_7 -> V_212 = V_224 ;
return 0 ;
}
}
V_7 -> V_218 = ~ F_120 ( F_12 ( V_7 -> V_24 ,
& F_16 ( V_7 ) -> V_25 ,
& F_16 ( V_7 ) -> V_26 , 0 ) ) ;
if ( V_7 -> V_24 <= 76 ) {
return F_192 ( V_7 ) ;
}
return 0 ;
}
static int V_89 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_41 * V_42 = F_6 ( V_3 ) ;
struct V_43 * V_44 ;
struct V_6 * V_342 = NULL ;
if ( V_7 -> V_196 == F_135 ( V_276 ) )
return V_85 ( V_3 , V_7 ) ;
#ifdef F_28
if ( F_106 ( V_3 , V_7 ) )
goto V_343;
#endif
if ( F_193 ( V_3 , V_7 ) )
goto V_343;
if ( V_42 -> V_299 . V_335 )
V_342 = F_181 ( V_7 , F_182 ( V_3 , V_241 ) ) ;
if ( V_3 -> V_18 == V_344 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
F_194 ( V_3 , V_7 ) ;
if ( V_9 ) {
if ( F_5 ( V_3 ) -> V_13 != V_7 -> V_14 ||
V_9 -> V_149 -> V_214 ( V_9 , V_42 -> V_16 ) == NULL ) {
F_175 ( V_9 ) ;
V_3 -> V_12 = NULL ;
}
}
if ( F_195 ( V_3 , V_7 , F_17 ( V_7 ) , V_7 -> V_24 ) )
goto V_345;
if ( V_342 )
goto V_346;
return 0 ;
}
if ( V_7 -> V_24 < F_196 ( V_7 ) || F_197 ( V_7 ) )
goto V_347;
if ( V_3 -> V_18 == V_143 ) {
struct V_2 * V_268 = F_148 ( V_3 , V_7 ) ;
if ( ! V_268 )
goto V_343;
if( V_268 != V_3 ) {
F_194 ( V_268 , V_7 ) ;
if ( F_198 ( V_3 , V_268 , V_7 ) )
goto V_345;
if ( V_342 )
F_199 ( V_342 ) ;
return 0 ;
}
} else
F_194 ( V_3 , V_7 ) ;
if ( F_200 ( V_3 , V_7 , F_17 ( V_7 ) , V_7 -> V_24 ) )
goto V_345;
if ( V_342 )
goto V_346;
return 0 ;
V_345:
F_138 ( V_3 , V_7 ) ;
V_343:
if ( V_342 )
F_199 ( V_342 ) ;
F_84 ( V_7 ) ;
return 0 ;
V_347:
F_81 ( F_82 ( V_3 ) , V_348 ) ;
goto V_343;
V_346:
V_44 = F_19 ( V_3 ) ;
if ( F_154 ( V_342 ) -> V_349 == V_44 -> V_350 &&
! ( ( 1 << V_3 -> V_18 ) & ( V_120 | V_119 ) ) ) {
if ( V_42 -> V_299 . V_300 . V_301 || V_42 -> V_299 . V_300 . V_302 )
V_42 -> V_329 = F_65 ( V_342 ) ;
if ( V_42 -> V_299 . V_300 . V_303 || V_42 -> V_299 . V_300 . V_304 )
V_42 -> V_330 = F_16 ( V_342 ) -> V_140 ;
if ( V_42 -> V_299 . V_300 . V_351 )
V_42 -> V_331 = F_179 ( F_16 ( V_7 ) ) ;
if ( F_166 ( V_3 , V_342 ) ) {
F_184 ( V_342 , V_3 ) ;
V_342 = F_201 ( & V_42 -> V_328 , V_342 ) ;
} else {
F_199 ( V_342 ) ;
V_342 = F_201 ( & V_42 -> V_328 , NULL ) ;
}
}
F_84 ( V_342 ) ;
return 0 ;
}
static int F_202 ( struct V_6 * V_7 )
{
const struct V_113 * V_129 ;
const struct V_114 * V_127 ;
struct V_2 * V_3 ;
int V_352 ;
struct V_131 * V_131 = F_49 ( V_7 -> V_132 ) ;
if ( V_7 -> V_353 != V_354 )
goto V_355;
F_81 ( V_131 , V_356 ) ;
if ( ! F_115 ( V_7 , sizeof( struct V_113 ) ) )
goto V_355;
V_129 = F_17 ( V_7 ) ;
if ( V_129 -> V_204 < sizeof( struct V_113 ) / 4 )
goto V_357;
if ( ! F_115 ( V_7 , V_129 -> V_204 * 4 ) )
goto V_355;
if ( ! F_203 ( V_7 ) && F_191 ( V_7 ) )
goto V_357;
V_129 = F_17 ( V_7 ) ;
V_127 = F_16 ( V_7 ) ;
F_154 ( V_7 ) -> V_130 = F_58 ( V_129 -> V_130 ) ;
F_154 ( V_7 ) -> V_349 = ( F_154 ( V_7 ) -> V_130 + V_129 -> V_254 + V_129 -> V_255 +
V_7 -> V_24 - V_129 -> V_204 * 4 ) ;
F_154 ( V_7 ) -> V_242 = F_58 ( V_129 -> V_242 ) ;
F_154 ( V_7 ) -> V_274 = 0 ;
F_154 ( V_7 ) -> V_358 = F_204 ( V_127 ) ;
F_154 ( V_7 ) -> V_359 = 0 ;
V_3 = F_205 ( & V_133 , V_7 , V_129 -> V_31 , V_129 -> V_30 ) ;
if ( ! V_3 )
goto V_360;
V_361:
if ( V_3 -> V_18 == V_136 )
goto V_362;
if ( V_127 -> V_140 < F_6 ( V_3 ) -> V_141 ) {
F_57 ( V_131 , V_142 ) ;
goto V_363;
}
if ( ! F_206 ( V_3 , V_364 , V_7 ) )
goto V_363;
if ( F_193 ( V_3 , V_7 ) )
goto V_363;
V_7 -> V_132 = NULL ;
F_207 ( V_3 ) ;
V_352 = 0 ;
if ( ! F_56 ( V_3 ) ) {
#ifdef F_208
struct V_43 * V_44 = F_19 ( V_3 ) ;
if ( ! V_44 -> V_365 . V_366 && V_44 -> V_365 . V_367 )
V_44 -> V_365 . V_366 = F_209 () ;
if ( V_44 -> V_365 . V_366 )
V_352 = V_89 ( V_3 , V_7 ) ;
else
#endif
{
if ( ! F_210 ( V_3 , V_7 ) )
V_352 = V_89 ( V_3 , V_7 ) ;
}
} else if ( F_211 ( F_212 ( V_3 , V_7 ,
V_3 -> V_368 + V_3 -> V_369 ) ) ) {
F_70 ( V_3 ) ;
F_57 ( V_131 , V_370 ) ;
goto V_363;
}
F_70 ( V_3 ) ;
F_71 ( V_3 ) ;
return V_352 ? - 1 : 0 ;
V_360:
if ( ! F_206 ( NULL , V_364 , V_7 ) )
goto V_355;
if ( V_7 -> V_24 < ( V_129 -> V_204 << 2 ) || F_197 ( V_7 ) ) {
V_357:
F_81 ( V_131 , V_348 ) ;
} else {
F_138 ( NULL , V_7 ) ;
}
V_355:
F_84 ( V_7 ) ;
return 0 ;
V_363:
F_71 ( V_3 ) ;
goto V_355;
V_362:
if ( ! F_206 ( NULL , V_364 , V_7 ) ) {
F_53 ( F_54 ( V_3 ) ) ;
goto V_355;
}
if ( V_7 -> V_24 < ( V_129 -> V_204 << 2 ) || F_197 ( V_7 ) ) {
F_81 ( V_131 , V_348 ) ;
F_53 ( F_54 ( V_3 ) ) ;
goto V_355;
}
switch ( F_213 ( F_54 ( V_3 ) , V_7 , V_129 ) ) {
case V_371 :
{
struct V_2 * V_372 ;
V_372 = F_140 ( F_49 ( V_7 -> V_132 ) , & V_133 ,
& F_16 ( V_7 ) -> V_26 ,
F_109 ( V_129 -> V_30 ) , F_65 ( V_7 ) ) ;
if ( V_372 != NULL ) {
struct V_256 * V_257 = F_54 ( V_3 ) ;
F_214 ( V_257 , & V_106 ) ;
F_53 ( V_257 ) ;
V_3 = V_372 ;
goto V_361;
}
}
case V_373 :
F_144 ( V_3 , V_7 ) ;
break;
case V_374 :
goto V_360;
case V_375 : ;
}
goto V_355;
}
static void F_215 ( struct V_6 * V_7 )
{
const struct V_114 * V_127 ;
const struct V_113 * V_129 ;
struct V_2 * V_3 ;
if ( V_7 -> V_353 != V_354 )
return;
if ( ! F_115 ( V_7 , F_126 ( V_7 ) + sizeof( struct V_113 ) ) )
return;
V_127 = F_16 ( V_7 ) ;
V_129 = F_17 ( V_7 ) ;
if ( V_129 -> V_204 < sizeof( struct V_113 ) / 4 )
return;
V_3 = F_150 ( F_49 ( V_7 -> V_132 ) , & V_133 ,
& V_127 -> V_25 , V_129 -> V_31 ,
& V_127 -> V_26 , F_109 ( V_129 -> V_30 ) ,
F_65 ( V_7 ) ) ;
if ( V_3 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_376 = V_377 ;
if ( V_3 -> V_18 != V_136 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
struct V_37 * V_40 = F_5 ( V_3 ) ;
if ( V_9 )
V_9 = F_216 ( V_9 , F_6 ( V_3 ) -> V_16 ) ;
if ( V_9 &&
V_40 -> V_13 == V_7 -> V_14 )
F_217 ( V_7 , V_9 ) ;
}
}
}
static int F_218 ( struct V_2 * V_3 )
{
struct V_39 * V_40 = F_8 ( V_3 ) ;
F_219 ( V_3 ) ;
V_40 -> V_20 = & V_88 ;
#ifdef F_28
F_19 ( V_3 ) -> V_86 = & V_90 ;
#endif
return 0 ;
}
static void F_220 ( struct V_2 * V_3 )
{
F_221 ( V_3 ) ;
F_222 ( V_3 ) ;
}
static void F_223 ( struct V_378 * V_130 ,
const struct V_2 * V_3 , struct V_153 * V_154 , int V_379 , T_11 V_380 )
{
int V_381 = V_154 -> V_382 - V_383 ;
const struct V_4 * V_384 = & F_73 ( V_154 ) -> V_169 ;
const struct V_4 * V_30 = & F_73 ( V_154 ) -> V_170 ;
if ( V_381 < 0 )
V_381 = 0 ;
F_224 ( V_130 ,
L_7
L_8 ,
V_379 ,
V_384 -> V_29 [ 0 ] , V_384 -> V_29 [ 1 ] ,
V_384 -> V_29 [ 2 ] , V_384 -> V_29 [ 3 ] ,
F_109 ( F_225 ( V_154 ) -> V_385 ) ,
V_30 -> V_29 [ 0 ] , V_30 -> V_29 [ 1 ] ,
V_30 -> V_29 [ 2 ] , V_30 -> V_29 [ 3 ] ,
F_109 ( F_225 ( V_154 ) -> V_386 ) ,
V_157 ,
0 , 0 ,
1 ,
F_226 ( V_381 ) ,
V_154 -> V_338 ,
F_227 ( F_228 ( V_130 ) , V_380 ) ,
0 ,
0 ,
0 , V_154 ) ;
}
static void F_229 ( struct V_378 * V_130 , struct V_2 * V_387 , int V_379 )
{
const struct V_4 * V_30 , * V_384 ;
T_12 V_388 , V_389 ;
int V_390 ;
unsigned long V_391 ;
const struct V_37 * V_38 = F_5 ( V_387 ) ;
const struct V_43 * V_44 = F_19 ( V_387 ) ;
const struct V_39 * V_40 = F_8 ( V_387 ) ;
const struct V_41 * V_42 = F_6 ( V_387 ) ;
V_30 = & V_42 -> V_26 ;
V_384 = & V_42 -> V_94 ;
V_388 = F_109 ( V_38 -> V_115 ) ;
V_389 = F_109 ( V_38 -> V_101 ) ;
if ( V_40 -> V_392 == V_393 ) {
V_390 = 1 ;
V_391 = V_40 -> V_394 ;
} else if ( V_40 -> V_392 == V_395 ) {
V_390 = 4 ;
V_391 = V_40 -> V_394 ;
} else if ( F_230 ( & V_387 -> V_396 ) ) {
V_390 = 2 ;
V_391 = V_387 -> V_396 . V_382 ;
} else {
V_390 = 0 ;
V_391 = V_383 ;
}
F_224 ( V_130 ,
L_7
L_9 ,
V_379 ,
V_384 -> V_29 [ 0 ] , V_384 -> V_29 [ 1 ] ,
V_384 -> V_29 [ 2 ] , V_384 -> V_29 [ 3 ] , V_389 ,
V_30 -> V_29 [ 0 ] , V_30 -> V_29 [ 1 ] ,
V_30 -> V_29 [ 2 ] , V_30 -> V_29 [ 3 ] , V_388 ,
V_387 -> V_18 ,
V_44 -> V_72 - V_44 -> V_144 ,
( V_387 -> V_18 == V_143 ) ? V_387 -> V_397 : ( V_44 -> V_350 - V_44 -> V_398 ) ,
V_390 ,
F_231 ( V_391 - V_383 ) ,
V_40 -> V_399 ,
F_227 ( F_228 ( V_130 ) , F_232 ( V_387 ) ) ,
V_40 -> V_400 ,
F_233 ( V_387 ) ,
F_234 ( & V_387 -> V_401 ) , V_387 ,
F_226 ( V_40 -> V_402 ) ,
F_226 ( V_40 -> V_403 . V_404 ) ,
( V_40 -> V_403 . V_405 << 1 ) | V_40 -> V_403 . V_406 ,
V_44 -> V_407 ,
F_235 ( V_44 ) ? - 1 : V_44 -> V_408
) ;
}
static void F_236 ( struct V_378 * V_130 ,
struct V_256 * V_257 , int V_379 )
{
const struct V_4 * V_30 , * V_384 ;
T_12 V_388 , V_389 ;
const struct V_409 * V_410 = F_237 ( (struct V_2 * ) V_257 ) ;
long V_411 = V_257 -> V_412 - V_383 ;
V_30 = & V_410 -> V_413 ;
V_384 = & V_410 -> V_414 ;
V_388 = F_109 ( V_257 -> V_415 ) ;
V_389 = F_109 ( V_257 -> V_416 ) ;
F_224 ( V_130 ,
L_7
L_8 ,
V_379 ,
V_384 -> V_29 [ 0 ] , V_384 -> V_29 [ 1 ] ,
V_384 -> V_29 [ 2 ] , V_384 -> V_29 [ 3 ] , V_389 ,
V_30 -> V_29 [ 0 ] , V_30 -> V_29 [ 1 ] ,
V_30 -> V_29 [ 2 ] , V_30 -> V_29 [ 3 ] , V_388 ,
V_257 -> V_417 , 0 , 0 ,
3 , F_231 ( V_411 ) , 0 , 0 , 0 , 0 ,
F_234 ( & V_257 -> V_418 ) , V_257 ) ;
}
static int F_238 ( struct V_378 * V_130 , void * V_419 )
{
struct V_420 * V_421 ;
if ( V_419 == V_422 ) {
F_239 ( V_130 ,
L_10
L_11
L_12
L_13
L_14 ) ;
goto V_139;
}
V_421 = V_130 -> V_423 ;
switch ( V_421 -> V_424 ) {
case V_425 :
case V_426 :
F_229 ( V_130 , V_419 , V_421 -> V_427 ) ;
break;
case V_428 :
F_223 ( V_130 , V_421 -> V_429 , V_419 , V_421 -> V_427 , V_421 -> V_380 ) ;
break;
case V_430 :
F_236 ( V_130 , V_419 , V_421 -> V_427 ) ;
break;
}
V_139:
return 0 ;
}
int T_13 F_240 ( struct V_131 * V_131 )
{
return F_241 ( V_131 , & V_431 ) ;
}
void F_242 ( struct V_131 * V_131 )
{
F_243 ( V_131 , & V_431 ) ;
}
static int T_13 F_244 ( struct V_131 * V_131 )
{
return F_245 ( & V_131 -> V_235 . F_19 , V_432 ,
V_433 , V_28 , V_131 ) ;
}
static void T_14 F_246 ( struct V_131 * V_131 )
{
F_247 ( V_131 -> V_235 . F_19 ) ;
}
static void T_14 F_248 ( struct V_434 * V_435 )
{
F_249 ( & V_133 , & V_106 , V_54 ) ;
}
int T_15 F_250 ( void )
{
int V_352 ;
V_352 = F_251 ( & V_436 , V_28 ) ;
if ( V_352 )
goto V_139;
V_352 = F_252 ( & V_437 ) ;
if ( V_352 )
goto V_438;
V_352 = F_253 ( & V_439 ) ;
if ( V_352 )
goto V_440;
V_139:
return V_352 ;
V_438:
F_254 ( & V_436 , V_28 ) ;
V_440:
F_255 ( & V_437 ) ;
goto V_139;
}
void F_256 ( void )
{
F_257 ( & V_439 ) ;
F_255 ( & V_437 ) ;
F_254 ( & V_436 , V_28 ) ;
}
