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
unsigned short V_123 ;
V_35 = F_64 ( V_121 , struct V_4 ,
V_124 ) ;
V_13 = F_32 ( V_35 ) ;
V_3 = V_13 -> V_16 ;
if ( F_35 ( V_3 == NULL ) ) {
F_65 (KERN_ERR PFX L_12 ) ;
goto V_125;
}
if ( F_35 ( F_54 ( V_24 ) -> V_100 != F_53 ( V_98 ) ) ) {
F_65 (KERN_ERR PFX L_13 ) ;
goto V_125;
}
if ( F_35 ( ( V_24 -> V_86 < V_126 ) ||
! F_66 ( V_24 , V_127 ) ) )
goto V_125;
F_67 ( V_24 , sizeof( struct V_70 ) ) ;
V_51 = (struct V_50 * ) F_68 ( V_24 ) ;
V_123 = F_26 ( V_51 -> V_54 ) ;
V_20 = F_9 ( V_24 ) ;
V_20 -> V_30 = V_3 ;
V_18 = & V_27 ;
F_14 ( & V_18 -> V_28 . V_29 ) ;
F_69 ( & V_18 -> V_28 , V_24 ) ;
if ( V_18 -> V_28 . V_119 == 1 )
F_70 ( V_18 -> V_128 ) ;
F_16 ( & V_18 -> V_28 . V_29 ) ;
return 0 ;
V_125:
F_11 ( V_24 ) ;
return - 1 ;
}
static int F_71 ( void * V_129 )
{
struct V_17 * V_18 = V_129 ;
struct V_23 * V_24 ;
F_72 ( V_130 , V_131 ) ;
F_73 ( V_132 ) ;
while ( ! F_74 () ) {
F_75 () ;
F_8 ( & V_18 -> V_28 . V_29 ) ;
while ( ( V_24 = F_76 ( & V_18 -> V_28 ) ) != NULL ) {
F_12 ( & V_18 -> V_28 . V_29 ) ;
F_77 ( V_24 ) ;
F_8 ( & V_18 -> V_28 . V_29 ) ;
}
F_78 ( V_132 ) ;
F_12 ( & V_18 -> V_28 . V_29 ) ;
}
F_78 ( V_133 ) ;
return 0 ;
}
static void F_77 ( struct V_23 * V_24 )
{
T_2 V_134 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_72 * V_73 ;
struct V_50 * V_51 ;
struct V_68 V_135 ;
struct V_46 * V_47 ;
struct V_2 * V_136 ;
struct V_5 * V_34 ;
T_1 * V_137 = NULL ;
T_1 * V_138 = NULL ;
struct V_70 * V_71 ;
V_20 = F_9 ( V_24 ) ;
V_3 = V_20 -> V_30 ;
if ( F_35 ( V_3 == NULL ) ) {
F_65 (KERN_ERR PFX L_14 ) ;
F_11 ( V_24 ) ;
return;
}
if ( F_43 ( V_24 ) )
F_79 ( V_24 ) ;
V_137 = F_54 ( V_24 ) -> V_107 ;
V_138 = F_54 ( V_24 ) -> V_102 ;
V_71 = (struct V_70 * ) F_80 ( V_24 ) ;
V_51 = (struct V_50 * ) F_68 ( V_24 ) ;
F_81 ( V_24 , sizeof( struct V_70 ) ) ;
V_134 = V_24 -> V_86 - sizeof( struct V_68 ) ;
V_47 = (struct V_46 * ) V_24 ;
F_82 ( V_47 ) ;
V_30 ( V_47 ) = V_3 ;
F_37 ( V_47 ) = V_71 -> V_111 ;
if ( F_83 ( V_24 , V_134 , & V_135 , sizeof( V_135 ) ) ) {
F_11 ( V_24 ) ;
return;
}
F_38 ( V_47 ) = V_135 . V_94 ;
F_84 ( V_47 ) = V_135 . V_95 ;
if ( F_85 ( V_24 , V_134 ) ) {
F_11 ( V_24 ) ;
return;
}
V_51 = F_25 ( V_47 ) ;
V_136 = F_86 ( V_3 , F_40 ( V_51 -> V_83 ) ) ;
if ( V_136 ) {
V_34 = F_2 ( V_136 ) ;
if ( ! F_87 ( V_34 -> V_109 , V_138 ) ) {
F_34 ( V_3 , L_15 ) ;
F_11 ( V_24 ) ;
return;
}
}
if ( V_51 -> V_55 == V_139 &&
V_51 -> V_56 == V_140 ) {
F_11 ( V_24 ) ;
return;
}
if ( V_51 -> V_55 == V_58 &&
V_51 -> V_56 == V_57 ) {
switch ( F_27 ( V_47 ) ) {
case V_60 :
if ( F_40 ( V_51 -> V_141 ) == V_142 ) {
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
V_73 = F_58 ( V_3 -> V_73 , F_88 () ) ;
V_73 -> V_143 ++ ;
V_73 -> V_144 += V_134 / V_87 ;
if ( F_89 ( F_84 ( V_47 ) ) !=
~ F_90 ( ~ 0 , V_24 -> V_145 , V_134 ) ) {
if ( V_73 -> V_146 < 5 )
F_65 (KERN_WARNING PFX L_16
L_17 ) ;
V_73 -> V_146 ++ ;
F_11 ( V_24 ) ;
return;
}
F_91 ( V_3 , V_47 ) ;
}
int F_92 ( void * V_129 )
{
struct V_147 * V_148 = V_129 ;
struct V_149 * V_150 , * V_151 ;
F_93 ( V_152 ) ;
F_72 ( V_130 , V_131 ) ;
F_73 ( V_132 ) ;
while ( ! F_74 () ) {
F_75 () ;
F_8 ( & V_148 -> V_153 ) ;
while ( ! F_94 ( & V_148 -> V_152 ) ) {
F_95 ( & V_148 -> V_152 , & V_152 ) ;
F_12 ( & V_148 -> V_153 ) ;
F_96 (work, tmp, &work_list, list) {
F_97 ( & V_150 -> V_22 ) ;
F_98 ( V_150 -> V_39 , V_150 -> V_154 ) ;
F_99 ( V_150 ) ;
}
F_8 ( & V_148 -> V_153 ) ;
}
F_78 ( V_132 ) ;
F_12 ( & V_148 -> V_153 ) ;
}
F_78 ( V_133 ) ;
return 0 ;
}
static struct V_155 * F_100 ( struct V_156 * V_157 )
{
struct V_155 * V_158 ;
struct V_2 * V_3 = F_101 ( V_157 ) ;
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_159 * V_160 ;
int V_32 = 0 ;
V_160 = (struct V_159 * ) V_37 -> V_161 ;
if ( ! V_160 )
return NULL ;
V_158 = F_102 ( V_157 ) ;
F_103 ( & V_37 -> V_162 ) ;
if ( F_104 ( V_37 ) )
return V_158 ;
V_32 = F_105 ( & V_37 -> V_162 , ( 2 * V_163 ) ) ;
if ( ! V_32 ) {
F_34 ( V_3 , L_18 ) ;
return V_158 ;
}
F_106 ( V_37 , V_164 , V_165 ) ;
V_158 -> V_166 += V_37 -> V_167 . V_165 ;
F_106 ( V_37 , V_168 , V_169 ) ;
V_158 -> V_170 += V_37 -> V_167 . V_169 ;
F_106 ( V_37 , V_168 , V_171 ) ;
V_158 -> V_172 += ( ( V_37 -> V_167 . V_171 ) / 4 ) ;
F_106 ( V_37 , V_173 , V_174 ) ;
V_158 -> V_175 += V_37 -> V_167 . V_174 ;
F_106 ( V_37 , V_173 , V_176 ) ;
V_158 -> V_177 += ( ( V_37 -> V_167 . V_176 ) / 4 ) ;
V_158 -> V_178 = 0 ;
V_158 -> V_179 = 0 ;
V_158 -> V_180 = 0 ;
V_158 -> V_181 = 0 ;
V_158 -> V_182 = 0 ;
V_158 -> V_183 = 0 ;
memcpy ( & V_37 -> V_184 , V_37 -> V_161 ,
sizeof( struct V_159 ) ) ;
return V_158 ;
}
static int F_107 ( struct V_2 * V_3 , struct V_185 * V_99 )
{
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_156 * V_157 = V_3 -> V_186 ;
int V_32 = 0 ;
V_157 -> V_187 = V_188 ;
V_157 -> V_189 = V_190 ;
V_157 -> V_191 = V_192 ;
V_157 -> V_193 = 0 ;
if ( V_3 -> V_194 )
V_157 -> V_195 = V_196 ;
else
V_157 -> V_195 = V_197 ;
V_32 = F_108 ( V_3 -> V_186 , V_99 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_19 ) ;
return V_32 ;
}
if ( ! V_3 -> V_194 )
F_109 ( V_3 -> V_186 ) = V_198 ;
snprintf ( F_110 ( V_3 -> V_186 ) , 256 ,
L_20 ,
V_199 , V_37 -> V_200 , V_201 ,
V_35 -> V_7 -> V_202 ) ;
return 0 ;
}
static int F_111 ( struct V_2 * V_3 )
{
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_1 * V_99 = V_37 -> V_203 ;
int V_32 = 0 ;
if ( ( V_99 -> V_85 & V_204 ) && F_112 ( V_99 ) )
F_113 ( V_205 , & V_37 -> V_206 ) ;
else {
F_114 ( V_205 , & V_37 -> V_206 ) ;
V_32 = - 1 ;
}
return V_32 ;
}
void F_115 ( struct V_36 * V_37 )
{
if ( F_41 ( V_207 , & V_37 -> V_203 -> V_208 ) )
F_114 ( V_205 , & V_37 -> V_206 ) ;
else
F_113 ( V_205 , & V_37 -> V_206 ) ;
}
static int F_116 ( struct V_2 * V_3 , struct V_1 * V_7 )
{
struct V_36 * V_37 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
struct V_5 * V_34 ;
T_4 V_209 , V_210 ;
V_34 = F_2 ( V_3 ) ;
V_35 = V_34 -> V_6 ;
V_13 = F_32 ( V_35 ) ;
V_37 = V_35 -> V_37 ;
if ( ! V_37 -> V_203 -> V_211 ||
! V_37 -> V_203 -> V_211 -> V_212 )
return - V_213 ;
if ( F_117 ( V_3 , V_214 ) )
return - V_82 ;
F_118 ( & V_34 -> V_118 ) ;
V_34 -> V_215 = 0 ;
F_119 ( & V_34 -> V_216 , V_217 , ( unsigned long ) V_3 ) ;
F_120 ( V_3 ) ;
if ( ! V_3 -> V_194 ) {
if ( F_121 ( V_7 , & V_209 , V_218 ) )
V_209 = F_122 ( V_13 -> V_108 ,
1 , 0 ) ;
F_34 ( V_3 , L_21 , V_209 ) ;
F_123 ( V_3 , V_209 ) ;
if ( F_121 ( V_7 , & V_210 , V_219 ) )
V_210 = F_122 ( V_13 -> V_108 ,
2 , 0 ) ;
F_34 ( V_3 , L_22 , V_210 ) ;
F_124 ( V_3 , V_210 ) ;
}
return 0 ;
}
static void F_125 ( unsigned long V_145 )
{
struct V_36 * V_37 = (struct V_36 * ) V_145 ;
F_65 (KERN_ERR PFX L_23
L_24 ) ;
F_114 ( V_220 , & V_37 -> V_85 ) ;
F_126 ( & V_37 -> V_221 ) ;
}
static void F_127 ( void * V_222 , unsigned long V_223 ,
T_5 V_15 )
{
struct V_36 * V_37 = (struct V_36 * ) V_222 ;
struct V_10 * V_224 ;
struct V_2 * V_3 ;
struct V_2 * V_194 ;
struct V_4 * V_35 , * V_151 ;
struct V_12 * V_13 ;
int V_225 = 0 ;
T_2 V_226 = 1 ;
if ( V_15 != 0 && V_223 != V_227 )
return;
switch ( V_223 ) {
case V_228 :
if ( ! F_41 ( V_229 , & V_37 -> V_206 ) )
F_65 ( V_230 L_25\
L_26 ) ;
break;
case V_231 :
F_113 ( V_232 , & V_37 -> V_206 ) ;
F_113 ( V_229 , & V_37 -> V_206 ) ;
V_226 = 0 ;
break;
case V_233 :
F_114 ( V_232 , & V_37 -> V_206 ) ;
V_226 = 0 ;
break;
case V_234 :
break;
case V_227 :
if ( ! V_15 )
return;
F_20 ( & V_235 ) ;
F_96 (interface, tmp, &if_list, list) {
if ( V_35 -> V_37 == V_37 &&
V_35 -> V_15 == ( V_15 & V_236 ) )
F_128 ( V_35 ) ;
}
F_23 ( & V_235 ) ;
F_129 ( V_237 ) ;
return;
default:
F_65 (KERN_ERR PFX L_27 , event) ;
return;
}
F_20 ( & V_235 ) ;
F_130 (interface, &if_list, list) {
if ( V_35 -> V_37 != V_37 )
continue;
V_13 = F_32 ( V_35 ) ;
V_3 = V_13 -> V_16 ;
F_34 ( V_3 , L_28 ,
V_35 -> V_7 -> V_202 , V_223 ) ;
F_120 ( V_3 ) ;
V_224 = F_131 ( V_13 ) ;
if ( V_226 && ! F_111 ( V_3 ) ) {
switch ( V_224 -> V_238 ) {
case V_239 :
F_132 ( L_29 ) ;
break;
case V_240 :
case V_241 :
F_117 ( V_3 , V_214 ) ;
if ( V_35 -> V_238 )
F_133 ( V_13 ) ;
} ;
} else if ( F_134 ( V_13 ) ) {
switch ( V_224 -> V_238 ) {
case V_239 :
F_132 ( L_30 ) ;
break;
case V_240 :
case V_241 :
F_20 ( & V_3 -> V_242 ) ;
F_130 (vport, &lport->vports, list)
F_135 ( V_194 -> V_186 ) =
V_243 ;
F_23 ( & V_3 -> V_242 ) ;
F_135 ( V_3 -> V_186 ) =
V_243 ;
F_58 ( V_3 -> V_73 ,
F_59 () ) -> V_244 ++ ;
F_60 () ;
F_136 ( V_3 ) ;
V_225 = 1 ;
} ;
}
}
F_23 ( & V_235 ) ;
if ( V_225 ) {
F_113 ( V_245 , & V_37 -> V_206 ) ;
F_137 ( & V_37 -> V_246 ) ;
F_19 ( L_31
L_32 ,
V_37 -> V_247 ) ;
V_37 -> V_248 = 1 ;
F_138 ( V_37 -> V_246 ,
( V_37 -> V_247 == 0 ) ) ;
F_19 ( L_33 ,
V_37 -> V_247 ) ;
V_37 -> V_248 = 0 ;
if ( F_139 ( V_130 ) )
F_140 ( V_130 ) ;
}
}
static int F_141 ( struct V_2 * V_3 )
{
memcpy ( & V_3 -> V_249 , & V_250 ,
sizeof( struct V_251 ) ) ;
F_142 ( V_3 ) ;
F_143 ( V_3 ) ;
F_144 ( V_3 ) ;
F_145 ( V_3 ) ;
F_146 ( V_3 , V_3 ) ;
return 0 ;
}
static int F_147 ( struct V_2 * V_3 , struct V_36 * V_37 )
{
int V_252 , V_253 ;
V_252 = V_37 -> V_254 + 1 ;
if ( V_255 <= 2 )
V_253 = V_37 -> V_254 + V_256 ;
else
V_253 = V_37 -> V_254 + V_257 ;
if ( ! F_148 ( V_3 , V_258 , V_252 ,
V_253 , NULL ) ) {
F_65 (KERN_ERR PFX L_34 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_149 ( struct V_2 * V_3 )
{
V_3 -> V_80 = 0 ;
V_3 -> V_259 = 0 ;
V_3 -> V_260 = V_261 ;
V_3 -> V_262 = V_263 ;
V_3 -> V_264 = 2 * 1000 ;
V_3 -> V_265 = 10 * 1000 ;
V_3 -> V_266 = ( V_267 | V_268 |
V_269 | V_270 ) ;
V_3 -> V_271 = 1 ;
memset ( & V_3 -> V_272 , 0 , sizeof( struct V_273 ) ) ;
V_3 -> V_272 . V_274 = V_275 ;
if ( F_150 ( V_3 ) )
return - V_65 ;
F_151 ( V_3 ) ;
return 0 ;
}
static int F_152 ( struct V_23 * V_24 , struct V_1 * V_99 ,
struct V_120 * V_121 ,
struct V_1 * V_276 )
{
struct V_4 * V_35 ;
struct V_12 * V_13 ;
V_35 = F_64 ( V_121 , struct V_4 ,
V_277 ) ;
V_13 = F_32 ( V_35 ) ;
F_153 ( V_13 , V_24 ) ;
return 0 ;
}
static void F_154 ( struct V_2 * V_3 , T_1 * V_278 )
{
struct V_5 * V_34 = F_2 ( V_3 ) ;
memcpy ( V_34 -> V_109 , V_278 , V_104 ) ;
}
static T_1 * F_155 ( struct V_2 * V_3 )
{
struct V_5 * V_34 ;
V_34 = (struct V_5 * ) F_2 ( V_3 ) ;
return V_34 -> V_109 ;
}
static void F_156 ( struct V_12 * V_279 , struct V_23 * V_24 )
{
V_24 -> V_99 = F_157 ( V_279 ) -> V_7 ;
F_158 ( V_24 ) ;
}
static int F_159 ( struct V_280 * V_194 , bool V_281 )
{
struct V_156 * V_157 = F_160 ( V_194 ) ;
struct V_2 * V_282 = F_101 ( V_157 ) ;
struct V_5 * V_34 = F_2 ( V_282 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_1 * V_7 = V_35 -> V_7 ;
struct V_2 * V_136 ;
int V_32 ;
char V_283 [ 32 ] ;
V_32 = F_161 ( V_194 ) ;
if ( V_32 ) {
F_162 ( V_194 -> V_284 , V_283 , sizeof( V_283 ) ) ;
F_65 (KERN_ERR PFX L_35
L_36 ,
buf) ;
return V_32 ;
}
if ( ! F_41 ( V_285 , & V_35 -> V_37 -> V_85 ) ) {
F_65 (KERN_ERR PFX L_37
L_38 ) ;
return - V_286 ;
}
F_163 () ;
F_20 ( & V_235 ) ;
V_136 = F_164 ( V_35 , & V_194 -> V_99 , 1 ) ;
F_23 ( & V_235 ) ;
F_165 () ;
if ( F_166 ( V_136 ) ) {
F_65 (KERN_ERR PFX L_39 ,
netdev->name) ;
return - V_286 ;
}
if ( V_281 ) {
F_167 ( V_194 , V_287 ) ;
} else {
V_136 -> V_288 = V_289 ;
F_168 ( V_136 ) ;
F_169 ( V_136 ) ;
F_170 ( V_136 ) ;
}
return 0 ;
}
static void F_171 ( struct V_36 * V_37 , struct V_2 * V_3 )
{
struct V_290 * V_291 , * V_151 ;
F_8 ( & V_37 -> V_43 ) ;
F_96 (blport, tmp, &hba->vports, list) {
if ( V_291 -> V_3 == V_3 ) {
F_172 ( & V_291 -> V_22 ) ;
F_99 ( V_291 ) ;
}
}
F_12 ( & V_37 -> V_43 ) ;
}
static int F_173 ( struct V_280 * V_194 )
{
struct V_156 * V_157 = F_160 ( V_194 ) ;
struct V_2 * V_282 = F_101 ( V_157 ) ;
struct V_2 * V_136 = V_194 -> V_292 ;
struct V_5 * V_34 = F_2 ( V_136 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_2 * V_293 ;
bool V_294 = false ;
F_20 ( & V_282 -> V_242 ) ;
F_130 (v_port, &n_port->vports, list)
if ( V_293 -> V_194 == V_194 ) {
V_294 = true ;
break;
}
if ( ! V_294 ) {
F_23 ( & V_282 -> V_242 ) ;
return - V_295 ;
}
F_172 ( & V_136 -> V_22 ) ;
F_23 ( & V_282 -> V_242 ) ;
F_171 ( V_35 -> V_37 , V_34 -> V_3 ) ;
F_174 ( V_34 -> V_3 ) ;
F_175 ( V_35 ) ;
F_176 ( V_237 , & V_34 -> V_296 ) ;
return 0 ;
}
static int F_177 ( struct V_280 * V_194 , bool V_297 )
{
struct V_2 * V_3 = V_194 -> V_292 ;
if ( V_297 ) {
F_167 ( V_194 , V_287 ) ;
F_178 ( V_3 ) ;
} else {
V_3 -> V_288 = V_289 ;
F_169 ( V_3 ) ;
F_170 ( V_3 ) ;
}
return 0 ;
}
static int F_179 ( struct V_4 * V_35 )
{
struct V_1 * V_7 = V_35 -> V_7 ;
struct V_1 * V_298 = V_35 -> V_37 -> V_203 ;
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_299 * V_300 ;
int V_301 = 0 ;
F_180 () ;
F_181 (physdev, ha) {
F_19 ( L_40 ,
V_300 -> type ) ;
F_65 ( V_302 L_41 , V_300 -> V_278 [ 0 ] ,
V_300 -> V_278 [ 1 ] , V_300 -> V_278 [ 2 ] , V_300 -> V_278 [ 3 ] ,
V_300 -> V_278 [ 4 ] , V_300 -> V_278 [ 5 ] ) ;
if ( ( V_300 -> type == V_303 ) &&
( F_182 ( V_300 -> V_278 ) ) ) {
memcpy ( V_13 -> V_108 , V_300 -> V_278 ,
V_104 ) ;
V_301 = 1 ;
F_19 ( L_42 ) ;
}
}
F_183 () ;
if ( ! V_301 )
return - V_64 ;
V_35 -> V_277 . V_304 = F_152 ;
V_35 -> V_277 . type = F_53 ( V_305 ) ;
V_35 -> V_277 . V_99 = V_7 ;
F_184 ( & V_35 -> V_277 ) ;
V_35 -> V_124 . V_304 = F_63 ;
V_35 -> V_124 . type = F_185 ( V_98 ) ;
V_35 -> V_124 . V_99 = V_7 ;
F_184 ( & V_35 -> V_124 ) ;
return 0 ;
}
static int F_186 ( void )
{
V_197 =
F_187 ( & V_306 ) ;
if ( V_197 == NULL ) {
F_65 (KERN_ERR PFX L_43 ) ;
return - V_64 ;
}
V_196 =
F_187 ( & V_307 ) ;
if ( V_196 == NULL ) {
F_65 (KERN_ERR PFX
L_44 ) ;
F_188 ( V_197 ) ;
V_197 = NULL ;
return - V_64 ;
}
return 0 ;
}
static void F_189 ( void )
{
F_188 ( V_197 ) ;
F_188 ( V_196 ) ;
V_197 = NULL ;
V_196 = NULL ;
}
static void F_190 ( struct V_308 * V_308 )
{
struct V_10 * V_11 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
struct V_1 * V_7 ;
V_35 = F_64 ( V_308 , struct V_4 , V_308 ) ;
F_19 ( L_45 ) ;
V_13 = F_32 ( V_35 ) ;
V_11 = F_131 ( V_13 ) ;
V_7 = V_35 -> V_7 ;
if ( F_191 ( V_309 , & V_35 -> V_310 ) )
F_192 ( V_13 ) ;
F_193 ( V_11 ) ;
F_194 ( V_7 ) ;
F_195 ( V_311 ) ;
}
static inline void F_196 ( struct V_4 * V_35 )
{
F_197 ( & V_35 -> V_308 ) ;
}
static inline void F_175 ( struct V_4 * V_35 )
{
F_198 ( & V_35 -> V_308 , F_190 ) ;
}
static void F_199 ( struct V_36 * V_37 )
{
if ( V_37 -> V_312 ) {
F_200 ( V_37 -> V_312 ) ;
V_37 -> V_312 = NULL ;
}
F_99 ( V_37 -> V_45 ) ;
F_201 ( V_37 ) ;
F_99 ( V_37 ) ;
}
static struct V_36 * F_202 ( struct V_313 * V_314 )
{
struct V_36 * V_37 ;
struct V_315 * V_316 ;
int V_32 ;
V_37 = F_203 ( sizeof( * V_37 ) , V_317 ) ;
if ( ! V_37 ) {
F_65 (KERN_ERR PFX L_46 ) ;
return NULL ;
}
F_204 ( & V_37 -> V_43 ) ;
F_205 ( & V_37 -> V_42 ) ;
V_37 -> V_314 = V_314 ;
V_37 -> V_318 = V_314 -> V_319 ;
V_37 -> V_320 = ( V_37 -> V_318 / 2 ) ;
V_37 -> V_321 = V_37 -> V_320 ;
V_37 -> V_254 = ( V_37 -> V_318 - 1 ) ;
V_32 = F_206 ( V_37 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_47 ) ;
goto V_322;
}
V_37 -> V_203 = V_314 -> V_7 ;
V_37 -> V_323 = 0 ;
V_37 -> V_45 =
F_203 ( sizeof( struct V_38 * ) * V_44 ,
V_317 ) ;
if ( ! V_37 -> V_45 ) {
F_65 (KERN_ERR PFX L_48 ) ;
goto V_324;
}
V_37 -> V_247 = 0 ;
V_37 -> V_312 = F_207 ( V_37 ) ;
if ( ! V_37 -> V_312 ) {
F_65 (KERN_ERR PFX L_49 ) ;
goto V_325;
}
V_316 = & V_37 -> V_316 ;
V_316 -> V_326 = V_327 <<
V_328 ;
V_316 -> V_326 |= V_44 <<
V_329 ;
V_316 -> V_330 = V_37 -> V_321 <<
V_331 ;
V_316 -> V_330 |= V_332 <<
V_333 ;
V_316 -> V_334 = V_44 <<
V_335 ;
V_316 -> V_334 |= V_37 -> V_321 <<
V_336 ;
V_316 -> V_337 = V_338 ;
F_137 ( & V_37 -> V_246 ) ;
F_137 ( & V_37 -> V_221 ) ;
F_208 ( & V_37 -> V_339 ) ;
return V_37 ;
V_325:
F_99 ( V_37 -> V_45 ) ;
V_324:
F_201 ( V_37 ) ;
V_322:
F_99 ( V_37 ) ;
return NULL ;
}
struct V_4 * F_209 ( struct V_36 * V_37 ,
struct V_1 * V_7 ,
enum V_340 V_341 )
{
struct V_10 * V_11 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
int V_342 ;
int V_32 = 0 ;
V_342 = ( sizeof( * V_35 ) + sizeof( struct V_12 ) ) ;
V_11 = F_210 ( & V_7 -> V_99 , & V_343 ,
V_342 ) ;
if ( ! V_11 ) {
F_65 (KERN_ERR PFX L_50 ) ;
return NULL ;
}
V_13 = F_5 ( V_11 ) ;
V_13 -> V_224 = V_11 ;
V_35 = F_6 ( V_13 ) ;
F_211 ( V_7 ) ;
F_212 ( & V_35 -> V_308 ) ;
V_35 -> V_37 = V_37 ;
V_35 -> V_7 = V_7 ;
F_213 ( V_13 , V_341 ) ;
V_13 -> V_344 = F_156 ;
V_13 -> V_345 = F_154 ;
V_13 -> V_346 = F_155 ;
F_114 ( V_309 , & V_35 -> V_310 ) ;
V_32 = F_179 ( V_35 ) ;
if ( ! V_32 )
return V_35 ;
F_192 ( V_13 ) ;
F_194 ( V_7 ) ;
F_193 ( V_11 ) ;
return NULL ;
}
static struct V_2 * F_164 ( struct V_4 * V_35 ,
struct V_185 * V_347 , int V_348 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 , * V_282 ;
struct V_5 * V_34 ;
struct V_156 * V_157 ;
struct V_280 * V_194 = F_214 ( V_347 ) ;
struct V_290 * V_291 ;
struct V_36 * V_37 = V_35 -> V_37 ;
int V_32 = 0 ;
V_291 = F_203 ( sizeof( struct V_290 ) , V_317 ) ;
if ( ! V_291 ) {
F_34 ( V_13 -> V_16 , L_51 ) ;
return NULL ;
}
V_349 . V_350 = V_37 -> V_321 ;
if ( ! V_348 )
V_3 = F_215 ( & V_349 , sizeof( * V_34 ) ) ;
else
V_3 = F_216 ( V_194 , sizeof( * V_34 ) ) ;
if ( ! V_3 ) {
F_65 (KERN_ERR PFX L_52 ) ;
goto V_351;
}
V_157 = V_3 -> V_186 ;
V_34 = F_2 ( V_3 ) ;
V_34 -> V_3 = V_3 ;
V_34 -> V_6 = V_35 ;
V_34 -> V_352 = F_1 ;
F_217 ( & V_34 -> V_296 , V_353 ) ;
V_32 = F_149 ( V_3 ) ;
if ( V_32 )
goto V_354;
if ( V_348 ) {
F_65 (KERN_ERR PFX L_53 ,
vport->node_name, vport->port_name) ;
F_123 ( V_3 , V_194 -> V_355 ) ;
F_124 ( V_3 , V_194 -> V_284 ) ;
}
V_32 = F_116 ( V_3 , V_35 -> V_7 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_54 ) ;
goto V_354;
}
V_32 = F_107 ( V_3 , V_347 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_55 ,
interface->netdev->name) ;
goto V_354;
}
V_32 = F_141 ( V_3 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_56 ) ;
goto V_356;
}
F_135 ( V_3 -> V_186 ) = V_243 ;
if ( ! V_348 )
V_32 = F_147 ( V_3 , V_37 ) ;
else {
V_157 = F_160 ( V_194 ) ;
V_282 = F_101 ( V_157 ) ;
V_32 = F_218 ( V_282 , V_3 ) ;
}
if ( V_32 ) {
F_65 (KERN_ERR PFX L_57 ) ;
goto V_356;
}
F_196 ( V_35 ) ;
F_8 ( & V_37 -> V_43 ) ;
V_291 -> V_3 = V_3 ;
F_219 ( & V_291 -> V_22 , & V_37 -> V_339 ) ;
F_12 ( & V_37 -> V_43 ) ;
return V_3 ;
V_356:
F_220 ( V_157 ) ;
V_354:
F_221 ( V_3 -> V_186 ) ;
V_351:
F_99 ( V_291 ) ;
return NULL ;
}
static void F_222 ( struct V_4 * V_35 )
{
F_223 ( & V_35 -> V_124 ) ;
F_223 ( & V_35 -> V_277 ) ;
F_224 () ;
}
static void F_225 ( struct V_4 * V_35 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 = V_13 -> V_16 ;
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_36 * V_37 = V_35 -> V_37 ;
F_226 ( & V_34 -> V_216 ) ;
F_136 ( V_3 ) ;
F_222 ( V_35 ) ;
F_171 ( V_37 , V_3 ) ;
}
static void F_227 ( struct V_2 * V_3 )
{
F_7 ( V_3 ) ;
F_228 ( V_3 -> V_186 ) ;
F_220 ( V_3 -> V_186 ) ;
F_229 ( V_3 ) ;
F_230 ( V_3 ) ;
F_221 ( V_3 -> V_186 ) ;
}
static void F_128 ( struct V_4 * V_35 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 = V_13 -> V_16 ;
struct V_5 * V_34 = F_2 ( V_3 ) ;
F_225 ( V_35 ) ;
F_231 ( V_35 ) ;
F_172 ( & V_35 -> V_22 ) ;
F_175 ( V_35 ) ;
F_176 ( V_237 , & V_34 -> V_296 ) ;
}
static int F_232 ( struct V_1 * V_7 )
{
struct V_4 * V_35 = NULL ;
struct V_357 * V_358 ;
struct V_12 * V_13 ;
int V_32 = 0 ;
F_163 () ;
F_20 ( & V_235 ) ;
V_35 = F_233 ( V_7 ) ;
V_13 = F_32 ( V_35 ) ;
if ( ! V_35 || ! V_13 -> V_16 ) {
V_32 = - V_64 ;
F_65 (KERN_ERR PFX L_58 ) ;
goto V_359;
}
V_358 = V_35 -> V_358 ;
F_128 ( V_35 ) ;
F_234 ( V_358 ) ;
V_359:
F_23 ( & V_235 ) ;
F_165 () ;
return V_32 ;
}
static void V_353 ( struct V_360 * V_150 )
{
struct V_5 * V_34 ;
struct V_2 * V_3 ;
V_34 = F_64 ( V_150 , struct V_5 , V_296 ) ;
V_3 = V_34 -> V_3 ;
F_34 ( V_3 , L_59 ) ;
F_227 ( V_3 ) ;
}
static void F_235 ( struct V_36 * V_37 )
{
F_236 ( V_37 ) ;
F_237 ( V_37 ) ;
}
static int F_238 ( struct V_36 * V_37 )
{
if ( F_239 ( V_37 ) )
goto V_361;
if ( F_240 ( V_37 ) )
goto V_361;
return 0 ;
V_361:
F_235 ( V_37 ) ;
return - V_65 ;
}
static int F_206 ( struct V_36 * V_37 )
{
struct V_313 * V_314 ;
struct V_362 * V_363 ;
if ( ! V_37 -> V_314 ) {
F_65 (KERN_ERR PFX L_60 ) ;
return - V_64 ;
}
V_314 = V_37 -> V_314 ;
V_363 = V_37 -> V_364 = V_314 -> V_364 ;
if ( ! V_37 -> V_364 )
return - V_64 ;
switch ( V_363 -> V_185 ) {
case V_365 :
strncpy ( V_37 -> V_200 , L_61 , V_366 ) ;
break;
case V_367 :
strncpy ( V_37 -> V_200 , L_62 , V_366 ) ;
break;
case V_368 :
case V_369 :
case V_370 :
strncpy ( V_37 -> V_200 , L_63 , V_366 ) ;
break;
case V_371 :
case V_372 :
case V_373 :
strncpy ( V_37 -> V_200 , L_64 , V_366 ) ;
break;
case V_374 :
case V_375 :
case V_376 :
strncpy ( V_37 -> V_200 , L_65 , V_366 ) ;
break;
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
strncpy ( V_37 -> V_200 , L_66 , V_366 ) ;
break;
default:
F_241 ( V_382 L_67 , V_363 -> V_185 ) ;
break;
}
F_242 ( V_37 -> V_364 ) ;
return 0 ;
}
static void F_201 ( struct V_36 * V_37 )
{
if ( V_37 -> V_364 ) {
V_37 -> V_200 [ 0 ] = '\0' ;
F_243 ( V_37 -> V_364 ) ;
}
V_37 -> V_364 = NULL ;
}
static int F_244 ( void * V_383 )
{
struct V_36 * V_37 = V_383 ;
struct V_313 * V_314 ;
struct V_384 * V_385 ;
if ( ! V_37 )
return - V_82 ;
V_314 = V_37 -> V_314 ;
V_385 = & V_314 -> V_385 -> V_386 ;
if ( ! V_385 )
return - V_82 ;
strncpy ( V_385 -> V_387 , V_201 ,
sizeof( V_385 -> V_387 ) ) ;
V_385 -> V_388 = V_389 ;
V_385 -> V_390 = V_391 ;
return 0 ;
}
static void F_245 ( void * V_383 )
{
struct V_36 * V_37 = V_383 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
struct V_2 * V_3 ;
F_20 ( & V_235 ) ;
if ( ! F_41 ( V_285 , & V_37 -> V_85 ) )
F_246 ( V_37 ) ;
F_19 ( L_68 ) ;
F_130 (interface, &if_list, list) {
if ( V_35 -> V_37 == V_37 ) {
V_13 = F_32 ( V_35 ) ;
V_3 = V_13 -> V_16 ;
F_65 (KERN_ERR PFX L_69 ) ;
V_3 -> V_249 . V_392 = F_31 ;
F_247 ( V_35 ) ;
}
}
F_23 ( & V_235 ) ;
}
static void F_174 ( struct V_2 * V_3 )
{
F_19 ( L_1 , V_41 ) ;
F_178 ( V_3 ) ;
F_248 ( V_3 ) ;
}
static void F_231 ( struct V_4 * V_35 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 ;
struct V_2 * V_194 ;
if ( ! F_41 ( V_285 , & V_35 -> V_37 -> V_85 ) )
return;
V_3 = V_13 -> V_16 ;
F_174 ( V_3 ) ;
F_20 ( & V_3 -> V_242 ) ;
F_130 (vport, &lport->vports, list)
F_135 ( V_194 -> V_186 ) =
V_243 ;
F_23 ( & V_3 -> V_242 ) ;
F_135 ( V_3 -> V_186 ) = V_243 ;
F_134 ( V_13 ) ;
F_136 ( V_3 ) ;
}
static int F_246 ( struct V_36 * V_37 )
{
#define F_249 (1000 / HZ)
int V_32 = - 1 ;
int V_40 = V_163 ;
V_32 = F_238 ( V_37 ) ;
if ( V_32 ) {
F_65 (KERN_ALERT PFX
L_70 , rc) ;
goto V_393;
}
V_32 = F_250 ( V_37 ) ;
if ( V_32 ) {
F_65 (KERN_ALERT PFX
L_71 , rc) ;
goto V_394;
}
while ( ! F_41 ( V_229 , & V_37 -> V_206 ) && V_40 -- )
F_251 ( F_249 ) ;
if ( ! F_41 ( V_229 , & V_37 -> V_206 ) ) {
F_65 (KERN_ERR PFX L_72
L_73 ,
hba->cnic->netdev->name) ;
V_32 = - 1 ;
goto V_394;
}
F_114 ( V_285 , & V_37 -> V_85 ) ;
return 0 ;
V_394:
F_235 ( V_37 ) ;
V_393:
return V_32 ;
}
static void F_252 ( struct V_36 * V_37 )
{
if ( F_191 ( V_285 , & V_37 -> V_85 ) ) {
if ( F_253 ( V_37 ) == 0 ) {
F_254 ( & V_37 -> V_395 ) ;
V_37 -> V_395 . V_396 = V_397 +
V_289 ;
V_37 -> V_395 . V_398 = F_125 ;
V_37 -> V_395 . V_145 = ( unsigned long ) V_37 ;
F_255 ( & V_37 -> V_395 ) ;
F_138 ( V_37 -> V_221 ,
F_41 ( V_220 ,
& V_37 -> V_85 ) ) ;
F_113 ( V_220 , & V_37 -> V_85 ) ;
if ( F_139 ( V_130 ) )
F_140 ( V_130 ) ;
F_226 ( & V_37 -> V_395 ) ;
}
F_235 ( V_37 ) ;
}
}
static void F_256 ( void * V_383 )
{
struct V_36 * V_37 = V_383 ;
struct V_4 * V_35 ;
F_65 ( V_230 L_74 ) ;
F_20 ( & V_235 ) ;
if ( ! F_41 ( V_285 , & V_37 -> V_85 ) )
goto exit;
F_130 (interface, &if_list, list) {
if ( V_35 -> V_37 == V_37 )
F_231 ( V_35 ) ;
}
F_257 ( V_37 -> V_247 != 0 ) ;
F_20 ( & V_37 -> V_42 ) ;
F_113 ( V_229 , & V_37 -> V_206 ) ;
F_113 ( V_232 ,
& V_37 -> V_206 ) ;
F_113 ( V_245 , & V_37 -> V_206 ) ;
F_23 ( & V_37 -> V_42 ) ;
F_252 ( V_37 ) ;
exit:
F_23 ( & V_235 ) ;
}
static void F_247 ( struct V_4 * V_35 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 ;
int V_399 = 0 ;
F_19 ( L_1 , V_41 ) ;
if ( ! F_41 ( V_285 , & V_35 -> V_37 -> V_85 ) ) {
F_65 (KERN_ERR PFX L_75 ) ;
return;
}
V_3 = V_13 -> V_16 ;
F_34 ( V_3 , L_76 ) ;
if ( ! F_111 ( V_3 ) && V_35 -> V_238 ) {
F_34 ( V_3 , L_77 ) ;
F_133 ( V_13 ) ;
F_135 ( V_3 -> V_186 ) = V_400 ;
F_114 ( V_245 , & V_35 -> V_37 -> V_206 ) ;
}
while ( ! V_13 -> V_81 ) {
F_251 ( 250 ) ;
if ( ++ V_399 > 12 )
break;
}
if ( F_117 ( V_3 , V_214 ) )
return;
F_168 ( V_3 ) ;
F_169 ( V_3 ) ;
}
static void F_258 ( struct V_313 * V_99 )
{
struct V_36 * V_37 ;
int V_32 = 0 ;
F_19 ( L_1 , V_41 ) ;
if ( ! F_41 ( V_401 , & V_99 -> V_85 ) ||
( V_99 -> V_402 == 0 ) ) {
F_65 (KERN_ERR PFX L_78
L_79 ,
dev->netdev->name, dev->flags, dev->max_fcoe_conn) ;
return;
}
V_37 = F_202 ( V_99 ) ;
if ( ! V_37 ) {
F_65 (KERN_ERR PFX L_80 ) ;
return;
}
F_20 ( & V_235 ) ;
F_219 ( & V_37 -> V_22 , & V_403 ) ;
V_404 ++ ;
F_23 ( & V_235 ) ;
V_99 -> V_316 = & V_37 -> V_316 ;
F_113 ( V_405 , & V_37 -> V_406 ) ;
V_32 = V_99 -> V_407 ( V_99 , V_408 ,
( void * ) V_37 ) ;
if ( V_32 )
F_65 (KERN_ERR PFX L_81 , rc) ;
else
F_114 ( V_405 , & V_37 -> V_406 ) ;
}
static int F_259 ( struct V_12 * V_13 )
{
struct V_4 * V_35 = F_6 ( V_13 ) ;
if ( V_35 -> V_238 == true ) {
if ( ! V_13 -> V_16 ) {
F_241 ( V_382 L_82 ) ;
return - V_64 ;
} else {
V_35 -> V_238 = false ;
F_134 ( V_13 ) ;
F_136 ( V_13 -> V_16 ) ;
}
}
return 0 ;
}
static int F_260 ( struct V_1 * V_7 )
{
struct V_4 * V_35 ;
struct V_12 * V_13 ;
int V_32 = 0 ;
F_163 () ;
F_20 ( & V_235 ) ;
V_35 = F_233 ( V_7 ) ;
V_13 = F_32 ( V_35 ) ;
if ( ! V_35 ) {
V_32 = - V_64 ;
F_241 ( V_382 L_83 ) ;
} else {
V_32 = F_259 ( V_13 ) ;
}
F_23 ( & V_235 ) ;
F_165 () ;
return V_32 ;
}
static int F_261 ( struct V_12 * V_13 )
{
struct V_4 * V_35 = F_6 ( V_13 ) ;
if ( V_35 -> V_238 == false ) {
if ( ! V_13 -> V_16 ) {
F_241 ( V_382 L_84 ) ;
return - V_64 ;
} else if ( ! F_111 ( V_13 -> V_16 ) ) {
F_133 ( V_13 ) ;
V_35 -> V_238 = true ;
}
}
return 0 ;
}
static int F_262 ( struct V_1 * V_7 )
{
struct V_4 * V_35 ;
struct V_12 * V_13 ;
int V_32 = 0 ;
F_163 () ;
F_20 ( & V_235 ) ;
V_35 = F_233 ( V_7 ) ;
V_13 = F_32 ( V_35 ) ;
if ( ! V_35 ) {
V_32 = - V_64 ;
F_241 ( V_382 L_85 ) ;
} else {
V_32 = F_261 ( V_13 ) ;
}
F_23 ( & V_235 ) ;
F_165 () ;
return V_32 ;
}
static int F_263 ( struct V_10 * V_224 )
{
struct V_12 * V_13 = F_5 ( V_224 ) ;
switch ( V_224 -> V_238 ) {
case V_240 :
return F_261 ( V_13 ) ;
case V_239 :
return F_259 ( V_13 ) ;
case V_241 :
default:
return - V_409 ;
} ;
}
static int F_264 ( struct V_1 * V_7 ,
enum V_340 V_341 ,
enum V_410 V_411 )
{
struct V_10 * V_224 ;
struct V_12 * V_13 ;
struct V_4 * V_35 ;
struct V_36 * V_37 ;
struct V_1 * V_203 = V_7 ;
struct V_2 * V_3 ;
struct V_412 V_413 ;
int V_32 = 0 ;
int V_15 = 0 ;
F_19 ( L_86 ) ;
if ( V_341 != V_414 ) {
F_65 ( V_230 L_87 ) ;
return - V_286 ;
}
F_163 () ;
F_20 ( & V_235 ) ;
if ( ! F_265 ( V_311 ) ) {
V_32 = - V_82 ;
goto V_415;
}
if ( V_7 -> V_416 & V_417 )
V_203 = F_266 ( V_7 ) ;
if ( V_203 -> V_211 && V_203 -> V_211 -> V_418 ) {
memset ( & V_413 , 0 , sizeof( V_413 ) ) ;
V_203 -> V_211 -> V_418 ( V_203 , & V_413 ) ;
if ( strncmp ( V_413 . V_419 , L_88 , strlen ( L_88 ) ) ) {
F_65 (KERN_ERR PFX L_89 ) ;
V_32 = - V_82 ;
goto V_359;
}
} else {
F_65 (KERN_ERR PFX L_90 ) ;
V_32 = - V_82 ;
goto V_359;
}
V_37 = F_267 ( V_203 ) ;
if ( ! V_37 ) {
V_32 = - V_64 ;
F_65 (KERN_ERR PFX L_91 ) ;
goto V_359;
}
if ( F_233 ( V_7 ) ) {
V_32 = - V_420 ;
goto V_359;
}
V_35 = F_209 ( V_37 , V_7 , V_341 ) ;
if ( ! V_35 ) {
F_65 (KERN_ERR PFX L_92 ) ;
goto V_421;
}
if ( V_7 -> V_416 & V_417 ) {
V_15 = F_268 ( V_7 ) ;
V_35 -> V_422 = 1 ;
}
V_13 = F_32 ( V_35 ) ;
V_224 = F_131 ( V_13 ) ;
V_35 -> V_15 = V_15 ;
V_35 -> V_358 =
F_269 ( L_93 ) ;
if ( ! V_35 -> V_358 ) {
F_65 (KERN_ERR PFX L_94 ) ;
V_32 = - V_82 ;
goto V_421;
}
V_3 = F_164 ( V_35 , & V_224 -> V_99 , 0 ) ;
if ( ! V_3 ) {
F_65 (KERN_ERR PFX L_95 ,
netdev->name) ;
V_32 = - V_82 ;
goto V_423;
}
F_219 ( & V_35 -> V_22 , & V_424 ) ;
V_3 -> V_288 = V_289 ;
V_13 -> V_16 = V_3 ;
if ( V_411 == V_425 )
V_224 -> V_238 = V_240 ;
else
V_224 -> V_238 = V_239 ;
if ( V_411 == V_425 &&
! F_111 ( V_3 ) ) {
F_133 ( V_13 ) ;
F_135 ( V_3 -> V_186 ) = V_400 ;
F_114 ( V_245 , & V_35 -> V_37 -> V_206 ) ;
}
F_34 ( V_3 , L_96 ) ;
F_247 ( V_35 ) ;
if ( V_411 == V_425 )
V_35 -> V_238 = true ;
F_175 ( V_35 ) ;
F_23 ( & V_235 ) ;
F_165 () ;
return 0 ;
V_423:
F_234 ( V_35 -> V_358 ) ;
V_421:
F_222 ( V_35 ) ;
F_175 ( V_35 ) ;
goto V_415;
V_359:
F_195 ( V_311 ) ;
V_415:
F_23 ( & V_235 ) ;
F_165 () ;
return V_32 ;
}
static int F_270 ( struct V_1 * V_7 , enum V_340 V_341 )
{
return F_264 ( V_7 , V_341 , V_425 ) ;
}
static int F_271 ( struct V_1 * V_7 )
{
return F_264 ( V_7 , V_414 ,
V_426 ) ;
}
static struct V_36 * F_272 ( struct V_313 * V_314 )
{
struct V_36 * V_37 ;
F_130 (hba, &adapter_list, list) {
if ( V_37 -> V_314 == V_314 )
return V_37 ;
}
return NULL ;
}
static struct V_4 * F_233 ( struct V_1
* V_7 )
{
struct V_4 * V_35 ;
F_130 (interface, &if_list, list) {
if ( V_35 -> V_7 == V_7 )
return V_35 ;
}
return NULL ;
}
static struct V_36 * F_267 ( struct V_1
* V_203 )
{
struct V_36 * V_37 ;
F_130 (hba, &adapter_list, list) {
if ( V_37 -> V_203 == V_203 )
return V_37 ;
}
F_65 (KERN_ERR PFX L_97 ) ;
return NULL ;
}
static void F_273 ( struct V_313 * V_99 )
{
struct V_36 * V_37 ;
struct V_4 * V_35 , * V_151 ;
F_19 ( L_98 ) ;
if ( ! F_41 ( V_401 , & V_99 -> V_85 ) ) {
F_65 (KERN_ERR PFX L_99 ,
dev->netdev->name, dev->flags) ;
return;
}
F_20 ( & V_235 ) ;
V_37 = F_272 ( V_99 ) ;
if ( ! V_37 ) {
F_65 (KERN_ERR PFX L_100 ,
dev) ;
F_23 ( & V_235 ) ;
return;
}
F_97 ( & V_37 -> V_22 ) ;
V_404 -- ;
F_96 (interface, tmp, &if_list, list)
if ( V_35 -> V_37 == V_37 )
F_128 ( V_35 ) ;
F_23 ( & V_235 ) ;
F_129 ( V_237 ) ;
F_256 ( V_37 ) ;
if ( F_191 ( V_405 , & V_37 -> V_406 ) )
V_37 -> V_314 -> V_427 ( V_37 -> V_314 , V_408 ) ;
F_199 ( V_37 ) ;
}
static int F_274 ( struct V_156 * V_157 )
{
struct V_2 * V_3 = F_101 ( V_157 ) ;
F_275 ( V_3 ) ;
return 0 ;
}
static bool F_276 ( struct V_1 * V_7 )
{
struct V_1 * V_203 = V_7 ;
F_20 ( & V_235 ) ;
if ( V_7 -> V_416 & V_417 )
V_203 = F_266 ( V_7 ) ;
if ( F_267 ( V_203 ) ) {
F_23 ( & V_235 ) ;
return true ;
}
F_23 ( & V_235 ) ;
return false ;
}
static void F_277 ( unsigned int V_428 )
{
struct V_147 * V_148 ;
struct V_429 * V_128 ;
V_148 = & F_278 ( V_430 , V_428 ) ;
V_128 = F_279 ( F_92 ,
( void * ) V_148 , F_280 ( V_428 ) ,
L_101 , V_428 ) ;
if ( F_281 ( ! F_166 ( V_128 ) ) ) {
F_282 ( V_128 , V_428 ) ;
V_148 -> V_431 = V_128 ;
F_70 ( V_128 ) ;
}
}
static void F_283 ( unsigned int V_428 )
{
struct V_147 * V_148 ;
struct V_429 * V_128 ;
struct V_149 * V_150 , * V_151 ;
F_19 ( L_102 , V_428 ) ;
V_148 = & F_278 ( V_430 , V_428 ) ;
F_8 ( & V_148 -> V_153 ) ;
V_128 = V_148 -> V_431 ;
V_148 -> V_431 = NULL ;
F_96 (work, tmp, &p->work_list, list) {
F_97 ( & V_150 -> V_22 ) ;
F_98 ( V_150 -> V_39 , V_150 -> V_154 ) ;
F_99 ( V_150 ) ;
}
F_12 ( & V_148 -> V_153 ) ;
if ( V_128 )
F_284 ( V_128 ) ;
}
static int F_285 ( struct V_432 * V_433 ,
unsigned long V_434 , void * V_435 )
{
unsigned V_428 = ( unsigned long ) V_435 ;
switch ( V_434 ) {
case V_436 :
case V_437 :
F_65 ( V_382 L_103 , V_428 ) ;
F_277 ( V_428 ) ;
break;
case V_438 :
case V_439 :
F_65 ( V_382 L_104 , V_428 ) ;
F_283 ( V_428 ) ;
break;
default:
break;
}
return V_440 ;
}
static int T_6 F_286 ( void )
{
struct V_17 * V_18 ;
struct V_429 * V_441 ;
int V_32 = 0 ;
unsigned int V_428 = 0 ;
struct V_147 * V_148 ;
F_65 (KERN_INFO PFX L_105 , version) ;
V_32 = F_287 ( & V_442 ) ;
if ( V_32 ) {
F_65 ( V_230 L_106
L_107 ) ;
goto V_443;
}
F_208 ( & V_403 ) ;
F_208 ( & V_424 ) ;
F_205 ( & V_235 ) ;
V_404 = 0 ;
V_32 = F_186 () ;
if ( V_32 )
goto V_444;
V_237 = F_288 ( L_108 , 0 , 0 ) ;
if ( ! V_237 ) {
V_32 = - V_65 ;
goto V_445;
}
V_18 = & V_27 ;
F_118 ( & V_18 -> V_28 ) ;
V_441 = F_289 ( F_71 ,
( void * ) V_18 ,
L_109 ) ;
if ( F_166 ( V_441 ) ) {
V_32 = F_290 ( V_441 ) ;
goto V_446;
}
F_70 ( V_441 ) ;
F_8 ( & V_18 -> V_28 . V_29 ) ;
V_18 -> V_128 = V_441 ;
F_12 ( & V_18 -> V_28 . V_29 ) ;
F_291 (cpu) {
V_148 = & F_278 ( V_430 , V_428 ) ;
F_208 ( & V_148 -> V_152 ) ;
F_204 ( & V_148 -> V_153 ) ;
}
F_292 () ;
F_293 (cpu) {
F_277 ( V_428 ) ;
}
F_294 ( & V_447 ) ;
F_295 () ;
F_296 ( V_408 , & V_448 ) ;
return 0 ;
V_446:
F_234 ( V_237 ) ;
V_445:
F_189 () ;
V_444:
F_297 ( & V_442 ) ;
V_443:
return V_32 ;
}
static void T_7 F_298 ( void )
{
F_93 ( V_449 ) ;
struct V_36 * V_37 , * V_25 ;
struct V_17 * V_18 ;
struct V_429 * V_441 ;
struct V_23 * V_24 ;
unsigned int V_428 = 0 ;
F_20 ( & V_235 ) ;
F_299 ( & V_403 , & V_449 ) ;
F_208 ( & V_403 ) ;
V_404 = 0 ;
F_23 ( & V_235 ) ;
F_96 (hba, next, &to_be_deleted, list) {
F_97 ( & V_37 -> V_22 ) ;
F_65 (KERN_ERR PFX L_110 ,
hba) ;
F_256 ( V_37 ) ;
if ( F_191 ( V_405 ,
& V_37 -> V_406 ) )
V_37 -> V_314 -> V_427 ( V_37 -> V_314 ,
V_408 ) ;
F_199 ( V_37 ) ;
}
F_300 ( V_408 ) ;
V_18 = & V_27 ;
F_8 ( & V_18 -> V_28 . V_29 ) ;
V_441 = V_18 -> V_128 ;
V_18 -> V_128 = NULL ;
while ( ( V_24 = F_76 ( & V_18 -> V_28 ) ) != NULL )
F_11 ( V_24 ) ;
F_12 ( & V_18 -> V_28 . V_29 ) ;
if ( V_441 )
F_284 ( V_441 ) ;
F_292 () ;
F_293 (cpu) {
F_283 ( V_428 ) ;
}
F_301 ( & V_447 ) ;
F_295 () ;
F_234 ( V_237 ) ;
F_189 () ;
F_297 ( & V_442 ) ;
}
