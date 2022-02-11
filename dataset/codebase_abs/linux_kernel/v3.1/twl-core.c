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
V_7 = V_15 [ V_2 ] . V_7 ;
V_9 = & V_16 [ V_7 ] ;
if ( F_3 ( ! V_17 ) ) {
F_4 ( L_2 , V_13 , V_7 ) ;
return - V_14 ;
}
F_5 ( & V_9 -> V_18 ) ;
V_11 = & V_9 -> V_19 [ 0 ] ;
V_11 -> V_20 = V_9 -> V_21 ;
V_11 -> V_22 = V_5 + 1 ;
V_11 -> V_23 = 0 ;
V_11 -> V_24 = V_3 ;
* V_3 = V_15 [ V_2 ] . V_25 + V_4 ;
V_6 = F_6 ( V_9 -> V_26 -> V_27 , V_9 -> V_19 , 1 ) ;
F_7 ( & V_9 -> V_18 ) ;
if ( V_6 != 1 ) {
F_4 ( L_3 ,
V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
else
return - V_28 ;
} else {
return 0 ;
}
}
int F_8 ( T_1 V_2 , T_1 * V_3 , T_1 V_4 , unsigned V_5 )
{
int V_6 ;
T_1 V_29 ;
int V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
if ( F_3 ( V_2 > V_12 ) ) {
F_4 ( L_1 , V_13 , V_2 ) ;
return - V_14 ;
}
V_7 = V_15 [ V_2 ] . V_7 ;
V_9 = & V_16 [ V_7 ] ;
if ( F_3 ( ! V_17 ) ) {
F_4 ( L_2 , V_13 , V_7 ) ;
return - V_14 ;
}
F_5 ( & V_9 -> V_18 ) ;
V_11 = & V_9 -> V_19 [ 0 ] ;
V_11 -> V_20 = V_9 -> V_21 ;
V_11 -> V_22 = 1 ;
V_11 -> V_23 = 0 ;
V_29 = V_15 [ V_2 ] . V_25 + V_4 ;
V_11 -> V_24 = & V_29 ;
V_11 = & V_9 -> V_19 [ 1 ] ;
V_11 -> V_20 = V_9 -> V_21 ;
V_11 -> V_23 = V_30 ;
V_11 -> V_22 = V_5 ;
V_11 -> V_24 = V_3 ;
V_6 = F_6 ( V_9 -> V_26 -> V_27 , V_9 -> V_19 , 2 ) ;
F_7 ( & V_9 -> V_18 ) ;
if ( V_6 != 2 ) {
F_4 ( L_4 ,
V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
else
return - V_28 ;
} else {
return 0 ;
}
}
int F_9 ( T_1 V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_31 [ 2 ] = { 0 } ;
V_31 [ 1 ] = V_3 ;
return F_2 ( V_2 , V_31 , V_4 , 1 ) ;
}
int F_10 ( T_1 V_2 , T_1 * V_3 , T_1 V_4 )
{
return F_8 ( V_2 , V_3 , V_4 , 1 ) ;
}
static int F_11 ( void )
{
int V_32 ;
V_32 = F_9 ( V_33 , V_34 ,
V_35 ) ;
if ( V_32 ) {
F_4 ( L_5 , V_32 ) ;
goto V_36;
}
V_32 = F_8 ( V_33 , ( T_1 * ) ( & V_37 ) ,
V_38 , 4 ) ;
if ( V_32 ) {
F_4 ( L_6 , V_32 ) ;
goto V_36;
}
V_32 = F_9 ( V_33 , 0x0 , V_35 ) ;
if ( V_32 )
F_4 ( L_7 , V_32 ) ;
V_36:
return V_32 ;
}
int F_12 ( void )
{
return F_13 ( V_37 ) ;
}
int F_14 ( void )
{
return F_15 ( V_37 ) ;
}
static struct V_39 *
F_16 ( unsigned V_40 , const char * V_41 , int V_42 ,
void * V_43 , unsigned V_44 ,
bool V_45 , int V_46 , int V_47 )
{
struct V_48 * V_49 ;
struct V_8 * V_9 = & V_16 [ V_40 ] ;
int V_50 ;
V_49 = F_17 ( V_41 , V_42 ) ;
if ( ! V_49 ) {
F_18 ( & V_9 -> V_26 -> V_51 , L_8 ) ;
V_50 = - V_52 ;
goto V_32;
}
F_19 ( & V_49 -> V_51 , V_45 ) ;
V_49 -> V_51 . V_53 = & V_9 -> V_26 -> V_51 ;
if ( V_43 ) {
V_50 = F_20 ( V_49 , V_43 , V_44 ) ;
if ( V_50 < 0 ) {
F_18 ( & V_49 -> V_51 , L_9 ) ;
goto V_32;
}
}
if ( V_46 ) {
struct V_54 V_55 [ 2 ] = {
{ . V_56 = V_46 , . V_23 = V_57 , } ,
{ . V_56 = V_47 , . V_23 = V_57 , } ,
} ;
V_50 = F_21 ( V_49 , V_55 , V_47 ? 2 : 1 ) ;
if ( V_50 < 0 ) {
F_18 ( & V_49 -> V_51 , L_10 ) ;
goto V_32;
}
}
V_50 = F_22 ( V_49 ) ;
V_32:
if ( V_50 < 0 ) {
F_23 ( V_49 ) ;
F_24 ( & V_9 -> V_26 -> V_51 , L_11 , V_41 ) ;
return F_25 ( V_50 ) ;
}
return & V_49 -> V_51 ;
}
static inline struct V_39 * F_26 ( unsigned V_40 , const char * V_41 ,
void * V_43 , unsigned V_44 ,
bool V_45 , int V_46 , int V_47 )
{
return F_16 ( V_40 , V_41 , - 1 , V_43 , V_44 ,
V_45 , V_46 , V_47 ) ;
}
static struct V_39 *
F_27 ( int V_42 , struct V_58 * V_43 ,
struct V_59 * V_60 ,
unsigned V_61 , unsigned long V_62 )
{
unsigned V_63 ;
if ( ! V_43 )
return NULL ;
if ( V_60 ) {
V_43 -> V_64 = V_60 ;
V_43 -> V_65 = V_61 ;
}
V_43 -> V_66 = ( void * ) V_62 ;
V_63 = V_15 [ V_67 ] . V_7 ;
return F_16 ( V_63 , L_12 , V_42 ,
V_43 , sizeof( * V_43 ) , false , 0 , 0 ) ;
}
static struct V_39 *
F_28 ( int V_42 , struct V_58 * V_43 ,
unsigned long V_62 )
{
return F_27 ( V_42 , V_43 , NULL , 0 , V_62 ) ;
}
static int
F_29 ( struct V_68 * V_43 , unsigned long V_62 )
{
struct V_39 * V_69 ;
unsigned V_63 ;
if ( F_30 () && V_43 -> V_70 ) {
V_69 = F_26 ( V_71 , L_13 ,
V_43 -> V_70 , sizeof( * V_43 -> V_70 ) ,
false , V_43 -> V_72 + V_73 , 0 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
}
if ( F_33 () && V_43 -> V_74 ) {
V_69 = F_26 ( V_75 , L_14 ,
V_43 -> V_74 , sizeof( * V_43 -> V_74 ) ,
true , V_43 -> V_72 + V_76 , 0 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
}
if ( F_34 () && V_43 -> V_77 ) {
V_69 = F_26 ( 2 , L_15 ,
V_43 -> V_77 , sizeof( * V_43 -> V_77 ) ,
true , V_43 -> V_72 + V_78 , 0 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
}
if ( F_35 () ) {
V_63 = V_15 [ V_79 ] . V_7 ;
V_69 = F_26 ( V_63 , L_16 ,
NULL , 0 ,
true , V_43 -> V_72 + V_80 , 0 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
}
if ( F_36 () && V_43 -> V_81 && F_37 () ) {
static struct V_59 V_82 = {
. V_83 = L_17 ,
} ;
static struct V_59 V_84 = {
. V_83 = L_18 ,
} ;
static struct V_59 V_85 = {
. V_83 = L_19 ,
} ;
if ( F_38 () ) {
struct V_58 V_86 = {
. V_87 . V_88 =
V_89
| V_90 ,
. V_87 . V_91 =
V_92
| V_93 ,
} ;
V_69 = F_27 ( V_94 ,
& V_86 , & V_82 , 1 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_27 ( V_95 ,
& V_86 , & V_84 , 1 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_27 ( V_96 ,
& V_86 , & V_85 , 1 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
}
V_69 = F_26 ( 0 , L_20 ,
V_43 -> V_81 , sizeof( * V_43 -> V_81 ) ,
true ,
V_43 -> V_72 + V_97 ,
V_43 -> V_72 + V_98 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
if ( F_38 () && V_69 ) {
V_82 . V_51 = V_69 ;
V_84 . V_51 = V_69 ;
V_85 . V_51 = V_69 ;
}
}
if ( F_36 () && V_43 -> V_81 && F_39 () ) {
static struct V_59 V_99 ;
int V_100 ;
if ( F_38 () ) {
struct V_58 V_86 = {
. V_87 . V_88 =
V_89
| V_90 ,
. V_87 . V_91 =
V_92
| V_93 ,
} ;
if ( V_62 & V_101 ) {
V_99 . V_83 = L_21 ;
V_100 = V_102 ;
} else {
V_99 . V_83 = L_22 ;
V_100 = V_103 ;
}
V_69 = F_27 ( V_100 , & V_86 ,
& V_99 , 1 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
}
V_43 -> V_81 -> V_62 = V_62 ;
V_69 = F_26 ( 0 , L_23 ,
V_43 -> V_81 , sizeof( * V_43 -> V_81 ) ,
true ,
V_43 -> V_72 + V_104 ,
V_43 -> V_72 + V_97 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
if ( F_38 () && V_69 )
V_99 . V_51 = V_69 ;
} else if ( F_38 () && F_39 () ) {
if ( V_62 & V_101 )
V_69 = F_28 ( V_102 ,
V_43 -> V_105 , V_62 ) ;
else
V_69 = F_28 ( V_103 ,
V_43 -> V_106 , V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
}
if ( F_40 () && F_37 () ) {
V_69 = F_26 ( 0 , L_24 , NULL , 0 , false , 0 , 0 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
}
if ( F_41 () && F_37 () ) {
V_69 = F_26 ( 1 , L_25 ,
NULL , 0 , true , V_43 -> V_72 + 8 + 0 , 0 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
}
if ( F_42 () && V_43 -> V_107 && F_37 () ) {
V_63 = V_15 [ V_108 ] . V_7 ;
V_69 = F_26 ( V_63 , L_26 ,
V_43 -> V_107 , sizeof( * V_43 -> V_107 ) ,
false , 0 , 0 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
}
if ( F_42 () && V_43 -> V_107 && F_39 () ) {
V_63 = V_15 [ V_108 ] . V_7 ;
V_69 = F_26 ( V_63 , L_27 ,
V_43 -> V_107 , sizeof( * V_43 -> V_107 ) ,
false , 0 , 0 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
}
if ( F_38 () && F_37 () ) {
V_69 = F_28 ( V_109 , V_43 -> V_110 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_111 , V_43 -> V_112 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_113 , V_43 -> V_114 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_115 , V_43 -> V_116 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_117 , V_43 -> V_118 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_119 , V_43 -> V_120 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( ( V_62 & V_121 )
? V_122
: V_123 ,
V_43 -> V_124 , V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_125 , V_43 -> V_126 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_127 , V_43 -> V_128 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_129 , V_43 -> V_130 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
}
if ( F_38 () && ! ( V_62 & V_131 )
&& F_37 () ) {
V_69 = F_28 ( V_132 , V_43 -> V_133 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_134 , V_43 -> V_135 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_136 , V_43 -> V_137 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_138 , V_43 -> V_139 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_140 , V_43 -> V_141 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_142 , V_43 -> V_143 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
}
if ( F_38 () && F_39 () &&
! ( V_62 & V_101 ) ) {
V_69 = F_28 ( V_144 , V_43 -> V_145 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_146 , V_43 -> V_147 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_148 , V_43 -> V_149 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_150 , V_43 -> V_151 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_152 , V_43 -> V_120 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_153 , V_43 -> V_139 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_154 , V_43 -> V_124 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_155 , V_43 -> V_141 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_156 , V_43 -> V_157 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
}
if ( F_38 () && F_39 () ) {
V_69 = F_28 ( V_158 , V_43 -> V_159 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
}
if ( F_38 () && F_39 () &&
( V_62 & V_101 ) ) {
V_69 = F_28 ( V_160 , V_43 -> V_161 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_162 , V_43 -> V_163 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_164 , V_43 -> V_165 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_166 , V_43 -> V_167 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_168 , V_43 -> V_169 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_170 , V_43 -> V_171 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_172 , V_43 -> V_173 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_174 , V_43 -> V_175 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_176 , V_43 -> V_177 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_178 , V_43 -> V_179 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
V_69 = F_28 ( V_180 , V_43 -> V_181 ,
V_62 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
}
if ( F_43 () && V_43 -> V_182 &&
! ( V_62 & ( V_131 | V_183 ) ) ) {
V_69 = F_26 ( 3 , L_28 ,
V_43 -> V_182 , sizeof( * V_43 -> V_182 ) , false ,
V_43 -> V_72 + V_184 ,
V_43 -> V_72 + V_185 ) ;
if ( F_31 ( V_69 ) )
return F_32 ( V_69 ) ;
}
return 0 ;
}
static inline int T_2 F_44 ( void )
{
int V_186 = 0 ;
V_186 = F_9 ( V_187 , 0 ,
V_188 ) ;
return V_186 ;
}
static inline int T_2 F_45 ( void )
{
int V_186 = 0 ;
V_186 |= F_9 ( V_187 ,
V_189 ,
V_188 ) ;
V_186 |= F_9 ( V_187 ,
V_190 ,
V_188 ) ;
return V_186 ;
}
static void F_46 ( struct V_39 * V_51 ,
struct V_191 * clock )
{
int V_186 = 0 ;
struct V_192 * V_193 ;
T_3 V_194 ;
T_1 V_195 = V_196 ;
#if F_47 ( V_197 ) || F_47 ( V_198 )
if ( F_48 () )
V_193 = F_49 ( V_51 , L_29 ) ;
else
V_193 = F_49 ( V_51 , L_30 ) ;
if ( F_31 ( V_193 ) ) {
F_50 ( V_199 L_31
L_32 ) ;
return;
}
V_194 = F_51 ( V_193 ) ;
F_52 ( V_193 ) ;
#else
V_193 = F_25 ( - V_28 ) ;
F_50 ( V_199 L_31
L_32 ) ;
return;
#endif
switch ( V_194 ) {
case 19200000 :
V_195 = V_200 ;
break;
case 26000000 :
V_195 = V_196 ;
break;
case 38400000 :
V_195 = V_201 ;
break;
}
V_195 |= V_202 ;
if ( clock && clock -> V_203 )
V_195 |= V_204 ;
V_186 |= F_45 () ;
V_186 |= F_9 ( V_67 , V_195 , V_205 ) ;
V_186 |= F_44 () ;
if ( V_186 < 0 )
F_4 ( L_33 , V_13 , V_186 ) ;
}
static int F_53 ( struct V_206 * V_26 )
{
unsigned V_207 ;
int V_50 ;
if ( F_37 () )
V_50 = F_54 () ;
else
V_50 = F_55 () ;
if ( V_50 < 0 )
return V_50 ;
for ( V_207 = 0 ; V_207 < V_208 ; V_207 ++ ) {
struct V_8 * V_9 = & V_16 [ V_207 ] ;
if ( V_9 -> V_26 && V_9 -> V_26 != V_26 )
F_56 ( V_9 -> V_26 ) ;
V_16 [ V_207 ] . V_26 = NULL ;
}
V_17 = false ;
return 0 ;
}
static int T_4
F_57 ( struct V_206 * V_26 , const struct V_209 * V_210 )
{
int V_50 ;
unsigned V_207 ;
struct V_68 * V_43 = V_26 -> V_51 . V_211 ;
T_1 V_212 ;
int V_6 = 0 ;
if ( ! V_43 ) {
F_18 ( & V_26 -> V_51 , L_34 ) ;
return - V_213 ;
}
if ( F_58 ( V_26 -> V_27 , V_214 ) == 0 ) {
F_18 ( & V_26 -> V_51 , L_35 ) ;
return - V_28 ;
}
if ( V_17 ) {
F_18 ( & V_26 -> V_51 , L_36 ) ;
return - V_215 ;
}
for ( V_207 = 0 ; V_207 < V_208 ; V_207 ++ ) {
struct V_8 * V_9 = & V_16 [ V_207 ] ;
V_9 -> V_21 = V_26 -> V_20 + V_207 ;
if ( V_207 == 0 )
V_9 -> V_26 = V_26 ;
else {
V_9 -> V_26 = F_59 ( V_26 -> V_27 ,
V_9 -> V_21 ) ;
if ( ! V_9 -> V_26 ) {
F_24 ( & V_26 -> V_51 ,
L_37 , V_207 ) ;
V_50 = - V_52 ;
goto V_36;
}
}
F_60 ( & V_9 -> V_18 ) ;
}
V_17 = true ;
if ( ( V_210 -> V_66 ) & V_216 ) {
V_1 = V_217 ;
V_15 = & V_218 [ 0 ] ;
} else {
V_1 = V_219 ;
V_15 = & V_220 [ 0 ] ;
}
F_46 ( & V_26 -> V_51 , V_43 -> clock ) ;
if ( V_1 == V_219 ) {
V_6 = F_11 () ;
F_61 ( V_6 < 0 , L_38 ) ;
}
if ( F_62 () && V_43 -> V_221 )
F_63 ( V_43 -> V_221 ) ;
if ( V_26 -> V_222
&& V_43 -> V_72
&& V_43 -> V_223 > V_43 -> V_72 ) {
if ( F_37 () ) {
F_64 ( V_210 -> V_41 ) ;
V_50 = F_65 ( V_26 -> V_222 , V_43 -> V_72 ,
V_43 -> V_223 ) ;
} else {
V_50 = F_66 ( V_26 -> V_222 , V_43 -> V_72 ,
V_43 -> V_223 ) ;
}
if ( V_50 < 0 )
goto V_36;
}
if ( F_37 () ) {
F_10 ( V_33 , & V_212 , V_224 ) ;
V_212 &= ~ ( V_225 | V_226 | \
V_227 | V_228 ) ;
F_9 ( V_33 , V_212 , V_224 ) ;
}
V_50 = F_29 ( V_43 , V_210 -> V_66 ) ;
V_36:
if ( V_50 < 0 )
F_53 ( V_26 ) ;
return V_50 ;
}
static int T_2 F_67 ( void )
{
return F_68 ( & V_229 ) ;
}
static void T_5 F_69 ( void )
{
F_70 ( & V_229 ) ;
}
