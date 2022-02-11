static int F_1 ( unsigned long V_1 , unsigned long const V_2 [] ,
int V_3 )
{
int V_4 ;
int V_5 = - V_6 ;
for ( V_4 = 0 ; V_4 < V_3 / 2 ; V_4 ++ )
if ( V_2 [ ( V_4 * 2 ) + 1 ] >= V_1 ) {
V_5 = V_2 [ V_4 * 2 ] ;
break;
}
return V_5 ;
}
static T_1 F_2 ( int V_7 , void * V_8 )
{
struct V_9 * V_10 = V_8 ;
F_3 ( 2 , V_11 , & V_10 -> V_12 ,
L_1 , V_13 ) ;
F_4 ( & V_10 -> V_14 ) ;
return V_15 ;
}
static int F_5 ( struct V_9 * V_10 , const T_2 V_16 ,
const T_2 args [] , const int V_17 ,
T_2 V_18 [] , const int V_19 , const int V_1 )
{
struct V_20 * V_21 = F_6 ( & V_10 -> V_12 ) ;
unsigned long V_22 ;
T_2 V_23 [ V_24 + 1 ] ;
int V_25 ;
if ( ! V_21 -> V_26 )
return - V_27 ;
V_23 [ 0 ] = V_16 ;
memcpy ( V_23 + 1 , args , V_17 ) ;
F_7 ( & V_10 -> V_12 , L_2 , V_23 , V_17 + 1 ) ;
V_25 = F_8 ( V_21 , V_23 , V_17 + 1 ) ;
if ( V_25 != V_17 + 1 ) {
F_9 ( & V_10 -> V_12 , L_3 ,
V_16 ) ;
return V_25 < 0 ? V_25 : - V_28 ;
}
V_22 = V_29 + F_10 ( V_1 ) + 1 ;
if ( V_21 -> V_7 ) {
if ( ! F_11 ( & V_10 -> V_14 ,
F_10 ( V_1 ) + 1 ) )
F_12 ( & V_10 -> V_12 ,
L_4 ,
V_13 ) ;
}
do {
V_25 = F_13 ( V_21 , V_18 , V_19 ) ;
if ( V_25 != V_19 ) {
F_9 ( & V_10 -> V_12 ,
L_5 ,
V_25 , V_16 ) ;
return V_25 < 0 ? V_25 : - V_28 ;
}
F_7 ( & V_10 -> V_12 , L_6 , V_18 , V_19 ) ;
if ( ! F_14 ( V_18 [ 0 ] ) )
return 0 ;
if ( V_21 -> V_7 )
return - V_30 ;
if ( V_1 <= 1000 )
F_15 ( V_1 , 1000 ) ;
else
F_15 ( 1000 , 2000 ) ;
} while ( F_16 ( V_22 ) );
return - V_30 ;
}
static int F_17 ( struct V_9 * V_10 , T_3 V_31 , T_4 * V_32 )
{
int V_25 ;
T_2 V_33 [ V_34 ] ;
const T_2 args [ V_35 ] = {
0x00 ,
F_18 ( V_31 ) ,
F_19 ( V_31 ) ,
} ;
V_25 = F_5 ( V_10 , V_36 ,
args , F_20 ( args ) , V_33 ,
F_20 ( V_33 ) , V_37 ) ;
if ( V_25 < 0 )
return V_25 ;
* V_32 = F_21 ( V_33 [ 2 ] , V_33 [ 3 ] ) ;
F_3 ( 1 , V_11 , & V_10 -> V_12 ,
L_7 ,
V_13 , V_31 , * V_32 , V_33 [ 0 ] ) ;
return V_25 ;
}
static int F_22 ( struct V_9 * V_10 , T_3 V_31 , T_3 V_33 )
{
int V_5 ;
T_2 V_38 [ V_39 ] ;
const T_2 args [ V_40 ] = {
0x00 ,
F_18 ( V_31 ) ,
F_19 ( V_31 ) ,
F_18 ( V_33 ) ,
F_19 ( V_33 ) ,
} ;
V_5 = F_5 ( V_10 , V_41 ,
args , F_20 ( args ) ,
V_38 , F_20 ( V_38 ) ,
V_37 ) ;
if ( V_5 < 0 )
return V_5 ;
F_3 ( 1 , V_11 , & V_10 -> V_12 ,
L_7 ,
V_13 , V_31 , V_33 , V_38 [ 0 ] ) ;
F_23 ( V_42 ) ;
return V_5 ;
}
static int F_24 ( struct V_9 * V_10 )
{
struct V_20 * V_21 = F_6 ( & V_10 -> V_12 ) ;
int V_25 ;
T_2 V_38 [ V_43 ] ;
T_2 args [ V_44 ] = {
V_45 | V_46 ,
V_47 ,
} ;
if ( V_10 -> V_48 )
return 0 ;
if ( V_10 -> V_49 ) {
V_25 = F_25 ( V_10 -> V_49 , V_10 -> V_50 ) ;
if ( V_25 ) {
F_9 ( & V_10 -> V_12 , L_8 , V_25 ) ;
return V_25 ;
}
}
if ( F_26 ( V_10 -> V_51 ) ) {
F_27 ( 50 ) ;
F_28 ( V_10 -> V_51 , 1 ) ;
}
if ( V_21 -> V_7 )
args [ 0 ] |= V_52 ;
V_25 = F_5 ( V_10 , V_53 ,
args , F_20 ( args ) ,
V_38 , F_20 ( V_38 ) ,
V_54 ) ;
if ( ! V_25 ) {
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_9 ,
V_38 [ 0 ] ) ;
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_10 ) ;
V_10 -> V_48 = V_55 ;
if ( V_21 -> V_7 )
V_25 = F_22 ( V_10 , V_56 ,
V_57 | V_58 ) ;
return V_25 ;
}
if ( F_26 ( V_10 -> V_51 ) )
F_28 ( V_10 -> V_51 , 0 ) ;
if ( V_10 -> V_49 ) {
V_25 = F_29 ( V_10 -> V_49 , V_10 -> V_50 ) ;
if ( V_25 )
F_9 ( & V_10 -> V_12 ,
L_11 , V_25 ) ;
}
return V_25 ;
}
static int F_30 ( struct V_9 * V_10 )
{
int V_25 ;
T_2 V_38 [ V_59 ] ;
if ( ! V_10 -> V_48 )
return 0 ;
V_25 = F_5 ( V_10 , V_60 ,
NULL , 0 ,
V_38 , F_20 ( V_38 ) ,
V_37 ) ;
if ( ! V_25 ) {
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_12 ,
V_38 [ 0 ] ) ;
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_13 ) ;
if ( F_26 ( V_10 -> V_51 ) )
F_28 ( V_10 -> V_51 , 0 ) ;
if ( V_10 -> V_49 ) {
V_25 = F_29 ( V_10 -> V_49 ,
V_10 -> V_50 ) ;
if ( V_25 )
F_9 ( & V_10 -> V_12 ,
L_11 , V_25 ) ;
}
V_10 -> V_48 = V_61 ;
}
return V_25 ;
}
static int F_31 ( struct V_9 * V_10 )
{
struct V_20 * V_21 = F_6 ( & V_10 -> V_12 ) ;
int V_5 ;
T_2 V_38 [ V_62 ] ;
V_5 = F_5 ( V_10 , V_63 ,
NULL , 0 ,
V_38 , F_20 ( V_38 ) ,
V_37 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_38 [ 1 ] == V_64 ) {
F_32 ( & V_10 -> V_12 , L_14 ,
V_21 -> V_65 << 1 , V_21 -> V_26 -> V_66 ) ;
} else {
F_9 ( & V_10 -> V_12 , L_15 , V_38 [ 1 ] ) ;
V_5 = - V_6 ;
}
return V_5 ;
}
static int F_33 ( struct V_9 * V_10 , const int V_1 )
{
struct V_20 * V_21 = F_6 ( & V_10 -> V_12 ) ;
T_2 V_38 [ V_67 ] ;
unsigned long V_68 = V_29 ;
int V_25 ;
if ( V_21 -> V_7 &&
! F_11 ( & V_10 -> V_14 , F_10 ( V_1 ) + 1 ) )
F_12 ( & V_10 -> V_12 ,
L_4 , V_13 ) ;
for (; ; ) {
V_25 = F_5 ( V_10 , V_69 ,
NULL , 0 ,
V_38 , F_20 ( V_38 ) ,
V_37 ) ;
if ( V_25 >= 0 ) {
F_3 ( 1 , V_11 , & V_10 -> V_12 ,
L_16 , V_13 , V_38 [ 0 ] ) ;
if ( V_38 [ 0 ] & V_57 )
return 0 ;
}
if ( F_34 ( V_29 - V_68 ) > V_1 )
return V_25 < 0 ? V_25 : - V_28 ;
F_15 ( 3000 , 4000 ) ;
}
}
static int F_35 ( struct V_9 * V_10 , T_3 V_70 )
{
int V_25 ;
T_2 V_33 [ V_71 ] ;
const T_2 args [ V_72 ] = {
0x00 ,
F_18 ( V_70 ) ,
F_19 ( V_70 ) ,
} ;
V_25 = F_5 ( V_10 , V_73 ,
args , F_20 ( args ) , V_33 ,
F_20 ( V_33 ) , V_37 ) ;
if ( V_25 < 0 )
return V_25 ;
F_3 ( 1 , V_11 , & V_10 -> V_12 ,
L_17 , V_13 ,
V_70 , V_33 [ 0 ] ) ;
V_25 = F_33 ( V_10 , V_74 ) ;
if ( V_25 < 0 )
return V_25 ;
return F_21 ( args [ 1 ] , args [ 2 ] ) ;
}
static int F_36 ( struct V_9 * V_10 , T_2 V_75 ,
T_2 V_76 )
{
int V_25 ;
T_2 V_33 [ V_77 ] ;
T_2 args [ V_78 ] = {
0x00 ,
0x00 ,
V_75 ,
V_76 ,
} ;
if ( V_75 > 0 && V_75 < V_79 )
args [ 2 ] = V_75 = V_79 ;
V_25 = F_5 ( V_10 , V_80 ,
args , F_20 ( args ) , V_33 ,
F_20 ( V_33 ) , V_37 ) ;
if ( V_25 < 0 )
return V_25 ;
F_3 ( 1 , V_11 , & V_10 -> V_12 ,
L_18 ,
V_13 , V_75 , V_76 , V_33 [ 0 ] ) ;
return F_33 ( V_10 , V_81 ) ;
}
static int F_37 ( struct V_9 * V_10 , T_3 V_70 ,
T_2 V_76 )
{
int V_25 ;
T_2 V_33 [ V_82 ] ;
const T_2 args [ V_83 ] = {
0x00 ,
F_18 ( V_70 ) ,
F_19 ( V_70 ) ,
V_76 ,
} ;
V_10 -> V_84 = V_85 ;
if ( V_76 > V_86 )
return - V_87 ;
V_25 = F_5 ( V_10 , V_88 ,
args , F_20 ( args ) , V_33 ,
F_20 ( V_33 ) , V_37 ) ;
if ( V_25 < 0 )
return V_25 ;
F_3 ( 1 , V_11 , & V_10 -> V_12 ,
L_19 ,
V_13 , V_70 , V_76 , V_33 [ 0 ] ) ;
return F_33 ( V_10 , V_74 ) ;
}
static int F_38 ( struct V_9 * V_10 , T_2 V_89 ,
T_3 * V_70 , T_2 * V_75 ,
T_2 * V_76 , T_2 * V_90 )
{
int V_25 ;
T_2 V_33 [ V_91 ] ;
const T_2 args [ V_92 ] = {
V_89 & V_93 ,
} ;
V_25 = F_5 ( V_10 , V_94 ,
args , F_20 ( args ) , V_33 ,
F_20 ( V_33 ) , V_37 ) ;
if ( ! V_25 ) {
F_3 ( 1 , V_11 , & V_10 -> V_12 ,
L_20 , V_13 , V_33 [ 0 ] ) ;
* V_70 = F_21 ( V_33 [ 2 ] , V_33 [ 3 ] ) ;
V_10 -> V_70 = * V_70 ;
* V_75 = V_33 [ 5 ] ;
* V_76 = V_33 [ 6 ] ;
* V_90 = V_33 [ 7 ] ;
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_21
L_22 , V_13 ,
* V_70 , * V_75 , * V_76 , * V_90 ) ;
}
return V_25 ;
}
static int F_39 ( struct V_9 * V_10 , T_2 V_95 , T_3 V_96 ,
T_3 V_97 , T_3 V_98 , T_5 * V_99 )
{
int V_25 ;
T_2 V_33 [ V_100 ] ;
const T_2 args [ V_101 ] = {
V_95 & V_102 ,
F_18 ( V_96 ) ,
F_19 ( V_96 ) ,
F_18 ( V_97 ) ,
F_19 ( V_97 ) ,
F_18 ( V_98 ) ,
F_19 ( V_98 ) ,
} ;
V_25 = F_5 ( V_10 , V_103 ,
args , F_20 ( args ) , V_33 ,
F_20 ( V_33 ) , V_37 ) ;
if ( ! V_25 ) {
F_3 ( 1 , V_11 , & V_10 -> V_12 ,
L_20 , V_13 , V_33 [ 0 ] ) ;
* V_99 = ( T_5 ) V_33 [ 2 ] - V_33 [ 3 ] ;
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_23
L_24
L_25 , V_13 , V_33 [ 1 ] ,
V_33 [ 2 ] , V_33 [ 3 ] , V_33 [ 4 ] , V_33 [ 5 ] ) ;
}
return V_25 ;
}
static int F_40 ( struct V_9 * V_10 , T_2 V_104 ,
unsigned char * V_105 )
{
int V_25 ;
T_2 V_33 [ V_106 ] ;
const T_2 args [ V_107 ] = {
V_104 & V_108 ,
V_105 [ 0 ] ,
V_105 [ 1 ] ,
V_105 [ 2 ] ,
V_105 [ 3 ] ,
} ;
V_25 = F_5 ( V_10 , V_109 ,
args , F_20 ( args ) , V_33 ,
F_20 ( V_33 ) , V_37 ) ;
if ( V_25 < 0 )
return V_25 ;
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_20 , V_13 , V_33 [ 0 ] ) ;
return V_25 ;
}
static int F_41 ( struct V_9 * V_10 , T_2 V_110 )
{
if ( V_110 )
return F_24 ( V_10 ) ;
return F_30 ( V_10 ) ;
}
static int F_42 ( struct V_9 * V_10 , T_3 V_111 )
{
int V_5 = 0 ;
V_111 = F_43 ( V_111 ) ;
if ( V_10 -> V_48 )
V_5 = F_22 ( V_10 ,
V_112 , V_111 ) ;
return V_5 ;
}
static int F_44 ( struct V_9 * V_10 , char * V_113 )
{
int V_5 = 0 , V_4 ;
T_2 V_114 = 0 ;
if ( ! strlen ( V_113 ) )
memset ( V_113 , 0 , V_115 + 1 ) ;
if ( V_10 -> V_48 ) {
for ( V_4 = 0 ; V_4 < V_115 ; V_4 += ( V_116 / 2 ) ) {
V_5 = F_40 ( V_10 , ( V_4 / ( V_116 / 2 ) ) ,
V_113 + V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( strlen ( V_113 ) )
V_114 = strlen ( V_113 ) - 1 ;
else
V_114 = 1 ;
V_5 = F_22 ( V_10 ,
V_117 ,
F_45 ( V_114 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_22 ( V_10 ,
V_118 ,
V_119 * 2 ) ;
if ( V_5 < 0 )
return V_5 ;
}
return V_5 ;
}
static int F_46 ( struct V_9 * V_10 , const char * V_120 )
{
static const char V_121 [ V_122 ] = { V_123 , 0 } ;
int V_5 = 0 , V_4 ;
T_3 V_124 = 0 ;
T_2 V_125 = 0 , V_126 = 0 ;
T_5 V_127 ;
if ( ! V_10 -> V_48 )
return V_5 ;
V_5 = F_39 ( V_10 , V_128 , 0 , 0 , 0 , & V_127 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ! strlen ( V_120 ) )
return V_5 ;
do {
if ( V_124 < ( V_129 * V_122 ) ) {
for ( V_4 = 0 ; V_4 < V_122 ; V_4 ++ ) {
if ( ! V_120 [ V_124 + V_4 ] ||
V_120 [ V_124 + V_4 ] == V_123 ) {
V_120 = V_121 ;
V_126 = 1 ;
break;
}
}
}
V_5 = F_39 ( V_10 , V_130 ,
F_21 ( V_131 , V_125 ++ ) ,
F_21 ( V_120 [ V_124 ] , V_120 [ V_124 + 1 ] ) ,
F_21 ( V_120 [ V_124 + 2 ] , V_120 [ V_124 + 3 ] ) ,
& V_127 ) ;
if ( V_5 < 0 )
return V_5 ;
V_124 += V_122 ;
if ( V_126 )
break;
} while ( V_127 > 0 );
return V_5 ;
}
static int F_47 ( struct V_9 * V_10 )
{
int V_5 ;
T_3 V_132 = 0 ;
T_2 V_133 = 0 , V_134 = 0 , V_135 = 0 ;
V_5 = F_38 ( V_10 , 0x00 , & V_132 , & V_133 , & V_134 , & V_135 ) ;
if ( V_5 < 0 )
goto exit;
V_10 -> V_84 = V_135 ;
exit:
return V_5 ;
}
static int F_48 ( struct V_9 * V_10 , T_4 V_136 ,
T_6 * V_137 , T_6 * V_138 , T_3 * V_139 , int * V_140 ,
unsigned long * * V_141 , int * V_3 )
{
T_6 V_5 = 0 ;
switch ( V_136 ) {
case V_142 :
* V_139 = V_143 ;
* V_140 = 1 ;
break;
case V_144 :
* V_139 = V_145 ;
* V_140 = 1 ;
break;
case V_146 :
* V_139 = V_147 ;
* V_140 = 1 ;
break;
case V_148 :
* V_139 = V_149 ;
* V_140 = 1 ;
break;
case V_150 :
* V_139 = V_151 ;
* V_140 = V_152 ;
break;
case V_153 :
* V_139 = V_154 ;
* V_140 = 10 ;
break;
case V_155 :
* V_139 = V_156 ;
* V_140 = 10 ;
break;
case V_157 :
* V_139 = V_158 ;
* V_140 = 1 ;
break;
case V_159 :
* V_139 = V_160 ;
* V_137 = 5 ;
* V_138 = 0x1F << 5 ;
break;
case V_161 :
* V_139 = V_162 ;
* V_137 = 1 ;
* V_138 = 1 << 1 ;
break;
case V_163 :
* V_139 = V_162 ;
* V_137 = 0 ;
* V_138 = 1 << 0 ;
break;
case V_164 :
* V_139 = V_165 ;
* V_137 = 0 ;
* V_138 = 1 << 0 ;
break;
case V_166 :
* V_139 = V_167 ;
* V_141 = V_168 ;
* V_3 = F_20 ( V_168 ) ;
break;
case V_169 :
* V_139 = V_170 ;
* V_141 = V_171 ;
* V_3 = F_20 ( V_171 ) ;
break;
case V_172 :
* V_139 = V_173 ;
* V_141 = V_174 ;
* V_3 = F_20 ( V_174 ) ;
break;
default:
V_5 = - V_6 ;
break;
}
return V_5 ;
}
static int F_49 ( struct V_9 * V_10 )
{
struct V_175 V_132 ;
struct V_176 V_177 ;
int V_5 ;
V_132 . V_178 = 0 ;
V_132 . V_70 = V_10 -> V_70 ? V_10 -> V_70 : V_179 ;
V_132 . V_70 = F_50 ( V_132 . V_70 ) ;
V_5 = F_51 ( & V_10 -> V_12 , & V_132 ) ;
V_177 . V_180 = 0 ;
if ( V_10 -> V_181 )
V_177 . V_182 = V_183 ;
else
V_177 . V_182 = V_184 ;
if ( V_10 -> V_185 )
V_177 . V_182 |= V_186 ;
F_52 ( & V_10 -> V_12 , & V_177 ) ;
return V_5 ;
}
static int F_53 ( struct V_9 * V_10 )
{
int V_5 ;
V_5 = F_41 ( V_10 , V_55 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_31 ( V_10 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_41 ( V_10 , V_61 ) ;
if ( V_5 < 0 )
return V_5 ;
V_10 -> V_70 = V_179 ;
V_10 -> V_181 = 1 ;
V_10 -> V_84 = V_85 ;
return 0 ;
}
static int F_54 ( struct V_187 * V_188 )
{
struct V_9 * V_10 =
F_55 ( V_188 -> V_189 , struct V_9 , V_190 ) ;
T_4 V_33 = 0 ;
T_6 V_137 = 0 , V_138 = 0 ;
T_3 V_139 = 0 ;
int V_140 = 0 ;
unsigned long * V_141 = NULL ;
int V_3 = 0 ;
bool V_191 = false ;
int V_192 ;
int V_193 = 0 ;
if ( V_188 -> V_136 != V_194 )
return - V_6 ;
if ( V_188 -> V_195 ) {
if ( V_188 -> V_33 ) {
V_193 = F_42 ( V_10 , V_188 -> V_33 ) ;
if ( ! V_193 )
V_193 = F_41 ( V_10 , V_196 ) ;
return V_193 ;
}
V_193 = F_41 ( V_10 , V_197 ) ;
if ( ! V_193 )
V_193 = F_42 ( V_10 , V_188 -> V_33 ) ;
if ( ! V_193 )
V_193 = F_49 ( V_10 ) ;
if ( V_193 )
return V_193 ;
V_191 = true ;
}
if ( ! V_10 -> V_48 )
return 0 ;
for ( V_192 = 1 ; ! V_193 && V_192 < V_188 -> V_198 ; V_192 ++ ) {
V_188 = V_188 -> V_199 [ V_192 ] ;
if ( ! V_191 && ! V_188 -> V_195 )
continue;
switch ( V_188 -> V_136 ) {
case V_200 :
V_193 = F_44 ( V_10 , V_188 -> string ) ;
break;
case V_201 :
V_193 = F_46 ( V_10 , V_188 -> string ) ;
break;
case V_202 :
if ( V_191 )
break;
case V_203 :
V_193 = F_36 ( V_10 ,
V_10 -> V_204 -> V_33 , V_10 -> V_205 -> V_33 ) ;
if ( ! V_193 ) {
V_10 -> V_205 -> V_195 = false ;
V_10 -> V_204 -> V_195 = false ;
}
break;
default:
V_193 = F_48 ( V_10 , V_188 -> V_136 , & V_137 ,
& V_138 , & V_139 , & V_140 , & V_141 , & V_3 ) ;
if ( V_193 < 0 )
break;
V_33 = V_188 -> V_33 ;
if ( V_140 ) {
V_33 = V_33 / V_140 ;
} else if ( V_141 ) {
V_193 = F_1 ( V_33 , V_141 , V_3 ) ;
if ( V_193 < 0 )
break;
V_33 = V_193 ;
V_193 = 0 ;
}
if ( V_138 ) {
V_193 = F_17 ( V_10 , V_139 , & V_33 ) ;
if ( V_193 < 0 )
break;
V_33 = F_56 ( V_33 , V_188 -> V_33 , V_137 , V_138 ) ;
}
V_193 = F_22 ( V_10 , V_139 , V_33 ) ;
if ( V_193 < 0 )
break;
if ( V_138 )
V_33 = V_188 -> V_33 ;
break;
}
}
return V_193 ;
}
static long F_57 ( struct V_206 * V_12 , unsigned int V_207 , void * V_208 )
{
struct V_9 * V_10 = F_58 ( V_12 ) ;
struct V_209 * V_210 = V_208 ;
T_3 V_70 ;
int V_5 = 0 ;
if ( ! V_208 )
return - V_6 ;
switch ( V_207 ) {
case V_211 :
V_70 = F_59 ( V_210 -> V_70 ) ;
if ( V_10 -> V_48 ) {
V_5 = F_37 ( V_10 , V_70 , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_47 ( V_10 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_210 -> V_210 = V_10 -> V_84 ;
break;
default:
V_5 = - V_212 ;
}
return V_5 ;
}
static int F_60 ( struct V_206 * V_12 , struct V_176 * V_177 )
{
struct V_9 * V_10 = F_58 ( V_12 ) ;
int V_5 = 0 ;
if ( ! V_10 )
return - V_27 ;
if ( V_177 -> V_180 > 0 )
return - V_6 ;
strncpy ( V_177 -> V_66 , L_26 , 32 ) ;
V_177 -> V_213 = V_214 | V_215 |
V_216 | V_217 ;
V_177 -> V_218 = F_50 ( V_219 ) ;
V_177 -> V_220 = F_50 ( V_221 ) ;
if ( V_10 -> V_48 ) {
T_4 V_222 = 0 ;
V_5 = F_17 ( V_10 , V_165 ,
& V_222 ) ;
if ( V_5 < 0 )
return V_5 ;
V_10 -> V_181 = F_61 ( V_222 , 1 , 1 << 1 ) ;
}
if ( V_10 -> V_181 )
V_177 -> V_182 = V_183 ;
else
V_177 -> V_182 = V_184 ;
if ( V_10 -> V_185 )
V_177 -> V_182 |= V_186 ;
else
V_177 -> V_182 &= ~ V_186 ;
return V_5 ;
}
static int F_52 ( struct V_206 * V_12 , const struct V_176 * V_177 )
{
struct V_9 * V_10 = F_58 ( V_12 ) ;
int V_5 = 0 ;
T_3 V_181 , V_223 ;
T_4 V_133 ;
if ( ! V_10 )
return - V_27 ;
if ( V_177 -> V_180 > 0 )
return - V_6 ;
if ( V_177 -> V_182 & V_183 )
V_181 = 1 ;
else if ( V_177 -> V_182 & V_184 )
V_181 = 0 ;
else
return - V_6 ;
V_223 = ! ! ( V_177 -> V_182 & V_186 ) ;
if ( V_10 -> V_48 ) {
V_5 = F_17 ( V_10 ,
V_165 , & V_133 ) ;
if ( V_5 < 0 )
return V_5 ;
V_133 = F_56 ( V_133 , V_181 , 1 , 1 << 1 ) ;
V_133 = F_56 ( V_133 , V_223 , 2 , 1 << 2 ) ;
V_5 = F_22 ( V_10 ,
V_165 , V_133 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_10 -> V_181 = V_181 ;
V_10 -> V_185 = V_223 ;
return V_5 ;
}
static int F_62 ( struct V_206 * V_12 , struct V_175 * V_132 )
{
struct V_9 * V_10 = F_58 ( V_12 ) ;
int V_5 = 0 ;
if ( V_132 -> V_178 )
return - V_6 ;
if ( V_10 -> V_48 ) {
T_3 V_224 ;
T_2 V_133 , V_134 , V_135 ;
V_5 = F_38 ( V_10 , 0x00 , & V_224 , & V_133 , & V_134 , & V_135 ) ;
if ( V_5 < 0 )
return V_5 ;
V_10 -> V_70 = V_224 ;
}
V_132 -> V_70 = F_50 ( V_10 -> V_70 ) ;
return V_5 ;
}
static int F_51 ( struct V_206 * V_12 , const struct V_175 * V_132 )
{
struct V_9 * V_10 = F_58 ( V_12 ) ;
int V_5 = 0 ;
T_3 V_70 = F_59 ( V_132 -> V_70 ) ;
if ( V_132 -> V_178 )
return - V_6 ;
V_70 = F_63 ( T_3 , V_70 , V_219 , V_221 ) ;
if ( V_10 -> V_48 ) {
V_5 = F_35 ( V_10 , V_70 ) ;
if ( V_5 < 0 )
return V_5 ;
V_70 = V_5 ;
V_5 = 0 ;
}
V_10 -> V_70 = V_70 ;
return V_5 ;
}
static int F_64 ( struct V_20 * V_21 ,
const struct V_225 * V_136 )
{
struct V_9 * V_10 ;
struct V_226 * V_227 = V_21 -> V_8 . V_228 ;
struct V_229 * V_230 ;
int V_5 , V_4 ;
V_10 = F_65 ( sizeof( * V_10 ) , V_231 ) ;
if ( ! V_10 ) {
F_66 ( & V_21 -> V_8 , L_27 ) ;
V_5 = - V_232 ;
goto exit;
}
V_10 -> V_51 = - 1 ;
if ( V_227 && F_26 ( V_227 -> V_51 ) ) {
V_5 = F_67 ( V_227 -> V_51 , L_28 ) ;
if ( V_5 ) {
F_66 ( & V_21 -> V_8 ,
L_29 , V_5 ) ;
goto V_233;
}
V_10 -> V_51 = V_227 -> V_51 ;
F_68 ( V_10 -> V_51 , 0 ) ;
V_10 -> V_49 = V_227 -> V_49 ;
}
for ( V_4 = 0 ; V_4 < V_10 -> V_49 ; V_4 ++ )
V_10 -> V_50 [ V_4 ] . V_234 = V_227 -> V_235 [ V_4 ] ;
V_5 = F_69 ( & V_21 -> V_8 , V_10 -> V_49 ,
V_10 -> V_50 ) ;
if ( V_5 ) {
F_66 ( & V_21 -> V_8 , L_30 , V_5 ) ;
goto V_236;
}
F_70 ( & V_10 -> V_12 , V_21 , & V_237 ) ;
F_71 ( & V_10 -> V_14 ) ;
V_230 = & V_10 -> V_190 ;
F_72 ( V_230 , 20 ) ;
V_10 -> V_111 = F_73 ( V_230 , & V_238 ,
V_194 , 0 , 1 , 1 , V_239 ) ;
V_10 -> V_240 = F_73 ( V_230 , & V_238 ,
V_142 , 0 , 0xffff , 1 , V_241 ) ;
V_10 -> V_242 = F_73 ( V_230 , & V_238 ,
V_159 , 0 , 31 , 1 , V_243 ) ;
V_10 -> V_244 = F_73 ( V_230 , & V_238 ,
V_157 , 0 , V_245 ,
10 , V_246 ) ;
V_10 -> V_247 = F_73 ( V_230 , & V_238 ,
V_200 , 0 , V_115 , 8 , 0 ) ;
V_10 -> V_248 = F_73 ( V_230 , & V_238 ,
V_201 , 0 , V_249 , 32 , 0 ) ;
V_10 -> V_250 = F_73 ( V_230 , & V_238 ,
V_161 , 0 , 1 , 1 , 1 ) ;
V_10 -> V_251 = F_73 ( V_230 , & V_238 ,
V_166 , 250 ,
V_252 , 10 , V_253 ) ;
V_10 -> V_254 = F_73 ( V_230 , & V_238 ,
V_155 , 0 ,
V_255 , 10 , V_256 ) ;
V_10 -> V_257 = F_73 ( V_230 , & V_238 ,
V_163 , 0 , 1 , 1 , 1 ) ;
V_10 -> V_258 = F_73 ( V_230 , & V_238 ,
V_146 , 0 , V_259 , 1 ,
V_260 ) ;
V_10 -> V_261 = F_73 ( V_230 , & V_238 ,
V_144 ,
V_262 , V_263 , 1 ,
V_264 ) ;
V_10 -> V_265 = F_73 ( V_230 , & V_238 ,
V_150 , 0 ,
V_266 , 500 , V_267 ) ;
V_10 -> V_268 = F_73 ( V_230 , & V_238 ,
V_169 , 100000 ,
V_269 , 100000 , V_270 ) ;
V_10 -> V_271 = F_73 ( V_230 , & V_238 ,
V_164 , 0 , 1 , 1 , 1 ) ;
V_10 -> V_272 = F_73 ( V_230 , & V_238 ,
V_153 , 0 , V_273 ,
10 , V_274 ) ;
V_10 -> V_275 = F_73 ( V_230 , & V_238 ,
V_148 , 0 , V_276 ,
1 , V_277 ) ;
V_10 -> V_278 = F_74 ( V_230 , & V_238 ,
V_172 ,
V_279 , 0 , V_280 ) ;
V_10 -> V_204 = F_73 ( V_230 , & V_238 ,
V_203 , 0 , V_281 ,
1 , V_282 ) ;
V_10 -> V_205 = F_73 ( V_230 , & V_238 ,
V_202 , 0 , V_86 ,
1 , 0 ) ;
if ( V_230 -> error ) {
V_5 = V_230 -> error ;
goto V_283;
}
F_75 ( 20 , & V_10 -> V_111 ) ;
V_10 -> V_12 . V_190 = V_230 ;
if ( V_21 -> V_7 ) {
V_5 = F_76 ( V_21 -> V_7 ,
F_2 , V_284 ,
V_21 -> V_66 , V_10 ) ;
if ( V_5 < 0 ) {
F_9 ( & V_10 -> V_12 , L_31 ) ;
goto V_285;
}
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_32 ) ;
} else {
F_12 ( & V_10 -> V_12 , L_33 ) ;
}
V_5 = F_53 ( V_10 ) ;
if ( V_5 < 0 ) {
F_9 ( & V_10 -> V_12 , L_34 ) ;
goto V_286;
}
return 0 ;
V_286:
if ( V_21 -> V_7 )
V_286 ( V_21 -> V_7 , V_10 ) ;
V_283:
F_77 ( V_230 ) ;
V_285:
F_78 ( V_10 -> V_49 , V_10 -> V_50 ) ;
V_236:
if ( F_26 ( V_10 -> V_51 ) )
F_79 ( V_10 -> V_51 ) ;
V_233:
F_80 ( V_10 ) ;
exit:
return V_5 ;
}
static int F_81 ( struct V_20 * V_21 )
{
struct V_206 * V_12 = F_82 ( V_21 ) ;
struct V_9 * V_10 = F_58 ( V_12 ) ;
if ( V_10 -> V_48 )
F_41 ( V_10 , V_196 ) ;
if ( V_21 -> V_7 > 0 )
V_286 ( V_21 -> V_7 , V_10 ) ;
F_83 ( V_12 ) ;
F_77 ( V_12 -> V_190 ) ;
F_78 ( V_10 -> V_49 , V_10 -> V_50 ) ;
if ( F_26 ( V_10 -> V_51 ) )
F_79 ( V_10 -> V_51 ) ;
F_80 ( V_10 ) ;
return 0 ;
}
