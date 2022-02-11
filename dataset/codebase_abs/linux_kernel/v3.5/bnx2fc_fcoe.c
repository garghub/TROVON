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
V_85 = F_62 ( V_3 -> V_128 , F_63 () ) ;
V_85 -> V_129 ++ ;
V_85 -> V_130 += V_91 ;
F_64 () ;
V_42 ( V_59 ) = V_3 ;
if ( V_46 -> V_131 . V_132 )
F_65 ( V_3 , V_36 ) ;
else if ( F_66 ( V_36 ) )
F_65 ( V_3 , V_36 ) ;
return 0 ;
}
static int F_67 ( struct V_35 * V_36 , struct V_1 * V_111 ,
struct V_133 * V_134 , struct V_1 * V_135 )
{
struct V_2 * V_3 ;
struct V_4 * V_47 ;
struct V_12 * V_26 ;
struct V_62 * V_63 ;
struct V_31 * V_32 ;
struct V_29 * V_30 ;
unsigned short V_136 ;
V_47 = F_68 ( V_134 , struct V_4 ,
V_137 ) ;
V_26 = F_36 ( V_47 ) ;
V_3 = V_26 -> V_14 ;
if ( F_39 ( V_3 == NULL ) ) {
F_69 (KERN_ERR PFX L_12 ) ;
goto V_138;
}
if ( F_39 ( F_58 ( V_36 ) -> V_112 != F_57 ( V_110 ) ) ) {
F_69 (KERN_ERR PFX L_13 ) ;
goto V_138;
}
if ( F_39 ( ( V_36 -> V_98 < V_139 ) ||
! F_70 ( V_36 , V_140 ) ) )
goto V_138;
F_71 ( V_36 , sizeof( struct V_82 ) ) ;
V_63 = (struct V_62 * ) F_72 ( V_36 ) ;
V_136 = F_30 ( V_63 -> V_66 ) ;
V_32 = F_13 ( V_36 ) ;
V_32 -> V_42 = V_3 ;
V_30 = & V_39 ;
F_18 ( & V_30 -> V_40 . V_41 ) ;
F_73 ( & V_30 -> V_40 , V_36 ) ;
if ( V_30 -> V_40 . V_132 == 1 )
F_74 ( V_30 -> V_141 ) ;
F_20 ( & V_30 -> V_40 . V_41 ) ;
return 0 ;
V_138:
F_15 ( V_36 ) ;
return - 1 ;
}
static int F_75 ( void * V_142 )
{
struct V_29 * V_30 = V_142 ;
struct V_35 * V_36 ;
F_76 ( V_143 , - 20 ) ;
F_77 ( V_144 ) ;
while ( ! F_78 () ) {
F_79 () ;
F_12 ( & V_30 -> V_40 . V_41 ) ;
while ( ( V_36 = F_80 ( & V_30 -> V_40 ) ) != NULL ) {
F_16 ( & V_30 -> V_40 . V_41 ) ;
F_81 ( V_36 ) ;
F_12 ( & V_30 -> V_40 . V_41 ) ;
}
F_82 ( V_144 ) ;
F_16 ( & V_30 -> V_40 . V_41 ) ;
}
F_82 ( V_145 ) ;
return 0 ;
}
static void F_81 ( struct V_35 * V_36 )
{
T_2 V_146 ;
struct V_2 * V_3 ;
struct V_31 * V_32 ;
struct V_84 * V_85 ;
struct V_62 * V_63 ;
struct V_80 V_147 ;
struct V_58 * V_59 ;
struct V_2 * V_148 ;
struct V_5 * V_46 ;
T_1 * V_149 = NULL ;
T_1 * V_150 = NULL ;
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
V_149 = F_58 ( V_36 ) -> V_119 ;
V_150 = F_58 ( V_36 ) -> V_114 ;
V_83 = (struct V_82 * ) F_84 ( V_36 ) ;
V_63 = (struct V_62 * ) F_72 ( V_36 ) ;
F_85 ( V_36 , sizeof( struct V_82 ) ) ;
V_146 = V_36 -> V_98 - sizeof( struct V_80 ) ;
V_85 = F_62 ( V_3 -> V_128 , F_63 () ) ;
V_85 -> V_151 ++ ;
V_85 -> V_152 += V_146 / V_99 ;
V_59 = (struct V_58 * ) V_36 ;
F_86 ( V_59 ) ;
V_42 ( V_59 ) = V_3 ;
F_41 ( V_59 ) = V_83 -> V_123 ;
if ( F_87 ( V_36 , V_146 , & V_147 , sizeof( V_147 ) ) ) {
F_64 () ;
F_15 ( V_36 ) ;
return;
}
F_42 ( V_59 ) = V_147 . V_106 ;
F_88 ( V_59 ) = V_147 . V_107 ;
if ( F_89 ( V_36 , V_146 ) ) {
F_64 () ;
F_15 ( V_36 ) ;
return;
}
V_63 = F_29 ( V_59 ) ;
V_148 = F_90 ( V_3 , F_44 ( V_63 -> V_95 ) ) ;
if ( V_148 ) {
V_46 = F_2 ( V_148 ) ;
if ( F_91 ( V_46 -> V_121 , V_150 )
!= 0 ) {
F_38 ( V_3 , L_15 ) ;
F_64 () ;
F_15 ( V_36 ) ;
return;
}
}
if ( V_63 -> V_67 == V_153 &&
V_63 -> V_68 == V_154 ) {
F_64 () ;
F_15 ( V_36 ) ;
return;
}
if ( V_63 -> V_67 == V_70 &&
V_63 -> V_68 == V_69 ) {
switch ( F_31 ( V_59 ) ) {
case V_72 :
if ( F_44 ( V_63 -> V_155 ) == V_156 ) {
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
~ F_93 ( ~ 0 , V_36 -> V_157 , V_146 ) ) {
if ( V_85 -> V_158 < 5 )
F_69 (KERN_WARNING PFX L_16
L_17 ) ;
V_85 -> V_158 ++ ;
F_64 () ;
F_15 ( V_36 ) ;
return;
}
F_64 () ;
F_94 ( V_3 , V_59 ) ;
}
int F_95 ( void * V_142 )
{
struct V_159 * V_160 = V_142 ;
struct V_161 * V_162 , * V_163 ;
F_96 ( V_164 ) ;
F_76 ( V_143 , - 20 ) ;
F_77 ( V_144 ) ;
while ( ! F_78 () ) {
F_79 () ;
F_12 ( & V_160 -> V_165 ) ;
while ( ! F_97 ( & V_160 -> V_164 ) ) {
F_98 ( & V_160 -> V_164 , & V_164 ) ;
F_16 ( & V_160 -> V_165 ) ;
F_99 (work, tmp, &work_list, list) {
F_100 ( & V_162 -> V_34 ) ;
F_101 ( V_162 -> V_51 , V_162 -> V_166 ) ;
F_102 ( V_162 ) ;
}
F_12 ( & V_160 -> V_165 ) ;
}
F_82 ( V_144 ) ;
F_16 ( & V_160 -> V_165 ) ;
}
F_82 ( V_145 ) ;
return 0 ;
}
static struct V_167 * F_103 ( struct V_168 * V_169 )
{
struct V_167 * V_170 ;
struct V_2 * V_3 = F_104 ( V_169 ) ;
struct V_5 * V_46 = F_2 ( V_3 ) ;
struct V_4 * V_47 = V_46 -> V_6 ;
struct V_48 * V_49 = V_47 -> V_49 ;
struct V_171 * V_172 ;
int V_44 = 0 ;
V_172 = (struct V_171 * ) V_49 -> V_173 ;
if ( ! V_172 )
return NULL ;
V_170 = F_105 ( V_169 ) ;
F_106 ( & V_49 -> V_174 ) ;
if ( F_107 ( V_49 ) )
return V_170 ;
V_44 = F_108 ( & V_49 -> V_174 , ( 2 * V_175 ) ) ;
if ( ! V_44 ) {
F_38 ( V_3 , L_18 ) ;
return V_170 ;
}
V_170 -> V_176 += V_172 -> V_177 . V_178 ;
V_170 -> V_179 += V_172 -> V_180 . V_181 ;
V_170 -> V_182 += ( V_172 -> V_180 . V_183 ) / 4 ;
V_170 -> V_184 += V_172 -> V_185 . V_186 ;
V_170 -> V_187 += ( V_172 -> V_185 . V_188 ) / 4 ;
V_170 -> V_189 = 0 ;
V_170 -> V_190 = 0 ;
V_170 -> V_191 = 0 ;
V_170 -> V_192 = 0 ;
V_170 -> V_193 = 0 ;
V_170 -> V_194 = 0 ;
return V_170 ;
}
static int F_109 ( struct V_2 * V_3 , struct V_195 * V_111 )
{
struct V_5 * V_46 = F_2 ( V_3 ) ;
struct V_4 * V_47 = V_46 -> V_6 ;
struct V_168 * V_169 = V_3 -> V_196 ;
int V_44 = 0 ;
V_169 -> V_197 = V_198 ;
V_169 -> V_199 = V_200 ;
V_169 -> V_201 = V_202 ;
V_169 -> V_203 = 0 ;
if ( V_3 -> V_204 )
V_169 -> V_205 = V_206 ;
else
V_169 -> V_205 = V_207 ;
V_44 = F_110 ( V_3 -> V_196 , V_111 ) ;
if ( V_44 ) {
F_69 (KERN_ERR PFX L_19 ) ;
return V_44 ;
}
if ( ! V_3 -> V_204 )
F_111 ( V_3 -> V_196 ) = V_208 ;
sprintf ( F_112 ( V_3 -> V_196 ) , L_20 ,
V_209 , V_210 ,
V_47 -> V_7 -> V_211 ) ;
return 0 ;
}
static void F_113 ( struct V_2 * V_3 )
{
struct V_5 * V_46 = F_2 ( V_3 ) ;
struct V_4 * V_47 = V_46 -> V_6 ;
struct V_1 * V_7 = V_47 -> V_7 ;
struct V_212 V_213 ;
if ( ! F_114 ( V_7 , & V_213 ) ) {
V_3 -> V_214 &=
~ ( V_215 | V_216 ) ;
if ( V_213 . V_217 & ( V_218 |
V_219 ) )
V_3 -> V_214 |= V_215 ;
if ( V_213 . V_217 & V_220 )
V_3 -> V_214 |= V_216 ;
switch ( F_115 ( & V_213 ) ) {
case V_221 :
V_3 -> V_222 = V_215 ;
break;
case V_223 :
V_3 -> V_222 = V_224 ;
break;
case V_225 :
V_3 -> V_222 = V_216 ;
break;
}
}
}
static int F_116 ( struct V_2 * V_3 )
{
struct V_5 * V_46 = F_2 ( V_3 ) ;
struct V_4 * V_47 = V_46 -> V_6 ;
struct V_48 * V_49 = V_47 -> V_49 ;
struct V_1 * V_111 = V_49 -> V_226 ;
int V_44 = 0 ;
if ( ( V_111 -> V_97 & V_227 ) && F_117 ( V_111 ) )
F_118 ( V_228 , & V_49 -> V_229 ) ;
else {
F_119 ( V_228 , & V_49 -> V_229 ) ;
V_44 = - 1 ;
}
return V_44 ;
}
void F_120 ( struct V_48 * V_49 )
{
if ( F_45 ( V_230 , & V_49 -> V_226 -> V_231 ) )
F_119 ( V_228 , & V_49 -> V_229 ) ;
else
F_118 ( V_228 , & V_49 -> V_229 ) ;
}
static int F_121 ( struct V_2 * V_3 , struct V_1 * V_7 )
{
struct V_48 * V_49 ;
struct V_4 * V_47 ;
struct V_12 * V_26 ;
struct V_5 * V_46 ;
T_4 V_232 , V_233 ;
V_46 = F_2 ( V_3 ) ;
V_47 = V_46 -> V_6 ;
V_26 = F_36 ( V_47 ) ;
V_49 = V_47 -> V_49 ;
if ( ! V_49 -> V_226 -> V_234 ||
! V_49 -> V_226 -> V_234 -> V_235 )
return - V_236 ;
if ( F_122 ( V_3 , V_237 ) )
return - V_94 ;
F_123 ( & V_46 -> V_131 ) ;
V_46 -> V_238 = 0 ;
F_124 ( & V_46 -> V_239 , V_240 , ( unsigned long ) V_3 ) ;
F_113 ( V_3 ) ;
if ( ! V_3 -> V_204 ) {
if ( F_125 ( V_7 , & V_232 , V_241 ) )
V_232 = F_126 ( V_26 -> V_120 ,
1 , 0 ) ;
F_38 ( V_3 , L_21 , V_232 ) ;
F_127 ( V_3 , V_232 ) ;
if ( F_125 ( V_7 , & V_233 , V_242 ) )
V_233 = F_126 ( V_26 -> V_120 ,
2 , 0 ) ;
F_38 ( V_3 , L_22 , V_233 ) ;
F_128 ( V_3 , V_233 ) ;
}
return 0 ;
}
static void F_129 ( unsigned long V_157 )
{
struct V_48 * V_49 = (struct V_48 * ) V_157 ;
F_69 (KERN_ERR PFX L_23
L_24 ) ;
F_119 ( V_243 , & V_49 -> V_97 ) ;
F_130 ( & V_49 -> V_244 ) ;
}
static void F_131 ( void * V_245 , unsigned long V_246 ,
T_5 V_28 )
{
struct V_48 * V_49 = (struct V_48 * ) V_245 ;
struct V_2 * V_3 ;
struct V_2 * V_204 ;
struct V_4 * V_47 , * V_163 ;
struct V_12 * V_26 ;
int V_247 = 0 ;
T_2 V_248 = 1 ;
if ( V_28 != 0 && V_246 != V_249 )
return;
switch ( V_246 ) {
case V_250 :
if ( ! F_45 ( V_251 , & V_49 -> V_229 ) )
F_69 ( V_252 L_25\
L_26 ) ;
break;
case V_253 :
F_118 ( V_254 , & V_49 -> V_229 ) ;
F_118 ( V_251 , & V_49 -> V_229 ) ;
V_248 = 0 ;
break;
case V_255 :
F_119 ( V_254 , & V_49 -> V_229 ) ;
V_248 = 0 ;
break;
case V_256 :
break;
case V_249 :
if ( ! V_28 )
return;
F_24 ( & V_257 ) ;
F_99 (interface, tmp, &if_list, list) {
if ( V_47 -> V_49 == V_49 &&
V_47 -> V_28 == ( V_28 & V_258 ) )
F_132 ( V_47 ) ;
}
F_27 ( & V_257 ) ;
return;
default:
F_69 (KERN_ERR PFX L_27 , event) ;
return;
}
F_24 ( & V_257 ) ;
F_133 (interface, &if_list, list) {
if ( V_47 -> V_49 != V_49 )
continue;
V_26 = F_36 ( V_47 ) ;
V_3 = V_26 -> V_14 ;
F_38 ( V_3 , L_28 ,
V_47 -> V_7 -> V_211 , V_246 ) ;
F_113 ( V_3 ) ;
if ( V_248 && ! F_116 ( V_3 ) ) {
F_122 ( V_3 , V_237 ) ;
if ( V_47 -> V_259 )
F_134 ( V_26 ) ;
} else if ( F_135 ( V_26 ) ) {
F_24 ( & V_3 -> V_260 ) ;
F_133 (vport, &lport->vports, list)
F_136 ( V_204 -> V_196 ) =
V_261 ;
F_27 ( & V_3 -> V_260 ) ;
F_136 ( V_3 -> V_196 ) = V_261 ;
F_62 ( V_3 -> V_128 ,
F_63 () ) -> V_262 ++ ;
F_64 () ;
F_137 ( V_3 ) ;
V_247 = 1 ;
}
}
F_27 ( & V_257 ) ;
if ( V_247 ) {
F_118 ( V_263 , & V_49 -> V_229 ) ;
F_138 ( & V_49 -> V_264 ) ;
F_23 ( L_29
L_30 ,
V_49 -> V_265 ) ;
V_49 -> V_266 = 1 ;
F_139 ( V_49 -> V_264 ,
( V_49 -> V_265 == 0 ) ) ;
F_23 ( L_31 ,
V_49 -> V_265 ) ;
V_49 -> V_266 = 0 ;
if ( F_140 ( V_143 ) )
F_141 ( V_143 ) ;
}
}
static int F_142 ( struct V_2 * V_3 )
{
memcpy ( & V_3 -> V_267 , & V_268 ,
sizeof( struct V_269 ) ) ;
F_143 ( V_3 ) ;
F_144 ( V_3 ) ;
F_145 ( V_3 ) ;
F_146 ( V_3 ) ;
return 0 ;
}
static int F_147 ( struct V_2 * V_3 )
{
int V_270 ;
if ( V_271 <= 2 )
V_270 = V_272 ;
else
V_270 = V_273 ;
if ( ! F_148 ( V_3 , V_274 , V_275 ,
V_270 , NULL ) ) {
F_69 (KERN_ERR PFX L_32 ) ;
return - V_77 ;
}
return 0 ;
}
static int F_149 ( struct V_2 * V_3 )
{
V_3 -> V_92 = 0 ;
V_3 -> V_276 = 0 ;
V_3 -> V_277 = V_278 ;
V_3 -> V_279 = V_280 ;
V_3 -> V_281 = 2 * 1000 ;
V_3 -> V_282 = 10 * 1000 ;
V_3 -> V_283 = ( V_284 | V_285 |
V_286 | V_287 ) ;
V_3 -> V_288 = 1 ;
memset ( & V_3 -> V_289 , 0 , sizeof( struct V_290 ) ) ;
V_3 -> V_289 . V_291 = V_292 ;
if ( F_150 ( V_3 ) )
return - V_77 ;
F_151 ( V_3 ) ;
return 0 ;
}
static int F_152 ( struct V_35 * V_36 , struct V_1 * V_111 ,
struct V_133 * V_134 ,
struct V_1 * V_293 )
{
struct V_4 * V_47 ;
struct V_12 * V_26 ;
V_47 = F_68 ( V_134 , struct V_4 ,
V_294 ) ;
V_26 = F_36 ( V_47 ) ;
F_153 ( V_26 , V_36 ) ;
return 0 ;
}
static void F_154 ( struct V_2 * V_3 , T_1 * V_295 )
{
struct V_5 * V_46 = F_2 ( V_3 ) ;
memcpy ( V_46 -> V_121 , V_295 , V_116 ) ;
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
static int F_159 ( struct V_296 * V_204 , bool V_297 )
{
struct V_168 * V_169 = F_160 ( V_204 ) ;
struct V_2 * V_298 = F_104 ( V_169 ) ;
struct V_5 * V_46 = F_2 ( V_298 ) ;
struct V_4 * V_47 = V_46 -> V_6 ;
struct V_1 * V_7 = V_47 -> V_7 ;
struct V_2 * V_148 ;
int V_44 ;
char V_299 [ 32 ] ;
V_44 = F_161 ( V_204 ) ;
if ( V_44 ) {
F_162 ( V_204 -> V_300 , V_299 , sizeof( V_299 ) ) ;
F_69 (KERN_ERR PFX L_33
L_34 ,
buf) ;
return V_44 ;
}
if ( ! F_45 ( V_301 , & V_47 -> V_49 -> V_97 ) ) {
F_69 (KERN_ERR PFX L_35
L_36 ) ;
return - V_302 ;
}
F_163 () ;
F_24 ( & V_257 ) ;
V_148 = F_164 ( V_47 , & V_204 -> V_111 , 1 ) ;
F_27 ( & V_257 ) ;
F_165 () ;
if ( F_166 ( V_148 ) ) {
F_69 (KERN_ERR PFX L_37 ,
netdev->name) ;
return - V_302 ;
}
if ( V_297 ) {
F_167 ( V_204 , V_303 ) ;
} else {
V_148 -> V_304 = V_305 ;
F_168 ( V_148 ) ;
F_169 ( V_148 ) ;
F_170 ( V_148 ) ;
}
return 0 ;
}
static void F_171 ( struct V_48 * V_49 , struct V_2 * V_3 )
{
struct V_306 * V_307 , * V_163 ;
F_12 ( & V_49 -> V_55 ) ;
F_99 (blport, tmp, &hba->vports, list) {
if ( V_307 -> V_3 == V_3 ) {
F_172 ( & V_307 -> V_34 ) ;
F_102 ( V_307 ) ;
}
}
F_16 ( & V_49 -> V_55 ) ;
}
static int F_173 ( struct V_296 * V_204 )
{
struct V_168 * V_169 = F_160 ( V_204 ) ;
struct V_2 * V_298 = F_104 ( V_169 ) ;
struct V_2 * V_148 = V_204 -> V_308 ;
struct V_5 * V_46 = F_2 ( V_148 ) ;
struct V_4 * V_47 = V_46 -> V_6 ;
struct V_2 * V_309 ;
bool V_310 = false ;
F_24 ( & V_298 -> V_260 ) ;
F_133 (v_port, &n_port->vports, list)
if ( V_309 -> V_204 == V_204 ) {
V_310 = true ;
break;
}
if ( ! V_310 ) {
F_27 ( & V_298 -> V_260 ) ;
return - V_311 ;
}
F_172 ( & V_148 -> V_34 ) ;
F_27 ( & V_298 -> V_260 ) ;
F_171 ( V_47 -> V_49 , V_46 -> V_3 ) ;
F_174 ( V_46 -> V_3 ) ;
F_175 ( V_47 ) ;
F_176 ( V_312 , & V_46 -> V_313 ) ;
return 0 ;
}
static int F_177 ( struct V_296 * V_204 , bool V_314 )
{
struct V_2 * V_3 = V_204 -> V_308 ;
if ( V_314 ) {
F_167 ( V_204 , V_303 ) ;
F_178 ( V_3 ) ;
} else {
V_3 -> V_304 = V_305 ;
F_169 ( V_3 ) ;
F_170 ( V_3 ) ;
}
return 0 ;
}
static int F_179 ( struct V_4 * V_47 )
{
struct V_1 * V_7 = V_47 -> V_7 ;
struct V_1 * V_315 = V_47 -> V_49 -> V_226 ;
struct V_12 * V_26 = F_36 ( V_47 ) ;
struct V_316 * V_317 ;
int V_318 = 0 ;
F_180 () ;
F_181 (physdev, ha) {
F_23 ( L_38 ,
V_317 -> type ) ;
F_69 ( V_319 L_39 , V_317 -> V_295 [ 0 ] ,
V_317 -> V_295 [ 1 ] , V_317 -> V_295 [ 2 ] , V_317 -> V_295 [ 3 ] ,
V_317 -> V_295 [ 4 ] , V_317 -> V_295 [ 5 ] ) ;
if ( ( V_317 -> type == V_320 ) &&
( F_182 ( V_317 -> V_295 ) ) ) {
memcpy ( V_26 -> V_120 , V_317 -> V_295 ,
V_116 ) ;
V_318 = 1 ;
F_23 ( L_40 ) ;
}
}
F_183 () ;
if ( ! V_318 )
return - V_76 ;
V_47 -> V_294 . V_321 = F_152 ;
V_47 -> V_294 . type = F_57 ( V_322 ) ;
V_47 -> V_294 . V_111 = V_7 ;
F_184 ( & V_47 -> V_294 ) ;
V_47 -> V_137 . V_321 = F_67 ;
V_47 -> V_137 . type = F_185 ( V_110 ) ;
V_47 -> V_137 . V_111 = V_7 ;
F_184 ( & V_47 -> V_137 ) ;
return 0 ;
}
static int F_186 ( void )
{
V_207 =
F_187 ( & V_323 ) ;
if ( V_207 == NULL ) {
F_69 (KERN_ERR PFX L_41 ) ;
return - V_76 ;
}
V_206 =
F_187 ( & V_324 ) ;
if ( V_206 == NULL ) {
F_69 (KERN_ERR PFX
L_42 ) ;
F_188 ( V_207 ) ;
V_207 = NULL ;
return - V_76 ;
}
return 0 ;
}
static void F_189 ( void )
{
F_188 ( V_207 ) ;
F_188 ( V_206 ) ;
V_207 = NULL ;
V_206 = NULL ;
}
static void F_190 ( struct V_325 * V_325 )
{
struct V_10 * V_11 ;
struct V_4 * V_47 ;
struct V_12 * V_26 ;
struct V_1 * V_7 ;
V_47 = F_68 ( V_325 , struct V_4 , V_325 ) ;
F_23 ( L_43 ) ;
V_26 = F_36 ( V_47 ) ;
V_11 = F_191 ( V_26 ) ;
V_7 = V_47 -> V_7 ;
if ( F_192 ( V_326 , & V_47 -> V_327 ) )
F_193 ( V_26 ) ;
F_194 ( V_11 ) ;
F_195 ( V_7 ) ;
F_196 ( V_328 ) ;
}
static inline void F_197 ( struct V_4 * V_47 )
{
F_198 ( & V_47 -> V_325 ) ;
}
static inline void F_175 ( struct V_4 * V_47 )
{
F_199 ( & V_47 -> V_325 , F_190 ) ;
}
static void F_200 ( struct V_48 * V_49 )
{
if ( V_49 -> V_329 ) {
F_201 ( V_49 -> V_329 ) ;
V_49 -> V_329 = NULL ;
}
F_102 ( V_49 -> V_57 ) ;
F_202 ( V_49 ) ;
F_102 ( V_49 ) ;
}
static struct V_48 * F_203 ( struct V_330 * V_331 )
{
struct V_48 * V_49 ;
int V_44 ;
V_49 = F_204 ( sizeof( * V_49 ) , V_332 ) ;
if ( ! V_49 ) {
F_69 (KERN_ERR PFX L_44 ) ;
return NULL ;
}
F_205 ( & V_49 -> V_55 ) ;
F_206 ( & V_49 -> V_54 ) ;
V_49 -> V_331 = V_331 ;
V_44 = F_207 ( V_49 ) ;
if ( V_44 ) {
F_69 (KERN_ERR PFX L_45 ) ;
goto V_333;
}
V_49 -> V_226 = V_331 -> V_7 ;
V_49 -> V_334 = 0 ;
V_49 -> V_57 =
F_204 ( sizeof( struct V_50 * ) * V_56 ,
V_332 ) ;
if ( ! V_49 -> V_57 ) {
F_69 (KERN_ERR PFX L_46 ) ;
goto V_335;
}
V_49 -> V_265 = 0 ;
V_49 -> V_329 = F_208 ( V_49 , V_336 ,
V_337 ) ;
if ( ! V_49 -> V_329 ) {
F_69 (KERN_ERR PFX L_47 ) ;
goto V_338;
}
F_138 ( & V_49 -> V_264 ) ;
F_138 ( & V_49 -> V_244 ) ;
F_209 ( & V_49 -> V_339 ) ;
return V_49 ;
V_338:
F_102 ( V_49 -> V_57 ) ;
V_335:
F_202 ( V_49 ) ;
V_333:
F_102 ( V_49 ) ;
return NULL ;
}
struct V_4 * F_210 ( struct V_48 * V_49 ,
struct V_1 * V_7 ,
enum V_340 V_341 )
{
struct V_10 * V_11 ;
struct V_4 * V_47 ;
struct V_12 * V_26 ;
int V_342 ;
int V_44 = 0 ;
V_342 = ( sizeof( * V_47 ) + sizeof( struct V_12 ) ) ;
V_11 = F_211 ( & V_7 -> V_111 , & V_343 ,
V_342 ) ;
if ( ! V_11 ) {
F_69 (KERN_ERR PFX L_48 ) ;
return NULL ;
}
V_26 = F_6 ( V_11 ) ;
V_47 = F_10 ( V_26 ) ;
F_212 ( V_7 ) ;
F_213 ( & V_47 -> V_325 ) ;
V_47 -> V_49 = V_49 ;
V_47 -> V_7 = V_7 ;
F_214 ( V_26 , V_341 ) ;
V_26 -> V_344 = F_156 ;
V_26 -> V_345 = F_154 ;
V_26 -> V_346 = F_155 ;
F_119 ( V_326 , & V_47 -> V_327 ) ;
V_44 = F_179 ( V_47 ) ;
if ( ! V_44 )
return V_47 ;
F_193 ( V_26 ) ;
F_195 ( V_7 ) ;
F_194 ( V_11 ) ;
return NULL ;
}
static struct V_2 * F_164 ( struct V_4 * V_47 ,
struct V_195 * V_347 , int V_348 )
{
struct V_12 * V_26 = F_36 ( V_47 ) ;
struct V_2 * V_3 , * V_298 ;
struct V_5 * V_46 ;
struct V_168 * V_169 ;
struct V_296 * V_204 = F_215 ( V_347 ) ;
struct V_306 * V_307 ;
struct V_48 * V_49 ;
int V_44 = 0 ;
V_307 = F_204 ( sizeof( struct V_306 ) , V_332 ) ;
if ( ! V_307 ) {
F_38 ( V_26 -> V_14 , L_49 ) ;
return NULL ;
}
if ( ! V_348 )
V_3 = F_216 ( & V_349 , sizeof( * V_46 ) ) ;
else
V_3 = F_217 ( V_204 , sizeof( * V_46 ) ) ;
if ( ! V_3 ) {
F_69 (KERN_ERR PFX L_50 ) ;
goto V_350;
}
V_169 = V_3 -> V_196 ;
V_46 = F_2 ( V_3 ) ;
V_46 -> V_3 = V_3 ;
V_46 -> V_6 = V_47 ;
F_218 ( & V_46 -> V_313 , V_351 ) ;
V_44 = F_149 ( V_3 ) ;
if ( V_44 )
goto V_352;
if ( V_348 ) {
F_69 (KERN_ERR PFX L_51 ,
vport->node_name, vport->port_name) ;
F_127 ( V_3 , V_204 -> V_353 ) ;
F_128 ( V_3 , V_204 -> V_300 ) ;
}
V_44 = F_121 ( V_3 , V_47 -> V_7 ) ;
if ( V_44 ) {
F_69 (KERN_ERR PFX L_52 ) ;
goto V_352;
}
V_44 = F_109 ( V_3 , V_347 ) ;
if ( V_44 ) {
F_69 (KERN_ERR PFX L_53 ,
interface->netdev->name) ;
goto V_352;
}
V_44 = F_142 ( V_3 ) ;
if ( V_44 ) {
F_69 (KERN_ERR PFX L_54 ) ;
goto V_354;
}
F_136 ( V_3 -> V_196 ) = V_261 ;
if ( ! V_348 )
V_44 = F_147 ( V_3 ) ;
else {
V_169 = F_160 ( V_204 ) ;
V_298 = F_104 ( V_169 ) ;
V_44 = F_219 ( V_298 , V_3 ) ;
}
if ( V_44 ) {
F_69 (KERN_ERR PFX L_55 ) ;
goto V_354;
}
F_197 ( V_47 ) ;
V_49 = V_47 -> V_49 ;
F_12 ( & V_49 -> V_55 ) ;
V_307 -> V_3 = V_3 ;
F_220 ( & V_307 -> V_34 , & V_49 -> V_339 ) ;
F_16 ( & V_49 -> V_55 ) ;
return V_3 ;
V_354:
F_221 ( V_169 ) ;
V_352:
F_222 ( V_3 -> V_196 ) ;
V_350:
F_102 ( V_307 ) ;
return NULL ;
}
static void F_223 ( struct V_4 * V_47 )
{
F_224 ( & V_47 -> V_137 ) ;
F_224 ( & V_47 -> V_294 ) ;
F_225 () ;
}
static void F_226 ( struct V_4 * V_47 )
{
struct V_12 * V_26 = F_36 ( V_47 ) ;
struct V_2 * V_3 = V_26 -> V_14 ;
struct V_5 * V_46 = F_2 ( V_3 ) ;
struct V_48 * V_49 = V_47 -> V_49 ;
F_227 ( & V_46 -> V_239 ) ;
F_137 ( V_3 ) ;
F_223 ( V_47 ) ;
F_171 ( V_49 , V_3 ) ;
}
static void F_228 ( struct V_2 * V_3 )
{
F_11 ( V_3 ) ;
F_229 ( V_3 -> V_196 ) ;
F_221 ( V_3 -> V_196 ) ;
F_230 ( V_3 ) ;
F_231 ( V_3 ) ;
F_222 ( V_3 -> V_196 ) ;
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
F_176 ( V_312 , & V_46 -> V_313 ) ;
}
static int F_233 ( struct V_1 * V_7 )
{
struct V_4 * V_47 = NULL ;
struct V_355 * V_356 ;
struct V_12 * V_26 ;
int V_44 = 0 ;
F_163 () ;
F_24 ( & V_257 ) ;
V_47 = F_234 ( V_7 ) ;
V_26 = F_36 ( V_47 ) ;
if ( ! V_47 || ! V_26 -> V_14 ) {
V_44 = - V_76 ;
F_69 (KERN_ERR PFX L_56 ) ;
goto V_357;
}
V_356 = V_47 -> V_356 ;
F_132 ( V_47 ) ;
F_235 ( V_356 ) ;
V_357:
F_27 ( & V_257 ) ;
F_165 () ;
return V_44 ;
}
static void V_351 ( struct V_358 * V_162 )
{
struct V_5 * V_46 ;
struct V_2 * V_3 ;
V_46 = F_68 ( V_162 , struct V_5 , V_313 ) ;
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
goto V_359;
if ( F_241 ( V_49 ) )
goto V_359;
return 0 ;
V_359:
F_236 ( V_49 ) ;
return - V_77 ;
}
static int F_207 ( struct V_48 * V_49 )
{
struct V_330 * V_331 ;
if ( ! V_49 -> V_331 ) {
F_69 (KERN_ERR PFX L_58 ) ;
return - V_76 ;
}
V_331 = V_49 -> V_331 ;
V_49 -> V_360 = V_331 -> V_360 ;
if ( V_49 -> V_360 )
F_242 ( V_49 -> V_360 ) ;
return 0 ;
}
static void F_202 ( struct V_48 * V_49 )
{
if ( V_49 -> V_360 )
F_243 ( V_49 -> V_360 ) ;
V_49 -> V_360 = NULL ;
}
static void F_244 ( void * V_361 )
{
struct V_48 * V_49 = V_361 ;
struct V_4 * V_47 ;
struct V_12 * V_26 ;
struct V_2 * V_3 ;
F_24 ( & V_257 ) ;
if ( ! F_45 ( V_301 , & V_49 -> V_97 ) )
F_245 ( V_49 ) ;
F_23 ( L_59 ) ;
F_133 (interface, &if_list, list) {
if ( V_47 -> V_49 == V_49 ) {
V_26 = F_36 ( V_47 ) ;
V_3 = V_26 -> V_14 ;
F_69 (KERN_ERR PFX L_60 ) ;
V_3 -> V_267 . V_362 = F_35 ;
F_246 ( V_47 ) ;
}
}
F_27 ( & V_257 ) ;
}
static void F_174 ( struct V_2 * V_3 )
{
F_23 ( L_1 , V_53 ) ;
F_178 ( V_3 ) ;
F_247 ( V_3 ) ;
}
static void F_232 ( struct V_4 * V_47 )
{
struct V_12 * V_26 = F_36 ( V_47 ) ;
struct V_2 * V_3 ;
struct V_2 * V_204 ;
if ( ! F_45 ( V_301 , & V_47 -> V_49 -> V_97 ) )
return;
V_3 = V_26 -> V_14 ;
F_174 ( V_3 ) ;
F_24 ( & V_3 -> V_260 ) ;
F_133 (vport, &lport->vports, list)
F_136 ( V_204 -> V_196 ) =
V_261 ;
F_27 ( & V_3 -> V_260 ) ;
F_136 ( V_3 -> V_196 ) = V_261 ;
F_135 ( V_26 ) ;
F_137 ( V_3 ) ;
}
static int F_245 ( struct V_48 * V_49 )
{
#define F_248 (1000 / HZ)
int V_44 = - 1 ;
int V_52 = V_175 ;
V_44 = F_239 ( V_49 ) ;
if ( V_44 ) {
F_69 (KERN_ALERT PFX
L_61 , rc) ;
goto V_363;
}
V_44 = F_249 ( V_49 ) ;
if ( V_44 ) {
F_69 (KERN_ALERT PFX
L_62 , rc) ;
goto V_364;
}
while ( ! F_45 ( V_251 , & V_49 -> V_229 ) && V_52 -- )
F_250 ( F_248 ) ;
if ( ! F_45 ( V_251 , & V_49 -> V_229 ) ) {
F_69 (KERN_ERR PFX L_63
L_64 ,
hba->cnic->netdev->name) ;
V_44 = - 1 ;
goto V_364;
}
F_119 ( V_301 , & V_49 -> V_97 ) ;
return 0 ;
V_364:
F_236 ( V_49 ) ;
V_363:
return V_44 ;
}
static void F_251 ( struct V_48 * V_49 )
{
if ( F_192 ( V_301 , & V_49 -> V_97 ) ) {
if ( F_252 ( V_49 ) == 0 ) {
F_253 ( & V_49 -> V_365 ) ;
V_49 -> V_365 . V_366 = V_367 +
V_305 ;
V_49 -> V_365 . V_368 = F_129 ;
V_49 -> V_365 . V_157 = ( unsigned long ) V_49 ;
F_254 ( & V_49 -> V_365 ) ;
F_139 ( V_49 -> V_244 ,
F_45 ( V_243 ,
& V_49 -> V_97 ) ) ;
F_118 ( V_243 , & V_49 -> V_97 ) ;
if ( F_140 ( V_143 ) )
F_141 ( V_143 ) ;
F_227 ( & V_49 -> V_365 ) ;
}
F_236 ( V_49 ) ;
}
}
static void F_255 ( void * V_361 )
{
struct V_48 * V_49 = V_361 ;
struct V_4 * V_47 ;
F_69 ( V_252 L_65 ) ;
F_24 ( & V_257 ) ;
if ( ! F_45 ( V_301 , & V_49 -> V_97 ) )
goto exit;
F_133 (interface, &if_list, list) {
if ( V_47 -> V_49 == V_49 )
F_232 ( V_47 ) ;
}
F_256 ( V_49 -> V_265 != 0 ) ;
F_24 ( & V_49 -> V_54 ) ;
F_118 ( V_251 , & V_49 -> V_229 ) ;
F_118 ( V_254 ,
& V_49 -> V_229 ) ;
F_118 ( V_263 , & V_49 -> V_229 ) ;
F_27 ( & V_49 -> V_54 ) ;
F_251 ( V_49 ) ;
exit:
F_27 ( & V_257 ) ;
}
static void F_246 ( struct V_4 * V_47 )
{
struct V_12 * V_26 = F_36 ( V_47 ) ;
struct V_2 * V_3 ;
int V_369 = 0 ;
F_23 ( L_1 , V_53 ) ;
if ( ! F_45 ( V_301 , & V_47 -> V_49 -> V_97 ) ) {
F_69 (KERN_ERR PFX L_66 ) ;
return;
}
V_3 = V_26 -> V_14 ;
F_38 ( V_3 , L_67 ) ;
if ( ! F_116 ( V_3 ) && V_47 -> V_259 ) {
F_38 ( V_3 , L_68 ) ;
F_134 ( V_26 ) ;
F_136 ( V_3 -> V_196 ) = V_370 ;
F_119 ( V_263 , & V_47 -> V_49 -> V_229 ) ;
}
while ( ! V_26 -> V_93 ) {
F_250 ( 250 ) ;
if ( ++ V_369 > 12 )
break;
}
if ( F_122 ( V_3 , V_237 ) )
return;
F_168 ( V_3 ) ;
F_169 ( V_3 ) ;
}
static void F_257 ( struct V_330 * V_111 )
{
struct V_48 * V_49 ;
int V_44 = 0 ;
F_23 ( L_1 , V_53 ) ;
if ( ! F_45 ( V_371 , & V_111 -> V_97 ) ||
( V_111 -> V_372 == 0 ) ) {
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
F_24 ( & V_257 ) ;
F_220 ( & V_49 -> V_34 , & V_373 ) ;
V_374 ++ ;
F_27 ( & V_257 ) ;
F_118 ( V_375 , & V_49 -> V_376 ) ;
V_44 = V_111 -> V_377 ( V_111 , V_378 ,
( void * ) V_49 ) ;
if ( V_44 )
F_69 (KERN_ERR PFX L_72 , rc) ;
else
F_119 ( V_375 , & V_49 -> V_376 ) ;
}
static int F_258 ( struct V_1 * V_7 )
{
struct V_4 * V_47 ;
struct V_12 * V_26 ;
int V_44 = 0 ;
F_163 () ;
F_24 ( & V_257 ) ;
V_47 = F_234 ( V_7 ) ;
V_26 = F_36 ( V_47 ) ;
if ( ! V_47 || ! V_26 -> V_14 ) {
V_44 = - V_76 ;
F_69 (KERN_ERR PFX L_73 ) ;
} else {
V_47 -> V_259 = false ;
F_135 ( V_26 ) ;
F_137 ( V_26 -> V_14 ) ;
}
F_27 ( & V_257 ) ;
F_165 () ;
return V_44 ;
}
static int F_259 ( struct V_1 * V_7 )
{
struct V_4 * V_47 ;
struct V_12 * V_26 ;
int V_44 = 0 ;
F_163 () ;
F_24 ( & V_257 ) ;
V_47 = F_234 ( V_7 ) ;
V_26 = F_36 ( V_47 ) ;
if ( ! V_47 || ! V_26 -> V_14 ) {
V_44 = - V_76 ;
F_69 (KERN_ERR PFX L_74 ) ;
} else if ( ! F_116 ( V_26 -> V_14 ) ) {
F_134 ( V_26 ) ;
V_47 -> V_259 = true ;
}
F_27 ( & V_257 ) ;
F_165 () ;
return V_44 ;
}
static int F_260 ( struct V_1 * V_7 , enum V_340 V_341 )
{
struct V_12 * V_26 ;
struct V_4 * V_47 ;
struct V_48 * V_49 ;
struct V_1 * V_226 ;
struct V_2 * V_3 ;
struct V_379 V_380 ;
int V_44 = 0 ;
int V_28 ;
F_23 ( L_75 ) ;
if ( V_341 != V_381 ) {
F_69 ( V_252 L_76 ) ;
return - V_302 ;
}
F_163 () ;
F_24 ( & V_257 ) ;
if ( ! F_261 ( V_328 ) ) {
V_44 = - V_94 ;
goto V_382;
}
if ( V_7 -> V_383 & V_384 ) {
V_226 = F_262 ( V_7 ) ;
V_28 = F_263 ( V_7 ) ;
} else {
F_69 (KERN_ERR PFX L_77 ) ;
V_44 = - V_94 ;
goto V_357;
}
if ( V_226 -> V_234 && V_226 -> V_234 -> V_385 ) {
memset ( & V_380 , 0 , sizeof( V_380 ) ) ;
V_226 -> V_234 -> V_385 ( V_226 , & V_380 ) ;
if ( strncmp ( V_380 . V_386 , L_78 , strlen ( L_78 ) ) ) {
F_69 (KERN_ERR PFX L_79 ) ;
V_44 = - V_94 ;
goto V_357;
}
} else {
F_69 (KERN_ERR PFX L_80 ) ;
V_44 = - V_94 ;
goto V_357;
}
V_49 = F_264 ( V_226 ) ;
if ( ! V_49 ) {
V_44 = - V_76 ;
F_69 (KERN_ERR PFX L_81 ) ;
goto V_357;
}
if ( F_234 ( V_7 ) ) {
V_44 = - V_387 ;
goto V_357;
}
V_47 = F_210 ( V_49 , V_7 , V_341 ) ;
if ( ! V_47 ) {
F_69 (KERN_ERR PFX L_82 ) ;
goto V_388;
}
V_26 = F_36 ( V_47 ) ;
V_47 -> V_28 = V_28 ;
V_47 -> V_389 = 1 ;
V_47 -> V_356 =
F_265 ( L_83 ) ;
if ( ! V_47 -> V_356 ) {
F_69 (KERN_ERR PFX L_84 ) ;
V_44 = - V_94 ;
goto V_388;
}
V_3 = F_164 ( V_47 , & V_47 -> V_49 -> V_360 -> V_111 , 0 ) ;
if ( ! V_3 ) {
F_69 (KERN_ERR PFX L_85 ,
netdev->name) ;
V_44 = - V_94 ;
goto V_390;
}
F_220 ( & V_47 -> V_34 , & V_391 ) ;
V_3 -> V_304 = V_305 ;
V_26 -> V_14 = V_3 ;
if ( ! F_116 ( V_3 ) ) {
F_134 ( V_26 ) ;
F_136 ( V_3 -> V_196 ) = V_370 ;
F_119 ( V_263 , & V_47 -> V_49 -> V_229 ) ;
}
F_38 ( V_3 , L_86 ) ;
F_246 ( V_47 ) ;
V_47 -> V_259 = true ;
F_175 ( V_47 ) ;
F_27 ( & V_257 ) ;
F_165 () ;
return 0 ;
V_390:
F_235 ( V_47 -> V_356 ) ;
V_388:
F_223 ( V_47 ) ;
F_175 ( V_47 ) ;
goto V_382;
V_357:
F_196 ( V_328 ) ;
V_382:
F_27 ( & V_257 ) ;
F_165 () ;
return V_44 ;
}
static struct V_48 * F_266 ( struct V_330 * V_331 )
{
struct V_392 * V_34 ;
struct V_392 * V_393 ;
struct V_48 * V_49 ;
F_267 (list, temp, &adapter_list) {
V_49 = (struct V_48 * ) V_34 ;
if ( V_49 -> V_331 == V_331 )
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
* V_226 )
{
struct V_48 * V_49 ;
F_133 (hba, &adapter_list, list) {
if ( V_49 -> V_226 == V_226 )
return V_49 ;
}
F_69 (KERN_ERR PFX L_87 ) ;
return NULL ;
}
static void F_268 ( struct V_330 * V_111 )
{
struct V_48 * V_49 ;
struct V_4 * V_47 , * V_163 ;
F_23 ( L_88 ) ;
if ( ! F_45 ( V_371 , & V_111 -> V_97 ) ) {
F_69 (KERN_ERR PFX L_89 ,
dev->netdev->name, dev->flags) ;
return;
}
F_24 ( & V_257 ) ;
V_49 = F_266 ( V_111 ) ;
if ( ! V_49 ) {
F_69 (KERN_ERR PFX L_90 ,
dev) ;
F_27 ( & V_257 ) ;
return;
}
F_100 ( & V_49 -> V_34 ) ;
V_374 -- ;
F_99 (interface, tmp, &if_list, list)
if ( V_47 -> V_49 == V_49 )
F_132 ( V_47 ) ;
F_27 ( & V_257 ) ;
F_255 ( V_49 ) ;
if ( F_192 ( V_375 , & V_49 -> V_376 ) )
V_49 -> V_331 -> V_394 ( V_49 -> V_331 , V_378 ) ;
F_200 ( V_49 ) ;
}
static int F_269 ( struct V_168 * V_169 )
{
struct V_2 * V_3 = F_104 ( V_169 ) ;
F_270 ( V_3 ) ;
return 0 ;
}
static bool F_271 ( struct V_1 * V_7 )
{
F_24 ( & V_257 ) ;
if ( V_7 -> V_383 & V_384 ) {
struct V_1 * V_226 = F_262 ( V_7 ) ;
if ( F_264 ( V_226 ) ) {
F_27 ( & V_257 ) ;
return true ;
}
}
F_27 ( & V_257 ) ;
return false ;
}
static void F_272 ( unsigned int V_395 )
{
struct V_159 * V_160 ;
struct V_396 * V_141 ;
V_160 = & F_273 ( V_397 , V_395 ) ;
V_141 = F_274 ( F_95 ,
( void * ) V_160 ,
L_91 , V_395 ) ;
if ( F_275 ( ! F_166 ( V_141 ) ) ) {
F_276 ( V_141 , V_395 ) ;
V_160 -> V_398 = V_141 ;
F_74 ( V_141 ) ;
}
}
static void F_277 ( unsigned int V_395 )
{
struct V_159 * V_160 ;
struct V_396 * V_141 ;
struct V_161 * V_162 , * V_163 ;
F_23 ( L_92 , V_395 ) ;
V_160 = & F_273 ( V_397 , V_395 ) ;
F_12 ( & V_160 -> V_165 ) ;
V_141 = V_160 -> V_398 ;
V_160 -> V_398 = NULL ;
F_99 (work, tmp, &p->work_list, list) {
F_100 ( & V_162 -> V_34 ) ;
F_101 ( V_162 -> V_51 , V_162 -> V_166 ) ;
F_102 ( V_162 ) ;
}
F_16 ( & V_160 -> V_165 ) ;
if ( V_141 )
F_278 ( V_141 ) ;
}
static int F_279 ( struct V_399 * V_400 ,
unsigned long V_401 , void * V_402 )
{
unsigned V_395 = ( unsigned long ) V_402 ;
switch ( V_401 ) {
case V_403 :
case V_404 :
F_69 ( V_405 L_93 , V_395 ) ;
F_272 ( V_395 ) ;
break;
case V_406 :
case V_407 :
F_69 ( V_405 L_94 , V_395 ) ;
F_277 ( V_395 ) ;
break;
default:
break;
}
return V_408 ;
}
static int T_6 F_280 ( void )
{
struct V_29 * V_30 ;
struct V_396 * V_409 ;
int V_44 = 0 ;
unsigned int V_395 = 0 ;
struct V_159 * V_160 ;
F_69 (KERN_INFO PFX L_95 , version) ;
V_44 = F_281 ( & V_410 ) ;
if ( V_44 ) {
F_69 ( V_252 L_96
L_97 ) ;
goto V_411;
}
F_209 ( & V_373 ) ;
F_209 ( & V_391 ) ;
F_206 ( & V_257 ) ;
V_374 = 0 ;
V_44 = F_186 () ;
if ( V_44 )
goto V_412;
V_312 = F_282 ( L_98 , 0 , 0 ) ;
if ( ! V_312 ) {
V_44 = - V_77 ;
goto V_413;
}
V_30 = & V_39 ;
F_123 ( & V_30 -> V_40 ) ;
V_409 = F_274 ( F_75 ,
( void * ) V_30 ,
L_99 ) ;
if ( F_166 ( V_409 ) ) {
V_44 = F_283 ( V_409 ) ;
goto V_414;
}
F_74 ( V_409 ) ;
F_12 ( & V_30 -> V_40 . V_41 ) ;
V_30 -> V_141 = V_409 ;
F_16 ( & V_30 -> V_40 . V_41 ) ;
F_284 (cpu) {
V_160 = & F_273 ( V_397 , V_395 ) ;
F_209 ( & V_160 -> V_164 ) ;
F_205 ( & V_160 -> V_165 ) ;
}
F_285 (cpu) {
F_272 ( V_395 ) ;
}
F_286 ( & V_415 ) ;
F_287 ( V_378 , & V_416 ) ;
return 0 ;
V_414:
F_235 ( V_312 ) ;
V_413:
F_189 () ;
V_412:
F_288 ( & V_410 ) ;
V_411:
return V_44 ;
}
static void T_7 F_289 ( void )
{
F_96 ( V_417 ) ;
struct V_48 * V_49 , * V_37 ;
struct V_29 * V_30 ;
struct V_396 * V_409 ;
struct V_35 * V_36 ;
unsigned int V_395 = 0 ;
F_24 ( & V_257 ) ;
F_290 ( & V_373 , & V_417 ) ;
F_209 ( & V_373 ) ;
V_374 = 0 ;
F_27 ( & V_257 ) ;
F_99 (hba, next, &to_be_deleted, list) {
F_100 ( & V_49 -> V_34 ) ;
F_69 (KERN_ERR PFX L_100 ,
hba) ;
F_255 ( V_49 ) ;
if ( F_192 ( V_375 ,
& V_49 -> V_376 ) )
V_49 -> V_331 -> V_394 ( V_49 -> V_331 ,
V_378 ) ;
F_200 ( V_49 ) ;
}
F_291 ( V_378 ) ;
V_30 = & V_39 ;
F_12 ( & V_30 -> V_40 . V_41 ) ;
V_409 = V_30 -> V_141 ;
V_30 -> V_141 = NULL ;
while ( ( V_36 = F_80 ( & V_30 -> V_40 ) ) != NULL )
F_15 ( V_36 ) ;
F_16 ( & V_30 -> V_40 . V_41 ) ;
if ( V_409 )
F_278 ( V_409 ) ;
F_292 ( & V_415 ) ;
F_285 (cpu) {
F_277 ( V_395 ) ;
}
F_235 ( V_312 ) ;
F_189 () ;
F_288 ( & V_410 ) ;
}
