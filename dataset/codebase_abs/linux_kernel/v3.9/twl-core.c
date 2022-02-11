static inline int F_1 ( void )
{
if ( F_2 () )
return 4 ;
else
return 3 ;
}
static inline int F_3 ( void )
{
if ( F_2 () )
return V_1 ;
else
return V_2 ;
}
unsigned int F_4 ( void )
{
return V_3 ? V_3 -> V_4 : 0 ;
}
int F_5 ( T_1 V_5 , T_1 * V_6 , T_1 V_7 , unsigned V_8 )
{
int V_9 ;
int V_10 ;
struct V_11 * V_12 ;
if ( F_6 ( ! V_3 || ! V_3 -> V_13 ) ) {
F_7 ( L_1 , V_14 ) ;
return - V_15 ;
}
if ( F_6 ( V_5 >= F_3 () ) ) {
F_7 ( L_2 , V_14 , V_5 ) ;
return - V_15 ;
}
V_10 = V_3 -> V_16 [ V_5 ] . V_10 ;
V_12 = & V_3 -> V_17 [ V_10 ] ;
V_9 = F_8 ( V_12 -> V_18 ,
V_3 -> V_16 [ V_5 ] . V_19 + V_7 , V_6 ,
V_8 ) ;
if ( V_9 )
F_7 ( L_3 ,
V_14 , V_5 , V_7 , V_8 ) ;
return V_9 ;
}
int F_9 ( T_1 V_5 , T_1 * V_6 , T_1 V_7 , unsigned V_8 )
{
int V_9 ;
int V_10 ;
struct V_11 * V_12 ;
if ( F_6 ( ! V_3 || ! V_3 -> V_13 ) ) {
F_7 ( L_1 , V_14 ) ;
return - V_15 ;
}
if ( F_6 ( V_5 >= F_3 () ) ) {
F_7 ( L_2 , V_14 , V_5 ) ;
return - V_15 ;
}
V_10 = V_3 -> V_16 [ V_5 ] . V_10 ;
V_12 = & V_3 -> V_17 [ V_10 ] ;
V_9 = F_10 ( V_12 -> V_18 ,
V_3 -> V_16 [ V_5 ] . V_19 + V_7 , V_6 ,
V_8 ) ;
if ( V_9 )
F_7 ( L_4 ,
V_14 , V_5 , V_7 , V_8 ) ;
return V_9 ;
}
static int F_11 ( void )
{
int V_20 ;
V_20 = F_12 ( V_21 , V_22 ,
V_23 ) ;
if ( V_20 ) {
F_7 ( L_5 , V_20 ) ;
goto V_24;
}
V_20 = F_9 ( V_21 , ( T_1 * ) ( & V_3 -> V_25 ) ,
V_26 , 4 ) ;
if ( V_20 ) {
F_7 ( L_6 , V_20 ) ;
goto V_24;
}
V_20 = F_12 ( V_21 , 0x0 , V_23 ) ;
if ( V_20 )
F_7 ( L_7 , V_20 ) ;
V_24:
return V_20 ;
}
int F_13 ( void )
{
return F_14 ( V_3 -> V_25 ) ;
}
int F_15 ( void )
{
return F_16 ( V_3 -> V_25 ) ;
}
int F_17 ( void )
{
T_1 V_27 ;
int V_28 ;
F_18 ( V_29 , & V_27 , V_30 ) ;
switch ( V_27 & 0x3 ) {
case V_31 :
V_28 = 19200000 ;
break;
case V_32 :
V_28 = 26000000 ;
break;
case V_33 :
V_28 = 38400000 ;
break;
default:
F_7 ( L_8 ) ;
V_28 = - V_34 ;
break;
}
return V_28 ;
}
static struct V_35 *
F_19 ( unsigned V_5 , const char * V_36 , int V_37 ,
void * V_38 , unsigned V_39 ,
bool V_40 , int V_41 , int V_42 )
{
struct V_43 * V_44 ;
struct V_11 * V_12 ;
int V_45 , V_10 ;
if ( F_6 ( V_5 >= F_3 () ) ) {
F_7 ( L_2 , V_14 , V_5 ) ;
return F_20 ( - V_15 ) ;
}
V_10 = V_3 -> V_16 [ V_5 ] . V_10 ;
V_12 = & V_3 -> V_17 [ V_10 ] ;
V_44 = F_21 ( V_36 , V_37 ) ;
if ( ! V_44 ) {
F_22 ( & V_12 -> V_46 -> V_47 , L_9 ) ;
V_45 = - V_48 ;
goto V_20;
}
V_44 -> V_47 . V_49 = & V_12 -> V_46 -> V_47 ;
if ( V_38 ) {
V_45 = F_23 ( V_44 , V_38 , V_39 ) ;
if ( V_45 < 0 ) {
F_22 ( & V_44 -> V_47 , L_10 ) ;
goto V_20;
}
}
if ( V_41 ) {
struct V_50 V_51 [ 2 ] = {
{ . V_52 = V_41 , . V_53 = V_54 , } ,
{ . V_52 = V_42 , . V_53 = V_54 , } ,
} ;
V_45 = F_24 ( V_44 , V_51 , V_42 ? 2 : 1 ) ;
if ( V_45 < 0 ) {
F_22 ( & V_44 -> V_47 , L_11 ) ;
goto V_20;
}
}
V_45 = F_25 ( V_44 ) ;
if ( V_45 == 0 )
F_26 ( & V_44 -> V_47 , V_40 ) ;
V_20:
if ( V_45 < 0 ) {
F_27 ( V_44 ) ;
F_28 ( & V_12 -> V_46 -> V_47 , L_12 , V_36 ) ;
return F_20 ( V_45 ) ;
}
return & V_44 -> V_47 ;
}
static inline struct V_35 * F_29 ( unsigned V_5 , const char * V_36 ,
void * V_38 , unsigned V_39 ,
bool V_40 , int V_41 , int V_42 )
{
return F_19 ( V_5 , V_36 , - 1 , V_38 , V_39 ,
V_40 , V_41 , V_42 ) ;
}
static struct V_35 *
F_30 ( int V_37 , struct V_55 * V_38 ,
struct V_56 * V_57 ,
unsigned V_58 , unsigned long V_59 )
{
struct V_60 V_61 ;
if ( ! V_38 )
return NULL ;
if ( V_57 ) {
V_38 -> V_62 = V_57 ;
V_38 -> V_63 = V_58 ;
}
if ( V_38 -> V_64 ) {
struct V_60 * V_65 ;
V_65 = V_38 -> V_64 ;
V_65 -> V_59 |= V_59 ;
} else {
V_61 . V_59 = V_59 ;
V_61 . V_66 = NULL ;
V_61 . V_67 = NULL ;
V_61 . V_68 = NULL ;
V_38 -> V_64 = & V_61 ;
}
return F_19 ( V_29 , L_13 , V_37 ,
V_38 , sizeof( * V_38 ) , false , 0 , 0 ) ;
}
static struct V_35 *
F_31 ( int V_37 , struct V_55 * V_38 ,
unsigned long V_59 )
{
return F_30 ( V_37 , V_38 , NULL , 0 , V_59 ) ;
}
static int
F_32 ( struct V_69 * V_38 , unsigned V_70 ,
unsigned long V_59 )
{
struct V_35 * V_71 ;
if ( F_33 ( V_72 ) && V_38 -> V_73 ) {
V_71 = F_29 ( V_74 , L_14 ,
V_38 -> V_73 , sizeof( * V_38 -> V_73 ) ,
false , V_70 + V_75 , 0 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
}
if ( F_33 ( V_76 ) && V_38 -> V_77 ) {
V_71 = F_29 ( V_78 , L_15 ,
V_38 -> V_77 , sizeof( * V_38 -> V_77 ) ,
true , V_70 + V_79 , 0 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
}
if ( F_33 ( V_80 ) && V_38 -> V_81 &&
F_2 () ) {
V_71 = F_29 ( V_82 , L_16 ,
V_38 -> V_81 , sizeof( * V_38 -> V_81 ) ,
true , V_70 + V_83 , 0 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
}
if ( F_33 ( V_84 ) ) {
V_71 = F_29 ( V_85 , L_17 , NULL , 0 ,
true , V_70 + V_86 , 0 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
}
if ( F_33 ( V_87 ) ) {
V_71 = F_29 ( V_88 , L_18 , NULL , 0 ,
false , 0 , 0 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
}
if ( F_33 ( V_89 ) ) {
V_71 = F_29 ( V_90 , L_19 , NULL , 0 ,
false , 0 , 0 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
}
if ( F_33 ( V_91 ) && V_38 -> V_92 &&
F_2 () ) {
static struct V_56 V_93 = {
. V_94 = L_20 ,
} ;
static struct V_56 V_95 = {
. V_94 = L_21 ,
} ;
static struct V_56 V_96 [] = {
{ . V_94 = L_22 } ,
{ . V_94 = L_23 } ,
} ;
if ( F_33 ( V_97 ) ) {
struct V_55 V_98 = {
. V_99 . V_100 =
V_101
| V_102 ,
. V_99 . V_103 =
V_104
| V_105 ,
} ;
V_71 = F_30 ( V_106 ,
& V_98 , & V_93 , 1 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_30 ( V_107 ,
& V_98 , & V_95 , 1 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_30 ( V_108 ,
& V_98 , V_96 , 2 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
}
V_71 = F_29 ( V_109 , L_24 ,
V_38 -> V_92 , sizeof( * V_38 -> V_92 ) , true ,
V_70 + V_110 ,
V_70 + V_111 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
if ( F_33 ( V_97 ) && V_71 ) {
V_93 . V_112 = V_112 ( V_71 ) ;
V_95 . V_112 = V_112 ( V_71 ) ;
V_96 [ 0 ] . V_112 = V_112 ( V_71 ) ;
}
}
if ( F_33 ( V_113 ) && V_38 -> V_92 &&
F_36 () ) {
static struct V_56 V_114 ;
int V_115 ;
if ( F_33 ( V_97 ) ) {
struct V_55 V_98 = {
. V_99 . V_100 =
V_101
| V_102 ,
. V_99 . V_103 =
V_104
| V_105 ,
} ;
if ( V_59 & V_116 ) {
V_114 . V_94 = L_25 ;
V_115 = V_117 ;
} else {
V_114 . V_94 = L_26 ;
V_115 = V_118 ;
}
V_71 = F_30 ( V_115 , & V_98 ,
& V_114 , 1 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
}
V_38 -> V_92 -> V_59 = V_59 ;
V_71 = F_29 ( V_109 , L_27 ,
V_38 -> V_92 , sizeof( * V_38 -> V_92 ) , true ,
V_70 + V_119 ,
V_70 + V_110 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
if ( F_33 ( V_97 ) && V_71 )
V_114 . V_112 = V_112 ( V_71 ) ;
} else if ( F_33 ( V_97 ) &&
F_36 () ) {
if ( V_59 & V_116 )
V_71 = F_31 ( V_117 ,
V_38 -> V_120 , V_59 ) ;
else
V_71 = F_31 ( V_118 ,
V_38 -> V_121 , V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
}
if ( F_33 ( V_122 ) && F_2 () ) {
V_71 = F_29 ( V_123 , L_28 , NULL ,
0 , false , 0 , 0 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
}
if ( F_33 ( V_124 ) && F_2 () ) {
V_71 = F_29 ( V_29 , L_29 ,
NULL , 0 , true , V_70 + 8 + 0 , 0 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
}
if ( F_33 ( V_125 ) && V_38 -> V_126 &&
F_2 () ) {
V_71 = F_29 ( V_127 , L_30 ,
V_38 -> V_126 , sizeof( * V_38 -> V_126 ) ,
false , 0 , 0 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
}
if ( F_33 ( V_97 ) && F_2 () ) {
V_71 = F_31 ( V_128 , V_38 -> V_129 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_130 , V_38 -> V_131 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_132 , V_38 -> V_133 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_134 , V_38 -> V_135 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_136 , V_38 -> V_137 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_138 , V_38 -> V_139 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( ( V_59 & V_140 )
? V_141
: V_142 ,
V_38 -> V_143 , V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_144 , V_38 -> V_145 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_146 , V_38 -> V_147 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_148 , V_38 -> V_149 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
}
if ( F_33 ( V_97 ) && ! ( V_59 & V_150 )
&& F_2 () ) {
V_71 = F_31 ( V_151 , V_38 -> V_152 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_153 , V_38 -> V_154 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_155 , V_38 -> V_156 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_157 , V_38 -> V_158 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_159 , V_38 -> V_160 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_161 , V_38 -> V_162 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
}
if ( F_33 ( V_97 ) && F_36 () &&
! ( V_59 & V_116 ) ) {
V_71 = F_31 ( V_163 , V_38 -> V_133 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_164 , V_38 -> V_135 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_165 , V_38 -> V_166 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_167 , V_38 -> V_168 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_169 , V_38 -> V_170 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_171 , V_38 -> V_172 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_173 , V_38 -> V_174 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_175 , V_38 -> V_176 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_177 , V_38 -> V_178 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_179 , V_38 -> V_139 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_180 , V_38 -> V_158 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_181 , V_38 -> V_143 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_182 , V_38 -> V_160 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_183 , V_38 -> V_184 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
}
if ( F_33 ( V_97 ) && F_36 () ) {
V_71 = F_31 ( V_185 , V_38 -> V_186 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
}
if ( F_33 ( V_97 ) && F_36 () &&
( V_59 & V_116 ) ) {
V_71 = F_31 ( V_187 , V_38 -> V_188 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_189 , V_38 -> V_190 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_191 , V_38 -> V_192 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_193 , V_38 -> V_194 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_195 , V_38 -> V_196 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_197 , V_38 -> V_198 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_199 , V_38 -> V_200 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_201 , V_38 -> V_202 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_203 , V_38 -> V_204 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_205 , V_38 -> V_206 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
V_71 = F_31 ( V_207 , V_38 -> V_208 ,
V_59 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
}
if ( F_33 ( V_209 ) && V_38 -> V_210 &&
! ( V_59 & ( V_150 | V_211 ) ) ) {
V_71 = F_29 ( V_212 , L_31 ,
V_38 -> V_210 , sizeof( * V_38 -> V_210 ) , false ,
V_70 + V_213 ,
V_70 + V_214 ) ;
if ( F_34 ( V_71 ) )
return F_35 ( V_71 ) ;
}
return 0 ;
}
static inline int T_2 F_37 ( void )
{
int V_215 = 0 ;
V_215 = F_12 ( V_29 , 0 ,
V_216 ) ;
return V_215 ;
}
static inline int T_2 F_38 ( void )
{
int V_215 = 0 ;
V_215 |= F_12 ( V_29 , V_217 ,
V_216 ) ;
V_215 |= F_12 ( V_29 , V_218 ,
V_216 ) ;
return V_215 ;
}
static void F_39 ( struct V_35 * V_47 ,
struct V_219 * clock )
{
int V_215 = 0 ;
struct V_220 * V_221 ;
T_3 V_28 ;
T_1 V_27 = V_32 ;
V_221 = F_40 ( V_47 , L_32 ) ;
if ( F_34 ( V_221 ) ) {
F_41 ( V_222 L_33
L_34 ) ;
return;
}
V_28 = F_42 ( V_221 ) ;
F_43 ( V_221 ) ;
switch ( V_28 ) {
case 19200000 :
V_27 = V_31 ;
break;
case 26000000 :
V_27 = V_32 ;
break;
case 38400000 :
V_27 = V_33 ;
break;
}
V_27 |= V_223 ;
if ( clock && clock -> V_224 )
V_27 |= V_225 ;
V_215 |= F_38 () ;
V_215 |= F_12 ( V_29 , V_27 , V_30 ) ;
V_215 |= F_37 () ;
if ( V_215 < 0 )
F_7 ( L_35 , V_14 , V_215 ) ;
}
static int F_44 ( struct V_226 * V_46 )
{
unsigned V_227 , V_228 ;
int V_45 ;
if ( F_2 () )
V_45 = F_45 () ;
else
V_45 = F_46 () ;
if ( V_45 < 0 )
return V_45 ;
V_228 = F_1 () ;
for ( V_227 = 0 ; V_227 < V_228 ; V_227 ++ ) {
struct V_11 * V_12 = & V_3 -> V_17 [ V_227 ] ;
if ( V_12 -> V_46 && V_12 -> V_46 != V_46 )
F_47 ( V_12 -> V_46 ) ;
V_12 -> V_46 = NULL ;
}
V_3 -> V_13 = false ;
return 0 ;
}
static int
F_48 ( struct V_226 * V_46 , const struct V_229 * V_230 )
{
struct V_69 * V_38 = V_46 -> V_47 . V_231 ;
struct V_232 * V_233 = V_46 -> V_47 . V_234 ;
struct V_43 * V_44 ;
struct V_235 * V_236 ;
int V_70 = 0 ;
int V_45 ;
unsigned V_227 , V_228 ;
if ( ! V_233 && ! V_38 ) {
F_28 ( & V_46 -> V_47 , L_36 ) ;
return - V_34 ;
}
if ( V_3 ) {
F_22 ( & V_46 -> V_47 , L_37 ,
V_14 ) ;
return - V_237 ;
}
V_44 = F_21 ( V_14 , - 1 ) ;
if ( ! V_44 ) {
F_28 ( & V_46 -> V_47 , L_38 ) ;
return - V_48 ;
}
V_45 = F_25 ( V_44 ) ;
if ( V_45 ) {
F_27 ( V_44 ) ;
return V_45 ;
}
if ( F_49 ( V_46 -> V_238 , V_239 ) == 0 ) {
F_22 ( & V_46 -> V_47 , L_39 ) ;
V_45 = - V_240 ;
goto free;
}
V_3 = F_50 ( & V_46 -> V_47 , sizeof( struct V_241 ) ,
V_242 ) ;
if ( ! V_3 ) {
V_45 = - V_48 ;
goto free;
}
if ( ( V_230 -> V_64 ) & V_243 ) {
V_3 -> V_4 = V_244 ;
V_3 -> V_16 = & V_245 [ 0 ] ;
if ( ( V_230 -> V_64 ) & V_116 )
V_3 -> V_16 [ V_212 ] . V_19 =
V_246 ;
V_236 = V_247 ;
} else {
V_3 -> V_4 = V_248 ;
V_3 -> V_16 = & V_249 [ 0 ] ;
V_236 = V_250 ;
}
V_228 = F_1 () ;
V_3 -> V_17 = F_50 ( & V_46 -> V_47 ,
sizeof( struct V_11 ) * V_228 ,
V_242 ) ;
if ( ! V_3 -> V_17 ) {
V_45 = - V_48 ;
goto free;
}
for ( V_227 = 0 ; V_227 < V_228 ; V_227 ++ ) {
struct V_11 * V_12 = & V_3 -> V_17 [ V_227 ] ;
if ( V_227 == 0 ) {
V_12 -> V_46 = V_46 ;
} else {
V_12 -> V_46 = F_51 ( V_46 -> V_238 ,
V_46 -> V_251 + V_227 ) ;
if ( ! V_12 -> V_46 ) {
F_28 ( & V_46 -> V_47 ,
L_40 , V_227 ) ;
V_45 = - V_48 ;
goto V_24;
}
}
V_12 -> V_18 = F_52 ( V_12 -> V_46 ,
& V_236 [ V_227 ] ) ;
if ( F_34 ( V_12 -> V_18 ) ) {
V_45 = F_35 ( V_12 -> V_18 ) ;
F_28 ( & V_46 -> V_47 ,
L_41 , V_227 ,
V_45 ) ;
goto V_24;
}
}
V_3 -> V_13 = true ;
F_39 ( & V_44 -> V_47 , V_38 ? V_38 -> clock : NULL ) ;
if ( F_2 () ) {
V_45 = F_11 () ;
F_53 ( V_45 < 0 , L_42 ) ;
}
if ( F_33 ( V_252 ) && V_38 && V_38 -> V_253 )
F_54 ( V_38 -> V_253 ) ;
if ( V_46 -> V_254 ) {
if ( F_2 () ) {
F_55 ( V_230 -> V_36 ) ;
V_70 = F_56 ( & V_46 -> V_47 , V_46 -> V_254 ) ;
} else {
V_70 = F_57 ( & V_46 -> V_47 , V_46 -> V_254 ) ;
}
if ( V_70 < 0 ) {
V_45 = V_70 ;
goto V_24;
}
}
if ( F_2 () ) {
T_1 V_255 ;
F_18 ( V_21 , & V_255 , V_256 ) ;
V_255 &= ~ ( V_257 | V_258 | \
V_259 | V_260 ) ;
F_12 ( V_21 , V_255 , V_256 ) ;
}
if ( V_233 )
V_45 = F_58 ( V_233 , NULL , NULL , & V_46 -> V_47 ) ;
else
V_45 = F_32 ( V_38 , V_70 , V_230 -> V_64 ) ;
V_24:
if ( V_45 < 0 )
F_44 ( V_46 ) ;
free:
if ( V_45 < 0 )
F_59 ( V_44 ) ;
return V_45 ;
}
static int T_2 F_60 ( void )
{
return F_61 ( & V_261 ) ;
}
static void T_4 F_62 ( void )
{
F_63 ( & V_261 ) ;
}
