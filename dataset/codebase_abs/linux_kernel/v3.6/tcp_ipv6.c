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
V_7 = F_75 ( V_3 , V_9 , V_154 , V_163 ) ;
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
switch ( V_7 -> V_212 ) {
case V_221 :
if ( ! F_12 ( F_118 ( V_7 ) , & V_220 -> V_25 , & V_220 -> V_26 ,
V_7 -> V_218 ) ) {
V_7 -> V_212 = V_222 ;
break;
}
case V_223 :
F_119 ( V_7 ) -> V_224 = 1 ;
return NULL ;
}
return F_120 ( V_216 , V_7 ) ;
}
static int F_121 ( struct V_6 * V_7 )
{
const struct V_114 * V_220 = F_16 ( V_7 ) ;
struct V_113 * V_129 = F_17 ( V_7 ) ;
V_129 -> V_214 = ~ F_12 ( V_7 -> V_24 - F_122 ( V_7 ) ,
& V_220 -> V_25 , & V_220 -> V_26 , 0 ) ;
F_123 ( V_7 ) -> V_225 = V_105 ;
return F_124 ( V_7 ) ;
}
static void F_125 ( struct V_6 * V_7 , T_5 V_130 , T_5 V_226 , T_5 V_227 ,
T_5 V_228 , struct V_1 * V_199 , int V_229 , T_6 V_171 )
{
const struct V_113 * V_129 = F_17 ( V_7 ) ;
struct V_113 * V_230 ;
struct V_6 * V_231 ;
struct V_47 V_48 ;
struct V_131 * V_131 = F_49 ( F_3 ( V_7 ) -> V_132 ) ;
struct V_2 * V_232 = V_131 -> V_233 . F_19 ;
unsigned int V_234 = sizeof( struct V_113 ) ;
struct V_8 * V_9 ;
T_7 * V_235 ;
if ( V_228 )
V_234 += V_236 ;
#ifdef F_28
if ( V_199 )
V_234 += V_237 ;
#endif
V_231 = F_126 ( V_238 + sizeof( struct V_114 ) + V_234 ,
V_239 ) ;
if ( V_231 == NULL )
return;
F_127 ( V_231 , V_238 + sizeof( struct V_114 ) + V_234 ) ;
V_230 = (struct V_113 * ) F_128 ( V_231 , V_234 ) ;
F_129 ( V_231 ) ;
memset ( V_230 , 0 , sizeof( * V_230 ) ) ;
V_230 -> V_30 = V_129 -> V_31 ;
V_230 -> V_31 = V_129 -> V_30 ;
V_230 -> V_204 = V_234 / 4 ;
V_230 -> V_130 = F_130 ( V_130 ) ;
V_230 -> V_240 = F_130 ( V_226 ) ;
V_230 -> V_226 = ! V_229 || ! V_129 -> V_226 ;
V_230 -> V_229 = V_229 ;
V_230 -> V_241 = F_131 ( V_227 ) ;
V_235 = ( T_7 * ) ( V_230 + 1 ) ;
if ( V_228 ) {
* V_235 ++ = F_130 ( ( V_242 << 24 ) | ( V_242 << 16 ) |
( V_243 << 8 ) | V_244 ) ;
* V_235 ++ = F_130 ( V_245 ) ;
* V_235 ++ = F_130 ( V_228 ) ;
}
#ifdef F_28
if ( V_199 ) {
* V_235 ++ = F_130 ( ( V_242 << 24 ) | ( V_242 << 16 ) |
( V_246 << 8 ) | V_247 ) ;
F_97 ( ( T_10 * ) V_235 , V_199 ,
& F_16 ( V_7 ) -> V_25 ,
& F_16 ( V_7 ) -> V_26 , V_230 ) ;
}
#endif
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_48 . V_26 = F_16 ( V_7 ) -> V_25 ;
V_48 . V_25 = F_16 ( V_7 ) -> V_26 ;
V_231 -> V_212 = V_213 ;
V_231 -> V_218 = 0 ;
F_76 ( V_231 , & V_48 . V_25 , & V_48 . V_26 ) ;
V_48 . V_95 = V_28 ;
V_48 . V_96 = F_65 ( V_7 ) ;
V_48 . V_99 = V_230 -> V_30 ;
V_48 . V_100 = V_230 -> V_31 ;
F_132 ( V_7 , F_33 ( & V_48 ) ) ;
V_9 = F_34 ( V_232 , & V_48 , NULL , false ) ;
if ( ! F_35 ( V_9 ) ) {
F_133 ( V_231 , V_9 ) ;
F_78 ( V_232 , V_231 , & V_48 , NULL , V_171 ) ;
F_81 ( V_131 , V_248 ) ;
if ( V_229 )
F_81 ( V_131 , V_249 ) ;
return;
}
F_84 ( V_231 ) ;
}
static void F_134 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
const struct V_113 * V_129 = F_17 ( V_7 ) ;
T_5 V_130 = 0 , V_240 = 0 ;
struct V_1 * V_199 = NULL ;
#ifdef F_28
const T_10 * V_206 = NULL ;
struct V_114 * V_219 = F_16 ( V_7 ) ;
unsigned char V_209 [ 16 ] ;
int V_208 ;
struct V_2 * V_250 = NULL ;
#endif
if ( V_129 -> V_229 )
return;
if ( ! F_135 ( V_7 ) )
return;
#ifdef F_28
V_206 = F_107 ( V_129 ) ;
if ( ! V_3 && V_206 ) {
V_250 = F_136 ( F_49 ( F_3 ( V_7 ) -> V_132 ) ,
& V_133 , & V_219 -> V_26 ,
F_109 ( V_129 -> V_31 ) , F_65 ( V_7 ) ) ;
if ( ! V_250 )
return;
F_137 () ;
V_199 = F_1 ( V_250 , & V_219 -> V_25 ) ;
if ( ! V_199 )
goto V_251;
V_208 = F_104 ( V_209 , V_199 , NULL , NULL , V_7 ) ;
if ( V_208 || memcmp ( V_206 , V_209 , 16 ) != 0 )
goto V_251;
} else {
V_199 = V_3 ? F_1 ( V_3 , & V_219 -> V_25 ) : NULL ;
}
#endif
if ( V_129 -> V_226 )
V_130 = F_58 ( V_129 -> V_240 ) ;
else
V_240 = F_58 ( V_129 -> V_130 ) + V_129 -> V_252 + V_129 -> V_253 + V_7 -> V_24 -
( V_129 -> V_204 << 2 ) ;
F_125 ( V_7 , V_130 , V_240 , 0 , 0 , V_199 , 1 , 0 ) ;
#ifdef F_28
V_251:
if ( V_250 ) {
F_138 () ;
F_71 ( V_250 ) ;
}
#endif
}
static void F_139 ( struct V_6 * V_7 , T_5 V_130 , T_5 V_226 , T_5 V_227 , T_5 V_228 ,
struct V_1 * V_199 , T_6 V_171 )
{
F_125 ( V_7 , V_130 , V_226 , V_227 , V_228 , V_199 , 0 , V_171 ) ;
}
static void F_140 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_254 * V_255 = F_54 ( V_3 ) ;
struct V_256 * V_257 = F_141 ( V_3 ) ;
F_139 ( V_7 , V_257 -> V_258 , V_257 -> V_259 ,
V_257 -> V_260 >> V_255 -> V_261 ,
V_257 -> V_262 , F_142 ( V_257 ) ,
V_255 -> V_263 ) ;
F_53 ( V_255 ) ;
}
static void F_143 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_153 * V_154 )
{
F_139 ( V_7 , F_67 ( V_154 ) -> V_156 + 1 , F_67 ( V_154 ) -> V_264 + 1 , V_154 -> V_265 , V_154 -> V_71 ,
F_1 ( V_3 , & F_16 ( V_7 ) -> V_26 ) , 0 ) ;
}
static struct V_2 * F_144 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_153 * V_154 , * * V_155 ;
const struct V_113 * V_129 = F_17 ( V_7 ) ;
struct V_2 * V_266 ;
V_154 = F_64 ( V_3 , & V_155 , V_129 -> V_31 ,
& F_16 ( V_7 ) -> V_25 ,
& F_16 ( V_7 ) -> V_26 , F_65 ( V_7 ) ) ;
if ( V_154 )
return F_145 ( V_3 , V_7 , V_154 , V_155 ) ;
V_266 = F_146 ( F_82 ( V_3 ) , & V_133 ,
& F_16 ( V_7 ) -> V_25 , V_129 -> V_31 ,
& F_16 ( V_7 ) -> V_26 , F_109 ( V_129 -> V_30 ) , F_65 ( V_7 ) ) ;
if ( V_266 ) {
if ( V_266 -> V_18 != V_136 ) {
F_55 ( V_266 ) ;
return V_266 ;
}
F_53 ( F_54 ( V_266 ) ) ;
return NULL ;
}
#ifdef F_147
if ( ! V_129 -> V_252 )
V_3 = F_148 ( V_3 , V_7 ) ;
#endif
return V_3 ;
}
static int F_149 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_267 V_268 ;
struct V_269 V_270 ;
const T_6 * V_206 ;
struct V_153 * V_154 ;
struct V_165 * V_166 ;
struct V_41 * V_42 = F_6 ( V_3 ) ;
struct V_43 * V_44 = F_19 ( V_3 ) ;
T_4 V_271 = F_150 ( V_7 ) -> V_272 ;
struct V_8 * V_9 = NULL ;
struct V_47 V_48 ;
bool V_273 = false ;
if ( V_7 -> V_196 == F_131 ( V_274 ) )
return F_151 ( V_3 , V_7 ) ;
if ( ! F_135 ( V_7 ) )
goto V_275;
if ( F_152 ( V_3 ) && ! V_271 ) {
V_273 = F_153 ( V_3 , V_7 , L_5 ) ;
if ( ! V_273 )
goto V_275;
}
if ( F_154 ( V_3 ) && F_155 ( V_3 ) > 1 )
goto V_275;
V_154 = F_156 ( & V_276 ) ;
if ( V_154 == NULL )
goto V_275;
#ifdef F_28
F_67 ( V_154 ) -> V_86 = & V_277 ;
#endif
F_157 ( & V_270 ) ;
V_270 . V_111 = V_112 - sizeof( struct V_113 ) - sizeof( struct V_114 ) ;
V_270 . V_278 = V_44 -> V_69 . V_278 ;
F_158 ( V_7 , & V_270 , & V_206 , 0 , NULL ) ;
if ( V_270 . V_279 > 0 &&
V_270 . V_280 &&
! V_44 -> V_69 . V_281 &&
( V_282 > 0 ||
( V_44 -> V_283 != NULL &&
V_44 -> V_283 -> V_284 > 0 ) ) ) {
T_6 * V_285 ;
T_5 * V_286 ;
T_5 * V_287 = & V_268 . V_288 [ V_289 ] ;
int V_290 = V_270 . V_279 - V_291 ;
if ( F_159 ( & V_268 . V_288 [ 0 ] ) != 0 )
goto V_292;
V_286 = ( V_293 T_5 * ) & F_16 ( V_7 ) -> V_26 . V_29 [ 0 ] ;
* V_287 ++ ^= * V_286 ++ ;
* V_287 ++ ^= * V_286 ++ ;
* V_287 ++ ^= * V_286 ++ ;
* V_287 ++ ^= * V_286 ++ ;
V_286 = ( V_293 T_5 * ) & F_16 ( V_7 ) -> V_25 . V_29 [ 0 ] ;
* V_287 ++ ^= * V_286 ++ ;
* V_287 ++ ^= * V_286 ++ ;
* V_287 ++ ^= * V_286 ++ ;
* V_287 ++ ^= * V_286 ++ ;
V_285 = ( T_6 * ) V_287 ;
while ( V_290 -- > 0 )
* V_285 ++ ^= * V_206 ++ ;
V_273 = false ;
V_268 . V_281 = 0 ;
V_268 . V_279 = V_270 . V_279 ;
} else if ( ! V_44 -> V_69 . V_294 ) {
V_268 . V_281 = 1 ;
V_268 . V_279 = 0 ;
} else {
goto V_292;
}
V_268 . V_294 = V_44 -> V_69 . V_294 ;
if ( V_273 && ! V_270 . V_280 )
F_157 ( & V_270 ) ;
V_270 . V_295 = V_270 . V_280 ;
F_160 ( V_154 , & V_270 , V_7 ) ;
V_166 = F_73 ( V_154 ) ;
V_166 -> V_170 = F_16 ( V_7 ) -> V_25 ;
V_166 -> V_169 = F_16 ( V_7 ) -> V_26 ;
if ( ! V_273 || V_270 . V_295 )
F_161 ( V_154 , V_7 ) ;
V_166 -> V_296 = V_3 -> V_68 ;
if ( ! V_3 -> V_68 &&
F_24 ( & V_166 -> V_170 ) & V_66 )
V_166 -> V_296 = F_65 ( V_7 ) ;
if ( ! V_271 ) {
if ( F_162 ( V_3 , V_7 ) ||
V_42 -> V_297 . V_298 . V_299 || V_42 -> V_297 . V_298 . V_300 ||
V_42 -> V_297 . V_298 . V_301 || V_42 -> V_297 . V_298 . V_302 ) {
F_163 ( & V_7 -> V_303 ) ;
V_166 -> V_173 = V_7 ;
}
if ( V_273 ) {
V_271 = F_164 ( V_3 , V_7 , & V_154 -> V_304 ) ;
V_154 -> V_305 = V_270 . V_295 ;
goto V_306;
}
if ( V_270 . V_280 &&
V_106 . V_107 &&
( V_9 = F_74 ( V_3 , & V_48 , V_154 ) ) != NULL ) {
if ( ! F_165 ( V_154 , V_9 , true ) ) {
F_57 ( F_82 ( V_3 ) , V_307 ) ;
goto V_308;
}
}
else if ( ! V_309 &&
( V_310 - F_166 ( V_3 ) <
( V_310 >> 2 ) ) &&
! F_165 ( V_154 , V_9 , false ) ) {
F_167 ( V_311 L_6 ,
& V_166 -> V_170 , F_109 ( F_17 ( V_7 ) -> V_31 ) ) ;
goto V_308;
}
V_271 = F_14 ( V_7 ) ;
}
V_306:
F_67 ( V_154 ) -> V_156 = V_271 ;
F_67 ( V_154 ) -> V_312 = V_245 ;
if ( F_168 ( V_3 , V_7 , V_154 ) )
goto V_308;
if ( F_72 ( V_3 , V_9 , & V_48 , V_154 ,
(struct V_162 * ) & V_268 ,
F_169 ( V_7 ) ) ||
V_273 )
goto V_292;
F_170 ( V_3 , V_154 , V_313 ) ;
return 0 ;
V_308:
F_171 ( V_9 ) ;
V_292:
F_172 ( V_154 ) ;
V_275:
return 0 ;
}
static struct V_2 * F_173 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_153 * V_154 ,
struct V_8 * V_9 )
{
struct V_165 * V_166 ;
struct V_41 * V_314 , * V_42 = F_6 ( V_3 ) ;
struct V_315 * V_316 ;
struct V_37 * V_317 ;
struct V_43 * V_318 ;
struct V_2 * V_319 ;
#ifdef F_28
struct V_1 * V_199 ;
#endif
struct V_47 V_48 ;
if ( V_7 -> V_196 == F_131 ( V_274 ) ) {
V_319 = F_174 ( V_3 , V_7 , V_154 , V_9 ) ;
if ( V_319 == NULL )
return NULL ;
V_316 = (struct V_315 * ) V_319 ;
F_5 ( V_319 ) -> V_320 = & V_316 -> V_321 ;
V_317 = F_5 ( V_319 ) ;
V_314 = F_6 ( V_319 ) ;
V_318 = F_19 ( V_319 ) ;
memcpy ( V_314 , V_42 , sizeof( struct V_41 ) ) ;
F_30 ( V_317 -> V_322 , & V_314 -> V_26 ) ;
F_30 ( V_317 -> V_92 , & V_314 -> V_25 ) ;
V_314 -> V_94 = V_314 -> V_25 ;
F_8 ( V_319 ) -> V_20 = & V_21 ;
V_319 -> V_84 = V_85 ;
#ifdef F_28
V_318 -> V_86 = & V_87 ;
#endif
V_314 -> V_323 = NULL ;
V_314 -> V_324 = NULL ;
V_314 -> V_325 = NULL ;
V_314 -> V_102 = NULL ;
V_314 -> V_326 = F_65 ( V_7 ) ;
V_314 -> V_327 = F_16 ( V_7 ) -> V_140 ;
V_314 -> V_328 = F_175 ( F_16 ( V_7 ) ) ;
F_46 ( V_319 , F_8 ( V_319 ) -> V_122 ) ;
return V_319 ;
}
V_166 = F_73 ( V_154 ) ;
if ( F_154 ( V_3 ) )
goto V_329;
if ( ! V_9 ) {
V_9 = F_74 ( V_3 , & V_48 , V_154 ) ;
if ( ! V_9 )
goto V_139;
}
V_319 = F_176 ( V_3 , V_154 , V_7 ) ;
if ( V_319 == NULL )
goto V_330;
V_319 -> V_104 = V_105 ;
F_37 ( V_319 , V_9 , NULL , NULL ) ;
F_2 ( V_319 , V_7 ) ;
V_316 = (struct V_315 * ) V_319 ;
F_5 ( V_319 ) -> V_320 = & V_316 -> V_321 ;
V_318 = F_19 ( V_319 ) ;
V_317 = F_5 ( V_319 ) ;
V_314 = F_6 ( V_319 ) ;
memcpy ( V_314 , V_42 , sizeof( struct V_41 ) ) ;
V_314 -> V_26 = V_166 -> V_170 ;
V_314 -> V_25 = V_166 -> V_169 ;
V_314 -> V_94 = V_166 -> V_169 ;
V_319 -> V_68 = V_166 -> V_296 ;
V_317 -> V_331 = NULL ;
V_314 -> V_323 = NULL ;
V_314 -> V_324 = NULL ;
V_314 -> V_297 . V_332 = V_42 -> V_297 . V_332 ;
V_314 -> V_325 = NULL ;
if ( V_166 -> V_173 != NULL ) {
V_314 -> V_325 = F_177 ( V_166 -> V_173 ,
F_178 ( V_3 , V_239 ) ) ;
F_179 ( V_166 -> V_173 ) ;
V_166 -> V_173 = NULL ;
if ( V_314 -> V_325 )
F_180 ( V_314 -> V_325 , V_319 ) ;
}
V_314 -> V_102 = NULL ;
V_314 -> V_326 = F_65 ( V_7 ) ;
V_314 -> V_327 = F_16 ( V_7 ) -> V_140 ;
V_314 -> V_328 = F_175 ( F_16 ( V_7 ) ) ;
if ( V_42 -> V_102 )
V_314 -> V_102 = F_181 ( V_319 , V_42 -> V_102 ) ;
F_8 ( V_319 ) -> V_76 = 0 ;
if ( V_314 -> V_102 )
F_8 ( V_319 ) -> V_76 = ( V_314 -> V_102 -> V_110 +
V_314 -> V_102 -> V_109 ) ;
F_182 ( V_319 ) ;
F_46 ( V_319 , F_45 ( V_9 ) ) ;
V_318 -> V_333 = F_183 ( V_9 ) ;
if ( F_19 ( V_3 ) -> V_69 . V_278 &&
F_19 ( V_3 ) -> V_69 . V_278 < V_318 -> V_333 )
V_318 -> V_333 = F_19 ( V_3 ) -> V_69 . V_278 ;
F_184 ( V_319 ) ;
if ( F_67 ( V_154 ) -> V_312 )
F_185 ( V_319 ,
V_245 - F_67 ( V_154 ) -> V_312 ) ;
V_318 -> V_334 = V_154 -> V_335 ;
V_317 -> V_322 = V_317 -> V_92 = V_103 ;
V_317 -> V_93 = V_103 ;
#ifdef F_28
if ( ( V_199 = F_1 ( V_3 , & V_314 -> V_26 ) ) != NULL ) {
F_92 ( V_319 , (union V_174 * ) & V_314 -> V_26 ,
V_54 , V_199 -> V_199 , V_199 -> V_336 ,
F_178 ( V_3 , V_239 ) ) ;
}
#endif
if ( F_186 ( V_3 , V_319 ) < 0 ) {
F_71 ( V_319 ) ;
goto V_139;
}
F_10 ( V_319 , NULL ) ;
return V_319 ;
V_329:
F_57 ( F_82 ( V_3 ) , V_337 ) ;
V_330:
F_171 ( V_9 ) ;
V_139:
F_57 ( F_82 ( V_3 ) , V_338 ) ;
return NULL ;
}
static T_2 F_187 ( struct V_6 * V_7 )
{
if ( V_7 -> V_212 == V_221 ) {
if ( ! F_12 ( V_7 -> V_24 , & F_16 ( V_7 ) -> V_25 ,
& F_16 ( V_7 ) -> V_26 , V_7 -> V_218 ) ) {
V_7 -> V_212 = V_222 ;
return 0 ;
}
}
V_7 -> V_218 = ~ F_188 ( F_12 ( V_7 -> V_24 ,
& F_16 ( V_7 ) -> V_25 ,
& F_16 ( V_7 ) -> V_26 , 0 ) ) ;
if ( V_7 -> V_24 <= 76 ) {
return F_189 ( V_7 ) ;
}
return 0 ;
}
static int V_89 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_41 * V_42 = F_6 ( V_3 ) ;
struct V_43 * V_44 ;
struct V_6 * V_339 = NULL ;
if ( V_7 -> V_196 == F_131 ( V_274 ) )
return V_85 ( V_3 , V_7 ) ;
#ifdef F_28
if ( F_106 ( V_3 , V_7 ) )
goto V_340;
#endif
if ( F_190 ( V_3 , V_7 ) )
goto V_340;
if ( V_42 -> V_297 . V_332 )
V_339 = F_177 ( V_7 , F_178 ( V_3 , V_239 ) ) ;
if ( V_3 -> V_18 == V_341 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
F_191 ( V_3 , V_7 ) ;
if ( V_9 ) {
if ( F_5 ( V_3 ) -> V_13 != V_7 -> V_14 ||
V_9 -> V_149 -> V_214 ( V_9 , V_42 -> V_16 ) == NULL ) {
F_171 ( V_9 ) ;
V_3 -> V_12 = NULL ;
}
}
if ( F_192 ( V_3 , V_7 , F_17 ( V_7 ) , V_7 -> V_24 ) )
goto V_342;
if ( V_339 )
goto V_343;
return 0 ;
}
if ( V_7 -> V_24 < F_193 ( V_7 ) || F_194 ( V_7 ) )
goto V_344;
if ( V_3 -> V_18 == V_143 ) {
struct V_2 * V_266 = F_144 ( V_3 , V_7 ) ;
if ( ! V_266 )
goto V_340;
if( V_266 != V_3 ) {
F_191 ( V_266 , V_7 ) ;
if ( F_195 ( V_3 , V_266 , V_7 ) )
goto V_342;
if ( V_339 )
F_196 ( V_339 ) ;
return 0 ;
}
} else
F_191 ( V_3 , V_7 ) ;
if ( F_197 ( V_3 , V_7 , F_17 ( V_7 ) , V_7 -> V_24 ) )
goto V_342;
if ( V_339 )
goto V_343;
return 0 ;
V_342:
F_134 ( V_3 , V_7 ) ;
V_340:
if ( V_339 )
F_196 ( V_339 ) ;
F_84 ( V_7 ) ;
return 0 ;
V_344:
F_81 ( F_82 ( V_3 ) , V_345 ) ;
goto V_340;
V_343:
V_44 = F_19 ( V_3 ) ;
if ( F_150 ( V_339 ) -> V_346 == V_44 -> V_347 &&
! ( ( 1 << V_3 -> V_18 ) & ( V_120 | V_119 ) ) ) {
if ( V_42 -> V_297 . V_298 . V_299 || V_42 -> V_297 . V_298 . V_300 )
V_42 -> V_326 = F_65 ( V_339 ) ;
if ( V_42 -> V_297 . V_298 . V_301 || V_42 -> V_297 . V_298 . V_302 )
V_42 -> V_327 = F_16 ( V_339 ) -> V_140 ;
if ( V_42 -> V_297 . V_298 . V_348 )
V_42 -> V_328 = F_175 ( F_16 ( V_7 ) ) ;
if ( F_162 ( V_3 , V_339 ) ) {
F_180 ( V_339 , V_3 ) ;
V_339 = F_198 ( & V_42 -> V_325 , V_339 ) ;
} else {
F_196 ( V_339 ) ;
V_339 = F_198 ( & V_42 -> V_325 , NULL ) ;
}
}
F_84 ( V_339 ) ;
return 0 ;
}
static int F_199 ( struct V_6 * V_7 )
{
const struct V_113 * V_129 ;
const struct V_114 * V_127 ;
struct V_2 * V_3 ;
int V_349 ;
struct V_131 * V_131 = F_49 ( V_7 -> V_132 ) ;
if ( V_7 -> V_350 != V_351 )
goto V_352;
F_81 ( V_131 , V_353 ) ;
if ( ! F_115 ( V_7 , sizeof( struct V_113 ) ) )
goto V_352;
V_129 = F_17 ( V_7 ) ;
if ( V_129 -> V_204 < sizeof( struct V_113 ) / 4 )
goto V_354;
if ( ! F_115 ( V_7 , V_129 -> V_204 * 4 ) )
goto V_352;
if ( ! F_200 ( V_7 ) && F_187 ( V_7 ) )
goto V_354;
V_129 = F_17 ( V_7 ) ;
V_127 = F_16 ( V_7 ) ;
F_150 ( V_7 ) -> V_130 = F_58 ( V_129 -> V_130 ) ;
F_150 ( V_7 ) -> V_346 = ( F_150 ( V_7 ) -> V_130 + V_129 -> V_252 + V_129 -> V_253 +
V_7 -> V_24 - V_129 -> V_204 * 4 ) ;
F_150 ( V_7 ) -> V_240 = F_58 ( V_129 -> V_240 ) ;
F_150 ( V_7 ) -> V_272 = 0 ;
F_150 ( V_7 ) -> V_355 = F_201 ( V_127 ) ;
F_150 ( V_7 ) -> V_356 = 0 ;
V_3 = F_202 ( & V_133 , V_7 , V_129 -> V_31 , V_129 -> V_30 ) ;
if ( ! V_3 )
goto V_357;
V_358:
if ( V_3 -> V_18 == V_136 )
goto V_359;
if ( V_127 -> V_140 < F_6 ( V_3 ) -> V_141 ) {
F_57 ( V_131 , V_142 ) ;
goto V_360;
}
if ( ! F_203 ( V_3 , V_361 , V_7 ) )
goto V_360;
if ( F_190 ( V_3 , V_7 ) )
goto V_360;
V_7 -> V_132 = NULL ;
F_204 ( V_3 ) ;
V_349 = 0 ;
if ( ! F_56 ( V_3 ) ) {
#ifdef F_205
struct V_43 * V_44 = F_19 ( V_3 ) ;
if ( ! V_44 -> V_362 . V_363 && V_44 -> V_362 . V_364 )
V_44 -> V_362 . V_363 = F_206 () ;
if ( V_44 -> V_362 . V_363 )
V_349 = V_89 ( V_3 , V_7 ) ;
else
#endif
{
if ( ! F_207 ( V_3 , V_7 ) )
V_349 = V_89 ( V_3 , V_7 ) ;
}
} else if ( F_208 ( F_209 ( V_3 , V_7 ,
V_3 -> V_365 + V_3 -> V_366 ) ) ) {
F_70 ( V_3 ) ;
F_57 ( V_131 , V_367 ) ;
goto V_360;
}
F_70 ( V_3 ) ;
F_71 ( V_3 ) ;
return V_349 ? - 1 : 0 ;
V_357:
if ( ! F_203 ( NULL , V_361 , V_7 ) )
goto V_352;
if ( V_7 -> V_24 < ( V_129 -> V_204 << 2 ) || F_194 ( V_7 ) ) {
V_354:
F_81 ( V_131 , V_345 ) ;
} else {
F_134 ( NULL , V_7 ) ;
}
V_352:
F_84 ( V_7 ) ;
return 0 ;
V_360:
F_71 ( V_3 ) ;
goto V_352;
V_359:
if ( ! F_203 ( NULL , V_361 , V_7 ) ) {
F_53 ( F_54 ( V_3 ) ) ;
goto V_352;
}
if ( V_7 -> V_24 < ( V_129 -> V_204 << 2 ) || F_194 ( V_7 ) ) {
F_81 ( V_131 , V_345 ) ;
F_53 ( F_54 ( V_3 ) ) ;
goto V_352;
}
switch ( F_210 ( F_54 ( V_3 ) , V_7 , V_129 ) ) {
case V_368 :
{
struct V_2 * V_369 ;
V_369 = F_136 ( F_49 ( V_7 -> V_132 ) , & V_133 ,
& F_16 ( V_7 ) -> V_26 ,
F_109 ( V_129 -> V_30 ) , F_65 ( V_7 ) ) ;
if ( V_369 != NULL ) {
struct V_254 * V_255 = F_54 ( V_3 ) ;
F_211 ( V_255 , & V_106 ) ;
F_53 ( V_255 ) ;
V_3 = V_369 ;
goto V_358;
}
}
case V_370 :
F_140 ( V_3 , V_7 ) ;
break;
case V_371 :
goto V_357;
case V_372 : ;
}
goto V_352;
}
static void F_212 ( struct V_6 * V_7 )
{
const struct V_114 * V_127 ;
const struct V_113 * V_129 ;
struct V_2 * V_3 ;
if ( V_7 -> V_350 != V_351 )
return;
if ( ! F_115 ( V_7 , F_122 ( V_7 ) + sizeof( struct V_113 ) ) )
return;
V_127 = F_16 ( V_7 ) ;
V_129 = F_17 ( V_7 ) ;
if ( V_129 -> V_204 < sizeof( struct V_113 ) / 4 )
return;
V_3 = F_146 ( F_49 ( V_7 -> V_132 ) , & V_133 ,
& V_127 -> V_25 , V_129 -> V_31 ,
& V_127 -> V_26 , F_109 ( V_129 -> V_30 ) ,
F_65 ( V_7 ) ) ;
if ( V_3 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_373 = V_374 ;
if ( V_3 -> V_18 != V_136 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
struct V_37 * V_40 = F_5 ( V_3 ) ;
if ( V_9 )
V_9 = F_213 ( V_9 , F_6 ( V_3 ) -> V_16 ) ;
if ( V_9 &&
V_40 -> V_13 == V_7 -> V_14 )
F_214 ( V_7 , V_9 ) ;
}
}
}
static int F_215 ( struct V_2 * V_3 )
{
struct V_39 * V_40 = F_8 ( V_3 ) ;
F_216 ( V_3 ) ;
V_40 -> V_20 = & V_88 ;
#ifdef F_28
F_19 ( V_3 ) -> V_86 = & V_90 ;
#endif
return 0 ;
}
static void F_217 ( struct V_2 * V_3 )
{
F_218 ( V_3 ) ;
F_219 ( V_3 ) ;
}
static void F_220 ( struct V_375 * V_130 ,
const struct V_2 * V_3 , struct V_153 * V_154 , int V_376 , int V_377 )
{
int V_378 = V_154 -> V_379 - V_380 ;
const struct V_4 * V_381 = & F_73 ( V_154 ) -> V_169 ;
const struct V_4 * V_30 = & F_73 ( V_154 ) -> V_170 ;
if ( V_378 < 0 )
V_378 = 0 ;
F_221 ( V_130 ,
L_7
L_8 ,
V_376 ,
V_381 -> V_29 [ 0 ] , V_381 -> V_29 [ 1 ] ,
V_381 -> V_29 [ 2 ] , V_381 -> V_29 [ 3 ] ,
F_109 ( F_222 ( V_154 ) -> V_382 ) ,
V_30 -> V_29 [ 0 ] , V_30 -> V_29 [ 1 ] ,
V_30 -> V_29 [ 2 ] , V_30 -> V_29 [ 3 ] ,
F_109 ( F_222 ( V_154 ) -> V_383 ) ,
V_157 ,
0 , 0 ,
1 ,
F_223 ( V_378 ) ,
V_154 -> V_335 ,
V_377 ,
0 ,
0 ,
0 , V_154 ) ;
}
static void F_224 ( struct V_375 * V_130 , struct V_2 * V_384 , int V_376 )
{
const struct V_4 * V_30 , * V_381 ;
T_11 V_385 , V_386 ;
int V_387 ;
unsigned long V_388 ;
const struct V_37 * V_38 = F_5 ( V_384 ) ;
const struct V_43 * V_44 = F_19 ( V_384 ) ;
const struct V_39 * V_40 = F_8 ( V_384 ) ;
const struct V_41 * V_42 = F_6 ( V_384 ) ;
V_30 = & V_42 -> V_26 ;
V_381 = & V_42 -> V_94 ;
V_385 = F_109 ( V_38 -> V_115 ) ;
V_386 = F_109 ( V_38 -> V_101 ) ;
if ( V_40 -> V_389 == V_390 ) {
V_387 = 1 ;
V_388 = V_40 -> V_391 ;
} else if ( V_40 -> V_389 == V_392 ) {
V_387 = 4 ;
V_388 = V_40 -> V_391 ;
} else if ( F_225 ( & V_384 -> V_393 ) ) {
V_387 = 2 ;
V_388 = V_384 -> V_393 . V_379 ;
} else {
V_387 = 0 ;
V_388 = V_380 ;
}
F_221 ( V_130 ,
L_7
L_9 ,
V_376 ,
V_381 -> V_29 [ 0 ] , V_381 -> V_29 [ 1 ] ,
V_381 -> V_29 [ 2 ] , V_381 -> V_29 [ 3 ] , V_386 ,
V_30 -> V_29 [ 0 ] , V_30 -> V_29 [ 1 ] ,
V_30 -> V_29 [ 2 ] , V_30 -> V_29 [ 3 ] , V_385 ,
V_384 -> V_18 ,
V_44 -> V_72 - V_44 -> V_144 ,
( V_384 -> V_18 == V_143 ) ? V_384 -> V_394 : ( V_44 -> V_347 - V_44 -> V_395 ) ,
V_387 ,
F_223 ( V_388 - V_380 ) ,
V_40 -> V_396 ,
F_226 ( V_384 ) ,
V_40 -> V_397 ,
F_227 ( V_384 ) ,
F_228 ( & V_384 -> V_398 ) , V_384 ,
F_223 ( V_40 -> V_399 ) ,
F_223 ( V_40 -> V_400 . V_401 ) ,
( V_40 -> V_400 . V_402 << 1 ) | V_40 -> V_400 . V_403 ,
V_44 -> V_404 ,
F_229 ( V_44 ) ? - 1 : V_44 -> V_405
) ;
}
static void F_230 ( struct V_375 * V_130 ,
struct V_254 * V_255 , int V_376 )
{
const struct V_4 * V_30 , * V_381 ;
T_11 V_385 , V_386 ;
const struct V_406 * V_407 = F_231 ( (struct V_2 * ) V_255 ) ;
int V_378 = V_255 -> V_408 - V_380 ;
if ( V_378 < 0 )
V_378 = 0 ;
V_30 = & V_407 -> V_409 ;
V_381 = & V_407 -> V_410 ;
V_385 = F_109 ( V_255 -> V_411 ) ;
V_386 = F_109 ( V_255 -> V_412 ) ;
F_221 ( V_130 ,
L_7
L_8 ,
V_376 ,
V_381 -> V_29 [ 0 ] , V_381 -> V_29 [ 1 ] ,
V_381 -> V_29 [ 2 ] , V_381 -> V_29 [ 3 ] , V_386 ,
V_30 -> V_29 [ 0 ] , V_30 -> V_29 [ 1 ] ,
V_30 -> V_29 [ 2 ] , V_30 -> V_29 [ 3 ] , V_385 ,
V_255 -> V_413 , 0 , 0 ,
3 , F_223 ( V_378 ) , 0 , 0 , 0 , 0 ,
F_228 ( & V_255 -> V_414 ) , V_255 ) ;
}
static int F_232 ( struct V_375 * V_130 , void * V_415 )
{
struct V_416 * V_417 ;
if ( V_415 == V_418 ) {
F_233 ( V_130 ,
L_10
L_11
L_12
L_13
L_14 ) ;
goto V_139;
}
V_417 = V_130 -> V_419 ;
switch ( V_417 -> V_420 ) {
case V_421 :
case V_422 :
F_224 ( V_130 , V_415 , V_417 -> V_423 ) ;
break;
case V_424 :
F_220 ( V_130 , V_417 -> V_425 , V_415 , V_417 -> V_423 , V_417 -> V_377 ) ;
break;
case V_426 :
F_230 ( V_130 , V_415 , V_417 -> V_423 ) ;
break;
}
V_139:
return 0 ;
}
int T_12 F_234 ( struct V_131 * V_131 )
{
return F_235 ( V_131 , & V_427 ) ;
}
void F_236 ( struct V_131 * V_131 )
{
F_237 ( V_131 , & V_427 ) ;
}
static int T_12 F_238 ( struct V_131 * V_131 )
{
return F_239 ( & V_131 -> V_233 . F_19 , V_428 ,
V_429 , V_28 , V_131 ) ;
}
static void T_13 F_240 ( struct V_131 * V_131 )
{
F_241 ( V_131 -> V_233 . F_19 ) ;
}
static void T_13 F_242 ( struct V_430 * V_431 )
{
F_243 ( & V_133 , & V_106 , V_54 ) ;
}
int T_14 F_244 ( void )
{
int V_349 ;
V_349 = F_245 ( & V_432 , V_28 ) ;
if ( V_349 )
goto V_139;
V_349 = F_246 ( & V_433 ) ;
if ( V_349 )
goto V_434;
V_349 = F_247 ( & V_435 ) ;
if ( V_349 )
goto V_436;
V_139:
return V_349 ;
V_434:
F_248 ( & V_432 , V_28 ) ;
V_436:
F_249 ( & V_433 ) ;
goto V_139;
}
void F_250 ( void )
{
F_251 ( & V_435 ) ;
F_249 ( & V_433 ) ;
F_248 ( & V_432 , V_28 ) ;
}
