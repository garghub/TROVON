int F_1 ( struct V_1 * * V_2 , unsigned int V_3 ,
struct V_4 * * V_5 , int * V_6 )
{
struct V_7 V_8 ;
struct V_4 * V_9 ;
int V_10 ;
if ( * V_5 )
return 0 ;
F_2 ( L_1 , ( unsigned long ) V_3 ) ;
if ( F_3 ( & V_8 , V_3 , V_11 ) )
goto V_12;
* V_5 = V_9 = V_8 . V_13 ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 ++ , V_9 = F_4 ( V_9 ) )
F_5 ( V_9 , V_2 [ V_10 ] , V_14 , 0 ) ;
* V_6 = F_6 ( V_15 . V_16 , * V_5 ,
V_3 , V_17 ) ;
if ( F_7 ( ! * V_6 ) )
goto V_12;
return 0 ;
V_12:
F_8 ( & V_8 ) ;
return - V_18 ;
}
void F_9 ( struct V_4 * V_5 , int V_6 )
{
struct V_7 V_8 ;
F_2 ( L_2 , ( unsigned long ) V_19 -> V_20 ) ;
F_10 ( V_15 . V_16 , V_5 ,
V_6 , V_17 ) ;
V_8 . V_13 = V_5 ;
V_8 . V_21 = V_8 . V_22 = V_6 ;
F_8 ( & V_8 ) ;
}
static void F_11 ( struct V_23 * V_24 , T_1 V_25 )
{
return;
}
static struct V_1 * F_12 ( void )
{
struct V_1 * V_1 ;
V_1 = F_13 ( V_11 | V_26 , 2 ) ;
if ( V_1 == NULL )
return NULL ;
if ( F_14 ( V_1 , 4 ) < 0 ) {
F_15 ( V_1 , 4 ) ;
F_16 ( V_1 , 2 ) ;
return NULL ;
}
F_17 ( V_1 ) ;
F_18 ( & V_27 -> V_28 ) ;
return V_1 ;
}
static void F_19 ( struct V_1 * V_1 )
{
if ( V_1 == NULL )
return;
F_15 ( V_1 , 4 ) ;
F_20 ( V_1 ) ;
F_16 ( V_1 , 2 ) ;
F_21 ( & V_27 -> V_28 ) ;
}
static int F_22 ( void )
{
T_1 V_29 ;
char * V_30 ;
V_30 = F_23 ( V_31 ) ;
if ( V_30 == NULL )
return - V_18 ;
V_15 . V_32 = V_30 ;
F_24 ( V_15 . V_16 , V_33 , & V_29 ) ;
V_29 &= 0xfff80000 ;
V_15 . V_34 = F_25 ( V_29 , F_26 ( 64 ) ) ;
if ( ! V_15 . V_34 )
return - V_18 ;
F_27 ( F_28 ( V_30 ) | V_35 ,
V_15 . V_34 + V_36 ) ;
V_15 . V_37 = V_29 + V_38 ;
if ( ( F_29 ( V_15 . V_34 + V_39 )
& V_40 ) == V_41 ) {
F_30 ( & V_15 . V_16 -> V_42 ,
L_3 ) ;
V_15 . V_43 = 1024 ;
}
return 0 ;
}
static void F_31 ( void )
{
F_27 ( 0 , V_15 . V_34 + V_36 ) ;
F_32 ( V_15 . V_32 , V_31 ) ;
}
static int F_33 ( struct V_44 * V_19 , T_2 V_45 ,
int type )
{
int V_10 ;
if ( ( V_45 + V_19 -> V_20 )
> V_15 . V_43 )
return - V_46 ;
if ( ! V_19 -> V_47 )
F_34 () ;
for ( V_10 = V_45 ; V_10 < ( V_45 + V_19 -> V_20 ) ; V_10 ++ ) {
T_3 V_48 = V_10 << V_49 ;
V_15 . V_50 -> V_51 ( V_48 ,
V_10 , type ) ;
}
F_29 ( V_15 . V_52 + V_10 - 1 ) ;
return 0 ;
}
static struct V_44 * F_35 ( T_4 V_53 , int type )
{
struct V_44 * V_54 ;
struct V_1 * V_1 ;
switch ( V_53 ) {
case 1 : V_1 = V_27 -> V_50 -> V_55 ( V_27 ) ;
break;
case 4 :
V_1 = F_12 () ;
break;
default:
return NULL ;
}
if ( V_1 == NULL )
return NULL ;
V_54 = F_36 ( V_53 ) ;
if ( V_54 == NULL )
return NULL ;
V_54 -> V_2 [ 0 ] = V_1 ;
if ( V_53 == 4 ) {
V_54 -> V_2 [ 1 ] = V_54 -> V_2 [ 0 ] + 1 ;
V_54 -> V_2 [ 2 ] = V_54 -> V_2 [ 1 ] + 1 ;
V_54 -> V_2 [ 3 ] = V_54 -> V_2 [ 2 ] + 1 ;
}
V_54 -> V_20 = V_53 ;
V_54 -> V_56 = V_53 ;
V_54 -> type = V_57 ;
V_54 -> V_58 = F_37 ( V_54 -> V_2 [ 0 ] ) ;
return V_54 ;
}
static void F_38 ( struct V_44 * V_59 )
{
F_39 ( V_59 -> V_60 ) ;
if ( V_59 -> type == V_57 ) {
if ( V_59 -> V_20 == 4 )
F_19 ( V_59 -> V_2 [ 0 ] ) ;
else {
V_27 -> V_50 -> V_61 ( V_59 -> V_2 [ 0 ] ,
V_62 ) ;
V_27 -> V_50 -> V_61 ( V_59 -> V_2 [ 0 ] ,
V_63 ) ;
}
F_40 ( V_59 ) ;
}
F_41 ( V_59 ) ;
}
static int F_42 ( void )
{
struct V_1 * V_1 ;
T_3 V_64 ;
V_1 = F_43 ( V_11 | V_26 | V_65 ) ;
if ( V_1 == NULL )
return - V_18 ;
F_17 ( V_1 ) ;
F_14 ( V_1 , 1 ) ;
if ( V_15 . V_66 . V_67 ) {
V_64 = F_44 ( V_15 . V_16 , V_1 , 0 ,
V_14 , V_17 ) ;
if ( F_45 ( V_15 . V_16 , V_64 ) )
return - V_46 ;
V_15 . V_66 . V_68 = V_64 ;
} else
V_15 . V_66 . V_68 = F_37 ( V_1 ) ;
V_15 . V_69 = V_1 ;
return 0 ;
}
static void F_46 ( T_3 V_48 , unsigned int V_70 ,
unsigned int V_71 )
{
T_1 V_72 = V_73 ;
switch ( V_71 ) {
case V_74 :
V_72 |= V_75 ;
break;
case V_76 :
V_72 |= V_77 ;
break;
}
F_27 ( V_48 | V_72 , V_15 . V_52 + V_70 ) ;
}
static unsigned int F_47 ( void )
{
T_5 V_78 ;
T_6 V_79 ;
int V_80 = 0 ;
static const int V_81 [ 4 ] = { 0 , 16 , 32 , 64 } ;
unsigned int V_82 = 0 ;
if ( V_83 == 1 )
return 0 ;
F_48 ( V_15 . V_84 ,
V_85 , & V_78 ) ;
if ( V_15 . V_84 -> V_86 == V_87 ||
V_15 . V_84 -> V_86 == V_88 ) {
switch ( V_78 & V_89 ) {
case V_90 :
V_82 = F_26 ( 512 ) ;
break;
case V_91 :
V_82 = F_49 ( 1 ) ;
break;
case V_92 :
V_82 = F_49 ( 8 ) ;
break;
case V_93 :
V_79 = F_50 ( V_15 . V_34 + V_94 ) ;
V_82 = ( F_51 ( V_79 ) + 1 ) *
F_49 ( V_81 [ F_52 ( V_79 ) ] ) ;
V_80 = 1 ;
break;
default:
V_82 = 0 ;
break;
}
} else if ( V_83 == 6 ) {
T_5 V_95 ;
F_48 ( V_15 . V_16 , V_96 , & V_95 ) ;
switch ( V_95 & V_97 ) {
case V_98 :
V_82 = F_49 ( 32 ) ;
break;
case V_99 :
V_82 = F_49 ( 64 ) ;
break;
case V_100 :
V_82 = F_49 ( 96 ) ;
break;
case V_101 :
V_82 = F_49 ( 128 ) ;
break;
case V_102 :
V_82 = F_49 ( 160 ) ;
break;
case V_103 :
V_82 = F_49 ( 192 ) ;
break;
case V_104 :
V_82 = F_49 ( 224 ) ;
break;
case V_105 :
V_82 = F_49 ( 256 ) ;
break;
case V_106 :
V_82 = F_49 ( 288 ) ;
break;
case V_107 :
V_82 = F_49 ( 320 ) ;
break;
case V_108 :
V_82 = F_49 ( 352 ) ;
break;
case V_109 :
V_82 = F_49 ( 384 ) ;
break;
case V_110 :
V_82 = F_49 ( 416 ) ;
break;
case V_111 :
V_82 = F_49 ( 448 ) ;
break;
case V_112 :
V_82 = F_49 ( 480 ) ;
break;
case V_113 :
V_82 = F_49 ( 512 ) ;
break;
}
} else {
switch ( V_78 & V_114 ) {
case V_115 :
V_82 = F_49 ( 1 ) ;
break;
case V_116 :
V_82 = F_49 ( 4 ) ;
break;
case V_117 :
V_82 = F_49 ( 8 ) ;
break;
case V_118 :
V_82 = F_49 ( 16 ) ;
break;
case V_119 :
V_82 = F_49 ( 32 ) ;
break;
case V_120 :
V_82 = F_49 ( 48 ) ;
break;
case V_121 :
V_82 = F_49 ( 64 ) ;
break;
case V_122 :
V_82 = F_49 ( 128 ) ;
break;
case V_123 :
V_82 = F_49 ( 256 ) ;
break;
case V_124 :
V_82 = F_49 ( 96 ) ;
break;
case V_125 :
V_82 = F_49 ( 160 ) ;
break;
case V_126 :
V_82 = F_49 ( 224 ) ;
break;
case V_127 :
V_82 = F_49 ( 352 ) ;
break;
default:
V_82 = 0 ;
break;
}
}
if ( V_82 > 0 ) {
F_30 ( & V_15 . V_84 -> V_42 , L_4 ,
V_82 / F_26 ( 1 ) , V_80 ? L_5 : L_6 ) ;
} else {
F_30 ( & V_15 . V_84 -> V_42 ,
L_7 ) ;
V_82 = 0 ;
}
return V_82 ;
}
static void F_53 ( unsigned int V_128 )
{
T_1 V_129 , V_130 ;
V_130 = F_29 ( V_15 . V_34 + V_131 ) ;
V_130 &= ~ V_35 ;
F_27 ( V_130 , V_15 . V_34 + V_131 ) ;
V_129 = F_29 ( V_15 . V_34 + V_36 ) ;
V_129 &= ~ V_132 ;
V_129 |= V_128 ;
F_27 ( V_129 , V_15 . V_34 + V_36 ) ;
}
static unsigned int F_54 ( void )
{
int V_133 ;
T_1 V_129 ;
T_5 V_134 ;
F_48 ( V_15 . V_84 ,
V_85 , & V_134 ) ;
if ( V_83 == 5 ) {
switch ( V_134 & V_135 ) {
case V_136 :
case V_137 :
F_53 ( V_138 ) ;
break;
case V_139 :
F_53 ( V_140 ) ;
break;
case V_141 :
case V_142 :
F_53 ( V_143 ) ;
break;
}
}
V_129 = F_29 ( V_15 . V_34 + V_36 ) ;
switch ( V_129 & V_132 ) {
case V_144 :
V_133 = F_26 ( 128 ) ;
break;
case V_145 :
V_133 = F_26 ( 256 ) ;
break;
case V_146 :
V_133 = F_26 ( 512 ) ;
break;
case V_138 :
V_133 = F_26 ( 1024 ) ;
break;
case V_143 :
V_133 = F_26 ( 2048 ) ;
break;
case V_140 :
V_133 = F_26 ( 1024 + 512 ) ;
break;
default:
F_30 ( & V_15 . V_16 -> V_42 ,
L_8 ) ;
V_133 = F_26 ( 512 ) ;
}
return V_133 / 4 ;
}
static unsigned int F_55 ( void )
{
int V_133 ;
if ( V_147 || V_83 == 4 || V_83 == 5 )
return F_54 () ;
else if ( V_83 == 6 ) {
T_5 V_95 ;
F_48 ( V_15 . V_16 , V_96 , & V_95 ) ;
switch ( V_95 & V_148 ) {
default:
case V_149 :
F_56 ( V_150 L_9 , V_95 ) ;
V_133 = F_49 ( 0 ) ;
break;
case V_151 :
V_133 = F_49 ( 1 ) ;
break;
case V_152 :
V_133 = F_49 ( 2 ) ;
break;
}
return V_133 / 4 ;
} else {
return V_15 . V_66 . V_153 ;
}
}
static unsigned int F_57 ( void )
{
unsigned int V_154 ;
if ( V_83 == 1 ) {
T_1 V_155 ;
F_24 ( V_15 . V_84 ,
V_156 , & V_155 ) ;
if ( ( V_155 & V_157 )
== V_158 )
V_154 = F_49 ( 32 ) ;
else
V_154 = F_49 ( 64 ) ;
} else if ( V_83 == 2 ) {
T_5 V_78 ;
F_48 ( V_15 . V_84 ,
V_85 , & V_78 ) ;
if ( ( V_78 & V_159 ) == V_160 )
V_154 = F_49 ( 64 ) ;
else
V_154 = F_49 ( 128 ) ;
} else {
V_154 = F_58 ( V_15 . V_16 , 2 ) ;
}
return V_154 >> V_49 ;
}
static void F_59 ( void )
{
F_15 ( V_15 . V_69 , 1 ) ;
F_60 ( V_15 . V_16 , V_15 . V_66 . V_68 ,
V_14 , V_17 ) ;
F_20 ( V_15 . V_69 ) ;
F_61 ( V_15 . V_69 ) ;
}
static void F_62 ( void )
{
V_15 . V_50 -> V_161 () ;
F_63 ( V_15 . V_52 ) ;
F_63 ( V_15 . V_34 ) ;
F_59 () ;
}
static int F_64 ( void )
{
T_1 V_162 ;
int V_163 ;
V_163 = V_15 . V_50 -> V_164 () ;
if ( V_163 != 0 )
return V_163 ;
V_15 . V_66 . V_153 = F_57 () ;
V_15 . V_66 . V_165 = F_55 () ;
V_15 . V_166 =
F_29 ( V_15 . V_34 + V_36 )
& ~ V_35 ;
if ( V_167 )
V_15 . V_166 |= V_35 ;
F_30 ( & V_15 . V_84 -> V_42 ,
L_10 ,
V_15 . V_66 . V_165 * 4 ,
V_15 . V_66 . V_153 * 4 ) ;
V_162 = V_15 . V_66 . V_165 * 4 ;
V_15 . V_52 = F_25 ( V_15 . V_37 ,
V_162 ) ;
if ( ! V_15 . V_52 ) {
V_15 . V_50 -> V_161 () ;
F_63 ( V_15 . V_34 ) ;
return - V_18 ;
}
V_15 . V_66 . V_52 = V_15 . V_52 ;
F_34 () ;
V_15 . V_66 . V_82 = F_47 () ;
V_15 . V_66 . V_67 = V_168 && V_83 > 2 ;
V_163 = F_42 () ;
if ( V_163 != 0 ) {
F_62 () ;
return V_163 ;
}
return 0 ;
}
static int F_65 ( void )
{
int V_169 = F_66 ( V_170 ) ;
unsigned int V_171 ;
int V_10 ;
V_171 = ( V_15 . V_66 . V_153 << V_49 )
/ F_49 ( 1 ) ;
for ( V_10 = 0 ; V_10 < V_169 ; V_10 ++ ) {
if ( V_171 == V_170 [ V_10 ] . V_133 ) {
V_27 -> V_172 =
( void * ) ( V_170 + V_10 ) ;
return V_171 ;
}
}
return 0 ;
}
static void F_67 ( void )
{
}
static void F_68 ( void )
{
unsigned long V_173 = V_174 + F_69 ( 1000 ) ;
F_70 () ;
F_27 ( F_29 ( V_15 . V_34 + V_175 ) | ( 1 << 31 ) ,
V_15 . V_34 + V_175 ) ;
while ( F_29 ( V_15 . V_34 + V_175 ) & ( 1 << 31 ) ) {
if ( F_71 ( V_174 , V_173 ) )
break;
F_72 ( 50 ) ;
}
}
static void F_73 ( T_3 V_48 , unsigned int V_70 ,
unsigned int V_71 )
{
T_1 V_72 = V_73 ;
if ( V_71 == V_76 )
V_72 |= V_77 ;
F_27 ( V_48 | V_72 , V_15 . V_52 + V_70 ) ;
}
static bool F_74 ( void )
{
T_1 V_176 ;
T_6 T_7 * V_177 ;
if ( V_83 <= 2 )
F_24 ( V_15 . V_16 , V_178 ,
& V_176 ) ;
else
F_24 ( V_15 . V_16 , V_179 ,
& V_176 ) ;
V_15 . V_180 = ( V_176 & V_181 ) ;
if ( V_83 >= 6 )
return true ;
if ( V_83 == 2 ) {
T_5 V_78 ;
F_48 ( V_15 . V_84 ,
V_85 , & V_78 ) ;
V_78 |= V_182 ;
F_75 ( V_15 . V_84 ,
V_85 , V_78 ) ;
F_48 ( V_15 . V_84 ,
V_85 , & V_78 ) ;
if ( ( V_78 & V_182 ) == 0 ) {
F_76 ( & V_15 . V_16 -> V_42 ,
L_11 ,
V_78 ) ;
return false ;
}
}
if ( V_83 >= 3 )
F_27 ( 0 , V_15 . V_34 + V_183 ) ;
V_177 = V_15 . V_34 + V_36 ;
F_27 ( V_15 . V_166 , V_177 ) ;
if ( V_167 && ( F_29 ( V_177 ) & V_35 ) == 0 ) {
F_76 ( & V_15 . V_16 -> V_42 ,
L_12 ,
F_29 ( V_177 ) , V_15 . V_166 ) ;
return false ;
}
if ( V_83 >= 3 )
F_27 ( 0 , V_15 . V_34 + V_183 ) ;
return true ;
}
static int F_77 ( void )
{
T_1 V_29 ;
F_24 ( V_15 . V_16 , V_33 , & V_29 ) ;
V_29 &= 0xfff80000 ;
V_15 . V_34 = F_25 ( V_29 , F_26 ( 64 ) ) ;
if ( ! V_15 . V_34 )
return - V_18 ;
V_15 . V_37 = V_29 + V_38 ;
return 0 ;
}
static int F_78 ( struct V_23 * V_24 )
{
V_27 -> V_184 = NULL ;
V_27 -> V_185 = NULL ;
V_27 -> V_186 = 0 ;
return 0 ;
}
static int F_79 ( struct V_23 * V_24 )
{
return 0 ;
}
static int F_80 ( void )
{
if ( ! F_74 () )
return - V_187 ;
V_15 . V_188 = true ;
V_27 -> V_189 = V_15 . V_180 ;
return 0 ;
}
static bool F_81 ( unsigned int V_71 )
{
switch ( V_71 ) {
case 0 :
case V_57 :
case V_76 :
case V_190 :
return true ;
}
return false ;
}
void F_82 ( struct V_4 * V_5 ,
unsigned int V_191 ,
unsigned int V_45 ,
unsigned int V_71 )
{
struct V_4 * V_9 ;
unsigned int V_192 , V_193 ;
int V_10 , V_194 ;
V_194 = V_45 ;
F_83 (sg_list, sg, sg_len, i) {
V_192 = F_84 ( V_9 ) >> V_49 ;
for ( V_193 = 0 ; V_193 < V_192 ; V_193 ++ ) {
T_3 V_48 = F_85 ( V_9 ) + ( V_193 << V_49 ) ;
V_15 . V_50 -> V_51 ( V_48 ,
V_194 , V_71 ) ;
V_194 ++ ;
}
}
F_29 ( V_15 . V_52 + V_194 - 1 ) ;
}
void F_86 ( unsigned int V_195 , unsigned int V_3 ,
struct V_1 * * V_2 , unsigned int V_71 )
{
int V_10 , V_194 ;
for ( V_10 = 0 , V_194 = V_195 ; V_10 < V_3 ; V_10 ++ , V_194 ++ ) {
T_3 V_48 = F_37 ( V_2 [ V_10 ] ) ;
V_15 . V_50 -> V_51 ( V_48 ,
V_194 , V_71 ) ;
}
F_29 ( V_15 . V_52 + V_194 - 1 ) ;
}
static int F_87 ( struct V_44 * V_19 ,
T_2 V_45 , int type )
{
int V_163 = - V_46 ;
if ( V_15 . V_66 . V_196 )
return - V_197 ;
if ( V_15 . V_188 ) {
int V_198 = V_15 . V_66 . V_82 / V_14 ;
int V_199 = V_15 . V_66 . V_153 ;
F_88 ( V_198 , V_199 - V_198 ) ;
V_15 . V_188 = false ;
}
if ( V_83 == 1 && type == V_74 )
return F_33 ( V_19 , V_45 , type ) ;
if ( V_19 -> V_20 == 0 )
goto V_200;
if ( V_45 + V_19 -> V_20 > V_15 . V_66 . V_165 )
goto V_201;
if ( type != V_19 -> type )
goto V_201;
if ( ! V_15 . V_50 -> V_202 ( type ) )
goto V_201;
if ( ! V_19 -> V_47 )
F_34 () ;
if ( V_15 . V_66 . V_67 ) {
V_163 = F_1 ( V_19 -> V_2 , V_19 -> V_20 ,
& V_19 -> V_5 , & V_19 -> V_6 ) ;
if ( V_163 != 0 )
return V_163 ;
F_82 ( V_19 -> V_5 , V_19 -> V_6 ,
V_45 , type ) ;
} else
F_86 ( V_45 , V_19 -> V_20 , V_19 -> V_2 ,
type ) ;
V_200:
V_163 = 0 ;
V_201:
V_19 -> V_47 = true ;
return V_163 ;
}
void F_88 ( unsigned int V_195 , unsigned int V_3 )
{
unsigned int V_10 ;
for ( V_10 = V_195 ; V_10 < ( V_195 + V_3 ) ; V_10 ++ ) {
V_15 . V_50 -> V_51 ( V_15 . V_66 . V_68 ,
V_10 , 0 ) ;
}
F_29 ( V_15 . V_52 + V_10 - 1 ) ;
}
static int F_89 ( struct V_44 * V_19 ,
T_2 V_45 , int type )
{
if ( V_19 -> V_20 == 0 )
return 0 ;
if ( V_15 . V_66 . V_196 )
return - V_197 ;
F_88 ( V_45 , V_19 -> V_20 ) ;
if ( V_15 . V_66 . V_67 ) {
F_9 ( V_19 -> V_5 , V_19 -> V_6 ) ;
V_19 -> V_5 = NULL ;
V_19 -> V_6 = 0 ;
}
return 0 ;
}
static struct V_44 * F_90 ( T_4 V_53 ,
int type )
{
struct V_44 * V_54 ;
if ( type == V_74 && V_83 == 1 ) {
if ( V_53 != V_15 . V_43 )
return NULL ;
V_54 = F_36 ( 1 ) ;
if ( V_54 == NULL )
return NULL ;
V_54 -> type = V_74 ;
V_54 -> V_20 = V_53 ;
V_54 -> V_56 = 0 ;
F_40 ( V_54 ) ;
return V_54 ;
}
if ( type == V_57 )
return F_35 ( V_53 , type ) ;
return NULL ;
}
static int F_91 ( void )
{
int V_163 ;
V_163 = F_92 ( V_15 . V_84 -> V_203 , & V_15 . V_204 , V_14 ,
V_14 , V_205 , 0 ,
V_206 , V_15 . V_84 ) ;
return V_163 ;
}
static void F_93 ( void )
{
int V_163 ;
T_1 V_207 ;
F_24 ( V_15 . V_84 , V_208 , & V_207 ) ;
if ( ! ( V_207 & 0x1 ) ) {
F_91 () ;
V_15 . V_209 = 1 ;
F_94 ( V_15 . V_84 , V_208 , ( V_15 . V_204 . V_198 & 0xffffffff ) | 0x1 ) ;
} else {
V_207 &= ~ 1 ;
V_15 . V_209 = 1 ;
V_15 . V_204 . V_198 = V_207 ;
V_15 . V_204 . V_199 = V_207 + V_14 ;
V_163 = F_95 ( & V_210 , & V_15 . V_204 ) ;
if ( V_163 )
V_15 . V_209 = 0 ;
}
}
static void F_96 ( void )
{
T_1 V_211 , V_212 ;
int V_163 ;
F_24 ( V_15 . V_84 , V_213 + 4 , & V_211 ) ;
F_24 ( V_15 . V_84 , V_213 , & V_212 ) ;
if ( ! ( V_212 & 0x1 ) ) {
F_91 () ;
V_15 . V_209 = 1 ;
F_94 ( V_15 . V_84 , V_213 + 4 ,
F_97 ( V_15 . V_204 . V_198 ) ) ;
F_94 ( V_15 . V_84 , V_213 , ( V_15 . V_204 . V_198 & 0xffffffff ) | 0x1 ) ;
} else {
T_8 V_214 ;
V_212 &= ~ 0x1 ;
V_214 = ( ( T_8 ) V_211 << 32 ) | V_212 ;
V_15 . V_209 = 1 ;
V_15 . V_204 . V_198 = V_214 ;
V_15 . V_204 . V_199 = V_214 + V_14 ;
V_163 = F_95 ( & V_210 , & V_15 . V_204 ) ;
if ( V_163 )
V_15 . V_209 = 0 ;
}
}
static void F_98 ( void )
{
if ( V_15 . V_204 . V_198 )
return;
if ( V_83 == 6 )
return;
V_15 . V_204 . V_215 = L_13 ;
V_15 . V_204 . V_71 = V_216 ;
if ( V_147 || V_83 >= 4 ) {
F_96 () ;
} else {
F_93 () ;
}
if ( V_15 . V_204 . V_198 )
V_15 . V_217 = F_99 ( V_15 . V_204 . V_198 , V_14 ) ;
if ( ! V_15 . V_217 )
F_76 ( & V_15 . V_16 -> V_42 ,
L_14 ) ;
}
static void F_100 ( void )
{
if ( V_15 . V_217 )
F_63 ( V_15 . V_217 ) ;
if ( V_15 . V_209 )
F_101 ( & V_15 . V_204 ) ;
V_15 . V_204 . V_198 = 0 ;
V_15 . V_209 = 0 ;
}
static void F_102 ( void )
{
if ( V_15 . V_217 )
F_27 ( 1 , V_15 . V_217 ) ;
}
static void F_103 ( T_3 V_48 ,
unsigned int V_70 ,
unsigned int V_71 )
{
T_1 V_72 ;
V_72 = V_73 ;
if ( V_71 == V_76 )
V_72 |= V_77 ;
V_48 |= ( V_48 >> 28 ) & 0xf0 ;
F_27 ( V_48 | V_72 , V_15 . V_52 + V_70 ) ;
}
static bool F_104 ( unsigned int V_71 )
{
return true ;
}
static void F_105 ( T_3 V_48 , unsigned int V_70 ,
unsigned int V_71 )
{
unsigned int V_218 = V_71 & ~ V_219 ;
unsigned int V_220 = V_71 & V_219 ;
T_1 V_72 ;
if ( V_218 == V_190 )
V_72 = V_221 | V_73 ;
else if ( V_218 == V_222 ) {
V_72 = V_223 | V_73 ;
if ( V_220 )
V_72 |= V_224 ;
} else {
V_72 = V_225 | V_73 ;
if ( V_220 )
V_72 |= V_224 ;
}
V_48 |= ( V_48 >> 28 ) & 0xff0 ;
F_27 ( V_48 | V_72 , V_15 . V_52 + V_70 ) ;
}
static void F_106 ( void )
{
}
static inline int F_107 ( void )
{
#ifdef F_108
const unsigned short V_226 = V_15 . V_16 -> V_86 ;
if ( ( V_226 == V_227 ||
V_226 == V_228 ) &&
V_229 )
return 1 ;
#endif
return 0 ;
}
static int F_109 ( void )
{
T_1 V_29 ;
F_24 ( V_15 . V_16 , V_230 , & V_29 ) ;
V_29 &= 0xfff80000 ;
V_15 . V_34 = F_25 ( V_29 , 128 * 4096 ) ;
if ( ! V_15 . V_34 )
return - V_18 ;
if ( V_83 == 3 ) {
T_1 V_231 ;
F_24 ( V_15 . V_16 ,
V_232 , & V_231 ) ;
V_15 . V_37 = V_231 ;
} else {
T_1 V_233 ;
switch ( V_83 ) {
case 5 :
case 6 :
V_233 = F_49 ( 2 ) ;
break;
case 4 :
default:
V_233 = F_26 ( 512 ) ;
break;
}
V_15 . V_37 = V_29 + V_233 ;
}
if ( F_107 () )
V_15 . V_66 . V_196 = 1 ;
F_98 () ;
return 0 ;
}
static int F_110 ( T_5 V_86 )
{
struct V_234 * V_235 ;
V_235 = F_111 ( V_236 , V_86 , NULL ) ;
if ( V_235 && F_112 ( V_235 -> V_237 ) != 0 ) {
V_235 = F_111 ( V_236 ,
V_86 , V_235 ) ;
}
if ( ! V_235 )
return 0 ;
V_15 . V_16 = V_235 ;
return 1 ;
}
int F_113 ( struct V_234 * V_238 ,
struct V_23 * V_24 )
{
int V_10 , V_239 ;
V_15 . V_50 = NULL ;
for ( V_10 = 0 ; V_240 [ V_10 ] . V_215 != NULL ; V_10 ++ ) {
if ( F_110 ( V_240 [ V_10 ] . V_241 ) ) {
V_15 . V_50 =
V_240 [ V_10 ] . V_242 ;
break;
}
}
if ( ! V_15 . V_50 )
return 0 ;
V_24 -> V_50 = & V_243 ;
V_24 -> V_244 = & V_15 ;
V_24 -> V_42 = V_238 ;
V_15 . V_84 = F_114 ( V_238 ) ;
F_30 ( & V_238 -> V_42 , L_15 , V_240 [ V_10 ] . V_215 ) ;
V_239 = V_15 . V_50 -> V_245 ;
if ( F_115 ( V_15 . V_16 , F_116 ( V_239 ) ) )
F_76 ( & V_15 . V_16 -> V_42 ,
L_16 , V_239 ) ;
else
F_117 ( V_15 . V_16 ,
F_116 ( V_239 ) ) ;
if ( F_64 () != 0 )
return 0 ;
return 1 ;
}
const struct V_246 * F_118 ( void )
{
return & V_15 . V_66 ;
}
void F_119 ( void )
{
if ( V_15 . V_50 -> V_247 )
V_15 . V_50 -> V_247 () ;
}
void F_120 ( struct V_234 * V_238 )
{
if ( V_15 . V_16 )
F_121 ( V_15 . V_16 ) ;
if ( V_15 . V_84 )
F_121 ( V_15 . V_84 ) ;
}
