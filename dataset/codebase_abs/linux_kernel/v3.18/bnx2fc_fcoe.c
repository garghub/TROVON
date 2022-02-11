static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return ( (struct V_4 * )
( (struct V_5 * ) F_2 ( V_3 ) ) -> V_6 ) -> V_7 ;
}
static void F_3 ( struct V_8 * V_9 )
{
struct V_10 * V_11 =
F_4 ( V_9 ) ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_4 * V_14 = F_6 ( V_13 ) ;
V_9 -> V_15 = V_14 -> V_15 ;
}
static void F_7 ( struct V_2 * V_16 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_23 * V_24 , * V_25 ;
struct V_23 * V_26 ;
V_18 = & V_27 ;
F_8 ( & V_18 -> V_28 . V_29 ) ;
V_22 = & V_18 -> V_28 ;
V_26 = V_22 -> V_25 ;
for ( V_24 = V_26 ; V_24 != (struct V_23 * ) V_22 ;
V_24 = V_25 ) {
V_25 = V_24 -> V_25 ;
V_20 = F_9 ( V_24 ) ;
if ( V_20 -> V_30 == V_16 ) {
F_10 ( V_24 , V_22 ) ;
F_11 ( V_24 ) ;
}
}
F_12 ( & V_18 -> V_28 . V_29 ) ;
}
int F_13 ( struct V_23 * V_24 , int V_31 )
{
int V_32 ;
F_14 ( & V_33 ) ;
V_32 = F_15 ( V_24 , V_31 , & V_27 ) ;
F_16 ( & V_33 ) ;
return V_32 ;
}
static void F_17 ( struct V_2 * V_3 )
{
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_38 * V_39 ;
int V_40 ;
F_19 ( L_1 , V_41 ) ;
F_20 ( & V_37 -> V_42 ) ;
F_8 ( & V_37 -> V_43 ) ;
for ( V_40 = 0 ; V_40 < V_44 ; V_40 ++ ) {
V_39 = V_37 -> V_45 [ V_40 ] ;
if ( V_39 ) {
if ( V_39 -> V_34 == V_34 ) {
F_12 ( & V_37 -> V_43 ) ;
F_21 ( V_39 , L_2 ) ;
F_22 ( V_39 ) ;
F_8 ( & V_37 -> V_43 ) ;
}
}
}
F_12 ( & V_37 -> V_43 ) ;
F_23 ( & V_37 -> V_42 ) ;
}
static int F_24 ( struct V_38 * V_39 ,
struct V_46 * V_47 )
{
struct V_48 * V_49 = V_39 -> V_49 ;
struct V_50 * V_51 ;
int V_32 = 0 ;
V_51 = F_25 ( V_47 ) ;
F_21 ( V_39 , L_3
L_4 , V_49 -> V_52 . V_53 ,
F_26 ( V_51 -> V_54 ) , V_51 -> V_55 ) ;
if ( ( V_51 -> V_56 == V_57 ) &&
( V_51 -> V_55 == V_58 ) ) {
switch ( F_27 ( V_47 ) ) {
case V_59 :
V_32 = F_28 ( V_39 , V_47 ) ;
break;
case V_60 :
V_32 = F_29 ( V_39 , V_47 ) ;
break;
case V_61 :
V_32 = F_30 ( V_39 , V_47 ) ;
break;
default:
break;
}
} else if ( ( V_51 -> V_56 == V_62 ) &&
( V_51 -> V_55 == V_63 ) )
F_21 ( V_39 , L_5 ) ;
else {
F_21 ( V_39 , L_6
L_7 ,
V_51 -> V_56 , V_51 -> V_55 ) ;
return - V_64 ;
}
if ( V_32 )
return - V_65 ;
else
return 0 ;
}
static int F_31 ( struct V_2 * V_3 , struct V_46 * V_47 )
{
struct V_66 * V_67 ;
struct V_68 * V_69 ;
struct V_23 * V_24 ;
struct V_50 * V_51 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
struct V_36 * V_37 ;
struct V_5 * V_34 ;
struct V_70 * V_71 ;
struct V_38 * V_39 ;
struct V_72 * V_73 ;
T_1 V_74 , V_75 ;
T_2 V_76 ;
unsigned int V_77 , V_31 , V_78 ;
int V_79 , V_32 = 0 ;
V_34 = (struct V_5 * ) F_2 ( V_3 ) ;
V_35 = V_34 -> V_6 ;
V_13 = F_32 ( V_35 ) ;
V_37 = V_35 -> V_37 ;
V_51 = F_25 ( V_47 ) ;
V_24 = F_33 ( V_47 ) ;
if ( ! V_3 -> V_80 ) {
F_34 ( V_3 , L_8 ) ;
F_11 ( V_24 ) ;
return 0 ;
}
if ( F_35 ( V_51 -> V_55 == V_58 ) ) {
if ( ! V_13 -> V_81 ) {
F_34 ( V_3 , L_9 ) ;
F_11 ( V_24 ) ;
return - V_82 ;
}
if ( F_36 ( V_13 , V_3 , V_24 ) )
return 0 ;
}
V_74 = F_37 ( V_47 ) ;
V_75 = F_38 ( V_47 ) ;
F_8 ( & V_37 -> V_43 ) ;
V_39 = F_39 ( V_34 , F_40 ( V_51 -> V_83 ) ) ;
if ( V_39 && ( F_41 ( V_84 , & V_39 -> V_85 ) ) ) {
F_34 ( V_3 , L_10
L_11 , F_40 ( V_51 -> V_83 ) ) ;
F_12 ( & V_37 -> V_43 ) ;
V_32 = F_24 ( V_39 , V_47 ) ;
if ( V_32 != - V_64 ) {
F_11 ( V_24 ) ;
return V_32 ;
}
} else {
F_12 ( & V_37 -> V_43 ) ;
}
V_78 = sizeof( struct V_66 ) ;
V_77 = sizeof( struct V_70 ) ;
V_31 = sizeof( struct V_68 ) ;
V_79 = ( V_24 -> V_86 - V_31 + sizeof( V_76 ) ) / V_87 ;
V_24 -> V_88 = V_89 ;
V_76 = F_42 ( V_47 ) ;
if ( F_43 ( V_24 ) ) {
T_3 * V_90 ;
if ( F_13 ( V_24 , V_31 ) ) {
F_11 ( V_24 ) ;
return - V_65 ;
}
V_90 = & F_44 ( V_24 ) -> V_91 [ F_44 ( V_24 ) -> V_92 - 1 ] ;
V_69 = F_45 ( F_46 ( V_90 ) ) + V_90 -> V_93 ;
} else {
V_69 = (struct V_68 * ) F_47 ( V_24 , V_31 ) ;
}
memset ( V_69 , 0 , sizeof( * V_69 ) ) ;
V_69 -> V_94 = V_75 ;
V_69 -> V_95 = F_48 ( ~ V_76 ) ;
if ( F_43 ( V_24 ) ) {
F_49 ( V_69 ) ;
V_69 = NULL ;
}
F_50 ( V_24 , V_78 + V_77 ) ;
F_51 ( V_24 ) ;
F_52 ( V_24 ) ;
V_24 -> V_96 = V_78 ;
V_24 -> V_97 = F_53 ( V_98 ) ;
V_24 -> V_99 = V_35 -> V_7 ;
V_67 = F_54 ( V_24 ) ;
V_67 -> V_100 = F_53 ( V_98 ) ;
if ( V_13 -> V_101 )
F_55 ( V_67 -> V_102 , V_51 -> V_83 ) ;
else
memcpy ( V_67 -> V_102 , V_13 -> V_103 , V_104 ) ;
if ( F_35 ( V_13 -> V_105 != V_106 ) )
memcpy ( V_67 -> V_107 , V_13 -> V_108 , V_104 ) ;
else
memcpy ( V_67 -> V_107 , V_34 -> V_109 , V_104 ) ;
V_71 = (struct V_70 * ) ( V_67 + 1 ) ;
memset ( V_71 , 0 , sizeof( * V_71 ) ) ;
if ( V_110 )
F_56 ( V_71 , V_110 ) ;
V_71 -> V_111 = V_74 ;
if ( V_3 -> V_112 && F_57 ( V_47 ) ) {
F_44 ( V_24 ) -> V_113 = V_114 ;
F_44 ( V_24 ) -> V_115 = F_57 ( V_47 ) ;
} else {
F_44 ( V_24 ) -> V_113 = 0 ;
F_44 ( V_24 ) -> V_115 = 0 ;
}
V_73 = F_58 ( V_3 -> V_73 , F_59 () ) ;
V_73 -> V_116 ++ ;
V_73 -> V_117 += V_79 ;
F_60 () ;
V_30 ( V_47 ) = V_3 ;
if ( V_34 -> V_118 . V_119 )
F_61 ( V_3 , V_24 ) ;
else if ( F_62 ( V_24 ) )
F_61 ( V_3 , V_24 ) ;
return 0 ;
}
static int F_63 ( struct V_23 * V_24 , struct V_1 * V_99 ,
struct V_120 * V_121 , struct V_1 * V_122 )
{
struct V_2 * V_3 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
struct V_50 * V_51 ;
struct V_19 * V_20 ;
struct V_17 * V_18 ;
struct V_23 * V_123 ;
unsigned short V_124 ;
V_35 = F_64 ( V_121 , struct V_4 ,
V_125 ) ;
V_13 = F_32 ( V_35 ) ;
V_3 = V_13 -> V_16 ;
if ( F_35 ( V_3 == NULL ) ) {
F_65 (KERN_ERR PFX L_12 ) ;
goto V_126;
}
V_123 = F_66 ( V_24 , V_127 ) ;
if ( ! V_123 )
goto V_126;
V_24 = V_123 ;
if ( F_35 ( F_54 ( V_24 ) -> V_100 != F_53 ( V_98 ) ) ) {
F_65 (KERN_ERR PFX L_13 ) ;
goto V_126;
}
if ( F_35 ( ( V_24 -> V_86 < V_128 ) ||
! F_67 ( V_24 , V_129 ) ) )
goto V_126;
F_68 ( V_24 , sizeof( struct V_70 ) ) ;
V_51 = (struct V_50 * ) F_69 ( V_24 ) ;
V_124 = F_26 ( V_51 -> V_54 ) ;
V_20 = F_9 ( V_24 ) ;
V_20 -> V_30 = V_3 ;
V_18 = & V_27 ;
F_14 ( & V_18 -> V_28 . V_29 ) ;
F_70 ( & V_18 -> V_28 , V_24 ) ;
if ( V_18 -> V_28 . V_119 == 1 )
F_71 ( V_18 -> V_130 ) ;
F_16 ( & V_18 -> V_28 . V_29 ) ;
return 0 ;
V_126:
F_11 ( V_24 ) ;
return - 1 ;
}
static int F_72 ( void * V_131 )
{
struct V_17 * V_18 = V_131 ;
struct V_23 * V_24 ;
F_73 ( V_132 , V_133 ) ;
F_74 ( V_134 ) ;
while ( ! F_75 () ) {
F_76 () ;
F_8 ( & V_18 -> V_28 . V_29 ) ;
while ( ( V_24 = F_77 ( & V_18 -> V_28 ) ) != NULL ) {
F_12 ( & V_18 -> V_28 . V_29 ) ;
F_78 ( V_24 ) ;
F_8 ( & V_18 -> V_28 . V_29 ) ;
}
F_79 ( V_134 ) ;
F_12 ( & V_18 -> V_28 . V_29 ) ;
}
F_79 ( V_135 ) ;
return 0 ;
}
static void F_78 ( struct V_23 * V_24 )
{
T_2 V_136 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_72 * V_73 ;
struct V_50 * V_51 ;
struct V_68 V_137 ;
struct V_46 * V_47 ;
struct V_2 * V_138 ;
struct V_5 * V_34 ;
T_1 * V_139 = NULL ;
T_1 * V_140 = NULL ;
struct V_70 * V_71 ;
V_20 = F_9 ( V_24 ) ;
V_3 = V_20 -> V_30 ;
if ( F_35 ( V_3 == NULL ) ) {
F_65 (KERN_ERR PFX L_14 ) ;
F_11 ( V_24 ) ;
return;
}
if ( F_43 ( V_24 ) )
F_80 ( V_24 ) ;
V_139 = F_54 ( V_24 ) -> V_107 ;
V_140 = F_54 ( V_24 ) -> V_102 ;
V_71 = (struct V_70 * ) F_81 ( V_24 ) ;
V_51 = (struct V_50 * ) F_69 ( V_24 ) ;
F_82 ( V_24 , sizeof( struct V_70 ) ) ;
V_136 = V_24 -> V_86 - sizeof( struct V_68 ) ;
V_47 = (struct V_46 * ) V_24 ;
F_83 ( V_47 ) ;
V_30 ( V_47 ) = V_3 ;
F_37 ( V_47 ) = V_71 -> V_111 ;
if ( F_84 ( V_24 , V_136 , & V_137 , sizeof( V_137 ) ) ) {
F_11 ( V_24 ) ;
return;
}
F_38 ( V_47 ) = V_137 . V_94 ;
F_85 ( V_47 ) = V_137 . V_95 ;
if ( F_86 ( V_24 , V_136 ) ) {
F_11 ( V_24 ) ;
return;
}
V_51 = F_25 ( V_47 ) ;
V_138 = F_87 ( V_3 , F_40 ( V_51 -> V_83 ) ) ;
if ( V_138 ) {
V_34 = F_2 ( V_138 ) ;
if ( ! F_88 ( V_34 -> V_109 , V_140 ) ) {
F_34 ( V_3 , L_15 ) ;
F_11 ( V_24 ) ;
return;
}
}
if ( V_51 -> V_55 == V_141 &&
V_51 -> V_56 == V_142 ) {
F_11 ( V_24 ) ;
return;
}
if ( V_51 -> V_55 == V_58 &&
V_51 -> V_56 == V_57 ) {
switch ( F_27 ( V_47 ) ) {
case V_60 :
if ( F_40 ( V_51 -> V_143 ) == V_144 ) {
F_11 ( V_24 ) ;
return;
}
break;
}
}
if ( V_51 -> V_55 == V_63 ) {
F_11 ( V_24 ) ;
return;
}
V_73 = F_58 ( V_3 -> V_73 , F_89 () ) ;
V_73 -> V_145 ++ ;
V_73 -> V_146 += V_136 / V_87 ;
if ( F_90 ( F_85 ( V_47 ) ) !=
~ F_91 ( ~ 0 , V_24 -> V_147 , V_136 ) ) {
if ( V_73 -> V_148 < 5 )
F_65 (KERN_WARNING PFX L_16
L_17 ) ;
V_73 -> V_148 ++ ;
F_11 ( V_24 ) ;
return;
}
F_92 ( V_3 , V_47 ) ;
}
int F_93 ( void * V_131 )
{
struct V_149 * V_150 = V_131 ;
struct V_151 * V_152 , * V_153 ;
F_94 ( V_154 ) ;
F_73 ( V_132 , V_133 ) ;
F_74 ( V_134 ) ;
while ( ! F_75 () ) {
F_76 () ;
F_8 ( & V_150 -> V_155 ) ;
while ( ! F_95 ( & V_150 -> V_154 ) ) {
F_96 ( & V_150 -> V_154 , & V_154 ) ;
F_12 ( & V_150 -> V_155 ) ;
F_97 (work, tmp, &work_list, list) {
F_98 ( & V_152 -> V_22 ) ;
F_99 ( V_152 -> V_39 , V_152 -> V_156 ) ;
F_100 ( V_152 ) ;
}
F_8 ( & V_150 -> V_155 ) ;
}
F_79 ( V_134 ) ;
F_12 ( & V_150 -> V_155 ) ;
}
F_79 ( V_135 ) ;
return 0 ;
}
static struct V_157 * F_101 ( struct V_158 * V_159 )
{
struct V_157 * V_160 ;
struct V_2 * V_3 = F_102 ( V_159 ) ;
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_161 * V_162 ;
int V_32 = 0 ;
V_162 = (struct V_161 * ) V_37 -> V_163 ;
if ( ! V_162 )
return NULL ;
V_160 = F_103 ( V_159 ) ;
F_104 ( & V_37 -> V_164 ) ;
if ( F_105 ( V_37 ) )
return V_160 ;
V_32 = F_106 ( & V_37 -> V_164 , ( 2 * V_165 ) ) ;
if ( ! V_32 ) {
F_34 ( V_3 , L_18 ) ;
return V_160 ;
}
F_107 ( V_37 , V_166 , V_167 ) ;
V_160 -> V_168 += V_37 -> V_169 . V_167 ;
F_107 ( V_37 , V_170 , V_171 ) ;
V_160 -> V_172 += V_37 -> V_169 . V_171 ;
F_107 ( V_37 , V_170 , V_173 ) ;
V_160 -> V_174 += ( ( V_37 -> V_169 . V_173 ) / 4 ) ;
F_107 ( V_37 , V_175 , V_176 ) ;
V_160 -> V_177 += V_37 -> V_169 . V_176 ;
F_107 ( V_37 , V_175 , V_178 ) ;
V_160 -> V_179 += ( ( V_37 -> V_169 . V_178 ) / 4 ) ;
V_160 -> V_180 = 0 ;
V_160 -> V_181 = 0 ;
V_160 -> V_182 = 0 ;
V_160 -> V_183 = 0 ;
V_160 -> V_184 = 0 ;
V_160 -> V_185 = 0 ;
memcpy ( & V_37 -> V_186 , V_37 -> V_163 ,
sizeof( struct V_161 ) ) ;
return V_160 ;
}
static int F_108 ( struct V_2 * V_3 , struct V_187 * V_99 )
{
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_158 * V_159 = V_3 -> V_188 ;
int V_32 = 0 ;
V_159 -> V_189 = V_190 ;
V_159 -> V_191 = V_192 ;
V_159 -> V_193 = V_194 ;
V_159 -> V_195 = 0 ;
if ( V_3 -> V_196 )
V_159 -> V_197 = V_198 ;
else
V_159 -> V_197 = V_199 ;
V_32 = F_109 ( V_3 -> V_188 , V_99 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_19 ) ;
return V_32 ;
}
if ( ! V_3 -> V_196 )
F_110 ( V_3 -> V_188 ) = V_200 ;
snprintf ( F_111 ( V_3 -> V_188 ) , 256 ,
L_20 ,
V_201 , V_37 -> V_202 , V_203 ,
V_35 -> V_7 -> V_204 ) ;
return 0 ;
}
static int F_112 ( struct V_2 * V_3 )
{
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_1 * V_99 = V_37 -> V_205 ;
int V_32 = 0 ;
if ( ( V_99 -> V_85 & V_206 ) && F_113 ( V_99 ) )
F_114 ( V_207 , & V_37 -> V_208 ) ;
else {
F_115 ( V_207 , & V_37 -> V_208 ) ;
V_32 = - 1 ;
}
return V_32 ;
}
void F_116 ( struct V_36 * V_37 )
{
if ( F_41 ( V_209 , & V_37 -> V_205 -> V_210 ) )
F_115 ( V_207 , & V_37 -> V_208 ) ;
else
F_114 ( V_207 , & V_37 -> V_208 ) ;
}
static int F_117 ( struct V_2 * V_3 , struct V_1 * V_7 )
{
struct V_36 * V_37 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
struct V_5 * V_34 ;
T_4 V_211 , V_212 ;
V_34 = F_2 ( V_3 ) ;
V_35 = V_34 -> V_6 ;
V_13 = F_32 ( V_35 ) ;
V_37 = V_35 -> V_37 ;
if ( ! V_37 -> V_205 -> V_213 ||
! V_37 -> V_205 -> V_213 -> V_214 )
return - V_215 ;
if ( F_118 ( V_3 , V_216 ) )
return - V_82 ;
F_119 ( & V_34 -> V_118 ) ;
V_34 -> V_217 = 0 ;
F_120 ( & V_34 -> V_218 , V_219 , ( unsigned long ) V_3 ) ;
F_121 ( V_3 ) ;
if ( ! V_3 -> V_196 ) {
if ( F_122 ( V_7 , & V_211 , V_220 ) )
V_211 = F_123 ( V_13 -> V_108 ,
1 , 0 ) ;
F_34 ( V_3 , L_21 , V_211 ) ;
F_124 ( V_3 , V_211 ) ;
if ( F_122 ( V_7 , & V_212 , V_221 ) )
V_212 = F_123 ( V_13 -> V_108 ,
2 , 0 ) ;
F_34 ( V_3 , L_22 , V_212 ) ;
F_125 ( V_3 , V_212 ) ;
}
return 0 ;
}
static void F_126 ( unsigned long V_147 )
{
struct V_36 * V_37 = (struct V_36 * ) V_147 ;
F_65 (KERN_ERR PFX L_23
L_24 ) ;
F_115 ( V_222 , & V_37 -> V_85 ) ;
F_127 ( & V_37 -> V_223 ) ;
}
static void F_128 ( void * V_224 , unsigned long V_225 ,
T_5 V_15 )
{
struct V_36 * V_37 = (struct V_36 * ) V_224 ;
struct V_10 * V_226 ;
struct V_2 * V_3 ;
struct V_2 * V_196 ;
struct V_4 * V_35 , * V_153 ;
struct V_12 * V_13 ;
int V_227 = 0 ;
T_2 V_228 = 1 ;
if ( V_15 != 0 && V_225 != V_229 )
return;
switch ( V_225 ) {
case V_230 :
if ( ! F_41 ( V_231 , & V_37 -> V_208 ) )
F_65 ( V_232 L_25\
L_26 ) ;
break;
case V_233 :
F_114 ( V_234 , & V_37 -> V_208 ) ;
F_114 ( V_231 , & V_37 -> V_208 ) ;
V_228 = 0 ;
break;
case V_235 :
F_115 ( V_234 , & V_37 -> V_208 ) ;
V_228 = 0 ;
break;
case V_236 :
break;
case V_229 :
if ( ! V_15 )
return;
F_20 ( & V_237 ) ;
F_97 (interface, tmp, &if_list, list) {
if ( V_35 -> V_37 == V_37 &&
V_35 -> V_15 == ( V_15 & V_238 ) )
F_129 ( V_35 ) ;
}
F_23 ( & V_237 ) ;
F_130 ( V_239 ) ;
return;
default:
F_65 (KERN_ERR PFX L_27 , event) ;
return;
}
F_20 ( & V_237 ) ;
F_131 (interface, &if_list, list) {
if ( V_35 -> V_37 != V_37 )
continue;
V_13 = F_32 ( V_35 ) ;
V_3 = V_13 -> V_16 ;
F_34 ( V_3 , L_28 ,
V_35 -> V_7 -> V_204 , V_225 ) ;
F_121 ( V_3 ) ;
V_226 = F_132 ( V_13 ) ;
if ( V_228 && ! F_112 ( V_3 ) ) {
switch ( V_226 -> V_240 ) {
case V_241 :
F_133 ( L_29 ) ;
break;
case V_242 :
case V_243 :
F_118 ( V_3 , V_216 ) ;
if ( V_35 -> V_240 )
F_134 ( V_13 ) ;
} ;
} else if ( F_135 ( V_13 ) ) {
switch ( V_226 -> V_240 ) {
case V_241 :
F_133 ( L_30 ) ;
break;
case V_242 :
case V_243 :
F_20 ( & V_3 -> V_244 ) ;
F_131 (vport, &lport->vports, list)
F_136 ( V_196 -> V_188 ) =
V_245 ;
F_23 ( & V_3 -> V_244 ) ;
F_136 ( V_3 -> V_188 ) =
V_245 ;
F_58 ( V_3 -> V_73 ,
F_59 () ) -> V_246 ++ ;
F_60 () ;
F_137 ( V_3 ) ;
V_227 = 1 ;
} ;
}
}
F_23 ( & V_237 ) ;
if ( V_227 ) {
F_114 ( V_247 , & V_37 -> V_208 ) ;
F_138 ( & V_37 -> V_248 ) ;
F_19 ( L_31
L_32 ,
V_37 -> V_249 ) ;
V_37 -> V_250 = 1 ;
F_139 ( V_37 -> V_248 ,
( V_37 -> V_249 == 0 ) ) ;
F_19 ( L_33 ,
V_37 -> V_249 ) ;
V_37 -> V_250 = 0 ;
if ( F_140 ( V_132 ) )
F_141 ( V_132 ) ;
}
}
static int F_142 ( struct V_2 * V_3 )
{
memcpy ( & V_3 -> V_251 , & V_252 ,
sizeof( struct V_253 ) ) ;
F_143 ( V_3 ) ;
F_144 ( V_3 ) ;
F_145 ( V_3 ) ;
F_146 ( V_3 ) ;
F_147 ( V_3 , V_3 ) ;
return 0 ;
}
static int F_148 ( struct V_2 * V_3 , struct V_36 * V_37 )
{
int V_254 , V_255 ;
V_254 = V_37 -> V_256 + 1 ;
if ( V_257 <= 2 )
V_255 = V_37 -> V_256 + V_258 ;
else
V_255 = V_37 -> V_256 + V_259 ;
if ( ! F_149 ( V_3 , V_260 , V_254 ,
V_255 , NULL ) ) {
F_65 (KERN_ERR PFX L_34 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_150 ( struct V_2 * V_3 )
{
V_3 -> V_80 = 0 ;
V_3 -> V_261 = 0 ;
V_3 -> V_262 = V_263 ;
V_3 -> V_264 = V_265 ;
V_3 -> V_266 = 2 * 1000 ;
V_3 -> V_267 = 10 * 1000 ;
V_3 -> V_268 = ( V_269 | V_270 |
V_271 | V_272 ) ;
V_3 -> V_273 = 1 ;
memset ( & V_3 -> V_274 , 0 , sizeof( struct V_275 ) ) ;
V_3 -> V_274 . V_276 = V_277 ;
if ( F_151 ( V_3 ) )
return - V_65 ;
F_152 ( V_3 ) ;
return 0 ;
}
static int F_153 ( struct V_23 * V_24 , struct V_1 * V_99 ,
struct V_120 * V_121 ,
struct V_1 * V_278 )
{
struct V_4 * V_35 ;
struct V_12 * V_13 ;
V_35 = F_64 ( V_121 , struct V_4 ,
V_279 ) ;
V_13 = F_32 ( V_35 ) ;
F_154 ( V_13 , V_24 ) ;
return 0 ;
}
static void F_155 ( struct V_2 * V_3 , T_1 * V_280 )
{
struct V_5 * V_34 = F_2 ( V_3 ) ;
memcpy ( V_34 -> V_109 , V_280 , V_104 ) ;
}
static T_1 * F_156 ( struct V_2 * V_3 )
{
struct V_5 * V_34 ;
V_34 = (struct V_5 * ) F_2 ( V_3 ) ;
return V_34 -> V_109 ;
}
static void F_157 ( struct V_12 * V_281 , struct V_23 * V_24 )
{
V_24 -> V_99 = F_158 ( V_281 ) -> V_7 ;
F_159 ( V_24 ) ;
}
static int F_160 ( struct V_282 * V_196 , bool V_283 )
{
struct V_158 * V_159 = F_161 ( V_196 ) ;
struct V_2 * V_284 = F_102 ( V_159 ) ;
struct V_5 * V_34 = F_2 ( V_284 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_1 * V_7 = V_35 -> V_7 ;
struct V_2 * V_138 ;
int V_32 ;
char V_285 [ 32 ] ;
V_32 = F_162 ( V_196 ) ;
if ( V_32 ) {
F_163 ( V_196 -> V_286 , V_285 , sizeof( V_285 ) ) ;
F_65 (KERN_ERR PFX L_35
L_36 ,
buf) ;
return V_32 ;
}
if ( ! F_41 ( V_287 , & V_35 -> V_37 -> V_85 ) ) {
F_65 (KERN_ERR PFX L_37
L_38 ) ;
return - V_288 ;
}
F_164 () ;
F_20 ( & V_237 ) ;
V_138 = F_165 ( V_35 , & V_196 -> V_99 , 1 ) ;
F_23 ( & V_237 ) ;
F_166 () ;
if ( F_167 ( V_138 ) ) {
F_65 (KERN_ERR PFX L_39 ,
netdev->name) ;
return - V_288 ;
}
if ( V_283 ) {
F_168 ( V_196 , V_289 ) ;
} else {
V_138 -> V_290 = V_291 ;
F_169 ( V_138 ) ;
F_170 ( V_138 ) ;
F_171 ( V_138 ) ;
}
return 0 ;
}
static void F_172 ( struct V_36 * V_37 , struct V_2 * V_3 )
{
struct V_292 * V_293 , * V_153 ;
F_8 ( & V_37 -> V_43 ) ;
F_97 (blport, tmp, &hba->vports, list) {
if ( V_293 -> V_3 == V_3 ) {
F_173 ( & V_293 -> V_22 ) ;
F_100 ( V_293 ) ;
}
}
F_12 ( & V_37 -> V_43 ) ;
}
static int F_174 ( struct V_282 * V_196 )
{
struct V_158 * V_159 = F_161 ( V_196 ) ;
struct V_2 * V_284 = F_102 ( V_159 ) ;
struct V_2 * V_138 = V_196 -> V_294 ;
struct V_5 * V_34 = F_2 ( V_138 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_2 * V_295 ;
bool V_296 = false ;
F_20 ( & V_284 -> V_244 ) ;
F_131 (v_port, &n_port->vports, list)
if ( V_295 -> V_196 == V_196 ) {
V_296 = true ;
break;
}
if ( ! V_296 ) {
F_23 ( & V_284 -> V_244 ) ;
return - V_297 ;
}
F_173 ( & V_138 -> V_22 ) ;
F_23 ( & V_284 -> V_244 ) ;
F_172 ( V_35 -> V_37 , V_34 -> V_3 ) ;
F_175 ( V_34 -> V_3 ) ;
F_176 ( V_35 ) ;
F_177 ( V_239 , & V_34 -> V_298 ) ;
return 0 ;
}
static int F_178 ( struct V_282 * V_196 , bool V_299 )
{
struct V_2 * V_3 = V_196 -> V_294 ;
if ( V_299 ) {
F_168 ( V_196 , V_289 ) ;
F_179 ( V_3 ) ;
} else {
V_3 -> V_290 = V_291 ;
F_170 ( V_3 ) ;
F_171 ( V_3 ) ;
}
return 0 ;
}
static int F_180 ( struct V_4 * V_35 )
{
struct V_1 * V_7 = V_35 -> V_7 ;
struct V_1 * V_300 = V_35 -> V_37 -> V_205 ;
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_301 * V_302 ;
int V_303 = 0 ;
F_181 () ;
F_182 (physdev, ha) {
F_19 ( L_40 ,
V_302 -> type ) ;
F_65 ( V_304 L_41 , V_302 -> V_280 [ 0 ] ,
V_302 -> V_280 [ 1 ] , V_302 -> V_280 [ 2 ] , V_302 -> V_280 [ 3 ] ,
V_302 -> V_280 [ 4 ] , V_302 -> V_280 [ 5 ] ) ;
if ( ( V_302 -> type == V_305 ) &&
( F_183 ( V_302 -> V_280 ) ) ) {
memcpy ( V_13 -> V_108 , V_302 -> V_280 ,
V_104 ) ;
V_303 = 1 ;
F_19 ( L_42 ) ;
}
}
F_184 () ;
if ( ! V_303 )
return - V_64 ;
V_35 -> V_279 . V_306 = F_153 ;
V_35 -> V_279 . type = F_53 ( V_307 ) ;
V_35 -> V_279 . V_99 = V_7 ;
F_185 ( & V_35 -> V_279 ) ;
V_35 -> V_125 . V_306 = F_63 ;
V_35 -> V_125 . type = F_186 ( V_98 ) ;
V_35 -> V_125 . V_99 = V_7 ;
F_185 ( & V_35 -> V_125 ) ;
return 0 ;
}
static int F_187 ( void )
{
V_199 =
F_188 ( & V_308 ) ;
if ( V_199 == NULL ) {
F_65 (KERN_ERR PFX L_43 ) ;
return - V_64 ;
}
V_198 =
F_188 ( & V_309 ) ;
if ( V_198 == NULL ) {
F_65 (KERN_ERR PFX
L_44 ) ;
F_189 ( V_199 ) ;
V_199 = NULL ;
return - V_64 ;
}
return 0 ;
}
static void F_190 ( void )
{
F_189 ( V_199 ) ;
F_189 ( V_198 ) ;
V_199 = NULL ;
V_198 = NULL ;
}
static void F_191 ( struct V_310 * V_310 )
{
struct V_10 * V_11 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
struct V_1 * V_7 ;
V_35 = F_64 ( V_310 , struct V_4 , V_310 ) ;
F_19 ( L_45 ) ;
V_13 = F_32 ( V_35 ) ;
V_11 = F_132 ( V_13 ) ;
V_7 = V_35 -> V_7 ;
if ( F_192 ( V_311 , & V_35 -> V_312 ) )
F_193 ( V_13 ) ;
F_194 ( V_11 ) ;
F_195 ( V_7 ) ;
F_196 ( V_313 ) ;
}
static inline void F_197 ( struct V_4 * V_35 )
{
F_198 ( & V_35 -> V_310 ) ;
}
static inline void F_176 ( struct V_4 * V_35 )
{
F_199 ( & V_35 -> V_310 , F_191 ) ;
}
static void F_200 ( struct V_36 * V_37 )
{
if ( V_37 -> V_314 ) {
F_201 ( V_37 -> V_314 ) ;
V_37 -> V_314 = NULL ;
}
F_100 ( V_37 -> V_45 ) ;
F_202 ( V_37 ) ;
F_100 ( V_37 ) ;
}
static struct V_36 * F_203 ( struct V_315 * V_316 )
{
struct V_36 * V_37 ;
struct V_317 * V_318 ;
int V_32 ;
V_37 = F_204 ( sizeof( * V_37 ) , V_319 ) ;
if ( ! V_37 ) {
F_65 (KERN_ERR PFX L_46 ) ;
return NULL ;
}
F_205 ( & V_37 -> V_43 ) ;
F_206 ( & V_37 -> V_42 ) ;
V_37 -> V_316 = V_316 ;
V_37 -> V_320 = V_316 -> V_321 ;
V_37 -> V_322 = ( V_37 -> V_320 / 2 ) ;
V_37 -> V_323 = V_37 -> V_322 ;
V_37 -> V_256 = ( V_37 -> V_320 - 1 ) ;
V_32 = F_207 ( V_37 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_47 ) ;
goto V_324;
}
V_37 -> V_205 = V_316 -> V_7 ;
V_37 -> V_325 = 0 ;
V_37 -> V_45 =
F_204 ( sizeof( struct V_38 * ) * V_44 ,
V_319 ) ;
if ( ! V_37 -> V_45 ) {
F_65 (KERN_ERR PFX L_48 ) ;
goto V_326;
}
V_37 -> V_249 = 0 ;
V_37 -> V_314 = F_208 ( V_37 ) ;
if ( ! V_37 -> V_314 ) {
F_65 (KERN_ERR PFX L_49 ) ;
goto V_327;
}
V_318 = & V_37 -> V_318 ;
V_318 -> V_328 = V_329 <<
V_330 ;
V_318 -> V_328 |= V_44 <<
V_331 ;
V_318 -> V_332 = V_37 -> V_323 <<
V_333 ;
V_318 -> V_332 |= V_334 <<
V_335 ;
V_318 -> V_336 = V_44 <<
V_337 ;
V_318 -> V_336 |= V_37 -> V_323 <<
V_338 ;
V_318 -> V_339 = V_340 ;
F_138 ( & V_37 -> V_248 ) ;
F_138 ( & V_37 -> V_223 ) ;
F_209 ( & V_37 -> V_341 ) ;
return V_37 ;
V_327:
F_100 ( V_37 -> V_45 ) ;
V_326:
F_202 ( V_37 ) ;
V_324:
F_100 ( V_37 ) ;
return NULL ;
}
struct V_4 * F_210 ( struct V_36 * V_37 ,
struct V_1 * V_7 ,
enum V_342 V_343 )
{
struct V_10 * V_11 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
int V_344 ;
int V_32 = 0 ;
V_344 = ( sizeof( * V_35 ) + sizeof( struct V_12 ) ) ;
V_11 = F_211 ( & V_7 -> V_99 , & V_345 ,
V_344 ) ;
if ( ! V_11 ) {
F_65 (KERN_ERR PFX L_50 ) ;
return NULL ;
}
V_13 = F_5 ( V_11 ) ;
V_13 -> V_226 = V_11 ;
V_35 = F_6 ( V_13 ) ;
F_212 ( V_7 ) ;
F_213 ( & V_35 -> V_310 ) ;
V_35 -> V_37 = V_37 ;
V_35 -> V_7 = V_7 ;
F_214 ( V_13 , V_343 ) ;
V_13 -> V_346 = F_157 ;
V_13 -> V_347 = F_155 ;
V_13 -> V_348 = F_156 ;
F_115 ( V_311 , & V_35 -> V_312 ) ;
V_32 = F_180 ( V_35 ) ;
if ( ! V_32 )
return V_35 ;
F_193 ( V_13 ) ;
F_195 ( V_7 ) ;
F_194 ( V_11 ) ;
return NULL ;
}
static struct V_2 * F_165 ( struct V_4 * V_35 ,
struct V_187 * V_349 , int V_350 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 , * V_284 ;
struct V_5 * V_34 ;
struct V_158 * V_159 ;
struct V_282 * V_196 = F_215 ( V_349 ) ;
struct V_292 * V_293 ;
struct V_36 * V_37 = V_35 -> V_37 ;
int V_32 = 0 ;
V_293 = F_204 ( sizeof( struct V_292 ) , V_319 ) ;
if ( ! V_293 ) {
F_34 ( V_13 -> V_16 , L_51 ) ;
return NULL ;
}
V_351 . V_352 = V_37 -> V_323 ;
if ( ! V_350 )
V_3 = F_216 ( & V_351 , sizeof( * V_34 ) ) ;
else
V_3 = F_217 ( V_196 , sizeof( * V_34 ) ) ;
if ( ! V_3 ) {
F_65 (KERN_ERR PFX L_52 ) ;
goto V_353;
}
V_159 = V_3 -> V_188 ;
V_34 = F_2 ( V_3 ) ;
V_34 -> V_3 = V_3 ;
V_34 -> V_6 = V_35 ;
V_34 -> V_354 = F_1 ;
F_218 ( & V_34 -> V_298 , V_355 ) ;
V_32 = F_150 ( V_3 ) ;
if ( V_32 )
goto V_356;
if ( V_350 ) {
F_65 (KERN_ERR PFX L_53 ,
vport->node_name, vport->port_name) ;
F_124 ( V_3 , V_196 -> V_357 ) ;
F_125 ( V_3 , V_196 -> V_286 ) ;
}
V_32 = F_117 ( V_3 , V_35 -> V_7 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_54 ) ;
goto V_356;
}
V_32 = F_108 ( V_3 , V_349 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_55 ,
interface->netdev->name) ;
goto V_356;
}
V_32 = F_142 ( V_3 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_56 ) ;
goto V_358;
}
F_136 ( V_3 -> V_188 ) = V_245 ;
if ( ! V_350 )
V_32 = F_148 ( V_3 , V_37 ) ;
else {
V_159 = F_161 ( V_196 ) ;
V_284 = F_102 ( V_159 ) ;
V_32 = F_219 ( V_284 , V_3 ) ;
}
if ( V_32 ) {
F_65 (KERN_ERR PFX L_57 ) ;
goto V_358;
}
F_197 ( V_35 ) ;
F_8 ( & V_37 -> V_43 ) ;
V_293 -> V_3 = V_3 ;
F_220 ( & V_293 -> V_22 , & V_37 -> V_341 ) ;
F_12 ( & V_37 -> V_43 ) ;
return V_3 ;
V_358:
F_221 ( V_159 ) ;
V_356:
F_222 ( V_3 -> V_188 ) ;
V_353:
F_100 ( V_293 ) ;
return NULL ;
}
static void F_223 ( struct V_4 * V_35 )
{
F_224 ( & V_35 -> V_125 ) ;
F_224 ( & V_35 -> V_279 ) ;
F_225 () ;
}
static void F_226 ( struct V_4 * V_35 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 = V_13 -> V_16 ;
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_36 * V_37 = V_35 -> V_37 ;
F_227 ( & V_34 -> V_218 ) ;
F_137 ( V_3 ) ;
F_223 ( V_35 ) ;
F_172 ( V_37 , V_3 ) ;
}
static void F_228 ( struct V_2 * V_3 )
{
F_7 ( V_3 ) ;
F_229 ( V_3 -> V_188 ) ;
F_221 ( V_3 -> V_188 ) ;
F_230 ( V_3 ) ;
F_231 ( V_3 ) ;
F_222 ( V_3 -> V_188 ) ;
}
static void F_129 ( struct V_4 * V_35 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 = V_13 -> V_16 ;
struct V_5 * V_34 = F_2 ( V_3 ) ;
F_226 ( V_35 ) ;
F_232 ( V_35 ) ;
F_173 ( & V_35 -> V_22 ) ;
F_176 ( V_35 ) ;
F_177 ( V_239 , & V_34 -> V_298 ) ;
}
static int F_233 ( struct V_1 * V_7 )
{
struct V_4 * V_35 = NULL ;
struct V_359 * V_360 ;
struct V_12 * V_13 ;
int V_32 = 0 ;
F_164 () ;
F_20 ( & V_237 ) ;
V_35 = F_234 ( V_7 ) ;
V_13 = F_32 ( V_35 ) ;
if ( ! V_35 || ! V_13 -> V_16 ) {
V_32 = - V_64 ;
F_65 (KERN_ERR PFX L_58 ) ;
goto V_361;
}
V_360 = V_35 -> V_360 ;
F_129 ( V_35 ) ;
F_235 ( V_360 ) ;
V_361:
F_23 ( & V_237 ) ;
F_166 () ;
return V_32 ;
}
static void V_355 ( struct V_362 * V_152 )
{
struct V_5 * V_34 ;
struct V_2 * V_3 ;
V_34 = F_64 ( V_152 , struct V_5 , V_298 ) ;
V_3 = V_34 -> V_3 ;
F_34 ( V_3 , L_59 ) ;
F_228 ( V_3 ) ;
}
static void F_236 ( struct V_36 * V_37 )
{
F_237 ( V_37 ) ;
F_238 ( V_37 ) ;
}
static int F_239 ( struct V_36 * V_37 )
{
if ( F_240 ( V_37 ) )
goto V_363;
if ( F_241 ( V_37 ) )
goto V_363;
return 0 ;
V_363:
F_236 ( V_37 ) ;
return - V_65 ;
}
static int F_207 ( struct V_36 * V_37 )
{
struct V_315 * V_316 ;
struct V_364 * V_365 ;
if ( ! V_37 -> V_316 ) {
F_65 (KERN_ERR PFX L_60 ) ;
return - V_64 ;
}
V_316 = V_37 -> V_316 ;
V_365 = V_37 -> V_366 = V_316 -> V_366 ;
if ( ! V_37 -> V_366 )
return - V_64 ;
switch ( V_365 -> V_187 ) {
case V_367 :
strncpy ( V_37 -> V_202 , L_61 , V_368 ) ;
break;
case V_369 :
strncpy ( V_37 -> V_202 , L_62 , V_368 ) ;
break;
case V_370 :
case V_371 :
case V_372 :
strncpy ( V_37 -> V_202 , L_63 , V_368 ) ;
break;
case V_373 :
case V_374 :
case V_375 :
strncpy ( V_37 -> V_202 , L_64 , V_368 ) ;
break;
case V_376 :
case V_377 :
case V_378 :
strncpy ( V_37 -> V_202 , L_65 , V_368 ) ;
break;
case V_379 :
case V_380 :
case V_381 :
case V_382 :
case V_383 :
strncpy ( V_37 -> V_202 , L_66 , V_368 ) ;
break;
default:
F_242 ( V_384 L_67 , V_365 -> V_187 ) ;
break;
}
F_243 ( V_37 -> V_366 ) ;
return 0 ;
}
static void F_202 ( struct V_36 * V_37 )
{
if ( V_37 -> V_366 ) {
V_37 -> V_202 [ 0 ] = '\0' ;
F_244 ( V_37 -> V_366 ) ;
}
V_37 -> V_366 = NULL ;
}
static int F_245 ( void * V_385 )
{
struct V_36 * V_37 = V_385 ;
struct V_315 * V_316 ;
struct V_386 * V_387 ;
if ( ! V_37 )
return - V_82 ;
V_316 = V_37 -> V_316 ;
V_387 = & V_316 -> V_387 -> V_388 ;
if ( ! V_387 )
return - V_82 ;
strncpy ( V_387 -> V_389 , V_203 ,
sizeof( V_387 -> V_389 ) ) ;
V_387 -> V_390 = V_391 ;
V_387 -> V_392 = V_393 ;
return 0 ;
}
static void F_246 ( void * V_385 )
{
struct V_36 * V_37 = V_385 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
struct V_2 * V_3 ;
F_20 ( & V_237 ) ;
if ( ! F_41 ( V_287 , & V_37 -> V_85 ) )
F_247 ( V_37 ) ;
F_19 ( L_68 ) ;
F_131 (interface, &if_list, list) {
if ( V_35 -> V_37 == V_37 ) {
V_13 = F_32 ( V_35 ) ;
V_3 = V_13 -> V_16 ;
F_65 (KERN_ERR PFX L_69 ) ;
V_3 -> V_251 . V_394 = F_31 ;
F_248 ( V_35 ) ;
}
}
F_23 ( & V_237 ) ;
}
static void F_175 ( struct V_2 * V_3 )
{
F_19 ( L_1 , V_41 ) ;
F_179 ( V_3 ) ;
F_249 ( V_3 ) ;
}
static void F_232 ( struct V_4 * V_35 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 ;
struct V_2 * V_196 ;
if ( ! F_41 ( V_287 , & V_35 -> V_37 -> V_85 ) )
return;
V_3 = V_13 -> V_16 ;
F_175 ( V_3 ) ;
F_20 ( & V_3 -> V_244 ) ;
F_131 (vport, &lport->vports, list)
F_136 ( V_196 -> V_188 ) =
V_245 ;
F_23 ( & V_3 -> V_244 ) ;
F_136 ( V_3 -> V_188 ) = V_245 ;
F_135 ( V_13 ) ;
F_137 ( V_3 ) ;
}
static int F_247 ( struct V_36 * V_37 )
{
#define F_250 (1000 / HZ)
int V_32 = - 1 ;
int V_40 = V_165 ;
V_32 = F_239 ( V_37 ) ;
if ( V_32 ) {
F_65 (KERN_ALERT PFX
L_70 , rc) ;
goto V_395;
}
V_32 = F_251 ( V_37 ) ;
if ( V_32 ) {
F_65 (KERN_ALERT PFX
L_71 , rc) ;
goto V_396;
}
while ( ! F_41 ( V_231 , & V_37 -> V_208 ) && V_40 -- )
F_252 ( F_250 ) ;
if ( ! F_41 ( V_231 , & V_37 -> V_208 ) ) {
F_65 (KERN_ERR PFX L_72
L_73 ,
hba->cnic->netdev->name) ;
V_32 = - 1 ;
goto V_396;
}
F_115 ( V_287 , & V_37 -> V_85 ) ;
return 0 ;
V_396:
F_236 ( V_37 ) ;
V_395:
return V_32 ;
}
static void F_253 ( struct V_36 * V_37 )
{
if ( F_192 ( V_287 , & V_37 -> V_85 ) ) {
if ( F_254 ( V_37 ) == 0 ) {
F_255 ( & V_37 -> V_397 ) ;
V_37 -> V_397 . V_398 = V_399 +
V_291 ;
V_37 -> V_397 . V_400 = F_126 ;
V_37 -> V_397 . V_147 = ( unsigned long ) V_37 ;
F_256 ( & V_37 -> V_397 ) ;
F_139 ( V_37 -> V_223 ,
F_41 ( V_222 ,
& V_37 -> V_85 ) ) ;
F_114 ( V_222 , & V_37 -> V_85 ) ;
if ( F_140 ( V_132 ) )
F_141 ( V_132 ) ;
F_227 ( & V_37 -> V_397 ) ;
}
F_236 ( V_37 ) ;
}
}
static void F_257 ( void * V_385 )
{
struct V_36 * V_37 = V_385 ;
struct V_4 * V_35 ;
F_65 ( V_232 L_74 ) ;
F_20 ( & V_237 ) ;
if ( ! F_41 ( V_287 , & V_37 -> V_85 ) )
goto exit;
F_131 (interface, &if_list, list) {
if ( V_35 -> V_37 == V_37 )
F_232 ( V_35 ) ;
}
F_258 ( V_37 -> V_249 != 0 ) ;
F_20 ( & V_37 -> V_42 ) ;
F_114 ( V_231 , & V_37 -> V_208 ) ;
F_114 ( V_234 ,
& V_37 -> V_208 ) ;
F_114 ( V_247 , & V_37 -> V_208 ) ;
F_23 ( & V_37 -> V_42 ) ;
F_253 ( V_37 ) ;
exit:
F_23 ( & V_237 ) ;
}
static void F_248 ( struct V_4 * V_35 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 ;
int V_401 = 0 ;
F_19 ( L_1 , V_41 ) ;
if ( ! F_41 ( V_287 , & V_35 -> V_37 -> V_85 ) ) {
F_65 (KERN_ERR PFX L_75 ) ;
return;
}
V_3 = V_13 -> V_16 ;
F_34 ( V_3 , L_76 ) ;
if ( ! F_112 ( V_3 ) && V_35 -> V_240 ) {
F_34 ( V_3 , L_77 ) ;
F_134 ( V_13 ) ;
F_136 ( V_3 -> V_188 ) = V_402 ;
F_115 ( V_247 , & V_35 -> V_37 -> V_208 ) ;
}
while ( ! V_13 -> V_81 ) {
F_252 ( 250 ) ;
if ( ++ V_401 > 12 )
break;
}
if ( F_118 ( V_3 , V_216 ) )
return;
F_169 ( V_3 ) ;
F_170 ( V_3 ) ;
}
static void F_259 ( struct V_315 * V_99 )
{
struct V_36 * V_37 ;
int V_32 = 0 ;
F_19 ( L_1 , V_41 ) ;
if ( ! F_41 ( V_403 , & V_99 -> V_85 ) ||
( V_99 -> V_404 == 0 ) ) {
F_65 (KERN_ERR PFX L_78
L_79 ,
dev->netdev->name, dev->flags, dev->max_fcoe_conn) ;
return;
}
V_37 = F_203 ( V_99 ) ;
if ( ! V_37 ) {
F_65 (KERN_ERR PFX L_80 ) ;
return;
}
F_20 ( & V_237 ) ;
F_220 ( & V_37 -> V_22 , & V_405 ) ;
V_406 ++ ;
F_23 ( & V_237 ) ;
V_99 -> V_318 = & V_37 -> V_318 ;
F_114 ( V_407 , & V_37 -> V_408 ) ;
V_32 = V_99 -> V_409 ( V_99 , V_410 ,
( void * ) V_37 ) ;
if ( V_32 )
F_65 (KERN_ERR PFX L_81 , rc) ;
else
F_115 ( V_407 , & V_37 -> V_408 ) ;
}
static int F_260 ( struct V_12 * V_13 )
{
struct V_4 * V_35 = F_6 ( V_13 ) ;
if ( V_35 -> V_240 == true ) {
if ( ! V_13 -> V_16 ) {
F_242 ( V_384 L_82 ) ;
return - V_64 ;
} else {
V_35 -> V_240 = false ;
F_135 ( V_13 ) ;
F_137 ( V_13 -> V_16 ) ;
}
}
return 0 ;
}
static int F_261 ( struct V_1 * V_7 )
{
struct V_4 * V_35 ;
struct V_12 * V_13 ;
int V_32 = 0 ;
F_164 () ;
F_20 ( & V_237 ) ;
V_35 = F_234 ( V_7 ) ;
V_13 = F_32 ( V_35 ) ;
if ( ! V_35 ) {
V_32 = - V_64 ;
F_242 ( V_384 L_83 ) ;
} else {
V_32 = F_260 ( V_13 ) ;
}
F_23 ( & V_237 ) ;
F_166 () ;
return V_32 ;
}
static int F_262 ( struct V_12 * V_13 )
{
struct V_4 * V_35 = F_6 ( V_13 ) ;
if ( V_35 -> V_240 == false ) {
if ( ! V_13 -> V_16 ) {
F_242 ( V_384 L_84 ) ;
return - V_64 ;
} else if ( ! F_112 ( V_13 -> V_16 ) ) {
F_134 ( V_13 ) ;
V_35 -> V_240 = true ;
}
}
return 0 ;
}
static int F_263 ( struct V_1 * V_7 )
{
struct V_4 * V_35 ;
struct V_12 * V_13 ;
int V_32 = 0 ;
F_164 () ;
F_20 ( & V_237 ) ;
V_35 = F_234 ( V_7 ) ;
V_13 = F_32 ( V_35 ) ;
if ( ! V_35 ) {
V_32 = - V_64 ;
F_242 ( V_384 L_85 ) ;
} else {
V_32 = F_262 ( V_13 ) ;
}
F_23 ( & V_237 ) ;
F_166 () ;
return V_32 ;
}
static int F_264 ( struct V_10 * V_226 )
{
struct V_12 * V_13 = F_5 ( V_226 ) ;
switch ( V_226 -> V_240 ) {
case V_242 :
return F_262 ( V_13 ) ;
case V_241 :
return F_260 ( V_13 ) ;
case V_243 :
default:
return - V_411 ;
} ;
}
static int F_265 ( struct V_1 * V_7 ,
enum V_342 V_343 ,
enum V_412 V_413 )
{
struct V_10 * V_226 ;
struct V_12 * V_13 ;
struct V_4 * V_35 ;
struct V_36 * V_37 ;
struct V_1 * V_205 = V_7 ;
struct V_2 * V_3 ;
struct V_414 V_415 ;
int V_32 = 0 ;
int V_15 = 0 ;
F_19 ( L_86 ) ;
if ( V_343 != V_416 ) {
F_65 ( V_232 L_87 ) ;
return - V_288 ;
}
F_164 () ;
F_20 ( & V_237 ) ;
if ( ! F_266 ( V_313 ) ) {
V_32 = - V_82 ;
goto V_417;
}
if ( V_7 -> V_418 & V_419 )
V_205 = F_267 ( V_7 ) ;
if ( V_205 -> V_213 && V_205 -> V_213 -> V_420 ) {
memset ( & V_415 , 0 , sizeof( V_415 ) ) ;
V_205 -> V_213 -> V_420 ( V_205 , & V_415 ) ;
if ( strncmp ( V_415 . V_421 , L_88 , strlen ( L_88 ) ) ) {
F_65 (KERN_ERR PFX L_89 ) ;
V_32 = - V_82 ;
goto V_361;
}
} else {
F_65 (KERN_ERR PFX L_90 ) ;
V_32 = - V_82 ;
goto V_361;
}
V_37 = F_268 ( V_205 ) ;
if ( ! V_37 ) {
V_32 = - V_64 ;
F_65 (KERN_ERR PFX L_91 ) ;
goto V_361;
}
if ( F_234 ( V_7 ) ) {
V_32 = - V_422 ;
goto V_361;
}
V_35 = F_210 ( V_37 , V_7 , V_343 ) ;
if ( ! V_35 ) {
F_65 (KERN_ERR PFX L_92 ) ;
goto V_423;
}
if ( V_7 -> V_418 & V_419 ) {
V_15 = F_269 ( V_7 ) ;
V_35 -> V_424 = 1 ;
}
V_13 = F_32 ( V_35 ) ;
V_226 = F_132 ( V_13 ) ;
V_35 -> V_15 = V_15 ;
V_35 -> V_360 =
F_270 ( L_93 ) ;
if ( ! V_35 -> V_360 ) {
F_65 (KERN_ERR PFX L_94 ) ;
V_32 = - V_82 ;
goto V_423;
}
V_3 = F_165 ( V_35 , & V_226 -> V_99 , 0 ) ;
if ( ! V_3 ) {
F_65 (KERN_ERR PFX L_95 ,
netdev->name) ;
V_32 = - V_82 ;
goto V_425;
}
F_220 ( & V_35 -> V_22 , & V_426 ) ;
V_3 -> V_290 = V_291 ;
V_13 -> V_16 = V_3 ;
if ( V_413 == V_427 )
V_226 -> V_240 = V_242 ;
else
V_226 -> V_240 = V_241 ;
if ( V_413 == V_427 &&
! F_112 ( V_3 ) ) {
F_134 ( V_13 ) ;
F_136 ( V_3 -> V_188 ) = V_402 ;
F_115 ( V_247 , & V_35 -> V_37 -> V_208 ) ;
}
F_34 ( V_3 , L_96 ) ;
F_248 ( V_35 ) ;
if ( V_413 == V_427 )
V_35 -> V_240 = true ;
F_176 ( V_35 ) ;
F_23 ( & V_237 ) ;
F_166 () ;
return 0 ;
V_425:
F_235 ( V_35 -> V_360 ) ;
V_423:
F_223 ( V_35 ) ;
F_176 ( V_35 ) ;
goto V_417;
V_361:
F_196 ( V_313 ) ;
V_417:
F_23 ( & V_237 ) ;
F_166 () ;
return V_32 ;
}
static int F_271 ( struct V_1 * V_7 , enum V_342 V_343 )
{
return F_265 ( V_7 , V_343 , V_427 ) ;
}
static int F_272 ( struct V_1 * V_7 )
{
return F_265 ( V_7 , V_416 ,
V_428 ) ;
}
static struct V_36 * F_273 ( struct V_315 * V_316 )
{
struct V_36 * V_37 ;
F_131 (hba, &adapter_list, list) {
if ( V_37 -> V_316 == V_316 )
return V_37 ;
}
return NULL ;
}
static struct V_4 * F_234 ( struct V_1
* V_7 )
{
struct V_4 * V_35 ;
F_131 (interface, &if_list, list) {
if ( V_35 -> V_7 == V_7 )
return V_35 ;
}
return NULL ;
}
static struct V_36 * F_268 ( struct V_1
* V_205 )
{
struct V_36 * V_37 ;
F_131 (hba, &adapter_list, list) {
if ( V_37 -> V_205 == V_205 )
return V_37 ;
}
F_65 (KERN_ERR PFX L_97 ) ;
return NULL ;
}
static void F_274 ( struct V_315 * V_99 )
{
struct V_36 * V_37 ;
struct V_4 * V_35 , * V_153 ;
F_19 ( L_98 ) ;
if ( ! F_41 ( V_403 , & V_99 -> V_85 ) ) {
F_65 (KERN_ERR PFX L_99 ,
dev->netdev->name, dev->flags) ;
return;
}
F_20 ( & V_237 ) ;
V_37 = F_273 ( V_99 ) ;
if ( ! V_37 ) {
F_65 (KERN_ERR PFX L_100 ,
dev) ;
F_23 ( & V_237 ) ;
return;
}
F_98 ( & V_37 -> V_22 ) ;
V_406 -- ;
F_97 (interface, tmp, &if_list, list)
if ( V_35 -> V_37 == V_37 )
F_129 ( V_35 ) ;
F_23 ( & V_237 ) ;
F_130 ( V_239 ) ;
F_257 ( V_37 ) ;
if ( F_192 ( V_407 , & V_37 -> V_408 ) )
V_37 -> V_316 -> V_429 ( V_37 -> V_316 , V_410 ) ;
F_200 ( V_37 ) ;
}
static int F_275 ( struct V_158 * V_159 )
{
struct V_2 * V_3 = F_102 ( V_159 ) ;
F_276 ( V_3 ) ;
return 0 ;
}
static bool F_277 ( struct V_1 * V_7 )
{
struct V_1 * V_205 = V_7 ;
F_20 ( & V_237 ) ;
if ( V_7 -> V_418 & V_419 )
V_205 = F_267 ( V_7 ) ;
if ( F_268 ( V_205 ) ) {
F_23 ( & V_237 ) ;
return true ;
}
F_23 ( & V_237 ) ;
return false ;
}
static void F_278 ( unsigned int V_430 )
{
struct V_149 * V_150 ;
struct V_431 * V_130 ;
V_150 = & F_279 ( V_432 , V_430 ) ;
V_130 = F_280 ( F_93 ,
( void * ) V_150 , F_281 ( V_430 ) ,
L_101 , V_430 ) ;
if ( F_282 ( ! F_167 ( V_130 ) ) ) {
F_283 ( V_130 , V_430 ) ;
V_150 -> V_433 = V_130 ;
F_71 ( V_130 ) ;
}
}
static void F_284 ( unsigned int V_430 )
{
struct V_149 * V_150 ;
struct V_431 * V_130 ;
struct V_151 * V_152 , * V_153 ;
F_19 ( L_102 , V_430 ) ;
V_150 = & F_279 ( V_432 , V_430 ) ;
F_8 ( & V_150 -> V_155 ) ;
V_130 = V_150 -> V_433 ;
V_150 -> V_433 = NULL ;
F_97 (work, tmp, &p->work_list, list) {
F_98 ( & V_152 -> V_22 ) ;
F_99 ( V_152 -> V_39 , V_152 -> V_156 ) ;
F_100 ( V_152 ) ;
}
F_12 ( & V_150 -> V_155 ) ;
if ( V_130 )
F_285 ( V_130 ) ;
}
static int F_286 ( struct V_434 * V_435 ,
unsigned long V_436 , void * V_437 )
{
unsigned V_430 = ( unsigned long ) V_437 ;
switch ( V_436 ) {
case V_438 :
case V_439 :
F_65 ( V_384 L_103 , V_430 ) ;
F_278 ( V_430 ) ;
break;
case V_440 :
case V_441 :
F_65 ( V_384 L_104 , V_430 ) ;
F_284 ( V_430 ) ;
break;
default:
break;
}
return V_442 ;
}
static int T_6 F_287 ( void )
{
struct V_17 * V_18 ;
struct V_431 * V_443 ;
int V_32 = 0 ;
unsigned int V_430 = 0 ;
struct V_149 * V_150 ;
F_65 (KERN_INFO PFX L_105 , version) ;
V_32 = F_288 ( & V_444 ) ;
if ( V_32 ) {
F_65 ( V_232 L_106
L_107 ) ;
goto V_445;
}
F_209 ( & V_405 ) ;
F_209 ( & V_426 ) ;
F_206 ( & V_237 ) ;
V_406 = 0 ;
V_32 = F_187 () ;
if ( V_32 )
goto V_446;
V_239 = F_289 ( L_108 , 0 , 0 ) ;
if ( ! V_239 ) {
V_32 = - V_65 ;
goto V_447;
}
V_18 = & V_27 ;
F_119 ( & V_18 -> V_28 ) ;
V_443 = F_290 ( F_72 ,
( void * ) V_18 ,
L_109 ) ;
if ( F_167 ( V_443 ) ) {
V_32 = F_291 ( V_443 ) ;
goto V_448;
}
F_71 ( V_443 ) ;
F_8 ( & V_18 -> V_28 . V_29 ) ;
V_18 -> V_130 = V_443 ;
F_12 ( & V_18 -> V_28 . V_29 ) ;
F_292 (cpu) {
V_150 = & F_279 ( V_432 , V_430 ) ;
F_209 ( & V_150 -> V_154 ) ;
F_205 ( & V_150 -> V_155 ) ;
}
F_293 () ;
F_294 (cpu) {
F_278 ( V_430 ) ;
}
F_295 ( & V_449 ) ;
F_296 () ;
F_297 ( V_410 , & V_450 ) ;
return 0 ;
V_448:
F_235 ( V_239 ) ;
V_447:
F_190 () ;
V_446:
F_298 ( & V_444 ) ;
V_445:
return V_32 ;
}
static void T_7 F_299 ( void )
{
F_94 ( V_451 ) ;
struct V_36 * V_37 , * V_25 ;
struct V_17 * V_18 ;
struct V_431 * V_443 ;
struct V_23 * V_24 ;
unsigned int V_430 = 0 ;
F_20 ( & V_237 ) ;
F_300 ( & V_405 , & V_451 ) ;
F_209 ( & V_405 ) ;
V_406 = 0 ;
F_23 ( & V_237 ) ;
F_97 (hba, next, &to_be_deleted, list) {
F_98 ( & V_37 -> V_22 ) ;
F_65 (KERN_ERR PFX L_110 ,
hba) ;
F_257 ( V_37 ) ;
if ( F_192 ( V_407 ,
& V_37 -> V_408 ) )
V_37 -> V_316 -> V_429 ( V_37 -> V_316 ,
V_410 ) ;
F_200 ( V_37 ) ;
}
F_301 ( V_410 ) ;
V_18 = & V_27 ;
F_8 ( & V_18 -> V_28 . V_29 ) ;
V_443 = V_18 -> V_130 ;
V_18 -> V_130 = NULL ;
while ( ( V_24 = F_77 ( & V_18 -> V_28 ) ) != NULL )
F_11 ( V_24 ) ;
F_12 ( & V_18 -> V_28 . V_29 ) ;
if ( V_443 )
F_285 ( V_443 ) ;
F_293 () ;
F_294 (cpu) {
F_284 ( V_430 ) ;
}
F_302 ( & V_449 ) ;
F_296 () ;
F_235 ( V_239 ) ;
F_190 () ;
F_298 ( & V_444 ) ;
}
