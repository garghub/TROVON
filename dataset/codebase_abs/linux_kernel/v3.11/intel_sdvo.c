static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_4 ) ;
}
static struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( F_4 ( V_6 ) ,
struct V_1 , V_4 ) ;
}
static struct V_7 * F_5 ( struct V_5 * V_6 )
{
return F_2 ( F_6 ( V_6 ) , struct V_7 , V_4 ) ;
}
static void F_7 ( struct V_1 * V_1 , T_1 V_8 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_14 = V_8 , V_15 = V_8 ;
int V_16 ;
if ( V_1 -> V_17 == V_18 ) {
F_8 ( V_1 -> V_17 , V_8 ) ;
F_9 ( V_1 -> V_17 ) ;
return;
}
if ( V_1 -> V_17 == V_19 )
V_15 = F_9 ( V_20 ) ;
else
V_14 = F_9 ( V_19 ) ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
{
F_8 ( V_19 , V_14 ) ;
F_9 ( V_19 ) ;
F_8 ( V_20 , V_15 ) ;
F_9 ( V_20 ) ;
}
}
static bool F_10 ( struct V_1 * V_1 , T_2 V_21 , T_2 * V_22 )
{
struct V_23 V_24 [] = {
{
. V_21 = V_1 -> V_25 ,
. V_26 = 0 ,
. V_27 = 1 ,
. V_28 = & V_21 ,
} ,
{
. V_21 = V_1 -> V_25 ,
. V_26 = V_29 ,
. V_27 = 1 ,
. V_28 = V_22 ,
}
} ;
int V_30 ;
if ( ( V_30 = F_11 ( V_1 -> V_31 , V_24 , 2 ) ) == 2 )
return true ;
F_12 ( L_1 , V_30 ) ;
return false ;
}
static void F_13 ( struct V_1 * V_1 , T_2 V_32 ,
const void * args , int V_33 )
{
int V_16 ;
F_12 ( L_2 ,
F_14 ( V_1 ) , V_32 ) ;
for ( V_16 = 0 ; V_16 < V_33 ; V_16 ++ )
F_15 ( L_3 , ( ( T_2 * ) args ) [ V_16 ] ) ;
for (; V_16 < 8 ; V_16 ++ )
F_15 ( L_4 ) ;
for ( V_16 = 0 ; V_16 < F_16 ( V_34 ) ; V_16 ++ ) {
if ( V_32 == V_34 [ V_16 ] . V_32 ) {
F_15 ( L_5 , V_34 [ V_16 ] . V_35 ) ;
break;
}
}
if ( V_16 == F_16 ( V_34 ) )
F_15 ( L_6 , V_32 ) ;
F_15 ( L_7 ) ;
}
static bool F_17 ( struct V_1 * V_1 , T_2 V_32 ,
const void * args , int V_33 )
{
T_2 * V_28 , V_36 ;
struct V_23 * V_24 ;
int V_16 , V_30 = true ;
V_28 = F_18 ( V_33 * 2 + 2 , V_37 ) ;
if ( ! V_28 )
return false ;
V_24 = F_19 ( V_33 + 3 , sizeof( * V_24 ) , V_37 ) ;
if ( ! V_24 ) {
F_20 ( V_28 ) ;
return false ;
}
F_13 ( V_1 , V_32 , args , V_33 ) ;
for ( V_16 = 0 ; V_16 < V_33 ; V_16 ++ ) {
V_24 [ V_16 ] . V_21 = V_1 -> V_25 ;
V_24 [ V_16 ] . V_26 = 0 ;
V_24 [ V_16 ] . V_27 = 2 ;
V_24 [ V_16 ] . V_28 = V_28 + 2 * V_16 ;
V_28 [ 2 * V_16 + 0 ] = V_38 - V_16 ;
V_28 [ 2 * V_16 + 1 ] = ( ( T_2 * ) args ) [ V_16 ] ;
}
V_24 [ V_16 ] . V_21 = V_1 -> V_25 ;
V_24 [ V_16 ] . V_26 = 0 ;
V_24 [ V_16 ] . V_27 = 2 ;
V_24 [ V_16 ] . V_28 = V_28 + 2 * V_16 ;
V_28 [ 2 * V_16 + 0 ] = V_39 ;
V_28 [ 2 * V_16 + 1 ] = V_32 ;
V_36 = V_40 ;
V_24 [ V_16 + 1 ] . V_21 = V_1 -> V_25 ;
V_24 [ V_16 + 1 ] . V_26 = 0 ;
V_24 [ V_16 + 1 ] . V_27 = 1 ;
V_24 [ V_16 + 1 ] . V_28 = & V_36 ;
V_24 [ V_16 + 2 ] . V_21 = V_1 -> V_25 ;
V_24 [ V_16 + 2 ] . V_26 = V_29 ;
V_24 [ V_16 + 2 ] . V_27 = 1 ;
V_24 [ V_16 + 2 ] . V_28 = & V_36 ;
V_30 = F_11 ( V_1 -> V_31 , V_24 , V_16 + 3 ) ;
if ( V_30 < 0 ) {
F_12 ( L_8 , V_30 ) ;
V_30 = false ;
goto V_41;
}
if ( V_30 != V_16 + 3 ) {
F_12 ( L_9 , V_30 , V_16 + 3 ) ;
V_30 = false ;
}
V_41:
F_20 ( V_24 ) ;
F_20 ( V_28 ) ;
return V_30 ;
}
static bool F_21 ( struct V_1 * V_1 ,
void * V_42 , int V_43 )
{
T_2 V_44 = 15 ;
T_2 V_36 ;
int V_16 ;
F_12 ( L_10 , F_14 ( V_1 ) ) ;
if ( ! F_10 ( V_1 ,
V_40 ,
& V_36 ) )
goto V_45;
while ( V_36 == V_46 && -- V_44 ) {
if ( V_44 < 10 )
F_22 ( 15 ) ;
else
F_23 ( 15 ) ;
if ( ! F_10 ( V_1 ,
V_40 ,
& V_36 ) )
goto V_45;
}
if ( V_36 <= V_47 )
F_15 ( L_5 , V_48 [ V_36 ] ) ;
else
F_15 ( L_11 , V_36 ) ;
if ( V_36 != V_49 )
goto V_45;
for ( V_16 = 0 ; V_16 < V_43 ; V_16 ++ ) {
if ( ! F_10 ( V_1 ,
V_50 + V_16 ,
& ( ( T_2 * ) V_42 ) [ V_16 ] ) )
goto V_45;
F_15 ( L_12 , ( ( T_2 * ) V_42 ) [ V_16 ] ) ;
}
F_15 ( L_7 ) ;
return true ;
V_45:
F_15 ( L_13 ) ;
return false ;
}
static int F_24 ( struct V_51 * V_52 )
{
if ( V_52 -> clock >= 100000 )
return 1 ;
else if ( V_52 -> clock >= 50000 )
return 2 ;
else
return 4 ;
}
static bool F_25 ( struct V_1 * V_1 ,
T_2 V_53 )
{
return F_17 ( V_1 ,
V_54 ,
& V_53 , 1 ) ;
}
static bool F_26 ( struct V_1 * V_1 , T_2 V_32 , const void * V_55 , int V_27 )
{
if ( ! F_17 ( V_1 , V_32 , V_55 , V_27 ) )
return false ;
return F_21 ( V_1 , NULL , 0 ) ;
}
static bool
F_27 ( struct V_1 * V_1 , T_2 V_32 , void * V_56 , int V_27 )
{
if ( ! F_17 ( V_1 , V_32 , NULL , 0 ) )
return false ;
return F_21 ( V_1 , V_56 , V_27 ) ;
}
static bool F_28 ( struct V_1 * V_1 )
{
struct V_57 V_58 = { 0 } ;
return F_26 ( V_1 ,
V_59 ,
& V_58 , sizeof( V_58 ) ) ;
}
static bool F_29 ( struct V_1 * V_1 , bool * V_60 , bool * V_61 )
{
struct V_62 V_42 ;
F_30 ( sizeof( V_42 ) != 1 ) ;
if ( ! F_27 ( V_1 , V_63 ,
& V_42 , sizeof( V_42 ) ) )
return false ;
* V_60 = V_42 . V_64 ;
* V_61 = V_42 . V_65 ;
return true ;
}
static bool F_31 ( struct V_1 * V_1 ,
T_3 V_66 )
{
return F_26 ( V_1 ,
V_67 ,
& V_66 , sizeof( V_66 ) ) ;
}
static bool F_32 ( struct V_1 * V_1 ,
T_3 * V_66 )
{
return F_27 ( V_1 ,
V_68 ,
V_66 , sizeof( * V_66 ) ) ;
}
static bool F_33 ( struct V_1 * V_1 ,
int V_52 )
{
T_2 V_69 = V_70 ;
switch ( V_52 ) {
case V_71 :
V_69 = V_70 ;
break;
case V_72 :
V_69 = V_73 ;
break;
case V_74 :
V_69 = V_75 ;
break;
case V_76 :
V_69 = V_77 ;
break;
}
return F_26 ( V_1 ,
V_78 , & V_69 , sizeof( V_69 ) ) ;
}
static bool F_34 ( struct V_1 * V_1 ,
int * V_79 ,
int * V_80 )
{
struct V_81 V_82 ;
F_30 ( sizeof( V_82 ) != 4 ) ;
if ( ! F_27 ( V_1 ,
V_83 ,
& V_82 , sizeof( V_82 ) ) )
return false ;
* V_79 = V_82 . V_84 * 10 ;
* V_80 = V_82 . V_85 * 10 ;
return true ;
}
static bool F_35 ( struct V_1 * V_1 ,
T_3 V_66 )
{
return F_26 ( V_1 ,
V_86 ,
& V_66 , sizeof( V_66 ) ) ;
}
static bool F_36 ( struct V_1 * V_1 , T_2 V_32 ,
struct V_87 * V_88 )
{
return F_26 ( V_1 , V_32 , & V_88 -> V_89 , sizeof( V_88 -> V_89 ) ) &&
F_26 ( V_1 , V_32 + 1 , & V_88 -> V_90 , sizeof( V_88 -> V_90 ) ) ;
}
static bool F_37 ( struct V_1 * V_1 , T_2 V_32 ,
struct V_87 * V_88 )
{
return F_27 ( V_1 , V_32 , & V_88 -> V_89 , sizeof( V_88 -> V_89 ) ) &&
F_27 ( V_1 , V_32 + 1 , & V_88 -> V_90 , sizeof( V_88 -> V_90 ) ) ;
}
static bool F_38 ( struct V_1 * V_1 ,
struct V_87 * V_88 )
{
return F_36 ( V_1 ,
V_91 , V_88 ) ;
}
static bool F_39 ( struct V_1 * V_1 ,
struct V_87 * V_88 )
{
return F_36 ( V_1 ,
V_92 , V_88 ) ;
}
static bool F_40 ( struct V_1 * V_1 ,
struct V_87 * V_88 )
{
return F_37 ( V_1 ,
V_93 , V_88 ) ;
}
static bool
F_41 ( struct V_1 * V_1 ,
T_4 clock ,
T_4 V_94 ,
T_4 V_95 )
{
struct V_96 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . clock = clock ;
args . V_94 = V_94 ;
args . V_95 = V_95 ;
args . V_97 = 0 ;
if ( V_1 -> V_98 &&
( V_1 -> V_99 -> V_100 != V_94 ||
V_1 -> V_99 -> V_101 != V_95 ) )
args . V_102 = 1 ;
return F_26 ( V_1 ,
V_103 ,
& args , sizeof( args ) ) ;
}
static bool F_42 ( struct V_1 * V_1 ,
struct V_87 * V_88 )
{
F_30 ( sizeof( V_88 -> V_89 ) != 8 ) ;
F_30 ( sizeof( V_88 -> V_90 ) != 8 ) ;
return F_27 ( V_1 , V_104 ,
& V_88 -> V_89 , sizeof( V_88 -> V_89 ) ) &&
F_27 ( V_1 , V_105 ,
& V_88 -> V_90 , sizeof( V_88 -> V_90 ) ) ;
}
static bool F_43 ( struct V_1 * V_1 , T_2 V_8 )
{
return F_26 ( V_1 , V_106 , & V_8 , 1 ) ;
}
static void F_44 ( struct V_87 * V_88 ,
const struct V_51 * V_52 )
{
T_4 V_94 , V_95 ;
T_4 V_107 , V_108 , V_109 , V_110 ;
T_4 V_111 , V_112 ;
int V_113 ;
V_94 = V_52 -> V_100 ;
V_95 = V_52 -> V_101 ;
V_107 = V_52 -> V_114 - V_52 -> V_100 ;
V_108 = V_52 -> V_115 - V_52 -> V_116 ;
V_109 = V_52 -> V_117 - V_52 -> V_101 ;
V_110 = V_52 -> V_118 - V_52 -> V_119 ;
V_111 = V_52 -> V_116 - V_52 -> V_100 ;
V_112 = V_52 -> V_119 - V_52 -> V_101 ;
V_113 = V_52 -> clock ;
V_113 /= 10 ;
V_88 -> V_89 . clock = V_113 ;
V_88 -> V_89 . V_120 = V_94 & 0xff ;
V_88 -> V_89 . V_121 = V_107 & 0xff ;
V_88 -> V_89 . V_122 = ( ( ( V_94 >> 8 ) & 0xf ) << 4 ) |
( ( V_107 >> 8 ) & 0xf ) ;
V_88 -> V_89 . V_123 = V_95 & 0xff ;
V_88 -> V_89 . V_124 = V_109 & 0xff ;
V_88 -> V_89 . V_125 = ( ( ( V_95 >> 8 ) & 0xf ) << 4 ) |
( ( V_109 >> 8 ) & 0xf ) ;
V_88 -> V_90 . V_126 = V_111 & 0xff ;
V_88 -> V_90 . V_127 = V_108 & 0xff ;
V_88 -> V_90 . V_128 = ( V_112 & 0xf ) << 4 |
( V_110 & 0xf ) ;
V_88 -> V_90 . V_129 = ( ( V_111 & 0x300 ) >> 2 ) |
( ( V_108 & 0x300 ) >> 4 ) | ( ( V_112 & 0x30 ) >> 2 ) |
( ( V_110 & 0x30 ) >> 4 ) ;
V_88 -> V_90 . V_130 = 0x18 ;
if ( V_52 -> V_26 & V_131 )
V_88 -> V_90 . V_130 |= V_132 ;
if ( V_52 -> V_26 & V_133 )
V_88 -> V_90 . V_130 |= V_134 ;
if ( V_52 -> V_26 & V_135 )
V_88 -> V_90 . V_130 |= V_136 ;
V_88 -> V_90 . V_137 = 0 ;
V_88 -> V_90 . V_138 = V_112 & 0xc0 ;
V_88 -> V_90 . V_139 = 0 ;
}
static void F_45 ( struct V_51 * V_52 ,
const struct V_87 * V_88 )
{
V_52 -> V_100 = V_88 -> V_89 . V_120 ;
V_52 -> V_100 += ( ( V_88 -> V_89 . V_122 >> 4 ) & 0x0f ) << 8 ;
V_52 -> V_116 = V_52 -> V_100 + V_88 -> V_90 . V_126 ;
V_52 -> V_116 += ( V_88 -> V_90 . V_129 & 0xc0 ) << 2 ;
V_52 -> V_115 = V_52 -> V_116 + V_88 -> V_90 . V_127 ;
V_52 -> V_115 += ( V_88 -> V_90 . V_129 & 0x30 ) << 4 ;
V_52 -> V_114 = V_52 -> V_100 + V_88 -> V_89 . V_121 ;
V_52 -> V_114 += ( V_88 -> V_89 . V_122 & 0xf ) << 8 ;
V_52 -> V_101 = V_88 -> V_89 . V_123 ;
V_52 -> V_101 += ( ( V_88 -> V_89 . V_125 >> 4 ) & 0x0f ) << 8 ;
V_52 -> V_119 = V_52 -> V_101 ;
V_52 -> V_119 += ( V_88 -> V_90 . V_128 >> 4 ) & 0xf ;
V_52 -> V_119 += ( V_88 -> V_90 . V_129 & 0x0c ) << 2 ;
V_52 -> V_119 += V_88 -> V_90 . V_138 & 0xc0 ;
V_52 -> V_118 = V_52 -> V_119 +
( V_88 -> V_90 . V_128 & 0xf ) ;
V_52 -> V_118 += ( V_88 -> V_90 . V_129 & 0x3 ) << 4 ;
V_52 -> V_117 = V_52 -> V_101 + V_88 -> V_89 . V_124 ;
V_52 -> V_117 += ( V_88 -> V_89 . V_125 & 0xf ) << 8 ;
V_52 -> clock = V_88 -> V_89 . clock * 10 ;
V_52 -> V_26 &= ~ ( V_133 | V_135 ) ;
if ( V_88 -> V_90 . V_130 & V_132 )
V_52 -> V_26 |= V_131 ;
if ( V_88 -> V_90 . V_130 & V_134 )
V_52 -> V_26 |= V_133 ;
if ( V_88 -> V_90 . V_130 & V_136 )
V_52 -> V_26 |= V_135 ;
}
static bool F_46 ( struct V_1 * V_1 )
{
struct V_140 V_141 ;
F_30 ( sizeof( V_141 ) != 2 ) ;
return F_27 ( V_1 ,
V_142 ,
& V_141 , sizeof( V_141 ) ) ;
}
static bool F_47 ( struct V_1 * V_1 ,
T_5 V_52 )
{
return F_26 ( V_1 , V_143 , & V_52 , 1 ) ;
}
static bool F_48 ( struct V_1 * V_1 ,
T_5 V_52 )
{
return F_26 ( V_1 , V_144 , & V_52 , 1 ) ;
}
static bool F_49 ( struct V_1 * V_1 ,
unsigned V_145 , T_5 V_146 ,
T_5 * V_55 , unsigned V_147 )
{
T_5 V_148 [ 2 ] = { V_145 , 0 } ;
T_5 V_149 , V_150 [ 8 ] ;
int V_16 ;
if ( ! F_26 ( V_1 ,
V_151 ,
V_148 , 2 ) )
return false ;
if ( ! F_27 ( V_1 , V_152 ,
& V_149 , 1 ) )
return false ;
V_149 ++ ;
F_12 ( L_14 ,
V_145 , V_147 , V_149 ) ;
for ( V_16 = 0 ; V_16 < V_149 ; V_16 += 8 ) {
memset ( V_150 , 0 , 8 ) ;
if ( V_16 < V_147 )
memcpy ( V_150 , V_55 + V_16 , F_50 ( unsigned , 8 , V_147 - V_16 ) ) ;
if ( ! F_26 ( V_1 ,
V_153 ,
V_150 , 8 ) )
return false ;
}
return F_26 ( V_1 ,
V_154 ,
& V_146 , 1 ) ;
}
static bool F_51 ( struct V_1 * V_1 ,
const struct V_51 * V_155 )
{
struct V_156 V_157 = {
. type = V_158 ,
. V_159 = V_160 ,
. V_27 = V_161 ,
} ;
T_5 V_162 [ 4 + sizeof( V_157 . V_163 . V_164 ) ] ;
struct V_165 * V_165 = F_52 ( V_1 -> V_4 . V_4 . V_166 ) ;
if ( V_1 -> V_167 ) {
if ( V_165 -> V_168 . V_169 )
V_157 . V_163 . V_164 . V_170 |= V_171 ;
else
V_157 . V_163 . V_164 . V_170 |= V_172 ;
}
V_157 . V_163 . V_164 . V_173 = F_53 ( V_155 ) ;
F_54 ( & V_157 ) ;
memcpy ( V_162 , & V_157 , 3 ) ;
V_162 [ 3 ] = V_157 . V_174 ;
memcpy ( & V_162 [ 4 ] , & V_157 . V_163 , sizeof( V_157 . V_163 . V_164 ) ) ;
return F_49 ( V_1 , V_175 ,
V_176 ,
V_162 , sizeof( V_162 ) ) ;
}
static bool F_55 ( struct V_1 * V_1 )
{
struct V_177 V_178 ;
T_6 V_179 ;
V_179 = 1 << V_1 -> V_180 ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
memcpy ( & V_178 , & V_179 , V_84 ( sizeof( V_178 ) , sizeof( V_179 ) ) ) ;
F_30 ( sizeof( V_178 ) != 6 ) ;
return F_26 ( V_1 ,
V_181 ,
& V_178 , sizeof( V_178 ) ) ;
}
static bool
F_56 ( struct V_1 * V_1 ,
const struct V_51 * V_52 )
{
struct V_87 V_182 ;
if ( ! F_35 ( V_1 ,
V_1 -> V_183 ) )
return false ;
F_44 ( & V_182 , V_52 ) ;
if ( ! F_39 ( V_1 , & V_182 ) )
return false ;
return true ;
}
static bool
F_57 ( struct V_1 * V_1 ,
const struct V_51 * V_52 ,
struct V_51 * V_155 )
{
struct V_87 V_184 ;
if ( ! F_28 ( V_1 ) )
return false ;
if ( ! F_41 ( V_1 ,
V_52 -> clock / 10 ,
V_52 -> V_100 ,
V_52 -> V_101 ) )
return false ;
if ( ! F_42 ( V_1 ,
& V_184 ) )
return false ;
F_45 ( V_155 , & V_184 ) ;
V_1 -> V_185 = V_184 . V_90 . V_137 ;
return true ;
}
static void F_58 ( struct V_186 * V_187 )
{
unsigned V_188 = V_187 -> V_155 . clock ;
struct V_189 * clock = & V_187 -> V_189 ;
if ( V_188 >= 100000 && V_188 < 140500 ) {
clock -> V_190 = 2 ;
clock -> V_191 = 10 ;
clock -> V_192 = 3 ;
clock -> V_193 = 16 ;
clock -> V_194 = 8 ;
} else if ( V_188 >= 140500 && V_188 <= 200000 ) {
clock -> V_190 = 1 ;
clock -> V_191 = 10 ;
clock -> V_192 = 6 ;
clock -> V_193 = 12 ;
clock -> V_194 = 8 ;
} else {
F_59 ( 1 , L_15 , V_188 ) ;
}
V_187 -> V_195 = true ;
}
static bool F_60 ( struct V_196 * V_3 ,
struct V_186 * V_187 )
{
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
struct V_51 * V_155 = & V_187 -> V_155 ;
struct V_51 * V_52 = & V_187 -> V_197 ;
F_12 ( L_16 ) ;
V_187 -> V_198 = 8 * 3 ;
if ( F_61 ( V_3 -> V_4 . V_10 ) )
V_187 -> V_199 = true ;
if ( V_1 -> V_200 ) {
if ( ! F_56 ( V_1 , V_52 ) )
return false ;
( void ) F_57 ( V_1 ,
V_52 ,
V_155 ) ;
V_187 -> V_201 = true ;
} else if ( V_1 -> V_98 ) {
if ( ! F_56 ( V_1 ,
V_1 -> V_99 ) )
return false ;
( void ) F_57 ( V_1 ,
V_52 ,
V_155 ) ;
}
V_187 -> V_202 =
F_24 ( V_155 ) ;
V_155 -> clock *= V_187 -> V_202 ;
if ( V_1 -> V_203 ) {
if ( V_1 -> V_204 &&
F_53 ( V_155 ) > 1 )
V_1 -> V_205 = V_206 ;
else
V_1 -> V_205 = 0 ;
}
if ( V_1 -> V_205 )
V_187 -> V_169 = true ;
if ( V_1 -> V_200 )
F_58 ( V_187 ) ;
return true ;
}
static void F_62 ( struct V_196 * V_196 )
{
struct V_9 * V_10 = V_196 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_207 * V_166 = V_196 -> V_4 . V_166 ;
struct V_165 * V_165 = F_52 ( V_166 ) ;
struct V_51 * V_155 =
& V_165 -> V_168 . V_155 ;
struct V_51 * V_52 = & V_165 -> V_168 . V_197 ;
struct V_1 * V_1 = F_1 ( & V_196 -> V_4 ) ;
T_1 V_208 ;
struct V_209 V_210 ;
struct V_87 V_184 , V_182 ;
int V_211 ;
if ( ! V_52 )
return;
V_210 . V_212 = V_1 -> V_183 ;
V_210 . V_213 = 0 ;
F_26 ( V_1 ,
V_214 ,
& V_210 , sizeof( V_210 ) ) ;
if ( ! F_35 ( V_1 ,
V_1 -> V_183 ) )
return;
if ( V_1 -> V_98 )
F_44 ( & V_182 ,
V_1 -> V_99 ) ;
else
F_44 ( & V_182 , V_52 ) ;
if ( ! F_39 ( V_1 , & V_182 ) )
F_63 ( L_17 ,
F_14 ( V_1 ) ) ;
if ( ! F_28 ( V_1 ) )
return;
if ( V_1 -> V_204 ) {
F_47 ( V_1 , V_215 ) ;
F_48 ( V_1 ,
V_216 ) ;
F_51 ( V_1 , V_155 ) ;
} else
F_47 ( V_1 , V_217 ) ;
if ( V_1 -> V_200 &&
! F_55 ( V_1 ) )
return;
F_44 ( & V_184 , V_155 ) ;
if ( V_1 -> V_200 || V_1 -> V_98 )
V_184 . V_90 . V_137 = V_1 -> V_185 ;
if ( ! F_38 ( V_1 , & V_184 ) )
F_63 ( L_18 ,
F_14 ( V_1 ) ) ;
switch ( V_165 -> V_168 . V_202 ) {
default:
F_59 ( 1 , L_19 ) ;
case 1 : V_211 = V_218 ; break;
case 2 : V_211 = V_219 ; break;
case 4 : V_211 = V_220 ; break;
}
if ( ! F_43 ( V_1 , V_211 ) )
return;
if ( F_64 ( V_10 ) -> V_221 >= 4 ) {
V_208 = V_222 | V_223 ;
if ( ! F_61 ( V_10 ) && V_1 -> V_224 )
V_208 |= V_1 -> V_205 ;
if ( F_64 ( V_10 ) -> V_221 < 5 )
V_208 |= V_225 ;
} else {
V_208 = F_9 ( V_1 -> V_17 ) ;
switch ( V_1 -> V_17 ) {
case V_19 :
V_208 &= V_226 ;
break;
case V_20 :
V_208 &= V_227 ;
break;
}
V_208 |= ( 9 << 19 ) | V_225 ;
}
if ( F_65 ( V_10 ) >= V_228 )
V_208 |= F_66 ( V_165 -> V_229 ) ;
else
V_208 |= F_67 ( V_165 -> V_229 ) ;
if ( V_1 -> V_230 )
V_208 |= V_231 ;
if ( F_64 ( V_10 ) -> V_221 >= 4 ) {
} else if ( F_68 ( V_10 ) || F_69 ( V_10 ) || F_70 ( V_10 ) ) {
} else {
V_208 |= ( V_165 -> V_168 . V_202 - 1 )
<< V_232 ;
}
if ( V_184 . V_90 . V_137 & V_233 &&
F_64 ( V_10 ) -> V_221 < 5 )
V_208 |= V_234 ;
F_7 ( V_1 , V_208 ) ;
}
static bool F_71 ( struct V_235 * V_6 )
{
struct V_7 * V_7 =
F_5 ( & V_6 -> V_4 ) ;
struct V_1 * V_1 = F_3 ( & V_6 -> V_4 ) ;
T_3 V_236 = 0 ;
F_32 ( V_1 , & V_236 ) ;
if ( V_236 & V_7 -> V_237 )
return true ;
else
return false ;
}
static bool F_72 ( struct V_196 * V_3 ,
enum V_229 * V_229 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
T_3 V_236 = 0 ;
T_1 V_150 ;
V_150 = F_9 ( V_1 -> V_17 ) ;
F_32 ( V_1 , & V_236 ) ;
if ( ! ( V_150 & V_238 ) && ( V_236 == 0 ) )
return false ;
if ( F_73 ( V_10 ) )
* V_229 = F_74 ( V_150 ) ;
else
* V_229 = F_75 ( V_150 ) ;
return true ;
}
static void F_76 ( struct V_196 * V_3 ,
struct V_186 * V_187 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
struct V_87 V_88 ;
int V_239 = 0 ;
T_1 V_26 = 0 , V_208 ;
T_2 V_8 ;
bool V_30 ;
V_30 = F_40 ( V_1 , & V_88 ) ;
if ( ! V_30 ) {
F_77 ( L_20 ) ;
V_187 -> V_240 |= V_241 ;
} else {
if ( V_88 . V_90 . V_130 & V_134 )
V_26 |= V_133 ;
else
V_26 |= V_242 ;
if ( V_88 . V_90 . V_130 & V_136 )
V_26 |= V_135 ;
else
V_26 |= V_243 ;
}
V_187 -> V_155 . V_26 |= V_26 ;
if ( F_78 ( V_10 ) || F_79 ( V_10 ) ) {
V_208 = F_9 ( V_1 -> V_17 ) ;
V_187 -> V_202 =
( ( V_208 & V_244 )
>> V_232 ) + 1 ;
}
F_27 ( V_1 , V_245 , & V_8 , 1 ) ;
switch ( V_8 ) {
case V_218 :
V_239 = 1 ;
break;
case V_219 :
V_239 = 2 ;
break;
case V_220 :
V_239 = 4 ;
break;
}
if( F_61 ( V_10 ) )
return;
F_59 ( V_239 != V_187 -> V_202 ,
L_21 ,
V_187 -> V_202 , V_239 ) ;
}
static void F_80 ( struct V_196 * V_3 )
{
struct V_11 * V_12 = V_3 -> V_4 . V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
T_1 V_246 ;
F_31 ( V_1 , 0 ) ;
if ( 0 )
F_33 ( V_1 ,
V_76 ) ;
V_246 = F_9 ( V_1 -> V_17 ) ;
if ( ( V_246 & V_238 ) != 0 ) {
if ( F_81 ( V_3 -> V_4 . V_10 ) ) {
struct V_207 * V_166 = V_3 -> V_4 . V_166 ;
int V_229 = V_166 ? F_52 ( V_166 ) -> V_229 : - 1 ;
if ( V_246 & V_247 ) {
V_246 &= ~ V_247 ;
F_8 ( V_1 -> V_17 , V_246 ) ;
F_82 ( V_1 -> V_17 ) ;
F_8 ( V_1 -> V_17 , V_246 ) ;
F_82 ( V_1 -> V_17 ) ;
if ( V_166 )
F_83 ( V_3 -> V_4 . V_10 , V_229 ) ;
else
F_22 ( 50 ) ;
}
}
F_7 ( V_1 , V_246 & ~ V_238 ) ;
}
}
static void F_84 ( struct V_196 * V_3 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
struct V_165 * V_165 = F_52 ( V_3 -> V_4 . V_166 ) ;
T_1 V_246 ;
bool V_248 , V_249 ;
int V_16 ;
T_2 V_36 ;
V_246 = F_9 ( V_1 -> V_17 ) ;
if ( ( V_246 & V_238 ) == 0 ) {
if ( F_81 ( V_10 ) )
V_246 |= F_67 ( V_165 -> V_229 ) ;
F_7 ( V_1 , V_246 | V_238 ) ;
}
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
F_83 ( V_10 , V_165 -> V_229 ) ;
V_36 = F_29 ( V_1 , & V_248 , & V_249 ) ;
if ( V_36 == V_49 && ! V_248 ) {
F_12 ( L_22
L_23 , F_14 ( V_1 ) ) ;
}
if ( 0 )
F_33 ( V_1 ,
V_71 ) ;
F_31 ( V_1 , V_1 -> V_183 ) ;
}
static void F_85 ( struct V_5 * V_6 , int V_52 )
{
struct V_207 * V_166 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_52 != V_71 )
V_52 = V_76 ;
if ( V_52 == V_6 -> V_250 )
return;
V_6 -> V_250 = V_52 ;
V_166 = V_1 -> V_4 . V_4 . V_166 ;
if ( ! V_166 ) {
V_1 -> V_4 . V_251 = false ;
return;
}
if ( V_52 != V_71 ) {
F_31 ( V_1 , 0 ) ;
if ( 0 )
F_33 ( V_1 , V_52 ) ;
V_1 -> V_4 . V_251 = false ;
F_86 ( V_166 ) ;
} else {
V_1 -> V_4 . V_251 = true ;
F_86 ( V_166 ) ;
if ( 0 )
F_33 ( V_1 , V_52 ) ;
F_31 ( V_1 , V_1 -> V_183 ) ;
}
F_87 ( V_6 -> V_10 ) ;
}
static int F_88 ( struct V_5 * V_6 ,
struct V_51 * V_52 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_52 -> V_26 & V_252 )
return V_253 ;
if ( V_1 -> V_254 > V_52 -> clock )
return V_255 ;
if ( V_1 -> V_256 < V_52 -> clock )
return V_257 ;
if ( V_1 -> V_98 ) {
if ( V_52 -> V_100 > V_1 -> V_99 -> V_100 )
return V_258 ;
if ( V_52 -> V_101 > V_1 -> V_99 -> V_101 )
return V_258 ;
}
return V_259 ;
}
static bool F_89 ( struct V_1 * V_1 , struct V_260 * V_261 )
{
F_30 ( sizeof( * V_261 ) != 8 ) ;
if ( ! F_27 ( V_1 ,
V_262 ,
V_261 , sizeof( * V_261 ) ) )
return false ;
F_12 ( L_24
L_25
L_26
L_27
L_28
L_29
L_30
L_31
L_32
L_33
L_34
L_35
L_36 ,
V_261 -> V_263 ,
V_261 -> V_264 ,
V_261 -> V_265 ,
V_261 -> V_266 ,
V_261 -> V_267 ,
V_261 -> V_268 ,
V_261 -> V_269 ,
V_261 -> V_270 ,
V_261 -> V_271 ,
V_261 -> V_272 ,
V_261 -> V_273 ,
V_261 -> V_274 ) ;
return true ;
}
static T_4 F_90 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
T_4 V_275 ;
if ( F_68 ( V_10 ) || F_69 ( V_10 ) )
return 0 ;
if ( ! F_27 ( V_1 , V_276 ,
& V_275 , sizeof( V_275 ) ) )
return 0 ;
return V_275 ;
}
static void F_91 ( struct V_196 * V_3 )
{
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
F_17 ( V_1 , V_277 ,
& V_1 -> V_278 , 2 ) ;
}
static bool
F_92 ( struct V_1 * V_1 )
{
return F_93 ( V_1 -> V_261 . V_274 ) > 1 ;
}
static struct V_279 *
F_94 ( struct V_5 * V_6 )
{
struct V_1 * V_280 = F_3 ( V_6 ) ;
return F_95 ( V_6 , & V_280 -> V_281 ) ;
}
static struct V_279 *
F_96 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
return F_95 ( V_6 ,
F_97 ( V_12 ,
V_12 -> V_282 . V_283 ) ) ;
}
static enum V_284
F_98 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
enum V_284 V_36 ;
struct V_279 * V_279 ;
V_279 = F_94 ( V_6 ) ;
if ( V_279 == NULL && F_92 ( V_1 ) ) {
T_2 V_281 , V_285 = V_1 -> V_53 ;
for ( V_281 = V_1 -> V_53 >> 1 ; V_281 > 1 ; V_281 >>= 1 ) {
V_1 -> V_53 = V_281 ;
V_279 = F_94 ( V_6 ) ;
if ( V_279 )
break;
}
if ( V_279 == NULL )
V_1 -> V_53 = V_285 ;
}
if ( V_279 == NULL )
V_279 = F_96 ( V_6 ) ;
V_36 = V_286 ;
if ( V_279 != NULL ) {
if ( V_279 -> V_287 & V_288 ) {
V_36 = V_289 ;
if ( V_1 -> V_224 ) {
V_1 -> V_204 = F_99 ( V_279 ) ;
V_1 -> V_230 = F_100 ( V_279 ) ;
V_1 -> V_167 =
F_101 ( V_279 ) ;
}
} else
V_36 = V_290 ;
F_20 ( V_279 ) ;
}
if ( V_36 == V_289 ) {
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_291 != V_292 )
V_1 -> V_230 = ( V_7 -> V_291 == V_293 ) ;
}
return V_36 ;
}
static bool
F_102 ( struct V_7 * V_280 ,
struct V_279 * V_279 )
{
bool V_294 = ! ! ( V_279 -> V_287 & V_288 ) ;
bool V_295 = ! ! F_103 ( V_280 ) ;
F_12 ( L_37 ,
V_295 , V_294 ) ;
return V_295 == V_294 ;
}
static enum V_284
F_104 ( struct V_5 * V_6 , bool V_296 )
{
T_4 V_42 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
enum V_284 V_30 ;
if ( ! F_27 ( V_1 ,
V_297 ,
& V_42 , 2 ) )
return V_286 ;
F_12 ( L_38 ,
V_42 & 0xff , V_42 >> 8 ,
V_7 -> V_237 ) ;
if ( V_42 == 0 )
return V_290 ;
V_1 -> V_183 = V_42 ;
V_1 -> V_204 = false ;
V_1 -> V_230 = false ;
V_1 -> V_167 = false ;
if ( ( V_7 -> V_237 & V_42 ) == 0 )
V_30 = V_290 ;
else if ( F_105 ( V_7 ) )
V_30 = F_98 ( V_6 ) ;
else {
struct V_279 * V_279 ;
V_279 = F_94 ( V_6 ) ;
if ( V_279 == NULL )
V_279 = F_96 ( V_6 ) ;
if ( V_279 != NULL ) {
if ( F_102 ( V_7 ,
V_279 ) )
V_30 = V_289 ;
else
V_30 = V_290 ;
F_20 ( V_279 ) ;
} else
V_30 = V_289 ;
}
if ( V_30 == V_289 ) {
V_1 -> V_200 = false ;
V_1 -> V_98 = false ;
if ( V_42 & V_298 )
V_1 -> V_200 = true ;
if ( V_42 & V_299 )
V_1 -> V_98 = V_1 -> V_99 != NULL ;
}
return V_30 ;
}
static void F_106 ( struct V_5 * V_6 )
{
struct V_279 * V_279 ;
V_279 = F_94 ( V_6 ) ;
if ( V_279 == NULL )
V_279 = F_96 ( V_6 ) ;
if ( V_279 != NULL ) {
if ( F_102 ( F_5 ( V_6 ) ,
V_279 ) ) {
F_107 ( V_6 , V_279 ) ;
F_108 ( V_6 , V_279 ) ;
}
F_20 ( V_279 ) ;
}
}
static void F_109 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_300 V_301 ;
T_6 V_302 = 0 , V_179 = 0 ;
int V_16 ;
V_179 = 1 << V_1 -> V_180 ;
memcpy ( & V_301 , & V_179 ,
V_84 ( sizeof( V_179 ) , sizeof( struct V_300 ) ) ) ;
if ( ! F_35 ( V_1 , V_1 -> V_183 ) )
return;
F_30 ( sizeof( V_301 ) != 3 ) ;
if ( ! F_17 ( V_1 ,
V_303 ,
& V_301 , sizeof( V_301 ) ) )
return;
if ( ! F_21 ( V_1 , & V_302 , 3 ) )
return;
for ( V_16 = 0 ; V_16 < F_16 ( V_304 ) ; V_16 ++ )
if ( V_302 & ( 1 << V_16 ) ) {
struct V_51 * V_305 ;
V_305 = F_110 ( V_6 -> V_10 ,
& V_304 [ V_16 ] ) ;
if ( V_305 )
F_111 ( V_6 , V_305 ) ;
}
}
static void F_112 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
struct V_51 * V_306 ;
if ( V_12 -> V_282 . V_307 != NULL ) {
V_306 = F_110 ( V_6 -> V_10 ,
V_12 -> V_282 . V_307 ) ;
if ( V_306 != NULL ) {
V_306 -> type = ( V_308 |
V_309 ) ;
F_111 ( V_6 , V_306 ) ;
}
}
F_113 ( V_6 , & V_1 -> V_281 ) ;
F_114 (newmode, &connector->probed_modes, head) {
if ( V_306 -> type & V_308 ) {
V_1 -> V_99 =
F_110 ( V_6 -> V_10 , V_306 ) ;
V_1 -> V_98 = true ;
break;
}
}
}
static int F_115 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( F_116 ( V_7 ) )
F_109 ( V_6 ) ;
else if ( F_117 ( V_7 ) )
F_112 ( V_6 ) ;
else
F_106 ( V_6 ) ;
return ! F_118 ( & V_6 -> V_310 ) ;
}
static void
F_119 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
if ( V_7 -> V_311 )
F_120 ( V_10 , V_7 -> V_311 ) ;
if ( V_7 -> V_312 )
F_120 ( V_10 , V_7 -> V_312 ) ;
if ( V_7 -> V_313 )
F_120 ( V_10 , V_7 -> V_313 ) ;
if ( V_7 -> V_314 )
F_120 ( V_10 , V_7 -> V_314 ) ;
if ( V_7 -> V_315 )
F_120 ( V_10 , V_7 -> V_315 ) ;
if ( V_7 -> V_316 )
F_120 ( V_10 , V_7 -> V_316 ) ;
if ( V_7 -> V_317 )
F_120 ( V_10 , V_7 -> V_317 ) ;
if ( V_7 -> V_318 )
F_120 ( V_10 , V_7 -> V_318 ) ;
if ( V_7 -> V_319 )
F_120 ( V_10 , V_7 -> V_319 ) ;
if ( V_7 -> V_320 )
F_120 ( V_10 , V_7 -> V_320 ) ;
if ( V_7 -> V_321 )
F_120 ( V_10 , V_7 -> V_321 ) ;
if ( V_7 -> V_322 )
F_120 ( V_10 , V_7 -> V_322 ) ;
if ( V_7 -> V_323 )
F_120 ( V_10 , V_7 -> V_323 ) ;
if ( V_7 -> V_324 )
F_120 ( V_10 , V_7 -> V_324 ) ;
if ( V_7 -> V_325 )
F_120 ( V_10 , V_7 -> V_325 ) ;
if ( V_7 -> V_326 )
F_120 ( V_10 , V_7 -> V_326 ) ;
if ( V_7 -> V_327 )
F_120 ( V_10 , V_7 -> V_327 ) ;
}
static void F_121 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_328 )
F_120 ( V_6 -> V_10 ,
V_7 -> V_328 ) ;
F_119 ( V_6 ) ;
F_122 ( V_6 ) ;
F_123 ( V_6 ) ;
F_20 ( V_7 ) ;
}
static bool F_124 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_279 * V_279 ;
bool V_329 = false ;
if ( ! V_1 -> V_224 )
return false ;
V_279 = F_94 ( V_6 ) ;
if ( V_279 != NULL && V_279 -> V_287 & V_288 )
V_329 = F_100 ( V_279 ) ;
F_20 ( V_279 ) ;
return V_329 ;
}
static int
F_125 ( struct V_5 * V_6 ,
struct V_330 * V_331 ,
T_7 V_8 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
T_4 V_332 ;
T_5 V_32 ;
int V_30 ;
V_30 = F_126 ( & V_6 -> V_4 , V_331 , V_8 ) ;
if ( V_30 )
return V_30 ;
if ( V_331 == V_12 -> V_333 ) {
int V_16 = V_8 ;
bool V_329 ;
if ( V_16 == V_7 -> V_291 )
return 0 ;
V_7 -> V_291 = V_16 ;
if ( V_16 == V_292 )
V_329 = F_124 ( V_6 ) ;
else
V_329 = ( V_16 == V_293 ) ;
if ( V_329 == V_1 -> V_230 )
return 0 ;
V_1 -> V_230 = V_329 ;
goto V_334;
}
if ( V_331 == V_12 -> V_335 ) {
bool V_336 = V_1 -> V_203 ;
T_6 V_337 = V_1 -> V_205 ;
switch ( V_8 ) {
case V_338 :
V_1 -> V_203 = true ;
break;
case V_339 :
V_1 -> V_203 = false ;
V_1 -> V_205 = 0 ;
break;
case V_340 :
V_1 -> V_203 = false ;
V_1 -> V_205 = V_206 ;
break;
default:
return - V_341 ;
}
if ( V_336 == V_1 -> V_203 &&
V_337 == V_1 -> V_205 )
return 0 ;
goto V_334;
}
#define F_127 ( V_35 , T_8 ) \
if (intel_sdvo_connector->name == property) { \
if (intel_sdvo_connector->cur_##name == temp_value) return 0; \
if (intel_sdvo_connector->max_##name < temp_value) return -EINVAL; \
cmd = SDVO_CMD_SET_##NAME; \
intel_sdvo_connector->cur_##name = temp_value; \
goto set_value; \
}
if ( V_331 == V_7 -> V_328 ) {
if ( V_8 >= V_342 )
return - V_341 ;
if ( V_1 -> V_180 ==
V_7 -> V_343 [ V_8 ] )
return 0 ;
V_1 -> V_180 = V_7 -> V_343 [ V_8 ] ;
goto V_334;
} else if ( F_128 ( V_7 ) ) {
V_332 = V_8 ;
if ( V_7 -> V_311 == V_331 ) {
F_126 ( & V_6 -> V_4 ,
V_7 -> V_312 , V_8 ) ;
if ( V_7 -> V_344 == V_332 )
return 0 ;
V_7 -> V_344 = V_332 ;
V_7 -> V_345 = V_332 ;
V_332 = V_7 -> V_346 -
V_7 -> V_344 ;
V_32 = V_347 ;
goto V_348;
} else if ( V_7 -> V_312 == V_331 ) {
F_126 ( & V_6 -> V_4 ,
V_7 -> V_311 , V_8 ) ;
if ( V_7 -> V_345 == V_332 )
return 0 ;
V_7 -> V_344 = V_332 ;
V_7 -> V_345 = V_332 ;
V_332 = V_7 -> V_346 -
V_7 -> V_344 ;
V_32 = V_347 ;
goto V_348;
} else if ( V_7 -> V_313 == V_331 ) {
F_126 ( & V_6 -> V_4 ,
V_7 -> V_314 , V_8 ) ;
if ( V_7 -> V_349 == V_332 )
return 0 ;
V_7 -> V_349 = V_332 ;
V_7 -> V_350 = V_332 ;
V_332 = V_7 -> V_351 -
V_7 -> V_349 ;
V_32 = V_352 ;
goto V_348;
} else if ( V_7 -> V_314 == V_331 ) {
F_126 ( & V_6 -> V_4 ,
V_7 -> V_313 , V_8 ) ;
if ( V_7 -> V_350 == V_332 )
return 0 ;
V_7 -> V_349 = V_332 ;
V_7 -> V_350 = V_332 ;
V_332 = V_7 -> V_351 -
V_7 -> V_349 ;
V_32 = V_352 ;
goto V_348;
}
F_127 (hpos, HPOS)
F_127 (vpos, VPOS)
F_127 (saturation, SATURATION)
F_127 (contrast, CONTRAST)
F_127 (hue, HUE)
F_127 (brightness, BRIGHTNESS)
F_127 (sharpness, SHARPNESS)
F_127 (flicker_filter, FLICKER_FILTER)
F_127 (flicker_filter_2d, FLICKER_FILTER_2D)
F_127 (flicker_filter_adaptive, FLICKER_FILTER_ADAPTIVE)
F_127 (tv_chroma_filter, TV_CHROMA_FILTER)
F_127 (tv_luma_filter, TV_LUMA_FILTER)
F_127 (dot_crawl, DOT_CRAWL)
}
return - V_341 ;
V_348:
if ( ! F_26 ( V_1 , V_32 , & V_332 , 2 ) )
return - V_353 ;
V_334:
if ( V_1 -> V_4 . V_4 . V_166 )
F_129 ( V_1 -> V_4 . V_4 . V_166 ) ;
return 0 ;
#undef F_127
}
static void F_130 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_99 != NULL )
F_131 ( V_3 -> V_10 ,
V_1 -> V_99 ) ;
F_132 ( & V_1 -> V_281 ) ;
F_133 ( V_3 ) ;
}
static void
F_134 ( struct V_1 * V_280 )
{
T_4 V_354 = 0 ;
unsigned int V_355 ;
switch ( V_280 -> V_356 ) {
case V_357 :
V_354 |= V_357 ;
case V_358 :
V_354 |= V_358 ;
case V_359 :
V_354 |= V_359 ;
case V_360 :
V_354 |= V_360 ;
case V_361 :
V_354 |= V_361 ;
case V_362 :
V_354 |= V_362 ;
break;
}
V_354 &= V_280 -> V_261 . V_274 ;
V_355 = F_93 ( V_354 ) ;
if ( V_355 > 3 )
V_355 = 3 ;
V_280 -> V_53 = 1 << V_355 ;
}
static void
F_135 ( struct V_11 * V_12 ,
struct V_1 * V_280 , T_1 V_363 )
{
struct V_364 * V_365 ;
if ( V_280 -> V_366 )
V_365 = & ( V_12 -> V_367 [ 0 ] ) ;
else
V_365 = & ( V_12 -> V_367 [ 1 ] ) ;
if ( V_365 -> V_368 )
V_280 -> V_53 = 1 << ( ( V_365 -> V_369 & 0xf0 ) >> 4 ) ;
else
F_134 ( V_280 ) ;
}
static void
F_136 ( struct V_11 * V_12 ,
struct V_1 * V_280 , T_1 V_363 )
{
struct V_364 * V_365 ;
T_2 V_370 ;
if ( V_280 -> V_366 )
V_365 = & V_12 -> V_367 [ 0 ] ;
else
V_365 = & V_12 -> V_367 [ 1 ] ;
if ( V_365 -> V_368 && F_137 ( V_365 -> V_371 ) )
V_370 = V_365 -> V_371 ;
else
V_370 = V_372 ;
V_280 -> V_31 = F_97 ( V_12 , V_370 ) ;
F_138 ( V_280 -> V_31 , true ) ;
}
static void
F_139 ( struct V_1 * V_280 )
{
F_138 ( V_280 -> V_31 , false ) ;
}
static bool
F_140 ( struct V_1 * V_1 , int V_373 )
{
return F_46 ( V_1 ) ;
}
static T_2
F_141 ( struct V_9 * V_10 , struct V_1 * V_280 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_364 * V_374 , * V_375 ;
if ( V_280 -> V_366 ) {
V_374 = & V_12 -> V_367 [ 0 ] ;
V_375 = & V_12 -> V_367 [ 1 ] ;
} else {
V_374 = & V_12 -> V_367 [ 1 ] ;
V_375 = & V_12 -> V_367 [ 0 ] ;
}
if ( V_374 -> V_25 )
return V_374 -> V_25 ;
if ( V_375 -> V_25 ) {
if ( V_375 -> V_25 == 0x70 )
return 0x72 ;
else
return 0x70 ;
}
if ( V_280 -> V_366 )
return 0x70 ;
else
return 0x72 ;
}
static void
F_142 ( struct V_7 * V_6 ,
struct V_1 * V_3 )
{
F_143 ( V_3 -> V_4 . V_4 . V_10 ,
& V_6 -> V_4 . V_4 ,
& V_376 ,
V_6 -> V_4 . V_4 . V_377 ) ;
F_144 ( & V_6 -> V_4 . V_4 ,
& V_378 ) ;
V_6 -> V_4 . V_4 . V_379 = 1 ;
V_6 -> V_4 . V_4 . V_380 = 0 ;
V_6 -> V_4 . V_4 . V_381 . V_382 = V_383 ;
V_6 -> V_4 . V_384 = F_71 ;
F_145 ( & V_6 -> V_4 , & V_3 -> V_4 ) ;
F_146 ( & V_6 -> V_4 . V_4 ) ;
}
static void
F_147 ( struct V_1 * V_1 ,
struct V_7 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_4 . V_4 . V_10 ;
F_148 ( & V_6 -> V_4 . V_4 ) ;
if ( F_64 ( V_10 ) -> V_221 >= 4 && F_149 ( V_10 ) ) {
F_150 ( & V_6 -> V_4 . V_4 ) ;
V_1 -> V_203 = true ;
}
}
static bool
F_151 ( struct V_1 * V_1 , int V_373 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_196 * V_196 = F_152 ( V_3 ) ;
struct V_235 * V_235 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
if ( V_373 == 0 ) {
V_1 -> V_356 |= V_360 ;
V_7 -> V_237 = V_360 ;
} else if ( V_373 == 1 ) {
V_1 -> V_356 |= V_359 ;
V_7 -> V_237 = V_359 ;
}
V_235 = & V_7 -> V_4 ;
V_6 = & V_235 -> V_4 ;
if ( F_90 ( V_1 ) &
V_7 -> V_237 ) {
V_1 -> V_278 |= V_7 -> V_237 ;
V_196 -> V_385 = F_91 ;
F_91 ( V_196 ) ;
} else {
V_235 -> V_386 = V_387 | V_388 ;
}
V_3 -> V_389 = V_390 ;
V_6 -> V_377 = V_391 ;
if ( F_140 ( V_1 , V_373 ) ) {
V_6 -> V_377 = V_392 ;
V_1 -> V_224 = true ;
}
F_142 ( V_7 , V_1 ) ;
if ( V_1 -> V_224 )
F_147 ( V_1 , V_7 ) ;
return true ;
}
static bool
F_153 ( struct V_1 * V_1 , int type )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_235 * V_235 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
V_235 = & V_7 -> V_4 ;
V_6 = & V_235 -> V_4 ;
V_3 -> V_389 = V_393 ;
V_6 -> V_377 = V_394 ;
V_1 -> V_356 |= type ;
V_7 -> V_237 = type ;
V_1 -> V_200 = true ;
F_142 ( V_7 , V_1 ) ;
if ( ! F_154 ( V_1 , V_7 , type ) )
goto V_395;
if ( ! F_155 ( V_1 , V_7 ) )
goto V_395;
return true ;
V_395:
F_121 ( V_6 ) ;
return false ;
}
static bool
F_156 ( struct V_1 * V_1 , int V_373 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_235 * V_235 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
V_235 = & V_7 -> V_4 ;
V_6 = & V_235 -> V_4 ;
V_235 -> V_386 = V_387 ;
V_3 -> V_389 = V_396 ;
V_6 -> V_377 = V_397 ;
if ( V_373 == 0 ) {
V_1 -> V_356 |= V_362 ;
V_7 -> V_237 = V_362 ;
} else if ( V_373 == 1 ) {
V_1 -> V_356 |= V_361 ;
V_7 -> V_237 = V_361 ;
}
F_142 ( V_7 ,
V_1 ) ;
return true ;
}
static bool
F_157 ( struct V_1 * V_1 , int V_373 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_235 * V_235 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
V_235 = & V_7 -> V_4 ;
V_6 = & V_235 -> V_4 ;
V_3 -> V_389 = V_398 ;
V_6 -> V_377 = V_399 ;
if ( V_373 == 0 ) {
V_1 -> V_356 |= V_358 ;
V_7 -> V_237 = V_358 ;
} else if ( V_373 == 1 ) {
V_1 -> V_356 |= V_357 ;
V_7 -> V_237 = V_357 ;
}
F_142 ( V_7 , V_1 ) ;
if ( ! F_155 ( V_1 , V_7 ) )
goto V_395;
return true ;
V_395:
F_121 ( V_6 ) ;
return false ;
}
static bool
F_158 ( struct V_1 * V_1 , T_4 V_26 )
{
V_1 -> V_200 = false ;
V_1 -> V_98 = false ;
if ( V_26 & V_360 )
if ( ! F_151 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_400 ) == V_400 )
if ( ! F_151 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_401 )
if ( ! F_153 ( V_1 , V_401 ) )
return false ;
if ( V_26 & V_402 )
if ( ! F_153 ( V_1 , V_402 ) )
return false ;
if ( V_26 & V_403 )
if ( ! F_153 ( V_1 , V_403 ) )
return false ;
if ( V_26 & V_362 )
if ( ! F_156 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_404 ) == V_404 )
if ( ! F_156 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_358 )
if ( ! F_157 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_299 ) == V_299 )
if ( ! F_157 ( V_1 , 1 ) )
return false ;
if ( ( V_26 & V_405 ) == 0 ) {
unsigned char V_406 [ 2 ] ;
V_1 -> V_356 = 0 ;
memcpy ( V_406 , & V_1 -> V_261 . V_274 , 2 ) ;
F_12 ( L_39 ,
F_14 ( V_1 ) ,
V_406 [ 0 ] , V_406 [ 1 ] ) ;
return false ;
}
V_1 -> V_4 . V_407 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
return true ;
}
static void F_159 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 , * V_150 ;
F_160 (connector, tmp,
&dev->mode_config.connector_list, head) {
if ( F_4 ( V_6 ) == & V_1 -> V_4 )
F_121 ( V_6 ) ;
}
}
static bool F_154 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
int type )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_177 V_178 ;
T_6 V_179 , V_16 ;
if ( ! F_35 ( V_1 , type ) )
return false ;
F_30 ( sizeof( V_178 ) != 6 ) ;
if ( ! F_27 ( V_1 ,
V_408 ,
& V_178 , sizeof( V_178 ) ) )
return false ;
memcpy ( & V_179 , & V_178 , V_84 ( sizeof( V_179 ) , sizeof( V_178 ) ) ) ;
if ( V_179 == 0 )
return false ;
V_7 -> V_409 = 0 ;
for ( V_16 = 0 ; V_16 < V_342 ; V_16 ++ )
if ( V_179 & ( 1 << V_16 ) )
V_7 -> V_343 [ V_7 -> V_409 ++ ] = V_16 ;
V_7 -> V_328 =
F_161 ( V_10 , V_410 ,
L_40 , V_7 -> V_409 ) ;
if ( ! V_7 -> V_328 )
return false ;
for ( V_16 = 0 ; V_16 < V_7 -> V_409 ; V_16 ++ )
F_162 (
V_7 -> V_328 , V_16 ,
V_16 , V_411 [ V_7 -> V_343 [ V_16 ] ] ) ;
V_1 -> V_180 = V_7 -> V_343 [ 0 ] ;
F_163 ( & V_7 -> V_4 . V_4 . V_4 ,
V_7 -> V_328 , 0 ) ;
return true ;
}
static bool
F_164 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_412 V_413 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_42 , V_414 [ 2 ] ;
if ( V_413 . V_415 ) {
if ( ! F_27 ( V_1 ,
V_416 ,
& V_414 , 4 ) )
return false ;
if ( ! F_27 ( V_1 ,
V_417 ,
& V_42 , 2 ) )
return false ;
V_7 -> V_346 = V_414 [ 0 ] ;
V_7 -> V_344 = V_414 [ 0 ] - V_42 ;
V_7 -> V_345 = V_7 -> V_344 ;
V_7 -> V_311 =
F_165 ( V_10 , 0 , L_41 , 0 , V_414 [ 0 ] ) ;
if ( ! V_7 -> V_311 )
return false ;
F_163 ( & V_6 -> V_4 ,
V_7 -> V_311 ,
V_7 -> V_344 ) ;
V_7 -> V_312 =
F_165 ( V_10 , 0 , L_42 , 0 , V_414 [ 0 ] ) ;
if ( ! V_7 -> V_312 )
return false ;
F_163 ( & V_6 -> V_4 ,
V_7 -> V_312 ,
V_7 -> V_345 ) ;
F_12 ( L_43
L_44 ,
V_414 [ 0 ] , V_414 [ 1 ] , V_42 ) ;
}
if ( V_413 . V_418 ) {
if ( ! F_27 ( V_1 ,
V_419 ,
& V_414 , 4 ) )
return false ;
if ( ! F_27 ( V_1 ,
V_420 ,
& V_42 , 2 ) )
return false ;
V_7 -> V_351 = V_414 [ 0 ] ;
V_7 -> V_349 = V_414 [ 0 ] - V_42 ;
V_7 -> V_350 = V_7 -> V_349 ;
V_7 -> V_313 =
F_165 ( V_10 , 0 ,
L_45 , 0 , V_414 [ 0 ] ) ;
if ( ! V_7 -> V_313 )
return false ;
F_163 ( & V_6 -> V_4 ,
V_7 -> V_313 ,
V_7 -> V_349 ) ;
V_7 -> V_314 =
F_165 ( V_10 , 0 ,
L_46 , 0 , V_414 [ 0 ] ) ;
if ( ! V_7 -> V_314 )
return false ;
F_163 ( & V_6 -> V_4 ,
V_7 -> V_314 ,
V_7 -> V_350 ) ;
F_12 ( L_47
L_44 ,
V_414 [ 0 ] , V_414 [ 1 ] , V_42 ) ;
}
F_166 ( V_315 , V_421 ) ;
F_166 ( V_316 , V_422 ) ;
F_166 ( V_317 , V_423 ) ;
F_166 ( V_318 , V_424 ) ;
F_166 ( V_319 , V_425 ) ;
F_166 ( V_320 , V_426 ) ;
F_166 ( V_327 , V_427 ) ;
F_166 ( V_321 , V_428 ) ;
F_166 ( V_323 , V_429 ) ;
F_166 ( V_322 , V_430 ) ;
F_166 ( V_325 , V_431 ) ;
F_166 ( V_324 , V_432 ) ;
if ( V_413 . V_326 ) {
if ( ! F_27 ( V_1 , V_433 , & V_42 , 2 ) )
return false ;
V_7 -> V_434 = 1 ;
V_7 -> V_435 = V_42 & 0x1 ;
V_7 -> V_326 =
F_165 ( V_10 , 0 , L_48 , 0 , 1 ) ;
if ( ! V_7 -> V_326 )
return false ;
F_163 ( & V_6 -> V_4 ,
V_7 -> V_326 ,
V_7 -> V_435 ) ;
F_12 ( L_49 , V_42 ) ;
}
return true ;
}
static bool
F_167 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_412 V_413 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_42 , V_414 [ 2 ] ;
F_166 ( V_327 , V_427 ) ;
return true ;
}
static bool F_155 ( struct V_1 * V_1 ,
struct V_7 * V_7 )
{
union {
struct V_412 V_302 ;
T_4 V_42 ;
} V_413 ;
F_30 ( sizeof( V_413 ) != 2 ) ;
V_413 . V_42 = 0 ;
F_27 ( V_1 ,
V_436 ,
& V_413 , sizeof( V_413 ) ) ;
if ( V_413 . V_42 == 0 ) {
F_12 ( L_50 ) ;
return true ;
}
if ( F_116 ( V_7 ) )
return F_164 ( V_1 , V_7 , V_413 . V_302 ) ;
else if ( F_117 ( V_7 ) )
return F_167 ( V_1 , V_7 , V_413 . V_302 ) ;
else
return true ;
}
static int F_168 ( struct V_437 * V_438 ,
struct V_23 * V_24 ,
int V_439 )
{
struct V_1 * V_280 = V_438 -> V_440 ;
if ( ! F_25 ( V_280 , V_280 -> V_53 ) )
return - V_353 ;
return V_280 -> V_31 -> V_441 -> V_442 ( V_280 -> V_31 , V_24 , V_439 ) ;
}
static T_1 F_169 ( struct V_437 * V_438 )
{
struct V_1 * V_280 = V_438 -> V_440 ;
return V_280 -> V_31 -> V_441 -> V_443 ( V_280 -> V_31 ) ;
}
static bool
F_170 ( struct V_1 * V_280 ,
struct V_9 * V_10 )
{
V_280 -> V_281 . V_444 = V_445 ;
V_280 -> V_281 . V_446 = V_447 ;
snprintf ( V_280 -> V_281 . V_35 , V_448 , L_51 ) ;
V_280 -> V_281 . V_10 . V_449 = & V_10 -> V_450 -> V_10 ;
V_280 -> V_281 . V_440 = V_280 ;
V_280 -> V_281 . V_441 = & V_451 ;
return F_171 ( & V_280 -> V_281 ) == 0 ;
}
bool F_172 ( struct V_9 * V_10 , T_6 V_17 , bool V_366 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_196 * V_196 ;
struct V_1 * V_1 ;
int V_16 ;
V_1 = F_18 ( sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_1 )
return false ;
V_1 -> V_17 = V_17 ;
V_1 -> V_366 = V_366 ;
V_1 -> V_25 = F_141 ( V_10 , V_1 ) >> 1 ;
F_136 ( V_12 , V_1 , V_17 ) ;
if ( ! F_170 ( V_1 , V_10 ) )
goto V_452;
V_196 = & V_1 -> V_4 ;
V_196 -> type = V_453 ;
F_173 ( V_10 , & V_196 -> V_4 , & V_454 , 0 ) ;
for ( V_16 = 0 ; V_16 < 0x40 ; V_16 ++ ) {
T_2 V_455 ;
if ( ! F_10 ( V_1 , V_16 , & V_455 ) ) {
F_12 ( L_52 ,
F_14 ( V_1 ) ) ;
goto V_395;
}
}
V_196 -> V_456 = F_60 ;
V_196 -> V_457 = F_80 ;
V_196 -> V_458 = F_62 ;
V_196 -> V_459 = F_84 ;
V_196 -> V_384 = F_72 ;
V_196 -> V_460 = F_76 ;
if ( ! F_89 ( V_1 , & V_1 -> V_261 ) )
goto V_395;
if ( F_158 ( V_1 ,
V_1 -> V_261 . V_274 ) != true ) {
F_12 ( L_53 ,
F_14 ( V_1 ) ) ;
goto V_461;
}
if ( V_1 -> V_278 ) {
V_196 -> V_462 =
V_1 -> V_366 ? V_463 : V_464 ;
}
V_1 -> V_4 . V_465 = false ;
F_135 ( V_12 , V_1 , V_17 ) ;
if ( ! F_28 ( V_1 ) )
goto V_461;
if ( ! F_34 ( V_1 ,
& V_1 -> V_254 ,
& V_1 -> V_256 ) )
goto V_461;
F_12 ( L_54
L_55
L_56
L_57 ,
F_14 ( V_1 ) ,
V_1 -> V_261 . V_263 , V_1 -> V_261 . V_264 ,
V_1 -> V_261 . V_265 ,
V_1 -> V_254 / 1000 ,
V_1 -> V_256 / 1000 ,
( V_1 -> V_261 . V_268 & 0x1 ) ? 'Y' : 'N' ,
( V_1 -> V_261 . V_268 & 0x2 ) ? 'Y' : 'N' ,
V_1 -> V_261 . V_274 &
( V_360 | V_362 ) ? 'Y' : 'N' ,
V_1 -> V_261 . V_274 &
( V_359 | V_361 ) ? 'Y' : 'N' ) ;
return true ;
V_461:
F_159 ( V_1 ) ;
V_395:
F_174 ( & V_196 -> V_4 ) ;
F_132 ( & V_1 -> V_281 ) ;
V_452:
F_139 ( V_1 ) ;
F_20 ( V_1 ) ;
return false ;
}
