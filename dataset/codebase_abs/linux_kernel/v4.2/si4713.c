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
V_25 = F_25 ( V_10 -> V_49 ) ;
if ( V_25 ) {
F_9 ( & V_10 -> V_12 , L_8 , V_25 ) ;
return V_25 ;
}
}
if ( V_10 -> V_50 ) {
V_25 = F_25 ( V_10 -> V_50 ) ;
if ( V_25 ) {
F_9 ( & V_10 -> V_12 , L_9 , V_25 ) ;
return V_25 ;
}
}
if ( V_10 -> V_51 ) {
F_26 ( 50 ) ;
F_27 ( V_10 -> V_51 , 1 ) ;
}
if ( V_21 -> V_7 )
args [ 0 ] |= V_52 ;
V_25 = F_5 ( V_10 , V_53 ,
args , F_20 ( args ) ,
V_38 , F_20 ( V_38 ) ,
V_54 ) ;
if ( ! V_25 ) {
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_10 ,
V_38 [ 0 ] ) ;
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_11 ) ;
V_10 -> V_48 = V_55 ;
if ( V_21 -> V_7 )
V_25 = F_22 ( V_10 , V_56 ,
V_57 | V_58 ) ;
return V_25 ;
}
F_27 ( V_10 -> V_51 , 0 ) ;
if ( V_10 -> V_49 ) {
V_25 = F_28 ( V_10 -> V_49 ) ;
if ( V_25 )
F_9 ( & V_10 -> V_12 , L_12 , V_25 ) ;
}
if ( V_10 -> V_50 ) {
V_25 = F_28 ( V_10 -> V_50 ) ;
if ( V_25 )
F_9 ( & V_10 -> V_12 , L_13 , V_25 ) ;
}
return V_25 ;
}
static int F_29 ( struct V_9 * V_10 )
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
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_14 ,
V_38 [ 0 ] ) ;
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_15 ) ;
if ( V_10 -> V_51 )
F_27 ( V_10 -> V_51 , 0 ) ;
if ( V_10 -> V_49 ) {
V_25 = F_28 ( V_10 -> V_49 ) ;
if ( V_25 ) {
F_9 ( & V_10 -> V_12 ,
L_12 , V_25 ) ;
}
}
if ( V_10 -> V_50 ) {
V_25 = F_28 ( V_10 -> V_50 ) ;
if ( V_25 ) {
F_9 ( & V_10 -> V_12 ,
L_13 , V_25 ) ;
}
}
V_10 -> V_48 = V_61 ;
}
return V_25 ;
}
static int F_30 ( struct V_9 * V_10 )
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
F_31 ( & V_10 -> V_12 , L_16 ,
V_21 -> V_65 << 1 , V_21 -> V_26 -> V_66 ) ;
} else {
F_9 ( & V_10 -> V_12 , L_17 , V_38 [ 1 ] ) ;
V_5 = - V_6 ;
}
return V_5 ;
}
static int F_32 ( struct V_9 * V_10 , const int V_1 )
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
L_18 , V_13 , V_38 [ 0 ] ) ;
if ( V_38 [ 0 ] & V_57 )
return 0 ;
}
if ( F_33 ( V_29 - V_68 ) > V_1 )
return V_25 < 0 ? V_25 : - V_28 ;
F_15 ( 3000 , 4000 ) ;
}
}
static int F_34 ( struct V_9 * V_10 , T_3 V_70 )
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
L_19 , V_13 ,
V_70 , V_33 [ 0 ] ) ;
V_25 = F_32 ( V_10 , V_74 ) ;
if ( V_25 < 0 )
return V_25 ;
return F_21 ( args [ 1 ] , args [ 2 ] ) ;
}
static int F_35 ( struct V_9 * V_10 , T_2 V_75 ,
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
L_20 ,
V_13 , V_75 , V_76 , V_33 [ 0 ] ) ;
return F_32 ( V_10 , V_81 ) ;
}
static int F_36 ( struct V_9 * V_10 , T_3 V_70 ,
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
L_21 ,
V_13 , V_70 , V_76 , V_33 [ 0 ] ) ;
return F_32 ( V_10 , V_74 ) ;
}
static int F_37 ( struct V_9 * V_10 , T_2 V_89 ,
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
L_22 , V_13 , V_33 [ 0 ] ) ;
* V_70 = F_21 ( V_33 [ 2 ] , V_33 [ 3 ] ) ;
V_10 -> V_70 = * V_70 ;
* V_75 = V_33 [ 5 ] ;
* V_76 = V_33 [ 6 ] ;
* V_90 = V_33 [ 7 ] ;
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_23
L_24 , V_13 ,
* V_70 , * V_75 , * V_76 , * V_90 ) ;
}
return V_25 ;
}
static int F_38 ( struct V_9 * V_10 , T_2 V_95 , T_3 V_96 ,
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
L_22 , V_13 , V_33 [ 0 ] ) ;
* V_99 = ( T_5 ) V_33 [ 2 ] - V_33 [ 3 ] ;
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_25
L_26
L_27 , V_13 , V_33 [ 1 ] ,
V_33 [ 2 ] , V_33 [ 3 ] , V_33 [ 4 ] , V_33 [ 5 ] ) ;
}
return V_25 ;
}
static int F_39 ( struct V_9 * V_10 , T_2 V_104 ,
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
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_22 , V_13 , V_33 [ 0 ] ) ;
return V_25 ;
}
static int F_40 ( struct V_9 * V_10 , T_2 V_110 )
{
if ( V_110 )
return F_24 ( V_10 ) ;
return F_29 ( V_10 ) ;
}
static int F_41 ( struct V_9 * V_10 , T_3 V_111 )
{
int V_5 = 0 ;
V_111 = F_42 ( V_111 ) ;
if ( V_10 -> V_48 )
V_5 = F_22 ( V_10 ,
V_112 , V_111 ) ;
return V_5 ;
}
static int F_43 ( struct V_9 * V_10 , char * V_113 )
{
int V_5 = 0 , V_4 ;
T_2 V_114 = 0 ;
if ( ! strlen ( V_113 ) )
memset ( V_113 , 0 , V_115 + 1 ) ;
if ( V_10 -> V_48 ) {
for ( V_4 = 0 ; V_4 < V_115 ; V_4 += ( V_116 / 2 ) ) {
V_5 = F_39 ( V_10 , ( V_4 / ( V_116 / 2 ) ) ,
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
F_44 ( V_114 ) ) ;
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
static int F_45 ( struct V_9 * V_10 , const char * V_120 )
{
static const char V_121 [ V_122 ] = { V_123 , 0 } ;
int V_5 = 0 , V_4 ;
T_3 V_124 = 0 ;
T_2 V_125 = 0 , V_126 = 0 ;
T_5 V_127 ;
if ( ! V_10 -> V_48 )
return V_5 ;
V_5 = F_38 ( V_10 , V_128 , 0 , 0 , 0 , & V_127 ) ;
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
V_5 = F_38 ( V_10 , V_130 ,
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
static int F_46 ( struct V_9 * V_10 )
{
int V_5 ;
T_3 V_132 = 0 ;
T_2 V_133 = 0 , V_134 = 0 , V_135 = 0 ;
V_5 = F_37 ( V_10 , 0x00 , & V_132 , & V_133 , & V_134 , & V_135 ) ;
if ( V_5 < 0 )
goto exit;
V_10 -> V_84 = V_135 ;
exit:
return V_5 ;
}
static int F_47 ( struct V_9 * V_10 , T_4 V_136 ,
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
* V_139 = V_160 ;
* V_137 = 15 ;
* V_138 = 1 << 15 ;
break;
case V_162 :
* V_139 = V_160 ;
* V_137 = 14 ;
* V_138 = 1 << 14 ;
break;
case V_163 :
* V_139 = V_160 ;
* V_137 = 13 ;
* V_138 = 1 << 13 ;
break;
case V_164 :
* V_139 = V_160 ;
* V_137 = 12 ;
* V_138 = 1 << 12 ;
break;
case V_165 :
* V_139 = V_160 ;
* V_137 = 10 ;
* V_138 = 1 << 10 ;
break;
case V_166 :
* V_139 = V_160 ;
* V_137 = 4 ;
* V_138 = 1 << 4 ;
break;
case V_167 :
* V_139 = V_160 ;
* V_137 = 3 ;
* V_138 = 1 << 3 ;
break;
case V_168 :
* V_139 = V_169 ;
* V_137 = 1 ;
* V_138 = 1 << 1 ;
break;
case V_170 :
* V_139 = V_169 ;
* V_137 = 0 ;
* V_138 = 1 << 0 ;
break;
case V_171 :
* V_139 = V_172 ;
* V_137 = 0 ;
* V_138 = 1 << 0 ;
break;
case V_173 :
* V_139 = V_174 ;
* V_141 = V_175 ;
* V_3 = F_20 ( V_175 ) ;
break;
case V_176 :
* V_139 = V_177 ;
* V_141 = V_178 ;
* V_3 = F_20 ( V_178 ) ;
break;
case V_179 :
* V_139 = V_180 ;
* V_141 = V_181 ;
* V_3 = F_20 ( V_181 ) ;
break;
default:
V_5 = - V_6 ;
break;
}
return V_5 ;
}
static int F_48 ( struct V_9 * V_10 )
{
struct V_182 V_132 ;
struct V_183 V_184 ;
int V_5 ;
V_132 . V_185 = 0 ;
V_132 . V_70 = V_10 -> V_70 ? V_10 -> V_70 : V_186 ;
V_132 . V_70 = F_49 ( V_132 . V_70 ) ;
V_5 = F_50 ( & V_10 -> V_12 , & V_132 ) ;
V_184 . V_187 = 0 ;
if ( V_10 -> V_188 )
V_184 . V_189 = V_190 ;
else
V_184 . V_189 = V_191 ;
if ( V_10 -> V_192 )
V_184 . V_189 |= V_193 ;
F_51 ( & V_10 -> V_12 , & V_184 ) ;
return V_5 ;
}
static int F_52 ( struct V_9 * V_10 )
{
int V_5 ;
V_5 = F_40 ( V_10 , V_55 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_30 ( V_10 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_40 ( V_10 , V_61 ) ;
if ( V_5 < 0 )
return V_5 ;
V_10 -> V_70 = V_186 ;
V_10 -> V_188 = 1 ;
V_10 -> V_84 = V_85 ;
return 0 ;
}
static int F_53 ( struct V_194 * V_195 )
{
struct V_9 * V_10 =
F_54 ( V_195 -> V_196 , struct V_9 , V_197 ) ;
T_4 V_33 = 0 ;
T_6 V_137 = 0 , V_138 = 0 ;
T_3 V_139 = 0 ;
int V_140 = 0 ;
unsigned long * V_141 = NULL ;
int V_3 = 0 ;
bool V_198 = false ;
int V_199 ;
int V_200 = 0 ;
if ( V_195 -> V_136 != V_201 )
return - V_6 ;
if ( V_195 -> V_202 ) {
if ( V_195 -> V_33 ) {
V_200 = F_41 ( V_10 , V_195 -> V_33 ) ;
if ( ! V_200 )
V_200 = F_40 ( V_10 , V_203 ) ;
return V_200 ;
}
V_200 = F_40 ( V_10 , V_204 ) ;
if ( ! V_200 )
V_200 = F_41 ( V_10 , V_195 -> V_33 ) ;
if ( ! V_200 )
V_200 = F_48 ( V_10 ) ;
if ( V_200 )
return V_200 ;
V_198 = true ;
}
if ( ! V_10 -> V_48 )
return 0 ;
for ( V_199 = 1 ; ! V_200 && V_199 < V_195 -> V_205 ; V_199 ++ ) {
V_195 = V_195 -> V_206 [ V_199 ] ;
if ( ! V_198 && ! V_195 -> V_202 )
continue;
switch ( V_195 -> V_136 ) {
case V_207 :
V_200 = F_43 ( V_10 , V_195 -> V_208 . V_209 ) ;
break;
case V_210 :
V_200 = F_45 ( V_10 , V_195 -> V_208 . V_209 ) ;
break;
case V_211 :
if ( V_198 )
break;
case V_212 :
V_200 = F_35 ( V_10 ,
V_10 -> V_213 -> V_33 , V_10 -> V_214 -> V_33 ) ;
if ( ! V_200 ) {
V_10 -> V_214 -> V_202 = false ;
V_10 -> V_213 -> V_202 = false ;
}
break;
case V_215 :
case V_216 :
if ( V_10 -> V_217 -> V_33 ) {
V_33 = V_10 -> V_218 -> V_208 . V_219 [ 0 ] ;
V_33 = V_33 / 100 - 876 + 0xe101 ;
} else {
V_33 = 0xe0e0 ;
}
V_200 = F_22 ( V_10 , V_220 , V_33 ) ;
break;
default:
V_200 = F_47 ( V_10 , V_195 -> V_136 , & V_137 ,
& V_138 , & V_139 , & V_140 , & V_141 , & V_3 ) ;
if ( V_200 < 0 )
break;
V_33 = V_195 -> V_33 ;
if ( V_140 ) {
V_33 = V_33 / V_140 ;
} else if ( V_141 ) {
V_200 = F_1 ( V_33 , V_141 , V_3 ) ;
if ( V_200 < 0 )
break;
V_33 = V_200 ;
V_200 = 0 ;
}
if ( V_138 ) {
V_200 = F_17 ( V_10 , V_139 , & V_33 ) ;
if ( V_200 < 0 )
break;
V_33 = F_55 ( V_33 , V_195 -> V_33 , V_137 , V_138 ) ;
}
V_200 = F_22 ( V_10 , V_139 , V_33 ) ;
if ( V_200 < 0 )
break;
if ( V_138 )
V_33 = V_195 -> V_33 ;
break;
}
}
return V_200 ;
}
static long F_56 ( struct V_221 * V_12 , unsigned int V_222 , void * V_223 )
{
struct V_9 * V_10 = F_57 ( V_12 ) ;
struct V_224 * V_225 = V_223 ;
T_3 V_70 ;
int V_5 = 0 ;
if ( ! V_223 )
return - V_6 ;
switch ( V_222 ) {
case V_226 :
V_70 = F_58 ( V_225 -> V_70 ) ;
if ( V_10 -> V_48 ) {
V_5 = F_36 ( V_10 , V_70 , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_46 ( V_10 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_225 -> V_225 = V_10 -> V_84 ;
break;
default:
V_5 = - V_227 ;
}
return V_5 ;
}
static int F_59 ( struct V_221 * V_12 , struct V_183 * V_184 )
{
struct V_9 * V_10 = F_57 ( V_12 ) ;
int V_5 = 0 ;
if ( ! V_10 )
return - V_27 ;
if ( V_184 -> V_187 > 0 )
return - V_6 ;
strncpy ( V_184 -> V_66 , L_28 , 32 ) ;
V_184 -> V_228 = V_229 | V_230 |
V_231 | V_232 ;
V_184 -> V_233 = F_49 ( V_234 ) ;
V_184 -> V_235 = F_49 ( V_236 ) ;
if ( V_10 -> V_48 ) {
T_4 V_237 = 0 ;
V_5 = F_17 ( V_10 , V_172 ,
& V_237 ) ;
if ( V_5 < 0 )
return V_5 ;
V_10 -> V_188 = F_60 ( V_237 , 1 , 1 << 1 ) ;
}
if ( V_10 -> V_188 )
V_184 -> V_189 = V_190 ;
else
V_184 -> V_189 = V_191 ;
if ( V_10 -> V_192 )
V_184 -> V_189 |= V_193 ;
else
V_184 -> V_189 &= ~ V_193 ;
return V_5 ;
}
static int F_51 ( struct V_221 * V_12 , const struct V_183 * V_184 )
{
struct V_9 * V_10 = F_57 ( V_12 ) ;
int V_5 = 0 ;
T_3 V_188 , V_238 ;
T_4 V_133 ;
if ( ! V_10 )
return - V_27 ;
if ( V_184 -> V_187 > 0 )
return - V_6 ;
if ( V_184 -> V_189 & V_190 )
V_188 = 1 ;
else if ( V_184 -> V_189 & V_191 )
V_188 = 0 ;
else
return - V_6 ;
V_238 = ! ! ( V_184 -> V_189 & V_193 ) ;
if ( V_10 -> V_48 ) {
V_5 = F_17 ( V_10 ,
V_172 , & V_133 ) ;
if ( V_5 < 0 )
return V_5 ;
V_133 = F_55 ( V_133 , V_188 , 1 , 1 << 1 ) ;
V_133 = F_55 ( V_133 , V_238 , 2 , 1 << 2 ) ;
V_5 = F_22 ( V_10 ,
V_172 , V_133 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_10 -> V_188 = V_188 ;
V_10 -> V_192 = V_238 ;
return V_5 ;
}
static int F_61 ( struct V_221 * V_12 , struct V_182 * V_132 )
{
struct V_9 * V_10 = F_57 ( V_12 ) ;
int V_5 = 0 ;
if ( V_132 -> V_185 )
return - V_6 ;
if ( V_10 -> V_48 ) {
T_3 V_239 ;
T_2 V_133 , V_134 , V_135 ;
V_5 = F_37 ( V_10 , 0x00 , & V_239 , & V_133 , & V_134 , & V_135 ) ;
if ( V_5 < 0 )
return V_5 ;
V_10 -> V_70 = V_239 ;
}
V_132 -> V_70 = F_49 ( V_10 -> V_70 ) ;
return V_5 ;
}
static int F_50 ( struct V_221 * V_12 , const struct V_182 * V_132 )
{
struct V_9 * V_10 = F_57 ( V_12 ) ;
int V_5 = 0 ;
T_3 V_70 = F_58 ( V_132 -> V_70 ) ;
if ( V_132 -> V_185 )
return - V_6 ;
V_70 = F_62 ( T_3 , V_70 , V_234 , V_236 ) ;
if ( V_10 -> V_48 ) {
V_5 = F_34 ( V_10 , V_70 ) ;
if ( V_5 < 0 )
return V_5 ;
V_70 = V_5 ;
V_5 = 0 ;
}
V_10 -> V_70 = V_70 ;
return V_5 ;
}
static int F_63 ( struct V_20 * V_21 ,
const struct V_240 * V_136 )
{
struct V_9 * V_10 ;
struct V_241 * V_242 ;
struct V_243 * V_244 = V_21 -> V_8 . V_245 ;
struct V_246 * V_247 = V_21 -> V_8 . V_248 ;
struct V_249 V_250 ;
struct V_251 * V_252 ;
int V_5 ;
V_10 = F_64 ( & V_21 -> V_8 , sizeof( * V_10 ) , V_253 ) ;
if ( ! V_10 ) {
F_65 ( & V_21 -> V_8 , L_29 ) ;
V_5 = - V_254 ;
goto exit;
}
V_10 -> V_51 = F_66 ( & V_21 -> V_8 , L_30 ,
V_255 ) ;
if ( F_67 ( V_10 -> V_51 ) ) {
V_5 = F_68 ( V_10 -> V_51 ) ;
F_65 ( & V_21 -> V_8 , L_31 , V_5 ) ;
goto exit;
}
V_10 -> V_49 = F_69 ( & V_21 -> V_8 , L_32 ) ;
if ( F_67 ( V_10 -> V_49 ) ) {
V_5 = F_68 ( V_10 -> V_49 ) ;
if ( V_5 == - V_256 )
goto exit;
F_70 ( & V_21 -> V_8 , L_33 , V_5 ) ;
V_10 -> V_49 = NULL ;
}
V_10 -> V_50 = F_69 ( & V_21 -> V_8 , L_34 ) ;
if ( F_67 ( V_10 -> V_50 ) ) {
V_5 = F_68 ( V_10 -> V_50 ) ;
if ( V_5 == - V_256 )
goto exit;
F_70 ( & V_21 -> V_8 , L_35 , V_5 ) ;
V_10 -> V_50 = NULL ;
}
F_71 ( & V_10 -> V_12 , V_21 , & V_257 ) ;
F_72 ( & V_10 -> V_14 ) ;
V_242 = & V_10 -> V_197 ;
F_73 ( V_242 , 20 ) ;
V_10 -> V_111 = F_74 ( V_242 , & V_258 ,
V_201 , 0 , 1 , 1 , V_259 ) ;
V_10 -> V_260 = F_74 ( V_242 , & V_258 ,
V_142 , 0 , 0xffff , 1 , V_261 ) ;
V_10 -> V_262 = F_74 ( V_242 , & V_258 ,
V_159 , 0 , 31 , 1 , V_263 ) ;
V_10 -> V_264 = F_74 ( V_242 , & V_258 ,
V_162 , 0 , 1 , 1 , 0 ) ;
V_10 -> V_265 = F_74 ( V_242 , & V_258 ,
V_163 , 0 , 1 , 1 , 0 ) ;
V_10 -> V_266 = F_74 ( V_242 , & V_258 ,
V_164 , 0 , 1 , 1 , 1 ) ;
V_10 -> V_267 = F_74 ( V_242 , & V_258 ,
V_165 , 0 , 1 , 1 , 0 ) ;
V_10 -> V_268 = F_74 ( V_242 , & V_258 ,
V_166 , 0 , 1 , 1 , 0 ) ;
V_10 -> V_269 = F_74 ( V_242 , & V_258 ,
V_167 , 0 , 1 , 1 , 1 ) ;
V_10 -> V_270 = F_74 ( V_242 , & V_258 ,
V_161 , 0 , 1 , 1 , 0 ) ;
V_10 -> V_217 = F_74 ( V_242 , & V_258 ,
V_215 , 0 , 1 , 1 , 0 ) ;
V_10 -> V_218 = F_75 ( V_242 , & V_271 , NULL ) ;
V_10 -> V_272 = F_74 ( V_242 , & V_258 ,
V_157 , 0 , V_273 ,
10 , V_274 ) ;
V_10 -> V_275 = F_74 ( V_242 , & V_258 ,
V_207 , 0 , V_115 , 8 , 0 ) ;
V_10 -> V_276 = F_74 ( V_242 , & V_258 ,
V_210 , 0 , V_277 , 32 , 0 ) ;
V_10 -> V_278 = F_74 ( V_242 , & V_258 ,
V_168 , 0 , 1 , 1 , 1 ) ;
V_10 -> V_279 = F_74 ( V_242 , & V_258 ,
V_173 , 250 ,
V_280 , 10 , V_281 ) ;
V_10 -> V_282 = F_74 ( V_242 , & V_258 ,
V_155 , 0 ,
V_283 , 10 , V_284 ) ;
V_10 -> V_285 = F_74 ( V_242 , & V_258 ,
V_170 , 0 , 1 , 1 , 1 ) ;
V_10 -> V_286 = F_74 ( V_242 , & V_258 ,
V_146 , 0 , V_287 , 1 ,
V_288 ) ;
V_10 -> V_289 = F_74 ( V_242 , & V_258 ,
V_144 ,
V_290 , V_291 , 1 ,
V_292 ) ;
V_10 -> V_293 = F_74 ( V_242 , & V_258 ,
V_150 , 0 ,
V_294 , 500 , V_295 ) ;
V_10 -> V_296 = F_74 ( V_242 , & V_258 ,
V_176 , 100000 ,
V_297 , 100000 , V_298 ) ;
V_10 -> V_299 = F_74 ( V_242 , & V_258 ,
V_171 , 0 , 1 , 1 , 1 ) ;
V_10 -> V_300 = F_74 ( V_242 , & V_258 ,
V_153 , 0 , V_301 ,
10 , V_302 ) ;
V_10 -> V_303 = F_74 ( V_242 , & V_258 ,
V_148 , 0 , V_304 ,
1 , V_305 ) ;
V_10 -> V_306 = F_76 ( V_242 , & V_258 ,
V_179 ,
V_307 , 0 , V_308 ) ;
V_10 -> V_213 = F_74 ( V_242 , & V_258 ,
V_212 , 0 , V_309 ,
1 , V_310 ) ;
V_10 -> V_214 = F_74 ( V_242 , & V_258 ,
V_211 , 0 , V_86 ,
1 , 0 ) ;
if ( V_242 -> error ) {
V_5 = V_242 -> error ;
goto V_311;
}
F_77 ( 29 , & V_10 -> V_111 ) ;
V_10 -> V_12 . V_197 = V_242 ;
if ( V_21 -> V_7 ) {
V_5 = F_78 ( & V_21 -> V_8 , V_21 -> V_7 ,
F_2 , V_312 ,
V_21 -> V_66 , V_10 ) ;
if ( V_5 < 0 ) {
F_9 ( & V_10 -> V_12 , L_36 ) ;
goto V_311;
}
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_37 ) ;
} else {
F_12 ( & V_10 -> V_12 , L_38 ) ;
}
V_5 = F_52 ( V_10 ) ;
if ( V_5 < 0 ) {
F_9 ( & V_10 -> V_12 , L_39 ) ;
goto V_311;
}
if ( ! V_247 && ( ! V_244 || ! V_244 -> V_313 ) )
return 0 ;
V_252 = F_79 ( L_40 , - 1 ) ;
if ( ! V_252 ) {
V_5 = - V_254 ;
goto V_314;
}
V_250 . V_315 = V_21 ;
V_5 = F_80 ( V_252 , & V_250 ,
sizeof( V_250 ) ) ;
if ( V_5 )
goto V_314;
V_5 = F_81 ( V_252 ) ;
if ( V_5 )
goto V_314;
V_10 -> V_316 = V_252 ;
return 0 ;
V_314:
F_82 ( V_252 ) ;
F_83 ( & V_10 -> V_12 ) ;
V_311:
F_84 ( V_242 ) ;
exit:
return V_5 ;
}
static int F_85 ( struct V_20 * V_21 )
{
struct V_221 * V_12 = F_86 ( V_21 ) ;
struct V_9 * V_10 = F_57 ( V_12 ) ;
F_87 ( V_10 -> V_316 ) ;
if ( V_10 -> V_48 )
F_40 ( V_10 , V_203 ) ;
F_83 ( V_12 ) ;
F_84 ( V_12 -> V_197 ) ;
return 0 ;
}
