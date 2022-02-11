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
if ( F_87 ( V_34 -> V_109 , V_137 )
!= 0 ) {
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
sprintf ( F_109 ( V_3 -> V_185 ) , L_20 ,
V_198 , V_199 ,
V_35 -> V_7 -> V_200 ) ;
return 0 ;
}
static int F_110 ( struct V_2 * V_3 )
{
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_1 * V_99 = V_37 -> V_201 ;
int V_32 = 0 ;
if ( ( V_99 -> V_85 & V_202 ) && F_111 ( V_99 ) )
F_112 ( V_203 , & V_37 -> V_204 ) ;
else {
F_113 ( V_203 , & V_37 -> V_204 ) ;
V_32 = - 1 ;
}
return V_32 ;
}
void F_114 ( struct V_36 * V_37 )
{
if ( F_41 ( V_205 , & V_37 -> V_201 -> V_206 ) )
F_113 ( V_203 , & V_37 -> V_204 ) ;
else
F_112 ( V_203 , & V_37 -> V_204 ) ;
}
static int F_115 ( struct V_2 * V_3 , struct V_1 * V_7 )
{
struct V_36 * V_37 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
struct V_5 * V_34 ;
T_4 V_207 , V_208 ;
V_34 = F_2 ( V_3 ) ;
V_35 = V_34 -> V_6 ;
V_13 = F_32 ( V_35 ) ;
V_37 = V_35 -> V_37 ;
if ( ! V_37 -> V_201 -> V_209 ||
! V_37 -> V_201 -> V_209 -> V_210 )
return - V_211 ;
if ( F_116 ( V_3 , V_212 ) )
return - V_82 ;
F_117 ( & V_34 -> V_118 ) ;
V_34 -> V_213 = 0 ;
F_118 ( & V_34 -> V_214 , V_215 , ( unsigned long ) V_3 ) ;
F_119 ( V_3 ) ;
if ( ! V_3 -> V_193 ) {
if ( F_120 ( V_7 , & V_207 , V_216 ) )
V_207 = F_121 ( V_13 -> V_108 ,
1 , 0 ) ;
F_34 ( V_3 , L_21 , V_207 ) ;
F_122 ( V_3 , V_207 ) ;
if ( F_120 ( V_7 , & V_208 , V_217 ) )
V_208 = F_121 ( V_13 -> V_108 ,
2 , 0 ) ;
F_34 ( V_3 , L_22 , V_208 ) ;
F_123 ( V_3 , V_208 ) ;
}
return 0 ;
}
static void F_124 ( unsigned long V_144 )
{
struct V_36 * V_37 = (struct V_36 * ) V_144 ;
F_65 (KERN_ERR PFX L_23
L_24 ) ;
F_113 ( V_218 , & V_37 -> V_85 ) ;
F_125 ( & V_37 -> V_219 ) ;
}
static void F_126 ( void * V_220 , unsigned long V_221 ,
T_5 V_15 )
{
struct V_36 * V_37 = (struct V_36 * ) V_220 ;
struct V_10 * V_222 ;
struct V_2 * V_3 ;
struct V_2 * V_193 ;
struct V_4 * V_35 , * V_150 ;
struct V_12 * V_13 ;
int V_223 = 0 ;
T_2 V_224 = 1 ;
if ( V_15 != 0 && V_221 != V_225 )
return;
switch ( V_221 ) {
case V_226 :
if ( ! F_41 ( V_227 , & V_37 -> V_204 ) )
F_65 ( V_228 L_25\
L_26 ) ;
break;
case V_229 :
F_112 ( V_230 , & V_37 -> V_204 ) ;
F_112 ( V_227 , & V_37 -> V_204 ) ;
V_224 = 0 ;
break;
case V_231 :
F_113 ( V_230 , & V_37 -> V_204 ) ;
V_224 = 0 ;
break;
case V_232 :
break;
case V_225 :
if ( ! V_15 )
return;
F_20 ( & V_233 ) ;
F_95 (interface, tmp, &if_list, list) {
if ( V_35 -> V_37 == V_37 &&
V_35 -> V_15 == ( V_15 & V_234 ) )
F_127 ( V_35 ) ;
}
F_23 ( & V_233 ) ;
return;
default:
F_65 (KERN_ERR PFX L_27 , event) ;
return;
}
F_20 ( & V_233 ) ;
F_128 (interface, &if_list, list) {
if ( V_35 -> V_37 != V_37 )
continue;
V_13 = F_32 ( V_35 ) ;
V_3 = V_13 -> V_16 ;
F_34 ( V_3 , L_28 ,
V_35 -> V_7 -> V_200 , V_221 ) ;
F_119 ( V_3 ) ;
V_222 = F_129 ( V_13 ) ;
if ( V_224 && ! F_110 ( V_3 ) ) {
switch ( V_222 -> V_235 ) {
case V_236 :
F_130 ( L_29 ) ;
break;
case V_237 :
case V_238 :
F_116 ( V_3 , V_212 ) ;
if ( V_35 -> V_235 )
F_131 ( V_13 ) ;
} ;
} else if ( F_132 ( V_13 ) ) {
switch ( V_222 -> V_235 ) {
case V_236 :
F_130 ( L_30 ) ;
break;
case V_237 :
case V_238 :
F_20 ( & V_3 -> V_239 ) ;
F_128 (vport, &lport->vports, list)
F_133 ( V_193 -> V_185 ) =
V_240 ;
F_23 ( & V_3 -> V_239 ) ;
F_133 ( V_3 -> V_185 ) =
V_240 ;
F_58 ( V_3 -> V_73 ,
F_59 () ) -> V_241 ++ ;
F_60 () ;
F_134 ( V_3 ) ;
V_223 = 1 ;
} ;
}
}
F_23 ( & V_233 ) ;
if ( V_223 ) {
F_112 ( V_242 , & V_37 -> V_204 ) ;
F_135 ( & V_37 -> V_243 ) ;
F_19 ( L_31
L_32 ,
V_37 -> V_244 ) ;
V_37 -> V_245 = 1 ;
F_136 ( V_37 -> V_243 ,
( V_37 -> V_244 == 0 ) ) ;
F_19 ( L_33 ,
V_37 -> V_244 ) ;
V_37 -> V_245 = 0 ;
if ( F_137 ( V_130 ) )
F_138 ( V_130 ) ;
}
}
static int F_139 ( struct V_2 * V_3 )
{
memcpy ( & V_3 -> V_246 , & V_247 ,
sizeof( struct V_248 ) ) ;
F_140 ( V_3 ) ;
F_141 ( V_3 ) ;
F_142 ( V_3 ) ;
F_143 ( V_3 ) ;
F_144 ( V_3 , V_3 ) ;
return 0 ;
}
static int F_145 ( struct V_2 * V_3 )
{
int V_249 ;
if ( V_250 <= 2 )
V_249 = V_251 ;
else
V_249 = V_252 ;
if ( ! F_146 ( V_3 , V_253 , V_254 ,
V_249 , NULL ) ) {
F_65 (KERN_ERR PFX L_34 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_147 ( struct V_2 * V_3 )
{
V_3 -> V_80 = 0 ;
V_3 -> V_255 = 0 ;
V_3 -> V_256 = V_257 ;
V_3 -> V_258 = V_259 ;
V_3 -> V_260 = 2 * 1000 ;
V_3 -> V_261 = 10 * 1000 ;
V_3 -> V_262 = ( V_263 | V_264 |
V_265 | V_266 ) ;
V_3 -> V_267 = 1 ;
memset ( & V_3 -> V_268 , 0 , sizeof( struct V_269 ) ) ;
V_3 -> V_268 . V_270 = V_271 ;
if ( F_148 ( V_3 ) )
return - V_65 ;
F_149 ( V_3 ) ;
return 0 ;
}
static int F_150 ( struct V_23 * V_24 , struct V_1 * V_99 ,
struct V_120 * V_121 ,
struct V_1 * V_272 )
{
struct V_4 * V_35 ;
struct V_12 * V_13 ;
V_35 = F_64 ( V_121 , struct V_4 ,
V_273 ) ;
V_13 = F_32 ( V_35 ) ;
F_151 ( V_13 , V_24 ) ;
return 0 ;
}
static void F_152 ( struct V_2 * V_3 , T_1 * V_274 )
{
struct V_5 * V_34 = F_2 ( V_3 ) ;
memcpy ( V_34 -> V_109 , V_274 , V_104 ) ;
}
static T_1 * F_153 ( struct V_2 * V_3 )
{
struct V_5 * V_34 ;
V_34 = (struct V_5 * ) F_2 ( V_3 ) ;
return V_34 -> V_109 ;
}
static void F_154 ( struct V_12 * V_275 , struct V_23 * V_24 )
{
V_24 -> V_99 = F_155 ( V_275 ) -> V_7 ;
F_156 ( V_24 ) ;
}
static int F_157 ( struct V_276 * V_193 , bool V_277 )
{
struct V_155 * V_156 = F_158 ( V_193 ) ;
struct V_2 * V_278 = F_100 ( V_156 ) ;
struct V_5 * V_34 = F_2 ( V_278 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_1 * V_7 = V_35 -> V_7 ;
struct V_2 * V_135 ;
int V_32 ;
char V_279 [ 32 ] ;
V_32 = F_159 ( V_193 ) ;
if ( V_32 ) {
F_160 ( V_193 -> V_280 , V_279 , sizeof( V_279 ) ) ;
F_65 (KERN_ERR PFX L_35
L_36 ,
buf) ;
return V_32 ;
}
if ( ! F_41 ( V_281 , & V_35 -> V_37 -> V_85 ) ) {
F_65 (KERN_ERR PFX L_37
L_38 ) ;
return - V_282 ;
}
F_161 () ;
F_20 ( & V_233 ) ;
V_135 = F_162 ( V_35 , & V_193 -> V_99 , 1 ) ;
F_23 ( & V_233 ) ;
F_163 () ;
if ( F_164 ( V_135 ) ) {
F_65 (KERN_ERR PFX L_39 ,
netdev->name) ;
return - V_282 ;
}
if ( V_277 ) {
F_165 ( V_193 , V_283 ) ;
} else {
V_135 -> V_284 = V_285 ;
F_166 ( V_135 ) ;
F_167 ( V_135 ) ;
F_168 ( V_135 ) ;
}
return 0 ;
}
static void F_169 ( struct V_36 * V_37 , struct V_2 * V_3 )
{
struct V_286 * V_287 , * V_150 ;
F_8 ( & V_37 -> V_43 ) ;
F_95 (blport, tmp, &hba->vports, list) {
if ( V_287 -> V_3 == V_3 ) {
F_170 ( & V_287 -> V_22 ) ;
F_98 ( V_287 ) ;
}
}
F_12 ( & V_37 -> V_43 ) ;
}
static int F_171 ( struct V_276 * V_193 )
{
struct V_155 * V_156 = F_158 ( V_193 ) ;
struct V_2 * V_278 = F_100 ( V_156 ) ;
struct V_2 * V_135 = V_193 -> V_288 ;
struct V_5 * V_34 = F_2 ( V_135 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_2 * V_289 ;
bool V_290 = false ;
F_20 ( & V_278 -> V_239 ) ;
F_128 (v_port, &n_port->vports, list)
if ( V_289 -> V_193 == V_193 ) {
V_290 = true ;
break;
}
if ( ! V_290 ) {
F_23 ( & V_278 -> V_239 ) ;
return - V_291 ;
}
F_170 ( & V_135 -> V_22 ) ;
F_23 ( & V_278 -> V_239 ) ;
F_169 ( V_35 -> V_37 , V_34 -> V_3 ) ;
F_172 ( V_34 -> V_3 ) ;
F_173 ( V_35 ) ;
F_174 ( V_292 , & V_34 -> V_293 ) ;
return 0 ;
}
static int F_175 ( struct V_276 * V_193 , bool V_294 )
{
struct V_2 * V_3 = V_193 -> V_288 ;
if ( V_294 ) {
F_165 ( V_193 , V_283 ) ;
F_176 ( V_3 ) ;
} else {
V_3 -> V_284 = V_285 ;
F_167 ( V_3 ) ;
F_168 ( V_3 ) ;
}
return 0 ;
}
static int F_177 ( struct V_4 * V_35 )
{
struct V_1 * V_7 = V_35 -> V_7 ;
struct V_1 * V_295 = V_35 -> V_37 -> V_201 ;
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_296 * V_297 ;
int V_298 = 0 ;
F_178 () ;
F_179 (physdev, ha) {
F_19 ( L_40 ,
V_297 -> type ) ;
F_65 ( V_299 L_41 , V_297 -> V_274 [ 0 ] ,
V_297 -> V_274 [ 1 ] , V_297 -> V_274 [ 2 ] , V_297 -> V_274 [ 3 ] ,
V_297 -> V_274 [ 4 ] , V_297 -> V_274 [ 5 ] ) ;
if ( ( V_297 -> type == V_300 ) &&
( F_180 ( V_297 -> V_274 ) ) ) {
memcpy ( V_13 -> V_108 , V_297 -> V_274 ,
V_104 ) ;
V_298 = 1 ;
F_19 ( L_42 ) ;
}
}
F_181 () ;
if ( ! V_298 )
return - V_64 ;
V_35 -> V_273 . V_301 = F_150 ;
V_35 -> V_273 . type = F_53 ( V_302 ) ;
V_35 -> V_273 . V_99 = V_7 ;
F_182 ( & V_35 -> V_273 ) ;
V_35 -> V_124 . V_301 = F_63 ;
V_35 -> V_124 . type = F_183 ( V_98 ) ;
V_35 -> V_124 . V_99 = V_7 ;
F_182 ( & V_35 -> V_124 ) ;
return 0 ;
}
static int F_184 ( void )
{
V_196 =
F_185 ( & V_303 ) ;
if ( V_196 == NULL ) {
F_65 (KERN_ERR PFX L_43 ) ;
return - V_64 ;
}
V_195 =
F_185 ( & V_304 ) ;
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
static void F_188 ( struct V_305 * V_305 )
{
struct V_10 * V_11 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
struct V_1 * V_7 ;
V_35 = F_64 ( V_305 , struct V_4 , V_305 ) ;
F_19 ( L_45 ) ;
V_13 = F_32 ( V_35 ) ;
V_11 = F_129 ( V_13 ) ;
V_7 = V_35 -> V_7 ;
if ( F_189 ( V_306 , & V_35 -> V_307 ) )
F_190 ( V_13 ) ;
F_191 ( V_11 ) ;
F_192 ( V_7 ) ;
F_193 ( V_308 ) ;
}
static inline void F_194 ( struct V_4 * V_35 )
{
F_195 ( & V_35 -> V_305 ) ;
}
static inline void F_173 ( struct V_4 * V_35 )
{
F_196 ( & V_35 -> V_305 , F_188 ) ;
}
static void F_197 ( struct V_36 * V_37 )
{
if ( V_37 -> V_309 ) {
F_198 ( V_37 -> V_309 ) ;
V_37 -> V_309 = NULL ;
}
F_98 ( V_37 -> V_45 ) ;
F_199 ( V_37 ) ;
F_98 ( V_37 ) ;
}
static struct V_36 * F_200 ( struct V_310 * V_311 )
{
struct V_36 * V_37 ;
struct V_312 * V_313 ;
int V_32 ;
V_37 = F_201 ( sizeof( * V_37 ) , V_314 ) ;
if ( ! V_37 ) {
F_65 (KERN_ERR PFX L_46 ) ;
return NULL ;
}
F_202 ( & V_37 -> V_43 ) ;
F_203 ( & V_37 -> V_42 ) ;
V_37 -> V_311 = V_311 ;
V_32 = F_204 ( V_37 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_47 ) ;
goto V_315;
}
V_37 -> V_201 = V_311 -> V_7 ;
V_37 -> V_316 = 0 ;
V_37 -> V_45 =
F_201 ( sizeof( struct V_38 * ) * V_44 ,
V_314 ) ;
if ( ! V_37 -> V_45 ) {
F_65 (KERN_ERR PFX L_48 ) ;
goto V_317;
}
V_37 -> V_244 = 0 ;
V_37 -> V_309 = F_205 ( V_37 , V_318 ,
V_319 ) ;
if ( ! V_37 -> V_309 ) {
F_65 (KERN_ERR PFX L_49 ) ;
goto V_320;
}
V_313 = & V_37 -> V_313 ;
V_313 -> V_321 = V_322 <<
V_323 ;
V_313 -> V_321 |= V_44 <<
V_324 ;
V_313 -> V_325 = V_326 <<
V_327 ;
V_313 -> V_325 |= V_328 <<
V_329 ;
V_313 -> V_330 = V_44 <<
V_331 ;
V_313 -> V_330 |= V_326 <<
V_332 ;
V_313 -> V_333 = V_334 ;
F_135 ( & V_37 -> V_243 ) ;
F_135 ( & V_37 -> V_219 ) ;
F_206 ( & V_37 -> V_335 ) ;
return V_37 ;
V_320:
F_98 ( V_37 -> V_45 ) ;
V_317:
F_199 ( V_37 ) ;
V_315:
F_98 ( V_37 ) ;
return NULL ;
}
struct V_4 * F_207 ( struct V_36 * V_37 ,
struct V_1 * V_7 ,
enum V_336 V_337 )
{
struct V_10 * V_11 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
int V_338 ;
int V_32 = 0 ;
V_338 = ( sizeof( * V_35 ) + sizeof( struct V_12 ) ) ;
V_11 = F_208 ( & V_7 -> V_99 , & V_339 ,
V_338 ) ;
if ( ! V_11 ) {
F_65 (KERN_ERR PFX L_50 ) ;
return NULL ;
}
V_13 = F_5 ( V_11 ) ;
V_35 = F_6 ( V_13 ) ;
F_209 ( V_7 ) ;
F_210 ( & V_35 -> V_305 ) ;
V_35 -> V_37 = V_37 ;
V_35 -> V_7 = V_7 ;
F_211 ( V_13 , V_337 ) ;
V_13 -> V_340 = F_154 ;
V_13 -> V_341 = F_152 ;
V_13 -> V_342 = F_153 ;
F_113 ( V_306 , & V_35 -> V_307 ) ;
V_32 = F_177 ( V_35 ) ;
if ( ! V_32 )
return V_35 ;
F_190 ( V_13 ) ;
F_192 ( V_7 ) ;
F_191 ( V_11 ) ;
return NULL ;
}
static struct V_2 * F_162 ( struct V_4 * V_35 ,
struct V_184 * V_343 , int V_344 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 , * V_278 ;
struct V_5 * V_34 ;
struct V_155 * V_156 ;
struct V_276 * V_193 = F_212 ( V_343 ) ;
struct V_286 * V_287 ;
struct V_36 * V_37 ;
int V_32 = 0 ;
V_287 = F_201 ( sizeof( struct V_286 ) , V_314 ) ;
if ( ! V_287 ) {
F_34 ( V_13 -> V_16 , L_51 ) ;
return NULL ;
}
if ( ! V_344 )
V_3 = F_213 ( & V_345 , sizeof( * V_34 ) ) ;
else
V_3 = F_214 ( V_193 , sizeof( * V_34 ) ) ;
if ( ! V_3 ) {
F_65 (KERN_ERR PFX L_52 ) ;
goto V_346;
}
V_156 = V_3 -> V_185 ;
V_34 = F_2 ( V_3 ) ;
V_34 -> V_3 = V_3 ;
V_34 -> V_6 = V_35 ;
V_34 -> V_347 = F_1 ;
F_215 ( & V_34 -> V_293 , V_348 ) ;
V_32 = F_147 ( V_3 ) ;
if ( V_32 )
goto V_349;
if ( V_344 ) {
F_65 (KERN_ERR PFX L_53 ,
vport->node_name, vport->port_name) ;
F_122 ( V_3 , V_193 -> V_350 ) ;
F_123 ( V_3 , V_193 -> V_280 ) ;
}
V_32 = F_115 ( V_3 , V_35 -> V_7 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_54 ) ;
goto V_349;
}
V_32 = F_106 ( V_3 , V_343 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_55 ,
interface->netdev->name) ;
goto V_349;
}
V_32 = F_139 ( V_3 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_56 ) ;
goto V_351;
}
F_133 ( V_3 -> V_185 ) = V_240 ;
if ( ! V_344 )
V_32 = F_145 ( V_3 ) ;
else {
V_156 = F_158 ( V_193 ) ;
V_278 = F_100 ( V_156 ) ;
V_32 = F_216 ( V_278 , V_3 ) ;
}
if ( V_32 ) {
F_65 (KERN_ERR PFX L_57 ) ;
goto V_351;
}
F_194 ( V_35 ) ;
V_37 = V_35 -> V_37 ;
F_8 ( & V_37 -> V_43 ) ;
V_287 -> V_3 = V_3 ;
F_217 ( & V_287 -> V_22 , & V_37 -> V_335 ) ;
F_12 ( & V_37 -> V_43 ) ;
return V_3 ;
V_351:
F_218 ( V_156 ) ;
V_349:
F_219 ( V_3 -> V_185 ) ;
V_346:
F_98 ( V_287 ) ;
return NULL ;
}
static void F_220 ( struct V_4 * V_35 )
{
F_221 ( & V_35 -> V_124 ) ;
F_221 ( & V_35 -> V_273 ) ;
F_222 () ;
}
static void F_223 ( struct V_4 * V_35 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 = V_13 -> V_16 ;
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_36 * V_37 = V_35 -> V_37 ;
F_224 ( & V_34 -> V_214 ) ;
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
F_174 ( V_292 , & V_34 -> V_293 ) ;
}
static int F_230 ( struct V_1 * V_7 )
{
struct V_4 * V_35 = NULL ;
struct V_352 * V_353 ;
struct V_12 * V_13 ;
int V_32 = 0 ;
F_161 () ;
F_20 ( & V_233 ) ;
V_35 = F_231 ( V_7 ) ;
V_13 = F_32 ( V_35 ) ;
if ( ! V_35 || ! V_13 -> V_16 ) {
V_32 = - V_64 ;
F_65 (KERN_ERR PFX L_58 ) ;
goto V_354;
}
V_353 = V_35 -> V_353 ;
F_127 ( V_35 ) ;
F_232 ( V_353 ) ;
V_354:
F_23 ( & V_233 ) ;
F_163 () ;
return V_32 ;
}
static void V_348 ( struct V_355 * V_149 )
{
struct V_5 * V_34 ;
struct V_2 * V_3 ;
V_34 = F_64 ( V_149 , struct V_5 , V_293 ) ;
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
goto V_356;
if ( F_238 ( V_37 ) )
goto V_356;
return 0 ;
V_356:
F_233 ( V_37 ) ;
return - V_65 ;
}
static int F_204 ( struct V_36 * V_37 )
{
struct V_310 * V_311 ;
if ( ! V_37 -> V_311 ) {
F_65 (KERN_ERR PFX L_60 ) ;
return - V_64 ;
}
V_311 = V_37 -> V_311 ;
V_37 -> V_357 = V_311 -> V_357 ;
if ( V_37 -> V_357 )
F_239 ( V_37 -> V_357 ) ;
return 0 ;
}
static void F_199 ( struct V_36 * V_37 )
{
if ( V_37 -> V_357 )
F_240 ( V_37 -> V_357 ) ;
V_37 -> V_357 = NULL ;
}
static int F_241 ( void * V_358 )
{
struct V_36 * V_37 = V_358 ;
struct V_310 * V_311 ;
struct V_359 * V_360 ;
if ( ! V_37 )
return - V_82 ;
V_311 = V_37 -> V_311 ;
V_360 = & V_311 -> V_360 -> V_361 ;
if ( ! V_360 )
return - V_82 ;
strncpy ( V_360 -> V_362 , V_199 ,
sizeof( V_360 -> V_362 ) ) ;
V_360 -> V_363 = V_364 ;
V_360 -> V_365 = V_366 ;
return 0 ;
}
static void F_242 ( void * V_358 )
{
struct V_36 * V_37 = V_358 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
struct V_2 * V_3 ;
F_20 ( & V_233 ) ;
if ( ! F_41 ( V_281 , & V_37 -> V_85 ) )
F_243 ( V_37 ) ;
F_19 ( L_61 ) ;
F_128 (interface, &if_list, list) {
if ( V_35 -> V_37 == V_37 ) {
V_13 = F_32 ( V_35 ) ;
V_3 = V_13 -> V_16 ;
F_65 (KERN_ERR PFX L_62 ) ;
V_3 -> V_246 . V_367 = F_31 ;
F_244 ( V_35 ) ;
}
}
F_23 ( & V_233 ) ;
}
static void F_172 ( struct V_2 * V_3 )
{
F_19 ( L_1 , V_41 ) ;
F_176 ( V_3 ) ;
F_245 ( V_3 ) ;
}
static void F_229 ( struct V_4 * V_35 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 ;
struct V_2 * V_193 ;
if ( ! F_41 ( V_281 , & V_35 -> V_37 -> V_85 ) )
return;
V_3 = V_13 -> V_16 ;
F_172 ( V_3 ) ;
F_20 ( & V_3 -> V_239 ) ;
F_128 (vport, &lport->vports, list)
F_133 ( V_193 -> V_185 ) =
V_240 ;
F_23 ( & V_3 -> V_239 ) ;
F_133 ( V_3 -> V_185 ) = V_240 ;
F_132 ( V_13 ) ;
F_134 ( V_3 ) ;
}
static int F_243 ( struct V_36 * V_37 )
{
#define F_246 (1000 / HZ)
int V_32 = - 1 ;
int V_40 = V_162 ;
V_32 = F_236 ( V_37 ) ;
if ( V_32 ) {
F_65 (KERN_ALERT PFX
L_63 , rc) ;
goto V_368;
}
V_32 = F_247 ( V_37 ) ;
if ( V_32 ) {
F_65 (KERN_ALERT PFX
L_64 , rc) ;
goto V_369;
}
while ( ! F_41 ( V_227 , & V_37 -> V_204 ) && V_40 -- )
F_248 ( F_246 ) ;
if ( ! F_41 ( V_227 , & V_37 -> V_204 ) ) {
F_65 (KERN_ERR PFX L_65
L_66 ,
hba->cnic->netdev->name) ;
V_32 = - 1 ;
goto V_369;
}
F_113 ( V_281 , & V_37 -> V_85 ) ;
return 0 ;
V_369:
F_233 ( V_37 ) ;
V_368:
return V_32 ;
}
static void F_249 ( struct V_36 * V_37 )
{
if ( F_189 ( V_281 , & V_37 -> V_85 ) ) {
if ( F_250 ( V_37 ) == 0 ) {
F_251 ( & V_37 -> V_370 ) ;
V_37 -> V_370 . V_371 = V_372 +
V_285 ;
V_37 -> V_370 . V_373 = F_124 ;
V_37 -> V_370 . V_144 = ( unsigned long ) V_37 ;
F_252 ( & V_37 -> V_370 ) ;
F_136 ( V_37 -> V_219 ,
F_41 ( V_218 ,
& V_37 -> V_85 ) ) ;
F_112 ( V_218 , & V_37 -> V_85 ) ;
if ( F_137 ( V_130 ) )
F_138 ( V_130 ) ;
F_224 ( & V_37 -> V_370 ) ;
}
F_233 ( V_37 ) ;
}
}
static void F_253 ( void * V_358 )
{
struct V_36 * V_37 = V_358 ;
struct V_4 * V_35 ;
F_65 ( V_228 L_67 ) ;
F_20 ( & V_233 ) ;
if ( ! F_41 ( V_281 , & V_37 -> V_85 ) )
goto exit;
F_128 (interface, &if_list, list) {
if ( V_35 -> V_37 == V_37 )
F_229 ( V_35 ) ;
}
F_254 ( V_37 -> V_244 != 0 ) ;
F_20 ( & V_37 -> V_42 ) ;
F_112 ( V_227 , & V_37 -> V_204 ) ;
F_112 ( V_230 ,
& V_37 -> V_204 ) ;
F_112 ( V_242 , & V_37 -> V_204 ) ;
F_23 ( & V_37 -> V_42 ) ;
F_249 ( V_37 ) ;
exit:
F_23 ( & V_233 ) ;
}
static void F_244 ( struct V_4 * V_35 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 ;
int V_374 = 0 ;
F_19 ( L_1 , V_41 ) ;
if ( ! F_41 ( V_281 , & V_35 -> V_37 -> V_85 ) ) {
F_65 (KERN_ERR PFX L_68 ) ;
return;
}
V_3 = V_13 -> V_16 ;
F_34 ( V_3 , L_69 ) ;
if ( ! F_110 ( V_3 ) && V_35 -> V_235 ) {
F_34 ( V_3 , L_70 ) ;
F_131 ( V_13 ) ;
F_133 ( V_3 -> V_185 ) = V_375 ;
F_113 ( V_242 , & V_35 -> V_37 -> V_204 ) ;
}
while ( ! V_13 -> V_81 ) {
F_248 ( 250 ) ;
if ( ++ V_374 > 12 )
break;
}
if ( F_116 ( V_3 , V_212 ) )
return;
F_166 ( V_3 ) ;
F_167 ( V_3 ) ;
}
static void F_255 ( struct V_310 * V_99 )
{
struct V_36 * V_37 ;
int V_32 = 0 ;
F_19 ( L_1 , V_41 ) ;
if ( ! F_41 ( V_376 , & V_99 -> V_85 ) ||
( V_99 -> V_377 == 0 ) ) {
F_65 (KERN_ERR PFX L_71
L_72 ,
dev->netdev->name, dev->flags, dev->max_fcoe_conn) ;
return;
}
V_37 = F_200 ( V_99 ) ;
if ( ! V_37 ) {
F_65 (KERN_ERR PFX L_73 ) ;
return;
}
F_20 ( & V_233 ) ;
F_217 ( & V_37 -> V_22 , & V_378 ) ;
V_379 ++ ;
F_23 ( & V_233 ) ;
V_99 -> V_313 = & V_37 -> V_313 ;
F_112 ( V_380 , & V_37 -> V_381 ) ;
V_32 = V_99 -> V_382 ( V_99 , V_383 ,
( void * ) V_37 ) ;
if ( V_32 )
F_65 (KERN_ERR PFX L_74 , rc) ;
else
F_113 ( V_380 , & V_37 -> V_381 ) ;
}
static int F_256 ( struct V_1 * V_7 )
{
struct V_4 * V_35 ;
struct V_12 * V_13 ;
int V_32 = 0 ;
F_161 () ;
F_20 ( & V_233 ) ;
V_35 = F_231 ( V_7 ) ;
V_13 = F_32 ( V_35 ) ;
if ( ! V_35 || ! V_13 -> V_16 ) {
V_32 = - V_64 ;
F_65 (KERN_ERR PFX L_75 ) ;
} else {
V_35 -> V_235 = false ;
F_132 ( V_13 ) ;
F_134 ( V_13 -> V_16 ) ;
}
F_23 ( & V_233 ) ;
F_163 () ;
return V_32 ;
}
static int F_257 ( struct V_1 * V_7 )
{
struct V_4 * V_35 ;
struct V_12 * V_13 ;
int V_32 = 0 ;
F_161 () ;
F_20 ( & V_233 ) ;
V_35 = F_231 ( V_7 ) ;
V_13 = F_32 ( V_35 ) ;
if ( ! V_35 || ! V_13 -> V_16 ) {
V_32 = - V_64 ;
F_65 (KERN_ERR PFX L_76 ) ;
} else if ( ! F_110 ( V_13 -> V_16 ) ) {
F_131 ( V_13 ) ;
V_35 -> V_235 = true ;
}
F_23 ( & V_233 ) ;
F_163 () ;
return V_32 ;
}
static int F_258 ( struct V_10 * V_222 )
{
struct V_12 * V_13 = F_5 ( V_222 ) ;
struct V_2 * V_3 = V_13 -> V_16 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
switch ( V_222 -> V_235 ) {
case V_237 :
return F_257 ( V_7 ) ;
case V_236 :
return F_256 ( V_7 ) ;
case V_238 :
default:
return - V_384 ;
} ;
}
static int F_259 ( struct V_1 * V_7 ,
enum V_336 V_337 ,
enum V_385 V_386 )
{
struct V_10 * V_222 ;
struct V_12 * V_13 ;
struct V_4 * V_35 ;
struct V_36 * V_37 ;
struct V_1 * V_201 = V_7 ;
struct V_2 * V_3 ;
struct V_387 V_388 ;
int V_32 = 0 ;
int V_15 = 0 ;
F_19 ( L_77 ) ;
if ( V_337 != V_389 ) {
F_65 ( V_228 L_78 ) ;
return - V_282 ;
}
F_161 () ;
F_20 ( & V_233 ) ;
if ( ! F_260 ( V_308 ) ) {
V_32 = - V_82 ;
goto V_390;
}
if ( V_7 -> V_391 & V_392 )
V_201 = F_261 ( V_7 ) ;
if ( V_201 -> V_209 && V_201 -> V_209 -> V_393 ) {
memset ( & V_388 , 0 , sizeof( V_388 ) ) ;
V_201 -> V_209 -> V_393 ( V_201 , & V_388 ) ;
if ( strncmp ( V_388 . V_394 , L_79 , strlen ( L_79 ) ) ) {
F_65 (KERN_ERR PFX L_80 ) ;
V_32 = - V_82 ;
goto V_354;
}
} else {
F_65 (KERN_ERR PFX L_81 ) ;
V_32 = - V_82 ;
goto V_354;
}
V_37 = F_262 ( V_201 ) ;
if ( ! V_37 ) {
V_32 = - V_64 ;
F_65 (KERN_ERR PFX L_82 ) ;
goto V_354;
}
if ( F_231 ( V_7 ) ) {
V_32 = - V_395 ;
goto V_354;
}
V_35 = F_207 ( V_37 , V_7 , V_337 ) ;
if ( ! V_35 ) {
F_65 (KERN_ERR PFX L_83 ) ;
goto V_396;
}
if ( V_7 -> V_391 & V_392 ) {
V_15 = F_263 ( V_7 ) ;
V_35 -> V_397 = 1 ;
}
V_13 = F_32 ( V_35 ) ;
V_222 = F_129 ( V_13 ) ;
V_35 -> V_15 = V_15 ;
V_35 -> V_353 =
F_264 ( L_84 ) ;
if ( ! V_35 -> V_353 ) {
F_65 (KERN_ERR PFX L_85 ) ;
V_32 = - V_82 ;
goto V_396;
}
V_3 = F_162 ( V_35 , & V_222 -> V_99 , 0 ) ;
if ( ! V_3 ) {
F_65 (KERN_ERR PFX L_86 ,
netdev->name) ;
V_32 = - V_82 ;
goto V_398;
}
F_217 ( & V_35 -> V_22 , & V_399 ) ;
V_3 -> V_284 = V_285 ;
V_13 -> V_16 = V_3 ;
if ( V_386 == V_400 )
V_222 -> V_235 = V_237 ;
else
V_222 -> V_235 = V_236 ;
if ( V_386 == V_400 &&
! F_110 ( V_3 ) ) {
F_131 ( V_13 ) ;
F_133 ( V_3 -> V_185 ) = V_375 ;
F_113 ( V_242 , & V_35 -> V_37 -> V_204 ) ;
}
F_34 ( V_3 , L_87 ) ;
F_244 ( V_35 ) ;
if ( V_386 == V_400 )
V_35 -> V_235 = true ;
F_173 ( V_35 ) ;
F_23 ( & V_233 ) ;
F_163 () ;
return 0 ;
V_398:
F_232 ( V_35 -> V_353 ) ;
V_396:
F_220 ( V_35 ) ;
F_173 ( V_35 ) ;
goto V_390;
V_354:
F_193 ( V_308 ) ;
V_390:
F_23 ( & V_233 ) ;
F_163 () ;
return V_32 ;
}
static int F_265 ( struct V_1 * V_7 , enum V_336 V_337 )
{
return F_259 ( V_7 , V_337 , V_400 ) ;
}
static int F_266 ( struct V_1 * V_7 )
{
return F_259 ( V_7 , V_389 ,
V_401 ) ;
}
static struct V_36 * F_267 ( struct V_310 * V_311 )
{
struct V_36 * V_37 ;
F_128 (hba, &adapter_list, list) {
if ( V_37 -> V_311 == V_311 )
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
static struct V_36 * F_262 ( struct V_1
* V_201 )
{
struct V_36 * V_37 ;
F_128 (hba, &adapter_list, list) {
if ( V_37 -> V_201 == V_201 )
return V_37 ;
}
F_65 (KERN_ERR PFX L_88 ) ;
return NULL ;
}
static void F_268 ( struct V_310 * V_99 )
{
struct V_36 * V_37 ;
struct V_4 * V_35 , * V_150 ;
F_19 ( L_89 ) ;
if ( ! F_41 ( V_376 , & V_99 -> V_85 ) ) {
F_65 (KERN_ERR PFX L_90 ,
dev->netdev->name, dev->flags) ;
return;
}
F_20 ( & V_233 ) ;
V_37 = F_267 ( V_99 ) ;
if ( ! V_37 ) {
F_65 (KERN_ERR PFX L_91 ,
dev) ;
F_23 ( & V_233 ) ;
return;
}
F_96 ( & V_37 -> V_22 ) ;
V_379 -- ;
F_95 (interface, tmp, &if_list, list)
if ( V_35 -> V_37 == V_37 )
F_127 ( V_35 ) ;
F_23 ( & V_233 ) ;
F_253 ( V_37 ) ;
if ( F_189 ( V_380 , & V_37 -> V_381 ) )
V_37 -> V_311 -> V_402 ( V_37 -> V_311 , V_383 ) ;
F_197 ( V_37 ) ;
}
static int F_269 ( struct V_155 * V_156 )
{
struct V_2 * V_3 = F_100 ( V_156 ) ;
F_270 ( V_3 ) ;
return 0 ;
}
static bool F_271 ( struct V_1 * V_7 )
{
struct V_1 * V_201 = V_7 ;
F_20 ( & V_233 ) ;
if ( V_7 -> V_391 & V_392 )
V_201 = F_261 ( V_7 ) ;
if ( F_262 ( V_201 ) ) {
F_23 ( & V_233 ) ;
return true ;
}
F_23 ( & V_233 ) ;
return false ;
}
static void F_272 ( unsigned int V_403 )
{
struct V_146 * V_147 ;
struct V_404 * V_128 ;
V_147 = & F_273 ( V_405 , V_403 ) ;
V_128 = F_274 ( F_91 ,
( void * ) V_147 , F_275 ( V_403 ) ,
L_92 , V_403 ) ;
if ( F_276 ( ! F_164 ( V_128 ) ) ) {
F_277 ( V_128 , V_403 ) ;
V_147 -> V_406 = V_128 ;
F_70 ( V_128 ) ;
}
}
static void F_278 ( unsigned int V_403 )
{
struct V_146 * V_147 ;
struct V_404 * V_128 ;
struct V_148 * V_149 , * V_150 ;
F_19 ( L_93 , V_403 ) ;
V_147 = & F_273 ( V_405 , V_403 ) ;
F_8 ( & V_147 -> V_152 ) ;
V_128 = V_147 -> V_406 ;
V_147 -> V_406 = NULL ;
F_95 (work, tmp, &p->work_list, list) {
F_96 ( & V_149 -> V_22 ) ;
F_97 ( V_149 -> V_39 , V_149 -> V_153 ) ;
F_98 ( V_149 ) ;
}
F_12 ( & V_147 -> V_152 ) ;
if ( V_128 )
F_279 ( V_128 ) ;
}
static int F_280 ( struct V_407 * V_408 ,
unsigned long V_409 , void * V_410 )
{
unsigned V_403 = ( unsigned long ) V_410 ;
switch ( V_409 ) {
case V_411 :
case V_412 :
F_65 ( V_413 L_94 , V_403 ) ;
F_272 ( V_403 ) ;
break;
case V_414 :
case V_415 :
F_65 ( V_413 L_95 , V_403 ) ;
F_278 ( V_403 ) ;
break;
default:
break;
}
return V_416 ;
}
static int T_6 F_281 ( void )
{
struct V_17 * V_18 ;
struct V_404 * V_417 ;
int V_32 = 0 ;
unsigned int V_403 = 0 ;
struct V_146 * V_147 ;
F_65 (KERN_INFO PFX L_96 , version) ;
V_32 = F_282 ( & V_418 ) ;
if ( V_32 ) {
F_65 ( V_228 L_97
L_98 ) ;
goto V_419;
}
F_206 ( & V_378 ) ;
F_206 ( & V_399 ) ;
F_203 ( & V_233 ) ;
V_379 = 0 ;
V_32 = F_184 () ;
if ( V_32 )
goto V_420;
V_292 = F_283 ( L_99 , 0 , 0 ) ;
if ( ! V_292 ) {
V_32 = - V_65 ;
goto V_421;
}
V_18 = & V_27 ;
F_117 ( & V_18 -> V_28 ) ;
V_417 = F_284 ( F_71 ,
( void * ) V_18 ,
L_100 ) ;
if ( F_164 ( V_417 ) ) {
V_32 = F_285 ( V_417 ) ;
goto V_422;
}
F_70 ( V_417 ) ;
F_8 ( & V_18 -> V_28 . V_29 ) ;
V_18 -> V_128 = V_417 ;
F_12 ( & V_18 -> V_28 . V_29 ) ;
F_286 (cpu) {
V_147 = & F_273 ( V_405 , V_403 ) ;
F_206 ( & V_147 -> V_151 ) ;
F_202 ( & V_147 -> V_152 ) ;
}
F_287 (cpu) {
F_272 ( V_403 ) ;
}
F_288 ( & V_423 ) ;
F_289 ( V_383 , & V_424 ) ;
return 0 ;
V_422:
F_232 ( V_292 ) ;
V_421:
F_187 () ;
V_420:
F_290 ( & V_418 ) ;
V_419:
return V_32 ;
}
static void T_7 F_291 ( void )
{
F_92 ( V_425 ) ;
struct V_36 * V_37 , * V_25 ;
struct V_17 * V_18 ;
struct V_404 * V_417 ;
struct V_23 * V_24 ;
unsigned int V_403 = 0 ;
F_20 ( & V_233 ) ;
F_292 ( & V_378 , & V_425 ) ;
F_206 ( & V_378 ) ;
V_379 = 0 ;
F_23 ( & V_233 ) ;
F_95 (hba, next, &to_be_deleted, list) {
F_96 ( & V_37 -> V_22 ) ;
F_65 (KERN_ERR PFX L_101 ,
hba) ;
F_253 ( V_37 ) ;
if ( F_189 ( V_380 ,
& V_37 -> V_381 ) )
V_37 -> V_311 -> V_402 ( V_37 -> V_311 ,
V_383 ) ;
F_197 ( V_37 ) ;
}
F_293 ( V_383 ) ;
V_18 = & V_27 ;
F_8 ( & V_18 -> V_28 . V_29 ) ;
V_417 = V_18 -> V_128 ;
V_18 -> V_128 = NULL ;
while ( ( V_24 = F_76 ( & V_18 -> V_28 ) ) != NULL )
F_11 ( V_24 ) ;
F_12 ( & V_18 -> V_28 . V_29 ) ;
if ( V_417 )
F_279 ( V_417 ) ;
F_294 ( & V_423 ) ;
F_287 (cpu) {
F_278 ( V_403 ) ;
}
F_232 ( V_292 ) ;
F_187 () ;
F_290 ( & V_418 ) ;
}
