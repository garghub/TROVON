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
V_23 = F_6 ( V_25 , false , true , false , 0 ) ;
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
for ( V_85 = V_95 ; V_85 < V_96 ; ++ V_85 ) {
F_47 ( & V_22 -> V_97 [ V_85 ] ) ;
F_48 ( & V_22 -> V_98 [ V_85 ] ) ;
}
F_45 ( & V_22 -> V_99 ) ;
F_49 ( & V_22 -> V_100 ) ;
F_49 ( & V_22 -> V_101 ) ;
V_22 -> V_102 = 0 ;
F_50 ( & V_22 -> V_103 , 0 ) ;
V_22 -> V_104 = 0 ;
V_22 -> V_105 = F_51 ( V_71 -> V_89 , 0 ) ;
V_22 -> V_106 = F_51 ( V_71 -> V_89 , 1 ) ;
V_22 -> V_107 = F_51 ( V_71 -> V_89 , 2 ) ;
V_22 -> V_108 = V_109 ;
F_25 ( & V_22 -> V_48 ) ;
F_26 ( V_22 , V_110 , V_111 ) ;
V_83 = F_27 ( V_22 , V_110 ) ;
if ( V_83 != V_111 ) {
V_23 = - V_112 ;
F_14 ( L_32 , V_83 ) ;
F_28 ( & V_22 -> V_48 ) ;
goto V_113;
}
V_22 -> V_1 = F_27 ( V_22 , V_114 ) ;
V_23 = F_32 ( V_22 ) ;
if ( F_5 ( V_23 != 0 ) ) {
F_2 ( L_33 ) ;
V_86 = true ;
}
V_22 -> V_115 = F_27 ( V_22 , V_116 ) ;
V_22 -> V_117 = F_27 ( V_22 , V_118 ) ;
V_22 -> V_59 = F_27 ( V_22 , V_119 ) ;
V_22 -> V_60 = F_27 ( V_22 , V_120 ) ;
F_30 ( V_22 ) ;
if ( V_22 -> V_1 & V_16 ) {
V_22 -> V_121 =
F_27 ( V_22 , V_122 ) ;
V_22 -> V_123 =
F_27 ( V_22 , V_124 ) ;
V_22 -> V_125 =
F_27 ( V_22 , V_126 ) ;
V_22 -> V_125 -= V_22 -> V_115 ;
} else {
V_22 -> V_125 = 512 * 1024 * 1024 ;
}
V_22 -> V_127 = 0 ;
V_22 -> V_128 = 0 ;
if ( V_22 -> V_1 & V_20 ) {
T_4 V_129 =
F_27 ( V_22 ,
V_130 ) ;
V_22 -> V_127 = V_129 * 1024 / V_31 ;
V_22 -> V_131 =
F_27 ( V_22 ,
V_132 ) ;
V_22 -> V_128 =
F_27 ( V_22 , V_133 ) ;
} else
V_22 -> V_131 = V_22 -> V_115 ;
V_23 = F_39 ( V_22 ) ;
if ( F_5 ( V_23 != 0 ) ) {
F_28 ( & V_22 -> V_48 ) ;
goto V_113;
}
if ( F_5 ( V_22 -> V_131 < V_22 -> V_115 ) )
V_22 -> V_131 = V_22 -> V_115 ;
F_28 ( & V_22 -> V_48 ) ;
F_1 ( V_22 -> V_1 ) ;
if ( V_22 -> V_1 & V_16 ) {
F_2 ( L_34 ,
( unsigned ) V_22 -> V_121 ) ;
F_2 ( L_35 ,
( unsigned ) V_22 -> V_123 ) ;
F_2 ( L_36 ,
( unsigned ) V_22 -> V_125 / 1024 ) ;
}
F_2 ( L_37 ,
V_22 -> V_131 / 1024 ) ;
F_2 ( L_38 ,
V_22 -> V_106 , V_22 -> V_115 / 1024 ) ;
F_2 ( L_39 ,
V_22 -> V_107 , V_22 -> V_117 / 1024 ) ;
V_23 = F_52 ( V_22 ) ;
if ( F_5 ( V_23 != 0 ) )
goto V_113;
F_53 ( & V_22 -> V_134 ) ;
F_54 ( & V_22 -> V_134 . V_135 , false , V_136 ) ;
V_22 -> V_137 = & V_22 -> V_134 ;
V_23 = F_55 ( & V_22 -> V_30 ,
V_22 -> V_138 . V_139 . V_140 ,
& V_141 , V_142 ,
false ) ;
if ( F_5 ( V_23 != 0 ) ) {
F_14 ( L_40 ) ;
goto V_143;
}
V_23 = F_56 ( & V_22 -> V_30 , V_144 ,
( V_22 -> V_115 >> V_145 ) ) ;
if ( F_5 ( V_23 != 0 ) ) {
F_14 ( L_41 ) ;
goto V_146;
}
V_22 -> V_147 = true ;
if ( ( ( V_22 -> V_1 & ( V_14 | V_16 ) ) == 0 ) ||
V_86 || F_56 ( & V_22 -> V_30 , V_148 ,
V_148 ) != 0 ) {
F_2 ( L_42
L_43 ) ;
V_22 -> V_147 = false ;
}
if ( V_22 -> V_1 & V_20 ) {
V_22 -> V_41 = true ;
if ( F_56 ( & V_22 -> V_30 , V_149 ,
V_149 ) != 0 ) {
F_2 ( L_44
L_45 ) ;
V_22 -> V_41 = false ;
}
}
V_22 -> V_150 = F_57 ( V_22 -> V_107 ,
V_22 -> V_117 ) ;
V_22 -> V_151 = F_58 ( V_22 -> V_107 ,
V_22 -> V_117 ) ;
if ( F_5 ( V_22 -> V_151 == NULL ) ) {
V_23 = - V_88 ;
F_14 ( L_46 ) ;
goto V_152;
}
if ( ! ( V_22 -> V_1 & V_13 ) &&
! ( V_22 -> V_1 & V_11 ) &&
! F_59 ( V_22 ) ) {
V_23 = - V_112 ;
F_14 ( L_47 ) ;
goto V_153;
}
V_22 -> V_154 = F_60
( V_22 -> V_155 . V_140 , 12 , & V_156 ) ;
if ( F_5 ( V_22 -> V_154 == NULL ) ) {
F_14 ( L_48 ) ;
V_23 = - V_88 ;
goto V_153;
}
V_71 -> V_157 = V_22 ;
V_23 = F_61 ( V_71 -> V_89 , L_49 ) ;
V_22 -> V_158 = ( V_23 != 0 ) ;
if ( V_22 -> V_158 ) {
F_2 ( L_50
L_51 ) ;
V_23 = F_62 ( V_71 -> V_89 , 2 , L_52 ) ;
if ( F_5 ( V_23 != 0 ) ) {
F_14 ( L_53 ) ;
goto V_159;
}
}
if ( V_22 -> V_1 & V_12 ) {
V_23 = F_63 ( V_71 ) ;
if ( V_23 != 0 ) {
F_14 ( L_54 , V_23 ) ;
goto V_160;
}
}
V_22 -> V_40 = F_64 ( V_22 ) ;
if ( F_5 ( V_22 -> V_40 == NULL ) ) {
V_23 = - V_88 ;
goto V_161;
}
F_65 ( V_22 ) ;
V_23 = F_66 ( V_22 ) ;
if ( F_5 ( V_23 != 0 ) )
goto V_162;
F_67 ( V_22 ) ;
if ( V_22 -> V_108 ) {
V_23 = F_24 ( V_22 , true ) ;
if ( F_5 ( V_23 != 0 ) )
goto V_163;
F_68 ( V_22 ) ;
}
V_22 -> V_164 . V_165 = V_166 ;
F_69 ( & V_22 -> V_164 ) ;
return 0 ;
V_163:
F_70 ( V_22 ) ;
F_71 ( V_22 ) ;
V_162:
F_72 ( V_22 ) ;
F_73 ( V_22 -> V_40 ) ;
V_161:
if ( V_22 -> V_1 & V_12 )
F_74 ( V_22 -> V_71 ) ;
V_160:
if ( V_22 -> V_158 )
F_75 ( V_71 -> V_89 , 2 ) ;
else
F_76 ( V_71 -> V_89 ) ;
V_159:
F_77 ( & V_22 -> V_154 ) ;
V_153:
F_78 ( V_22 -> V_151 ) ;
V_152:
F_79 ( V_22 -> V_150 ) ;
if ( V_22 -> V_41 )
( void ) F_80 ( & V_22 -> V_30 , V_149 ) ;
if ( V_22 -> V_147 )
( void ) F_80 ( & V_22 -> V_30 , V_148 ) ;
( void ) F_80 ( & V_22 -> V_30 , V_144 ) ;
V_146:
( void ) F_81 ( & V_22 -> V_30 ) ;
V_143:
F_82 ( V_22 ) ;
V_113:
for ( V_85 = V_95 ; V_85 < V_96 ; ++ V_85 )
F_83 ( & V_22 -> V_97 [ V_85 ] ) ;
F_84 ( V_22 ) ;
return V_23 ;
}
static int F_85 ( struct V_80 * V_71 )
{
struct V_21 * V_22 = F_86 ( V_71 ) ;
enum V_84 V_85 ;
F_87 ( & V_22 -> V_164 ) ;
if ( V_22 -> V_167 . V_168 )
F_88 ( & V_22 -> V_167 . V_169 ) ;
if ( V_22 -> V_167 . V_170 )
F_89 ( V_22 -> V_167 . V_170 ) ;
if ( V_22 -> V_108 ) {
F_90 ( V_22 ) ;
F_72 ( V_22 ) ;
F_29 ( V_22 , false ) ;
}
F_71 ( V_22 ) ;
F_70 ( V_22 ) ;
F_73 ( V_22 -> V_40 ) ;
if ( V_22 -> V_1 & V_12 )
F_74 ( V_22 -> V_71 ) ;
if ( V_22 -> V_158 )
F_75 ( V_71 -> V_89 , 2 ) ;
else
F_76 ( V_71 -> V_89 ) ;
F_77 ( & V_22 -> V_154 ) ;
F_78 ( V_22 -> V_151 ) ;
F_79 ( V_22 -> V_150 ) ;
if ( V_22 -> V_41 )
( void ) F_80 ( & V_22 -> V_30 , V_149 ) ;
if ( V_22 -> V_147 )
( void ) F_80 ( & V_22 -> V_30 , V_148 ) ;
( void ) F_80 ( & V_22 -> V_30 , V_144 ) ;
( void ) F_81 ( & V_22 -> V_30 ) ;
F_82 ( V_22 ) ;
for ( V_85 = V_95 ; V_85 < V_96 ; ++ V_85 )
F_83 ( & V_22 -> V_97 [ V_85 ] ) ;
F_84 ( V_22 ) ;
return 0 ;
}
static void F_91 ( struct V_80 * V_71 ,
struct V_171 * V_172 )
{
struct V_173 * V_174 = V_173 ( V_172 ) ;
struct V_21 * V_22 = F_86 ( V_71 ) ;
F_92 ( V_22 -> V_40 , & V_174 -> V_175 ) ;
}
static void F_93 ( struct V_80 * V_71 ,
struct V_171 * V_172 )
{
struct V_173 * V_174 ;
V_174 = V_173 ( V_172 ) ;
if ( V_174 -> V_176 ) {
struct V_177 * V_178 =
V_177 ( V_174 -> V_176 ) ;
F_54 ( & V_178 -> V_135 , true , V_136 ) ;
F_94 ( & V_178 -> V_135 ) ;
F_95 ( & V_174 -> V_176 ) ;
}
F_96 ( V_174 -> V_179 ) ;
F_97 ( & V_174 -> V_180 ) ;
F_84 ( V_174 ) ;
}
static int F_98 ( struct V_80 * V_71 , struct V_171 * V_172 )
{
struct V_21 * V_22 = F_86 ( V_71 ) ;
struct V_173 * V_174 ;
int V_23 = - V_88 ;
V_174 = F_43 ( sizeof( * V_174 ) , V_87 ) ;
if ( F_5 ( V_174 == NULL ) )
return V_23 ;
F_48 ( & V_174 -> V_175 ) ;
V_174 -> V_180 = F_99 ( V_22 -> V_154 , 10 ) ;
if ( F_5 ( V_174 -> V_180 == NULL ) )
goto V_181;
V_174 -> V_179 = F_100 ( V_22 ) ;
if ( F_101 ( V_174 -> V_179 ) )
goto V_182;
V_172 -> V_183 = V_174 ;
V_22 -> V_30 . V_184 = V_71 -> V_184 ;
return 0 ;
V_182:
F_97 ( & V_174 -> V_180 ) ;
V_181:
F_84 ( V_174 ) ;
return V_23 ;
}
static long F_102 ( struct V_185 * V_186 , unsigned int V_187 ,
unsigned long V_188 )
{
struct V_171 * V_172 = V_186 -> V_189 ;
struct V_80 * V_71 = V_172 -> V_190 -> V_71 ;
unsigned int V_191 = F_103 ( V_187 ) ;
if ( ( V_191 >= V_192 ) && ( V_191 < V_193 )
&& ( V_191 < V_192 + V_71 -> V_194 -> V_195 ) ) {
const struct V_196 * V_197 =
& V_198 [ V_191 - V_192 ] ;
if ( F_5 ( V_197 -> V_199 != V_187 ) ) {
F_14 ( L_55 ,
V_191 - V_192 ) ;
return - V_79 ;
}
}
return F_104 ( V_186 , V_187 , V_188 ) ;
}
static void F_105 ( struct V_80 * V_71 )
{
struct V_200 * V_201 ;
struct V_202 V_203 ;
int V_23 ;
V_203 . V_204 = 0 ;
V_203 . V_205 = 0 ;
V_203 . V_206 = NULL ;
V_203 . V_207 = NULL ;
V_203 . V_208 = NULL ;
V_203 . V_209 = 0 ;
F_106 (crtc, &dev->mode_config.crtc_list, head) {
V_203 . V_201 = V_201 ;
V_23 = F_107 ( & V_203 ) ;
F_108 ( V_23 != 0 ) ;
}
}
static void F_53 ( struct V_177 * V_178 )
{
F_109 ( & V_178 -> V_135 ) ;
F_48 ( & V_178 -> V_210 ) ;
F_45 ( & V_178 -> V_211 ) ;
}
static int F_110 ( struct V_80 * V_71 ,
struct V_212 * V_213 )
{
struct V_177 * V_178 ;
V_178 = F_43 ( sizeof( * V_178 ) , V_87 ) ;
if ( F_5 ( V_178 == NULL ) )
return - V_88 ;
F_53 ( V_178 ) ;
F_54 ( & V_178 -> V_135 , true , V_136 ) ;
V_213 -> V_183 = V_178 ;
return 0 ;
}
static void F_111 ( struct V_80 * V_71 ,
struct V_212 * V_213 )
{
struct V_177 * V_178 = V_177 ( V_213 ) ;
V_213 -> V_183 = NULL ;
F_84 ( V_178 ) ;
}
static int F_112 ( struct V_80 * V_71 ,
struct V_171 * V_172 ,
bool V_214 )
{
struct V_21 * V_22 = F_86 ( V_71 ) ;
struct V_173 * V_174 = V_173 ( V_172 ) ;
struct V_177 * V_215 = V_22 -> V_137 ;
struct V_177 * V_178 = V_177 ( V_172 -> V_213 ) ;
int V_23 = 0 ;
if ( ! V_22 -> V_108 ) {
V_23 = F_24 ( V_22 , true ) ;
if ( F_5 ( V_23 != 0 ) )
return V_23 ;
F_65 ( V_22 ) ;
F_25 ( & V_22 -> V_48 ) ;
F_26 ( V_22 , V_216 , 0 ) ;
F_28 ( & V_22 -> V_48 ) ;
}
if ( V_215 ) {
F_7 ( V_215 != & V_22 -> V_134 ) ;
V_23 = F_113 ( & V_215 -> V_135 , false , V_174 -> V_180 ) ;
if ( F_5 ( V_23 != 0 ) )
goto V_217;
F_54 ( & V_215 -> V_135 , true , V_136 ) ;
V_23 = F_114 ( & V_22 -> V_30 , V_144 ) ;
if ( F_5 ( V_23 != 0 ) ) {
F_14 ( L_56
L_57 ) ;
}
V_22 -> V_137 = NULL ;
}
F_54 ( & V_178 -> V_135 , false , V_136 ) ;
if ( ! V_214 ) {
F_94 ( & V_178 -> V_135 ) ;
F_7 ( V_174 -> V_176 != V_172 -> V_213 ) ;
F_95 ( & V_174 -> V_176 ) ;
}
V_22 -> V_137 = V_178 ;
return 0 ;
V_217:
if ( ! V_22 -> V_108 ) {
F_72 ( V_22 ) ;
F_29 ( V_22 , true ) ;
F_25 ( & V_22 -> V_48 ) ;
F_26 ( V_22 , V_216 , 1 ) ;
F_28 ( & V_22 -> V_48 ) ;
}
return V_23 ;
}
static void F_115 ( struct V_80 * V_71 ,
struct V_171 * V_172 ,
bool V_218 )
{
struct V_21 * V_22 = F_86 ( V_71 ) ;
struct V_173 * V_174 = V_173 ( V_172 ) ;
struct V_177 * V_178 = V_177 ( V_172 -> V_213 ) ;
int V_23 ;
V_174 -> V_176 = F_116 ( V_172 -> V_213 ) ;
V_23 = F_113 ( & V_178 -> V_135 , false , V_174 -> V_180 ) ;
if ( F_5 ( ( V_23 != 0 ) ) ) {
F_14 ( L_58 ) ;
F_95 ( & V_174 -> V_176 ) ;
}
F_54 ( & V_178 -> V_135 , false , V_136 ) ;
F_117 ( V_22 ) ;
if ( ! V_22 -> V_108 ) {
V_23 = F_114 ( & V_22 -> V_30 , V_144 ) ;
if ( F_5 ( V_23 != 0 ) )
F_14 ( L_59 ) ;
F_72 ( V_22 ) ;
F_29 ( V_22 , true ) ;
F_25 ( & V_22 -> V_48 ) ;
F_26 ( V_22 , V_216 , 1 ) ;
F_28 ( & V_22 -> V_48 ) ;
}
V_22 -> V_137 = & V_22 -> V_134 ;
F_54 ( & V_22 -> V_134 . V_135 , false , V_136 ) ;
F_94 ( & V_22 -> V_134 . V_135 ) ;
if ( V_22 -> V_108 )
F_118 ( V_22 ) ;
}
static void F_119 ( struct V_219 * V_89 )
{
struct V_80 * V_71 = F_120 ( V_89 ) ;
F_121 ( V_71 ) ;
}
static int V_166 ( struct V_220 * V_221 , unsigned long V_222 ,
void * V_223 )
{
struct V_21 * V_22 =
F_122 ( V_221 , struct V_21 , V_164 ) ;
struct V_177 * V_178 = V_22 -> V_137 ;
switch ( V_222 ) {
case V_224 :
case V_225 :
F_123 ( & V_178 -> V_135 ) ;
F_117 ( V_22 ) ;
F_124 ( V_22 ) ;
F_125 ( & V_22 -> V_30 ) ;
break;
case V_226 :
case V_227 :
case V_228 :
F_126 ( & V_178 -> V_135 ) ;
break;
case V_229 :
break;
default:
break;
}
return 0 ;
}
static int F_127 ( struct V_219 * V_89 , T_5 V_35 )
{
struct V_80 * V_71 = F_120 ( V_89 ) ;
struct V_21 * V_22 = F_86 ( V_71 ) ;
if ( V_22 -> V_47 != 0 ) {
F_2 ( L_60
L_61 ) ;
return - V_230 ;
}
F_128 ( V_89 ) ;
F_129 ( V_89 ) ;
F_130 ( V_89 , V_231 ) ;
return 0 ;
}
static int F_131 ( struct V_219 * V_89 )
{
F_130 ( V_89 , V_232 ) ;
F_132 ( V_89 ) ;
return F_133 ( V_89 ) ;
}
static int F_134 ( struct V_233 * V_234 )
{
struct V_219 * V_89 = F_135 ( V_234 ) ;
struct V_235 V_29 ;
V_29 . V_236 = 0 ;
return F_127 ( V_89 , V_29 ) ;
}
static int F_136 ( struct V_233 * V_234 )
{
struct V_219 * V_89 = F_135 ( V_234 ) ;
return F_131 ( V_89 ) ;
}
static int F_137 ( struct V_233 * V_234 )
{
struct V_219 * V_89 = F_135 ( V_234 ) ;
struct V_80 * V_71 = F_120 ( V_89 ) ;
struct V_21 * V_22 = F_86 ( V_71 ) ;
V_22 -> V_237 = true ;
if ( V_22 -> V_108 )
F_29 ( V_22 , true ) ;
if ( V_22 -> V_47 != 0 ) {
F_2 ( L_60
L_61 ) ;
if ( V_22 -> V_108 )
F_24 ( V_22 , true ) ;
V_22 -> V_237 = false ;
return - V_230 ;
}
return 0 ;
}
static void F_138 ( struct V_233 * V_234 )
{
struct V_219 * V_89 = F_135 ( V_234 ) ;
struct V_80 * V_71 = F_120 ( V_89 ) ;
struct V_21 * V_22 = F_86 ( V_71 ) ;
F_25 ( & V_22 -> V_48 ) ;
F_26 ( V_22 , V_110 , V_111 ) ;
( void ) F_27 ( V_22 , V_110 ) ;
F_28 ( & V_22 -> V_48 ) ;
if ( V_22 -> V_108 )
F_24 ( V_22 , false ) ;
V_22 -> V_237 = false ;
}
static int F_139 ( struct V_219 * V_89 , const struct V_238 * V_239 )
{
return F_140 ( V_89 , V_239 , & V_194 ) ;
}
static int T_6 F_141 ( void )
{
int V_23 ;
V_23 = F_142 ( & V_194 , & V_240 ) ;
if ( V_23 )
F_14 ( L_62 ) ;
return V_23 ;
}
static void T_7 F_143 ( void )
{
F_144 ( & V_194 , & V_240 ) ;
}
