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
}
static int F_3 ( struct V_21 * V_22 )
{
int V_23 ;
struct V_24 * V_25 ;
struct V_26 V_27 ;
volatile T_2 * V_28 ;
bool V_29 ;
V_23 = F_4 ( & V_22 -> V_30 ,
V_31 ,
V_32 ,
& V_33 ,
0 , false , NULL ,
& V_25 ) ;
if ( F_5 ( V_23 != 0 ) )
return V_23 ;
V_23 = F_6 ( V_25 , false , true , false , NULL ) ;
F_7 ( V_23 != 0 ) ;
V_23 = F_8 ( V_25 , 0 , 1 , & V_27 ) ;
if ( F_9 ( V_23 == 0 ) ) {
V_28 = F_10 ( & V_27 , & V_29 ) ;
V_28 -> V_34 = sizeof( * V_28 ) ;
V_28 -> V_35 = V_36 ;
V_28 -> V_37 = 0xff ;
F_11 ( & V_27 ) ;
}
F_12 ( V_25 , false ) ;
F_13 ( V_25 ) ;
if ( F_5 ( V_23 != 0 ) ) {
F_14 ( L_21 ) ;
F_15 ( & V_25 ) ;
} else
V_22 -> V_38 = V_25 ;
return V_23 ;
}
static int F_16 ( struct V_21 * V_22 )
{
int V_23 ;
V_23 = F_17 ( V_22 , & V_22 -> V_39 ) ;
if ( F_5 ( V_23 != 0 ) ) {
F_14 ( L_22 ) ;
return V_23 ;
}
F_18 ( V_22 -> V_40 ) ;
if ( V_22 -> V_41 ) {
V_23 = F_19 ( V_22 ) ;
if ( F_5 ( V_23 != 0 ) ) {
F_14 ( L_23
L_24 ) ;
goto V_42;
}
}
V_23 = F_3 ( V_22 ) ;
if ( F_5 ( V_23 != 0 ) )
goto V_43;
return 0 ;
V_43:
if ( V_22 -> V_41 )
F_20 ( V_22 ) ;
V_42:
F_21 ( V_22 -> V_40 ) ;
F_22 ( V_22 , & V_22 -> V_39 ) ;
return V_23 ;
}
static void F_23 ( struct V_21 * V_22 )
{
F_7 ( V_22 -> V_44 != NULL ) ;
F_15 ( & V_22 -> V_38 ) ;
if ( V_22 -> V_41 )
F_20 ( V_22 ) ;
F_21 ( V_22 -> V_40 ) ;
F_22 ( V_22 , & V_22 -> V_39 ) ;
}
int F_24 ( struct V_21 * V_22 ,
bool V_45 )
{
int V_23 = 0 ;
F_25 ( & V_22 -> V_46 ) ;
if ( F_5 ( V_22 -> V_47 ++ == 0 ) ) {
V_23 = F_16 ( V_22 ) ;
if ( F_5 ( V_23 != 0 ) )
-- V_22 -> V_47 ;
} else if ( V_45 ) {
F_26 ( V_22 , V_48 ,
F_27 ( V_22 , V_48 ) &
~ V_49 ) ;
}
F_28 ( & V_22 -> V_46 ) ;
return V_23 ;
}
void F_29 ( struct V_21 * V_22 ,
bool V_50 )
{
T_3 V_51 ;
F_25 ( & V_22 -> V_46 ) ;
if ( F_5 ( -- V_22 -> V_47 == 0 ) )
F_23 ( V_22 ) ;
else if ( V_50 )
F_26 ( V_22 , V_48 ,
F_27 ( V_22 , V_48 ) |
V_49 ) ;
V_51 = ( T_3 ) V_22 -> V_47 ;
F_28 ( & V_22 -> V_46 ) ;
F_7 ( V_51 < 0 ) ;
}
static void F_30 ( struct V_21 * V_22 )
{
T_1 V_52 ;
T_1 V_53 ;
V_52 = F_27 ( V_22 , V_54 ) ;
V_53 = F_27 ( V_22 , V_55 ) ;
V_52 = F_31 ( T_1 , V_52 , V_56 ) ;
V_53 = F_31 ( T_1 , V_53 , V_57 ) ;
if ( V_52 > V_22 -> V_58 ||
V_53 > V_22 -> V_59 ) {
V_52 = V_56 ;
V_53 = V_57 ;
}
V_22 -> V_60 = V_52 ;
V_22 -> V_61 = V_53 ;
}
static int F_32 ( struct V_21 * V_22 )
{
static const char * V_62 [ V_63 ] = {
[ V_64 ] = L_25 ,
[ V_65 ] = L_26 ,
[ V_66 ] = L_27 ,
[ V_67 ] = L_28 } ;
#ifdef F_33
const struct V_68 * V_69 = F_34 ( V_22 -> V_70 -> V_70 ) ;
#ifdef F_35
if ( V_71 ) {
V_22 -> V_72 = V_66 ;
goto V_73;
}
#endif
if ( ! ( V_74 || V_75 ) ) {
V_22 -> V_72 = V_64 ;
F_2 ( L_29 , V_62 [ V_22 -> V_72 ] ) ;
return 0 ;
}
V_22 -> V_72 = V_66 ;
if ( V_69 -> V_76 )
V_22 -> V_72 = V_65 ;
#ifdef F_36
if ( F_37 () == 0 )
V_22 -> V_72 = V_66 ;
#endif
#ifdef F_35
V_73:
#endif
if ( V_22 -> V_72 == V_66 &&
V_77 )
V_22 -> V_72 = V_67 ;
if ( V_75 )
V_22 -> V_72 = V_65 ;
#if ! F_38 ( F_36 ) && ! F_38 ( F_35 )
if ( V_22 -> V_72 == V_65 )
return - V_78 ;
#endif
#else
V_22 -> V_72 = V_66 ;
#endif
F_2 ( L_29 , V_62 [ V_22 -> V_72 ] ) ;
return 0 ;
}
static int F_39 ( struct V_21 * V_22 )
{
struct V_79 * V_70 = V_22 -> V_70 ;
if ( V_71 &&
(sizeof( unsigned long ) == 4 || V_80 ) ) {
F_2 ( L_30 ) ;
return F_40 ( V_70 -> V_70 , F_41 ( 44 ) ) ;
}
return 0 ;
}
static int F_39 ( struct V_21 * V_22 )
{
return 0 ;
}
static int F_42 ( struct V_79 * V_70 , unsigned long V_81 )
{
struct V_21 * V_22 ;
int V_23 ;
T_1 V_82 ;
enum V_83 V_84 ;
bool V_85 = false ;
V_22 = F_43 ( sizeof( * V_22 ) , V_86 ) ;
if ( F_5 ( V_22 == NULL ) ) {
F_14 ( L_31 ) ;
return - V_87 ;
}
F_44 ( V_70 -> V_88 ) ;
V_22 -> V_70 = V_70 ;
V_22 -> V_89 = V_81 ;
V_22 -> V_90 = ( T_1 ) - 100 ;
F_45 ( & V_22 -> V_91 ) ;
F_45 ( & V_22 -> V_46 ) ;
F_45 ( & V_22 -> V_92 ) ;
F_46 ( & V_22 -> V_93 ) ;
F_47 ( & V_22 -> V_94 ) ;
F_48 ( & V_22 -> V_95 ) ;
F_48 ( & V_22 -> V_96 ) ;
F_48 ( & V_22 -> V_97 ) ;
for ( V_84 = V_98 ; V_84 < V_99 ; ++ V_84 ) {
F_49 ( & V_22 -> V_100 [ V_84 ] ) ;
F_50 ( & V_22 -> V_101 [ V_84 ] ) ;
}
F_45 ( & V_22 -> V_102 ) ;
F_51 ( & V_22 -> V_103 ) ;
F_51 ( & V_22 -> V_104 ) ;
V_22 -> V_105 = 0 ;
F_52 ( & V_22 -> V_106 , 0 ) ;
V_22 -> V_107 = 0 ;
V_22 -> V_108 = F_53 ( V_70 -> V_88 , 0 ) ;
V_22 -> V_109 = F_53 ( V_70 -> V_88 , 1 ) ;
V_22 -> V_110 = F_53 ( V_70 -> V_88 , 2 ) ;
V_22 -> V_111 = V_112 ;
F_26 ( V_22 , V_113 , V_114 ) ;
V_82 = F_27 ( V_22 , V_113 ) ;
if ( V_82 != V_114 ) {
V_23 = - V_115 ;
F_14 ( L_32 , V_82 ) ;
goto V_116;
}
V_22 -> V_1 = F_27 ( V_22 , V_117 ) ;
V_23 = F_32 ( V_22 ) ;
if ( F_5 ( V_23 != 0 ) ) {
F_2 ( L_33 ) ;
V_85 = true ;
}
V_22 -> V_118 = F_27 ( V_22 , V_119 ) ;
V_22 -> V_120 = F_27 ( V_22 , V_121 ) ;
V_22 -> V_58 = F_27 ( V_22 , V_122 ) ;
V_22 -> V_59 = F_27 ( V_22 , V_123 ) ;
F_30 ( V_22 ) ;
if ( V_22 -> V_1 & V_16 ) {
V_22 -> V_124 =
F_27 ( V_22 , V_125 ) ;
V_22 -> V_126 =
F_27 ( V_22 , V_127 ) ;
V_22 -> V_128 =
F_27 ( V_22 , V_129 ) ;
V_22 -> V_128 -= V_22 -> V_118 ;
} else {
V_22 -> V_128 = 512 * 1024 * 1024 ;
}
V_22 -> V_130 = 0 ;
V_22 -> V_131 = 0 ;
if ( V_22 -> V_1 & V_20 ) {
T_4 V_132 =
F_27 ( V_22 ,
V_133 ) ;
V_22 -> V_130 = V_132 * 1024 / V_31 ;
V_22 -> V_134 =
F_27 ( V_22 ,
V_135 ) ;
V_22 -> V_131 =
F_27 ( V_22 , V_136 ) ;
} else
V_22 -> V_134 = V_22 -> V_118 ;
V_23 = F_39 ( V_22 ) ;
if ( F_5 ( V_23 != 0 ) )
goto V_116;
if ( V_22 -> V_134 > V_22 -> V_118 )
V_22 -> V_134 = V_22 -> V_118 ;
F_1 ( V_22 -> V_1 ) ;
if ( V_22 -> V_1 & V_16 ) {
F_2 ( L_34 ,
( unsigned ) V_22 -> V_124 ) ;
F_2 ( L_35 ,
( unsigned ) V_22 -> V_126 ) ;
F_2 ( L_36 ,
( unsigned ) V_22 -> V_128 / 1024 ) ;
}
F_2 ( L_37 ,
V_22 -> V_134 / 1024 ) ;
F_2 ( L_38 ,
V_22 -> V_109 , V_22 -> V_118 / 1024 ) ;
F_2 ( L_39 ,
V_22 -> V_110 , V_22 -> V_120 / 1024 ) ;
V_23 = F_54 ( V_22 ) ;
if ( F_5 ( V_23 != 0 ) )
goto V_116;
F_55 ( & V_22 -> V_137 ) ;
F_56 ( & V_22 -> V_137 . V_138 , false , V_139 ) ;
V_22 -> V_140 = & V_22 -> V_137 ;
V_23 = F_57 ( & V_22 -> V_30 ,
V_22 -> V_141 . V_142 . V_143 ,
& V_144 ,
V_70 -> V_145 -> V_146 ,
V_147 ,
false ) ;
if ( F_5 ( V_23 != 0 ) ) {
F_14 ( L_40 ) ;
goto V_148;
}
V_22 -> V_149 = F_58 ( V_22 -> V_110 ,
V_22 -> V_120 ) ;
V_22 -> V_150 = F_59 ( V_22 -> V_110 ,
V_22 -> V_120 ) ;
if ( F_5 ( V_22 -> V_150 == NULL ) ) {
V_23 = - V_87 ;
F_14 ( L_41 ) ;
goto V_151;
}
if ( ! ( V_22 -> V_1 & V_13 ) &&
! ( V_22 -> V_1 & V_11 ) &&
! F_60 ( V_22 ) ) {
V_23 = - V_115 ;
F_14 ( L_42 ) ;
goto V_152;
}
V_22 -> V_153 = F_61
( V_22 -> V_154 . V_143 , 12 , & V_155 ) ;
if ( F_5 ( V_22 -> V_153 == NULL ) ) {
F_14 ( L_43 ) ;
V_23 = - V_87 ;
goto V_152;
}
V_70 -> V_156 = V_22 ;
V_23 = F_62 ( V_70 -> V_88 , L_44 ) ;
V_22 -> V_157 = ( V_23 != 0 ) ;
if ( V_22 -> V_157 ) {
F_2 ( L_45
L_46 ) ;
V_23 = F_63 ( V_70 -> V_88 , 2 , L_47 ) ;
if ( F_5 ( V_23 != 0 ) ) {
F_14 ( L_48 ) ;
goto V_158;
}
}
if ( V_22 -> V_1 & V_12 ) {
V_23 = F_64 ( V_70 , V_70 -> V_88 -> V_159 ) ;
if ( V_23 != 0 ) {
F_14 ( L_49 , V_23 ) ;
goto V_160;
}
}
V_22 -> V_40 = F_65 ( V_22 ) ;
if ( F_5 ( V_22 -> V_40 == NULL ) ) {
V_23 = - V_87 ;
goto V_161;
}
V_23 = F_66 ( & V_22 -> V_30 , V_162 ,
( V_22 -> V_118 >> V_163 ) ) ;
if ( F_5 ( V_23 != 0 ) ) {
F_14 ( L_50 ) ;
goto V_164;
}
V_22 -> V_165 = true ;
if ( ( ( V_22 -> V_1 & ( V_14 | V_16 ) ) == 0 ) ||
V_85 || F_66 ( & V_22 -> V_30 , V_166 ,
V_166 ) != 0 ) {
F_2 ( L_51
L_52 ) ;
V_22 -> V_165 = false ;
}
if ( V_22 -> V_1 & V_20 ) {
V_22 -> V_41 = true ;
if ( F_66 ( & V_22 -> V_30 , V_167 ,
V_167 ) != 0 ) {
F_2 ( L_53
L_54 ) ;
V_22 -> V_41 = false ;
}
}
F_67 ( V_22 ) ;
V_23 = F_68 ( V_22 ) ;
if ( F_5 ( V_23 != 0 ) )
goto V_168;
F_69 ( V_22 ) ;
if ( V_22 -> V_111 ) {
V_23 = F_24 ( V_22 , true ) ;
if ( F_5 ( V_23 != 0 ) )
goto V_169;
F_70 ( V_22 ) ;
}
V_22 -> V_170 . V_171 = V_172 ;
F_71 ( & V_22 -> V_170 ) ;
return 0 ;
V_169:
F_72 ( V_22 ) ;
F_73 ( V_22 ) ;
V_168:
F_74 ( V_22 ) ;
if ( V_22 -> V_41 )
( void ) F_75 ( & V_22 -> V_30 , V_167 ) ;
if ( V_22 -> V_165 )
( void ) F_75 ( & V_22 -> V_30 , V_166 ) ;
( void ) F_75 ( & V_22 -> V_30 , V_162 ) ;
V_164:
F_76 ( V_22 -> V_40 ) ;
V_161:
if ( V_22 -> V_1 & V_12 )
F_77 ( V_22 -> V_70 ) ;
V_160:
if ( V_22 -> V_157 )
F_78 ( V_70 -> V_88 , 2 ) ;
else
F_79 ( V_70 -> V_88 ) ;
V_158:
F_80 ( & V_22 -> V_153 ) ;
V_152:
F_81 ( V_22 -> V_150 ) ;
V_151:
F_82 ( V_22 -> V_149 ) ;
( void ) F_83 ( & V_22 -> V_30 ) ;
V_148:
F_84 ( V_22 ) ;
V_116:
for ( V_84 = V_98 ; V_84 < V_99 ; ++ V_84 )
F_85 ( & V_22 -> V_100 [ V_84 ] ) ;
F_86 ( V_22 ) ;
return V_23 ;
}
static int F_87 ( struct V_79 * V_70 )
{
struct V_21 * V_22 = F_88 ( V_70 ) ;
enum V_83 V_84 ;
F_89 ( & V_22 -> V_170 ) ;
if ( V_22 -> V_173 . V_174 )
F_90 ( & V_22 -> V_173 . V_175 ) ;
F_91 ( V_22 -> V_173 . V_176 ) ;
if ( V_22 -> V_111 ) {
F_92 ( V_22 ) ;
F_74 ( V_22 ) ;
F_29 ( V_22 , false ) ;
}
F_73 ( V_22 ) ;
F_72 ( V_22 ) ;
if ( V_22 -> V_41 )
( void ) F_75 ( & V_22 -> V_30 , V_167 ) ;
if ( V_22 -> V_165 )
( void ) F_75 ( & V_22 -> V_30 , V_166 ) ;
( void ) F_75 ( & V_22 -> V_30 , V_162 ) ;
F_76 ( V_22 -> V_40 ) ;
if ( V_22 -> V_1 & V_12 )
F_77 ( V_22 -> V_70 ) ;
if ( V_22 -> V_157 )
F_78 ( V_70 -> V_88 , 2 ) ;
else
F_79 ( V_70 -> V_88 ) ;
F_80 ( & V_22 -> V_153 ) ;
F_81 ( V_22 -> V_150 ) ;
F_82 ( V_22 -> V_149 ) ;
( void ) F_83 ( & V_22 -> V_30 ) ;
F_84 ( V_22 ) ;
for ( V_84 = V_98 ; V_84 < V_99 ; ++ V_84 )
F_85 ( & V_22 -> V_100 [ V_84 ] ) ;
F_86 ( V_22 ) ;
return 0 ;
}
static void F_93 ( struct V_79 * V_70 ,
struct V_177 * V_178 )
{
struct V_179 * V_180 = V_179 ( V_178 ) ;
struct V_21 * V_22 = F_88 ( V_70 ) ;
F_94 ( V_22 -> V_40 , & V_180 -> V_181 ) ;
}
static void F_95 ( struct V_79 * V_70 ,
struct V_177 * V_178 )
{
struct V_179 * V_180 ;
V_180 = V_179 ( V_178 ) ;
if ( V_180 -> V_182 ) {
struct V_183 * V_184 =
V_183 ( V_180 -> V_182 ) ;
F_56 ( & V_184 -> V_138 , true , V_139 ) ;
F_96 ( & V_184 -> V_138 ) ;
F_97 ( & V_180 -> V_182 ) ;
}
F_98 ( & V_180 -> V_185 ) ;
F_86 ( V_180 ) ;
}
static int F_99 ( struct V_79 * V_70 , struct V_177 * V_178 )
{
struct V_21 * V_22 = F_88 ( V_70 ) ;
struct V_179 * V_180 ;
int V_23 = - V_87 ;
V_180 = F_43 ( sizeof( * V_180 ) , V_86 ) ;
if ( F_5 ( V_180 == NULL ) )
return V_23 ;
F_50 ( & V_180 -> V_181 ) ;
V_180 -> V_185 = F_100 ( V_22 -> V_153 , 10 ) ;
if ( F_5 ( V_180 -> V_185 == NULL ) )
goto V_186;
V_178 -> V_187 = V_180 ;
return 0 ;
V_186:
F_86 ( V_180 ) ;
return V_23 ;
}
static struct V_183 * F_101 ( struct V_79 * V_70 ,
struct V_177 * V_178 ,
unsigned int V_188 )
{
int V_23 ;
struct V_179 * V_180 = V_179 ( V_178 ) ;
struct V_183 * V_184 ;
if ( V_178 -> V_189 -> type != V_190 ||
! ( V_188 & V_191 ) )
return NULL ;
V_23 = F_102 ( & V_70 -> V_192 ) ;
if ( F_5 ( V_23 != 0 ) )
return F_103 ( - V_193 ) ;
if ( V_178 -> V_194 ) {
F_28 ( & V_70 -> V_192 ) ;
return NULL ;
}
if ( V_180 -> V_182 ) {
F_28 ( & V_70 -> V_192 ) ;
F_14 ( L_55
L_56 ) ;
return F_103 ( - V_195 ) ;
}
F_28 ( & V_70 -> V_192 ) ;
if ( ! ( V_188 & V_196 ) ) {
F_14 ( L_57 ) ;
return F_103 ( - V_197 ) ;
}
V_184 = V_183 ( V_178 -> V_198 ) ;
V_23 = F_104 ( & V_184 -> V_138 , true ) ;
if ( F_5 ( V_23 != 0 ) )
V_184 = F_103 ( V_23 ) ;
return V_184 ;
}
static long F_105 ( struct V_199 * V_200 , unsigned int V_201 ,
unsigned long V_202 ,
long (* F_106)( struct V_199 * , unsigned int ,
unsigned long ) )
{
struct V_177 * V_178 = V_200 -> V_203 ;
struct V_79 * V_70 = V_178 -> V_189 -> V_70 ;
unsigned int V_204 = F_107 ( V_201 ) ;
struct V_183 * V_184 ;
unsigned int V_188 ;
long V_23 ;
if ( ( V_204 >= V_205 ) && ( V_204 < V_206 )
&& ( V_204 < V_205 + V_70 -> V_207 -> V_208 ) ) {
const struct V_209 * V_210 =
& V_211 [ V_204 - V_205 ] ;
if ( F_5 ( V_210 -> V_212 != V_201 ) ) {
F_14 ( L_58 ,
V_204 - V_205 ) ;
return - V_78 ;
}
V_188 = V_210 -> V_188 ;
} else if ( ! F_108 ( V_204 , & V_188 ) )
return - V_78 ;
V_184 = F_101 ( V_70 , V_178 , V_188 ) ;
if ( F_5 ( F_109 ( V_184 ) ) ) {
V_23 = F_110 ( V_184 ) ;
if ( V_23 != - V_193 )
F_2 ( L_59 ,
V_204 , V_23 ) ;
return V_23 ;
}
V_23 = F_106 ( V_200 , V_201 , V_202 ) ;
if ( V_184 )
F_111 ( & V_184 -> V_138 ) ;
return V_23 ;
}
static long F_112 ( struct V_199 * V_200 , unsigned int V_201 ,
unsigned long V_202 )
{
return F_105 ( V_200 , V_201 , V_202 , & V_213 ) ;
}
static long F_113 ( struct V_199 * V_200 , unsigned int V_201 ,
unsigned long V_202 )
{
return F_105 ( V_200 , V_201 , V_202 , & V_214 ) ;
}
static void F_114 ( struct V_79 * V_70 )
{
struct V_215 * V_216 ;
struct V_217 V_218 ;
int V_23 ;
V_218 . V_219 = 0 ;
V_218 . V_220 = 0 ;
V_218 . V_221 = NULL ;
V_218 . V_222 = NULL ;
V_218 . V_223 = NULL ;
V_218 . V_224 = 0 ;
F_115 (crtc, &dev->mode_config.crtc_list, head) {
V_218 . V_216 = V_216 ;
V_23 = F_116 ( & V_218 ) ;
F_117 ( V_23 != 0 ) ;
}
}
static void F_55 ( struct V_183 * V_184 )
{
F_47 ( & V_184 -> V_138 ) ;
F_50 ( & V_184 -> V_225 ) ;
F_45 ( & V_184 -> V_226 ) ;
}
static int F_118 ( struct V_79 * V_70 ,
struct V_227 * V_198 )
{
struct V_183 * V_184 ;
V_184 = F_43 ( sizeof( * V_184 ) , V_86 ) ;
if ( F_5 ( V_184 == NULL ) )
return - V_87 ;
F_55 ( V_184 ) ;
F_56 ( & V_184 -> V_138 , true , V_139 ) ;
V_198 -> V_187 = V_184 ;
return 0 ;
}
static void F_119 ( struct V_79 * V_70 ,
struct V_227 * V_198 )
{
struct V_183 * V_184 = V_183 ( V_198 ) ;
V_198 -> V_187 = NULL ;
F_86 ( V_184 ) ;
}
static int F_120 ( struct V_79 * V_70 ,
struct V_177 * V_178 ,
bool V_228 )
{
struct V_21 * V_22 = F_88 ( V_70 ) ;
struct V_179 * V_180 = V_179 ( V_178 ) ;
struct V_183 * V_229 = V_22 -> V_140 ;
struct V_183 * V_184 = V_183 ( V_178 -> V_198 ) ;
int V_23 = 0 ;
if ( ! V_22 -> V_111 ) {
V_23 = F_24 ( V_22 , true ) ;
if ( F_5 ( V_23 != 0 ) )
return V_23 ;
F_67 ( V_22 ) ;
F_26 ( V_22 , V_230 , 0 ) ;
}
if ( V_229 ) {
F_7 ( V_229 != & V_22 -> V_137 ) ;
V_23 = F_121 ( & V_229 -> V_138 , false , V_180 -> V_185 ) ;
if ( F_5 ( V_23 != 0 ) )
goto V_231;
F_56 ( & V_229 -> V_138 , true , V_139 ) ;
V_23 = F_122 ( & V_22 -> V_30 , V_162 ) ;
if ( F_5 ( V_23 != 0 ) ) {
F_14 ( L_60
L_61 ) ;
}
V_22 -> V_140 = NULL ;
}
F_56 ( & V_184 -> V_138 , false , V_139 ) ;
if ( ! V_228 ) {
F_96 ( & V_184 -> V_138 ) ;
F_7 ( V_180 -> V_182 != V_178 -> V_198 ) ;
F_97 ( & V_180 -> V_182 ) ;
}
V_22 -> V_140 = V_184 ;
return 0 ;
V_231:
if ( ! V_22 -> V_111 ) {
F_74 ( V_22 ) ;
F_29 ( V_22 , true ) ;
F_26 ( V_22 , V_230 , 1 ) ;
}
return V_23 ;
}
static void F_123 ( struct V_79 * V_70 ,
struct V_177 * V_178 ,
bool V_232 )
{
struct V_21 * V_22 = F_88 ( V_70 ) ;
struct V_179 * V_180 = V_179 ( V_178 ) ;
struct V_183 * V_184 = V_183 ( V_178 -> V_198 ) ;
int V_23 ;
V_180 -> V_182 = F_124 ( V_178 -> V_198 ) ;
V_23 = F_121 ( & V_184 -> V_138 , false , V_180 -> V_185 ) ;
if ( F_5 ( ( V_23 != 0 ) ) ) {
F_14 ( L_62 ) ;
F_97 ( & V_180 -> V_182 ) ;
}
F_56 ( & V_184 -> V_138 , false , V_139 ) ;
F_125 ( V_22 ) ;
if ( ! V_22 -> V_111 ) {
V_23 = F_122 ( & V_22 -> V_30 , V_162 ) ;
if ( F_5 ( V_23 != 0 ) )
F_14 ( L_63 ) ;
F_74 ( V_22 ) ;
F_29 ( V_22 , true ) ;
F_26 ( V_22 , V_230 , 1 ) ;
}
V_22 -> V_140 = & V_22 -> V_137 ;
F_56 ( & V_22 -> V_137 . V_138 , false , V_139 ) ;
F_96 ( & V_22 -> V_137 . V_138 ) ;
if ( V_22 -> V_111 )
F_126 ( V_22 ) ;
}
static void F_127 ( struct V_233 * V_88 )
{
struct V_79 * V_70 = F_128 ( V_88 ) ;
F_129 ( V_88 ) ;
F_130 ( V_70 ) ;
}
static int V_172 ( struct V_234 * V_235 , unsigned long V_236 ,
void * V_237 )
{
struct V_21 * V_22 =
F_131 ( V_235 , struct V_21 , V_170 ) ;
switch ( V_236 ) {
case V_238 :
case V_239 :
F_132 ( & V_22 -> V_94 ) ;
F_125 ( V_22 ) ;
F_133 ( V_22 ) ;
F_134 ( & V_22 -> V_30 ) ;
break;
case V_240 :
case V_241 :
case V_242 :
F_135 ( & V_22 -> V_94 ) ;
break;
case V_243 :
break;
default:
break;
}
return 0 ;
}
static int F_136 ( struct V_233 * V_88 , T_5 V_35 )
{
struct V_79 * V_70 = F_128 ( V_88 ) ;
struct V_21 * V_22 = F_88 ( V_70 ) ;
if ( V_22 -> V_47 != 0 ) {
F_2 ( L_64
L_65 ) ;
return - V_244 ;
}
F_137 ( V_88 ) ;
F_129 ( V_88 ) ;
F_138 ( V_88 , V_245 ) ;
return 0 ;
}
static int F_139 ( struct V_233 * V_88 )
{
F_138 ( V_88 , V_246 ) ;
F_140 ( V_88 ) ;
return F_141 ( V_88 ) ;
}
static int F_142 ( struct V_247 * V_248 )
{
struct V_233 * V_88 = F_143 ( V_248 ) ;
struct V_249 V_29 ;
V_29 . V_250 = 0 ;
return F_136 ( V_88 , V_29 ) ;
}
static int F_144 ( struct V_247 * V_248 )
{
struct V_233 * V_88 = F_143 ( V_248 ) ;
return F_139 ( V_88 ) ;
}
static int F_145 ( struct V_247 * V_248 )
{
struct V_233 * V_88 = F_143 ( V_248 ) ;
struct V_79 * V_70 = F_128 ( V_88 ) ;
struct V_21 * V_22 = F_88 ( V_70 ) ;
V_22 -> V_251 = true ;
if ( V_22 -> V_111 )
F_29 ( V_22 , true ) ;
if ( V_22 -> V_47 != 0 ) {
F_2 ( L_64
L_65 ) ;
if ( V_22 -> V_111 )
F_24 ( V_22 , true ) ;
V_22 -> V_251 = false ;
return - V_244 ;
}
return 0 ;
}
static void F_146 ( struct V_247 * V_248 )
{
struct V_233 * V_88 = F_143 ( V_248 ) ;
struct V_79 * V_70 = F_128 ( V_88 ) ;
struct V_21 * V_22 = F_88 ( V_70 ) ;
F_26 ( V_22 , V_113 , V_114 ) ;
( void ) F_27 ( V_22 , V_113 ) ;
if ( V_22 -> V_111 )
F_24 ( V_22 , false ) ;
V_22 -> V_251 = false ;
}
static int F_147 ( struct V_233 * V_88 , const struct V_252 * V_253 )
{
return F_148 ( V_88 , V_253 , & V_207 ) ;
}
static int T_6 F_149 ( void )
{
int V_23 ;
V_23 = F_150 ( & V_207 , & V_254 ) ;
if ( V_23 )
F_14 ( L_66 ) ;
return V_23 ;
}
static void T_7 F_151 ( void )
{
F_152 ( & V_207 , & V_254 ) ;
}
