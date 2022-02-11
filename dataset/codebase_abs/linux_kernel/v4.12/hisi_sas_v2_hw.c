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
struct V_8 * V_24 = & V_1 -> V_25 -> V_24 ;
void * V_10 = V_1 -> V_26 ;
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
struct V_1 * V_1 = V_8 -> V_27 -> V_28 -> V_29 ;
struct V_12 * V_13 = NULL ;
int V_30 , V_9 = F_10 ( V_8 ) ;
int V_15 = - 1 ;
F_17 ( & V_1 -> V_31 ) ;
if ( V_9 )
if ( ! F_13 ( V_1 , & V_15 ) )
goto V_32;
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ ) {
if ( V_9 && ( V_30 & 1 ) )
continue;
if ( V_1 -> V_34 [ V_30 ] . V_35 == V_36 ) {
V_1 -> V_34 [ V_30 ] . V_37 = V_30 ;
V_13 = & V_1 -> V_34 [ V_30 ] ;
V_13 -> V_38 = V_39 ;
V_13 -> V_35 = V_8 -> V_35 ;
V_13 -> V_1 = V_1 ;
V_13 -> V_40 = V_8 ;
V_13 -> V_15 = V_15 ;
F_18 ( & V_1 -> V_34 [ V_30 ] . V_41 ) ;
break;
}
}
V_32:
F_19 ( & V_1 -> V_31 ) ;
return V_13 ;
}
static void F_20 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_42 = F_8 ( V_1 , V_5 , V_43 ) ;
V_42 &= ~ V_44 ;
V_42 |= 1 << V_45 ;
F_7 ( V_1 , V_5 , V_43 , V_42 ) ;
}
static void F_21 ( struct V_1 * V_1 , int V_5 )
{
struct V_46 V_47 ;
T_1 * V_48 ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_35 = V_49 ;
V_47 . V_50 = 0 ;
V_47 . V_51 = 1 ;
V_47 . V_52 = V_53 ;
V_47 . V_54 = V_55 ;
memcpy ( & V_47 . V_56 [ 0 ] , V_1 -> V_57 , V_58 ) ;
memcpy ( & V_47 . V_57 [ 0 ] , V_1 -> V_57 , V_58 ) ;
V_47 . V_59 = V_5 ;
V_48 = ( T_1 * ) ( & V_47 ) ;
F_7 ( V_1 , V_5 , V_60 ,
F_22 ( V_48 [ 0 ] ) ) ;
F_7 ( V_1 , V_5 , V_61 ,
F_22 ( V_48 [ 1 ] ) ) ;
F_7 ( V_1 , V_5 , V_62 ,
F_22 ( V_48 [ 2 ] ) ) ;
F_7 ( V_1 , V_5 , V_63 ,
F_22 ( V_48 [ 3 ] ) ) ;
F_7 ( V_1 , V_5 , V_64 ,
F_22 ( V_48 [ 4 ] ) ) ;
F_7 ( V_1 , V_5 , V_65 ,
F_22 ( V_48 [ 5 ] ) ) ;
}
static void F_23 ( struct V_1 * V_1 ,
struct V_12 * V_13 )
{
struct V_7 * V_8 = V_13 -> V_40 ;
struct V_8 * V_24 = & V_1 -> V_25 -> V_24 ;
T_3 V_66 , V_37 = V_13 -> V_37 ;
struct V_67 * V_68 = & V_1 -> V_68 [ V_37 ] ;
struct V_7 * V_69 = V_8 -> V_70 ;
struct V_71 * V_72 = V_8 -> V_27 ;
struct V_73 * V_27 = F_24 ( V_72 ) ;
memset ( V_68 , 0 , sizeof( * V_68 ) ) ;
V_66 = 0 ;
switch ( V_13 -> V_35 ) {
case V_49 :
case V_74 :
case V_75 :
V_66 = V_76 << V_77 ;
break;
case V_78 :
case V_79 :
if ( V_69 && F_25 ( V_69 -> V_35 ) )
V_66 = V_80 << V_77 ;
else
V_66 = V_81 << V_77 ;
break;
default:
F_15 ( V_24 , L_2 ,
V_13 -> V_35 ) ;
}
V_66 |= ( ( 1 << V_82 ) |
( V_8 -> V_83 << V_84 ) |
( 1 << V_85 ) |
( V_86 << V_87 ) |
( 1 << V_88 ) |
( V_27 -> V_89 << V_90 ) ) ;
V_68 -> V_66 = F_26 ( V_66 ) ;
memcpy ( & V_68 -> V_57 , V_8 -> V_57 , V_58 ) ;
V_68 -> V_57 = F_27 ( V_68 -> V_57 ) ;
if ( ! F_10 ( V_8 ) )
V_68 -> V_91 = F_26 ( ( 5000ULL << V_92 ) |
( 0x1ULL << V_93 ) |
( 0x32ULL << V_94 ) |
( 0x1ULL << V_95 ) ) ;
}
static void F_28 ( struct V_1 * V_1 ,
struct V_12 * V_13 )
{
T_3 V_96 = V_13 -> V_37 ;
struct V_8 * V_24 = & V_1 -> V_25 -> V_24 ;
struct V_67 * V_68 = & V_1 -> V_68 [ V_96 ] ;
T_1 V_97 = F_1 ( V_1 , V_98 ) ;
int V_30 ;
if ( F_10 ( V_13 -> V_40 ) )
F_29 ( V_13 -> V_15 , V_1 -> V_26 ) ;
if ( V_99 & V_97 )
F_5 ( V_1 , V_98 ,
V_99 ) ;
for ( V_30 = 0 ; V_30 < 2 ; V_30 ++ ) {
V_97 = F_1 ( V_1 , V_100 ) ;
V_97 |= V_101 | ( V_96 & V_102 ) ;
F_5 ( V_1 , V_100 , V_97 ) ;
F_30 ( 10 ) ;
V_97 = F_1 ( V_1 , V_98 ) ;
if ( V_99 & V_97 ) {
F_31 ( V_24 , L_3 ) ;
memset ( V_68 , 0 , sizeof( struct V_67 ) ) ;
F_5 ( V_1 , V_98 ,
V_99 ) ;
F_5 ( V_1 , V_100 , 0 ) ;
F_31 ( V_24 , L_4 ) ;
break;
}
}
}
static int F_32 ( struct V_1 * V_1 )
{
int V_30 , V_103 ;
T_1 V_4 ;
unsigned long V_104 ;
struct V_8 * V_24 = & V_1 -> V_25 -> V_24 ;
if ( V_1 -> V_105 == 9 )
V_103 = 0x1fffff ;
else
V_103 = 0x7ffff ;
F_5 ( V_1 , V_106 , 0 ) ;
for ( V_30 = 0 ; V_30 < V_1 -> V_105 ; V_30 ++ ) {
T_1 V_107 = F_8 ( V_1 , V_30 , V_43 ) ;
V_107 &= ~ V_108 ;
F_7 ( V_1 , V_30 , V_43 , V_107 ) ;
}
F_30 ( 50 ) ;
for ( V_30 = 0 ; V_30 < V_1 -> V_105 ; V_30 ++ ) {
T_1 V_109 , V_110 ;
V_104 = V_111 + F_33 ( 1000 ) ;
while ( 1 ) {
V_109 = F_8 ( V_1 , V_30 ,
V_112 ) ;
V_110 = F_8 ( V_1 , V_30 ,
V_113 ) ;
if ( ! ( V_109 & V_114 ) &&
! ( V_110 & V_115 ) )
break;
F_34 ( 20 ) ;
if ( F_35 ( V_111 , V_104 ) )
return - V_116 ;
}
}
V_104 = V_111 + F_33 ( 1000 ) ;
while ( 1 ) {
T_1 V_117 =
F_1 ( V_1 , V_118 ) ;
if ( V_117 == 0 )
break;
F_34 ( 20 ) ;
if ( F_35 ( V_111 , V_104 ) )
return - V_116 ;
}
if ( F_36 ( V_24 ) ) {
T_4 V_119 ;
V_119 = F_37 ( F_36 ( V_24 ) , L_5 , NULL , NULL ) ;
if ( F_38 ( V_119 ) ) {
F_39 ( V_24 , L_6 ) ;
return - V_116 ;
}
} else if ( V_1 -> V_120 ) {
F_40 ( V_1 -> V_120 , V_1 -> V_121 ,
V_103 ) ;
F_40 ( V_1 -> V_120 , V_1 -> V_122 + 4 ,
V_103 ) ;
F_34 ( 1 ) ;
F_41 ( V_1 -> V_120 , V_1 -> V_123 , & V_4 ) ;
if ( V_103 != ( V_4 & V_103 ) ) {
F_39 ( V_24 , L_7 ) ;
return - V_116 ;
}
F_40 ( V_1 -> V_120 , V_1 -> V_121 + 4 ,
V_103 ) ;
F_40 ( V_1 -> V_120 , V_1 -> V_122 ,
V_103 ) ;
F_34 ( 1 ) ;
F_41 ( V_1 -> V_120 , V_1 -> V_123 ,
& V_4 ) ;
if ( V_4 & V_103 ) {
F_39 ( V_24 , L_8 ) ;
return - V_116 ;
}
} else
F_15 ( V_24 , L_9 ) ;
return 0 ;
}
static void F_42 ( struct V_1 * V_1 )
{
T_1 V_42 ;
int V_5 ;
V_1 -> V_124 = ( 1 << V_1 -> V_105 ) - 1 ;
for ( V_5 = 0 ; V_5 < V_1 -> V_105 ; V_5 ++ ) {
V_42 = F_8 ( V_1 , V_5 , V_125 ) ;
if ( ! ( V_42 & V_126 ) )
continue;
V_42 &= ~ V_126 ;
F_7 ( V_1 , V_5 , V_125 , V_42 ) ;
}
}
static void F_43 ( struct V_1 * V_1 )
{
int V_5 ;
T_1 V_127 ;
for ( V_5 = 0 ; V_5 < V_1 -> V_105 ; V_5 ++ ) {
if ( ! ( V_1 -> V_124 & F_44 ( V_5 ) ) )
continue;
V_127 = F_8 ( V_1 , V_5 ,
V_128 ) ;
if ( V_127 & V_129 ) {
T_1 V_42 = F_8 ( V_1 ,
V_5 , V_125 ) ;
V_42 |= V_126 ;
F_7 ( V_1 , V_5 ,
V_125 , V_42 ) ;
F_29 ( V_5 , & V_1 -> V_124 ) ;
}
}
}
static void F_45 ( struct V_1 * V_1 )
{
struct V_8 * V_24 = & V_1 -> V_25 -> V_24 ;
int V_30 ;
if ( F_46 ( V_24 , L_10 ) ) {
F_5 ( V_1 , V_130 , 0x2020 ) ;
F_5 ( V_1 , V_131 ,
0x2020 ) ;
}
F_5 ( V_1 , V_106 ,
( T_1 ) ( ( 1ULL << V_1 -> V_132 ) - 1 ) ) ;
F_5 ( V_1 , V_133 , 0xc0000000 ) ;
F_5 ( V_1 , V_134 , 0x10000 ) ;
F_5 ( V_1 , V_135 , 0x0 ) ;
F_5 ( V_1 , V_136 , 0x7FF ) ;
F_5 ( V_1 , V_137 , 0x1 ) ;
F_5 ( V_1 , V_138 , 0x1F4 ) ;
F_5 ( V_1 , V_139 , 0x32 ) ;
F_5 ( V_1 , V_140 , 0x1 ) ;
F_5 ( V_1 , V_141 , 0x1 ) ;
F_5 ( V_1 , V_142 , 0x1 ) ;
F_5 ( V_1 , V_143 , 0x1 ) ;
F_5 ( V_1 , V_144 , 0xc ) ;
F_5 ( V_1 , V_145 , 0x60 ) ;
F_5 ( V_1 , V_146 , 0x3 ) ;
F_5 ( V_1 , V_147 , 0x1 ) ;
F_5 ( V_1 , V_148 , 0x1 ) ;
F_5 ( V_1 , V_149 , 0x0 ) ;
F_5 ( V_1 , V_150 , 0xffffffff ) ;
F_5 ( V_1 , V_151 , 0xffffffff ) ;
F_5 ( V_1 , V_98 , 0xffffffff ) ;
F_5 ( V_1 , V_152 , 0x7efefefe ) ;
F_5 ( V_1 , V_153 , 0x7efefefe ) ;
F_5 ( V_1 , V_154 , 0x7ffffffe ) ;
F_5 ( V_1 , V_155 , 0xfff00c30 ) ;
for ( V_30 = 0 ; V_30 < V_1 -> V_132 ; V_30 ++ )
F_5 ( V_1 , V_156 + 0x4 * V_30 , 0 ) ;
F_5 ( V_1 , V_157 , 1 ) ;
F_5 ( V_1 , V_158 , 1 ) ;
for ( V_30 = 0 ; V_30 < V_1 -> V_105 ; V_30 ++ ) {
F_7 ( V_1 , V_30 , V_159 , 0x855 ) ;
F_7 ( V_1 , V_30 , V_160 , 0x30b9908 ) ;
F_7 ( V_1 , V_30 , V_161 , 0x7d7d7d7d ) ;
F_7 ( V_1 , V_30 , V_162 , 0x0 ) ;
F_7 ( V_1 , V_30 , V_163 , 0x2 ) ;
F_7 ( V_1 , V_30 , V_164 , 0x8 ) ;
F_7 ( V_1 , V_30 , V_165 , 0xffffffff ) ;
F_7 ( V_1 , V_30 , V_166 , 0xffffffff ) ;
F_7 ( V_1 , V_30 , V_167 , 0xfff87fff ) ;
F_7 ( V_1 , V_30 , V_168 , 0x1000 ) ;
F_7 ( V_1 , V_30 , V_169 , 0xffffffff ) ;
F_7 ( V_1 , V_30 , V_170 , 0x8ffffbff ) ;
F_7 ( V_1 , V_30 , V_171 , 0x13f801fc ) ;
F_7 ( V_1 , V_30 , V_172 , 0x0 ) ;
F_7 ( V_1 , V_30 , V_173 , 0x0 ) ;
F_7 ( V_1 , V_30 , V_174 , 0x0 ) ;
F_7 ( V_1 , V_30 , V_175 , 0x0 ) ;
F_7 ( V_1 , V_30 , V_176 , 0x0 ) ;
F_7 ( V_1 , V_30 , V_177 , 0x0 ) ;
F_7 ( V_1 , V_30 , V_178 , 0x0 ) ;
if ( V_1 -> V_179 == 66 )
F_7 ( V_1 , V_30 , V_180 , 0x199B694 ) ;
}
for ( V_30 = 0 ; V_30 < V_1 -> V_132 ; V_30 ++ ) {
F_5 ( V_1 ,
V_181 + ( V_30 * 0x14 ) ,
F_47 ( V_1 -> V_182 [ V_30 ] ) ) ;
F_5 ( V_1 , V_183 + ( V_30 * 0x14 ) ,
F_48 ( V_1 -> V_182 [ V_30 ] ) ) ;
F_5 ( V_1 , V_184 + ( V_30 * 0x14 ) ,
V_185 ) ;
F_5 ( V_1 , V_186 + ( V_30 * 0x14 ) ,
F_47 ( V_1 -> V_187 [ V_30 ] ) ) ;
F_5 ( V_1 , V_188 + ( V_30 * 0x14 ) ,
F_48 ( V_1 -> V_187 [ V_30 ] ) ) ;
F_5 ( V_1 , V_189 + ( V_30 * 0x14 ) ,
V_185 ) ;
}
F_5 ( V_1 , V_190 ,
F_48 ( V_1 -> V_191 ) ) ;
F_5 ( V_1 , V_192 ,
F_47 ( V_1 -> V_191 ) ) ;
F_5 ( V_1 , V_193 ,
F_48 ( V_1 -> V_194 ) ) ;
F_5 ( V_1 , V_195 ,
F_47 ( V_1 -> V_194 ) ) ;
F_5 ( V_1 , V_196 ,
F_48 ( V_1 -> V_197 ) ) ;
F_5 ( V_1 , V_198 ,
F_47 ( V_1 -> V_197 ) ) ;
F_5 ( V_1 , V_199 ,
F_48 ( V_1 -> V_200 ) ) ;
F_5 ( V_1 , V_201 ,
F_47 ( V_1 -> V_200 ) ) ;
F_5 ( V_1 , V_202 ,
F_48 ( V_1 -> V_203 ) ) ;
F_5 ( V_1 , V_204 ,
F_47 ( V_1 -> V_203 ) ) ;
}
static void F_49 ( unsigned long V_205 )
{
struct V_1 * V_1 = (struct V_1 * ) V_205 ;
int V_30 , V_97 ;
for ( V_30 = 0 ; V_30 < V_1 -> V_105 ; V_30 ++ ) {
if ( V_1 -> V_124 & F_44 ( V_30 ) )
continue;
V_97 = F_8 ( V_1 , V_30 , V_125 ) ;
if ( ! ( V_97 & F_44 ( 0 ) ) ) {
F_7 ( V_1 , V_30 ,
V_125 , 0x7 ) ;
break;
}
}
V_1 -> V_206 . V_207 = V_208 ;
F_50 ( & V_1 -> V_206 , V_111 + F_33 ( 900 ) ) ;
}
static void V_208 ( unsigned long V_205 )
{
struct V_1 * V_1 = (struct V_1 * ) V_205 ;
int V_30 , V_97 ;
V_97 = F_1 ( V_1 , V_209 ) ;
for ( V_30 = 0 ; V_30 < V_1 -> V_105 && V_97 ; V_30 ++ ) {
if ( V_1 -> V_124 & F_44 ( V_30 ) )
continue;
if ( V_97 & F_44 ( V_30 ) ) {
F_7 ( V_1 , V_30 ,
V_125 , 0x6 ) ;
break;
}
}
V_1 -> V_206 . V_207 = F_49 ;
F_50 ( & V_1 -> V_206 , V_111 + F_33 ( 100 ) ) ;
}
static void F_51 ( struct V_1 * V_1 )
{
V_1 -> V_206 . V_205 = ( unsigned long ) V_1 ;
V_1 -> V_206 . V_207 = V_208 ;
V_1 -> V_206 . V_210 = V_111 + F_33 ( 1000 ) ;
F_52 ( & V_1 -> V_206 ) ;
}
static int F_53 ( struct V_1 * V_1 )
{
struct V_8 * V_24 = & V_1 -> V_25 -> V_24 ;
int V_211 ;
V_211 = F_32 ( V_1 ) ;
if ( V_211 ) {
F_39 ( V_24 , L_11 , V_211 ) ;
return V_211 ;
}
F_34 ( 100 ) ;
F_45 ( V_1 ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_42 = F_8 ( V_1 , V_5 , V_43 ) ;
V_42 |= V_212 ;
F_7 ( V_1 , V_5 , V_43 , V_42 ) ;
}
static bool F_55 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_213 ;
V_213 = F_1 ( V_1 , V_214 ) ;
if ( V_213 & ( 1 << V_5 ) )
return true ;
return false ;
}
static bool F_56 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_215 ;
V_215 = F_8 ( V_1 , V_5 , V_128 ) ;
if ( V_215 & F_44 ( 16 ) )
return false ;
return true ;
}
static bool F_57 ( struct V_1 * V_1 , int V_5 )
{
int V_30 , V_216 = 1000 ;
struct V_8 * V_24 = & V_1 -> V_25 -> V_24 ;
T_1 V_217 , V_117 , V_215 , V_218 ;
for ( V_30 = 0 ; V_30 < V_216 ; V_30 ++ ) {
V_217 = F_3 ( V_1 ,
V_219 + V_220 ) ;
V_117 = F_1 ( V_1 , V_118 ) ;
V_215 = F_8 ( V_1 , V_5 , V_128 ) ;
V_218 = F_8 ( V_1 ,
V_5 , V_221 ) ;
if ( ( V_217 == 0x3 ) && ( V_117 == 0x0 ) &&
( V_215 & F_44 ( 20 ) ) && ( V_218 & F_44 ( 10 ) ) )
return true ;
F_30 ( 10 ) ;
}
F_39 ( V_24 , L_12 ,
V_5 , V_217 , V_117 ,
V_215 , V_218 ) ;
return false ;
}
static bool F_58 ( struct V_1 * V_1 , int V_5 )
{
int V_30 , V_216 = 1000 ;
struct V_8 * V_24 = & V_1 -> V_25 -> V_24 ;
T_1 V_217 , V_222 ;
for ( V_30 = 0 ; V_30 < V_216 ; V_30 ++ ) {
V_217 = F_8 ( V_1 , V_5 , V_223 ) ;
V_217 = ( V_217 & 0x3fc0 ) >> 6 ;
if ( V_217 != 0x1 )
return true ;
V_222 = F_8 ( V_1 , V_5 , V_224 ) ;
if ( ( V_222 & 0x1ff ) == 0x2 )
return true ;
F_30 ( 10 ) ;
}
F_39 ( V_24 , L_13 ,
V_5 , V_217 , V_222 ) ;
return false ;
}
static bool F_59 ( struct V_1 * V_1 , int V_5 )
{
if ( F_56 ( V_1 , V_5 ) )
return true ;
if ( ! F_57 ( V_1 , V_5 ) )
return false ;
if ( ! F_58 ( V_1 , V_5 ) )
return false ;
return true ;
}
static void F_60 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_42 , V_225 , V_226 , V_227 ;
struct V_8 * V_24 = & V_1 -> V_25 -> V_24 ;
V_225 = F_1 ( V_1 , V_219 +
V_228 ) ;
V_225 |= 0x1 ;
F_5 ( V_1 , V_219 +
V_228 , V_225 ) ;
if ( F_55 ( V_1 , V_5 ) ) {
if ( F_59 ( V_1 , V_5 ) )
goto V_229;
F_61 ( V_1 -> V_230 , & V_1 -> V_231 ) ;
return;
}
V_226 = F_8 ( V_1 , V_5 , V_232 ) ;
V_226 = ( V_226 & 0x1fc0 ) >> 6 ;
if ( V_226 != 0x4 )
goto V_229;
if ( ! F_56 ( V_1 , V_5 ) ) {
F_15 ( V_24 , L_14 ,
V_5 ) ;
V_227 = F_8 ( V_1 , V_5 ,
V_163 ) ;
V_227 |= V_233 ;
F_7 ( V_1 , V_5 , V_163 ,
V_227 ) ;
}
V_229:
V_42 = F_8 ( V_1 , V_5 , V_43 ) ;
V_42 &= ~ V_212 ;
F_7 ( V_1 , V_5 , V_43 , V_42 ) ;
V_225 &= ~ 0x1 ;
F_5 ( V_1 , V_219 +
V_228 , V_225 ) ;
}
static void F_62 ( struct V_1 * V_1 , int V_5 )
{
F_21 ( V_1 , V_5 ) ;
F_20 ( V_1 , V_5 ) ;
F_54 ( V_1 , V_5 ) ;
}
static void F_63 ( struct V_1 * V_1 , int V_5 )
{
F_60 ( V_1 , V_5 ) ;
}
static void F_64 ( struct V_1 * V_1 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_1 -> V_105 ; V_30 ++ )
F_63 ( V_1 , V_30 ) ;
}
static void F_65 ( struct V_1 * V_1 , int V_5 )
{
struct V_234 * V_235 = & V_1 -> V_235 [ V_5 ] ;
T_1 V_227 ;
F_63 ( V_1 , V_5 ) ;
if ( V_235 -> V_236 . V_237 == V_49 ) {
V_227 = F_8 ( V_1 , V_5 , V_163 ) ;
F_7 ( V_1 , V_5 , V_163 ,
V_227 | V_238 ) ;
}
F_34 ( 100 ) ;
F_62 ( V_1 , V_5 ) ;
}
static void F_66 ( struct V_1 * V_1 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_1 -> V_105 ; V_30 ++ )
F_62 ( V_1 , V_30 ) ;
}
static void F_67 ( struct V_1 * V_1 )
{
F_66 ( V_1 ) ;
}
static void F_68 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_239 ;
V_239 = F_8 ( V_1 , V_5 , V_162 ) ;
V_239 |= V_240 ;
F_7 ( V_1 , V_5 , V_162 , V_239 ) ;
F_34 ( 1 ) ;
V_239 = F_8 ( V_1 , V_5 , V_162 ) ;
V_239 &= ~ V_240 ;
F_7 ( V_1 , V_5 , V_162 , V_239 ) ;
}
static enum V_241 F_69 ( void )
{
return V_242 ;
}
static void F_70 ( struct V_1 * V_1 , int V_5 ,
struct V_243 * V_244 )
{
T_1 V_245 =
F_8 ( V_1 , V_5 , V_159 ) ;
struct V_234 * V_235 = & V_1 -> V_235 [ V_5 ] ;
struct V_246 * V_247 = & V_235 -> V_247 ;
int V_30 ;
enum V_241 V_248 , V_249 ;
T_1 V_250 = 0 ;
if ( V_244 -> V_251 == V_252 ) {
V_249 = V_247 -> V_235 -> V_251 ;
V_248 = V_244 -> V_253 ;
} else if ( V_244 -> V_253 == V_252 ) {
V_249 = V_244 -> V_251 ;
V_248 = V_247 -> V_235 -> V_253 ;
} else
return;
V_247 -> V_235 -> V_251 = V_249 ;
V_247 -> V_235 -> V_253 = V_248 ;
V_248 -= V_254 ;
V_249 -= V_254 ;
for ( V_30 = 0 ; V_30 <= V_249 ; V_30 ++ )
V_250 |= 1 << ( V_30 * 2 ) ;
V_245 &= ~ 0xff ;
V_245 |= V_250 ;
F_7 ( V_1 , V_5 , V_159 ,
V_245 ) ;
F_65 ( V_1 , V_5 ) ;
}
static int F_71 ( struct V_1 * V_1 , int V_255 )
{
int V_30 , V_10 = 0 ;
T_1 V_256 = F_1 ( V_1 , V_257 ) ;
T_1 V_258 = F_1 ( V_1 , V_209 ) ;
for ( V_30 = 0 ; V_30 < ( V_1 -> V_105 < 9 ? V_1 -> V_105 : 8 ) ; V_30 ++ )
if ( V_258 & 1 << V_30 )
if ( ( ( V_256 >> ( V_30 * 4 ) ) & 0xf ) == V_255 )
V_10 |= 1 << V_30 ;
if ( V_1 -> V_105 == 9 ) {
T_1 V_259 = F_1 ( V_1 , V_260 ) ;
if ( V_258 & 1 << 8 )
if ( ( ( V_259 & V_261 ) >>
V_262 ) == V_255 )
V_10 |= 1 << 9 ;
}
return V_10 ;
}
static int F_72 ( struct V_1 * V_1 , T_1 V_96 ,
int * V_263 , int * V_119 )
{
struct V_8 * V_24 = & V_1 -> V_25 -> V_24 ;
struct V_264 * V_265 ;
T_1 V_244 , V_266 ;
int V_267 = V_96 % V_1 -> V_132 ;
V_265 = & V_1 -> V_265 [ V_267 ] ;
V_266 = V_265 -> V_268 ;
V_244 = F_3 ( V_1 ,
V_269 + ( V_267 * 0x14 ) ) ;
if ( V_244 == ( V_266 + 1 ) % V_185 ) {
F_15 ( V_24 , L_15 ,
V_267 , V_244 , V_266 ) ;
return - V_270 ;
}
* V_263 = V_267 ;
* V_119 = V_266 ;
return 0 ;
}
static void F_73 ( struct V_1 * V_1 )
{
int V_271 = V_1 -> V_272 -> V_271 ;
int V_273 = V_1 -> V_272 -> V_273 ;
struct V_264 * V_265 = & V_1 -> V_265 [ V_271 ] ;
V_265 -> V_268 = ++ V_273 % V_185 ;
F_5 ( V_1 , V_274 + ( V_271 * 0x14 ) ,
V_265 -> V_268 ) ;
}
static int F_74 ( struct V_1 * V_1 ,
struct V_275 * V_276 ,
struct V_277 * V_278 ,
struct V_279 * V_280 ,
int V_281 )
{
struct V_8 * V_24 = & V_1 -> V_25 -> V_24 ;
struct V_279 * V_282 ;
int V_30 ;
if ( V_281 > V_283 ) {
F_39 ( V_24 , L_16 ,
V_281 ) ;
return - V_20 ;
}
V_276 -> V_284 = F_75 ( V_1 -> V_285 , V_286 ,
& V_276 -> V_287 ) ;
if ( ! V_276 -> V_284 )
return - V_288 ;
F_76 (scatter, sg, n_elem, i) {
struct V_289 * V_290 = & V_276 -> V_284 -> V_291 [ V_30 ] ;
V_290 -> V_292 = F_26 ( F_77 ( V_282 ) ) ;
V_290 -> V_293 = V_290 -> V_294 = 0 ;
V_290 -> V_295 = F_78 ( F_79 ( V_282 ) ) ;
V_290 -> V_296 = 0 ;
}
V_278 -> V_297 = F_26 ( V_276 -> V_287 ) ;
V_278 -> V_298 = F_78 ( V_281 << V_299 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_1 ,
struct V_275 * V_276 )
{
struct V_300 * V_301 = V_276 -> V_301 ;
struct V_277 * V_278 = V_276 -> V_302 ;
struct V_7 * V_8 = V_301 -> V_24 ;
struct V_8 * V_24 = & V_1 -> V_25 -> V_24 ;
struct V_73 * V_27 = V_276 -> V_27 ;
struct V_279 * V_303 , * V_304 ;
struct V_12 * V_13 = V_8 -> V_14 ;
T_5 V_305 ;
unsigned int V_306 , V_307 ;
int V_308 , V_211 ;
V_303 = & V_301 -> V_309 . V_310 ;
V_308 = F_81 ( V_24 , V_303 , 1 , V_311 ) ;
if ( ! V_308 )
return - V_288 ;
V_306 = F_79 ( V_303 ) ;
V_305 = F_77 ( V_303 ) ;
V_304 = & V_301 -> V_309 . V_312 ;
V_308 = F_81 ( V_24 , V_304 , 1 , V_313 ) ;
if ( ! V_308 ) {
V_211 = - V_288 ;
goto V_314;
}
V_307 = F_79 ( V_304 ) ;
if ( ( V_306 & 0x3 ) || ( V_307 & 0x3 ) ) {
V_211 = - V_20 ;
goto V_315;
}
V_278 -> V_316 = F_78 ( ( V_27 -> V_89 << V_317 ) |
( 1 << V_318 ) |
( 2 << V_319 ) ) ;
V_278 -> V_320 = F_78 ( ( V_13 -> V_37 << V_321 ) |
( 1 << V_322 ) |
( V_323 << V_324 ) ) ;
V_278 -> V_325 = F_78 ( ( ( ( V_306 - 4 ) / 4 ) << V_326 ) |
( V_327 / 4 <<
V_328 ) ) ;
V_278 -> V_329 = F_78 ( V_276 -> V_22 << V_330 ) ;
V_278 -> V_331 = F_26 ( V_305 ) ;
V_278 -> V_332 = F_26 ( V_276 -> V_333 ) ;
return 0 ;
V_315:
F_82 ( V_24 , & V_276 -> V_301 -> V_309 . V_312 , 1 ,
V_313 ) ;
V_314:
F_82 ( V_24 , & V_276 -> V_301 -> V_309 . V_310 , 1 ,
V_311 ) ;
return V_211 ;
}
static int F_83 ( struct V_1 * V_1 ,
struct V_275 * V_276 , int V_334 ,
struct V_335 * V_336 )
{
struct V_300 * V_301 = V_276 -> V_301 ;
struct V_277 * V_278 = V_276 -> V_302 ;
struct V_7 * V_8 = V_301 -> V_24 ;
struct V_12 * V_13 = V_8 -> V_14 ;
struct V_73 * V_27 = V_276 -> V_27 ;
struct V_337 * V_338 = & V_301 -> V_338 ;
struct V_339 * V_339 = V_338 -> V_340 ;
int V_341 = 0 , V_211 , V_342 = V_334 ;
T_6 * V_343 ;
T_1 V_320 = 0 , V_325 = 0 ;
V_278 -> V_316 = F_78 ( ( 1 << V_344 ) |
( 2 << V_345 ) |
( V_27 -> V_89 << V_317 ) |
( V_342 << V_318 ) |
( 1 << V_319 ) ) ;
V_320 = 1 << V_346 ;
if ( V_334 ) {
V_320 |= 2 << V_322 ;
V_320 |= V_323 << V_324 ;
} else {
V_320 |= 1 << V_322 ;
switch ( V_339 -> V_347 ) {
case V_311 :
V_341 = 1 ;
V_320 |= V_348 << V_324 ;
break;
case V_313 :
V_341 = 1 ;
V_320 |= V_349 << V_324 ;
break;
default:
V_320 &= ~ V_350 ;
}
}
V_320 |= V_13 -> V_37 << V_321 ;
V_278 -> V_320 = F_78 ( V_320 ) ;
V_325 = ( ( ( sizeof( struct V_351 ) + sizeof( struct V_352 )
+ 3 ) / 4 ) << V_326 ) |
( ( V_353 / 4 ) << V_328 ) |
( 2 << V_354 ) ;
V_278 -> V_325 = F_78 ( V_325 ) ;
V_278 -> V_329 = F_78 ( V_276 -> V_22 ) ;
if ( V_341 ) {
V_211 = F_74 ( V_1 , V_276 , V_278 , V_301 -> V_280 ,
V_276 -> V_281 ) ;
if ( V_211 )
return V_211 ;
}
V_278 -> V_355 = F_78 ( V_301 -> V_356 ) ;
V_278 -> V_331 = F_26 ( V_276 -> V_357 ) ;
V_278 -> V_332 = F_26 ( V_276 -> V_333 ) ;
V_343 = V_276 -> V_358 + sizeof( struct V_352 ) ;
memcpy ( V_343 , & V_301 -> V_338 . V_359 , 8 ) ;
if ( ! V_334 ) {
V_343 [ 9 ] = V_301 -> V_338 . V_360 |
( V_301 -> V_338 . V_361 << 3 ) ;
memcpy ( V_343 + 12 , V_301 -> V_338 . V_340 -> V_362 ,
V_301 -> V_338 . V_340 -> V_363 ) ;
} else {
V_343 [ 10 ] = V_336 -> V_336 ;
switch ( V_336 -> V_336 ) {
case V_364 :
case V_365 :
V_343 [ 12 ] =
( V_336 -> V_366 >> 8 ) & 0xff ;
V_343 [ 13 ] =
V_336 -> V_366 & 0xff ;
break;
default:
break;
}
}
return 0 ;
}
static void F_84 ( struct V_1 * V_1 , struct V_300 * V_301 ,
struct V_275 * V_276 )
{
struct V_367 * V_368 = & V_301 -> V_369 ;
struct V_370 * V_371 = (struct V_370 * ) V_368 -> V_372 ;
struct V_373 * V_374 = V_276 -> V_375 +
sizeof( struct V_376 ) ;
V_371 -> V_377 = sizeof( struct V_373 ) ;
memcpy ( & V_371 -> V_378 [ 0 ] , V_374 , sizeof( struct V_373 ) ) ;
V_368 -> V_379 = sizeof( * V_371 ) ;
}
static int F_85 ( T_1 V_380 )
{
const T_6 V_381 [] = {
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
V_404 ,
V_405 ,
V_406 ,
V_407 ,
V_408 ,
V_409 ,
V_410 ,
V_411 ,
V_412 ,
} ;
int V_23 , V_30 ;
for ( V_30 = 0 ; V_30 < F_86 ( V_381 ) ; V_30 ++ ) {
V_23 = V_381 [ V_30 ] - V_413 ;
if ( V_380 & ( 1 << V_23 ) )
return V_381 [ V_30 ] ;
}
return - 1 ;
}
static int F_87 ( T_1 V_380 )
{
const T_6 V_414 [] = {
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
V_438 ,
V_439 ,
V_440 ,
V_441 ,
V_442 ,
V_443 ,
V_444 ,
V_445 ,
V_446 ,
} ;
int V_23 , V_30 ;
for ( V_30 = 0 ; V_30 < F_86 ( V_414 ) ; V_30 ++ ) {
V_23 = V_414 [ V_30 ] - V_447 ;
if ( V_380 & ( 1 << V_23 ) )
return V_414 [ V_30 ] ;
}
return - 1 ;
}
static int F_88 ( T_1 V_380 )
{
const T_6 V_448 [] = {
V_449 ,
V_450 ,
V_451 ,
V_452 ,
V_453 ,
V_454 ,
V_455 ,
V_456 ,
V_457 ,
V_458 ,
V_459 ,
} ;
int V_23 , V_30 ;
for ( V_30 = 0 ; V_30 < F_86 ( V_448 ) ; V_30 ++ ) {
V_23 = V_448 [ V_30 ] - V_460 ;
V_380 = V_380 & V_461 ;
if ( V_380 & ( 1 << V_23 ) )
return V_448 [ V_30 ] ;
}
return - 1 ;
}
static int F_89 ( T_1 V_380 )
{
const T_6 V_462 [] = {
V_463 ,
V_464 ,
V_465 ,
V_466 ,
V_467 ,
V_468 ,
V_469 ,
V_470 ,
V_471 ,
V_472 ,
V_473 ,
} ;
int V_23 , V_30 ;
for ( V_30 = 0 ; V_30 < F_86 ( V_462 ) ; V_30 ++ ) {
V_23 = V_462 [ V_30 ] - V_474 ;
V_380 = V_380 & V_475 ;
if ( V_380 & ( 1 << ( V_23 + 0x10 ) ) )
return V_462 [ V_30 ] ;
}
return - 1 ;
}
static int F_90 ( T_1 V_380 )
{
const T_6 V_476 [] = {
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
V_494 ,
V_495 ,
V_496 ,
V_497 ,
V_498 ,
V_499 ,
V_500 ,
V_501 ,
V_502 ,
} ;
int V_23 , V_30 ;
for ( V_30 = 0 ; V_30 < F_86 ( V_476 ) ; V_30 ++ ) {
V_23 = V_476 [ V_30 ] - V_503 ;
if ( V_380 & ( 1 << V_23 ) )
return V_476 [ V_30 ] ;
}
return - 1 ;
}
static void F_91 ( struct V_1 * V_1 ,
struct V_300 * V_301 ,
struct V_275 * V_276 ,
int V_504 )
{
struct V_367 * V_368 = & V_301 -> V_369 ;
struct V_505 * V_506 = V_276 -> V_375 ;
T_1 V_507 = F_78 ( V_506 -> V_507 ) ;
T_1 V_508 = F_78 ( V_506 -> V_508 ) ;
T_7 V_509 = F_92 ( V_506 -> V_509 ) ;
T_7 V_510 = F_92 ( V_506 -> V_510 ) ;
T_1 V_511 = F_78 ( V_506 -> V_511 ) ;
int error = - 1 ;
if ( V_504 == 1 ) {
error = F_88 ( V_509 ) ;
if ( error == - 1 )
error = F_85 (
V_507 ) ;
} else if ( V_504 == 2 ) {
error = F_87 (
V_508 ) ;
if ( error == - 1 ) {
error = F_90 (
V_511 ) ;
if ( error == - 1 )
error = F_89 (
V_510 ) ;
}
}
switch ( V_301 -> V_512 ) {
case V_513 :
{
switch ( error ) {
case V_397 :
{
V_368 -> V_514 = V_515 ;
V_368 -> V_516 = V_517 ;
break;
}
case V_390 :
{
V_368 -> V_514 = V_515 ;
V_368 -> V_516 = V_518 ;
break;
}
case V_391 :
{
V_368 -> V_514 = V_515 ;
V_368 -> V_516 = V_519 ;
break;
}
case V_392 :
{
V_368 -> V_514 = V_515 ;
V_368 -> V_516 = V_520 ;
break;
}
case V_384 :
{
V_368 -> V_514 = V_515 ;
V_368 -> V_516 = V_521 ;
break;
}
case V_485 :
case V_385 :
case V_483 :
{
V_368 -> V_514 = V_515 ;
V_368 -> V_516 = V_522 ;
break;
}
case V_394 :
{
V_368 -> V_514 = V_523 ;
break;
}
case V_478 :
{
V_368 -> V_514 = V_524 ;
V_368 -> V_525 = 0 ;
break;
}
case V_479 :
{
V_368 -> V_525 = V_511 ;
V_368 -> V_514 = V_526 ;
break;
}
case V_382 :
case V_383 :
case V_386 :
case V_388 :
case V_393 :
case V_395 :
case V_396 :
case V_398 :
case V_402 :
case V_403 :
case V_404 :
case V_405 :
case V_406 :
case V_399 :
case V_400 :
case V_401 :
case V_407 :
case V_408 :
case V_409 :
case V_410 :
case V_415 :
case V_416 :
case V_417 :
case V_422 :
case V_426 :
case V_427 :
case V_428 :
case V_430 :
case V_424 :
case V_425 :
case V_527 :
case V_423 :
case V_431 :
case V_432 :
case V_433 :
case V_434 :
case V_439 :
case V_458 :
case V_449 :
case V_450 :
case V_451 :
case V_452 :
case V_473 :
case V_501 :
case V_480 :
case V_491 :
case V_492 :
case V_493 :
case V_482 :
case V_477 :
{
V_368 -> V_514 = V_21 ;
V_276 -> abort = 1 ;
break;
}
default:
break;
}
}
break;
case V_528 :
V_368 -> V_514 = V_529 ;
break;
case V_530 :
case V_531 :
case V_530 | V_531 :
{
switch ( error ) {
case V_397 :
{
V_368 -> V_514 = V_515 ;
V_368 -> V_516 = V_517 ;
break;
}
case V_394 :
{
V_368 -> V_371 = V_532 ;
V_368 -> V_514 = V_523 ;
break;
}
case V_390 :
{
V_368 -> V_514 = V_515 ;
V_368 -> V_516 = V_518 ;
break;
}
case V_391 :
{
V_368 -> V_514 = V_515 ;
V_368 -> V_516 = V_519 ;
break;
}
case V_392 :
{
V_368 -> V_514 = V_515 ;
V_368 -> V_516 = V_519 ;
break;
}
case V_384 :
{
V_368 -> V_514 = V_515 ;
V_368 -> V_516 = V_521 ;
break;
}
case V_483 :
case V_485 :
case V_385 :
{
V_368 -> V_514 = V_515 ;
V_368 -> V_516 = V_522 ;
break;
}
case V_478 :
{
V_368 -> V_514 = V_524 ;
V_368 -> V_525 = 0 ;
break;
}
case V_479 :
{
V_368 -> V_525 = V_511 ;
V_368 -> V_514 = V_526 ;
break;
}
case V_382 :
case V_383 :
case V_386 :
case V_388 :
case V_393 :
case V_395 :
case V_396 :
case V_398 :
case V_402 :
case V_403 :
case V_404 :
case V_405 :
case V_406 :
case V_399 :
case V_400 :
case V_401 :
case V_408 :
case V_409 :
case V_411 :
case V_412 :
case V_417 :
case V_416 :
case V_418 :
case V_419 :
case V_420 :
case V_421 :
case V_422 :
case V_426 :
case V_427 :
case V_428 :
case V_430 :
case V_423 :
case V_424 :
case V_425 :
case V_431 :
case V_432 :
case V_433 :
case V_439 :
case V_458 :
case V_449 :
case V_450 :
case V_451 :
case V_452 :
case V_463 :
case V_464 :
case V_465 :
case V_466 :
case V_467 :
case V_468 :
case V_471 :
case V_501 :
case V_480 :
case V_482 :
case V_486 :
case V_487 :
case V_488 :
case V_489 :
case V_490 :
case V_491 :
case V_492 :
case V_493 :
case V_494 :
case V_495 :
case V_496 :
case V_477 :
case V_434 :
case V_389 :
{
V_276 -> abort = 1 ;
V_368 -> V_514 = V_533 ;
break;
}
default:
{
V_368 -> V_514 = V_534 ;
break;
}
}
F_84 ( V_1 , V_301 , V_276 ) ;
}
break;
default:
break;
}
}
static int
F_93 ( struct V_1 * V_1 , struct V_275 * V_276 )
{
struct V_300 * V_301 = V_276 -> V_301 ;
struct V_12 * V_13 ;
struct V_8 * V_24 = & V_1 -> V_25 -> V_24 ;
struct V_367 * V_368 ;
struct V_7 * V_8 ;
enum V_535 V_536 ;
struct V_537 * V_538 =
V_1 -> V_539 [ V_276 -> V_540 ] ;
struct V_537 * V_539 =
& V_538 [ V_276 -> V_541 ] ;
unsigned long V_542 ;
int V_543 ;
if ( F_94 ( ! V_301 || ! V_301 -> V_544 || ! V_301 -> V_24 ) )
return - V_20 ;
V_368 = & V_301 -> V_369 ;
V_8 = V_301 -> V_24 ;
V_13 = V_8 -> V_14 ;
F_95 ( & V_301 -> V_545 , V_542 ) ;
V_543 = V_301 -> V_546 & V_547 ;
V_301 -> V_546 &=
~ ( V_548 | V_549 ) ;
F_96 ( & V_301 -> V_545 , V_542 ) ;
memset ( V_368 , 0 , sizeof( * V_368 ) ) ;
V_368 -> V_371 = V_550 ;
if ( F_94 ( V_543 ) ) {
V_368 -> V_514 = V_551 ;
F_97 ( V_1 , V_301 , V_276 ) ;
return - 1 ;
}
if ( F_94 ( ! V_13 ) ) {
F_31 ( V_24 , L_17 ) ;
V_368 -> V_514 = V_533 ;
goto V_32;
}
switch ( ( V_539 -> V_316 & V_552 )
>> V_553 ) {
case V_554 :
V_368 -> V_514 = V_551 ;
goto V_32;
case V_555 :
V_368 -> V_514 = V_556 ;
F_98 ( & V_276 -> V_557 ) ;
goto V_32;
case V_558 :
V_368 -> V_514 = V_559 ;
F_98 ( & V_276 -> V_557 ) ;
goto V_32;
case V_560 :
V_368 -> V_514 = V_561 ;
F_98 ( & V_276 -> V_557 ) ;
goto V_32;
default:
break;
}
if ( ( V_539 -> V_316 & V_562 ) &&
( ! ( V_539 -> V_316 & V_563 ) ) ) {
T_1 V_504 = ( V_539 -> V_316 & V_564 )
>> V_565 ;
if ( F_99 ( V_504 ) )
F_91 ( V_1 , V_301 , V_276 , 1 ) ;
else if ( F_100 ( V_504 ) )
F_91 ( V_1 , V_301 , V_276 , 2 ) ;
if ( F_94 ( V_276 -> abort ) )
return V_368 -> V_514 ;
goto V_32;
}
switch ( V_301 -> V_512 ) {
case V_513 :
{
struct V_566 * V_567 = V_276 -> V_375 +
sizeof( struct V_376 ) ;
F_101 ( V_24 , V_301 , V_567 ) ;
break;
}
case V_528 :
{
struct V_279 * V_304 = & V_301 -> V_309 . V_312 ;
void * V_568 ;
V_368 -> V_514 = V_569 ;
V_568 = F_102 ( F_103 ( V_304 ) ) ;
F_82 ( V_24 , & V_301 -> V_309 . V_312 , 1 ,
V_313 ) ;
F_82 ( V_24 , & V_301 -> V_309 . V_310 , 1 ,
V_311 ) ;
memcpy ( V_568 + V_304 -> V_570 ,
V_276 -> V_375 +
sizeof( struct V_376 ) ,
F_79 ( V_304 ) ) ;
F_104 ( V_568 ) ;
break;
}
case V_530 :
case V_531 :
case V_530 | V_531 :
{
V_368 -> V_514 = V_569 ;
F_84 ( V_1 , V_301 , V_276 ) ;
break;
}
default:
V_368 -> V_514 = V_529 ;
break;
}
if ( ! V_276 -> V_27 -> V_571 ) {
F_39 ( V_24 , L_18 ,
V_276 -> V_27 -> V_72 . V_89 ) ;
V_368 -> V_514 = V_533 ;
}
V_32:
F_95 ( & V_301 -> V_545 , V_542 ) ;
V_301 -> V_546 |= V_572 ;
F_96 ( & V_301 -> V_545 , V_542 ) ;
F_97 ( V_1 , V_301 , V_276 ) ;
V_536 = V_368 -> V_514 ;
if ( V_301 -> V_573 )
V_301 -> V_573 ( V_301 ) ;
return V_536 ;
}
static T_6 F_105 ( T_6 V_340 , int V_574 )
{
switch ( V_340 ) {
case V_575 :
case V_576 :
case V_577 :
case V_578 :
case V_579 :
return V_580 ;
case V_581 :
case V_582 :
case V_583 :
case V_584 :
case V_585 :
case V_586 :
case V_587 :
case V_588 :
case V_589 :
case V_590 :
return V_591 ;
case V_592 :
case V_593 :
case V_594 :
case V_595 :
case V_596 :
case V_597 :
case V_598 :
case V_599 :
case V_600 :
case V_601 :
case V_602 :
case V_603 :
case V_604 :
case V_605 :
case V_606 :
case V_607 :
return V_608 ;
case V_609 :
case V_610 :
case V_611 :
case V_612 :
case V_613 :
case V_614 :
case V_615 :
case V_616 :
case V_617 :
case V_618 :
return V_619 ;
default:
if ( V_574 == V_620 )
return V_619 ;
return V_591 ;
}
}
static int F_106 ( struct V_300 * V_301 , T_1 * V_621 )
{
struct V_622 * V_623 = V_301 -> V_624 ;
if ( V_623 ) {
if ( V_623 -> V_625 . V_626 == V_575 ||
V_623 -> V_625 . V_626 == V_576 ) {
* V_621 = V_623 -> V_621 ;
return 1 ;
}
}
return 0 ;
}
static int F_107 ( struct V_1 * V_1 ,
struct V_275 * V_276 )
{
struct V_300 * V_301 = V_276 -> V_301 ;
struct V_7 * V_8 = V_301 -> V_24 ;
struct V_7 * V_69 = V_8 -> V_70 ;
struct V_12 * V_13 = V_8 -> V_14 ;
struct V_277 * V_278 = V_276 -> V_302 ;
struct V_71 * V_72 = V_8 -> V_27 ;
struct V_73 * V_27 = F_24 ( V_72 ) ;
T_6 * V_343 ;
int V_341 = 0 , V_211 = 0 , V_627 = 0 ;
T_1 V_320 = 0 , V_325 = 0 ;
V_278 -> V_316 = F_78 ( V_27 -> V_89 << V_317 ) ;
if ( V_69 && F_25 ( V_69 -> V_35 ) )
V_278 -> V_316 |= F_78 ( 3 << V_319 ) ;
else
V_278 -> V_316 |= F_78 ( 4 << V_319 ) ;
switch ( V_301 -> V_628 ) {
case V_311 :
V_341 = 1 ;
V_320 |= V_348 << V_324 ;
break;
case V_313 :
V_341 = 1 ;
V_320 |= V_349 << V_324 ;
break;
default:
V_320 &= ~ V_350 ;
}
if ( ( V_301 -> V_629 . V_630 . V_626 == V_610 ) &&
( V_301 -> V_629 . V_630 . V_631 & V_632 ) )
V_320 |= 1 << V_633 ;
V_320 |= ( F_105 ( V_301 -> V_629 . V_630 . V_626 , V_301 -> V_628 ) )
<< V_322 ;
V_320 |= V_13 -> V_37 << V_321 ;
V_278 -> V_320 = F_78 ( V_320 ) ;
if ( V_301 -> V_629 . V_634 && F_106 ( V_301 , & V_627 ) ) {
V_301 -> V_629 . V_630 . V_635 |= ( T_6 ) ( V_627 << 3 ) ;
V_325 |= V_627 << V_636 ;
}
V_325 |= ( V_637 / 4 ) << V_326 |
2 << V_354 ;
V_278 -> V_325 = F_78 ( V_325 ) ;
V_278 -> V_329 = F_78 ( V_276 -> V_22 ) ;
if ( V_341 ) {
V_211 = F_74 ( V_1 , V_276 , V_278 , V_301 -> V_280 ,
V_276 -> V_281 ) ;
if ( V_211 )
return V_211 ;
}
V_278 -> V_355 = F_78 ( V_301 -> V_356 ) ;
V_278 -> V_331 = F_26 ( V_276 -> V_357 ) ;
V_278 -> V_332 = F_26 ( V_276 -> V_333 ) ;
V_343 = V_276 -> V_358 ;
if ( F_108 ( ! V_301 -> V_629 . V_638 ) )
V_301 -> V_629 . V_630 . V_542 |= 0x80 ;
memcpy ( V_343 , & V_301 -> V_629 . V_630 , sizeof( struct V_639 ) ) ;
return 0 ;
}
static void F_109 ( unsigned long V_205 )
{
struct V_275 * V_276 = (struct V_275 * ) V_205 ;
struct V_73 * V_27 = V_276 -> V_27 ;
struct V_71 * V_71 ;
struct V_246 * V_247 ;
if ( ! V_27 )
return;
V_71 = & V_27 -> V_72 ;
F_110 (sas_phy, &asd_sas_port->phy_list, port_phy_el) {
struct V_234 * V_235 = V_247 -> V_640 ;
struct V_1 * V_1 = V_235 -> V_1 ;
int V_5 = V_247 -> V_89 ;
T_1 V_641 ;
V_641 = F_8 ( V_1 , V_5 , V_223 ) ;
if ( ( V_641 == V_642 ) ||
( V_641 & V_643 ) ) {
T_1 V_227 ;
V_227 = F_8 ( V_1 , V_5 ,
V_163 ) ;
V_227 |= V_233 ;
F_7 ( V_1 , V_5 , V_163 ,
V_227 ) ;
return;
}
}
}
static int F_111 ( struct V_1 * V_1 ,
struct V_275 * V_276 ,
int V_37 , int V_644 , int V_645 )
{
struct V_300 * V_301 = V_276 -> V_301 ;
struct V_7 * V_24 = V_301 -> V_24 ;
struct V_277 * V_278 = V_276 -> V_302 ;
struct V_73 * V_27 = V_276 -> V_27 ;
struct V_646 * V_206 = & V_276 -> V_557 ;
F_112 ( V_206 , F_109 ,
( unsigned long ) V_276 ) ;
F_50 ( V_206 , V_111 + F_33 ( 100 ) ) ;
V_278 -> V_316 = F_78 ( ( 5 << V_319 ) |
( V_27 -> V_89 << V_317 ) |
( ( F_10 ( V_24 ) ? 1 : 0 ) <<
V_647 ) |
( V_644 << V_648 ) ) ;
V_278 -> V_320 = F_78 ( V_37 << V_321 ) ;
V_278 -> V_649 = F_78 ( V_645 << V_650 ) ;
V_278 -> V_329 = F_78 ( V_276 -> V_22 ) ;
return 0 ;
}
static int F_113 ( int V_5 , struct V_1 * V_1 )
{
int V_30 , V_651 = V_652 ;
T_1 V_255 , V_653 , V_654 ;
struct V_234 * V_235 = & V_1 -> V_235 [ V_5 ] ;
struct V_246 * V_247 = & V_235 -> V_247 ;
struct V_8 * V_24 = & V_1 -> V_25 -> V_24 ;
T_1 * V_655 = ( T_1 * ) V_247 -> V_655 ;
struct V_46 * V_89 = (struct V_46 * ) V_655 ;
F_7 ( V_1 , V_5 , V_175 , 1 ) ;
if ( F_55 ( V_1 , V_5 ) )
goto V_17;
if ( V_5 == 8 ) {
T_1 V_259 = F_1 ( V_1 , V_260 ) ;
V_255 = ( V_259 & V_261 ) >>
V_262 ;
V_653 = ( V_259 & V_656 ) >>
V_657 ;
} else {
V_255 = F_1 ( V_1 , V_257 ) ;
V_255 = ( V_255 >> ( 4 * V_5 ) ) & 0xf ;
V_653 = F_1 ( V_1 , V_658 ) ;
V_653 = ( V_653 >> ( V_5 * 4 ) ) & 0xf ;
}
if ( V_255 == 0xf ) {
F_39 ( V_24 , L_19 , V_5 ) ;
V_651 = V_659 ;
goto V_17;
}
for ( V_30 = 0 ; V_30 < 6 ; V_30 ++ ) {
T_1 V_660 = F_8 ( V_1 , V_5 ,
V_661 + ( V_30 * 4 ) ) ;
V_655 [ V_30 ] = F_22 ( V_660 ) ;
}
V_247 -> V_83 = V_653 ;
V_654 = F_8 ( V_1 , V_5 ,
V_662 ) ;
V_235 -> V_251 = V_654 & 0xf ;
V_235 -> V_253 = ( V_654 >> 4 ) & 0xf ;
V_247 -> V_663 = V_664 ;
memcpy ( V_247 -> V_665 , & V_89 -> V_57 , V_58 ) ;
F_114 ( V_24 , L_20 , V_5 , V_653 ) ;
V_235 -> V_255 = V_255 ;
V_235 -> V_666 &= ~ ( V_667 | V_668 ) ;
V_235 -> V_666 |= V_667 ;
V_235 -> V_669 = 1 ;
V_235 -> V_236 . V_237 = V_89 -> V_35 ;
V_235 -> V_670 = sizeof( struct V_46 ) ;
if ( V_235 -> V_236 . V_237 == V_49 )
V_235 -> V_236 . V_671 =
V_513 ;
else if ( V_235 -> V_236 . V_237 != V_36 ) {
V_235 -> V_236 . V_671 =
V_528 ;
if ( ! F_115 ( & V_1 -> V_206 ) )
F_51 ( V_1 ) ;
}
F_61 ( V_1 -> V_230 , & V_235 -> V_672 ) ;
V_17:
F_7 ( V_1 , V_5 , V_165 ,
V_673 ) ;
F_7 ( V_1 , V_5 , V_175 , 0 ) ;
return V_651 ;
}
static bool F_116 ( struct V_1 * V_1 )
{
T_1 V_259 ;
V_259 = F_1 ( V_1 , V_260 ) ;
if ( V_259 & 0x1ff )
return true ;
return false ;
}
static int F_117 ( int V_5 , struct V_1 * V_1 )
{
T_1 V_258 , V_674 , V_227 ;
struct V_234 * V_235 = & V_1 -> V_235 [ V_5 ] ;
struct V_73 * V_27 = V_235 -> V_27 ;
F_7 ( V_1 , V_5 , V_173 , 1 ) ;
V_258 = F_1 ( V_1 , V_209 ) ;
F_118 ( V_1 , V_5 , ( V_258 & 1 << V_5 ) ? 1 : 0 ) ;
V_674 = F_8 ( V_1 , V_5 , V_162 ) ;
F_7 ( V_1 , V_5 , V_162 ,
V_674 & ~ V_675 ) ;
if ( V_27 && ! F_71 ( V_1 , V_27 -> V_89 ) )
if ( ! F_116 ( V_1 ) &&
F_115 ( & V_1 -> V_206 ) )
F_98 ( & V_1 -> V_206 ) ;
V_227 = F_8 ( V_1 , V_5 , V_163 ) ;
F_7 ( V_1 , V_5 , V_163 ,
V_227 | V_676 ) ;
F_7 ( V_1 , V_5 , V_165 , V_677 ) ;
F_7 ( V_1 , V_5 , V_173 , 0 ) ;
return V_652 ;
}
static T_8 F_119 ( int V_678 , void * V_679 )
{
struct V_1 * V_1 = V_679 ;
T_1 V_680 ;
int V_5 = 0 ;
V_680 = ( F_1 ( V_1 , V_681 )
>> V_682 ) & 0x1ff ;
while ( V_680 ) {
if ( V_680 & 1 ) {
T_1 V_683 = F_8 ( V_1 , V_5 ,
V_165 ) ;
switch ( V_683 & ( V_677 |
V_673 ) ) {
case V_673 :
if ( F_113 ( V_5 , V_1 ) ==
V_659 )
return V_659 ;
break;
case V_677 :
if ( F_117 ( V_5 , V_1 ) ==
V_659 )
return V_659 ;
break;
case ( V_677 |
V_673 ) :
V_683 = F_1 ( V_1 ,
V_209 ) ;
if ( V_683 & F_44 ( V_5 ) ) {
if ( F_113 ( V_5 , V_1 ) ==
V_659 )
return V_659 ;
} else {
if ( F_117 ( V_5 , V_1 ) ==
V_659 )
return V_659 ;
}
break;
default:
break;
}
}
V_680 >>= 1 ;
V_5 ++ ;
}
return V_652 ;
}
static void F_120 ( int V_5 , struct V_1 * V_1 )
{
struct V_234 * V_235 = & V_1 -> V_235 [ V_5 ] ;
struct V_246 * V_247 = & V_235 -> V_247 ;
struct V_684 * V_685 = & V_1 -> V_686 ;
T_1 V_687 ;
F_7 ( V_1 , V_5 , V_176 , 1 ) ;
V_687 = F_8 ( V_1 , V_5 , V_688 ) ;
if ( V_687 & V_689 )
V_685 -> V_690 ( V_247 , V_691 ) ;
F_7 ( V_1 , V_5 , V_165 ,
V_692 ) ;
F_7 ( V_1 , V_5 , V_176 , 0 ) ;
}
static T_8 F_121 ( int V_678 , void * V_679 )
{
struct V_1 * V_1 = V_679 ;
struct V_8 * V_24 = & V_1 -> V_25 -> V_24 ;
T_1 V_693 , V_694 , V_680 ;
int V_5 = 0 ;
V_693 = F_1 ( V_1 , V_154 ) ;
V_694 = V_693 ;
V_693 |= V_695 ;
F_5 ( V_1 , V_154 , V_693 ) ;
V_680 = ( F_1 ( V_1 , V_681 ) >>
V_696 ) & 0x1ff ;
while ( V_680 ) {
if ( V_680 & ( 1 << V_5 ) ) {
T_1 V_697 = F_8 ( V_1 , V_5 ,
V_165 ) ;
T_1 V_698 = F_8 ( V_1 , V_5 ,
V_166 ) ;
T_1 V_699 = F_8 ( V_1 , V_5 ,
V_167 ) ;
if ( V_698 ) {
if ( V_698 & ( V_700 |
V_701 ) )
F_122 ( L_21 ,
F_123 ( V_24 ) , V_698 ) ;
F_7 ( V_1 , V_5 ,
V_166 , V_698 ) ;
}
if ( V_699 )
F_7 ( V_1 , V_5 ,
V_167 , V_699 ) ;
if ( V_697 ) {
if ( V_697 & V_692 )
F_120 ( V_5 , V_1 ) ;
F_7 ( V_1 , V_5 ,
V_165 , V_697
& ( ~ V_702 )
& ( ~ V_673 )
& ( ~ V_677 ) ) ;
}
}
V_680 &= ~ ( 1 << V_5 ) ;
V_5 ++ ;
}
F_5 ( V_1 , V_154 , V_694 ) ;
return V_652 ;
}
static void
F_124 ( struct V_1 * V_1 , T_1 V_703 )
{
struct V_8 * V_24 = & V_1 -> V_25 -> V_24 ;
T_1 V_97 ;
if ( V_703 & F_44 ( V_704 ) ) {
V_97 = F_1 ( V_1 , V_705 ) ;
F_15 ( V_24 , L_22 ,
( V_97 & V_706 ) >>
V_707 ) ;
}
if ( V_703 & F_44 ( V_708 ) ) {
V_97 = F_1 ( V_1 , V_709 ) ;
F_15 ( V_24 , L_23 ,
( V_97 & V_710 ) >>
V_711 ) ;
}
if ( V_703 & F_44 ( V_712 ) ) {
V_97 = F_1 ( V_1 , V_713 ) ;
F_15 ( V_24 , L_24 ,
( V_97 & V_714 ) >>
V_715 ) ;
}
if ( V_703 & F_44 ( V_716 ) ) {
V_97 = F_1 ( V_1 , V_717 ) ;
F_15 ( V_24 , L_25 ,
( V_97 & V_718 ) >>
V_719 ) ;
}
if ( V_703 & F_44 ( V_720 ) ) {
V_97 = F_1 ( V_1 , V_717 ) ;
F_15 ( V_24 , L_26 ,
( V_97 & V_721 ) >>
V_722 ) ;
}
if ( V_703 & F_44 ( V_723 ) ) {
V_97 = F_1 ( V_1 , V_724 ) ;
F_15 ( V_24 , L_27 ,
( V_97 & V_725 ) >>
V_726 ) ;
}
if ( V_703 & F_44 ( V_727 ) ) {
V_97 = F_1 ( V_1 , V_728 ) ;
F_15 ( V_24 , L_28 ,
( V_97 & V_729 ) >>
V_730 ) ;
}
if ( V_703 & F_44 ( V_731 ) ) {
V_97 = F_1 ( V_1 , V_728 ) ;
F_15 ( V_24 , L_29 ,
( V_97 & V_732 ) >>
V_733 ) ;
}
if ( V_703 & F_44 ( V_734 ) ) {
V_97 = F_1 ( V_1 , V_728 ) ;
F_15 ( V_24 , L_30 ,
( V_97 & V_735 ) >>
V_736 ) ;
}
if ( V_703 & F_44 ( V_737 ) ) {
V_97 = F_1 ( V_1 , V_738 ) ;
F_15 ( V_24 , L_31 ,
( V_97 & V_739 ) >>
V_740 ) ;
}
}
static void F_125 ( struct V_1 * V_1 ,
T_1 V_703 )
{
T_1 V_97 ;
struct V_8 * V_24 = & V_1 -> V_25 -> V_24 ;
if ( V_703 & F_44 ( V_741 ) ) {
V_97 = F_1 ( V_1 , V_705 ) ;
F_15 ( V_24 , L_32 ,
V_703 ,
( V_97 & V_742 ) >>
V_743 ) ;
F_61 ( V_1 -> V_230 , & V_1 -> V_231 ) ;
}
if ( V_703 & F_44 ( V_744 ) ) {
V_97 = F_1 ( V_1 , V_709 ) ;
F_15 ( V_24 , L_33 ,
V_703 ,
( V_97 & V_745 ) >>
V_746 ) ;
F_61 ( V_1 -> V_230 , & V_1 -> V_231 ) ;
}
if ( V_703 & F_44 ( V_747 ) ) {
V_97 = F_1 ( V_1 , V_713 ) ;
F_15 ( V_24 , L_34 ,
V_703 ,
( V_97 & V_748 ) >>
V_749 ) ;
F_61 ( V_1 -> V_230 , & V_1 -> V_231 ) ;
}
if ( V_703 & F_44 ( V_750 ) ) {
V_97 = F_1 ( V_1 , V_717 ) ;
F_15 ( V_24 , L_35 ,
V_703 ,
( V_97 & V_718 ) >>
V_719 ) ;
F_61 ( V_1 -> V_230 , & V_1 -> V_231 ) ;
}
if ( V_703 & F_44 ( V_751 ) ) {
V_97 = F_1 ( V_1 , V_717 ) ;
F_15 ( V_24 , L_36 ,
V_703 ,
( V_97 & V_721 ) >>
V_722 ) ;
F_61 ( V_1 -> V_230 , & V_1 -> V_231 ) ;
}
if ( V_703 & F_44 ( V_752 ) ) {
V_97 = F_1 ( V_1 , V_724 ) ;
F_15 ( V_24 , L_37 ,
V_703 ,
( V_97 & V_753 ) >>
V_754 ) ;
F_61 ( V_1 -> V_230 , & V_1 -> V_231 ) ;
}
if ( V_703 & F_44 ( V_755 ) ) {
V_97 = F_1 ( V_1 , V_728 ) ;
F_15 ( V_24 , L_38 ,
V_703 ,
( V_97 & V_729 ) >>
V_730 ) ;
F_61 ( V_1 -> V_230 , & V_1 -> V_231 ) ;
}
if ( V_703 & F_44 ( V_756 ) ) {
V_97 = F_1 ( V_1 , V_728 ) ;
F_15 ( V_24 , L_39 ,
V_703 ,
( V_97 & V_732 ) >>
V_733 ) ;
F_61 ( V_1 -> V_230 , & V_1 -> V_231 ) ;
}
if ( V_703 & F_44 ( V_757 ) ) {
V_97 = F_1 ( V_1 , V_728 ) ;
F_15 ( V_24 , L_40 ,
V_703 ,
( V_97 & V_735 ) >>
V_736 ) ;
F_61 ( V_1 -> V_230 , & V_1 -> V_231 ) ;
}
if ( V_703 & F_44 ( V_758 ) ) {
V_97 = F_1 ( V_1 , V_738 ) ;
F_15 ( V_24 , L_41 ,
V_703 ,
( V_97 & V_739 ) >>
V_740 ) ;
F_61 ( V_1 -> V_230 , & V_1 -> V_231 ) ;
}
return;
}
static T_8 F_126 ( int V_678 , void * V_679 )
{
struct V_1 * V_1 = V_679 ;
T_1 V_703 , V_680 ;
V_680 = F_1 ( V_1 , V_155 ) ;
F_5 ( V_1 , V_155 , V_680 | 0xffffffff ) ;
V_703 = F_1 ( V_1 , V_759 ) ;
if ( V_703 ) {
F_124 ( V_1 , V_703 ) ;
F_125 ( V_1 , V_703 ) ;
}
F_5 ( V_1 , V_759 , V_703 ) ;
F_5 ( V_1 , V_155 , V_680 ) ;
return V_652 ;
}
static T_8 F_127 ( int V_678 , void * V_679 )
{
struct V_1 * V_1 = V_679 ;
T_1 V_703 , V_680 , V_760 ;
struct V_8 * V_24 = & V_1 -> V_25 -> V_24 ;
V_680 = F_1 ( V_1 , V_154 ) ;
F_5 ( V_1 , V_154 , V_680 | 0xfffffffe ) ;
V_703 = F_1 ( V_1 , V_98 ) ;
if ( V_703 ) {
if ( V_703 & F_44 ( V_761 ) ) {
F_5 ( V_1 , V_98 ,
1 << V_761 ) ;
F_15 ( V_24 , L_42 ,
V_703 ) ;
F_61 ( V_1 -> V_230 , & V_1 -> V_231 ) ;
}
if ( V_703 & F_44 ( V_762 ) ) {
F_5 ( V_1 , V_98 ,
1 <<
V_762 ) ;
F_15 ( V_24 , L_43 ,
V_703 ) ;
F_61 ( V_1 -> V_230 , & V_1 -> V_231 ) ;
}
if ( V_703 & F_44 ( V_763 ) ) {
F_15 ( V_24 , L_44 ,
V_703 ) ;
F_61 ( V_1 -> V_230 , & V_1 -> V_231 ) ;
}
if ( V_703 & F_44 ( V_764 ) ) {
int V_30 ;
F_5 ( V_1 , V_98 ,
1 << V_764 ) ;
V_760 = F_1 ( V_1 ,
V_765 ) ;
for ( V_30 = 0 ; V_30 < V_766 ; V_30 ++ ) {
if ( V_760 & F_44 ( V_30 ) ) {
F_15 ( V_24 , L_45 ,
V_767 [ V_30 ] , V_703 ) ;
F_61 ( V_1 -> V_230 , & V_1 -> V_231 ) ;
}
}
}
if ( V_703 & F_44 ( V_768 ) ) {
int V_30 ;
F_5 ( V_1 , V_98 ,
1 << V_768 ) ;
V_760 = F_1 ( V_1 ,
V_765 ) ;
for ( V_30 = 0 ; V_30 < V_769 ; V_30 ++ ) {
if ( V_760 & F_44 ( V_766 + V_30 ) ) {
F_15 ( V_24 , L_45 ,
V_770 [ V_30 ] , V_703 ) ;
F_61 ( V_1 -> V_230 , & V_1 -> V_231 ) ;
}
}
}
if ( V_703 & F_44 ( V_771 ) ) {
F_5 ( V_1 , V_98 ,
1 << V_771 ) ;
F_15 ( V_24 , L_46 ,
V_703 ) ;
F_61 ( V_1 -> V_230 , & V_1 -> V_231 ) ;
}
if ( V_703 & F_44 ( V_772 ) ) {
F_5 ( V_1 , V_98 ,
1 << V_772 ) ;
F_15 ( V_24 , L_47 ,
V_703 ) ;
F_61 ( V_1 -> V_230 , & V_1 -> V_231 ) ;
}
}
F_5 ( V_1 , V_154 , V_680 ) ;
return V_652 ;
}
static void F_128 ( unsigned long V_4 )
{
struct V_773 * V_774 = (struct V_773 * ) V_4 ;
struct V_1 * V_1 = V_774 -> V_1 ;
struct V_275 * V_276 ;
struct V_67 * V_68 ;
struct V_537 * V_538 ;
T_1 V_775 = V_774 -> V_775 , V_268 , V_96 ;
int V_267 = V_774 -> V_89 ;
if ( F_94 ( V_1 -> V_124 ) )
F_43 ( V_1 ) ;
V_538 = V_1 -> V_539 [ V_267 ] ;
F_17 ( & V_1 -> V_31 ) ;
V_268 = F_1 ( V_1 , V_776 +
( 0x14 * V_267 ) ) ;
while ( V_775 != V_268 ) {
struct V_537 * V_539 ;
int V_777 ;
V_539 = & V_538 [ V_775 ] ;
if ( V_539 -> V_778 ) {
T_1 V_779 = V_539 -> V_778 ;
int V_780 = F_129 ( V_779 ) ;
V_96 = ( V_539 -> V_320 & V_781 ) >>
V_782 ;
V_68 = & V_1 -> V_68 [ V_96 ] ;
while ( V_780 ) {
T_9 * V_783 = & V_68 -> V_784 [ 0 ] ;
V_780 -= 1 ;
V_777 = ( V_783 [ V_780 / 5 ]
>> ( V_780 % 5 ) * 12 ) & 0xfff ;
V_276 = & V_1 -> V_785 [ V_777 ] ;
V_276 -> V_541 = V_775 ;
V_276 -> V_540 = V_267 ;
F_93 ( V_1 , V_276 ) ;
V_779 &= ~ ( 1 << V_780 ) ;
V_780 = F_129 ( V_779 ) ;
}
} else {
V_777 = ( V_539 -> V_320 ) & V_786 ;
V_276 = & V_1 -> V_785 [ V_777 ] ;
V_276 -> V_541 = V_775 ;
V_276 -> V_540 = V_267 ;
F_93 ( V_1 , V_276 ) ;
}
if ( ++ V_775 >= V_185 )
V_775 = 0 ;
}
V_774 -> V_775 = V_775 ;
F_5 ( V_1 , V_787 + ( 0x14 * V_267 ) , V_775 ) ;
F_19 ( & V_1 -> V_31 ) ;
}
static T_8 F_130 ( int V_678 , void * V_679 )
{
struct V_773 * V_774 = V_679 ;
struct V_1 * V_1 = V_774 -> V_1 ;
int V_267 = V_774 -> V_89 ;
F_5 ( V_1 , V_149 , 1 << V_267 ) ;
F_131 ( & V_774 -> V_788 ) ;
return V_652 ;
}
static T_8 F_132 ( int V_678 , void * V_679 )
{
struct V_234 * V_235 = V_679 ;
struct V_1 * V_1 = V_235 -> V_1 ;
struct V_246 * V_247 = & V_235 -> V_247 ;
struct V_8 * V_24 = & V_1 -> V_25 -> V_24 ;
struct V_789 * V_790 ;
struct V_373 * V_630 ;
T_1 V_694 , V_693 , V_791 , V_255 , V_653 , V_654 ;
T_8 V_651 = V_652 ;
T_6 V_665 [ V_58 ] = { 0 } ;
int V_5 , V_570 ;
V_5 = V_247 -> V_89 ;
V_790 = & V_1 -> V_790 [ V_5 ] ;
V_630 = & V_790 -> V_630 ;
V_570 = 4 * ( V_5 / 4 ) ;
V_693 = F_1 ( V_1 , V_152 + V_570 ) ;
F_5 ( V_1 , V_152 + V_570 ,
V_693 | 1 << ( ( V_5 % 4 ) * 8 ) ) ;
V_791 = F_1 ( V_1 , V_150 + V_570 ) ;
V_694 = V_791 & ( 1 << ( V_792 *
( V_5 % 4 ) ) ) ;
V_791 >>= V_792 * ( V_5 % 4 ) ;
if ( ( V_791 & V_793 ) == 0 ) {
F_15 ( V_24 , L_48 , V_5 ) ;
V_651 = V_659 ;
goto V_17;
}
if ( V_630 -> V_217 & V_794 ) {
F_15 ( V_24 , L_49 , V_5 ,
V_630 -> V_217 ) ;
F_60 ( V_1 , V_5 ) ;
F_54 ( V_1 , V_5 ) ;
V_651 = V_659 ;
goto V_17;
}
if ( F_94 ( V_5 == 8 ) ) {
T_1 V_259 = F_1 ( V_1 , V_260 ) ;
V_255 = ( V_259 & V_261 ) >>
V_262 ;
V_653 = ( V_259 & V_656 ) >>
V_657 ;
} else {
V_255 = F_1 ( V_1 , V_257 ) ;
V_255 = ( V_255 >> ( 4 * V_5 ) ) & 0xf ;
V_653 = F_1 ( V_1 , V_658 ) ;
V_653 = ( V_653 >> ( V_5 * 4 ) ) & 0xf ;
}
if ( V_255 == 0xf ) {
F_39 ( V_24 , L_50 , V_5 ) ;
V_651 = V_659 ;
goto V_17;
}
V_247 -> V_83 = V_653 ;
V_654 = F_8 ( V_1 , V_5 ,
V_662 ) ;
V_235 -> V_251 = V_654 & 0xf ;
V_235 -> V_253 = ( V_654 >> 4 ) & 0xf ;
V_247 -> V_663 = V_795 ;
V_665 [ 0 ] = 0x50 ;
V_665 [ 7 ] = V_5 ;
memcpy ( V_247 -> V_665 , V_665 , V_58 ) ;
memcpy ( V_247 -> V_655 , V_630 , sizeof( struct V_373 ) ) ;
F_114 ( V_24 , L_51 , V_5 , V_653 ) ;
V_235 -> V_666 &= ~ ( V_667 | V_668 ) ;
V_235 -> V_255 = V_255 ;
V_235 -> V_666 |= V_668 ;
V_235 -> V_669 = 1 ;
V_235 -> V_236 . V_237 = V_78 ;
V_235 -> V_670 = sizeof( struct V_373 ) ;
V_235 -> V_236 . V_671 = V_530 ;
F_61 ( V_1 -> V_230 , & V_235 -> V_672 ) ;
V_17:
F_5 ( V_1 , V_150 + V_570 , V_694 ) ;
F_5 ( V_1 , V_152 + V_570 , V_693 ) ;
return V_651 ;
}
static int F_133 ( struct V_1 * V_1 )
{
struct V_796 * V_25 = V_1 -> V_25 ;
struct V_8 * V_24 = & V_25 -> V_24 ;
int V_30 , V_797 , V_211 , V_798 [ 128 ] ;
for ( V_30 = 0 ; V_30 < 128 ; V_30 ++ )
V_798 [ V_30 ] = F_134 ( V_25 , V_30 ) ;
for ( V_30 = 0 ; V_30 < V_799 ; V_30 ++ ) {
int V_22 = V_30 ;
V_797 = V_798 [ V_22 + 1 ] ;
if ( ! V_797 ) {
F_39 ( V_24 , L_52 ,
V_22 ) ;
return - V_800 ;
}
V_211 = F_135 ( V_24 , V_797 , V_801 [ V_30 ] , 0 ,
V_802 L_53 , V_1 ) ;
if ( V_211 ) {
F_39 ( V_24 , L_54
L_55 ,
V_797 , V_211 ) ;
return - V_800 ;
}
}
for ( V_30 = 0 ; V_30 < V_1 -> V_105 ; V_30 ++ ) {
struct V_234 * V_235 = & V_1 -> V_235 [ V_30 ] ;
int V_22 = V_30 + 72 ;
V_797 = V_798 [ V_22 ] ;
if ( ! V_797 ) {
F_39 ( V_24 , L_52 ,
V_22 ) ;
return - V_800 ;
}
V_211 = F_135 ( V_24 , V_797 , F_132 , 0 ,
V_802 L_56 , V_235 ) ;
if ( V_211 ) {
F_39 ( V_24 , L_54
L_57 ,
V_797 , V_211 ) ;
return - V_800 ;
}
}
for ( V_30 = 0 ; V_30 < V_803 ; V_30 ++ ) {
int V_22 = V_30 ;
V_797 = V_798 [ V_22 + 81 ] ;
if ( ! V_797 ) {
F_39 ( V_24 , L_58 ,
V_22 ) ;
return - V_800 ;
}
V_211 = F_135 ( V_24 , V_797 , V_804 [ V_30 ] , 0 ,
V_802 L_59 , V_1 ) ;
if ( V_211 ) {
F_39 ( V_24 ,
L_60 ,
V_797 , V_211 ) ;
return - V_800 ;
}
}
for ( V_30 = 0 ; V_30 < V_1 -> V_132 ; V_30 ++ ) {
int V_22 = V_30 + 96 ;
struct V_773 * V_774 = & V_1 -> V_774 [ V_30 ] ;
struct V_805 * V_806 = & V_774 -> V_788 ;
V_797 = V_798 [ V_22 ] ;
if ( ! V_797 ) {
F_39 ( V_24 ,
L_61 ,
V_22 ) ;
return - V_800 ;
}
V_211 = F_135 ( V_24 , V_797 , F_130 , 0 ,
V_802 L_62 , & V_1 -> V_774 [ V_30 ] ) ;
if ( V_211 ) {
F_39 ( V_24 ,
L_63 ,
V_797 , V_211 ) ;
return - V_800 ;
}
F_136 ( V_806 , F_128 , ( unsigned long ) V_774 ) ;
}
return 0 ;
}
static int F_137 ( struct V_1 * V_1 )
{
int V_211 ;
memset ( V_1 -> V_26 , 0 , sizeof( V_1 -> V_26 ) ) ;
V_211 = F_53 ( V_1 ) ;
if ( V_211 )
return V_211 ;
V_211 = F_133 ( V_1 ) ;
if ( V_211 )
return V_211 ;
return 0 ;
}
static void F_138 ( struct V_1 * V_1 )
{
struct V_796 * V_25 = V_1 -> V_25 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_1 -> V_132 ; V_30 ++ )
F_5 ( V_1 , V_156 + 0x4 * V_30 , 0x1 ) ;
F_5 ( V_1 , V_152 , 0xffffffff ) ;
F_5 ( V_1 , V_153 , 0xffffffff ) ;
F_5 ( V_1 , V_154 , 0xffffffff ) ;
F_5 ( V_1 , V_155 , 0xffffffff ) ;
for ( V_30 = 0 ; V_30 < V_1 -> V_105 ; V_30 ++ ) {
F_7 ( V_1 , V_30 , V_169 , 0xffffffff ) ;
F_7 ( V_1 , V_30 , V_170 , 0xffffffff ) ;
}
for ( V_30 = 0 ; V_30 < 128 ; V_30 ++ )
F_139 ( F_134 ( V_25 , V_30 ) ) ;
}
static int F_140 ( struct V_1 * V_1 )
{
struct V_8 * V_24 = & V_1 -> V_25 -> V_24 ;
T_1 V_807 , V_808 ;
int V_211 , V_809 ;
int V_5 ;
V_807 = F_1 ( V_1 , V_209 ) ;
F_138 ( V_1 ) ;
F_5 ( V_1 , V_106 , 0x0 ) ;
F_64 ( V_1 ) ;
F_141 ( 10 ) ;
F_5 ( V_1 , V_219 + V_228 , 0x1 ) ;
V_809 = 0 ;
while ( 1 ) {
T_1 V_217 = F_3 ( V_1 ,
V_219 + V_220 ) ;
if ( V_217 == 0x3 )
break;
F_30 ( 10 ) ;
if ( V_809 ++ > 10 ) {
F_114 ( V_24 , L_64 ) ;
return - 1 ;
}
}
F_142 ( V_1 ) ;
V_211 = F_53 ( V_1 ) ;
if ( V_211 )
return V_211 ;
F_42 ( V_1 ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_105 ; V_5 ++ ) {
struct V_234 * V_235 = & V_1 -> V_235 [ V_5 ] ;
struct V_246 * V_247 = & V_235 -> V_247 ;
if ( V_247 -> V_810 )
F_62 ( V_1 , V_5 ) ;
}
F_34 ( 1000 ) ;
V_808 = F_1 ( V_1 , V_209 ) ;
F_143 ( V_1 , V_807 , V_808 ) ;
return 0 ;
}
static int F_144 ( struct V_796 * V_25 )
{
int V_811 = F_134 ( V_25 , 0 ) ;
if ( V_811 < 0 ) {
if ( V_811 != - V_812 )
F_39 ( & V_25 -> V_24 , L_65 ) ;
return V_811 ;
}
return F_145 ( V_25 , & V_813 ) ;
}
static int F_146 ( struct V_796 * V_25 )
{
struct V_684 * V_686 = F_147 ( V_25 ) ;
struct V_1 * V_1 = V_686 -> V_29 ;
if ( F_115 ( & V_1 -> V_206 ) )
F_98 ( & V_1 -> V_206 ) ;
return F_148 ( V_25 ) ;
}
