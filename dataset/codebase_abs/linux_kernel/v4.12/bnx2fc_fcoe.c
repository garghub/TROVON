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
static int F_93 ( void * V_131 )
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
F_20 ( & V_37 -> V_164 ) ;
V_160 = F_103 ( V_159 ) ;
F_104 ( & V_37 -> V_165 ) ;
if ( F_105 ( V_37 ) )
goto V_166;
V_32 = F_106 ( & V_37 -> V_165 , ( 2 * V_167 ) ) ;
if ( ! V_32 ) {
F_34 ( V_3 , L_18 ) ;
goto V_166;
}
F_107 ( V_37 , V_168 , V_169 ) ;
V_160 -> V_170 += V_37 -> V_171 . V_169 ;
F_107 ( V_37 , V_172 , V_173 ) ;
V_160 -> V_174 += V_37 -> V_171 . V_173 ;
F_107 ( V_37 , V_172 , V_175 ) ;
V_160 -> V_176 += ( ( V_37 -> V_171 . V_175 ) / 4 ) ;
F_107 ( V_37 , V_177 , V_178 ) ;
V_160 -> V_179 += V_37 -> V_171 . V_178 ;
F_107 ( V_37 , V_177 , V_180 ) ;
V_160 -> V_181 += ( ( V_37 -> V_171 . V_180 ) / 4 ) ;
V_160 -> V_182 = 0 ;
V_160 -> V_183 = 0 ;
V_160 -> V_184 = 0 ;
V_160 -> V_185 = 0 ;
V_160 -> V_186 = 0 ;
V_160 -> V_187 = 0 ;
memcpy ( & V_37 -> V_188 , V_37 -> V_163 ,
sizeof( struct V_161 ) ) ;
V_166:
F_23 ( & V_37 -> V_164 ) ;
return V_160 ;
}
static int F_108 ( struct V_2 * V_3 , struct V_189 * V_99 )
{
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_158 * V_159 = V_3 -> V_190 ;
int V_32 = 0 ;
V_159 -> V_191 = V_192 ;
V_159 -> V_193 = V_194 ;
V_159 -> V_195 = V_196 ;
V_159 -> V_197 = 0 ;
if ( V_3 -> V_198 )
V_159 -> V_199 = V_200 ;
else
V_159 -> V_199 = V_201 ;
V_32 = F_109 ( V_3 -> V_190 , V_99 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_19 ) ;
return V_32 ;
}
if ( ! V_3 -> V_198 )
F_110 ( V_3 -> V_190 ) = V_202 ;
snprintf ( F_111 ( V_3 -> V_190 ) , 256 ,
L_20 ,
V_203 , V_37 -> V_204 , V_205 ,
V_35 -> V_7 -> V_206 ) ;
return 0 ;
}
static int F_112 ( struct V_2 * V_3 )
{
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_1 * V_99 = V_37 -> V_207 ;
int V_32 = 0 ;
if ( ( V_99 -> V_85 & V_208 ) && F_113 ( V_99 ) )
F_114 ( V_209 , & V_37 -> V_210 ) ;
else {
F_115 ( V_209 , & V_37 -> V_210 ) ;
V_32 = - 1 ;
}
return V_32 ;
}
void F_116 ( struct V_36 * V_37 )
{
if ( F_41 ( V_211 , & V_37 -> V_207 -> V_212 ) )
F_115 ( V_209 , & V_37 -> V_210 ) ;
else
F_114 ( V_209 , & V_37 -> V_210 ) ;
}
static int F_117 ( struct V_2 * V_3 , struct V_1 * V_7 )
{
struct V_36 * V_37 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
struct V_5 * V_34 ;
T_4 V_213 , V_214 ;
V_34 = F_2 ( V_3 ) ;
V_35 = V_34 -> V_6 ;
V_13 = F_32 ( V_35 ) ;
V_37 = V_35 -> V_37 ;
if ( ! V_37 -> V_207 -> V_215 ||
! V_37 -> V_207 -> V_215 -> V_216 )
return - V_217 ;
if ( F_118 ( V_3 , V_218 ) )
return - V_82 ;
F_119 ( & V_34 -> V_118 ) ;
V_34 -> V_219 = 0 ;
F_120 ( & V_34 -> V_220 , V_221 , ( unsigned long ) V_3 ) ;
F_121 ( V_3 ) ;
if ( ! V_3 -> V_198 ) {
if ( F_122 ( V_7 , & V_213 , V_222 ) )
V_213 = F_123 ( V_13 -> V_108 ,
1 , 0 ) ;
F_34 ( V_3 , L_21 , V_213 ) ;
F_124 ( V_3 , V_213 ) ;
if ( F_122 ( V_7 , & V_214 , V_223 ) )
V_214 = F_123 ( V_13 -> V_108 ,
2 , 0 ) ;
F_34 ( V_3 , L_22 , V_214 ) ;
F_125 ( V_3 , V_214 ) ;
}
return 0 ;
}
static void F_126 ( unsigned long V_147 )
{
struct V_36 * V_37 = (struct V_36 * ) V_147 ;
F_65 (KERN_ERR PFX L_23
L_24 ) ;
F_115 ( V_224 , & V_37 -> V_85 ) ;
F_127 ( & V_37 -> V_225 ) ;
}
static void F_128 ( void * V_226 , unsigned long V_227 ,
T_5 V_15 )
{
struct V_36 * V_37 = (struct V_36 * ) V_226 ;
struct V_10 * V_228 ;
struct V_2 * V_3 ;
struct V_2 * V_198 ;
struct V_4 * V_35 , * V_153 ;
struct V_12 * V_13 ;
int V_229 = 0 ;
T_2 V_230 = 1 ;
if ( V_15 != 0 && V_227 != V_231 )
return;
switch ( V_227 ) {
case V_232 :
if ( ! F_41 ( V_233 , & V_37 -> V_210 ) )
F_65 ( V_234 L_25\
L_26 ) ;
break;
case V_235 :
F_114 ( V_236 , & V_37 -> V_210 ) ;
F_114 ( V_233 , & V_37 -> V_210 ) ;
V_230 = 0 ;
break;
case V_237 :
F_115 ( V_236 , & V_37 -> V_210 ) ;
V_230 = 0 ;
break;
case V_238 :
break;
case V_231 :
if ( ! V_15 )
return;
F_20 ( & V_239 ) ;
F_97 (interface, tmp, &if_list, list) {
if ( V_35 -> V_37 == V_37 &&
V_35 -> V_15 == ( V_15 & V_240 ) )
F_129 ( V_35 ) ;
}
F_23 ( & V_239 ) ;
F_130 ( V_241 ) ;
return;
default:
return;
}
F_20 ( & V_239 ) ;
F_131 (interface, &if_list, list) {
if ( V_35 -> V_37 != V_37 )
continue;
V_13 = F_32 ( V_35 ) ;
V_3 = V_13 -> V_16 ;
F_34 ( V_3 , L_27 ,
V_35 -> V_7 -> V_206 , V_227 ) ;
F_121 ( V_3 ) ;
V_228 = F_132 ( V_13 ) ;
if ( V_230 && ! F_112 ( V_3 ) ) {
switch ( V_228 -> V_242 ) {
case V_243 :
F_133 ( L_28 ) ;
break;
case V_244 :
case V_245 :
F_118 ( V_3 , V_218 ) ;
if ( V_35 -> V_242 )
F_134 ( V_13 ) ;
} ;
} else if ( F_135 ( V_13 ) ) {
switch ( V_228 -> V_242 ) {
case V_243 :
F_133 ( L_29 ) ;
break;
case V_244 :
case V_245 :
F_20 ( & V_3 -> V_246 ) ;
F_131 (vport, &lport->vports, list)
F_136 ( V_198 -> V_190 ) =
V_247 ;
F_23 ( & V_3 -> V_246 ) ;
F_136 ( V_3 -> V_190 ) =
V_247 ;
F_58 ( V_3 -> V_73 ,
F_59 () ) -> V_248 ++ ;
F_60 () ;
F_137 ( V_3 ) ;
V_229 = 1 ;
} ;
}
}
F_23 ( & V_239 ) ;
if ( V_229 ) {
F_114 ( V_249 , & V_37 -> V_210 ) ;
F_138 ( & V_37 -> V_250 ) ;
F_19 ( L_30
L_31 ,
V_37 -> V_251 ) ;
V_37 -> V_252 = 1 ;
F_139 ( V_37 -> V_250 ,
( V_37 -> V_251 == 0 ) ) ;
F_19 ( L_32 ,
V_37 -> V_251 ) ;
V_37 -> V_252 = 0 ;
if ( F_140 ( V_132 ) )
F_141 ( V_132 ) ;
}
}
static int F_142 ( struct V_2 * V_3 )
{
memcpy ( & V_3 -> V_253 , & V_254 ,
sizeof( struct V_255 ) ) ;
F_143 ( V_3 ) ;
F_144 ( V_3 ) ;
F_145 ( V_3 ) ;
F_146 ( V_3 , V_3 ) ;
return 0 ;
}
static int F_147 ( struct V_2 * V_3 , struct V_36 * V_37 )
{
int V_256 , V_257 ;
V_256 = V_37 -> V_258 + 1 ;
if ( V_259 <= 2 )
V_257 = V_37 -> V_258 + V_260 ;
else
V_257 = V_37 -> V_258 + V_261 ;
if ( ! F_148 ( V_3 , V_262 , V_256 ,
V_257 , NULL ) ) {
F_65 (KERN_ERR PFX L_33 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_149 ( struct V_2 * V_3 )
{
V_3 -> V_80 = 0 ;
V_3 -> V_263 = 0 ;
V_3 -> V_264 = V_265 ;
V_3 -> V_266 = V_267 ;
V_3 -> V_268 = 2 * 1000 ;
V_3 -> V_269 = 10 * 1000 ;
V_3 -> V_270 = ( V_271 | V_272 |
V_273 | V_274 ) ;
V_3 -> V_275 = 1 ;
memset ( & V_3 -> V_276 , 0 , sizeof( struct V_277 ) ) ;
V_3 -> V_276 . V_278 = V_279 ;
if ( F_150 ( V_3 ) )
return - V_65 ;
F_151 ( V_3 ) ;
return 0 ;
}
static int F_152 ( struct V_23 * V_24 , struct V_1 * V_99 ,
struct V_120 * V_121 ,
struct V_1 * V_280 )
{
struct V_4 * V_35 ;
struct V_12 * V_13 ;
V_35 = F_64 ( V_121 , struct V_4 ,
V_281 ) ;
V_13 = F_32 ( V_35 ) ;
F_153 ( V_13 , V_24 ) ;
return 0 ;
}
static void F_154 ( struct V_2 * V_3 , T_1 * V_282 )
{
struct V_5 * V_34 = F_2 ( V_3 ) ;
memcpy ( V_34 -> V_109 , V_282 , V_104 ) ;
}
static T_1 * F_155 ( struct V_2 * V_3 )
{
struct V_5 * V_34 ;
V_34 = (struct V_5 * ) F_2 ( V_3 ) ;
return V_34 -> V_109 ;
}
static void F_156 ( struct V_12 * V_283 , struct V_23 * V_24 )
{
struct V_284 * V_285 ;
struct V_66 * F_54 ;
T_5 V_286 ;
T_1 V_287 ;
V_285 = (struct V_284 * ) ( ( void * ) V_24 -> V_147 + 2 * V_104 + 2 ) ;
F_54 = (struct V_66 * ) F_157 ( V_24 ) ;
V_286 = F_26 ( V_285 -> V_288 ) ;
V_287 = V_285 -> V_289 ;
if ( V_286 == V_290 && V_287 == V_291 && V_292 )
F_19 ( L_34 ,
F_54 -> V_107 , F_54 -> V_102 ) ;
V_24 -> V_99 = F_158 ( V_283 ) -> V_7 ;
F_159 ( V_24 ) ;
}
static int F_160 ( struct V_293 * V_198 , bool V_294 )
{
struct V_158 * V_159 = F_161 ( V_198 ) ;
struct V_2 * V_295 = F_102 ( V_159 ) ;
struct V_5 * V_34 = F_2 ( V_295 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_1 * V_7 = V_35 -> V_7 ;
struct V_2 * V_138 ;
int V_32 ;
char V_296 [ 32 ] ;
V_32 = F_162 ( V_198 ) ;
if ( V_32 ) {
F_163 ( V_198 -> V_297 , V_296 , sizeof( V_296 ) ) ;
F_65 (KERN_ERR PFX L_35
L_36 ,
buf) ;
return V_32 ;
}
if ( ! F_41 ( V_298 , & V_35 -> V_37 -> V_85 ) ) {
F_65 (KERN_ERR PFX L_37
L_38 ) ;
return - V_299 ;
}
F_164 () ;
F_20 ( & V_239 ) ;
V_138 = F_165 ( V_35 , & V_198 -> V_99 , 1 ) ;
F_23 ( & V_239 ) ;
F_166 () ;
if ( ! V_138 ) {
F_65 (KERN_ERR PFX L_39 ,
netdev->name) ;
return - V_299 ;
}
if ( V_300 )
F_167 ( V_138 -> V_190 ) = V_300 ;
if ( V_294 ) {
F_168 ( V_198 , V_301 ) ;
} else {
V_138 -> V_302 = V_303 ;
F_169 ( V_138 ) ;
F_170 ( V_138 ) ;
F_171 ( V_138 ) ;
}
return 0 ;
}
static void F_172 ( struct V_36 * V_37 , struct V_2 * V_3 )
{
struct V_304 * V_305 , * V_153 ;
F_8 ( & V_37 -> V_43 ) ;
F_97 (blport, tmp, &hba->vports, list) {
if ( V_305 -> V_3 == V_3 ) {
F_173 ( & V_305 -> V_22 ) ;
F_100 ( V_305 ) ;
}
}
F_12 ( & V_37 -> V_43 ) ;
}
static int F_174 ( struct V_293 * V_198 )
{
struct V_158 * V_159 = F_161 ( V_198 ) ;
struct V_2 * V_295 = F_102 ( V_159 ) ;
struct V_2 * V_138 = V_198 -> V_306 ;
struct V_5 * V_34 = F_2 ( V_138 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_2 * V_307 ;
bool V_308 = false ;
F_20 ( & V_295 -> V_246 ) ;
F_131 (v_port, &n_port->vports, list)
if ( V_307 -> V_198 == V_198 ) {
V_308 = true ;
break;
}
if ( ! V_308 ) {
F_23 ( & V_295 -> V_246 ) ;
return - V_309 ;
}
F_173 ( & V_138 -> V_22 ) ;
F_23 ( & V_295 -> V_246 ) ;
F_172 ( V_35 -> V_37 , V_34 -> V_3 ) ;
F_175 ( V_34 -> V_3 ) ;
F_176 ( V_35 ) ;
F_177 ( V_241 , & V_34 -> V_310 ) ;
return 0 ;
}
static int F_178 ( struct V_293 * V_198 , bool V_311 )
{
struct V_2 * V_3 = V_198 -> V_306 ;
if ( V_311 ) {
F_168 ( V_198 , V_301 ) ;
F_179 ( V_3 ) ;
} else {
V_3 -> V_302 = V_303 ;
F_170 ( V_3 ) ;
F_171 ( V_3 ) ;
}
return 0 ;
}
static int F_180 ( struct V_4 * V_35 )
{
struct V_1 * V_7 = V_35 -> V_7 ;
struct V_1 * V_312 = V_35 -> V_37 -> V_207 ;
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_313 * V_314 ;
int V_315 = 0 ;
F_181 () ;
F_182 (physdev, ha) {
F_19 ( L_40 ,
V_314 -> type ) ;
F_65 ( V_316 L_41 , V_314 -> V_282 [ 0 ] ,
V_314 -> V_282 [ 1 ] , V_314 -> V_282 [ 2 ] , V_314 -> V_282 [ 3 ] ,
V_314 -> V_282 [ 4 ] , V_314 -> V_282 [ 5 ] ) ;
if ( ( V_314 -> type == V_317 ) &&
( F_183 ( V_314 -> V_282 ) ) ) {
memcpy ( V_13 -> V_108 , V_314 -> V_282 ,
V_104 ) ;
V_315 = 1 ;
F_19 ( L_42 ) ;
}
}
F_184 () ;
if ( ! V_315 )
return - V_64 ;
V_35 -> V_281 . V_318 = F_152 ;
V_35 -> V_281 . type = F_53 ( V_319 ) ;
V_35 -> V_281 . V_99 = V_7 ;
F_185 ( & V_35 -> V_281 ) ;
V_35 -> V_125 . V_318 = F_63 ;
V_35 -> V_125 . type = F_186 ( V_98 ) ;
V_35 -> V_125 . V_99 = V_7 ;
F_185 ( & V_35 -> V_125 ) ;
return 0 ;
}
static int F_187 ( void )
{
V_201 =
F_188 ( & V_320 ) ;
if ( V_201 == NULL ) {
F_65 (KERN_ERR PFX L_43 ) ;
return - V_64 ;
}
V_200 =
F_188 ( & V_321 ) ;
if ( V_200 == NULL ) {
F_65 (KERN_ERR PFX
L_44 ) ;
F_189 ( V_201 ) ;
V_201 = NULL ;
return - V_64 ;
}
return 0 ;
}
static void F_190 ( void )
{
F_189 ( V_201 ) ;
F_189 ( V_200 ) ;
V_201 = NULL ;
V_200 = NULL ;
}
static void F_191 ( struct V_322 * V_322 )
{
struct V_10 * V_11 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
struct V_1 * V_7 ;
V_35 = F_64 ( V_322 , struct V_4 , V_322 ) ;
F_19 ( L_45 ) ;
V_13 = F_32 ( V_35 ) ;
V_11 = F_132 ( V_13 ) ;
V_7 = V_35 -> V_7 ;
if ( F_192 ( V_323 , & V_35 -> V_324 ) )
F_193 ( V_13 ) ;
F_194 ( V_11 ) ;
F_195 ( V_7 ) ;
F_196 ( V_325 ) ;
}
static inline void F_197 ( struct V_4 * V_35 )
{
F_198 ( & V_35 -> V_322 ) ;
}
static inline void F_176 ( struct V_4 * V_35 )
{
F_199 ( & V_35 -> V_322 , F_191 ) ;
}
static void F_200 ( struct V_36 * V_37 )
{
if ( V_37 -> V_326 ) {
F_201 ( V_37 -> V_326 ) ;
V_37 -> V_326 = NULL ;
}
F_100 ( V_37 -> V_45 ) ;
F_202 ( V_37 ) ;
F_100 ( V_37 ) ;
}
static struct V_36 * F_203 ( struct V_327 * V_328 )
{
struct V_36 * V_37 ;
struct V_329 * V_330 ;
int V_32 ;
V_37 = F_204 ( sizeof( * V_37 ) , V_331 ) ;
if ( ! V_37 ) {
F_65 (KERN_ERR PFX L_46 ) ;
return NULL ;
}
F_205 ( & V_37 -> V_43 ) ;
F_206 ( & V_37 -> V_42 ) ;
F_206 ( & V_37 -> V_164 ) ;
V_37 -> V_328 = V_328 ;
V_37 -> V_332 = V_328 -> V_333 ;
V_37 -> V_334 = ( V_37 -> V_332 / 2 ) ;
V_37 -> V_335 = V_37 -> V_334 ;
V_37 -> V_258 = ( V_37 -> V_332 - 1 ) ;
V_32 = F_207 ( V_37 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_47 ) ;
goto V_336;
}
V_37 -> V_207 = V_328 -> V_7 ;
V_37 -> V_337 = 0 ;
V_37 -> V_45 =
F_204 ( sizeof( struct V_38 * ) * V_44 ,
V_331 ) ;
if ( ! V_37 -> V_45 ) {
F_65 (KERN_ERR PFX L_48 ) ;
goto V_338;
}
V_37 -> V_251 = 0 ;
V_37 -> V_326 = F_208 ( V_37 ) ;
if ( ! V_37 -> V_326 ) {
F_65 (KERN_ERR PFX L_49 ) ;
goto V_339;
}
V_330 = & V_37 -> V_330 ;
V_330 -> V_340 = V_341 <<
V_342 ;
V_330 -> V_340 |= V_44 <<
V_343 ;
V_330 -> V_344 = V_37 -> V_335 <<
V_345 ;
V_330 -> V_344 |= V_346 <<
V_347 ;
V_330 -> V_348 = V_44 <<
V_349 ;
V_330 -> V_348 |= V_37 -> V_335 <<
V_350 ;
V_330 -> V_351 = V_352 ;
F_138 ( & V_37 -> V_250 ) ;
F_138 ( & V_37 -> V_225 ) ;
F_209 ( & V_37 -> V_353 ) ;
return V_37 ;
V_339:
F_100 ( V_37 -> V_45 ) ;
V_338:
F_202 ( V_37 ) ;
V_336:
F_100 ( V_37 ) ;
return NULL ;
}
static struct V_4 *
F_210 ( struct V_36 * V_37 ,
struct V_1 * V_7 ,
enum V_354 V_355 )
{
struct V_10 * V_11 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
int V_356 ;
int V_32 = 0 ;
V_356 = ( sizeof( * V_35 ) + sizeof( struct V_12 ) ) ;
V_11 = F_211 ( & V_7 -> V_99 , & V_357 ,
V_356 ) ;
if ( ! V_11 ) {
F_65 (KERN_ERR PFX L_50 ) ;
return NULL ;
}
V_13 = F_5 ( V_11 ) ;
V_13 -> V_228 = V_11 ;
V_35 = F_6 ( V_13 ) ;
F_212 ( V_7 ) ;
F_213 ( & V_35 -> V_322 ) ;
V_35 -> V_37 = V_37 ;
V_35 -> V_7 = V_7 ;
F_214 ( V_13 , V_355 ) ;
V_13 -> V_358 = F_156 ;
V_13 -> V_359 = F_154 ;
V_13 -> V_360 = F_155 ;
F_115 ( V_323 , & V_35 -> V_324 ) ;
V_32 = F_180 ( V_35 ) ;
if ( ! V_32 )
return V_35 ;
F_193 ( V_13 ) ;
F_195 ( V_7 ) ;
F_194 ( V_11 ) ;
return NULL ;
}
static struct V_2 * F_165 ( struct V_4 * V_35 ,
struct V_189 * V_361 , int V_362 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 , * V_295 ;
struct V_5 * V_34 ;
struct V_158 * V_159 ;
struct V_293 * V_198 = F_215 ( V_361 ) ;
struct V_304 * V_305 ;
struct V_36 * V_37 = V_35 -> V_37 ;
int V_32 = 0 ;
V_305 = F_204 ( sizeof( struct V_304 ) , V_331 ) ;
if ( ! V_305 ) {
F_34 ( V_13 -> V_16 , L_51 ) ;
return NULL ;
}
V_363 . V_364 = V_37 -> V_335 ;
if ( ! V_362 )
V_3 = F_216 ( & V_363 , sizeof( * V_34 ) ) ;
else
V_3 = F_217 ( V_198 , sizeof( * V_34 ) ) ;
if ( ! V_3 ) {
F_65 (KERN_ERR PFX L_52 ) ;
goto V_365;
}
V_159 = V_3 -> V_190 ;
V_34 = F_2 ( V_3 ) ;
V_34 -> V_3 = V_3 ;
V_34 -> V_6 = V_35 ;
V_34 -> V_366 = F_1 ;
F_218 ( & V_34 -> V_310 , V_367 ) ;
V_32 = F_149 ( V_3 ) ;
if ( V_32 )
goto V_368;
if ( V_362 ) {
F_65 (KERN_ERR PFX L_53 ,
vport->node_name, vport->port_name) ;
F_124 ( V_3 , V_198 -> V_369 ) ;
F_125 ( V_3 , V_198 -> V_297 ) ;
}
V_32 = F_117 ( V_3 , V_35 -> V_7 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_54 ) ;
goto V_368;
}
V_32 = F_108 ( V_3 , V_361 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_55 ,
interface->netdev->name) ;
goto V_368;
}
V_32 = F_142 ( V_3 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_56 ) ;
goto V_370;
}
F_136 ( V_3 -> V_190 ) = V_247 ;
if ( V_300 )
F_167 ( V_159 ) = V_300 ;
if ( ! V_362 )
V_32 = F_147 ( V_3 , V_37 ) ;
else {
V_159 = F_161 ( V_198 ) ;
V_295 = F_102 ( V_159 ) ;
V_32 = F_219 ( V_295 , V_3 ) ;
}
if ( V_32 ) {
F_65 (KERN_ERR PFX L_57 ) ;
goto V_370;
}
F_197 ( V_35 ) ;
F_8 ( & V_37 -> V_43 ) ;
V_305 -> V_3 = V_3 ;
F_220 ( & V_305 -> V_22 , & V_37 -> V_353 ) ;
F_12 ( & V_37 -> V_43 ) ;
return V_3 ;
V_370:
F_221 ( V_159 ) ;
V_368:
F_222 ( V_3 -> V_190 ) ;
V_365:
F_100 ( V_305 ) ;
return NULL ;
}
static void F_223 ( struct V_4 * V_35 )
{
F_224 ( & V_35 -> V_125 ) ;
F_224 ( & V_35 -> V_281 ) ;
F_225 () ;
}
static void F_226 ( struct V_4 * V_35 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 = V_13 -> V_16 ;
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_36 * V_37 = V_35 -> V_37 ;
F_227 ( & V_34 -> V_220 ) ;
F_137 ( V_3 ) ;
F_223 ( V_35 ) ;
F_172 ( V_37 , V_3 ) ;
}
static void F_228 ( struct V_2 * V_3 )
{
F_7 ( V_3 ) ;
F_229 ( V_3 -> V_190 ) ;
F_221 ( V_3 -> V_190 ) ;
F_230 ( V_3 ) ;
F_231 ( V_3 ) ;
F_222 ( V_3 -> V_190 ) ;
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
F_177 ( V_241 , & V_34 -> V_310 ) ;
}
static int F_233 ( struct V_1 * V_7 )
{
struct V_4 * V_35 = NULL ;
struct V_371 * V_372 ;
struct V_12 * V_13 ;
int V_32 = 0 ;
F_164 () ;
F_20 ( & V_239 ) ;
V_35 = F_234 ( V_7 ) ;
V_13 = F_32 ( V_35 ) ;
if ( ! V_35 || ! V_13 -> V_16 ) {
V_32 = - V_64 ;
F_65 (KERN_ERR PFX L_58 ) ;
goto V_373;
}
V_372 = V_35 -> V_372 ;
F_129 ( V_35 ) ;
F_235 ( V_372 ) ;
V_373:
F_23 ( & V_239 ) ;
F_166 () ;
return V_32 ;
}
static void V_367 ( struct V_374 * V_152 )
{
struct V_5 * V_34 ;
struct V_2 * V_3 ;
V_34 = F_64 ( V_152 , struct V_5 , V_310 ) ;
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
goto V_375;
if ( F_241 ( V_37 ) )
goto V_375;
return 0 ;
V_375:
F_236 ( V_37 ) ;
return - V_65 ;
}
static int F_207 ( struct V_36 * V_37 )
{
struct V_327 * V_328 ;
struct V_376 * V_377 ;
if ( ! V_37 -> V_328 ) {
F_65 (KERN_ERR PFX L_60 ) ;
return - V_64 ;
}
V_328 = V_37 -> V_328 ;
V_377 = V_37 -> V_378 = V_328 -> V_378 ;
if ( ! V_37 -> V_378 )
return - V_64 ;
switch ( V_377 -> V_189 ) {
case V_379 :
strncpy ( V_37 -> V_204 , L_61 , V_380 ) ;
break;
case V_381 :
strncpy ( V_37 -> V_204 , L_62 , V_380 ) ;
break;
case V_382 :
case V_383 :
case V_384 :
strncpy ( V_37 -> V_204 , L_63 , V_380 ) ;
break;
case V_385 :
case V_386 :
case V_387 :
strncpy ( V_37 -> V_204 , L_64 , V_380 ) ;
break;
case V_388 :
case V_389 :
case V_390 :
strncpy ( V_37 -> V_204 , L_65 , V_380 ) ;
break;
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
strncpy ( V_37 -> V_204 , L_66 , V_380 ) ;
break;
default:
F_242 ( V_396 L_67 , V_377 -> V_189 ) ;
break;
}
F_243 ( V_37 -> V_378 ) ;
return 0 ;
}
static void F_202 ( struct V_36 * V_37 )
{
if ( V_37 -> V_378 ) {
V_37 -> V_204 [ 0 ] = '\0' ;
F_244 ( V_37 -> V_378 ) ;
}
V_37 -> V_378 = NULL ;
}
static int F_245 ( void * V_397 )
{
struct V_36 * V_37 = V_397 ;
struct V_327 * V_328 ;
struct V_398 * V_399 ;
if ( ! V_37 )
return - V_82 ;
V_328 = V_37 -> V_328 ;
V_399 = & V_328 -> V_399 -> V_400 ;
if ( ! V_399 )
return - V_82 ;
strncpy ( V_399 -> V_401 , V_205 ,
sizeof( V_399 -> V_401 ) ) ;
V_399 -> V_402 = V_403 ;
V_399 -> V_404 = V_405 ;
return 0 ;
}
static void F_246 ( void * V_397 )
{
struct V_36 * V_37 = V_397 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
struct V_2 * V_3 ;
F_20 ( & V_239 ) ;
if ( ! F_41 ( V_298 , & V_37 -> V_85 ) )
F_247 ( V_37 ) ;
F_19 ( L_68 ) ;
F_131 (interface, &if_list, list) {
if ( V_35 -> V_37 == V_37 ) {
V_13 = F_32 ( V_35 ) ;
V_3 = V_13 -> V_16 ;
F_65 (KERN_ERR PFX L_69 ) ;
V_3 -> V_253 . V_406 = F_31 ;
F_248 ( V_35 ) ;
}
}
F_23 ( & V_239 ) ;
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
struct V_2 * V_198 ;
if ( ! F_41 ( V_298 , & V_35 -> V_37 -> V_85 ) )
return;
V_3 = V_13 -> V_16 ;
F_175 ( V_3 ) ;
F_20 ( & V_3 -> V_246 ) ;
F_131 (vport, &lport->vports, list)
F_136 ( V_198 -> V_190 ) =
V_247 ;
F_23 ( & V_3 -> V_246 ) ;
F_136 ( V_3 -> V_190 ) = V_247 ;
F_135 ( V_13 ) ;
F_137 ( V_3 ) ;
}
static int F_247 ( struct V_36 * V_37 )
{
#define F_250 (1000 / HZ)
int V_32 = - 1 ;
int V_40 = V_167 ;
V_32 = F_239 ( V_37 ) ;
if ( V_32 ) {
F_65 (KERN_ALERT PFX
L_70 , rc) ;
goto V_407;
}
V_32 = F_251 ( V_37 ) ;
if ( V_32 ) {
F_65 (KERN_ALERT PFX
L_71 , rc) ;
goto V_408;
}
while ( ! F_41 ( V_233 , & V_37 -> V_210 ) && V_40 -- )
F_252 ( F_250 ) ;
if ( ! F_41 ( V_233 , & V_37 -> V_210 ) ) {
F_65 (KERN_ERR PFX L_72
L_73 ,
hba->cnic->netdev->name) ;
V_32 = - 1 ;
goto V_408;
}
F_115 ( V_298 , & V_37 -> V_85 ) ;
return 0 ;
V_408:
F_236 ( V_37 ) ;
V_407:
return V_32 ;
}
static void F_253 ( struct V_36 * V_37 )
{
if ( F_192 ( V_298 , & V_37 -> V_85 ) ) {
if ( F_254 ( V_37 ) == 0 ) {
F_255 ( & V_37 -> V_409 ) ;
V_37 -> V_409 . V_410 = V_411 +
V_303 ;
V_37 -> V_409 . V_412 = F_126 ;
V_37 -> V_409 . V_147 = ( unsigned long ) V_37 ;
F_256 ( & V_37 -> V_409 ) ;
F_139 ( V_37 -> V_225 ,
F_41 ( V_224 ,
& V_37 -> V_85 ) ) ;
F_114 ( V_224 , & V_37 -> V_85 ) ;
if ( F_140 ( V_132 ) )
F_141 ( V_132 ) ;
F_227 ( & V_37 -> V_409 ) ;
}
F_236 ( V_37 ) ;
}
}
static void F_257 ( void * V_397 )
{
struct V_36 * V_37 = V_397 ;
struct V_4 * V_35 ;
F_65 ( V_234 L_74 ) ;
F_20 ( & V_239 ) ;
if ( ! F_41 ( V_298 , & V_37 -> V_85 ) )
goto exit;
F_131 (interface, &if_list, list) {
if ( V_35 -> V_37 == V_37 )
F_232 ( V_35 ) ;
}
F_258 ( V_37 -> V_251 != 0 ) ;
F_20 ( & V_37 -> V_42 ) ;
F_114 ( V_233 , & V_37 -> V_210 ) ;
F_114 ( V_236 ,
& V_37 -> V_210 ) ;
F_114 ( V_249 , & V_37 -> V_210 ) ;
F_23 ( & V_37 -> V_42 ) ;
F_253 ( V_37 ) ;
exit:
F_23 ( & V_239 ) ;
}
static void F_248 ( struct V_4 * V_35 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 ;
int V_413 = 0 ;
F_19 ( L_1 , V_41 ) ;
if ( ! F_41 ( V_298 , & V_35 -> V_37 -> V_85 ) ) {
F_65 (KERN_ERR PFX L_75 ) ;
return;
}
V_3 = V_13 -> V_16 ;
F_34 ( V_3 , L_76 ) ;
if ( ! F_112 ( V_3 ) && V_35 -> V_242 ) {
F_34 ( V_3 , L_77 ) ;
F_134 ( V_13 ) ;
F_136 ( V_3 -> V_190 ) = V_414 ;
F_115 ( V_249 , & V_35 -> V_37 -> V_210 ) ;
}
while ( ! V_13 -> V_81 ) {
F_252 ( 250 ) ;
if ( ++ V_413 > 12 )
break;
}
if ( F_118 ( V_3 , V_218 ) )
return;
F_169 ( V_3 ) ;
F_170 ( V_3 ) ;
}
static void F_259 ( struct V_327 * V_99 )
{
struct V_36 * V_37 ;
int V_32 = 0 ;
F_19 ( L_1 , V_41 ) ;
if ( ! F_41 ( V_415 , & V_99 -> V_85 ) ||
( V_99 -> V_416 == 0 ) ) {
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
F_133 ( V_396 L_81 , V_99 -> V_7 -> V_206 ) ;
F_20 ( & V_239 ) ;
F_220 ( & V_37 -> V_22 , & V_417 ) ;
V_418 ++ ;
F_23 ( & V_239 ) ;
V_99 -> V_330 = & V_37 -> V_330 ;
F_114 ( V_419 , & V_37 -> V_420 ) ;
V_32 = V_99 -> V_421 ( V_99 , V_422 ,
( void * ) V_37 ) ;
if ( V_32 )
F_65 (KERN_ERR PFX L_82 , rc) ;
else
F_115 ( V_419 , & V_37 -> V_420 ) ;
}
static int F_260 ( struct V_12 * V_13 )
{
struct V_4 * V_35 = F_6 ( V_13 ) ;
if ( V_35 -> V_242 == true ) {
if ( ! V_13 -> V_16 ) {
F_242 ( V_396 L_83 ) ;
return - V_64 ;
} else {
V_35 -> V_242 = false ;
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
F_20 ( & V_239 ) ;
V_35 = F_234 ( V_7 ) ;
V_13 = F_32 ( V_35 ) ;
if ( ! V_35 ) {
V_32 = - V_64 ;
F_242 ( V_396 L_84 ) ;
} else {
V_32 = F_260 ( V_13 ) ;
}
F_23 ( & V_239 ) ;
F_166 () ;
return V_32 ;
}
static T_6 F_262 ( struct V_2 * V_3 ,
struct V_423 * V_424 )
{
struct V_425 V_426 ;
T_6 V_40 , V_427 = 0 ;
if ( V_424 -> V_428 > V_429 ) {
F_34 ( V_3 , L_85 ) ;
goto V_430;
}
if ( F_263 ( V_424 -> V_213 [ 0 ] ) == 0 &&
F_263 ( V_424 -> V_214 [ 0 ] ) == 0 ) {
F_34 ( V_3 , L_86 ) ;
goto V_430;
}
V_426 . V_431 = V_432 ;
V_426 . V_433 = V_434 ;
V_426 . V_311 = false ;
for ( V_40 = 0 ; V_40 < V_424 -> V_428 ; V_40 ++ ) {
V_426 . V_369 = F_263 ( V_424 -> V_213 [ V_40 ] ) ;
V_426 . V_297 = F_263 ( V_424 -> V_214 [ V_40 ] ) ;
F_264 ( V_426 . V_435 , sizeof( V_426 . V_435 ) ,
L_87 ,
V_427 , V_426 . V_297 , V_426 . V_369 ) ;
if ( F_265 ( V_3 -> V_190 , 0 , & V_426 ) )
V_427 ++ ;
else
F_34 ( V_3 , L_88 ) ;
}
V_430:
return V_427 ;
}
static int F_266 ( struct V_12 * V_13 )
{
struct V_4 * V_35 = F_6 ( V_13 ) ;
struct V_36 * V_37 ;
struct V_423 * V_424 ;
struct V_2 * V_3 ;
if ( V_35 -> V_242 == false ) {
if ( ! V_13 -> V_16 ) {
F_242 ( V_396 L_89 ) ;
return - V_64 ;
} else if ( ! F_112 ( V_13 -> V_16 ) ) {
F_134 ( V_13 ) ;
V_35 -> V_242 = true ;
}
}
V_37 = V_35 -> V_37 ;
V_3 = V_13 -> V_16 ;
if ( ! V_37 )
goto V_430;
if ( ! V_37 -> V_328 )
goto V_430;
if ( ! V_3 )
goto V_430;
if ( ! V_3 -> V_190 )
goto V_430;
if ( ! V_37 -> V_328 -> V_436 )
goto V_430;
V_424 = F_204 ( sizeof( struct V_423 ) , V_331 ) ;
if ( ! V_424 )
goto V_430;
if ( V_37 -> V_328 -> V_436 ( V_37 -> V_328 , V_424 ) )
goto V_437;
F_262 ( V_3 , V_424 ) ;
V_437:
F_100 ( V_424 ) ;
V_430:
return 0 ;
}
static int F_267 ( struct V_1 * V_7 )
{
struct V_4 * V_35 ;
struct V_12 * V_13 ;
int V_32 = 0 ;
F_164 () ;
F_20 ( & V_239 ) ;
V_35 = F_234 ( V_7 ) ;
V_13 = F_32 ( V_35 ) ;
if ( ! V_35 ) {
V_32 = - V_64 ;
F_242 ( V_396 L_90 ) ;
} else {
V_32 = F_266 ( V_13 ) ;
}
F_23 ( & V_239 ) ;
F_166 () ;
return V_32 ;
}
static int F_268 ( struct V_10 * V_228 )
{
struct V_12 * V_13 = F_5 ( V_228 ) ;
switch ( V_228 -> V_242 ) {
case V_244 :
return F_266 ( V_13 ) ;
case V_243 :
return F_260 ( V_13 ) ;
case V_245 :
default:
return - V_438 ;
} ;
}
static int F_269 ( struct V_1 * V_7 ,
enum V_355 V_355 ,
enum V_439 V_440 )
{
struct V_10 * V_228 ;
struct V_12 * V_13 ;
struct V_4 * V_35 ;
struct V_36 * V_37 ;
struct V_1 * V_207 = V_7 ;
struct V_2 * V_3 ;
struct V_441 V_442 ;
int V_32 = 0 ;
int V_15 = 0 ;
F_19 ( L_91 ) ;
if ( V_355 != V_443 ) {
F_65 ( V_234 L_92 ) ;
return - V_299 ;
}
F_164 () ;
F_20 ( & V_239 ) ;
if ( ! F_270 ( V_325 ) ) {
V_32 = - V_82 ;
goto V_444;
}
if ( F_271 ( V_7 ) )
V_207 = F_272 ( V_7 ) ;
if ( V_207 -> V_215 && V_207 -> V_215 -> V_445 ) {
memset ( & V_442 , 0 , sizeof( V_442 ) ) ;
V_207 -> V_215 -> V_445 ( V_207 , & V_442 ) ;
if ( strncmp ( V_442 . V_446 , L_93 , strlen ( L_93 ) ) ) {
F_65 (KERN_ERR PFX L_94 ) ;
V_32 = - V_82 ;
goto V_373;
}
} else {
F_65 (KERN_ERR PFX L_95 ) ;
V_32 = - V_82 ;
goto V_373;
}
V_37 = F_273 ( V_207 ) ;
if ( ! V_37 ) {
V_32 = - V_64 ;
F_65 (KERN_ERR PFX L_96 ) ;
goto V_373;
}
if ( F_234 ( V_7 ) ) {
V_32 = - V_447 ;
goto V_373;
}
V_35 = F_210 ( V_37 , V_7 , V_355 ) ;
if ( ! V_35 ) {
F_65 (KERN_ERR PFX L_97 ) ;
V_32 = - V_65 ;
goto V_448;
}
if ( F_271 ( V_7 ) ) {
V_15 = F_274 ( V_7 ) ;
V_35 -> V_449 = 1 ;
}
V_13 = F_32 ( V_35 ) ;
V_228 = F_132 ( V_13 ) ;
V_35 -> V_15 = V_15 ;
V_35 -> V_450 = V_451 ;
V_35 -> V_372 =
F_275 ( L_98 ) ;
if ( ! V_35 -> V_372 ) {
F_65 (KERN_ERR PFX L_99 ) ;
V_32 = - V_82 ;
goto V_448;
}
V_3 = F_165 ( V_35 , & V_228 -> V_99 , 0 ) ;
if ( ! V_3 ) {
F_65 (KERN_ERR PFX L_100 ,
netdev->name) ;
V_32 = - V_82 ;
goto V_452;
}
F_220 ( & V_35 -> V_22 , & V_453 ) ;
V_3 -> V_302 = V_303 ;
V_13 -> V_16 = V_3 ;
if ( V_440 == V_454 )
V_228 -> V_242 = V_244 ;
else
V_228 -> V_242 = V_243 ;
if ( V_440 == V_454 &&
! F_112 ( V_3 ) ) {
F_134 ( V_13 ) ;
F_136 ( V_3 -> V_190 ) = V_414 ;
F_115 ( V_249 , & V_35 -> V_37 -> V_210 ) ;
}
F_34 ( V_3 , L_101 ) ;
F_248 ( V_35 ) ;
if ( V_440 == V_454 )
V_35 -> V_242 = true ;
F_176 ( V_35 ) ;
F_23 ( & V_239 ) ;
F_166 () ;
return 0 ;
V_452:
F_235 ( V_35 -> V_372 ) ;
V_448:
F_223 ( V_35 ) ;
F_176 ( V_35 ) ;
goto V_444;
V_373:
F_196 ( V_325 ) ;
V_444:
F_23 ( & V_239 ) ;
F_166 () ;
return V_32 ;
}
static int F_276 ( struct V_1 * V_7 , enum V_355 V_355 )
{
return F_269 ( V_7 , V_355 , V_454 ) ;
}
static int F_277 ( struct V_1 * V_7 )
{
return F_269 ( V_7 , V_443 ,
V_455 ) ;
}
static struct V_36 * F_278 ( struct V_327 * V_328 )
{
struct V_36 * V_37 ;
F_131 (hba, &adapter_list, list) {
if ( V_37 -> V_328 == V_328 )
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
static struct V_36 * F_273 ( struct V_1
* V_207 )
{
struct V_36 * V_37 ;
F_131 (hba, &adapter_list, list) {
if ( V_37 -> V_207 == V_207 )
return V_37 ;
}
F_65 (KERN_ERR PFX L_102 ) ;
return NULL ;
}
static void F_279 ( struct V_327 * V_99 )
{
struct V_36 * V_37 ;
struct V_4 * V_35 , * V_153 ;
F_19 ( L_103 ) ;
if ( ! F_41 ( V_415 , & V_99 -> V_85 ) ) {
F_65 (KERN_ERR PFX L_104 ,
dev->netdev->name, dev->flags) ;
return;
}
F_20 ( & V_239 ) ;
V_37 = F_278 ( V_99 ) ;
if ( ! V_37 ) {
F_65 (KERN_ERR PFX L_105 ,
dev) ;
F_23 ( & V_239 ) ;
return;
}
F_98 ( & V_37 -> V_22 ) ;
V_418 -- ;
F_97 (interface, tmp, &if_list, list)
if ( V_35 -> V_37 == V_37 )
F_129 ( V_35 ) ;
F_23 ( & V_239 ) ;
F_130 ( V_241 ) ;
F_257 ( V_37 ) ;
if ( F_192 ( V_419 , & V_37 -> V_420 ) )
V_37 -> V_328 -> V_456 ( V_37 -> V_328 , V_422 ) ;
F_200 ( V_37 ) ;
}
static int F_280 ( struct V_158 * V_159 )
{
struct V_2 * V_3 = F_102 ( V_159 ) ;
F_281 ( V_3 ) ;
return 0 ;
}
static bool F_282 ( struct V_1 * V_7 )
{
struct V_1 * V_207 = V_7 ;
F_20 ( & V_239 ) ;
if ( F_271 ( V_7 ) )
V_207 = F_272 ( V_7 ) ;
if ( F_273 ( V_207 ) ) {
F_23 ( & V_239 ) ;
return true ;
}
F_23 ( & V_239 ) ;
return false ;
}
static void F_283 ( unsigned int V_457 )
{
struct V_149 * V_150 ;
struct V_458 * V_459 ;
V_150 = & F_284 ( V_460 , V_457 ) ;
V_459 = F_285 ( F_93 ,
( void * ) V_150 , F_286 ( V_457 ) ,
L_106 , V_457 ) ;
if ( F_287 ( ! F_288 ( V_459 ) ) ) {
F_289 ( V_459 , V_457 ) ;
V_150 -> V_461 = V_459 ;
F_71 ( V_459 ) ;
}
}
static void F_290 ( unsigned int V_457 )
{
struct V_149 * V_150 ;
struct V_458 * V_459 ;
struct V_151 * V_152 , * V_153 ;
F_19 ( L_107 , V_457 ) ;
V_150 = & F_284 ( V_460 , V_457 ) ;
F_8 ( & V_150 -> V_155 ) ;
V_459 = V_150 -> V_461 ;
V_150 -> V_461 = NULL ;
F_97 (work, tmp, &p->work_list, list) {
F_98 ( & V_152 -> V_22 ) ;
F_99 ( V_152 -> V_39 , V_152 -> V_156 ) ;
F_100 ( V_152 ) ;
}
F_12 ( & V_150 -> V_155 ) ;
if ( V_459 )
F_291 ( V_459 ) ;
}
static int F_292 ( unsigned int V_457 )
{
F_65 ( V_396 L_108 , V_457 ) ;
F_283 ( V_457 ) ;
return 0 ;
}
static int F_293 ( unsigned int V_457 )
{
F_65 ( V_396 L_109 , V_457 ) ;
F_290 ( V_457 ) ;
return 0 ;
}
static int F_294 ( struct V_462 * V_463 )
{
if ( ! V_464 )
return 0 ;
F_295 ( V_463 , V_464 ) ;
return 0 ;
}
static int T_7 F_296 ( void )
{
struct V_17 * V_18 ;
struct V_458 * V_465 ;
int V_32 = 0 ;
unsigned int V_457 = 0 ;
struct V_149 * V_150 ;
F_65 (KERN_INFO PFX L_110 , version) ;
V_32 = F_297 ( & V_466 ) ;
if ( V_32 ) {
F_65 ( V_234 L_111
L_112 ) ;
goto V_467;
}
F_209 ( & V_417 ) ;
F_209 ( & V_453 ) ;
F_206 ( & V_239 ) ;
V_418 = 0 ;
V_32 = F_187 () ;
if ( V_32 )
goto V_468;
V_241 = F_298 ( L_113 , 0 , 0 ) ;
if ( ! V_241 ) {
V_32 = - V_65 ;
goto V_469;
}
V_18 = & V_27 ;
F_119 ( & V_18 -> V_28 ) ;
V_465 = F_299 ( F_72 ,
( void * ) V_18 ,
L_114 ) ;
if ( F_288 ( V_465 ) ) {
V_32 = F_300 ( V_465 ) ;
goto V_470;
}
F_71 ( V_465 ) ;
F_8 ( & V_18 -> V_28 . V_29 ) ;
V_18 -> V_130 = V_465 ;
F_12 ( & V_18 -> V_28 . V_29 ) ;
F_301 (cpu) {
V_150 = & F_284 ( V_460 , V_457 ) ;
F_209 ( & V_150 -> V_154 ) ;
F_205 ( & V_150 -> V_155 ) ;
}
F_302 () ;
F_303 (cpu)
F_283 ( V_457 ) ;
V_32 = F_304 ( V_471 ,
L_115 ,
F_292 , NULL ) ;
if ( V_32 < 0 )
goto V_472;
V_473 = V_32 ;
F_304 ( V_474 , L_116 ,
NULL , F_293 ) ;
F_305 () ;
F_306 ( V_422 , & V_475 ) ;
return 0 ;
V_472:
F_303 (cpu)
F_290 ( V_457 ) ;
F_305 () ;
F_291 ( V_465 ) ;
V_470:
F_235 ( V_241 ) ;
V_469:
F_190 () ;
V_468:
F_307 ( & V_466 ) ;
V_467:
return V_32 ;
}
static void T_8 F_308 ( void )
{
F_94 ( V_476 ) ;
struct V_36 * V_37 , * V_25 ;
struct V_17 * V_18 ;
struct V_458 * V_465 ;
struct V_23 * V_24 ;
unsigned int V_457 = 0 ;
F_20 ( & V_239 ) ;
F_96 ( & V_417 , & V_476 ) ;
V_418 = 0 ;
F_23 ( & V_239 ) ;
F_97 (hba, next, &to_be_deleted, list) {
F_98 ( & V_37 -> V_22 ) ;
F_65 (KERN_ERR PFX L_117 ,
hba) ;
F_257 ( V_37 ) ;
if ( F_192 ( V_419 ,
& V_37 -> V_420 ) )
V_37 -> V_328 -> V_456 ( V_37 -> V_328 ,
V_422 ) ;
F_200 ( V_37 ) ;
}
F_309 ( V_422 ) ;
V_18 = & V_27 ;
F_8 ( & V_18 -> V_28 . V_29 ) ;
V_465 = V_18 -> V_130 ;
V_18 -> V_130 = NULL ;
while ( ( V_24 = F_77 ( & V_18 -> V_28 ) ) != NULL )
F_11 ( V_24 ) ;
F_12 ( & V_18 -> V_28 . V_29 ) ;
if ( V_465 )
F_291 ( V_465 ) ;
F_302 () ;
F_303 (cpu) {
F_290 ( V_457 ) ;
}
F_310 ( V_473 ) ;
F_310 ( V_474 ) ;
F_305 () ;
F_235 ( V_241 ) ;
F_190 () ;
F_307 ( & V_466 ) ;
}
static T_9
F_311 ( struct V_189 * V_99 , struct V_477 * V_478 ,
char * V_296 )
{
struct V_158 * V_159 = F_312 ( V_99 ) ;
struct V_2 * V_3 = F_102 ( V_159 ) ;
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
sprintf ( V_296 , L_118 , V_35 -> V_450 ) ;
return strlen ( V_296 ) ;
}
static T_9
F_313 ( struct V_189 * V_99 ,
struct V_477 * V_478 , const char * V_296 , T_10 V_428 )
{
struct V_158 * V_159 = F_312 ( V_99 ) ;
struct V_2 * V_3 = F_102 ( V_159 ) ;
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
int V_479 , V_480 ;
V_479 = F_314 ( V_296 , 10 , & V_480 ) ;
if ( V_479 )
return V_479 ;
if ( V_480 > 255 )
return - V_481 ;
V_35 -> V_450 = ( T_1 ) V_480 ;
return strlen ( V_296 ) ;
}
