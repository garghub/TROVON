static void F_1 ( T_1 V_1 )
{
F_2 ( L_1 ) ;
if ( V_1 & V_2 )
F_2 ( L_2 ) ;
if ( V_1 & V_3 )
F_2 ( L_3 ) ;
if ( V_1 & V_4 )
F_2 ( L_4 ) ;
if ( V_1 & V_5 )
F_2 ( L_5 ) ;
if ( V_1 & V_6 )
F_2 ( L_6 ) ;
if ( V_1 & V_7 )
F_2 ( L_7 ) ;
if ( V_1 & V_8 )
F_2 ( L_8 ) ;
if ( V_1 & V_9 )
F_2 ( L_9 ) ;
if ( V_1 & V_10 )
F_2 ( L_10 ) ;
if ( V_1 & V_11 )
F_2 ( L_11 ) ;
if ( V_1 & V_12 )
F_2 ( L_12 ) ;
if ( V_1 & V_13 )
F_2 ( L_13 ) ;
if ( V_1 & V_14 )
F_2 ( L_14 ) ;
if ( V_1 & V_15 )
F_2 ( L_15 ) ;
if ( V_1 & V_16 )
F_2 ( L_16 ) ;
if ( V_1 & V_17 )
F_2 ( L_17 ) ;
if ( V_1 & V_18 )
F_2 ( L_18 ) ;
if ( V_1 & V_19 )
F_2 ( L_19 ) ;
if ( V_1 & V_20 )
F_2 ( L_20 ) ;
if ( V_1 & V_21 )
F_2 ( L_21 ) ;
}
static int F_3 ( struct V_22 * V_23 )
{
int V_24 ;
struct V_25 * V_26 ;
struct V_27 V_28 ;
volatile T_2 * V_29 ;
bool V_30 ;
V_26 = F_4 ( sizeof( * V_26 ) , V_31 ) ;
if ( ! V_26 )
return - V_32 ;
V_24 = F_5 ( V_23 , V_26 , V_33 ,
& V_34 , false ,
& V_35 ) ;
if ( F_6 ( V_24 != 0 ) )
return V_24 ;
V_24 = F_7 ( & V_26 -> V_36 , false , true , NULL ) ;
F_8 ( V_24 != 0 ) ;
F_9 ( V_26 , true ) ;
V_24 = F_10 ( & V_26 -> V_36 , 0 , 1 , & V_28 ) ;
if ( F_11 ( V_24 == 0 ) ) {
V_29 = F_12 ( & V_28 , & V_30 ) ;
V_29 -> V_37 = sizeof( * V_29 ) ;
V_29 -> V_38 = V_39 ;
V_29 -> V_40 = 0xff ;
F_13 ( & V_28 ) ;
}
F_9 ( V_26 , false ) ;
F_14 ( & V_26 -> V_36 ) ;
if ( F_6 ( V_24 != 0 ) ) {
F_15 ( L_22 ) ;
F_16 ( & V_26 ) ;
} else
V_23 -> V_41 = V_26 ;
return V_24 ;
}
static int F_17 ( struct V_22 * V_23 )
{
int V_24 ;
if ( V_23 -> V_42 ) {
V_24 = F_18 ( V_23 ) ;
if ( F_6 ( V_24 != 0 ) ) {
F_15 ( L_23
L_24 ) ;
return V_24 ;
}
}
if ( V_23 -> V_43 ) {
V_24 = F_19 ( V_23 -> V_43 ,
256 * 4096 , 2 * 4096 ) ;
if ( V_24 ) {
struct V_44 * V_45 = V_23 -> V_43 ;
V_23 -> V_43 = NULL ;
F_20 ( V_45 ) ;
}
}
return 0 ;
}
static int F_21 ( struct V_22 * V_23 )
{
int V_24 ;
V_24 = F_22 ( V_23 , & V_23 -> V_46 ) ;
if ( F_6 ( V_24 != 0 ) ) {
F_15 ( L_25 ) ;
return V_24 ;
}
F_23 ( V_23 -> V_47 ) ;
V_23 -> V_43 = F_24 ( V_23 ) ;
if ( F_25 ( V_23 -> V_43 ) ) {
V_23 -> V_43 = NULL ;
V_23 -> V_48 = false ;
}
V_24 = F_17 ( V_23 ) ;
if ( V_24 )
goto V_49;
V_24 = F_3 ( V_23 ) ;
if ( F_6 ( V_24 != 0 ) )
goto V_50;
return 0 ;
V_50:
if ( V_23 -> V_43 )
F_26 ( V_23 -> V_43 ) ;
if ( V_23 -> V_42 ) {
( void ) F_27 ( & V_23 -> V_51 , V_52 ) ;
F_28 ( V_23 ) ;
}
if ( V_23 -> V_43 )
F_20 ( V_23 -> V_43 ) ;
V_49:
F_29 ( V_23 -> V_47 ) ;
F_30 ( V_23 , & V_23 -> V_46 ) ;
return V_24 ;
}
static void F_31 ( struct V_22 * V_23 )
{
F_8 ( V_23 -> V_53 != NULL ) ;
F_16 ( & V_23 -> V_41 ) ;
if ( V_23 -> V_43 )
F_26 ( V_23 -> V_43 ) ;
if ( V_23 -> V_42 ) {
F_27 ( & V_23 -> V_51 , V_52 ) ;
F_28 ( V_23 ) ;
}
}
static void F_32 ( struct V_22 * V_23 )
{
F_29 ( V_23 -> V_47 ) ;
if ( V_23 -> V_43 )
F_20 ( V_23 -> V_43 ) ;
F_30 ( V_23 , & V_23 -> V_46 ) ;
}
static void F_33 ( struct V_22 * V_23 )
{
T_1 V_54 ;
T_1 V_55 ;
V_54 = F_34 ( V_23 , V_56 ) ;
V_55 = F_34 ( V_23 , V_57 ) ;
V_54 = F_35 ( T_1 , V_54 , V_58 ) ;
V_55 = F_35 ( T_1 , V_55 , V_59 ) ;
if ( V_54 > V_23 -> V_60 ||
V_55 > V_23 -> V_61 ) {
V_54 = V_58 ;
V_55 = V_59 ;
}
V_23 -> V_62 = V_54 ;
V_23 -> V_63 = V_55 ;
}
static int F_36 ( struct V_22 * V_23 )
{
static const char * V_64 [ V_65 ] = {
[ V_66 ] = L_26 ,
[ V_67 ] = L_27 ,
[ V_68 ] = L_28 ,
[ V_69 ] = L_29 } ;
#ifdef F_37
const struct V_70 * V_71 = F_38 ( V_23 -> V_72 -> V_72 ) ;
#ifdef F_39
if ( V_73 ) {
V_23 -> V_74 = V_68 ;
goto V_75;
}
#endif
if ( ! ( V_76 || V_77 ) ) {
V_23 -> V_74 = V_66 ;
F_2 ( L_30 , V_64 [ V_23 -> V_74 ] ) ;
return 0 ;
}
V_23 -> V_74 = V_68 ;
if ( V_71 -> V_78 )
V_23 -> V_74 = V_67 ;
#ifdef F_40
if ( F_41 () == 0 )
V_23 -> V_74 = V_68 ;
#endif
#ifdef F_39
V_75:
#endif
if ( V_23 -> V_74 == V_68 &&
V_79 )
V_23 -> V_74 = V_69 ;
if ( V_77 )
V_23 -> V_74 = V_67 ;
#if ! F_42 ( F_40 ) && ! F_42 ( F_39 )
if ( V_23 -> V_74 == V_67 )
return - V_80 ;
#endif
#else
V_23 -> V_74 = V_68 ;
#endif
F_2 ( L_30 , V_64 [ V_23 -> V_74 ] ) ;
return 0 ;
}
static int F_43 ( struct V_22 * V_23 )
{
struct V_81 * V_72 = V_23 -> V_72 ;
if ( V_73 &&
(sizeof( unsigned long ) == 4 || V_82 ) ) {
F_2 ( L_31 ) ;
return F_44 ( V_72 -> V_72 , F_45 ( 44 ) ) ;
}
return 0 ;
}
static int F_43 ( struct V_22 * V_23 )
{
return 0 ;
}
static int F_46 ( struct V_81 * V_72 , unsigned long V_83 )
{
struct V_22 * V_23 ;
int V_24 ;
T_1 V_84 ;
enum V_85 V_86 ;
bool V_87 = false ;
char V_88 [ 100 ] = { 0 } ;
V_23 = F_4 ( sizeof( * V_23 ) , V_31 ) ;
if ( F_6 ( V_23 == NULL ) ) {
F_15 ( L_32 ) ;
return - V_32 ;
}
F_47 ( V_72 -> V_89 ) ;
V_23 -> V_72 = V_72 ;
V_23 -> V_90 = V_83 ;
V_23 -> V_91 = ( T_1 ) - 100 ;
F_48 ( & V_23 -> V_92 ) ;
F_48 ( & V_23 -> V_93 ) ;
F_48 ( & V_23 -> V_94 ) ;
F_48 ( & V_23 -> V_95 ) ;
F_49 ( & V_23 -> V_96 ) ;
F_50 ( & V_23 -> V_97 ) ;
F_51 ( & V_23 -> V_98 ) ;
F_51 ( & V_23 -> V_99 ) ;
F_51 ( & V_23 -> V_100 ) ;
F_51 ( & V_23 -> V_101 ) ;
for ( V_86 = V_102 ; V_86 < V_103 ; ++ V_86 ) {
F_52 ( & V_23 -> V_104 [ V_86 ] ) ;
F_53 ( & V_23 -> V_105 [ V_86 ] ) ;
}
F_48 ( & V_23 -> V_106 ) ;
F_54 ( & V_23 -> V_107 ) ;
F_54 ( & V_23 -> V_108 ) ;
V_23 -> V_109 = 0 ;
V_23 -> V_110 = 0 ;
V_23 -> V_111 = 0 ;
V_23 -> V_112 = F_55 ( V_72 -> V_89 , 0 ) ;
V_23 -> V_113 = F_55 ( V_72 -> V_89 , 1 ) ;
V_23 -> V_114 = F_55 ( V_72 -> V_89 , 2 ) ;
V_23 -> V_115 = ! ! V_116 ;
V_23 -> V_117 = V_118 ;
F_56 ( V_23 , V_119 , V_120 ) ;
V_84 = F_34 ( V_23 , V_119 ) ;
if ( V_84 != V_120 ) {
V_24 = - V_121 ;
F_15 ( L_33 , V_84 ) ;
goto V_122;
}
V_23 -> V_1 = F_34 ( V_23 , V_123 ) ;
V_24 = F_36 ( V_23 ) ;
if ( F_6 ( V_24 != 0 ) ) {
F_2 ( L_34 ) ;
V_87 = true ;
}
V_23 -> V_124 = F_34 ( V_23 , V_125 ) ;
V_23 -> V_126 = F_34 ( V_23 , V_127 ) ;
V_23 -> V_60 = F_34 ( V_23 , V_128 ) ;
V_23 -> V_61 = F_34 ( V_23 , V_129 ) ;
F_33 ( V_23 ) ;
if ( V_23 -> V_1 & V_16 ) {
V_23 -> V_130 =
F_34 ( V_23 , V_131 ) ;
V_23 -> V_132 =
F_34 ( V_23 , V_133 ) ;
V_23 -> V_134 =
F_34 ( V_23 , V_135 ) ;
V_23 -> V_134 -= V_23 -> V_124 ;
} else {
V_23 -> V_134 = 512 * 1024 * 1024 ;
}
V_23 -> V_136 = 0 ;
V_23 -> V_137 = 0 ;
if ( V_23 -> V_1 & V_20 ) {
T_3 V_138 =
F_34 ( V_23 ,
V_139 ) ;
if ( ! ( V_23 -> V_1 & V_8 ) )
V_138 *= 2 ;
V_23 -> V_136 = V_138 * 1024 / V_33 ;
V_23 -> V_140 =
F_34 ( V_23 ,
V_141 ) ;
V_23 -> V_137 =
F_34 ( V_23 , V_142 ) ;
V_23 -> V_143 =
F_34 ( V_23 , V_144 ) ;
V_23 -> V_145 =
F_34 ( V_23 , V_146 ) ;
F_56 ( V_23 , V_147 ,
V_148 ) ;
V_23 -> V_149 = F_34 ( V_23 ,
V_147 ) ;
F_56 ( V_23 , V_147 ,
V_150 ) ;
V_23 -> V_151 = F_34 ( V_23 ,
V_147 ) ;
} else {
V_23 -> V_149 = 8192 ;
V_23 -> V_151 = 8192 ;
V_23 -> V_140 = V_23 -> V_124 ;
}
F_1 ( V_23 -> V_1 ) ;
V_24 = F_43 ( V_23 ) ;
if ( F_6 ( V_24 != 0 ) )
goto V_122;
if ( V_23 -> V_1 & V_16 ) {
F_2 ( L_35 ,
( unsigned ) V_23 -> V_130 ) ;
F_2 ( L_36 ,
( unsigned ) V_23 -> V_132 ) ;
F_2 ( L_37 ,
( unsigned ) V_23 -> V_134 / 1024 ) ;
}
F_2 ( L_38 ,
V_23 -> V_140 / 1024 ) ;
F_2 ( L_39 ,
V_23 -> V_113 , V_23 -> V_124 / 1024 ) ;
F_2 ( L_40 ,
V_23 -> V_114 , V_23 -> V_126 / 1024 ) ;
V_24 = F_57 ( V_23 ) ;
if ( F_6 ( V_24 != 0 ) )
goto V_122;
F_58 ( & V_23 -> V_152 ) ;
F_59 ( & V_23 -> V_152 . V_153 , false , V_154 ) ;
V_23 -> V_155 = & V_23 -> V_152 ;
V_23 -> V_156 = F_60 ( V_23 -> V_114 ,
V_23 -> V_126 , V_157 ) ;
if ( F_6 ( V_23 -> V_156 == NULL ) ) {
V_24 = - V_32 ;
F_15 ( L_41 ) ;
goto V_158;
}
if ( ! ( V_23 -> V_1 & V_13 ) &&
! ( V_23 -> V_1 & V_11 ) &&
! F_61 ( V_23 ) ) {
V_24 = - V_121 ;
F_15 ( L_42 ) ;
goto V_159;
}
V_23 -> V_160 = F_62
( V_23 -> V_161 . V_162 , 12 , & V_163 ) ;
if ( F_6 ( V_23 -> V_160 == NULL ) ) {
F_15 ( L_43 ) ;
V_24 = - V_32 ;
goto V_159;
}
V_72 -> V_164 = V_23 ;
V_24 = F_63 ( V_72 -> V_89 , L_44 ) ;
V_23 -> V_165 = ( V_24 != 0 ) ;
if ( V_23 -> V_165 ) {
F_2 ( L_45
L_46 ) ;
V_24 = F_64 ( V_72 -> V_89 , 2 , L_47 ) ;
if ( F_6 ( V_24 != 0 ) ) {
F_15 ( L_48 ) ;
goto V_166;
}
}
if ( V_23 -> V_1 & V_12 ) {
V_24 = F_65 ( V_72 , V_72 -> V_89 -> V_167 ) ;
if ( V_24 != 0 ) {
F_15 ( L_49 , V_24 ) ;
goto V_168;
}
}
V_23 -> V_47 = F_66 ( V_23 ) ;
if ( F_6 ( V_23 -> V_47 == NULL ) ) {
V_24 = - V_32 ;
goto V_169;
}
V_24 = F_67 ( & V_23 -> V_51 ,
V_23 -> V_170 . V_171 . V_162 ,
& V_172 ,
V_72 -> V_173 -> V_174 ,
V_175 ,
false ) ;
if ( F_6 ( V_24 != 0 ) ) {
F_15 ( L_50 ) ;
goto V_176;
}
V_24 = F_68 ( & V_23 -> V_51 , V_177 ,
( V_23 -> V_124 >> V_178 ) ) ;
if ( F_6 ( V_24 != 0 ) ) {
F_15 ( L_51 ) ;
goto V_179;
}
V_23 -> V_51 . V_45 [ V_177 ] . V_180 = false ;
V_23 -> V_181 = true ;
if ( ( ( V_23 -> V_1 & ( V_14 | V_16 ) ) == 0 ) ||
V_87 || F_68 ( & V_23 -> V_51 , V_182 ,
V_182 ) != 0 ) {
F_2 ( L_52
L_53 ) ;
V_23 -> V_181 = false ;
}
if ( V_23 -> V_1 & V_20 ) {
V_23 -> V_42 = true ;
if ( F_68 ( & V_23 -> V_51 , V_52 ,
V_52 ) != 0 ) {
F_2 ( L_54
L_55 ) ;
V_23 -> V_42 = false ;
}
}
if ( V_23 -> V_42 ) {
F_69 ( & V_23 -> V_100 ) ;
F_56 ( V_23 , V_147 , V_183 ) ;
V_23 -> V_48 = ! ! F_34 ( V_23 , V_147 ) ;
F_70 ( & V_23 -> V_100 ) ;
}
V_24 = F_71 ( V_23 ) ;
if ( F_6 ( V_24 != 0 ) )
goto V_184;
F_72 ( V_23 ) ;
V_24 = F_21 ( V_23 ) ;
if ( V_24 )
goto V_185;
F_2 ( L_56 , V_23 -> V_48 ? L_57 : L_58 ) ;
snprintf ( V_88 , sizeof( V_88 ) , L_59 ,
V_186 , V_187 ) ;
F_73 ( V_88 ) ;
memset ( V_88 , 0 , sizeof( V_88 ) ) ;
snprintf ( V_88 , sizeof( V_88 ) , L_60 ,
V_188 , V_189 ,
V_190 ) ;
F_73 ( V_88 ) ;
if ( V_23 -> V_117 ) {
F_74 ( V_23 ) ;
F_75 ( V_23 ) ;
F_76 ( V_23 ) ;
}
V_23 -> V_191 . V_192 = V_193 ;
F_77 ( & V_23 -> V_191 ) ;
return 0 ;
V_185:
F_78 ( V_23 ) ;
F_79 ( V_23 ) ;
V_184:
if ( V_23 -> V_42 )
( void ) F_80 ( & V_23 -> V_51 , V_52 ) ;
if ( V_23 -> V_181 )
( void ) F_80 ( & V_23 -> V_51 , V_182 ) ;
( void ) F_80 ( & V_23 -> V_51 , V_177 ) ;
V_179:
( void ) F_81 ( & V_23 -> V_51 ) ;
V_176:
F_82 ( V_23 -> V_47 ) ;
V_169:
if ( V_23 -> V_1 & V_12 )
F_83 ( V_23 -> V_72 ) ;
V_168:
if ( V_23 -> V_165 )
F_84 ( V_72 -> V_89 , 2 ) ;
else
F_85 ( V_72 -> V_89 ) ;
V_166:
F_86 ( & V_23 -> V_160 ) ;
V_159:
F_87 ( V_23 -> V_156 ) ;
V_158:
F_88 ( V_23 ) ;
V_122:
for ( V_86 = V_102 ; V_86 < V_103 ; ++ V_86 )
F_89 ( & V_23 -> V_104 [ V_86 ] ) ;
if ( V_23 -> V_194 . V_195 )
F_90 ( V_23 -> V_194 . V_195 ) ;
F_91 ( V_23 ) ;
return V_24 ;
}
static void F_92 ( struct V_81 * V_72 )
{
struct V_22 * V_23 = F_93 ( V_72 ) ;
enum V_85 V_86 ;
F_94 ( & V_23 -> V_191 ) ;
if ( V_23 -> V_194 . V_196 )
F_95 ( & V_23 -> V_194 . V_197 ) ;
F_96 ( V_23 -> V_194 . V_198 ) ;
if ( V_23 -> V_117 ) {
F_97 ( V_23 ) ;
F_98 ( V_23 ) ;
F_99 ( V_23 ) ;
F_100 ( V_23 ) ;
}
F_79 ( V_23 ) ;
F_78 ( V_23 ) ;
if ( V_23 -> V_181 )
( void ) F_80 ( & V_23 -> V_51 , V_182 ) ;
( void ) F_80 ( & V_23 -> V_51 , V_177 ) ;
F_31 ( V_23 ) ;
if ( V_23 -> V_42 )
( void ) F_80 ( & V_23 -> V_51 , V_52 ) ;
( void ) F_81 ( & V_23 -> V_51 ) ;
F_32 ( V_23 ) ;
F_82 ( V_23 -> V_47 ) ;
if ( V_23 -> V_1 & V_12 )
F_83 ( V_23 -> V_72 ) ;
if ( V_23 -> V_165 )
F_84 ( V_72 -> V_89 , 2 ) ;
else
F_85 ( V_72 -> V_89 ) ;
F_86 ( & V_23 -> V_160 ) ;
F_87 ( V_23 -> V_156 ) ;
if ( V_23 -> V_194 . V_195 )
F_90 ( V_23 -> V_194 . V_195 ) ;
F_88 ( V_23 ) ;
for ( V_86 = V_102 ; V_86 < V_103 ; ++ V_86 )
F_89 ( & V_23 -> V_104 [ V_86 ] ) ;
F_91 ( V_23 ) ;
}
static void F_101 ( struct V_81 * V_72 ,
struct V_199 * V_200 )
{
struct V_201 * V_202 ;
V_202 = V_201 ( V_200 ) ;
if ( V_202 -> V_203 ) {
struct V_204 * V_205 =
V_204 ( V_202 -> V_203 ) ;
F_59 ( & V_205 -> V_153 , true , V_154 ) ;
F_102 ( & V_205 -> V_153 ) ;
F_103 ( & V_202 -> V_203 ) ;
}
F_104 ( & V_202 -> V_206 ) ;
F_91 ( V_202 ) ;
}
static int F_105 ( struct V_81 * V_72 , struct V_199 * V_200 )
{
struct V_22 * V_23 = F_93 ( V_72 ) ;
struct V_201 * V_202 ;
int V_24 = - V_32 ;
V_202 = F_4 ( sizeof( * V_202 ) , V_31 ) ;
if ( F_6 ( V_202 == NULL ) )
return V_24 ;
V_202 -> V_206 = F_106 ( V_23 -> V_160 , 10 ) ;
if ( F_6 ( V_202 -> V_206 == NULL ) )
goto V_207;
V_200 -> V_208 = V_202 ;
return 0 ;
V_207:
F_91 ( V_202 ) ;
return V_24 ;
}
static struct V_204 * F_107 ( struct V_81 * V_72 ,
struct V_199 * V_200 ,
unsigned int V_209 )
{
int V_24 ;
struct V_201 * V_202 = V_201 ( V_200 ) ;
struct V_204 * V_205 ;
if ( ! F_108 ( V_200 ) || ! ( V_209 & V_210 ) )
return NULL ;
V_24 = F_109 ( & V_72 -> V_211 ) ;
if ( F_6 ( V_24 != 0 ) )
return F_110 ( - V_212 ) ;
if ( F_111 ( V_200 ) ) {
F_112 ( & V_72 -> V_211 ) ;
return NULL ;
}
if ( V_202 -> V_203 ) {
F_112 ( & V_72 -> V_211 ) ;
if ( V_209 & V_213 )
return NULL ;
F_15 ( L_61
L_62 ) ;
return F_110 ( - V_214 ) ;
}
F_112 ( & V_72 -> V_211 ) ;
V_205 = V_204 ( V_200 -> V_215 ) ;
V_24 = F_113 ( & V_205 -> V_153 , true ) ;
if ( F_6 ( V_24 != 0 ) )
V_205 = F_110 ( V_24 ) ;
return V_205 ;
}
static long F_114 ( struct V_216 * V_217 , unsigned int V_218 ,
unsigned long V_219 ,
long (* F_115)( struct V_216 * , unsigned int ,
unsigned long ) )
{
struct V_199 * V_200 = V_217 -> V_220 ;
struct V_81 * V_72 = V_200 -> V_221 -> V_72 ;
unsigned int V_222 = F_116 ( V_218 ) ;
struct V_204 * V_205 ;
unsigned int V_209 ;
long V_24 ;
if ( ( V_222 >= V_223 ) && ( V_222 < V_224 )
&& ( V_222 < V_223 + V_72 -> V_225 -> V_226 ) ) {
const struct V_227 * V_228 =
& V_229 [ V_222 - V_223 ] ;
if ( V_222 == V_223 + V_230 ) {
V_24 = ( long ) F_117 ( V_228 -> V_209 , V_200 ) ;
if ( F_6 ( V_24 != 0 ) )
return V_24 ;
if ( F_6 ( ( V_218 & ( V_231 | V_232 ) ) != V_231 ) )
goto V_233;
return ( long ) F_118 ( V_72 , V_219 , V_200 ,
F_119 ( V_218 ) ) ;
} else if ( V_222 == V_223 + V_234 ) {
if ( ! F_111 ( V_200 ) &&
! F_120 ( V_235 ) )
return - V_214 ;
}
if ( F_6 ( V_228 -> V_218 != V_218 ) )
goto V_233;
V_209 = V_228 -> V_209 ;
} else if ( ! F_121 ( V_222 , & V_209 ) )
return - V_80 ;
V_205 = F_107 ( V_72 , V_200 , V_209 ) ;
if ( F_25 ( V_205 ) ) {
V_24 = F_122 ( V_205 ) ;
if ( V_24 != - V_212 )
F_2 ( L_63 ,
V_222 , V_24 ) ;
return V_24 ;
}
V_24 = F_115 ( V_217 , V_218 , V_219 ) ;
if ( V_205 )
F_123 ( & V_205 -> V_153 ) ;
return V_24 ;
V_233:
F_15 ( L_64 ,
V_222 - V_223 ) ;
return - V_80 ;
}
static long F_124 ( struct V_216 * V_217 , unsigned int V_218 ,
unsigned long V_219 )
{
return F_114 ( V_217 , V_218 , V_219 , & V_236 ) ;
}
static long F_125 ( struct V_216 * V_217 , unsigned int V_218 ,
unsigned long V_219 )
{
return F_114 ( V_217 , V_218 , V_219 , & V_237 ) ;
}
static void F_126 ( struct V_81 * V_72 )
{
}
static void F_58 ( struct V_204 * V_205 )
{
F_50 ( & V_205 -> V_153 ) ;
}
static int F_127 ( struct V_81 * V_72 ,
struct V_238 * V_215 )
{
struct V_204 * V_205 ;
V_205 = F_4 ( sizeof( * V_205 ) , V_31 ) ;
if ( F_6 ( V_205 == NULL ) )
return - V_32 ;
F_58 ( V_205 ) ;
F_59 ( & V_205 -> V_153 , true , V_154 ) ;
V_215 -> V_208 = V_205 ;
return 0 ;
}
static void F_128 ( struct V_81 * V_72 ,
struct V_238 * V_215 )
{
struct V_204 * V_205 = V_204 ( V_215 ) ;
V_215 -> V_208 = NULL ;
F_91 ( V_205 ) ;
}
static int F_129 ( struct V_81 * V_72 ,
struct V_199 * V_200 ,
bool V_239 )
{
struct V_22 * V_23 = F_93 ( V_72 ) ;
struct V_201 * V_202 = V_201 ( V_200 ) ;
struct V_204 * V_240 = V_23 -> V_155 ;
struct V_204 * V_205 = V_204 ( V_200 -> V_215 ) ;
int V_24 = 0 ;
if ( V_240 ) {
F_8 ( V_240 != & V_23 -> V_152 ) ;
V_24 = F_130 ( & V_240 -> V_153 , false , V_202 -> V_206 ) ;
if ( F_6 ( V_24 != 0 ) )
return V_24 ;
F_59 ( & V_240 -> V_153 , true , V_154 ) ;
V_23 -> V_155 = NULL ;
}
F_59 ( & V_205 -> V_153 , false , V_154 ) ;
if ( ! V_239 ) {
F_102 ( & V_205 -> V_153 ) ;
F_8 ( V_202 -> V_203 != V_200 -> V_215 ) ;
F_103 ( & V_202 -> V_203 ) ;
}
V_23 -> V_155 = V_205 ;
F_131 ( V_72 ) ;
return 0 ;
}
static void F_132 ( struct V_81 * V_72 ,
struct V_199 * V_200 )
{
struct V_22 * V_23 = F_93 ( V_72 ) ;
struct V_201 * V_202 = V_201 ( V_200 ) ;
struct V_204 * V_205 = V_204 ( V_200 -> V_215 ) ;
int V_24 ;
V_202 -> V_203 = F_133 ( V_200 -> V_215 ) ;
V_24 = F_130 ( & V_205 -> V_153 , false , V_202 -> V_206 ) ;
F_134 ( V_23 ) ;
if ( F_6 ( ( V_24 != 0 ) ) ) {
F_15 ( L_65 ) ;
F_103 ( & V_202 -> V_203 ) ;
}
F_59 ( & V_205 -> V_153 , false , V_154 ) ;
if ( ! V_23 -> V_117 )
F_100 ( V_23 ) ;
V_23 -> V_155 = & V_23 -> V_152 ;
F_59 ( & V_23 -> V_152 . V_153 , false , V_154 ) ;
F_102 ( & V_23 -> V_152 . V_153 ) ;
if ( V_23 -> V_117 )
F_135 ( V_23 ) ;
}
static void F_136 ( struct V_22 * V_23 )
{
F_69 ( & V_23 -> V_101 ) ;
if ( ! V_23 -> V_51 . V_45 [ V_177 ] . V_180 ) {
F_56 ( V_23 , V_241 , V_241 ) ;
V_23 -> V_51 . V_45 [ V_177 ] . V_180 = true ;
}
F_70 ( & V_23 -> V_101 ) ;
}
void F_75 ( struct V_22 * V_23 )
{
( void ) F_113 ( & V_23 -> V_97 , false ) ;
F_136 ( V_23 ) ;
F_123 ( & V_23 -> V_97 ) ;
}
static void F_137 ( struct V_22 * V_23 )
{
F_69 ( & V_23 -> V_101 ) ;
if ( V_23 -> V_51 . V_45 [ V_177 ] . V_180 ) {
V_23 -> V_51 . V_45 [ V_177 ] . V_180 = false ;
F_56 ( V_23 , V_241 ,
V_242 |
V_243 ) ;
}
F_70 ( & V_23 -> V_101 ) ;
}
void F_100 ( struct V_22 * V_23 )
{
F_138 ( & V_23 -> V_97 , false ) ;
F_69 ( & V_23 -> V_101 ) ;
if ( V_23 -> V_51 . V_45 [ V_177 ] . V_180 ) {
V_23 -> V_51 . V_45 [ V_177 ] . V_180 = false ;
F_70 ( & V_23 -> V_101 ) ;
if ( F_27 ( & V_23 -> V_51 , V_177 ) )
F_15 ( L_66 ) ;
F_56 ( V_23 , V_241 ,
V_242 |
V_243 ) ;
} else
F_70 ( & V_23 -> V_101 ) ;
F_139 ( & V_23 -> V_97 ) ;
}
static void F_140 ( struct V_244 * V_89 )
{
struct V_81 * V_72 = F_141 ( V_89 ) ;
F_142 ( V_89 ) ;
F_143 ( V_72 ) ;
}
static int V_193 ( struct V_245 * V_246 , unsigned long V_247 ,
void * V_248 )
{
struct V_22 * V_23 =
F_144 ( V_246 , struct V_22 , V_191 ) ;
switch ( V_247 ) {
case V_249 :
if ( V_23 -> V_117 )
F_97 ( V_23 ) ;
F_145 ( & V_23 -> V_97 ) ;
F_146 ( V_23 ) ;
F_147 ( V_23 ) ;
F_31 ( V_23 ) ;
F_148 ( & V_23 -> V_51 ) ;
F_29 ( V_23 -> V_47 ) ;
break;
case V_250 :
case V_251 :
F_23 ( V_23 -> V_47 ) ;
F_149 ( & V_23 -> V_97 ) ;
if ( V_23 -> V_117 )
F_135 ( V_23 ) ;
break;
case V_252 :
break;
default:
break;
}
return 0 ;
}
static int F_150 ( struct V_244 * V_89 , T_4 V_38 )
{
struct V_81 * V_72 = F_141 ( V_89 ) ;
struct V_22 * V_23 = F_93 ( V_72 ) ;
if ( V_23 -> V_253 )
return - V_254 ;
F_151 ( V_89 ) ;
F_142 ( V_89 ) ;
F_152 ( V_89 , V_255 ) ;
return 0 ;
}
static int F_153 ( struct V_244 * V_89 )
{
F_152 ( V_89 , V_256 ) ;
F_154 ( V_89 ) ;
return F_155 ( V_89 ) ;
}
static int F_156 ( struct V_257 * V_258 )
{
struct V_244 * V_89 = F_157 ( V_258 ) ;
struct V_259 V_30 ;
V_30 . V_260 = 0 ;
return F_150 ( V_89 , V_30 ) ;
}
static int F_158 ( struct V_257 * V_258 )
{
struct V_244 * V_89 = F_157 ( V_258 ) ;
return F_153 ( V_89 ) ;
}
static int F_159 ( struct V_257 * V_258 )
{
struct V_244 * V_89 = F_157 ( V_258 ) ;
struct V_81 * V_72 = F_141 ( V_89 ) ;
struct V_22 * V_23 = F_93 ( V_72 ) ;
V_23 -> V_261 = true ;
if ( V_23 -> V_117 )
F_99 ( V_23 ) ;
if ( F_160 ( & V_23 -> V_262 ) != 0 ) {
F_15 ( L_67 ) ;
if ( V_23 -> V_117 )
F_74 ( V_23 ) ;
F_161 ( F_17 ( V_23 ) ) ;
V_23 -> V_261 = false ;
return - V_254 ;
}
if ( V_23 -> V_117 )
F_137 ( V_23 ) ;
F_32 ( V_23 ) ;
return 0 ;
}
static int F_162 ( struct V_257 * V_258 )
{
struct V_244 * V_89 = F_157 ( V_258 ) ;
struct V_81 * V_72 = F_141 ( V_89 ) ;
struct V_22 * V_23 = F_93 ( V_72 ) ;
int V_24 ;
F_56 ( V_23 , V_119 , V_120 ) ;
( void ) F_34 ( V_23 , V_119 ) ;
if ( V_23 -> V_117 )
F_74 ( V_23 ) ;
V_24 = F_21 ( V_23 ) ;
if ( V_24 )
return V_24 ;
if ( V_23 -> V_117 )
F_136 ( V_23 ) ;
V_23 -> V_261 = false ;
return 0 ;
}
static int F_163 ( struct V_244 * V_89 , const struct V_263 * V_264 )
{
return F_164 ( V_89 , V_264 , & V_225 ) ;
}
static int T_5 F_165 ( void )
{
int V_24 ;
if ( F_166 () )
return - V_80 ;
V_24 = F_167 ( & V_225 , & V_265 ) ;
if ( V_24 )
F_15 ( L_68 ) ;
return V_24 ;
}
static void T_6 F_168 ( void )
{
F_169 ( & V_225 , & V_265 ) ;
}
