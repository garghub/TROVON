static int F_1 ( struct V_1 * * V_2 ,
unsigned int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int V_8 ;
F_2 ( L_1 , ( unsigned long ) V_3 ) ;
if ( F_3 ( V_5 , V_3 , V_9 ) )
goto V_10;
F_4 (st->sgl, sg, num_entries, i)
F_5 ( V_7 , V_2 [ V_8 ] , V_11 , 0 ) ;
if ( ! F_6 ( V_12 . V_13 ,
V_5 -> V_14 , V_5 -> V_15 , V_16 ) )
goto V_10;
return 0 ;
V_10:
F_7 ( V_5 ) ;
return - V_17 ;
}
static void F_8 ( struct V_6 * V_18 , int V_19 )
{
struct V_4 V_5 ;
F_2 ( L_2 , ( unsigned long ) V_20 -> V_21 ) ;
F_9 ( V_12 . V_13 , V_18 ,
V_19 , V_16 ) ;
V_5 . V_14 = V_18 ;
V_5 . V_22 = V_5 . V_15 = V_19 ;
F_7 ( & V_5 ) ;
}
static void F_10 ( struct V_23 * V_24 , T_1 V_25 )
{
return;
}
static struct V_1 * F_11 ( void )
{
struct V_1 * V_1 ;
V_1 = F_12 ( V_9 | V_26 , 2 ) ;
if ( V_1 == NULL )
return NULL ;
if ( F_13 ( V_1 , 4 ) < 0 ) {
F_14 ( V_1 , 4 ) ;
F_15 ( V_1 , 2 ) ;
return NULL ;
}
F_16 ( V_1 ) ;
F_17 ( & V_27 -> V_28 ) ;
return V_1 ;
}
static void F_18 ( struct V_1 * V_1 )
{
if ( V_1 == NULL )
return;
F_14 ( V_1 , 4 ) ;
F_19 ( V_1 ) ;
F_15 ( V_1 , 2 ) ;
F_20 ( & V_27 -> V_28 ) ;
}
static int F_21 ( void )
{
T_1 V_29 ;
char * V_30 ;
V_30 = F_22 ( V_31 ) ;
if ( V_30 == NULL )
return - V_17 ;
V_12 . V_32 = V_30 ;
F_23 ( V_12 . V_13 , V_33 , & V_29 ) ;
V_29 &= 0xfff80000 ;
V_12 . V_34 = F_24 ( V_29 , F_25 ( 64 ) ) ;
if ( ! V_12 . V_34 )
return - V_17 ;
F_26 ( F_27 ( V_30 ) | V_35 ,
V_12 . V_34 + V_36 ) ;
V_12 . V_37 = V_29 + V_38 ;
if ( ( F_28 ( V_12 . V_34 + V_39 )
& V_40 ) == V_41 ) {
F_29 ( & V_12 . V_13 -> V_42 ,
L_3 ) ;
V_12 . V_43 = 1024 ;
}
return 0 ;
}
static void F_30 ( void )
{
F_26 ( 0 , V_12 . V_34 + V_36 ) ;
F_31 ( V_12 . V_32 , V_31 ) ;
}
static int F_32 ( struct V_44 * V_20 , T_2 V_45 ,
int type )
{
int V_8 ;
if ( ( V_45 + V_20 -> V_21 )
> V_12 . V_43 )
return - V_46 ;
if ( ! V_20 -> V_47 )
F_33 () ;
for ( V_8 = V_45 ; V_8 < ( V_45 + V_20 -> V_21 ) ; V_8 ++ ) {
T_3 V_48 = V_8 << V_49 ;
V_12 . V_50 -> V_51 ( V_48 ,
V_8 , type ) ;
}
F_28 ( V_12 . V_52 + V_8 - 1 ) ;
return 0 ;
}
static struct V_44 * F_34 ( T_4 V_53 , int type )
{
struct V_44 * V_54 ;
struct V_1 * V_1 ;
switch ( V_53 ) {
case 1 : V_1 = V_27 -> V_50 -> V_55 ( V_27 ) ;
break;
case 4 :
V_1 = F_11 () ;
break;
default:
return NULL ;
}
if ( V_1 == NULL )
return NULL ;
V_54 = F_35 ( V_53 ) ;
if ( V_54 == NULL )
return NULL ;
V_54 -> V_2 [ 0 ] = V_1 ;
if ( V_53 == 4 ) {
V_54 -> V_2 [ 1 ] = V_54 -> V_2 [ 0 ] + 1 ;
V_54 -> V_2 [ 2 ] = V_54 -> V_2 [ 1 ] + 1 ;
V_54 -> V_2 [ 3 ] = V_54 -> V_2 [ 2 ] + 1 ;
}
V_54 -> V_21 = V_53 ;
V_54 -> V_56 = V_53 ;
V_54 -> type = V_57 ;
V_54 -> V_58 = F_36 ( V_54 -> V_2 [ 0 ] ) ;
return V_54 ;
}
static void F_37 ( struct V_44 * V_59 )
{
F_38 ( V_59 -> V_60 ) ;
if ( V_59 -> type == V_57 ) {
if ( V_59 -> V_21 == 4 )
F_18 ( V_59 -> V_2 [ 0 ] ) ;
else {
V_27 -> V_50 -> V_61 ( V_59 -> V_2 [ 0 ] ,
V_62 ) ;
V_27 -> V_50 -> V_61 ( V_59 -> V_2 [ 0 ] ,
V_63 ) ;
}
F_39 ( V_59 ) ;
}
F_40 ( V_59 ) ;
}
static int F_41 ( void )
{
struct V_1 * V_1 ;
T_3 V_64 ;
V_1 = F_42 ( V_9 | V_26 | V_65 ) ;
if ( V_1 == NULL )
return - V_17 ;
F_16 ( V_1 ) ;
F_13 ( V_1 , 1 ) ;
if ( V_12 . V_66 . V_67 ) {
V_64 = F_43 ( V_12 . V_13 , V_1 , 0 ,
V_11 , V_16 ) ;
if ( F_44 ( V_12 . V_13 , V_64 ) )
return - V_46 ;
V_12 . V_66 . V_68 = V_64 ;
} else
V_12 . V_66 . V_68 = F_36 ( V_1 ) ;
V_12 . V_69 = V_1 ;
return 0 ;
}
static void F_45 ( T_3 V_48 , unsigned int V_70 ,
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
F_26 ( V_48 | V_72 , V_12 . V_52 + V_70 ) ;
}
static unsigned int F_46 ( void )
{
T_5 V_78 ;
T_6 V_79 ;
int V_80 = 0 ;
static const int V_81 [ 4 ] = { 0 , 16 , 32 , 64 } ;
unsigned int V_82 = 0 ;
if ( V_83 == 1 )
return 0 ;
F_47 ( V_12 . V_84 ,
V_85 , & V_78 ) ;
if ( V_12 . V_84 -> V_86 == V_87 ||
V_12 . V_84 -> V_86 == V_88 ) {
switch ( V_78 & V_89 ) {
case V_90 :
V_82 = F_25 ( 512 ) ;
break;
case V_91 :
V_82 = F_48 ( 1 ) ;
break;
case V_92 :
V_82 = F_48 ( 8 ) ;
break;
case V_93 :
V_79 = F_49 ( V_12 . V_34 + V_94 ) ;
V_82 = ( F_50 ( V_79 ) + 1 ) *
F_48 ( V_81 [ F_51 ( V_79 ) ] ) ;
V_80 = 1 ;
break;
default:
V_82 = 0 ;
break;
}
} else if ( V_83 == 6 ) {
T_5 V_95 ;
F_47 ( V_12 . V_13 , V_96 , & V_95 ) ;
switch ( V_95 & V_97 ) {
case V_98 :
V_82 = F_48 ( 32 ) ;
break;
case V_99 :
V_82 = F_48 ( 64 ) ;
break;
case V_100 :
V_82 = F_48 ( 96 ) ;
break;
case V_101 :
V_82 = F_48 ( 128 ) ;
break;
case V_102 :
V_82 = F_48 ( 160 ) ;
break;
case V_103 :
V_82 = F_48 ( 192 ) ;
break;
case V_104 :
V_82 = F_48 ( 224 ) ;
break;
case V_105 :
V_82 = F_48 ( 256 ) ;
break;
case V_106 :
V_82 = F_48 ( 288 ) ;
break;
case V_107 :
V_82 = F_48 ( 320 ) ;
break;
case V_108 :
V_82 = F_48 ( 352 ) ;
break;
case V_109 :
V_82 = F_48 ( 384 ) ;
break;
case V_110 :
V_82 = F_48 ( 416 ) ;
break;
case V_111 :
V_82 = F_48 ( 448 ) ;
break;
case V_112 :
V_82 = F_48 ( 480 ) ;
break;
case V_113 :
V_82 = F_48 ( 512 ) ;
break;
}
} else {
switch ( V_78 & V_114 ) {
case V_115 :
V_82 = F_48 ( 1 ) ;
break;
case V_116 :
V_82 = F_48 ( 4 ) ;
break;
case V_117 :
V_82 = F_48 ( 8 ) ;
break;
case V_118 :
V_82 = F_48 ( 16 ) ;
break;
case V_119 :
V_82 = F_48 ( 32 ) ;
break;
case V_120 :
V_82 = F_48 ( 48 ) ;
break;
case V_121 :
V_82 = F_48 ( 64 ) ;
break;
case V_122 :
V_82 = F_48 ( 128 ) ;
break;
case V_123 :
V_82 = F_48 ( 256 ) ;
break;
case V_124 :
V_82 = F_48 ( 96 ) ;
break;
case V_125 :
V_82 = F_48 ( 160 ) ;
break;
case V_126 :
V_82 = F_48 ( 224 ) ;
break;
case V_127 :
V_82 = F_48 ( 352 ) ;
break;
default:
V_82 = 0 ;
break;
}
}
if ( V_82 > 0 ) {
F_29 ( & V_12 . V_84 -> V_42 , L_4 ,
V_82 / F_25 ( 1 ) , V_80 ? L_5 : L_6 ) ;
} else {
F_29 ( & V_12 . V_84 -> V_42 ,
L_7 ) ;
V_82 = 0 ;
}
return V_82 ;
}
static void F_52 ( unsigned int V_128 )
{
T_1 V_129 , V_130 ;
V_130 = F_28 ( V_12 . V_34 + V_131 ) ;
V_130 &= ~ V_35 ;
F_26 ( V_130 , V_12 . V_34 + V_131 ) ;
V_129 = F_28 ( V_12 . V_34 + V_36 ) ;
V_129 &= ~ V_132 ;
V_129 |= V_128 ;
F_26 ( V_129 , V_12 . V_34 + V_36 ) ;
}
static unsigned int F_53 ( void )
{
int V_133 ;
T_1 V_129 ;
T_5 V_134 ;
F_47 ( V_12 . V_84 ,
V_85 , & V_134 ) ;
if ( V_83 == 5 ) {
switch ( V_134 & V_135 ) {
case V_136 :
case V_137 :
F_52 ( V_138 ) ;
break;
case V_139 :
F_52 ( V_140 ) ;
break;
case V_141 :
case V_142 :
F_52 ( V_143 ) ;
break;
}
}
V_129 = F_28 ( V_12 . V_34 + V_36 ) ;
switch ( V_129 & V_132 ) {
case V_144 :
V_133 = F_25 ( 128 ) ;
break;
case V_145 :
V_133 = F_25 ( 256 ) ;
break;
case V_146 :
V_133 = F_25 ( 512 ) ;
break;
case V_138 :
V_133 = F_25 ( 1024 ) ;
break;
case V_143 :
V_133 = F_25 ( 2048 ) ;
break;
case V_140 :
V_133 = F_25 ( 1024 + 512 ) ;
break;
default:
F_29 ( & V_12 . V_13 -> V_42 ,
L_8 ) ;
V_133 = F_25 ( 512 ) ;
}
return V_133 / 4 ;
}
static unsigned int F_54 ( void )
{
int V_133 ;
if ( V_147 || V_83 == 4 || V_83 == 5 )
return F_53 () ;
else if ( V_83 == 6 ) {
T_5 V_95 ;
F_47 ( V_12 . V_13 , V_96 , & V_95 ) ;
switch ( V_95 & V_148 ) {
default:
case V_149 :
F_55 ( V_150 L_9 , V_95 ) ;
V_133 = F_48 ( 0 ) ;
break;
case V_151 :
V_133 = F_48 ( 1 ) ;
break;
case V_152 :
V_133 = F_48 ( 2 ) ;
break;
}
return V_133 / 4 ;
} else {
return V_12 . V_66 . V_153 ;
}
}
static unsigned int F_56 ( void )
{
unsigned int V_154 ;
if ( V_83 == 1 ) {
T_1 V_155 ;
F_23 ( V_12 . V_84 ,
V_156 , & V_155 ) ;
if ( ( V_155 & V_157 )
== V_158 )
V_154 = F_48 ( 32 ) ;
else
V_154 = F_48 ( 64 ) ;
} else if ( V_83 == 2 ) {
T_5 V_78 ;
F_47 ( V_12 . V_84 ,
V_85 , & V_78 ) ;
if ( ( V_78 & V_159 ) == V_160 )
V_154 = F_48 ( 64 ) ;
else
V_154 = F_48 ( 128 ) ;
} else {
V_154 = F_57 ( V_12 . V_13 , 2 ) ;
}
return V_154 >> V_49 ;
}
static void F_58 ( void )
{
F_14 ( V_12 . V_69 , 1 ) ;
F_59 ( V_12 . V_13 , V_12 . V_66 . V_68 ,
V_11 , V_16 ) ;
F_19 ( V_12 . V_69 ) ;
F_60 ( V_12 . V_69 ) ;
}
static void F_61 ( void )
{
V_12 . V_50 -> V_161 () ;
F_62 ( V_12 . V_52 ) ;
F_62 ( V_12 . V_34 ) ;
F_58 () ;
}
static int F_63 ( void )
{
T_1 V_162 ;
T_1 V_163 ;
int V_164 ;
V_164 = V_12 . V_50 -> V_165 () ;
if ( V_164 != 0 )
return V_164 ;
V_12 . V_66 . V_153 = F_56 () ;
V_12 . V_66 . V_166 = F_54 () ;
V_12 . V_167 =
F_28 ( V_12 . V_34 + V_36 )
& ~ V_35 ;
if ( V_168 )
V_12 . V_167 |= V_35 ;
F_29 ( & V_12 . V_84 -> V_42 ,
L_10 ,
V_12 . V_66 . V_166 * 4 ,
V_12 . V_66 . V_153 * 4 ) ;
V_163 = V_12 . V_66 . V_166 * 4 ;
V_12 . V_52 = NULL ;
if ( V_83 < 6 && V_83 > 2 )
V_12 . V_52 = F_64 ( V_12 . V_37 ,
V_163 ) ;
if ( V_12 . V_52 == NULL )
V_12 . V_52 = F_24 ( V_12 . V_37 ,
V_163 ) ;
if ( V_12 . V_52 == NULL ) {
V_12 . V_50 -> V_161 () ;
F_62 ( V_12 . V_34 ) ;
return - V_17 ;
}
V_12 . V_66 . V_52 = V_12 . V_52 ;
F_33 () ;
V_12 . V_66 . V_82 = F_46 () ;
V_12 . V_66 . V_67 = V_169 && V_83 > 2 ;
V_164 = F_41 () ;
if ( V_164 != 0 ) {
F_61 () ;
return V_164 ;
}
if ( V_83 <= 2 )
F_23 ( V_12 . V_13 , V_170 ,
& V_162 ) ;
else
F_23 ( V_12 . V_13 , V_171 ,
& V_162 ) ;
V_12 . V_66 . V_172 = ( V_162 & V_173 ) ;
return 0 ;
}
static int F_65 ( void )
{
int V_174 = F_66 ( V_175 ) ;
unsigned int V_176 ;
int V_8 ;
V_176 = ( V_12 . V_66 . V_153 << V_49 )
/ F_48 ( 1 ) ;
for ( V_8 = 0 ; V_8 < V_174 ; V_8 ++ ) {
if ( V_176 == V_175 [ V_8 ] . V_133 ) {
V_27 -> V_177 =
( void * ) ( V_175 + V_8 ) ;
return V_176 ;
}
}
return 0 ;
}
static void F_67 ( void )
{
}
static void F_68 ( void )
{
unsigned long V_178 = V_179 + F_69 ( 1000 ) ;
F_70 () ;
F_26 ( F_28 ( V_12 . V_34 + V_180 ) | ( 1 << 31 ) ,
V_12 . V_34 + V_180 ) ;
while ( F_28 ( V_12 . V_34 + V_180 ) & ( 1 << 31 ) ) {
if ( F_71 ( V_179 , V_178 ) )
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
F_26 ( V_48 | V_72 , V_12 . V_52 + V_70 ) ;
}
bool F_74 ( void )
{
T_6 T_7 * V_181 ;
if ( V_83 >= 6 )
return true ;
if ( V_83 == 2 ) {
T_5 V_78 ;
F_47 ( V_12 . V_84 ,
V_85 , & V_78 ) ;
V_78 |= V_182 ;
F_75 ( V_12 . V_84 ,
V_85 , V_78 ) ;
F_47 ( V_12 . V_84 ,
V_85 , & V_78 ) ;
if ( ( V_78 & V_182 ) == 0 ) {
F_76 ( & V_12 . V_13 -> V_42 ,
L_11 ,
V_78 ) ;
return false ;
}
}
if ( V_83 >= 3 )
F_26 ( 0 , V_12 . V_34 + V_183 ) ;
V_181 = V_12 . V_34 + V_36 ;
F_26 ( V_12 . V_167 , V_181 ) ;
if ( V_168 && ( F_28 ( V_181 ) & V_35 ) == 0 ) {
F_76 ( & V_12 . V_13 -> V_42 ,
L_12 ,
F_28 ( V_181 ) , V_12 . V_167 ) ;
return false ;
}
if ( V_83 >= 3 )
F_26 ( 0 , V_12 . V_34 + V_183 ) ;
return true ;
}
static int F_77 ( void )
{
T_1 V_29 ;
F_23 ( V_12 . V_13 , V_33 , & V_29 ) ;
V_29 &= 0xfff80000 ;
V_12 . V_34 = F_24 ( V_29 , F_25 ( 64 ) ) ;
if ( ! V_12 . V_34 )
return - V_17 ;
V_12 . V_37 = V_29 + V_38 ;
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
V_12 . V_188 = true ;
V_27 -> V_189 = V_12 . V_66 . V_172 ;
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
unsigned int V_45 ,
unsigned int V_71 )
{
struct V_6 * V_7 ;
unsigned int V_191 , V_192 ;
int V_8 , V_193 ;
V_193 = V_45 ;
F_4 (st->sgl, sg, st->nents, i) {
V_191 = F_83 ( V_7 ) >> V_49 ;
for ( V_192 = 0 ; V_192 < V_191 ; V_192 ++ ) {
T_3 V_48 = F_84 ( V_7 ) + ( V_192 << V_49 ) ;
V_12 . V_50 -> V_51 ( V_48 , V_193 , V_71 ) ;
V_193 ++ ;
}
}
F_28 ( V_12 . V_52 + V_193 - 1 ) ;
}
static void F_85 ( unsigned int V_194 ,
unsigned int V_3 ,
struct V_1 * * V_2 ,
unsigned int V_71 )
{
int V_8 , V_193 ;
for ( V_8 = 0 , V_193 = V_194 ; V_8 < V_3 ; V_8 ++ , V_193 ++ ) {
T_3 V_48 = F_36 ( V_2 [ V_8 ] ) ;
V_12 . V_50 -> V_51 ( V_48 ,
V_193 , V_71 ) ;
}
F_28 ( V_12 . V_52 + V_193 - 1 ) ;
}
static int F_86 ( struct V_44 * V_20 ,
T_2 V_45 , int type )
{
int V_164 = - V_46 ;
if ( V_12 . V_66 . V_195 )
return - V_196 ;
if ( V_12 . V_188 ) {
int V_197 = V_12 . V_66 . V_82 / V_11 ;
int V_198 = V_12 . V_66 . V_153 ;
F_87 ( V_197 , V_198 - V_197 ) ;
V_12 . V_188 = false ;
}
if ( V_83 == 1 && type == V_74 )
return F_32 ( V_20 , V_45 , type ) ;
if ( V_20 -> V_21 == 0 )
goto V_199;
if ( V_45 + V_20 -> V_21 > V_12 . V_66 . V_166 )
goto V_200;
if ( type != V_20 -> type )
goto V_200;
if ( ! V_12 . V_50 -> V_201 ( type ) )
goto V_200;
if ( ! V_20 -> V_47 )
F_33 () ;
if ( V_12 . V_66 . V_67 ) {
struct V_4 V_5 ;
V_164 = F_1 ( V_20 -> V_2 , V_20 -> V_21 , & V_5 ) ;
if ( V_164 != 0 )
return V_164 ;
F_82 ( & V_5 , V_45 , type ) ;
V_20 -> V_18 = V_5 . V_14 ;
V_20 -> V_19 = V_5 . V_15 ;
} else
F_85 ( V_45 , V_20 -> V_21 , V_20 -> V_2 ,
type ) ;
V_199:
V_164 = 0 ;
V_200:
V_20 -> V_47 = true ;
return V_164 ;
}
void F_87 ( unsigned int V_194 , unsigned int V_3 )
{
unsigned int V_8 ;
for ( V_8 = V_194 ; V_8 < ( V_194 + V_3 ) ; V_8 ++ ) {
V_12 . V_50 -> V_51 ( V_12 . V_66 . V_68 ,
V_8 , 0 ) ;
}
F_28 ( V_12 . V_52 + V_8 - 1 ) ;
}
static int F_88 ( struct V_44 * V_20 ,
T_2 V_45 , int type )
{
if ( V_20 -> V_21 == 0 )
return 0 ;
if ( V_12 . V_66 . V_195 )
return - V_196 ;
F_87 ( V_45 , V_20 -> V_21 ) ;
if ( V_12 . V_66 . V_67 ) {
F_8 ( V_20 -> V_18 , V_20 -> V_19 ) ;
V_20 -> V_18 = NULL ;
V_20 -> V_19 = 0 ;
}
return 0 ;
}
static struct V_44 * F_89 ( T_4 V_53 ,
int type )
{
struct V_44 * V_54 ;
if ( type == V_74 && V_83 == 1 ) {
if ( V_53 != V_12 . V_43 )
return NULL ;
V_54 = F_35 ( 1 ) ;
if ( V_54 == NULL )
return NULL ;
V_54 -> type = V_74 ;
V_54 -> V_21 = V_53 ;
V_54 -> V_56 = 0 ;
F_39 ( V_54 ) ;
return V_54 ;
}
if ( type == V_57 )
return F_34 ( V_53 , type ) ;
return NULL ;
}
static int F_90 ( void )
{
int V_164 ;
V_164 = F_91 ( V_12 . V_84 -> V_202 , & V_12 . V_203 , V_11 ,
V_11 , V_204 , 0 ,
V_205 , V_12 . V_84 ) ;
return V_164 ;
}
static void F_92 ( void )
{
int V_164 ;
T_1 V_206 ;
F_23 ( V_12 . V_84 , V_207 , & V_206 ) ;
if ( ! ( V_206 & 0x1 ) ) {
F_90 () ;
V_12 . V_208 = 1 ;
F_93 ( V_12 . V_84 , V_207 , ( V_12 . V_203 . V_197 & 0xffffffff ) | 0x1 ) ;
} else {
V_206 &= ~ 1 ;
V_12 . V_208 = 1 ;
V_12 . V_203 . V_197 = V_206 ;
V_12 . V_203 . V_198 = V_206 + V_11 ;
V_164 = F_94 ( & V_209 , & V_12 . V_203 ) ;
if ( V_164 )
V_12 . V_208 = 0 ;
}
}
static void F_95 ( void )
{
T_1 V_210 , V_211 ;
int V_164 ;
F_23 ( V_12 . V_84 , V_212 + 4 , & V_210 ) ;
F_23 ( V_12 . V_84 , V_212 , & V_211 ) ;
if ( ! ( V_211 & 0x1 ) ) {
F_90 () ;
V_12 . V_208 = 1 ;
F_93 ( V_12 . V_84 , V_212 + 4 ,
F_96 ( V_12 . V_203 . V_197 ) ) ;
F_93 ( V_12 . V_84 , V_212 , ( V_12 . V_203 . V_197 & 0xffffffff ) | 0x1 ) ;
} else {
T_8 V_213 ;
V_211 &= ~ 0x1 ;
V_213 = ( ( T_8 ) V_210 << 32 ) | V_211 ;
V_12 . V_208 = 1 ;
V_12 . V_203 . V_197 = V_213 ;
V_12 . V_203 . V_198 = V_213 + V_11 ;
V_164 = F_94 ( & V_209 , & V_12 . V_203 ) ;
if ( V_164 )
V_12 . V_208 = 0 ;
}
}
static void F_97 ( void )
{
if ( V_12 . V_203 . V_197 )
return;
if ( V_83 == 6 )
return;
V_12 . V_203 . V_214 = L_13 ;
V_12 . V_203 . V_71 = V_215 ;
if ( V_147 || V_83 >= 4 ) {
F_95 () ;
} else {
F_92 () ;
}
if ( V_12 . V_203 . V_197 )
V_12 . V_216 = F_98 ( V_12 . V_203 . V_197 , V_11 ) ;
if ( ! V_12 . V_216 )
F_76 ( & V_12 . V_13 -> V_42 ,
L_14 ) ;
}
static void F_99 ( void )
{
if ( V_12 . V_216 )
F_62 ( V_12 . V_216 ) ;
if ( V_12 . V_208 )
F_100 ( & V_12 . V_203 ) ;
V_12 . V_203 . V_197 = 0 ;
V_12 . V_208 = 0 ;
}
static void F_101 ( void )
{
if ( V_12 . V_216 )
F_26 ( 1 , V_12 . V_216 ) ;
}
static void F_102 ( T_3 V_48 ,
unsigned int V_70 ,
unsigned int V_71 )
{
T_1 V_72 ;
V_72 = V_73 ;
if ( V_71 == V_76 )
V_72 |= V_77 ;
V_48 |= ( V_48 >> 28 ) & 0xf0 ;
F_26 ( V_48 | V_72 , V_12 . V_52 + V_70 ) ;
}
static bool F_103 ( unsigned int V_71 )
{
return true ;
}
static void F_104 ( T_3 V_48 , unsigned int V_70 ,
unsigned int V_71 )
{
unsigned int V_217 = V_71 & ~ V_218 ;
unsigned int V_219 = V_71 & V_218 ;
T_1 V_72 ;
if ( V_217 == V_190 )
V_72 = V_220 | V_73 ;
else if ( V_217 == V_221 ) {
V_72 = V_222 | V_73 ;
if ( V_219 )
V_72 |= V_223 ;
} else {
V_72 = V_224 | V_73 ;
if ( V_219 )
V_72 |= V_223 ;
}
V_48 |= ( V_48 >> 28 ) & 0xff0 ;
F_26 ( V_48 | V_72 , V_12 . V_52 + V_70 ) ;
}
static void F_105 ( T_3 V_48 , unsigned int V_70 ,
unsigned int V_71 )
{
unsigned int V_217 = V_71 & ~ V_218 ;
unsigned int V_219 = V_71 & V_218 ;
T_1 V_72 ;
if ( V_217 == V_190 )
V_72 = V_225 | V_73 ;
else if ( V_217 == V_221 ) {
V_72 = V_222 | V_73 ;
if ( V_219 )
V_72 |= V_223 ;
} else {
V_72 = V_224 | V_73 ;
if ( V_219 )
V_72 |= V_223 ;
}
V_48 |= ( V_48 >> 28 ) & 0xff0 ;
F_26 ( V_48 | V_72 , V_12 . V_52 + V_70 ) ;
}
static void F_106 ( T_3 V_48 , unsigned int V_70 ,
unsigned int V_71 )
{
unsigned int V_217 = V_71 & ~ V_218 ;
unsigned int V_219 = V_71 & V_218 ;
T_1 V_72 ;
if ( V_217 == V_190 )
V_72 = V_225 | V_73 ;
else {
V_72 = V_224 | V_73 ;
if ( V_219 )
V_72 |= V_223 ;
}
V_48 |= ( V_48 >> 28 ) & 0xff0 ;
F_26 ( V_48 | V_72 , V_12 . V_52 + V_70 ) ;
F_26 ( 1 , V_12 . V_34 + V_226 ) ;
}
static void F_107 ( void )
{
}
static inline int F_108 ( void )
{
#ifdef F_109
const unsigned short V_227 = V_12 . V_13 -> V_86 ;
if ( ( V_227 == V_228 ||
V_227 == V_229 ) &&
V_230 )
return 1 ;
#endif
return 0 ;
}
static int F_110 ( void )
{
T_1 V_29 ;
int V_133 = F_25 ( 512 ) ;
F_23 ( V_12 . V_13 , V_231 , & V_29 ) ;
V_29 &= 0xfff80000 ;
if ( V_83 >= 7 )
V_133 = F_48 ( 2 ) ;
V_12 . V_34 = F_24 ( V_29 , V_133 ) ;
if ( ! V_12 . V_34 )
return - V_17 ;
if ( V_83 == 3 ) {
T_1 V_232 ;
F_23 ( V_12 . V_13 ,
V_233 , & V_232 ) ;
V_12 . V_37 = V_232 ;
} else {
T_1 V_234 ;
switch ( V_83 ) {
case 5 :
case 6 :
case 7 :
V_234 = F_48 ( 2 ) ;
break;
case 4 :
default:
V_234 = F_25 ( 512 ) ;
break;
}
V_12 . V_37 = V_29 + V_234 ;
}
if ( F_108 () )
V_12 . V_66 . V_195 = 1 ;
F_97 () ;
return 0 ;
}
static int F_111 ( T_5 V_86 )
{
struct V_235 * V_236 ;
V_236 = F_112 ( V_237 , V_86 , NULL ) ;
if ( V_236 && F_113 ( V_236 -> V_238 ) != 0 ) {
V_236 = F_112 ( V_237 ,
V_86 , V_236 ) ;
}
if ( ! V_236 )
return 0 ;
V_12 . V_13 = V_236 ;
return 1 ;
}
int F_114 ( struct V_235 * V_239 , struct V_235 * V_240 ,
struct V_23 * V_24 )
{
int V_8 , V_241 ;
if ( V_12 . V_50 ) {
V_12 . V_242 ++ ;
return 1 ;
}
for ( V_8 = 0 ; V_243 [ V_8 ] . V_214 != NULL ; V_8 ++ ) {
if ( V_240 ) {
if ( V_240 -> V_86 ==
V_243 [ V_8 ] . V_244 ) {
V_12 . V_13 = F_115 ( V_240 ) ;
V_12 . V_50 =
V_243 [ V_8 ] . V_245 ;
break;
}
} else if ( F_111 ( V_243 [ V_8 ] . V_244 ) ) {
V_12 . V_50 =
V_243 [ V_8 ] . V_245 ;
break;
}
}
if ( ! V_12 . V_50 )
return 0 ;
V_12 . V_242 ++ ;
if ( V_24 ) {
V_24 -> V_50 = & V_246 ;
V_24 -> V_247 = & V_12 ;
V_24 -> V_42 = V_239 ;
}
V_12 . V_84 = F_115 ( V_239 ) ;
F_29 ( & V_239 -> V_42 , L_15 , V_243 [ V_8 ] . V_214 ) ;
V_241 = V_12 . V_50 -> V_248 ;
if ( F_116 ( V_12 . V_13 , F_117 ( V_241 ) ) )
F_76 ( & V_12 . V_13 -> V_42 ,
L_16 , V_241 ) ;
else
F_118 ( V_12 . V_13 ,
F_117 ( V_241 ) ) ;
if ( F_63 () != 0 ) {
F_119 () ;
return 0 ;
}
return 1 ;
}
const struct V_249 * F_120 ( void )
{
return & V_12 . V_66 ;
}
void F_121 ( void )
{
if ( V_12 . V_50 -> V_250 )
V_12 . V_50 -> V_250 () ;
}
void F_119 ( void )
{
if ( -- V_12 . V_242 )
return;
if ( V_12 . V_13 )
F_122 ( V_12 . V_13 ) ;
if ( V_12 . V_84 )
F_122 ( V_12 . V_84 ) ;
V_12 . V_50 = NULL ;
}
