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
if ( ! V_46 ) {
F_26 ( & V_12 -> V_48 -> V_2 , L_9 ) ;
V_47 = - V_49 ;
goto V_23;
}
V_46 -> V_2 . V_50 = & V_12 -> V_48 -> V_2 ;
if ( V_40 ) {
V_47 = F_27 ( V_46 , V_40 , V_41 ) ;
if ( V_47 < 0 ) {
F_26 ( & V_46 -> V_2 , L_10 ) ;
goto V_23;
}
}
if ( V_43 ) {
struct V_51 V_52 [ 2 ] = {
{ . V_53 = V_43 , . V_54 = V_55 , } ,
{ . V_53 = V_44 , . V_54 = V_55 , } ,
} ;
V_47 = F_28 ( V_46 , V_52 , V_44 ? 2 : 1 ) ;
if ( V_47 < 0 ) {
F_26 ( & V_46 -> V_2 , L_11 ) ;
goto V_23;
}
}
V_47 = F_29 ( V_46 ) ;
if ( V_47 == 0 )
F_30 ( & V_46 -> V_2 , V_42 ) ;
V_23:
if ( V_47 < 0 ) {
F_31 ( V_46 ) ;
F_32 ( & V_12 -> V_48 -> V_2 , L_12 , V_38 ) ;
return F_24 ( V_47 ) ;
}
return & V_46 -> V_2 ;
}
static inline struct V_1 * F_33 ( unsigned V_9 , const char * V_38 ,
void * V_40 , unsigned V_41 ,
bool V_42 , int V_43 , int V_44 )
{
return F_23 ( V_9 , V_38 , - 1 , V_40 , V_41 ,
V_42 , V_43 , V_44 ) ;
}
static struct V_1 *
F_34 ( int V_39 , struct V_56 * V_40 ,
struct V_57 * V_58 ,
unsigned V_59 , unsigned long V_60 )
{
struct V_61 V_62 ;
if ( ! V_40 )
return NULL ;
if ( V_58 ) {
V_40 -> V_63 = V_58 ;
V_40 -> V_64 = V_59 ;
}
if ( V_40 -> V_65 ) {
struct V_61 * V_66 ;
V_66 = V_40 -> V_65 ;
V_66 -> V_60 |= V_60 ;
} else {
V_62 . V_60 = V_60 ;
V_62 . V_67 = NULL ;
V_62 . V_68 = NULL ;
V_62 . V_69 = NULL ;
V_40 -> V_65 = & V_62 ;
}
return F_23 ( V_32 , L_13 , V_39 ,
V_40 , sizeof( * V_40 ) , false , 0 , 0 ) ;
}
static struct V_1 *
F_35 ( int V_39 , struct V_56 * V_40 ,
unsigned long V_60 )
{
return F_34 ( V_39 , V_40 , NULL , 0 , V_60 ) ;
}
static int
F_36 ( struct V_70 * V_40 , unsigned V_71 ,
unsigned long V_60 )
{
struct V_1 * V_72 ;
if ( F_37 ( V_73 ) && V_40 -> V_74 ) {
V_72 = F_33 ( V_75 , L_14 ,
V_40 -> V_74 , sizeof( * V_40 -> V_74 ) ,
false , V_71 + V_76 , 0 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
}
if ( F_37 ( V_77 ) && V_40 -> V_78 ) {
V_72 = F_33 ( V_79 , L_15 ,
V_40 -> V_78 , sizeof( * V_40 -> V_78 ) ,
true , V_71 + V_80 , 0 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
}
if ( F_37 ( V_81 ) && V_40 -> V_82 &&
F_3 () ) {
V_72 = F_33 ( V_83 , L_16 ,
V_40 -> V_82 , sizeof( * V_40 -> V_82 ) ,
true , V_71 + V_84 , 0 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
}
if ( F_37 ( V_85 ) ) {
V_72 = F_33 ( V_86 , L_17 , NULL , 0 ,
true , V_71 + V_87 , 0 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
}
if ( F_37 ( V_88 ) ) {
V_72 = F_33 ( V_89 , L_18 , NULL , 0 ,
false , 0 , 0 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
}
if ( F_37 ( V_90 ) ) {
V_72 = F_33 ( V_91 , L_19 , NULL , 0 ,
false , 0 , 0 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
}
if ( F_37 ( V_92 ) && V_40 -> V_93 &&
F_3 () ) {
static struct V_57 V_94 = {
. V_95 = L_20 ,
} ;
static struct V_57 V_96 = {
. V_95 = L_21 ,
} ;
static struct V_57 V_97 [] = {
{ . V_95 = L_22 } ,
{ . V_95 = L_23 } ,
} ;
if ( F_37 ( V_98 ) ) {
struct V_56 V_99 = {
. V_100 . V_101 =
V_102
| V_103 ,
. V_100 . V_104 =
V_105
| V_106 ,
} ;
V_72 = F_34 ( V_107 ,
& V_99 , & V_94 , 1 ,
V_60 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
V_72 = F_34 ( V_108 ,
& V_99 , & V_96 , 1 ,
V_60 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
V_72 = F_34 ( V_109 ,
& V_99 , V_97 , 2 ,
V_60 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
}
V_72 = F_33 ( V_110 , L_24 ,
V_40 -> V_93 , sizeof( * V_40 -> V_93 ) , true ,
V_71 + V_111 ,
V_71 + V_112 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
if ( F_37 ( V_98 ) && V_72 ) {
V_94 . V_113 = V_113 ( V_72 ) ;
V_96 . V_113 = V_113 ( V_72 ) ;
V_97 [ 0 ] . V_113 = V_113 ( V_72 ) ;
}
}
if ( F_37 ( V_114 ) && F_3 () ) {
V_72 = F_33 ( V_115 , L_25 , NULL ,
0 , false , 0 , 0 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
}
if ( F_37 ( V_116 ) && F_3 () ) {
V_72 = F_33 ( V_32 , L_26 ,
NULL , 0 , true , V_71 + 8 + 0 , 0 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
}
if ( F_37 ( V_117 ) && V_40 -> V_118 &&
F_3 () ) {
V_72 = F_33 ( V_119 , L_27 ,
V_40 -> V_118 , sizeof( * V_40 -> V_118 ) ,
false , 0 , 0 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
}
if ( F_37 ( V_98 ) && F_3 () ) {
V_72 = F_35 ( V_120 , V_40 -> V_121 ,
V_60 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
V_72 = F_35 ( V_122 , V_40 -> V_123 ,
V_60 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
V_72 = F_35 ( V_124 , V_40 -> V_125 ,
V_60 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
V_72 = F_35 ( V_126 , V_40 -> V_127 ,
V_60 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
V_72 = F_35 ( V_128 , V_40 -> V_129 ,
V_60 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
V_72 = F_35 ( V_130 , V_40 -> V_131 ,
V_60 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
V_72 = F_35 ( ( V_60 & V_132 )
? V_133
: V_134 ,
V_40 -> V_135 , V_60 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
V_72 = F_35 ( V_136 , V_40 -> V_137 ,
V_60 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
V_72 = F_35 ( V_138 , V_40 -> V_139 ,
V_60 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
V_72 = F_35 ( V_140 , V_40 -> V_141 ,
V_60 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
}
if ( F_37 ( V_98 ) && ! ( V_60 & V_142 )
&& F_3 () ) {
V_72 = F_35 ( V_143 , V_40 -> V_144 ,
V_60 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
V_72 = F_35 ( V_145 , V_40 -> V_146 ,
V_60 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
V_72 = F_35 ( V_147 , V_40 -> V_148 ,
V_60 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
V_72 = F_35 ( V_149 , V_40 -> V_150 ,
V_60 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
V_72 = F_35 ( V_151 , V_40 -> V_152 ,
V_60 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
V_72 = F_35 ( V_153 , V_40 -> V_154 ,
V_60 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
}
if ( F_37 ( V_155 ) && V_40 -> V_156 &&
! ( V_60 & ( V_142 | V_157 ) ) ) {
V_72 = F_33 ( V_158 , L_28 ,
V_40 -> V_156 , sizeof( * V_40 -> V_156 ) , false ,
V_71 + V_159 ,
V_71 + V_160 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
}
if ( F_37 ( V_161 ) && V_40 -> V_162 ) {
V_72 = F_33 ( V_32 , L_29 ,
V_40 -> V_162 , sizeof( * V_40 -> V_162 ) , false ,
0 , 0 ) ;
if ( F_38 ( V_72 ) )
return F_39 ( V_72 ) ;
}
return 0 ;
}
static inline int T_2 F_40 ( void )
{
int V_163 = 0 ;
V_163 = F_16 ( V_32 , 0 ,
V_164 ) ;
return V_163 ;
}
static inline int T_2 F_41 ( void )
{
int V_163 = 0 ;
V_163 |= F_16 ( V_32 , V_165 ,
V_164 ) ;
V_163 |= F_16 ( V_32 , V_166 ,
V_164 ) ;
return V_163 ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_167 * clock )
{
int V_163 = 0 ;
struct V_168 * V_169 ;
T_3 V_31 ;
T_1 V_30 = V_35 ;
V_169 = F_43 ( V_2 , L_30 ) ;
if ( F_38 ( V_169 ) ) {
F_44 ( V_170 L_31
L_32 ) ;
return;
}
V_31 = F_45 ( V_169 ) ;
F_46 ( V_169 ) ;
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
V_30 |= V_171 ;
if ( clock && clock -> V_172 )
V_30 |= V_173 ;
V_163 |= F_41 () ;
V_163 |= F_16 ( V_32 , V_30 , V_33 ) ;
V_163 |= F_40 () ;
if ( V_163 < 0 )
F_8 ( L_33 , V_14 , V_163 ) ;
}
static int F_47 ( struct V_174 * V_48 )
{
unsigned V_175 , V_176 ;
int V_47 ;
if ( F_3 () )
V_47 = F_48 () ;
else
V_47 = F_49 () ;
if ( V_47 < 0 )
return V_47 ;
V_176 = F_2 () ;
for ( V_175 = 0 ; V_175 < V_176 ; V_175 ++ ) {
struct V_11 * V_12 = & V_6 -> V_16 [ V_175 ] ;
if ( V_12 -> V_48 && V_12 -> V_48 != V_48 )
F_50 ( V_12 -> V_48 ) ;
V_12 -> V_48 = NULL ;
}
V_6 -> V_13 = false ;
return 0 ;
}
static int
F_51 ( struct V_174 * V_48 , const struct V_177 * V_178 )
{
struct V_70 * V_40 = F_52 ( & V_48 -> V_2 ) ;
struct V_179 * V_180 = V_48 -> V_2 . V_181 ;
struct V_45 * V_46 ;
struct V_182 * V_183 ;
int V_71 = 0 ;
int V_47 ;
unsigned V_175 , V_176 ;
if ( ! V_180 && ! V_40 ) {
F_32 ( & V_48 -> V_2 , L_34 ) ;
return - V_37 ;
}
if ( V_6 ) {
F_26 ( & V_48 -> V_2 , L_35 ,
V_14 ) ;
return - V_184 ;
}
V_46 = F_25 ( V_14 , - 1 ) ;
if ( ! V_46 ) {
F_32 ( & V_48 -> V_2 , L_36 ) ;
return - V_49 ;
}
V_47 = F_29 ( V_46 ) ;
if ( V_47 ) {
F_31 ( V_46 ) ;
return V_47 ;
}
if ( F_53 ( V_48 -> V_185 , V_186 ) == 0 ) {
F_26 ( & V_48 -> V_2 , L_37 ) ;
V_47 = - V_187 ;
goto free;
}
V_6 = F_54 ( & V_48 -> V_2 , sizeof( struct V_188 ) ,
V_189 ) ;
if ( ! V_6 ) {
V_47 = - V_49 ;
goto free;
}
if ( ( V_178 -> V_65 ) & V_190 ) {
V_6 -> V_7 = V_191 ;
V_6 -> V_15 = & V_192 [ 0 ] ;
if ( ( V_178 -> V_65 ) & V_193 )
V_6 -> V_15 [ V_158 ] . V_21 =
V_194 ;
V_183 = V_195 ;
} else {
V_6 -> V_7 = V_196 ;
V_6 -> V_15 = & V_197 [ 0 ] ;
V_183 = V_198 ;
}
V_176 = F_2 () ;
V_6 -> V_16 = F_54 ( & V_48 -> V_2 ,
sizeof( struct V_11 ) * V_176 ,
V_189 ) ;
if ( ! V_6 -> V_16 ) {
V_47 = - V_49 ;
goto free;
}
for ( V_175 = 0 ; V_175 < V_176 ; V_175 ++ ) {
struct V_11 * V_12 = & V_6 -> V_16 [ V_175 ] ;
if ( V_175 == 0 ) {
V_12 -> V_48 = V_48 ;
} else {
V_12 -> V_48 = F_55 ( V_48 -> V_185 ,
V_48 -> V_199 + V_175 ) ;
if ( ! V_12 -> V_48 ) {
F_32 ( & V_48 -> V_2 ,
L_38 , V_175 ) ;
V_47 = - V_49 ;
goto V_27;
}
}
V_12 -> V_8 = F_56 ( V_12 -> V_48 ,
& V_183 [ V_175 ] ) ;
if ( F_38 ( V_12 -> V_8 ) ) {
V_47 = F_39 ( V_12 -> V_8 ) ;
F_32 ( & V_48 -> V_2 ,
L_39 , V_175 ,
V_47 ) ;
goto V_27;
}
}
V_6 -> V_13 = true ;
F_42 ( & V_46 -> V_2 , V_40 ? V_40 -> clock : NULL ) ;
if ( F_3 () ) {
V_47 = F_15 () ;
F_57 ( V_47 < 0 , L_40 ) ;
}
if ( V_48 -> V_200 ) {
if ( F_3 () ) {
F_58 ( V_178 -> V_38 ) ;
V_71 = F_59 ( & V_48 -> V_2 , V_48 -> V_200 ) ;
} else {
V_71 = F_60 ( & V_48 -> V_2 , V_48 -> V_200 ) ;
}
if ( V_71 < 0 ) {
V_47 = V_71 ;
goto V_27;
}
}
if ( F_3 () ) {
T_1 V_201 ;
F_22 ( V_24 , & V_201 , V_202 ) ;
V_201 &= ~ ( V_203 | V_204 | \
V_205 | V_206 ) ;
F_16 ( V_24 , V_201 , V_202 ) ;
}
if ( V_180 ) {
if ( V_40 )
V_207 [ 0 ] . V_208 = V_40 -> V_74 ;
V_47 = F_61 ( V_180 , NULL , V_207 ,
& V_48 -> V_2 ) ;
} else {
V_47 = F_36 ( V_40 , V_71 , V_178 -> V_65 ) ;
}
V_27:
if ( V_47 < 0 )
F_47 ( V_48 ) ;
free:
if ( V_47 < 0 )
F_62 ( V_46 ) ;
return V_47 ;
}
