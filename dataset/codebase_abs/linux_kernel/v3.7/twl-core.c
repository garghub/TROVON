unsigned int F_1 ( void )
{
return V_1 ;
}
int F_2 ( T_1 V_2 , T_1 * V_3 , T_1 V_4 , unsigned V_5 )
{
int V_6 ;
int V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
if ( F_3 ( V_2 > V_12 ) ) {
F_4 ( L_1 , V_13 , V_2 ) ;
return - V_14 ;
}
if ( F_3 ( ! V_15 ) ) {
F_4 ( L_2 , V_13 ) ;
return - V_14 ;
}
V_7 = V_16 [ V_2 ] . V_7 ;
if ( F_3 ( V_7 == V_17 ) ) {
F_4 ( L_3 ,
V_13 , V_2 ) ;
return - V_18 ;
}
V_9 = & V_19 [ V_7 ] ;
F_5 ( & V_9 -> V_20 ) ;
V_11 = & V_9 -> V_21 [ 0 ] ;
V_11 -> V_22 = V_9 -> V_23 ;
V_11 -> V_24 = V_5 + 1 ;
V_11 -> V_25 = 0 ;
V_11 -> V_26 = V_3 ;
* V_3 = V_16 [ V_2 ] . V_27 + V_4 ;
V_6 = F_6 ( V_9 -> V_28 -> V_29 , V_9 -> V_21 , 1 ) ;
F_7 ( & V_9 -> V_20 ) ;
if ( V_6 != 1 ) {
F_4 ( L_4 ,
V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
else
return - V_30 ;
} else {
return 0 ;
}
}
int F_8 ( T_1 V_2 , T_1 * V_3 , T_1 V_4 , unsigned V_5 )
{
int V_6 ;
T_1 V_31 ;
int V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
if ( F_3 ( V_2 > V_12 ) ) {
F_4 ( L_1 , V_13 , V_2 ) ;
return - V_14 ;
}
if ( F_3 ( ! V_15 ) ) {
F_4 ( L_2 , V_13 ) ;
return - V_14 ;
}
V_7 = V_16 [ V_2 ] . V_7 ;
if ( F_3 ( V_7 == V_17 ) ) {
F_4 ( L_3 ,
V_13 , V_2 ) ;
return - V_18 ;
}
V_9 = & V_19 [ V_7 ] ;
F_5 ( & V_9 -> V_20 ) ;
V_11 = & V_9 -> V_21 [ 0 ] ;
V_11 -> V_22 = V_9 -> V_23 ;
V_11 -> V_24 = 1 ;
V_11 -> V_25 = 0 ;
V_31 = V_16 [ V_2 ] . V_27 + V_4 ;
V_11 -> V_26 = & V_31 ;
V_11 = & V_9 -> V_21 [ 1 ] ;
V_11 -> V_22 = V_9 -> V_23 ;
V_11 -> V_25 = V_32 ;
V_11 -> V_24 = V_5 ;
V_11 -> V_26 = V_3 ;
V_6 = F_6 ( V_9 -> V_28 -> V_29 , V_9 -> V_21 , 2 ) ;
F_7 ( & V_9 -> V_20 ) ;
if ( V_6 != 2 ) {
F_4 ( L_5 ,
V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
else
return - V_30 ;
} else {
return 0 ;
}
}
int F_9 ( T_1 V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_33 [ 2 ] = { 0 } ;
V_33 [ 1 ] = V_3 ;
return F_2 ( V_2 , V_33 , V_4 , 1 ) ;
}
int F_10 ( T_1 V_2 , T_1 * V_3 , T_1 V_4 )
{
return F_8 ( V_2 , V_3 , V_4 , 1 ) ;
}
static int F_11 ( void )
{
int V_34 ;
V_34 = F_9 ( V_35 , V_36 ,
V_37 ) ;
if ( V_34 ) {
F_4 ( L_6 , V_34 ) ;
goto V_38;
}
V_34 = F_8 ( V_35 , ( T_1 * ) ( & V_39 ) ,
V_40 , 4 ) ;
if ( V_34 ) {
F_4 ( L_7 , V_34 ) ;
goto V_38;
}
V_34 = F_9 ( V_35 , 0x0 , V_37 ) ;
if ( V_34 )
F_4 ( L_8 , V_34 ) ;
V_38:
return V_34 ;
}
int F_12 ( void )
{
return F_13 ( V_39 ) ;
}
int F_14 ( void )
{
return F_15 ( V_39 ) ;
}
int F_16 ( void )
{
T_1 V_41 ;
int V_42 ;
F_10 ( V_43 , & V_41 , V_44 ) ;
switch ( V_41 & 0x3 ) {
case V_45 :
V_42 = 19200000 ;
break;
case V_46 :
V_42 = 26000000 ;
break;
case V_47 :
V_42 = 38400000 ;
break;
default:
F_4 ( L_9 ) ;
V_42 = - V_18 ;
break;
}
return V_42 ;
}
static struct V_48 *
F_17 ( unsigned V_49 , const char * V_50 , int V_51 ,
void * V_52 , unsigned V_53 ,
bool V_54 , int V_55 , int V_56 )
{
struct V_57 * V_58 ;
struct V_8 * V_9 = & V_19 [ V_49 ] ;
int V_59 ;
V_58 = F_18 ( V_50 , V_51 ) ;
if ( ! V_58 ) {
F_19 ( & V_9 -> V_28 -> V_60 , L_10 ) ;
V_59 = - V_61 ;
goto V_34;
}
V_58 -> V_60 . V_62 = & V_9 -> V_28 -> V_60 ;
if ( V_52 ) {
V_59 = F_20 ( V_58 , V_52 , V_53 ) ;
if ( V_59 < 0 ) {
F_19 ( & V_58 -> V_60 , L_11 ) ;
goto V_34;
}
}
if ( V_55 ) {
struct V_63 V_64 [ 2 ] = {
{ . V_65 = V_55 , . V_25 = V_66 , } ,
{ . V_65 = V_56 , . V_25 = V_66 , } ,
} ;
V_59 = F_21 ( V_58 , V_64 , V_56 ? 2 : 1 ) ;
if ( V_59 < 0 ) {
F_19 ( & V_58 -> V_60 , L_12 ) ;
goto V_34;
}
}
V_59 = F_22 ( V_58 ) ;
if ( V_59 == 0 )
F_23 ( & V_58 -> V_60 , V_54 ) ;
V_34:
if ( V_59 < 0 ) {
F_24 ( V_58 ) ;
F_25 ( & V_9 -> V_28 -> V_60 , L_13 , V_50 ) ;
return F_26 ( V_59 ) ;
}
return & V_58 -> V_60 ;
}
static inline struct V_48 * F_27 ( unsigned V_49 , const char * V_50 ,
void * V_52 , unsigned V_53 ,
bool V_54 , int V_55 , int V_56 )
{
return F_17 ( V_49 , V_50 , - 1 , V_52 , V_53 ,
V_54 , V_55 , V_56 ) ;
}
static struct V_48 *
F_28 ( int V_51 , struct V_67 * V_52 ,
struct V_68 * V_69 ,
unsigned V_70 , unsigned long V_71 )
{
unsigned V_72 ;
struct V_73 V_74 ;
if ( ! V_52 )
return NULL ;
if ( V_69 ) {
V_52 -> V_75 = V_69 ;
V_52 -> V_76 = V_70 ;
}
if ( V_52 -> V_77 ) {
struct V_73 * V_78 ;
V_78 = V_52 -> V_77 ;
V_78 -> V_71 |= V_71 ;
} else {
V_74 . V_71 = V_71 ;
V_74 . V_79 = NULL ;
V_74 . V_80 = NULL ;
V_74 . V_81 = NULL ;
V_52 -> V_77 = & V_74 ;
}
V_72 = V_16 [ V_43 ] . V_7 ;
return F_17 ( V_72 , L_14 , V_51 ,
V_52 , sizeof( * V_52 ) , false , 0 , 0 ) ;
}
static struct V_48 *
F_29 ( int V_51 , struct V_67 * V_52 ,
unsigned long V_71 )
{
return F_28 ( V_51 , V_52 , NULL , 0 , V_71 ) ;
}
static int
F_30 ( struct V_82 * V_52 , unsigned V_83 ,
unsigned long V_71 )
{
struct V_48 * V_84 ;
unsigned V_72 ;
if ( F_31 ( V_85 ) && V_52 -> V_86 ) {
V_84 = F_27 ( V_87 , L_15 ,
V_52 -> V_86 , sizeof( * V_52 -> V_86 ) ,
false , V_83 + V_88 , 0 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
}
if ( F_31 ( V_89 ) && V_52 -> V_90 ) {
V_84 = F_27 ( V_91 , L_16 ,
V_52 -> V_90 , sizeof( * V_52 -> V_90 ) ,
true , V_83 + V_92 , 0 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
}
if ( F_31 ( V_93 ) && V_52 -> V_94 ) {
V_84 = F_27 ( 2 , L_17 ,
V_52 -> V_94 , sizeof( * V_52 -> V_94 ) ,
true , V_83 + V_95 , 0 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
}
if ( F_31 ( V_96 ) ) {
V_72 = V_16 [ V_97 ] . V_7 ;
V_84 = F_27 ( V_72 , L_18 ,
NULL , 0 ,
true , V_83 + V_98 , 0 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
}
if ( F_31 ( V_99 ) && F_34 () ) {
V_84 = F_27 ( V_87 , L_19 , NULL , 0 ,
false , 0 , 0 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
}
if ( F_31 ( V_100 ) && V_52 -> V_101 &&
F_35 () ) {
static struct V_68 V_102 = {
. V_103 = L_20 ,
} ;
static struct V_68 V_104 = {
. V_103 = L_21 ,
} ;
static struct V_68 V_105 [] = {
{ . V_103 = L_22 } ,
{ . V_103 = L_23 } ,
} ;
if ( F_31 ( V_106 ) ) {
struct V_67 V_107 = {
. V_108 . V_109 =
V_110
| V_111 ,
. V_108 . V_112 =
V_113
| V_114 ,
} ;
V_84 = F_28 ( V_115 ,
& V_107 , & V_102 , 1 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_28 ( V_116 ,
& V_107 , & V_104 , 1 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_28 ( V_117 ,
& V_107 , V_105 , 2 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
}
V_84 = F_27 ( 0 , L_24 ,
V_52 -> V_101 , sizeof( * V_52 -> V_101 ) ,
true ,
V_83 + V_118 ,
V_83 + V_119 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
if ( F_31 ( V_106 ) && V_84 ) {
V_102 . V_120 = V_120 ( V_84 ) ;
V_104 . V_120 = V_120 ( V_84 ) ;
V_105 [ 0 ] . V_120 = V_120 ( V_84 ) ;
}
}
if ( F_31 ( V_121 ) && V_52 -> V_101 &&
F_34 () ) {
static struct V_68 V_122 ;
int V_123 ;
if ( F_31 ( V_106 ) ) {
struct V_67 V_107 = {
. V_108 . V_109 =
V_110
| V_111 ,
. V_108 . V_112 =
V_113
| V_114 ,
} ;
if ( V_71 & V_124 ) {
V_122 . V_103 = L_25 ;
V_123 = V_125 ;
} else {
V_122 . V_103 = L_26 ;
V_123 = V_126 ;
}
V_84 = F_28 ( V_123 , & V_107 ,
& V_122 , 1 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
}
V_52 -> V_101 -> V_71 = V_71 ;
V_84 = F_27 ( 0 , L_27 ,
V_52 -> V_101 , sizeof( * V_52 -> V_101 ) ,
true ,
V_83 + V_127 ,
V_83 + V_118 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
if ( F_31 ( V_106 ) && V_84 )
V_122 . V_120 = V_120 ( V_84 ) ;
} else if ( F_31 ( V_106 ) &&
F_34 () ) {
if ( V_71 & V_124 )
V_84 = F_29 ( V_125 ,
V_52 -> V_128 , V_71 ) ;
else
V_84 = F_29 ( V_126 ,
V_52 -> V_129 , V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
}
if ( F_31 ( V_130 ) && F_35 () ) {
V_84 = F_27 ( 0 , L_28 , NULL , 0 , false , 0 , 0 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
}
if ( F_31 ( V_131 ) && F_35 () ) {
V_84 = F_27 ( 1 , L_29 ,
NULL , 0 , true , V_83 + 8 + 0 , 0 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
}
if ( F_31 ( V_132 ) && V_52 -> V_133 &&
F_35 () ) {
V_72 = V_16 [ V_134 ] . V_7 ;
V_84 = F_27 ( V_72 , L_30 ,
V_52 -> V_133 , sizeof( * V_52 -> V_133 ) ,
false , 0 , 0 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
}
if ( F_31 ( V_106 ) && F_35 () ) {
V_84 = F_29 ( V_135 , V_52 -> V_136 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_137 , V_52 -> V_138 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_139 , V_52 -> V_140 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_141 , V_52 -> V_142 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_143 , V_52 -> V_144 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_145 , V_52 -> V_146 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( ( V_71 & V_147 )
? V_148
: V_149 ,
V_52 -> V_150 , V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_151 , V_52 -> V_152 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_153 , V_52 -> V_154 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_155 , V_52 -> V_156 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
}
if ( F_31 ( V_106 ) && ! ( V_71 & V_157 )
&& F_35 () ) {
V_84 = F_29 ( V_158 , V_52 -> V_159 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_160 , V_52 -> V_161 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_162 , V_52 -> V_163 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_164 , V_52 -> V_165 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_166 , V_52 -> V_167 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_168 , V_52 -> V_169 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
}
if ( F_31 ( V_106 ) && F_34 () &&
! ( V_71 & V_124 ) ) {
V_84 = F_29 ( V_170 , V_52 -> V_140 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_171 , V_52 -> V_142 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_172 , V_52 -> V_173 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_174 , V_52 -> V_175 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_176 , V_52 -> V_177 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_178 , V_52 -> V_179 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_180 , V_52 -> V_181 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_182 , V_52 -> V_183 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_184 , V_52 -> V_185 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_186 , V_52 -> V_146 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_187 , V_52 -> V_165 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_188 , V_52 -> V_150 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_189 , V_52 -> V_167 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_190 , V_52 -> V_191 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
}
if ( F_31 ( V_106 ) && F_34 () ) {
V_84 = F_29 ( V_192 , V_52 -> V_193 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
}
if ( F_31 ( V_106 ) && F_34 () &&
( V_71 & V_124 ) ) {
V_84 = F_29 ( V_194 , V_52 -> V_195 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_196 , V_52 -> V_197 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_198 , V_52 -> V_199 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_200 , V_52 -> V_201 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_202 , V_52 -> V_203 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_204 , V_52 -> V_205 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_206 , V_52 -> V_207 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_208 , V_52 -> V_209 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_210 , V_52 -> V_211 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_212 , V_52 -> V_213 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
V_84 = F_29 ( V_214 , V_52 -> V_215 ,
V_71 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
}
if ( F_31 ( V_216 ) && V_52 -> V_217 &&
! ( V_71 & ( V_157 | V_218 ) ) ) {
V_84 = F_27 ( 3 , L_31 ,
V_52 -> V_217 , sizeof( * V_52 -> V_217 ) , false ,
V_83 + V_219 ,
V_83 + V_220 ) ;
if ( F_32 ( V_84 ) )
return F_33 ( V_84 ) ;
}
return 0 ;
}
static inline int T_2 F_36 ( void )
{
int V_221 = 0 ;
V_221 = F_9 ( V_222 , 0 ,
V_223 ) ;
return V_221 ;
}
static inline int T_2 F_37 ( void )
{
int V_221 = 0 ;
V_221 |= F_9 ( V_222 ,
V_224 ,
V_223 ) ;
V_221 |= F_9 ( V_222 ,
V_225 ,
V_223 ) ;
return V_221 ;
}
static void F_38 ( struct V_48 * V_60 ,
struct V_226 * clock )
{
int V_221 = 0 ;
struct V_227 * V_228 ;
T_3 V_42 ;
T_1 V_41 = V_46 ;
V_228 = F_39 ( V_60 , L_32 ) ;
if ( F_32 ( V_228 ) ) {
F_40 ( V_229 L_33
L_34 ) ;
return;
}
V_42 = F_41 ( V_228 ) ;
F_42 ( V_228 ) ;
switch ( V_42 ) {
case 19200000 :
V_41 = V_45 ;
break;
case 26000000 :
V_41 = V_46 ;
break;
case 38400000 :
V_41 = V_47 ;
break;
}
V_41 |= V_230 ;
if ( clock && clock -> V_231 )
V_41 |= V_232 ;
V_221 |= F_37 () ;
V_221 |= F_9 ( V_43 , V_41 , V_44 ) ;
V_221 |= F_36 () ;
if ( V_221 < 0 )
F_4 ( L_35 , V_13 , V_221 ) ;
}
static int F_43 ( struct V_233 * V_28 )
{
unsigned V_234 , V_235 ;
int V_59 ;
if ( F_35 () ) {
V_59 = F_44 () ;
V_235 = V_236 ;
} else {
V_59 = F_45 () ;
V_235 = V_236 - 1 ;
}
if ( V_59 < 0 )
return V_59 ;
for ( V_234 = 0 ; V_234 < V_235 ; V_234 ++ ) {
struct V_8 * V_9 = & V_19 [ V_234 ] ;
if ( V_9 -> V_28 && V_9 -> V_28 != V_28 )
F_46 ( V_9 -> V_28 ) ;
V_19 [ V_234 ] . V_28 = NULL ;
}
V_15 = false ;
return 0 ;
}
static int T_4
F_47 ( struct V_233 * V_28 , const struct V_237 * V_238 )
{
struct V_82 * V_52 = V_28 -> V_60 . V_239 ;
struct V_240 * V_241 = V_28 -> V_60 . V_242 ;
struct V_57 * V_58 ;
int V_83 = 0 ;
int V_59 ;
unsigned V_234 , V_235 ;
V_58 = F_18 ( V_13 , - 1 ) ;
if ( ! V_58 ) {
F_25 ( & V_28 -> V_60 , L_36 ) ;
return - V_61 ;
}
V_59 = F_22 ( V_58 ) ;
if ( V_59 ) {
F_24 ( V_58 ) ;
return V_59 ;
}
if ( V_241 && ! V_52 ) {
V_52 = F_48 ( & V_28 -> V_60 ,
sizeof( struct V_82 ) ,
V_243 ) ;
if ( ! V_52 ) {
V_59 = - V_61 ;
goto free;
}
}
if ( ! V_52 ) {
F_19 ( & V_28 -> V_60 , L_37 ) ;
V_59 = - V_18 ;
goto free;
}
F_49 ( V_58 , V_52 ) ;
if ( F_50 ( V_28 -> V_29 , V_244 ) == 0 ) {
F_19 ( & V_28 -> V_60 , L_38 ) ;
V_59 = - V_30 ;
goto free;
}
if ( V_15 ) {
F_19 ( & V_28 -> V_60 , L_39 ) ;
V_59 = - V_245 ;
goto free;
}
if ( ( V_238 -> V_77 ) & V_246 ) {
V_1 = V_247 ;
V_16 = & V_248 [ 0 ] ;
V_235 = V_236 - 1 ;
} else {
V_1 = V_249 ;
V_16 = & V_250 [ 0 ] ;
V_235 = V_236 ;
}
for ( V_234 = 0 ; V_234 < V_235 ; V_234 ++ ) {
struct V_8 * V_9 = & V_19 [ V_234 ] ;
V_9 -> V_23 = V_28 -> V_22 + V_234 ;
if ( V_234 == 0 ) {
V_9 -> V_28 = V_28 ;
} else {
V_9 -> V_28 = F_51 ( V_28 -> V_29 ,
V_9 -> V_23 ) ;
if ( ! V_9 -> V_28 ) {
F_25 ( & V_28 -> V_60 ,
L_40 , V_234 ) ;
V_59 = - V_61 ;
goto V_38;
}
}
F_52 ( & V_9 -> V_20 ) ;
}
V_15 = true ;
F_38 ( & V_58 -> V_60 , V_52 -> clock ) ;
if ( V_1 == V_249 ) {
V_59 = F_11 () ;
F_53 ( V_59 < 0 , L_41 ) ;
}
if ( F_31 ( V_251 ) && V_52 -> V_252 )
F_54 ( V_52 -> V_252 ) ;
if ( V_28 -> V_253 ) {
if ( F_35 () ) {
F_55 ( V_238 -> V_50 ) ;
V_83 = F_56 ( & V_28 -> V_60 , V_28 -> V_253 ) ;
} else {
V_83 = F_57 ( & V_28 -> V_60 , V_28 -> V_253 ) ;
}
if ( V_83 < 0 ) {
V_59 = V_83 ;
goto V_38;
}
}
if ( F_35 () ) {
T_1 V_254 ;
F_10 ( V_35 , & V_254 , V_255 ) ;
V_254 &= ~ ( V_256 | V_257 | \
V_258 | V_259 ) ;
F_9 ( V_35 , V_254 , V_255 ) ;
}
V_59 = - V_260 ;
if ( V_241 )
V_59 = F_58 ( V_241 , NULL , NULL , & V_28 -> V_60 ) ;
if ( V_59 )
V_59 = F_30 ( V_52 , V_83 , V_238 -> V_77 ) ;
V_38:
if ( V_59 < 0 )
F_43 ( V_28 ) ;
free:
if ( V_59 < 0 )
F_59 ( V_58 ) ;
return V_59 ;
}
static int T_2 F_60 ( void )
{
return F_61 ( & V_261 ) ;
}
static void T_5 F_62 ( void )
{
F_63 ( & V_261 ) ;
}
