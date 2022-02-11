static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return ( (struct V_4 * )
( (struct V_5 * ) F_2 ( V_3 ) ) -> V_6 ) -> V_7 ;
}
static void F_3 ( struct V_2 * V_3 ,
struct V_8 * V_9 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_4 ( V_3 , V_9 , V_7 ) ;
}
static void F_5 ( struct V_2 * V_10 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 , * V_19 ;
struct V_17 * V_20 ;
V_12 = & V_21 ;
F_6 ( & V_12 -> V_22 . V_23 ) ;
V_16 = & V_12 -> V_22 ;
V_20 = V_16 -> V_19 ;
for ( V_18 = V_20 ; V_18 != (struct V_17 * ) V_16 ;
V_18 = V_19 ) {
V_19 = V_18 -> V_19 ;
V_14 = F_7 ( V_18 ) ;
if ( V_14 -> V_24 == V_10 ) {
F_8 ( V_18 , V_16 ) ;
F_9 ( V_18 ) ;
}
}
F_10 ( & V_12 -> V_22 . V_23 ) ;
}
int F_11 ( struct V_17 * V_18 , int V_25 )
{
int V_26 ;
F_12 ( & V_27 ) ;
V_26 = F_13 ( V_18 , V_25 , & V_21 ) ;
F_14 ( & V_27 ) ;
return V_26 ;
}
static void F_15 ( struct V_2 * V_3 )
{
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_5 * V_28 = F_2 ( V_3 ) ;
struct V_4 * V_29 = V_28 -> V_6 ;
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_32 * V_33 ;
int V_34 ;
F_17 ( L_1 , V_35 ) ;
F_18 ( & V_31 -> V_36 ) ;
F_6 ( & V_31 -> V_37 ) ;
for ( V_34 = 0 ; V_34 < V_38 ; V_34 ++ ) {
V_33 = V_31 -> V_39 [ V_34 ] ;
if ( V_33 ) {
if ( V_33 -> V_28 == V_28 ) {
F_10 ( & V_31 -> V_37 ) ;
F_19 ( V_33 , L_2 ) ;
F_20 ( V_33 ) ;
F_6 ( & V_31 -> V_37 ) ;
}
}
}
F_10 ( & V_31 -> V_37 ) ;
F_21 ( & V_31 -> V_36 ) ;
}
static int F_22 ( struct V_32 * V_33 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_33 -> V_43 ;
struct V_44 * V_45 ;
int V_26 = 0 ;
V_45 = F_23 ( V_41 ) ;
F_19 ( V_33 , L_3
L_4 , V_43 -> V_46 . V_47 ,
F_24 ( V_45 -> V_48 ) , V_45 -> V_49 ) ;
if ( ( V_45 -> V_50 == V_51 ) &&
( V_45 -> V_49 == V_52 ) ) {
switch ( F_25 ( V_41 ) ) {
case V_53 :
V_26 = F_26 ( V_33 , V_41 ) ;
break;
case V_54 :
V_26 = F_27 ( V_33 , V_41 ) ;
break;
case V_55 :
V_26 = F_28 ( V_33 , V_41 ) ;
break;
default:
break;
}
} else if ( ( V_45 -> V_50 == V_56 ) &&
( V_45 -> V_49 == V_57 ) )
F_19 ( V_33 , L_5 ) ;
else {
F_19 ( V_33 , L_6
L_7 ,
V_45 -> V_50 , V_45 -> V_49 ) ;
return - V_58 ;
}
if ( V_26 )
return - V_59 ;
else
return 0 ;
}
static int F_29 ( struct V_2 * V_3 , struct V_40 * V_41 )
{
struct V_60 * V_61 ;
struct V_62 * V_63 ;
struct V_17 * V_18 ;
struct V_44 * V_45 ;
struct V_4 * V_29 ;
struct V_30 * V_31 ;
struct V_5 * V_28 ;
struct V_64 * V_65 ;
struct V_32 * V_33 ;
struct V_66 * V_67 ;
T_1 V_68 , V_69 ;
T_2 V_70 ;
unsigned int V_71 , V_25 , V_72 ;
int V_73 , V_26 = 0 ;
V_28 = (struct V_5 * ) F_2 ( V_3 ) ;
V_29 = V_28 -> V_6 ;
V_31 = V_29 -> V_31 ;
V_45 = F_23 ( V_41 ) ;
V_18 = F_30 ( V_41 ) ;
if ( ! V_3 -> V_74 ) {
F_31 ( V_3 , L_8 ) ;
F_9 ( V_18 ) ;
return 0 ;
}
if ( F_32 ( V_45 -> V_49 == V_52 ) ) {
if ( ! V_29 -> V_75 . V_76 ) {
F_31 ( V_3 , L_9 ) ;
F_9 ( V_18 ) ;
return - V_77 ;
}
if ( F_33 ( & V_29 -> V_75 , V_3 , V_18 ) )
return 0 ;
}
V_68 = F_34 ( V_41 ) ;
V_69 = F_35 ( V_41 ) ;
F_6 ( & V_31 -> V_37 ) ;
V_33 = F_36 ( V_28 , F_37 ( V_45 -> V_78 ) ) ;
if ( V_33 && ( F_38 ( V_79 , & V_33 -> V_80 ) ) ) {
F_31 ( V_3 , L_10
L_11 , F_37 ( V_45 -> V_78 ) ) ;
F_10 ( & V_31 -> V_37 ) ;
V_26 = F_22 ( V_33 , V_41 ) ;
if ( V_26 != - V_58 ) {
F_9 ( V_18 ) ;
return V_26 ;
}
} else {
F_10 ( & V_31 -> V_37 ) ;
}
V_72 = sizeof( struct V_60 ) ;
V_71 = sizeof( struct V_64 ) ;
V_25 = sizeof( struct V_62 ) ;
V_73 = ( V_18 -> V_81 - V_25 + sizeof( V_70 ) ) / V_82 ;
V_18 -> V_83 = V_84 ;
V_70 = F_39 ( V_41 ) ;
if ( F_40 ( V_18 ) ) {
T_3 * V_85 ;
if ( F_11 ( V_18 , V_25 ) ) {
F_9 ( V_18 ) ;
return - V_59 ;
}
V_85 = & F_41 ( V_18 ) -> V_86 [ F_41 ( V_18 ) -> V_87 - 1 ] ;
V_63 = F_42 ( F_43 ( V_85 ) ) + V_85 -> V_88 ;
} else {
V_63 = (struct V_62 * ) F_44 ( V_18 , V_25 ) ;
}
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> V_89 = V_69 ;
V_63 -> V_90 = F_45 ( ~ V_70 ) ;
if ( F_40 ( V_18 ) ) {
F_46 ( V_63 ) ;
V_63 = NULL ;
}
F_47 ( V_18 , V_72 + V_71 ) ;
F_48 ( V_18 ) ;
F_49 ( V_18 ) ;
V_18 -> V_91 = V_72 ;
V_18 -> V_92 = F_50 ( V_93 ) ;
V_18 -> V_94 = V_29 -> V_7 ;
V_61 = F_51 ( V_18 ) ;
V_61 -> V_95 = F_50 ( V_93 ) ;
if ( V_29 -> V_75 . V_96 )
F_52 ( V_61 -> V_97 , V_45 -> V_78 ) ;
else
memcpy ( V_61 -> V_97 , V_29 -> V_75 . V_98 , V_99 ) ;
if ( F_32 ( V_29 -> V_75 . V_100 != V_101 ) )
memcpy ( V_61 -> V_102 , V_29 -> V_75 . V_103 , V_99 ) ;
else
memcpy ( V_61 -> V_102 , V_28 -> V_104 , V_99 ) ;
V_65 = (struct V_64 * ) ( V_61 + 1 ) ;
memset ( V_65 , 0 , sizeof( * V_65 ) ) ;
if ( V_105 )
F_53 ( V_65 , V_105 ) ;
V_65 -> V_106 = V_68 ;
if ( V_3 -> V_107 && F_54 ( V_41 ) ) {
F_41 ( V_18 ) -> V_108 = V_109 ;
F_41 ( V_18 ) -> V_110 = F_54 ( V_41 ) ;
} else {
F_41 ( V_18 ) -> V_108 = 0 ;
F_41 ( V_18 ) -> V_110 = 0 ;
}
V_67 = F_55 ( V_3 -> V_111 , F_56 () ) ;
V_67 -> V_112 ++ ;
V_67 -> V_113 += V_73 ;
F_57 () ;
V_24 ( V_41 ) = V_3 ;
if ( V_28 -> V_114 . V_115 )
F_58 ( V_3 , V_18 ) ;
else if ( F_59 ( V_18 ) )
F_58 ( V_3 , V_18 ) ;
return 0 ;
}
static int F_60 ( struct V_17 * V_18 , struct V_1 * V_94 ,
struct V_116 * V_117 , struct V_1 * V_118 )
{
struct V_2 * V_3 ;
struct V_4 * V_29 ;
struct V_44 * V_45 ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
unsigned short V_119 ;
V_29 = F_61 ( V_117 , struct V_4 ,
V_120 ) ;
V_3 = V_29 -> V_75 . V_10 ;
if ( F_32 ( V_3 == NULL ) ) {
F_62 (KERN_ERR PFX L_12 ) ;
goto V_121;
}
if ( F_32 ( F_51 ( V_18 ) -> V_95 != F_50 ( V_93 ) ) ) {
F_62 (KERN_ERR PFX L_13 ) ;
goto V_121;
}
if ( F_32 ( ( V_18 -> V_81 < V_122 ) ||
! F_63 ( V_18 , V_123 ) ) )
goto V_121;
F_64 ( V_18 , sizeof( struct V_64 ) ) ;
V_45 = (struct V_44 * ) F_65 ( V_18 ) ;
V_119 = F_24 ( V_45 -> V_48 ) ;
V_14 = F_7 ( V_18 ) ;
V_14 -> V_24 = V_3 ;
V_12 = & V_21 ;
F_12 ( & V_12 -> V_22 . V_23 ) ;
F_66 ( & V_12 -> V_22 , V_18 ) ;
if ( V_12 -> V_22 . V_115 == 1 )
F_67 ( V_12 -> V_124 ) ;
F_14 ( & V_12 -> V_22 . V_23 ) ;
return 0 ;
V_121:
F_9 ( V_18 ) ;
return - 1 ;
}
static int F_68 ( void * V_125 )
{
struct V_11 * V_12 = V_125 ;
struct V_17 * V_18 ;
F_69 ( V_126 , - 20 ) ;
F_70 ( V_127 ) ;
while ( ! F_71 () ) {
F_72 () ;
F_6 ( & V_12 -> V_22 . V_23 ) ;
while ( ( V_18 = F_73 ( & V_12 -> V_22 ) ) != NULL ) {
F_10 ( & V_12 -> V_22 . V_23 ) ;
F_74 ( V_18 ) ;
F_6 ( & V_12 -> V_22 . V_23 ) ;
}
F_75 ( V_127 ) ;
F_10 ( & V_12 -> V_22 . V_23 ) ;
}
F_75 ( V_128 ) ;
return 0 ;
}
static void F_74 ( struct V_17 * V_18 )
{
T_2 V_129 ;
struct V_2 * V_3 ;
struct V_13 * V_14 ;
struct V_66 * V_67 ;
struct V_44 * V_45 ;
struct V_62 V_130 ;
struct V_40 * V_41 ;
struct V_2 * V_131 ;
struct V_5 * V_28 ;
T_1 * V_132 = NULL ;
T_1 * V_133 = NULL ;
struct V_64 * V_65 ;
V_14 = F_7 ( V_18 ) ;
V_3 = V_14 -> V_24 ;
if ( F_32 ( V_3 == NULL ) ) {
F_62 (KERN_ERR PFX L_14 ) ;
F_9 ( V_18 ) ;
return;
}
if ( F_40 ( V_18 ) )
F_76 ( V_18 ) ;
V_132 = F_51 ( V_18 ) -> V_102 ;
V_133 = F_51 ( V_18 ) -> V_97 ;
V_65 = (struct V_64 * ) F_77 ( V_18 ) ;
V_45 = (struct V_44 * ) F_65 ( V_18 ) ;
F_78 ( V_18 , sizeof( struct V_64 ) ) ;
V_129 = V_18 -> V_81 - sizeof( struct V_62 ) ;
V_67 = F_55 ( V_3 -> V_111 , F_56 () ) ;
V_67 -> V_134 ++ ;
V_67 -> V_135 += V_129 / V_82 ;
V_41 = (struct V_40 * ) V_18 ;
F_79 ( V_41 ) ;
V_24 ( V_41 ) = V_3 ;
F_34 ( V_41 ) = V_65 -> V_106 ;
if ( F_80 ( V_18 , V_129 , & V_130 , sizeof( V_130 ) ) ) {
F_57 () ;
F_9 ( V_18 ) ;
return;
}
F_35 ( V_41 ) = V_130 . V_89 ;
F_81 ( V_41 ) = V_130 . V_90 ;
if ( F_82 ( V_18 , V_129 ) ) {
F_57 () ;
F_9 ( V_18 ) ;
return;
}
V_45 = F_23 ( V_41 ) ;
V_131 = F_83 ( V_3 , F_37 ( V_45 -> V_78 ) ) ;
if ( V_131 ) {
V_28 = F_2 ( V_131 ) ;
if ( F_84 ( V_28 -> V_104 , V_133 )
!= 0 ) {
F_31 ( V_3 , L_15 ) ;
F_57 () ;
F_9 ( V_18 ) ;
return;
}
}
if ( V_45 -> V_49 == V_136 &&
V_45 -> V_50 == V_137 ) {
F_57 () ;
F_9 ( V_18 ) ;
return;
}
if ( V_45 -> V_49 == V_52 &&
V_45 -> V_50 == V_51 ) {
switch ( F_25 ( V_41 ) ) {
case V_54 :
if ( F_37 ( V_45 -> V_138 ) == V_139 ) {
F_57 () ;
F_9 ( V_18 ) ;
return;
}
break;
}
}
if ( V_45 -> V_49 == V_57 ) {
F_57 () ;
F_9 ( V_18 ) ;
return;
}
if ( F_85 ( F_81 ( V_41 ) ) !=
~ F_86 ( ~ 0 , V_18 -> V_140 , V_129 ) ) {
if ( V_67 -> V_141 < 5 )
F_62 (KERN_WARNING PFX L_16
L_17 ) ;
V_67 -> V_141 ++ ;
F_57 () ;
F_9 ( V_18 ) ;
return;
}
F_57 () ;
F_87 ( V_3 , V_41 ) ;
}
int F_88 ( void * V_125 )
{
struct V_142 * V_143 = V_125 ;
struct V_144 * V_145 , * V_146 ;
F_89 ( V_147 ) ;
F_69 ( V_126 , - 20 ) ;
F_70 ( V_127 ) ;
while ( ! F_71 () ) {
F_72 () ;
F_6 ( & V_143 -> V_148 ) ;
while ( ! F_90 ( & V_143 -> V_147 ) ) {
F_91 ( & V_143 -> V_147 , & V_147 ) ;
F_10 ( & V_143 -> V_148 ) ;
F_92 (work, tmp, &work_list, list) {
F_93 ( & V_145 -> V_16 ) ;
F_94 ( V_145 -> V_33 , V_145 -> V_149 ) ;
F_95 ( V_145 ) ;
}
F_6 ( & V_143 -> V_148 ) ;
}
F_75 ( V_127 ) ;
F_10 ( & V_143 -> V_148 ) ;
}
F_75 ( V_128 ) ;
return 0 ;
}
static struct V_150 * F_96 ( struct V_151 * V_152 )
{
struct V_150 * V_153 ;
struct V_2 * V_3 = F_97 ( V_152 ) ;
struct V_5 * V_28 = F_2 ( V_3 ) ;
struct V_4 * V_29 = V_28 -> V_6 ;
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_154 * V_155 ;
int V_26 = 0 ;
V_155 = (struct V_154 * ) V_31 -> V_156 ;
if ( ! V_155 )
return NULL ;
V_153 = F_98 ( V_152 ) ;
F_99 ( & V_31 -> V_157 ) ;
if ( F_100 ( V_31 ) )
return V_153 ;
V_26 = F_101 ( & V_31 -> V_157 , ( 2 * V_158 ) ) ;
if ( ! V_26 ) {
F_31 ( V_3 , L_18 ) ;
return V_153 ;
}
V_153 -> V_159 += V_155 -> V_160 . V_161 ;
V_153 -> V_162 += V_155 -> V_163 . V_164 ;
V_153 -> V_165 += ( V_155 -> V_163 . V_166 ) / 4 ;
V_153 -> V_167 += V_155 -> V_168 . V_169 ;
V_153 -> V_170 += ( V_155 -> V_168 . V_171 ) / 4 ;
V_153 -> V_172 = 0 ;
V_153 -> V_173 = 0 ;
V_153 -> V_174 = 0 ;
V_153 -> V_175 = 0 ;
V_153 -> V_176 = 0 ;
V_153 -> V_177 = 0 ;
return V_153 ;
}
static int F_102 ( struct V_2 * V_3 , struct V_178 * V_94 )
{
struct V_5 * V_28 = F_2 ( V_3 ) ;
struct V_4 * V_29 = V_28 -> V_6 ;
struct V_151 * V_152 = V_3 -> V_179 ;
int V_26 = 0 ;
V_152 -> V_180 = V_181 ;
V_152 -> V_182 = V_183 ;
V_152 -> V_184 = V_185 ;
V_152 -> V_186 = 0 ;
if ( V_3 -> V_187 )
V_152 -> V_188 = V_189 ;
else
V_152 -> V_188 = V_190 ;
V_26 = F_103 ( V_3 -> V_179 , V_94 ) ;
if ( V_26 ) {
F_62 (KERN_ERR PFX L_19 ) ;
return V_26 ;
}
if ( ! V_3 -> V_187 )
F_104 ( V_3 -> V_179 ) = V_191 ;
sprintf ( F_105 ( V_3 -> V_179 ) , L_20 ,
V_192 , V_193 ,
V_29 -> V_7 -> V_194 ) ;
return 0 ;
}
static void F_106 ( struct V_2 * V_3 )
{
struct V_5 * V_28 = F_2 ( V_3 ) ;
struct V_4 * V_29 = V_28 -> V_6 ;
struct V_1 * V_7 = V_29 -> V_7 ;
struct V_195 V_196 ;
if ( ! F_107 ( V_7 , & V_196 ) ) {
V_3 -> V_197 &=
~ ( V_198 | V_199 ) ;
if ( V_196 . V_200 & ( V_201 |
V_202 ) )
V_3 -> V_197 |= V_198 ;
if ( V_196 . V_200 & V_203 )
V_3 -> V_197 |= V_199 ;
switch ( F_108 ( & V_196 ) ) {
case V_204 :
V_3 -> V_205 = V_198 ;
break;
case V_206 :
V_3 -> V_205 = V_207 ;
break;
case V_208 :
V_3 -> V_205 = V_199 ;
break;
}
}
}
static int F_109 ( struct V_2 * V_3 )
{
struct V_5 * V_28 = F_2 ( V_3 ) ;
struct V_4 * V_29 = V_28 -> V_6 ;
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_1 * V_94 = V_31 -> V_209 ;
int V_26 = 0 ;
if ( ( V_94 -> V_80 & V_210 ) && F_110 ( V_94 ) )
F_111 ( V_211 , & V_31 -> V_212 ) ;
else {
F_112 ( V_211 , & V_31 -> V_212 ) ;
V_26 = - 1 ;
}
return V_26 ;
}
void F_113 ( struct V_30 * V_31 )
{
if ( F_38 ( V_213 , & V_31 -> V_209 -> V_214 ) )
F_112 ( V_211 , & V_31 -> V_212 ) ;
else
F_111 ( V_211 , & V_31 -> V_212 ) ;
}
static int F_114 ( struct V_2 * V_3 , struct V_1 * V_7 )
{
struct V_30 * V_31 ;
struct V_4 * V_29 ;
struct V_5 * V_28 ;
T_4 V_215 , V_216 ;
V_28 = F_2 ( V_3 ) ;
V_29 = V_28 -> V_6 ;
V_31 = V_29 -> V_31 ;
if ( ! V_31 -> V_209 -> V_217 ||
! V_31 -> V_209 -> V_217 -> V_218 )
return - V_219 ;
if ( F_115 ( V_3 , V_220 ) )
return - V_77 ;
F_116 ( & V_28 -> V_114 ) ;
V_28 -> V_221 = 0 ;
F_117 ( & V_28 -> V_222 , V_223 , ( unsigned long ) V_3 ) ;
F_106 ( V_3 ) ;
if ( ! V_3 -> V_187 ) {
if ( F_118 ( V_7 , & V_215 , V_224 ) )
V_215 = F_119 ( V_29 -> V_75 . V_103 ,
1 , 0 ) ;
F_31 ( V_3 , L_21 , V_215 ) ;
F_120 ( V_3 , V_215 ) ;
if ( F_118 ( V_7 , & V_216 , V_225 ) )
V_216 = F_119 ( V_29 -> V_75 . V_103 ,
2 , 0 ) ;
F_31 ( V_3 , L_22 , V_216 ) ;
F_121 ( V_3 , V_216 ) ;
}
return 0 ;
}
static void F_122 ( unsigned long V_140 )
{
struct V_30 * V_31 = (struct V_30 * ) V_140 ;
F_62 (KERN_ERR PFX L_23
L_24 ) ;
F_112 ( V_226 , & V_31 -> V_80 ) ;
F_123 ( & V_31 -> V_227 ) ;
}
static void F_124 ( void * V_228 , unsigned long V_229 ,
T_5 V_230 )
{
struct V_30 * V_31 = (struct V_30 * ) V_228 ;
struct V_2 * V_3 ;
struct V_2 * V_187 ;
struct V_4 * V_29 , * V_146 ;
int V_231 = 0 ;
T_2 V_232 = 1 ;
if ( V_230 != 0 && V_229 != V_233 )
return;
switch ( V_229 ) {
case V_234 :
if ( ! F_38 ( V_235 , & V_31 -> V_212 ) )
F_62 ( V_236 L_25\
L_26 ) ;
break;
case V_237 :
F_111 ( V_238 , & V_31 -> V_212 ) ;
F_111 ( V_235 , & V_31 -> V_212 ) ;
V_232 = 0 ;
break;
case V_239 :
F_112 ( V_238 , & V_31 -> V_212 ) ;
V_232 = 0 ;
break;
case V_240 :
break;
case V_233 :
if ( ! V_230 )
return;
F_18 ( & V_241 ) ;
F_92 (interface, tmp, &if_list, list) {
if ( V_29 -> V_31 == V_31 &&
V_29 -> V_230 == ( V_230 & V_242 ) )
F_125 ( V_29 ) ;
}
F_21 ( & V_241 ) ;
return;
default:
F_62 (KERN_ERR PFX L_27 , event) ;
return;
}
F_18 ( & V_241 ) ;
F_126 (interface, &if_list, list) {
if ( V_29 -> V_31 != V_31 )
continue;
V_3 = V_29 -> V_75 . V_10 ;
F_31 ( V_3 , L_28 ,
V_29 -> V_7 -> V_194 , V_229 ) ;
F_106 ( V_3 ) ;
if ( V_232 && ! F_109 ( V_3 ) ) {
F_115 ( V_3 , V_220 ) ;
if ( V_29 -> V_243 )
F_127 ( & V_29 -> V_75 ) ;
} else if ( F_128 ( & V_29 -> V_75 ) ) {
F_18 ( & V_3 -> V_244 ) ;
F_126 (vport, &lport->vports, list)
F_129 ( V_187 -> V_179 ) =
V_245 ;
F_21 ( & V_3 -> V_244 ) ;
F_129 ( V_3 -> V_179 ) = V_245 ;
F_55 ( V_3 -> V_111 ,
F_56 () ) -> V_246 ++ ;
F_57 () ;
F_130 ( V_3 ) ;
V_231 = 1 ;
}
}
F_21 ( & V_241 ) ;
if ( V_231 ) {
F_111 ( V_247 , & V_31 -> V_212 ) ;
F_131 ( & V_31 -> V_248 ) ;
F_17 ( L_29
L_30 ,
V_31 -> V_249 ) ;
V_31 -> V_250 = 1 ;
F_132 ( V_31 -> V_248 ,
( V_31 -> V_249 == 0 ) ) ;
F_17 ( L_31 ,
V_31 -> V_249 ) ;
V_31 -> V_250 = 0 ;
if ( F_133 ( V_126 ) )
F_134 ( V_126 ) ;
}
}
static int F_135 ( struct V_2 * V_3 )
{
memcpy ( & V_3 -> V_251 , & V_252 ,
sizeof( struct V_253 ) ) ;
F_136 ( V_3 ) ;
F_137 ( V_3 ) ;
F_138 ( V_3 ) ;
F_139 ( V_3 ) ;
return 0 ;
}
static int F_140 ( struct V_2 * V_3 )
{
int V_254 ;
if ( V_255 <= 2 )
V_254 = V_256 ;
else
V_254 = V_257 ;
if ( ! F_141 ( V_3 , V_258 , V_259 ,
V_254 , NULL ) ) {
F_62 (KERN_ERR PFX L_32 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_142 ( struct V_2 * V_3 )
{
V_3 -> V_74 = 0 ;
V_3 -> V_260 = 0 ;
V_3 -> V_261 = V_262 ;
V_3 -> V_263 = V_264 ;
V_3 -> V_265 = 2 * 1000 ;
V_3 -> V_266 = 10 * 1000 ;
V_3 -> V_267 = ( V_268 | V_269 |
V_270 | V_271 ) ;
V_3 -> V_272 = 1 ;
memset ( & V_3 -> V_273 , 0 , sizeof( struct V_274 ) ) ;
V_3 -> V_273 . V_275 = V_276 ;
if ( F_143 ( V_3 ) )
return - V_59 ;
F_144 ( V_3 ) ;
return 0 ;
}
static int F_145 ( struct V_17 * V_18 , struct V_1 * V_94 ,
struct V_116 * V_117 ,
struct V_1 * V_277 )
{
struct V_4 * V_29 ;
V_29 = F_61 ( V_117 , struct V_4 ,
V_278 ) ;
F_146 ( & V_29 -> V_75 , V_18 ) ;
return 0 ;
}
static void F_147 ( struct V_2 * V_3 , T_1 * V_279 )
{
struct V_5 * V_28 = F_2 ( V_3 ) ;
memcpy ( V_28 -> V_104 , V_279 , V_99 ) ;
}
static T_1 * F_148 ( struct V_2 * V_3 )
{
struct V_5 * V_28 ;
V_28 = (struct V_5 * ) F_2 ( V_3 ) ;
return V_28 -> V_104 ;
}
static void F_149 ( struct V_280 * V_281 , struct V_17 * V_18 )
{
V_18 -> V_94 = F_150 ( V_281 ) -> V_7 ;
F_151 ( V_18 ) ;
}
static int F_152 ( struct V_282 * V_187 , bool V_283 )
{
struct V_151 * V_152 = F_153 ( V_187 ) ;
struct V_2 * V_284 = F_97 ( V_152 ) ;
struct V_5 * V_28 = F_2 ( V_284 ) ;
struct V_4 * V_29 = V_28 -> V_6 ;
struct V_1 * V_7 = V_29 -> V_7 ;
struct V_2 * V_131 ;
int V_26 ;
char V_285 [ 32 ] ;
V_26 = F_154 ( V_187 ) ;
if ( V_26 ) {
F_155 ( V_187 -> V_286 , V_285 , sizeof( V_285 ) ) ;
F_62 (KERN_ERR PFX L_33
L_34 ,
buf) ;
return V_26 ;
}
if ( ! F_38 ( V_287 , & V_29 -> V_31 -> V_80 ) ) {
F_62 (KERN_ERR PFX L_35
L_36 ) ;
return - V_288 ;
}
F_156 () ;
F_18 ( & V_241 ) ;
V_131 = F_157 ( V_29 , & V_187 -> V_94 , 1 ) ;
F_21 ( & V_241 ) ;
F_158 () ;
if ( F_159 ( V_131 ) ) {
F_62 (KERN_ERR PFX L_37 ,
netdev->name) ;
return - V_288 ;
}
if ( V_283 ) {
F_160 ( V_187 , V_289 ) ;
} else {
V_131 -> V_290 = V_291 ;
F_161 ( V_131 ) ;
F_162 ( V_131 ) ;
F_163 ( V_131 ) ;
}
return 0 ;
}
static void F_164 ( struct V_30 * V_31 , struct V_2 * V_3 )
{
struct V_292 * V_293 , * V_146 ;
F_6 ( & V_31 -> V_37 ) ;
F_92 (blport, tmp, &hba->vports, list) {
if ( V_293 -> V_3 == V_3 ) {
F_165 ( & V_293 -> V_16 ) ;
F_95 ( V_293 ) ;
}
}
F_10 ( & V_31 -> V_37 ) ;
}
static int F_166 ( struct V_282 * V_187 )
{
struct V_151 * V_152 = F_153 ( V_187 ) ;
struct V_2 * V_284 = F_97 ( V_152 ) ;
struct V_2 * V_131 = V_187 -> V_294 ;
struct V_5 * V_28 = F_2 ( V_131 ) ;
struct V_4 * V_29 = V_28 -> V_6 ;
struct V_2 * V_295 ;
bool V_296 = false ;
F_18 ( & V_284 -> V_244 ) ;
F_126 (v_port, &n_port->vports, list)
if ( V_295 -> V_187 == V_187 ) {
V_296 = true ;
break;
}
if ( ! V_296 ) {
F_21 ( & V_284 -> V_244 ) ;
return - V_297 ;
}
F_165 ( & V_131 -> V_16 ) ;
F_21 ( & V_284 -> V_244 ) ;
F_164 ( V_29 -> V_31 , V_28 -> V_3 ) ;
F_167 ( V_28 -> V_3 ) ;
F_168 ( V_29 ) ;
F_169 ( V_298 , & V_28 -> V_299 ) ;
return 0 ;
}
static int F_170 ( struct V_282 * V_187 , bool V_300 )
{
struct V_2 * V_3 = V_187 -> V_294 ;
if ( V_300 ) {
F_160 ( V_187 , V_289 ) ;
F_171 ( V_3 ) ;
} else {
V_3 -> V_290 = V_291 ;
F_162 ( V_3 ) ;
F_163 ( V_3 ) ;
}
return 0 ;
}
static int F_172 ( struct V_4 * V_29 )
{
struct V_1 * V_7 = V_29 -> V_7 ;
struct V_1 * V_301 = V_29 -> V_31 -> V_209 ;
struct V_302 * V_303 ;
int V_304 = 0 ;
F_173 () ;
F_174 (physdev, ha) {
F_17 ( L_38 ,
V_303 -> type ) ;
F_62 ( V_305 L_39 , V_303 -> V_279 [ 0 ] ,
V_303 -> V_279 [ 1 ] , V_303 -> V_279 [ 2 ] , V_303 -> V_279 [ 3 ] ,
V_303 -> V_279 [ 4 ] , V_303 -> V_279 [ 5 ] ) ;
if ( ( V_303 -> type == V_306 ) &&
( F_175 ( V_303 -> V_279 ) ) ) {
memcpy ( V_29 -> V_75 . V_103 , V_303 -> V_279 ,
V_99 ) ;
V_304 = 1 ;
F_17 ( L_40 ) ;
}
}
F_176 () ;
if ( ! V_304 )
return - V_58 ;
V_29 -> V_278 . V_307 = F_145 ;
V_29 -> V_278 . type = F_50 ( V_308 ) ;
V_29 -> V_278 . V_94 = V_7 ;
F_177 ( & V_29 -> V_278 ) ;
V_29 -> V_120 . V_307 = F_60 ;
V_29 -> V_120 . type = F_178 ( V_93 ) ;
V_29 -> V_120 . V_94 = V_7 ;
F_177 ( & V_29 -> V_120 ) ;
return 0 ;
}
static int F_179 ( void )
{
V_190 =
F_180 ( & V_309 ) ;
if ( V_190 == NULL ) {
F_62 (KERN_ERR PFX L_41 ) ;
return - V_58 ;
}
V_189 =
F_180 ( & V_310 ) ;
if ( V_189 == NULL ) {
F_62 (KERN_ERR PFX
L_42 ) ;
F_181 ( V_190 ) ;
V_190 = NULL ;
return - V_58 ;
}
return 0 ;
}
static void F_182 ( void )
{
F_181 ( V_190 ) ;
F_181 ( V_189 ) ;
V_190 = NULL ;
V_189 = NULL ;
}
static void F_183 ( struct V_311 * V_311 )
{
struct V_4 * V_29 ;
struct V_1 * V_7 ;
V_29 = F_61 ( V_311 , struct V_4 , V_311 ) ;
F_17 ( L_43 ) ;
V_7 = V_29 -> V_7 ;
if ( F_184 ( V_312 , & V_29 -> V_313 ) )
F_185 ( & V_29 -> V_75 ) ;
F_95 ( V_29 ) ;
F_186 ( V_7 ) ;
F_187 ( V_314 ) ;
}
static inline void F_188 ( struct V_4 * V_29 )
{
F_189 ( & V_29 -> V_311 ) ;
}
static inline void F_168 ( struct V_4 * V_29 )
{
F_190 ( & V_29 -> V_311 , F_183 ) ;
}
static void F_191 ( struct V_30 * V_31 )
{
if ( V_31 -> V_315 ) {
F_192 ( V_31 -> V_315 ) ;
V_31 -> V_315 = NULL ;
}
F_95 ( V_31 -> V_39 ) ;
F_193 ( V_31 ) ;
F_95 ( V_31 ) ;
}
static struct V_30 * F_194 ( struct V_316 * V_317 )
{
struct V_30 * V_31 ;
int V_26 ;
V_31 = F_195 ( sizeof( * V_31 ) , V_318 ) ;
if ( ! V_31 ) {
F_62 (KERN_ERR PFX L_44 ) ;
return NULL ;
}
F_196 ( & V_31 -> V_37 ) ;
F_197 ( & V_31 -> V_36 ) ;
V_31 -> V_317 = V_317 ;
V_26 = F_198 ( V_31 ) ;
if ( V_26 ) {
F_62 (KERN_ERR PFX L_45 ) ;
goto V_319;
}
V_31 -> V_209 = V_317 -> V_7 ;
V_31 -> V_320 = 0 ;
V_31 -> V_39 =
F_195 ( sizeof( struct V_32 * ) * V_38 ,
V_318 ) ;
if ( ! V_31 -> V_39 ) {
F_62 (KERN_ERR PFX L_46 ) ;
goto V_321;
}
V_31 -> V_249 = 0 ;
V_31 -> V_315 = F_199 ( V_31 , V_322 ,
V_323 ) ;
if ( ! V_31 -> V_315 ) {
F_62 (KERN_ERR PFX L_47 ) ;
goto V_324;
}
F_131 ( & V_31 -> V_248 ) ;
F_131 ( & V_31 -> V_227 ) ;
F_200 ( & V_31 -> V_325 ) ;
return V_31 ;
V_324:
F_95 ( V_31 -> V_39 ) ;
V_321:
F_193 ( V_31 ) ;
V_319:
F_95 ( V_31 ) ;
return NULL ;
}
struct V_4 * F_201 ( struct V_30 * V_31 ,
struct V_1 * V_7 ,
enum V_326 V_327 )
{
struct V_4 * V_29 ;
int V_26 = 0 ;
V_29 = F_195 ( sizeof( * V_29 ) , V_318 ) ;
if ( ! V_29 ) {
F_62 (KERN_ERR PFX L_48 ) ;
return NULL ;
}
F_202 ( V_7 ) ;
F_203 ( & V_29 -> V_311 ) ;
V_29 -> V_31 = V_31 ;
V_29 -> V_7 = V_7 ;
F_204 ( & V_29 -> V_75 , V_327 ) ;
V_29 -> V_75 . V_328 = F_149 ;
V_29 -> V_75 . V_329 = F_147 ;
V_29 -> V_75 . V_330 = F_148 ;
F_112 ( V_312 , & V_29 -> V_313 ) ;
V_26 = F_172 ( V_29 ) ;
if ( ! V_26 )
return V_29 ;
F_185 ( & V_29 -> V_75 ) ;
F_186 ( V_7 ) ;
F_95 ( V_29 ) ;
return NULL ;
}
static struct V_2 * F_157 ( struct V_4 * V_29 ,
struct V_178 * V_331 , int V_332 )
{
struct V_2 * V_3 , * V_284 ;
struct V_5 * V_28 ;
struct V_151 * V_152 ;
struct V_282 * V_187 = F_205 ( V_331 ) ;
struct V_292 * V_293 ;
struct V_30 * V_31 ;
int V_26 = 0 ;
V_293 = F_195 ( sizeof( struct V_292 ) , V_318 ) ;
if ( ! V_293 ) {
F_31 ( V_29 -> V_75 . V_10 , L_49 ) ;
return NULL ;
}
if ( ! V_332 )
V_3 = F_206 ( & V_333 , sizeof( * V_28 ) ) ;
else
V_3 = F_207 ( V_187 , sizeof( * V_28 ) ) ;
if ( ! V_3 ) {
F_62 (KERN_ERR PFX L_50 ) ;
goto V_334;
}
V_152 = V_3 -> V_179 ;
V_28 = F_2 ( V_3 ) ;
V_28 -> V_3 = V_3 ;
V_28 -> V_6 = V_29 ;
F_208 ( & V_28 -> V_299 , V_335 ) ;
V_26 = F_142 ( V_3 ) ;
if ( V_26 )
goto V_336;
if ( V_332 ) {
F_62 (KERN_ERR PFX L_51 ,
vport->node_name, vport->port_name) ;
F_120 ( V_3 , V_187 -> V_337 ) ;
F_121 ( V_3 , V_187 -> V_286 ) ;
}
V_26 = F_114 ( V_3 , V_29 -> V_7 ) ;
if ( V_26 ) {
F_62 (KERN_ERR PFX L_52 ) ;
goto V_336;
}
V_26 = F_102 ( V_3 , V_331 ) ;
if ( V_26 ) {
F_62 (KERN_ERR PFX L_53 ,
interface->netdev->name) ;
goto V_336;
}
V_26 = F_135 ( V_3 ) ;
if ( V_26 ) {
F_62 (KERN_ERR PFX L_54 ) ;
goto V_338;
}
F_129 ( V_3 -> V_179 ) = V_245 ;
if ( ! V_332 )
V_26 = F_140 ( V_3 ) ;
else {
V_152 = F_153 ( V_187 ) ;
V_284 = F_97 ( V_152 ) ;
V_26 = F_209 ( V_284 , V_3 ) ;
}
if ( V_26 ) {
F_62 (KERN_ERR PFX L_55 ) ;
goto V_338;
}
F_188 ( V_29 ) ;
V_31 = V_29 -> V_31 ;
F_6 ( & V_31 -> V_37 ) ;
V_293 -> V_3 = V_3 ;
F_210 ( & V_293 -> V_16 , & V_31 -> V_325 ) ;
F_10 ( & V_31 -> V_37 ) ;
return V_3 ;
V_338:
F_211 ( V_152 ) ;
V_336:
F_212 ( V_3 -> V_179 ) ;
V_334:
F_95 ( V_293 ) ;
return NULL ;
}
static void F_213 ( struct V_4 * V_29 )
{
F_214 ( & V_29 -> V_120 ) ;
F_214 ( & V_29 -> V_278 ) ;
F_215 () ;
}
static void F_216 ( struct V_4 * V_29 )
{
struct V_2 * V_3 = V_29 -> V_75 . V_10 ;
struct V_5 * V_28 = F_2 ( V_3 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
F_217 ( & V_28 -> V_222 ) ;
F_130 ( V_3 ) ;
F_213 ( V_29 ) ;
F_164 ( V_31 , V_3 ) ;
}
static void F_218 ( struct V_2 * V_3 )
{
F_5 ( V_3 ) ;
F_219 ( V_3 -> V_179 ) ;
F_211 ( V_3 -> V_179 ) ;
F_220 ( V_3 ) ;
F_221 ( V_3 ) ;
F_212 ( V_3 -> V_179 ) ;
}
static void F_125 ( struct V_4 * V_29 )
{
struct V_2 * V_3 = V_29 -> V_75 . V_10 ;
struct V_5 * V_28 = F_2 ( V_3 ) ;
F_216 ( V_29 ) ;
F_222 ( V_29 ) ;
F_165 ( & V_29 -> V_16 ) ;
F_168 ( V_29 ) ;
F_169 ( V_298 , & V_28 -> V_299 ) ;
}
static int F_223 ( struct V_1 * V_7 )
{
struct V_4 * V_29 = NULL ;
struct V_339 * V_340 ;
int V_26 = 0 ;
F_156 () ;
F_18 ( & V_241 ) ;
V_29 = F_224 ( V_7 ) ;
if ( ! V_29 || ! V_29 -> V_75 . V_10 ) {
V_26 = - V_58 ;
F_62 (KERN_ERR PFX L_56 ) ;
goto V_341;
}
V_340 = V_29 -> V_340 ;
F_125 ( V_29 ) ;
F_225 ( V_340 ) ;
V_341:
F_21 ( & V_241 ) ;
F_158 () ;
return V_26 ;
}
static void V_335 ( struct V_342 * V_145 )
{
struct V_5 * V_28 ;
struct V_2 * V_3 ;
V_28 = F_61 ( V_145 , struct V_5 , V_299 ) ;
V_3 = V_28 -> V_3 ;
F_31 ( V_3 , L_57 ) ;
F_218 ( V_3 ) ;
}
static void F_226 ( struct V_30 * V_31 )
{
F_227 ( V_31 ) ;
F_228 ( V_31 ) ;
}
static int F_229 ( struct V_30 * V_31 )
{
if ( F_230 ( V_31 ) )
goto V_343;
if ( F_231 ( V_31 ) )
goto V_343;
return 0 ;
V_343:
F_226 ( V_31 ) ;
return - V_59 ;
}
static int F_198 ( struct V_30 * V_31 )
{
struct V_316 * V_317 ;
if ( ! V_31 -> V_317 ) {
F_62 (KERN_ERR PFX L_58 ) ;
return - V_58 ;
}
V_317 = V_31 -> V_317 ;
V_31 -> V_344 = V_317 -> V_344 ;
if ( V_31 -> V_344 )
F_232 ( V_31 -> V_344 ) ;
return 0 ;
}
static void F_193 ( struct V_30 * V_31 )
{
if ( V_31 -> V_344 )
F_233 ( V_31 -> V_344 ) ;
V_31 -> V_344 = NULL ;
}
static void F_234 ( void * V_345 )
{
struct V_30 * V_31 = V_345 ;
struct V_4 * V_29 ;
struct V_2 * V_3 ;
F_18 ( & V_241 ) ;
if ( ! F_38 ( V_287 , & V_31 -> V_80 ) )
F_235 ( V_31 ) ;
F_17 ( L_59 ) ;
F_126 (interface, &if_list, list) {
if ( V_29 -> V_31 == V_31 ) {
V_3 = V_29 -> V_75 . V_10 ;
F_62 (KERN_ERR PFX L_60 ) ;
V_3 -> V_251 . V_346 = F_29 ;
F_236 ( V_29 ) ;
}
}
F_21 ( & V_241 ) ;
}
static void F_167 ( struct V_2 * V_3 )
{
F_17 ( L_1 , V_35 ) ;
F_171 ( V_3 ) ;
F_237 ( V_3 ) ;
}
static void F_222 ( struct V_4 * V_29 )
{
struct V_2 * V_3 ;
struct V_2 * V_187 ;
if ( ! F_38 ( V_287 , & V_29 -> V_31 -> V_80 ) )
return;
V_3 = V_29 -> V_75 . V_10 ;
F_167 ( V_3 ) ;
F_18 ( & V_3 -> V_244 ) ;
F_126 (vport, &lport->vports, list)
F_129 ( V_187 -> V_179 ) =
V_245 ;
F_21 ( & V_3 -> V_244 ) ;
F_129 ( V_3 -> V_179 ) = V_245 ;
F_128 ( & V_29 -> V_75 ) ;
F_130 ( V_3 ) ;
}
static int F_235 ( struct V_30 * V_31 )
{
#define F_238 (1000 / HZ)
int V_26 = - 1 ;
int V_34 = V_158 ;
V_26 = F_229 ( V_31 ) ;
if ( V_26 ) {
F_62 (KERN_ALERT PFX
L_61 , rc) ;
goto V_347;
}
V_26 = F_239 ( V_31 ) ;
if ( V_26 ) {
F_62 (KERN_ALERT PFX
L_62 , rc) ;
goto V_348;
}
while ( ! F_38 ( V_235 , & V_31 -> V_212 ) && V_34 -- )
F_240 ( F_238 ) ;
if ( ! F_38 ( V_235 , & V_31 -> V_212 ) ) {
F_62 (KERN_ERR PFX L_63
L_64 ,
hba->cnic->netdev->name) ;
V_26 = - 1 ;
goto V_348;
}
F_112 ( V_287 , & V_31 -> V_80 ) ;
return 0 ;
V_348:
F_226 ( V_31 ) ;
V_347:
return V_26 ;
}
static void F_241 ( struct V_30 * V_31 )
{
if ( F_184 ( V_287 , & V_31 -> V_80 ) ) {
if ( F_242 ( V_31 ) == 0 ) {
F_243 ( & V_31 -> V_349 ) ;
V_31 -> V_349 . V_350 = V_351 +
V_291 ;
V_31 -> V_349 . V_352 = F_122 ;
V_31 -> V_349 . V_140 = ( unsigned long ) V_31 ;
F_244 ( & V_31 -> V_349 ) ;
F_132 ( V_31 -> V_227 ,
F_38 ( V_226 ,
& V_31 -> V_80 ) ) ;
F_111 ( V_226 , & V_31 -> V_80 ) ;
if ( F_133 ( V_126 ) )
F_134 ( V_126 ) ;
F_217 ( & V_31 -> V_349 ) ;
}
F_226 ( V_31 ) ;
}
}
static void F_245 ( void * V_345 )
{
struct V_30 * V_31 = V_345 ;
struct V_4 * V_29 ;
F_62 ( V_236 L_65 ) ;
F_18 ( & V_241 ) ;
if ( ! F_38 ( V_287 , & V_31 -> V_80 ) )
goto exit;
F_126 (interface, &if_list, list) {
if ( V_29 -> V_31 == V_31 )
F_222 ( V_29 ) ;
}
F_246 ( V_31 -> V_249 != 0 ) ;
F_18 ( & V_31 -> V_36 ) ;
F_111 ( V_235 , & V_31 -> V_212 ) ;
F_111 ( V_238 ,
& V_31 -> V_212 ) ;
F_111 ( V_247 , & V_31 -> V_212 ) ;
F_21 ( & V_31 -> V_36 ) ;
F_241 ( V_31 ) ;
exit:
F_21 ( & V_241 ) ;
}
static void F_236 ( struct V_4 * V_29 )
{
struct V_2 * V_3 ;
int V_353 = 0 ;
F_17 ( L_1 , V_35 ) ;
if ( ! F_38 ( V_287 , & V_29 -> V_31 -> V_80 ) ) {
F_62 (KERN_ERR PFX L_66 ) ;
return;
}
V_3 = V_29 -> V_75 . V_10 ;
F_31 ( V_3 , L_67 ) ;
if ( ! F_109 ( V_3 ) && V_29 -> V_243 ) {
F_31 ( V_3 , L_68 ) ;
F_127 ( & V_29 -> V_75 ) ;
F_129 ( V_3 -> V_179 ) = V_354 ;
F_112 ( V_247 , & V_29 -> V_31 -> V_212 ) ;
}
while ( ! V_29 -> V_75 . V_76 ) {
F_240 ( 250 ) ;
if ( ++ V_353 > 12 )
break;
}
if ( F_115 ( V_3 , V_220 ) )
return;
F_161 ( V_3 ) ;
F_162 ( V_3 ) ;
}
static void F_247 ( struct V_316 * V_94 )
{
struct V_30 * V_31 ;
int V_26 = 0 ;
F_17 ( L_1 , V_35 ) ;
if ( ! F_38 ( V_355 , & V_94 -> V_80 ) ||
( V_94 -> V_356 == 0 ) ) {
F_62 (KERN_ERR PFX L_69
L_70 ,
dev->netdev->name, dev->flags, dev->max_fcoe_conn) ;
return;
}
V_31 = F_194 ( V_94 ) ;
if ( ! V_31 ) {
F_62 (KERN_ERR PFX L_71 ) ;
return;
}
F_18 ( & V_241 ) ;
F_210 ( & V_31 -> V_16 , & V_357 ) ;
V_358 ++ ;
F_21 ( & V_241 ) ;
F_111 ( V_359 , & V_31 -> V_360 ) ;
V_26 = V_94 -> V_361 ( V_94 , V_362 ,
( void * ) V_31 ) ;
if ( V_26 )
F_62 (KERN_ERR PFX L_72 , rc) ;
else
F_112 ( V_359 , & V_31 -> V_360 ) ;
}
static int F_248 ( struct V_1 * V_7 )
{
struct V_4 * V_29 ;
int V_26 = 0 ;
F_156 () ;
F_18 ( & V_241 ) ;
V_29 = F_224 ( V_7 ) ;
if ( ! V_29 || ! V_29 -> V_75 . V_10 ) {
V_26 = - V_58 ;
F_62 (KERN_ERR PFX L_73 ) ;
} else {
V_29 -> V_243 = false ;
F_128 ( & V_29 -> V_75 ) ;
F_130 ( V_29 -> V_75 . V_10 ) ;
}
F_21 ( & V_241 ) ;
F_158 () ;
return V_26 ;
}
static int F_249 ( struct V_1 * V_7 )
{
struct V_4 * V_29 ;
int V_26 = 0 ;
F_156 () ;
F_18 ( & V_241 ) ;
V_29 = F_224 ( V_7 ) ;
if ( ! V_29 || ! V_29 -> V_75 . V_10 ) {
V_26 = - V_58 ;
F_62 (KERN_ERR PFX L_74 ) ;
} else if ( ! F_109 ( V_29 -> V_75 . V_10 ) ) {
F_127 ( & V_29 -> V_75 ) ;
V_29 -> V_243 = true ;
}
F_21 ( & V_241 ) ;
F_158 () ;
return V_26 ;
}
static int F_250 ( struct V_1 * V_7 , enum V_326 V_327 )
{
struct V_4 * V_29 ;
struct V_30 * V_31 ;
struct V_1 * V_209 ;
struct V_2 * V_3 ;
struct V_363 V_364 ;
int V_26 = 0 ;
int V_230 ;
F_17 ( L_75 ) ;
if ( V_327 != V_365 ) {
F_62 ( V_236 L_76 ) ;
return - V_288 ;
}
F_156 () ;
F_18 ( & V_241 ) ;
if ( ! F_251 ( V_314 ) ) {
V_26 = - V_77 ;
goto V_366;
}
if ( V_7 -> V_367 & V_368 ) {
V_209 = F_252 ( V_7 ) ;
V_230 = F_253 ( V_7 ) ;
} else {
F_62 (KERN_ERR PFX L_77 ) ;
V_26 = - V_77 ;
goto V_341;
}
if ( V_209 -> V_217 && V_209 -> V_217 -> V_369 ) {
memset ( & V_364 , 0 , sizeof( V_364 ) ) ;
V_209 -> V_217 -> V_369 ( V_209 , & V_364 ) ;
if ( strncmp ( V_364 . V_370 , L_78 , strlen ( L_78 ) ) ) {
F_62 (KERN_ERR PFX L_79 ) ;
V_26 = - V_77 ;
goto V_341;
}
} else {
F_62 (KERN_ERR PFX L_80 ) ;
V_26 = - V_77 ;
goto V_341;
}
V_31 = F_254 ( V_209 ) ;
if ( ! V_31 ) {
V_26 = - V_58 ;
F_62 (KERN_ERR PFX L_81 ) ;
goto V_341;
}
if ( F_224 ( V_7 ) ) {
V_26 = - V_371 ;
goto V_341;
}
V_29 = F_201 ( V_31 , V_7 , V_327 ) ;
if ( ! V_29 ) {
F_62 (KERN_ERR PFX L_82 ) ;
goto V_372;
}
V_29 -> V_230 = V_230 ;
V_29 -> V_373 = 1 ;
V_29 -> V_340 =
F_255 ( L_83 ) ;
if ( ! V_29 -> V_340 ) {
F_62 (KERN_ERR PFX L_84 ) ;
V_26 = - V_77 ;
goto V_372;
}
V_3 = F_157 ( V_29 , & V_29 -> V_31 -> V_344 -> V_94 , 0 ) ;
if ( ! V_3 ) {
F_62 (KERN_ERR PFX L_85 ,
netdev->name) ;
V_26 = - V_77 ;
goto V_374;
}
F_210 ( & V_29 -> V_16 , & V_375 ) ;
V_3 -> V_290 = V_291 ;
V_29 -> V_75 . V_10 = V_3 ;
if ( ! F_109 ( V_3 ) ) {
F_127 ( & V_29 -> V_75 ) ;
F_129 ( V_3 -> V_179 ) = V_354 ;
F_112 ( V_247 , & V_29 -> V_31 -> V_212 ) ;
}
F_31 ( V_3 , L_86 ) ;
F_236 ( V_29 ) ;
V_29 -> V_243 = true ;
F_168 ( V_29 ) ;
F_21 ( & V_241 ) ;
F_158 () ;
return 0 ;
V_374:
F_225 ( V_29 -> V_340 ) ;
V_372:
F_213 ( V_29 ) ;
F_168 ( V_29 ) ;
goto V_366;
V_341:
F_187 ( V_314 ) ;
V_366:
F_21 ( & V_241 ) ;
F_158 () ;
return V_26 ;
}
static struct V_30 * F_256 ( struct V_316 * V_317 )
{
struct V_376 * V_16 ;
struct V_376 * V_377 ;
struct V_30 * V_31 ;
F_257 (list, temp, &adapter_list) {
V_31 = (struct V_30 * ) V_16 ;
if ( V_31 -> V_317 == V_317 )
return V_31 ;
}
return NULL ;
}
static struct V_4 * F_224 ( struct V_1
* V_7 )
{
struct V_4 * V_29 ;
F_126 (interface, &if_list, list) {
if ( V_29 -> V_7 == V_7 )
return V_29 ;
}
return NULL ;
}
static struct V_30 * F_254 ( struct V_1
* V_209 )
{
struct V_30 * V_31 ;
F_126 (hba, &adapter_list, list) {
if ( V_31 -> V_209 == V_209 )
return V_31 ;
}
F_62 (KERN_ERR PFX L_87 ) ;
return NULL ;
}
static void F_258 ( struct V_316 * V_94 )
{
struct V_30 * V_31 ;
struct V_4 * V_29 , * V_146 ;
F_17 ( L_88 ) ;
if ( ! F_38 ( V_355 , & V_94 -> V_80 ) ) {
F_62 (KERN_ERR PFX L_89 ,
dev->netdev->name, dev->flags) ;
return;
}
F_18 ( & V_241 ) ;
V_31 = F_256 ( V_94 ) ;
if ( ! V_31 ) {
F_62 (KERN_ERR PFX L_90 ,
dev) ;
F_21 ( & V_241 ) ;
return;
}
F_93 ( & V_31 -> V_16 ) ;
V_358 -- ;
F_92 (interface, tmp, &if_list, list)
if ( V_29 -> V_31 == V_31 )
F_125 ( V_29 ) ;
F_21 ( & V_241 ) ;
F_245 ( V_31 ) ;
if ( F_184 ( V_359 , & V_31 -> V_360 ) )
V_31 -> V_317 -> V_378 ( V_31 -> V_317 , V_362 ) ;
F_191 ( V_31 ) ;
}
static int F_259 ( struct V_151 * V_152 )
{
struct V_2 * V_3 = F_97 ( V_152 ) ;
F_260 ( V_3 ) ;
return 0 ;
}
static bool F_261 ( struct V_1 * V_7 )
{
F_18 ( & V_241 ) ;
if ( V_7 -> V_367 & V_368 ) {
struct V_1 * V_209 = F_252 ( V_7 ) ;
if ( F_254 ( V_209 ) ) {
F_21 ( & V_241 ) ;
return true ;
}
}
F_21 ( & V_241 ) ;
return false ;
}
static void F_262 ( unsigned int V_379 )
{
struct V_142 * V_143 ;
struct V_380 * V_124 ;
V_143 = & F_263 ( V_381 , V_379 ) ;
V_124 = F_264 ( F_88 ,
( void * ) V_143 ,
L_91 , V_379 ) ;
if ( F_265 ( ! F_159 ( V_124 ) ) ) {
F_266 ( V_124 , V_379 ) ;
V_143 -> V_382 = V_124 ;
F_67 ( V_124 ) ;
}
}
static void F_267 ( unsigned int V_379 )
{
struct V_142 * V_143 ;
struct V_380 * V_124 ;
struct V_144 * V_145 , * V_146 ;
F_17 ( L_92 , V_379 ) ;
V_143 = & F_263 ( V_381 , V_379 ) ;
F_6 ( & V_143 -> V_148 ) ;
V_124 = V_143 -> V_382 ;
V_143 -> V_382 = NULL ;
F_92 (work, tmp, &p->work_list, list) {
F_93 ( & V_145 -> V_16 ) ;
F_94 ( V_145 -> V_33 , V_145 -> V_149 ) ;
F_95 ( V_145 ) ;
}
F_10 ( & V_143 -> V_148 ) ;
if ( V_124 )
F_268 ( V_124 ) ;
}
static int F_269 ( struct V_383 * V_384 ,
unsigned long V_385 , void * V_386 )
{
unsigned V_379 = ( unsigned long ) V_386 ;
switch ( V_385 ) {
case V_387 :
case V_388 :
F_62 ( V_389 L_93 , V_379 ) ;
F_262 ( V_379 ) ;
break;
case V_390 :
case V_391 :
F_62 ( V_389 L_94 , V_379 ) ;
F_267 ( V_379 ) ;
break;
default:
break;
}
return V_392 ;
}
static int T_6 F_270 ( void )
{
struct V_11 * V_12 ;
struct V_380 * V_393 ;
int V_26 = 0 ;
unsigned int V_379 = 0 ;
struct V_142 * V_143 ;
F_62 (KERN_INFO PFX L_95 , version) ;
V_26 = F_271 ( & V_394 ) ;
if ( V_26 ) {
F_62 ( V_236 L_96
L_97 ) ;
goto V_395;
}
F_200 ( & V_357 ) ;
F_200 ( & V_375 ) ;
F_197 ( & V_241 ) ;
V_358 = 0 ;
V_26 = F_179 () ;
if ( V_26 )
goto V_396;
V_298 = F_272 ( L_98 , 0 , 0 ) ;
if ( ! V_298 ) {
V_26 = - V_59 ;
goto V_397;
}
V_12 = & V_21 ;
F_116 ( & V_12 -> V_22 ) ;
V_393 = F_264 ( F_68 ,
( void * ) V_12 ,
L_99 ) ;
if ( F_159 ( V_393 ) ) {
V_26 = F_273 ( V_393 ) ;
goto V_398;
}
F_67 ( V_393 ) ;
F_6 ( & V_12 -> V_22 . V_23 ) ;
V_12 -> V_124 = V_393 ;
F_10 ( & V_12 -> V_22 . V_23 ) ;
F_274 (cpu) {
V_143 = & F_263 ( V_381 , V_379 ) ;
F_200 ( & V_143 -> V_147 ) ;
F_196 ( & V_143 -> V_148 ) ;
}
F_275 (cpu) {
F_262 ( V_379 ) ;
}
F_276 ( & V_399 ) ;
F_277 ( V_362 , & V_400 ) ;
return 0 ;
V_398:
F_225 ( V_298 ) ;
V_397:
F_182 () ;
V_396:
F_278 ( & V_394 ) ;
V_395:
return V_26 ;
}
static void T_7 F_279 ( void )
{
F_89 ( V_401 ) ;
struct V_30 * V_31 , * V_19 ;
struct V_11 * V_12 ;
struct V_380 * V_393 ;
struct V_17 * V_18 ;
unsigned int V_379 = 0 ;
F_18 ( & V_241 ) ;
F_280 ( & V_357 , & V_401 ) ;
F_200 ( & V_357 ) ;
V_358 = 0 ;
F_21 ( & V_241 ) ;
F_92 (hba, next, &to_be_deleted, list) {
F_93 ( & V_31 -> V_16 ) ;
F_62 (KERN_ERR PFX L_100 ,
hba) ;
F_245 ( V_31 ) ;
if ( F_184 ( V_359 ,
& V_31 -> V_360 ) )
V_31 -> V_317 -> V_378 ( V_31 -> V_317 ,
V_362 ) ;
F_191 ( V_31 ) ;
}
F_281 ( V_362 ) ;
V_12 = & V_21 ;
F_6 ( & V_12 -> V_22 . V_23 ) ;
V_393 = V_12 -> V_124 ;
V_12 -> V_124 = NULL ;
while ( ( V_18 = F_73 ( & V_12 -> V_22 ) ) != NULL )
F_9 ( V_18 ) ;
F_10 ( & V_12 -> V_22 . V_23 ) ;
if ( V_393 )
F_268 ( V_393 ) ;
F_282 ( & V_399 ) ;
F_275 (cpu) {
F_267 ( V_379 ) ;
}
F_225 ( V_298 ) ;
F_182 () ;
F_278 ( & V_394 ) ;
}
