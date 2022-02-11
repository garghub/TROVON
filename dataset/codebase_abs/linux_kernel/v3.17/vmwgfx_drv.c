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
F_25 ( & V_22 -> V_48 ) ;
F_26 ( V_22 , V_49 ,
F_27 ( V_22 , V_49 ) &
~ V_50 ) ;
F_28 ( & V_22 -> V_48 ) ;
}
F_28 ( & V_22 -> V_46 ) ;
return V_23 ;
}
void F_29 ( struct V_21 * V_22 ,
bool V_51 )
{
T_3 V_52 ;
F_25 ( & V_22 -> V_46 ) ;
if ( F_5 ( -- V_22 -> V_47 == 0 ) )
F_23 ( V_22 ) ;
else if ( V_51 ) {
F_25 ( & V_22 -> V_48 ) ;
F_26 ( V_22 , V_49 ,
F_27 ( V_22 , V_49 ) |
V_50 ) ;
F_28 ( & V_22 -> V_48 ) ;
}
V_52 = ( T_3 ) V_22 -> V_47 ;
F_28 ( & V_22 -> V_46 ) ;
F_7 ( V_52 < 0 ) ;
}
static void F_30 ( struct V_21 * V_22 )
{
T_1 V_53 ;
T_1 V_54 ;
V_53 = F_27 ( V_22 , V_55 ) ;
V_54 = F_27 ( V_22 , V_56 ) ;
V_53 = F_31 ( T_1 , V_53 , V_57 ) ;
V_54 = F_31 ( T_1 , V_54 , V_58 ) ;
if ( V_53 > V_22 -> V_59 ||
V_54 > V_22 -> V_60 ) {
V_53 = V_57 ;
V_54 = V_58 ;
}
V_22 -> V_61 = V_53 ;
V_22 -> V_62 = V_54 ;
}
static int F_32 ( struct V_21 * V_22 )
{
static const char * V_63 [ V_64 ] = {
[ V_65 ] = L_25 ,
[ V_66 ] = L_26 ,
[ V_67 ] = L_27 ,
[ V_68 ] = L_28 } ;
#ifdef F_33
const struct V_69 * V_70 = F_34 ( V_22 -> V_71 -> V_71 ) ;
#ifdef F_35
if ( V_72 ) {
V_22 -> V_73 = V_67 ;
goto V_74;
}
#endif
if ( ! ( V_75 || V_76 ) ) {
V_22 -> V_73 = V_65 ;
F_2 ( L_29 , V_63 [ V_22 -> V_73 ] ) ;
return 0 ;
}
V_22 -> V_73 = V_67 ;
if ( V_70 -> V_77 )
V_22 -> V_73 = V_66 ;
#ifdef F_36
if ( F_37 () == 0 )
V_22 -> V_73 = V_67 ;
#endif
#ifdef F_35
V_74:
#endif
if ( V_22 -> V_73 == V_67 &&
V_78 )
V_22 -> V_73 = V_68 ;
if ( V_76 )
V_22 -> V_73 = V_66 ;
#if ! F_38 ( F_36 ) && ! F_38 ( F_35 )
if ( V_22 -> V_73 == V_66 )
return - V_79 ;
#endif
#else
V_22 -> V_73 = V_67 ;
#endif
F_2 ( L_29 , V_63 [ V_22 -> V_73 ] ) ;
return 0 ;
}
static int F_39 ( struct V_21 * V_22 )
{
struct V_80 * V_71 = V_22 -> V_71 ;
if ( V_72 &&
(sizeof( unsigned long ) == 4 || V_81 ) ) {
F_2 ( L_30 ) ;
return F_40 ( V_71 -> V_71 , F_41 ( 44 ) ) ;
}
return 0 ;
}
static int F_39 ( struct V_21 * V_22 )
{
return 0 ;
}
static int F_42 ( struct V_80 * V_71 , unsigned long V_82 )
{
struct V_21 * V_22 ;
int V_23 ;
T_1 V_83 ;
enum V_84 V_85 ;
bool V_86 = false ;
V_22 = F_43 ( sizeof( * V_22 ) , V_87 ) ;
if ( F_5 ( V_22 == NULL ) ) {
F_14 ( L_31 ) ;
return - V_88 ;
}
F_44 ( V_71 -> V_89 ) ;
V_22 -> V_71 = V_71 ;
V_22 -> V_90 = V_82 ;
V_22 -> V_91 = ( T_1 ) - 100 ;
F_45 ( & V_22 -> V_48 ) ;
F_45 ( & V_22 -> V_92 ) ;
F_45 ( & V_22 -> V_46 ) ;
F_45 ( & V_22 -> V_93 ) ;
F_46 ( & V_22 -> V_94 ) ;
F_47 ( & V_22 -> V_95 ) ;
for ( V_85 = V_96 ; V_85 < V_97 ; ++ V_85 ) {
F_48 ( & V_22 -> V_98 [ V_85 ] ) ;
F_49 ( & V_22 -> V_99 [ V_85 ] ) ;
}
F_45 ( & V_22 -> V_100 ) ;
F_50 ( & V_22 -> V_101 ) ;
F_50 ( & V_22 -> V_102 ) ;
V_22 -> V_103 = 0 ;
F_51 ( & V_22 -> V_104 , 0 ) ;
V_22 -> V_105 = 0 ;
V_22 -> V_106 = F_52 ( V_71 -> V_89 , 0 ) ;
V_22 -> V_107 = F_52 ( V_71 -> V_89 , 1 ) ;
V_22 -> V_108 = F_52 ( V_71 -> V_89 , 2 ) ;
V_22 -> V_109 = V_110 ;
F_25 ( & V_22 -> V_48 ) ;
F_26 ( V_22 , V_111 , V_112 ) ;
V_83 = F_27 ( V_22 , V_111 ) ;
if ( V_83 != V_112 ) {
V_23 = - V_113 ;
F_14 ( L_32 , V_83 ) ;
F_28 ( & V_22 -> V_48 ) ;
goto V_114;
}
V_22 -> V_1 = F_27 ( V_22 , V_115 ) ;
V_23 = F_32 ( V_22 ) ;
if ( F_5 ( V_23 != 0 ) ) {
F_2 ( L_33 ) ;
V_86 = true ;
}
V_22 -> V_116 = F_27 ( V_22 , V_117 ) ;
V_22 -> V_118 = F_27 ( V_22 , V_119 ) ;
V_22 -> V_59 = F_27 ( V_22 , V_120 ) ;
V_22 -> V_60 = F_27 ( V_22 , V_121 ) ;
F_30 ( V_22 ) ;
if ( V_22 -> V_1 & V_16 ) {
V_22 -> V_122 =
F_27 ( V_22 , V_123 ) ;
V_22 -> V_124 =
F_27 ( V_22 , V_125 ) ;
V_22 -> V_126 =
F_27 ( V_22 , V_127 ) ;
V_22 -> V_126 -= V_22 -> V_116 ;
} else {
V_22 -> V_126 = 512 * 1024 * 1024 ;
}
V_22 -> V_128 = 0 ;
V_22 -> V_129 = 0 ;
if ( V_22 -> V_1 & V_20 ) {
T_4 V_130 =
F_27 ( V_22 ,
V_131 ) ;
V_22 -> V_128 = V_130 * 1024 / V_31 ;
V_22 -> V_132 =
F_27 ( V_22 ,
V_133 ) ;
V_22 -> V_129 =
F_27 ( V_22 , V_134 ) ;
} else
V_22 -> V_132 = V_22 -> V_116 ;
V_23 = F_39 ( V_22 ) ;
if ( F_5 ( V_23 != 0 ) ) {
F_28 ( & V_22 -> V_48 ) ;
goto V_114;
}
if ( F_5 ( V_22 -> V_132 < V_22 -> V_116 ) )
V_22 -> V_132 = V_22 -> V_116 ;
F_28 ( & V_22 -> V_48 ) ;
F_1 ( V_22 -> V_1 ) ;
if ( V_22 -> V_1 & V_16 ) {
F_2 ( L_34 ,
( unsigned ) V_22 -> V_122 ) ;
F_2 ( L_35 ,
( unsigned ) V_22 -> V_124 ) ;
F_2 ( L_36 ,
( unsigned ) V_22 -> V_126 / 1024 ) ;
}
F_2 ( L_37 ,
V_22 -> V_132 / 1024 ) ;
F_2 ( L_38 ,
V_22 -> V_107 , V_22 -> V_116 / 1024 ) ;
F_2 ( L_39 ,
V_22 -> V_108 , V_22 -> V_118 / 1024 ) ;
V_23 = F_53 ( V_22 ) ;
if ( F_5 ( V_23 != 0 ) )
goto V_114;
F_54 ( & V_22 -> V_135 ) ;
F_55 ( & V_22 -> V_135 . V_136 , false , V_137 ) ;
V_22 -> V_138 = & V_22 -> V_135 ;
V_23 = F_56 ( & V_22 -> V_30 ,
V_22 -> V_139 . V_140 . V_141 ,
& V_142 ,
V_71 -> V_143 -> V_144 ,
V_145 ,
false ) ;
if ( F_5 ( V_23 != 0 ) ) {
F_14 ( L_40 ) ;
goto V_146;
}
V_23 = F_57 ( & V_22 -> V_30 , V_147 ,
( V_22 -> V_116 >> V_148 ) ) ;
if ( F_5 ( V_23 != 0 ) ) {
F_14 ( L_41 ) ;
goto V_149;
}
V_22 -> V_150 = true ;
if ( ( ( V_22 -> V_1 & ( V_14 | V_16 ) ) == 0 ) ||
V_86 || F_57 ( & V_22 -> V_30 , V_151 ,
V_151 ) != 0 ) {
F_2 ( L_42
L_43 ) ;
V_22 -> V_150 = false ;
}
if ( V_22 -> V_1 & V_20 ) {
V_22 -> V_41 = true ;
if ( F_57 ( & V_22 -> V_30 , V_152 ,
V_152 ) != 0 ) {
F_2 ( L_44
L_45 ) ;
V_22 -> V_41 = false ;
}
}
V_22 -> V_153 = F_58 ( V_22 -> V_108 ,
V_22 -> V_118 ) ;
V_22 -> V_154 = F_59 ( V_22 -> V_108 ,
V_22 -> V_118 ) ;
if ( F_5 ( V_22 -> V_154 == NULL ) ) {
V_23 = - V_88 ;
F_14 ( L_46 ) ;
goto V_155;
}
if ( ! ( V_22 -> V_1 & V_13 ) &&
! ( V_22 -> V_1 & V_11 ) &&
! F_60 ( V_22 ) ) {
V_23 = - V_113 ;
F_14 ( L_47 ) ;
goto V_156;
}
V_22 -> V_157 = F_61
( V_22 -> V_158 . V_141 , 12 , & V_159 ) ;
if ( F_5 ( V_22 -> V_157 == NULL ) ) {
F_14 ( L_48 ) ;
V_23 = - V_88 ;
goto V_156;
}
V_71 -> V_160 = V_22 ;
V_23 = F_62 ( V_71 -> V_89 , L_49 ) ;
V_22 -> V_161 = ( V_23 != 0 ) ;
if ( V_22 -> V_161 ) {
F_2 ( L_50
L_51 ) ;
V_23 = F_63 ( V_71 -> V_89 , 2 , L_52 ) ;
if ( F_5 ( V_23 != 0 ) ) {
F_14 ( L_53 ) ;
goto V_162;
}
}
if ( V_22 -> V_1 & V_12 ) {
V_23 = F_64 ( V_71 , V_71 -> V_89 -> V_163 ) ;
if ( V_23 != 0 ) {
F_14 ( L_54 , V_23 ) ;
goto V_164;
}
}
V_22 -> V_40 = F_65 ( V_22 ) ;
if ( F_5 ( V_22 -> V_40 == NULL ) ) {
V_23 = - V_88 ;
goto V_165;
}
F_66 ( V_22 ) ;
V_23 = F_67 ( V_22 ) ;
if ( F_5 ( V_23 != 0 ) )
goto V_166;
F_68 ( V_22 ) ;
if ( V_22 -> V_109 ) {
V_23 = F_24 ( V_22 , true ) ;
if ( F_5 ( V_23 != 0 ) )
goto V_167;
F_69 ( V_22 ) ;
}
V_22 -> V_168 . V_169 = V_170 ;
F_70 ( & V_22 -> V_168 ) ;
return 0 ;
V_167:
F_71 ( V_22 ) ;
F_72 ( V_22 ) ;
V_166:
F_73 ( V_22 ) ;
F_74 ( V_22 -> V_40 ) ;
V_165:
if ( V_22 -> V_1 & V_12 )
F_75 ( V_22 -> V_71 ) ;
V_164:
if ( V_22 -> V_161 )
F_76 ( V_71 -> V_89 , 2 ) ;
else
F_77 ( V_71 -> V_89 ) ;
V_162:
F_78 ( & V_22 -> V_157 ) ;
V_156:
F_79 ( V_22 -> V_154 ) ;
V_155:
F_80 ( V_22 -> V_153 ) ;
if ( V_22 -> V_41 )
( void ) F_81 ( & V_22 -> V_30 , V_152 ) ;
if ( V_22 -> V_150 )
( void ) F_81 ( & V_22 -> V_30 , V_151 ) ;
( void ) F_81 ( & V_22 -> V_30 , V_147 ) ;
V_149:
( void ) F_82 ( & V_22 -> V_30 ) ;
V_146:
F_83 ( V_22 ) ;
V_114:
for ( V_85 = V_96 ; V_85 < V_97 ; ++ V_85 )
F_84 ( & V_22 -> V_98 [ V_85 ] ) ;
F_85 ( V_22 ) ;
return V_23 ;
}
static int F_86 ( struct V_80 * V_71 )
{
struct V_21 * V_22 = F_87 ( V_71 ) ;
enum V_84 V_85 ;
F_88 ( & V_22 -> V_168 ) ;
if ( V_22 -> V_171 . V_172 )
F_89 ( & V_22 -> V_171 . V_173 ) ;
if ( V_22 -> V_171 . V_174 )
F_90 ( V_22 -> V_171 . V_174 ) ;
if ( V_22 -> V_109 ) {
F_91 ( V_22 ) ;
F_73 ( V_22 ) ;
F_29 ( V_22 , false ) ;
}
F_72 ( V_22 ) ;
F_71 ( V_22 ) ;
F_74 ( V_22 -> V_40 ) ;
if ( V_22 -> V_1 & V_12 )
F_75 ( V_22 -> V_71 ) ;
if ( V_22 -> V_161 )
F_76 ( V_71 -> V_89 , 2 ) ;
else
F_77 ( V_71 -> V_89 ) ;
F_78 ( & V_22 -> V_157 ) ;
F_79 ( V_22 -> V_154 ) ;
F_80 ( V_22 -> V_153 ) ;
if ( V_22 -> V_41 )
( void ) F_81 ( & V_22 -> V_30 , V_152 ) ;
if ( V_22 -> V_150 )
( void ) F_81 ( & V_22 -> V_30 , V_151 ) ;
( void ) F_81 ( & V_22 -> V_30 , V_147 ) ;
( void ) F_82 ( & V_22 -> V_30 ) ;
F_83 ( V_22 ) ;
for ( V_85 = V_96 ; V_85 < V_97 ; ++ V_85 )
F_84 ( & V_22 -> V_98 [ V_85 ] ) ;
F_85 ( V_22 ) ;
return 0 ;
}
static void F_92 ( struct V_80 * V_71 ,
struct V_175 * V_176 )
{
struct V_177 * V_178 = V_177 ( V_176 ) ;
struct V_21 * V_22 = F_87 ( V_71 ) ;
F_93 ( V_22 -> V_40 , & V_178 -> V_179 ) ;
}
static void F_94 ( struct V_80 * V_71 ,
struct V_175 * V_176 )
{
struct V_177 * V_178 ;
V_178 = V_177 ( V_176 ) ;
if ( V_178 -> V_180 ) {
struct V_181 * V_182 =
V_181 ( V_178 -> V_180 ) ;
F_55 ( & V_182 -> V_136 , true , V_137 ) ;
F_95 ( & V_182 -> V_136 ) ;
F_96 ( & V_178 -> V_180 ) ;
}
F_97 ( & V_178 -> V_183 ) ;
F_85 ( V_178 ) ;
}
static int F_98 ( struct V_80 * V_71 , struct V_175 * V_176 )
{
struct V_21 * V_22 = F_87 ( V_71 ) ;
struct V_177 * V_178 ;
int V_23 = - V_88 ;
V_178 = F_43 ( sizeof( * V_178 ) , V_87 ) ;
if ( F_5 ( V_178 == NULL ) )
return V_23 ;
F_49 ( & V_178 -> V_179 ) ;
V_178 -> V_183 = F_99 ( V_22 -> V_157 , 10 ) ;
if ( F_5 ( V_178 -> V_183 == NULL ) )
goto V_184;
V_176 -> V_185 = V_178 ;
return 0 ;
V_184:
F_85 ( V_178 ) ;
return V_23 ;
}
static struct V_181 * F_100 ( struct V_80 * V_71 ,
struct V_175 * V_176 ,
unsigned int V_186 )
{
int V_23 ;
struct V_177 * V_178 = V_177 ( V_176 ) ;
struct V_181 * V_182 ;
if ( V_176 -> V_187 -> type != V_188 ||
! ( V_186 & V_189 ) )
return NULL ;
V_23 = F_101 ( & V_71 -> V_190 ) ;
if ( F_5 ( V_23 != 0 ) )
return F_102 ( - V_191 ) ;
if ( V_176 -> V_192 ) {
F_28 ( & V_71 -> V_190 ) ;
return NULL ;
}
if ( V_178 -> V_180 ) {
F_28 ( & V_71 -> V_190 ) ;
F_14 ( L_55
L_56 ) ;
return F_102 ( - V_193 ) ;
}
F_28 ( & V_71 -> V_190 ) ;
if ( ! ( V_186 & V_194 ) ) {
F_14 ( L_57 ) ;
return F_102 ( - V_195 ) ;
}
V_182 = V_181 ( V_176 -> V_196 ) ;
V_23 = F_103 ( & V_182 -> V_136 , true ) ;
if ( F_5 ( V_23 != 0 ) )
V_182 = F_102 ( V_23 ) ;
return V_182 ;
}
static long F_104 ( struct V_197 * V_198 , unsigned int V_199 ,
unsigned long V_200 ,
long (* F_105)( struct V_197 * , unsigned int ,
unsigned long ) )
{
struct V_175 * V_176 = V_198 -> V_201 ;
struct V_80 * V_71 = V_176 -> V_187 -> V_71 ;
unsigned int V_202 = F_106 ( V_199 ) ;
struct V_181 * V_182 ;
unsigned int V_186 ;
long V_23 ;
if ( ( V_202 >= V_203 ) && ( V_202 < V_204 )
&& ( V_202 < V_203 + V_71 -> V_205 -> V_206 ) ) {
const struct V_207 * V_208 =
& V_209 [ V_202 - V_203 ] ;
if ( F_5 ( V_208 -> V_210 != V_199 ) ) {
F_14 ( L_58 ,
V_202 - V_203 ) ;
return - V_79 ;
}
V_186 = V_208 -> V_186 ;
} else if ( ! F_107 ( V_202 , & V_186 ) )
return - V_79 ;
V_182 = F_100 ( V_71 , V_176 , V_186 ) ;
if ( F_5 ( F_108 ( V_182 ) ) ) {
F_2 ( L_59 , V_202 ) ;
return F_109 ( V_182 ) ;
}
V_23 = F_105 ( V_198 , V_199 , V_200 ) ;
if ( V_182 )
F_110 ( & V_182 -> V_136 ) ;
return V_23 ;
}
static long F_111 ( struct V_197 * V_198 , unsigned int V_199 ,
unsigned long V_200 )
{
return F_104 ( V_198 , V_199 , V_200 , & V_211 ) ;
}
static long F_112 ( struct V_197 * V_198 , unsigned int V_199 ,
unsigned long V_200 )
{
return F_104 ( V_198 , V_199 , V_200 , & V_212 ) ;
}
static void F_113 ( struct V_80 * V_71 )
{
struct V_213 * V_214 ;
struct V_215 V_216 ;
int V_23 ;
V_216 . V_217 = 0 ;
V_216 . V_218 = 0 ;
V_216 . V_219 = NULL ;
V_216 . V_220 = NULL ;
V_216 . V_221 = NULL ;
V_216 . V_222 = 0 ;
F_114 (crtc, &dev->mode_config.crtc_list, head) {
V_216 . V_214 = V_214 ;
V_23 = F_115 ( & V_216 ) ;
F_116 ( V_23 != 0 ) ;
}
}
static void F_54 ( struct V_181 * V_182 )
{
F_47 ( & V_182 -> V_136 ) ;
F_49 ( & V_182 -> V_223 ) ;
F_45 ( & V_182 -> V_224 ) ;
}
static int F_117 ( struct V_80 * V_71 ,
struct V_225 * V_196 )
{
struct V_181 * V_182 ;
V_182 = F_43 ( sizeof( * V_182 ) , V_87 ) ;
if ( F_5 ( V_182 == NULL ) )
return - V_88 ;
F_54 ( V_182 ) ;
F_55 ( & V_182 -> V_136 , true , V_137 ) ;
V_196 -> V_185 = V_182 ;
return 0 ;
}
static void F_118 ( struct V_80 * V_71 ,
struct V_225 * V_196 )
{
struct V_181 * V_182 = V_181 ( V_196 ) ;
V_196 -> V_185 = NULL ;
F_85 ( V_182 ) ;
}
static int F_119 ( struct V_80 * V_71 ,
struct V_175 * V_176 ,
bool V_226 )
{
struct V_21 * V_22 = F_87 ( V_71 ) ;
struct V_177 * V_178 = V_177 ( V_176 ) ;
struct V_181 * V_227 = V_22 -> V_138 ;
struct V_181 * V_182 = V_181 ( V_176 -> V_196 ) ;
int V_23 = 0 ;
if ( ! V_22 -> V_109 ) {
V_23 = F_24 ( V_22 , true ) ;
if ( F_5 ( V_23 != 0 ) )
return V_23 ;
F_66 ( V_22 ) ;
F_25 ( & V_22 -> V_48 ) ;
F_26 ( V_22 , V_228 , 0 ) ;
F_28 ( & V_22 -> V_48 ) ;
}
if ( V_227 ) {
F_7 ( V_227 != & V_22 -> V_135 ) ;
V_23 = F_120 ( & V_227 -> V_136 , false , V_178 -> V_183 ) ;
if ( F_5 ( V_23 != 0 ) )
goto V_229;
F_55 ( & V_227 -> V_136 , true , V_137 ) ;
V_23 = F_121 ( & V_22 -> V_30 , V_147 ) ;
if ( F_5 ( V_23 != 0 ) ) {
F_14 ( L_60
L_61 ) ;
}
V_22 -> V_138 = NULL ;
}
F_55 ( & V_182 -> V_136 , false , V_137 ) ;
if ( ! V_226 ) {
F_95 ( & V_182 -> V_136 ) ;
F_7 ( V_178 -> V_180 != V_176 -> V_196 ) ;
F_96 ( & V_178 -> V_180 ) ;
}
V_22 -> V_138 = V_182 ;
return 0 ;
V_229:
if ( ! V_22 -> V_109 ) {
F_73 ( V_22 ) ;
F_29 ( V_22 , true ) ;
F_25 ( & V_22 -> V_48 ) ;
F_26 ( V_22 , V_228 , 1 ) ;
F_28 ( & V_22 -> V_48 ) ;
}
return V_23 ;
}
static void F_122 ( struct V_80 * V_71 ,
struct V_175 * V_176 ,
bool V_230 )
{
struct V_21 * V_22 = F_87 ( V_71 ) ;
struct V_177 * V_178 = V_177 ( V_176 ) ;
struct V_181 * V_182 = V_181 ( V_176 -> V_196 ) ;
int V_23 ;
V_178 -> V_180 = F_123 ( V_176 -> V_196 ) ;
V_23 = F_120 ( & V_182 -> V_136 , false , V_178 -> V_183 ) ;
if ( F_5 ( ( V_23 != 0 ) ) ) {
F_14 ( L_62 ) ;
F_96 ( & V_178 -> V_180 ) ;
}
F_55 ( & V_182 -> V_136 , false , V_137 ) ;
F_124 ( V_22 ) ;
if ( ! V_22 -> V_109 ) {
V_23 = F_121 ( & V_22 -> V_30 , V_147 ) ;
if ( F_5 ( V_23 != 0 ) )
F_14 ( L_63 ) ;
F_73 ( V_22 ) ;
F_29 ( V_22 , true ) ;
F_25 ( & V_22 -> V_48 ) ;
F_26 ( V_22 , V_228 , 1 ) ;
F_28 ( & V_22 -> V_48 ) ;
}
V_22 -> V_138 = & V_22 -> V_135 ;
F_55 ( & V_22 -> V_135 . V_136 , false , V_137 ) ;
F_95 ( & V_22 -> V_135 . V_136 ) ;
if ( V_22 -> V_109 )
F_125 ( V_22 ) ;
}
static void F_126 ( struct V_231 * V_89 )
{
struct V_80 * V_71 = F_127 ( V_89 ) ;
F_128 ( V_71 ) ;
}
static int V_170 ( struct V_232 * V_233 , unsigned long V_234 ,
void * V_235 )
{
struct V_21 * V_22 =
F_129 ( V_233 , struct V_21 , V_168 ) ;
switch ( V_234 ) {
case V_236 :
case V_237 :
F_130 ( & V_22 -> V_95 ) ;
F_124 ( V_22 ) ;
F_131 ( V_22 ) ;
F_132 ( & V_22 -> V_30 ) ;
break;
case V_238 :
case V_239 :
case V_240 :
F_133 ( & V_22 -> V_95 ) ;
break;
case V_241 :
break;
default:
break;
}
return 0 ;
}
static int F_134 ( struct V_231 * V_89 , T_5 V_35 )
{
struct V_80 * V_71 = F_127 ( V_89 ) ;
struct V_21 * V_22 = F_87 ( V_71 ) ;
if ( V_22 -> V_47 != 0 ) {
F_2 ( L_64
L_65 ) ;
return - V_242 ;
}
F_135 ( V_89 ) ;
F_136 ( V_89 ) ;
F_137 ( V_89 , V_243 ) ;
return 0 ;
}
static int F_138 ( struct V_231 * V_89 )
{
F_137 ( V_89 , V_244 ) ;
F_139 ( V_89 ) ;
return F_140 ( V_89 ) ;
}
static int F_141 ( struct V_245 * V_246 )
{
struct V_231 * V_89 = F_142 ( V_246 ) ;
struct V_247 V_29 ;
V_29 . V_248 = 0 ;
return F_134 ( V_89 , V_29 ) ;
}
static int F_143 ( struct V_245 * V_246 )
{
struct V_231 * V_89 = F_142 ( V_246 ) ;
return F_138 ( V_89 ) ;
}
static int F_144 ( struct V_245 * V_246 )
{
struct V_231 * V_89 = F_142 ( V_246 ) ;
struct V_80 * V_71 = F_127 ( V_89 ) ;
struct V_21 * V_22 = F_87 ( V_71 ) ;
V_22 -> V_249 = true ;
if ( V_22 -> V_109 )
F_29 ( V_22 , true ) ;
if ( V_22 -> V_47 != 0 ) {
F_2 ( L_64
L_65 ) ;
if ( V_22 -> V_109 )
F_24 ( V_22 , true ) ;
V_22 -> V_249 = false ;
return - V_242 ;
}
return 0 ;
}
static void F_145 ( struct V_245 * V_246 )
{
struct V_231 * V_89 = F_142 ( V_246 ) ;
struct V_80 * V_71 = F_127 ( V_89 ) ;
struct V_21 * V_22 = F_87 ( V_71 ) ;
F_25 ( & V_22 -> V_48 ) ;
F_26 ( V_22 , V_111 , V_112 ) ;
( void ) F_27 ( V_22 , V_111 ) ;
F_28 ( & V_22 -> V_48 ) ;
if ( V_22 -> V_109 )
F_24 ( V_22 , false ) ;
V_22 -> V_249 = false ;
}
static int F_146 ( struct V_231 * V_89 , const struct V_250 * V_251 )
{
return F_147 ( V_89 , V_251 , & V_205 ) ;
}
static int T_6 F_148 ( void )
{
int V_23 ;
V_23 = F_149 ( & V_205 , & V_252 ) ;
if ( V_23 )
F_14 ( L_66 ) ;
return V_23 ;
}
static void T_7 F_150 ( void )
{
F_151 ( & V_205 , & V_252 ) ;
}
