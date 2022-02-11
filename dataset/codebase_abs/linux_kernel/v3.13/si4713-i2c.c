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
T_2 V_22 [ V_23 + 1 ] ;
int V_24 ;
if ( ! V_21 -> V_25 )
return - V_26 ;
V_22 [ 0 ] = V_16 ;
memcpy ( V_22 + 1 , args , V_17 ) ;
F_7 ( & V_10 -> V_12 , L_2 , V_22 , V_17 + 1 ) ;
V_24 = F_8 ( V_21 , V_22 , V_17 + 1 ) ;
if ( V_24 != V_17 + 1 ) {
F_9 ( & V_10 -> V_12 , L_3 ,
V_16 ) ;
return ( V_24 > 0 ) ? - V_27 : V_24 ;
}
if ( ! F_10 ( & V_10 -> V_14 ,
F_11 ( V_1 ) + 1 ) )
F_12 ( & V_10 -> V_12 ,
L_4 ,
V_13 ) ;
V_24 = F_13 ( V_21 , V_18 , V_19 ) ;
if ( V_24 != V_19 ) {
F_9 ( & V_10 -> V_12 ,
L_5 ,
V_16 ) ;
return ( V_24 > 0 ) ? - V_27 : V_24 ;
}
F_7 ( & V_10 -> V_12 , L_6 , V_18 , V_19 ) ;
if ( F_14 ( V_18 [ 0 ] ) )
return - V_28 ;
return 0 ;
}
static int F_15 ( struct V_9 * V_10 , T_3 V_29 , T_4 * V_30 )
{
int V_24 ;
T_2 V_31 [ V_32 ] ;
const T_2 args [ V_33 ] = {
0x00 ,
F_16 ( V_29 ) ,
F_17 ( V_29 ) ,
} ;
V_24 = F_5 ( V_10 , V_34 ,
args , F_18 ( args ) , V_31 ,
F_18 ( V_31 ) , V_35 ) ;
if ( V_24 < 0 )
return V_24 ;
* V_30 = F_19 ( V_31 [ 2 ] , V_31 [ 3 ] ) ;
F_3 ( 1 , V_11 , & V_10 -> V_12 ,
L_7 ,
V_13 , V_29 , * V_30 , V_31 [ 0 ] ) ;
return V_24 ;
}
static int F_20 ( struct V_9 * V_10 , T_3 V_29 , T_3 V_31 )
{
int V_5 ;
T_2 V_36 [ V_37 ] ;
const T_2 args [ V_38 ] = {
0x00 ,
F_16 ( V_29 ) ,
F_17 ( V_29 ) ,
F_16 ( V_31 ) ,
F_17 ( V_31 ) ,
} ;
V_5 = F_5 ( V_10 , V_39 ,
args , F_18 ( args ) ,
V_36 , F_18 ( V_36 ) ,
V_35 ) ;
if ( V_5 < 0 )
return V_5 ;
F_3 ( 1 , V_11 , & V_10 -> V_12 ,
L_7 ,
V_13 , V_29 , V_31 , V_36 [ 0 ] ) ;
F_21 ( V_40 ) ;
return V_5 ;
}
static int F_22 ( struct V_9 * V_10 )
{
int V_24 ;
T_2 V_36 [ V_41 ] ;
const T_2 args [ V_42 ] = {
V_43 | V_44 | V_45 ,
V_46 ,
} ;
if ( V_10 -> V_47 )
return 0 ;
V_24 = F_23 ( F_18 ( V_10 -> V_48 ) ,
V_10 -> V_48 ) ;
if ( V_24 ) {
F_9 ( & V_10 -> V_12 , L_8 , V_24 ) ;
return V_24 ;
}
if ( F_24 ( V_10 -> V_49 ) ) {
F_25 ( 50 ) ;
F_26 ( V_10 -> V_49 , 1 ) ;
}
V_24 = F_5 ( V_10 , V_50 ,
args , F_18 ( args ) ,
V_36 , F_18 ( V_36 ) ,
V_51 ) ;
if ( ! V_24 ) {
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_9 ,
V_36 [ 0 ] ) ;
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_10 ) ;
V_10 -> V_47 = V_52 ;
V_24 = F_20 ( V_10 , V_53 ,
V_54 | V_55 ) ;
} else {
if ( F_24 ( V_10 -> V_49 ) )
F_26 ( V_10 -> V_49 , 0 ) ;
V_24 = F_27 ( F_18 ( V_10 -> V_48 ) ,
V_10 -> V_48 ) ;
if ( V_24 )
F_9 ( & V_10 -> V_12 ,
L_11 , V_24 ) ;
}
return V_24 ;
}
static int F_28 ( struct V_9 * V_10 )
{
int V_24 ;
T_2 V_36 [ V_56 ] ;
if ( ! V_10 -> V_47 )
return 0 ;
V_24 = F_5 ( V_10 , V_57 ,
NULL , 0 ,
V_36 , F_18 ( V_36 ) ,
V_35 ) ;
if ( ! V_24 ) {
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_12 ,
V_36 [ 0 ] ) ;
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_13 ) ;
if ( F_24 ( V_10 -> V_49 ) )
F_26 ( V_10 -> V_49 , 0 ) ;
V_24 = F_27 ( F_18 ( V_10 -> V_48 ) ,
V_10 -> V_48 ) ;
if ( V_24 )
F_9 ( & V_10 -> V_12 ,
L_11 , V_24 ) ;
V_10 -> V_47 = V_58 ;
}
return V_24 ;
}
static int F_29 ( struct V_9 * V_10 )
{
struct V_20 * V_21 = F_6 ( & V_10 -> V_12 ) ;
int V_5 ;
T_2 V_36 [ V_59 ] ;
V_5 = F_5 ( V_10 , V_60 ,
NULL , 0 ,
V_36 , F_18 ( V_36 ) ,
V_35 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_36 [ 1 ] == V_61 ) {
F_30 ( & V_10 -> V_12 , L_14 ,
V_21 -> V_62 << 1 , V_21 -> V_25 -> V_63 ) ;
} else {
F_9 ( & V_10 -> V_12 , L_15 ) ;
V_5 = - V_6 ;
}
return V_5 ;
}
static int F_31 ( struct V_9 * V_10 , const int V_1 )
{
int V_24 ;
T_2 V_36 [ V_64 ] ;
if ( ! F_10 ( & V_10 -> V_14 ,
F_11 ( V_1 ) + 1 ) )
F_12 ( & V_10 -> V_12 ,
L_16 ,
V_13 , V_1 ) ;
V_24 = F_5 ( V_10 , V_65 ,
NULL , 0 ,
V_36 , F_18 ( V_36 ) ,
V_35 ) ;
if ( V_24 < 0 )
goto exit;
F_3 ( 1 , V_11 , & V_10 -> V_12 ,
L_17 , V_13 , V_36 [ 0 ] ) ;
if ( ! ( V_36 [ 0 ] & V_54 ) )
V_24 = - V_27 ;
exit:
return V_24 ;
}
static int F_32 ( struct V_9 * V_10 , T_3 V_66 )
{
int V_24 ;
T_2 V_31 [ V_67 ] ;
const T_2 args [ V_68 ] = {
0x00 ,
F_16 ( V_66 ) ,
F_17 ( V_66 ) ,
} ;
V_24 = F_5 ( V_10 , V_69 ,
args , F_18 ( args ) , V_31 ,
F_18 ( V_31 ) , V_35 ) ;
if ( V_24 < 0 )
return V_24 ;
F_3 ( 1 , V_11 , & V_10 -> V_12 ,
L_18 , V_13 ,
V_66 , V_31 [ 0 ] ) ;
V_24 = F_31 ( V_10 , V_70 ) ;
if ( V_24 < 0 )
return V_24 ;
return F_19 ( args [ 1 ] , args [ 2 ] ) ;
}
static int F_33 ( struct V_9 * V_10 , T_2 V_71 ,
T_2 V_72 )
{
int V_24 ;
T_2 V_31 [ V_73 ] ;
const T_2 args [ V_74 ] = {
0x00 ,
0x00 ,
V_71 ,
V_72 ,
} ;
if ( ( ( V_71 > 0 ) && ( V_71 < V_75 ) ) ||
V_71 > V_76 || V_72 > V_77 )
return - V_78 ;
V_24 = F_5 ( V_10 , V_79 ,
args , F_18 ( args ) , V_31 ,
F_18 ( V_31 ) , V_35 ) ;
if ( V_24 < 0 )
return V_24 ;
F_3 ( 1 , V_11 , & V_10 -> V_12 ,
L_19 ,
V_13 , V_71 , V_72 , V_31 [ 0 ] ) ;
return F_31 ( V_10 , V_80 ) ;
}
static int F_34 ( struct V_9 * V_10 , T_3 V_66 ,
T_2 V_72 )
{
int V_24 ;
T_2 V_31 [ V_81 ] ;
const T_2 args [ V_82 ] = {
0x00 ,
F_16 ( V_66 ) ,
F_17 ( V_66 ) ,
V_72 ,
} ;
V_10 -> V_83 = V_84 ;
if ( V_72 > V_77 )
return - V_78 ;
V_24 = F_5 ( V_10 , V_85 ,
args , F_18 ( args ) , V_31 ,
F_18 ( V_31 ) , V_35 ) ;
if ( V_24 < 0 )
return V_24 ;
F_3 ( 1 , V_11 , & V_10 -> V_12 ,
L_20 ,
V_13 , V_66 , V_72 , V_31 [ 0 ] ) ;
return F_31 ( V_10 , V_70 ) ;
}
static int F_35 ( struct V_9 * V_10 , T_2 V_86 ,
T_3 * V_66 , T_2 * V_71 ,
T_2 * V_72 , T_2 * V_87 )
{
int V_24 ;
T_2 V_31 [ V_88 ] ;
const T_2 args [ V_89 ] = {
V_86 & V_90 ,
} ;
V_24 = F_5 ( V_10 , V_91 ,
args , F_18 ( args ) , V_31 ,
F_18 ( V_31 ) , V_35 ) ;
if ( ! V_24 ) {
F_3 ( 1 , V_11 , & V_10 -> V_12 ,
L_21 , V_13 , V_31 [ 0 ] ) ;
* V_66 = F_19 ( V_31 [ 2 ] , V_31 [ 3 ] ) ;
V_10 -> V_66 = * V_66 ;
* V_71 = V_31 [ 5 ] ;
* V_72 = V_31 [ 6 ] ;
* V_87 = V_31 [ 7 ] ;
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_22
L_23 , V_13 ,
* V_66 , * V_71 , * V_72 , * V_87 ) ;
}
return V_24 ;
}
static int F_36 ( struct V_9 * V_10 , T_2 V_92 , T_3 V_93 ,
T_3 V_94 , T_3 V_95 , T_5 * V_96 )
{
int V_24 ;
T_2 V_31 [ V_97 ] ;
const T_2 args [ V_98 ] = {
V_92 & V_99 ,
F_16 ( V_93 ) ,
F_17 ( V_93 ) ,
F_16 ( V_94 ) ,
F_17 ( V_94 ) ,
F_16 ( V_95 ) ,
F_17 ( V_95 ) ,
} ;
V_24 = F_5 ( V_10 , V_100 ,
args , F_18 ( args ) , V_31 ,
F_18 ( V_31 ) , V_35 ) ;
if ( ! V_24 ) {
F_3 ( 1 , V_11 , & V_10 -> V_12 ,
L_21 , V_13 , V_31 [ 0 ] ) ;
* V_96 = ( T_5 ) V_31 [ 2 ] - V_31 [ 3 ] ;
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_24
L_25
L_26 , V_13 , V_31 [ 1 ] ,
V_31 [ 2 ] , V_31 [ 3 ] , V_31 [ 4 ] , V_31 [ 5 ] ) ;
}
return V_24 ;
}
static int F_37 ( struct V_9 * V_10 , T_2 V_101 ,
unsigned char * V_102 )
{
int V_24 ;
T_2 V_31 [ V_103 ] ;
const T_2 args [ V_104 ] = {
V_101 & V_105 ,
V_102 [ 0 ] ,
V_102 [ 1 ] ,
V_102 [ 2 ] ,
V_102 [ 3 ] ,
} ;
V_24 = F_5 ( V_10 , V_106 ,
args , F_18 ( args ) , V_31 ,
F_18 ( V_31 ) , V_35 ) ;
if ( V_24 < 0 )
return V_24 ;
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_21 , V_13 , V_31 [ 0 ] ) ;
return V_24 ;
}
static int F_38 ( struct V_9 * V_10 , T_2 V_107 )
{
if ( V_107 )
return F_22 ( V_10 ) ;
return F_28 ( V_10 ) ;
}
static int F_39 ( struct V_9 * V_10 , T_3 V_108 )
{
int V_5 = 0 ;
V_108 = F_40 ( V_108 ) ;
if ( V_10 -> V_47 )
V_5 = F_20 ( V_10 ,
V_109 , V_108 ) ;
return V_5 ;
}
static int F_41 ( struct V_9 * V_10 , char * V_110 )
{
int V_5 = 0 , V_4 ;
T_2 V_111 = 0 ;
if ( ! strlen ( V_110 ) )
memset ( V_110 , 0 , V_112 + 1 ) ;
if ( V_10 -> V_47 ) {
for ( V_4 = 0 ; V_4 < V_112 ; V_4 += ( V_113 / 2 ) ) {
V_5 = F_37 ( V_10 , ( V_4 / ( V_113 / 2 ) ) ,
V_110 + V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( strlen ( V_110 ) )
V_111 = strlen ( V_110 ) - 1 ;
else
V_111 = 1 ;
V_5 = F_20 ( V_10 ,
V_114 ,
F_42 ( V_111 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_20 ( V_10 ,
V_115 ,
V_116 * 2 ) ;
if ( V_5 < 0 )
return V_5 ;
}
return V_5 ;
}
static int F_43 ( struct V_9 * V_10 , char * V_117 )
{
int V_5 = 0 , V_4 ;
T_3 V_118 = 0 ;
T_2 V_119 = 0 , V_120 = 0 ;
T_5 V_121 ;
if ( ! V_10 -> V_47 )
return V_5 ;
V_5 = F_36 ( V_10 , V_122 , 0 , 0 , 0 , & V_121 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ! strlen ( V_117 ) )
return V_5 ;
do {
if ( V_118 < ( V_123 * V_124 ) ) {
for ( V_4 = 0 ; V_4 < V_124 ; V_4 ++ ) {
if ( ! V_117 [ V_118 + V_4 ] ||
V_117 [ V_118 + V_4 ] == V_125 ) {
V_117 [ V_118 + V_4 ] = V_125 ;
V_120 = 1 ;
break;
}
}
}
V_5 = F_36 ( V_10 , V_126 ,
F_19 ( V_127 , V_119 ++ ) ,
F_19 ( V_117 [ V_118 ] , V_117 [ V_118 + 1 ] ) ,
F_19 ( V_117 [ V_118 + 2 ] , V_117 [ V_118 + 3 ] ) ,
& V_121 ) ;
if ( V_5 < 0 )
return V_5 ;
V_118 += V_124 ;
if ( V_120 )
break;
} while ( V_121 > 0 );
return V_5 ;
}
static int F_44 ( struct V_9 * V_10 )
{
int V_5 ;
T_3 V_128 = 0 ;
T_2 V_129 = 0 , V_130 = 0 , V_131 = 0 ;
V_5 = F_35 ( V_10 , 0x00 , & V_128 , & V_129 , & V_130 , & V_131 ) ;
if ( V_5 < 0 )
goto exit;
V_10 -> V_83 = V_131 ;
exit:
return V_5 ;
}
static int F_45 ( struct V_9 * V_10 , T_4 V_132 ,
T_6 * V_133 , T_6 * V_134 , T_3 * V_135 , int * V_136 ,
unsigned long * * V_137 , int * V_3 )
{
T_6 V_5 = 0 ;
switch ( V_132 ) {
case V_138 :
* V_135 = V_139 ;
* V_136 = 1 ;
break;
case V_140 :
* V_135 = V_141 ;
* V_136 = 1 ;
break;
case V_142 :
* V_135 = V_143 ;
* V_136 = 1 ;
break;
case V_144 :
* V_135 = V_145 ;
* V_136 = 1 ;
break;
case V_146 :
* V_135 = V_147 ;
* V_136 = V_148 ;
break;
case V_149 :
* V_135 = V_150 ;
* V_136 = 10 ;
break;
case V_151 :
* V_135 = V_152 ;
* V_136 = 10 ;
break;
case V_153 :
* V_135 = V_154 ;
* V_136 = 1 ;
break;
case V_155 :
* V_135 = V_156 ;
* V_133 = 5 ;
* V_134 = 0x1F << 5 ;
break;
case V_157 :
* V_135 = V_158 ;
* V_133 = 1 ;
* V_134 = 1 << 1 ;
break;
case V_159 :
* V_135 = V_158 ;
* V_133 = 0 ;
* V_134 = 1 << 0 ;
break;
case V_160 :
* V_135 = V_161 ;
* V_133 = 0 ;
* V_134 = 1 << 0 ;
break;
case V_162 :
* V_135 = V_163 ;
* V_137 = V_164 ;
* V_3 = F_18 ( V_164 ) ;
break;
case V_165 :
* V_135 = V_166 ;
* V_137 = V_167 ;
* V_3 = F_18 ( V_167 ) ;
break;
case V_168 :
* V_135 = V_169 ;
* V_137 = V_170 ;
* V_3 = F_18 ( V_170 ) ;
break;
default:
V_5 = - V_6 ;
break;
}
return V_5 ;
}
static int F_46 ( struct V_9 * V_10 )
{
struct V_171 V_128 ;
struct V_172 V_173 ;
int V_5 ;
V_128 . V_174 = 0 ;
V_128 . V_66 = V_10 -> V_66 ? V_10 -> V_66 : V_175 ;
V_128 . V_66 = F_47 ( V_128 . V_66 ) ;
V_5 = F_48 ( & V_10 -> V_12 , & V_128 ) ;
V_173 . V_176 = 0 ;
if ( V_10 -> V_177 )
V_173 . V_178 = V_179 ;
else
V_173 . V_178 = V_180 ;
if ( V_10 -> V_181 )
V_173 . V_178 |= V_182 ;
F_49 ( & V_10 -> V_12 , & V_173 ) ;
return V_5 ;
}
static int F_50 ( struct V_9 * V_10 )
{
int V_5 ;
V_5 = F_38 ( V_10 , V_52 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_29 ( V_10 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_38 ( V_10 , V_58 ) ;
if ( V_5 < 0 )
return V_5 ;
V_10 -> V_66 = V_175 ;
V_10 -> V_177 = 1 ;
V_10 -> V_83 = V_84 ;
return 0 ;
}
static int F_51 ( struct V_183 * V_184 )
{
struct V_9 * V_10 =
F_52 ( V_184 -> V_185 , struct V_9 , V_186 ) ;
T_4 V_31 = 0 ;
T_6 V_133 = 0 , V_134 = 0 ;
T_3 V_135 = 0 ;
int V_136 = 0 ;
unsigned long * V_137 = NULL ;
int V_3 = 0 ;
bool V_187 = false ;
int V_188 ;
int V_189 = 0 ;
if ( V_184 -> V_132 != V_190 )
return - V_6 ;
if ( V_184 -> V_191 ) {
if ( V_184 -> V_31 ) {
V_189 = F_39 ( V_10 , V_184 -> V_31 ) ;
if ( ! V_189 )
V_189 = F_38 ( V_10 , V_192 ) ;
return V_189 ;
}
V_189 = F_38 ( V_10 , V_193 ) ;
if ( ! V_189 )
V_189 = F_39 ( V_10 , V_184 -> V_31 ) ;
if ( ! V_189 )
V_189 = F_46 ( V_10 ) ;
if ( V_189 )
return V_189 ;
V_187 = true ;
}
if ( ! V_10 -> V_47 )
return 0 ;
for ( V_188 = 1 ; ! V_189 && V_188 < V_184 -> V_194 ; V_188 ++ ) {
V_184 = V_184 -> V_195 [ V_188 ] ;
if ( ! V_187 && ! V_184 -> V_191 )
continue;
switch ( V_184 -> V_132 ) {
case V_196 :
V_189 = F_41 ( V_10 , V_184 -> string ) ;
break;
case V_197 :
V_189 = F_43 ( V_10 , V_184 -> string ) ;
break;
case V_198 :
if ( V_187 )
break;
case V_199 :
V_189 = F_33 ( V_10 ,
V_10 -> V_200 -> V_31 , V_10 -> V_201 -> V_31 ) ;
if ( ! V_189 ) {
V_10 -> V_201 -> V_191 = false ;
V_10 -> V_200 -> V_191 = false ;
}
break;
default:
V_189 = F_45 ( V_10 , V_184 -> V_132 , & V_133 ,
& V_134 , & V_135 , & V_136 , & V_137 , & V_3 ) ;
if ( V_189 < 0 )
break;
V_31 = V_184 -> V_31 ;
if ( V_136 ) {
V_31 = V_31 / V_136 ;
} else if ( V_137 ) {
V_189 = F_1 ( V_31 , V_137 , V_3 ) ;
if ( V_189 < 0 )
break;
V_31 = V_189 ;
V_189 = 0 ;
}
if ( V_134 ) {
V_189 = F_15 ( V_10 , V_135 , & V_31 ) ;
if ( V_189 < 0 )
break;
V_31 = F_53 ( V_31 , V_184 -> V_31 , V_133 , V_134 ) ;
}
V_189 = F_20 ( V_10 , V_135 , V_31 ) ;
if ( V_189 < 0 )
break;
if ( V_134 )
V_31 = V_184 -> V_31 ;
break;
}
}
return V_189 ;
}
static long F_54 ( struct V_202 * V_12 , unsigned int V_203 , void * V_204 )
{
struct V_9 * V_10 = F_55 ( V_12 ) ;
struct V_205 * V_206 = V_204 ;
T_3 V_66 ;
int V_5 = 0 ;
if ( ! V_204 )
return - V_6 ;
switch ( V_203 ) {
case V_207 :
V_66 = F_56 ( V_206 -> V_66 ) ;
if ( V_10 -> V_47 ) {
V_5 = F_34 ( V_10 , V_66 , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_44 ( V_10 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_206 -> V_206 = V_10 -> V_83 ;
break;
default:
V_5 = - V_208 ;
}
return V_5 ;
}
static int F_57 ( struct V_202 * V_12 , struct V_172 * V_173 )
{
struct V_9 * V_10 = F_55 ( V_12 ) ;
int V_5 = 0 ;
if ( ! V_10 )
return - V_26 ;
if ( V_173 -> V_176 > 0 )
return - V_6 ;
strncpy ( V_173 -> V_63 , L_27 , 32 ) ;
V_173 -> V_209 = V_210 | V_211 |
V_212 | V_213 ;
V_173 -> V_214 = F_47 ( V_215 ) ;
V_173 -> V_216 = F_47 ( V_217 ) ;
if ( V_10 -> V_47 ) {
T_4 V_218 = 0 ;
V_5 = F_15 ( V_10 , V_161 ,
& V_218 ) ;
if ( V_5 < 0 )
return V_5 ;
V_10 -> V_177 = F_58 ( V_218 , 1 , 1 << 1 ) ;
}
if ( V_10 -> V_177 )
V_173 -> V_178 = V_179 ;
else
V_173 -> V_178 = V_180 ;
if ( V_10 -> V_181 )
V_173 -> V_178 |= V_182 ;
else
V_173 -> V_178 &= ~ V_182 ;
return V_5 ;
}
static int F_49 ( struct V_202 * V_12 , const struct V_172 * V_173 )
{
struct V_9 * V_10 = F_55 ( V_12 ) ;
int V_5 = 0 ;
T_3 V_177 , V_219 ;
T_4 V_129 ;
if ( ! V_10 )
return - V_26 ;
if ( V_173 -> V_176 > 0 )
return - V_6 ;
if ( V_173 -> V_178 & V_179 )
V_177 = 1 ;
else if ( V_173 -> V_178 & V_180 )
V_177 = 0 ;
else
return - V_6 ;
V_219 = ! ! ( V_173 -> V_178 & V_182 ) ;
if ( V_10 -> V_47 ) {
V_5 = F_15 ( V_10 ,
V_161 , & V_129 ) ;
if ( V_5 < 0 )
return V_5 ;
V_129 = F_53 ( V_129 , V_177 , 1 , 1 << 1 ) ;
V_129 = F_53 ( V_129 , V_219 , 2 , 1 << 2 ) ;
V_5 = F_20 ( V_10 ,
V_161 , V_129 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_10 -> V_177 = V_177 ;
V_10 -> V_181 = V_219 ;
return V_5 ;
}
static int F_59 ( struct V_202 * V_12 , struct V_171 * V_128 )
{
struct V_9 * V_10 = F_55 ( V_12 ) ;
int V_5 = 0 ;
if ( V_128 -> V_174 )
return - V_6 ;
if ( V_10 -> V_47 ) {
T_3 V_220 ;
T_2 V_129 , V_130 , V_131 ;
V_5 = F_35 ( V_10 , 0x00 , & V_220 , & V_129 , & V_130 , & V_131 ) ;
if ( V_5 < 0 )
return V_5 ;
V_10 -> V_66 = V_220 ;
}
V_128 -> V_66 = F_47 ( V_10 -> V_66 ) ;
return V_5 ;
}
static int F_48 ( struct V_202 * V_12 , const struct V_171 * V_128 )
{
struct V_9 * V_10 = F_55 ( V_12 ) ;
int V_5 = 0 ;
T_3 V_66 = F_56 ( V_128 -> V_66 ) ;
if ( V_128 -> V_174 )
return - V_6 ;
V_66 = F_60 ( T_3 , V_66 , V_215 , V_217 ) ;
if ( V_10 -> V_47 ) {
V_5 = F_32 ( V_10 , V_66 ) ;
if ( V_5 < 0 )
return V_5 ;
V_66 = V_5 ;
V_5 = 0 ;
}
V_10 -> V_66 = V_66 ;
return V_5 ;
}
static int F_61 ( struct V_20 * V_21 ,
const struct V_221 * V_132 )
{
struct V_9 * V_10 ;
struct V_222 * V_223 = V_21 -> V_8 . V_224 ;
struct V_225 * V_226 ;
int V_5 , V_4 ;
V_10 = F_62 ( sizeof *V_10 , V_227 ) ;
if ( ! V_10 ) {
F_63 ( & V_21 -> V_8 , L_28 ) ;
V_5 = - V_228 ;
goto exit;
}
V_10 -> V_49 = - 1 ;
if ( V_223 && F_24 ( V_223 -> V_49 ) ) {
V_5 = F_64 ( V_223 -> V_49 , L_29 ) ;
if ( V_5 ) {
F_63 ( & V_21 -> V_8 ,
L_30 , V_5 ) ;
goto V_229;
}
V_10 -> V_49 = V_223 -> V_49 ;
F_65 ( V_10 -> V_49 , 0 ) ;
}
for ( V_4 = 0 ; V_4 < F_18 ( V_10 -> V_48 ) ; V_4 ++ )
V_10 -> V_48 [ V_4 ] . V_230 = V_231 [ V_4 ] ;
V_5 = F_66 ( & V_21 -> V_8 , F_18 ( V_10 -> V_48 ) ,
V_10 -> V_48 ) ;
if ( V_5 ) {
F_63 ( & V_21 -> V_8 , L_31 , V_5 ) ;
goto V_232;
}
F_67 ( & V_10 -> V_12 , V_21 , & V_233 ) ;
F_68 ( & V_10 -> V_14 ) ;
V_226 = & V_10 -> V_186 ;
F_69 ( V_226 , 20 ) ;
V_10 -> V_108 = F_70 ( V_226 , & V_234 ,
V_190 , 0 , 1 , 1 , V_235 ) ;
V_10 -> V_236 = F_70 ( V_226 , & V_234 ,
V_138 , 0 , 0xffff , 1 , V_237 ) ;
V_10 -> V_238 = F_70 ( V_226 , & V_234 ,
V_155 , 0 , 31 , 1 , V_239 ) ;
V_10 -> V_240 = F_70 ( V_226 , & V_234 ,
V_153 , 0 , V_241 ,
10 , V_242 ) ;
V_10 -> V_243 = F_70 ( V_226 , & V_234 ,
V_196 , 0 , V_112 , 8 , 0 ) ;
V_10 -> V_244 = F_70 ( V_226 , & V_234 ,
V_197 , 0 , V_245 , 32 , 0 ) ;
V_10 -> V_246 = F_70 ( V_226 , & V_234 ,
V_157 , 0 , 1 , 1 , 1 ) ;
V_10 -> V_247 = F_70 ( V_226 , & V_234 ,
V_162 , 250 ,
V_248 , 10 , V_249 ) ;
V_10 -> V_250 = F_70 ( V_226 , & V_234 ,
V_151 , 0 ,
V_251 , 10 , V_252 ) ;
V_10 -> V_253 = F_70 ( V_226 , & V_234 ,
V_159 , 0 , 1 , 1 , 1 ) ;
V_10 -> V_254 = F_70 ( V_226 , & V_234 ,
V_142 , 0 , V_255 , 1 ,
V_256 ) ;
V_10 -> V_257 = F_70 ( V_226 , & V_234 ,
V_140 , V_258 ,
V_259 , 1 ,
V_260 ) ;
V_10 -> V_261 = F_70 ( V_226 , & V_234 ,
V_146 , 0 ,
V_262 , 500 , V_263 ) ;
V_10 -> V_264 = F_70 ( V_226 , & V_234 ,
V_165 , 100000 ,
V_265 , 100000 , V_266 ) ;
V_10 -> V_267 = F_70 ( V_226 , & V_234 ,
V_160 , 0 , 1 , 1 , 1 ) ;
V_10 -> V_268 = F_70 ( V_226 , & V_234 ,
V_149 , 0 , V_269 ,
10 , V_270 ) ;
V_10 -> V_271 = F_70 ( V_226 , & V_234 ,
V_144 , 0 , V_272 ,
1 , V_273 ) ;
V_10 -> V_274 = F_71 ( V_226 , & V_234 ,
V_168 ,
V_275 , 0 , V_276 ) ;
V_10 -> V_200 = F_70 ( V_226 , & V_234 ,
V_199 , 0 , 120 , 1 , V_277 ) ;
V_10 -> V_201 = F_70 ( V_226 , & V_234 ,
V_198 , 0 , 191 , 1 , 0 ) ;
if ( V_226 -> error ) {
V_5 = V_226 -> error ;
goto V_278;
}
F_72 ( 20 , & V_10 -> V_108 ) ;
V_10 -> V_12 . V_186 = V_226 ;
if ( V_21 -> V_7 ) {
V_5 = F_73 ( V_21 -> V_7 ,
F_2 , V_279 ,
V_21 -> V_63 , V_10 ) ;
if ( V_5 < 0 ) {
F_9 ( & V_10 -> V_12 , L_32 ) ;
goto V_280;
}
F_3 ( 1 , V_11 , & V_10 -> V_12 , L_33 ) ;
} else {
F_12 ( & V_10 -> V_12 , L_34 ) ;
}
V_5 = F_50 ( V_10 ) ;
if ( V_5 < 0 ) {
F_9 ( & V_10 -> V_12 , L_35 ) ;
goto V_281;
}
return 0 ;
V_281:
if ( V_21 -> V_7 )
V_281 ( V_21 -> V_7 , V_10 ) ;
V_278:
F_74 ( V_226 ) ;
V_280:
F_75 ( F_18 ( V_10 -> V_48 ) , V_10 -> V_48 ) ;
V_232:
if ( F_24 ( V_10 -> V_49 ) )
F_76 ( V_10 -> V_49 ) ;
V_229:
F_77 ( V_10 ) ;
exit:
return V_5 ;
}
static int F_78 ( struct V_20 * V_21 )
{
struct V_202 * V_12 = F_79 ( V_21 ) ;
struct V_9 * V_10 = F_55 ( V_12 ) ;
if ( V_10 -> V_47 )
F_38 ( V_10 , V_192 ) ;
if ( V_21 -> V_7 > 0 )
V_281 ( V_21 -> V_7 , V_10 ) ;
F_80 ( V_12 ) ;
F_74 ( V_12 -> V_186 ) ;
F_75 ( F_18 ( V_10 -> V_48 ) , V_10 -> V_48 ) ;
if ( F_24 ( V_10 -> V_49 ) )
F_76 ( V_10 -> V_49 ) ;
F_77 ( V_10 ) ;
return 0 ;
}
