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
F_72 ( V_130 , - 20 ) ;
F_73 ( V_131 ) ;
while ( ! F_74 () ) {
F_75 () ;
F_8 ( & V_18 -> V_28 . V_29 ) ;
while ( ( V_24 = F_76 ( & V_18 -> V_28 ) ) != NULL ) {
F_12 ( & V_18 -> V_28 . V_29 ) ;
F_77 ( V_24 ) ;
F_8 ( & V_18 -> V_28 . V_29 ) ;
}
F_78 ( V_131 ) ;
F_12 ( & V_18 -> V_28 . V_29 ) ;
}
F_78 ( V_132 ) ;
return 0 ;
}
static void F_77 ( struct V_23 * V_24 )
{
T_2 V_133 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_72 * V_73 ;
struct V_50 * V_51 ;
struct V_68 V_134 ;
struct V_46 * V_47 ;
struct V_2 * V_135 ;
struct V_5 * V_34 ;
T_1 * V_136 = NULL ;
T_1 * V_137 = NULL ;
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
V_136 = F_54 ( V_24 ) -> V_107 ;
V_137 = F_54 ( V_24 ) -> V_102 ;
V_71 = (struct V_70 * ) F_80 ( V_24 ) ;
V_51 = (struct V_50 * ) F_68 ( V_24 ) ;
F_81 ( V_24 , sizeof( struct V_70 ) ) ;
V_133 = V_24 -> V_86 - sizeof( struct V_68 ) ;
V_73 = F_58 ( V_3 -> V_73 , F_59 () ) ;
V_73 -> V_138 ++ ;
V_73 -> V_139 += V_133 / V_87 ;
V_47 = (struct V_46 * ) V_24 ;
F_82 ( V_47 ) ;
V_30 ( V_47 ) = V_3 ;
F_37 ( V_47 ) = V_71 -> V_111 ;
if ( F_83 ( V_24 , V_133 , & V_134 , sizeof( V_134 ) ) ) {
F_60 () ;
F_11 ( V_24 ) ;
return;
}
F_38 ( V_47 ) = V_134 . V_94 ;
F_84 ( V_47 ) = V_134 . V_95 ;
if ( F_85 ( V_24 , V_133 ) ) {
F_60 () ;
F_11 ( V_24 ) ;
return;
}
V_51 = F_25 ( V_47 ) ;
V_135 = F_86 ( V_3 , F_40 ( V_51 -> V_83 ) ) ;
if ( V_135 ) {
V_34 = F_2 ( V_135 ) ;
if ( ! F_87 ( V_34 -> V_109 , V_137 ) ) {
F_34 ( V_3 , L_15 ) ;
F_60 () ;
F_11 ( V_24 ) ;
return;
}
}
if ( V_51 -> V_55 == V_140 &&
V_51 -> V_56 == V_141 ) {
F_60 () ;
F_11 ( V_24 ) ;
return;
}
if ( V_51 -> V_55 == V_58 &&
V_51 -> V_56 == V_57 ) {
switch ( F_27 ( V_47 ) ) {
case V_60 :
if ( F_40 ( V_51 -> V_142 ) == V_143 ) {
F_60 () ;
F_11 ( V_24 ) ;
return;
}
break;
}
}
if ( V_51 -> V_55 == V_63 ) {
F_60 () ;
F_11 ( V_24 ) ;
return;
}
if ( F_88 ( F_84 ( V_47 ) ) !=
~ F_89 ( ~ 0 , V_24 -> V_144 , V_133 ) ) {
if ( V_73 -> V_145 < 5 )
F_65 (KERN_WARNING PFX L_16
L_17 ) ;
V_73 -> V_145 ++ ;
F_60 () ;
F_11 ( V_24 ) ;
return;
}
F_60 () ;
F_90 ( V_3 , V_47 ) ;
}
int F_91 ( void * V_129 )
{
struct V_146 * V_147 = V_129 ;
struct V_148 * V_149 , * V_150 ;
F_92 ( V_151 ) ;
F_72 ( V_130 , - 20 ) ;
F_73 ( V_131 ) ;
while ( ! F_74 () ) {
F_75 () ;
F_8 ( & V_147 -> V_152 ) ;
while ( ! F_93 ( & V_147 -> V_151 ) ) {
F_94 ( & V_147 -> V_151 , & V_151 ) ;
F_12 ( & V_147 -> V_152 ) ;
F_95 (work, tmp, &work_list, list) {
F_96 ( & V_149 -> V_22 ) ;
F_97 ( V_149 -> V_39 , V_149 -> V_153 ) ;
F_98 ( V_149 ) ;
}
F_8 ( & V_147 -> V_152 ) ;
}
F_78 ( V_131 ) ;
F_12 ( & V_147 -> V_152 ) ;
}
F_78 ( V_132 ) ;
return 0 ;
}
static struct V_154 * F_99 ( struct V_155 * V_156 )
{
struct V_154 * V_157 ;
struct V_2 * V_3 = F_100 ( V_156 ) ;
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_158 * V_159 ;
int V_32 = 0 ;
V_159 = (struct V_158 * ) V_37 -> V_160 ;
if ( ! V_159 )
return NULL ;
V_157 = F_101 ( V_156 ) ;
F_102 ( & V_37 -> V_161 ) ;
if ( F_103 ( V_37 ) )
return V_157 ;
V_32 = F_104 ( & V_37 -> V_161 , ( 2 * V_162 ) ) ;
if ( ! V_32 ) {
F_34 ( V_3 , L_18 ) ;
return V_157 ;
}
F_105 ( V_37 , V_163 , V_164 ) ;
V_157 -> V_165 += V_37 -> V_166 . V_164 ;
F_105 ( V_37 , V_167 , V_168 ) ;
V_157 -> V_169 += V_37 -> V_166 . V_168 ;
F_105 ( V_37 , V_167 , V_170 ) ;
V_157 -> V_171 += ( ( V_37 -> V_166 . V_170 ) / 4 ) ;
F_105 ( V_37 , V_172 , V_173 ) ;
V_157 -> V_174 += V_37 -> V_166 . V_173 ;
F_105 ( V_37 , V_172 , V_175 ) ;
V_157 -> V_176 += ( ( V_37 -> V_166 . V_175 ) / 4 ) ;
V_157 -> V_177 = 0 ;
V_157 -> V_178 = 0 ;
V_157 -> V_179 = 0 ;
V_157 -> V_180 = 0 ;
V_157 -> V_181 = 0 ;
V_157 -> V_182 = 0 ;
memcpy ( & V_37 -> V_183 , V_37 -> V_160 ,
sizeof( struct V_158 ) ) ;
return V_157 ;
}
static int F_106 ( struct V_2 * V_3 , struct V_184 * V_99 )
{
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_155 * V_156 = V_3 -> V_185 ;
int V_32 = 0 ;
V_156 -> V_186 = V_187 ;
V_156 -> V_188 = V_189 ;
V_156 -> V_190 = V_191 ;
V_156 -> V_192 = 0 ;
if ( V_3 -> V_193 )
V_156 -> V_194 = V_195 ;
else
V_156 -> V_194 = V_196 ;
V_32 = F_107 ( V_3 -> V_185 , V_99 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_19 ) ;
return V_32 ;
}
if ( ! V_3 -> V_193 )
F_108 ( V_3 -> V_185 ) = V_197 ;
snprintf ( F_109 ( V_3 -> V_185 ) , 256 ,
L_20 ,
V_198 , V_37 -> V_199 , V_200 ,
V_35 -> V_7 -> V_201 ) ;
return 0 ;
}
static int F_110 ( struct V_2 * V_3 )
{
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_1 * V_99 = V_37 -> V_202 ;
int V_32 = 0 ;
if ( ( V_99 -> V_85 & V_203 ) && F_111 ( V_99 ) )
F_112 ( V_204 , & V_37 -> V_205 ) ;
else {
F_113 ( V_204 , & V_37 -> V_205 ) ;
V_32 = - 1 ;
}
return V_32 ;
}
void F_114 ( struct V_36 * V_37 )
{
if ( F_41 ( V_206 , & V_37 -> V_202 -> V_207 ) )
F_113 ( V_204 , & V_37 -> V_205 ) ;
else
F_112 ( V_204 , & V_37 -> V_205 ) ;
}
static int F_115 ( struct V_2 * V_3 , struct V_1 * V_7 )
{
struct V_36 * V_37 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
struct V_5 * V_34 ;
T_4 V_208 , V_209 ;
V_34 = F_2 ( V_3 ) ;
V_35 = V_34 -> V_6 ;
V_13 = F_32 ( V_35 ) ;
V_37 = V_35 -> V_37 ;
if ( ! V_37 -> V_202 -> V_210 ||
! V_37 -> V_202 -> V_210 -> V_211 )
return - V_212 ;
if ( F_116 ( V_3 , V_213 ) )
return - V_82 ;
F_117 ( & V_34 -> V_118 ) ;
V_34 -> V_214 = 0 ;
F_118 ( & V_34 -> V_215 , V_216 , ( unsigned long ) V_3 ) ;
F_119 ( V_3 ) ;
if ( ! V_3 -> V_193 ) {
if ( F_120 ( V_7 , & V_208 , V_217 ) )
V_208 = F_121 ( V_13 -> V_108 ,
1 , 0 ) ;
F_34 ( V_3 , L_21 , V_208 ) ;
F_122 ( V_3 , V_208 ) ;
if ( F_120 ( V_7 , & V_209 , V_218 ) )
V_209 = F_121 ( V_13 -> V_108 ,
2 , 0 ) ;
F_34 ( V_3 , L_22 , V_209 ) ;
F_123 ( V_3 , V_209 ) ;
}
return 0 ;
}
static void F_124 ( unsigned long V_144 )
{
struct V_36 * V_37 = (struct V_36 * ) V_144 ;
F_65 (KERN_ERR PFX L_23
L_24 ) ;
F_113 ( V_219 , & V_37 -> V_85 ) ;
F_125 ( & V_37 -> V_220 ) ;
}
static void F_126 ( void * V_221 , unsigned long V_222 ,
T_5 V_15 )
{
struct V_36 * V_37 = (struct V_36 * ) V_221 ;
struct V_10 * V_223 ;
struct V_2 * V_3 ;
struct V_2 * V_193 ;
struct V_4 * V_35 , * V_150 ;
struct V_12 * V_13 ;
int V_224 = 0 ;
T_2 V_225 = 1 ;
if ( V_15 != 0 && V_222 != V_226 )
return;
switch ( V_222 ) {
case V_227 :
if ( ! F_41 ( V_228 , & V_37 -> V_205 ) )
F_65 ( V_229 L_25\
L_26 ) ;
break;
case V_230 :
F_112 ( V_231 , & V_37 -> V_205 ) ;
F_112 ( V_228 , & V_37 -> V_205 ) ;
V_225 = 0 ;
break;
case V_232 :
F_113 ( V_231 , & V_37 -> V_205 ) ;
V_225 = 0 ;
break;
case V_233 :
break;
case V_226 :
if ( ! V_15 )
return;
F_20 ( & V_234 ) ;
F_95 (interface, tmp, &if_list, list) {
if ( V_35 -> V_37 == V_37 &&
V_35 -> V_15 == ( V_15 & V_235 ) )
F_127 ( V_35 ) ;
}
F_23 ( & V_234 ) ;
return;
default:
F_65 (KERN_ERR PFX L_27 , event) ;
return;
}
F_20 ( & V_234 ) ;
F_128 (interface, &if_list, list) {
if ( V_35 -> V_37 != V_37 )
continue;
V_13 = F_32 ( V_35 ) ;
V_3 = V_13 -> V_16 ;
F_34 ( V_3 , L_28 ,
V_35 -> V_7 -> V_201 , V_222 ) ;
F_119 ( V_3 ) ;
V_223 = F_129 ( V_13 ) ;
if ( V_225 && ! F_110 ( V_3 ) ) {
switch ( V_223 -> V_236 ) {
case V_237 :
F_130 ( L_29 ) ;
break;
case V_238 :
case V_239 :
F_116 ( V_3 , V_213 ) ;
if ( V_35 -> V_236 )
F_131 ( V_13 ) ;
} ;
} else if ( F_132 ( V_13 ) ) {
switch ( V_223 -> V_236 ) {
case V_237 :
F_130 ( L_30 ) ;
break;
case V_238 :
case V_239 :
F_20 ( & V_3 -> V_240 ) ;
F_128 (vport, &lport->vports, list)
F_133 ( V_193 -> V_185 ) =
V_241 ;
F_23 ( & V_3 -> V_240 ) ;
F_133 ( V_3 -> V_185 ) =
V_241 ;
F_58 ( V_3 -> V_73 ,
F_59 () ) -> V_242 ++ ;
F_60 () ;
F_134 ( V_3 ) ;
V_224 = 1 ;
} ;
}
}
F_23 ( & V_234 ) ;
if ( V_224 ) {
F_112 ( V_243 , & V_37 -> V_205 ) ;
F_135 ( & V_37 -> V_244 ) ;
F_19 ( L_31
L_32 ,
V_37 -> V_245 ) ;
V_37 -> V_246 = 1 ;
F_136 ( V_37 -> V_244 ,
( V_37 -> V_245 == 0 ) ) ;
F_19 ( L_33 ,
V_37 -> V_245 ) ;
V_37 -> V_246 = 0 ;
if ( F_137 ( V_130 ) )
F_138 ( V_130 ) ;
}
}
static int F_139 ( struct V_2 * V_3 )
{
memcpy ( & V_3 -> V_247 , & V_248 ,
sizeof( struct V_249 ) ) ;
F_140 ( V_3 ) ;
F_141 ( V_3 ) ;
F_142 ( V_3 ) ;
F_143 ( V_3 ) ;
F_144 ( V_3 , V_3 ) ;
return 0 ;
}
static int F_145 ( struct V_2 * V_3 , struct V_36 * V_37 )
{
int V_250 , V_251 ;
V_250 = V_37 -> V_252 + 1 ;
if ( V_253 <= 2 )
V_251 = V_37 -> V_252 + V_254 ;
else
V_251 = V_37 -> V_252 + V_255 ;
if ( ! F_146 ( V_3 , V_256 , V_250 ,
V_251 , NULL ) ) {
F_65 (KERN_ERR PFX L_34 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_147 ( struct V_2 * V_3 )
{
V_3 -> V_80 = 0 ;
V_3 -> V_257 = 0 ;
V_3 -> V_258 = V_259 ;
V_3 -> V_260 = V_261 ;
V_3 -> V_262 = 2 * 1000 ;
V_3 -> V_263 = 10 * 1000 ;
V_3 -> V_264 = ( V_265 | V_266 |
V_267 | V_268 ) ;
V_3 -> V_269 = 1 ;
memset ( & V_3 -> V_270 , 0 , sizeof( struct V_271 ) ) ;
V_3 -> V_270 . V_272 = V_273 ;
if ( F_148 ( V_3 ) )
return - V_65 ;
F_149 ( V_3 ) ;
return 0 ;
}
static int F_150 ( struct V_23 * V_24 , struct V_1 * V_99 ,
struct V_120 * V_121 ,
struct V_1 * V_274 )
{
struct V_4 * V_35 ;
struct V_12 * V_13 ;
V_35 = F_64 ( V_121 , struct V_4 ,
V_275 ) ;
V_13 = F_32 ( V_35 ) ;
F_151 ( V_13 , V_24 ) ;
return 0 ;
}
static void F_152 ( struct V_2 * V_3 , T_1 * V_276 )
{
struct V_5 * V_34 = F_2 ( V_3 ) ;
memcpy ( V_34 -> V_109 , V_276 , V_104 ) ;
}
static T_1 * F_153 ( struct V_2 * V_3 )
{
struct V_5 * V_34 ;
V_34 = (struct V_5 * ) F_2 ( V_3 ) ;
return V_34 -> V_109 ;
}
static void F_154 ( struct V_12 * V_277 , struct V_23 * V_24 )
{
V_24 -> V_99 = F_155 ( V_277 ) -> V_7 ;
F_156 ( V_24 ) ;
}
static int F_157 ( struct V_278 * V_193 , bool V_279 )
{
struct V_155 * V_156 = F_158 ( V_193 ) ;
struct V_2 * V_280 = F_100 ( V_156 ) ;
struct V_5 * V_34 = F_2 ( V_280 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_1 * V_7 = V_35 -> V_7 ;
struct V_2 * V_135 ;
int V_32 ;
char V_281 [ 32 ] ;
V_32 = F_159 ( V_193 ) ;
if ( V_32 ) {
F_160 ( V_193 -> V_282 , V_281 , sizeof( V_281 ) ) ;
F_65 (KERN_ERR PFX L_35
L_36 ,
buf) ;
return V_32 ;
}
if ( ! F_41 ( V_283 , & V_35 -> V_37 -> V_85 ) ) {
F_65 (KERN_ERR PFX L_37
L_38 ) ;
return - V_284 ;
}
F_161 () ;
F_20 ( & V_234 ) ;
V_135 = F_162 ( V_35 , & V_193 -> V_99 , 1 ) ;
F_23 ( & V_234 ) ;
F_163 () ;
if ( F_164 ( V_135 ) ) {
F_65 (KERN_ERR PFX L_39 ,
netdev->name) ;
return - V_284 ;
}
if ( V_279 ) {
F_165 ( V_193 , V_285 ) ;
} else {
V_135 -> V_286 = V_287 ;
F_166 ( V_135 ) ;
F_167 ( V_135 ) ;
F_168 ( V_135 ) ;
}
return 0 ;
}
static void F_169 ( struct V_36 * V_37 , struct V_2 * V_3 )
{
struct V_288 * V_289 , * V_150 ;
F_8 ( & V_37 -> V_43 ) ;
F_95 (blport, tmp, &hba->vports, list) {
if ( V_289 -> V_3 == V_3 ) {
F_170 ( & V_289 -> V_22 ) ;
F_98 ( V_289 ) ;
}
}
F_12 ( & V_37 -> V_43 ) ;
}
static int F_171 ( struct V_278 * V_193 )
{
struct V_155 * V_156 = F_158 ( V_193 ) ;
struct V_2 * V_280 = F_100 ( V_156 ) ;
struct V_2 * V_135 = V_193 -> V_290 ;
struct V_5 * V_34 = F_2 ( V_135 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_2 * V_291 ;
bool V_292 = false ;
F_20 ( & V_280 -> V_240 ) ;
F_128 (v_port, &n_port->vports, list)
if ( V_291 -> V_193 == V_193 ) {
V_292 = true ;
break;
}
if ( ! V_292 ) {
F_23 ( & V_280 -> V_240 ) ;
return - V_293 ;
}
F_170 ( & V_135 -> V_22 ) ;
F_23 ( & V_280 -> V_240 ) ;
F_169 ( V_35 -> V_37 , V_34 -> V_3 ) ;
F_172 ( V_34 -> V_3 ) ;
F_173 ( V_35 ) ;
F_174 ( V_294 , & V_34 -> V_295 ) ;
return 0 ;
}
static int F_175 ( struct V_278 * V_193 , bool V_296 )
{
struct V_2 * V_3 = V_193 -> V_290 ;
if ( V_296 ) {
F_165 ( V_193 , V_285 ) ;
F_176 ( V_3 ) ;
} else {
V_3 -> V_286 = V_287 ;
F_167 ( V_3 ) ;
F_168 ( V_3 ) ;
}
return 0 ;
}
static int F_177 ( struct V_4 * V_35 )
{
struct V_1 * V_7 = V_35 -> V_7 ;
struct V_1 * V_297 = V_35 -> V_37 -> V_202 ;
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_298 * V_299 ;
int V_300 = 0 ;
F_178 () ;
F_179 (physdev, ha) {
F_19 ( L_40 ,
V_299 -> type ) ;
F_65 ( V_301 L_41 , V_299 -> V_276 [ 0 ] ,
V_299 -> V_276 [ 1 ] , V_299 -> V_276 [ 2 ] , V_299 -> V_276 [ 3 ] ,
V_299 -> V_276 [ 4 ] , V_299 -> V_276 [ 5 ] ) ;
if ( ( V_299 -> type == V_302 ) &&
( F_180 ( V_299 -> V_276 ) ) ) {
memcpy ( V_13 -> V_108 , V_299 -> V_276 ,
V_104 ) ;
V_300 = 1 ;
F_19 ( L_42 ) ;
}
}
F_181 () ;
if ( ! V_300 )
return - V_64 ;
V_35 -> V_275 . V_303 = F_150 ;
V_35 -> V_275 . type = F_53 ( V_304 ) ;
V_35 -> V_275 . V_99 = V_7 ;
F_182 ( & V_35 -> V_275 ) ;
V_35 -> V_124 . V_303 = F_63 ;
V_35 -> V_124 . type = F_183 ( V_98 ) ;
V_35 -> V_124 . V_99 = V_7 ;
F_182 ( & V_35 -> V_124 ) ;
return 0 ;
}
static int F_184 ( void )
{
V_196 =
F_185 ( & V_305 ) ;
if ( V_196 == NULL ) {
F_65 (KERN_ERR PFX L_43 ) ;
return - V_64 ;
}
V_195 =
F_185 ( & V_306 ) ;
if ( V_195 == NULL ) {
F_65 (KERN_ERR PFX
L_44 ) ;
F_186 ( V_196 ) ;
V_196 = NULL ;
return - V_64 ;
}
return 0 ;
}
static void F_187 ( void )
{
F_186 ( V_196 ) ;
F_186 ( V_195 ) ;
V_196 = NULL ;
V_195 = NULL ;
}
static void F_188 ( struct V_307 * V_307 )
{
struct V_10 * V_11 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
struct V_1 * V_7 ;
V_35 = F_64 ( V_307 , struct V_4 , V_307 ) ;
F_19 ( L_45 ) ;
V_13 = F_32 ( V_35 ) ;
V_11 = F_129 ( V_13 ) ;
V_7 = V_35 -> V_7 ;
if ( F_189 ( V_308 , & V_35 -> V_309 ) )
F_190 ( V_13 ) ;
F_191 ( V_11 ) ;
F_192 ( V_7 ) ;
F_193 ( V_310 ) ;
}
static inline void F_194 ( struct V_4 * V_35 )
{
F_195 ( & V_35 -> V_307 ) ;
}
static inline void F_173 ( struct V_4 * V_35 )
{
F_196 ( & V_35 -> V_307 , F_188 ) ;
}
static void F_197 ( struct V_36 * V_37 )
{
if ( V_37 -> V_311 ) {
F_198 ( V_37 -> V_311 ) ;
V_37 -> V_311 = NULL ;
}
F_98 ( V_37 -> V_45 ) ;
F_199 ( V_37 ) ;
F_98 ( V_37 ) ;
}
static struct V_36 * F_200 ( struct V_312 * V_313 )
{
struct V_36 * V_37 ;
struct V_314 * V_315 ;
int V_32 ;
V_37 = F_201 ( sizeof( * V_37 ) , V_316 ) ;
if ( ! V_37 ) {
F_65 (KERN_ERR PFX L_46 ) ;
return NULL ;
}
F_202 ( & V_37 -> V_43 ) ;
F_203 ( & V_37 -> V_42 ) ;
V_37 -> V_313 = V_313 ;
V_37 -> V_317 = V_313 -> V_318 ;
V_37 -> V_319 = ( V_37 -> V_317 / 2 ) ;
V_37 -> V_320 = V_37 -> V_319 ;
V_37 -> V_252 = ( V_37 -> V_317 - 1 ) ;
V_32 = F_204 ( V_37 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_47 ) ;
goto V_321;
}
V_37 -> V_202 = V_313 -> V_7 ;
V_37 -> V_322 = 0 ;
V_37 -> V_45 =
F_201 ( sizeof( struct V_38 * ) * V_44 ,
V_316 ) ;
if ( ! V_37 -> V_45 ) {
F_65 (KERN_ERR PFX L_48 ) ;
goto V_323;
}
V_37 -> V_245 = 0 ;
V_37 -> V_311 = F_205 ( V_37 ) ;
if ( ! V_37 -> V_311 ) {
F_65 (KERN_ERR PFX L_49 ) ;
goto V_324;
}
V_315 = & V_37 -> V_315 ;
V_315 -> V_325 = V_326 <<
V_327 ;
V_315 -> V_325 |= V_44 <<
V_328 ;
V_315 -> V_329 = V_37 -> V_320 <<
V_330 ;
V_315 -> V_329 |= V_331 <<
V_332 ;
V_315 -> V_333 = V_44 <<
V_334 ;
V_315 -> V_333 |= V_37 -> V_320 <<
V_335 ;
V_315 -> V_336 = V_337 ;
F_135 ( & V_37 -> V_244 ) ;
F_135 ( & V_37 -> V_220 ) ;
F_206 ( & V_37 -> V_338 ) ;
return V_37 ;
V_324:
F_98 ( V_37 -> V_45 ) ;
V_323:
F_199 ( V_37 ) ;
V_321:
F_98 ( V_37 ) ;
return NULL ;
}
struct V_4 * F_207 ( struct V_36 * V_37 ,
struct V_1 * V_7 ,
enum V_339 V_340 )
{
struct V_10 * V_11 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
int V_341 ;
int V_32 = 0 ;
V_341 = ( sizeof( * V_35 ) + sizeof( struct V_12 ) ) ;
V_11 = F_208 ( & V_7 -> V_99 , & V_342 ,
V_341 ) ;
if ( ! V_11 ) {
F_65 (KERN_ERR PFX L_50 ) ;
return NULL ;
}
V_13 = F_5 ( V_11 ) ;
V_13 -> V_223 = V_11 ;
V_35 = F_6 ( V_13 ) ;
F_209 ( V_7 ) ;
F_210 ( & V_35 -> V_307 ) ;
V_35 -> V_37 = V_37 ;
V_35 -> V_7 = V_7 ;
F_211 ( V_13 , V_340 ) ;
V_13 -> V_343 = F_154 ;
V_13 -> V_344 = F_152 ;
V_13 -> V_345 = F_153 ;
F_113 ( V_308 , & V_35 -> V_309 ) ;
V_32 = F_177 ( V_35 ) ;
if ( ! V_32 )
return V_35 ;
F_190 ( V_13 ) ;
F_192 ( V_7 ) ;
F_191 ( V_11 ) ;
return NULL ;
}
static struct V_2 * F_162 ( struct V_4 * V_35 ,
struct V_184 * V_346 , int V_347 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 , * V_280 ;
struct V_5 * V_34 ;
struct V_155 * V_156 ;
struct V_278 * V_193 = F_212 ( V_346 ) ;
struct V_288 * V_289 ;
struct V_36 * V_37 = V_35 -> V_37 ;
int V_32 = 0 ;
V_289 = F_201 ( sizeof( struct V_288 ) , V_316 ) ;
if ( ! V_289 ) {
F_34 ( V_13 -> V_16 , L_51 ) ;
return NULL ;
}
V_348 . V_349 = V_37 -> V_320 ;
if ( ! V_347 )
V_3 = F_213 ( & V_348 , sizeof( * V_34 ) ) ;
else
V_3 = F_214 ( V_193 , sizeof( * V_34 ) ) ;
if ( ! V_3 ) {
F_65 (KERN_ERR PFX L_52 ) ;
goto V_350;
}
V_156 = V_3 -> V_185 ;
V_34 = F_2 ( V_3 ) ;
V_34 -> V_3 = V_3 ;
V_34 -> V_6 = V_35 ;
V_34 -> V_351 = F_1 ;
F_215 ( & V_34 -> V_295 , V_352 ) ;
V_32 = F_147 ( V_3 ) ;
if ( V_32 )
goto V_353;
if ( V_347 ) {
F_65 (KERN_ERR PFX L_53 ,
vport->node_name, vport->port_name) ;
F_122 ( V_3 , V_193 -> V_354 ) ;
F_123 ( V_3 , V_193 -> V_282 ) ;
}
V_32 = F_115 ( V_3 , V_35 -> V_7 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_54 ) ;
goto V_353;
}
V_32 = F_106 ( V_3 , V_346 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_55 ,
interface->netdev->name) ;
goto V_353;
}
V_32 = F_139 ( V_3 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_56 ) ;
goto V_355;
}
F_133 ( V_3 -> V_185 ) = V_241 ;
if ( ! V_347 )
V_32 = F_145 ( V_3 , V_37 ) ;
else {
V_156 = F_158 ( V_193 ) ;
V_280 = F_100 ( V_156 ) ;
V_32 = F_216 ( V_280 , V_3 ) ;
}
if ( V_32 ) {
F_65 (KERN_ERR PFX L_57 ) ;
goto V_355;
}
F_194 ( V_35 ) ;
F_8 ( & V_37 -> V_43 ) ;
V_289 -> V_3 = V_3 ;
F_217 ( & V_289 -> V_22 , & V_37 -> V_338 ) ;
F_12 ( & V_37 -> V_43 ) ;
return V_3 ;
V_355:
F_218 ( V_156 ) ;
V_353:
F_219 ( V_3 -> V_185 ) ;
V_350:
F_98 ( V_289 ) ;
return NULL ;
}
static void F_220 ( struct V_4 * V_35 )
{
F_221 ( & V_35 -> V_124 ) ;
F_221 ( & V_35 -> V_275 ) ;
F_222 () ;
}
static void F_223 ( struct V_4 * V_35 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 = V_13 -> V_16 ;
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_36 * V_37 = V_35 -> V_37 ;
F_224 ( & V_34 -> V_215 ) ;
F_134 ( V_3 ) ;
F_220 ( V_35 ) ;
F_169 ( V_37 , V_3 ) ;
}
static void F_225 ( struct V_2 * V_3 )
{
F_7 ( V_3 ) ;
F_226 ( V_3 -> V_185 ) ;
F_218 ( V_3 -> V_185 ) ;
F_227 ( V_3 ) ;
F_228 ( V_3 ) ;
F_219 ( V_3 -> V_185 ) ;
}
static void F_127 ( struct V_4 * V_35 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 = V_13 -> V_16 ;
struct V_5 * V_34 = F_2 ( V_3 ) ;
F_223 ( V_35 ) ;
F_229 ( V_35 ) ;
F_170 ( & V_35 -> V_22 ) ;
F_173 ( V_35 ) ;
F_174 ( V_294 , & V_34 -> V_295 ) ;
}
static int F_230 ( struct V_1 * V_7 )
{
struct V_4 * V_35 = NULL ;
struct V_356 * V_357 ;
struct V_12 * V_13 ;
int V_32 = 0 ;
F_161 () ;
F_20 ( & V_234 ) ;
V_35 = F_231 ( V_7 ) ;
V_13 = F_32 ( V_35 ) ;
if ( ! V_35 || ! V_13 -> V_16 ) {
V_32 = - V_64 ;
F_65 (KERN_ERR PFX L_58 ) ;
goto V_358;
}
V_357 = V_35 -> V_357 ;
F_127 ( V_35 ) ;
F_232 ( V_357 ) ;
V_358:
F_23 ( & V_234 ) ;
F_163 () ;
return V_32 ;
}
static void V_352 ( struct V_359 * V_149 )
{
struct V_5 * V_34 ;
struct V_2 * V_3 ;
V_34 = F_64 ( V_149 , struct V_5 , V_295 ) ;
V_3 = V_34 -> V_3 ;
F_34 ( V_3 , L_59 ) ;
F_225 ( V_3 ) ;
}
static void F_233 ( struct V_36 * V_37 )
{
F_234 ( V_37 ) ;
F_235 ( V_37 ) ;
}
static int F_236 ( struct V_36 * V_37 )
{
if ( F_237 ( V_37 ) )
goto V_360;
if ( F_238 ( V_37 ) )
goto V_360;
return 0 ;
V_360:
F_233 ( V_37 ) ;
return - V_65 ;
}
static int F_204 ( struct V_36 * V_37 )
{
struct V_312 * V_313 ;
struct V_361 * V_362 ;
if ( ! V_37 -> V_313 ) {
F_65 (KERN_ERR PFX L_60 ) ;
return - V_64 ;
}
V_313 = V_37 -> V_313 ;
V_362 = V_37 -> V_363 = V_313 -> V_363 ;
if ( ! V_37 -> V_363 )
return - V_64 ;
switch ( V_362 -> V_184 ) {
case V_364 :
strncpy ( V_37 -> V_199 , L_61 , V_365 ) ;
break;
case V_366 :
strncpy ( V_37 -> V_199 , L_62 , V_365 ) ;
break;
case V_367 :
case V_368 :
case V_369 :
strncpy ( V_37 -> V_199 , L_63 , V_365 ) ;
break;
case V_370 :
case V_371 :
case V_372 :
strncpy ( V_37 -> V_199 , L_64 , V_365 ) ;
break;
case V_373 :
case V_374 :
case V_375 :
strncpy ( V_37 -> V_199 , L_65 , V_365 ) ;
break;
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
strncpy ( V_37 -> V_199 , L_66 , V_365 ) ;
break;
default:
F_239 ( V_381 L_67 , V_362 -> V_184 ) ;
break;
}
F_240 ( V_37 -> V_363 ) ;
return 0 ;
}
static void F_199 ( struct V_36 * V_37 )
{
if ( V_37 -> V_363 ) {
V_37 -> V_199 [ 0 ] = '\0' ;
F_241 ( V_37 -> V_363 ) ;
}
V_37 -> V_363 = NULL ;
}
static int F_242 ( void * V_382 )
{
struct V_36 * V_37 = V_382 ;
struct V_312 * V_313 ;
struct V_383 * V_384 ;
if ( ! V_37 )
return - V_82 ;
V_313 = V_37 -> V_313 ;
V_384 = & V_313 -> V_384 -> V_385 ;
if ( ! V_384 )
return - V_82 ;
strncpy ( V_384 -> V_386 , V_200 ,
sizeof( V_384 -> V_386 ) ) ;
V_384 -> V_387 = V_388 ;
V_384 -> V_389 = V_390 ;
return 0 ;
}
static void F_243 ( void * V_382 )
{
struct V_36 * V_37 = V_382 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
struct V_2 * V_3 ;
F_20 ( & V_234 ) ;
if ( ! F_41 ( V_283 , & V_37 -> V_85 ) )
F_244 ( V_37 ) ;
F_19 ( L_68 ) ;
F_128 (interface, &if_list, list) {
if ( V_35 -> V_37 == V_37 ) {
V_13 = F_32 ( V_35 ) ;
V_3 = V_13 -> V_16 ;
F_65 (KERN_ERR PFX L_69 ) ;
V_3 -> V_247 . V_391 = F_31 ;
F_245 ( V_35 ) ;
}
}
F_23 ( & V_234 ) ;
}
static void F_172 ( struct V_2 * V_3 )
{
F_19 ( L_1 , V_41 ) ;
F_176 ( V_3 ) ;
F_246 ( V_3 ) ;
}
static void F_229 ( struct V_4 * V_35 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 ;
struct V_2 * V_193 ;
if ( ! F_41 ( V_283 , & V_35 -> V_37 -> V_85 ) )
return;
V_3 = V_13 -> V_16 ;
F_172 ( V_3 ) ;
F_20 ( & V_3 -> V_240 ) ;
F_128 (vport, &lport->vports, list)
F_133 ( V_193 -> V_185 ) =
V_241 ;
F_23 ( & V_3 -> V_240 ) ;
F_133 ( V_3 -> V_185 ) = V_241 ;
F_132 ( V_13 ) ;
F_134 ( V_3 ) ;
}
static int F_244 ( struct V_36 * V_37 )
{
#define F_247 (1000 / HZ)
int V_32 = - 1 ;
int V_40 = V_162 ;
V_32 = F_236 ( V_37 ) ;
if ( V_32 ) {
F_65 (KERN_ALERT PFX
L_70 , rc) ;
goto V_392;
}
V_32 = F_248 ( V_37 ) ;
if ( V_32 ) {
F_65 (KERN_ALERT PFX
L_71 , rc) ;
goto V_393;
}
while ( ! F_41 ( V_228 , & V_37 -> V_205 ) && V_40 -- )
F_249 ( F_247 ) ;
if ( ! F_41 ( V_228 , & V_37 -> V_205 ) ) {
F_65 (KERN_ERR PFX L_72
L_73 ,
hba->cnic->netdev->name) ;
V_32 = - 1 ;
goto V_393;
}
F_113 ( V_283 , & V_37 -> V_85 ) ;
return 0 ;
V_393:
F_233 ( V_37 ) ;
V_392:
return V_32 ;
}
static void F_250 ( struct V_36 * V_37 )
{
if ( F_189 ( V_283 , & V_37 -> V_85 ) ) {
if ( F_251 ( V_37 ) == 0 ) {
F_252 ( & V_37 -> V_394 ) ;
V_37 -> V_394 . V_395 = V_396 +
V_287 ;
V_37 -> V_394 . V_397 = F_124 ;
V_37 -> V_394 . V_144 = ( unsigned long ) V_37 ;
F_253 ( & V_37 -> V_394 ) ;
F_136 ( V_37 -> V_220 ,
F_41 ( V_219 ,
& V_37 -> V_85 ) ) ;
F_112 ( V_219 , & V_37 -> V_85 ) ;
if ( F_137 ( V_130 ) )
F_138 ( V_130 ) ;
F_224 ( & V_37 -> V_394 ) ;
}
F_233 ( V_37 ) ;
}
}
static void F_254 ( void * V_382 )
{
struct V_36 * V_37 = V_382 ;
struct V_4 * V_35 ;
F_65 ( V_229 L_74 ) ;
F_20 ( & V_234 ) ;
if ( ! F_41 ( V_283 , & V_37 -> V_85 ) )
goto exit;
F_128 (interface, &if_list, list) {
if ( V_35 -> V_37 == V_37 )
F_229 ( V_35 ) ;
}
F_255 ( V_37 -> V_245 != 0 ) ;
F_20 ( & V_37 -> V_42 ) ;
F_112 ( V_228 , & V_37 -> V_205 ) ;
F_112 ( V_231 ,
& V_37 -> V_205 ) ;
F_112 ( V_243 , & V_37 -> V_205 ) ;
F_23 ( & V_37 -> V_42 ) ;
F_250 ( V_37 ) ;
exit:
F_23 ( & V_234 ) ;
}
static void F_245 ( struct V_4 * V_35 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 ;
int V_398 = 0 ;
F_19 ( L_1 , V_41 ) ;
if ( ! F_41 ( V_283 , & V_35 -> V_37 -> V_85 ) ) {
F_65 (KERN_ERR PFX L_75 ) ;
return;
}
V_3 = V_13 -> V_16 ;
F_34 ( V_3 , L_76 ) ;
if ( ! F_110 ( V_3 ) && V_35 -> V_236 ) {
F_34 ( V_3 , L_77 ) ;
F_131 ( V_13 ) ;
F_133 ( V_3 -> V_185 ) = V_399 ;
F_113 ( V_243 , & V_35 -> V_37 -> V_205 ) ;
}
while ( ! V_13 -> V_81 ) {
F_249 ( 250 ) ;
if ( ++ V_398 > 12 )
break;
}
if ( F_116 ( V_3 , V_213 ) )
return;
F_166 ( V_3 ) ;
F_167 ( V_3 ) ;
}
static void F_256 ( struct V_312 * V_99 )
{
struct V_36 * V_37 ;
int V_32 = 0 ;
F_19 ( L_1 , V_41 ) ;
if ( ! F_41 ( V_400 , & V_99 -> V_85 ) ||
( V_99 -> V_401 == 0 ) ) {
F_65 (KERN_ERR PFX L_78
L_79 ,
dev->netdev->name, dev->flags, dev->max_fcoe_conn) ;
return;
}
V_37 = F_200 ( V_99 ) ;
if ( ! V_37 ) {
F_65 (KERN_ERR PFX L_80 ) ;
return;
}
F_20 ( & V_234 ) ;
F_217 ( & V_37 -> V_22 , & V_402 ) ;
V_403 ++ ;
F_23 ( & V_234 ) ;
V_99 -> V_315 = & V_37 -> V_315 ;
F_112 ( V_404 , & V_37 -> V_405 ) ;
V_32 = V_99 -> V_406 ( V_99 , V_407 ,
( void * ) V_37 ) ;
if ( V_32 )
F_65 (KERN_ERR PFX L_81 , rc) ;
else
F_113 ( V_404 , & V_37 -> V_405 ) ;
}
static int F_257 ( struct V_12 * V_13 )
{
struct V_4 * V_35 = F_6 ( V_13 ) ;
if ( V_35 -> V_236 == true ) {
if ( ! V_13 -> V_16 ) {
F_239 ( V_381 L_82 ) ;
return - V_64 ;
} else {
V_35 -> V_236 = false ;
F_132 ( V_13 ) ;
F_134 ( V_13 -> V_16 ) ;
}
}
return 0 ;
}
static int F_258 ( struct V_1 * V_7 )
{
struct V_4 * V_35 ;
struct V_12 * V_13 ;
int V_32 = 0 ;
F_161 () ;
F_20 ( & V_234 ) ;
V_35 = F_231 ( V_7 ) ;
V_13 = F_32 ( V_35 ) ;
if ( ! V_35 ) {
V_32 = - V_64 ;
F_239 ( V_381 L_83 ) ;
} else {
V_32 = F_257 ( V_13 ) ;
}
F_23 ( & V_234 ) ;
F_163 () ;
return V_32 ;
}
static int F_259 ( struct V_12 * V_13 )
{
struct V_4 * V_35 = F_6 ( V_13 ) ;
if ( V_35 -> V_236 == false ) {
if ( ! V_13 -> V_16 ) {
F_239 ( V_381 L_84 ) ;
return - V_64 ;
} else if ( ! F_110 ( V_13 -> V_16 ) ) {
F_131 ( V_13 ) ;
V_35 -> V_236 = true ;
}
}
return 0 ;
}
static int F_260 ( struct V_1 * V_7 )
{
struct V_4 * V_35 ;
struct V_12 * V_13 ;
int V_32 = 0 ;
F_161 () ;
F_20 ( & V_234 ) ;
V_35 = F_231 ( V_7 ) ;
V_13 = F_32 ( V_35 ) ;
if ( ! V_35 ) {
V_32 = - V_64 ;
F_239 ( V_381 L_85 ) ;
} else {
V_32 = F_259 ( V_13 ) ;
}
F_23 ( & V_234 ) ;
F_163 () ;
return V_32 ;
}
static int F_261 ( struct V_10 * V_223 )
{
struct V_12 * V_13 = F_5 ( V_223 ) ;
switch ( V_223 -> V_236 ) {
case V_238 :
return F_259 ( V_13 ) ;
case V_237 :
return F_257 ( V_13 ) ;
case V_239 :
default:
return - V_408 ;
} ;
}
static int F_262 ( struct V_1 * V_7 ,
enum V_339 V_340 ,
enum V_409 V_410 )
{
struct V_10 * V_223 ;
struct V_12 * V_13 ;
struct V_4 * V_35 ;
struct V_36 * V_37 ;
struct V_1 * V_202 = V_7 ;
struct V_2 * V_3 ;
struct V_411 V_412 ;
int V_32 = 0 ;
int V_15 = 0 ;
F_19 ( L_86 ) ;
if ( V_340 != V_413 ) {
F_65 ( V_229 L_87 ) ;
return - V_284 ;
}
F_161 () ;
F_20 ( & V_234 ) ;
if ( ! F_263 ( V_310 ) ) {
V_32 = - V_82 ;
goto V_414;
}
if ( V_7 -> V_415 & V_416 )
V_202 = F_264 ( V_7 ) ;
if ( V_202 -> V_210 && V_202 -> V_210 -> V_417 ) {
memset ( & V_412 , 0 , sizeof( V_412 ) ) ;
V_202 -> V_210 -> V_417 ( V_202 , & V_412 ) ;
if ( strncmp ( V_412 . V_418 , L_88 , strlen ( L_88 ) ) ) {
F_65 (KERN_ERR PFX L_89 ) ;
V_32 = - V_82 ;
goto V_358;
}
} else {
F_65 (KERN_ERR PFX L_90 ) ;
V_32 = - V_82 ;
goto V_358;
}
V_37 = F_265 ( V_202 ) ;
if ( ! V_37 ) {
V_32 = - V_64 ;
F_65 (KERN_ERR PFX L_91 ) ;
goto V_358;
}
if ( F_231 ( V_7 ) ) {
V_32 = - V_419 ;
goto V_358;
}
V_35 = F_207 ( V_37 , V_7 , V_340 ) ;
if ( ! V_35 ) {
F_65 (KERN_ERR PFX L_92 ) ;
goto V_420;
}
if ( V_7 -> V_415 & V_416 ) {
V_15 = F_266 ( V_7 ) ;
V_35 -> V_421 = 1 ;
}
V_13 = F_32 ( V_35 ) ;
V_223 = F_129 ( V_13 ) ;
V_35 -> V_15 = V_15 ;
V_35 -> V_357 =
F_267 ( L_93 ) ;
if ( ! V_35 -> V_357 ) {
F_65 (KERN_ERR PFX L_94 ) ;
V_32 = - V_82 ;
goto V_420;
}
V_3 = F_162 ( V_35 , & V_223 -> V_99 , 0 ) ;
if ( ! V_3 ) {
F_65 (KERN_ERR PFX L_95 ,
netdev->name) ;
V_32 = - V_82 ;
goto V_422;
}
F_217 ( & V_35 -> V_22 , & V_423 ) ;
V_3 -> V_286 = V_287 ;
V_13 -> V_16 = V_3 ;
if ( V_410 == V_424 )
V_223 -> V_236 = V_238 ;
else
V_223 -> V_236 = V_237 ;
if ( V_410 == V_424 &&
! F_110 ( V_3 ) ) {
F_131 ( V_13 ) ;
F_133 ( V_3 -> V_185 ) = V_399 ;
F_113 ( V_243 , & V_35 -> V_37 -> V_205 ) ;
}
F_34 ( V_3 , L_96 ) ;
F_245 ( V_35 ) ;
if ( V_410 == V_424 )
V_35 -> V_236 = true ;
F_173 ( V_35 ) ;
F_23 ( & V_234 ) ;
F_163 () ;
return 0 ;
V_422:
F_232 ( V_35 -> V_357 ) ;
V_420:
F_220 ( V_35 ) ;
F_173 ( V_35 ) ;
goto V_414;
V_358:
F_193 ( V_310 ) ;
V_414:
F_23 ( & V_234 ) ;
F_163 () ;
return V_32 ;
}
static int F_268 ( struct V_1 * V_7 , enum V_339 V_340 )
{
return F_262 ( V_7 , V_340 , V_424 ) ;
}
static int F_269 ( struct V_1 * V_7 )
{
return F_262 ( V_7 , V_413 ,
V_425 ) ;
}
static struct V_36 * F_270 ( struct V_312 * V_313 )
{
struct V_36 * V_37 ;
F_128 (hba, &adapter_list, list) {
if ( V_37 -> V_313 == V_313 )
return V_37 ;
}
return NULL ;
}
static struct V_4 * F_231 ( struct V_1
* V_7 )
{
struct V_4 * V_35 ;
F_128 (interface, &if_list, list) {
if ( V_35 -> V_7 == V_7 )
return V_35 ;
}
return NULL ;
}
static struct V_36 * F_265 ( struct V_1
* V_202 )
{
struct V_36 * V_37 ;
F_128 (hba, &adapter_list, list) {
if ( V_37 -> V_202 == V_202 )
return V_37 ;
}
F_65 (KERN_ERR PFX L_97 ) ;
return NULL ;
}
static void F_271 ( struct V_312 * V_99 )
{
struct V_36 * V_37 ;
struct V_4 * V_35 , * V_150 ;
F_19 ( L_98 ) ;
if ( ! F_41 ( V_400 , & V_99 -> V_85 ) ) {
F_65 (KERN_ERR PFX L_99 ,
dev->netdev->name, dev->flags) ;
return;
}
F_20 ( & V_234 ) ;
V_37 = F_270 ( V_99 ) ;
if ( ! V_37 ) {
F_65 (KERN_ERR PFX L_100 ,
dev) ;
F_23 ( & V_234 ) ;
return;
}
F_96 ( & V_37 -> V_22 ) ;
V_403 -- ;
F_95 (interface, tmp, &if_list, list)
if ( V_35 -> V_37 == V_37 )
F_127 ( V_35 ) ;
F_23 ( & V_234 ) ;
F_254 ( V_37 ) ;
if ( F_189 ( V_404 , & V_37 -> V_405 ) )
V_37 -> V_313 -> V_426 ( V_37 -> V_313 , V_407 ) ;
F_197 ( V_37 ) ;
}
static int F_272 ( struct V_155 * V_156 )
{
struct V_2 * V_3 = F_100 ( V_156 ) ;
F_273 ( V_3 ) ;
return 0 ;
}
static bool F_274 ( struct V_1 * V_7 )
{
struct V_1 * V_202 = V_7 ;
F_20 ( & V_234 ) ;
if ( V_7 -> V_415 & V_416 )
V_202 = F_264 ( V_7 ) ;
if ( F_265 ( V_202 ) ) {
F_23 ( & V_234 ) ;
return true ;
}
F_23 ( & V_234 ) ;
return false ;
}
static void F_275 ( unsigned int V_427 )
{
struct V_146 * V_147 ;
struct V_428 * V_128 ;
V_147 = & F_276 ( V_429 , V_427 ) ;
V_128 = F_277 ( F_91 ,
( void * ) V_147 , F_278 ( V_427 ) ,
L_101 , V_427 ) ;
if ( F_279 ( ! F_164 ( V_128 ) ) ) {
F_280 ( V_128 , V_427 ) ;
V_147 -> V_430 = V_128 ;
F_70 ( V_128 ) ;
}
}
static void F_281 ( unsigned int V_427 )
{
struct V_146 * V_147 ;
struct V_428 * V_128 ;
struct V_148 * V_149 , * V_150 ;
F_19 ( L_102 , V_427 ) ;
V_147 = & F_276 ( V_429 , V_427 ) ;
F_8 ( & V_147 -> V_152 ) ;
V_128 = V_147 -> V_430 ;
V_147 -> V_430 = NULL ;
F_95 (work, tmp, &p->work_list, list) {
F_96 ( & V_149 -> V_22 ) ;
F_97 ( V_149 -> V_39 , V_149 -> V_153 ) ;
F_98 ( V_149 ) ;
}
F_12 ( & V_147 -> V_152 ) ;
if ( V_128 )
F_282 ( V_128 ) ;
}
static int F_283 ( struct V_431 * V_432 ,
unsigned long V_433 , void * V_434 )
{
unsigned V_427 = ( unsigned long ) V_434 ;
switch ( V_433 ) {
case V_435 :
case V_436 :
F_65 ( V_381 L_103 , V_427 ) ;
F_275 ( V_427 ) ;
break;
case V_437 :
case V_438 :
F_65 ( V_381 L_104 , V_427 ) ;
F_281 ( V_427 ) ;
break;
default:
break;
}
return V_439 ;
}
static int T_6 F_284 ( void )
{
struct V_17 * V_18 ;
struct V_428 * V_440 ;
int V_32 = 0 ;
unsigned int V_427 = 0 ;
struct V_146 * V_147 ;
F_65 (KERN_INFO PFX L_105 , version) ;
V_32 = F_285 ( & V_441 ) ;
if ( V_32 ) {
F_65 ( V_229 L_106
L_107 ) ;
goto V_442;
}
F_206 ( & V_402 ) ;
F_206 ( & V_423 ) ;
F_203 ( & V_234 ) ;
V_403 = 0 ;
V_32 = F_184 () ;
if ( V_32 )
goto V_443;
V_294 = F_286 ( L_108 , 0 , 0 ) ;
if ( ! V_294 ) {
V_32 = - V_65 ;
goto V_444;
}
V_18 = & V_27 ;
F_117 ( & V_18 -> V_28 ) ;
V_440 = F_287 ( F_71 ,
( void * ) V_18 ,
L_109 ) ;
if ( F_164 ( V_440 ) ) {
V_32 = F_288 ( V_440 ) ;
goto V_445;
}
F_70 ( V_440 ) ;
F_8 ( & V_18 -> V_28 . V_29 ) ;
V_18 -> V_128 = V_440 ;
F_12 ( & V_18 -> V_28 . V_29 ) ;
F_289 (cpu) {
V_147 = & F_276 ( V_429 , V_427 ) ;
F_206 ( & V_147 -> V_151 ) ;
F_202 ( & V_147 -> V_152 ) ;
}
F_290 (cpu) {
F_275 ( V_427 ) ;
}
F_291 ( & V_446 ) ;
F_292 ( V_407 , & V_447 ) ;
return 0 ;
V_445:
F_232 ( V_294 ) ;
V_444:
F_187 () ;
V_443:
F_293 ( & V_441 ) ;
V_442:
return V_32 ;
}
static void T_7 F_294 ( void )
{
F_92 ( V_448 ) ;
struct V_36 * V_37 , * V_25 ;
struct V_17 * V_18 ;
struct V_428 * V_440 ;
struct V_23 * V_24 ;
unsigned int V_427 = 0 ;
F_20 ( & V_234 ) ;
F_295 ( & V_402 , & V_448 ) ;
F_206 ( & V_402 ) ;
V_403 = 0 ;
F_23 ( & V_234 ) ;
F_95 (hba, next, &to_be_deleted, list) {
F_96 ( & V_37 -> V_22 ) ;
F_65 (KERN_ERR PFX L_110 ,
hba) ;
F_254 ( V_37 ) ;
if ( F_189 ( V_404 ,
& V_37 -> V_405 ) )
V_37 -> V_313 -> V_426 ( V_37 -> V_313 ,
V_407 ) ;
F_197 ( V_37 ) ;
}
F_296 ( V_407 ) ;
V_18 = & V_27 ;
F_8 ( & V_18 -> V_28 . V_29 ) ;
V_440 = V_18 -> V_128 ;
V_18 -> V_128 = NULL ;
while ( ( V_24 = F_76 ( & V_18 -> V_28 ) ) != NULL )
F_11 ( V_24 ) ;
F_12 ( & V_18 -> V_28 . V_29 ) ;
if ( V_440 )
F_282 ( V_440 ) ;
F_297 ( & V_446 ) ;
F_290 (cpu) {
F_281 ( V_427 ) ;
}
F_232 ( V_294 ) ;
F_187 () ;
F_293 ( & V_441 ) ;
}
