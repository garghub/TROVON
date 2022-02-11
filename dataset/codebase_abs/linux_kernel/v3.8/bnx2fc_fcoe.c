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
static void F_5 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_6 ( V_11 ) ;
struct V_1 * V_7 = F_1 ( V_13 -> V_14 ) ;
struct V_15 * V_16 ;
struct V_8 V_9 ;
F_4 ( V_13 -> V_14 , & V_9 , V_7 ) ;
V_16 = (struct V_15 * ) ( & V_9 ) ;
V_11 -> V_17 . V_18 =
F_7 ( V_16 -> V_18 ) ;
V_11 -> V_17 . V_19 =
F_7 ( V_16 -> V_19 ) ;
V_11 -> V_17 . V_20 =
F_7 ( V_16 -> V_20 ) ;
V_11 -> V_17 . V_21 =
F_7 ( V_16 -> V_21 ) ;
V_11 -> V_17 . V_22 =
F_7 ( V_16 -> V_22 ) ;
V_11 -> V_17 . V_23 =
F_7 ( V_16 -> V_23 ) ;
}
static void F_8 ( struct V_24 * V_25 )
{
struct V_10 * V_11 =
F_9 ( V_25 ) ;
struct V_12 * V_26 = F_6 ( V_11 ) ;
struct V_4 * V_27 = F_10 ( V_26 ) ;
V_25 -> V_28 = V_27 -> V_28 ;
}
static void F_11 ( struct V_2 * V_14 )
{
struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_35 * V_36 , * V_37 ;
struct V_35 * V_38 ;
V_30 = & V_39 ;
F_12 ( & V_30 -> V_40 . V_41 ) ;
V_34 = & V_30 -> V_40 ;
V_38 = V_34 -> V_37 ;
for ( V_36 = V_38 ; V_36 != (struct V_35 * ) V_34 ;
V_36 = V_37 ) {
V_37 = V_36 -> V_37 ;
V_32 = F_13 ( V_36 ) ;
if ( V_32 -> V_42 == V_14 ) {
F_14 ( V_36 , V_34 ) ;
F_15 ( V_36 ) ;
}
}
F_16 ( & V_30 -> V_40 . V_41 ) ;
}
int F_17 ( struct V_35 * V_36 , int V_43 )
{
int V_44 ;
F_18 ( & V_45 ) ;
V_44 = F_19 ( V_36 , V_43 , & V_39 ) ;
F_20 ( & V_45 ) ;
return V_44 ;
}
static void F_21 ( struct V_2 * V_3 )
{
}
static void F_22 ( struct V_2 * V_3 )
{
struct V_5 * V_46 = F_2 ( V_3 ) ;
struct V_4 * V_47 = V_46 -> V_6 ;
struct V_48 * V_49 = V_47 -> V_49 ;
struct V_50 * V_51 ;
int V_52 ;
F_23 ( L_1 , V_53 ) ;
F_24 ( & V_49 -> V_54 ) ;
F_12 ( & V_49 -> V_55 ) ;
for ( V_52 = 0 ; V_52 < V_56 ; V_52 ++ ) {
V_51 = V_49 -> V_57 [ V_52 ] ;
if ( V_51 ) {
if ( V_51 -> V_46 == V_46 ) {
F_16 ( & V_49 -> V_55 ) ;
F_25 ( V_51 , L_2 ) ;
F_26 ( V_51 ) ;
F_12 ( & V_49 -> V_55 ) ;
}
}
}
F_16 ( & V_49 -> V_55 ) ;
F_27 ( & V_49 -> V_54 ) ;
}
static int F_28 ( struct V_50 * V_51 ,
struct V_58 * V_59 )
{
struct V_60 * V_61 = V_51 -> V_61 ;
struct V_62 * V_63 ;
int V_44 = 0 ;
V_63 = F_29 ( V_59 ) ;
F_25 ( V_51 , L_3
L_4 , V_61 -> V_64 . V_65 ,
F_30 ( V_63 -> V_66 ) , V_63 -> V_67 ) ;
if ( ( V_63 -> V_68 == V_69 ) &&
( V_63 -> V_67 == V_70 ) ) {
switch ( F_31 ( V_59 ) ) {
case V_71 :
V_44 = F_32 ( V_51 , V_59 ) ;
break;
case V_72 :
V_44 = F_33 ( V_51 , V_59 ) ;
break;
case V_73 :
V_44 = F_34 ( V_51 , V_59 ) ;
break;
default:
break;
}
} else if ( ( V_63 -> V_68 == V_74 ) &&
( V_63 -> V_67 == V_75 ) )
F_25 ( V_51 , L_5 ) ;
else {
F_25 ( V_51 , L_6
L_7 ,
V_63 -> V_68 , V_63 -> V_67 ) ;
return - V_76 ;
}
if ( V_44 )
return - V_77 ;
else
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , struct V_58 * V_59 )
{
struct V_78 * V_79 ;
struct V_80 * V_81 ;
struct V_35 * V_36 ;
struct V_62 * V_63 ;
struct V_4 * V_47 ;
struct V_12 * V_26 ;
struct V_48 * V_49 ;
struct V_5 * V_46 ;
struct V_82 * V_83 ;
struct V_50 * V_51 ;
struct V_84 * V_85 ;
T_1 V_86 , V_87 ;
T_2 V_88 ;
unsigned int V_89 , V_43 , V_90 ;
int V_91 , V_44 = 0 ;
V_46 = (struct V_5 * ) F_2 ( V_3 ) ;
V_47 = V_46 -> V_6 ;
V_26 = F_36 ( V_47 ) ;
V_49 = V_47 -> V_49 ;
V_63 = F_29 ( V_59 ) ;
V_36 = F_37 ( V_59 ) ;
if ( ! V_3 -> V_92 ) {
F_38 ( V_3 , L_8 ) ;
F_15 ( V_36 ) ;
return 0 ;
}
if ( F_39 ( V_63 -> V_67 == V_70 ) ) {
if ( ! V_26 -> V_93 ) {
F_38 ( V_3 , L_9 ) ;
F_15 ( V_36 ) ;
return - V_94 ;
}
if ( F_40 ( V_26 , V_3 , V_36 ) )
return 0 ;
}
V_86 = F_41 ( V_59 ) ;
V_87 = F_42 ( V_59 ) ;
F_12 ( & V_49 -> V_55 ) ;
V_51 = F_43 ( V_46 , F_44 ( V_63 -> V_95 ) ) ;
if ( V_51 && ( F_45 ( V_96 , & V_51 -> V_97 ) ) ) {
F_38 ( V_3 , L_10
L_11 , F_44 ( V_63 -> V_95 ) ) ;
F_16 ( & V_49 -> V_55 ) ;
V_44 = F_28 ( V_51 , V_59 ) ;
if ( V_44 != - V_76 ) {
F_15 ( V_36 ) ;
return V_44 ;
}
} else {
F_16 ( & V_49 -> V_55 ) ;
}
V_90 = sizeof( struct V_78 ) ;
V_89 = sizeof( struct V_82 ) ;
V_43 = sizeof( struct V_80 ) ;
V_91 = ( V_36 -> V_98 - V_43 + sizeof( V_88 ) ) / V_99 ;
V_36 -> V_100 = V_101 ;
V_88 = F_46 ( V_59 ) ;
if ( F_47 ( V_36 ) ) {
T_3 * V_102 ;
if ( F_17 ( V_36 , V_43 ) ) {
F_15 ( V_36 ) ;
return - V_77 ;
}
V_102 = & F_48 ( V_36 ) -> V_103 [ F_48 ( V_36 ) -> V_104 - 1 ] ;
V_81 = F_49 ( F_50 ( V_102 ) ) + V_102 -> V_105 ;
} else {
V_81 = (struct V_80 * ) F_51 ( V_36 , V_43 ) ;
}
memset ( V_81 , 0 , sizeof( * V_81 ) ) ;
V_81 -> V_106 = V_87 ;
V_81 -> V_107 = F_52 ( ~ V_88 ) ;
if ( F_47 ( V_36 ) ) {
F_53 ( V_81 ) ;
V_81 = NULL ;
}
F_54 ( V_36 , V_90 + V_89 ) ;
F_55 ( V_36 ) ;
F_56 ( V_36 ) ;
V_36 -> V_108 = V_90 ;
V_36 -> V_109 = F_57 ( V_110 ) ;
V_36 -> V_111 = V_47 -> V_7 ;
V_79 = F_58 ( V_36 ) ;
V_79 -> V_112 = F_57 ( V_110 ) ;
if ( V_26 -> V_113 )
F_59 ( V_79 -> V_114 , V_63 -> V_95 ) ;
else
memcpy ( V_79 -> V_114 , V_26 -> V_115 , V_116 ) ;
if ( F_39 ( V_26 -> V_117 != V_118 ) )
memcpy ( V_79 -> V_119 , V_26 -> V_120 , V_116 ) ;
else
memcpy ( V_79 -> V_119 , V_46 -> V_121 , V_116 ) ;
V_83 = (struct V_82 * ) ( V_79 + 1 ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
if ( V_122 )
F_60 ( V_83 , V_122 ) ;
V_83 -> V_123 = V_86 ;
if ( V_3 -> V_124 && F_61 ( V_59 ) ) {
F_48 ( V_36 ) -> V_125 = V_126 ;
F_48 ( V_36 ) -> V_127 = F_61 ( V_59 ) ;
} else {
F_48 ( V_36 ) -> V_125 = 0 ;
F_48 ( V_36 ) -> V_127 = 0 ;
}
V_85 = F_62 ( V_3 -> V_85 , F_63 () ) ;
V_85 -> V_128 ++ ;
V_85 -> V_129 += V_91 ;
F_64 () ;
V_42 ( V_59 ) = V_3 ;
if ( V_46 -> V_130 . V_131 )
F_65 ( V_3 , V_36 ) ;
else if ( F_66 ( V_36 ) )
F_65 ( V_3 , V_36 ) ;
return 0 ;
}
static int F_67 ( struct V_35 * V_36 , struct V_1 * V_111 ,
struct V_132 * V_133 , struct V_1 * V_134 )
{
struct V_2 * V_3 ;
struct V_4 * V_47 ;
struct V_12 * V_26 ;
struct V_62 * V_63 ;
struct V_31 * V_32 ;
struct V_29 * V_30 ;
unsigned short V_135 ;
V_47 = F_68 ( V_133 , struct V_4 ,
V_136 ) ;
V_26 = F_36 ( V_47 ) ;
V_3 = V_26 -> V_14 ;
if ( F_39 ( V_3 == NULL ) ) {
F_69 (KERN_ERR PFX L_12 ) ;
goto V_137;
}
if ( F_39 ( F_58 ( V_36 ) -> V_112 != F_57 ( V_110 ) ) ) {
F_69 (KERN_ERR PFX L_13 ) ;
goto V_137;
}
if ( F_39 ( ( V_36 -> V_98 < V_138 ) ||
! F_70 ( V_36 , V_139 ) ) )
goto V_137;
F_71 ( V_36 , sizeof( struct V_82 ) ) ;
V_63 = (struct V_62 * ) F_72 ( V_36 ) ;
V_135 = F_30 ( V_63 -> V_66 ) ;
V_32 = F_13 ( V_36 ) ;
V_32 -> V_42 = V_3 ;
V_30 = & V_39 ;
F_18 ( & V_30 -> V_40 . V_41 ) ;
F_73 ( & V_30 -> V_40 , V_36 ) ;
if ( V_30 -> V_40 . V_131 == 1 )
F_74 ( V_30 -> V_140 ) ;
F_20 ( & V_30 -> V_40 . V_41 ) ;
return 0 ;
V_137:
F_15 ( V_36 ) ;
return - 1 ;
}
static int F_75 ( void * V_141 )
{
struct V_29 * V_30 = V_141 ;
struct V_35 * V_36 ;
F_76 ( V_142 , - 20 ) ;
F_77 ( V_143 ) ;
while ( ! F_78 () ) {
F_79 () ;
F_12 ( & V_30 -> V_40 . V_41 ) ;
while ( ( V_36 = F_80 ( & V_30 -> V_40 ) ) != NULL ) {
F_16 ( & V_30 -> V_40 . V_41 ) ;
F_81 ( V_36 ) ;
F_12 ( & V_30 -> V_40 . V_41 ) ;
}
F_82 ( V_143 ) ;
F_16 ( & V_30 -> V_40 . V_41 ) ;
}
F_82 ( V_144 ) ;
return 0 ;
}
static void F_81 ( struct V_35 * V_36 )
{
T_2 V_145 ;
struct V_2 * V_3 ;
struct V_31 * V_32 ;
struct V_84 * V_85 ;
struct V_62 * V_63 ;
struct V_80 V_146 ;
struct V_58 * V_59 ;
struct V_2 * V_147 ;
struct V_5 * V_46 ;
T_1 * V_148 = NULL ;
T_1 * V_149 = NULL ;
struct V_82 * V_83 ;
V_32 = F_13 ( V_36 ) ;
V_3 = V_32 -> V_42 ;
if ( F_39 ( V_3 == NULL ) ) {
F_69 (KERN_ERR PFX L_14 ) ;
F_15 ( V_36 ) ;
return;
}
if ( F_47 ( V_36 ) )
F_83 ( V_36 ) ;
V_148 = F_58 ( V_36 ) -> V_119 ;
V_149 = F_58 ( V_36 ) -> V_114 ;
V_83 = (struct V_82 * ) F_84 ( V_36 ) ;
V_63 = (struct V_62 * ) F_72 ( V_36 ) ;
F_85 ( V_36 , sizeof( struct V_82 ) ) ;
V_145 = V_36 -> V_98 - sizeof( struct V_80 ) ;
V_85 = F_62 ( V_3 -> V_85 , F_63 () ) ;
V_85 -> V_150 ++ ;
V_85 -> V_151 += V_145 / V_99 ;
V_59 = (struct V_58 * ) V_36 ;
F_86 ( V_59 ) ;
V_42 ( V_59 ) = V_3 ;
F_41 ( V_59 ) = V_83 -> V_123 ;
if ( F_87 ( V_36 , V_145 , & V_146 , sizeof( V_146 ) ) ) {
F_64 () ;
F_15 ( V_36 ) ;
return;
}
F_42 ( V_59 ) = V_146 . V_106 ;
F_88 ( V_59 ) = V_146 . V_107 ;
if ( F_89 ( V_36 , V_145 ) ) {
F_64 () ;
F_15 ( V_36 ) ;
return;
}
V_63 = F_29 ( V_59 ) ;
V_147 = F_90 ( V_3 , F_44 ( V_63 -> V_95 ) ) ;
if ( V_147 ) {
V_46 = F_2 ( V_147 ) ;
if ( F_91 ( V_46 -> V_121 , V_149 )
!= 0 ) {
F_38 ( V_3 , L_15 ) ;
F_64 () ;
F_15 ( V_36 ) ;
return;
}
}
if ( V_63 -> V_67 == V_152 &&
V_63 -> V_68 == V_153 ) {
F_64 () ;
F_15 ( V_36 ) ;
return;
}
if ( V_63 -> V_67 == V_70 &&
V_63 -> V_68 == V_69 ) {
switch ( F_31 ( V_59 ) ) {
case V_72 :
if ( F_44 ( V_63 -> V_154 ) == V_155 ) {
F_64 () ;
F_15 ( V_36 ) ;
return;
}
break;
}
}
if ( V_63 -> V_67 == V_75 ) {
F_64 () ;
F_15 ( V_36 ) ;
return;
}
if ( F_92 ( F_88 ( V_59 ) ) !=
~ F_93 ( ~ 0 , V_36 -> V_156 , V_145 ) ) {
if ( V_85 -> V_157 < 5 )
F_69 (KERN_WARNING PFX L_16
L_17 ) ;
V_85 -> V_157 ++ ;
F_64 () ;
F_15 ( V_36 ) ;
return;
}
F_64 () ;
F_94 ( V_3 , V_59 ) ;
}
int F_95 ( void * V_141 )
{
struct V_158 * V_159 = V_141 ;
struct V_160 * V_161 , * V_162 ;
F_96 ( V_163 ) ;
F_76 ( V_142 , - 20 ) ;
F_77 ( V_143 ) ;
while ( ! F_78 () ) {
F_79 () ;
F_12 ( & V_159 -> V_164 ) ;
while ( ! F_97 ( & V_159 -> V_163 ) ) {
F_98 ( & V_159 -> V_163 , & V_163 ) ;
F_16 ( & V_159 -> V_164 ) ;
F_99 (work, tmp, &work_list, list) {
F_100 ( & V_161 -> V_34 ) ;
F_101 ( V_161 -> V_51 , V_161 -> V_165 ) ;
F_102 ( V_161 ) ;
}
F_12 ( & V_159 -> V_164 ) ;
}
F_82 ( V_143 ) ;
F_16 ( & V_159 -> V_164 ) ;
}
F_82 ( V_144 ) ;
return 0 ;
}
static struct V_166 * F_103 ( struct V_167 * V_168 )
{
struct V_166 * V_169 ;
struct V_2 * V_3 = F_104 ( V_168 ) ;
struct V_5 * V_46 = F_2 ( V_3 ) ;
struct V_4 * V_47 = V_46 -> V_6 ;
struct V_48 * V_49 = V_47 -> V_49 ;
struct V_170 * V_171 ;
int V_44 = 0 ;
V_171 = (struct V_170 * ) V_49 -> V_172 ;
if ( ! V_171 )
return NULL ;
V_169 = F_105 ( V_168 ) ;
F_106 ( & V_49 -> V_173 ) ;
if ( F_107 ( V_49 ) )
return V_169 ;
V_44 = F_108 ( & V_49 -> V_173 , ( 2 * V_174 ) ) ;
if ( ! V_44 ) {
F_38 ( V_3 , L_18 ) ;
return V_169 ;
}
V_169 -> V_175 += V_171 -> V_176 . V_177 ;
V_169 -> V_178 += V_171 -> V_179 . V_180 ;
V_169 -> V_181 += ( V_171 -> V_179 . V_182 ) / 4 ;
V_169 -> V_183 += V_171 -> V_184 . V_185 ;
V_169 -> V_186 += ( V_171 -> V_184 . V_187 ) / 4 ;
V_169 -> V_188 = 0 ;
V_169 -> V_189 = 0 ;
V_169 -> V_190 = 0 ;
V_169 -> V_191 = 0 ;
V_169 -> V_192 = 0 ;
V_169 -> V_193 = 0 ;
return V_169 ;
}
static int F_109 ( struct V_2 * V_3 , struct V_194 * V_111 )
{
struct V_5 * V_46 = F_2 ( V_3 ) ;
struct V_4 * V_47 = V_46 -> V_6 ;
struct V_167 * V_168 = V_3 -> V_195 ;
int V_44 = 0 ;
V_168 -> V_196 = V_197 ;
V_168 -> V_198 = V_199 ;
V_168 -> V_200 = V_201 ;
V_168 -> V_202 = 0 ;
if ( V_3 -> V_203 )
V_168 -> V_204 = V_205 ;
else
V_168 -> V_204 = V_206 ;
V_44 = F_110 ( V_3 -> V_195 , V_111 ) ;
if ( V_44 ) {
F_69 (KERN_ERR PFX L_19 ) ;
return V_44 ;
}
if ( ! V_3 -> V_203 )
F_111 ( V_3 -> V_195 ) = V_207 ;
sprintf ( F_112 ( V_3 -> V_195 ) , L_20 ,
V_208 , V_209 ,
V_47 -> V_7 -> V_210 ) ;
return 0 ;
}
static void F_113 ( struct V_2 * V_3 )
{
struct V_5 * V_46 = F_2 ( V_3 ) ;
struct V_4 * V_47 = V_46 -> V_6 ;
struct V_1 * V_7 = V_47 -> V_7 ;
struct V_211 V_212 ;
if ( ! F_114 ( V_7 , & V_212 ) ) {
V_3 -> V_213 &=
~ ( V_214 | V_215 ) ;
if ( V_212 . V_216 & ( V_217 |
V_218 ) )
V_3 -> V_213 |= V_214 ;
if ( V_212 . V_216 & V_219 )
V_3 -> V_213 |= V_215 ;
switch ( F_115 ( & V_212 ) ) {
case V_220 :
V_3 -> V_221 = V_214 ;
break;
case V_222 :
V_3 -> V_221 = V_223 ;
break;
case V_224 :
V_3 -> V_221 = V_215 ;
break;
}
}
}
static int F_116 ( struct V_2 * V_3 )
{
struct V_5 * V_46 = F_2 ( V_3 ) ;
struct V_4 * V_47 = V_46 -> V_6 ;
struct V_48 * V_49 = V_47 -> V_49 ;
struct V_1 * V_111 = V_49 -> V_225 ;
int V_44 = 0 ;
if ( ( V_111 -> V_97 & V_226 ) && F_117 ( V_111 ) )
F_118 ( V_227 , & V_49 -> V_228 ) ;
else {
F_119 ( V_227 , & V_49 -> V_228 ) ;
V_44 = - 1 ;
}
return V_44 ;
}
void F_120 ( struct V_48 * V_49 )
{
if ( F_45 ( V_229 , & V_49 -> V_225 -> V_230 ) )
F_119 ( V_227 , & V_49 -> V_228 ) ;
else
F_118 ( V_227 , & V_49 -> V_228 ) ;
}
static int F_121 ( struct V_2 * V_3 , struct V_1 * V_7 )
{
struct V_48 * V_49 ;
struct V_4 * V_47 ;
struct V_12 * V_26 ;
struct V_5 * V_46 ;
T_4 V_231 , V_232 ;
V_46 = F_2 ( V_3 ) ;
V_47 = V_46 -> V_6 ;
V_26 = F_36 ( V_47 ) ;
V_49 = V_47 -> V_49 ;
if ( ! V_49 -> V_225 -> V_233 ||
! V_49 -> V_225 -> V_233 -> V_234 )
return - V_235 ;
if ( F_122 ( V_3 , V_236 ) )
return - V_94 ;
F_123 ( & V_46 -> V_130 ) ;
V_46 -> V_237 = 0 ;
F_124 ( & V_46 -> V_238 , V_239 , ( unsigned long ) V_3 ) ;
F_113 ( V_3 ) ;
if ( ! V_3 -> V_203 ) {
if ( F_125 ( V_7 , & V_231 , V_240 ) )
V_231 = F_126 ( V_26 -> V_120 ,
1 , 0 ) ;
F_38 ( V_3 , L_21 , V_231 ) ;
F_127 ( V_3 , V_231 ) ;
if ( F_125 ( V_7 , & V_232 , V_241 ) )
V_232 = F_126 ( V_26 -> V_120 ,
2 , 0 ) ;
F_38 ( V_3 , L_22 , V_232 ) ;
F_128 ( V_3 , V_232 ) ;
}
return 0 ;
}
static void F_129 ( unsigned long V_156 )
{
struct V_48 * V_49 = (struct V_48 * ) V_156 ;
F_69 (KERN_ERR PFX L_23
L_24 ) ;
F_119 ( V_242 , & V_49 -> V_97 ) ;
F_130 ( & V_49 -> V_243 ) ;
}
static void F_131 ( void * V_244 , unsigned long V_245 ,
T_5 V_28 )
{
struct V_48 * V_49 = (struct V_48 * ) V_244 ;
struct V_2 * V_3 ;
struct V_2 * V_203 ;
struct V_4 * V_47 , * V_162 ;
struct V_12 * V_26 ;
int V_246 = 0 ;
T_2 V_247 = 1 ;
if ( V_28 != 0 && V_245 != V_248 )
return;
switch ( V_245 ) {
case V_249 :
if ( ! F_45 ( V_250 , & V_49 -> V_228 ) )
F_69 ( V_251 L_25\
L_26 ) ;
break;
case V_252 :
F_118 ( V_253 , & V_49 -> V_228 ) ;
F_118 ( V_250 , & V_49 -> V_228 ) ;
V_247 = 0 ;
break;
case V_254 :
F_119 ( V_253 , & V_49 -> V_228 ) ;
V_247 = 0 ;
break;
case V_255 :
break;
case V_248 :
if ( ! V_28 )
return;
F_24 ( & V_256 ) ;
F_99 (interface, tmp, &if_list, list) {
if ( V_47 -> V_49 == V_49 &&
V_47 -> V_28 == ( V_28 & V_257 ) )
F_132 ( V_47 ) ;
}
F_27 ( & V_256 ) ;
return;
default:
F_69 (KERN_ERR PFX L_27 , event) ;
return;
}
F_24 ( & V_256 ) ;
F_133 (interface, &if_list, list) {
if ( V_47 -> V_49 != V_49 )
continue;
V_26 = F_36 ( V_47 ) ;
V_3 = V_26 -> V_14 ;
F_38 ( V_3 , L_28 ,
V_47 -> V_7 -> V_210 , V_245 ) ;
F_113 ( V_3 ) ;
if ( V_247 && ! F_116 ( V_3 ) ) {
F_122 ( V_3 , V_236 ) ;
if ( V_47 -> V_258 )
F_134 ( V_26 ) ;
} else if ( F_135 ( V_26 ) ) {
F_24 ( & V_3 -> V_259 ) ;
F_133 (vport, &lport->vports, list)
F_136 ( V_203 -> V_195 ) =
V_260 ;
F_27 ( & V_3 -> V_259 ) ;
F_136 ( V_3 -> V_195 ) = V_260 ;
F_62 ( V_3 -> V_85 ,
F_63 () ) -> V_261 ++ ;
F_64 () ;
F_137 ( V_3 ) ;
V_246 = 1 ;
}
}
F_27 ( & V_256 ) ;
if ( V_246 ) {
F_118 ( V_262 , & V_49 -> V_228 ) ;
F_138 ( & V_49 -> V_263 ) ;
F_23 ( L_29
L_30 ,
V_49 -> V_264 ) ;
V_49 -> V_265 = 1 ;
F_139 ( V_49 -> V_263 ,
( V_49 -> V_264 == 0 ) ) ;
F_23 ( L_31 ,
V_49 -> V_264 ) ;
V_49 -> V_265 = 0 ;
if ( F_140 ( V_142 ) )
F_141 ( V_142 ) ;
}
}
static int F_142 ( struct V_2 * V_3 )
{
memcpy ( & V_3 -> V_266 , & V_267 ,
sizeof( struct V_268 ) ) ;
F_143 ( V_3 ) ;
F_144 ( V_3 ) ;
F_145 ( V_3 ) ;
F_146 ( V_3 ) ;
return 0 ;
}
static int F_147 ( struct V_2 * V_3 )
{
int V_269 ;
if ( V_270 <= 2 )
V_269 = V_271 ;
else
V_269 = V_272 ;
if ( ! F_148 ( V_3 , V_273 , V_274 ,
V_269 , NULL ) ) {
F_69 (KERN_ERR PFX L_32 ) ;
return - V_77 ;
}
return 0 ;
}
static int F_149 ( struct V_2 * V_3 )
{
V_3 -> V_92 = 0 ;
V_3 -> V_275 = 0 ;
V_3 -> V_276 = V_277 ;
V_3 -> V_278 = V_279 ;
V_3 -> V_280 = 2 * 1000 ;
V_3 -> V_281 = 10 * 1000 ;
V_3 -> V_282 = ( V_283 | V_284 |
V_285 | V_286 ) ;
V_3 -> V_287 = 1 ;
memset ( & V_3 -> V_288 , 0 , sizeof( struct V_289 ) ) ;
V_3 -> V_288 . V_290 = V_291 ;
if ( F_150 ( V_3 ) )
return - V_77 ;
F_151 ( V_3 ) ;
return 0 ;
}
static int F_152 ( struct V_35 * V_36 , struct V_1 * V_111 ,
struct V_132 * V_133 ,
struct V_1 * V_292 )
{
struct V_4 * V_47 ;
struct V_12 * V_26 ;
V_47 = F_68 ( V_133 , struct V_4 ,
V_293 ) ;
V_26 = F_36 ( V_47 ) ;
F_153 ( V_26 , V_36 ) ;
return 0 ;
}
static void F_154 ( struct V_2 * V_3 , T_1 * V_294 )
{
struct V_5 * V_46 = F_2 ( V_3 ) ;
memcpy ( V_46 -> V_121 , V_294 , V_116 ) ;
}
static T_1 * F_155 ( struct V_2 * V_3 )
{
struct V_5 * V_46 ;
V_46 = (struct V_5 * ) F_2 ( V_3 ) ;
return V_46 -> V_121 ;
}
static void F_156 ( struct V_12 * V_13 , struct V_35 * V_36 )
{
V_36 -> V_111 = F_157 ( V_13 ) -> V_7 ;
F_158 ( V_36 ) ;
}
static int F_159 ( struct V_295 * V_203 , bool V_296 )
{
struct V_167 * V_168 = F_160 ( V_203 ) ;
struct V_2 * V_297 = F_104 ( V_168 ) ;
struct V_5 * V_46 = F_2 ( V_297 ) ;
struct V_4 * V_47 = V_46 -> V_6 ;
struct V_1 * V_7 = V_47 -> V_7 ;
struct V_2 * V_147 ;
int V_44 ;
char V_298 [ 32 ] ;
V_44 = F_161 ( V_203 ) ;
if ( V_44 ) {
F_162 ( V_203 -> V_299 , V_298 , sizeof( V_298 ) ) ;
F_69 (KERN_ERR PFX L_33
L_34 ,
buf) ;
return V_44 ;
}
if ( ! F_45 ( V_300 , & V_47 -> V_49 -> V_97 ) ) {
F_69 (KERN_ERR PFX L_35
L_36 ) ;
return - V_301 ;
}
F_163 () ;
F_24 ( & V_256 ) ;
V_147 = F_164 ( V_47 , & V_203 -> V_111 , 1 ) ;
F_27 ( & V_256 ) ;
F_165 () ;
if ( F_166 ( V_147 ) ) {
F_69 (KERN_ERR PFX L_37 ,
netdev->name) ;
return - V_301 ;
}
if ( V_296 ) {
F_167 ( V_203 , V_302 ) ;
} else {
V_147 -> V_303 = V_304 ;
F_168 ( V_147 ) ;
F_169 ( V_147 ) ;
F_170 ( V_147 ) ;
}
return 0 ;
}
static void F_171 ( struct V_48 * V_49 , struct V_2 * V_3 )
{
struct V_305 * V_306 , * V_162 ;
F_12 ( & V_49 -> V_55 ) ;
F_99 (blport, tmp, &hba->vports, list) {
if ( V_306 -> V_3 == V_3 ) {
F_172 ( & V_306 -> V_34 ) ;
F_102 ( V_306 ) ;
}
}
F_16 ( & V_49 -> V_55 ) ;
}
static int F_173 ( struct V_295 * V_203 )
{
struct V_167 * V_168 = F_160 ( V_203 ) ;
struct V_2 * V_297 = F_104 ( V_168 ) ;
struct V_2 * V_147 = V_203 -> V_307 ;
struct V_5 * V_46 = F_2 ( V_147 ) ;
struct V_4 * V_47 = V_46 -> V_6 ;
struct V_2 * V_308 ;
bool V_309 = false ;
F_24 ( & V_297 -> V_259 ) ;
F_133 (v_port, &n_port->vports, list)
if ( V_308 -> V_203 == V_203 ) {
V_309 = true ;
break;
}
if ( ! V_309 ) {
F_27 ( & V_297 -> V_259 ) ;
return - V_310 ;
}
F_172 ( & V_147 -> V_34 ) ;
F_27 ( & V_297 -> V_259 ) ;
F_171 ( V_47 -> V_49 , V_46 -> V_3 ) ;
F_174 ( V_46 -> V_3 ) ;
F_175 ( V_47 ) ;
F_176 ( V_311 , & V_46 -> V_312 ) ;
return 0 ;
}
static int F_177 ( struct V_295 * V_203 , bool V_313 )
{
struct V_2 * V_3 = V_203 -> V_307 ;
if ( V_313 ) {
F_167 ( V_203 , V_302 ) ;
F_178 ( V_3 ) ;
} else {
V_3 -> V_303 = V_304 ;
F_169 ( V_3 ) ;
F_170 ( V_3 ) ;
}
return 0 ;
}
static int F_179 ( struct V_4 * V_47 )
{
struct V_1 * V_7 = V_47 -> V_7 ;
struct V_1 * V_314 = V_47 -> V_49 -> V_225 ;
struct V_12 * V_26 = F_36 ( V_47 ) ;
struct V_315 * V_316 ;
int V_317 = 0 ;
F_180 () ;
F_181 (physdev, ha) {
F_23 ( L_38 ,
V_316 -> type ) ;
F_69 ( V_318 L_39 , V_316 -> V_294 [ 0 ] ,
V_316 -> V_294 [ 1 ] , V_316 -> V_294 [ 2 ] , V_316 -> V_294 [ 3 ] ,
V_316 -> V_294 [ 4 ] , V_316 -> V_294 [ 5 ] ) ;
if ( ( V_316 -> type == V_319 ) &&
( F_182 ( V_316 -> V_294 ) ) ) {
memcpy ( V_26 -> V_120 , V_316 -> V_294 ,
V_116 ) ;
V_317 = 1 ;
F_23 ( L_40 ) ;
}
}
F_183 () ;
if ( ! V_317 )
return - V_76 ;
V_47 -> V_293 . V_320 = F_152 ;
V_47 -> V_293 . type = F_57 ( V_321 ) ;
V_47 -> V_293 . V_111 = V_7 ;
F_184 ( & V_47 -> V_293 ) ;
V_47 -> V_136 . V_320 = F_67 ;
V_47 -> V_136 . type = F_185 ( V_110 ) ;
V_47 -> V_136 . V_111 = V_7 ;
F_184 ( & V_47 -> V_136 ) ;
return 0 ;
}
static int F_186 ( void )
{
V_206 =
F_187 ( & V_322 ) ;
if ( V_206 == NULL ) {
F_69 (KERN_ERR PFX L_41 ) ;
return - V_76 ;
}
V_205 =
F_187 ( & V_323 ) ;
if ( V_205 == NULL ) {
F_69 (KERN_ERR PFX
L_42 ) ;
F_188 ( V_206 ) ;
V_206 = NULL ;
return - V_76 ;
}
return 0 ;
}
static void F_189 ( void )
{
F_188 ( V_206 ) ;
F_188 ( V_205 ) ;
V_206 = NULL ;
V_205 = NULL ;
}
static void F_190 ( struct V_324 * V_324 )
{
struct V_10 * V_11 ;
struct V_4 * V_47 ;
struct V_12 * V_26 ;
struct V_1 * V_7 ;
V_47 = F_68 ( V_324 , struct V_4 , V_324 ) ;
F_23 ( L_43 ) ;
V_26 = F_36 ( V_47 ) ;
V_11 = F_191 ( V_26 ) ;
V_7 = V_47 -> V_7 ;
if ( F_192 ( V_325 , & V_47 -> V_326 ) )
F_193 ( V_26 ) ;
F_194 ( V_11 ) ;
F_195 ( V_7 ) ;
F_196 ( V_327 ) ;
}
static inline void F_197 ( struct V_4 * V_47 )
{
F_198 ( & V_47 -> V_324 ) ;
}
static inline void F_175 ( struct V_4 * V_47 )
{
F_199 ( & V_47 -> V_324 , F_190 ) ;
}
static void F_200 ( struct V_48 * V_49 )
{
if ( V_49 -> V_328 ) {
F_201 ( V_49 -> V_328 ) ;
V_49 -> V_328 = NULL ;
}
F_102 ( V_49 -> V_57 ) ;
F_202 ( V_49 ) ;
F_102 ( V_49 ) ;
}
static struct V_48 * F_203 ( struct V_329 * V_330 )
{
struct V_48 * V_49 ;
struct V_331 * V_332 ;
int V_44 ;
V_49 = F_204 ( sizeof( * V_49 ) , V_333 ) ;
if ( ! V_49 ) {
F_69 (KERN_ERR PFX L_44 ) ;
return NULL ;
}
F_205 ( & V_49 -> V_55 ) ;
F_206 ( & V_49 -> V_54 ) ;
V_49 -> V_330 = V_330 ;
V_44 = F_207 ( V_49 ) ;
if ( V_44 ) {
F_69 (KERN_ERR PFX L_45 ) ;
goto V_334;
}
V_49 -> V_225 = V_330 -> V_7 ;
V_49 -> V_335 = 0 ;
V_49 -> V_57 =
F_204 ( sizeof( struct V_50 * ) * V_56 ,
V_333 ) ;
if ( ! V_49 -> V_57 ) {
F_69 (KERN_ERR PFX L_46 ) ;
goto V_336;
}
V_49 -> V_264 = 0 ;
V_49 -> V_328 = F_208 ( V_49 , V_337 ,
V_338 ) ;
if ( ! V_49 -> V_328 ) {
F_69 (KERN_ERR PFX L_47 ) ;
goto V_339;
}
V_332 = & V_49 -> V_332 ;
V_332 -> V_340 = V_341 <<
V_342 ;
V_332 -> V_340 |= V_56 <<
V_343 ;
V_332 -> V_344 = V_345 <<
V_346 ;
V_332 -> V_344 |= V_347 <<
V_348 ;
V_332 -> V_349 = V_56 <<
V_350 ;
V_332 -> V_349 |= V_345 <<
V_351 ;
V_332 -> V_352 = V_353 ;
F_138 ( & V_49 -> V_263 ) ;
F_138 ( & V_49 -> V_243 ) ;
F_209 ( & V_49 -> V_354 ) ;
return V_49 ;
V_339:
F_102 ( V_49 -> V_57 ) ;
V_336:
F_202 ( V_49 ) ;
V_334:
F_102 ( V_49 ) ;
return NULL ;
}
struct V_4 * F_210 ( struct V_48 * V_49 ,
struct V_1 * V_7 ,
enum V_355 V_356 )
{
struct V_10 * V_11 ;
struct V_4 * V_47 ;
struct V_12 * V_26 ;
int V_357 ;
int V_44 = 0 ;
V_357 = ( sizeof( * V_47 ) + sizeof( struct V_12 ) ) ;
V_11 = F_211 ( & V_7 -> V_111 , & V_358 ,
V_357 ) ;
if ( ! V_11 ) {
F_69 (KERN_ERR PFX L_48 ) ;
return NULL ;
}
V_26 = F_6 ( V_11 ) ;
V_47 = F_10 ( V_26 ) ;
F_212 ( V_7 ) ;
F_213 ( & V_47 -> V_324 ) ;
V_47 -> V_49 = V_49 ;
V_47 -> V_7 = V_7 ;
F_214 ( V_26 , V_356 ) ;
V_26 -> V_359 = F_156 ;
V_26 -> V_360 = F_154 ;
V_26 -> V_361 = F_155 ;
F_119 ( V_325 , & V_47 -> V_326 ) ;
V_44 = F_179 ( V_47 ) ;
if ( ! V_44 )
return V_47 ;
F_193 ( V_26 ) ;
F_195 ( V_7 ) ;
F_194 ( V_11 ) ;
return NULL ;
}
static struct V_2 * F_164 ( struct V_4 * V_47 ,
struct V_194 * V_362 , int V_363 )
{
struct V_12 * V_26 = F_36 ( V_47 ) ;
struct V_2 * V_3 , * V_297 ;
struct V_5 * V_46 ;
struct V_167 * V_168 ;
struct V_295 * V_203 = F_215 ( V_362 ) ;
struct V_305 * V_306 ;
struct V_48 * V_49 ;
int V_44 = 0 ;
V_306 = F_204 ( sizeof( struct V_305 ) , V_333 ) ;
if ( ! V_306 ) {
F_38 ( V_26 -> V_14 , L_49 ) ;
return NULL ;
}
if ( ! V_363 )
V_3 = F_216 ( & V_364 , sizeof( * V_46 ) ) ;
else
V_3 = F_217 ( V_203 , sizeof( * V_46 ) ) ;
if ( ! V_3 ) {
F_69 (KERN_ERR PFX L_50 ) ;
goto V_365;
}
V_168 = V_3 -> V_195 ;
V_46 = F_2 ( V_3 ) ;
V_46 -> V_3 = V_3 ;
V_46 -> V_6 = V_47 ;
F_218 ( & V_46 -> V_312 , V_366 ) ;
V_44 = F_149 ( V_3 ) ;
if ( V_44 )
goto V_367;
if ( V_363 ) {
F_69 (KERN_ERR PFX L_51 ,
vport->node_name, vport->port_name) ;
F_127 ( V_3 , V_203 -> V_368 ) ;
F_128 ( V_3 , V_203 -> V_299 ) ;
}
V_44 = F_121 ( V_3 , V_47 -> V_7 ) ;
if ( V_44 ) {
F_69 (KERN_ERR PFX L_52 ) ;
goto V_367;
}
V_44 = F_109 ( V_3 , V_362 ) ;
if ( V_44 ) {
F_69 (KERN_ERR PFX L_53 ,
interface->netdev->name) ;
goto V_367;
}
V_44 = F_142 ( V_3 ) ;
if ( V_44 ) {
F_69 (KERN_ERR PFX L_54 ) ;
goto V_369;
}
F_136 ( V_3 -> V_195 ) = V_260 ;
if ( ! V_363 )
V_44 = F_147 ( V_3 ) ;
else {
V_168 = F_160 ( V_203 ) ;
V_297 = F_104 ( V_168 ) ;
V_44 = F_219 ( V_297 , V_3 ) ;
}
if ( V_44 ) {
F_69 (KERN_ERR PFX L_55 ) ;
goto V_369;
}
F_197 ( V_47 ) ;
V_49 = V_47 -> V_49 ;
F_12 ( & V_49 -> V_55 ) ;
V_306 -> V_3 = V_3 ;
F_220 ( & V_306 -> V_34 , & V_49 -> V_354 ) ;
F_16 ( & V_49 -> V_55 ) ;
return V_3 ;
V_369:
F_221 ( V_168 ) ;
V_367:
F_222 ( V_3 -> V_195 ) ;
V_365:
F_102 ( V_306 ) ;
return NULL ;
}
static void F_223 ( struct V_4 * V_47 )
{
F_224 ( & V_47 -> V_136 ) ;
F_224 ( & V_47 -> V_293 ) ;
F_225 () ;
}
static void F_226 ( struct V_4 * V_47 )
{
struct V_12 * V_26 = F_36 ( V_47 ) ;
struct V_2 * V_3 = V_26 -> V_14 ;
struct V_5 * V_46 = F_2 ( V_3 ) ;
struct V_48 * V_49 = V_47 -> V_49 ;
F_227 ( & V_46 -> V_238 ) ;
F_137 ( V_3 ) ;
F_223 ( V_47 ) ;
F_171 ( V_49 , V_3 ) ;
}
static void F_228 ( struct V_2 * V_3 )
{
F_11 ( V_3 ) ;
F_229 ( V_3 -> V_195 ) ;
F_221 ( V_3 -> V_195 ) ;
F_230 ( V_3 ) ;
F_231 ( V_3 ) ;
F_222 ( V_3 -> V_195 ) ;
}
static void F_132 ( struct V_4 * V_47 )
{
struct V_12 * V_26 = F_36 ( V_47 ) ;
struct V_2 * V_3 = V_26 -> V_14 ;
struct V_5 * V_46 = F_2 ( V_3 ) ;
F_226 ( V_47 ) ;
F_232 ( V_47 ) ;
F_172 ( & V_47 -> V_34 ) ;
F_175 ( V_47 ) ;
F_176 ( V_311 , & V_46 -> V_312 ) ;
}
static int F_233 ( struct V_1 * V_7 )
{
struct V_4 * V_47 = NULL ;
struct V_370 * V_371 ;
struct V_12 * V_26 ;
int V_44 = 0 ;
F_163 () ;
F_24 ( & V_256 ) ;
V_47 = F_234 ( V_7 ) ;
V_26 = F_36 ( V_47 ) ;
if ( ! V_47 || ! V_26 -> V_14 ) {
V_44 = - V_76 ;
F_69 (KERN_ERR PFX L_56 ) ;
goto V_372;
}
V_371 = V_47 -> V_371 ;
F_132 ( V_47 ) ;
F_235 ( V_371 ) ;
V_372:
F_27 ( & V_256 ) ;
F_165 () ;
return V_44 ;
}
static void V_366 ( struct V_373 * V_161 )
{
struct V_5 * V_46 ;
struct V_2 * V_3 ;
V_46 = F_68 ( V_161 , struct V_5 , V_312 ) ;
V_3 = V_46 -> V_3 ;
F_38 ( V_3 , L_57 ) ;
F_228 ( V_3 ) ;
}
static void F_236 ( struct V_48 * V_49 )
{
F_237 ( V_49 ) ;
F_238 ( V_49 ) ;
}
static int F_239 ( struct V_48 * V_49 )
{
if ( F_240 ( V_49 ) )
goto V_374;
if ( F_241 ( V_49 ) )
goto V_374;
return 0 ;
V_374:
F_236 ( V_49 ) ;
return - V_77 ;
}
static int F_207 ( struct V_48 * V_49 )
{
struct V_329 * V_330 ;
if ( ! V_49 -> V_330 ) {
F_69 (KERN_ERR PFX L_58 ) ;
return - V_76 ;
}
V_330 = V_49 -> V_330 ;
V_49 -> V_375 = V_330 -> V_375 ;
if ( V_49 -> V_375 )
F_242 ( V_49 -> V_375 ) ;
return 0 ;
}
static void F_202 ( struct V_48 * V_49 )
{
if ( V_49 -> V_375 )
F_243 ( V_49 -> V_375 ) ;
V_49 -> V_375 = NULL ;
}
static int F_244 ( void * V_376 )
{
struct V_48 * V_49 = V_376 ;
struct V_329 * V_330 ;
struct V_377 * V_378 ;
if ( ! V_49 )
return - V_94 ;
V_330 = V_49 -> V_330 ;
V_378 = & V_330 -> V_378 -> V_379 ;
if ( ! V_378 )
return - V_94 ;
strncpy ( V_378 -> V_380 , V_209 ,
sizeof( V_378 -> V_380 ) ) ;
V_378 -> V_381 = V_382 ;
V_378 -> V_383 = V_384 ;
return 0 ;
}
static void F_245 ( void * V_376 )
{
struct V_48 * V_49 = V_376 ;
struct V_4 * V_47 ;
struct V_12 * V_26 ;
struct V_2 * V_3 ;
F_24 ( & V_256 ) ;
if ( ! F_45 ( V_300 , & V_49 -> V_97 ) )
F_246 ( V_49 ) ;
F_23 ( L_59 ) ;
F_133 (interface, &if_list, list) {
if ( V_47 -> V_49 == V_49 ) {
V_26 = F_36 ( V_47 ) ;
V_3 = V_26 -> V_14 ;
F_69 (KERN_ERR PFX L_60 ) ;
V_3 -> V_266 . V_385 = F_35 ;
F_247 ( V_47 ) ;
}
}
F_27 ( & V_256 ) ;
}
static void F_174 ( struct V_2 * V_3 )
{
F_23 ( L_1 , V_53 ) ;
F_178 ( V_3 ) ;
F_248 ( V_3 ) ;
}
static void F_232 ( struct V_4 * V_47 )
{
struct V_12 * V_26 = F_36 ( V_47 ) ;
struct V_2 * V_3 ;
struct V_2 * V_203 ;
if ( ! F_45 ( V_300 , & V_47 -> V_49 -> V_97 ) )
return;
V_3 = V_26 -> V_14 ;
F_174 ( V_3 ) ;
F_24 ( & V_3 -> V_259 ) ;
F_133 (vport, &lport->vports, list)
F_136 ( V_203 -> V_195 ) =
V_260 ;
F_27 ( & V_3 -> V_259 ) ;
F_136 ( V_3 -> V_195 ) = V_260 ;
F_135 ( V_26 ) ;
F_137 ( V_3 ) ;
}
static int F_246 ( struct V_48 * V_49 )
{
#define F_249 (1000 / HZ)
int V_44 = - 1 ;
int V_52 = V_174 ;
V_44 = F_239 ( V_49 ) ;
if ( V_44 ) {
F_69 (KERN_ALERT PFX
L_61 , rc) ;
goto V_386;
}
V_44 = F_250 ( V_49 ) ;
if ( V_44 ) {
F_69 (KERN_ALERT PFX
L_62 , rc) ;
goto V_387;
}
while ( ! F_45 ( V_250 , & V_49 -> V_228 ) && V_52 -- )
F_251 ( F_249 ) ;
if ( ! F_45 ( V_250 , & V_49 -> V_228 ) ) {
F_69 (KERN_ERR PFX L_63
L_64 ,
hba->cnic->netdev->name) ;
V_44 = - 1 ;
goto V_387;
}
F_119 ( V_300 , & V_49 -> V_97 ) ;
return 0 ;
V_387:
F_236 ( V_49 ) ;
V_386:
return V_44 ;
}
static void F_252 ( struct V_48 * V_49 )
{
if ( F_192 ( V_300 , & V_49 -> V_97 ) ) {
if ( F_253 ( V_49 ) == 0 ) {
F_254 ( & V_49 -> V_388 ) ;
V_49 -> V_388 . V_389 = V_390 +
V_304 ;
V_49 -> V_388 . V_391 = F_129 ;
V_49 -> V_388 . V_156 = ( unsigned long ) V_49 ;
F_255 ( & V_49 -> V_388 ) ;
F_139 ( V_49 -> V_243 ,
F_45 ( V_242 ,
& V_49 -> V_97 ) ) ;
F_118 ( V_242 , & V_49 -> V_97 ) ;
if ( F_140 ( V_142 ) )
F_141 ( V_142 ) ;
F_227 ( & V_49 -> V_388 ) ;
}
F_236 ( V_49 ) ;
}
}
static void F_256 ( void * V_376 )
{
struct V_48 * V_49 = V_376 ;
struct V_4 * V_47 ;
F_69 ( V_251 L_65 ) ;
F_24 ( & V_256 ) ;
if ( ! F_45 ( V_300 , & V_49 -> V_97 ) )
goto exit;
F_133 (interface, &if_list, list) {
if ( V_47 -> V_49 == V_49 )
F_232 ( V_47 ) ;
}
F_257 ( V_49 -> V_264 != 0 ) ;
F_24 ( & V_49 -> V_54 ) ;
F_118 ( V_250 , & V_49 -> V_228 ) ;
F_118 ( V_253 ,
& V_49 -> V_228 ) ;
F_118 ( V_262 , & V_49 -> V_228 ) ;
F_27 ( & V_49 -> V_54 ) ;
F_252 ( V_49 ) ;
exit:
F_27 ( & V_256 ) ;
}
static void F_247 ( struct V_4 * V_47 )
{
struct V_12 * V_26 = F_36 ( V_47 ) ;
struct V_2 * V_3 ;
int V_392 = 0 ;
F_23 ( L_1 , V_53 ) ;
if ( ! F_45 ( V_300 , & V_47 -> V_49 -> V_97 ) ) {
F_69 (KERN_ERR PFX L_66 ) ;
return;
}
V_3 = V_26 -> V_14 ;
F_38 ( V_3 , L_67 ) ;
if ( ! F_116 ( V_3 ) && V_47 -> V_258 ) {
F_38 ( V_3 , L_68 ) ;
F_134 ( V_26 ) ;
F_136 ( V_3 -> V_195 ) = V_393 ;
F_119 ( V_262 , & V_47 -> V_49 -> V_228 ) ;
}
while ( ! V_26 -> V_93 ) {
F_251 ( 250 ) ;
if ( ++ V_392 > 12 )
break;
}
if ( F_122 ( V_3 , V_236 ) )
return;
F_168 ( V_3 ) ;
F_169 ( V_3 ) ;
}
static void F_258 ( struct V_329 * V_111 )
{
struct V_48 * V_49 ;
int V_44 = 0 ;
F_23 ( L_1 , V_53 ) ;
if ( ! F_45 ( V_394 , & V_111 -> V_97 ) ||
( V_111 -> V_395 == 0 ) ) {
F_69 (KERN_ERR PFX L_69
L_70 ,
dev->netdev->name, dev->flags, dev->max_fcoe_conn) ;
return;
}
V_49 = F_203 ( V_111 ) ;
if ( ! V_49 ) {
F_69 (KERN_ERR PFX L_71 ) ;
return;
}
F_24 ( & V_256 ) ;
F_220 ( & V_49 -> V_34 , & V_396 ) ;
V_397 ++ ;
F_27 ( & V_256 ) ;
V_111 -> V_332 = & V_49 -> V_332 ;
F_118 ( V_398 , & V_49 -> V_399 ) ;
V_44 = V_111 -> V_400 ( V_111 , V_401 ,
( void * ) V_49 ) ;
if ( V_44 )
F_69 (KERN_ERR PFX L_72 , rc) ;
else
F_119 ( V_398 , & V_49 -> V_399 ) ;
}
static int F_259 ( struct V_1 * V_7 )
{
struct V_4 * V_47 ;
struct V_12 * V_26 ;
int V_44 = 0 ;
F_163 () ;
F_24 ( & V_256 ) ;
V_47 = F_234 ( V_7 ) ;
V_26 = F_36 ( V_47 ) ;
if ( ! V_47 || ! V_26 -> V_14 ) {
V_44 = - V_76 ;
F_69 (KERN_ERR PFX L_73 ) ;
} else {
V_47 -> V_258 = false ;
F_135 ( V_26 ) ;
F_137 ( V_26 -> V_14 ) ;
}
F_27 ( & V_256 ) ;
F_165 () ;
return V_44 ;
}
static int F_260 ( struct V_1 * V_7 )
{
struct V_4 * V_47 ;
struct V_12 * V_26 ;
int V_44 = 0 ;
F_163 () ;
F_24 ( & V_256 ) ;
V_47 = F_234 ( V_7 ) ;
V_26 = F_36 ( V_47 ) ;
if ( ! V_47 || ! V_26 -> V_14 ) {
V_44 = - V_76 ;
F_69 (KERN_ERR PFX L_74 ) ;
} else if ( ! F_116 ( V_26 -> V_14 ) ) {
F_134 ( V_26 ) ;
V_47 -> V_258 = true ;
}
F_27 ( & V_256 ) ;
F_165 () ;
return V_44 ;
}
static int F_261 ( struct V_1 * V_7 , enum V_355 V_356 )
{
struct V_12 * V_26 ;
struct V_4 * V_47 ;
struct V_48 * V_49 ;
struct V_1 * V_225 = V_7 ;
struct V_2 * V_3 ;
struct V_402 V_403 ;
int V_44 = 0 ;
int V_28 = 0 ;
F_23 ( L_75 ) ;
if ( V_356 != V_404 ) {
F_69 ( V_251 L_76 ) ;
return - V_301 ;
}
F_163 () ;
F_24 ( & V_256 ) ;
if ( ! F_262 ( V_327 ) ) {
V_44 = - V_94 ;
goto V_405;
}
if ( V_7 -> V_406 & V_407 )
V_225 = F_263 ( V_7 ) ;
if ( V_225 -> V_233 && V_225 -> V_233 -> V_408 ) {
memset ( & V_403 , 0 , sizeof( V_403 ) ) ;
V_225 -> V_233 -> V_408 ( V_225 , & V_403 ) ;
if ( strncmp ( V_403 . V_409 , L_77 , strlen ( L_77 ) ) ) {
F_69 (KERN_ERR PFX L_78 ) ;
V_44 = - V_94 ;
goto V_372;
}
} else {
F_69 (KERN_ERR PFX L_79 ) ;
V_44 = - V_94 ;
goto V_372;
}
V_49 = F_264 ( V_225 ) ;
if ( ! V_49 ) {
V_44 = - V_76 ;
F_69 (KERN_ERR PFX L_80 ) ;
goto V_372;
}
if ( F_234 ( V_7 ) ) {
V_44 = - V_410 ;
goto V_372;
}
V_47 = F_210 ( V_49 , V_7 , V_356 ) ;
if ( ! V_47 ) {
F_69 (KERN_ERR PFX L_81 ) ;
goto V_411;
}
if ( V_7 -> V_406 & V_407 ) {
V_28 = F_265 ( V_7 ) ;
V_47 -> V_412 = 1 ;
}
V_26 = F_36 ( V_47 ) ;
V_47 -> V_28 = V_28 ;
V_47 -> V_371 =
F_266 ( L_82 ) ;
if ( ! V_47 -> V_371 ) {
F_69 (KERN_ERR PFX L_83 ) ;
V_44 = - V_94 ;
goto V_411;
}
V_3 = F_164 ( V_47 , & V_47 -> V_49 -> V_375 -> V_111 , 0 ) ;
if ( ! V_3 ) {
F_69 (KERN_ERR PFX L_84 ,
netdev->name) ;
V_44 = - V_94 ;
goto V_413;
}
F_220 ( & V_47 -> V_34 , & V_414 ) ;
V_3 -> V_303 = V_304 ;
V_26 -> V_14 = V_3 ;
if ( ! F_116 ( V_3 ) ) {
F_134 ( V_26 ) ;
F_136 ( V_3 -> V_195 ) = V_393 ;
F_119 ( V_262 , & V_47 -> V_49 -> V_228 ) ;
}
F_38 ( V_3 , L_85 ) ;
F_247 ( V_47 ) ;
V_47 -> V_258 = true ;
F_175 ( V_47 ) ;
F_27 ( & V_256 ) ;
F_165 () ;
return 0 ;
V_413:
F_235 ( V_47 -> V_371 ) ;
V_411:
F_223 ( V_47 ) ;
F_175 ( V_47 ) ;
goto V_405;
V_372:
F_196 ( V_327 ) ;
V_405:
F_27 ( & V_256 ) ;
F_165 () ;
return V_44 ;
}
static struct V_48 * F_267 ( struct V_329 * V_330 )
{
struct V_48 * V_49 ;
F_133 (hba, &adapter_list, list) {
if ( V_49 -> V_330 == V_330 )
return V_49 ;
}
return NULL ;
}
static struct V_4 * F_234 ( struct V_1
* V_7 )
{
struct V_4 * V_47 ;
F_133 (interface, &if_list, list) {
if ( V_47 -> V_7 == V_7 )
return V_47 ;
}
return NULL ;
}
static struct V_48 * F_264 ( struct V_1
* V_225 )
{
struct V_48 * V_49 ;
F_133 (hba, &adapter_list, list) {
if ( V_49 -> V_225 == V_225 )
return V_49 ;
}
F_69 (KERN_ERR PFX L_86 ) ;
return NULL ;
}
static void F_268 ( struct V_329 * V_111 )
{
struct V_48 * V_49 ;
struct V_4 * V_47 , * V_162 ;
F_23 ( L_87 ) ;
if ( ! F_45 ( V_394 , & V_111 -> V_97 ) ) {
F_69 (KERN_ERR PFX L_88 ,
dev->netdev->name, dev->flags) ;
return;
}
F_24 ( & V_256 ) ;
V_49 = F_267 ( V_111 ) ;
if ( ! V_49 ) {
F_69 (KERN_ERR PFX L_89 ,
dev) ;
F_27 ( & V_256 ) ;
return;
}
F_100 ( & V_49 -> V_34 ) ;
V_397 -- ;
F_99 (interface, tmp, &if_list, list)
if ( V_47 -> V_49 == V_49 )
F_132 ( V_47 ) ;
F_27 ( & V_256 ) ;
F_256 ( V_49 ) ;
if ( F_192 ( V_398 , & V_49 -> V_399 ) )
V_49 -> V_330 -> V_415 ( V_49 -> V_330 , V_401 ) ;
F_200 ( V_49 ) ;
}
static int F_269 ( struct V_167 * V_168 )
{
struct V_2 * V_3 = F_104 ( V_168 ) ;
F_270 ( V_3 ) ;
return 0 ;
}
static bool F_271 ( struct V_1 * V_7 )
{
struct V_1 * V_225 = V_7 ;
F_24 ( & V_256 ) ;
if ( V_7 -> V_406 & V_407 )
V_225 = F_263 ( V_7 ) ;
if ( F_264 ( V_225 ) ) {
F_27 ( & V_256 ) ;
return true ;
}
F_27 ( & V_256 ) ;
return false ;
}
static void F_272 ( unsigned int V_416 )
{
struct V_158 * V_159 ;
struct V_417 * V_140 ;
V_159 = & F_273 ( V_418 , V_416 ) ;
V_140 = F_274 ( F_95 ,
( void * ) V_159 , F_275 ( V_416 ) ,
L_90 , V_416 ) ;
if ( F_276 ( ! F_166 ( V_140 ) ) ) {
F_277 ( V_140 , V_416 ) ;
V_159 -> V_419 = V_140 ;
F_74 ( V_140 ) ;
}
}
static void F_278 ( unsigned int V_416 )
{
struct V_158 * V_159 ;
struct V_417 * V_140 ;
struct V_160 * V_161 , * V_162 ;
F_23 ( L_91 , V_416 ) ;
V_159 = & F_273 ( V_418 , V_416 ) ;
F_12 ( & V_159 -> V_164 ) ;
V_140 = V_159 -> V_419 ;
V_159 -> V_419 = NULL ;
F_99 (work, tmp, &p->work_list, list) {
F_100 ( & V_161 -> V_34 ) ;
F_101 ( V_161 -> V_51 , V_161 -> V_165 ) ;
F_102 ( V_161 ) ;
}
F_16 ( & V_159 -> V_164 ) ;
if ( V_140 )
F_279 ( V_140 ) ;
}
static int F_280 ( struct V_420 * V_421 ,
unsigned long V_422 , void * V_423 )
{
unsigned V_416 = ( unsigned long ) V_423 ;
switch ( V_422 ) {
case V_424 :
case V_425 :
F_69 ( V_426 L_92 , V_416 ) ;
F_272 ( V_416 ) ;
break;
case V_427 :
case V_428 :
F_69 ( V_426 L_93 , V_416 ) ;
F_278 ( V_416 ) ;
break;
default:
break;
}
return V_429 ;
}
static int T_6 F_281 ( void )
{
struct V_29 * V_30 ;
struct V_417 * V_430 ;
int V_44 = 0 ;
unsigned int V_416 = 0 ;
struct V_158 * V_159 ;
F_69 (KERN_INFO PFX L_94 , version) ;
V_44 = F_282 ( & V_431 ) ;
if ( V_44 ) {
F_69 ( V_251 L_95
L_96 ) ;
goto V_432;
}
F_209 ( & V_396 ) ;
F_209 ( & V_414 ) ;
F_206 ( & V_256 ) ;
V_397 = 0 ;
V_44 = F_186 () ;
if ( V_44 )
goto V_433;
V_311 = F_283 ( L_97 , 0 , 0 ) ;
if ( ! V_311 ) {
V_44 = - V_77 ;
goto V_434;
}
V_30 = & V_39 ;
F_123 ( & V_30 -> V_40 ) ;
V_430 = F_284 ( F_75 ,
( void * ) V_30 ,
L_98 ) ;
if ( F_166 ( V_430 ) ) {
V_44 = F_285 ( V_430 ) ;
goto V_435;
}
F_74 ( V_430 ) ;
F_12 ( & V_30 -> V_40 . V_41 ) ;
V_30 -> V_140 = V_430 ;
F_16 ( & V_30 -> V_40 . V_41 ) ;
F_286 (cpu) {
V_159 = & F_273 ( V_418 , V_416 ) ;
F_209 ( & V_159 -> V_163 ) ;
F_205 ( & V_159 -> V_164 ) ;
}
F_287 (cpu) {
F_272 ( V_416 ) ;
}
F_288 ( & V_436 ) ;
F_289 ( V_401 , & V_437 ) ;
return 0 ;
V_435:
F_235 ( V_311 ) ;
V_434:
F_189 () ;
V_433:
F_290 ( & V_431 ) ;
V_432:
return V_44 ;
}
static void T_7 F_291 ( void )
{
F_96 ( V_438 ) ;
struct V_48 * V_49 , * V_37 ;
struct V_29 * V_30 ;
struct V_417 * V_430 ;
struct V_35 * V_36 ;
unsigned int V_416 = 0 ;
F_24 ( & V_256 ) ;
F_292 ( & V_396 , & V_438 ) ;
F_209 ( & V_396 ) ;
V_397 = 0 ;
F_27 ( & V_256 ) ;
F_99 (hba, next, &to_be_deleted, list) {
F_100 ( & V_49 -> V_34 ) ;
F_69 (KERN_ERR PFX L_99 ,
hba) ;
F_256 ( V_49 ) ;
if ( F_192 ( V_398 ,
& V_49 -> V_399 ) )
V_49 -> V_330 -> V_415 ( V_49 -> V_330 ,
V_401 ) ;
F_200 ( V_49 ) ;
}
F_293 ( V_401 ) ;
V_30 = & V_39 ;
F_12 ( & V_30 -> V_40 . V_41 ) ;
V_430 = V_30 -> V_140 ;
V_30 -> V_140 = NULL ;
while ( ( V_36 = F_80 ( & V_30 -> V_40 ) ) != NULL )
F_15 ( V_36 ) ;
F_16 ( & V_30 -> V_40 . V_41 ) ;
if ( V_430 )
F_279 ( V_430 ) ;
F_294 ( & V_436 ) ;
F_287 (cpu) {
F_278 ( V_416 ) ;
}
F_235 ( V_311 ) ;
F_189 () ;
F_290 ( & V_431 ) ;
}
