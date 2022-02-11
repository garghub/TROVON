unsigned int F_1 ( void )
{
return V_1 ;
}
int F_2 ( T_1 V_2 , T_1 * V_3 , T_1 V_4 , unsigned V_5 )
{
int V_6 ;
int V_7 ;
struct V_8 * V_9 ;
if ( F_3 ( V_2 >= V_10 ) ) {
F_4 ( L_1 , V_11 , V_2 ) ;
return - V_12 ;
}
if ( F_3 ( ! V_13 ) ) {
F_4 ( L_2 , V_11 ) ;
return - V_12 ;
}
V_7 = V_14 [ V_2 ] . V_7 ;
if ( F_3 ( V_7 == V_15 ) ) {
F_4 ( L_3 ,
V_11 , V_2 ) ;
return - V_16 ;
}
V_9 = & V_17 [ V_7 ] ;
V_6 = F_5 ( V_9 -> V_18 , V_14 [ V_2 ] . V_19 + V_4 ,
V_3 , V_5 ) ;
if ( V_6 )
F_4 ( L_4 ,
V_11 , V_2 , V_4 , V_5 ) ;
return V_6 ;
}
int F_6 ( T_1 V_2 , T_1 * V_3 , T_1 V_4 , unsigned V_5 )
{
int V_6 ;
int V_7 ;
struct V_8 * V_9 ;
if ( F_3 ( V_2 >= V_10 ) ) {
F_4 ( L_1 , V_11 , V_2 ) ;
return - V_12 ;
}
if ( F_3 ( ! V_13 ) ) {
F_4 ( L_2 , V_11 ) ;
return - V_12 ;
}
V_7 = V_14 [ V_2 ] . V_7 ;
if ( F_3 ( V_7 == V_15 ) ) {
F_4 ( L_3 ,
V_11 , V_2 ) ;
return - V_16 ;
}
V_9 = & V_17 [ V_7 ] ;
V_6 = F_7 ( V_9 -> V_18 , V_14 [ V_2 ] . V_19 + V_4 ,
V_3 , V_5 ) ;
if ( V_6 )
F_4 ( L_5 ,
V_11 , V_2 , V_4 , V_5 ) ;
return V_6 ;
}
int F_8 ( T_1 V_2 , T_1 V_3 , T_1 V_4 )
{
return F_2 ( V_2 , & V_3 , V_4 , 1 ) ;
}
int F_9 ( T_1 V_2 , T_1 * V_3 , T_1 V_4 )
{
return F_6 ( V_2 , V_3 , V_4 , 1 ) ;
}
static int F_10 ( void )
{
int V_20 ;
V_20 = F_8 ( V_21 , V_22 ,
V_23 ) ;
if ( V_20 ) {
F_4 ( L_6 , V_20 ) ;
goto V_24;
}
V_20 = F_6 ( V_21 , ( T_1 * ) ( & V_25 ) ,
V_26 , 4 ) ;
if ( V_20 ) {
F_4 ( L_7 , V_20 ) ;
goto V_24;
}
V_20 = F_8 ( V_21 , 0x0 , V_23 ) ;
if ( V_20 )
F_4 ( L_8 , V_20 ) ;
V_24:
return V_20 ;
}
int F_11 ( void )
{
return F_12 ( V_25 ) ;
}
int F_13 ( void )
{
return F_14 ( V_25 ) ;
}
int F_15 ( void )
{
T_1 V_27 ;
int V_28 ;
F_9 ( V_29 , & V_27 , V_30 ) ;
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
F_4 ( L_9 ) ;
V_28 = - V_16 ;
break;
}
return V_28 ;
}
static struct V_34 *
F_16 ( unsigned V_35 , const char * V_36 , int V_37 ,
void * V_38 , unsigned V_39 ,
bool V_40 , int V_41 , int V_42 )
{
struct V_43 * V_44 ;
struct V_8 * V_9 = & V_17 [ V_35 ] ;
int V_45 ;
V_44 = F_17 ( V_36 , V_37 ) ;
if ( ! V_44 ) {
F_18 ( & V_9 -> V_46 -> V_47 , L_10 ) ;
V_45 = - V_48 ;
goto V_20;
}
V_44 -> V_47 . V_49 = & V_9 -> V_46 -> V_47 ;
if ( V_38 ) {
V_45 = F_19 ( V_44 , V_38 , V_39 ) ;
if ( V_45 < 0 ) {
F_18 ( & V_44 -> V_47 , L_11 ) ;
goto V_20;
}
}
if ( V_41 ) {
struct V_50 V_51 [ 2 ] = {
{ . V_52 = V_41 , . V_53 = V_54 , } ,
{ . V_52 = V_42 , . V_53 = V_54 , } ,
} ;
V_45 = F_20 ( V_44 , V_51 , V_42 ? 2 : 1 ) ;
if ( V_45 < 0 ) {
F_18 ( & V_44 -> V_47 , L_12 ) ;
goto V_20;
}
}
V_45 = F_21 ( V_44 ) ;
if ( V_45 == 0 )
F_22 ( & V_44 -> V_47 , V_40 ) ;
V_20:
if ( V_45 < 0 ) {
F_23 ( V_44 ) ;
F_24 ( & V_9 -> V_46 -> V_47 , L_13 , V_36 ) ;
return F_25 ( V_45 ) ;
}
return & V_44 -> V_47 ;
}
static inline struct V_34 * F_26 ( unsigned V_35 , const char * V_36 ,
void * V_38 , unsigned V_39 ,
bool V_40 , int V_41 , int V_42 )
{
return F_16 ( V_35 , V_36 , - 1 , V_38 , V_39 ,
V_40 , V_41 , V_42 ) ;
}
static struct V_34 *
F_27 ( int V_37 , struct V_55 * V_38 ,
struct V_56 * V_57 ,
unsigned V_58 , unsigned long V_59 )
{
unsigned V_60 ;
struct V_61 V_62 ;
if ( ! V_38 )
return NULL ;
if ( V_57 ) {
V_38 -> V_63 = V_57 ;
V_38 -> V_64 = V_58 ;
}
if ( V_38 -> V_65 ) {
struct V_61 * V_66 ;
V_66 = V_38 -> V_65 ;
V_66 -> V_59 |= V_59 ;
} else {
V_62 . V_59 = V_59 ;
V_62 . V_67 = NULL ;
V_62 . V_68 = NULL ;
V_62 . V_69 = NULL ;
V_38 -> V_65 = & V_62 ;
}
V_60 = V_14 [ V_29 ] . V_7 ;
return F_16 ( V_60 , L_14 , V_37 ,
V_38 , sizeof( * V_38 ) , false , 0 , 0 ) ;
}
static struct V_34 *
F_28 ( int V_37 , struct V_55 * V_38 ,
unsigned long V_59 )
{
return F_27 ( V_37 , V_38 , NULL , 0 , V_59 ) ;
}
static int
F_29 ( struct V_70 * V_38 , unsigned V_71 ,
unsigned long V_59 )
{
struct V_34 * V_72 ;
unsigned V_60 ;
if ( F_30 ( V_73 ) && V_38 -> V_74 ) {
V_72 = F_26 ( V_75 , L_15 ,
V_38 -> V_74 , sizeof( * V_38 -> V_74 ) ,
false , V_71 + V_76 , 0 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
}
if ( F_30 ( V_77 ) && V_38 -> V_78 ) {
V_72 = F_26 ( V_79 , L_16 ,
V_38 -> V_78 , sizeof( * V_38 -> V_78 ) ,
true , V_71 + V_80 , 0 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
}
if ( F_30 ( V_81 ) && V_38 -> V_82 &&
F_33 () ) {
V_72 = F_26 ( V_79 , L_17 ,
V_38 -> V_82 , sizeof( * V_38 -> V_82 ) ,
true , V_71 + V_83 , 0 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
}
if ( F_30 ( V_84 ) ) {
V_60 = V_14 [ V_85 ] . V_7 ;
V_72 = F_26 ( V_60 , L_18 , NULL , 0 ,
true , V_71 + V_86 , 0 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
}
if ( F_30 ( V_87 ) ) {
V_72 = F_26 ( V_75 , L_19 , NULL , 0 ,
false , 0 , 0 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
}
if ( F_30 ( V_88 ) ) {
V_72 = F_26 ( V_75 , L_20 , NULL , 0 ,
false , 0 , 0 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
}
if ( F_30 ( V_89 ) && V_38 -> V_90 &&
F_33 () ) {
static struct V_56 V_91 = {
. V_92 = L_21 ,
} ;
static struct V_56 V_93 = {
. V_92 = L_22 ,
} ;
static struct V_56 V_94 [] = {
{ . V_92 = L_23 } ,
{ . V_92 = L_24 } ,
} ;
if ( F_30 ( V_95 ) ) {
struct V_55 V_96 = {
. V_97 . V_98 =
V_99
| V_100 ,
. V_97 . V_101 =
V_102
| V_103 ,
} ;
V_72 = F_27 ( V_104 ,
& V_96 , & V_91 , 1 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_27 ( V_105 ,
& V_96 , & V_93 , 1 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_27 ( V_106 ,
& V_96 , V_94 , 2 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
}
V_72 = F_26 ( V_107 , L_25 ,
V_38 -> V_90 , sizeof( * V_38 -> V_90 ) , true ,
V_71 + V_108 ,
V_71 + V_109 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
if ( F_30 ( V_95 ) && V_72 ) {
V_91 . V_110 = V_110 ( V_72 ) ;
V_93 . V_110 = V_110 ( V_72 ) ;
V_94 [ 0 ] . V_110 = V_110 ( V_72 ) ;
}
}
if ( F_30 ( V_111 ) && V_38 -> V_90 &&
F_34 () ) {
static struct V_56 V_112 ;
int V_113 ;
if ( F_30 ( V_95 ) ) {
struct V_55 V_96 = {
. V_97 . V_98 =
V_99
| V_100 ,
. V_97 . V_101 =
V_102
| V_103 ,
} ;
if ( V_59 & V_114 ) {
V_112 . V_92 = L_26 ;
V_113 = V_115 ;
} else {
V_112 . V_92 = L_27 ;
V_113 = V_116 ;
}
V_72 = F_27 ( V_113 , & V_96 ,
& V_112 , 1 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
}
V_38 -> V_90 -> V_59 = V_59 ;
V_72 = F_26 ( V_107 , L_28 ,
V_38 -> V_90 , sizeof( * V_38 -> V_90 ) , true ,
V_71 + V_117 ,
V_71 + V_108 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
if ( F_30 ( V_95 ) && V_72 )
V_112 . V_110 = V_110 ( V_72 ) ;
} else if ( F_30 ( V_95 ) &&
F_34 () ) {
if ( V_59 & V_114 )
V_72 = F_28 ( V_115 ,
V_38 -> V_118 , V_59 ) ;
else
V_72 = F_28 ( V_116 ,
V_38 -> V_119 , V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
}
if ( F_30 ( V_120 ) && F_33 () ) {
V_72 = F_26 ( V_121 , L_29 , NULL , 0 ,
false , 0 , 0 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
}
if ( F_30 ( V_122 ) && F_33 () ) {
V_72 = F_26 ( V_121 , L_30 , NULL , 0 ,
true , V_71 + 8 + 0 , 0 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
}
if ( F_30 ( V_123 ) && V_38 -> V_124 &&
F_33 () ) {
V_72 = F_26 ( V_75 , L_31 ,
V_38 -> V_124 , sizeof( * V_38 -> V_124 ) ,
false , 0 , 0 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
}
if ( F_30 ( V_95 ) && F_33 () ) {
V_72 = F_28 ( V_125 , V_38 -> V_126 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_127 , V_38 -> V_128 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_129 , V_38 -> V_130 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_131 , V_38 -> V_132 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_133 , V_38 -> V_134 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_135 , V_38 -> V_136 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( ( V_59 & V_137 )
? V_138
: V_139 ,
V_38 -> V_140 , V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_141 , V_38 -> V_142 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_143 , V_38 -> V_144 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_145 , V_38 -> V_146 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
}
if ( F_30 ( V_95 ) && ! ( V_59 & V_147 )
&& F_33 () ) {
V_72 = F_28 ( V_148 , V_38 -> V_149 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_150 , V_38 -> V_151 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_152 , V_38 -> V_153 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_154 , V_38 -> V_155 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_156 , V_38 -> V_157 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_158 , V_38 -> V_159 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
}
if ( F_30 ( V_95 ) && F_34 () &&
! ( V_59 & V_114 ) ) {
V_72 = F_28 ( V_160 , V_38 -> V_130 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_161 , V_38 -> V_132 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_162 , V_38 -> V_163 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_164 , V_38 -> V_165 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_166 , V_38 -> V_167 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_168 , V_38 -> V_169 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_170 , V_38 -> V_171 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_172 , V_38 -> V_173 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_174 , V_38 -> V_175 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_176 , V_38 -> V_136 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_177 , V_38 -> V_155 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_178 , V_38 -> V_140 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_179 , V_38 -> V_157 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_180 , V_38 -> V_181 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
}
if ( F_30 ( V_95 ) && F_34 () ) {
V_72 = F_28 ( V_182 , V_38 -> V_183 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
}
if ( F_30 ( V_95 ) && F_34 () &&
( V_59 & V_114 ) ) {
V_72 = F_28 ( V_184 , V_38 -> V_185 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_186 , V_38 -> V_187 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_188 , V_38 -> V_189 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_190 , V_38 -> V_191 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_192 , V_38 -> V_193 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_194 , V_38 -> V_195 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_196 , V_38 -> V_197 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_198 , V_38 -> V_199 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_200 , V_38 -> V_201 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_202 , V_38 -> V_203 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
V_72 = F_28 ( V_204 , V_38 -> V_205 ,
V_59 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
}
if ( F_30 ( V_206 ) && V_38 -> V_207 &&
! ( V_59 & ( V_147 | V_208 ) ) ) {
V_72 = F_26 ( V_121 , L_32 ,
V_38 -> V_207 , sizeof( * V_38 -> V_207 ) , false ,
V_71 + V_209 ,
V_71 + V_210 ) ;
if ( F_31 ( V_72 ) )
return F_32 ( V_72 ) ;
}
return 0 ;
}
static inline int T_2 F_35 ( void )
{
int V_211 = 0 ;
V_211 = F_8 ( V_29 , 0 ,
V_212 ) ;
return V_211 ;
}
static inline int T_2 F_36 ( void )
{
int V_211 = 0 ;
V_211 |= F_8 ( V_29 , V_213 ,
V_212 ) ;
V_211 |= F_8 ( V_29 , V_214 ,
V_212 ) ;
return V_211 ;
}
static void F_37 ( struct V_34 * V_47 ,
struct V_215 * clock )
{
int V_211 = 0 ;
struct V_216 * V_217 ;
T_3 V_28 ;
T_1 V_27 = V_32 ;
V_217 = F_38 ( V_47 , L_33 ) ;
if ( F_31 ( V_217 ) ) {
F_39 ( V_218 L_34
L_35 ) ;
return;
}
V_28 = F_40 ( V_217 ) ;
F_41 ( V_217 ) ;
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
V_27 |= V_219 ;
if ( clock && clock -> V_220 )
V_27 |= V_221 ;
V_211 |= F_36 () ;
V_211 |= F_8 ( V_29 , V_27 , V_30 ) ;
V_211 |= F_35 () ;
if ( V_211 < 0 )
F_4 ( L_36 , V_11 , V_211 ) ;
}
static int F_42 ( struct V_222 * V_46 )
{
unsigned V_223 , V_224 ;
int V_45 ;
if ( F_33 () ) {
V_45 = F_43 () ;
V_224 = V_225 ;
} else {
V_45 = F_44 () ;
V_224 = V_225 - 1 ;
}
if ( V_45 < 0 )
return V_45 ;
for ( V_223 = 0 ; V_223 < V_224 ; V_223 ++ ) {
struct V_8 * V_9 = & V_17 [ V_223 ] ;
if ( V_9 -> V_46 && V_9 -> V_46 != V_46 )
F_45 ( V_9 -> V_46 ) ;
V_17 [ V_223 ] . V_46 = NULL ;
}
V_13 = false ;
return 0 ;
}
static int
F_46 ( struct V_222 * V_46 , const struct V_226 * V_227 )
{
struct V_70 * V_38 = V_46 -> V_47 . V_228 ;
struct V_229 * V_230 = V_46 -> V_47 . V_231 ;
struct V_43 * V_44 ;
struct V_232 * V_233 ;
int V_71 = 0 ;
int V_45 ;
unsigned V_223 , V_224 ;
V_44 = F_17 ( V_11 , - 1 ) ;
if ( ! V_44 ) {
F_24 ( & V_46 -> V_47 , L_37 ) ;
return - V_48 ;
}
V_45 = F_21 ( V_44 ) ;
if ( V_45 ) {
F_23 ( V_44 ) ;
return V_45 ;
}
if ( V_230 && ! V_38 ) {
V_38 = F_47 ( & V_46 -> V_47 ,
sizeof( struct V_70 ) ,
V_234 ) ;
if ( ! V_38 ) {
V_45 = - V_48 ;
goto free;
}
}
if ( ! V_38 ) {
F_18 ( & V_46 -> V_47 , L_38 ) ;
V_45 = - V_16 ;
goto free;
}
F_48 ( V_44 , V_38 ) ;
if ( F_49 ( V_46 -> V_235 , V_236 ) == 0 ) {
F_18 ( & V_46 -> V_47 , L_39 ) ;
V_45 = - V_237 ;
goto free;
}
if ( V_13 ) {
F_18 ( & V_46 -> V_47 , L_40 ) ;
V_45 = - V_238 ;
goto free;
}
if ( ( V_227 -> V_65 ) & V_239 ) {
V_1 = V_240 ;
V_14 = & V_241 [ 0 ] ;
V_233 = V_242 ;
V_224 = V_225 - 1 ;
} else {
V_1 = V_243 ;
V_14 = & V_244 [ 0 ] ;
V_233 = V_245 ;
V_224 = V_225 ;
}
for ( V_223 = 0 ; V_223 < V_224 ; V_223 ++ ) {
struct V_8 * V_9 = & V_17 [ V_223 ] ;
if ( V_223 == 0 ) {
V_9 -> V_46 = V_46 ;
} else {
V_9 -> V_46 = F_50 ( V_46 -> V_235 ,
V_46 -> V_246 + V_223 ) ;
if ( ! V_9 -> V_46 ) {
F_24 ( & V_46 -> V_47 ,
L_41 , V_223 ) ;
V_45 = - V_48 ;
goto V_24;
}
}
V_9 -> V_18 = F_51 ( V_9 -> V_46 ,
& V_233 [ V_223 ] ) ;
if ( F_31 ( V_9 -> V_18 ) ) {
V_45 = F_32 ( V_9 -> V_18 ) ;
F_24 ( & V_46 -> V_47 ,
L_42 , V_223 ,
V_45 ) ;
goto V_24;
}
}
V_13 = true ;
F_37 ( & V_44 -> V_47 , V_38 -> clock ) ;
if ( V_1 == V_243 ) {
V_45 = F_10 () ;
F_52 ( V_45 < 0 , L_43 ) ;
}
if ( F_30 ( V_247 ) && V_38 -> V_248 )
F_53 ( V_38 -> V_248 ) ;
if ( V_46 -> V_249 ) {
if ( F_33 () ) {
F_54 ( V_227 -> V_36 ) ;
V_71 = F_55 ( & V_46 -> V_47 , V_46 -> V_249 ) ;
} else {
V_71 = F_56 ( & V_46 -> V_47 , V_46 -> V_249 ) ;
}
if ( V_71 < 0 ) {
V_45 = V_71 ;
goto V_24;
}
}
if ( F_33 () ) {
T_1 V_250 ;
F_9 ( V_21 , & V_250 , V_251 ) ;
V_250 &= ~ ( V_252 | V_253 | \
V_254 | V_255 ) ;
F_8 ( V_21 , V_250 , V_251 ) ;
}
V_45 = - V_256 ;
if ( V_230 )
V_45 = F_57 ( V_230 , NULL , NULL , & V_46 -> V_47 ) ;
if ( V_45 )
V_45 = F_29 ( V_38 , V_71 , V_227 -> V_65 ) ;
V_24:
if ( V_45 < 0 )
F_42 ( V_46 ) ;
free:
if ( V_45 < 0 )
F_58 ( V_44 ) ;
return V_45 ;
}
static int T_2 F_59 ( void )
{
return F_60 ( & V_257 ) ;
}
static void T_4 F_61 ( void )
{
F_62 ( & V_257 ) ;
}
