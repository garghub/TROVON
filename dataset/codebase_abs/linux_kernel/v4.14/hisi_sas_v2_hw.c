static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
void T_2 * V_3 = V_1 -> V_3 + V_2 ;
return F_2 ( V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_1 , T_1 V_2 )
{
void T_2 * V_3 = V_1 -> V_3 + V_2 ;
return F_4 ( V_3 ) ;
}
static void F_5 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_4 )
{
void T_2 * V_3 = V_1 -> V_3 + V_2 ;
F_6 ( V_4 , V_3 ) ;
}
static void F_7 ( struct V_1 * V_1 , int V_5 ,
T_1 V_2 , T_1 V_4 )
{
void T_2 * V_3 = V_1 -> V_3 + ( 0x400 * V_5 ) + V_2 ;
F_6 ( V_4 , V_3 ) ;
}
static T_1 F_8 ( struct V_1 * V_1 ,
int V_5 , T_1 V_2 )
{
void T_2 * V_3 = V_1 -> V_3 + ( 0x400 * V_5 ) + V_2 ;
return F_2 ( V_3 ) ;
}
static int
F_9 ( struct V_1 * V_1 , int * V_6 ,
struct V_7 * V_8 )
{
int V_9 = F_10 ( V_8 ) ;
void * V_10 = V_1 -> V_11 ;
struct V_12 * V_13 = V_8 -> V_14 ;
int V_15 = V_13 -> V_15 ;
int V_16 , V_17 ;
if ( ! V_9 ) {
V_16 = 1 ;
V_17 = V_1 -> V_18 ;
} else {
if ( V_15 >= V_19 )
return - V_20 ;
V_16 = 64 * ( V_15 + 1 ) ;
V_17 = 64 * ( V_15 + 2 ) ;
}
while ( 1 ) {
V_16 = F_11 ( V_10 ,
V_1 -> V_18 , V_16 ) ;
if ( V_16 >= V_17 )
return - V_21 ;
if ( V_9 ^ ( V_16 & 1 ) )
break;
V_16 ++ ;
}
F_12 ( V_16 , V_10 ) ;
* V_6 = V_16 ;
return 0 ;
}
static bool F_13 ( struct V_1 * V_1 , int * V_22 )
{
unsigned int V_23 ;
struct V_8 * V_24 = V_1 -> V_24 ;
void * V_10 = V_1 -> V_25 ;
V_23 = F_14 ( V_10 , V_19 ) ;
if ( V_23 >= V_19 ) {
F_15 ( V_24 , L_1 , V_23 ) ;
return false ;
}
F_12 ( V_23 , V_10 ) ;
* V_22 = V_23 ;
return true ;
}
static struct
V_12 * F_16 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = V_8 -> V_26 -> V_27 -> V_28 ;
struct V_12 * V_13 = NULL ;
int V_29 , V_9 = F_10 ( V_8 ) ;
int V_15 = - 1 ;
F_17 ( & V_1 -> V_30 ) ;
if ( V_9 )
if ( ! F_13 ( V_1 , & V_15 ) )
goto V_31;
for ( V_29 = 0 ; V_29 < V_32 ; V_29 ++ ) {
if ( V_9 && ( V_29 & 1 ) )
continue;
if ( V_1 -> V_33 [ V_29 ] . V_34 == V_35 ) {
int V_36 = V_29 % V_1 -> V_37 ;
struct V_38 * V_39 = & V_1 -> V_39 [ V_36 ] ;
V_1 -> V_33 [ V_29 ] . V_40 = V_29 ;
V_13 = & V_1 -> V_33 [ V_29 ] ;
V_13 -> V_41 = V_42 ;
V_13 -> V_34 = V_8 -> V_34 ;
V_13 -> V_1 = V_1 ;
V_13 -> V_43 = V_8 ;
V_13 -> V_15 = V_15 ;
V_13 -> V_39 = V_39 ;
F_18 ( & V_1 -> V_33 [ V_29 ] . V_44 ) ;
break;
}
}
V_31:
F_19 ( & V_1 -> V_30 ) ;
return V_13 ;
}
static void F_20 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_45 = F_8 ( V_1 , V_5 , V_46 ) ;
V_45 &= ~ V_47 ;
V_45 |= 1 << V_48 ;
F_7 ( V_1 , V_5 , V_46 , V_45 ) ;
}
static void F_21 ( struct V_1 * V_1 , int V_5 )
{
struct V_49 V_50 ;
T_1 * V_51 ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_34 = V_52 ;
V_50 . V_53 = 0 ;
V_50 . V_54 = 1 ;
V_50 . V_55 = V_56 ;
V_50 . V_57 = V_58 ;
memcpy ( & V_50 . V_59 [ 0 ] , V_1 -> V_60 , V_61 ) ;
memcpy ( & V_50 . V_60 [ 0 ] , V_1 -> V_60 , V_61 ) ;
V_50 . V_62 = V_5 ;
V_51 = ( T_1 * ) ( & V_50 ) ;
F_7 ( V_1 , V_5 , V_63 ,
F_22 ( V_51 [ 0 ] ) ) ;
F_7 ( V_1 , V_5 , V_64 ,
F_22 ( V_51 [ 1 ] ) ) ;
F_7 ( V_1 , V_5 , V_65 ,
F_22 ( V_51 [ 2 ] ) ) ;
F_7 ( V_1 , V_5 , V_66 ,
F_22 ( V_51 [ 3 ] ) ) ;
F_7 ( V_1 , V_5 , V_67 ,
F_22 ( V_51 [ 4 ] ) ) ;
F_7 ( V_1 , V_5 , V_68 ,
F_22 ( V_51 [ 5 ] ) ) ;
}
static void F_23 ( struct V_1 * V_1 ,
struct V_12 * V_13 )
{
struct V_7 * V_8 = V_13 -> V_43 ;
struct V_8 * V_24 = V_1 -> V_24 ;
T_3 V_69 , V_40 = V_13 -> V_40 ;
struct V_70 * V_71 = & V_1 -> V_71 [ V_40 ] ;
struct V_7 * V_72 = V_8 -> V_73 ;
struct V_74 * V_75 = V_8 -> V_26 ;
struct V_76 * V_26 = F_24 ( V_75 ) ;
memset ( V_71 , 0 , sizeof( * V_71 ) ) ;
V_69 = 0 ;
switch ( V_13 -> V_34 ) {
case V_52 :
case V_77 :
case V_78 :
V_69 = V_79 << V_80 ;
break;
case V_81 :
case V_82 :
if ( V_72 && F_25 ( V_72 -> V_34 ) )
V_69 = V_83 << V_80 ;
else
V_69 = V_84 << V_80 ;
break;
default:
F_15 ( V_24 , L_2 ,
V_13 -> V_34 ) ;
}
V_69 |= ( ( 1 << V_85 ) |
( V_8 -> V_86 << V_87 ) |
( 1 << V_88 ) |
( V_89 << V_90 ) |
( 1 << V_91 ) |
( V_26 -> V_92 << V_93 ) ) ;
V_71 -> V_69 = F_26 ( V_69 ) ;
memcpy ( & V_71 -> V_60 , V_8 -> V_60 , V_61 ) ;
V_71 -> V_60 = F_27 ( V_71 -> V_60 ) ;
if ( ! F_10 ( V_8 ) )
V_71 -> V_94 = F_26 ( ( 5000ULL << V_95 ) |
( 0x1ULL << V_96 ) |
( 0x32ULL << V_97 ) |
( 0x1ULL << V_98 ) ) ;
}
static void F_28 ( struct V_1 * V_1 ,
struct V_12 * V_13 )
{
F_29 ( V_99 ) ;
T_3 V_100 = V_13 -> V_40 ;
struct V_70 * V_71 = & V_1 -> V_71 [ V_100 ] ;
T_1 V_101 = F_1 ( V_1 , V_102 ) ;
int V_29 ;
V_13 -> V_99 = & V_99 ;
if ( F_10 ( V_13 -> V_43 ) )
F_30 ( V_13 -> V_15 , V_1 -> V_25 ) ;
if ( V_103 & V_101 )
F_5 ( V_1 , V_102 ,
V_103 ) ;
for ( V_29 = 0 ; V_29 < 2 ; V_29 ++ ) {
V_101 = V_104 | ( V_100 & V_105 ) ;
F_5 ( V_1 , V_106 , V_101 ) ;
F_31 ( V_13 -> V_99 ) ;
memset ( V_71 , 0 , sizeof( struct V_70 ) ) ;
}
}
static int F_32 ( struct V_1 * V_1 )
{
int V_29 , V_107 ;
T_1 V_4 ;
unsigned long V_108 ;
struct V_8 * V_24 = V_1 -> V_24 ;
if ( V_1 -> V_109 == 9 )
V_107 = 0x1fffff ;
else
V_107 = 0x7ffff ;
F_5 ( V_1 , V_110 , 0 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_109 ; V_29 ++ ) {
T_1 V_111 = F_8 ( V_1 , V_29 , V_46 ) ;
V_111 &= ~ V_112 ;
F_7 ( V_1 , V_29 , V_46 , V_111 ) ;
}
F_33 ( 50 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_109 ; V_29 ++ ) {
T_1 V_113 , V_114 ;
V_108 = V_115 + F_34 ( 1000 ) ;
while ( 1 ) {
V_113 = F_8 ( V_1 , V_29 ,
V_116 ) ;
V_114 = F_8 ( V_1 , V_29 ,
V_117 ) ;
if ( ! ( V_113 & V_118 ) &&
! ( V_114 & V_119 ) )
break;
F_35 ( 20 ) ;
if ( F_36 ( V_115 , V_108 ) )
return - V_120 ;
}
}
V_108 = V_115 + F_34 ( 1000 ) ;
while ( 1 ) {
T_1 V_121 =
F_1 ( V_1 , V_122 ) ;
if ( V_121 == 0 )
break;
F_35 ( 20 ) ;
if ( F_36 ( V_115 , V_108 ) )
return - V_120 ;
}
if ( F_37 ( V_24 ) ) {
T_4 V_123 ;
V_123 = F_38 ( F_37 ( V_24 ) , L_3 , NULL , NULL ) ;
if ( F_39 ( V_123 ) ) {
F_40 ( V_24 , L_4 ) ;
return - V_120 ;
}
} else if ( V_1 -> V_124 ) {
F_41 ( V_1 -> V_124 , V_1 -> V_125 ,
V_107 ) ;
F_41 ( V_1 -> V_124 , V_1 -> V_126 + 4 ,
V_107 ) ;
F_35 ( 1 ) ;
F_42 ( V_1 -> V_124 , V_1 -> V_127 , & V_4 ) ;
if ( V_107 != ( V_4 & V_107 ) ) {
F_40 ( V_24 , L_5 ) ;
return - V_120 ;
}
F_41 ( V_1 -> V_124 , V_1 -> V_125 + 4 ,
V_107 ) ;
F_41 ( V_1 -> V_124 , V_1 -> V_126 ,
V_107 ) ;
F_35 ( 1 ) ;
F_42 ( V_1 -> V_124 , V_1 -> V_127 ,
& V_4 ) ;
if ( V_4 & V_107 ) {
F_40 ( V_24 , L_6 ) ;
return - V_120 ;
}
} else
F_15 ( V_24 , L_7 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_1 )
{
T_1 V_45 ;
int V_5 ;
V_1 -> V_128 = ( 1 << V_1 -> V_109 ) - 1 ;
for ( V_5 = 0 ; V_5 < V_1 -> V_109 ; V_5 ++ ) {
V_45 = F_8 ( V_1 , V_5 , V_129 ) ;
if ( ! ( V_45 & V_130 ) )
continue;
V_45 &= ~ V_130 ;
F_7 ( V_1 , V_5 , V_129 , V_45 ) ;
}
}
static void F_44 ( struct V_1 * V_1 )
{
int V_5 ;
T_1 V_131 ;
for ( V_5 = 0 ; V_5 < V_1 -> V_109 ; V_5 ++ ) {
if ( ! ( V_1 -> V_128 & F_45 ( V_5 ) ) )
continue;
V_131 = F_8 ( V_1 , V_5 ,
V_132 ) ;
if ( V_131 & V_133 ) {
T_1 V_45 = F_8 ( V_1 ,
V_5 , V_129 ) ;
V_45 |= V_130 ;
F_7 ( V_1 , V_5 ,
V_129 , V_45 ) ;
F_30 ( V_5 , & V_1 -> V_128 ) ;
}
}
}
static void F_46 ( struct V_1 * V_1 )
{
struct V_8 * V_24 = V_1 -> V_24 ;
int V_29 ;
if ( F_47 ( V_24 , L_8 ) ) {
F_5 ( V_1 , V_134 , 0x2020 ) ;
F_5 ( V_1 , V_135 ,
0x2020 ) ;
}
F_5 ( V_1 , V_110 ,
( T_1 ) ( ( 1ULL << V_1 -> V_37 ) - 1 ) ) ;
F_5 ( V_1 , V_136 , 0xc0000000 ) ;
F_5 ( V_1 , V_137 , 0x10000 ) ;
F_5 ( V_1 , V_138 , 0x0 ) ;
F_5 ( V_1 , V_139 , 0x7FF ) ;
F_5 ( V_1 , V_140 , 0x1 ) ;
F_5 ( V_1 , V_141 , 0x1F4 ) ;
F_5 ( V_1 , V_142 , 0x32 ) ;
F_5 ( V_1 , V_143 , 0x1 ) ;
F_5 ( V_1 , V_144 , 0x1 ) ;
F_5 ( V_1 , V_145 , 0x1 ) ;
F_5 ( V_1 , V_146 , 0x1 ) ;
F_5 ( V_1 , V_147 , 0xc ) ;
F_5 ( V_1 , V_148 , 0x60 ) ;
F_5 ( V_1 , V_149 , 0x3 ) ;
F_5 ( V_1 , V_150 , 0x1 ) ;
F_5 ( V_1 , V_151 , 0x1 ) ;
F_5 ( V_1 , V_152 , 0x0 ) ;
F_5 ( V_1 , V_153 , 0xffffffff ) ;
F_5 ( V_1 , V_154 , 0xffffffff ) ;
F_5 ( V_1 , V_102 , 0xffffffff ) ;
F_5 ( V_1 , V_155 , 0x7efefefe ) ;
F_5 ( V_1 , V_156 , 0x7efefefe ) ;
F_5 ( V_1 , V_157 , 0x7ffe20fe ) ;
F_5 ( V_1 , V_158 , 0xfff00c30 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_37 ; V_29 ++ )
F_5 ( V_1 , V_159 + 0x4 * V_29 , 0 ) ;
F_5 ( V_1 , V_160 , 1 ) ;
F_5 ( V_1 , V_161 , 1 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_109 ; V_29 ++ ) {
F_7 ( V_1 , V_29 , V_162 , 0x855 ) ;
F_7 ( V_1 , V_29 , V_163 , 0x30b9908 ) ;
F_7 ( V_1 , V_29 , V_164 , 0x7d7d7d7d ) ;
F_7 ( V_1 , V_29 , V_165 , 0x0 ) ;
F_7 ( V_1 , V_29 , V_166 , 0x2 ) ;
F_7 ( V_1 , V_29 , V_167 , 0x8 ) ;
F_7 ( V_1 , V_29 , V_168 , 0xffffffff ) ;
F_7 ( V_1 , V_29 , V_169 , 0xffffffff ) ;
F_7 ( V_1 , V_29 , V_170 , 0xfff87fff ) ;
F_7 ( V_1 , V_29 , V_171 , 0x1000 ) ;
F_7 ( V_1 , V_29 , V_172 , 0xffffffff ) ;
F_7 ( V_1 , V_29 , V_173 , 0x8ffffbff ) ;
F_7 ( V_1 , V_29 , V_174 , 0x13f801fc ) ;
F_7 ( V_1 , V_29 , V_175 , 0x0 ) ;
F_7 ( V_1 , V_29 , V_176 , 0x0 ) ;
F_7 ( V_1 , V_29 , V_177 , 0x0 ) ;
F_7 ( V_1 , V_29 , V_178 , 0x0 ) ;
F_7 ( V_1 , V_29 , V_179 , 0x0 ) ;
F_7 ( V_1 , V_29 , V_180 , 0x0 ) ;
F_7 ( V_1 , V_29 , V_181 , 0x0 ) ;
if ( V_1 -> V_182 == 66 )
F_7 ( V_1 , V_29 , V_183 , 0x199B694 ) ;
}
for ( V_29 = 0 ; V_29 < V_1 -> V_37 ; V_29 ++ ) {
F_5 ( V_1 ,
V_184 + ( V_29 * 0x14 ) ,
F_48 ( V_1 -> V_185 [ V_29 ] ) ) ;
F_5 ( V_1 , V_186 + ( V_29 * 0x14 ) ,
F_49 ( V_1 -> V_185 [ V_29 ] ) ) ;
F_5 ( V_1 , V_187 + ( V_29 * 0x14 ) ,
V_188 ) ;
F_5 ( V_1 , V_189 + ( V_29 * 0x14 ) ,
F_48 ( V_1 -> V_190 [ V_29 ] ) ) ;
F_5 ( V_1 , V_191 + ( V_29 * 0x14 ) ,
F_49 ( V_1 -> V_190 [ V_29 ] ) ) ;
F_5 ( V_1 , V_192 + ( V_29 * 0x14 ) ,
V_188 ) ;
}
F_5 ( V_1 , V_193 ,
F_49 ( V_1 -> V_194 ) ) ;
F_5 ( V_1 , V_195 ,
F_48 ( V_1 -> V_194 ) ) ;
F_5 ( V_1 , V_196 ,
F_49 ( V_1 -> V_197 ) ) ;
F_5 ( V_1 , V_198 ,
F_48 ( V_1 -> V_197 ) ) ;
F_5 ( V_1 , V_199 ,
F_49 ( V_1 -> V_200 ) ) ;
F_5 ( V_1 , V_201 ,
F_48 ( V_1 -> V_200 ) ) ;
F_5 ( V_1 , V_202 ,
F_49 ( V_1 -> V_203 ) ) ;
F_5 ( V_1 , V_204 ,
F_48 ( V_1 -> V_203 ) ) ;
F_5 ( V_1 , V_205 ,
F_49 ( V_1 -> V_206 ) ) ;
F_5 ( V_1 , V_207 ,
F_48 ( V_1 -> V_206 ) ) ;
}
static void F_50 ( unsigned long V_208 )
{
struct V_1 * V_1 = (struct V_1 * ) V_208 ;
int V_29 , V_101 ;
for ( V_29 = 0 ; V_29 < V_1 -> V_109 ; V_29 ++ ) {
if ( V_1 -> V_128 & F_45 ( V_29 ) )
continue;
V_101 = F_8 ( V_1 , V_29 , V_129 ) ;
if ( ! ( V_101 & F_45 ( 0 ) ) ) {
F_7 ( V_1 , V_29 ,
V_129 , 0x7 ) ;
break;
}
}
V_1 -> V_209 . V_210 = V_211 ;
F_51 ( & V_1 -> V_209 , V_115 + F_34 ( 900 ) ) ;
}
static void V_211 ( unsigned long V_208 )
{
struct V_1 * V_1 = (struct V_1 * ) V_208 ;
int V_29 , V_101 ;
V_101 = F_1 ( V_1 , V_212 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_109 && V_101 ; V_29 ++ ) {
if ( V_1 -> V_128 & F_45 ( V_29 ) )
continue;
if ( V_101 & F_45 ( V_29 ) ) {
F_7 ( V_1 , V_29 ,
V_129 , 0x6 ) ;
break;
}
}
V_1 -> V_209 . V_210 = F_50 ;
F_51 ( & V_1 -> V_209 , V_115 + F_34 ( 100 ) ) ;
}
static void F_52 ( struct V_1 * V_1 )
{
V_1 -> V_209 . V_208 = ( unsigned long ) V_1 ;
V_1 -> V_209 . V_210 = V_211 ;
V_1 -> V_209 . V_213 = V_115 + F_34 ( 1000 ) ;
F_53 ( & V_1 -> V_209 ) ;
}
static int F_54 ( struct V_1 * V_1 )
{
struct V_8 * V_24 = V_1 -> V_24 ;
int V_214 ;
V_214 = F_32 ( V_1 ) ;
if ( V_214 ) {
F_40 ( V_24 , L_9 , V_214 ) ;
return V_214 ;
}
F_35 ( 100 ) ;
F_46 ( V_1 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_45 = F_8 ( V_1 , V_5 , V_46 ) ;
V_45 |= V_215 ;
F_7 ( V_1 , V_5 , V_46 , V_45 ) ;
}
static bool F_56 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_216 ;
V_216 = F_1 ( V_1 , V_217 ) ;
if ( V_216 & ( 1 << V_5 ) )
return true ;
return false ;
}
static bool F_57 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_218 ;
V_218 = F_8 ( V_1 , V_5 , V_132 ) ;
if ( V_218 & F_45 ( 16 ) )
return false ;
return true ;
}
static bool F_58 ( struct V_1 * V_1 , int V_5 )
{
int V_29 , V_219 = 1000 ;
struct V_8 * V_24 = V_1 -> V_24 ;
T_1 V_220 , V_121 , V_218 , V_221 ;
for ( V_29 = 0 ; V_29 < V_219 ; V_29 ++ ) {
V_220 = F_3 ( V_1 ,
V_222 + V_223 ) ;
V_121 = F_1 ( V_1 , V_122 ) ;
V_218 = F_8 ( V_1 , V_5 , V_132 ) ;
V_221 = F_8 ( V_1 ,
V_5 , V_224 ) ;
if ( ( V_220 == 0x3 ) && ( V_121 == 0x0 ) &&
( V_218 & F_45 ( 20 ) ) && ( V_221 & F_45 ( 10 ) ) )
return true ;
F_33 ( 10 ) ;
}
F_40 ( V_24 , L_10 ,
V_5 , V_220 , V_121 ,
V_218 , V_221 ) ;
return false ;
}
static bool F_59 ( struct V_1 * V_1 , int V_5 )
{
int V_29 , V_219 = 1000 ;
struct V_8 * V_24 = V_1 -> V_24 ;
T_1 V_220 , V_225 ;
for ( V_29 = 0 ; V_29 < V_219 ; V_29 ++ ) {
V_220 = F_8 ( V_1 , V_5 , V_226 ) ;
V_220 = ( V_220 & 0x3fc0 ) >> 6 ;
if ( V_220 != 0x1 )
return true ;
V_225 = F_8 ( V_1 , V_5 , V_227 ) ;
if ( ( V_225 & 0x1ff ) == 0x2 )
return true ;
F_33 ( 10 ) ;
}
F_40 ( V_24 , L_11 ,
V_5 , V_220 , V_225 ) ;
return false ;
}
static bool F_60 ( struct V_1 * V_1 , int V_5 )
{
if ( F_57 ( V_1 , V_5 ) )
return true ;
if ( ! F_58 ( V_1 , V_5 ) )
return false ;
if ( ! F_59 ( V_1 , V_5 ) )
return false ;
return true ;
}
static void F_61 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_45 , V_228 , V_229 , V_230 ;
struct V_8 * V_24 = V_1 -> V_24 ;
V_228 = F_1 ( V_1 , V_222 +
V_231 ) ;
V_228 |= 0x1 ;
F_5 ( V_1 , V_222 +
V_231 , V_228 ) ;
if ( F_56 ( V_1 , V_5 ) ) {
if ( F_60 ( V_1 , V_5 ) )
goto V_232;
F_62 ( V_1 -> V_233 , & V_1 -> V_234 ) ;
return;
}
V_229 = F_8 ( V_1 , V_5 , V_235 ) ;
V_229 = ( V_229 & 0x1fc0 ) >> 6 ;
if ( V_229 != 0x4 )
goto V_232;
if ( ! F_57 ( V_1 , V_5 ) ) {
F_15 ( V_24 , L_12 ,
V_5 ) ;
V_230 = F_8 ( V_1 , V_5 ,
V_166 ) ;
V_230 |= V_236 ;
F_7 ( V_1 , V_5 , V_166 ,
V_230 ) ;
}
V_232:
V_45 = F_8 ( V_1 , V_5 , V_46 ) ;
V_45 &= ~ V_215 ;
F_7 ( V_1 , V_5 , V_46 , V_45 ) ;
V_228 &= ~ 0x1 ;
F_5 ( V_1 , V_222 +
V_231 , V_228 ) ;
}
static void F_63 ( struct V_1 * V_1 , int V_5 )
{
F_21 ( V_1 , V_5 ) ;
F_20 ( V_1 , V_5 ) ;
F_55 ( V_1 , V_5 ) ;
}
static void F_64 ( struct V_1 * V_1 , int V_5 )
{
struct V_237 * V_238 = & V_1 -> V_238 [ V_5 ] ;
T_1 V_230 ;
F_61 ( V_1 , V_5 ) ;
if ( V_238 -> V_239 . V_240 == V_52 ) {
V_230 = F_8 ( V_1 , V_5 , V_166 ) ;
F_7 ( V_1 , V_5 , V_166 ,
V_230 | V_241 ) ;
}
F_35 ( 100 ) ;
F_63 ( V_1 , V_5 ) ;
}
static void F_65 ( struct V_1 * V_1 , int V_5 )
{
struct V_237 * V_238 = & V_1 -> V_238 [ V_5 ] ;
struct V_242 * V_243 = & V_238 -> V_243 ;
struct V_243 * V_244 = V_243 -> V_238 ;
T_1 V_245 , V_246 ;
V_245 = F_8 ( V_1 , V_5 , V_247 ) ;
V_246 = F_8 ( V_1 , V_5 , V_248 ) ;
V_244 -> V_249 += ( V_245 >> 16 ) & 0xFFFF ;
V_244 -> V_250 += V_245 & 0xFFFF ;
V_244 -> V_251 += ( V_246 & 0xFF0000 ) >> 16 ;
V_244 -> V_252 += V_246 & 0xFF ;
}
static void F_66 ( struct V_1 * V_1 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_1 -> V_109 ; V_29 ++ ) {
struct V_237 * V_238 = & V_1 -> V_238 [ V_29 ] ;
struct V_242 * V_243 = & V_238 -> V_243 ;
if ( ! V_243 -> V_238 -> V_253 )
continue;
F_63 ( V_1 , V_29 ) ;
}
}
static void F_67 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_254 ;
V_254 = F_8 ( V_1 , V_5 , V_165 ) ;
V_254 |= V_255 ;
F_7 ( V_1 , V_5 , V_165 , V_254 ) ;
F_35 ( 1 ) ;
V_254 = F_8 ( V_1 , V_5 , V_165 ) ;
V_254 &= ~ V_255 ;
F_7 ( V_1 , V_5 , V_165 , V_254 ) ;
}
static enum V_256 F_68 ( void )
{
return V_257 ;
}
static void F_69 ( struct V_1 * V_1 , int V_5 ,
struct V_258 * V_259 )
{
T_1 V_260 =
F_8 ( V_1 , V_5 , V_162 ) ;
struct V_237 * V_238 = & V_1 -> V_238 [ V_5 ] ;
struct V_242 * V_243 = & V_238 -> V_243 ;
int V_29 ;
enum V_256 V_261 , V_262 ;
T_1 V_263 = 0 ;
if ( V_259 -> V_264 == V_265 ) {
V_262 = V_243 -> V_238 -> V_264 ;
V_261 = V_259 -> V_266 ;
} else if ( V_259 -> V_266 == V_265 ) {
V_262 = V_259 -> V_264 ;
V_261 = V_243 -> V_238 -> V_266 ;
} else
return;
V_243 -> V_238 -> V_264 = V_262 ;
V_243 -> V_238 -> V_266 = V_261 ;
V_261 -= V_267 ;
V_262 -= V_267 ;
for ( V_29 = 0 ; V_29 <= V_262 ; V_29 ++ )
V_263 |= 1 << ( V_29 * 2 ) ;
V_260 &= ~ 0xff ;
V_260 |= V_263 ;
F_7 ( V_1 , V_5 , V_162 ,
V_260 ) ;
F_64 ( V_1 , V_5 ) ;
}
static int F_70 ( struct V_1 * V_1 , int V_268 )
{
int V_29 , V_10 = 0 ;
T_1 V_269 = F_1 ( V_1 , V_270 ) ;
T_1 V_271 = F_1 ( V_1 , V_212 ) ;
for ( V_29 = 0 ; V_29 < ( V_1 -> V_109 < 9 ? V_1 -> V_109 : 8 ) ; V_29 ++ )
if ( V_271 & 1 << V_29 )
if ( ( ( V_269 >> ( V_29 * 4 ) ) & 0xf ) == V_268 )
V_10 |= 1 << V_29 ;
if ( V_1 -> V_109 == 9 ) {
T_1 V_272 = F_1 ( V_1 , V_273 ) ;
if ( V_271 & 1 << 8 )
if ( ( ( V_272 & V_274 ) >>
V_275 ) == V_268 )
V_10 |= 1 << 9 ;
}
return V_10 ;
}
static int
F_71 ( struct V_1 * V_1 , struct V_38 * V_39 )
{
struct V_8 * V_24 = V_1 -> V_24 ;
int V_36 = V_39 -> V_92 ;
T_1 V_259 , V_276 ;
V_276 = V_39 -> V_277 ;
V_259 = F_3 ( V_1 ,
V_278 + ( V_36 * 0x14 ) ) ;
if ( V_259 == ( V_276 + 1 ) % V_188 ) {
F_15 ( V_24 , L_13 ,
V_36 , V_259 , V_276 ) ;
return - V_279 ;
}
return 0 ;
}
static void F_72 ( struct V_38 * V_39 )
{
struct V_1 * V_1 = V_39 -> V_1 ;
int V_280 = V_39 -> V_281 -> V_280 ;
int V_282 = V_39 -> V_281 -> V_282 ;
V_39 -> V_277 = ++ V_282 % V_188 ;
F_5 ( V_1 , V_283 + ( V_280 * 0x14 ) ,
V_39 -> V_277 ) ;
}
static int F_73 ( struct V_1 * V_1 ,
struct V_284 * V_285 ,
struct V_286 * V_287 ,
struct V_288 * V_289 ,
int V_290 )
{
struct V_291 * V_292 = F_74 ( V_285 ) ;
struct V_8 * V_24 = V_1 -> V_24 ;
struct V_288 * V_293 ;
int V_29 ;
if ( V_290 > V_294 ) {
F_40 ( V_24 , L_14 ,
V_290 ) ;
return - V_20 ;
}
F_75 (scatter, sg, n_elem, i) {
struct V_295 * V_296 = & V_292 -> V_297 [ V_29 ] ;
V_296 -> V_298 = F_26 ( F_76 ( V_293 ) ) ;
V_296 -> V_299 = V_296 -> V_300 = 0 ;
V_296 -> V_301 = F_77 ( F_78 ( V_293 ) ) ;
V_296 -> V_302 = 0 ;
}
V_287 -> V_303 = F_26 ( F_79 ( V_285 ) ) ;
V_287 -> V_304 = F_77 ( V_290 << V_305 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_1 ,
struct V_284 * V_285 )
{
struct V_306 * V_307 = V_285 -> V_307 ;
struct V_286 * V_287 = V_285 -> V_308 ;
struct V_7 * V_8 = V_307 -> V_24 ;
struct V_8 * V_24 = V_1 -> V_24 ;
struct V_76 * V_26 = V_285 -> V_26 ;
struct V_288 * V_309 , * V_310 ;
struct V_12 * V_13 = V_8 -> V_14 ;
T_5 V_311 ;
unsigned int V_312 , V_313 ;
int V_314 , V_214 ;
V_309 = & V_307 -> V_315 . V_316 ;
V_314 = F_81 ( V_24 , V_309 , 1 , V_317 ) ;
if ( ! V_314 )
return - V_318 ;
V_312 = F_78 ( V_309 ) ;
V_311 = F_76 ( V_309 ) ;
V_310 = & V_307 -> V_315 . V_319 ;
V_314 = F_81 ( V_24 , V_310 , 1 , V_320 ) ;
if ( ! V_314 ) {
V_214 = - V_318 ;
goto V_321;
}
V_313 = F_78 ( V_310 ) ;
if ( ( V_312 & 0x3 ) || ( V_313 & 0x3 ) ) {
V_214 = - V_20 ;
goto V_322;
}
V_287 -> V_323 = F_77 ( ( V_26 -> V_92 << V_324 ) |
( 1 << V_325 ) |
( 2 << V_326 ) ) ;
V_287 -> V_327 = F_77 ( ( V_13 -> V_40 << V_328 ) |
( 1 << V_329 ) |
( V_330 << V_331 ) ) ;
V_287 -> V_332 = F_77 ( ( ( ( V_312 - 4 ) / 4 ) << V_333 ) |
( V_334 / 4 <<
V_335 ) ) ;
V_287 -> V_336 = F_77 ( V_285 -> V_22 << V_337 ) ;
V_287 -> V_338 = F_26 ( V_311 ) ;
V_287 -> V_339 = F_26 ( F_82 ( V_285 ) ) ;
return 0 ;
V_322:
F_83 ( V_24 , & V_285 -> V_307 -> V_315 . V_319 , 1 ,
V_320 ) ;
V_321:
F_83 ( V_24 , & V_285 -> V_307 -> V_315 . V_316 , 1 ,
V_317 ) ;
return V_214 ;
}
static int F_84 ( struct V_1 * V_1 ,
struct V_284 * V_285 , int V_340 ,
struct V_341 * V_342 )
{
struct V_306 * V_307 = V_285 -> V_307 ;
struct V_286 * V_287 = V_285 -> V_308 ;
struct V_7 * V_8 = V_307 -> V_24 ;
struct V_12 * V_13 = V_8 -> V_14 ;
struct V_76 * V_26 = V_285 -> V_26 ;
struct V_343 * V_344 = & V_307 -> V_344 ;
struct V_345 * V_345 = V_344 -> V_346 ;
int V_347 = 0 , V_214 , V_348 = V_340 ;
T_6 * V_349 ;
T_1 V_327 = 0 , V_332 = 0 ;
V_287 -> V_323 = F_77 ( ( 1 << V_350 ) |
( 2 << V_351 ) |
( V_26 -> V_92 << V_324 ) |
( V_348 << V_325 ) |
( 1 << V_326 ) ) ;
V_327 = 1 << V_352 ;
if ( V_340 ) {
V_327 |= 2 << V_329 ;
V_327 |= V_330 << V_331 ;
} else {
V_327 |= 1 << V_329 ;
switch ( V_345 -> V_353 ) {
case V_317 :
V_347 = 1 ;
V_327 |= V_354 << V_331 ;
break;
case V_320 :
V_347 = 1 ;
V_327 |= V_355 << V_331 ;
break;
default:
V_327 &= ~ V_356 ;
}
}
V_327 |= V_13 -> V_40 << V_328 ;
V_287 -> V_327 = F_77 ( V_327 ) ;
V_332 = ( ( ( sizeof( struct V_357 ) + sizeof( struct V_358 )
+ 3 ) / 4 ) << V_333 ) |
( ( V_359 / 4 ) << V_335 ) |
( 2 << V_360 ) ;
V_287 -> V_332 = F_77 ( V_332 ) ;
V_287 -> V_336 = F_77 ( V_285 -> V_22 ) ;
if ( V_347 ) {
V_214 = F_73 ( V_1 , V_285 , V_287 , V_307 -> V_289 ,
V_285 -> V_290 ) ;
if ( V_214 )
return V_214 ;
}
V_287 -> V_361 = F_77 ( V_307 -> V_362 ) ;
V_287 -> V_338 = F_26 ( F_85 ( V_285 ) ) ;
V_287 -> V_339 = F_26 ( F_82 ( V_285 ) ) ;
V_349 = F_86 ( V_285 ) +
sizeof( struct V_358 ) ;
memcpy ( V_349 , & V_307 -> V_344 . V_363 , 8 ) ;
if ( ! V_340 ) {
V_349 [ 9 ] = V_307 -> V_344 . V_364 |
( V_307 -> V_344 . V_365 << 3 ) ;
memcpy ( V_349 + 12 , V_307 -> V_344 . V_346 -> V_366 ,
V_307 -> V_344 . V_346 -> V_367 ) ;
} else {
V_349 [ 10 ] = V_342 -> V_342 ;
switch ( V_342 -> V_342 ) {
case V_368 :
case V_369 :
V_349 [ 12 ] =
( V_342 -> V_370 >> 8 ) & 0xff ;
V_349 [ 13 ] =
V_342 -> V_370 & 0xff ;
break;
default:
break;
}
}
return 0 ;
}
static int F_87 ( T_1 V_371 )
{
static const T_6 V_372 [] = {
V_373 ,
V_374 ,
V_375 ,
V_376 ,
V_377 ,
V_378 ,
V_379 ,
V_380 ,
V_381 ,
V_382 ,
V_383 ,
V_384 ,
V_385 ,
V_386 ,
V_387 ,
V_388 ,
V_389 ,
V_390 ,
V_391 ,
V_392 ,
V_393 ,
V_394 ,
V_395 ,
V_396 ,
V_397 ,
V_398 ,
V_399 ,
V_400 ,
V_401 ,
V_402 ,
V_403 ,
} ;
int V_23 , V_29 ;
for ( V_29 = 0 ; V_29 < F_88 ( V_372 ) ; V_29 ++ ) {
V_23 = V_372 [ V_29 ] - V_404 ;
if ( V_371 & ( 1 << V_23 ) )
return V_372 [ V_29 ] ;
}
return - 1 ;
}
static int F_89 ( T_1 V_371 )
{
static const T_6 V_405 [] = {
V_406 ,
V_407 ,
V_408 ,
V_409 ,
V_410 ,
V_411 ,
V_412 ,
V_413 ,
V_414 ,
V_415 ,
V_416 ,
V_417 ,
V_418 ,
V_419 ,
V_420 ,
V_421 ,
V_422 ,
V_423 ,
V_424 ,
V_425 ,
V_426 ,
V_427 ,
V_428 ,
V_429 ,
V_430 ,
V_431 ,
V_432 ,
V_433 ,
V_434 ,
V_435 ,
V_436 ,
V_437 ,
} ;
int V_23 , V_29 ;
for ( V_29 = 0 ; V_29 < F_88 ( V_405 ) ; V_29 ++ ) {
V_23 = V_405 [ V_29 ] - V_438 ;
if ( V_371 & ( 1 << V_23 ) )
return V_405 [ V_29 ] ;
}
return - 1 ;
}
static int F_90 ( T_1 V_371 )
{
static const T_6 V_439 [] = {
V_440 ,
V_441 ,
V_442 ,
V_443 ,
V_444 ,
V_445 ,
V_446 ,
V_447 ,
V_448 ,
V_449 ,
V_450 ,
} ;
int V_23 , V_29 ;
for ( V_29 = 0 ; V_29 < F_88 ( V_439 ) ; V_29 ++ ) {
V_23 = V_439 [ V_29 ] - V_451 ;
V_371 = V_371 & V_452 ;
if ( V_371 & ( 1 << V_23 ) )
return V_439 [ V_29 ] ;
}
return - 1 ;
}
static int F_91 ( T_1 V_371 )
{
static const T_6 V_453 [] = {
V_454 ,
V_455 ,
V_456 ,
V_457 ,
V_458 ,
V_459 ,
V_460 ,
V_461 ,
V_462 ,
V_463 ,
V_464 ,
} ;
int V_23 , V_29 ;
for ( V_29 = 0 ; V_29 < F_88 ( V_453 ) ; V_29 ++ ) {
V_23 = V_453 [ V_29 ] - V_465 ;
V_371 = V_371 & V_466 ;
if ( V_371 & ( 1 << ( V_23 + 0x10 ) ) )
return V_453 [ V_29 ] ;
}
return - 1 ;
}
static int F_92 ( T_1 V_371 )
{
static const T_6 V_467 [] = {
V_468 ,
V_469 ,
V_470 ,
V_471 ,
V_472 ,
V_473 ,
V_474 ,
V_475 ,
V_476 ,
V_477 ,
V_478 ,
V_479 ,
V_480 ,
V_481 ,
V_482 ,
V_483 ,
V_484 ,
V_485 ,
V_486 ,
V_487 ,
V_488 ,
V_489 ,
V_490 ,
V_491 ,
V_492 ,
V_493 ,
} ;
int V_23 , V_29 ;
for ( V_29 = 0 ; V_29 < F_88 ( V_467 ) ; V_29 ++ ) {
V_23 = V_467 [ V_29 ] - V_494 ;
if ( V_371 & ( 1 << V_23 ) )
return V_467 [ V_29 ] ;
}
return - 1 ;
}
static void F_93 ( struct V_1 * V_1 ,
struct V_306 * V_307 ,
struct V_284 * V_285 ,
int V_495 )
{
struct V_496 * V_497 = & V_307 -> V_498 ;
struct V_499 * V_500 =
F_94 ( V_285 ) ;
T_1 V_501 = F_77 ( V_500 -> V_501 ) ;
T_1 V_502 = F_77 ( V_500 -> V_502 ) ;
T_7 V_503 = F_95 ( V_500 -> V_503 ) ;
T_7 V_504 = F_95 ( V_500 -> V_504 ) ;
T_1 V_505 = F_77 ( V_500 -> V_505 ) ;
int error = - 1 ;
if ( V_495 == 1 ) {
error = F_90 ( V_503 ) ;
if ( error == - 1 )
error = F_87 (
V_501 ) ;
} else if ( V_495 == 2 ) {
error = F_89 (
V_502 ) ;
if ( error == - 1 ) {
error = F_92 (
V_505 ) ;
if ( error == - 1 )
error = F_91 (
V_504 ) ;
}
}
switch ( V_307 -> V_506 ) {
case V_507 :
{
switch ( error ) {
case V_388 :
{
V_497 -> V_508 = V_509 ;
V_497 -> V_510 = V_511 ;
break;
}
case V_381 :
{
V_497 -> V_508 = V_509 ;
V_497 -> V_510 = V_512 ;
break;
}
case V_382 :
{
V_497 -> V_508 = V_509 ;
V_497 -> V_510 = V_513 ;
break;
}
case V_383 :
{
V_497 -> V_508 = V_509 ;
V_497 -> V_510 = V_514 ;
break;
}
case V_375 :
{
V_497 -> V_508 = V_509 ;
V_497 -> V_510 = V_515 ;
break;
}
case V_476 :
case V_376 :
case V_474 :
{
V_497 -> V_508 = V_509 ;
V_497 -> V_510 = V_516 ;
break;
}
case V_385 :
{
V_497 -> V_508 = V_517 ;
break;
}
case V_469 :
{
V_497 -> V_508 = V_518 ;
V_497 -> V_519 = 0 ;
break;
}
case V_470 :
{
V_497 -> V_519 = V_501 ;
V_497 -> V_508 = V_520 ;
break;
}
case V_373 :
case V_374 :
case V_377 :
case V_379 :
case V_384 :
case V_386 :
case V_387 :
case V_389 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_397 :
case V_390 :
case V_391 :
case V_392 :
case V_398 :
case V_399 :
case V_400 :
case V_401 :
case V_406 :
case V_407 :
case V_408 :
case V_413 :
case V_417 :
case V_418 :
case V_419 :
case V_421 :
case V_415 :
case V_416 :
case V_521 :
case V_414 :
case V_422 :
case V_423 :
case V_424 :
case V_425 :
case V_430 :
case V_449 :
case V_440 :
case V_441 :
case V_442 :
case V_443 :
case V_464 :
case V_492 :
case V_471 :
case V_482 :
case V_483 :
case V_484 :
case V_473 :
case V_468 :
{
V_497 -> V_508 = V_21 ;
V_285 -> abort = 1 ;
break;
}
default:
break;
}
}
break;
case V_522 :
V_497 -> V_508 = V_523 ;
break;
case V_524 :
case V_525 :
case V_524 | V_525 :
{
switch ( error ) {
case V_388 :
{
V_497 -> V_508 = V_509 ;
V_497 -> V_510 = V_511 ;
break;
}
case V_385 :
{
V_497 -> V_526 = V_527 ;
V_497 -> V_508 = V_517 ;
break;
}
case V_381 :
{
V_497 -> V_508 = V_509 ;
V_497 -> V_510 = V_512 ;
break;
}
case V_382 :
{
V_497 -> V_508 = V_509 ;
V_497 -> V_510 = V_513 ;
break;
}
case V_383 :
{
V_497 -> V_508 = V_509 ;
V_497 -> V_510 = V_513 ;
break;
}
case V_375 :
{
V_497 -> V_508 = V_509 ;
V_497 -> V_510 = V_515 ;
break;
}
case V_474 :
case V_476 :
case V_376 :
{
V_497 -> V_508 = V_509 ;
V_497 -> V_510 = V_516 ;
break;
}
case V_469 :
{
V_497 -> V_508 = V_518 ;
V_497 -> V_519 = 0 ;
break;
}
case V_470 :
{
V_497 -> V_519 = V_501 ;
V_497 -> V_508 = V_520 ;
break;
}
case V_373 :
case V_374 :
case V_377 :
case V_379 :
case V_384 :
case V_386 :
case V_387 :
case V_389 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_397 :
case V_390 :
case V_391 :
case V_392 :
case V_399 :
case V_400 :
case V_402 :
case V_403 :
case V_408 :
case V_407 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_413 :
case V_417 :
case V_418 :
case V_419 :
case V_421 :
case V_414 :
case V_415 :
case V_416 :
case V_422 :
case V_423 :
case V_424 :
case V_430 :
case V_449 :
case V_440 :
case V_441 :
case V_442 :
case V_443 :
case V_454 :
case V_455 :
case V_456 :
case V_457 :
case V_458 :
case V_459 :
case V_462 :
case V_492 :
case V_471 :
case V_473 :
case V_477 :
case V_478 :
case V_479 :
case V_480 :
case V_481 :
case V_482 :
case V_483 :
case V_484 :
case V_485 :
case V_486 :
case V_487 :
case V_468 :
case V_425 :
case V_380 :
{
V_285 -> abort = 1 ;
V_497 -> V_508 = V_528 ;
break;
}
default:
{
V_497 -> V_508 = V_529 ;
break;
}
}
F_96 ( V_307 , V_285 ) ;
}
break;
default:
break;
}
}
static int
F_97 ( struct V_1 * V_1 , struct V_284 * V_285 )
{
struct V_306 * V_307 = V_285 -> V_307 ;
struct V_12 * V_13 ;
struct V_8 * V_24 = V_1 -> V_24 ;
struct V_496 * V_497 ;
struct V_7 * V_8 ;
enum V_530 V_531 ;
struct V_532 * V_533 =
V_1 -> V_534 [ V_285 -> V_535 ] ;
struct V_532 * V_534 =
& V_533 [ V_285 -> V_536 ] ;
unsigned long V_537 ;
int V_538 ;
if ( F_98 ( ! V_307 || ! V_307 -> V_539 || ! V_307 -> V_24 ) )
return - V_20 ;
V_497 = & V_307 -> V_498 ;
V_8 = V_307 -> V_24 ;
V_13 = V_8 -> V_14 ;
F_99 ( & V_307 -> V_540 , V_537 ) ;
V_538 = V_307 -> V_541 & V_542 ;
V_307 -> V_541 &=
~ ( V_543 | V_544 ) ;
F_100 ( & V_307 -> V_540 , V_537 ) ;
memset ( V_497 , 0 , sizeof( * V_497 ) ) ;
V_497 -> V_526 = V_545 ;
if ( F_98 ( V_538 ) ) {
V_497 -> V_508 = V_546 ;
F_101 ( V_1 , V_307 , V_285 ) ;
return - 1 ;
}
if ( F_98 ( ! V_13 ) ) {
F_102 ( V_24 , L_15 ) ;
V_497 -> V_508 = V_528 ;
goto V_31;
}
switch ( ( V_534 -> V_323 & V_547 )
>> V_548 ) {
case V_549 :
V_497 -> V_508 = V_546 ;
goto V_31;
case V_550 :
V_497 -> V_508 = V_551 ;
F_103 ( & V_285 -> V_552 ) ;
goto V_31;
case V_553 :
V_497 -> V_508 = V_554 ;
F_103 ( & V_285 -> V_552 ) ;
goto V_31;
case V_555 :
V_497 -> V_508 = V_556 ;
F_103 ( & V_285 -> V_552 ) ;
goto V_31;
default:
break;
}
if ( ( V_534 -> V_323 & V_557 ) &&
( ! ( V_534 -> V_323 & V_558 ) ) ) {
T_1 V_495 = ( V_534 -> V_323 & V_559 )
>> V_560 ;
if ( F_104 ( V_495 ) )
F_93 ( V_1 , V_307 , V_285 , 1 ) ;
else if ( F_105 ( V_495 ) )
F_93 ( V_1 , V_307 , V_285 , 2 ) ;
if ( F_98 ( V_285 -> abort ) )
return V_497 -> V_508 ;
goto V_31;
}
switch ( V_307 -> V_506 ) {
case V_507 :
{
struct V_561 * V_562 =
F_94 ( V_285 ) ;
struct V_563 * V_564 = (struct V_563 * )
& V_562 -> V_564 [ 0 ] ;
F_106 ( V_24 , V_307 , V_564 ) ;
break;
}
case V_522 :
{
struct V_288 * V_310 = & V_307 -> V_315 . V_319 ;
void * V_565 ;
V_497 -> V_508 = V_566 ;
V_565 = F_107 ( F_108 ( V_310 ) ) ;
F_83 ( V_24 , & V_307 -> V_315 . V_319 , 1 ,
V_320 ) ;
F_83 ( V_24 , & V_307 -> V_315 . V_316 , 1 ,
V_317 ) ;
memcpy ( V_565 + V_310 -> V_567 ,
F_94 ( V_285 ) +
sizeof( struct V_568 ) ,
F_78 ( V_310 ) ) ;
F_109 ( V_565 ) ;
break;
}
case V_524 :
case V_525 :
case V_524 | V_525 :
{
V_497 -> V_508 = V_566 ;
F_96 ( V_307 , V_285 ) ;
break;
}
default:
V_497 -> V_508 = V_523 ;
break;
}
if ( ! V_285 -> V_26 -> V_569 ) {
F_40 ( V_24 , L_16 ,
V_285 -> V_26 -> V_75 . V_92 ) ;
V_497 -> V_508 = V_528 ;
}
V_31:
F_99 ( & V_307 -> V_540 , V_537 ) ;
V_307 -> V_541 |= V_570 ;
F_100 ( & V_307 -> V_540 , V_537 ) ;
F_99 ( & V_1 -> V_30 , V_537 ) ;
F_101 ( V_1 , V_307 , V_285 ) ;
F_100 ( & V_1 -> V_30 , V_537 ) ;
V_531 = V_497 -> V_508 ;
if ( V_307 -> V_571 )
V_307 -> V_571 ( V_307 ) ;
return V_531 ;
}
static int F_110 ( struct V_1 * V_1 ,
struct V_284 * V_285 )
{
struct V_306 * V_307 = V_285 -> V_307 ;
struct V_7 * V_8 = V_307 -> V_24 ;
struct V_7 * V_72 = V_8 -> V_73 ;
struct V_12 * V_13 = V_8 -> V_14 ;
struct V_286 * V_287 = V_285 -> V_308 ;
struct V_74 * V_75 = V_8 -> V_26 ;
struct V_76 * V_26 = F_24 ( V_75 ) ;
T_6 * V_349 ;
int V_347 = 0 , V_214 = 0 , V_572 = 0 ;
T_1 V_327 = 0 , V_332 = 0 ;
V_287 -> V_323 = F_77 ( V_26 -> V_92 << V_324 ) ;
if ( V_72 && F_25 ( V_72 -> V_34 ) )
V_287 -> V_323 |= F_77 ( 3 << V_326 ) ;
else
V_287 -> V_323 |= F_77 ( 4 << V_326 ) ;
switch ( V_307 -> V_573 ) {
case V_317 :
V_347 = 1 ;
V_327 |= V_354 << V_331 ;
break;
case V_320 :
V_347 = 1 ;
V_327 |= V_355 << V_331 ;
break;
default:
V_327 &= ~ V_356 ;
}
if ( ( V_307 -> V_574 . V_575 . V_576 == V_577 ) &&
( V_307 -> V_574 . V_575 . V_578 & V_579 ) )
V_327 |= 1 << V_580 ;
V_327 |= ( F_111 (
V_307 -> V_574 . V_575 . V_576 , V_307 -> V_573 ) )
<< V_329 ;
V_327 |= V_13 -> V_40 << V_328 ;
V_287 -> V_327 = F_77 ( V_327 ) ;
if ( V_307 -> V_574 . V_581 && F_112 ( V_307 , & V_572 ) ) {
V_307 -> V_574 . V_575 . V_582 |= ( T_6 ) ( V_572 << 3 ) ;
V_332 |= V_572 << V_583 ;
}
V_332 |= ( V_584 / 4 ) << V_333 |
2 << V_360 ;
V_287 -> V_332 = F_77 ( V_332 ) ;
V_287 -> V_336 = F_77 ( V_285 -> V_22 ) ;
if ( V_347 ) {
V_214 = F_73 ( V_1 , V_285 , V_287 , V_307 -> V_289 ,
V_285 -> V_290 ) ;
if ( V_214 )
return V_214 ;
}
V_287 -> V_361 = F_77 ( V_307 -> V_362 ) ;
V_287 -> V_338 = F_26 ( F_85 ( V_285 ) ) ;
V_287 -> V_339 = F_26 ( F_82 ( V_285 ) ) ;
V_349 = F_86 ( V_285 ) ;
if ( F_113 ( ! V_307 -> V_574 . V_585 ) )
V_307 -> V_574 . V_575 . V_537 |= 0x80 ;
memcpy ( V_349 , & V_307 -> V_574 . V_575 , sizeof( struct V_586 ) ) ;
return 0 ;
}
static void F_114 ( unsigned long V_208 )
{
struct V_284 * V_285 = (struct V_284 * ) V_208 ;
struct V_76 * V_26 = V_285 -> V_26 ;
struct V_74 * V_74 ;
struct V_242 * V_243 ;
if ( ! V_26 )
return;
V_74 = & V_26 -> V_75 ;
F_115 (sas_phy, &asd_sas_port->phy_list, port_phy_el) {
struct V_237 * V_238 = V_243 -> V_587 ;
struct V_1 * V_1 = V_238 -> V_1 ;
int V_5 = V_243 -> V_92 ;
T_1 V_588 ;
V_588 = F_8 ( V_1 , V_5 , V_226 ) ;
if ( ( V_588 == V_589 ) ||
( V_588 & V_590 ) ) {
T_1 V_230 ;
V_230 = F_8 ( V_1 , V_5 ,
V_166 ) ;
V_230 |= V_236 ;
F_7 ( V_1 , V_5 , V_166 ,
V_230 ) ;
return;
}
}
}
static int F_116 ( struct V_1 * V_1 ,
struct V_284 * V_285 ,
int V_40 , int V_591 , int V_592 )
{
struct V_306 * V_307 = V_285 -> V_307 ;
struct V_7 * V_24 = V_307 -> V_24 ;
struct V_286 * V_287 = V_285 -> V_308 ;
struct V_76 * V_26 = V_285 -> V_26 ;
struct V_593 * V_209 = & V_285 -> V_552 ;
F_117 ( V_209 , F_114 ,
( unsigned long ) V_285 ) ;
F_51 ( V_209 , V_115 + F_34 ( 100 ) ) ;
V_287 -> V_323 = F_77 ( ( 5 << V_326 ) |
( V_26 -> V_92 << V_324 ) |
( ( F_10 ( V_24 ) ? 1 : 0 ) <<
V_594 ) |
( V_591 << V_595 ) ) ;
V_287 -> V_327 = F_77 ( V_40 << V_328 ) ;
V_287 -> V_596 = F_77 ( V_592 << V_597 ) ;
V_287 -> V_336 = F_77 ( V_285 -> V_22 ) ;
return 0 ;
}
static int F_118 ( int V_5 , struct V_1 * V_1 )
{
int V_29 , V_598 = V_599 ;
T_1 V_268 , V_600 , V_601 ;
struct V_237 * V_238 = & V_1 -> V_238 [ V_5 ] ;
struct V_242 * V_243 = & V_238 -> V_243 ;
struct V_8 * V_24 = V_1 -> V_24 ;
T_1 * V_602 = ( T_1 * ) V_243 -> V_602 ;
struct V_49 * V_92 = (struct V_49 * ) V_602 ;
F_7 ( V_1 , V_5 , V_178 , 1 ) ;
if ( F_56 ( V_1 , V_5 ) )
goto V_17;
if ( V_5 == 8 ) {
T_1 V_272 = F_1 ( V_1 , V_273 ) ;
V_268 = ( V_272 & V_274 ) >>
V_275 ;
V_600 = ( V_272 & V_603 ) >>
V_604 ;
} else {
V_268 = F_1 ( V_1 , V_270 ) ;
V_268 = ( V_268 >> ( 4 * V_5 ) ) & 0xf ;
V_600 = F_1 ( V_1 , V_605 ) ;
V_600 = ( V_600 >> ( V_5 * 4 ) ) & 0xf ;
}
if ( V_268 == 0xf ) {
F_40 ( V_24 , L_17 , V_5 ) ;
V_598 = V_606 ;
goto V_17;
}
for ( V_29 = 0 ; V_29 < 6 ; V_29 ++ ) {
T_1 V_607 = F_8 ( V_1 , V_5 ,
V_608 + ( V_29 * 4 ) ) ;
V_602 [ V_29 ] = F_22 ( V_607 ) ;
}
V_243 -> V_86 = V_600 ;
V_601 = F_8 ( V_1 , V_5 ,
V_609 ) ;
V_238 -> V_264 = V_601 & 0xf ;
V_238 -> V_266 = ( V_601 >> 4 ) & 0xf ;
V_243 -> V_610 = V_611 ;
memcpy ( V_243 -> V_612 , & V_92 -> V_60 , V_61 ) ;
F_119 ( V_24 , L_18 , V_5 , V_600 ) ;
V_238 -> V_268 = V_268 ;
V_238 -> V_613 &= ~ ( V_614 | V_615 ) ;
V_238 -> V_613 |= V_614 ;
V_238 -> V_616 = 1 ;
V_238 -> V_239 . V_240 = V_92 -> V_34 ;
V_238 -> V_617 = sizeof( struct V_49 ) ;
if ( V_238 -> V_239 . V_240 == V_52 )
V_238 -> V_239 . V_618 =
V_507 ;
else if ( V_238 -> V_239 . V_240 != V_35 ) {
V_238 -> V_239 . V_618 =
V_522 ;
if ( ! F_120 ( & V_1 -> V_209 ) )
F_52 ( V_1 ) ;
}
F_62 ( V_1 -> V_233 , & V_238 -> V_619 ) ;
V_17:
F_7 ( V_1 , V_5 , V_168 ,
V_620 ) ;
F_7 ( V_1 , V_5 , V_178 , 0 ) ;
return V_598 ;
}
static bool F_121 ( struct V_1 * V_1 )
{
T_1 V_272 ;
V_272 = F_1 ( V_1 , V_273 ) ;
if ( V_272 & 0x1ff )
return true ;
return false ;
}
static int F_122 ( int V_5 , struct V_1 * V_1 )
{
T_1 V_271 , V_621 , V_230 ;
struct V_237 * V_238 = & V_1 -> V_238 [ V_5 ] ;
struct V_76 * V_26 = V_238 -> V_26 ;
F_7 ( V_1 , V_5 , V_176 , 1 ) ;
V_271 = F_1 ( V_1 , V_212 ) ;
F_123 ( V_1 , V_5 , ( V_271 & 1 << V_5 ) ? 1 : 0 ) ;
V_621 = F_8 ( V_1 , V_5 , V_165 ) ;
F_7 ( V_1 , V_5 , V_165 ,
V_621 & ~ V_622 ) ;
if ( V_26 && ! F_70 ( V_1 , V_26 -> V_92 ) )
if ( ! F_121 ( V_1 ) &&
F_120 ( & V_1 -> V_209 ) )
F_103 ( & V_1 -> V_209 ) ;
V_230 = F_8 ( V_1 , V_5 , V_166 ) ;
F_7 ( V_1 , V_5 , V_166 ,
V_230 | V_623 ) ;
F_7 ( V_1 , V_5 , V_168 , V_624 ) ;
F_7 ( V_1 , V_5 , V_176 , 0 ) ;
return V_599 ;
}
static T_8 F_124 ( int V_625 , void * V_626 )
{
struct V_1 * V_1 = V_626 ;
T_1 V_627 ;
int V_5 = 0 ;
T_8 V_598 = V_606 ;
V_627 = ( F_1 ( V_1 , V_628 )
>> V_629 ) & 0x1ff ;
while ( V_627 ) {
if ( V_627 & 1 ) {
T_1 V_630 = F_8 ( V_1 , V_5 ,
V_168 ) ;
switch ( V_630 & ( V_624 |
V_620 ) ) {
case V_620 :
if ( F_118 ( V_5 , V_1 ) ==
V_599 )
V_598 = V_599 ;
break;
case V_624 :
if ( F_122 ( V_5 , V_1 ) ==
V_599 )
V_598 = V_599 ;
break;
case ( V_624 |
V_620 ) :
V_630 = F_1 ( V_1 ,
V_212 ) ;
if ( V_630 & F_45 ( V_5 ) ) {
if ( F_118 ( V_5 , V_1 ) ==
V_599 )
V_598 = V_599 ;
} else {
if ( F_122 ( V_5 , V_1 ) ==
V_599 )
V_598 = V_599 ;
}
break;
default:
break;
}
}
V_627 >>= 1 ;
V_5 ++ ;
}
return V_598 ;
}
static void F_125 ( int V_5 , struct V_1 * V_1 )
{
struct V_237 * V_238 = & V_1 -> V_238 [ V_5 ] ;
struct V_242 * V_243 = & V_238 -> V_243 ;
struct V_631 * V_632 = & V_1 -> V_633 ;
T_1 V_634 ;
F_7 ( V_1 , V_5 , V_179 , 1 ) ;
V_634 = F_8 ( V_1 , V_5 , V_635 ) ;
if ( V_634 & V_636 )
V_632 -> V_637 ( V_243 , V_638 ) ;
F_7 ( V_1 , V_5 , V_168 ,
V_639 ) ;
F_7 ( V_1 , V_5 , V_179 , 0 ) ;
}
static T_8 F_126 ( int V_625 , void * V_626 )
{
struct V_1 * V_1 = V_626 ;
struct V_8 * V_24 = V_1 -> V_24 ;
T_1 V_640 , V_641 , V_627 ;
int V_5 = 0 ;
V_640 = F_1 ( V_1 , V_157 ) ;
V_641 = V_640 ;
V_640 |= V_642 ;
F_5 ( V_1 , V_157 , V_640 ) ;
V_627 = ( F_1 ( V_1 , V_628 ) >>
V_643 ) & 0x1ff ;
while ( V_627 ) {
if ( V_627 & ( 1 << V_5 ) ) {
T_1 V_644 = F_8 ( V_1 , V_5 ,
V_168 ) ;
T_1 V_645 = F_8 ( V_1 , V_5 ,
V_169 ) ;
T_1 V_646 = F_8 ( V_1 , V_5 ,
V_170 ) ;
if ( V_645 ) {
if ( V_645 & ( V_647 |
V_648 ) )
F_127 ( L_19 ,
F_128 ( V_24 ) , V_645 ) ;
F_7 ( V_1 , V_5 ,
V_169 , V_645 ) ;
}
if ( V_646 )
F_7 ( V_1 , V_5 ,
V_170 , V_646 ) ;
if ( V_644 ) {
if ( V_644 & V_639 )
F_125 ( V_5 , V_1 ) ;
F_7 ( V_1 , V_5 ,
V_168 , V_644
& ( ~ V_649 )
& ( ~ V_620 )
& ( ~ V_624 ) ) ;
}
}
V_627 &= ~ ( 1 << V_5 ) ;
V_5 ++ ;
}
F_5 ( V_1 , V_157 , V_641 ) ;
return V_599 ;
}
static void
F_129 ( struct V_1 * V_1 , T_1 V_650 )
{
struct V_8 * V_24 = V_1 -> V_24 ;
const struct V_651 * V_652 ;
T_1 V_4 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < F_88 ( V_653 ) ; V_29 ++ ) {
V_652 = & V_653 [ V_29 ] ;
if ( V_650 & V_652 -> V_627 ) {
V_4 = F_1 ( V_1 , V_652 -> V_654 ) ;
V_4 &= V_652 -> V_655 ;
V_4 >>= V_652 -> V_656 ;
F_15 ( V_24 , V_652 -> V_657 , V_4 ) ;
}
}
}
static void F_130 ( struct V_1 * V_1 ,
T_1 V_650 )
{
struct V_8 * V_24 = V_1 -> V_24 ;
const struct V_651 * V_652 ;
T_1 V_4 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < F_88 ( V_658 ) ; V_29 ++ ) {
V_652 = & V_658 [ V_29 ] ;
if ( V_650 & V_652 -> V_627 ) {
V_4 = F_1 ( V_1 , V_652 -> V_654 ) ;
V_4 &= V_652 -> V_655 ;
V_4 >>= V_652 -> V_656 ;
F_15 ( V_24 , V_652 -> V_657 , V_650 , V_4 ) ;
F_62 ( V_1 -> V_233 , & V_1 -> V_234 ) ;
}
}
return;
}
static T_8 F_131 ( int V_625 , void * V_626 )
{
struct V_1 * V_1 = V_626 ;
T_1 V_650 , V_627 ;
V_627 = F_1 ( V_1 , V_158 ) ;
F_5 ( V_1 , V_158 , V_627 | 0xffffffff ) ;
V_650 = F_1 ( V_1 , V_659 ) ;
if ( V_650 ) {
F_129 ( V_1 , V_650 ) ;
F_130 ( V_1 , V_650 ) ;
}
F_5 ( V_1 , V_659 , V_650 ) ;
F_5 ( V_1 , V_158 , V_627 ) ;
return V_599 ;
}
static T_8 F_132 ( int V_625 , void * V_626 )
{
struct V_1 * V_1 = V_626 ;
T_1 V_650 , V_627 , V_660 ;
struct V_8 * V_24 = V_1 -> V_24 ;
V_627 = F_1 ( V_1 , V_157 ) ;
F_5 ( V_1 , V_157 , V_627 | 0xfffffffe ) ;
V_650 = F_1 ( V_1 , V_102 ) ;
if ( V_650 ) {
if ( V_650 & F_45 ( V_661 ) ) {
F_5 ( V_1 , V_102 ,
1 << V_661 ) ;
F_15 ( V_24 , L_20 ,
V_650 ) ;
F_62 ( V_1 -> V_233 , & V_1 -> V_234 ) ;
}
if ( V_650 & F_45 ( V_662 ) ) {
F_5 ( V_1 , V_102 ,
1 <<
V_662 ) ;
F_15 ( V_24 , L_21 ,
V_650 ) ;
F_62 ( V_1 -> V_233 , & V_1 -> V_234 ) ;
}
if ( V_650 & F_45 ( V_663 ) ) {
F_15 ( V_24 , L_22 ,
V_650 ) ;
F_62 ( V_1 -> V_233 , & V_1 -> V_234 ) ;
}
if ( V_650 & F_45 ( V_664 ) ) {
int V_29 ;
F_5 ( V_1 , V_102 ,
1 << V_664 ) ;
V_660 = F_1 ( V_1 ,
V_665 ) ;
for ( V_29 = 0 ; V_29 < V_666 ; V_29 ++ ) {
if ( V_660 & F_45 ( V_29 ) ) {
F_15 ( V_24 , L_23 ,
V_667 [ V_29 ] , V_650 ) ;
F_62 ( V_1 -> V_233 , & V_1 -> V_234 ) ;
}
}
}
if ( V_650 & F_45 ( V_668 ) ) {
int V_29 ;
F_5 ( V_1 , V_102 ,
1 << V_668 ) ;
V_660 = F_1 ( V_1 ,
V_665 ) ;
for ( V_29 = 0 ; V_29 < V_669 ; V_29 ++ ) {
if ( V_660 & F_45 ( V_666 + V_29 ) ) {
F_15 ( V_24 , L_23 ,
V_670 [ V_29 ] , V_650 ) ;
F_62 ( V_1 -> V_233 , & V_1 -> V_234 ) ;
}
}
}
if ( V_650 & F_45 ( V_671 ) ) {
F_5 ( V_1 , V_102 ,
1 << V_671 ) ;
F_15 ( V_24 , L_24 ,
V_650 ) ;
F_62 ( V_1 -> V_233 , & V_1 -> V_234 ) ;
}
if ( V_650 & F_45 ( V_672 ) ) {
F_5 ( V_1 , V_102 ,
1 << V_672 ) ;
F_15 ( V_24 , L_25 ,
V_650 ) ;
F_62 ( V_1 -> V_233 , & V_1 -> V_234 ) ;
}
if ( V_650 & F_45 ( V_673 ) ) {
T_1 V_101 = F_1 ( V_1 , V_106 ) ;
T_1 V_100 = V_101 & V_105 ;
struct V_12 * V_13 =
& V_1 -> V_33 [ V_100 ] ;
F_5 ( V_1 , V_106 , 0 ) ;
F_102 ( V_24 , L_26 ) ;
F_133 ( V_13 -> V_99 ) ;
}
}
F_5 ( V_1 , V_102 , V_650 ) ;
F_5 ( V_1 , V_157 , V_627 ) ;
return V_599 ;
}
static void F_134 ( unsigned long V_4 )
{
struct V_674 * V_675 = (struct V_674 * ) V_4 ;
struct V_1 * V_1 = V_675 -> V_1 ;
struct V_284 * V_285 ;
struct V_70 * V_71 ;
struct V_532 * V_533 ;
T_1 V_676 = V_675 -> V_676 , V_277 , V_100 ;
int V_36 = V_675 -> V_92 ;
struct V_38 * V_39 = & V_1 -> V_39 [ V_36 ] ;
if ( F_98 ( V_1 -> V_128 ) )
F_44 ( V_1 ) ;
V_533 = V_1 -> V_534 [ V_36 ] ;
F_17 ( & V_39 -> V_30 ) ;
V_277 = F_1 ( V_1 , V_677 +
( 0x14 * V_36 ) ) ;
while ( V_676 != V_277 ) {
struct V_532 * V_534 ;
int V_678 ;
V_534 = & V_533 [ V_676 ] ;
if ( V_534 -> V_679 ) {
T_1 V_680 = V_534 -> V_679 ;
int V_681 = F_135 ( V_680 ) ;
V_100 = ( V_534 -> V_327 & V_682 ) >>
V_683 ;
V_71 = & V_1 -> V_71 [ V_100 ] ;
while ( V_681 ) {
T_9 * V_684 = & V_71 -> V_685 [ 0 ] ;
V_681 -= 1 ;
V_678 = ( V_684 [ V_681 / 5 ]
>> ( V_681 % 5 ) * 12 ) & 0xfff ;
V_285 = & V_1 -> V_686 [ V_678 ] ;
V_285 -> V_536 = V_676 ;
V_285 -> V_535 = V_36 ;
F_97 ( V_1 , V_285 ) ;
V_680 &= ~ ( 1 << V_681 ) ;
V_681 = F_135 ( V_680 ) ;
}
} else {
V_678 = ( V_534 -> V_327 ) & V_687 ;
V_285 = & V_1 -> V_686 [ V_678 ] ;
V_285 -> V_536 = V_676 ;
V_285 -> V_535 = V_36 ;
F_97 ( V_1 , V_285 ) ;
}
if ( ++ V_676 >= V_188 )
V_676 = 0 ;
}
V_675 -> V_676 = V_676 ;
F_5 ( V_1 , V_688 + ( 0x14 * V_36 ) , V_676 ) ;
F_19 ( & V_39 -> V_30 ) ;
}
static T_8 F_136 ( int V_625 , void * V_626 )
{
struct V_674 * V_675 = V_626 ;
struct V_1 * V_1 = V_675 -> V_1 ;
int V_36 = V_675 -> V_92 ;
F_5 ( V_1 , V_152 , 1 << V_36 ) ;
F_137 ( & V_675 -> V_689 ) ;
return V_599 ;
}
static T_8 F_138 ( int V_625 , void * V_626 )
{
struct V_237 * V_238 = V_626 ;
struct V_1 * V_1 = V_238 -> V_1 ;
struct V_242 * V_243 = & V_238 -> V_243 ;
struct V_8 * V_24 = V_1 -> V_24 ;
struct V_690 * V_691 ;
struct V_692 * V_575 ;
T_1 V_641 , V_640 , V_693 , V_268 , V_600 , V_601 ;
T_8 V_598 = V_599 ;
T_6 V_612 [ V_61 ] = { 0 } ;
int V_5 , V_567 ;
V_5 = V_243 -> V_92 ;
V_691 = & V_1 -> V_691 [ V_5 ] ;
V_575 = & V_691 -> V_575 ;
V_567 = 4 * ( V_5 / 4 ) ;
V_640 = F_1 ( V_1 , V_155 + V_567 ) ;
F_5 ( V_1 , V_155 + V_567 ,
V_640 | 1 << ( ( V_5 % 4 ) * 8 ) ) ;
V_693 = F_1 ( V_1 , V_153 + V_567 ) ;
V_641 = V_693 & ( 1 << ( V_694 *
( V_5 % 4 ) ) ) ;
V_693 >>= V_694 * ( V_5 % 4 ) ;
if ( ( V_693 & V_695 ) == 0 ) {
F_15 ( V_24 , L_27 , V_5 ) ;
V_598 = V_606 ;
goto V_17;
}
if ( V_575 -> V_220 & V_696 ) {
F_15 ( V_24 , L_28 , V_5 ,
V_575 -> V_220 ) ;
F_61 ( V_1 , V_5 ) ;
F_55 ( V_1 , V_5 ) ;
V_598 = V_606 ;
goto V_17;
}
if ( F_98 ( V_5 == 8 ) ) {
T_1 V_272 = F_1 ( V_1 , V_273 ) ;
V_268 = ( V_272 & V_274 ) >>
V_275 ;
V_600 = ( V_272 & V_603 ) >>
V_604 ;
} else {
V_268 = F_1 ( V_1 , V_270 ) ;
V_268 = ( V_268 >> ( 4 * V_5 ) ) & 0xf ;
V_600 = F_1 ( V_1 , V_605 ) ;
V_600 = ( V_600 >> ( V_5 * 4 ) ) & 0xf ;
}
if ( V_268 == 0xf ) {
F_40 ( V_24 , L_29 , V_5 ) ;
V_598 = V_606 ;
goto V_17;
}
V_243 -> V_86 = V_600 ;
V_601 = F_8 ( V_1 , V_5 ,
V_609 ) ;
V_238 -> V_264 = V_601 & 0xf ;
V_238 -> V_266 = ( V_601 >> 4 ) & 0xf ;
V_243 -> V_610 = V_697 ;
V_612 [ 0 ] = 0x50 ;
V_612 [ 7 ] = V_5 ;
memcpy ( V_243 -> V_612 , V_612 , V_61 ) ;
memcpy ( V_243 -> V_602 , V_575 , sizeof( struct V_692 ) ) ;
F_119 ( V_24 , L_30 , V_5 , V_600 ) ;
V_238 -> V_613 &= ~ ( V_614 | V_615 ) ;
V_238 -> V_268 = V_268 ;
V_238 -> V_613 |= V_615 ;
V_238 -> V_616 = 1 ;
V_238 -> V_239 . V_240 = V_81 ;
V_238 -> V_617 = sizeof( struct V_692 ) ;
V_238 -> V_239 . V_618 = V_524 ;
F_62 ( V_1 -> V_233 , & V_238 -> V_619 ) ;
V_17:
F_5 ( V_1 , V_153 + V_567 , V_641 ) ;
F_5 ( V_1 , V_155 + V_567 , V_640 ) ;
return V_598 ;
}
static int F_139 ( struct V_1 * V_1 )
{
struct V_698 * V_699 = V_1 -> V_700 ;
struct V_8 * V_24 = & V_699 -> V_24 ;
int V_701 , V_214 , V_702 [ 128 ] ;
int V_29 , V_5 , V_703 , V_704 , V_705 ;
for ( V_29 = 0 ; V_29 < 128 ; V_29 ++ )
V_702 [ V_29 ] = F_140 ( V_699 , V_29 ) ;
for ( V_29 = 0 ; V_29 < V_706 ; V_29 ++ ) {
V_701 = V_702 [ V_29 + 1 ] ;
V_214 = F_141 ( V_24 , V_701 , V_707 [ V_29 ] , 0 ,
V_708 L_31 , V_1 ) ;
if ( V_214 ) {
F_40 ( V_24 , L_32
L_33 ,
V_701 , V_214 ) ;
V_214 = - V_709 ;
goto V_710;
}
}
for ( V_5 = 0 ; V_5 < V_1 -> V_109 ; V_5 ++ ) {
struct V_237 * V_238 = & V_1 -> V_238 [ V_5 ] ;
V_701 = V_702 [ V_5 + 72 ] ;
V_214 = F_141 ( V_24 , V_701 , F_138 , 0 ,
V_708 L_34 , V_238 ) ;
if ( V_214 ) {
F_40 ( V_24 , L_32
L_35 ,
V_701 , V_214 ) ;
V_214 = - V_709 ;
goto V_711;
}
}
for ( V_703 = 0 ; V_703 < V_712 ; V_703 ++ ) {
V_701 = V_702 [ V_703 + 81 ] ;
V_214 = F_141 ( V_24 , V_701 , V_713 [ V_703 ] , 0 ,
V_708 L_36 , V_1 ) ;
if ( V_214 ) {
F_40 ( V_24 ,
L_37 ,
V_701 , V_214 ) ;
V_214 = - V_709 ;
goto V_714;
}
}
for ( V_704 = 0 ; V_704 < V_1 -> V_37 ; V_704 ++ ) {
struct V_674 * V_675 = & V_1 -> V_675 [ V_704 ] ;
struct V_715 * V_716 = & V_675 -> V_689 ;
V_701 = V_702 [ V_704 + 96 ] ;
V_214 = F_141 ( V_24 , V_701 , F_136 , 0 ,
V_708 L_38 , V_675 ) ;
if ( V_214 ) {
F_40 ( V_24 ,
L_39 ,
V_701 , V_214 ) ;
V_214 = - V_709 ;
goto V_717;
}
F_142 ( V_716 , F_134 , ( unsigned long ) V_675 ) ;
}
return 0 ;
V_717:
for ( V_705 = 0 ; V_705 < V_704 ; V_705 ++ ) {
struct V_674 * V_675 = & V_1 -> V_675 [ V_705 ] ;
F_143 ( V_702 [ V_705 + 96 ] , V_675 ) ;
F_144 ( & V_675 -> V_689 ) ;
}
V_714:
for ( V_705 = 0 ; V_705 < V_703 ; V_705 ++ )
F_143 ( V_702 [ V_705 + 81 ] , V_1 ) ;
V_711:
for ( V_705 = 0 ; V_705 < V_5 ; V_705 ++ ) {
struct V_237 * V_238 = & V_1 -> V_238 [ V_705 ] ;
F_143 ( V_702 [ V_705 + 72 ] , V_238 ) ;
}
V_710:
for ( V_705 = 0 ; V_705 < V_29 ; V_705 ++ )
F_143 ( V_702 [ V_705 + 1 ] , V_1 ) ;
return V_214 ;
}
static int F_145 ( struct V_1 * V_1 )
{
int V_214 ;
memset ( V_1 -> V_25 , 0 , sizeof( V_1 -> V_25 ) ) ;
V_214 = F_54 ( V_1 ) ;
if ( V_214 )
return V_214 ;
V_214 = F_139 ( V_1 ) ;
if ( V_214 )
return V_214 ;
return 0 ;
}
static void F_146 ( struct V_1 * V_1 )
{
struct V_698 * V_699 = V_1 -> V_700 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_1 -> V_37 ; V_29 ++ )
F_5 ( V_1 , V_159 + 0x4 * V_29 , 0x1 ) ;
F_5 ( V_1 , V_155 , 0xffffffff ) ;
F_5 ( V_1 , V_156 , 0xffffffff ) ;
F_5 ( V_1 , V_157 , 0xffffffff ) ;
F_5 ( V_1 , V_158 , 0xffffffff ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_109 ; V_29 ++ ) {
F_7 ( V_1 , V_29 , V_172 , 0xffffffff ) ;
F_7 ( V_1 , V_29 , V_173 , 0xffffffff ) ;
}
for ( V_29 = 0 ; V_29 < 128 ; V_29 ++ )
F_147 ( F_140 ( V_699 , V_29 ) ) ;
}
static T_1 F_148 ( struct V_1 * V_1 )
{
return F_1 ( V_1 , V_212 ) ;
}
static int F_149 ( struct V_1 * V_1 )
{
struct V_8 * V_24 = V_1 -> V_24 ;
int V_214 , V_718 ;
F_146 ( V_1 ) ;
F_5 ( V_1 , V_110 , 0x0 ) ;
F_150 ( V_1 ) ;
F_151 ( 10 ) ;
F_5 ( V_1 , V_222 + V_231 , 0x1 ) ;
V_718 = 0 ;
while ( 1 ) {
T_1 V_220 = F_3 ( V_1 ,
V_222 + V_223 ) ;
if ( V_220 == 0x3 )
break;
F_33 ( 10 ) ;
if ( V_718 ++ > 10 ) {
F_119 ( V_24 , L_40 ) ;
return - 1 ;
}
}
F_152 ( V_1 ) ;
V_214 = F_54 ( V_1 ) ;
if ( V_214 )
return V_214 ;
F_43 ( V_1 ) ;
return 0 ;
}
static int F_153 ( struct V_698 * V_699 )
{
int V_719 = F_140 ( V_699 , 0 ) ;
if ( V_719 < 0 ) {
if ( V_719 != - V_720 )
F_40 ( & V_699 -> V_24 , L_41 ) ;
return V_719 ;
}
return F_154 ( V_699 , & V_721 ) ;
}
static int F_155 ( struct V_698 * V_699 )
{
struct V_631 * V_633 = F_156 ( V_699 ) ;
struct V_1 * V_1 = V_633 -> V_28 ;
int V_29 ;
if ( F_120 ( & V_1 -> V_209 ) )
F_103 ( & V_1 -> V_209 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_37 ; V_29 ++ ) {
struct V_674 * V_675 = & V_1 -> V_675 [ V_29 ] ;
F_144 ( & V_675 -> V_689 ) ;
}
return F_157 ( V_699 ) ;
}
