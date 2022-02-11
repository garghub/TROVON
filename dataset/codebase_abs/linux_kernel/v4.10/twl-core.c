static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case 0x00 :
case 0x03 :
case 0x40 :
case 0x41 :
case 0x42 :
return false ;
default:
return true ;
}
}
static inline int F_2 ( void )
{
if ( F_3 () )
return 4 ;
else
return 3 ;
}
static inline int F_4 ( void )
{
if ( F_3 () )
return V_4 ;
else
return V_5 ;
}
unsigned int F_5 ( void )
{
return V_6 ? V_6 -> V_7 : 0 ;
}
static struct V_8 * F_6 ( T_1 V_9 )
{
int V_10 ;
struct V_11 * V_12 ;
if ( F_7 ( ! V_6 || ! V_6 -> V_13 ) ) {
F_8 ( L_1 , V_14 ) ;
return NULL ;
}
if ( F_7 ( V_9 >= F_4 () ) ) {
F_8 ( L_2 , V_14 , V_9 ) ;
return NULL ;
}
V_10 = V_6 -> V_15 [ V_9 ] . V_10 ;
V_12 = & V_6 -> V_16 [ V_10 ] ;
return V_12 -> V_8 ;
}
int F_9 ( T_1 V_9 , T_1 * V_17 , T_1 V_3 , unsigned V_18 )
{
struct V_8 * V_8 = F_6 ( V_9 ) ;
int V_19 ;
if ( ! V_8 )
return - V_20 ;
V_19 = F_10 ( V_8 , V_6 -> V_15 [ V_9 ] . V_21 + V_3 ,
V_17 , V_18 ) ;
if ( V_19 )
F_8 ( L_3 ,
V_14 , V_9 , V_3 , V_18 ) ;
return V_19 ;
}
int F_11 ( T_1 V_9 , T_1 * V_17 , T_1 V_3 , unsigned V_18 )
{
struct V_8 * V_8 = F_6 ( V_9 ) ;
int V_19 ;
if ( ! V_8 )
return - V_20 ;
V_19 = F_12 ( V_8 , V_6 -> V_15 [ V_9 ] . V_21 + V_3 ,
V_17 , V_18 ) ;
if ( V_19 )
F_8 ( L_4 ,
V_14 , V_9 , V_3 , V_18 ) ;
return V_19 ;
}
int F_13 ( T_1 V_9 , bool V_22 )
{
struct V_8 * V_8 = F_6 ( V_9 ) ;
if ( ! V_8 )
return - V_20 ;
F_14 ( V_8 , V_22 ) ;
return 0 ;
}
static int F_15 ( void )
{
int V_23 ;
V_23 = F_16 ( V_24 , V_25 ,
V_26 ) ;
if ( V_23 ) {
F_8 ( L_5 , V_23 ) ;
goto V_27;
}
V_23 = F_11 ( V_24 , ( T_1 * ) ( & V_6 -> V_28 ) ,
V_29 , 4 ) ;
if ( V_23 ) {
F_8 ( L_6 , V_23 ) ;
goto V_27;
}
V_23 = F_16 ( V_24 , 0x0 , V_26 ) ;
if ( V_23 )
F_8 ( L_7 , V_23 ) ;
V_27:
return V_23 ;
}
int F_17 ( void )
{
return F_18 ( V_6 -> V_28 ) ;
}
int F_19 ( void )
{
return F_20 ( V_6 -> V_28 ) ;
}
int F_21 ( void )
{
T_1 V_30 ;
int V_31 ;
F_22 ( V_32 , & V_30 , V_33 ) ;
switch ( V_30 & 0x3 ) {
case V_34 :
V_31 = 19200000 ;
break;
case V_35 :
V_31 = 26000000 ;
break;
case V_36 :
V_31 = 38400000 ;
break;
default:
F_8 ( L_8 ) ;
V_31 = - V_37 ;
break;
}
return V_31 ;
}
static struct V_1 *
F_23 ( unsigned V_9 , const char * V_38 , int V_39 ,
void * V_40 , unsigned V_41 ,
bool V_42 , int V_43 , int V_44 )
{
struct V_45 * V_46 ;
struct V_11 * V_12 ;
int V_47 , V_10 ;
if ( F_7 ( V_9 >= F_4 () ) ) {
F_8 ( L_2 , V_14 , V_9 ) ;
return F_24 ( - V_20 ) ;
}
V_10 = V_6 -> V_15 [ V_9 ] . V_10 ;
V_12 = & V_6 -> V_16 [ V_10 ] ;
V_46 = F_25 ( V_38 , V_39 ) ;
if ( ! V_46 )
return F_24 ( - V_48 ) ;
V_46 -> V_2 . V_49 = & V_12 -> V_50 -> V_2 ;
if ( V_40 ) {
V_47 = F_26 ( V_46 , V_40 , V_41 ) ;
if ( V_47 < 0 ) {
F_27 ( & V_46 -> V_2 , L_9 ) ;
goto V_51;
}
}
if ( V_43 ) {
struct V_52 V_53 [ 2 ] = {
{ . V_54 = V_43 , . V_55 = V_56 , } ,
{ . V_54 = V_44 , . V_55 = V_56 , } ,
} ;
V_47 = F_28 ( V_46 , V_53 , V_44 ? 2 : 1 ) ;
if ( V_47 < 0 ) {
F_27 ( & V_46 -> V_2 , L_10 ) ;
goto V_51;
}
}
V_47 = F_29 ( V_46 ) ;
if ( V_47 )
goto V_51;
F_30 ( & V_46 -> V_2 , V_42 ) ;
return & V_46 -> V_2 ;
V_51:
F_31 ( V_46 ) ;
F_32 ( & V_12 -> V_50 -> V_2 , L_11 , V_38 ) ;
return F_24 ( V_47 ) ;
}
static inline struct V_1 * F_33 ( unsigned V_9 , const char * V_38 ,
void * V_40 , unsigned V_41 ,
bool V_42 , int V_43 , int V_44 )
{
return F_23 ( V_9 , V_38 , - 1 , V_40 , V_41 ,
V_42 , V_43 , V_44 ) ;
}
static struct V_1 *
F_34 ( int V_39 , struct V_57 * V_40 ,
struct V_58 * V_59 ,
unsigned V_60 , unsigned long V_61 )
{
struct V_62 V_63 ;
if ( ! V_40 )
return NULL ;
if ( V_59 ) {
V_40 -> V_64 = V_59 ;
V_40 -> V_65 = V_60 ;
}
if ( V_40 -> V_66 ) {
struct V_62 * V_67 ;
V_67 = V_40 -> V_66 ;
V_67 -> V_61 |= V_61 ;
} else {
V_63 . V_61 = V_61 ;
V_63 . V_68 = NULL ;
V_63 . V_69 = NULL ;
V_63 . V_70 = NULL ;
V_40 -> V_66 = & V_63 ;
}
return F_23 ( V_32 , L_12 , V_39 ,
V_40 , sizeof( * V_40 ) , false , 0 , 0 ) ;
}
static struct V_1 *
F_35 ( int V_39 , struct V_57 * V_40 ,
unsigned long V_61 )
{
return F_34 ( V_39 , V_40 , NULL , 0 , V_61 ) ;
}
static int
F_36 ( struct V_71 * V_40 , unsigned V_72 ,
unsigned long V_61 )
{
struct V_1 * V_73 ;
if ( F_37 ( V_74 ) && V_40 -> V_75 ) {
V_73 = F_33 ( V_76 , L_13 ,
V_40 -> V_75 , sizeof( * V_40 -> V_75 ) ,
false , V_72 + V_77 , 0 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
}
if ( F_37 ( V_78 ) && V_40 -> V_79 ) {
V_73 = F_33 ( V_80 , L_14 ,
V_40 -> V_79 , sizeof( * V_40 -> V_79 ) ,
true , V_72 + V_81 , 0 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
}
if ( F_37 ( V_82 ) && V_40 -> V_83 &&
F_3 () ) {
V_73 = F_33 ( V_84 , L_15 ,
V_40 -> V_83 , sizeof( * V_40 -> V_83 ) ,
true , V_72 + V_85 , 0 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
}
if ( F_37 ( V_86 ) ) {
V_73 = F_33 ( V_87 , L_16 , NULL , 0 ,
true , V_72 + V_88 , 0 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
}
if ( F_37 ( V_89 ) ) {
V_73 = F_33 ( V_90 , L_17 , NULL , 0 ,
false , 0 , 0 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
}
if ( F_37 ( V_91 ) ) {
V_73 = F_33 ( V_92 , L_18 , NULL , 0 ,
false , 0 , 0 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
}
if ( F_37 ( V_93 ) && V_40 -> V_94 &&
F_3 () ) {
static struct V_58 V_95 = {
. V_96 = L_19 ,
} ;
static struct V_58 V_97 = {
. V_96 = L_20 ,
} ;
static struct V_58 V_98 = {
. V_96 = L_21 ,
} ;
if ( F_37 ( V_99 ) ) {
struct V_57 V_100 = {
. V_101 . V_102 =
V_103
| V_104 ,
. V_101 . V_105 =
V_106
| V_107 ,
} ;
V_73 = F_34 ( V_108 ,
& V_100 , & V_95 , 1 ,
V_61 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
V_73 = F_34 ( V_109 ,
& V_100 , & V_97 , 1 ,
V_61 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
V_73 = F_34 ( V_110 ,
& V_100 , & V_98 , 1 ,
V_61 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
}
V_73 = F_33 ( V_111 , L_22 ,
V_40 -> V_94 , sizeof( * V_40 -> V_94 ) , true ,
V_72 + V_112 ,
V_72 + V_113 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
if ( F_37 ( V_99 ) && V_73 ) {
V_95 . V_114 = V_114 ( V_73 ) ;
V_97 . V_114 = V_114 ( V_73 ) ;
V_98 . V_114 = V_114 ( V_73 ) ;
}
}
if ( F_37 ( V_115 ) && F_3 () ) {
V_73 = F_33 ( V_116 , L_23 , NULL ,
0 , false , 0 , 0 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
}
if ( F_37 ( V_117 ) && F_3 () ) {
V_73 = F_33 ( V_32 , L_24 ,
NULL , 0 , true , V_72 + 8 + 0 , 0 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
}
if ( F_37 ( V_118 ) && V_40 -> V_119 &&
F_3 () ) {
V_73 = F_33 ( V_120 , L_25 ,
V_40 -> V_119 , sizeof( * V_40 -> V_119 ) ,
false , 0 , 0 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
}
if ( F_37 ( V_99 ) && F_3 () ) {
V_73 = F_35 ( V_121 , V_40 -> V_122 ,
V_61 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
V_73 = F_35 ( V_123 , V_40 -> V_124 ,
V_61 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
V_73 = F_35 ( V_125 , V_40 -> V_126 ,
V_61 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
V_73 = F_35 ( V_127 , V_40 -> V_128 ,
V_61 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
V_73 = F_35 ( V_129 , V_40 -> V_130 ,
V_61 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
V_73 = F_35 ( V_131 , V_40 -> V_132 ,
V_61 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
V_73 = F_35 ( ( V_61 & V_133 )
? V_134
: V_135 ,
V_40 -> V_136 , V_61 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
V_73 = F_35 ( V_137 , V_40 -> V_138 ,
V_61 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
V_73 = F_35 ( V_139 , V_40 -> V_140 ,
V_61 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
V_73 = F_35 ( V_141 , V_40 -> V_142 ,
V_61 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
}
if ( F_37 ( V_99 ) && ! ( V_61 & V_143 )
&& F_3 () ) {
V_73 = F_35 ( V_144 , V_40 -> V_145 ,
V_61 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
V_73 = F_35 ( V_146 , V_40 -> V_147 ,
V_61 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
V_73 = F_35 ( V_148 , V_40 -> V_149 ,
V_61 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
V_73 = F_35 ( V_150 , V_40 -> V_151 ,
V_61 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
V_73 = F_35 ( V_152 , V_40 -> V_153 ,
V_61 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
V_73 = F_35 ( V_154 , V_40 -> V_155 ,
V_61 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
}
if ( F_37 ( V_156 ) && V_40 -> V_157 &&
! ( V_61 & ( V_143 | V_158 ) ) ) {
V_73 = F_33 ( V_159 , L_26 ,
V_40 -> V_157 , sizeof( * V_40 -> V_157 ) , false ,
V_72 + V_160 ,
V_72 + V_161 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
}
if ( F_37 ( V_162 ) && V_40 -> V_163 ) {
V_73 = F_33 ( V_32 , L_27 ,
V_40 -> V_163 , sizeof( * V_40 -> V_163 ) , false ,
0 , 0 ) ;
if ( F_38 ( V_73 ) )
return F_39 ( V_73 ) ;
}
return 0 ;
}
static inline int T_2 F_40 ( void )
{
int V_164 = 0 ;
V_164 = F_16 ( V_32 , 0 ,
V_165 ) ;
return V_164 ;
}
static inline int T_2 F_41 ( void )
{
int V_164 = 0 ;
V_164 |= F_16 ( V_32 , V_166 ,
V_165 ) ;
V_164 |= F_16 ( V_32 , V_167 ,
V_165 ) ;
return V_164 ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_168 * clock )
{
int V_164 = 0 ;
struct V_169 * V_170 ;
T_3 V_31 ;
T_1 V_30 = V_35 ;
V_170 = F_43 ( V_2 , L_28 ) ;
if ( F_38 ( V_170 ) ) {
F_44 ( V_171 L_29
L_30 ) ;
return;
}
V_31 = F_45 ( V_170 ) ;
F_46 ( V_170 ) ;
switch ( V_31 ) {
case 19200000 :
V_30 = V_34 ;
break;
case 26000000 :
V_30 = V_35 ;
break;
case 38400000 :
V_30 = V_36 ;
break;
}
V_30 |= V_172 ;
if ( clock && clock -> V_173 )
V_30 |= V_174 ;
V_164 |= F_41 () ;
V_164 |= F_16 ( V_32 , V_30 , V_33 ) ;
V_164 |= F_40 () ;
if ( V_164 < 0 )
F_8 ( L_31 , V_14 , V_164 ) ;
}
static int F_47 ( struct V_175 * V_50 )
{
unsigned V_176 , V_177 ;
int V_47 ;
if ( F_3 () )
V_47 = F_48 () ;
else
V_47 = F_49 () ;
if ( V_47 < 0 )
return V_47 ;
V_177 = F_2 () ;
for ( V_176 = 0 ; V_176 < V_177 ; V_176 ++ ) {
struct V_11 * V_12 = & V_6 -> V_16 [ V_176 ] ;
if ( V_12 -> V_50 && V_12 -> V_50 != V_50 )
F_50 ( V_12 -> V_50 ) ;
V_12 -> V_50 = NULL ;
}
V_6 -> V_13 = false ;
return 0 ;
}
static int
F_51 ( struct V_175 * V_50 , const struct V_178 * V_179 )
{
struct V_71 * V_40 = F_52 ( & V_50 -> V_2 ) ;
struct V_180 * V_181 = V_50 -> V_2 . V_182 ;
struct V_45 * V_46 ;
const struct V_183 * V_184 ;
int V_72 = 0 ;
int V_47 ;
unsigned V_176 , V_177 ;
if ( ! V_181 && ! V_40 ) {
F_32 ( & V_50 -> V_2 , L_32 ) ;
return - V_37 ;
}
if ( V_6 ) {
F_27 ( & V_50 -> V_2 , L_33 ,
V_14 ) ;
return - V_185 ;
}
V_46 = F_25 ( V_14 , - 1 ) ;
if ( ! V_46 ) {
F_32 ( & V_50 -> V_2 , L_34 ) ;
return - V_48 ;
}
V_47 = F_29 ( V_46 ) ;
if ( V_47 ) {
F_31 ( V_46 ) ;
return V_47 ;
}
if ( F_53 ( V_50 -> V_186 , V_187 ) == 0 ) {
F_27 ( & V_50 -> V_2 , L_35 ) ;
V_47 = - V_188 ;
goto free;
}
V_6 = F_54 ( & V_50 -> V_2 , sizeof( struct V_189 ) ,
V_190 ) ;
if ( ! V_6 ) {
V_47 = - V_48 ;
goto free;
}
if ( ( V_179 -> V_66 ) & V_191 ) {
V_6 -> V_7 = V_192 ;
V_6 -> V_15 = & V_193 [ 0 ] ;
if ( ( V_179 -> V_66 ) & V_194 )
V_6 -> V_15 [ V_159 ] . V_21 =
V_195 ;
V_184 = V_196 ;
} else {
V_6 -> V_7 = V_197 ;
V_6 -> V_15 = & V_198 [ 0 ] ;
V_184 = V_199 ;
}
V_177 = F_2 () ;
V_6 -> V_16 = F_54 ( & V_50 -> V_2 ,
sizeof( struct V_11 ) * V_177 ,
V_190 ) ;
if ( ! V_6 -> V_16 ) {
V_47 = - V_48 ;
goto free;
}
for ( V_176 = 0 ; V_176 < V_177 ; V_176 ++ ) {
struct V_11 * V_12 = & V_6 -> V_16 [ V_176 ] ;
if ( V_176 == 0 ) {
V_12 -> V_50 = V_50 ;
} else {
V_12 -> V_50 = F_55 ( V_50 -> V_186 ,
V_50 -> V_200 + V_176 ) ;
if ( ! V_12 -> V_50 ) {
F_32 ( & V_50 -> V_2 ,
L_36 , V_176 ) ;
V_47 = - V_48 ;
goto V_27;
}
}
V_12 -> V_8 = F_56 ( V_12 -> V_50 ,
& V_184 [ V_176 ] ) ;
if ( F_38 ( V_12 -> V_8 ) ) {
V_47 = F_39 ( V_12 -> V_8 ) ;
F_32 ( & V_50 -> V_2 ,
L_37 , V_176 ,
V_47 ) ;
goto V_27;
}
}
V_6 -> V_13 = true ;
F_42 ( & V_46 -> V_2 , V_40 ? V_40 -> clock : NULL ) ;
if ( F_3 () ) {
V_47 = F_15 () ;
F_57 ( V_47 < 0 , L_38 ) ;
}
if ( V_50 -> V_201 ) {
if ( F_3 () ) {
F_58 ( V_179 -> V_38 ) ;
V_72 = F_59 ( & V_50 -> V_2 , V_50 -> V_201 ) ;
} else {
V_72 = F_60 ( & V_50 -> V_2 , V_50 -> V_201 ) ;
}
if ( V_72 < 0 ) {
V_47 = V_72 ;
goto V_27;
}
}
if ( F_3 () ) {
T_1 V_202 ;
F_22 ( V_24 , & V_202 , V_203 ) ;
V_202 &= ~ ( V_204 | V_205 | \
V_206 | V_207 ) ;
F_16 ( V_24 , V_202 , V_203 ) ;
F_22 ( V_116 , & V_202 ,
V_208 ) ;
V_202 |= V_209 ;
F_16 ( V_116 , V_202 ,
V_208 ) ;
}
if ( V_181 ) {
if ( V_40 )
V_210 [ 0 ] . V_211 = V_40 -> V_75 ;
V_47 = F_61 ( V_181 , NULL , V_210 ,
& V_50 -> V_2 ) ;
} else {
V_47 = F_36 ( V_40 , V_72 , V_179 -> V_66 ) ;
}
V_27:
if ( V_47 < 0 )
F_47 ( V_50 ) ;
free:
if ( V_47 < 0 )
F_62 ( V_46 ) ;
return V_47 ;
}
