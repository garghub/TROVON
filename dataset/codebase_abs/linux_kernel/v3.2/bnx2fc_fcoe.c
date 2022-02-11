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
V_63 = F_42 ( F_43 ( V_85 ) , V_88 )
+ V_85 -> V_89 ;
} else {
V_63 = (struct V_62 * ) F_44 ( V_18 , V_25 ) ;
}
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> V_90 = V_69 ;
V_63 -> V_91 = F_45 ( ~ V_70 ) ;
if ( F_40 ( V_18 ) ) {
F_46 ( V_63 , V_88 ) ;
V_63 = NULL ;
}
F_47 ( V_18 , V_72 + V_71 ) ;
F_48 ( V_18 ) ;
F_49 ( V_18 ) ;
V_18 -> V_92 = V_72 ;
V_18 -> V_93 = F_50 ( V_94 ) ;
V_18 -> V_95 = V_29 -> V_7 ;
V_61 = F_51 ( V_18 ) ;
V_61 -> V_96 = F_50 ( V_94 ) ;
if ( V_29 -> V_75 . V_97 )
F_52 ( V_61 -> V_98 , V_45 -> V_78 ) ;
else
memcpy ( V_61 -> V_98 , V_29 -> V_75 . V_99 , V_100 ) ;
if ( F_32 ( V_29 -> V_75 . V_101 != V_102 ) )
memcpy ( V_61 -> V_103 , V_29 -> V_75 . V_104 , V_100 ) ;
else
memcpy ( V_61 -> V_103 , V_28 -> V_105 , V_100 ) ;
V_65 = (struct V_64 * ) ( V_61 + 1 ) ;
memset ( V_65 , 0 , sizeof( * V_65 ) ) ;
if ( V_106 )
F_53 ( V_65 , V_106 ) ;
V_65 -> V_107 = V_68 ;
if ( V_3 -> V_108 && F_54 ( V_41 ) ) {
F_41 ( V_18 ) -> V_109 = V_110 ;
F_41 ( V_18 ) -> V_111 = F_54 ( V_41 ) ;
} else {
F_41 ( V_18 ) -> V_109 = 0 ;
F_41 ( V_18 ) -> V_111 = 0 ;
}
V_67 = F_55 ( V_3 -> V_112 , F_56 () ) ;
V_67 -> V_113 ++ ;
V_67 -> V_114 += V_73 ;
F_57 () ;
V_24 ( V_41 ) = V_3 ;
if ( V_28 -> V_115 . V_116 )
F_58 ( V_3 , V_18 ) ;
else if ( F_59 ( V_18 ) )
F_58 ( V_3 , V_18 ) ;
return 0 ;
}
static int F_60 ( struct V_17 * V_18 , struct V_1 * V_95 ,
struct V_117 * V_118 , struct V_1 * V_119 )
{
struct V_2 * V_3 ;
struct V_4 * V_29 ;
struct V_44 * V_45 ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
unsigned short V_120 ;
V_29 = F_61 ( V_118 , struct V_4 ,
V_121 ) ;
V_3 = V_29 -> V_75 . V_10 ;
if ( F_32 ( V_3 == NULL ) ) {
F_62 (KERN_ERR PFX L_12 ) ;
goto V_122;
}
if ( F_32 ( F_51 ( V_18 ) -> V_96 != F_50 ( V_94 ) ) ) {
F_62 (KERN_ERR PFX L_13 ) ;
goto V_122;
}
if ( F_32 ( ( V_18 -> V_81 < V_123 ) ||
! F_63 ( V_18 , V_124 ) ) )
goto V_122;
F_64 ( V_18 , sizeof( struct V_64 ) ) ;
V_45 = (struct V_44 * ) F_65 ( V_18 ) ;
V_120 = F_24 ( V_45 -> V_48 ) ;
V_14 = F_7 ( V_18 ) ;
V_14 -> V_24 = V_3 ;
V_12 = & V_21 ;
F_6 ( & V_12 -> V_22 . V_23 ) ;
F_66 ( & V_12 -> V_22 , V_18 ) ;
if ( V_12 -> V_22 . V_116 == 1 )
F_67 ( V_12 -> V_125 ) ;
F_10 ( & V_12 -> V_22 . V_23 ) ;
return 0 ;
V_122:
F_9 ( V_18 ) ;
return - 1 ;
}
static int F_68 ( void * V_126 )
{
struct V_11 * V_12 = V_126 ;
struct V_17 * V_18 ;
F_69 ( V_127 , - 20 ) ;
F_70 ( V_128 ) ;
while ( ! F_71 () ) {
F_72 () ;
F_6 ( & V_12 -> V_22 . V_23 ) ;
while ( ( V_18 = F_73 ( & V_12 -> V_22 ) ) != NULL ) {
F_10 ( & V_12 -> V_22 . V_23 ) ;
F_74 ( V_18 ) ;
F_6 ( & V_12 -> V_22 . V_23 ) ;
}
F_75 ( V_128 ) ;
F_10 ( & V_12 -> V_22 . V_23 ) ;
}
F_75 ( V_129 ) ;
return 0 ;
}
static void F_74 ( struct V_17 * V_18 )
{
T_2 V_130 ;
struct V_2 * V_3 ;
struct V_13 * V_14 ;
struct V_66 * V_67 ;
struct V_44 * V_45 ;
struct V_62 V_131 ;
struct V_40 * V_41 ;
struct V_2 * V_132 ;
struct V_5 * V_28 ;
T_1 * V_133 = NULL ;
T_1 * V_134 = NULL ;
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
V_133 = F_51 ( V_18 ) -> V_103 ;
V_134 = F_51 ( V_18 ) -> V_98 ;
V_65 = (struct V_64 * ) F_77 ( V_18 ) ;
V_45 = (struct V_44 * ) F_65 ( V_18 ) ;
F_78 ( V_18 , sizeof( struct V_64 ) ) ;
V_130 = V_18 -> V_81 - sizeof( struct V_62 ) ;
V_67 = F_55 ( V_3 -> V_112 , F_56 () ) ;
V_67 -> V_135 ++ ;
V_67 -> V_136 += V_130 / V_82 ;
V_41 = (struct V_40 * ) V_18 ;
F_79 ( V_41 ) ;
V_24 ( V_41 ) = V_3 ;
F_34 ( V_41 ) = V_65 -> V_107 ;
if ( F_80 ( V_18 , V_130 , & V_131 , sizeof( V_131 ) ) ) {
F_57 () ;
F_9 ( V_18 ) ;
return;
}
F_35 ( V_41 ) = V_131 . V_90 ;
F_81 ( V_41 ) = V_131 . V_91 ;
if ( F_82 ( V_18 , V_130 ) ) {
F_57 () ;
F_9 ( V_18 ) ;
return;
}
V_45 = F_23 ( V_41 ) ;
V_132 = F_83 ( V_3 , F_37 ( V_45 -> V_78 ) ) ;
if ( V_132 ) {
V_28 = F_2 ( V_132 ) ;
if ( F_84 ( V_28 -> V_105 , V_134 )
!= 0 ) {
F_31 ( V_3 , L_15 ) ;
F_57 () ;
F_9 ( V_18 ) ;
return;
}
}
if ( V_45 -> V_49 == V_137 &&
V_45 -> V_50 == V_138 ) {
F_57 () ;
F_9 ( V_18 ) ;
return;
}
if ( V_45 -> V_49 == V_52 &&
V_45 -> V_50 == V_51 ) {
switch ( F_25 ( V_41 ) ) {
case V_54 :
if ( F_37 ( V_45 -> V_139 ) == V_140 ) {
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
~ F_86 ( ~ 0 , V_18 -> V_141 , V_130 ) ) {
if ( V_67 -> V_142 < 5 )
F_62 (KERN_WARNING PFX L_16
L_17 ) ;
V_67 -> V_142 ++ ;
F_57 () ;
F_9 ( V_18 ) ;
return;
}
F_57 () ;
F_87 ( V_3 , V_41 ) ;
}
int F_88 ( void * V_126 )
{
struct V_143 * V_144 = V_126 ;
struct V_145 * V_146 , * V_147 ;
F_89 ( V_148 ) ;
F_69 ( V_127 , - 20 ) ;
F_70 ( V_128 ) ;
while ( ! F_71 () ) {
F_72 () ;
F_6 ( & V_144 -> V_149 ) ;
while ( ! F_90 ( & V_144 -> V_148 ) ) {
F_91 ( & V_144 -> V_148 , & V_148 ) ;
F_10 ( & V_144 -> V_149 ) ;
F_92 (work, tmp, &work_list, list) {
F_93 ( & V_146 -> V_16 ) ;
F_94 ( V_146 -> V_33 , V_146 -> V_150 ) ;
F_95 ( V_146 ) ;
}
F_6 ( & V_144 -> V_149 ) ;
}
F_75 ( V_128 ) ;
F_10 ( & V_144 -> V_149 ) ;
}
F_75 ( V_129 ) ;
return 0 ;
}
static struct V_151 * F_96 ( struct V_152 * V_153 )
{
struct V_151 * V_154 ;
struct V_2 * V_3 = F_97 ( V_153 ) ;
struct V_5 * V_28 = F_2 ( V_3 ) ;
struct V_4 * V_29 = V_28 -> V_6 ;
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_155 * V_156 ;
int V_26 = 0 ;
V_156 = (struct V_155 * ) V_31 -> V_157 ;
if ( ! V_156 )
return NULL ;
V_154 = F_98 ( V_153 ) ;
F_99 ( & V_31 -> V_158 ) ;
if ( F_100 ( V_31 ) )
return V_154 ;
V_26 = F_101 ( & V_31 -> V_158 , ( 2 * V_159 ) ) ;
if ( ! V_26 ) {
F_31 ( V_3 , L_18 ) ;
return V_154 ;
}
V_154 -> V_160 += V_156 -> V_161 . V_162 ;
V_154 -> V_163 += V_156 -> V_164 . V_165 ;
V_154 -> V_166 += ( V_156 -> V_164 . V_167 ) / 4 ;
V_154 -> V_168 += V_156 -> V_169 . V_170 ;
V_154 -> V_171 += ( V_156 -> V_169 . V_172 ) / 4 ;
V_154 -> V_173 = 0 ;
V_154 -> V_174 = 0 ;
V_154 -> V_175 = 0 ;
V_154 -> V_176 = 0 ;
V_154 -> V_177 = 0 ;
V_154 -> V_178 = 0 ;
return V_154 ;
}
static int F_102 ( struct V_2 * V_3 , struct V_179 * V_95 )
{
struct V_5 * V_28 = F_2 ( V_3 ) ;
struct V_4 * V_29 = V_28 -> V_6 ;
struct V_152 * V_153 = V_3 -> V_180 ;
int V_26 = 0 ;
V_153 -> V_181 = V_182 ;
V_153 -> V_183 = V_184 ;
V_153 -> V_185 = V_186 ;
V_153 -> V_187 = 0 ;
if ( V_3 -> V_188 )
V_153 -> V_189 = V_190 ;
else
V_153 -> V_189 = V_191 ;
V_26 = F_103 ( V_3 -> V_180 , V_95 ) ;
if ( V_26 ) {
F_62 (KERN_ERR PFX L_19 ) ;
return V_26 ;
}
if ( ! V_3 -> V_188 )
F_104 ( V_3 -> V_180 ) = V_192 ;
sprintf ( F_105 ( V_3 -> V_180 ) , L_20 ,
V_193 , V_194 ,
V_29 -> V_7 -> V_195 ) ;
return 0 ;
}
static void F_106 ( struct V_2 * V_3 )
{
struct V_5 * V_28 = F_2 ( V_3 ) ;
struct V_4 * V_29 = V_28 -> V_6 ;
struct V_1 * V_7 = V_29 -> V_7 ;
struct V_196 V_197 ;
if ( ! F_107 ( V_7 , & V_197 ) ) {
V_3 -> V_198 &=
~ ( V_199 | V_200 ) ;
if ( V_197 . V_201 & ( V_202 |
V_203 ) )
V_3 -> V_198 |= V_199 ;
if ( V_197 . V_201 & V_204 )
V_3 -> V_198 |= V_200 ;
switch ( F_108 ( & V_197 ) ) {
case V_205 :
V_3 -> V_206 = V_199 ;
break;
case V_207 :
V_3 -> V_206 = V_208 ;
break;
case V_209 :
V_3 -> V_206 = V_200 ;
break;
}
}
}
static int F_109 ( struct V_2 * V_3 )
{
struct V_5 * V_28 = F_2 ( V_3 ) ;
struct V_4 * V_29 = V_28 -> V_6 ;
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_1 * V_95 = V_31 -> V_210 ;
int V_26 = 0 ;
if ( ( V_95 -> V_80 & V_211 ) && F_110 ( V_95 ) )
F_111 ( V_212 , & V_31 -> V_213 ) ;
else {
F_112 ( V_212 , & V_31 -> V_213 ) ;
V_26 = - 1 ;
}
return V_26 ;
}
void F_113 ( struct V_30 * V_31 )
{
if ( F_38 ( V_214 , & V_31 -> V_210 -> V_215 ) )
F_112 ( V_212 , & V_31 -> V_213 ) ;
else
F_111 ( V_212 , & V_31 -> V_213 ) ;
}
static int F_114 ( struct V_2 * V_3 , struct V_1 * V_7 )
{
struct V_30 * V_31 ;
struct V_4 * V_29 ;
struct V_5 * V_28 ;
T_4 V_216 , V_217 ;
V_28 = F_2 ( V_3 ) ;
V_29 = V_28 -> V_6 ;
V_31 = V_29 -> V_31 ;
if ( ! V_31 -> V_210 -> V_218 ||
! V_31 -> V_210 -> V_218 -> V_219 )
return - V_220 ;
if ( F_115 ( V_3 , V_221 ) )
return - V_77 ;
F_116 ( & V_28 -> V_115 ) ;
V_28 -> V_222 = 0 ;
F_117 ( & V_28 -> V_223 , V_224 , ( unsigned long ) V_3 ) ;
F_106 ( V_3 ) ;
if ( ! V_3 -> V_188 ) {
if ( F_118 ( V_7 , & V_216 , V_225 ) )
V_216 = F_119 ( V_29 -> V_75 . V_104 ,
1 , 0 ) ;
F_31 ( V_3 , L_21 , V_216 ) ;
F_120 ( V_3 , V_216 ) ;
if ( F_118 ( V_7 , & V_217 , V_226 ) )
V_217 = F_119 ( V_29 -> V_75 . V_104 ,
2 , 0 ) ;
F_31 ( V_3 , L_22 , V_217 ) ;
F_121 ( V_3 , V_217 ) ;
}
return 0 ;
}
static void F_122 ( unsigned long V_141 )
{
struct V_30 * V_31 = (struct V_30 * ) V_141 ;
F_62 (KERN_ERR PFX L_23
L_24 ) ;
F_112 ( V_227 , & V_31 -> V_80 ) ;
F_123 ( & V_31 -> V_228 ) ;
}
static void F_124 ( void * V_229 , unsigned long V_230 ,
T_5 V_231 )
{
struct V_30 * V_31 = (struct V_30 * ) V_229 ;
struct V_2 * V_3 ;
struct V_2 * V_188 ;
struct V_4 * V_29 , * V_147 ;
int V_232 = 0 ;
T_2 V_233 = 1 ;
if ( V_231 != 0 && V_230 != V_234 )
return;
switch ( V_230 ) {
case V_235 :
if ( ! F_38 ( V_236 , & V_31 -> V_213 ) )
F_62 ( V_237 L_25\
L_26 ) ;
break;
case V_238 :
F_111 ( V_239 , & V_31 -> V_213 ) ;
F_111 ( V_236 , & V_31 -> V_213 ) ;
V_233 = 0 ;
break;
case V_240 :
F_112 ( V_239 , & V_31 -> V_213 ) ;
V_233 = 0 ;
break;
case V_241 :
break;
case V_234 :
if ( ! V_231 )
return;
F_18 ( & V_242 ) ;
F_92 (interface, tmp, &if_list, list) {
if ( V_29 -> V_31 == V_31 &&
V_29 -> V_231 == ( V_231 & V_243 ) )
F_125 ( V_29 ) ;
}
F_21 ( & V_242 ) ;
return;
default:
F_62 (KERN_ERR PFX L_27 , event) ;
return;
}
F_18 ( & V_242 ) ;
F_126 (interface, &if_list, list) {
if ( V_29 -> V_31 != V_31 )
continue;
V_3 = V_29 -> V_75 . V_10 ;
F_31 ( V_3 , L_28 ,
V_29 -> V_7 -> V_195 , V_230 ) ;
F_106 ( V_3 ) ;
if ( V_233 && ! F_109 ( V_3 ) ) {
F_115 ( V_3 , V_221 ) ;
if ( V_29 -> V_244 )
F_127 ( & V_29 -> V_75 ) ;
} else if ( F_128 ( & V_29 -> V_75 ) ) {
F_18 ( & V_3 -> V_245 ) ;
F_126 (vport, &lport->vports, list)
F_129 ( V_188 -> V_180 ) =
V_246 ;
F_21 ( & V_3 -> V_245 ) ;
F_129 ( V_3 -> V_180 ) = V_246 ;
F_55 ( V_3 -> V_112 ,
F_56 () ) -> V_247 ++ ;
F_57 () ;
F_130 ( V_3 ) ;
V_232 = 1 ;
}
}
F_21 ( & V_242 ) ;
if ( V_232 ) {
F_111 ( V_248 , & V_31 -> V_213 ) ;
F_131 ( & V_31 -> V_249 ) ;
F_17 ( L_29
L_30 ,
V_31 -> V_250 ) ;
V_31 -> V_251 = 1 ;
F_132 ( V_31 -> V_249 ,
( V_31 -> V_250 == 0 ) ) ;
F_17 ( L_31 ,
V_31 -> V_250 ) ;
V_31 -> V_251 = 0 ;
if ( F_133 ( V_127 ) )
F_134 ( V_127 ) ;
}
}
static int F_135 ( struct V_2 * V_3 )
{
memcpy ( & V_3 -> V_252 , & V_253 ,
sizeof( struct V_254 ) ) ;
F_136 ( V_3 ) ;
F_137 ( V_3 ) ;
F_138 ( V_3 ) ;
F_139 ( V_3 ) ;
return 0 ;
}
static int F_140 ( struct V_2 * V_3 )
{
if ( ! F_141 ( V_3 , V_255 , V_256 ,
V_257 , NULL ) ) {
F_62 (KERN_ERR PFX L_32 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_142 ( struct V_2 * V_3 )
{
V_3 -> V_74 = 0 ;
V_3 -> V_258 = 0 ;
V_3 -> V_259 = 3 ;
V_3 -> V_260 = 3 ;
V_3 -> V_261 = 2 * 1000 ;
V_3 -> V_262 = 10 * 1000 ;
V_3 -> V_263 = ( V_264 | V_265 |
V_266 | V_267 ) ;
V_3 -> V_268 = 1 ;
memset ( & V_3 -> V_269 , 0 , sizeof( struct V_270 ) ) ;
V_3 -> V_269 . V_271 = V_272 ;
if ( F_143 ( V_3 ) )
return - V_59 ;
F_144 ( V_3 ) ;
return 0 ;
}
static int F_145 ( struct V_17 * V_18 , struct V_1 * V_95 ,
struct V_117 * V_118 ,
struct V_1 * V_273 )
{
struct V_4 * V_29 ;
V_29 = F_61 ( V_118 , struct V_4 ,
V_274 ) ;
F_146 ( & V_29 -> V_75 , V_18 ) ;
return 0 ;
}
static void F_147 ( struct V_2 * V_3 , T_1 * V_275 )
{
struct V_5 * V_28 = F_2 ( V_3 ) ;
memcpy ( V_28 -> V_105 , V_275 , V_100 ) ;
}
static T_1 * F_148 ( struct V_2 * V_3 )
{
struct V_5 * V_28 ;
V_28 = (struct V_5 * ) F_2 ( V_3 ) ;
return V_28 -> V_105 ;
}
static void F_149 ( struct V_276 * V_277 , struct V_17 * V_18 )
{
V_18 -> V_95 = F_150 ( V_277 ) -> V_7 ;
F_151 ( V_18 ) ;
}
static int F_152 ( struct V_278 * V_188 , bool V_279 )
{
struct V_152 * V_153 = F_153 ( V_188 ) ;
struct V_2 * V_280 = F_97 ( V_153 ) ;
struct V_5 * V_28 = F_2 ( V_280 ) ;
struct V_4 * V_29 = V_28 -> V_6 ;
struct V_1 * V_7 = V_29 -> V_7 ;
struct V_2 * V_132 ;
int V_26 ;
char V_281 [ 32 ] ;
V_26 = F_154 ( V_188 ) ;
if ( V_26 ) {
F_155 ( V_188 -> V_282 , V_281 , sizeof( V_281 ) ) ;
F_62 (KERN_ERR PFX L_33
L_34 ,
buf) ;
return V_26 ;
}
if ( ! F_38 ( V_283 , & V_29 -> V_31 -> V_80 ) ) {
F_62 (KERN_ERR PFX L_35
L_36 ) ;
return - V_284 ;
}
F_156 () ;
F_18 ( & V_242 ) ;
V_132 = F_157 ( V_29 , & V_188 -> V_95 , 1 ) ;
F_21 ( & V_242 ) ;
F_158 () ;
if ( F_159 ( V_132 ) ) {
F_62 (KERN_ERR PFX L_37 ,
netdev->name) ;
return - V_284 ;
}
if ( V_279 ) {
F_160 ( V_188 , V_285 ) ;
} else {
V_132 -> V_286 = V_287 ;
F_161 ( V_132 ) ;
F_162 ( V_132 ) ;
F_163 ( V_132 ) ;
}
return 0 ;
}
static void F_164 ( struct V_30 * V_31 , struct V_2 * V_3 )
{
struct V_288 * V_289 , * V_147 ;
F_6 ( & V_31 -> V_37 ) ;
F_92 (blport, tmp, &hba->vports, list) {
if ( V_289 -> V_3 == V_3 ) {
F_165 ( & V_289 -> V_16 ) ;
F_95 ( V_289 ) ;
}
}
F_10 ( & V_31 -> V_37 ) ;
}
static int F_166 ( struct V_278 * V_188 )
{
struct V_152 * V_153 = F_153 ( V_188 ) ;
struct V_2 * V_280 = F_97 ( V_153 ) ;
struct V_2 * V_132 = V_188 -> V_290 ;
struct V_5 * V_28 = F_2 ( V_132 ) ;
struct V_4 * V_29 = V_28 -> V_6 ;
struct V_2 * V_291 ;
bool V_292 = false ;
F_18 ( & V_280 -> V_245 ) ;
F_126 (v_port, &n_port->vports, list)
if ( V_291 -> V_188 == V_188 ) {
V_292 = true ;
break;
}
if ( ! V_292 ) {
F_21 ( & V_280 -> V_245 ) ;
return - V_293 ;
}
F_165 ( & V_132 -> V_16 ) ;
F_21 ( & V_280 -> V_245 ) ;
F_164 ( V_29 -> V_31 , V_28 -> V_3 ) ;
F_167 ( V_28 -> V_3 ) ;
F_168 ( V_29 ) ;
F_169 ( V_294 , & V_28 -> V_295 ) ;
return 0 ;
}
static int F_170 ( struct V_278 * V_188 , bool V_296 )
{
struct V_2 * V_3 = V_188 -> V_290 ;
if ( V_296 ) {
F_160 ( V_188 , V_285 ) ;
F_171 ( V_3 ) ;
} else {
V_3 -> V_286 = V_287 ;
F_162 ( V_3 ) ;
F_163 ( V_3 ) ;
}
return 0 ;
}
static int F_172 ( struct V_4 * V_29 )
{
struct V_1 * V_7 = V_29 -> V_7 ;
struct V_1 * V_297 = V_29 -> V_31 -> V_210 ;
struct V_298 * V_299 ;
int V_300 = 0 ;
F_173 () ;
F_174 (physdev, ha) {
F_17 ( L_38 ,
V_299 -> type ) ;
F_62 ( V_301 L_39 , V_299 -> V_275 [ 0 ] ,
V_299 -> V_275 [ 1 ] , V_299 -> V_275 [ 2 ] , V_299 -> V_275 [ 3 ] ,
V_299 -> V_275 [ 4 ] , V_299 -> V_275 [ 5 ] ) ;
if ( ( V_299 -> type == V_302 ) &&
( F_175 ( V_299 -> V_275 ) ) ) {
memcpy ( V_29 -> V_75 . V_104 , V_299 -> V_275 ,
V_100 ) ;
V_300 = 1 ;
F_17 ( L_40 ) ;
}
}
F_176 () ;
if ( ! V_300 )
return - V_58 ;
V_29 -> V_274 . V_303 = F_145 ;
V_29 -> V_274 . type = F_50 ( V_304 ) ;
V_29 -> V_274 . V_95 = V_7 ;
F_177 ( & V_29 -> V_274 ) ;
V_29 -> V_121 . V_303 = F_60 ;
V_29 -> V_121 . type = F_178 ( V_94 ) ;
V_29 -> V_121 . V_95 = V_7 ;
F_177 ( & V_29 -> V_121 ) ;
return 0 ;
}
static int F_179 ( void )
{
V_191 =
F_180 ( & V_305 ) ;
if ( V_191 == NULL ) {
F_62 (KERN_ERR PFX L_41 ) ;
return - V_58 ;
}
V_190 =
F_180 ( & V_306 ) ;
if ( V_190 == NULL ) {
F_62 (KERN_ERR PFX
L_42 ) ;
F_181 ( V_191 ) ;
V_191 = NULL ;
return - V_58 ;
}
return 0 ;
}
static void F_182 ( void )
{
F_181 ( V_191 ) ;
F_181 ( V_190 ) ;
V_191 = NULL ;
V_190 = NULL ;
}
static void F_183 ( struct V_307 * V_307 )
{
struct V_4 * V_29 ;
struct V_1 * V_7 ;
V_29 = F_61 ( V_307 , struct V_4 , V_307 ) ;
F_17 ( L_43 ) ;
V_7 = V_29 -> V_7 ;
if ( F_184 ( V_308 , & V_29 -> V_309 ) )
F_185 ( & V_29 -> V_75 ) ;
F_95 ( V_29 ) ;
F_186 ( V_7 ) ;
F_187 ( V_310 ) ;
}
static inline void F_188 ( struct V_4 * V_29 )
{
F_189 ( & V_29 -> V_307 ) ;
}
static inline void F_168 ( struct V_4 * V_29 )
{
F_190 ( & V_29 -> V_307 , F_183 ) ;
}
static void F_191 ( struct V_30 * V_31 )
{
if ( V_31 -> V_311 ) {
F_192 ( V_31 -> V_311 ) ;
V_31 -> V_311 = NULL ;
}
F_95 ( V_31 -> V_39 ) ;
F_193 ( V_31 ) ;
F_95 ( V_31 ) ;
}
static struct V_30 * F_194 ( struct V_312 * V_313 )
{
struct V_30 * V_31 ;
int V_26 ;
V_31 = F_195 ( sizeof( * V_31 ) , V_314 ) ;
if ( ! V_31 ) {
F_62 (KERN_ERR PFX L_44 ) ;
return NULL ;
}
F_196 ( & V_31 -> V_37 ) ;
F_197 ( & V_31 -> V_36 ) ;
V_31 -> V_313 = V_313 ;
V_26 = F_198 ( V_31 ) ;
if ( V_26 ) {
F_62 (KERN_ERR PFX L_45 ) ;
goto V_315;
}
V_31 -> V_210 = V_313 -> V_7 ;
V_31 -> V_316 = 0 ;
V_31 -> V_39 =
F_195 ( sizeof( struct V_32 * ) * V_38 ,
V_314 ) ;
if ( ! V_31 -> V_39 ) {
F_62 (KERN_ERR PFX L_46 ) ;
goto V_317;
}
V_31 -> V_250 = 0 ;
V_31 -> V_311 = F_199 ( V_31 , V_318 ,
V_319 ) ;
if ( ! V_31 -> V_311 ) {
F_62 (KERN_ERR PFX L_47 ) ;
goto V_320;
}
F_131 ( & V_31 -> V_249 ) ;
F_131 ( & V_31 -> V_228 ) ;
F_200 ( & V_31 -> V_321 ) ;
return V_31 ;
V_320:
F_95 ( V_31 -> V_39 ) ;
V_317:
F_193 ( V_31 ) ;
V_315:
F_95 ( V_31 ) ;
return NULL ;
}
struct V_4 * F_201 ( struct V_30 * V_31 ,
struct V_1 * V_7 ,
enum V_322 V_323 )
{
struct V_4 * V_29 ;
int V_26 = 0 ;
V_29 = F_195 ( sizeof( * V_29 ) , V_314 ) ;
if ( ! V_29 ) {
F_62 (KERN_ERR PFX L_48 ) ;
return NULL ;
}
F_202 ( V_7 ) ;
F_203 ( & V_29 -> V_307 ) ;
V_29 -> V_31 = V_31 ;
V_29 -> V_7 = V_7 ;
F_204 ( & V_29 -> V_75 , V_323 ) ;
V_29 -> V_75 . V_324 = F_149 ;
V_29 -> V_75 . V_325 = F_147 ;
V_29 -> V_75 . V_326 = F_148 ;
F_112 ( V_308 , & V_29 -> V_309 ) ;
V_26 = F_172 ( V_29 ) ;
if ( ! V_26 )
return V_29 ;
F_185 ( & V_29 -> V_75 ) ;
F_186 ( V_7 ) ;
F_95 ( V_29 ) ;
return NULL ;
}
static struct V_2 * F_157 ( struct V_4 * V_29 ,
struct V_179 * V_327 , int V_328 )
{
struct V_2 * V_3 , * V_280 ;
struct V_5 * V_28 ;
struct V_152 * V_153 ;
struct V_278 * V_188 = F_205 ( V_327 ) ;
struct V_288 * V_289 ;
struct V_30 * V_31 ;
int V_26 = 0 ;
V_289 = F_195 ( sizeof( struct V_288 ) , V_314 ) ;
if ( ! V_289 ) {
F_31 ( V_29 -> V_75 . V_10 , L_49 ) ;
return NULL ;
}
if ( ! V_328 )
V_3 = F_206 ( & V_329 , sizeof( * V_28 ) ) ;
else
V_3 = F_207 ( V_188 , sizeof( * V_28 ) ) ;
if ( ! V_3 ) {
F_62 (KERN_ERR PFX L_50 ) ;
goto V_330;
}
V_153 = V_3 -> V_180 ;
V_28 = F_2 ( V_3 ) ;
V_28 -> V_3 = V_3 ;
V_28 -> V_6 = V_29 ;
F_208 ( & V_28 -> V_295 , V_331 ) ;
V_26 = F_142 ( V_3 ) ;
if ( V_26 )
goto V_332;
if ( V_328 ) {
F_62 (KERN_ERR PFX L_51 ,
vport->node_name, vport->port_name) ;
F_120 ( V_3 , V_188 -> V_333 ) ;
F_121 ( V_3 , V_188 -> V_282 ) ;
}
V_26 = F_114 ( V_3 , V_29 -> V_7 ) ;
if ( V_26 ) {
F_62 (KERN_ERR PFX L_52 ) ;
goto V_332;
}
V_26 = F_102 ( V_3 , V_327 ) ;
if ( V_26 ) {
F_62 (KERN_ERR PFX L_53 ,
interface->netdev->name) ;
goto V_332;
}
V_26 = F_135 ( V_3 ) ;
if ( V_26 ) {
F_62 (KERN_ERR PFX L_54 ) ;
goto V_334;
}
F_129 ( V_3 -> V_180 ) = V_246 ;
if ( ! V_328 )
V_26 = F_140 ( V_3 ) ;
else {
V_153 = F_153 ( V_188 ) ;
V_280 = F_97 ( V_153 ) ;
V_26 = F_209 ( V_280 , V_3 ) ;
}
if ( V_26 ) {
F_62 (KERN_ERR PFX L_55 ) ;
goto V_334;
}
F_188 ( V_29 ) ;
V_31 = V_29 -> V_31 ;
F_6 ( & V_31 -> V_37 ) ;
V_289 -> V_3 = V_3 ;
F_210 ( & V_289 -> V_16 , & V_31 -> V_321 ) ;
F_10 ( & V_31 -> V_37 ) ;
return V_3 ;
V_334:
F_211 ( V_153 ) ;
V_332:
F_212 ( V_3 -> V_180 ) ;
V_330:
F_95 ( V_289 ) ;
return NULL ;
}
static void F_213 ( struct V_4 * V_29 )
{
F_214 ( & V_29 -> V_121 ) ;
F_214 ( & V_29 -> V_274 ) ;
F_215 () ;
}
static void F_216 ( struct V_4 * V_29 )
{
struct V_2 * V_3 = V_29 -> V_75 . V_10 ;
struct V_5 * V_28 = F_2 ( V_3 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
F_217 ( & V_28 -> V_223 ) ;
F_130 ( V_3 ) ;
F_213 ( V_29 ) ;
F_164 ( V_31 , V_3 ) ;
}
static void F_218 ( struct V_2 * V_3 )
{
F_5 ( V_3 ) ;
F_219 ( V_3 -> V_180 ) ;
F_211 ( V_3 -> V_180 ) ;
F_220 ( V_3 ) ;
F_221 ( V_3 ) ;
F_212 ( V_3 -> V_180 ) ;
}
static void F_125 ( struct V_4 * V_29 )
{
struct V_2 * V_3 = V_29 -> V_75 . V_10 ;
struct V_5 * V_28 = F_2 ( V_3 ) ;
F_216 ( V_29 ) ;
F_222 ( V_29 ) ;
F_165 ( & V_29 -> V_16 ) ;
F_168 ( V_29 ) ;
F_169 ( V_294 , & V_28 -> V_295 ) ;
}
static int F_223 ( struct V_1 * V_7 )
{
struct V_4 * V_29 = NULL ;
int V_26 = 0 ;
F_156 () ;
F_18 ( & V_242 ) ;
V_29 = F_224 ( V_7 ) ;
if ( ! V_29 || ! V_29 -> V_75 . V_10 ) {
V_26 = - V_58 ;
F_62 (KERN_ERR PFX L_56 ) ;
goto V_335;
}
F_225 ( V_29 -> V_336 ) ;
F_125 ( V_29 ) ;
V_335:
F_21 ( & V_242 ) ;
F_158 () ;
return V_26 ;
}
static void V_331 ( struct V_337 * V_146 )
{
struct V_5 * V_28 ;
struct V_2 * V_3 ;
V_28 = F_61 ( V_146 , struct V_5 , V_295 ) ;
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
goto V_338;
if ( F_231 ( V_31 ) )
goto V_338;
return 0 ;
V_338:
F_226 ( V_31 ) ;
return - V_59 ;
}
static int F_198 ( struct V_30 * V_31 )
{
struct V_312 * V_313 ;
if ( ! V_31 -> V_313 ) {
F_62 (KERN_ERR PFX L_58 ) ;
return - V_58 ;
}
V_313 = V_31 -> V_313 ;
V_31 -> V_339 = V_313 -> V_339 ;
if ( V_31 -> V_339 )
F_232 ( V_31 -> V_339 ) ;
return 0 ;
}
static void F_193 ( struct V_30 * V_31 )
{
if ( V_31 -> V_339 )
F_233 ( V_31 -> V_339 ) ;
V_31 -> V_339 = NULL ;
}
static void F_234 ( void * V_340 )
{
struct V_30 * V_31 = V_340 ;
struct V_4 * V_29 ;
struct V_2 * V_3 ;
F_18 ( & V_242 ) ;
if ( ! F_38 ( V_283 , & V_31 -> V_80 ) )
F_235 ( V_31 ) ;
F_17 ( L_59 ) ;
F_126 (interface, &if_list, list) {
if ( V_29 -> V_31 == V_31 ) {
V_3 = V_29 -> V_75 . V_10 ;
F_62 (KERN_ERR PFX L_60 ) ;
V_3 -> V_252 . V_341 = F_29 ;
F_236 ( V_29 ) ;
}
}
F_21 ( & V_242 ) ;
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
struct V_2 * V_188 ;
if ( ! F_38 ( V_283 , & V_29 -> V_31 -> V_80 ) )
return;
V_3 = V_29 -> V_75 . V_10 ;
F_167 ( V_3 ) ;
F_18 ( & V_3 -> V_245 ) ;
F_126 (vport, &lport->vports, list)
F_129 ( V_188 -> V_180 ) =
V_246 ;
F_21 ( & V_3 -> V_245 ) ;
F_129 ( V_3 -> V_180 ) = V_246 ;
F_128 ( & V_29 -> V_75 ) ;
F_130 ( V_3 ) ;
}
static int F_235 ( struct V_30 * V_31 )
{
#define F_238 (1000 / HZ)
int V_26 = - 1 ;
int V_34 = V_159 ;
V_26 = F_229 ( V_31 ) ;
if ( V_26 ) {
F_62 (KERN_ALERT PFX
L_61 , rc) ;
goto V_342;
}
V_26 = F_239 ( V_31 ) ;
if ( V_26 ) {
F_62 (KERN_ALERT PFX
L_62 , rc) ;
goto V_343;
}
while ( ! F_38 ( V_236 , & V_31 -> V_213 ) && V_34 -- )
F_240 ( F_238 ) ;
if ( ! F_38 ( V_236 , & V_31 -> V_213 ) ) {
F_62 (KERN_ERR PFX L_63
L_64 ,
hba->cnic->netdev->name) ;
V_26 = - 1 ;
goto V_343;
}
F_112 ( V_283 , & V_31 -> V_80 ) ;
return 0 ;
V_343:
F_226 ( V_31 ) ;
V_342:
return V_26 ;
}
static void F_241 ( struct V_30 * V_31 )
{
if ( F_184 ( V_283 , & V_31 -> V_80 ) ) {
if ( F_242 ( V_31 ) == 0 ) {
F_243 ( & V_31 -> V_344 ) ;
V_31 -> V_344 . V_345 = V_346 +
V_287 ;
V_31 -> V_344 . V_347 = F_122 ;
V_31 -> V_344 . V_141 = ( unsigned long ) V_31 ;
F_244 ( & V_31 -> V_344 ) ;
F_132 ( V_31 -> V_228 ,
F_38 ( V_227 ,
& V_31 -> V_80 ) ) ;
F_111 ( V_227 , & V_31 -> V_80 ) ;
if ( F_133 ( V_127 ) )
F_134 ( V_127 ) ;
F_217 ( & V_31 -> V_344 ) ;
}
F_226 ( V_31 ) ;
}
}
static void F_245 ( void * V_340 )
{
struct V_30 * V_31 = V_340 ;
struct V_4 * V_29 ;
F_62 ( V_237 L_65 ) ;
F_18 ( & V_242 ) ;
if ( ! F_38 ( V_283 , & V_31 -> V_80 ) )
goto exit;
F_126 (interface, &if_list, list) {
if ( V_29 -> V_31 == V_31 )
F_222 ( V_29 ) ;
}
F_246 ( V_31 -> V_250 != 0 ) ;
F_18 ( & V_31 -> V_36 ) ;
F_111 ( V_236 , & V_31 -> V_213 ) ;
F_111 ( V_239 ,
& V_31 -> V_213 ) ;
F_111 ( V_248 , & V_31 -> V_213 ) ;
F_21 ( & V_31 -> V_36 ) ;
F_241 ( V_31 ) ;
exit:
F_21 ( & V_242 ) ;
}
static void F_236 ( struct V_4 * V_29 )
{
struct V_2 * V_3 ;
int V_348 = 0 ;
F_17 ( L_1 , V_35 ) ;
if ( ! F_38 ( V_283 , & V_29 -> V_31 -> V_80 ) ) {
F_62 (KERN_ERR PFX L_66 ) ;
return;
}
V_3 = V_29 -> V_75 . V_10 ;
F_31 ( V_3 , L_67 ) ;
if ( ! F_109 ( V_3 ) && V_29 -> V_244 ) {
F_31 ( V_3 , L_68 ) ;
F_127 ( & V_29 -> V_75 ) ;
F_129 ( V_3 -> V_180 ) = V_349 ;
F_112 ( V_248 , & V_29 -> V_31 -> V_213 ) ;
}
while ( ! V_29 -> V_75 . V_76 ) {
F_240 ( 250 ) ;
if ( ++ V_348 > 12 )
break;
}
if ( F_115 ( V_3 , V_221 ) )
return;
F_161 ( V_3 ) ;
F_162 ( V_3 ) ;
}
static void F_247 ( struct V_312 * V_95 )
{
struct V_30 * V_31 ;
int V_26 = 0 ;
F_17 ( L_1 , V_35 ) ;
if ( ! F_38 ( V_350 , & V_95 -> V_80 ) ||
( V_95 -> V_351 == 0 ) ) {
F_62 (KERN_ERR PFX L_69
L_70 ,
dev->netdev->name, dev->flags, dev->max_fcoe_conn) ;
return;
}
V_31 = F_194 ( V_95 ) ;
if ( ! V_31 ) {
F_62 (KERN_ERR PFX L_71 ) ;
return;
}
F_18 ( & V_242 ) ;
F_210 ( & V_31 -> V_16 , & V_352 ) ;
V_353 ++ ;
F_21 ( & V_242 ) ;
F_111 ( V_354 , & V_31 -> V_355 ) ;
V_26 = V_95 -> V_356 ( V_95 , V_357 ,
( void * ) V_31 ) ;
if ( V_26 )
F_62 (KERN_ERR PFX L_72 , rc) ;
else
F_112 ( V_354 , & V_31 -> V_355 ) ;
}
static int F_248 ( struct V_1 * V_7 )
{
struct V_4 * V_29 ;
int V_26 = 0 ;
F_156 () ;
F_18 ( & V_242 ) ;
V_29 = F_224 ( V_7 ) ;
if ( ! V_29 || ! V_29 -> V_75 . V_10 ) {
V_26 = - V_58 ;
F_62 (KERN_ERR PFX L_73 ) ;
} else {
V_29 -> V_244 = false ;
F_128 ( & V_29 -> V_75 ) ;
F_130 ( V_29 -> V_75 . V_10 ) ;
}
F_21 ( & V_242 ) ;
F_158 () ;
return V_26 ;
}
static int F_249 ( struct V_1 * V_7 )
{
struct V_4 * V_29 ;
int V_26 = 0 ;
F_156 () ;
F_18 ( & V_242 ) ;
V_29 = F_224 ( V_7 ) ;
if ( ! V_29 || ! V_29 -> V_75 . V_10 ) {
V_26 = - V_58 ;
F_62 (KERN_ERR PFX L_74 ) ;
} else if ( ! F_109 ( V_29 -> V_75 . V_10 ) ) {
F_127 ( & V_29 -> V_75 ) ;
V_29 -> V_244 = true ;
}
F_21 ( & V_242 ) ;
F_158 () ;
return V_26 ;
}
static int F_250 ( struct V_1 * V_7 , enum V_322 V_323 )
{
struct V_4 * V_29 ;
struct V_30 * V_31 ;
struct V_1 * V_210 ;
struct V_2 * V_3 ;
struct V_358 V_359 ;
int V_26 = 0 ;
int V_231 ;
F_17 ( L_75 ) ;
if ( V_323 != V_360 ) {
F_62 ( V_237 L_76 ) ;
return - V_284 ;
}
F_156 () ;
F_18 ( & V_242 ) ;
if ( ! F_251 ( V_310 ) ) {
V_26 = - V_77 ;
goto V_361;
}
if ( V_7 -> V_362 & V_363 ) {
V_210 = F_252 ( V_7 ) ;
V_231 = F_253 ( V_7 ) ;
} else {
F_62 (KERN_ERR PFX L_77 ) ;
V_26 = - V_77 ;
goto V_335;
}
if ( V_210 -> V_218 && V_210 -> V_218 -> V_364 ) {
memset ( & V_359 , 0 , sizeof( V_359 ) ) ;
V_210 -> V_218 -> V_364 ( V_210 , & V_359 ) ;
if ( strncmp ( V_359 . V_365 , L_78 , strlen ( L_78 ) ) ) {
F_62 (KERN_ERR PFX L_79 ) ;
V_26 = - V_77 ;
goto V_335;
}
} else {
F_62 (KERN_ERR PFX L_80 ) ;
V_26 = - V_77 ;
goto V_335;
}
V_31 = F_254 ( V_210 ) ;
if ( ! V_31 ) {
V_26 = - V_58 ;
F_62 (KERN_ERR PFX L_81 ) ;
goto V_335;
}
if ( F_224 ( V_7 ) ) {
V_26 = - V_366 ;
goto V_335;
}
V_29 = F_201 ( V_31 , V_7 , V_323 ) ;
if ( ! V_29 ) {
F_62 (KERN_ERR PFX L_82 ) ;
goto V_367;
}
V_29 -> V_231 = V_231 ;
V_29 -> V_368 = 1 ;
V_29 -> V_336 =
F_255 ( L_83 ) ;
if ( ! V_29 -> V_336 ) {
F_62 (KERN_ERR PFX L_84 ) ;
V_26 = - V_77 ;
goto V_367;
}
V_3 = F_157 ( V_29 , & V_29 -> V_31 -> V_339 -> V_95 , 0 ) ;
if ( ! V_3 ) {
F_62 (KERN_ERR PFX L_85 ,
netdev->name) ;
V_26 = - V_77 ;
goto V_369;
}
F_210 ( & V_29 -> V_16 , & V_370 ) ;
V_3 -> V_286 = V_287 ;
V_29 -> V_75 . V_10 = V_3 ;
if ( ! F_109 ( V_3 ) ) {
F_127 ( & V_29 -> V_75 ) ;
F_129 ( V_3 -> V_180 ) = V_349 ;
F_112 ( V_248 , & V_29 -> V_31 -> V_213 ) ;
}
F_31 ( V_3 , L_86 ) ;
F_236 ( V_29 ) ;
V_29 -> V_244 = true ;
F_168 ( V_29 ) ;
F_21 ( & V_242 ) ;
F_158 () ;
return 0 ;
V_369:
F_225 ( V_29 -> V_336 ) ;
V_367:
F_213 ( V_29 ) ;
F_168 ( V_29 ) ;
V_335:
F_187 ( V_310 ) ;
V_361:
F_21 ( & V_242 ) ;
F_158 () ;
return V_26 ;
}
static struct V_30 * F_256 ( struct V_312 * V_313 )
{
struct V_371 * V_16 ;
struct V_371 * V_372 ;
struct V_30 * V_31 ;
F_257 (list, temp, &adapter_list) {
V_31 = (struct V_30 * ) V_16 ;
if ( V_31 -> V_313 == V_313 )
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
* V_210 )
{
struct V_30 * V_31 ;
F_126 (hba, &adapter_list, list) {
if ( V_31 -> V_210 == V_210 )
return V_31 ;
}
F_62 (KERN_ERR PFX L_87 ) ;
return NULL ;
}
static void F_258 ( struct V_312 * V_95 )
{
struct V_30 * V_31 ;
struct V_4 * V_29 , * V_147 ;
F_17 ( L_88 ) ;
if ( ! F_38 ( V_350 , & V_95 -> V_80 ) ) {
F_62 (KERN_ERR PFX L_89 ,
dev->netdev->name, dev->flags) ;
return;
}
F_18 ( & V_242 ) ;
V_31 = F_256 ( V_95 ) ;
if ( ! V_31 ) {
F_62 (KERN_ERR PFX L_90 ,
dev) ;
F_21 ( & V_242 ) ;
return;
}
F_93 ( & V_31 -> V_16 ) ;
V_353 -- ;
F_92 (interface, tmp, &if_list, list)
if ( V_29 -> V_31 == V_31 )
F_125 ( V_29 ) ;
F_21 ( & V_242 ) ;
F_245 ( V_31 ) ;
if ( F_184 ( V_354 , & V_31 -> V_355 ) )
V_31 -> V_313 -> V_373 ( V_31 -> V_313 , V_357 ) ;
F_191 ( V_31 ) ;
}
static int F_259 ( struct V_152 * V_153 )
{
struct V_2 * V_3 = F_97 ( V_153 ) ;
F_260 ( V_3 ) ;
return 0 ;
}
static bool F_261 ( struct V_1 * V_7 )
{
F_18 ( & V_242 ) ;
if ( V_7 -> V_362 & V_363 ) {
struct V_1 * V_210 = F_252 ( V_7 ) ;
if ( F_254 ( V_210 ) ) {
F_21 ( & V_242 ) ;
return true ;
}
}
F_21 ( & V_242 ) ;
return false ;
}
static void F_262 ( unsigned int V_374 )
{
struct V_143 * V_144 ;
struct V_375 * V_125 ;
V_144 = & F_263 ( V_376 , V_374 ) ;
V_125 = F_264 ( F_88 ,
( void * ) V_144 ,
L_91 , V_374 ) ;
if ( F_265 ( ! F_159 ( V_125 ) ) ) {
F_266 ( V_125 , V_374 ) ;
V_144 -> V_377 = V_125 ;
F_67 ( V_125 ) ;
}
}
static void F_267 ( unsigned int V_374 )
{
struct V_143 * V_144 ;
struct V_375 * V_125 ;
struct V_145 * V_146 , * V_147 ;
F_17 ( L_92 , V_374 ) ;
V_144 = & F_263 ( V_376 , V_374 ) ;
F_6 ( & V_144 -> V_149 ) ;
V_125 = V_144 -> V_377 ;
V_144 -> V_377 = NULL ;
F_92 (work, tmp, &p->work_list, list) {
F_93 ( & V_146 -> V_16 ) ;
F_94 ( V_146 -> V_33 , V_146 -> V_150 ) ;
F_95 ( V_146 ) ;
}
F_10 ( & V_144 -> V_149 ) ;
if ( V_125 )
F_268 ( V_125 ) ;
}
static int F_269 ( struct V_378 * V_379 ,
unsigned long V_380 , void * V_381 )
{
unsigned V_374 = ( unsigned long ) V_381 ;
switch ( V_380 ) {
case V_382 :
case V_383 :
F_62 ( V_384 L_93 , V_374 ) ;
F_262 ( V_374 ) ;
break;
case V_385 :
case V_386 :
F_62 ( V_384 L_94 , V_374 ) ;
F_267 ( V_374 ) ;
break;
default:
break;
}
return V_387 ;
}
static int T_6 F_270 ( void )
{
struct V_11 * V_12 ;
struct V_375 * V_388 ;
int V_26 = 0 ;
unsigned int V_374 = 0 ;
struct V_143 * V_144 ;
F_62 (KERN_INFO PFX L_95 , version) ;
V_26 = F_271 ( & V_389 ) ;
if ( V_26 ) {
F_62 ( V_237 L_96
L_97 ) ;
goto V_390;
}
F_200 ( & V_352 ) ;
F_200 ( & V_370 ) ;
F_197 ( & V_242 ) ;
V_353 = 0 ;
V_26 = F_179 () ;
if ( V_26 )
goto V_391;
V_294 = F_272 ( L_98 , 0 , 0 ) ;
if ( ! V_294 ) {
V_26 = - V_59 ;
goto V_392;
}
V_12 = & V_21 ;
F_116 ( & V_12 -> V_22 ) ;
V_388 = F_264 ( F_68 ,
( void * ) V_12 ,
L_99 ) ;
if ( F_159 ( V_388 ) ) {
V_26 = F_273 ( V_388 ) ;
goto V_393;
}
F_67 ( V_388 ) ;
F_6 ( & V_12 -> V_22 . V_23 ) ;
V_12 -> V_125 = V_388 ;
F_10 ( & V_12 -> V_22 . V_23 ) ;
F_274 (cpu) {
V_144 = & F_263 ( V_376 , V_374 ) ;
F_200 ( & V_144 -> V_148 ) ;
F_196 ( & V_144 -> V_149 ) ;
}
F_275 (cpu) {
F_262 ( V_374 ) ;
}
F_276 ( & V_394 ) ;
F_277 ( V_357 , & V_395 ) ;
return 0 ;
V_393:
F_225 ( V_294 ) ;
V_392:
F_182 () ;
V_391:
F_278 ( & V_389 ) ;
V_390:
return V_26 ;
}
static void T_7 F_279 ( void )
{
F_89 ( V_396 ) ;
struct V_30 * V_31 , * V_19 ;
struct V_11 * V_12 ;
struct V_375 * V_388 ;
struct V_17 * V_18 ;
unsigned int V_374 = 0 ;
F_18 ( & V_242 ) ;
F_280 ( & V_352 , & V_396 ) ;
F_200 ( & V_352 ) ;
V_353 = 0 ;
F_21 ( & V_242 ) ;
F_92 (hba, next, &to_be_deleted, list) {
F_93 ( & V_31 -> V_16 ) ;
F_62 (KERN_ERR PFX L_100 ,
hba) ;
F_245 ( V_31 ) ;
if ( F_184 ( V_354 ,
& V_31 -> V_355 ) )
V_31 -> V_313 -> V_373 ( V_31 -> V_313 ,
V_357 ) ;
F_191 ( V_31 ) ;
}
F_281 ( V_357 ) ;
V_12 = & V_21 ;
F_6 ( & V_12 -> V_22 . V_23 ) ;
V_388 = V_12 -> V_125 ;
V_12 -> V_125 = NULL ;
while ( ( V_18 = F_73 ( & V_12 -> V_22 ) ) != NULL )
F_9 ( V_18 ) ;
F_10 ( & V_12 -> V_22 . V_23 ) ;
if ( V_388 )
F_268 ( V_388 ) ;
F_282 ( & V_394 ) ;
F_275 (cpu) {
F_267 ( V_374 ) ;
}
F_225 ( V_294 ) ;
F_182 () ;
F_278 ( & V_389 ) ;
}
