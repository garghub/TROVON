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
V_24 = F_7 ( & V_26 -> V_36 , false , true , false , NULL ) ;
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
V_23 = F_4 ( sizeof( * V_23 ) , V_31 ) ;
if ( F_6 ( V_23 == NULL ) ) {
F_15 ( L_32 ) ;
return - V_32 ;
}
F_47 ( V_72 -> V_88 ) ;
V_23 -> V_72 = V_72 ;
V_23 -> V_89 = V_83 ;
V_23 -> V_90 = ( T_1 ) - 100 ;
F_48 ( & V_23 -> V_91 ) ;
F_48 ( & V_23 -> V_92 ) ;
F_48 ( & V_23 -> V_93 ) ;
F_49 ( & V_23 -> V_94 ) ;
F_50 ( & V_23 -> V_95 ) ;
F_51 ( & V_23 -> V_96 ) ;
F_51 ( & V_23 -> V_97 ) ;
F_51 ( & V_23 -> V_98 ) ;
F_51 ( & V_23 -> V_99 ) ;
for ( V_86 = V_100 ; V_86 < V_101 ; ++ V_86 ) {
F_52 ( & V_23 -> V_102 [ V_86 ] ) ;
F_53 ( & V_23 -> V_103 [ V_86 ] ) ;
}
F_48 ( & V_23 -> V_104 ) ;
F_54 ( & V_23 -> V_105 ) ;
F_54 ( & V_23 -> V_106 ) ;
V_23 -> V_107 = 0 ;
F_55 ( & V_23 -> V_108 , 0 ) ;
V_23 -> V_109 = 0 ;
V_23 -> V_110 = F_56 ( V_72 -> V_88 , 0 ) ;
V_23 -> V_111 = F_56 ( V_72 -> V_88 , 1 ) ;
V_23 -> V_112 = F_56 ( V_72 -> V_88 , 2 ) ;
V_23 -> V_113 = V_114 ;
F_57 ( V_23 , V_115 , V_116 ) ;
V_84 = F_34 ( V_23 , V_115 ) ;
if ( V_84 != V_116 ) {
V_24 = - V_117 ;
F_15 ( L_33 , V_84 ) ;
goto V_118;
}
V_23 -> V_1 = F_34 ( V_23 , V_119 ) ;
V_24 = F_36 ( V_23 ) ;
if ( F_6 ( V_24 != 0 ) ) {
F_2 ( L_34 ) ;
V_87 = true ;
}
V_23 -> V_120 = F_34 ( V_23 , V_121 ) ;
V_23 -> V_122 = F_34 ( V_23 , V_123 ) ;
V_23 -> V_60 = F_34 ( V_23 , V_124 ) ;
V_23 -> V_61 = F_34 ( V_23 , V_125 ) ;
F_33 ( V_23 ) ;
if ( V_23 -> V_1 & V_16 ) {
V_23 -> V_126 =
F_34 ( V_23 , V_127 ) ;
V_23 -> V_128 =
F_34 ( V_23 , V_129 ) ;
V_23 -> V_130 =
F_34 ( V_23 , V_131 ) ;
V_23 -> V_130 -= V_23 -> V_120 ;
} else {
V_23 -> V_130 = 512 * 1024 * 1024 ;
}
V_23 -> V_132 = 0 ;
V_23 -> V_133 = 0 ;
if ( V_23 -> V_1 & V_20 ) {
T_3 V_134 =
F_34 ( V_23 ,
V_135 ) ;
V_23 -> V_132 = V_134 * 1024 / V_33 ;
V_23 -> V_136 =
F_34 ( V_23 ,
V_137 ) ;
V_23 -> V_133 =
F_34 ( V_23 , V_138 ) ;
V_23 -> V_139 =
F_34 ( V_23 , V_140 ) ;
V_23 -> V_141 =
F_34 ( V_23 , V_142 ) ;
F_57 ( V_23 , V_143 ,
V_144 ) ;
V_23 -> V_145 = F_34 ( V_23 ,
V_143 ) ;
F_57 ( V_23 , V_143 ,
V_146 ) ;
V_23 -> V_147 = F_34 ( V_23 ,
V_143 ) ;
} else {
V_23 -> V_145 = 8192 ;
V_23 -> V_147 = 8192 ;
V_23 -> V_136 = V_23 -> V_120 ;
}
F_1 ( V_23 -> V_1 ) ;
V_24 = F_43 ( V_23 ) ;
if ( F_6 ( V_24 != 0 ) )
goto V_118;
if ( V_23 -> V_1 & V_16 ) {
F_2 ( L_35 ,
( unsigned ) V_23 -> V_126 ) ;
F_2 ( L_36 ,
( unsigned ) V_23 -> V_128 ) ;
F_2 ( L_37 ,
( unsigned ) V_23 -> V_130 / 1024 ) ;
}
F_2 ( L_38 ,
V_23 -> V_136 / 1024 ) ;
F_2 ( L_39 ,
V_23 -> V_111 , V_23 -> V_120 / 1024 ) ;
F_2 ( L_40 ,
V_23 -> V_112 , V_23 -> V_122 / 1024 ) ;
V_24 = F_58 ( V_23 ) ;
if ( F_6 ( V_24 != 0 ) )
goto V_118;
F_59 ( & V_23 -> V_148 ) ;
F_60 ( & V_23 -> V_148 . V_149 , false , V_150 ) ;
V_23 -> V_151 = & V_23 -> V_148 ;
V_23 -> V_152 = F_61 ( V_23 -> V_112 ,
V_23 -> V_122 ) ;
if ( F_6 ( V_23 -> V_152 == NULL ) ) {
V_24 = - V_32 ;
F_15 ( L_41 ) ;
goto V_153;
}
if ( ! ( V_23 -> V_1 & V_13 ) &&
! ( V_23 -> V_1 & V_11 ) &&
! F_62 ( V_23 ) ) {
V_24 = - V_117 ;
F_15 ( L_42 ) ;
goto V_154;
}
V_23 -> V_155 = F_63
( V_23 -> V_156 . V_157 , 12 , & V_158 ) ;
if ( F_6 ( V_23 -> V_155 == NULL ) ) {
F_15 ( L_43 ) ;
V_24 = - V_32 ;
goto V_154;
}
V_72 -> V_159 = V_23 ;
V_24 = F_64 ( V_72 -> V_88 , L_44 ) ;
V_23 -> V_160 = ( V_24 != 0 ) ;
if ( V_23 -> V_160 ) {
F_2 ( L_45
L_46 ) ;
V_24 = F_65 ( V_72 -> V_88 , 2 , L_47 ) ;
if ( F_6 ( V_24 != 0 ) ) {
F_15 ( L_48 ) ;
goto V_161;
}
}
if ( V_23 -> V_1 & V_12 ) {
V_24 = F_66 ( V_72 , V_72 -> V_88 -> V_162 ) ;
if ( V_24 != 0 ) {
F_15 ( L_49 , V_24 ) ;
goto V_163;
}
}
V_23 -> V_47 = F_67 ( V_23 ) ;
if ( F_6 ( V_23 -> V_47 == NULL ) ) {
V_24 = - V_32 ;
goto V_164;
}
V_24 = F_68 ( & V_23 -> V_51 ,
V_23 -> V_165 . V_166 . V_157 ,
& V_167 ,
V_72 -> V_168 -> V_169 ,
V_170 ,
false ) ;
if ( F_6 ( V_24 != 0 ) ) {
F_15 ( L_50 ) ;
goto V_171;
}
V_24 = F_69 ( & V_23 -> V_51 , V_172 ,
( V_23 -> V_120 >> V_173 ) ) ;
if ( F_6 ( V_24 != 0 ) ) {
F_15 ( L_51 ) ;
goto V_174;
}
V_23 -> V_51 . V_45 [ V_172 ] . V_175 = false ;
V_23 -> V_176 = true ;
if ( ( ( V_23 -> V_1 & ( V_14 | V_16 ) ) == 0 ) ||
V_87 || F_69 ( & V_23 -> V_51 , V_177 ,
V_177 ) != 0 ) {
F_2 ( L_52
L_53 ) ;
V_23 -> V_176 = false ;
}
if ( V_23 -> V_1 & V_20 ) {
V_23 -> V_42 = true ;
if ( F_69 ( & V_23 -> V_51 , V_52 ,
V_52 ) != 0 ) {
F_2 ( L_54
L_55 ) ;
V_23 -> V_42 = false ;
}
}
if ( V_23 -> V_42 ) {
F_70 ( & V_23 -> V_98 ) ;
F_57 ( V_23 , V_143 , V_178 ) ;
V_23 -> V_48 = ! ! F_34 ( V_23 , V_143 ) ;
F_71 ( & V_23 -> V_98 ) ;
}
V_24 = F_72 ( V_23 ) ;
if ( F_6 ( V_24 != 0 ) )
goto V_179;
F_73 ( V_23 ) ;
V_24 = F_21 ( V_23 ) ;
if ( V_24 )
goto V_180;
F_2 ( L_56 , V_23 -> V_48 ? L_57 : L_58 ) ;
if ( V_23 -> V_113 ) {
F_74 ( V_23 ) ;
F_75 ( V_23 ) ;
F_76 ( V_23 ) ;
}
V_23 -> V_181 . V_182 = V_183 ;
F_77 ( & V_23 -> V_181 ) ;
return 0 ;
V_180:
F_78 ( V_23 ) ;
F_79 ( V_23 ) ;
V_179:
if ( V_23 -> V_42 )
( void ) F_80 ( & V_23 -> V_51 , V_52 ) ;
if ( V_23 -> V_176 )
( void ) F_80 ( & V_23 -> V_51 , V_177 ) ;
( void ) F_80 ( & V_23 -> V_51 , V_172 ) ;
V_174:
( void ) F_81 ( & V_23 -> V_51 ) ;
V_171:
F_82 ( V_23 -> V_47 ) ;
V_164:
if ( V_23 -> V_1 & V_12 )
F_83 ( V_23 -> V_72 ) ;
V_163:
if ( V_23 -> V_160 )
F_84 ( V_72 -> V_88 , 2 ) ;
else
F_85 ( V_72 -> V_88 ) ;
V_161:
F_86 ( & V_23 -> V_155 ) ;
V_154:
F_87 ( V_23 -> V_152 ) ;
V_153:
F_88 ( V_23 ) ;
V_118:
for ( V_86 = V_100 ; V_86 < V_101 ; ++ V_86 )
F_89 ( & V_23 -> V_102 [ V_86 ] ) ;
if ( V_23 -> V_184 . V_185 )
F_90 ( V_23 -> V_184 . V_185 ) ;
F_91 ( V_23 ) ;
return V_24 ;
}
static int F_92 ( struct V_81 * V_72 )
{
struct V_22 * V_23 = F_93 ( V_72 ) ;
enum V_85 V_86 ;
F_94 ( & V_23 -> V_181 ) ;
if ( V_23 -> V_184 . V_186 )
F_95 ( & V_23 -> V_184 . V_187 ) ;
F_96 ( V_23 -> V_184 . V_188 ) ;
if ( V_23 -> V_113 ) {
F_97 ( V_23 ) ;
F_98 ( V_23 ) ;
F_99 ( V_23 ) ;
F_100 ( V_23 ) ;
}
F_79 ( V_23 ) ;
F_78 ( V_23 ) ;
if ( V_23 -> V_176 )
( void ) F_80 ( & V_23 -> V_51 , V_177 ) ;
( void ) F_80 ( & V_23 -> V_51 , V_172 ) ;
F_31 ( V_23 ) ;
if ( V_23 -> V_42 )
( void ) F_80 ( & V_23 -> V_51 , V_52 ) ;
( void ) F_81 ( & V_23 -> V_51 ) ;
F_32 ( V_23 ) ;
F_82 ( V_23 -> V_47 ) ;
if ( V_23 -> V_1 & V_12 )
F_83 ( V_23 -> V_72 ) ;
if ( V_23 -> V_160 )
F_84 ( V_72 -> V_88 , 2 ) ;
else
F_85 ( V_72 -> V_88 ) ;
F_86 ( & V_23 -> V_155 ) ;
F_87 ( V_23 -> V_152 ) ;
if ( V_23 -> V_184 . V_185 )
F_90 ( V_23 -> V_184 . V_185 ) ;
F_88 ( V_23 ) ;
for ( V_86 = V_100 ; V_86 < V_101 ; ++ V_86 )
F_89 ( & V_23 -> V_102 [ V_86 ] ) ;
F_91 ( V_23 ) ;
return 0 ;
}
static void F_101 ( struct V_81 * V_72 ,
struct V_189 * V_190 )
{
struct V_191 * V_192 = V_191 ( V_190 ) ;
struct V_22 * V_23 = F_93 ( V_72 ) ;
F_102 ( V_23 -> V_47 , & V_192 -> V_193 ) ;
}
static void F_103 ( struct V_81 * V_72 ,
struct V_189 * V_190 )
{
struct V_191 * V_192 ;
V_192 = V_191 ( V_190 ) ;
if ( V_192 -> V_194 ) {
struct V_195 * V_196 =
V_195 ( V_192 -> V_194 ) ;
F_60 ( & V_196 -> V_149 , true , V_150 ) ;
F_104 ( & V_196 -> V_149 ) ;
F_105 ( & V_192 -> V_194 ) ;
}
F_106 ( & V_192 -> V_197 ) ;
F_91 ( V_192 ) ;
}
static int F_107 ( struct V_81 * V_72 , struct V_189 * V_190 )
{
struct V_22 * V_23 = F_93 ( V_72 ) ;
struct V_191 * V_192 ;
int V_24 = - V_32 ;
V_192 = F_4 ( sizeof( * V_192 ) , V_31 ) ;
if ( F_6 ( V_192 == NULL ) )
return V_24 ;
F_53 ( & V_192 -> V_193 ) ;
V_192 -> V_197 = F_108 ( V_23 -> V_155 , 10 ) ;
if ( F_6 ( V_192 -> V_197 == NULL ) )
goto V_198;
V_190 -> V_199 = V_192 ;
return 0 ;
V_198:
F_91 ( V_192 ) ;
return V_24 ;
}
static struct V_195 * F_109 ( struct V_81 * V_72 ,
struct V_189 * V_190 ,
unsigned int V_200 )
{
int V_24 ;
struct V_191 * V_192 = V_191 ( V_190 ) ;
struct V_195 * V_196 ;
if ( V_190 -> V_201 -> type != V_202 ||
! ( V_200 & V_203 ) )
return NULL ;
V_24 = F_110 ( & V_72 -> V_204 ) ;
if ( F_6 ( V_24 != 0 ) )
return F_111 ( - V_205 ) ;
if ( V_190 -> V_206 ) {
F_112 ( & V_72 -> V_204 ) ;
return NULL ;
}
if ( V_192 -> V_194 ) {
F_112 ( & V_72 -> V_204 ) ;
if ( V_200 & V_207 )
return NULL ;
F_15 ( L_59
L_60 ) ;
return F_111 ( - V_208 ) ;
}
F_112 ( & V_72 -> V_204 ) ;
if ( ! ( V_200 & V_209 ) ) {
F_15 ( L_61 ) ;
return F_111 ( - V_210 ) ;
}
V_196 = V_195 ( V_190 -> V_211 ) ;
V_24 = F_113 ( & V_196 -> V_149 , true ) ;
if ( F_6 ( V_24 != 0 ) )
V_196 = F_111 ( V_24 ) ;
return V_196 ;
}
static long F_114 ( struct V_212 * V_213 , unsigned int V_214 ,
unsigned long V_215 ,
long (* F_115)( struct V_212 * , unsigned int ,
unsigned long ) )
{
struct V_189 * V_190 = V_213 -> V_216 ;
struct V_81 * V_72 = V_190 -> V_201 -> V_72 ;
unsigned int V_217 = F_116 ( V_214 ) ;
struct V_195 * V_196 ;
unsigned int V_200 ;
long V_24 ;
if ( ( V_217 >= V_218 ) && ( V_217 < V_219 )
&& ( V_217 < V_218 + V_72 -> V_220 -> V_221 ) ) {
const struct V_222 * V_223 =
& V_224 [ V_217 - V_218 ] ;
if ( V_217 == V_218 + V_225 ) {
V_24 = ( long ) F_117 ( V_223 -> V_200 , V_190 ) ;
if ( F_6 ( V_24 != 0 ) )
return V_24 ;
if ( F_6 ( ( V_214 & ( V_226 | V_227 ) ) != V_226 ) )
goto V_228;
return ( long ) F_118 ( V_72 , V_215 , V_190 ,
F_119 ( V_214 ) ) ;
}
if ( F_6 ( V_223 -> V_214 != V_214 ) )
goto V_228;
V_200 = V_223 -> V_200 ;
} else if ( ! F_120 ( V_217 , & V_200 ) )
return - V_80 ;
V_196 = F_109 ( V_72 , V_190 , V_200 ) ;
if ( F_25 ( V_196 ) ) {
V_24 = F_121 ( V_196 ) ;
if ( V_24 != - V_205 )
F_2 ( L_62 ,
V_217 , V_24 ) ;
return V_24 ;
}
V_24 = F_115 ( V_213 , V_214 , V_215 ) ;
if ( V_196 )
F_122 ( & V_196 -> V_149 ) ;
return V_24 ;
V_228:
F_15 ( L_63 ,
V_217 - V_218 ) ;
return - V_80 ;
}
static long F_123 ( struct V_212 * V_213 , unsigned int V_214 ,
unsigned long V_215 )
{
return F_114 ( V_213 , V_214 , V_215 , & V_229 ) ;
}
static long F_124 ( struct V_212 * V_213 , unsigned int V_214 ,
unsigned long V_215 )
{
return F_114 ( V_213 , V_214 , V_215 , & V_230 ) ;
}
static void F_125 ( struct V_81 * V_72 )
{
}
static void F_59 ( struct V_195 * V_196 )
{
F_50 ( & V_196 -> V_149 ) ;
}
static int F_126 ( struct V_81 * V_72 ,
struct V_231 * V_211 )
{
struct V_195 * V_196 ;
V_196 = F_4 ( sizeof( * V_196 ) , V_31 ) ;
if ( F_6 ( V_196 == NULL ) )
return - V_32 ;
F_59 ( V_196 ) ;
F_60 ( & V_196 -> V_149 , true , V_150 ) ;
V_211 -> V_199 = V_196 ;
return 0 ;
}
static void F_127 ( struct V_81 * V_72 ,
struct V_231 * V_211 )
{
struct V_195 * V_196 = V_195 ( V_211 ) ;
V_211 -> V_199 = NULL ;
F_91 ( V_196 ) ;
}
static int F_128 ( struct V_81 * V_72 ,
struct V_189 * V_190 ,
bool V_232 )
{
struct V_22 * V_23 = F_93 ( V_72 ) ;
struct V_191 * V_192 = V_191 ( V_190 ) ;
struct V_195 * V_233 = V_23 -> V_151 ;
struct V_195 * V_196 = V_195 ( V_190 -> V_211 ) ;
int V_24 = 0 ;
if ( V_233 ) {
F_8 ( V_233 != & V_23 -> V_148 ) ;
V_24 = F_129 ( & V_233 -> V_149 , false , V_192 -> V_197 ) ;
if ( F_6 ( V_24 != 0 ) )
return V_24 ;
F_60 ( & V_233 -> V_149 , true , V_150 ) ;
V_23 -> V_151 = NULL ;
}
F_60 ( & V_196 -> V_149 , false , V_150 ) ;
if ( ! V_232 ) {
F_104 ( & V_196 -> V_149 ) ;
F_8 ( V_192 -> V_194 != V_190 -> V_211 ) ;
F_105 ( & V_192 -> V_194 ) ;
}
V_23 -> V_151 = V_196 ;
return 0 ;
}
static void F_130 ( struct V_81 * V_72 ,
struct V_189 * V_190 ,
bool V_234 )
{
struct V_22 * V_23 = F_93 ( V_72 ) ;
struct V_191 * V_192 = V_191 ( V_190 ) ;
struct V_195 * V_196 = V_195 ( V_190 -> V_211 ) ;
int V_24 ;
V_192 -> V_194 = F_131 ( V_190 -> V_211 ) ;
V_24 = F_129 ( & V_196 -> V_149 , false , V_192 -> V_197 ) ;
if ( F_6 ( ( V_24 != 0 ) ) ) {
F_15 ( L_64 ) ;
F_105 ( & V_192 -> V_194 ) ;
}
F_60 ( & V_196 -> V_149 , false , V_150 ) ;
if ( ! V_23 -> V_113 )
F_100 ( V_23 ) ;
V_23 -> V_151 = & V_23 -> V_148 ;
F_60 ( & V_23 -> V_148 . V_149 , false , V_150 ) ;
F_104 ( & V_23 -> V_148 . V_149 ) ;
if ( V_23 -> V_113 )
F_132 ( V_23 ) ;
}
static void F_133 ( struct V_22 * V_23 )
{
F_70 ( & V_23 -> V_99 ) ;
if ( ! V_23 -> V_51 . V_45 [ V_172 ] . V_175 ) {
F_57 ( V_23 , V_235 , V_235 ) ;
V_23 -> V_51 . V_45 [ V_172 ] . V_175 = true ;
}
F_71 ( & V_23 -> V_99 ) ;
}
void F_75 ( struct V_22 * V_23 )
{
F_113 ( & V_23 -> V_95 , false ) ;
F_133 ( V_23 ) ;
F_122 ( & V_23 -> V_95 ) ;
}
static void F_134 ( struct V_22 * V_23 )
{
F_70 ( & V_23 -> V_99 ) ;
if ( V_23 -> V_51 . V_45 [ V_172 ] . V_175 ) {
V_23 -> V_51 . V_45 [ V_172 ] . V_175 = false ;
F_57 ( V_23 , V_235 ,
V_236 |
V_237 ) ;
}
F_71 ( & V_23 -> V_99 ) ;
}
void F_100 ( struct V_22 * V_23 )
{
F_135 ( & V_23 -> V_95 , false ) ;
F_70 ( & V_23 -> V_99 ) ;
if ( V_23 -> V_51 . V_45 [ V_172 ] . V_175 ) {
V_23 -> V_51 . V_45 [ V_172 ] . V_175 = false ;
F_71 ( & V_23 -> V_99 ) ;
if ( F_27 ( & V_23 -> V_51 , V_172 ) )
F_15 ( L_65 ) ;
F_57 ( V_23 , V_235 ,
V_236 |
V_237 ) ;
} else
F_71 ( & V_23 -> V_99 ) ;
F_136 ( & V_23 -> V_95 ) ;
}
static void F_137 ( struct V_238 * V_88 )
{
struct V_81 * V_72 = F_138 ( V_88 ) ;
F_139 ( V_88 ) ;
F_140 ( V_72 ) ;
}
static int V_183 ( struct V_239 * V_240 , unsigned long V_241 ,
void * V_242 )
{
struct V_22 * V_23 =
F_141 ( V_240 , struct V_22 , V_181 ) ;
switch ( V_241 ) {
case V_243 :
if ( V_23 -> V_113 )
F_97 ( V_23 ) ;
F_142 ( & V_23 -> V_95 ) ;
F_143 ( V_23 ) ;
F_144 ( V_23 ) ;
F_31 ( V_23 ) ;
F_145 ( & V_23 -> V_51 ) ;
F_29 ( V_23 -> V_47 ) ;
break;
case V_244 :
case V_245 :
F_23 ( V_23 -> V_47 ) ;
F_146 ( & V_23 -> V_95 ) ;
if ( V_23 -> V_113 )
F_132 ( V_23 ) ;
break;
case V_246 :
break;
default:
break;
}
return 0 ;
}
static int F_147 ( struct V_238 * V_88 , T_4 V_38 )
{
struct V_81 * V_72 = F_138 ( V_88 ) ;
struct V_22 * V_23 = F_93 ( V_72 ) ;
if ( V_23 -> V_247 )
return - V_248 ;
F_148 ( V_88 ) ;
F_139 ( V_88 ) ;
F_149 ( V_88 , V_249 ) ;
return 0 ;
}
static int F_150 ( struct V_238 * V_88 )
{
F_149 ( V_88 , V_250 ) ;
F_151 ( V_88 ) ;
return F_152 ( V_88 ) ;
}
static int F_153 ( struct V_251 * V_252 )
{
struct V_238 * V_88 = F_154 ( V_252 ) ;
struct V_253 V_30 ;
V_30 . V_254 = 0 ;
return F_147 ( V_88 , V_30 ) ;
}
static int F_155 ( struct V_251 * V_252 )
{
struct V_238 * V_88 = F_154 ( V_252 ) ;
return F_150 ( V_88 ) ;
}
static int F_156 ( struct V_251 * V_252 )
{
struct V_238 * V_88 = F_154 ( V_252 ) ;
struct V_81 * V_72 = F_138 ( V_88 ) ;
struct V_22 * V_23 = F_93 ( V_72 ) ;
V_23 -> V_255 = true ;
if ( V_23 -> V_113 )
F_99 ( V_23 ) ;
if ( F_157 ( & V_23 -> V_256 ) != 0 ) {
F_15 ( L_66 ) ;
if ( V_23 -> V_113 )
F_74 ( V_23 ) ;
F_158 ( F_17 ( V_23 ) ) ;
V_23 -> V_255 = false ;
return - V_248 ;
}
if ( V_23 -> V_113 )
F_134 ( V_23 ) ;
F_32 ( V_23 ) ;
return 0 ;
}
static int F_159 ( struct V_251 * V_252 )
{
struct V_238 * V_88 = F_154 ( V_252 ) ;
struct V_81 * V_72 = F_138 ( V_88 ) ;
struct V_22 * V_23 = F_93 ( V_72 ) ;
int V_24 ;
F_57 ( V_23 , V_115 , V_116 ) ;
( void ) F_34 ( V_23 , V_115 ) ;
if ( V_23 -> V_113 )
F_74 ( V_23 ) ;
V_24 = F_21 ( V_23 ) ;
if ( V_24 )
return V_24 ;
if ( V_23 -> V_113 )
F_133 ( V_23 ) ;
V_23 -> V_255 = false ;
return 0 ;
}
static int F_160 ( struct V_238 * V_88 , const struct V_257 * V_258 )
{
return F_161 ( V_88 , V_258 , & V_220 ) ;
}
static int T_5 F_162 ( void )
{
int V_24 ;
V_24 = F_163 ( & V_220 , & V_259 ) ;
if ( V_24 )
F_15 ( L_67 ) ;
return V_24 ;
}
static void T_6 F_164 ( void )
{
F_165 ( & V_220 , & V_259 ) ;
}
