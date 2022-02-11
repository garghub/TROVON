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
static struct V_41 *
F_16 ( unsigned V_42 , const char * V_43 , int V_44 ,
void * V_45 , unsigned V_46 ,
bool V_47 , int V_48 , int V_49 )
{
struct V_50 * V_51 ;
struct V_8 * V_9 = & V_19 [ V_42 ] ;
int V_52 ;
V_51 = F_17 ( V_43 , V_44 ) ;
if ( ! V_51 ) {
F_18 ( & V_9 -> V_28 -> V_53 , L_9 ) ;
V_52 = - V_54 ;
goto V_34;
}
F_19 ( & V_51 -> V_53 , V_47 ) ;
V_51 -> V_53 . V_55 = & V_9 -> V_28 -> V_53 ;
if ( V_45 ) {
V_52 = F_20 ( V_51 , V_45 , V_46 ) ;
if ( V_52 < 0 ) {
F_18 ( & V_51 -> V_53 , L_10 ) ;
goto V_34;
}
}
if ( V_48 ) {
struct V_56 V_57 [ 2 ] = {
{ . V_58 = V_48 , . V_25 = V_59 , } ,
{ . V_58 = V_49 , . V_25 = V_59 , } ,
} ;
V_52 = F_21 ( V_51 , V_57 , V_49 ? 2 : 1 ) ;
if ( V_52 < 0 ) {
F_18 ( & V_51 -> V_53 , L_11 ) ;
goto V_34;
}
}
V_52 = F_22 ( V_51 ) ;
V_34:
if ( V_52 < 0 ) {
F_23 ( V_51 ) ;
F_24 ( & V_9 -> V_28 -> V_53 , L_12 , V_43 ) ;
return F_25 ( V_52 ) ;
}
return & V_51 -> V_53 ;
}
static inline struct V_41 * F_26 ( unsigned V_42 , const char * V_43 ,
void * V_45 , unsigned V_46 ,
bool V_47 , int V_48 , int V_49 )
{
return F_16 ( V_42 , V_43 , - 1 , V_45 , V_46 ,
V_47 , V_48 , V_49 ) ;
}
static struct V_41 *
F_27 ( int V_44 , struct V_60 * V_45 ,
struct V_61 * V_62 ,
unsigned V_63 , unsigned long V_64 )
{
unsigned V_65 ;
struct V_66 V_67 ;
if ( ! V_45 )
return NULL ;
if ( V_62 ) {
V_45 -> V_68 = V_62 ;
V_45 -> V_69 = V_63 ;
}
if ( V_45 -> V_70 ) {
struct V_66 * V_71 ;
V_71 = V_45 -> V_70 ;
V_71 -> V_64 |= V_64 ;
} else {
V_67 . V_64 = V_64 ;
V_67 . V_72 = NULL ;
V_67 . V_73 = NULL ;
V_67 . V_74 = NULL ;
V_45 -> V_70 = & V_67 ;
}
V_65 = V_16 [ V_75 ] . V_7 ;
return F_16 ( V_65 , L_13 , V_44 ,
V_45 , sizeof( * V_45 ) , false , 0 , 0 ) ;
}
static struct V_41 *
F_28 ( int V_44 , struct V_60 * V_45 ,
unsigned long V_64 )
{
return F_27 ( V_44 , V_45 , NULL , 0 , V_64 ) ;
}
static int
F_29 ( struct V_76 * V_45 , unsigned V_77 ,
unsigned long V_64 )
{
struct V_41 * V_78 ;
unsigned V_65 ;
if ( F_30 () && V_45 -> V_79 ) {
V_78 = F_26 ( V_80 , L_14 ,
V_45 -> V_79 , sizeof( * V_45 -> V_79 ) ,
false , V_77 + V_81 , 0 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
}
if ( F_33 () && V_45 -> V_82 ) {
V_78 = F_26 ( V_83 , L_15 ,
V_45 -> V_82 , sizeof( * V_45 -> V_82 ) ,
true , V_77 + V_84 , 0 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
}
if ( F_34 () && V_45 -> V_85 ) {
V_78 = F_26 ( 2 , L_16 ,
V_45 -> V_85 , sizeof( * V_45 -> V_85 ) ,
true , V_77 + V_86 , 0 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
}
if ( F_35 () ) {
V_65 = V_16 [ V_87 ] . V_7 ;
V_78 = F_26 ( V_65 , L_17 ,
NULL , 0 ,
true , V_77 + V_88 , 0 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
}
if ( F_36 () && V_45 -> V_89 && F_37 () ) {
static struct V_61 V_90 = {
. V_91 = L_18 ,
} ;
static struct V_61 V_92 = {
. V_91 = L_19 ,
} ;
static struct V_61 V_93 = {
. V_91 = L_20 ,
} ;
if ( F_38 () ) {
struct V_60 V_94 = {
. V_95 . V_96 =
V_97
| V_98 ,
. V_95 . V_99 =
V_100
| V_101 ,
} ;
V_78 = F_27 ( V_102 ,
& V_94 , & V_90 , 1 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_27 ( V_103 ,
& V_94 , & V_92 , 1 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_27 ( V_104 ,
& V_94 , & V_93 , 1 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
}
V_78 = F_26 ( 0 , L_21 ,
V_45 -> V_89 , sizeof( * V_45 -> V_89 ) ,
true ,
V_77 + V_105 ,
V_77 + V_106 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
if ( F_38 () && V_78 ) {
V_90 . V_107 = V_107 ( V_78 ) ;
V_92 . V_107 = V_107 ( V_78 ) ;
V_93 . V_107 = V_107 ( V_78 ) ;
}
}
if ( F_36 () && V_45 -> V_89 && F_39 () ) {
static struct V_61 V_108 ;
int V_109 ;
if ( F_38 () ) {
struct V_60 V_94 = {
. V_95 . V_96 =
V_97
| V_98 ,
. V_95 . V_99 =
V_100
| V_101 ,
} ;
if ( V_64 & V_110 ) {
V_108 . V_91 = L_22 ;
V_109 = V_111 ;
} else {
V_108 . V_91 = L_23 ;
V_109 = V_112 ;
}
V_78 = F_27 ( V_109 , & V_94 ,
& V_108 , 1 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
}
V_45 -> V_89 -> V_64 = V_64 ;
V_78 = F_26 ( 0 , L_24 ,
V_45 -> V_89 , sizeof( * V_45 -> V_89 ) ,
true ,
V_77 + V_113 ,
V_77 + V_105 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
if ( F_38 () && V_78 )
V_108 . V_107 = V_107 ( V_78 ) ;
} else if ( F_38 () && F_39 () ) {
if ( V_64 & V_110 )
V_78 = F_28 ( V_111 ,
V_45 -> V_114 , V_64 ) ;
else
V_78 = F_28 ( V_112 ,
V_45 -> V_115 , V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
}
if ( F_40 () && F_37 () ) {
V_78 = F_26 ( 0 , L_25 , NULL , 0 , false , 0 , 0 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
}
if ( F_41 () && F_37 () ) {
V_78 = F_26 ( 1 , L_26 ,
NULL , 0 , true , V_77 + 8 + 0 , 0 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
}
if ( F_42 () && V_45 -> V_116 && F_37 () ) {
V_65 = V_16 [ V_117 ] . V_7 ;
V_78 = F_26 ( V_65 , L_27 ,
V_45 -> V_116 , sizeof( * V_45 -> V_116 ) ,
false , 0 , 0 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
}
if ( F_38 () && F_37 () ) {
V_78 = F_28 ( V_118 , V_45 -> V_119 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_120 , V_45 -> V_121 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_122 , V_45 -> V_123 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_124 , V_45 -> V_125 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_126 , V_45 -> V_127 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_128 , V_45 -> V_129 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( ( V_64 & V_130 )
? V_131
: V_132 ,
V_45 -> V_133 , V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_134 , V_45 -> V_135 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_136 , V_45 -> V_137 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_138 , V_45 -> V_139 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
}
if ( F_38 () && ! ( V_64 & V_140 )
&& F_37 () ) {
V_78 = F_28 ( V_141 , V_45 -> V_142 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_143 , V_45 -> V_144 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_145 , V_45 -> V_146 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_147 , V_45 -> V_148 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_149 , V_45 -> V_150 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_151 , V_45 -> V_152 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
}
if ( F_38 () && F_39 () &&
! ( V_64 & V_110 ) ) {
V_78 = F_28 ( V_153 , V_45 -> V_123 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_154 , V_45 -> V_125 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_155 , V_45 -> V_156 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_157 , V_45 -> V_158 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_159 , V_45 -> V_160 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_161 , V_45 -> V_162 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_163 , V_45 -> V_164 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_165 , V_45 -> V_166 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_167 , V_45 -> V_168 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_169 , V_45 -> V_129 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_170 , V_45 -> V_148 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_171 , V_45 -> V_133 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_172 , V_45 -> V_150 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_173 , V_45 -> V_174 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
}
if ( F_38 () && F_39 () ) {
V_78 = F_28 ( V_175 , V_45 -> V_176 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
}
if ( F_38 () && F_39 () &&
( V_64 & V_110 ) ) {
V_78 = F_28 ( V_177 , V_45 -> V_178 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_179 , V_45 -> V_180 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_181 , V_45 -> V_182 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_183 , V_45 -> V_184 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_185 , V_45 -> V_186 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_187 , V_45 -> V_188 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_189 , V_45 -> V_190 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_191 , V_45 -> V_192 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_193 , V_45 -> V_194 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_195 , V_45 -> V_196 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_78 = F_28 ( V_197 , V_45 -> V_198 ,
V_64 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
}
if ( F_43 () && V_45 -> V_199 &&
! ( V_64 & ( V_140 | V_200 ) ) ) {
V_78 = F_26 ( 3 , L_28 ,
V_45 -> V_199 , sizeof( * V_45 -> V_199 ) , false ,
V_77 + V_201 ,
V_77 + V_202 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
}
return 0 ;
}
static inline int T_2 F_44 ( void )
{
int V_203 = 0 ;
V_203 = F_9 ( V_204 , 0 ,
V_205 ) ;
return V_203 ;
}
static inline int T_2 F_45 ( void )
{
int V_203 = 0 ;
V_203 |= F_9 ( V_204 ,
V_206 ,
V_205 ) ;
V_203 |= F_9 ( V_204 ,
V_207 ,
V_205 ) ;
return V_203 ;
}
static void F_46 ( struct V_41 * V_53 ,
struct V_208 * clock )
{
int V_203 = 0 ;
struct V_209 * V_210 ;
T_3 V_211 ;
T_1 V_212 = V_213 ;
#if F_47 ( V_214 ) || F_47 ( V_215 )
if ( F_48 () )
V_210 = F_49 ( V_53 , L_29 ) ;
else
V_210 = F_49 ( V_53 , L_30 ) ;
if ( F_31 ( V_210 ) ) {
F_50 ( V_216 L_31
L_32 ) ;
return;
}
V_211 = F_51 ( V_210 ) ;
F_52 ( V_210 ) ;
#else
V_210 = F_25 ( - V_30 ) ;
F_50 ( V_216 L_31
L_32 ) ;
return;
#endif
switch ( V_211 ) {
case 19200000 :
V_212 = V_217 ;
break;
case 26000000 :
V_212 = V_213 ;
break;
case 38400000 :
V_212 = V_218 ;
break;
}
V_212 |= V_219 ;
if ( clock && clock -> V_220 )
V_212 |= V_221 ;
V_203 |= F_45 () ;
V_203 |= F_9 ( V_75 , V_212 , V_222 ) ;
V_203 |= F_44 () ;
if ( V_203 < 0 )
F_4 ( L_33 , V_13 , V_203 ) ;
}
static int F_53 ( struct V_223 * V_28 )
{
unsigned V_224 , V_225 ;
int V_52 ;
if ( F_37 () ) {
V_52 = F_54 () ;
V_225 = V_226 ;
} else {
V_52 = F_55 () ;
V_225 = V_226 - 1 ;
}
if ( V_52 < 0 )
return V_52 ;
for ( V_224 = 0 ; V_224 < V_225 ; V_224 ++ ) {
struct V_8 * V_9 = & V_19 [ V_224 ] ;
if ( V_9 -> V_28 && V_9 -> V_28 != V_28 )
F_56 ( V_9 -> V_28 ) ;
V_19 [ V_224 ] . V_28 = NULL ;
}
V_15 = false ;
return 0 ;
}
static int T_4
F_57 ( struct V_223 * V_28 , const struct V_227 * V_228 )
{
struct V_76 * V_45 = V_28 -> V_53 . V_229 ;
struct V_230 * V_231 = V_28 -> V_53 . V_232 ;
int V_77 = 0 ;
int V_52 ;
unsigned V_224 , V_225 ;
if ( V_231 && ! V_45 ) {
V_45 = F_58 ( & V_28 -> V_53 ,
sizeof( struct V_76 ) ,
V_233 ) ;
if ( ! V_45 )
return - V_54 ;
}
if ( ! V_45 ) {
F_18 ( & V_28 -> V_53 , L_34 ) ;
return - V_18 ;
}
if ( F_59 ( V_28 -> V_29 , V_234 ) == 0 ) {
F_18 ( & V_28 -> V_53 , L_35 ) ;
return - V_30 ;
}
if ( V_15 ) {
F_18 ( & V_28 -> V_53 , L_36 ) ;
return - V_235 ;
}
if ( ( V_228 -> V_70 ) & V_236 ) {
V_1 = V_237 ;
V_16 = & V_238 [ 0 ] ;
V_225 = V_226 - 1 ;
} else {
V_1 = V_239 ;
V_16 = & V_240 [ 0 ] ;
V_225 = V_226 ;
}
for ( V_224 = 0 ; V_224 < V_225 ; V_224 ++ ) {
struct V_8 * V_9 = & V_19 [ V_224 ] ;
V_9 -> V_23 = V_28 -> V_22 + V_224 ;
if ( V_224 == 0 ) {
V_9 -> V_28 = V_28 ;
} else {
V_9 -> V_28 = F_60 ( V_28 -> V_29 ,
V_9 -> V_23 ) ;
if ( ! V_9 -> V_28 ) {
F_24 ( & V_28 -> V_53 ,
L_37 , V_224 ) ;
V_52 = - V_54 ;
goto V_38;
}
}
F_61 ( & V_9 -> V_20 ) ;
}
V_15 = true ;
F_46 ( & V_28 -> V_53 , V_45 -> clock ) ;
if ( V_1 == V_239 ) {
V_52 = F_11 () ;
F_62 ( V_52 < 0 , L_38 ) ;
}
if ( F_63 () && V_45 -> V_241 )
F_64 ( V_45 -> V_241 ) ;
if ( V_28 -> V_242 ) {
if ( F_37 () ) {
F_65 ( V_228 -> V_43 ) ;
V_77 = F_66 ( & V_28 -> V_53 , V_28 -> V_242 ) ;
} else {
V_77 = F_67 ( & V_28 -> V_53 , V_28 -> V_242 ) ;
}
if ( V_77 < 0 ) {
V_52 = V_77 ;
goto V_38;
}
}
if ( F_37 () ) {
T_1 V_243 ;
F_10 ( V_35 , & V_243 , V_244 ) ;
V_243 &= ~ ( V_245 | V_246 | \
V_247 | V_248 ) ;
F_9 ( V_35 , V_243 , V_244 ) ;
}
V_52 = - V_249 ;
if ( V_231 )
V_52 = F_68 ( V_231 , NULL , NULL , & V_28 -> V_53 ) ;
if ( V_52 )
V_52 = F_29 ( V_45 , V_77 , V_228 -> V_70 ) ;
V_38:
if ( V_52 < 0 )
F_53 ( V_28 ) ;
return V_52 ;
}
static int T_2 F_69 ( void )
{
return F_70 ( & V_250 ) ;
}
static void T_5 F_71 ( void )
{
F_72 ( & V_250 ) ;
}
