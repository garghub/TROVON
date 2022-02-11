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
V_69 = F_47 ( V_24 , V_31 ) ;
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
struct V_5 * V_34 , * V_139 ;
T_1 * V_140 = NULL ;
T_1 * V_141 = NULL ;
struct V_70 * V_71 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
V_20 = F_9 ( V_24 ) ;
V_3 = V_20 -> V_30 ;
if ( F_35 ( V_3 == NULL ) ) {
F_65 (KERN_ERR PFX L_14 ) ;
F_11 ( V_24 ) ;
return;
}
if ( F_43 ( V_24 ) )
F_80 ( V_24 ) ;
V_140 = F_54 ( V_24 ) -> V_107 ;
V_141 = F_54 ( V_24 ) -> V_102 ;
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
V_139 = F_2 ( V_3 ) ;
V_35 = V_139 -> V_6 ;
V_13 = F_32 ( V_35 ) ;
V_51 = F_25 ( V_47 ) ;
if ( F_40 ( & V_141 [ 3 ] ) != F_40 ( V_51 -> V_83 ) ) {
F_34 ( V_3 , L_15 ,
V_141 ) ;
F_11 ( V_24 ) ;
return;
}
V_138 = F_87 ( V_3 , F_40 ( V_51 -> V_83 ) ) ;
if ( V_138 ) {
V_34 = F_2 ( V_138 ) ;
if ( ! F_88 ( V_34 -> V_109 , V_141 ) ) {
F_34 ( V_3 , L_16 ) ;
F_11 ( V_24 ) ;
return;
}
}
if ( V_13 -> V_142 ) {
if ( ! F_88 ( V_140 , V_13 -> V_103 ) ) {
F_34 ( V_3 , L_17 ,
V_140 , V_13 -> V_103 ) ;
F_11 ( V_24 ) ;
return;
}
}
if ( V_51 -> V_55 == V_143 &&
V_51 -> V_56 == V_144 ) {
F_11 ( V_24 ) ;
return;
}
if ( V_51 -> V_55 == V_58 &&
V_51 -> V_56 == V_57 ) {
switch ( F_27 ( V_47 ) ) {
case V_60 :
if ( F_40 ( V_51 -> V_145 ) == V_146 ) {
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
if ( V_3 -> V_53 != F_40 ( V_51 -> V_83 ) && ! V_138 ) {
F_34 ( V_3 , L_18 ,
V_3 -> V_53 , F_40 ( V_51 -> V_83 ) ) ;
F_11 ( V_24 ) ;
return;
}
V_73 = F_58 ( V_3 -> V_73 , F_89 () ) ;
V_73 -> V_147 ++ ;
V_73 -> V_148 += V_136 / V_87 ;
if ( F_90 ( F_85 ( V_47 ) ) !=
~ F_91 ( ~ 0 , V_24 -> V_149 , V_136 ) ) {
if ( V_73 -> V_150 < 5 )
F_65 (KERN_WARNING PFX L_19
L_20 ) ;
V_73 -> V_150 ++ ;
F_11 ( V_24 ) ;
return;
}
F_92 ( V_3 , V_47 ) ;
}
static int F_93 ( void * V_131 )
{
struct V_151 * V_152 = V_131 ;
struct V_153 * V_154 , * V_155 ;
F_94 ( V_156 ) ;
F_73 ( V_132 , V_133 ) ;
F_74 ( V_134 ) ;
while ( ! F_75 () ) {
F_76 () ;
F_8 ( & V_152 -> V_157 ) ;
while ( ! F_95 ( & V_152 -> V_156 ) ) {
F_96 ( & V_152 -> V_156 , & V_156 ) ;
F_12 ( & V_152 -> V_157 ) ;
F_97 (work, tmp, &work_list, list) {
F_98 ( & V_154 -> V_22 ) ;
F_99 ( V_154 -> V_39 , V_154 -> V_158 ) ;
F_100 ( V_154 ) ;
}
F_8 ( & V_152 -> V_157 ) ;
}
F_79 ( V_134 ) ;
F_12 ( & V_152 -> V_157 ) ;
}
F_79 ( V_135 ) ;
return 0 ;
}
static struct V_159 * F_101 ( struct V_160 * V_161 )
{
struct V_159 * V_162 ;
struct V_2 * V_3 = F_102 ( V_161 ) ;
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_163 * V_164 ;
int V_32 = 0 ;
V_164 = (struct V_163 * ) V_37 -> V_165 ;
if ( ! V_164 )
return NULL ;
F_20 ( & V_37 -> V_166 ) ;
V_162 = F_103 ( V_161 ) ;
F_104 ( & V_37 -> V_167 ) ;
if ( F_105 ( V_37 ) )
goto V_168;
V_32 = F_106 ( & V_37 -> V_167 , ( 2 * V_169 ) ) ;
if ( ! V_32 ) {
F_34 ( V_3 , L_21 ) ;
goto V_168;
}
F_107 ( V_37 , V_170 , V_171 ) ;
V_162 -> V_172 += V_37 -> V_173 . V_171 ;
F_107 ( V_37 , V_174 , V_175 ) ;
V_162 -> V_176 += V_37 -> V_173 . V_175 ;
F_107 ( V_37 , V_174 , V_177 ) ;
V_162 -> V_178 += ( ( V_37 -> V_173 . V_177 ) / 4 ) ;
F_107 ( V_37 , V_179 , V_180 ) ;
V_162 -> V_181 += V_37 -> V_173 . V_180 ;
F_107 ( V_37 , V_179 , V_182 ) ;
V_162 -> V_183 += ( ( V_37 -> V_173 . V_182 ) / 4 ) ;
V_162 -> V_184 = 0 ;
V_162 -> V_185 = 0 ;
V_162 -> V_186 = 0 ;
V_162 -> V_187 = 0 ;
V_162 -> V_188 = 0 ;
V_162 -> V_189 = 0 ;
memcpy ( & V_37 -> V_190 , V_37 -> V_165 ,
sizeof( struct V_163 ) ) ;
V_168:
F_23 ( & V_37 -> V_166 ) ;
return V_162 ;
}
static int F_108 ( struct V_2 * V_3 , struct V_191 * V_99 )
{
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_160 * V_161 = V_3 -> V_192 ;
int V_32 = 0 ;
V_161 -> V_193 = V_194 ;
V_161 -> V_195 = V_196 ;
V_161 -> V_197 = V_198 ;
V_161 -> V_199 = 0 ;
if ( V_3 -> V_200 )
V_161 -> V_201 = V_202 ;
else
V_161 -> V_201 = V_203 ;
V_32 = F_109 ( V_3 -> V_192 , V_99 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_22 ) ;
return V_32 ;
}
if ( ! V_3 -> V_200 )
F_110 ( V_3 -> V_192 ) = V_204 ;
snprintf ( F_111 ( V_3 -> V_192 ) , 256 ,
L_23 ,
V_205 , V_37 -> V_206 , V_207 ,
V_35 -> V_7 -> V_208 ) ;
return 0 ;
}
static int F_112 ( struct V_2 * V_3 )
{
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_1 * V_99 = V_37 -> V_209 ;
int V_32 = 0 ;
if ( ( V_99 -> V_85 & V_210 ) && F_113 ( V_99 ) )
F_114 ( V_211 , & V_37 -> V_212 ) ;
else {
F_115 ( V_211 , & V_37 -> V_212 ) ;
V_32 = - 1 ;
}
return V_32 ;
}
void F_116 ( struct V_36 * V_37 )
{
if ( F_41 ( V_213 , & V_37 -> V_209 -> V_142 ) )
F_115 ( V_211 , & V_37 -> V_212 ) ;
else
F_114 ( V_211 , & V_37 -> V_212 ) ;
}
static int F_117 ( struct V_2 * V_3 , struct V_1 * V_7 )
{
struct V_36 * V_37 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
struct V_5 * V_34 ;
T_4 V_214 , V_215 ;
V_34 = F_2 ( V_3 ) ;
V_35 = V_34 -> V_6 ;
V_13 = F_32 ( V_35 ) ;
V_37 = V_35 -> V_37 ;
if ( ! V_37 -> V_209 -> V_216 ||
! V_37 -> V_209 -> V_216 -> V_217 )
return - V_218 ;
if ( F_118 ( V_3 , V_219 ) )
return - V_82 ;
F_119 ( & V_34 -> V_118 ) ;
V_34 -> V_220 = 0 ;
F_120 ( & V_34 -> V_221 , V_222 , ( unsigned long ) V_3 ) ;
F_121 ( V_3 ) ;
if ( ! V_3 -> V_200 ) {
if ( F_122 ( V_7 , & V_214 , V_223 ) )
V_214 = F_123 ( V_13 -> V_108 ,
1 , 0 ) ;
F_34 ( V_3 , L_24 , V_214 ) ;
F_124 ( V_3 , V_214 ) ;
if ( F_122 ( V_7 , & V_215 , V_224 ) )
V_215 = F_123 ( V_13 -> V_108 ,
2 , 0 ) ;
F_34 ( V_3 , L_25 , V_215 ) ;
F_125 ( V_3 , V_215 ) ;
}
return 0 ;
}
static void F_126 ( unsigned long V_149 )
{
struct V_36 * V_37 = (struct V_36 * ) V_149 ;
F_65 (KERN_ERR PFX L_26
L_27 ) ;
F_115 ( V_225 , & V_37 -> V_85 ) ;
F_127 ( & V_37 -> V_226 ) ;
}
static void F_128 ( void * V_227 , unsigned long V_228 ,
T_5 V_15 )
{
struct V_36 * V_37 = (struct V_36 * ) V_227 ;
struct V_10 * V_229 ;
struct V_2 * V_3 ;
struct V_2 * V_200 ;
struct V_4 * V_35 , * V_155 ;
struct V_12 * V_13 ;
int V_230 = 0 ;
T_2 V_231 = 1 ;
if ( V_15 != 0 && V_228 != V_232 )
return;
switch ( V_228 ) {
case V_233 :
if ( ! F_41 ( V_234 , & V_37 -> V_212 ) )
F_65 ( V_235 L_28\
L_29 ) ;
break;
case V_236 :
F_114 ( V_237 , & V_37 -> V_212 ) ;
F_114 ( V_234 , & V_37 -> V_212 ) ;
V_231 = 0 ;
break;
case V_238 :
F_115 ( V_237 , & V_37 -> V_212 ) ;
V_231 = 0 ;
break;
case V_239 :
break;
case V_232 :
if ( ! V_15 )
return;
F_20 ( & V_240 ) ;
F_97 (interface, tmp, &if_list, list) {
if ( V_35 -> V_37 == V_37 &&
V_35 -> V_15 == ( V_15 & V_241 ) )
F_129 ( V_35 ) ;
}
F_23 ( & V_240 ) ;
F_130 ( V_242 ) ;
return;
default:
return;
}
F_20 ( & V_240 ) ;
F_131 (interface, &if_list, list) {
if ( V_35 -> V_37 != V_37 )
continue;
V_13 = F_32 ( V_35 ) ;
V_3 = V_13 -> V_16 ;
F_34 ( V_3 , L_30 ,
V_35 -> V_7 -> V_208 , V_228 ) ;
F_121 ( V_3 ) ;
V_229 = F_132 ( V_13 ) ;
if ( V_231 && ! F_112 ( V_3 ) ) {
switch ( V_229 -> V_243 ) {
case V_244 :
F_133 ( L_31 ) ;
break;
case V_245 :
case V_246 :
F_118 ( V_3 , V_219 ) ;
if ( V_35 -> V_243 )
F_134 ( V_13 ) ;
} ;
} else if ( F_135 ( V_13 ) ) {
switch ( V_229 -> V_243 ) {
case V_244 :
F_133 ( L_32 ) ;
break;
case V_245 :
case V_246 :
F_20 ( & V_3 -> V_247 ) ;
F_131 (vport, &lport->vports, list)
F_136 ( V_200 -> V_192 ) =
V_248 ;
F_23 ( & V_3 -> V_247 ) ;
F_136 ( V_3 -> V_192 ) =
V_248 ;
F_58 ( V_3 -> V_73 ,
F_59 () ) -> V_249 ++ ;
F_60 () ;
F_137 ( V_3 ) ;
V_230 = 1 ;
} ;
}
}
F_23 ( & V_240 ) ;
if ( V_230 ) {
F_114 ( V_250 , & V_37 -> V_212 ) ;
F_138 ( & V_37 -> V_251 ) ;
F_19 ( L_33
L_34 ,
V_37 -> V_252 ) ;
V_37 -> V_253 = 1 ;
F_139 ( V_37 -> V_251 ,
( V_37 -> V_252 == 0 ) ) ;
F_19 ( L_35 ,
V_37 -> V_252 ) ;
V_37 -> V_253 = 0 ;
if ( F_140 ( V_132 ) )
F_141 ( V_132 ) ;
}
}
static int F_142 ( struct V_2 * V_3 )
{
memcpy ( & V_3 -> V_254 , & V_255 ,
sizeof( struct V_256 ) ) ;
F_143 ( V_3 ) ;
F_144 ( V_3 ) ;
F_145 ( V_3 ) ;
F_146 ( V_3 , V_3 ) ;
return 0 ;
}
static int F_147 ( struct V_2 * V_3 , struct V_36 * V_37 )
{
int V_257 , V_258 ;
V_257 = V_37 -> V_259 + 1 ;
if ( V_260 <= 2 )
V_258 = V_37 -> V_259 + V_261 ;
else
V_258 = V_37 -> V_259 + V_262 ;
if ( ! F_148 ( V_3 , V_263 , V_257 ,
V_258 , NULL ) ) {
F_65 (KERN_ERR PFX L_36 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_149 ( struct V_2 * V_3 )
{
V_3 -> V_80 = 0 ;
V_3 -> V_264 = 0 ;
V_3 -> V_265 = V_266 ;
V_3 -> V_267 = V_268 ;
V_3 -> V_269 = 2 * 1000 ;
V_3 -> V_270 = 10 * 1000 ;
V_3 -> V_271 = ( V_272 | V_273 |
V_274 | V_275 ) ;
V_3 -> V_276 = 1 ;
memset ( & V_3 -> V_277 , 0 , sizeof( struct V_278 ) ) ;
V_3 -> V_277 . V_279 = V_280 ;
if ( F_150 ( V_3 ) )
return - V_65 ;
F_151 ( V_3 ) ;
return 0 ;
}
static int F_152 ( struct V_23 * V_24 , struct V_1 * V_99 ,
struct V_120 * V_121 ,
struct V_1 * V_281 )
{
struct V_4 * V_35 ;
struct V_12 * V_13 ;
V_35 = F_64 ( V_121 , struct V_4 ,
V_282 ) ;
V_13 = F_32 ( V_35 ) ;
F_153 ( V_13 , V_24 ) ;
return 0 ;
}
static void F_154 ( struct V_2 * V_3 , T_1 * V_283 )
{
struct V_5 * V_34 = F_2 ( V_3 ) ;
memcpy ( V_34 -> V_109 , V_283 , V_104 ) ;
}
static T_1 * F_155 ( struct V_2 * V_3 )
{
struct V_5 * V_34 ;
V_34 = (struct V_5 * ) F_2 ( V_3 ) ;
return V_34 -> V_109 ;
}
static void F_156 ( struct V_12 * V_284 , struct V_23 * V_24 )
{
struct V_285 * V_286 ;
struct V_66 * F_54 ;
T_5 V_287 ;
T_1 V_288 ;
V_286 = (struct V_285 * ) ( ( void * ) V_24 -> V_149 + 2 * V_104 + 2 ) ;
F_54 = (struct V_66 * ) F_157 ( V_24 ) ;
V_287 = F_26 ( V_286 -> V_289 ) ;
V_288 = V_286 -> V_290 ;
if ( V_287 == V_291 && V_288 == V_292 && V_293 )
F_19 ( L_37 ,
F_54 -> V_107 , F_54 -> V_102 ) ;
V_24 -> V_99 = F_158 ( V_284 ) -> V_7 ;
F_159 ( V_24 ) ;
}
static int F_160 ( struct V_294 * V_200 , bool V_295 )
{
struct V_160 * V_161 = F_161 ( V_200 ) ;
struct V_2 * V_296 = F_102 ( V_161 ) ;
struct V_5 * V_34 = F_2 ( V_296 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_1 * V_7 = V_35 -> V_7 ;
struct V_2 * V_138 ;
int V_32 ;
char V_297 [ 32 ] ;
V_32 = F_162 ( V_200 ) ;
if ( V_32 ) {
F_163 ( V_200 -> V_298 , V_297 , sizeof( V_297 ) ) ;
F_65 (KERN_ERR PFX L_38
L_39 ,
buf) ;
return V_32 ;
}
if ( ! F_41 ( V_299 , & V_35 -> V_37 -> V_85 ) ) {
F_65 (KERN_ERR PFX L_40
L_41 ) ;
return - V_300 ;
}
F_164 () ;
F_20 ( & V_240 ) ;
V_138 = F_165 ( V_35 , & V_200 -> V_99 , 1 ) ;
F_23 ( & V_240 ) ;
F_166 () ;
if ( ! V_138 ) {
F_65 (KERN_ERR PFX L_42 ,
netdev->name) ;
return - V_300 ;
}
if ( V_301 )
F_167 ( V_138 -> V_192 ) = V_301 ;
if ( V_295 ) {
F_168 ( V_200 , V_302 ) ;
} else {
V_138 -> V_303 = V_304 ;
F_169 ( V_138 ) ;
F_170 ( V_138 ) ;
F_171 ( V_138 ) ;
}
return 0 ;
}
static void F_172 ( struct V_36 * V_37 , struct V_2 * V_3 )
{
struct V_305 * V_306 , * V_155 ;
F_8 ( & V_37 -> V_43 ) ;
F_97 (blport, tmp, &hba->vports, list) {
if ( V_306 -> V_3 == V_3 ) {
F_173 ( & V_306 -> V_22 ) ;
F_100 ( V_306 ) ;
}
}
F_12 ( & V_37 -> V_43 ) ;
}
static int F_174 ( struct V_294 * V_200 )
{
struct V_160 * V_161 = F_161 ( V_200 ) ;
struct V_2 * V_296 = F_102 ( V_161 ) ;
struct V_2 * V_138 = V_200 -> V_307 ;
struct V_5 * V_34 = F_2 ( V_138 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
struct V_2 * V_308 ;
bool V_309 = false ;
F_20 ( & V_296 -> V_247 ) ;
F_131 (v_port, &n_port->vports, list)
if ( V_308 -> V_200 == V_200 ) {
V_309 = true ;
break;
}
if ( ! V_309 ) {
F_23 ( & V_296 -> V_247 ) ;
return - V_310 ;
}
F_173 ( & V_138 -> V_22 ) ;
F_23 ( & V_296 -> V_247 ) ;
F_172 ( V_35 -> V_37 , V_34 -> V_3 ) ;
F_175 ( V_34 -> V_3 ) ;
F_176 ( V_35 ) ;
F_177 ( V_242 , & V_34 -> V_311 ) ;
return 0 ;
}
static int F_178 ( struct V_294 * V_200 , bool V_312 )
{
struct V_2 * V_3 = V_200 -> V_307 ;
if ( V_312 ) {
F_168 ( V_200 , V_302 ) ;
F_179 ( V_3 ) ;
} else {
V_3 -> V_303 = V_304 ;
F_170 ( V_3 ) ;
F_171 ( V_3 ) ;
}
return 0 ;
}
static int F_180 ( struct V_4 * V_35 )
{
struct V_1 * V_7 = V_35 -> V_7 ;
struct V_1 * V_313 = V_35 -> V_37 -> V_209 ;
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_314 * V_315 ;
int V_316 = 0 ;
F_181 () ;
F_182 (physdev, ha) {
F_19 ( L_43 ,
V_315 -> type ) ;
F_65 ( V_317 L_44 , V_315 -> V_283 [ 0 ] ,
V_315 -> V_283 [ 1 ] , V_315 -> V_283 [ 2 ] , V_315 -> V_283 [ 3 ] ,
V_315 -> V_283 [ 4 ] , V_315 -> V_283 [ 5 ] ) ;
if ( ( V_315 -> type == V_318 ) &&
( F_183 ( V_315 -> V_283 ) ) ) {
memcpy ( V_13 -> V_108 , V_315 -> V_283 ,
V_104 ) ;
V_316 = 1 ;
F_19 ( L_45 ) ;
}
}
F_184 () ;
if ( ! V_316 )
return - V_64 ;
V_35 -> V_282 . V_319 = F_152 ;
V_35 -> V_282 . type = F_53 ( V_320 ) ;
V_35 -> V_282 . V_99 = V_7 ;
F_185 ( & V_35 -> V_282 ) ;
V_35 -> V_125 . V_319 = F_63 ;
V_35 -> V_125 . type = F_186 ( V_98 ) ;
V_35 -> V_125 . V_99 = V_7 ;
F_185 ( & V_35 -> V_125 ) ;
return 0 ;
}
static int F_187 ( void )
{
V_203 =
F_188 ( & V_321 ) ;
if ( V_203 == NULL ) {
F_65 (KERN_ERR PFX L_46 ) ;
return - V_64 ;
}
V_202 =
F_188 ( & V_322 ) ;
if ( V_202 == NULL ) {
F_65 (KERN_ERR PFX
L_47 ) ;
F_189 ( V_203 ) ;
V_203 = NULL ;
return - V_64 ;
}
return 0 ;
}
static void F_190 ( void )
{
F_189 ( V_203 ) ;
F_189 ( V_202 ) ;
V_203 = NULL ;
V_202 = NULL ;
}
static void F_191 ( struct V_323 * V_323 )
{
struct V_10 * V_11 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
struct V_1 * V_7 ;
V_35 = F_64 ( V_323 , struct V_4 , V_323 ) ;
F_19 ( L_48 ) ;
V_13 = F_32 ( V_35 ) ;
V_11 = F_132 ( V_13 ) ;
V_7 = V_35 -> V_7 ;
if ( F_192 ( V_324 , & V_35 -> V_325 ) )
F_193 ( V_13 ) ;
F_194 ( V_11 ) ;
F_195 ( V_7 ) ;
F_196 ( V_326 ) ;
}
static inline void F_197 ( struct V_4 * V_35 )
{
F_198 ( & V_35 -> V_323 ) ;
}
static inline void F_176 ( struct V_4 * V_35 )
{
F_199 ( & V_35 -> V_323 , F_191 ) ;
}
static void F_200 ( struct V_36 * V_37 )
{
if ( V_37 -> V_327 ) {
F_201 ( V_37 -> V_327 ) ;
V_37 -> V_327 = NULL ;
}
F_100 ( V_37 -> V_45 ) ;
F_202 ( V_37 ) ;
F_100 ( V_37 ) ;
}
static struct V_36 * F_203 ( struct V_328 * V_329 )
{
struct V_36 * V_37 ;
struct V_330 * V_331 ;
int V_32 ;
V_37 = F_204 ( sizeof( * V_37 ) , V_332 ) ;
if ( ! V_37 ) {
F_65 (KERN_ERR PFX L_49 ) ;
return NULL ;
}
F_205 ( & V_37 -> V_43 ) ;
F_206 ( & V_37 -> V_42 ) ;
F_206 ( & V_37 -> V_166 ) ;
V_37 -> V_329 = V_329 ;
V_37 -> V_333 = V_329 -> V_334 ;
V_37 -> V_335 = ( V_37 -> V_333 / 2 ) ;
V_37 -> V_336 = V_37 -> V_335 ;
V_37 -> V_259 = ( V_37 -> V_333 - 1 ) ;
V_32 = F_207 ( V_37 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_50 ) ;
goto V_337;
}
V_37 -> V_209 = V_329 -> V_7 ;
V_37 -> V_338 = 0 ;
V_37 -> V_45 =
F_204 ( sizeof( struct V_38 * ) * V_44 ,
V_332 ) ;
if ( ! V_37 -> V_45 ) {
F_65 (KERN_ERR PFX L_51 ) ;
goto V_339;
}
V_37 -> V_252 = 0 ;
V_37 -> V_327 = F_208 ( V_37 ) ;
if ( ! V_37 -> V_327 ) {
F_65 (KERN_ERR PFX L_52 ) ;
goto V_340;
}
V_331 = & V_37 -> V_331 ;
V_331 -> V_341 = V_342 <<
V_343 ;
V_331 -> V_341 |= V_44 <<
V_344 ;
V_331 -> V_345 = V_37 -> V_336 <<
V_346 ;
V_331 -> V_345 |= V_347 <<
V_348 ;
V_331 -> V_349 = V_44 <<
V_350 ;
V_331 -> V_349 |= V_37 -> V_336 <<
V_351 ;
V_331 -> V_352 = V_353 ;
F_138 ( & V_37 -> V_251 ) ;
F_138 ( & V_37 -> V_226 ) ;
F_209 ( & V_37 -> V_354 ) ;
return V_37 ;
V_340:
F_100 ( V_37 -> V_45 ) ;
V_339:
F_202 ( V_37 ) ;
V_337:
F_100 ( V_37 ) ;
return NULL ;
}
static struct V_4 *
F_210 ( struct V_36 * V_37 ,
struct V_1 * V_7 ,
enum V_355 V_356 )
{
struct V_10 * V_11 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
int V_357 ;
int V_32 = 0 ;
V_357 = ( sizeof( * V_35 ) + sizeof( struct V_12 ) ) ;
V_11 = F_211 ( & V_7 -> V_99 , & V_358 ,
V_357 ) ;
if ( ! V_11 ) {
F_65 (KERN_ERR PFX L_53 ) ;
return NULL ;
}
V_13 = F_5 ( V_11 ) ;
V_13 -> V_229 = V_11 ;
V_35 = F_6 ( V_13 ) ;
F_212 ( V_7 ) ;
F_213 ( & V_35 -> V_323 ) ;
V_35 -> V_37 = V_37 ;
V_35 -> V_7 = V_7 ;
F_214 ( V_13 , V_356 ) ;
V_13 -> V_359 = F_156 ;
V_13 -> V_360 = F_154 ;
V_13 -> V_361 = F_155 ;
F_115 ( V_324 , & V_35 -> V_325 ) ;
V_32 = F_180 ( V_35 ) ;
if ( ! V_32 )
return V_35 ;
F_193 ( V_13 ) ;
F_195 ( V_7 ) ;
F_194 ( V_11 ) ;
return NULL ;
}
static struct V_2 * F_165 ( struct V_4 * V_35 ,
struct V_191 * V_362 , int V_363 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 , * V_296 ;
struct V_5 * V_34 ;
struct V_160 * V_161 ;
struct V_294 * V_200 = F_215 ( V_362 ) ;
struct V_305 * V_306 ;
struct V_36 * V_37 = V_35 -> V_37 ;
int V_32 = 0 ;
V_306 = F_204 ( sizeof( struct V_305 ) , V_332 ) ;
if ( ! V_306 ) {
F_34 ( V_13 -> V_16 , L_54 ) ;
return NULL ;
}
V_364 . V_365 = V_37 -> V_336 ;
if ( ! V_363 )
V_3 = F_216 ( & V_364 , sizeof( * V_34 ) ) ;
else
V_3 = F_217 ( V_200 , sizeof( * V_34 ) ) ;
if ( ! V_3 ) {
F_65 (KERN_ERR PFX L_55 ) ;
goto V_366;
}
V_161 = V_3 -> V_192 ;
V_34 = F_2 ( V_3 ) ;
V_34 -> V_3 = V_3 ;
V_34 -> V_6 = V_35 ;
V_34 -> V_367 = F_1 ;
F_218 ( & V_34 -> V_311 , V_368 ) ;
V_32 = F_149 ( V_3 ) ;
if ( V_32 )
goto V_369;
if ( V_363 ) {
F_65 (KERN_ERR PFX L_56 ,
vport->node_name, vport->port_name) ;
F_124 ( V_3 , V_200 -> V_370 ) ;
F_125 ( V_3 , V_200 -> V_298 ) ;
}
V_32 = F_117 ( V_3 , V_35 -> V_7 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_57 ) ;
goto V_369;
}
V_32 = F_108 ( V_3 , V_362 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_58 ,
interface->netdev->name) ;
goto V_369;
}
V_32 = F_142 ( V_3 ) ;
if ( V_32 ) {
F_65 (KERN_ERR PFX L_59 ) ;
goto V_371;
}
F_136 ( V_3 -> V_192 ) = V_248 ;
if ( V_301 )
F_167 ( V_161 ) = V_301 ;
if ( ! V_363 )
V_32 = F_147 ( V_3 , V_37 ) ;
else {
V_161 = F_161 ( V_200 ) ;
V_296 = F_102 ( V_161 ) ;
V_32 = F_219 ( V_296 , V_3 ) ;
}
if ( V_32 ) {
F_65 (KERN_ERR PFX L_60 ) ;
goto V_371;
}
F_197 ( V_35 ) ;
F_8 ( & V_37 -> V_43 ) ;
V_306 -> V_3 = V_3 ;
F_220 ( & V_306 -> V_22 , & V_37 -> V_354 ) ;
F_12 ( & V_37 -> V_43 ) ;
return V_3 ;
V_371:
F_221 ( V_161 ) ;
V_369:
F_222 ( V_3 -> V_192 ) ;
V_366:
F_100 ( V_306 ) ;
return NULL ;
}
static void F_223 ( struct V_4 * V_35 )
{
F_224 ( & V_35 -> V_125 ) ;
F_224 ( & V_35 -> V_282 ) ;
F_225 () ;
}
static void F_226 ( struct V_4 * V_35 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 = V_13 -> V_16 ;
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_36 * V_37 = V_35 -> V_37 ;
F_227 ( & V_34 -> V_221 ) ;
F_137 ( V_3 ) ;
F_223 ( V_35 ) ;
F_172 ( V_37 , V_3 ) ;
}
static void F_228 ( struct V_2 * V_3 )
{
F_7 ( V_3 ) ;
F_229 ( V_3 -> V_192 ) ;
F_221 ( V_3 -> V_192 ) ;
F_230 ( V_3 ) ;
F_231 ( V_3 ) ;
F_222 ( V_3 -> V_192 ) ;
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
F_177 ( V_242 , & V_34 -> V_311 ) ;
}
static int F_233 ( struct V_1 * V_7 )
{
struct V_4 * V_35 = NULL ;
struct V_372 * V_373 ;
struct V_12 * V_13 ;
int V_32 = 0 ;
F_164 () ;
F_20 ( & V_240 ) ;
V_35 = F_234 ( V_7 ) ;
V_13 = F_32 ( V_35 ) ;
if ( ! V_35 || ! V_13 -> V_16 ) {
V_32 = - V_64 ;
F_65 (KERN_ERR PFX L_61 ) ;
goto V_374;
}
V_373 = V_35 -> V_373 ;
F_129 ( V_35 ) ;
F_235 ( V_373 ) ;
V_374:
F_23 ( & V_240 ) ;
F_166 () ;
return V_32 ;
}
static void V_368 ( struct V_375 * V_154 )
{
struct V_5 * V_34 ;
struct V_2 * V_3 ;
V_34 = F_64 ( V_154 , struct V_5 , V_311 ) ;
V_3 = V_34 -> V_3 ;
F_34 ( V_3 , L_62 ) ;
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
goto V_376;
if ( F_241 ( V_37 ) )
goto V_376;
return 0 ;
V_376:
F_236 ( V_37 ) ;
return - V_65 ;
}
static int F_207 ( struct V_36 * V_37 )
{
struct V_328 * V_329 ;
struct V_377 * V_378 ;
if ( ! V_37 -> V_329 ) {
F_65 (KERN_ERR PFX L_63 ) ;
return - V_64 ;
}
V_329 = V_37 -> V_329 ;
V_378 = V_37 -> V_379 = V_329 -> V_379 ;
if ( ! V_37 -> V_379 )
return - V_64 ;
switch ( V_378 -> V_191 ) {
case V_380 :
strncpy ( V_37 -> V_206 , L_64 , V_381 ) ;
break;
case V_382 :
strncpy ( V_37 -> V_206 , L_65 , V_381 ) ;
break;
case V_383 :
case V_384 :
case V_385 :
strncpy ( V_37 -> V_206 , L_66 , V_381 ) ;
break;
case V_386 :
case V_387 :
case V_388 :
strncpy ( V_37 -> V_206 , L_67 , V_381 ) ;
break;
case V_389 :
case V_390 :
case V_391 :
strncpy ( V_37 -> V_206 , L_68 , V_381 ) ;
break;
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
strncpy ( V_37 -> V_206 , L_69 , V_381 ) ;
break;
default:
F_242 ( V_397 L_70 , V_378 -> V_191 ) ;
break;
}
F_243 ( V_37 -> V_379 ) ;
return 0 ;
}
static void F_202 ( struct V_36 * V_37 )
{
if ( V_37 -> V_379 ) {
V_37 -> V_206 [ 0 ] = '\0' ;
F_244 ( V_37 -> V_379 ) ;
}
V_37 -> V_379 = NULL ;
}
static int F_245 ( void * V_398 )
{
struct V_36 * V_37 = V_398 ;
struct V_328 * V_329 ;
struct V_399 * V_400 ;
if ( ! V_37 )
return - V_82 ;
V_329 = V_37 -> V_329 ;
V_400 = & V_329 -> V_400 -> V_401 ;
if ( ! V_400 )
return - V_82 ;
strncpy ( V_400 -> V_402 , V_207 ,
sizeof( V_400 -> V_402 ) ) ;
V_400 -> V_403 = V_404 ;
V_400 -> V_405 = V_406 ;
return 0 ;
}
static void F_246 ( void * V_398 )
{
struct V_36 * V_37 = V_398 ;
struct V_4 * V_35 ;
struct V_12 * V_13 ;
struct V_2 * V_3 ;
F_20 ( & V_240 ) ;
if ( ! F_41 ( V_299 , & V_37 -> V_85 ) )
F_247 ( V_37 ) ;
F_19 ( L_71 ) ;
F_131 (interface, &if_list, list) {
if ( V_35 -> V_37 == V_37 ) {
V_13 = F_32 ( V_35 ) ;
V_3 = V_13 -> V_16 ;
F_65 (KERN_ERR PFX L_72 ) ;
V_3 -> V_254 . V_407 = F_31 ;
F_248 ( V_35 ) ;
}
}
F_23 ( & V_240 ) ;
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
struct V_2 * V_200 ;
if ( ! F_41 ( V_299 , & V_35 -> V_37 -> V_85 ) )
return;
V_3 = V_13 -> V_16 ;
F_175 ( V_3 ) ;
F_20 ( & V_3 -> V_247 ) ;
F_131 (vport, &lport->vports, list)
F_136 ( V_200 -> V_192 ) =
V_248 ;
F_23 ( & V_3 -> V_247 ) ;
F_136 ( V_3 -> V_192 ) = V_248 ;
F_135 ( V_13 ) ;
F_137 ( V_3 ) ;
}
static int F_247 ( struct V_36 * V_37 )
{
#define F_250 (1000 / HZ)
int V_32 = - 1 ;
int V_40 = V_169 ;
V_32 = F_239 ( V_37 ) ;
if ( V_32 ) {
F_65 (KERN_ALERT PFX
L_73 , rc) ;
goto V_408;
}
V_32 = F_251 ( V_37 ) ;
if ( V_32 ) {
F_65 (KERN_ALERT PFX
L_74 , rc) ;
goto V_409;
}
while ( ! F_41 ( V_234 , & V_37 -> V_212 ) && V_40 -- )
F_252 ( F_250 ) ;
if ( ! F_41 ( V_234 , & V_37 -> V_212 ) ) {
F_65 (KERN_ERR PFX L_75
L_76 ,
hba->cnic->netdev->name) ;
V_32 = - 1 ;
goto V_409;
}
F_115 ( V_299 , & V_37 -> V_85 ) ;
return 0 ;
V_409:
F_236 ( V_37 ) ;
V_408:
return V_32 ;
}
static void F_253 ( struct V_36 * V_37 )
{
if ( F_192 ( V_299 , & V_37 -> V_85 ) ) {
if ( F_254 ( V_37 ) == 0 ) {
F_255 ( & V_37 -> V_410 ) ;
V_37 -> V_410 . V_411 = V_412 +
V_304 ;
V_37 -> V_410 . V_413 = F_126 ;
V_37 -> V_410 . V_149 = ( unsigned long ) V_37 ;
F_256 ( & V_37 -> V_410 ) ;
F_139 ( V_37 -> V_226 ,
F_41 ( V_225 ,
& V_37 -> V_85 ) ) ;
F_114 ( V_225 , & V_37 -> V_85 ) ;
if ( F_140 ( V_132 ) )
F_141 ( V_132 ) ;
F_227 ( & V_37 -> V_410 ) ;
}
F_236 ( V_37 ) ;
}
}
static void F_257 ( void * V_398 )
{
struct V_36 * V_37 = V_398 ;
struct V_4 * V_35 ;
F_65 ( V_235 L_77 ) ;
F_20 ( & V_240 ) ;
if ( ! F_41 ( V_299 , & V_37 -> V_85 ) )
goto exit;
F_131 (interface, &if_list, list) {
if ( V_35 -> V_37 == V_37 )
F_232 ( V_35 ) ;
}
F_258 ( V_37 -> V_252 != 0 ) ;
F_20 ( & V_37 -> V_42 ) ;
F_114 ( V_234 , & V_37 -> V_212 ) ;
F_114 ( V_237 ,
& V_37 -> V_212 ) ;
F_114 ( V_250 , & V_37 -> V_212 ) ;
F_23 ( & V_37 -> V_42 ) ;
F_253 ( V_37 ) ;
exit:
F_23 ( & V_240 ) ;
}
static void F_248 ( struct V_4 * V_35 )
{
struct V_12 * V_13 = F_32 ( V_35 ) ;
struct V_2 * V_3 ;
int V_414 = 0 ;
F_19 ( L_1 , V_41 ) ;
if ( ! F_41 ( V_299 , & V_35 -> V_37 -> V_85 ) ) {
F_65 (KERN_ERR PFX L_78 ) ;
return;
}
V_3 = V_13 -> V_16 ;
F_34 ( V_3 , L_79 ) ;
if ( ! F_112 ( V_3 ) && V_35 -> V_243 ) {
F_34 ( V_3 , L_80 ) ;
F_134 ( V_13 ) ;
F_136 ( V_3 -> V_192 ) = V_415 ;
F_115 ( V_250 , & V_35 -> V_37 -> V_212 ) ;
}
while ( ! V_13 -> V_81 ) {
F_252 ( 250 ) ;
if ( ++ V_414 > 12 )
break;
}
if ( F_118 ( V_3 , V_219 ) )
return;
F_169 ( V_3 ) ;
F_170 ( V_3 ) ;
}
static void F_259 ( struct V_328 * V_99 )
{
struct V_36 * V_37 ;
int V_32 = 0 ;
F_19 ( L_1 , V_41 ) ;
if ( ! F_41 ( V_416 , & V_99 -> V_85 ) ||
( V_99 -> V_417 == 0 ) ) {
F_65 (KERN_ERR PFX L_81
L_82 ,
dev->netdev->name, dev->flags, dev->max_fcoe_conn) ;
return;
}
V_37 = F_203 ( V_99 ) ;
if ( ! V_37 ) {
F_65 (KERN_ERR PFX L_83 ) ;
return;
}
F_133 ( V_397 L_84 , V_99 -> V_7 -> V_208 ) ;
F_20 ( & V_240 ) ;
F_220 ( & V_37 -> V_22 , & V_418 ) ;
V_419 ++ ;
F_23 ( & V_240 ) ;
V_99 -> V_331 = & V_37 -> V_331 ;
F_114 ( V_420 , & V_37 -> V_421 ) ;
V_32 = V_99 -> V_422 ( V_99 , V_423 ,
( void * ) V_37 ) ;
if ( V_32 )
F_65 (KERN_ERR PFX L_85 , rc) ;
else
F_115 ( V_420 , & V_37 -> V_421 ) ;
}
static int F_260 ( struct V_12 * V_13 )
{
struct V_4 * V_35 = F_6 ( V_13 ) ;
if ( V_35 -> V_243 == true ) {
if ( ! V_13 -> V_16 ) {
F_242 ( V_397 L_86 ) ;
return - V_64 ;
} else {
V_35 -> V_243 = false ;
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
F_20 ( & V_240 ) ;
V_35 = F_234 ( V_7 ) ;
V_13 = F_32 ( V_35 ) ;
if ( ! V_35 ) {
V_32 = - V_64 ;
F_242 ( V_397 L_87 ) ;
} else {
V_32 = F_260 ( V_13 ) ;
}
F_23 ( & V_240 ) ;
F_166 () ;
return V_32 ;
}
static T_6 F_262 ( struct V_2 * V_3 ,
struct V_424 * V_425 )
{
struct V_426 V_427 ;
T_6 V_40 , V_428 = 0 ;
T_4 V_214 = 0 ;
char V_429 [ 32 ] ;
char V_430 [ 32 ] ;
if ( V_425 -> V_431 > V_432 ) {
F_34 ( V_3 , L_88 ) ;
goto V_433;
}
if ( F_263 ( V_425 -> V_214 [ 0 ] ) == 0 &&
F_263 ( V_425 -> V_215 [ 0 ] ) == 0 ) {
F_34 ( V_3 , L_89 ) ;
goto V_433;
}
V_427 . V_434 = V_435 ;
V_427 . V_436 = V_437 ;
V_427 . V_312 = false ;
for ( V_40 = 0 ; V_40 < V_425 -> V_431 ; V_40 ++ ) {
V_214 = F_263 ( V_425 -> V_214 [ V_40 ] ) ;
if ( V_214 == 0 ) {
V_214 = V_3 -> V_214 ;
}
V_427 . V_370 = V_214 ;
V_427 . V_298 = F_263 ( V_425 -> V_215 [ V_40 ] ) ;
F_264 ( V_427 . V_438 , sizeof( V_427 . V_438 ) ,
L_90 ,
V_428 , V_427 . V_298 , V_427 . V_370 ) ;
F_163 ( V_427 . V_370 , V_430 , sizeof( V_430 ) ) ;
F_163 ( V_427 . V_298 , V_429 , sizeof( V_429 ) ) ;
F_34 ( V_3 , L_91 , V_430 ,
V_429 ) ;
if ( F_265 ( V_3 -> V_192 , 0 , & V_427 ) )
V_428 ++ ;
else
F_34 ( V_3 , L_92 ) ;
}
V_433:
return V_428 ;
}
static int F_266 ( struct V_12 * V_13 )
{
struct V_4 * V_35 = F_6 ( V_13 ) ;
struct V_36 * V_37 ;
struct V_424 * V_425 ;
struct V_2 * V_3 ;
if ( V_35 -> V_243 == false ) {
if ( ! V_13 -> V_16 ) {
F_242 ( V_397 L_93 ) ;
return - V_64 ;
} else if ( ! F_112 ( V_13 -> V_16 ) ) {
F_134 ( V_13 ) ;
V_35 -> V_243 = true ;
}
}
V_37 = V_35 -> V_37 ;
V_3 = V_13 -> V_16 ;
if ( ! V_37 )
goto V_433;
if ( ! V_37 -> V_329 )
goto V_433;
if ( ! V_3 )
goto V_433;
if ( ! V_3 -> V_192 )
goto V_433;
if ( ! V_37 -> V_329 -> V_439 )
goto V_433;
V_425 = F_204 ( sizeof( struct V_424 ) , V_332 ) ;
if ( ! V_425 )
goto V_433;
if ( V_37 -> V_329 -> V_439 ( V_37 -> V_329 , V_425 ) )
goto V_440;
F_262 ( V_3 , V_425 ) ;
V_440:
F_100 ( V_425 ) ;
V_433:
return 0 ;
}
static int F_267 ( struct V_1 * V_7 )
{
struct V_4 * V_35 ;
struct V_12 * V_13 ;
int V_32 = 0 ;
F_164 () ;
F_20 ( & V_240 ) ;
V_35 = F_234 ( V_7 ) ;
V_13 = F_32 ( V_35 ) ;
if ( ! V_35 ) {
V_32 = - V_64 ;
F_242 ( V_397 L_94 ) ;
} else {
V_32 = F_266 ( V_13 ) ;
}
F_23 ( & V_240 ) ;
F_166 () ;
return V_32 ;
}
static int F_268 ( struct V_10 * V_229 )
{
struct V_12 * V_13 = F_5 ( V_229 ) ;
switch ( V_229 -> V_243 ) {
case V_245 :
return F_266 ( V_13 ) ;
case V_244 :
return F_260 ( V_13 ) ;
case V_246 :
default:
return - V_441 ;
} ;
}
static int F_269 ( struct V_1 * V_7 ,
enum V_356 V_356 ,
enum V_442 V_443 )
{
struct V_10 * V_229 ;
struct V_12 * V_13 ;
struct V_4 * V_35 ;
struct V_36 * V_37 ;
struct V_1 * V_209 = V_7 ;
struct V_2 * V_3 ;
struct V_444 V_445 ;
int V_32 = 0 ;
int V_15 = 0 ;
F_19 ( L_95 ) ;
if ( V_356 != V_446 ) {
F_65 ( V_235 L_96 ) ;
return - V_300 ;
}
F_164 () ;
F_20 ( & V_240 ) ;
if ( ! F_270 ( V_326 ) ) {
V_32 = - V_82 ;
goto V_447;
}
if ( F_271 ( V_7 ) )
V_209 = F_272 ( V_7 ) ;
if ( V_209 -> V_216 && V_209 -> V_216 -> V_448 ) {
memset ( & V_445 , 0 , sizeof( V_445 ) ) ;
V_209 -> V_216 -> V_448 ( V_209 , & V_445 ) ;
if ( strncmp ( V_445 . V_449 , L_97 , strlen ( L_97 ) ) ) {
F_65 (KERN_ERR PFX L_98 ) ;
V_32 = - V_82 ;
goto V_374;
}
} else {
F_65 (KERN_ERR PFX L_99 ) ;
V_32 = - V_82 ;
goto V_374;
}
V_37 = F_273 ( V_209 ) ;
if ( ! V_37 ) {
V_32 = - V_64 ;
F_65 (KERN_ERR PFX L_100 ) ;
goto V_374;
}
if ( F_234 ( V_7 ) ) {
V_32 = - V_450 ;
goto V_374;
}
V_35 = F_210 ( V_37 , V_7 , V_356 ) ;
if ( ! V_35 ) {
F_65 (KERN_ERR PFX L_101 ) ;
V_32 = - V_65 ;
goto V_451;
}
if ( F_271 ( V_7 ) ) {
V_15 = F_274 ( V_7 ) ;
V_35 -> V_452 = 1 ;
}
V_13 = F_32 ( V_35 ) ;
V_229 = F_132 ( V_13 ) ;
V_35 -> V_15 = V_15 ;
V_35 -> V_453 = V_454 ;
V_35 -> V_373 =
F_275 ( L_102 ) ;
if ( ! V_35 -> V_373 ) {
F_65 (KERN_ERR PFX L_103 ) ;
V_32 = - V_82 ;
goto V_451;
}
V_3 = F_165 ( V_35 , & V_229 -> V_99 , 0 ) ;
if ( ! V_3 ) {
F_65 (KERN_ERR PFX L_104 ,
netdev->name) ;
V_32 = - V_82 ;
goto V_455;
}
F_220 ( & V_35 -> V_22 , & V_456 ) ;
V_3 -> V_303 = V_304 ;
V_13 -> V_16 = V_3 ;
if ( V_443 == V_457 )
V_229 -> V_243 = V_245 ;
else
V_229 -> V_243 = V_244 ;
if ( V_443 == V_457 &&
! F_112 ( V_3 ) ) {
F_134 ( V_13 ) ;
F_136 ( V_3 -> V_192 ) = V_415 ;
F_115 ( V_250 , & V_35 -> V_37 -> V_212 ) ;
}
F_34 ( V_3 , L_105 ) ;
F_248 ( V_35 ) ;
if ( V_443 == V_457 )
V_35 -> V_243 = true ;
F_176 ( V_35 ) ;
F_23 ( & V_240 ) ;
F_166 () ;
return 0 ;
V_455:
F_235 ( V_35 -> V_373 ) ;
V_451:
F_223 ( V_35 ) ;
F_176 ( V_35 ) ;
goto V_447;
V_374:
F_196 ( V_326 ) ;
V_447:
F_23 ( & V_240 ) ;
F_166 () ;
return V_32 ;
}
static int F_276 ( struct V_1 * V_7 , enum V_356 V_356 )
{
return F_269 ( V_7 , V_356 , V_457 ) ;
}
static int F_277 ( struct V_1 * V_7 )
{
return F_269 ( V_7 , V_446 ,
V_458 ) ;
}
static struct V_36 * F_278 ( struct V_328 * V_329 )
{
struct V_36 * V_37 ;
F_131 (hba, &adapter_list, list) {
if ( V_37 -> V_329 == V_329 )
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
* V_209 )
{
struct V_36 * V_37 ;
F_131 (hba, &adapter_list, list) {
if ( V_37 -> V_209 == V_209 )
return V_37 ;
}
F_65 (KERN_ERR PFX L_106 ) ;
return NULL ;
}
static void F_279 ( struct V_328 * V_99 )
{
struct V_36 * V_37 ;
struct V_4 * V_35 , * V_155 ;
F_19 ( L_107 ) ;
if ( ! F_41 ( V_416 , & V_99 -> V_85 ) ) {
F_65 (KERN_ERR PFX L_108 ,
dev->netdev->name, dev->flags) ;
return;
}
F_20 ( & V_240 ) ;
V_37 = F_278 ( V_99 ) ;
if ( ! V_37 ) {
F_65 (KERN_ERR PFX L_109 ,
dev) ;
F_23 ( & V_240 ) ;
return;
}
F_98 ( & V_37 -> V_22 ) ;
V_419 -- ;
F_97 (interface, tmp, &if_list, list)
if ( V_35 -> V_37 == V_37 )
F_129 ( V_35 ) ;
F_23 ( & V_240 ) ;
F_130 ( V_242 ) ;
F_257 ( V_37 ) ;
if ( F_192 ( V_420 , & V_37 -> V_421 ) )
V_37 -> V_329 -> V_459 ( V_37 -> V_329 , V_423 ) ;
F_200 ( V_37 ) ;
}
static void F_280 ( struct V_460 * V_461 )
{
}
static int F_281 ( struct V_160 * V_161 )
{
struct V_2 * V_3 = F_102 ( V_161 ) ;
F_282 ( V_3 ) ;
return 0 ;
}
static bool F_283 ( struct V_1 * V_7 )
{
struct V_1 * V_209 = V_7 ;
F_20 ( & V_240 ) ;
if ( F_271 ( V_7 ) )
V_209 = F_272 ( V_7 ) ;
if ( F_273 ( V_209 ) ) {
F_23 ( & V_240 ) ;
return true ;
}
F_23 ( & V_240 ) ;
return false ;
}
static int F_284 ( unsigned int V_462 )
{
struct V_151 * V_152 ;
struct V_463 * V_464 ;
V_152 = & F_285 ( V_465 , V_462 ) ;
V_464 = F_286 ( F_93 ,
( void * ) V_152 , F_287 ( V_462 ) ,
L_110 , V_462 ) ;
if ( F_288 ( V_464 ) )
return F_289 ( V_464 ) ;
F_290 ( V_464 , V_462 ) ;
V_152 -> V_466 = V_464 ;
F_71 ( V_464 ) ;
return 0 ;
}
static int F_291 ( unsigned int V_462 )
{
struct V_151 * V_152 ;
struct V_463 * V_464 ;
struct V_153 * V_154 , * V_155 ;
F_19 ( L_111 , V_462 ) ;
V_152 = & F_285 ( V_465 , V_462 ) ;
F_8 ( & V_152 -> V_157 ) ;
V_464 = V_152 -> V_466 ;
V_152 -> V_466 = NULL ;
F_97 (work, tmp, &p->work_list, list) {
F_98 ( & V_154 -> V_22 ) ;
F_99 ( V_154 -> V_39 , V_154 -> V_158 ) ;
F_100 ( V_154 ) ;
}
F_12 ( & V_152 -> V_157 ) ;
if ( V_464 )
F_292 ( V_464 ) ;
return 0 ;
}
static int F_293 ( struct V_467 * V_468 )
{
if ( ! V_469 )
return 0 ;
F_294 ( V_468 , V_469 ) ;
return 0 ;
}
static int T_7 F_295 ( void )
{
struct V_17 * V_18 ;
struct V_463 * V_470 ;
int V_32 = 0 ;
unsigned int V_462 = 0 ;
struct V_151 * V_152 ;
F_65 (KERN_INFO PFX L_112 , version) ;
V_32 = F_296 ( & V_471 ) ;
if ( V_32 ) {
F_65 ( V_235 L_113
L_114 ) ;
goto V_472;
}
F_209 ( & V_418 ) ;
F_209 ( & V_456 ) ;
F_206 ( & V_240 ) ;
V_419 = 0 ;
V_32 = F_187 () ;
if ( V_32 )
goto V_473;
V_242 = F_297 ( L_115 , 0 , 0 ) ;
if ( ! V_242 ) {
V_32 = - V_65 ;
goto V_474;
}
V_18 = & V_27 ;
F_119 ( & V_18 -> V_28 ) ;
V_470 = F_298 ( F_72 ,
( void * ) V_18 ,
L_116 ) ;
if ( F_288 ( V_470 ) ) {
V_32 = F_289 ( V_470 ) ;
goto V_475;
}
F_71 ( V_470 ) ;
F_8 ( & V_18 -> V_28 . V_29 ) ;
V_18 -> V_130 = V_470 ;
F_12 ( & V_18 -> V_28 . V_29 ) ;
F_299 (cpu) {
V_152 = & F_285 ( V_465 , V_462 ) ;
F_209 ( & V_152 -> V_156 ) ;
F_205 ( & V_152 -> V_157 ) ;
}
V_32 = F_300 ( V_476 , L_117 ,
F_284 , F_291 ) ;
if ( V_32 < 0 )
goto V_477;
V_478 = V_32 ;
F_301 ( V_423 , & V_479 ) ;
return 0 ;
V_477:
F_292 ( V_470 ) ;
V_475:
F_235 ( V_242 ) ;
V_474:
F_190 () ;
V_473:
F_302 ( & V_471 ) ;
V_472:
return V_32 ;
}
static void T_8 F_303 ( void )
{
F_94 ( V_480 ) ;
struct V_36 * V_37 , * V_25 ;
struct V_17 * V_18 ;
struct V_463 * V_470 ;
struct V_23 * V_24 ;
F_20 ( & V_240 ) ;
F_96 ( & V_418 , & V_480 ) ;
V_419 = 0 ;
F_23 ( & V_240 ) ;
F_97 (hba, next, &to_be_deleted, list) {
F_98 ( & V_37 -> V_22 ) ;
F_65 (KERN_ERR PFX L_118 ,
hba) ;
F_257 ( V_37 ) ;
if ( F_192 ( V_420 ,
& V_37 -> V_421 ) )
V_37 -> V_329 -> V_459 ( V_37 -> V_329 ,
V_423 ) ;
F_200 ( V_37 ) ;
}
F_304 ( V_423 ) ;
V_18 = & V_27 ;
F_8 ( & V_18 -> V_28 . V_29 ) ;
V_470 = V_18 -> V_130 ;
V_18 -> V_130 = NULL ;
while ( ( V_24 = F_77 ( & V_18 -> V_28 ) ) != NULL )
F_11 ( V_24 ) ;
F_12 ( & V_18 -> V_28 . V_29 ) ;
if ( V_470 )
F_292 ( V_470 ) ;
F_305 ( V_478 ) ;
F_235 ( V_242 ) ;
F_190 () ;
F_302 ( & V_471 ) ;
}
static T_9
F_306 ( struct V_191 * V_99 , struct V_481 * V_482 ,
char * V_297 )
{
struct V_160 * V_161 = F_307 ( V_99 ) ;
struct V_2 * V_3 = F_102 ( V_161 ) ;
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
sprintf ( V_297 , L_119 , V_35 -> V_453 ) ;
return strlen ( V_297 ) ;
}
static T_9
F_308 ( struct V_191 * V_99 ,
struct V_481 * V_482 , const char * V_297 , T_10 V_431 )
{
struct V_160 * V_161 = F_307 ( V_99 ) ;
struct V_2 * V_3 = F_102 ( V_161 ) ;
struct V_5 * V_34 = F_2 ( V_3 ) ;
struct V_4 * V_35 = V_34 -> V_6 ;
int V_483 , V_484 ;
V_483 = F_309 ( V_297 , 10 , & V_484 ) ;
if ( V_483 )
return V_483 ;
if ( V_484 > 255 )
return - V_485 ;
V_35 -> V_453 = ( T_1 ) V_484 ;
return strlen ( V_297 ) ;
}
